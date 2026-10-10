/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 404dbe9c FUN_404dbe9c */

/* Boundary evidence: original MIPS .pdata 404dbe9c..404dbfaf. Semantic name remains unreviewed. */

undefined4 FUN_404dbe9c(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    DAT_404f4250 = 1;
    FUN_404dd14c();
    if (DAT_404f4254 != (code *)0x0) {
      (*DAT_404f4254)();
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_404f423c);
    if (DAT_404f415c != -1) {
      TlsCall(1);
    }
    if (DAT_404f4160 != -1) {
      TlsCall(1);
    }
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_404f423c);
    DAT_404f4238 = param_1;
    DAT_404f415c = TlsCall(0,0);
    DAT_404f4160 = TlsCall(0,0);
    DAT_404f4254 = (code *)GetProcAddressW(DAT_404f4238,L"TermPalette");
  }
  return 1;
}



/* 404dbfb0 FUN_404dbfb0 */

/* Boundary evidence: original MIPS .pdata 404dbfb0..404dc073. Semantic name remains unreviewed. */

int FUN_404dbfb0(BYTE *param_1,int param_2)

{
  BYTE *pBVar1;
  BYTE *pBVar2;
  BOOL BVar3;
  int iVar4;
  
  if ((param_1 == (BYTE *)0x0) || (param_2 < 1)) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_2 + -1;
    pBVar2 = param_1 + iVar4;
    do {
      pBVar1 = pBVar2;
      if (pBVar1 <= param_1) break;
      BVar3 = IsDBCSLeadByte(pBVar1[-1]);
      pBVar2 = pBVar1 + -1;
    } while (BVar3 != 0);
    if ((((uint)(param_1 + (iVar4 - (int)pBVar1)) & 1) != 0) && (0 < iVar4)) {
      iVar4 = param_2 + -2;
    }
    param_1[iVar4] = '\0';
  }
  return iVar4;
}



/* 404dc074 IUnknown_AtomicRelease */

/* Boundary evidence: original MIPS .pdata 404dc074..404dc0af. Semantic name remains unreviewed. */

void IUnknown_AtomicRelease(void **ppunk)

{
  int *piVar1;
  
                    /* 0xc074  169  IUnknown_AtomicRelease */
  if ((ppunk != (void **)0x0) && (piVar1 = *ppunk, piVar1 != (int *)0x0)) {
    *ppunk = (void *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



/* 404dc0b0 ConnectToConnectionPoint */

/* Boundary evidence: original MIPS .pdata 404dc0b0..404dc20b. Semantic name remains unreviewed. */

HRESULT ConnectToConnectionPoint
                  (IUnknown *punk,IID *riidEvent,BOOL fConnect,IUnknown *punkTarget,DWORD *pdwCookie
                  ,IConnectionPoint **ppcpOut)

{
  HRESULT HVar1;
  int iVar2;
  IConnectionPoint *local_20;
  int *local_1c;
  
                    /* 0xc0b0  168  ConnectToConnectionPoint */
  if ((punkTarget == (IUnknown *)0x0) || ((fConnect != 0 && (punk == (IUnknown *)0x0)))) {
    return -0x7fffbffb;
  }
  if (ppcpOut != (IConnectionPoint **)0x0) {
    *ppcpOut = (IConnectionPoint *)0x0;
  }
  HVar1 = (*punkTarget->lpVtbl->QueryInterface)(punkTarget,(IID *)&UNK_404dbcac,&local_1c);
  if (HVar1 < 0) {
    return HVar1;
  }
  iVar2 = (**(code **)(*local_1c + 0x10))(local_1c,riidEvent,&local_20);
  if (iVar2 < 0) goto LAB_404dc1c4;
  if (fConnect == 0) {
    iVar2 = (*local_20->lpVtbl->Unadvise)(local_20,*pdwCookie);
LAB_404dc190:
    *pdwCookie = 0;
  }
  else {
    iVar2 = (*local_20->lpVtbl->Advise)(local_20,punk,pdwCookie);
    if (iVar2 < 0) goto LAB_404dc190;
  }
  if ((ppcpOut == (IConnectionPoint **)0x0) || (iVar2 < 0)) {
    (*local_20->lpVtbl->Release)(local_20);
  }
  else {
    *ppcpOut = local_20;
  }
LAB_404dc1c4:
  (**(code **)(*local_1c + 8))();
  return iVar2;
}



/* 404dc20c IUnknown_QueryStatus */

/* Boundary evidence: original MIPS .pdata 404dc20c..404dc2b3. Semantic name remains unreviewed. */

undefined4
IUnknown_QueryStatus
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  int *local_20 [2];
  
                    /* 0xc20c  163  IUnknown_QueryStatus */
  uVar1 = 0x80004005;
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = (**(code **)*param_1)(param_1,&UNK_404dbcbc,local_20);
    if (local_20[0] != (int *)0x0) {
      uVar1 = (**(code **)(*local_20[0] + 0xc))(local_20[0],param_2,param_3,param_4,param_5);
      (**(code **)(*local_20[0] + 8))();
    }
  }
  return uVar1;
}



/* 404dc2b4 IUnknown_Exec */

/* Boundary evidence: original MIPS .pdata 404dc2b4..404dc367. Semantic name remains unreviewed. */

int IUnknown_Exec(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int *local_20 [2];
  
                    /* 0xc2b4  164  IUnknown_Exec */
  iVar1 = -0x7fffbffb;
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbcbc,local_20), -1 < iVar1)) {
    iVar1 = (**(code **)(*local_20[0] + 0x10))(local_20[0],param_2,param_3,param_4,param_5,param_6);
    (**(code **)(*local_20[0] + 8))();
  }
  return iVar1;
}



/* 404dc368 FUN_404dc368 */

/* Boundary evidence: original MIPS .pdata 404dc368..404dc3db. Semantic name remains unreviewed. */

void FUN_404dc368(HWND param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint dwNewLong;
  
  uVar1 = GetWindowLongW(param_1,param_2);
  dwNewLong = ~param_3 & uVar1 | param_3 & param_4;
  if (uVar1 != dwNewLong) {
    SetWindowLongW(param_1,param_2,dwNewLong);
  }
  return;
}



/* 404dc3dc SHSetParentHwnd */

/* Boundary evidence: original MIPS .pdata 404dc3dc..404dc4e7. Semantic name remains unreviewed. */

void SHSetParentHwnd(HWND param_1,HWND param_2)

{
  HWND pHVar1;
  uint uVar2;
  
                    /* 0xc3dc  167  SHSetParentHwnd */
  pHVar1 = GetParent(param_1);
  if (param_2 != pHVar1) {
    if (param_2 != (HWND)0x0) {
      FUN_404dc368(param_1,-0x10,0xc0000000,0x40000000);
    }
    SetParent(param_1,param_2);
    if (param_2 == (HWND)0x0) {
      FUN_404dc368(param_1,-0x10,0xc0000000,0x80000000);
    }
    if (DAT_404f4230 != 0) {
      uVar2 = SendMessageW(param_2,0x129,0,0);
      if ((uVar2 & 3) != 0) {
        SendMessageW(param_1,0x128,(uVar2 & 3) << 0x10 | 1,0);
      }
      if ((~uVar2 & 3) != 0) {
        SendMessageW(param_1,0x128,(~uVar2 & 3) << 0x10 | 2,0);
      }
    }
  }
  return;
}



/* 404dc4e8 SHIsSameObject */

/* Boundary evidence: original MIPS .pdata 404dc4e8..404dc5ab. Semantic name remains unreviewed. */

undefined4 SHIsSameObject(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int *local_18;
  int *local_14;
  
                    /* 0xc4e8  171  SHIsSameObject */
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    if (param_1 == param_2) {
      return 1;
    }
    iVar1 = (**(code **)*param_1)(param_1,&DAT_404dbccc,&local_14);
    if (-1 < iVar1) {
      (**(code **)(*local_14 + 8))();
      iVar1 = (**(code **)*param_2)(param_2,&DAT_404dbccc,&local_18);
      if ((-1 < iVar1) && ((**(code **)(*local_18 + 8))(), local_14 == local_18)) {
        return 1;
      }
    }
  }
  return 0;
}



/* 404dc5ac IUnknown_GetWindow */

/* Boundary evidence: original MIPS .pdata 404dc5ac..404dc6c3. Semantic name remains unreviewed. */

HRESULT IUnknown_GetWindow(IUnknown *punk,HWND *phwnd)

{
  HRESULT HVar1;
  int *local_20;
  int *local_1c;
  int *local_18 [2];
  
                    /* 0xc5ac  172  IUnknown_GetWindow */
  HVar1 = -0x7fffbffb;
  *phwnd = (HWND)0x0;
  if (punk != (IUnknown *)0x0) {
    HVar1 = (*punk->lpVtbl->QueryInterface)(punk,(IID *)&UNK_404dbcfc,&local_20);
    if (HVar1 < 0) {
      HVar1 = (*punk->lpVtbl->QueryInterface)(punk,(IID *)&UNK_404dbcec,&local_1c);
      if (HVar1 < 0) {
        HVar1 = (*punk->lpVtbl->QueryInterface)(punk,(IID *)&UNK_404dbcdc,local_18);
        if (HVar1 < 0) {
          return HVar1;
        }
        HVar1 = (**(code **)(*local_18[0] + 0xc))(local_18[0],phwnd);
        local_20 = local_18[0];
      }
      else {
        HVar1 = (**(code **)(*local_1c + 0xc))(local_1c,phwnd);
        local_20 = local_1c;
      }
    }
    else {
      HVar1 = (**(code **)(*local_20 + 0xc))(local_20,phwnd);
    }
    (**(code **)(*local_20 + 8))();
  }
  return HVar1;
}



/* 404dc6c4 IUnknown_EnableModless */

/* Boundary evidence: original MIPS .pdata 404dc6c4..404dc857. Semantic name remains unreviewed. */

int IUnknown_EnableModless(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18 [2];
  
                    /* 0xc6c4  355  IUnknown_EnableModless */
  iVar1 = -0x7fffbffb;
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbd3c,&local_28);
    if (iVar1 < 0) {
      iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbcec,&local_24);
      if (iVar1 < 0) {
        iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbd2c,&local_20);
        if (iVar1 < 0) {
          iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbd1c,&local_1c);
          if (iVar1 < 0) {
            iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbd0c,local_18);
            if (iVar1 < 0) {
              return iVar1;
            }
            iVar1 = (**(code **)(*local_18[0] + 0x20))(local_18[0],param_2);
            local_28 = local_18[0];
          }
          else {
            iVar1 = (**(code **)(*local_1c + 0x24))(local_1c,param_2);
            local_28 = local_1c;
          }
        }
        else {
          iVar1 = (**(code **)(*local_20 + 0x34))(local_20,param_2);
          local_28 = local_20;
        }
      }
      else {
        iVar1 = (**(code **)(*local_24 + 0x10))(local_24,param_2);
        local_28 = local_24;
      }
    }
    else {
      iVar1 = (**(code **)(*local_28 + 0x24))(local_28,param_2);
    }
    (**(code **)(*local_28 + 8))();
  }
  return iVar1;
}



/* 404dc858 IUnknown_SetOwner */

undefined4 IUnknown_SetOwner(void)

{
                    /* 0xc858  173  IUnknown_SetOwner */
  return 0x80004005;
}



/* 404dc864 IUnknown_SetSite */

/* Boundary evidence: original MIPS .pdata 404dc864..404dc937. Semantic name remains unreviewed. */

HRESULT IUnknown_SetSite(IUnknown *punk,IUnknown *punkSite)

{
  HRESULT HVar1;
  int *local_18;
  int *local_14;
  
                    /* 0xc864  174  IUnknown_SetSite */
  HVar1 = -0x7fffbffb;
  if (punk != (IUnknown *)0x0) {
    HVar1 = (*punk->lpVtbl->QueryInterface)(punk,(IID *)&UNK_404dbd5c,&local_18);
    if (HVar1 < 0) {
      HVar1 = (*punk->lpVtbl->QueryInterface)(punk,(IID *)&DAT_404dbd4c,&local_14);
      if (HVar1 < 0) {
        return HVar1;
      }
      HVar1 = (**(code **)(*local_14 + 0xc))(local_14,punkSite);
      local_18 = local_14;
    }
    else {
      HVar1 = (**(code **)(*local_18 + 0xc))(local_18,punkSite);
    }
    (**(code **)(*local_18 + 8))();
  }
  return HVar1;
}



/* 404dc938 IUnknown_GetClassID */

/* Boundary evidence: original MIPS .pdata 404dc938..404dc9bb. Semantic name remains unreviewed. */

int IUnknown_GetClassID(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_18 [2];
  
                    /* 0xc938  175  IUnknown_GetClassID */
  iVar1 = -0x7fffbffb;
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbd6c,local_18), -1 < iVar1)) {
    iVar1 = (**(code **)(*local_18[0] + 0xc))(local_18[0],param_2);
    (**(code **)(*local_18[0] + 8))();
  }
  return iVar1;
}



/* 404dc9bc IUnknown_QueryService */

/* Boundary evidence: original MIPS .pdata 404dc9bc..404dca63. Semantic name remains unreviewed. */

HRESULT IUnknown_QueryService(IUnknown *punk,GUID *guidService,IID *riid,void **ppvOut)

{
  HRESULT HVar1;
  int *local_20 [2];
  
                    /* 0xc9bc  176  IUnknown_QueryService */
  *ppvOut = (void *)0x0;
  HVar1 = -0x7fffbffb;
  if ((punk != (IUnknown *)0x0) &&
     (HVar1 = (*punk->lpVtbl->QueryInterface)(punk,(IID *)&UNK_404dbd7c,local_20), -1 < HVar1)) {
    HVar1 = (**(code **)(*local_20[0] + 0xc))(local_20[0],guidService,riid,ppvOut);
    (**(code **)(*local_20[0] + 8))();
  }
  return HVar1;
}



/* 404dca64 SHPropagateMessage */

void SHPropagateMessage(void)

{
                    /* 0xca64  178  SHPropagateMessage
                       0xca64  220  SHSetDefaultDialogFont
                       0xca64  221  SHRemoveDefaultDialogFont
                       0xca64  383  ZoneConfigureW
                       0xca64  384  SHRestrictedMessageBox */
  return;
}



/* 404dca6c SHDefWindowProc */

/* Boundary evidence: original MIPS .pdata 404dca6c..404dca87. Semantic name remains unreviewed. */

void SHDefWindowProc(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
                    /* 0xca6c  240  SHDefWindowProc */
  DefWindowProcW(param_1,param_2,param_3,param_4);
  return;
}



/* 404dca88 IStream_Read */

/* Boundary evidence: original MIPS .pdata 404dca88..404dcad7. Semantic name remains unreviewed. */

HRESULT IStream_Read(IStream *pstm,void *pv,ULONG cb)

{
  HRESULT HVar1;
  ULONG local_10 [2];
  
                    /* 0xca88  184  IStream_Read */
  HVar1 = (*pstm->lpVtbl->Read)(pstm,pv,cb,local_10);
  if ((-1 < HVar1) && (local_10[0] != cb)) {
    HVar1 = -0x7fffbffb;
  }
  return HVar1;
}



/* 404dcad8 IStream_Write */

/* Boundary evidence: original MIPS .pdata 404dcad8..404dcb27. Semantic name remains unreviewed. */

HRESULT IStream_Write(IStream *pstm,void *pv,ULONG cb)

{
  HRESULT HVar1;
  ULONG local_10 [2];
  
                    /* 0xcad8  212  IStream_Write */
  HVar1 = (*pstm->lpVtbl->Write)(pstm,pv,cb,local_10);
  if ((-1 < HVar1) && (cb != local_10[0])) {
    HVar1 = -0x7fffbffb;
  }
  return HVar1;
}



/* 404dcb28 SHRegisterClassW */

/* Boundary evidence: original MIPS .pdata 404dcb28..404dcb73. Semantic name remains unreviewed. */

ATOM SHRegisterClassW(WNDCLASSW *param_1)

{
  ATOM AVar1;
  BOOL BVar2;
  tagWNDCLASSW tStack_30;
  
                    /* 0xcb28  237  SHRegisterClassW */
  BVar2 = GetClassInfoW(param_1->hInstance,param_1->lpszClassName,&tStack_30);
  if (BVar2 == 0) {
    AVar1 = RegisterClassW(param_1);
  }
  else {
    AVar1 = 1;
  }
  return AVar1;
}



/* 404dcb74 SHUnregisterClassesW */

/* Boundary evidence: original MIPS .pdata 404dcb74..404dcbe7. Semantic name remains unreviewed. */

void SHUnregisterClassesW(HINSTANCE param_1,undefined4 *param_2,int param_3)

{
  BOOL BVar1;
  tagWNDCLASSW tStack_38;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    BVar1 = GetClassInfoW(param_1,(LPCWSTR)*param_2,&tStack_38);
    if (BVar1 != 0) {
      UnregisterClassW((LPCWSTR)*param_2,param_1);
    }
    param_2 = param_2 + 1;
  }
  return;
}



/* 404dcbe8 SHSimulateDrop */

/* Boundary evidence: original MIPS .pdata 404dcbe8..404dccdf. Semantic name remains unreviewed. */

undefined4
SHSimulateDrop(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  
                    /* 0xcbe8  186  SHSimulateDrop */
  if (param_4 == (undefined4 *)0x0) {
    param_4 = &local_28;
    local_28 = 0;
    local_24 = 0;
  }
  if (param_5 == (int *)0x0) {
    local_30[0] = 7;
    param_5 = local_30;
  }
  iVar2 = *param_5;
  (**(code **)(*param_1 + 0xc))(param_1,param_2,param_3,*param_4,param_4[1],param_5);
  if (*param_5 == 0) {
    (**(code **)(*param_1 + 0x14))(param_1);
    uVar1 = 1;
  }
  else {
    *param_5 = iVar2;
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,param_2,param_3,*param_4,param_4[1],param_5);
  }
  return uVar1;
}



/* 404dcce0 IUnknown_TranslateAcceleratorOCS */

/* Boundary evidence: original MIPS .pdata 404dcce0..404dcd73. Semantic name remains unreviewed. */

int IUnknown_TranslateAcceleratorOCS(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *local_18 [2];
  
                    /* 0xcce0  188  IUnknown_TranslateAcceleratorOCS */
  iVar1 = -0x7fffbffb;
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbdac,local_18), -1 < iVar1)) {
    iVar1 = (**(code **)(*local_18[0] + 0x1c))(local_18[0],param_2,param_3);
    (**(code **)(*local_18[0] + 8))();
  }
  return iVar1;
}



/* 404dcd74 IUnknown_OnFocusOCS */

/* Boundary evidence: original MIPS .pdata 404dcd74..404dcdf7. Semantic name remains unreviewed. */

int IUnknown_OnFocusOCS(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_18 [2];
  
                    /* 0xcd74  189  IUnknown_OnFocusOCS */
  iVar1 = -0x7fffbffb;
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbdac,local_18), -1 < iVar1)) {
    iVar1 = (**(code **)(*local_18[0] + 0x20))(local_18[0],param_2);
    (**(code **)(*local_18[0] + 8))();
  }
  return iVar1;
}



/* 404dcdf8 SHSearchMapInt */

undefined4 SHSearchMapInt(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  while( true ) {
                    /* 0xcdf8  198  SHSearchMapInt */
    if (param_3 < 1) {
      return 0xffffffff;
    }
    if (*param_1 == param_4) break;
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return *param_2;
}



/* 404dce30 IUnknown_Set */

/* Boundary evidence: original MIPS .pdata 404dce30..404dce9f. Semantic name remains unreviewed. */

void IUnknown_Set(IUnknown **ppunk,IUnknown *punk)

{
  IUnknown *This;
  
                    /* 0xce30  199  IUnknown_Set */
  This = *ppunk;
  if (This != punk) {
    if (This != (IUnknown *)0x0) {
      *ppunk = (IUnknown *)0x0;
      (*This->lpVtbl->Release)(This);
    }
    if (punk != (IUnknown *)0x0) {
      (*punk->lpVtbl->AddRef)(punk);
      *ppunk = punk;
    }
  }
  return;
}



/* 404dcea0 SHIsChildOrSelf */

/* Boundary evidence: original MIPS .pdata 404dcea0..404dcee7. Semantic name remains unreviewed. */

undefined4 SHIsChildOrSelf(HWND param_1,HWND param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
                    /* 0xcea0  204  SHIsChildOrSelf */
  if (((param_1 == (HWND)0x0) || (param_2 == (HWND)0x0)) ||
     ((param_1 != param_2 && (BVar1 = IsChild(param_1,param_2), BVar1 == 0)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 404dcee8 SHInterlockedCompareExchange */

/* Boundary evidence: original MIPS .pdata 404dcee8..404dcf03. Semantic name remains unreviewed. */

void SHInterlockedCompareExchange(LONG *param_1,LONG param_2,LONG param_3)

{
                    /* 0xcee8  342  SHInterlockedCompareExchange */
  InterlockedCompareExchange(param_1,param_2,param_3);
  return;
}



/* 404dcf04 FUN_404dcf04 */

/* Boundary evidence: original MIPS .pdata 404dcf04..404dcfc7. Semantic name remains unreviewed. */

undefined4 FUN_404dcf04(wchar_t *param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  LSTATUS LVar1;
  undefined4 local_228;
  DWORD local_224;
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_404f4224;
  local_228 = 0;
  if (param_1 == (wchar_t *)0x0) {
    param_1 = L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies";
  }
  PathCombineW(aWStack_220,param_1,param_2);
  local_224 = 4;
  LVar1 = SHGetValueW((HKEY)0x80000002,aWStack_220,param_3,(DWORD *)0x0,&local_228,&local_224);
  if (LVar1 != 0) {
    local_224 = 4;
    SHGetValueW((HKEY)0x80000001,aWStack_220,param_3,(DWORD *)0x0,&local_228,&local_224);
  }
  FUN_404f1430(local_18);
  return local_228;
}



/* 404dcfc8 SHSkipJunction */

/* Boundary evidence: original MIPS .pdata 404dcfc8..404dd0a7. Semantic name remains unreviewed. */

BOOL SHSkipJunction(IBindCtx *pbc,CLSID *pclsid)

{
  HRESULT HVar1;
  int iVar2;
  BOOL BVar3;
  IUnknown *local_28 [2];
  ulong local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  
                    /* 0xcfc8  57  SHSkipJunction */
  local_10 = DAT_404f4224;
  if ((pbc == (IBindCtx *)0x0) ||
     (HVar1 = (*pbc->lpVtbl->GetObjectParam)(pbc,L"Skip Binding CLSID",local_28), HVar1 < 0)) {
    FUN_404f1430(local_10);
    BVar3 = 0;
  }
  else {
    iVar2 = IUnknown_GetClassID(local_28[0],&local_20);
    if ((((iVar2 < 0) || (local_20 != pclsid->Data1)) ||
        (iVar2._0_2_ = pclsid->Data2, iVar2._2_2_ = pclsid->Data3, local_1c != iVar2)) ||
       ((local_18 != *(int *)pclsid->Data4 || (BVar3 = 1, local_14 != *(int *)(pclsid->Data4 + 4))))
       ) {
      BVar3 = 0;
    }
    (*local_28[0]->lpVtbl->Release)(local_28[0]);
    FUN_404f1430(local_10);
  }
  return BVar3;
}



/* 404dd0a8 SHRestrictionLookup */

/* Boundary evidence: original MIPS .pdata 404dd0a8..404dd14b. Semantic name remains unreviewed. */

int SHRestrictionLookup(int param_1,wchar_t *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0xd0a8  266  SHRestrictionLookup */
  iVar1 = param_3[1];
  iVar2 = 0;
  piVar3 = param_3;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 == *piVar3) break;
    iVar2 = iVar2 + 1;
    piVar3 = param_3 + iVar2 * 3;
    iVar1 = piVar3[1];
  }
  piVar3 = (int *)(iVar2 * 4 + param_4);
  iVar1 = *piVar3;
  if (iVar1 != -1) {
    return iVar1;
  }
  iVar2 = FUN_404dcf04(param_2,(LPCWSTR)param_3[iVar2 * 3 + 1],(LPCWSTR)param_3[iVar2 * 3 + 2]);
  *piVar3 = iVar2;
  return iVar2;
}



/* 404dd14c FUN_404dd14c */

/* Boundary evidence: original MIPS .pdata 404dd14c..404dd177. Semantic name remains unreviewed. */

void FUN_404dd14c(void)

{
  if (DAT_404f4270 != (HLOCAL)0x0) {
    LocalFree(DAT_404f4270);
  }
  return;
}



/* 404dd178 FUN_404dd178 */

undefined4 FUN_404dd178(int param_1,undefined1 *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  if (param_3 < 0x27) {
    uVar1 = 0;
  }
  else {
    *param_2 = 0x7b;
    pcVar3 = param_2 + 1;
    uVar5 = 0;
    do {
      uVar2 = (uint)(byte)(&DAT_404d10f0)[uVar5];
      if (uVar2 == 0x2d) {
        *pcVar3 = '-';
        pcVar3 = pcVar3 + 1;
      }
      else {
        pcVar4 = pcVar3 + 1;
        *pcVar3 = "0123456789ABCDEF"[*(byte *)(uVar2 + param_1) >> 4];
        pcVar3 = pcVar3 + 2;
        *pcVar4 = "0123456789ABCDEF"[*(byte *)((uint)(byte)(&DAT_404d10f0)[uVar5] + param_1) & 0xf];
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x14);
    *pcVar3 = '}';
    pcVar3[1] = '\0';
    uVar1 = 0x27;
  }
  return uVar1;
}



/* 404dd230 SHStringFromGUIDW */

undefined4 SHStringFromGUIDW(int param_1,undefined2 *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  wchar_t *pwVar3;
  uint uVar4;
  
                    /* 0xd230  24  SHStringFromGUIDW */
  if (param_3 < 0x27) {
    uVar1 = 0;
  }
  else {
    *param_2 = 0x7b;
    pwVar3 = param_2 + 1;
    uVar4 = 0;
    do {
      uVar2 = (uint)(byte)(&DAT_404d10f0)[uVar4];
      if (uVar2 == 0x2d) {
        *pwVar3 = L'-';
        pwVar3 = pwVar3 + 1;
      }
      else {
        *pwVar3 = L"0123456789ABCDEF"[*(byte *)(uVar2 + param_1) >> 4];
        pwVar3[1] = L"0123456789ABCDEF"
                    [*(byte *)((uint)(byte)(&DAT_404d10f0)[uVar4] + param_1) & 0xf];
        pwVar3 = pwVar3 + 2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x14);
    *pwVar3 = L'}';
    pwVar3[1] = L'\0';
    uVar1 = 0x27;
  }
  return uVar1;
}



/* 404dd2f0 FUN_404dd2f0 */

/* Boundary evidence: original MIPS .pdata 404dd2f0..404dd40f. Semantic name remains unreviewed. */

HMODULE FUN_404dd2f0(int param_1)

{
  HRESULT HVar1;
  int iVar2;
  LSTATUS LVar3;
  HMODULE pHVar4;
  HKEY local_290;
  DWORD local_28c;
  char acStack_288 [6];
  undefined1 auStack_282 [98];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_404f4224;
  pHVar4 = (HMODULE)0x0;
  HVar1 = StringCchCopyA(acStack_288,0x67,"CLSID\\");
  if (((-1 < HVar1) && (iVar2 = FUN_404dd178(param_1,auStack_282,0x61), iVar2 != 0)) &&
     (HVar1 = StringCchCatA(acStack_288,0x67,"\\InProcServer32"), -1 < HVar1)) {
    LVar3 = RegOpenKeyExA((HKEY)0x80000000,acStack_288,0,1,&local_290);
    if (LVar3 == 0) {
      local_28c = 0x208;
      LVar3 = SHQueryValueExW(local_290,(LPCWSTR)0x0,(DWORD *)0x0,(DWORD *)0x0,aWStack_220,
                              &local_28c);
      if (LVar3 == 0) {
        pHVar4 = LoadLibraryExW(aWStack_220,(HANDLE)0x0,0);
      }
      RegCloseKey(local_290);
    }
  }
  FUN_404f1430(local_18);
  return pHVar4;
}



/* 404dd410 FUN_404dd410 */

undefined4 FUN_404dd410(int *param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *param_1;
  iVar3 = 0;
  uVar1 = 1;
  iVar4 = 0;
  if (0 < param_3) {
    do {
      uVar6 = (uint)*(char *)(iVar4 + iVar5);
      if (uVar6 - 0x30 < 10) {
        iVar3 = iVar3 * 0x10 + uVar6 + -0x30;
      }
      else {
        if (5 < (uVar6 | 0x20) - 0x61) {
          return 0;
        }
        iVar3 = iVar3 * 0x10 + (uVar6 | 0x20) + -0x57;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_3);
  }
  if ((param_4 != 0) && (pcVar2 = (char *)(iVar4 + iVar5), iVar4 = iVar4 + 1, *pcVar2 != param_4)) {
    uVar1 = 0;
  }
  *param_2 = iVar3;
  *param_1 = iVar4 + iVar5;
  return uVar1;
}



/* 404dd4c4 GUIDFromStringA */

/* Boundary evidence: original MIPS .pdata 404dd4c4..404dd687. Semantic name remains unreviewed. */

undefined4 GUIDFromStringA(char *param_1,int *param_2)

{
  int iVar1;
  char *local_res0 [4];
  undefined1 local_10 [8];
  
                    /* 0xd4c4  269  GUIDFromStringA */
  local_res0[0] = param_1 + 1;
  if (((*param_1 == '{') && (iVar1 = FUN_404dd410((int *)local_res0,param_2,8,0x2d), iVar1 != 0)) &&
     (iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,4,0x2d), iVar1 != 0)) {
    *(short *)(param_2 + 1) = (short)local_10._0_4_;
    iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,4,0x2d);
    if (iVar1 != 0) {
      *(short *)((int)param_2 + 6) = (short)local_10._0_4_;
      iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,2,0);
      if (iVar1 != 0) {
        *(undefined1 *)(param_2 + 2) = local_10[0];
        iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,2,0x2d);
        if (iVar1 != 0) {
          *(undefined1 *)((int)param_2 + 9) = local_10[0];
          iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,2,0);
          if (iVar1 != 0) {
            *(undefined1 *)((int)param_2 + 10) = local_10[0];
            iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,2,0);
            if (iVar1 != 0) {
              *(undefined1 *)((int)param_2 + 0xb) = local_10[0];
              iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,2,0);
              if (iVar1 != 0) {
                *(undefined1 *)(param_2 + 3) = local_10[0];
                iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,2,0);
                if (iVar1 != 0) {
                  *(undefined1 *)((int)param_2 + 0xd) = local_10[0];
                  iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,2,0);
                  if (iVar1 != 0) {
                    *(undefined1 *)((int)param_2 + 0xe) = local_10[0];
                    iVar1 = FUN_404dd410((int *)local_res0,(int *)local_10,2,0x7d);
                    if (iVar1 != 0) {
                      *(undefined1 *)((int)param_2 + 0xf) = local_10[0];
                      return 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



/* 404dd688 GUIDFromStringW */

/* Boundary evidence: original MIPS .pdata 404dd688..404dd6db. Semantic name remains unreviewed. */

undefined4 GUIDFromStringW(LPCWSTR param_1,int *param_2)

{
  undefined4 uVar1;
  CHAR aCStack_38 [40];
  uint local_10;
  
                    /* 0xd688  270  GUIDFromStringW */
  local_10 = DAT_404f4224;
  SHUnicodeToAnsi(param_1,aCStack_38,0x27);
  uVar1 = GUIDFromStringA(aCStack_38,param_2);
  FUN_404f1430(local_10);
  return uVar1;
}



/* 404dd6dc FUN_404dd6dc */

/* Boundary evidence: original MIPS .pdata 404dd6dc..404dd86f. Semantic name remains unreviewed. */

undefined4 FUN_404dd6dc(LPBYTE param_1,LPDWORD param_2)

{
  LSTATUS LVar1;
  LCID LVar2;
  size_t sVar3;
  LCID *pLVar4;
  undefined4 uVar5;
  int iVar6;
  HKEY local_20;
  DWORD DStack_1c;
  
  if (((param_1 == (LPBYTE)0x0) || (param_2 == (LPDWORD)0x0)) || (*param_2 == 0)) {
    uVar5 = 0x80004005;
  }
  else {
    LVar1 = RegOpenKeyExA((HKEY)0x80000001,"Software\\Microsoft\\Internet Explorer\\International",0
                          ,0xf003f,&local_20);
    uVar5 = 0x80004005;
    if ((LVar1 == 0) && (uVar5 = 0x80004005, local_20 != (HKEY)0x0)) {
      LVar1 = RegQueryValueExA(local_20,"AcceptLanguage",(LPDWORD)0x0,&DStack_1c,param_1,param_2);
      if (LVar1 == 0) {
        uVar5 = 0;
        if (*param_1 == '\0') {
          uVar5 = 1;
        }
      }
      else {
        LVar2 = GetUserDefaultLCID();
        pLVar4 = &DAT_404d11c0;
        iVar6 = 0;
        *param_1 = '\0';
        do {
          if (LVar2 == *pLVar4) {
            strncpy((char *)param_1,*(char **)(&UNK_404d11c4 + iVar6 * 8),*param_2);
            sVar3 = strlen((char *)param_1);
            *param_2 = sVar3;
            break;
          }
          iVar6 = iVar6 + 1;
          pLVar4 = pLVar4 + 2;
        } while (iVar6 < 0x7a);
        uVar5 = 0;
        if (iVar6 == 0x7a) {
          *param_2 = 0;
          uVar5 = 0x80004005;
        }
      }
      RegCloseKey(local_20);
    }
  }
  return uVar5;
}



/* 404dd870 FUN_404dd870 */

/* Boundary evidence: original MIPS .pdata 404dd870..404dd95b. Semantic name remains unreviewed. */

undefined4 FUN_404dd870(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  HMODULE hLibModule;
  code *pcVar2;
  undefined4 uVar3;
  
  uVar3 = 0x80004005;
  bVar1 = false;
  hLibModule = GetModuleHandleW(L"URLMON.DLL");
  if (hLibModule == (HMODULE)0x0) {
    hLibModule = LoadLibraryW(L"URLMON.DLL");
    bVar1 = true;
    if (hLibModule == (HMODULE)0x0) {
      return 0x80004005;
    }
  }
  pcVar2 = (code *)GetProcAddressW(hLibModule,L"RegisterFormatEnumerator");
  if (pcVar2 != (code *)0x0) {
    uVar3 = (*pcVar2)(param_1,param_2,param_3);
  }
  if (bVar1) {
    FreeLibrary(hLibModule);
  }
  return uVar3;
}



/* 404dd95c RegisterDefaultAcceptHeaders */

/* Boundary evidence: original MIPS .pdata 404dd95c..404ddaab. Semantic name remains unreviewed. */

HRESULT RegisterDefaultAcceptHeaders(undefined4 param_1,IUnknown *param_2)

{
  HRESULT HVar1;
  int *local_30;
  int *local_2c;
  int *local_28 [2];
  _union_2683 local_20;
  
                    /* 0xd95c  13  RegisterDefaultAcceptHeaders */
  HVar1 = IUnknown_QueryService(param_2,(GUID *)&DAT_404dbdfc,(IID *)&DAT_404dbdfc,local_28);
  if (-1 < HVar1) {
    local_20.n2.vt = 0;
    memset(&local_20.n2.wReserved1,0,0xe);
    HVar1 = (**(code **)(*local_28[0] + 0x8c))
                      (local_28[0],L"{D0FCA420-D3F5-11CF-B211-00AA004AE837}",&local_20);
    if (-1 < HVar1) {
      if (((local_20.n2.vt != 0) && (local_20.n2.vt == 0xd)) &&
         (HVar1 = (*(code *)**(undefined4 **)local_20._8_4_)(local_20._8_4_,&DAT_404dbdec,&local_2c)
         , -1 < HVar1)) {
        local_30 = (int *)0x0;
        HVar1 = (**(code **)(*local_2c + 0x18))(local_2c,&local_30);
        if (-1 < HVar1) {
          HVar1 = FUN_404dd870(param_1,local_30,0);
          (**(code **)(*local_30 + 8))();
        }
        (**(code **)(*local_2c + 8))();
      }
      VariantClear((VARIANTARG *)&local_20.n2);
    }
    (**(code **)(*local_28[0] + 8))();
  }
  return HVar1;
}



/* 404ddaac GetAcceptLanguagesW */

/* Boundary evidence: original MIPS .pdata 404ddaac..404ddb9f. Semantic name remains unreviewed. */

HRESULT GetAcceptLanguagesW(LPWSTR psz,DWORD *pcch)

{
  LPBYTE lpMultiByteStr;
  DWORD DVar1;
  int iVar2;
  DWORD local_20 [2];
  
                    /* 0xdaac  15  GetAcceptLanguagesW */
  if (((psz == (LPWSTR)0x0) || (pcch == (DWORD *)0x0)) || (local_20[0] = *pcch, local_20[0] == 0)) {
    iVar2 = -0x7fffbffb;
  }
  else {
    lpMultiByteStr = LocalAlloc(0x40,local_20[0]);
    if (lpMultiByteStr == (LPBYTE)0x0) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      iVar2 = FUN_404dd6dc(lpMultiByteStr,local_20);
      if (iVar2 < 0) {
        *pcch = local_20[0];
      }
      else {
        DVar1 = MultiByteToWideChar(0,0,(LPCSTR)lpMultiByteStr,-1,psz,*pcch - 1);
        *pcch = DVar1;
        psz[DVar1] = L'\0';
      }
      LocalFree(lpMultiByteStr);
    }
  }
  return iVar2;
}



/* 404ddba0 SHPackDispParamsV */

/* Boundary evidence: original MIPS .pdata 404ddba0..404ddd4b. Semantic name remains unreviewed. */

undefined4 SHPackDispParamsV(undefined4 *param_1,void *param_2,int param_3,uint *param_4)

{
  undefined2 *puVar1;
  undefined *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  
                    /* 0xdba0  281  SHPackDispParamsV */
  memset(param_2,0,param_3 * 0x10);
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = param_3;
  param_1[3] = 0;
  puVar1 = (undefined2 *)(param_3 * 0x10 + (int)param_2);
  do {
    if (param_3 == 0) {
      return 0;
    }
    puVar5 = puVar1 + -8;
    puVar3 = (uint *)((int)param_4 + 3U & 0xfffffffc);
    uVar4 = *puVar3;
    *puVar5 = (short)uVar4;
    if ((uVar4 & 0x4000) == 0) {
      if (uVar4 != 3) {
        if (uVar4 == 8) {
          param_4 = puVar3 + 2;
          uVar4 = puVar3[1];
          *(uint *)(puVar1 + -4) = uVar4;
          if (uVar4 == 0) {
            puVar2 = &DAT_404d18d8;
            goto LAB_404ddd44;
          }
          goto LAB_404ddcb0;
        }
        if (uVar4 != 9) {
          if (uVar4 == 0xb) {
            param_4 = (uint *)((int)puVar3 + 6);
            puVar1[-4] = (short)puVar3[1];
            goto LAB_404ddcb0;
          }
          if (uVar4 != 0xd) {
            *puVar5 = 3;
          }
        }
      }
      param_4 = puVar3 + 2;
      *(uint *)(puVar1 + -4) = puVar3[1];
    }
    else {
      puVar2 = (undefined *)puVar3[1];
LAB_404ddd44:
      param_4 = puVar3 + 2;
      *(undefined **)(puVar1 + -4) = puVar2;
    }
LAB_404ddcb0:
    param_3 = param_3 + -1;
    puVar1 = puVar5;
  } while( true );
}



/* 404ddd4c SHPackDispParams */

/* Boundary evidence: original MIPS .pdata 404ddd4c..404ddd6f. Semantic name remains unreviewed. */

void SHPackDispParams(undefined4 *param_1,void *param_2,int param_3,uint param_4)

{
  uint local_resc;
  
                    /* 0xdd4c  282  SHPackDispParams */
  local_resc = param_4;
  SHPackDispParamsV(param_1,param_2,param_3,&local_resc);
  return;
}



/* 404ddd70 FUN_404ddd70 */

/* Boundary evidence: original MIPS .pdata 404ddd70..404dddcb. Semantic name remains unreviewed. */

undefined4 FUN_404ddd70(undefined4 *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  *param_3 = 0;
  if ((param_2 != 0) && (uVar1 = (**(code **)*param_1)(param_1,param_2,param_3), *param_3 == 0)) {
    uVar1 = 0x80004002;
  }
  return uVar1;
}



/* 404dddcc FUN_404dddcc */

/* Boundary evidence: original MIPS .pdata 404dddcc..404ddf1f. Semantic name remains unreviewed. */

int FUN_404dddcc(int *param_1,int param_2,int param_3,undefined *param_4,undefined4 param_5)

{
  int iVar1;
  int *local_30;
  int *local_2c;
  undefined1 auStack_28 [8];
  int *local_20 [2];
  
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7fffbffe;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,&local_2c);
  }
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_2c + 0xc))(local_2c,1,local_20,auStack_28);
    while (iVar1 == 0) {
      iVar1 = FUN_404ddd70(local_20[0],param_2,(int *)&local_30);
      if ((iVar1 < 0) && (iVar1 = FUN_404ddd70(local_20[0],param_3,(int *)&local_30), iVar1 < 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(code *)param_4)(local_30,param_5);
        (**(code **)(*local_30 + 8))();
      }
      if (local_20[0] != (int *)0x0) {
        (**(code **)(*local_20[0] + 8))();
      }
      if (iVar1 < 0) break;
      iVar1 = (**(code **)(*local_2c + 0xc))(local_2c,1,local_20,auStack_28);
    }
    (**(code **)(*local_2c + 8))();
    iVar1 = 0;
  }
  return iVar1;
}



/* 404ddf20 FUN_404ddf20 */

/* Boundary evidence: original MIPS .pdata 404ddf20..404ddfff. Semantic name remains unreviewed. */

int FUN_404ddf20(int *param_1,int param_2)

{
  int iVar1;
  
  if ((*(code **)(param_2 + 0x22) == (code *)0x0) ||
     (iVar1 = (**(code **)(param_2 + 0x22))(param_1,param_2), iVar1 == 0)) {
    (**(code **)(*param_1 + 0x18))
              (param_1,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
               *(undefined4 *)(param_2 + 0xc),*(undefined2 *)(param_2 + 0x10),
               *(undefined4 *)(param_2 + 0x12),*(undefined4 *)(param_2 + 0x16),
               *(undefined4 *)(param_2 + 0x1a),*(undefined4 *)(param_2 + 0x1e));
    iVar1 = 0;
  }
  return iVar1;
}



/* 404de000 FUN_404de000 */

/* Boundary evidence: original MIPS .pdata 404de000..404de13f. Semantic name remains unreviewed. */

int FUN_404de000(int *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  undefined4 local_38;
  undefined1 auStack_34 [12];
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_404f4224;
  local_38 = 0;
  memset(auStack_34,0,0xc);
  piVar5 = (int *)((int)param_2 + 0x12);
  if (*piVar5 == 0) {
    *piVar5 = (int)&local_38;
  }
  if ((*param_2 & 1) == 0) {
    *(undefined4 *)((int)param_2 + 0x22) = 0;
  }
  if ((*param_2 & 2) != 0) {
    param_2[2] = (uint)&DAT_404dbe1c;
    uVar1 = (int)param_2 + 0x19U & 3;
    puVar2 = (uint *)(((int)param_2 + 0x19U) - uVar1);
    *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
    uVar1 = (int)param_2 + 0x1dU & 3;
    puVar2 = (uint *)(((int)param_2 + 0x1dU) - uVar1);
    *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
    uVar1 = (int)param_2 + 0x21U & 3;
    puVar2 = (uint *)(((int)param_2 + 0x21U) - uVar1);
    *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
    param_2[3] = 0;
    *(undefined1 *)(param_2 + 4) = 1;
    *(undefined1 *)((int)param_2 + 0x11) = 0;
    uVar1 = (int)param_2 + 0x16U & 3;
    puVar2 = (uint *)(((int)param_2 + 0x16U) - uVar1);
    *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
    uVar1 = (int)param_2 + 0x1aU & 3;
    puVar2 = (uint *)(((int)param_2 + 0x1aU) - uVar1);
    *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
    uVar1 = (int)param_2 + 0x1eU & 3;
    puVar2 = (uint *)(((int)param_2 + 0x1eU) - uVar1);
    *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  }
  iVar3 = (**(code **)(*param_1 + 0xc))(param_1,auStack_28);
  puVar4 = auStack_28;
  if (iVar3 != 0) {
    puVar4 = (undefined1 *)0x0;
  }
  iVar3 = FUN_404dddcc(param_1,(int)puVar4,0x404dbe0c,FUN_404ddf20,param_2);
  if ((undefined4 *)*piVar5 == &local_38) {
    *piVar5 = 0;
  }
  FUN_404f1430(local_18);
  return iVar3;
}



/* 404de188 IConnectionPoint_InvokeWithCancel */

/* Boundary evidence: original MIPS .pdata 404de188..404de1d3. Semantic name remains unreviewed. */

void IConnectionPoint_InvokeWithCancel
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  uint local_38;
  undefined4 local_34;
  undefined4 local_26;
  undefined1 *local_16;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0xe188  283  IConnectionPoint_InvokeWithCancel */
  local_38 = 3;
  local_16 = &LAB_404de140;
  local_c = param_5;
  local_34 = param_2;
  local_26 = param_3;
  local_10 = param_4;
  FUN_404de000(param_1,&local_38);
  return;
}



/* 404de1d4 IConnectionPoint_SimpleInvoke */

/* Boundary evidence: original MIPS .pdata 404de1d4..404de20b. Semantic name remains unreviewed. */

void IConnectionPoint_SimpleInvoke(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint local_30;
  undefined4 local_2c;
  undefined4 local_1e;
  
                    /* 0xe1d4  284  IConnectionPoint_SimpleInvoke */
  local_30 = 2;
  local_2c = param_2;
  local_1e = param_3;
  FUN_404de000(param_1,&local_30);
  return;
}



/* 404de20c FUN_404de20c */

/* Boundary evidence: original MIPS .pdata 404de20c..404de29b. Semantic name remains unreviewed. */

int FUN_404de20c(int *param_1,undefined4 param_2,void *param_3,int param_4,uint *param_5)

{
  undefined1 *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 auStack_48 [4];
  uint local_38;
  undefined4 local_34;
  undefined1 auStack_26 [22];
  
  if (param_1 == (int *)0x0) {
    iVar4 = -0x7fffbffe;
  }
  else {
    iVar4 = SHPackDispParamsV(auStack_48,param_3,param_4,param_5);
    if (-1 < iVar4) {
      puVar1 = auStack_26 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)auStack_48 >> (3 - uVar2) * 8;
      local_38 = 2;
      uVar2 = (uint)auStack_26 & 3;
      puVar3 = (uint *)(auStack_26 + -uVar2);
      *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | (int)auStack_48 << uVar2 * 8;
      local_34 = param_2;
      iVar4 = FUN_404de000(param_1,&local_38);
    }
  }
  return iVar4;
}



/* 404de29c FUN_404de29c */

/* Boundary evidence: original MIPS .pdata 404de29c..404de2c3. Semantic name remains unreviewed. */

undefined4 FUN_404de29c(int *param_1)

{
  (**(code **)(*param_1 + 0xc))();
  return 0;
}



/* 404de2c4 FUN_404de2c4 */

/* Boundary evidence: original MIPS .pdata 404de2c4..404de363. Semantic name remains unreviewed. */

int FUN_404de2c4(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *local_18 [2];
  
  *param_3 = 0;
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = -0x7fffbffe;
  }
  else {
    iVar1 = (**(code **)*param_1)(param_1,&UNK_404dbcac,local_18);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_18[0] + 0x10))(local_18[0],param_2,param_3);
      (**(code **)(*local_18[0] + 8))();
    }
  }
  return iVar1;
}



/* 404de364 IUnknown_CPContainerInvokeParam */

/* Boundary evidence: original MIPS .pdata 404de364..404de3df. Semantic name remains unreviewed. */

int IUnknown_CPContainerInvokeParam
              (undefined4 *param_1,undefined4 param_2,undefined4 param_3,void *param_4,int param_5)

{
  int iVar1;
  int *local_18 [2];
  
                    /* 0xe364  286  IUnknown_CPContainerInvokeParam */
  iVar1 = FUN_404de2c4(param_1,param_2,local_18);
  if (-1 < iVar1) {
    iVar1 = FUN_404de20c(local_18[0],param_3,param_4,param_5,(uint *)&stack0x00000014);
    (**(code **)(*local_18[0] + 8))();
  }
  return iVar1;
}



/* 404de3e0 IUnknown_CPContainerOnChanged */

/* Boundary evidence: original MIPS .pdata 404de3e0..404de463. Semantic name remains unreviewed. */

int IUnknown_CPContainerOnChanged(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_18 [2];
  
                    /* 0xe3e0  287  IUnknown_CPContainerOnChanged */
  iVar1 = FUN_404de2c4(param_1,&DAT_404dbe2c,local_18);
  if (-1 < iVar1) {
    iVar1 = FUN_404dddcc(local_18[0],0x404dbe2c,0,FUN_404de29c,param_2);
    (**(code **)(*local_18[0] + 8))();
  }
  return iVar1;
}



/* 404de464 IsCharSpaceW */

BOOL IsCharSpaceW(WCHAR wch)

{
  undefined2 in_register_00000012;
  uint uVar1;
  int iVar2;
  
                    /* 0xe464  29  IsCharSpaceW */
  uVar1 = CONCAT22(in_register_00000012,wch) >> 8;
  if (uVar1 == 0) {
    iVar2 = 0x1e;
  }
  else {
    iVar2 = 0x20;
    if (uVar1 == 0x20) {
      iVar2 = 0x1f;
    }
    else if (uVar1 != 0x30) {
      if (uVar1 == 0xfe) {
        iVar2 = 0x21;
      }
      else {
        iVar2 = 0;
      }
    }
  }
  return *(uint *)(&DAT_404d18dc +
                  (uint)(byte)(&DAT_404d1c44)[(((ushort)wch & 0xe0) >> 5) + iVar2 * 8] * 4) >>
         ((ushort)wch & 0x1f) & 1;
}



/* 404de4f8 IsCharDigitW */

uint IsCharDigitW(uint param_1)

{
                    /* 0xe4f8  33  IsCharDigitW */
  return *(uint *)(&DAT_404d18dc +
                  (uint)(byte)(&DAT_404d1c44)
                              [(uint)(byte)(&DAT_404d2154)[param_1 >> 8] * 8 + (param_1 >> 5 & 7)] *
                  4) >> (param_1 & 0x1f) & 1;
}



/* 404de554 IsCharXDigitW */

uint IsCharXDigitW(uint param_1)

{
  int iVar1;
  
                    /* 0xe554  34  IsCharXDigitW */
  if (param_1 >> 8 == 0) {
    iVar1 = 0x49;
  }
  else if (param_1 >> 8 == 0xff) {
    iVar1 = 0x4a;
  }
  else {
    iVar1 = 0;
  }
  return *(uint *)(&DAT_404d18dc + (uint)(byte)(&DAT_404d1c44)[(param_1 >> 5 & 7) + iVar1 * 8] * 4)
         >> (param_1 & 0x1f) & 1;
}



/* 404de5c8 IsCharCntrlW */

undefined4 IsCharCntrlW(uint param_1)

{
  undefined4 uVar1;
  
                    /* 0xe5c8  32  IsCharCntrlW */
  if ((param_1 < 0x20) || (uVar1 = 0, param_1 - 0x7f < 0x21)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 404de5f4 IsCharBlankW */

undefined4 IsCharBlankW(int param_1)

{
  undefined4 uVar1;
  
                    /* 0xe5f4  30  IsCharBlankW */
  if ((((param_1 == 9) || (param_1 == 0x20)) || (param_1 == 0xa0)) ||
     ((param_1 == 0x3000 || (uVar1 = 0, param_1 == 0xfeff)))) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 404de640 FUN_404de640 */

/* Boundary evidence: original MIPS .pdata 404de640..404de6cb. Semantic name remains unreviewed. */

undefined4 FUN_404de640(char *param_1,STRSAFE_LPSTR param_2,uint param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  
  sVar1 = strlen(param_1);
  if (sVar1 + 0x1d < param_3) {
    uVar2 = 1;
    StringCchPrintfA(param_2,param_3,"MIME\\Database\\Content Type\\%s",param_1);
  }
  else {
    uVar2 = 0;
    if (param_3 != 0) {
      *param_2 = '\0';
    }
  }
  return uVar2;
}



/* 404de6cc FUN_404de6cc */

/* Boundary evidence: original MIPS .pdata 404de6cc..404de78b. Semantic name remains unreviewed. */

int FUN_404de6cc(LPCWSTR param_1,LPWSTR param_2,int param_3)

{
  int iVar1;
  CHAR aCStack_220 [264];
  char acStack_118 [260];
  uint local_14;
  
  local_14 = DAT_404f4224;
  WideCharToMultiByte(0,0,param_1,-1,aCStack_220,0x104,(LPCSTR)0x0,(LPBOOL)0x0);
  iVar1 = FUN_404de640(aCStack_220,acStack_118,0x104);
  if (iVar1 != 0) {
    MultiByteToWideChar(0,0,acStack_118,-1,param_2,param_3);
  }
  FUN_404f1430(local_14);
  return iVar1;
}



/* 404de78c FUN_404de78c */

/* Boundary evidence: original MIPS .pdata 404de78c..404de823. Semantic name remains unreviewed. */

undefined4 FUN_404de78c(LPCWSTR param_1,LPCWSTR param_2,DWORD *param_3,void *param_4,DWORD *param_5)

{
  int iVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_404f4224;
  iVar1 = FUN_404de6cc(param_1,aWStack_228,0x104);
  if (iVar1 != 0) {
    LVar2 = SHGetValueW((HKEY)0x80000000,aWStack_228,param_2,param_3,param_4,param_5);
    uVar3 = 1;
    if (LVar2 == 0) goto LAB_404de7fc;
  }
  uVar3 = 0;
LAB_404de7fc:
  FUN_404f1430(local_20);
  return uVar3;
}



/* 404de824 FUN_404de824 */

/* Boundary evidence: original MIPS .pdata 404de824..404de88f. Semantic name remains unreviewed. */

undefined4 FUN_404de824(LPCWSTR param_1,LPCWSTR param_2,undefined2 *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  DWORD local_18;
  DWORD local_14;
  
  local_18 = param_4 << 1;
  iVar1 = FUN_404de78c(param_1,param_2,&local_14,param_3,&local_18);
  if (((iVar1 == 0) || (uVar2 = 1, local_14 != 1)) && (uVar2 = 0, param_4 != 0)) {
    *param_3 = 0;
  }
  return uVar2;
}



/* 404de890 MIME_GetExtensionW */

/* Boundary evidence: original MIPS .pdata 404de890..404de953. Semantic name remains unreviewed. */

undefined4 MIME_GetExtensionW(LPCWSTR param_1,undefined2 *param_2,uint param_3)

{
  int iVar1;
  size_t sVar2;
  wchar_t *_Str;
  
                    /* 0xe890  331  MIME_GetExtensionW */
  if (2 < param_3) {
    _Str = param_2 + 1;
    iVar1 = FUN_404de824(param_1,L"Extension",_Str,param_3 - 1);
    if ((iVar1 != 0) && (*_Str != L'\0')) {
      if (*_Str == L'.') {
        sVar2 = wcslen(_Str);
        memmove(param_2,_Str,(sVar2 + 1) * 2);
      }
      else {
        *param_2 = 0x2e;
      }
      return 1;
    }
  }
  if (param_3 != 0) {
    *param_2 = 0;
  }
  return 0;
}



/* 404de954 FUN_404de954 */

/* Boundary evidence: original MIPS .pdata 404de954..404de9f3. Semantic name remains unreviewed. */

uint FUN_404de954(void)

{
  uint uVar1;
  HMODULE pHVar2;
  
  uVar1 = (uint)DAT_404f427c;
  if (uVar1 == 0) {
    if (DAT_404f4278 == (code *)0x0) {
      pHVar2 = GetModuleHandleW(L"coredll.dll");
      if (pHVar2 != (HMODULE)0x0) {
        DAT_404f4278 = (code *)GetProcAddressW(pHVar2,L"GetSystemDefaultUILanguage");
      }
      if (DAT_404f4278 == (code *)0x0) {
        return (uint)DAT_404f427c;
      }
    }
    uVar1 = (*DAT_404f4278)();
  }
  return uVar1;
}



/* 404de9f4 FUN_404de9f4 */

/* Boundary evidence: original MIPS .pdata 404de9f4..404deabb. Semantic name remains unreviewed. */

bool FUN_404de9f4(wchar_t *param_1,uint param_2,STRSAFE_LPCWSTR param_3)

{
  size_t sVar1;
  int iVar2;
  wchar_t *pwVar3;
  
  sVar1 = wcslen(param_1);
  pwVar3 = param_1 + sVar1;
  if (pwVar3[-1] == L'\\') {
    if (*param_3 == L'\\') {
      param_3 = param_3 + 1;
    }
  }
  else if (*param_3 != L'\\') {
    if (param_2 <= sVar1) {
      iVar2 = -0x7fffbffb;
      goto LAB_404dea90;
    }
    *pwVar3 = L'\\';
    pwVar3[1] = L'\0';
  }
  iVar2 = StringCchCatW(param_1,param_2,param_3);
LAB_404dea90:
  return -1 < iVar2;
}



/* 404deabc MLLoadLibraryW */

/* Boundary evidence: original MIPS .pdata 404deabc..404debd3. Semantic name remains unreviewed. */

HMODULE MLLoadLibraryW(LPCWSTR param_1,HMODULE param_2)

{
  bool bVar1;
  uint uVar2;
  DWORD DVar3;
  undefined3 extraout_var;
  uint uVar4;
  HMODULE pHVar5;
  LPCWSTR lpLibFileName;
  WCHAR local_228 [260];
  uint local_20;
  
                    /* 0xeabc  378  MLLoadLibraryW */
  local_20 = DAT_404f4224;
  lpLibFileName = (LPCWSTR)0x0;
  if (param_1 == (LPCWSTR)0x0) {
    FUN_404f1430(DAT_404f4224);
    return (HMODULE)0x0;
  }
  local_228[0] = L'\0';
  uVar2 = FUN_404de954();
  if ((param_2 != (HMODULE)0x0) && (DVar3 = GetModuleFileNameW(param_2,local_228,0x104), DVar3 != 0)
     ) {
    PathRemoveFileSpecW(local_228);
    bVar1 = FUN_404de9f4(local_228,0x104,param_1);
    if ((CONCAT31(extraout_var,bVar1) != 0) && (uVar4 = FUN_404de954(), uVar4 == uVar2)) {
      lpLibFileName = local_228;
    }
  }
  pHVar5 = LoadLibraryW(lpLibFileName);
  if (pHVar5 == (HMODULE)0x0) {
    if (lpLibFileName != local_228) {
      FUN_404de954();
      pHVar5 = LoadLibraryW(local_228);
      if (pHVar5 != (HMODULE)0x0) goto LAB_404debac;
    }
    pHVar5 = LoadLibraryW(param_1);
  }
LAB_404debac:
  FUN_404f1430(local_20);
  return pHVar5;
}



/* 404debd4 MLFreeLibrary */

/* Boundary evidence: original MIPS .pdata 404debd4..404debf7. Semantic name remains unreviewed. */

void MLFreeLibrary(HMODULE param_1)

{
                    /* 0xebd4  418  MLFreeLibrary */
  FreeLibrary(param_1);
  return;
}



/* 404debf8 MLBuildResURLW */

/* Boundary evidence: original MIPS .pdata 404debf8..404dedc3. Semantic name remains unreviewed. */

HRESULT MLBuildResURLW(LPCWSTR param_1,HMODULE param_2,int param_3,wchar_t *param_4,
                      STRSAFE_LPWSTR param_5,size_t param_6)

{
  HMODULE hModule;
  DWORD DVar1;
  size_t sVar2;
  size_t sVar3;
  HRESULT HVar4;
  size_t cchDest;
  STRSAFE_LPWSTR pszDest;
  WCHAR aWStack_238 [260];
  uint local_30;
  
                    /* 0xebf8  406  MLBuildResURLW */
  local_30 = DAT_404f4224;
  HVar4 = -0x7ff8ffa9;
  if (((((param_1 != (LPCWSTR)0x0) && (param_2 != (HMODULE)0x0)) && (param_2 != (HMODULE)0xffffffff)
       ) && ((param_3 == 2 || (param_3 == 0)))) &&
     ((param_4 != (wchar_t *)0x0 && (param_5 != (STRSAFE_LPWSTR)0x0)))) {
    HVar4 = -0x7fffbffb;
    if (6 < (int)param_6) {
      StringCchCopyW(param_5,param_6,L"res://");
      pszDest = param_5 + 6;
      cchDest = param_6 - 6;
      hModule = MLLoadLibraryW(param_1,param_2);
      if (hModule != (HMODULE)0x0) {
        DVar1 = GetModuleFileNameW(hModule,aWStack_238,0x104);
        FreeLibrary(hModule);
        if (((DVar1 != 0) && (sVar2 = wcslen(aWStack_238), (int)(sVar2 + 1) <= (int)cchDest)) &&
           (HVar4 = StringCchCopyW(pszDest,cchDest,aWStack_238), -1 < HVar4)) {
          sVar3 = wcslen(param_4);
          if ((int)(sVar3 + 2) <= (int)(cchDest - sVar2)) {
            pszDest[sVar2] = L'/';
            HVar4 = StringCchCopyW(pszDest + sVar2 + 1,(cchDest - sVar2) - 1,param_4);
          }
          if (-1 < HVar4) goto LAB_404ded8c;
        }
      }
    }
    *param_5 = L'\0';
  }
LAB_404ded8c:
  FUN_404f1430(local_30);
  return HVar4;
}



/* 404dedc4 FUN_404dedc4 */

undefined4 FUN_404dedc4(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (((((param_1 & 0xffffff00) != 0) || ((int)(char)param_1 == 0)) ||
      (uVar2 = (int)(char)param_1 & 0xffff, uVar2 < 0x20)) ||
     ((0x7f < uVar2 || (uVar1 = 1, (*(ushort *)(&DAT_404d2f0c + (uVar2 - 0x20) * 2) & 5) == 0)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 404dee38 FUN_404dee38 */

undefined4 FUN_404dee38(char *param_1,ushort *param_2,int param_3)

{
  uint uVar1;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    uVar1 = (int)*param_1 & 0xffff;
    if ((uVar1 != *param_2) &&
       (((uVar1 < 0x41 || (0x5a < uVar1)) || (uVar1 + 0x20 != (uint)*param_2)))) break;
    param_1 = param_1 + 1;
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  }
  if (*param_2 < uVar1) {
    return 1;
  }
  return 0xffffffff;
}



/* 404deeb0 FUN_404deeb0 */

/* Boundary evidence: original MIPS .pdata 404deeb0..404defc7. Semantic name remains unreviewed. */

undefined4 FUN_404deeb0(LPCWSTR param_1,undefined *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **ppuVar4;
  
  iVar3 = DAT_404f4308;
  ppuVar4 = &PTR_DAT_404d30dc;
  if ((param_2 == (undefined *)(&DAT_404d30e4)[DAT_404f4308 * 4]) &&
     (iVar1 = FUN_404ee924((ushort *)param_1,(ushort *)(&PTR_DAT_404d30dc)[DAT_404f4308 * 4],
                           (int)param_2), iVar1 == 0)) {
LAB_404def94:
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = (&DAT_404d30e8)[iVar3 * 4];
    }
    uVar2 = (&DAT_404d30e0)[iVar3 * 4];
    DAT_404f4308 = iVar3;
  }
  else {
    iVar3 = 0;
    do {
      if ((param_2 == ppuVar4[2]) &&
         (iVar1 = StrCmpNIW(param_1,(LPCWSTR)*ppuVar4,(int)param_2), iVar1 == 0)) goto LAB_404def94;
      iVar3 = iVar3 + 1;
      ppuVar4 = ppuVar4 + 4;
    } while (iVar3 < 0x12);
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 404defc8 FUN_404defc8 */

/* Boundary evidence: original MIPS .pdata 404defc8..404df08f. Semantic name remains unreviewed. */

undefined4 FUN_404defc8(char *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  
  ppuVar3 = &PTR_DAT_404d30dc;
  iVar2 = 0;
  do {
    iVar1 = FUN_404dee38(param_1,(ushort *)*ppuVar3,param_2);
    if (iVar1 == 0) {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = (&DAT_404d30e8)[iVar2 * 4];
      }
      return (&DAT_404d30e0)[iVar2 * 4];
    }
    iVar2 = iVar2 + 1;
    ppuVar3 = ppuVar3 + 4;
  } while (iVar2 < 0x12);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return 0;
}



/* 404df090 FUN_404df090 */

/* Boundary evidence: original MIPS .pdata 404df090..404df12f. Semantic name remains unreviewed. */

undefined4 FUN_404df090(char *param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  
  ppuVar3 = &PTR_DAT_404d30dc;
  iVar2 = 0;
  while ((param_2 != ppuVar3[2] ||
         (iVar1 = FUN_404dee38(param_1,(ushort *)*ppuVar3,(int)param_2), iVar1 != 0))) {
    iVar2 = iVar2 + 1;
    ppuVar3 = ppuVar3 + 4;
    if (0x11 < iVar2) {
      return 0;
    }
  }
  return (&DAT_404d30e0)[iVar2 * 4];
}



/* 404df130 FUN_404df130 */

/* Boundary evidence: original MIPS .pdata 404df130..404df1cf. Semantic name remains unreviewed. */

undefined4 FUN_404df130(LPCWSTR param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  
  ppuVar3 = &PTR_DAT_404d30dc;
  iVar2 = 0;
  while ((param_2 != ppuVar3[2] ||
         (iVar1 = StrCmpNIW(param_1,(LPCWSTR)*ppuVar3,(int)param_2), iVar1 != 0))) {
    iVar2 = iVar2 + 1;
    ppuVar3 = ppuVar3 + 4;
    if (0x11 < iVar2) {
      return 0;
    }
  }
  return (&DAT_404d30e0)[iVar2 * 4];
}



/* 404df1d0 FUN_404df1d0 */

/* Boundary evidence: original MIPS .pdata 404df1d0..404df293. Semantic name remains unreviewed. */

wchar_t * FUN_404df1d0(wchar_t *param_1,uint *param_2,uint param_3)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  
  pwVar4 = (wchar_t *)0x0;
  if (param_1 != (wchar_t *)0x0) {
    do {
      iVar3 = 0;
      if (*param_1 == L'\b') {
        do {
          param_1 = param_1 + 1;
          iVar3 = iVar3 + 1;
        } while (*param_1 == L'\b');
        if (iVar3 == 0) goto LAB_404df224;
      }
      else {
LAB_404df224:
        iVar3 = 1;
      }
      uVar2 = *param_2;
      if (uVar2 + iVar3 < param_3) {
        sVar1 = wcslen(param_1);
        *param_2 = uVar2 + iVar3;
        pwVar4 = param_1 + sVar1 + 1;
      }
      else {
        pwVar4 = (wchar_t *)0x0;
      }
    } while ((pwVar4 != (wchar_t *)0x0) && (param_1 = pwVar4, *pwVar4 == L'\b'));
  }
  return pwVar4;
}



/* 404df294 FUN_404df294 */

/* Boundary evidence: original MIPS .pdata 404df294..404df343. Semantic name remains unreviewed. */

wchar_t * FUN_404df294(wchar_t *param_1,uint param_2,int param_3)

{
  bool bVar1;
  wchar_t *pwVar2;
  uint local_20 [2];
  
  local_20[0] = 0;
  pwVar2 = (wchar_t *)0x0;
  bVar1 = false;
  if (param_2 != 0) {
    if ((param_1 != (wchar_t *)0x0) && (*param_1 != L'\b')) {
      bVar1 = true;
      pwVar2 = param_1;
    }
    while (param_1 = FUN_404df1d0(param_1,local_20,param_2), param_1 != (wchar_t *)0x0) {
      bVar1 = pwVar2 == (wchar_t *)0x0;
      pwVar2 = param_1;
    }
    if ((param_3 != 0) && (bVar1)) {
      pwVar2 = (wchar_t *)0x0;
    }
  }
  return pwVar2;
}



/* 404df344 FUN_404df344 */

/* Boundary evidence: original MIPS .pdata 404df344..404df38f. Semantic name remains unreviewed. */

wchar_t * FUN_404df344(wchar_t *param_1,uint *param_2,uint param_3)

{
  *param_2 = 0;
  if ((param_1 == (wchar_t *)0x0) || (param_3 == 0)) {
    param_1 = (wchar_t *)0x0;
  }
  else if (*param_1 == L'\b') {
    param_1 = FUN_404df1d0(param_1,param_2,param_3);
  }
  return param_1;
}



/* 404df390 FUN_404df390 */

undefined4 FUN_404df390(short *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 == 0) || ((param_1[1] != 0x3a && ((*param_1 == 0 || (param_1[1] != 0x7c)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 404df3dc FUN_404df3dc */

/* Boundary evidence: original MIPS .pdata 404df3dc..404df46b. Semantic name remains unreviewed. */

void FUN_404df3dc(wchar_t *param_1)

{
  wchar_t wVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  
  if ((param_1 != (wchar_t *)0x0) && (sVar2 = wcslen(param_1), 7 < sVar2)) {
    pwVar3 = param_1 + 7;
    wVar1 = *pwVar3;
    while (((wVar1 != L'\0' && (wVar1 = *pwVar3, wVar1 != L'?')) && (wVar1 != L'#'))) {
      if (wVar1 == L'/') {
        *pwVar3 = L'\\';
      }
      pwVar3 = pwVar3 + 1;
      wVar1 = *pwVar3;
    }
  }
  return;
}



/* 404df46c FUN_404df46c */

void FUN_404df46c(ushort *param_1)

{
  ushort *puVar1;
  ushort uVar2;
  ushort *puVar3;
  
  uVar2 = *param_1;
  if (uVar2 != 0) {
    puVar3 = (ushort *)0x0;
    puVar1 = param_1;
    do {
      if (0x20 < uVar2) break;
      puVar1 = puVar1 + 1;
      uVar2 = *puVar1;
    } while (uVar2 != 0);
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      do {
        if (((uVar2 != 9) && (uVar2 != 0xd)) && (uVar2 != 10)) {
          if (uVar2 < 0x21) {
            if (puVar3 == (ushort *)0x0) {
              puVar3 = param_1;
            }
          }
          else {
            puVar3 = (ushort *)0x0;
          }
          *param_1 = uVar2;
          param_1 = param_1 + 1;
        }
        puVar1 = puVar1 + 1;
        uVar2 = *puVar1;
      } while (uVar2 != 0);
      if (puVar3 != (ushort *)0x0) {
        *puVar3 = 0;
        return;
      }
    }
    *param_1 = 0;
  }
  return;
}



/* 404df530 FUN_404df530 */

/* Boundary evidence: original MIPS .pdata 404df530..404df5c3. Semantic name remains unreviewed. */

undefined4 FUN_404df530(int param_1,uint param_2)

{
  int iVar1;
  uint nChar;
  uint uVar2;
  
  uVar2 = 0;
  while ((nChar = *(uint *)((int)&DAT_404d3204 + uVar2), param_2 < nChar ||
         (iVar1 = StrCmpNIA((LPCSTR)(param_1 - nChar),
                            *(LPCSTR *)((int)&PTR_s__html_404d31fc + uVar2),nChar), iVar1 != 0))) {
    uVar2 = uVar2 + 0xc;
    if (0x9b < uVar2) {
      return 0;
    }
  }
  return 1;
}



/* 404df5c4 FUN_404df5c4 */

/* Boundary evidence: original MIPS .pdata 404df5c4..404df65f. Semantic name remains unreviewed. */

undefined4 FUN_404df5c4(int param_1,uint param_2)

{
  int iVar1;
  uint nChar;
  uint uVar2;
  
  uVar2 = 0;
  while ((nChar = *(uint *)((int)&DAT_404d3204 + uVar2), param_2 < nChar ||
         (iVar1 = StrCmpNIW((LPCWSTR)(param_1 + nChar * -2),
                            *(LPCWSTR *)((int)&PTR_u__html_404d3200 + uVar2),nChar), iVar1 != 0))) {
    uVar2 = uVar2 + 0xc;
    if (0x9b < uVar2) {
      return 0;
    }
  }
  return 1;
}



/* 404df660 FUN_404df660 */

/* Boundary evidence: original MIPS .pdata 404df660..404df71b. Semantic name remains unreviewed. */

ushort * FUN_404df660(ushort *param_1,int param_2,int param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  ushort *puVar4;
  
  puVar1 = FUN_404ecf10(param_1,0x23,param_2);
  if (((puVar1 != (ushort *)0x0) && (param_3 != 0)) &&
     ((puVar2 = FUN_404ecf10(param_1,0x3f,param_2), puVar4 = puVar1, puVar2 == (ushort *)0x0 ||
      (puVar1 <= puVar2)))) {
    do {
      iVar3 = FUN_404df530((int)puVar4,(int)puVar4 - (int)param_1);
      if (iVar3 != 0) {
        return puVar4;
      }
      puVar4 = FUN_404ecf10((ushort *)((int)puVar4 + 1),0x23,param_2);
      puVar1 = (ushort *)0x0;
    } while (puVar4 != (ushort *)0x0);
  }
  return puVar1;
}



/* 404df71c FUN_404df71c */

/* Boundary evidence: original MIPS .pdata 404df71c..404df7c3. Semantic name remains unreviewed. */

LPWSTR FUN_404df71c(LPCWSTR param_1,int param_2)

{
  LPWSTR pWVar1;
  LPWSTR pWVar2;
  int iVar3;
  LPWSTR pWVar4;
  
  pWVar1 = StrChrW(param_1,L'#');
  if (((pWVar1 != (LPWSTR)0x0) && (param_2 != 0)) &&
     ((pWVar2 = StrChrW(param_1,L'?'), pWVar4 = pWVar1, pWVar2 == (LPWSTR)0x0 || (pWVar1 <= pWVar2))
     )) {
    do {
      iVar3 = FUN_404df5c4((int)pWVar4,(int)pWVar4 - (int)param_1 >> 1);
      if (iVar3 != 0) {
        return pWVar4;
      }
      pWVar4 = StrChrW(pWVar4 + 1,L'#');
      pWVar1 = (LPWSTR)0x0;
    } while (pWVar4 != (LPWSTR)0x0);
  }
  return pWVar1;
}



/* 404df7c4 FUN_404df7c4 */

/* Boundary evidence: original MIPS .pdata 404df7c4..404df82f. Semantic name remains unreviewed. */

void FUN_404df7c4(undefined4 *param_1,uint *param_2)

{
  LPWSTR pWVar1;
  
  if (((*(LPCWSTR)*param_1 != L'\0') && ((*param_2 & 1) == 0)) &&
     (pWVar1 = FUN_404df71c((LPCWSTR)*param_1,(uint)(param_2[2] == 9)), pWVar1 != (LPWSTR)0x0)) {
    *pWVar1 = L'\0';
    param_2[9] = (uint)(pWVar1 + 1);
  }
  return;
}



/* 404df830 FUN_404df830 */

char * FUN_404df830(char *param_1,uint *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  
  *param_2 = 0;
  cVar1 = *param_1;
  bVar2 = false;
  bVar3 = false;
  uVar5 = 0;
  do {
    uVar4 = (uint)cVar1;
    if (uVar4 == 0) {
      return (char *)0x0;
    }
    if (uVar4 == 0x5b) {
      bVar2 = true;
    }
    else if (uVar4 == 0x5d) {
      bVar3 = true;
    }
    else if (uVar4 == 0x3a) {
      if (bVar2) {
        if (bVar3) {
LAB_404df898:
          if (uVar5 < 2) {
            return (char *)0x0;
          }
          *param_2 = uVar5;
          return param_1;
        }
      }
      else if (!bVar3) goto LAB_404df898;
    }
    uVar4 = uVar4 & 0xffff;
    if (uVar4 < 0x20) {
      return (char *)0x0;
    }
    if (0x7f < uVar4) {
      return (char *)0x0;
    }
    if ((*(ushort *)(&DAT_404d2f0c + (uVar4 - 0x20) * 2) & 5) == 0) {
      return (char *)0x0;
    }
    uVar5 = uVar5 + 1;
    cVar1 = param_1[uVar5];
  } while( true );
}



/* 404df914 FUN_404df914 */

/* Boundary evidence: original MIPS .pdata 404df914..404dfa2b. Semantic name remains unreviewed. */

ushort * FUN_404df914(ushort *param_1,uint *param_2,int param_3)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  
  *param_2 = 0;
  uVar1 = *param_1;
  bVar2 = false;
  bVar3 = false;
  uVar6 = 0;
  puVar7 = param_1;
  do {
    uVar5 = (uint)uVar1;
    if (uVar5 == 0) {
      return (ushort *)0x0;
    }
    if (uVar5 == 0x5b) {
      bVar2 = true;
    }
    else if (uVar5 == 0x5d) {
      bVar3 = true;
    }
    else {
      if (uVar5 == 0x3a) {
        if (bVar2) {
          if (bVar3) goto LAB_404df9a4;
        }
        else if (!bVar3) goto LAB_404df9a4;
      }
      if ((param_3 != 0) && (uVar5 == 0x3b)) {
LAB_404df9a4:
        if (uVar6 < 2) {
          return (ushort *)0x0;
        }
        *param_2 = uVar6;
        return param_1;
      }
    }
    iVar4 = FUN_404dedc4(uVar5);
    if (iVar4 == 0) {
      return (ushort *)0x0;
    }
    puVar7 = puVar7 + 1;
    uVar1 = *puVar7;
    uVar6 = uVar6 + 1;
  } while( true );
}



/* 404dfa2c FUN_404dfa2c */

/* Boundary evidence: original MIPS .pdata 404dfa2c..404dfb43. Semantic name remains unreviewed. */

LPCWSTR FUN_404dfa2c(LPCWSTR param_1)

{
  BOOL BVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LPCWSTR pWVar4;
  undefined *local_18 [2];
  
  if ((*param_1 != L'\0') && (param_1[1] == L':')) {
    return param_1;
  }
  BVar1 = PathIsUNCW(param_1);
  if (BVar1 != 0) {
    return param_1;
  }
  pWVar2 = (LPCWSTR)FUN_404df914((ushort *)param_1,(uint *)local_18,0);
  if ((pWVar2 != (LPCWSTR)0x0) &&
     (iVar3 = FUN_404deeb0(pWVar2,local_18[0],(undefined4 *)0x0), iVar3 == 9)) {
    iVar3 = 0;
    pWVar2 = param_1 + (int)(local_18[0] + 1);
    for (pWVar4 = param_1 + (int)(local_18[0] + 1); (*pWVar4 == L'/' || (*pWVar4 == L'\\'));
        pWVar4 = pWVar4 + 1) {
      iVar3 = iVar3 + 1;
      pWVar2 = pWVar4;
    }
    if (iVar3 == 2) {
      if ((pWVar2[1] != L'\0') && (pWVar2[2] == L':')) {
        return pWVar2 + 1;
      }
    }
    else if (iVar3 == 4) {
      return pWVar2 + -1;
    }
  }
  return (LPCWSTR)0x0;
}



/* 404dfb44 FUN_404dfb44 */

/* Boundary evidence: original MIPS .pdata 404dfb44..404dfbcb. Semantic name remains unreviewed. */

void FUN_404dfb44(wchar_t *param_1,LPCWSTR param_2)

{
  int iVar1;
  BOOL BVar2;
  
  iVar1 = FUN_404df390(param_2);
  if ((iVar1 == 0) && (BVar2 = PathIsUNCW(param_2), BVar2 == 0)) {
    FUN_404f0dd4(param_1,param_2,0xffffffff);
  }
  else {
    FUN_404f0dd4(param_1,L"file://",0xffffffff);
    FUN_404f0e24(param_1,param_2,0xffffffff);
  }
  return;
}



/* 404dfbcc FUN_404dfbcc */

/* Boundary evidence: original MIPS .pdata 404dfbcc..404dfc9b. Semantic name remains unreviewed. */

void FUN_404dfbcc(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  ushort *puVar3;
  undefined *local_20 [2];
  
  puVar3 = (ushort *)*param_1;
  if ((*puVar3 != 0) && (iVar1 = FUN_404df390((short *)puVar3), iVar1 == 0)) {
    puVar3 = FUN_404df914(puVar3,(uint *)local_20,0);
    param_2[1] = puVar3;
    if (puVar3 == (ushort *)0x0) {
      if (local_20[0] != (undefined *)0x0) {
        *param_1 = (int)(local_20[0] + 1) * 2 + *param_1;
      }
    }
    else {
      puVar3[(int)local_20[0]] = 0;
      CharLowerW((LPWSTR)param_2[1]);
      *param_1 = param_2[1] + (int)local_20[0] * 2 + 2;
      uVar2 = FUN_404deeb0((LPCWSTR)param_2[1],local_20[0],param_2);
      param_2[2] = uVar2;
    }
  }
  return;
}



/* 404dfc9c FUN_404dfc9c */

/* Boundary evidence: original MIPS .pdata 404dfc9c..404dfd0f. Semantic name remains unreviewed. */

void FUN_404dfc9c(undefined4 *param_1,uint *param_2)

{
  LPWSTR pWVar1;
  
  if (((*(LPCWSTR)*param_1 != L'\0') && ((*param_2 & 1) == 0)) &&
     ((pWVar1 = StrChrW((LPCWSTR)*param_1,L'?'), pWVar1 != (LPWSTR)0x0 ||
      (((LPCWSTR)param_2[9] != (LPCWSTR)0x0 &&
       (pWVar1 = StrChrW((LPCWSTR)param_2[9],L'?'), pWVar1 != (LPWSTR)0x0)))))) {
    *pWVar1 = L'\0';
    param_2[8] = (uint)(pWVar1 + 1);
  }
  return;
}



/* 404dfd10 FUN_404dfd10 */

/* Boundary evidence: original MIPS .pdata 404dfd10..404dfd97. Semantic name remains unreviewed. */

void FUN_404dfd10(int *param_1,uint *param_2)

{
  LPWSTR pWVar1;
  size_t sVar2;
  wchar_t *_Str;
  
  if (*(short *)*param_1 == 0x40) {
    param_2[3] = (uint)*param_1;
    pWVar1 = StrChrW((LPCWSTR)*param_1,L'/');
    if (pWVar1 == (LPWSTR)0x0) {
      _Str = (wchar_t *)*param_1;
      sVar2 = wcslen(_Str);
      *param_1 = (int)(_Str + sVar2);
    }
    else {
      *param_2 = *param_2 | 0x100;
      *pWVar1 = L'\0';
      *param_1 = (int)(pWVar1 + 1);
    }
  }
  return;
}



/* 404dfd98 FUN_404dfd98 */

/* Boundary evidence: original MIPS .pdata 404dfd98..404dfe53. Semantic name remains unreviewed. */

void FUN_404dfd98(int *param_1,uint *param_2)

{
  LPWSTR pWVar1;
  size_t sVar2;
  LPCWSTR lpStart;
  int iVar3;
  short *psVar4;
  wchar_t *_Str;
  
  if (*(short *)*param_1 == 0x2f) {
    *param_2 = *param_2 | 0x100;
    iVar3 = *param_1;
    psVar4 = (short *)(iVar3 + 2);
    *param_1 = (int)psVar4;
    if (*psVar4 == 0x2f) {
      lpStart = (LPCWSTR)(iVar3 + 4);
      param_2[3] = (uint)lpStart;
      pWVar1 = StrChrW(lpStart,L'/');
      if (pWVar1 == (LPWSTR)0x0) {
        _Str = (wchar_t *)*param_1;
        sVar2 = wcslen(_Str);
        *param_1 = (int)(_Str + sVar2);
      }
      else {
        *pWVar1 = L'\0';
        *param_1 = (int)(pWVar1 + 1);
      }
    }
  }
  else if (param_2[1] != 0) {
    *param_2 = *param_2 | 1;
  }
  return;
}



/* 404dfe54 FUN_404dfe54 */

/* Boundary evidence: original MIPS .pdata 404dfe54..404e0023. Semantic name remains unreviewed. */

void FUN_404dfe54(uint *param_1,uint *param_2)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  short *psVar4;
  uint uVar5;
  undefined2 *puVar6;
  wchar_t *pwVar7;
  
  uVar5 = 0;
  for (psVar4 = (short *)*param_1; (*psVar4 == 0x2f || (*psVar4 == 0x5c)); psVar4 = psVar4 + 1) {
    *param_1 = (uint)psVar4;
    uVar5 = uVar5 + 1;
  }
  if ((uVar5 == 0) && (iVar1 = FUN_404df390((short *)*param_1), iVar1 == 0)) goto LAB_404dffdc;
  uVar3 = *param_2;
  *param_2 = uVar3 | 0x100;
  if (uVar5 == 0) goto LAB_404dffdc;
  if (uVar5 == 2) {
LAB_404dff34:
    puVar6 = (undefined2 *)*param_1;
    iVar1 = FUN_404df390(puVar6 + 1);
    if (iVar1 != 0) {
      *puVar6 = 0;
      param_2[3] = *param_1;
      *param_1 = *param_1 + 2;
      *param_2 = *param_2 | 0x10000000;
      goto LAB_404dffdc;
    }
  }
  else {
    if (uVar5 == 4) {
      *param_2 = uVar3 | 0x10000100;
      goto LAB_404dff34;
    }
    if ((uVar5 < 5) || (6 < uVar5)) {
      *(undefined2 *)*param_1 = 0;
      param_2[3] = *param_1;
      *param_1 = *param_1 + 2;
      goto LAB_404dffdc;
    }
  }
  uVar5 = *param_1;
  *param_1 = uVar5 + 2;
  param_2[3] = uVar5 + 2;
  for (pwVar7 = (wchar_t *)*param_1; ((*pwVar7 != L'\0' && (*pwVar7 != L'/')) && (*pwVar7 != L'\\'))
      ; pwVar7 = pwVar7 + 1) {
  }
  if (*pwVar7 == L'\0') {
    sVar2 = wcslen(pwVar7);
    pwVar7 = pwVar7 + sVar2;
  }
  else {
    *pwVar7 = L'\0';
    pwVar7 = pwVar7 + 1;
  }
  *param_1 = (uint)pwVar7;
LAB_404dffdc:
  if (((LPCWSTR)param_2[3] != (LPCWSTR)0x0) &&
     (iVar1 = StrCmpIW((LPCWSTR)param_2[3],L"localhost"), iVar1 == 0)) {
    param_2[3] = 0;
  }
  return;
}



/* 404e0024 FUN_404e0024 */

/* Boundary evidence: original MIPS .pdata 404e0024..404e00d3. Semantic name remains unreviewed. */

void FUN_404e0024(uint *param_1,uint *param_2,int param_3)

{
  short *psVar1;
  
  psVar1 = (short *)*param_1;
  if ((*psVar1 != 0) && ((*param_2 & 1) == 0)) {
    if (param_3 != 0) {
      for (; *psVar1 != 0; psVar1 = psVar1 + 1) {
        if (*psVar1 == 0x5c) {
          *psVar1 = 0x2f;
        }
      }
    }
    if (param_2[2] == 9) {
      FUN_404dfe54(param_1,param_2);
    }
    else if (param_2[2] == 10) {
      FUN_404dfd10((int *)param_1,param_2);
    }
    else {
      FUN_404dfd98((int *)param_1,param_2);
    }
  }
  return;
}



/* 404e00d4 FUN_404e00d4 */

/* Boundary evidence: original MIPS .pdata 404e00d4..404e019f. Semantic name remains unreviewed. */

void FUN_404e00d4(LPCWSTR param_1,uint *param_2)

{
  LPWSTR pWVar1;
  
  while (pWVar1 = StrChrW(param_1,L'/'), pWVar1 != (LPWSTR)0x0) {
    param_2[5] = param_2[5] + 1;
    param_1 = pWVar1 + 1;
    *pWVar1 = L'\0';
  }
  if (*param_1 == L'\0') {
    if (1 < param_2[5]) {
      param_2[5] = param_2[5] - 1;
    }
  }
  else {
    if (*param_1 != L'.') {
      return;
    }
    if (param_1[1] != L'\0') {
      if (param_1[1] != L'.') {
        return;
      }
      if (param_1[2] != L'\0') {
        return;
      }
    }
  }
  *param_2 = *param_2 | 0x1000;
  return;
}



/* 404e01a0 FUN_404e01a0 */

/* Boundary evidence: original MIPS .pdata 404e01a0..404e021b. Semantic name remains unreviewed. */

void FUN_404e01a0(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  LPCWSTR pWVar2;
  
  if (*(short *)*param_1 != 0) {
    iVar1 = FUN_404df390((short *)*param_1);
    if (iVar1 != 0) {
      *param_2 = *param_2 | 0x200;
    }
    pWVar2 = (LPCWSTR)*param_1;
    param_2[4] = (uint)pWVar2;
    param_2[5] = 1;
    if ((*param_2 & 1) == 0) {
      FUN_404e00d4(pWVar2,param_2);
    }
  }
  return;
}



/* 404e021c FUN_404e021c */

/* Boundary evidence: original MIPS .pdata 404e021c..404e02a7. Semantic name remains unreviewed. */

void FUN_404e021c(int *param_1,uint *param_2)

{
  short *psVar1;
  
  psVar1 = (short *)*param_1;
  if (*psVar1 != 0) {
    if ((*param_2 & 1) == 0) {
      if ((param_2[3] == 0) && ((*psVar1 == 0x2f || (*psVar1 == 0x5c)))) {
        *param_2 = *param_2 | 0x100;
        *param_1 = *param_1 + 2;
      }
      FUN_404e01a0(param_1,param_2);
    }
    else {
      param_2[4] = (uint)psVar1;
      param_2[5] = 1;
    }
  }
  return;
}



/* 404e02a8 FUN_404e02a8 */

/* Boundary evidence: original MIPS .pdata 404e02a8..404e031b. Semantic name remains unreviewed. */

undefined4 FUN_404e02a8(int param_1,ushort *param_2)

{
  undefined4 uVar1;
  LPCWSTR pWVar2;
  int iVar3;
  undefined *local_10 [2];
  
  if ((param_2 == (ushort *)0x0) ||
     ((*(int *)(param_1 + 4) != 0 &&
      ((pWVar2 = (LPCWSTR)FUN_404df914(param_2,(uint *)local_10,0), pWVar2 == (LPCWSTR)0x0 ||
       (iVar3 = FUN_404deeb0(pWVar2,local_10[0],(undefined4 *)0x0), *(int *)(param_1 + 8) != iVar3))
      )))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 404e031c FUN_404e031c */

/* Boundary evidence: original MIPS .pdata 404e031c..404e03db. Semantic name remains unreviewed. */

void FUN_404e031c(uint *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  LPCWSTR psz1;
  uint uVar2;
  
  psz1 = (LPCWSTR)param_1[1];
  if (psz1 == (LPCWSTR)0x0) {
    param_3[1] = param_2[1];
    param_3[2] = param_2[2];
    *param_3 = *param_2 & 0xff | *param_3;
  }
  else {
    param_3[1] = (uint)psz1;
    uVar2 = param_1[2];
    param_3[2] = uVar2;
    *param_3 = *param_1 & 0xff | *param_3;
    if ((((uVar2 != 0) && (uVar2 != param_2[2])) || (uVar2 == 9)) ||
       (((LPCWSTR)param_2[1] == (LPCWSTR)0x0 ||
        (iVar1 = StrCmpW(psz1,(LPCWSTR)param_2[1]), iVar1 != 0)))) {
      memset(param_2,0,0x28);
    }
  }
  return;
}



/* 404e03dc FUN_404e03dc */

/* Boundary evidence: original MIPS .pdata 404e03dc..404e0443. Semantic name remains unreviewed. */

void FUN_404e03dc(int param_1,void *param_2,int param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)((int)param_2 + 0xc);
  }
  else {
    *(int *)(param_3 + 0xc) = *(int *)(param_1 + 0xc);
    if ((*(LPCWSTR *)((int)param_2 + 0xc) != (LPCWSTR)0x0) &&
       (iVar1 = StrCmpW(*(LPCWSTR *)(param_1 + 0xc),*(LPCWSTR *)((int)param_2 + 0xc)), iVar1 != 0))
    {
      memset(param_2,0,0x28);
    }
  }
  return;
}



/* 404e0444 FUN_404e0444 */

/* Boundary evidence: original MIPS .pdata 404e0444..404e06ab. Semantic name remains unreviewed. */

void FUN_404e0444(uint *param_1,uint *param_2,uint *param_3)

{
  wchar_t *pwVar1;
  uint uVar2;
  
  if ((*param_1 & 0x100) == 0) {
    if ((*param_2 & 0x100) == 0) {
      if (param_1[5] == 0) {
        if (param_2[5] != 0) {
          param_3[4] = param_2[4];
          param_3[5] = param_2[5];
          *param_3 = *param_2 & 0xff00 | *param_3;
        }
      }
      else {
        param_3[4] = param_1[4];
        param_3[5] = param_1[5];
        *param_3 = *param_1 & 0xff00 | *param_3;
      }
    }
    else {
      param_3[4] = param_2[4];
      param_3[5] = param_2[5];
      uVar2 = *param_2 & 0xf00 | *param_3;
      *param_3 = uVar2;
      if ((param_1[5] == 0) && ((*param_1 & 0x400) == 0)) {
        *param_3 = *param_2 & 0xf000 | uVar2;
      }
      else {
        param_3[6] = param_1[4];
        param_3[7] = param_1[5];
        uVar2 = *param_3;
        *param_3 = *param_1 & 0xf000 | uVar2;
        if ((((*param_2 & 0x1000) == 0) &&
            (pwVar1 = FUN_404df294((wchar_t *)param_3[4],param_3[5],uVar2 & 0x200),
            pwVar1 != (wchar_t *)0x0)) &&
           (((*pwVar1 != L'.' || (pwVar1[1] != L'.')) || (pwVar1[2] != L'\0')))) {
          if ((*param_1 & 0x400) != 0) {
            *param_3 = *param_3 | 0x1000;
          }
          *pwVar1 = L'\b';
        }
      }
    }
  }
  else {
    if (((*param_2 & 0x200) == 0) || ((*param_1 & 0x200) != 0)) {
      param_3[4] = param_1[4];
      param_3[5] = param_1[5];
      *param_3 = *param_1 & 0xff00 | *param_3;
    }
    else {
      param_3[4] = param_2[4];
      param_3[5] = 1;
      uVar2 = *param_2 & 0xf00 | *param_3;
      *param_3 = uVar2;
      param_3[6] = param_1[4];
      param_3[7] = param_1[5];
      *param_3 = *param_1 & 0xf000 | uVar2;
    }
    memset(param_2,0,0x28);
  }
  if (param_1[5] != 0) {
    memset(param_2,0,0x28);
  }
  return;
}



/* 404e06ac FUN_404e06ac */

/* Boundary evidence: original MIPS .pdata 404e06ac..404e0713. Semantic name remains unreviewed. */

void FUN_404e06ac(int param_1,void *param_2,int param_3)

{
  int iVar1;
  LPCWSTR psz1;
  
  psz1 = *(LPCWSTR *)(param_1 + 0x20);
  if (psz1 == (LPCWSTR)0x0) {
    *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)((int)param_2 + 0x20);
  }
  else {
    *(LPCWSTR *)(param_3 + 0x20) = psz1;
    if ((*(LPCWSTR *)((int)param_2 + 0x20) != (LPCWSTR)0x0) &&
       (iVar1 = StrCmpW(psz1,*(LPCWSTR *)((int)param_2 + 0x20)), iVar1 != 0)) {
      memset(param_2,0,0x28);
    }
  }
  return;
}



/* 404e0714 FUN_404e0714 */

/* Boundary evidence: original MIPS .pdata 404e0714..404e0787. Semantic name remains unreviewed. */

void FUN_404e0714(int param_1,void *param_2,int param_3)

{
  int iVar1;
  LPCWSTR psz1;
  
  psz1 = *(LPCWSTR *)(param_1 + 0x24);
  if ((psz1 == (LPCWSTR)0x0) && (*(int *)(param_1 + 0x14) == 0)) {
    *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)((int)param_2 + 0x24);
  }
  else {
    *(LPCWSTR *)(param_3 + 0x24) = psz1;
    if ((*(LPCWSTR *)((int)param_2 + 0x24) != (LPCWSTR)0x0) &&
       (iVar1 = StrCmpW(psz1,*(LPCWSTR *)((int)param_2 + 0x24)), iVar1 != 0)) {
      memset(param_2,0,0x28);
    }
  }
  return;
}



/* 404e0788 FUN_404e0788 */

/* Boundary evidence: original MIPS .pdata 404e0788..404e081f. Semantic name remains unreviewed. */

void FUN_404e0788(uint *param_1,uint *param_2,uint *param_3)

{
  memset(param_3,0,0x28);
  FUN_404e031c(param_1,param_2,param_3);
  FUN_404e03dc((int)param_1,param_2,(int)param_3);
  FUN_404e0444(param_1,param_2,param_3);
  FUN_404e06ac((int)param_1,param_2,(int)param_3);
  FUN_404e0714((int)param_1,param_2,(int)param_3);
  return;
}



/* 404e0820 FUN_404e0820 */

/* Boundary evidence: original MIPS .pdata 404e0820..404e0943. Semantic name remains unreviewed. */

void FUN_404e0820(uint *param_1)

{
  LPWSTR pWVar1;
  LPWSTR pWVar2;
  int iVar3;
  wchar_t *psz2;
  uint uVar4;
  
  if (((LPCWSTR)param_1[3] != (LPCWSTR)0x0) && ((*param_1 & 2) != 0)) {
    pWVar1 = StrRChrW((LPCWSTR)param_1[3],(LPCWSTR)0x0,L'@');
    if (pWVar1 == (LPWSTR)0x0) {
      pWVar1 = (LPWSTR)param_1[3];
    }
    CharLowerW(pWVar1);
    pWVar2 = StrChrW(pWVar1,L'[');
    if ((pWVar2 == (LPWSTR)0x0) || (pWVar2 = StrChrW(pWVar2,L']'), pWVar2 == (LPWSTR)0x0)) {
      pWVar2 = pWVar1;
    }
    pWVar1 = StrChrW(pWVar2,L':');
    if ((pWVar1 != (LPWSTR)0x0) && (uVar4 = param_1[2], uVar4 != 0)) {
      if (uVar4 == 1) {
        psz2 = L":21";
      }
      else if (uVar4 == 2) {
        psz2 = L":80";
      }
      else if (uVar4 == 3) {
        psz2 = L":70";
      }
      else {
        if (uVar4 != 0xb) {
          return;
        }
        psz2 = L":443";
      }
      iVar3 = StrCmpW(pWVar1,psz2);
      if (iVar3 == 0) {
        *pWVar1 = L'\0';
      }
    }
  }
  return;
}



/* 404e0944 FUN_404e0944 */

/* Boundary evidence: original MIPS .pdata 404e0944..404e0a4b. Semantic name remains unreviewed. */

void FUN_404e0944(uint *param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  uint uVar3;
  uint local_28 [2];
  
  pwVar1 = FUN_404df294((wchar_t *)param_1[4],param_1[5],*param_1 & 0x200);
  pwVar2 = (wchar_t *)param_1[6];
  uVar3 = param_1[7];
  local_28[0] = 0;
  if ((pwVar2 == (wchar_t *)0x0) || (*pwVar2 == L'\b')) {
    pwVar2 = FUN_404df1d0(pwVar2,local_28,uVar3);
  }
  for (; (((pwVar2 != (wchar_t *)0x0 && (*pwVar2 == L'.')) && (pwVar2[1] == L'.')) &&
         (pwVar2[2] == L'\0')); pwVar2 = FUN_404df1d0(pwVar2,local_28,uVar3)) {
    if (pwVar1 != (wchar_t *)0x0) {
      *pwVar1 = L'\b';
    }
    *pwVar2 = L'\b';
    pwVar1 = FUN_404df294((wchar_t *)param_1[4],param_1[5],*param_1 & 0x200);
  }
  return;
}



/* 404e0a4c FUN_404e0a4c */

/* Boundary evidence: original MIPS .pdata 404e0a4c..404e0bc7. Semantic name remains unreviewed. */

void FUN_404e0a4c(wchar_t *param_1,uint param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  uint local_30 [2];
  
  local_30[0] = 0;
  pwVar4 = (wchar_t *)0x0;
  bVar1 = true;
  bVar2 = true;
  pwVar3 = FUN_404df344(param_1,local_30,param_2);
  do {
    if (pwVar3 == (wchar_t *)0x0) {
      return;
    }
    if (*pwVar3 == L'.') {
      if (pwVar3[1] != L'\0') {
        if (((((pwVar3[1] != L'.') || (pwVar3[2] != L'\0')) || (pwVar4 == (wchar_t *)0x0)) ||
            (((*pwVar4 == L'.' && (pwVar4[1] == L'.')) && (pwVar4[2] == L'\0')))) ||
           ((bVar1 && (param_3 != 0)))) goto LAB_404e0b3c;
        *pwVar4 = L'\b';
        pwVar4 = (wchar_t *)0x0;
      }
      *pwVar3 = L'\b';
    }
LAB_404e0b3c:
    if (*pwVar3 == L'\b') {
      pwVar4 = FUN_404df294(param_1,local_30[0],param_3);
    }
    else {
      if ((pwVar4 != (wchar_t *)0x0) || (bVar1 = true, !bVar2)) {
        bVar1 = false;
      }
      bVar2 = false;
      pwVar4 = pwVar3;
    }
    pwVar3 = FUN_404df1d0(pwVar3,local_30,param_2);
  } while( true );
}



/* 404e0bc8 FUN_404e0bc8 */

/* Boundary evidence: original MIPS .pdata 404e0bc8..404e0c2f. Semantic name remains unreviewed. */

void FUN_404e0bc8(uint *param_1)

{
  if (param_1[5] != 0) {
    FUN_404e0a4c((wchar_t *)param_1[4],param_1[5],*param_1 & 0x200);
  }
  if (param_1[7] != 0) {
    FUN_404e0a4c((wchar_t *)param_1[6],param_1[7],0);
  }
  if (param_1[7] != 0) {
    FUN_404e0944(param_1);
  }
  return;
}



/* 404e0c30 FUN_404e0c30 */

/* Boundary evidence: original MIPS .pdata 404e0c30..404e0c87. Semantic name remains unreviewed. */

int FUN_404e0c30(int param_1,undefined4 param_2,wchar_t *param_3)

{
  int iVar1;
  wchar_t local_10 [4];
  
  iVar1 = 0;
  if ((*(wchar_t **)(param_1 + 4) != (wchar_t *)0x0) &&
     (iVar1 = FUN_404f0e24(param_3,*(wchar_t **)(param_1 + 4),0xffffffff), -1 < iVar1)) {
    local_10[0] = L':';
    iVar1 = FUN_404f0e24(param_3,local_10,1);
  }
  return iVar1;
}



/* 404e0c88 FUN_404e0c88 */

/* Boundary evidence: original MIPS .pdata 404e0c88..404e0dcf. Semantic name remains unreviewed. */

int FUN_404e0c88(uint *param_1,uint param_2,wchar_t *param_3)

{
  int iVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  int iVar4;
  wchar_t local_18 [4];
  
  iVar4 = 0;
  if (param_1[2] == 9) {
    if (((param_2 & 0x80000000) == 0) && ((param_2 & 0x10000) == 0)) {
      if ((*param_1 & 0x100) == 0) goto LAB_404e0d90;
      pwVar2 = L"//";
      goto LAB_404e0d80;
    }
    if (((short *)param_1[3] != (short *)0x0) && (*(short *)param_1[3] != 0)) {
      pwVar2 = L"////";
      goto LAB_404e0d80;
    }
    if (((short *)param_1[4] == (short *)0x0) ||
       (iVar1 = FUN_404df390((short *)param_1[4]), iVar1 == 0)) {
      if ((*param_1 & 0x100) == 0) goto LAB_404e0d90;
      pwVar2 = L"//";
      goto LAB_404e0d80;
    }
    local_18[0] = L'/';
    sVar3 = 1;
    pwVar2 = local_18;
  }
  else {
    if ((param_1[2] == 10) || (param_1[3] == 0)) goto LAB_404e0d90;
    pwVar2 = L"//";
LAB_404e0d80:
    sVar3 = 0xffffffff;
  }
  iVar4 = FUN_404f0e24(param_3,pwVar2,sVar3);
LAB_404e0d90:
  if (((wchar_t *)param_1[3] != (wchar_t *)0x0) && (-1 < iVar4)) {
    iVar4 = FUN_404f0e24(param_3,(wchar_t *)param_1[3],0xffffffff);
  }
  return iVar4;
}



/* 404e0dd0 FUN_404e0dd0 */

/* Boundary evidence: original MIPS .pdata 404e0dd0..404e0f0f. Semantic name remains unreviewed. */

int FUN_404e0dd0(wchar_t *param_1,uint param_2,wchar_t *param_3,int param_4,undefined4 *param_5)

{
  wchar_t *pwVar1;
  int iVar2;
  wchar_t local_28 [2];
  uint local_24;
  
  local_24 = 0;
  *param_5 = 0;
  iVar2 = 1;
  pwVar1 = FUN_404df344(param_1,&local_24,param_2);
  if (param_4 == 0) {
    if (pwVar1 == (wchar_t *)0x0) {
      return 1;
    }
    iVar2 = FUN_404f0e24(param_3,pwVar1,0xffffffff);
    if (iVar2 < 0) {
      pwVar1 = (wchar_t *)0x0;
    }
    else {
      pwVar1 = FUN_404df1d0(pwVar1,&local_24,param_2);
    }
  }
  while( true ) {
    if (pwVar1 == (wchar_t *)0x0) {
      return iVar2;
    }
    local_28[0] = L'/';
    iVar2 = FUN_404f0e24(param_3,local_28,1);
    if ((iVar2 < 0) || (*pwVar1 == L'\0')) {
      *param_5 = 1;
    }
    else {
      iVar2 = FUN_404f0e24(param_3,pwVar1,0xffffffff);
      *param_5 = 0;
    }
    if (iVar2 < 0) break;
    pwVar1 = FUN_404df1d0(pwVar1,&local_24,param_2);
  }
  return iVar2;
}



/* 404e0f10 FUN_404e0f10 */

/* Boundary evidence: original MIPS .pdata 404e0f10..404e1093. Semantic name remains unreviewed. */

int FUN_404e0f10(uint *param_1,undefined4 param_2,wchar_t *param_3)

{
  wchar_t *pwVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  wchar_t local_28 [2];
  uint local_24;
  
  uVar2 = 0;
  local_24 = 0;
  iVar4 = 0;
  if (param_1[5] != 0) {
    iVar4 = FUN_404e0dd0((wchar_t *)param_1[4],param_1[5],param_3,*param_1 & 0x100,&local_24);
    uVar2 = local_24;
    if (local_24 != 0) {
      local_28[0] = L'/';
      FUN_404f0e24(param_3,local_28,1);
    }
    uVar3 = uVar2;
    if (iVar4 < 0) goto LAB_404e0ff8;
  }
  uVar3 = uVar2;
  if (param_1[7] != 0) {
    iVar4 = FUN_404e0dd0((wchar_t *)param_1[6],param_1[7],param_3,(uint)(uVar2 == 0),&local_24);
    uVar3 = local_24;
    if (local_24 != 0) {
      local_28[0] = L'/';
      FUN_404f0e24(param_3,local_28,1);
    }
    if (iVar4 == 1) {
      uVar3 = uVar2;
    }
  }
LAB_404e0ff8:
  if ((uVar3 == 0) &&
     (((*param_1 & 0x1000) != 0 ||
      (((pwVar1 = FUN_404df344((wchar_t *)param_1[4],&local_24,param_1[5]), pwVar1 == (wchar_t *)0x0
        && (pwVar1 = FUN_404df344((wchar_t *)param_1[6],&local_24,param_1[7]),
           pwVar1 == (wchar_t *)0x0)) && ((*param_1 & 0x100) != 0)))))) {
    local_28[0] = L'/';
    iVar4 = FUN_404f0e24(param_3,local_28,1);
  }
  return iVar4;
}



/* 404e1094 FUN_404e1094 */

/* Boundary evidence: original MIPS .pdata 404e1094..404e10fb. Semantic name remains unreviewed. */

int FUN_404e1094(int param_1,undefined4 param_2,wchar_t *param_3)

{
  int iVar1;
  wchar_t local_18 [4];
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    local_18[0] = L'?';
    iVar1 = FUN_404f0e24(param_3,local_18,1);
    if (-1 < iVar1) {
      iVar1 = FUN_404f0e24(param_3,*(wchar_t **)(param_1 + 0x20),0xffffffff);
    }
  }
  return iVar1;
}



/* 404e10fc FUN_404e10fc */

/* Boundary evidence: original MIPS .pdata 404e10fc..404e1163. Semantic name remains unreviewed. */

int FUN_404e10fc(int param_1,undefined4 param_2,wchar_t *param_3)

{
  int iVar1;
  wchar_t local_18 [4];
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x24) != 0) {
    local_18[0] = L'#';
    iVar1 = FUN_404f0e24(param_3,local_18,1);
    if (-1 < iVar1) {
      iVar1 = FUN_404f0e24(param_3,*(wchar_t **)(param_1 + 0x24),0xffffffff);
    }
  }
  return iVar1;
}



/* 404e1164 FUN_404e1164 */

/* Boundary evidence: original MIPS .pdata 404e1164..404e120b. Semantic name remains unreviewed. */

void FUN_404e1164(uint *param_1,uint param_2,wchar_t *param_3)

{
  int iVar1;
  
  iVar1 = FUN_404e0c30((int)param_1,param_2,param_3);
  if ((((-1 < iVar1) && (iVar1 = FUN_404e0c88(param_1,param_2,param_3), -1 < iVar1)) &&
      (iVar1 = FUN_404e0f10(param_1,param_2,param_3), -1 < iVar1)) &&
     (iVar1 = FUN_404e1094((int)param_1,param_2,param_3), -1 < iVar1)) {
    FUN_404e10fc((int)param_1,param_2,param_3);
  }
  return;
}



/* 404e120c FUN_404e120c */

/* Boundary evidence: original MIPS .pdata 404e120c..404e13ab. Semantic name remains unreviewed. */

int FUN_404e120c(wchar_t *param_1,wchar_t *param_2,uint param_3)

{
  size_t sVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  int iVar4;
  STRSAFE_LPWSTR pszDest;
  
  iVar4 = 0;
  FUN_404f0b04(param_2);
  wVar3 = *param_1;
  pwVar2 = param_1;
  if (wVar3 != L'\0') {
    do {
      if (wVar3 == L' ') {
        iVar4 = iVar4 + 1;
      }
      wVar3 = pwVar2[1];
      pwVar2 = pwVar2 + 1;
    } while (wVar3 != L'\0');
    if (iVar4 != 0) {
      sVar1 = wcslen(param_1);
      iVar4 = FUN_404f0b58(param_2,iVar4 * 2 + sVar1 + 1);
      if (iVar4 < 0) {
        return iVar4;
      }
      pszDest = *(STRSAFE_LPWSTR *)(param_2 + 0x42);
      if (pszDest == (STRSAFE_LPWSTR)0x0) {
        sVar1 = 0;
      }
      else {
        sVar1 = *(size_t *)(param_2 + 0x44);
      }
      do {
        if (*param_1 == L'\0') {
LAB_404e1368:
          *pszDest = L'\0';
          return iVar4;
        }
        wVar3 = *param_1;
        if (((wVar3 == L'#') || (wVar3 == L'?')) && ((param_3 & 0x2000000) != 0)) {
          StringCchCopyW(pszDest,sVar1,param_1);
          sVar1 = wcslen(pszDest);
          pszDest = pszDest + sVar1;
          goto LAB_404e1368;
        }
        if (wVar3 == L' ') {
          *pszDest = L'%';
          pszDest[1] = L'2';
          pszDest[2] = L'0';
          pszDest = pszDest + 3;
          sVar1 = sVar1 - 3;
        }
        else {
          *pszDest = wVar3;
          pszDest = pszDest + 1;
          sVar1 = sVar1 - 1;
        }
        param_1 = param_1 + 1;
      } while( true );
    }
  }
  iVar4 = FUN_404f0dd4(param_2,param_1,0xffffffff);
  return iVar4;
}



/* 404e13ac FUN_404e13ac */

undefined4 FUN_404e13ac(ushort *param_1,uint param_2,int *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  *param_3 = 0;
  uVar2 = 0;
  uVar1 = *param_1;
  while (uVar1 != 0) {
    iVar3 = *param_3;
    *param_3 = iVar3 + 1;
    uVar4 = (uint)*param_1;
    if (((uVar4 < 0x100) &&
        (((uVar4 < 0x20 || (0x7f < uVar4)) ||
         ((*(ushort *)(&DAT_404d2f0c + (uVar4 - 0x20) * 2) & 9) == 0)))) ||
       (((param_2 & 0x1000) != 0 && (uVar4 == 0x25)))) {
      *param_3 = iVar3 + 3;
      uVar2 = 1;
    }
    param_1 = param_1 + 1;
    uVar1 = *param_1;
  }
  *param_3 = *param_3 + 1;
  return uVar2;
}



/* 404e1460 FUN_404e1460 */

/* Boundary evidence: original MIPS .pdata 404e1460..404e1523. Semantic name remains unreviewed. */

int FUN_404e1460(wchar_t *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  wchar_t *pwVar2;
  int iVar3;
  int iVar4;
  int local_20;
  uint uStack_1c;
  
  iVar4 = 0;
  bVar1 = false;
  pwVar2 = FUN_404df344(param_1,&uStack_1c,param_2);
  if (pwVar2 != (wchar_t *)0x0) {
    do {
      if (*pwVar2 == L'\b') break;
      iVar3 = FUN_404e13ac((ushort *)pwVar2,param_3,&local_20);
      if (iVar3 != 0) {
        bVar1 = true;
      }
      iVar4 = local_20 + iVar4;
      pwVar2 = FUN_404df1d0(pwVar2,&uStack_1c,param_2);
    } while (pwVar2 != (wchar_t *)0x0);
    if (bVar1) {
      return iVar4;
    }
  }
  return 0;
}



/* 404e1524 FUN_404e1524 */

void FUN_404e1524(wchar_t *param_1,uint param_2,undefined4 *param_3)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  uint uVar3;
  
  pwVar2 = (wchar_t *)*param_3;
  wVar1 = *param_1;
  while (wVar1 != L'\0') {
    wVar1 = *param_1;
    uVar3 = (uint)(ushort)wVar1;
    if (((uVar3 < 0x100) &&
        (((uVar3 < 0x20 || (0x7f < uVar3)) ||
         ((*(ushort *)(&DAT_404d2f0c + (uVar3 - 0x20) * 2) & 9) == 0)))) ||
       (((param_2 & 0x1000) != 0 && (uVar3 == 0x25)))) {
      *pwVar2 = L'%';
      pwVar2[1] = L"0123456789ABCDEF"[(ushort)wVar1 >> 4 & 0xf];
      pwVar2 = pwVar2 + 2;
      *pwVar2 = L"0123456789ABCDEF"[uVar3 & 0xf];
    }
    else {
      *pwVar2 = wVar1;
    }
    param_1 = param_1 + 1;
    pwVar2 = pwVar2 + 1;
    wVar1 = *param_1;
  }
  *pwVar2 = L'\0';
  *param_3 = pwVar2 + 1;
  return;
}



/* 404e15fc FUN_404e15fc */

/* Boundary evidence: original MIPS .pdata 404e15fc..404e170b. Semantic name remains unreviewed. */

int FUN_404e15fc(wchar_t *param_1,uint param_2,uint param_3,int param_4,wchar_t *param_5)

{
  uint uVar1;
  wchar_t *pwVar2;
  int iVar3;
  undefined4 local_28;
  uint uStack_24;
  
  iVar3 = 0;
  uVar1 = FUN_404e1460(param_1,param_2,param_3);
  if (uVar1 == 0) {
    *(uint *)(param_4 + 0x14) = param_2;
    *(wchar_t **)(param_4 + 0x10) = param_1;
  }
  else {
    iVar3 = FUN_404f0b58(param_5,uVar1);
    if (-1 < iVar3) {
      local_28 = *(undefined4 *)(param_5 + 0x42);
      *(undefined4 *)(param_4 + 0x10) = local_28;
      *(undefined4 *)(param_4 + 0x14) = 0;
      for (pwVar2 = FUN_404df344(param_1,&uStack_24,param_2);
          (pwVar2 != (wchar_t *)0x0 && (*pwVar2 != L'\b'));
          pwVar2 = FUN_404df1d0(pwVar2,&uStack_24,param_2)) {
        FUN_404e1524(pwVar2,param_3,&local_28);
        *(int *)(param_4 + 0x14) = *(int *)(param_4 + 0x14) + 1;
      }
    }
  }
  return iVar3;
}



/* 404e170c FUN_404e170c */

uint FUN_404e170c(uint param_1)

{
  int iVar1;
  
  if ((param_1 < 0x30) || (0x39 < param_1)) {
    if ((param_1 < 0x41) || (0x46 < param_1)) {
      if ((param_1 < 0x61) || (0x66 < param_1)) {
        return 0xffff;
      }
      iVar1 = 0xffa9;
    }
    else {
      iVar1 = 0xffc9;
    }
  }
  else {
    iVar1 = 0xffd0;
  }
  return param_1 + iVar1 & 0xffff;
}



/* 404e1784 FUN_404e1784 */

undefined4 FUN_404e1784(short *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((((*param_1 != 0x25) || (uVar2 = (uint)(ushort)param_1[1], uVar2 < 0x20)) || (0x7f < uVar2))
     || ((((*(ushort *)(&DAT_404d2f0c + (uVar2 - 0x20) * 2) & 2) == 0 ||
          (uVar2 = (uint)(ushort)param_1[2], uVar2 < 0x20)) ||
         ((0x7f < uVar2 || (uVar1 = 1, (*(ushort *)(&DAT_404d2f0c + (uVar2 - 0x20) * 2) & 2) == 0)))
         ))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 404e1820 FUN_404e1820 */

undefined4 FUN_404e1820(char *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((((*param_1 != '%') || (uVar2 = (int)param_1[1] & 0xffff, uVar2 < 0x20)) || (0x7f < uVar2)) ||
     ((((*(ushort *)(&DAT_404d2f0c + (uVar2 - 0x20) * 2) & 2) == 0 ||
       (uVar2 = (int)param_1[2] & 0xffff, uVar2 < 0x20)) ||
      ((0x7f < uVar2 || (uVar1 = 1, (*(ushort *)(&DAT_404d2f0c + (uVar2 - 0x20) * 2) & 2) == 0))))))
  {
    uVar1 = 0;
  }
  return uVar1;
}



/* 404e18c4 FUN_404e18c4 */

/* Boundary evidence: original MIPS .pdata 404e18c4..404e19e7. Semantic name remains unreviewed. */

undefined4 FUN_404e18c4(char *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  while( true ) {
    if (*param_1 == '\0') {
      *pcVar5 = '\0';
      return 0;
    }
    cVar1 = *param_1;
    if (((cVar1 == '#') || (cVar1 == '?')) && ((param_2 & 0x2000000) != 0)) break;
    iVar2 = FUN_404e1820(param_1);
    if (iVar2 == 0) {
      *pcVar5 = cVar1;
      param_1 = param_1 + 1;
    }
    else {
      cVar1 = param_1[1];
      uVar3 = FUN_404e170c((int)param_1[2] & 0xffff);
      uVar4 = FUN_404e170c((int)cVar1 & 0xffff);
      iVar2 = (uVar3 + uVar4 * 0x10) * 0x1000000;
      if (iVar2 >> 0x18 == 0) {
        return 0x80004005;
      }
      *pcVar5 = (char)((uint)iVar2 >> 0x18);
      param_1 = param_1 + 3;
    }
    pcVar5 = pcVar5 + 1;
  }
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  return 0;
}



/* 404e19e8 FUN_404e19e8 */

/* Boundary evidence: original MIPS .pdata 404e19e8..404e1aff. Semantic name remains unreviewed. */

undefined4 FUN_404e19e8(short *param_1,uint param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  
  psVar6 = param_1;
  while( true ) {
    if (*param_1 == 0) {
      *psVar6 = 0;
      return 0;
    }
    sVar1 = *param_1;
    if (((sVar1 == 0x23) || (sVar1 == 0x3f)) && ((param_2 & 0x2000000) != 0)) break;
    iVar3 = FUN_404e1784(param_1);
    if (iVar3 == 0) {
      *psVar6 = sVar1;
      param_1 = param_1 + 1;
    }
    else {
      uVar2 = param_1[1];
      uVar4 = FUN_404e170c((uint)(ushort)param_1[2]);
      uVar5 = FUN_404e170c((uint)uVar2);
      uVar4 = uVar4 + uVar5 * 0x10;
      if ((uVar4 & 0xffff) == 0) {
        return 0x80004005;
      }
      *psVar6 = (short)uVar4;
      param_1 = param_1 + 3;
    }
    psVar6 = psVar6 + 1;
  }
  do {
    sVar1 = *param_1;
    param_1 = param_1 + 1;
    *psVar6 = sVar1;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  return 0;
}



/* 404e1b00 FUN_404e1b00 */

/* Boundary evidence: original MIPS .pdata 404e1b00..404e1c87. Semantic name remains unreviewed. */

int FUN_404e1b00(uint *param_1,wchar_t *param_2,uint param_3)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  if (((short *)param_1[4] != (short *)0x0) &&
     (iVar2 = FUN_404df390((short *)param_1[4]), iVar2 != 0)) {
    *param_1 = *param_1 & 0xfffffeff;
  }
  if (((short *)param_1[3] != (short *)0x0) && (*(short *)param_1[3] == 0)) {
    param_1[3] = 0;
  }
  param_1[2] = 0;
  iVar2 = FUN_404e0c88(param_1,param_3,param_2);
  if ((-1 < iVar2) &&
     ((param_1[5] == 0 || (iVar2 = FUN_404e0f10(param_1,param_3,param_2), -1 < iVar2)))) {
    if ((param_3 & 0x10000) == 0x10000) {
      FUN_404df3dc(*(wchar_t **)(param_2 + 0x42));
    }
    else {
      for (psVar3 = *(short **)(param_2 + 0x42);
          ((*psVar3 != 0 && (sVar1 = *psVar3, sVar1 != 0x3f)) && (sVar1 != 0x23));
          psVar3 = psVar3 + 1) {
        if (sVar1 == 0x2f) {
          *psVar3 = 0x5c;
        }
      }
    }
    if ((*param_1 & 0x10000000) != 0x10000000) {
      FUN_404e19e8(*(short **)(param_2 + 0x42),param_3);
    }
    psVar3 = *(short **)(param_2 + 0x42);
    if ((*psVar3 != 0) && (psVar3[1] == 0x7c)) {
      psVar3[1] = 0x3a;
    }
  }
  return iVar2;
}



/* 404e1c88 FUN_404e1c88 */

/* Boundary evidence: original MIPS .pdata 404e1c88..404e1f5f. Semantic name remains unreviewed. */

int FUN_404e1c88(LPCWSTR param_1,wchar_t *param_2,uint param_3)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  wchar_t *local_230 [2];
  uint local_228 [2];
  int local_220;
  wchar_t *local_21c;
  undefined4 local_218;
  undefined4 local_214;
  uint local_200;
  undefined2 *local_1fc;
  undefined4 local_1f8;
  wchar_t *local_1f0;
  uint local_1ec;
  wchar_t awStack_1d8 [66];
  wchar_t *local_154;
  wchar_t awStack_148 [66];
  wchar_t *local_c4;
  wchar_t awStack_b8 [70];
  uint local_2c;
  
  local_2c = DAT_404f4224;
  FUN_404f0aec(awStack_1d8);
  BVar1 = PathIsURLW(param_1);
  if (BVar1 != 0) {
    iVar2 = FUN_404f0dd4(param_2,param_1,0xffffffff);
    if (-1 < iVar2) {
      iVar2 = 1;
    }
    goto LAB_404e1f1c;
  }
  FUN_404f0b04(param_2);
  iVar2 = FUN_404f0dd4(awStack_1d8,param_1,0xffffffff);
  FUN_404df46c((ushort *)local_154);
  if (iVar2 < 0) goto LAB_404e1f1c;
  FUN_404f0aec(awStack_b8);
  FUN_404f0aec(awStack_148);
  local_230[0] = local_154;
  memset(&local_200,0,0x28);
  local_1fc = &DAT_404d2ffc;
  local_1f8 = 9;
  local_200 = 8;
  FUN_404df7c4(local_230,&local_200);
  FUN_404e0024((uint *)local_230,&local_200,1);
  FUN_404e021c((int *)local_230,&local_200);
  memcpy(local_228,&local_200,0x28);
  pwVar4 = local_21c;
  if ((param_3 & 0x10000) == 0x10000) {
LAB_404e1e60:
    if (pwVar4 == (wchar_t *)0x0) goto LAB_404e1e68;
  }
  else {
    iVar2 = 0;
    if (local_1ec == 0) {
      local_214 = 0;
      local_218 = 0;
    }
    else {
      iVar2 = FUN_404e15fc(local_1f0,local_1ec,param_3 | 0x1000,(int)local_228,awStack_b8);
    }
    pwVar4 = local_21c;
    if (iVar2 < 0) goto LAB_404e1e60;
    if (local_21c != (wchar_t *)0x0) {
      iVar3 = FUN_404e13ac((ushort *)local_21c,param_3 | 0x1000,(int *)local_230);
      if ((iVar3 != 0) && (iVar2 = FUN_404f0b58(awStack_148,(uint)local_230[0]), -1 < iVar2)) {
        local_230[0] = local_c4;
        FUN_404e1524(pwVar4,param_3 | 0x1000,local_230);
        local_21c = local_c4;
        pwVar4 = local_c4;
      }
      goto LAB_404e1e60;
    }
LAB_404e1e68:
    if ((local_228[0] & 0x100) == 0x100) {
      local_21c = L"";
    }
  }
  if (-1 < iVar2) {
    if ((local_220 == 9) && ((param_3 & 0x10000) == 0x10000)) {
      iVar2 = FUN_404f0dd4(param_2,L"file://",0xffffffff);
      if (iVar2 < 0) goto LAB_404e1f0c;
      iVar2 = FUN_404e1b00(local_228,param_2,param_3);
    }
    else {
      iVar2 = FUN_404e1164(local_228,param_3,param_2);
    }
    if ((-1 < iVar2) && ((param_3 & 0x80000000) == 0x80000000)) {
      FUN_404df3dc(*(wchar_t **)(param_2 + 0x42));
    }
  }
LAB_404e1f0c:
  FUN_404f0b04(awStack_148);
  FUN_404f0b04(awStack_b8);
LAB_404e1f1c:
  FUN_404f0b04(awStack_1d8);
  FUN_404f1430(local_2c);
  return iVar2;
}



/* 404e1f60 FUN_404e1f60 */

/* Boundary evidence: original MIPS .pdata 404e1f60..404e201f. Semantic name remains unreviewed. */

void FUN_404e1f60(LPCWSTR param_1,undefined4 *param_2)

{
  LPWSTR pWVar1;
  
  pWVar1 = StrChrW(param_1,L'@');
  if (pWVar1 == (LPWSTR)0x0) {
    param_2[2] = param_1;
  }
  else {
    *pWVar1 = L'\0';
    param_2[2] = pWVar1 + 1;
    *param_2 = param_1;
    pWVar1 = StrChrW(param_1,L':');
    if (pWVar1 != (LPWSTR)0x0) {
      *pWVar1 = L'\0';
      param_2[1] = pWVar1 + 1;
    }
  }
  pWVar1 = StrChrW((LPCWSTR)param_2[2],L'[');
  if ((pWVar1 == (LPWSTR)0x0) || (pWVar1 = StrChrW(pWVar1,L']'), pWVar1 == (LPWSTR)0x0)) {
    pWVar1 = (LPWSTR)param_2[2];
  }
  pWVar1 = StrChrW(pWVar1,L':');
  if (pWVar1 != (LPWSTR)0x0) {
    *pWVar1 = L'\0';
    param_2[3] = pWVar1 + 1;
  }
  return;
}



/* 404e2020 FUN_404e2020 */

/* Boundary evidence: original MIPS .pdata 404e2020..404e20eb. Semantic name remains unreviewed. */

undefined4 FUN_404e2020(int param_1,int param_2,wchar_t *param_3)

{
  undefined4 uVar1;
  LPCWSTR pWVar2;
  wchar_t *local_28;
  wchar_t *local_24;
  wchar_t *local_20;
  wchar_t *local_1c;
  
  pWVar2 = *(LPCWSTR *)(param_2 + 0xc);
  uVar1 = 0x80004005;
  if (pWVar2 != (LPCWSTR)0x0) {
    local_28 = (wchar_t *)0x0;
    memset(&local_24,0,0xc);
    FUN_404e1f60(pWVar2,&local_28);
    if ((((param_1 == 2) || (local_20 = local_28, param_1 == 3)) ||
        (local_20 = local_24, param_1 == 4)) || (local_20 = local_1c, param_1 == 5)) {
      uVar1 = FUN_404f0e24(param_3,local_20,0xffffffff);
    }
  }
  return uVar1;
}



/* 404e20ec FUN_404e20ec */

/* Boundary evidence: original MIPS .pdata 404e20ec..404e2307. Semantic name remains unreviewed. */

int FUN_404e20ec(LPCWSTR param_1,wchar_t *param_2)

{
  LSTATUS LVar1;
  int iVar2;
  int iVar3;
  DWORD dwIndex;
  DWORD local_450;
  DWORD local_44c;
  HKEY local_448;
  DWORD DStack_444;
  BYTE aBStack_440 [264];
  CHAR aCStack_338 [264];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_404f4224;
  iVar3 = 1;
  LVar1 = RegOpenKeyExA((HKEY)0x80000002,
                        "Software\\Microsoft\\Windows\\CurrentVersion\\URL\\Prefixes",0,1,&local_448
                       );
  if (LVar1 == 0) {
    local_450 = 0x104;
    local_44c = 0x104;
    if ((*param_1 == L'/') && (param_1[1] == L'/')) {
      param_1 = param_1 + 2;
    }
    dwIndex = 0;
    iVar2 = RegEnumValueA(local_448,0,aCStack_338,&local_450,(LPDWORD)0x0,&DStack_444,aBStack_440,
                          &local_44c);
    while (iVar2 == 0) {
      MultiByteToWideChar(0,0,aCStack_338,-1,aWStack_230,0x104);
      iVar2 = StrCmpNIW(param_1,aWStack_230,local_450);
      if ((iVar2 == 0) && (param_1[local_450] != L'\0')) {
        MultiByteToWideChar(0,0,(LPCSTR)aBStack_440,-1,aWStack_230,0x104);
        iVar3 = FUN_404f0dd4(param_2,aWStack_230,0xffffffff);
        if (-1 < iVar3) {
          iVar3 = FUN_404f0e24(param_2,param_1,0xffffffff);
        }
        break;
      }
      dwIndex = dwIndex + 1;
      local_450 = 0x104;
      local_44c = 0x104;
      iVar2 = RegEnumValueA(local_448,dwIndex,aCStack_338,&local_450,(LPDWORD)0x0,&DStack_444,
                            aBStack_440,&local_44c);
    }
    RegCloseKey(local_448);
  }
  FUN_404f1430(local_28);
  return iVar3;
}



/* 404e2308 FUN_404e2308 */

/* Boundary evidence: original MIPS .pdata 404e2308..404e23eb. Semantic name remains unreviewed. */

int FUN_404e2308(wchar_t *param_1,wchar_t *param_2)

{
  LSTATUS LVar1;
  int iVar2;
  DWORD local_228;
  DWORD DStack_224;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_404f4224;
  local_228 = 0x208;
  iVar2 = 1;
  LVar1 = SHRegGetUSValueW(L"Software\\Microsoft\\Windows\\CurrentVersion\\URL\\DefaultPrefix",
                           (LPCWSTR)0x0,&DStack_224,awStack_220,&local_228,1,L"http://",0x10);
  if (LVar1 == 0) {
    if ((*param_1 == L'/') && (param_1[1] == L'/')) {
      param_1 = param_1 + 2;
    }
    iVar2 = FUN_404f0dd4(param_2,awStack_220,0xffffffff);
    if (-1 < iVar2) {
      iVar2 = FUN_404f0e24(param_2,param_1,0xffffffff);
    }
  }
  FUN_404f1430(local_18);
  return iVar2;
}



/* 404e23ec FUN_404e23ec */

/* Boundary evidence: original MIPS .pdata 404e23ec..404e24db. Semantic name remains unreviewed. */

int FUN_404e23ec(LPCWSTR param_1,wchar_t *param_2,uint param_3)

{
  ushort *puVar1;
  LPCWSTR pWVar2;
  int iVar3;
  int iVar4;
  uint auStack_20 [2];
  
  iVar4 = 1;
  if ((((param_3 & 8) != 0) ||
      (puVar1 = FUN_404df914((ushort *)param_1,auStack_20,0), puVar1 == (ushort *)0x0)) &&
     (((param_3 & 2) == 0 || (iVar4 = FUN_404e20ec(param_1,param_2), iVar4 != 0)))) {
    if ((((param_3 & 4) != 0) && (pWVar2 = FUN_404dfa2c(param_1), pWVar2 != (LPCWSTR)0x0)) &&
       (iVar3 = FUN_404e1c88(pWVar2,param_2,0), -1 < iVar3)) {
      iVar4 = 0;
    }
    if ((iVar4 != 0) && (((param_3 & 1) != 0 || (param_3 == 0)))) {
      iVar4 = FUN_404e2308(param_1,param_2);
    }
  }
  return iVar4;
}



/* 404e24dc FUN_404e24dc */

/* Boundary evidence: original MIPS .pdata 404e24dc..404e256f. Semantic name remains unreviewed. */

void FUN_404e24dc(int param_1,STRSAFE_LPSTR param_2,uint *param_3)

{
  size_t sVar1;
  int iVar2;
  char *_Str;
  
  _Str = *(char **)(param_1 + 0x44);
  sVar1 = strlen(_Str);
  if ((sVar1 < *param_3) && (param_2 != (STRSAFE_LPSTR)0x0)) {
    iVar2 = StringCchCopyA(param_2,*param_3,_Str);
  }
  else {
    iVar2 = -0x7fffbffd;
  }
  *param_3 = (iVar2 < 0) + sVar1;
  return;
}



/* 404e2570 FUN_404e2570 */

/* Boundary evidence: original MIPS .pdata 404e2570..404e2603. Semantic name remains unreviewed. */

void FUN_404e2570(wchar_t *param_1,STRSAFE_LPWSTR param_2,uint *param_3)

{
  size_t sVar1;
  int iVar2;
  
  sVar1 = wcslen(param_1);
  if ((sVar1 < *param_3) && (param_2 != (STRSAFE_LPWSTR)0x0)) {
    iVar2 = StringCchCopyW(param_2,*param_3,param_1);
  }
  else {
    iVar2 = -0x7fffbffd;
  }
  *param_3 = (iVar2 < 0) + sVar1;
  return;
}



/* 404e2604 FUN_404e2604 */

/* Boundary evidence: original MIPS .pdata 404e2604..404e269f. Semantic name remains unreviewed. */

undefined4 FUN_404e2604(int param_1,STRSAFE_LPWSTR param_2,uint *param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *_Str;
  
  _Str = *(wchar_t **)(param_1 + 0x84);
  uVar3 = 0;
  sVar1 = wcslen(_Str);
  if ((sVar1 < *param_3) && (param_2 != (STRSAFE_LPWSTR)0x0)) {
    StringCchCopyW(param_2,*param_3,_Str);
    iVar2 = 0;
  }
  else {
    uVar3 = 0x80004003;
    iVar2 = 1;
  }
  *param_3 = iVar2 + sVar1;
  return uVar3;
}



/* 404e26a0 UrlGetLocationA */

/* Boundary evidence: original MIPS .pdata 404e26a0..404e278f. Semantic name remains unreviewed. */

LPCSTR UrlGetLocationA(LPCSTR psz1)

{
  BOOL BVar1;
  char *pcVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  uint local_30 [2];
  _cpinfo _Stack_28;
  uint local_14;
  
                    /* 0x126a0  98  UrlGetLocationA */
  local_14 = DAT_404f4224;
  BVar1 = GetCPInfo(0,&_Stack_28);
  if ((BVar1 == 0) || (iVar5 = 1, _Stack_28.LeadByte[0] == '\0')) {
    iVar5 = 0;
  }
  if ((psz1 == (LPCSTR)0x0) || (pcVar2 = FUN_404df830(psz1,local_30), pcVar2 == (char *)0x0)) {
    FUN_404f1430(local_14);
    puVar4 = (ushort *)0x0;
  }
  else {
    iVar3 = FUN_404defc8(pcVar2,local_30[0],local_30);
    if ((local_30[0] & 1) == 0) {
      puVar4 = FUN_404df660((ushort *)psz1,iVar5,(uint)(iVar3 == 9));
    }
    else {
      puVar4 = (ushort *)0x0;
    }
    FUN_404f1430(local_14);
  }
  return (LPCSTR)puVar4;
}



/* 404e2790 UrlGetLocationW */

/* Boundary evidence: original MIPS .pdata 404e2790..404e2813. Semantic name remains unreviewed. */

LPCWSTR UrlGetLocationW(LPCWSTR psz1)

{
  LPCWSTR pWVar1;
  int iVar2;
  LPWSTR pWVar3;
  undefined *local_10 [2];
  
                    /* 0x12790  99  UrlGetLocationW */
  if (((psz1 == (LPCWSTR)0x0) ||
      (pWVar1 = (LPCWSTR)FUN_404df914((ushort *)psz1,(uint *)local_10,0), pWVar1 == (LPCWSTR)0x0))
     || (iVar2 = FUN_404deeb0(pWVar1,local_10[0],local_10), ((uint)local_10[0] & 1) != 0)) {
    pWVar3 = (LPWSTR)0x0;
  }
  else {
    pWVar3 = FUN_404df71c(psz1,(uint)(iVar2 == 9));
  }
  return pWVar3;
}



/* 404e2814 UrlUnescapeA */

/* Boundary evidence: original MIPS .pdata 404e2814..404e291b. Semantic name remains unreviewed. */

HRESULT UrlUnescapeA(LPSTR pszUrl,LPSTR pszUnescaped,LPDWORD pcchUnescaped,DWORD dwFlags)

{
  int iVar1;
  char acStack_68 [68];
  char *local_24;
  uint local_1c;
  
                    /* 0x12814  104  UrlUnescapeA */
  local_1c = DAT_404f4224;
  if ((dwFlags & 0x100000) == 0) {
    if ((((pszUrl == (LPSTR)0x0) || (pcchUnescaped == (LPDWORD)0x0)) || (*pcchUnescaped == 0)) ||
       (pszUnescaped == (LPSTR)0x0)) {
      FUN_404f1430(DAT_404f4224);
      return -0x7ff8ffa9;
    }
    FUN_404f077c(acStack_68);
    iVar1 = FUN_404f0a5c(acStack_68,pszUrl);
    if (-1 < iVar1) {
      FUN_404e18c4(local_24,dwFlags);
      iVar1 = FUN_404e24dc((int)acStack_68,pszUnescaped,pcchUnescaped);
    }
    FUN_404f0794(acStack_68);
  }
  else {
    iVar1 = FUN_404e18c4(pszUrl,dwFlags);
  }
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e291c UrlCompareW */

/* Boundary evidence: original MIPS .pdata 404e291c..404e2a83. Semantic name remains unreviewed. */

int UrlCompareW(LPCWSTR psz1,LPCWSTR psz2,BOOL fIgnoreSlash)

{
  wchar_t *pwVar1;
  int iVar2;
  size_t sVar3;
  LPCWSTR psz2_00;
  wchar_t awStack_130 [66];
  LPCWSTR local_ac;
  wchar_t awStack_a0 [66];
  wchar_t *local_1c;
  uint local_14;
  
                    /* 0x1291c  95  UrlCompareW */
  local_14 = DAT_404f4224;
  if ((psz1 != (LPCWSTR)0x0) && (psz2 != (LPCWSTR)0x0)) {
    FUN_404f0aec(awStack_a0);
    FUN_404f0aec(awStack_130);
    iVar2 = FUN_404f0dd4(awStack_a0,psz1,0xffffffff);
    if ((-1 < iVar2) &&
       (((iVar2 = FUN_404f0dd4(awStack_130,psz2,0xffffffff), -1 < iVar2 &&
         (iVar2 = FUN_404e19e8(local_1c,0), -1 < iVar2)) &&
        (iVar2 = FUN_404e19e8(local_ac,0), pwVar1 = local_1c, -1 < iVar2)))) {
      psz2_00 = local_ac;
      if (fIgnoreSlash != 0) {
        sVar3 = wcslen(local_1c);
        psz2_00 = local_ac;
        if (pwVar1[sVar3 - 1] == L'/') {
          pwVar1[sVar3 - 1] = L'\0';
        }
        sVar3 = wcslen(local_ac);
        if (psz2_00[sVar3 - 1] == L'/') {
          psz2_00[sVar3 - 1] = L'\0';
          psz2_00 = local_ac;
        }
      }
      iVar2 = StrCmpW(local_1c,psz2_00);
      FUN_404f0b04(awStack_130);
      FUN_404f0b04(awStack_a0);
      goto LAB_404e2a60;
    }
    FUN_404f0b04(awStack_130);
    FUN_404f0b04(awStack_a0);
  }
  iVar2 = StrCmpW(psz1,psz2);
LAB_404e2a60:
  FUN_404f1430(local_14);
  return iVar2;
}



/* 404e2a84 UrlUnescapeW */

/* Boundary evidence: original MIPS .pdata 404e2a84..404e2b8f. Semantic name remains unreviewed. */

HRESULT UrlUnescapeW(LPWSTR pszUrl,LPWSTR pszUnescaped,LPDWORD pcchUnescaped,DWORD dwFlags)

{
  int iVar1;
  wchar_t awStack_a8 [66];
  short *local_24;
  uint local_1c;
  
                    /* 0x12a84  105  UrlUnescapeW */
  local_1c = DAT_404f4224;
  if ((dwFlags & 0x100000) == 0) {
    if ((((pszUrl == (LPWSTR)0x0) || (pcchUnescaped == (LPDWORD)0x0)) || (*pcchUnescaped == 0)) ||
       (pszUnescaped == (LPWSTR)0x0)) {
      FUN_404f1430(DAT_404f4224);
      return -0x7ff8ffa9;
    }
    FUN_404f0aec(awStack_a8);
    iVar1 = FUN_404f0dd4(awStack_a8,pszUrl,0xffffffff);
    if (-1 < iVar1) {
      FUN_404e19e8(local_24,dwFlags);
      iVar1 = FUN_404e2604((int)awStack_a8,pszUnescaped,pcchUnescaped);
    }
    FUN_404f0b04(awStack_a8);
  }
  else {
    iVar1 = FUN_404e19e8(pszUrl,dwFlags);
  }
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e2b90 UrlCreateFromPathW */

/* Boundary evidence: original MIPS .pdata 404e2b90..404e2c63. Semantic name remains unreviewed. */

HRESULT UrlCreateFromPathW(LPCWSTR pszPath,LPWSTR pszUrl,LPDWORD pcchUrl,DWORD dwFlags)

{
  int iVar1;
  int iVar2;
  wchar_t awStack_a8 [70];
  uint local_1c;
  
                    /* 0x12b90  96  UrlCreateFromPathW */
  local_1c = DAT_404f4224;
  FUN_404f0aec(awStack_a8);
  if ((((pszPath == (LPCWSTR)0x0) || (pszUrl == (LPWSTR)0x0)) || (pcchUrl == (LPDWORD)0x0)) ||
     (*pcchUrl == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_404e1c88(pszPath,awStack_a8,dwFlags);
  }
  if ((-1 < iVar1) && (iVar2 = FUN_404e2604((int)awStack_a8,pszUrl,pcchUrl), iVar2 != 0)) {
    iVar1 = iVar2;
  }
  FUN_404f0b04(awStack_a8);
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e2c64 UrlApplySchemeW */

/* Boundary evidence: original MIPS .pdata 404e2c64..404e2d2f. Semantic name remains unreviewed. */

HRESULT UrlApplySchemeW(LPCWSTR pszIn,LPWSTR pszOut,LPDWORD pcchOut,DWORD dwFlags)

{
  int iVar1;
  wchar_t awStack_a8 [70];
  uint local_1c;
  
                    /* 0x12c64  90  UrlApplySchemeW */
  local_1c = DAT_404f4224;
  FUN_404f0aec(awStack_a8);
  if ((((pszIn == (LPCWSTR)0x0) || (pszOut == (LPWSTR)0x0)) || (pcchOut == (LPDWORD)0x0)) ||
     (*pcchOut == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_404e23ec(pszIn,awStack_a8,dwFlags);
  }
  if (iVar1 == 0) {
    iVar1 = FUN_404e2604((int)awStack_a8,pszOut,pcchOut);
  }
  FUN_404f0b04(awStack_a8);
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e2d30 ParseURLA */

/* Boundary evidence: original MIPS .pdata 404e2d30..404e2e17. Semantic name remains unreviewed. */

HRESULT ParseURLA(LPCSTR pcszURL,PARSEDURLA *ppu)

{
  char *pcVar1;
  UINT UVar2;
  size_t sVar3;
  HRESULT HVar4;
  undefined *local_18 [2];
  
                    /* 0x12d30  1  ParseURLA */
  HVar4 = -0x7ff8ffa9;
  if (((pcszURL != (LPCSTR)0x0) && (ppu != (PARSEDURLA *)0x0)) && (ppu->cbSize == 0x18)) {
    HVar4 = -0x7ffbefff;
    pcVar1 = FUN_404df830(pcszURL,(uint *)local_18);
    ppu->pszProtocol = pcVar1;
    if (pcVar1 != (char *)0x0) {
      ppu->cchProtocol = (UINT)local_18[0];
      UVar2 = FUN_404df090(pcVar1,local_18[0]);
      pcVar1 = pcVar1 + (int)local_18[0];
      ppu->nScheme = UVar2;
      ppu->pszSuffix = pcVar1 + 1;
      if (((UVar2 == 9) && (pcVar1[1] == '/')) &&
         ((pcVar1[2] == '/' && (ppu->pszSuffix = pcVar1 + 3, pcVar1[3] == '/')))) {
        ppu->pszSuffix = pcVar1 + 4;
      }
      sVar3 = strlen(ppu->pszSuffix);
      HVar4 = 0;
      ppu->cchSuffix = sVar3;
    }
  }
  return HVar4;
}



/* 404e2e18 ParseURLW */

/* Boundary evidence: original MIPS .pdata 404e2e18..404e2eff. Semantic name remains unreviewed. */

HRESULT ParseURLW(LPCWSTR pcszURL,PARSEDURLW *ppu)

{
  LPCWSTR pWVar1;
  UINT UVar2;
  size_t sVar3;
  HRESULT HVar4;
  undefined *local_18 [2];
  
                    /* 0x12e18  2  ParseURLW */
  HVar4 = -0x7ff8ffa9;
  if (((pcszURL != (LPCWSTR)0x0) && (ppu != (PARSEDURLW *)0x0)) && (ppu->cbSize == 0x18)) {
    HVar4 = -0x7ffbefff;
    pWVar1 = (LPCWSTR)FUN_404df914((ushort *)pcszURL,(uint *)local_18,0);
    ppu->pszProtocol = pWVar1;
    if (pWVar1 != (LPCWSTR)0x0) {
      ppu->cchProtocol = (UINT)local_18[0];
      UVar2 = FUN_404df130(pWVar1,local_18[0]);
      pWVar1 = ppu->pszProtocol + (int)(local_18[0] + 1);
      ppu->nScheme = UVar2;
      ppu->pszSuffix = pWVar1;
      if (((UVar2 == 9) && (*pWVar1 == L'/')) &&
         ((pWVar1[1] == L'/' && (ppu->pszSuffix = pWVar1 + 2, pWVar1[2] == L'/')))) {
        ppu->pszSuffix = pWVar1 + 3;
      }
      sVar3 = wcslen(ppu->pszSuffix);
      HVar4 = 0;
      ppu->cchSuffix = sVar3;
    }
  }
  return HVar4;
}



/* 404e2f00 FUN_404e2f00 */

/* Boundary evidence: original MIPS .pdata 404e2f00..404e302b. Semantic name remains unreviewed. */

undefined4 FUN_404e2f00(LPCWSTR param_1,undefined *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **ppuVar4;
  
  iVar3 = DAT_404f4308;
  ppuVar4 = &PTR_DAT_404d30dc;
  if ((param_2 == (undefined *)(&DAT_404d30e4)[DAT_404f4308 * 4]) &&
     (iVar1 = FUN_404ee924((ushort *)param_1,(ushort *)(&PTR_DAT_404d30dc)[DAT_404f4308 * 4],
                           (int)param_2), iVar1 == 0)) {
LAB_404e2fe4:
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = (&DAT_404d30e8)[iVar3 * 4];
    }
    DAT_404f4308 = iVar3;
    memcpy(param_1,(&PTR_DAT_404d30dc)[iVar3 * 4],(int)param_2 << 1);
    uVar2 = (&DAT_404d30e0)[iVar3 * 4];
  }
  else {
    iVar3 = 0;
    do {
      if ((param_2 == ppuVar4[2]) &&
         (iVar1 = StrCmpNIW(param_1,(LPCWSTR)*ppuVar4,(int)param_2), iVar1 == 0)) goto LAB_404e2fe4;
      iVar3 = iVar3 + 1;
      ppuVar4 = ppuVar4 + 4;
    } while (iVar3 < 0x12);
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 404e302c FUN_404e302c */

/* Boundary evidence: original MIPS .pdata 404e302c..404e3123. Semantic name remains unreviewed. */

void FUN_404e302c(int param_1,int param_2)

{
  HLOCAL _Dst;
  int iVar1;
  uint uVar2;
  
  if ((*(int *)(param_1 + 0x2c) != 0) && (param_2 == 0x5c)) {
    param_2 = 0x2f;
  }
  *(short *)(*(int *)(param_1 + 4) * 2 + *(int *)(param_1 + 0x23c) + -2) = (short)param_2;
  iVar1 = *(int *)(param_1 + 4);
  uVar2 = iVar1 + 1;
  *(uint *)(param_1 + 4) = uVar2;
  if (*(uint *)(param_1 + 0x18) < uVar2) {
    if (*(int *)(param_1 + 0x34) == 0) {
      _Dst = LocalAlloc(0x40,*(uint *)(param_1 + 0x18) << 2);
      if (_Dst == (HLOCAL)0x0) {
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
        *(undefined4 *)(param_1 + 0x34) = 1;
      }
      else {
        memcpy(_Dst,*(void **)(param_1 + 0x23c),(*(int *)(param_1 + 4) + -1) * 2);
        if (0x100 < *(uint *)(param_1 + 0x18)) {
          LocalFree(*(HLOCAL *)(param_1 + 0x23c));
        }
        *(HLOCAL *)(param_1 + 0x23c) = _Dst;
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) << 1;
      }
    }
    else {
      *(int *)(param_1 + 4) = iVar1;
    }
  }
  return;
}



/* 404e3124 FUN_404e3124 */

/* Boundary evidence: original MIPS .pdata 404e3124..404e33bf. Semantic name remains unreviewed. */

void FUN_404e3124(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 < 0x21) {
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 4);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  iVar3 = *(int *)(param_1 + 0x28);
  if (iVar3 == 1) {
    if (*(int *)(param_1 + 0x30) == 0) {
      if (param_2 == 0x25) {
        *(undefined4 *)(param_1 + 0x30) = 1;
        *(undefined2 *)(param_1 + 0x38) = 0;
        return;
      }
    }
    else if (((param_2 < 0x20) || (0x7f < param_2)) ||
            ((*(ushort *)(&DAT_404d2f0c + (param_2 - 0x20) * 2) & 2) == 0)) {
      FUN_404e302c(param_1,0x25);
      if (*(ushort *)(param_1 + 0x38) != 0) {
        FUN_404e302c(param_1,(uint)*(ushort *)(param_1 + 0x38));
      }
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    else {
      if (*(ushort *)(param_1 + 0x38) == 0) {
        *(short *)(param_1 + 0x38) = (short)param_2;
        return;
      }
      uVar1 = FUN_404e170c((uint)*(ushort *)(param_1 + 0x38));
      uVar2 = FUN_404e170c(param_2);
      param_2 = uVar1 * 0x10 + uVar2 & 0xffff;
      if (param_2 < 0x21) {
        if (*(int *)(param_1 + 0xc) == 0) {
          *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 4);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
      *(undefined4 *)(param_1 + 0x30) = 0;
      if ((param_2 == 0x5c) && (*(int *)(param_1 + 0x2c) != 0)) {
        *(undefined4 *)(param_1 + 0x2c) = 0;
        FUN_404e302c(param_1,0x5c);
        *(undefined4 *)(param_1 + 0x2c) = 1;
        return;
      }
    }
  }
  else if (iVar3 == 2) {
    if (((param_2 != 0x2f) && ((param_2 != 0x5c || (*(int *)(param_1 + 0x2c) == 0)))) &&
       (((param_2 < 0x100 &&
         (((param_2 < 0x20 || (0x7f < param_2)) ||
          ((*(ushort *)(&DAT_404d2f0c + (param_2 - 0x20) * 2) & 9) == 0)))) ||
        ((param_2 == 0x25 && ((*(uint *)(param_1 + 0x24) & 0x1000) != 0)))))) {
      FUN_404e302c(param_1,0x25);
      FUN_404e302c(param_1,(uint)(ushort)L"0123456789ABCDEF"[param_2 >> 4 & 0xf]);
      param_2 = (uint)(ushort)L"0123456789ABCDEF"[param_2 & 0xf];
    }
  }
  else if ((iVar3 == 3) && (param_2 == 0x20)) {
    FUN_404e302c(param_1,0x25);
    FUN_404e302c(param_1,0x32);
    param_2 = 0x30;
  }
  FUN_404e302c(param_1,param_2);
  return;
}



/* 404e33c0 FUN_404e33c0 */

/* Boundary evidence: original MIPS .pdata 404e33c0..404e340b. Semantic name remains unreviewed. */

void FUN_404e33c0(int param_1,ushort *param_2)

{
  for (; *param_2 != 0; param_2 = param_2 + 1) {
    FUN_404e3124(param_1,(uint)*param_2);
  }
  return;
}



/* 404e340c FUN_404e340c */

void FUN_404e340c(int *param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = param_1[1] - 2;
  if (*param_1 == 10) {
    if ((param_2 == 0) && (*(short *)(param_1[0x8f] + uVar2 * 2) == 0x2f)) {
      return;
    }
    uVar3 = param_1[2] - 1;
    iVar4 = uVar2 * 2;
    do {
      uVar2 = uVar2 - 1;
      iVar4 = iVar4 + -2;
      if (uVar2 < uVar3) break;
    } while (*(short *)(param_1[0x8f] + iVar4) != 0x2f);
  }
  else {
    if (param_2 == 0) {
      sVar1 = *(short *)(param_1[0x8f] + uVar2 * 2);
      if (sVar1 == 0x2f) {
        return;
      }
      if (sVar1 == 0x5c) {
        return;
      }
    }
    uVar3 = param_1[2] - 1;
    iVar4 = uVar2 * 2;
    do {
      uVar2 = uVar2 - 1;
      iVar4 = iVar4 + -2;
      if ((uVar2 < uVar3) || (*(short *)(param_1[0x8f] + iVar4) == 0x2f)) break;
    } while (*(short *)(param_1[0x8f] + iVar4) != 0x5c);
  }
  if (uVar3 <= uVar2) {
    uVar3 = uVar2 + 1;
  }
  param_1[1] = uVar3 + 1;
  return;
}



/* 404e3508 FUN_404e3508 */

/* Boundary evidence: original MIPS .pdata 404e3508..404e355f. Semantic name remains unreviewed. */

int FUN_404e3508(int param_1,LPCWSTR param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = 1;
  }
  else {
    *(undefined2 *)(*(int *)(param_1 + 4) * 2 + *(int *)(param_1 + 0x23c) + -2) = 0;
    iVar1 = StrCmpW((LPCWSTR)(*(int *)(param_1 + 8) * 2 + *(int *)(param_1 + 0x23c) + -2),param_2);
  }
  return iVar1;
}



/* 404e3560 FUN_404e3560 */

void FUN_404e3560(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (((*(uint *)(param_1 + 0x1c) & 1) != 0) && ((*(uint *)(param_1 + 0x24) & 0x4000000) != 0)) {
    return;
  }
  if (((*(int *)(param_1 + 0x10) != 0) || (*(int *)(param_1 + 0x14) != 0)) &&
     ((*(uint *)(param_1 + 0x24) & 0x22000000) != 0)) {
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x24);
  if ((uVar2 & 0x10000000) == 0) {
    if ((uVar2 & 0x20000000) != 0) {
      *(undefined4 *)(param_1 + 0x28) = 2;
      return;
    }
    if ((uVar2 & 0x4000000) == 0) {
      return;
    }
    uVar1 = 3;
  }
  else {
    uVar1 = 1;
  }
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  return;
}



/* 404e361c FUN_404e361c */

void FUN_404e361c(undefined4 *param_1,ushort *param_2,undefined4 param_3)

{
  for (; (*param_2 != 0 && (*param_2 < 0x21)); param_2 = param_2 + 1) {
  }
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_3;
  param_1[5] = 1;
  param_1[6] = 0;
  return;
}



/* 404e3650 FUN_404e3650 */

short FUN_404e3650(int param_1)

{
  short sVar1;
  short *psVar2;
  
  for (psVar2 = *(short **)(param_1 + 4);
      ((sVar1 = *psVar2, sVar1 == 9 || (sVar1 == 0xd)) || (sVar1 == 10)); psVar2 = psVar2 + 1) {
  }
  do {
    do {
      psVar2 = psVar2 + 1;
      sVar1 = *psVar2;
    } while (sVar1 == 9);
  } while ((sVar1 == 0xd) || (sVar1 == 10));
  return *psVar2;
}



/* 404e36bc FUN_404e36bc */

/* Boundary evidence: original MIPS .pdata 404e36bc..404e37d3. Semantic name remains unreviewed. */

ushort * FUN_404e36bc(undefined4 param_1,ushort *param_2,int param_3,uint param_4,ushort param_5,
                     ushort param_6,ushort param_7)

{
  ushort uVar1;
  uint uVar2;
  
  for (; ((uVar1 = *param_2, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); param_2 = param_2 + 1)
  {
  }
  if (*param_2 != 0) {
    do {
      uVar2 = (uint)*param_2;
      if (uVar2 == param_4) {
        return param_2;
      }
      if (uVar2 == param_5) {
        return param_2;
      }
      if (uVar2 == param_6) {
        return param_2;
      }
      if (uVar2 == param_7) {
        return param_2;
      }
      FUN_404e3124(param_3,uVar2);
      do {
        do {
          param_2 = param_2 + 1;
          uVar1 = *param_2;
        } while (uVar1 == 9);
      } while ((uVar1 == 0xd) || (uVar1 == 10));
    } while (uVar1 != 0);
  }
  return param_2;
}



/* 404e37d4 FUN_404e37d4 */

undefined4 FUN_404e37d4(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  short *psVar3;
  
  for (psVar3 = *(short **)(param_1 + 4);
      ((sVar1 = *psVar3, sVar1 == 9 || (sVar1 == 0xd)) || (sVar1 == 10)); psVar3 = psVar3 + 1) {
  }
  if (*psVar3 == 0x40) {
    uVar2 = 1;
    do {
      do {
        psVar3 = psVar3 + 1;
        sVar1 = *psVar3;
      } while (sVar1 == 9);
    } while ((sVar1 == 0xd) || (sVar1 == 10));
    *(short **)(param_1 + 4) = psVar3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 404e3860 FUN_404e3860 */

/* Boundary evidence: original MIPS .pdata 404e3860..404e392f. Semantic name remains unreviewed. */

void FUN_404e3860(int param_1,int param_2)

{
  ushort uVar1;
  ushort *puVar2;
  
  FUN_404e3560(param_2);
  FUN_404e3124(param_2,0x40);
  puVar2 = FUN_404e36bc(param_1,*(ushort **)(param_1 + 4),param_2,0x2f,0,0,0);
  *(ushort **)(param_1 + 4) = puVar2;
  if (*puVar2 == 0) {
    if (*(int *)(param_2 + 0xc) != 0) {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 0xc);
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
  }
  else {
    do {
      do {
        puVar2 = puVar2 + 1;
        uVar1 = *puVar2;
      } while (uVar1 == 9);
    } while ((uVar1 == 0xd) || (uVar1 == 10));
    *(ushort **)(param_1 + 4) = puVar2;
  }
  FUN_404e3124(param_2,0x2f);
  return;
}



/* 404e3930 FUN_404e3930 */

/* Boundary evidence: original MIPS .pdata 404e3930..404e3a2f. Semantic name remains unreviewed. */

void FUN_404e3930(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  short *psVar3;
  ushort *puVar4;
  
  for (puVar4 = *(ushort **)(param_1 + 4);
      ((uVar1 = *puVar4, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); puVar4 = puVar4 + 1) {
  }
  FUN_404e3124(param_2,(uint)*puVar4);
  puVar4 = *(ushort **)(param_1 + 4);
  do {
    do {
      puVar4 = puVar4 + 1;
      uVar1 = *puVar4;
    } while (uVar1 == 9);
  } while ((uVar1 == 0xd) || (uVar1 == 10));
  *(ushort **)(param_1 + 4) = puVar4;
  FUN_404e3124(param_2,(uint)*puVar4);
  psVar3 = *(short **)(param_1 + 4);
  do {
    do {
      psVar3 = psVar3 + 1;
      sVar2 = *psVar3;
    } while (sVar2 == 9);
  } while ((sVar2 == 0xd) || (sVar2 == 10));
  *(short **)(param_1 + 4) = psVar3;
  *(undefined4 *)(param_2 + 0x28) = 0;
  return;
}



/* 404e3a30 FUN_404e3a30 */

/* Boundary evidence: original MIPS .pdata 404e3a30..404e3b2f. Semantic name remains unreviewed. */

ushort * FUN_404e3a30(int param_1,ushort *param_2,int param_3)

{
  ushort *puVar1;
  wchar_t *pwVar2;
  int iVar3;
  
  *(undefined4 *)(param_3 + 8) = *(undefined4 *)(param_3 + 4);
  puVar1 = FUN_404e36bc(param_1,param_2,param_3,0x2f,0x5c,0x23,0x3f);
  if ((*(uint *)(param_1 + 0x10) & 0x8000000) == 0) {
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 == 1) {
      pwVar2 = L":21";
    }
    else if (iVar3 == 2) {
      pwVar2 = L":80";
    }
    else if (iVar3 == 3) {
      pwVar2 = L":70";
    }
    else {
      if (iVar3 != 0xb) goto LAB_404e3b10;
      pwVar2 = L":443";
    }
    iVar3 = FUN_404e3508(param_3,pwVar2);
    if (iVar3 == 0) {
      if (*(int *)(param_3 + 8) == 0) {
        return puVar1;
      }
      *(int *)(param_3 + 4) = *(int *)(param_3 + 8);
    }
  }
LAB_404e3b10:
  *(undefined4 *)(param_3 + 8) = 0;
  return puVar1;
}



/* 404e3b30 FUN_404e3b30 */

/* Boundary evidence: original MIPS .pdata 404e3b30..404e3d9b. Semantic name remains unreviewed. */

ushort * FUN_404e3b30(int param_1,ushort *param_2,int param_3,undefined4 *param_4)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint nChar;
  ushort *puVar5;
  int iVar6;
  
  bVar2 = false;
  for (; ((uVar1 = *param_2, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); param_2 = param_2 + 1)
  {
  }
  do {
    uVar4 = (uint)*param_2;
    puVar5 = param_2;
    if (uVar4 == 0) {
LAB_404e3d58:
      *param_4 = 0;
      bVar2 = true;
      param_2 = puVar5;
    }
    else {
      if (uVar4 == 0x23) {
        if (*(int *)(param_1 + 8) == 9) {
          iVar6 = 0;
          uVar4 = 0;
          do {
            nChar = *(uint *)((int)&DAT_404d3204 + uVar4);
            if (nChar < *(uint *)(param_3 + 4)) {
              iVar3 = StrCmpNIW((LPCWSTR)(((*(uint *)(param_3 + 4) - nChar) + -1) * 2 +
                                         *(int *)(param_3 + 0x23c)),
                                *(LPCWSTR *)((int)&PTR_u__html_404d3200 + uVar4),nChar);
            }
            else {
              iVar3 = 1;
            }
            if (iVar3 == 0) break;
            uVar4 = uVar4 + 0xc;
            iVar6 = iVar6 + 1;
          } while (uVar4 < 0x9c);
          if (iVar6 == 0xd) {
            FUN_404e3124(param_3,(uint)*param_2);
            do {
              do {
                param_2 = param_2 + 1;
                uVar1 = *param_2;
              } while (uVar1 == 9);
            } while ((uVar1 == 0xd) || (uVar1 == 10));
            goto LAB_404e3d60;
          }
        }
        goto LAB_404e3d58;
      }
      if (uVar4 == 0x2f) {
LAB_404e3bf8:
        bVar2 = true;
      }
      else {
        if (uVar4 == 0x3f) {
          if ((*(int *)(param_1 + 8) == 9) &&
             (puVar5 = (ushort *)&DAT_404f430c, *(int *)(param_1 + 0x18) == 0)) {
            FUN_404e302c(param_3,0x3f);
            do {
              do {
                param_2 = param_2 + 1;
                uVar1 = *param_2;
              } while (uVar1 == 9);
            } while ((uVar1 == 0xd) || (uVar1 == 10));
            goto LAB_404e3d60;
          }
          goto LAB_404e3d58;
        }
        if (uVar4 == 0x5c) goto LAB_404e3bf8;
      }
      FUN_404e3124(param_3,uVar4);
      do {
        do {
          param_2 = param_2 + 1;
          uVar1 = *param_2;
        } while (uVar1 == 9);
      } while ((uVar1 == 0xd) || (uVar1 == 10));
    }
LAB_404e3d60:
    if (bVar2) {
      return param_2;
    }
  } while( true );
}



/* 404e3d9c FUN_404e3d9c */

undefined4 FUN_404e3d9c(int param_1,undefined4 *param_2)

{
  short sVar1;
  undefined4 uVar2;
  short *psVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    for (psVar3 = *(short **)(param_1 + 4);
        ((sVar1 = *psVar3, sVar1 == 9 || (sVar1 == 0xd)) || (sVar1 == 10)); psVar3 = psVar3 + 1) {
    }
  }
  else {
    psVar3 = (short *)*param_2;
  }
  uVar2 = 0;
  if (*psVar3 == 0x2e) {
    do {
      do {
        psVar3 = psVar3 + 1;
        sVar1 = *psVar3;
      } while (sVar1 == 9);
    } while ((sVar1 == 0xd) || (sVar1 == 10));
    uVar2 = 1;
    if (sVar1 == 0x2e) {
      do {
        do {
          psVar3 = psVar3 + 1;
          sVar1 = *psVar3;
        } while (sVar1 == 9);
      } while ((sVar1 == 0xd) || (sVar1 == 10));
      uVar2 = 2;
    }
    sVar1 = *psVar3;
    if ((sVar1 != 0) && (sVar1 != 0x23)) {
      if (sVar1 != 0x2f) {
        if (sVar1 == 0x3f) goto LAB_404e3ec0;
        if (sVar1 != 0x5c) {
          uVar2 = 0;
          goto LAB_404e3ec0;
        }
        if (*(int *)(param_1 + 8) == 10) {
          uVar2 = 0;
        }
      }
      do {
        do {
          psVar3 = psVar3 + 1;
          sVar1 = *psVar3;
        } while (sVar1 == 9);
      } while ((sVar1 == 0xd) || (sVar1 == 10));
    }
  }
LAB_404e3ec0:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = psVar3;
  }
  return uVar2;
}



/* 404e3ed4 FUN_404e3ed4 */

/* Boundary evidence: original MIPS .pdata 404e3ed4..404e437b. Semantic name remains unreviewed. */

void FUN_404e3ed4(undefined4 *param_1,int param_2)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  puVar5 = (ushort *)param_1[1];
  if ((param_1[3] & 1) == 0) {
    for (; ((uVar2 = *puVar5, uVar2 == 9 || (uVar2 == 0xd)) || (uVar2 == 10)); puVar5 = puVar5 + 1)
    {
    }
    if (*puVar5 == 0x3f) {
      FUN_404e302c(param_2,0x3f);
    }
    if (*puVar5 == 0x3f) {
      if (*(int *)(param_2 + 0x10) != 0) {
        *(int *)(param_2 + 4) = *(int *)(param_2 + 0x10);
        *(undefined4 *)(param_2 + 0x14) = 0;
        *(undefined4 *)(param_2 + 0x10) = 0;
      }
      if (*(int *)(param_2 + 0x10) == 0) {
        *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_2 + 4);
      }
      FUN_404e3560(param_2);
      do {
        do {
          puVar5 = puVar5 + 1;
          uVar2 = *puVar5;
        } while (uVar2 == 9);
      } while ((uVar2 == 0xd) || (uVar2 == 10));
      while (uVar2 != 0) {
        if (*puVar5 == 0x23) {
          if (*(int *)(param_2 + 0x14) == 0) {
            *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 4);
            FUN_404e302c(param_2,0x23);
          }
        }
        else {
          FUN_404e3124(param_2,(uint)*puVar5);
        }
        do {
          do {
            puVar5 = puVar5 + 1;
            uVar2 = *puVar5;
          } while (uVar2 == 9);
        } while ((uVar2 == 0xd) || (uVar2 == 10));
      }
    }
    else {
      for (puVar4 = (ushort *)*param_1;
          ((uVar2 = *puVar4, uVar2 == 9 || (uVar2 == 0xd)) || (uVar2 == 10)); puVar4 = puVar4 + 1) {
      }
      bVar1 = puVar5 == puVar4;
      if (*(int *)(param_2 + 0x14) != 0) {
        *(int *)(param_2 + 4) = *(int *)(param_2 + 0x14);
        *(undefined4 *)(param_2 + 0x14) = 0;
      }
      if (*(int *)(param_2 + 0x14) == 0) {
        *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 4);
        FUN_404e302c(param_2,0x23);
      }
      FUN_404e3560(param_2);
      do {
        do {
          puVar5 = puVar5 + 1;
          uVar2 = *puVar5;
        } while (uVar2 == 9);
      } while ((uVar2 == 0xd) || (uVar2 == 10));
      while (((uVar3 = (uint)*puVar5, uVar3 == 0x3f && (bVar1)) || (uVar3 != 0))) {
        if (uVar3 == 0x3f) {
          FUN_404e302c(param_2,0x3f);
        }
        else {
          FUN_404e3124(param_2,uVar3);
        }
        do {
          do {
            puVar5 = puVar5 + 1;
            uVar2 = *puVar5;
          } while (uVar2 == 9);
        } while ((uVar2 == 0xd) || (uVar2 == 10));
      }
      if (*puVar5 == 0x3f) {
        if (*(int *)(param_2 + 0x14) != 0) {
          *(int *)(param_2 + 4) = *(int *)(param_2 + 0x14);
          *(undefined4 *)(param_2 + 0x14) = 0;
        }
        if (*(int *)(param_2 + 0x10) == 0) {
          *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_2 + 4);
        }
        FUN_404e302c(param_2,(uint)*puVar5);
        do {
          do {
            puVar5 = puVar5 + 1;
            uVar2 = *puVar5;
          } while (uVar2 == 9);
        } while ((uVar2 == 0xd) || (uVar2 == 10));
        while (*puVar5 != 0) {
          FUN_404e3124(param_2,(uint)*puVar5);
          do {
            do {
              puVar5 = puVar5 + 1;
              uVar2 = *puVar5;
            } while (uVar2 == 9);
          } while ((uVar2 == 0xd) || (uVar2 == 10));
        }
        if (*(int *)(param_2 + 0xc) != 0) {
          *(int *)(param_2 + 4) = *(int *)(param_2 + 0xc);
          *(undefined4 *)(param_2 + 0xc) = 0;
        }
        if (*(int *)(param_2 + 0x14) == 0) {
          *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 4);
          FUN_404e302c(param_2,0x23);
        }
        for (puVar5 = (ushort *)param_1[1];
            ((uVar2 = *puVar5, uVar2 == 9 || (uVar2 == 0xd)) || (uVar2 == 10)); puVar5 = puVar5 + 1)
        {
        }
        FUN_404e302c(param_2,(uint)*puVar5);
        do {
          do {
            puVar5 = puVar5 + 1;
            uVar2 = *puVar5;
          } while (uVar2 == 9);
        } while ((uVar2 == 0xd) || (uVar2 == 10));
        while (*puVar5 != 0x3f) {
          FUN_404e3124(param_2,(uint)*puVar5);
          do {
            do {
              puVar5 = puVar5 + 1;
              uVar2 = *puVar5;
            } while (uVar2 == 9);
          } while ((uVar2 == 0xd) || (uVar2 == 10));
        }
      }
    }
    if (*(int *)(param_2 + 0xc) != 0) {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 0xc);
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
    *(undefined4 *)(param_2 + 8) = 0;
  }
  else {
    for (; ((uVar2 = *puVar5, uVar2 == 9 || (uVar2 == 0xd)) || (uVar2 == 10)); puVar5 = puVar5 + 1)
    {
    }
    while (*puVar5 != 0) {
      FUN_404e3124(param_2,(uint)*puVar5);
      do {
        do {
          puVar5 = puVar5 + 1;
          uVar2 = *puVar5;
        } while (uVar2 == 9);
      } while ((uVar2 == 0xd) || (uVar2 == 10));
    }
    param_1[1] = puVar5;
  }
  return;
}



/* 404e437c FUN_404e437c */

/* Boundary evidence: original MIPS .pdata 404e437c..404e44df. Semantic name remains unreviewed. */

undefined4 FUN_404e437c(wchar_t *param_1,wint_t *param_2,LPWSTR param_3,int param_4)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  wint_t *pwVar4;
  LPWSTR pWVar5;
  
  StrCpyNW(param_3,param_1,param_4);
  sVar1 = wcslen(param_1);
  if ((int)(sVar1 + 3) < param_4) {
    pWVar5 = param_3 + sVar1;
    *pWVar5 = L':';
    iVar3 = 0;
    iVar2 = StrCmpW(param_1,L"http");
    pwVar4 = param_2;
    if (((iVar2 == 0) || (iVar2 = StrCmpW(param_1,L"ftp"), iVar2 == 0)) ||
       (iVar2 = StrCmpW(param_1,L"https"), iVar2 == 0)) {
      do {
        if ((*pwVar4 == 0) || (iVar2 = iswctype(*pwVar4,0x107), iVar2 != 0)) break;
        iVar3 = iVar3 + 1;
        pwVar4 = pwVar4 + 1;
      } while (iVar3 < 3);
      pWVar5[1] = L'/';
      param_3[sVar1 + 2] = L'/';
      param_3[sVar1 + 3] = L'\0';
    }
    else {
      iVar3 = 1;
      pWVar5[1] = L'\0';
    }
    StrCatBuffW(param_3,(LPCWSTR)(param_2 + iVar3),param_4);
  }
  return 0;
}



/* 404e44e0 UrlFixupW */

/* Boundary evidence: original MIPS .pdata 404e44e0..404e47ff. Semantic name remains unreviewed. */

HRESULT UrlFixupW(LPCWSTR pszIn,LPWSTR pszOut,DWORD cchOut)

{
  wchar_t wVar1;
  bool bVar2;
  LPCWSTR psz2;
  int iVar3;
  LSTATUS LVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  uint uVar7;
  WCHAR WVar8;
  wchar_t *pwVar9;
  WCHAR *pWVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  wchar_t *pwVar17;
  uint local_1070 [2];
  wchar_t local_1068 [32];
  WCHAR aWStack_1028 [2048];
  uint local_28;
  
                    /* 0x144e0  462  UrlFixupW */
  local_28 = DAT_404f4224;
  local_1070[0] = 0;
  psz2 = (LPCWSTR)FUN_404df914((ushort *)pszIn,local_1070,1);
  uVar16 = local_1070[0];
  if ((psz2 == (LPCWSTR)0x0) || (0x1f < local_1070[0])) {
    FUN_404f1430(local_28);
    uVar16 = 1;
  }
  else {
    uVar15 = 0;
    if (local_1070[0] != 0) {
      pWVar10 = local_1068;
      uVar13 = local_1070[0];
      do {
        WVar8 = *psz2;
        if ((0x40 < (ushort)WVar8) && ((ushort)WVar8 < 0x5b)) {
          WVar8 = WVar8 + L' ';
        }
        *pWVar10 = WVar8;
        pWVar10 = pWVar10 + 1;
        uVar13 = uVar13 - 1;
        psz2 = psz2 + 1;
        uVar15 = local_1070[0];
      } while (uVar13 != 0);
    }
    local_1068[uVar15] = L'\0';
    if (pszIn == pszOut) {
      StrCpyNW(aWStack_1028,psz2,0x800);
      psz2 = aWStack_1028;
    }
    uVar15 = 0;
    do {
      iVar3 = StrCmpW(local_1068,*(LPCWSTR *)((int)&PTR_DAT_404d30dc + uVar15));
      if (iVar3 == 0) goto LAB_404e47a4;
      uVar15 = uVar15 + 0x10;
    } while (uVar15 < 0x120);
    LVar4 = SHGetValueW((HKEY)0x80000000,local_1068,L"URL Protocol",(DWORD *)0x0,(void *)0x0,
                        (DWORD *)0x0);
    if (LVar4 == 0) {
LAB_404e47a4:
      FUN_404e437c(local_1068,(wint_t *)psz2,pszOut,cchOut);
      FUN_404f1430(local_28);
      uVar16 = 0;
    }
    else {
      uVar15 = 0;
      pwVar6 = (wchar_t *)0x0;
      uVar13 = 0;
      do {
        if ((*(uint *)((int)&DAT_404d30e8 + uVar13) & 0x10) != 0x10) {
          pwVar17 = *(wchar_t **)((int)&PTR_DAT_404d30dc + uVar13);
          uVar14 = *(uint *)((int)&DAT_404d30e4 + uVar13);
          uVar11 = 0;
          iVar3 = 0;
          bVar2 = false;
          if (local_1068[0] == *pwVar17) {
            uVar11 = 0x96;
          }
          else if (local_1068[0] == pwVar17[1]) {
            uVar11 = 0x50;
            bVar2 = true;
          }
          uVar7 = 1;
          if (1 < uVar14) {
            pwVar5 = local_1068;
            pwVar9 = pwVar17 + 2;
            uVar12 = uVar11;
            do {
              pwVar5 = pwVar5 + 1;
              wVar1 = *pwVar5;
              uVar11 = uVar12;
              if (wVar1 == L'\0') break;
              if (wVar1 == pwVar9[-1]) {
                uVar11 = uVar12 + 100;
              }
              else if (wVar1 == pwVar9[-2]) {
                if (iVar3 == 0) {
                  iVar3 = 1;
                  uVar11 = uVar12 + 0x50;
                }
                else {
LAB_404e46fc:
                  uVar11 = uVar12 + 100;
                }
              }
              else if (wVar1 == *pwVar9) {
                uVar11 = uVar12 + 0x50;
                if (bVar2) goto LAB_404e46fc;
                bVar2 = true;
              }
              uVar7 = uVar7 + 1;
              pwVar9 = pwVar9 + 1;
              uVar12 = uVar11;
            } while (uVar7 < iVar3 + uVar14);
          }
          if (uVar14 < uVar16) {
            uVar14 = uVar16;
          }
          uVar11 = uVar11 / uVar14;
          if (uVar14 == 0) {
            trap(0x1c00);
          }
          if (((int)uVar15 < (int)uVar11) && (pwVar6 = pwVar17, uVar15 = uVar11, 99 < (int)uVar11))
          break;
        }
        uVar13 = uVar13 + 0x10;
      } while (uVar13 < 0x120);
      if ((int)uVar15 >= 0x3c) {
        FUN_404e437c(pwVar6,(wint_t *)psz2,pszOut,cchOut);
      }
      uVar16 = (uint)((int)uVar15 < 0x3c);
      FUN_404f1430(local_28);
    }
  }
  return uVar16;
}



/* 404e4800 FUN_404e4800 */

/* Boundary evidence: original MIPS .pdata 404e4800..404e4897. Semantic name remains unreviewed. */

undefined4 FUN_404e4800(LPCWSTR param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  puVar3 = &DAT_404f4164;
  while ((puVar3[1] != param_2 || (iVar1 = StrCmpNIW((LPCWSTR)*puVar3,param_1,param_2), iVar1 != 0))
        ) {
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 4;
    if (0xb < iVar2) {
      return 0;
    }
  }
  *param_3 = iVar2;
  return 1;
}



/* 404e4898 FUN_404e4898 */

/* Boundary evidence: original MIPS .pdata 404e4898..404e494b. Semantic name remains unreviewed. */

undefined4 FUN_404e4898(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x57;
  }
  else {
    puVar2 = param_1 + param_2 + -1;
    *puVar2 = *puVar2;
    for (; param_1 < puVar2; param_1 = param_1 + 0x1000) {
      *param_1 = *param_1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 404e494c FUN_404e494c */

/* Boundary evidence: original MIPS .pdata 404e494c..404e4957. Semantic name remains unreviewed. */

undefined4 FUN_404e494c(void)

{
  return 1;
}



/* 404e4958 FUN_404e4958 */

/* Boundary evidence: original MIPS .pdata 404e4958..404e49e7. Semantic name remains unreviewed. */

undefined4 FUN_404e4958(short *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (short *)0x0) {
    for (; *param_1 != 0; param_1 = param_1 + 1) {
      iVar1 = iVar1 + 1;
    }
  }
  *param_2 = iVar1;
  return 0;
}



/* 404e49e8 FUN_404e49e8 */

/* Boundary evidence: original MIPS .pdata 404e49e8..404e49f3. Semantic name remains unreviewed. */

undefined4 FUN_404e49e8(void)

{
  return 1;
}



/* 404e49f4 FUN_404e49f4 */

/* Boundary evidence: original MIPS .pdata 404e49f4..404e4b5f. Semantic name remains unreviewed. */

undefined4 FUN_404e49f4(short *param_1,int param_2,short *param_3,int *param_4)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *param_4;
  do {
    if (param_2 == 0) {
LAB_404e4b0c:
      *param_4 = *param_4 - iVar3;
      return 0;
    }
    if (iVar3 == 0) {
      iVar3 = 0;
      if (param_2 != 0) {
        return 0x7a;
      }
      goto LAB_404e4b0c;
    }
    sVar2 = *param_1;
    if (sVar2 == 0x25) {
      uVar1 = (uint)(ushort)param_1[1];
      if ((((uVar1 < 0x20) || (0x7f < uVar1)) ||
          ((*(ushort *)(&DAT_404d2f0c + (uVar1 - 0x20) * 2) & 2) == 0)) ||
         (((uVar4 = (uint)(ushort)param_1[2], uVar4 < 0x20 || (0x7f < uVar4)) ||
          ((*(ushort *)(&DAT_404d2f0c + (uVar4 - 0x20) * 2) & 2) == 0)))) {
        return 0x2ee5;
      }
      uVar1 = FUN_404e170c(uVar1);
      uVar4 = FUN_404e170c(uVar4);
      sVar2 = (short)uVar1 * 0x10 + (short)uVar4;
      param_1 = param_1 + 3;
      param_2 = param_2 + -3;
    }
    else {
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    }
    *param_3 = sVar2;
    param_3 = param_3 + 1;
    iVar3 = iVar3 + -1;
  } while( true );
}



/* 404e4b60 FUN_404e4b60 */

/* Boundary evidence: original MIPS .pdata 404e4b60..404e4cf3. Semantic name remains unreviewed. */

undefined4
FUN_404e4b60(undefined4 *param_1,int *param_2,undefined4 *param_3,int *param_4,undefined4 *param_5,
            undefined4 *param_6,int *param_7,undefined4 *param_8)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  short sVar4;
  short *psVar5;
  short *psVar6;
  int iVar7;
  undefined4 *puVar8;
  
  psVar5 = (short *)*param_1;
  *param_3 = psVar5;
  *param_4 = 0;
  *param_5 = 0;
  *param_8 = 0;
  sVar4 = *psVar5;
  iVar7 = *param_2;
  bVar1 = false;
  bVar2 = false;
  psVar6 = (short *)0x0;
  iVar3 = 0;
  puVar8 = param_5;
  if (sVar4 != 0x2f) {
    do {
      if ((sVar4 == 0) || (iVar7 == 0)) break;
      if (sVar4 == 0x25) {
        *puVar8 = 1;
      }
      sVar4 = *psVar5;
      if (sVar4 == 0x5b) {
        if (bVar1) {
          return 0x2ee5;
        }
        if (bVar2) {
          return 0x2ee5;
        }
        bVar1 = true;
      }
      if (sVar4 == 0x5d) {
        if (!bVar1) {
          return 0x2ee5;
        }
        if (bVar2) {
          return 0x2ee5;
        }
        bVar2 = true;
      }
      if ((sVar4 != 0x3a) || (((bVar1 || (bVar2)) && ((!bVar1 || (!bVar2)))))) {
        iVar3 = iVar3 + 1;
      }
      else {
        if (psVar6 != (short *)0x0) {
          return 0x2ee5;
        }
        *param_4 = iVar3;
        if (iVar3 == 0) {
          *param_3 = 0;
        }
        iVar3 = 0;
        psVar6 = psVar5;
        puVar8 = param_8;
      }
      psVar5 = psVar5 + 1;
      sVar4 = *psVar5;
      iVar7 = iVar7 + -1;
    } while (sVar4 != 0x2f);
    if (psVar6 != (short *)0x0) {
      *param_7 = iVar3;
      *param_6 = psVar6 + 1;
      goto LAB_404e4cc4;
    }
  }
  *param_4 = iVar3;
  *param_6 = 0;
  *param_7 = 0;
  *param_8 = 0;
LAB_404e4cc4:
  if ((bVar1) && (bVar2)) {
    *param_5 = 0;
  }
  *param_1 = psVar5;
  *param_2 = iVar7;
  return 0;
}



/* 404e4cf4 FUN_404e4cf4 */

/* Boundary evidence: original MIPS .pdata 404e4cf4..404e509b. Semantic name remains unreviewed. */

int FUN_404e4cf4(int *param_1,size_t *param_2,undefined4 *param_3,uint *param_4,undefined4 *param_5,
                int *param_6,short *param_7,int *param_8,undefined2 *param_9,undefined4 *param_10)

{
  int iVar1;
  uint uVar2;
  wchar_t *pwVar3;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  wchar_t *_Str;
  ushort *puVar7;
  uint local_70;
  int local_6c;
  wchar_t *local_68;
  short *local_64;
  ushort *local_60;
  short *local_5c;
  int local_58;
  int local_54;
  int *local_50;
  int *local_4c;
  int local_48;
  size_t *local_44;
  short *local_40 [2];
  ushort local_38 [6];
  uint local_2c;
  
  local_2c = DAT_404f4224;
  _Str = (wchar_t *)*param_1;
  local_50 = param_8;
  local_5c = param_7;
  local_68 = _Str;
  local_4c = param_1;
  local_44 = param_2;
  local_64 = (short *)wcslen(_Str);
  psVar4 = (short *)0x0;
  pwVar3 = _Str;
  if (local_64 != (short *)0x0) {
    do {
      if (*pwVar3 == L'/') break;
      if (*pwVar3 == L'@') {
        if (_Str + (int)psVar4 != (wchar_t *)0x0) {
          local_60 = (ushort *)((int)(_Str + (int)psVar4) - (int)_Str >> 1);
          local_48 = (int)local_64 - (int)local_60;
          iVar1 = FUN_404e4b60(&local_68,(int *)&local_60,&local_64,(int *)&local_70,&local_58,
                               local_40,&local_6c,&local_54);
          psVar4 = local_64;
          if (iVar1 != 0) goto LAB_404e4f7c;
          if (param_3 != (undefined4 *)0x0) {
            if ((local_58 != 0) &&
               (iVar1 = FUN_404e49f4(local_64,local_70,local_64,(int *)&local_70), iVar1 != 0))
            goto LAB_404e4f7c;
            *param_3 = psVar4;
            *param_4 = local_70;
          }
          if (param_5 != (undefined4 *)0x0) {
            if ((local_54 != 0) &&
               (iVar1 = FUN_404e49f4(local_40[0],local_6c,local_40[0],&local_6c), iVar1 != 0))
            goto LAB_404e4f7c;
            *param_5 = local_40[0];
            *param_6 = local_6c;
          }
          local_68 = local_68 + 1;
          local_64 = (short *)(local_48 - 1);
          param_7 = local_5c;
          goto LAB_404e4dcc;
        }
        break;
      }
      psVar4 = (short *)((int)psVar4 + 1);
      pwVar3 = pwVar3 + 1;
    } while (psVar4 < local_64);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    *param_4 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
    *param_6 = 0;
  }
LAB_404e4dcc:
  local_60 = local_38;
  local_70 = 0xc;
  iVar1 = FUN_404e4b60(&local_68,(int *)&local_64,&local_5c,&local_6c,&local_58,&local_60,
                       (int *)&local_70,&local_54);
  psVar4 = local_5c;
  if (iVar1 == 0) {
    if (param_7 != (short *)0x0) {
      if ((local_58 != 0) &&
         (iVar1 = FUN_404e49f4(local_5c,local_6c,local_5c,&local_6c), iVar1 != 0))
      goto LAB_404e4f7c;
      *(short **)param_7 = psVar4;
      *local_50 = local_6c;
    }
    puVar7 = local_60;
    if (param_9 != (undefined2 *)0x0) {
      if (local_70 == 0) {
        *param_9 = 0;
        if (param_10 != (undefined4 *)0x0) {
          *param_10 = 0;
        }
      }
      else {
        if ((local_54 != 0) &&
           (iVar1 = FUN_404e49f4((short *)local_60,local_70,(short *)local_60,(int *)&local_70),
           iVar1 != 0)) goto LAB_404e4f7c;
        uVar6 = 0;
        uVar5 = 0;
        if (local_70 != 0) {
          do {
            uVar2 = (uint)*puVar7;
            if ((uVar2 < 0x30) || (0x39 < uVar2)) {
LAB_404e502c:
              FUN_404f1430(local_2c);
              return 0x2ee5;
            }
            uVar5 = (uVar5 * 10 + uVar2) - 0x30;
            puVar7 = puVar7 + 1;
            if (0xffff < uVar5) goto LAB_404e502c;
            uVar6 = uVar6 + 1;
          } while (uVar6 < local_70);
        }
        *param_9 = (short)uVar5;
        if (param_10 != (undefined4 *)0x0) {
          *param_10 = 1;
        }
      }
    }
    *local_4c = (int)local_68;
    *local_44 = (size_t)local_64;
    FUN_404f1430(local_2c);
    iVar1 = 0;
  }
  else {
LAB_404e4f7c:
    FUN_404f1430(local_2c);
  }
  return iVar1;
}



/* 404e509c FUN_404e509c */

/* Boundary evidence: original MIPS .pdata 404e509c..404e5487. Semantic name remains unreviewed. */

int FUN_404e509c(wchar_t *param_1,uint param_2,int param_3,int *param_4,undefined4 *param_5,
                int *param_6,short *param_7,int *param_8,undefined2 *param_9,undefined4 *param_10,
                uint *param_11,undefined4 *param_12,int *param_13,undefined4 *param_14,
                uint *param_15,undefined4 *param_16,int *param_17,undefined4 *param_18)

{
  bool bVar1;
  wchar_t wVar2;
  int iVar3;
  int iVar4;
  wchar_t *pwVar5;
  uint uVar6;
  wchar_t *pwVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  wchar_t *local_res0;
  uint local_res4 [3];
  int local_38;
  int *local_34;
  int local_30;
  
  local_34 = param_4;
  local_30 = param_3;
  if (param_2 == 0) {
    param_2 = wcslen(param_1);
  }
  iVar11 = 0;
  wVar2 = *param_1;
  pwVar7 = param_1;
  while (wVar2 != L':') {
    if (param_2 == 0) {
      return 0x2ee6;
    }
    if (*pwVar7 == L'\0') {
      return 0x2ee6;
    }
    pwVar7 = pwVar7 + 1;
    param_2 = param_2 - 1;
    iVar11 = iVar11 + 1;
    wVar2 = *pwVar7;
  }
  iVar12 = 0;
  iVar10 = 0;
  iVar9 = -1;
  iVar3 = FUN_404e4800(param_1,iVar11,&local_38);
  if (iVar3 != 0) {
    iVar9 = *(int *)(&DAT_404f416c + local_38 * 0x10);
    iVar12 = *(int *)(&DAT_404f4170 + local_38 * 0x10);
  }
  iVar3 = 1;
  if ((3 < param_2) && (iVar4 = StrCmpNIW(param_1 + iVar11,L"://",3), iVar4 == 0)) {
    iVar3 = 3;
    iVar10 = 1;
  }
  bVar1 = iVar9 == 5;
  if ((iVar9 == 6) || (iVar9 == -1)) {
    iVar12 = iVar10;
    if (iVar10 != 0) {
      bVar1 = false;
      goto LAB_404e51e8;
    }
    bVar1 = true;
  }
  else {
LAB_404e51e8:
    if (iVar10 != 0) {
      if (iVar12 == 0) {
        return 0x2ee6;
      }
      goto LAB_404e5230;
    }
  }
  if (iVar12 != 0) {
    return 0x2ee6;
  }
LAB_404e5230:
  if (local_34 != (int *)0x0) {
    *local_34 = iVar9;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = param_1;
    *param_6 = iVar11;
  }
  local_res0 = param_1 + iVar3 + iVar11;
  uVar8 = param_2 - iVar3;
  pwVar7 = local_res0;
  local_res4[0] = uVar8;
  if (iVar9 == 0xb) {
    if (param_10 != (undefined4 *)0x0) {
      *param_10 = 0;
      *param_11 = 0;
    }
    if (param_12 != (undefined4 *)0x0) {
      *param_12 = 0;
      *param_13 = 0;
    }
    if (param_9 != (undefined2 *)0x0) {
      *param_9 = 0;
    }
    for (; (*pwVar7 != L'\0' && (*pwVar7 != L'/')); pwVar7 = pwVar7 + 1) {
    }
    iVar11 = local_30;
    if (param_7 != (short *)0x0) {
      iVar12 = (int)pwVar7 - (int)local_res0 >> 1;
      *(wchar_t **)param_7 = local_res0;
      *param_8 = iVar12;
      local_res4[0] = uVar8 - iVar12;
      iVar11 = FUN_404e49f4(*(short **)param_7,iVar12,*(short **)param_7,param_8);
      uVar8 = uVar8 - iVar12;
    }
  }
  else if (bVar1) {
    if (param_10 != (undefined4 *)0x0) {
      *param_10 = 0;
      *param_11 = 0;
    }
    if (param_12 != (undefined4 *)0x0) {
      *param_12 = 0;
      *param_13 = 0;
    }
    if (param_7 != (short *)0x0) {
      param_7[0] = 0;
      param_7[1] = 0;
      *param_8 = 0;
    }
    if (param_9 != (undefined2 *)0x0) {
      *param_9 = 0;
    }
    iVar11 = 0;
  }
  else {
    iVar11 = FUN_404e4cf4((int *)&local_res0,local_res4,param_10,param_11,param_12,param_13,param_7,
                          param_8,param_9,param_18);
    pwVar7 = local_res0;
    uVar8 = local_res4[0];
  }
  if (local_30 != 0) {
    if (iVar11 != 0) {
      return iVar11;
    }
    iVar11 = FUN_404e49f4(pwVar7,uVar8,pwVar7,(int *)local_res4);
    uVar8 = local_res4[0];
  }
  if (iVar11 == 0) {
    if (param_16 != (undefined4 *)0x0) {
      uVar6 = 0;
      *param_17 = 0;
      pwVar5 = pwVar7;
      if (uVar8 != 0) {
        do {
          if ((*pwVar5 == L'?') || (*pwVar5 == L'#')) {
            *param_16 = pwVar5;
            *param_17 = uVar8 - uVar6;
            uVar8 = uVar8 - (uVar8 - uVar6);
          }
          uVar6 = uVar6 + 1;
          pwVar5 = pwVar5 + 1;
        } while (uVar6 < uVar8);
      }
    }
    if (param_14 != (undefined4 *)0x0) {
      *param_14 = pwVar7;
      *param_15 = uVar8;
      return 0;
    }
    return 0;
  }
  return iVar11;
}



/* 404e5488 FUN_404e5488 */

/* Boundary evidence: original MIPS .pdata 404e5488..404e552f. Semantic name remains unreviewed. */

int FUN_404e5488(LPCWSTR param_1,wchar_t *param_2,uint param_3)

{
  int iVar1;
  LPCWSTR pWVar2;
  
  if ((param_3 & 0x80000000) == 0) {
    pWVar2 = FUN_404dfa2c(param_1);
    if (pWVar2 == (LPCWSTR)0x0) {
      iVar1 = FUN_404f0dd4(param_2,param_1,0xffffffff);
    }
    else {
      iVar1 = FUN_404e1c88(pWVar2,param_2,param_3);
    }
  }
  else {
    iVar1 = FUN_404dfb44(param_2,param_1);
  }
  if (-1 < iVar1) {
    FUN_404df46c(*(ushort **)(param_2 + 0x42));
  }
  return iVar1;
}



/* 404e5530 FUN_404e5530 */

/* Boundary evidence: original MIPS .pdata 404e5530..404e5663. Semantic name remains unreviewed. */

int FUN_404e5530(short *param_1,uint *param_2,LPCWSTR param_3,wchar_t *param_4,uint *param_5,
                uint param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  short *local_res0 [4];
  
  iVar3 = 1;
  local_res0[0] = param_1;
  memset(param_2,0,0x28);
  if (*param_1 == 0) {
    *param_2 = *param_2 | 0x400;
  }
  if ((*param_1 != 0) || (param_3 != (LPCWSTR)0x0)) {
    FUN_404dfbcc((int *)local_res0,param_2);
    FUN_404df7c4(local_res0,param_2);
    FUN_404dfc9c(local_res0,param_2);
    iVar1 = FUN_404e02a8((int)param_2,(ushort *)param_3);
    if (iVar1 == 0) {
      uVar2 = *param_2;
    }
    else {
      iVar3 = FUN_404e5488(param_3,param_4,param_6);
      if (iVar3 < 0) {
        return iVar3;
      }
      FUN_404e5530(*(short **)(param_4 + 0x42),param_5,(LPCWSTR)0x0,(wchar_t *)0x0,(uint *)0x0,0);
      uVar2 = *param_5;
    }
    FUN_404e0024((uint *)local_res0,param_2,uVar2 & 8);
    FUN_404e021c((int *)local_res0,param_2);
  }
  return iVar3;
}



/* 404e5664 FUN_404e5664 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 404e5664..404e590f. Semantic name remains unreviewed. */

int FUN_404e5664(wchar_t *param_1,wchar_t *param_2,uint param_3)

{
  uint uVar1;
  uint *in_zero;
  int iVar2;
  short *local_218 [2];
  uint local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  wchar_t *local_200;
  uint local_1fc;
  undefined4 local_1f0;
  undefined4 local_1ec;
  uint local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  wchar_t *local_1d8;
  undefined4 local_1d4;
  undefined4 local_1c8;
  undefined4 local_1c4;
  wchar_t awStack_1c0 [66];
  short *local_13c;
  wchar_t awStack_130 [72];
  wchar_t awStack_a0 [70];
  uint local_14;
  
  local_14 = DAT_404f4224;
  FUN_404f0aec(awStack_1c0);
  if ((param_1 == (wchar_t *)0x0) || (param_2 == (wchar_t *)0x0)) {
    FUN_404f0b04(awStack_1c0);
    FUN_404f1430(local_14);
    return -0x7ff8ffa9;
  }
  if ((param_3 & 0x4000000) != 0) {
    iVar2 = FUN_404e120c(param_1,param_2,param_3);
    goto LAB_404e571c;
  }
  if ((param_3 & 0x2000) != 0) {
    FUN_404f0aec(awStack_130);
    FUN_404e15fc(param_1,1,param_3,(int)&local_1e8,awStack_130);
    FUN_404f0dd4(param_2,local_1d8,0xffffffff);
    FUN_404f0b04(awStack_130);
    iVar2 = 0;
    goto LAB_404e571c;
  }
  FUN_404f0b04(param_2);
  iVar2 = FUN_404f0dd4(awStack_1c0,param_1,0xffffffff);
  if (iVar2 < 0) {
    iVar2 = -0x7ff8fff2;
    goto LAB_404e571c;
  }
  FUN_404f0aec(awStack_a0);
  local_218[0] = local_13c;
  memset(&local_210,0,0x28);
  if (*local_13c == 0) {
    local_210 = local_210 | 0x400;
  }
  else {
    FUN_404dfbcc((int *)local_218,&local_210);
    FUN_404df7c4(local_218,&local_210);
    FUN_404dfc9c(local_218,&local_210);
    iVar2 = FUN_404e02a8((int)&local_210,(ushort *)0x0);
    uVar1 = local_210;
    if (iVar2 != 0) {
      iVar2 = FUN_404e5488((LPCWSTR)0x0,(wchar_t *)0x0,0);
      if (iVar2 < 0) goto LAB_404e5830;
      FUN_404e5530(_DAT_00000084,(uint *)0x0,(LPCWSTR)0x0,(wchar_t *)0x0,(uint *)0x0,0);
      uVar1 = *in_zero;
    }
    FUN_404e0024((uint *)local_218,&local_210,uVar1 & 8);
    FUN_404e021c((int *)local_218,&local_210);
  }
LAB_404e5830:
  memset(&local_1e8,0,0x28);
  iVar2 = 0;
  local_1e4 = local_20c;
  local_1e0 = local_208;
  local_1dc = local_204;
  if (local_1fc == 0) {
    local_1d4 = 0;
    local_1d8 = (wchar_t *)0x0;
  }
  else {
    iVar2 = FUN_404e15fc(local_200,local_1fc,param_3,(int)&local_1e8,awStack_a0);
  }
  if (-1 < iVar2) {
    local_1c8 = local_1f0;
    local_1c4 = local_1ec;
    local_1e8 = local_210;
    iVar2 = FUN_404e1164(&local_1e8,param_3,param_2);
  }
  FUN_404f0b04(awStack_a0);
LAB_404e571c:
  FUN_404f0b04(awStack_1c0);
  FUN_404f1430(local_14);
  return iVar2;
}



/* 404e5910 FUN_404e5910 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 404e5910..404e5a97. Semantic name remains unreviewed. */

int FUN_404e5910(wchar_t *param_1,wchar_t *param_2,uint param_3)

{
  uint uVar1;
  uint *in_zero;
  int iVar2;
  short *local_d0 [2];
  uint local_c8 [2];
  int local_c0;
  wchar_t awStack_a0 [66];
  short *local_1c;
  uint local_14;
  
  local_14 = DAT_404f4224;
  FUN_404f0aec(awStack_a0);
  FUN_404f0b04(param_2);
  iVar2 = FUN_404f0dd4(awStack_a0,param_1,0xffffffff);
  if (iVar2 < 0) goto LAB_404e5a6c;
  local_d0[0] = local_1c;
  memset(local_c8,0,0x28);
  if (*local_1c == 0) {
    local_c8[0] = local_c8[0] | 0x400;
  }
  else {
    FUN_404dfbcc((int *)local_d0,local_c8);
    FUN_404df7c4(local_d0,local_c8);
    FUN_404dfc9c(local_d0,local_c8);
    iVar2 = FUN_404e02a8((int)local_c8,(ushort *)0x0);
    uVar1 = local_c8[0];
    if (iVar2 != 0) {
      iVar2 = FUN_404e5488((LPCWSTR)0x0,(wchar_t *)0x0,0);
      if (iVar2 < 0) goto LAB_404e5a3c;
      FUN_404e5530(_DAT_00000084,(uint *)0x0,(LPCWSTR)0x0,(wchar_t *)0x0,(uint *)0x0,0);
      uVar1 = *in_zero;
    }
    FUN_404e0024((uint *)local_d0,local_c8,uVar1 & 8);
    FUN_404e021c((int *)local_d0,local_c8);
  }
LAB_404e5a3c:
  if (local_c0 == 9) {
    iVar2 = FUN_404e1b00(local_c8,param_2,param_3);
  }
  else {
    iVar2 = -0x7ff8ffa9;
  }
LAB_404e5a6c:
  FUN_404f0b04(awStack_a0);
  FUN_404f1430(local_14);
  return iVar2;
}



/* 404e5a98 FUN_404e5a98 */

/* Boundary evidence: original MIPS .pdata 404e5a98..404e5d33. Semantic name remains unreviewed. */

int FUN_404e5a98(LPCWSTR param_1,wchar_t *param_2,wchar_t *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint auStack_1b0 [2];
  int local_1a8;
  uint auStack_188 [10];
  uint auStack_160 [10];
  wchar_t awStack_138 [66];
  LPCWSTR local_b4;
  wchar_t awStack_a8 [70];
  uint local_1c;
  
  local_1c = DAT_404f4224;
  FUN_404f0aec(awStack_a8);
  FUN_404f0aec(awStack_138);
  FUN_404f0b04(param_3);
  if ((*param_2 == L'#') && ((param_1 == (LPCWSTR)0x0 || (*param_1 == L'\0')))) {
LAB_404e5b10:
    iVar1 = FUN_404f0dd4(param_3,param_2,0xffffffff);
LAB_404e5ce8:
    if (-1 < iVar1) goto LAB_404e5cf8;
  }
  else {
    iVar1 = FUN_404e5488(param_2,awStack_138,param_4);
    if (-1 < iVar1) {
      iVar1 = StrCmpW(local_b4,L"://");
      if (iVar1 == 0) {
        param_2 = L":///";
        goto LAB_404e5b10;
      }
      iVar1 = FUN_404e5530(local_b4,auStack_188,param_1,awStack_a8,auStack_160,param_4);
      if (-1 < iVar1) {
        if (iVar1 == 0) {
          FUN_404e0788(auStack_188,auStack_160,auStack_1b0);
        }
        else {
          memcpy(auStack_1b0,auStack_188,0x28);
        }
        if ((param_4 & 0x8000000) == 0) {
          FUN_404e0820(auStack_1b0);
          FUN_404e0bc8(auStack_1b0);
        }
        if ((local_1a8 == 9) && ((param_4 & 0x10000) == 0x10000)) {
          iVar1 = FUN_404f0dd4(param_3,L"file://",0xffffffff);
          if (iVar1 < 0) goto LAB_404e5cf0;
          iVar1 = FUN_404e1b00(auStack_1b0,param_3,param_4);
          iVar2 = local_1a8;
        }
        else {
          iVar1 = FUN_404e1164(auStack_1b0,param_4,param_3);
          iVar2 = local_1a8;
        }
        if (-1 < iVar1) {
          if ((param_4 & 0x10000000) != 0) {
            FUN_404e19e8(*(short **)(param_3 + 0x42),param_4);
          }
          if (((param_4 & 0x4000000) != 0) || ((param_4 & 0x20000000) != 0)) {
            iVar1 = FUN_404f0dd4(awStack_138,*(wchar_t **)(param_3 + 0x42),0xffffffff);
            if (iVar1 < 0) goto LAB_404e5cf0;
            iVar1 = FUN_404e5664(local_b4,param_3,param_4);
          }
          if (-1 < iVar1) {
            if (((param_4 & 0x80000000) == 0x80000000) && (iVar2 == 9)) {
              FUN_404df3dc(*(wchar_t **)(param_3 + 0x42));
            }
            goto LAB_404e5ce8;
          }
        }
      }
    }
  }
LAB_404e5cf0:
  FUN_404f0b04(param_3);
LAB_404e5cf8:
  FUN_404f0b04(awStack_138);
  FUN_404f0b04(awStack_a8);
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e5d34 FUN_404e5d34 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 404e5d34..404e5f6b. Semantic name remains unreviewed. */

int FUN_404e5d34(int param_1,wchar_t *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint *in_zero;
  int iVar2;
  short *psVar3;
  int iVar4;
  short *local_50 [2];
  uint local_48;
  wchar_t *local_44;
  int local_40;
  wchar_t *local_3c;
  wchar_t *local_28;
  
  psVar3 = *(short **)(param_1 + 0x84);
  iVar4 = 0;
  local_50[0] = psVar3;
  memset(&local_48,0,0x28);
  if (*psVar3 == 0) {
    local_48 = local_48 | 0x400;
  }
  else {
    FUN_404dfbcc((int *)local_50,&local_48);
    FUN_404df7c4(local_50,&local_48);
    FUN_404dfc9c(local_50,&local_48);
    iVar2 = FUN_404e02a8((int)&local_48,(ushort *)0x0);
    uVar1 = local_48;
    if (iVar2 != 0) {
      iVar2 = FUN_404e5488((LPCWSTR)0x0,(wchar_t *)0x0,0);
      if (iVar2 < 0) goto LAB_404e5e38;
      FUN_404e5530(_DAT_00000084,(uint *)0x0,(LPCWSTR)0x0,(wchar_t *)0x0,(uint *)0x0,0);
      uVar1 = *in_zero;
    }
    FUN_404e0024((uint *)local_50,&local_48,uVar1 & 8);
    FUN_404e021c((int *)local_50,&local_48);
  }
LAB_404e5e38:
  if ((param_4 & 1) == 0) {
    FUN_404f0b04(param_2);
  }
  else {
    iVar4 = FUN_404f0dd4(param_2,local_44,0xffffffff);
    if (iVar4 < 0) {
      return iVar4;
    }
    local_50[0] = (short *)CONCAT22(local_50[0]._2_2_,0x3a);
    iVar4 = FUN_404f0e24(param_2,(wchar_t *)local_50,1);
  }
  if (iVar4 < 0) {
    return iVar4;
  }
  if (param_3 != 1) {
    if (param_3 != 2) {
      if (2 < param_3) {
        if (param_3 < 6) goto LAB_404e5ef8;
        local_44 = local_28;
        if (param_3 == 6) goto LAB_404e5f34;
      }
      return -0x7fff0001;
    }
    local_44 = local_3c;
    if (local_40 != 9) {
LAB_404e5ef8:
      if ((local_48 & 2) != 0) {
        iVar4 = FUN_404e2020(param_3,(int)&local_48,param_2);
        return iVar4;
      }
      return -0x7fffbffb;
    }
  }
LAB_404e5f34:
  iVar4 = FUN_404f0dd4(param_2,local_44,0xffffffff);
  return iVar4;
}



/* 404e5f6c UrlIsW */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 404e5f6c..404e6207. Semantic name remains unreviewed. */

BOOL UrlIsW(LPCWSTR pszUrl,URLIS UrlIs)

{
  uint uVar1;
  uint *in_zero;
  LPCWSTR pWVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short *local_d8 [2];
  uint local_d0 [5];
  int local_bc;
  short *local_b0;
  wchar_t awStack_a8 [66];
  short *local_24;
  uint local_1c;
  
                    /* 0x15f6c  103  UrlIsW */
  local_1c = DAT_404f4224;
  uVar5 = 0;
  if ((pszUrl == (LPCWSTR)0x0) ||
     (pWVar2 = (LPCWSTR)FUN_404df914((ushort *)pszUrl,(uint *)local_d8,0), pWVar2 == (LPCWSTR)0x0))
  goto LAB_404e61dc;
  FUN_404f0aec(awStack_a8);
  iVar3 = FUN_404deeb0(pWVar2,(undefined *)local_d8[0],local_d8);
  if (UrlIs == URLIS_URL) {
    uVar5 = 1;
  }
  else if (UrlIs == URLIS_OPAQUE) {
    uVar5 = (uint)local_d8[0] & 1;
  }
  else if (UrlIs == URLIS_NOHISTORY) {
    uVar5 = (uint)local_d8[0] & 4;
  }
  else {
    if (UrlIs == URLIS_FILEURL) {
      if (iVar3 != 9) goto LAB_404e61b0;
      goto LAB_404e619c;
    }
    if (UrlIs == URLIS_APPLIABLE) {
      if ((iVar3 == 0) && (iVar3 = FUN_404e20ec(pszUrl,awStack_a8), iVar3 == 0)) goto LAB_404e619c;
    }
    else if ((4 < (int)UrlIs) &&
            (((int)UrlIs < 7 && (iVar3 = FUN_404f0dd4(awStack_a8,pszUrl,0xffffffff), -1 < iVar3))))
    {
      local_d8[0] = local_24;
      iVar3 = 1;
      memset(local_d0,0,0x28);
      if (*local_24 == 0) {
        local_d0[0] = local_d0[0] | 0x400;
      }
      else {
        FUN_404dfbcc((int *)local_d8,local_d0);
        FUN_404df7c4(local_d8,local_d0);
        FUN_404dfc9c(local_d8,local_d0);
        iVar4 = FUN_404e02a8((int)local_d0,(ushort *)0x0);
        uVar1 = local_d0[0];
        if (iVar4 == 0) {
LAB_404e6104:
          FUN_404e0024((uint *)local_d8,local_d0,uVar1 & 8);
          FUN_404e021c((int *)local_d8,local_d0);
        }
        else {
          iVar3 = FUN_404e5488((LPCWSTR)0x0,(wchar_t *)0x0,0);
          if (-1 < iVar3) {
            FUN_404e5530(_DAT_00000084,(uint *)0x0,(LPCWSTR)0x0,(wchar_t *)0x0,(uint *)0x0,0);
            uVar1 = *in_zero;
            goto LAB_404e6104;
          }
        }
        if (iVar3 < 0) goto LAB_404e61d4;
      }
      if (UrlIs == URLIS_DIRECTORY) {
        if ((local_bc == 0) || ((local_d0[0] & 0x1000) != 0)) goto LAB_404e619c;
LAB_404e61b0:
        uVar5 = 0;
      }
      else if (UrlIs == URLIS_HASQUERY) {
        if ((local_b0 == (short *)0x0) || (*local_b0 == 0)) goto LAB_404e61b0;
LAB_404e619c:
        uVar5 = 1;
      }
    }
  }
LAB_404e61d4:
  FUN_404f0b04(awStack_a8);
LAB_404e61dc:
  FUN_404f1430(local_1c);
  return uVar5;
}



/* 404e6208 UrlIsOpaqueW */

/* Boundary evidence: original MIPS .pdata 404e6208..404e6223. Semantic name remains unreviewed. */

BOOL UrlIsOpaqueW(LPCWSTR pszURL)

{
  BOOL BVar1;
  
                    /* 0x16208  102  UrlIsOpaqueW */
  BVar1 = UrlIsW(pszURL,URLIS_OPAQUE);
  return BVar1;
}



/* 404e6224 UrlIsNoHistoryW */

/* Boundary evidence: original MIPS .pdata 404e6224..404e623f. Semantic name remains unreviewed. */

BOOL UrlIsNoHistoryW(LPCWSTR pszURL)

{
  BOOL BVar1;
  
                    /* 0x16224  101  UrlIsNoHistoryW */
  BVar1 = UrlIsW(pszURL,URLIS_NOHISTORY);
  return BVar1;
}



/* 404e6240 PathCreateFromUrlA */

/* Boundary evidence: original MIPS .pdata 404e6240..404e636b. Semantic name remains unreviewed. */

HRESULT PathCreateFromUrlA(LPCSTR pszUrl,LPSTR pszPath,LPDWORD pcchPath,DWORD dwFlags)

{
  int iVar1;
  char acStack_188 [80];
  wchar_t awStack_138 [66];
  wchar_t *local_b4;
  wchar_t awStack_a8 [66];
  LPCWSTR local_24;
  uint local_1c;
  
                    /* 0x16240  7  PathCreateFromUrlA */
  local_1c = DAT_404f4224;
  FUN_404f077c(acStack_188);
  if ((((pszUrl == (LPCSTR)0x0) || (pszPath == (LPSTR)0x0)) || (pcchPath == (LPDWORD)0x0)) ||
     (*pcchPath == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    FUN_404f0aec(awStack_a8);
    FUN_404f0aec(awStack_138);
    iVar1 = FUN_404f0d94(awStack_138,pszUrl);
    if (iVar1 < 0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      iVar1 = FUN_404e5910(local_b4,awStack_a8,dwFlags);
    }
    if (-1 < iVar1) {
      iVar1 = FUN_404f0a9c(acStack_188,local_24,-1);
    }
    FUN_404f0b04(awStack_138);
    FUN_404f0b04(awStack_a8);
  }
  if (-1 < iVar1) {
    iVar1 = FUN_404e24dc((int)acStack_188,pszPath,pcchPath);
  }
  FUN_404f0794(acStack_188);
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e636c UrlEscapeW */

/* Boundary evidence: original MIPS .pdata 404e636c..404e6437. Semantic name remains unreviewed. */

HRESULT UrlEscapeW(LPCWSTR pszUrl,LPWSTR pszEscaped,LPDWORD pcchEscaped,DWORD dwFlags)

{
  int iVar1;
  wchar_t awStack_a8 [70];
  uint local_1c;
  
                    /* 0x1636c  97  UrlEscapeW */
  local_1c = DAT_404f4224;
  FUN_404f0aec(awStack_a8);
  if ((((pszUrl == (LPCWSTR)0x0) || (pszEscaped == (LPWSTR)0x0)) || (pcchEscaped == (LPDWORD)0x0))
     || (*pcchEscaped == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_404e5664(pszUrl,awStack_a8,dwFlags);
  }
  if (-1 < iVar1) {
    iVar1 = FUN_404e2604((int)awStack_a8,pszEscaped,pcchEscaped);
  }
  FUN_404f0b04(awStack_a8);
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e6438 PathCreateFromUrlW */

/* Boundary evidence: original MIPS .pdata 404e6438..404e6503. Semantic name remains unreviewed. */

HRESULT PathCreateFromUrlW(LPCWSTR pszUrl,LPWSTR pszPath,LPDWORD pcchPath,DWORD dwFlags)

{
  int iVar1;
  wchar_t awStack_a8 [70];
  uint local_1c;
  
                    /* 0x16438  8  PathCreateFromUrlW */
  local_1c = DAT_404f4224;
  FUN_404f0aec(awStack_a8);
  if ((((pszUrl == (LPCWSTR)0x0) || (pszPath == (LPWSTR)0x0)) || (pcchPath == (LPDWORD)0x0)) ||
     (*pcchPath == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_404e5910(pszUrl,awStack_a8,dwFlags);
  }
  if (-1 < iVar1) {
    iVar1 = FUN_404e2604((int)awStack_a8,pszPath,pcchPath);
  }
  FUN_404f0b04(awStack_a8);
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e6504 UrlGetPartW */

/* Boundary evidence: original MIPS .pdata 404e6504..404e6607. Semantic name remains unreviewed. */

HRESULT UrlGetPartW(LPCWSTR pszIn,LPWSTR pszOut,LPDWORD pcchOut,DWORD dwPart,DWORD dwFlags)

{
  int iVar1;
  wchar_t awStack_138 [72];
  wchar_t awStack_a8 [70];
  uint local_1c;
  
                    /* 0x16504  100  UrlGetPartW */
  local_1c = DAT_404f4224;
  FUN_404f0aec(awStack_a8);
  FUN_404f0aec(awStack_138);
  if ((((pszIn == (LPCWSTR)0x0) || (pszOut == (LPWSTR)0x0)) || (pcchOut == (LPDWORD)0x0)) ||
     ((*pcchOut == 0 || (dwPart == 0)))) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_404f0dd4(awStack_a8,pszIn,0xffffffff);
    if (iVar1 < 0) goto LAB_404e65d0;
    iVar1 = FUN_404e5d34((int)awStack_a8,awStack_138,dwPart,dwFlags);
  }
  if (-1 < iVar1) {
    iVar1 = FUN_404e2604((int)awStack_138,pszOut,pcchOut);
  }
LAB_404e65d0:
  FUN_404f0b04(awStack_138);
  FUN_404f0b04(awStack_a8);
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e6608 FUN_404e6608 */

undefined4 FUN_404e6608(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  
  for (; ((uVar1 = *param_2, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); param_2 = param_2 + 1)
  {
  }
  uVar1 = *param_2;
  if (((uVar1 < 0x61) || (0x7a < uVar1)) && ((uVar1 < 0x41 || (0x5a < uVar1)))) {
LAB_404e66f4:
    uVar2 = 0;
  }
  else {
    puVar3 = param_2 + 1;
    for (puVar4 = puVar3; ((uVar1 = *puVar4, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10));
        puVar4 = puVar4 + 1) {
    }
    if (*puVar4 != 0x3a) {
      for (; ((uVar1 = *puVar3, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); puVar3 = puVar3 + 1
          ) {
      }
      if (*puVar3 != 0x7c) goto LAB_404e66f4;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 404e6700 FUN_404e6700 */

/* Boundary evidence: original MIPS .pdata 404e6700..404e67c7. Semantic name remains unreviewed. */

int FUN_404e6700(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  
  for (; ((uVar1 = *param_2, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); param_2 = param_2 + 1)
  {
  }
  iVar2 = FUN_404e6608(param_1,param_2);
  if ((iVar2 == 0) && (*param_2 == 0x5c)) {
    do {
      do {
        param_2 = param_2 + 1;
        uVar1 = *param_2;
      } while (uVar1 == 9);
    } while ((uVar1 == 0xd) || (uVar1 == 10));
    iVar2 = 1;
    if (*param_2 != 0x5c) {
      iVar2 = 0;
    }
  }
  return iVar2;
}



/* 404e67c8 FUN_404e67c8 */

undefined4 FUN_404e67c8(int param_1,uint param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  ushort *puVar4;
  
  for (puVar4 = *(ushort **)(param_1 + 4);
      ((uVar1 = *puVar4, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); puVar4 = puVar4 + 1) {
  }
  uVar3 = (uint)*puVar4;
  if ((uVar3 == 0) || (((uVar3 != param_2 && (uVar3 != param_3)) && (uVar3 != param_4)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 404e683c FUN_404e683c */

bool FUN_404e683c(int param_1)

{
  short sVar1;
  short *psVar2;
  
  for (psVar2 = *(short **)(param_1 + 4);
      ((sVar1 = *psVar2, sVar1 == 9 || (sVar1 == 0xd)) || (sVar1 == 10)); psVar2 = psVar2 + 1) {
  }
  return *psVar2 != 0;
}



/* 404e688c FUN_404e688c */

/* Boundary evidence: original MIPS .pdata 404e688c..404e6b8b. Semantic name remains unreviewed. */

int FUN_404e688c(int param_1,int *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  
  puVar6 = *(ushort **)(param_1 + 4);
  for (puVar7 = puVar6; ((uVar1 = *puVar7, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10));
      puVar7 = puVar7 + 1) {
  }
  iVar2 = FUN_404e6700(param_1,puVar6);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 8) = 9;
    if (param_3 == 0) {
      FUN_404e33c0((int)param_2,&DAT_404d2ffc);
      FUN_404e3124((int)param_2,0x3a);
      *(undefined4 *)(param_1 + 0xc) = 8;
      *param_2 = *(int *)(param_1 + 8);
      param_2[7] = 8;
      param_2[0xb] = 8;
      param_2[9] = param_2[9] | 0x20001000;
      return iVar2;
    }
    if (*param_2 != 9) {
      *(undefined **)(param_1 + 4) = &DAT_404f430c;
      return iVar2;
    }
    return iVar2;
  }
  iVar2 = FUN_404dedc4((uint)*puVar7);
  while (iVar2 != 0) {
    do {
      do {
        puVar7 = puVar7 + 1;
        uVar3 = (uint)*puVar7;
      } while (uVar3 == 9);
    } while ((uVar3 == 0xd) || (uVar3 == 10));
    iVar2 = FUN_404dedc4(uVar3);
  }
  if (*puVar7 != 0x3a) {
    return 0;
  }
  iVar2 = 0;
  for (; ((uVar1 = *puVar6, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); puVar6 = puVar6 + 1) {
  }
  if (param_3 == 0) {
    while (puVar6 <= puVar7) {
      uVar1 = *puVar6;
      if ((uVar1 < 0x41) || (uVar4 = uVar1 + 0x20, 0x5a < uVar1)) {
        uVar4 = uVar1;
      }
      FUN_404e3124((int)param_2,(uint)uVar4);
      iVar2 = iVar2 + 1;
      do {
        do {
          puVar6 = puVar6 + 1;
          uVar1 = *puVar6;
        } while (uVar1 == 9);
      } while ((uVar1 == 0xd) || (uVar1 == 10));
    }
    *(ushort **)(param_1 + 4) = puVar6;
    iVar2 = FUN_404e2f00((LPCWSTR)param_2[0x8f],(undefined *)(iVar2 + -1),(uint *)(param_1 + 0xc));
    uVar3 = *(uint *)(param_1 + 0xc);
    *(int *)(param_1 + 8) = iVar2;
    param_2[7] = uVar3;
    *param_2 = iVar2;
    param_2[0xb] = uVar3 & 8;
  }
  else {
    puVar5 = (ushort *)param_2[0x8f];
    if (puVar6 <= puVar7) {
      do {
        uVar1 = *puVar6;
        if ((uVar1 < 0x41) || (uVar4 = uVar1 + 0x20, 0x5a < uVar1)) {
          uVar4 = uVar1;
        }
        if (uVar4 != *puVar5) break;
        do {
          do {
            puVar6 = puVar6 + 1;
            uVar1 = *puVar6;
          } while (uVar1 == 9);
        } while ((uVar1 == 0xd) || (uVar1 == 10));
        puVar5 = puVar5 + 1;
      } while (puVar6 <= puVar7);
      if (puVar6 <= puVar7) {
        *(undefined **)(param_1 + 4) = &DAT_404f430c;
        return 1;
      }
    }
    *(ushort **)(param_1 + 4) = puVar6;
  }
  return 1;
}



/* 404e6b8c FUN_404e6b8c */

/* Boundary evidence: original MIPS .pdata 404e6b8c..404e6be7. Semantic name remains unreviewed. */

void FUN_404e6b8c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_404e6608(param_1,*(ushort **)(param_1 + 4));
  if (iVar1 == 0) {
    FUN_404e67c8(param_1,0x2f,0x5c,0);
  }
  else {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x10000000;
  }
  return;
}



/* 404e6be8 FUN_404e6be8 */

/* Boundary evidence: original MIPS .pdata 404e6be8..404e6ca3. Semantic name remains unreviewed. */

undefined4 FUN_404e6be8(int param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar2 = FUN_404e67c8(param_1,0x2f,0x5c,0);
  if (iVar2 != 0) {
    psVar3 = *(short **)(param_1 + 4);
    do {
      do {
        psVar3 = psVar3 + 1;
        sVar1 = *psVar3;
      } while (sVar1 == 9);
    } while ((sVar1 == 0xd) || (sVar1 == 10));
    if ((*psVar3 == 0x2f) || (uVar4 = 0, *psVar3 == 0x5c)) {
      uVar4 = 1;
    }
  }
  return uVar4;
}



/* 404e6ca4 FUN_404e6ca4 */

/* Boundary evidence: original MIPS .pdata 404e6ca4..404e6f57. Semantic name remains unreviewed. */

void FUN_404e6ca4(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  
  for (puVar3 = *(ushort **)(param_1 + 4);
      ((uVar1 = *puVar3, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); puVar3 = puVar3 + 1) {
  }
  while ((*puVar3 == 0x2f || (*puVar3 == 0x5c))) {
    do {
      do {
        puVar3 = puVar3 + 1;
        uVar1 = *puVar3;
      } while (uVar1 == 9);
    } while ((uVar1 == 0xd) || (uVar1 == 10));
  }
  uVar4 = (int)puVar3 - (int)*(ushort **)(param_1 + 4) >> 1;
  if (uVar4 == 0) {
    iVar2 = FUN_404e6608(param_1,puVar3);
    if (iVar2 != 0) {
      *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) | 0x20001000;
    }
LAB_404e6edc:
    FUN_404e3124(param_2,0x2f);
    FUN_404e3124(param_2,0x2f);
    FUN_404e3124(param_2,0x2f);
    for (; ((uVar1 = *puVar3, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); puVar3 = puVar3 + 1)
    {
    }
    *(ushort **)(param_1 + 4) = puVar3;
    return;
  }
  if (uVar4 != 2) {
    if (uVar4 != 4) {
      if ((uVar4 < 5) || (6 < uVar4)) goto LAB_404e6edc;
      goto LAB_404e6de4;
    }
    *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) | 0x20001000;
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x10000000;
  }
  iVar2 = FUN_404e6608(param_1,puVar3);
  if (iVar2 != 0) {
    *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) | 0x20001000;
  }
LAB_404e6de4:
  FUN_404e3124(param_2,0x2f);
  FUN_404e3124(param_2,0x2f);
  iVar2 = FUN_404e6608(param_1,puVar3);
  if (iVar2 == 0) {
    FUN_404e3560(param_2);
    puVar3 = FUN_404e36bc(param_1,puVar3,param_2,0x2f,0x5c,0,0);
    if (*puVar3 == 0) {
      if (*(int *)(param_2 + 0xc) != 0) {
        *(int *)(param_2 + 4) = *(int *)(param_2 + 0xc);
        *(undefined4 *)(param_2 + 0xc) = 0;
      }
      *(undefined **)(param_1 + 4) = &DAT_404f430c;
    }
    else {
      do {
        do {
          puVar3 = puVar3 + 1;
          uVar1 = *puVar3;
        } while (uVar1 == 9);
      } while ((uVar1 == 0xd) || (uVar1 == 10));
      *(ushort **)(param_1 + 4) = puVar3;
    }
  }
  else {
    *(ushort **)(param_1 + 4) = puVar3;
  }
  FUN_404e3124(param_2,0x2f);
  return;
}



/* 404e6f58 FUN_404e6f58 */

/* Boundary evidence: original MIPS .pdata 404e6f58..404e7397. Semantic name remains unreviewed. */

void FUN_404e6f58(int param_1,int param_2)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  ushort uVar5;
  ushort *puVar6;
  
  for (puVar6 = *(ushort **)(param_1 + 4);
      ((uVar1 = *puVar6, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); puVar6 = puVar6 + 1) {
  }
  uVar4 = (uint)*puVar6;
  if ((uVar4 == 0x5c) || (uVar4 == 0x2f)) {
    FUN_404e3124(param_2,uVar4);
    do {
      do {
        puVar6 = puVar6 + 1;
        uVar1 = *puVar6;
      } while (uVar1 == 9);
    } while ((uVar1 == 0xd) || (uVar1 == 10));
  }
  uVar4 = (uint)*puVar6;
  if ((uVar4 == 0x5c) || (uVar4 == 0x2f)) {
    FUN_404e3124(param_2,uVar4);
    do {
      do {
        puVar6 = puVar6 + 1;
        uVar1 = *puVar6;
      } while (uVar1 == 9);
    } while ((uVar1 == 0xd) || (uVar1 == 10));
  }
  FUN_404e3560(param_2);
  *(ushort **)(param_1 + 4) = puVar6;
  bVar2 = false;
  while( true ) {
    if ((((*puVar6 == 0) || (uVar1 = *puVar6, uVar1 == 0x2f)) || (uVar1 == 0x23)) || (uVar1 == 0x3f)
       ) goto LAB_404e70d8;
    if (uVar1 == 0x40) break;
    do {
      do {
        puVar6 = puVar6 + 1;
        uVar1 = *puVar6;
      } while (uVar1 == 9);
    } while ((uVar1 == 0xd) || (uVar1 == 10));
  }
  bVar2 = true;
LAB_404e70d8:
  puVar6 = *(ushort **)(param_1 + 4);
  if (bVar2) {
    uVar1 = *puVar6;
    while (uVar1 != 0x40) {
      FUN_404e3124(param_2,(uint)*puVar6);
      do {
        do {
          puVar6 = puVar6 + 1;
          uVar1 = *puVar6;
        } while (uVar1 == 9);
      } while ((uVar1 == 0xd) || (uVar1 == 10));
    }
  }
  bVar2 = false;
  bVar3 = false;
  uVar1 = *puVar6;
  while (((uVar1 != 0 && (uVar1 != 0x2f)) &&
         ((uVar1 != 0x3a && ((uVar1 != 0x3f && (uVar1 != 0x23))))))) {
    if (uVar1 == 0x5b) {
      if (bVar2) {
        return;
      }
      if (bVar3) {
        return;
      }
      *(undefined4 *)(param_2 + 0x28) = 0;
      bVar2 = true;
    }
    uVar1 = *puVar6;
    if (uVar1 == 0x5d) {
      if (!bVar2) {
        return;
      }
      if (bVar3) {
        return;
      }
      FUN_404e3124(param_2,0x5d);
      FUN_404e3560(param_2);
      bVar3 = true;
      do {
        do {
          puVar6 = puVar6 + 1;
          uVar1 = *puVar6;
        } while (uVar1 == 9);
      } while ((uVar1 == 0xd) || (uVar1 == 10));
    }
    else {
      if ((uVar1 == 0x3a) && (((!bVar2 && (!bVar3)) || ((bVar2 && (bVar3)))))) break;
      if ((uVar1 < 0x41) || (uVar5 = uVar1 + 0x20, 0x5a < uVar1)) {
        uVar5 = uVar1;
      }
      FUN_404e3124(param_2,(uint)uVar5);
      do {
        do {
          puVar6 = puVar6 + 1;
          uVar1 = *puVar6;
        } while (uVar1 == 9);
      } while ((uVar1 == 0xd) || (uVar1 == 10));
    }
    uVar1 = *puVar6;
  }
  if (*puVar6 == 0x3a) {
    puVar6 = FUN_404e3a30(param_1,puVar6,param_2);
  }
  *(undefined4 *)(param_2 + 0x28) = 0;
  *(ushort **)(param_1 + 4) = puVar6;
  uVar4 = (uint)*puVar6;
  if (uVar4 == 0) {
    if (*(int *)(param_2 + 0xc) != 0) {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 0xc);
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
  }
  else if ((uVar4 != 0x3f) && (uVar4 != 0x23)) {
    FUN_404e3124(param_2,uVar4);
    do {
      do {
        puVar6 = puVar6 + 1;
        uVar1 = *puVar6;
      } while (uVar1 == 9);
    } while ((uVar1 == 0xd) || (uVar1 == 10));
    *(ushort **)(param_1 + 4) = puVar6;
    return;
  }
  FUN_404e3124(param_2,0x2f);
  return;
}



/* 404e7398 FUN_404e7398 */

/* Boundary evidence: original MIPS .pdata 404e7398..404e7917. Semantic name remains unreviewed. */

void FUN_404e7398(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  ushort *puVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort *puVar7;
  ushort *puVar8;
  
  for (puVar7 = *(ushort **)(param_1 + 4);
      ((uVar5 = *puVar7, uVar5 == 9 || (uVar5 == 0xd)) || (uVar5 == 10)); puVar7 = puVar7 + 1) {
  }
  uVar4 = (uint)*puVar7;
  if ((uVar4 == 0x5c) || (uVar4 == 0x2f)) {
    FUN_404e3124(param_2,uVar4);
    do {
      do {
        puVar7 = puVar7 + 1;
        uVar5 = *puVar7;
      } while (uVar5 == 9);
    } while ((uVar5 == 0xd) || (uVar5 == 10));
  }
  uVar4 = (uint)*puVar7;
  if ((uVar4 == 0x5c) || (uVar4 == 0x2f)) {
    FUN_404e3124(param_2,uVar4);
    do {
      do {
        puVar7 = puVar7 + 1;
        uVar5 = *puVar7;
      } while (uVar5 == 9);
    } while ((uVar5 == 0xd) || (uVar5 == 10));
  }
  FUN_404e3560(param_2);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_2 + 4);
  uVar5 = *puVar7;
  bVar1 = false;
  bVar2 = false;
  puVar8 = puVar7;
  if (uVar5 != 0) {
    while (((((uVar5 != 0x5c && (uVar5 != 0x2f)) && (uVar5 != 0x3a)) &&
            ((uVar5 != 0x3f && (uVar5 != 0x23)))) && (uVar5 != 0x40))) {
      if (uVar5 == 0x5b) {
        if (bVar1) {
          return;
        }
        if (bVar2) {
          return;
        }
        *(undefined4 *)(param_2 + 0x28) = 0;
        bVar1 = true;
      }
      uVar5 = *puVar8;
      if (uVar5 == 0x5d) {
        if (!bVar1) {
          return;
        }
        if (bVar2) {
          return;
        }
        FUN_404e3124(param_2,0x5d);
        FUN_404e3560(param_2);
        bVar2 = true;
        do {
          do {
            puVar8 = puVar8 + 1;
            uVar5 = *puVar8;
          } while (uVar5 == 9);
        } while ((uVar5 == 0xd) || (uVar5 == 10));
      }
      else {
        if ((uVar5 == 0x3a) && (((!bVar1 && (!bVar2)) || ((bVar1 && (bVar2)))))) break;
        if ((uVar5 < 0x41) || (uVar6 = uVar5 + 0x20, 0x5a < uVar5)) {
          uVar6 = uVar5;
        }
        FUN_404e3124(param_2,(uint)uVar6);
        do {
          do {
            puVar8 = puVar8 + 1;
            uVar5 = *puVar8;
          } while (uVar5 == 9);
        } while ((uVar5 == 0xd) || (uVar5 == 10));
      }
      uVar5 = *puVar8;
      if (uVar5 == 0) break;
    }
  }
  puVar3 = puVar8;
  if (*puVar8 == 0x3a) {
    do {
      do {
        puVar3 = puVar3 + 1;
        uVar5 = *puVar3;
      } while (uVar5 == 9);
    } while (((uVar5 == 0xd) || (uVar5 == 10)) ||
            (((uVar5 != 0 && (((uVar5 != 0x5c && (uVar5 != 0x2f)) && (uVar5 != 0x3a)))) &&
             (((uVar5 != 0x3f && (uVar5 != 0x23)) && (uVar5 != 0x40))))));
    if (*puVar3 != 0x40) {
      puVar3 = FUN_404e3a30(param_1,puVar8,param_2);
    }
  }
  if (*puVar3 == 0x40) {
    if (*(int *)(param_2 + 8) != 0) {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 8);
      *(undefined4 *)(param_2 + 8) = 0;
    }
    uVar5 = *puVar7;
    while (uVar5 != 0x40) {
      FUN_404e3124(param_2,(uint)*puVar7);
      do {
        do {
          puVar7 = puVar7 + 1;
          uVar5 = *puVar7;
        } while (uVar5 == 9);
      } while ((uVar5 == 0xd) || (uVar5 == 10));
    }
    uVar5 = *puVar7;
    puVar3 = puVar7;
    while (((((uVar5 != 0 && (uVar5 = *puVar3, uVar5 != 0x5c)) && (uVar5 != 0x2f)) &&
            ((uVar5 != 0x3a && (uVar5 != 0x3f)))) && (uVar5 != 0x23))) {
      if ((uVar5 < 0x41) || (uVar6 = uVar5 + 0x20, 0x5a < uVar5)) {
        uVar6 = uVar5;
      }
      FUN_404e3124(param_2,(uint)uVar6);
      do {
        do {
          puVar3 = puVar3 + 1;
          uVar5 = *puVar3;
        } while (uVar5 == 9);
      } while ((uVar5 == 0xd) || (uVar5 == 10));
    }
    if (*puVar3 == 0x3a) {
      puVar3 = FUN_404e3a30(param_1,puVar3,param_2);
    }
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0x28) = 0;
  *(ushort **)(param_1 + 4) = puVar3;
  uVar4 = (uint)*puVar3;
  if (uVar4 == 0) {
    if (*(int *)(param_2 + 0xc) != 0) {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 0xc);
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 8) == 0) {
      return;
    }
    if ((*(uint *)(param_1 + 0xc) & 1) != 0) {
      return;
    }
  }
  else if ((uVar4 != 0x3f) && (uVar4 != 0x23)) {
    FUN_404e3124(param_2,uVar4);
    do {
      do {
        puVar3 = puVar3 + 1;
        uVar5 = *puVar3;
      } while (uVar5 == 9);
    } while ((uVar5 == 0xd) || (uVar5 == 10));
    *(ushort **)(param_1 + 4) = puVar3;
    return;
  }
  FUN_404e3124(param_2,0x2f);
  return;
}



/* 404e7918 FUN_404e7918 */

/* Boundary evidence: original MIPS .pdata 404e7918..404e7d2b. Semantic name remains unreviewed. */

void FUN_404e7918(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort *puVar6;
  
  for (puVar6 = *(ushort **)(param_1 + 4);
      ((uVar4 = *puVar6, uVar4 == 9 || (uVar4 == 0xd)) || (uVar4 == 10)); puVar6 = puVar6 + 1) {
  }
  if ((*(uint *)(param_1 + 0xc) & 2) == 0) {
    *(undefined4 *)(param_2 + 0x2c) = 0;
  }
  uVar3 = (uint)*puVar6;
  if ((uVar3 == 0x5c) || (uVar3 == 0x2f)) {
    FUN_404e3124(param_2,uVar3);
    do {
      do {
        puVar6 = puVar6 + 1;
        uVar4 = *puVar6;
      } while (uVar4 == 9);
    } while ((uVar4 == 0xd) || (uVar4 == 10));
  }
  uVar3 = (uint)*puVar6;
  if ((uVar3 == 0x5c) || (uVar3 == 0x2f)) {
    FUN_404e3124(param_2,uVar3);
    do {
      do {
        puVar6 = puVar6 + 1;
        uVar4 = *puVar6;
      } while (uVar4 == 9);
    } while ((uVar4 == 0xd) || (uVar4 == 10));
  }
  if ((*(uint *)(param_1 + 0xc) & 2) == 0) {
    uVar4 = *puVar6;
    while ((uVar4 != 0 && (*puVar6 != 0x2f))) {
      FUN_404e3124(param_2,(uint)*puVar6);
      do {
        do {
          puVar6 = puVar6 + 1;
          uVar4 = *puVar6;
        } while (uVar4 == 9);
      } while ((uVar4 == 0xd) || (uVar4 == 10));
    }
  }
  else {
    FUN_404e3560(param_2);
    uVar4 = *puVar6;
    bVar1 = false;
    bVar2 = false;
    if (uVar4 != 0) {
      while ((((uVar4 != 0x5c && (uVar4 != 0x2f)) && (uVar4 != 0x3a)) &&
             ((uVar4 != 0x3f && (uVar4 != 0x23))))) {
        if (uVar4 == 0x5b) {
          if (bVar1) {
            return;
          }
          if (bVar2) {
            return;
          }
          *(undefined4 *)(param_2 + 0x28) = 0;
          bVar1 = true;
        }
        uVar4 = *puVar6;
        if (uVar4 == 0x5d) {
          if (!bVar1) {
            return;
          }
          if (bVar2) {
            return;
          }
          FUN_404e3124(param_2,0x5d);
          FUN_404e3560(param_2);
          bVar2 = true;
          do {
            do {
              puVar6 = puVar6 + 1;
              uVar4 = *puVar6;
            } while (uVar4 == 9);
          } while ((uVar4 == 0xd) || (uVar4 == 10));
        }
        else {
          if ((uVar4 == 0x3a) && (((!bVar1 && (!bVar2)) || ((bVar1 && (bVar2)))))) break;
          if ((uVar4 < 0x41) || (uVar5 = uVar4 + 0x20, 0x5a < uVar4)) {
            uVar5 = uVar4;
          }
          FUN_404e3124(param_2,(uint)uVar5);
          do {
            do {
              puVar6 = puVar6 + 1;
              uVar4 = *puVar6;
            } while (uVar4 == 9);
          } while ((uVar4 == 0xd) || (uVar4 == 10));
        }
        uVar4 = *puVar6;
        if (uVar4 == 0) break;
      }
    }
    if (*puVar6 == 0x3a) {
      puVar6 = FUN_404e3a30(param_1,puVar6,param_2);
    }
    *(undefined4 *)(param_2 + 0x28) = 0;
  }
  *(ushort **)(param_1 + 4) = puVar6;
  uVar3 = (uint)*puVar6;
  if (uVar3 == 0) {
    if (*(int *)(param_2 + 0xc) != 0) {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 0xc);
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 8) == 0) {
      return;
    }
    if ((*(uint *)(param_1 + 0xc) & 1) != 0) {
      return;
    }
  }
  else if ((uVar3 != 0x3f) && (uVar3 != 0x23)) {
    FUN_404e3124(param_2,uVar3);
    do {
      do {
        puVar6 = puVar6 + 1;
        uVar4 = *puVar6;
      } while (uVar4 == 9);
    } while ((uVar4 == 0xd) || (uVar4 == 10));
    *(ushort **)(param_1 + 4) = puVar6;
    return;
  }
  FUN_404e3124(param_2,0x2f);
  return;
}



/* 404e7d2c FUN_404e7d2c */

/* Boundary evidence: original MIPS .pdata 404e7d2c..404e7dcf. Semantic name remains unreviewed. */

undefined4 FUN_404e7d2c(int param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if ((*(uint *)(param_1 + 0xc) & 1) == 0) {
    iVar2 = FUN_404e67c8(param_1,0x2f,0x5c,0);
    if (iVar2 != 0) {
      psVar3 = *(short **)(param_1 + 4);
      uVar4 = 1;
      do {
        do {
          psVar3 = psVar3 + 1;
          sVar1 = *psVar3;
        } while (sVar1 == 9);
      } while ((sVar1 == 0xd) || (sVar1 == 10));
      *(short **)(param_1 + 4) = psVar3;
    }
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}



/* 404e7dd0 FUN_404e7dd0 */

/* Boundary evidence: original MIPS .pdata 404e7dd0..404e7e4b. Semantic name remains unreviewed. */

undefined4 FUN_404e7dd0(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short *psVar4;
  
  for (psVar4 = *(short **)(param_1 + 4);
      ((sVar1 = *psVar4, sVar1 == 9 || (sVar1 == 0xd)) || (sVar1 == 10)); psVar4 = psVar4 + 1) {
  }
  if ((*psVar4 == 0) || (iVar2 = FUN_404e67c8(param_1,0x3f,0x23,0), iVar2 != 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* 404e7e4c FUN_404e7e4c */

/* Boundary evidence: original MIPS .pdata 404e7e4c..404e7fab. Semantic name remains unreviewed. */

void FUN_404e7e4c(int param_1,int *param_2,int param_3)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  ushort *local_20;
  int local_1c;
  
  for (local_20 = *(ushort **)(param_1 + 4);
      ((uVar1 = *local_20, uVar1 == 9 || (uVar1 == 0xd)) || (uVar1 == 10)); local_20 = local_20 + 1)
  {
  }
  if (param_3 != 0) {
    param_2[2] = param_2[1];
  }
  if ((*(uint *)(param_1 + 0xc) & 1) == 0) {
    iVar4 = 1;
    local_1c = 1;
    do {
      puVar2 = local_20;
      if ((*(int *)(param_1 + 0x14) == 0) || (iVar3 = FUN_404e3d9c(param_1,&local_20), iVar3 == 0))
      {
        local_20 = FUN_404e3b30(param_1,puVar2,(int)param_2,&local_1c);
        iVar4 = local_1c;
      }
      else if (iVar3 == 2) {
        FUN_404e340c(param_2,1);
      }
    } while (iVar4 != 0);
    *(ushort **)(param_1 + 4) = local_20;
    if (*local_20 != 0) {
      return;
    }
    if (param_2[3] == 0) {
      return;
    }
    param_2[1] = param_2[3];
  }
  else {
    puVar2 = FUN_404e36bc(param_1,local_20,(int)param_2,0,0,0,0);
    *(ushort **)(param_1 + 4) = puVar2;
    if (param_2[3] == 0) {
      return;
    }
    param_2[1] = param_2[3];
  }
  param_2[3] = 0;
  return;
}



/* 404e7fac UrlCrackW */

/* Boundary evidence: original MIPS .pdata 404e7fac..404e87f3. Semantic name remains unreviewed. */

bool UrlCrackW(wchar_t *param_1,uint param_2,uint param_3,int *param_4)

{
  bool bVar1;
  DWORD DVar2;
  DWORD dwErrCode;
  BOOL BVar3;
  uint uVar4;
  wchar_t *_Dst;
  HRESULT HVar5;
  LPWSTR pWVar6;
  SIZE_T uBytes;
  undefined2 **ppuVar7;
  uint *puVar8;
  undefined2 *puVar9;
  size_t sVar10;
  uint uVar11;
  LPDWORD pcchPath;
  uint local_res4 [3];
  short local_70 [2];
  uint local_6c;
  undefined2 *local_68;
  uint local_64;
  undefined2 *local_60;
  uint local_5c;
  undefined2 *local_58;
  uint local_54;
  undefined2 *local_50;
  uint local_4c;
  undefined2 *local_48;
  DWORD local_44;
  undefined2 *local_40;
  uint local_3c;
  wchar_t *local_38;
  wchar_t *local_34;
  int local_30;
  int local_2c;
  
                    /* 0x17fac  480  UrlCrackW */
  local_res4[0] = param_2;
  local_6c = param_3;
  local_38 = param_1;
  if (param_1 == (wchar_t *)0x0) {
LAB_404e802c:
    dwErrCode = 0x57;
LAB_404e8030:
    if (dwErrCode != 0) goto LAB_404e87a8;
  }
  else {
    if (param_2 == 0) {
      dwErrCode = FUN_404e4958(param_1,(int *)local_res4);
      param_2 = local_res4[0];
      goto LAB_404e8030;
    }
    BVar3 = IsBadReadPtr(param_1,param_2 << 1);
    if (BVar3 != 0) goto LAB_404e802c;
  }
  BVar3 = IsBadWritePtr(param_4,0x3c);
  if ((BVar3 == 0) && (*param_4 == 0x3c)) {
    if ((param_3 & 0x6fffffff) != 0) {
LAB_404e8078:
      dwErrCode = 0x57;
      goto LAB_404e87a8;
    }
    puVar9 = (undefined2 *)param_4[1];
    local_64 = param_4[2];
    bVar1 = false;
    local_68 = puVar9;
    if ((puVar9 != (undefined2 *)0x0) && (local_64 != 0)) {
      dwErrCode = FUN_404e4898((undefined1 *)puVar9,local_64 << 1);
      if (dwErrCode != 0) goto LAB_404e87a8;
      *puVar9 = 0;
      bVar1 = true;
    }
    puVar9 = (undefined2 *)param_4[4];
    local_5c = param_4[5];
    local_60 = puVar9;
    if ((puVar9 != (undefined2 *)0x0) && (local_5c != 0)) {
      dwErrCode = FUN_404e4898((undefined1 *)puVar9,local_5c << 1);
      if (dwErrCode != 0) goto LAB_404e87a8;
      *puVar9 = 0;
      bVar1 = true;
    }
    puVar9 = (undefined2 *)param_4[7];
    local_54 = param_4[8];
    local_58 = puVar9;
    if ((puVar9 != (undefined2 *)0x0) && (local_54 != 0)) {
      dwErrCode = FUN_404e4898((undefined1 *)puVar9,local_54 << 1);
      if (dwErrCode != 0) goto LAB_404e87a8;
      *puVar9 = 0;
      bVar1 = true;
    }
    puVar9 = (undefined2 *)param_4[9];
    local_4c = param_4[10];
    local_50 = puVar9;
    if ((puVar9 != (undefined2 *)0x0) && (local_4c != 0)) {
      dwErrCode = FUN_404e4898((undefined1 *)puVar9,local_4c << 1);
      if (dwErrCode != 0) goto LAB_404e87a8;
      *puVar9 = 0;
      bVar1 = true;
    }
    pcchPath = (LPDWORD)(param_4 + 0xc);
    puVar9 = (undefined2 *)param_4[0xb];
    local_44 = *pcchPath;
    local_48 = puVar9;
    if ((puVar9 != (undefined2 *)0x0) && (local_44 != 0)) {
      dwErrCode = FUN_404e4898((undefined1 *)puVar9,local_44 << 1);
      if (dwErrCode != 0) goto LAB_404e87a8;
      *puVar9 = 0;
      bVar1 = true;
    }
    puVar9 = (undefined2 *)param_4[0xd];
    uVar11 = param_4[0xe];
    local_40 = puVar9;
    local_3c = uVar11;
    if ((puVar9 != (undefined2 *)0x0) && (uVar11 != 0)) {
      dwErrCode = FUN_404e4898((undefined1 *)puVar9,uVar11 << 1);
      if (dwErrCode != 0) goto LAB_404e87a8;
      *puVar9 = 0;
      bVar1 = true;
    }
    if ((local_6c & 0x90000000) == 0) {
      local_34 = (wchar_t *)0x0;
    }
    else {
      if (!bVar1) goto LAB_404e8078;
      uVar4 = param_2;
      if (param_2 == 0) {
        uVar4 = wcslen(param_1);
      }
      if (uVar4 + 1 < 0x80000000) {
        uBytes = (uVar4 + 1) * 2;
      }
      else {
        uBytes = 0xffffffff;
      }
      _Dst = LocalAlloc(0x40,uBytes);
      local_34 = _Dst;
      if (_Dst == (wchar_t *)0x0) {
        dwErrCode = 8;
        goto LAB_404e87a8;
      }
      memcpy(_Dst,param_1,(uVar4 + 1) * 2);
      param_1 = _Dst;
      local_38 = _Dst;
    }
    uVar4 = local_6c;
    puVar8 = &local_3c;
    if (uVar11 == 0) {
      puVar8 = (uint *)0x0;
      ppuVar7 = (undefined2 **)0x0;
    }
    else {
      ppuVar7 = &local_40;
    }
    dwErrCode = FUN_404e509c(param_1,param_2,(uint)((local_6c & 0x80000000) != 0),&local_30,
                             &local_68,(int *)&local_64,(short *)&local_60,(int *)&local_5c,local_70
                             ,&local_58,&local_54,&local_50,(int *)&local_4c,&local_48,&local_44,
                             ppuVar7,(int *)puVar8,&local_2c);
    uVar11 = local_64;
    if (dwErrCode == 0) {
      bVar1 = false;
      if ((void *)param_4[1] == (void *)0x0) {
        if (param_4[2] != 0) {
          param_4[1] = (int)local_68;
          param_4[2] = local_64;
        }
      }
      else {
        if (local_64 < (uint)param_4[2]) {
          sVar10 = local_64 * 2;
          memcpy((void *)param_4[1],local_68,sVar10);
          *(undefined2 *)(param_4[1] + sVar10) = 0;
          if ((uVar4 & 0x10000000) != 0) {
            UrlUnescapeW((LPWSTR)param_4[1],(LPWSTR)0x0,(LPDWORD)0x0,0x100000);
          }
        }
        else {
          uVar11 = local_64 + 1;
          bVar1 = true;
        }
        param_4[2] = uVar11;
      }
      uVar11 = local_5c;
      if ((void *)param_4[4] == (void *)0x0) {
        if (param_4[5] != 0) {
          param_4[4] = (int)local_60;
          param_4[5] = local_5c;
        }
      }
      else {
        if (local_5c < (uint)param_4[5]) {
          sVar10 = local_5c * 2;
          memcpy((void *)param_4[4],local_60,sVar10);
          *(undefined2 *)(sVar10 + param_4[4]) = 0;
          if ((((uVar4 & 0x10000000) != 0) && (uVar11 != 0)) &&
             ((pWVar6 = (LPWSTR)param_4[4], *pWVar6 != L'[' || (pWVar6[uVar11 - 1] != L']')))) {
            UrlUnescapeW(pWVar6,(LPWSTR)0x0,(LPDWORD)0x0,0x100000);
          }
        }
        else {
          uVar11 = local_5c + 1;
          bVar1 = true;
        }
        param_4[5] = uVar11;
      }
      uVar11 = local_54;
      if ((void *)param_4[7] == (void *)0x0) {
        if (param_4[8] != 0) {
          param_4[7] = (int)local_58;
          param_4[8] = local_54;
        }
      }
      else {
        if (local_54 < (uint)param_4[8]) {
          sVar10 = local_54 * 2;
          memcpy((void *)param_4[7],local_58,sVar10);
          *(undefined2 *)(param_4[7] + sVar10) = 0;
          if ((uVar4 & 0x10000000) != 0) {
            UrlUnescapeW((LPWSTR)param_4[7],(LPWSTR)0x0,(LPDWORD)0x0,0x100000);
          }
        }
        else {
          uVar11 = local_54 + 1;
          bVar1 = true;
        }
        param_4[8] = uVar11;
      }
      uVar11 = local_4c;
      if ((void *)param_4[9] == (void *)0x0) {
        if (param_4[10] != 0) {
          param_4[9] = (int)local_50;
          param_4[10] = local_4c;
        }
      }
      else {
        if (local_4c < (uint)param_4[10]) {
          sVar10 = local_4c * 2;
          memcpy((void *)param_4[9],local_50,sVar10);
          *(undefined2 *)(sVar10 + param_4[9]) = 0;
          if ((uVar4 & 0x10000000) != 0) {
            UrlUnescapeW((LPWSTR)param_4[9],(LPWSTR)0x0,(LPDWORD)0x0,0x100000);
          }
        }
        else {
          uVar11 = local_4c + 1;
          bVar1 = true;
        }
        param_4[10] = uVar11;
      }
      DVar2 = local_44;
      pWVar6 = (LPWSTR)param_4[0xb];
      if (pWVar6 == (LPWSTR)0x0) {
        if (*pcchPath != 0) {
          param_4[0xb] = (int)local_48;
          *pcchPath = local_44;
        }
      }
      else if (local_30 == 5) {
        HVar5 = PathCreateFromUrlW(local_38,pWVar6,pcchPath,0);
        if (HVar5 < 0) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      else if (local_44 < *pcchPath) {
        sVar10 = local_44 * 2;
        memcpy(pWVar6,local_48,sVar10);
        *(undefined2 *)(param_4[0xb] + sVar10) = 0;
        if ((local_6c & 0x10000000) != 0) {
          UrlUnescapeW((LPWSTR)param_4[0xb],(LPWSTR)0x0,(LPDWORD)0x0,0x100000);
        }
        *pcchPath = DVar2;
      }
      else {
        *pcchPath = local_44 + 1;
        bVar1 = true;
      }
      uVar11 = local_3c;
      if ((void *)param_4[0xd] == (void *)0x0) {
        if (param_4[0xe] != 0) {
          param_4[0xd] = (int)local_40;
          param_4[0xe] = local_3c;
        }
      }
      else {
        if (local_3c < (uint)param_4[0xe]) {
          sVar10 = local_3c * 2;
          memcpy((void *)param_4[0xd],local_40,sVar10);
          *(undefined2 *)(sVar10 + param_4[0xd]) = 0;
          if ((local_6c & 0x10000000) != 0) {
            UrlUnescapeW((LPWSTR)param_4[0xd],(LPWSTR)0x0,(LPDWORD)0x0,0x100000);
          }
        }
        else {
          uVar11 = local_3c + 1;
          bVar1 = true;
        }
        param_4[0xe] = uVar11;
      }
      if (bVar1) {
        dwErrCode = 0x7a;
      }
      param_4[3] = local_30;
      if ((local_70[0] == 0) && (local_2c == 0)) {
        if (local_30 == 1) {
          local_70[0] = 0x15;
        }
        else if (local_30 == 2) {
          local_70[0] = 0x46;
        }
        else if (local_30 == 3) {
          local_70[0] = 0x50;
        }
        else if (local_30 == 4) {
          local_70[0] = 0x1bb;
        }
      }
      *(short *)(param_4 + 6) = local_70[0];
    }
    if (local_34 != (wchar_t *)0x0) {
      LocalFree(local_34);
    }
  }
  else {
    dwErrCode = 0x57;
  }
  if (dwErrCode == 0) {
    return true;
  }
LAB_404e87a8:
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* 404e87f4 FUN_404e87f4 */

/* Boundary evidence: original MIPS .pdata 404e87f4..404e884b. Semantic name remains unreviewed. */

void FUN_404e87f4(int param_1)

{
  if (*(int *)(param_1 + 8) == 9) {
    FUN_404e6b8c(param_1);
  }
  else if (*(int *)(param_1 + 8) == 10) {
    FUN_404e37d4(param_1);
  }
  else {
    FUN_404e6be8(param_1);
  }
  return;
}



/* 404e884c FUN_404e884c */

/* Boundary evidence: original MIPS .pdata 404e884c..404e88e7. Semantic name remains unreviewed. */

void FUN_404e884c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 1) {
    FUN_404e6f58(param_1,param_2);
    return;
  }
  if (iVar1 != 2) {
    if (iVar1 == 9) {
      FUN_404e6ca4(param_1,param_2);
      return;
    }
    if (iVar1 == 10) {
      FUN_404e3860(param_1,param_2);
      return;
    }
    if (iVar1 != 0xb) {
      FUN_404e7918(param_1,param_2);
      return;
    }
  }
  FUN_404e7398(param_1,param_2);
  return;
}



/* 404e88e8 FUN_404e88e8 */

/* Boundary evidence: original MIPS .pdata 404e88e8..404e8f33. Semantic name remains unreviewed. */

undefined4 FUN_404e88e8(undefined4 *param_1,undefined4 *param_2,int *param_3,uint param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined3 extraout_var;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  
  bVar2 = false;
  uVar11 = 0;
  bVar1 = false;
  iVar5 = FUN_404e688c((int)param_2,param_3,0);
  iVar6 = 0;
  if ((iVar5 == 0) || ((*param_3 != 9 && ((param_2[3] & 1) == 0)))) {
    iVar6 = FUN_404e688c((int)param_1,param_3,iVar5);
    if ((iVar6 != 0) && (iVar5 == 0)) {
      uVar8 = param_1[3];
      param_2[2] = param_1[2];
      param_2[3] = uVar8;
    }
  }
  else {
    param_1[1] = &DAT_404f430c;
  }
  iVar9 = *param_3;
  if (((iVar9 == 9) || ((iVar5 == 0 && (iVar6 == 0)))) &&
     (((param_4 & 0x10000) != 0 || ((param_4 & 0x80000000) != 0)))) {
    return 0x80004005;
  }
  if (iVar9 == 0) {
    if ((param_4 & 0x40000000) == 0) {
      return 0x80004005;
    }
    param_2[5] = 0;
    bVar3 = FUN_404e683c((int)param_1);
    if ((CONCAT31(extraout_var,bVar3) == 0) || ((undefined *)param_1[1] == &DAT_404f430c)) {
      iVar6 = FUN_404e67c8((int)param_2,0x2f,0x5c,0);
      if (iVar6 == 0) {
        param_2[3] = param_2[3] | 1;
        uVar10 = param_3[7];
        param_3[7] = uVar10 | 1;
        param_3[0xb] = uVar10 & 8;
      }
    }
    else {
      iVar6 = FUN_404e67c8((int)param_1,0x2f,0x5c,0);
      if (iVar6 == 0) {
        iVar6 = FUN_404e67c8((int)param_2,0x3f,0x23,0);
        if (iVar6 == 0) {
          param_1[1] = &DAT_404f430c;
        }
        param_1[3] = param_1[3] | 1;
        param_2[3] = param_2[3] | 1;
        uVar10 = param_3[7];
        param_3[7] = uVar10 | 1;
        param_3[0xb] = uVar10 & 8;
      }
    }
  }
  else if (iVar9 == 1) {
    param_3[0xb] = 0;
  }
  if ((param_4 & 0x8000000) != 0) {
    param_1[5] = 0;
    param_2[5] = 0;
  }
  FUN_404e3560((int)param_3);
  if ((param_3[7] & 1U) == 0) {
    iVar6 = FUN_404e87f4((int)param_2);
    if ((iVar6 == 0) ||
       (((iVar6 = FUN_404e87f4((int)param_1), iVar6 != 0 &&
         (sVar4 = FUN_404e3650((int)param_2), CONCAT22(extraout_var_03,sVar4) != 0x2f)) &&
        (sVar4 = FUN_404e3650((int)param_2), CONCAT22(extraout_var_04,sVar4) != 0x5c)))) {
      iVar6 = FUN_404e87f4((int)param_1);
      if (iVar6 != 0) {
        bVar2 = true;
        FUN_404e884c((int)param_1,(int)param_3);
      }
    }
    else {
      bVar1 = true;
      FUN_404e884c((int)param_2,(int)param_3);
      param_1[1] = &DAT_404f430c;
    }
  }
  if (*param_3 == 9) {
    iVar6 = FUN_404e67c8((int)param_2,0x3f,0,0);
    if (iVar6 == 0) {
      iVar6 = FUN_404e7d2c((int)param_2);
      iVar9 = FUN_404e6608(param_2,(ushort *)param_2[1]);
      if (iVar9 == 0) {
        iVar9 = FUN_404e6608(param_1,(ushort *)param_1[1]);
        if (iVar9 == 0) {
          if (iVar6 == 0) goto LAB_404e8d28;
          if (bVar1) goto LAB_404e8c58;
        }
        else {
          FUN_404e3930((int)param_1,(int)param_3);
          puVar7 = param_1;
          if (iVar6 == 0) goto LAB_404e8c00;
LAB_404e8c58:
          FUN_404e3124((int)param_3,0x2f);
        }
        param_1[1] = &DAT_404f430c;
      }
      else {
        param_1[1] = &DAT_404f430c;
        FUN_404e3930((int)param_2,(int)param_3);
        puVar7 = param_2;
LAB_404e8c00:
        iVar6 = FUN_404e7d2c((int)puVar7);
        if (iVar6 != 0) {
LAB_404e8d1c:
          FUN_404e3124((int)param_3,0x2f);
        }
      }
    }
    else {
      param_1[6] = 1;
    }
  }
  else if (*param_3 == 0) {
    if ((param_3[7] & 1U) == 0) {
      if ((undefined *)param_1[1] == &DAT_404f430c) {
        iVar6 = FUN_404e67c8((int)param_2,0x2f,0x5c,0);
        if (iVar6 != 0) {
LAB_404e8d14:
          if (iVar5 == 0) goto LAB_404e8d1c;
        }
      }
      else {
        iVar6 = FUN_404e67c8((int)param_2,0x2f,0x5c,0);
        if ((iVar6 != 0) ||
           (((bVar3 = FUN_404e683c((int)param_1), CONCAT31(extraout_var_01,bVar3) == 0 &&
             (bVar3 = FUN_404e683c((int)param_2), CONCAT31(extraout_var_02,bVar3) != 0)) &&
            (iVar6 = FUN_404e67c8((int)param_2,0x3f,0,0), iVar6 == 0)))) goto LAB_404e8d14;
      }
    }
    else {
      bVar3 = FUN_404e683c((int)param_2);
      if (CONCAT31(extraout_var_00,bVar3) == 0) {
        param_2[1] = &DAT_404f430c;
      }
    }
  }
LAB_404e8d28:
  FUN_404e3560((int)param_3);
  if ((bVar2) && (iVar6 = FUN_404e7d2c((int)param_2), iVar6 != 0)) {
    if (!bVar1) {
      param_3[9] = param_3[8];
      FUN_404e3560((int)param_3);
    }
LAB_404e8d64:
    iVar5 = FUN_404e3d9c((int)param_2,(undefined4 *)0x0);
    if (iVar5 != 0) {
      param_2[5] = 0;
    }
LAB_404e8d7c:
    iVar5 = 1;
  }
  else {
    iVar6 = FUN_404e7dd0((int)param_1);
    if (iVar6 == 0) {
      iVar5 = FUN_404e7dd0((int)param_2);
      if (iVar5 == 0) goto LAB_404e8d90;
      if (bVar1) goto LAB_404e8d64;
      param_3[9] = param_3[8];
      FUN_404e3560((int)param_3);
      goto LAB_404e8d7c;
    }
    FUN_404e7e4c((int)param_1,param_3,1);
    if ((param_1[3] & 1) != 0) {
      param_2[5] = 0;
LAB_404e8eb4:
      FUN_404e7e4c((int)param_2,param_3,0);
      goto LAB_404e8d90;
    }
    param_3[9] = param_3[8];
    FUN_404e3560((int)param_3);
    iVar6 = FUN_404e7dd0((int)param_2);
    if ((iVar6 == 0) && (iVar6 = FUN_404e67c8((int)param_2,0x3f,0x23,0), iVar6 != 0))
    goto LAB_404e8eb4;
    iVar6 = FUN_404e7dd0((int)param_2);
    if (((iVar6 == 0) && (iVar5 != 0)) || (FUN_404e340c(param_3,0), iVar5 != 0)) {
      param_2[5] = 0;
    }
    iVar5 = 0;
  }
  FUN_404e7e4c((int)param_2,param_3,iVar5);
  param_1[1] = &DAT_404f430c;
LAB_404e8d90:
  param_3[2] = 0;
  param_3[0xb] = 0;
  iVar5 = FUN_404e67c8((int)param_1,0x3f,0x23,0);
  if (iVar5 != 0) {
    FUN_404e3ed4(param_1,(int)param_3);
  }
  iVar5 = FUN_404e67c8((int)param_2,0x3f,0x23,0);
  if (iVar5 != 0) {
    FUN_404e3ed4(param_2,(int)param_3);
  }
  FUN_404e302c((int)param_3,0);
  if (param_3[0xd] != 0) {
    uVar11 = 0x8007000e;
  }
  return uVar11;
}



/* 404e8f34 FUN_404e8f34 */

/* Boundary evidence: original MIPS .pdata 404e8f34..404e9167. Semantic name remains unreviewed. */

int FUN_404e8f34(LPCWSTR param_1,wchar_t *param_2,LPWSTR param_3,LPDWORD param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  DWORD DVar4;
  undefined4 auStack_330 [8];
  undefined4 auStack_310 [8];
  int local_2f0;
  int local_2ec;
  undefined4 local_2e8;
  undefined4 local_2e0;
  undefined4 local_2dc;
  uint local_2d8;
  uint local_2d0;
  uint local_2cc;
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined4 local_2c0;
  undefined4 local_2bc;
  WCHAR aWStack_2b6 [257];
  LPCWSTR local_b4;
  wchar_t awStack_b0 [70];
  uint local_24;
  
  local_24 = DAT_404f4224;
  if (((param_5 & 0x20000000) != 0) && ((param_5 & 0x4000000) != 0)) {
    param_5 = param_5 ^ 0x20000000;
  }
  uVar3 = param_5;
  if ((param_5 & 0x10000000) != 0) {
    if ((param_5 & 0x20000000) != 0) {
      uVar3 = param_5 ^ 0x20000000;
    }
    if ((param_5 & 0x4000000) != 0) {
      uVar3 = uVar3 ^ 0x4000000;
    }
  }
  thunk_FUN_404e361c(auStack_330,(ushort *)param_1,0);
  thunk_FUN_404e361c(auStack_310,(ushort *)param_2,0);
  local_2d8 = 0x100;
  local_b4 = aWStack_2b6;
  local_2ec = 1;
  local_2e8 = 0;
  local_2dc = 0;
  local_2e0 = 0;
  local_2f0 = 0;
  local_2c8 = 0;
  local_2c4 = 1;
  local_2c0 = 0;
  local_2bc = 0;
  local_2d0 = uVar3;
  local_2cc = uVar3;
  iVar1 = FUN_404e88e8(auStack_330,auStack_310,&local_2f0,uVar3);
  iVar2 = local_2ec;
  if (iVar1 < 0) {
    if (iVar1 == -0x7fffbffb) {
      FUN_404f0aec(awStack_b0);
      iVar1 = FUN_404e5a98(param_1,param_2,awStack_b0,param_5);
      if ((-1 < iVar1) && (iVar2 = FUN_404e2604((int)awStack_b0,param_3,param_4), iVar2 != 0)) {
        iVar1 = iVar2;
      }
      FUN_404f0b04(awStack_b0);
    }
  }
  else {
    DVar4 = local_2ec - 1;
    if (((param_5 & 0x10000000) == 0) || ((param_5 & 0x24000000) == 0)) {
      if (*param_4 < DVar4) {
        iVar1 = -0x7fffbffd;
      }
      else if (param_3 != (LPWSTR)0x0) {
        memcpy(param_3,local_b4,DVar4 * 2);
        DVar4 = iVar2 - 2;
      }
      *param_4 = DVar4;
    }
    else {
      iVar1 = UrlEscapeW(local_b4,param_3,param_4,param_5);
    }
  }
  if (0x100 < local_2d8) {
    LocalFree(local_b4);
  }
  FUN_404f1430(local_24);
  return iVar1;
}



/* 404e9168 FUN_404e9168 */

/* Boundary evidence: original MIPS .pdata 404e9168..404e946f. Semantic name remains unreviewed. */

int FUN_404e9168(char *param_1,char *param_2,STRSAFE_LPSTR param_3,uint *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 auStack_580 [8];
  undefined4 auStack_560 [8];
  char acStack_540 [80];
  char acStack_4f0 [80];
  wchar_t awStack_4a0 [66];
  wchar_t *local_41c;
  wchar_t awStack_410 [66];
  LPCWSTR local_38c;
  int local_380 [4];
  undefined4 local_370;
  undefined4 local_36c;
  uint local_368;
  uint local_360;
  uint local_35c;
  undefined4 local_358;
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  WCHAR aWStack_346 [257];
  WCHAR *local_144;
  wchar_t awStack_140 [66];
  LPCWSTR local_bc;
  wchar_t awStack_b0 [66];
  LPCWSTR local_2c;
  uint local_24;
  
  local_24 = DAT_404f4224;
  if (((param_5 & 0x20000000) != 0) && ((param_5 & 0x4000000) != 0)) {
    param_5 = param_5 ^ 0x20000000;
  }
  FUN_404f0aec(awStack_410);
  FUN_404f0aec(awStack_4a0);
  iVar1 = FUN_404f0d94(awStack_410,param_1);
  if ((iVar1 < 0) || (iVar1 = FUN_404f0d94(awStack_4a0,param_2), iVar1 < 0)) {
    FUN_404f0b04(awStack_4a0);
    FUN_404f0b04(awStack_410);
    FUN_404f1430(local_24);
    iVar1 = -0x7ff8fff2;
  }
  else {
    uVar3 = param_5;
    if ((param_5 & 0x10000000) != 0) {
      if ((param_5 & 0x20000000) != 0) {
        uVar3 = param_5 ^ 0x20000000;
      }
      if ((param_5 & 0x4000000) != 0) {
        uVar3 = uVar3 ^ 0x4000000;
      }
    }
    thunk_FUN_404e361c(auStack_580,(ushort *)local_38c,0);
    thunk_FUN_404e361c(auStack_560,(ushort *)local_41c,0);
    local_368 = 0x100;
    local_144 = aWStack_346;
    local_380[1] = 1;
    local_380[2] = 0;
    local_36c = 0;
    local_370 = 0;
    local_380[0] = 0;
    local_358 = 0;
    local_354 = 1;
    local_350 = 0;
    local_34c = 0;
    local_360 = uVar3;
    local_35c = uVar3;
    iVar1 = FUN_404e88e8(auStack_580,auStack_560,local_380,uVar3);
    if (iVar1 < 0) {
      if (iVar1 == -0x7fffbffb) {
        FUN_404f0aec(awStack_b0);
        iVar1 = FUN_404e5a98(local_38c,local_41c,awStack_b0,param_5);
        if (-1 < iVar1) {
          FUN_404f077c(acStack_4f0);
          iVar2 = FUN_404f0a9c(acStack_4f0,local_2c,-1);
          if (iVar2 != 0) {
            iVar1 = iVar2;
          }
          if ((-1 < iVar1) && (iVar2 = FUN_404e24dc((int)acStack_4f0,param_3,param_4), iVar2 != 0))
          {
            iVar1 = iVar2;
          }
          FUN_404f0794(acStack_4f0);
        }
        FUN_404f0b04(awStack_b0);
      }
    }
    else {
      FUN_404f077c(acStack_540);
      if (((param_5 & 0x10000000) == 0) || ((param_5 & 0x24000000) == 0)) {
        iVar1 = FUN_404f0a9c(acStack_540,local_144,-1);
      }
      else {
        FUN_404f0aec(awStack_140);
        iVar1 = FUN_404e5664(local_144,awStack_140,param_5);
        iVar2 = FUN_404f0a9c(acStack_540,local_bc,-1);
        if (iVar2 != 0) {
          iVar1 = iVar2;
        }
        FUN_404f0b04(awStack_140);
      }
      if (-1 < iVar1) {
        iVar1 = FUN_404e24dc((int)acStack_540,param_3,param_4);
      }
      FUN_404f0794(acStack_540);
    }
    if (0x100 < local_368) {
      LocalFree(local_144);
    }
    FUN_404f0b04(awStack_4a0);
    FUN_404f0b04(awStack_410);
    FUN_404f1430(local_24);
  }
  return iVar1;
}



/* 404e9470 UrlCombineW */

/* Boundary evidence: original MIPS .pdata 404e9470..404e94ab. Semantic name remains unreviewed. */

HRESULT UrlCombineW(LPCWSTR pszBase,LPCWSTR pszRelative,LPWSTR pszCombined,LPDWORD pcchCombined,
                   DWORD dwFlags)

{
  int iVar1;
  
                    /* 0x19470  94  UrlCombineW */
  iVar1 = -0x7ff8ffa9;
  if (((pszBase != (LPCWSTR)0x0) && (pszRelative != (LPCWSTR)0x0)) && (pcchCombined != (LPDWORD)0x0)
     ) {
    iVar1 = FUN_404e8f34(pszBase,pszRelative,pszCombined,pcchCombined,dwFlags);
  }
  return iVar1;
}



/* 404e94ac UrlCombineA */

/* Boundary evidence: original MIPS .pdata 404e94ac..404e94f3. Semantic name remains unreviewed. */

HRESULT UrlCombineA(LPCSTR pszBase,LPCSTR pszRelative,LPSTR pszCombined,LPDWORD pcchCombined,
                   DWORD dwFlags)

{
  int iVar1;
  
                    /* 0x194ac  93  UrlCombineA */
  if (((pszBase == (LPCSTR)0x0) || (pszRelative == (LPCSTR)0x0)) || (pcchCombined == (LPDWORD)0x0))
  {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_404e9168(pszBase,pszRelative,pszCombined,pcchCombined,dwFlags);
  }
  return iVar1;
}



/* 404e94f4 UrlCanonicalizeA */

/* Boundary evidence: original MIPS .pdata 404e94f4..404e95af. Semantic name remains unreviewed. */

HRESULT UrlCanonicalizeA(LPCSTR pszUrl,LPSTR pszCanonicalized,LPDWORD pcchCanonicalized,
                        DWORD dwFlags)

{
  int iVar1;
  undefined1 auStack_68 [76];
  uint local_1c;
  
                    /* 0x194f4  91  UrlCanonicalizeA */
  local_1c = DAT_404f4224;
  FUN_404f077c(auStack_68);
  if ((((pszUrl == (LPCSTR)0x0) || (pszCanonicalized == (LPSTR)0x0)) ||
      (pcchCanonicalized == (LPDWORD)0x0)) || (*pcchCanonicalized == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_404e9168("",pszUrl,pszCanonicalized,pcchCanonicalized,dwFlags);
  }
  FUN_404f0794(auStack_68);
  FUN_404f1430(local_1c);
  return iVar1;
}



/* 404e95b0 UrlCanonicalizeW */

/* Boundary evidence: original MIPS .pdata 404e95b0..404e976b. Semantic name remains unreviewed. */

HRESULT UrlCanonicalizeW(LPCWSTR pszUrl,LPWSTR pszCanonicalized,LPDWORD pcchCanonicalized,
                        DWORD dwFlags)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  DWORD DVar4;
  undefined2 auStack_b8 [70];
  uint local_2c;
  
                    /* 0x195b0  92  UrlCanonicalizeW */
  local_2c = DAT_404f4224;
  FUN_404f0aec(auStack_b8);
  if ((((pszUrl == (LPCWSTR)0x0) || (pszCanonicalized == (LPWSTR)0x0)) ||
      (pcchCanonicalized == (LPDWORD)0x0)) || (*pcchCanonicalized == 0)) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    LVar1 = InterlockedExchange((LONG *)&DAT_404f4304,1);
    if (LVar1 == 0) {
      iVar3 = -0x7fffbffb;
      if (((DAT_404f4280 == dwFlags) && ((dwFlags & 0x1000) == 0)) &&
         (iVar2 = StrCmpCW((ushort *)pszUrl,(ushort *)&DAT_404f4284), iVar2 == 0)) {
        DVar4 = *pcchCanonicalized;
        iVar3 = FUN_404e2570((wchar_t *)&DAT_404f4284,pszCanonicalized,pcchCanonicalized);
        if (iVar3 < 0) {
          *pcchCanonicalized = DVar4;
        }
      }
      InterlockedExchange((LONG *)&DAT_404f4304,0);
      if (-1 < iVar3) goto LAB_404e972c;
    }
    iVar3 = FUN_404e8f34(L"",pszUrl,pszCanonicalized,pcchCanonicalized,dwFlags);
    if (((-1 < iVar3) && (*pcchCanonicalized < 0x40)) &&
       (LVar1 = InterlockedExchange((LONG *)&DAT_404f4304,1), LVar1 == 0)) {
      StringCchCopyW((STRSAFE_LPWSTR)&DAT_404f4284,0x40,pszCanonicalized);
      DAT_404f4280 = dwFlags;
      InterlockedExchange((LONG *)&DAT_404f4304,0);
    }
  }
LAB_404e972c:
  FUN_404f0b04(auStack_b8);
  FUN_404f1430(local_2c);
  return iVar3;
}



/* 404e976c PathGetArgsW */

LPWSTR PathGetArgsW(LPCWSTR pszPath)

{
  WCHAR WVar1;
  bool bVar2;
  
                    /* 0x1976c  16  PathGetArgsW */
  if (pszPath != (LPCWSTR)0x0) {
    bVar2 = false;
    for (; WVar1 = *pszPath, WVar1 != L'\0'; pszPath = pszPath + 1) {
      if (WVar1 == L'\"') {
        if (bVar2) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
      }
      else if ((!bVar2) && (WVar1 == L' ')) {
        return pszPath + 1;
      }
    }
  }
  return pszPath;
}



/* 404e97dc PathRemoveArgsW */

/* Boundary evidence: original MIPS .pdata 404e97dc..404e983f. Semantic name remains unreviewed. */

void PathRemoveArgsW(LPWSTR pszPath)

{
  LPWSTR pWVar1;
  
                    /* 0x197dc  21  PathRemoveArgsW */
  if (pszPath != (LPWSTR)0x0) {
    pWVar1 = PathGetArgsW(pszPath);
    if (*pWVar1 == L'\0') {
      pWVar1 = CharPrevW(pszPath,pWVar1);
      if (*pWVar1 == L' ') {
        *pWVar1 = L'\0';
      }
    }
    else {
      pWVar1[-1] = L'\0';
    }
  }
  return;
}



/* 404e9840 PathFileExistsW */

/* Boundary evidence: original MIPS .pdata 404e9840..404e9887. Semantic name remains unreviewed. */

BOOL PathFileExistsW(LPCWSTR pszPath)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* 0x19840  10  PathFileExistsW */
  BVar1 = 0;
  if (pszPath != (LPCWSTR)0x0) {
    DVar2 = GetFileAttributesW(pszPath);
    if (DVar2 == 0xffffffff) {
      BVar1 = 0;
    }
    else {
      BVar1 = 1;
    }
  }
  return BVar1;
}



/* 404e9888 PathFindExtensionW */

LPWSTR PathFindExtensionW(LPCWSTR pszPath)

{
  LPWSTR pWVar1;
  LPWSTR pWVar2;
  WCHAR WVar3;
  
                    /* 0x19888  12  PathFindExtensionW */
  if ((pszPath != (LPCWSTR)0x0) && (WVar3 = *pszPath, pWVar1 = (LPWSTR)0x0, WVar3 != L'\0')) {
    do {
      if ((WVar3 == L' ') ||
         ((pWVar2 = pszPath, WVar3 != L'.' && (pWVar2 = pWVar1, WVar3 == L'\\')))) {
        pWVar2 = (LPWSTR)0x0;
      }
      pszPath = pszPath + 1;
      WVar3 = *pszPath;
      pWVar1 = pWVar2;
    } while (WVar3 != L'\0');
    if (pWVar2 != (LPWSTR)0x0) {
      return pWVar2;
    }
  }
  return pszPath;
}



/* 404e98f0 PathRemoveExtensionW */

/* Boundary evidence: original MIPS .pdata 404e98f0..404e9923. Semantic name remains unreviewed. */

void PathRemoveExtensionW(LPWSTR pszPath)

{
  LPWSTR pWVar1;
  
                    /* 0x198f0  25  PathRemoveExtensionW */
  if ((pszPath != (LPWSTR)0x0) && (pWVar1 = PathFindExtensionW(pszPath), *pWVar1 != L'\0')) {
    *pWVar1 = L'\0';
  }
  return;
}



/* 404e9924 PathRenameExtensionW */

/* Boundary evidence: original MIPS .pdata 404e9924..404e99b3. Semantic name remains unreviewed. */

BOOL PathRenameExtensionW(LPWSTR pszPath,LPCWSTR pszExt)

{
  LPWSTR pszDest;
  size_t sVar1;
  int iVar2;
  
                    /* 0x19924  28  PathRenameExtensionW */
  if ((pszPath != (LPWSTR)0x0) && (pszExt != (LPCWSTR)0x0)) {
    pszDest = PathFindExtensionW(pszPath);
    sVar1 = wcslen(pszExt);
    iVar2 = (int)pszDest - (int)pszPath >> 1;
    if (iVar2 + sVar1 + 1 < 0x105) {
      StringCchCopyW(pszDest,0x104 - iVar2,pszExt);
      return 1;
    }
  }
  return 0;
}



/* 404e99b4 PathCommonPrefixW */

/* Boundary evidence: original MIPS .pdata 404e99b4..404e9b87. Semantic name remains unreviewed. */

int PathCommonPrefixW(LPCWSTR pszFile1,LPCWSTR pszFile2,LPWSTR achPath)

{
  WCHAR WVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  LPCWSTR pWVar4;
  PCNZWCH pWVar5;
  WCHAR *pWVar6;
  WCHAR *pWVar7;
  
                    /* 0x199b4  6  PathCommonPrefixW */
  if ((pszFile1 == (LPCWSTR)0x0) || (pszFile2 == (LPCWSTR)0x0)) {
LAB_404e9b5c:
    iVar3 = 0;
  }
  else {
    pWVar7 = (WCHAR *)0x0;
    if (achPath != (LPWSTR)0x0) {
      *achPath = L'\0';
    }
    pWVar4 = pszFile1;
    if ((*pszFile1 == L'\\') && (pszFile1[1] == L'\\')) {
      if ((*pszFile2 != L'\\') || (pszFile2[1] != L'\\')) goto LAB_404e9b5c;
      pWVar4 = pszFile1 + 2;
    }
    if ((*pszFile2 == L'\\') && (pszFile2[1] == L'\\')) {
      if ((*pszFile1 != L'\\') || (pszFile1[1] != L'\\')) goto LAB_404e9b5c;
      pszFile2 = pszFile2 + 2;
    }
    while( true ) {
      WVar1 = *pWVar4;
      pWVar5 = pWVar4;
      while ((WVar1 != L'\0' && (WVar1 != L'\\'))) {
        pWVar5 = pWVar5 + 1;
        WVar1 = *pWVar5;
      }
      WVar1 = *pszFile2;
      pWVar6 = pszFile2;
      while ((WVar1 != L'\0' && (WVar1 != L'\\'))) {
        pWVar6 = pWVar6 + 1;
        WVar1 = *pWVar6;
      }
      iVar3 = (int)pWVar5 - (int)pWVar4 >> 1;
      if ((((iVar3 != (int)pWVar6 - (int)pszFile2 >> 1) ||
           (bVar2 = FUN_404ee1b0(0,pWVar4,pszFile2,iVar3), CONCAT31(extraout_var,bVar2) == 0)) ||
          (pWVar7 = pWVar5, *pWVar5 == L'\0')) || (pWVar4 = pWVar5 + 1, *pWVar6 == L'\0')) break;
      pszFile2 = pWVar6 + 1;
    }
    if (pWVar7 == (WCHAR *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (int)pWVar7 - (int)pszFile1 >> 1;
      if (iVar3 == 2) {
        iVar3 = 3;
      }
    }
    if ((achPath != (LPWSTR)0x0) && (iVar3 < 0x104)) {
      memcpy(achPath,pszFile1,iVar3 * 2);
      achPath[iVar3] = L'\0';
    }
  }
  return iVar3;
}



/* 404e9b88 FUN_404e9b88 */

/* Boundary evidence: original MIPS .pdata 404e9b88..404e9bcb. Semantic name remains unreviewed. */

LPWSTR FUN_404e9b88(LPCWSTR param_1)

{
  LPWSTR pWVar1;
  size_t sVar2;
  
  pWVar1 = StrChrW(param_1,L'\\');
  if (pWVar1 == (LPWSTR)0x0) {
    sVar2 = wcslen(param_1);
    pWVar1 = param_1 + sVar2;
  }
  return pWVar1;
}



/* 404e9bcc FUN_404e9bcc */

void FUN_404e9bcc(short *param_1,int param_2)

{
  if (*param_1 == 0) {
    *param_1 = 0x5c;
    param_1[1] = 0;
  }
  if ((param_1[1] == 0x3a) && (param_1[2] == 0)) {
    param_1[2] = 0x5c;
    param_1[3] = 0;
  }
  if (((param_2 != 0) && (*param_1 == 0x5c)) && (param_1[1] == 0)) {
    param_1[1] = 0x5c;
    param_1[2] = 0;
  }
  return;
}



/* 404e9c34 PathRemoveFileSpecW */

BOOL PathRemoveFileSpecW(LPWSTR pszPath)

{
  WCHAR WVar1;
  LPWSTR pWVar2;
  LPWSTR pWVar3;
  LPWSTR pWVar4;
  
                    /* 0x19c34  27  PathRemoveFileSpecW */
  if (pszPath != (LPWSTR)0x0) {
    pWVar4 = pszPath;
    pWVar2 = pszPath;
    WVar1 = *pszPath;
    while (WVar1 != L'\0') {
      pWVar3 = pWVar4;
      if ((*pWVar4 != L'\\') && (pWVar3 = pWVar2, *pWVar4 == L':')) {
        if (pWVar4[1] == L'\\') {
          pWVar4 = pWVar4 + 1;
        }
        pWVar3 = pWVar4 + 1;
      }
      pWVar4 = pWVar4 + 1;
      pWVar2 = pWVar3;
      WVar1 = *pWVar4;
    }
    WVar1 = *pWVar2;
    if (WVar1 != L'\0') {
      if (((pWVar2 == pszPath) && (WVar1 == L'\\')) ||
         ((pWVar2 == pszPath + 1 && ((WVar1 == L'\\' && (*pszPath == L'\\')))))) {
        if (pWVar2[1] == L'\0') {
          return 0;
        }
        pWVar2[1] = L'\0';
      }
      else {
        *pWVar2 = L'\0';
      }
      return 1;
    }
  }
  return 0;
}



/* 404e9d08 PathAddBackslashW */

/* Boundary evidence: original MIPS .pdata 404e9d08..404e9d97. Semantic name remains unreviewed. */

LPWSTR PathAddBackslashW(LPWSTR pszPath)

{
  size_t sVar1;
  LPWSTR pWVar2;
  LPWSTR lpszCurrent;
  
                    /* 0x19d08  3  PathAddBackslashW */
  lpszCurrent = (LPWSTR)0x0;
  if (pszPath != (LPWSTR)0x0) {
    sVar1 = wcslen(pszPath);
    lpszCurrent = pszPath + sVar1;
    if ((sVar1 != 0) && (pWVar2 = CharPrevW(pszPath,lpszCurrent), *pWVar2 != L'\\')) {
      if ((int)sVar1 < 0x102) {
        *lpszCurrent = L'\\';
        lpszCurrent = lpszCurrent + 1;
        *lpszCurrent = L'\0';
      }
      else {
        lpszCurrent = (LPWSTR)0x0;
      }
    }
  }
  return lpszCurrent;
}



/* 404e9d98 PathFindFileNameW */

LPWSTR PathFindFileNameW(LPCWSTR pszPath)

{
  WCHAR WVar1;
  WCHAR *pWVar2;
  
                    /* 0x19d98  14  PathFindFileNameW */
  if (pszPath != (LPCWSTR)0x0) {
    WVar1 = *pszPath;
    pWVar2 = pszPath;
    while (WVar1 != L'\0') {
      if (((WVar1 == L'\\') || (WVar1 == L':')) || (WVar1 == L'/')) {
        WVar1 = pWVar2[1];
        if (((WVar1 != L'\0') && (WVar1 != L'\\')) && (WVar1 != L'/')) {
          pszPath = pWVar2 + 1;
        }
      }
      pWVar2 = pWVar2 + 1;
      WVar1 = *pWVar2;
    }
  }
  return pszPath;
}



/* 404e9e18 PathIsUNCW */

BOOL PathIsUNCW(LPCWSTR pszPath)

{
  BOOL BVar1;
  
                    /* 0x19e18  18  PathIsUNCW */
  if (((pszPath == (LPCWSTR)0x0) || (*pszPath != L'\\')) || (BVar1 = 1, pszPath[1] != L'\\')) {
    BVar1 = 0;
  }
  return BVar1;
}



/* 404e9e48 FUN_404e9e48 */

/* Boundary evidence: original MIPS .pdata 404e9e48..404e9f37. Semantic name remains unreviewed. */

undefined4 FUN_404e9e48(short *param_1)

{
  WCHAR WVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  
  if ((param_1 == (short *)0x0) || (*param_1 == 0)) {
LAB_404e9f20:
    uVar4 = 0;
  }
  else {
    iVar3 = lstrcmpiW(param_1 + 1,L":\\");
    if (iVar3 != 0) {
      if (*param_1 != 0x5c) goto LAB_404e9f20;
      WVar1 = param_1[1];
      if (WVar1 != L'\0') {
        if (WVar1 != L'\\') goto LAB_404e9f20;
        psVar5 = param_1 + 2;
        iVar3 = 0;
        sVar2 = *psVar5;
        while (sVar2 != 0) {
          if ((sVar2 == 0x5c) && ((iVar3 = iVar3 + 1, 1 < iVar3 || (psVar5[1] == 0))))
          goto LAB_404e9f20;
          psVar5 = psVar5 + 1;
          sVar2 = *psVar5;
        }
      }
    }
    uVar4 = 1;
  }
  return uVar4;
}



/* 404e9f38 PathUnquoteSpacesW */

/* Boundary evidence: original MIPS .pdata 404e9f38..404e9fa3. Semantic name remains unreviewed. */

BOOL PathUnquoteSpacesW(LPWSTR lpsz)

{
  void *in_v0;
  
                    /* 0x19f38  35  PathUnquoteSpacesW */
  if (((lpsz != (LPWSTR)0x0) && (in_v0 = (void *)wcslen(lpsz), *lpsz == L'\"')) &&
     (lpsz[(int)in_v0 - 1] == L'\"')) {
    lpsz[(int)in_v0 - 1] = L'\0';
    in_v0 = memmove(lpsz,lpsz + 1,((int)in_v0 - 1U) * 2);
  }
  return (BOOL)in_v0;
}



/* 404e9fa4 PathQuoteSpacesW */

/* Boundary evidence: original MIPS .pdata 404e9fa4..404ea02b. Semantic name remains unreviewed. */

BOOL PathQuoteSpacesW(LPWSTR lpsz)

{
  void *in_v0;
  LPWSTR pWVar1;
  int iVar2;
  
                    /* 0x19fa4  20  PathQuoteSpacesW */
  if ((lpsz != (LPWSTR)0x0) &&
     (pWVar1 = StrChrW(lpsz,L' '), in_v0 = (void *)0x0, pWVar1 != (LPWSTR)0x0)) {
    in_v0 = (void *)wcslen(lpsz);
    iVar2 = (int)in_v0 + 1;
    if ((int)((int)in_v0 + 2U) < 0x104) {
      in_v0 = memmove(lpsz + 1,lpsz,iVar2 * 2);
      *lpsz = L'\"';
      lpsz[iVar2] = L'\"';
      (lpsz + iVar2)[1] = L'\0';
    }
  }
  return (BOOL)in_v0;
}



/* 404ea02c PathIsURLW */

/* Boundary evidence: original MIPS .pdata 404ea02c..404ea06b. Semantic name remains unreviewed. */

BOOL PathIsURLW(LPCWSTR pszPath)

{
  HRESULT HVar1;
  PARSEDURLW local_20;
  
                    /* 0x1a02c  19  PathIsURLW */
  if (pszPath != (LPCWSTR)0x0) {
    local_20.cbSize = 0x18;
    HVar1 = ParseURLW(pszPath,&local_20);
    if (-1 < HVar1) {
      return 1;
    }
  }
  return 0;
}



/* 404ea06c PathUndecorateW */

/* Boundary evidence: original MIPS .pdata 404ea06c..404ea153. Semantic name remains unreviewed. */

void PathUndecorateW(LPWSTR pszPath)

{
  LPWSTR _Str;
  size_t sVar1;
  LPWSTR _Dst;
  
                    /* 0x1a06c  31  PathUndecorateW */
  if ((((pszPath != (LPWSTR)0x0) && (_Str = PathFindExtensionW(pszPath), pszPath < _Str)) &&
      (_Dst = _Str + -2, _Str[-1] == L']')) && (pszPath < _Dst)) {
    do {
      if (((ushort)*_Dst < 0x30) || (0x39 < (ushort)*_Dst)) break;
      _Dst = _Dst + -1;
    } while (pszPath < _Dst);
    if (((*_Dst == L'[') && (pszPath < _Dst)) && (_Dst[-1] != L'\\')) {
      sVar1 = wcslen(_Str);
      memmove(_Dst,_Str,(sVar1 + 1) * 2);
    }
  }
  return;
}



/* 404ea154 PathRemoveBackslashW */

/* Boundary evidence: original MIPS .pdata 404ea154..404ea1d3. Semantic name remains unreviewed. */

LPWSTR PathRemoveBackslashW(LPWSTR pszPath)

{
  size_t sVar1;
  int iVar2;
  LPWSTR pWVar3;
  
                    /* 0x1a154  23  PathRemoveBackslashW */
  if (pszPath == (LPWSTR)0x0) {
    pWVar3 = (LPWSTR)0x0;
  }
  else {
    sVar1 = wcslen(pszPath);
    pWVar3 = pszPath + (sVar1 - 1);
    CharPrevW(pszPath,pWVar3 + 1);
    iVar2 = FUN_404e9e48(pszPath);
    if ((iVar2 == 0) && (*pWVar3 == L'\\')) {
      *pWVar3 = L'\0';
    }
  }
  return pWVar3;
}



/* 404ea1d4 PathCanonicalizeW */

/* Boundary evidence: original MIPS .pdata 404ea1d4..404ea40f. Semantic name remains unreviewed. */

BOOL PathCanonicalizeW(LPWSTR pszBuf,LPCWSTR pszPath)

{
  WCHAR WVar1;
  LPWSTR pWVar2;
  HRESULT HVar3;
  int iVar4;
  STRSAFE_LPWSTR pwVar5;
  size_t cchToCopy;
  LPCWSTR pWVar6;
  BOOL BVar7;
  int iVar8;
  
                    /* 0x1a1d4  4  PathCanonicalizeW */
  if ((pszBuf == (LPWSTR)0x0) || (pszPath == (LPCWSTR)0x0)) {
    SetLastError(0x57);
LAB_404ea3d8:
    BVar7 = 0;
  }
  else {
    *pszBuf = L'\0';
    WVar1 = *pszPath;
    BVar7 = 1;
    pwVar5 = pszBuf;
    if ((WVar1 != L'\\') || (iVar8 = 1, pszPath[1] != L'\\')) {
      iVar8 = 0;
    }
    while (WVar1 != L'\0') {
      pWVar2 = FUN_404e9b88(pszPath);
      cchToCopy = (int)pWVar2 - (int)pszPath >> 1;
      if (cchToCopy == 0) {
        if (*pszPath != L'\\') goto LAB_404ea36c;
        HVar3 = StringCchCopyW(pwVar5,(int)pszBuf + (0x208 - (int)pwVar5) >> 1,L"\\");
        if (HVar3 < 0) goto LAB_404ea3d8;
        pwVar5 = pwVar5 + 1;
        pWVar6 = pszPath + 1;
      }
      else {
        if (cchToCopy == 1) {
          if (*pszPath == L'.') {
            pWVar6 = pszPath + 1;
            if (*pWVar6 == L'\0') {
              if ((pszBuf < pwVar5) && (iVar4 = FUN_404e9e48(pszBuf), iVar4 == 0)) {
                pwVar5 = pwVar5 + -1;
              }
              goto LAB_404ea3a4;
            }
LAB_404ea364:
            pWVar6 = pszPath + 2;
            goto LAB_404ea3a4;
          }
        }
        else if (((cchToCopy == 2) && (*pszPath == L'.')) && (pszPath[1] == L'.')) {
          iVar4 = FUN_404e9e48(pszBuf);
          if (iVar4 == 0) {
            pwVar5 = StrRChrW(pszBuf,pwVar5 + -1,L'\\');
            if (pwVar5 == (LPWSTR)0x0) {
              pwVar5 = pszBuf;
            }
          }
          else if (pszPath[2] == L'\\') {
            pszPath = pszPath + 1;
          }
          goto LAB_404ea364;
        }
LAB_404ea36c:
        HVar3 = StringCchCopyNW(pwVar5,(int)pszBuf + (0x208 - (int)pwVar5) >> 1,pszPath,cchToCopy);
        if (HVar3 < 0) goto LAB_404ea3d8;
        pwVar5 = pwVar5 + cchToCopy;
        pWVar6 = pszPath + cchToCopy;
      }
LAB_404ea3a4:
      *pwVar5 = L'\0';
      pszPath = pWVar6;
      WVar1 = *pWVar6;
    }
    FUN_404e9bcc(pszBuf,iVar8);
  }
  return BVar7;
}



/* 404ea410 FUN_404ea410 */

/* Boundary evidence: original MIPS .pdata 404ea410..404ea463. Semantic name remains unreviewed. */

undefined4 FUN_404ea410(LPWSTR param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  pWVar1 = param_1;
  while( true ) {
    if (pWVar1 == (LPWSTR)0x0) {
      return 0;
    }
    iVar2 = FUN_404e9e48(param_1);
    if (iVar2 != 0) break;
    pWVar1 = (LPWSTR)PathRemoveFileSpecW(param_1);
  }
  return 1;
}



/* 404ea464 PathCombineW */

/* Boundary evidence: original MIPS .pdata 404ea464..404ea66b. Semantic name remains unreviewed. */

LPWSTR PathCombineW(LPWSTR pszDest,LPCWSTR pszDir,LPCWSTR pszFile)

{
  WCHAR WVar1;
  LPWSTR pszDest_00;
  size_t sVar2;
  BOOL BVar3;
  LPCWSTR pWVar4;
  size_t cchDest;
  wchar_t local_228 [260];
  uint local_20;
  
                    /* 0x1a464  5  PathCombineW */
  local_20 = DAT_404f4224;
  if (pszDest == (LPWSTR)0x0) goto LAB_404ea640;
  local_228[0] = L'\0';
  pWVar4 = pszFile;
  if ((pszDir == (LPCWSTR)0x0) || (*pszDir == L'\0')) {
    if ((pszFile != (LPCWSTR)0x0) && (*pszFile != L'\0')) {
LAB_404ea5cc:
      pszDest_00 = local_228;
      cchDest = 0x104;
      goto LAB_404ea5d8;
    }
  }
  else if ((pszFile == (LPCWSTR)0x0) || (WVar1 = *pszFile, WVar1 == L'\0')) {
    cchDest = 0x104;
    pszDest_00 = local_228;
    pWVar4 = pszDir;
LAB_404ea5d8:
    StringCchCopyW(pszDest_00,cchDest,pWVar4);
  }
  else {
    if (WVar1 == L'\\') {
LAB_404ea548:
      if (pszFile[1] == L'\\') goto LAB_404ea5cc;
      StringCchCopyW(local_228,0x104,pszDir);
      FUN_404ea410(local_228);
      pszDest_00 = PathAddBackslashW(local_228);
      if (pszDest_00 != (LPWSTR)0x0) {
        cchDest = 0x104 - ((int)pszDest_00 - (int)local_228 >> 1);
        pWVar4 = pszFile + 1;
        goto LAB_404ea5d8;
      }
    }
    else {
      if (pszFile[1] == L':') {
        if (WVar1 != L'\\') goto LAB_404ea5cc;
        goto LAB_404ea548;
      }
      StringCchCopyW(local_228,0x104,pszDir);
      pszDest_00 = PathAddBackslashW(local_228);
      if (pszDest_00 != (LPWSTR)0x0) {
        cchDest = 0x104 - ((int)pszDest_00 - (int)local_228 >> 1);
        sVar2 = wcslen(pszFile);
        if ((int)sVar2 < (int)cchDest) goto LAB_404ea5d8;
      }
    }
    local_228[0] = L'\0';
  }
  if (local_228[0] == L'\0') {
    if (pszDir == (LPCWSTR)0x0) {
      if (pszFile != (LPCWSTR)0x0) {
LAB_404ea610:
        if ((pszFile == (LPCWSTR)0x0) || (*pszFile == L'\0')) goto LAB_404ea624;
      }
    }
    else if (*pszDir == L'\0') goto LAB_404ea610;
  }
  else {
LAB_404ea624:
    BVar3 = PathCanonicalizeW(pszDest,local_228);
    if (BVar3 != 0) goto LAB_404ea640;
  }
  *pszDest = L'\0';
  pszDest = (LPWSTR)0x0;
LAB_404ea640:
  FUN_404f1430(local_20);
  return pszDest;
}



/* 404ea66c FUN_404ea66c */

/* Boundary evidence: original MIPS .pdata 404ea66c..404ea737. Semantic name remains unreviewed. */

BYTE * FUN_404ea66c(UINT param_1,BYTE *param_2,BYTE *param_3)

{
  bool bVar1;
  BOOL BVar2;
  BYTE *pBVar3;
  BYTE *pBVar4;
  BYTE *pBVar5;
  
  pBVar3 = param_3;
  if (param_2 < param_3) {
    pBVar5 = param_3 + -2;
    bVar1 = false;
    pBVar3 = param_3 + -1;
    pBVar4 = pBVar5;
    if (param_2 <= pBVar5) {
      do {
        BVar2 = IsDBCSLeadByteEx(param_1,*pBVar4);
        if (BVar2 == 0) break;
        bVar1 = !bVar1;
        pBVar4 = pBVar4 + -1;
      } while (param_2 <= pBVar4);
      if (bVar1) {
        pBVar3 = pBVar5;
      }
    }
  }
  return pBVar3;
}



/* 404ea738 PathFindExtensionA */

LPSTR PathFindExtensionA(LPCSTR pszPath)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  
                    /* 0x1a738  11  PathFindExtensionA */
  if ((pszPath != (LPCSTR)0x0) && (cVar3 = *pszPath, pcVar1 = (char *)0x0, cVar3 != '\0')) {
    do {
      if ((cVar3 == ' ') || ((pcVar2 = pszPath, cVar3 != '.' && (pcVar2 = pcVar1, cVar3 == '\\'))))
      {
        pcVar2 = (char *)0x0;
      }
      pszPath = pszPath + 1;
      cVar3 = *pszPath;
      pcVar1 = pcVar2;
    } while (cVar3 != '\0');
    if (pcVar2 != (char *)0x0) {
      return pcVar2;
    }
  }
  return pszPath;
}



/* 404ea7a8 PathRemoveFileSpecA */

BOOL PathRemoveFileSpecA(LPSTR pszPath)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
                    /* 0x1a7a8  26  PathRemoveFileSpecA */
  if (pszPath != (LPSTR)0x0) {
    pcVar4 = pszPath;
    pcVar2 = pszPath;
    cVar1 = *pszPath;
    while (cVar1 != '\0') {
      pcVar3 = pcVar4;
      if ((*pcVar4 != '\\') && (pcVar3 = pcVar2, *pcVar4 == ':')) {
        if (pcVar4[1] == '\\') {
          pcVar4 = pcVar4 + 1;
        }
        pcVar3 = pcVar4 + 1;
      }
      pcVar4 = pcVar4 + 1;
      pcVar2 = pcVar3;
      cVar1 = *pcVar4;
    }
    cVar1 = *pcVar2;
    if (cVar1 != '\0') {
      if (((pcVar2 == pszPath) && (cVar1 == '\\')) ||
         ((pcVar2 == pszPath + 1 && ((cVar1 == '\\' && (*pszPath == '\\')))))) {
        if (pcVar2[1] == '\0') {
          return 0;
        }
        pcVar2[1] = '\0';
      }
      else {
        *pcVar2 = '\0';
      }
      return 1;
    }
  }
  return 0;
}



/* 404ea87c FUN_404ea87c */

/* Boundary evidence: original MIPS .pdata 404ea87c..404ea90f. Semantic name remains unreviewed. */

BYTE * FUN_404ea87c(BYTE *param_1)

{
  size_t sVar1;
  BYTE *pBVar2;
  BYTE *pBVar3;
  
  pBVar3 = (BYTE *)0x0;
  if (param_1 != (BYTE *)0x0) {
    sVar1 = strlen((char *)param_1);
    pBVar3 = param_1 + sVar1;
    if ((sVar1 != 0) && (pBVar2 = FUN_404ea66c(0,param_1,pBVar3), *pBVar2 != '\\')) {
      if ((int)sVar1 < 0x102) {
        *pBVar3 = '\\';
        pBVar3 = pBVar3 + 1;
        *pBVar3 = '\0';
      }
      else {
        pBVar3 = (BYTE *)0x0;
      }
    }
  }
  return pBVar3;
}



/* 404ea910 PathIsUNCServerA */

BOOL PathIsUNCServerA(LPCSTR pszPath)

{
  int iVar1;
  
                    /* 0x1a910  17  PathIsUNCServerA */
  if (((pszPath != (LPCSTR)0x0) && (*pszPath == '\\')) && (pszPath[1] == '\\')) {
    iVar1 = 0;
    do {
      if (*pszPath == '\0') break;
      if (*pszPath == '\\') {
        iVar1 = iVar1 + 1;
      }
      pszPath = pszPath + 1;
    } while (pszPath != (char *)0x0);
    if (iVar1 == 2) {
      return 1;
    }
  }
  return 0;
}



/* 404ea978 FUN_404ea978 */

/* Boundary evidence: original MIPS .pdata 404ea978..404eaa73. Semantic name remains unreviewed. */

undefined4 FUN_404ea978(BYTE *param_1)

{
  BYTE BVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  BYTE *pBVar5;
  
  if ((param_1 == (BYTE *)0x0) || (*param_1 == '\0')) {
LAB_404eaa60:
    uVar4 = 0;
  }
  else {
    BVar2 = IsDBCSLeadByte(*param_1);
    if ((BVar2 != 0) || (iVar3 = _stricmp((char *)(param_1 + 1),":\\"), iVar3 != 0)) {
      if (*param_1 != '\\') goto LAB_404eaa60;
      if (param_1[1] != '\0') {
        if (param_1[1] != '\\') goto LAB_404eaa60;
        pBVar5 = param_1 + 2;
        iVar3 = 0;
        BVar1 = *pBVar5;
        while (BVar1 != '\0') {
          if ((BVar1 == '\\') && ((iVar3 = iVar3 + 1, 1 < iVar3 || (pBVar5[1] == '\0'))))
          goto LAB_404eaa60;
          pBVar5 = pBVar5 + 1;
          BVar1 = *pBVar5;
        }
      }
    }
    uVar4 = 1;
  }
  return uVar4;
}



/* 404eaa74 PathRemoveBackslashA */

/* Boundary evidence: original MIPS .pdata 404eaa74..404eab17. Semantic name remains unreviewed. */

LPSTR PathRemoveBackslashA(LPSTR pszPath)

{
  size_t sVar1;
  BYTE *pBVar2;
  BOOL BVar3;
  int iVar4;
  LPSTR pCVar5;
  int iVar6;
  
                    /* 0x1aa74  22  PathRemoveBackslashA */
  if (pszPath == (LPSTR)0x0) {
    pCVar5 = (LPSTR)0x0;
  }
  else {
    sVar1 = strlen(pszPath);
    iVar6 = sVar1 - 1;
    pBVar2 = FUN_404ea66c(0,(BYTE *)pszPath,(BYTE *)(pszPath + sVar1));
    BVar3 = IsDBCSLeadByte(*pBVar2);
    if (BVar3 != 0) {
      iVar6 = sVar1 - 2;
    }
    iVar4 = FUN_404ea978((BYTE *)pszPath);
    if ((iVar4 == 0) && (pszPath[iVar6] == '\\')) {
      pszPath[iVar6] = '\0';
    }
    pCVar5 = pszPath + iVar6;
  }
  return pCVar5;
}



/* 404eab18 QISearch */

/* Boundary evidence: original MIPS .pdata 404eab18..404eac2b. Semantic name remains unreviewed. */

HRESULT QISearch(void *that,LPCQITAB pqit,IID *riid,void **ppv)

{
  HRESULT HVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  IID *pIVar5;
  LPCQITAB pQVar6;
  int *piVar7;
  
                    /* 0x1ab18  219  QISearch */
  if (ppv == (void **)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else {
    pIVar5 = pqit->piid;
    if (pIVar5 != (IID *)0x0) {
      pQVar6 = pqit;
      do {
        if ((((riid->Data1 == pIVar5->Data1) &&
             (iVar3._0_2_ = riid->Data2, iVar3._2_2_ = riid->Data3, iVar2._0_2_ = pIVar5->Data2,
             iVar2._2_2_ = pIVar5->Data3, iVar3 == iVar2)) &&
            (*(int *)riid->Data4 == *(int *)pIVar5->Data4)) &&
           (*(int *)(riid->Data4 + 4) == *(int *)(pIVar5->Data4 + 4))) goto LAB_404eabe8;
        pQVar6 = pQVar6 + 1;
        pIVar5 = pQVar6->piid;
      } while (pIVar5 != (IID *)0x0);
    }
    if (((riid->Data1 == 0) && (iVar4._0_2_ = riid->Data2, iVar4._2_2_ = riid->Data3, iVar4 == 0))
       && ((*(int *)riid->Data4 == 0xc0 && (pQVar6 = pqit, *(int *)(riid->Data4 + 4) == 0x46000000))
          )) {
LAB_404eabe8:
      piVar7 = (int *)(pQVar6->dwOffset + (int)that);
      (**(code **)(*piVar7 + 4))(piVar7);
      HVar1 = 0;
      *ppv = piVar7;
    }
    else {
      *ppv = (void *)0x0;
      HVar1 = -0x7fffbffe;
    }
  }
  return HVar1;
}



/* 404eac2c FUN_404eac2c */

/* Boundary evidence: original MIPS .pdata 404eac2c..404eac8b. Semantic name remains unreviewed. */

LPWSTR FUN_404eac2c(LPWSTR param_1,LPCSTR param_2,int *param_3)

{
  int iVar1;
  
  *param_1 = L'\0';
  iVar1 = MultiByteToWideChar(0,0,param_2,-1,param_1,*param_3);
  *param_3 = iVar1;
  return param_1;
}



/* 404eac8c FUN_404eac8c */

/* Boundary evidence: original MIPS .pdata 404eac8c..404ead07. Semantic name remains unreviewed. */

LPSTR FUN_404eac8c(LPSTR param_1,LPCWSTR param_2,int *param_3)

{
  int iVar1;
  
  if ((param_1 == (LPSTR)0x0) || (param_2 == (LPCWSTR)0x0)) {
    param_1 = (LPSTR)0x0;
  }
  else {
    *param_1 = '\0';
    iVar1 = WideCharToMultiByte(0,0,param_2,-1,param_1,*param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    *param_3 = iVar1;
  }
  return param_1;
}



/* 404ead08 FUN_404ead08 */

/* Boundary evidence: original MIPS .pdata 404ead08..404ead5b. Semantic name remains unreviewed. */

int FUN_404ead08(LPSTR param_1,wchar_t *param_2)

{
  size_t sVar1;
  int local_18 [2];
  
  sVar1 = wcslen(param_2);
  local_18[0] = sVar1 * 2 + 1;
  FUN_404eac8c(param_1,param_2,local_18);
  return local_18[0];
}



/* 404ead5c RegEnumValueA */

/* Boundary evidence: original MIPS .pdata 404ead5c..404eaecf. Semantic name remains unreviewed. */

LSTATUS RegEnumValueA(HKEY hKey,DWORD dwIndex,LPSTR lpValueName,LPDWORD lpcchValueName,
                     LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData)

{
  LSTATUS LVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  DWORD *pDVar5;
  wchar_t *_Src;
  undefined1 *puVar6;
  undefined1 auStack_48 [32];
  DWORD local_28;
  uint local_24;
  
                    /* 0x1ad5c  42  RegEnumValueA */
  local_24 = DAT_404f4224;
  _Src = (wchar_t *)0x0;
  if (((lpValueName == (LPSTR)0x0) || (lpcchValueName == (LPDWORD)0x0)) ||
     ((lpData != (LPBYTE)0x0 && (lpcbData == (LPDWORD)0x0)))) {
    FUN_404f1430(DAT_404f4224);
    LVar1 = 0x57;
  }
  else {
    iVar4 = (int)(*lpcchValueName * 2 + 7) >> 3;
    puVar6 = auStack_48 + iVar4 * -8;
    if (lpData == (LPBYTE)0x0) {
      pDVar5 = (DWORD *)0x0;
    }
    else {
      iVar3 = (int)(*lpcbData + 7) >> 3;
      puVar6 = auStack_48 + iVar3 * -8 + iVar4 * -8;
      _Src = (wchar_t *)(&local_28 + iVar4 * -2 + iVar3 * -2);
      pDVar5 = &local_28;
    }
    *(LPDWORD *)(puVar6 + 0x1c) = lpcbData;
    *(wchar_t **)(puVar6 + 0x18) = _Src;
    *(DWORD **)(puVar6 + 0x14) = pDVar5;
    *(LPDWORD *)(puVar6 + 0x10) = lpReserved;
    LVar1 = RegEnumValueW(hKey,dwIndex,(LPWSTR)(&local_28 + iVar4 * -2),lpcchValueName,
                          *(LPDWORD *)(puVar6 + 0x10),*(LPDWORD *)(puVar6 + 0x14),
                          *(LPBYTE *)(puVar6 + 0x18),*(LPDWORD *)(puVar6 + 0x1c));
    if (LVar1 == 0) {
      FUN_404ead08(lpValueName,(wchar_t *)(&local_28 + iVar4 * -2));
      if (lpData != (LPBYTE)0x0) {
        if (lpType != (LPDWORD)0x0) {
          *lpType = local_28;
        }
        if (local_28 == 1) {
          DVar2 = FUN_404ead08((LPSTR)lpData,_Src);
          *lpcbData = DVar2;
        }
        else if (_Src != (wchar_t *)0x0) {
          memcpy(lpData,_Src,*lpcbData);
        }
      }
    }
    FUN_404f1430(local_24);
  }
  return LVar1;
}



/* 404eaed0 RegEnumKeyExA */

LSTATUS RegEnumKeyExA(HKEY hKey,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,
                     LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime)

{
                    /* 0x1aed0  40  RegEnumKeyExA */
  return 0x32;
}



/* 404eaed8 RegDeleteKeyA */

/* Boundary evidence: original MIPS .pdata 404eaed8..404eaf7f. Semantic name remains unreviewed. */

LSTATUS RegDeleteKeyA(HKEY hKey,LPCSTR lpSubKey)

{
  LPCWSTR lpSubKey_00;
  size_t sVar1;
  LSTATUS LVar2;
  int local_18;
  uint local_14;
  
                    /* 0x1aed8  37  RegDeleteKeyA */
  local_14 = DAT_404f4224;
  if (lpSubKey == (LPCSTR)0x0) {
    lpSubKey_00 = (LPCWSTR)0x0;
  }
  else {
    sVar1 = strlen(lpSubKey);
    local_18 = sVar1 + 1;
    lpSubKey_00 = FUN_404eac2c((LPWSTR)(&local_18 + (local_18 * 2 + 7 >> 3) * -2),lpSubKey,&local_18
                              );
  }
  LVar2 = RegDeleteKeyW(hKey,lpSubKey_00);
  FUN_404f1430(local_14);
  return LVar2;
}



/* 404eaf80 RegCreateKeyExA */

/* Boundary evidence: original MIPS .pdata 404eaf80..404eb0b7. Semantic name remains unreviewed. */

LSTATUS RegCreateKeyExA(HKEY hKey,LPCSTR lpSubKey,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,
                       REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,
                       LPDWORD lpdwDisposition)

{
  LPWSTR lpClass_00;
  size_t sVar1;
  LSTATUS LVar2;
  int iVar3;
  LPWSTR lpSubKey_00;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_48 [40];
  int local_20;
  uint local_1c;
  
                    /* 0x1af80  36  RegCreateKeyExA */
  puVar4 = auStack_48;
  local_1c = DAT_404f4224;
  if (lpSubKey == (LPCSTR)0x0) {
    lpSubKey_00 = (LPCWSTR)0x0;
  }
  else {
    sVar1 = strlen(lpSubKey);
    local_20 = sVar1 + 1;
    iVar3 = local_20 * 2 + 7 >> 3;
    puVar4 = auStack_48 + iVar3 * -8;
    lpSubKey_00 = FUN_404eac2c((LPWSTR)(&local_20 + iVar3 * -2),lpSubKey,&local_20);
  }
  if (lpClass == (LPSTR)0x0) {
    lpClass_00 = (LPWSTR)0x0;
    puVar5 = puVar4;
  }
  else {
    sVar1 = strlen(lpClass);
    local_20 = sVar1 + 1;
    iVar3 = (local_20 * 2 + 7 >> 3) * -8;
    puVar5 = puVar4 + iVar3;
    lpClass_00 = FUN_404eac2c((LPWSTR)(puVar4 + iVar3 + 0x28),lpClass,&local_20);
  }
  *(LPDWORD *)(puVar5 + 0x20) = lpdwDisposition;
  *(PHKEY *)(puVar5 + 0x1c) = phkResult;
  *(LPSECURITY_ATTRIBUTES *)(puVar5 + 0x18) = lpSecurityAttributes;
  *(REGSAM *)(puVar5 + 0x14) = samDesired;
  *(DWORD *)(puVar5 + 0x10) = dwOptions;
  LVar2 = RegCreateKeyExW(hKey,lpSubKey_00,Reserved,lpClass_00,*(DWORD *)(puVar5 + 0x10),
                          *(REGSAM *)(puVar5 + 0x14),*(LPSECURITY_ATTRIBUTES *)(puVar5 + 0x18),
                          *(PHKEY *)(puVar5 + 0x1c),*(LPDWORD *)(puVar5 + 0x20));
  FUN_404f1430(local_1c);
  return LVar2;
}



/* 404eb0b8 RegDeleteValueA */

/* Boundary evidence: original MIPS .pdata 404eb0b8..404eb15f. Semantic name remains unreviewed. */

LSTATUS RegDeleteValueA(HKEY hKey,LPCSTR lpValueName)

{
  LPCWSTR lpValueName_00;
  size_t sVar1;
  LSTATUS LVar2;
  int local_18;
  uint local_14;
  
                    /* 0x1b0b8  38  RegDeleteValueA */
  local_14 = DAT_404f4224;
  if (lpValueName == (LPCSTR)0x0) {
    lpValueName_00 = (LPCWSTR)0x0;
  }
  else {
    sVar1 = strlen(lpValueName);
    local_18 = sVar1 + 1;
    lpValueName_00 =
         FUN_404eac2c((LPWSTR)(&local_18 + (local_18 * 2 + 7 >> 3) * -2),lpValueName,&local_18);
  }
  LVar2 = RegDeleteValueW(hKey,lpValueName_00);
  FUN_404f1430(local_14);
  return LVar2;
}



/* 404eb160 RegEnumKeyW */

/* Boundary evidence: original MIPS .pdata 404eb160..404eb18f. Semantic name remains unreviewed. */

LSTATUS RegEnumKeyW(HKEY hKey,DWORD dwIndex,LPWSTR lpName,DWORD cchName)

{
  LSTATUS LVar1;
  DWORD local_resc;
  
                    /* 0x1b160  41  RegEnumKeyW */
  local_resc = cchName;
  LVar1 = RegEnumKeyExW(hKey,dwIndex,lpName,&local_resc,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                        (PFILETIME)0x0);
  return LVar1;
}



/* 404eb190 RegEnumKeyA */

/* Boundary evidence: original MIPS .pdata 404eb190..404eb24b. Semantic name remains unreviewed. */

LSTATUS RegEnumKeyA(HKEY hKey,DWORD dwIndex,LPSTR lpName,DWORD cchName)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 auStack_30 [4];
  DWORD local_20;
  uint local_1c;
  
                    /* 0x1b190  39  RegEnumKeyA */
  local_1c = DAT_404f4224;
  if ((int)((ulonglong)cchName * 2 >> 0x20) == 0) {
    iVar2 = (int)((ulonglong)cchName * 2) + 7 >> 3;
    local_20 = cchName;
    auStack_30[iVar2 * -2 + 3] = 0;
    auStack_30[iVar2 * -2 + 2] = 0;
    auStack_30[iVar2 * -2 + 1] = 0;
    auStack_30[iVar2 * -2] = 0;
    LVar1 = RegEnumKeyExW(hKey,dwIndex,(LPWSTR)(&local_20 + iVar2 * -2),&local_20,
                          (LPDWORD)auStack_30[iVar2 * -2],(LPWSTR)auStack_30[iVar2 * -2 + 1],
                          (LPDWORD)auStack_30[iVar2 * -2 + 2],(PFILETIME)auStack_30[iVar2 * -2 + 3])
    ;
    FUN_404ead08(lpName,(wchar_t *)(&local_20 + iVar2 * -2));
  }
  else {
    LVar1 = 0x57;
  }
  FUN_404f1430(local_1c);
  return LVar1;
}



/* 404eb24c RegSetValueExA */

/* Boundary evidence: original MIPS .pdata 404eb24c..404eb417. Semantic name remains unreviewed. */

LSTATUS RegSetValueExA(HKEY hKey,LPCSTR lpValueName,DWORD Reserved,DWORD dwType,BYTE *lpData,
                      DWORD cbData)

{
  LPCWSTR pWVar1;
  size_t sVar2;
  LSTATUS LVar3;
  int iVar4;
  LPWSTR pWVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_40 [24];
  int local_28;
  uint local_24;
  
                    /* 0x1b24c  46  RegSetValueExA */
  puVar6 = auStack_40;
  puVar8 = auStack_40;
  local_24 = DAT_404f4224;
  if (dwType != 0) {
    if (dwType < 3) {
      if (lpData == (BYTE *)0x0) {
        pWVar5 = (LPWSTR)0x0;
      }
      else {
        sVar2 = strlen((char *)lpData);
        local_28 = sVar2 + 1;
        iVar4 = local_28 * 2 + 7 >> 3;
        puVar6 = auStack_40 + iVar4 * -8;
        pWVar5 = FUN_404eac2c((LPWSTR)(&local_28 + iVar4 * -2),(LPCSTR)lpData,&local_28);
      }
      if (lpValueName == (LPCSTR)0x0) {
        pWVar1 = (LPCWSTR)0x0;
        puVar7 = puVar6;
      }
      else {
        sVar2 = strlen(lpValueName);
        local_28 = sVar2 + 1;
        iVar4 = (local_28 * 2 + 7 >> 3) * -8;
        puVar7 = puVar6 + iVar4;
        pWVar1 = FUN_404eac2c((LPWSTR)(puVar6 + iVar4 + 0x18),lpValueName,&local_28);
      }
      *(LPWSTR *)(puVar7 + 0x10) = pWVar5;
      *(DWORD *)(puVar7 + 0x14) = cbData << 1;
      LVar3 = RegSetValueExW(hKey,pWVar1,Reserved,dwType,*(BYTE **)(puVar7 + 0x10),
                             *(DWORD *)(puVar7 + 0x14));
      goto LAB_404eb3e0;
    }
    if (dwType == 7) {
      FUN_404f1430(DAT_404f4224);
      return 0x32;
    }
  }
  if (lpValueName == (LPCSTR)0x0) {
    pWVar1 = (LPCWSTR)0x0;
  }
  else {
    sVar2 = strlen(lpValueName);
    local_28 = sVar2 + 1;
    iVar4 = local_28 * 2 + 7 >> 3;
    puVar8 = auStack_40 + iVar4 * -8;
    pWVar1 = FUN_404eac2c((LPWSTR)(&local_28 + iVar4 * -2),lpValueName,&local_28);
  }
  *(DWORD *)(puVar8 + 0x14) = cbData;
  *(BYTE **)(puVar8 + 0x10) = lpData;
  LVar3 = RegSetValueExW(hKey,pWVar1,Reserved,dwType,*(BYTE **)(puVar8 + 0x10),
                         *(DWORD *)(puVar8 + 0x14));
LAB_404eb3e0:
  FUN_404f1430(local_24);
  return LVar3;
}



/* 404eb418 RegOpenKeyExA */

/* Boundary evidence: original MIPS .pdata 404eb418..404eb4e7. Semantic name remains unreviewed. */

LSTATUS RegOpenKeyExA(HKEY hKey,LPCSTR lpSubKey,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult)

{
  LPCWSTR lpSubKey_00;
  size_t sVar1;
  LSTATUS LVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_38 [24];
  int local_20;
  uint local_1c;
  
                    /* 0x1b418  43  RegOpenKeyExA */
  puVar4 = auStack_38;
  local_1c = DAT_404f4224;
  if (lpSubKey == (LPCSTR)0x0) {
    lpSubKey_00 = (LPCWSTR)0x0;
  }
  else {
    sVar1 = strlen(lpSubKey);
    local_20 = sVar1 + 1;
    iVar3 = local_20 * 2 + 7 >> 3;
    puVar4 = auStack_38 + iVar3 * -8;
    lpSubKey_00 = FUN_404eac2c((LPWSTR)(&local_20 + iVar3 * -2),lpSubKey,&local_20);
  }
  *(PHKEY *)(puVar4 + 0x10) = phkResult;
  LVar2 = RegOpenKeyExW(hKey,lpSubKey_00,ulOptions,samDesired,*(PHKEY *)(puVar4 + 0x10));
  FUN_404f1430(local_1c);
  return LVar2;
}



/* 404eb4e8 RegQueryValueExA */

/* Boundary evidence: original MIPS .pdata 404eb4e8..404eb77f. Semantic name remains unreviewed. */

LSTATUS RegQueryValueExA(HKEY hKey,LPCSTR lpValueName,LPDWORD lpReserved,LPDWORD lpType,
                        LPBYTE lpData,LPDWORD lpcbData)

{
  size_t sVar1;
  DWORD DVar2;
  DWORD DVar3;
  int iVar4;
  LPCWSTR lpWideCharStr;
  LPWSTR lpValueName_00;
  undefined1 *puVar5;
  undefined1 auStack_58 [32];
  uint local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  
                    /* 0x1b4e8  45  RegQueryValueExA */
  puVar5 = auStack_58;
  local_2c = DAT_404f4224;
  if ((lpData != (LPBYTE)0x0) && (lpcbData == (LPDWORD)0x0)) {
    FUN_404f1430(DAT_404f4224);
    return 0x57;
  }
  if (lpValueName == (LPCSTR)0x0) {
    lpValueName_00 = (LPCWSTR)0x0;
  }
  else {
    sVar1 = strlen(lpValueName);
    local_34 = sVar1 + 1;
    iVar4 = local_34 * 2 + 7 >> 3;
    puVar5 = auStack_58 + iVar4 * -8;
    lpValueName_00 = FUN_404eac2c((LPWSTR)(&local_38 + iVar4 * -2),lpValueName,&local_34);
  }
  *(uint **)(puVar5 + 0x14) = &local_38;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  DVar2 = RegQueryValueExW(hKey,lpValueName_00,lpReserved,lpType,*(LPBYTE *)(puVar5 + 0x10),
                           *(LPDWORD *)(puVar5 + 0x14));
  if ((DVar2 == 0) && (lpcbData != (LPDWORD)0x0)) {
    iVar4 = ((int)(local_38 + 7) >> 3) * -8;
    lpWideCharStr = (LPCWSTR)(puVar5 + iVar4 + 0x20);
    *(uint **)(puVar5 + iVar4 + 0x14) = &local_38;
    *(LPCWSTR *)(puVar5 + iVar4 + 0x10) = lpWideCharStr;
    DVar2 = RegQueryValueExW(hKey,lpValueName_00,lpReserved,&local_30,
                             *(LPBYTE *)(puVar5 + iVar4 + 0x10),*(LPDWORD *)(puVar5 + iVar4 + 0x14))
    ;
    if (DVar2 == 0) {
      if (lpType != (LPDWORD)0x0) {
        *lpType = local_30;
      }
      if (local_30 != 0) {
        if (local_30 < 3) {
          if (lpData == (LPBYTE)0x0) {
            *(undefined4 *)(puVar5 + iVar4 + 0x1c) = 0;
            *(undefined4 *)(puVar5 + iVar4 + 0x18) = 0;
            *(undefined4 *)(puVar5 + iVar4 + 0x14) = 0;
            *(undefined4 *)(puVar5 + iVar4 + 0x10) = 0;
            DVar3 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)(puVar5 + iVar4 + 0x10),
                                        *(int *)(puVar5 + iVar4 + 0x14),
                                        *(LPCSTR *)(puVar5 + iVar4 + 0x18),
                                        *(LPBOOL *)(puVar5 + iVar4 + 0x1c));
          }
          else {
            *(DWORD *)(puVar5 + iVar4 + 0x14) = *lpcbData;
            *(undefined4 *)(puVar5 + iVar4 + 0x1c) = 0;
            *(undefined4 *)(puVar5 + iVar4 + 0x18) = 0;
            *(LPBYTE *)(puVar5 + iVar4 + 0x10) = lpData;
            DVar3 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)(puVar5 + iVar4 + 0x10),
                                        *(int *)(puVar5 + iVar4 + 0x14),
                                        *(LPCSTR *)(puVar5 + iVar4 + 0x18),
                                        *(LPBOOL *)(puVar5 + iVar4 + 0x1c));
            *lpcbData = DVar3;
            if ((DVar3 != 0) || (DVar2 = GetLastError(), DVar2 != 0x7a)) goto LAB_404eb740;
            *(undefined4 *)(puVar5 + iVar4 + 0x1c) = 0;
            *(undefined4 *)(puVar5 + iVar4 + 0x18) = 0;
            DVar2 = 0xea;
            *(undefined4 *)(puVar5 + iVar4 + 0x14) = 0;
            *(undefined4 *)(puVar5 + iVar4 + 0x10) = 0;
            DVar3 = WideCharToMultiByte(0,0,lpWideCharStr,-1,*(LPSTR *)(puVar5 + iVar4 + 0x10),
                                        *(int *)(puVar5 + iVar4 + 0x14),
                                        *(LPCSTR *)(puVar5 + iVar4 + 0x18),
                                        *(LPBOOL *)(puVar5 + iVar4 + 0x1c));
          }
          *lpcbData = DVar3;
          goto LAB_404eb740;
        }
        if (local_30 == 7) {
          FUN_404f1430(local_2c);
          return 0x32;
        }
      }
      if (lpData != (LPBYTE)0x0) {
        if (*lpcbData < local_38) {
          DVar2 = 0xea;
        }
        else {
          memcpy(lpData,lpWideCharStr,local_38);
        }
      }
      *lpcbData = local_38;
    }
  }
LAB_404eb740:
  FUN_404f1430(local_2c);
  return DVar2;
}



/* 404eb780 RegQueryValueA */

/* Boundary evidence: original MIPS .pdata 404eb780..404eb7a7. Semantic name remains unreviewed. */

LSTATUS RegQueryValueA(HKEY hKey,LPCSTR lpSubKey,LPSTR lpData,PLONG lpcbData)

{
  LSTATUS LVar1;
  
                    /* 0x1b780  44  RegQueryValueA */
  LVar1 = RegQueryValueExA(hKey,lpSubKey,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)lpData,(LPDWORD)lpcbData)
  ;
  return LVar1;
}



/* 404eb7a8 FUN_404eb7a8 */

/* Boundary evidence: original MIPS .pdata 404eb7a8..404eb8f3. Semantic name remains unreviewed. */

size_t FUN_404eb7a8(UINT param_1,LPCSTR param_2,int param_3,STRSAFE_LPWSTR param_4,size_t param_5)

{
  size_t sVar1;
  DWORD DVar2;
  int iVar3;
  STRSAFE_LPCWSTR lpWideCharStr;
  
  sVar1 = MultiByteToWideChar(param_1,0,param_2,param_3,param_4,param_5);
  if ((sVar1 == 0) && (DVar2 = GetLastError(), DVar2 == 0x7a)) {
    iVar3 = MultiByteToWideChar(param_1,0,param_2,param_3,(LPWSTR)0x0,0);
    if ((iVar3 != 0) &&
       (lpWideCharStr = LocalAlloc(0,iVar3 << 1), lpWideCharStr != (STRSAFE_LPCWSTR)0x0)) {
      iVar3 = MultiByteToWideChar(param_1,0,param_2,param_3,lpWideCharStr,iVar3);
      sVar1 = 0;
      if (iVar3 != 0) {
        StringCchCopyW(param_4,param_5,lpWideCharStr);
        sVar1 = param_5;
      }
      LocalFree(lpWideCharStr);
    }
  }
  return sVar1;
}



/* 404eb8f4 FUN_404eb8f4 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 404eb8f4..404eba07. Semantic name remains unreviewed. */

size_t FUN_404eb8f4(undefined4 param_1,undefined4 param_2,int param_3,STRSAFE_LPWSTR param_4,
                   size_t param_5)

{
  int iVar1;
  STRSAFE_LPCWSTR pszSrc;
  size_t sVar2;
  size_t sVar3;
  int local_res8 [2];
  size_t local_30 [4];
  
  local_30[0] = param_5;
  local_30[1] = 0;
  sVar2 = 0;
  local_res8[0] = param_3;
  local_30[2] = param_3;
  iVar1 = FUN_404ebe18(local_30 + 1,param_1,param_2,local_30 + 2,param_4,local_30);
  sVar3 = sVar2;
  if (((-1 < iVar1) && (sVar3 = local_30[0], (int)local_30[2] < local_res8[0])) &&
     (pszSrc = LocalAlloc(0,local_30[0] << 1), sVar3 = sVar2, pszSrc != (STRSAFE_LPCWSTR)0x0)) {
    local_30[1] = 0;
    iVar1 = FUN_404ebe18(local_30 + 1,param_1,param_2,local_res8,pszSrc,local_30);
    if (-1 < iVar1) {
      StringCchCopyW(param_4,param_5,pszSrc);
      sVar2 = param_5;
    }
    LocalFree(pszSrc);
    sVar3 = sVar2;
  }
  return sVar3;
}



/* 404eba08 SHAnsiToUnicodeCP */

/* Boundary evidence: original MIPS .pdata 404eba08..404ebae3. Semantic name remains unreviewed. */

size_t SHAnsiToUnicodeCP(uint param_1,char *param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  size_t sVar1;
  
                    /* 0x1ba08  216  SHAnsiToUnicodeCP */
  sVar1 = 0;
  if (param_2 == (char *)0x0) {
    param_2 = "";
  }
  if ((param_3 != (STRSAFE_LPWSTR)0x0) && (param_4 != 0)) {
    *param_3 = L'\0';
    sVar1 = strlen(param_2);
    if (param_1 == 0x4b0) {
      param_1 = 0xfde9;
    }
    else if ((param_1 != 50000) && ((param_1 < 65000 || (0xfde9 < param_1)))) {
      sVar1 = FUN_404eb7a8(param_1,param_2,sVar1 + 1,param_3,param_4);
      return sVar1;
    }
    sVar1 = FUN_404eb8f4(param_1,param_2,sVar1 + 1,param_3,param_4);
  }
  return sVar1;
}



/* 404ebae4 SHUnicodeToUnicode */

/* Boundary evidence: original MIPS .pdata 404ebae4..404ebb1b. Semantic name remains unreviewed. */

int SHUnicodeToUnicode(LPCWSTR pwzSrc,LPWSTR pwzDst,int cwchBuf)

{
  short *psVar1;
  
                    /* 0x1bae4  346  SHUnicodeToUnicode */
  psVar1 = FUN_404ecd94(pwzDst,pwzSrc,cwchBuf);
  return ((int)psVar1 - (int)pwzDst >> 1) + 1;
}



/* 404ebb1c SHAnsiToUnicode */

/* Boundary evidence: original MIPS .pdata 404ebb1c..404ebb43. Semantic name remains unreviewed. */

int SHAnsiToUnicode(LPCSTR pszSrc,LPWSTR pwszDst,int cwchBuf)

{
  size_t sVar1;
  
                    /* 0x1bb1c  215  SHAnsiToUnicode */
  sVar1 = SHAnsiToUnicodeCP(0,pszSrc,pwszDst,cwchBuf);
  return sVar1;
}



/* 404ebb44 FUN_404ebb44 */

/* Boundary evidence: original MIPS .pdata 404ebb44..404ebcb3. Semantic name remains unreviewed. */

int FUN_404ebb44(UINT param_1,LPCWSTR param_2,int param_3,char *param_4,size_t param_5)

{
  int iVar1;
  DWORD DVar2;
  SIZE_T uBytes;
  BYTE *lpMultiByteStr;
  int iVar3;
  
  iVar1 = WideCharToMultiByte(param_1,0,param_2,param_3,param_4,param_5,(LPCSTR)0x0,(LPBOOL)0x0);
  if ((iVar1 == 0) && (DVar2 = GetLastError(), DVar2 == 0x7a)) {
    uBytes = WideCharToMultiByte(param_1,0,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((uBytes != 0) && (lpMultiByteStr = LocalAlloc(0,uBytes), lpMultiByteStr != (BYTE *)0x0)) {
      iVar3 = WideCharToMultiByte(param_1,0,param_2,param_3,(LPSTR)lpMultiByteStr,uBytes,(LPCSTR)0x0
                                  ,(LPBOOL)0x0);
      iVar1 = 0;
      if (iVar3 != 0) {
        iVar1 = FUN_404dbfb0(lpMultiByteStr,param_5);
        iVar1 = iVar1 + 1;
        strncpy(param_4,(char *)lpMultiByteStr,param_5);
      }
      LocalFree(lpMultiByteStr);
    }
  }
  return iVar1;
}



/* 404ebcb4 SHUnicodeToAnsiCP */

/* Boundary evidence: original MIPS .pdata 404ebcb4..404ebd7b. Semantic name remains unreviewed. */

int SHUnicodeToAnsiCP(uint param_1,wchar_t *param_2,char *param_3,size_t param_4)

{
  int iVar1;
  size_t sVar2;
  
                    /* 0x1bcb4  218  SHUnicodeToAnsiCP */
  iVar1 = 0;
  if (param_2 == (wchar_t *)0x0) {
    param_2 = L"";
  }
  if ((param_3 != (char *)0x0) && (param_4 != 0)) {
    *param_3 = '\0';
    sVar2 = wcslen(param_2);
    if (((param_1 == 0x4b0) || (param_1 == 50000)) || ((64999 < param_1 && (param_1 < 0xfdea)))) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_404ebb44(param_1,param_2,sVar2 + 1,param_3,param_4);
    }
  }
  return iVar1;
}



/* 404ebd7c SHUnicodeToAnsi */

/* Boundary evidence: original MIPS .pdata 404ebd7c..404ebda3. Semantic name remains unreviewed. */

int SHUnicodeToAnsi(LPCWSTR pwszSrc,LPSTR pszDst,int cchBuf)

{
  int iVar1;
  
                    /* 0x1bd7c  217  SHUnicodeToAnsi */
  iVar1 = SHUnicodeToAnsiCP(0,pwszSrc,pszDst,cchBuf);
  return iVar1;
}



/* 404ebda4 FUN_404ebda4 */

/* Boundary evidence: original MIPS .pdata 404ebda4..404ebe17. Semantic name remains unreviewed. */

void FUN_404ebda4(int *param_1,LPCWSTR param_2,int *param_3,undefined4 param_4)

{
  HMODULE pHVar1;
  int iVar2;
  
  if (*param_3 == 0) {
    if (*param_1 == 0) {
      pHVar1 = LoadLibraryW(param_2);
      *param_1 = (int)pHVar1;
      if (pHVar1 == (HMODULE)0x0) {
        return;
      }
    }
    iVar2 = GetProcAddressW(*param_1,param_4);
    *param_3 = iVar2;
  }
  return;
}



/* 404ebe18 FUN_404ebe18 */

/* Boundary evidence: original MIPS .pdata 404ebe18..404ebecf. Semantic name remains unreviewed. */

undefined4
FUN_404ebe18(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  FUN_404ebda4((int *)&DAT_404f4310,L"mlang.dll",(int *)&DAT_404f4314,
               L"ConvertINetMultiByteToUnicode");
  if (DAT_404f4314 == (code *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (*DAT_404f4314)(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar1;
}



/* 404ebed0 SHGetPathFromIDListWrapW */

/* Boundary evidence: original MIPS .pdata 404ebed0..404ebf53. Semantic name remains unreviewed. */

undefined4 SHGetPathFromIDListWrapW(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
                    /* 0x1bed0  334  SHGetPathFromIDListWrapW */
  FUN_404ebda4((int *)&DAT_404f431c,L"ceshell.dll",(int *)&DAT_404f4328,L"SHGetPathFromIDListW");
  if (DAT_404f4328 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_404f4328)(param_1,param_2);
  }
  return uVar1;
}



/* 404ebf54 SHChangeNotifyWrap */

/* Boundary evidence: original MIPS .pdata 404ebf54..404ebfeb. Semantic name remains unreviewed. */

void SHChangeNotifyWrap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
                    /* 0x1bf54  394  SHChangeNotifyWrap */
  FUN_404ebda4((int *)&DAT_404f431c,L"ceshell.dll",(int *)&DAT_404f4360,L"SHChangeNotify");
  if (DAT_404f4360 != (code *)0x0) {
    (*DAT_404f4360)(param_1,param_2,param_3,param_4);
  }
  return;
}



/* 404ebfec SHSetValueA */

/* Boundary evidence: original MIPS .pdata 404ebfec..404ec0df. Semantic name remains unreviewed. */

LSTATUS SHSetValueA(HKEY hkey,LPCSTR pszSubKey,LPCSTR pszValue,DWORD dwType,LPCVOID pvData,
                   DWORD cbData)

{
  HKEY pHVar1;
  LSTATUS LVar2;
  HKEY local_20;
  DWORD DStack_1c;
  
                    /* 0x1bfec  55  SHSetValueA */
  LVar2 = 0;
  pHVar1 = hkey;
  if ((pszSubKey != (LPCSTR)0x0) && (pHVar1 = hkey, *pszSubKey != '\0')) {
    LVar2 = RegCreateKeyExA(hkey,pszSubKey,0,"",0,2,(LPSECURITY_ATTRIBUTES)0x0,&local_20,&DStack_1c)
    ;
    pHVar1 = local_20;
  }
  local_20 = pHVar1;
  if ((LVar2 == 0) &&
     (LVar2 = RegSetValueExA(local_20,pszValue,0,dwType,pvData,cbData), local_20 != hkey)) {
    RegCloseKey(local_20);
  }
  return LVar2;
}



/* 404ec0e0 SHSetValueW */

/* Boundary evidence: original MIPS .pdata 404ec0e0..404ec1d3. Semantic name remains unreviewed. */

LSTATUS SHSetValueW(HKEY hkey,LPCWSTR pszSubKey,LPCWSTR pszValue,DWORD dwType,LPCVOID pvData,
                   DWORD cbData)

{
  HKEY pHVar1;
  LSTATUS LVar2;
  HKEY local_20;
  DWORD DStack_1c;
  
                    /* 0x1c0e0  56  SHSetValueW */
  LVar2 = 0;
  pHVar1 = hkey;
  if ((pszSubKey != (LPCWSTR)0x0) && (pHVar1 = hkey, *pszSubKey != L'\0')) {
    LVar2 = RegCreateKeyExW(hkey,pszSubKey,0,L"",0,2,(LPSECURITY_ATTRIBUTES)0x0,&local_20,&DStack_1c
                           );
    pHVar1 = local_20;
  }
  local_20 = pHVar1;
  if ((LVar2 == 0) &&
     (LVar2 = RegSetValueExW(local_20,pszValue,0,dwType,pvData,cbData), local_20 != hkey)) {
    RegCloseKey(local_20);
  }
  return LVar2;
}



/* 404ec1d4 SHDeleteValueW */

/* Boundary evidence: original MIPS .pdata 404ec1d4..404ec24f. Semantic name remains unreviewed. */

LSTATUS SHDeleteValueW(HKEY hkey,LPCWSTR pszSubKey,LPCWSTR pszValue)

{
  LSTATUS LVar1;
  HKEY local_18 [2];
  
                    /* 0x1c1d4  47  SHDeleteValueW */
  LVar1 = RegOpenKeyExW(hkey,pszSubKey,0,2,local_18);
  if (LVar1 == 0) {
    LVar1 = RegDeleteValueW(local_18[0],pszValue);
    RegCloseKey(local_18[0]);
  }
  return LVar1;
}



/* 404ec250 SHQueryValueExA */

/* Boundary evidence: original MIPS .pdata 404ec250..404ec317. Semantic name remains unreviewed. */

LSTATUS SHQueryValueExA(HKEY hkey,LPCSTR pszValue,DWORD *pdwReserved,DWORD *pdwType,void *pvData,
                       DWORD *pcbData)

{
  LSTATUS LVar1;
  DWORD local_18;
  DWORD local_14;
  
                    /* 0x1c250  51  SHQueryValueExA */
  local_18 = 0;
  if (pcbData != (DWORD *)0x0) {
    local_18 = *pcbData;
  }
  LVar1 = RegQueryValueExA(hkey,pszValue,pdwReserved,&local_14,pvData,&local_18);
  if ((((LVar1 == 0) && (local_14 == 1)) && (pvData != (void *)0x0)) &&
     ((pcbData != (DWORD *)0x0 && (local_18 < *pcbData)))) {
    *(undefined1 *)(local_18 + (int)pvData) = 0;
  }
  if (pdwType != (DWORD *)0x0) {
    *pdwType = local_14;
  }
  if (pcbData != (DWORD *)0x0) {
    *pcbData = local_18;
  }
  return LVar1;
}



/* 404ec318 SHQueryValueExW */

/* Boundary evidence: original MIPS .pdata 404ec318..404ec3eb. Semantic name remains unreviewed. */

LSTATUS SHQueryValueExW(HKEY hkey,LPCWSTR pszValue,DWORD *pdwReserved,DWORD *pdwType,void *pvData,
                       DWORD *pcbData)

{
  LSTATUS LVar1;
  DWORD local_18;
  DWORD local_14;
  
                    /* 0x1c318  52  SHQueryValueExW */
  local_18 = 0;
  if (pcbData != (DWORD *)0x0) {
    local_18 = *pcbData;
  }
  LVar1 = RegQueryValueExW(hkey,pszValue,pdwReserved,&local_14,pvData,&local_18);
  if ((((LVar1 == 0) && (local_14 == 1)) && (pvData != (void *)0x0)) &&
     ((pcbData != (DWORD *)0x0 && (local_18 + 2 <= *pcbData)))) {
    *(undefined2 *)((local_18 & 0xfffffffe) + (int)pvData) = 0;
  }
  if (pdwType != (DWORD *)0x0) {
    *pdwType = local_14;
  }
  if (pcbData != (DWORD *)0x0) {
    *pcbData = local_18;
  }
  return LVar1;
}



/* 404ec3ec FUN_404ec3ec */

/* Boundary evidence: original MIPS .pdata 404ec3ec..404ec70b. Semantic name remains unreviewed. */

int FUN_404ec3ec(LPCSTR param_1,HKEY param_2,int *param_3,undefined4 *param_4,int param_5)

{
  BOOL BVar1;
  PHKEY _Dst;
  size_t sVar2;
  LSTATUS LVar3;
  HKEY hKey;
  PHKEY phkResult;
  PHKEY phkResult_00;
  PHKEY _Str;
  PHKEY ppHVar4;
  PHKEY phkResult_01;
  PHKEY ppHVar5;
  
  if ((param_4 == (undefined4 *)0x0) ||
     ((param_3 != (int *)0x0 &&
      ((BVar1 = IsBadWritePtr(param_3,0x114), BVar1 != 0 || ((*param_3 == 0 && (param_3[2] == 0)))))
      ))) {
    return 0x57;
  }
  _Dst = LocalAlloc(0x40,0x114);
  *param_4 = _Dst;
  if (_Dst == (PHKEY)0x0) {
    return 8;
  }
  if (param_3 == (int *)0x0) {
    _Dst[3] = (HKEY)0x80000002;
    _Dst[1] = (HKEY)0x80000001;
  }
  else {
    memcpy(_Dst,param_3,0x114);
  }
  ppHVar5 = _Dst + 2;
  _Dst[0x44] = param_2;
  if (param_5 == 0) {
    ppHVar4 = _Dst + 1;
    phkResult_00 = _Dst + 3;
    phkResult = ppHVar5;
    phkResult_01 = _Dst;
  }
  else {
    ppHVar4 = _Dst + 3;
    phkResult_00 = _Dst + 1;
    phkResult = _Dst;
    phkResult_01 = ppHVar5;
  }
  _Str = _Dst + 4;
  if (*(char *)_Str != '\0') {
    FUN_404ea87c((BYTE *)_Str);
  }
  sVar2 = strlen((char *)_Str);
  StrNCatA((LPSTR)_Str,param_1,0xff - sVar2);
  if (*phkResult_01 == (HKEY)0x0) {
    if (*ppHVar4 == (HKEY)0x0) {
      LVar3 = 2;
    }
    else {
      LVar3 = RegOpenKeyExA(*ppHVar4,(LPCSTR)_Str,0,(REGSAM)_Dst[0x44],phkResult_01);
    }
    strncpy((char *)_Str,param_1,0x100);
    *ppHVar4 = (HKEY)0x0;
  }
  else {
    LVar3 = RegOpenKeyExA(*phkResult_01,param_1,0,(REGSAM)_Dst[0x44],phkResult_01);
  }
  if (LVar3 != 2) {
    if (*phkResult == (HKEY)0x0) {
      hKey = *phkResult_00;
      if (((hKey != (HKEY)0x0) && (hKey != (HKEY)0x80000002)) && (hKey != (HKEY)0x80000001)) {
        LVar3 = RegOpenKeyExA(hKey,(LPCSTR)0x0,0,(REGSAM)_Dst[0x44],phkResult_00);
      }
    }
    else {
      RegOpenKeyExA(*phkResult,(LPCSTR)0x0,0,(REGSAM)_Dst[0x44],phkResult);
    }
    if (*phkResult != (HKEY)0x0) {
      *phkResult_00 = *phkResult;
      *phkResult = (HKEY)0x0;
    }
    goto LAB_404ec6b0;
  }
  if (param_5 == 0) {
    if (*phkResult_00 != (HKEY)0x0) {
      LVar3 = RegOpenKeyExA(*phkResult_00,(LPCSTR)_Str,0,(REGSAM)_Dst[0x44],phkResult);
      goto LAB_404ec618;
    }
    if (*phkResult != (HKEY)0x0) {
      LVar3 = RegOpenKeyExA(*phkResult,(LPCSTR)_Str,0,(REGSAM)_Dst[0x44],phkResult);
    }
  }
  else {
    *phkResult = (HKEY)0x0;
LAB_404ec618:
    *phkResult_00 = (HKEY)0x0;
  }
  *phkResult_01 = (HKEY)0x0;
  *ppHVar4 = (HKEY)0x0;
LAB_404ec6b0:
  if (LVar3 != 0) {
    *_Dst = (HKEY)0x0;
    *ppHVar5 = (HKEY)0x0;
    LocalFree(_Dst);
    *param_4 = 0;
  }
  return LVar3;
}



/* 404ec70c SHRegOpenUSKeyW */

/* Boundary evidence: original MIPS .pdata 404ec70c..404ec7cf. Semantic name remains unreviewed. */

LSTATUS SHRegOpenUSKeyW(LPCWSTR pwzPath,REGSAM samDesired,HUSKEY hRelativeUSKey,PHUSKEY phNewUSKey,
                       BOOL fIgnoreHKCU)

{
  int iVar1;
  DWORD DVar2;
  CHAR aCStack_118 [256];
  uint local_18;
  
                    /* 0x1c70c  54  SHRegOpenUSKeyW */
  local_18 = DAT_404f4224;
  iVar1 = WideCharToMultiByte(0,0,pwzPath,-1,aCStack_118,0x100,(LPCSTR)0x0,(LPBOOL)0x0);
  if (iVar1 == 0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = FUN_404ec3ec(aCStack_118,(HKEY)samDesired,hRelativeUSKey,phNewUSKey,fIgnoreHKCU);
  }
  FUN_404f1430(local_18);
  return DVar2;
}



/* 404ec7d0 SHRegGetUSValueW */

/* Boundary evidence: original MIPS .pdata 404ec7d0..404ec95f. Semantic name remains unreviewed. */

LSTATUS SHRegGetUSValueW(LPCWSTR pszSubKey,LPCWSTR pszValue,DWORD *pdwType,void *pvData,
                        DWORD *pcbData,BOOL fIgnoreHKCU,void *pvDefaultData,DWORD dwDefaultDataSize)

{
  LSTATUS LVar1;
  int iVar2;
  uint uVar3;
  HKEY local_28 [2];
  
                    /* 0x1c7d0  53  SHRegGetUSValueW */
  if (pcbData == (DWORD *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *pcbData;
  }
  if ((fIgnoreHKCU == 0) &&
     (LVar1 = RegOpenKeyExW((HKEY)0x80000001,pszSubKey,0,0,local_28), LVar1 == 0)) {
    iVar2 = RegQueryValueExW(local_28[0],pszValue,(LPDWORD)0x0,pdwType,pvData,pcbData);
  }
  else {
    iVar2 = RegOpenKeyExW((HKEY)0x80000002,pszSubKey,0,0,local_28);
    if (iVar2 != 0) goto LAB_404ec8ec;
    iVar2 = RegQueryValueExW(local_28[0],pszValue,(LPDWORD)0x0,pdwType,pvData,pcbData);
  }
  RegCloseKey(local_28[0]);
  if (iVar2 == 0) {
    return 0;
  }
LAB_404ec8ec:
  if ((((pvDefaultData != (void *)0x0) && (dwDefaultDataSize != 0)) && (pvData != (void *)0x0)) &&
     (dwDefaultDataSize <= uVar3)) {
    memmove(pvData,pvDefaultData,dwDefaultDataSize);
    if (pcbData != (DWORD *)0x0) {
      *pcbData = dwDefaultDataSize;
    }
    iVar2 = 0;
  }
  return iVar2;
}



/* 404ec960 SHGetValueA */

/* Boundary evidence: original MIPS .pdata 404ec960..404eca27. Semantic name remains unreviewed. */

LSTATUS SHGetValueA(HKEY hkey,LPCSTR pszSubKey,LPCSTR pszValue,DWORD *pdwType,void *pvData,
                   DWORD *pcbData)

{
  LSTATUS LVar1;
  HKEY local_18 [2];
  
                    /* 0x1c960  49  SHGetValueA */
  local_18[0] = (HKEY)0x0;
  LVar1 = 0x57;
  if ((pszSubKey != (LPCSTR)0x0) && (*pszSubKey != '\0')) {
    LVar1 = RegOpenKeyExA(hkey,pszSubKey,0,1,local_18);
    hkey = local_18[0];
  }
  if (hkey == (HKEY)0x0) {
    if (pcbData != (DWORD *)0x0) {
      *pcbData = 0;
    }
  }
  else {
    LVar1 = SHQueryValueExA(hkey,pszValue,(DWORD *)0x0,pdwType,pvData,pcbData);
    if (local_18[0] != (HKEY)0x0) {
      RegCloseKey(local_18[0]);
    }
  }
  return LVar1;
}



/* 404eca28 SHGetValueW */

/* Boundary evidence: original MIPS .pdata 404eca28..404ecaef. Semantic name remains unreviewed. */

LSTATUS SHGetValueW(HKEY hkey,LPCWSTR pszSubKey,LPCWSTR pszValue,DWORD *pdwType,void *pvData,
                   DWORD *pcbData)

{
  LSTATUS LVar1;
  HKEY local_18 [2];
  
                    /* 0x1ca28  50  SHGetValueW */
  local_18[0] = (HKEY)0x0;
  LVar1 = 0x57;
  if ((pszSubKey != (LPCWSTR)0x0) && (*pszSubKey != L'\0')) {
    LVar1 = RegOpenKeyExW(hkey,pszSubKey,0,1,local_18);
    hkey = local_18[0];
  }
  if (hkey == (HKEY)0x0) {
    if (pcbData != (DWORD *)0x0) {
      *pcbData = 0;
    }
  }
  else {
    LVar1 = SHQueryValueExW(hkey,pszValue,(DWORD *)0x0,pdwType,pvData,pcbData);
    if (local_18[0] != (HKEY)0x0) {
      RegCloseKey(local_18[0]);
    }
  }
  return LVar1;
}



/* 404ecaf0 FUN_404ecaf0 */

/* Boundary evidence: original MIPS .pdata 404ecaf0..404ecbab. Semantic name remains unreviewed. */

int FUN_404ecaf0(void)

{
  HLOCAL hMem;
  LONG LVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if ((DAT_404f43c0 == 0) && (hMem = LocalAlloc(0x40,0x8000), hMem != (HLOCAL)0x0)) {
    iVar4 = 0;
    do {
      pbVar2 = &DAT_404d3a88 + iVar4;
      puVar3 = (undefined1 *)(iVar4 + (int)hMem);
      iVar4 = iVar4 + 1;
      *puVar3 = (&DAT_404dbb88)[*pbVar2];
    } while (iVar4 < 0x8000);
    LVar1 = InterlockedCompareExchange(&DAT_404f43c0,(LONG)hMem,0);
    if (LVar1 != 0) {
      LocalFree(hMem);
    }
  }
  return DAT_404f43c0;
}



/* 404ecbac SHGetInverseCMAP */

/* Boundary evidence: original MIPS .pdata 404ecbac..404ecc57. Semantic name remains unreviewed. */

HRESULT SHGetInverseCMAP(BYTE *pbMap,ULONG cbMap)

{
  HRESULT HVar1;
  void *_Src;
  
                    /* 0x1cbac  48  SHGetInverseCMAP */
  if (pbMap == (BYTE *)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else if ((cbMap == 0x8000) || (cbMap == 4)) {
    _Src = (void *)FUN_404ecaf0();
    if (_Src == (void *)0x0) {
      HVar1 = -0x7ff8fff2;
    }
    else {
      if (cbMap == 4) {
        *(void **)pbMap = _Src;
      }
      else {
        memcpy(pbMap,_Src,0x8000);
      }
      HVar1 = 0;
    }
  }
  else {
    HVar1 = -0x7ff8ffa9;
  }
  return HVar1;
}



/* 404ecc58 TermPalette */

/* Boundary evidence: original MIPS .pdata 404ecc58..404ecc83. Semantic name remains unreviewed. */

void TermPalette(void)

{
                    /* 0x1cc58  89  TermPalette */
  if (DAT_404f43c0 != (HLOCAL)0x0) {
    LocalFree(DAT_404f43c0);
  }
  return;
}



/* 404ecc84 FUN_404ecc84 */

/* Boundary evidence: original MIPS .pdata 404ecc84..404ecceb. Semantic name remains unreviewed. */

undefined4 FUN_404ecc84(uint param_1,uint param_2)

{
  BOOL BVar1;
  
  if (((param_1 & 0xff) == (param_2 & 0xff)) &&
     ((BVar1 = IsDBCSLeadByte((BYTE)param_1), BVar1 == 0 || (param_1 == param_2)))) {
    return 0;
  }
  return 1;
}



/* 404eccec FUN_404eccec */

/* Boundary evidence: original MIPS .pdata 404eccec..404ecd67. Semantic name remains unreviewed. */

void FUN_404eccec(undefined4 param_1,undefined4 param_2)

{
  BOOL BVar1;
  BYTE local_18;
  undefined1 local_17;
  undefined1 local_16;
  char local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  local_18 = (BYTE)param_1;
  BVar1 = IsDBCSLeadByte(local_18);
  if (BVar1 == 0) {
    local_17 = 0;
  }
  else {
    local_17 = (undefined1)((uint)param_1 >> 8);
    local_16 = 0;
  }
  local_14 = (char)param_2;
  local_13 = (undefined1)((uint)param_2 >> 8);
  local_12 = 0;
  _stricmp((char *)&local_18,&local_14);
  return;
}



/* 404ecd68 StrCpyW */

LPWSTR StrCpyW(LPWSTR psz1,LPCWSTR psz2)

{
  WCHAR WVar1;
  LPWSTR pWVar2;
  
                    /* 0x1cd68  72  StrCpyW */
  if ((psz1 != (LPWSTR)0x0) && (pWVar2 = psz1, psz2 != (LPCWSTR)0x0)) {
    do {
      WVar1 = *psz2;
      psz2 = psz2 + 1;
      *pWVar2 = WVar1;
      pWVar2 = pWVar2 + 1;
    } while (WVar1 != L'\0');
  }
  return psz1;
}



/* 404ecd94 FUN_404ecd94 */

short * FUN_404ecd94(short *param_1,short *param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  
  if (0 < param_3) {
    psVar2 = param_1;
    if (param_2 != (short *)0x0) {
      do {
        param_1 = psVar2;
        param_3 = param_3 + -1;
        if (param_3 < 1) break;
        sVar1 = *param_2;
        param_2 = param_2 + 1;
        *param_1 = sVar1;
        psVar2 = param_1 + 1;
      } while (sVar1 != 0);
    }
    *param_1 = 0;
  }
  return param_1;
}



/* 404ecde8 StrCpyNW */

/* Boundary evidence: original MIPS .pdata 404ecde8..404ece13. Semantic name remains unreviewed. */

LPWSTR StrCpyNW(LPWSTR psz1,LPCWSTR psz2,int cchMax)

{
                    /* 0x1cde8  71  StrCpyNW */
  FUN_404ecd94(psz1,psz2,cchMax);
  return psz1;
}



/* 404ece14 StrCatW */

LPWSTR StrCatW(LPWSTR psz1,LPCWSTR psz2)

{
  WCHAR WVar1;
  WCHAR *pWVar2;
  
                    /* 0x1ce14  61  StrCatW */
  if ((psz1 != (LPWSTR)0x0) && (psz2 != (LPCWSTR)0x0)) {
    WVar1 = *psz1;
    pWVar2 = psz1;
    while (WVar1 != L'\0') {
      pWVar2 = pWVar2 + 1;
      WVar1 = *pWVar2;
    }
    do {
      WVar1 = *psz2;
      psz2 = psz2 + 1;
      *pWVar2 = WVar1;
      pWVar2 = pWVar2 + 1;
    } while (WVar1 != L'\0');
  }
  return psz1;
}



/* 404ece5c StrCatBuffW */

/* Boundary evidence: original MIPS .pdata 404ece5c..404ece93. Semantic name remains unreviewed. */

LPWSTR StrCatBuffW(LPWSTR pszDest,LPCWSTR pszSrc,int cchDestBuffSize)

{
                    /* 0x1ce5c  60  StrCatBuffW */
  StringCchCatW(pszDest,cchDestBuffSize,pszSrc);
  return pszDest;
}



/* 404ece94 StrCatBuffA */

/* Boundary evidence: original MIPS .pdata 404ece94..404ececb. Semantic name remains unreviewed. */

LPSTR StrCatBuffA(LPSTR pszDest,LPCSTR pszSrc,int cchDestBuffSize)

{
                    /* 0x1ce94  59  StrCatBuffA */
  StringCchCatA(pszDest,cchDestBuffSize,pszSrc);
  return pszDest;
}



/* 404ececc StrNCatA */

/* Boundary evidence: original MIPS .pdata 404ececc..404ecf0f. Semantic name remains unreviewed. */

LPSTR StrNCatA(LPSTR psz1,LPCSTR psz2,int cchMax)

{
  LPSTR pCVar1;
  char *_Dest;
  
                    /* 0x1cecc  77  StrNCatA */
  if ((psz1 != (LPSTR)0x0) && (pCVar1 = psz1, psz2 != (LPCSTR)0x0)) {
    do {
      _Dest = pCVar1;
      pCVar1 = _Dest + 1;
    } while (*_Dest != '\0');
    strncpy(_Dest,psz2,cchMax);
  }
  return psz1;
}



/* 404ecf10 FUN_404ecf10 */

/* Boundary evidence: original MIPS .pdata 404ecf10..404ecfb3. Semantic name remains unreviewed. */

ushort * FUN_404ecf10(ushort *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 == 0) {
    uVar2 = (uint)(char)*param_1;
    if (uVar2 != 0) {
      do {
        if ((uVar2 & 0xff) == (param_2 & 0xff)) {
          return param_1;
        }
        param_1 = (ushort *)((int)param_1 + 1);
        uVar2 = (uint)*(char *)param_1;
      } while (uVar2 != 0);
    }
  }
  else {
    for (; (char)*param_1 != '\0'; param_1 = (ushort *)((int)param_1 + 1)) {
      iVar1 = FUN_404ecc84((uint)*param_1,param_2);
      if (iVar1 == 0) {
        return param_1;
      }
    }
  }
  return (ushort *)0x0;
}



/* 404ecfb4 StrChrA */

/* Boundary evidence: original MIPS .pdata 404ecfb4..404ed04b. Semantic name remains unreviewed. */

LPSTR StrChrA(LPCSTR lpStart,WORD wMatch)

{
  BOOL BVar1;
  undefined2 in_register_00000016;
  int iVar2;
  ushort *puVar3;
  _cpinfo _Stack_28;
  uint local_14;
  
                    /* 0x1cfb4  62  StrChrA */
  local_14 = DAT_404f4224;
  if (lpStart == (LPCSTR)0x0) {
    FUN_404f1430(DAT_404f4224);
    puVar3 = (ushort *)0x0;
  }
  else {
    BVar1 = GetCPInfo(0,&_Stack_28);
    if ((BVar1 == 0) || (iVar2 = 1, _Stack_28.LeadByte[0] == '\0')) {
      iVar2 = 0;
    }
    puVar3 = FUN_404ecf10((ushort *)lpStart,CONCAT22(in_register_00000016,wMatch),iVar2);
    FUN_404f1430(local_14);
  }
  return (LPSTR)puVar3;
}



/* 404ed04c StrChrW */

LPWSTR StrChrW(LPCWSTR lpStart,WCHAR wMatch)

{
  WCHAR WVar1;
  undefined2 in_register_00000016;
  
                    /* 0x1d04c  64  StrChrW */
  if (lpStart != (LPCWSTR)0x0) {
    WVar1 = *lpStart;
    while ((ushort)WVar1 != 0) {
      if ((uint)(ushort)WVar1 == CONCAT22(in_register_00000016,wMatch)) {
        return lpStart;
      }
      lpStart = lpStart + 1;
      WVar1 = *lpStart;
    }
  }
  return (LPWSTR)0x0;
}



/* 404ed090 StrRChrA */

/* Boundary evidence: original MIPS .pdata 404ed090..404ed123. Semantic name remains unreviewed. */

LPSTR StrRChrA(LPCSTR lpStart,LPCSTR lpEnd,WORD wMatch)

{
  size_t sVar1;
  int iVar2;
  undefined2 in_register_0000001a;
  ushort *puVar3;
  
                    /* 0x1d090  79  StrRChrA */
  puVar3 = (ushort *)0x0;
  if (lpEnd == (LPCSTR)0x0) {
    sVar1 = strlen(lpStart);
    lpEnd = lpStart + sVar1;
  }
  for (; lpStart < lpEnd; lpStart = (LPCSTR)((int)lpStart + 1)) {
    iVar2 = FUN_404ecc84((uint)*(ushort *)lpStart,CONCAT22(in_register_0000001a,wMatch));
    if (iVar2 == 0) {
      puVar3 = (ushort *)lpStart;
    }
  }
  return (LPSTR)puVar3;
}



/* 404ed124 StrRChrW */

/* Boundary evidence: original MIPS .pdata 404ed124..404ed1a3. Semantic name remains unreviewed. */

LPWSTR StrRChrW(LPCWSTR lpStart,LPCWSTR lpEnd,WCHAR wMatch)

{
  size_t sVar1;
  undefined2 in_register_0000001a;
  LPWSTR pWVar2;
  
                    /* 0x1d124  80  StrRChrW */
  pWVar2 = (LPWSTR)0x0;
  if (lpEnd == (LPCWSTR)0x0) {
    sVar1 = wcslen(lpStart);
    lpEnd = lpStart + sVar1;
  }
  for (; lpStart < lpEnd; lpStart = lpStart + 1) {
    if ((uint)(ushort)*lpStart == CONCAT22(in_register_0000001a,wMatch)) {
      pWVar2 = lpStart;
    }
  }
  return pWVar2;
}



/* 404ed1a4 FUN_404ed1a4 */

/* Boundary evidence: original MIPS .pdata 404ed1a4..404ed23f. Semantic name remains unreviewed. */

ushort * FUN_404ed1a4(ushort *param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  
  if (param_1 != (ushort *)0x0) {
    BVar1 = IsDBCSLeadByte((BYTE)param_2);
    if (BVar1 == 0) {
      param_2 = param_2 & 0xff;
    }
    for (; (char)*param_1 != '\0'; param_1 = (ushort *)((int)param_1 + 1)) {
      iVar2 = FUN_404eccec((uint)*param_1,param_2 & 0xffff);
      if (iVar2 == 0) {
        return param_1;
      }
    }
  }
  return (ushort *)0x0;
}



/* 404ed240 StrChrIW */

/* Boundary evidence: original MIPS .pdata 404ed240..404ed2c7. Semantic name remains unreviewed. */

LPWSTR StrChrIW(LPCWSTR lpStart,WCHAR wMatch)

{
  int iVar1;
  WCHAR local_18 [3];
  undefined2 local_12;
  
                    /* 0x1d240  63  StrChrIW */
  if (lpStart != (LPCWSTR)0x0) {
    local_18[2] = *lpStart;
    while (local_18[2] != L'\0') {
      local_12 = 0;
      local_18[1] = 0;
      local_18[0] = wMatch;
      iVar1 = lstrcmpiW(local_18 + 2,local_18);
      if (iVar1 == 0) {
        return lpStart;
      }
      lpStart = lpStart + 1;
      local_18[2] = *lpStart;
    }
  }
  return (LPWSTR)0x0;
}



/* 404ed2c8 StrPBrkW */

LPWSTR StrPBrkW(LPCWSTR psz,LPCWSTR pszSet)

{
  WCHAR WVar1;
  WCHAR *pWVar2;
  WCHAR WVar3;
  
                    /* 0x1d2c8  78  StrPBrkW */
  if (((psz != (LPCWSTR)0x0) && (pszSet != (LPCWSTR)0x0)) && (WVar3 = *psz, WVar3 != L'\0')) {
    WVar1 = *pszSet;
    pWVar2 = pszSet;
    do {
      while (WVar1 != L'\0') {
        if (WVar3 == WVar1) {
          return psz;
        }
        WVar1 = pWVar2[1];
        pWVar2 = pWVar2 + 1;
      }
      psz = psz + 1;
      WVar3 = *psz;
      WVar1 = *pszSet;
      pWVar2 = pszSet;
    } while (WVar3 != L'\0');
  }
  return (LPWSTR)0x0;
}



/* 404ed334 StrToIntA */

int StrToIntA(LPCSTR lpSrc)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
                    /* 0x1d334  86  StrToIntA */
  iVar3 = 0;
  if (lpSrc != (LPCSTR)0x0) {
    cVar1 = *lpSrc;
    if (cVar1 == '-') {
      lpSrc = lpSrc + 1;
    }
    cVar2 = *lpSrc;
    while ((int)cVar2 - 0x30U < 10) {
      lpSrc = lpSrc + 1;
      iVar3 = iVar3 * 10 + (int)cVar2 + -0x30;
      cVar2 = *lpSrc;
    }
    if (cVar1 == '-') {
      iVar3 = -iVar3;
    }
  }
  return iVar3;
}



/* 404ed3a4 StrToIntW */

int StrToIntW(LPCWSTR lpSrc)

{
  WCHAR WVar1;
  WCHAR WVar2;
  int iVar3;
  
                    /* 0x1d3a4  87  StrToIntW */
  iVar3 = 0;
  if (lpSrc != (LPCWSTR)0x0) {
    WVar1 = *lpSrc;
    if (WVar1 == L'-') {
      lpSrc = lpSrc + 1;
    }
    WVar2 = *lpSrc;
    while ((ushort)WVar2 - 0x30 < 10) {
      lpSrc = lpSrc + 1;
      iVar3 = iVar3 * 10 + (uint)(ushort)WVar2 + -0x30;
      WVar2 = *lpSrc;
    }
    if (WVar1 == L'-') {
      iVar3 = -iVar3;
    }
  }
  return iVar3;
}



/* 404ed414 FUN_404ed414 */

/* Boundary evidence: original MIPS .pdata 404ed414..404ed59f. Semantic name remains unreviewed. */

int FUN_404ed414(ushort *param_1,char *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  char local_20 [4];
  char local_1c [4];
  
  if (((param_1 != (ushort *)0x0) && (param_2 != (char *)0x0)) &&
     (puVar4 = (ushort *)((int)param_1 + param_3), param_1 < puVar4)) {
    if (param_4 == 0) {
      do {
        if (((char)*param_1 == '\0') && (*param_2 == '\0')) {
          return 0;
        }
        if ((char)*param_1 != *param_2) {
          local_1c[0] = (char)*param_1;
          local_20[0] = *param_2;
          goto LAB_404ed530;
        }
        param_1 = (ushort *)((int)param_1 + 1);
        param_2 = param_2 + 1;
      } while (param_1 < puVar4);
    }
    else {
      do {
        if ((char)*param_1 == '\0') {
          if (*param_2 == '\0') {
            return 0;
          }
          uVar2 = 0;
        }
        else {
          uVar2 = (uint)*param_1;
        }
        if (*param_2 == '\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = (uint)CONCAT11(param_2[1],*param_2);
        }
        iVar1 = FUN_404ecc84(uVar2,uVar3);
        if (iVar1 != 0) {
          local_1c[0] = (char)uVar2;
          local_20[0] = (char)uVar3;
LAB_404ed530:
          local_20[1] = 0;
          local_1c[1] = 0;
          iVar1 = strcmp(local_1c,local_20);
          return iVar1;
        }
        param_1 = (ushort *)((int)param_1 + 1);
        param_2 = param_2 + 1;
      } while (param_1 < puVar4);
    }
  }
  return 0;
}



/* 404ed5a0 StrCmpNA */

/* Boundary evidence: original MIPS .pdata 404ed5a0..404ed62f. Semantic name remains unreviewed. */

int StrCmpNA(LPCSTR lpStr1,LPCSTR lpStr2,int nChar)

{
  BOOL BVar1;
  int iVar2;
  _cpinfo _Stack_28;
  uint local_14;
  
                    /* 0x1d5a0  66  StrCmpNA */
  local_14 = DAT_404f4224;
  BVar1 = GetCPInfo(0,&_Stack_28);
  if ((BVar1 == 0) || (iVar2 = 1, _Stack_28.LeadByte[0] == '\0')) {
    iVar2 = 0;
  }
  iVar2 = FUN_404ed414((ushort *)lpStr1,lpStr2,nChar,iVar2);
  FUN_404f1430(local_14);
  return iVar2;
}



/* 404ed630 StrCmpNW */

/* Boundary evidence: original MIPS .pdata 404ed630..404ed66b. Semantic name remains unreviewed. */

int StrCmpNW(LPCWSTR lpStr1,LPCWSTR lpStr2,int nChar)

{
  int iVar1;
  
                    /* 0x1d630  69  StrCmpNW */
  iVar1 = CompareStringW(0x800,0,lpStr1,nChar,lpStr2,nChar);
  return iVar1 + -2;
}



/* 404ed66c StrCmpNIA */

/* Boundary evidence: original MIPS .pdata 404ed66c..404ed87f. Semantic name remains unreviewed. */

int StrCmpNIA(LPCSTR lpStr1,LPCSTR lpStr2,int nChar)

{
  BOOL BVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  
                    /* 0x1d66c  67  StrCmpNIA */
  if (DAT_404f422c == 0) {
    if ((nChar == 0) || ((lpStr1 != (LPCSTR)0x0 && (lpStr2 != (LPCSTR)0x0)))) {
      puVar7 = (ushort *)(lpStr1 + nChar);
      DAT_404f422c = 0;
      do {
        if (puVar7 <= lpStr1) {
          return 0;
        }
        cVar3 = (char)*(ushort *)lpStr1;
        uVar5 = (uint)cVar3;
        if ((uVar5 == 0) && ((byte)*(ushort *)lpStr2 == 0)) {
          return 0;
        }
        if ((uVar5 & 0x80) == 0) {
          bVar2 = (byte)*(ushort *)lpStr2;
          uVar6 = (uint)(char)bVar2;
          if ((uVar6 & 0x80) != 0) goto LAB_404ed7c4;
          if ((0x40 < (int)uVar5) && ((int)uVar5 < 0x5b)) {
            cVar3 = cVar3 + ' ';
          }
          if ((0x40 < (int)uVar6) && ((int)uVar6 < 0x5b)) {
            bVar2 = bVar2 + 0x20;
          }
          iVar4 = (int)cVar3 - (int)(char)bVar2;
        }
        else {
LAB_404ed7c4:
          if (uVar5 == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = (uint)*(ushort *)lpStr1;
          }
          BVar1 = IsDBCSLeadByte((byte)*(ushort *)lpStr2);
          if (BVar1 == 0) {
            uVar6 = (uint)(byte)*(ushort *)lpStr2;
          }
          else {
            uVar6 = (uint)*(ushort *)lpStr2;
          }
          iVar4 = FUN_404eccec(uVar5,uVar6);
        }
        if (iVar4 != 0) {
          if (iVar4 < 0) {
            return -1;
          }
          return 1;
        }
        lpStr1 = (LPCSTR)((int)lpStr1 + 1);
        lpStr2 = (LPCSTR)((int)lpStr2 + 1);
      } while( true );
    }
  }
  else if ((nChar == 0) || ((lpStr1 != (LPCSTR)0x0 && (lpStr2 != (LPCSTR)0x0)))) {
    iVar4 = 0;
    if (0 < nChar) {
      do {
        if (lpStr1[iVar4] == '\0') break;
        iVar4 = iVar4 + 1;
      } while (iVar4 < nChar);
    }
    iVar4 = 0;
    if (0 < nChar) {
      do {
        if (lpStr2[iVar4] == '\0') {
          return -1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < nChar);
    }
  }
  return -1;
}



/* 404ed880 StrCmpNIW */

/* Boundary evidence: original MIPS .pdata 404ed880..404ed8bb. Semantic name remains unreviewed. */

int StrCmpNIW(LPCWSTR lpStr1,LPCWSTR lpStr2,int nChar)

{
  int iVar1;
  
                    /* 0x1d880  68  StrCmpNIW */
  iVar1 = CompareStringW(0x800,1,lpStr1,nChar,lpStr2,nChar);
  return iVar1 + -2;
}



/* 404ed8bc StrStrA */

/* Boundary evidence: original MIPS .pdata 404ed8bc..404ed9c7. Semantic name remains unreviewed. */

LPSTR StrStrA(LPCSTR lpFirst,LPCSTR lpSrch)

{
  ushort uVar1;
  BOOL BVar2;
  size_t sVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  _cpinfo _Stack_30;
  uint local_1c;
  
                    /* 0x1d8bc  82  StrStrA */
  local_1c = DAT_404f4224;
  if ((lpFirst == (LPCSTR)0x0) || (lpSrch == (LPCSTR)0x0)) {
    FUN_404f1430(DAT_404f4224);
    puVar5 = (ushort *)0x0;
  }
  else {
    BVar2 = GetCPInfo(0,&_Stack_30);
    if ((BVar2 == 0) || (iVar6 = 1, _Stack_30.LeadByte[0] == '\0')) {
      iVar6 = 0;
    }
    sVar3 = strlen(lpSrch);
    uVar1 = *(ushort *)lpSrch;
    while ((puVar5 = FUN_404ecf10((ushort *)lpFirst,(uint)uVar1,iVar6), puVar5 != (ushort *)0x0 &&
           (iVar4 = FUN_404ed414(puVar5,lpSrch,sVar3,iVar6), iVar4 != 0))) {
      lpFirst = (LPCSTR)((int)puVar5 + 1);
    }
    FUN_404f1430(local_1c);
  }
  return (LPSTR)puVar5;
}



/* 404ed9c8 StrStrW */

/* Boundary evidence: original MIPS .pdata 404ed9c8..404edaab. Semantic name remains unreviewed. */

LPWSTR StrStrW(LPCWSTR lpFirst,LPCWSTR lpSrch)

{
  WCHAR WVar1;
  WCHAR WVar2;
  size_t cchCount1;
  int iVar3;
  
                    /* 0x1d9c8  85  StrStrW */
  if ((lpFirst != (LPCWSTR)0x0) && (lpSrch != (LPCWSTR)0x0)) {
    cchCount1 = wcslen(lpSrch);
    WVar1 = *lpSrch;
    for (; lpFirst != (LPCWSTR)0x0; lpFirst = lpFirst + 1) {
      WVar2 = *lpFirst;
      while (WVar2 != L'\0') {
        if (WVar2 == WVar1) goto LAB_404eda48;
        lpFirst = lpFirst + 1;
        WVar2 = *lpFirst;
      }
      lpFirst = (PCNZWCH)0x0;
LAB_404eda48:
      if (lpFirst == (PCNZWCH)0x0) {
        return (LPWSTR)0x0;
      }
      iVar3 = CompareStringW(0x800,0,lpFirst,cchCount1,lpSrch,cchCount1);
      if (iVar3 == 2) {
        return lpFirst;
      }
    }
  }
  return (LPWSTR)0x0;
}



/* 404edaac StrStrIA */

/* Boundary evidence: original MIPS .pdata 404edaac..404edb5b. Semantic name remains unreviewed. */

LPSTR StrStrIA(LPCSTR lpFirst,LPCSTR lpSrch)

{
  ushort uVar1;
  size_t nChar;
  int iVar2;
  ushort *lpStr1;
  
                    /* 0x1daac  83  StrStrIA */
  if ((lpFirst == (LPCSTR)0x0) || (lpSrch == (LPCSTR)0x0)) {
    lpStr1 = (ushort *)0x0;
  }
  else {
    nChar = strlen(lpSrch);
    uVar1 = *(ushort *)lpSrch;
    while ((lpStr1 = FUN_404ed1a4((ushort *)lpFirst,(uint)uVar1), lpStr1 != (ushort *)0x0 &&
           (iVar2 = StrCmpNIA((LPCSTR)lpStr1,lpSrch,nChar), iVar2 != 0))) {
      lpFirst = (LPCSTR)((int)lpStr1 + 1);
    }
  }
  return (LPSTR)lpStr1;
}



/* 404edb5c StrStrIW */

/* Boundary evidence: original MIPS .pdata 404edb5c..404edc2b. Semantic name remains unreviewed. */

LPWSTR StrStrIW(LPCWSTR lpFirst,LPCWSTR lpSrch)

{
  WCHAR wMatch;
  size_t cchCount1;
  PCNZWCH lpString1;
  int iVar1;
  
                    /* 0x1db5c  84  StrStrIW */
  if ((lpFirst == (LPCWSTR)0x0) || (lpSrch == (LPCWSTR)0x0)) {
    lpString1 = (PCNZWCH)0x0;
  }
  else {
    cchCount1 = wcslen(lpSrch);
    wMatch = *lpSrch;
    lpString1 = StrChrIW(lpFirst,wMatch);
    while ((lpString1 != (PCNZWCH)0x0 &&
           (iVar1 = CompareStringW(0x800,1,lpString1,cchCount1,lpSrch,cchCount1), iVar1 != 2))) {
      lpString1 = StrChrIW(lpString1 + 1,wMatch);
    }
  }
  return lpString1;
}



/* 404edc2c StrDupA */

/* Boundary evidence: original MIPS .pdata 404edc2c..404edc97. Semantic name remains unreviewed. */

LPSTR StrDupA(LPCSTR lpSrch)

{
  size_t sVar1;
  char *_Dest;
  
                    /* 0x1dc2c  73  StrDupA */
  if (lpSrch == (LPCSTR)0x0) {
    _Dest = (char *)0x0;
  }
  else {
    sVar1 = strlen(lpSrch);
    _Dest = LocalAlloc(0x40,sVar1 + 1);
    if (_Dest != (char *)0x0) {
      strcpy(_Dest,lpSrch);
    }
  }
  return _Dest;
}



/* 404edc98 StrDupW */

/* Boundary evidence: original MIPS .pdata 404edc98..404edd03. Semantic name remains unreviewed. */

LPWSTR StrDupW(LPCWSTR lpSrch)

{
  WCHAR WVar1;
  size_t sVar2;
  LPWSTR pWVar3;
  WCHAR *pWVar4;
  int iVar5;
  
                    /* 0x1dc98  74  StrDupW */
  if (lpSrch == (LPCWSTR)0x0) {
    pWVar3 = (LPWSTR)0x0;
  }
  else {
    sVar2 = wcslen(lpSrch);
    pWVar3 = LocalAlloc(0x40,(sVar2 + 1) * 2);
    if (pWVar3 != (LPWSTR)0x0) {
      iVar5 = (int)pWVar3 - (int)lpSrch;
      do {
        WVar1 = *lpSrch;
        pWVar4 = (WCHAR *)(iVar5 + (int)lpSrch);
        lpSrch = lpSrch + 1;
        *pWVar4 = WVar1;
      } while (WVar1 != L'\0');
    }
  }
  return pWVar3;
}



/* 404edd04 FUN_404edd04 */

/* Boundary evidence: original MIPS .pdata 404edd04..404ede83. Semantic name remains unreviewed. */

void FUN_404edd04(int *param_1,HINSTANCE param_2,UINT param_3,uint *param_4,int *param_5,
                 uint param_6)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  wchar_t *_Str;
  uint uVar6;
  short local_118 [64];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_404f4224;
  if (*param_5 == 0) goto LAB_404ede68;
  uVar6 = *param_4 / param_6;
  if (param_6 == 0) {
    trap(0x1c00);
  }
  uVar4 = 1;
  if ((uVar6 == 0) && (param_6 != 1)) goto LAB_404ede68;
  *param_4 = *param_4 - uVar6 * param_6;
  psVar5 = local_118;
  if (uVar6 / 10 == 0) {
LAB_404eddc8:
    iVar3 = *param_5;
    do {
      if (iVar3 == 0) {
        *psVar5 = 0x30;
      }
      else {
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        *psVar5 = (short)(uVar6 / uVar4) + 0x30;
        iVar3 = iVar3 + -1;
        uVar6 = uVar6 - (uVar6 / uVar4) * uVar4;
      }
      uVar4 = uVar4 / 10;
      psVar5 = psVar5 + 1;
    } while (uVar4 != 0);
    *param_5 = iVar3;
  }
  else {
    uVar1 = 10;
    do {
      uVar4 = uVar1;
      uVar1 = uVar4 * 10;
      if (uVar1 == 0) {
        trap(0x1c00);
      }
    } while (uVar6 / uVar1 != 0);
    if (uVar4 != 0) goto LAB_404eddc8;
  }
  *psVar5 = 0;
  LoadStringW(param_2,param_3,aWStack_98,0x40);
  wsprintfW((LPWSTR)*param_1,aWStack_98,local_118);
  _Str = (wchar_t *)*param_1;
  sVar2 = wcslen(_Str);
  *param_1 = (int)(_Str + sVar2);
LAB_404ede68:
  FUN_404f1430(local_18);
  return;
}



/* 404ede84 FUN_404ede84 */

/* Boundary evidence: original MIPS .pdata 404ede84..404ee193. Semantic name remains unreviewed. */

size_t FUN_404ede84(wchar_t *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  size_t sVar2;
  uint uVar3;
  WCHAR *pWVar4;
  wchar_t *_Str;
  uint uVar5;
  uint uVar6;
  int local_resc;
  uint local_338;
  wchar_t *local_334;
  WCHAR local_330 [64];
  WCHAR local_2b0 [64];
  wchar_t awStack_230 [256];
  uint local_30;
  
  local_30 = DAT_404f4224;
  uVar5 = (param_3 + 500U) / 1000;
  _Str = awStack_230;
  local_resc = param_4;
  local_338 = uVar5;
  local_334 = _Str;
  if (param_4 != 0) {
    uVar6 = uVar5 / 0xe10;
    if (uVar6 != 0) {
      pWVar4 = local_330;
      uVar5 = uVar5 % 0xe10;
      uVar3 = 1;
      if (uVar6 / 10 == 0) goto LAB_404edf6c;
      uVar1 = 10;
      do {
        uVar3 = uVar1;
        uVar1 = uVar3 * 10;
        if (uVar1 == 0) {
          trap(0x1c00);
        }
      } while (uVar6 / uVar1 != 0);
      for (; uVar3 != 0; uVar3 = uVar3 / 10) {
LAB_404edf6c:
        if (param_4 == 0) {
          *pWVar4 = L'0';
        }
        else {
          if (uVar3 == 0) {
            trap(0x1c00);
          }
          *pWVar4 = (short)(uVar6 / uVar3) + L'0';
          param_4 = param_4 + -1;
          uVar6 = uVar6 - (uVar6 / uVar3) * uVar3;
        }
        pWVar4 = pWVar4 + 1;
      }
      *pWVar4 = L'\0';
      local_resc = param_4;
      local_338 = uVar5;
      LoadStringW(DAT_404f4238,0x100,local_2b0,0x40);
      wsprintfW(awStack_230,local_2b0,local_330);
      sVar2 = wcslen(awStack_230);
      _Str = awStack_230 + sVar2;
    }
    local_334 = _Str;
    if ((param_4 != 0) && (uVar6 = uVar5 / 0x3c, uVar6 != 0)) {
      pWVar4 = local_2b0;
      local_338 = uVar5 % 0x3c;
      uVar5 = 1;
      if (uVar6 / 10 == 0) goto LAB_404ee080;
      uVar3 = 10;
      do {
        uVar5 = uVar3;
        uVar3 = uVar5 * 10;
        if (uVar3 == 0) {
          trap(0x1c00);
        }
      } while (uVar6 / uVar3 != 0);
      for (; uVar5 != 0; uVar5 = uVar5 / 10) {
LAB_404ee080:
        if (param_4 == 0) {
          *pWVar4 = L'0';
        }
        else {
          if (uVar5 == 0) {
            trap(0x1c00);
          }
          *pWVar4 = (short)(uVar6 / uVar5) + L'0';
          param_4 = param_4 + -1;
          uVar6 = uVar6 - (uVar6 / uVar5) * uVar5;
        }
        pWVar4 = pWVar4 + 1;
        local_resc = param_4;
      }
      *pWVar4 = L'\0';
      LoadStringW(DAT_404f4238,0x101,local_330,0x40);
      wsprintfW(_Str,local_330,local_2b0);
      sVar2 = wcslen(_Str);
      local_334 = _Str + sVar2;
    }
  }
  FUN_404edd04((int *)&local_334,DAT_404f4238,0x102,&local_338,&local_resc,1);
  sVar2 = wcslen(awStack_230);
  if (sVar2 < param_2) {
    wcscpy(param_1,awStack_230);
  }
  FUN_404f1430(local_30);
  return sVar2;
}



/* 404ee194 StrFromTimeIntervalW */

/* Boundary evidence: original MIPS .pdata 404ee194..404ee1af. Semantic name remains unreviewed. */

int StrFromTimeIntervalW(LPWSTR pwszOut,UINT cchMax,DWORD dwTimeMS,int digits)

{
  size_t sVar1;
  
                    /* 0x1e194  76  StrFromTimeIntervalW */
  sVar1 = FUN_404ede84(pwszOut,cchMax,dwTimeMS,digits);
  return sVar1;
}



/* 404ee1b0 FUN_404ee1b0 */

/* Boundary evidence: original MIPS .pdata 404ee1b0..404ee20b. Semantic name remains unreviewed. */

bool FUN_404ee1b0(int param_1,PCNZWCH param_2,PCNZWCH param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_1 == 0) {
    uVar2 = 0x10000001;
  }
  iVar1 = CompareStringW(0x800,uVar2 & 0xefffffff,param_2,param_4,param_3,param_4);
  return iVar1 == 2;
}



/* 404ee20c FUN_404ee20c */

/* Boundary evidence: original MIPS .pdata 404ee20c..404ee307. Semantic name remains unreviewed. */

void FUN_404ee20c(undefined4 param_1,undefined4 param_2,short *param_3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  longlong lVar6;
  short local_70 [40];
  uint local_20;
  
  lVar6 = CONCAT44(param_2,param_1);
  local_20 = DAT_404f4224;
  iVar4 = 0;
  uVar3 = 0;
  do {
    uVar5 = (undefined4)((ulonglong)lVar6 >> 0x20);
    sVar1 = __ll_rem((int)lVar6,uVar5,10,0);
    local_70[uVar3] = sVar1 + 0x30;
    uVar2 = uVar3 + 1;
    iVar4 = iVar4 + (uint)(uVar2 < uVar3);
    lVar6 = __ll_div((int)lVar6,uVar5,10,0);
    uVar3 = uVar2;
  } while (lVar6 != 0);
  do {
    uVar3 = uVar2 - 1;
    iVar4 = iVar4 - (uint)(uVar2 == 0);
    *param_3 = local_70[uVar3];
    param_3 = param_3 + 1;
    uVar2 = uVar3;
  } while (uVar3 != 0 || iVar4 != 0);
  *param_3 = 0;
  FUN_404f1430(local_20);
  return;
}



/* 404ee308 FUN_404ee308 */

/* Boundary evidence: original MIPS .pdata 404ee308..404ee3fb. Semantic name remains unreviewed. */

int FUN_404ee308(void)

{
  uint uVar1;
  int iVar2;
  WCHAR *pWVar3;
  WCHAR local_50;
  WCHAR local_4e [31];
  uint local_10;
  
  local_10 = DAT_404f4224;
  iVar2 = GetLocaleInfoW(0x400,0x10,&local_50,0x20);
  if (iVar2 == 0) {
    FUN_404f1430(local_10);
    iVar2 = 3;
  }
  else {
    iVar2 = 0;
    pWVar3 = &local_50;
    if (DAT_404f422c == 0) {
      iVar2 = StrToIntW(&local_50);
    }
    else {
      while (uVar1 = (uint)(ushort)local_50, uVar1 != 0x30) {
        if (uVar1 - 0x30 < 10) {
          iVar2 = iVar2 * 10 + uVar1 + -0x30;
        }
        else if (uVar1 == 0) {
          iVar2 = iVar2 * 10;
          break;
        }
        pWVar3 = pWVar3 + 1;
        local_50 = *pWVar3;
      }
    }
    FUN_404f1430(local_10);
  }
  return iVar2;
}



/* 404ee3fc FUN_404ee3fc */

/* Boundary evidence: original MIPS .pdata 404ee3fc..404ee4e3. Semantic name remains unreviewed. */

STRSAFE_LPWSTR
FUN_404ee3fc(undefined4 param_1,undefined4 param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  int iVar1;
  NUMBERFMTW local_98;
  WCHAR aWStack_80 [8];
  WCHAR aWStack_70 [40];
  uint local_20;
  
  local_20 = DAT_404f4224;
  local_98.NumDigits = 0;
  local_98.LeadingZero = 0;
  local_98.Grouping = FUN_404ee308();
  GetLocaleInfoW(0x400,0xf,aWStack_80,5);
  local_98.lpThousandSep = aWStack_80;
  local_98.lpDecimalSep = aWStack_80;
  local_98.NegativeOrder = 0;
  FUN_404ee20c(param_1,param_2,aWStack_70);
  iVar1 = GetNumberFormatW(0x400,0,aWStack_70,&local_98,param_3,param_4);
  if (iVar1 == 0) {
    StringCchCopyW(param_3,param_4,aWStack_70);
  }
  FUN_404f1430(local_20);
  return param_3;
}



/* 404ee4e4 StrFormatByteSizeW */

/* Boundary evidence: original MIPS .pdata 404ee4e4..404ee6fb. Semantic name remains unreviewed. */

LPWSTR StrFormatByteSizeW(LONGLONG qdw,LPWSTR pszBuf,UINT cchBuf)

{
  size_t sVar1;
  uint in_a0;
  int in_a1;
  uint uVar2;
  uint uVar3;
  wchar_t awStack_b8 [2];
  short local_b4;
  WCHAR aWStack_a8 [32];
  WCHAR aWStack_68 [32];
  uint local_28;
  
                    /* 0x1e4e4  75  StrFormatByteSizeW */
  local_28 = DAT_404f4224;
  if (pszBuf != (LPWSTR)0x0) {
    if ((in_a1 < 1) && ((in_a1 != 0 || (in_a0 < 0x400)))) {
      wnsprintfW(aWStack_a8,0x20,L"%d",in_a0);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
      do {
        if ((in_a1 < 0) || ((in_a1 == 0 && (in_a0 < 0xfa000)))) break;
        uVar2 = uVar2 + 1;
        in_a0 = in_a1 << 0x16 | in_a0 >> 10;
        in_a1 = in_a1 >> 10;
      } while (uVar2 < 6);
      FUN_404ee3fc(in_a1 << 0x16 | in_a0 >> 10,0,aWStack_a8,0x20);
      sVar1 = wcslen(aWStack_a8);
      if (sVar1 < 3) {
        uVar3 = ((in_a0 + (in_a0 >> 10) * -0x400) * 1000) / 0x2800;
        if (sVar1 == 2) {
          uVar3 = uVar3 / 10;
        }
        StringCchCopyW(awStack_b8,8,L"%02d");
        local_b4 = 0x33 - (short)sVar1;
        GetLocaleInfoW(0x400,0xe,aWStack_a8 + sVar1,0x20 - sVar1);
        sVar1 = wcslen(aWStack_a8);
        StringCchPrintfW(aWStack_a8 + sVar1,0x20 - sVar1,awStack_b8,uVar3);
      }
    }
    LoadStringW(DAT_404f4238,(int)(short)(&DAT_404dbc88)[uVar2],aWStack_68,0x20);
    StringCchPrintfW(pszBuf,cchBuf,aWStack_68,aWStack_a8);
  }
  FUN_404f1430(local_28);
  return pszBuf;
}



/* 404ee6fc StrCmpW */

/* Boundary evidence: original MIPS .pdata 404ee6fc..404ee73b. Semantic name remains unreviewed. */

int StrCmpW(LPCWSTR psz1,LPCWSTR psz2)

{
  int iVar1;
  
                    /* 0x1e6fc  70  StrCmpW */
  iVar1 = CompareStringW(0x800,0,psz1,-1,psz2,-1);
  return iVar1 + -2;
}



/* 404ee73c StrCmpIW */

/* Boundary evidence: original MIPS .pdata 404ee73c..404ee77b. Semantic name remains unreviewed. */

int StrCmpIW(LPCWSTR psz1,LPCWSTR psz2)

{
  int iVar1;
  
                    /* 0x1e73c  65  StrCmpIW */
  iVar1 = CompareStringW(0x800,1,psz1,-1,psz2,-1);
  return iVar1 + -2;
}



/* 404ee77c StrTrimW */

/* Boundary evidence: original MIPS .pdata 404ee77c..404ee8c7. Semantic name remains unreviewed. */

BOOL StrTrimW(LPWSTR psz,LPCWSTR pszTrimChars)

{
  WCHAR WVar1;
  BOOL BVar2;
  size_t sVar3;
  WCHAR WVar4;
  WCHAR *pWVar5;
  LPWSTR _Str;
  WCHAR *pWVar6;
  LPCWSTR pWVar7;
  WCHAR *pWVar8;
  
                    /* 0x1e77c  88  StrTrimW */
  BVar2 = 0;
  if ((psz != (LPWSTR)0x0) && (pszTrimChars != (LPCWSTR)0x0)) {
    pWVar8 = (WCHAR *)0x0;
    _Str = psz;
    if (*psz != L'\0') {
      do {
        if (*pszTrimChars != L'\0') {
          pWVar7 = pszTrimChars;
          WVar4 = *pszTrimChars;
          do {
            if (WVar4 == *_Str) goto LAB_404ee7ec;
            pWVar7 = pWVar7 + 1;
            WVar4 = *pWVar7;
          } while (WVar4 != L'\0');
        }
        pWVar7 = (WCHAR *)0x0;
LAB_404ee7ec:
      } while ((pWVar7 != (WCHAR *)0x0) && (_Str = _Str + 1, *_Str != L'\0'));
    }
    WVar4 = *_Str;
    if (WVar4 != L'\0') {
      WVar1 = *pszTrimChars;
      pWVar5 = pszTrimChars;
      pWVar6 = _Str;
joined_r0x404ee81c:
      do {
        if (WVar1 == L'\0') {
          pWVar5 = (WCHAR *)0x0;
        }
        else if (WVar1 != WVar4) {
          WVar1 = pWVar5[1];
          pWVar5 = pWVar5 + 1;
          goto joined_r0x404ee81c;
        }
        if (pWVar5 == (WCHAR *)0x0) {
          pWVar8 = (WCHAR *)0x0;
        }
        else if (pWVar8 == (WCHAR *)0x0) {
          pWVar8 = pWVar6;
        }
        pWVar6 = pWVar6 + 1;
        WVar4 = *pWVar6;
        WVar1 = *pszTrimChars;
        pWVar5 = pszTrimChars;
      } while (WVar4 != L'\0');
      if (pWVar8 != (WCHAR *)0x0) {
        *pWVar8 = L'\0';
        BVar2 = 1;
      }
    }
    if (psz < _Str) {
      sVar3 = wcslen(_Str);
      memmove(psz,_Str,(sVar3 + 1) * 2);
      BVar2 = 1;
    }
  }
  return BVar2;
}



/* 404ee8c8 StrCmpNCA */

int StrCmpNCA(LPCSTR lpStr1,LPCSTR lpStr2,int nChar)

{
  int iVar1;
  
                    /* 0x1e8c8  151  StrCmpNCA */
  if (nChar == 0) {
    iVar1 = 0;
  }
  else {
    for (; ((nChar = nChar + -1, nChar != 0 && (*lpStr1 != 0)) && (*lpStr1 == *lpStr2));
        lpStr1 = lpStr1 + 1) {
      lpStr2 = lpStr2 + 1;
    }
    iVar1 = (uint)(byte)*lpStr1 - (uint)(byte)*lpStr2;
  }
  return iVar1;
}



/* 404ee924 FUN_404ee924 */

int FUN_404ee924(ushort *param_1,ushort *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    for (; ((param_3 = param_3 + -1, param_3 != 0 && (*param_1 != 0)) && (*param_1 == *param_2));
        param_1 = param_1 + 1) {
      param_2 = param_2 + 1;
    }
    iVar1 = (uint)*param_1 - (uint)*param_2;
  }
  return iVar1;
}



/* 404ee980 StrCmpNICA */

int StrCmpNICA(LPCSTR lpStr1,LPCSTR lpStr2,int nChar)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1e980  153  StrCmpNICA */
  if (nChar == 0) {
    iVar1 = 0;
  }
  else {
    do {
      iVar1 = (int)*lpStr1;
      lpStr1 = lpStr1 + 1;
      if ((0x40 < iVar1) && (iVar1 < 0x5b)) {
        iVar1 = iVar1 + 0x20;
      }
      iVar2 = (int)*lpStr2;
      lpStr2 = lpStr2 + 1;
      if ((0x40 < iVar2) && (iVar2 < 0x5b)) {
        iVar2 = iVar2 + 0x20;
      }
      nChar = nChar + -1;
    } while (((nChar != 0) && (iVar1 != 0)) && (iVar1 == iVar2));
    iVar1 = iVar1 - iVar2;
  }
  return iVar1;
}



/* 404eea00 StrCmpNICW */

int StrCmpNICW(LPCWSTR lpStr1,LPCWSTR lpStr2,int nChar)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
                    /* 0x1ea00  154  StrCmpNICW */
  if (nChar == 0) {
    iVar1 = 0;
  }
  else {
    do {
      uVar2 = (uint)(ushort)*lpStr1;
      lpStr1 = lpStr1 + 1;
      if ((0x40 < uVar2) && (uVar2 < 0x5b)) {
        uVar2 = uVar2 + 0x20;
      }
      uVar3 = (uint)(ushort)*lpStr2;
      lpStr2 = lpStr2 + 1;
      if ((0x40 < uVar3) && (uVar3 < 0x5b)) {
        uVar3 = uVar3 + 0x20;
      }
      nChar = nChar + -1;
    } while (((nChar != 0) && (uVar2 != 0)) && (uVar2 == uVar3));
    iVar1 = uVar2 - uVar3;
  }
  return iVar1;
}



/* 404eea9c FUN_404eea9c */

int FUN_404eea9c(byte *param_1,byte *param_2)

{
  for (; (*param_1 != 0 && (*param_1 == *param_2)); param_1 = param_1 + 1) {
    param_2 = param_2 + 1;
  }
  return (uint)*param_1 - (uint)*param_2;
}



/* 404eead8 FUN_404eead8 */

int FUN_404eead8(ushort *param_1,ushort *param_2)

{
  for (; (*param_1 != 0 && (*param_1 == *param_2)); param_1 = param_1 + 1) {
    param_2 = param_2 + 1;
  }
  return (uint)*param_1 - (uint)*param_2;
}



/* 404eeaf8 StrCmpICW */

int StrCmpICW(LPCWSTR pszStr1,LPCWSTR pszStr2)

{
  uint uVar1;
  uint uVar2;
  
  do {
                    /* 0x1eaf8  158  StrCmpICW */
    uVar1 = (uint)(ushort)*pszStr1;
    pszStr1 = pszStr1 + 1;
    if ((0x40 < uVar1) && (uVar1 < 0x5b)) {
      uVar1 = uVar1 + 0x20;
    }
    uVar2 = (uint)(ushort)*pszStr2;
    pszStr2 = pszStr2 + 1;
    if ((0x40 < uVar2) && (uVar2 < 0x5b)) {
      uVar2 = uVar2 + 0x20;
    }
  } while ((uVar1 != 0) && (uVar1 == uVar2));
  return uVar1 - uVar2;
}



/* 404eeb58 StrRetToBufW */

/* Boundary evidence: original MIPS .pdata 404eeb58..404eec1b. Semantic name remains unreviewed. */

HRESULT StrRetToBufW(STRRET *pstr,LPCITEMIDLIST pidl,LPWSTR pszBuf,UINT cchBuf)

{
  _union_3888 *pszSrc;
  UINT UVar1;
  STRSAFE_LPCWSTR pszSrc_00;
  
                    /* 0x1eb58  81  StrRetToBufW */
  UVar1 = pstr->uType;
  if (UVar1 == 0) {
    pszSrc_00 = (pstr->u).pOleStr;
    if (pszSrc_00 == (STRSAFE_LPCWSTR)0x0) goto LAB_404eebfc;
    StringCchCopyW(pszBuf,cchBuf,pszSrc_00);
    CoTaskMemFree(pszSrc_00);
    pstr->uType = 2;
    (pstr->u).cStr[0] = '\0';
  }
  else {
    if (UVar1 == 1) {
      if (pidl == (LPCITEMIDLIST)0x0) goto LAB_404eebfc;
      pszSrc = (_union_3888 *)((int)(pstr->u).pOleStr + (int)pidl);
    }
    else {
      if (UVar1 != 2) {
LAB_404eebfc:
        if (cchBuf == 0) {
          return -0x7fffbffb;
        }
        *pszBuf = L'\0';
        return -0x7fffbffb;
      }
      pszSrc = &pstr->u;
    }
    SHAnsiToUnicode(pszSrc->cStr,pszBuf,cchBuf);
  }
  return 0;
}



/* 404eec1c SHStrDupW */

/* Boundary evidence: original MIPS .pdata 404eec1c..404eecab. Semantic name remains unreviewed. */

HRESULT SHStrDupW(LPCWSTR psz,LPWSTR *ppwsz)

{
  size_t sVar1;
  LPWSTR _Dst;
  HRESULT HVar2;
  undefined4 local_18;
  
                    /* 0x1ec1c  58  SHStrDupW */
  if (psz == (LPCWSTR)0x0) {
    _Dst = (LPWSTR)0x0;
  }
  else {
    sVar1 = wcslen(psz);
    local_18 = (sVar1 + 1) * 2;
    _Dst = LocalAlloc(0x40,local_18);
  }
  *ppwsz = _Dst;
  if (_Dst == (LPWSTR)0x0) {
    HVar2 = -0x7ff8fff2;
  }
  else {
    memcpy(_Dst,psz,local_18);
    HVar2 = 0;
  }
  return HVar2;
}



/* 404eecac FUN_404eecac */

/* Boundary evidence: original MIPS .pdata 404eecac..404eed57. Semantic name remains unreviewed. */

undefined4 FUN_404eecac(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (DAT_404f4424 == (int *)0x0) {
    CoGetClassObject((IID *)&DAT_404dbe4c,1,(LPVOID)0x0,(IID *)&DAT_404dbe3c,&DAT_404f4424);
    FUN_404dd2f0(0x404dbe4c);
    if (DAT_404f4424 == (int *)0x0) {
      *param_2 = 0;
      return 0x80004005;
    }
  }
  uVar1 = (**(code **)(*DAT_404f4424 + 0xc))(DAT_404f4424,0,param_1,param_2);
  return uVar1;
}



/* 404eed58 FUN_404eed58 */

/* Boundary evidence: original MIPS .pdata 404eed58..404eeef3. Semantic name remains unreviewed. */

int FUN_404eed58(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,int *param_9)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28 [2];
  
  iVar2 = -0x7ff8ffa9;
  if (param_1 != 0) {
    if ((param_9 == (int *)0x0) || (puVar1 = (undefined4 *)*param_9, puVar1 == (undefined4 *)0x0)) {
      iVar2 = FUN_404eecac(&DAT_404dbd4c,&local_30);
      if (iVar2 < 0) {
        return iVar2;
      }
      if (param_9 != (int *)0x0) {
        (**(code **)*local_30)(local_30,&DAT_404dbd4c,param_9);
      }
    }
    else {
      iVar2 = (**(code **)*puVar1)(puVar1,&DAT_404dbd4c,&local_30);
    }
    if (-1 < iVar2) {
      local_28[0] = 0;
      local_2c = 0;
      if (param_8 != 0) {
        (**(code **)(*local_30 + 0xc))(local_30,param_8);
      }
      if (param_4 == (undefined4 *)0x0) {
        param_5 = 4;
        param_4 = &local_2c;
      }
      if (param_2 == (undefined4 *)0x0) {
        param_3 = 4;
        param_2 = local_28;
      }
      iVar2 = (**(code **)(*local_30 + 0x1c))
                        (local_30,param_1,param_6,param_2,param_3,param_4,param_5,param_7,0);
      if (param_8 != 0) {
        (**(code **)(*local_30 + 0xc))(local_30,0);
      }
      (**(code **)(*local_30 + 8))();
    }
  }
  return iVar2;
}



/* 404eeef4 ZoneCheckUrlExW */

/* Boundary evidence: original MIPS .pdata 404eeef4..404eef2f. Semantic name remains unreviewed. */

void ZoneCheckUrlExW(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
                    /* 0x1eef4  231  ZoneCheckUrlExW */
  FUN_404eed58(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,(int *)0x0);
  return;
}



/* 404eef30 ZoneCheckHost */

/* Boundary evidence: original MIPS .pdata 404eef30..404eef87. Semantic name remains unreviewed. */

undefined4 ZoneCheckHost(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0x1ef30  234  ZoneCheckHost */
  local_c = 0;
  local_10 = 0;
  if (param_1 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_2,&local_c,4,&local_10,4,param_3,0);
  }
  return uVar1;
}



/* 404eef88 PathFileExistsA */

UINT PathFileExistsA(void)

{
                    /* 0x1ef88  9  PathFileExistsA
                       0x1ef88  276  WhichPlatform
                       0x1ef88  356  CreateAllAccessSecurityAttributes
                       0x1ef88  382  ZoneComputePaneSize
                       0x1ef88  476  SHGetObjectCompatFlags */
  return 0;
}



/* 404eef90 FUN_404eef90 */

/* Boundary evidence: original MIPS .pdata 404eef90..404ef04b. Semantic name remains unreviewed. */

int FUN_404eef90(LPCSTR param_1,int param_2,undefined4 *param_3)

{
  LPWSTR lpWideCharStr;
  int iVar1;
  uint cbMultiByte;
  
  iVar1 = 0;
  if ((0 < param_2) && (param_3 != (undefined4 *)0x0)) {
    cbMultiByte = param_2 + 1;
    if ((int)((ulonglong)cbMultiByte * 2 >> 0x20) == 0) {
      lpWideCharStr = LocalAlloc(0,(SIZE_T)((ulonglong)cbMultiByte * 2));
      *param_3 = lpWideCharStr;
      if (lpWideCharStr != (LPWSTR)0x0) {
        iVar1 = MultiByteToWideChar(0,0,param_1,cbMultiByte,lpWideCharStr,cbMultiByte);
        if (iVar1 == 0) {
          LocalFree((HLOCAL)*param_3);
          *param_3 = 0;
          iVar1 = 0;
        }
        else {
          iVar1 = iVar1 + -1;
        }
      }
    }
  }
  return iVar1;
}



/* 404ef04c FUN_404ef04c */

/* Boundary evidence: original MIPS .pdata 404ef04c..404ef11b. Semantic name remains unreviewed. */

int FUN_404ef04c(LPCWSTR param_1,int param_2,undefined4 *param_3)

{
  SIZE_T uBytes;
  LPSTR lpMultiByteStr;
  int iVar2;
  longlong lVar1;
  
  iVar2 = 0;
  if ((0 < param_2) && (param_3 != (undefined4 *)0x0)) {
    lVar1 = (ulonglong)(param_2 + 1U) * 2;
    uBytes = (SIZE_T)lVar1;
    if ((int)((ulonglong)lVar1 >> 0x20) == 0) {
      lpMultiByteStr = LocalAlloc(0,uBytes);
      *param_3 = lpMultiByteStr;
      if (lpMultiByteStr != (LPSTR)0x0) {
        iVar2 = WideCharToMultiByte(0,0,param_1,param_2 + 1U,lpMultiByteStr,uBytes,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        if (iVar2 == 0) {
          LocalFree((HLOCAL)*param_3);
          *param_3 = 0;
          iVar2 = 0;
        }
        else {
          iVar2 = iVar2 + -1;
        }
      }
    }
  }
  return iVar2;
}



/* 404ef11c FUN_404ef11c */

/* Boundary evidence: original MIPS .pdata 404ef11c..404ef22b. Semantic name remains unreviewed. */

undefined4
FUN_404ef11c(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            int param_5,undefined4 param_6,int param_7,int *param_8)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  
  lVar5 = CONCAT44(param_4,param_3);
  iVar4 = 7;
  *param_8 = 0;
  if (param_7 == 0) {
    iVar4 = 0x27;
  }
  if (param_5 != 0) {
    do {
      uVar2 = (undefined4)((ulonglong)lVar5 >> 0x20);
      iVar1 = __ull_rem((int)lVar5,uVar2,param_6,0);
      lVar5 = __ull_div((int)lVar5,uVar2,param_6,0);
      uVar3 = iVar1 + 0x30;
      if (0x39 < uVar3) {
        uVar3 = uVar3 + iVar4;
      }
      *param_1 = (char)uVar3;
      iVar1 = *param_8;
      *param_8 = iVar1 + 1;
      param_1 = param_1 + 1;
    } while ((iVar1 + 1 < param_5) && (lVar5 != 0));
  }
  if ((lVar5 != 0) || (uVar2 = 1, *param_8 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 404ef22c FUN_404ef22c */

char * FUN_404ef22c(char *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  cVar1 = *param_1;
  while ((iVar2 = (int)cVar1, 0x2f < iVar2 && (iVar2 < 0x3a))) {
    param_1 = param_1 + 1;
    iVar3 = iVar3 * 10 + iVar2 + -0x30;
    cVar1 = *param_1;
  }
  *param_2 = iVar3;
  return param_1;
}



/* 404ef280 FUN_404ef280 */

ushort * FUN_404ef280(ushort *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  for (; (uVar2 = (uint)*param_1, 0x2f < uVar2 && (uVar2 < 0x3a)); param_1 = param_1 + 1) {
    iVar1 = iVar1 * 10 + uVar2 + -0x30;
  }
  *param_2 = iVar1;
  return param_1;
}



/* 404ef2cc wvnsprintfA */

/* Boundary evidence: original MIPS .pdata 404ef2cc..404efc83. Semantic name remains unreviewed. */

int wvnsprintfA(LPSTR pszDest,int cchDest,LPCSTR pszFmt,va_list arglist)

{
  bool bVar1;
  bool bVar2;
  WCHAR WVar3;
  size_t sVar4;
  BOOL BVar5;
  size_t sVar6;
  int iVar7;
  BYTE *pBVar8;
  size_t *psVar9;
  BYTE BVar10;
  undefined4 *puVar11;
  ushort *puVar12;
  uint *puVar13;
  short *psVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  BYTE *pBVar18;
  int iVar19;
  LPCWSTR _Str;
  BYTE *pBVar20;
  int iVar21;
  size_t sVar22;
  int iVar23;
  BYTE local_58;
  uint *local_54;
  size_t local_50;
  size_t local_4c;
  LPCWSTR local_48;
  LPCWSTR local_44;
  int local_40;
  uint local_38;
  uint local_34;
  uint local_30;
  
                    /* 0x1f2cc  108  wvnsprintfA */
  local_30 = DAT_404f4224;
  iVar19 = cchDest + -1;
  local_4c = 0;
  local_48 = (LPCWSTR)0x0;
  local_44 = (LPCWSTR)0x0;
  local_40 = iVar19;
  if (iVar19 < 0) {
    FUN_404f1430(DAT_404f4224);
    iVar19 = 0;
  }
  else {
    BVar10 = *pszFmt;
    iVar7 = iVar19;
    pBVar18 = (BYTE *)pszDest;
    local_54 = (uint *)arglist;
    if (BVar10 != '\0') {
LAB_404ef360:
      iVar7 = iVar19;
      pBVar18 = (BYTE *)pszDest;
      if (BVar10 == '%') {
        pBVar8 = (BYTE *)(pszFmt + 1);
        iVar23 = 0;
        iVar21 = 0;
        BVar10 = *pBVar8;
        while (BVar10 != '\0') {
          if (BVar10 == '-') {
            iVar23 = iVar23 + 1;
          }
          else {
            if (BVar10 != '#') break;
            iVar21 = (iVar21 + 1) * 0x1000000 >> 0x18;
          }
          pBVar8 = pBVar8 + 1;
          BVar10 = *pBVar8;
        }
        if (*pBVar8 == '0') {
          local_58 = '0';
          pBVar8 = pBVar8 + 1;
        }
        else {
          local_58 = ' ';
        }
        psVar9 = &local_50;
        pszFmt = FUN_404ef22c((char *)pBVar8,(int *)psVar9);
        sVar4 = local_50;
        if (*pszFmt == '.') {
          psVar9 = &local_50;
          pszFmt = FUN_404ef22c(pszFmt + 1,(int *)psVar9);
          sVar22 = local_50;
        }
        else {
          sVar22 = 0xffffffff;
        }
        BVar10 = *pszFmt;
        bVar1 = false;
        if (BVar10 == 'w') {
          iVar15 = 2;
LAB_404ef42c:
          pszFmt = pszFmt + 1;
        }
        else {
          if (BVar10 == 'l') {
            pBVar8 = (BYTE *)(pszFmt + 1);
            goto LAB_404ef578;
          }
          if (BVar10 == 't') {
            iVar15 = 0;
            goto LAB_404ef42c;
          }
          if (BVar10 == 'I') {
            pBVar8 = (BYTE *)(pszFmt + 1);
            if ((*pBVar8 == '3') && (pszFmt[2] == '2')) {
              pBVar8 = (BYTE *)(pszFmt + 3);
            }
            else if ((*pBVar8 == '6') && (pszFmt[2] == '4')) {
              iVar15 = 3;
              pszFmt = pszFmt + 3;
              goto LAB_404ef43c;
            }
LAB_404ef578:
            pszFmt = (LPCSTR)pBVar8;
            iVar15 = 1;
          }
          else {
            iVar15 = 0;
            if (BVar10 == 'h') {
              pszFmt = pszFmt + 1;
              bVar1 = true;
            }
            else if ((BVar10 == 'i') || (BVar10 == 'd')) {
              iVar15 = 1;
            }
          }
        }
LAB_404ef43c:
        BVar10 = *pszFmt;
        iVar16 = 0;
        bVar2 = false;
        uVar17 = 10;
        if ((char)BVar10 < 'e') {
          if (BVar10 == 'd') {
LAB_404ef8e0:
            bVar2 = true;
LAB_404ef8e4:
            BVar10 = '\0';
LAB_404ef8e8:
            if ((iVar23 != 0) || (-1 < (int)sVar22)) {
              local_58 = ' ';
            }
            if (iVar15 == 3) {
              puVar13 = (uint *)((uint)((int)local_54 + 7) & 0xfffffff8);
              local_54 = puVar13 + 2;
              local_38 = *puVar13;
              local_34 = puVar13[1];
            }
            else {
              if (iVar15 == 0) {
                if (!bVar2) {
                  puVar13 = (uint *)((uint)((int)local_54 + 3) & 0xfffffffc);
                  local_54 = puVar13 + 1;
                  local_38 = *puVar13;
                  local_34 = 0;
                  goto LAB_404ef9bc;
                }
                psVar14 = (short *)((uint)((int)local_54 + 3) & 0xfffffffc);
                local_54 = (uint *)(psVar14 + 1);
                local_38 = (uint)*psVar14;
              }
              else {
                puVar13 = (uint *)((uint)((int)local_54 + 3) & 0xfffffffc);
                local_54 = puVar13 + 1;
                local_38 = *puVar13;
              }
              local_34 = (int)local_38 >> 0x1f;
            }
LAB_404ef9bc:
            if (((bVar2) && ((int)local_34 < 1)) && (local_34 != 0)) {
              local_34 = -(uint)(local_38 != 0) - local_34;
              local_38 = -local_38;
            }
            else {
              bVar2 = false;
            }
            if (iVar15 != 3) {
              local_34 = 0;
            }
            iVar7 = FUN_404ef11c(pszDest,psVar9,local_38,local_34,iVar19,uVar17,iVar16,
                                 (int *)&local_50);
            if (iVar7 != 0) {
              iVar21 = iVar19 - local_50;
              iVar15 = sVar22 - local_50;
              iVar16 = sVar4 - local_50;
              iVar7 = iVar21;
              if (0 < iVar15) {
                iVar16 = iVar16 - iVar15;
                iVar7 = iVar21 - iVar15;
              }
              if (0 < iVar16) {
                iVar7 = ((uint)bVar2 - iVar16) + iVar7;
              }
              if (bVar2) {
                iVar7 = iVar7 + -1;
              }
              if (iVar7 < 0) goto LAB_404ef4f4;
              pBVar8 = (BYTE *)(pszDest + local_50);
              while (pBVar18 = pBVar8, 0 < iVar15) {
                iVar15 = iVar15 + -1;
                iVar7 = 0;
                if (iVar21 == 0) goto LAB_404ef518;
                *pBVar8 = '0';
                pBVar8 = pBVar8 + 1;
                iVar21 = iVar21 + -1;
              }
              iVar7 = iVar21;
              if ((iVar16 < 1) || (iVar23 != 0)) {
                if (bVar2) {
                  if (iVar21 == 0) goto LAB_404ef518;
                  *pBVar8 = '-';
                  pBVar8 = pBVar8 + 1;
                  iVar21 = iVar21 + -1;
                  iVar16 = iVar16 + -1;
                }
                pBVar18 = pBVar8;
                if (BVar10 != '\0') {
                  iVar7 = iVar21;
                  if (iVar21 == 0) goto LAB_404ef518;
                  *pBVar8 = BVar10;
                  iVar7 = 0;
                  pBVar18 = pBVar8 + 1;
                  if (iVar21 == 1) goto LAB_404ef518;
                  pBVar8[1] = '0';
                  pBVar8 = pBVar8 + 2;
                  iVar21 = iVar21 + -2;
                  pBVar18 = pBVar8;
                }
                for (; pBVar8 = pBVar8 + -1, iVar19 = iVar21, pszDest < pBVar8;
                    pszDest = pszDest + 1) {
                  BVar10 = *pszDest;
                  *pszDest = *pBVar8;
                  *pBVar8 = BVar10;
                }
                while (pszDest = (LPSTR)pBVar18, 0 < iVar16) {
                  iVar16 = iVar16 + -1;
                  iVar7 = iVar19;
                  pBVar18 = (BYTE *)pszDest;
                  if (iVar19 == 0) goto LAB_404ef518;
                  *pszDest = local_58;
                  pBVar18 = (BYTE *)(pszDest + 1);
                  iVar19 = iVar19 + -1;
                }
              }
              else {
                if (local_58 != '0') {
                  if (bVar2) {
                    bVar2 = false;
                    if (iVar21 == 0) goto LAB_404ef518;
                    *pBVar8 = '-';
                    pBVar8 = pBVar8 + 1;
                    iVar21 = iVar21 + -1;
                    iVar16 = iVar16 + -1;
                  }
                  if (BVar10 != '\0') {
                    iVar7 = iVar21;
                    pBVar18 = pBVar8;
                    if (iVar21 == 0) goto LAB_404ef518;
                    *pBVar8 = BVar10;
                    iVar7 = 0;
                    pBVar18 = pBVar8 + 1;
                    if (iVar21 == 1) goto LAB_404ef518;
                    pBVar8[1] = '0';
                    pBVar8 = pBVar8 + 2;
                    iVar21 = iVar21 + -2;
                    BVar10 = '\0';
                  }
                }
                if (bVar2) {
                  iVar16 = iVar16 + -1;
                }
                while (pBVar18 = pBVar8, 0 < iVar16) {
                  iVar16 = iVar16 + -1;
                  iVar7 = 0;
                  if (iVar21 == 0) goto LAB_404ef518;
                  *pBVar8 = local_58;
                  pBVar8 = pBVar8 + 1;
                  iVar21 = iVar21 + -1;
                }
                if (bVar2) {
                  iVar7 = iVar21;
                  if (iVar21 == 0) goto LAB_404ef518;
                  *pBVar8 = '-';
                  pBVar8 = pBVar8 + 1;
                  iVar21 = iVar21 + -1;
                }
                pBVar20 = (BYTE *)pszDest;
                pBVar18 = pBVar8;
                iVar19 = iVar21;
                if (BVar10 != '\0') {
                  iVar7 = iVar21;
                  if (iVar21 == 0) goto LAB_404ef518;
                  *pBVar8 = BVar10;
                  iVar7 = 0;
                  pBVar18 = pBVar8 + 1;
                  if (iVar21 == 1) goto LAB_404ef518;
                  pBVar8[1] = '0';
                  pBVar8 = pBVar8 + 2;
                  iVar19 = iVar21 + -2;
                  pBVar18 = pBVar8;
                }
                for (; pszDest = (LPSTR)pBVar18, pBVar8 = pBVar8 + -1, pBVar20 < pBVar8;
                    pBVar20 = pBVar20 + 1) {
                  BVar10 = *pBVar20;
                  *pBVar20 = *pBVar8;
                  *pBVar8 = BVar10;
                  pBVar18 = (BYTE *)pszDest;
                }
              }
            }
            goto LAB_404ef4f4;
          }
          if (BVar10 == '\0') goto LAB_404ef518;
          if (BVar10 == 'C') {
            if ((iVar15 == 0) && (!bVar1)) {
              iVar15 = 1;
            }
LAB_404ef6ac:
            sVar6 = 1;
            _Str = (LPCWSTR)&local_38;
            puVar12 = (ushort *)((uint)((int)local_54 + 3) & 0xfffffffc);
            if (iVar15 == 0) {
              local_54 = (uint *)((int)puVar12 + 1);
              local_38._0_2_ = (WCHAR)(byte)*puVar12;
              goto LAB_404ef7c0;
            }
            local_54 = (uint *)(puVar12 + 1);
            local_38 = (uint)*puVar12;
          }
          else {
            if (BVar10 != 'S') {
              if (BVar10 == 'X') goto LAB_404ef8bc;
              if (BVar10 != 'c') goto LAB_404ef49c;
              goto LAB_404ef6ac;
            }
            if ((iVar15 == 0) && (bVar1)) goto LAB_404ef664;
LAB_404ef74c:
            puVar11 = (undefined4 *)((uint)((int)local_54 + 3) & 0xfffffffc);
            local_54 = puVar11 + 1;
            _Str = (LPCWSTR)*puVar11;
            if (_Str == (wchar_t *)0x0) {
              sVar6 = 0;
            }
            else {
              sVar6 = wcslen(_Str);
            }
          }
          sVar6 = FUN_404ef04c(_Str,sVar6,&local_44);
          local_48 = local_44;
          _Str = local_44;
          local_4c = sVar6;
        }
        else {
          if (BVar10 == 'i') goto LAB_404ef8e0;
          if (BVar10 == 'p') {
            iVar15 = 1;
            if (sVar22 == 0xffffffff) {
              sVar22 = 8;
            }
LAB_404ef8bc:
            iVar16 = 1;
LAB_404ef8c4:
            uVar17 = 0x10;
            BVar10 = '\0';
            if ((iVar21 != 0) && (BVar10 = 'x', iVar16 != 0)) {
              BVar10 = 'X';
            }
            goto LAB_404ef8e8;
          }
          if (BVar10 != 's') {
            if (BVar10 != 'u') {
              if (BVar10 != 'x') goto LAB_404ef49c;
              goto LAB_404ef8c4;
            }
            goto LAB_404ef8e4;
          }
          if (iVar15 != 0) goto LAB_404ef74c;
LAB_404ef664:
          puVar11 = (undefined4 *)((uint)((int)local_54 + 3) & 0xfffffffc);
          local_54 = puVar11 + 1;
          _Str = (LPCWSTR)*puVar11;
          if (_Str == (LPCWSTR)0x0) {
            sVar6 = 0;
          }
          else {
            sVar6 = strlen((char *)_Str);
          }
        }
LAB_404ef7c0:
        if ((-1 < (int)sVar22) && ((int)sVar22 < (int)sVar6)) {
          sVar6 = sVar22;
        }
        iVar21 = sVar4 - sVar6;
        if (iVar23 == 0) {
          while (0 < iVar21) {
            iVar21 = iVar21 + -1;
            iVar7 = 0;
            pBVar18 = (BYTE *)pszDest;
            if (iVar19 == 0) goto LAB_404ef518;
            *pszDest = local_58;
            pszDest = pszDest + 1;
            iVar19 = iVar19 + -1;
          }
          while (sVar6 != 0) {
            sVar6 = sVar6 - 1;
            iVar7 = 0;
            pBVar18 = (BYTE *)pszDest;
            if (iVar19 == 0) goto LAB_404ef518;
            WVar3 = *_Str;
            _Str = (LPCWSTR)((int)_Str + 1);
            *pszDest = (BYTE)WVar3;
            pszDest = pszDest + 1;
            iVar19 = iVar19 + -1;
          }
        }
        else {
          while (sVar6 != 0) {
            sVar6 = sVar6 - 1;
            iVar7 = 0;
            pBVar18 = (BYTE *)pszDest;
            if (iVar19 == 0) goto LAB_404ef518;
            WVar3 = *_Str;
            _Str = (LPCWSTR)((int)_Str + 1);
            *pszDest = (BYTE)WVar3;
            pszDest = pszDest + 1;
            iVar19 = iVar19 + -1;
          }
          local_50 = 0xffffffff;
          while (0 < iVar21) {
            iVar21 = iVar21 + -1;
            iVar7 = 0;
            pBVar18 = (BYTE *)pszDest;
            if (iVar19 == 0) goto LAB_404ef518;
            *pszDest = local_58;
            pszDest = pszDest + 1;
            iVar19 = iVar19 + -1;
          }
        }
        local_50 = 0xffffffff;
        if (local_4c != 0) {
          LocalFree(local_48);
          local_4c = 0;
        }
      }
      else {
LAB_404ef49c:
        BVar5 = IsDBCSLeadByte(BVar10);
        if (BVar5 != 0) {
          if (iVar19 == 0) goto LAB_404ef518;
          BVar10 = *pszFmt;
          pszFmt = pszFmt + 1;
          *pszDest = BVar10;
          pszDest = pszDest + 1;
          iVar19 = iVar19 + -1;
          if (*pszFmt == '\0') goto LAB_404ef4f4;
        }
        iVar7 = iVar19;
        pBVar18 = (BYTE *)pszDest;
        if (iVar19 == 0) goto LAB_404ef518;
        iVar19 = iVar19 + -1;
        *pszDest = *pszFmt;
        pszDest = pszDest + 1;
      }
LAB_404ef4f4:
      pszFmt = pszFmt + 1;
      BVar10 = *pszFmt;
      iVar7 = iVar19;
      pBVar18 = (BYTE *)pszDest;
      if (BVar10 == '\0') goto LAB_404ef518;
      goto LAB_404ef360;
    }
LAB_404ef518:
    iVar19 = local_40;
    *pBVar18 = '\0';
    if (local_4c != 0) {
      LocalFree(local_48);
    }
    iVar19 = iVar19 - iVar7;
    FUN_404f1430(local_30);
  }
  return iVar19;
}



/* 404efc84 wnsprintfA */

/* Boundary evidence: original MIPS .pdata 404efc84..404efca7. Semantic name remains unreviewed. */

int wnsprintfA(LPSTR pszDest,int cchDest,LPCSTR pszFmt,...)

{
  int iVar1;
  undefined4 in_a3;
  undefined4 local_resc;
  
                    /* 0x1fc84  106  wnsprintfA */
  local_resc = in_a3;
  iVar1 = wvnsprintfA(pszDest,cchDest,pszFmt,(va_list)&local_resc);
  return iVar1;
}



/* 404efca8 FUN_404efca8 */

/* Boundary evidence: original MIPS .pdata 404efca8..404efdb7. Semantic name remains unreviewed. */

undefined4
FUN_404efca8(undefined2 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            int param_5,undefined4 param_6,int param_7,int *param_8)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  
  lVar5 = CONCAT44(param_4,param_3);
  iVar4 = 7;
  *param_8 = 0;
  if (param_7 == 0) {
    iVar4 = 0x27;
  }
  if (param_5 != 0) {
    do {
      uVar2 = (undefined4)((ulonglong)lVar5 >> 0x20);
      iVar1 = __ull_rem((int)lVar5,uVar2,param_6,0);
      lVar5 = __ull_div((int)lVar5,uVar2,param_6,0);
      uVar3 = iVar1 + 0x30;
      if (0x39 < uVar3) {
        uVar3 = uVar3 + iVar4;
      }
      *param_1 = (short)uVar3;
      iVar1 = *param_8;
      *param_8 = iVar1 + 1;
      param_1 = param_1 + 1;
    } while ((iVar1 + 1 < param_5) && (lVar5 != 0));
  }
  if ((lVar5 != 0) || (uVar2 = 1, *param_8 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 404efdb8 FUN_404efdb8 */

/* Boundary evidence: original MIPS .pdata 404efdb8..404f0757. Semantic name remains unreviewed. */

int FUN_404efdb8(wchar_t *param_1,int param_2,wchar_t *param_3,uint *param_4)

{
  bool bVar1;
  bool bVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  size_t *psVar6;
  short sVar7;
  wchar_t wVar8;
  ushort *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  uint *puVar12;
  short *psVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  wchar_t *pwVar18;
  int iVar19;
  wchar_t *pwVar20;
  wchar_t *pwVar21;
  size_t sVar22;
  int iVar23;
  uint *local_58;
  wchar_t local_54;
  size_t local_50;
  size_t local_4c;
  wchar_t *local_48;
  wchar_t *local_44;
  int local_40;
  uint local_38;
  uint local_34;
  uint local_30;
  
  local_30 = DAT_404f4224;
  iVar19 = param_2 + -1;
  local_4c = 0;
  local_48 = (wchar_t *)0x0;
  local_44 = (wchar_t *)0x0;
  local_40 = iVar19;
  if (iVar19 < 0) {
    FUN_404f1430(DAT_404f4224);
    iVar19 = 0;
  }
  else {
    wVar8 = *param_3;
    iVar5 = iVar19;
    pwVar18 = param_1;
    local_58 = param_4;
    if (wVar8 != L'\0') {
LAB_404efe4c:
      iVar5 = iVar19;
      pwVar18 = param_1;
      if (wVar8 == L'%') {
        pwVar20 = param_3 + 1;
        iVar23 = 0;
        sVar7 = 0;
        wVar8 = *pwVar20;
        while (wVar8 != L'\0') {
          if (wVar8 == L'-') {
            iVar23 = iVar23 + 1;
          }
          else {
            if (wVar8 != L'#') break;
            sVar7 = sVar7 + 1;
          }
          pwVar20 = pwVar20 + 1;
          wVar8 = *pwVar20;
        }
        if (*pwVar20 == L'0') {
          local_54 = L'0';
          pwVar20 = pwVar20 + 1;
        }
        else {
          local_54 = L' ';
        }
        psVar6 = &local_50;
        param_3 = (wchar_t *)FUN_404ef280((ushort *)pwVar20,(int *)psVar6);
        sVar3 = local_50;
        if (*param_3 == L'.') {
          psVar6 = &local_50;
          param_3 = (wchar_t *)FUN_404ef280((ushort *)(param_3 + 1),(int *)psVar6);
          sVar22 = local_50;
        }
        else {
          sVar22 = 0xffffffff;
        }
        wVar8 = *param_3;
        bVar1 = false;
        if ((wVar8 == L'w') || (wVar8 == L't')) {
          iVar15 = 2;
          param_3 = param_3 + 1;
        }
        else {
          if (wVar8 == L'l') {
            pwVar20 = param_3 + 1;
          }
          else {
            if (wVar8 != L'I') {
              iVar15 = 0;
              if (wVar8 == L'h') {
                param_3 = param_3 + 1;
                bVar1 = true;
              }
              else if ((wVar8 == L'i') || (wVar8 == L'd')) {
                iVar15 = 1;
              }
              goto LAB_404f000c;
            }
            pwVar20 = param_3 + 1;
            if ((*pwVar20 == L'3') && (param_3[2] == L'2')) {
              pwVar20 = param_3 + 3;
            }
            else if ((*pwVar20 == L'6') && (param_3[2] == L'4')) {
              iVar15 = 3;
              param_3 = param_3 + 3;
              goto LAB_404f000c;
            }
          }
          param_3 = pwVar20;
          iVar15 = 1;
        }
LAB_404f000c:
        wVar8 = *param_3;
        iVar16 = 0;
        bVar2 = false;
        uVar17 = 10;
        if ((ushort)wVar8 < 0x65) {
          if (wVar8 == L'd') {
LAB_404f03a8:
            bVar2 = true;
LAB_404f03b4:
            wVar8 = L'\0';
LAB_404f03b8:
            if ((iVar23 != 0) || (-1 < (int)sVar22)) {
              local_54 = L' ';
            }
            if (iVar15 == 3) {
              puVar12 = (uint *)((uint)((int)local_58 + 7) & 0xfffffff8);
              local_58 = puVar12 + 2;
              local_38 = *puVar12;
              local_34 = puVar12[1];
            }
            else {
              if (iVar15 == 0) {
                if (!bVar2) {
                  puVar12 = (uint *)((uint)((int)local_58 + 3) & 0xfffffffc);
                  local_58 = puVar12 + 1;
                  local_38 = *puVar12;
                  local_34 = 0;
                  goto LAB_404f048c;
                }
                psVar13 = (short *)((uint)((int)local_58 + 3) & 0xfffffffc);
                local_58 = (uint *)(psVar13 + 1);
                local_38 = (uint)*psVar13;
              }
              else {
                puVar12 = (uint *)((uint)((int)local_58 + 3) & 0xfffffffc);
                local_58 = puVar12 + 1;
                local_38 = *puVar12;
              }
              local_34 = (int)local_38 >> 0x1f;
            }
LAB_404f048c:
            if (((bVar2) && ((int)local_34 < 1)) && (local_34 != 0)) {
              local_34 = -(uint)(local_38 != 0) - local_34;
              local_38 = -local_38;
            }
            else {
              bVar2 = false;
            }
            if (iVar15 != 3) {
              local_34 = 0;
            }
            iVar5 = FUN_404efca8(param_1,psVar6,local_38,local_34,iVar19,uVar17,iVar16,
                                 (int *)&local_50);
            if (iVar5 == 0) goto LAB_404f02f0;
            iVar15 = iVar19 - local_50;
            iVar16 = sVar22 - local_50;
            iVar14 = sVar3 - local_50;
            iVar5 = iVar15;
            if (0 < iVar16) {
              iVar14 = iVar14 - iVar16;
              iVar5 = iVar15 - iVar16;
            }
            if (0 < iVar14) {
              iVar5 = ((uint)bVar2 - iVar14) + iVar5;
            }
            if (bVar2) {
              iVar5 = iVar5 + -1;
            }
            if (-1 < iVar5) {
              pwVar20 = param_1 + local_50;
              while (pwVar18 = pwVar20, 0 < iVar16) {
                iVar16 = iVar16 + -1;
                iVar5 = 0;
                if (iVar15 == 0) goto LAB_404f0314;
                *pwVar20 = L'0';
                pwVar20 = pwVar20 + 1;
                iVar15 = iVar15 + -1;
              }
              iVar5 = iVar15;
              if ((iVar14 < 1) || (iVar23 != 0)) {
                if (bVar2) {
                  if (iVar15 == 0) goto LAB_404f0314;
                  *pwVar20 = L'-';
                  pwVar20 = pwVar20 + 1;
                  iVar15 = iVar15 + -1;
                  iVar14 = iVar14 + -1;
                }
                pwVar18 = pwVar20;
                if (wVar8 != L'\0') {
                  iVar5 = iVar15;
                  if (iVar15 == 0) goto LAB_404f0314;
                  *pwVar20 = wVar8;
                  iVar5 = 0;
                  pwVar18 = pwVar20 + 1;
                  if (iVar15 == 1) goto LAB_404f0314;
                  pwVar20[1] = L'0';
                  pwVar20 = pwVar20 + 2;
                  iVar15 = iVar15 + -2;
                  pwVar18 = pwVar20;
                }
                for (; pwVar20 = pwVar20 + -1, iVar19 = iVar15, param_1 < pwVar20;
                    param_1 = param_1 + 1) {
                  wVar8 = *param_1;
                  *param_1 = *pwVar20;
                  *pwVar20 = wVar8;
                }
                while (param_1 = pwVar18, 0 < iVar14) {
                  iVar14 = iVar14 + -1;
                  iVar5 = iVar19;
                  pwVar18 = param_1;
                  if (iVar19 == 0) goto LAB_404f0314;
                  *param_1 = local_54;
                  pwVar18 = param_1 + 1;
                  iVar19 = iVar19 + -1;
                }
              }
              else {
                if (local_54 != L'0') {
                  if (bVar2) {
                    bVar2 = false;
                    if (iVar15 == 0) goto LAB_404f0314;
                    *pwVar20 = L'-';
                    pwVar20 = pwVar20 + 1;
                    iVar15 = iVar15 + -1;
                    iVar14 = iVar14 + -1;
                  }
                  if (wVar8 != L'\0') {
                    iVar5 = iVar15;
                    pwVar18 = pwVar20;
                    if (iVar15 == 0) goto LAB_404f0314;
                    *pwVar20 = wVar8;
                    iVar5 = 0;
                    pwVar18 = pwVar20 + 1;
                    if (iVar15 == 1) goto LAB_404f0314;
                    pwVar20[1] = L'0';
                    pwVar20 = pwVar20 + 2;
                    iVar15 = iVar15 + -2;
                    wVar8 = L'\0';
                  }
                }
                if (bVar2) {
                  iVar14 = iVar14 + -1;
                }
                while (pwVar18 = pwVar20, 0 < iVar14) {
                  iVar14 = iVar14 + -1;
                  iVar5 = 0;
                  if (iVar15 == 0) goto LAB_404f0314;
                  *pwVar20 = local_54;
                  pwVar20 = pwVar20 + 1;
                  iVar15 = iVar15 + -1;
                }
                if (bVar2) {
                  iVar5 = iVar15;
                  if (iVar15 == 0) goto LAB_404f0314;
                  *pwVar20 = L'-';
                  pwVar20 = pwVar20 + 1;
                  iVar15 = iVar15 + -1;
                }
                pwVar21 = param_1;
                pwVar18 = pwVar20;
                iVar19 = iVar15;
                if (wVar8 != L'\0') {
                  iVar5 = iVar15;
                  if (iVar15 == 0) goto LAB_404f0314;
                  *pwVar20 = wVar8;
                  iVar5 = 0;
                  pwVar18 = pwVar20 + 1;
                  if (iVar15 == 1) goto LAB_404f0314;
                  pwVar20[1] = L'0';
                  pwVar20 = pwVar20 + 2;
                  iVar19 = iVar15 + -2;
                  pwVar18 = pwVar20;
                }
                for (; param_1 = pwVar18, pwVar20 = pwVar20 + -1, pwVar21 < pwVar20;
                    pwVar21 = pwVar21 + 1) {
                  wVar8 = *pwVar21;
                  *pwVar21 = *pwVar20;
                  *pwVar20 = wVar8;
                  pwVar18 = param_1;
                }
              }
            }
            goto LAB_404f02f0;
          }
          if (wVar8 == L'\0') goto LAB_404f0314;
          if (wVar8 == L'C') {
LAB_404f0080:
            sVar4 = 1;
            pwVar20 = (wchar_t *)&local_38;
            if (iVar15 == 0) {
              pbVar10 = (byte *)((uint)((int)local_58 + 3) & 0xfffffffc);
              local_58 = (uint *)(pbVar10 + 1);
              local_38._0_2_ = (wchar_t)*pbVar10;
              goto LAB_404f019c;
            }
            puVar9 = (ushort *)((uint)((int)local_58 + 3) & 0xfffffffc);
            local_58 = (uint *)(puVar9 + 1);
            local_38 = (uint)*puVar9;
          }
          else {
            if (wVar8 != L'S') {
              if (wVar8 == L'X') goto LAB_404f0374;
              if (wVar8 != L'c') goto LAB_404f012c;
              if ((iVar15 == 0) && (!bVar1)) {
                iVar15 = 1;
              }
              goto LAB_404f0080;
            }
LAB_404f0158:
            if (iVar15 == 0) goto LAB_404f0160;
LAB_404f01c4:
            puVar11 = (undefined4 *)((uint)((int)local_58 + 3) & 0xfffffffc);
            local_58 = puVar11 + 1;
            pwVar20 = (wchar_t *)*puVar11;
            if (pwVar20 == (wchar_t *)0x0) {
              sVar4 = 0;
            }
            else {
              sVar4 = wcslen(pwVar20);
            }
          }
        }
        else {
          if (wVar8 == L'i') goto LAB_404f03a8;
          if (wVar8 == L'p') {
            iVar15 = 1;
            if (sVar22 == 0xffffffff) {
              sVar22 = 8;
            }
LAB_404f0374:
            iVar16 = 1;
LAB_404f0384:
            uVar17 = 0x10;
            wVar8 = L'\0';
            if (sVar7 != 0) {
              if (iVar16 == 0) {
                wVar8 = L'x';
              }
              else {
                wVar8 = L'X';
              }
            }
            goto LAB_404f03b8;
          }
          if (wVar8 != L's') {
            if (wVar8 != L'u') {
              if (wVar8 != L'x') goto LAB_404f012c;
              goto LAB_404f0384;
            }
            goto LAB_404f03b4;
          }
          if (iVar15 != 0) goto LAB_404f01c4;
          if (!bVar1) {
            iVar15 = 1;
            goto LAB_404f0158;
          }
LAB_404f0160:
          puVar11 = (undefined4 *)((uint)((int)local_58 + 3) & 0xfffffffc);
          local_58 = puVar11 + 1;
          pwVar20 = (wchar_t *)*puVar11;
          if (pwVar20 == (wchar_t *)0x0) {
            sVar4 = 0;
          }
          else {
            sVar4 = strlen((char *)pwVar20);
          }
LAB_404f019c:
          sVar4 = FUN_404eef90((LPCSTR)pwVar20,sVar4,&local_44);
          local_48 = local_44;
          pwVar20 = local_44;
          local_4c = sVar4;
        }
        if ((-1 < (int)sVar22) && ((int)sVar22 < (int)sVar4)) {
          sVar4 = sVar22;
        }
        iVar15 = sVar3 - sVar4;
        if (iVar23 == 0) {
          while (0 < iVar15) {
            iVar15 = iVar15 + -1;
            iVar5 = 0;
            pwVar18 = param_1;
            if (iVar19 == 0) goto LAB_404f0314;
            *param_1 = local_54;
            param_1 = param_1 + 1;
            iVar19 = iVar19 + -1;
          }
          while (sVar4 != 0) {
            sVar4 = sVar4 - 1;
            iVar5 = 0;
            pwVar18 = param_1;
            if (iVar19 == 0) goto LAB_404f0314;
            wVar8 = *pwVar20;
            pwVar20 = pwVar20 + 1;
            *param_1 = wVar8;
            param_1 = param_1 + 1;
            iVar19 = iVar19 + -1;
          }
        }
        else {
          while (sVar4 != 0) {
            sVar4 = sVar4 - 1;
            iVar5 = 0;
            pwVar18 = param_1;
            if (iVar19 == 0) goto LAB_404f0314;
            wVar8 = *pwVar20;
            pwVar20 = pwVar20 + 1;
            *param_1 = wVar8;
            param_1 = param_1 + 1;
            iVar19 = iVar19 + -1;
          }
          local_50 = 0xffffffff;
          while (0 < iVar15) {
            iVar15 = iVar15 + -1;
            iVar5 = 0;
            pwVar18 = param_1;
            if (iVar19 == 0) goto LAB_404f0314;
            *param_1 = local_54;
            param_1 = param_1 + 1;
            iVar19 = iVar19 + -1;
          }
        }
        local_50 = 0xffffffff;
        if (local_4c != 0) {
          LocalFree(local_48);
          local_4c = 0;
        }
      }
      else {
LAB_404f012c:
        if (iVar19 == 0) goto LAB_404f0314;
        *param_1 = wVar8;
        param_1 = param_1 + 1;
        iVar19 = iVar19 + -1;
      }
LAB_404f02f0:
      param_3 = param_3 + 1;
      wVar8 = *param_3;
      iVar5 = iVar19;
      pwVar18 = param_1;
      if (wVar8 == L'\0') goto LAB_404f0314;
      goto LAB_404efe4c;
    }
LAB_404f0314:
    iVar19 = local_40;
    *pwVar18 = L'\0';
    if (local_4c != 0) {
      LocalFree(local_48);
    }
    iVar19 = iVar19 - iVar5;
    FUN_404f1430(local_30);
  }
  return iVar19;
}



/* 404f0758 wnsprintfW */

/* Boundary evidence: original MIPS .pdata 404f0758..404f077b. Semantic name remains unreviewed. */

int wnsprintfW(LPWSTR pszDest,int cchDest,LPCWSTR pszFmt,...)

{
  int iVar1;
  uint in_a3;
  uint local_resc;
  
                    /* 0x20758  107  wnsprintfW */
  local_resc = in_a3;
  iVar1 = FUN_404efdb8(pszDest,cchDest,pszFmt,&local_resc);
  return iVar1;
}



/* 404f077c FUN_404f077c */

undefined1 * FUN_404f077c(undefined1 *param_1)

{
  *param_1 = 0;
  *(undefined1 **)(param_1 + 0x44) = param_1;
  *(undefined4 *)(param_1 + 0x48) = 0x41;
  return param_1;
}



/* 404f0794 FUN_404f0794 */

/* Boundary evidence: original MIPS .pdata 404f0794..404f07e7. Semantic name remains unreviewed. */

void FUN_404f0794(undefined1 *param_1)

{
  if ((*(HLOCAL *)(param_1 + 0x44) != (HLOCAL)0x0) && (*(int *)(param_1 + 0x48) != 0x41)) {
    LocalFree(*(HLOCAL *)(param_1 + 0x44));
  }
  *(undefined4 *)(param_1 + 0x48) = 0x41;
  *param_1 = 0;
  *(undefined1 **)(param_1 + 0x44) = param_1;
  return;
}



/* 404f07e8 FUN_404f07e8 */

/* Boundary evidence: original MIPS .pdata 404f07e8..404f08db. Semantic name remains unreviewed. */

undefined4 FUN_404f07e8(char *param_1,uint param_2)

{
  char *_Dest;
  uint uVar1;
  uint uBytes;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = *(uint *)(param_1 + 0x48);
  for (uBytes = uVar1; uBytes < param_2; uBytes = uBytes << 2) {
  }
  if (uBytes != uVar1) {
    if (uBytes < 0x42) {
      if ((*(char **)(param_1 + 0x44) != (char *)0x0) && (uVar1 != 0)) {
        strncpy(param_1,*(char **)(param_1 + 0x44),0x41);
      }
      FUN_404f0794(param_1);
      *(char **)(param_1 + 0x44) = param_1;
    }
    else {
      _Dest = LocalAlloc(0x40,uBytes);
      if (_Dest == (char *)0x0) {
        uVar2 = 0x8007000e;
      }
      else {
        strncpy(_Dest,*(char **)(param_1 + 0x44),param_2);
        FUN_404f0794(param_1);
        *(uint *)(param_1 + 0x48) = uBytes;
        *(char **)(param_1 + 0x44) = _Dest;
      }
    }
  }
  return uVar2;
}



/* 404f08dc FUN_404f08dc */

/* Boundary evidence: original MIPS .pdata 404f08dc..404f094f. Semantic name remains unreviewed. */

int FUN_404f08dc(char *param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  
  iVar2 = 1;
  if (((param_2 != (char *)0x0) && (sVar1 = strlen(param_2), sVar1 != 0)) &&
     (iVar2 = FUN_404f07e8(param_1,sVar1 + 1), -1 < iVar2)) {
    strcpy(*(char **)(param_1 + 0x44),param_2);
  }
  return iVar2;
}



/* 404f0950 FUN_404f0950 */

/* Boundary evidence: original MIPS .pdata 404f0950..404f0a5b. Semantic name remains unreviewed. */

int FUN_404f0950(char *param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  if ((param_2 != (LPCWSTR)0x0) && (param_3 != 0)) {
    iVar1 = param_3;
    if (param_3 == -1) {
      iVar1 = WideCharToMultiByte(0,0,param_2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    }
    if ((iVar1 != 0) && (iVar3 = FUN_404f07e8(param_1,iVar1 + 1), -1 < iVar3)) {
      uVar2 = WideCharToMultiByte(0,0,param_2,param_3,*(LPSTR *)(param_1 + 0x44),
                                  *(int *)(param_1 + 0x48),(LPCSTR)0x0,(LPBOOL)0x0);
      if (*(uint *)(param_1 + 0x48) <= uVar2) {
        uVar2 = *(uint *)(param_1 + 0x48) - 1;
      }
      *(undefined1 *)(uVar2 + *(int *)(param_1 + 0x44)) = 0;
    }
  }
  return iVar3;
}



/* 404f0a5c FUN_404f0a5c */

/* Boundary evidence: original MIPS .pdata 404f0a5c..404f0a9b. Semantic name remains unreviewed. */

void FUN_404f0a5c(char *param_1,char *param_2)

{
  FUN_404f0794(param_1);
  FUN_404f08dc(param_1,param_2);
  return;
}



/* 404f0a9c FUN_404f0a9c */

/* Boundary evidence: original MIPS .pdata 404f0a9c..404f0aeb. Semantic name remains unreviewed. */

void FUN_404f0a9c(char *param_1,LPCWSTR param_2,int param_3)

{
  FUN_404f0794(param_1);
  FUN_404f0950(param_1,param_2,param_3);
  return;
}



/* 404f0aec FUN_404f0aec */

undefined2 * FUN_404f0aec(undefined2 *param_1)

{
  *param_1 = 0;
  *(undefined2 **)(param_1 + 0x42) = param_1;
  *(undefined4 *)(param_1 + 0x44) = 0x41;
  return param_1;
}



/* 404f0b04 FUN_404f0b04 */

/* Boundary evidence: original MIPS .pdata 404f0b04..404f0b57. Semantic name remains unreviewed. */

void FUN_404f0b04(undefined2 *param_1)

{
  if ((*(HLOCAL *)(param_1 + 0x42) != (HLOCAL)0x0) && (*(int *)(param_1 + 0x44) != 0x41)) {
    LocalFree(*(HLOCAL *)(param_1 + 0x42));
  }
  *(undefined4 *)(param_1 + 0x44) = 0x41;
  *param_1 = 0;
  *(undefined2 **)(param_1 + 0x42) = param_1;
  return;
}



/* 404f0b58 FUN_404f0b58 */

/* Boundary evidence: original MIPS .pdata 404f0b58..404f0c4b. Semantic name remains unreviewed. */

undefined4 FUN_404f0b58(wchar_t *param_1,uint param_2)

{
  wchar_t *_Dest;
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = *(uint *)(param_1 + 0x44);
  for (uVar2 = uVar1; uVar2 < param_2; uVar2 = uVar2 << 2) {
  }
  if (uVar2 != uVar1) {
    if (uVar2 < 0x42) {
      if ((*(wchar_t **)(param_1 + 0x42) != (wchar_t *)0x0) && (uVar1 != 0)) {
        wcsncpy(param_1,*(wchar_t **)(param_1 + 0x42),0x41);
      }
      FUN_404f0b04(param_1);
      *(wchar_t **)(param_1 + 0x42) = param_1;
    }
    else {
      _Dest = LocalAlloc(0x40,uVar2 << 1);
      if (_Dest == (wchar_t *)0x0) {
        uVar3 = 0x8007000e;
      }
      else {
        wcsncpy(_Dest,*(wchar_t **)(param_1 + 0x42),param_2);
        FUN_404f0b04(param_1);
        *(uint *)(param_1 + 0x44) = uVar2;
        *(wchar_t **)(param_1 + 0x42) = _Dest;
      }
    }
  }
  return uVar3;
}



/* 404f0c4c FUN_404f0c4c */

/* Boundary evidence: original MIPS .pdata 404f0c4c..404f0cdf. Semantic name remains unreviewed. */

int FUN_404f0c4c(wchar_t *param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  
  iVar2 = 1;
  if (((param_2 != (char *)0x0) && (sVar1 = strlen(param_2), sVar1 != 0)) &&
     (iVar2 = FUN_404f0b58(param_1,sVar1 + 1), -1 < iVar2)) {
    MultiByteToWideChar(0,0,param_2,-1,*(LPWSTR *)(param_1 + 0x42),*(int *)(param_1 + 0x44));
  }
  return iVar2;
}



/* 404f0ce0 FUN_404f0ce0 */

/* Boundary evidence: original MIPS .pdata 404f0ce0..404f0d93. Semantic name remains unreviewed. */

int FUN_404f0ce0(wchar_t *param_1,wchar_t *param_2,size_t param_3)

{
  uint _Count;
  int iVar1;
  
  iVar1 = 1;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != 0)) {
    if (param_3 == 0xffffffff) {
      param_3 = wcslen(param_2);
    }
    if (param_3 != 0) {
      _Count = param_3 + 1;
      iVar1 = FUN_404f0b58(param_1,_Count);
      if (-1 < iVar1) {
        if (*(uint *)(param_1 + 0x44) <= _Count) {
          _Count = *(uint *)(param_1 + 0x44);
        }
        wcsncpy(*(wchar_t **)(param_1 + 0x42),param_2,_Count);
      }
    }
  }
  return iVar1;
}



/* 404f0d94 FUN_404f0d94 */

/* Boundary evidence: original MIPS .pdata 404f0d94..404f0dd3. Semantic name remains unreviewed. */

void FUN_404f0d94(wchar_t *param_1,char *param_2)

{
  FUN_404f0b04(param_1);
  FUN_404f0c4c(param_1,param_2);
  return;
}



/* 404f0dd4 FUN_404f0dd4 */

/* Boundary evidence: original MIPS .pdata 404f0dd4..404f0e23. Semantic name remains unreviewed. */

void FUN_404f0dd4(wchar_t *param_1,wchar_t *param_2,size_t param_3)

{
  FUN_404f0b04(param_1);
  FUN_404f0ce0(param_1,param_2,param_3);
  return;
}



/* 404f0e24 FUN_404f0e24 */

/* Boundary evidence: original MIPS .pdata 404f0e24..404f0efb. Semantic name remains unreviewed. */

undefined4 FUN_404f0e24(wchar_t *param_1,wchar_t *param_2,size_t param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_2 == (wchar_t *)0x0) {
    uVar3 = 0x80070057;
  }
  else {
    sVar1 = wcslen(*(wchar_t **)(param_1 + 0x42));
    if (param_3 == 0xffffffff) {
      param_3 = wcslen(param_2);
    }
    iVar2 = FUN_404f0b58(param_1,sVar1 + param_3 + 1);
    if (iVar2 < 0) {
      uVar3 = 0x8007000e;
    }
    else {
      wcsncpy((wchar_t *)(sVar1 * 2 + *(int *)(param_1 + 0x42)),param_2,param_3);
      *(undefined2 *)((sVar1 + param_3) * 2 + *(int *)(param_1 + 0x42)) = 0;
    }
  }
  return uVar3;
}



/* 404f117c FUN_404f117c */

/* Boundary evidence: original MIPS .pdata 404f117c..404f12b7. Semantic name remains unreviewed. */

int FUN_404f117c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_404f443c != (code *)0x0) {
      iVar2 = (*DAT_404f443c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_404f122c;
    FUN_404f1610();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_404dbe9c(param_1,param_2);
  }
LAB_404f122c:
  if (((param_2 == 0) && (FUN_404f1598(), iVar1 != 0)) && (DAT_404f443c != (code *)0x0)) {
    iVar1 = (*DAT_404f443c)(param_1,0,param_3);
  }
  return iVar1;
}



/* 404f12b8 FUN_404f12b8 */

/* Boundary evidence: original MIPS .pdata 404f12b8..404f12e3. Semantic name remains unreviewed. */

void FUN_404f12b8(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 404f12e4 entry */

/* Boundary evidence: original MIPS .pdata 404f12e4..404f133b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_404f133c();
  }
  FUN_404f117c(param_1,param_2,param_3);
  return;
}



/* 404f133c FUN_404f133c */

/* Boundary evidence: original MIPS .pdata 404f133c..404f13af. Semantic name remains unreviewed. */

void FUN_404f133c(void)

{
  uint uVar1;
  
  if ((DAT_404f4224 == 0) || (DAT_404f4224 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_404f4224 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_404f4224 == 0) {
      DAT_404f4224 = 0xb064;
    }
  }
  DAT_404f4228 = ~DAT_404f4224;
  return;
}



/* 404f13b0 FUN_404f13b0 */

/* Boundary evidence: original MIPS .pdata 404f13b0..404f1403. Semantic name remains unreviewed. */

void FUN_404f13b0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_404f1430(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 404f1404 FUN_404f1404 */

/* Boundary evidence: original MIPS .pdata 404f1404..404f142f. Semantic name remains unreviewed. */

undefined4 FUN_404f1404(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_404f13b0(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 404f1430 FUN_404f1430 */

/* Boundary evidence: original MIPS .pdata 404f1430..404f1477. Semantic name remains unreviewed. */

void FUN_404f1430(uint param_1)

{
  if ((param_1 == DAT_404f4224) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 404f1478 FUN_404f1478 */

/* Boundary evidence: original MIPS .pdata 404f1478..404f1597. Semantic name remains unreviewed. */

void FUN_404f1478(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_404f442c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_404f4434;
    if (DAT_404f4434 != (undefined4 *)0x0) {
      while (DAT_404f4430 = DAT_404f4430 + -1, _Memory <= DAT_404f4430) {
        if ((code *)*DAT_404f4430 != (code *)0x0) {
          (*(code *)*DAT_404f4430)();
          _Memory = DAT_404f4434;
        }
      }
      free(_Memory);
      DAT_404f4430 = (undefined4 *)0x0;
      DAT_404f4434 = (undefined4 *)0x0;
    }
    FUN_404f15bc((undefined4 *)&DAT_404d1010,(undefined4 *)&DAT_404d1014);
  }
  FUN_404f15bc((undefined4 *)&DAT_404d1018,(undefined4 *)&DAT_404d101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_404f4438,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 404f1598 FUN_404f1598 */

/* Boundary evidence: original MIPS .pdata 404f1598..404f15bb. Semantic name remains unreviewed. */

void FUN_404f1598(void)

{
  FUN_404f1478(0,0,1);
  return;
}



/* 404f15bc FUN_404f15bc */

/* Boundary evidence: original MIPS .pdata 404f15bc..404f160f. Semantic name remains unreviewed. */

void FUN_404f15bc(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 404f1610 FUN_404f1610 */

/* Boundary evidence: original MIPS .pdata 404f1610..404f164b. Semantic name remains unreviewed. */

void FUN_404f1610(void)

{
  FUN_404f15bc((undefined4 *)&DAT_404d1008,(undefined4 *)&DAT_404d100c);
  FUN_404f15bc((undefined4 *)&DAT_404d1000,(undefined4 *)&DAT_404d1004);
  return;
}


