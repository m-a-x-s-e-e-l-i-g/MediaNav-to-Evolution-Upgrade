/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40572d5c FUN_40572d5c */

/* Boundary evidence: original MIPS .pdata 40572d5c..40572def. Semantic name remains unreviewed. */

undefined4 * FUN_40572d5c(undefined4 *param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    param_2 = (undefined4 *)0x0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    param_2[1] = 0;
    *param_2 = 0;
    if (param_1[2] == 0) {
      *param_1 = param_2;
    }
    else {
      *param_2 = param_1[1];
      *(undefined4 **)(param_1[1] + 4) = param_2;
    }
    param_1[1] = param_2;
    param_1[2] = param_1[2] + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  return param_2;
}



/* 40572df0 FUN_40572df0 */

/* Boundary evidence: original MIPS .pdata 40572df0..40572e97. Semantic name remains unreviewed. */

int * FUN_40572df0(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 == (int *)0x0) {
    param_2 = (int *)0x0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    iVar1 = param_1[2];
    param_1[2] = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      *param_1 = 0;
      param_1[1] = 0;
    }
    else {
      iVar1 = *param_2;
      piVar2 = (int *)param_2[1];
      if (iVar1 == 0) {
        *piVar2 = 0;
        *param_1 = piVar2;
      }
      else if (piVar2 == (int *)0x0) {
        *(undefined4 *)(iVar1 + 4) = 0;
        param_1[1] = iVar1;
      }
      else {
        *piVar2 = iVar1;
        *(int **)(iVar1 + 4) = piVar2;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  return param_2;
}



/* 40572e98 FUN_40572e98 */

/* Boundary evidence: original MIPS .pdata 40572e98..40572fa3. Semantic name remains unreviewed. */

void FUN_40572e98(undefined4 *param_1)

{
  LPCRITICAL_SECTION p_Var1;
  int *hMem;
  int *piVar2;
  
  p_Var1 = (LPCRITICAL_SECTION)(param_1 + 3);
  EnterCriticalSection(p_Var1);
  EnterCriticalSection(p_Var1);
  LeaveCriticalSection(p_Var1);
  hMem = (int *)*param_1;
  while (hMem != (int *)0x0) {
    piVar2 = (int *)hMem[1];
    FUN_40572df0(param_1,hMem);
    (**(code **)(*(int *)hMem[3] + 8))();
    LocalFree(hMem);
    hMem = piVar2;
  }
  p_Var1 = (LPCRITICAL_SECTION)(param_1 + 3);
  EnterCriticalSection(p_Var1);
  LeaveCriticalSection(p_Var1);
  LeaveCriticalSection(p_Var1);
  DeleteCriticalSection(p_Var1);
  return;
}



/* 40572fa4 FUN_40572fa4 */

/* Boundary evidence: original MIPS .pdata 40572fa4..40572faf. Semantic name remains unreviewed. */

undefined4 FUN_40572fa4(void)

{
  return 1;
}



/* 40572fb0 FUN_40572fb0 */

/* Boundary evidence: original MIPS .pdata 40572fb0..40573033. Semantic name remains unreviewed. */

uint FUN_40572fb0(int param_1)

{
  short extraout_var;
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = 0;
  iVar1 = 0;
  if (param_1 == 0) {
    iVar1 = 3;
  }
  puVar3 = (uint *)(&UNK_40571040 + iVar1 * 8);
  iVar1 = 6 - iVar1;
  do {
    GetAsyncKeyState(puVar3[-1]);
    if (extraout_var < 0) {
      uVar2 = uVar2 | *puVar3 & 0xffff;
    }
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 2;
  } while (iVar1 != 0);
  return uVar2;
}



/* 40573034 FUN_40573034 */

/* Boundary evidence: original MIPS .pdata 40573034..40573067. Semantic name remains unreviewed. */

LRESULT FUN_40573034(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  
  if (param_2 == 0x1f) {
    LVar1 = 0;
  }
  else {
    LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
  }
  return LVar1;
}



/* 40573068 FUN_40573068 */

/* Boundary evidence: original MIPS .pdata 40573068..405733a7. Semantic name remains unreviewed. */

undefined4 FUN_40573068(int param_1)

{
  UINT_PTR uIDEvent;
  BOOL BVar1;
  uint uVar2;
  short extraout_var;
  int iVar3;
  short extraout_var_00;
  uint uVar4;
  undefined4 uVar5;
  tagMSG tStack_68;
  tagMSG tStack_48;
  
  uVar5 = 1;
  uIDEvent = SetTimer((HWND)0x0,0,100,(TIMERPROC)0x0);
LAB_405730c4:
  BVar1 = PeekMessageW(&tStack_68,(HWND)0x0,0x12,0x12,3);
  if (((BVar1 == 0) && (BVar1 = PeekMessageW(&tStack_68,(HWND)0x0,0x100,0x108,3), BVar1 == 0)) &&
     (BVar1 = PeekMessageW(&tStack_68,(HWND)0x0,0x104,0x105,3), BVar1 == 0)) {
    BVar1 = PeekMessageW(&tStack_68,(HWND)0x0,0x200,0x20d,1);
    if ((BVar1 == 0) && (BVar1 = PeekMessageW(&tStack_68,(HWND)0x0,0,0,3), BVar1 == 0))
    goto LAB_405730c4;
  }
  if (tStack_68.message == 0x12) {
    PostQuitMessage(tStack_68.wParam);
    uVar5 = 0;
    *(undefined4 *)(param_1 + 0x30) = 0x80004005;
    goto LAB_4057336c;
  }
  if (((tStack_68.message < 0x100) || (0x108 < tStack_68.message)) &&
     ((tStack_68.message < 0x104 || (0x105 < tStack_68.message)))) {
    if ((0x1ff < tStack_68.message) && (tStack_68.message < 0x20e)) {
      GetAsyncKeyState(0x1b);
      if (extraout_var < 0) {
        *(undefined4 *)(param_1 + 0x20) = 1;
      }
      if (tStack_68.message == 0x200) {
        iVar3 = PeekMessageW(&tStack_48,(HWND)0x0,0x200,0x200,1);
        while (iVar3 != 0) {
          memcpy(&tStack_68,&tStack_48,0x1c);
          iVar3 = PeekMessageW(&tStack_48,(HWND)0x0,0x200,0x200,1);
        }
      }
      *(uint *)(param_1 + 0x10) = tStack_68.lParam & 0xffff;
      *(uint *)(param_1 + 0x14) = (uint)tStack_68.lParam >> 0x10;
      if (tStack_68.message == 0x202) {
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffffe;
      }
      goto LAB_4057336c;
    }
    if ((tStack_68.message == 0x113) && (tStack_68.wParam == uIDEvent)) {
      uVar2 = FUN_40572fb0(0);
      *(uint *)(param_1 + 0x2c) = uVar2 | *(uint *)(param_1 + 0x2c) & 0x13;
      GetAsyncKeyState(0x1b);
      if (extraout_var_00 < 0) {
        *(undefined4 *)(param_1 + 0x20) = 1;
      }
      goto LAB_4057336c;
    }
    DispatchMessageW(&tStack_68);
  }
  else {
    do {
      if (((tStack_68.message == 0x100) || (tStack_68.message == 0x104)) &&
         (tStack_68.wParam == 0x1b)) {
        *(undefined4 *)(param_1 + 0x20) = 1;
      }
      BVar1 = PeekMessageW(&tStack_68,(HWND)0x0,0x100,0x108,3);
    } while ((BVar1 != 0) || (BVar1 = PeekMessageW(&tStack_68,(HWND)0x0,0x104,0x105,3), BVar1 != 0))
    ;
    uVar4 = *(uint *)(param_1 + 0x2c);
    uVar2 = FUN_40572fb0(0);
    uVar2 = uVar2 | uVar4 & 0x13;
    if ((uVar2 != uVar4) || (*(int *)(param_1 + 0x20) != 0)) {
      *(uint *)(param_1 + 0x2c) = uVar2;
LAB_4057336c:
      KillTimer((HWND)0x0,uIDEvent);
      return uVar5;
    }
  }
  goto LAB_405730c4;
}



/* 405733a8 FUN_405733a8 */

/* Boundary evidence: original MIPS .pdata 405733a8..40573437. Semantic name remains unreviewed. */

undefined4 FUN_405733a8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 != 0) {
    **(undefined4 **)(param_1 + 0x1c) = 0;
  }
  **(uint **)(param_1 + 0x1c) =
       (*(uint *)(param_1 + 0x18) | 0x80000000) & **(uint **)(param_1 + 0x1c);
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x10))
                    (*(int **)(param_1 + 4),**(undefined4 **)(param_1 + 0x1c));
  if ((iVar1 != 0) && (iVar1 != 0x40102)) {
    uVar2 = 0;
    *(int *)(param_1 + 0x30) = iVar1;
  }
  return uVar2;
}



/* 40573438 FUN_40573438 */

/* Boundary evidence: original MIPS .pdata 40573438..4057351b. Semantic name remains unreviewed. */

undefined4 FUN_40573438(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 auStack_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  uVar2 = 1;
  if (*(int *)(param_1 + 8) == 0) {
    ImageList_DragMove(*(int *)(param_1 + 0x10),*(int *)(param_1 + 0x14));
  }
  else {
    **(undefined4 **)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
    piVar1 = *(int **)(param_1 + 8);
    if (*(int **)(param_1 + 0xc) == piVar1) {
      local_14 = (**(code **)(*piVar1 + 0x10))
                           (piVar1,*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x10),
                            *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x1c));
    }
    else {
      local_24 = *(undefined4 *)(param_1 + 0x2c);
      local_20 = *(undefined4 *)(param_1 + 0x10);
      local_1c = *(undefined4 *)(param_1 + 0x14);
      local_18 = *(undefined4 *)(param_1 + 0x1c);
      SendMessageW(DAT_405a9a44,0x801,0,(LPARAM)auStack_28);
    }
    uVar2 = FUN_405733a8(param_1,local_14);
  }
  return uVar2;
}



/* 4057351c FUN_4057351c */

/* Boundary evidence: original MIPS .pdata 4057351c..405736db. Semantic name remains unreviewed. */

undefined4 FUN_4057351c(undefined4 *param_1)

{
  int *piVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  ReleaseCapture();
  piVar1 = (int *)param_1[2];
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)param_1[7] = 0;
  }
  else {
    if ((int *)param_1[3] == piVar1) {
      if ((param_1[0xc] == 0x40100) && (*(int *)param_1[7] != 0)) {
        *(int *)param_1[7] = param_1[6];
        local_14 = (**(code **)(*(int *)param_1[2] + 0x18))
                             ((int *)param_1[2],*param_1,param_1[0xb],param_1[4],param_1[5],
                              param_1[7]);
        if (local_14 != 0) {
          param_1[0xc] = local_14;
        }
      }
      else {
        (**(code **)(*piVar1 + 0x14))();
      }
    }
    else {
      if ((param_1[0xc] == 0x40100) && (*(int *)param_1[7] != 0)) {
        *(int *)param_1[7] = param_1[6];
        local_20 = param_1[4];
        local_28 = *param_1;
        local_24 = param_1[0xb];
        local_1c = param_1[5];
        local_18 = param_1[7];
        SendMessageW(DAT_405a9a44,0x803,0,(LPARAM)&local_28);
        if (local_14 != 0) {
          param_1[0xc] = local_14;
        }
      }
      else {
        *(undefined4 *)param_1[7] = 0;
        SendMessageW(DAT_405a9a44,0x802,0,(LPARAM)&local_28);
      }
      SetWindowLongW(DAT_405a9a44,-4,DAT_405a9a48);
      DAT_405a9a48 = 0;
      DAT_405a9a44 = (HWND)0x0;
    }
    (**(code **)(*(int *)param_1[2] + 8))();
    param_1[2] = 0;
  }
  return param_1[0xc];
}



/* 40573794 FUN_40573794 */

/* Boundary evidence: original MIPS .pdata 40573794..405737c3. Semantic name remains unreviewed. */

int FUN_40573794(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 4) + -1;
  *(int *)((int)param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 405737c4 FUN_405737c4 */

/* Boundary evidence: original MIPS .pdata 405737c4..405737fb. Semantic name remains unreviewed. */

undefined4 FUN_405737c4(void)

{
  int in_a3;
  int in_stack_00000010;
  undefined4 *in_stack_00000014;
  
  ImageList_DragEnter((HWND)0x0,in_a3,in_stack_00000010);
  *in_stack_00000014 = 0;
  return 0;
}



/* 405737fc FUN_405737fc */

/* Boundary evidence: original MIPS .pdata 405737fc..4057382f. Semantic name remains unreviewed. */

undefined4
FUN_405737fc(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  ImageList_DragMove(param_3,param_4);
  *param_5 = 0;
  return 0;
}



/* 40573830 FUN_40573830 */

/* Boundary evidence: original MIPS .pdata 40573830..40573857. Semantic name remains unreviewed. */

undefined4 FUN_40573830(void)

{
  ImageList_DragLeave((HWND)0x0);
  return 0;
}



/* 40573858 FUN_40573858 */

/* Boundary evidence: original MIPS .pdata 40573858..405739d7. Semantic name remains unreviewed. */

LRESULT FUN_40573858(HWND param_1,UINT param_2,WPARAM param_3,undefined4 *param_4)

{
  LRESULT LVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  for (iVar4 = *DAT_405a9a4c; iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
    if (param_1 == *(HWND *)(iVar4 + 8)) goto LAB_40573898;
  }
  iVar4 = 0;
LAB_40573898:
  if (iVar4 == 0) {
    return 0;
  }
  piVar3 = *(int **)(iVar4 + 0xc);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  if (param_2 == 0x800) {
    if (param_4 == (undefined4 *)0x0) {
      return 0;
    }
    uVar2 = (**(code **)(*piVar3 + 0xc))
                      (piVar3,*param_4,param_4[1],param_4[2],param_4[3],param_4[4]);
  }
  else if (param_2 == 0x801) {
    if (param_4 == (undefined4 *)0x0) {
      return 0;
    }
    uVar2 = (**(code **)(*piVar3 + 0x10))(piVar3,param_4[1],param_4[2],param_4[3],param_4[4]);
  }
  else if (param_2 == 0x802) {
    if (param_4 == (undefined4 *)0x0) {
      return 0;
    }
    uVar2 = (**(code **)(*piVar3 + 0x14))();
  }
  else {
    if (param_2 != 0x803) {
      if (DAT_405a9a48 == (WNDPROC)0x0) {
        return 0;
      }
      LVar1 = CallWindowProcW(DAT_405a9a48,param_1,param_2,param_3,(LPARAM)param_4);
      return LVar1;
    }
    if (param_4 == (undefined4 *)0x0) {
      return 0;
    }
    uVar2 = (**(code **)(*piVar3 + 0x18))
                      (piVar3,*param_4,param_4[1],param_4[2],param_4[3],param_4[4]);
  }
  param_4[5] = uVar2;
  return 0;
}



/* 405739d8 FUN_405739d8 */

/* Boundary evidence: original MIPS .pdata 405739d8..40573a8b. Semantic name remains unreviewed. */

undefined4 FUN_405739d8(int *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  for (iVar3 = *param_1; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    if (param_2 == *(int *)(iVar3 + 8)) goto LAB_40573a20;
  }
  iVar3 = 0;
LAB_40573a20:
  if ((iVar3 == 0) && (puVar2 = LocalAlloc(0,0x10), puVar2 != (undefined4 *)0x0)) {
    puVar2[2] = param_2;
    puVar2[3] = param_3;
    (**(code **)(*param_3 + 4))(param_3);
    FUN_40572d5c(param_1,puVar2);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40573a8c FUN_40573a8c */

/* Boundary evidence: original MIPS .pdata 40573a8c..40573b07. Semantic name remains unreviewed. */

bool FUN_40573a8c(int *param_1,int param_2)

{
  int *hMem;
  
  for (hMem = (int *)*param_1; hMem != (int *)0x0; hMem = (int *)hMem[1]) {
    if (param_2 == hMem[2]) goto LAB_40573ac0;
  }
  hMem = (int *)0x0;
LAB_40573ac0:
  if (hMem != (int *)0x0) {
    FUN_40572df0(param_1,hMem);
    (**(code **)(*(int *)hMem[3] + 8))();
    LocalFree(hMem);
  }
  return hMem != (int *)0x0;
}



/* 40573b08 FUN_40573b08 */

/* Boundary evidence: original MIPS .pdata 40573b08..40573d57. Semantic name remains unreviewed. */

undefined4 FUN_40573b08(undefined4 *param_1)

{
  HWND pHVar1;
  int iVar2;
  HWND hWnd;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  piVar4 = (int *)param_1[3];
  uVar5 = 1;
  pHVar1 = WindowFromPoint(*(POINT *)(param_1 + 4));
  iVar2 = (**(code **)(*(int *)param_1[1] + 0xc))((int *)param_1[1],param_1[8],param_1[0xb]);
  if (iVar2 == 0) {
    hWnd = pHVar1;
    if (pHVar1 != (HWND)param_1[9]) {
      while ((hWnd != (HWND)0x0 && (piVar4 == (int *)param_1[3]))) {
        for (iVar2 = *DAT_405a9a4c; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
          if (hWnd == *(HWND *)(iVar2 + 8)) goto LAB_40573bbc;
        }
        iVar2 = 0;
LAB_40573bbc:
        if (iVar2 != 0) {
          piVar4 = *(int **)(iVar2 + 0xc);
        }
        param_1[10] = hWnd;
        hWnd = GetParent(hWnd);
      }
      piVar3 = (int *)param_1[2];
      param_1[9] = pHVar1;
      if ((piVar4 != piVar3) || (piVar3 == (int *)0x0)) {
        if (piVar3 != (int *)0x0) {
          if ((int *)param_1[3] == piVar3) {
            (**(code **)(*piVar3 + 0x14))();
          }
          else {
            SendMessageW(DAT_405a9a44,0x802,0,(LPARAM)&local_30);
            SetWindowLongW(DAT_405a9a44,-4,DAT_405a9a48);
            DAT_405a9a48 = 0;
            DAT_405a9a44 = (HWND)0x0;
          }
          (**(code **)(*(int *)param_1[2] + 8))();
          param_1[2] = 0;
        }
        *(undefined4 *)param_1[7] = param_1[6];
        param_1[2] = piVar4;
        (**(code **)(*piVar4 + 4))(piVar4);
        piVar4 = (int *)param_1[2];
        if ((int *)param_1[3] == piVar4) {
          local_1c = (**(code **)(*piVar4 + 0xc))
                               (piVar4,*param_1,param_1[0xb],param_1[4],param_1[5],param_1[7]);
        }
        else {
          DAT_405a9a44 = (HWND)param_1[10];
          DAT_405a9a48 = SetWindowLongW(DAT_405a9a44,-4,0x40573858);
          local_30 = *param_1;
          local_2c = param_1[0xb];
          local_28 = param_1[4];
          local_24 = param_1[5];
          local_20 = param_1[7];
          SendMessageW(DAT_405a9a44,0x800,0,(LPARAM)&local_30);
        }
        FUN_405733a8((int)param_1,local_1c);
      }
    }
  }
  else {
    param_1[0xc] = iVar2;
    uVar5 = 0;
  }
  return uVar5;
}



/* 40573d58 RegisterDragDrop */

/* Boundary evidence: original MIPS .pdata 40573d58..40573e3f. Semantic name remains unreviewed. */

HRESULT RegisterDragDrop(HWND hwnd,LPDROPTARGET pDropTarget)

{
  BOOL BVar1;
  HRESULT HVar2;
  int *piVar3;
  int iVar4;
  
                    /* 0x3d58  7  RegisterDragDrop */
  BVar1 = IsWindow(hwnd);
  if (BVar1 == 0) {
    HVar2 = -0x7ffbfefe;
  }
  else if (pDropTarget == (LPDROPTARGET)0x0) {
    HVar2 = -0x7ff8ffa9;
  }
  else {
    if (DAT_405a9a4c == (int *)0x0) {
      piVar3 = operator_new(0x20);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        InitializeCriticalSection((LPCRITICAL_SECTION)(piVar3 + 3));
        *piVar3 = 0;
        piVar3[1] = 0;
        piVar3[2] = 0;
      }
      DAT_405a9a4c = piVar3;
      if (piVar3 == (int *)0x0) {
        return -0x7ff8fff2;
      }
    }
    iVar4 = FUN_405739d8(DAT_405a9a4c,(int)hwnd,(int *)pDropTarget);
    if (iVar4 == 0) {
      HVar2 = -0x7ffbfeff;
    }
    else {
      HVar2 = 0;
    }
  }
  return HVar2;
}



/* 40573e40 RevokeDragDrop */

/* Boundary evidence: original MIPS .pdata 40573e40..40573ee3. Semantic name remains unreviewed. */

HRESULT RevokeDragDrop(HWND hwnd)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  HRESULT HVar3;
  
                    /* 0x3e40  8  RevokeDragDrop */
  if (DAT_405a9a4c == (int *)0x0) {
    piVar2 = operator_new(0x20);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      InitializeCriticalSection((LPCRITICAL_SECTION)(piVar2 + 3));
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
    }
    DAT_405a9a4c = piVar2;
    if (piVar2 == (int *)0x0) {
      return -0x7ff8fff2;
    }
  }
  bVar1 = FUN_40573a8c(DAT_405a9a4c,(int)hwnd);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    HVar3 = -0x7ffbff00;
  }
  else {
    HVar3 = 0;
  }
  return HVar3;
}



/* 40573ee4 FUN_40573ee4 */

/* Boundary evidence: original MIPS .pdata 40573ee4..40574003. Semantic name remains unreviewed. */

undefined4 *
FUN_40573ee4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  HWND hWnd;
  undefined4 *puVar1;
  BOOL BVar2;
  tagMSG tStack_30;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[6] = param_4;
  param_1[7] = param_5;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  hWnd = CreateWindowExW(0,L"DragCaptureWnd",(LPCWSTR)0x0,0x80000000,0,0,1,1,(HWND)0x0,(HMENU)0x0,
                         DAT_405aa0c0,(LPVOID)0x0);
  param_1[0xe] = hWnd;
  SetCapture(hWnd);
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_LAB_40571088;
    puVar1[1] = 1;
  }
  param_1[3] = puVar1;
  do {
    BVar2 = PeekMessageW(&tStack_30,(HWND)0x0,0x200,0x20d,1);
  } while (BVar2 == 0);
  param_1[4] = tStack_30.lParam & 0xffff;
  param_1[5] = (uint)tStack_30.lParam >> 0x10;
  param_1[0xb] = (uint)(tStack_30.message != 0x202);
  return param_1;
}



/* 40574004 DoDragDrop */

/* Boundary evidence: original MIPS .pdata 40574004..40574197. Semantic name remains unreviewed. */

HRESULT DoDragDrop(LPDATAOBJECT pDataObj,LPDROPSOURCE pDropSource,DWORD dwOKEffects,
                  LPDWORD pdwEffect)

{
  ATOM AVar1;
  BOOL BVar2;
  undefined2 extraout_var;
  DWORD DVar3;
  int iVar4;
  HRESULT HVar5;
  tagWNDCLASSW local_88;
  undefined4 auStack_60 [3];
  int *local_54;
  HWND local_28;
  
                    /* 0x4004  6  DoDragDrop */
  local_88.style = 0;
  memset(&local_88.lpfnWndProc,0,0x24);
  BVar2 = GetClassInfoW(DAT_405aa0c0,L"DragCaptureWnd",&local_88);
  if (BVar2 == 0) {
    local_88.lpfnWndProc = FUN_40573034;
    local_88.hInstance = DAT_405aa0c0;
    local_88.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_88.lpszClassName = L"DragCaptureWnd";
    AVar1 = RegisterClassW(&local_88);
    if (CONCAT22(extraout_var,AVar1) == 0) {
      DVar3 = GetLastError();
      if ((int)DVar3 < 1) {
        return DVar3;
      }
      return DVar3 & 0xffff | 0x80070000;
    }
  }
  if (DAT_405a9a48 == 0) {
    FUN_40573ee4(auStack_60,pDataObj,pDropSource,dwOKEffects,pdwEffect);
    do {
      iVar4 = FUN_40573b08(auStack_60);
      if ((iVar4 == 0) || (iVar4 = FUN_40573438((int)auStack_60), iVar4 == 0)) break;
      iVar4 = FUN_40573068((int)auStack_60);
    } while (iVar4 != 0);
    HVar5 = FUN_4057351c(auStack_60);
    ReleaseCapture();
    DestroyWindow(local_28);
    (**(code **)(*local_54 + 8))();
  }
  else {
    HVar5 = -0x7fffbffb;
  }
  return HVar5;
}



/* 40574198 SHGetDocumentsFolder */

/* Boundary evidence: original MIPS .pdata 40574198..40574343. Semantic name remains unreviewed. */

int SHGetDocumentsFolder(wchar_t *param_1,wchar_t *param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  int iVar3;
  WCHAR aWStack_228 [260];
  uint local_20;
  
                    /* 0x4198  75  SHGetDocumentsFolder */
  local_20 = DAT_405a9a3c;
  iVar3 = 0;
  iVar1 = wcscmp(param_1,L"\\");
  if (iVar1 == 0) {
    iVar3 = SHGetSpecialFolderPath(0,param_2,5,1);
    if (iVar3 == 0) {
      *param_2 = L'\0';
    }
    goto LAB_40574318;
  }
  DVar2 = GetFileAttributesW(param_1);
  if ((DVar2 == 0xffffffff) || ((DVar2 & 0x110) != 0x110)) goto LAB_40574318;
  wsprintfW(aWStack_228,L"%s\\ignore_my_docs",param_1);
  DVar2 = GetFileAttributesW(aWStack_228);
  if (DVar2 == 0xffffffff) {
    wsprintfW(aWStack_228,L"%s\\My Documents",param_1);
    DVar2 = GetFileAttributesW(aWStack_228);
    if (DVar2 != 0xffffffff) {
      param_1 = aWStack_228;
      goto LAB_405742a4;
    }
    if (param_2 != param_1) {
      wcscpy(param_2,param_1);
    }
    wsprintfW(aWStack_228,L"%s\\ignore_my_docs",param_1);
    hObject = CreateFileW(aWStack_228,0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,2,2,(HANDLE)0x0);
    CloseHandle(hObject);
  }
  else if (param_2 != param_1) {
LAB_405742a4:
    wcscpy(param_2,param_1);
  }
  iVar3 = 1;
LAB_40574318:
  FUN_405a7174(local_20);
  return iVar3;
}



/* 40574344 SHGetMalloc */

/* Boundary evidence: original MIPS .pdata 40574344..405743b3. Semantic name remains unreviewed. */

HRESULT SHGetMalloc(IMalloc **ppMalloc)

{
  HRESULT HVar1;
  undefined4 *puVar2;
  IMalloc *pIVar3;
  
                    /* 0x4344  12  SHGetMalloc */
  if (ppMalloc == (IMalloc **)0x0) {
    HVar1 = -0x7ff8ffa9;
  }
  else {
    puVar2 = operator_new(8);
    if (puVar2 == (undefined4 *)0x0) {
      pIVar3 = (IMalloc *)0x0;
    }
    else {
      pIVar3 = (IMalloc *)FUN_40580eb4(puVar2);
    }
    *ppMalloc = pIVar3;
    if (pIVar3 == (IMalloc *)0x0) {
      HVar1 = -0x7ff8fff2;
    }
    else {
      HVar1 = 0;
    }
  }
  return HVar1;
}



/* 405743b4 SHGetSpecialFolderLocation */

/* Boundary evidence: original MIPS .pdata 405743b4..4057457f. Semantic name remains unreviewed. */

HRESULT SHGetSpecialFolderLocation(HWND hwnd,int csidl,LPITEMIDLIST *ppidl)

{
  DWORD DVar1;
  int iVar2;
  HRESULT HVar3;
  IID *pIVar4;
  uint uVar5;
  IShellFolder *local_228 [2];
  WCHAR aWStack_220 [260];
  uint local_18;
  
                    /* 0x43b4  10  SHGetSpecialFolderLocation */
  local_18 = DAT_405a9a3c;
  if (ppidl == (LPITEMIDLIST *)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    return -0x7ff8ffa9;
  }
  *ppidl = (LPITEMIDLIST)0x0;
  uVar5 = csidl & 0xffff7fff;
  if (uVar5 == 0) {
    DVar1 = __GetUserKData(0xc);
    DVar1 = GetProcessVersion(DVar1);
    if ((DVar1 >> 0x10 < 4) || ((DVar1 >> 0x10 == 4 && ((DVar1 & 0xffff) < 0x14)))) {
      uVar5 = 0x10;
      goto LAB_40574464;
    }
    pIVar4 = (IID *)&DAT_405719c0;
  }
  else {
LAB_40574464:
    if (uVar5 == 10) {
      pIVar4 = (IID *)&DAT_405719b0;
    }
    else if (uVar5 == 0x11) {
      pIVar4 = (IID *)&DAT_405719d0;
    }
    else {
      if (uVar5 != 0x12) {
        iVar2 = SHGetSpecialFolderPath(hwnd,aWStack_220,uVar5,csidl & 0x8000);
        if (iVar2 == 0) {
          DVar1 = GetLastError();
          if (DVar1 == 0x57) {
            HVar3 = -0x7ff8ffa9;
          }
          else {
            HVar3 = -0x7fffbffb;
          }
        }
        else {
          local_228[0] = (IShellFolder *)0x0;
          HVar3 = SHGetDesktopFolder(local_228);
          if (-1 < HVar3) {
            HVar3 = (*local_228[0]->lpVtbl->ParseDisplayName)
                              (local_228[0],hwnd,(IBindCtx *)0x0,aWStack_220,(ULONG *)0x0,ppidl,
                               (ULONG *)0x0);
            (*local_228[0]->lpVtbl->Release)(local_228[0]);
          }
        }
        goto LAB_4057455c;
      }
      pIVar4 = (IID *)&DAT_405719e0;
    }
  }
  HVar3 = FUN_40587d78(pIVar4,(int *)ppidl);
LAB_4057455c:
  FUN_405a7174(local_18);
  return HVar3;
}



/* 40574580 SHBindToParent */

/* Boundary evidence: original MIPS .pdata 40574580..40574757. Semantic name remains unreviewed. */

HRESULT SHBindToParent(LPCITEMIDLIST pidl,IID *riid,void **ppv,LPCITEMIDLIST *ppidlLast)

{
  int iVar1;
  ushort *puVar2;
  LPCITEMIDLIST pIVar3;
  HRESULT HVar4;
  IShellFolder *local_28;
  int *local_24;
  
                    /* 0x4580  82  SHBindToParent */
  if ((pidl == (LPCITEMIDLIST)0x0) || (ppv == (void **)0x0)) {
    HVar4 = -0x7ff8ffa9;
  }
  else {
    *ppv = (void *)0x0;
    local_28 = (IShellFolder *)0x0;
    local_24 = (int *)0x0;
    iVar1 = FUN_40581410((ushort *)pidl);
    if (iVar1 == 0) {
      HVar4 = -0x7fffbffb;
    }
    else {
      HVar4 = SHGetDesktopFolder(&local_28);
      if (-1 < HVar4) {
        if (iVar1 == 1) {
          HVar4 = (*local_28->lpVtbl->QueryInterface)(local_28,(IID *)&DAT_40572b68,&local_24);
        }
        else {
          pIVar3 = FUN_405813a0((ushort *)pidl,iVar1 + -1);
          if (pIVar3 == (LPCITEMIDLIST)0x0) {
            HVar4 = -0x7ff8fff2;
          }
          else {
            HVar4 = (*local_28->lpVtbl->BindToObject)
                              (local_28,pIVar3,(IBindCtx *)0x0,(IID *)&DAT_40572b68,&local_24);
            FUN_40580ef4(pIVar3);
          }
        }
        (*local_28->lpVtbl->Release)(local_28);
        if (-1 < HVar4) {
          HVar4 = (**(code **)*local_24)(local_24,riid,ppv);
          (**(code **)(*local_24 + 8))();
          if ((-1 < HVar4) && (ppidlLast != (LPCITEMIDLIST *)0x0)) {
            puVar2 = FUN_40581470((ushort *)pidl);
            pIVar3 = FUN_405813a0(puVar2,1);
            *ppidlLast = pIVar3;
            if (pIVar3 == (LPCITEMIDLIST)0x0) {
              (**(code **)(*(int *)*ppv + 8))();
              HVar4 = -0x7ff8fff2;
              *ppv = (void *)0x0;
            }
          }
        }
      }
    }
  }
  return HVar4;
}



/* 40574758 StrRetToBufW */

/* Boundary evidence: original MIPS .pdata 40574758..4057488b. Semantic name remains unreviewed. */

HRESULT StrRetToBufW(STRRET *pstr,LPCITEMIDLIST pidl,LPWSTR pszBuf,UINT cchBuf)

{
  IMalloc *This;
  HRESULT HVar1;
  _union_3888 *p_Var2;
  IMalloc *local_28 [2];
  
                    /* 0x4758  84  StrRetToBufW */
  if ((pstr == (STRRET *)0x0) || (pszBuf == (LPWSTR)0x0)) {
    HVar1 = -0x7ff8ffa9;
  }
  else {
    HVar1 = -0x7fffbffb;
    if (pstr->uType == 0) {
      p_Var2 = &pstr->u;
      if (p_Var2->pOleStr != (LPWSTR)0x0) {
        local_28[0] = (IMalloc *)0x0;
        HVar1 = SHGetMalloc(local_28);
        if (-1 < HVar1) {
          HVar1 = StringCchCopyW(pszBuf,cchBuf,p_Var2->pOleStr);
          This = local_28[0];
          (*local_28[0]->lpVtbl->Free)(local_28[0],p_Var2->pOleStr);
          (*This->lpVtbl->Release)(This);
          pstr->uType = 2;
          p_Var2->cStr[0] = '\0';
          if (-1 < HVar1) {
            return HVar1;
          }
        }
      }
    }
    else if (pstr->uType == 2) {
      mbstowcs(pszBuf,(pstr->u).cStr,cchBuf);
      return 0;
    }
    if (cchBuf != 0) {
      *pszBuf = L'\0';
    }
  }
  return HVar1;
}



/* 4057488c SHShowOutOfMemory */

/* Boundary evidence: original MIPS .pdata 4057488c..4057491f. Semantic name remains unreviewed. */

int SHShowOutOfMemory(HWND param_1)

{
  int iVar1;
  LPCWSTR lpCaption;
  LPCWSTR lpText;
  
                    /* 0x488c  86  SHShowOutOfMemory */
  iVar1 = WaitForAPIReady(0x51,0);
  if (iVar1 == 0) {
    lpCaption = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x8008,(LPWSTR)0x0,0);
    lpText = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x8007,(LPWSTR)0x0,0);
    iVar1 = MessageBoxW(param_1,lpText,lpCaption,0x10010);
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}



/* 40574920 FUN_40574920 */

/* Boundary evidence: original MIPS .pdata 40574920..405749fb. Semantic name remains unreviewed. */

HRESULT FUN_40574920(IShellFolder *param_1,IID *param_2,LPCITEMIDLIST param_3,void **param_4)

{
  HRESULT HVar1;
  int iVar2;
  IShellFolder *This;
  IShellFolder *local_res0 [4];
  
  local_res0[0] = param_1;
  if (param_1 == (IShellFolder *)0x0) {
    HVar1 = SHGetDesktopFolder(local_res0);
    if (HVar1 < 0) {
      return HVar1;
    }
    This = local_res0[0];
    if (local_res0[0] == (IShellFolder *)0x0) {
      return HVar1;
    }
  }
  else {
    This = (IShellFolder *)0x0;
  }
  iVar2 = FUN_40580fe8((char *)param_3);
  if (iVar2 == 0) {
    HVar1 = (*local_res0[0]->lpVtbl->BindToObject)
                      (local_res0[0],param_3,(IBindCtx *)0x0,param_2,param_4);
  }
  else {
    HVar1 = (*local_res0[0]->lpVtbl->QueryInterface)(local_res0[0],param_2,param_4);
  }
  if (This != (IShellFolder *)0x0) {
    (*This->lpVtbl->Release)(This);
  }
  return HVar1;
}



/* 405749fc SHGetPathFromIDList */

/* Boundary evidence: original MIPS .pdata 405749fc..40574b57. Semantic name remains unreviewed. */

undefined4 SHGetPathFromIDList(LPCITEMIDLIST param_1,wchar_t *param_2)

{
  HRESULT HVar1;
  int iVar2;
  LPCITEMIDLIST local_130;
  int *local_12c;
  uint local_128 [2];
  STRRET SStack_120;
  
                    /* 0x49fc  11  SHGetPathFromIDList */
  if ((param_1 != (LPCITEMIDLIST)0x0) && (param_2 != (wchar_t *)0x0)) {
    local_12c = (int *)0x0;
    local_130 = (LPCITEMIDLIST)0x0;
    HVar1 = SHBindToParent(param_1,(IID *)&DAT_40572b68,&local_12c,&local_130);
    if (-1 < HVar1) {
      iVar2 = FUN_4058150c((ushort *)local_130,&DAT_405719d0);
      if (iVar2 == 0) {
        HVar1 = (**(code **)(*local_12c + 0x2c))(local_12c,local_130,0x8000,&SStack_120);
        if ((-1 < HVar1) && (HVar1 = StrRetToBufW(&SStack_120,local_130,param_2,0x104), -1 < HVar1))
        {
          local_128[0] = 0x40000000;
          HVar1 = (**(code **)(*local_12c + 0x24))(local_12c,1,&local_130,local_128);
          if ((-1 < HVar1) && ((local_128[0] & 0x40000000) == 0)) {
            *param_2 = L'\0';
            HVar1 = -0x7fffbffb;
          }
        }
      }
      else {
        wcscpy(param_2,L"\\");
      }
      FUN_40580ef4(local_130);
      (**(code **)(*local_12c + 8))();
      if (-1 < HVar1) {
        return 1;
      }
    }
  }
  return 0;
}



/* 40574b58 SHGetFileInfo */

/* Boundary evidence: original MIPS .pdata 40574b58..4057507f. Semantic name remains unreviewed. */

undefined4 SHGetFileInfo(LPCWSTR param_1,DWORD param_2,undefined4 *param_3,int param_4,uint param_5)

{
  undefined4 *puVar1;
  int iVar2;
  LONG LVar3;
  HIMAGELIST himl;
  HICON pHVar4;
  undefined4 uVar5;
  DWORD DVar6;
  uint uVar7;
  UINT flags;
  LPCITEMIDLIST local_140;
  IShellFolder *local_13c;
  int *local_138;
  LPITEMIDLIST local_134;
  STRRET local_130;
  
                    /* 0x4b58  13  SHGetFileInfo */
  local_138 = (int *)0x0;
  local_140 = (LPCITEMIDLIST)0x0;
  uVar7 = 0;
  if (((param_1 == (LPCWSTR)0x0) || (param_3 == (undefined4 *)0x0)) || (param_4 != 0x2b4)) {
    DVar6 = 0x57;
    goto LAB_40575040;
  }
  if (((param_5 & 0xffffb0ee) != 0) || (((param_5 & 0x800) != 0 && ((param_5 & 0x10) != 0)))) {
    SetLastError(0x3ec);
    return 0;
  }
  if (((param_5 & 1) != 0) && ((param_5 & 0x4100) == 0)) {
    DVar6 = 0x3ec;
    goto LAB_40575040;
  }
  if (DAT_405a9a64 == (undefined4 *)0x0) {
    puVar1 = operator_new(0x28);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_405818a0(puVar1);
    }
    if ((puVar1 == (undefined4 *)0x0) || (iVar2 = FUN_40581c44(puVar1), iVar2 == 0)) {
      DVar6 = 0xe;
      goto LAB_40575040;
    }
    LVar3 = InterlockedCompareExchange((LONG *)&DAT_405a9a64,(LONG)puVar1,0);
    if (LVar3 != 0) {
      FUN_40581e58(puVar1);
      operator_delete(puVar1);
    }
  }
  if (((param_5 & 0x10) == 0) && (param_2 = GetFileAttributesW(param_1), param_2 == 0xffffffff)) {
    iVar2 = PathIsGUID(param_1);
    if (-1 < iVar2) {
      param_2 = 0;
      goto LAB_40574d80;
    }
    DVar6 = GetLastError();
    if (((*param_1 == L'\\') && (param_1[1] == L'\\')) &&
       ((DVar6 == 5 || (((DVar6 == 0x35 || (DVar6 == 0x4c7)) || (DVar6 == 0x4c6)))))) {
      param_2 = 0x110;
      if ((param_5 & 0x800) != 0) {
        param_5 = param_5 & 0xf7ff;
        param_3[2] = 0x60000000;
      }
      goto LAB_40574d80;
    }
  }
  else {
LAB_40574d80:
    if ((param_5 & 0x400) != 0) {
      FUN_405828c0(DAT_405a9a64,param_1,param_2,(STRSAFE_LPWSTR)(param_3 + 0x85),0x50);
    }
    if ((param_5 & 0x4100) != 0) {
      iVar2 = FUN_40582a10(DAT_405a9a64,param_1,param_2,0);
      param_3[1] = iVar2;
      if ((param_5 & 0x100) != 0) {
        flags = 0;
        himl = (HIMAGELIST)FUN_40581aa0(DAT_405a9a64,(uint)((param_5 & 1) != 0));
        iVar2 = PathIsLink(param_1);
        if (iVar2 != 0) {
          flags = 0x100;
        }
        pHVar4 = ImageList_GetIcon(himl,param_3[1],flags);
        *param_3 = pHVar4;
      }
    }
    if ((param_5 & 0xa00) == 0) {
LAB_40574ee8:
      if ((param_5 & 0x800) != 0) {
        local_13c = (IShellFolder *)0xffffffff;
        uVar7 = (**(code **)(*local_138 + 0x24))(local_138,1,&local_140,&local_13c);
        if (-1 < (int)uVar7) {
          param_3[2] = local_13c;
        }
      }
      if ((param_5 & 0x200) != 0) {
        local_130.uType = 0;
        memset(&local_130.u,0,0x104);
        uVar7 = (**(code **)(*local_138 + 0x2c))(local_138,local_140,0x4001,&local_130);
        if (-1 < (int)uVar7) {
          uVar7 = StrRetToBufW(&local_130,local_140,(LPWSTR)(param_3 + 3),0x104);
        }
      }
      if (local_138 != (int *)0x0) {
        (**(code **)(*local_138 + 8))(local_138);
        local_138 = (int *)0x0;
      }
      if (local_140 != (LPCITEMIDLIST)0x0) {
        FUN_40580ef4(local_140);
        local_140 = (LPCITEMIDLIST)0x0;
      }
      if (-1 < (int)uVar7) {
        if ((param_5 & 0x4100) != 0) {
          uVar5 = FUN_40581aa0(DAT_405a9a64,(uint)((param_5 & 1) != 0));
          return uVar5;
        }
        return 1;
      }
    }
    else {
      local_13c = (IShellFolder *)0x0;
      uVar7 = SHGetDesktopFolder(&local_13c);
      if (-1 < (int)uVar7) {
        local_134 = (LPCITEMIDLIST)0x0;
        uVar7 = (*local_13c->lpVtbl->ParseDisplayName)
                          (local_13c,(HWND)0x0,(IBindCtx *)0x0,param_1,(ULONG *)0x0,&local_134,
                           (ULONG *)0x0);
        if (-1 < (int)uVar7) {
          uVar7 = SHBindToParent(local_134,(IID *)&DAT_40572b68,&local_138,&local_140);
          FUN_40580ef4(local_134);
        }
        (*local_13c->lpVtbl->Release)(local_13c);
        if (-1 < (int)uVar7) goto LAB_40574ee8;
      }
    }
    if ((uVar7 & 0x1fff0000) == 0x70000) {
      DVar6 = uVar7 & 0xffff;
      goto LAB_40575040;
    }
  }
  DVar6 = 0x7e;
LAB_40575040:
  SetLastError(DVar6);
  return 0;
}



/* 40575080 SHAddToRecentDocs */

/* Boundary evidence: original MIPS .pdata 40575080..40575277. Semantic name remains unreviewed. */

void SHAddToRecentDocs(UINT uFlags,LPCVOID pv)

{
  int iVar1;
  HRESULT HVar2;
  LPWSTR pszSrc;
  STRSAFE_LPWSTR local_458 [2];
  _SHFILEOPSTRUCTW local_450;
  wchar_t awStack_430 [260];
  wchar_t local_228 [2];
  undefined1 auStack_224 [520];
  uint local_1c;
  
                    /* 0x5080  19  SHAddToRecentDocs */
  local_1c = DAT_405a9a3c;
  iVar1 = SHGetSpecialFolderPath(0,awStack_430,8,1);
  if (iVar1 != 0) {
    if (pv == (LPCVOID)0x0) {
      local_458[0] = (STRSAFE_LPWSTR)0x0;
      HVar2 = StringCbCatExW(awStack_430,0x206,L"\\*.*",local_458,(size_t *)0x0,0);
      if (-1 < HVar2) {
        local_458[0] = local_458[0] + 1;
        *local_458[0] = L'\0';
        local_450.hwnd = (HWND)0x0;
        memset(&local_450.wFunc,0,0x1a);
        local_450.pFrom = awStack_430;
        local_450.fFlags._0_1_ = 0x10;
        local_450.wFunc = 3;
        local_450.fFlags._1_1_ = 4;
        SHFileOperationW(&local_450);
      }
    }
    else if ((uFlags == 2) || (uFlags == 1)) {
      local_228[0] = L'\"';
      local_228[1] = L'\0';
      memset(auStack_224,0,0x208);
      if (uFlags == 2) {
        HVar2 = StringCbCatW(local_228,0x20c,pv);
        if (HVar2 < 0) goto LAB_40575254;
      }
      else {
        iVar1 = SHGetPathFromIDList(pv,local_228 + 1);
        if (iVar1 == 0) goto LAB_40575254;
      }
      HVar2 = StringCbCatW(awStack_430,0x208,L"\\");
      if (-1 < HVar2) {
        pszSrc = PathFindFileNameW(local_228);
        HVar2 = StringCbCatW(awStack_430,0x208,pszSrc);
        if (-1 < HVar2) {
          PathRemoveExtensionW(awStack_430);
          HVar2 = StringCbCatW(awStack_430,0x208,L".lnk");
          if ((-1 < HVar2) && (HVar2 = StringCbCatW(local_228,0x20c,L"\""), -1 < HVar2)) {
            SHCreateShortcut(awStack_430,local_228);
          }
        }
      }
    }
  }
LAB_40575254:
  FUN_405a7174(local_1c);
  return;
}



/* 40575278 FUN_40575278 */

/* Boundary evidence: original MIPS .pdata 40575278..405753cb. Semantic name remains unreviewed. */

ushort * FUN_40575278(HWND param_1,LRESULT param_2)

{
  LRESULT LVar1;
  ushort *puVar2;
  ushort *puVar3;
  int iVar4;
  ushort *puVar5;
  undefined4 local_38;
  LRESULT local_34;
  ushort *local_14;
  
  if ((param_2 != 0) || (param_2 = SendMessageW(param_1,0x110a,9,0), param_2 != 0)) {
    local_38 = 0x14;
    local_34 = param_2;
    LVar1 = SendMessageW(param_1,0x113e,0,(LPARAM)&local_38);
    if (LVar1 != 0) {
      puVar2 = FUN_405813a0(local_14,-1);
      while ((local_34 = SendMessageW(param_1,0x110a,3,local_34), local_34 != 0 &&
             (puVar2 != (ushort *)0x0))) {
        LVar1 = SendMessageW(param_1,0x113e,0,(LPARAM)&local_38);
        if (LVar1 == 0) {
          return puVar2;
        }
        puVar3 = FUN_405812ec(local_14,puVar2);
        FUN_40580ef4(puVar2);
        puVar2 = puVar3;
      }
      puVar3 = FUN_405813a0(puVar2,1);
      if (puVar3 == (ushort *)0x0) {
        return puVar2;
      }
      iVar4 = FUN_4058150c(puVar3,&DAT_405719c0);
      puVar5 = puVar2;
      if (iVar4 != 0) {
        puVar5 = (ushort *)FUN_40581214(puVar2);
        puVar5 = FUN_405813a0(puVar5,-1);
        FUN_40580ef4(puVar2);
      }
      FUN_40580ef4(puVar3);
      return puVar5;
    }
  }
  return (ushort *)0x0;
}



/* 405753cc FUN_405753cc */

/* Boundary evidence: original MIPS .pdata 405753cc..4057554f. Semantic name remains unreviewed. */

ushort * FUN_405753cc(int param_1,LPARAM param_2,ushort *param_3)

{
  HRESULT HVar1;
  LRESULT LVar2;
  LPCITEMIDLIST pIVar3;
  ushort *puVar4;
  ushort *puVar5;
  void **ppvVar6;
  IShellFolder *local_28 [2];
  
  local_28[0] = (IShellFolder *)0x0;
  puVar5 = (ushort *)0x0;
  if (param_3 == (ushort *)0x0) {
    return (ushort *)0x0;
  }
  HVar1 = SHGetDesktopFolder(local_28);
  if (-1 < HVar1) {
    if (local_28[0] == (IShellFolder *)0x0) {
      return (ushort *)0x0;
    }
    LVar2 = SendMessageW(*(HWND *)(param_1 + 0x24),0x110a,3,param_2);
    if ((LVar2 != *(int *)(param_1 + 0x2c)) || (*(int *)(param_1 + 0x30) == 0)) {
      ppvVar6 = (void **)(param_1 + 0x30);
      if (*ppvVar6 != (int *)0x0) {
        (**(code **)(*(int *)*ppvVar6 + 8))();
        *ppvVar6 = (void *)0x0;
      }
      if (LVar2 == 0) {
        puVar4 = FUN_40581470(param_3);
        if (puVar4 == param_3) {
          pIVar3 = (LPCITEMIDLIST)0x0;
        }
        else {
          pIVar3 = FUN_405813a0(param_3,-1);
          FUN_40581780((ushort *)pIVar3);
          param_3 = puVar4;
        }
      }
      else {
        pIVar3 = (LPCITEMIDLIST)FUN_40575278(*(HWND *)(param_1 + 0x24),LVar2);
      }
      *(LRESULT *)(param_1 + 0x2c) = LVar2;
      FUN_40574920(local_28[0],(IID *)&DAT_40572b68,pIVar3,ppvVar6);
      FUN_40580ef4(pIVar3);
      if (*ppvVar6 == (void *)0x0) goto LAB_40575508;
    }
    puVar5 = FUN_40581470(param_3);
  }
LAB_40575508:
  if (local_28[0] != (IShellFolder *)0x0) {
    (*local_28[0]->lpVtbl->Release)(local_28[0]);
  }
  return puVar5;
}



/* 40575550 FUN_40575550 */

/* Boundary evidence: original MIPS .pdata 40575550..405755a3. Semantic name remains unreviewed. */

void FUN_40575550(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_30 = 0x67;
  local_34 = 0xffff0001;
  local_18 = 0xffffffff;
  local_14 = 0xffffffff;
  local_20 = 0xffffffff;
  local_38 = param_2;
  local_10 = param_4;
  local_c = param_3;
  SendMessageW(param_1,0x1132,0,(LPARAM)&local_38);
  return;
}



/* 405755a4 FUN_405755a4 */

/* Boundary evidence: original MIPS .pdata 405755a4..405755f3. Semantic name remains unreviewed. */

int FUN_405755a4(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_3 + 0x1c))(param_3,0,param_1,param_2);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)(short)iVar1;
  }
  return iVar1;
}



/* 405755f4 FUN_405755f4 */

/* Boundary evidence: original MIPS .pdata 405755f4..405756f3. Semantic name remains unreviewed. */

int FUN_405755f4(HWND param_1,ushort *param_2)

{
  int lParam;
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  WPARAM wParam;
  
  lParam = SendMessageW(param_1,0x110a,0,0);
  do {
    while( true ) {
      if (lParam == 0) {
        return 0;
      }
      puVar1 = FUN_40575278(param_1,lParam);
      if (puVar1 != (ushort *)0x0) break;
      lParam = 0;
    }
    puVar2 = FUN_40581470(puVar1);
    iVar3 = FUN_405810a4((char *)param_2,(char *)puVar2);
    if (iVar3 == 0) {
      wParam = 1;
    }
    else {
      param_2 = (ushort *)FUN_40581214(param_2);
      iVar3 = FUN_40580fe8((char *)param_2);
      if (iVar3 != 0) {
        return lParam;
      }
      SendMessageW(param_1,0x1102,2,lParam);
      wParam = 4;
    }
    lParam = SendMessageW(param_1,0x110a,wParam,lParam);
    FUN_40580ef4(puVar1);
  } while( true );
}



/* 405756f4 FUN_405756f4 */

/* Boundary evidence: original MIPS .pdata 405756f4..405758ef. Semantic name remains unreviewed. */

undefined4 FUN_405756f4(int param_1,ushort *param_2)

{
  bool bVar1;
  LRESULT lParam;
  LPCITEMIDLIST pIVar2;
  LPCITEMIDLIST pIVar3;
  ushort *puVar4;
  int iVar5;
  char *pcVar6;
  LPCITEMIDLIST pIVar7;
  undefined3 extraout_var;
  WPARAM wParam;
  undefined4 uVar8;
  
  uVar8 = 0;
  lParam = SendMessageW(*(HWND *)(param_1 + 0x24),0x110a,4,0);
  if (lParam != 0) {
    SendMessageW(*(HWND *)(param_1 + 0x24),0x1102,2,lParam);
    pIVar2 = (LPCITEMIDLIST)FUN_40575278(*(HWND *)(param_1 + 0x24),lParam);
    if (pIVar2 != (LPCITEMIDLIST)0x0) {
      do {
        pIVar3 = FUN_405813a0(param_2,-1);
        if ((pIVar3 == (LPCITEMIDLIST)0x0) ||
           (puVar4 = FUN_405817c0(pIVar2,(ushort *)pIVar3), puVar4 == (ushort *)0x0)) {
LAB_405758a0:
          if (pIVar2 != (LPCITEMIDLIST)0x0) {
            FUN_40580ef4(pIVar2);
          }
          break;
        }
        iVar5 = FUN_40580fe8((char *)puVar4);
        if (iVar5 != 0) {
          SendMessageW(*(HWND *)(param_1 + 0x24),0x110b,9,lParam);
          uVar8 = 1;
          goto LAB_405758a0;
        }
        pcVar6 = FUN_40581214(puVar4);
        if (pcVar6 == (char *)0x0) goto LAB_405758a0;
        *pcVar6 = '\0';
        pcVar6[1] = '\0';
        wParam = 4;
        while( true ) {
          lParam = SendMessageW(*(HWND *)(param_1 + 0x24),0x110a,wParam,lParam);
          if (lParam == 0) goto LAB_405758a0;
          pIVar7 = (LPCITEMIDLIST)FUN_40575278(*(HWND *)(param_1 + 0x24),lParam);
          if (pIVar7 == (LPCITEMIDLIST)0x0) break;
          bVar1 = FUN_40581018(pIVar7,pIVar3);
          FUN_40580ef4(pIVar7);
          if (CONCAT31(extraout_var,bVar1) != 0) goto LAB_4057583c;
          wParam = 1;
        }
        lParam = 0;
LAB_4057583c:
        if (lParam == 0) goto LAB_405758a0;
        FUN_40580ef4(pIVar2);
        FUN_40580ef4(pIVar3);
        SendMessageW(*(HWND *)(param_1 + 0x24),0x1102,2,lParam);
        pIVar2 = (LPCITEMIDLIST)FUN_40575278(*(HWND *)(param_1 + 0x24),lParam);
      } while (pIVar2 != (LPCITEMIDLIST)0x0);
      if (pIVar3 != (LPCITEMIDLIST)0x0) {
        FUN_40580ef4(pIVar3);
      }
    }
  }
  return uVar8;
}



/* 405758f0 FUN_405758f0 */

/* Boundary evidence: original MIPS .pdata 405758f0..405759cf. Semantic name remains unreviewed. */

void FUN_405758f0(int param_1,int param_2)

{
  ushort *puVar1;
  undefined4 local_248;
  undefined4 local_244;
  WCHAR *local_238;
  undefined4 local_234;
  WCHAR local_220 [260];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  if ((*(uint *)(param_1 + 0x14) & 0x10) != 0) {
    local_248 = 1;
    local_244 = *(undefined4 *)(param_2 + 0x3c);
    local_238 = local_220;
    local_220[0] = L'\0';
    local_234 = 0x104;
    SendMessageW(*(HWND *)(param_1 + 0x24),0x113e,0,(LPARAM)&local_248);
    SetWindowTextW(*(HWND *)(param_1 + 0x28),local_220);
  }
  if ((*(int *)(param_1 + 0x18) != 0) &&
     (puVar1 = FUN_40575278(*(HWND *)(param_1 + 0x24),*(LRESULT *)(param_2 + 0x3c)),
     puVar1 != (ushort *)0x0)) {
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))
                (*(undefined4 *)(param_1 + 0x20),2,puVar1,*(undefined4 *)(param_1 + 0x1c));
    }
    FUN_40580ef4(puVar1);
  }
  FUN_405a7174(local_18);
  return;
}



/* 405759d0 FUN_405759d0 */

/* Boundary evidence: original MIPS .pdata 405759d0..40575c0f. Semantic name remains unreviewed. */

void FUN_405759d0(int param_1,int param_2)

{
  bool bVar1;
  LPCITEMIDLIST pidl;
  HRESULT HVar2;
  int iVar3;
  int *local_410;
  ushort *local_40c;
  uint local_408 [2];
  uint local_400;
  undefined4 local_3fc [3];
  undefined4 local_3f0;
  undefined4 local_3e8;
  undefined4 local_3e4;
  uint local_3e0;
  STRRET SStack_3d8;
  undefined4 local_2d0;
  undefined4 local_2cc [172];
  uint local_1c;
  
  local_1c = DAT_405a9a3c;
  local_400 = 0;
  memset(local_3fc,0,0x24);
  local_40c = *(ushort **)(param_2 + 0x30);
  if ((*(uint *)(param_2 + 0xc) & 99) != 0) {
    local_40c = FUN_405753cc(param_1,*(LPARAM *)(param_2 + 0x10),local_40c);
    if (local_40c != (ushort *)0x0) {
      local_3fc[0] = *(undefined4 *)(param_2 + 0x10);
      local_400 = 0;
      if ((*(uint *)(param_2 + 0xc) & 0x22) != 0) {
        local_2d0 = 0;
        memset(local_2cc,0,0x2b0);
        SHGetFileInfo(L".",0x10,&local_2d0,0x2b4,0x4010);
        local_3e4 = local_2cc[0];
        *(undefined4 *)(param_2 + 0x24) = local_2cc[0];
        local_3e8 = local_2cc[0];
        *(undefined4 *)(param_2 + 0x28) = local_2cc[0];
        local_400 = 0x22;
      }
      if (((*(uint *)(param_2 + 0xc) & 0x40) != 0) &&
         (pidl = (LPCITEMIDLIST)FUN_40575278(*(HWND *)(param_1 + 0x24),*(LRESULT *)(param_2 + 0x10))
         , pidl != (LPCITEMIDLIST)0x0)) {
        local_408[0] = 0x80000000;
        local_410 = (int *)0x0;
        HVar2 = SHBindToParent(pidl,(IID *)&DAT_40572b68,&local_410,(LPCITEMIDLIST *)0x0);
        if (-1 < HVar2) {
          iVar3 = (**(code **)(*local_410 + 0x24))(local_410,1,&local_40c,local_408);
          if (-1 < iVar3) {
            bVar1 = (local_408[0] & 0x80000000) == 0;
            if (bVar1) {
              *(undefined4 *)(param_2 + 0x2c) = 0;
            }
            else {
              *(undefined4 *)(param_2 + 0x2c) = 1;
            }
            local_3e0 = (uint)!bVar1;
            local_400 = local_400 | 0x40;
          }
          (**(code **)(*local_410 + 8))();
        }
        FUN_40580ef4(pidl);
      }
      if ((((*(uint *)(param_2 + 0xc) & 1) != 0) &&
          (iVar3 = (**(code **)(**(int **)(param_1 + 0x30) + 0x2c))
                             (*(int **)(param_1 + 0x30),local_40c,1,&SStack_3d8), -1 < iVar3)) &&
         (HVar2 = StrRetToBufW(&SStack_3d8,(LPCITEMIDLIST)0x0,*(LPWSTR *)(param_2 + 0x1c),
                               *(UINT *)(param_2 + 0x20)), -1 < HVar2)) {
        local_3f0 = *(undefined4 *)(param_2 + 0x1c);
        local_400 = local_400 | 1;
      }
      SendMessageW(*(HWND *)(param_1 + 0x24),0x113f,0,(LPARAM)&local_400);
    }
  }
  FUN_405a7174(local_1c);
  return;
}



/* 40575c10 FUN_40575c10 */

/* Boundary evidence: original MIPS .pdata 40575c10..40575e9f. Semantic name remains unreviewed. */

void FUN_40575c10(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  HWND hWnd;
  LRESULT LVar2;
  ushort *puVar3;
  int iVar4;
  HRESULT HVar5;
  uint bEnable;
  INT_PTR nResult;
  IShellFolder *local_468 [2];
  undefined4 local_460;
  LRESULT local_45c;
  WCHAR *local_450;
  undefined4 local_44c;
  undefined4 local_448;
  LPITEMIDLIST local_438 [2];
  WCHAR aWStack_430 [260];
  WCHAR local_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  bVar1 = true;
  if (param_2 == 1) {
    LVar2 = SendMessageW((HWND)param_1[9],0x110a,9,0);
    puVar3 = FUN_40575278((HWND)param_1[9],LVar2);
    local_460 = 3;
    local_450 = (WCHAR *)param_1[2];
    param_1[0xd] = puVar3;
    if (local_450 == (WCHAR *)0x0) {
      local_450 = local_228;
    }
    local_44c = 0x104;
    local_45c = LVar2;
    SendMessageW((HWND)param_1[9],0x113e,0,(LPARAM)&local_460);
    if ((param_1[5] & 0x10) != 0) {
      GetWindowTextW((HWND)param_1[10],aWStack_430,0x104);
      iVar4 = CompareStringW(0x400,1,aWStack_430,-1,local_450,-1);
      if (iVar4 != 2) {
        local_468[0] = (IShellFolder *)0x0;
        HVar5 = SHGetDesktopFolder(local_468);
        if (-1 < HVar5) {
          local_438[0] = (LPITEMIDLIST)0x0;
          HVar5 = (*local_468[0]->lpVtbl->ParseDisplayName)
                            (local_468[0],(HWND)*param_1,(IBindCtx *)0x0,aWStack_430,(ULONG *)0x0,
                             local_438,(ULONG *)0x0);
          if (-1 < HVar5) {
            FUN_40580ef4((HLOCAL)param_1[0xd]);
            param_1[0xd] = local_438[0];
            wcscpy(local_450,aWStack_430);
            local_448 = 0xffffffff;
          }
          (*local_468[0]->lpVtbl->Release)(local_468[0]);
          if (-1 < HVar5) goto LAB_40575e54;
        }
        if ((param_1[5] & 0x20) != 0) {
          FUN_40580ef4((HLOCAL)param_1[0xd]);
          param_1[0xd] = 0;
          *local_450 = L'\0';
          local_448 = 0xffffffff;
          if ((code *)param_1[6] == (code *)0x0) {
            iVar4 = 0;
          }
          else {
            iVar4 = (*(code *)param_1[6])(param_1[8],3,aWStack_430,param_1[7]);
          }
          if (iVar4 != 0) {
            bVar1 = false;
          }
        }
      }
    }
LAB_40575e54:
    if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
      *(undefined4 *)param_1[3] = local_448;
    }
    if (!bVar1) goto LAB_40575e7c;
    nResult = 1;
  }
  else {
    if (param_2 != 2) {
      if ((param_2 == 0x2103) && (param_4 == 0x300)) {
        local_438[0] = (LPITEMIDLIST)CONCAT22(local_438[0]._2_2_,1);
        GetDlgItemTextW((HWND)param_1[8],0x2103,(LPWSTR)local_438,4);
        bEnable = (uint)local_438[0] & 0xffff;
        hWnd = GetDlgItem((HWND)param_1[8],1);
        EnableWindow(hWnd,bEnable);
      }
      goto LAB_40575e7c;
    }
    nResult = 0;
  }
  EndDialog((HWND)param_1[8],nResult);
LAB_40575e7c:
  FUN_405a7174(local_20);
  return;
}



/* 40575ea0 FUN_40575ea0 */

/* Boundary evidence: original MIPS .pdata 40575ea0..40575f13. Semantic name remains unreviewed. */

void FUN_40575ea0(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 local_20;
  code *local_1c;
  int *local_18;
  
  local_1c = FUN_405755a4;
  local_20 = param_2;
  (**(code **)(*param_3 + 4))(param_3);
  local_18 = param_3;
  SendMessageW(*(HWND *)(param_1 + 0x24),0x1115,0,(LPARAM)&local_20);
  (**(code **)(*param_3 + 8))(param_3);
  return;
}



/* 40575f14 FUN_40575f14 */

/* Boundary evidence: original MIPS .pdata 40575f14..4057619f. Semantic name remains unreviewed. */

undefined4 FUN_40575f14(int param_1,int param_2)

{
  LRESULT LVar1;
  LPCITEMIDLIST pIVar2;
  HRESULT HVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  IShellFolder *local_58;
  int *local_54;
  int *local_50;
  int local_4c;
  undefined4 local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_20;
  
  iVar6 = 0;
  if ((*(int *)(param_2 + 0xc) == 2) && ((*(uint *)(param_2 + 0x40) & 0x40) == 0)) {
    local_3c = *(undefined4 *)(param_2 + 0x3c);
    local_40 = 8;
    local_38 = 0x40;
    local_34 = 0x40;
    SendMessageW(*(HWND *)(param_1 + 0x24),0x113f,0,(LPARAM)&local_40);
    if (*(int *)(param_2 + 0x3c) == 0) {
      LVar1 = SendMessageW(*(HWND *)(param_1 + 0x24),0x110a,9,0);
      *(LRESULT *)(param_2 + 0x3c) = LVar1;
      if (LVar1 == 0) {
        return 0;
      }
    }
    pIVar2 = (LPCITEMIDLIST)FUN_40575278(*(HWND *)(param_1 + 0x24),*(LRESULT *)(param_2 + 0x3c));
    HVar3 = SHGetDesktopFolder(&local_58);
    if ((-1 < HVar3) && (local_58 != (IShellFolder *)0x0)) {
      HVar3 = FUN_40574920(local_58,(IID *)&DAT_40572b68,pIVar2,&local_54);
      if (HVar3 < 0) {
        if (pIVar2 != (LPCITEMIDLIST)0x0) {
          FUN_40580ef4(pIVar2);
        }
        (*local_58->lpVtbl->Release)(local_58);
      }
      else {
        uVar5 = 0x20;
        if ((*(uint *)(param_1 + 0x38) & 1) != 0) {
          uVar5 = 0xa0;
        }
        iVar4 = (**(code **)(*local_54 + 0x10))
                          (local_54,*(undefined4 *)(param_1 + 0x20),uVar5,&local_50);
        if (iVar4 < 0) {
          if (pIVar2 != (LPCITEMIDLIST)0x0) {
            FUN_40580ef4(pIVar2);
          }
          (*local_58->lpVtbl->Release)(local_58);
          (**(code **)(*local_54 + 8))();
        }
        else {
          while ((iVar4 = (**(code **)(*local_50 + 0xc))(local_50,1,local_48,&local_4c), iVar4 == 0
                 && (local_4c == 1))) {
            FUN_40575550(*(HWND *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x3c),local_48[0],
                         0xffffffff);
            iVar6 = iVar6 + 1;
          }
          (**(code **)(*local_50 + 8))();
          FUN_40575ea0(param_1,*(undefined4 *)(param_2 + 0x3c),local_54);
          if (pIVar2 != (LPCITEMIDLIST)0x0) {
            FUN_40580ef4(pIVar2);
          }
          (*local_58->lpVtbl->Release)(local_58);
          (**(code **)(*local_54 + 8))();
          if (iVar6 != 0) {
            return 1;
          }
        }
        local_40 = 0x50;
        local_3c = *(undefined4 *)(param_2 + 0x3c);
        local_20 = 0;
        SendMessageW(*(HWND *)(param_1 + 0x24),0x113f,0,(LPARAM)&local_40);
      }
    }
  }
  return 0;
}



/* 405761a0 FUN_405761a0 */

/* Boundary evidence: original MIPS .pdata 405761a0..4057628b. Semantic name remains unreviewed. */

LRESULT FUN_405761a0(undefined4 *param_1,int param_2,LPWSTR param_3)

{
  HRESULT HVar1;
  int lParam;
  LRESULT LVar2;
  LPITEMIDLIST local_18;
  IShellFolder *local_14;
  
  LVar2 = 0;
  if (param_2 == 0) {
    LVar2 = FUN_405756f4((int)param_1,(ushort *)param_3);
  }
  else {
    local_14 = (IShellFolder *)0x0;
    HVar1 = SHGetDesktopFolder(&local_14);
    if (-1 < HVar1) {
      local_18 = (LPITEMIDLIST)0x0;
      HVar1 = (*local_14->lpVtbl->ParseDisplayName)
                        (local_14,(HWND)*param_1,(IBindCtx *)0x0,param_3,(ULONG *)0x0,&local_18,
                         (ULONG *)0x0);
      if (-1 < HVar1) {
        lParam = FUN_405755f4((HWND)param_1[9],(ushort *)local_18);
        if (lParam != 0) {
          LVar2 = SendMessageW((HWND)param_1[9],0x110b,9,lParam);
        }
        FUN_40580ef4(local_18);
      }
      (*local_14->lpVtbl->Release)(local_14);
    }
  }
  return LVar2;
}



/* 4057628c FUN_4057628c */

/* Boundary evidence: original MIPS .pdata 4057628c..405765cf. Semantic name remains unreviewed. */

undefined4 FUN_4057628c(HWND param_1,undefined4 param_2,int param_3)

{
  HWND hWnd;
  HWND pHVar1;
  int iVar2;
  LPARAM LVar3;
  uint uVar4;
  LRESULT LVar5;
  ushort *csidl;
  UINT uFlags;
  tagPOINT local_388;
  tagRECT local_380;
  tagRECT tStack_370;
  undefined4 local_360;
  LRESULT local_35c;
  undefined4 local_33c;
  undefined1 auStack_338 [60];
  LRESULT local_2fc;
  undefined4 local_2dc;
  undefined4 local_2d0;
  undefined1 auStack_2cc [688];
  uint local_1c;
  
  local_1c = DAT_405a9a3c;
  FUN_405a6df8(param_1);
  SetWindowLongW(param_1,8,param_3);
  *(HWND *)(param_3 + 0x20) = param_1;
  hWnd = GetDlgItem(param_1,0x2104);
  *(HWND *)(param_3 + 0x24) = hWnd;
  if (*(LPCWSTR *)(param_3 + 0x10) != (LPCWSTR)0x0) {
    SetDlgItemTextW(param_1,0x2101,*(LPCWSTR *)(param_3 + 0x10));
  }
  if (hWnd != (HWND)0x0) {
    local_388.x = 0;
    local_388.y = 0;
    uFlags = 0x37;
    GetClientRect(hWnd,&local_380);
    MapWindowPoints(hWnd,param_1,(LPPOINT)&local_380,2);
    pHVar1 = GetDlgItem(param_1,0x2103);
    *(HWND *)(param_3 + 0x28) = pHVar1;
    if ((*(uint *)(param_3 + 0x14) & 4) == 0) {
      pHVar1 = GetDlgItem(param_1,0x2102);
      ShowWindow(pHVar1,0);
      MapWindowPoints(pHVar1,param_1,&local_388,1);
      uFlags = 0x34;
      local_380.top = local_388.y;
    }
    if ((*(uint *)(param_3 + 0x14) & 0x10) == 0) {
      DestroyWindow(*(HWND *)(param_3 + 0x28));
      *(undefined4 *)(param_3 + 0x28) = 0;
    }
    else {
      GetClientRect(*(HWND *)(param_3 + 0x28),&tStack_370);
      SetWindowPos(*(HWND *)(param_3 + 0x28),(HWND)0x0,local_380.left,local_380.top,0,0,0x15);
      iVar2 = GetSystemMetrics(0x2e);
      local_380.top = (iVar2 * 4 - tStack_370.top) + tStack_370.bottom + local_380.top;
      uFlags = 0x34;
    }
    local_2d0 = 0;
    memset(auStack_2cc,0,0x2b0);
    LVar3 = SHGetFileInfo(L"",0,&local_2d0,0x2b4,0x4001);
    SendMessageW(hWnd,0x1109,0,LVar3);
    uVar4 = GetWindowLongW(hWnd,-0x14);
    SetWindowLongW(hWnd,-0x14,uVar4 | 0x200);
    SetWindowPos(hWnd,(HWND)0x0,local_380.left,local_380.top,local_380.right - local_380.left,
                 local_380.bottom - local_380.top,uFlags);
  }
  csidl = *(ushort **)(param_3 + 4);
  if (csidl == (ushort *)0x0) {
    local_388.x = 0;
    SHGetSpecialFolderLocation(param_1,0x11,(LPITEMIDLIST *)&local_388);
  }
  else if (((uint)csidl & 0xffff0000) == 0) {
    local_388.x = 0;
    SHGetSpecialFolderLocation(param_1,(int)csidl,(LPITEMIDLIST *)&local_388);
  }
  else {
    local_388.x = (LONG)FUN_405813a0(csidl,-1);
  }
  LVar3 = FUN_40575550(hWnd,0xffff0000,local_388.x,1);
  SendMessageW(hWnd,0x1102,2,LVar3);
  LVar5 = SendMessageW(hWnd,0x110a,9,0);
  if (LVar5 != 0) {
    local_360 = 4;
    local_35c = LVar5;
    SendMessageW(hWnd,0x113e,0,(LPARAM)&local_360);
    local_2dc = local_33c;
    local_2fc = LVar5;
    FUN_405758f0(param_3,(int)auStack_338);
  }
  FUN_405a6ca0(param_1,2);
  if (*(code **)(param_3 + 0x18) != (code *)0x0) {
    (**(code **)(param_3 + 0x18))
              (*(undefined4 *)(param_3 + 0x20),1,0,*(undefined4 *)(param_3 + 0x1c));
  }
  FUN_405a7174(local_1c);
  return 1;
}



/* 405765d0 FUN_405765d0 */

/* Boundary evidence: original MIPS .pdata 405765d0..40576807. Semantic name remains unreviewed. */

LRESULT FUN_405765d0(HWND param_1,int param_2,uint param_3,LPWSTR param_4)

{
  undefined4 *puVar1;
  LRESULT LVar2;
  HWND hWnd;
  HCURSOR pHVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)GetWindowLongW(param_1,8);
  if (param_2 == 2) {
    if ((int *)puVar1[0xc] != (int *)0x0) {
      (**(code **)(*(int *)puVar1[0xc] + 8))();
      puVar1[0xc] = 0;
    }
    FUN_405a6bf8();
    return 1;
  }
  if (param_2 != 0x4e) {
    if (param_2 == 0x53) {
      return 1;
    }
    if (param_2 == 0x110) {
      FUN_405a6b40();
      LVar2 = FUN_4057628c(param_1,param_3,(int)param_4);
      return LVar2;
    }
    if (param_2 == 0x111) {
      FUN_40575c10(puVar1,param_3 & 0xffff,param_4,param_3 >> 0x10);
    }
    else {
      if (param_2 == 0x465) {
        hWnd = GetDlgItem(param_1,1);
        EnableWindow(hWnd,(BOOL)param_4);
        return 1;
      }
      if (param_2 == 0x466) {
        LVar2 = FUN_405761a0(puVar1,param_3,param_4);
        return LVar2;
      }
    }
    return 0;
  }
  iVar4 = *(int *)(param_4 + 4);
  if (iVar4 == -0x1ca) {
    if (*(HLOCAL *)(param_4 + 0x1a) == (HLOCAL)0x0) {
      return 1;
    }
    FUN_40580ef4(*(HLOCAL *)(param_4 + 0x1a));
    return 1;
  }
  if (iVar4 != -0x1c7) {
    if (iVar4 != -0x1c6) {
      if (iVar4 == -0x1c4) {
        FUN_405759d0((int)puVar1,(int)param_4);
        return 1;
      }
      if (iVar4 != -0x1c3) {
        return 1;
      }
      FUN_405758f0((int)puVar1,(int)param_4);
      return 1;
    }
    pHVar3 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    SetCursor(pHVar3);
    iVar4 = FUN_40575f14((int)puVar1,(int)param_4);
    if (iVar4 != 0) {
      return 1;
    }
  }
  pHVar3 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  SetCursor(pHVar3);
  return 1;
}



/* 40576808 SHBrowseForFolder */

/* Boundary evidence: original MIPS .pdata 40576808..40576943. Semantic name remains unreviewed. */

undefined4 SHBrowseForFolder(undefined4 *param_1)

{
  HCURSOR pHVar1;
  int iVar2;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar3;
  undefined4 uVar4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [20];
  undefined4 local_24;
  
                    /* 0x6808  83  SHBrowseForFolder */
  if (param_1 == (undefined4 *)0x0) {
    uVar4 = 0;
  }
  else {
    local_58 = *param_1;
    local_54 = param_1[1];
    local_50 = param_1[2];
    local_48 = param_1[3];
    local_44 = param_1[4];
    local_40 = param_1[5];
    local_3c = param_1[6];
    local_4c = param_1 + 7;
    memset(auStack_38,0,0x1c);
    pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar1 = SetCursor(pHVar1);
    iVar2 = FUN_405a6b40();
    if (iVar2 != 0) {
      FUN_405a6d64();
    }
    hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2100,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
    IVar3 = DialogBoxIndirectParamW
                      (DAT_405aa0c0,hDialogTemplate,(HWND)*param_1,FUN_405765d0,(LPARAM)&local_58);
    uVar4 = 0;
    if (IVar3 != 0) {
      uVar4 = local_24;
    }
    if (pHVar1 != (HCURSOR)0x0) {
      SetCursor(pHVar1);
    }
    FUN_405a6bf8();
  }
  return uVar4;
}



/* 40576944 FUN_40576944 */

/* Boundary evidence: original MIPS .pdata 40576944..40576bdf. Semantic name remains unreviewed. */

undefined4 FUN_40576944(LPCWSTR param_1,LPWSTR param_2,int param_3)

{
  char cVar1;
  UINT CodePage;
  BOOL BVar2;
  LSTATUS LVar3;
  size_t sVar4;
  int iVar5;
  char *pcVar6;
  HANDLE hFile;
  DWORD DVar7;
  undefined4 uVar8;
  UINT local_348;
  DWORD local_344;
  DWORD local_340;
  DWORD DStack_33c;
  char local_338 [780];
  uint local_2c;
  
  local_2c = DAT_405a9a3c;
  uVar8 = 0;
  hFile = (HANDLE)0xffffffff;
  if ((((param_1 == (LPCWSTR)0x0) || (param_2 == (LPWSTR)0x0)) || (*param_1 == L'\0')) ||
     (param_3 == 0)) {
    DVar7 = 0x57;
LAB_40576b80:
    SetLastError(DVar7);
  }
  else {
    hFile = CreateFileW(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (hFile == (HANDLE)0xffffffff) goto LAB_40576ba8;
    SetFilePointer(hFile,0,(PLONG)0x0,0);
    BVar2 = ReadFile(hFile,local_338,0x30b,&local_340,(LPOVERLAPPED)0x0);
    if (BVar2 != 0) {
      local_338[local_340] = '\0';
      if (((local_338[0] == -0x11) && (local_338[1] == -0x45)) && (local_338[2] == -0x41)) {
        local_348 = 0xfde9;
        DVar7 = 0;
        pcVar6 = local_338 + 3;
      }
      else {
        local_344 = 4;
        LVar3 = RegQueryValueExW((HKEY)0x80000002,L"ACP",
                                 (LPDWORD)L"SOFTWARE\\Microsoft\\International",&DStack_33c,
                                 (LPBYTE)&local_348,&local_344);
        if (LVar3 != 0) {
          local_348 = 0;
        }
        DVar7 = 1;
        pcVar6 = local_338;
      }
      CodePage = local_348;
      cVar1 = *pcVar6;
      while (cVar1 != '\0') {
        if (cVar1 == '#') {
          sVar4 = strlen(pcVar6 + 1);
          iVar5 = MultiByteToWideChar(CodePage,DVar7,pcVar6 + 1,sVar4 + 1,param_2,param_3);
          if (iVar5 != 0) {
            SetLastError(0);
            uVar8 = 1;
          }
          goto LAB_40576b90;
        }
        if ((cVar1 < '0') || ('9' < cVar1)) break;
        pcVar6 = pcVar6 + 1;
        cVar1 = *pcVar6;
      }
      DVar7 = 0xb;
      goto LAB_40576b80;
    }
  }
LAB_40576b90:
  if (hFile != (HANDLE)0xffffffff) {
    CloseHandle(hFile);
  }
LAB_40576ba8:
  FUN_405a7174(local_2c);
  return uVar8;
}



/* 40576be0 SHGetShortcutTarget */

/* Boundary evidence: original MIPS .pdata 40576be0..40576bfb. Semantic name remains unreviewed. */

void SHGetShortcutTarget(LPCWSTR param_1,LPWSTR param_2,int param_3)

{
                    /* 0x6be0  18  SHGetShortcutTarget */
  FUN_40576944(param_1,param_2,param_3);
  return;
}



/* 40576bfc FUN_40576bfc */

/* Boundary evidence: original MIPS .pdata 40576bfc..40576fbf. Semantic name remains unreviewed. */

undefined4 FUN_40576bfc(HANDLE param_1,STRSAFE_LPCWSTR param_2)

{
  HRESULT HVar1;
  LPWSTR pWVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  BOOL BVar7;
  LPSTR pCVar8;
  DWORD nNumberOfBytesToWrite;
  LPSTR lpMultiByteStr;
  DWORD dwErrCode;
  undefined4 uVar9;
  DWORD aDStack_650 [2];
  wchar_t awStack_648 [260];
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  uVar9 = 0;
  dwErrCode = 0;
  lpMultiByteStr = (LPSTR)0x0;
  if (param_2 == (STRSAFE_LPCWSTR)0x0) {
    dwErrCode = 0x57;
    goto LAB_40576f68;
  }
  HVar1 = StringCchCopyW(awStack_648,0x104,param_2);
  if (HVar1 < 0) {
LAB_40576f48:
    dwErrCode = 0xce;
  }
  else {
    pWVar2 = PathGetArgsW(awStack_648);
    HVar1 = StringCchCopyW(awStack_238,0x104,pWVar2);
    if (HVar1 < 0) goto LAB_40576f48;
    PathRemoveQuotesAndArgs(awStack_648);
    iVar3 = PathIsLink(awStack_648);
    if (iVar3 != 0) {
      iVar3 = FUN_40576944(awStack_648,awStack_648,0x104);
      if (iVar3 != 0) {
        pWVar2 = PathGetArgsW(awStack_648);
        wcscpy(awStack_238,pWVar2);
        PathRemoveQuotesAndArgs(awStack_648);
        goto LAB_40576cd8;
      }
      goto LAB_40576f10;
    }
LAB_40576cd8:
    sVar4 = wcslen(awStack_238);
    if (sVar4 != 0) {
      sVar4 = sVar4 + 1;
    }
    sVar5 = wcslen(awStack_648);
    HVar1 = StringCchPrintfW(awStack_440,0x104,L"%d#\"%s\"",sVar5 + sVar4 + 2,awStack_648);
    if (HVar1 < 0) {
      dwErrCode = 0xce;
      goto LAB_40576f68;
    }
    sVar4 = wcslen(awStack_440);
    iVar3 = WideCharToMultiByte(0xfde9,0,awStack_440,sVar4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    lpMultiByteStr = (LPSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,iVar3 + 3);
    if (lpMultiByteStr == (LPSTR)0x0) {
      SetLastError(0xe);
LAB_40576f10:
      dwErrCode = GetLastError();
      SetFilePointer(param_1,0,(PLONG)0x0,0);
    }
    else {
      *lpMultiByteStr = -0x11;
      lpMultiByteStr[1] = -0x45;
      lpMultiByteStr[2] = -0x41;
      sVar4 = wcslen(awStack_440);
      iVar6 = WideCharToMultiByte(0xfde9,0,awStack_440,sVar4,lpMultiByteStr + 3,iVar3,(LPCSTR)0x0,
                                  (LPBOOL)0x0);
      if ((iVar6 == 0) ||
         (BVar7 = WriteFile(param_1,lpMultiByteStr,iVar6 + 3,aDStack_650,(LPOVERLAPPED)0x0),
         BVar7 == 0)) goto LAB_40576f10;
      sVar4 = wcslen(awStack_238);
      if (sVar4 != 0) {
        HVar1 = StringCchPrintfW(awStack_440,0x104,L" %s",awStack_238);
        if (HVar1 < 0) goto LAB_40576f48;
        sVar4 = wcslen(awStack_440);
        iVar6 = WideCharToMultiByte(0xfde9,0,awStack_440,sVar4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0)
        ;
        pCVar8 = (LPSTR)(**(code **)(*DAT_405aa0c8 + 0x10))(DAT_405aa0c8,lpMultiByteStr,iVar6);
        if (pCVar8 != (LPSTR)0x0) {
          lpMultiByteStr = pCVar8;
          iVar3 = iVar6;
        }
        sVar4 = wcslen(awStack_440);
        nNumberOfBytesToWrite =
             WideCharToMultiByte(0xfde9,0,awStack_440,sVar4,lpMultiByteStr,iVar3,(LPCSTR)0x0,
                                 (LPBOOL)0x0);
        if ((nNumberOfBytesToWrite == 0) ||
           (BVar7 = WriteFile(param_1,lpMultiByteStr,nNumberOfBytesToWrite,aDStack_650,
                              (LPOVERLAPPED)0x0), BVar7 == 0)) goto LAB_40576f10;
      }
      uVar9 = 1;
    }
  }
  if (lpMultiByteStr != (LPSTR)0x0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpMultiByteStr);
  }
LAB_40576f68:
  SetEndOfFile(param_1);
  SetLastError(dwErrCode);
  FUN_405a7174(local_30);
  return uVar9;
}



/* 40576fc0 FUN_40576fc0 */

/* Boundary evidence: original MIPS .pdata 40576fc0..4057733b. Semantic name remains unreviewed. */

undefined4
FUN_40576fc0(wchar_t *param_1,wchar_t *param_2,STRSAFE_LPCWSTR param_3,wchar_t *param_4,
            uint *param_5,DWORD param_6,int param_7)

{
  size_t sVar1;
  size_t sVar2;
  HRESULT HVar3;
  int iVar4;
  LSTATUS LVar5;
  BOOL BVar6;
  code *pcVar7;
  HANDLE pvVar8;
  undefined4 uVar9;
  int iVar10;
  HKEY local_650;
  DWORD local_64c;
  wchar_t awStack_648 [260];
  wchar_t awStack_440 [7];
  undefined1 auStack_432 [504];
  undefined2 local_23a;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  iVar10 = 0;
  pvVar8 = (HANDLE)0xce;
  uVar9 = 0;
  sVar1 = wcslen(param_1);
  pcVar7 = SetLastError_exref;
  if (sVar1 + 1 < 0x102) {
    sVar1 = wcslen(param_2);
    sVar2 = wcslen(param_3);
    pcVar7 = SetLastError_exref;
    if (((sVar2 + sVar1 + 2 < 0x104) &&
        (HVar3 = StringCchCopyW(awStack_648,0x104,param_2), pcVar7 = SetLastError_exref, -1 < HVar3)
        ) && ((iVar4 = wcscmp(awStack_648,L"\\"), iVar4 == 0 ||
              (HVar3 = StringCchCatW(awStack_648,0x104,L"\\"), pcVar7 = SetLastError_exref,
              -1 < HVar3)))) {
      iVar4 = PathIsGUID(param_3);
      if (iVar4 == 0) {
        local_650 = (HKEY)0x0;
        memcpy(awStack_440,L"CLSID\\",0xe);
        memset(auStack_432,0,0x1fa);
        local_64c = 0x208;
        HVar3 = StringCchCatW(awStack_440,0x104,param_3);
        pcVar7 = SetLastError_exref;
        if (-1 < HVar3) {
          LVar5 = RegOpenKeyExW((HKEY)0x80000000,awStack_440,0,0,&local_650);
          if (LVar5 == 0) {
            LVar5 = RegQueryValueExW(local_650,L"DisplayName",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)awStack_440,&local_64c);
            RegCloseKey(local_650);
            local_23a = 0;
            if (LVar5 == 0) {
              param_3 = awStack_440;
              goto LAB_40577184;
            }
          }
          goto LAB_40577198;
        }
      }
      else {
LAB_40577184:
        HVar3 = StringCchCatW(awStack_648,0x104,param_3);
        pcVar7 = SetLastError_exref;
        if (-1 < HVar3) {
LAB_40577198:
          if (param_7 == 0) goto LAB_405772d8;
          HVar3 = StringCchCopyW(awStack_238,0x104,param_1);
          pcVar7 = SetLastError_exref;
          if (-1 < HVar3) {
            PathRemoveQuotesAndArgs(awStack_238);
            BVar6 = PathIsDirectoryW(awStack_238);
            iVar4 = PathIsLink(awStack_238);
            if (iVar4 == 0) {
              iVar10 = LoadStringW(DAT_405aa0c0,0x8009,(LPWSTR)0x0,0);
            }
            HVar3 = StringCchCopyW(awStack_238,0x104,awStack_648);
            pcVar7 = SetLastError_exref;
            if (-1 < HVar3) {
              iVar10 = PathMakeUniqueNameEx(awStack_238,iVar10,0,1,BVar6,awStack_648,0x104);
              if (iVar10 == 0) {
                pvVar8 = (HANDLE)0x50;
                pcVar7 = SetLastError_exref;
              }
              else {
                if ((param_4 != (wchar_t *)0x0) && (param_5 != (uint *)0x0)) {
                  sVar1 = wcslen(awStack_648);
                  if (*param_5 < sVar1 + 1) {
                    *param_5 = sVar1 + 1;
                    pvVar8 = (HANDLE)0x7a;
                    pcVar7 = SetLastError_exref;
                    goto LAB_40577250;
                  }
                  wcscpy(param_4,awStack_648);
                }
LAB_405772d8:
                pvVar8 = CreateFileW(awStack_648,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,param_6,
                                     0x80,(HANDLE)0x0);
                if (pvVar8 == (HANDLE)0xffffffff) goto LAB_40577258;
                uVar9 = FUN_40576bfc(pvVar8,param_1);
                pcVar7 = CloseHandle_exref;
              }
            }
          }
        }
      }
    }
  }
LAB_40577250:
  (*pcVar7)(pvVar8);
LAB_40577258:
  FUN_405a7174(local_30);
  return uVar9;
}



/* 4057733c SHCreateShortcut */

/* Boundary evidence: original MIPS .pdata 4057733c..4057744b. Semantic name remains unreviewed. */

undefined4 SHCreateShortcut(wchar_t *param_1,wchar_t *param_2)

{
  size_t sVar1;
  int iVar2;
  HRESULT HVar3;
  LPWSTR pWVar4;
  DWORD dwErrCode;
  undefined4 uVar5;
  wchar_t awStack_228 [260];
  uint local_20;
  
                    /* 0x733c  17  SHCreateShortcut */
  local_20 = DAT_405a9a3c;
  uVar5 = 0;
  dwErrCode = 0x57;
  if ((((param_1 != (wchar_t *)0x0) && (param_2 != (wchar_t *)0x0)) && (*param_1 != L'\0')) &&
     (*param_2 != L'\0')) {
    sVar1 = wcslen(param_1);
    if (sVar1 + 1 < 0x104) {
      iVar2 = PathIsValidPath(param_1);
      if (iVar2 == 0) goto LAB_405773b0;
      HVar3 = StringCchCopyW(awStack_228,0x104,param_1);
      if (-1 < HVar3) {
        PathRemoveFileSpecW(awStack_228);
        pWVar4 = PathFindFileNameW(param_1);
        uVar5 = FUN_40576fc0(param_2,awStack_228,pWVar4,(wchar_t *)0x0,(uint *)0x0,1,0);
        goto LAB_405773c0;
      }
    }
    dwErrCode = 0xce;
  }
LAB_405773b0:
  SetLastError(dwErrCode);
LAB_405773c0:
  FUN_405a7174(local_20);
  return uVar5;
}



/* 4057744c SHCreateShortcutEx */

/* Boundary evidence: original MIPS .pdata 4057744c..4057755b. Semantic name remains unreviewed. */

undefined4 SHCreateShortcutEx(LPCWSTR param_1,wchar_t *param_2,wchar_t *param_3,uint *param_4)

{
  int iVar1;
  HRESULT HVar2;
  LPWSTR pWVar3;
  DWORD dwErrCode;
  undefined4 uVar4;
  wchar_t awStack_230 [260];
  uint local_28;
  
                    /* 0x744c  85  SHCreateShortcutEx */
  local_28 = DAT_405a9a3c;
  uVar4 = 0;
  dwErrCode = 0x57;
  if ((((param_1 != (LPCWSTR)0x0) && (param_2 != (wchar_t *)0x0)) && (*param_1 != L'\0')) &&
     ((*param_2 != L'\0' && (iVar1 = PathIsValidPath(param_1), iVar1 != 0)))) {
    HVar2 = StringCchCopyW(awStack_230,0x104,param_1);
    if (-1 < HVar2) {
      PathRemoveFileSpecW(awStack_230);
      pWVar3 = PathFindFileNameW(param_1);
      uVar4 = FUN_40576fc0(param_2,awStack_230,pWVar3,param_3,param_4,1,1);
      goto LAB_405774f0;
    }
    dwErrCode = 0xce;
  }
  SetLastError(dwErrCode);
LAB_405774f0:
  FUN_405a7174(local_28);
  return uVar4;
}



/* 4057755c FUN_4057755c */

/* Boundary evidence: original MIPS .pdata 4057755c..4057759f. Semantic name remains unreviewed. */

undefined4 * FUN_4057755c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_405711f8;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 405775a0 FUN_405775a0 */

/* Boundary evidence: original MIPS .pdata 405775a0..405775e3. Semantic name remains unreviewed. */

undefined4 * FUN_405775a0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_4057120c;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 405775ec FUN_405775ec */

/* Boundary evidence: original MIPS .pdata 405775ec..40577707. Semantic name remains unreviewed. */

wchar_t * FUN_405775ec(STRSAFE_PCNZWCH param_1,uint param_2)

{
  wchar_t wVar1;
  HRESULT HVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  uint uVar5;
  size_t local_18 [2];
  
  if ((param_1 != (STRSAFE_PCNZWCH)0x0) && (*param_1 != L'\0')) {
    local_18[0] = 0;
    HVar2 = StringCchLengthW(param_1,0x104,local_18);
    if (-1 < HVar2) {
      wVar1 = *param_1;
      pwVar3 = param_1;
      while (wVar1 != L'\\') {
        if (wVar1 == L'\0') {
          return (wchar_t *)0x0;
        }
        pwVar3 = pwVar3 + 1;
        wVar1 = *pwVar3;
      }
      if (pwVar3[1] == L'\\') {
        pwVar3 = pwVar3 + 2;
        wVar1 = *pwVar3;
        while (wVar1 != L'\\') {
          if (wVar1 == L'\0') {
            return (wchar_t *)0x0;
          }
          pwVar3 = pwVar3 + 1;
          wVar1 = *pwVar3;
        }
      }
      pwVar4 = param_1 + (local_18[0] - 1);
      uVar5 = 0;
      if (param_2 != 0) {
        do {
          if (*pwVar4 != L'\\') goto LAB_405776cc;
          do {
            if (pwVar4 <= pwVar3) {
              return pwVar3;
            }
            pwVar4 = pwVar4 + -1;
LAB_405776cc:
          } while (*pwVar4 != L'\\');
          uVar5 = uVar5 + 1;
        } while (uVar5 < param_2);
        return pwVar4;
      }
      return pwVar4;
    }
  }
  return (wchar_t *)0x0;
}



/* 40577708 FUN_40577708 */

/* Boundary evidence: original MIPS .pdata 40577708..40577817. Semantic name remains unreviewed. */

undefined4 FUN_40577708(STRSAFE_PCNZWCH param_1,STRSAFE_LPWSTR param_2,uint param_3)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  HRESULT HVar3;
  int iVar4;
  
  if (((param_1 != (STRSAFE_PCNZWCH)0x0) && (param_2 != (STRSAFE_LPWSTR)0x0)) && (param_3 != 0)) {
    pwVar1 = FUN_405775ec(param_1,2);
    pwVar2 = FUN_405775ec(param_1,1);
    if ((pwVar1 != (wchar_t *)0x0) && (pwVar2 != (wchar_t *)0x0)) {
      if (pwVar1 == pwVar2) {
        HVar3 = StringCchCopyW(param_2,param_3,param_1);
        if (-1 < HVar3) {
          param_2[((int)pwVar2 - (int)param_1 >> 1) + 1] = L'\0';
          return 1;
        }
      }
      else {
        iVar4 = (int)pwVar2 - (int)(pwVar1 + 1) >> 1;
        if (iVar4 + 1U <= param_3) {
          memcpy(param_2,pwVar1 + 1,iVar4 * 2);
          param_2[iVar4] = L'\0';
          return 1;
        }
      }
    }
  }
  return 0;
}



/* 40577818 FUN_40577818 */

/* Boundary evidence: original MIPS .pdata 40577818..40577927. Semantic name remains unreviewed. */

undefined4 FUN_40577818(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  wchar_t wVar2;
  STRSAFE_PCNZWCH pwVar3;
  wchar_t *pwVar4;
  size_t local_10 [2];
  
  if ((param_1 != (STRSAFE_PCNZWCH)0x0) && (*param_1 != L'\0')) {
    local_10[0] = 0;
    HVar1 = StringCchLengthW(param_1,0x104,local_10);
    if (-1 < HVar1) {
      wVar2 = *param_1;
      if (wVar2 == L'\\') {
        pwVar3 = param_1 + 1;
        if (*pwVar3 == L'\0') {
          return 1;
        }
        if (*pwVar3 == L'\\') {
          do {
            wVar2 = pwVar3[1];
            if (wVar2 == L'\\') {
              pwVar3 = pwVar3 + 2;
              while( true ) {
                if (*pwVar3 == L'\\') {
                  if (pwVar3[1] != L'\0') {
                    return 0;
                  }
                  return 1;
                }
                if (*pwVar3 == L'\0') break;
                pwVar3 = pwVar3 + 1;
              }
              return 1;
            }
            pwVar3 = pwVar3 + 1;
          } while (wVar2 != L'\0');
        }
      }
      else {
        do {
          pwVar4 = param_1;
          if (wVar2 == L'\0') {
            return 0;
          }
          param_1 = pwVar4 + 1;
          wVar2 = *param_1;
        } while (wVar2 != L'\\');
        if (pwVar4[2] == L'\0') {
          return 1;
        }
      }
    }
  }
  return 0;
}



/* 4057795c FUN_4057795c */

/* Boundary evidence: original MIPS .pdata 4057795c..405779e7. Semantic name remains unreviewed. */

void FUN_4057795c(int param_1)

{
  HANDLE pvVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE *)(param_1 + 0xc) = pvVar1;
    if (pvVar1 != (HANDLE)0x0) {
      PostMessageW(*(HWND *)(param_1 + 8),0x10,0,0);
      WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),0xffffffff);
    }
    CloseHandle(*(HANDLE *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}



/* 405779e8 FUN_405779e8 */

/* Boundary evidence: original MIPS .pdata 405779e8..40577a33. Semantic name remains unreviewed. */

void FUN_405779e8(int param_1,int param_2)

{
  HWND hWnd;
  
  if ((*(HWND *)(param_1 + 8) != (HWND)0x0) && (param_2 != 0)) {
    hWnd = GetDlgItem(*(HWND *)(param_1 + 8),0x2003);
    SendMessageW(hWnd,0xc,0,param_2);
  }
  return;
}



/* 40577a34 FUN_40577a34 */

/* Boundary evidence: original MIPS .pdata 40577a34..40577a7f. Semantic name remains unreviewed. */

void FUN_40577a34(int param_1,int param_2)

{
  HWND hWnd;
  
  if ((*(HWND *)(param_1 + 8) != (HWND)0x0) && (param_2 != 0)) {
    hWnd = GetDlgItem(*(HWND *)(param_1 + 8),0x2004);
    SendMessageW(hWnd,0xc,0,param_2);
  }
  return;
}



/* 40577a80 FUN_40577a80 */

/* Boundary evidence: original MIPS .pdata 40577a80..40577c87. Semantic name remains unreviewed. */

void FUN_40577a80(int param_1,uint param_2)

{
  longlong lVar1;
  DWORD DVar2;
  int iVar3;
  STRSAFE_LPCWSTR pwVar4;
  HWND pHVar5;
  wchar_t *lParam;
  uint uVar6;
  undefined8 uVar7;
  wchar_t local_120;
  undefined1 auStack_11e [254];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if (*(int *)(param_1 + 8) != 0) {
    if (*(int *)(param_1 + 0x14) == 0) {
      DVar2 = GetTickCount();
      *(DWORD *)(param_1 + 0x14) = DVar2;
    }
    if (1000 < param_2) {
      param_2 = 1000;
    }
    DVar2 = GetTickCount();
    uVar6 = *(uint *)(param_1 + 0x14);
    if (uVar6 < DVar2) {
      uVar6 = DVar2 - uVar6;
    }
    else {
      uVar6 = ~uVar6 + DVar2 + 1;
    }
    if ((uVar6 == 0) || (param_2 == 0)) {
      pHVar5 = GetDlgItem(*(HWND *)(param_1 + 8),0x2002);
      lParam = L"";
    }
    else {
      lVar1 = (ulonglong)(1000 - param_2) * (ulonglong)uVar6;
      uVar7 = __ull_div((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),param_2,0);
      iVar3 = __ull_div((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),60000,0);
      local_120 = L'\0';
      memset(auStack_11e,0,0xfe);
      if (iVar3 == 0) {
        pwVar4 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3003,(LPWSTR)0x0,0);
        if (pwVar4 != (STRSAFE_LPCWSTR)0x0) {
          StringCchCopyW(&local_120,0x80,pwVar4);
        }
      }
      else {
        pwVar4 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3007,(LPWSTR)0x0,0);
        if (pwVar4 != (STRSAFE_LPCWSTR)0x0) {
          StringCchPrintfW(&local_120,0x80,pwVar4,iVar3);
        }
      }
      pHVar5 = GetDlgItem(*(HWND *)(param_1 + 8),0x2002);
      lParam = &local_120;
    }
    SendMessageW(pHVar5,0xc,0,(LPARAM)lParam);
    pHVar5 = GetDlgItem(*(HWND *)(param_1 + 8),0x2001);
    SendMessageW(pHVar5,0x402,param_2 / 10,0);
    if (99 < param_2 / 10) {
      FUN_4057795c(param_1);
    }
  }
  FUN_405a7174(local_20);
  return;
}



/* 40577cc0 FUN_40577cc0 */

/* Boundary evidence: original MIPS .pdata 40577cc0..40577ef7. Semantic name remains unreviewed. */

undefined4 FUN_40577cc0(int param_1,wchar_t *param_2)

{
  int iVar1;
  LPWSTR pWVar2;
  STRSAFE_LPCWSTR pszFormat;
  HRESULT HVar3;
  LPCWSTR pWVar4;
  LPCWSTR lpText;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  wchar_t awStack_428 [260];
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  piVar7 = &DAT_405711c0;
  uVar5 = 0;
  iVar6 = 0;
  while ((iVar1 = SHGetSpecialFolderPath(**(undefined4 **)(param_1 + 8),awStack_428,*piVar7,0),
         iVar1 == 0 || (iVar1 = _wcsicmp(param_2,awStack_428), iVar1 != 0))) {
    iVar6 = iVar6 + 1;
    piVar7 = &DAT_405711c0 + iVar6;
    if (*piVar7 == 0) {
      piVar7 = &DAT_405711e0;
      iVar6 = 0;
      while ((iVar1 = SHGetSpecialFolderPath(**(undefined4 **)(param_1 + 8),awStack_428,*piVar7,0),
             iVar1 == 0 || (iVar1 = _wcsicmp(param_2,awStack_428), iVar1 != 0))) {
        iVar6 = iVar6 + 1;
        piVar7 = &DAT_405711e0 + iVar6;
        if (*piVar7 == 0) {
          FUN_405a7174(local_20);
          return 0;
        }
      }
      if ((*(ushort *)(param_1 + 4) & 0x10) == 0) {
        pWVar4 = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x3073,(LPWSTR)0x0,0);
        lpText = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x3070,(LPWSTR)0x0,0);
        iVar6 = MessageBoxW((HWND)0x0,lpText,pWVar4,0x10034);
        if (iVar6 == 7) {
          uVar5 = 1;
        }
      }
      FUN_405a7174(local_20);
      return uVar5;
    }
  }
  if ((*(ushort *)(param_1 + 4) & 0x400) == 0) {
    pWVar2 = PathFindFileNameW(param_2);
    pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0xc071,(LPWSTR)0x0,0);
    HVar3 = StringCchPrintfExW(awStack_220,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pszFormat
                               ,pWVar2);
    if (-1 < HVar3) {
      pWVar4 = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x3073,(LPWSTR)0x0,0);
      MessageBoxW((HWND)0x0,awStack_220,pWVar4,0x10010);
    }
  }
  FUN_405a7174(local_20);
  return 1;
}



/* 40577ef8 FUN_40577ef8 */

/* Boundary evidence: original MIPS .pdata 40577ef8..40577f7f. Semantic name remains unreviewed. */

void FUN_40577ef8(int param_1,uint param_2)

{
  HRESULT HVar1;
  wchar_t awStack_58 [38];
  uint local_c;
  
  local_c = DAT_405a9a3c;
  if (((((*(ushort *)(param_1 + 4) & 0x400) == 0) && ((int)param_2 < 0)) && (param_2 != 0x800704c7))
     && (HVar1 = StringCchPrintfW(awStack_58,0x26,L"An unknown error occured (0x%8.8x)",
                                  param_2 & 0xffff), -1 < HVar1)) {
    MessageBoxW((HWND)0x0,awStack_58,(LPCWSTR)0x0,0x10010);
  }
  FUN_405a7174(local_c);
  return;
}



/* 40577f80 FUN_40577f80 */

/* Boundary evidence: original MIPS .pdata 40577f80..40578117. Semantic name remains unreviewed. */

int FUN_40577f80(int *param_1,int param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_2 == 0) {
LAB_40577fa8:
    iVar3 = -0x7ff8fff3;
  }
  else {
    param_1[2] = param_2;
    bVar1 = *(byte *)(param_2 + 0x10);
    *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 0x10);
    if ((bVar1 & 0x40) != 0) {
      if ((*(int *)(param_2 + 4) == 3) && (iVar3 = FUN_4058862c(), iVar3 == 0)) goto LAB_40577fa8;
      if (DAT_405aa0d0 == (int *)0x0) {
        puVar2 = operator_new(0x48);
        if (puVar2 == (undefined4 *)0x0) {
          DAT_405aa0d0 = (int *)0x0;
        }
        else {
          DAT_405aa0d0 = FUN_40582bfc(puVar2);
        }
        if (DAT_405aa0d0 == (int *)0x0) {
          return -0x7ff8fff2;
        }
      }
      iVar3 = FUN_40583010(DAT_405aa0d0,*(int *)(param_1[2] + 4));
      if (iVar3 != 0) {
        *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0xffbf;
      }
    }
    iVar3 = (**(code **)*param_1)(param_1);
    if ((-1 < iVar3) && (iVar3 != 1)) {
      iVar3 = (**(code **)(*param_1 + 0xc))(param_1);
    }
    (**(code **)(*param_1 + 8))(param_1,iVar3);
    *(uint *)(param_2 + 0x12) = (uint)(iVar3 == -0x7ff8fb39);
    if ((*(ushort *)(param_1 + 1) & 0x40) != 0) {
      FUN_40582f20(DAT_405aa0d0);
    }
  }
  return iVar3;
}



/* 40578118 FUN_40578118 */

/* Boundary evidence: original MIPS .pdata 40578118..4057824b. Semantic name remains unreviewed. */

HRESULT FUN_40578118(int *param_1)

{
  BOOL BVar1;
  LPWSTR _Str;
  wchar_t *pwVar2;
  int iVar3;
  int *piVar4;
  HRESULT HVar5;
  STRSAFE_PCNZWCH psz;
  size_t local_18 [2];
  
  if ((param_1[2] == 0) || (piVar4 = (int *)(param_1[2] + 8), *piVar4 == 0)) {
    HVar5 = -0x7ff8fff3;
  }
  else {
    local_18[0] = 0;
    psz = (STRSAFE_PCNZWCH)*piVar4;
    HVar5 = 0;
    if (*psz != L'\0') {
      do {
        HVar5 = StringCchLengthW(psz,0x104,local_18);
        if (HVar5 < 0) goto LAB_4057820c;
        BVar1 = PathFileExistsW(psz);
        if (BVar1 == 0) {
          _Str = PathFindFileNameW(psz);
          pwVar2 = wcschr(_Str,L'*');
          if (pwVar2 == (wchar_t *)0x0) {
            HVar5 = -0x7ff8fffd;
            goto LAB_4057820c;
          }
        }
        iVar3 = FUN_40577818(psz);
        if (iVar3 != 0) {
          HVar5 = -0x7ff8ff5f;
          break;
        }
        psz = psz + local_18[0] + 1;
        param_1[0xb] = param_1[0xb] + 1;
      } while (*psz != L'\0');
      if (HVar5 < 0) {
LAB_4057820c:
        (**(code **)(*param_1 + 0x18))(param_1,psz);
      }
    }
  }
  return HVar5;
}



/* 4057824c FUN_4057824c */

/* Boundary evidence: original MIPS .pdata 4057824c..405782d3. Semantic name remains unreviewed. */

HRESULT FUN_4057824c(int param_1,STRSAFE_LPCWSTR param_2)

{
  HRESULT HVar1;
  void *pvVar2;
  
  if (param_2 == (STRSAFE_LPCWSTR)0x0) {
    if (*(void **)(param_1 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    HVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x10) == 0) {
      pvVar2 = operator_new(0x208);
      *(void **)(param_1 + 0x10) = pvVar2;
      if (pvVar2 == (void *)0x0) {
        return -0x7ff8fff2;
      }
    }
    HVar1 = StringCchCopyW(*(STRSAFE_LPWSTR *)(param_1 + 0x10),0x104,param_2);
  }
  return HVar1;
}



/* 405782d4 FUN_405782d4 */

/* Boundary evidence: original MIPS .pdata 405782d4..4057839b. Semantic name remains unreviewed. */

undefined4 FUN_405782d4(uint param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_stack_00000024;
  int in_stack_00000030;
  
  if (in_stack_00000024 == 1) {
    uVar1 = *(uint *)(in_stack_00000030 + 0x38);
    uVar2 = uVar1 + param_1;
    *(uint *)(in_stack_00000030 + 0x38) = uVar2;
    *(uint *)(in_stack_00000030 + 0x3c) =
         *(int *)(in_stack_00000030 + 0x3c) + param_2 + (uint)(uVar2 < uVar1);
  }
  uVar2 = *(uint *)(in_stack_00000030 + 0x38) - param_1;
  uVar1 = uVar2 + param_3;
  iVar3 = ((*(int *)(in_stack_00000030 + 0x3c) - param_2) -
          (uint)(*(uint *)(in_stack_00000030 + 0x38) < param_1)) + param_4 + (uint)(uVar1 < uVar2);
  if ((iVar3 != 0) || (uVar2 = 0, uVar1 != 0)) {
    uVar2 = __ull_div((int)((ulonglong)uVar1 * 1000),
                      iVar3 * 1000 + (int)((ulonglong)uVar1 * 1000 >> 0x20),
                      *(undefined4 *)(in_stack_00000030 + 0x30),
                      *(undefined4 *)(in_stack_00000030 + 0x34));
  }
  FUN_40577a80(in_stack_00000030 + 0x14,uVar2);
  return *(undefined4 *)(in_stack_00000030 + 0x24);
}



/* 4057839c FUN_4057839c */

/* Boundary evidence: original MIPS .pdata 4057839c..405787ff. Semantic name remains unreviewed. */

DWORD FUN_4057839c(int param_1,STRSAFE_PCNZWCH param_2,int param_3)

{
  DWORD DVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  LPCWSTR pWVar4;
  LPCWSTR lpCaption;
  int iVar5;
  DWORD DVar6;
  UINT cchMax;
  BOOL BVar7;
  uint uVar8;
  uint cchDest;
  size_t local_448;
  INT_PTR local_444;
  wchar_t awStack_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  local_448 = 0;
  if (param_2 == (STRSAFE_PCNZWCH)0x0) {
LAB_405783e8:
    FUN_405a7174(local_30);
    return 0x80070057;
  }
  DVar1 = StringCchLengthW(param_2,0x104,&local_448);
  if ((int)DVar1 < 0) goto LAB_4057841c;
  if (local_448 == 0) goto LAB_405783e8;
  if ((param_3 != 0) && ((*(ushort *)(param_1 + 4) & 0x200) == 0)) {
    pwVar2 = (wchar_t *)LoadStringW(DAT_405aa0c0,0x3005,(LPWSTR)0x0,0);
    if (pwVar2 == (wchar_t *)0x0) {
LAB_4057847c:
      FUN_405a7174(local_30);
      return 0x8007000e;
    }
    sVar3 = wcslen(pwVar2);
    cchDest = (sVar3 + local_448) - 1;
    uVar8 = cchDest * 2;
    if (0x7fffffff < cchDest) {
      uVar8 = 0xffffffff;
    }
    pWVar4 = operator_new(uVar8);
    if (pWVar4 == (LPCWSTR)0x0) goto LAB_4057847c;
    DVar1 = StringCchPrintfW(pWVar4,cchDest,pwVar2,param_2);
    if ((int)DVar1 < 0) {
      operator_delete(pWVar4);
      goto LAB_4057841c;
    }
    lpCaption = (LPCWSTR)LoadStringW(DAT_405aa0c0,0xc004,(LPWSTR)0x0,0);
    iVar5 = MessageBoxW((HWND)**(undefined4 **)(param_1 + 8),pWVar4,lpCaption,0x10034);
    operator_delete(pWVar4);
    if (iVar5 == 7) goto LAB_40578544;
  }
  if (*(int *)(param_1 + 0x24) != 1) {
    DVar1 = StringCchCopyW(awStack_440,0x104,param_2);
    if ((int)DVar1 < 0) goto LAB_4057841c;
    DVar6 = GetFileAttributesW(awStack_440);
    if (DVar6 != 0xffffffff) {
      if ((DVar6 & 0x10) == 0) {
        FUN_405a7174(local_30);
        return 0x80070050;
      }
      if ((*(ushort *)(param_1 + 4) & 8) == 0) {
        if ((*(ushort *)(param_1 + 4) & 0x10) == 0) {
          local_444 = 6;
          DVar1 = FUN_4058b380(awStack_440,(HWND)**(undefined4 **)(param_1 + 8),
                               (uint)(*(int *)(param_1 + 0x2c) == 1),&local_444);
          if ((int)DVar1 < 0) goto LAB_4057841c;
          if (local_444 == 2) goto LAB_40578544;
          if (local_444 == 7) {
            FUN_405a7174(local_30);
            return 1;
          }
          if (local_444 == 0x2203) {
            *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | 0x10;
          }
        }
        goto LAB_40578720;
      }
      pWVar4 = (LPCWSTR)LoadStringW(DAT_405aa0c0,0xc002,(LPWSTR)0x0,0);
      cchMax = LoadStringW(DAT_405aa0c0,0xc001,(LPWSTR)0x0,0);
      BVar7 = PathMakeUniqueName(awStack_440,cchMax,pWVar4,(LPCWSTR)0x0,aWStack_238);
      if (BVar7 == 0) {
LAB_40578624:
        DVar1 = GetLastError();
        if (0 < (int)DVar1) {
          DVar1 = DVar1 & 0xffff | 0x80070000;
        }
LAB_4057841c:
        FUN_405a7174(local_30);
        return DVar1;
      }
      DVar1 = StringCchCopyW(awStack_440,0x104,aWStack_238);
      DVar6 = 0xffffffff;
      if ((int)DVar1 < 0) goto LAB_4057841c;
    }
    if (*(int *)(param_1 + 0x24) != 1) {
      pwVar2 = (wchar_t *)0x0;
      while (DVar6 == 0xffffffff) {
        pwVar2 = FUN_405775ec(awStack_440,1);
        if (pwVar2 == (wchar_t *)0x0) {
          FUN_405a7174(local_30);
          return 0x800700a1;
        }
        *pwVar2 = L'\0';
        DVar6 = GetFileAttributesW(awStack_440);
      }
      if (pwVar2 < awStack_440 + local_448) {
        do {
          *pwVar2 = L'\\';
          BVar7 = CreateDirectoryW(awStack_440,(LPSECURITY_ATTRIBUTES)0x0);
          if (BVar7 == 0) goto LAB_40578624;
          sVar3 = wcslen(pwVar2);
          pwVar2 = pwVar2 + sVar3;
        } while (pwVar2 < awStack_440 + local_448);
      }
LAB_40578720:
      FUN_405a7174(local_30);
      return 0;
    }
  }
LAB_40578544:
  FUN_405a7174(local_30);
  return 0x800704c7;
}



/* 40578800 FUN_40578800 */

/* Boundary evidence: original MIPS .pdata 40578800..40578a8f. Semantic name remains unreviewed. */

DWORD FUN_40578800(int param_1,wchar_t *param_2,LPCWSTR param_3,size_t param_4)

{
  DWORD DVar1;
  LPWSTR pWVar2;
  int iVar3;
  LPCWSTR pszTemplate;
  UINT cchMax;
  BOOL BVar4;
  DWORD DVar5;
  INT_PTR local_238 [2];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  DVar5 = 0;
  DVar1 = GetFileAttributesW(param_3);
  pWVar2 = PathFindFileNameW(param_3);
  iVar3 = PathIsValidFileName(pWVar2);
  if (iVar3 == 0) {
    FUN_405a7174(local_28);
    return 0x8007007b;
  }
  if ((DVar1 != 0xffffffff) && ((DVar1 & 0x10) == 0)) {
    if ((*(ushort *)(param_1 + 4) & 8) == 0) {
      iVar3 = _wcsicmp(param_2,param_3);
      if (iVar3 == 0) {
        FUN_405a7174(local_28);
        return 0x800700b7;
      }
      if ((*(ushort *)(param_1 + 4) & 0x10) == 0) {
        local_238[0] = 6;
        FUN_4058bc04(param_2,param_3,(HWND)**(undefined4 **)(param_1 + 8),local_238);
        if (local_238[0] == 2) goto LAB_40578a7c;
        if (local_238[0] == 7) {
          FUN_405a7174(local_28);
          return 1;
        }
        if (local_238[0] == 0x2203) {
          *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | 0x10;
        }
      }
      SetFileAttributesW(param_3,DVar1 & 0xfffffffa);
      DeleteFileW(param_3);
    }
    else {
      pszTemplate = (LPCWSTR)LoadStringW(DAT_405aa0c0,0xc002,(LPWSTR)0x0,0);
      cchMax = LoadStringW(DAT_405aa0c0,0xc001,(LPWSTR)0x0,0);
      BVar4 = PathMakeUniqueName(param_3,cchMax,pszTemplate,(LPCWSTR)0x0,aWStack_230);
      if (BVar4 == 0) {
        DVar5 = GetLastError();
        if (0 < (int)DVar5) {
          DVar5 = DVar5 & 0xffff | 0x80070000;
        }
      }
      else {
        DVar5 = StringCchCopyW(param_3,param_4,aWStack_230);
      }
      if ((int)DVar5 < 0) goto LAB_40578960;
    }
  }
  if (*(int *)(param_1 + 0x24) == 1) {
LAB_40578a7c:
    FUN_405a7174(local_28);
    return 0x800704c7;
  }
LAB_40578960:
  FUN_405a7174(local_28);
  return DVar5;
}



/* 40578a90 FUN_40578a90 */

/* Boundary evidence: original MIPS .pdata 40578a90..40578bdb. Semantic name remains unreviewed. */

HRESULT FUN_40578a90(int *param_1)

{
  wchar_t wVar1;
  short sVar2;
  HRESULT HVar3;
  int iVar4;
  STRSAFE_PCNZWCH psz;
  size_t local_18 [2];
  
  HVar3 = FUN_40578118(param_1);
  if ((-1 < HVar3) && (HVar3 != 1)) {
    if (*(int *)(param_1[2] + 0xc) == 0) {
      HVar3 = -0x7ff8fff3;
    }
    else {
      local_18[0] = 0;
      psz = *(STRSAFE_PCNZWCH *)(param_1[2] + 8);
      wVar1 = *psz;
      while (wVar1 != L'\0') {
        HVar3 = StringCchLengthW(psz,0x104,local_18);
        if (HVar3 < 0) goto LAB_40578b9c;
        iVar4 = _wcsnicmp(psz,*(wchar_t **)(param_1[2] + 0xc),local_18[0]);
        if (iVar4 == 0) {
          sVar2 = *(short *)(*(int *)(param_1[2] + 0xc) + local_18[0] * 2);
          if (sVar2 == 0) {
            HVar3 = -0x7ff8ff49;
            goto LAB_40578b9c;
          }
          if (sVar2 == 0x5c) {
            HVar3 = -0x7ff8ffea;
            break;
          }
        }
        psz = psz + local_18[0] + 1;
        wVar1 = *psz;
      }
      if (HVar3 < 0) {
LAB_40578b9c:
        FUN_4057824c((int)param_1,psz);
      }
    }
  }
  return HVar3;
}



/* 40578bdc FUN_40578bdc */

/* Boundary evidence: original MIPS .pdata 40578bdc..4057900f. Semantic name remains unreviewed. */

DWORD FUN_40578bdc(int param_1,STRSAFE_LPCWSTR param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD DVar3;
  int iVar4;
  LPCWSTR pszTemplate;
  UINT cchMax;
  BOOL BVar5;
  STRSAFE_PCNZWCH lpFileName;
  wchar_t *pwVar6;
  uint uVar7;
  size_t sVar8;
  uint uVar9;
  size_t local_238 [2];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  DVar1 = FUN_4057824c(param_1,param_2);
  if (((int)DVar1 < 0) || (DVar1 == 1)) goto LAB_40578cc0;
  if ((*(int *)(param_1 + 0x10) == 0) || (*(int *)(*(int *)(param_1 + 8) + 0xc) == 0)) {
    FUN_405a7174(local_28);
    return 0x8007000d;
  }
  if (*(void **)(param_1 + 0x40) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  DVar2 = GetFileAttributesW(*(LPCWSTR *)(param_1 + 0x10));
  DVar3 = GetFileAttributesW(*(LPCWSTR *)(*(int *)(param_1 + 8) + 0xc));
  uVar9 = 0xffffffff;
  if (DVar2 == 0xffffffff) {
    if (DVar3 == 0xffffffff) {
      DVar1 = FUN_4057839c(param_1,*(STRSAFE_PCNZWCH *)(*(int *)(param_1 + 8) + 0xc),1);
    }
    else if ((DVar3 & 0x10) == 0) {
LAB_40578cb8:
      DVar1 = 0x80070050;
      goto LAB_40578cc0;
    }
    if (((int)DVar1 < 0) || (DVar1 == 1)) goto LAB_40578cc0;
LAB_40578fdc:
    pwVar6 = FUN_405775ec(*(STRSAFE_PCNZWCH *)(param_1 + 0x10),1);
    *(wchar_t **)(param_1 + 0x44) = pwVar6;
    if (pwVar6 != (wchar_t *)0x0) goto LAB_40578cc0;
  }
  else {
    if ((DVar2 & 0x10) == 0) {
      if (DVar3 == 0xffffffff) {
        pwVar6 = FUN_405775ec(*(STRSAFE_PCNZWCH *)(*(int *)(param_1 + 8) + 0xc),1);
        iVar4 = (int)pwVar6 - *(int *)(*(int *)(param_1 + 8) + 0xc) >> 1;
        uVar7 = (iVar4 + 1U) * 2;
        if (0x7fffffff < iVar4 + 1U) {
          uVar7 = uVar9;
        }
        lpFileName = operator_new(uVar7);
        if (lpFileName == (STRSAFE_PCNZWCH)0x0) {
LAB_40578ed0:
          FUN_405a7174(local_28);
          return 0x8007000e;
        }
        memcpy(lpFileName,*(void **)(*(int *)(param_1 + 8) + 0xc),iVar4 * 2);
        lpFileName[iVar4] = L'\0';
        DVar2 = GetFileAttributesW(lpFileName);
        if (DVar2 == 0xffffffff) {
          DVar1 = FUN_4057839c(param_1,lpFileName,1);
        }
        operator_delete(lpFileName);
        goto LAB_40578cc0;
      }
      if ((DVar3 & 0x10) == 0) goto LAB_40578cc0;
      goto LAB_40578fdc;
    }
    if (DVar3 != 0xffffffff) {
      if ((DVar3 & 0x10) == 0) goto LAB_40578cb8;
      pwVar6 = FUN_405775ec(*(STRSAFE_PCNZWCH *)(param_1 + 0x10),1);
      *(wchar_t **)(param_1 + 0x44) = pwVar6;
      if (pwVar6 == (wchar_t *)0x0) {
        DVar1 = 0x800700a1;
      }
      sVar8 = (int)pwVar6 - (int)*(wchar_t **)(param_1 + 0x10) >> 1;
      if (sVar8 == 0) {
        sVar8 = 1;
      }
      pwVar6 = *(wchar_t **)(*(int *)(param_1 + 8) + 0xc);
      if ((pwVar6[sVar8] != L'\0') ||
         (iVar4 = _wcsnicmp(*(wchar_t **)(param_1 + 0x10),pwVar6,sVar8), iVar4 != 0))
      goto LAB_40578cc0;
      if ((*(ushort *)(param_1 + 4) & 8) == 0) {
        FUN_405a7174(local_28);
        return 0x800700b7;
      }
      pszTemplate = (LPCWSTR)LoadStringW(DAT_405aa0c0,0xc002,(LPWSTR)0x0,0);
      cchMax = LoadStringW(DAT_405aa0c0,0xc001,(LPWSTR)0x0,0);
      BVar5 = PathMakeUniqueName(*(LPWSTR *)(param_1 + 0x10),cchMax,pszTemplate,(LPCWSTR)0x0,
                                 aWStack_230);
      if (BVar5 != 0) {
        sVar8 = wcslen(aWStack_230);
        if (sVar8 + 1 < 0x80000000) {
          uVar9 = (sVar8 + 1) * 2;
        }
        pwVar6 = operator_new(uVar9);
        *(wchar_t **)(param_1 + 0x40) = pwVar6;
        if (pwVar6 == (wchar_t *)0x0) goto LAB_40578ed0;
        wcscpy(pwVar6,aWStack_230);
        goto LAB_40578d5c;
      }
LAB_40578d7c:
      DVar1 = GetLastError();
      if (0 < (int)DVar1) {
        DVar1 = DVar1 & 0xffff | 0x80070000;
      }
      goto LAB_40578cc0;
    }
    pwVar6 = FUN_405775ec(*(STRSAFE_PCNZWCH *)(*(int *)(param_1 + 8) + 0xc),2);
    if (pwVar6 != (wchar_t *)0x0) {
LAB_40578d5c:
      local_238[0] = 0;
      DVar1 = StringCchLengthW(*(STRSAFE_PCNZWCH *)(param_1 + 0x10),0x104,local_238);
      if (-1 < (int)DVar1) {
        *(size_t *)(param_1 + 0x44) = local_238[0] * 2 + *(int *)(param_1 + 0x10);
        goto LAB_40578cc0;
      }
      goto LAB_40578d7c;
    }
  }
  DVar1 = 0x800700a1;
LAB_40578cc0:
  FUN_405a7174(local_28);
  return DVar1;
}



/* 40579010 FUN_40579010 */

/* Boundary evidence: original MIPS .pdata 40579010..40579197. Semantic name remains unreviewed. */

HRESULT FUN_40579010(int param_1,STRSAFE_LPWSTR param_2,size_t param_3,int param_4)

{
  HRESULT HVar1;
  int *piVar2;
  STRSAFE_PCNZWCH psz;
  STRSAFE_LPCWSTR pwVar3;
  STRSAFE_LPWSTR local_20;
  size_t local_1c;
  
  if ((param_2 == (STRSAFE_LPWSTR)0x0) || (param_4 == 0)) {
    HVar1 = -0x7ff8ffa9;
  }
  else if (((param_3 == 0) || (piVar2 = (int *)(*(int *)(param_1 + 8) + 0xc), *piVar2 == 0)) ||
          (psz = *(STRSAFE_PCNZWCH *)(param_1 + 0x10), psz == (STRSAFE_PCNZWCH)0x0)) {
    HVar1 = -0x7ff8fff3;
  }
  else {
    pwVar3 = *(STRSAFE_LPCWSTR *)(param_1 + 0x40);
    local_20 = (STRSAFE_LPWSTR)0x0;
    local_1c = 0;
    if (pwVar3 == (STRSAFE_LPCWSTR)0x0) {
      pwVar3 = (STRSAFE_LPCWSTR)*piVar2;
    }
    if (*(int *)(param_1 + 0x44) == 0) {
      HVar1 = StringCchLengthW(psz,param_3,&local_1c);
      if (HVar1 < 0) {
        return HVar1;
      }
    }
    else {
      local_1c = *(int *)(param_1 + 0x44) - (int)psz >> 1;
    }
    HVar1 = StringCchCopyExW(param_2,param_3,pwVar3,&local_20,(size_t *)0x0,0);
    if ((-1 < HVar1) &&
       ((local_20[-1] == L'\\' || (HVar1 = StringCchCatW(param_2,param_3,L"\\"), -1 < HVar1)))) {
      pwVar3 = (STRSAFE_LPCWSTR)(local_1c * 2 + param_4);
      if (*pwVar3 == L'\\') {
        HVar1 = StringCchCatExW(param_2,param_3,pwVar3 + 1,&local_20,(size_t *)0x0,0);
      }
      else {
        HVar1 = StringCchCatExW(param_2,param_3,pwVar3,&local_20,(size_t *)0x0,0);
      }
      if (local_20[-1] == L'\\') {
        local_20[-1] = L'\0';
      }
    }
  }
  return HVar1;
}



/* 40579198 FUN_40579198 */

/* Boundary evidence: original MIPS .pdata 40579198..405792ef. Semantic name remains unreviewed. */

DWORD FUN_40579198(int param_1,int param_2,wchar_t *param_3)

{
  int iVar1;
  DWORD DVar2;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  DVar2 = 0;
  if (param_3 == (wchar_t *)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    DVar2 = 0x80070057;
  }
  else if (*(int *)(param_1 + -4) == 0) {
    FUN_405a7174(DAT_405a9a3c);
    DVar2 = 0x8007000d;
  }
  else {
    iVar1 = _wcsicmp(param_3,*(wchar_t **)(*(int *)(param_1 + -4) + 0xc));
    if (iVar1 == 0) {
      FUN_405a7174(local_20);
      DVar2 = 1;
    }
    else {
      if (param_2 == 0) {
        DVar2 = FUN_40579010(param_1 + -0xc,awStack_228,0x104,(int)param_3);
        if (-1 < (int)DVar2) {
          if (DVar2 != 1) {
            DVar2 = FUN_4057839c(param_1 + -0xc,awStack_228,0);
          }
          if (((-1 < (int)DVar2) && (DVar2 != 1)) && ((*(ushort *)(param_1 + -8) & 0x40) != 0)) {
            FUN_40582c5c(DAT_405aa0d0,param_3,awStack_228);
          }
        }
      }
      if (*(int *)(param_1 + 0x18) == 1) {
        DVar2 = 0x800704c7;
      }
      FUN_405a7174(local_20);
    }
  }
  return DVar2;
}



/* 405792f0 FUN_405792f0 */

/* Boundary evidence: original MIPS .pdata 405792f0..405795ff. Semantic name remains unreviewed. */

DWORD FUN_405792f0(int param_1,STRSAFE_PCNZWCH param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  STRSAFE_LPCWSTR pszFormat;
  BOOL BVar3;
  LPWSTR _Str1;
  DWORD DVar4;
  LPVOID lpData;
  BOOL local_848 [2];
  wchar_t awStack_840 [260];
  wchar_t local_638;
  undefined1 auStack_636 [518];
  wchar_t local_430;
  undefined1 auStack_42e [518];
  wchar_t local_228;
  undefined1 auStack_226 [518];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if (param_2 == (STRSAFE_PCNZWCH)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    DVar4 = 0x80070057;
  }
  else if (*(int *)(param_1 + -4) == 0) {
    FUN_405a7174(DAT_405a9a3c);
    DVar4 = 0x8007000d;
  }
  else {
    DVar4 = GetFileAttributesW(param_2);
    if (DVar4 == 0xffffffff) {
      FUN_405a7174(local_20);
      DVar4 = 0x80070002;
    }
    else {
      lpData = (LPVOID)(param_1 + -0xc);
      DVar4 = FUN_40579010((int)lpData,awStack_840,0x104,(int)param_2);
      if ((((-1 < (int)DVar4) && (DVar4 != 1)) &&
          (DVar4 = FUN_40578800((int)lpData,param_2,awStack_840,0x104), -1 < (int)DVar4)) &&
         (DVar4 != 1)) {
        if (((*(ushort *)(param_1 + -8) & 4) == 0) && ((*(ushort *)(param_1 + -8) & 0x100) == 0)) {
          pwVar1 = FUN_405775ec(awStack_840,1);
          if (pwVar1 != (wchar_t *)0x0) {
            FUN_405779e8(param_1 + 8,(int)(pwVar1 + 1));
          }
          local_430 = L'\0';
          memset(auStack_42e,0,0x206);
          local_638 = L'\0';
          memset(auStack_636,0,0x206);
          local_228 = L'\0';
          memset(auStack_226,0,0x206);
          iVar2 = FUN_40577708(param_2,&local_430,0x104);
          if ((iVar2 != 0) && (iVar2 = FUN_40577708(awStack_840,&local_638,0x104), iVar2 != 0)) {
            pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3062,(LPWSTR)0x0,0);
            StringCchPrintfExW(&local_228,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,pszFormat,
                               &local_430,&local_638);
          }
          FUN_40577a34(param_1 + 8,(int)&local_228);
        }
        local_848[0] = 0;
        BVar3 = CopyFileExW(param_2,awStack_840,FUN_405782d4,lpData,local_848,0);
        if ((BVar3 == 0) && (DVar4 = GetLastError(), 0 < (int)DVar4)) {
          DVar4 = DVar4 & 0xffff | 0x80070000;
        }
        _Str1 = PathFindFileNameW(awStack_840);
        iVar2 = _wcsicmp(_Str1,L"desktop.ini");
        if (iVar2 == 0) {
          FUN_4058dc14(L"[.ShellClassInfo]",L"LocalizedResourceName",(STRSAFE_PCNZWCH)0x0,0,
                       awStack_840);
        }
        if (*(int *)(param_1 + 0x18) == 1) {
          DVar4 = 0x800704c7;
        }
        if (((-1 < (int)DVar4) && (DVar4 != 1)) && ((*(ushort *)(param_1 + -8) & 0x40) != 0)) {
          FUN_40582c5c(DAT_405aa0d0,param_2,awStack_840);
        }
      }
      FUN_405a7174(local_20);
    }
  }
  return DVar4;
}



/* 40579600 FUN_40579600 */

/* Boundary evidence: original MIPS .pdata 40579600..4057996f. Semantic name remains unreviewed. */

void FUN_40579600(int *param_1,uint param_2)

{
  int iVar1;
  DWORD DVar2;
  STRSAFE_LPCWSTR pwVar3;
  HRESULT HVar4;
  UINT uID;
  LPCWSTR pWVar5;
  int iVar6;
  uint uVar7;
  HWND pHVar8;
  wchar_t local_528;
  undefined1 auStack_526 [510];
  WCHAR local_328;
  undefined1 auStack_326 [254];
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((((*(ushort *)(param_1 + 1) & 0x400) != 0) || (-1 < (int)param_2)) || (param_2 == 0x800704c7))
  goto LAB_40579940;
  pHVar8 = (HWND)0x0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    pHVar8 = *(HWND *)param_1[2];
  }
  pWVar5 = (LPCWSTR)param_1[4];
  if ((LPCWSTR)param_1[4] == (LPCWSTR)0x0) {
    pWVar5 = L"";
  }
  iVar1 = LoadStringW(DAT_405aa0c0,0xc05b,(LPWSTR)0x0,0);
  local_528 = L'\0';
  memset(auStack_526,0,0x1fe);
  if ((iVar1 != 0) && (pWVar5 != (LPCWSTR)0x0)) {
    if ((int)param_2 < -0x7ff8ff8f) {
      if (param_2 == 0x80070070) {
        uID = 0xc013;
      }
      else {
        uVar7 = param_2 + 0x7ff8fffe;
        if ((param_2 == 0x80070002) || (uVar7 < 2)) {
          DVar2 = GetFileAttributesW(pWVar5);
          if ((DVar2 == 0xffffffff) || ((DVar2 & 0x2000) == 0)) {
LAB_405797a8:
            uID = 0xc012;
          }
          else {
            uID = (**(code **)(*param_1 + 4))(param_1);
          }
        }
        else if (uVar7 == 3) {
          uID = 0xc00f;
        }
        else if (uVar7 == 0xc) {
          uID = 0xc00d;
        }
        else if (uVar7 == 0x14) {
          uID = 0xc011;
        }
        else {
          if (uVar7 != 0x1e) {
            iVar6 = param_2 + 0x7ff8ffb0;
            goto LAB_405797f4;
          }
          uID = 0xc015;
        }
      }
LAB_405798a0:
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
      iVar6 = StringCchCopyW(&local_528,0x100,pwVar3);
    }
    else {
      if (param_2 == 0x8007007a) {
LAB_4057989c:
        uID = 0xc014;
        goto LAB_405798a0;
      }
      if (param_2 == 0x8007007b) {
        uID = 0xc044;
        goto LAB_405798a0;
      }
      if (param_2 == 0x800700a1) goto LAB_405797a8;
      if (param_2 == 0x800700b7) {
        uID = 0xc075;
        goto LAB_405798a0;
      }
      iVar6 = param_2 + 0x7ff8ff32;
LAB_405797f4:
      if (iVar6 == 0) goto LAB_4057989c;
      local_328 = L'\0';
      memset(auStack_326,0,0xfe);
      FormatMessageW(0x1200,(LPCVOID)0x0,param_2 & 0xffff,0,&local_328,0x80,(va_list *)0x0);
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0xc000,(LPWSTR)0x0,0);
      iVar6 = StringCchPrintfExW(&local_528,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar3,
                                 param_2 & 0xffff,&local_328);
    }
    if (-1 < iVar6) {
      HVar4 = StringCchPrintfExW(awStack_228,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,L"%s%s"
                                 ,iVar1,&local_528);
      if (-1 < HVar4) {
        pWVar5 = (LPCWSTR)param_1[4];
        if ((LPCWSTR)param_1[4] == (LPCWSTR)0x0) {
          pWVar5 = L"";
        }
        FUN_4058a544(pHVar8,(LPCWSTR)0x3006,awStack_228,pWVar5,0x10);
        goto LAB_40579940;
      }
    }
  }
  FUN_40577ef8((int)param_1,param_2);
LAB_40579940:
  FUN_405a7174(local_28);
  return;
}



/* 40579970 FUN_40579970 */

/* Boundary evidence: original MIPS .pdata 40579970..405799eb. Semantic name remains unreviewed. */

DWORD FUN_40579970(int param_1,wchar_t *param_2)

{
  DWORD DVar1;
  
  DVar1 = FUN_40577cc0(param_1,param_2);
  if (((int)DVar1 < 0) || (DVar1 == 1)) {
    FUN_4057824c(param_1,param_2);
  }
  else {
    DVar1 = FUN_40578bdc(param_1,param_2);
  }
  return DVar1;
}



/* 405799ec FUN_405799ec */

/* Boundary evidence: original MIPS .pdata 405799ec..40579b8b. Semantic name remains unreviewed. */

DWORD FUN_405799ec(int param_1,int param_2,wchar_t *param_3)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  DVar3 = 0;
  if (param_3 == (wchar_t *)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    DVar3 = 0x80070057;
  }
  else if (*(int *)(param_1 + -4) == 0) {
    FUN_405a7174(DAT_405a9a3c);
    DVar3 = 0x8007000d;
  }
  else {
    iVar1 = _wcsicmp(param_3,*(wchar_t **)(*(int *)(param_1 + -4) + 0xc));
    if (iVar1 == 0) {
      FUN_405a7174(local_20);
      DVar3 = 1;
    }
    else {
      if (param_2 == 0) {
        DVar3 = FUN_40579010(param_1 + -0xc,awStack_228,0x104,(int)param_3);
        if (-1 < (int)DVar3) {
          if (DVar3 != 1) {
            DVar3 = FUN_4057839c(param_1 + -0xc,awStack_228,0);
          }
          if (((-1 < (int)DVar3) && (DVar3 != 1)) && ((*(ushort *)(param_1 + -8) & 0x40) != 0)) {
            FUN_40582c5c(DAT_405aa0d0,param_3,awStack_228);
          }
        }
      }
      else {
        BVar2 = RemoveDirectoryW(param_3);
        if ((BVar2 == 0) && (DVar3 = GetLastError(), 0 < (int)DVar3)) {
          DVar3 = DVar3 & 0xffff | 0x80070000;
        }
      }
      if (*(int *)(param_1 + 0x18) == 1) {
        DVar3 = 0x800704c7;
      }
      FUN_405a7174(local_20);
    }
  }
  return DVar3;
}



/* 40579b8c FUN_40579b8c */

/* Boundary evidence: original MIPS .pdata 40579b8c..4057a0d3. Semantic name remains unreviewed. */

DWORD FUN_40579b8c(int param_1,LPCWSTR param_2)

{
  longlong lVar1;
  DWORD DVar2;
  DWORD DVar3;
  wchar_t *pwVar4;
  int iVar5;
  STRSAFE_LPCWSTR pszFormat;
  BOOL BVar6;
  HANDLE hFile;
  uint uVar7;
  LPVOID lpData;
  DWORD local_850;
  DWORD local_84c;
  wchar_t awStack_848 [260];
  wchar_t local_640;
  undefined1 auStack_63e [518];
  wchar_t local_438;
  undefined1 auStack_436 [518];
  wchar_t local_230;
  undefined1 auStack_22e [518];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  DVar2 = GetFileAttributesW(param_2);
  if (param_2 == (LPCWSTR)0x0) {
    FUN_405a7174(local_28);
    return 0x80070057;
  }
  if (*(int *)(param_1 + -4) == 0) {
    FUN_405a7174(local_28);
    return 0x8007000d;
  }
  if (DVar2 == 0xffffffff) {
    FUN_405a7174(local_28);
    return 0x80070002;
  }
  lpData = (LPVOID)(param_1 + -0xc);
  DVar3 = FUN_40579010((int)lpData,awStack_848,0x104,(int)param_2);
  if ((-1 < (int)DVar3) && (DVar3 != 1)) {
    if ((*(ushort *)(param_1 + -8) & 0x10) == 0) {
      local_850 = 6;
      DVar3 = FUN_4058a6d8(param_2,(HWND)**(undefined4 **)(param_1 + -4),
                           (uint)(*(int *)(param_1 + 0x20) == 1),(INT_PTR *)&local_850);
      if ((int)DVar3 < 0) goto LAB_4057a0a0;
      if (local_850 == 2) goto LAB_40579f94;
      if (local_850 == 7) {
        FUN_405a7174(local_28);
        return 1;
      }
      if (local_850 == 0x2203) {
        *(ushort *)(param_1 + -8) = *(ushort *)(param_1 + -8) | 0x10;
      }
    }
    if (*(int *)(param_1 + 0x18) == 1) {
LAB_40579f94:
      FUN_405a7174(local_28);
      return 0x800704c7;
    }
    DVar3 = FUN_40578800((int)lpData,param_2,awStack_848,0x104);
    if ((-1 < (int)DVar3) && (DVar3 != 1)) {
      if (((*(ushort *)(param_1 + -8) & 4) == 0) && ((*(ushort *)(param_1 + -8) & 0x100) == 0)) {
        pwVar4 = FUN_405775ec(awStack_848,1);
        if (pwVar4 != (wchar_t *)0x0) {
          FUN_405779e8(param_1 + 8,(int)(pwVar4 + 1));
        }
        local_438 = L'\0';
        memset(auStack_436,0,0x206);
        local_640 = L'\0';
        memset(auStack_63e,0,0x206);
        local_230 = L'\0';
        memset(auStack_22e,0,0x206);
        iVar5 = FUN_40577708(param_2,&local_438,0x104);
        if ((iVar5 != 0) && (iVar5 = FUN_40577708(awStack_848,&local_640,0x104), iVar5 != 0)) {
          pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3062,(LPWSTR)0x0,0);
          StringCchPrintfExW(&local_230,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,pszFormat,
                             &local_438,&local_640);
        }
        FUN_40577a34(param_1 + 8,(int)&local_230);
      }
      iVar5 = PathIsSameDevice(param_2,awStack_848);
      if (iVar5 == 0) {
        local_850 = 0;
        BVar6 = CopyFileExW(param_2,awStack_848,FUN_405782d4,lpData,(LPBOOL)&local_850,0);
        if ((BVar6 == 0) && (DVar3 = GetLastError(), 0 < (int)DVar3)) {
          DVar3 = DVar3 & 0xffff | 0x80070000;
        }
        if (*(int *)(param_1 + 0x18) == 1) {
          DVar3 = 0x800704c7;
        }
        if ((int)DVar3 < 0) goto LAB_4057a0a0;
        SetFileAttributesW(param_2,DVar2 & 0xfffffffa);
        BVar6 = DeleteFileW(param_2);
        if ((BVar6 == 0) && (DVar3 = GetLastError(), 0 < (int)DVar3)) {
          DVar3 = DVar3 & 0xffff | 0x80070000;
        }
      }
      else {
        BVar6 = MoveFileW(param_2,awStack_848);
        if ((BVar6 == 0) && (DVar3 = GetLastError(), 0 < (int)DVar3)) {
          DVar3 = DVar3 & 0xffff | 0x80070000;
        }
        if (*(int *)(param_1 + 0x18) == 1) {
          DVar3 = 0x800704c7;
        }
        if ((int)DVar3 < 0) goto LAB_4057a0a0;
        hFile = CreateFileW(awStack_848,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
        if (hFile != (HANDLE)0xffffffff) {
          local_850 = 0;
          memset(&local_84c,0,4);
          local_850 = GetFileSize(hFile,&local_84c);
          if (local_850 != 0xffffffff) {
            uVar7 = local_850 + *(int *)(param_1 + 0x2c);
            *(uint *)(param_1 + 0x2c) = uVar7;
            *(DWORD *)(param_1 + 0x30) =
                 local_84c + *(int *)(param_1 + 0x30) + (uint)(uVar7 < local_850);
            if ((*(int *)(param_1 + 0x28) != 0) || (*(int *)(param_1 + 0x24) != 0)) {
              lVar1 = (ulonglong)*(uint *)(param_1 + 0x2c) * 1000;
              uVar7 = __ull_div((int)lVar1,
                                *(int *)(param_1 + 0x30) * 1000 + (int)((ulonglong)lVar1 >> 0x20));
              FUN_40577a80(param_1 + 8,uVar7);
            }
          }
          CloseHandle(hFile);
        }
      }
      if (((-1 < (int)DVar3) && (DVar3 != 1)) && ((*(ushort *)(param_1 + -8) & 0x40) != 0)) {
        FUN_40582c5c(DAT_405aa0d0,param_2,awStack_848);
      }
    }
  }
LAB_4057a0a0:
  FUN_405a7174(local_28);
  return DVar3;
}



/* 4057a0d4 FUN_4057a0d4 */

/* Boundary evidence: original MIPS .pdata 4057a0d4..4057a443. Semantic name remains unreviewed. */

void FUN_4057a0d4(int *param_1,uint param_2)

{
  int iVar1;
  DWORD DVar2;
  STRSAFE_LPCWSTR pwVar3;
  HRESULT HVar4;
  UINT uID;
  LPCWSTR pWVar5;
  int iVar6;
  uint uVar7;
  HWND pHVar8;
  wchar_t local_528;
  undefined1 auStack_526 [510];
  WCHAR local_328;
  undefined1 auStack_326 [254];
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((((*(ushort *)(param_1 + 1) & 0x400) != 0) || (-1 < (int)param_2)) || (param_2 == 0x800704c7))
  goto LAB_4057a414;
  pHVar8 = (HWND)0x0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    pHVar8 = *(HWND *)param_1[2];
  }
  pWVar5 = (LPCWSTR)param_1[4];
  if ((LPCWSTR)param_1[4] == (LPCWSTR)0x0) {
    pWVar5 = L"";
  }
  iVar1 = LoadStringW(DAT_405aa0c0,0xc05e,(LPWSTR)0x0,0);
  local_528 = L'\0';
  memset(auStack_526,0,0x1fe);
  if ((iVar1 != 0) && (pWVar5 != (LPCWSTR)0x0)) {
    if ((int)param_2 < -0x7ff8ff8f) {
      if (param_2 == 0x80070070) {
        uID = 0xc013;
      }
      else {
        uVar7 = param_2 + 0x7ff8fffe;
        if ((param_2 == 0x80070002) || (uVar7 < 2)) {
          DVar2 = GetFileAttributesW(pWVar5);
          if ((DVar2 == 0xffffffff) || ((DVar2 & 0x2000) == 0)) {
LAB_4057a27c:
            uID = 0xc012;
          }
          else {
            uID = (**(code **)(*param_1 + 4))(param_1);
          }
        }
        else if (uVar7 == 3) {
          uID = 0xc00f;
        }
        else if (uVar7 == 0xc) {
          uID = 0xc00d;
        }
        else if (uVar7 == 0x14) {
          uID = 0xc011;
        }
        else {
          if (uVar7 != 0x1e) {
            iVar6 = param_2 + 0x7ff8ffb0;
            goto LAB_4057a2c8;
          }
          uID = 0xc015;
        }
      }
LAB_4057a374:
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
      iVar6 = StringCchCopyW(&local_528,0x100,pwVar3);
    }
    else {
      if (param_2 == 0x8007007a) {
LAB_4057a370:
        uID = 0xc014;
        goto LAB_4057a374;
      }
      if (param_2 == 0x8007007b) {
        uID = 0xc044;
        goto LAB_4057a374;
      }
      if (param_2 == 0x800700a1) goto LAB_4057a27c;
      if (param_2 == 0x800700b7) {
        uID = 0xc075;
        goto LAB_4057a374;
      }
      iVar6 = param_2 + 0x7ff8ff32;
LAB_4057a2c8:
      if (iVar6 == 0) goto LAB_4057a370;
      local_328 = L'\0';
      memset(auStack_326,0,0xfe);
      FormatMessageW(0x1200,(LPCVOID)0x0,param_2 & 0xffff,0,&local_328,0x80,(va_list *)0x0);
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0xc000,(LPWSTR)0x0,0);
      iVar6 = StringCchPrintfExW(&local_528,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar3,
                                 param_2 & 0xffff,&local_328);
    }
    if (-1 < iVar6) {
      HVar4 = StringCchPrintfExW(awStack_228,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,L"%s%s"
                                 ,iVar1,&local_528);
      if (-1 < HVar4) {
        pWVar5 = (LPCWSTR)param_1[4];
        if ((LPCWSTR)param_1[4] == (LPCWSTR)0x0) {
          pWVar5 = L"";
        }
        FUN_4058a544(pHVar8,(LPCWSTR)0x301a,awStack_228,pWVar5,0x10);
        goto LAB_4057a414;
      }
    }
  }
  FUN_40577ef8((int)param_1,param_2);
LAB_4057a414:
  FUN_405a7174(local_28);
  return;
}



/* 4057a444 FUN_4057a444 */

/* Boundary evidence: original MIPS .pdata 4057a444..4057a6c7. Semantic name remains unreviewed. */

HRESULT FUN_4057a444(int *param_1)

{
  bool bVar1;
  bool bVar2;
  HRESULT HVar3;
  int iVar4;
  DWORD DVar5;
  STRSAFE_PCNZWCH psz;
  uint uVar6;
  size_t local_30;
  INT_PTR local_2c;
  
  HVar3 = FUN_40578118(param_1);
  uVar6 = 0;
  bVar2 = true;
  if ((*(ushort *)(param_1 + 1) & 0x40) != 0) {
    bVar1 = DAT_405aa0d4 == 0;
    param_1[0x10] = DAT_405aa0d4;
    if (bVar1) {
      return -0x7ff8fff2;
    }
    FUN_40586a28(DAT_405aa0d4,0);
  }
  if (HVar3 < 0) {
    return HVar3;
  }
  if (HVar3 == 1) {
    return 1;
  }
  local_30 = 0;
  psz = *(STRSAFE_PCNZWCH *)(param_1[2] + 8);
  if (*psz == L'\0') {
LAB_4057a5bc:
    DVar5 = GetFileAttributesW(*(LPCWSTR *)(param_1[2] + 8));
    if ((DVar5 == 0xffffffff) || ((DVar5 & 0x10) == 0)) {
      param_1[0x11] = 1;
      goto LAB_4057a688;
    }
    if ((*(ushort *)(param_1 + 1) & 0x10) == 0) {
      local_2c = 6;
      HVar3 = FUN_4058abc0((LPCWSTR)((undefined4 *)param_1[2])[2],*(HWND *)param_1[2],1,(uint)!bVar2
                           ,1,&local_2c);
      goto LAB_4057a648;
    }
  }
  else {
    do {
      iVar4 = PathIsSameDevice(psz,&DAT_405a9aa4);
      if (iVar4 == 0) {
        bVar2 = false;
      }
      HVar3 = StringCchLengthW(psz,0x104,&local_30);
      if (HVar3 < 0) {
        FUN_4057824c((int)param_1,psz);
        return HVar3;
      }
      psz = psz + local_30 + 1;
      uVar6 = uVar6 + 1;
    } while (*psz != L'\0');
    if (uVar6 < 2) goto LAB_4057a5bc;
    if ((*(ushort *)(param_1 + 1) & 0x10) == 0) {
      local_2c = 6;
      iVar4 = 0;
      if ((param_1[0x10] == 0) || (!bVar2)) {
        iVar4 = 1;
      }
      HVar3 = FUN_4058af5c(uVar6,*(HWND *)param_1[2],iVar4,&local_2c);
LAB_4057a648:
      if (-1 < HVar3) {
        if (local_2c == 2) {
          HVar3 = -0x7ff8fb39;
        }
        else if (local_2c == 7) {
          HVar3 = 1;
        }
      }
    }
  }
  param_1[0x11] = 0;
LAB_4057a688:
  if (param_1[9] == 1) {
    HVar3 = -0x7ff8fb39;
  }
  return HVar3;
}



/* 4057a6c8 FUN_4057a6c8 */

/* Boundary evidence: original MIPS .pdata 4057a6c8..4057a743. Semantic name remains unreviewed. */

int FUN_4057a6c8(int param_1,wchar_t *param_2)

{
  HRESULT HVar1;
  
  HVar1 = FUN_40577cc0(param_1,param_2);
  if ((HVar1 < 0) || (HVar1 == 1)) {
    FUN_4057824c(param_1,param_2);
  }
  else {
    HVar1 = FUN_4057824c(param_1,param_2);
  }
  return HVar1;
}



/* 4057a744 FUN_4057a744 */

/* Boundary evidence: original MIPS .pdata 4057a744..4057a937. Semantic name remains unreviewed. */

DWORD FUN_4057a744(int param_1,int param_2,LPCWSTR param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  HANDLE hFindFile;
  int iVar3;
  wchar_t *pwVar4;
  DWORD DVar5;
  HLOCAL local_460 [2];
  _WIN32_FIND_DATAW local_458;
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  DVar5 = 0;
  if (param_2 == 1) {
    DVar1 = GetFileAttributesW(param_3);
    if (((DVar1 != 0xffffffff) && (BVar2 = RemoveDirectoryW(param_3), BVar2 == 0)) &&
       (DVar5 = GetLastError(), 0 < (int)DVar5)) {
      DVar5 = DVar5 & 0xffff | 0x80070000;
    }
  }
  else {
    local_458.dwFileAttributes = 0;
    memset(&local_458.ftCreationTime,0,0x22c);
    DVar5 = StringCchCopyW(local_458.cFileName + 0x102,0x104,param_3);
    if (-1 < (int)DVar5) {
      DVar5 = StringCchCatW(local_458.cFileName + 0x102,0x104,L"\\*");
      hFindFile = FindFirstFileW(local_458.cFileName + 0x102,&local_458);
      if ((((-1 < (int)DVar5) && (hFindFile == (HANDLE)0xffffffff)) &&
          ((*(ushort *)(param_1 + -8) & 0x40) != 0)) &&
         ((*(int *)(param_1 + 0x34) != 0 &&
          (iVar3 = PathIsSameDevice(param_3,&DAT_405a9aa4), iVar3 != 0)))) {
        local_460[0] = (HLOCAL)0x0;
        DVar5 = FUN_405860d4(*(int *)(param_1 + 0x34),param_3,local_460);
        if ((-1 < (int)DVar5) && ((DVar5 != 1 && (local_460[0] != (HLOCAL)0x0)))) {
          pwVar4 = (wchar_t *)FUN_40580ed0((int)local_460[0]);
          DVar5 = FUN_40582c5c(DAT_405aa0d0,param_3,pwVar4);
          FUN_40580ef4(local_460[0]);
        }
      }
      FindClose(hFindFile);
    }
  }
  if (*(int *)(param_1 + 0x18) == 1) {
    DVar5 = 0x800704c7;
  }
  FUN_405a7174(local_20);
  return DVar5;
}



/* 4057a938 FUN_4057a938 */

/* Boundary evidence: original MIPS .pdata 4057a938..4057ade7. Semantic name remains unreviewed. */

uint FUN_4057a938(int param_1,LPCWSTR param_2)

{
  longlong lVar1;
  DWORD DVar2;
  int iVar3;
  wchar_t *pwVar4;
  STRSAFE_LPCWSTR pszFormat;
  HANDLE hFile;
  BOOL BVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  HLOCAL local_448;
  DWORD local_444;
  wchar_t local_440;
  undefined1 auStack_43e [518];
  wchar_t local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  uVar8 = 0;
  DVar2 = GetFileAttributesW(param_2);
  if (param_2 == (LPCWSTR)0x0) {
    FUN_405a7174(local_30);
    uVar8 = 0x80070057;
  }
  else if (*(int *)(param_1 + -4) == 0) {
    FUN_405a7174(local_30);
    uVar8 = 0x8007000d;
  }
  else if (DVar2 == 0xffffffff) {
    FUN_405a7174(local_30);
    uVar8 = 0x80070002;
  }
  else {
    if ((*(ushort *)(param_1 + -8) & 0x10) == 0) {
      local_448 = (HLOCAL)0x6;
      iVar3 = PathIsSameDevice(param_2,&DAT_405a9aa4);
      uVar8 = FUN_4058abc0(param_2,(HWND)**(undefined4 **)(param_1 + -4),*(int *)(param_1 + 0x38),
                           (uint)(iVar3 == 0),(uint)(*(int *)(param_1 + 0x20) == 1),
                           (INT_PTR *)&local_448);
      if (-1 < (int)uVar8) {
        if (local_448 == (HLOCAL)0x2) {
          uVar8 = 0x800704c7;
        }
        else if (local_448 == (HLOCAL)0x7) {
          uVar8 = 1;
        }
        else if (local_448 == (HLOCAL)0x2203) {
          *(ushort *)(param_1 + -8) = *(ushort *)(param_1 + -8) | 0x10;
        }
      }
    }
    if (*(int *)(param_1 + 0x18) == 1) {
      FUN_405a7174(local_30);
      uVar8 = 0x800704c7;
    }
    else {
      if ((-1 < (int)uVar8) && (uVar8 != 1)) {
        if (((*(ushort *)(param_1 + -8) & 4) == 0) && ((*(ushort *)(param_1 + -8) & 0x100) == 0)) {
          pwVar4 = FUN_405775ec(param_2,1);
          if (pwVar4 != (wchar_t *)0x0) {
            FUN_405779e8(param_1 + 8,(int)(pwVar4 + 1));
          }
          local_440 = L'\0';
          memset(auStack_43e,0,0x206);
          local_238 = L'\0';
          memset(auStack_236,0,0x206);
          iVar3 = FUN_40577708(param_2,&local_440,0x104);
          if (iVar3 != 0) {
            pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3074,(LPWSTR)0x0,0);
            StringCchPrintfExW(&local_238,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,pszFormat,
                               &local_440);
          }
          FUN_40577a34(param_1 + 8,(int)&local_238);
        }
        hFile = CreateFileW(param_2,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
        if (hFile != (HANDLE)0xffffffff) {
          local_448 = (HLOCAL)0x0;
          memset(&local_444,0,4);
          local_448 = (HLOCAL)GetFileSize(hFile,&local_444);
          if (local_448 != (HLOCAL)0xffffffff) {
            uVar6 = *(uint *)(param_1 + 0x2c);
            uVar7 = uVar6 + (int)local_448;
            *(uint *)(param_1 + 0x2c) = uVar7;
            *(DWORD *)(param_1 + 0x30) =
                 *(int *)(param_1 + 0x30) + local_444 + (uint)(uVar7 < uVar6);
          }
          CloseHandle(hFile);
        }
        if ((((*(ushort *)(param_1 + -8) & 0x40) == 0) || (*(int *)(param_1 + 0x34) == 0)) ||
           (iVar3 = PathIsSameDevice(param_2,&DAT_405a9aa4), iVar3 == 0)) {
          SetFileAttributesW(param_2,DVar2 & 0xfffffffa);
          BVar5 = DeleteFileW(param_2);
          if ((BVar5 == 0) && (uVar8 = GetLastError(), 0 < (int)uVar8)) {
            uVar8 = uVar8 & 0xffff | 0x80070000;
          }
        }
        else {
          local_448 = (HLOCAL)0x0;
          uVar8 = FUN_405860d4(*(int *)(param_1 + 0x34),param_2,&local_448);
          if (((-1 < (int)uVar8) && (uVar8 != 1)) && (local_448 != (HLOCAL)0x0)) {
            pwVar4 = (wchar_t *)FUN_40580ed0((int)local_448);
            uVar8 = FUN_40582c5c(DAT_405aa0d0,param_2,pwVar4);
            FUN_40580ef4(local_448);
          }
        }
        if (*(int *)(param_1 + 0x18) == 1) {
          uVar8 = 0x800704c7;
        }
        if (((-1 < (int)uVar8) && (uVar8 != 1)) &&
           ((*(int *)(param_1 + 0x28) != 0 || (*(int *)(param_1 + 0x24) != 0)))) {
          lVar1 = (ulonglong)*(uint *)(param_1 + 0x2c) * 1000;
          uVar6 = __ull_div((int)lVar1,
                            *(int *)(param_1 + 0x30) * 1000 + (int)((ulonglong)lVar1 >> 0x20));
          FUN_40577a80(param_1 + 8,uVar6);
        }
      }
      FUN_405a7174(local_30);
    }
  }
  return uVar8;
}



/* 4057ade8 FUN_4057ade8 */

/* Boundary evidence: original MIPS .pdata 4057ade8..4057b157. Semantic name remains unreviewed. */

void FUN_4057ade8(int *param_1,uint param_2)

{
  int iVar1;
  DWORD DVar2;
  STRSAFE_LPCWSTR pwVar3;
  HRESULT HVar4;
  UINT uID;
  LPCWSTR pWVar5;
  int iVar6;
  uint uVar7;
  HWND pHVar8;
  wchar_t local_528;
  undefined1 auStack_526 [510];
  WCHAR local_328;
  undefined1 auStack_326 [254];
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((((*(ushort *)(param_1 + 1) & 0x400) != 0) || (-1 < (int)param_2)) || (param_2 == 0x800704c7))
  goto LAB_4057b128;
  pHVar8 = (HWND)0x0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    pHVar8 = *(HWND *)param_1[2];
  }
  pWVar5 = (LPCWSTR)param_1[4];
  if ((LPCWSTR)param_1[4] == (LPCWSTR)0x0) {
    pWVar5 = L"";
  }
  iVar1 = LoadStringW(DAT_405aa0c0,0xc05c,(LPWSTR)0x0,0);
  local_528 = L'\0';
  memset(auStack_526,0,0x1fe);
  if ((iVar1 != 0) && (pWVar5 != (LPCWSTR)0x0)) {
    if ((int)param_2 < -0x7ff8ff8f) {
      if (param_2 == 0x80070070) {
        uID = 0xc013;
      }
      else {
        uVar7 = param_2 + 0x7ff8fffe;
        if ((param_2 == 0x80070002) || (uVar7 < 2)) {
          DVar2 = GetFileAttributesW(pWVar5);
          if ((DVar2 == 0xffffffff) || ((DVar2 & 0x2000) == 0)) {
LAB_4057af90:
            uID = 0xc012;
          }
          else {
            uID = (**(code **)(*param_1 + 4))(param_1);
          }
        }
        else if (uVar7 == 3) {
          uID = 0xc00f;
        }
        else if (uVar7 == 0xc) {
          uID = 0xc00d;
        }
        else if (uVar7 == 0x14) {
          uID = 0xc011;
        }
        else {
          if (uVar7 != 0x1e) {
            iVar6 = param_2 + 0x7ff8ffb0;
            goto LAB_4057afdc;
          }
          uID = 0xc015;
        }
      }
LAB_4057b088:
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
      iVar6 = StringCchCopyW(&local_528,0x100,pwVar3);
    }
    else {
      if (param_2 == 0x8007007a) {
LAB_4057b084:
        uID = 0xc014;
        goto LAB_4057b088;
      }
      if (param_2 == 0x8007007b) {
        uID = 0xc044;
        goto LAB_4057b088;
      }
      if (param_2 == 0x800700a1) goto LAB_4057af90;
      if (param_2 == 0x800700b7) {
        uID = 0xc075;
        goto LAB_4057b088;
      }
      iVar6 = param_2 + 0x7ff8ff32;
LAB_4057afdc:
      if (iVar6 == 0) goto LAB_4057b084;
      local_328 = L'\0';
      memset(auStack_326,0,0xfe);
      FormatMessageW(0x1200,(LPCVOID)0x0,param_2 & 0xffff,0,&local_328,0x80,(va_list *)0x0);
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0xc000,(LPWSTR)0x0,0);
      iVar6 = StringCchPrintfExW(&local_528,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar3,
                                 param_2 & 0xffff,&local_328);
    }
    if (-1 < iVar6) {
      HVar4 = StringCchPrintfExW(awStack_228,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,L"%s%s"
                                 ,iVar1,&local_528);
      if (-1 < HVar4) {
        pWVar5 = (LPCWSTR)param_1[4];
        if ((LPCWSTR)param_1[4] == (LPCWSTR)0x0) {
          pWVar5 = L"";
        }
        FUN_4058a544(pHVar8,(LPCWSTR)0x3064,awStack_228,pWVar5,0x10);
        goto LAB_4057b128;
      }
    }
  }
  FUN_40577ef8((int)param_1,param_2);
LAB_4057b128:
  FUN_405a7174(local_28);
  return;
}



/* 4057b158 FUN_4057b158 */

/* Boundary evidence: original MIPS .pdata 4057b158..4057b397. Semantic name remains unreviewed. */

HRESULT FUN_4057b158(int param_1)

{
  HRESULT HVar1;
  BOOL BVar2;
  wchar_t *_Str1;
  wchar_t *_Str2;
  LPWSTR pWVar3;
  int iVar4;
  size_t local_18 [2];
  
  iVar4 = *(int *)(param_1 + 8);
  if (((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) && (*(int *)(iVar4 + 0xc) != 0)) {
    local_18[0] = 0;
    HVar1 = StringCchLengthW(*(STRSAFE_PCNZWCH *)(iVar4 + 8),0x104,local_18);
    if (HVar1 < 0) {
      return HVar1;
    }
    BVar2 = PathFileExistsW(*(LPCWSTR *)(*(int *)(param_1 + 8) + 8));
    if (BVar2 == 0) {
      return -0x7ff8fffd;
    }
    iVar4 = FUN_40577818(*(STRSAFE_PCNZWCH *)(*(int *)(param_1 + 8) + 8));
    if (iVar4 != 0) {
      return -0x7ff8ff5f;
    }
    iVar4 = *(int *)(param_1 + 8);
    if (*(short *)((local_18[0] + 1) * 2 + *(int *)(iVar4 + 8)) == 0) {
      iVar4 = _wcsnicmp(*(wchar_t **)(iVar4 + 8),*(wchar_t **)(iVar4 + 0xc),local_18[0]);
      if (iVar4 == 0) {
        if (*(short *)(*(int *)(*(int *)(param_1 + 8) + 0xc) + local_18[0] * 2) == 0) {
          _Str1 = FUN_405775ec(*(STRSAFE_PCNZWCH *)(*(int *)(param_1 + 8) + 8),1);
          _Str2 = FUN_405775ec(*(STRSAFE_PCNZWCH *)(*(int *)(param_1 + 8) + 0xc),1);
          if (((_Str1 != (wchar_t *)0x0) && (_Str2 != (wchar_t *)0x0)) &&
             (iVar4 = wcscmp(_Str1,_Str2), iVar4 == 0)) {
            return 1;
          }
        }
        if (*(short *)(local_18[0] * 2 + *(int *)(*(int *)(param_1 + 8) + 0xc)) == 0x5c) {
          return -0x7ff8ffea;
        }
      }
      pWVar3 = PathFindFileNameW(*(LPCWSTR *)(*(int *)(param_1 + 8) + 0xc));
      iVar4 = PathIsValidFileName(pWVar3);
      if (iVar4 == 0) {
        return -0x7ff8ff85;
      }
      HVar1 = FUN_40577cc0(param_1,*(wchar_t **)(*(int *)(param_1 + 8) + 8));
      return HVar1;
    }
  }
  return -0x7ff8fff3;
}



/* 4057b398 FUN_4057b398 */

/* Boundary evidence: original MIPS .pdata 4057b398..4057b713. Semantic name remains unreviewed. */

void FUN_4057b398(int *param_1,uint param_2)

{
  int iVar1;
  DWORD DVar2;
  STRSAFE_LPCWSTR pwVar3;
  HRESULT HVar4;
  UINT uID;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  LPCWSTR lpFileName;
  HWND pHVar8;
  wchar_t local_528;
  undefined1 auStack_526 [510];
  WCHAR local_328;
  undefined1 auStack_326 [254];
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((((*(ushort *)(param_1 + 1) & 0x400) != 0) || (-1 < (int)param_2)) || (param_2 == 0x800704c7))
  goto LAB_4057b6e4;
  puVar7 = (undefined4 *)param_1[2];
  pHVar8 = (HWND)0x0;
  lpFileName = L"";
  if ((puVar7 != (undefined4 *)0x0) && (pHVar8 = (HWND)*puVar7, puVar7[2] != 0)) {
    lpFileName = (LPCWSTR)puVar7[2];
  }
  iVar1 = LoadStringW(DAT_405aa0c0,0xc05f,(LPWSTR)0x0,0);
  local_528 = L'\0';
  memset(auStack_526,0,0x1fe);
  if ((iVar1 != 0) && (lpFileName != (LPCWSTR)0x0)) {
    if ((int)param_2 < -0x7ff8ff8f) {
      if (param_2 == 0x80070070) {
        uID = 0xc013;
      }
      else {
        uVar6 = param_2 + 0x7ff8fffe;
        if ((param_2 == 0x80070002) || (uVar6 < 2)) {
          DVar2 = GetFileAttributesW(lpFileName);
          if ((DVar2 == 0xffffffff) || ((DVar2 & 0x2000) == 0)) {
LAB_4057b558:
            uID = 0xc012;
          }
          else {
            uID = (**(code **)(*param_1 + 4))(param_1);
          }
        }
        else if (uVar6 == 3) {
          uID = 0xc00f;
        }
        else if (uVar6 == 0xc) {
          uID = 0xc00d;
        }
        else if (uVar6 == 0x14) {
          uID = 0xc011;
        }
        else {
          if (uVar6 != 0x1e) {
            iVar5 = param_2 + 0x7ff8ffb0;
            goto LAB_4057b5a4;
          }
          uID = 0xc015;
        }
      }
LAB_4057b650:
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
      iVar5 = StringCchCopyW(&local_528,0x100,pwVar3);
    }
    else {
      if (param_2 == 0x8007007a) {
LAB_4057b64c:
        uID = 0xc014;
        goto LAB_4057b650;
      }
      if (param_2 == 0x8007007b) {
        uID = 0xc044;
        goto LAB_4057b650;
      }
      if (param_2 == 0x800700a1) goto LAB_4057b558;
      if (param_2 == 0x800700b7) {
        uID = 0xc075;
        goto LAB_4057b650;
      }
      iVar5 = param_2 + 0x7ff8ff32;
LAB_4057b5a4:
      if (iVar5 == 0) goto LAB_4057b64c;
      local_328 = L'\0';
      memset(auStack_326,0,0xfe);
      FormatMessageW(0x1200,(LPCVOID)0x0,param_2 & 0xffff,0,&local_328,0x80,(va_list *)0x0);
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0xc000,(LPWSTR)0x0,0);
      iVar5 = StringCchPrintfExW(&local_528,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar3,
                                 param_2 & 0xffff,&local_328);
    }
    if (-1 < iVar5) {
      HVar4 = StringCchPrintfExW(awStack_228,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,L"%s%s"
                                 ,iVar1,&local_528);
      if (-1 < HVar4) {
        FUN_4058a544(pHVar8,(LPCWSTR)0x3025,awStack_228,lpFileName,0x10);
        goto LAB_4057b6e4;
      }
    }
  }
  FUN_40577ef8((int)param_1,param_2);
LAB_4057b6e4:
  FUN_405a7174(local_28);
  return;
}



/* 4057b714 FUN_4057b714 */

/* Boundary evidence: original MIPS .pdata 4057b714..4057b87f. Semantic name remains unreviewed. */

DWORD FUN_4057b714(int param_1)

{
  BOOL BVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  INT_PTR local_18 [2];
  
  DVar3 = 0;
  if ((*(ushort *)(param_1 + 4) & 0x10) == 0) {
    local_18[0] = 6;
    puVar2 = *(undefined4 **)(param_1 + 8);
    DVar3 = FUN_4058a938((LPCWSTR)puVar2[2],(LPCWSTR)puVar2[3],(HWND)*puVar2,local_18);
    if ((int)DVar3 < 0) {
      return DVar3;
    }
    if (local_18[0] == 2) {
      return 0x800704c7;
    }
    if (local_18[0] == 7) {
      return 1;
    }
  }
  BVar1 = MoveFileW(*(LPCWSTR *)(*(int *)(param_1 + 8) + 8),
                    *(LPCWSTR *)(*(int *)(param_1 + 8) + 0xc));
  if (BVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    if (((-1 < (int)DVar3) && (DVar3 != 1)) &&
       ((*(byte *)(*(int *)(param_1 + 8) + 0x10) & 0x40) != 0)) {
      FUN_40582c5c(DAT_405aa0d0,*(wchar_t **)(*(int *)(param_1 + 8) + 8),
                   *(wchar_t **)(*(int *)(param_1 + 8) + 0xc));
    }
    DVar3 = 0;
  }
  return DVar3;
}



/* 4057b880 FUN_4057b880 */

/* Boundary evidence: original MIPS .pdata 4057b880..4057b8c3. Semantic name remains unreviewed. */

undefined4 * FUN_4057b880(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_4057120c;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4057b8c4 FUN_4057b8c4 */

/* Boundary evidence: original MIPS .pdata 4057b8c4..4057bbbf. Semantic name remains unreviewed. */

int FUN_4057b8c4(STRSAFE_LPWSTR param_1,uint param_2,int *param_3)

{
  bool bVar1;
  DWORD DVar2;
  HANDLE hFindFile;
  size_t sVar3;
  BOOL BVar4;
  int iVar5;
  STRSAFE_LPWSTR local_268 [2];
  uint local_260;
  undefined1 auStack_25c [36];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  local_268[0] = (wchar_t *)0x0;
  local_260 = 0;
  memset(auStack_25c,0,0x22c);
  iVar5 = 0;
  bVar1 = true;
  if ((param_1 == (STRSAFE_LPWSTR)0x0) || (param_3 == (int *)0x0)) {
    FUN_405a7174(local_30);
    return -0x7ff8ffa9;
  }
  if (param_2 == 0) {
    FUN_405a7174(local_30);
    return -0x7ff8ff86;
  }
  DVar2 = GetFileAttributesW(param_1);
  if ((DVar2 == 0xffffffff) || ((DVar2 & 0x10) == 0)) {
    local_268[0] = FUN_405775ec(param_1,1);
    if (local_268[0] == (wchar_t *)0x0) {
      iVar5 = -0x7ff8ff5f;
      local_268[0] = (wchar_t *)0x0;
      goto LAB_4057ba30;
    }
    local_268[0] = local_268[0] + 1;
LAB_4057ba38:
    hFindFile = FindFirstFileW(param_1,(LPWIN32_FIND_DATAW)&local_260);
    if (hFindFile != (HANDLE)0xffffffff) {
      while (sVar3 = wcslen(awStack_238),
            ((int)local_268[0] - (int)param_1 >> 1) + sVar3 + 1 <= param_2) {
        wcscpy(local_268[0],awStack_238);
        if ((local_260 & 0x10) == 0) {
          iVar5 = (**(code **)(*param_3 + 4))(param_3,param_1,&local_260);
        }
        else {
          iVar5 = FUN_4057b8c4(param_1,param_2,param_3);
        }
        if ((iVar5 < 0) || (iVar5 == 1)) {
          bVar1 = false;
        }
        if ((iVar5 < 0) ||
           (BVar4 = FindNextFileW(hFindFile,(LPWIN32_FIND_DATAW)&local_260), BVar4 == 0))
        goto LAB_4057bb18;
      }
      iVar5 = -0x7ff8ff86;
LAB_4057bb18:
      FindClose(hFindFile);
      if (!bVar1) goto LAB_4057b9f8;
    }
  }
  else {
    iVar5 = (**(code **)*param_3)(param_3,0,param_1);
    if ((iVar5 < 0) || (iVar5 == 1)) goto LAB_4057b9f8;
    iVar5 = StringCchCatExW(param_1,param_2,L"\\*",local_268,(size_t *)0x0,0x1000);
    if (iVar5 < 0) {
      local_268[0] = (wchar_t *)0x0;
    }
    else {
      local_268[0] = local_268[0] + -1;
    }
LAB_4057ba30:
    if (-1 < iVar5) goto LAB_4057ba38;
  }
  if ((DVar2 != 0xffffffff) && ((DVar2 & 0x10) != 0)) {
    if (local_268[0] != (wchar_t *)0x0) {
      local_268[0] = local_268[0] + -1;
      *local_268[0] = L'\0';
    }
    iVar5 = (**(code **)*param_3)(param_3,1,param_1);
  }
LAB_4057b9f8:
  FUN_405a7174(local_30);
  return iVar5;
}



/* 4057bbc0 FUN_4057bbc0 */

/* Boundary evidence: original MIPS .pdata 4057bbc0..4057bc07. Semantic name remains unreviewed. */

void FUN_4057bbc0(int param_1)

{
  BOOL BVar1;
  
  if ((*(HWND *)(param_1 + 8) != (HWND)0x0) &&
     (BVar1 = IsWindowVisible(*(HWND *)(param_1 + 8)), BVar1 == 0)) {
    ShowWindow(*(HWND *)(param_1 + 8),5);
  }
  return;
}



/* 4057bc08 FUN_4057bc08 */

/* Boundary evidence: original MIPS .pdata 4057bc08..4057bc4f. Semantic name remains unreviewed. */

void FUN_4057bc08(int param_1)

{
  BOOL BVar1;
  
  if ((*(HWND *)(param_1 + 8) != (HWND)0x0) &&
     (BVar1 = IsWindowVisible(*(HWND *)(param_1 + 8)), BVar1 != 0)) {
    ShowWindow(*(HWND *)(param_1 + 8),0);
  }
  return;
}



/* 4057bc50 FUN_4057bc50 */

/* Boundary evidence: original MIPS .pdata 4057bc50..4057bd5f. Semantic name remains unreviewed. */

int FUN_4057bc50(int *param_1)

{
  int iVar1;
  STRSAFE_PCNZWCH psz;
  size_t local_20 [2];
  
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  if (-1 < iVar1) {
    if (iVar1 != 1) {
      local_20[0] = 0;
      for (psz = *(STRSAFE_PCNZWCH *)(param_1[2] + 8); *psz != L'\0'; psz = psz + local_20[0] + 1) {
        iVar1 = (**(code **)(*param_1 + 0x18))(param_1,psz);
        if (iVar1 < 0) goto LAB_4057bd38;
        if (iVar1 != 1) {
          iVar1 = FUN_4057b8c4((STRSAFE_LPWSTR)param_1[4],0x104,param_1 + 3);
        }
        if ((iVar1 < 0) || (iVar1 = StringCchLengthW(psz,0x104,local_20), iVar1 < 0))
        goto LAB_4057bd38;
      }
    }
    if ((-1 < iVar1) && (iVar1 != 1)) {
      return iVar1;
    }
  }
LAB_4057bd38:
  FUN_4057795c((int)(param_1 + 5));
  return iVar1;
}



/* 4057bd60 FUN_4057bd60 */

/* Boundary evidence: original MIPS .pdata 4057bd60..4057bddb. Semantic name remains unreviewed. */

void FUN_4057bd60(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40571304;
  param_1[3] = &PTR_LAB_405712fc;
  if ((void *)param_1[4] != (void *)0x0) {
    operator_delete((void *)param_1[4]);
    param_1[4] = 0;
  }
  param_1[5] = &PTR_FUN_40571234;
  if (param_1[7] != 0) {
    FUN_4057795c((int)(param_1 + 5));
  }
  *param_1 = &PTR_LAB_4057120c;
  return;
}



/* 4057bddc FUN_4057bddc */

/* Boundary evidence: original MIPS .pdata 4057bddc..4057be27. Semantic name remains unreviewed. */

undefined4 * FUN_4057bddc(undefined4 *param_1,uint param_2)

{
  FUN_4057bd60(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4057be28 FUN_4057be28 */

/* Boundary evidence: original MIPS .pdata 4057be28..4057be77. Semantic name remains unreviewed. */

void FUN_4057be28(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_4057132c;
  param_1[3] = &PTR_LAB_40571324;
  if ((void *)param_1[0x10] != (void *)0x0) {
    operator_delete((void *)param_1[0x10]);
  }
  FUN_4057bd60(param_1);
  return;
}



/* 4057be78 FUN_4057be78 */

/* Boundary evidence: original MIPS .pdata 4057be78..4057bec3. Semantic name remains unreviewed. */

undefined4 * FUN_4057be78(undefined4 *param_1,uint param_2)

{
  FUN_4057be28(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4057bed4 FUN_4057bed4 */

/* Boundary evidence: original MIPS .pdata 4057bed4..4057bf2b. Semantic name remains unreviewed. */

void FUN_4057bed4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40571354;
  param_1[3] = &PTR_FUN_4057134c;
  if (param_1[0x10] != 0) {
    FUN_40583798(DAT_405aa0d4);
    param_1[0x10] = 0;
  }
  FUN_4057bd60(param_1);
  return;
}



/* 4057bf2c FUN_4057bf2c */

/* Boundary evidence: original MIPS .pdata 4057bf2c..4057bf77. Semantic name remains unreviewed. */

undefined4 * FUN_4057bf2c(undefined4 *param_1,uint param_2)

{
  FUN_4057bed4(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4057bf90 FUN_4057bf90 */

/* Boundary evidence: original MIPS .pdata 4057bf90..4057c063. Semantic name remains unreviewed. */

undefined4 FUN_4057bf90(int param_1,undefined4 param_2,int param_3)

{
  longlong lVar1;
  BOOL BVar2;
  HWND hWnd;
  
  lVar1 = (ulonglong)*(uint *)(param_3 + 0x1c) * 0xffffffff +
          CONCAT44(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_3 + 0x20)) +
          (ulonglong)*(uint *)(param_1 + 8);
  *(longlong *)(param_1 + 8) = lVar1;
  if (*(int *)(param_1 + 0x10) != 0) {
    if ((((int)((ulonglong)lVar1 >> 0x20) != 0) || (0xc800 < (uint)lVar1)) &&
       ((hWnd = *(HWND *)(*(int *)(param_1 + 0x10) + 8), hWnd == (HWND)0x0 ||
        (BVar2 = IsWindowVisible(hWnd), BVar2 == 0)))) {
      FUN_4057bbc0(*(int *)(param_1 + 0x10));
    }
    if (*(int *)(*(int *)(param_1 + 0x10) + 0x10) == 1) {
      return 0x800704c7;
    }
  }
  return 0;
}



/* 4057c064 FUN_4057c064 */

/* Boundary evidence: original MIPS .pdata 4057c064..4057c0c3. Semantic name remains unreviewed. */

undefined4 * FUN_4057c064(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40571234;
  if (param_1[2] != 0) {
    FUN_4057795c((int)param_1);
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4057c0c4 FUN_4057c0c4 */

/* Boundary evidence: original MIPS .pdata 4057c0c4..4057c22b. Semantic name remains unreviewed. */

undefined4 FUN_4057c0c4(HWND param_1,int param_2,short param_3,int param_4)

{
  LONG LVar1;
  HWND pHVar2;
  int iVar3;
  
  LVar1 = GetWindowLongW(param_1,-0x15);
  if ((LVar1 == 0) && (param_2 != 0x110)) {
    return 0;
  }
  if (param_2 == 2) {
    *(undefined4 *)(LVar1 + 0x14) = 0;
    *(undefined4 *)(LVar1 + 8) = 0;
    SetWindowLongW(param_1,-0x15,0);
    iVar3 = *(int *)(LVar1 + 0xc);
LAB_4057c1f4:
    if (iVar3 != 0) {
      EventModify(iVar3,3);
    }
  }
  else {
    if (param_2 != 0x10) {
      if (param_2 == 0x110) {
        *(HWND *)(param_4 + 8) = param_1;
        SetWindowLongW(param_1,-0x15,param_4);
        pHVar2 = GetDlgItem(param_1,0x2001);
        SendMessageW(pHVar2,0x406,0,100);
        pHVar2 = GetDlgItem(param_1,0x2001);
        SendMessageW(pHVar2,0x402,0,0);
        FUN_405a6ca0(param_1,8);
        iVar3 = *(int *)(param_4 + 0xc);
        goto LAB_4057c1f4;
      }
      if (param_2 != 0x111) {
        return 0;
      }
      if (param_3 != 2) {
        return 1;
      }
      *(undefined4 *)(LVar1 + 0x10) = 1;
      FUN_4057bc08(LVar1);
    }
    DestroyWindow(param_1);
  }
  return 1;
}



/* 4057c22c SHFileOperationW */

/* Boundary evidence: original MIPS .pdata 4057c22c..4057c45b. Semantic name remains unreviewed. */

int SHFileOperationW(LPSHFILEOPSTRUCTW lpFileOp)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  UINT UVar4;
  undefined **ppuVar5;
  int iVar6;
  
                    /* 0xc22c  14  SHFileOperationW */
  iVar6 = 1;
  if (lpFileOp == (LPSHFILEOPSTRUCTW)0x0) {
    return 1;
  }
  if ((lpFileOp->fFlags & 0xf8a3) != 0) {
    return 1;
  }
  UVar4 = lpFileOp->wFunc;
  if (UVar4 == 1) {
    piVar1 = operator_new(0x48);
    if (piVar1 != (int *)0x0) {
      *(undefined2 *)(piVar1 + 1) = 0;
      piVar1[2] = 0;
      piVar1[3] = (int)&PTR_LAB_40571204;
      piVar1[4] = 0;
      piVar1[5] = (int)&PTR_FUN_40571234;
      ppuVar3 = &PTR_FUN_405713a4;
      ppuVar5 = &PTR_FUN_4057139c;
LAB_4057c3c8:
      piVar1[6] = 0;
      piVar1[7] = 0;
      piVar1[8] = 0;
      piVar1[9] = 0;
      piVar1[10] = 0;
      piVar1[0x11] = 0;
LAB_4057c3e0:
      piVar1[3] = (int)ppuVar5;
      piVar1[0x10] = 0;
      piVar1[0xf] = 0;
      piVar1[0xe] = 0;
      piVar1[0xd] = 0;
      piVar1[0xc] = 0;
      piVar1[0xb] = 0;
LAB_4057c3fc:
      *piVar1 = (int)ppuVar3;
      goto LAB_4057c408;
    }
  }
  else if (UVar4 == 2) {
    piVar1 = operator_new(0x48);
    if (piVar1 != (int *)0x0) {
      *(undefined2 *)(piVar1 + 1) = 0;
      piVar1[2] = 0;
      piVar1[3] = (int)&PTR_LAB_40571204;
      piVar1[4] = 0;
      piVar1[5] = (int)&PTR_FUN_40571234;
      ppuVar3 = &PTR_FUN_4057137c;
      ppuVar5 = &PTR_FUN_40571374;
      goto LAB_4057c3c8;
    }
  }
  else if (UVar4 == 3) {
    piVar1 = operator_new(0x48);
    if (piVar1 != (int *)0x0) {
      *(undefined2 *)(piVar1 + 1) = 0;
      piVar1[2] = 0;
      piVar1[3] = (int)&PTR_LAB_40571204;
      piVar1[4] = 0;
      piVar1[5] = (int)&PTR_FUN_40571234;
      piVar1[6] = 0;
      piVar1[7] = 0;
      piVar1[8] = 0;
      piVar1[9] = 0;
      piVar1[10] = 0;
      ppuVar3 = &PTR_FUN_40571354;
      ppuVar5 = &PTR_FUN_4057134c;
      piVar1[0x11] = 1;
      goto LAB_4057c3e0;
    }
  }
  else {
    if (UVar4 != 4) {
      return 1;
    }
    piVar1 = operator_new(0xc);
    if (piVar1 != (int *)0x0) {
      ppuVar3 = &PTR_FUN_40571220;
      *(undefined2 *)(piVar1 + 1) = 0;
      piVar1[2] = 0;
      goto LAB_4057c3fc;
    }
  }
  piVar1 = (int *)0x0;
LAB_4057c408:
  if (piVar1 != (int *)0x0) {
    iVar2 = FUN_40577f80(piVar1,(int)lpFileOp);
    (**(code **)(*piVar1 + 0x10))(piVar1,1);
    if (-1 < iVar2) {
      iVar6 = 0;
    }
  }
  return iVar6;
}



/* 4057c45c FUN_4057c45c */

/* Boundary evidence: original MIPS .pdata 4057c45c..4057c4a7. Semantic name remains unreviewed. */

undefined4 * FUN_4057c45c(undefined4 *param_1,uint param_2)

{
  FUN_4057be28(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4057c4a8 FUN_4057c4a8 */

/* Boundary evidence: original MIPS .pdata 4057c4a8..4057c4f3. Semantic name remains unreviewed. */

undefined4 * FUN_4057c4a8(undefined4 *param_1,uint param_2)

{
  FUN_4057be28(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4057c4f4 FUN_4057c4f4 */

/* Boundary evidence: original MIPS .pdata 4057c4f4..4057c62f. Semantic name remains unreviewed. */

undefined4 FUN_4057c4f4(int param_1)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  HWND hDlg;
  LONG LVar1;
  BOOL BVar2;
  INITCOMMONCONTROLSEX local_38;
  tagMSG local_30;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 8) == 0)) {
    memset(&local_38.dwICC,0,4);
    local_30.hwnd = (HWND)0x0;
    memset(&local_30.message,0,0x18);
    local_38.dwICC = 0x20;
    local_38.dwSize = 8;
    InitCommonControlsEx(&local_38);
    hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2000,(LPCWSTR)0x5);
    lpTemplate = LoadResource(DAT_405aa0c0,hResInfo);
    hDlg = CreateDialogIndirectParamW
                     (DAT_405aa0c0,lpTemplate,*(HWND *)(param_1 + 4),FUN_4057c0c4,param_1);
    while (BVar2 = GetMessageW(&local_30,(HWND)0x0,0,0), BVar2 != 0) {
      BVar2 = IsDialogMessageW(hDlg,&local_30);
      if (BVar2 == 0) {
        TranslateMessage(&local_30);
        DispatchMessageW(&local_30);
      }
      BVar2 = IsWindow(hDlg);
      if (BVar2 == 0) {
        return 0xffffffff;
      }
      LVar1 = GetWindowLongW(hDlg,-0x15);
      if (LVar1 != param_1) {
        return 0xffffffff;
      }
    }
  }
  return 0xffffffff;
}



/* 4057c630 FUN_4057c630 */

/* Boundary evidence: original MIPS .pdata 4057c630..4057c6ef. Semantic name remains unreviewed. */

void FUN_4057c630(LPVOID param_1,undefined4 param_2)

{
  HANDLE pvVar1;
  
  if (*(int *)((int)param_1 + 8) == 0) {
    *(undefined4 *)((int)param_1 + 4) = param_2;
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)param_1 + 0xc) = pvVar1;
    if (pvVar1 != (HANDLE)0x0) {
      pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_4057c4f4,param_1,0,(LPDWORD)0x0);
      if (pvVar1 != (HANDLE)0x0) {
        WaitForSingleObject(*(HANDLE *)((int)param_1 + 0xc),0xffffffff);
        CloseHandle(pvVar1);
      }
      CloseHandle(*(HANDLE *)((int)param_1 + 0xc));
      *(undefined4 *)((int)param_1 + 0xc) = 0;
    }
  }
  return;
}



/* 4057c6f0 FUN_4057c6f0 */

/* Boundary evidence: original MIPS .pdata 4057c6f0..4057c883. Semantic name remains unreviewed. */

HRESULT FUN_4057c6f0(int *param_1)

{
  UINT uID;
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  STRSAFE_PCNZWCH pszSrc;
  size_t local_240 [2];
  undefined **local_238 [2];
  int local_230;
  int local_22c;
  int *local_228;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  HVar2 = 0;
  if ((*(ushort *)(param_1 + 1) & 4) == 0) {
    piVar3 = param_1 + 5;
    FUN_4057c630(piVar3,*(undefined4 *)param_1[2]);
    if ((*(ushort *)(param_1 + 1) & 0x100) == 0) {
      uID = (**(code **)(*param_1 + 0x1c))(param_1);
      iVar1 = LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
      FUN_40577a34((int)piVar3,iVar1);
    }
    else {
      FUN_405779e8((int)piVar3,*(int *)(param_1[2] + 0x1a));
    }
  }
  local_238[0] = &PTR_LAB_405711f8;
  local_228 = param_1 + 5;
  local_230 = 0;
  local_22c = 0;
  local_240[0] = 0;
  pszSrc = *(STRSAFE_PCNZWCH *)(param_1[2] + 8);
  if (pszSrc != (STRSAFE_PCNZWCH)0x0) {
    while (*pszSrc != L'\0') {
      HVar2 = StringCchCopyW(awStack_220,0x104,pszSrc);
      if (((HVar2 < 0) || (HVar2 = FUN_4057b8c4(awStack_220,0x104,(int *)local_238), HVar2 < 0)) ||
         (HVar2 = StringCchLengthW(pszSrc,0x104,local_240), HVar2 < 0)) goto LAB_4057c860;
      pszSrc = pszSrc + local_240[0] + 1;
      if (pszSrc == (STRSAFE_PCNZWCH)0x0) break;
    }
  }
  param_1[0xc] = local_230;
  param_1[0xd] = local_22c;
LAB_4057c860:
  FUN_405a7174(local_18);
  return HVar2;
}



/* 4057c884 FUN_4057c884 */

/* Boundary evidence: original MIPS .pdata 4057c884..4057c9cf. Semantic name remains unreviewed. */

HRESULT FUN_4057c884(int *param_1)

{
  HRESULT HVar1;
  BOOL BVar2;
  LPCWSTR lpCaption;
  LPCWSTR lpText;
  int iVar3;
  ULARGE_INTEGER local_28;
  ULARGE_INTEGER local_20;
  
  HVar1 = FUN_4057c6f0(param_1);
  if (((-1 < HVar1) && (HVar1 != 1)) && ((*(ushort *)(param_1 + 1) & 0x10) == 0)) {
    local_28.s.LowPart = 0;
    memset(&local_28.s.HighPart,0,4);
    local_20.s.LowPart = 0;
    memset(&local_20.s.HighPart,0,4);
    BVar2 = GetDiskFreeSpaceExW(*(LPCWSTR *)(param_1[2] + 0xc),&local_28,&local_20,
                                (PULARGE_INTEGER)0x0);
    if (BVar2 != 0) {
      if ((local_28.s.HighPart <= (uint)param_1[0xd]) &&
         ((local_28.s.HighPart != param_1[0xd] || (local_28.s.LowPart < (uint)param_1[0xc])))) {
        lpCaption = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x3085,(LPWSTR)0x0,0);
        lpText = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x3084,(LPWSTR)0x0,0);
        iVar3 = MessageBoxW(*(HWND *)param_1[2],lpText,lpCaption,0x10034);
        if (iVar3 == 7) {
          HVar1 = -0x7ff8fb39;
        }
      }
    }
  }
  return HVar1;
}



/* 4057c9dc FUN_4057c9dc */

/* Boundary evidence: original MIPS .pdata 4057c9dc..4057cb4f. Semantic name remains unreviewed. */

BOOL FUN_4057c9dc(int param_1,HWND param_2,int param_3)

{
  int iVar1;
  int iVar2;
  BOOL BVar3;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  tagRECT local_58;
  undefined4 local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  BVar3 = 0;
  GetWindowRect(param_2,&local_58);
  memset(&local_48,0,0x30);
  local_48 = 0x30;
  if ((*(code **)(param_1 + 0x69c) == (code *)0x0) ||
     (iVar1 = (**(code **)(param_1 + 0x69c))(&local_48), iVar1 == 0)) {
    SystemParametersInfoW(0x30,0,&local_68,0);
  }
  else {
    local_68 = local_40;
    local_64 = local_3c;
    local_60 = local_38;
    local_5c = local_34;
  }
  if ((param_3 != 0) || ((local_44 & 1) != 0)) {
    iVar1 = ((local_58.left - local_58.right) - local_68) + local_60;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 1;
    }
    iVar1 = iVar1 >> 1;
    iVar2 = ((local_58.top - local_58.bottom) - local_64) + local_5c;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 1;
    }
    iVar2 = iVar2 >> 1;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    BVar3 = SetWindowPos(param_2,(HWND)0x0,local_68 + iVar1,local_64 + iVar2,0,0,5);
  }
  return BVar3;
}



/* 4057cb50 FUN_4057cb50 */

int FUN_4057cb50(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar1 = 3;
  iVar2 = 3;
  if (param_3 == 0) {
    iVar2 = 2;
  }
  if (param_3 == 0) {
    iVar1 = 2;
  }
  iVar1 = iVar1 * 6 + iVar2 * 0x18;
  if ((param_1 != 0) && (0 < param_2)) {
    pbVar3 = (byte *)(param_1 + 9);
    do {
      if ((*pbVar3 & 1) == 0) {
        iVar1 = iVar1 + 0x18;
      }
      else {
        iVar1 = iVar1 + 6;
      }
      param_2 = param_2 + -1;
      pbVar3 = pbVar3 + 0x14;
    } while (param_2 != 0);
  }
  return iVar1;
}



/* 4057cbc8 FUN_4057cbc8 */

/* Boundary evidence: original MIPS .pdata 4057cbc8..4057cceb. Semantic name remains unreviewed. */

void FUN_4057cbc8(int param_1)

{
  int *piVar1;
  
  *(undefined2 *)(param_1 + 0x44c) = 0;
  *(undefined2 *)(param_1 + 0x3c) = 0;
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x24) + 8))();
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x2c) + 8))();
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,0);
    (**(code **)(**(int **)(param_1 + 0x20) + 0x28))();
    *(undefined4 *)(param_1 + 0x678) = 0;
    (**(code **)(**(int **)(param_1 + 0x20) + 8))();
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  if (*(int *)(param_1 + 0x67c) != 0) {
    SetWindowLongW(*(HWND *)(param_1 + 0x678),-4,*(int *)(param_1 + 0x67c));
    *(undefined4 *)(param_1 + 0x67c) = 0;
  }
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (*(HLOCAL *)(param_1 + 0x14) != (HLOCAL)0x0) {
    FUN_40580ef4(*(HLOCAL *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



/* 4057ccec FUN_4057ccec */

/* Boundary evidence: original MIPS .pdata 4057ccec..4057cee7. Semantic name remains unreviewed. */

void FUN_4057ccec(int param_1,HDC param_2,RECT *param_3)

{
  HGDIOBJ h;
  DWORD color;
  COLORREF color_00;
  HGDIOBJ h_00;
  HDC hDC;
  tagRECT local_250;
  POINT local_240;
  int local_238;
  int local_234;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  hDC = (HDC)0x0;
  if ((param_2 != (HDC)0x0) ||
     (param_2 = GetDC(*(HWND *)(param_1 + 0x658)), hDC = param_2, param_2 != (HDC)0x0)) {
    CopyRect(&local_250,param_3);
    FillRect(param_2,&local_250,*(HBRUSH *)(param_1 + 0x690));
    h = SelectObject(param_2,*(HGDIOBJ *)(param_1 + 0x68c));
    color = GetSysColor(0x40000012);
    color_00 = SetTextColor(param_2,color);
    SetBkMode(param_2,1);
    h_00 = GetStockObject(6);
    SelectObject(param_2,h_00);
    local_240.y = local_250.top + 1;
    local_240.x = local_250.left;
    local_238 = local_250.right;
    local_234 = local_240.y;
    Polyline(param_2,&local_240,2);
    local_250.right = local_250.right + -0x30;
    local_250.bottom = local_250.top + 0x16;
    if (*(HICON *)(param_1 + 0x694) != (HICON)0x0) {
      DrawIconEx(param_2,local_250.left + 6,local_250.top + 3,*(HICON *)(param_1 + 0x694),0x10,0x10,
                 0,(HBRUSH)0x0,3);
      local_250.left = local_250.left + 0x1a;
    }
    StringCchCopyW(awStack_230,0x104,(STRSAFE_LPCWSTR)(param_1 + 0x3c));
    PathCompactPathW(param_2,awStack_230,local_250.right - local_250.left);
    DrawTextW(param_2,awStack_230,-1,&local_250,0x824);
    if (color_00 != 0xffffffff) {
      SetTextColor(param_2,color_00);
    }
    if (h != (HGDIOBJ)0x0) {
      SelectObject(param_2,h);
    }
    if (hDC != (HDC)0x0) {
      ReleaseDC(*(HWND *)(param_1 + 0x658),hDC);
    }
  }
  FUN_405a7174(local_28);
  return;
}



/* 4057cee8 FUN_4057cee8 */

/* Boundary evidence: original MIPS .pdata 4057cee8..4057cf4f. Semantic name remains unreviewed. */

undefined4 FUN_4057cee8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 local_40 [12];
  
  pcVar3 = *(code **)(param_1 + 0x69c);
  uVar2 = 0;
  if (pcVar3 != (code *)0x0) {
    memset(local_40,0,0x30);
    local_40[0] = 0x30;
    iVar1 = (*pcVar3)(local_40);
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 4057cf50 FUN_4057cf50 */

/* Boundary evidence: original MIPS .pdata 4057cf50..4057d0b7. Semantic name remains unreviewed. */

WPARAM FUN_4057cf50(int param_1)

{
  wchar_t wVar1;
  HWND hWnd;
  size_t sVar2;
  STRSAFE_LPCWSTR pszSrc;
  wchar_t *pwVar3;
  WPARAM wParam;
  
  wParam = 0;
  hWnd = GetDlgItem(*(HWND *)(param_1 + 0x658),0x2507);
  pwVar3 = *(wchar_t **)(*(int *)(param_1 + 0x30) + 0xc);
  *(STRSAFE_LPWSTR)(param_1 + 0x244) = L'\0';
  if (hWnd != (HWND)0x0) {
    if (pwVar3 == (wchar_t *)0x0) {
      EnableWindow(hWnd,0);
    }
    else {
      wVar1 = *pwVar3;
      while (wVar1 != L'\0') {
        wParam = SendMessageW(hWnd,0x143,0,(LPARAM)pwVar3);
        sVar2 = wcslen(pwVar3);
        pwVar3 = pwVar3 + sVar2 + 1;
        SendMessageW(hWnd,0x151,wParam,(LPARAM)pwVar3);
        sVar2 = wcslen(pwVar3);
        pwVar3 = pwVar3 + sVar2 + 1;
        wVar1 = *pwVar3;
      }
      SendMessageW(hWnd,0x14e,*(int *)(*(int *)(param_1 + 0x30) + 0x18) - 1,0);
      pszSrc = (STRSAFE_LPCWSTR)
               SendMessageW(hWnd,0x150,*(int *)(*(int *)(param_1 + 0x30) + 0x18) - 1,0);
      StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x244),0x104,pszSrc);
      SendMessageW(hWnd,0x155,1,0);
    }
  }
  return wParam;
}



/* 4057d0b8 FUN_4057d0b8 */

/* Boundary evidence: original MIPS .pdata 4057d0b8..4057d25b. Semantic name remains unreviewed. */

undefined4 FUN_4057d0b8(int param_1)

{
  HRESULT HVar1;
  BOOL BVar2;
  HANDLE pvVar3;
  DWORD DVar4;
  HGDIOBJ h;
  HFONT pHVar5;
  HBRUSH pHVar6;
  HMODULE pHVar7;
  int iVar8;
  undefined4 uVar9;
  INITCOMMONCONTROLSEX local_78;
  LOGFONTW local_70;
  uint local_14;
  
  local_14 = DAT_405a9a3c;
  uVar9 = 0;
  HVar1 = SHGetDesktopFolder((IShellFolder **)(param_1 + 0x18));
  if ((-1 < HVar1) && (*(IShellFolder **)(param_1 + 0x18) != (IShellFolder *)0x0)) {
    local_78.dwSize = 8;
    local_78.dwICC = 5;
    BVar2 = InitCommonControlsEx(&local_78);
    if (BVar2 == 0) {
      SetLastError(0x45a);
    }
    else {
      uVar9 = 1;
      pvVar3 = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1506,1,0x10,0x10,0);
      *(HANDLE *)(param_1 + 0x694) = pvVar3;
      DVar4 = GetFileAttributesW(L"\\windows\\peghelp.exe");
      if (DVar4 == 0xffffffff) {
        *(byte *)(param_1 + 0x654) = *(byte *)(param_1 + 0x654) & 0xfb;
      }
      else {
        *(byte *)(param_1 + 0x654) = *(byte *)(param_1 + 0x654) | 4;
      }
      h = GetStockObject(0xd);
      GetObjectW(h,0x5c,&local_70);
      local_70.lfHeight = 0x10;
      local_70.lfWidth = 0;
      local_70.lfWeight = 700;
      local_70.lfPitchAndFamily = ' ';
      pHVar5 = CreateFontIndirectW(&local_70);
      *(HFONT *)(param_1 + 0x68c) = pHVar5;
      DVar4 = GetSysColor(0x4000000f);
      pHVar6 = CreateSolidBrush(DVar4);
      *(HBRUSH *)(param_1 + 0x690) = pHVar6;
      pHVar7 = LoadLibraryW(L"coredll.dll");
      *(HMODULE *)(param_1 + 0x698) = pHVar7;
      if (pHVar7 != (HMODULE)0x0) {
        iVar8 = GetProcAddressW(pHVar7,L"SipGetInfo");
        *(int *)(param_1 + 0x69c) = iVar8;
        if (iVar8 == 0) {
          *(undefined4 *)(param_1 + 0x69c) = 0;
        }
      }
    }
  }
  FUN_405a7174(local_14);
  return uVar9;
}



/* 4057d25c FUN_4057d25c */

/* Boundary evidence: original MIPS .pdata 4057d25c..4057d48f. Semantic name remains unreviewed. */

int FUN_4057d25c(int param_1,int *param_2,LPCITEMIDLIST param_3,undefined4 *param_4)

{
  int iVar1;
  HRESULT HVar2;
  LPCITEMIDLIST pIVar3;
  HLOCAL pvVar4;
  int iVar5;
  LPCITEMIDLIST local_340;
  int *local_33c;
  LPCITEMIDLIST local_338;
  uint local_334;
  STRRET local_330;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  iVar5 = 0;
  local_334 = 0x28010000;
  local_340 = (LPCITEMIDLIST)0x0;
  local_338 = param_3;
  if (((param_2 != (int *)0x0) || (param_2 = *(int **)(param_1 + 0x1c), param_2 != (int *)0x0)) &&
     (iVar1 = (**(code **)(*param_2 + 0x24))(param_2,1,&local_338,&local_334), -1 < iVar1)) {
    if ((local_334 & 0x28000000) == 0) {
      if (((local_334 & 0x10000) != 0) &&
         ((*(uint *)(*(int *)(param_1 + 0x30) + 0x34) & 0x100000) == 0)) {
        local_330.uType = 0;
        memset(&local_330.u,0,0x104);
        iVar1 = (**(code **)(*param_2 + 0x2c))(param_2,local_338,0x8000,&local_330);
        if ((-1 < iVar1) &&
           ((HVar2 = StrRetToBufW(&local_330,local_338,aWStack_228,0x104), -1 < HVar2 &&
            (iVar1 = SHGetShortcutTarget(aWStack_228,aWStack_228,0x104), iVar1 != 0)))) {
          PathRemoveQuotesAndArgs(aWStack_228);
          local_33c = (int *)0x0;
          iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))
                            (*(int **)(param_1 + 0x18),0,0,aWStack_228,0,&local_340,0);
          if ((-1 < iVar1) &&
             (HVar2 = SHBindToParent(local_340,(IID *)&DAT_40572b68,&local_33c,(LPCITEMIDLIST *)0x0)
             , -1 < HVar2)) {
            pIVar3 = (LPCITEMIDLIST)FUN_40581470((ushort *)local_340);
            iVar1 = FUN_4057d25c(param_1,local_33c,pIVar3,(undefined4 *)0x0);
            if (iVar1 != 0) {
              iVar5 = 1;
            }
          }
          if (local_33c != (int *)0x0) {
            (**(code **)(*local_33c + 8))();
          }
        }
      }
    }
    else {
      iVar5 = 1;
    }
  }
  if ((param_4 != (undefined4 *)0x0) && (iVar5 != 0)) {
    pvVar4 = FUN_405813a0((ushort *)local_340,-1);
    *param_4 = pvVar4;
  }
  if (local_340 != (LPCITEMIDLIST)0x0) {
    FUN_40580ef4(local_340);
  }
  FUN_405a7174(local_20);
  return iVar5;
}



/* 4057d490 FUN_4057d490 */

/* Boundary evidence: original MIPS .pdata 4057d490..4057d61b. Semantic name remains unreviewed. */

HRESULT FUN_4057d490(int *param_1,STRSAFE_LPCWSTR param_2)

{
  HRESULT HVar1;
  int iVar2;
  LPCITEMIDLIST local_230;
  int *local_22c;
  LPCITEMIDLIST local_228;
  uint local_224;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  local_230 = (LPCITEMIDLIST)0x0;
  local_228 = (LPCITEMIDLIST)0x0;
  local_22c = (int *)0x0;
  local_224 = 0x68000000;
  if ((param_2 == (STRSAFE_LPCWSTR)0x0) || (*param_2 == L'\0')) {
    HVar1 = -0x7ff8ffa9;
  }
  else {
    HVar1 = StringCchCopyW(awStack_220,0x104,param_2);
    if (-1 < HVar1) {
      PathRemoveTrailingSlashes(awStack_220);
      iVar2 = (**(code **)(*(int *)param_1[6] + 0xc))
                        ((int *)param_1[6],0,0,awStack_220,0,&local_230,0);
      if ((((iVar2 < 0) ||
           (HVar1 = SHBindToParent(local_230,(IID *)&DAT_40572b68,&local_22c,&local_228), HVar1 < 0)
           ) || (iVar2 = (**(code **)(*local_22c + 0x24))(local_22c,1,&local_228,&local_224),
                iVar2 < 0)) || ((local_224 & 0x28000000) == 0)) {
        HVar1 = -0x7fffbffb;
      }
      else {
        HVar1 = (**(code **)(*param_1 + 0x2c))(param_1,local_230,1);
      }
    }
  }
  if (local_230 != (LPCITEMIDLIST)0x0) {
    FUN_40580ef4(local_230);
  }
  if (local_228 != (LPCITEMIDLIST)0x0) {
    FUN_40580ef4(local_228);
  }
  if (local_22c != (int *)0x0) {
    (**(code **)(*local_22c + 8))();
  }
  FUN_405a7174(local_18);
  return HVar1;
}



/* 4057d61c FUN_4057d61c */

/* Boundary evidence: original MIPS .pdata 4057d61c..4057d6a3. Semantic name remains unreviewed. */

undefined4 FUN_4057d61c(int param_1)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  if (*(int *)(*(int *)(param_1 + 0x30) + 0x44) != 0) {
    local_20 = *(undefined4 *)(param_1 + 0x658);
    local_18 = 0xfffffda1;
    local_14 = *(int *)(param_1 + 0x30);
    local_1c = 0;
    local_10 = 0;
    (**(code **)(local_14 + 0x44))(local_20,0x4e,0,&local_20);
  }
  return 0;
}



/* 4057d6a4 FUN_4057d6a4 */

/* Boundary evidence: original MIPS .pdata 4057d6a4..4057d917. Semantic name remains unreviewed. */

undefined4 FUN_4057d6a4(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  wchar_t wVar1;
  size_t sVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  int iVar6;
  wchar_t *_Source;
  wchar_t *_Dest;
  
  *param_3 = L'\0';
  uVar5 = 0;
  sVar2 = wcslen(param_4);
  wVar1 = *param_4;
  if (wVar1 != L'\\') {
    sVar3 = wcslen(param_2);
    sVar2 = sVar3 + sVar2 + 1;
  }
  if (sVar2 < 0x104) {
    if (wVar1 == L'\0') {
      wcscpy(param_3,param_2);
    }
    else {
      if (wVar1 == L'\\') {
        param_4 = param_4 + 1;
        wcscpy(param_3,L"\\");
      }
      else {
        wcscpy(param_3,param_2);
        sVar2 = wcslen(param_3);
        if ((sVar2 != 0) && (param_3[sVar2 - 1] != L'\\')) {
          wcscat(param_3,L"\\");
        }
      }
      sVar2 = wcslen(param_3);
      _Dest = param_3 + sVar2;
      while (pwVar4 = wcschr(param_4,L'.'), _Source = param_4, pwVar4 != (wchar_t *)0x0) {
        if ((pwVar4 == param_4) || (pwVar4[-1] == L'\\')) {
          if (param_4 < pwVar4) {
            *pwVar4 = L'\0';
            wcscpy(_Dest,param_4);
            *pwVar4 = L'.';
            _Dest = _Dest + ((int)pwVar4 - (int)param_4 >> 1);
            _Source = pwVar4;
          }
          iVar6 = 0;
          wVar1 = *pwVar4;
          while (wVar1 == L'.') {
            pwVar4 = pwVar4 + 1;
            iVar6 = iVar6 + 1;
            wVar1 = *pwVar4;
          }
          param_4 = pwVar4;
          if (*pwVar4 != L'\0') {
            if (*pwVar4 != L'\\') goto LAB_4057d874;
            param_4 = pwVar4 + 1;
          }
          while (0 < iVar6) {
            iVar6 = iVar6 + -1;
            pwVar4 = wcsrchr(param_3,L'\\');
            if ((pwVar4 == (wchar_t *)0x0) || (pwVar4 == param_3 + 1)) break;
            *pwVar4 = L'\0';
            _Dest = pwVar4;
          }
          wcscpy(_Dest,L"\\");
          _Dest = _Dest + 1;
        }
        else {
LAB_4057d874:
          pwVar4 = wcschr(pwVar4,L'\\');
          if (pwVar4 == (wchar_t *)0x0) break;
          param_4 = pwVar4 + 1;
          wVar1 = *param_4;
          *param_4 = L'\0';
          wcscpy(_Dest,_Source);
          *param_4 = wVar1;
          _Dest = _Dest + ((int)param_4 - (int)_Source >> 1);
        }
      }
      wcscpy(_Dest,_Source);
      PathRemoveTrailingSlashes(param_3);
    }
    uVar5 = 1;
  }
  return uVar5;
}



/* 4057d918 FUN_4057d918 */

/* Boundary evidence: original MIPS .pdata 4057d918..4057da57. Semantic name remains unreviewed. */

undefined4 FUN_4057d918(int param_1)

{
  void *_Dst;
  short *psVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  size_t _Size;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x38) != 0) {
    for (psVar1 = (short *)(param_1 + 0x244); (*psVar1 != 0 && (*psVar1 != 0x2e));
        psVar1 = psVar1 + 1) {
    }
    if (*psVar1 != 0) {
      psVar1 = psVar1 + 1;
      sVar2 = *psVar1;
      if (((sVar2 != 0) && (sVar2 != 0x2a)) && (sVar2 != 0x3f)) {
        iVar3 = 0;
        do {
          if (sVar2 == 0x3b) break;
          iVar3 = iVar3 + 1;
          sVar2 = psVar1[iVar3];
        } while (sVar2 != 0);
        _Size = iVar3 * 2;
        _Dst = (void *)(**(code **)(*DAT_405aa0c8 + 0x10))
                                 (DAT_405aa0c8,*(int *)(param_1 + 0x38),_Size + 2);
        if (_Dst == (void *)0x0) {
          (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,*(undefined4 *)(param_1 + 0x38));
          *(undefined4 *)(param_1 + 0x38) = 0;
          return 0;
        }
        *(void **)(param_1 + 0x38) = _Dst;
        memcpy(_Dst,psVar1,_Size);
        *(undefined2 *)(_Size + *(int *)(param_1 + 0x38)) = 0;
      }
      uVar4 = 1;
    }
  }
  return uVar4;
}



/* 4057da58 FUN_4057da58 */

/* Boundary evidence: original MIPS .pdata 4057da58..4057db13. Semantic name remains unreviewed. */

void FUN_4057da58(int param_1)

{
  undefined4 *_Dst;
  
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (*(HICON *)(param_1 + 0x694) != (HICON)0x0) {
    DestroyIcon(*(HICON *)(param_1 + 0x694));
    *(undefined4 *)(param_1 + 0x694) = 0;
  }
  if (*(HGDIOBJ *)(param_1 + 0x68c) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x68c));
    *(undefined4 *)(param_1 + 0x68c) = 0;
  }
  if (*(HGDIOBJ *)(param_1 + 0x690) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x690));
    *(undefined4 *)(param_1 + 0x690) = 0;
  }
  _Dst = (undefined4 *)(param_1 + 0x698);
  if ((HMODULE)*_Dst != (HMODULE)0x0) {
    FreeLibrary((HMODULE)*_Dst);
    *_Dst = 0;
    memset(_Dst,0,8);
  }
  return;
}



/* 4057db14 FUN_4057db14 */

/* Boundary evidence: original MIPS .pdata 4057db14..4057dbe7. Semantic name remains unreviewed. */

void FUN_4057db14(int param_1,HWND param_2)

{
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c;
  
  local_28 = 0x1001;
  local_20 = 0x1041;
  local_10 = 0x1061;
  local_24 = 0;
  local_1c = 0;
  local_18 = 0x1042;
  local_14 = 0;
  local_c = 0;
  (**(code **)(**(int **)(param_1 + 0x2c) + 0xc))
            (*(int **)(param_1 + 0x2c),&DAT_40571a20,4,&local_28,0);
  SendMessageW(param_2,0x401,0x1001,local_24 & 2);
  SendMessageW(param_2,0x402,0x1041,local_1c & 4);
  SendMessageW(param_2,0x402,0x1042,local_14 & 4);
  SendMessageW(param_2,0x401,0x1061,local_c & 2);
  return;
}



/* 4057dbe8 FUN_4057dbe8 */

/* Boundary evidence: original MIPS .pdata 4057dbe8..4057dd97. Semantic name remains unreviewed. */

LRESULT FUN_4057dbe8(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  HWND pHVar1;
  LONG LVar2;
  DWORD color;
  size_t c;
  HGDIOBJ h;
  LRESULT LVar3;
  tagRECT local_280;
  tagPAINTSTRUCT local_270;
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  LVar3 = 0;
  pHVar1 = GetParent(param_1);
  pHVar1 = GetParent(pHVar1);
  LVar2 = GetWindowLongW(pHVar1,8);
  if (LVar2 != 0) {
    if (param_2 == 0xf) {
      h = (HGDIOBJ)0x0;
      BeginPaint(param_1,&local_270);
      if (local_270.hdc != (HDC)0x0) {
        if (*(HGDIOBJ *)(LVar2 + 0x68c) != (HGDIOBJ)0x0) {
          h = SelectObject(local_270.hdc,*(HGDIOBJ *)(LVar2 + 0x68c));
        }
        GetClientRect(param_1,&local_280);
        FillRect(local_270.hdc,&local_280,*(HBRUSH *)(LVar2 + 0x690));
        local_280.left = local_280.left + 3;
        local_280.top = local_280.top + 3;
        color = GetSysColor(0x40000012);
        SetTextColor(local_270.hdc,color);
        SetBkMode(local_270.hdc,1);
        GetWindowTextW(param_1,aWStack_230,0x104);
        c = wcslen(aWStack_230);
        ExtTextOutW(local_270.hdc,local_280.left,local_280.top,0,(RECT *)0x0,aWStack_230,c,
                    (INT *)0x0);
        if (h != (HGDIOBJ)0x0) {
          SelectObject(local_270.hdc,h);
        }
      }
      EndPaint(param_1,&local_270);
    }
    else {
      LVar3 = CallWindowProcW(*(WNDPROC *)(LVar2 + 0x664),param_1,param_2,param_3,param_4);
    }
  }
  FUN_405a7174(local_28);
  return LVar3;
}



/* 4057dd98 FUN_4057dd98 */

/* Boundary evidence: original MIPS .pdata 4057dd98..4057de4b. Semantic name remains unreviewed. */

void FUN_4057dd98(void)

{
  if (DAT_405a9a50 == 0) {
    DAT_405a9a54 = LoadStringW(DAT_405aa0c0,0x8102,(LPWSTR)0x0,0);
    DAT_405a9a58 = LoadStringW(DAT_405aa0c0,0xc004,(LPWSTR)0x0,0);
    DAT_405a9a5c = LoadStringW(DAT_405aa0c0,0x8103,(LPWSTR)0x0,0);
    DAT_405a9a60 = LoadStringW(DAT_405aa0c0,0x8104,(LPWSTR)0x0,0);
  }
  DAT_405a9a50 = DAT_405a9a50 + 1;
  return;
}



/* 4057de4c FUN_4057de4c */

/* Boundary evidence: original MIPS .pdata 4057de4c..4057df83. Semantic name remains unreviewed. */

undefined4 FUN_4057de4c(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = *param_2;
    if (((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
        ) || (((iVar2 == 0x214e2 && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    else {
      if (iVar2 != -0x48dd4335) {
        return 0x80004002;
      }
      if (param_2[1] != 0x101b4e68) {
        return 0x80004002;
      }
      if (param_2[2] != -0x55ff435e) {
        return 0x80004002;
      }
      if (param_2[3] != 0x70474000) {
        return 0x80004002;
      }
      iVar2 = param_1 + 4;
      if (param_1 == 0) {
        iVar2 = 0;
      }
      *param_3 = iVar2;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4057dfbc FUN_4057dfbc */

/* Boundary evidence: original MIPS .pdata 4057dfbc..4057e013. Semantic name remains unreviewed. */

undefined4 FUN_4057dfbc(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0x2d) {
      PostMessageW(*(HWND *)(param_1 + 0x654),0x10,0,0);
      uVar1 = 0;
    }
    else {
      uVar1 = 0x80040100;
    }
  }
  else {
    uVar1 = 0x80040104;
  }
  return uVar1;
}



/* 4057e014 FUN_4057e014 */

/* Boundary evidence: original MIPS .pdata 4057e014..4057e16f. Semantic name remains unreviewed. */

undefined4 FUN_4057e014(STRSAFE_LPCWSTR param_1,PCNZWCH param_2,int param_3)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  int iVar3;
  undefined4 uVar4;
  HKEY local_438;
  DWORD local_434 [3];
  wchar_t awStack_428 [7];
  undefined1 auStack_41a [498];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  uVar4 = 0;
  memcpy(awStack_428,L"CLSID\\",0xe);
  memset(auStack_41a,0,0x1f2);
  local_434[0] = 0;
  local_438 = (HKEY)0x0;
  HVar1 = StringCchCatW(awStack_428,0x100,param_1);
  if (-1 < HVar1) {
    LVar2 = RegOpenKeyExW((HKEY)0x80000000,awStack_428,0,0,&local_438);
    if (LVar2 == 0) {
      local_434[1] = 0x208;
      LVar2 = RegQueryValueExW(local_438,L"DisplayName",(LPDWORD)0x0,local_434,(LPBYTE)aWStack_228,
                               local_434 + 1);
      if (LVar2 == 0) {
        iVar3 = CompareStringW(0x400,0x20001,param_2,param_3,aWStack_228,-1);
        if (iVar3 == 2) {
          uVar4 = 1;
        }
      }
      RegCloseKey(local_438);
    }
  }
  FUN_405a7174(local_20);
  return uVar4;
}



/* 4057e170 FUN_4057e170 */

/* Boundary evidence: original MIPS .pdata 4057e170..4057e63f. Semantic name remains unreviewed. */

undefined4 FUN_4057e170(wchar_t *param_1,STRSAFE_LPWSTR param_2,uint *param_3)

{
  DWORD DVar1;
  PCNZWCH lpString2;
  size_t cchCount1;
  wchar_t *_Source;
  LSTATUS LVar2;
  int iVar3;
  undefined4 uVar4;
  uint cchDest;
  DWORD DVar5;
  uint uVar6;
  wchar_t *pwVar7;
  DWORD local_258;
  HKEY local_254;
  DWORD local_250;
  uint local_24c;
  DWORD local_248;
  wchar_t *local_244;
  PCNZWCH local_240;
  size_t local_23c;
  wchar_t *local_238;
  WCHAR aWStack_230 [256];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  local_248 = 0;
  if ((((param_1 != (wchar_t *)0x0) && (param_2 != (STRSAFE_LPWSTR)0x0)) && (param_3 != (uint *)0x0)
      ) && ((*param_1 != L'\\' &&
            (lpString2 = (PCNZWCH)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,0x208),
            local_240 = lpString2, lpString2 != (PCNZWCH)0x0)))) {
    cchDest = *param_3;
    local_258 = 0xffffffff;
    cchCount1 = wcslen(param_1);
    local_23c = cchCount1;
    _Source = wcschr(param_1,L'\\');
    if (_Source != (wchar_t *)0x0) {
      cchCount1 = (int)_Source - (int)param_1 >> 1;
    }
    local_254 = (HKEY)0x0;
    local_238 = _Source;
    LVar2 = RegOpenKeyExW((HKEY)0x80000001,
                          L"\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CurrentGUIDs",
                          0,0,&local_254);
    if (local_254 == (HKEY)0x0) {
LAB_4057e3bc:
      iVar3 = 0;
      if (LVar2 != 0) goto LAB_4057e3c4;
    }
    else {
      if (LVar2 == 0) {
        local_258 = 0x100;
        local_250 = 0x208;
        DVar5 = 0;
        LVar2 = RegEnumValueW(local_254,0,aWStack_230,&local_258,(LPDWORD)0x0,&local_248,
                              (LPBYTE)lpString2,&local_250);
        while (LVar2 == 0) {
          DVar5 = DVar5 + 1;
          iVar3 = wcscmp(aWStack_230,L"{000214A1-0000-0000-C000-000000000046}");
          if ((iVar3 != 0) &&
             (iVar3 = CompareStringW(0x400,0x20001,param_1,cchCount1,lpString2,-1), iVar3 == 2)) {
            cchDest = local_258 + 1;
            if (*param_3 <= local_258 + 1) {
              cchDest = *param_3;
            }
            LVar2 = StringCchCopyW(param_2,cchDest,aWStack_230);
            break;
          }
          local_258 = 0x100;
          local_250 = 0x208;
          LVar2 = RegEnumValueW(local_254,DVar5,aWStack_230,&local_258,(LPDWORD)0x0,&local_248,
                                (LPBYTE)lpString2,&local_250);
        }
        RegCloseKey(local_254);
        goto LAB_4057e3bc;
      }
LAB_4057e3c4:
      iVar3 = FUN_4057e014(L"{00021400-0000-0000-C000-000000000046}",param_1,cchCount1);
      if (iVar3 == 0) {
        local_244 = L"Explorer\\Desktop";
        local_24c = 0;
        do {
          pwVar7 = local_244;
          uVar6 = local_24c;
          local_254 = (HKEY)0x0;
          iVar3 = RegOpenKeyExW((HKEY)0x80000002,local_244,0,0,&local_254);
          if (local_254 == (HKEY)0x0) {
LAB_4057e574:
            _Source = local_238;
            lpString2 = local_240;
            if (iVar3 == 0) break;
          }
          else if (iVar3 == 0) {
            local_258 = 0x100;
            DVar5 = 0;
            iVar3 = RegEnumValueW(local_254,0,aWStack_230,&local_258,(LPDWORD)0x0,(LPDWORD)0x0,
                                  (LPBYTE)0x0,(LPDWORD)0x0);
            DVar1 = local_258;
            while (iVar3 == 0) {
              local_258 = DVar1;
              iVar3 = wcscmp(aWStack_230,L"{000214A1-0000-0000-C000-000000000046}");
              if ((iVar3 != 0) && (iVar3 = FUN_4057e014(aWStack_230,param_1,cchCount1), iVar3 != 0))
              {
                cchDest = DVar1 + 1;
                if (*param_3 <= DVar1 + 1) {
                  cchDest = *param_3;
                }
                iVar3 = StringCchCopyW(param_2,cchDest,aWStack_230);
                uVar6 = local_24c;
                break;
              }
              local_258 = 0x100;
              DVar5 = DVar5 + 1;
              iVar3 = RegEnumValueW(local_254,DVar5,aWStack_230,&local_258,(LPDWORD)0x0,(LPDWORD)0x0
                                    ,(LPBYTE)0x0,(LPDWORD)0x0);
              DVar1 = local_258;
              uVar6 = local_24c;
            }
            local_258 = DVar1;
            RegCloseKey(local_254);
            pwVar7 = local_244;
            goto LAB_4057e574;
          }
          local_24c = uVar6 + 0x32;
          local_244 = pwVar7 + 0x19;
          _Source = local_238;
          lpString2 = local_240;
        } while (local_24c < 100);
      }
      else {
        cchDest = *param_3;
        if (0x27 < cchDest) {
          cchDest = 0x27;
        }
        iVar3 = StringCchCopyW(param_2,cchDest,L"{00021400-0000-0000-C000-000000000046}");
      }
    }
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpString2);
    if (iVar3 == 0) {
      if ((_Source != (wchar_t *)0x0) && ((local_23c - cchCount1) + cchDest < *param_3)) {
        wcscat(param_2,_Source);
      }
      *param_3 = local_258 + 1;
      uVar4 = 1;
      goto LAB_4057e604;
    }
  }
  uVar4 = 0;
LAB_4057e604:
  FUN_405a7174(local_30);
  return uVar4;
}



/* 4057e654 FUN_4057e654 */

/* Boundary evidence: original MIPS .pdata 4057e654..4057e9ab. Semantic name remains unreviewed. */

undefined4 FUN_4057e654(int param_1)

{
  HDC hdc;
  HGDIOBJ h;
  int iVar1;
  size_t cchString;
  HRESULT HVar2;
  HWND hWnd;
  HWND hWnd_00;
  LONG LVar3;
  int iVar4;
  uint uVar5;
  wchar_t *_Str;
  STRSAFE_LPWSTR pszDest;
  undefined4 uVar6;
  undefined2 uVar7;
  LPSIZE lpSize;
  int local_48 [2];
  tagSIZE local_40;
  tagRECT local_38;
  
  uVar6 = 0;
  pszDest = (LPCWSTR)0x0;
  hdc = CreateCompatibleDC((HDC)0x0);
  h = SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x68c));
  GetWindowRect(*(HWND *)(param_1 + 0x658),&local_38);
  iVar1 = FUN_4057cb50(*(int *)(param_1 + 0x684),(int)*(short *)(param_1 + 0x688),
                       *(byte *)(param_1 + 0x654) >> 2 & 1);
  _Str = *(wchar_t **)(param_1 + 0x34);
  iVar1 = ((local_38.right - local_38.left) - iVar1) + -5;
  cchString = wcslen(_Str);
  lpSize = &local_40;
  uVar7 = 0;
  GetTextExtentExPointW(hdc,_Str,cchString,iVar1,local_48,(LPINT)0x0,lpSize);
  if (local_48[0] < (int)cchString) {
    pszDest = (STRSAFE_LPWSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(cchString + 1) * 2);
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      SetLastError(0xe);
      goto LAB_4057e954;
    }
    HVar2 = StringCchCopyW(pszDest,cchString + 1,*(STRSAFE_LPCWSTR *)(param_1 + 0x34));
    local_40.cx = iVar1;
    if (-1 < HVar2) {
      pszDest[local_48[0]] = L'\0';
      iVar1 = 1;
      do {
        if (local_48[0] < iVar1) break;
        iVar4 = local_48[0] - iVar1;
        iVar1 = iVar1 + 1;
        pszDest[iVar4] = L'.';
      } while (iVar1 < 4);
    }
  }
  hWnd = (HWND)CommandBar_Create(DAT_405aa0c0,*(undefined4 *)(param_1 + 0x658),0x2502);
  *(HWND *)(param_1 + 0x65c) = hWnd;
  hWnd_00 = (HWND)CommandBar_InsertControl
                            (hWnd,DAT_405aa0c0,L"STATIC",local_40.cx + 5,0,CONCAT22(uVar7,0x41a),
                             (uint)lpSize & 0xffff0000);
  *(HWND *)(param_1 + 0x660) = hWnd_00;
  LVar3 = SetWindowLongW(hWnd_00,-4,0x4057dbe8);
  *(LONG *)(param_1 + 0x664) = LVar3;
  if (pszDest == (LPCWSTR)0x0) {
    SetWindowTextW(*(HWND *)(param_1 + 0x660),*(LPCWSTR *)(param_1 + 0x34));
    SetWindowTextW(*(HWND *)(param_1 + 0x658),*(LPCWSTR *)(param_1 + 0x34));
  }
  else {
    SetWindowTextW(*(HWND *)(param_1 + 0x660),pszDest);
    SetWindowTextW(*(HWND *)(param_1 + 0x658),pszDest);
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,pszDest);
  }
  CommandBar_AddBitmap(hWnd,0xffffffff,4,0,0x10,0x10);
  SendMessageW(hWnd,0x444,(int)*(short *)(param_1 + 0x688),*(LPARAM *)(param_1 + 0x684));
  uVar5 = 0xb;
  if ((*(byte *)(param_1 + 0x654) & 4) == 0) {
    uVar5 = 0;
  }
  CommandBar_AddAdornments(hWnd,uVar5 | 0xf000,0);
  SendMessageW(hWnd,0x402,0x1041,1);
  if ((((DAT_405a9a54 != 0) && (DAT_405a9a58 != 0)) && (DAT_405a9a5c != 0)) && (DAT_405a9a60 != 0))
  {
    SendMessageW(hWnd,0x451,4,0x405a9a54);
  }
  uVar6 = 1;
  if (hWnd == (HWND)0x0) {
    uVar6 = 0;
  }
LAB_4057e954:
  if (h != (HGDIOBJ)0x0) {
    SelectObject(hdc,h);
  }
  if (hdc != (HDC)0x0) {
    DeleteDC(hdc);
  }
  return uVar6;
}



/* 4057e9ac FUN_4057e9ac */

/* Boundary evidence: original MIPS .pdata 4057e9ac..4057ec77. Semantic name remains unreviewed. */

undefined4 FUN_4057e9ac(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  short sVar1;
  int iVar2;
  HWND hWnd;
  LPWSTR lpString;
  WPARAM wParam;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *local_338;
  int local_334;
  STRRET local_330;
  WCHAR local_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  uVar3 = *(uint *)(param_3 + 8);
  uVar4 = 1;
  if (uVar3 == 0xffffff50) {
    *(byte *)(param_1 + 0x654) = *(byte *)(param_1 + 0x654) & 0xf7;
  }
  else {
    if (uVar3 != 0xffffff51) {
      if (uVar3 == 0xffffff65) {
        sVar1 = *(short *)(param_3 + 0xc);
        if (sVar1 == 8) {
          wParam = 0x1061;
        }
        else if (sVar1 == 0xd) {
LAB_4057ea54:
          wParam = 1;
        }
        else if (sVar1 == 0x2e) {
          wParam = 0x1002;
        }
        else if (sVar1 == 0x70) {
          wParam = 0x2503;
        }
        else {
          if (sVar1 != 0x74) goto LAB_4057ec20;
          wParam = 0x16;
        }
        PostMessageW(*(HWND *)(param_1 + 0x658),0x111,wParam,0);
      }
      else if (uVar3 == 0xffffff9b) {
        if (((*(byte *)(param_1 + 0x654) & 1) == 0) && ((*(uint *)(param_3 + 0x1c) & 8) != 0)) {
          if ((*(uint *)(param_3 + 0x14) & 2) == 0) {
            *(byte *)(param_1 + 0x654) = *(byte *)(param_1 + 0x654) & 0xdf;
          }
          else {
            local_338 = (undefined4 *)0x0;
            local_334 = 0;
            if ((*(uint *)(param_3 + 0x18) & 2) == 0) {
              iVar2 = (**(code **)(**(int **)(param_1 + 0x24) + 0x10))
                                (*(int **)(param_1 + 0x24),&local_338,&local_334);
              if (((-1 < iVar2) && (local_334 == 1)) &&
                 (iVar2 = FUN_4057d25c(param_1,(int *)0x0,(LPCITEMIDLIST)*local_338,
                                       (undefined4 *)0x0), iVar2 == 0)) {
                hWnd = GetDlgItem(*(HWND *)(param_1 + 0x658),0x2505);
                local_330.uType = 0;
                memset(&local_330.u,0,0x104);
                local_228[0] = L'\0';
                iVar2 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x2c))
                                  (*(int **)(param_1 + 0x1c),*local_338,0x4000,&local_330);
                if (-1 < iVar2) {
                  StrRetToBufW(&local_330,(LPCITEMIDLIST)*local_338,local_228,0x104);
                }
                lpString = PathFindFileNameW(local_228);
                SetWindowTextW(hWnd,lpString);
              }
              if (local_338 != (undefined4 *)0x0) {
                (**(code **)(*DAT_405aa0c8 + 0x14))();
              }
            }
            *(byte *)(param_1 + 0x654) = *(byte *)(param_1 + 0x654) | 0x20;
          }
        }
      }
      else {
        if ((uVar3 < 0xfffffffc) || (0xfffffffd < uVar3)) goto LAB_4057ec4c;
        if (*(int *)(param_3 + 0xc) != -1) goto LAB_4057ea54;
      }
LAB_4057ec20:
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0;
      }
      goto LAB_4057ec50;
    }
    *(byte *)(param_1 + 0x654) = *(byte *)(param_1 + 0x654) | 8;
  }
LAB_4057ec4c:
  uVar4 = 0;
LAB_4057ec50:
  FUN_405a7174(local_20);
  return uVar4;
}



/* 4057ec78 FUN_4057ec78 */

/* Boundary evidence: original MIPS .pdata 4057ec78..4057f74b. Semantic name remains unreviewed. */

undefined4 FUN_4057ec78(int *param_1)

{
  undefined1 *puVar1;
  HKEY pHVar2;
  HCURSOR hCursor;
  HWND hWnd;
  size_t sVar3;
  int iVar4;
  DWORD DVar5;
  LPWSTR pWVar6;
  DWORD DVar7;
  HRESULT HVar8;
  LSTATUS LVar9;
  BOOL BVar10;
  STRSAFE_LPCWSTR pwVar11;
  HWND hWnd_00;
  LRESULT LVar12;
  uint uVar13;
  STRSAFE_PCNZWCH pszSrc;
  wchar_t *pwVar14;
  wchar_t *pwVar15;
  uint uVar16;
  wchar_t *_Dest;
  LPCWSTR pWVar17;
  undefined4 uVar18;
  LPCITEMIDLIST local_560;
  uint local_55c;
  HKEY local_558;
  int local_554;
  HCURSOR local_550;
  STRRET local_548;
  undefined1 local_440 [4];
  wchar_t local_43c;
  undefined1 auStack_43a [514];
  WCHAR local_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  puVar1 = local_440 + 3;
  uVar13 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar13) =
       *(uint *)(puVar1 + -uVar13) & -1 << (uVar13 + 1) * 8 | 0x3a003aU >> (3 - uVar13) * 8;
  uVar18 = 0;
  _Dest = (wchar_t *)0x0;
  local_440 = (undefined1  [4])0x3a003a;
  local_43c = L'\0';
  memset(auStack_43a,0,0x202);
  pWVar17 = (LPCWSTR)0x0;
  hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
  local_550 = SetCursor(hCursor);
  hWnd = GetDlgItem((HWND)param_1[0x196],0x2505);
  if ((wchar_t *)param_1[0xe] != (wchar_t *)0x0) {
    sVar3 = wcslen((wchar_t *)param_1[0xe]);
    _Dest = (wchar_t *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar3 + 1) * 2);
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,(wchar_t *)param_1[0xe]);
    }
  }
  FUN_4057d918((int)param_1);
  if ((*(byte *)(param_1 + 0x195) & 0x20) == 0) {
    GetWindowTextW(hWnd,local_238,0x104);
    if (local_238[0] == L'\0') goto LAB_4057f6c0;
    local_55c = 0x102;
    iVar4 = FUN_4057e170(local_238,&local_43c,&local_55c);
    if (iVar4 != 0) {
      local_560 = (LPCITEMIDLIST)0x0;
      HVar8 = FUN_4057d490(param_1,(STRSAFE_LPCWSTR)local_440);
      if (-1 < HVar8) goto LAB_4057f6c0;
      iVar4 = (**(code **)(*(int *)param_1[6] + 0xc))
                        ((int *)param_1[6],0,0,local_440,0,&local_560,0);
      if (-1 < iVar4) {
        SHGetPathFromIDList(local_560,local_238);
        FUN_40580ef4(local_560);
      }
    }
    PathRemoveBlanksW(local_238);
    pwVar15 = wcspbrk(local_238,L"/:\"<>|");
    if (pwVar15 == (wchar_t *)0x0) {
      pwVar15 = wcspbrk(local_238,L"*?");
      if ((pwVar15 != (wchar_t *)0x0) &&
         (pwVar15 = wcschr(local_238,L'\\'), pwVar15 == (wchar_t *)0x0)) {
        if ((param_1[10] != 0) && (param_1[0xb] != 0)) {
          HVar8 = StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x91),0x104,local_238);
          if (-1 < HVar8) {
            (**(code **)(*(int *)param_1[10] + 0xc))((int *)param_1[10],param_1 + 0x91);
            *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) | 1;
            (**(code **)(*(int *)param_1[0xb] + 0x10))((int *)param_1[0xb],0,0x16,0,0,0);
            *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) & 0xfe;
          }
        }
        goto LAB_4057f6c0;
      }
      iVar4 = FUN_4057d6a4(param_1,(wchar_t *)(param_1 + 0x113),(wchar_t *)local_440,local_238);
      if (iVar4 != 0) goto LAB_4057f09c;
      goto LAB_4057f6a0;
    }
    pwVar15 = (wchar_t *)0x8107;
    pWVar17 = local_238;
  }
  else {
    local_560 = (LPCITEMIDLIST)0x0;
    local_554 = 0;
    local_440 = (undefined1  [4])((uint)local_440 & 0xffff0000);
    iVar4 = (**(code **)(*(int *)param_1[9] + 0x10))((int *)param_1[9],&local_560,&local_554);
    if ((-1 < iVar4) && (local_554 == 1)) {
      local_558 = (HKEY)0x0;
      iVar4 = FUN_4057d25c((int)param_1,(int *)0x0,*(LPCITEMIDLIST *)local_560,&local_558);
      pHVar2 = local_558;
      if (iVar4 == 0) {
        local_548.uType = 0;
        memset(&local_548.u,0,0x104);
        iVar4 = (**(code **)(*(int *)param_1[7] + 0x2c))
                          ((int *)param_1[7],*(undefined4 *)local_560,0x8000,&local_548);
        if ((-1 < iVar4) &&
           (HVar8 = StrRetToBufW(&local_548,*(LPCITEMIDLIST *)local_560,local_238,0x104), -1 < HVar8
           )) {
          pwVar15 = L"%s\\%s";
          iVar4 = wcscmp((wchar_t *)(param_1 + 0x113),L"\\");
          if (iVar4 == 0) {
            pwVar15 = L"%s%s";
          }
          pWVar6 = PathFindFileNameW(local_238);
          StringCchPrintfW((STRSAFE_LPWSTR)local_440,0x104,pwVar15,param_1 + 0x113,pWVar6);
        }
      }
      else if (local_558 == (HKEY)0x0) {
        (**(code **)(*param_1 + 0x2c))(param_1,*(undefined4 *)local_560,0x1001);
      }
      else {
        (**(code **)(*param_1 + 0x2c))(param_1,local_558,1);
        FUN_40580ef4(pHVar2);
      }
    }
    if (local_560 != (LPCITEMIDLIST)0x0) {
      (**(code **)(*DAT_405aa0c8 + 0x14))();
    }
    if (local_440._0_2_ == L'\0') goto LAB_4057f6c0;
LAB_4057f09c:
    DVar5 = GetFileAttributesW((LPCWSTR)local_440);
    pWVar6 = PathFindExtensionW((LPCWSTR)local_440);
    iVar4 = PathIsLink(local_440);
    if (((iVar4 != 0) && ((*(uint *)(param_1[0xc] + 0x34) & 0x100000) == 0)) &&
       (iVar4 = SHGetShortcutTarget((LPCWSTR)local_440,local_238,0x104), iVar4 != 0)) {
      PathRemoveQuotesAndArgs(local_238);
      DVar7 = GetFileAttributesW(local_238);
      if (DVar7 != 0xffffffff) {
        StringCchCopyW((STRSAFE_LPWSTR)local_440,0x104,local_238);
        pWVar6 = PathFindExtensionW((LPCWSTR)local_440);
        DVar5 = DVar7;
        if ((DVar7 & 0x10) != 0) {
          SetWindowTextW(hWnd,(LPCWSTR)0x0);
        }
      }
    }
    if (DVar5 == 0xffffffff) {
      if ((wchar_t *)param_1[0xe] == (wchar_t *)0x0) {
LAB_4057f268:
        if ((*(uint *)(param_1[0xc] + 0x34) & 0x800) == 0) {
LAB_4057f3d4:
          if ((*(uint *)(param_1[0xc] + 0x34) & 0x1000) == 0) {
            if (((*(uint *)(param_1[0xc] + 0x34) & 0x2000) != 0) &&
               ((*(byte *)(param_1 + 0x195) & 2) == 0)) {
              pwVar11 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x8105,(LPWSTR)0x0,0);
              StringCchPrintfExW(local_238,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar11,
                                 local_440);
              goto LAB_4057f478;
            }
            goto LAB_4057f498;
          }
          pwVar15 = (wchar_t *)0x8106;
          pwVar14 = (wchar_t *)local_440;
        }
        else {
          HVar8 = StringCchCopyW(local_238,0x104,(STRSAFE_LPCWSTR)local_440);
          if (-1 < HVar8) {
            PathRemoveFileSpecW(local_238);
          }
          BVar10 = PathFileExistsW(local_238);
          if (BVar10 != 0) goto LAB_4057f3d4;
          GetWindowTextW(hWnd,local_238,0x104);
          pwVar15 = (wchar_t *)0x8108;
          pwVar14 = local_238;
        }
        FUN_40588be0((HWND)param_1[0x196],(LPCWSTR)param_1[0xd],pwVar15,pwVar14,0x30);
        goto LAB_4057f6c0;
      }
      if (*pWVar6 != L'\0') {
        iVar4 = _wcsicmp((wchar_t *)param_1[0xe],pWVar6 + 1);
        if (iVar4 != 0) {
          LVar9 = RegOpenKeyExW((HKEY)0x80000000,pWVar6,0,0,&local_558);
          if (LVar9 != 0) goto LAB_4057f2d0;
          RegCloseKey(local_558);
        }
        goto LAB_4057f268;
      }
LAB_4057f2d0:
      iVar4 = wcscmp((wchar_t *)(param_1 + 0x91),L"*.*");
      if ((iVar4 == 0) && (*pWVar6 != L'\0')) {
LAB_4057f340:
        DVar5 = GetFileAttributesW((LPCWSTR)local_440);
        if (DVar5 != 0xffffffff) goto LAB_4057f360;
        goto LAB_4057f268;
      }
      HVar8 = StringCchLengthW((STRSAFE_PCNZWCH)local_440,0x104,&local_55c);
      if (-1 < HVar8) {
        pszSrc = (STRSAFE_PCNZWCH)param_1[0xe];
        *(undefined2 *)(local_440 + local_55c * 2) = 0x2e;
        HVar8 = StringCchCopyNW((STRSAFE_LPWSTR)(local_440 + local_55c * 2 + 2),0x103 - local_55c,
                                pszSrc,3);
        if (-1 < HVar8) goto LAB_4057f340;
      }
    }
    else {
      if ((DVar5 & 0x10) != 0) {
        *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) | 1;
        HVar8 = FUN_4057d490(param_1,(STRSAFE_LPCWSTR)local_440);
        *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) & 0xfe;
        if (-1 < HVar8) {
          GetWindowTextW(hWnd,*(LPWSTR *)(param_1[0xc] + 0x1c),*(int *)(param_1[0xc] + 0x20));
          PathRemoveTrailingSlashes(*(undefined4 *)(param_1[0xc] + 0x1c));
          pWVar6 = PathFindFileNameW(*(LPCWSTR *)(param_1[0xc] + 0x1c));
          SetWindowTextW(hWnd,pWVar6);
          goto LAB_4057f6c0;
        }
      }
LAB_4057f360:
      if (((*(byte *)(param_1 + 0x195) & 2) != 0) && ((*(uint *)(param_1[0xc] + 0x34) & 2) != 0)) {
        pwVar11 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x810a,(LPWSTR)0x0,0);
        StringCchPrintfExW(local_238,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar11,
                           local_440);
LAB_4057f478:
        iVar4 = MessageBoxW((HWND)param_1[0x196],local_238,(LPCWSTR)param_1[0xd],0x34);
        if (iVar4 != 6) goto LAB_4057f6c0;
      }
LAB_4057f498:
      HVar8 = StringCchLengthW((STRSAFE_PCNZWCH)local_440,0x104,&local_55c);
      if (-1 < HVar8) {
        uVar13 = *(uint *)(param_1[0xc] + 0x20);
        if ((local_55c < uVar13) &&
           (HVar8 = StringCchCopyW(*(STRSAFE_LPWSTR *)(param_1[0xc] + 0x1c),uVar13,
                                   (STRSAFE_LPCWSTR)local_440), -1 < HVar8)) {
          pWVar6 = PathFindExtensionW((LPCWSTR)local_440);
          if ((*pWVar6 != L'\0') &&
             ((_Dest != (wchar_t *)0x0 && (iVar4 = _wcsicmp(pWVar6 + 1,_Dest), iVar4 != 0)))) {
            *(uint *)(param_1[0xc] + 0x34) = *(uint *)(param_1[0xc] + 0x34) | 0x400;
          }
          if (*pWVar6 == L'.') {
            if (pWVar6[1] == L'\0') {
              iVar4 = param_1[0xc];
              *(undefined1 *)(iVar4 + 0x3a) = 0;
              *(undefined1 *)(iVar4 + 0x3b) = 0;
            }
            else {
              iVar4 = param_1[0xc];
              uVar13 = (int)(pWVar6 + 1) - (int)local_440 >> 1 & 0xffff;
              *(char *)(iVar4 + 0x3a) = (char)uVar13;
              *(char *)(iVar4 + 0x3b) = (char)(uVar13 >> 8);
            }
          }
          else {
            iVar4 = param_1[0xc];
            uVar13 = (int)pWVar6 - (int)local_440 >> 1 & 0xffff;
            *(char *)(iVar4 + 0x3a) = (char)uVar13;
            *(char *)(iVar4 + 0x3b) = (char)(uVar13 >> 8);
          }
          pWVar6 = PathFindFileNameW((LPCWSTR)local_440);
          iVar4 = param_1[0xc];
          uVar16 = (int)pWVar6 - (int)local_440 >> 1;
          uVar13 = uVar16 & 0xffff;
          *(char *)(iVar4 + 0x38) = (char)uVar13;
          *(char *)(iVar4 + 0x39) = (char)(uVar13 >> 8);
          if ((*(int *)(param_1[0xc] + 0x24) == 0) || (*(int *)(param_1[0xc] + 0x28) == 0)) {
LAB_4057f65c:
            hWnd_00 = GetDlgItem((HWND)param_1[0x196],0x2507);
            LVar12 = SendMessageW(hWnd_00,0x147,0,0);
            *(LRESULT *)(param_1[0xc] + 0x18) = LVar12 + 1;
            *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) | 0x10;
            uVar18 = 1;
            goto LAB_4057f6c0;
          }
          HVar8 = StringCchLengthW(pWVar6,0x104 - uVar16,&local_55c);
          if (-1 < HVar8) {
            uVar13 = *(uint *)(param_1[0xc] + 0x28);
            if ((local_55c < uVar13) &&
               (HVar8 = StringCchCopyW(*(STRSAFE_LPWSTR *)(param_1[0xc] + 0x24),uVar13,pWVar6),
               -1 < HVar8)) goto LAB_4057f65c;
          }
        }
      }
    }
LAB_4057f6a0:
    pwVar15 = (wchar_t *)0x8109;
  }
  FUN_4058a544((HWND)param_1[0x196],(LPCWSTR)param_1[0xd],pwVar15,pWVar17,0x30);
LAB_4057f6c0:
  SetCursor(local_550);
  if (_Dest != (wchar_t *)0x0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,_Dest);
  }
  *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) & 0xdf;
  SendMessageW(hWnd,0xb1,0,-1);
  SetFocus(hWnd);
  FUN_405a7174(local_30);
  return uVar18;
}



/* 4057f74c FUN_4057f74c */

/* Boundary evidence: original MIPS .pdata 4057f74c..4057f97b. Semantic name remains unreviewed. */

BOOL FUN_4057f74c(int *param_1,HWND param_2)

{
  BOOL BVar1;
  HWND pHVar2;
  LPWSTR lpString;
  HRESULT HVar3;
  HWND hWnd;
  STRSAFE_LPCWSTR pwVar4;
  BOOL BVar5;
  tagWNDCLASSW tStack_40;
  
  BVar5 = 0;
  FUN_405a6d64();
  BVar1 = GetClassInfoW(DAT_405aa0c0,L"SIPPREF",&tStack_40);
  if (BVar1 != 0) {
    CreateWindowExW(0,L"SIPPREF",(LPCWSTR)0x0,0x40000000,-10,-10,5,5,param_2,(HMENU)0x0,DAT_405aa0c0
                    ,(LPVOID)0x0);
  }
  FUN_405a6ca0(param_2,2);
  param_1[0x196] = (int)param_2;
  pHVar2 = GetDlgItem(param_2,0x2504);
  param_1[0x19e] = (int)pHVar2;
  GetWindowRect(pHVar2,(LPRECT)(param_1 + 0x19a));
  MapWindowPoints((HWND)0x0,param_2,(LPPOINT)(param_1 + 0x19a),2);
  param_1[0x19b] = param_1[0x19b] + 0x14;
  DestroyWindow((HWND)param_1[0x19e]);
  param_1[0x19e] = 0;
  *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) & 0xd6 | 1;
  FUN_4057e654((int)param_1);
  FUN_4057cf50((int)param_1);
  pHVar2 = GetDlgItem((HWND)param_1[0x196],0x2505);
  lpString = PathFindFileNameW(*(LPCWSTR *)(param_1[0xc] + 0x1c));
  SetWindowTextW(pHVar2,lpString);
  *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) & 0xfe;
  if ((*(LPCWSTR *)(param_1[0xc] + 0x2c) == (LPCWSTR)0x0) ||
     (BVar1 = PathIsDirectoryW(*(LPCWSTR *)(param_1[0xc] + 0x2c)), BVar1 == 0)) {
    pwVar4 = L"\\";
  }
  else {
    pwVar4 = *(STRSAFE_LPCWSTR *)(param_1[0xc] + 0x2c);
  }
  HVar3 = FUN_4057d490(param_1,pwVar4);
  if (HVar3 < 0) {
    SetWindowLongW((HWND)param_1[0x198],-4,param_1[0x199]);
    BVar5 = EndDialog(param_2,2);
  }
  else {
    hWnd = GetDlgItem(param_2,0x2505);
    SendMessageW(hWnd,0xc5,0x103,0);
    FUN_4057c9dc((int)param_1,param_2,1);
    SendMessageW(pHVar2,0xb1,0,-1);
    SetFocus(pHVar2);
  }
  return BVar5;
}



/* 4057f97c FUN_4057f97c */

/* Boundary evidence: original MIPS .pdata 4057f97c..4057fa87. Semantic name remains unreviewed. */

LRESULT FUN_4057f97c(HWND param_1,UINT param_2,uint param_3,int param_4)

{
  HWND hWnd;
  LONG LVar1;
  int iVar2;
  LRESULT LVar3;
  uint uVar4;
  LRESULT local_28 [2];
  
  local_28[0] = 0;
  hWnd = GetParent(param_1);
  LVar1 = GetWindowLongW(hWnd,8);
  LVar3 = 0;
  if ((((LVar1 != 0) &&
       (((param_2 != 0x4e ||
         (iVar2 = FUN_4057e9ac(LVar1,param_3,param_4,local_28), LVar3 = local_28[0], iVar2 == 0)) &&
        (LVar3 = CallWindowProcW(*(WNDPROC *)(LVar1 + 0x67c),param_1,param_2,param_3,param_4),
        param_2 == 0x111)))) && (uVar4 = param_3 & 0xffff, 0x103f < uVar4)) &&
     ((uVar4 < 0x1043 || (uVar4 == 0x104a)))) {
    FUN_4057db14(LVar1,*(HWND *)(LVar1 + 0x65c));
  }
  return LVar3;
}



/* 4057fa88 FUN_4057fa88 */

/* Boundary evidence: original MIPS .pdata 4057fa88..4057facb. Semantic name remains unreviewed. */

int FUN_4057fa88(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2] + -1;
  param_1[2] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_405715d8;
    param_1[1] = &PTR_LAB_405715c4;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 4057fae0 FUN_4057fae0 */

/* Boundary evidence: original MIPS .pdata 4057fae0..4057fcab. Semantic name remains unreviewed. */

void FUN_4057fae0(int param_1)

{
  undefined1 *puVar1;
  uint *puVar2;
  int iVar3;
  LPCITEMIDLIST pIVar4;
  HRESULT HVar5;
  ushort *puVar6;
  uint uVar7;
  LONG LVar8;
  int *local_130 [2];
  tagRECT tStack_128;
  STRRET SStack_118;
  
  puVar1 = (undefined1 *)((int)&SStack_118.uType + 3);
  uVar7 = (uint)puVar1 & 3;
  puVar2 = (uint *)(puVar1 + -uVar7);
  *puVar2 = *puVar2 & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
  local_130[0] = (int *)0x0;
  SStack_118.uType = 0;
  memset(&SStack_118.u,0,0x104);
  iVar3 = FUN_40580fe8(*(char **)(param_1 + 0x14));
  if ((iVar3 == 0) && (iVar3 = FUN_4058150c(*(ushort **)(param_1 + 0x14),&DAT_405719c0), iVar3 == 0)
     ) {
    SHGetPathFromIDList(*(LPCITEMIDLIST *)(param_1 + 0x14),(wchar_t *)(param_1 + 0x44c));
  }
  else {
    SHGetSpecialFolderPath(0,param_1 + 0x44c,0x10,1);
  }
  pIVar4 = FUN_405813a0(*(ushort **)(param_1 + 0x14),-1);
  FUN_40581780((ushort *)pIVar4);
  HVar5 = FUN_40574920(*(IShellFolder **)(param_1 + 0x18),(IID *)&DAT_40572b68,pIVar4,local_130);
  if (-1 < HVar5) {
    iVar3 = *local_130[0];
    puVar6 = FUN_40581470(*(ushort **)(param_1 + 0x14));
    iVar3 = (**(code **)(iVar3 + 0x2c))(local_130[0],puVar6,0x4000,&SStack_118);
    if (-1 < iVar3) {
      StrRetToBufW(&SStack_118,*(LPCITEMIDLIST *)(param_1 + 0x14),(LPWSTR)(param_1 + 0x3c),0x104);
    }
    (**(code **)(*local_130[0] + 8))();
  }
  if (pIVar4 != (LPCITEMIDLIST)0x0) {
    FUN_40580ef4(pIVar4);
  }
  FUN_4057db14(param_1,*(HWND *)(param_1 + 0x65c));
  GetClientRect(*(HWND *)(param_1 + 0x658),&tStack_128);
  iVar3 = CommandBar_Height(*(undefined4 *)(param_1 + 0x65c));
  tStack_128.top = iVar3 + tStack_128.top;
  FUN_4057ccec(param_1,(HDC)0x0,&tStack_128);
  uVar7 = GetWindowLongW(*(HWND *)(param_1 + 0x678),-0x10);
  SetWindowLongW(*(HWND *)(param_1 + 0x678),-0x10,uVar7 | 0x810000);
  LVar8 = SetWindowLongW(*(HWND *)(param_1 + 0x678),-4,0x4057f97c);
  *(LONG *)(param_1 + 0x67c) = LVar8;
  (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))(*(int **)(param_1 + 0x20),1);
  return;
}



/* 4057fcac FUN_4057fcac */

/* Boundary evidence: original MIPS .pdata 4057fcac..40580087. Semantic name remains unreviewed. */

BOOL FUN_4057fcac(int *param_1,uint param_2,HWND param_3)

{
  int iVar1;
  LRESULT LVar2;
  WPARAM wParam;
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar3;
  HWND hWnd;
  int *piVar4;
  undefined4 *puVar5;
  wchar_t *lpCommandLine;
  uint nResult;
  BOOL BVar6;
  
  nResult = param_2 & 0xffff;
  BVar6 = 0;
  puVar5 = (undefined4 *)0x0;
  if (nResult < 0x1048) {
    if (nResult < 0x1044) {
      if (nResult == 1) {
        LVar2 = SendDlgItemMessageW((HWND)param_1[0x196],0x2507,0x157,0,0);
        if (LVar2 != 0) {
          SendDlgItemMessageW((HWND)param_1[0x196],0x2507,0x100,0xd,0);
          return 0;
        }
        if (param_2 >> 0x10 != 0) {
          return 0;
        }
        if ((*(byte *)(param_1 + 0x195) & 8) != 0) {
          FUN_4057ec78(param_1);
          return 0;
        }
        iVar1 = FUN_4057ec78(param_1);
        if (iVar1 == 0) {
          return 0;
        }
LAB_4057fe88:
        BVar6 = EndDialog((HWND)param_1[0x196],nResult);
        return BVar6;
      }
      if (nResult == 2) {
        if (param_3 != (HWND)0x0) {
          return 0;
        }
        if (((*(byte *)(param_1 + 0x195) & 8) != 0) &&
           (piVar4 = (int *)param_1[0xb], piVar4 != (int *)0x0)) {
          (**(code **)(*piVar4 + 0x10))(piVar4,&DAT_40571a20,0x1050,0,0,0);
        }
        goto LAB_4057fe88;
      }
      if (nResult == 0x16) goto LAB_4057fd58;
      if (nResult < 0x1001) {
        return 0;
      }
      if (0x1004 < nResult) {
        if (nResult < 0x1040) {
          return 0;
        }
        if (0x1042 < nResult) {
          return 0;
        }
      }
    }
  }
  else if (nResult != 0x104a) {
    if (nResult == 0x1061) {
      (**(code **)(*param_1 + 0x2c))(param_1,0,0x2001);
      return 0;
    }
    if (nResult == 0x2503) {
      if ((*(byte *)(param_1 + 0x195) & 4) == 0) {
        return 0;
      }
      if ((*(byte *)(param_1 + 0x195) & 2) == 0) {
        lpCommandLine = L"file:wince.htm#Open_dialog_box";
      }
      else {
        lpCommandLine = L"file:wince.htm#Save_As_dialog_box";
      }
      CreateProcessW(L"peghelp",lpCommandLine,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,
                     0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
      return 0;
    }
    if (nResult == 0x2505) {
      if (param_2 >> 0x10 != 0x300) {
        return 0;
      }
      *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) & 0xdf;
      return 0;
    }
    if (nResult != 0x2507) {
      return 0;
    }
    if (param_2 >> 0x10 != 8) {
      return 0;
    }
    wParam = SendMessageW(param_3,0x147,0,0);
    if (param_1[0xb] == 0) {
      return 0;
    }
    if (wParam + 1 == *(int *)(param_1[0xc] + 0x18)) {
      return 0;
    }
    pszSrc = (STRSAFE_LPCWSTR)SendMessageW(param_3,0x150,wParam,0);
    HVar3 = StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x91),0x104,pszSrc);
    if (HVar3 < 0) {
      return 0;
    }
    UpdateWindow((HWND)param_1[0x196]);
    hWnd = GetParent((HWND)param_1[0x196]);
    UpdateWindow(hWnd);
    *(WPARAM *)(param_1[0xc] + 0x18) = wParam + 1;
    (**(code **)(*(int *)param_1[10] + 0xc))((int *)param_1[10],param_1 + 0x91);
    *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) | 1;
    (**(code **)(*(int *)param_1[0xb] + 0x10))((int *)param_1[0xb],0,0x16,0,0,0);
    *(byte *)(param_1 + 0x195) = *(byte *)(param_1 + 0x195) & 0xfe;
    FUN_4057d61c((int)param_1);
    return 0;
  }
  puVar5 = &DAT_40571a20;
LAB_4057fd58:
  piVar4 = (int *)param_1[0xb];
  if (piVar4 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar4 + 0x10))(piVar4,puVar5,nResult,0,0,0);
    BVar6 = 1;
    if (iVar1 < 0) {
      BVar6 = 0;
    }
  }
  return BVar6;
}



/* 40580088 FUN_40580088 */

/* Boundary evidence: original MIPS .pdata 40580088..4058047b. Semantic name remains unreviewed. */

BOOL FUN_40580088(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  int *piVar1;
  int iVar2;
  HWND pHVar3;
  HRESULT HVar4;
  DWORD color;
  BOOL BVar5;
  HDC local_248 [2];
  tagRECT tStack_240;
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  BVar5 = 0;
  piVar1 = (int *)GetWindowLongW(param_1,8);
  if ((piVar1 == (int *)0x0) && (param_2 != 0x110)) goto LAB_40580414;
  if (param_2 < 0x112) {
    if (param_2 == 0x111) {
      BVar5 = FUN_4057fcac(piVar1,(uint)param_3,param_4);
      goto LAB_40580414;
    }
    if (param_2 == 2) {
      SetWindowLongW((HWND)piVar1[0x198],-4,piVar1[0x199]);
      FUN_4057cbc8((int)piVar1);
      SetWindowLongW(param_1,8,0);
      goto LAB_40580414;
    }
    if (param_2 == 0x14) {
      GetClientRect((HWND)piVar1[0x196],&tStack_240);
      iVar2 = CommandBar_Height(piVar1[0x197]);
      tStack_240.top = iVar2 + tStack_240.top;
      FUN_4057ccec((int)piVar1,param_3,&tStack_240);
    }
    else {
      if (param_2 == 0x1a) {
        if (param_3 == (HDC)0xe0) {
          FUN_4057c9dc((int)piVar1,param_1,0);
        }
        goto LAB_40580414;
      }
      if (param_2 != 0x53) {
        if (param_2 == 0x110) {
          SetWindowLongW(param_1,8,(LONG)param_4);
          BVar5 = FUN_4057f74c(&param_4->unused,param_1);
        }
        goto LAB_40580414;
      }
      FUN_4057fcac(piVar1,0x2503,(HWND)0x0);
    }
  }
  else {
    if (param_2 == 0x138) {
      color = GetSysColor(0x40000012);
      SetTextColor(param_3,color);
      SetBkMode(param_3,1);
      FUN_405a7174(local_28);
      return piVar1[0x1a4];
    }
    if (param_2 == 0x464) {
      pHVar3 = GetDlgItem((HWND)piVar1[0x196],0x2505);
      local_248[0] = (HDC)GetWindowTextW(pHVar3,aWStack_230,0x104);
      if ((param_4 != (HWND)0x0) && (local_248[0] < param_3)) {
        StringCchCopyW((STRSAFE_LPWSTR)param_4,(size_t)param_3,aWStack_230);
      }
    }
    else {
      if (param_2 != 0x466) {
        if (param_2 == 0x468) {
          if ((param_3 == (HDC)0x480) && (param_4 != (HWND)0x0)) {
            pHVar3 = GetDlgItem(param_1,0x2505);
            SetWindowTextW(pHVar3,(LPCWSTR)param_4);
            pHVar3 = GetDlgItem(param_1,0x2505);
            UpdateWindow(pHVar3);
          }
        }
        else if (param_2 == 0x46a) {
          if (param_4 == (HWND)0x0) {
            if (piVar1[0xe] != 0) {
              (**(code **)(*DAT_405aa0c8 + 0x14))();
              piVar1[0xe] = 0;
            }
          }
          else {
            local_248[0] = (HDC)wcslen((wchar_t *)param_4);
            if (piVar1[0xe] == 0) {
              iVar2 = (**(code **)(*DAT_405aa0c8 + 0xc))
                                (DAT_405aa0c8,(int)((int)&local_248[0]->unused + 1) * 2);
              piVar1[0xe] = iVar2;
            }
            else {
              iVar2 = (**(code **)(*DAT_405aa0c8 + 0x10))
                                (DAT_405aa0c8,piVar1[0xe],(int)((int)&local_248[0]->unused + 1) * 2)
              ;
              if (iVar2 == 0) {
                (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,piVar1[0xe]);
              }
              piVar1[0xe] = iVar2;
            }
            if ((wchar_t *)piVar1[0xe] != (wchar_t *)0x0) {
              wcscpy((wchar_t *)piVar1[0xe],(wchar_t *)param_4);
            }
          }
        }
        goto LAB_40580414;
      }
      local_248[0] = (HDC)0x0;
      HVar4 = StringCchLengthW((STRSAFE_PCNZWCH)(piVar1 + 0x113),0x104,(size_t *)local_248);
      if ((-1 < HVar4) && (local_248[0] < param_3)) {
        StringCchCopyW((STRSAFE_LPWSTR)param_4,(size_t)param_3,(STRSAFE_LPCWSTR)(piVar1 + 0x113));
      }
    }
    SetWindowLongW(param_1,0,(LONG)((int)&local_248[0]->unused + 1));
  }
  BVar5 = 1;
LAB_40580414:
  FUN_405a7174(local_28);
  return BVar5;
}



/* 4058047c FUN_4058047c */

/* Boundary evidence: original MIPS .pdata 4058047c..4058084f. Semantic name remains unreviewed. */

HRESULT FUN_4058047c(int param_1,ushort *param_2,uint param_3)

{
  HCURSOR pHVar1;
  LPCITEMIDLIST pIVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  HRESULT HVar7;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int local_30;
  int *local_2c;
  int local_28 [4];
  
  local_34 = (int *)0x0;
  local_40 = (int *)0x0;
  local_2c = (int *)0x0;
  HVar7 = -0x7fffbffb;
  local_38 = (int *)0x0;
  local_3c = (int *)0x0;
  local_30 = 0;
  pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
  pHVar1 = SetCursor(pHVar1);
  if ((param_2 == (ushort *)0x0) && ((param_3 & 0x2000) == 0)) {
    HVar7 = -0x7ff8ffa9;
    goto LAB_40580824;
  }
  uVar6 = param_3 & 0x3000;
  if (uVar6 == 0) {
    pIVar2 = FUN_405813a0(param_2,-1);
  }
  else if (uVar6 == 0x1000) {
    if (*(ushort **)(param_1 + 0x14) == (ushort *)0x0) goto LAB_40580824;
    pIVar2 = FUN_405812ec(*(ushort **)(param_1 + 0x14),param_2);
  }
  else {
    if ((uVar6 != 0x2000) || (*(ushort **)(param_1 + 0x14) == (ushort *)0x0)) goto LAB_40580824;
    pIVar2 = FUN_405813a0(*(ushort **)(param_1 + 0x14),-1);
    FUN_40581780((ushort *)pIVar2);
  }
  if (pIVar2 != (LPCITEMIDLIST)0x0) {
    HVar7 = FUN_40574920(*(IShellFolder **)(param_1 + 0x18),(IID *)&DAT_40572b68,pIVar2,&local_34);
    if ((((-1 < HVar7) &&
         (HVar7 = (**(code **)(*local_34 + 0x20))
                            (local_34,*(undefined4 *)(param_1 + 0x658),&DAT_40572ba8,&local_40),
         -1 < HVar7)) &&
        (HVar7 = (**(code **)*local_40)(local_40,&DAT_40572b78,&local_2c), -1 < HVar7)) &&
       ((HVar7 = (**(code **)*local_40)(local_40,&DAT_405719f0,&local_38), -1 < HVar7 &&
        (iVar3 = (**(code **)*local_40)(local_40,&DAT_40572b98,&local_3c), -1 < iVar3)))) {
      (**(code **)(*local_38 + 0xc))(local_38,param_1 + 0x244);
      iVar3 = 0;
      do {
        local_28[iVar3] = (int)*(short *)(iVar3 * 2 + *(int *)(param_1 + 0x680));
        if (iVar3 == 1) {
          iVar4 = GetSystemMetrics(2);
          local_28[1] = local_28[1] - iVar4;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      (**(code **)(*local_3c + 0x14))(local_3c,local_28,4);
      (**(code **)(*local_3c + 0xc))(local_3c,0);
      piVar5 = *(int **)(param_1 + 0x20);
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x2c))(piVar5,param_1 + 0xc);
      }
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x41;
      HVar7 = (**(code **)(*local_40 + 0x24))
                        (local_40,*(undefined4 *)(param_1 + 0x20),param_1 + 0xc,param_1,
                         param_1 + 0x668,&local_30);
      if ((-1 < HVar7) && (local_30 != 0)) {
        FUN_4057cbc8(param_1);
        *(int *)(param_1 + 0x678) = local_30;
        *(LPCITEMIDLIST *)(param_1 + 0x14) = pIVar2;
        *(int **)(param_1 + 0x1c) = local_34;
        *(int **)(param_1 + 0x20) = local_40;
        *(int **)(param_1 + 0x24) = local_3c;
        *(int **)(param_1 + 0x28) = local_38;
        *(int **)(param_1 + 0x2c) = local_2c;
        FUN_4057fae0(param_1);
        goto LAB_40580824;
      }
    }
    FUN_40580ef4(pIVar2);
    if (local_3c != (int *)0x0) {
      (**(code **)(*local_3c + 8))();
    }
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 8))();
    }
    if (local_2c != (int *)0x0) {
      (**(code **)(*local_2c + 8))();
    }
    if (local_40 != (int *)0x0) {
      (**(code **)(*local_40 + 8))();
    }
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 8))();
    }
  }
LAB_40580824:
  SetCursor(pHVar1);
  return HVar7;
}



/* 40580850 FUN_40580850 */

undefined4 * FUN_40580850(undefined4 *param_1,int param_2)

{
  byte bVar1;
  
  *param_1 = &PTR_FUN_405715d8;
  bVar1 = *(byte *)(param_1 + 0x195) & 0xef;
  param_1[1] = &PTR_LAB_405715c4;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  *(byte *)(param_1 + 0x195) = bVar1;
  *(byte *)(param_1 + 0x195) = ((param_2 != 0) << 1 ^ bVar1) & 2 ^ bVar1;
  param_1[2] = 1;
  return param_1;
}



/* 405808bc FUN_405808bc */

/* Boundary evidence: original MIPS .pdata 405808bc..40580c53. Semantic name remains unreviewed. */

byte FUN_405808bc(int param_1,int *param_2)

{
  size_t sVar1;
  int iVar2;
  HRSRC pHVar3;
  int iVar4;
  LPCDLGTEMPLATEW hDialogTemplate;
  wchar_t *pwVar5;
  DWORD dwErrCode;
  HMODULE hModule;
  UINT uID;
  int *piVar6;
  undefined4 *puVar7;
  LPCWSTR lpName;
  byte bVar8;
  byte bVar9;
  
  bVar8 = 0;
  if (((param_2 == (int *)0x0) || (*param_2 != 0x4c)) || (param_2[7] == 0)) {
    dwErrCode = 0x57;
LAB_40580c10:
    SetLastError(dwErrCode);
    return 0;
  }
  *(int **)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_2[0xc];
  *(undefined4 *)(param_1 + 0x38) = 0;
  pwVar5 = (wchar_t *)param_2[0xf];
  if (pwVar5 != (wchar_t *)0x0) {
    sVar1 = wcslen(pwVar5);
    pwVar5 = (wchar_t *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar1 + 1) * 2);
    *(wchar_t **)(param_1 + 0x38) = pwVar5;
    if (pwVar5 == (wchar_t *)0x0) {
      dwErrCode = 0xe;
      goto LAB_40580c10;
    }
    wcscpy(pwVar5,(wchar_t *)param_2[0xf]);
  }
  *(undefined2 *)(param_1 + 0x44c) = 0;
  *(undefined4 *)(param_1 + 0xc) = 3;
  *(undefined4 *)(param_1 + 0x10) = 0;
  iVar2 = FUN_4057d0b8(param_1);
  bVar9 = 0;
  if (iVar2 == 0) goto LAB_40580bdc;
  if (*(int *)(param_1 + 0x34) == 0) {
    uID = 0x8101;
    if ((*(byte *)(param_1 + 0x654) & 2) == 0) {
      uID = 0x8100;
    }
    iVar2 = LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
    *(int *)(param_1 + 0x34) = iVar2;
  }
  piVar6 = (int *)(*(int *)(param_1 + 0x30) + 0x18);
  if (*piVar6 == 0) {
    *piVar6 = 1;
  }
  *(undefined2 *)(param_1 + 0x688) = 7;
  *(undefined **)(param_1 + 0x684) = &DAT_405713d4;
  *(undefined **)(param_1 + 0x680) = &DAT_405713c4;
  bVar9 = bVar8;
  if ((param_2[0xd] & 0x40U) == 0) {
    if ((param_2[0xd] & 0x80U) == 0) {
      iVar2 = 0;
      pHVar3 = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x999,L"BOOL");
      if (pHVar3 != (HRSRC)0x0) {
        piVar6 = LoadResource(DAT_405aa0c0,pHVar3);
        iVar2 = *piVar6;
      }
      lpName = (LPCWSTR)0x2500;
      iVar4 = FUN_4057cee8(param_1);
      if (iVar4 == 0) {
LAB_40580b00:
        if (iVar2 != 0) {
          *(undefined **)(param_1 + 0x680) = &DAT_405713cc;
          *(undefined **)(param_1 + 0x684) = &DAT_40571460;
          *(undefined2 *)(param_1 + 0x688) = 2;
        }
      }
      else if (iVar2 != 0) {
        lpName = (LPCWSTR)0x2501;
        goto LAB_40580b00;
      }
      pHVar3 = FindResourceW(DAT_405aa0c0,lpName,(LPCWSTR)0x5);
      hModule = DAT_405aa0c0;
      if (pHVar3 == (HRSRC)0x0) goto LAB_40580bdc;
      goto LAB_40580b48;
    }
    hDialogTemplate = (LPCDLGTEMPLATEW)param_2[2];
  }
  else {
    pHVar3 = FindResourceW((HMODULE)param_2[2],(LPCWSTR)param_2[0x12],(LPCWSTR)0x5);
    if (pHVar3 == (HRSRC)0x0) goto LAB_40580bdc;
    hModule = (HMODULE)param_2[2];
LAB_40580b48:
    hDialogTemplate = LoadResource(hModule,pHVar3);
  }
  if (hDialogTemplate != (LPCDLGTEMPLATEW)0x0) {
    FUN_405a6b40();
    FUN_4057dd98();
    DialogBoxIndirectParamW(DAT_405aa0c0,hDialogTemplate,(HWND)param_2[1],FUN_40580088,param_1);
    DAT_405a9a50 = DAT_405a9a50 + -1;
    if (DAT_405a9a50 == 0) {
      puVar7 = &DAT_405a9a54;
      do {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      } while (puVar7 != &DAT_405a9a64);
    }
    FUN_405a6bf8();
    bVar9 = *(byte *)(param_1 + 0x654) >> 4 & 1;
  }
LAB_40580bdc:
  FUN_4057da58(param_1);
  if (*(int *)(param_1 + 0x38) != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
  }
  return bVar9;
}



/* 40580c54 SHGetOpenFileName */

/* Boundary evidence: original MIPS .pdata 40580c54..40580d07. Semantic name remains unreviewed. */

byte SHGetOpenFileName(int *param_1,int param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  
  bVar1 = 0;
                    /* 0x10c54  21  SHGetOpenFileName */
  puVar2 = operator_new(0x6a0);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_40580850(puVar2,param_2);
  }
  if (puVar2 == (undefined4 *)0x0) {
    SetLastError(0xe);
  }
  else {
    bVar1 = FUN_405808bc((int)puVar2,param_1);
    *puVar2 = &PTR_FUN_405715d8;
    puVar2[1] = &PTR_LAB_405715c4;
    operator_delete(puVar2);
  }
  return bVar1;
}



/* 40580d08 FUN_40580d08 */

/* Boundary evidence: original MIPS .pdata 40580d08..40580ddf. Semantic name remains unreviewed. */

undefined4 FUN_40580d08(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    if ((((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
         (param_2[3] == 0x46000000)) ||
        (((*param_2 == 2 && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) &&
       (*param_3 = (int)param_1, param_1 != (int *)0x0)) {
      (**(code **)(*param_1 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40580df0 FUN_40580df0 */

/* Boundary evidence: original MIPS .pdata 40580df0..40580e0b. Semantic name remains unreviewed. */

void FUN_40580df0(undefined4 param_1,SIZE_T param_2)

{
  LocalAlloc(0,param_2);
  return;
}



/* 40580e0c FUN_40580e0c */

/* Boundary evidence: original MIPS .pdata 40580e0c..40580e33. Semantic name remains unreviewed. */

void FUN_40580e0c(undefined4 param_1,HLOCAL param_2,SIZE_T param_3)

{
  LocalReAlloc(param_2,param_3,0);
  return;
}



/* 40580e34 FUN_40580e34 */

/* Boundary evidence: original MIPS .pdata 40580e34..40580e4f. Semantic name remains unreviewed. */

void FUN_40580e34(undefined4 param_1,HLOCAL param_2)

{
  LocalFree(param_2);
  return;
}



/* 40580e50 FUN_40580e50 */

/* Boundary evidence: original MIPS .pdata 40580e50..40580e6b. Semantic name remains unreviewed. */

void FUN_40580e50(undefined4 param_1,HLOCAL param_2)

{
  LocalSize(param_2);
  return;
}



/* 40580e7c FUN_40580e7c */

/* Boundary evidence: original MIPS .pdata 40580e7c..40580eb3. Semantic name remains unreviewed. */

int FUN_40580e7c(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_405717d4;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40580eb4 FUN_40580eb4 */

undefined4 * FUN_40580eb4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_405717d4;
  param_1[1] = 1;
  return param_1;
}



/* 40580ed0 FUN_40580ed0 */

int FUN_40580ed0(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (uint)*(ushort *)(param_1 + 4) + param_1;
  }
  return iVar1;
}



/* 40580ef4 FUN_40580ef4 */

/* Boundary evidence: original MIPS .pdata 40580ef4..40580f17. Semantic name remains unreviewed. */

void FUN_40580ef4(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    LocalFree(param_1);
  }
  return;
}



/* 40580f18 FUN_40580f18 */

undefined4 FUN_40580f18(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 == 0) || ((*(ushort *)(param_1 + 2) & 0x100) == 0)) {
    uVar1 = 0;
  }
  else {
    puVar2 = (undefined4 *)((uint)*(ushort *)(param_1 + 6) + param_1);
    uVar1 = 1;
    *param_2 = *puVar2;
    param_2[1] = puVar2[1];
  }
  return uVar1;
}



/* 40580f64 FUN_40580f64 */

undefined4 FUN_40580f64(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) || ((*(ushort *)(param_1 + 2) & 0x200) == 0)) {
    uVar1 = 0;
  }
  else {
    iVar2 = (uint)*(ushort *)(param_1 + 6) + param_1;
    uVar1 = 1;
    *param_2 = *(undefined4 *)(iVar2 + 8);
    param_2[1] = *(undefined4 *)(iVar2 + 0xc);
  }
  return uVar1;
}



/* 40580fb4 FUN_40580fb4 */

int FUN_40580fb4(int param_1)

{
  int iVar1;
  
  if ((param_1 == 0) || ((*(ushort *)(param_1 + 2) & 0x400) == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = (uint)*(ushort *)(param_1 + 6) + param_1 + 0x10;
  }
  return iVar1;
}



/* 40580fe8 FUN_40580fe8 */

undefined4 FUN_40580fe8(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0' || param_1[1] != '\0')) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40581018 FUN_40581018 */

/* Boundary evidence: original MIPS .pdata 40581018..405810a3. Semantic name remains unreviewed. */

bool FUN_40581018(LPCITEMIDLIST param_1,LPCITEMIDLIST param_2)

{
  HRESULT HVar1;
  bool bVar2;
  IShellFolder *local_18 [2];
  
  local_18[0] = (IShellFolder *)0x0;
  bVar2 = false;
  HVar1 = SHGetDesktopFolder(local_18);
  if (-1 < HVar1) {
    HVar1 = (*local_18[0]->lpVtbl->CompareIDs)(local_18[0],0,param_1,param_2);
    bVar2 = HVar1 == 0;
    (*local_18[0]->lpVtbl->Release)(local_18[0]);
  }
  return bVar2;
}



/* 405810a4 FUN_405810a4 */

/* Boundary evidence: original MIPS .pdata 405810a4..4058114b. Semantic name remains unreviewed. */

undefined4 FUN_405810a4(char *param_1,char *param_2)

{
  int iVar1;
  
  if ((((param_1 != (char *)0x0) && (*param_1 != '\0' || param_1[1] != '\0')) &&
      (param_2 != (char *)0x0)) &&
     ((*param_2 != '\0' || param_2[1] != '\0' &&
      (iVar1 = CompareStringW(0x400,1,(PCNZWCH)(param_1 + 8),-1,(PCNZWCH)(param_2 + 8),-1),
      iVar1 == 2)))) {
    return 1;
  }
  return 0;
}



/* 4058114c FUN_4058114c */

ushort FUN_4058114c(char *param_1)

{
  ushort uVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0' && param_1[1] == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 2) & 0x1000;
  }
  return uVar1;
}



/* 40581188 FUN_40581188 */

undefined4 FUN_40581188(char *param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == (char *)0x0) || (*param_1 == '\0' && param_1[1] == '\0')) ||
      ((*(ushort *)(param_1 + 2) & 0x1000) == 0)) ||
     (uVar1 = 1, (*(ushort *)(param_1 + 2) & 1) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 405811d8 FUN_405811d8 */

ushort FUN_405811d8(char *param_1)

{
  ushort uVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0' && param_1[1] == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 2) & 0x2000;
  }
  return uVar1;
}



/* 40581214 FUN_40581214 */

char * FUN_40581214(ushort *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if ((param_1 != (ushort *)0x0) &&
     ((pcVar1 = (char *)((uint)*param_1 + (int)param_1), pcVar1 == (char *)0x0 ||
      (*pcVar1 == '\0' && pcVar1[1] == '\0')))) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}



/* 40581264 FUN_40581264 */

int FUN_40581264(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + 8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40581278 FUN_40581278 */

/* Boundary evidence: original MIPS .pdata 40581278..405812eb. Semantic name remains unreviewed. */

int FUN_40581278(ushort *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 == (ushort *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      bVar1 = param_2 == 0;
      param_2 = param_2 + -1;
      if (bVar1) break;
      iVar2 = (uint)*param_1 + iVar2;
      param_1 = (ushort *)FUN_40581214(param_1);
    } while (param_1 != (ushort *)0x0);
    iVar2 = iVar2 + 2;
  }
  return iVar2;
}



/* 405812ec FUN_405812ec */

/* Boundary evidence: original MIPS .pdata 405812ec..4058139f. Semantic name remains unreviewed. */

HLOCAL FUN_405812ec(ushort *param_1,ushort *param_2)

{
  int iVar1;
  HLOCAL _Dst;
  size_t _Size;
  
  _Dst = (HLOCAL)0x0;
  if ((param_1 != (ushort *)0x0) && (param_2 != (ushort *)0x0)) {
    iVar1 = FUN_40581278(param_1,-1);
    _Size = iVar1 - 2;
    iVar1 = FUN_40581278(param_2,-1);
    _Dst = LocalAlloc(0x40,(iVar1 - 2U) + _Size + 2);
    if (_Dst != (HLOCAL)0x0) {
      memcpy(_Dst,param_1,_Size);
      memcpy((void *)(_Size + (int)_Dst),param_2,iVar1 - 2U);
    }
  }
  return _Dst;
}



/* 405813a0 FUN_405813a0 */

/* Boundary evidence: original MIPS .pdata 405813a0..4058140f. Semantic name remains unreviewed. */

HLOCAL FUN_405813a0(ushort *param_1,int param_2)

{
  SIZE_T uBytes;
  HLOCAL _Dst;
  
  _Dst = (HLOCAL)0x0;
  if (param_1 != (ushort *)0x0) {
    uBytes = FUN_40581278(param_1,param_2);
    _Dst = LocalAlloc(0x40,uBytes);
    if (_Dst != (HLOCAL)0x0) {
      memcpy(_Dst,param_1,uBytes - 2);
    }
  }
  return _Dst;
}



/* 40581410 FUN_40581410 */

/* Boundary evidence: original MIPS .pdata 40581410..4058146f. Semantic name remains unreviewed. */

int FUN_40581410(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (param_1 != (ushort *)0x0 &&
         ((char)*param_1 != '\0' || *(char *)((int)param_1 + 1) != '\0'));
      param_1 = (ushort *)FUN_40581214(param_1)) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



/* 40581470 FUN_40581470 */

/* Boundary evidence: original MIPS .pdata 40581470..405814cf. Semantic name remains unreviewed. */

ushort * FUN_40581470(ushort *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar2 = param_1;
  while ((puVar1 = param_1, puVar1 != (ushort *)0x0 &&
         ((char)*puVar1 != '\0' || *(char *)((int)puVar1 + 1) != '\0'))) {
    param_1 = (ushort *)FUN_40581214(puVar1);
    puVar2 = puVar1;
  }
  return puVar2;
}



/* 405814d0 FUN_405814d0 */

ushort FUN_405814d0(char *param_1)

{
  ushort uVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0' && param_1[1] == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 2) & 0x400;
  }
  return uVar1;
}



/* 4058150c FUN_4058150c */

/* Boundary evidence: original MIPS .pdata 4058150c..40581603. Semantic name remains unreviewed. */

undefined4 FUN_4058150c(ushort *param_1,ulong *param_2)

{
  ushort *puVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  CLSID local_28;
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  local_28.Data1 = 0;
  memset(&local_28.Data2,0,0xc);
  puVar1 = FUN_40581470(param_1);
  if (((((puVar1 == (ushort *)0x0) || ((char)*puVar1 == '\0' && *(char *)((int)puVar1 + 1) == '\0'))
       || ((puVar1[1] & 0x2000) == 0)) ||
      ((HVar2 = CLSIDFromString((LPCOLESTR)(puVar1 + 4),&local_28), HVar2 < 0 ||
       (local_28.Data1 != *param_2)))) ||
     ((local_28._4_4_ != param_2[1] ||
      ((local_28.Data4._0_4_ != param_2[2] || (local_28.Data4._4_4_ != param_2[3])))))) {
    FUN_405a7174(local_18);
    uVar3 = 0;
  }
  else {
    FUN_405a7174(local_18);
    uVar3 = 1;
  }
  return uVar3;
}



/* 40581604 FUN_40581604 */

/* Boundary evidence: original MIPS .pdata 40581604..4058177f. Semantic name remains unreviewed. */

bool FUN_40581604(LPCITEMIDLIST param_1,ushort *param_2,int param_3)

{
  bool bVar1;
  LPCITEMIDLIST pIVar2;
  ushort *puVar3;
  char *pcVar4;
  
  if ((param_1 != (LPCITEMIDLIST)0x0) &&
     (puVar3 = param_2, pIVar2 = param_1, param_2 != (ushort *)0x0)) {
    while ((pIVar2 != (LPCITEMIDLIST)0x0 &&
           ((char)(pIVar2->mkid).cb != '\0' || *(char *)((int)&(pIVar2->mkid).cb + 1) != '\0'))) {
      if (puVar3 == (ushort *)0x0) {
        return false;
      }
      if ((char)*puVar3 == '\0' && *(char *)((int)puVar3 + 1) == '\0') {
        return false;
      }
      pIVar2 = (LPCITEMIDLIST)FUN_40581214((ushort *)pIVar2);
      puVar3 = (ushort *)FUN_40581214(puVar3);
    }
    if ((param_3 == 0) ||
       ((((puVar3 != (ushort *)0x0 && ((char)*puVar3 != '\0' || *(char *)((int)puVar3 + 1) != '\0'))
         && (pcVar4 = FUN_40581214(puVar3), pcVar4 != (char *)0x0)) &&
        ((pcVar4 = FUN_40581214(puVar3), pcVar4 == (char *)0x0 ||
         (*pcVar4 == '\0' && pcVar4[1] == '\0')))))) {
      pIVar2 = LocalAlloc(0x40,((int)puVar3 - (int)param_2) + 2);
      if (pIVar2 != (LPCITEMIDLIST)0x0) {
        memcpy(pIVar2,param_2,(int)puVar3 - (int)param_2);
        bVar1 = FUN_40581018(param_1,pIVar2);
        LocalFree(pIVar2);
        return bVar1;
      }
    }
  }
  return false;
}



/* 40581780 FUN_40581780 */

/* Boundary evidence: original MIPS .pdata 40581780..405817bf. Semantic name remains unreviewed. */

bool FUN_40581780(ushort *param_1)

{
  ushort *puVar1;
  
  puVar1 = FUN_40581470(param_1);
  if (puVar1 != (ushort *)0x0) {
    *(undefined1 *)puVar1 = 0;
    *(undefined1 *)((int)puVar1 + 1) = 0;
  }
  return puVar1 != (ushort *)0x0;
}



/* 405817c0 FUN_405817c0 */

/* Boundary evidence: original MIPS .pdata 405817c0..4058184b. Semantic name remains unreviewed. */

ushort * FUN_405817c0(LPCITEMIDLIST param_1,ushort *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_40581604(param_1,param_2,0);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    param_2 = (ushort *)0x0;
  }
  else {
    while ((param_1 != (LPCITEMIDLIST)0x0 &&
           ((char)(param_1->mkid).cb != '\0' || *(char *)((int)&(param_1->mkid).cb + 1) != '\0'))) {
      param_2 = (ushort *)FUN_40581214(param_2);
      param_1 = (LPCITEMIDLIST)FUN_40581214((ushort *)param_1);
    }
  }
  return param_2;
}



/* 4058184c FUN_4058184c */

/* Boundary evidence: original MIPS .pdata 4058184c..4058189f. Semantic name remains unreviewed. */

void FUN_4058184c(int param_1)

{
  if (*(void **)(param_1 + 8) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 8));
  }
  if ((*(int *)(param_1 + 0x14) != 0) && (*(void **)(param_1 + 0x18) != (void *)0x0)) {
    operator_delete(*(void **)(param_1 + 0x18));
  }
  return;
}



/* 405818a0 FUN_405818a0 */

/* Boundary evidence: original MIPS .pdata 405818a0..40581927. Semantic name remains unreviewed. */

undefined4 * FUN_405818a0(undefined4 *param_1)

{
  HIMAGELIST p_Var1;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  p_Var1 = ImageList_Create(0x10,0x10,1,1,0);
  *param_1 = p_Var1;
  p_Var1 = ImageList_Create(0x20,0x20,1,1,0);
  param_1[1] = p_Var1;
  return param_1;
}



/* 40581928 FUN_40581928 */

/* Boundary evidence: original MIPS .pdata 40581928..40581a9f. Semantic name remains unreviewed. */

undefined4 FUN_40581928(undefined4 param_1,LPWSTR param_2,uint param_3)

{
  LPWSTR pszPath;
  int iVar1;
  BOOL BVar2;
  undefined2 local_238;
  undefined1 auStack_236 [10];
  WCHAR aWStack_22c [266];
  
  if (param_3 == 0xffffffff) {
    pszPath = PathFindFileNameW(param_2);
    iVar1 = PathIsGUID(pszPath);
    if (-1 < iVar1) {
      return 1;
    }
    param_2 = PathFindExtensionW(pszPath);
    if (param_2 == (LPWSTR)0x0) {
      return 0;
    }
    if (*param_2 == L'\0') {
      return 1;
    }
  }
  else if ((param_3 & 0x10) != 0) {
    if ((param_3 & 0x100) == 0) {
      return 1;
    }
    local_238 = 0;
    memset(auStack_236,0,0x21e);
    if ((((*param_2 != L'\\') || (param_2[1] != L'\\')) &&
        (iVar1 = CompareStringW(0x409,1,L"\\release",-1,param_2,-1), iVar1 != 2)) &&
       ((iVar1 = CeOidGetInfo(0xe0000001,&local_238), iVar1 == 0 ||
        (iVar1 = CompareStringW(0x400,1,aWStack_22c,-1,param_2,-1), iVar1 != 2)))) {
      return 3;
    }
    return 4;
  }
  BVar2 = PathIsExe(param_2);
  if (BVar2 == 0) {
    return 0;
  }
  return 2;
}



/* 40581aa0 FUN_40581aa0 */

undefined4 FUN_40581aa0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == 0) {
    uVar1 = param_1[1];
  }
  else if (param_2 == 1) {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 40581ac8 FUN_40581ac8 */

/* Boundary evidence: original MIPS .pdata 40581ac8..40581c43. Semantic name remains unreviewed. */

undefined4 FUN_40581ac8(undefined4 param_1,wchar_t *param_2,HICON *param_3,HICON *param_4)

{
  wchar_t *pwVar1;
  long nIconIndex;
  LPWSTR lpString1;
  int iVar2;
  int iVar3;
  HICON pHVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (param_3 != (HICON *)0x0) {
    *param_3 = (HICON)0x0;
  }
  if (param_4 != (HICON *)0x0) {
    *param_4 = (HICON)0x0;
  }
  pwVar1 = wcschr(param_2,L',');
  if (pwVar1 != (wchar_t *)0x0) {
    *pwVar1 = L'\0';
    nIconIndex = _wtol(pwVar1 + 1);
    lpString1 = PathFindFileNameW(param_2);
    uVar5 = 1;
    iVar2 = CompareStringW(0x409,1,lpString1,-1,L"ceshell.dll",-1);
    if (iVar2 == 2) {
      if (param_3 != (HICON *)0x0) {
        iVar2 = GetSystemMetrics(0x32);
        iVar3 = GetSystemMetrics(0x31);
        pHVar4 = LoadImageW(DAT_405aa0c0,(LPCWSTR)(-nIconIndex & 0xffff),1,iVar3,iVar2,0);
        *param_3 = pHVar4;
      }
      if (param_4 != (HICON *)0x0) {
        iVar2 = GetSystemMetrics(0xc);
        iVar3 = GetSystemMetrics(0xb);
        pHVar4 = LoadImageW(DAT_405aa0c0,(LPCWSTR)(-nIconIndex & 0xffff),1,iVar3,iVar2,0);
        *param_4 = pHVar4;
      }
    }
    else {
      ExtractIconExW(param_2,nIconIndex,param_4,param_3,1);
    }
  }
  return uVar5;
}



/* 40581c44 FUN_40581c44 */

/* Boundary evidence: original MIPS .pdata 40581c44..40581e57. Semantic name remains unreviewed. */

undefined4 FUN_40581c44(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  HICON pHVar3;
  undefined4 uVar4;
  uint uVar5;
  _MEMORYSTATUS local_48;
  
  uVar4 = 1;
  memset(&local_48.dwMemoryLoad,0,0x1c);
  local_48.dwLength = 0x20;
  GlobalMemoryStatus(&local_48);
  if (local_48.dwAvailPhys < 0x10000) {
    uVar4 = 0;
  }
  else {
    ImageList_Remove((HIMAGELIST)*param_1,-1);
    ImageList_Remove((HIMAGELIST)param_1[1],-1);
    uVar5 = 0x1500;
    do {
      iVar1 = GetSystemMetrics(0x32);
      iVar2 = GetSystemMetrics(0x31);
      pHVar3 = LoadImageW(DAT_405aa0c0,(LPCWSTR)(uVar5 & 0xffff),1,iVar2,iVar1,0);
      if (pHVar3 == (HICON)0x0) {
LAB_40581e00:
        ImageList_Remove((HIMAGELIST)*param_1,-1);
        ImageList_Remove((HIMAGELIST)param_1[1],-1);
        return 0;
      }
      iVar1 = ImageList_ReplaceIcon((HIMAGELIST)*param_1,-1,pHVar3);
      DestroyIcon(pHVar3);
      if (iVar1 == -1) goto LAB_40581e00;
      iVar1 = GetSystemMetrics(0xc);
      iVar2 = GetSystemMetrics(0xb);
      pHVar3 = LoadImageW(DAT_405aa0c0,(LPCWSTR)(uVar5 & 0xffff),1,iVar2,iVar1,0);
      if (pHVar3 == (HICON)0x0) goto LAB_40581e00;
      iVar1 = ImageList_ReplaceIcon((HIMAGELIST)param_1[1],-1,pHVar3);
      DestroyIcon(pHVar3);
      if (iVar1 == -1) goto LAB_40581e00;
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 0x1506);
    ImageList_SetOverlayImage((HIMAGELIST)*param_1,5,1);
    ImageList_SetOverlayImage((HIMAGELIST)param_1[1],5,1);
  }
  return uVar4;
}



/* 40581e58 FUN_40581e58 */

/* Boundary evidence: original MIPS .pdata 40581e58..40581f47. Semantic name remains unreviewed. */

void FUN_40581e58(undefined4 *param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION p_Var2;
  int *piVar3;
  
  p_Var2 = (LPCRITICAL_SECTION)(param_1 + 5);
  EnterCriticalSection(p_Var2);
  EnterCriticalSection(p_Var2);
  LeaveCriticalSection(p_Var2);
  piVar3 = (int *)param_1[2];
  while (piVar1 = piVar3, piVar1 != (int *)0x0) {
    piVar3 = (int *)0x0;
    if (piVar1 != (int *)0x0) {
      piVar3 = (int *)piVar1[1];
    }
    FUN_40572df0(param_1 + 2,piVar1);
    if (piVar1 != (int *)0x0) {
      FUN_4058184c((int)piVar1);
      operator_delete(piVar1);
    }
  }
  p_Var2 = (LPCRITICAL_SECTION)(param_1 + 5);
  EnterCriticalSection(p_Var2);
  LeaveCriticalSection(p_Var2);
  LeaveCriticalSection(p_Var2);
  if ((HIMAGELIST)*param_1 != (HIMAGELIST)0x0) {
    ImageList_Destroy((HIMAGELIST)*param_1);
  }
  if ((HIMAGELIST)param_1[1] != (HIMAGELIST)0x0) {
    ImageList_Destroy((HIMAGELIST)param_1[1]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  return;
}



/* 40581f48 FUN_40581f48 */

/* Boundary evidence: original MIPS .pdata 40581f48..40582797. Semantic name remains unreviewed. */

void * FUN_40581f48(undefined4 *param_1,LPCWSTR param_2)

{
  void *pvVar1;
  LPWSTR pWVar2;
  int iVar3;
  size_t sVar4;
  STRSAFE_LPWSTR pwVar5;
  HRESULT HVar6;
  LSTATUS LVar7;
  BOOL BVar8;
  wchar_t *_Str;
  size_t sVar9;
  void *pvVar10;
  undefined4 uVar11;
  size_t cchLength;
  HICON pHVar12;
  uint uVar13;
  uint uVar14;
  uint cchDest;
  wchar_t *_Str_00;
  HKEY local_4d8;
  DWORD local_4d4;
  HICON local_4d0;
  HICON local_4cc;
  HICON local_4c8;
  HICON local_4c4;
  wchar_t local_4c0;
  undefined1 auStack_4be [12];
  undefined1 auStack_4b2 [506];
  wchar_t awStack_2b8 [64];
  wchar_t awStack_238 [259];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  if (param_2 == (LPCWSTR)0x0) {
LAB_40581f90:
    FUN_405a7174(local_30);
    return (void *)0x0;
  }
  pvVar1 = operator_new(0x1c);
  uVar13 = 0xffffffff;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    *(undefined4 *)((int)pvVar1 + 0xc) = 0xffffffff;
    *(undefined4 *)((int)pvVar1 + 0x10) = 0xffffffff;
    *(undefined4 *)((int)pvVar1 + 0x14) = 0;
    *(undefined4 *)((int)pvVar1 + 0x18) = 0;
  }
  pWVar2 = PathFindFileNameW(param_2);
  local_4cc = (HICON)0x0;
  local_4d0 = (HICON)0x0;
  local_4c4 = (HICON)0x0;
  local_4c8 = (HICON)0x0;
  local_4d8 = (HKEY)0x0;
  if (pvVar1 == (void *)0x0) goto LAB_40581f90;
  iVar3 = PathIsGUID(pWVar2);
  if (iVar3 < 0) {
    BVar8 = PathIsExe(pWVar2);
    if (BVar8 != 0) {
      sVar4 = wcslen(param_2);
      uVar14 = sVar4 + 1;
      if (uVar14 < 0x80000000) {
        uVar13 = uVar14 * 2;
      }
      pwVar5 = operator_new(uVar13);
      *(STRSAFE_LPWSTR *)((int)pvVar1 + 8) = pwVar5;
      if (pwVar5 != (STRSAFE_LPWSTR)0x0) {
        StringCchCopyW(pwVar5,uVar14,param_2);
      }
      iVar3 = LoadStringW(DAT_405aa0c0,0x8000,(LPWSTR)0x0,0);
      *(int *)((int)pvVar1 + 0x18) = iVar3;
      *(undefined4 *)((int)pvVar1 + 0x14) = 0;
      ExtractIconExW(param_2,0,&local_4d0,&local_4cc,1);
      goto LAB_40582634;
    }
    pWVar2 = PathFindExtensionW(pWVar2);
    local_4c0 = L'\0';
    memset(auStack_4be,0,0x1fe);
    if (((pWVar2 == (LPWSTR)0x0) || (*pWVar2 == L'\0')) || (_Str_00 = pWVar2 + 1, *_Str_00 == L'\0')
       ) {
      sVar4 = wcslen(param_2);
      uVar14 = sVar4 + 1;
      if (uVar14 < 0x80000000) {
        uVar13 = uVar14 * 2;
      }
      pwVar5 = operator_new(uVar13);
      *(STRSAFE_LPWSTR *)((int)pvVar1 + 8) = pwVar5;
      if (pwVar5 != (STRSAFE_LPWSTR)0x0) {
        StringCchCopyW(pwVar5,uVar14,param_2);
      }
      iVar3 = LoadStringW(DAT_405aa0c0,0x8003,(LPWSTR)0x0,0);
LAB_40582530:
      *(undefined4 *)((int)pvVar1 + 0x14) = 0;
      *(int *)((int)pvVar1 + 0x18) = iVar3;
    }
    else {
      sVar4 = wcslen(pWVar2);
      cchDest = sVar4 + 1;
      uVar14 = cchDest * 2;
      if (0x7fffffff < cchDest) {
        uVar14 = 0xffffffff;
      }
      pwVar5 = operator_new(uVar14);
      *(STRSAFE_LPWSTR *)((int)pvVar1 + 8) = pwVar5;
      if (pwVar5 != (STRSAFE_LPWSTR)0x0) {
        StringCchCopyW(pwVar5,cchDest,pWVar2);
      }
      LVar7 = RegOpenKeyExW((HKEY)0x80000000,pWVar2,0,0,&local_4d8);
      if (LVar7 == 0) {
        local_4d4 = 0x200;
        LVar7 = RegQueryValueExW(local_4d8,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_4c0
                                 ,&local_4d4);
        if (LVar7 != 0) {
          local_4c0 = L'\0';
        }
        RegCloseKey(local_4d8);
        local_4d8 = (HKEY)0x0;
      }
      if (local_4c0 == L'\0') {
        sVar4 = wcslen(_Str_00);
        _Str = (wchar_t *)LoadStringW(DAT_405aa0c0,0x8002,(LPWSTR)0x0,0);
        sVar9 = wcslen(_Str);
        HVar6 = StringCchCopyW(awStack_2b8,0x40,_Str_00);
        if (-1 < HVar6) {
          cchLength = sVar4;
          if (0x3e < sVar4) {
            cchLength = 0x3f;
          }
          CharUpperBuffW(awStack_2b8,cchLength);
          _Str_00 = awStack_2b8;
        }
        uVar14 = (sVar9 + sVar4) - 1;
        if (uVar14 < 0x80000000) {
          uVar13 = uVar14 * 2;
        }
        pvVar10 = operator_new(uVar13);
        *(void **)((int)pvVar1 + 0x18) = pvVar10;
        if (pvVar10 != (void *)0x0) {
          sVar4 = LoadStringW(DAT_405aa0c0,0x8002,(LPWSTR)0x0,0);
          swprintf(*(wchar_t **)((int)pvVar1 + 0x18),sVar4,_Str_00);
        }
        *(undefined4 *)((int)pvVar1 + 0x14) = 1;
      }
      else {
        LVar7 = RegOpenKeyExW((HKEY)0x80000000,&local_4c0,0,0,&local_4d8);
        if (LVar7 != 0) {
          iVar3 = LoadStringW(DAT_405aa0c0,0x8006,(LPWSTR)0x0,0);
          goto LAB_40582530;
        }
        local_4d4 = 0x208;
        LVar7 = RegQueryValueExW(local_4d8,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPBYTE)awStack_238,&local_4d4);
        local_32 = 0;
        if (LVar7 == 0) {
          uVar14 = local_4d4 >> 1;
          if (uVar14 < 0x80000000) {
            uVar13 = uVar14 << 1;
          }
          pwVar5 = operator_new(uVar13);
          *(STRSAFE_LPWSTR *)((int)pvVar1 + 0x18) = pwVar5;
          if (pwVar5 != (STRSAFE_LPWSTR)0x0) {
            StringCchCopyW(pwVar5,uVar14,awStack_238);
          }
          *(undefined4 *)((int)pvVar1 + 0x14) = 1;
        }
        else {
          iVar3 = LoadStringW(DAT_405aa0c0,0x8006,(LPWSTR)0x0,0);
          *(int *)((int)pvVar1 + 0x18) = iVar3;
          *(undefined4 *)((int)pvVar1 + 0x14) = 0;
        }
        RegCloseKey(local_4d8);
      }
    }
    if (local_4c0 == L'\0') goto LAB_40582634;
    local_4d4 = 0x208;
    HVar6 = StringCchPrintfW(awStack_238,0x104,L"%s\\%s",&local_4c0,L"DefaultIcon");
    if ((HVar6 < 0) ||
       (LVar7 = RegOpenKeyExW((HKEY)0x80000000,awStack_238,0,0,&local_4d8), LVar7 != 0))
    goto LAB_40582634;
    local_4d4 = 0x208;
    LVar7 = RegQueryValueExW(local_4d8,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)awStack_238,
                             &local_4d4);
    local_32 = 0;
    if (LVar7 == 0) {
      iVar3 = wcscmp(awStack_238,L"%1");
      if (iVar3 == 0) {
        ExtractIconExW(param_2,0,&local_4d0,&local_4cc,1);
      }
      else {
        FUN_40581ac8(param_1,awStack_238,&local_4cc,&local_4d0);
      }
    }
  }
  else {
    sVar4 = wcslen(pWVar2);
    uVar14 = sVar4 + 1;
    if (uVar14 < 0x80000000) {
      uVar13 = uVar14 * 2;
    }
    pwVar5 = operator_new(uVar13);
    *(STRSAFE_LPWSTR *)((int)pvVar1 + 8) = pwVar5;
    if (pwVar5 != (STRSAFE_LPWSTR)0x0) {
      StringCchCopyW(pwVar5,uVar14,pWVar2);
    }
    iVar3 = LoadStringW(DAT_405aa0c0,0x8005,(LPWSTR)0x0,0);
    *(int *)((int)pvVar1 + 0x18) = iVar3;
    *(undefined4 *)((int)pvVar1 + 0x14) = 0;
    memcpy(&local_4c0,L"CLSID\\",0xe);
    memset(auStack_4b2,0,0x1fa);
    HVar6 = StringCchCatW(&local_4c0,0x104,pWVar2);
    if ((HVar6 < 0) ||
       (LVar7 = RegOpenKeyExW((HKEY)0x80000000,&local_4c0,0,0,&local_4d8), LVar7 != 0))
    goto LAB_40582634;
    local_4d4 = 0x208;
    LVar7 = RegQueryValueExW(local_4d8,L"DefaultIcon",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_4c0,
                             &local_4d4);
    if (LVar7 == 0) {
      FUN_40581ac8(param_1,&local_4c0,&local_4cc,&local_4d0);
    }
    local_4d4 = 0x208;
    LVar7 = RegQueryValueExW(local_4d8,L"AltIcon",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_4c0,
                             &local_4d4);
    if (LVar7 == 0) {
      FUN_40581ac8(param_1,&local_4c0,&local_4c4,&local_4c8);
    }
  }
  RegCloseKey(local_4d8);
LAB_40582634:
  if ((*(int *)((int)pvVar1 + 8) == 0) || (*(int *)((int)pvVar1 + 0x18) == 0)) {
    FUN_4058184c((int)pvVar1);
    operator_delete(pvVar1);
    pvVar1 = (void *)0x0;
  }
  else if (local_4d0 == (HICON)0x0) {
    uVar11 = FUN_40581928(param_1,param_2,0);
    *(undefined4 *)((int)pvVar1 + 0xc) = uVar11;
  }
  else {
    iVar3 = ImageList_ReplaceIcon((HIMAGELIST)param_1[1],-1,local_4d0);
    pHVar12 = local_4cc;
    if (local_4cc == (HICON)0x0) {
      pHVar12 = local_4d0;
    }
    ImageList_ReplaceIcon((HIMAGELIST)*param_1,-1,pHVar12);
    *(int *)((int)pvVar1 + 0xc) = iVar3;
    if (local_4c8 != (HICON)0x0) {
      iVar3 = ImageList_ReplaceIcon((HIMAGELIST)param_1[1],-1,local_4c8);
      pHVar12 = local_4c4;
      if (local_4c4 == (HICON)0x0) {
        pHVar12 = local_4c8;
      }
      ImageList_ReplaceIcon((HIMAGELIST)*param_1,-1,pHVar12);
      *(int *)((int)pvVar1 + 0x10) = iVar3;
    }
  }
  if (local_4cc != (HICON)0x0) {
    DestroyIcon(local_4cc);
  }
  if (local_4d0 != (HICON)0x0) {
    DestroyIcon(local_4d0);
  }
  if (local_4c4 != (HICON)0x0) {
    DestroyIcon(local_4c4);
  }
  if (local_4c8 != (HICON)0x0) {
    DestroyIcon(local_4c8);
  }
  FUN_405a7174(local_30);
  return pvVar1;
}



/* 40582798 FUN_40582798 */

/* Boundary evidence: original MIPS .pdata 40582798..405828bf. Semantic name remains unreviewed. */

undefined4 * FUN_40582798(undefined4 *param_1,wchar_t *param_2)

{
  int iVar1;
  LPWSTR _Str1;
  LPCRITICAL_SECTION p_Var2;
  undefined4 *puVar3;
  
  if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
    return (undefined4 *)0x0;
  }
  p_Var2 = (LPCRITICAL_SECTION)(param_1 + 5);
  EnterCriticalSection(p_Var2);
  EnterCriticalSection(p_Var2);
  LeaveCriticalSection(p_Var2);
  puVar3 = (undefined4 *)param_1[2];
  if (puVar3 != (undefined4 *)0x0) {
    do {
      iVar1 = _wcsicmp(param_2,(wchar_t *)puVar3[2]);
      if ((iVar1 == 0) ||
         (((_Str1 = PathFindExtensionW(param_2), _Str1 != (LPWSTR)0x0 && (*_Str1 != L'\0')) &&
          (iVar1 = _wcsicmp(_Str1,(wchar_t *)puVar3[2]), iVar1 == 0)))) break;
      puVar3 = (undefined4 *)puVar3[1];
    } while (puVar3 != (undefined4 *)0x0);
    if (puVar3 != (undefined4 *)0x0) goto LAB_40582874;
  }
  puVar3 = FUN_40581f48(param_1,param_2);
  if (puVar3 != (undefined4 *)0x0) {
    FUN_40572d5c(param_1 + 2,puVar3);
  }
LAB_40582874:
  p_Var2 = (LPCRITICAL_SECTION)(param_1 + 5);
  EnterCriticalSection(p_Var2);
  LeaveCriticalSection(p_Var2);
  LeaveCriticalSection(p_Var2);
  return puVar3;
}



/* 405828c0 FUN_405828c0 */

/* Boundary evidence: original MIPS .pdata 405828c0..40582a0f. Semantic name remains unreviewed. */

undefined4
FUN_405828c0(undefined4 *param_1,LPCWSTR param_2,uint param_3,STRSAFE_LPWSTR param_4,size_t param_5)

{
  LPWSTR pszPath;
  int iVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar4;
  UINT uID;
  
  if (param_2 == (LPCWSTR)0x0) {
    return 0;
  }
  if (param_4 == (STRSAFE_LPWSTR)0x0) {
    return 0;
  }
  if (*param_2 == L'\0') {
    return 0;
  }
  pszPath = PathFindFileNameW(param_2);
  iVar1 = wcscmp(L"\\",param_2);
  if ((iVar1 == 0) || (iVar1 = PathIsGUID(pszPath), -1 < iVar1)) {
    uID = 0x8005;
  }
  else if ((param_3 == 0xffffffff) || ((param_3 & 0x10) == 0)) {
    BVar2 = PathIsExe(pszPath);
    if (BVar2 == 0) {
      iVar1 = PathIsLink(pszPath);
      if (iVar1 == 0) {
        puVar3 = FUN_40582798(param_1,param_2);
        if (puVar3 == (undefined4 *)0x0) {
          return 0;
        }
        pszSrc = (STRSAFE_LPCWSTR)puVar3[6];
        if (pszSrc == (STRSAFE_LPCWSTR)0x0) {
          return 0;
        }
        goto LAB_405829f4;
      }
      uID = 0x8004;
    }
    else {
      uID = 0x8000;
    }
  }
  else {
    uID = 0x8001;
  }
  pszSrc = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
LAB_405829f4:
  HVar4 = StringCchCopyW(param_4,param_5,pszSrc);
  if (HVar4 < 0) {
    return 0;
  }
  return 1;
}



/* 40582a10 FUN_40582a10 */

/* Boundary evidence: original MIPS .pdata 40582a10..40582b67. Semantic name remains unreviewed. */

int FUN_40582a10(undefined4 *param_1,LPWSTR param_2,DWORD param_3,int param_4)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 *puVar3;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if ((param_2 == (LPWSTR)0x0) || (*param_2 == L'\0')) {
    FUN_405a7174(DAT_405a9a3c);
    return -1;
  }
  HVar1 = StringCchCopyW(awStack_228,0x104,param_2);
  if (-1 < HVar1) {
    iVar2 = PathIsLink(param_2);
    if (iVar2 != 0) {
      do {
        iVar2 = SHGetShortcutTarget(awStack_228,awStack_228,0x104);
        if (iVar2 == 0) goto LAB_40582a74;
        PathRemoveQuotesAndArgs(awStack_228);
        iVar2 = PathIsLink(awStack_228);
      } while (iVar2 != 0);
      param_3 = GetFileAttributesW(awStack_228);
    }
    if (((param_3 == 0xffffffff) || ((param_3 & 0x10) == 0)) &&
       (puVar3 = FUN_40582798(param_1,awStack_228), puVar3 != (undefined4 *)0x0)) {
      if ((param_4 == 0) || (iVar2 = puVar3[4], iVar2 == -1)) {
        iVar2 = puVar3[3];
      }
      goto LAB_40582a84;
    }
    param_2 = awStack_228;
  }
LAB_40582a74:
  iVar2 = FUN_40581928(param_1,param_2,param_3);
LAB_40582a84:
  FUN_405a7174(local_20);
  return iVar2;
}



/* 40582b68 FUN_40582b68 */

/* Boundary evidence: original MIPS .pdata 40582b68..40582bfb. Semantic name remains unreviewed. */

undefined4 * FUN_40582b68(undefined4 *param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    param_2 = (undefined4 *)0x0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    param_2[1] = 0;
    *param_2 = 0;
    if (param_1[2] == 0) {
      param_1[1] = param_2;
    }
    else {
      param_2[1] = *param_1;
      *(undefined4 **)*param_1 = param_2;
    }
    *param_1 = param_2;
    param_1[2] = param_1[2] + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  return param_2;
}



/* 40582bfc FUN_40582bfc */

/* Boundary evidence: original MIPS .pdata 40582bfc..40582c5b. Semantic name remains unreviewed. */

undefined4 * FUN_40582bfc(undefined4 *param_1)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd));
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



/* 40582c5c FUN_40582c5c */

/* Boundary evidence: original MIPS .pdata 40582c5c..40582f1f. Semantic name remains unreviewed. */

uint FUN_40582c5c(int *param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  undefined4 *hMem;
  STRSAFE_LPWSTR pwVar4;
  uint uVar5;
  uint uVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  uint cchDest;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 5);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = __GetUserKData(8);
  if (param_1[1] != iVar1) {
    uVar6 = 0;
LAB_40582ed0:
    LeaveCriticalSection(lpCriticalSection);
    return uVar6;
  }
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    LeaveCriticalSection(lpCriticalSection);
    return 0xd;
  }
  if (((param_1[2] == 0) || (param_2 == (wchar_t *)0x0)) || (param_3 == (wchar_t *)0x0)) {
    uVar6 = 0x57;
    goto LAB_40582ed0;
  }
  sVar2 = wcslen(param_2);
  sVar3 = wcslen(param_3);
  if ((0x103 < sVar2) || (0x103 < sVar3)) {
    uVar6 = 0xd;
    goto LAB_40582ed0;
  }
  hMem = LocalAlloc(0,0x10);
  if (hMem == (undefined4 *)0x0) {
    uVar6 = 0xe;
    goto LAB_40582ed0;
  }
  hMem[3] = 0;
  hMem[2] = 0;
  uVar6 = 0xffffffff;
  if (*param_3 != L'\0') {
    cchDest = sVar3 + 1;
    uVar5 = cchDest * 2;
    if (0x7fffffff < cchDest) {
      uVar5 = uVar6;
    }
    pwVar4 = operator_new(uVar5);
    if (pwVar4 == (STRSAFE_LPWSTR)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      goto LAB_40582d88;
    }
    uVar5 = StringCchCopyW(pwVar4,cchDest,param_3);
    if ((int)uVar5 < 0) {
      LeaveCriticalSection(lpCriticalSection);
      operator_delete(pwVar4);
      LocalFree(hMem);
      return uVar5 & 0xffff;
    }
    hMem[3] = pwVar4;
    param_1[4] = param_1[4] + sVar3 + 1;
  }
  if ((param_1[2] != 2) && (*param_2 != L'\0')) {
    uVar5 = sVar2 + 1;
    if (uVar5 < 0x80000000) {
      uVar6 = uVar5 * 2;
    }
    pwVar4 = operator_new(uVar6);
    if (pwVar4 == (STRSAFE_LPWSTR)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      operator_delete((void *)hMem[3]);
      hMem[3] = 0;
LAB_40582d88:
      LocalFree(hMem);
      return 0xe;
    }
    uVar6 = StringCchCopyW(pwVar4,uVar5,param_2);
    if ((int)uVar6 < 0) {
      LeaveCriticalSection(lpCriticalSection);
      operator_delete(pwVar4);
      operator_delete((void *)hMem[3]);
      hMem[3] = 0;
      LocalFree(hMem);
      return uVar6 & 0xffff;
    }
    hMem[2] = pwVar4;
    param_1[3] = param_1[3] + sVar2 + 1;
  }
  FUN_40582b68(param_1 + 10,hMem);
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40582f20 FUN_40582f20 */

/* Boundary evidence: original MIPS .pdata 40582f20..40582f97. Semantic name remains unreviewed. */

undefined4 FUN_40582f20(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  iVar1 = __GetUserKData(8);
  if (param_1[1] == iVar1) {
    if (*param_1 == 0) {
      uVar2 = 0xd;
    }
    else {
      *param_1 = 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  return uVar2;
}



/* 40582f98 FUN_40582f98 */

/* Boundary evidence: original MIPS .pdata 40582f98..4058300f. Semantic name remains unreviewed. */

bool FUN_40582f98(int *param_1)

{
  bool bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  if ((*param_1 != 0) || (bVar1 = param_1[2] != 0, param_1[10] == 0)) {
    bVar1 = false;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  return bVar1;
}



/* 40583010 FUN_40583010 */

/* Boundary evidence: original MIPS .pdata 40583010..405830e7. Semantic name remains unreviewed. */

undefined4 FUN_40583010(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int *hMem;
  
  if (((param_2 == 0) || (param_2 < 1)) || (4 < param_2)) {
    uVar1 = 0xd;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
    while (hMem = (int *)param_1[10], hMem != (int *)0x0) {
      operator_delete((void *)hMem[3]);
      operator_delete((void *)hMem[2]);
      FUN_40572df0(param_1 + 10,hMem);
      LocalFree(hMem);
    }
    *param_1 = 1;
    param_1[2] = param_2;
    uVar1 = __GetUserKData(8);
    param_1[1] = uVar1;
    param_1[3] = 0;
    param_1[4] = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
    uVar1 = 0;
  }
  return uVar1;
}



/* 405830e8 FUN_405830e8 */

/* Boundary evidence: original MIPS .pdata 405830e8..4058368f. Semantic name remains unreviewed. */

DWORD FUN_405830e8(int *param_1,HWND param_2)

{
  uint *puVar1;
  bool bVar2;
  undefined1 *puVar3;
  size_t sVar4;
  uint uVar5;
  DWORD DVar6;
  size_t sVar7;
  STRSAFE_LPWSTR pwVar8;
  STRSAFE_LPWSTR pszDest;
  BOOL BVar9;
  STRSAFE_PCNZWCH pwVar10;
  wchar_t *_Str;
  int iVar11;
  DWORD DVar12;
  wchar_t *pwVar13;
  int *hMem;
  size_t sVar14;
  LPCRITICAL_SECTION lpCriticalSection;
  size_t local_58;
  STRSAFE_LPWSTR local_54;
  HLOCAL local_50;
  STRSAFE_LPWSTR local_4c;
  _SHFILEOPSTRUCTW local_48;
  
  local_54 = (STRSAFE_LPWSTR)0x0;
  local_58 = 0;
  memset(&local_48.wFunc,0,0x1a);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 5);
  DVar12 = 0;
  local_48.hwnd = param_2;
  EnterCriticalSection(lpCriticalSection);
  if (((*param_1 != 0) || (iVar11 = param_1[2], iVar11 == 0)) ||
     ((iVar11 != 2 && (param_1[3] == 0)))) {
    LeaveCriticalSection(lpCriticalSection);
    return 0xd;
  }
  hMem = (int *)param_1[10];
  if (hMem == (int *)0x0) {
    DVar12 = 0xd;
LAB_405831dc:
    LeaveCriticalSection(lpCriticalSection);
    return DVar12;
  }
  if (iVar11 == 2) {
    local_58 = param_1[4];
    uVar5 = (local_58 + 1) * 2;
    if (0x7fffffff < local_58 + 1) {
      uVar5 = 0xffffffff;
    }
    local_54 = operator_new(uVar5);
    if (local_54 == (STRSAFE_LPWSTR)0x0) {
      DVar12 = 0xe;
      goto LAB_405831dc;
    }
  }
  local_48.fFlags._0_1_ = 0x10;
  puVar3 = (undefined1 *)((int)&local_48.lpszProgressTitle + 3);
  uVar5 = (uint)puVar3 & 3;
  puVar1 = (uint *)(puVar3 + -uVar5);
  *puVar1 = *puVar1 & -1 << (uVar5 + 1) * 8 | 0x4057185cU >> (3 - uVar5) * 8;
  local_48.fFlags._1_1_ = 3;
  uVar5 = (uint)&local_48.lpszProgressTitle & 3;
  puVar1 = (uint *)((int)&local_48.lpszProgressTitle - uVar5);
  *puVar1 = *puVar1 & 0xffffffffU >> (4 - uVar5) * 8 | 0x4057185c << uVar5 * 8;
  sVar14 = local_58;
  pwVar8 = local_54;
  local_4c = local_54;
  do {
    if (((param_1[2] == 2) && (pwVar13 = (wchar_t *)hMem[3], pwVar13 != (wchar_t *)0x0)) &&
       (*pwVar13 != L'\0')) {
      sVar4 = wcslen(pwVar13);
      uVar5 = StringCchCopyW(pwVar8,sVar14,pwVar13);
      if ((int)uVar5 < 0) {
        DVar12 = uVar5 & 0xffff;
      }
      else {
        pwVar8 = pwVar8 + sVar4 + 1;
        sVar14 = (sVar14 - sVar4) - 1;
        local_58 = sVar14;
        local_4c = pwVar8;
      }
    }
    if (((param_1[2] == 3) && ((short *)hMem[2] != (short *)0x0)) &&
       ((*(short *)hMem[2] != 0 &&
        ((pwVar10 = (STRSAFE_PCNZWCH)hMem[3], pwVar10 != (STRSAFE_PCNZWCH)0x0 && (*pwVar10 != L'\0')
         ))))) {
      local_50 = (HLOCAL)0x0;
      iVar11 = FUN_40587d0c(pwVar10,&local_50);
      if (iVar11 < 0) {
        DVar12 = 0xd;
      }
      else {
        FUN_40586a28(DAT_405aa0d4,0);
        DVar6 = FUN_40584fb4(DAT_405aa0d4,(int)local_50);
        if ((int)DVar6 < 0) {
          DVar12 = 0xd;
        }
        FUN_40583798(DAT_405aa0d4);
        FUN_40580ef4(local_50);
      }
    }
    if (((((param_1[2] == 1) || (param_1[2] == 4)) &&
         (pwVar13 = (wchar_t *)hMem[2], pwVar13 != (wchar_t *)0x0)) &&
        ((*pwVar13 != L'\0' && (_Str = (wchar_t *)hMem[3], _Str != (wchar_t *)0x0)))) &&
       (*_Str != L'\0')) {
      sVar4 = wcslen(_Str);
      sVar7 = wcslen(pwVar13);
      uVar5 = (sVar4 + 2) * 2;
      if (0x7fffffff < sVar4 + 2) {
        uVar5 = 0xffffffff;
      }
      pwVar8 = operator_new(uVar5);
      uVar5 = (sVar7 + 2) * 2;
      if (0x7fffffff < sVar7 + 2) {
        uVar5 = 0xffffffff;
      }
      pszDest = operator_new(uVar5);
      if ((pwVar8 == (STRSAFE_LPWSTR)0x0) || (pszDest == (STRSAFE_LPWSTR)0x0)) {
        DVar12 = 0xe;
      }
      else {
        uVar5 = StringCchCopyW(pwVar8,sVar4 + 1,(STRSAFE_LPCWSTR)hMem[3]);
        if (((int)uVar5 < 0) ||
           (uVar5 = StringCchCopyW(pszDest,sVar7 + 1,(STRSAFE_LPCWSTR)hMem[2]), (int)uVar5 < 0)) {
          DVar12 = uVar5 & 0xffff;
        }
        else {
          DVar6 = GetFileAttributesW(pwVar8);
          bVar2 = false;
          sVar14 = local_58;
          if ((((DVar6 == 0xffffffff) || ((DVar6 & 0x10) == 0)) ||
              (DVar6 = GetFileAttributesW(pszDest), DVar6 == 0xffffffff)) || ((DVar6 & 0x10) == 0))
          {
LAB_405835bc:
            pwVar8[sVar4 + 1] = L'\0';
            pszDest[sVar7 + 1] = L'\0';
            if (param_1[2] == 1) {
              local_48.wFunc = 1;
            }
            else {
              local_48.wFunc = 4;
            }
            local_48.pFrom = pwVar8;
            local_48.pTo = pszDest;
            iVar11 = SHFileOperationW(&local_48);
            if (iVar11 != 0) {
              if (bVar2) goto LAB_4058349c;
LAB_4058359c:
              DVar12 = GetLastError();
            }
          }
          else {
            if (param_1[2] == 4) {
              bVar2 = true;
              goto LAB_405835bc;
            }
            BVar9 = RemoveDirectoryW(pwVar8);
            if (BVar9 == 0) goto LAB_4058359c;
LAB_4058349c:
            DVar12 = 0;
          }
        }
      }
      if (pwVar8 != (STRSAFE_LPWSTR)0x0) {
        operator_delete(pwVar8);
      }
      pwVar8 = local_4c;
      if (pszDest != (STRSAFE_LPWSTR)0x0) {
        operator_delete(pszDest);
        pwVar8 = local_4c;
      }
    }
    if (DVar12 != 0) {
LAB_40583520:
      iVar11 = param_1[2];
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
      if ((DVar12 == 0) && (iVar11 == 2)) {
        local_54[param_1[4]] = L'\0';
        local_48.wFunc = 3;
        local_48.pFrom = local_54;
        local_48.pTo = (STRSAFE_LPWSTR)0x0;
        iVar11 = SHFileOperationW(&local_48);
        if (iVar11 != 0) {
          DVar12 = GetLastError();
        }
      }
      operator_delete(local_54);
      return DVar12;
    }
    operator_delete((void *)hMem[3]);
    operator_delete((void *)hMem[2]);
    FUN_40572df0(param_1 + 10,hMem);
    LocalFree(hMem);
    if (((param_1[2] == 2) && (sVar14 == 0)) || (hMem = (int *)param_1[10], hMem == (int *)0x0))
    goto LAB_40583520;
  } while( true );
}



/* 40583690 FUN_40583690 */

/* Boundary evidence: original MIPS .pdata 40583690..405836ef. Semantic name remains unreviewed. */

void FUN_40583690(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  DAT_405a9a7c = 1;
  memset(&DAT_405a9a8c,-1,0x10);
  DAT_405a9a80 = 0;
  DAT_405a9a88 = 0;
  DAT_405a9a84 = 0;
  return;
}



/* 405836f0 FUN_405836f0 */

/* Boundary evidence: original MIPS .pdata 405836f0..40583797. Semantic name remains unreviewed. */

void FUN_405836f0(void)

{
  if (DAT_405a9a84 != 0) {
    CloseHandle((HANDLE)DAT_405a9a84);
  }
  if ((DAT_405aa0bc == 1) &&
     ((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) != 0xffffffff)) {
    CeUnmountDBVol();
    DAT_405a9a80 = 0;
  }
  if (DAT_405a9a7c != 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  }
  return;
}



/* 40583798 FUN_40583798 */

/* Boundary evidence: original MIPS .pdata 40583798..4058384f. Semantic name remains unreviewed. */

void FUN_40583798(int param_1)

{
  HANDLE hFindFile;
  
  hFindFile = *(HANDLE *)(param_1 + 0xc);
  if ((hFindFile != (HANDLE)0xffffffff) && (hFindFile != (HANDLE)0x0)) {
    FindClose(hFindFile);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  if (DAT_405a9a84 != 0) {
    CloseHandle((HANDLE)DAT_405a9a84);
    DAT_405a9a84 = 0;
  }
  if (DAT_405aa0bc != 1) {
    memset(&DAT_405a9a8c,-1,0x10);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  return;
}



/* 40583850 FUN_40583850 */

/* Boundary evidence: original MIPS .pdata 40583850..40583a93. Semantic name remains unreviewed. */

DWORD FUN_40583850(void)

{
  BOOL BVar1;
  int iVar2;
  HRESULT HVar3;
  BOOL BVar4;
  DWORD DVar5;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  DVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  if (((DAT_405a9a84 == 0) || (DAT_405a9a84 == -1)) ||
     ((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) == 0xffffffff)) {
LAB_40583914:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    FUN_405a7174(local_30);
    return 0xd;
  }
  if (DAT_405aa0bc == 1) {
    if (((DAT_405a9a98 == 0 && DAT_405a9a94 == 0) && DAT_405a9a90 == 0) && DAT_405a9a8c == 0)
    goto LAB_40583914;
  }
  else if (((DAT_405a9a98 != 0 || DAT_405a9a94 != 0) || DAT_405a9a90 != 0) || DAT_405a9a8c != 0)
  goto LAB_40583914;
  BVar1 = CloseHandle((HANDLE)DAT_405a9a84);
  if ((DAT_405a9a88 == 0) || (BVar1 == 0)) {
    DVar5 = 0xd;
  }
  else {
    iVar2 = CeDeleteDatabaseEx(&DAT_405a9a8c);
    if (iVar2 != 0) {
      if ((DAT_405aa0bc == 1) && (BVar1 = CeUnmountDBVol(&DAT_405a9a8c), BVar1 != 0)) {
        DAT_405a9a80 = 0;
      }
      iVar2 = DAT_405aa0bc;
      memset(&DAT_405a9a8c,-1,0x10);
      DAT_405a9a84 = 0;
      DAT_405a9a88 = 0;
      if ((((iVar2 != 1) || (BVar1 == 0)) ||
          (HVar3 = StringCchCopyW(awStack_238,0x104,(STRSAFE_LPCWSTR)&DAT_405a9cac), HVar3 < 0)) ||
         ((HVar3 = StringCchCatW(awStack_238,0x104,L"\\recycle.bin"), HVar3 < 0 ||
          (BVar4 = DeleteFileW(awStack_238), BVar4 != 0)))) goto LAB_40583a68;
    }
    DVar5 = GetLastError();
  }
LAB_40583a68:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  if ((DVar5 == 0) && (BVar1 == 0)) {
    DVar5 = 0xd;
  }
  FUN_405a7174(local_30);
  return DVar5;
}



/* 40583a94 FUN_40583a94 */

/* Boundary evidence: original MIPS .pdata 40583a94..40583c2b. Semantic name remains unreviewed. */

undefined4 FUN_40583a94(int param_1,void *param_2)

{
  HRESULT HVar1;
  int iVar2;
  DWORD dwFileAttributes;
  BOOL BVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  uVar5 = 0;
  memset(param_2,-1,0x10);
  HVar1 = StringCchCopyW(awStack_230,0x104,(STRSAFE_LPCWSTR)&DAT_405a9cac);
  if ((-1 < HVar1) && (HVar1 = StringCchCatW(awStack_230,0x104,L"\\recycle.bin"), -1 < HVar1)) {
    uVar6 = *(uint *)(param_1 + 4) / 5000;
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    iVar4 = 0;
    if (uVar6 != 0) {
      do {
        iVar2 = CeMountDBVol(param_2,awStack_230,4);
        if (iVar2 != 0) {
          uVar5 = 1;
          DAT_405a9a80 = 1;
          dwFileAttributes = GetFileAttributesW(awStack_230);
          if (dwFileAttributes != 0xffffffff) {
            if ((dwFileAttributes & 4) == 0) {
              dwFileAttributes = dwFileAttributes | 4;
            }
            if ((dwFileAttributes & 2) == 0) {
              dwFileAttributes = dwFileAttributes | 4;
            }
            BVar3 = SetFileAttributesW(awStack_230,dwFileAttributes);
            if (BVar3 == 0) {
              uVar5 = 0;
            }
          }
          break;
        }
        memset(param_2,-1,0x10);
        Sleep(5000);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)uVar6);
    }
  }
  FUN_405a7174(local_28);
  return uVar5;
}



/* 40583c2c FUN_40583c2c */

/* Boundary evidence: original MIPS .pdata 40583c2c..40583ce7. Semantic name remains unreviewed. */

undefined4
FUN_40583c2c(undefined4 param_1,HKEY param_2,LPCWSTR param_3,LPCWSTR param_4,undefined4 param_5)

{
  LSTATUS LVar1;
  HKEY local_20;
  undefined4 local_1c;
  DWORD local_18 [2];
  
  local_20 = (HKEY)0x0;
  local_1c = param_5;
  LVar1 = RegOpenKeyExW(param_2,param_3,0,0,&local_20);
  if (LVar1 == 0) {
    local_18[0] = 4;
    LVar1 = RegQueryValueExW(local_20,param_4,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_1c,local_18);
    if (LVar1 != 0) {
      local_1c = param_5;
    }
    RegCloseKey(local_20);
    param_5 = local_1c;
  }
  return param_5;
}



/* 40583ce8 FUN_40583ce8 */

/* Boundary evidence: original MIPS .pdata 40583ce8..40583e8b. Semantic name remains unreviewed. */

int FUN_40583ce8(undefined4 param_1,LPCWSTR param_2,STRSAFE_LPWSTR param_3,size_t param_4,
                undefined4 *param_5)

{
  LPWSTR pWVar1;
  int iVar2;
  undefined2 local_38 [2];
  undefined4 *local_34;
  undefined4 local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  
  local_38[0] = 2;
  if ((((param_2 == (LPCWSTR)0x0) || (DAT_405a9a84 == 0)) || (DAT_405a9a84 == -1)) ||
     (local_34 = LocalAlloc(0,0x20), local_34 == (undefined4 *)0x0)) {
    iVar2 = 0;
  }
  else {
    *local_34 = 0x1021001f;
    *(undefined2 *)((int)local_34 + 6) = 0;
    pWVar1 = PathFindFileNameW(param_2);
    local_34[2] = pWVar1;
    iVar2 = CeSeekDatabaseEx(DAT_405a9a84,0x20,local_34,1,0);
    if ((iVar2 != 0) && ((param_3 != (STRSAFE_LPWSTR)0x0 || (param_5 != (undefined4 *)0x0)))) {
      local_28 = 0x1022001f;
      local_24 = 0x10230040;
      local_30[0] = 0x20;
      iVar2 = CeReadRecordPropsEx(DAT_405a9a84,1,local_38,&local_28,&local_34,local_30,0);
      if (iVar2 != 0) {
        if (param_3 != (STRSAFE_LPWSTR)0x0) {
          StringCchCopyExW(param_3,param_4,(STRSAFE_LPCWSTR)local_34[2],(STRSAFE_LPWSTR *)0x0,
                           (size_t *)0x0,0x800);
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = local_34[6];
          param_5[1] = local_34[7];
        }
      }
    }
    LocalFree(local_34);
  }
  return iVar2;
}



/* 40583e8c FUN_40583e8c */

/* Boundary evidence: original MIPS .pdata 40583e8c..4058400f. Semantic name remains unreviewed. */

undefined4 FUN_40583e8c(undefined4 param_1,uint param_2,STRSAFE_LPCWSTR param_3,undefined4 *param_4)

{
  STRSAFE_LPWSTR pszDest;
  undefined4 uVar1;
  HRESULT HVar2;
  DWORD DVar3;
  HANDLE hObject;
  undefined4 local_2c;
  
  local_2c = 0;
  if (param_4 == (undefined4 *)0x0) {
    local_2c = 0x57;
  }
  else {
    *param_4 = 0;
    pszDest = operator_new(0x20a);
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      local_2c = 0xe;
    }
    else {
      while( true ) {
        while( true ) {
          do {
            uVar1 = Random();
            HVar2 = StringCchPrintfW(pszDest,0x105,L"%s\\tk%x",&DAT_405a9aa4,uVar1);
          } while (HVar2 < 0);
          if (param_3 != (STRSAFE_LPCWSTR)0x0) {
            StringCchCatW(pszDest,0x105,param_3);
          }
          if ((param_2 & 0x10) == 0) break;
          DVar3 = GetFileAttributesW(pszDest);
          if ((DVar3 == 0xffffffff) || ((DVar3 & 0x10) == 0)) goto LAB_40583f84;
        }
        hObject = CreateFileW(pszDest,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
        if (hObject == (HANDLE)0xffffffff) break;
        CloseHandle(hObject);
      }
LAB_40583f84:
      *param_4 = pszDest;
    }
  }
  return local_2c;
}



/* 40584010 FUN_40584010 */

/* Boundary evidence: original MIPS .pdata 40584010..4058410f. Semantic name remains unreviewed. */

int FUN_40584010(undefined4 param_1,uint *param_2)

{
  HANDLE hFindFile;
  BOOL BVar1;
  int iVar2;
  uint local_234;
  DWORD local_230;
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  iVar2 = 0;
  *param_2 = 0;
  param_2[1] = 0;
  hFindFile = FindFirstFileW((LPCWSTR)&DAT_405a9eb4,(LPWIN32_FIND_DATAW)&stack0xfffffdb0);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      iVar2 = iVar2 + 1;
      *(ulonglong *)param_2 =
           (ulonglong)local_234 * 0xffffffff + CONCAT44(param_2[1],local_230) + (ulonglong)*param_2;
      BVar1 = FindNextFileW(hFindFile,(LPWIN32_FIND_DATAW)&stack0xfffffdb0);
    } while (BVar1 != 0);
    FindClose(hFindFile);
  }
  FUN_405a7174(local_20);
  return iVar2;
}



/* 40584110 FUN_40584110 */

bool FUN_40584110(int param_1)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = true;
  if ((*(uint *)(param_1 + 0x14) & 0x10) == 0) {
    uVar2 = *(uint *)(param_1 + 0x10) & 0x40;
  }
  else {
    bVar1 = *(int *)(param_1 + 0x34) == *(int *)(param_1 + 0x30);
    uVar2 = *(uint *)(param_1 + 0x10) & 0x20;
  }
  if (uVar2 == 0) {
    bVar1 = false;
  }
  return bVar1;
}



/* 4058416c FUN_4058416c */

/* Boundary evidence: original MIPS .pdata 4058416c..405841c7. Semantic name remains unreviewed. */

bool FUN_4058416c(void)

{
  bool bVar1;
  
  bVar1 = DAT_405a9aa0 != (HWND)0x0;
  if (bVar1) {
    InvalidateRect(DAT_405a9aa0,(RECT *)0x0,1);
    UpdateWindow(DAT_405a9aa0);
  }
  return bVar1;
}



/* 405841c8 FUN_405841c8 */

/* Boundary evidence: original MIPS .pdata 405841c8..40584467. Semantic name remains unreviewed. */

DWORD FUN_405841c8(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  int iVar3;
  undefined2 local_128;
  undefined2 local_126;
  undefined2 local_124;
  undefined4 local_120;
  undefined4 local_114;
  undefined2 local_108;
  undefined2 local_106;
  undefined4 local_104;
  wchar_t awStack_100 [32];
  undefined4 local_c0;
  undefined1 auStack_ac [128];
  uint local_2c;
  
  local_2c = DAT_405a9a3c;
  iVar3 = 1;
  DVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  if (DAT_405aa0bc == 1) {
    if ((DAT_405a9a80 == 0) &&
       ((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) == 0xffffffff)) {
      iVar3 = FUN_40583a94(param_1,&DAT_405a9a8c);
LAB_405842b0:
      if (iVar3 == 0) {
        DVar2 = 0xd;
        goto LAB_40584428;
      }
    }
  }
  else if (((DAT_405a9a98 != 0 || DAT_405a9a94 != 0) || DAT_405a9a90 != 0) || DAT_405a9a8c != 0) {
    memset(&DAT_405a9a8c,0,0x10);
    goto LAB_405842b0;
  }
  if (((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) != 0xffffffff) &&
     ((DAT_405a9a84 == 0 || (DAT_405a9a84 == -1)))) {
    memset(&local_108,0,0xdc);
    uVar1 = StringCchCopyW(awStack_100,0x20,L"RecycleData");
    if ((int)uVar1 < 0) {
      DVar2 = uVar1 & 0xffff;
    }
    else {
      local_104 = 7;
      local_108 = 1;
      if (DAT_405aa0bc != 1) {
        local_104 = 0x20007;
      }
      local_c0 = 0x10211201;
      local_106 = 1;
      local_128 = 1;
      local_126 = 1;
      local_124 = 0;
      local_120 = 0x1021001f;
      local_114 = 1;
      memcpy(auStack_ac,&local_128,0x20);
      DAT_405a9a88 = 0;
      DAT_405a9a84 = CeOpenDatabaseEx2(&DAT_405a9a8c,&DAT_405a9a88,awStack_100,&local_128,0,0);
      if (DAT_405a9a84 == -1) {
        iVar3 = CeCreateDatabaseEx2(&DAT_405a9a8c,&local_108);
        if (iVar3 != 0) {
          DAT_405a9a88 = 0;
          DAT_405a9a84 = CeOpenDatabaseEx2(&DAT_405a9a8c,&DAT_405a9a88,awStack_100,&local_128,0,0);
          if (DAT_405a9a84 != -1) goto LAB_40584428;
        }
        DVar2 = GetLastError();
        memset(&DAT_405a9a8c,-1,0x10);
        DAT_405a9a88 = 0;
      }
    }
  }
LAB_40584428:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  FUN_405a7174(local_2c);
  return DVar2;
}



/* 40584468 FUN_40584468 */

/* Boundary evidence: original MIPS .pdata 40584468..405848a3. Semantic name remains unreviewed. */

int FUN_40584468(undefined4 param_1,int param_2)

{
  uint uVar1;
  HANDLE pvVar2;
  HRESULT HVar3;
  int iVar4;
  LPWSTR pWVar5;
  HRESULT HVar6;
  DWORD DVar7;
  BOOL BVar8;
  int iVar9;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar10;
  uint local_8b0 [2];
  LPCRITICAL_SECTION local_8a8;
  undefined1 local_8a0 [564];
  undefined1 auStack_66c [36];
  wchar_t awStack_648 [260];
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  local_8b0[0] = 0;
  local_8b0[1] = 0;
  local_8a8 = (LPCRITICAL_SECTION)&DAT_405a9a68;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  if ((((DAT_405a9a84 == 0) || (DAT_405a9a84 == -1)) || (DAT_405a9a88 == 0)) ||
     (iVar10 = -0x7fffbffb,
     (DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) == 0xffffffff)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    FUN_405a7174(local_30);
    return -0x7fffbffb;
  }
  if ((param_2 == 0) || (uVar1 = FUN_40584010(param_1,local_8b0), uVar1 == 0)) {
LAB_40584694:
    iVar9 = 0;
    local_8a0._0_4_ = 0;
    memset(local_8a0 + 4,0,0x22c);
    pvVar2 = FindFirstFileW((LPCWSTR)&DAT_405a9eb4,(LPWIN32_FIND_DATAW)local_8a0);
    lpCriticalSection = (LPCRITICAL_SECTION)&DAT_405a9a68;
    if (pvVar2 != (HANDLE)0xffffffff) {
      do {
        iVar9 = StringCchCopyW(awStack_440,0x104,&DAT_405a9aa4);
        if (((-1 < iVar9) && (iVar9 = StringCchCatW(awStack_440,0x104,L"\\"), -1 < iVar9)) &&
           (iVar9 = StringCchCatW(awStack_440,0x104,(STRSAFE_LPCWSTR)(local_8a0 + 0x28)), -1 < iVar9
           )) {
          DVar7 = GetFileAttributesW(awStack_440);
          if (DVar7 != 0xffffffff) {
            if ((DVar7 & 1) != 0) {
              SetFileAttributesW(awStack_440,0);
            }
            if ((DVar7 & 0x10) == 0) {
              iVar4 = DeleteFileW(awStack_440);
            }
            else {
              iVar4 = RemoveDirectoryW(awStack_440);
            }
            if ((iVar4 != 0) &&
               ((iVar4 = FUN_40583ce8(param_1,awStack_440,(STRSAFE_LPWSTR)0x0,0,(undefined4 *)0x0),
                iVar4 == 0 || (iVar4 = CeDeleteRecord(DAT_405a9a84,iVar4), iVar4 != 0))))
            goto LAB_405847e8;
          }
          iVar9 = -0x7fffbffb;
        }
LAB_405847e8:
        BVar8 = FindNextFileW(pvVar2,(LPWIN32_FIND_DATAW)local_8a0);
      } while ((BVar8 != 0) && (-1 < iVar9));
      FindClose(pvVar2);
      lpCriticalSection = local_8a8;
    }
    LeaveCriticalSection(lpCriticalSection);
    if (-1 < iVar9) {
      DVar7 = FUN_40583850();
      if (DVar7 != 0) {
        iVar9 = iVar10;
      }
      FUN_4058416c();
    }
  }
  else {
    local_8b0[0] = 6;
    iVar9 = 1;
    if (uVar1 == 1) {
      local_8a0._560_2_ = L'\0';
      local_8a0._562_2_ = L'\0';
      memset(auStack_66c,0,0x22c);
      pvVar2 = FindFirstFileW((LPCWSTR)&DAT_405a9eb4,(LPWIN32_FIND_DATAW)(local_8a0 + 0x230));
      HVar6 = iVar10;
      if (pvVar2 == (HANDLE)0xffffffff) goto LAB_40584674;
      local_8a0._0_4_ = local_8a0._0_4_ & 0xffff0000;
      memset(local_8a0 + 2,0,0x206);
      FindClose(pvVar2);
      HVar3 = StringCchCopyW(awStack_238,0x104,&DAT_405a9aa4);
      if (((-1 < HVar3) && (HVar3 = StringCchCatW(awStack_238,0x104,L"\\"), -1 < HVar3)) &&
         (HVar3 = StringCchCatW(awStack_238,0x104,awStack_648), -1 < HVar3)) {
        iVar4 = FUN_40583ce8(param_1,awStack_238,(STRSAFE_LPWSTR)local_8a0,0x104,(undefined4 *)0x0);
        if (iVar4 != 0) {
          pWVar5 = PathFindFileNameW((LPCWSTR)local_8a0);
          HVar6 = FUN_4058b140(pWVar5,(HWND)0x0,0,(INT_PTR *)local_8b0);
        }
        goto LAB_40584674;
      }
    }
    else {
      HVar6 = FUN_4058af5c(uVar1,(HWND)0x0,1,(INT_PTR *)local_8b0);
LAB_40584674:
      if ((-1 < HVar6) && (local_8b0[0] == 6)) goto LAB_40584694;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  }
  FUN_405a7174(local_30);
  return iVar9;
}



/* 405848a4 FUN_405848a4 */

/* Boundary evidence: original MIPS .pdata 405848a4..405849cf. Semantic name remains unreviewed. */

undefined4 FUN_405848a4(undefined4 param_1,int param_2,undefined4 *param_3)

{
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  uVar3 = 0;
  if ((param_2 != 0) && (param_3 != (undefined4 *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    if ((DAT_405a9a84 != 0) &&
       (((DAT_405a9a84 != -1 && (DAT_405a9a88 != 0)) &&
        ((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) != 0xffffffff)))) {
      pszSrc = (STRSAFE_LPCWSTR)FUN_40580ed0(param_2);
      HVar1 = StringCchCopyW(awStack_228,0x104,pszSrc);
      if (-1 < HVar1) {
        iVar2 = FUN_40583ce8(param_1,awStack_228,(STRSAFE_LPWSTR)0x0,0,param_3);
        if (iVar2 != 0) {
          uVar3 = 1;
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  }
  FUN_405a7174(local_20);
  return uVar3;
}



/* 405849d0 FUN_405849d0 */

/* Boundary evidence: original MIPS .pdata 405849d0..40584b7b. Semantic name remains unreviewed. */

wchar_t * FUN_405849d0(undefined4 param_1,int param_2)

{
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar1;
  int iVar2;
  size_t sVar3;
  wchar_t *_Source;
  wchar_t *_Dest;
  wchar_t awStack_430 [260];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  _Dest = (wchar_t *)0x0;
  if (param_2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    if ((((DAT_405a9a84 != 0) && (DAT_405a9a84 != -1)) && (DAT_405a9a88 != 0)) &&
       ((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) != 0xffffffff)) {
      pszSrc = (STRSAFE_LPCWSTR)FUN_40580ed0(param_2);
      HVar1 = StringCchCopyW(awStack_228,0x104,pszSrc);
      if ((-1 < HVar1) &&
         (iVar2 = FUN_40583ce8(param_1,awStack_228,awStack_430,0x104,(undefined4 *)0x0), iVar2 != 0)
         ) {
        PathRemoveFileSpecW(awStack_430);
        sVar3 = wcslen(awStack_430);
        if (DAT_405aa0c8 != (int *)0x0) {
          if (sVar3 == 0) {
            _Dest = (wchar_t *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,4);
            if (_Dest == (wchar_t *)0x0) goto LAB_40584b30;
            _Source = L"\\";
          }
          else {
            _Dest = (wchar_t *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar3 + 1) * 2);
            if (_Dest == (wchar_t *)0x0) goto LAB_40584b30;
            _Source = awStack_430;
          }
          wcscpy(_Dest,_Source);
        }
      }
LAB_40584b30:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
      FUN_405a7174(local_20);
      return _Dest;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  }
  FUN_405a7174(local_20);
  return (wchar_t *)0x0;
}



/* 40584b7c FUN_40584b7c */

/* Boundary evidence: original MIPS .pdata 40584b7c..40584d1b. Semantic name remains unreviewed. */

wchar_t * FUN_40584b7c(undefined4 param_1,int param_2)

{
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar1;
  int iVar2;
  LPWSTR pszSrc_00;
  size_t sVar3;
  wchar_t *_Dest;
  wchar_t awStack_430 [260];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  _Dest = (wchar_t *)0x0;
  if (param_2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    if ((((DAT_405a9a84 != 0) && (DAT_405a9a84 != -1)) && (DAT_405a9a88 != 0)) &&
       ((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) != 0xffffffff)) {
      pszSrc = (STRSAFE_LPCWSTR)FUN_40580ed0(param_2);
      HVar1 = StringCchCopyW(awStack_228,0x104,pszSrc);
      if ((-1 < HVar1) &&
         (iVar2 = FUN_40583ce8(param_1,awStack_228,awStack_430,0x104,(undefined4 *)0x0), iVar2 != 0)
         ) {
        pszSrc_00 = PathFindFileNameW(awStack_430);
        HVar1 = StringCchCopyW(awStack_430,0x104,pszSrc_00);
        sVar3 = wcslen(awStack_430);
        if (((-1 < HVar1) && ((sVar3 != 0 && (DAT_405aa0c8 != (int *)0x0)))) &&
           (_Dest = (wchar_t *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar3 + 1) * 2),
           _Dest != (wchar_t *)0x0)) {
          wcscpy(_Dest,awStack_430);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
      FUN_405a7174(local_20);
      return _Dest;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  }
  FUN_405a7174(local_20);
  return (wchar_t *)0x0;
}



/* 40584d1c FUN_40584d1c */

/* Boundary evidence: original MIPS .pdata 40584d1c..40584ebb. Semantic name remains unreviewed. */

undefined4 FUN_40584d1c(undefined4 param_1,int param_2,longlong *param_3)

{
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar1;
  size_t sVar2;
  size_t sVar3;
  STRSAFE_LPWSTR pszDest;
  HANDLE hFindFile;
  uint uVar4;
  uint cchDest;
  undefined4 uVar5;
  _WIN32_FIND_DATAW _Stack_460;
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  uVar5 = 0;
  if (param_2 == 0) {
    FUN_405a7174(DAT_405a9a3c);
    uVar5 = 0;
  }
  else {
    *(undefined4 *)param_3 = 0;
    *(undefined4 *)((int)param_3 + 4) = 0;
    pszSrc = (STRSAFE_LPCWSTR)FUN_40580ed0(param_2);
    HVar1 = StringCchCopyW(_Stack_460.cFileName + 0x102,0x104,pszSrc);
    if (-1 < HVar1) {
      sVar2 = wcslen(&DAT_405a9aa4);
      sVar3 = wcslen(_Stack_460.cFileName + 0x102);
      cchDest = sVar3 + sVar2 + 2;
      uVar4 = cchDest * 2;
      if (0x7fffffff < cchDest) {
        uVar4 = 0xffffffff;
      }
      pszDest = operator_new(uVar4);
      if ((((pszDest != (STRSAFE_LPWSTR)0x0) &&
           (HVar1 = StringCchCopyW(pszDest,cchDest,&DAT_405a9aa4), -1 < HVar1)) &&
          (HVar1 = StringCchCatW(pszDest,cchDest,L"\\"), -1 < HVar1)) &&
         ((HVar1 = StringCchCatW(pszDest,cchDest,_Stack_460.cFileName + 0x102), -1 < HVar1 &&
          (hFindFile = FindFirstFileW(pszDest,&_Stack_460), hFindFile != (HANDLE)0xffffffff)))) {
        *param_3 = (ulonglong)_Stack_460.nFileSizeHigh * 0xffffffff +
                   (ulonglong)_Stack_460.nFileSizeLow;
        FindClose(hFindFile);
        uVar5 = 1;
      }
      operator_delete(pszDest);
    }
    FUN_405a7174(local_28);
  }
  return uVar5;
}



/* 40584ebc FUN_40584ebc */

undefined4 FUN_40584ebc(void)

{
  return DAT_405a9a9c;
}



/* 40584ec8 FUN_40584ec8 */

/* Boundary evidence: original MIPS .pdata 40584ec8..40584f3f. Semantic name remains unreviewed. */

void FUN_40584ec8(int param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = *(HANDLE *)(param_1 + 0xc);
  if ((pvVar1 != (HANDLE)0xffffffff) && (pvVar1 != (HANDLE)0x0)) {
    FindClose(pvVar1);
  }
  pvVar1 = FindFirstFileW((LPCWSTR)&DAT_405a9eb4,(LPWIN32_FIND_DATAW)(param_1 + 0x14));
  *(HANDLE *)(param_1 + 0xc) = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}



/* 40584f40 FUN_40584f40 */

/* Boundary evidence: original MIPS .pdata 40584f40..40584fb3. Semantic name remains unreviewed. */

bool FUN_40584f40(void)

{
  HANDLE hFindFile;
  uint local_10;
  
  local_10 = DAT_405a9a3c;
  hFindFile = FindFirstFileW((LPCWSTR)&DAT_405a9eb4,(LPWIN32_FIND_DATAW)&stack0xfffffdc0);
  if (hFindFile != (HANDLE)0xffffffff) {
    FindClose(hFindFile);
  }
  FUN_405a7174(local_10);
  return hFindFile == (HANDLE)0xffffffff;
}



/* 40584fb4 FUN_40584fb4 */

/* Boundary evidence: original MIPS .pdata 40584fb4..405853d7. Semantic name remains unreviewed. */

DWORD FUN_40584fb4(undefined4 param_1,int param_2)

{
  undefined1 *puVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  STRSAFE_LPCWSTR pszSrc;
  DWORD DVar5;
  int iVar6;
  size_t sVar7;
  size_t sVar8;
  STRSAFE_LPWSTR pszDest;
  DWORD dwFileAttributes;
  DWORD DVar9;
  BOOL BVar10;
  int iVar11;
  undefined3 extraout_var;
  uint uVar12;
  uint uVar13;
  size_t cchDest;
  _SHFILEOPSTRUCTW _Stack_468;
  wchar_t wStack_448;
  undefined2 auStack_446 [263];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  puVar1 = (undefined1 *)((int)&_Stack_468.hwnd + 3);
  uVar12 = (uint)puVar1 & 3;
  puVar2 = (uint *)(puVar1 + -uVar12);
  *puVar2 = *puVar2 & -1 << (uVar12 + 1) * 8 | 0U >> (3 - uVar12) * 8;
  bVar4 = false;
  _Stack_468.hwnd = (HWND)0x0;
  memset(&_Stack_468.wFunc,0,0x1a);
  if (param_2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    if ((((DAT_405a9a84 != 0) && (DAT_405a9a84 != -1)) && (DAT_405a9a88 != 0)) &&
       ((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) != 0xffffffff)) {
      pszSrc = (STRSAFE_LPCWSTR)FUN_40580ed0(param_2);
      DVar5 = StringCchCopyW(awStack_238,0x104,pszSrc);
      if ((-1 < (int)DVar5) &&
         (iVar6 = FUN_40583ce8(param_1,awStack_238,&wStack_448,0x104,(undefined4 *)0x0), iVar6 != 0)
         ) {
        sVar7 = wcslen(&DAT_405a9aa4);
        sVar8 = wcslen(awStack_238);
        cchDest = sVar8 + sVar7 + 2;
        uVar13 = sVar8 + sVar7 + 3;
        uVar12 = uVar13 * 2;
        if (0x7fffffff < uVar13) {
          uVar12 = 0xffffffff;
        }
        pszDest = operator_new(uVar12);
        if (((pszDest != (STRSAFE_LPWSTR)0x0) &&
            (DVar5 = StringCchCopyW(pszDest,cchDest,&DAT_405a9aa4), -1 < (int)DVar5)) &&
           ((DVar5 = StringCchCatW(pszDest,cchDest,L"\\"), -1 < (int)DVar5 &&
            (DVar5 = StringCchCatW(pszDest,cchDest,awStack_238), -1 < (int)DVar5)))) {
          bVar3 = false;
          dwFileAttributes = GetFileAttributesW(pszDest);
          if (((dwFileAttributes & 1) != 0) || ((dwFileAttributes & 4) != 0)) {
            SetFileAttributesW(pszDest,0);
            bVar3 = true;
          }
          if ((((dwFileAttributes & 0x10) == 0) ||
              (DVar9 = GetFileAttributesW(&wStack_448), DVar9 == 0xffffffff)) ||
             ((DVar9 & 0x10) == 0)) {
            sVar7 = wcslen(&wStack_448);
            auStack_446[sVar7] = 0;
            sVar7 = wcslen(pszDest);
            _Stack_468.pTo = &wStack_448;
            pszDest[sVar7 + 1] = L'\0';
            _Stack_468.wFunc = 1;
            _Stack_468.fFlags._0_1_ = 4;
            _Stack_468.fFlags._1_1_ = 2;
            _Stack_468.pFrom = pszDest;
            iVar11 = SHFileOperationW(&_Stack_468);
            if ((iVar11 == 0) && (BVar10 = PathFileExistsW(pszDest), BVar10 == 0)) {
              iVar6 = CeDeleteRecord(DAT_405a9a84,iVar6);
              if (iVar6 == 0) {
                DVar5 = 0x80004005;
              }
              else {
                DVar5 = 0;
              }
              if (bVar3) {
                SetFileAttributesW(&wStack_448,dwFileAttributes);
              }
              bVar4 = true;
            }
            else if (bVar3) {
              SetFileAttributesW(pszDest,dwFileAttributes);
            }
          }
          else {
            BVar10 = RemoveDirectoryW(pszDest);
            if (BVar10 == 0) {
              DVar5 = GetLastError();
              if (0 < (int)DVar5) {
                DVar5 = DVar5 & 0xffff | 0x80070000;
              }
            }
            else {
              iVar6 = CeDeleteRecord(DAT_405a9a84,iVar6);
              if (iVar6 == 0) {
                DVar5 = 0x80004005;
              }
              else {
                DVar5 = 0;
              }
            }
          }
        }
        operator_delete(pszDest);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
      if (((bVar4) && (-1 < (int)DVar5)) &&
         (bVar4 = FUN_40584f40(), CONCAT31(extraout_var,bVar4) != 0)) {
        FUN_4058416c();
      }
      FUN_405a7174(local_30);
      return DVar5;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  }
  FUN_405a7174(local_30);
  return 0x80004005;
}



/* 405853d8 FUN_405853d8 */

/* Boundary evidence: original MIPS .pdata 405853d8..4058580b. Semantic name remains unreviewed. */

DWORD FUN_405853d8(undefined4 param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  uint *puVar3;
  bool bVar4;
  bool bVar5;
  HANDLE hFindFile;
  int iVar6;
  DWORD DVar7;
  DWORD DVar8;
  BOOL BVar9;
  size_t sVar10;
  int iVar11;
  WCHAR *lpFileName;
  DWORD DVar12;
  _SHFILEOPSTRUCTW _Stack_698;
  _WIN32_FIND_DATAW _Stack_678;
  wchar_t wStack_238;
  undefined2 auStack_236 [261];
  uint local_2c;
  
  local_2c = DAT_405a9a3c;
  puVar1 = (undefined1 *)((int)&_Stack_698.hwnd + 3);
  uVar2 = (uint)puVar1 & 3;
  puVar3 = (uint *)(puVar1 + -uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  bVar5 = false;
  _Stack_698.hwnd = (HWND)0x0;
  memset(&_Stack_698.wFunc,0,0x1a);
  DVar12 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  if ((((DAT_405a9a84 == 0) || (DAT_405a9a84 == -1)) || (DAT_405a9a88 == 0)) ||
     ((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) == 0xffffffff)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    FUN_405a7174(local_2c);
    DVar12 = 0x80004005;
  }
  else {
    hFindFile = FindFirstFileW((LPCWSTR)&DAT_405a9eb4,&_Stack_678);
    if (hFindFile != (HANDLE)0xffffffff) {
      _Stack_698.wFunc = 1;
      _Stack_698.fFlags._0_1_ = 4;
      _Stack_698.fFlags._1_1_ = 0;
      do {
        DVar12 = StringCchCopyW(_Stack_678.cFileName + 0x102,0x104,&DAT_405a9aa4);
        if (((-1 < (int)DVar12) &&
            (DVar12 = StringCchCatW(_Stack_678.cFileName + 0x102,0x104,L"\\"), -1 < (int)DVar12)) &&
           ((DVar12 = StringCchCatW(_Stack_678.cFileName + 0x102,0x104,
                                    (STRSAFE_LPCWSTR)&_Stack_678.dwReserved1), -1 < (int)DVar12 &&
            (iVar6 = FUN_40583ce8(param_1,_Stack_678.cFileName + 0x102,&wStack_238,0x104,
                                  (undefined4 *)0x0), iVar6 != 0)))) {
          bVar4 = false;
          DVar7 = GetFileAttributesW(_Stack_678.cFileName + 0x102);
          if (((DVar7 & 1) != 0) || ((DVar7 & 4) != 0)) {
            SetFileAttributesW(_Stack_678.cFileName + 0x102,0);
            bVar4 = true;
          }
          DVar8 = GetFileAttributesW(_Stack_678.cFileName + 0x102);
          if ((((DVar8 & 0x10) == 0) ||
              (DVar8 = GetFileAttributesW(&wStack_238), DVar8 == 0xffffffff)) ||
             ((DVar8 & 0x10) == 0)) {
            sVar10 = wcslen(&wStack_238);
            auStack_236[sVar10] = 0;
            sVar10 = wcslen(_Stack_678.cFileName + 0x102);
            _Stack_698.pFrom = _Stack_678.cFileName + 0x102;
            _Stack_698.pTo = &wStack_238;
            _Stack_678.cFileName[sVar10 + 0x103] = L'\0';
            iVar11 = SHFileOperationW(&_Stack_698);
            if (iVar11 == 0) {
              BVar9 = PathFileExistsW(_Stack_678.cFileName + 0x102);
              if (BVar9 != 0) {
                bVar5 = true;
                goto LAB_40585720;
              }
              iVar6 = CeDeleteRecord(DAT_405a9a84,iVar6);
              if (iVar6 == 0) {
                DVar12 = 0x80004005;
              }
              if (!bVar4) goto LAB_40585744;
              lpFileName = &wStack_238;
            }
            else {
              DVar12 = 0x80004005;
LAB_40585720:
              if (!bVar4) goto LAB_40585744;
              lpFileName = _Stack_678.cFileName + 0x102;
            }
            SetFileAttributesW(lpFileName,DVar7);
          }
          else {
            BVar9 = RemoveDirectoryW(_Stack_678.cFileName + 0x102);
            if (BVar9 == 0) {
              DVar12 = GetLastError();
              if (0 < (int)DVar12) {
                DVar12 = DVar12 & 0xffff | 0x80070000;
              }
            }
            else {
              iVar6 = CeDeleteRecord(DAT_405a9a84,iVar6);
              if (iVar6 == 0) {
                DVar12 = 0x80004005;
              }
              else {
                DVar12 = 0;
              }
            }
          }
        }
LAB_40585744:
        BVar9 = FindNextFileW(hFindFile,&_Stack_678);
      } while ((BVar9 != 0) && (-1 < (int)DVar12));
      FindClose(hFindFile);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    if ((-1 < (int)DVar12) && (!bVar5)) {
      DVar7 = FUN_40583850();
      if (DVar7 != 0) {
        DVar12 = 0x80004005;
      }
      FUN_4058416c();
    }
    FUN_405a7174(local_2c);
  }
  return DVar12;
}



/* 4058580c FUN_4058580c */

void FUN_4058580c(undefined4 param_1,undefined4 param_2)

{
  DAT_405a9aa0 = param_2;
  return;
}



/* 40585818 FUN_40585818 */

/* Boundary evidence: original MIPS .pdata 40585818..40585897. Semantic name remains unreviewed. */

undefined4 FUN_40585818(undefined4 param_1,uint param_2)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (param_2 < 0x65) {
    if (param_2 != DAT_405a9a9c) {
      FUN_40588690(param_2);
      bVar1 = param_2 < DAT_405a9a9c;
      DAT_405a9a9c = param_2;
      if (bVar1) {
        FUN_4058416c();
      }
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40585898 FUN_40585898 */

/* Boundary evidence: original MIPS .pdata 40585898..40585943. Semantic name remains unreviewed. */

undefined8 FUN_40585898(void)

{
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_28 [2];
  ULARGE_INTEGER local_20;
  ULARGE_INTEGER local_18;
  
  uVar3 = 0;
  uVar4 = 0;
  if (DAT_405aa0bc == 1) {
    local_18.s.LowPart = 0;
    local_18.s.HighPart = 0;
    BVar1 = GetDiskFreeSpaceExW((LPCWSTR)&DAT_405a9cac,&local_20,&local_18,(PULARGE_INTEGER)0x0);
    if (BVar1 != 0) {
      uVar3 = local_18.s.LowPart;
      uVar4 = local_18.s.HighPart;
    }
  }
  else {
    local_28[0] = 0;
    local_20.s.LowPart = 0;
    iVar2 = GetSystemMemoryDivision(local_28,&local_18,&local_20);
    if (iVar2 != 0) {
      uVar3 = local_20.s.LowPart * local_28[0];
      uVar4 = 0;
    }
  }
  return CONCAT44(uVar4,uVar3);
}



/* 40585944 FUN_40585944 */

/* Boundary evidence: original MIPS .pdata 40585944..40585a1b. Semantic name remains unreviewed. */

undefined4 FUN_40585944(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    if ((((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
         (param_2[3] == 0x46000000)) ||
        (((*param_2 == 0x214f2 && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) &&
       (*param_3 = (int)param_1, param_1 != (int *)0x0)) {
      (**(code **)(*param_1 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40585a1c FUN_40585a1c */

/* Boundary evidence: original MIPS .pdata 40585a1c..40585b4b. Semantic name remains unreviewed. */

int FUN_40585a1c(int param_1,undefined4 param_2,undefined4 *param_3,uint *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  BOOL BVar2;
  undefined3 extraout_var_00;
  int iVar3;
  
  if (param_3 == (undefined4 *)0x0) {
    iVar3 = -0x7ff8ffa9;
  }
  else if (*(int *)(param_1 + 0xc) == -1) {
    iVar3 = -0x7fff0001;
  }
  else if (*(int *)(param_1 + 0xc) == 0) {
    iVar3 = 1;
  }
  else {
    bVar1 = FUN_40584110(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      do {
        BVar2 = FindNextFileW(*(HANDLE *)(param_1 + 0xc),(LPWIN32_FIND_DATAW)(param_1 + 0x14));
        if (BVar2 == 0) {
          FindClose(*(HANDLE *)(param_1 + 0xc));
          iVar3 = 1;
          goto LAB_40585b0c;
        }
        bVar1 = FUN_40584110(param_1);
      } while (CONCAT31(extraout_var_00,bVar1) == 0);
    }
    iVar3 = FUN_40587d0c((STRSAFE_PCNZWCH)(param_1 + 0x3c),param_3);
    if (param_4 != (uint *)0x0) {
      *param_4 = (uint)(-1 < iVar3);
    }
    BVar2 = FindNextFileW(*(HANDLE *)(param_1 + 0xc),(LPWIN32_FIND_DATAW)(param_1 + 0x14));
    if (BVar2 == 0) {
      FindClose(*(HANDLE *)(param_1 + 0xc));
LAB_40585b0c:
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  return iVar3;
}



/* 40585b4c FUN_40585b4c */

/* Boundary evidence: original MIPS .pdata 40585b4c..40585d07. Semantic name remains unreviewed. */

DWORD FUN_40585b4c(int param_1,LPCWSTR param_2,int param_3)

{
  DWORD DVar1;
  int iVar2;
  _FILETIME _Stack_68;
  _SYSTEMTIME _Stack_60;
  undefined4 local_50;
  undefined2 local_4a;
  LPWSTR local_48;
  undefined4 local_40;
  undefined2 local_3a;
  int local_38;
  undefined4 local_30;
  undefined2 local_2a;
  _FILETIME _Stack_28;
  
  if ((param_2 == (LPCWSTR)0x0) || (param_3 == 0)) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = FUN_405841c8(param_1);
    if (DVar1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
      if ((((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) != 0xffffffff) &&
          (DAT_405a9a84 != -1)) && (DAT_405a9a88 != 0)) {
        local_4a = 0;
        local_50 = 0x1021001f;
        local_48 = PathFindFileNameW(param_2);
        local_40 = 0x1022001f;
        local_3a = 0;
        local_30 = 0x10230040;
        local_2a = 0;
        local_38 = param_3;
        GetLocalTime(&_Stack_60);
        SystemTimeToFileTime(&_Stack_60,&_Stack_68);
        LocalFileTimeToFileTime(&_Stack_68,&_Stack_28);
        iVar2 = CeSeekDatabaseEx(DAT_405a9a84,0x20,&local_50,1,0);
        if (iVar2 == 0) {
          iVar2 = CeWriteRecordProps(DAT_405a9a84,0,3,&local_50);
          if (iVar2 == 0) {
            DVar1 = GetLastError();
          }
          else if (DAT_405a9508 != 0) {
            CeFlushDBVol(&DAT_405a9a8c);
          }
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    }
  }
  return DVar1;
}



/* 40585d08 FUN_40585d08 */

/* Boundary evidence: original MIPS .pdata 40585d08..40585e2b. Semantic name remains unreviewed. */

undefined4 FUN_40585d08(undefined4 param_1,HANDLE param_2,DWORD *param_3)

{
  DWORD DVar1;
  uint uVar2;
  undefined4 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint local_1c;
  
  uVar3 = 0;
  memset(&local_1c,0,4);
  *param_3 = 0;
  param_3[1] = 0;
  if ((param_2 == (HANDLE)0x0) || (param_2 == (HANDLE)0xffffffff)) {
    uVar3 = 0;
  }
  else {
    DVar1 = GetFileSize(param_2,&local_1c);
    if (DVar1 != 0xffffffff) {
      lVar4 = FUN_40585898();
      if (lVar4 != 0) {
        *param_3 = DVar1;
        param_3[1] = local_1c;
        uVar5 = __ull_div((int)lVar4,(int)((ulonglong)lVar4 >> 0x20),100,0);
        lVar4 = (uVar5 & 0xffffffff) * (ulonglong)DAT_405a9a9c;
        uVar2 = (int)(uVar5 >> 0x20) * DAT_405a9a9c + (int)((ulonglong)lVar4 >> 0x20);
        if ((local_1c <= uVar2) && ((local_1c != uVar2 || (DVar1 <= (uint)lVar4)))) {
          uVar3 = 1;
        }
      }
    }
  }
  return uVar3;
}



/* 40585e2c FUN_40585e2c */

/* Boundary evidence: original MIPS .pdata 40585e2c..40585ff3. Semantic name remains unreviewed. */

HRESULT FUN_40585e2c(undefined4 param_1)

{
  int iVar1;
  HRESULT HVar2;
  wchar_t *pszSrc;
  
  HVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  pszSrc = &DAT_405a9aa4;
  if (DAT_405a9aa4 != 0) goto LAB_40585fc4;
  DAT_405aa0bc = FUN_40583c2c(param_1,(HKEY)0x80000002,L"Explorer",L"RecycleBinEnableDBFile",0);
  if (DAT_405aa0bc == 1) {
    iVar1 = FUN_40583c2c(param_1,(HKEY)0x80000002,L"Explorer",L"RecycleBinFlush",0);
    DAT_405a9508 = (uint)(iVar1 != 0);
    iVar1 = SHGetSpecialFolderPath(0,&DAT_405a9cac,0x28,0);
    if (iVar1 == 0) {
      HVar2 = -0x7fffbffb;
      goto LAB_40585fc4;
    }
    HVar2 = StringCchCopyW(&DAT_405a9aa4,0x104,(STRSAFE_LPCWSTR)&DAT_405a9cac);
    if ((HVar2 < 0) || (HVar2 = StringCchCatW(&DAT_405a9aa4,0x104,L"\\Recycled"), HVar2 < 0))
    goto LAB_40585fc4;
  }
  else {
    HVar2 = StringCchCopyW(&DAT_405a9aa4,0x104,L"\\Recycled");
    if (HVar2 < 0) goto LAB_40585fc4;
    pszSrc = L"\\Recycled";
  }
  HVar2 = StringCchCopyW((STRSAFE_LPWSTR)&DAT_405a9eb4,0x104,pszSrc);
  if (-1 < HVar2) {
    HVar2 = StringCchCatW((STRSAFE_LPWSTR)&DAT_405a9eb4,0x104,L"\\*.*");
  }
LAB_40585fc4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  return HVar2;
}



/* 40585ff4 FUN_40585ff4 */

/* Boundary evidence: original MIPS .pdata 40585ff4..405860d3. Semantic name remains unreviewed. */

HRESULT FUN_40585ff4(int param_1)

{
  HRESULT HVar1;
  DWORD DVar2;
  BOOL BVar3;
  LPCWSTR lpText;
  
  HVar1 = FUN_40585e2c(param_1);
  if (HVar1 < 0) {
    lpText = (LPCWSTR)LoadStringW(DAT_405aa0c0,0xc086,(LPWSTR)0x0,0);
    MessageBoxW((HWND)0x0,lpText,(LPCWSTR)0x0,0x10010);
  }
  else {
    DVar2 = GetFileAttributesW(&DAT_405a9aa4);
    if ((DVar2 == 0xffffffff) &&
       (BVar3 = CreateDirectoryW(&DAT_405a9aa4,(LPSECURITY_ATTRIBUTES)0x0), BVar3 != 0)) {
      SetFileAttributesW(&DAT_405a9aa4,6);
    }
    FUN_405841c8(param_1);
  }
  return HVar1;
}



/* 405860d4 FUN_405860d4 */

/* Boundary evidence: original MIPS .pdata 405860d4..405865cb. Semantic name remains unreviewed. */

uint FUN_405860d4(int param_1,LPCWSTR param_2,undefined4 *param_3)

{
  bool bVar1;
  DWORD DVar2;
  HANDLE hObject;
  int iVar3;
  LPCWSTR pWVar4;
  HWND hWnd;
  STRSAFE_LPWSTR pszDest;
  STRSAFE_LPCWSTR pszFormat;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  LPWSTR pWVar5;
  undefined3 extraout_var;
  BOOL BVar6;
  code *pcVar7;
  uint uVar8;
  DWORD DVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  ulonglong uVar13;
  INT_PTR local_48;
  LPCWSTR local_44;
  undefined4 local_40 [2];
  uint local_38;
  int local_34;
  DWORD local_30;
  int local_2c;
  
  local_48 = 6;
  local_40[0] = 0;
  local_44 = (LPCWSTR)0x0;
  local_30 = 0;
  local_2c = 0;
  DVar9 = 0;
  if (((param_2 == (LPCWSTR)0x0) || (param_3 == (undefined4 *)0x0)) ||
     (DVar2 = GetFileAttributesW(param_2), DVar2 == 0xffffffff)) {
    return 0x80004005;
  }
  if ((DVar2 & 0x10) == 0) {
    hObject = CreateFileW(param_2,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (hObject != (HANDLE)0xffffffff) {
      iVar3 = FUN_40585d08(param_1,hObject,&local_30);
      if (iVar3 == 0) {
        CloseHandle(hObject);
        DVar9 = FUN_4058b140(param_2,(HWND)0x0,1,&local_48);
        if (-1 < (int)DVar9) {
          if (local_48 == 2) goto LAB_40586444;
          pcVar7 = DeleteFileW_exref;
          if (local_48 != 6) goto LAB_40586438;
LAB_405864f8:
          iVar3 = (*pcVar7)(param_2);
          if (iVar3 != 0) {
            return 1;
          }
          DVar9 = GetLastError();
          if (0 < (int)DVar9) {
            DVar9 = DVar9 & 0xffff | 0x80070000;
          }
        }
        goto LAB_4058644c;
      }
      CloseHandle(hObject);
      lVar12 = FUN_40585898();
      local_38 = 0;
      local_34 = 0;
      FUN_40584010(param_1,&local_38);
      uVar11 = local_38 + local_30;
      uVar10 = local_34 + local_2c + (uint)(uVar11 < local_38);
      if (lVar12 != 0) {
        uVar13 = __ull_div((int)lVar12,(int)((ulonglong)lVar12 >> 0x20),100,0);
        lVar12 = (uVar13 & 0xffffffff) * (ulonglong)DAT_405a9a9c;
        uVar8 = (int)(uVar13 >> 0x20) * DAT_405a9a9c + (int)((ulonglong)lVar12 >> 0x20);
        if ((uVar8 <= uVar10) && ((uVar10 != uVar8 || ((uint)lVar12 < uVar11)))) {
          pWVar4 = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x305a,(LPWSTR)0x0,0);
          hWnd = FindWindowW(L"Dialog",pWVar4);
          if (hWnd == (HWND)0x0) {
            pszDest = LocalAlloc(0,0x208);
            if (pszDest != (STRSAFE_LPWSTR)0x0) {
              pWVar5 = PathFindFileNameW(param_2);
              pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0xc06b,(LPWSTR)0x0,0);
              DVar9 = StringCchPrintfExW(pszDest,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,
                                         pszFormat,pWVar5);
              if (-1 < (int)DVar9) {
                hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2313,(LPCWSTR)0x5);
                hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
                local_48 = DialogBoxIndirectParamW
                                     (DAT_405aa0c0,hDialogTemplate,(HWND)0x0,FUN_4058a468,
                                      (LPARAM)pszDest);
                if (local_48 == 2) {
                  DVar9 = 0x800704c7;
                }
              }
            }
            LocalFree(pszDest);
            goto LAB_4058644c;
          }
          SetForegroundWindow(hWnd);
        }
      }
    }
  }
  else if (DAT_405a9a9c == 0) {
    DVar9 = FUN_4058b140(param_2,(HWND)0x0,1,&local_48);
    if (-1 < (int)DVar9) {
      if (local_48 != 2) {
        pcVar7 = RemoveDirectoryW_exref;
        if (local_48 == 6) goto LAB_405864f8;
LAB_40586438:
        if (local_48 != 7) goto LAB_4058644c;
      }
LAB_40586444:
      DVar9 = 0x800704c7;
    }
LAB_4058644c:
    if (DVar9 != 0) {
      return DVar9;
    }
  }
  uVar10 = 0;
  pWVar5 = PathFindExtensionW(param_2);
  iVar3 = FUN_40583e8c(param_1,DVar2,pWVar5,&local_44);
  if (iVar3 != 0) goto LAB_40586590;
  bVar1 = FUN_40584f40();
  pWVar4 = local_44;
  BVar6 = MoveFileW(param_2,local_44);
  if (BVar6 == 0) {
    uVar10 = GetLastError();
LAB_40586570:
    if (0 < (int)uVar10) {
      uVar10 = uVar10 & 0xffff | 0x80070000;
    }
  }
  else {
    DVar9 = FUN_40585b4c(param_1,pWVar4,(int)param_2);
    if (DVar9 == 0) {
      pWVar5 = PathFindFileNameW(pWVar4);
      iVar3 = FUN_40587d0c(pWVar5,local_40);
      if ((-1 < iVar3) && (CONCAT31(extraout_var,bVar1) != 0)) {
        FUN_4058416c();
      }
    }
    else {
      BVar6 = MoveFileW(pWVar4,param_2);
      if (BVar6 == 0) {
        uVar10 = GetLastError();
        goto LAB_40586570;
      }
    }
  }
  operator_delete(pWVar4);
LAB_40586590:
  *param_3 = local_40[0];
  return uVar10;
}



/* 405865cc FUN_405865cc */

/* Boundary evidence: original MIPS .pdata 405865cc..4058689b. Semantic name remains unreviewed. */

int FUN_405865cc(undefined4 param_1,int param_2)

{
  bool bVar1;
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  STRSAFE_LPWSTR pszDest;
  DWORD DVar6;
  undefined3 extraout_var;
  uint uVar7;
  uint cchDest;
  int iVar8;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  iVar8 = 0;
  if (param_2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
    if ((((DAT_405a9a84 != 0) && (DAT_405a9a84 != -1)) && (DAT_405a9a88 != 0)) &&
       ((DAT_405a9a98 & DAT_405a9a94 & DAT_405a9a90 & DAT_405a9a8c) != 0xffffffff)) {
      pszSrc = (STRSAFE_LPCWSTR)FUN_40580ed0(param_2);
      HVar2 = StringCchCopyW(awStack_238,0x104,pszSrc);
      if ((-1 < HVar2) &&
         (iVar3 = FUN_40583ce8(param_1,awStack_238,(STRSAFE_LPWSTR)0x0,0,(undefined4 *)0x0),
         iVar3 != 0)) {
        sVar4 = wcslen(&DAT_405a9aa4);
        sVar5 = wcslen(awStack_238);
        cchDest = sVar5 + sVar4 + 2;
        uVar7 = cchDest * 2;
        if (0x7fffffff < cchDest) {
          uVar7 = 0xffffffff;
        }
        pszDest = operator_new(uVar7);
        if (((pszDest != (STRSAFE_LPWSTR)0x0) &&
            (HVar2 = StringCchCopyW(pszDest,cchDest,&DAT_405a9aa4), -1 < HVar2)) &&
           ((HVar2 = StringCchCatW(pszDest,cchDest,L"\\"), -1 < HVar2 &&
            ((HVar2 = StringCchCatW(pszDest,cchDest,awStack_238), -1 < HVar2 &&
             (DVar6 = GetFileAttributesW(pszDest), DVar6 != 0xffffffff)))))) {
          if ((DVar6 & 1) != 0) {
            SetFileAttributesW(pszDest,0);
          }
          if ((DVar6 & 0x10) == 0) {
            iVar8 = DeleteFileW(pszDest);
          }
          else {
            iVar8 = RemoveDirectoryW(pszDest);
          }
          if ((iVar8 != 0) && (iVar3 = CeDeleteRecord(DAT_405a9a84,iVar3), iVar3 != 0)) {
            HVar2 = 0;
          }
        }
        operator_delete(pszDest);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
      if (((iVar8 != 0) && (-1 < HVar2)) &&
         (bVar1 = FUN_40584f40(), CONCAT31(extraout_var,bVar1) != 0)) {
        FUN_4058416c();
      }
      FUN_405a7174(local_30);
      return HVar2;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405a9a68);
  }
  FUN_405a7174(local_30);
  return -0x7fffbffb;
}



/* 4058689c FUN_4058689c */

/* Boundary evidence: original MIPS .pdata 4058689c..40586983. Semantic name remains unreviewed. */

undefined4 FUN_4058689c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint local_20;
  uint local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if (DAT_405a9a9c != 0) {
    FUN_40584010(param_1,&local_20);
    uVar2 = local_1c;
    uVar1 = local_20;
    if (local_20 == 0 && local_1c == 0) {
      return 0;
    }
    lVar4 = FUN_40585898();
    if (lVar4 == 0) {
      return 0;
    }
    uVar5 = __ull_div((int)lVar4,(int)((ulonglong)lVar4 >> 0x20),100,0);
    lVar4 = (uVar5 & 0xffffffff) * (ulonglong)DAT_405a9a9c;
    uVar3 = (int)(uVar5 >> 0x20) * DAT_405a9a9c + (int)((ulonglong)lVar4 >> 0x20);
    if (uVar2 < uVar3) {
      return 0;
    }
    if ((uVar2 == uVar3) && (uVar1 <= (uint)lVar4)) {
      return 0;
    }
  }
  return 1;
}



/* 40586984 FUN_40586984 */

/* Boundary evidence: original MIPS .pdata 40586984..405869bb. Semantic name remains unreviewed. */

int FUN_40586984(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2] + -1;
  param_1[2] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_40571918;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 405869bc FUN_405869bc */

/* Boundary evidence: original MIPS .pdata 405869bc..40586a27. Semantic name remains unreviewed. */

undefined4 * FUN_405869bc(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = &PTR_FUN_40571918;
  param_1[1] = 20000;
  param_1[2] = 0;
  param_1[3] = 0xffffffff;
  param_1[4] = param_2;
  DAT_405a9a9c = FUN_405885d8();
  memset(param_1 + 5,0,0x230);
  param_1[2] = 1;
  return param_1;
}



/* 40586a28 FUN_40586a28 */

/* Boundary evidence: original MIPS .pdata 40586a28..40586a67. Semantic name remains unreviewed. */

void FUN_40586a28(int param_1,int param_2)

{
  FUN_40585ff4(param_1);
  if (param_2 != 0) {
    *(int *)(param_1 + 0x10) = param_2;
  }
  return;
}



/* 40586a68 FUN_40586a68 */

/* Boundary evidence: original MIPS .pdata 40586a68..40586bdf. Semantic name remains unreviewed. */

void FUN_40586a68(void)

{
  undefined4 *puVar1;
  int *piVar2;
  void *pvVar3;
  
  piVar2 = DAT_405aa0cc;
  if (DAT_405aa0cc != (int *)0x0) {
    FUN_4058e978(DAT_405aa0cc);
    operator_delete(piVar2);
    DAT_405aa0cc = (int *)0x0;
  }
  if (DAT_405aa0d4 != (int *)0x0) {
    FUN_405836f0();
    (**(code **)(*DAT_405aa0d4 + 8))();
    DAT_405aa0d4 = (int *)0x0;
  }
  puVar1 = DAT_405a9a64;
  if (DAT_405a9a64 != (undefined4 *)0x0) {
    FUN_40581e58(DAT_405a9a64);
    operator_delete(puVar1);
    DAT_405a9a64 = (undefined4 *)0x0;
  }
  puVar1 = DAT_405a9a4c;
  if (DAT_405a9a4c != (undefined4 *)0x0) {
    FUN_40572e98(DAT_405a9a4c);
    operator_delete(puVar1);
    DAT_405a9a4c = (undefined4 *)0x0;
  }
  pvVar3 = DAT_405aa0d8;
  if (DAT_405aa0d8 != (void *)0x0) {
    FUN_40587acc((int)DAT_405aa0d8);
    operator_delete(pvVar3);
    DAT_405aa0d8 = (void *)0x0;
  }
  if (DAT_405aa300 != (int *)0x0) {
    (**(code **)(*DAT_405aa300 + 8))();
    DAT_405aa300 = (int *)0x0;
  }
  if (DAT_405aa0c8 != (int *)0x0) {
    (**(code **)(*DAT_405aa0c8 + 8))();
    DAT_405aa0c8 = (int *)0x0;
  }
  if (DAT_405aa0c4 != 0) {
    FreeLibrary((HMODULE)DAT_405aa0c4);
    DAT_405aa0c4 = 0;
  }
  FUN_405a6b10();
  return;
}



/* 40586be0 FUN_40586be0 */

/* Boundary evidence: original MIPS .pdata 40586be0..40586d27. Semantic name remains unreviewed. */

undefined4 FUN_40586be0(void)

{
  HRESULT HVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  HVar1 = SHGetMalloc((IMalloc **)&DAT_405aa0c8);
  if (HVar1 < 0) {
LAB_40586cd4:
    uVar3 = 0;
  }
  else {
    puVar2 = operator_new(0x130);
    if (puVar2 == (undefined4 *)0x0) {
      DAT_405aa0cc = (undefined4 *)0x0;
    }
    else {
      DAT_405aa0cc = FUN_4058e1a4(puVar2);
    }
    if (DAT_405aa0cc == (undefined4 *)0x0) {
      uVar3 = 0;
      FUN_40586a68();
      goto LAB_40586cd8;
    }
    if (DAT_405a9aa4 == 0) {
      puVar2 = operator_new(0x244);
      if (puVar2 == (undefined4 *)0x0) {
        DAT_405aa0d4 = (undefined4 *)0x0;
      }
      else {
        DAT_405aa0d4 = FUN_405869bc(puVar2,0);
      }
      if (DAT_405aa0d4 == (undefined4 *)0x0) {
        FUN_40586a68();
        goto LAB_40586cd4;
      }
      FUN_40583690();
      FUN_40588820();
    }
    puVar2 = operator_new(0x50);
    if (puVar2 == (undefined4 *)0x0) {
      DAT_405aa0d8 = (undefined4 *)0x0;
    }
    else {
      DAT_405aa0d8 = FUN_40587a14(puVar2);
    }
    DAT_405aa0c4 = LoadLibraryExW(L"ceshell.dll",(HANDLE)0x0,2);
  }
LAB_40586cd8:
  FUN_405a6ae0();
  return uVar3;
}



/* 40586d28 FUN_40586d28 */

/* Boundary evidence: original MIPS .pdata 40586d28..40586d73. Semantic name remains unreviewed. */

undefined4 FUN_40586d28(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_2 == 0) {
    FUN_40586a68();
  }
  else if (param_2 == 1) {
    DAT_405aa0c0 = param_1;
    uVar1 = FUN_40586be0();
  }
  return uVar1;
}



/* 40586d74 FUN_40586d74 */

/* Boundary evidence: original MIPS .pdata 40586d74..40586e4b. Semantic name remains unreviewed. */

undefined4 FUN_40586d74(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    if ((((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
         (param_2[3] == 0x46000000)) ||
        (((*param_2 == 1 && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) &&
       (*param_3 = (int)param_1, param_1 != (int *)0x0)) {
      (**(code **)(*param_1 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40586e4c FUN_40586e4c */

/* Boundary evidence: original MIPS .pdata 40586e4c..405870e7. Semantic name remains unreviewed. */

undefined4 FUN_40586e4c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_2 != 0) {
    return 0x80040110;
  }
  if ((((*(int *)(param_1 + 8) == 0x214a1) && (*(int *)(param_1 + 0xc) == 0)) &&
      (*(int *)(param_1 + 0x10) == 0xc0)) && (*(int *)(param_1 + 0x14) == 0x46000000)) {
    puVar1 = operator_new(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    piVar2 = FUN_40593360(puVar1);
  }
  else if (((*(int *)(param_1 + 8) == 0x21400) && (*(int *)(param_1 + 0xc) == 0)) &&
          ((*(int *)(param_1 + 0x10) == 0xc0 && (*(int *)(param_1 + 0x14) == 0x46000000)))) {
    puVar1 = operator_new(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    piVar2 = FUN_405922a0(puVar1);
  }
  else if (((*(int *)(param_1 + 8) == 0x214a0) && (*(int *)(param_1 + 0xc) == 0)) &&
          ((*(int *)(param_1 + 0x10) == 0xc0 && (*(int *)(param_1 + 0x14) == 0x46000000)))) {
    puVar1 = operator_new(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    piVar2 = FUN_40590040(puVar1);
  }
  else if ((((*(int *)(param_1 + 8) == 0x214a2) && (*(int *)(param_1 + 0xc) == 0)) &&
           (*(int *)(param_1 + 0x10) == 0xc0)) && (*(int *)(param_1 + 0x14) == 0x46000000)) {
    puVar1 = operator_new(0xc);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    piVar2 = FUN_405908f8(puVar1);
  }
  else {
    if (((*(int *)(param_1 + 8) != 0x56fdf344) || (*(int *)(param_1 + 0xc) != 0x11d0fd6d)) ||
       ((*(int *)(param_1 + 0x10) != 0x60008a95 || (*(int *)(param_1 + 0x14) != -0x6f5f3669)))) {
      return 0x80004002;
    }
    puVar1 = operator_new(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    piVar2 = FUN_405a5d70(puVar1);
  }
  if (piVar2 == (int *)0x0) {
    return 0x8007000e;
  }
  uVar3 = (**(code **)*piVar2)(piVar2,param_3,param_4);
  (**(code **)(*piVar2 + 8))(piVar2);
  return uVar3;
}



/* 405870e8 FUN_405870e8 */

/* Boundary evidence: original MIPS .pdata 405870e8..4058711f. Semantic name remains unreviewed. */

int FUN_405870e8(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_40571954;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40587120 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40587120..40587357. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  HRESULT HVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  
                    /* 0x17120  20  DllGetClassObject */
  uVar8 = rclsid->Data1;
  if (((((uVar8 == 0x214a1) &&
        (iVar3._0_2_ = rclsid->Data2, iVar3._2_2_ = rclsid->Data3, iVar3 == 0)) &&
       (*(int *)rclsid->Data4 == 0xc0)) && (*(int *)(rclsid->Data4 + 4) == 0x46000000)) ||
     (((((uVar8 == 0x21400 && (iVar4._0_2_ = rclsid->Data2, iVar4._2_2_ = rclsid->Data3, iVar4 == 0)
         ) && ((*(int *)rclsid->Data4 == 0xc0 && (*(int *)(rclsid->Data4 + 4) == 0x46000000)))) ||
       (((uVar8 == 0x214a0 && (iVar5._0_2_ = rclsid->Data2, iVar5._2_2_ = rclsid->Data3, iVar5 == 0)
         ) && ((*(int *)rclsid->Data4 == 0xc0 && (*(int *)(rclsid->Data4 + 4) == 0x46000000)))))) ||
      (((((uVar8 == 0x214a2 &&
          (iVar6._0_2_ = rclsid->Data2, iVar6._2_2_ = rclsid->Data3, iVar6 == 0)) &&
         (*(int *)rclsid->Data4 == 0xc0)) && (*(int *)(rclsid->Data4 + 4) == 0x46000000)) ||
       (((uVar8 == 0x56fdf344 &&
         (iVar7._0_2_ = rclsid->Data2, iVar7._2_2_ = rclsid->Data3, iVar7 == 0x11d0fd6d)) &&
        ((*(int *)rclsid->Data4 == 0x60008a95 && (*(int *)(rclsid->Data4 + 4) == -0x6f5f3669))))))))
     )) {
    piVar1 = operator_new(0x18);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      *piVar1 = (int)&PTR_FUN_40571954;
      piVar1[1] = 1;
      piVar1[2] = rclsid->Data1;
      piVar1[3] = *(int *)&rclsid->Data2;
      piVar1[4] = *(int *)rclsid->Data4;
      piVar1[5] = *(int *)(rclsid->Data4 + 4);
    }
    if (piVar1 == (int *)0x0) {
      HVar2 = -0x7ff8fff2;
    }
    else {
      HVar2 = (**(code **)*piVar1)(piVar1,riid,ppv);
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  else {
    HVar2 = -0x7ffbfeef;
  }
  return HVar2;
}



/* 40587358 SHGetDesktopFolder */

/* Boundary evidence: original MIPS .pdata 40587358..405873b7. Semantic name remains unreviewed. */

HRESULT SHGetDesktopFolder(IShellFolder **ppshf)

{
  undefined4 *puVar1;
  IShellFolder *pIVar2;
  HRESULT HVar3;
  
                    /* 0x17358  9  SHGetDesktopFolder */
  puVar1 = operator_new(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    pIVar2 = (IShellFolder *)0x0;
  }
  else {
    pIVar2 = (IShellFolder *)FUN_405922a0(puVar1);
  }
  if (pIVar2 == (IShellFolder *)0x0) {
    HVar3 = -0x7ff8fff2;
  }
  else {
    *ppshf = pIVar2;
    HVar3 = 0;
  }
  return HVar3;
}



/* 405873b8 FUN_405873b8 */

/* Boundary evidence: original MIPS .pdata 405873b8..40587697. Semantic name remains unreviewed. */

uint * FUN_405873b8(STRSAFE_PCNZWCH param_1,STRSAFE_PCNZWCH param_2,uint param_3,LPCWSTR param_4,
                   int param_5)

{
  ushort uVar1;
  HRESULT HVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  uint *puVar11;
  size_t local_2f0;
  size_t local_2ec;
  size_t local_2e8 [2];
  undefined4 local_2e0;
  undefined1 auStack_2dc [528];
  wchar_t awStack_cc [80];
  uint local_2c;
  
  local_2c = DAT_405a9a3c;
  local_2ec = 0;
  local_2e8[0] = 0;
  HVar2 = StringCchLengthW(param_1,0x104,&local_2ec);
  puVar11 = (uint *)0x0;
  if (-1 < HVar2) {
    if ((param_1 == param_2) || (HVar2 = StringCchLengthW(param_2,0x104,local_2e8), HVar2 < 0)) {
      param_2 = (wchar_t *)0x0;
    }
    uVar6 = (local_2ec + 5) * 2;
    uVar5 = uVar6 & 3;
    iVar4 = 4 - uVar5;
    if (uVar5 == 0) {
      iVar4 = 0;
    }
    uVar6 = iVar4 + uVar6;
    uVar5 = uVar6;
    uVar7 = 8;
    if (param_2 != (wchar_t *)0x0) {
      uVar5 = (local_2e8[0] + 1) * 2 + uVar6;
      uVar7 = uVar5 & 3;
      if (uVar7 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = 4 - uVar7;
      }
      uVar5 = iVar4 + uVar5;
      uVar7 = uVar6;
    }
    local_2e0 = 0;
    memset(auStack_2dc,0,0x2b0);
    local_2f0 = 0;
    uVar6 = uVar5;
    if ((param_5 != 0) &&
       (((uVar6 = uVar5 + 8, (param_3 & 0x1000) == 0 || ((param_3 & 1) == 0)) &&
        (uVar6 = uVar5 + 0x10, param_4 != (LPCWSTR)0x0)))) {
      iVar4 = SHGetFileInfo(param_4,0,&local_2e0,0x2b4,0x400);
      if ((iVar4 != 0) && (HVar2 = StringCchLengthW(awStack_cc,0x50,&local_2f0), -1 < HVar2)) {
        uVar6 = (local_2f0 + 1) * 2 + uVar6;
        uVar8 = uVar6 & 3;
        if (uVar8 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = 4 - uVar8;
        }
        uVar6 = iVar4 + uVar6;
      }
    }
    puVar3 = LocalAlloc(0x40,uVar6 + 2);
    if (puVar3 != (uint *)0x0) {
      *(short *)puVar3 = (short)uVar6;
      puVar3[1] = uVar5 << 0x10 | uVar7 & 0xffff | puVar3[1];
      uVar5 = param_3 & 0xf0ff;
      wcscpy((wchar_t *)(puVar3 + 2),param_1);
      if (param_2 != (wchar_t *)0x0) {
        wcscpy((wchar_t *)((uint)(ushort)puVar3[1] + (int)puVar3),param_2);
      }
      uVar6 = uVar5;
      if (param_5 != 0) {
        puVar9 = (undefined4 *)((uint)*(ushort *)((int)puVar3 + 6) + (int)puVar3);
        *puVar9 = *(undefined4 *)(param_5 + 0x14);
        uVar6 = uVar5 | 0x100;
        puVar9[1] = *(undefined4 *)(param_5 + 0x18);
        if (((param_3 & 0x1000) == 0) || ((param_3 & 1) == 0)) {
          uVar1 = *(ushort *)((int)puVar3 + 6);
          uVar10 = *(undefined4 *)(param_5 + 0x1c);
          uVar6 = uVar5 | 0x300;
          *(undefined4 *)((int)puVar3 + uVar1 + 8) = *(undefined4 *)(param_5 + 0x20);
          *(undefined4 *)((int)puVar3 + uVar1 + 0xc) = uVar10;
          if (local_2f0 != 0) {
            wcscpy((wchar_t *)((int)puVar3 + *(ushort *)((int)puVar3 + 6) + 0x10),awStack_cc);
            uVar6 = uVar5 | 0x700;
          }
        }
      }
      *puVar3 = uVar6 << 0x10 | *puVar3;
      puVar11 = puVar3;
    }
  }
  FUN_405a7174(local_2c);
  return puVar11;
}



/* 40587698 FUN_40587698 */

/* Boundary evidence: original MIPS .pdata 40587698..40587713. Semantic name remains unreviewed. */

void FUN_40587698(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  wchar_t *pszSrc;
  size_t local_10 [2];
  
  HVar1 = StringCchLengthW(param_1,0x104,local_10);
  if (-1 < HVar1) {
    if ((local_10[0] == 0) || (param_1[local_10[0] - 1] != L'\\')) {
      pszSrc = L"\\desktop.ini";
    }
    else {
      pszSrc = L"desktop.ini";
    }
    StringCchCatW(param_1,0x104,pszSrc);
  }
  return;
}



/* 40587714 FUN_40587714 */

/* Boundary evidence: original MIPS .pdata 40587714..40587a13. Semantic name remains unreviewed. */

int FUN_40587714(LPCITEMIDLIST param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined2 extraout_var;
  LPCITEMIDLIST pIVar3;
  int iVar4;
  HANDLE hFindFile;
  int iVar5;
  HRESULT HVar6;
  uint *puVar7;
  uint uVar8;
  WCHAR *_Str1;
  LPCWSTR pWVar9;
  _WIN32_FIND_DATAW local_670;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  if ((((param_1 == (LPCITEMIDLIST)0x0) || (param_2 == (int *)0x0)) ||
      (iVar2 = FUN_40580fe8((char *)*param_2), iVar2 != 0)) ||
     ((uVar1 = FUN_4058114c((char *)*param_2), CONCAT22(extraout_var,uVar1) == 0 ||
      (iVar2 = FUN_40581410((ushort *)*param_2), iVar2 != 1)))) {
    FUN_405a7174(local_30);
    return -0x7ff8ffa9;
  }
  iVar2 = 0;
  pIVar3 = FUN_405812ec((ushort *)param_1,(ushort *)*param_2);
  if (pIVar3 == (LPCITEMIDLIST)0x0) {
    iVar2 = -0x7ff8fff2;
    goto LAB_405879c0;
  }
  iVar4 = SHGetPathFromIDList(pIVar3,awStack_238);
  if (iVar4 == 0) {
LAB_405879a0:
    iVar2 = -0x7fffbffb;
  }
  else {
    local_670.dwFileAttributes = 0;
    memset(&local_670.ftCreationTime,0,0x22c);
    hFindFile = FindFirstFileW(awStack_238,&local_670);
    if (hFindFile == (HANDLE)0xffffffff) goto LAB_405879a0;
    iVar4 = *param_2;
    uVar8 = (uint)*(ushort *)(iVar4 + 2);
    _Str1 = (WCHAR *)((uint)*(ushort *)(iVar4 + 4) + iVar4);
    pWVar9 = awStack_238;
    if ((local_670.dwFileAttributes & 0x10) == 0) {
      iVar5 = PathIsLink(awStack_238);
      if (iVar5 != 0) {
        uVar8 = uVar8 | 2;
        iVar5 = SHGetPathFromIDList(param_1,local_670.cFileName + 0x102);
        if (((iVar5 != 0) && (iVar2 = FUN_40587698(local_670.cFileName + 0x102), -1 < iVar2)) &&
           ((iVar5 = FUN_4058da84(L"[LocalizedFileNames]",(wchar_t *)(iVar4 + 8),
                                  local_670.cFileName + 0x102,0x104,local_670.cFileName + 0x102),
            iVar5 != 0 &&
            (HVar6 = SHLoadIndirectString
                               (local_670.cFileName + 0x102,local_670.cFileName + 0x102,0x104,
                                (void **)0x0), -1 < HVar6)))) goto LAB_40587938;
      }
    }
    else {
      uVar8 = uVar8 | 1;
      pWVar9 = (LPCWSTR)0x0;
      wcscpy(local_670.cFileName + 0x102,awStack_238);
      iVar2 = FUN_40587698(local_670.cFileName + 0x102);
      if ((((-1 < iVar2) &&
           (iVar5 = FUN_4058da84(L"[.ShellClassInfo]",L"LocalizedResourceName",
                                 local_670.cFileName + 0x102,0x104,local_670.cFileName + 0x102),
           iVar5 != 0)) &&
          (HVar6 = SHLoadIndirectString
                             (local_670.cFileName + 0x102,local_670.cFileName + 0x102,0x104,
                              (void **)0x0), -1 < HVar6)) &&
         (iVar5 = wcscmp(_Str1,local_670.cFileName + 0x102), iVar5 != 0)) {
LAB_40587938:
        _Str1 = local_670.cFileName + 0x102;
      }
    }
    if ((uVar8 & 0xf00) == 0) {
      puVar7 = FUN_405873b8((wchar_t *)(iVar4 + 8),_Str1,uVar8,pWVar9,(int)&local_670);
      if (puVar7 == (uint *)0x0) {
        iVar2 = -0x7ff8fff2;
      }
      else {
        FUN_40580ef4((HLOCAL)*param_2);
        *param_2 = (int)puVar7;
      }
    }
    FindClose(hFindFile);
  }
  FUN_40580ef4(pIVar3);
LAB_405879c0:
  FUN_405a7174(local_30);
  return iVar2;
}



/* 40587a14 FUN_40587a14 */

undefined4 * FUN_40587a14(undefined4 *param_1)

{
  *param_1 = 0x21400;
  param_1[1] = 0;
  param_1[2] = 0xc0;
  param_1[3] = 0x46000000;
  param_1[4] = 0;
  param_1[5] = 0x214a0;
  param_1[6] = 0;
  param_1[7] = 0xc0;
  param_1[8] = 0x46000000;
  param_1[9] = 0;
  param_1[10] = 0x214a1;
  param_1[0xb] = 0;
  param_1[0xc] = 0xc0;
  param_1[0xd] = 0x46000000;
  param_1[0xe] = 0;
  param_1[0xf] = 0x214a2;
  param_1[0x10] = 0;
  param_1[0x11] = 0xc0;
  param_1[0x12] = 0x46000000;
  param_1[0x13] = 0;
  return param_1;
}



/* 40587acc FUN_40587acc */

/* Boundary evidence: original MIPS .pdata 40587acc..40587b1b. Semantic name remains unreviewed. */

void FUN_40587acc(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0x10);
  iVar2 = 4;
  do {
    if ((HLOCAL)*puVar1 != (HLOCAL)0x0) {
      FUN_40580ef4((HLOCAL)*puVar1);
      *puVar1 = 0;
    }
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  return;
}



/* 40587b1c FUN_40587b1c */

/* Boundary evidence: original MIPS .pdata 40587b1c..40587bb7. Semantic name remains unreviewed. */

HLOCAL FUN_40587b1c(int param_1,int *param_2)

{
  HLOCAL pvVar1;
  ushort *puVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = (int *)(param_1 + 8);
  while ((((*param_2 != piVar3[-2] || (param_2[1] != piVar3[-1])) || (param_2[2] != *piVar3)) ||
         (param_2[3] != piVar3[1]))) {
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 5;
    if (3 < iVar4) {
      return (HLOCAL)0x0;
    }
  }
  puVar2 = *(ushort **)(iVar4 * 0x14 + param_1 + 0x10);
  if (puVar2 == (ushort *)0x0) {
    return (HLOCAL)0x0;
  }
  pvVar1 = FUN_405813a0(puVar2,-1);
  return pvVar1;
}



/* 40587bb8 FUN_40587bb8 */

/* Boundary evidence: original MIPS .pdata 40587bb8..40587c73. Semantic name remains unreviewed. */

void FUN_40587bb8(int param_1,int *param_2,ushort *param_3)

{
  HLOCAL pvVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = (int *)(param_1 + 8);
  while ((((*param_2 != piVar2[-2] || (param_2[1] != piVar2[-1])) || (param_2[2] != *piVar2)) ||
         (param_2[3] != piVar2[1]))) {
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 5;
    if (3 < iVar3) {
      return;
    }
  }
  iVar3 = iVar3 * 0x14 + param_1;
  pvVar1 = *(HLOCAL *)(iVar3 + 0x10);
  if (pvVar1 != (HLOCAL)0x0) {
    FUN_40580ef4(pvVar1);
  }
  pvVar1 = FUN_405813a0(param_3,-1);
  *(HLOCAL *)(iVar3 + 0x10) = pvVar1;
  return;
}



/* 40587c74 FUN_40587c74 */

/* Boundary evidence: original MIPS .pdata 40587c74..40587d0b. Semantic name remains unreviewed. */

void FUN_40587c74(int param_1,ushort *param_2)

{
  int iVar1;
  HLOCAL pvVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x10);
  do {
    iVar1 = FUN_405810a4((char *)param_2,(char *)*puVar3);
    if (iVar1 != 0) {
      iVar4 = iVar4 * 0x14 + param_1;
      FUN_40580ef4(*(HLOCAL *)(iVar4 + 0x10));
      pvVar2 = FUN_405813a0(param_2,-1);
      *(HLOCAL *)(iVar4 + 0x10) = pvVar2;
      return;
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 5;
  } while (iVar4 < 4);
  return;
}



/* 40587d0c FUN_40587d0c */

/* Boundary evidence: original MIPS .pdata 40587d0c..40587d77. Semantic name remains unreviewed. */

undefined4 FUN_40587d0c(STRSAFE_PCNZWCH param_1,undefined4 *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  
  if ((param_1 == (STRSAFE_PCNZWCH)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar2 = 0x80070057;
  }
  else {
    uVar2 = 0;
    puVar1 = FUN_405873b8(param_1,(STRSAFE_PCNZWCH)0x0,0x1000,(LPCWSTR)0x0,0);
    *param_2 = puVar1;
    if (puVar1 == (uint *)0x0) {
      uVar2 = 0x8007000e;
    }
  }
  return uVar2;
}



/* 40587d78 FUN_40587d78 */

/* Boundary evidence: original MIPS .pdata 40587d78..40587f4f. Semantic name remains unreviewed. */

HRESULT FUN_40587d78(IID *param_1,int *param_2)

{
  HLOCAL pvVar1;
  LSTATUS LVar2;
  uint *puVar3;
  HRESULT HVar4;
  STRSAFE_PCNZWCH pwVar5;
  LPOLESTR local_238;
  HKEY local_234;
  DWORD local_230 [2];
  wchar_t awStack_228 [7];
  undefined1 auStack_21a [506];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if (param_2 == (int *)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    HVar4 = -0x7ff8ffa9;
  }
  else {
    *param_2 = 0;
    HVar4 = 0;
    local_238 = (STRSAFE_LPCWSTR)0x0;
    if (DAT_405aa0d8 != 0) {
      pvVar1 = FUN_40587b1c(DAT_405aa0d8,(int *)param_1);
      *param_2 = (int)pvVar1;
    }
    if ((*param_2 == 0) && (HVar4 = StringFromCLSID(param_1,&local_238), -1 < HVar4)) {
      local_234 = (HKEY)0x0;
      memcpy(awStack_228,L"CLSID\\",0xe);
      memset(auStack_21a,0,0x1fa);
      local_230[0] = 0x208;
      pwVar5 = (STRSAFE_PCNZWCH)0x0;
      HVar4 = StringCchCatW(awStack_228,0x104,local_238);
      if (-1 < HVar4) {
        LVar2 = RegOpenKeyExW((HKEY)0x80000000,awStack_228,0,0,&local_234);
        if (LVar2 == 0) {
          LVar2 = RegQueryValueExW(local_234,L"DisplayName",(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPBYTE)awStack_228,local_230);
          if (LVar2 == 0) {
            pwVar5 = awStack_228;
          }
          RegCloseKey(local_234);
        }
        puVar3 = FUN_405873b8(local_238,pwVar5,0x2000,(LPCWSTR)0x0,0);
        *param_2 = (int)puVar3;
        if (puVar3 == (uint *)0x0) {
          HVar4 = -0x7ff8fff2;
        }
        else if (DAT_405aa0d8 != 0) {
          FUN_40587bb8(DAT_405aa0d8,(int *)param_1,(ushort *)puVar3);
        }
      }
      CoTaskMemFree(local_238);
    }
    FUN_405a7174(local_20);
  }
  return HVar4;
}



/* 40587f50 FUN_40587f50 */

/* Boundary evidence: original MIPS .pdata 40587f50..4058816f. Semantic name remains unreviewed. */

DWORD FUN_40587f50(STRSAFE_PCNZWCH param_1,int *param_2)

{
  DWORD DVar1;
  LSTATUS LVar2;
  uint *puVar3;
  size_t local_228;
  HKEY local_224;
  wchar_t awStack_220 [7];
  undefined1 auStack_212 [506];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  if ((param_1 == (STRSAFE_PCNZWCH)0x0) || (param_2 == (int *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    DVar1 = 0x80070057;
  }
  else {
    memcpy(awStack_220,L"CLSID\\",0xe);
    memset(auStack_212,0,0x1fa);
    local_228 = 0;
    DVar1 = StringCbLengthW(param_1,0x208,&local_228);
    if (-1 < (int)DVar1) {
      local_228 = local_228 + 2;
      DVar1 = StringCchCatW(awStack_220,0x104,(STRSAFE_LPCWSTR)(*param_2 + 8));
      if (-1 < (int)DVar1) {
        local_224 = (HKEY)0x0;
        LVar2 = RegOpenKeyExW((HKEY)0x80000000,awStack_220,0,0,&local_224);
        if (LVar2 == 0) {
          LVar2 = RegSetValueExW(local_224,L"DisplayName",0,1,(BYTE *)param_1,local_228);
          if (LVar2 == 0) {
            puVar3 = FUN_405873b8((STRSAFE_PCNZWCH)(*param_2 + 8),param_1,0x2000,(LPCWSTR)0x0,0);
            if (puVar3 == (uint *)0x0) {
              DVar1 = 0x8007000e;
            }
            else {
              if (DAT_405aa0d8 != 0) {
                FUN_40587c74(DAT_405aa0d8,(ushort *)puVar3);
              }
              FUN_40580ef4((HLOCAL)*param_2);
              *param_2 = (int)puVar3;
            }
          }
          else {
            DVar1 = GetLastError();
            if (0 < (int)DVar1) {
              DVar1 = DVar1 & 0xffff | 0x80070000;
            }
          }
          RegCloseKey(local_224);
        }
        else {
          DVar1 = GetLastError();
          if (0 < (int)DVar1) {
            DVar1 = DVar1 & 0xffff | 0x80070000;
          }
        }
        if (-1 < (int)DVar1) {
          FUN_4058e220(DAT_405aa0cc);
        }
      }
    }
    FUN_405a7174(local_18);
  }
  return DVar1;
}



/* 40588170 FUN_40588170 */

/* Boundary evidence: original MIPS .pdata 40588170..4058821f. Semantic name remains unreviewed. */

undefined4 FUN_40588170(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  HKEY local_20;
  undefined4 local_1c;
  DWORD local_18 [2];
  
  local_20 = (HKEY)0x0;
  local_1c = param_4;
  LVar1 = RegOpenKeyExW(param_1,param_2,0,0,&local_20);
  if (LVar1 == 0) {
    local_18[0] = 4;
    LVar1 = RegQueryValueExW(local_20,param_3,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_1c,local_18);
    if (LVar1 != 0) {
      local_1c = param_4;
    }
    RegCloseKey(local_20);
    param_4 = local_1c;
  }
  return param_4;
}



/* 40588220 FUN_40588220 */

/* Boundary evidence: original MIPS .pdata 40588220..405882cf. Semantic name remains unreviewed. */

undefined4 FUN_40588220(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  HKEY local_20;
  undefined4 local_1c;
  DWORD local_18 [2];
  
  local_20 = (HKEY)0x0;
  local_1c = param_4;
  LVar1 = RegOpenKeyExW(param_1,param_2,0,0,&local_20);
  if (LVar1 == 0) {
    local_18[0] = 4;
    LVar1 = RegQueryValueExW(local_20,param_3,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_1c,local_18);
    if (LVar1 != 0) {
      local_1c = param_4;
    }
    RegCloseKey(local_20);
    param_4 = local_1c;
  }
  return param_4;
}



/* 405882d0 FUN_405882d0 */

/* Boundary evidence: original MIPS .pdata 405882d0..405883c3. Semantic name remains unreviewed. */

undefined1
FUN_405882d0(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,STRSAFE_LPWSTR param_4,size_t param_5,
            STRSAFE_LPCWSTR param_6)

{
  LSTATUS LVar1;
  HRESULT HVar2;
  HKEY local_20;
  DWORD local_1c;
  
  local_20 = (HKEY)0x0;
  if ((param_4 != (STRSAFE_LPWSTR)0x0) && (param_5 != 0)) {
    LVar1 = RegOpenKeyExW(param_1,param_2,0,0,&local_20);
    if (LVar1 == 0) {
      local_1c = param_5 << 1;
      LVar1 = RegQueryValueExW(local_20,param_3,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)param_4,&local_1c)
      ;
      RegCloseKey(local_20);
      if (LVar1 == 0) {
        return 1;
      }
    }
    if ((param_6 == (STRSAFE_LPCWSTR)0x0) ||
       (HVar2 = StringCchCopyW(param_4,param_5,param_6), HVar2 < 0)) {
      *param_4 = L'\0';
    }
  }
  return 0;
}



/* 405883c4 FUN_405883c4 */

/* Boundary evidence: original MIPS .pdata 405883c4..4058847b. Semantic name remains unreviewed. */

bool FUN_405883c4(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  bool bVar2;
  undefined4 local_resc;
  HKEY local_18 [2];
  
  bVar2 = false;
  local_18[0] = (HKEY)0x0;
  local_resc = param_4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,L"",0,0,(LPSECURITY_ATTRIBUTES)0x0,local_18,(LPDWORD)0x0
                         );
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_18[0],param_3,0,4,(BYTE *)&local_resc,4);
    bVar2 = LVar1 == 0;
    RegCloseKey(local_18[0]);
  }
  return bVar2;
}



/* 4058847c FUN_4058847c */

/* Boundary evidence: original MIPS .pdata 4058847c..40588533. Semantic name remains unreviewed. */

bool FUN_4058847c(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  bool bVar2;
  undefined4 local_resc;
  HKEY local_18 [2];
  
  bVar2 = false;
  local_18[0] = (HKEY)0x0;
  local_resc = param_4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,L"",0,0,(LPSECURITY_ATTRIBUTES)0x0,local_18,(LPDWORD)0x0
                         );
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_18[0],param_3,0,4,(BYTE *)&local_resc,4);
    bVar2 = LVar1 == 0;
    RegCloseKey(local_18[0]);
  }
  return bVar2;
}



/* 40588534 FUN_40588534 */

/* Boundary evidence: original MIPS .pdata 40588534..40588567. Semantic name remains unreviewed. */

bool FUN_40588534(STRSAFE_LPWSTR param_1,size_t param_2)

{
  HRESULT HVar1;
  
  HVar1 = StringCchCopyW(param_1,param_2,(STRSAFE_LPCWSTR)&DAT_405aa0dc);
  return -1 < HVar1;
}



/* 40588568 FUN_40588568 */

/* Boundary evidence: original MIPS .pdata 40588568..405885d7. Semantic name remains unreviewed. */

undefined4 FUN_40588568(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40588220((HKEY)0x80000002,L"Explorer",L"ListStyle",0);
  uVar2 = 1;
  if (iVar1 == 1) {
    uVar2 = 4;
  }
  else if (iVar1 == 2) {
    uVar2 = 2;
  }
  else if (iVar1 == 3) {
    uVar2 = 3;
  }
  return uVar2;
}



/* 405885d8 FUN_405885d8 */

undefined4 FUN_405885d8(void)

{
  return DAT_405a9950;
}



/* 405885e4 FUN_405885e4 */

undefined4 FUN_405885e4(void)

{
  return DAT_405aa2e4;
}



/* 405885f0 FUN_405885f0 */

undefined4 FUN_405885f0(void)

{
  return DAT_405aa2e8;
}



/* 405885fc FUN_405885fc */

undefined4 FUN_405885fc(void)

{
  return DAT_405aa2ec;
}



/* 40588608 FUN_40588608 */

undefined4 FUN_40588608(void)

{
  return DAT_405aa2f0;
}



/* 40588614 FUN_40588614 */

undefined4 FUN_40588614(void)

{
  return DAT_405aa2f4;
}



/* 40588620 FUN_40588620 */

undefined4 FUN_40588620(void)

{
  return DAT_405a9954;
}



/* 4058862c FUN_4058862c */

undefined4 FUN_4058862c(void)

{
  return DAT_405a9958;
}



/* 40588638 FUN_40588638 */

/* Boundary evidence: original MIPS .pdata 40588638..4058868f. Semantic name remains unreviewed. */

void FUN_40588638(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (((param_1 != 2) && (uVar1 = 3, param_1 != 3)) && (uVar1 = 0, param_1 == 4)) {
    uVar1 = 1;
  }
  FUN_4058847c((HKEY)0x80000002,L"Explorer",L"ListStyle",uVar1);
  return;
}



/* 40588690 FUN_40588690 */

/* Boundary evidence: original MIPS .pdata 40588690..405886df. Semantic name remains unreviewed. */

void FUN_40588690(undefined4 param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_4058847c((HKEY)0x80000002,L"Explorer",L"RecycleBinSize",param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    DAT_405a9950 = param_1;
  }
  return;
}



/* 405886e0 FUN_405886e0 */

/* Boundary evidence: original MIPS .pdata 405886e0..4058872f. Semantic name remains unreviewed. */

void FUN_405886e0(undefined4 param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_405883c4((HKEY)0x80000002,L"Explorer",L"ShowExt",param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    DAT_405aa2e4 = param_1;
  }
  return;
}



/* 40588730 FUN_40588730 */

/* Boundary evidence: original MIPS .pdata 40588730..4058877f. Semantic name remains unreviewed. */

void FUN_40588730(undefined4 param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_405883c4((HKEY)0x80000002,L"Explorer",L"ViewAll",param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    DAT_405aa2e8 = param_1;
  }
  return;
}



/* 40588780 FUN_40588780 */

/* Boundary evidence: original MIPS .pdata 40588780..405887cf. Semantic name remains unreviewed. */

void FUN_40588780(undefined4 param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_405883c4((HKEY)0x80000002,L"Explorer",L"ShowSys",param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    DAT_405aa2ec = param_1;
  }
  return;
}



/* 405887d0 FUN_405887d0 */

/* Boundary evidence: original MIPS .pdata 405887d0..4058881f. Semantic name remains unreviewed. */

void FUN_405887d0(undefined4 param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_405883c4((HKEY)0x80000002,L"Explorer",L"UseRecycleBin",param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    DAT_405a9958 = param_1;
  }
  return;
}



/* 40588820 FUN_40588820 */

/* Boundary evidence: original MIPS .pdata 40588820..405889a7. Semantic name remains unreviewed. */

void FUN_40588820(void)

{
  FUN_405882d0((HKEY)0x80000001,L"ControlPanel\\Desktop",L"wallpaper",(STRSAFE_LPWSTR)&DAT_405aa0dc,
               0x104,L"");
  DAT_405a9950 = FUN_40588220((HKEY)0x80000002,L"Explorer",L"RecycleBinSize",10);
  DAT_405aa2e4 = FUN_40588170((HKEY)0x80000002,L"Explorer",L"ShowExt",0);
  DAT_405aa2e8 = FUN_40588170((HKEY)0x80000002,L"Explorer",L"ViewAll",0);
  DAT_405aa2ec = FUN_40588170((HKEY)0x80000002,L"Explorer",L"ShowSys",0);
  DAT_405aa2f0 = FUN_40588170((HKEY)0x80000001,L"ControlPanel\\Desktop",L"tile",0);
  DAT_405aa2f4 = FUN_40588170((HKEY)0x80000002,L"Explorer",L"Use2ndClipboard",0);
  DAT_405a9954 = FUN_40588170((HKEY)0x80000002,L"Explorer",L"UseCompatibleBGImage",1);
  DAT_405a9958 = FUN_40588170((HKEY)0x80000002,L"Explorer",L"UseRecycleBin",1);
  return;
}



/* 405889a8 FUN_405889a8 */

/* Boundary evidence: original MIPS .pdata 405889a8..40588b4b. Semantic name remains unreviewed. */

undefined4 FUN_405889a8(HWND param_1,int param_2,uint param_3)

{
  LRESULT LVar1;
  uint nResult;
  undefined4 uVar2;
  
  if (param_2 == 0x110) {
    FUN_405a6ca0(param_1,8);
    SendDlgItemMessageW(param_1,0x2401,0xf1,(uint)(DAT_405aa2e4 == 0),0);
    SendDlgItemMessageW(param_1,0x2402,0xf1,(uint)(DAT_405aa2e8 == 0),0);
    SendDlgItemMessageW(param_1,0x2403,0xf1,(uint)(DAT_405aa2ec == 0),0);
    DAT_405aa2f8 = param_1;
    return 1;
  }
  if (param_2 == 0x111) {
    nResult = param_3 & 0xffff;
    uVar2 = 1;
    if (nResult == 1) {
      LVar1 = SendDlgItemMessageW(param_1,0x2401,0xf0,0,0);
      FUN_405886e0((uint)(LVar1 != 1));
      LVar1 = SendDlgItemMessageW(param_1,0x2402,0xf0,0,0);
      FUN_40588730((uint)(LVar1 != 1));
      LVar1 = SendDlgItemMessageW(param_1,0x2403,0xf0,0,0);
      FUN_40588780((uint)(LVar1 != 1));
      FUN_4058e220(DAT_405aa0cc);
    }
    else if (nResult != 2) goto LAB_405889f4;
    EndDialog(param_1,nResult);
  }
  else {
LAB_405889f4:
    uVar2 = 0;
  }
  return uVar2;
}



/* 40588b4c FUN_40588b4c */

/* Boundary evidence: original MIPS .pdata 40588b4c..40588bdf. Semantic name remains unreviewed. */

void FUN_40588b4c(void)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  
  if (DAT_405aa2f8 == (HWND)0x0) {
    hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2400,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
    DialogBoxIndirectParamW(DAT_405aa0c0,hDialogTemplate,(HWND)0x0,FUN_405889a8,0);
    DAT_405aa2f8 = (HWND)0x0;
  }
  else {
    SetForegroundWindow(DAT_405aa2f8);
  }
  return;
}



/* 40588be0 FUN_40588be0 */

/* Boundary evidence: original MIPS .pdata 40588be0..40588d9b. Semantic name remains unreviewed. */

undefined4 FUN_40588be0(HWND param_1,LPCWSTR param_2,wchar_t *param_3,wchar_t *param_4,uint param_5)

{
  HCURSOR pHVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  size_t sVar4;
  LPCWSTR lpText;
  undefined4 uVar5;
  
  uVar5 = 0;
  pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  pHVar1 = SetCursor(pHVar1);
  if ((param_2 != (LPCWSTR)0x0) && ((uint)param_2 >> 0x10 == 0)) {
    param_2 = (LPCWSTR)LoadStringW(DAT_405aa0c0,(uint)param_2 & 0xffff,(LPWSTR)0x0,0);
  }
  if (param_3 != (wchar_t *)0x0) {
    if ((uint)param_3 >> 0x10 == 0) {
      param_3 = (wchar_t *)LoadStringW(DAT_405aa0c0,(uint)param_3 & 0xffff,(LPWSTR)0x0,0);
    }
    if (((param_3 != (wchar_t *)0x0) && (param_4 != (wchar_t *)0x0)) &&
       (pwVar2 = wcschr(param_3,L'%'), pwVar2 != (wchar_t *)0x0)) {
      sVar3 = wcslen(param_3);
      sVar4 = wcslen(param_4);
      lpText = (LPCWSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar4 + sVar3 + 1) * 2);
      if (lpText == (LPCWSTR)0x0) {
        uVar5 = 0x8007000e;
      }
      else {
        wsprintfW(lpText,param_3,param_4);
        MessageBoxW(param_1,lpText,param_2,param_5 | 0x10000);
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpText);
      }
      goto LAB_40588d64;
    }
  }
  MessageBoxW(param_1,param_3,param_2,param_5 | 0x10000);
LAB_40588d64:
  SetCursor(pHVar1);
  return uVar5;
}



/* 40588d9c FUN_40588d9c */

/* Boundary evidence: original MIPS .pdata 40588d9c..4058925b. Semantic name remains unreviewed. */

void FUN_40588d9c(UINT *param_1,HWND param_2)

{
  LONG LVar1;
  LPCWSTR lpString;
  HICON pHVar2;
  HDC hdc;
  HWND pHVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int cx;
  tagRECT local_48;
  int local_38 [4];
  
  lpString = (LPCWSTR)LoadStringW(DAT_405aa0c0,*param_1,(LPWSTR)0x0,0);
  SetWindowTextW(param_2,lpString);
  FUN_405a6ca0(param_2,8);
  pHVar2 = (HICON)SendDlgItemMessageW(param_2,0x2204,0x172,1,param_1[1]);
  if (pHVar2 != (HICON)0x0) {
    DestroyIcon(pHVar2);
  }
  SetDlgItemTextW(param_2,0x2205,(LPCWSTR)(param_1 + 2));
  if (param_1[0x105] == 0) {
    pHVar3 = GetDlgItem(param_2,0x2205);
    hdc = GetDC(pHVar3);
    local_38[0] = 6;
    local_38[1] = 0x2203;
    local_38[2] = 7;
    local_38[3] = 2;
    local_48.left = 0;
    memset(&local_48.top,0,0xc);
    GetClientRect(pHVar3,&local_48);
    LVar1 = local_48.bottom;
    DrawTextW(hdc,(LPCWSTR)(param_1 + 2),-1,&local_48,0xc50);
    ReleaseDC(pHVar3,hdc);
    iVar4 = LVar1 - local_48.bottom;
    GetClientRect(pHVar3,&local_48);
    MapWindowPoints((HWND)0x0,param_2,(LPPOINT)&local_48,2);
    LVar1 = local_48.bottom;
    pHVar3 = GetDlgItem(param_2,0x2204);
    GetClientRect(pHVar3,&local_48);
    MapWindowPoints((HWND)0x0,param_2,(LPPOINT)&local_48,2);
    if (LVar1 - local_48.bottom < iVar4) {
      iVar4 = LVar1 - local_48.bottom;
    }
    piVar5 = local_38;
    iVar6 = 4;
    do {
      pHVar3 = GetDlgItem(param_2,*piVar5);
      if (pHVar3 != (HWND)0x0) {
        GetWindowRect(pHVar3,&local_48);
        MapWindowPoints((HWND)0x0,param_2,(LPPOINT)&local_48,2);
        SetWindowPos(pHVar3,(HWND)0x0,local_48.left,local_48.top - iVar4,0,0,0x15);
      }
      iVar6 = iVar6 + -1;
      piVar5 = piVar5 + 1;
    } while (iVar6 != 0);
    GetWindowRect(param_2,&local_48);
    iVar6 = (local_48.bottom - local_48.top) - iVar4;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 1;
    }
    SetWindowPos(param_2,(HWND)0x0,local_48.left,(iVar4 >> 1) + local_48.top,
                 local_48.right - local_48.left,iVar6,0x14);
  }
  else {
    pHVar2 = (HICON)SendDlgItemMessageW(param_2,0x2206,0x172,1,param_1[0x106]);
    if (pHVar2 != (HICON)0x0) {
      DestroyIcon(pHVar2);
    }
    SetDlgItemTextW(param_2,0x2207,(LPCWSTR)(param_1 + 0x108));
    pHVar2 = (HICON)SendDlgItemMessageW(param_2,0x2208,0x172,1,param_1[0x107]);
    if (pHVar2 != (HICON)0x0) {
      DestroyIcon(pHVar2);
    }
    SetDlgItemTextW(param_2,0x2209,(LPCWSTR)(param_1 + 0x188));
  }
  if (param_1[0x104] != 0) {
    local_48.left = 0;
    memset(&local_48.top,0,0xc);
    pHVar3 = GetDlgItem(param_2,6);
    GetWindowRect(pHVar3,&local_48);
    MapWindowPoints((HWND)0x0,param_2,(LPPOINT)&local_48,2);
    LVar1 = local_48.top;
    pHVar3 = GetDlgItem(param_2,7);
    GetWindowRect(pHVar3,&local_48);
    MapWindowPoints((HWND)0x0,param_2,(LPPOINT)&local_48,2);
    pHVar3 = GetDlgItem(param_2,6);
    SetWindowPos(pHVar3,(HWND)0x0,local_48.left,local_48.top,0,0,0x15);
    pHVar3 = GetDlgItem(param_2,2);
    GetWindowRect(pHVar3,&local_48);
    MapWindowPoints((HWND)0x0,param_2,(LPPOINT)&local_48,2);
    pHVar3 = GetDlgItem(param_2,7);
    SetWindowPos(pHVar3,(HWND)0x0,local_48.left,local_48.top,0,0,0x15);
    pHVar3 = GetDlgItem(param_2,0x2203);
    DestroyWindow(pHVar3);
    pHVar3 = GetDlgItem(param_2,2);
    DestroyWindow(pHVar3);
    iVar6 = local_48.top - LVar1;
    pHVar3 = GetDlgItem(param_2,0x2205);
    GetWindowRect(pHVar3,&local_48);
    MapWindowPoints((HWND)0x0,param_2,(LPPOINT)&local_48,2);
    iVar4 = local_48.bottom - local_48.top;
    cx = local_48.right - local_48.left;
    pHVar3 = GetDlgItem(param_2,0x2205);
    SetWindowPos(pHVar3,(HWND)0x0,local_48.left,local_48.top,cx,iVar4 + iVar6,0x14);
  }
  return;
}



/* 4058925c FUN_4058925c */

/* Boundary evidence: original MIPS .pdata 4058925c..4058937b. Semantic name remains unreviewed. */

undefined4 FUN_4058925c(undefined4 param_1,undefined4 param_2,LPWSTR param_3,int param_4)

{
  HRESULT HVar1;
  int iVar2;
  NUMBERFMTW local_a8;
  WCHAR aWStack_90 [32];
  wchar_t awStack_50 [30];
  uint local_14;
  
  local_14 = DAT_405a9a3c;
  HVar1 = StringCchPrintfW(awStack_50,0x1e,L"%I64u",param_4,param_1,param_2);
  if (-1 < HVar1) {
    local_a8.NumDigits = 0;
    memset(&local_a8.LeadingZero,0,0x14);
    iVar2 = GetLocaleInfoW(0x400,0x10,aWStack_90,0x1e);
    if (iVar2 != 0) {
      local_a8.Grouping = _wtol(aWStack_90);
      iVar2 = GetLocaleInfoW(0x400,0xf,aWStack_90,0x1e);
      if (iVar2 != 0) {
        local_a8.lpThousandSep = aWStack_90;
        local_a8.lpDecimalSep = aWStack_90;
        iVar2 = GetNumberFormatW(0x400,0,awStack_50,&local_a8,param_3,param_4);
        if (iVar2 != 0) {
          FUN_405a7174(local_14);
          return 1;
        }
      }
    }
  }
  FUN_405a7174(local_14);
  return 0;
}



/* 4058937c FUN_4058937c */

/* Boundary evidence: original MIPS .pdata 4058937c..40589503. Semantic name remains unreviewed. */

bool FUN_4058937c(LPCWSTR param_1,LPWSTR param_2,size_t param_3)

{
  HANDLE hFindFile;
  bool bVar1;
  LPWSTR local_270 [2];
  _FILETIME local_268;
  _SYSTEMTIME local_260;
  DWORD local_250;
  undefined1 auStack_24c [16];
  FILETIME aFStack_23c [67];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  local_268.dwLowDateTime = 0;
  local_270[0] = param_2;
  memset(&local_268.dwHighDateTime,0,4);
  local_260.wYear = 0;
  memset(&local_260.wMonth,0,0xe);
  local_250 = 0;
  memset(auStack_24c,0,0x22c);
  if (((param_1 == (LPCWSTR)0x0) || (param_2 == (LPWSTR)0x0)) || (param_3 == 0)) {
    FUN_405a7174(local_20);
    bVar1 = false;
  }
  else {
    hFindFile = FindFirstFileW(param_1,(LPWIN32_FIND_DATAW)&local_250);
    bVar1 = hFindFile != (HANDLE)0xffffffff;
    if (bVar1) {
      FindClose(hFindFile);
      FileTimeToLocalFileTime(aFStack_23c,&local_268);
      FileTimeToSystemTime(&local_268,&local_260);
      GetDateFormatW(0x400,0,&local_260,(LPCWSTR)0x0,local_270[0],param_3);
      StringCchCatExW(local_270[0],param_3,L" ",local_270,(size_t *)0x0,0x800);
      GetTimeFormatW(0x400,0,&local_260,(LPCWSTR)0x0,local_270[0],param_3);
    }
    FUN_405a7174(local_20);
  }
  return bVar1;
}



/* 40589504 FUN_40589504 */

/* Boundary evidence: original MIPS .pdata 40589504..405897d7. Semantic name remains unreviewed. */

bool FUN_40589504(uint param_1,uint param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  STRSAFE_LPCWSTR pszFormat;
  HRESULT HVar4;
  wchar_t *pszFormat_00;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  UINT local_78 [6];
  wchar_t awStack_60 [30];
  uint local_24;
  
  local_24 = DAT_405a9a3c;
  local_78[0] = 0x3029;
  local_78[1] = 0x302a;
  local_78[2] = 0x302b;
  local_78[3] = 0x302c;
  local_78[4] = 0x302d;
  uVar7 = 0;
  uVar8 = 0;
  bVar1 = true;
  if ((param_2 == 0) && (param_1 < 1000)) {
    StringCbPrintfW(awStack_60,0x3c,L"%d",param_1);
  }
  else {
    uVar8 = 1;
    if (param_2 == 0) goto LAB_405895e8;
    do {
      do {
        if (3 < uVar8) goto LAB_405895f4;
        param_1 = param_2 << 0x16 | param_1 >> 10;
        param_2 = param_2 >> 10;
        uVar8 = uVar8 + 1;
      } while (param_2 != 0);
LAB_405895e8:
    } while (0xf9fff < param_1);
LAB_405895f4:
    uVar5 = param_2 << 0x16 | param_1 >> 10;
    if ((uVar5 < 100) || (1 < uVar8)) {
      uVar6 = (param_1 + (param_1 >> 10) * -0x400) * 1000 >> 10;
      uVar9 = uVar6 / 10;
      uVar7 = uVar9;
      if ((9 < uVar5) && (uVar8 < 3)) {
        uVar7 = uVar9 / 10;
        bVar1 = false;
        uVar6 = uVar9;
      }
      if ((uVar7 != 0) && (5 < uVar6 % 10)) {
        if ((uVar7 == 9) || (uVar7 == 99)) {
          uVar5 = uVar5 + 1;
          uVar7 = 0;
        }
        else {
          uVar7 = uVar7 + 1;
        }
      }
    }
    iVar2 = FUN_4058925c(uVar5,param_2 >> 10,awStack_60,0x1e);
    if (iVar2 == 0) {
      FUN_405a7174(local_24);
      return false;
    }
    if (uVar7 != 0) {
      sVar3 = wcslen(awStack_60);
      iVar2 = GetLocaleInfoW(0x400,0xe,awStack_60 + sVar3,0x1e - sVar3);
      if (iVar2 != 0) {
        sVar3 = wcslen(awStack_60);
        if (bVar1) {
          pszFormat_00 = L"%02d";
        }
        else {
          pszFormat_00 = L"%d";
        }
        StringCchPrintfW(awStack_60 + sVar3,0x1e - sVar3,pszFormat_00,uVar7);
      }
    }
  }
  pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,local_78[uVar8],(LPWSTR)0x0,0);
  HVar4 = StringCchPrintfExW(param_3,param_4,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,pszFormat,
                             awStack_60);
  FUN_405a7174(local_24);
  return -1 < HVar4;
}



/* 405897d8 FUN_405897d8 */

/* Boundary evidence: original MIPS .pdata 405897d8..4058989b. Semantic name remains unreviewed. */

bool FUN_405897d8(undefined4 param_1,UINT param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  int iVar1;
  STRSAFE_LPCWSTR pszFormat;
  HRESULT HVar2;
  bool bVar3;
  WCHAR aWStack_50 [30];
  uint local_14;
  
  local_14 = DAT_405a9a3c;
  iVar1 = FUN_4058925c(param_1,0,aWStack_50,0x1e);
  if (iVar1 == 0) {
    FUN_405a7174(local_14);
    bVar3 = false;
  }
  else {
    pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,param_2,(LPWSTR)0x0,0);
    HVar2 = StringCchPrintfExW(param_3,param_4,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,pszFormat,
                               aWStack_50);
    bVar3 = -1 < HVar2;
    FUN_405a7174(local_14);
  }
  return bVar3;
}



/* 4058989c FUN_4058989c */

/* Boundary evidence: original MIPS .pdata 4058989c..40589adb. Semantic name remains unreviewed. */

undefined4 FUN_4058989c(FILETIME *param_1,uint param_2,LPWSTR param_3,size_t param_4)

{
  HRESULT HVar1;
  DWORD dwFlags;
  STRSAFE_LPCWSTR pszSrc;
  DWORD dwFlags_00;
  LPWSTR local_res8 [2];
  size_t local_40 [2];
  _FILETIME _Stack_38;
  _SYSTEMTIME _Stack_30;
  
  if (param_1 == (FILETIME *)0x0) {
    return 0;
  }
  if (param_3 == (LPWSTR)0x0) {
    return 0;
  }
  if (param_4 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    param_2 = 3;
  }
  local_res8[0] = param_3;
  local_40[0] = param_4;
  FileTimeToLocalFileTime(param_1,&_Stack_38);
  FileTimeToSystemTime(&_Stack_38,&_Stack_30);
  dwFlags = 1;
  dwFlags_00 = 2;
  if ((param_2 & 4) != 0) {
    dwFlags = 2;
  }
  if ((param_2 & 0x100) == 0) {
    if ((param_2 & 0x200) != 0) {
      dwFlags = dwFlags | 0x20;
    }
  }
  else {
    dwFlags = dwFlags | 0x10;
  }
  if ((param_2 & 8) != 0) {
    dwFlags_00 = 0;
  }
  if (((param_2 & 6) != 0) &&
     (GetDateFormatW(0x400,dwFlags,&_Stack_30,(LPCWSTR)0x0,local_res8[0],param_4),
     (param_2 & 9) != 0)) {
    if ((param_2 & 4) == 0) {
      pszSrc = L" ";
    }
    else {
      pszSrc = L", ";
    }
    HVar1 = StringCchCatExW(local_res8[0],param_4,pszSrc,local_res8,local_40,0x800);
    if (HVar1 < 0) {
      return 0;
    }
    if ((param_2 & 0x200) == 0) {
      if (((param_2 & 0x100) == 0) || (local_40[0] < 2)) goto LAB_40589a7c;
      *local_res8[0] = L'\x200f';
      local_res8[0][1] = L'\x200e';
      local_res8[0][2] = L'\0';
    }
    else {
      if (local_40[0] < 2) goto LAB_40589a7c;
      *local_res8[0] = L'\x200e';
      local_res8[0][1] = L'\x200f';
      local_res8[0][2] = L'\0';
    }
    local_res8[0] = local_res8[0] + 2;
    local_40[0] = local_40[0] - 2;
  }
LAB_40589a7c:
  if ((param_2 & 9) != 0) {
    GetTimeFormatW(0x400,dwFlags_00,&_Stack_30,(LPCWSTR)0x0,local_res8[0],local_40[0]);
  }
  return 1;
}



/* 40589adc FUN_40589adc */

/* Boundary evidence: original MIPS .pdata 40589adc..40589c5f. Semantic name remains unreviewed. */

undefined4 FUN_40589adc(HDC param_1,wchar_t *param_2,int *param_3,size_t *param_4,int param_5)

{
  size_t cchString;
  int iVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  tagSIZE local_30;
  
  iVar2 = param_3[2];
  iVar1 = *param_3;
  cchString = wcslen(param_2);
  if (cchString == 0) {
    *param_4 = 0;
  }
  else {
    GetTextExtentExPointW(param_1,param_2,cchString,0,(LPINT)0x0,(LPINT)0x0,&local_30);
    if (iVar2 - iVar1 < local_30.cx) {
      iVar1 = (iVar2 - iVar1) - param_5;
      sVar3 = 1;
      if (0 < iVar1) {
        sVar4 = 0;
        sVar3 = cchString;
        if (0 < (int)cchString) {
          do {
            iVar2 = sVar4 + sVar3 + 1;
            if (iVar2 < 0) {
              iVar2 = sVar4 + sVar3 + 2;
            }
            cchString = iVar2 >> 1;
            GetTextExtentExPointW
                      (param_1,param_2 + sVar4,cchString - sVar4,0,(LPINT)0x0,(LPINT)0x0,&local_30);
            if (local_30.cx < iVar1) {
              iVar1 = iVar1 - local_30.cx;
              sVar4 = cchString;
            }
            else {
              if (local_30.cx <= iVar1) break;
              sVar3 = cchString - 1;
            }
            cchString = sVar3;
            sVar3 = cchString;
          } while ((int)sVar4 < (int)cchString);
        }
        sVar3 = cchString;
        if ((int)cchString < 1) {
          sVar3 = 1;
        }
      }
      *param_4 = sVar3;
      return 1;
    }
    *param_4 = cchString;
  }
  return 0;
}



/* 40589c60 FUN_40589c60 */

/* Boundary evidence: original MIPS .pdata 40589c60..40589e33. Semantic name remains unreviewed. */

void FUN_40589c60(int param_1)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  STRSAFE_LPWSTR pszDest;
  uint uVar4;
  ULARGE_INTEGER local_178;
  ULARGE_INTEGER local_170;
  ULARGE_INTEGER UStack_168;
  WCHAR aWStack_160 [64];
  wchar_t local_e0 [64];
  WCHAR aWStack_60 [32];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  BVar1 = GetDiskFreeSpaceExW((LPCWSTR)(param_1 + 0x8c0),&UStack_168,&local_170,&local_178);
  if (BVar1 != 0) {
    LoadStringW(DAT_405aa0c0,0x3029,aWStack_60,0x20);
    uVar3 = local_170.s.LowPart - local_178._0_4_;
    uVar4 = (local_170.s.HighPart - local_178._4_4_) -
            (uint)(local_170.s.LowPart < local_178.s.LowPart);
    local_e0[0] = L'\0';
    iVar2 = FUN_4058925c(uVar3,uVar4,aWStack_160,0x40);
    if (iVar2 != 0) {
      StringCchPrintfExW(local_e0,0x40,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800,aWStack_60,
                         aWStack_160);
    }
    FUN_40589504(uVar3,uVar4,aWStack_160,0x40);
    pszDest = (STRSAFE_LPWSTR)(param_1 + 0x4b0);
    if (local_e0[0] == L'\0') {
      StringCchCopyW(pszDest,0x104,aWStack_160);
    }
    else {
      StringCchPrintfW(pszDest,0x104,L"%s (%s)",aWStack_160,local_e0);
    }
    local_e0[0] = L'\0';
    iVar2 = FUN_4058925c(local_178.s.LowPart,local_178.s.HighPart,aWStack_160,0x40);
    if (iVar2 != 0) {
      StringCchPrintfExW(local_e0,0x40,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800,aWStack_60,
                         aWStack_160);
    }
    FUN_40589504(local_178.s.LowPart,local_178.s.HighPart,aWStack_160,0x40);
    if (local_e0[0] == L'\0') {
      StringCchCopyW(pszDest,0x104,aWStack_160);
    }
    else {
      StringCchPrintfW((STRSAFE_LPWSTR)(param_1 + 0x6b8),0x104,L"%s (%s)",aWStack_160,local_e0);
    }
  }
  FUN_405a7174(local_20);
  return;
}



/* 40589e34 FUN_40589e34 */

/* Boundary evidence: original MIPS .pdata 40589e34..40589fb7. Semantic name remains unreviewed. */

void FUN_40589e34(LPCITEMIDLIST param_1,STRSAFE_LPWSTR param_2)

{
  HRESULT HVar1;
  int iVar2;
  LPCITEMIDLIST local_530;
  int *local_52c;
  STRRET local_528;
  WCHAR aWStack_420 [260];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_405a9a3c;
  local_52c = (int *)0x0;
  local_530 = (LPCITEMIDLIST)0x0;
  if (((param_1 != (LPCITEMIDLIST)0x0) && (param_2 != (STRSAFE_LPWSTR)0x0)) &&
     (HVar1 = SHBindToParent(param_1,(IID *)&DAT_40572b68,&local_52c,&local_530), -1 < HVar1)) {
    local_528.uType = 0;
    memset(&local_528.u,0,0x104);
    iVar2 = (**(code **)(*local_52c + 0x2c))(local_52c,local_530,0x1000,&local_528);
    if ((-1 < iVar2) && (HVar1 = StrRetToBufW(&local_528,local_530,aWStack_420,0x104), -1 < HVar1))
    {
      iVar2 = SHGetSpecialFolderPath(0,aWStack_218,0x10,1);
      if (iVar2 != 0) {
        iVar2 = CompareStringW(0x400,1,aWStack_218,-1,aWStack_420,-1);
        if ((iVar2 == 2) &&
           (iVar2 = (**(code **)(*local_52c + 0x2c))(local_52c,local_530,0x1001,&local_528),
           -1 < iVar2)) {
          StrRetToBufW(&local_528,local_530,aWStack_420,0x104);
        }
      }
      StringCchCopyExW(param_2,0x104,aWStack_420,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800);
    }
    (**(code **)(*local_52c + 8))();
    FUN_40580ef4(local_530);
  }
  FUN_405a7174(local_10);
  return;
}



/* 40589fb8 FUN_40589fb8 */

/* Boundary evidence: original MIPS .pdata 40589fb8..4058a44b. Semantic name remains unreviewed. */

undefined4 FUN_40589fb8(HWND param_1,int param_2,uint param_3,int param_4)

{
  longlong lVar1;
  uint *puVar2;
  HWND pHVar3;
  uint uVar4;
  int nIDDlgItem;
  int *dwNewLong;
  undefined8 uVar5;
  wchar_t awStack_a8 [64];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  puVar2 = (uint *)GetWindowLongW(param_1,8);
  if (param_2 == 0x110) {
    dwNewLong = *(int **)(param_4 + 0x1c);
    SetWindowLongW(param_1,8,(LONG)dwNewLong);
    FUN_405a6ca0(param_1,8);
    pHVar3 = GetDlgItem(param_1,0x2317);
    SendMessageW(pHVar3,0x406,1,0x640000);
    SendMessageW(pHVar3,0x414,10,10);
    SendMessageW(pHVar3,0x415,0,10);
    SendMessageW(pHVar3,0x405,1,dwNewLong[1]);
    pHVar3 = GetDlgItem(param_1,0x2314);
    SendMessageW(pHVar3,0xf1,(uint)(*dwNewLong == 0),0);
    pHVar3 = GetDlgItem(param_1,0x2315);
    StringCbPrintfW(awStack_a8,0x80,L"%d%%",dwNewLong[1]);
    SetWindowTextW(pHVar3,awStack_a8);
    pHVar3 = GetDlgItem(param_1,0x2318);
    FUN_40589504(dwNewLong[2],dwNewLong[3],awStack_a8,0x40);
    SetWindowTextW(pHVar3,awStack_a8);
    pHVar3 = GetDlgItem(param_1,0x2319);
    lVar1 = (ulonglong)(uint)dwNewLong[1] * (ulonglong)(uint)dwNewLong[2];
    uVar5 = __ull_div((int)lVar1,dwNewLong[1] * dwNewLong[3] + (int)((ulonglong)lVar1 >> 0x20),100,0
                     );
    FUN_40589504((uint)uVar5,(uint)((ulonglong)uVar5 >> 0x20),awStack_a8,0x40);
    SetWindowTextW(pHVar3,awStack_a8);
    nIDDlgItem = 0x2317;
    if (*dwNewLong == 0) {
      pHVar3 = GetDlgItem(param_1,0x2317);
      EnableWindow(pHVar3,0);
      pHVar3 = GetDlgItem(param_1,0x2315);
      EnableWindow(pHVar3,0);
      pHVar3 = GetDlgItem(param_1,0x2316);
      EnableWindow(pHVar3,0);
      pHVar3 = GetDlgItem(param_1,0x2304);
      EnableWindow(pHVar3,0);
      nIDDlgItem = 0x2314;
    }
    pHVar3 = GetDlgItem(param_1,nIDDlgItem);
    SetFocus(pHVar3);
  }
  else if (param_2 == 0x111) {
    if (((param_3 & 0xffff) == 0x2314) && (param_3 >> 0x10 == 0)) {
      uVar4 = (uint)(*puVar2 == 0);
      *puVar2 = uVar4;
      if (uVar4 != 0) {
        pHVar3 = GetDlgItem(param_1,0x2317);
        EnableWindow(pHVar3,1);
        pHVar3 = GetDlgItem(param_1,0x2315);
        EnableWindow(pHVar3,1);
        pHVar3 = GetDlgItem(param_1,0x2316);
        EnableWindow(pHVar3,1);
        pHVar3 = GetDlgItem(param_1,0x2304);
      }
      else {
        pHVar3 = GetDlgItem(param_1,0x2317);
        EnableWindow(pHVar3,0);
        pHVar3 = GetDlgItem(param_1,0x2315);
        EnableWindow(pHVar3,0);
        pHVar3 = GetDlgItem(param_1,0x2316);
        EnableWindow(pHVar3,0);
        pHVar3 = GetDlgItem(param_1,0x2304);
      }
      EnableWindow(pHVar3,(uint)(uVar4 != 0));
    }
  }
  else {
    if (param_2 != 0x114) {
      FUN_405a7174(local_28);
      return 0;
    }
    pHVar3 = GetDlgItem(param_1,0x2317);
    uVar4 = SendMessageW(pHVar3,0x400,0,0);
    puVar2[1] = uVar4;
    pHVar3 = GetDlgItem(param_1,0x2315);
    StringCbPrintfW(awStack_a8,0x80,L"%d%%",puVar2[1]);
    SetWindowTextW(pHVar3,awStack_a8);
    pHVar3 = GetDlgItem(param_1,0x2318);
    FUN_40589504(puVar2[2],puVar2[3],awStack_a8,0x40);
    SetWindowTextW(pHVar3,awStack_a8);
    pHVar3 = GetDlgItem(param_1,0x2319);
    lVar1 = (ulonglong)puVar2[1] * (ulonglong)puVar2[2];
    uVar5 = __ull_div((int)lVar1,puVar2[1] * puVar2[3] + (int)((ulonglong)lVar1 >> 0x20),100,0);
    FUN_40589504((uint)uVar5,(uint)((ulonglong)uVar5 >> 0x20),awStack_a8,0x40);
    SetWindowTextW(pHVar3,awStack_a8);
  }
  FUN_405a7174(local_28);
  return 1;
}



/* 4058a468 FUN_4058a468 */

/* Boundary evidence: original MIPS .pdata 4058a468..4058a543. Semantic name remains unreviewed. */

undefined4 FUN_4058a468(HWND param_1,int param_2,uint param_3,LPCWSTR param_4)

{
  uint nResult;
  
  if (param_2 == 0x110) {
    FUN_405a6ca0(param_1,8);
    SetDlgItemTextW(param_1,0x2205,param_4);
    MessageBeep(0xffffffff);
  }
  else {
    if (param_2 != 0x111) {
      return 0;
    }
    nResult = param_3 & 0xffff;
    if (nResult != 2) {
      if (nResult != 0x231b) {
        return 1;
      }
      FUN_40586a28(DAT_405aa0d4,0);
      FUN_40584468(DAT_405aa0d4,0);
      FUN_40583798(DAT_405aa0d4);
      ShowWindow(param_1,0);
    }
    EndDialog(param_1,nResult);
  }
  return 1;
}



/* 4058a544 FUN_4058a544 */

/* Boundary evidence: original MIPS .pdata 4058a544..4058a5af. Semantic name remains unreviewed. */

void FUN_4058a544(HWND param_1,LPCWSTR param_2,wchar_t *param_3,LPCWSTR param_4,uint param_5)

{
  wchar_t *pwVar1;
  
  if (param_4 == (LPCWSTR)0x0) {
    pwVar1 = (wchar_t *)0x0;
  }
  else {
    pwVar1 = PathFindFileNameW(param_4);
  }
  FUN_40588be0(param_1,param_2,param_3,pwVar1,param_5);
  return;
}



/* 4058a5b0 FUN_4058a5b0 */

/* Boundary evidence: original MIPS .pdata 4058a5b0..4058a6d7. Semantic name remains unreviewed. */

undefined4 FUN_4058a5b0(HWND param_1,int param_2,uint param_3,UINT *param_4)

{
  HICON pHVar1;
  uint nResult;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 == 2) {
    pHVar1 = (HICON)SendDlgItemMessageW(param_1,0x2204,0x172,1,0);
    if (pHVar1 != (HICON)0x0) {
      DestroyIcon(pHVar1);
    }
    pHVar1 = (HICON)SendDlgItemMessageW(param_1,0x2206,0x172,1,0);
    if (pHVar1 != (HICON)0x0) {
      DestroyIcon(pHVar1);
    }
    pHVar1 = (HICON)SendDlgItemMessageW(param_1,0x2208,0x172,1,0);
    if (pHVar1 != (HICON)0x0) {
      DestroyIcon(pHVar1);
    }
  }
  else if (param_2 == 0x110) {
    FUN_40588d9c(param_4,param_1);
  }
  else if (param_2 == 0x111) {
    nResult = param_3 & 0xffff;
    if ((nResult == 2) || ((5 < nResult && ((nResult < 8 || (nResult == 0x2203)))))) {
      EndDialog(param_1,nResult);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4058a6d8 FUN_4058a6d8 */

/* Boundary evidence: original MIPS .pdata 4058a6d8..4058a937. Semantic name remains unreviewed. */

int FUN_4058a6d8(LPCWSTR param_1,HWND param_2,undefined4 param_3,INT_PTR *param_4)

{
  DWORD DVar1;
  LPWSTR pWVar2;
  STRSAFE_LPCWSTR pwVar3;
  int iVar4;
  HCURSOR pHVar5;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar6;
  undefined4 local_840;
  HANDLE local_83c;
  wchar_t awStack_838 [516];
  undefined4 local_430;
  undefined4 local_42c;
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if ((param_1 == (LPCWSTR)0x0) || (param_4 == (INT_PTR *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return -0x7ff8ffa9;
  }
  DVar1 = GetFileAttributesW(param_1);
  if (DVar1 == 0xffffffff) {
    FUN_405a7174(local_20);
    return -0x7fffbffb;
  }
  if ((DVar1 & 0x10) == 0) {
    if ((DVar1 & 4) == 0) {
      if ((DVar1 & 1) == 0) {
        *param_4 = 1;
        goto LAB_4058a768;
      }
      pWVar2 = PathFindFileNameW(param_1);
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3048,(LPWSTR)0x0,0);
      iVar4 = StringCchPrintfExW(awStack_838,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar3,
                                 pWVar2);
    }
    else {
      pWVar2 = PathFindFileNameW(param_1);
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3049,(LPWSTR)0x0,0);
      iVar4 = StringCchPrintfExW(awStack_838,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar3,
                                 pWVar2);
    }
    if (iVar4 < 0) {
      FUN_405a7174(local_20);
      return iVar4;
    }
    local_840 = 0x3045;
    local_83c = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1300,1,0x20,0x20,0);
    local_42c = 0;
    local_430 = param_3;
    pHVar5 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    pHVar5 = SetCursor(pHVar5);
    hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2200,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
    IVar6 = DialogBoxIndirectParamW
                      (DAT_405aa0c0,hDialogTemplate,param_2,FUN_4058a5b0,(LPARAM)&local_840);
    *param_4 = IVar6;
    SetCursor(pHVar5);
  }
  else {
    *param_4 = 1;
  }
LAB_4058a768:
  FUN_405a7174(local_20);
  return 0;
}



/* 4058a938 FUN_4058a938 */

/* Boundary evidence: original MIPS .pdata 4058a938..4058abbf. Semantic name remains unreviewed. */

int FUN_4058a938(LPCWSTR param_1,LPCWSTR param_2,HWND param_3,INT_PTR *param_4)

{
  DWORD DVar1;
  LPWSTR pWVar2;
  LPWSTR pWVar3;
  STRSAFE_LPCWSTR pwVar4;
  int iVar5;
  HCURSOR pHVar6;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar7;
  undefined4 local_840;
  HANDLE local_83c;
  wchar_t awStack_838 [516];
  undefined4 local_430;
  undefined4 local_42c;
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if (((param_1 == (LPCWSTR)0x0) || (param_2 == (LPCWSTR)0x0)) || (param_4 == (INT_PTR *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return -0x7ff8ffa9;
  }
  DVar1 = GetFileAttributesW(param_1);
  if (DVar1 == 0xffffffff) {
    FUN_405a7174(local_20);
    return -0x7fffbffb;
  }
  if ((DVar1 & 0x10) == 0) {
    if ((DVar1 & 4) == 0) {
      if ((DVar1 & 1) == 0) {
        *param_4 = 1;
        goto LAB_4058a9d0;
      }
      pWVar2 = PathFindFileNameW(param_2);
      pWVar3 = PathFindFileNameW(param_1);
      pwVar4 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x304a,(LPWSTR)0x0,0);
      iVar5 = StringCchPrintfExW(awStack_838,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar4,
                                 pWVar3,pWVar2);
    }
    else {
      pWVar2 = PathFindFileNameW(param_2);
      pWVar3 = PathFindFileNameW(param_1);
      pwVar4 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x304b,(LPWSTR)0x0,0);
      iVar5 = StringCchPrintfExW(awStack_838,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar4,
                                 pWVar3,pWVar2);
    }
    if (iVar5 < 0) {
      FUN_405a7174(local_20);
      return iVar5;
    }
    local_840 = 0x3046;
    local_83c = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1301,1,0x20,0x20,0);
    local_430 = 0;
    local_42c = 0;
    pHVar6 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    pHVar6 = SetCursor(pHVar6);
    hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2201,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
    IVar7 = DialogBoxIndirectParamW
                      (DAT_405aa0c0,hDialogTemplate,param_3,FUN_4058a5b0,(LPARAM)&local_840);
    *param_4 = IVar7;
    SetCursor(pHVar6);
  }
  else {
    *param_4 = 1;
  }
LAB_4058a9d0:
  FUN_405a7174(local_20);
  return 0;
}



/* 4058abc0 FUN_4058abc0 */

/* Boundary evidence: original MIPS .pdata 4058abc0..4058af5b. Semantic name remains unreviewed. */

HRESULT FUN_4058abc0(LPCWSTR param_1,HWND param_2,int param_3,int param_4,undefined4 param_5,
                    INT_PTR *param_6)

{
  DWORD DVar1;
  int iVar2;
  STRSAFE_LPCWSTR pwVar3;
  LPWSTR pWVar4;
  BOOL BVar5;
  HCURSOR pHVar6;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar7;
  UINT uID;
  HRESULT HVar8;
  undefined4 local_c58;
  HANDLE local_c54;
  wchar_t local_c50 [516];
  undefined4 local_848;
  undefined4 local_844;
  wchar_t awStack_438 [516];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  HVar8 = 0;
  if ((param_1 == (LPCWSTR)0x0) || (param_6 == (INT_PTR *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return -0x7ff8ffa9;
  }
  DVar1 = GetFileAttributesW(param_1);
  if (DVar1 == 0xffffffff) {
    FUN_405a7174(local_30);
    return -0x7fffbffb;
  }
  if ((DVar1 & 0x10) == 0) {
    if ((DVar1 & 4) == 0) {
      if ((DVar1 & 1) == 0) {
        BVar5 = PathIsExe(param_1);
        if (BVar5 == 0) {
          if (param_3 == 0) {
            *param_6 = 1;
            goto LAB_4058ad34;
          }
          local_c50[0] = L'\0';
        }
        else {
          pWVar4 = PathFindFileNameW(param_1);
          pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x304e,(LPWSTR)0x0,0);
          HVar8 = StringCchPrintfExW(local_c50,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,
                                     pwVar3,pWVar4);
        }
      }
      else {
        pWVar4 = PathFindFileNameW(param_1);
        pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x304c,(LPWSTR)0x0,0);
        HVar8 = StringCchPrintfExW(local_c50,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar3,
                                   pWVar4);
      }
    }
    else {
      pWVar4 = PathFindFileNameW(param_1);
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x304d,(LPWSTR)0x0,0);
      HVar8 = StringCchPrintfExW(local_c50,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar3,
                                 pWVar4);
    }
    if (-1 < HVar8) goto LAB_4058ac68;
LAB_4058ae58:
    FUN_405a7174(local_30);
  }
  else {
    if (param_3 == 0) {
      *param_6 = 1;
    }
    else {
      local_c50[0] = L'\0';
LAB_4058ac68:
      iVar2 = FUN_4058862c();
      if ((iVar2 == 0) || (uID = 0x304f, param_4 != 0)) {
        uID = 0x3050;
      }
      pwVar3 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
      pWVar4 = PathFindFileNameW(param_1);
      HVar8 = StringCchPrintfExW(awStack_438,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar3,
                                 pWVar4);
      if ((HVar8 < 0) || (HVar8 = StringCchCatW(local_c50,0x204,awStack_438), HVar8 < 0))
      goto LAB_4058ae58;
      local_c58 = 0x3047;
      iVar2 = FUN_4058862c();
      if ((iVar2 == 0) || (param_4 != 0)) {
        local_c54 = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1407,1,0x20,0x20,0);
      }
      else {
        local_c54 = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1103,1,0x20,0x20,0);
      }
      local_848 = param_5;
      local_844 = 0;
      pHVar6 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
      pHVar6 = SetCursor(pHVar6);
      hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2200,(LPCWSTR)0x5);
      hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
      IVar7 = DialogBoxIndirectParamW
                        (DAT_405aa0c0,hDialogTemplate,param_2,FUN_4058a5b0,(LPARAM)&local_c58);
      *param_6 = IVar7;
      SetCursor(pHVar6);
    }
LAB_4058ad34:
    FUN_405a7174(local_30);
    HVar8 = 0;
  }
  return HVar8;
}



/* 4058af5c FUN_4058af5c */

/* Boundary evidence: original MIPS .pdata 4058af5c..4058b13f. Semantic name remains unreviewed. */

HRESULT FUN_4058af5c(uint param_1,HWND param_2,int param_3,INT_PTR *param_4)

{
  int iVar1;
  STRSAFE_LPCWSTR pszFormat;
  HRESULT HVar2;
  HCURSOR pHVar3;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar4;
  UINT uID;
  undefined4 local_840;
  HANDLE local_83c;
  wchar_t awStack_838 [516];
  undefined4 local_430;
  undefined4 local_42c;
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if ((param_1 < 2) || (param_4 == (INT_PTR *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    HVar2 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_4058862c();
    if ((iVar1 == 0) || (uID = 0x3051, param_3 != 0)) {
      uID = 0x3052;
    }
    pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
    HVar2 = StringCchPrintfExW(awStack_838,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pszFormat
                               ,param_1);
    if (HVar2 < 0) {
      FUN_405a7174(local_20);
    }
    else {
      local_840 = 0x3047;
      iVar1 = FUN_4058862c();
      if ((iVar1 == 0) || (param_3 != 0)) {
        local_83c = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1407,1,0x20,0x20,0);
      }
      else {
        local_83c = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1103,1,0x20,0x20,0);
      }
      local_430 = 0;
      local_42c = 0;
      pHVar3 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
      pHVar3 = SetCursor(pHVar3);
      hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2201,(LPCWSTR)0x5);
      hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
      IVar4 = DialogBoxIndirectParamW
                        (DAT_405aa0c0,hDialogTemplate,param_2,FUN_4058a5b0,(LPARAM)&local_840);
      *param_4 = IVar4;
      SetCursor(pHVar3);
      FUN_405a7174(local_20);
      HVar2 = 0;
    }
  }
  return HVar2;
}



/* 4058b140 FUN_4058b140 */

/* Boundary evidence: original MIPS .pdata 4058b140..4058b37f. Semantic name remains unreviewed. */

HRESULT FUN_4058b140(LPCWSTR param_1,HWND param_2,int param_3,INT_PTR *param_4)

{
  LPWSTR pWVar1;
  STRSAFE_LPCWSTR pwVar2;
  HCURSOR pHVar3;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar4;
  UINT uID;
  HRESULT HVar5;
  undefined4 local_c58;
  HANDLE local_c54;
  wchar_t awStack_c50 [516];
  undefined4 local_848;
  undefined4 local_844;
  wchar_t local_438 [516];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  HVar5 = 0;
  if ((param_1 == (LPCWSTR)0x0) || (param_4 == (INT_PTR *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    HVar5 = -0x7ff8ffa9;
  }
  else {
    if (param_3 == 0) {
      local_438[0] = L'\0';
    }
    else {
      pWVar1 = PathFindFileNameW(param_1);
      pwVar2 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x306b,(LPWSTR)0x0,0);
      HVar5 = StringCchPrintfExW(local_438,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar2,
                                 pWVar1);
    }
    if ((-1 < HVar5) && (HVar5 = StringCchCopyW(awStack_c50,0x204,local_438), -1 < HVar5)) {
      uID = 0x3087;
      if (param_3 == 0) {
        uID = 0x3050;
      }
      pwVar2 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
      pWVar1 = PathFindFileNameW(param_1);
      HVar5 = StringCchPrintfExW(local_438,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,pwVar2,
                                 pWVar1);
      if ((-1 < HVar5) && (HVar5 = StringCchCatW(awStack_c50,0x204,local_438), -1 < HVar5)) {
        local_c58 = 0x3047;
        local_c54 = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1407,1,0x20,0x20,0);
        local_848 = 0;
        local_844 = 0;
        pHVar3 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
        pHVar3 = SetCursor(pHVar3);
        hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2201,(LPCWSTR)0x5);
        hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
        IVar4 = DialogBoxIndirectParamW
                          (DAT_405aa0c0,hDialogTemplate,param_2,FUN_4058a5b0,(LPARAM)&local_c58);
        *param_4 = IVar4;
        SetCursor(pHVar3);
      }
    }
    FUN_405a7174(local_30);
  }
  return HVar5;
}



/* 4058b380 FUN_4058b380 */

/* Boundary evidence: original MIPS .pdata 4058b380..4058b547. Semantic name remains unreviewed. */

HRESULT FUN_4058b380(LPCWSTR param_1,HWND param_2,undefined4 param_3,INT_PTR *param_4)

{
  DWORD DVar1;
  LPWSTR pWVar2;
  STRSAFE_LPCWSTR pszFormat;
  HCURSOR pHVar3;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar4;
  HRESULT HVar5;
  undefined4 local_840;
  HANDLE local_83c;
  wchar_t awStack_838 [516];
  undefined4 local_430;
  undefined4 local_42c;
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if ((param_1 == (LPCWSTR)0x0) || (param_4 == (INT_PTR *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    HVar5 = -0x7ff8ffa9;
  }
  else {
    DVar1 = GetFileAttributesW(param_1);
    if (DVar1 == 0xffffffff) {
      FUN_405a7174(local_20);
      HVar5 = -0x7fffbffb;
    }
    else {
      pWVar2 = PathFindFileNameW(param_1);
      pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3053,(LPWSTR)0x0,0);
      HVar5 = StringCchPrintfExW(awStack_838,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,
                                 pszFormat,pWVar2);
      if (HVar5 < 0) {
        FUN_405a7174(local_20);
      }
      else {
        local_840 = 0x3076;
        local_83c = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1302,1,0x20,0x20,0);
        local_42c = 0;
        local_430 = param_3;
        pHVar3 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
        pHVar3 = SetCursor(pHVar3);
        hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2200,(LPCWSTR)0x5);
        hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
        IVar4 = DialogBoxIndirectParamW
                          (DAT_405aa0c0,hDialogTemplate,param_2,FUN_4058a5b0,(LPARAM)&local_840);
        *param_4 = IVar4;
        SetCursor(pHVar3);
        FUN_405a7174(local_20);
        HVar5 = 0;
      }
    }
  }
  return HVar5;
}



/* 4058b548 FUN_4058b548 */

/* Boundary evidence: original MIPS .pdata 4058b548..4058b6c3. Semantic name remains unreviewed. */

bool FUN_4058b548(LPCWSTR param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  HANDLE hFindFile;
  int iVar1;
  HRESULT HVar2;
  bool bVar3;
  _FILETIME _Stack_3a0;
  _SYSTEMTIME _Stack_398;
  _WIN32_FIND_DATAW _Stack_388;
  WCHAR aWStack_118 [64];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  if ((param_1 == (LPCWSTR)0x0) ||
     (hFindFile = FindFirstFileW(param_1,&_Stack_388), hFindFile == (HANDLE)0xffffffff)) {
    FUN_405a7174(local_18);
    bVar3 = false;
  }
  else {
    FindClose(hFindFile);
    FUN_40589504(_Stack_388.nFileSizeLow,_Stack_388.nFileSizeHigh,_Stack_388.cFileName + 0x102,0x20)
    ;
    FileTimeToLocalFileTime(&_Stack_388.ftLastWriteTime,&_Stack_3a0);
    FileTimeToSystemTime(&_Stack_3a0,&_Stack_398);
    GetDateFormatW(0x400,2,&_Stack_398,(LPCWSTR)0x0,aWStack_118,0x40);
    GetTimeFormatW(0x400,0,&_Stack_398,(LPCWSTR)0x0,aWStack_98,0x40);
    iVar1 = LoadStringW(DAT_405aa0c0,0x302f,(LPWSTR)0x0,0);
    HVar2 = StringCchPrintfExW(param_2,param_3,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,
                               L"%s\r\n%s %s, %s",_Stack_388.cFileName + 0x102,iVar1,aWStack_118,
                               aWStack_98);
    bVar3 = -1 < HVar2;
    FUN_405a7174(local_18);
  }
  return bVar3;
}



/* 4058b6c4 FUN_4058b6c4 */

/* Boundary evidence: original MIPS .pdata 4058b6c4..4058b817. Semantic name remains unreviewed. */

undefined4 FUN_4058b6c4(int *param_1,LPCITEMIDLIST param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  undefined2 extraout_var;
  int iVar2;
  HRESULT HVar3;
  DWORD dwFileAttributes;
  BOOL BVar4;
  LPWSTR pWVar5;
  STRRET local_330;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  local_330.uType = 0;
  memset(&local_330.u,0,0x104);
  uVar1 = FUN_4058114c((char *)param_2);
  if (((CONCAT22(extraout_var,uVar1) != 0) &&
      (iVar2 = (**(code **)(*param_1 + 0x2c))(param_1,param_2,0x8000,&local_330), -1 < iVar2)) &&
     (HVar3 = StrRetToBufW(&local_330,param_2,aWStack_228,0x104), -1 < HVar3)) {
    dwFileAttributes = GetFileAttributesW(aWStack_228);
    if (dwFileAttributes != 0xffffffff) {
      dwFileAttributes = ~param_4 & dwFileAttributes | param_3;
    }
    BVar4 = SetFileAttributesW(aWStack_228,dwFileAttributes);
    if ((BVar4 == 0) && (BVar4 = PathIsDirectoryW(aWStack_228), BVar4 == 0)) {
      pWVar5 = PathFindFileNameW(aWStack_228);
      FUN_4058a544((HWND)0x0,pWVar5,(wchar_t *)0x303c,aWStack_228,0x10);
      FUN_405a7174(local_20);
      return 0x80004005;
    }
  }
  FUN_405a7174(local_20);
  return 0;
}



/* 4058b818 FUN_4058b818 */

/* Boundary evidence: original MIPS .pdata 4058b818..4058b983. Semantic name remains unreviewed. */

undefined4 FUN_4058b818(HWND param_1,int param_2,wchar_t *param_3)

{
  HWND hWnd;
  HDC hdc;
  int iVar1;
  undefined4 uVar2;
  size_t local_250 [2];
  tagSIZE local_248;
  tagRECT local_240;
  WCHAR local_230 [4];
  wchar_t awStack_228 [259];
  undefined2 local_22;
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  local_240.left = 0;
  memset(&local_240.top,0,0xc);
  builtin_memcpy(local_230,L"...",8);
  hWnd = GetDlgItem(param_1,param_2);
  if (((param_3 == (wchar_t *)0x0) || (hdc = GetDC(hWnd), hWnd == (HWND)0x0)) || (hdc == (HDC)0x0))
  {
    FUN_405a7174(local_20);
    uVar2 = 0;
  }
  else {
    GetClientRect(hWnd,&local_240);
    wcsncpy(awStack_228,param_3,0x103);
    local_22 = 0;
    GetTextExtentExPointW(hdc,local_230,3,0,(LPINT)0x0,(LPINT)0x0,&local_248);
    local_248.cx = local_248.cx + 2;
    iVar1 = FUN_40589adc(hdc,param_3,&local_240.left,local_250,local_248.cx);
    ReleaseDC(hWnd,hdc);
    if (iVar1 != 0) {
      wcscpy(awStack_228 + local_250[0],local_230);
    }
    SetWindowTextW(hWnd,awStack_228);
    FUN_405a7174(local_20);
    uVar2 = 1;
  }
  return uVar2;
}



/* 4058b984 FUN_4058b984 */

/* Boundary evidence: original MIPS .pdata 4058b984..4058bc03. Semantic name remains unreviewed. */

void FUN_4058b984(void)

{
  bool bVar1;
  INT_PTR IVar2;
  int iVar3;
  uint uVar4;
  undefined3 extraout_var;
  LPCWSTR lpWindowName;
  HWND hWnd;
  undefined2 *hMem;
  HCURSOR pHVar5;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  int local_78;
  uint local_74;
  undefined8 local_70;
  PROPSHEETHEADERW_V2 local_68;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  code *local_28;
  int *local_24;
  undefined4 local_20;
  
  local_78 = FUN_4058862c();
  FUN_40586a28(DAT_405aa0d4,0);
  local_74 = FUN_40584ebc();
  local_70 = FUN_40585898();
  FUN_40583798(DAT_405aa0d4);
  local_68.hplWatermark = (HPALETTE)0x8;
  local_34 = 0x2312;
  local_28 = FUN_40589fb8;
  local_24 = &local_78;
  local_2c = 0x3039;
  local_68.u5 = DAT_405aa0c0;
  local_68.hInstance = (HINSTANCE)DAT_405aa0c0;
  local_68.pszCaption = (LPCWSTR)0x303d;
  local_68.u3.ppsp = (LPCPROPSHEETPAGEW)&local_68.u4;
  local_68.u4 = (_union_1967)0x28;
  local_68.dwSize = 0x28;
  local_30 = 0;
  local_20 = 0;
  local_68.dwFlags = 0x108;
  local_68.hwndParent = (HWND)0x0;
  local_68.u.hIcon = (HICON)0x0;
  local_68.u2.nStartPage = 0;
  local_68.pfnCallback = (PFNPROPSHEETCALLBACK)&LAB_4058a44c;
  local_68.nPages = 1;
  if (DAT_405aa2fc == (HWND)0x0) {
    IVar2 = PropertySheetW(&local_68);
    if (IVar2 != -1) {
      iVar3 = FUN_4058862c();
      if (local_78 != iVar3) {
        FUN_405887d0(local_78);
      }
      FUN_40586a28(DAT_405aa0d4,0);
      uVar4 = FUN_40584ebc();
      if ((local_74 != uVar4) && (FUN_40585818(DAT_405aa0d4,local_74), local_78 != 0)) {
        bVar1 = FUN_40584f40();
        if ((CONCAT31(extraout_var,bVar1) == 0) && (iVar3 = FUN_4058689c(DAT_405aa0d4), iVar3 != 0))
        {
          lpWindowName = (LPCWSTR)LoadStringW(DAT_405aa0c0.pszbmHeader,0x305a,(LPWSTR)0x0,0);
          hWnd = FindWindowW(L"Dialog",lpWindowName);
          if (hWnd == (HWND)0x0) {
            hMem = LocalAlloc(0,2);
            if (hMem != (undefined2 *)0x0) {
              *hMem = 0;
              pHVar5 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
              pHVar5 = SetCursor(pHVar5);
              hResInfo = FindResourceW((HMODULE)DAT_405aa0c0.hbmHeader,(LPCWSTR)0x2313,(LPCWSTR)0x5)
              ;
              hDialogTemplate = LoadResource((HMODULE)DAT_405aa0c0.hbmHeader,hResInfo);
              DialogBoxIndirectParamW
                        ((HINSTANCE)DAT_405aa0c0.hbmHeader,hDialogTemplate,(HWND)0x0,FUN_4058a468,
                         (LPARAM)hMem);
              SetCursor(pHVar5);
              LocalFree(hMem);
            }
          }
          else {
            SetForegroundWindow(hWnd);
          }
        }
      }
      FUN_40583798(DAT_405aa0d4);
      DAT_405aa2fc = (HWND)0x0;
    }
  }
  else {
    SetForegroundWindow(DAT_405aa2fc);
  }
  return;
}



/* 4058bc04 FUN_4058bc04 */

/* Boundary evidence: original MIPS .pdata 4058bc04..4058bec3. Semantic name remains unreviewed. */

HRESULT FUN_4058bc04(LPCWSTR param_1,LPCWSTR param_2,HWND param_3,INT_PTR *param_4)

{
  DWORD DVar1;
  DWORD DVar2;
  STRSAFE_LPCWSTR pszFormat;
  LPWSTR pWVar3;
  HRESULT HVar4;
  int iVar5;
  HCURSOR pHVar6;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar7;
  UINT uID;
  undefined4 local_b00;
  undefined1 auStack_afc [692];
  undefined4 local_848;
  HANDLE local_844;
  wchar_t awStack_840 [516];
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  wchar_t awStack_428 [256];
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if (((param_1 == (LPCWSTR)0x0) || (param_2 == (LPCWSTR)0x0)) || (param_4 == (INT_PTR *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    HVar4 = -0x7ff8ffa9;
  }
  else {
    DVar1 = GetFileAttributesW(param_1);
    DVar2 = GetFileAttributesW(param_2);
    if ((DVar1 == 0xffffffff) || (DVar2 == 0xffffffff)) {
      FUN_405a7174(local_28);
      HVar4 = -0x7fffbffb;
    }
    else {
      if ((DVar2 & 4) == 0) {
        if ((DVar2 & 1) == 0) {
          uID = 0x3055;
        }
        else {
          uID = 0x3056;
        }
      }
      else {
        uID = 0x3057;
      }
      pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,uID,(LPWSTR)0x0,0);
      pWVar3 = PathFindFileNameW(param_2);
      HVar4 = StringCchPrintfExW(awStack_840,0x204,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,
                                 pszFormat,pWVar3);
      if (HVar4 < 0) {
        FUN_405a7174(local_28);
      }
      else {
        local_848 = 0x3054;
        local_844 = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1302,1,0x20,0x20,0);
        local_438 = 0;
        local_434 = 1;
        FUN_4058b548(param_2,awStack_428,0x100);
        FUN_4058b548(param_1,awStack_228,0x100);
        local_b00 = 0;
        memset(auStack_afc,0,0x2b0);
        iVar5 = SHGetFileInfo(param_2,0,&local_b00,0x2b4,0x100);
        if (iVar5 != 0) {
          local_430 = local_b00;
        }
        iVar5 = SHGetFileInfo(param_1,0,&local_b00,0x2b4,0x100);
        if (iVar5 != 0) {
          local_42c = local_b00;
        }
        pHVar6 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
        pHVar6 = SetCursor(pHVar6);
        hResInfo = FindResourceW(DAT_405aa0c0,(LPCWSTR)0x2202,(LPCWSTR)0x5);
        hDialogTemplate = LoadResource(DAT_405aa0c0,hResInfo);
        IVar7 = DialogBoxIndirectParamW
                          (DAT_405aa0c0,hDialogTemplate,param_3,FUN_4058a5b0,(LPARAM)&local_848);
        *param_4 = IVar7;
        SetCursor(pHVar6);
        FUN_405a7174(local_28);
        HVar4 = 0;
      }
    }
  }
  return HVar4;
}



/* 4058bec4 FUN_4058bec4 */

/* Boundary evidence: original MIPS .pdata 4058bec4..4058c52f. Semantic name remains unreviewed. */

undefined4 FUN_4058bec4(HWND param_1,int param_2,undefined4 param_3,int param_4)

{
  LONG LVar1;
  size_t sVar2;
  HWND pHVar3;
  uint uVar4;
  wchar_t *dwNewLong;
  WPARAM WVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  WCHAR aWStack_60 [30];
  uint local_24;
  
  local_24 = DAT_405a9a3c;
  LVar1 = GetWindowLongW(param_1,8);
  if (param_2 == 2) {
    uVar7 = *(uint *)(LVar1 + 0xad0);
    uVar8 = *(uint *)(LVar1 + 0xacc);
    *(undefined4 *)(LVar1 + 0xad0) = 0;
    *(undefined4 *)(LVar1 + 0xacc) = 0;
    if (*(int *)(LVar1 + 0xad8) == 0) {
      uVar6 = (uint)((uVar7 & 1) != 0);
      if (((*(int *)(LVar1 + 0xad4) != 0) && (uVar6 != 0)) && ((uVar8 & 1) == 0)) {
        uVar6 = 2;
      }
      pHVar3 = GetDlgItem(param_1,0x230c);
      uVar4 = SendMessageW(pHVar3,0xf0,0,0);
      if ((uVar4 != uVar6) && (*(uint *)(LVar1 + 0xad0) = *(uint *)(LVar1 + 0xad0) | 1, uVar4 != 0))
      {
        *(uint *)(LVar1 + 0xacc) = *(uint *)(LVar1 + 0xacc) | 1;
      }
      uVar6 = (uint)((uVar7 & 2) != 0);
      if (((*(int *)(LVar1 + 0xad4) != 0) && (uVar6 != 0)) && ((uVar8 & 2) == 0)) {
        uVar6 = 2;
      }
      pHVar3 = GetDlgItem(param_1,0x2305);
      uVar4 = SendMessageW(pHVar3,0xf0,0,0);
      if ((uVar4 != uVar6) && (*(uint *)(LVar1 + 0xad0) = *(uint *)(LVar1 + 0xad0) | 2, uVar4 != 0))
      {
        *(uint *)(LVar1 + 0xacc) = *(uint *)(LVar1 + 0xacc) | 2;
      }
      uVar6 = (uint)((uVar7 & 0x20) != 0);
      if (((*(int *)(LVar1 + 0xad4) != 0) && (uVar6 != 0)) && ((uVar8 & 0x20) == 0)) {
        uVar6 = 2;
      }
      pHVar3 = GetDlgItem(param_1,0x2302);
      uVar4 = SendMessageW(pHVar3,0xf0,0,0);
      if ((uVar4 != uVar6) &&
         (*(uint *)(LVar1 + 0xad0) = *(uint *)(LVar1 + 0xad0) | 0x20, uVar4 != 0)) {
        *(uint *)(LVar1 + 0xacc) = *(uint *)(LVar1 + 0xacc) | 0x20;
      }
      uVar7 = (uint)((uVar7 & 4) != 0);
      if (((*(int *)(LVar1 + 0xad4) != 0) && (uVar7 != 0)) && ((uVar8 & 4) == 0)) {
        uVar7 = 2;
      }
      pHVar3 = GetDlgItem(param_1,0x230e);
      uVar8 = SendMessageW(pHVar3,0xf0,0,0);
      if ((uVar8 != uVar7) && (*(uint *)(LVar1 + 0xad0) = *(uint *)(LVar1 + 0xad0) | 4, uVar8 != 0))
      {
        *(uint *)(LVar1 + 0xacc) = *(uint *)(LVar1 + 0xacc) | 4;
      }
    }
  }
  else if (param_2 == 0x110) {
    dwNewLong = *(wchar_t **)(param_4 + 0x1c);
    SetWindowLongW(param_1,8,(LONG)dwNewLong);
    SendDlgItemMessageW(param_1,0x230a,0x172,1,*(LPARAM *)(dwNewLong + 0x564));
    FUN_4058b818(param_1,0x2303,dwNewLong);
    FUN_4058b818(param_1,0x2311,dwNewLong + 0x104);
    FUN_4058b818(param_1,0x2306,dwNewLong + 0x154);
    FUN_405a6ca0(param_1,8);
    if (*(int *)(dwNewLong + 0x56e) != 0) {
      LoadStringW(DAT_405aa0c0,0x303b,aWStack_60,0x1e);
      SetDlgItemTextW(param_1,0x230d,aWStack_60);
      LoadStringW(DAT_405aa0c0,0x3058,aWStack_60,0x1e);
      SetDlgItemTextW(param_1,0x2309,aWStack_60);
    }
    sVar2 = wcslen(dwNewLong + 600);
    if (sVar2 == 0) {
      pHVar3 = GetDlgItem(param_1,0x230d);
      ShowWindow(pHVar3,0);
      pHVar3 = GetDlgItem(param_1,0x230b);
      ShowWindow(pHVar3,0);
    }
    else {
      FUN_4058b818(param_1,0x230b,dwNewLong + 600);
    }
    sVar2 = wcslen(dwNewLong + 0x35c);
    if (sVar2 == 0) {
      pHVar3 = GetDlgItem(param_1,0x2309);
      ShowWindow(pHVar3,0);
      pHVar3 = GetDlgItem(param_1,0x2308);
      ShowWindow(pHVar3,0);
    }
    else {
      SetDlgItemTextW(param_1,0x2308,dwNewLong + 0x35c);
    }
    if (*(int *)(dwNewLong + 0x56c) == 0) {
      WVar5 = (WPARAM)((*(uint *)(dwNewLong + 0x568) & 1) != 0);
      pHVar3 = GetDlgItem(param_1,0x230c);
      if (((*(int *)(dwNewLong + 0x56a) == 0) || (WVar5 == 0)) ||
         ((*(uint *)(dwNewLong + 0x566) & 1) != 0)) {
        PostMessageW(pHVar3,0xf4,3,0);
      }
      else {
        WVar5 = 2;
      }
      PostMessageW(pHVar3,0xf1,WVar5,0);
      WVar5 = (WPARAM)((*(uint *)(dwNewLong + 0x568) & 2) != 0);
      pHVar3 = GetDlgItem(param_1,0x2305);
      if (((*(int *)(dwNewLong + 0x56a) == 0) || (WVar5 == 0)) ||
         ((*(uint *)(dwNewLong + 0x566) & 2) != 0)) {
        PostMessageW(pHVar3,0xf4,3,0);
      }
      else {
        WVar5 = 2;
      }
      PostMessageW(pHVar3,0xf1,WVar5,0);
      WVar5 = (WPARAM)((*(uint *)(dwNewLong + 0x568) & 0x20) != 0);
      pHVar3 = GetDlgItem(param_1,0x2302);
      if (((*(int *)(dwNewLong + 0x56a) == 0) || (WVar5 == 0)) ||
         ((*(uint *)(dwNewLong + 0x566) & 0x20) != 0)) {
        PostMessageW(pHVar3,0xf4,3,0);
      }
      else {
        WVar5 = 2;
      }
      PostMessageW(pHVar3,0xf1,WVar5,0);
      WVar5 = (WPARAM)((*(uint *)(dwNewLong + 0x568) & 4) != 0);
      pHVar3 = GetDlgItem(param_1,0x230e);
      if (((*(int *)(dwNewLong + 0x56a) == 0) || (WVar5 == 0)) ||
         ((*(uint *)(dwNewLong + 0x566) & 4) != 0)) {
        PostMessageW(pHVar3,0xf4,3,0);
      }
      else {
        WVar5 = 2;
      }
      PostMessageW(pHVar3,0xf1,WVar5,0);
    }
    else {
      pHVar3 = GetDlgItem(param_1,0x230c);
      ShowWindow(pHVar3,0);
      pHVar3 = GetDlgItem(param_1,0x2305);
      ShowWindow(pHVar3,0);
      pHVar3 = GetDlgItem(param_1,0x2302);
      ShowWindow(pHVar3,0);
      pHVar3 = GetDlgItem(param_1,0x230e);
      ShowWindow(pHVar3,0);
      pHVar3 = GetDlgItem(param_1,0x2304);
      ShowWindow(pHVar3,0);
    }
    FUN_405a7174(local_24);
    return 0xffffffff;
  }
  FUN_405a7174(local_24);
  return 0;
}



/* 4058c530 FUN_4058c530 */

/* Boundary evidence: original MIPS .pdata 4058c530..4058c797. Semantic name remains unreviewed. */

undefined4 FUN_4058c530(HWND param_1,int param_2,undefined4 param_3,int param_4)

{
  LONG LVar1;
  HWND pHVar2;
  size_t sVar3;
  int iVar4;
  int *dwNewLong;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  LVar1 = GetWindowLongW(param_1,8);
  if (param_2 == 2) {
    *(undefined4 *)(LVar1 + 0x558) = 0;
    GetDlgItemTextW(param_1,0x230f,aWStack_228,0x104);
    iVar4 = CompareStringW(0x400,1,aWStack_228,-1,(wchar_t *)(LVar1 + 0x104),-1);
    if (iVar4 != 2) {
      wcscpy((wchar_t *)(LVar1 + 0x104),aWStack_228);
      *(undefined4 *)(LVar1 + 0x558) = 1;
    }
    FUN_405a6bf8();
  }
  else if (param_2 == 0x110) {
    FUN_405a6b40();
    FUN_405a6df8(param_1);
    dwNewLong = *(int **)(param_4 + 0x1c);
    SetWindowLongW(param_1,8,(LONG)dwNewLong);
    SendDlgItemMessageW(param_1,0x230a,0x172,1,*(LPARAM *)(*dwNewLong + 0xac8));
    FUN_4058b818(param_1,0x2303,(wchar_t *)*dwNewLong);
    FUN_4058b818(param_1,0x2310,(wchar_t *)(dwNewLong + 1));
    SetDlgItemTextW(param_1,0x230f,(LPCWSTR)(dwNewLong + 0x41));
    pHVar2 = GetDlgItem(param_1,0x230f);
    SendMessageW(pHVar2,0xc5,0x100,0);
    if (dwNewLong[0x155] == 0) {
      pHVar2 = GetDlgItem(param_1,0x230f);
      EnableWindow(pHVar2,0);
    }
    sVar3 = wcslen((wchar_t *)(dwNewLong + 0xd3));
    if (sVar3 == 0) {
      pHVar2 = GetDlgItem(param_1,0x2309);
      ShowWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x2308);
      ShowWindow(pHVar2,0);
    }
    else {
      FUN_4058b818(param_1,0x2308,(wchar_t *)(dwNewLong + 0xd3));
    }
    sVar3 = wcslen((wchar_t *)(dwNewLong + 0xc3));
    if (sVar3 == 0) {
      pHVar2 = GetDlgItem(param_1,0x230d);
      ShowWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x230b);
      ShowWindow(pHVar2,0);
    }
    else {
      FUN_4058b818(param_1,0x230b,(wchar_t *)(dwNewLong + 0xc3));
    }
    FUN_405a6ca0(param_1,2);
    FUN_405a7174(local_20);
    return 0xffffffff;
  }
  FUN_405a7174(local_20);
  return 0;
}



/* 4058c798 FUN_4058c798 */

/* Boundary evidence: original MIPS .pdata 4058c798..4058d4c3. Semantic name remains unreviewed. */

undefined4 FUN_4058c798(undefined4 *param_1)

{
  bool bVar1;
  ushort uVar2;
  STRSAFE_LPWSTR _Dest;
  undefined4 *puVar3;
  int iVar4;
  undefined2 extraout_var;
  DWORD DVar5;
  BOOL BVar6;
  undefined2 extraout_var_00;
  LPWSTR pWVar7;
  size_t sVar8;
  ushort *puVar9;
  undefined2 extraout_var_01;
  STRSAFE_LPCWSTR pszSrc;
  HANDLE hFindFile;
  wchar_t *pwVar10;
  HICON pHVar11;
  INT_PTR IVar12;
  HRESULT HVar13;
  undefined2 *puVar14;
  int iVar15;
  uint uVar16;
  undefined4 *puVar17;
  STRSAFE_LPWSTR pwVar18;
  int *piVar19;
  uint uVar20;
  LPCITEMIDLIST pIVar21;
  int iVar22;
  STRSAFE_LPWSTR pszDest;
  uint uVar23;
  int *piVar24;
  LPCITEMIDLIST local_d18;
  undefined4 *local_d14;
  int local_d10;
  LPCITEMIDLIST local_d0c;
  uint local_d08;
  uint local_d04;
  uint local_d00;
  LPCITEMIDLIST local_cfc;
  int *local_cf8;
  undefined4 *local_cf4;
  undefined4 *local_cf0;
  IShellFolder *local_cec;
  int local_ce8;
  int *local_ce4;
  undefined4 *local_ce0;
  PROPSHEETHEADERW_V2 local_cd8;
  undefined4 local_ca4;
  undefined4 local_c9c;
  code *local_c98;
  STRSAFE_LPWSTR local_c94;
  undefined4 local_c88;
  undefined4 local_c84;
  HINSTANCE local_c80;
  undefined4 local_c7c;
  undefined4 local_c74;
  code *local_c70;
  undefined4 *local_c6c;
  undefined4 local_c60;
  undefined1 auStack_c5c [24];
  int local_c44;
  int local_c40;
  STRRET local_c38;
  undefined4 local_b30;
  undefined1 auStack_b2c [528];
  WCHAR aWStack_91c [82];
  _WIN32_FIND_DATAW _Stack_878;
  WCHAR local_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  puVar17 = (undefined4 *)param_1[3];
  piVar24 = (int *)param_1[1];
  piVar19 = (int *)param_1[2];
  pIVar21 = (LPCITEMIDLIST)*param_1;
  bVar1 = false;
  local_ce8 = 0;
  local_d10 = 0;
  local_d18 = (LPCITEMIDLIST)0x0;
  local_cd8.u4.hbmWatermark = (HBITMAP)0x0;
  local_d14 = puVar17;
  local_d0c = pIVar21;
  local_cf8 = piVar19;
  local_cf0 = puVar17;
  local_ce4 = piVar24;
  local_ce0 = param_1;
  memset(&local_cd8.hplWatermark,0,0x4c);
  local_cd8.dwSize = 0;
  memset(&local_cd8.dwFlags,0,0x24);
  local_b30 = 0;
  memset(auStack_b2c,0,0x2b0);
  uVar23 = param_1[4];
  iVar22 = 0;
  iVar15 = 0;
  local_d00 = uVar23;
  if (pIVar21 == (LPCITEMIDLIST)0x0) goto LAB_4058d41c;
  if ((((piVar24 != (int *)0x0) && (puVar17 != (undefined4 *)0x0)) && (uVar23 != 0)) &&
     (_Dest = LocalAlloc(0x40,0xae0), piVar19 = local_cf8, _Dest != (STRSAFE_LPWSTR)0x0)) {
    puVar3 = LocalAlloc(0x40,0x55c);
    local_cf4 = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = _Dest;
      _Dest[0x566] = L'\xffff';
      _Dest[0x567] = L'\0';
      pwVar10 = _Dest + 0x104;
      _Dest[0x568] = L'\0';
      _Dest[0x569] = L'\0';
      _Dest[0x56c] = L'\0';
      _Dest[0x56d] = L'\0';
      *pwVar10 = L'\0';
      iVar4 = FUN_4058150c((ushort *)local_d0c,&DAT_405719b0);
      if (iVar4 != 0) {
        local_d10 = 1;
      }
      local_cd8.hplWatermark = (HPALETTE)0x8;
      local_ca4 = 0x2300;
      local_c98 = FUN_4058bec4;
      local_c9c = 0x3036;
      local_cd8.u3.ppsp = (LPCPROPSHEETPAGEW)&local_cd8.u4;
      local_cd8.u4 = (_union_1967)0x28;
      local_cd8.u5.hbmHeader = (HBITMAP)DAT_405aa0c0;
      local_cd8.nPages = 1;
      local_cd8.dwSize = 0x28;
      local_cd8.dwFlags = 9;
      local_cd8.hInstance = DAT_405aa0c0;
      local_cd8.pszCaption = L"";
      local_c94 = _Dest;
      SHGetDesktopFolder(&local_cec);
      local_d08 = 0;
      local_d04 = 0;
      uVar16 = uVar23;
      uVar20 = local_d08;
      if (uVar23 != 0) {
        uVar20 = 0;
        puVar17 = local_cf0;
        do {
          local_c38.uType = 0;
          memset(&local_c38.u,0,0x104);
          local_440[0] = L'\0';
          local_d18 = (LPCITEMIDLIST)*puVar17;
          if (local_d10 == 0) {
            (**(code **)(*piVar24 + 0x2c))(piVar24,local_d18,0x8000,&local_c38);
          }
          else {
            FUN_40586a28(DAT_405aa0d4,0);
            (**(code **)(*piVar24 + 0x2c))(piVar24,local_d18,0x8000,&local_c38);
            FUN_40583798(DAT_405aa0d4);
          }
          StrRetToBufW(&local_c38,local_d18,local_440,0x104);
          SHGetFileInfo(local_440,0,&local_b30,0x2b4,0x500);
          if (!bVar1) {
            if (*pwVar10 == L'\0') {
              wcscpy(pwVar10,aWStack_91c);
            }
            else {
              iVar4 = CompareStringW(0x400,1,pwVar10,-1,aWStack_91c,-1);
              if (iVar4 != 2) {
                bVar1 = true;
              }
            }
          }
          uVar2 = FUN_4058114c((char *)local_d18);
          if (CONCAT22(extraout_var,uVar2) == 0) {
LAB_4058cb64:
            iVar15 = iVar15 + 1;
          }
          else {
            DVar5 = GetFileAttributesW(local_440);
            if (DVar5 != 0xffffffff) {
              *(uint *)(_Dest + 0x568) = *(uint *)(_Dest + 0x568) | DVar5;
              *(uint *)(_Dest + 0x566) = *(uint *)(_Dest + 0x566) & DVar5;
            }
            local_d08 = 0x20000000;
            iVar4 = (**(code **)(*piVar24 + 0x24))(piVar24,1,&local_d18,&local_d08);
            if ((-1 < iVar4) && ((local_d08 & 0x20000000) != 0)) goto LAB_4058cb64;
            local_c60 = 0;
            iVar22 = iVar22 + 1;
            memset(auStack_c5c,0,0x20);
            BVar6 = GetFileAttributesExW(local_440,GetFileExInfoStandard,&local_c60);
            if (BVar6 != 0) {
              uVar20 = local_c40 + uVar20;
              local_d04 = local_c44 + local_d04;
            }
          }
          uVar23 = uVar23 - 1;
          puVar17 = puVar17 + 1;
          puVar3 = local_cf4;
          uVar16 = local_d00;
        } while (uVar23 != 0);
      }
      local_d08 = uVar20;
      pwVar18 = _Dest + 600;
      FUN_40589504(local_d08,local_d04,pwVar18,0x104);
      uVar23 = uVar16;
      if ((iVar22 == 0) && (iVar15 == 0)) {
        _Dest[0x56a] = L'\0';
        _Dest[0x56b] = L'\0';
      }
      else if (iVar15 + iVar22 == 1) {
        _Dest[0x56a] = L'\0';
        _Dest[0x56b] = L'\0';
        *(undefined4 *)(_Dest + 0x564) = local_b30;
        uVar2 = FUN_405811d8((char *)local_d18);
        if (CONCAT22(extraout_var_00,uVar2) == 0) {
          pszDest = _Dest + 0x460;
          StringCchCopyExW(pszDest,0x104,local_440,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800);
          pWVar7 = _Dest + 0x35c;
          *pWVar7 = L'\0';
          FUN_4058937c(pszDest,pWVar7,0x104);
          iVar15 = PathIsLink(pszDest);
          if (iVar15 == 0) {
LAB_4058cef0:
            BVar6 = PathIsDirectoryW(pszDest);
            if (BVar6 != 0) {
              *pwVar18 = L'\0';
              *pWVar7 = L'\0';
              DVar5 = GetFileAttributesW(pszDest);
              if ((DVar5 != 0xffffffff) && ((DVar5 & 0x100) != 0)) {
                FUN_40589c60((int)_Dest);
                _Dest[0x56e] = L'\x01';
                _Dest[0x56f] = L'\0';
              }
              _Dest[0x56c] = L'\x01';
              _Dest[0x56d] = L'\0';
            }
          }
          else {
            pwVar10 = (wchar_t *)(puVar3 + 0x41);
            iVar15 = SHGetShortcutTarget(pszDest,pwVar10,0x104);
            if (iVar15 == 0) goto LAB_4058cef0;
            puVar3[0x155] = (uint)(local_d10 == 0);
            PathRemoveQuotesAndArgs(pwVar10);
            iVar15 = PathIsGUID(pwVar10);
            if (-1 < iVar15) {
              sVar8 = wcslen(pwVar10);
              if (0 < (int)sVar8) {
                puVar14 = (undefined2 *)((sVar8 + 0x83) * 2 + (int)puVar3);
                do {
                  sVar8 = sVar8 - 1;
                  *puVar14 = puVar14[-2];
                  puVar14 = puVar14 + -1;
                } while (0 < (int)sVar8);
              }
              *(undefined2 *)((int)puVar3 + 0x106) = 0x3a;
              *pwVar10 = L':';
            }
            HVar13 = (*local_cec->lpVtbl->ParseDisplayName)
                               (local_cec,(HWND)0x0,(IBindCtx *)0x0,pwVar10,(ULONG *)&local_cf0,
                                &local_cfc,(ULONG *)0x0);
            if (HVar13 < 0) {
              LoadStringW(DAT_405aa0c0,0x3030,(LPWSTR)(puVar3 + 1),0x80);
            }
            else {
              *(wchar_t *)(puVar3 + 0xc3) = L'\0';
              *(WCHAR *)(puVar3 + 0xd3) = L'\0';
              puVar9 = FUN_40581470((ushort *)local_cfc);
              uVar2 = FUN_405811d8((char *)puVar9);
              if (CONCAT22(extraout_var_01,uVar2) == 0) {
                SHGetPathFromIDList(local_cfc,_Stack_878.cFileName + 0x102);
                SHGetFileInfo(_Stack_878.cFileName + 0x102,0,&local_b30,0x2b4,0x400);
                wcscpy((wchar_t *)(puVar3 + 1),aWStack_91c);
                DVar5 = GetFileAttributesW(_Stack_878.cFileName + 0x102);
                if ((DVar5 != 0xffffffff) && ((DVar5 & 0x10) == 0)) {
                  hFindFile = FindFirstFileW(_Stack_878.cFileName + 0x102,&_Stack_878);
                  if (hFindFile != (HANDLE)0xffffffff) {
                    FindClose(hFindFile);
                    FUN_40589504(_Stack_878.nFileSizeLow,_Stack_878.nFileSizeHigh,
                                 (STRSAFE_LPWSTR)(puVar3 + 0xc3),0x20);
                  }
                  FUN_4058937c(_Stack_878.cFileName + 0x102,(LPWSTR)(puVar3 + 0xd3),0x104);
                }
              }
              else {
                local_ce8 = 1;
                pszSrc = (STRSAFE_LPCWSTR)FUN_40580ed0((int)local_d0c);
                StringCchCopyExW(pwVar10,0x104,pszSrc,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800);
                LoadStringW(DAT_405aa0c0,0x303f,(LPWSTR)(puVar3 + 1),0x80);
                puVar3[0x155] = 0;
              }
              FUN_40580ef4(local_cfc);
              piVar24 = local_ce4;
            }
            if (local_ce8 == 0) {
              SHGetShortcutTarget(pszDest,pwVar10,0x104);
            }
            local_c88 = 0x28;
            local_c84 = 8;
            local_c7c = 0x2301;
            local_c80 = DAT_405aa0c0;
            local_c70 = FUN_4058c530;
            local_cd8.nPages = local_cd8.nPages + 1;
            local_c74 = 0x301d;
            local_c6c = puVar3;
          }
          pIVar21 = local_d0c;
          iVar15 = FUN_4058150c((ushort *)local_d0c,&DAT_405719b0);
          if ((iVar15 == 0) || (local_d10 == 0)) {
            StringCchCopyExW(_Stack_878.cFileName + 0x102,0x104,pszDest,(STRSAFE_LPWSTR *)0x0,
                             (size_t *)0x0,0x800);
            iVar15 = FUN_405885e4();
            if (((iVar15 == 0) &&
                (BVar6 = PathIsDirectoryW(_Stack_878.cFileName + 0x102), BVar6 == 0)) ||
               (iVar15 = PathIsLink(_Stack_878.cFileName + 0x102), iVar15 != 0)) {
              PathRemoveExtensionW(_Stack_878.cFileName + 0x102);
            }
            pWVar7 = PathFindFileNameW(_Stack_878.cFileName + 0x102);
            wcscpy(_Dest,pWVar7);
          }
          else {
            _Dest[0x35c] = L'\0';
            _Dest[0x56c] = L'\x01';
            _Dest[0x56d] = L'\0';
            FUN_40586a28(DAT_405aa0d4,0);
            pwVar10 = FUN_40584b7c(DAT_405aa0d4,(int)local_d18);
            FUN_40583798(DAT_405aa0d4);
            if ((pwVar10 != (wchar_t *)0x0) &&
               (StringCchCopyExW(_Dest,0x104,pwVar10,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800),
               DAT_405aa0c8 != (int *)0x0)) {
              (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,pwVar10);
            }
            iVar15 = FUN_405885e4();
            if (((iVar15 == 0) && (BVar6 = PathIsDirectoryW(_Dest), BVar6 == 0)) ||
               (iVar15 = PathIsLink(_Dest), iVar15 != 0)) {
              PathRemoveExtensionW(_Dest);
            }
          }
        }
        else {
          *pwVar18 = L'\0';
          _Dest[0x35c] = L'\0';
          _Dest[0x56c] = L'\x01';
          _Dest[0x56d] = L'\0';
          pWVar7 = PathFindFileNameW(local_440);
          StringCchCopyExW(_Dest,0x104,pWVar7,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800);
          pIVar21 = local_d0c;
        }
        if (local_d10 == 0) {
          FUN_40589e34(pIVar21,_Dest + 0x154);
          uVar23 = local_d00;
        }
        else {
          StringCchCopyExW(_Dest + 0x154,0x104,L"Recycle Bin",(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,
                           0x800);
          uVar23 = local_d00;
        }
      }
      else {
        _Dest[0x56a] = L'\x01';
        _Dest[0x56b] = L'\0';
        LoadStringW(DAT_405aa0c0,0x3035,aWStack_238,0x104);
        wsprintfW(_Dest,aWStack_238,iVar22,iVar15);
        if ((iVar22 != 0) && (iVar15 != 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          LoadStringW(DAT_405aa0c0,0x3042,pwVar10,0x50);
        }
        else {
          _Stack_878.cFileName[0x102] = L'\0';
          LoadStringW(DAT_405aa0c0,0x3040,aWStack_238,0x104);
          wcscpy(_Stack_878.cFileName + 0x102,pwVar10);
          wsprintfW(pwVar10,aWStack_238,_Stack_878.cFileName + 0x102);
        }
        pHVar11 = LoadIconW(DAT_405aa0c0,(LPCWSTR)0x1000);
        *(HICON *)(_Dest + 0x564) = pHVar11;
        LoadStringW(DAT_405aa0c0,0x3027,aWStack_238,0x104);
        iVar15 = local_d10;
        if (local_d10 == 0) {
          _Stack_878.cFileName[0x102] = L'\0';
          FUN_40589e34(local_d0c,_Stack_878.cFileName + 0x102);
        }
        else {
          StringCchCopyExW(_Stack_878.cFileName + 0x102,0x104,L"Recycle Bin",(STRSAFE_LPWSTR *)0x0,
                           (size_t *)0x0,0x800);
        }
        wsprintfW(_Dest + 0x154,aWStack_238,_Stack_878.cFileName + 0x102);
        _Dest[0x35c] = L'\0';
        if (iVar22 == 0) {
          _Dest[0x56c] = L'\x01';
          _Dest[0x56d] = L'\0';
          *pwVar18 = L'\0';
        }
        if (iVar15 != 0) {
          _Dest[0x56c] = L'\x01';
          _Dest[0x56d] = L'\0';
        }
      }
      (*local_cec->lpVtbl->Release)(local_cec);
      local_cd8.pszCaption = _Dest;
      iVar15 = FUN_405a6b40();
      if (iVar15 != 0) {
        FUN_405a6d64();
      }
      IVar12 = PropertySheetW(&local_cd8);
      puVar17 = local_d14;
      if (IVar12 != 0) {
        if (*(int *)(_Dest + 0x568) != 0) {
          bVar1 = false;
          uVar16 = 0;
          if (uVar23 != 0) {
            do {
              local_d18 = (LPCITEMIDLIST)*puVar17;
              iVar15 = FUN_4058b6c4(piVar24,local_d18,*(uint *)(_Dest + 0x566),
                                    *(uint *)(_Dest + 0x568));
              puVar3 = local_cf4;
              if (iVar15 < 0) break;
              uVar16 = uVar16 + 1;
              bVar1 = true;
              puVar17 = puVar17 + 1;
            } while (uVar16 < uVar23);
            if (bVar1) {
              (**(code **)(*local_cf8 + 0x20))();
            }
          }
        }
        puVar17 = local_d14;
        if (((1 < local_cd8.nPages) && (puVar3[0x155] != 0)) &&
           ((puVar3[0x156] != 0 && (uVar23 == 1)))) {
          local_c38.uType = 0;
          memset(&local_c38.u,0,0x104);
          puVar17 = local_d14;
          pWVar7 = _Dest + 0x460;
          local_d18 = (LPCITEMIDLIST)*local_d14;
          *pWVar7 = L'\0';
          iVar15 = (**(code **)(*piVar24 + 0x2c))(piVar24,local_d18,0x8000,&local_c38);
          if ((-1 < iVar15) &&
             (HVar13 = StrRetToBufW(&local_c38,local_d18,pWVar7,0x104), -1 < HVar13)) {
            DVar5 = GetFileAttributesW(pWVar7);
            if ((DVar5 != 0xffffffff) && ((DVar5 & 1) != 0)) {
              SetFileAttributesW(pWVar7,0);
            }
            DeleteFileW(pWVar7);
            SHCreateShortcut(pWVar7,(wchar_t *)(puVar3 + 0x41));
          }
        }
      }
      FUN_405a6bf8();
      LocalFree(puVar3);
      pIVar21 = local_d0c;
    }
    if (*(HICON *)(_Dest + 0x564) != (HICON)0x0) {
      DestroyIcon(*(HICON *)(_Dest + 0x564));
    }
    LocalFree(_Dest);
    piVar19 = local_cf8;
    param_1 = local_ce0;
  }
  FUN_40580ef4(pIVar21);
LAB_4058d41c:
  if (piVar24 != (int *)0x0) {
    (**(code **)(*piVar24 + 8))(piVar24);
  }
  if (piVar19 != (int *)0x0) {
    (**(code **)(*piVar19 + 8))(piVar19);
  }
  puVar3 = puVar17;
  if (puVar17 != (undefined4 *)0x0) {
    for (; uVar23 != 0; uVar23 = uVar23 - 1) {
      FUN_40580ef4((HLOCAL)*puVar3);
      puVar3 = puVar3 + 1;
    }
    LocalFree(puVar17);
  }
  LocalFree(param_1);
  FUN_405a7174(local_30);
  return 0;
}



/* 4058d4c4 FUN_4058d4c4 */

/* Boundary evidence: original MIPS .pdata 4058d4c4..4058d867. Semantic name remains unreviewed. */

undefined4 FUN_4058d4c4(undefined4 *param_1)

{
  uint uVar1;
  uint *puVar2;
  STRSAFE_LPWSTR pszDest;
  HRESULT HVar3;
  int iVar4;
  BOOL BVar5;
  DWORD DVar6;
  LPWSTR pszSrc;
  LPCITEMIDLIST pidl;
  int *piVar7;
  LPCWSTR pszPath;
  LPCITEMIDLIST pidl_00;
  LPCITEMIDLIST local_438;
  int *local_434;
  undefined4 local_430;
  undefined4 local_42c;
  HINSTANCE local_428;
  undefined4 local_424;
  undefined4 local_41c;
  code *local_418;
  STRSAFE_LPWSTR local_414;
  undefined1 local_408 [43];
  undefined4 uStack_3dd;
  undefined4 local_2d8;
  undefined1 auStack_2d4 [528];
  wchar_t awStack_c4 [80];
  uint local_24;
  
  local_24 = DAT_405a9a3c;
  pidl_00 = (LPCITEMIDLIST)*param_1;
  piVar7 = (int *)param_1[1];
  local_430 = 0;
  memset(&local_42c,0,0x24);
  local_408._0_4_ = 0;
  memset(local_408 + 4,0,0x24);
  local_2d8 = 0;
  memset(auStack_2d4,0,0x2b0);
  uVar1 = (uint)&uStack_3dd & 3;
  puVar2 = (uint *)((int)&uStack_3dd - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  local_434 = (int *)0x0;
  local_438 = (LPCITEMIDLIST)0x0;
  stack0xfffffc20 = (HBITMAP)0x0;
  memset((void *)((int)&uStack_3dd + 1),0,0x104);
  if (pidl_00 != (LPCITEMIDLIST)0x0) {
    if ((piVar7 != (int *)0x0) && (pszDest = LocalAlloc(0x40,0xae0), pszDest != (STRSAFE_LPWSTR)0x0)
       ) {
      local_424 = 0x2300;
      local_418 = FUN_4058bec4;
      local_408._20_4_ = (LPCWSTR)0x3036;
      local_408._32_4_ = &local_430;
      local_430 = 0x28;
      local_42c = 8;
      local_428 = DAT_405aa0c0;
      local_41c = 0x303a;
      local_408._24_4_ = 1;
      local_408._0_4_ = 0x28;
      local_408._4_4_ = 8;
      local_408._12_4_ = DAT_405aa0c0;
      pszDest[0x56a] = L'\0';
      pszDest[0x56b] = L'\0';
      local_414 = pszDest;
      HVar3 = SHBindToParent(pidl_00,(IID *)&DAT_40572b68,&local_434,&local_438);
      if ((-1 < HVar3) &&
         (iVar4 = (**(code **)(*local_434 + 0x2c))(local_434,local_438,0x8000,local_408 + 0x28),
         -1 < iVar4)) {
        StrRetToBufW((STRRET *)(local_408 + 0x28),local_438,pszDest + 0x460,0x104);
      }
      if (local_434 != (int *)0x0) {
        (**(code **)(*local_434 + 8))();
      }
      if (local_438 != (LPCITEMIDLIST)0x0) {
        FUN_40580ef4(local_438);
      }
      pszPath = pszDest + 0x460;
      BVar5 = PathIsDirectoryW(pszPath);
      if (BVar5 != 0) {
        SHGetFileInfo(pszPath,0,&local_2d8,0x2b4,0x500);
        *(undefined4 *)(pszDest + 0x564) = local_2d8;
        wcscpy(pszDest + 0x104,awStack_c4);
        pszDest[600] = L'\0';
        pszDest[0x35c] = L'\0';
        pszDest[0x56c] = L'\x01';
        pszDest[0x56d] = L'\0';
        DVar6 = GetFileAttributesW(pszPath);
        if ((DVar6 != 0xffffffff) && ((DVar6 & 0x100) != 0)) {
          FUN_40589c60((int)pszDest);
          pszDest[0x56e] = L'\x01';
          pszDest[0x56f] = L'\0';
        }
        pszSrc = PathFindFileNameW(pszPath);
        StringCchCopyExW(pszDest,0x104,pszSrc,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800);
        iVar4 = FUN_40581410((ushort *)pidl_00);
        if (iVar4 != 0) {
          pidl = FUN_405813a0((ushort *)pidl_00,iVar4 + -1);
          HVar3 = SHBindToParent(pidl,(IID *)&DAT_40572b68,&local_434,&local_438);
          if ((-1 < HVar3) &&
             (iVar4 = (**(code **)(*local_434 + 0x2c))(local_434,local_438,0x1000,local_408 + 0x28),
             -1 < iVar4)) {
            StrRetToBufW((STRRET *)(local_408 + 0x28),local_438,pszDest + 0x154,0x104);
          }
          if (local_434 != (int *)0x0) {
            (**(code **)(*local_434 + 8))();
          }
          if (local_438 != (LPCITEMIDLIST)0x0) {
            FUN_40580ef4(local_438);
          }
          if (pidl != (LPCITEMIDLIST)0x0) {
            FUN_40580ef4(pidl);
          }
        }
      }
      PropertySheetW((LPCPROPSHEETHEADERW)local_408);
      if (*(HICON *)(pszDest + 0x564) != (HICON)0x0) {
        DestroyIcon(*(HICON *)(pszDest + 0x564));
      }
      LocalFree(pszDest);
    }
    FUN_40580ef4(pidl_00);
  }
  if (piVar7 != (int *)0x0) {
    (**(code **)(*piVar7 + 8))(piVar7);
  }
  LocalFree(param_1);
  FUN_405a7174(local_24);
  return 0;
}



/* 4058d868 FUN_4058d868 */

/* Boundary evidence: original MIPS .pdata 4058d868..4058d9cf. Semantic name remains unreviewed. */

void FUN_4058d868(ushort *param_1,int *param_2,int *param_3,int param_4,int param_5)

{
  undefined4 *lpParameter;
  HLOCAL pvVar1;
  int iVar2;
  HANDLE hObject;
  int iVar3;
  
  if (((((param_1 != (ushort *)0x0) && (param_2 != (int *)0x0)) && (param_3 != (int *)0x0)) &&
      ((param_4 != 0 && (param_5 != 0)))) &&
     (lpParameter = LocalAlloc(0x40,0x14), lpParameter != (undefined4 *)0x0)) {
    pvVar1 = FUN_405813a0(param_1,-1);
    *lpParameter = pvVar1;
    lpParameter[1] = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    lpParameter[2] = param_3;
    (**(code **)(*param_3 + 4))(param_3);
    iVar2 = (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,param_5 << 2);
    lpParameter[3] = iVar2;
    if ((iVar2 != 0) && (param_5 != 0)) {
      iVar3 = 0;
      iVar2 = param_5;
      do {
        if (*(ushort **)(iVar3 + param_4) != (ushort *)0x0) {
          pvVar1 = FUN_405813a0(*(ushort **)(iVar3 + param_4),-1);
          *(HLOCAL *)(iVar3 + lpParameter[3]) = pvVar1;
        }
        iVar2 = iVar2 + -1;
        iVar3 = iVar3 + 4;
      } while (iVar2 != 0);
    }
    lpParameter[4] = param_5;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_4058c798,lpParameter,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
  }
  return;
}



/* 4058d9d0 FUN_4058d9d0 */

/* Boundary evidence: original MIPS .pdata 4058d9d0..4058da83. Semantic name remains unreviewed. */

void FUN_4058d9d0(ushort *param_1,int *param_2)

{
  undefined4 *lpParameter;
  HLOCAL pvVar1;
  HANDLE hObject;
  
  if (((param_1 != (ushort *)0x0) && (param_2 != (int *)0x0)) &&
     (lpParameter = LocalAlloc(0x40,8), lpParameter != (undefined4 *)0x0)) {
    pvVar1 = FUN_405813a0(param_1,-1);
    *lpParameter = pvVar1;
    lpParameter[1] = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_4058d4c4,lpParameter,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
  }
  return;
}



/* 4058da84 FUN_4058da84 */

/* Boundary evidence: original MIPS .pdata 4058da84..4058dc13. Semantic name remains unreviewed. */

undefined4
FUN_4058da84(wchar_t *param_1,wchar_t *param_2,STRSAFE_LPWSTR param_3,size_t param_4,
            wchar_t *param_5)

{
  FILE *_File;
  int iVar1;
  HRESULT HVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  STRSAFE_LPWSTR local_230 [2];
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  uVar4 = 0;
  local_230[0] = (wchar_t *)0x0;
  if ((((param_5 != (wchar_t *)0x0) && (param_1 != (wchar_t *)0x0)) && (param_2 != (wchar_t *)0x0))
     && (((param_3 != (STRSAFE_LPWSTR)0x0 && (param_4 != 0)) &&
         (_File = _wfopen(param_5,L"r"), _File != (FILE *)0x0)))) {
    while (pwVar3 = fgetws(awStack_228,0x100,_File), pwVar3 != (wchar_t *)0x0) {
      pwVar3 = wcsstr(awStack_228,param_1);
      if (pwVar3 != (wchar_t *)0x0) {
        while (pwVar3 = fgetws(awStack_228,0x100,_File), pwVar3 != (wchar_t *)0x0) {
          local_230[0] = wcschr(awStack_228,L'=');
          if (local_230[0] != (wchar_t *)0x0) {
            *local_230[0] = L'\0';
            iVar1 = _wcsicmp(awStack_228,param_2);
            if (iVar1 == 0) {
              local_230[0] = local_230[0] + 1;
              HVar2 = StringCchCopyExW(param_3,param_4,local_230[0],local_230,(size_t *)0x0,0);
              if (HVar2 < 0) {
                uVar4 = 0;
              }
              else {
                local_230[0] = local_230[0] + -1;
                uVar4 = 1;
                if (*local_230[0] == L'\n') {
                  *local_230[0] = L'\0';
                }
              }
            }
          }
        }
      }
    }
    fclose(_File);
  }
  FUN_405a7174(local_28);
  return uVar4;
}



/* 4058dc14 FUN_4058dc14 */

/* Boundary evidence: original MIPS .pdata 4058dc14..4058e1a3. Semantic name remains unreviewed. */

bool FUN_4058dc14(wchar_t *param_1,wchar_t *param_2,STRSAFE_PCNZWCH param_3,uint param_4,
                 wchar_t *param_5)

{
  bool bVar1;
  bool bVar2;
  DWORD dwFileAttributes;
  FILE *_File;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  HRESULT HVar6;
  HANDLE hFile;
  uint cchToCopy;
  bool bVar7;
  size_t cchToCopy_00;
  size_t local_458;
  STRSAFE_LPWSTR local_454;
  size_t local_450;
  wchar_t *local_44c;
  fpos_t fStack_448;
  wchar_t *local_440;
  fpos_t fStack_438;
  wchar_t awStack_430 [256];
  wchar_t awStack_230 [256];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  bVar7 = false;
  local_454 = (wchar_t *)0x0;
  local_44c = param_2;
  local_440 = param_1;
  if ((((param_5 != (wchar_t *)0x0) && (param_1 != (wchar_t *)0x0)) && (param_2 != (wchar_t *)0x0))
     && (((param_3 != (STRSAFE_PCNZWCH)0x0 || (param_4 == 0)) &&
         ((param_4 < 0x100 &&
          (dwFileAttributes = GetFileAttributesW(param_5), dwFileAttributes != 0xffffffff)))))) {
    SetFileAttributesW(param_5,dwFileAttributes & 0xfffffffe);
    _File = _wfopen(param_5,L"r+");
    if (_File != (FILE *)0x0) {
      local_450 = 0;
      bVar2 = false;
      pwVar3 = fgetws(awStack_430,0x100,_File);
      if (pwVar3 != (wchar_t *)0x0) {
        do {
          pwVar3 = wcsstr(awStack_430,param_1);
          if (pwVar3 != (wchar_t *)0x0) {
            iVar4 = fgetpos(_File,&fStack_438);
            if ((iVar4 != 0) || (iVar4 = fgetpos(_File,&fStack_448), iVar4 != 0)) break;
            pwVar3 = fgetws(awStack_430,0x100,_File);
            while (pwVar3 != (wchar_t *)0x0) {
              local_458 = wcslen(awStack_430);
              local_454 = wcschr(awStack_430,L'=');
              if (local_454 != (wchar_t *)0x0) {
                *local_454 = L'\0';
                iVar4 = _wcsicmp(awStack_430,param_2);
                if (iVar4 == 0) {
                  *local_454 = L'=';
                  local_454 = local_454 + 1;
                  if ((param_3 == (STRSAFE_PCNZWCH)0x0) || (param_4 == 0)) {
                    bVar2 = true;
                    local_458 = 0;
                  }
                  else {
                    cchToCopy_00 = (int)local_454 - (int)awStack_430 >> 1;
                    HVar6 = StringCchCopyNExW(awStack_230,0x100,awStack_430,cchToCopy_00,&local_454,
                                              &local_450,0);
                    param_2 = local_44c;
                    if (-1 < HVar6) {
                      cchToCopy = local_458 - cchToCopy_00;
                      if (param_4 <= local_458 - cchToCopy_00) {
                        cchToCopy = param_4;
                      }
                      HVar6 = StringCchCopyNExW(local_454,local_450,param_3,cchToCopy,&local_454,
                                                &local_450,0x100);
                      param_2 = local_44c;
                      if (-1 < HVar6) {
                        bVar2 = true;
                        bVar1 = awStack_430[local_458 - 1] == L'\n';
                        if (bVar1) {
                          local_458 = local_458 - 1;
                        }
                        if (local_458 - cchToCopy_00 < param_4) {
                          if (bVar1) {
                            local_458 = local_458 + 1;
                          }
                          param_3 = param_3 + (local_458 - cchToCopy_00);
                          HVar6 = StringCchCopyNExW(awStack_430,0x100,param_3,
                                                    (cchToCopy_00 - local_458) + param_4,&local_454,
                                                    &local_458,0);
                          if ((HVar6 < 0) ||
                             (((bVar1 && (HVar6 = StringCchCopyW(local_454,local_458,L"\n"),
                                         HVar6 < 0)) ||
                              (HVar6 = StringCchLengthW(awStack_430,0x100,&local_458), HVar6 < 0))))
                          {
                            bVar2 = false;
                          }
                        }
                        else {
                          if ((bVar1) &&
                             (HVar6 = StringCchCopyW(local_454,local_450,L"\n"), HVar6 < 0)) {
                            bVar2 = false;
                          }
                          local_458 = 0;
                        }
                        HVar6 = StringCchLengthW(awStack_230,0x100,&local_450);
                        param_2 = local_44c;
                        if (HVar6 < 0) {
                          bVar2 = false;
                        }
                      }
                    }
                  }
                }
                else {
                  *local_454 = L'=';
                }
              }
              if (bVar2) {
                iVar4 = feof(_File);
                iVar5 = fgetpos(_File,&fStack_438);
                if ((iVar5 != 0) || (iVar5 = fsetpos(_File,&fStack_448), iVar5 != 0))
                goto LAB_4058e0f0;
                if (local_450 == 0) {
                  if (local_458 != 0) {
                    iVar5 = fputws(awStack_430,_File);
                    bVar7 = iVar5 != 0xffff;
                    local_458 = 0;
                  }
                }
                else {
                  iVar5 = fputws(awStack_230,_File);
                  bVar7 = iVar5 != 0xffff;
                  if ((local_458 == 0) ||
                     (HVar6 = StringCchCopyNW(awStack_230,0x100,awStack_430,local_458), HVar6 < 0))
                  {
                    local_450 = 0;
                  }
                  else {
                    local_450 = local_458;
                  }
                }
                iVar5 = fgetpos(_File,&fStack_448);
                if (((iVar5 != 0) || (iVar4 != 0)) ||
                   (iVar4 = fsetpos(_File,&fStack_438), iVar4 != 0)) goto LAB_4058e0f0;
              }
              else {
                iVar4 = fgetpos(_File,&fStack_438);
                if ((iVar4 != 0) || (iVar4 = fgetpos(_File,&fStack_448), iVar4 != 0))
                goto LAB_4058e14c;
              }
              pwVar3 = fgetws(awStack_430,0x100,_File);
              param_1 = local_440;
            }
          }
          pwVar3 = fgetws(awStack_430,0x100,_File);
        } while (pwVar3 != (wchar_t *)0x0);
LAB_4058e0f0:
        if ((bVar2) && (iVar4 = fsetpos(_File,&fStack_448), iVar4 == 0)) {
          if (local_450 != 0) {
            iVar4 = fputws(awStack_230,_File);
            bVar7 = true;
            if (iVar4 == 0xffff) {
              bVar7 = false;
            }
          }
          hFile = (HANDLE)_fileno(_File);
          SetEndOfFile(hFile);
        }
      }
LAB_4058e14c:
      fclose(_File);
    }
    SetFileAttributesW(param_5,dwFileAttributes);
  }
  FUN_405a7174(local_30);
  return bVar7;
}



/* 4058e1a4 FUN_4058e1a4 */

/* Boundary evidence: original MIPS .pdata 4058e1a4..4058e21f. Semantic name remains unreviewed. */

undefined4 * FUN_4058e1a4(undefined4 *param_1)

{
  HANDLE pvVar1;
  
  *param_1 = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_1[param_1[0xc] + 0xd] = pvVar1;
  param_1[0xc] = param_1[0xc] + 1;
  return param_1;
}



/* 4058e220 FUN_4058e220 */

/* Boundary evidence: original MIPS .pdata 4058e220..4058e2ff. Semantic name remains unreviewed. */

void FUN_4058e220(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  EventModify(*(undefined4 *)(param_1 + 0x34),3);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  uVar2 = 1;
  if (1 < *(uint *)(param_1 + 0x30)) {
    puVar1 = (undefined4 *)(param_1 + 0xb4);
    do {
      (**(code **)(*(int *)*puVar1 + 4))();
      (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,0x8000000,0,0);
      (**(code **)(*(int *)*puVar1 + 8))();
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x30));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return;
}



/* 4058e300 FUN_4058e300 */

/* Boundary evidence: original MIPS .pdata 4058e300..4058e573. Semantic name remains unreviewed. */

void FUN_4058e300(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  int *piVar6;
  HLOCAL local_38;
  uint local_34;
  HLOCAL local_30 [2];
  
  local_34 = 0;
  iVar1 = CeGetFileNotificationInfo(param_2,0,0,0,0,&local_34);
  if (iVar1 != 0) {
    if (0xfff < local_34) {
      local_34 = 0xfff;
    }
    iVar1 = (**(code **)(*DAT_405aa0c8 + 0xc))();
    if (iVar1 != 0) {
      iVar2 = CeGetFileNotificationInfo(param_2,0,iVar1,local_34,0,0);
      if (iVar2 != 0) {
        iVar2 = 0;
        local_38 = (HLOCAL)0x0;
        do {
          piVar6 = (int *)(iVar2 + iVar1);
          iVar3 = wcscmp(L"\\",(wchar_t *)(piVar6 + 3));
          if (iVar3 == 0) {
            (**(code **)(*param_3 + 0xc))(param_3,0x10,0,0);
          }
          else {
            iVar3 = FUN_40587d0c((STRSAFE_PCNZWCH)(piVar6 + 3),&local_38);
            if (-1 < iVar3) {
              iVar3 = piVar6[1];
              if (iVar3 == 1) {
                uVar4 = 2;
LAB_4058e4dc:
                pcVar5 = *(code **)(*param_3 + 0xc);
LAB_4058e4e4:
                (*pcVar5)(param_3,uVar4,local_38,0);
              }
              else {
                if (iVar3 == 2) {
                  uVar4 = 4;
                  goto LAB_4058e4dc;
                }
                if (iVar3 == 3) {
                  uVar4 = 0x800;
                  goto LAB_4058e4dc;
                }
                if (iVar3 != 4) {
                  if (iVar3 != 0x10000) goto LAB_4058e4f4;
                  (**(code **)(*param_3 + 0xc))(param_3,0x800,local_38,0);
                  pcVar5 = *(code **)(*param_3 + 0xc);
                  uVar4 = 0x2000;
                  goto LAB_4058e4e4;
                }
                iVar2 = *piVar6 + iVar2;
                piVar6 = (int *)(iVar2 + iVar1);
                local_30[0] = (HLOCAL)0x0;
                iVar3 = FUN_40587d0c((STRSAFE_PCNZWCH)(piVar6 + 3),local_30);
                if (-1 < iVar3) {
                  (**(code **)(*param_3 + 0xc))(param_3,1,local_38,local_30[0]);
                  FUN_40580ef4(local_30[0]);
                }
              }
LAB_4058e4f4:
              FUN_40580ef4(local_38);
              local_38 = (HLOCAL)0x0;
            }
          }
          iVar2 = *piVar6 + iVar2;
        } while (*piVar6 != 0);
      }
      (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,iVar1);
    }
  }
  return;
}



/* 4058e574 FUN_4058e574 */

/* Boundary evidence: original MIPS .pdata 4058e574..4058e657. Semantic name remains unreviewed. */

void FUN_4058e574(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 1;
  param_1[0xb] = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  EventModify(param_1[0xd],3);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if (1 < (uint)param_1[0xc]) {
    puVar1 = param_1 + 0xe;
    do {
      FindCloseChangeNotification((HANDLE)*puVar1);
      (**(code **)(*(int *)puVar1[0x1f] + 8))();
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (uVar2 < (uint)param_1[0xc]);
  }
  CloseHandle((HANDLE)*param_1);
  *param_1 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return;
}



/* 4058e658 FUN_4058e658 */

/* Boundary evidence: original MIPS .pdata 4058e658..4058e7ab. Semantic name remains unreviewed. */

void FUN_4058e658(int param_1)

{
  DWORD DVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  piVar2 = (int *)0x0;
  if (*(int *)(param_1 + 0x2c) == 0) {
    do {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
      DVar1 = WaitForMultipleObjects
                        (*(DWORD *)(param_1 + 0x30),(HANDLE *)(param_1 + 0x34),0,0xffffffff);
      if ((DVar1 != 0) && (DVar1 < *(uint *)(param_1 + 0x30))) {
        piVar2 = *(int **)((DVar1 + 0x2c) * 4 + param_1);
        uVar3 = *(undefined4 *)((DVar1 + 0xd) * 4 + param_1);
        (**(code **)(*piVar2 + 4))(piVar2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
      if (DVar1 == 0) {
        EventModify(*(HANDLE *)(param_1 + 0x34),2);
      }
      else if (DVar1 < *(uint *)(param_1 + 0x30)) {
        FUN_4058e300(param_1,uVar3,piVar2);
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    } while (*(int *)(param_1 + 0x2c) == 0);
  }
  return;
}



/* 4058e7ac FUN_4058e7ac */

/* Boundary evidence: original MIPS .pdata 4058e7ac..4058e977. Semantic name remains unreviewed. */

bool FUN_4058e7ac(int *param_1,int param_2)

{
  int iVar1;
  HANDLE pvVar2;
  int *piVar3;
  uint uVar4;
  HANDLE hHandle;
  uint uVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  piVar3 = param_1 + 0xd;
  EventModify(*piVar3,3);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  uVar4 = 0;
  uVar5 = 0xffffffff;
  if (param_1[0xc] != 0) {
    do {
      if (param_2 == *piVar3) {
        uVar5 = uVar4;
        if (uVar4 != 0xffffffff) {
          FindCloseChangeNotification((HANDLE)param_1[uVar4 + 0xd]);
          (**(code **)(*(int *)param_1[uVar4 + 0x2c] + 8))();
          iVar1 = param_1[0xc];
          param_1[0xc] = iVar1 + -1;
          memcpy(param_1 + uVar4 + 0xd,param_1 + uVar4 + 0xe,((iVar1 + -1) - uVar4) * 4);
          memcpy(param_1 + uVar4 + 0x2c,param_1 + uVar4 + 0x2d,(param_1[0xc] - uVar4) * 4);
        }
        break;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
      uVar5 = 0xffffffff;
    } while (uVar4 < (uint)param_1[0xc]);
  }
  pvVar2 = (HANDLE)*param_1;
  hHandle = (HANDLE)0x0;
  if ((pvVar2 != (HANDLE)0x0) && (param_1[0xc] == 1)) {
    *param_1 = 0;
    param_1[0xb] = 1;
    hHandle = pvVar2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  return uVar5 != 0xffffffff;
}



/* 4058e978 FUN_4058e978 */

/* Boundary evidence: original MIPS .pdata 4058e978..4058e9d7. Semantic name remains unreviewed. */

void FUN_4058e978(int *param_1)

{
  if (*param_1 != 0) {
    FUN_4058e574(param_1);
  }
  if ((HANDLE)param_1[0xd] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0xd]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return;
}



/* 4058e9d8 FUN_4058e9d8 */

/* Boundary evidence: original MIPS .pdata 4058e9d8..4058e9f7. Semantic name remains unreviewed. */

undefined4 FUN_4058e9d8(int param_1)

{
  FUN_4058e658(param_1);
  return 0;
}



/* 4058e9f8 FUN_4058e9f8 */

/* Boundary evidence: original MIPS .pdata 4058e9f8..4058eb73. Semantic name remains unreviewed. */

int FUN_4058e9f8(int *param_1,LPCWSTR param_2,int param_3)

{
  HANDLE pvVar1;
  uint uVar2;
  int iVar3;
  
  if ((((param_2 == (LPCWSTR)0x0) || (param_3 == 0)) || (0x1f < (uint)param_1[0xc])) ||
     (pvVar1 = FindFirstChangeNotificationW(param_2,0,0x8000001b), pvVar1 == (HANDLE)0xffffffff)) {
    iVar3 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
    EventModify(param_1[0xd],3);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    param_1[param_1[0xc] + 0xd] = (int)pvVar1;
    param_1[param_1[0xc] + 0x2c] = param_3;
    (**(code **)(*(int *)param_1[param_1[0xc] + 0x2c] + 4))();
    uVar2 = param_1[0xc] + 1;
    iVar3 = param_1[param_1[0xc] + 0xd];
    param_1[0xc] = uVar2;
    if ((*param_1 == 0) && (1 < uVar2)) {
      param_1[0xb] = 0;
      pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_4058e9d8,param_1,0,(LPDWORD)0x0);
      *param_1 = (int)pvVar1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  }
  return iVar3;
}



/* 4058eb74 FUN_4058eb74 */

/* Boundary evidence: original MIPS .pdata 4058eb74..4058ebbf. Semantic name remains unreviewed. */

void FUN_4058eb74(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40571ef4;
  param_1[1] = &PTR_LAB_40571ee0;
  param_1[2] = &PTR_LAB_40571ecc;
  if ((HLOCAL)param_1[4] != (HLOCAL)0x0) {
    FUN_40580ef4((HLOCAL)param_1[4]);
  }
  return;
}



/* 4058ebc0 FUN_4058ebc0 */

/* Boundary evidence: original MIPS .pdata 4058ebc0..4058ed8b. Semantic name remains unreviewed. */

undefined4 FUN_4058ebc0(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = *param_2;
    if (((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
        ) || (((iVar2 == 0x214e6 && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    else {
      if (((iVar2 == 0x214ec) && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))) {
        iVar2 = param_1 + 4;
      }
      else {
        if ((((iVar2 != 0x10c) || (param_2[1] != 0)) || (param_2[2] != 0xc0)) ||
           (param_2[3] != 0x46000000)) {
          if (iVar2 != 0x214ea) {
            return 0x80004002;
          }
          if (param_2[1] != 0) {
            return 0x80004002;
          }
          if (param_2[2] != 0xc0) {
            return 0x80004002;
          }
          if (param_2[3] != 0x46000000) {
            return 0x80004002;
          }
        }
        iVar2 = param_1 + 8;
      }
      if (param_1 == 0) {
        iVar2 = 0;
      }
      *param_3 = iVar2;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4058ed8c FUN_4058ed8c */

/* Boundary evidence: original MIPS .pdata 4058ed8c..4058efab. Semantic name remains unreviewed. */

HRESULT FUN_4058ed8c(undefined4 param_1,ushort *param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 *param_5)

{
  ushort uVar1;
  undefined2 extraout_var;
  LPCOLESTR lpsz;
  HRESULT HVar2;
  undefined4 *puVar3;
  HLOCAL pvVar4;
  char *pcVar5;
  int *local_40;
  int *local_3c;
  CLSID CStack_38;
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((param_2 == (ushort *)0x0) || (param_5 == (undefined4 *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return -0x7fffbffb;
  }
  *param_5 = 0;
  local_40 = (int *)0x0;
  uVar1 = FUN_405811d8((char *)param_2);
  if (CONCAT22(extraout_var,uVar1) == 0) {
    puVar3 = operator_new(0x20);
    if (puVar3 == (undefined4 *)0x0) {
      local_40 = (int *)0x0;
    }
    else {
      local_40 = FUN_405956e0(puVar3);
    }
    if (local_40 == (int *)0x0) {
      HVar2 = -0x7ff8fff2;
    }
    else {
      local_3c = (int *)0x0;
      HVar2 = (**(code **)*local_40)(local_40,&DAT_40572bf8,&local_3c);
      if (HVar2 < 0) goto LAB_4058ef4c;
      pvVar4 = FUN_405813a0(param_2,1);
      if (pvVar4 == (HLOCAL)0x0) {
        HVar2 = -0x7ff8fff2;
      }
      else {
        HVar2 = (**(code **)(*local_3c + 0x10))(local_3c,pvVar4);
        FUN_40580ef4(pvVar4);
      }
      (**(code **)(*local_3c + 8))();
    }
  }
  else {
    lpsz = (LPCOLESTR)FUN_40581264((int)param_2);
    HVar2 = CLSIDFromString(lpsz,&CStack_38);
    if (HVar2 < 0) goto LAB_4058ef4c;
    HVar2 = CoCreateInstance(&CStack_38,(LPUNKNOWN)0x0,1,(IID *)&DAT_40572b68,&local_40);
  }
  if (-1 < HVar2) {
    pcVar5 = FUN_40581214(param_2);
    if (pcVar5 == (char *)0x0) {
      HVar2 = (**(code **)*local_40)(local_40,param_4,param_5);
    }
    else {
      HVar2 = (*(code *)((undefined4 *)*local_40)[5])(local_40,pcVar5,param_3,param_4,param_5);
    }
  }
LAB_4058ef4c:
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40);
  }
  FUN_405a7174(local_28);
  return HVar2;
}



/* 4058efac FUN_4058efac */

/* Boundary evidence: original MIPS .pdata 4058efac..4058f11f. Semantic name remains unreviewed. */

uint FUN_4058efac(undefined4 param_1,undefined4 param_2,char *param_3,char *param_4)

{
  ushort uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  PCNZWCH lpString2;
  PCNZWCH lpString1;
  int iVar2;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  uint uVar3;
  uint uVar4;
  
  if ((param_3 == (char *)0x0) || (param_4 == (char *)0x0)) {
    uVar3 = 0x80070057;
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    uVar1 = FUN_405811d8(param_3);
    if ((CONCAT22(extraout_var,uVar1) == 0) ||
       (uVar1 = FUN_405811d8(param_4), CONCAT22(extraout_var_00,uVar1) == 0)) {
      uVar1 = FUN_405811d8(param_3);
      if ((CONCAT22(extraout_var_01,uVar1) == 0) ||
         (uVar1 = FUN_405811d8(param_4), CONCAT22(extraout_var_02,uVar1) != 0)) {
        uVar1 = FUN_405811d8(param_3);
        if ((CONCAT22(extraout_var_03,uVar1) == 0) &&
           (uVar1 = FUN_405811d8(param_4), CONCAT22(extraout_var_04,uVar1) != 0)) {
          uVar3 = 1;
        }
        else if (DAT_405aa300 == (int *)0x0) {
          uVar4 = 1;
        }
        else {
          uVar3 = (**(code **)(*DAT_405aa300 + 0x1c))(DAT_405aa300,param_2,param_3,param_4);
          uVar4 = (int)uVar3 >> 0x1f & 1;
          uVar3 = uVar3 & 0xffff;
        }
      }
      else {
        uVar3 = 0xffffffff;
      }
    }
    else {
      lpString2 = (PCNZWCH)FUN_40580ed0((int)param_4);
      lpString1 = (PCNZWCH)FUN_40580ed0((int)param_3);
      iVar2 = CompareStringW(0x400,1,lpString1,-1,lpString2,-1);
      if (iVar2 == 0) {
        uVar4 = 1;
      }
      else {
        uVar3 = iVar2 - 2;
      }
    }
    uVar3 = uVar4 << 0x1f | uVar3 & 0xffff;
  }
  return uVar3;
}



/* 4058f120 FUN_4058f120 */

/* Boundary evidence: original MIPS .pdata 4058f120..4058f30b. Semantic name remains unreviewed. */

HRESULT FUN_4058f120(int *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  HRESULT HVar4;
  int iVar5;
  LPITEMIDLIST local_28;
  int *local_24;
  
  HVar4 = -0x7fffbffe;
  if (param_4 == (undefined4 *)0x0) {
    HVar4 = -0x7ff8ffa9;
  }
  else {
    *param_4 = 0;
    if ((((*param_3 == 0x214e3) && (param_3[1] == 0)) && (param_3[2] == 0xc0)) &&
       (param_3[3] == 0x46000000)) {
      local_28 = (LPITEMIDLIST)0x0;
      HVar4 = SHGetSpecialFolderLocation((HWND)0x0,0x11,&local_28);
      if (-1 < HVar4) {
        (**(code **)(*param_1 + 4))(param_1);
        puVar1 = operator_new(0x78);
        if (puVar1 == (undefined4 *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = FUN_4059bc34(puVar1,param_1,(ushort *)local_28);
        }
        FUN_40580ef4(local_28);
        if (piVar2 == (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
          HVar4 = -0x7ff8fff2;
        }
        else {
          local_24 = (int *)0x0;
          iVar5 = 0;
          iVar3 = (**(code **)*piVar2)(piVar2,&DAT_40572c28,&local_24);
          if (-1 < iVar3) {
            iVar5 = FUN_4058e9f8(DAT_405aa0cc,L"\\",(int)local_24);
            if (iVar5 != 0) {
              piVar2[0x13] = iVar5;
            }
            (**(code **)(*local_24 + 8))();
          }
          HVar4 = (**(code **)*piVar2)(piVar2,param_3,param_4);
          if ((HVar4 < 0) && (iVar5 != 0)) {
            FUN_4058e7ac(DAT_405aa0cc,iVar5);
          }
          (**(code **)(*piVar2 + 8))(piVar2);
        }
      }
    }
  }
  return HVar4;
}



/* 4058f30c FUN_4058f30c */

/* Boundary evidence: original MIPS .pdata 4058f30c..4058f3f7. Semantic name remains unreviewed. */

undefined4
FUN_4058f30c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  ushort *local_20 [2];
  
  if (param_4 == (undefined4 *)0x0) {
    uVar4 = 0x80070057;
  }
  else {
    *param_4 = 0;
    uVar4 = 0;
    puVar1 = operator_new(0x34);
    if (puVar1 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_4059c4cc(puVar1,param_3);
    }
    if (piVar2 == (int *)0x0) {
      uVar4 = 0x8007000e;
    }
    else {
      local_20[0] = (ushort *)0x0;
      FUN_40587d78((IID *)&DAT_405719d0,(int *)local_20);
      iVar3 = FUN_4059bdbc(piVar2,&DAT_405719d0,local_20[0]);
      if (iVar3 == 0) {
        uVar4 = 0x80004005;
      }
      else {
        *param_4 = piVar2;
      }
      if (local_20[0] != (ushort *)0x0) {
        FUN_40580ef4(local_20[0]);
      }
    }
  }
  return uVar4;
}



/* 4058f3f8 FUN_4058f3f8 */

/* Boundary evidence: original MIPS .pdata 4058f3f8..4058f55b. Semantic name remains unreviewed. */

undefined4 FUN_4058f3f8(undefined4 param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (uint *)0x0)) {
    uVar3 = 0x80070057;
  }
  else {
    uVar3 = 0;
    iVar4 = 0;
    puVar2 = (undefined4 *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,param_2 << 2);
    if (puVar2 == (undefined4 *)0x0) {
      uVar3 = 0x8007000e;
    }
    else {
      puVar5 = puVar2;
      if (param_2 != 0) {
        do {
          uVar1 = FUN_405811d8((char *)*param_3);
          if (CONCAT22(extraout_var,uVar1) == 0) {
            iVar4 = iVar4 + 1;
            *puVar5 = *param_3;
            puVar5 = puVar5 + 1;
          }
          else {
            *param_4 = *param_4 & 0x98000014;
          }
          param_3 = param_3 + 1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
        if (iVar4 != 0) {
          if (DAT_405aa300 == (int *)0x0) {
            uVar3 = 0x8007000e;
          }
          else {
            uVar3 = (**(code **)(*DAT_405aa300 + 0x24))(DAT_405aa300,iVar4,puVar2,param_4);
          }
        }
      }
      (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,puVar2);
    }
  }
  return uVar3;
}



/* 4058f55c FUN_4058f55c */

/* Boundary evidence: original MIPS .pdata 4058f55c..4058f72f. Semantic name remains unreviewed. */

int FUN_4058f55c(undefined4 param_1,ushort *param_2,uint param_3,undefined4 *param_4)

{
  ushort uVar1;
  int iVar2;
  undefined2 extraout_var;
  STRSAFE_LPCWSTR pwVar3;
  undefined2 extraout_var_00;
  size_t sVar4;
  wchar_t *pwVar5;
  wchar_t local_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if ((param_2 == (ushort *)0x0) || (param_4 == (undefined4 *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return -0x7ff8ffa9;
  }
  iVar2 = FUN_40581410(param_2);
  if (iVar2 != 1) {
    FUN_405a7174(local_20);
    return -0x7fffbffb;
  }
  uVar1 = FUN_405811d8((char *)param_2);
  if (CONCAT22(extraout_var,uVar1) == 0) {
    pwVar5 = local_228;
    if ((param_3 & 1) == 0) {
      local_228[0] = L'\\';
      pwVar5 = local_228 + 1;
    }
    uVar1 = FUN_405811d8((char *)param_2);
    if ((CONCAT22(extraout_var_00,uVar1) != 0) && ((param_3 & 0x8000) != 0)) {
      *pwVar5 = L':';
      pwVar5[1] = L':';
      pwVar5 = pwVar5 + 2;
    }
    *pwVar5 = L'\0';
    if ((param_3 & 0x8000) != 0) goto LAB_4058f5f4;
    pwVar3 = (STRSAFE_LPCWSTR)FUN_40580ed0((int)param_2);
  }
  else {
    if ((param_3 & 0x8000) == 0) {
      pwVar3 = (STRSAFE_LPCWSTR)FUN_40580ed0((int)param_2);
      iVar2 = StringCchCopyW(local_228,0x104,pwVar3);
      goto LAB_4058f694;
    }
    wcscpy(local_228,L"::");
LAB_4058f5f4:
    pwVar3 = (STRSAFE_LPCWSTR)FUN_40581264((int)param_2);
  }
  iVar2 = StringCchCatW(local_228,0x104,pwVar3);
LAB_4058f694:
  if (-1 < iVar2) {
    sVar4 = wcslen(local_228);
    pwVar5 = (wchar_t *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar4 + 1) * 2);
    param_4[1] = pwVar5;
    if (pwVar5 == (wchar_t *)0x0) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      wcscpy(pwVar5,local_228);
      *param_4 = 0;
    }
  }
  FUN_405a7174(local_20);
  return iVar2;
}



/* 4058f730 FUN_4058f730 */

/* Boundary evidence: original MIPS .pdata 4058f730..4058f8c3. Semantic name remains unreviewed. */

undefined4 FUN_4058f730(void)

{
  undefined4 uVar1;
  int in_a3;
  int iVar2;
  int *in_stack_00000010;
  undefined4 *in_stack_00000018;
  
  if ((in_a3 == 0) || (in_stack_00000018 == (undefined4 *)0x0)) {
    uVar1 = 0x80070057;
  }
  else {
    *in_stack_00000018 = 0;
    uVar1 = 0x80004001;
    if (DAT_405aa300 == (int *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      iVar2 = *in_stack_00000010;
      if ((((iVar2 == 0x10e) && (in_stack_00000010[1] == 0)) && (in_stack_00000010[2] == 0xc0)) &&
         (in_stack_00000010[3] == 0x46000000)) {
        uVar1 = (**(code **)(*DAT_405aa300 + 0x28))();
      }
      else if (((iVar2 == 0x122) && (in_stack_00000010[1] == 0)) &&
              ((in_stack_00000010[2] == 0xc0 && (in_stack_00000010[3] == 0x46000000)))) {
        uVar1 = (**(code **)(*DAT_405aa300 + 0x28))();
      }
      else if (((iVar2 == 0x214e4) && (in_stack_00000010[1] == 0)) &&
              ((in_stack_00000010[2] == 0xc0 && (in_stack_00000010[3] == 0x46000000)))) {
        uVar1 = (**(code **)(*DAT_405aa300 + 0x28))();
      }
    }
  }
  return uVar1;
}



/* 4058f8c4 FUN_4058f8c4 */

/* Boundary evidence: original MIPS .pdata 4058f8c4..4058fbd7. Semantic name remains unreviewed. */

HRESULT FUN_4058f8c4(int *param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
                    undefined4 param_5,int *param_6,undefined4 param_7)

{
  int iVar1;
  wchar_t *pwVar2;
  STRSAFE_PCNZWCH _Dst;
  HLOCAL pvVar3;
  HRESULT HVar4;
  ushort *local_50;
  size_t local_4c;
  ushort *local_48;
  int *local_44;
  CLSID CStack_40;
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  if (param_6 == (int *)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    HVar4 = -0x7ff8ffa9;
  }
  else {
    *param_6 = 0;
    iVar1 = wcsncmp(param_4,L"::{",3);
    if (iVar1 == 0) {
      HVar4 = CLSIDFromString(param_4,&CStack_40);
      if (-1 < HVar4) {
        HVar4 = FUN_40587d78(&CStack_40,param_6);
      }
    }
    else if ((*param_4 == L'\0') || (*param_4 == L'\\')) {
      HVar4 = -0x7fffbffb;
    }
    else {
      local_50 = (ushort *)0x0;
      local_4c = 0;
      HVar4 = StringCchLengthW(param_4,0x104,&local_4c);
      if (-1 < HVar4) {
        pwVar2 = wcschr(param_4,L'\\');
        if (pwVar2 != (wchar_t *)0x0) {
          local_4c = (int)pwVar2 - (int)param_4 >> 1;
        }
        _Dst = (STRSAFE_PCNZWCH)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(local_4c + 1) * 2);
        if (_Dst == (STRSAFE_PCNZWCH)0x0) {
          HVar4 = -0x7ff8fff2;
        }
        else {
          memcpy(_Dst,param_4,local_4c << 1);
          _Dst[local_4c] = L'\0';
          HVar4 = FUN_40587d0c(_Dst,&local_50);
          FUN_40587714((LPCITEMIDLIST)param_1[4],(int *)&local_50);
          (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,_Dst);
          if (-1 < HVar4) {
            pwVar2 = param_4 + local_4c;
            if (*pwVar2 == L'\0') {
              pvVar3 = FUN_405813a0(local_50,-1);
              *param_6 = (int)pvVar3;
              if (pvVar3 == (HLOCAL)0x0) {
                HVar4 = -0x7ff8fff2;
              }
            }
            else {
              local_44 = (int *)0x0;
              HVar4 = (**(code **)(*param_1 + 0x14))(param_1,local_50,0,&DAT_40572b68,&local_44);
              if (-1 < HVar4) {
                local_48 = (ushort *)0x0;
                HVar4 = (**(code **)(*local_44 + 0xc))
                                  (local_44,param_2,param_3,pwVar2 + 1,param_5,&local_48,param_7);
                if (-1 < HVar4) {
                  if (local_48 == (ushort *)0x0) {
                    pvVar3 = FUN_405813a0(local_50,-1);
                    *param_6 = (int)pvVar3;
                  }
                  else {
                    pvVar3 = FUN_405812ec(local_50,local_48);
                    *param_6 = (int)pvVar3;
                    FUN_40580ef4(local_48);
                  }
                  if (*param_6 == 0) {
                    HVar4 = -0x7ff8fff2;
                  }
                }
                (**(code **)(*local_44 + 8))();
              }
            }
            FUN_40580ef4(local_50);
          }
        }
      }
    }
    FUN_405a7174(local_30);
  }
  return HVar4;
}



/* 4058fbd8 FUN_4058fbd8 */

/* Boundary evidence: original MIPS .pdata 4058fbd8..4058fe47. Semantic name remains unreviewed. */

DWORD FUN_4058fbd8(undefined4 param_1,HWND param_2,ushort *param_3,STRSAFE_LPCWSTR param_4,
                  undefined4 param_5,undefined4 *param_6)

{
  ushort uVar1;
  undefined2 extraout_var;
  DWORD DVar2;
  LPWSTR pWVar3;
  int iVar4;
  int iVar5;
  HRESULT HVar6;
  wchar_t *pwVar7;
  LPCWSTR pWVar8;
  HLOCAL local_440;
  size_t local_43c;
  wchar_t awStack_438 [260];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((param_3 == (ushort *)0x0) || (param_4 == (STRSAFE_LPCWSTR)0x0)) {
    DVar2 = 0x80070057;
    goto LAB_4058fe18;
  }
  uVar1 = FUN_405811d8((char *)param_3);
  if (CONCAT22(extraout_var,uVar1) == 0) {
    if (DAT_405aa300 != (int *)0x0) {
      DVar2 = (**(code **)(*DAT_405aa300 + 0x30))
                        (DAT_405aa300,param_2,param_3,param_4,param_5,param_6);
      goto LAB_4058fe18;
    }
LAB_4058fe04:
    DVar2 = 0x8007000e;
  }
  else {
    local_43c = 0;
    pwVar7 = (wchar_t *)0x0;
    pWVar8 = (LPCWSTR)0x0;
    DVar2 = StringCchCopyW(awStack_438,0x104,param_4);
    if ((int)DVar2 < 0) goto LAB_4058fe18;
    PathRemoveBlanksW(awStack_438);
    DVar2 = StringCchLengthW(awStack_438,0x104,&local_43c);
    if ((int)DVar2 < 0) goto LAB_4058fe18;
    if (local_43c == 0) {
      pwVar7 = (wchar_t *)0x3043;
      DVar2 = 0x80004005;
    }
    else {
      pWVar3 = PathFindFileNameW(awStack_438);
      iVar4 = PathIsValidFileName(pWVar3);
      if (iVar4 == 0) {
        iVar4 = LoadStringW(DAT_405aa0c0,0xc044,(LPWSTR)0x0,0);
        iVar5 = LoadStringW(DAT_405aa0c0,0xc05f,(LPWSTR)0x0,0);
        HVar6 = StringCchPrintfExW(awStack_230,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,
                                   L"%s%s",iVar5,iVar4);
        if (HVar6 < 0) {
          pwVar7 = (wchar_t *)LoadStringW(DAT_405aa0c0,0xc044,(LPWSTR)0x0,0);
        }
        else {
          pwVar7 = awStack_230;
          pWVar8 = (LPCWSTR)FUN_40580ed0((int)param_3);
        }
        DVar2 = 0x80004005;
      }
      if (-1 < (int)DVar2) {
        local_440 = FUN_405813a0(param_3,-1);
        if (local_440 != (HLOCAL)0x0) {
          DVar2 = FUN_40587f50(awStack_438,(int *)&local_440);
          if (((int)DVar2 < 0) || (param_6 == (undefined4 *)0x0)) {
            FUN_40580ef4(local_440);
          }
          else {
            *param_6 = local_440;
          }
          goto LAB_4058fe18;
        }
        goto LAB_4058fe04;
      }
    }
    FUN_4058a544(param_2,(LPCWSTR)0x3025,pwVar7,pWVar8,0x10);
  }
LAB_4058fe18:
  FUN_405a7174(local_28);
  return DVar2;
}



/* 4058fe48 FUN_4058fe48 */

/* Boundary evidence: original MIPS .pdata 4058fe48..4058ffa3. Semantic name remains unreviewed. */

int FUN_4058fe48(int param_1,char *param_2,int param_3,int param_4)

{
  ushort uVar1;
  undefined2 extraout_var;
  int iVar2;
  int *local_20 [2];
  
  if ((param_2 == (char *)0x0) || (param_4 == 0)) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar2 = 0;
    uVar1 = FUN_405811d8(param_2);
    if (CONCAT22(extraout_var,uVar1) == 0) {
      if (DAT_405aa300 == (undefined4 *)0x0) {
        iVar2 = -0x7ff8fff2;
      }
      else {
        local_20[0] = (int *)0x0;
        iVar2 = (**(code **)*DAT_405aa300)(DAT_405aa300,&DAT_40572c18,local_20);
        if (-1 < iVar2) {
          iVar2 = (**(code **)(*local_20[0] + 0xc))(local_20[0],param_2,param_3,param_4);
          (**(code **)(*local_20[0] + 8))();
        }
      }
    }
    else if (param_3 == 0) {
      iVar2 = (**(code **)(*(int *)(param_1 + -4) + 0x2c))
                        ((int *)(param_1 + -4),param_2,0x1001,param_4 + 8);
    }
    else if ((((param_3 != 1) && (param_3 != 2)) && (param_3 != 3)) && (param_3 != 4)) {
      iVar2 = -0x7fffbffb;
    }
  }
  return iVar2;
}



/* 4058ffd4 FUN_4058ffd4 */

/* Boundary evidence: original MIPS .pdata 4058ffd4..40590017. Semantic name remains unreviewed. */

int FUN_4058ffd4(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[3] + -1;
  param_1[3] = iVar1;
  if (iVar1 == 0) {
    FUN_4058eb74(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40590040 FUN_40590040 */

/* Boundary evidence: original MIPS .pdata 40590040..405900ef. Semantic name remains unreviewed. */

undefined4 * FUN_40590040(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  param_1[1] = &PTR_LAB_40571f30;
  *param_1 = &PTR_FUN_40571ef4;
  param_1[1] = &PTR_LAB_40571ee0;
  param_1[2] = &PTR_LAB_40571ecc;
  param_1[3] = 0;
  FUN_40587d78((IID *)&DAT_405719d0,param_1 + 4);
  if (DAT_405aa300 == (undefined4 *)0x0) {
    puVar1 = operator_new(0x20);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_405aa300 = (undefined4 *)0x0;
    }
    else {
      DAT_405aa300 = FUN_405956e0(puVar1);
    }
  }
  param_1[3] = 1;
  return param_1;
}



/* 405900f0 FUN_405900f0 */

/* Boundary evidence: original MIPS .pdata 405900f0..40590177. Semantic name remains unreviewed. */

void FUN_405900f0(undefined4 param_1,uint param_2,LPCWSTR param_3)

{
  wchar_t *pwVar1;
  uint uVar2;
  
  if ((param_2 & 0x1fff0000) == 0x70000) {
    uVar2 = param_2 & 0xffff;
    if (uVar2 == 5) {
      pwVar1 = (wchar_t *)0x3079;
      if (param_3 == (LPCWSTR)0x0) {
        pwVar1 = (wchar_t *)0x306d;
      }
    }
    else if (uVar2 == 0x35) {
      pwVar1 = (wchar_t *)0x306c;
    }
    else {
      if (uVar2 != 0x4c6) {
        return;
      }
      pwVar1 = (wchar_t *)0x306e;
    }
    FUN_4058a544((HWND)0x0,(LPCWSTR)0x306f,pwVar1,param_3,0x30);
  }
  return;
}



/* 40590178 FUN_40590178 */

/* Boundary evidence: original MIPS .pdata 40590178..405902af. Semantic name remains unreviewed. */

undefined4 FUN_40590178(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = *param_2;
    if (((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
        ) || (((iVar2 == 0x214e6 && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    else {
      if (iVar2 != 0x214ea) {
        return 0x80004002;
      }
      if (param_2[1] != 0) {
        return 0x80004002;
      }
      if (param_2[2] != 0xc0) {
        return 0x80004002;
      }
      if (param_2[3] != 0x46000000) {
        return 0x80004002;
      }
      iVar2 = param_1 + 4;
      if (param_1 == 0) {
        iVar2 = 0;
      }
      *param_3 = iVar2;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 405902b0 FUN_405902b0 */

/* Boundary evidence: original MIPS .pdata 405902b0..4059047f. Semantic name remains unreviewed. */

uint FUN_405902b0(undefined4 param_1,ushort *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  ushort uVar1;
  ushort *puVar2;
  undefined2 extraout_var;
  undefined4 *puVar3;
  int *piVar4;
  char *pcVar5;
  uint uVar6;
  
  if ((param_2 == (ushort *)0x0) || (param_5 == (undefined4 *)0x0)) {
    return 0x80070057;
  }
  *param_5 = 0;
  puVar2 = FUN_405813a0(param_2,1);
  if (puVar2 == (ushort *)0x0) {
    return 0x8007000e;
  }
  uVar1 = FUN_4058114c((char *)puVar2);
  if (CONCAT22(extraout_var,uVar1) == 0) {
    uVar6 = 0x80004005;
    goto LAB_4059042c;
  }
  puVar3 = operator_new(0x20);
  if (puVar3 == (undefined4 *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = FUN_405956e0(puVar3);
  }
  if (piVar4 == (int *)0x0) {
    uVar6 = 0x8007000e;
    goto LAB_4059042c;
  }
  pcVar5 = FUN_40581214(param_2);
  FUN_40593608((int)piVar4,1);
  if (pcVar5 == (char *)0x0) {
    uVar6 = (**(code **)(piVar4[2] + 0x10))();
    if (-1 < (int)uVar6) {
      uVar6 = (**(code **)*piVar4)(piVar4,param_4,param_5);
      goto LAB_405903e4;
    }
LAB_405903f0:
    FUN_405900f0(param_1,uVar6,(LPCWSTR)0x0);
  }
  else {
    uVar6 = FUN_40593590((int)piVar4,puVar2);
    if ((int)uVar6 < 0) goto LAB_405903f0;
    uVar6 = (**(code **)(*piVar4 + 0x14))(piVar4,pcVar5,param_3,param_4,param_5);
LAB_405903e4:
    if ((int)uVar6 < 0) goto LAB_405903f0;
  }
  (**(code **)(*piVar4 + 8))(piVar4);
LAB_4059042c:
  FUN_40580ef4(puVar2);
  return uVar6;
}



/* 405904b0 FUN_405904b0 */

/* Boundary evidence: original MIPS .pdata 405904b0..4059059f. Semantic name remains unreviewed. */

HRESULT FUN_405904b0(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  STRSAFE_LPWSTR pszDest;
  HRESULT HVar1;
  STRSAFE_LPCWSTR pszSrc;
  int iVar2;
  
  if ((param_2 == 0) || (param_4 == (undefined4 *)0x0)) {
    HVar1 = -0x7ff8ffa9;
  }
  else {
    pszDest = (STRSAFE_LPWSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,0x208);
    param_4[1] = pszDest;
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      HVar1 = -0x7ff8fff2;
    }
    else {
      *param_4 = 0;
      iVar2 = 0;
      if ((param_3 & 1) == 0) {
        *pszDest = L'\\';
        pszDest[1] = L'\\';
        pszDest = pszDest + 2;
        iVar2 = 2;
      }
      if ((param_3 & 0x8000) == 0) {
        pszSrc = (STRSAFE_LPCWSTR)FUN_40580ed0(param_2);
      }
      else {
        pszSrc = (STRSAFE_LPCWSTR)FUN_40581264(param_2);
      }
      HVar1 = StringCchCopyW(pszDest,0x104 - iVar2,pszSrc);
    }
  }
  return HVar1;
}



/* 405905a0 FUN_405905a0 */

/* Boundary evidence: original MIPS .pdata 405905a0..4059088b. Semantic name remains unreviewed. */

uint FUN_405905a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,LPCWSTR param_4,
                 undefined4 param_5,undefined4 *param_6,undefined4 param_7)

{
  uint uVar1;
  wchar_t *pwVar2;
  undefined4 *puVar3;
  int *piVar4;
  HLOCAL pvVar5;
  int *piVar6;
  STRSAFE_PCNZWCH psz;
  STRSAFE_PCNZWCH _Dst;
  size_t local_38;
  ushort *local_34;
  ushort *local_30;
  undefined4 local_2c;
  
  if (param_6 == (undefined4 *)0x0) {
    return 0x80070057;
  }
  if ((*param_4 != L'\\') || (param_4[1] != L'\\')) {
    return 0x80004005;
  }
  psz = param_4 + 2;
  local_34 = (ushort *)0x0;
  local_30 = (ushort *)0x0;
  local_38 = 0;
  _Dst = (STRSAFE_PCNZWCH)0x0;
  piVar6 = (int *)0x0;
  local_2c = param_2;
  uVar1 = StringCchLengthW(psz,0x104,&local_38);
  piVar4 = piVar6;
  if (-1 < (int)uVar1) {
    pwVar2 = wcschr(psz,L'\\');
    if (pwVar2 != (wchar_t *)0x0) {
      local_38 = (int)pwVar2 - (int)psz >> 1;
    }
    if (local_38 == 0) {
      uVar1 = 0x8007006f;
    }
    if (-1 < (int)uVar1) {
      _Dst = (STRSAFE_PCNZWCH)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(local_38 + 1) * 2);
      if (_Dst == (STRSAFE_PCNZWCH)0x0) goto LAB_405906b0;
      memcpy(_Dst,psz,local_38 << 1);
      _Dst[local_38] = L'\0';
      uVar1 = FUN_40587d0c(_Dst,&local_34);
      if (-1 < (int)uVar1) {
        if (pwVar2 == (wchar_t *)0x0) {
          pvVar5 = FUN_405813a0(local_34,-1);
          *param_6 = pvVar5;
          if (pvVar5 == (HLOCAL)0x0) {
            uVar1 = 0x8007000e;
          }
LAB_405907d0:
          if (-1 < (int)uVar1) goto LAB_405907e8;
        }
        else {
          puVar3 = operator_new(0x20);
          if (puVar3 == (undefined4 *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = FUN_405956e0(puVar3);
          }
          if (piVar4 != (int *)0x0) {
            FUN_40593608((int)piVar4,1);
            uVar1 = FUN_40593590((int)piVar4,local_34);
            if (((int)uVar1 < 0) ||
               (uVar1 = (**(code **)(*piVar4 + 0xc))
                                  (piVar4,local_2c,param_3,pwVar2 + 1,param_5,&local_30,param_7),
               (int)uVar1 < 0)) goto LAB_405907d8;
            pvVar5 = FUN_405812ec(local_34,local_30);
            *param_6 = pvVar5;
            piVar6 = piVar4;
            if (pvVar5 != (HLOCAL)0x0) goto LAB_405907d0;
          }
LAB_405906b0:
          uVar1 = 0x8007000e;
          piVar4 = piVar6;
        }
      }
    }
  }
LAB_405907d8:
  FUN_405900f0(param_1,uVar1,param_4);
LAB_405907e8:
  if (local_34 != (ushort *)0x0) {
    FUN_40580ef4(local_34);
  }
  if (local_30 != (ushort *)0x0) {
    FUN_40580ef4(local_30);
  }
  if (_Dst != (STRSAFE_PCNZWCH)0x0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,_Dst);
  }
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  return uVar1;
}



/* 405908a0 FUN_405908a0 */

/* Boundary evidence: original MIPS .pdata 405908a0..405908e3. Semantic name remains unreviewed. */

int FUN_405908a0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2] + -1;
  param_1[2] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_40571f58;
    param_1[1] = &PTR_LAB_40571f44;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 405908f8 FUN_405908f8 */

undefined4 * FUN_405908f8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40571f58;
  param_1[1] = &PTR_LAB_40571f44;
  param_1[2] = 1;
  return param_1;
}



/* 40590920 FUN_40590920 */

/* Boundary evidence: original MIPS .pdata 40590920..4059096b. Semantic name remains unreviewed. */

void FUN_40590920(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40571fb4;
  param_1[1] = &PTR_LAB_40571fa0;
  param_1[2] = &PTR_LAB_40571f8c;
  if ((HLOCAL)param_1[4] != (HLOCAL)0x0) {
    FUN_40580ef4((HLOCAL)param_1[4]);
  }
  return;
}



/* 4059096c FUN_4059096c */

/* Boundary evidence: original MIPS .pdata 4059096c..40590ad7. Semantic name remains unreviewed. */

int FUN_4059096c(int *param_1,HLOCAL *param_2,int *param_3)

{
  int iVar1;
  HLOCAL local_230 [2];
  undefined1 auStack_228 [520];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  local_230[0] = (HLOCAL)0x0;
  if (param_2 == (HLOCAL *)0x0) {
    param_2 = local_230;
  }
  else {
    *param_2 = (HLOCAL)0x0;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  iVar1 = SHGetSpecialFolderPath(0,auStack_228,0x10,1);
  if (iVar1 == 0) {
    iVar1 = -0x7fffbffb;
LAB_40590a60:
    if (-1 < iVar1) goto LAB_40590ab0;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1,0,0,auStack_228,0,param_2,0);
    if (-1 < iVar1) {
      if (param_3 != (int *)0x0) {
        iVar1 = (**(code **)(*param_1 + 0x14))(param_1,*param_2,0,&DAT_40572b68,param_3);
      }
      if (param_2 == local_230) {
        FUN_40580ef4(local_230[0]);
      }
      goto LAB_40590a60;
    }
  }
  if ((param_2 != (HLOCAL *)0x0) && (*param_2 != (HLOCAL)0x0)) {
    FUN_40580ef4(*param_2);
    *param_2 = (HLOCAL)0x0;
  }
  if ((param_3 != (int *)0x0) && ((int *)*param_3 != (int *)0x0)) {
    (**(code **)(*(int *)*param_3 + 8))();
    *param_3 = 0;
  }
LAB_40590ab0:
  FUN_405a7174(local_20);
  return iVar1;
}



/* 40590ad8 FUN_40590ad8 */

/* Boundary evidence: original MIPS .pdata 40590ad8..40590ca3. Semantic name remains unreviewed. */

undefined4 FUN_40590ad8(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = *param_2;
    if (((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
        ) || (((iVar2 == 0x214e6 && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    else {
      if (((iVar2 == 0x214ec) && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))) {
        iVar2 = param_1 + 4;
      }
      else {
        if ((((iVar2 != 0x10c) || (param_2[1] != 0)) || (param_2[2] != 0xc0)) ||
           (param_2[3] != 0x46000000)) {
          if (iVar2 != 0x214ea) {
            return 0x80004002;
          }
          if (param_2[1] != 0) {
            return 0x80004002;
          }
          if (param_2[2] != 0xc0) {
            return 0x80004002;
          }
          if (param_2[3] != 0x46000000) {
            return 0x80004002;
          }
        }
        iVar2 = param_1 + 8;
      }
      if (param_1 == 0) {
        iVar2 = 0;
      }
      *param_3 = iVar2;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40590ca4 FUN_40590ca4 */

/* Boundary evidence: original MIPS .pdata 40590ca4..40590eb3. Semantic name remains unreviewed. */

HRESULT FUN_40590ca4(int *param_1,ushort *param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 *param_5)

{
  ushort uVar1;
  undefined2 extraout_var;
  LPCOLESTR lpsz;
  HRESULT HVar2;
  char *pcVar3;
  int *local_40;
  int *local_3c;
  CLSID CStack_38;
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((param_2 == (ushort *)0x0) || (param_5 == (undefined4 *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return -0x7ff8ffa9;
  }
  *param_5 = 0;
  local_40 = (int *)0x0;
  uVar1 = FUN_405811d8((char *)param_2);
  if (CONCAT22(extraout_var,uVar1) == 0) {
    HVar2 = FUN_4059096c(param_1,(HLOCAL *)0x0,(int *)&local_40);
    if (-1 < HVar2) {
      HVar2 = (**(code **)(*local_40 + 0x14))(local_40,param_2,param_3,param_4,param_5);
    }
  }
  else {
    lpsz = (LPCOLESTR)FUN_40581264((int)param_2);
    HVar2 = CLSIDFromString(lpsz,&CStack_38);
    if (-1 < HVar2) {
      local_3c = (int *)0x0;
      HVar2 = DllGetClassObject(&CStack_38,(IID *)&DAT_40572bd8,&local_3c);
      if (HVar2 < 0) {
        if (HVar2 == -0x7ffbfeef) {
          HVar2 = CoGetClassObject(&CStack_38,1,(LPVOID)0x0,(IID *)&DAT_40572bd8,&local_3c);
        }
        if (HVar2 < 0) goto LAB_40590e50;
      }
      HVar2 = (**(code **)(*local_3c + 0xc))(local_3c,0,&DAT_40572b68,&local_40);
      (**(code **)(*local_3c + 8))();
      if (-1 < HVar2) {
        pcVar3 = FUN_40581214(param_2);
        if (pcVar3 == (char *)0x0) {
          HVar2 = (**(code **)*local_40)(local_40,param_4,param_5);
        }
        else {
          HVar2 = (*(code *)((undefined4 *)*local_40)[5])(local_40,pcVar3,param_3,param_4,param_5);
        }
      }
    }
  }
LAB_40590e50:
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))();
  }
  FUN_405a7174(local_28);
  return HVar2;
}



/* 40590eb4 FUN_40590eb4 */

/* Boundary evidence: original MIPS .pdata 40590eb4..40591057. Semantic name remains unreviewed. */

uint FUN_40590eb4(int *param_1,undefined4 param_2,char *param_3,char *param_4)

{
  ushort uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  PCNZWCH lpString2;
  PCNZWCH lpString1;
  int iVar2;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  uint uVar3;
  uint uVar4;
  int *local_28 [2];
  
  if ((param_3 == (char *)0x0) || (param_4 == (char *)0x0)) {
    uVar3 = 0x80070057;
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    uVar1 = FUN_405811d8(param_3);
    if ((CONCAT22(extraout_var,uVar1) == 0) ||
       (uVar1 = FUN_405811d8(param_4), CONCAT22(extraout_var_00,uVar1) == 0)) {
      uVar1 = FUN_405811d8(param_3);
      if ((CONCAT22(extraout_var_01,uVar1) == 0) ||
         (uVar1 = FUN_405811d8(param_4), CONCAT22(extraout_var_02,uVar1) != 0)) {
        uVar1 = FUN_405811d8(param_3);
        if ((CONCAT22(extraout_var_03,uVar1) == 0) &&
           (uVar1 = FUN_405811d8(param_4), CONCAT22(extraout_var_04,uVar1) != 0)) {
          uVar3 = 1;
        }
        else {
          local_28[0] = (int *)0x0;
          FUN_4059096c(param_1,(HLOCAL *)0x0,(int *)local_28);
          if (local_28[0] == (int *)0x0) {
            uVar4 = 1;
          }
          else {
            uVar3 = (**(code **)(*local_28[0] + 0x1c))(local_28[0],param_2,param_3,param_4);
            uVar4 = (int)uVar3 >> 0x1f & 1;
            uVar3 = uVar3 & 0xffff;
            (**(code **)(*local_28[0] + 8))();
          }
        }
      }
      else {
        uVar3 = 0xffffffff;
      }
    }
    else {
      lpString2 = (PCNZWCH)FUN_40580ed0((int)param_4);
      lpString1 = (PCNZWCH)FUN_40580ed0((int)param_3);
      iVar2 = CompareStringW(0x400,1,lpString1,-1,lpString2,-1);
      if (iVar2 == 0) {
        uVar4 = 1;
      }
      else {
        uVar3 = iVar2 - 2;
      }
    }
    uVar3 = uVar4 << 0x1f | uVar3 & 0xffff;
  }
  return uVar3;
}



/* 40591058 FUN_40591058 */

/* Boundary evidence: original MIPS .pdata 40591058..40591273. Semantic name remains unreviewed. */

int FUN_40591058(int *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  ushort *local_238;
  int *local_234;
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  iVar3 = -0x7fffbffe;
  if (param_4 == (undefined4 *)0x0) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    *param_4 = 0;
    if ((((*param_3 == 0x214e3) && (param_3[1] == 0)) && (param_3[2] == 0xc0)) &&
       (param_3[3] == 0x46000000)) {
      local_238 = (ushort *)0x0;
      iVar3 = FUN_4059096c(param_1,&local_238,(int *)0x0);
      if (-1 < iVar3) {
        (**(code **)(*param_1 + 4))(param_1);
        puVar1 = operator_new(0x88);
        if (puVar1 == (undefined4 *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = FUN_4059c59c(puVar1,param_1,local_238);
        }
        if (piVar2 == (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
          iVar3 = -0x7ff8fff2;
        }
        else {
          iVar4 = 0;
          iVar3 = SHGetSpecialFolderPath(0,aWStack_230,0x10,1);
          if (iVar3 != 0) {
            local_234 = (int *)0x0;
            iVar3 = (**(code **)*piVar2)(piVar2,&DAT_40572c28,&local_234);
            if (-1 < iVar3) {
              iVar4 = FUN_4058e9f8(DAT_405aa0cc,aWStack_230,(int)local_234);
              if (iVar4 != 0) {
                piVar2[0x13] = iVar4;
              }
              (**(code **)(*local_234 + 8))();
            }
          }
          iVar3 = (**(code **)*piVar2)(piVar2,param_3,param_4);
          if ((iVar3 < 0) && (iVar4 != 0)) {
            FUN_4058e7ac(DAT_405aa0cc,iVar4);
          }
          (**(code **)(*piVar2 + 8))(piVar2);
        }
        FUN_40580ef4(local_238);
      }
    }
  }
  FUN_405a7174(local_28);
  return iVar3;
}



/* 40591274 FUN_40591274 */

/* Boundary evidence: original MIPS .pdata 40591274..4059136f. Semantic name remains unreviewed. */

undefined4 FUN_40591274(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  ushort *local_20 [2];
  
  if (param_4 == (undefined4 *)0x0) {
    uVar4 = 0x80070057;
  }
  else {
    local_20[0] = (ushort *)0x0;
    uVar4 = 0;
    puVar1 = operator_new(0x34);
    if (puVar1 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_4059c4cc(puVar1,param_3);
    }
    if (piVar2 == (int *)0x0) {
      uVar4 = 0x8007000e;
    }
    else {
      FUN_4059096c(param_1,local_20,(int *)0x0);
      iVar3 = FUN_4059bdbc(piVar2,&DAT_405719c0,local_20[0]);
      if (iVar3 == 0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        uVar4 = 0x80004005;
      }
      else {
        *param_4 = piVar2;
      }
      if (local_20[0] != (ushort *)0x0) {
        FUN_40580ef4(local_20[0]);
      }
    }
  }
  return uVar4;
}



/* 40591370 FUN_40591370 */

/* Boundary evidence: original MIPS .pdata 40591370..405914eb. Semantic name remains unreviewed. */

int FUN_40591370(int *param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined2 extraout_var;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *local_30 [2];
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (uint *)0x0)) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    iVar4 = 0;
    puVar2 = (undefined4 *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,param_2 << 2);
    local_30[0] = (int *)0x0;
    puVar5 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      iVar3 = -0x7ff8fff2;
    }
    else {
      for (; param_2 != 0; param_2 = param_2 + -1) {
        uVar1 = FUN_405811d8((char *)*param_3);
        if (CONCAT22(extraout_var,uVar1) == 0) {
          iVar4 = iVar4 + 1;
          *puVar5 = *param_3;
          puVar5 = puVar5 + 1;
        }
        else {
          *param_4 = *param_4 & 0x98000014;
        }
        param_3 = param_3 + 1;
      }
      iVar3 = FUN_4059096c(param_1,(HLOCAL *)0x0,(int *)local_30);
      if (-1 < iVar3) {
        if (iVar4 != 0) {
          iVar3 = (**(code **)(*local_30[0] + 0x24))(local_30[0],iVar4,puVar2,param_4);
        }
        (**(code **)(*local_30[0] + 8))();
      }
      (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,puVar2);
    }
  }
  return iVar3;
}



/* 405914ec FUN_405914ec */

/* Boundary evidence: original MIPS .pdata 405914ec..405916b3. Semantic name remains unreviewed. */

int FUN_405914ec(int *param_1,ushort *param_2,uint param_3,undefined4 *param_4)

{
  ushort uVar1;
  uint uVar2;
  undefined2 extraout_var;
  STRSAFE_LPCWSTR pwVar3;
  size_t sVar4;
  wchar_t *_Dest;
  int iVar5;
  int *local_230 [2];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if (param_4 == (undefined4 *)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    iVar5 = -0x7ff8ffa9;
  }
  else {
    iVar5 = FUN_40580fe8((char *)param_2);
    if (iVar5 != 0) {
      param_2 = (ushort *)param_1[4];
    }
    uVar2 = FUN_40581410(param_2);
    if (uVar2 < 2) {
      uVar1 = FUN_405811d8((char *)param_2);
      if (CONCAT22(extraout_var,uVar1) == 0) {
        local_230[0] = (int *)0x0;
        iVar5 = FUN_4059096c(param_1,(HLOCAL *)0x0,(int *)local_230);
        if (-1 < iVar5) {
          iVar5 = (**(code **)(*local_230[0] + 0x2c))(local_230[0],param_2,param_3,param_4);
          (**(code **)(*local_230[0] + 8))();
        }
      }
      else {
        if ((param_3 & 0x8000) == 0) {
          pwVar3 = (STRSAFE_LPCWSTR)FUN_40580ed0((int)param_2);
          iVar5 = StringCchCopyW(awStack_228,0x104,pwVar3);
        }
        else {
          wcscpy(awStack_228,L"::");
          pwVar3 = (STRSAFE_LPCWSTR)FUN_40581264((int)param_2);
          iVar5 = StringCchCatW(awStack_228,0x104,pwVar3);
        }
        if (-1 < iVar5) {
          sVar4 = wcslen(awStack_228);
          _Dest = (wchar_t *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar4 + 1) * 2);
          param_4[1] = _Dest;
          if (_Dest == (wchar_t *)0x0) {
            iVar5 = -0x7ff8fff2;
          }
          else {
            wcscpy(_Dest,awStack_228);
            *param_4 = 0;
          }
        }
      }
      FUN_405a7174(local_20);
    }
    else {
      FUN_405a7174(local_20);
      iVar5 = -0x7fff0001;
    }
  }
  return iVar5;
}



/* 405916b4 FUN_405916b4 */

/* Boundary evidence: original MIPS .pdata 405916b4..40591a2b. Semantic name remains unreviewed. */

int FUN_405916b4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int *param_5
                ,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *local_28 [2];
  
  if ((param_4 == (undefined4 *)0x0) || (param_7 == (undefined4 *)0x0)) {
    return -0x7ff8ffa9;
  }
  *param_7 = 0;
  local_28[0] = (int *)0x0;
  iVar1 = FUN_4059096c(param_1,(HLOCAL *)0x0,(int *)local_28);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar4 = *param_5;
  if ((((iVar4 == 0x10e) && (param_5[1] == 0)) && (param_5[2] == 0xc0)) &&
     (param_5[3] == 0x46000000)) {
    iVar1 = (**(code **)(*local_28[0] + 0x28))
                      (local_28[0],param_2,param_3,param_4,param_5,param_6,param_7);
    goto LAB_405919e0;
  }
  if (((iVar4 == 0x122) && (param_5[1] == 0)) &&
     ((param_5[2] == 0xc0 && (param_5[3] == 0x46000000)))) {
    iVar1 = FUN_4058150c((ushort *)*param_4,&DAT_405719d0);
    if (iVar1 == 0) {
      iVar1 = FUN_4058150c((ushort *)*param_4,&DAT_405719b0);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*local_28[0] + 0x28))
                          (local_28[0],param_2,param_3,param_4,param_5,param_6,param_7);
        goto LAB_405919e0;
      }
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = FUN_4059e6c8(puVar2);
      }
      if (piVar3 == (int *)0x0) goto LAB_405919a4;
      iVar1 = FUN_4059e130((int)piVar3);
    }
    else {
      puVar2 = operator_new(0x214);
      if (puVar2 == (undefined4 *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = FUN_4059ed1c(puVar2);
      }
      if (piVar3 == (int *)0x0) {
LAB_405919a4:
        iVar1 = -0x7ff8fff2;
        goto LAB_405919e0;
      }
      iVar1 = FUN_4059e6ec((int)piVar3,L"\\");
    }
    if (iVar1 != 0) goto LAB_40591830;
    iVar1 = -0x7fffbffb;
  }
  else {
    if (((iVar4 != 0x214e4) || (param_5[1] != 0)) ||
       ((param_5[2] != 0xc0 || (param_5[3] != 0x46000000)))) goto LAB_405919e0;
    iVar1 = FUN_4058150c((ushort *)*param_4,&DAT_405719d0);
    if (iVar1 != 0) {
      iVar1 = -0x7fffbfff;
      goto LAB_405919e0;
    }
    iVar1 = FUN_4058150c((ushort *)*param_4,&DAT_405719b0);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_28[0] + 0x28))
                        (local_28[0],param_2,param_3,param_4,param_5,param_6,param_7);
      goto LAB_405919e0;
    }
    puVar2 = operator_new(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_4059e110(puVar2);
    }
    if (piVar3 == (int *)0x0) goto LAB_405919a4;
LAB_40591830:
    iVar1 = (**(code **)*piVar3)(piVar3,param_5,param_7);
  }
  (**(code **)(*piVar3 + 8))(piVar3);
LAB_405919e0:
  (**(code **)(*local_28[0] + 8))();
  return iVar1;
}



/* 40591a2c FUN_40591a2c */

/* Boundary evidence: original MIPS .pdata 40591a2c..40591dcf. Semantic name remains unreviewed. */

DWORD FUN_40591a2c(int *param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
                  undefined4 param_5,ushort **param_6,undefined4 param_7)

{
  wchar_t wVar1;
  int iVar2;
  DWORD DVar3;
  wchar_t *pwVar4;
  ushort *puVar5;
  BOOL BVar6;
  IID *pIVar7;
  ushort **ppuVar8;
  STRSAFE_PCNZWCH psz;
  LPCOLESTR lpsz;
  ushort *local_58;
  size_t local_54;
  undefined4 local_50;
  ushort *local_4c;
  int *local_48;
  undefined4 local_44;
  CLSID CStack_40;
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  local_44 = param_5;
  local_50 = param_7;
  if (param_6 == (ushort **)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80070057;
  }
  *param_6 = (ushort *)0x0;
  local_48 = (int *)0x0;
  local_58 = (ushort *)0x0;
  lpsz = (LPCOLESTR)0x0;
  local_4c = (ushort *)0x0;
  local_54 = 0;
  iVar2 = wcsncmp(param_4,L"::{",3);
  if (iVar2 == 0) {
    psz = param_4 + 2;
    DVar3 = StringCchLengthW(psz,0x104,&local_54);
    if ((int)DVar3 < 0) goto LAB_40591c98;
    pwVar4 = wcschr(psz,L'\\');
    if (pwVar4 != (wchar_t *)0x0) {
      local_54 = (int)pwVar4 - (int)psz >> 1;
    }
    if (local_54 == 0) {
      DVar3 = 0x8007006f;
    }
    if ((int)DVar3 < 0) goto LAB_40591c98;
    lpsz = (LPCOLESTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(local_54 + 1) * 2);
    if (lpsz == (LPCOLESTR)0x0) {
      DVar3 = 0x8007000e;
    }
    else {
      memcpy(lpsz,psz,local_54 << 1);
      lpsz[local_54] = L'\0';
      DVar3 = CLSIDFromString(lpsz,&CStack_40);
      if ((int)DVar3 < 0) goto LAB_40591c98;
      DVar3 = FUN_40587d78(&CStack_40,(int *)&local_58);
    }
    if ((int)DVar3 < 0) goto LAB_40591c98;
    if (pwVar4 == (wchar_t *)0x0) {
      puVar5 = FUN_405813a0(local_58,-1);
      *param_6 = puVar5;
      param_5 = local_44;
      param_7 = local_50;
      if (puVar5 == (ushort *)0x0) {
        DVar3 = 0x8007000e;
      }
    }
    else {
      param_4 = pwVar4 + 1;
      param_5 = local_44;
      param_7 = local_50;
    }
  }
  else if (*param_4 == L'\\') {
    wVar1 = param_4[1];
    ppuVar8 = param_6;
    if (wVar1 == L'\0') {
LAB_40591dac:
      pIVar7 = (IID *)&DAT_405719d0;
    }
    else {
      if (wVar1 != L'\\') {
        BVar6 = PathFileExistsW(param_4);
        if (BVar6 == 0) {
          DVar3 = GetLastError();
          if (0 < (int)DVar3) {
            DVar3 = DVar3 & 0xffff | 0x80070000;
          }
          goto LAB_40591be0;
        }
        ppuVar8 = &local_58;
        param_4 = param_4 + 1;
        goto LAB_40591dac;
      }
      ppuVar8 = &local_58;
      pIVar7 = (IID *)&DAT_405719e0;
    }
    DVar3 = FUN_40587d78(pIVar7,(int *)ppuVar8);
  }
  else {
    DVar3 = 0x80004005;
  }
LAB_40591be0:
  if (((-1 < (int)DVar3) && (*param_6 == (ushort *)0x0)) &&
     (DVar3 = (**(code **)(*param_1 + 0x14))(param_1,local_58,0,&DAT_40572b68,&local_48),
     -1 < (int)DVar3)) {
    DVar3 = (**(code **)(*local_48 + 0xc))
                      (local_48,param_2,param_3,param_4,param_5,&local_4c,param_7);
    if (-1 < (int)DVar3) {
      puVar5 = FUN_405812ec(local_58,local_4c);
      *param_6 = puVar5;
      if (puVar5 == (ushort *)0x0) {
        DVar3 = 0x8007000e;
      }
      FUN_40580ef4(local_4c);
    }
    (**(code **)(*local_48 + 8))();
  }
LAB_40591c98:
  if (local_58 != (ushort *)0x0) {
    FUN_40580ef4(local_58);
  }
  if (lpsz != (LPCOLESTR)0x0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpsz);
  }
  FUN_405a7174(local_30);
  return DVar3;
}



/* 40591dd0 FUN_40591dd0 */

/* Boundary evidence: original MIPS .pdata 40591dd0..40592073. Semantic name remains unreviewed. */

DWORD FUN_40591dd0(int *param_1,HWND param_2,ushort *param_3,STRSAFE_LPCWSTR param_4,
                  undefined4 param_5,undefined4 *param_6)

{
  ushort uVar1;
  undefined2 extraout_var;
  DWORD DVar2;
  LPWSTR pWVar3;
  int iVar4;
  int iVar5;
  HRESULT HVar6;
  wchar_t *pwVar7;
  LPCWSTR pWVar8;
  int *local_440;
  size_t local_43c;
  wchar_t awStack_438 [260];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((param_3 == (ushort *)0x0) || (param_4 == (STRSAFE_LPCWSTR)0x0)) {
    DVar2 = 0x80070057;
  }
  else {
    uVar1 = FUN_405811d8((char *)param_3);
    if (CONCAT22(extraout_var,uVar1) == 0) {
      local_440 = (int *)0x0;
      DVar2 = FUN_4059096c(param_1,(HLOCAL *)0x0,(int *)&local_440);
      if (-1 < (int)DVar2) {
        DVar2 = (**(code **)(*local_440 + 0x30))(local_440,param_2,param_3,param_4,param_5,param_6);
        (**(code **)(*local_440 + 8))();
      }
    }
    else {
      local_43c = 0;
      pwVar7 = (wchar_t *)0x0;
      pWVar8 = (LPCWSTR)0x0;
      DVar2 = StringCchCopyW(awStack_438,0x104,param_4);
      if (-1 < (int)DVar2) {
        PathRemoveBlanksW(awStack_438);
        DVar2 = StringCchLengthW(awStack_438,0x104,&local_43c);
        if (-1 < (int)DVar2) {
          if (local_43c == 0) {
            pwVar7 = (wchar_t *)0x3043;
            DVar2 = 0x80004005;
          }
          else {
            pWVar3 = PathFindFileNameW(awStack_438);
            iVar4 = PathIsValidFileName(pWVar3);
            if (iVar4 == 0) {
              iVar4 = LoadStringW(DAT_405aa0c0,0xc044,(LPWSTR)0x0,0);
              iVar5 = LoadStringW(DAT_405aa0c0,0xc05f,(LPWSTR)0x0,0);
              HVar6 = StringCchPrintfExW(awStack_230,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100
                                         ,L"%s%s",iVar5,iVar4);
              if (HVar6 < 0) {
                pwVar7 = (wchar_t *)LoadStringW(DAT_405aa0c0,0xc044,(LPWSTR)0x0,0);
              }
              else {
                pwVar7 = awStack_230;
                pWVar8 = (LPCWSTR)FUN_40580ed0((int)param_3);
              }
              DVar2 = 0x80004005;
            }
            if (-1 < (int)DVar2) {
              local_440 = FUN_405813a0(param_3,-1);
              if (local_440 == (int *)0x0) {
                DVar2 = 0x8007000e;
              }
              else {
                DVar2 = FUN_40587f50(awStack_438,(int *)&local_440);
                if (((int)DVar2 < 0) || (param_6 == (undefined4 *)0x0)) {
                  FUN_40580ef4(local_440);
                }
                else {
                  *param_6 = local_440;
                }
              }
              goto LAB_40592040;
            }
          }
          FUN_4058a544(param_2,(LPCWSTR)0x3025,pwVar7,pWVar8,0x10);
        }
      }
    }
  }
LAB_40592040:
  FUN_405a7174(local_28);
  return DVar2;
}



/* 40592074 FUN_40592074 */

/* Boundary evidence: original MIPS .pdata 40592074..405921eb. Semantic name remains unreviewed. */

int FUN_40592074(int param_1,char *param_2,int param_3,int param_4)

{
  ushort uVar1;
  undefined2 extraout_var;
  int iVar2;
  int *local_20;
  int *local_1c;
  
  if ((param_2 == (char *)0x0) || (param_4 == 0)) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar2 = 0;
    uVar1 = FUN_405811d8(param_2);
    if (CONCAT22(extraout_var,uVar1) == 0) {
      local_1c = (int *)0x0;
      iVar2 = FUN_4059096c((int *)(param_1 + -4),(HLOCAL *)0x0,(int *)&local_1c);
      if (-1 < iVar2) {
        local_20 = (int *)0x0;
        iVar2 = (**(code **)*local_1c)(local_1c,&DAT_40572c18,&local_20);
        if (-1 < iVar2) {
          iVar2 = (**(code **)(*local_20 + 0xc))(local_20,param_2,param_3,param_4);
          (**(code **)(*local_20 + 8))();
        }
        (**(code **)(*local_1c + 8))();
      }
    }
    else if (param_3 == 0) {
      iVar2 = (**(code **)(*(int *)(param_1 + -4) + 0x2c))
                        ((int *)(param_1 + -4),param_2,0x1001,param_4 + 8);
    }
    else if ((((param_3 != 1) && (param_3 != 2)) && (param_3 != 3)) && (param_3 != 4)) {
      iVar2 = -0x7fffbffb;
    }
  }
  return iVar2;
}



/* 40592234 FUN_40592234 */

/* Boundary evidence: original MIPS .pdata 40592234..40592277. Semantic name remains unreviewed. */

int FUN_40592234(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[3] + -1;
  param_1[3] = iVar1;
  if (iVar1 == 0) {
    FUN_40590920(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 405922a0 FUN_405922a0 */

/* Boundary evidence: original MIPS .pdata 405922a0..4059231f. Semantic name remains unreviewed. */

undefined4 * FUN_405922a0(undefined4 *param_1)

{
  int local_10 [2];
  
  param_1[1] = &PTR_LAB_40571f30;
  param_1[2] = &PTR_LAB_40571f8c;
  *param_1 = &PTR_FUN_40571fb4;
  param_1[1] = &PTR_LAB_40571fa0;
  param_1[3] = 0;
  param_1[4] = 0;
  local_10[0] = 0;
  FUN_40587d78((IID *)&DAT_405719c0,local_10);
  param_1[4] = local_10[0];
  param_1[3] = 1;
  return param_1;
}



/* 40592320 FUN_40592320 */

/* Boundary evidence: original MIPS .pdata 40592320..405924a7. Semantic name remains unreviewed. */

undefined4 FUN_40592320(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = *param_2;
    if (((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
        ) || (((iVar2 == 0x214e6 && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    else {
      if (((iVar2 == 0x214ec) && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))) {
        iVar2 = param_1 + 4;
      }
      else {
        if (iVar2 != 0x214ea) {
          return 0x80004002;
        }
        if (param_2[1] != 0) {
          return 0x80004002;
        }
        if (param_2[2] != 0xc0) {
          return 0x80004002;
        }
        if (param_2[3] != 0x46000000) {
          return 0x80004002;
        }
        iVar2 = param_1 + 8;
      }
      if (param_1 == 0) {
        iVar2 = 0;
      }
      *param_3 = iVar2;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 405924a8 FUN_405924a8 */

/* Boundary evidence: original MIPS .pdata 405924a8..4059282f. Semantic name remains unreviewed. */

uint FUN_405924a8(int *param_1,int param_2,LPCITEMIDLIST param_3,LPCITEMIDLIST param_4)

{
  int iVar1;
  wchar_t *lpString1;
  wchar_t *lpString2;
  uint uVar2;
  int iVar3;
  FILETIME local_558;
  FILETIME local_550;
  STRRET local_548;
  WCHAR aWStack_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  if ((param_3 == (LPCITEMIDLIST)0x0) || (param_4 == (LPCITEMIDLIST)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80070057;
  }
  iVar3 = 0;
  uVar2 = 0;
  if (param_2 == 0) {
    local_548.uType = 0;
    memset(&local_548.u,0,0x104);
    iVar1 = (**(code **)(*param_1 + 0x2c))(param_1,param_3,0x4001,&local_548);
    if (iVar1 < 0) goto LAB_405927d4;
    StrRetToBufW(&local_548,param_3,aWStack_238,0x104);
    iVar1 = (**(code **)(*param_1 + 0x2c))(param_1,param_4,0x4001,&local_548);
    if (iVar1 < 0) goto LAB_405927d4;
    StrRetToBufW(&local_548,param_4,aWStack_440,0x104);
    iVar1 = CompareStringW(0x400,1,aWStack_238,-1,aWStack_440,-1);
    if (iVar1 != 0) {
      uVar2 = iVar1 - 2;
      goto LAB_405927d4;
    }
  }
  else if (param_2 == 1) {
    FUN_40586a28(DAT_405aa0d4,0);
    local_558.dwLowDateTime = 0;
    local_558.dwHighDateTime = 0;
    local_550.dwLowDateTime = 0;
    local_550.dwHighDateTime = 0;
    iVar1 = FUN_40584d1c(DAT_405aa0d4,(int)param_3,(longlong *)&local_558);
    if ((iVar1 != 0) &&
       (iVar1 = FUN_40584d1c(DAT_405aa0d4,(int)param_4,(longlong *)&local_550), iVar1 != 0)) {
      if ((local_550.dwHighDateTime < local_558.dwHighDateTime) ||
         ((local_558.dwHighDateTime == local_550.dwHighDateTime &&
          (local_550.dwLowDateTime <= local_558.dwLowDateTime)))) {
        if ((local_558.dwHighDateTime < local_550.dwHighDateTime) ||
           ((local_558.dwHighDateTime == local_550.dwHighDateTime &&
            (local_558.dwLowDateTime <= local_550.dwLowDateTime)))) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
      else {
        uVar2 = 0xffffffff;
      }
      goto LAB_40592700;
    }
  }
  else if (param_2 == 2) {
    FUN_40586a28(DAT_405aa0d4,0);
    lpString1 = FUN_405849d0(DAT_405aa0d4,(int)param_3);
    if (lpString1 != (wchar_t *)0x0) {
      lpString2 = FUN_405849d0(DAT_405aa0d4,(int)param_4);
      if (lpString2 == (wchar_t *)0x0) {
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpString1);
      }
      else {
        iVar1 = CompareStringW(0x400,1,lpString1,-1,lpString2,-1);
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpString1);
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpString2);
        if (iVar1 == 0) goto LAB_4059257c;
        uVar2 = iVar1 - 2;
      }
LAB_40592700:
      FUN_40583798(DAT_405aa0d4);
      goto LAB_405927d4;
    }
  }
  else {
    if (param_2 != 3) goto LAB_405927d4;
    FUN_40586a28(DAT_405aa0d4,0);
    iVar1 = FUN_405848a4(DAT_405aa0d4,(int)param_3,&local_558.dwLowDateTime);
    if ((iVar1 != 0) &&
       (iVar1 = FUN_405848a4(DAT_405aa0d4,(int)param_4,&local_550.dwLowDateTime), iVar1 != 0)) {
      uVar2 = CompareFileTime(&local_558,&local_550);
      goto LAB_40592700;
    }
  }
LAB_4059257c:
  iVar3 = 1;
LAB_405927d4:
  FUN_405a7174(local_30);
  return iVar3 << 0x1f | uVar2 & 0xffff;
}



/* 40592830 FUN_40592830 */

/* Boundary evidence: original MIPS .pdata 40592830..40592a17. Semantic name remains unreviewed. */

HRESULT FUN_40592830(int *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  HRESULT HVar4;
  int iVar5;
  ushort *local_28;
  int *local_24;
  
  HVar4 = 0;
  if (param_4 == (undefined4 *)0x0) {
    HVar4 = -0x7ff8ffa9;
  }
  else {
    *param_4 = 0;
    if ((((*param_3 == 0x214e3) && (param_3[1] == 0)) && (param_3[2] == 0xc0)) &&
       (param_3[3] == 0x46000000)) {
      (**(code **)(*param_1 + 4))(param_1);
      local_28 = (ushort *)0x0;
      HVar4 = FUN_40587d78((IID *)&DAT_405719b0,(int *)&local_28);
      if (-1 < HVar4) {
        puVar1 = operator_new(0x78);
        if (puVar1 == (undefined4 *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = FUN_4059ed3c(puVar1,param_1,local_28);
        }
        FUN_40580ef4(local_28);
        if (piVar2 == (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
          HVar4 = -0x7ff8fff2;
        }
        else {
          local_24 = (int *)0x0;
          iVar5 = 0;
          iVar3 = (**(code **)*piVar2)(piVar2,&DAT_40572c28,&local_24);
          if (-1 < iVar3) {
            iVar5 = FUN_4058e9f8(DAT_405aa0cc,&DAT_405a9aa4,(int)local_24);
            if (iVar5 != 0) {
              piVar2[0x13] = iVar5;
            }
            (**(code **)(*local_24 + 8))();
          }
          HVar4 = (**(code **)*piVar2)(piVar2,param_3,param_4);
          if ((HVar4 < 0) && (iVar5 != 0)) {
            FUN_4058e7ac(DAT_405aa0cc,iVar5);
          }
          (**(code **)(*piVar2 + 8))(piVar2);
        }
      }
    }
  }
  return HVar4;
}



/* 40592a18 FUN_40592a18 */

/* Boundary evidence: original MIPS .pdata 40592a18..40592acf. Semantic name remains unreviewed. */

undefined4
FUN_40592a18(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_4 == (undefined4 *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    *param_4 = 0;
    uVar2 = 0;
    FUN_40586a28(DAT_405aa0d4,0);
    FUN_40583798(DAT_405aa0d4);
    puVar1 = operator_new(0x244);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_405869bc(puVar1,param_3);
    }
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0x8007000e;
    }
    else {
      FUN_40584ec8((int)puVar1);
      *param_4 = puVar1;
    }
  }
  return uVar2;
}



/* 40592ad0 FUN_40592ad0 */

/* Boundary evidence: original MIPS .pdata 40592ad0..40592c9b. Semantic name remains unreviewed. */

DWORD FUN_40592ad0(int *param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  DWORD DVar1;
  uint uVar2;
  DWORD DVar3;
  uint uVar4;
  uint uVar5;
  STRRET local_340;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (uint *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80070057;
  }
  local_340.uType = 0;
  DVar3 = 0;
  memset(&local_340.u,0,0x104);
  uVar5 = 0xffffffff;
  uVar4 = 0;
  if (param_2 == 0) {
LAB_40592c20:
    if (param_2 != 0) {
      *param_4 = (uVar5 | 0x40020) & *param_4;
      goto LAB_40592c48;
    }
  }
  else {
    do {
      DVar3 = (**(code **)(*param_1 + 0x2c))(param_1,*param_3,0x8000,&local_340);
      if ((int)DVar3 < 0) goto LAB_40592c44;
      StrRetToBufW(&local_340,(LPCITEMIDLIST)*param_3,aWStack_238,0x104);
      DVar1 = GetFileAttributesW(aWStack_238);
      if (DVar1 == 0xffffffff) {
        DVar3 = GetLastError();
        if (0 < (int)DVar3) {
          DVar3 = DVar3 & 0xffff | 0x80070000;
        }
        break;
      }
      uVar2 = 0;
      if (((*param_4 & 0x20000000) != 0) && ((DVar1 & 0x10) != 0)) {
        uVar2 = 0x20000000;
      }
      uVar4 = uVar4 + 1;
      param_3 = param_3 + 1;
      uVar5 = uVar2 & uVar5;
    } while (uVar4 < param_2);
    if (-1 < (int)DVar3) goto LAB_40592c20;
  }
LAB_40592c44:
  *param_4 = 0;
LAB_40592c48:
  FUN_405a7174(local_30);
  return DVar3;
}



/* 40592c9c FUN_40592c9c */

/* Boundary evidence: original MIPS .pdata 40592c9c..40592ed3. Semantic name remains unreviewed. */

HRESULT FUN_40592c9c(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar1;
  size_t sVar2;
  size_t sVar3;
  STRSAFE_LPWSTR pwVar4;
  wchar_t *_Str;
  undefined4 *puVar5;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if ((param_2 == 0) || (param_4 == (undefined4 *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    HVar1 = -0x7ff8ffa9;
  }
  else {
    if ((param_3 & 1) == 0) {
      pszSrc = (STRSAFE_LPCWSTR)FUN_40580ed0(param_2);
      HVar1 = StringCchCopyW(awStack_228,0x104,pszSrc);
      if (HVar1 < 0) {
        HVar1 = -0x7fffbffb;
      }
      else {
        sVar2 = wcslen(&DAT_405a9aa4);
        sVar3 = wcslen(awStack_228);
        pwVar4 = (STRSAFE_LPWSTR)
                 (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar3 + sVar2 + 2) * 2);
        puVar5 = param_4 + 1;
        *puVar5 = pwVar4;
        if (pwVar4 == (STRSAFE_LPWSTR)0x0) {
          HVar1 = -0x7ff8fff2;
        }
        else {
          sVar2 = sVar3 + sVar2 + 2;
          HVar1 = StringCchCopyW(pwVar4,sVar2,&DAT_405a9aa4);
          if (((-1 < HVar1) &&
              (HVar1 = StringCchCatW((STRSAFE_LPWSTR)*puVar5,sVar2,L"\\"), -1 < HVar1)) &&
             (HVar1 = StringCchCatW((STRSAFE_LPWSTR)*puVar5,sVar2,awStack_228), -1 < HVar1)) {
            *param_4 = 0;
          }
        }
      }
    }
    else {
      FUN_40586a28(DAT_405aa0d4,0);
      _Str = FUN_40584b7c(DAT_405aa0d4,param_2);
      if (_Str == (wchar_t *)0x0) {
        HVar1 = -0x7fffbffb;
      }
      else {
        sVar2 = wcslen(_Str);
        pwVar4 = (STRSAFE_LPWSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar2 + 1) * 2);
        param_4[1] = pwVar4;
        if (pwVar4 == (STRSAFE_LPWSTR)0x0) {
          HVar1 = -0x7ff8fff2;
        }
        else {
          HVar1 = StringCchCopyW(pwVar4,sVar2 + 1,_Str);
          *param_4 = 0;
        }
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,_Str);
      }
      FUN_40583798(DAT_405aa0d4);
    }
    FUN_405a7174(local_20);
  }
  return HVar1;
}



/* 40592ed4 FUN_40592ed4 */

/* Boundary evidence: original MIPS .pdata 40592ed4..4059301f. Semantic name remains unreviewed. */

int FUN_40592ed4(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int in_a3;
  int iVar3;
  int *in_stack_00000010;
  undefined4 *in_stack_00000018;
  
  if ((in_a3 == 0) || (in_stack_00000018 == (undefined4 *)0x0)) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    *in_stack_00000018 = 0;
    iVar3 = -0x7fffbfff;
    if ((((*in_stack_00000010 == 0x122) && (in_stack_00000010[1] == 0)) &&
        (in_stack_00000010[2] == 0xc0)) && (in_stack_00000010[3] == 0x46000000)) {
      puVar1 = operator_new(0x10);
      if (puVar1 == (undefined4 *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = FUN_4059e6c8(puVar1);
      }
      if (piVar2 == (int *)0x0) {
        iVar3 = -0x7ff8fff2;
      }
      else {
        iVar3 = FUN_4059e130((int)piVar2);
        if (iVar3 == 0) {
          iVar3 = -0x7fffbffb;
        }
        else {
          iVar3 = (**(code **)*piVar2)(piVar2,in_stack_00000010,in_stack_00000018);
          (**(code **)(*piVar2 + 8))(piVar2);
        }
        if (iVar3 < 0) {
          (**(code **)(*piVar2 + 8))(piVar2);
          *in_stack_00000018 = 0;
        }
      }
    }
  }
  return iVar3;
}



/* 40593020 DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
                    /* 0x23020  15  DllCanUnloadNow */
  return 1;
}



/* 40593028 FUN_40593028 */

/* Boundary evidence: original MIPS .pdata 40593028..405932bf. Semantic name remains unreviewed. */

HRESULT FUN_40593028(undefined4 param_1,int param_2,int param_3,int *param_4)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  LPWSTR pWVar4;
  size_t sVar5;
  STRSAFE_LPWSTR pszDest;
  wchar_t *pwVar6;
  HRESULT HVar7;
  uint uVar8;
  FILETIME local_28;
  
  HVar7 = 0;
  if ((param_2 == 0) || (param_4 == (int *)0x0)) {
    return -0x7ff8ffa9;
  }
  FUN_40586a28(DAT_405aa0d4,0);
  if (param_3 == 0) {
    pwVar6 = FUN_40584b7c(DAT_405aa0d4,param_2);
LAB_405931f8:
    if (pwVar6 == (wchar_t *)0x0) goto LAB_40593280;
    sVar5 = wcslen(pwVar6);
    pszDest = (STRSAFE_LPWSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(sVar5 + 1) * 2);
    param_4[3] = (int)pszDest;
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      HVar7 = -0x7ff8fff2;
    }
    else {
      HVar7 = StringCchCopyW(pszDest,sVar5 + 1,pwVar6);
      param_4[2] = 0;
      *param_4 = 0;
    }
  }
  else {
    if (param_3 == 1) {
      local_28.dwLowDateTime = 0;
      local_28.dwHighDateTime = 0;
      iVar3 = FUN_40584d1c(DAT_405aa0d4,param_2,(longlong *)&local_28);
      if (iVar3 != 0) {
        pwVar6 = (wchar_t *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,0x208);
        param_4[3] = (int)pwVar6;
        if (pwVar6 == (wchar_t *)0x0) {
          HVar7 = -0x7ff8fff2;
        }
        else {
          *param_4 = 1;
          _ultow(local_28.dwLowDateTime,pwVar6,10);
        }
        goto LAB_40593280;
      }
LAB_405930a0:
      HVar7 = -0x7fffbffb;
      goto LAB_40593280;
    }
    if (param_3 == 2) {
      pwVar6 = FUN_405849d0(DAT_405aa0d4,param_2);
      goto LAB_405931f8;
    }
    uVar8 = 3;
    if (param_3 != 3) goto LAB_405930a0;
    local_28.dwLowDateTime = 0;
    memset(&local_28.dwHighDateTime,0,4);
    iVar3 = FUN_405848a4(DAT_405aa0d4,param_2,&local_28.dwLowDateTime);
    if (iVar3 == 0) goto LAB_40593280;
    if (*param_4 == 0x10) {
      uVar8 = 0x103;
    }
    else if (*param_4 == 0x20) {
      uVar8 = 0x203;
    }
    pWVar4 = (LPWSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,0x80);
    param_4[3] = (int)pWVar4;
    if (pWVar4 == (LPWSTR)0x0) {
      HVar7 = -0x7ff8fff2;
    }
    else {
      uVar1 = (int)param_4 + 0xbU & 3;
      puVar2 = (uint *)(((int)param_4 + 0xbU) - uVar1);
      *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
      uVar1 = (int)param_4 + 3U & 3;
      puVar2 = (uint *)(((int)param_4 + 3U) - uVar1);
      *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
      uVar1 = (uint)(param_4 + 2) & 3;
      puVar2 = (uint *)((int)(param_4 + 2) - uVar1);
      *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
      uVar1 = (uint)param_4 & 3;
      *(uint *)((int)param_4 - uVar1) =
           *(uint *)((int)param_4 - uVar1) & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
      FUN_4058989c(&local_28,uVar8,pWVar4,0x40);
    }
    pwVar6 = (wchar_t *)0x0;
  }
  (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,pwVar6);
LAB_40593280:
  FUN_40583798(DAT_405aa0d4);
  return HVar7;
}



/* 405932e8 FUN_405932e8 */

/* Boundary evidence: original MIPS .pdata 405932e8..40593337. Semantic name remains unreviewed. */

int FUN_405932e8(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[3] + -1;
  param_1[3] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_40572010;
    param_1[1] = &PTR_LAB_40571ffc;
    param_1[2] = &PTR_LAB_40571fe8;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40593360 FUN_40593360 */

undefined4 * FUN_40593360(undefined4 *param_1)

{
  param_1[1] = &PTR_LAB_40571f30;
  *param_1 = &PTR_FUN_40572010;
  param_1[1] = &PTR_LAB_40571ffc;
  param_1[2] = &PTR_LAB_40571fe8;
  param_1[3] = 1;
  return param_1;
}



/* 405933a0 FUN_405933a0 */

/* Boundary evidence: original MIPS .pdata 405933a0..40593407. Semantic name remains unreviewed. */

void FUN_405933a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_4057206c;
  param_1[1] = &PTR_LAB_40572058;
  param_1[2] = &PTR_LAB_40572044;
  if ((HLOCAL)param_1[4] != (HLOCAL)0x0) {
    FUN_40580ef4((HLOCAL)param_1[4]);
  }
  if ((HLOCAL)param_1[5] != (HLOCAL)0x0) {
    FUN_40580ef4((HLOCAL)param_1[5]);
  }
  return;
}



/* 40593408 FUN_40593408 */

/* Boundary evidence: original MIPS .pdata 40593408..4059358f. Semantic name remains unreviewed. */

void * FUN_40593408(int param_1,int *param_2)

{
  HLOCAL pvVar1;
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar2;
  void *_Dst;
  STRSAFE_LPWSTR pwVar3;
  int iVar4;
  ushort *puVar5;
  size_t sVar6;
  wchar_t local_230;
  wchar_t local_22e [259];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  puVar5 = *(ushort **)(param_1 + 0x10);
  pwVar3 = &local_230;
  if (puVar5 != (ushort *)0x0) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      local_230 = L'\\';
      pwVar3 = local_22e;
    }
    do {
      pvVar1 = FUN_405813a0(puVar5,1);
      if (pvVar1 == (HLOCAL)0x0) goto LAB_40593544;
      *pwVar3 = L'\\';
      pwVar3 = pwVar3 + 1;
      sVar6 = 0x104 - ((int)pwVar3 - (int)&local_230 >> 1);
      if ((int)sVar6 < 1) {
LAB_4059353c:
        FUN_40580ef4(pvVar1);
LAB_40593544:
        FUN_405a7174(local_28);
        return (void *)0x0;
      }
      pszSrc = (STRSAFE_LPCWSTR)FUN_40581264((int)pvVar1);
      HVar2 = StringCchCopyW(pwVar3,sVar6,pszSrc);
      if (HVar2 < 0) goto LAB_4059353c;
      sVar6 = wcslen(pwVar3);
      pwVar3 = pwVar3 + sVar6;
      FUN_40580ef4(pvVar1);
      puVar5 = (ushort *)FUN_40581214(puVar5);
    } while (puVar5 != (ushort *)0x0);
  }
  *pwVar3 = L'\0';
  iVar4 = (int)pwVar3 - (int)&local_230 >> 1;
  sVar6 = (iVar4 + 1) * 2;
  _Dst = (void *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,sVar6);
  if (_Dst == (void *)0x0) {
    if (param_2 != (int *)0x0) {
      *param_2 = 0;
    }
  }
  else {
    memcpy(_Dst,&local_230,sVar6);
    if (param_2 != (int *)0x0) {
      *param_2 = iVar4;
    }
  }
  FUN_405a7174(local_28);
  return _Dst;
}



/* 40593590 FUN_40593590 */

/* Boundary evidence: original MIPS .pdata 40593590..40593607. Semantic name remains unreviewed. */

undefined4 FUN_40593590(int param_1,ushort *param_2)

{
  HLOCAL pvVar1;
  undefined4 uVar2;
  
  if (param_2 == (ushort *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    uVar2 = 0;
    if (*(HLOCAL *)(param_1 + 0x10) != (HLOCAL)0x0) {
      FUN_40580ef4(*(HLOCAL *)(param_1 + 0x10));
    }
    pvVar1 = FUN_405813a0(param_2,-1);
    *(HLOCAL *)(param_1 + 0x10) = pvVar1;
    if (pvVar1 == (HLOCAL)0x0) {
      uVar2 = 0x8007000e;
    }
  }
  return uVar2;
}



/* 40593608 FUN_40593608 */

/* Boundary evidence: original MIPS .pdata 40593608..4059368b. Semantic name remains unreviewed. */

HRESULT FUN_40593608(int param_1,int param_2)

{
  HRESULT HVar1;
  int csidl;
  LPITEMIDLIST *ppidl;
  
  HVar1 = 0;
  if (*(int *)(param_1 + 0x1c) != param_2) {
    ppidl = (LPITEMIDLIST *)(param_1 + 0x14);
    if (*ppidl != (LPITEMIDLIST)0x0) {
      FUN_40580ef4(*ppidl);
      *ppidl = (LPITEMIDLIST)0x0;
    }
    csidl = 0x12;
    if (param_2 == 0) {
      csidl = 0x11;
    }
    HVar1 = SHGetSpecialFolderLocation((HWND)0x0,csidl,ppidl);
    if (-1 < HVar1) {
      *(int *)(param_1 + 0x1c) = param_2;
    }
  }
  return HVar1;
}



/* 4059368c FUN_4059368c */

/* Boundary evidence: original MIPS .pdata 4059368c..40593857. Semantic name remains unreviewed. */

undefined4 FUN_4059368c(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = *param_2;
    if (((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
        ) || (((iVar2 == 0x214e6 && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    else {
      if (((iVar2 == 0x214ec) && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))) {
        iVar2 = param_1 + 4;
      }
      else {
        if ((((iVar2 != 0x10c) || (param_2[1] != 0)) || (param_2[2] != 0xc0)) ||
           (param_2[3] != 0x46000000)) {
          if (iVar2 != 0x214ea) {
            return 0x80004002;
          }
          if (param_2[1] != 0) {
            return 0x80004002;
          }
          if (param_2[2] != 0xc0) {
            return 0x80004002;
          }
          if (param_2[3] != 0x46000000) {
            return 0x80004002;
          }
        }
        iVar2 = param_1 + 8;
      }
      if (param_1 == 0) {
        iVar2 = 0;
      }
      *param_3 = iVar2;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40593868 FUN_40593868 */

/* Boundary evidence: original MIPS .pdata 40593868..40593b63. Semantic name remains unreviewed. */

uint FUN_40593868(undefined4 param_1,int param_2,char *param_3,char *param_4)

{
  ushort uVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  PCNZWCH pWVar3;
  PCNZWCH pWVar4;
  uint uVar5;
  int iVar6;
  FILETIME local_38;
  FILETIME local_30;
  
  if ((param_3 == (char *)0x0) || (param_4 == (char *)0x0)) {
    return 0x80070057;
  }
  iVar6 = 0;
  uVar5 = 0;
  iVar2 = FUN_40581188(param_3);
  if ((iVar2 != 0) && (iVar2 = FUN_40581188(param_4), iVar2 == 0)) {
LAB_405938d4:
    uVar5 = 0xffffffff;
    goto LAB_40593b1c;
  }
  iVar2 = FUN_40581188(param_3);
  if ((iVar2 == 0) && (iVar2 = FUN_40581188(param_4), iVar2 != 0)) {
    uVar5 = 1;
    goto LAB_40593b1c;
  }
  iVar2 = FUN_40581188(param_3);
  if (((iVar2 != 0) && (iVar2 = FUN_40581188(param_4), iVar2 != 0)) &&
     ((param_2 == 1 || (param_2 == 2)))) {
    uVar5 = 0;
    goto LAB_40593b1c;
  }
  if (param_2 == 0) {
    pWVar3 = (PCNZWCH)FUN_40580ed0((int)param_4);
    pWVar4 = (PCNZWCH)FUN_40580ed0((int)param_3);
    iVar2 = CompareStringW(0x400,1,pWVar4,-1,pWVar3,-1);
LAB_40593b10:
    if (iVar2 != 0) {
      uVar5 = iVar2 - 2;
      goto LAB_40593b1c;
    }
  }
  else if (param_2 == 1) {
    iVar2 = FUN_40580f64((int)param_3,&local_38.dwLowDateTime);
    if ((iVar2 != 0) && (iVar2 = FUN_40580f64((int)param_4,&local_30.dwLowDateTime), iVar2 != 0)) {
      if ((local_38.dwHighDateTime <= local_30.dwHighDateTime) &&
         ((local_38.dwHighDateTime != local_30.dwHighDateTime ||
          (local_38.dwLowDateTime < local_30.dwLowDateTime)))) goto LAB_405938d4;
      if ((local_30.dwHighDateTime <= local_38.dwHighDateTime) &&
         ((local_38.dwHighDateTime != local_30.dwHighDateTime ||
          (local_30.dwLowDateTime < local_38.dwLowDateTime)))) {
        uVar5 = 1;
        goto LAB_40593b1c;
      }
      uVar5 = 0;
LAB_40593a90:
      if (uVar5 != 0) goto LAB_40593b1c;
LAB_40593a98:
      pWVar3 = (PCNZWCH)FUN_40580ed0((int)param_4);
      pWVar4 = (PCNZWCH)FUN_40580ed0((int)param_3);
      iVar2 = CompareStringW(0x400,1,pWVar4,-1,pWVar3,-1);
      goto LAB_40593b10;
    }
  }
  else if (param_2 == 2) {
    uVar1 = FUN_405814d0(param_3);
    if ((CONCAT22(extraout_var,uVar1) != 0) &&
       (uVar1 = FUN_405814d0(param_4), CONCAT22(extraout_var_00,uVar1) != 0)) {
      pWVar3 = (PCNZWCH)FUN_40580fb4((int)param_4);
      pWVar4 = (PCNZWCH)FUN_40580fb4((int)param_3);
      iVar2 = CompareStringW(0x400,1,pWVar4,-1,pWVar3,-1);
      if (iVar2 != 0) {
        uVar5 = iVar2 - 2;
        goto LAB_40593a90;
      }
    }
  }
  else {
    if (param_2 != 3) goto LAB_40593a98;
    iVar2 = FUN_40580f18((int)param_3,&local_38.dwLowDateTime);
    if ((iVar2 != 0) && (iVar2 = FUN_40580f18((int)param_4,&local_30.dwLowDateTime), iVar2 != 0)) {
      uVar5 = CompareFileTime(&local_38,&local_30);
      goto LAB_40593a90;
    }
  }
  iVar6 = 1;
LAB_40593b1c:
  return iVar6 << 0x1f | uVar5 & 0xffff;
}



/* 40593b64 FUN_40593b64 */

/* Boundary evidence: original MIPS .pdata 40593b64..40593e6f. Semantic name remains unreviewed. */

int FUN_40593b64(int *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  LPCWSTR lpString2;
  ushort *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *local_250 [2];
  undefined2 local_248;
  undefined1 auStack_246 [10];
  WCHAR aWStack_23c [266];
  
  if (param_4 == (undefined4 *)0x0) {
    return -0x7ff8ffa9;
  }
  *param_4 = 0;
  if (*param_3 != 0x214e3) {
    return -0x7fffbfff;
  }
  if (param_3[1] != 0) {
    return -0x7fffbfff;
  }
  if (param_3[2] != 0xc0) {
    return -0x7fffbfff;
  }
  if (param_3[3] != 0x46000000) {
    return -0x7fffbfff;
  }
  lpString2 = FUN_40593408((int)param_1,(int *)0x0);
  if (lpString2 == (LPCWSTR)0x0) {
    return -0x7ff8fff2;
  }
  if ((ushort *)param_1[4] == (ushort *)0x0) {
    puVar1 = FUN_405813a0((ushort *)param_1[5],-1);
  }
  else {
    puVar1 = FUN_405812ec((ushort *)param_1[5],(ushort *)param_1[4]);
  }
  if (puVar1 == (ushort *)0x0) {
    iVar2 = -0x7ff8fff2;
    goto LAB_40593e24;
  }
  local_248 = 0;
  memset(auStack_246,0,0x21e);
  (**(code **)(*param_1 + 4))(param_1);
  if (((param_1[7] == 0) || (iVar2 = FUN_40581410((ushort *)param_1[4]), iVar2 != 1)) &&
     ((iVar2 = CeOidGetInfo(0xe0000001,&local_248), iVar2 == 0 ||
      (iVar2 = CompareStringW(0x400,1,aWStack_23c,-1,lpString2,-1), iVar2 != 2)))) {
    puVar3 = operator_new(0x78);
    if (puVar3 == (undefined4 *)0x0) {
LAB_40593d30:
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = FUN_4059bc34(puVar3,param_1,puVar1);
    }
  }
  else {
    puVar3 = operator_new(0x78);
    if (puVar3 == (undefined4 *)0x0) goto LAB_40593d30;
    piVar4 = FUN_4059fbd0(puVar3,param_1,puVar1);
  }
  if (piVar4 == (int *)0x0) {
    iVar2 = -0x7ff8fff2;
  }
  else {
    iVar5 = 0;
    local_250[0] = (int *)0x0;
    iVar2 = (**(code **)*piVar4)(piVar4,&DAT_40572c28,local_250);
    if (-1 < iVar2) {
      iVar5 = FUN_4058e9f8(DAT_405aa0cc,lpString2,(int)local_250[0]);
      if (iVar5 != 0) {
        piVar4[0x13] = iVar5;
      }
      (**(code **)(*local_250[0] + 8))();
    }
    iVar2 = (**(code **)*piVar4)(piVar4,param_3,param_4);
    if ((iVar2 < 0) && (iVar5 != 0)) {
      FUN_4058e7ac(DAT_405aa0cc,iVar5);
    }
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  if (iVar2 < 0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_40580ef4(puVar1);
LAB_40593e24:
  (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpString2);
  return iVar2;
}



/* 40593e70 FUN_40593e70 */

/* Boundary evidence: original MIPS .pdata 40593e70..40593f7f. Semantic name remains unreviewed. */

undefined4 FUN_40593e70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  ushort *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_4 == (undefined4 *)0x0) {
    uVar5 = 0x80070057;
  }
  else {
    *param_4 = 0;
    uVar5 = 0;
    if (*(ushort **)(param_1 + 0x10) == (ushort *)0x0) {
      puVar1 = FUN_405813a0(*(ushort **)(param_1 + 0x14),-1);
    }
    else {
      puVar1 = FUN_405812ec(*(ushort **)(param_1 + 0x14),*(ushort **)(param_1 + 0x10));
    }
    if (puVar1 == (ushort *)0x0) {
      uVar5 = 0x8007000e;
    }
    else {
      puVar2 = operator_new(0x250);
      if (puVar2 == (undefined4 *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = FUN_405a0988(puVar2,param_3);
      }
      if (piVar3 == (int *)0x0) {
        uVar5 = 0x8007000e;
      }
      else {
        iVar4 = FUN_405a01cc((int)piVar3,puVar1);
        if (iVar4 == 0) {
          (**(code **)(*piVar3 + 8))(piVar3);
          uVar5 = 0x80004005;
        }
        else {
          *param_4 = piVar3;
        }
      }
      FUN_40580ef4(puVar1);
    }
  }
  return uVar5;
}



/* 40593f80 FUN_40593f80 */

/* Boundary evidence: original MIPS .pdata 40593f80..40594343. Semantic name remains unreviewed. */

DWORD FUN_40593f80(int *param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  DWORD DVar1;
  int iVar2;
  HRESULT HVar3;
  HANDLE hFindFile;
  BOOL BVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  DWORD DVar8;
  wchar_t *pszSrc;
  uint uVar9;
  STRSAFE_LPWSTR local_580;
  int *local_57c;
  wchar_t *local_578;
  STRRET local_570;
  _WIN32_FIND_DATAW local_468;
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  local_57c = param_1;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (uint *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80070057;
  }
  local_570.uType = 0;
  DVar8 = 0;
  memset(&local_570.u,0,0x104);
  uVar5 = 0xffffffff;
  uVar9 = 0;
  if (param_2 == 0) {
LAB_405942d4:
    if (param_2 != 0) {
      *param_4 = *param_4 & uVar5;
      goto LAB_405942f0;
    }
  }
  else {
    pszSrc = L"\\*.*";
    local_578 = L"\\*.*";
    do {
      DVar8 = (**(code **)(*param_1 + 0x2c))(param_1,*param_3,0x8000,&local_570);
      if ((int)DVar8 < 0) goto LAB_405942ec;
      StrRetToBufW(&local_570,(LPCITEMIDLIST)*param_3,local_468.cFileName + 0x102,0x104);
      DVar1 = GetFileAttributesW(local_468.cFileName + 0x102);
      if (DVar1 == 0xffffffff) {
        DVar8 = GetLastError();
        if (0 < (int)DVar8) {
          DVar8 = DVar8 & 0xffff | 0x80070000;
        }
        break;
      }
      uVar6 = *param_4;
      uVar7 = (uint)((uVar6 & 1) != 0);
      if (((uVar6 & 0x20) != 0) && ((DVar1 & 0x40) == 0)) {
        uVar7 = uVar7 | 0x20;
      }
      if ((uVar6 & 4) != 0) {
        uVar7 = uVar7 | 4;
      }
      if (((uVar6 & 2) != 0) && ((DVar1 & 0x40) == 0)) {
        uVar7 = uVar7 | 2;
      }
      if (((uVar6 & 0x10) != 0) && ((DVar1 & 0x40) == 0)) {
        uVar7 = uVar7 | 0x10;
      }
      if (((uVar6 & 0x10000) != 0) && (iVar2 = PathIsLink(local_468.cFileName + 0x102), iVar2 != 0))
      {
        uVar7 = uVar7 | 0x10000;
      }
      if (((*param_4 & 0x40000) != 0) && ((DVar1 & 0x41) != 0)) {
        uVar7 = uVar7 | 0x40000;
      }
      if ((((*param_4 & 0x80000000) != 0) && (local_580 = (STRSAFE_LPWSTR)0x0, (DVar1 & 0x10) != 0))
         && (HVar3 = StringCchCatExW(local_468.cFileName + 0x102,0x104,pszSrc,&local_580,
                                     (size_t *)0x0,0), -1 < HVar3)) {
        local_468.dwFileAttributes = 0;
        memset(&local_468.ftCreationTime,0,0x22c);
        hFindFile = FindFirstFileW(local_468.cFileName + 0x102,&local_468);
        if (hFindFile != (HANDLE)0xffffffff) {
          do {
            if ((local_468.dwFileAttributes & 0x10) != 0) {
              uVar7 = uVar7 | 0x80000000;
              break;
            }
            BVar4 = FindNextFileW(hFindFile,&local_468);
          } while (BVar4 != 0);
          FindClose(hFindFile);
        }
        local_580[-4] = L'\0';
        pszSrc = local_578;
      }
      uVar6 = *param_4;
      if ((uVar6 & 0x40000000) != 0) {
        uVar7 = uVar7 | 0x40000000;
      }
      if ((uVar6 & 0x10000000) != 0) {
        uVar7 = uVar7 | 0x10000000;
      }
      if (((uVar6 & 0x20000000) != 0) && ((DVar1 & 0x10) != 0)) {
        uVar7 = uVar7 | 0x20000000;
      }
      if (((uVar6 & 0x2000000) != 0) &&
         (iVar2 = PathIsRemovableDevice(local_468.cFileName + 0x102), iVar2 != 0)) {
        uVar7 = uVar7 | 0x2000000;
      }
      uVar9 = uVar9 + 1;
      param_3 = param_3 + 1;
      uVar5 = uVar7 & uVar5;
      param_1 = local_57c;
    } while (uVar9 < param_2);
    if (-1 < (int)DVar8) goto LAB_405942d4;
  }
LAB_405942ec:
  *param_4 = 0;
LAB_405942f0:
  FUN_405a7174(local_30);
  return DVar8;
}



/* 40594344 FUN_40594344 */

/* Boundary evidence: original MIPS .pdata 40594344..40594617. Semantic name remains unreviewed. */

int FUN_40594344(int param_1,ushort *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  void *_Src;
  STRSAFE_LPCWSTR pwVar2;
  int iVar3;
  ushort *puVar4;
  LPWSTR pWVar5;
  int *piVar6;
  int iVar7;
  STRSAFE_LPWSTR local_38;
  size_t local_34;
  int local_30 [2];
  
  if ((param_2 == (ushort *)0x0) || (param_4 == (undefined4 *)0x0)) {
    return -0x7ff8ffa9;
  }
  local_34 = 0x104;
  *param_4 = 0;
  local_38 = (STRSAFE_LPWSTR)0x0;
  local_38 = (STRSAFE_LPWSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,0x208);
  piVar6 = param_4 + 1;
  *piVar6 = (int)local_38;
  if (local_38 == (STRSAFE_LPWSTR)0x0) {
    return -0x7ff8fff2;
  }
  iVar7 = -0x7ff8ff91;
  iVar3 = 0;
  if ((param_3 & 1) == 0) {
    local_30[0] = 0;
    _Src = FUN_40593408(param_1,local_30);
    iVar1 = local_30[0];
    if (_Src == (void *)0x0) {
      iVar7 = -0x7ff8fff2;
    }
    else {
      memcpy(local_38,_Src,local_30[0] * 2);
      (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,_Src);
      if (2 < local_34 - iVar1) {
        local_38[iVar1] = L'\\';
        local_38 = local_38 + iVar1 + 1;
        local_34 = local_34 - ((int)local_38 - *piVar6 >> 1);
        goto LAB_405944a0;
      }
    }
    param_2 = (ushort *)0x0;
    iVar3 = iVar7;
  }
LAB_405944a0:
  if (param_2 != (ushort *)0x0) {
    do {
      if ((param_3 & 0x8000) == 0) {
        pwVar2 = (STRSAFE_LPCWSTR)FUN_40580ed0((int)param_2);
        iVar3 = StringCchCopyExW(local_38,local_34,pwVar2,&local_38,&local_34,0);
      }
      else {
        pwVar2 = (STRSAFE_LPCWSTR)FUN_40581264((int)param_2);
        iVar3 = StringCchCopyExW(local_38,local_34,pwVar2,&local_38,&local_34,0);
      }
      if (iVar3 < 0) goto LAB_405945b4;
      puVar4 = (ushort *)FUN_40581214(param_2);
      if (puVar4 == (ushort *)0x0) {
        if ((((param_3 & 0x8000) == 0) && (iVar7 = FUN_40581188((char *)param_2), iVar7 == 0)) &&
           (iVar7 = FUN_405885e4(), iVar7 == 0)) {
          pWVar5 = PathFindExtensionW((LPCWSTR)*piVar6);
          *pWVar5 = L'\0';
        }
      }
      else if (local_34 < 3) {
        iVar3 = -0x7ff8ff91;
        puVar4 = (ushort *)0x0;
      }
      else {
        *local_38 = L'\\';
        local_38 = local_38 + 1;
        local_34 = local_34 - 1;
      }
      param_2 = puVar4;
    } while (puVar4 != (ushort *)0x0);
  }
  if (iVar3 < 0) {
LAB_405945b4:
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,*piVar6);
    *piVar6 = 0;
  }
  return iVar3;
}



/* 40594618 FUN_40594618 */

/* Boundary evidence: original MIPS .pdata 40594618..40594663. Semantic name remains unreviewed. */

undefined4 * FUN_40594618(undefined4 *param_1,uint param_2)

{
  FUN_405a0ea8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40594664 FUN_40594664 */

/* Boundary evidence: original MIPS .pdata 40594664..4059492f. Semantic name remains unreviewed. */

DWORD FUN_40594664(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                  undefined4 *param_6)

{
  void *pvVar1;
  BOOL BVar2;
  LPCITEMIDLIST pIVar3;
  LPCITEMIDLIST pIVar4;
  wchar_t *pwVar5;
  DWORD DVar6;
  HLOCAL pvVar7;
  STRSAFE_PCNZWCH _Str;
  DWORD DVar8;
  ushort *local_238;
  int local_234;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((param_4 == 0) || (param_6 == (undefined4 *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    DVar8 = 0x80070057;
  }
  else {
    local_234 = 0;
    pvVar1 = FUN_40593408(param_1,&local_234);
    *param_6 = 0;
    if (pvVar1 == (void *)0x0) {
      FUN_405a7174(local_28);
      DVar8 = 0x8007000e;
    }
    else {
      DVar8 = StringCchPrintfW(awStack_230,0x104,L"%s\\%s",pvVar1,param_4);
      (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,pvVar1);
      if (-1 < (int)DVar8) {
        BVar2 = PathFileExistsW(awStack_230);
        if (BVar2 == 0) {
          DVar8 = GetLastError();
          if (0 < (int)DVar8) {
            DVar8 = DVar8 & 0xffff | 0x80070000;
          }
        }
        else {
          local_238 = (ushort *)0x0;
          if (*(ushort **)(param_1 + 0x10) == (ushort *)0x0) {
            pIVar3 = FUN_405813a0(*(ushort **)(param_1 + 0x14),-1);
          }
          else {
            pIVar3 = FUN_405812ec(*(ushort **)(param_1 + 0x14),*(ushort **)(param_1 + 0x10));
          }
          _Str = awStack_230 + local_234;
          if (*_Str == L'\\') {
            _Str = awStack_230 + local_234 + 1;
          }
          while (pwVar5 = wcschr(_Str,L'\\'), pwVar5 != (wchar_t *)0x0) {
            *pwVar5 = L'\0';
            FUN_40587d0c(_Str,&local_238);
            FUN_40587714(pIVar3,(int *)&local_238);
            if ((ushort *)*param_6 == (ushort *)0x0) {
              *param_6 = local_238;
              pIVar4 = FUN_405812ec((ushort *)pIVar3,local_238);
              FUN_40580ef4(pIVar3);
            }
            else {
              pvVar7 = FUN_405812ec((ushort *)*param_6,local_238);
              FUN_40580ef4((HLOCAL)*param_6);
              *param_6 = pvVar7;
              pIVar4 = FUN_405812ec((ushort *)pIVar3,local_238);
              FUN_40580ef4(pIVar3);
              FUN_40580ef4(local_238);
            }
            local_238 = (ushort *)0x0;
            _Str = pwVar5 + 1;
            pIVar3 = pIVar4;
          }
          if (*_Str != L'\0') {
            FUN_40587d0c(_Str,&local_238);
            DVar6 = GetFileAttributesW(awStack_230);
            if ((DVar6 != 0xffffffff) && ((DVar6 & 0x10) != 0)) {
              FUN_40587714(pIVar3,(int *)&local_238);
            }
          }
          if ((ushort *)*param_6 == (ushort *)0x0) {
            *param_6 = local_238;
          }
          else if (local_238 != (ushort *)0x0) {
            pvVar7 = FUN_405812ec((ushort *)*param_6,local_238);
            FUN_40580ef4(local_238);
            FUN_40580ef4((HLOCAL)*param_6);
            *param_6 = pvVar7;
          }
          FUN_40580ef4(pIVar3);
        }
      }
      FUN_405a7174(local_28);
    }
  }
  return DVar8;
}



/* 40594930 FUN_40594930 */

/* Boundary evidence: original MIPS .pdata 40594930..40594d97. Semantic name remains unreviewed. */

HRESULT FUN_40594930(int *param_1,HWND param_2,LPCITEMIDLIST param_3,STRSAFE_LPCWSTR param_4,
                    uint param_5,int *param_6)

{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  HRESULT HVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  STRSAFE_LPCWSTR pszSrc;
  LPWSTR pszSrc_00;
  BOOL BVar8;
  LPCITEMIDLIST pIVar9;
  wchar_t *pwVar10;
  LPCWSTR pWVar11;
  STRSAFE_LPWSTR local_988;
  size_t local_984;
  size_t local_980 [2];
  _SHFILEOPSTRUCTW local_978;
  STRRET SStack_958;
  wchar_t local_850 [260];
  wchar_t awStack_648 [260];
  WCHAR WStack_440;
  undefined2 auStack_43e [259];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  local_988 = (LPWSTR)0x0;
  local_984 = 0;
  if ((param_3 == (LPCITEMIDLIST)0x0) || (param_4 == (STRSAFE_LPCWSTR)0x0)) {
    iVar5 = -0x7ff8ffa9;
    goto LAB_40594d60;
  }
  if (param_6 != (int *)0x0) {
    *param_6 = 0;
  }
  HVar4 = StringCchCopyW(local_850,0x104,param_4);
  if (HVar4 < 0) {
LAB_40594adc:
    memset(&SStack_958,0,0x108);
    iVar5 = (**(code **)(*param_1 + 0x2c))(param_1,param_3,0x8000,&SStack_958);
    if ((-1 < iVar5) && (iVar5 = StrRetToBufW(&SStack_958,param_3,&WStack_440,0x104), -1 < iVar5)) {
      sVar7 = wcslen(&WStack_440);
      auStack_43e[sVar7] = 0;
      if ((param_5 & 1) == 0) {
        iVar5 = StringCchCopyW(awStack_648,0x104,local_850);
        local_988 = PathFindFileNameW(awStack_648);
      }
      else {
        pszSrc = FUN_40593408((int)param_1,(int *)0x0);
        if (pszSrc == (STRSAFE_LPCWSTR)0x0) {
          iVar5 = -0x7ff8fff2;
        }
        else {
          iVar5 = StringCchCopyW(awStack_648,0x104,pszSrc);
          if (-1 < iVar5) {
            local_980[0] = 0;
            iVar5 = StringCchCatExW(awStack_648,0x104,L"\\",&local_988,local_980,0);
            if (-1 < iVar5) {
              iVar5 = StringCchCatW(local_988,local_980[0],local_850);
            }
          }
          (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,pszSrc);
        }
      }
      if (-1 < iVar5) {
        if (((((param_5 & 0x8000) == 0) && (iVar6 = FUN_40581188((char *)param_3), iVar6 == 0)) &&
            (iVar6 = FUN_405885e4(), iVar6 == 0)) &&
           (pszSrc_00 = PathFindExtensionW(&WStack_440), *pszSrc_00 != L'\0')) {
          iVar5 = StringCchCatW(awStack_648,0x104,pszSrc_00);
        }
        if (-1 < iVar5) {
          memset(&local_978,0,0x1e);
          local_978.pFrom = &WStack_440;
          local_978.pTo = awStack_648;
          local_978.fFlags._0_1_ = 0x40;
          local_978.wFunc = 4;
          puVar3 = (undefined1 *)((int)&local_978.pTo + 3);
          uVar1 = (uint)puVar3 & 3;
          puVar2 = (uint *)(puVar3 + -uVar1);
          *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | (uint)local_978.pTo >> (3 - uVar1) * 8;
          local_978.fFlags._1_1_ = 0;
          local_978.hwnd = param_2;
          iVar6 = SHFileOperationW(&local_978);
          if ((iVar6 != 0) || (BVar8 = PathFileExistsW(&WStack_440), BVar8 != 0)) {
            iVar5 = -0x7fffbffb;
          }
          if ((-1 < iVar5) && (param_6 != (int *)0x0)) {
            if ((ushort *)param_1[4] == (ushort *)0x0) {
              pIVar9 = FUN_405813a0((ushort *)param_1[5],-1);
            }
            else {
              pIVar9 = FUN_405812ec((ushort *)param_1[5],(ushort *)param_1[4]);
            }
            iVar5 = FUN_40587d0c(local_988,param_6);
            FUN_40587714(pIVar9,param_6);
            FUN_40580ef4(pIVar9);
          }
        }
      }
    }
  }
  else {
    pwVar10 = (wchar_t *)0x0;
    pWVar11 = (LPCWSTR)0x0;
    PathRemoveBlanksW(local_850);
    iVar5 = StringCchLengthW(local_850,0x104,&local_984);
    if (iVar5 < 0) goto LAB_40594d60;
    if ((local_984 == 0) || (local_850[0] == L'.')) {
      pwVar10 = (wchar_t *)0x3043;
      iVar5 = -0x7fffbffb;
LAB_40594ab0:
      if (-1 < iVar5) goto LAB_40594adc;
    }
    else {
      iVar6 = PathIsValidFileName(local_850);
      if (iVar6 != 0) goto LAB_40594ab0;
      iVar5 = LoadStringW(DAT_405aa0c0,0xc044,(LPWSTR)0x0,0);
      iVar6 = LoadStringW(DAT_405aa0c0,0xc05f,(LPWSTR)0x0,0);
      HVar4 = StringCchPrintfExW(awStack_238,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,L"%s%s"
                                 ,iVar6,iVar5);
      if (HVar4 < 0) {
        pwVar10 = (wchar_t *)LoadStringW(DAT_405aa0c0,0xc044,(LPWSTR)0x0,0);
      }
      else {
        pwVar10 = awStack_238;
        pWVar11 = (LPCWSTR)FUN_40580ed0((int)param_3);
      }
      iVar5 = -0x7fffbffb;
    }
    FUN_4058a544(param_2,(LPCWSTR)0x3025,pwVar10,pWVar11,0x10);
  }
LAB_40594d60:
  FUN_405a7174(local_30);
  return iVar5;
}



/* 40594d98 FUN_40594d98 */

/* Boundary evidence: original MIPS .pdata 40594d98..4059507b. Semantic name remains unreviewed. */

undefined4 FUN_40594d98(int param_1,char *param_2,int param_3,int *param_4)

{
  uint uVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  LPWSTR pWVar5;
  STRSAFE_PCNZWCH psz;
  HRESULT HVar6;
  STRSAFE_LPWSTR pszDest;
  undefined3 extraout_var;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  FILETIME local_20;
  
  if ((param_2 == (char *)0x0) || (param_4 == (int *)0x0)) {
    return 0x80070057;
  }
  if (param_3 == 0) {
    uVar7 = (**(code **)(*(int *)(param_1 + -4) + 0x2c))
                      ((int *)(param_1 + -4),param_2,0x1001,param_4 + 2);
    return uVar7;
  }
  if (param_3 == 1) {
    iVar4 = (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,0x3c);
    piVar9 = param_4 + 3;
    *piVar9 = iVar4;
    if (iVar4 == 0) {
      return 0x8007000e;
    }
    param_4[2] = 0;
    iVar4 = FUN_40581188(param_2);
    if (iVar4 != 0) {
      *(undefined2 *)*piVar9 = 0;
      return 0;
    }
    local_20.dwLowDateTime = 0;
    memset(&local_20.dwHighDateTime,0,4);
    iVar4 = FUN_40580f64((int)param_2,&local_20.dwLowDateTime);
    if ((iVar4 != 0) &&
       (bVar3 = FUN_40589504(local_20.dwLowDateTime,local_20.dwHighDateTime,(STRSAFE_LPWSTR)*piVar9,
                             0x1e), CONCAT31(extraout_var,bVar3) != 0)) {
      return 0;
    }
    iVar4 = *piVar9;
  }
  else {
    if (param_3 != 2) {
      uVar8 = 3;
      if (param_3 != 3) {
        if (param_3 != 4) {
          return 0x80004005;
        }
        return 0;
      }
      local_20.dwLowDateTime = 0;
      memset(&local_20.dwHighDateTime,0,4);
      iVar4 = FUN_40580f18((int)param_2,&local_20.dwLowDateTime);
      if (iVar4 == 0) {
        return 0x80004005;
      }
      if (*param_4 == 0x10) {
        uVar8 = 0x103;
      }
      else if (*param_4 == 0x20) {
        uVar8 = 0x203;
      }
      pWVar5 = (LPWSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,0x80);
      param_4[3] = (int)pWVar5;
      if (pWVar5 == (LPWSTR)0x0) {
        return 0x8007000e;
      }
      uVar1 = (int)param_4 + 0xbU & 3;
      puVar2 = (uint *)(((int)param_4 + 0xbU) - uVar1);
      *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
      uVar1 = (uint)(param_4 + 2) & 3;
      puVar2 = (uint *)((int)(param_4 + 2) - uVar1);
      *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
      FUN_4058989c(&local_20,uVar8,pWVar5,0x40);
      return 0;
    }
    iVar4 = FUN_40581188(param_2);
    if (iVar4 == 0) {
      psz = (STRSAFE_PCNZWCH)FUN_40580fb4((int)param_2);
    }
    else {
      psz = (STRSAFE_PCNZWCH)LoadStringW(DAT_405aa0c0,0x500c,(LPWSTR)0x0,0);
    }
    local_20.dwLowDateTime = 0;
    if (psz == (STRSAFE_PCNZWCH)0x0) {
      return 0x80004005;
    }
    HVar6 = StringCchLengthW(psz,0x104,&local_20.dwLowDateTime);
    if (HVar6 < 0) {
      return 0x80004005;
    }
    pszDest = (STRSAFE_LPWSTR)
              (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(local_20.dwLowDateTime + 1) * 2);
    param_4[3] = (int)pszDest;
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      return 0x8007000e;
    }
    param_4[2] = 0;
    HVar6 = StringCchCopyW(pszDest,local_20.dwLowDateTime + 1,psz);
    if (-1 < HVar6) {
      return 0;
    }
    iVar4 = param_4[3];
  }
  (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,iVar4);
  return 0x80004005;
}



/* 4059507c FUN_4059507c */

/* Boundary evidence: original MIPS .pdata 4059507c..40595197. Semantic name remains unreviewed. */

DWORD FUN_4059507c(int param_1,ushort *param_2)

{
  LPCWSTR lpFileName;
  DWORD DVar1;
  DWORD DVar2;
  
  if (param_2 == (ushort *)0x0) {
    DVar2 = 0x80070057;
  }
  else {
    DVar2 = FUN_40593590(param_1 + -8,param_2);
    if (-1 < (int)DVar2) {
      lpFileName = FUN_40593408(param_1 + -8,(int *)(param_1 + 0x10));
      if (lpFileName == (LPCWSTR)0x0) {
        DVar2 = 0x8007000e;
      }
      else {
        DVar1 = GetFileAttributesW(lpFileName);
        if ((DVar1 == 0xffffffff) && (DVar2 = GetLastError(), 0 < (int)DVar2)) {
          DVar2 = DVar2 & 0xffff | 0x80070000;
        }
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpFileName);
      }
      if (-1 < (int)DVar2) {
        return DVar2;
      }
    }
    if (*(HLOCAL *)(param_1 + 8) != (HLOCAL)0x0) {
      FUN_40580ef4(*(HLOCAL *)(param_1 + 8));
      *(undefined4 *)(param_1 + 8) = 0;
    }
    if (*(HLOCAL *)(param_1 + 0xc) != (HLOCAL)0x0) {
      FUN_40580ef4(*(HLOCAL *)(param_1 + 0xc));
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  return DVar2;
}



/* 405951d4 FUN_405951d4 */

/* Boundary evidence: original MIPS .pdata 405951d4..40595217. Semantic name remains unreviewed. */

int FUN_405951d4(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[3] + -1;
  param_1[3] = iVar1;
  if (iVar1 == 0) {
    FUN_405933a0(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40595218 FUN_40595218 */

/* Boundary evidence: original MIPS .pdata 40595218..405956b7. Semantic name remains unreviewed. */

int FUN_40595218(int *param_1,undefined4 param_2,uint param_3,undefined4 *param_4,int *param_5,
                undefined4 param_6,undefined4 *param_7)

{
  ushort uVar1;
  undefined4 *puVar2;
  int *piVar3;
  UINT UVar4;
  HLOCAL pvVar5;
  undefined2 extraout_var;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_380;
  undefined4 *local_37c [3];
  uint local_370;
  undefined4 local_36c;
  HLOCAL local_368;
  uint local_364;
  undefined4 *local_360;
  undefined2 local_358 [2];
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  STRRET local_340;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  if ((param_4 == (undefined4 *)0x0) || (param_7 == (undefined4 *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return -0x7ff8ffa9;
  }
  *param_7 = 0;
  iVar6 = *param_5;
  iVar7 = -0x7fffbfff;
  if ((((iVar6 == 0x10e) && (param_5[1] == 0)) && (param_5[2] == 0xc0)) &&
     (param_5[3] == 0x46000000)) {
    puVar2 = operator_new(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_405a23c8(puVar2);
    }
    if (piVar3 != (int *)0x0) {
      local_358[0] = 0;
      memset(&local_354,0,0x10);
      local_380 = 0;
      memset(local_37c,0,8);
      UVar4 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
      if ((ushort *)param_1[4] == (ushort *)0x0) {
        pvVar5 = FUN_405813a0((ushort *)param_1[5],-1);
      }
      else {
        pvVar5 = FUN_405812ec((ushort *)param_1[5],(ushort *)param_1[4]);
      }
      if (pvVar5 == (HLOCAL)0x0) {
        iVar7 = -0x7ff8fff2;
      }
      else {
        FUN_405a0a00(&local_370);
        uVar8 = 0;
        puVar2 = param_4;
        if (param_3 != 0) {
          do {
            uVar1 = FUN_405811d8((char *)*puVar2);
            if (CONCAT22(extraout_var,uVar1) != 0) {
              local_370 = local_370 | 1;
              break;
            }
            uVar8 = uVar8 + 1;
            puVar2 = puVar2 + 1;
          } while (uVar8 < param_3);
        }
        local_36c = param_2;
        local_368 = pvVar5;
        local_364 = param_3;
        local_360 = param_4;
        local_37c[0] = FUN_405a0c08(&local_370);
        if (local_37c[0] != (undefined4 *)0x0) {
          local_350 = 1;
          local_380 = 1;
          local_348 = 1;
          local_358[0] = (undefined2)UVar4;
          local_354 = 0;
          local_34c = 0xffffffff;
          iVar7 = (**(code **)(*piVar3 + 0x1c))(piVar3,local_358,&local_380,1);
        }
        FUN_40580ef4(pvVar5);
      }
      if (-1 < iVar7) {
LAB_40595620:
        iVar7 = (**(code **)*piVar3)(piVar3,param_5,param_7);
LAB_40595644:
        (**(code **)(*piVar3 + 8))(piVar3);
        goto LAB_40595664;
      }
      FUN_405a0ea8(piVar3);
      operator_delete(piVar3);
LAB_40595448:
      *param_7 = 0;
      goto LAB_40595664;
    }
  }
  else if (((iVar6 == 0x122) && (param_5[1] == 0)) &&
          ((param_5[2] == 0xc0 && (param_5[3] == 0x46000000)))) {
    puVar2 = operator_new(0x214);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_4059ed1c(puVar2);
    }
    if (piVar3 != (int *)0x0) {
      local_340.uType = 0;
      memset(&local_340.u,0,0x104);
      iVar7 = (**(code **)(*param_1 + 0x2c))(param_1,*param_4,0x8000,&local_340);
      if ((-1 < iVar7) &&
         (iVar7 = StrRetToBufW(&local_340,(LPCITEMIDLIST)*param_4,aWStack_238,0x104), -1 < iVar7)) {
        iVar7 = FUN_4059e6ec((int)piVar3,aWStack_238);
        if (iVar7 == 0) {
          iVar7 = -0x7fffbffb;
        }
        else {
          iVar7 = (**(code **)*piVar3)(piVar3,param_5,param_7);
          (**(code **)(*piVar3 + 8))(piVar3);
        }
        if (-1 < iVar7) goto LAB_40595664;
      }
      (**(code **)(*piVar3 + 8))(piVar3);
      goto LAB_40595448;
    }
  }
  else {
    if (((iVar6 != 0x214e4) || (param_5[1] != 0)) ||
       ((param_5[2] != 0xc0 || (param_5[3] != 0x46000000)))) goto LAB_40595664;
    puVar2 = operator_new(0x1c);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_405a33cc(puVar2);
    }
    if (piVar3 != (int *)0x0) {
      iVar7 = FUN_405a29b4((int)piVar3,param_1,param_3,(int)param_4);
      if (iVar7 != 0) goto LAB_40595620;
      iVar7 = -0x7fffbffb;
      goto LAB_40595644;
    }
  }
  iVar7 = -0x7ff8fff2;
LAB_40595664:
  FUN_405a7174(local_30);
  return iVar7;
}



/* 405956e0 FUN_405956e0 */

/* Boundary evidence: original MIPS .pdata 405956e0..4059575b. Semantic name remains unreviewed. */

undefined4 * FUN_405956e0(undefined4 *param_1)

{
  param_1[1] = &PTR_LAB_40571f30;
  *param_1 = &PTR_FUN_4057206c;
  param_1[1] = &PTR_LAB_40572058;
  param_1[2] = &PTR_LAB_40572044;
  param_1[4] = 0;
  param_1[5] = (LPITEMIDLIST)0x0;
  param_1[6] = 0;
  param_1[7] = 0;
  SHGetSpecialFolderLocation((HWND)0x0,0x11,(LPITEMIDLIST *)(param_1 + 5));
  param_1[3] = 1;
  return param_1;
}



/* 4059575c FUN_4059575c */

/* Boundary evidence: original MIPS .pdata 4059575c..405958a7. Semantic name remains unreviewed. */

int FUN_4059575c(int param_1,ushort *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  HLOCAL pvVar3;
  int iVar4;
  
  if ((param_2 == (ushort *)0x0) || (param_5 == (undefined4 *)0x0)) {
    iVar4 = -0x7ff8ffa9;
  }
  else {
    *param_5 = 0;
    puVar1 = operator_new(0x20);
    if (puVar1 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_405956e0(puVar1);
    }
    if (piVar2 == (int *)0x0) {
      iVar4 = -0x7ff8fff2;
    }
    else {
      FUN_40593608((int)piVar2,*(int *)(param_1 + 0x1c));
      if (*(ushort **)(param_1 + 0x10) == (ushort *)0x0) {
        pvVar3 = FUN_405813a0(param_2,-1);
      }
      else {
        pvVar3 = FUN_405812ec(*(ushort **)(param_1 + 0x10),param_2);
      }
      if (pvVar3 == (HLOCAL)0x0) {
        iVar4 = -0x7ff8fff2;
      }
      else {
        iVar4 = (**(code **)(piVar2[2] + 0x10))(piVar2 + 2,pvVar3);
        if (-1 < iVar4) {
          iVar4 = (**(code **)*piVar2)(piVar2,param_4,param_5);
        }
        FUN_40580ef4(pvVar3);
      }
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  return iVar4;
}



/* 405958a8 FUN_405958a8 */

/* Boundary evidence: original MIPS .pdata 405958a8..405958d7. Semantic name remains unreviewed. */

void FUN_405958a8(int param_1)

{
  FUN_40580ef4(*(HLOCAL *)(param_1 + 4));
  FUN_40580ef4(*(HLOCAL *)(param_1 + 8));
  return;
}



/* 405958d8 FUN_405958d8 */

/* Boundary evidence: original MIPS .pdata 405958d8..4059594f. Semantic name remains unreviewed. */

int FUN_405958d8(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = param_1;
  if ((*(uint *)(param_3 + 0x54) & 0x10) != 0) {
    uVar2 = param_2;
    param_2 = param_1;
  }
  iVar1 = (**(code **)(**(int **)(param_3 + 0x68) + 0x1c))
                    (*(int **)(param_3 + 0x68),*(undefined1 *)(param_3 + 0x48),uVar2,param_2);
  if (-1 < iVar1) {
    iVar3 = (int)(short)iVar1;
  }
  return iVar3;
}



/* 40595950 FUN_40595950 */

/* Boundary evidence: original MIPS .pdata 40595950..405959e7. Semantic name remains unreviewed. */

void FUN_40595950(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (DAT_405aa304 == 0) {
    piVar2 = &DAT_405aa308;
    iVar3 = 0;
    do {
      iVar1 = LoadStringW(DAT_405aa0c0,iVar3 + 0x3065,(LPWSTR)0x0,0);
      *piVar2 = iVar1;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x405aa320);
  }
  DAT_405aa304 = DAT_405aa304 + 1;
  return;
}



/* 405959e8 FUN_405959e8 */

/* Boundary evidence: original MIPS .pdata 405959e8..40595b9b. Semantic name remains unreviewed. */

int FUN_405959e8(void)

{
  HRESULT HVar1;
  int iVar2;
  wchar_t *pwVar3;
  LPCITEMIDLIST local_5f0;
  int *local_5ec;
  LPITEMIDLIST local_5e8 [2];
  STRRET local_5e0;
  undefined4 local_4d8;
  undefined1 auStack_4d4 [692];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  if (DAT_405aa320 == 0) {
    local_5e8[0] = (LPCITEMIDLIST)0x0;
    HVar1 = SHGetSpecialFolderLocation((HWND)0x0,0x11,local_5e8);
    if (-1 < HVar1) {
      local_5ec = (int *)0x0;
      local_5f0 = (LPCITEMIDLIST)0x0;
      HVar1 = SHBindToParent(local_5e8[0],(IID *)&DAT_40572b68,&local_5ec,&local_5f0);
      if (-1 < HVar1) {
        local_4d8 = 0;
        memset(auStack_4d4,0,0x2b0);
        local_5e0.uType = 0;
        memset(&local_5e0.u,0,0x104);
        iVar2 = (**(code **)(*local_5ec + 0x2c))(local_5ec,local_5f0,0x8000,&local_5e0);
        if ((-1 < iVar2) &&
           (HVar1 = StrRetToBufW(&local_5e0,local_5f0,aWStack_220,0x104), -1 < HVar1)) {
          pwVar3 = wcsrchr(aWStack_220,L'{');
          iVar2 = SHGetFileInfo(pwVar3,0,&local_4d8,0x2b4,0x111);
          if (iVar2 != 0) {
            DAT_405aa328 = local_4d8;
          }
        }
        iVar2 = (**(code **)(*local_5ec + 0x2c))(local_5ec,local_5f0,0,&local_5e0);
        if ((-1 < iVar2) && (local_5e0.uType == 0)) {
          DAT_405aa324 = local_5e0.u.pOleStr;
        }
        (**(code **)(*local_5ec + 8))();
        FUN_40580ef4(local_5f0);
      }
      FUN_40580ef4(local_5e8[0]);
    }
  }
  iVar2 = DAT_405aa320 + 1;
  DAT_405aa320 = iVar2;
  FUN_405a7174(local_18);
  return iVar2;
}



/* 40595b9c FUN_40595b9c */

/* Boundary evidence: original MIPS .pdata 40595b9c..40595c2b. Semantic name remains unreviewed. */

int FUN_40595b9c(void)

{
  DAT_405aa320 = DAT_405aa320 + -1;
  if (DAT_405aa320 == 0) {
    if (DAT_405aa328 != (HICON)0x0) {
      DestroyIcon(DAT_405aa328);
      DAT_405aa328 = (HICON)0x0;
    }
    if (DAT_405aa324 != 0) {
      (**(code **)(*DAT_405aa0c8 + 0x14))();
      DAT_405aa324 = 0;
    }
  }
  return DAT_405aa320;
}



/* 40595c2c FUN_40595c2c */

/* Boundary evidence: original MIPS .pdata 40595c2c..40595dfb. Semantic name remains unreviewed. */

undefined4 FUN_40595c2c(int param_1,int param_2)

{
  LPCITEMIDLIST pidl;
  uint uVar1;
  int iVar2;
  int iVar3;
  HRESULT HVar4;
  undefined4 uVar5;
  STRRET local_538;
  WCHAR aWStack_430 [260];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x40;
  uVar5 = 0;
  if ((*(int *)(param_2 + 0x20) != 0) &&
     (pidl = (LPCITEMIDLIST)FUN_405a3ed0(*(undefined4 **)(param_1 + 0x44),*(int *)(param_2 + 0x10)),
     pidl != (LPCITEMIDLIST)0x0)) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x68) + 0x30))
                      (*(int **)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x28),pidl,
                       *(undefined4 *)(param_2 + 0x20),0x1001,0);
    if ((int)uVar1 < 0) {
      if ((uVar1 & 0xffff) == 0x7a) {
        iVar2 = LoadStringW(DAT_405aa0c0,0xc014,(LPWSTR)0x0,0);
        iVar3 = LoadStringW(DAT_405aa0c0,0xc05f,(LPWSTR)0x0,0);
        HVar4 = StringCchPrintfExW(awStack_228,0x104,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,
                                   L"%s%s",iVar3,iVar2);
        if (-1 < HVar4) {
          local_538.uType = 0;
          memset(&local_538.u,0,0x104);
          iVar2 = (**(code **)(**(int **)(param_1 + 0x68) + 0x2c))
                            (*(int **)(param_1 + 0x68),pidl,0,&local_538);
          if ((-1 < iVar2) && (HVar4 = StrRetToBufW(&local_538,pidl,aWStack_430,0x104), -1 < HVar4))
          {
            FUN_4058a544(*(HWND *)(param_1 + 0x28),(LPCWSTR)0x3025,awStack_228,aWStack_430,0x10);
          }
        }
      }
    }
    else {
      DAT_405a995c = 0x3108;
      uVar5 = 1;
    }
  }
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xffffffbe;
  FUN_405a7174(local_20);
  return uVar5;
}



/* 40595dfc FUN_40595dfc */

/* Boundary evidence: original MIPS .pdata 40595dfc..40595e8f. Semantic name remains unreviewed. */

undefined4 FUN_40595dfc(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_18;
  int local_14;
  
  uVar2 = 1;
  if (param_2 != 0) {
    local_14 = FUN_405a3ed0(*(undefined4 **)(param_1 + 0x44),*(int *)(param_2 + 0x10));
    if (local_14 != 0) {
      local_18 = 0x10;
      iVar1 = (**(code **)(**(int **)(param_1 + 0x68) + 0x24))
                        (*(int **)(param_1 + 0x68),1,&local_14,&local_18);
      if ((-1 < iVar1) && ((local_18 & 0x10) != 0)) {
        *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 1;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



/* 40595e90 FUN_40595e90 */

/* Boundary evidence: original MIPS .pdata 40595e90..4059605f. Semantic name remains unreviewed. */

int FUN_40595e90(int *param_1,HWND param_2,int param_3,int param_4)

{
  LANGID LVar1;
  int iVar2;
  uint uVar3;
  HRESULT HVar4;
  int iVar5;
  int iVar6;
  LPDROPTARGET local_20 [2];
  
  iVar5 = -1;
  param_1[10] = (int)param_2;
  iVar6 = -1;
  if (param_2 != (HWND)0x0) {
    SetWindowLongW(param_2,-0x15,(LONG)param_1);
    if (((int *)param_1[0x11] != (int *)0x0) &&
       (iVar2 = FUN_405a5318((int *)param_1[0x11],(HWND)param_1[10],param_1[0x16]), iVar2 != 0)) {
      if ((param_1[0x15] & 0x20U) != 0) {
        iVar5 = FUN_40588568();
        param_1[0x17] = iVar5;
      }
      iVar5 = FUN_405a4924((undefined4 *)param_1[0x11],param_1[0x17]);
      param_1[0x17] = iVar5;
      param_1[0x18] = DAT_405a995c;
      *(undefined2 *)((int)param_1 + 0x4a) = 0;
      LVar1 = GetUserDefaultUILanguage();
      if ((LVar1 & 0x3ff) == 1) {
        uVar3 = GetWindowLongW((HWND)param_1[10],-0x14);
        if ((uVar3 & 0x400000) == 0) {
          *(undefined2 *)((int)param_1 + 0x4a) = 0x10;
        }
        else {
          *(undefined2 *)((int)param_1 + 0x4a) = 0x20;
        }
      }
      (**(code **)(*param_1 + 0x7c))(param_1);
      (**(code **)(*param_1 + 0x78))(param_1);
      FUN_405a4770((undefined4 *)param_1[0x11],param_3,param_4);
      iVar2 = (**(code **)(*param_1 + 0x20))(param_1);
      iVar5 = iVar6;
      if (-1 < iVar2) {
        local_20[0] = (LPDROPTARGET)0x0;
        iVar2 = (**(code **)*param_1)(param_1,&DAT_40572b48,local_20);
        if (-1 < iVar2) {
          HVar4 = RegisterDragDrop(*(HWND *)param_1[0x11],local_20[0]);
          if (-1 < HVar4) {
            iVar6 = 0;
          }
          (**(code **)(*param_1 + 8))(param_1);
          iVar5 = iVar6;
          if (iVar6 != -1) {
            return iVar6;
          }
        }
      }
      (**(code **)(*param_1 + 0x4c))(param_1);
    }
  }
  return iVar5;
}



/* 40596060 FUN_40596060 */

/* Boundary evidence: original MIPS .pdata 40596060..405960d3. Semantic name remains unreviewed. */

void FUN_40596060(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  if ((*(int *)(param_1 + 0x4c) != 0) &&
     (bVar1 = FUN_4058e7ac(DAT_405aa0cc,*(int *)(param_1 + 0x4c)), CONCAT31(extraout_var,bVar1) != 0
     )) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x44) != (undefined4 *)0x0) {
    RevokeDragDrop((HWND)**(undefined4 **)(param_1 + 0x44));
    FUN_405a3a5c(*(undefined4 **)(param_1 + 0x44));
  }
  SetWindowLongW(*(HWND *)(param_1 + 0x28),-0x15,0);
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}



/* 405960d4 FUN_405960d4 */

/* Boundary evidence: original MIPS .pdata 405960d4..4059639b. Semantic name remains unreviewed. */

void FUN_405960d4(int *param_1,LONG param_2,int param_3)

{
  int *piVar1;
  HMENU hMenu;
  int iVar2;
  uint uVar3;
  HMENU hmenu;
  UINT UVar4;
  int nPos;
  int local_90;
  int local_8c;
  LRESULT LStack_88;
  int local_84;
  int *local_80 [2];
  undefined4 local_78;
  undefined1 auStack_74 [4];
  int local_70;
  uint local_6c;
  MENUITEMINFOW local_50;
  
  if (param_1[0x11] == 0) {
    return;
  }
  local_90 = 0;
  memset(&local_8c,0,0x10);
  hMenu = (HMENU)(**(code **)(*param_1 + 0x80))(param_1);
  UVar4 = 0x100;
  if (hMenu == (HMENU)0x0) {
    return;
  }
  local_84 = FUN_405a4104((undefined4 *)param_1[0x11],&LStack_88);
  local_8c = FUN_405a3fdc((int *)param_1[0x11],param_2,param_3);
  nPos = 1;
  if ((local_84 != 0) && (local_8c != 0)) {
    (**(code **)(*(int *)param_1[0x1a] + 0x28))
              ((int *)param_1[0x1a],param_1[10],1,&local_8c,&DAT_40572c38,0,local_80);
  }
  iVar2 = GetSystemMetrics(0x4e);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  if (iVar2 >> 1 <= param_2) {
    UVar4 = 0x108;
  }
  uVar3 = GetWindowLongW((HWND)param_1[10],-0x14);
  if ((uVar3 & 0x400000) != 0) {
    UVar4 = UVar4 ^ 8;
  }
  iVar2 = GetSystemMetrics(0x4f);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  if (iVar2 >> 1 <= param_3) {
    UVar4 = UVar4 | 0x20;
  }
  if ((local_84 == 0) || (local_8c == 0)) {
    nPos = 0;
  }
  local_90 = nPos;
  hmenu = GetSubMenu(hMenu,nPos);
  if (hmenu != (HMENU)0x0) {
    memset(&local_50.fMask,0,0x28);
    local_50.fMask = 0x20;
    local_50.cbSize = 0x2c;
    local_50.dwItemData = (ULONG_PTR)&local_90;
    SetMenuItemInfoW(hmenu,0,1,&local_50);
    uVar3 = TrackPopupMenuEx(hmenu,UVar4,param_2,param_3,(HWND)param_1[10],(LPTPMPARAMS)0x0);
    piVar1 = local_80[0];
    if (uVar3 != 0) {
      if ((uVar3 < 0x1100) || (0x1199 < uVar3)) {
        SendMessageW((HWND)param_1[10],0x111,uVar3,0);
      }
      else {
        if (local_80[0] == (int *)0x0) goto LAB_4059634c;
        memset(auStack_74,0,0x20);
        local_70 = param_1[10];
        local_6c = uVar3 & 0xffff;
        local_78 = 0x24;
        (**(code **)(*piVar1 + 0x10))(piVar1,&local_78);
      }
    }
  }
  if (local_80[0] != (int *)0x0) {
    (**(code **)(*local_80[0] + 8))();
  }
LAB_4059634c:
  if (local_84 != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
  }
  DestroyMenu(hMenu);
  return;
}



/* 4059639c FUN_4059639c */

/* Boundary evidence: original MIPS .pdata 4059639c..405964cf. Semantic name remains unreviewed. */

void FUN_4059639c(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  LPDATAOBJECT local_20;
  LPDROPSOURCE local_1c;
  LRESULT local_18 [2];
  
  local_20 = (LPDATAOBJECT)0x0;
  local_18[0] = 0;
  iVar1 = FUN_405a4104((undefined4 *)param_1[0x11],local_18);
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)param_1[0x1a] + 0x28))
                      ((int *)param_1[0x1a],*(undefined4 *)param_1[0x11],local_18[0],iVar1,
                       &DAT_40572c48,0,&local_20);
    if ((-1 < iVar2) && (local_20 != (LPDATAOBJECT)0x0)) {
      local_1c = (LPDROPSOURCE)0x0;
      iVar2 = (**(code **)*param_1)(param_1,&DAT_40572c58,&local_1c);
      if (-1 < iVar2) {
        local_18[1] = 0;
        FUN_405a3598((int *)param_1[0x11],param_2);
        DoDragDrop(local_20,local_1c,7,(LPDWORD)(local_18 + 1));
        FUN_405a3c44((undefined4 *)param_1[0x11]);
        (*local_1c->lpVtbl->Release)(local_1c);
      }
      (*local_20->lpVtbl->Release)(local_20);
    }
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,iVar1);
  }
  return;
}



/* 405964d0 FUN_405964d0 */

/* Boundary evidence: original MIPS .pdata 405964d0..405966f7. Semantic name remains unreviewed. */

void FUN_405964d0(int param_1)

{
  STRSAFE_LPCWSTR pszSrc;
  int iVar1;
  HRESULT HVar2;
  BOOL BVar3;
  LPWSTR pWVar4;
  DWORD DVar5;
  wchar_t *pwVar6;
  ushort *local_438;
  size_t local_434;
  wchar_t awStack_430 [260];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  pszSrc = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3004,(LPWSTR)0x0,0);
  pwVar6 = (wchar_t *)0x0;
  iVar1 = SHGetPathFromIDList(*(LPCITEMIDLIST *)(param_1 + 0x24),awStack_430);
  if ((iVar1 == 0) || (pszSrc == (STRSAFE_LPCWSTR)0x0)) {
    MessageBeep(0xffffffff);
    goto LAB_405966d4;
  }
  HVar2 = StringCchLengthW(awStack_430,0x104,&local_434);
  if ((((HVar2 < 0) || (local_434 == 0)) ||
      ((awStack_430[local_434 - 1] != L'\\' &&
       (HVar2 = StringCchCatW(awStack_430,0x104,L"\\"), HVar2 < 0)))) ||
     (HVar2 = StringCchCatW(awStack_430,0x104,pszSrc), HVar2 < 0)) {
LAB_40596694:
    pwVar6 = (wchar_t *)0x300b;
  }
  else {
    BVar3 = PathMakeUniqueName(awStack_430,0,(LPCWSTR)0x0,(LPCWSTR)0x0,aWStack_228);
    if (BVar3 == 0) goto LAB_40596694;
    local_438 = (ushort *)0x0;
    pWVar4 = PathFindFileNameW(aWStack_228);
    if ((pWVar4 != (LPWSTR)0x0) && (iVar1 = FUN_40587d0c(pWVar4,&local_438), -1 < iVar1)) {
      FUN_405a4524(*(int *)(param_1 + 0x44),local_438);
    }
    BVar3 = CreateDirectoryW(aWStack_228,(LPSECURITY_ATTRIBUTES)0x0);
    if (BVar3 == 0) {
      DVar5 = GetLastError();
      if ((DVar5 == 2) || (DVar5 == 5)) {
        pwVar6 = (wchar_t *)0x3008;
      }
      else if ((DVar5 == 0x27) || (DVar5 == 0x70)) {
        pwVar6 = (wchar_t *)0x3009;
      }
      else {
        pwVar6 = (wchar_t *)0x300a;
      }
    }
    if (local_438 != (ushort *)0x0) {
      FUN_40580ef4(local_438);
    }
  }
  if (pwVar6 != (wchar_t *)0x0) {
    FUN_4058a544((HWND)**(undefined4 **)(param_1 + 0x44),(LPCWSTR)0x3004,pwVar6,awStack_430,0x10);
  }
LAB_405966d4:
  FUN_405a7174(local_20);
  return;
}



/* 405966f8 FUN_405966f8 */

/* Boundary evidence: original MIPS .pdata 405966f8..405969db. Semantic name remains unreviewed. */

void FUN_405966f8(int *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  HRESULT HVar6;
  LPCITEMIDLIST local_580;
  uint local_57c;
  int *local_578 [2];
  undefined4 local_570;
  undefined1 auStack_56c [8];
  undefined1 auStack_564 [4];
  undefined1 auStack_560 [4];
  wchar_t *local_55c;
  undefined1 auStack_558 [4];
  undefined1 auStack_554 [4];
  undefined1 auStack_550 [32];
  STRRET SStack_530;
  WCHAR aWStack_428 [260];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  local_57c = 0;
  puVar4 = (undefined4 *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)&local_57c);
  local_570 = 0x3c;
  puVar1 = auStack_56c + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x440U >> (3 - uVar2) * 8;
  puVar1 = auStack_564 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_558 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_554 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 5U >> (3 - uVar2) * 8;
  puVar1 = auStack_550 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_560 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x405722acU >> (3 - uVar2) * 8;
  auStack_56c._0_4_ = 0x440;
  auStack_564 = (undefined1  [4])0x0;
  auStack_558 = (undefined1  [4])0x0;
  auStack_554 = (undefined1  [4])0x5;
  auStack_550._0_4_ = 0;
  auStack_560 = (undefined1  [4])&UNK_405722ac;
  if (puVar4 != (undefined4 *)0x0) {
    if (local_57c < 2) {
      if (local_57c == 1) {
        iVar5 = FUN_4058150c((ushort *)*puVar4,&DAT_405719b0);
        if (iVar5 == 0) {
          iVar5 = FUN_4058150c((ushort *)*puVar4,&DAT_405719d0);
          if (iVar5 == 0) {
            FUN_4058d868((ushort *)param_1[9],(int *)param_1[0x1a],param_1,(int)puVar4,local_57c);
          }
          else {
            local_55c = L"cplmain.cpl,6";
            ShellExecuteEx(&local_570);
          }
        }
        else {
          FUN_4058b984();
        }
      }
    }
    else {
      FUN_4058d868((ushort *)param_1[9],(int *)param_1[0x1a],param_1,(int)puVar4,local_57c);
    }
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,puVar4);
    goto LAB_405969c0;
  }
  iVar5 = FUN_4058150c((ushort *)param_1[9],&DAT_405719b0);
  if (iVar5 != 0) {
    FUN_4058b984();
    goto LAB_405969c0;
  }
  puVar1 = (undefined1 *)((int)&SStack_530.uType + 3);
  uVar2 = (uint)puVar1 & 3;
  puVar3 = (uint *)(puVar1 + -uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  local_578[0] = (int *)0x0;
  local_580 = (LPCITEMIDLIST)0x0;
  SStack_530.uType = 0;
  memset(&SStack_530.u,0,0x104);
  HVar6 = SHBindToParent((LPCITEMIDLIST)param_1[9],(IID *)&DAT_40572b68,local_578,&local_580);
  if (-1 < HVar6) {
    iVar5 = FUN_4058150c((ushort *)local_580,&DAT_405719d0);
    if (iVar5 == 0) {
      (**(code **)(*local_578[0] + 0x2c))(local_578[0],local_580,0x8000,&SStack_530);
      StrRetToBufW(&SStack_530,local_580,aWStack_428,0x104);
      iVar5 = SHGetSpecialFolderPath(0,aWStack_220,0x10,1);
      if (iVar5 != 0) {
        iVar5 = CompareStringW(0x400,1,aWStack_220,-1,aWStack_428,-1);
        if (iVar5 == 2) {
          local_55c = L"cplmain.cpl,7";
          goto LAB_4059696c;
        }
        FUN_4058d9d0((ushort *)param_1[9],(int *)param_1[0x1a]);
      }
    }
    else {
      local_55c = L"cplmain.cpl,6";
LAB_4059696c:
      ShellExecuteEx(&local_570);
    }
  }
  if (local_580 != (LPCITEMIDLIST)0x0) {
    FUN_40580ef4(local_580);
  }
  if (local_578[0] != (int *)0x0) {
    (**(code **)(*local_578[0] + 8))();
  }
LAB_405969c0:
  FUN_405a7174(local_18);
  return;
}



/* 405969dc FUN_405969dc */

/* Boundary evidence: original MIPS .pdata 405969dc..40596c73. Semantic name remains unreviewed. */

void FUN_405969dc(int param_1,int param_2)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  HRESULT HVar4;
  undefined2 extraout_var_00;
  wchar_t *pwVar5;
  undefined3 extraout_var;
  LPCITEMIDLIST pidl;
  uint uVar6;
  int *local_5f8 [2];
  undefined1 local_5f0 [272];
  undefined4 local_4e0;
  int local_4dc;
  uint local_4d8;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  if (param_2 != 0) {
    pidl = *(LPCITEMIDLIST *)(param_2 + 0x2c);
    if ((*(int *)(param_2 + 0x14) == 0) && (uVar6 = *(uint *)(param_2 + 0xc), (uVar6 & 2) != 0)) {
      local_4e0 = 0;
      memset(&local_4dc,0,0x2b0);
      local_5f0._0_4_ = 0;
      memset(local_5f0 + 4,0,0x104);
      *(uint *)(param_2 + 0xc) = uVar6 | 0x1000;
      iVar3 = (**(code **)(**(int **)(param_1 + 0x68) + 0x2c))
                        (*(int **)(param_1 + 0x68),pidl,0x8000,local_5f0);
      if ((-1 < iVar3) &&
         (HVar4 = StrRetToBufW((STRRET *)local_5f0,pidl,aWStack_228,0x104), -1 < HVar4)) {
        pwVar5 = aWStack_228;
        uVar2 = FUN_405811d8((char *)pidl);
        if (CONCAT22(extraout_var_00,uVar2) == 0) {
          uVar6 = 0x4800;
        }
        else {
          pwVar5 = wcsrchr(aWStack_228,L'{');
          uVar6 = 0x4010;
        }
        iVar3 = SHGetFileInfo(pwVar5,0,&local_4e0,0x2b4,uVar6);
        if ((iVar3 != 0) && (iVar3 = FUN_4058150c((ushort *)pidl,&DAT_405719b0), iVar3 != 0)) {
          FUN_40586a28(DAT_405aa0d4,0);
          bVar1 = FUN_40584f40();
          if (CONCAT31(extraout_var,bVar1) == 0) {
            local_4dc = local_4dc + 1;
          }
          FUN_40583798(DAT_405aa0d4);
          *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xffffefff;
        }
        if ((local_4d8 & 0x10000) != 0) {
          *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
          *(undefined4 *)(param_2 + 0x1c) = 0xf00;
          *(undefined4 *)(param_2 + 0x18) = 0x100;
        }
      }
      *(int *)(param_2 + 0x28) = local_4dc;
    }
    if ((*(uint *)(param_2 + 0xc) & 1) != 0) {
      if (*(int *)(param_2 + 0x24) != 0) {
        **(undefined2 **)(param_2 + 0x20) = 0;
      }
      local_5f8[0] = (int *)0x0;
      iVar3 = (**(code **)**(undefined4 **)(param_1 + 0x68))
                        (*(undefined4 **)(param_1 + 0x68),&DAT_40572c18,local_5f8);
      if (-1 < iVar3) {
        memset(local_5f0 + 4,0,0x10c);
        local_5f0._0_4_ = SEXT24(*(short *)(param_1 + 0x4a));
        iVar3 = (**(code **)(*local_5f8[0] + 0xc))
                          (local_5f8[0],pidl,*(undefined4 *)(param_2 + 0x14),local_5f0);
        if (-1 < iVar3) {
          StrRetToBufW((STRRET *)(local_5f0 + 8),pidl,*(LPWSTR *)(param_2 + 0x20),
                       *(UINT *)(param_2 + 0x24));
        }
        (**(code **)(*local_5f8[0] + 8))();
      }
    }
  }
  FUN_405a7174(local_20);
  return;
}



/* 40596c74 FUN_40596c74 */

/* Boundary evidence: original MIPS .pdata 40596c74..405974e7. Semantic name remains unreviewed. */

undefined4 FUN_40596c74(int *param_1,uint param_2)

{
  int iVar1;
  WPARAM wParam;
  HMENU hMenu;
  HMENU pHVar2;
  HWND hWnd;
  uint uVar3;
  BOOL BVar4;
  HRESULT HVar5;
  int *piVar6;
  tagPOINT *ptVar7;
  LONG LVar8;
  code *pcVar9;
  int iVar10;
  char cVar11;
  undefined4 uVar12;
  HWND local_288 [2];
  tagPOINT local_280;
  int local_278;
  uint local_274;
  tagPOINT *local_270;
  tagMENUITEMINFOW local_258;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  uVar12 = 0;
  if (0x1042 < param_2) {
    if (0x104a < param_2) {
      if (param_2 == 0x1050) {
LAB_405974ac:
        if ((undefined4 *)param_1[0x11] != (undefined4 *)0x0) {
          FUN_405a42c4((undefined4 *)param_1[0x11]);
        }
      }
      else {
        if (param_2 == 0x1060) {
          local_288[0] = (HWND)0x0;
          if ((param_1[0x1b] != 0) &&
             (HVar5 = SHGetSpecialFolderLocation(*(HWND *)param_1[0x11],5,(LPITEMIDLIST *)local_288)
             , -1 < HVar5)) {
            (**(code **)(*(int *)param_1[0x1b] + 0x2c))((int *)param_1[0x1b],local_288[0],0);
            FUN_40580ef4(local_288[0]);
          }
          goto LAB_405974c0;
        }
        if (param_2 == 0x1061) {
          param_1 = (int *)param_1[0x1b];
          if (param_1 == (int *)0x0) goto LAB_405974c0;
          iVar1 = 0x2000;
          pcVar9 = *(code **)(*param_1 + 0x2c);
          iVar10 = 0;
        }
        else {
          if (param_2 == 0x4014) {
            CreateProcessW(L"\\windows\\peghelp.exe",L"wince.htm#Windows_Explorer_Help",
                           (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,
                           (LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
LAB_40597428:
            uVar12 = 1;
            goto LAB_405974c0;
          }
          if (param_2 == 0x4015) {
            ptVar7 = (tagPOINT *)0x16;
            goto LAB_4059700c;
          }
          if (param_2 == 0x4016) goto LAB_405974ac;
          if (param_2 != 0x4017) goto LAB_40597318;
          iVar1 = FUN_405a3dc8((undefined4 *)param_1[0x11]);
          iVar10 = (int)(short)iVar1;
          iVar1 = iVar1 >> 0x10;
          pcVar9 = *(code **)(*param_1 + 0x50);
        }
        (*pcVar9)(param_1,iVar10,iVar1);
      }
      goto LAB_405974c0;
    }
    if (param_2 == 0x104a) {
      if (param_1[0x17] == 2) goto LAB_405974c0;
      iVar1 = 2;
      goto LAB_4059705c;
    }
    if (param_2 == 0x1043) {
      uVar3 = FUN_405a43e0((undefined4 *)param_1[0x11]);
      FUN_405a4b00((undefined4 *)param_1[0x11],(uint)(uVar3 == 0));
      goto LAB_405974c0;
    }
    if (param_2 == 0x1044) {
      cVar11 = '\x03';
LAB_40597230:
      if ((char)param_1[0x12] == cVar11) {
        param_1[0x15] = param_1[0x15] ^ 0x10;
      }
      else {
        uVar3 = param_1[0x15];
        *(char *)(param_1 + 0x12) = cVar11;
LAB_40597260:
        param_1[0x15] = uVar3 & 0xffffffef;
      }
    }
    else {
      if (param_2 != 0x1045) {
        if (param_2 == 0x1046) {
          cVar11 = '\x01';
        }
        else {
          if (param_2 != 0x1047) {
            if (param_2 == 0x1048) {
              FUN_40588b4c();
              goto LAB_405974c0;
            }
            if (param_2 == 0x1049) {
              piVar6 = (int *)param_1[0x1c];
              if ((piVar6 != (int *)0x0) &&
                 (iVar1 = (**(code **)(*piVar6 + 0x34))(piVar6,2,local_288), iVar1 == 0)) {
                wParam = SendMessageW(local_288[0],0x419,0x1049,0);
                SendMessageW(local_288[0],0x41d,wParam,(LPARAM)&local_280);
                MapWindowPoints(local_288[0],(HWND)0x0,&local_280,2);
                hMenu = LoadMenuW(DAT_405aa0c0,(LPCWSTR)0x4001);
                pHVar2 = GetSubMenu(hMenu,0);
                pHVar2 = GetSubMenu(pHVar2,0);
                hWnd = GetParent((HWND)param_1[10]);
                uVar3 = GetWindowLongW(hWnd,-0x14);
                LVar8 = local_278;
                if ((uVar3 & 0x400000) == 0) {
                  LVar8 = local_280.x;
                }
                TrackPopupMenuEx(pHVar2,0,LVar8,local_274,(HWND)param_1[10],(LPTPMPARAMS)0x0);
                DestroyMenu(hMenu);
              }
              goto LAB_405974c0;
            }
LAB_40597318:
            if ((param_2 < 0x1100) || (0x1199 < param_2)) goto LAB_40597428;
            memset(&local_258.fMask,0,0x28);
            local_258.cbSize = 0x2c;
            local_258.fMask = 0x20;
            BVar4 = GetMenuItemInfoW((HMENU)param_1[0xc],0,1,&local_258);
            if ((BVar4 == 0) || ((int *)local_258.dwItemData == (int *)0x0)) goto LAB_405974c0;
            memset(&local_280.y,0,0x20);
            local_278 = param_1[10];
            local_274 = param_2 & 0xffff;
            local_280.x = 0x24;
            ptVar7 = &local_280;
            pcVar9 = *(code **)(*(int *)local_258.dwItemData + 0x10);
            param_1 = (int *)local_258.dwItemData;
            goto LAB_40597018;
          }
          cVar11 = '\x02';
        }
        goto LAB_40597230;
      }
      if ((char)param_1[0x12] != '\0') {
        uVar3 = param_1[0x15];
        *(undefined1 *)(param_1 + 0x12) = 0;
        goto LAB_40597260;
      }
      param_1[0x15] = param_1[0x15] ^ 0x10;
    }
    if ((undefined4 *)param_1[0x11] != (undefined4 *)0x0) {
      FUN_405a4a88((undefined4 *)param_1[0x11],0x405958d8,(WPARAM)param_1);
    }
    goto LAB_405974c0;
  }
  if (param_2 == 0x1042) {
    if (param_1[0x17] == 4) goto LAB_405974c0;
    iVar1 = 4;
LAB_4059705c:
    iVar1 = FUN_405a4924((undefined4 *)param_1[0x11],iVar1);
    param_1[0x17] = iVar1;
    if ((param_1[0x15] & 0x20U) != 0) {
      FUN_40588638(iVar1);
    }
    goto LAB_405974c0;
  }
  if (param_2 < 0x1021) {
    if (param_2 == 0x1020) {
      ptVar7 = (tagPOINT *)0xf;
      goto LAB_4059700c;
    }
    if (param_2 == 0x1000) {
      ptVar7 = (tagPOINT *)0x1;
      goto LAB_4059700c;
    }
    if (param_2 == 0x1001) {
      SetFocus(*(HWND *)param_1[0x11]);
      pcVar9 = *(code **)(*param_1 + 0x58);
LAB_40596ed4:
      (*pcVar9)(param_1);
      goto LAB_405974c0;
    }
    if (param_2 == 0x1002) {
      iVar1 = (**(code **)(*param_1 + 0x88))(param_1);
      if (iVar1 != 0) goto LAB_405974c0;
      FUN_405a0a00(&local_280.x);
      local_270 = (tagPOINT *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)&local_274);
      if (local_270 == (tagPOINT *)0x0) goto LAB_405974c0;
      local_288[0] = (HWND)0x20;
      iVar1 = (**(code **)(*(int *)param_1[0x1a] + 0x24))
                        ((int *)param_1[0x1a],local_274,local_270,local_288);
      if ((-1 < iVar1) && (((uint)local_288[0] & 0x20) != 0)) {
        local_280.y = *(LONG *)param_1[0x11];
        local_278 = param_1[9];
        FUN_405a2004(&local_280.x,3,(STRSAFE_PCNZWCH)0x0);
        DAT_405a995c = 0x3109;
      }
    }
    else {
      if (param_2 == 0x1003) {
        FUN_405a47a4((undefined4 *)param_1[0x11]);
        goto LAB_405974c0;
      }
      if (param_2 == 0x1004) {
        iVar1 = (**(code **)(*param_1 + 0x88))(param_1);
        if (iVar1 != 0) goto LAB_405974c0;
        pcVar9 = *(code **)(*param_1 + 0x5c);
        goto LAB_40596ed4;
      }
      if (param_2 == 0x1005) {
        iVar1 = SHGetSpecialFolderPath(*(undefined4 *)param_1[0x11],awStack_228,0x10,1);
        if (iVar1 == 0) goto LAB_405974c0;
        FUN_405a0a00(&local_280.x);
        local_270 = (tagPOINT *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)&local_274);
        if (local_270 == (tagPOINT *)0x0) goto LAB_405974c0;
        iVar1 = 2;
      }
      else {
        if (param_2 != 0x1006) goto LAB_40597318;
        iVar1 = SHGetSpecialFolderPath(*(undefined4 *)param_1[0x11],awStack_228,5,1);
        if (iVar1 == 0) goto LAB_405974c0;
        FUN_405a0a00(&local_280.x);
        local_270 = (tagPOINT *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)&local_274);
        if (local_270 == (tagPOINT *)0x0) goto LAB_405974c0;
        iVar1 = 0;
      }
      local_280.y = *(LONG *)param_1[0x11];
      local_278 = param_1[9];
      FUN_405a2004(&local_280.x,iVar1,awStack_228);
    }
    pcVar9 = *(code **)(*DAT_405aa0c8 + 0x14);
    param_1 = DAT_405aa0c8;
    ptVar7 = local_270;
  }
  else {
    if (param_2 == 0x1021) {
      iVar1 = (**(code **)(*param_1 + 0x88))(param_1);
      if (iVar1 != 0) goto LAB_405974c0;
      ptVar7 = (tagPOINT *)0xb;
    }
    else if (param_2 == 0x1022) {
      iVar1 = (**(code **)(*param_1 + 0x88))(param_1);
      if (iVar1 != 0) goto LAB_405974c0;
      ptVar7 = (tagPOINT *)0xc;
    }
    else {
      if (param_2 != 0x1023) {
        if (param_2 == 0x1024) {
          iVar1 = (**(code **)(*param_1 + 0x88))(param_1);
          if (iVar1 == 0) {
            FUN_405a23e8(*(undefined4 *)param_1[0x11],(LPCITEMIDLIST)param_1[9],1);
            DAT_405a995c = 0x3107;
          }
          goto LAB_405974c0;
        }
        if (param_2 == 0x1025) {
          SetFocus(*(HWND *)param_1[0x11]);
          FUN_405a4824((undefined4 *)param_1[0x11]);
          goto LAB_405974c0;
        }
        if (param_2 == 0x1040) {
          if (param_1[0x17] == 1) goto LAB_405974c0;
          iVar1 = 1;
        }
        else {
          if (param_2 != 0x1041) goto LAB_40597318;
          if (param_1[0x17] == 3) goto LAB_405974c0;
          iVar1 = 3;
        }
        goto LAB_4059705c;
      }
      iVar1 = (**(code **)(*param_1 + 0x88))(param_1);
      if (iVar1 != 0) goto LAB_405974c0;
      ptVar7 = (tagPOINT *)0xd;
    }
LAB_4059700c:
    pcVar9 = *(code **)(*param_1 + 0x8c);
  }
LAB_40597018:
  (*pcVar9)(param_1,ptVar7);
LAB_405974c0:
  FUN_405a7174(local_20);
  return uVar12;
}



/* 405974e8 FUN_405974e8 */

/* Boundary evidence: original MIPS .pdata 405974e8..405977e3. Semantic name remains unreviewed. */

undefined4 FUN_405974e8(int *param_1,HMENU param_2,int *param_3)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  UINT UVar5;
  UINT UVar6;
  UINT uEnable;
  UINT uEnable_00;
  UINT uEnable_01;
  uint local_60;
  uint local_5c;
  tagMENUITEMINFOW local_58;
  
  if (param_3 == (int *)0x0) {
    local_58.cbSize = 0x2c;
    local_58.fMask = 2;
    (**(code **)(*param_1 + 0xa4))(param_1,param_2);
    UVar6 = 0;
    BVar1 = GetMenuItemInfoW(param_2,0,1,&local_58);
    if (BVar1 != 0) {
      do {
        local_60 = local_58.wID;
        (**(code **)(param_1[1] + 0xc))(param_1 + 1,&DAT_40571a20,1,&local_60,0);
        if ((local_5c & 2) == 0) {
          if ((local_5c & 1) != 0) {
            EnableMenuItem(param_2,local_60,1);
          }
        }
        else {
          UVar5 = 0;
          if ((local_5c & 4) != 0) {
            UVar5 = 8;
          }
          EnableMenuItem(param_2,local_60,0);
          CheckMenuItem(param_2,local_60,UVar5);
        }
        UVar6 = UVar6 + 1;
        BVar1 = GetMenuItemInfoW(param_2,UVar6,1,&local_58);
      } while (BVar1 != 0);
    }
  }
  else {
    piVar4 = (int *)param_3[4];
    UVar6 = 1;
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0xc))(piVar4,param_2,1,0x1100,0x1199,0);
    }
    if (*param_3 == 0) {
      iVar2 = FUN_405a16ac();
      uVar3 = FUN_405a1574();
      UVar6 = (UINT)((uVar3 & 2) == 0);
      EnableMenuItem(param_2,0x1023,(uint)(iVar2 == 0));
      UVar5 = 0x1024;
    }
    else {
      if (*param_3 != 1) {
        return 1;
      }
      local_60 = 0x33;
      UVar5 = 0;
      iVar2 = (**(code **)(*(int *)param_1[0x1a] + 0x24))
                        ((int *)param_1[0x1a],param_3[2],param_3[3],&local_60);
      if (iVar2 < 0) {
        UVar5 = 1;
        uEnable_01 = 1;
        uEnable_00 = 1;
        uEnable = 1;
      }
      else {
        uEnable_01 = (UINT)((local_60 & 2) == 0);
        uEnable_00 = (UINT)((local_60 & 1) == 0);
        uEnable = (UINT)((local_60 & 0x20) == 0);
        if (((uint)param_3[2] < 2) && ((local_60 & 0x10) != 0)) {
          UVar6 = 0;
        }
      }
      EnableMenuItem(param_2,0x1000,UVar5);
      EnableMenuItem(param_2,0x1021,uEnable_01);
      EnableMenuItem(param_2,0x1022,uEnable_00);
      EnableMenuItem(param_2,0x1002,uEnable);
      UVar5 = 0x1003;
    }
    EnableMenuItem(param_2,UVar5,UVar6);
  }
  return 0;
}



/* 405977e4 FUN_405977e4 */

/* Boundary evidence: original MIPS .pdata 405977e4..40597867. Semantic name remains unreviewed. */

void FUN_405977e4(int param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD DVar3;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    DVar1 = GetSysColor(0x40000005);
    DVar2 = GetSysColor(0x40000008);
    DVar3 = GetSysColor(0x40000005);
    FUN_405a4888(*(undefined4 **)(param_1 + 0x44),DVar3,DVar2,DVar1);
  }
  return;
}



/* 40597868 FUN_40597868 */

/* Boundary evidence: original MIPS .pdata 40597868..4059798f. Semantic name remains unreviewed. */

void FUN_40597868(int param_1)

{
  int iVar1;
  short *psVar2;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    psVar2 = (short *)&DAT_405a9960;
    if (*(short **)(param_1 + 0x40) != (short *)0x0) {
      psVar2 = *(short **)(param_1 + 0x40);
    }
    iVar1 = LoadStringW(DAT_405aa0c0,0x301f,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      FUN_405a34cc(*(undefined4 **)(param_1 + 0x44),iVar1,(int)*psVar2,0);
    }
    iVar1 = LoadStringW(DAT_405aa0c0,0x3020,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      FUN_405a34cc(*(undefined4 **)(param_1 + 0x44),iVar1,(int)psVar2[1],1);
    }
    iVar1 = LoadStringW(DAT_405aa0c0,0x3021,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      FUN_405a34cc(*(undefined4 **)(param_1 + 0x44),iVar1,(int)psVar2[2],0);
    }
    iVar1 = LoadStringW(DAT_405aa0c0,0x3022,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      FUN_405a34cc(*(undefined4 **)(param_1 + 0x44),iVar1,(int)psVar2[3],0);
    }
  }
  return;
}



/* 40597990 FUN_40597990 */

/* Boundary evidence: original MIPS .pdata 40597990..405979b3. Semantic name remains unreviewed. */

void FUN_40597990(void)

{
  LoadMenuW(DAT_405aa0c0,(LPCWSTR)0x4001);
  return;
}



/* 405979b4 FUN_405979b4 */

/* Boundary evidence: original MIPS .pdata 405979b4..40597a3b. Semantic name remains unreviewed. */

undefined4 FUN_405979b4(undefined4 param_1,HMENU param_2,UINT *param_3,int param_4)

{
  LPCWSTR lpNewItem;
  
  if (0 < param_4) {
    do {
      lpNewItem = (LPCWSTR)LoadStringW(DAT_405aa0c0,param_3[3],(LPWSTR)0x0,0);
      InsertMenuW(param_2,*param_3,param_3[1],param_3[2],lpNewItem);
      param_4 = param_4 + -1;
      param_3 = param_3 + 4;
    } while (param_4 != 0);
  }
  return 1;
}



/* 40597a3c FUN_40597a3c */

/* Boundary evidence: original MIPS .pdata 40597a3c..40597a6b. Semantic name remains unreviewed. */

bool FUN_40597a3c(int param_1)

{
  bool bVar1;
  
  bVar1 = (*(uint *)(param_1 + 0x54) & 1) != 0;
  if (bVar1) {
    MessageBeep(0xffffffff);
  }
  return bVar1;
}



/* 40597a6c FUN_40597a6c */

/* Boundary evidence: original MIPS .pdata 40597a6c..40597e43. Semantic name remains unreviewed. */

undefined4 FUN_40597a6c(int *param_1,int param_2)

{
  undefined1 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  undefined3 extraout_var_00;
  undefined4 *puVar4;
  int iVar5;
  HANDLE pvVar6;
  HRESULT HVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  uint local_388;
  uint local_384;
  undefined1 auStack_380 [4];
  undefined1 auStack_37c [4];
  undefined1 auStack_378 [8];
  WCHAR *local_370;
  undefined1 auStack_364 [36];
  STRRET local_340;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  uVar11 = 0;
  if (param_2 == 1) {
    local_388 = 0;
    puVar4 = (undefined4 *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)&local_388);
    if (puVar4 == (undefined4 *)0x0) goto LAB_40597e0c;
    memset(auStack_37c,0,0x38);
    local_340.uType = 0;
    memset(&local_340.u,0,0x104);
    uVar8 = param_1[10];
    puVar1 = auStack_380 + 3;
    uVar3 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar3) =
         *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0x3cU >> (3 - uVar3) * 8;
    puVar1 = auStack_378 + 3;
    uVar3 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar3) =
         *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | uVar8 >> (3 - uVar3) * 8;
    puVar1 = auStack_364 + 3;
    uVar3 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar3) =
         *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 1U >> (3 - uVar3) * 8;
    bVar2 = false;
    uVar3 = 0;
    auStack_380 = (undefined1  [4])0x3c;
    auStack_364._0_4_ = 1;
    puVar10 = puVar4;
    auStack_378._0_4_ = uVar8;
    if (local_388 != 0) {
      do {
        local_384 = 0x28000000;
        (**(code **)(*(int *)param_1[0x1a] + 0x24))((int *)param_1[0x1a],1,puVar10,&local_384);
        if ((local_384 & 0x28000000) == 0) {
          (**(code **)(*(int *)param_1[0x1a] + 0x2c))
                    ((int *)param_1[0x1a],*puVar10,0x8000,&local_340);
          HVar7 = StrRetToBufW(&local_340,(LPCITEMIDLIST)*puVar10,aWStack_238,0x104);
          if (-1 < HVar7) {
            local_370 = aWStack_238;
            ShellExecuteEx(auStack_380);
          }
        }
        else if (!bVar2) {
          (**(code **)(*(int *)param_1[0x1b] + 0x2c))((int *)param_1[0x1b],*puVar10,0x1000);
          bVar2 = true;
        }
        uVar3 = uVar3 + 1;
        puVar10 = puVar10 + 1;
      } while (uVar3 < local_388);
    }
  }
  else if (param_2 == 0xb) {
    local_388 = 0;
    puVar4 = (undefined4 *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)&local_388);
    if (puVar4 == (undefined4 *)0x0) goto LAB_40597e0c;
    local_384 = 2;
    iVar5 = (**(code **)(*(int *)param_1[0x1a] + 0x24))
                      ((int *)param_1[0x1a],local_388,puVar4,&local_384);
    if (((-1 < iVar5) && ((local_384 & 2) != 0)) &&
       (pvVar6 = FUN_405a2350(*(undefined4 *)param_1[0x11],(int *)param_1[0x1a],local_388,
                              (int)puVar4), pvVar6 != (HANDLE)0x0)) {
      FUN_405a49cc((undefined4 *)param_1[0x11]);
    }
  }
  else {
    if (param_2 != 0xc) {
      if (param_2 == 0xd) {
        uVar3 = FUN_405a1574();
        if ((uVar3 & 2) == 0) {
          uVar9 = 0x310b;
          if ((uVar3 & 4) == 0) {
            uVar9 = 0x3083;
          }
        }
        else {
          uVar9 = 0x310a;
        }
        bVar2 = FUN_405a23e8(*(undefined4 *)param_1[0x11],(LPCITEMIDLIST)param_1[9],0);
        if (CONCAT31(extraout_var_00,bVar2) != 0) {
          DAT_405a995c = uVar9;
        }
      }
      else if (param_2 == 0xf) {
        if ((DAT_405aa0d0 != (int *)0x0) &&
           (bVar2 = FUN_40582f98(DAT_405aa0d0), CONCAT31(extraout_var,bVar2) != 0)) {
          FUN_405830e8(DAT_405aa0d0,(HWND)param_1[10]);
        }
        DAT_405a995c = 0x3107;
      }
      else if (param_2 == 0x16) {
        FUN_40588820();
        (**(code **)(*param_1 + 0x20))(param_1);
      }
      else {
        uVar11 = 0x80040100;
      }
      goto LAB_40597e0c;
    }
    local_388 = 0;
    puVar4 = (undefined4 *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)&local_388);
    if (puVar4 == (undefined4 *)0x0) goto LAB_40597e0c;
    local_384 = 1;
    iVar5 = (**(code **)(*(int *)param_1[0x1a] + 0x24))
                      ((int *)param_1[0x1a],local_388,puVar4,&local_384);
    if ((-1 < iVar5) && ((local_384 & 1) != 0)) {
      FUN_405a238c(*(undefined4 *)param_1[0x11],(int *)param_1[0x1a],local_388,(int)puVar4);
    }
  }
  (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,puVar4);
LAB_40597e0c:
  FUN_405a7174(local_30);
  return uVar11;
}



/* 40597e44 FUN_40597e44 */

/* Boundary evidence: original MIPS .pdata 40597e44..40597e6b. Semantic name remains unreviewed. */

void FUN_40597e44(int param_1,int param_2,int param_3)

{
  if (*(undefined4 **)(param_1 + 0x44) != (undefined4 *)0x0) {
    FUN_405a4770(*(undefined4 **)(param_1 + 0x44),param_2,param_3);
  }
  return;
}



/* 40597e6c FUN_40597e6c */

/* Boundary evidence: original MIPS .pdata 40597e6c..405982b3. Semantic name remains unreviewed. */

undefined4 FUN_40597e6c(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  BOOL BVar4;
  HMENU pHVar5;
  HMENU pHVar6;
  HMENU pHVar7;
  LPCWSTR pWVar8;
  HMENU hMenu;
  int *piVar9;
  undefined4 uVar10;
  HWND local_60 [2];
  tagMENUITEMINFOW local_58;
  
  piVar9 = (int *)param_1[0x1c];
  if (piVar9 == (int *)0x0) {
    uVar10 = 0;
  }
  else {
    uVar10 = 1;
    if (param_1[0x14] != 0) {
      if (param_1[0xc] != 0) {
        iVar2 = (**(code **)(*piVar9 + 0x34))(piVar9,2,local_60);
        if (-1 < iVar2) {
          uVar3 = SendMessageW(local_60[0],0x412,0x8150,0);
          if ((uVar3 & 4) == 0) {
            param_1[0x15] = param_1[0x15] & 0xfffffffb;
          }
          else {
            param_1[0x15] = param_1[0x15] | 4;
          }
          uVar3 = SendMessageW(local_60[0],0x412,0x8151,0);
          if ((uVar3 & 4) == 0) {
            param_1[0x15] = param_1[0x15] & 0xfffffff7;
          }
          else {
            param_1[0x15] = param_1[0x15] | 8;
          }
        }
        memset(&local_58.fMask,0,0x28);
        local_58.cbSize = 0x2c;
        local_58.fMask = 0x20;
        BVar4 = GetMenuItemInfoW((HMENU)param_1[0xc],0,1,&local_58);
        if ((BVar4 != 0) && ((int *)local_58.dwItemData != (int *)0x0)) {
          (**(code **)(*(int *)local_58.dwItemData + 8))();
        }
        (**(code **)(*(int *)param_1[0x1c] + 0x1c))((int *)param_1[0x1c],param_1[0xc]);
        param_1[0xc] = 0;
      }
      param_1[0x14] = 0;
    }
    if (param_2 != 0) {
      pHVar5 = CreateMenu();
      param_1[0xc] = (int)pHVar5;
      if (pHVar5 != (HMENU)0x0) {
        bVar1 = param_2 == 2;
        local_58.cbSize = 0;
        local_58.fMask = 0;
        local_58.fType = 0;
        local_58.fState = 0;
        local_58.wID = 0;
        local_58.hSubMenu = (HMENU)0x0;
        (**(code **)(*(int *)param_1[0x1c] + 0x14))((int *)param_1[0x1c],pHVar5,&local_58);
        pHVar5 = GetSubMenu((HMENU)param_1[0xc],0);
        if (pHVar5 != (HMENU)0x0) {
          (**(code **)(*param_1 + 0x84))(param_1,pHVar5,&DAT_40572104,8,bVar1);
          pHVar6 = LoadMenuW(DAT_405aa0c0,(LPCWSTR)0x4002);
          pHVar7 = GetSubMenu(pHVar6,0);
          RemoveMenu(pHVar6,0,0x400);
          DestroyMenu(pHVar6);
          pWVar8 = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x3105,(LPWSTR)0x0,0);
          BVar4 = InsertMenuW(pHVar5,7,0x410,(UINT_PTR)pHVar7,pWVar8);
          if (BVar4 == 0) {
            DestroyMenu(pHVar7);
          }
        }
        pHVar5 = GetSubMenu((HMENU)param_1[0xc],1);
        if (pHVar5 != (HMENU)0x0) {
          param_1[0x18] = DAT_405a995c;
          pWVar8 = (LPCWSTR)LoadStringW(DAT_405aa0c0,DAT_405a995c,(LPWSTR)0x0,0);
          InsertMenuW(pHVar5,0,0x400,0x1020,pWVar8);
          (**(code **)(*param_1 + 0x84))(param_1,pHVar5,&DAT_40572184,7,bVar1);
        }
        pHVar5 = GetSubMenu((HMENU)param_1[0xc],2);
        if (pHVar5 != (HMENU)0x0) {
          (**(code **)(*param_1 + 0x84))(param_1,pHVar5,&DAT_405721f4,6,bVar1);
          pHVar6 = LoadMenuW(DAT_405aa0c0,(LPCWSTR)0x4001);
          pHVar7 = GetSubMenu(pHVar6,0);
          hMenu = GetSubMenu(pHVar7,2);
          RemoveMenu(pHVar7,2,0x400);
          DestroyMenu(pHVar6);
          pWVar8 = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x3114,(LPWSTR)0x0,0);
          BVar4 = InsertMenuW(pHVar5,4,0x410,(UINT_PTR)hMenu,pWVar8);
          if (BVar4 == 0) {
            DestroyMenu(hMenu);
          }
        }
        pHVar5 = GetSubMenu((HMENU)param_1[0xc],3);
        if (pHVar5 != (HMENU)0x0) {
          (**(code **)(*param_1 + 0x84))(param_1,pHVar5,&UNK_40572254,2,bVar1);
        }
        (**(code **)(*(int *)param_1[0x1c] + 0x18))((int *)param_1[0x1c],param_1[0xc],0,param_1[10])
        ;
      }
      (**(code **)(*param_1 + 0x98))(param_1,param_2);
    }
  }
  return uVar10;
}



/* 405982b4 FUN_405982b4 */

/* Boundary evidence: original MIPS .pdata 405982b4..405983f3. Semantic name remains unreviewed. */

undefined4 FUN_405982b4(int param_1)

{
  undefined4 uVar1;
  HWND hWnd;
  uint uVar2;
  int iVar3;
  int iVar4;
  HWND local_20 [2];
  
  if (*(int *)(param_1 + 0x70) != 0) {
    DAT_405a9984 = 4;
    DAT_405a9970 = 4;
    if ((*(uint *)(param_1 + 0x54) & 4) == 0) {
      DAT_405a9970 = 0;
    }
    if ((*(uint *)(param_1 + 0x54) & 8) == 0) {
      DAT_405a9984 = 0;
    }
    hWnd = GetParent(*(HWND *)(param_1 + 0x28));
    uVar2 = GetWindowLongW(hWnd,-0x14);
    uVar1 = DAT_405a9968;
    if ((uVar2 & 0x400000) != 0) {
      DAT_405a9968 = DAT_405a997c;
      DAT_405a997c = uVar1;
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x70) + 0x44))
                      (*(int **)(param_1 + 0x70),&DAT_405a9968,9,1);
    iVar4 = (**(code **)(**(int **)(param_1 + 0x70) + 0x34))(*(int **)(param_1 + 0x70),2,local_20);
    if (-1 < iVar4) {
      SendMessageW(local_20[0],0x451,6,0x405aa308);
    }
    uVar1 = DAT_405a9968;
    if ((uVar2 & 0x400000) != 0) {
      DAT_405a9968 = DAT_405a997c;
      DAT_405a997c = uVar1;
    }
    if (-1 < iVar3) {
      return 1;
    }
  }
  return 0;
}



/* 405983f4 FUN_405983f4 */

/* Boundary evidence: original MIPS .pdata 405983f4..405985df. Semantic name remains unreviewed. */

void FUN_405983f4(int param_1,undefined4 param_2,LONG param_3,LONG param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  int *local_28;
  int *local_24;
  LPCITEMIDLIST local_20;
  int local_1c;
  
  local_1c = FUN_405a3fdc(*(int **)(param_1 + 0x44),param_3,param_4);
  local_28 = (int *)0x0;
  if (local_1c == 0) {
    local_24 = (int *)0x0;
    local_20 = (LPCITEMIDLIST)0x0;
    *(undefined4 *)(*(int *)(param_1 + 100) + 0x14) = 0;
    iVar1 = SHBindToParent(*(LPCITEMIDLIST *)(param_1 + 0x24),(IID *)&DAT_40572b68,&local_24,
                           &local_20);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_24 + 0x28))
                        (local_24,**(undefined4 **)(param_1 + 0x44),1,&local_20,&DAT_40572b48,0,
                         &local_28);
      (**(code **)(*local_24 + 8))();
      FUN_40580ef4(local_20);
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 100) + 0x14) = 1;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x68) + 0x28))
                      (*(int **)(param_1 + 0x68),**(undefined4 **)(param_1 + 0x44),1,&local_1c,
                       &DAT_40572b48,0,&local_28);
  }
  if (*(int *)(*(int *)(param_1 + 100) + 4) != 0) {
    (**(code **)(**(int **)(*(int *)(param_1 + 100) + 4) + 0x14))();
    (**(code **)(**(int **)(*(int *)(param_1 + 100) + 4) + 8))();
  }
  if (iVar1 < 0) {
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))();
    }
    *(undefined4 *)(*(int *)(param_1 + 100) + 4) = 0;
    *param_5 = 0;
  }
  else {
    *(int **)(*(int *)(param_1 + 100) + 4) = local_28;
    piVar2 = *(int **)(*(int *)(param_1 + 100) + 4);
    (**(code **)(*piVar2 + 0xc))
              (piVar2,*(undefined4 *)(*(int *)(param_1 + 100) + 8),param_2,param_3,param_4,param_5);
  }
  return;
}



/* 405985e0 FUN_405985e0 */

/* Boundary evidence: original MIPS .pdata 405985e0..405989d7. Semantic name remains unreviewed. */

void FUN_405985e0(int *param_1,undefined4 *param_2,LRESULT param_3,int param_4)

{
  BOOL BVar1;
  STRSAFE_LPCWSTR pszSrc;
  UINT UVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  LRESULT local_res8 [2];
  size_t local_380;
  wchar_t *local_37c;
  int local_378 [2];
  undefined1 auStack_370 [12];
  undefined4 local_364;
  int local_360;
  undefined4 local_35c;
  undefined1 *local_350;
  undefined4 local_34c;
  int local_344;
  wchar_t local_338 [128];
  wchar_t awStack_238 [2];
  undefined1 auStack_234 [516];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  piVar3 = (int *)param_1[0x1c];
  local_res8[0] = param_3;
  if (piVar3 == (int *)0x0) goto LAB_405989a0;
  (**(code **)(*piVar3 + 4))(piVar3);
  uVar7 = DAT_405aa328;
  uVar8 = DAT_405aa324;
  if (param_4 != 0) {
    local_380 = 0;
    (**(code **)(*piVar3 + 0x38))(piVar3,1,0x406,0,0,&local_380);
    iVar5 = 0;
    if (0 < (int)local_380) {
      do {
        (**(code **)(*piVar3 + 0x38))(piVar3,1,0x40b,iVar5,&DAT_4057112c,0);
        (**(code **)(*piVar3 + 0x38))(piVar3,1,0x40f,iVar5,0,0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)local_380);
    }
    iVar5 = SHGetPathFromIDList((LPCITEMIDLIST)param_1[9],awStack_238);
    if ((iVar5 != 0) && (BVar1 = PathMatchSpecW(awStack_238,L"\\\\*"), BVar1 != 0)) {
      uVar7 = 0;
      uVar8 = 0;
    }
    (**(code **)(*piVar3 + 0x38))(piVar3,1,0x40b,4,uVar8,0);
    (**(code **)(*piVar3 + 0x38))(piVar3,1,0x40f,4,uVar7,0);
  }
  puVar4 = (undefined4 *)0x0;
  if (param_2 == (undefined4 *)0x0) {
    param_2 = (undefined4 *)FUN_405a4104((undefined4 *)param_1[0x11],local_res8);
    puVar4 = param_2;
  }
  if (local_res8[0] == 0) {
    local_res8[0] = SendMessageW(*(HWND *)param_1[0x11],0x1004,0,0);
    UVar2 = 0x3088;
LAB_40598938:
    FUN_405897d8(local_res8[0],UVar2,local_338,0x80);
  }
  else {
    if (local_res8[0] != 1) {
LAB_40598910:
      UVar2 = 0x3089;
      goto LAB_40598938;
    }
    local_378[0] = 0x60000000;
    iVar5 = (**(code **)(*(int *)param_1[0x1a] + 0x24))((int *)param_1[0x1a],1,param_2,local_378);
    if ((iVar5 < 0) || (local_378[0] != 0x40000000)) goto LAB_40598910;
    wcscpy(awStack_238,L": ");
    local_37c = local_338;
    local_380 = 0x80;
    local_360 = FUN_405a3ce0((undefined4 *)param_1[0x11],(char *)*param_2);
    local_344 = FUN_405a3ed0((undefined4 *)param_1[0x11],local_360);
    if (local_344 == 0) goto LAB_40598910;
    local_350 = auStack_234;
    puVar6 = &DAT_405a9a1c;
    local_364 = 1;
    local_34c = 0x102;
    do {
      pszSrc = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,puVar6[1],(LPWSTR)0x0,0);
      StringCchCopyExW(local_37c,local_380,pszSrc,&local_37c,&local_380,0x800);
      local_35c = *puVar6;
      (**(code **)(*param_1 + 0x60))(param_1,auStack_370);
      StringCchCopyExW(local_37c,local_380,awStack_238,&local_37c,&local_380,0x800);
      if (local_380 != 0) {
        *local_37c = L' ';
        local_37c = local_37c + 1;
        local_380 = local_380 - 1;
      }
      puVar6 = puVar6 + 2;
    } while ((int)puVar6 < 0x405a9a34);
    local_37c[-1] = L'\0';
  }
  (**(code **)(*piVar3 + 0x38))(piVar3,1,0x40b,0,local_338,0);
  (**(code **)(*piVar3 + 8))(piVar3);
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,puVar4);
  }
LAB_405989a0:
  FUN_405a7174(local_30);
  return;
}



/* 405989d8 FUN_405989d8 */

/* Boundary evidence: original MIPS .pdata 405989d8..40598a9b. Semantic name remains unreviewed. */

void FUN_405989d8(int param_1,HMENU param_2)

{
  int iVar1;
  BOOL BVar2;
  MENUITEMINFOW local_250;
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  if ((DAT_405a995c != *(UINT *)(param_1 + 0x60)) &&
     (iVar1 = LoadStringW(DAT_405aa0c0,DAT_405a995c,aWStack_220,0x104), iVar1 != 0)) {
    local_250.dwTypeData = aWStack_220;
    local_250.cbSize = 0x2c;
    local_250.fMask = 0x10;
    local_250.fType = 0;
    local_250.cch = wcslen(aWStack_220);
    BVar2 = SetMenuItemInfoW(param_2,0x1020,0,&local_250);
    if (BVar2 != 0) {
      *(UINT *)(param_1 + 0x60) = DAT_405a995c;
    }
  }
  FUN_405a7174(local_18);
  return;
}



/* 40598a9c FUN_40598a9c */

/* Boundary evidence: original MIPS .pdata 40598a9c..40598de3. Semantic name remains unreviewed. */

undefined4 FUN_40598a9c(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = *param_2;
    if ((((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
         (param_2[3] == 0x46000000)) ||
        (((iVar2 == 0x114 && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) ||
       (((iVar2 == 0x214e3 && (param_2[1] == 0)) &&
        ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    else {
      if ((((iVar2 == -0x48dd4335) && (param_2[1] == 0x101b4e68)) && (param_2[2] == -0x55ff435e)) &&
         (param_2[3] == 0x70474000)) {
        iVar2 = param_1 + 4;
      }
      else if (((iVar2 == 0x117) && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))) {
        iVar2 = param_1 + 8;
      }
      else if (((iVar2 == -0x27d41d4f) && (param_2[1] == 0x11d05764)) &&
              ((param_2[2] == -0x3fff9157 && (param_2[3] == -0x5dfa28b1)))) {
        iVar2 = param_1 + 0xc;
      }
      else if ((((iVar2 == 0x121) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
              (param_2[3] == 0x46000000)) {
        iVar2 = param_1 + 0x10;
      }
      else if (((iVar2 == 0x122) && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))) {
        iVar2 = param_1 + 0x14;
      }
      else if (((iVar2 == 0x1cb6bfa9) && (param_2[1] == 0x4d356809)) &&
              ((param_2[2] == -0x7f2b866e && (param_2[3] == -0x130d9a6e)))) {
        iVar2 = param_1 + 0x18;
      }
      else {
        if (iVar2 != 0x214ff) {
          return 0x80004002;
        }
        if (param_2[1] != 0) {
          return 0x80004002;
        }
        if (param_2[2] != 0xc0) {
          return 0x80004002;
        }
        if (param_2[3] != 0x46000000) {
          return 0x80004002;
        }
        iVar2 = param_1 + 0x1c;
      }
      if (param_1 == 0) {
        iVar2 = 0;
      }
      *param_3 = iVar2;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40598e1c FUN_40598e1c */

/* Boundary evidence: original MIPS .pdata 40598e1c..40599067. Semantic name remains unreviewed. */

undefined4 FUN_40598e1c(int *param_1)

{
  BOOL BVar1;
  LRESULT LVar2;
  int *piVar3;
  undefined4 *puVar4;
  HMENU hmenu;
  HWND local_48 [2];
  tagMENUITEMINFOW local_40;
  
  (**(code **)(*param_1 + 0x1c))(param_1,0);
  DAT_405aa304 = DAT_405aa304 + -1;
  if (DAT_405aa304 == 0) {
    puVar4 = &DAT_405aa308;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    } while (puVar4 != &DAT_405aa320);
  }
  FUN_40595b9c();
  hmenu = (HMENU)param_1[0xc];
  if (hmenu != (HMENU)0x0) {
    memset(&local_40.fMask,0,0x28);
    local_40.cbSize = 0x2c;
    local_40.fMask = 0x20;
    BVar1 = GetMenuItemInfoW(hmenu,0,1,&local_40);
    if ((BVar1 != 0) && ((int *)local_40.dwItemData != (int *)0x0)) {
      (**(code **)(*(int *)local_40.dwItemData + 8))();
    }
    piVar3 = (int *)param_1[0x1c];
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x1c))(piVar3,param_1[0xc]);
    }
  }
  if ((HWND)param_1[10] != (HWND)0x0) {
    DestroyWindow((HWND)param_1[10]);
  }
  if ((int *)param_1[0x1d] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x1d] + 8))();
    param_1[0x1d] = 0;
  }
  if ((int *)param_1[0x1b] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x1b] + 8))();
    param_1[0x1b] = 0;
  }
  piVar3 = (int *)param_1[0x1c];
  if (piVar3 != (int *)0x0) {
    local_48[0] = (HWND)0x0;
    (**(code **)(*piVar3 + 0xc))(piVar3,local_48);
    LVar2 = SendMessageW(local_48[0],0x7f,0,0);
    if ((LVar2 != 0) && (LVar2 == param_1[0xb])) {
      SendMessageW(local_48[0],0x80,0,0);
      (**(code **)(*(int *)param_1[0x1c] + 0x38))((int *)param_1[0x1c],1,0x40b,0,&DAT_4057112c,0);
      (**(code **)(*(int *)param_1[0x1c] + 0x38))((int *)param_1[0x1c],1,0x40b,4,&DAT_4057112c,0);
      (**(code **)(*(int *)param_1[0x1c] + 0x38))((int *)param_1[0x1c],1,0x40f,4,0,0);
    }
    (**(code **)(*(int *)param_1[0x1c] + 8))();
    param_1[0x1c] = 0;
  }
  if ((HICON)param_1[0xb] != (HICON)0x0) {
    DestroyIcon((HICON)param_1[0xb]);
  }
  return 0;
}



/* 405990c4 FUN_405990c4 */

/* Boundary evidence: original MIPS .pdata 405990c4..405992a3. Semantic name remains unreviewed. */

int FUN_405990c4(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_48;
  int *local_44;
  undefined1 auStack_40 [12];
  undefined4 local_34;
  undefined4 local_30;
  
  uVar2 = param_1[0x15];
  iVar3 = 0;
  if ((uVar2 & 2) == 0) {
    if ((uVar2 & 0x40) == 0) {
      param_1[0x15] = uVar2 | 2;
      if (((undefined4 *)param_1[0x11] == (undefined4 *)0x0) ||
         (iVar3 = FUN_405a39a0((undefined4 *)param_1[0x11]), iVar3 == 0)) {
        iVar3 = -0x7fffbffb;
      }
      else {
        uVar4 = 0x60;
        iVar3 = FUN_405885f0();
        if (iVar3 != 0) {
          uVar4 = 0xe0;
        }
        local_48 = (int *)0x0;
        iVar3 = (**(code **)(*(int *)param_1[0x1a] + 0x10))
                          ((int *)param_1[0x1a],param_1[10],uVar4,&local_48);
        if (-1 < iVar3) {
          if ((param_1[0xe] != 0) &&
             (iVar1 = (**(code **)*local_48)(local_48,&DAT_405719f0,&local_44), -1 < iVar1)) {
            (**(code **)(*local_44 + 0xc))(local_44,param_1[0xe]);
            (**(code **)(*local_44 + 8))();
          }
          FUN_405a48fc((undefined4 *)param_1[0x11],0);
          iVar1 = FUN_405a56ec((int *)param_1[0x11],local_48);
          if (iVar1 != 0) {
            FUN_405a4a88((undefined4 *)param_1[0x11],0x405958d8,(WPARAM)param_1);
            local_30 = 1;
            local_34 = 1;
            SendMessageW(*(HWND *)param_1[0x11],0x102b,0,(LPARAM)auStack_40);
          }
          FUN_405a48fc((undefined4 *)param_1[0x11],1);
          (**(code **)(*local_48 + 8))();
          (**(code **)(*param_1 + 0xa0))(param_1,0,0,0);
        }
      }
      param_1[0x15] = param_1[0x15] & 0xfffffffd;
    }
    else {
      PostMessageW((HWND)param_1[10],0x111,0x4015,0);
    }
  }
  else {
    iVar3 = 1;
  }
  return iVar3;
}



/* 405992a4 FUN_405992a4 */

/* Boundary evidence: original MIPS .pdata 405992a4..405994cf. Semantic name remains unreviewed. */

uint FUN_405992a4(int param_1,MSG *param_2)

{
  ushort uVar1;
  HWND pHVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  int *local_20;
  int *local_1c;
  
  if ((*(uint *)(param_1 + 0x54) & 1) != 0) {
    uVar4 = param_2->message;
    if ((0xff < uVar4) && (uVar4 < 0x109)) {
      if ((uVar4 != 0x100) || (param_2->wParam != 9)) {
        TranslateMessage(param_2);
        DispatchMessageW(param_2);
      }
      return 0;
    }
    return 1;
  }
  uVar4 = 1;
  if ((*(int *)(param_1 + 0x6c) == 0) ||
     ((param_2->hwnd != *(HWND *)(param_1 + 0x28) &&
      (pHVar2 = GetParent(param_2->hwnd), *(HWND *)(param_1 + 0x28) != pHVar2)))) {
    if ((param_2->message != 0x100) || (param_2->wParam != 9)) goto LAB_40599494;
    FUN_405a4570(*(undefined4 **)(param_1 + 0x44));
    uVar4 = 0;
  }
  else {
    if (((param_2->message != 0x100) || (param_2->wParam != 9)) ||
       (iVar3 = (**(code **)**(undefined4 **)(param_1 + 0x6c))
                          (*(undefined4 **)(param_1 + 0x6c),&UNK_40572c98,&local_1c), iVar3 < 0))
    goto LAB_40599494;
    iVar3 = (**(code **)(*local_1c + 0xc))(local_1c,&DAT_40571a10,&DAT_40572c88,&local_20);
    if (-1 < iVar3) {
      uVar1 = GetKeyState(0x10);
      cVar5 = (uVar1 & 0x8000) != 0;
      uVar1 = GetKeyState(0x11);
      if ((uVar1 & 0x8000) != 0) {
        cVar5 = cVar5 + '\x02';
      }
      uVar1 = GetKeyState(0x12);
      if ((uVar1 & 0x8000) != 0) {
        cVar5 = cVar5 + '\x04';
      }
      uVar4 = (**(code **)(*local_20 + 0x1c))(local_20,param_2,cVar5);
      (**(code **)(*local_20 + 8))();
    }
    (**(code **)(*local_1c + 8))();
  }
  if (uVar4 != 1) {
    return uVar4;
  }
LAB_40599494:
  iVar3 = TranslateAcceleratorW(*(HWND *)(param_1 + 0x28),*(HACCEL *)(param_1 + 0x34),param_2);
  return (uint)(iVar3 == 0);
}



/* 405994d0 FUN_405994d0 */

/* Boundary evidence: original MIPS .pdata 405994d0..40599523. Semantic name remains unreviewed. */

undefined4 FUN_405994d0(int *param_1,int param_2)

{
  if (param_2 != param_1[0x14]) {
    (**(code **)(*param_1 + 0x94))(param_1,param_2);
    param_1[0x14] = param_2;
  }
  return 0;
}



/* 40599524 FUN_40599524 */

/* Boundary evidence: original MIPS .pdata 40599524..40599bdf. Semantic name remains unreviewed. */

HRESULT FUN_40599524(int param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  bool bVar1;
  bool bVar2;
  size_t sVar3;
  int iVar4;
  BOOL BVar5;
  undefined3 extraout_var;
  HMENU pHVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  HRESULT HVar10;
  uint local_68;
  int *local_64;
  LRESULT local_60;
  HRESULT local_5c;
  tagMENUITEMINFOW local_58;
  
  if (param_4 == 0) {
    HVar10 = -0x7fffbffd;
  }
  else if (*(undefined4 **)(param_1 + 0x40) == (undefined4 *)0x0) {
    HVar10 = -0x7fffbffb;
  }
  else {
    HVar10 = 0;
    local_5c = 0;
    if (param_2 == (int *)0x0) {
      if (((param_5 != (int *)0x0) && (iVar7 = *param_5, iVar7 != 0)) &&
         ((iVar7 == 1 || (iVar7 == 2)))) {
        HVar10 = StringCchCopyW((STRSAFE_LPWSTR)(param_5 + 3),param_5[2],L"TODO");
        if (-1 < HVar10) {
          sVar3 = wcslen((wchar_t *)(param_5 + 3));
          param_5[1] = sVar3 + 1;
        }
      }
    }
    else if ((((*param_2 == 0x10a7df2f) && (param_2[1] == 0x4eec61ee)) &&
             (param_2[2] == -0x7911f143)) && (param_2[3] == 0x18564efe)) {
      local_68 = 0x33;
      local_60 = 0;
      iVar7 = FUN_405a4104(*(undefined4 **)(param_1 + 0x40),&local_60);
      bVar1 = false;
      if (iVar7 != 0) {
        iVar4 = (**(code **)(**(int **)(param_1 + 100) + 0x24))
                          (*(int **)(param_1 + 100),local_60,iVar7,&local_68);
        bVar1 = true;
        if (iVar4 < 0) {
          bVar1 = false;
        }
      }
      if (param_3 != 0) {
        puVar9 = (uint *)(param_4 + 4);
        do {
          uVar8 = puVar9[-1];
          *puVar9 = 1;
          if (uVar8 < 0x1041) {
            if (uVar8 == 0x1040) {
              *puVar9 = 3;
              if (*(int *)(param_1 + 0x58) == 1) goto LAB_40599a50;
            }
            else {
              switch(uVar8) {
              case 0x1000:
                memset(&local_58.fMask,0,0x28);
                local_58.cbSize = 0x2c;
                local_58.fMask = 0x20;
                BVar5 = GetMenuItemInfoW(*(HMENU *)(param_1 + 0x2c),0,1,&local_58);
                if ((BVar5 != 0) && ((int *)local_58.dwItemData != (int *)0x0)) {
                  (**(code **)(*(int *)local_58.dwItemData + 8))();
                  local_58.dwItemData = 0;
                  SetMenuItemInfoW(*(HMENU *)(param_1 + 0x2c),0,1,&local_58);
                }
                pHVar6 = GetSubMenu(*(HMENU *)(param_1 + 0x2c),0);
                if (pHVar6 != (HMENU)0x0) {
                  local_58.fMask = 2;
                  while (((BVar5 = GetMenuItemInfoW(pHVar6,1,1,&local_58), BVar5 != 0 &&
                          (0x10ff < local_58.wID)) && (local_58.wID < 0x119a))) {
                    RemoveMenu(pHVar6,1,0x400);
                  }
                }
                if (bVar1) {
                  local_64 = (int *)0x0;
                  *puVar9 = *puVar9 | 2;
                  iVar4 = (**(code **)(**(int **)(param_1 + 100) + 0x28))
                                    (*(int **)(param_1 + 100),*(undefined4 *)(param_1 + 0x24),1,
                                     iVar7,&DAT_40572c38,0,&local_64);
                  if (-1 < iVar4) {
                    if (pHVar6 != (HMENU)0x0) {
                      (**(code **)(*local_64 + 0xc))(local_64,pHVar6,1,0x1100,0x1199,0);
                    }
                    local_58.fMask = 0x20;
                    local_58.dwItemData = (ULONG_PTR)local_64;
                    SetMenuItemInfoW(*(HMENU *)(param_1 + 0x2c),0,1,&local_58);
                  }
                }
                break;
              case 0x1001:
              case 0x1004:
              case 0x1025:
switchD_405996f8_caseD_1001:
                *puVar9 = 3;
                break;
              case 0x1002:
                if (bVar1) {
                  uVar8 = local_68 & 0x20;
LAB_405998ec:
                  if (uVar8 != 0) goto switchD_405996f8_caseD_1001;
                }
                break;
              case 0x1003:
                if (((bVar1) && ((local_68 & 0x10) != 0)) && (local_60 == 1))
                goto switchD_405996f8_caseD_1001;
                break;
              case 0x1005:
              case 0x1006:
                if (bVar1) goto switchD_405996f8_caseD_1001;
                break;
              default:
                goto switchD_405996f8_caseD_1007;
              case 0x1020:
                if ((DAT_405aa0d0 != (int *)0x0) &&
                   (bVar2 = FUN_40582f98(DAT_405aa0d0), CONCAT31(extraout_var,bVar2) != 0)) {
                  *puVar9 = *puVar9 | 2;
                }
                iVar4 = *(int *)(param_1 + -4);
                pHVar6 = GetSubMenu(*(HMENU *)(param_1 + 0x2c),1);
                (**(code **)(iVar4 + 0xa4))((int *)(param_1 + -4),pHVar6);
                break;
              case 0x1021:
                if (bVar1) {
                  uVar8 = local_68 & 2;
                  goto LAB_405998ec;
                }
                break;
              case 0x1022:
                if (bVar1) {
                  uVar8 = local_68 & 1;
                  goto LAB_405998ec;
                }
                break;
              case 0x1023:
                iVar4 = FUN_405a16ac();
                if (iVar4 != 0) {
                  uVar8 = *puVar9 | 2;
                  goto LAB_40599a08;
                }
                break;
              case 0x1024:
                uVar8 = FUN_405a1574();
                if ((uVar8 & 2) != 0) {
                  *puVar9 = *puVar9 | 2;
                }
              }
            }
          }
          else {
            switch(uVar8) {
            case 0x1041:
              *puVar9 = 3;
              if (*(int *)(param_1 + 0x58) == 3) {
LAB_40599a50:
                *puVar9 = 7;
              }
              break;
            case 0x1042:
              *puVar9 = 3;
              if (*(int *)(param_1 + 0x58) == 4) goto LAB_40599a50;
              break;
            case 0x1043:
              *puVar9 = 3;
              uVar8 = FUN_405a43e0(*(undefined4 **)(param_1 + 0x40));
              if (uVar8 != 0) {
                uVar8 = *puVar9 | 4;
LAB_40599a08:
                *puVar9 = uVar8;
              }
              break;
            case 0x1044:
              *puVar9 = 3;
              if (*(char *)(param_1 + 0x44) == '\x03') goto LAB_40599a50;
              break;
            case 0x1045:
              *puVar9 = 3;
              if (*(char *)(param_1 + 0x44) == '\0') goto LAB_40599a50;
              break;
            case 0x1046:
              *puVar9 = 3;
              if (*(char *)(param_1 + 0x44) == '\x01') goto LAB_40599a50;
              break;
            case 0x1047:
              *puVar9 = 3;
              if (*(char *)(param_1 + 0x44) == '\x02') goto LAB_40599a50;
              break;
            case 0x1048:
            case 0x1050:
            case 0x1060:
            case 0x1061:
              goto switchD_405996f8_caseD_1001;
            default:
switchD_405996f8_caseD_1007:
              *puVar9 = 0;
              break;
            case 0x104a:
              *puVar9 = 3;
              if (*(int *)(param_1 + 0x58) == 2) goto LAB_40599a50;
            }
          }
          param_3 = param_3 + -1;
          puVar9 = puVar9 + 2;
          HVar10 = local_5c;
        } while (param_3 != 0);
      }
      if (iVar7 != 0) {
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,iVar7);
      }
    }
    else {
      HVar10 = -0x7ffbfefc;
    }
  }
  return HVar10;
}



/* 40599be0 FUN_40599be0 */

/* Boundary evidence: original MIPS .pdata 40599be0..40599c77. Semantic name remains unreviewed. */

undefined4 FUN_40599be0(int param_1,int *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  
  if (param_2 == (int *)0x0) {
    pcVar2 = *(code **)(*(int *)(param_1 + -4) + 0x8c);
  }
  else {
    if ((((*param_2 != 0x10a7df2f) || (param_2[1] != 0x4eec61ee)) || (param_2[2] != -0x7911f143)) ||
       (param_2[3] != 0x18564efe)) {
      return 0x80040104;
    }
    pcVar2 = *(code **)(*(int *)(param_1 + -4) + 0x68);
  }
  uVar1 = (*pcVar2)(param_1 + -4,param_3);
  return uVar1;
}



/* 40599c78 FUN_40599c78 */

/* Boundary evidence: original MIPS .pdata 40599c78..40599cab. Semantic name remains unreviewed. */

undefined4 FUN_40599c78(int param_1,int param_2)

{
  if ((*(undefined4 **)(param_1 + 0x3c) != (undefined4 *)0x0) && (param_2 != 0)) {
    SetFocus((HWND)**(undefined4 **)(param_1 + 0x3c));
  }
  return 0;
}



/* 40599cac FUN_40599cac */

/* Boundary evidence: original MIPS .pdata 40599cac..40599dcf. Semantic name remains unreviewed. */

undefined4 FUN_40599cac(int param_1,undefined4 param_2,ushort *param_3,ushort *param_4)

{
  undefined4 *_Dst;
  HLOCAL pvVar1;
  BOOL BVar2;
  undefined4 uVar3;
  
  _Dst = operator_new(0xc);
  if (_Dst == (undefined4 *)0x0) {
    _Dst = (undefined4 *)0x0;
  }
  else {
    memset(_Dst,0,0xc);
  }
  if (_Dst == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  *_Dst = param_2;
  if (param_3 == (ushort *)0x0) {
LAB_40599d40:
    if (param_4 != (ushort *)0x0) {
      pvVar1 = FUN_405813a0(param_4,-1);
      _Dst[2] = pvVar1;
      if (pvVar1 == (HLOCAL)0x0) goto LAB_40599d34;
    }
    BVar2 = PostMessageW(*(HWND *)(param_1 + 0x1c),0x551,0,(LPARAM)_Dst);
    if (BVar2 != 0) {
      return 0;
    }
    uVar3 = 0x80004005;
  }
  else {
    pvVar1 = FUN_405813a0(param_3,-1);
    _Dst[1] = pvVar1;
    if (pvVar1 != (HLOCAL)0x0) goto LAB_40599d40;
LAB_40599d34:
    uVar3 = 0x8007000e;
  }
  FUN_40580ef4((HLOCAL)_Dst[1]);
  FUN_40580ef4((HLOCAL)_Dst[2]);
  operator_delete(_Dst);
  return uVar3;
}



/* 40599e08 FUN_40599e08 */

/* Boundary evidence: original MIPS .pdata 40599e08..40599e43. Semantic name remains unreviewed. */

undefined4 FUN_40599e08(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_405a4224(*(undefined4 *)(param_1 + 0x34),param_2);
  if (iVar1 == 0) {
    uVar2 = 0x40102;
  }
  return uVar2;
}



/* 40599e44 FUN_40599e44 */

/* Boundary evidence: original MIPS .pdata 40599e44..4059a077. Semantic name remains unreviewed. */

int FUN_40599e44(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  undefined4 *_Dst;
  UINT UVar1;
  int iVar2;
  undefined4 local_60;
  undefined4 *local_5c [3];
  undefined2 local_50 [2];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_38;
  undefined4 local_34;
  
  if ((param_2 == 0) || (param_6 == 0)) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    _Dst = operator_new(0x18);
    if (_Dst == (undefined4 *)0x0) {
      _Dst = (undefined4 *)0x0;
    }
    else {
      memset(_Dst,0,0x18);
    }
    param_1[0x14] = (int)_Dst;
    if (_Dst == (undefined4 *)0x0) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      *_Dst = 0;
      *(undefined4 *)(param_1[0x14] + 4) = 0;
      *(undefined4 *)(param_1[0x14] + 8) = 0;
      *(undefined4 *)(param_1[0x14] + 0xc) = 0;
      *(undefined4 *)(param_1[0x14] + 0x10) = 0;
      *(int *)(param_1[0x14] + 8) = param_2;
      (**(code **)(**(int **)(param_1[0x14] + 8) + 4))();
      local_50[0] = 0;
      memset(&local_4c,0,0x10);
      local_60 = 0;
      memset(local_5c,0,8);
      FUN_405a0a00(&local_38);
      UVar1 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
      local_44 = 0xffffffff;
      local_50[0] = (undefined2)UVar1;
      local_4c = 0;
      local_48 = 1;
      local_40 = 1;
      iVar2 = (**(code **)(**(int **)(param_1[0x14] + 8) + 0xc))
                        (*(int **)(param_1[0x14] + 8),local_50,&local_60);
      if ((-1 < iVar2) && (iVar2 = FUN_405a0d88(local_5c[0],&local_38), iVar2 != 0)) {
        *(undefined4 *)(param_1[0x14] + 0xc) = local_34;
        if ((local_38 & 1) != 0) {
          *(undefined4 *)(param_1[0x14] + 0x10) = 1;
        }
        FUN_405a0a1c((int)&local_38);
      }
      FUN_405a52ec(param_1[0xc],param_4,param_5);
      (**(code **)(param_1[-5] + 0x9c))(param_1 + -5,param_3,param_4,param_5,param_6);
      iVar2 = (**(code **)(*param_1 + 0x10))(param_1,param_3,param_4,param_5,param_6);
      if (iVar2 < 0) {
        (**(code **)(*param_1 + 0x14))(param_1);
      }
    }
  }
  return iVar2;
}



/* 4059a078 FUN_4059a078 */

/* Boundary evidence: original MIPS .pdata 4059a078..4059a237. Semantic name remains unreviewed. */

undefined4 FUN_4059a078(int param_1,uint param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  int *piVar2;
  uint local_20 [2];
  
  if (param_5 == (uint *)0x0) {
    return 0x80070057;
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    return 0x8000ffff;
  }
  iVar1 = FUN_405a5534(*(int **)(param_1 + 0x30),param_3,param_4,local_20);
  if (iVar1 != 0) {
    (**(code **)(*(int *)(param_1 + -0x14) + 0x9c))
              ((int *)(param_1 + -0x14),param_2,param_3,param_4,param_5);
  }
  if (*(int *)(*(int *)(param_1 + 0x50) + 4) == 0) {
    *param_5 = 0;
  }
  else {
    piVar2 = *(int **)(*(int *)(param_1 + 0x50) + 4);
    (**(code **)(*piVar2 + 0x10))(piVar2,param_2,param_3,param_4,param_5);
  }
  if (*param_5 == 0) goto LAB_4059a208;
  FUN_405a431c(*(undefined4 **)(param_1 + 0x30));
  iVar1 = *(int *)(param_1 + 0x50);
  if (*(int *)(iVar1 + 0x10) == 0) {
    if ((param_2 & 8) == 0) {
      if ((param_2 & 4) != 0) {
        *param_5 = 2;
      }
    }
    else {
      if ((param_2 & 4) != 0) goto LAB_4059a1a8;
      *param_5 = 1;
    }
  }
  else if ((((**(int **)(param_1 + 0x30) != *(int *)(iVar1 + 0xc)) || (*(int *)(iVar1 + 0x14) != 0))
           || ((param_2 & 8) != 0)) || ((param_2 & 4) != 0)) {
LAB_4059a1a8:
    *param_5 = 4;
  }
  if (local_20[0] != 0) {
    *param_5 = *param_5 | 0x80000000;
  }
LAB_4059a208:
  **(uint **)(param_1 + 0x50) = *param_5;
  return 0;
}



/* 4059a238 FUN_4059a238 */

/* Boundary evidence: original MIPS .pdata 4059a238..4059a2e3. Semantic name remains unreviewed. */

undefined4 FUN_4059a238(int param_1)

{
  int *piVar1;
  
  if (*(undefined4 **)(param_1 + 0x30) != (undefined4 *)0x0) {
    FUN_405a39c8(*(undefined4 **)(param_1 + 0x30));
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x50) + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))();
      (**(code **)(**(int **)(*(int *)(param_1 + 0x50) + 4) + 8))();
    }
    piVar1 = *(int **)(*(int *)(param_1 + 0x50) + 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))();
    }
    operator_delete(*(void **)(param_1 + 0x50));
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  return 0;
}



/* 4059a2e4 FUN_4059a2e4 */

/* Boundary evidence: original MIPS .pdata 4059a2e4..4059a4f7. Semantic name remains unreviewed. */

int FUN_4059a2e4(int *param_1,int *param_2,undefined4 param_3,int param_4,int param_5,
                undefined4 *param_6)

{
  UINT UVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_60;
  undefined4 *local_5c [3];
  undefined2 local_50 [2];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_38;
  int local_34;
  
  if ((param_2 == (int *)0x0) || (param_6 == (undefined4 *)0x0)) {
    iVar5 = -0x7ff8ffa9;
  }
  else if (param_1[0x14] == 0) {
    iVar5 = -0x7fff0001;
  }
  else if (*(int *)(param_1[0x14] + 4) == 0) {
    iVar5 = -0x7fffbffb;
  }
  else {
    local_50[0] = 0;
    memset(&local_4c,0,0x10);
    local_60 = 0;
    memset(local_5c,0,8);
    FUN_405a0a00(&uStack_38);
    UVar1 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
    local_44 = 0xffffffff;
    iVar5 = 1;
    local_50[0] = (undefined2)UVar1;
    local_4c = 0;
    local_48 = 1;
    local_40 = 1;
    iVar2 = (**(code **)(*param_2 + 0xc))(param_2,local_50,&local_60);
    if ((iVar2 < 0) || (iVar2 = FUN_405a0d88(local_5c[0],&uStack_38), iVar2 == 0)) {
      iVar5 = -0x7fffbffb;
    }
    else {
      if ((((*(int *)param_1[0xc] == local_34) && (((uint *)param_1[0x14])[5] == 0)) &&
          (uVar4 = *(uint *)param_1[0x14], (uVar4 & 4) == 0)) && ((uVar4 & 1) == 0)) {
        FUN_405a3af4((int *)param_1[0xc],param_4,param_5);
      }
      else {
        piVar3 = *(int **)(param_1[0x14] + 4);
        iVar5 = (**(code **)(*piVar3 + 0x18))(piVar3,param_2,param_3,param_4,param_5,param_1[0x14]);
        if (-1 < iVar5) {
          DAT_405a995c = 0x310b;
        }
      }
      FUN_405a0a1c((int)&uStack_38);
    }
    if (iVar5 < 0) {
      *(undefined4 *)param_1[0x14] = 0;
    }
    *param_6 = *(undefined4 *)param_1[0x14];
    (**(code **)(*param_1 + 0x14))(param_1);
  }
  return iVar5;
}



/* 4059a4f8 FUN_4059a4f8 */

/* Boundary evidence: original MIPS .pdata 4059a4f8..4059a603. Semantic name remains unreviewed. */

HRESULT FUN_4059a4f8(int param_1,STRSAFE_PCNZWCH param_2)

{
  STRSAFE_LPWSTR pszDest;
  HRESULT HVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  if (param_2 == (STRSAFE_PCNZWCH)0x0) {
    HVar1 = 0;
  }
  else {
    HVar1 = StringCchLengthW(param_2,0x104,local_20);
    if (-1 < HVar1) {
      if (*(int *)(param_1 + 0x20) == 0) {
        pszDest = (STRSAFE_LPWSTR)
                  (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(local_20[0] + 1) * 2);
      }
      else {
        pszDest = (STRSAFE_LPWSTR)
                  (**(code **)(*DAT_405aa0c8 + 0x10))
                            (DAT_405aa0c8,*(int *)(param_1 + 0x20),(local_20[0] + 1) * 2);
      }
      if (pszDest == (STRSAFE_LPWSTR)0x0) {
        HVar1 = -0x7ff8fff2;
      }
      else {
        HVar1 = StringCchCopyW(pszDest,local_20[0] + 1,param_2);
        *(STRSAFE_LPWSTR *)(param_1 + 0x20) = pszDest;
        if (-1 < HVar1) {
          return HVar1;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return HVar1;
}



/* 4059a638 FUN_4059a638 */

/* Boundary evidence: original MIPS .pdata 4059a638..4059a6a7. Semantic name remains unreviewed. */

undefined4 FUN_4059a638(int param_1,int *param_2,LRESULT *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 == (int *)0x0) || (param_3 == (LRESULT *)0x0)) {
    uVar2 = 0x80070057;
  }
  else if (*(undefined4 **)(param_1 + 0x28) == (undefined4 *)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = 0;
    iVar1 = FUN_405a4104(*(undefined4 **)(param_1 + 0x28),param_3);
    *param_2 = iVar1;
  }
  return uVar2;
}



/* 4059a6a8 FUN_4059a6a8 */

/* Boundary evidence: original MIPS .pdata 4059a6a8..4059a7b3. Semantic name remains unreviewed. */

undefined4 FUN_4059a6a8(int param_1,undefined4 *param_2,uint param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((param_2 == (undefined4 *)0x0) || (4 < param_3)) {
    uVar4 = 0x80070057;
  }
  else {
    if (*(int *)(param_1 + 0x24) == 0) {
      puVar1 = (undefined2 *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,param_3 << 1);
    }
    else {
      puVar1 = (undefined2 *)
               (**(code **)(*DAT_405aa0c8 + 0x10))
                         (DAT_405aa0c8,*(int *)(param_1 + 0x24),param_3 << 1);
    }
    if (puVar1 != (undefined2 *)0x0) {
      puVar2 = puVar1;
      uVar3 = param_3;
      if (0 < (int)param_3) {
        do {
          uVar3 = uVar3 - 1;
          *puVar2 = (short)*param_2;
          param_2 = param_2 + 1;
          puVar2 = puVar2 + 1;
        } while (uVar3 != 0);
      }
      *(short *)(param_1 + 0x20) = (short)param_3;
      *(undefined2 **)(param_1 + 0x24) = puVar1;
      return 0;
    }
    uVar4 = 0x8007000e;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined2 *)(param_1 + 0x20) = 0;
  }
  return uVar4;
}



/* 4059a7b4 FUN_4059a7b4 */

/* Boundary evidence: original MIPS .pdata 4059a7b4..4059a803. Semantic name remains unreviewed. */

void FUN_4059a7b4(int param_1)

{
  if ((*(uint *)(param_1 + 0x54) & 0x80) == 0) {
    PostMessageW(*(HWND *)(param_1 + 0x28),0x550,0,0);
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x80;
  }
  return;
}



/* 4059a804 FUN_4059a804 */

/* Boundary evidence: original MIPS .pdata 4059a804..4059a927. Semantic name remains unreviewed. */

void FUN_4059a804(int *param_1)

{
  int iVar1;
  int iVar2;
  LPARAM lParam;
  LRESULT local_20;
  uint local_1c;
  HWND local_18 [2];
  
  if ((param_1[0x15] & 0x80U) != 0) {
    local_20 = 0;
    iVar1 = FUN_405a4104((undefined4 *)param_1[0x11],&local_20);
    iVar2 = (**(code **)(*(int *)param_1[0x1c] + 0x34))((int *)param_1[0x1c],2,local_18);
    if (-1 < iVar2) {
      local_1c = 0x20;
      lParam = 0;
      if (((iVar1 != 0) &&
          (iVar2 = (**(code **)(*(int *)param_1[0x1a] + 0x24))
                             ((int *)param_1[0x1a],local_20,iVar1,&local_1c), -1 < iVar2)) &&
         ((local_1c & 0x20) != 0)) {
        lParam = 4;
      }
      SendMessageW(local_18[0],0x411,0x1002,lParam);
    }
    (**(code **)(*param_1 + 0xa0))(param_1,iVar1,local_20,0);
    if (iVar1 != 0) {
      (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,iVar1);
    }
    param_1[0x15] = param_1[0x15] & 0xffffff7f;
  }
  return;
}



/* 4059a928 FUN_4059a928 */

/* Boundary evidence: original MIPS .pdata 4059a928..4059aa7f. Semantic name remains unreviewed. */

void FUN_4059a928(int *param_1)

{
  int *piVar1;
  
  *param_1 = (int)&PTR_FUN_40572410;
  param_1[1] = (int)&PTR_LAB_405723fc;
  param_1[2] = (int)&PTR_LAB_405723d4;
  param_1[3] = (int)&PTR_LAB_405723c4;
  param_1[4] = (int)&PTR_LAB_405723b0;
  piVar1 = (int *)param_1[0x11];
  param_1[5] = (int)&PTR_LAB_40572394;
  param_1[6] = (int)&PTR_LAB_40572384;
  param_1[7] = (int)&PTR_LAB_4057236c;
  if (piVar1 != (int *)0x0) {
    FUN_405a52a4(piVar1);
    operator_delete(piVar1);
  }
  if (param_1[10] != 0) {
    FUN_40598e1c(param_1);
  }
  if (param_1[0x19] != 0) {
    piVar1 = *(int **)(param_1[0x19] + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))();
    }
    operator_delete((void *)param_1[0x19]);
  }
  if ((HLOCAL)param_1[9] != (HLOCAL)0x0) {
    FUN_40580ef4((HLOCAL)param_1[9]);
  }
  if ((int *)param_1[0x1a] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x1a] + 8))();
  }
  if (param_1[0xe] != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
  }
  if (param_1[0x10] != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
  }
  return;
}



/* 4059abd4 FUN_4059abd4 */

/* Boundary evidence: original MIPS .pdata 4059abd4..4059aea3. Semantic name remains unreviewed. */

LRESULT FUN_4059abd4(HWND param_1,uint param_2,HMENU param_3,undefined4 *param_4)

{
  int *piVar1;
  LRESULT LVar2;
  BOOL BVar3;
  code *pcVar4;
  tagMENUITEMINFOW local_50;
  
  piVar1 = (int *)GetWindowLongW(param_1,-0x15);
  if ((piVar1 == (int *)0x0) && (param_2 != 1)) {
LAB_4059ada4:
    LVar2 = DefWindowProcW(param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
    return LVar2;
  }
  if (param_2 < 0x1b) {
    if (param_2 != 0x1a) {
      if (param_2 == 1) {
        LVar2 = (**(code **)(*(int *)*param_4 + 0x48))
                          ((int *)*param_4,param_1,param_4[5],param_4[4]);
        return LVar2;
      }
      if (param_2 == 2) {
        pcVar4 = *(code **)(*piVar1 + 0x4c);
      }
      else {
        if (param_2 == 5) {
          (**(code **)(*piVar1 + 0x90))(piVar1,(uint)param_4 & 0xffff,(uint)param_4 >> 0x10);
          return 0;
        }
        if (param_2 == 6) {
          pcVar4 = *(code **)(*piVar1 + 0x94);
          piVar1[0x14] = 2;
          (*pcVar4)(piVar1,2);
          return 0;
        }
        if (param_2 == 7) {
          (**(code **)(*(int *)piVar1[0x1b] + 0x40))((int *)piVar1[0x1b],piVar1);
          SetFocus(*(HWND *)piVar1[0x11]);
          return 0;
        }
        if (param_2 != 0x15) goto LAB_4059ada4;
        pcVar4 = *(code **)(*piVar1 + 0x78);
      }
      (*pcVar4)(piVar1);
      return 0;
    }
    pcVar4 = *(code **)(*piVar1 + 0x74);
LAB_4059ad48:
    LVar2 = (*pcVar4)(piVar1,param_3,param_4);
  }
  else {
    if (param_2 == 0x4e) {
      pcVar4 = *(code **)(*piVar1 + 0x70);
    }
    else if (param_2 == 0x53) {
      pcVar4 = *(code **)(*piVar1 + 0x68);
      param_4 = (undefined4 *)0x4014;
    }
    else {
      if (param_2 == 0x111) {
        LVar2 = (**(code **)(*piVar1 + 0x68))(piVar1,(uint)param_3 & 0xffff);
        return LVar2;
      }
      if (param_2 == 0x117) {
        memset(&local_50.fMask,0,0x28);
        local_50.cbSize = 0x2c;
        local_50.fMask = 0x20;
        BVar3 = GetMenuItemInfoW(param_3,0,1,&local_50);
        if (BVar3 == 0) {
          return 1;
        }
        pcVar4 = *(code **)(*piVar1 + 0x6c);
        param_4 = (undefined4 *)local_50.dwItemData;
        goto LAB_4059ad48;
      }
      if (param_2 == 0x550) {
        FUN_4059a804(piVar1);
        return 0;
      }
      if (param_2 != 0x551) goto LAB_4059ada4;
      pcVar4 = *(code **)(*piVar1 + 100);
    }
    LVar2 = (*pcVar4)(piVar1,param_4);
  }
  return LVar2;
}



/* 4059aea4 FUN_4059aea4 */

/* Boundary evidence: original MIPS .pdata 4059aea4..4059b407. Semantic name remains unreviewed. */

undefined4 FUN_4059aea4(int *param_1,int *param_2)

{
  bool bVar1;
  ushort *puVar2;
  LPCITEMIDLIST pIVar3;
  uint uVar4;
  DWORD DVar5;
  int iVar6;
  code *pcVar7;
  undefined4 uVar8;
  ushort *local_240;
  ushort *local_23c;
  int *local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  local_240 = (ushort *)0x0;
  local_23c = (ushort *)0x0;
  if (param_2 == (int *)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80004005;
  }
  if (param_1[0x11] == 0) {
    FUN_40580ef4((HLOCAL)param_2[1]);
    FUN_40580ef4((HLOCAL)param_2[2]);
    uVar8 = 1;
    goto LAB_4059b3cc;
  }
  if ((ushort *)param_2[1] != (ushort *)0x0) {
    local_240 = FUN_405813a0((ushort *)param_2[1],-1);
    FUN_40587714((LPCITEMIDLIST)param_1[9],(int *)&local_240);
  }
  if ((ushort *)param_2[2] != (ushort *)0x0) {
    local_23c = FUN_405813a0((ushort *)param_2[2],-1);
    FUN_40587714((LPCITEMIDLIST)param_1[9],(int *)&local_23c);
  }
  iVar6 = *param_2;
  bVar1 = true;
  if (iVar6 == 1) {
    if ((((local_240 != (ushort *)0x0) && (local_23c != (ushort *)0x0)) &&
        (puVar2 = (ushort *)FUN_405a3f50((undefined4 *)param_1[0x11],(char *)local_240),
        puVar2 != (ushort *)0x0)) &&
       (pIVar3 = FUN_405813a0(puVar2,-1), pIVar3 != (LPCITEMIDLIST)0x0)) {
      iVar6 = FUN_405a4b60((undefined4 *)param_1[0x11],(char *)local_240,local_23c);
      if (iVar6 != 0) {
        FUN_405a4404((undefined4 *)param_1[0x11],(char *)local_23c,0);
        uVar4 = (**(code **)(*(int *)param_1[0x1a] + 0x1c))((int *)param_1[0x1a],2,pIVar3,local_23c)
        ;
        if ((-1 < (int)uVar4) && ((uVar4 & 0xffff) != 0)) {
          iVar6 = 2;
          puVar2 = local_23c;
          goto LAB_4059b344;
        }
        goto LAB_4059b34c;
      }
LAB_4059b35c:
      FUN_40580ef4(pIVar3);
    }
  }
  else if (iVar6 == 2) {
    if ((local_240 != (ushort *)0x0) &&
       (pIVar3 = FUN_405812ec((ushort *)param_1[9],local_240), pIVar3 != (LPCITEMIDLIST)0x0)) {
      iVar6 = SHGetPathFromIDList(pIVar3,awStack_230);
      if ((iVar6 != 0) && (DVar5 = GetFileAttributesW(awStack_230), DVar5 != 0xffffffff)) {
        iVar6 = FUN_405885fc();
        if ((iVar6 == 0) && (((DVar5 & 4) != 0 || ((DVar5 & 0x2000) != 0)))) {
          bVar1 = false;
        }
        iVar6 = FUN_405885f0();
        if ((iVar6 == 0) && ((DVar5 & 2) != 0)) {
          bVar1 = false;
        }
        if (!bVar1) goto LAB_4059b35c;
      }
      FUN_405a45f0((int *)param_1[0x11],local_240);
      goto LAB_4059b35c;
    }
  }
  else if (iVar6 == 4) {
    if (local_240 != (ushort *)0x0) {
      FUN_405a4708((undefined4 *)param_1[0x11],(char *)local_240);
    }
  }
  else if (iVar6 == 0x10) {
    if ((int *)param_1[0x1b] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x1b] + 4))();
      iVar6 = (*(code *)**(undefined4 **)param_1[0x1b])
                        ((undefined4 *)param_1[0x1b],&DAT_40572b78,local_238);
      (**(code **)(*(int *)param_1[0x1b] + 8))();
      if (-1 < iVar6) {
        (**(code **)(*local_238[0] + 0x10))(local_238[0],0,0x2d,0,0,0);
        pcVar7 = *(code **)(*local_238[0] + 8);
        goto LAB_4059afd8;
      }
    }
  }
  else if (iVar6 == 0x800) {
    if (((local_240 != (ushort *)0x0) &&
        (puVar2 = (ushort *)FUN_405a3f50((undefined4 *)param_1[0x11],(char *)local_240),
        puVar2 != (ushort *)0x0)) &&
       (pIVar3 = FUN_405813a0(puVar2,-1), pIVar3 != (LPCITEMIDLIST)0x0)) {
      iVar6 = FUN_405a4b60((undefined4 *)param_1[0x11],(char *)pIVar3,local_240);
      if (iVar6 != 0) {
        uVar4 = (**(code **)(*(int *)param_1[0x1a] + 0x1c))((int *)param_1[0x1a],1,pIVar3,local_240)
        ;
        if ((-1 < (int)uVar4) && ((uVar4 & 0xffff) != 0)) {
          iVar6 = 1;
          puVar2 = local_240;
LAB_4059b344:
          FUN_405a4404((undefined4 *)param_1[0x11],(char *)puVar2,iVar6);
        }
LAB_4059b34c:
        UpdateWindow(*(HWND *)param_1[0x11]);
      }
      goto LAB_4059b35c;
    }
  }
  else if (iVar6 == 0x2000) {
    if (((local_240 != (ushort *)0x0) &&
        (puVar2 = (ushort *)FUN_405a3f50((undefined4 *)param_1[0x11],(char *)local_240),
        puVar2 != (ushort *)0x0)) &&
       (pIVar3 = FUN_405813a0(puVar2,-1), pIVar3 != (LPCITEMIDLIST)0x0)) {
      iVar6 = FUN_405a4b60((undefined4 *)param_1[0x11],(char *)pIVar3,local_240);
      if (iVar6 != 0) {
        FUN_405a4404((undefined4 *)param_1[0x11],(char *)local_240,0);
        uVar4 = (**(code **)(*(int *)param_1[0x1a] + 0x1c))((int *)param_1[0x1a],1,pIVar3,local_240)
        ;
        if ((-1 < (int)uVar4) && ((uVar4 & 0xffff) != 0)) {
          FUN_405a4404((undefined4 *)param_1[0x11],(char *)local_240,1);
        }
        uVar4 = (**(code **)(*(int *)param_1[0x1a] + 0x1c))((int *)param_1[0x1a],3,pIVar3,local_240)
        ;
        if ((-1 < (int)uVar4) && ((uVar4 & 0xffff) != 0)) {
          iVar6 = 3;
          puVar2 = local_240;
          goto LAB_4059b344;
        }
        goto LAB_4059b34c;
      }
      goto LAB_4059b35c;
    }
  }
  else {
    pcVar7 = *(code **)(*param_1 + 0x20);
    local_238[0] = param_1;
LAB_4059afd8:
    (*pcVar7)(local_238[0]);
  }
  if (*param_2 != 0x10) {
    (**(code **)(*param_1 + 0xa0))(param_1,0,0,0);
  }
  if (local_240 != (ushort *)0x0) {
    FUN_40580ef4(local_240);
  }
  if (local_23c != (ushort *)0x0) {
    FUN_40580ef4(local_23c);
  }
  FUN_40580ef4((HLOCAL)param_2[1]);
  FUN_40580ef4((HLOCAL)param_2[2]);
  uVar8 = 0;
LAB_4059b3cc:
  operator_delete(param_2);
  FUN_405a7174(local_28);
  return uVar8;
}



/* 4059b408 FUN_4059b408 */

/* Boundary evidence: original MIPS .pdata 4059b408..4059b73f. Semantic name remains unreviewed. */

undefined4 FUN_4059b408(int *param_1,int param_2)

{
  SHORT SVar1;
  undefined4 uVar2;
  HLOCAL pvVar3;
  undefined2 extraout_var;
  DWORD DVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar7 = *(uint *)(param_2 + 8);
  if (uVar7 < 0xffffff94) {
    if (uVar7 == 0xffffff93) {
      (**(code **)(*param_1 + 0x54))(param_1);
      return 0;
    }
    if (uVar7 == 1000) {
LAB_4059b6f8:
      DVar4 = GetMessagePos();
      (**(code **)(*param_1 + 0x50))(param_1,(int)(short)DVar4,(int)DVar4 >> 0x10);
      return 0;
    }
    if ((uVar7 == 0xfffffeb9) || (uVar7 == 0xfffffebf)) {
      if (3 < *(int *)(param_2 + 0xc)) {
        return 0;
      }
      if ((**(uint **)(param_2 + 0x14) & 1) == 0) {
        return 0;
      }
      *(short *)(&DAT_405a9960 + *(int *)(param_2 + 0xc) * 2) =
           (short)(*(uint **)(param_2 + 0x14))[1];
      return 0;
    }
    if (uVar7 != 0xffffff4f) {
      if (uVar7 == 0xffffff50) {
        pcVar5 = *(code **)(*param_1 + 0x40);
      }
      else {
        if (uVar7 != 0xffffff51) {
          if (uVar7 != 0xffffff65) {
            return 0;
          }
          if (*(short *)(param_2 + 0xc) != 0x1b) {
            return 0;
          }
          FUN_405a1604(*(int *)param_1[0x11]);
          DAT_405a995c = 0x3107;
          return 0;
        }
        pcVar5 = *(code **)(*param_1 + 0x44);
      }
      uVar2 = (*pcVar5)(param_1);
      return uVar2;
    }
    pcVar5 = *(code **)(*param_1 + 0x60);
  }
  else {
    if (0xfffffff9 < uVar7) {
      if (uVar7 < 0xfffffffa) {
        return 0;
      }
      if (uVar7 < 0xfffffffc) {
        if (uVar7 != 0xfffffffe) goto LAB_4059b6f8;
      }
      else {
        if (uVar7 < 0xfffffffe) {
          pcVar5 = *(code **)(*param_1 + 0x8c);
          param_2 = 1;
          goto LAB_4059b65c;
        }
        if (uVar7 != 0xfffffffe) {
          return 0;
        }
      }
      SVar1 = GetAsyncKeyState(0x12);
      if (CONCAT22(extraout_var,SVar1) == 0) {
        return 0;
      }
      goto LAB_4059b6f8;
    }
    if (uVar7 == 0xfffffff9) {
      (**(code **)(*param_1 + 0xa0))(param_1,0,0,0);
      return 0;
    }
    if (uVar7 != 0xffffff94) {
      if (uVar7 == 0xffffff99) {
        pvVar3 = (HLOCAL)FUN_405a3ed0((undefined4 *)param_1[0x11],*(int *)(param_2 + 0xc));
        FUN_40580ef4(pvVar3);
        return 0;
      }
      if (uVar7 != 0xffffff9b) {
        return 0;
      }
      if (param_1[0x1c] == 0) {
        return 0;
      }
      if ((*(uint *)(param_2 + 0x1c) & 8) == 0) {
        return 0;
      }
      if (((*(uint *)(param_2 + 0x18) ^ *(uint *)(param_2 + 0x14)) & 2) == 0) {
        return 0;
      }
      FUN_4059a7b4((int)param_1);
      return 0;
    }
    iVar6 = *(int *)(param_2 + 0x10);
    if (iVar6 == 0) {
      param_2 = 0x1045;
    }
    else if (iVar6 == 1) {
      param_2 = 0x1046;
    }
    else if (iVar6 == 2) {
      param_2 = 0x1047;
    }
    else {
      if (iVar6 != 3) {
        return 0;
      }
      param_2 = 0x1044;
    }
    pcVar5 = *(code **)(*param_1 + 0x68);
  }
LAB_4059b65c:
  (*pcVar5)(param_1,param_2);
  return 0;
}



/* 4059b740 FUN_4059b740 */

/* Boundary evidence: original MIPS .pdata 4059b740..4059bb63. Semantic name remains unreviewed. */

undefined4
FUN_4059b740(int *param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5,
            undefined4 *param_6)

{
  ATOM AVar1;
  ushort uVar2;
  BOOL BVar3;
  undefined2 extraout_var;
  HWND pHVar4;
  int iVar5;
  HRESULT HVar6;
  undefined2 extraout_var_00;
  wchar_t *pwVar7;
  int *piVar8;
  uint uVar9;
  LPCITEMIDLIST local_630;
  int *local_62c;
  HWND local_628;
  int *local_624;
  HWND local_620 [2];
  tagWNDCLASSW local_618;
  STRRET local_5f0;
  int local_4e8;
  undefined1 auStack_4e4 [692];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((((param_3 == (int *)0x0) || (param_4 == (int *)0x0)) || (param_5 == (int *)0x0)) ||
     (param_6 == (undefined4 *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80070057;
  }
  *param_6 = 0;
  if (param_1[10] != 0) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  local_618.style = 0;
  memset(&local_618.lpfnWndProc,0,0x24);
  local_620[0] = (HWND)0x0;
  BVar3 = GetClassInfoW(DAT_405aa0c0,L"DefShellView",&local_618);
  if (BVar3 == 0) {
    local_618.style = 3;
    local_618.lpfnWndProc = FUN_4059abd4;
    local_618.hInstance = DAT_405aa0c0;
    local_618.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_618.hbrBackground = (HBRUSH)0x40000006;
    local_618.lpszClassName = L"DefShellView";
    AVar1 = RegisterClassW(&local_618);
    if (CONCAT22(extraout_var,AVar1) == 0) goto LAB_4059b848;
  }
  param_1[0x1b] = (int)param_4;
  (**(code **)(*param_4 + 4))(param_4);
  param_1[0x17] = *param_3;
  param_1[0x16] = param_3[1] | 0x2000;
  (**(code **)(*(int *)param_1[0x1b] + 0xc))((int *)param_1[0x1b],local_620);
  pHVar4 = CreateWindowExW(0,L"DefShellView",(LPCWSTR)0x0,0x46000000,*param_5,param_5[1],
                           param_5[2] - *param_5,param_5[3] - param_5[1],local_620[0],(HMENU)0x0,
                           DAT_405aa0c0,param_1);
  *param_6 = pHVar4;
  if (pHVar4 != (HWND)0x0) {
    FUN_40595950();
    FUN_405959e8();
    iVar5 = (*(code *)**(undefined4 **)param_1[0x1b])
                      ((undefined4 *)param_1[0x1b],&UNK_40572c98,&local_624);
    if (-1 < iVar5) {
      (**(code **)(*local_624 + 0xc))(local_624,&DAT_40571a10,&DAT_40572b88,param_1 + 0x1c);
      (**(code **)(*local_624 + 8))();
    }
    iVar5 = (*(code *)**(undefined4 **)param_1[0x1b])
                      ((undefined4 *)param_1[0x1b],&UNK_40572ca8,param_1 + 0x1d);
    if (-1 < iVar5) {
      piVar8 = (int *)param_1[0x1d];
      (**(code **)(*piVar8 + 0x20))(piVar8,param_1 + 2,0);
    }
    ShowWindow((HWND)*param_6,5);
    if (param_1[0x1c] != 0) {
      local_62c = (int *)0x0;
      local_630 = (LPCITEMIDLIST)0x0;
      HVar6 = SHBindToParent((LPCITEMIDLIST)param_1[9],(IID *)&DAT_40572b68,&local_62c,&local_630);
      if (-1 < HVar6) {
        local_4e8 = 0;
        memset(auStack_4e4,0,0x2b0);
        local_5f0.uType = 0;
        memset(&local_5f0.u,0,0x104);
        iVar5 = (**(code **)(*local_62c + 0x2c))(local_62c,local_630,0x8000,&local_5f0);
        if ((-1 < iVar5) &&
           (HVar6 = StrRetToBufW(&local_5f0,local_630,aWStack_230,0x104), -1 < HVar6)) {
          pwVar7 = aWStack_230;
          uVar9 = 0x101;
          uVar2 = FUN_405811d8((char *)local_630);
          if (CONCAT22(extraout_var_00,uVar2) != 0) {
            pwVar7 = wcsrchr(aWStack_230,L'{');
            uVar9 = 0x111;
          }
          iVar5 = SHGetFileInfo(pwVar7,0,&local_4e8,0x2b4,uVar9);
          if (iVar5 != 0) {
            local_628 = (HWND)0x0;
            (**(code **)(*(int *)param_1[0x1c] + 0xc))((int *)param_1[0x1c],&local_628);
            SendMessageW(local_628,0x80,0,local_4e8);
            param_1[0xb] = local_4e8;
          }
        }
        (**(code **)(*local_62c + 8))();
        FUN_40580ef4(local_630);
      }
    }
    (**(code **)(*param_1 + 0xa0))(param_1,0,0,1);
    FUN_405a7174(local_28);
    return 0;
  }
LAB_4059b848:
  FUN_405a7174(local_28);
  return 0x80004005;
}



/* 4059bb64 FUN_4059bb64 */

/* Boundary evidence: original MIPS .pdata 4059bb64..4059bba7. Semantic name remains unreviewed. */

int FUN_4059bb64(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[8] + -1;
  param_1[8] = iVar1;
  if (iVar1 == 0) {
    FUN_4059a928(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 4059bc34 FUN_4059bc34 */

/* Boundary evidence: original MIPS .pdata 4059bc34..4059bdbb. Semantic name remains unreviewed. */

undefined4 * FUN_4059bc34(undefined4 *param_1,undefined4 param_2,ushort *param_3)

{
  HACCEL pHVar1;
  HLOCAL pvVar2;
  undefined4 *puVar3;
  
  param_1[2] = &PTR_LAB_405724b8;
  param_1[3] = &PTR_LAB_40572320;
  param_1[4] = &PTR_LAB_40572330;
  param_1[5] = &PTR_LAB_4057106c;
  param_1[6] = &PTR_LAB_40572344;
  param_1[7] = &PTR_LAB_40572354;
  param_1[1] = &PTR_LAB_405723fc;
  *param_1 = &PTR_FUN_40572410;
  param_1[4] = &PTR_LAB_405723b0;
  param_1[2] = &PTR_LAB_405723d4;
  param_1[3] = &PTR_LAB_405723c4;
  param_1[7] = &PTR_LAB_4057236c;
  param_1[0x15] = 0x20;
  param_1[0x1a] = param_2;
  param_1[5] = &PTR_LAB_40572394;
  param_1[6] = &PTR_LAB_40572384;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined2 *)((int)param_1 + 0x4a) = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 1;
  param_1[0x19] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  pHVar1 = LoadAcceleratorsW(DAT_405aa0c0,(LPCWSTR)0x4000);
  param_1[0xd] = pHVar1;
  pvVar2 = FUN_405813a0(param_3,-1);
  param_1[9] = pvVar2;
  puVar3 = operator_new(0x3c);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = FUN_405a34b0(puVar3);
  }
  param_1[0x11] = puVar3;
  param_1[8] = 1;
  return param_1;
}



/* 4059bdbc FUN_4059bdbc */

/* Boundary evidence: original MIPS .pdata 4059bdbc..4059be37. Semantic name remains unreviewed. */

undefined4 FUN_4059bdbc(int *param_1,int *param_2,ushort *param_3)

{
  HLOCAL pvVar1;
  int iVar2;
  
  param_1[3] = *param_2;
  param_1[4] = param_2[1];
  param_1[5] = param_2[2];
  param_1[6] = param_2[3];
  if (param_3 != (ushort *)0x0) {
    pvVar1 = FUN_405813a0(param_3,-1);
    param_1[9] = (int)pvVar1;
    if (pvVar1 == (HLOCAL)0x0) {
      return 0;
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar2 < 0) {
    return 0;
  }
  return 1;
}



/* 4059be38 FUN_4059be38 */

/* Boundary evidence: original MIPS .pdata 4059be38..4059be9b. Semantic name remains unreviewed. */

void FUN_4059be38(int param_1)

{
  if (*(HKEY *)(param_1 + 0x1c) != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return;
}



/* 4059be9c FUN_4059be9c */

/* Boundary evidence: original MIPS .pdata 4059be9c..4059bfd3. Semantic name remains unreviewed. */

undefined4 FUN_4059be9c(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = *param_2;
    if (((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
        ) || (((iVar2 == 0x214f2 && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    else {
      if (iVar2 != 0x1cb6bfa9) {
        return 0x80004002;
      }
      if (param_2[1] != 0x4d356809) {
        return 0x80004002;
      }
      if (param_2[2] != -0x7f2b866e) {
        return 0x80004002;
      }
      if (param_2[3] != -0x130d9a6e) {
        return 0x80004002;
      }
      iVar2 = param_1 + 4;
      if (param_1 == 0) {
        iVar2 = 0;
      }
      *param_3 = iVar2;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4059bfd4 FUN_4059bfd4 */

/* Boundary evidence: original MIPS .pdata 4059bfd4..4059c1e3. Semantic name remains unreviewed. */

int FUN_4059bfd4(int param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  DWORD dwIndex;
  HRESULT HVar3;
  DWORD local_98 [2];
  CLSID local_90;
  WCHAR aWStack_80 [40];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  HVar3 = 0;
  if (param_3 == (int *)0x0) {
    HVar3 = -0x7ff8ffa9;
  }
  if ((*(int *)(param_1 + 0x1c) == 0) && (*(int *)(param_1 + 0x28) == 0)) {
    HVar3 = -0x7fff0001;
  }
  if (HVar3 == 0) {
    do {
      local_98[0] = 0x27;
      local_90.Data1 = 0;
      memset(&local_90.Data2,0,0xc);
      if (*(HKEY *)(param_1 + 0x1c) == (HKEY)0x0) {
        iVar1 = 0x103;
      }
      else {
        dwIndex = *(DWORD *)(param_1 + 0x20);
        *(DWORD *)(param_1 + 0x20) = dwIndex + 1;
        iVar1 = RegEnumValueW(*(HKEY *)(param_1 + 0x1c),dwIndex,aWStack_80,local_98,(LPDWORD)0x0,
                              (LPDWORD)0x0,(LPBYTE)0x0,(LPDWORD)0x0);
      }
      if (iVar1 != 0) {
        if (iVar1 == 0x103) {
          piVar2 = *(int **)(param_1 + 0x28);
          if (piVar2 == (int *)0x0) {
            HVar3 = 1;
          }
          else {
            HVar3 = (**(code **)(*piVar2 + 0xc))(piVar2,param_2,param_3,param_4);
          }
        }
        else {
          HVar3 = -0x7fffbffb;
        }
        goto LAB_4059c198;
      }
      HVar3 = CLSIDFromString(aWStack_80,&local_90);
    } while ((((*(char *)(param_1 + 0x30) != '\0') && (local_90.Data1 == 0x214a1)) &&
             (local_90._4_4_ == 0)) &&
            ((local_90.Data4._0_4_ == 0xc0 && (local_90.Data4._4_4_ == 0x46000000))));
    if ((-1 < HVar3) &&
       ((HVar3 = FUN_40587d78(&local_90,param_3), -1 < HVar3 && (param_4 != (undefined4 *)0x0)))) {
      *param_4 = 1;
    }
LAB_4059c198:
    if (HVar3 == 0) goto LAB_4059c1ac;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
LAB_4059c1ac:
  FUN_405a7174(local_30);
  return HVar3;
}



/* 4059c1e4 FUN_4059c1e4 */

/* Boundary evidence: original MIPS .pdata 4059c1e4..4059c39b. Semantic name remains unreviewed. */

int FUN_4059c1e4(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_4059be38(param_1);
  if ((((*(int *)(param_1 + 0xc) == 0x21400) && (*(int *)(param_1 + 0x10) == 0)) &&
      (*(int *)(param_1 + 0x14) == 0xc0)) && (*(int *)(param_1 + 0x18) == 0x46000000)) {
    iVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Explorer\\Desktop",0,0,(PHKEY)(param_1 + 0x1c));
  }
  else {
    if (((*(int *)(param_1 + 0xc) != 0x214a0) || (*(int *)(param_1 + 0x10) != 0)) ||
       ((*(int *)(param_1 + 0x14) != 0xc0 || (*(int *)(param_1 + 0x18) != 0x46000000)))) {
      iVar3 = -0x7fffbffb;
      goto LAB_4059c310;
    }
    iVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Explorer\\My Computer",0,0,(PHKEY)(param_1 + 0x1c));
  }
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
LAB_4059c310:
  if (*(int *)(param_1 + 0x24) != 0) {
    puVar2 = operator_new(0x250);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_405a0988(puVar2,*(undefined4 *)(param_1 + 0x2c));
    }
    if (puVar2 == (undefined4 *)0x0) {
      iVar3 = -0x7ff8fff2;
    }
    else {
      iVar1 = FUN_405a01cc((int)puVar2,*(ushort **)(param_1 + 0x24));
      if (iVar1 != 0) {
        *(undefined4 **)(param_1 + 0x28) = puVar2;
      }
    }
  }
  if (iVar3 < 0) {
    FUN_4059be38(param_1);
  }
  return iVar3;
}



/* 4059c39c FUN_4059c39c */

/* Boundary evidence: original MIPS .pdata 4059c39c..4059c44f. Semantic name remains unreviewed. */

int FUN_4059c39c(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  int *local_18 [2];
  
  iVar4 = -0x7fffbffb;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  if (param_2 == 0) {
    return 0;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x24);
  if (puVar2 == (undefined4 *)0x0) {
    return -0x7fffbffb;
  }
  iVar1 = (**(code **)*puVar2)(puVar2,&DAT_405719f0,local_18);
  if (-1 < iVar1) {
    iVar4 = (**(code **)(*local_18[0] + 0xc))(local_18[0],param_2);
    (**(code **)(*local_18[0] + 8))();
    uVar3 = 1;
    if (-1 < iVar4) goto LAB_4059c430;
  }
  uVar3 = 0;
LAB_4059c430:
  *(undefined1 *)(param_1 + 0x2c) = uVar3;
  return iVar4;
}



/* 4059c450 FUN_4059c450 */

/* Boundary evidence: original MIPS .pdata 4059c450..4059c4a3. Semantic name remains unreviewed. */

void FUN_4059c450(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40572540;
  param_1[1] = &PTR_LAB_40572530;
  FUN_4059be38((int)param_1);
  if ((HLOCAL)param_1[9] != (HLOCAL)0x0) {
    FUN_40580ef4((HLOCAL)param_1[9]);
  }
  return;
}



/* 4059c4cc FUN_4059c4cc */

/* Boundary evidence: original MIPS .pdata 4059c4cc..4059c543. Semantic name remains unreviewed. */

undefined4 * FUN_4059c4cc(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = &PTR_LAB_40572344;
  param_1[0xb] = param_2;
  *param_1 = &PTR_FUN_40572540;
  param_1[1] = &PTR_LAB_40572530;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  memset(param_1 + 3,0,0x10);
  param_1[2] = 1;
  return param_1;
}



/* 4059c544 FUN_4059c544 */

/* Boundary evidence: original MIPS .pdata 4059c544..4059c587. Semantic name remains unreviewed. */

int FUN_4059c544(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2] + -1;
  param_1[2] = iVar1;
  if (iVar1 == 0) {
    FUN_4059c450(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 4059c59c FUN_4059c59c */

/* Boundary evidence: original MIPS .pdata 4059c59c..4059c637. Semantic name remains unreviewed. */

undefined4 * FUN_4059c59c(undefined4 *param_1,undefined4 param_2,ushort *param_3)

{
  FUN_4059bc34(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_4057262c;
  param_1[1] = &PTR_LAB_40572618;
  param_1[2] = &PTR_LAB_405725f0;
  param_1[3] = &PTR_LAB_405725e0;
  param_1[4] = &PTR_LAB_405725cc;
  param_1[5] = &PTR_LAB_405725b0;
  param_1[6] = &PTR_LAB_405725a0;
  param_1[7] = &PTR_LAB_40572588;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  *(undefined1 *)(param_1 + 0x21) = 0;
  return param_1;
}



/* 4059c638 FUN_4059c638 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 4059c638..4059c863. Semantic name remains unreviewed. */

HBITMAP FUN_4059c638(int param_1,HBITMAP param_2)

{
  HDC hdc;
  HDC hdc_00;
  HDC hdc_01;
  int iVar1;
  int cx;
  LRESULT LVar2;
  HBRUSH h;
  HGDIOBJ h_00;
  HBITMAP h_01;
  int local_48;
  int local_44 [3];
  int local_38;
  
  if (param_2 == (HBITMAP)0x0) {
    h_01 = (HBITMAP)0x0;
  }
  else {
    local_44[1] = 0;
    memset(local_44 + 2,0,0x14);
    hdc = CreateDCW(L"DISPLAY",(LPCWSTR)0x0,(LPCWSTR)0x0,(DEVMODEW *)0x0);
    GetObjectW(param_2,0x18,local_44 + 1);
    hdc_00 = CreateCompatibleDC(hdc);
    SelectObject(hdc_00,param_2);
    hdc_01 = CreateCompatibleDC(hdc);
    iVar1 = FUN_40588608();
    if (iVar1 == 0) {
      h_01 = CreateCompatibleBitmap(hdc,local_44[2],local_38);
      SelectObject(hdc_01,h_01);
      BitBlt(hdc_01,0,0,local_44[2],local_38,hdc_00,0,0,0xcc0020);
    }
    else {
      iVar1 = GetSystemMetrics(0x4f);
      cx = GetSystemMetrics(0x4e);
      h_01 = CreateCompatibleBitmap(hdc,cx,iVar1);
      SelectObject(hdc_01,h_01);
      local_48 = 0;
      memset(local_44,0,4);
      if ((*(undefined4 **)(param_1 + 0x44) != (undefined4 *)0x0) &&
         (LVar2 = SendMessageW((HWND)**(undefined4 **)(param_1 + 0x44),0x1029,0,(LPARAM)&local_48),
         LVar2 != 0)) {
        SetBrushOrgEx(hdc_00,local_48,local_44[0],(LPPOINT)0x0);
      }
      h = CreatePatternBrush(param_2);
      h_00 = SelectObject(hdc_01,h);
      PatBlt(hdc_01,0,0,cx,iVar1,0xf00021);
      SelectObject(hdc_01,h_00);
      DeleteObject(h);
    }
    DeleteDC(hdc_00);
    DeleteDC(hdc_01);
    DeleteDC(hdc);
  }
  return h_01;
}



/* 4059c864 FUN_4059c864 */

/* Boundary evidence: original MIPS .pdata 4059c864..4059c8cf. Semantic name remains unreviewed. */

void FUN_4059c864(int param_1)

{
  HRESULT HVar1;
  
  if ((*(char *)(param_1 + 0x84) == '\0') && (HVar1 = CoInitializeEx((LPVOID)0x0,0), -1 < HVar1)) {
    *(undefined1 *)(param_1 + 0x84) = 1;
    CoCreateInstance((IID *)&DAT_40571b10,(LPUNKNOWN)0x0,1,(IID *)&DAT_40571b00,
                     (LPVOID *)(param_1 + 0x80));
  }
  return;
}



/* 4059c8d0 FUN_4059c8d0 */

/* Boundary evidence: original MIPS .pdata 4059c8d0..4059c927. Semantic name remains unreviewed. */

void FUN_4059c8d0(int param_1)

{
  if (*(int **)(param_1 + 0x80) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x80) + 8))();
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if (*(char *)(param_1 + 0x84) != '\0') {
    CoUninitialize();
    *(undefined1 *)(param_1 + 0x84) = 0;
  }
  return;
}



/* 4059c928 FUN_4059c928 */

/* Boundary evidence: original MIPS .pdata 4059c928..4059ca63. Semantic name remains unreviewed. */

undefined4 FUN_4059c928(int param_1,LPCWSTR param_2)

{
  LPWSTR _Str1;
  int iVar1;
  LPWSTR _SubStr;
  LPWSTR _Str;
  wchar_t *pwVar2;
  uint uVar3;
  undefined4 uVar4;
  LPVOID local_20;
  uint local_1c;
  
  uVar4 = 0;
  if (((((param_2 != (LPCWSTR)0x0) && (*param_2 != L'\0')) &&
       (_Str1 = PathFindExtensionW(param_2), _Str1 != (LPWSTR)0x0)) &&
      ((*_Str1 != L'\0' && (*(int *)(param_1 + 0x80) != 0)))) &&
     (iVar1 = _wcsicmp(_Str1,L".2bp"), iVar1 != 0)) {
    local_20 = (LPVOID)0x0;
    local_1c = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x80) + 0x30))
                      (*(int **)(param_1 + 0x80),&local_1c,&local_20);
    if (((-1 < iVar1) && (local_20 != (LPVOID)0x0)) && (local_1c != 0)) {
      uVar3 = 0;
      iVar1 = 0;
      do {
        _SubStr = CharUpperW(_Str1);
        _Str = CharUpperW(*(LPWSTR *)((int)local_20 + iVar1 + 0x2c));
        pwVar2 = wcsstr(_Str,_SubStr);
        if (pwVar2 != (wchar_t *)0x0) {
          uVar4 = 1;
          break;
        }
        uVar3 = uVar3 + 1;
        iVar1 = iVar1 + 0x4c;
      } while (uVar3 < local_1c);
      CoTaskMemFree(local_20);
    }
  }
  return uVar4;
}



/* 4059ca64 FUN_4059ca64 */

/* Boundary evidence: original MIPS .pdata 4059ca64..4059cbbb. Semantic name remains unreviewed. */

HBRUSH FUN_4059ca64(undefined4 param_1,LPCWSTR param_2)

{
  HANDLE hFile;
  DWORD DVar1;
  BOOL BVar2;
  LPVOID lpBuffer;
  HBRUSH pHVar3;
  DWORD local_30 [2];
  short local_28 [8];
  
  pHVar3 = (HBRUSH)0x0;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar1 = GetFileSize(hFile,(LPDWORD)0x0);
    local_30[0] = 0;
    BVar2 = ReadFile(hFile,local_28,0xe,local_30,(LPOVERLAPPED)0x0);
    if (((BVar2 == 0) && (local_28[0] == 0x4d42)) &&
       (lpBuffer = VirtualAlloc((LPVOID)0x0,DVar1 - local_30[0],0x3000,4), lpBuffer != (LPVOID)0x0))
    {
      BVar2 = ReadFile(hFile,lpBuffer,DVar1 - local_30[0],local_30,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        pHVar3 = CreateDIBPatternBrushPt(lpBuffer,0);
      }
      VirtualFree(lpBuffer,0,0x8000);
    }
    CloseHandle(hFile);
  }
  return pHVar3;
}



/* 4059cbbc FUN_4059cbbc */

/* Boundary evidence: original MIPS .pdata 4059cbbc..4059cee7. Semantic name remains unreviewed. */

void FUN_4059cbbc(int param_1,HDC param_2)

{
  int iVar1;
  int iVar2;
  DWORD color;
  DWORD color_00;
  LRESULT LVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  HRGN hrgn;
  HBRUSH pHVar5;
  int iVar6;
  int iVar7;
  HANDLE h_00;
  int local_60;
  int local_5c;
  tagRECT local_58;
  tagRECT local_48;
  undefined4 local_38;
  int local_34;
  int local_30;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    iVar1 = FUN_40588620();
    iVar2 = FUN_40588608();
    color = GetSysColor(0x40000001);
    color_00 = GetSysColor(0x40000019);
    local_48.left = 0;
    memset(&local_48.top,0,0xc);
    local_58.left = 0;
    memset(&local_58.top,0,0xc);
    GetClientRect((HWND)**(undefined4 **)(param_1 + 0x44),&local_48);
    SetBkColor(param_2,color);
    if (color == color_00) {
      color_00 = GetSysColor(0x4000001a);
    }
    SetTextColor(param_2,color_00);
    h_00 = *(HANDLE *)(param_1 + 0x7c);
    if (h_00 == (HANDLE)0x0) {
      pHVar5 = GetSysColorBrush(0x40000001);
    }
    else {
      if ((iVar1 != 0) || (iVar2 == 0)) {
        local_38 = 0;
        memset(&local_34,0,0x14);
        GetObjectW(h_00,0x18,&local_38);
        hdc = CreateCompatibleDC(param_2);
        h = SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x7c));
        if (iVar2 == 0) {
          iVar1 = GetSystemMetrics(0);
          if (iVar1 < 0) {
            iVar1 = iVar1 + 1;
          }
          iVar6 = local_34;
          if (local_34 < 0) {
            iVar6 = local_34 + 1;
          }
          iVar4 = GetSystemMetrics(1);
          if (iVar4 < 0) {
            iVar4 = iVar4 + 1;
          }
          iVar7 = local_30;
          if (local_30 < 0) {
            iVar7 = local_30 + 1;
          }
          SetRect(&local_58,0,0,local_34,local_30);
          OffsetRect(&local_58,(iVar1 >> 1) - (iVar6 >> 1),(iVar4 >> 1) - (iVar7 >> 1));
          BitBlt(param_2,local_58.left,local_58.top,local_34,local_30,hdc,0,0,0xcc0020);
        }
        else {
          BitBlt(param_2,0,0,local_34,local_30,hdc,0,0,0xcc0020);
        }
        SelectObject(hdc,h);
        DeleteDC(hdc);
        hrgn = CreateRectRgnIndirect(&local_48);
        SelectClipRgn(param_2,hrgn);
        DeleteObject(hrgn);
        if (iVar2 != 0) {
          return;
        }
        ExcludeClipRect(param_2,local_58.left,local_58.top,local_58.right,local_58.bottom);
        pHVar5 = GetSysColorBrush(0x40000001);
        FillRect(param_2,&local_48,pHVar5);
        SelectClipRgn(param_2,(HRGN)0x0);
        return;
      }
      LVar3 = SendMessageW((HWND)**(undefined4 **)(param_1 + 0x44),0x1029,0,(LPARAM)&local_60);
      if (LVar3 != 0) {
        SetBrushOrgEx(param_2,local_60,local_5c,(LPPOINT)0x0);
      }
      pHVar5 = *(HBRUSH *)(param_1 + 0x7c);
    }
    FillRect(param_2,&local_48,pHVar5);
  }
  return;
}



/* 4059cee8 FUN_4059cee8 */

/* Boundary evidence: original MIPS .pdata 4059cee8..4059cf7f. Semantic name remains unreviewed. */

void FUN_4059cee8(int param_1,int param_2)

{
  int iVar1;
  LPWSTR pWVar2;
  
  FUN_405969dc(param_1,param_2);
  if (((((*(uint *)(param_1 + 0x58) & 0x20) != 0) && (iVar1 = FUN_405885e4(), iVar1 != 0)) &&
      (param_2 != 0)) &&
     ((((*(uint *)(param_2 + 0xc) & 1) != 0 && (*(char **)(param_2 + 0x2c) != (char *)0x0)) &&
      (iVar1 = FUN_40581188(*(char **)(param_2 + 0x2c)), iVar1 == 0)))) {
    pWVar2 = PathFindExtensionW(*(LPCWSTR *)(param_2 + 0x20));
    *pWVar2 = L'\0';
  }
  return;
}



/* 4059cf80 FUN_4059cf80 */

/* Boundary evidence: original MIPS .pdata 4059cf80..4059cfeb. Semantic name remains unreviewed. */

undefined4 FUN_4059cf80(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1[0x16] & 0x20U) == 0) {
LAB_4059cfbc:
    uVar1 = FUN_40596c74(param_1,param_2);
  }
  else {
    if ((param_2 == 0x3e9) || (param_2 == 0x451)) {
      (**(code **)(*param_1 + 0x74))(param_1,0x14,0);
    }
    else if (param_2 != 0x1061) goto LAB_4059cfbc;
    uVar1 = 0;
  }
  return uVar1;
}



/* 4059cfec FUN_4059cfec */

/* Boundary evidence: original MIPS .pdata 4059cfec..4059d08f. Semantic name remains unreviewed. */

int FUN_4059cfec(int *param_1,HMENU param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_405974e8(param_1,param_2,param_3);
  if ((((iVar1 == 0) && ((param_1[0x16] & 0x20U) != 0)) && (param_3 != (int *)0x0)) &&
     (*param_3 == 0)) {
    RemoveMenu(param_2,0,0x400);
    RemoveMenu(param_2,0,0x400);
  }
  return iVar1;
}



/* 4059d090 FUN_4059d090 */

/* Boundary evidence: original MIPS .pdata 4059d090..4059d48b. Semantic name remains unreviewed. */

undefined4 FUN_4059d090(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HDC hdc;
  HDC hdc_00;
  HBITMAP pHVar5;
  HGDIOBJ h;
  HBRUSH pHVar6;
  HWND hWnd;
  HBITMAP ho;
  undefined4 uVar7;
  int *local_298 [2];
  tagRECT local_290;
  tagRECT local_280;
  undefined4 local_270;
  undefined1 auStack_26c [16];
  int local_25c;
  int local_258;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  uVar7 = 1;
  if (((param_1[0x16] & 0x20U) == 0) || (param_2 == 0)) goto LAB_4059d45c;
  if (param_2 == 0x3002) {
    iVar2 = GetSystemMetrics(0x4f);
    iVar3 = GetSystemMetrics(0x4e);
    MoveWindow((HWND)param_1[10],0,0,iVar3,iVar2,1);
    (**(code **)(*param_1 + 0x74))(param_1,0x2f,0);
    (**(code **)(*param_1 + 0x74))(param_1,0x14,0);
    goto LAB_4059d45c;
  }
  if (param_2 == 0x14) {
    FUN_40588820();
    FUN_40588534(awStack_230,0x104);
    if ((HGDIOBJ)param_1[0x1f] != (HGDIOBJ)0x0) {
      DeleteObject((HGDIOBJ)param_1[0x1f]);
      param_1[0x1f] = 0;
    }
    FUN_4059c864((int)param_1);
    iVar2 = FUN_40588620();
    if (iVar2 == 0) {
      iVar2 = FUN_40588608();
      if (iVar2 == 0) {
        pHVar6 = (HBRUSH)SHLoadDIBitmap(awStack_230);
      }
      else {
        pHVar6 = FUN_4059ca64(param_1,awStack_230);
      }
      param_1[0x1f] = (int)pHVar6;
    }
    else {
      ho = (HBITMAP)0x0;
      iVar2 = FUN_4059c928((int)param_1,awStack_230);
      if (iVar2 == 0) {
        ho = (HBITMAP)SHLoadDIBitmap(awStack_230);
      }
      else {
        local_298[0] = (int *)0x0;
        iVar2 = (**(code **)(*(int *)param_1[0x20] + 0x10))
                          ((int *)param_1[0x20],awStack_230,local_298);
        piVar1 = local_298[0];
        if ((iVar2 < 0) || (local_298[0] == (int *)0x0)) goto LAB_4059d38c;
        local_270 = 0;
        memset(auStack_26c,0,0x3c);
        iVar4 = (**(code **)(*piVar1 + 0x10))(piVar1,&local_270);
        iVar3 = local_258;
        iVar2 = local_25c;
        if ((-1 < iVar4) && ((local_25c != 0 && (local_258 != 0)))) {
          local_290.left = 0;
          memset(&local_290.top,0,0xc);
          SetRect(&local_290,0,0,iVar2,iVar3);
          hdc = GetDC((HWND)param_1[10]);
          if (hdc != (HDC)0x0) {
            hdc_00 = CreateCompatibleDC(hdc);
            if (hdc_00 != (HDC)0x0) {
              pHVar5 = CreateCompatibleBitmap(hdc,local_25c,local_258);
              ho = (HBITMAP)0x0;
              if (pHVar5 != (HBITMAP)0x0) {
                h = SelectObject(hdc_00,pHVar5);
                if ((h == (HGDIOBJ)0x0) ||
                   (iVar2 = (**(code **)(*local_298[0] + 0x18))(local_298[0],hdc_00,&local_290,0),
                   iVar2 < 0)) {
                  DeleteObject(pHVar5);
                  ho = (HBITMAP)0x0;
                }
                else {
                  ho = SelectObject(hdc_00,h);
                }
              }
              DeleteDC(hdc_00);
            }
            ReleaseDC((HWND)param_1[10],hdc);
          }
        }
        (**(code **)(*local_298[0] + 8))();
      }
      if (ho != (HBITMAP)0x0) {
        pHVar5 = FUN_4059c638((int)param_1,ho);
        param_1[0x1f] = (int)pHVar5;
        DeleteObject(ho);
      }
    }
LAB_4059d38c:
    iVar2 = (**(code **)(*param_1 + 0x8c))(param_1,0x16);
    if (iVar2 < 0) goto LAB_4059d45c;
  }
  else {
    if (param_2 != 0x2f) goto LAB_4059d45c;
    local_280.left = 0;
    memset(&local_280.top,0,0xc);
    GetClientRect(*(HWND *)param_1[0x11],&local_280);
    hWnd = FindWindowW(L"HHTaskBar",(LPCWSTR)0x0);
    if (hWnd != (HWND)0x0) {
      local_290.left = 0;
      memset(&local_290.top,0,0xc);
      GetClientRect(hWnd,&local_290);
      local_280.bottom = (local_280.bottom - local_290.bottom) + local_290.top;
      if ((undefined4 *)param_1[0x11] != (undefined4 *)0x0) {
        SendMessageW(*(HWND *)param_1[0x11],0x1041,1,(LPARAM)&local_280);
        FUN_405a4a60((undefined4 *)param_1[0x11]);
      }
    }
  }
  uVar7 = 0;
LAB_4059d45c:
  FUN_405a7174(local_28);
  return uVar7;
}



/* 4059d48c FUN_4059d48c */

/* Boundary evidence: original MIPS .pdata 4059d48c..4059d547. Semantic name remains unreviewed. */

void FUN_4059d48c(int param_1)

{
  DWORD DVar1;
  LPARAM LVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    if ((*(uint *)(param_1 + 0x58) & 0x20) == 0) {
      FUN_405977e4(param_1);
    }
    else {
      DVar1 = GetSysColor(0x40000001);
      uVar3 = ((DVar1 & 0xffff) >> 8) + (DVar1 >> 0x10 & 0xff) + (DVar1 & 0xff);
      uVar4 = 0;
      if (uVar3 != 0) {
        uVar4 = uVar3 / 3;
      }
      if (uVar4 < 0x81) {
        LVar2 = 0xffffff;
      }
      else {
        LVar2 = 0;
      }
      FUN_405a4888(*(undefined4 **)(param_1 + 0x44),DVar1,LVar2,DVar1);
    }
  }
  return;
}



/* 4059d548 FUN_4059d548 */

/* Boundary evidence: original MIPS .pdata 4059d548..4059d6bb. Semantic name remains unreviewed. */

undefined4 FUN_4059d548(int *param_1,int param_2)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  HRESULT HVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint local_378 [2];
  undefined4 local_370;
  undefined1 auStack_36c [4];
  int local_368;
  WCHAR *local_360;
  undefined1 auStack_354 [36];
  STRRET local_330;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  uVar6 = 0;
  if ((param_2 == 1) && ((param_1[0x16] & 0x20U) != 0)) {
    local_378[0] = 0;
    puVar2 = (undefined4 *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)local_378);
    if (puVar2 != (undefined4 *)0x0) {
      memset(auStack_36c,0,0x38);
      local_330.uType = 0;
      memset(&local_330.u,0,0x104);
      local_368 = param_1[10];
      puVar1 = auStack_354 + 3;
      uVar5 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar5) =
           *(uint *)(puVar1 + -uVar5) & -1 << (uVar5 + 1) * 8 | 1U >> (3 - uVar5) * 8;
      uVar5 = 0;
      local_370 = 0x3c;
      auStack_354._0_4_ = 1;
      puVar4 = puVar2;
      if (local_378[0] != 0) {
        do {
          (**(code **)(*(int *)param_1[0x1a] + 0x2c))
                    ((int *)param_1[0x1a],*puVar4,0x8000,&local_330);
          HVar3 = StrRetToBufW(&local_330,(LPCITEMIDLIST)*puVar4,aWStack_228,0x104);
          if (-1 < HVar3) {
            local_360 = aWStack_228;
            ShellExecuteEx(&local_370);
          }
          uVar5 = uVar5 + 1;
          puVar4 = puVar4 + 1;
        } while (uVar5 < local_378[0]);
      }
      (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,puVar2);
    }
  }
  else {
    uVar6 = FUN_40597a6c(param_1,param_2);
  }
  FUN_405a7174(local_20);
  return uVar6;
}



/* 4059d6bc FUN_4059d6bc */

/* Boundary evidence: original MIPS .pdata 4059d6bc..4059d707. Semantic name remains unreviewed. */

void FUN_4059d6bc(int param_1,int param_2,int param_3)

{
  if ((*(int *)(param_1 + 0x44) != 0) &&
     (FUN_40597e44(param_1,param_2,param_3), (*(uint *)(param_1 + 0x58) & 0x20) != 0)) {
    FUN_405a3570(*(undefined4 **)(param_1 + 0x44));
  }
  return;
}



/* 4059d708 FUN_4059d708 */

/* Boundary evidence: original MIPS .pdata 4059d708..4059d73b. Semantic name remains unreviewed. */

undefined4 FUN_4059d708(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1[0x16] & 0x20U) == 0) {
    uVar1 = FUN_40597e6c(param_1,param_2);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 4059d73c FUN_4059d73c */

/* Boundary evidence: original MIPS .pdata 4059d73c..4059d7d3. Semantic name remains unreviewed. */

undefined4 FUN_4059d73c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  HWND local_18 [2];
  
  if ((*(uint *)(param_1 + 0x58) & 0x20) == 0) {
    if (*(int *)(param_1 + 0x70) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_405982b4(param_1);
      iVar1 = (**(code **)(**(int **)(param_1 + 0x70) + 0x34))(*(int **)(param_1 + 0x70),2,local_18)
      ;
      if (-1 < iVar1) {
        SendMessageW(local_18[0],0x401,0x1061,0);
      }
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 4059d7d4 FUN_4059d7d4 */

/* Boundary evidence: original MIPS .pdata 4059d7d4..4059d8c3. Semantic name remains unreviewed. */

void FUN_4059d7d4(int *param_1,undefined4 *param_2,LRESULT param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x1c];
  if (((param_1[0x16] & 0x20U) == 0) && (piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 4))(piVar1);
    FUN_405985e0(param_1,param_2,param_3,param_4);
    if (param_4 != 0) {
      (**(code **)(*piVar1 + 0x38))(piVar1,1,0x40b,4,&DAT_4057112c,0);
      (**(code **)(*piVar1 + 0x38))(piVar1,1,0x40f,4,0,0);
    }
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



/* 4059d8c4 FUN_4059d8c4 */

/* Boundary evidence: original MIPS .pdata 4059d8c4..4059d9a3. Semantic name remains unreviewed. */

HRESULT FUN_4059d8c4(int param_1,int *param_2,int param_3,int *param_4,int *param_5)

{
  HRESULT HVar1;
  
  if (param_4 == (int *)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else {
    HVar1 = FUN_40599524(param_1,param_2,param_3,(int)param_4,param_5);
    if ((((param_2 != (int *)0x0) && (*param_2 == 0x10a7df2f)) && (param_2[1] == 0x4eec61ee)) &&
       ((param_2[2] == -0x7911f143 && (param_2[3] == 0x18564efe)))) {
      for (; param_3 != 0; param_3 = param_3 + -1) {
        if (*param_4 == 0x1061) {
          param_4[1] = 0;
        }
        param_4 = param_4 + 2;
      }
    }
  }
  return HVar1;
}



/* 4059d9a4 FUN_4059d9a4 */

/* Boundary evidence: original MIPS .pdata 4059d9a4..4059da43. Semantic name remains unreviewed. */

void FUN_4059d9a4(int *param_1)

{
  *param_1 = (int)&PTR_FUN_4057262c;
  param_1[1] = (int)&PTR_LAB_40572618;
  param_1[2] = (int)&PTR_LAB_405725f0;
  param_1[3] = (int)&PTR_LAB_405725e0;
  param_1[4] = (int)&PTR_LAB_405725cc;
  param_1[5] = (int)&PTR_LAB_405725b0;
  param_1[6] = (int)&PTR_LAB_405725a0;
  param_1[7] = (int)&PTR_LAB_40572588;
  if ((HGDIOBJ)param_1[0x1f] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0x1f]);
  }
  FUN_4059c8d0((int)param_1);
  FUN_4059a928(param_1);
  return;
}



/* 4059da44 FUN_4059da44 */

/* Boundary evidence: original MIPS .pdata 4059da44..4059db8b. Semantic name remains unreviewed. */

LRESULT FUN_4059da44(HWND param_1,UINT param_2,HDC param_3,LPARAM param_4)

{
  HWND pHVar1;
  LONG LVar2;
  LRESULT LVar3;
  
  pHVar1 = GetParent(param_1);
  LVar2 = GetWindowLongW(pHVar1,-0x15);
  if (param_2 == 0x14) {
    FUN_4059cbbc(LVar2,param_3);
    return 0;
  }
  if (param_2 == 0x100) {
    if (param_3 == (HDC)0x9) {
      if (((*(uint *)(LVar2 + 0x58) & 0x20) != 0) && ((*(uint *)(LVar2 + 0x54) & 1) == 0)) {
        pHVar1 = FindWindowW(L"HHTaskBar",(LPCWSTR)0x0);
        SetForegroundWindow(pHVar1);
        return 0;
      }
    }
    else if ((param_3 == (HDC)0x70) &&
            (pHVar1 = FindWindowW(L"HHTaskBar",(LPCWSTR)0x0), pHVar1 != (HWND)0x0)) {
      PostMessageW(pHVar1,0x100,0x70,param_4);
      return 0;
    }
  }
  LVar3 = CallWindowProcW(*(WNDPROC *)(LVar2 + 0x78),param_1,param_2,(WPARAM)param_3,param_4);
  return LVar3;
}



/* 4059db8c FUN_4059db8c */

/* Boundary evidence: original MIPS .pdata 4059db8c..4059de4f. Semantic name remains unreviewed. */

undefined4
FUN_4059db8c(int *param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5,
            undefined4 *param_6)

{
  ATOM AVar1;
  LANGID LVar2;
  undefined4 uVar3;
  BOOL BVar4;
  undefined2 extraout_var;
  HWND pHVar5;
  int iVar6;
  LONG LVar7;
  ushort uVar8;
  DWORD dwExStyle;
  tagWNDCLASSW local_48;
  
  if ((((param_3 == (int *)0x0) || (param_4 == (int *)0x0)) || (param_5 == (int *)0x0)) ||
     (param_6 == (undefined4 *)0x0)) {
    return 0x80070057;
  }
  *param_6 = 0;
  if ((param_3[1] & 0x20U) == 0) {
    uVar3 = FUN_4059b740(param_1,param_2,param_3,param_4,param_5,param_6);
    return uVar3;
  }
  if (param_1[10] != 0) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  local_48.style = 0;
  memset(&local_48.lpfnWndProc,0,0x24);
  BVar4 = GetClassInfoW(DAT_405aa0c0,L"DefShellView",&local_48);
  if (BVar4 == 0) {
    local_48.style = 3;
    local_48.lpfnWndProc = FUN_4059abd4;
    local_48.hInstance = DAT_405aa0c0;
    local_48.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_48.hbrBackground = (HBRUSH)0x40000006;
    local_48.lpszClassName = L"DesktopExplorerWindow";
    AVar1 = RegisterClassW(&local_48);
    if (CONCAT22(extraout_var,AVar1) == 0) {
      return 0x80004005;
    }
    param_1[0x1b] = (int)param_4;
    param_1[0x16] = param_3[1];
    dwExStyle = 0;
    LVar2 = GetUserDefaultUILanguage();
    uVar8 = LVar2 & 0x3ff;
    if (((uVar8 == 1) || (uVar8 == 0x29)) || ((uVar8 == 0xd || (uVar8 == 0x20)))) {
      dwExStyle = 0x400000;
    }
    pHVar5 = CreateWindowExW(dwExStyle,L"DesktopExplorerWindow",(LPCWSTR)0x0,0x6000000,*param_5,
                             param_5[1],param_5[2] - *param_5,param_5[3] - param_5[1],(HWND)0x0,
                             (HMENU)0x0,DAT_405aa0c0,param_1);
    *param_6 = pHVar5;
    if (pHVar5 != (HWND)0x0) {
      (**(code **)(*(int *)param_1[0x1b] + 4))();
      iVar6 = FUN_405a4924((undefined4 *)param_1[0x11],1);
      param_1[0x17] = iVar6;
      LVar7 = SetWindowLongW(*(HWND *)param_1[0x11],-4,0x4059da44);
      param_1[0x1e] = LVar7;
      if (LVar7 != 0) {
        FUN_40586a28(DAT_405aa0d4,0);
        FUN_4058580c(DAT_405aa0d4,*(undefined4 *)param_1[0x11]);
        FUN_40583798(DAT_405aa0d4);
        (**(code **)(*param_1 + 0x74))(param_1,0x14,0);
        ShowWindow((HWND)*param_6,5);
        return 0;
      }
    }
    UnregisterClassW(L"DesktopExplorerWindow",DAT_405aa0c0);
    return 0;
  }
  return 0x80004005;
}



/* 4059de50 FUN_4059de50 */

/* Boundary evidence: original MIPS .pdata 4059de50..4059de9b. Semantic name remains unreviewed. */

int * FUN_4059de50(int *param_1,uint param_2)

{
  FUN_4059d9a4(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4059de9c FUN_4059de9c */

/* Boundary evidence: original MIPS .pdata 4059de9c..4059df73. Semantic name remains unreviewed. */

undefined4 FUN_4059de9c(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    if ((((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
         (param_2[3] == 0x46000000)) ||
        (((*param_2 == 0x214e4 && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) &&
       (*param_3 = (int)param_1, param_1 != (int *)0x0)) {
      (**(code **)(*param_1 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4059df74 FUN_4059df74 */

/* Boundary evidence: original MIPS .pdata 4059df74..4059e003. Semantic name remains unreviewed. */

undefined4 FUN_4059df74(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == (int *)0x0) || (*param_2 != 0x24)) {
    uVar1 = 0x80004005;
  }
  else {
    if (((param_2[3] != 0) && (*(short *)((int)param_2 + 0xe) == 0)) &&
       (*(uint *)(param_1 + 4) == (param_2[3] & 0xffffU))) {
      FUN_40586a28(DAT_405aa0d4,0);
      FUN_40584468(DAT_405aa0d4,1);
      FUN_40583798(DAT_405aa0d4);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 4059e004 FUN_4059e004 */

/* Boundary evidence: original MIPS .pdata 4059e004..4059e0d7. Semantic name remains unreviewed. */

undefined4 FUN_4059e004(int param_1,HMENU param_2,UINT param_3,UINT param_4)

{
  bool bVar1;
  LPCWSTR lpNewItem;
  BOOL BVar2;
  undefined3 extraout_var;
  
  lpNewItem = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x301c,(LPWSTR)0x0,0);
  if ((lpNewItem != (LPCWSTR)0x0) &&
     (BVar2 = InsertMenuW(param_2,param_3,0x400,param_4,lpNewItem), BVar2 != 0)) {
    *(UINT *)(param_1 + 4) = param_4;
    FUN_40586a28(DAT_405aa0d4,0);
    bVar1 = FUN_40584f40();
    if (CONCAT31(extraout_var,bVar1) != 0) {
      EnableMenuItem(param_2,param_4,1);
    }
    FUN_40583798(DAT_405aa0d4);
    return 1;
  }
  return 0x80004005;
}



/* 4059e0d8 FUN_4059e0d8 */

/* Boundary evidence: original MIPS .pdata 4059e0d8..4059e10f. Semantic name remains unreviewed. */

int FUN_4059e0d8(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2] + -1;
  param_1[2] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_40572708;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 4059e110 FUN_4059e110 */

undefined4 * FUN_4059e110(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40572708;
  param_1[1] = 0;
  param_1[2] = 1;
  return param_1;
}



/* 4059e130 FUN_4059e130 */

/* Boundary evidence: original MIPS .pdata 4059e130..4059e213. Semantic name remains unreviewed. */

undefined4 FUN_4059e130(int param_1)

{
  HRESULT HVar1;
  void *_Dst;
  BOOL BVar2;
  size_t local_20 [2];
  
  local_20[0] = 0;
  HVar1 = StringCbLengthW(&DAT_405a9aa4,0x208,local_20);
  if (-1 < HVar1) {
    local_20[0] = local_20[0] + 2;
    _Dst = (void *)(**(code **)(*DAT_405aa0c8 + 0xc))();
    *(void **)(param_1 + 8) = _Dst;
    if (_Dst == (void *)0x0) {
      HVar1 = -0x7ff8fff2;
    }
    else {
      memcpy(_Dst,&DAT_405a9aa4,local_20[0]);
      BVar2 = PathFileExistsW(*(LPCWSTR *)(param_1 + 8));
      if (BVar2 == 0) {
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,*(undefined4 *)(param_1 + 8));
        HVar1 = -0x7fffbffb;
        *(undefined4 *)(param_1 + 8) = 0;
      }
    }
    if (-1 < HVar1) {
      return 1;
    }
  }
  return 0;
}



/* 4059e214 FUN_4059e214 */

/* Boundary evidence: original MIPS .pdata 4059e214..4059e2eb. Semantic name remains unreviewed. */

undefined4 FUN_4059e214(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    if ((((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
         (param_2[3] == 0x46000000)) ||
        (((*param_2 == 0x122 && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) &&
       (*param_3 = (int)param_1, param_1 != (int *)0x0)) {
      (**(code **)(*param_1 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4059e2ec FUN_4059e2ec */

/* Boundary evidence: original MIPS .pdata 4059e2ec..4059e35b. Semantic name remains unreviewed. */

undefined4 * FUN_4059e2ec(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40572720;
  if (param_1[2] != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4059e35c FUN_4059e35c */

/* Boundary evidence: original MIPS .pdata 4059e35c..4059e527. Semantic name remains unreviewed. */

undefined4 FUN_4059e35c(int param_1,int *param_2)

{
  int iVar1;
  HRESULT HVar2;
  DWORD DVar3;
  UINT UVar4;
  undefined4 uVar5;
  int in_stack_00000014;
  undefined2 local_270 [2];
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_258;
  undefined4 *local_254 [3];
  int local_248 [6];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  uVar5 = 0x8000ffff;
  if ((param_2 == (int *)0x0) || (in_stack_00000014 == 0)) {
    uVar5 = 0x80070057;
    goto LAB_4059e4f8;
  }
  if (((*(PCNZWCH *)(param_1 + 8) == (PCNZWCH)0x0) ||
      (iVar1 = CompareStringW(0x800,1,&DAT_405a9aa4,-1,*(PCNZWCH *)(param_1 + 8),-1), iVar1 != 2))
     || (HVar2 = StringCchCopyW(awStack_230,0x104,*(STRSAFE_LPCWSTR *)(param_1 + 8)), HVar2 < 0))
  goto LAB_4059e4f8;
  DVar3 = GetFileAttributesW(awStack_230);
  if ((DVar3 == 0xffffffff) || ((DVar3 & 0x10) == 0)) {
LAB_4059e4e4:
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  else {
    local_270[0] = 0;
    memset(&local_26c,0,0x10);
    local_258 = 0;
    memset(local_254,0,8);
    FUN_405a0a00(local_248);
    UVar4 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
    local_270[0] = (undefined2)UVar4;
    local_26c = 0;
    local_268 = 1;
    local_264 = 0xffffffff;
    local_260 = 1;
    iVar1 = (**(code **)(*param_2 + 0xc))(param_2,local_270,&local_258);
    if ((iVar1 < 0) || (iVar1 = FUN_405a0d88(local_254[0],local_248), iVar1 == 0))
    goto LAB_4059e4e4;
    *(undefined4 *)(param_1 + 0xc) = 2;
    if (local_248[0] != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    FUN_405a0a1c((int)local_248);
  }
  uVar5 = 0;
LAB_4059e4f8:
  FUN_405a7174(local_28);
  return uVar5;
}



/* 4059e560 FUN_4059e560 */

/* Boundary evidence: original MIPS .pdata 4059e560..4059e697. Semantic name remains unreviewed. */

undefined4 FUN_4059e560(int *param_1,int *param_2)

{
  UINT UVar1;
  int iVar2;
  undefined4 uVar3;
  uint *in_stack_00000014;
  undefined4 local_50;
  undefined4 *local_4c [3];
  undefined2 local_40 [2];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 auStack_28 [6];
  
  if ((param_2 == (int *)0x0) || (in_stack_00000014 == (uint *)0x0)) {
    uVar3 = 0x80070057;
  }
  else {
    local_40[0] = 0;
    memset(&local_3c,0,0x10);
    local_50 = 0;
    memset(local_4c,0,8);
    FUN_405a0a00(auStack_28);
    UVar1 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
    local_34 = 0xffffffff;
    local_40[0] = (undefined2)UVar1;
    local_3c = 0;
    local_38 = 1;
    local_30 = 1;
    iVar2 = (**(code **)(*param_2 + 0xc))(param_2,local_40,&local_50);
    if ((-1 < iVar2) && (iVar2 = FUN_405a0d88(local_4c[0],auStack_28), iVar2 != 0)) {
      if ((*in_stack_00000014 & 2) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_405a2004(auStack_28,3,(STRSAFE_PCNZWCH)0x0);
      }
      FUN_405a0a1c((int)auStack_28);
      (**(code **)(*param_1 + 0x14))(param_1);
      if (iVar2 != 0) {
        return 0;
      }
    }
    uVar3 = 0x80004005;
  }
  return uVar3;
}



/* 4059e698 FUN_4059e698 */

/* Boundary evidence: original MIPS .pdata 4059e698..4059e6c7. Semantic name remains unreviewed. */

int FUN_4059e698(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    FUN_4059e2ec(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 4059e6c8 FUN_4059e6c8 */

undefined4 * FUN_4059e6c8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40572720;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = 1;
  return param_1;
}



/* 4059e6ec FUN_4059e6ec */

/* Boundary evidence: original MIPS .pdata 4059e6ec..4059e747. Semantic name remains unreviewed. */

undefined4 FUN_4059e6ec(int param_1,STRSAFE_LPCWSTR param_2)

{
  HRESULT HVar1;
  BOOL BVar2;
  
  if (param_2 != (STRSAFE_LPCWSTR)0x0) {
    HVar1 = StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 8),0x104,param_2);
    if ((-1 < HVar1) && (BVar2 = PathFileExistsW((STRSAFE_LPWSTR)(param_1 + 8)), BVar2 != 0)) {
      return 1;
    }
  }
  return 0;
}



/* 4059e748 FUN_4059e748 */

/* Boundary evidence: original MIPS .pdata 4059e748..4059e81f. Semantic name remains unreviewed. */

undefined4 FUN_4059e748(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    if ((((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
         (param_2[3] == 0x46000000)) ||
        (((*param_2 == 0x122 && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) &&
       (*param_3 = (int)param_1, param_1 != (int *)0x0)) {
      (**(code **)(*param_1 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4059e820 FUN_4059e820 */

/* Boundary evidence: original MIPS .pdata 4059e820..4059e84f. Semantic name remains unreviewed. */

int FUN_4059e820(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 4) + -1;
  *(int *)((int)param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 4059e850 FUN_4059e850 */

/* Boundary evidence: original MIPS .pdata 4059e850..4059ea3b. Semantic name remains unreviewed. */

undefined4 FUN_4059e850(int param_1,int *param_2)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  LPCWSTR lpFileName;
  int in_stack_00000014;
  undefined2 local_270 [2];
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_258;
  undefined4 *local_254 [3];
  undefined4 auStack_248 [2];
  LPCITEMIDLIST local_240;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((param_2 == (int *)0x0) || (in_stack_00000014 == 0)) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80070057;
  }
  lpFileName = (LPCWSTR)(param_1 + 8);
  DVar1 = GetFileAttributesW(lpFileName);
  if (DVar1 != 0xffffffff) {
    iVar2 = PathIsLink(lpFileName);
    if (iVar2 != 0) {
      iVar2 = SHGetShortcutTarget(lpFileName,lpFileName,0x104);
      if (iVar2 == 0) {
        DVar1 = 0xffffffff;
      }
      else {
        PathRemoveQuotesAndArgs(lpFileName);
        DVar1 = GetFileAttributesW(lpFileName);
      }
    }
    if ((DVar1 != 0xffffffff) && ((DVar1 & 0x10) != 0)) {
      local_270[0] = 0;
      memset(&local_26c,0,0x10);
      local_258 = 0;
      memset(local_254,0,8);
      FUN_405a0a00(auStack_248);
      UVar3 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
      local_270[0] = (undefined2)UVar3;
      local_26c = 0;
      local_268 = 1;
      local_264 = 0xffffffff;
      local_260 = 1;
      iVar2 = (**(code **)(*param_2 + 0xc))(param_2,local_270,&local_258);
      if ((-1 < iVar2) && (iVar2 = FUN_405a0d88(local_254[0],auStack_248), iVar2 != 0)) {
        iVar2 = SHGetPathFromIDList(local_240,awStack_230);
        if (iVar2 == 0) {
          *(undefined4 *)(param_1 + 0x210) = 0;
        }
        else {
          iVar2 = PathIsSameDevice(awStack_230,lpFileName);
          if (iVar2 == 0) {
            *(undefined4 *)(param_1 + 0x210) = 1;
          }
          else {
            *(undefined4 *)(param_1 + 0x210) = 2;
          }
        }
        FUN_405a0a1c((int)auStack_248);
        goto LAB_4059e9f8;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x210) = 0;
LAB_4059e9f8:
  FUN_405a7174(local_28);
  return 0;
}



/* 4059ea74 FUN_4059ea74 */

/* Boundary evidence: original MIPS .pdata 4059ea74..4059ed1b. Semantic name remains unreviewed. */

undefined4 FUN_4059ea74(int *param_1,int *param_2)

{
  bool bVar1;
  UINT UVar2;
  int iVar3;
  int iVar4;
  HRESULT HVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *in_stack_00000014;
  uint local_370 [2];
  LPCITEMIDLIST local_368;
  undefined2 local_358 [2];
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_340;
  undefined4 *local_33c [3];
  wchar_t awStack_330 [128];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if ((param_2 == (int *)0x0) || (in_stack_00000014 == (uint *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80070057;
  }
  local_358[0] = 0;
  memset(&local_354,0,0x10);
  local_340 = 0;
  memset(local_33c,0,8);
  FUN_405a0a00(local_370);
  UVar2 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
  bVar1 = true;
  local_358[0] = (undefined2)UVar2;
  local_354 = 0;
  local_350 = 1;
  local_34c = 0xffffffff;
  local_348 = 1;
  iVar3 = (**(code **)(*param_2 + 0xc))(param_2,local_358,&local_340);
  if ((iVar3 < 0) || (iVar3 = FUN_405a0d88(local_33c[0],local_370), iVar3 == 0)) {
    FUN_405a7174(local_28);
    return 0x80004005;
  }
  iVar3 = SHGetPathFromIDList(local_368,awStack_230);
  if (iVar3 == 0) {
LAB_4059ec30:
    iVar3 = 0;
  }
  else {
    iVar3 = CompareStringW(0x400,1,awStack_230,-1,(PCNZWCH)(param_1 + 2),-1);
    if (iVar3 == 2) {
      if ((*in_stack_00000014 & 5) == 0) {
        if ((*in_stack_00000014 & 2) != 0) {
          iVar3 = LoadStringW(DAT_405aa0c0,0x3010,(LPWSTR)0x0,0);
          iVar4 = LoadStringW(DAT_405aa0c0,0x301a,(LPWSTR)0x0,0);
          HVar5 = StringCchPrintfW(awStack_330,0x80,L"%s%s",iVar4,iVar3);
          if (-1 < HVar5) {
            FUN_4058a544((HWND)0x0,(LPCWSTR)0x301a,awStack_330,(LPCWSTR)0x0,0x10);
          }
        }
        goto LAB_4059ec30;
      }
    }
    else {
      bVar1 = false;
    }
    uVar6 = *in_stack_00000014;
    if ((uVar6 & 1) == 0) {
      if ((uVar6 & 2) == 0) {
        if ((uVar6 & 4) == 0) goto LAB_4059ec30;
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      if (bVar1) {
        local_370[0] = local_370[0] | 8;
      }
      iVar3 = 0;
    }
    iVar3 = FUN_405a2004(local_370,iVar3,(STRSAFE_PCNZWCH)(param_1 + 2));
  }
  FUN_405a0a1c((int)local_370);
  (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar3 == 0) {
    uVar7 = 0x80004005;
  }
  else {
    uVar7 = 0;
  }
  FUN_405a7174(local_28);
  return uVar7;
}



/* 4059ed1c FUN_4059ed1c */

undefined4 * FUN_4059ed1c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_4057273c;
  param_1[0x84] = 0;
  param_1[1] = 1;
  return param_1;
}



/* 4059ed3c FUN_4059ed3c */

/* Boundary evidence: original MIPS .pdata 4059ed3c..4059edc7. Semantic name remains unreviewed. */

undefined4 * FUN_4059ed3c(undefined4 *param_1,undefined4 param_2,ushort *param_3)

{
  FUN_4059bc34(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_4057283c;
  param_1[1] = &PTR_LAB_40572828;
  param_1[2] = &PTR_LAB_40572800;
  param_1[3] = &PTR_LAB_405727f0;
  param_1[4] = &PTR_LAB_405727dc;
  param_1[5] = &PTR_LAB_405727c0;
  param_1[6] = &PTR_LAB_405727b0;
  param_1[7] = &PTR_LAB_40572798;
  return param_1;
}



/* 4059edc8 FUN_4059edc8 */

/* Boundary evidence: original MIPS .pdata 4059edc8..4059f0ab. Semantic name remains unreviewed. */

undefined4 FUN_4059edc8(int *param_1,uint param_2)

{
  int *piVar1;
  wchar_t *pszSrc;
  HRESULT HVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  int *piVar6;
  uint uVar7;
  uint local_238;
  INT_PTR local_234;
  wchar_t local_230;
  undefined1 auStack_22e [518];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  if (param_2 < 0x1000) {
LAB_4059f070:
    uVar4 = FUN_40596c74(param_1,param_2);
    FUN_405a7174(local_28);
    return uVar4;
  }
  if (param_2 < 0x1002) goto LAB_4059f060;
  if (param_2 == 0x1002) {
    local_238 = 0;
    piVar1 = (int *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)&local_238);
    if ((piVar1 == (int *)0x0) || (local_238 == 0)) goto LAB_4059f060;
    local_234 = 6;
    if (local_238 == 1) {
      local_230 = L'\0';
      memset(auStack_22e,0,0x206);
      FUN_40586a28(DAT_405aa0d4,0);
      pszSrc = FUN_40584b7c(DAT_405aa0d4,*piVar1);
      FUN_40583798(DAT_405aa0d4);
      if (pszSrc == (wchar_t *)0x0) {
LAB_4059efc8:
        iVar3 = FUN_4058b140(&local_230,(HWND)0x0,0,&local_234);
        goto LAB_4059eff0;
      }
      HVar2 = StringCchCopyW(&local_230,0x104,pszSrc);
      (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,pszSrc);
      if (-1 < HVar2) goto LAB_4059efc8;
    }
    else {
      iVar3 = FUN_4058af5c(local_238,(HWND)0x0,1,&local_234);
LAB_4059eff0:
      if (((-1 < iVar3) && (local_234 == 6)) && (uVar7 = 0, piVar6 = piVar1, local_238 != 0)) {
        do {
          FUN_40586a28(DAT_405aa0d4,0);
          FUN_405865cc(DAT_405aa0d4,*piVar6);
          FUN_40583798(DAT_405aa0d4);
          uVar7 = uVar7 + 1;
          piVar6 = piVar6 + 1;
        } while (uVar7 < local_238);
      }
    }
    pcVar5 = *(code **)(*DAT_405aa0c8 + 0x14);
  }
  else {
    if (param_2 == 0x1003) goto LAB_4059f060;
    if (param_2 != 0x1007) {
      if (param_2 == 0x1008) {
        FUN_40586a28(DAT_405aa0d4,0);
        FUN_405853d8(DAT_405aa0d4);
      }
      else {
        if (param_2 != 0x1009) goto LAB_4059f070;
        FUN_40586a28(DAT_405aa0d4,0);
        FUN_40584468(DAT_405aa0d4,1);
      }
      FUN_40583798(DAT_405aa0d4);
      goto LAB_4059f060;
    }
    local_238 = 0;
    piVar1 = (int *)FUN_405a4104((undefined4 *)param_1[0x11],(LRESULT *)&local_238);
    if ((piVar1 == (int *)0x0) || (local_238 == 0)) goto LAB_4059f060;
    uVar7 = 0;
    piVar6 = piVar1;
    if (local_238 != 0) {
      do {
        FUN_40586a28(DAT_405aa0d4,0);
        FUN_40584fb4(DAT_405aa0d4,*piVar6);
        FUN_40583798(DAT_405aa0d4);
        uVar7 = uVar7 + 1;
        piVar6 = piVar6 + 1;
      } while (uVar7 < local_238);
    }
    pcVar5 = *(code **)(*DAT_405aa0c8 + 0x14);
  }
  (*pcVar5)(DAT_405aa0c8,piVar1);
LAB_4059f060:
  FUN_405a7174(local_28);
  return 0;
}



/* 4059f0ac FUN_4059f0ac */

/* Boundary evidence: original MIPS .pdata 4059f0ac..4059f18f. Semantic name remains unreviewed. */

undefined4 FUN_4059f0ac(int *param_1,HMENU param_2,int *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_3 == (int *)0x0) {
    uVar3 = FUN_405974e8(param_1,param_2,(int *)0x0);
  }
  else {
    piVar2 = (int *)param_3[4];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,param_2,1,0x1100,0x1199,0);
    }
    if (*param_3 == 0) {
      FUN_40586a28(DAT_405aa0d4,0);
      bVar1 = FUN_40584f40();
      if (CONCAT31(extraout_var,bVar1) != 0) {
        EnableMenuItem(param_2,0x1009,1);
      }
      FUN_40583798(DAT_405aa0d4);
      EnableMenuItem(param_2,0x1023,1);
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* 4059f190 FUN_4059f190 */

/* Boundary evidence: original MIPS .pdata 4059f190..4059f21f. Semantic name remains unreviewed. */

undefined4 FUN_4059f190(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    if ((*(int *)(param_2 + 8) != -0x147) && (*(int *)(param_2 + 8) != -0x141)) {
      uVar1 = FUN_4059b408(param_1,param_2);
      return uVar1;
    }
    if ((*(int *)(param_2 + 0xc) < 4) && ((**(uint **)(param_2 + 0x14) & 1) != 0)) {
      (&DAT_405a9a34)[*(int *)(param_2 + 0xc)] = (short)(*(uint **)(param_2 + 0x14))[1];
    }
  }
  return 0;
}



/* 4059f220 FUN_4059f220 */

/* Boundary evidence: original MIPS .pdata 4059f220..4059f333. Semantic name remains unreviewed. */

void FUN_4059f220(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    iVar1 = LoadStringW(DAT_405aa0c0,0x301f,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      FUN_405a34cc(*(undefined4 **)(param_1 + 0x44),iVar1,(int)DAT_405a9a34,0);
    }
    iVar1 = LoadStringW(DAT_405aa0c0,0x3020,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      FUN_405a34cc(*(undefined4 **)(param_1 + 0x44),iVar1,(int)DAT_405a9a36,1);
    }
    iVar1 = LoadStringW(DAT_405aa0c0,0x3023,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      FUN_405a34cc(*(undefined4 **)(param_1 + 0x44),iVar1,(int)DAT_405a9a38,0);
    }
    iVar1 = LoadStringW(DAT_405aa0c0,0x3024,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      FUN_405a34cc(*(undefined4 **)(param_1 + 0x44),iVar1,(int)DAT_405a9a3a,0);
    }
  }
  return;
}



/* 4059f334 FUN_4059f334 */

/* Boundary evidence: original MIPS .pdata 4059f334..4059f357. Semantic name remains unreviewed. */

void FUN_4059f334(void)

{
  LoadMenuW(DAT_405aa0c0,(LPCWSTR)0x4005);
  return;
}



/* 4059f358 FUN_4059f358 */

/* Boundary evidence: original MIPS .pdata 4059f358..4059f447. Semantic name remains unreviewed. */

HRESULT FUN_4059f358(int *param_1,int param_2)

{
  int iVar1;
  HRESULT HVar2;
  ushort *local_20;
  LRESULT local_1c;
  
  HVar2 = 0;
  if (param_2 == 1) {
    local_1c = 0;
    iVar1 = FUN_405a4104((undefined4 *)param_1[0x11],&local_1c);
    if ((iVar1 != 0) && (local_1c != 0)) {
      local_20 = (ushort *)0x0;
      HVar2 = FUN_40587d78((IID *)&DAT_405719b0,(int *)&local_20);
      if (-1 < HVar2) {
        FUN_4058d868(local_20,(int *)param_1[0x1a],param_1,iVar1,1);
        FUN_40580ef4(local_20);
      }
      (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,iVar1);
    }
  }
  else if ((param_2 < 0xb) || (0xd < param_2)) {
    HVar2 = FUN_40597a6c(param_1,param_2);
  }
  return HVar2;
}



/* 4059f448 FUN_4059f448 */

/* Boundary evidence: original MIPS .pdata 4059f448..4059f667. Semantic name remains unreviewed. */

undefined4 FUN_4059f448(int *param_1,int param_2)

{
  HMENU pHVar1;
  HMENU pHVar2;
  HMENU hMenu;
  HMENU hMenu_00;
  LPCWSTR lpNewItem;
  BOOL BVar3;
  
  FUN_40597e6c(param_1,param_2);
  if ((param_2 != 0) && ((HMENU)param_1[0xc] != (HMENU)0x0)) {
    pHVar1 = GetSubMenu((HMENU)param_1[0xc],0);
    if (pHVar1 != (HMENU)0x0) {
      pHVar2 = GetSubMenu(pHVar1,7);
      if (pHVar2 != (HMENU)0x0) {
        RemoveMenu(pHVar1,7,0x400);
        DestroyMenu(pHVar2);
      }
      RemoveMenu(pHVar1,7,0x400);
      RemoveMenu(pHVar1,1,0x400);
      RemoveMenu(pHVar1,0,0x400);
      FUN_405979b4(param_1,pHVar1,(UINT *)&DAT_40572758,3);
    }
    pHVar1 = GetSubMenu((HMENU)param_1[0xc],1);
    if (pHVar1 != (HMENU)0x0) {
      RemoveMenu(pHVar1,0,0x400);
      FUN_405979b4(param_1,pHVar1,(UINT *)&DAT_40572788,1);
    }
    pHVar1 = GetSubMenu((HMENU)param_1[0xc],2);
    if (pHVar1 != (HMENU)0x0) {
      pHVar2 = GetSubMenu(pHVar1,4);
      if (pHVar2 != (HMENU)0x0) {
        RemoveMenu(pHVar1,4,0x400);
        DestroyMenu(pHVar2);
      }
      pHVar2 = LoadMenuW(DAT_405aa0c0,(LPCWSTR)0x4005);
      if (pHVar2 != (HMENU)0x0) {
        hMenu = GetSubMenu(pHVar2,0);
        hMenu_00 = GetSubMenu(hMenu,3);
        RemoveMenu(hMenu,3,0x400);
        DestroyMenu(pHVar2);
        lpNewItem = (LPCWSTR)LoadStringW(DAT_405aa0c0,0x3114,(LPWSTR)0x0,0);
        BVar3 = InsertMenuW(pHVar1,4,0x410,(UINT_PTR)hMenu_00,lpNewItem);
        if (BVar3 == 0) {
          DestroyMenu(hMenu_00);
        }
      }
    }
  }
  return 1;
}



/* 4059f668 FUN_4059f668 */

/* Boundary evidence: original MIPS .pdata 4059f668..4059f7cf. Semantic name remains unreviewed. */

void FUN_4059f668(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  HRESULT HVar1;
  int *piVar2;
  HLOCAL local_20;
  int *local_1c;
  
  local_1c = (int *)0x0;
  local_20 = (HLOCAL)0x0;
  HVar1 = FUN_40587d78((IID *)&DAT_405719b0,(int *)&local_20);
  if (-1 < HVar1) {
    HVar1 = (**(code **)(**(int **)(param_1 + 0x68) + 0x28))
                      (*(int **)(param_1 + 0x68),**(undefined4 **)(param_1 + 0x44),1,&local_20,
                       &DAT_40572b48,0,&local_1c);
    FUN_40580ef4(local_20);
  }
  if (*(int *)(*(int *)(param_1 + 100) + 4) != 0) {
    (**(code **)(**(int **)(*(int *)(param_1 + 100) + 4) + 0x14))();
    (**(code **)(**(int **)(*(int *)(param_1 + 100) + 4) + 8))();
  }
  if (HVar1 < 0) {
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))();
    }
    *(undefined4 *)(*(int *)(param_1 + 100) + 4) = 0;
    *param_5 = 0;
  }
  else {
    *(int **)(*(int *)(param_1 + 100) + 4) = local_1c;
    piVar2 = *(int **)(*(int *)(param_1 + 100) + 4);
    (**(code **)(*piVar2 + 0xc))
              (piVar2,*(undefined4 *)(*(int *)(param_1 + 100) + 8),param_2,param_3,param_4,param_5);
  }
  return;
}



/* 4059f7d0 FUN_4059f7d0 */

/* Boundary evidence: original MIPS .pdata 4059f7d0..4059f8af. Semantic name remains unreviewed. */

void FUN_4059f7d0(int *param_1,undefined4 *param_2,LRESULT param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x1c];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    FUN_405985e0(param_1,param_2,param_3,param_4);
    if (param_4 != 0) {
      (**(code **)(*piVar1 + 0x38))(piVar1,1,0x40b,4,&DAT_4057112c,0);
      (**(code **)(*piVar1 + 0x38))(piVar1,1,0x40f,4,0,0);
    }
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



/* 4059f8b0 FUN_4059f8b0 */

/* Boundary evidence: original MIPS .pdata 4059f8b0..4059f93b. Semantic name remains unreviewed. */

undefined4
FUN_4059f8b0(int *param_1,undefined4 param_2,int param_3,int *param_4,int *param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  int local_10;
  undefined4 local_c;
  
  if ((((param_3 == 0) || (param_4 == (int *)0x0)) || (param_5 == (int *)0x0)) ||
     (param_6 == (undefined4 *)0x0)) {
    uVar1 = 0x80070057;
  }
  else {
    *param_6 = 0;
    local_c = *(undefined4 *)(param_3 + 4);
    local_10 = 4;
    uVar1 = FUN_4059b740(param_1,param_2,&local_10,param_4,param_5,param_6);
  }
  return uVar1;
}



/* 4059f93c FUN_4059f93c */

/* Boundary evidence: original MIPS .pdata 4059f93c..4059fb03. Semantic name remains unreviewed. */

HRESULT FUN_4059f93c(int param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  undefined4 *puVar4;
  HRESULT HVar5;
  LRESULT local_28 [2];
  
  if (param_4 == 0) {
    HVar5 = -0x7fffbffd;
  }
  else {
    HVar5 = FUN_40599524(param_1,param_2,param_3,param_4,param_5);
    if ((((param_2 != (int *)0x0) && (*param_2 == 0x10a7df2f)) && (param_2[1] == 0x4eec61ee)) &&
       ((param_2[2] == -0x7911f143 && (param_2[3] == 0x18564efe)))) {
      local_28[0] = 0;
      iVar2 = FUN_405a4104(*(undefined4 **)(param_1 + 0x40),local_28);
      if (iVar2 != 0) {
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,iVar2);
      }
      if (param_3 != 0) {
        puVar4 = (undefined4 *)(param_4 + 4);
        do {
          uVar3 = puVar4[-1];
          if (uVar3 == 0x1002) {
LAB_4059faf0:
            if (local_28[0] == 0) {
LAB_4059fa7c:
              *puVar4 = 1;
            }
            else {
              *puVar4 = 2;
            }
          }
          else {
            if (uVar3 == 0x1003) goto LAB_4059fa7c;
            if (uVar3 == 0x1007) goto LAB_4059faf0;
            if (uVar3 == 0x1009) {
              FUN_40586a28(DAT_405aa0d4,0);
              bVar1 = FUN_40584f40();
              if (CONCAT31(extraout_var,bVar1) == 0) {
                *puVar4 = 2;
              }
              else {
                *puVar4 = 1;
              }
              FUN_40583798(DAT_405aa0d4);
            }
            else if ((0x101f < uVar3) && (uVar3 < 0x1025)) goto LAB_4059fa7c;
          }
          param_3 = param_3 + -1;
          puVar4 = puVar4 + 2;
        } while (param_3 != 0);
      }
    }
  }
  return HVar5;
}



/* 4059fb04 FUN_4059fb04 */

/* Boundary evidence: original MIPS .pdata 4059fb04..4059fbcf. Semantic name remains unreviewed. */

undefined4 FUN_4059fb04(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_2 == (int *)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    piVar1 = (int *)param_1[0x11];
    if (piVar1 == (int *)0x0) {
      uVar2 = 1;
    }
    else {
      if (*param_2 == 2) {
        if ((ushort *)param_2[1] != (ushort *)0x0) {
          FUN_405a45f0(piVar1,(ushort *)param_2[1]);
        }
      }
      else if (*param_2 == 4) {
        if ((char *)param_2[1] != (char *)0x0) {
          FUN_405a4708(piVar1,(char *)param_2[1]);
        }
      }
      else {
        (**(code **)(*param_1 + 0x20))();
      }
      uVar2 = 0;
    }
    FUN_405958a8((int)param_2);
    operator_delete(param_2);
  }
  return uVar2;
}



/* 4059fbd0 FUN_4059fbd0 */

/* Boundary evidence: original MIPS .pdata 4059fbd0..4059fc5b. Semantic name remains unreviewed. */

undefined4 * FUN_4059fbd0(undefined4 *param_1,undefined4 param_2,ushort *param_3)

{
  FUN_4059bc34(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_40572988;
  param_1[1] = &PTR_LAB_40572974;
  param_1[2] = &PTR_LAB_4057294c;
  param_1[3] = &PTR_LAB_4057293c;
  param_1[4] = &PTR_LAB_40572928;
  param_1[5] = &PTR_LAB_4057290c;
  param_1[6] = &PTR_LAB_405728fc;
  param_1[7] = &PTR_LAB_405728e4;
  return param_1;
}



/* 4059fc5c FUN_4059fc5c */

/* Boundary evidence: original MIPS .pdata 4059fc5c..4059fcd3. Semantic name remains unreviewed. */

void FUN_4059fc5c(int *param_1)

{
  *param_1 = (int)&PTR_FUN_40572988;
  param_1[1] = (int)&PTR_LAB_40572974;
  param_1[2] = (int)&PTR_LAB_4057294c;
  param_1[3] = (int)&PTR_LAB_4057293c;
  param_1[4] = (int)&PTR_LAB_40572928;
  param_1[5] = (int)&PTR_LAB_4057290c;
  param_1[6] = (int)&PTR_LAB_405728fc;
  param_1[7] = (int)&PTR_LAB_405728e4;
  FUN_4059a928(param_1);
  return;
}



/* 4059fcd4 FUN_4059fcd4 */

/* Boundary evidence: original MIPS .pdata 4059fcd4..4059fdab. Semantic name remains unreviewed. */

int FUN_4059fcd4(int *param_1,HMENU param_2,int *param_3)

{
  int iVar1;
  UINT uIDEnableItem;
  
  iVar1 = FUN_405974e8(param_1,param_2,param_3);
  if ((iVar1 == 0) && (param_3 != (int *)0x0)) {
    if (*param_3 == 0) {
      EnableMenuItem(param_2,0x1023,1);
      EnableMenuItem(param_2,0x1024,1);
      EnableMenuItem(param_2,0x1001,1);
      uIDEnableItem = 0x1004;
    }
    else {
      if (*param_3 != 1) {
        return 0;
      }
      EnableMenuItem(param_2,0x1021,1);
      EnableMenuItem(param_2,0x1002,1);
      uIDEnableItem = 0x1003;
    }
    EnableMenuItem(param_2,uIDEnableItem,1);
  }
  return iVar1;
}



/* 4059fdac FUN_4059fdac */

/* Boundary evidence: original MIPS .pdata 4059fdac..4059fe53. Semantic name remains unreviewed. */

undefined4 FUN_4059fdac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  HWND local_18 [2];
  
  if (*(int *)(param_1 + 0x70) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_405982b4(param_1);
    iVar1 = (**(code **)(**(int **)(param_1 + 0x70) + 0x34))(*(int **)(param_1 + 0x70),2,local_18);
    if (-1 < iVar1) {
      SendMessageW(local_18[0],0x411,0x1002,0);
      SendMessageW(local_18[0],0x411,0x1004,0);
      SendMessageW(local_18[0],0x411,0x1061,0);
    }
  }
  return uVar2;
}



/* 4059fe54 FUN_4059fe54 */

/* Boundary evidence: original MIPS .pdata 4059fe54..4059ff33. Semantic name remains unreviewed. */

void FUN_4059fe54(int *param_1,undefined4 *param_2,LRESULT param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x1c];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    FUN_405985e0(param_1,param_2,param_3,param_4);
    if (param_4 != 0) {
      (**(code **)(*piVar1 + 0x38))(piVar1,1,0x40b,4,&DAT_4057112c,0);
      (**(code **)(*piVar1 + 0x38))(piVar1,1,0x40f,4,0,0);
    }
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



/* 4059ff34 FUN_4059ff34 */

/* Boundary evidence: original MIPS .pdata 4059ff34..405a00e7. Semantic name remains unreviewed. */

HRESULT FUN_4059ff34(int param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  HRESULT HVar4;
  LRESULT local_20 [2];
  
  if (param_4 == 0) {
    HVar4 = -0x7fffbffd;
  }
  else {
    HVar4 = FUN_40599524(param_1,param_2,param_3,param_4,param_5);
    if ((((param_2 != (int *)0x0) && (*param_2 == 0x10a7df2f)) && (param_2[1] == 0x4eec61ee)) &&
       ((param_2[2] == -0x7911f143 && (param_2[3] == 0x18564efe)))) {
      local_20[0] = 0;
      iVar1 = FUN_405a4104(*(undefined4 **)(param_1 + 0x40),local_20);
      if (param_3 != 0) {
        puVar3 = (undefined4 *)(param_4 + 4);
        do {
          uVar2 = puVar3[-1];
          if (uVar2 < 0x1022) {
            if (uVar2 == 0x1021) goto LAB_405a0090;
            if (uVar2 < 0x1001) goto LAB_405a0094;
            if (uVar2 < 0x1004) goto LAB_405a0090;
            if (uVar2 == 0x1004) {
              if (local_20[0] == 0) goto LAB_405a0090;
            }
            else if ((uVar2 == 0x1006) && (local_20[0] != 0)) goto LAB_405a0090;
          }
          else {
            if ((uVar2 < 0x1023) || ((0x1024 < uVar2 && (uVar2 != 0x1061)))) goto LAB_405a0094;
LAB_405a0090:
            *puVar3 = 1;
          }
LAB_405a0094:
          param_3 = param_3 + -1;
          puVar3 = puVar3 + 2;
        } while (param_3 != 0);
      }
      if (iVar1 != 0) {
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,iVar1);
      }
    }
  }
  return HVar4;
}



/* 405a00e8 FUN_405a00e8 */

/* Boundary evidence: original MIPS .pdata 405a00e8..405a0133. Semantic name remains unreviewed. */

int * FUN_405a00e8(int *param_1,uint param_2)

{
  FUN_4059fc5c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 405a0134 FUN_405a0134 */

/* Boundary evidence: original MIPS .pdata 405a0134..405a01cb. Semantic name remains unreviewed. */

void FUN_405a0134(undefined4 *param_1)

{
  HANDLE hFindFile;
  
  *param_1 = &PTR_FUN_40572a44;
  param_1[1] = &PTR_LAB_40572a34;
  if ((HLOCAL)param_1[3] != (HLOCAL)0x0) {
    FUN_40580ef4((HLOCAL)param_1[3]);
  }
  hFindFile = (HANDLE)param_1[4];
  if ((hFindFile != (HANDLE)0xffffffff) && (hFindFile != (HANDLE)0x0)) {
    FindClose(hFindFile);
  }
  if (param_1[0x92] != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
  }
  return;
}



/* 405a01cc FUN_405a01cc */

/* Boundary evidence: original MIPS .pdata 405a01cc..405a039b. Semantic name remains unreviewed. */

undefined4 FUN_405a01cc(int param_1,ushort *param_2)

{
  HLOCAL pvVar1;
  int iVar2;
  LPWSTR pWVar3;
  HANDLE pvVar4;
  uint _MaxCount;
  undefined4 uVar5;
  wchar_t local_228;
  short local_226;
  uint local_20;
  
  local_20 = DAT_405a9a3c;
  uVar5 = 0;
  if (param_2 != (ushort *)0x0) {
    if (*(HLOCAL *)(param_1 + 0xc) != (HLOCAL)0x0) {
      FUN_40580ef4(*(HLOCAL *)(param_1 + 0xc));
    }
    pvVar1 = FUN_405813a0(param_2,-1);
    pvVar4 = *(HANDLE *)(param_1 + 0x10);
    *(HLOCAL *)(param_1 + 0xc) = pvVar1;
    if ((pvVar4 != (HANDLE)0xffffffff) && (pvVar4 != (HANDLE)0x0)) {
      FindClose(pvVar4);
      *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    }
    iVar2 = SHGetPathFromIDList(*(LPCITEMIDLIST *)(param_1 + 0xc),&local_228);
    if (iVar2 != 0) {
      iVar2 = FUN_4058862c();
      if (iVar2 != 0) {
        FUN_40586a28(DAT_405aa0d4,0);
        pWVar3 = PathFindFileNameW(&DAT_405a9aa4);
        *(LPWSTR *)(param_1 + 0x24c) = pWVar3;
        if ((pWVar3 != (LPWSTR)0x0) &&
           ((((_MaxCount = ((int)(pWVar3 + -0x202d4d52) >> 1) - 1, _MaxCount < 0x104 &&
              ((&local_228)[_MaxCount] != L'\0')) && ((&local_228)[_MaxCount] != L'\\')) ||
            (iVar2 = _wcsnicmp(&local_228,&DAT_405a9aa4,_MaxCount), iVar2 != 0)))) {
          *(undefined4 *)(param_1 + 0x24c) = 0;
        }
        FUN_40583798(DAT_405aa0d4);
      }
      if ((local_228 == L'\\') && (local_226 == 0)) {
        StringCchCopyW(&local_228,0x104,L"\\*.*");
      }
      else {
        PathRemoveTrailingSlashes(&local_228);
        StringCchCatW(&local_228,0x104,L"\\*.*");
      }
      pvVar4 = FindFirstFileW(&local_228,(LPWIN32_FIND_DATAW)(param_1 + 0x14));
      *(HANDLE *)(param_1 + 0x10) = pvVar4;
      if (pvVar4 == (HANDLE)0xffffffff) {
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
      uVar5 = 1;
    }
  }
  FUN_405a7174(local_20);
  return uVar5;
}



/* 405a039c FUN_405a039c */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 405a039c..405a0583. Semantic name remains unreviewed. */

undefined4 FUN_405a039c(int param_1)

{
  BOOL BVar1;
  HRESULT HVar2;
  LPWSTR pszFile;
  int iVar3;
  uint uVar4;
  LPCWSTR pszFile_00;
  undefined4 uVar5;
  size_t local_228;
  short sStack_222;
  undefined1 auStack_220 [520];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  uVar5 = 0;
  if ((*(uint *)(param_1 + 0x14) & 0x10) == 0) {
    if ((*(uint *)(param_1 + 0x244) & 0x40) == 0) goto LAB_405a0560;
    if (*(LPCWSTR *)(param_1 + 0x248) != (LPCWSTR)0x0) {
      pszFile_00 = (LPCWSTR)(param_1 + 0x3c);
      BVar1 = PathMatchSpecW(pszFile_00,*(LPCWSTR *)(param_1 + 0x248));
      if (BVar1 == 0) {
        iVar3 = PathIsLink(pszFile_00);
        if (((((iVar3 == 0) ||
              (iVar3 = SHGetPathFromIDList(*(LPCITEMIDLIST *)(param_1 + 0xc),(wchar_t *)auStack_220)
              , iVar3 == 0)) ||
             (HVar2 = StringCchLengthW((STRSAFE_PCNZWCH)auStack_220,0x104,&local_228), HVar2 < 0))
            || (((&sStack_222)[local_228] != 0x5c &&
                (HVar2 = StringCchCatW((STRSAFE_LPWSTR)auStack_220,0x104,L"\\"), HVar2 < 0)))) ||
           ((HVar2 = StringCchCatW((STRSAFE_LPWSTR)auStack_220,0x104,pszFile_00), HVar2 < 0 ||
            (iVar3 = SHGetShortcutTarget((LPCWSTR)auStack_220,(LPWSTR)auStack_220,0x104), iVar3 == 0
            )))) goto LAB_405a0560;
        PathRemoveQuotesAndArgs(auStack_220);
        BVar1 = PathIsDirectoryW((LPCWSTR)auStack_220);
        if (BVar1 == 0) {
          pszFile = PathFindFileNameW((LPCWSTR)auStack_220);
          uVar4 = PathMatchSpecW(pszFile,*(LPCWSTR *)(param_1 + 0x248));
          goto joined_r0x405a04ec;
        }
      }
    }
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x244) & 0x20;
joined_r0x405a04ec:
    if (uVar4 == 0) goto LAB_405a0560;
  }
  iVar3 = FUN_405885fc();
  if ((((iVar3 != 0) ||
       (((*(uint *)(param_1 + 0x14) & 4) == 0 && ((*(uint *)(param_1 + 0x14) & 0x2000) == 0)))) &&
      (((*(uint *)(param_1 + 0x244) & 0x80) != 0 || ((*(uint *)(param_1 + 0x14) & 2) == 0)))) &&
     ((*(wchar_t **)(param_1 + 0x24c) == (wchar_t *)0x0 ||
      (iVar3 = _wcsicmp(*(wchar_t **)(param_1 + 0x24c),(wchar_t *)(param_1 + 0x3c)), iVar3 != 0))))
  {
    uVar5 = 1;
  }
LAB_405a0560:
  FUN_405a7174(local_18);
  return uVar5;
}



/* 405a0584 FUN_405a0584 */

/* Boundary evidence: original MIPS .pdata 405a0584..405a06bb. Semantic name remains unreviewed. */

undefined4 FUN_405a0584(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = *param_2;
    if (((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
        ) || (((iVar2 == 0x214f2 && (param_2[1] == 0)) &&
              ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    else {
      if (iVar2 != 0x1cb6bfa9) {
        return 0x80004002;
      }
      if (param_2[1] != 0x4d356809) {
        return 0x80004002;
      }
      if (param_2[2] != -0x7f2b866e) {
        return 0x80004002;
      }
      if (param_2[3] != -0x130d9a6e) {
        return 0x80004002;
      }
      iVar2 = param_1 + 4;
      if (param_1 == 0) {
        iVar2 = 0;
      }
      *param_3 = iVar2;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 405a06bc FUN_405a06bc */

/* Boundary evidence: original MIPS .pdata 405a06bc..405a080f. Semantic name remains unreviewed. */

int FUN_405a06bc(int param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  BOOL BVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_3 == (int *)0x0) {
    iVar2 = -0x7ff8ffa9;
  }
  if (*(int *)(param_1 + 0x10) == -1) {
    iVar2 = -0x7fff0001;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar2 = 1;
  }
  if (iVar2 == 0) {
    iVar2 = FUN_405a039c(param_1);
    if (iVar2 == 0) {
      do {
        BVar1 = FindNextFileW(*(HANDLE *)(param_1 + 0x10),(LPWIN32_FIND_DATAW)(param_1 + 0x14));
        if (BVar1 == 0) {
          FindClose(*(HANDLE *)(param_1 + 0x10));
          iVar2 = 1;
          *(undefined4 *)(param_1 + 0x10) = 0;
          goto LAB_405a07c0;
        }
        iVar2 = FUN_405a039c(param_1);
      } while (iVar2 == 0);
    }
    iVar2 = FUN_40587d0c((STRSAFE_PCNZWCH)(param_1 + 0x3c),param_3);
    FUN_40587714(*(LPCITEMIDLIST *)(param_1 + 0xc),param_3);
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 1;
    }
    BVar1 = FindNextFileW(*(HANDLE *)(param_1 + 0x10),(LPWIN32_FIND_DATAW)(param_1 + 0x14));
    if (BVar1 == 0) {
      FindClose(*(HANDLE *)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
LAB_405a07c0:
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  return iVar2;
}



/* 405a0810 FUN_405a0810 */

/* Boundary evidence: original MIPS .pdata 405a0810..405a091b. Semantic name remains unreviewed. */

HRESULT FUN_405a0810(int param_1,STRSAFE_PCNZWCH param_2)

{
  STRSAFE_LPWSTR pszDest;
  HRESULT HVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  if (param_2 == (STRSAFE_PCNZWCH)0x0) {
    HVar1 = 0;
  }
  else {
    HVar1 = StringCchLengthW(param_2,0x104,local_20);
    if (-1 < HVar1) {
      if (*(int *)(param_1 + 0x244) == 0) {
        pszDest = (STRSAFE_LPWSTR)
                  (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(local_20[0] + 1) * 2);
      }
      else {
        pszDest = (STRSAFE_LPWSTR)
                  (**(code **)(*DAT_405aa0c8 + 0x10))
                            (DAT_405aa0c8,*(int *)(param_1 + 0x244),(local_20[0] + 1) * 2);
      }
      if (pszDest == (STRSAFE_LPWSTR)0x0) {
        HVar1 = -0x7ff8fff2;
      }
      else {
        HVar1 = StringCchCopyW(pszDest,local_20[0] + 1,param_2);
        *(STRSAFE_LPWSTR *)(param_1 + 0x244) = pszDest;
        if (-1 < HVar1) {
          return HVar1;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x244) != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
    *(undefined4 *)(param_1 + 0x244) = 0;
  }
  return HVar1;
}



/* 405a0930 FUN_405a0930 */

/* Boundary evidence: original MIPS .pdata 405a0930..405a0973. Semantic name remains unreviewed. */

int FUN_405a0930(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2] + -1;
  param_1[2] = iVar1;
  if (iVar1 == 0) {
    FUN_405a0134(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 405a0988 FUN_405a0988 */

/* Boundary evidence: original MIPS .pdata 405a0988..405a09ff. Semantic name remains unreviewed. */

undefined4 * FUN_405a0988(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = &PTR_LAB_40572344;
  param_1[0x91] = param_2;
  *param_1 = &PTR_FUN_40572a44;
  param_1[1] = &PTR_LAB_40572a34;
  param_1[3] = 0;
  param_1[4] = 0xffffffff;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  memset(param_1 + 5,0,0x230);
  param_1[2] = 1;
  return param_1;
}



/* 405a0a00 FUN_405a0a00 */

undefined4 * FUN_405a0a00(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



/* 405a0a1c FUN_405a0a1c */

/* Boundary evidence: original MIPS .pdata 405a0a1c..405a0ad7. Semantic name remains unreviewed. */

void FUN_405a0a1c(int param_1)

{
  HLOCAL pvVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar2 = 0;
      do {
        pvVar1 = *(HLOCAL *)(iVar2 + *(int *)(param_1 + 0x10));
        if (pvVar1 != (HLOCAL)0x0) {
          FUN_40580ef4(pvVar1);
          *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x10)) = 0;
        }
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (uVar3 < *(uint *)(param_1 + 0xc));
    }
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if (*(HLOCAL *)(param_1 + 8) != (HLOCAL)0x0) {
    FUN_40580ef4(*(HLOCAL *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}



/* 405a0ad8 FUN_405a0ad8 */

/* Boundary evidence: original MIPS .pdata 405a0ad8..405a0c07. Semantic name remains unreviewed. */

undefined4 * FUN_405a0ad8(undefined4 *param_1)

{
  undefined4 *puVar1;
  HLOCAL pvVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = operator_new(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
  }
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    puVar1[2] = 0;
    puVar1[3] = param_1[3];
    puVar1[4] = 0;
    if ((ushort *)param_1[2] != (ushort *)0x0) {
      pvVar2 = FUN_405813a0((ushort *)param_1[2],-1);
      puVar1[2] = pvVar2;
    }
    if (param_1[3] != 0) {
      iVar3 = (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,param_1[3] << 2);
      puVar1[4] = iVar3;
      if ((iVar3 != 0) && (uVar4 = 0, param_1[3] != 0)) {
        iVar3 = 0;
        do {
          if (*(ushort **)(iVar3 + param_1[4]) != (ushort *)0x0) {
            pvVar2 = FUN_405813a0(*(ushort **)(iVar3 + param_1[4]),-1);
            *(HLOCAL *)(puVar1[4] + iVar3) = pvVar2;
          }
          uVar4 = uVar4 + 1;
          iVar3 = iVar3 + 4;
        } while (uVar4 < (uint)param_1[3]);
      }
    }
  }
  return puVar1;
}



/* 405a0c08 FUN_405a0c08 */

/* Boundary evidence: original MIPS .pdata 405a0c08..405a0d87. Semantic name remains unreviewed. */

undefined4 * FUN_405a0c08(undefined4 *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if (((param_1 != (undefined4 *)0x0) && ((ushort *)param_1[2] != (ushort *)0x0)) &&
     (param_1[4] != 0)) {
    iVar4 = 0;
    sVar1 = FUN_40581278((ushort *)param_1[2],-1);
    uVar6 = 0;
    if (param_1[3] != 0) {
      iVar5 = 0;
      do {
        iVar2 = FUN_40581278(*(ushort **)(iVar5 + param_1[4]),1);
        uVar6 = uVar6 + 1;
        iVar4 = iVar2 + iVar4;
        iVar5 = iVar5 + 4;
      } while (uVar6 < (uint)param_1[3]);
    }
    puVar3 = LocalAlloc(0x40,iVar4 + sVar1 + 0xc);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *param_1;
      puVar3[1] = param_1[1];
      memcpy(puVar3 + 2,(void *)param_1[2],sVar1);
      *(undefined4 *)(sVar1 + 8 + (int)puVar3) = param_1[3];
      iVar4 = sVar1 + 0xc;
      uVar6 = 0;
      if (param_1[3] == 0) {
        return puVar3;
      }
      iVar5 = 0;
      do {
        sVar1 = FUN_40581278(*(ushort **)(iVar5 + param_1[4]),1);
        memcpy((void *)(iVar4 + (int)puVar3),*(void **)(iVar5 + param_1[4]),sVar1);
        iVar2 = FUN_40581278(*(ushort **)(iVar5 + param_1[4]),1);
        uVar6 = uVar6 + 1;
        iVar4 = iVar2 + iVar4;
        iVar5 = iVar5 + 4;
      } while (uVar6 < (uint)param_1[3]);
      return puVar3;
    }
  }
  return (undefined4 *)0x0;
}



/* 405a0d88 FUN_405a0d88 */

/* Boundary evidence: original MIPS .pdata 405a0d88..405a0ea7. Semantic name remains unreviewed. */

undefined4 FUN_405a0d88(undefined4 *param_1,undefined4 *param_2)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  HLOCAL pvVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar7 = 0;
  }
  else {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    puVar1 = FUN_405813a0((ushort *)(param_1 + 2),-1);
    param_2[2] = puVar1;
    iVar2 = FUN_40581278(puVar1,-1);
    piVar6 = (int *)(iVar2 + (int)(param_1 + 2));
    iVar2 = *piVar6;
    puVar1 = (ushort *)(piVar6 + 1);
    param_2[3] = iVar2;
    uVar3 = (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,iVar2 << 2);
    uVar8 = 0;
    uVar7 = 1;
    param_2[4] = uVar3;
    if (param_2[3] != 0) {
      iVar2 = 0;
      do {
        pvVar4 = FUN_405813a0(puVar1,1);
        *(HLOCAL *)(param_2[4] + iVar2) = pvVar4;
        iVar5 = FUN_40581278(*(ushort **)(param_2[4] + iVar2),1);
        uVar8 = uVar8 + 1;
        puVar1 = (ushort *)(iVar5 + (int)puVar1);
        iVar2 = iVar2 + 4;
      } while (uVar8 < (uint)param_2[3]);
    }
  }
  return uVar7;
}



/* 405a0ea8 FUN_405a0ea8 */

/* Boundary evidence: original MIPS .pdata 405a0ea8..405a0edb. Semantic name remains unreviewed. */

void FUN_405a0ea8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40572a70;
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* 405a0edc FUN_405a0edc */

/* Boundary evidence: original MIPS .pdata 405a0edc..405a0fb7. Semantic name remains unreviewed. */

undefined4 FUN_405a0edc(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    if (((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
        (param_2[3] == 0x46000000)) ||
       (((*param_2 == 0x10e && (param_2[1] == 0)) &&
        ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = param_1;
    }
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 405a0fb8 FUN_405a0fb8 */

/* Boundary evidence: original MIPS .pdata 405a0fb8..405a1027. Semantic name remains unreviewed. */

int FUN_405a0fb8(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_2 == 0) || (param_3 == (undefined4 *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    if (-1 < iVar1) {
      *param_3 = 1;
      param_3[1] = param_1[2];
      param_3[2] = 0;
    }
  }
  return iVar1;
}



/* 405a1028 FUN_405a1028 */

/* Boundary evidence: original MIPS .pdata 405a1028..405a10df. Semantic name remains unreviewed. */

undefined4 FUN_405a1028(undefined4 param_1,ushort *param_2)

{
  undefined4 uVar1;
  UINT UVar2;
  
  if (param_2 == (ushort *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    UVar2 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
    if ((UVar2 == *param_2) && (*(int *)(param_2 + 2) == 0)) {
      if (*(int *)(param_2 + 4) == 1) {
        if (*(int *)(param_2 + 6) == -1) {
          if (*(int *)(param_2 + 8) == 1) {
            uVar1 = 0;
          }
          else {
            uVar1 = 0x80040069;
          }
        }
        else {
          uVar1 = 0x80040068;
        }
      }
      else {
        uVar1 = 0x8004006b;
      }
    }
    else {
      uVar1 = 0x80040064;
    }
  }
  return uVar1;
}



/* 405a10e0 FUN_405a10e0 */

/* Boundary evidence: original MIPS .pdata 405a10e0..405a11bf. Semantic name remains unreviewed. */

int FUN_405a10e0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  SIZE_T uBytes;
  HLOCAL pvVar2;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    if (-1 < iVar1) {
      pvVar2 = *(HLOCAL *)(param_3 + 4);
      if (pvVar2 == (HLOCAL)0x0) {
        iVar1 = -0x7fffbffb;
      }
      else if (param_4 == 0) {
        uBytes = LocalSize(pvVar2);
        pvVar2 = LocalAlloc(0x40,uBytes);
        param_1[2] = (int)pvVar2;
        if (pvVar2 == (HLOCAL)0x0) {
          iVar1 = -0x7ff8fff2;
        }
        else {
          memcpy(pvVar2,*(void **)(param_3 + 4),uBytes);
        }
      }
      else {
        param_1[2] = (int)pvVar2;
      }
    }
  }
  return iVar1;
}



/* 405a11c0 FUN_405a11c0 */

/* Boundary evidence: original MIPS .pdata 405a11c0..405a1247. Semantic name remains unreviewed. */

void FUN_405a11c0(void)

{
  UINT uFormat;
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_50;
  HWND local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 auStack_38 [12];
  undefined4 local_2c;
  undefined4 local_28;
  
  uFormat = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
  puVar1 = GetClipboardData(uFormat);
  if (puVar1 != (undefined4 *)0x0) {
    local_50 = 0;
    local_4c = (HWND)0x0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    iVar2 = FUN_405a0d88(puVar1,&local_50);
    if (iVar2 != 0) {
      local_28 = 4;
      local_2c = 0;
      SendMessageW(local_4c,0x102b,0xffffffff,(LPARAM)auStack_38);
      FUN_405a0a1c((int)&local_50);
    }
  }
  EmptyClipboard();
  return;
}



/* 405a1248 FUN_405a1248 */

/* Boundary evidence: original MIPS .pdata 405a1248..405a12d3. Semantic name remains unreviewed. */

undefined4 FUN_405a1248(LPSHFILEOPSTRUCTW param_1)

{
  SHFileOperationW(param_1);
  (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,param_1->pFrom);
  (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,param_1->pTo);
  (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,param_1);
  return 0;
}



/* 405a12d4 FUN_405a12d4 */

/* Boundary evidence: original MIPS .pdata 405a12d4..405a1573. Semantic name remains unreviewed. */

void FUN_405a12d4(void)

{
  undefined1 *puVar1;
  uint uVar2;
  uint *puVar3;
  bool bVar4;
  UINT uFormat;
  undefined4 *puVar5;
  int iVar6;
  HRESULT HVar7;
  size_t sVar8;
  undefined4 *puVar9;
  HANDLE pvVar10;
  uint uVar11;
  int iVar12;
  undefined4 *_Dst;
  int *local_358;
  IShellFolder *local_354;
  undefined4 local_350;
  undefined4 local_34c;
  LPCITEMIDLIST local_348;
  uint local_344;
  undefined4 *local_340;
  STRRET SStack_338;
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  uFormat = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
  puVar1 = (undefined1 *)((int)&SStack_338.uType + 3);
  uVar2 = (uint)puVar1 & 3;
  puVar3 = (uint *)(puVar1 + -uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  bVar4 = false;
  local_350 = 0;
  local_34c = 0;
  local_348 = (LPCITEMIDLIST)0x0;
  local_344 = 0;
  local_340 = (undefined4 *)0x0;
  local_354 = (IShellFolder *)0x0;
  local_358 = (int *)0x0;
  SStack_338.uType = 0;
  memset(&SStack_338.u,0,0x104);
  iVar12 = 0;
  puVar5 = GetClipboardData(uFormat);
  if ((puVar5 != (undefined4 *)0x0) && (iVar6 = FUN_405a0d88(puVar5,&local_350), iVar6 != 0)) {
    bVar4 = true;
    HVar7 = SHGetDesktopFolder(&local_354);
    if ((-1 < HVar7) &&
       (HVar7 = (*local_354->lpVtbl->BindToObject)
                          (local_354,local_348,(IBindCtx *)0x0,(IID *)&DAT_40572b68,&local_358),
       puVar5 = local_340, uVar2 = local_344, -1 < HVar7)) {
      uVar11 = 0;
      puVar9 = local_340;
      if (local_344 != 0) {
        do {
          iVar6 = (**(code **)(*local_358 + 0x2c))(local_358,*puVar9,0x8000,&SStack_338);
          if ((iVar6 < 0) ||
             (HVar7 = StrRetToBufW(&SStack_338,(LPCITEMIDLIST)*puVar9,aWStack_230,0x104), HVar7 < 0)
             ) goto LAB_405a14fc;
          sVar8 = wcslen(aWStack_230);
          uVar11 = uVar11 + 1;
          iVar12 = sVar8 + iVar12 + 1;
          puVar9 = puVar9 + 1;
        } while (uVar11 < uVar2);
      }
      puVar9 = LocalAlloc(0x40,(iVar12 + 0xb) * 2);
      if (puVar9 != (undefined4 *)0x0) {
        _Dst = puVar9 + 5;
        *puVar9 = 0x14;
        uVar11 = 0;
        puVar9[4] = 1;
        if (uVar2 != 0) {
          do {
            iVar12 = (**(code **)(*local_358 + 0x2c))(local_358,*puVar5,0x8000,&SStack_338);
            if ((iVar12 < 0) ||
               (HVar7 = StrRetToBufW(&SStack_338,(LPCITEMIDLIST)*puVar5,aWStack_230,0x104),
               HVar7 < 0)) goto LAB_405a14f4;
            sVar8 = wcslen(aWStack_230);
            sVar8 = (sVar8 + 1) * 2;
            memcpy(_Dst,aWStack_230,sVar8);
            uVar11 = uVar11 + 1;
            puVar5 = puVar5 + 1;
            _Dst = (undefined4 *)(sVar8 + (int)_Dst);
          } while (uVar11 < uVar2);
        }
        pvVar10 = SetClipboardData(0xf,puVar9);
        if (pvVar10 == (HANDLE)0x0) {
LAB_405a14f4:
          LocalFree(_Dst);
        }
      }
    }
  }
LAB_405a14fc:
  if (local_358 != (int *)0x0) {
    (**(code **)(*local_358 + 8))();
  }
  if (local_354 != (IShellFolder *)0x0) {
    (*local_354->lpVtbl->Release)(local_354);
  }
  if (bVar4) {
    FUN_405a0a1c((int)&local_350);
  }
  FUN_405a7174(local_28);
  return;
}



/* 405a1574 FUN_405a1574 */

/* Boundary evidence: original MIPS .pdata 405a1574..405a1603. Semantic name remains unreviewed. */

uint FUN_405a1574(void)

{
  BOOL BVar1;
  UINT uFormat;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint local_20 [6];
  
  uVar4 = 0;
  BVar1 = OpenClipboard((HWND)0x0);
  if (BVar1 != 0) {
    uFormat = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
    puVar2 = GetClipboardData(uFormat);
    if (puVar2 != (undefined4 *)0x0) {
      local_20[0] = 0;
      local_20[1] = 0;
      local_20[2] = 0;
      local_20[3] = 0;
      local_20[4] = 0;
      iVar3 = FUN_405a0d88(puVar2,local_20);
      if (iVar3 != 0) {
        uVar4 = local_20[0] & 7;
        FUN_405a0a1c((int)local_20);
      }
    }
    CloseClipboard();
  }
  return uVar4;
}



/* 405a1604 FUN_405a1604 */

/* Boundary evidence: original MIPS .pdata 405a1604..405a16ab. Semantic name remains unreviewed. */

void FUN_405a1604(int param_1)

{
  BOOL BVar1;
  UINT uFormat;
  undefined4 *puVar2;
  int iVar3;
  uint local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  BVar1 = OpenClipboard((HWND)0x0);
  if (BVar1 != 0) {
    uFormat = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
    puVar2 = GetClipboardData(uFormat);
    if (puVar2 != (undefined4 *)0x0) {
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      iVar3 = FUN_405a0d88(puVar2,&local_20);
      if (iVar3 != 0) {
        if ((param_1 == local_1c) && ((local_20 & 4) != 0)) {
          FUN_405a11c0();
        }
        FUN_405a0a1c((int)&local_20);
      }
    }
    CloseClipboard();
  }
  return;
}



/* 405a16ac FUN_405a16ac */

/* Boundary evidence: original MIPS .pdata 405a16ac..405a175f. Semantic name remains unreviewed. */

undefined4 FUN_405a16ac(void)

{
  BOOL BVar1;
  UINT UVar2;
  UINT format;
  int iVar3;
  undefined4 uVar4;
  
  BVar1 = OpenClipboard((HWND)0x0);
  if (BVar1 == 0) {
    uVar4 = 0;
  }
  else {
    UVar2 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
    format = EnumClipboardFormats(0);
    uVar4 = 0;
    for (; format != 0; format = EnumClipboardFormats(format)) {
      if ((UVar2 == format) || ((format == 0xf && (iVar3 = FUN_40588614(), iVar3 != 0)))) {
        uVar4 = 1;
        break;
      }
    }
    CloseClipboard();
  }
  return uVar4;
}



/* 405a1760 FUN_405a1760 */

/* Boundary evidence: original MIPS .pdata 405a1760..405a18b7. Semantic name remains unreviewed. */

undefined4 FUN_405a1760(int param_1,char *param_2)

{
  uint uVar1;
  BOOL BVar2;
  UINT uFormat;
  undefined4 *puVar3;
  int iVar4;
  LONG LVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  FILETIME FStack_48;
  FILETIME FStack_40;
  uint local_38;
  int local_34;
  undefined4 local_30;
  uint local_2c;
  undefined4 *local_28;
  
  BVar2 = OpenClipboard((HWND)0x0);
  uVar6 = 0;
  if (BVar2 != 0) {
    uFormat = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
    puVar3 = GetClipboardData(uFormat);
    if (puVar3 != (undefined4 *)0x0) {
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      local_28 = (undefined4 *)0x0;
      iVar4 = FUN_405a0d88(puVar3,&local_38);
      puVar3 = local_28;
      uVar1 = local_2c;
      if (iVar4 != 0) {
        if (((param_1 == local_34) && ((local_38 & 4) != 0)) &&
           (uVar7 = 0, puVar8 = local_28, local_2c != 0)) {
          do {
            iVar4 = FUN_405810a4(param_2,(char *)*puVar8);
            if (iVar4 != 0) {
              iVar4 = FUN_40580f18((int)param_2,&FStack_40.dwLowDateTime);
              if (((iVar4 == 0) ||
                  (iVar4 = FUN_40580f18(puVar3[uVar7],&FStack_48.dwLowDateTime), iVar4 == 0)) ||
                 (LVar5 = CompareFileTime(&FStack_40,&FStack_48), LVar5 == 0)) {
                uVar6 = 1;
              }
              break;
            }
            uVar7 = uVar7 + 1;
            puVar8 = puVar8 + 1;
          } while (uVar7 < uVar1);
        }
        FUN_405a0a1c((int)&local_38);
      }
    }
    CloseClipboard();
  }
  return uVar6;
}



/* 405a18b8 FUN_405a18b8 */

/* Boundary evidence: original MIPS .pdata 405a18b8..405a2003. Semantic name remains unreviewed. */

bool FUN_405a18b8(int *param_1)

{
  undefined1 uVar1;
  UINT UVar2;
  ushort uVar3;
  LPCITEMIDLIST pIVar4;
  ushort *puVar5;
  undefined2 extraout_var;
  STRSAFE_LPCWSTR pwVar6;
  HRESULT HVar7;
  size_t sVar8;
  LPWSTR pWVar9;
  LPCWSTR _Dst;
  undefined1 uVar10;
  int iVar11;
  wchar_t *_Str;
  bool bVar12;
  uint uVar13;
  int iVar14;
  LPCWSTR pWVar15;
  uint uVar16;
  uint local_670;
  _SHFILEOPSTRUCTW local_668;
  wchar_t local_648;
  undefined1 auStack_646 [510];
  wchar_t local_448;
  wchar_t awStack_446 [263];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  bVar12 = true;
  uVar13 = 0;
  if (param_1[1] == 2) {
    iVar11 = *param_1;
    local_448 = L'\"';
    if (*(int *)(iVar11 + 0xc) != 0) {
      iVar14 = 0;
      do {
        pIVar4 = FUN_405812ec(*(ushort **)(iVar11 + 8),
                              *(ushort **)(*(int *)(iVar11 + 0x10) + iVar14));
        if (pIVar4 != (LPCITEMIDLIST)0x0) {
          puVar5 = FUN_40581470((ushort *)pIVar4);
          uVar3 = FUN_405811d8((char *)puVar5);
          if (CONCAT22(extraout_var,uVar3) == 0) {
            iVar11 = SHGetPathFromIDList(pIVar4,awStack_446);
            if (iVar11 != 0) goto LAB_405a1a6c;
LAB_405a19ac:
            local_648 = L'\0';
            memset(auStack_646,0,0x1fe);
            puVar5 = FUN_40581470((ushort *)pIVar4);
            iVar11 = FUN_40580ed0((int)puVar5);
            pwVar6 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x301e,(LPWSTR)0x0,0);
            StringCchPrintfExW(&local_648,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,pwVar6,
                               iVar11);
            pwVar6 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3012,(LPWSTR)0x0,0);
            HVar7 = StringCchCatW(&local_648,0x100,pwVar6);
            if (HVar7 < 0) {
              FUN_4058a544((HWND)0x0,(LPCWSTR)0x301d,(wchar_t *)0x3012,(LPCWSTR)0x0,0x10);
            }
            else {
              FUN_4058a544((HWND)0x0,(LPCWSTR)0x301d,&local_648,(LPCWSTR)0x0,0x10);
            }
          }
          else {
            puVar5 = FUN_40581470((ushort *)pIVar4);
            pwVar6 = (STRSAFE_LPCWSTR)FUN_40581264((int)puVar5);
            HVar7 = StringCchCopyW(awStack_446,0x105,pwVar6);
            if (HVar7 < 0) goto LAB_405a19ac;
LAB_405a1a6c:
            _Str = (wchar_t *)param_1[2];
            sVar8 = wcslen(_Str);
            if (_Str[sVar8] == L'\\') {
              pWVar9 = PathFindFileNameW(awStack_446);
              iVar11 = StringCchPrintfW(awStack_238,0x104,L"%s%s",param_1[2],pWVar9);
            }
            else {
              pWVar9 = PathFindFileNameW(awStack_446);
              iVar11 = StringCchPrintfW(awStack_238,0x104,L"%s\\%s",param_1[2],pWVar9);
            }
            if (((iVar11 < 0) || (HVar7 = StringCchCatW(&local_448,0x106,L"\""), HVar7 < 0)) ||
               (iVar11 = SHCreateShortcutEx(awStack_238,&local_448,(wchar_t *)0x0,(uint *)0x0),
               iVar11 == 0)) {
              FUN_4058a544((HWND)0x0,(LPCWSTR)0x301d,(wchar_t *)0x301e,&local_448,0x10);
            }
          }
          FUN_40580ef4(pIVar4);
        }
        iVar11 = *param_1;
        uVar13 = uVar13 + 1;
        iVar14 = iVar14 + 4;
      } while (uVar13 < *(uint *)(iVar11 + 0xc));
      bVar12 = true;
    }
    goto LAB_405a1f84;
  }
  local_668.hwnd = (HWND)0x0;
  uVar16 = 0;
  memset(&local_668.wFunc,0,0x1a);
  iVar11 = *param_1;
  local_670 = 0;
  if (*(int *)(iVar11 + 0xc) != 0) {
    iVar14 = 0;
    do {
      pIVar4 = FUN_405812ec(*(ushort **)(iVar11 + 8),*(ushort **)(*(int *)(iVar11 + 0x10) + iVar14))
      ;
      if (pIVar4 != (LPCITEMIDLIST)0x0) {
        iVar11 = SHGetPathFromIDList(pIVar4,&local_448);
        if (iVar11 == 0) {
          local_648 = L'\0';
          pWVar15 = (LPCWSTR)0x0;
          memset(auStack_646,0,0x1fe);
          iVar11 = param_1[1];
          if (iVar11 == 0) {
            pWVar15 = (LPCWSTR)0x3006;
            puVar5 = FUN_40581470((ushort *)pIVar4);
            iVar11 = FUN_40580ed0((int)puVar5);
            pwVar6 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x305b,(LPWSTR)0x0,0);
            StringCchPrintfExW(&local_648,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,pwVar6,
                               iVar11);
          }
          else if (iVar11 == 1) {
            pWVar15 = (LPCWSTR)0x301a;
            puVar5 = FUN_40581470((ushort *)pIVar4);
            iVar11 = FUN_40580ed0((int)puVar5);
            pwVar6 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x305e,(LPWSTR)0x0,0);
            StringCchPrintfExW(&local_648,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,pwVar6,
                               iVar11);
          }
          else if (iVar11 == 3) {
            pWVar15 = (LPCWSTR)0x3064;
            puVar5 = FUN_40581470((ushort *)pIVar4);
            iVar11 = FUN_40580ed0((int)puVar5);
            pwVar6 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x305c,(LPWSTR)0x0,0);
            StringCchPrintfExW(&local_648,0x100,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x900,pwVar6,
                               iVar11);
          }
          pwVar6 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3012,(LPWSTR)0x0,0);
          HVar7 = StringCchCatW(&local_648,0x100,pwVar6);
          if (HVar7 < 0) {
            FUN_4058a544((HWND)0x0,pWVar15,(wchar_t *)0x3012,(LPCWSTR)0x0,0x10);
            pWVar15 = local_668.pFrom;
          }
          else {
            FUN_4058a544((HWND)0x0,pWVar15,&local_648,(LPCWSTR)0x0,0x10);
            pWVar15 = local_668.pFrom;
          }
        }
        else {
          sVar8 = wcslen(&local_448);
          uVar16 = sVar8 + uVar16 + 1;
          _Dst = (LPCWSTR)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,uVar16 * 2 + 2);
          pWVar15 = local_668.pFrom;
          if (_Dst != (LPCWSTR)0x0) {
            if (uVar13 != 0) {
              memcpy(_Dst,local_668.pFrom,uVar13 << 1);
            }
            if (uVar16 - uVar13 < 0x107) {
              memcpy(_Dst + uVar13,&local_448,(uVar16 - uVar13) * 2);
            }
            _Dst[uVar16] = L'\0';
            uVar13 = uVar16;
            pWVar15 = _Dst;
            if (local_668.pFrom != (LPCWSTR)0x0) {
              (**(code **)(*DAT_405aa0c8 + 0x14))();
            }
          }
        }
        local_668.pFrom = pWVar15;
        FUN_40580ef4(pIVar4);
      }
      iVar11 = *param_1;
      local_670 = local_670 + 1;
      iVar14 = iVar14 + 4;
    } while (local_670 < *(uint *)(iVar11 + 0xc));
  }
  if (local_668.pFrom == (LPCWSTR)0x0) goto LAB_405a1f84;
  iVar11 = param_1[1];
  UVar2 = 2;
  if (iVar11 != 0) {
    if (iVar11 == 1) {
      UVar2 = 1;
    }
    else {
      UVar2 = local_668.wFunc;
      if (iVar11 == 3) {
        UVar2 = 3;
      }
    }
  }
  local_668.wFunc = UVar2;
  local_668.hwnd = (HWND)0x0;
  if (local_668.wFunc == 3) {
    iVar11 = FUN_4058862c();
    uVar3 = local_668.fFlags;
    if (iVar11 != 0) {
      uVar1 = (undefined1)local_668.fFlags;
      uVar10 = (undefined1)(local_668.fFlags >> 8);
      goto LAB_405a1f1c;
    }
  }
  else {
    uVar1 = (undefined1)local_668.fFlags;
    uVar10 = (undefined1)(local_668.fFlags >> 8);
LAB_405a1f1c:
    uVar3 = local_668.fFlags | 0x40;
    local_668.fFlags = CONCAT11(uVar10,uVar1) | 0x40;
  }
  if ((*(uint *)*param_1 & 8) != 0) {
    local_668.fFlags = uVar3 | 8;
  }
  local_668.pTo = (LPCWSTR)param_1[2];
  iVar11 = SHFileOperationW(&local_668);
  bVar12 = iVar11 == 0;
  (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,local_668.pFrom);
LAB_405a1f84:
  if (param_1[2] != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
  }
  FUN_405a0a1c(*param_1);
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  operator_delete(param_1);
  FUN_405a7174(local_30);
  return bVar12;
}



/* 405a2004 FUN_405a2004 */

/* Boundary evidence: original MIPS .pdata 405a2004..405a2193. Semantic name remains unreviewed. */

undefined4 FUN_405a2004(undefined4 *param_1,int param_2,STRSAFE_PCNZWCH param_3)

{
  int *_Dst;
  undefined4 *puVar1;
  HRESULT HVar2;
  wchar_t *_Dest;
  HANDLE hObject;
  size_t local_20 [2];
  
  if ((param_2 != 3) && (param_3 == (STRSAFE_PCNZWCH)0x0)) {
    return 0;
  }
  _Dst = operator_new(0xc);
  if (_Dst == (int *)0x0) {
    _Dst = (int *)0x0;
  }
  else {
    memset(_Dst,0,0xc);
  }
  if (_Dst == (int *)0x0) {
    return 0;
  }
  *_Dst = 0;
  _Dst[1] = param_2;
  _Dst[2] = 0;
  puVar1 = FUN_405a0ad8(param_1);
  *_Dst = (int)puVar1;
  if (puVar1 == (undefined4 *)0x0) goto LAB_405a2124;
  if (param_3 != (STRSAFE_PCNZWCH)0x0) {
    local_20[0] = 0;
    HVar2 = StringCchLengthW(param_3,0x104,local_20);
    if (HVar2 < 0) goto LAB_405a2124;
    _Dest = (wchar_t *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,(local_20[0] + 1) * 2);
    _Dst[2] = (int)_Dest;
    if (_Dest == (wchar_t *)0x0) goto LAB_405a2124;
    wcscpy(_Dest,param_3);
  }
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_405a18b8,_Dst,0,(LPDWORD)0x0);
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
    return 1;
  }
LAB_405a2124:
  if (_Dst[2] != 0) {
    (**(code **)(*DAT_405aa0c8 + 0x14))();
  }
  if (*_Dst != 0) {
    FUN_405a0a1c(*_Dst);
    if ((void *)*_Dst != (void *)0x0) {
      operator_delete((void *)*_Dst);
    }
  }
  operator_delete(_Dst);
  return 0;
}



/* 405a2194 FUN_405a2194 */

/* Boundary evidence: original MIPS .pdata 405a2194..405a21c3. Semantic name remains unreviewed. */

int FUN_405a2194(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    FUN_40594618(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 405a21c4 FUN_405a21c4 */

/* Boundary evidence: original MIPS .pdata 405a21c4..405a234f. Semantic name remains unreviewed. */

HANDLE FUN_405a21c4(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                   uint param_5)

{
  int iVar1;
  UINT uFormat;
  BOOL BVar2;
  undefined4 *hMem;
  HANDLE pvVar3;
  int *local_58 [2];
  undefined4 local_50;
  undefined4 *local_4c [3];
  uint local_40 [6];
  undefined2 local_28 [2];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  pvVar3 = (HANDLE)0x0;
  local_58[0] = (int *)0x0;
  iVar1 = (**(code **)(*param_2 + 0x28))(param_2,param_1,param_3,param_4,&DAT_40572c48,0,local_58);
  if (-1 < iVar1) {
    local_28[0] = 0;
    memset(&local_24,0,0x10);
    local_50 = 0;
    memset(local_4c,0,8);
    uFormat = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
    local_1c = 0xffffffff;
    local_28[0] = (undefined2)uFormat;
    local_24 = 0;
    local_20 = 1;
    local_18 = 1;
    iVar1 = (**(code **)(*local_58[0] + 0xc))(local_58[0],local_28,&local_50);
    if ((-1 < iVar1) && (BVar2 = OpenClipboard((HWND)0x0), BVar2 != 0)) {
      local_40[0] = 0;
      local_40[1] = 0;
      local_40[2] = 0;
      local_40[3] = 0;
      local_40[4] = 0;
      FUN_405a11c0();
      iVar1 = FUN_405a0d88(local_4c[0],local_40);
      if (iVar1 != 0) {
        local_40[0] = local_40[0] | param_5;
        hMem = FUN_405a0c08(local_40);
        if (hMem != (undefined4 *)0x0) {
          pvVar3 = SetClipboardData(uFormat,hMem);
        }
        FUN_405a0a1c((int)local_40);
        if ((pvVar3 != (HANDLE)0x0) && (iVar1 = FUN_40588614(), iVar1 != 0)) {
          FUN_405a12d4();
        }
      }
      CloseClipboard();
    }
    (**(code **)(*local_58[0] + 8))();
  }
  return pvVar3;
}



/* 405a2350 FUN_405a2350 */

/* Boundary evidence: original MIPS .pdata 405a2350..405a238b. Semantic name remains unreviewed. */

HANDLE FUN_405a2350(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  HANDLE pvVar1;
  
  if ((param_2 == (int *)0x0) || (param_4 == 0)) {
    pvVar1 = (HANDLE)0x0;
  }
  else {
    pvVar1 = FUN_405a21c4(param_1,param_2,param_3,param_4,4);
  }
  return pvVar1;
}



/* 405a238c FUN_405a238c */

/* Boundary evidence: original MIPS .pdata 405a238c..405a23c7. Semantic name remains unreviewed. */

HANDLE FUN_405a238c(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  HANDLE pvVar1;
  
  if ((param_2 == (int *)0x0) || (param_4 == 0)) {
    pvVar1 = (HANDLE)0x0;
  }
  else {
    pvVar1 = FUN_405a21c4(param_1,param_2,param_3,param_4,2);
  }
  return pvVar1;
}



/* 405a23c8 FUN_405a23c8 */

undefined4 * FUN_405a23c8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40572a70;
  param_1[2] = 0;
  param_1[1] = 1;
  return param_1;
}



/* 405a23e8 FUN_405a23e8 */

/* Boundary evidence: original MIPS .pdata 405a23e8..405a289f. Semantic name remains unreviewed. */

bool FUN_405a23e8(undefined4 param_1,LPCITEMIDLIST param_2,int param_3)

{
  wchar_t wVar1;
  uint uVar2;
  uint *puVar3;
  BOOL BVar4;
  UINT UVar5;
  HRESULT HVar6;
  int iVar7;
  int *piVar8;
  LPVOID lpParameter;
  size_t sVar9;
  void *pvVar10;
  HANDLE hObject;
  wchar_t *_Str;
  bool bVar11;
  wchar_t *_Src;
  undefined4 local_280;
  LPCITEMIDLIST local_27c;
  int *local_278;
  int *local_274;
  undefined4 local_270;
  undefined4 *local_26c [3];
  uint local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined2 local_248 [2];
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405a9a3c;
  BVar4 = OpenClipboard((HWND)0x0);
  if (BVar4 == 0) {
    FUN_405a7174(local_28);
    return false;
  }
  local_270 = 0;
  bVar11 = false;
  memset(local_26c,0,8);
  UVar5 = RegisterClipboardFormatW(L"SHELL_DATA_TRANSFER");
  local_26c[0] = (undefined4 *)GetClipboardDataAlloc(UVar5);
  if (local_26c[0] == (undefined4 *)0x0) {
    iVar7 = FUN_40588614();
    if (iVar7 != 0) {
      piVar8 = GetClipboardData(0xf);
      lpParameter = (LPVOID)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,0x1e);
      if (((piVar8 != (int *)0x0) && (iVar7 = SHGetPathFromIDList(param_2,awStack_230), iVar7 != 0))
         && (lpParameter != (LPVOID)0x0)) {
        iVar7 = *piVar8;
        uVar2 = (int)lpParameter + 3U & 3;
        puVar3 = (uint *)(((int)lpParameter + 3U) - uVar2);
        *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
        _Src = (wchar_t *)((int)piVar8 + iVar7);
        *(undefined1 *)((int)lpParameter + 0x10) = 0x40;
        uVar2 = (int)lpParameter + 0x15U & 3;
        puVar3 = (uint *)(((int)lpParameter + 0x15U) - uVar2);
        *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
        uVar2 = (int)lpParameter + 0x19U & 3;
        puVar3 = (uint *)(((int)lpParameter + 0x19U) - uVar2);
        *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
        uVar2 = (int)lpParameter + 0x1dU & 3;
        puVar3 = (uint *)(((int)lpParameter + 0x1dU) - uVar2);
        *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
        uVar2 = (uint)lpParameter & 3;
        *(uint *)((int)lpParameter - uVar2) =
             *(uint *)((int)lpParameter - uVar2) & 0xffffffffU >> (4 - uVar2) * 8 | 0 << uVar2 * 8;
        *(undefined4 *)((int)lpParameter + 4) = 2;
        *(undefined1 *)((int)lpParameter + 0x11) = 0;
        uVar2 = (int)lpParameter + 0x12U & 3;
        puVar3 = (uint *)(((int)lpParameter + 0x12U) - uVar2);
        *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0 << uVar2 * 8;
        uVar2 = (int)lpParameter + 0x16U & 3;
        puVar3 = (uint *)(((int)lpParameter + 0x16U) - uVar2);
        *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0 << uVar2 * 8;
        uVar2 = (int)lpParameter + 0x1aU & 3;
        puVar3 = (uint *)(((int)lpParameter + 0x1aU) - uVar2);
        *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0 << uVar2 * 8;
        wVar1 = *_Src;
        _Str = _Src;
        while (wVar1 != L'\0') {
          sVar9 = wcslen(_Str);
          _Str = _Str + sVar9 + 1;
          wVar1 = *_Str;
        }
        sVar9 = (((int)_Str - (int)_Src >> 1) + 1) * 2;
        pvVar10 = (void *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,sVar9);
        *(undefined4 *)((int)lpParameter + 8) = pvVar10;
        if (pvVar10 != (void *)0x0) {
          memcpy(pvVar10,_Src,sVar9);
          sVar9 = wcslen(awStack_230);
          sVar9 = (sVar9 + 1) * 2;
          pvVar10 = (void *)(**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,sVar9);
          *(void **)((int)lpParameter + 0xc) = pvVar10;
          if (pvVar10 != (void *)0x0) {
            memcpy(pvVar10,awStack_230,sVar9);
            hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_405a1248,lpParameter,0,
                                   (LPDWORD)0x0);
            if (hObject != (HANDLE)0x0) {
              CloseHandle(hObject);
              bVar11 = true;
              goto LAB_405a2868;
            }
          }
        }
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,*(undefined4 *)((int)lpParameter + 8));
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,*(undefined4 *)((int)lpParameter + 0xc));
        (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,lpParameter);
      }
    }
  }
  else {
    local_278 = (int *)0x0;
    local_27c = (LPCITEMIDLIST)0x0;
    HVar6 = SHBindToParent(param_2,(IID *)&DAT_40572b68,&local_278,&local_27c);
    if (-1 < HVar6) {
      local_274 = (int *)0x0;
      iVar7 = (**(code **)(*local_278 + 0x28))
                        (local_278,param_1,1,&local_27c,&DAT_40572b48,0,&local_274);
      if (-1 < iVar7) {
        piVar8 = operator_new(0xc);
        if (piVar8 == (int *)0x0) {
          piVar8 = (int *)0x0;
        }
        else {
          *piVar8 = (int)&PTR_FUN_40572a70;
          piVar8[2] = 0;
          piVar8[1] = 1;
        }
        if (piVar8 != (int *)0x0) {
          local_260 = 0;
          local_25c = 0;
          local_258 = 0;
          local_254 = 0;
          local_250 = 0;
          memset(&local_244,0,0x10);
          local_270 = 1;
          local_248[0] = (undefined2)UVar5;
          local_244 = 0;
          local_240 = 1;
          local_23c = 0xffffffff;
          local_238 = 1;
          iVar7 = (**(code **)(*piVar8 + 0x1c))(piVar8,local_248,&local_270,0);
          if ((-1 < iVar7) &&
             (iVar7 = FUN_405a0d88(local_26c[0],&local_260), uVar2 = local_260, iVar7 != 0)) {
            local_280 = 0;
            if (param_3 == 0) {
              if ((local_260 & 4) != 0) {
                local_280 = 2;
              }
              if ((local_260 & 2) != 0) {
                local_280 = 1;
              }
              if ((local_260 & 1) != 0) {
                local_280 = 4;
              }
            }
            else {
              local_280 = 4;
            }
            iVar7 = (**(code **)(*local_274 + 0x18))
                              (local_274,piVar8,0,0xffffffff,0xffffffff,&local_280);
            bVar11 = -1 < iVar7;
            if ((param_3 == 0) && ((uVar2 & 4) != 0)) {
              FUN_405a11c0();
            }
            FUN_405a0a1c((int)&local_260);
          }
          (**(code **)(*piVar8 + 8))(piVar8);
        }
        (**(code **)(*local_274 + 8))();
      }
      (**(code **)(*local_278 + 8))();
      FUN_40580ef4(local_27c);
    }
    LocalFree(local_26c[0]);
  }
LAB_405a2868:
  CloseClipboard();
  FUN_405a7174(local_28);
  return bVar11;
}



/* 405a28a0 FUN_405a28a0 */

/* Boundary evidence: original MIPS .pdata 405a28a0..405a29b3. Semantic name remains unreviewed. */

void FUN_405a28a0(int param_1)

{
  void *pvVar1;
  HLOCAL pvVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 8))();
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar4 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar3 = 0;
      do {
        pvVar2 = *(HLOCAL *)(iVar3 + *(int *)(param_1 + 0x10));
        if (pvVar2 != (HLOCAL)0x0) {
          FUN_40580ef4(pvVar2);
        }
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 4;
      } while (uVar4 < *(uint *)(param_1 + 0xc));
    }
    (**(code **)(*DAT_405aa0c8 + 0x14))(DAT_405aa0c8,*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    uVar4 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      iVar3 = 0;
      do {
        pvVar1 = *(void **)(*(int *)(param_1 + 0x18) + iVar3 + 4);
        if (pvVar1 != (void *)0x0) {
          operator_delete(pvVar1);
        }
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 8;
      } while (uVar4 < *(uint *)(param_1 + 0x14));
    }
    operator_delete(*(void **)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* 405a29b4 FUN_405a29b4 */

/* Boundary evidence: original MIPS .pdata 405a29b4..405a2ad3. Semantic name remains unreviewed. */

undefined4 FUN_405a29b4(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  HLOCAL pvVar2;
  uint uVar3;
  
  if (((param_2 != (int *)0x0) && (param_3 != 0)) && (param_4 != 0)) {
    *(int **)(param_1 + 8) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    *(int *)(param_1 + 0xc) = param_3;
    iVar1 = (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,param_3 << 2);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 != 0) {
      uVar3 = 0;
      if (*(int *)(param_1 + 0xc) != 0) {
        iVar1 = 0;
        do {
          if (*(ushort **)(iVar1 + param_4) == (ushort *)0x0) break;
          pvVar2 = FUN_405813a0(*(ushort **)(iVar1 + param_4),-1);
          *(HLOCAL *)(iVar1 + *(int *)(param_1 + 0x10)) = pvVar2;
          if (*(int *)(iVar1 + *(int *)(param_1 + 0x10)) == 0) break;
          uVar3 = uVar3 + 1;
          iVar1 = iVar1 + 4;
        } while (uVar3 < *(uint *)(param_1 + 0xc));
      }
      if (uVar3 == *(uint *)(param_1 + 0xc)) {
        return 1;
      }
    }
    FUN_405a28a0(param_1);
  }
  return 0;
}



/* 405a2ad4 FUN_405a2ad4 */

/* Boundary evidence: original MIPS .pdata 405a2ad4..405a2bab. Semantic name remains unreviewed. */

undefined4 FUN_405a2ad4(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    if ((((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
         (param_2[3] == 0x46000000)) ||
        (((*param_2 == 0x214e4 && (param_2[1] == 0)) &&
         ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) &&
       (*param_3 = (int)param_1, param_1 != (int *)0x0)) {
      (**(code **)(*param_1 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 405a2bac FUN_405a2bac */

/* Boundary evidence: original MIPS .pdata 405a2bac..405a2da7. Semantic name remains unreviewed. */

undefined4 FUN_405a2bac(int param_1,int param_2)

{
  HRESULT HVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 local_368;
  undefined1 auStack_364 [4];
  undefined4 local_360;
  uint local_35c;
  WCHAR *local_358;
  undefined4 local_34c;
  STRRET local_328;
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_405a9a3c;
  if (param_2 == 0) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80070057;
  }
  if (((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
     (puVar5 = *(uint **)(param_1 + 0x18), puVar5 == (uint *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x8000ffff;
  }
  local_368 = 0;
  memset(auStack_364,0,0x38);
  local_328.uType = 0;
  memset(&local_328.u,0,0x104);
  uVar2 = 0;
  if (*(uint *)(param_1 + 0x14) != 0) {
    puVar3 = puVar5;
    do {
      if ((uint)*(ushort *)(param_2 + 0xc) == *puVar3) {
        local_368 = 0x3c;
        local_360 = *(undefined4 *)(param_2 + 8);
        local_35c = puVar5[uVar2 * 2 + 1];
        local_34c = 1;
        break;
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 2;
    } while (uVar2 < *(uint *)(param_1 + 0x14));
  }
  if (local_35c != 0) {
    uVar2 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar6 = 0;
      do {
        (**(code **)(**(int **)(param_1 + 8) + 0x2c))
                  (*(int **)(param_1 + 8),*(undefined4 *)(iVar6 + *(int *)(param_1 + 0x10)),0x8000,
                   &local_328);
        HVar1 = StrRetToBufW(&local_328,*(LPCITEMIDLIST *)(iVar6 + *(int *)(param_1 + 0x10)),
                             aWStack_220,0x104);
        if (-1 < HVar1) {
          local_358 = aWStack_220;
          ShellExecuteEx(&local_368);
        }
        uVar2 = uVar2 + 1;
        iVar6 = iVar6 + 4;
      } while (uVar2 < *(uint *)(param_1 + 0xc));
    }
    if (local_35c != 0) {
      uVar4 = 0;
      goto LAB_405a2d6c;
    }
  }
  uVar4 = 0x80004005;
LAB_405a2d6c:
  FUN_405a7174(local_18);
  return uVar4;
}



/* 405a2da8 FUN_405a2da8 */

/* Boundary evidence: original MIPS .pdata 405a2da8..405a33cb. Semantic name remains unreviewed. */

DWORD FUN_405a2da8(int param_1,HMENU param_2,undefined4 param_3,int param_4)

{
  DWORD DVar1;
  LPWSTR lpSubKey;
  LSTATUS LVar2;
  void *pvVar3;
  STRSAFE_LPCWSTR pwVar4;
  BOOL BVar5;
  wchar_t *_Dest;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  DWORD dwIndex;
  HKEY local_350;
  DWORD local_34c;
  DWORD local_348 [2];
  STRRET local_340;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405a9a3c;
  if (param_2 == (HMENU)0x0) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x80070057;
  }
  piVar8 = *(int **)(param_1 + 8);
  if ((piVar8 == (int *)0x0) ||
     (puVar9 = *(undefined4 **)(param_1 + 0x10), puVar9 == (undefined4 *)0x0)) {
    FUN_405a7174(DAT_405a9a3c);
    return 0x8000ffff;
  }
  local_340.uType = 0;
  memset(&local_340.u,0,0x104);
  local_350 = (HKEY)0x0;
  local_348[0] = 0;
  dwIndex = 0;
  DVar1 = (**(code **)(*piVar8 + 0x2c))(piVar8,*puVar9,0x8001,&local_340);
  if (((((int)DVar1 < 0) ||
       (DVar1 = StrRetToBufW(&local_340,(LPCITEMIDLIST)**(undefined4 **)(param_1 + 0x10),aWStack_238
                             ,0x104), (int)DVar1 < 0)) ||
      (lpSubKey = PathFindExtensionW(aWStack_238), lpSubKey == (LPWSTR)0x0)) || (*lpSubKey == L'\0')
     ) goto LAB_405a3350;
  LVar2 = RegOpenKeyExW((HKEY)0x80000000,lpSubKey,0,0,&local_350);
  if (LVar2 == 0) {
    local_34c = 0x208;
    LVar2 = RegQueryValueExW(local_350,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)aWStack_238,
                             &local_34c);
    if (LVar2 == 0) {
      DVar1 = StringCbCatW(aWStack_238,0x208,L"\\Shell");
      if ((int)DVar1 < 0) goto LAB_405a3350;
      RegCloseKey(local_350);
      local_350 = (HKEY)0x0;
      LVar2 = RegOpenKeyExW((HKEY)0x80000000,aWStack_238,0,0,&local_350);
      if ((LVar2 == 0) &&
         (LVar2 = RegQueryInfoKeyW(local_350,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,local_348,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(PFILETIME)0x0), LVar2 == 0)) {
        if (local_348[0] != 0) {
          *(undefined4 *)(param_1 + 0x14) = 0;
          if (*(void **)(param_1 + 0x18) != (void *)0x0) {
            operator_delete(*(void **)(param_1 + 0x18));
          }
          uVar7 = local_348[0] << 3;
          if (0x1fffffff < local_348[0]) {
            uVar7 = 0xffffffff;
          }
          pvVar3 = operator_new(uVar7);
          *(void **)(param_1 + 0x18) = pvVar3;
          if (pvVar3 == (void *)0x0) {
LAB_405a3348:
            DVar1 = 0x8007000e;
          }
          else {
            uVar7 = 0;
            if (local_348[0] != 0) {
              iVar6 = 0;
              do {
                *(undefined4 *)(iVar6 + *(int *)(param_1 + 0x18)) = 0;
                *(undefined4 *)(iVar6 + *(int *)(param_1 + 0x18) + 4) = 0;
                uVar7 = uVar7 + 1;
                iVar6 = iVar6 + 8;
              } while (uVar7 < local_348[0]);
            }
            local_34c = 0x104;
            iVar6 = RegEnumKeyExW(local_350,0,aWStack_238,&local_34c,(LPDWORD)0x0,(LPWSTR)0x0,
                                  (LPDWORD)0x0,(PFILETIME)0x0);
            while (iVar6 == 0) {
              iVar6 = CompareStringW(0x409,1,aWStack_238,-1,L"open",-1);
              if (iVar6 == 2) {
                local_348[0] = local_348[0] - 1;
              }
              else {
                uVar7 = (local_34c + 1) * 2;
                if (0x7fffffff < local_34c + 1) {
                  uVar7 = 0xffffffff;
                }
                pvVar3 = operator_new(uVar7);
                *(void **)(*(int *)(param_1 + 0x14) * 8 + *(int *)(param_1 + 0x18) + 4) = pvVar3;
                _Dest = *(wchar_t **)(*(int *)(param_1 + 0x14) * 8 + *(int *)(param_1 + 0x18) + 4);
                if (_Dest == (wchar_t *)0x0) goto LAB_405a3348;
                wcscpy(_Dest,aWStack_238);
                iVar6 = CompareStringW(0x409,1,aWStack_238,-1,L"edit",-1);
                if (iVar6 == 2) {
                  pwVar4 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3077,(LPWSTR)0x0,0);
                  StringCchCopyExW(aWStack_238,0x104,pwVar4,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,
                                   0x800);
                }
                iVar6 = CompareStringW(0x409,1,aWStack_238,-1,L"print",-1);
                if (iVar6 == 2) {
                  pwVar4 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405aa0c0,0x3078,(LPWSTR)0x0,0);
                  StringCchCopyExW(aWStack_238,0x104,pwVar4,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,
                                   0x800);
                }
                else {
                  local_34c = 0x208;
                  LVar2 = RegQueryValueExW(local_350,(LPCWSTR)0x0,(LPDWORD)aWStack_238,(LPDWORD)0x0,
                                           (LPBYTE)aWStack_238,&local_34c);
                  if (LVar2 != 0) {
                    wcscpy(aWStack_238,
                           *(wchar_t **)
                            (*(int *)(param_1 + 0x14) * 8 + *(int *)(param_1 + 0x18) + 4));
                  }
                }
                BVar5 = InsertMenuW(param_2,1,0x400,*(int *)(param_1 + 0x14) + param_4,aWStack_238);
                iVar6 = *(int *)(param_1 + 0x14);
                if (BVar5 == 0) {
                  operator_delete(*(void **)(iVar6 * 8 + *(int *)(param_1 + 0x18) + 4));
                  *(undefined4 *)(*(int *)(param_1 + 0x14) * 8 + *(int *)(param_1 + 0x18) + 4) = 0;
                }
                else {
                  *(int *)(iVar6 * 8 + *(int *)(param_1 + 0x18)) = iVar6 + param_4;
                  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
                }
              }
              local_34c = 0x104;
              dwIndex = dwIndex + 1;
              iVar6 = RegEnumKeyExW(local_350,dwIndex,aWStack_238,&local_34c,(LPDWORD)0x0,
                                    (LPWSTR)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
            }
          }
        }
        goto LAB_405a3350;
      }
    }
  }
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
LAB_405a3350:
  if (local_350 != (HKEY)0x0) {
    RegCloseKey(local_350);
  }
  if (-1 < (int)DVar1) {
    DVar1 = *(int *)(param_1 + 0x14) + 1;
  }
  FUN_405a7174(local_30);
  return DVar1;
}



/* 405a33cc FUN_405a33cc */

undefined4 * FUN_405a33cc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40572ad4;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[1] = 1;
  return param_1;
}



/* 405a33fc FUN_405a33fc */

/* Boundary evidence: original MIPS .pdata 405a33fc..405a344b. Semantic name remains unreviewed. */

int FUN_405a33fc(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_40572ad4;
    FUN_405a28a0((int)param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 405a344c FUN_405a344c */

/* Boundary evidence: original MIPS .pdata 405a344c..405a34af. Semantic name remains unreviewed. */

LRESULT FUN_405a344c(HWND param_1,WPARAM param_2,uint param_3)

{
  LRESULT LVar1;
  BOOL BVar2;
  
  LVar1 = SendMessageW(param_1,0x100c,param_2,param_3 & 0xffff);
  if ((LVar1 == 0) && (BVar2 = IsWindow(param_1), BVar2 == 0)) {
    LVar1 = -1;
  }
  return LVar1;
}



/* 405a34b0 FUN_405a34b0 */

undefined4 * FUN_405a34b0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  param_1[3] = 0;
  return param_1;
}



/* 405a34cc FUN_405a34cc */

/* Boundary evidence: original MIPS .pdata 405a34cc..405a356f. Semantic name remains unreviewed. */

bool FUN_405a34cc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  LRESULT LVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  WPARAM local_24;
  
  memset(&local_34,0,0x1c);
  local_24 = param_1[1];
  local_38 = 0xf;
  local_34 = param_4;
  local_30 = param_3;
  local_2c = param_2;
  LVar1 = SendMessageW((HWND)*param_1,0x1061,local_24,(LPARAM)&local_38);
  if (LVar1 != -1) {
    param_1[1] = param_1[1] + 1;
  }
  return LVar1 != -1;
}



/* 405a3570 FUN_405a3570 */

/* Boundary evidence: original MIPS .pdata 405a3570..405a3597. Semantic name remains unreviewed. */

void FUN_405a3570(undefined4 *param_1)

{
  SendMessageW((HWND)*param_1,0x1016,0,0);
  return;
}



/* 405a3598 FUN_405a3598 */

/* Boundary evidence: original MIPS .pdata 405a3598..405a399f. Semantic name remains unreviewed. */

BOOL FUN_405a3598(int *param_1,int param_2)

{
  uint uVar1;
  int *_Dst;
  HIMAGELIST himl;
  HICON pHVar2;
  BOOL BVar3;
  HIMAGELIST p_Var4;
  void *pvVar5;
  WPARAM WVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  uVar1 = SendMessageW((HWND)*param_1,0x1032,0,0);
  if ((param_2 != 0) && (uVar1 != 0)) {
    _Dst = operator_new(0x14);
    if (_Dst == (int *)0x0) {
      _Dst = (int *)0x0;
    }
    else {
      memset(_Dst,0,0x14);
    }
    DAT_405aa32c = _Dst;
    if (_Dst != (int *)0x0) {
      memset(_Dst,0,0x14);
      local_30 = 0;
      memset(&local_2c,0,4);
      local_38 = 0;
      memset(&local_34,0,4);
      SendMessageW((HWND)*param_1,0x1029,0,(LPARAM)&local_30);
      if (uVar1 < 2) {
        himl = (HIMAGELIST)
               SendMessageW((HWND)*param_1,0x1021,*(WPARAM *)(param_2 + 0xc),(LPARAM)&local_38);
        if (himl != (HIMAGELIST)0x0) {
LAB_405a37b4:
          BVar3 = ImageList_BeginDrag(himl,0,*(int *)(param_2 + 0x20) - local_38,
                                      *(int *)(param_2 + 0x24) - local_34);
          if (BVar3 != 0) {
            p_Var4 = ImageList_Create(0x20,0x20,1,4,1);
            *DAT_405aa32c = (int)p_Var4;
            iVar7 = *DAT_405aa32c;
            for (uVar9 = 0; (iVar7 != 0 && (uVar9 < 4)); uVar9 = uVar9 + 1) {
              pHVar2 = LoadImageW(DAT_405aa0c0,(LPCWSTR)(uVar9 + 0x1001 & 0xffff),1,0x20,0x20,0);
              if (pHVar2 == (HICON)0x0) {
                ImageList_Destroy((HIMAGELIST)*DAT_405aa32c);
                *DAT_405aa32c = 0;
              }
              else {
                ImageList_ReplaceIcon((HIMAGELIST)*DAT_405aa32c,-1,pHVar2);
                DestroyIcon(pHVar2);
              }
              iVar7 = *DAT_405aa32c;
            }
            DAT_405aa32c[1] = *param_1;
            DAT_405aa32c[2] = *(int *)(param_2 + 0x20) + local_30;
            DAT_405aa32c[3] = *(int *)(param_2 + 0x24) + local_2c;
            uVar9 = (uVar1 + 1) * 4;
            if (0x3fffffff < uVar1 + 1) {
              uVar9 = 0xffffffff;
            }
            pvVar5 = operator_new(uVar9);
            DAT_405aa32c[4] = (int)pvVar5;
            if (DAT_405aa32c[4] != 0) {
              WVar6 = FUN_405a344c((HWND)*param_1,0xffffffff,2);
              uVar9 = 0;
              if (uVar1 != 0) {
                iVar7 = 0;
                uVar8 = uVar1;
                do {
                  *(WPARAM *)(DAT_405aa32c[4] + iVar7) = WVar6;
                  WVar6 = FUN_405a344c((HWND)*param_1,WVar6,2);
                  uVar8 = uVar8 - 1;
                  iVar7 = iVar7 + 4;
                  uVar9 = uVar1;
                } while (uVar8 != 0);
              }
              *(undefined4 *)(DAT_405aa32c[4] + uVar9 * 4) = 0xffffffff;
            }
          }
          ImageList_Destroy(himl);
          return BVar3;
        }
      }
      else {
        himl = ImageList_Create(0x20,0x20,1,1,1);
        if (himl != (HIMAGELIST)0x0) {
          pHVar2 = LoadImageW(DAT_405aa0c0,(LPCWSTR)0x1000,1,0x20,0x20,0);
          if (pHVar2 != (HICON)0x0) {
            ImageList_ReplaceIcon(himl,-1,pHVar2);
            DestroyIcon(pHVar2);
            SendMessageW((HWND)*param_1,0x1010,*(WPARAM *)(param_2 + 0xc),(LPARAM)&local_38);
            local_38 = local_38 - local_30;
            local_34 = local_34 - local_2c;
            goto LAB_405a37b4;
          }
          ImageList_Destroy(himl);
        }
      }
    }
  }
  return 0;
}



/* 405a39a0 FUN_405a39a0 */

/* Boundary evidence: original MIPS .pdata 405a39a0..405a39c7. Semantic name remains unreviewed. */

void FUN_405a39a0(undefined4 *param_1)

{
  SendMessageW((HWND)*param_1,0x1009,0,0);
  return;
}



/* 405a39c8 FUN_405a39c8 */

/* Boundary evidence: original MIPS .pdata 405a39c8..405a3a5b. Semantic name remains unreviewed. */

void FUN_405a39c8(undefined4 *param_1)

{
  LRESULT LVar1;
  undefined1 auStack_40 [12];
  undefined4 local_34;
  undefined4 local_30;
  
  ImageList_DragLeave((HWND)0x0);
  if ((param_1[2] != 0xffffffff) &&
     (LVar1 = SendMessageW((HWND)*param_1,0x102c,param_1[2],8), LVar1 == 8)) {
    local_30 = 8;
    local_34 = 0;
    SendMessageW((HWND)*param_1,0x102b,param_1[2],(LPARAM)auStack_40);
    UpdateWindow((HWND)*param_1);
  }
  param_1[2] = 0xffffffff;
  return;
}



/* 405a3a5c FUN_405a3a5c */

/* Boundary evidence: original MIPS .pdata 405a3a5c..405a3af3. Semantic name remains unreviewed. */

void FUN_405a3a5c(undefined4 *param_1)

{
  if (DAT_405aa32c != (undefined4 *)0x0) {
    if ((HIMAGELIST)*DAT_405aa32c != (HIMAGELIST)0x0) {
      ImageList_Destroy((HIMAGELIST)*DAT_405aa32c);
    }
    if ((void *)DAT_405aa32c[4] != (void *)0x0) {
      operator_delete((void *)DAT_405aa32c[4]);
    }
    operator_delete(DAT_405aa32c);
    DAT_405aa32c = (undefined4 *)0x0;
  }
  if ((HWND)*param_1 != (HWND)0x0) {
    DestroyWindow((HWND)*param_1);
    *param_1 = 0;
  }
  return;
}



/* 405a3af4 FUN_405a3af4 */

/* Boundary evidence: original MIPS .pdata 405a3af4..405a3c43. Semantic name remains unreviewed. */

void FUN_405a3af4(int *param_1,int param_2,int param_3)

{
  LRESULT LVar1;
  WPARAM wParam;
  int iVar2;
  int iVar3;
  int local_30;
  int local_2c;
  tagPOINT local_28;
  int local_20;
  int local_1c;
  
  local_30 = 0;
  memset(&local_2c,0,4);
  local_28.x = param_2;
  local_28.y = param_3;
  ScreenToClient((HWND)*param_1,&local_28);
  SendMessageW((HWND)*param_1,0x1029,0,(LPARAM)&local_30);
  iVar2 = local_28.x + local_30;
  iVar3 = local_2c + local_28.y;
  if ((DAT_405aa32c != 0) && (*param_1 == *(int *)(DAT_405aa32c + 4))) {
    iVar2 = iVar2 - *(int *)(DAT_405aa32c + 8);
    iVar3 = iVar3 - *(int *)(DAT_405aa32c + 0xc);
  }
  local_20 = 0;
  memset(&local_1c,0,4);
  wParam = 0xffffffff;
  while (wParam = FUN_405a344c((HWND)*param_1,wParam,2), wParam != 0xffffffff) {
    LVar1 = SendMessageW((HWND)*param_1,0x1010,wParam,(LPARAM)&local_20);
    if (LVar1 != 0) {
      SendMessageW((HWND)*param_1,0x100f,wParam,
                   (local_1c + iVar3) * 0x10000 | local_20 + iVar2 & 0xffffU);
    }
  }
  return;
}



/* 405a3c44 FUN_405a3c44 */

/* Boundary evidence: original MIPS .pdata 405a3c44..405a3cdf. Semantic name remains unreviewed. */

void FUN_405a3c44(undefined4 *param_1)

{
  if (param_1[2] != -1) {
    FUN_405a39c8(param_1);
  }
  ImageList_EndDrag();
  if (DAT_405aa32c != (undefined4 *)0x0) {
    if ((HIMAGELIST)*DAT_405aa32c != (HIMAGELIST)0x0) {
      ImageList_Destroy((HIMAGELIST)*DAT_405aa32c);
    }
    if ((void *)DAT_405aa32c[4] != (void *)0x0) {
      operator_delete((void *)DAT_405aa32c[4]);
    }
    operator_delete(DAT_405aa32c);
    DAT_405aa32c = (undefined4 *)0x0;
  }
  return;
}



/* 405a3ce0 FUN_405a3ce0 */

/* Boundary evidence: original MIPS .pdata 405a3ce0..405a3dc7. Semantic name remains unreviewed. */

int FUN_405a3ce0(undefined4 *param_1,char *param_2)

{
  LRESULT LVar1;
  LRESULT LVar2;
  int iVar3;
  undefined4 local_48;
  int local_44 [7];
  char *local_28;
  
  if (param_2 != (char *)0x0) {
    LVar1 = SendMessageW((HWND)*param_1,0x1004,0,0);
    memset(local_44,0,0x28);
    local_48 = 4;
    if ((LVar1 != 0) && (local_44[0] < LVar1)) {
      while (LVar2 = SendMessageW((HWND)*param_1,0x104b,0,(LPARAM)&local_48), LVar2 != 0) {
        iVar3 = FUN_405810a4(param_2,local_28);
        if (iVar3 != 0) {
          return local_44[0];
        }
        local_44[0] = local_44[0] + 1;
        if (LVar1 <= local_44[0]) {
          return -1;
        }
      }
    }
  }
  return -1;
}



/* 405a3dc8 FUN_405a3dc8 */

/* Boundary evidence: original MIPS .pdata 405a3dc8..405a3ecf. Semantic name remains unreviewed. */

undefined4 FUN_405a3dc8(undefined4 *param_1)

{
  WPARAM wParam;
  LRESULT LVar1;
  tagPOINT local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  local_30.x = 0;
  memset(&local_30.y,0,4);
  wParam = FUN_405a344c((HWND)*param_1,0xffffffff,2);
  if (wParam != 0xffffffff) {
    memset(&local_24,0,0xc);
    local_28 = 1;
    LVar1 = SendMessageW((HWND)*param_1,0x100e,wParam,(LPARAM)&local_28);
    if (LVar1 != 0) {
      local_20 = local_20 + local_28;
      if (local_20 < 0) {
        local_20 = local_20 + 1;
      }
      local_30.x = local_20 >> 1;
      local_1c = local_1c + local_24;
      if (local_1c < 0) {
        local_1c = local_1c + 1;
      }
      local_30.y = local_1c >> 1;
    }
  }
  MapWindowPoints((HWND)*param_1,(HWND)0x0,&local_30,1);
  return CONCAT22((undefined2)local_30.y,(undefined2)local_30.x);
}



/* 405a3ed0 FUN_405a3ed0 */

/* Boundary evidence: original MIPS .pdata 405a3ed0..405a3f4f. Semantic name remains unreviewed. */

undefined4 FUN_405a3ed0(undefined4 *param_1,int param_2)

{
  LRESULT LVar1;
  undefined4 uVar2;
  undefined4 local_40;
  int local_3c [7];
  undefined4 local_20;
  
  memset(local_3c,0,0x28);
  local_40 = 4;
  uVar2 = 0;
  if ((param_2 != -1) &&
     (local_3c[0] = param_2, LVar1 = SendMessageW((HWND)*param_1,0x104b,0,(LPARAM)&local_40),
     LVar1 != 0)) {
    uVar2 = local_20;
  }
  return uVar2;
}



/* 405a3f50 FUN_405a3f50 */

/* Boundary evidence: original MIPS .pdata 405a3f50..405a3fdb. Semantic name remains unreviewed. */

undefined4 FUN_405a3f50(undefined4 *param_1,char *param_2)

{
  LRESULT LVar1;
  undefined4 uVar2;
  undefined4 local_40;
  int local_3c [7];
  undefined4 local_20;
  
  memset(local_3c,0,0x28);
  local_40 = 4;
  local_3c[0] = FUN_405a3ce0(param_1,param_2);
  uVar2 = 0;
  if ((local_3c[0] != -1) &&
     (LVar1 = SendMessageW((HWND)*param_1,0x104b,0,(LPARAM)&local_40), LVar1 != 0)) {
    uVar2 = local_20;
  }
  return uVar2;
}



/* 405a3fdc FUN_405a3fdc */

/* Boundary evidence: original MIPS .pdata 405a3fdc..405a4103. Semantic name remains unreviewed. */

undefined4 FUN_405a3fdc(int *param_1,LONG param_2,LONG param_3)

{
  LRESULT LVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  tagPOINT local_60 [3];
  undefined4 local_48;
  int local_44 [7];
  undefined4 local_28;
  
  memset(&local_60[0].y,0,0x10);
  local_48 = 0;
  memset(local_44,0,0x28);
  local_60[0].x = param_2;
  local_60[0].y = param_3;
  ScreenToClient((HWND)*param_1,local_60);
  local_44[0] = SendMessageW((HWND)*param_1,0x1012,0,(LPARAM)local_60);
  if ((DAT_405aa32c != 0) && (*param_1 == *(int *)(DAT_405aa32c + 4))) {
    iVar3 = 0;
    iVar2 = **(int **)(DAT_405aa32c + 0x10);
    while (iVar2 != -1) {
      if (local_44[0] == iVar2) {
        local_44[0] = -1;
        break;
      }
      iVar3 = iVar3 + 1;
      iVar2 = (*(int **)(DAT_405aa32c + 0x10))[iVar3];
    }
  }
  uVar4 = 0;
  if (local_44[0] != -1) {
    local_48 = 4;
    LVar1 = SendMessageW((HWND)*param_1,0x104b,0,(LPARAM)&local_48);
    if (LVar1 != 0) {
      uVar4 = local_28;
    }
  }
  return uVar4;
}



/* 405a4104 FUN_405a4104 */

/* Boundary evidence: original MIPS .pdata 405a4104..405a4223. Semantic name remains unreviewed. */

int FUN_405a4104(undefined4 *param_1,LRESULT *param_2)

{
  LRESULT LVar1;
  LRESULT LVar2;
  WPARAM WVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_50;
  WPARAM local_4c [7];
  undefined4 local_30;
  
  iVar5 = 0;
  LVar1 = SendMessageW((HWND)*param_1,0x1032,0,0);
  if (LVar1 != 0) {
    iVar5 = (**(code **)(*DAT_405aa0c8 + 0xc))(DAT_405aa0c8,LVar1 * 4);
    if (iVar5 == 0) {
      LVar1 = 0;
    }
    else {
      puVar4 = (undefined4 *)(LVar1 * 4 + iVar5);
      memset(local_4c,0,0x28);
      local_50 = 4;
      WVar3 = 0xffffffff;
      while( true ) {
        puVar4 = puVar4 + -1;
        local_4c[0] = FUN_405a344c((HWND)*param_1,WVar3,2);
        if (local_4c[0] == 0xffffffff) break;
        LVar2 = SendMessageW((HWND)*param_1,0x104b,0,(LPARAM)&local_50);
        WVar3 = local_4c[0];
        if (LVar2 != 0) {
          *puVar4 = local_30;
        }
      }
    }
  }
  if (param_2 != (LRESULT *)0x0) {
    *param_2 = LVar1;
  }
  return iVar5;
}



/* 405a4224 FUN_405a4224 */

/* Boundary evidence: original MIPS .pdata 405a4224..405a42c3. Semantic name remains unreviewed. */

undefined4 FUN_405a4224(undefined4 param_1,uint param_2)

{
  int iDrag;
  undefined4 uVar1;
  
  if ((DAT_405aa32c == (int *)0x0) || (*DAT_405aa32c == 0)) {
    uVar1 = 0;
  }
  else {
    iDrag = 2;
    uVar1 = 1;
    if ((param_2 & 2) == 2) {
      iDrag = 1;
    }
    else if ((param_2 & 1) == 1) {
      iDrag = 0;
    }
    else if ((param_2 & 4) != 4) {
      iDrag = 3;
    }
    ImageList_SetDragCursorImage((HIMAGELIST)*DAT_405aa32c,iDrag,0,0);
  }
  return uVar1;
}



/* 405a42c4 FUN_405a42c4 */

/* Boundary evidence: original MIPS .pdata 405a42c4..405a431b. Semantic name remains unreviewed. */

void FUN_405a42c4(undefined4 *param_1)

{
  HWND hWnd;
  
  hWnd = (HWND)SendMessageW((HWND)*param_1,0x1018,0,0);
  if (hWnd == (HWND)0x0) {
    hWnd = (HWND)*param_1;
  }
  SendMessageW(hWnd,0x100,0x1b,0);
  return;
}



/* 405a431c FUN_405a431c */

/* Boundary evidence: original MIPS .pdata 405a431c..405a43df. Semantic name remains unreviewed. */

void FUN_405a431c(undefined4 *param_1)

{
  LRESULT LVar1;
  BOOL BVar2;
  tagPOINT local_48;
  undefined1 auStack_40 [12];
  undefined4 local_34;
  undefined4 local_30;
  
  if ((param_1[2] != 0xffffffff) &&
     (LVar1 = SendMessageW((HWND)*param_1,0x102c,param_1[2],8), LVar1 != 8)) {
    local_48.x = 0;
    memset(&local_48.y,0,4);
    BVar2 = GetCursorPos(&local_48);
    if (BVar2 != 0) {
      ImageList_DragLeave((HWND)0x0);
      local_30 = 8;
      local_34 = 8;
      SendMessageW((HWND)*param_1,0x102b,param_1[2],(LPARAM)auStack_40);
      UpdateWindow((HWND)*param_1);
      ImageList_DragEnter((HWND)0x0,local_48.x,local_48.y);
    }
  }
  return;
}



/* 405a43e0 FUN_405a43e0 */

/* Boundary evidence: original MIPS .pdata 405a43e0..405a4403. Semantic name remains unreviewed. */

uint FUN_405a43e0(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = GetWindowLongW((HWND)*param_1,-0x10);
  return uVar1 & 0x100;
}



/* 405a4404 FUN_405a4404 */

/* Boundary evidence: original MIPS .pdata 405a4404..405a4523. Semantic name remains unreviewed. */

void FUN_405a4404(undefined4 *param_1,char *param_2,int param_3)

{
  WPARAM wParam;
  LRESULT LVar1;
  UINT Msg;
  RECT local_58;
  undefined4 local_48;
  WPARAM local_44;
  int local_40;
  undefined4 local_34;
  undefined4 local_2c;
  
  local_48 = 0;
  memset(&local_44,0,0x28);
  wParam = FUN_405a3ce0(param_1,param_2);
  if (wParam != 0xffffffff) {
    local_58.left = 0;
    local_44 = wParam;
    memset(&local_58.top,0,0xc);
    if (param_3 == 0) {
      SendMessageW((HWND)*param_1,0x102a,wParam,0);
      local_48 = 3;
      local_34 = 0xffffffff;
      local_2c = 0xffffffff;
      SendMessageW((HWND)*param_1,0x104c,0,(LPARAM)&local_48);
      local_58.left = 3;
      Msg = 0x100e;
    }
    else {
      local_48 = 1;
      local_34 = 0xffffffff;
      local_40 = param_3;
      SendMessageW((HWND)*param_1,0x104c,0,(LPARAM)&local_48);
      local_58.left = 0;
      Msg = 0x1038;
      local_58.top = param_3;
    }
    LVar1 = SendMessageW((HWND)*param_1,Msg,local_44,(LPARAM)&local_58);
    if (LVar1 != 0) {
      InvalidateRect((HWND)*param_1,&local_58,0);
    }
  }
  return;
}



/* 405a4524 FUN_405a4524 */

/* Boundary evidence: original MIPS .pdata 405a4524..405a456f. Semantic name remains unreviewed. */

void FUN_405a4524(int param_1,ushort *param_2)

{
  HLOCAL pvVar1;
  
  if (*(HLOCAL *)(param_1 + 0xc) != (HLOCAL)0x0) {
    FUN_40580ef4(*(HLOCAL *)(param_1 + 0xc));
  }
  pvVar1 = FUN_405813a0(param_2,-1);
  *(HLOCAL *)(param_1 + 0xc) = pvVar1;
  return;
}



/* 405a4570 FUN_405a4570 */

/* Boundary evidence: original MIPS .pdata 405a4570..405a45ef. Semantic name remains unreviewed. */

void FUN_405a4570(undefined4 *param_1)

{
  LRESULT LVar1;
  undefined4 local_38;
  undefined1 auStack_34 [8];
  undefined4 local_2c;
  undefined4 local_28;
  
  LVar1 = SendMessageW((HWND)*param_1,0x1042,0,0);
  if (LVar1 == -1) {
    memset(auStack_34,0,0x28);
    local_38 = 8;
    local_28 = 1;
    local_2c = 1;
    SendMessageW((HWND)*param_1,0x104c,0,(LPARAM)&local_38);
  }
  SetFocus((HWND)*param_1);
  return;
}



/* 405a45f0 FUN_405a45f0 */

/* Boundary evidence: original MIPS .pdata 405a45f0..405a4707. Semantic name remains unreviewed. */

undefined4 FUN_405a45f0(int *param_1,ushort *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_48;
  WPARAM local_44 [2];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2c;
  HLOCAL local_28;
  
  uVar2 = 0;
  if (param_2 != (ushort *)0x0) {
    memset(local_44,0,0x28);
    local_48 = 7;
    local_34 = 0xffffffff;
    local_2c = 0xffffffff;
    local_44[0] = SendMessageW((HWND)*param_1,0x1004,0,0);
    local_28 = FUN_405813a0(param_2,1);
    iVar1 = FUN_405a1760(*param_1,(char *)param_2);
    if (iVar1 != 0) {
      local_48 = local_48 | 8;
      local_38 = 4;
      local_3c = 4;
    }
    local_44[0] = SendMessageW((HWND)*param_1,0x104d,0,(LPARAM)&local_48);
    if (local_44[0] != 0xffffffff) {
      uVar2 = 1;
      if (((char *)param_1[3] != (char *)0x0) &&
         (iVar1 = FUN_405810a4((char *)param_1[3],(char *)param_2), iVar1 != 0)) {
        SendMessageW((HWND)*param_1,0x1076,local_44[0],0);
        FUN_40580ef4((HLOCAL)param_1[3]);
        param_1[3] = 0;
      }
    }
  }
  return uVar2;
}



/* 405a4708 FUN_405a4708 */

/* Boundary evidence: original MIPS .pdata 405a4708..405a476f. Semantic name remains unreviewed. */

undefined4 FUN_405a4708(undefined4 *param_1,char *param_2)

{
  WPARAM wParam;
  LRESULT LVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_2 != (char *)0x0) && (wParam = FUN_405a3ce0(param_1,param_2), wParam != 0xffffffff))
     && (LVar1 = SendMessageW((HWND)*param_1,0x1008,wParam,0), LVar1 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* 405a4770 FUN_405a4770 */

/* Boundary evidence: original MIPS .pdata 405a4770..405a47a3. Semantic name remains unreviewed. */

void FUN_405a4770(undefined4 *param_1,int param_2,int param_3)

{
  MoveWindow((HWND)*param_1,0,0,param_2,param_3,1);
  return;
}



/* 405a47a4 FUN_405a47a4 */

/* Boundary evidence: original MIPS .pdata 405a47a4..405a4823. Semantic name remains unreviewed. */

void FUN_405a47a4(undefined4 *param_1)

{
  uint uVar1;
  LRESULT LVar2;
  WPARAM wParam;
  
  uVar1 = SendMessageW((HWND)*param_1,0x1032,0,0);
  if ((uVar1 < 2) && (LVar2 = SendMessageW((HWND)*param_1,0x1018,0,0), LVar2 == 0)) {
    wParam = FUN_405a344c((HWND)*param_1,0xffffffff,2);
    SendMessageW((HWND)*param_1,0x1076,wParam,0);
  }
  return;
}



/* 405a4824 FUN_405a4824 */

/* Boundary evidence: original MIPS .pdata 405a4824..405a4887. Semantic name remains unreviewed. */

void FUN_405a4824(undefined4 *param_1)

{
  LRESULT LVar1;
  undefined1 auStack_38 [12];
  undefined4 local_2c;
  undefined4 local_28;
  
  LVar1 = SendMessageW((HWND)*param_1,0x1018,0,0);
  if (LVar1 != 0) {
    SetFocus((HWND)*param_1);
  }
  local_28 = 2;
  local_2c = 2;
  SendMessageW((HWND)*param_1,0x102b,0xffffffff,(LPARAM)auStack_38);
  return;
}



/* 405a4888 FUN_405a4888 */

/* Boundary evidence: original MIPS .pdata 405a4888..405a48fb. Semantic name remains unreviewed. */

void FUN_405a4888(undefined4 *param_1,LPARAM param_2,LPARAM param_3,LPARAM param_4)

{
  SendMessageW((HWND)*param_1,0x1001,0,param_2);
  SendMessageW((HWND)*param_1,0x1024,0,param_3);
  SendMessageW((HWND)*param_1,0x1026,0,param_4);
  return;
}



/* 405a48fc FUN_405a48fc */

/* Boundary evidence: original MIPS .pdata 405a48fc..405a4923. Semantic name remains unreviewed. */

void FUN_405a48fc(undefined4 *param_1,WPARAM param_2)

{
  SendMessageW((HWND)*param_1,0xb,param_2,0);
  return;
}



/* 405a4924 FUN_405a4924 */

/* Boundary evidence: original MIPS .pdata 405a4924..405a49cb. Semantic name remains unreviewed. */

undefined4 FUN_405a4924(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = GetWindowLongW((HWND)*param_1,-0x10);
  uVar2 = 1;
  uVar1 = uVar1 & 0xfffffffc;
  if (param_2 != 1) {
    if (param_2 == 2) {
      uVar1 = uVar1 | 2;
      uVar2 = 2;
    }
    else if (param_2 == 3) {
      uVar1 = uVar1 | 3;
      uVar2 = 3;
    }
    else if (param_2 == 4) {
      uVar1 = uVar1 | 1;
      uVar2 = 4;
    }
  }
  SetWindowLongW((HWND)*param_1,-0x10,uVar1);
  return uVar2;
}



/* 405a49cc FUN_405a49cc */

/* Boundary evidence: original MIPS .pdata 405a49cc..405a4a5f. Semantic name remains unreviewed. */

void FUN_405a49cc(undefined4 *param_1)

{
  WPARAM wParam;
  undefined1 auStack_48 [12];
  undefined4 local_3c;
  undefined4 local_38;
  
  for (wParam = FUN_405a344c((HWND)*param_1,0xffffffff,2); wParam != 0xffffffff;
      wParam = FUN_405a344c((HWND)*param_1,wParam,2)) {
    local_38 = 4;
    local_3c = 4;
    SendMessageW((HWND)*param_1,0x102b,wParam,(LPARAM)auStack_48);
  }
  return;
}



/* 405a4a60 FUN_405a4a60 */

/* Boundary evidence: original MIPS .pdata 405a4a60..405a4a87. Semantic name remains unreviewed. */

void FUN_405a4a60(undefined4 *param_1)

{
  SendMessageW((HWND)*param_1,0x1016,5,0);
  return;
}



/* 405a4a88 FUN_405a4a88 */

/* Boundary evidence: original MIPS .pdata 405a4a88..405a4aff. Semantic name remains unreviewed. */

void FUN_405a4a88(undefined4 *param_1,int param_2,WPARAM param_3)

{
  HCURSOR pHVar1;
  
  if (param_2 != 0) {
    pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar1 = SetCursor(pHVar1);
    SendMessageW((HWND)*param_1,0x1030,param_3,param_2);
    SetCursor(pHVar1);
  }
  return;
}



/* 405a4b00 FUN_405a4b00 */

/* Boundary evidence: original MIPS .pdata 405a4b00..405a4b5f. Semantic name remains unreviewed. */

void FUN_405a4b00(undefined4 *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = GetWindowLongW((HWND)*param_1,-0x10);
  if (param_2 == 0) {
    uVar1 = uVar1 & 0xfffffeff;
  }
  else {
    uVar1 = uVar1 | 0x100;
  }
  SetWindowLongW((HWND)*param_1,-0x10,uVar1);
  return;
}



/* 405a4b60 FUN_405a4b60 */

/* Boundary evidence: original MIPS .pdata 405a4b60..405a4c3f. Semantic name remains unreviewed. */

undefined4 FUN_405a4b60(undefined4 *param_1,char *param_2,ushort *param_3)

{
  LRESULT LVar1;
  undefined4 uVar2;
  undefined4 local_48;
  int local_44 [7];
  HLOCAL local_28;
  
  if ((param_2 == (char *)0x0) || (param_3 == (ushort *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    memset(local_44,0,0x28);
    local_48 = 4;
    local_44[0] = FUN_405a3ce0(param_1,param_2);
    if ((local_44[0] != -1) &&
       (LVar1 = SendMessageW((HWND)*param_1,0x104b,0,(LPARAM)&local_48), LVar1 != 0)) {
      FUN_40580ef4(local_28);
      local_28 = FUN_405813a0(param_3,1);
      LVar1 = SendMessageW((HWND)*param_1,0x104c,0,(LPARAM)&local_48);
      if (LVar1 != 0) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



/* 405a4c40 FUN_405a4c40 */

bool FUN_405a4c40(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  param_1[(iVar1 % 3 + 1) * 2] = *param_2;
  (param_1 + (iVar1 % 3 + 1) * 2)[1] = param_2[1];
  param_1[*param_1 % 3 + 8] = param_3;
  iVar1 = *param_1;
  *param_1 = iVar1 + 1;
  return 2 < iVar1 + 1;
}



/* 405a4cac FUN_405a4cac */

uint FUN_405a4cac(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = 0;
  uVar2 = 1;
  iVar3 = *param_1 % 3;
  do {
    iVar6 = (iVar3 + 1) % 3;
    uVar4 = param_1[iVar3 * 2 + 3] - param_1[iVar6 * 2 + 3] >> 0x1f;
    uVar5 = param_1[iVar3 * 2 + 2] - param_1[iVar6 * 2 + 2] >> 0x1f;
    iVar1 = ((param_1[iVar3 * 2 + 3] - param_1[iVar6 * 2 + 3] ^ uVar4) - uVar4) +
            ((param_1[iVar3 * 2 + 2] - param_1[iVar6 * 2 + 2] ^ uVar5) - uVar5) + iVar1;
    uVar4 = param_1[iVar3 + 8] - param_1[iVar6 + 8] >> 0x1f;
    uVar2 = ((param_1[iVar3 + 8] - param_1[iVar6 + 8] ^ uVar4) - uVar4) + uVar2;
    iVar3 = iVar6;
  } while (iVar6 != *param_1 % 3);
  if (uVar2 == 0) {
    trap(0x1c00);
  }
  return (uint)(iVar1 * 0x400) / uVar2;
}



/* 405a4d74 FUN_405a4d74 */

/* Boundary evidence: original MIPS .pdata 405a4d74..405a4e23. Semantic name remains unreviewed. */

bool FUN_405a4d74(HWND param_1,int param_2)

{
  bool bVar1;
  int nBar;
  tagSCROLLINFO local_30;
  
  if ((param_2 == 0) || (nBar = 0, param_2 == 1)) {
    nBar = 1;
  }
  local_30.cbSize = 0x1c;
  local_30.fMask = 0x17;
  GetScrollInfo(param_1,nBar,&local_30);
  if ((param_2 == 1) || (param_2 == 3)) {
    if (local_30.nPage != 0) {
      local_30.nMax = (local_30.nMax - local_30.nPage) + 1;
    }
    bVar1 = local_30.nPos < local_30.nMax;
  }
  else {
    bVar1 = local_30.nMin < local_30.nPos;
  }
  return bVar1;
}



/* 405a4e24 FUN_405a4e24 */

/* Boundary evidence: original MIPS .pdata 405a4e24..405a507f. Semantic name remains unreviewed. */

void FUN_405a4e24(HWND param_1,POINT *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  POINT pt;
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  BOOL BVar5;
  tagRECT local_68;
  tagRECT local_58;
  tagSCROLLINFO local_48;
  
  GetClientRect(param_1,&local_68);
  uVar2 = GetWindowLongW(param_1,-0x10);
  if ((uVar2 & 0x100000) != 0) {
    iVar3 = GetSystemMetrics(3);
    local_68.bottom = local_68.bottom - iVar3;
  }
  if ((uVar2 & 0x200000) != 0) {
    iVar3 = GetSystemMetrics(2);
    local_68.right = local_68.right - iVar3;
  }
  local_58.left = local_68.left;
  local_58.top = local_68.top;
  local_58.bottom = local_68.bottom;
  local_58.right = local_68.right;
  iVar3 = GetSystemMetrics(0x32);
  iVar4 = GetSystemMetrics(0x31);
  InflateRect(&local_58,iVar4,iVar3);
  iVar3 = GetSystemMetrics(0xc);
  iVar4 = GetSystemMetrics(0xb);
  InflateRect(&local_68,-iVar4,-iVar3);
  pt = *param_2;
  BVar5 = PtInRect(&local_68,*param_2);
  if (BVar5 != 0) {
    return;
  }
  BVar5 = PtInRect(&local_58,pt);
  if (BVar5 == 0) {
    return;
  }
  if ((uVar2 & 0x100000) != 0) {
    if (param_2->x < local_68.left) {
      bVar1 = FUN_405a4d74(param_1,2);
    }
    else {
      if (param_2->x <= local_68.right) goto LAB_405a4fb8;
      bVar1 = FUN_405a4d74(param_1,3);
      param_5 = param_6;
    }
    *(bool *)param_5 = bVar1;
  }
LAB_405a4fb8:
  if ((uVar2 & 0x200000) != 0) {
    if (param_2->y < local_68.top) {
      bVar1 = FUN_405a4d74(param_1,0);
      *(bool *)param_3 = bVar1;
    }
    else if (local_68.bottom < param_2->y) {
      local_48.cbSize = 0x1c;
      local_48.fMask = 0x17;
      GetScrollInfo(param_1,1,&local_48);
      if (local_48.nPage != 0) {
        local_48.nMax = (local_48.nMax - local_48.nPage) + 1;
      }
      *(bool *)param_4 = local_48.nPos < local_48.nMax;
    }
  }
  return;
}



/* 405a5080 FUN_405a5080 */

/* Boundary evidence: original MIPS .pdata 405a5080..405a52a3. Semantic name remains unreviewed. */

uint FUN_405a5080(int *param_1,HWND param_2,POINT *param_3)

{
  bool bVar1;
  DWORD DVar2;
  undefined3 extraout_var;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  uint local_34;
  uint local_30;
  
  DVar2 = GetTickCount();
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  uVar4 = 0;
  local_38 = 0;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  bVar1 = FUN_405a4c40(param_1,&param_3->x,DVar2);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_405a4e24(param_2,param_3,&local_38,&local_37,&local_36,&local_35);
    uVar5 = (uint)local_38;
    uVar6 = (uint)local_37;
    uVar7 = (uint)local_36;
  }
  else {
    uVar3 = FUN_405a4cac(param_1);
    if ((0x14 < (int)uVar3) || (DVar2 - param_1[1] < 0xfa)) goto LAB_405a5268;
    FUN_405a4e24(param_2,param_3,&local_38,&local_37,&local_36,&local_35);
    local_30 = (uint)local_35;
    uVar6 = (uint)local_37;
    uVar5 = (uint)local_38;
    uVar7 = (uint)local_36;
    if (((local_38 == 0 && local_37 == 0) && local_36 == 0) && local_35 == 0) goto LAB_405a5264;
    local_34 = uVar6;
    ImageList_DragShowNolock(0);
    uVar4 = 1;
    if (uVar5 == 0) {
      if (local_34 != 0) {
        uVar3 = 1;
        goto LAB_405a51cc;
      }
    }
    else {
      uVar3 = 0;
LAB_405a51cc:
      SendMessageW(param_2,0x115,uVar3 | 0x10000,0);
    }
    if (uVar7 == 0) {
      if (local_30 != 0) goto LAB_405a5204;
    }
    else {
      uVar4 = 0;
LAB_405a5204:
      SendMessageW(param_2,0x114,uVar4 | 0x10000,0);
    }
    ImageList_DragShowNolock(1);
    param_1[1] = DVar2;
  }
LAB_405a5264:
  uVar4 = (uint)local_35;
LAB_405a5268:
  return uVar4 | uVar7 | uVar6 | uVar5;
}



/* 405a52a4 FUN_405a52a4 */

/* Boundary evidence: original MIPS .pdata 405a52a4..405a52eb. Semantic name remains unreviewed. */

void FUN_405a52a4(int *param_1)

{
  if ((HLOCAL)param_1[3] != (HLOCAL)0x0) {
    FUN_40580ef4((HLOCAL)param_1[3]);
  }
  if (*param_1 != 0) {
    FUN_405a3a5c(param_1);
  }
  return;
}



/* 405a52ec FUN_405a52ec */

/* Boundary evidence: original MIPS .pdata 405a52ec..405a5317. Semantic name remains unreviewed. */

void FUN_405a52ec(int param_1,int param_2,int param_3)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  ImageList_DragEnter((HWND)0x0,param_2,param_3);
  return;
}



/* 405a5318 FUN_405a5318 */

/* Boundary evidence: original MIPS .pdata 405a5318..405a5533. Semantic name remains unreviewed. */

undefined4 FUN_405a5318(int *param_1,HWND param_2,uint param_3)

{
  HWND pHVar1;
  int iVar2;
  uint uVar3;
  DWORD dwStyle;
  DWORD dwExStyle;
  undefined4 uVar4;
  INITCOMMONCONTROLSEX local_2e0;
  undefined4 local_2d8;
  undefined1 auStack_2d4 [688];
  uint local_24;
  
  local_24 = DAT_405a9a3c;
  uVar4 = 1;
  local_2e0.dwSize = 8;
  local_2e0.dwICC = 1;
  InitCommonControlsEx(&local_2e0);
  if (*param_1 != 0) {
    FUN_405a3a5c(param_1);
  }
  uVar3 = 0x50010240;
  if ((param_3 & 1) != 0) {
    uVar3 = 0x50010340;
  }
  if ((param_3 & 0x40) != 0) {
    uVar3 = uVar3 | 4;
  }
  dwExStyle = 0;
  if ((param_3 & 0x400) == 0) {
    dwStyle = uVar3 | 0x300000;
  }
  else {
    dwStyle = uVar3 | 0x2000;
  }
  if ((param_3 & 0x800) != 0) {
    dwStyle = dwStyle | 0x800;
  }
  if ((param_3 & 0x2000) != 0) {
    dwStyle = dwStyle | 8;
  }
  uVar3 = GetWindowLongW(param_2,-0x14);
  if ((uVar3 & 0x400000) != 0) {
    dwExStyle = 0x2000;
  }
  pHVar1 = CreateWindowExW(dwExStyle,L"SysListView32",(LPCWSTR)0x0,dwStyle,0,0,0,0,param_2,
                           (HMENU)0x0,DAT_405aa0c0,(LPVOID)0x0);
  *param_1 = (int)pHVar1;
  if (pHVar1 != (HWND)0x0) {
    local_2d8 = 0;
    memset(auStack_2d4,0,0x2b0);
    iVar2 = SHGetFileInfo(L"",0,&local_2d8,0x2b4,0x4010);
    if (iVar2 != 0) {
      SendMessageW((HWND)*param_1,0x1003,0,iVar2);
    }
    iVar2 = SHGetFileInfo(L"",0,&local_2d8,0x2b4,0x4011);
    if (iVar2 != 0) {
      SendMessageW((HWND)*param_1,0x1003,1,iVar2);
    }
    if (*param_1 != 0) goto LAB_405a5504;
  }
  uVar4 = 0;
LAB_405a5504:
  FUN_405a7174(local_24);
  return uVar4;
}



/* 405a5534 FUN_405a5534 */

/* Boundary evidence: original MIPS .pdata 405a5534..405a56eb. Semantic name remains unreviewed. */

undefined4 FUN_405a5534(int *param_1,int param_2,int param_3,uint *param_4)

{
  uint uVar1;
  WPARAM WVar2;
  LRESULT LVar3;
  WPARAM WVar4;
  int iVar5;
  undefined4 uVar6;
  POINT local_res4;
  tagPOINT local_68 [3];
  undefined1 auStack_50 [12];
  undefined4 local_44;
  undefined4 local_40;
  
  local_68[0].x = 0;
  local_res4.x = param_2;
  local_res4.y = param_3;
  memset(&local_68[0].y,0,0x10);
  uVar6 = 0;
  uVar1 = FUN_405a5080(param_1 + 4,(HWND)*param_1,&local_res4);
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar1;
  }
  local_68[0].x = param_2;
  local_68[0].y = param_3;
  ScreenToClient((HWND)*param_1,local_68);
  WVar2 = SendMessageW((HWND)*param_1,0x1012,0,(LPARAM)local_68);
  ImageList_DragMove(param_2,param_3);
  WVar4 = param_1[2];
  if (WVar4 != WVar2) {
    if ((WVar4 != 0xffffffff) && (LVar3 = SendMessageW((HWND)*param_1,0x102c,WVar4,8), LVar3 == 8))
    {
      ImageList_DragLeave((HWND)0x0);
      local_40 = 8;
      local_44 = 0;
      SendMessageW((HWND)*param_1,0x102b,param_1[2],(LPARAM)auStack_50);
      UpdateWindow((HWND)*param_1);
      ImageList_DragEnter((HWND)0x0,param_2,param_3);
    }
    param_1[2] = WVar2;
    if ((DAT_405aa32c != 0) && (*param_1 == *(int *)(DAT_405aa32c + 4))) {
      iVar5 = 0;
      WVar4 = **(WPARAM **)(DAT_405aa32c + 0x10);
      while (WVar4 != 0xffffffff) {
        if (WVar2 == WVar4) {
          param_1[2] = -1;
          break;
        }
        iVar5 = iVar5 + 1;
        WVar4 = (*(WPARAM **)(DAT_405aa32c + 0x10))[iVar5];
      }
    }
    uVar6 = 1;
  }
  return uVar6;
}



/* 405a56ec FUN_405a56ec */

/* Boundary evidence: original MIPS .pdata 405a56ec..405a58a7. Semantic name remains unreviewed. */

int FUN_405a56ec(int *param_1,int *param_2)

{
  HCURSOR pHVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  ushort *local_40;
  int local_3c;
  tagMSG local_38;
  
  if (param_2 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    local_3c = 0;
    local_40 = (ushort *)0x0;
    local_38.hwnd = (HWND)0x0;
    iVar4 = 1;
    memset(&local_38.message,0,0x18);
    pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar1 = SetCursor(pHVar1);
    iVar2 = (**(code **)(*param_2 + 0xc))(param_2,1,&local_40,&local_3c);
    if (iVar2 == 0) {
      do {
        if (local_3c == 0) break;
        iVar4 = FUN_405a45f0(param_1,local_40);
        FUN_40580ef4(local_40);
        BVar3 = PeekMessageW(&local_38,(HWND)0x0,0x10,0x10,0);
        if (BVar3 != 0) {
          iVar4 = 0;
        }
        if (iVar4 == 0) goto LAB_405a5868;
        BVar3 = PeekMessageW(&local_38,(HWND)0x0,0xf,0xf,1);
        if (BVar3 == 0) {
          BVar3 = PeekMessageW(&local_38,(HWND)0x0,5,5,1);
          if (BVar3 != 0) goto LAB_405a582c;
          BVar3 = PeekMessageW(&local_38,(HWND)0x0,3,3,1);
          if (BVar3 != 0) goto LAB_405a582c;
        }
        else {
LAB_405a582c:
          TranslateMessage(&local_38);
          DispatchMessageW(&local_38);
        }
        iVar2 = (**(code **)(*param_2 + 0xc))(param_2,1,&local_40,&local_3c);
      } while (iVar2 == 0);
      if (iVar4 == 0) {
LAB_405a5868:
        SendMessageW((HWND)*param_1,0x1009,0,0);
      }
    }
    SetCursor(pHVar1);
  }
  return iVar4;
}



/* 405a58a8 FUN_405a58a8 */

/* Boundary evidence: original MIPS .pdata 405a58a8..405a590f. Semantic name remains unreviewed. */

HWND FUN_405a58a8(int param_1)

{
  BOOL BVar1;
  HWND hWnd;
  
  hWnd = *(HWND *)(param_1 + 8);
  if (((hWnd == (HWND)0x0) || (BVar1 = IsWindow(hWnd), BVar1 == 0)) &&
     (hWnd = FindWindowW(L"HHTaskBar",(LPCWSTR)0x0), hWnd != (HWND)0x0)) {
    *(HWND *)(param_1 + 8) = hWnd;
  }
  return hWnd;
}



/* 405a5910 FUN_405a5910 */

/* Boundary evidence: original MIPS .pdata 405a5910..405a5a1f. Semantic name remains unreviewed. */

undefined4 FUN_405a5910(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004002;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
    iVar2 = *param_2;
    if (((((((iVar2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
          (param_2[3] == 0x46000000)) ||
         (((iVar2 == 0x56fdf342 && (param_2[1] == 0x11d0fd6d)) &&
          ((param_2[2] == 0x60008a95 && (param_2[3] == -0x6f5f3669)))))) ||
        (((iVar2 == 0x602d4995 && (param_2[1] == 0x429bb13a)) &&
         ((param_2[2] == 0x35196ea6 && (param_2[3] == 0x17434fe4)))))) &&
       (*param_3 = (int)param_1, param_1 != (int *)0x0)) {
      (**(code **)(*param_1 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 405a5a20 FUN_405a5a20 */

/* Boundary evidence: original MIPS .pdata 405a5a20..405a5a53. Semantic name remains unreviewed. */

undefined4 FUN_405a5a20(int param_1)

{
  HWND pHVar1;
  undefined4 uVar2;
  
  pHVar1 = FUN_405a58a8(param_1);
  if (pHVar1 == (HWND)0x0) {
    uVar2 = 0x80004001;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 405a5a54 FUN_405a5a54 */

/* Boundary evidence: original MIPS .pdata 405a5a54..405a5ae7. Semantic name remains unreviewed. */

undefined4 FUN_405a5a54(int param_1,HWND param_2)

{
  HWND hWnd;
  BOOL BVar1;
  LRESULT LVar2;
  undefined4 uVar3;
  
  hWnd = FUN_405a58a8(param_1);
  if ((param_2 == (HWND)0x0) || (BVar1 = IsWindow(param_2), BVar1 == 0)) {
    uVar3 = 0x80070057;
  }
  else if ((hWnd == (HWND)0x0) ||
          (LVar2 = SendMessageW(hWnd,*(UINT *)(param_1 + 0xc),1,(LPARAM)param_2), LVar2 == 0)) {
    uVar3 = 0x80004005;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 405a5ae8 FUN_405a5ae8 */

/* Boundary evidence: original MIPS .pdata 405a5ae8..405a5b7b. Semantic name remains unreviewed. */

undefined4 FUN_405a5ae8(int param_1,HWND param_2)

{
  HWND hWnd;
  BOOL BVar1;
  LRESULT LVar2;
  undefined4 uVar3;
  
  hWnd = FUN_405a58a8(param_1);
  if ((param_2 == (HWND)0x0) || (BVar1 = IsWindow(param_2), BVar1 == 0)) {
    uVar3 = 0x80070057;
  }
  else if ((hWnd == (HWND)0x0) ||
          (LVar2 = SendMessageW(hWnd,*(UINT *)(param_1 + 0xc),2,(LPARAM)param_2), LVar2 == 0)) {
    uVar3 = 0x80004005;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 405a5b7c FUN_405a5b7c */

/* Boundary evidence: original MIPS .pdata 405a5b7c..405a5c23. Semantic name remains unreviewed. */

undefined4 FUN_405a5b7c(int param_1,HWND param_2)

{
  HWND hWnd;
  BOOL BVar1;
  LRESULT LVar2;
  undefined4 uVar3;
  
  hWnd = FUN_405a58a8(param_1);
  if ((param_2 == (HWND)0x0) || (BVar1 = IsWindow(param_2), BVar1 == 0)) {
    uVar3 = 0x80070057;
  }
  else {
    if (hWnd != (HWND)0x0) {
      SendMessageW(hWnd,*(UINT *)(param_1 + 0xc),4,(LPARAM)param_2);
      LVar2 = SendMessageW(hWnd,0x432,0,(LPARAM)param_2);
      if (LVar2 != 0) {
        return 0;
      }
    }
    uVar3 = 0x80004005;
  }
  return uVar3;
}



/* 405a5c24 FUN_405a5c24 */

/* Boundary evidence: original MIPS .pdata 405a5c24..405a5ca7. Semantic name remains unreviewed. */

undefined4 FUN_405a5c24(int param_1,HWND param_2)

{
  HWND hWnd;
  BOOL BVar1;
  LRESULT LVar2;
  undefined4 uVar3;
  
  hWnd = FUN_405a58a8(param_1);
  if ((param_2 == (HWND)0x0) || (BVar1 = IsWindow(param_2), BVar1 == 0)) {
    uVar3 = 0x80070057;
  }
  else if ((hWnd == (HWND)0x0) || (LVar2 = SendMessageW(hWnd,0x432,0,(LPARAM)param_2), LVar2 == 0))
  {
    uVar3 = 0x80004005;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 405a5ca8 FUN_405a5ca8 */

/* Boundary evidence: original MIPS .pdata 405a5ca8..405a5d37. Semantic name remains unreviewed. */

undefined4 FUN_405a5ca8(int param_1,HWND param_2,WPARAM param_3)

{
  HWND hWnd;
  BOOL BVar1;
  LRESULT LVar2;
  undefined4 uVar3;
  
  hWnd = FUN_405a58a8(param_1);
  if ((param_2 == (HWND)0x0) || (BVar1 = IsWindow(param_2), BVar1 == 0)) {
    uVar3 = 0x80070057;
  }
  else if ((hWnd == (HWND)0x0) ||
          (LVar2 = SendMessageW(hWnd,0x43c,param_3,(LPARAM)param_2), LVar2 == 0)) {
    uVar3 = 0x80004005;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 405a5d38 FUN_405a5d38 */

/* Boundary evidence: original MIPS .pdata 405a5d38..405a5d6f. Semantic name remains unreviewed. */

int FUN_405a5d38(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_40572b10;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 405a5d70 FUN_405a5d70 */

/* Boundary evidence: original MIPS .pdata 405a5d70..405a5dbf. Semantic name remains unreviewed. */

undefined4 * FUN_405a5d70(undefined4 *param_1)

{
  UINT UVar1;
  
  *param_1 = &PTR_FUN_40572b10;
  param_1[1] = 0;
  param_1[2] = 0;
  UVar1 = RegisterWindowMessageW(L"SHELLHOOK");
  param_1[3] = UVar1;
  param_1[1] = 1;
  return param_1;
}



/* 405a6ae0 FUN_405a6ae0 */

/* Boundary evidence: original MIPS .pdata 405a6ae0..405a6b0f. Semantic name remains unreviewed. */

undefined4 FUN_405a6ae0(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_405aa330);
  DAT_405aa354 = 1;
  return 1;
}



/* 405a6b10 FUN_405a6b10 */

/* Boundary evidence: original MIPS .pdata 405a6b10..405a6b3f. Semantic name remains unreviewed. */

undefined4 FUN_405a6b10(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_405aa330);
  DAT_405aa354 = 0;
  return 1;
}



/* 405a6b40 FUN_405a6b40 */

/* Boundary evidence: original MIPS .pdata 405a6b40..405a6bf7. Semantic name remains unreviewed. */

undefined4 FUN_405a6b40(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_405aa354 == 0) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405aa330);
    if (DAT_405aa344 == (HMODULE)0x0) {
      DAT_405aa344 = LoadLibraryW(L"aygshell.dll");
      if (DAT_405aa344 != (HMODULE)0x0) {
        DAT_405aa350 = DAT_405aa350 + 1;
        uVar1 = 1;
        DAT_405aa34c = 1;
      }
    }
    else {
      DAT_405aa350 = DAT_405aa350 + 1;
      uVar1 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405aa330);
  }
  return uVar1;
}



/* 405a6bf8 FUN_405a6bf8 */

/* Boundary evidence: original MIPS .pdata 405a6bf8..405a6c9f. Semantic name remains unreviewed. */

undefined4 FUN_405a6bf8(void)

{
  undefined4 uVar1;
  
  if ((DAT_405aa354 == 0) || (DAT_405aa34c == 0)) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405aa330);
    DAT_405aa350 = DAT_405aa350 + -1;
    if (DAT_405aa350 < 1) {
      FreeLibrary(DAT_405aa344);
      DAT_405aa344 = (HMODULE)0x0;
      DAT_405aa348 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405aa330);
    uVar1 = 1;
  }
  return uVar1;
}



/* 405a6ca0 FUN_405a6ca0 */

/* Boundary evidence: original MIPS .pdata 405a6ca0..405a6d63. Semantic name remains unreviewed. */

undefined4 FUN_405a6ca0(undefined4 param_1,undefined4 param_2)

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
  if ((DAT_405aa354 != 0) && (iVar1 = FUN_405a6b40(), iVar1 != 0)) {
    local_20 = 1;
    local_1c = param_1;
    local_18 = param_2;
    pcVar2 = (code *)GetProcAddressW(DAT_405aa344,L"SHInitDialog");
    if (pcVar2 != (code *)0x0) {
      uVar3 = (*pcVar2)(&local_20);
    }
    iVar1 = FUN_405a6bf8();
    if (iVar1 != 0) {
      return uVar3;
    }
  }
  return 0;
}



/* 405a6d64 FUN_405a6d64 */

/* Boundary evidence: original MIPS .pdata 405a6d64..405a6df7. Semantic name remains unreviewed. */

int FUN_405a6d64(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = DAT_405aa348;
  if ((DAT_405aa354 == 0) || (DAT_405aa344 == 0)) {
    iVar3 = 0;
  }
  else if (DAT_405aa348 == 0) {
    pcVar2 = (code *)GetProcAddressW(DAT_405aa344,L"SHInitExtraControls");
    iVar1 = iVar3;
    if (pcVar2 != (code *)0x0) {
      iVar3 = (*pcVar2)();
      iVar1 = iVar3;
    }
  }
  else {
    iVar3 = 1;
  }
  DAT_405aa348 = iVar1;
  return iVar3;
}



/* 405a6df8 FUN_405a6df8 */

/* Boundary evidence: original MIPS .pdata 405a6df8..405a6ebf. Semantic name remains unreviewed. */

undefined4 FUN_405a6df8(HWND param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  tagWNDCLASSW tStack_38;
  
  if ((((DAT_405aa354 == 0) || (DAT_405aa344 == (HINSTANCE)0x0)) ||
      (iVar1 = FUN_405a6d64(), iVar1 == 0)) ||
     (BVar2 = GetClassInfoW(DAT_405aa344,L"SIPPREF",&tStack_38), BVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    CreateWindowExW(0,L"SIPPREF",(LPCWSTR)0x0,0x40000000,-10,-10,5,5,param_1,(HMENU)0x0,DAT_405aa344
                    ,(LPVOID)0x0);
    uVar3 = 1;
  }
  return uVar3;
}



/* 405a6ec0 FUN_405a6ec0 */

/* Boundary evidence: original MIPS .pdata 405a6ec0..405a6ffb. Semantic name remains unreviewed. */

int FUN_405a6ec0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_405aa368 != (code *)0x0) {
      iVar2 = (*DAT_405aa368)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_405a6f70;
    FUN_405a7354();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40586d28(param_1,param_2);
  }
LAB_405a6f70:
  if (((param_2 == 0) && (FUN_405a72dc(), iVar1 != 0)) && (DAT_405aa368 != (code *)0x0)) {
    iVar1 = (*DAT_405aa368)(param_1,0,param_3);
  }
  return iVar1;
}



/* 405a6ffc FUN_405a6ffc */

/* Boundary evidence: original MIPS .pdata 405a6ffc..405a7027. Semantic name remains unreviewed. */

void FUN_405a6ffc(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 405a7028 entry */

/* Boundary evidence: original MIPS .pdata 405a7028..405a707f. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_405a7080();
  }
  FUN_405a6ec0(param_1,param_2,param_3);
  return;
}



/* 405a7080 FUN_405a7080 */

/* Boundary evidence: original MIPS .pdata 405a7080..405a70f3. Semantic name remains unreviewed. */

void FUN_405a7080(void)

{
  uint uVar1;
  
  if ((DAT_405a9a3c == 0) || (DAT_405a9a3c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_405a9a3c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_405a9a3c == 0) {
      DAT_405a9a3c = 0xb064;
    }
  }
  DAT_405a9a40 = ~DAT_405a9a3c;
  return;
}



/* 405a70f4 FUN_405a70f4 */

/* Boundary evidence: original MIPS .pdata 405a70f4..405a7147. Semantic name remains unreviewed. */

void FUN_405a70f4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_405a7174(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 405a7148 FUN_405a7148 */

/* Boundary evidence: original MIPS .pdata 405a7148..405a7173. Semantic name remains unreviewed. */

undefined4 FUN_405a7148(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_405a70f4(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 405a7174 FUN_405a7174 */

/* Boundary evidence: original MIPS .pdata 405a7174..405a71bb. Semantic name remains unreviewed. */

void FUN_405a7174(uint param_1)

{
  if ((param_1 == DAT_405a9a3c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 405a71bc FUN_405a71bc */

/* Boundary evidence: original MIPS .pdata 405a71bc..405a72db. Semantic name remains unreviewed. */

void FUN_405a71bc(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_405aa358 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_405aa360;
    if (DAT_405aa360 != (undefined4 *)0x0) {
      while (DAT_405aa35c = DAT_405aa35c + -1, _Memory <= DAT_405aa35c) {
        if ((code *)*DAT_405aa35c != (code *)0x0) {
          (*(code *)*DAT_405aa35c)();
          _Memory = DAT_405aa360;
        }
      }
      free(_Memory);
      DAT_405aa35c = (undefined4 *)0x0;
      DAT_405aa360 = (undefined4 *)0x0;
    }
    FUN_405a7300((undefined4 *)&DAT_40571010,(undefined4 *)&DAT_40571014);
  }
  FUN_405a7300((undefined4 *)&DAT_40571018,(undefined4 *)&DAT_4057101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_405aa364,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 405a72dc FUN_405a72dc */

/* Boundary evidence: original MIPS .pdata 405a72dc..405a72ff. Semantic name remains unreviewed. */

void FUN_405a72dc(void)

{
  FUN_405a71bc(0,0,1);
  return;
}



/* 405a7300 FUN_405a7300 */

/* Boundary evidence: original MIPS .pdata 405a7300..405a7353. Semantic name remains unreviewed. */

void FUN_405a7300(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 405a7354 FUN_405a7354 */

/* Boundary evidence: original MIPS .pdata 405a7354..405a738f. Semantic name remains unreviewed. */

void FUN_405a7354(void)

{
  FUN_405a7300((undefined4 *)&DAT_40571008,(undefined4 *)&DAT_4057100c);
  FUN_405a7300((undefined4 *)&DAT_40571000,(undefined4 *)&DAT_40571004);
  return;
}


