/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40211428 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40211428..402114cf. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  undefined4 *puVar1;
  int *piVar2;
  HRESULT HVar3;
  
                    /* 0x1428  1  DllGetClassObject */
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_40211738(puVar1,&rclsid->Data1);
  }
  if (piVar2 == (int *)0x0) {
    HVar3 = -0x7ff8fff2;
  }
  else {
    HVar3 = (**(code **)*piVar2)(piVar2,riid,ppv);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return HVar3;
}



/* 402114d0 DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
                    /* 0x14d0  3  DllCanUnloadNow */
  return (uint)(DAT_40213a44 != 0);
}



/* 402114ec FUN_402114ec */

undefined4 FUN_402114ec(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_40213a48 = param_1;
  }
  return 1;
}



/* 40211508 FUN_40211508 */

/* Boundary evidence: original MIPS .pdata 40211508..4021159f. Semantic name remains unreviewed. */

undefined4 FUN_40211508(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_3 = 0;
  iVar1 = memcmp(&DAT_40211064,param_2,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(&DAT_40211074,param_2,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 402115b0 FUN_402115b0 */

/* Boundary evidence: original MIPS .pdata 402115b0..402115e7. Semantic name remains unreviewed. */

int FUN_402115b0(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x14))(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 402115e8 FUN_402115e8 */

/* Boundary evidence: original MIPS .pdata 402115e8..402116b3. Semantic name remains unreviewed. */

undefined4 FUN_402115e8(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0x80004005;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_2 == 0) {
    iVar1 = memcmp(&DAT_402113f4,(void *)(param_1 + 8),0x10);
    if (iVar1 == 0) {
      puVar2 = operator_new(0xc);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40212518(puVar2,0);
      }
      if (puVar2 != (undefined4 *)0x0) {
        uVar3 = (**(code **)*puVar2)(puVar2,param_3,param_4);
      }
    }
  }
  else {
    uVar3 = 0x80040110;
  }
  return uVar3;
}



/* 402116e8 FUN_402116e8 */

/* Boundary evidence: original MIPS .pdata 402116e8..40211737. Semantic name remains unreviewed. */

undefined4 * FUN_402116e8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_4021103c;
  DAT_40213a44 = DAT_40213a44 + -1;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40211738 FUN_40211738 */

undefined4 * FUN_40211738(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = &PTR_FUN_4021103c;
  DAT_40213a44 = DAT_40213a44 + 1;
  param_1[1] = 1;
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  param_1[4] = param_2[2];
  param_1[5] = param_2[3];
  return param_1;
}



/* 40211784 FUN_40211784 */

/* Boundary evidence: original MIPS .pdata 40211784..40211893. Semantic name remains unreviewed. */

void FUN_40211784(undefined4 param_1,int *param_2,int param_3)

{
  HDC hdc;
  DWORD rop;
  int iVar1;
  tagRECT local_28;
  
  iVar1 = 0;
  hdc = GetDC(DAT_40213a64);
  local_28.left = *param_2;
  local_28.top = param_2[1];
  local_28.right = param_2[2];
  local_28.bottom = param_2[3];
  InflateRect(&local_28,-1,-1);
  if (DAT_40213a5c != DAT_40213a6c) {
    iVar1 = 0xc3;
  }
  if (param_3 == 0) {
    rop = 0xcc0020;
  }
  else {
    rop = 0x330008;
  }
  BitBlt(hdc,local_28.left,local_28.top,(local_28.right - local_28.left) + 1,
         (local_28.bottom - local_28.top) + 1,DAT_40213a60,local_28.left,local_28.top + iVar1,rop);
  ReleaseDC(DAT_40213a64,hdc);
  return;
}



/* 40211894 FUN_40211894 */

/* Boundary evidence: original MIPS .pdata 40211894..402119e7. Semantic name remains unreviewed. */

void FUN_40211894(HDC param_1,int *param_2)

{
  int *piVar1;
  int x;
  int y;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  
  iVar2 = 0;
  if (DAT_40213a5c != DAT_40213a6c) {
    iVar2 = 0xc3;
  }
  y = param_2[1];
  x = *param_2;
  BitBlt(param_1,x,y,param_2[2] - x,param_2[3] - y,DAT_40213a60,x,y + iVar2,0xcc0020);
  if (DAT_40213a58 != 0) {
    piVar6 = &DAT_4021308c;
    puVar4 = &DAT_40213a1c;
    piVar5 = piVar6;
    do {
      iVar2 = *piVar6;
      piVar3 = piVar6;
      piVar1 = piVar5;
      while (iVar2 != -1) {
        if ((piVar3[4] & 4U) != 0) {
          local_30 = piVar3[5];
          local_28 = piVar3[0xb];
          local_2c = *puVar4;
          local_24 = puVar4[1];
          FUN_40211784(piVar3,&local_30,1);
        }
        piVar3 = piVar1 + 6;
        piVar1 = piVar3;
        iVar2 = *piVar3;
      }
      piVar6 = piVar6 + 0x66;
      piVar5 = piVar5 + 0x66;
      puVar4 = puVar4 + 1;
    } while ((int)piVar6 < 0x40213a1c);
  }
  return;
}



/* 402119e8 FUN_402119e8 */

undefined4 * FUN_402119e8(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  if (DAT_40213a20 < param_1[1]) {
    piVar2 = &DAT_40213a20;
    do {
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + 1;
    } while (*piVar2 < param_1[1]);
    if (5 < iVar3) {
      iVar3 = 5;
    }
  }
  iVar4 = (&DAT_402130b8)[iVar3 * 0x66];
  if (iVar4 < *param_1) {
    piVar2 = &DAT_402130b8 + iVar3 * 0x66;
    do {
      piVar2 = piVar2 + 6;
      iVar4 = *piVar2;
      iVar5 = iVar5 + 1;
    } while (iVar4 < *param_1);
  }
  iVar5 = iVar3 * 0x11 + iVar5;
  iVar1 = *(int *)(iVar5 * 0x18 + 0x402130a0);
  param_1[2] = iVar4;
  *param_1 = iVar1;
  param_1[1] = (&DAT_40213a1c)[iVar3];
  param_1[3] = (&DAT_40213a20)[iVar3];
  return &DAT_4021308c + iVar5 * 6;
}



/* 40211aec FUN_40211aec */

/* Boundary evidence: original MIPS .pdata 40211aec..40211e27. Semantic name remains unreviewed. */

bool FUN_40211aec(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  HDC hDC;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  LONG *pLVar8;
  int *piVar9;
  uint local_40 [2];
  tagRECT local_38;
  
  uVar6 = 0x10000;
  if (param_1 == 0) {
    param_2[4] = param_2[4] & 0xfffffffb;
    uVar7 = 6;
    local_40[0] = 0x10000;
  }
  else {
    param_2[4] = param_2[4] | 4;
    uVar7 = 4;
    local_40[0] = 0x80;
  }
  iVar5 = 1;
  if (param_1 == 0) {
    iVar5 = -1;
  }
  DAT_40213a58 = iVar5 + DAT_40213a58;
  if ((param_2[4] & 1U) != 0) {
    uVar6 = (**(code **)(*DAT_40213a70 + 0x10))(DAT_40213a70,(char)*param_2,uVar7);
    goto LAB_40211c80;
  }
  piVar9 = param_2 + 1;
  if ((*piVar9 == 0) && (param_2[2] == 0)) {
    local_40[0] = local_40[0] | 0x10000;
  }
  if (DAT_40213a68 != 0) {
    local_40[0] = local_40[0] | 0x11000000;
  }
  if (DAT_40213a4c == 0) {
    if (DAT_40213a5c != DAT_40213a6c) {
      uVar6 = 0x20000000;
      piVar9 = param_2 + 2;
      goto LAB_40211c40;
    }
  }
  else {
    local_40[0] = local_40[0] | 0x40000000;
    piVar9 = param_2 + 3;
    if (*piVar9 == -1) {
LAB_40211c40:
      local_40[0] = local_40[0] | uVar6;
    }
  }
  uVar6 = local_40[0];
  if (piVar9 != (int *)0x0) {
    uVar6 = (**(code **)(*DAT_40213a70 + 0x14))(DAT_40213a70,*param_2,local_40[0],1,local_40,piVar9)
    ;
  }
LAB_40211c80:
  iVar4 = *param_2;
  iVar5 = DAT_40213a4c;
  iVar2 = DAT_40213a5c;
  iVar3 = param_1;
  if ((((iVar4 != 0x10) && (iVar5 = param_1, iVar3 = DAT_40213a6c, iVar4 != 0x11)) &&
      (iVar5 = DAT_40213a4c, iVar2 = param_1, iVar4 != 0x14)) &&
     (iVar2 = DAT_40213a5c, iVar4 == 0xa4)) {
    DAT_40213a68 = param_1;
  }
  DAT_40213a6c = iVar3;
  DAT_40213a5c = iVar2;
  DAT_40213a4c = iVar5;
  if ((param_2[4] & 8U) != 0) {
    GetClientRect(DAT_40213a64,&local_38);
    hDC = GetDC(DAT_40213a64);
    FUN_40211894(hDC,&local_38.left);
    ReleaseDC(DAT_40213a64,hDC);
  }
  FUN_40211784(param_2,param_3,param_1);
  if ((param_1 == 0) && (DAT_40213a58 != 0)) {
    piVar9 = &DAT_4021308c;
    pLVar8 = &DAT_40213a1c;
    iVar5 = DAT_40213a58;
    do {
      piVar1 = piVar9;
      if (0x40213a1b < (int)piVar9) break;
      for (; (iVar5 != 0 && (*piVar1 != -1)); piVar1 = piVar1 + 6) {
        if (((piVar1[4] & 4U) != 0) && (*piVar1 != 0x14)) {
          Sleep(100);
          local_38.left = piVar1[5];
          local_38.right = piVar1[0xb];
          local_38.top = *pLVar8;
          local_38.bottom = pLVar8[1];
          FUN_40211aec(0,piVar1,&local_38.left);
          iVar5 = DAT_40213a58;
        }
      }
      piVar9 = piVar9 + 0x66;
      pLVar8 = pLVar8 + 1;
    } while (iVar5 != 0);
  }
  return -1 < (int)uVar6;
}



/* 40211e28 FUN_40211e28 */

/* Boundary evidence: original MIPS .pdata 40211e28..402120a3. Semantic name remains unreviewed. */

undefined4 FUN_40211e28(HWND param_1,int param_2,undefined4 param_3,uint param_4)

{
  HDC hDC;
  int *piVar1;
  uint uVar2;
  tagRECT tStack_28;
  
  piVar1 = DAT_40213a84;
  if (param_2 == 0x201) {
    DAT_40213a80 = 0;
    DAT_40213a7c = (uint)(short)param_4;
    DAT_40213a78 = (int)param_4 >> 0x10;
    DAT_40213a88 = DAT_40213a7c;
    DAT_40213a8c = DAT_40213a78;
    piVar1 = FUN_402119e8((int *)&DAT_40213a88);
    DAT_40213a84 = piVar1;
    if (piVar1 != (int *)0x0) {
      piVar1[4] = piVar1[4] | 0x100;
      FUN_40211784(piVar1,(int *)&DAT_40213a88,1);
      SetCapture(param_1);
    }
  }
  else if (param_2 == 0x202) {
    if (DAT_40213a80 == 0) {
      if (DAT_40213a84 != (int *)0x0) {
        uVar2 = DAT_40213a84[4];
        DAT_40213a84[4] = uVar2 & 0xfffffeff;
        if (((uVar2 & 2) == 0) || ((uVar2 & 4) == 0)) {
          FUN_40211aec(1,piVar1,(int *)&DAT_40213a88);
          if (*DAT_40213a84 == 0x14) {
            (**(code **)(*DAT_40213a70 + 0x10))(DAT_40213a70,0x14,6);
            GetClientRect(DAT_40213a64,&tStack_28);
            hDC = GetDC(DAT_40213a64);
            FUN_40211894(hDC,&tStack_28.left);
            ReleaseDC(DAT_40213a64,hDC);
          }
        }
        else {
          if (*piVar1 == 0x14) {
            (**(code **)(*DAT_40213a70 + 0x10))(DAT_40213a70,0x14,4);
            piVar1 = DAT_40213a84;
          }
          FUN_40211aec(0,piVar1,(int *)&DAT_40213a88);
        }
        if ((DAT_40213a84[4] & 2U) == 0) {
          FUN_40211aec(0,DAT_40213a84,(int *)&DAT_40213a88);
          DAT_40213a84 = (int *)0x0;
        }
      }
      ReleaseCapture();
    }
  }
  else if (param_2 == 0x203) {
    DAT_40213a88 = param_4 & 0xffff;
    DAT_40213a8c = param_4 >> 0x10;
    DAT_40213a84 = FUN_402119e8((int *)&DAT_40213a88);
    SetCapture(param_1);
    if ((DAT_40213a84[4] & 2U) == 0) {
      FUN_40211784(DAT_40213a84,(int *)&DAT_40213a88,1);
    }
    else {
      DAT_40213a80 = 1;
    }
  }
  return 0;
}



/* 402120a4 FUN_402120a4 */

/* Boundary evidence: original MIPS .pdata 402120a4..40212153. Semantic name remains unreviewed. */

LRESULT FUN_402120a4(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  LRESULT LVar1;
  tagPAINTSTRUCT local_50;
  uint local_10;
  
  local_10 = DAT_40213a3c;
  if (param_2 == 0xf) {
    BeginPaint(param_1,&local_50);
    FUN_40211894(local_50.hdc,&local_50.rcPaint.left);
    EndPaint(param_1,&local_50);
    FUN_40212828(local_10);
    LVar1 = 0;
  }
  else {
    if ((param_2 < 0x200) || (0x203 < param_2)) {
      LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
    }
    else {
      LVar1 = FUN_40211e28(param_1,param_2,param_3,param_4);
    }
    FUN_40212828(local_10);
  }
  return LVar1;
}



/* 40212154 FUN_40212154 */

/* Boundary evidence: original MIPS .pdata 40212154..40212287. Semantic name remains unreviewed. */

undefined4 FUN_40212154(undefined4 param_1,HWND param_2)

{
  ATOM AVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  WNDCLASSW local_40;
  
  memset(&local_40,0,0x28);
  local_40.lpfnWndProc = FUN_402120a4;
  local_40.style = 8;
  local_40.hInstance = DAT_40213a48;
  local_40.hbrBackground = (HBRUSH)0x0;
  local_40.lpszClassName = L"A523DFC7-1A7E-4af6-991A-510E75847828 - MicrosoftIMWndClass";
  AVar1 = RegisterClassW(&local_40);
  if (CONCAT22(extraout_var,AVar1) == 0) {
    uVar2 = 0x80004005;
  }
  else {
    DAT_40213a60 = CreateCompatibleDC((HDC)0x0);
    DAT_40213a50 = LoadBitmapW(DAT_40213a48,(LPCWSTR)0x1f4);
    DAT_40213a54 = SelectObject(DAT_40213a60,DAT_40213a50);
    DAT_40213a64 = CreateWindowExW(0,L"A523DFC7-1A7E-4af6-991A-510E75847828 - MicrosoftIMWndClass",
                                   L"",0x40000000,0,0,10,10,param_2,(HMENU)0x0,DAT_40213a48,
                                   (LPVOID)0x0);
    InvalidateRect(DAT_40213a64,(RECT *)0x0,1);
    UpdateWindow(DAT_40213a64);
    ShowWindow(DAT_40213a64,4);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40212288 FUN_40212288 */

/* Boundary evidence: original MIPS .pdata 40212288..402122e7. Semantic name remains unreviewed. */

undefined4 FUN_40212288(void)

{
  SelectObject(DAT_40213a60,DAT_40213a54);
  DeleteObject(DAT_40213a50);
  DeleteDC(DAT_40213a60);
  DestroyWindow(DAT_40213a64);
  UnregisterClassW(L"A523DFC7-1A7E-4af6-991A-510E75847828 - MicrosoftIMWndClass",DAT_40213a48);
  return 0;
}



/* 402122e8 FUN_402122e8 */

/* Boundary evidence: original MIPS .pdata 402122e8..40212343. Semantic name remains unreviewed. */

undefined4 FUN_402122e8(void)

{
  HDC hDC;
  tagRECT tStack_20;
  
  GetClientRect(DAT_40213a64,&tStack_20);
  hDC = GetDC(DAT_40213a64);
  FUN_40211894(hDC,&tStack_20.left);
  ReleaseDC(DAT_40213a64,hDC);
  return 0;
}



/* 40212344 FUN_40212344 */

/* Boundary evidence: original MIPS .pdata 40212344..402123cb. Semantic name remains unreviewed. */

undefined4 FUN_40212344(undefined4 param_1,int param_2)

{
  int *piVar1;
  
  *(undefined4 *)(param_2 + 0x14) = 2;
  piVar1 = DAT_40213a70;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x18) + 0x1d1;
  *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x1c) + 0xc2;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))();
  }
  InvalidateRect(DAT_40213a64,(RECT *)0x0,1);
  UpdateWindow(DAT_40213a64);
  return 0;
}



/* 402123cc FUN_402123cc */

/* Boundary evidence: original MIPS .pdata 402123cc..40212417. Semantic name remains unreviewed. */

undefined4 FUN_402123cc(undefined4 param_1,int param_2)

{
  MoveWindow(DAT_40213a64,0,0,*(int *)(param_2 + 0x20) - *(int *)(param_2 + 0x18),
             *(int *)(param_2 + 0x24) - *(int *)(param_2 + 0x1c),0);
  return 0;
}



/* 4021243c FUN_4021243c */

/* Boundary evidence: original MIPS .pdata 4021243c..402124cf. Semantic name remains unreviewed. */

undefined4 FUN_4021243c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(&DAT_40211064,param_2,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(&DAT_40211304,param_2,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 402124d0 FUN_402124d0 */

/* Boundary evidence: original MIPS .pdata 402124d0..40212517. Semantic name remains unreviewed. */

int FUN_402124d0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_402113bc;
    DAT_40213a44 = DAT_40213a44 + -1;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40212518 FUN_40212518 */

undefined4 * FUN_40212518(undefined4 *param_1,int param_2)

{
  *param_1 = &PTR_FUN_402113bc;
  param_1[1] = 0;
  DAT_40213a44 = DAT_40213a44 + 1;
  if (param_2 == 0) {
    param_1[2] = param_1;
  }
  else {
    param_1[2] = param_2;
  }
  return param_1;
}



/* 402126c0 entry */

/* Boundary evidence: original MIPS .pdata 402126c0..40212733. Semantic name remains unreviewed. */

undefined4 entry(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_40212734();
    FUN_40212a08();
  }
  uVar1 = FUN_402114ec(param_1,param_2);
  if (param_2 == 0) {
    FUN_40212990();
  }
  return uVar1;
}



/* 40212734 FUN_40212734 */

/* Boundary evidence: original MIPS .pdata 40212734..402127a7. Semantic name remains unreviewed. */

void FUN_40212734(void)

{
  uint uVar1;
  
  if ((DAT_40213a3c == 0) || (DAT_40213a3c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40213a3c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40213a3c == 0) {
      DAT_40213a3c = 0xb064;
    }
  }
  DAT_40213a40 = ~DAT_40213a3c;
  return;
}



/* 402127a8 FUN_402127a8 */

/* Boundary evidence: original MIPS .pdata 402127a8..402127fb. Semantic name remains unreviewed. */

void FUN_402127a8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40212828(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 402127fc FUN_402127fc */

/* Boundary evidence: original MIPS .pdata 402127fc..40212827. Semantic name remains unreviewed. */

undefined4 FUN_402127fc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_402127a8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40212828 FUN_40212828 */

/* Boundary evidence: original MIPS .pdata 40212828..4021286f. Semantic name remains unreviewed. */

void FUN_40212828(uint param_1)

{
  if ((param_1 == DAT_40213a3c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40212870 FUN_40212870 */

/* Boundary evidence: original MIPS .pdata 40212870..4021298f. Semantic name remains unreviewed. */

void FUN_40212870(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_40213a98 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40213aa0;
    if (DAT_40213aa0 != (undefined4 *)0x0) {
      while (DAT_40213a9c = DAT_40213a9c + -1, _Memory <= DAT_40213a9c) {
        if ((code *)*DAT_40213a9c != (code *)0x0) {
          (*(code *)*DAT_40213a9c)();
          _Memory = DAT_40213aa0;
        }
      }
      free(_Memory);
      DAT_40213a9c = (undefined4 *)0x0;
      DAT_40213aa0 = (undefined4 *)0x0;
    }
    FUN_402129b4((undefined4 *)&DAT_40211010,(undefined4 *)&DAT_40211014);
  }
  FUN_402129b4((undefined4 *)&DAT_40211018,(undefined4 *)&DAT_4021101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_40213aa4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40212990 FUN_40212990 */

/* Boundary evidence: original MIPS .pdata 40212990..402129b3. Semantic name remains unreviewed. */

void FUN_40212990(void)

{
  FUN_40212870(0,0,1);
  return;
}



/* 402129b4 FUN_402129b4 */

/* Boundary evidence: original MIPS .pdata 402129b4..40212a07. Semantic name remains unreviewed. */

void FUN_402129b4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40212a08 FUN_40212a08 */

/* Boundary evidence: original MIPS .pdata 40212a08..40212a43. Semantic name remains unreviewed. */

void FUN_40212a08(void)

{
  FUN_402129b4((undefined4 *)&DAT_40211008,(undefined4 *)&DAT_4021100c);
  FUN_402129b4((undefined4 *)&DAT_40211000,(undefined4 *)&DAT_40211004);
  return;
}


