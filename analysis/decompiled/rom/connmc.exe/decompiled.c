/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011f94 FUN_00011f94 */

/* Boundary evidence: original MIPS .pdata 00011f94..00012027. Semantic name remains unreviewed. */

void FUN_00011f94(HINSTANCE param_1)

{
  UINT UVar1;
  
  FUN_000122a4();
  UVar1 = FUN_00015330(param_1);
  FUN_000121e4(UVar1);
  FUN_00012204(UVar1);
  return;
}



/* 00012028 FUN_00012028 */

/* Boundary evidence: original MIPS .pdata 00012028..00012067. Semantic name remains unreviewed. */

void FUN_00012028(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00012068 entry */

/* Boundary evidence: original MIPS .pdata 00012068..000120c3. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1)

{
  FUN_000122e0();
  FUN_00011f94(param_1);
  return;
}



/* 000120c4 FUN_000120c4 */

/* Boundary evidence: original MIPS .pdata 000120c4..000121e3. Semantic name remains unreviewed. */

void FUN_000120c4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00023400 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000239e8;
    if (DAT_000239e8 != (undefined4 *)0x0) {
      while (DAT_000239e4 = DAT_000239e4 + -1, _Memory <= DAT_000239e4) {
        if ((code *)*DAT_000239e4 != (code *)0x0) {
          (*(code *)*DAT_000239e4)();
          _Memory = DAT_000239e8;
        }
      }
      free(_Memory);
      DAT_000239e4 = (undefined4 *)0x0;
      DAT_000239e8 = (undefined4 *)0x0;
    }
    FUN_00012250((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  }
  FUN_00012250((undefined4 *)&DAT_00011020,(undefined4 *)&DAT_00011024);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_000239ec,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 000121e4 FUN_000121e4 */

/* Boundary evidence: original MIPS .pdata 000121e4..00012203. Semantic name remains unreviewed. */

void FUN_000121e4(UINT param_1)

{
  FUN_000120c4(param_1,0,0);
  return;
}



/* 00012204 FUN_00012204 */

/* Boundary evidence: original MIPS .pdata 00012204..0001224f. Semantic name remains unreviewed. */

void FUN_00012204(UINT param_1)

{
  DAT_00023400 = 0;
  FUN_00012250((undefined4 *)&DAT_00011020,(undefined4 *)&DAT_00011024);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00012250 FUN_00012250 */

/* Boundary evidence: original MIPS .pdata 00012250..000122a3. Semantic name remains unreviewed. */

void FUN_00012250(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000122a4 FUN_000122a4 */

/* Boundary evidence: original MIPS .pdata 000122a4..000122df. Semantic name remains unreviewed. */

void FUN_000122a4(void)

{
  FUN_00012250((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  FUN_00012250((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_0001100c);
  return;
}



/* 000122e0 FUN_000122e0 */

/* Boundary evidence: original MIPS .pdata 000122e0..00012353. Semantic name remains unreviewed. */

void FUN_000122e0(void)

{
  uint uVar1;
  
  if ((DAT_00023314 == 0) || (DAT_00023314 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00023314 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00023314 == 0) {
      DAT_00023314 = 0xb064;
    }
  }
  DAT_00023318 = ~DAT_00023314;
  return;
}



/* 00012354 FUN_00012354 */

/* Boundary evidence: original MIPS .pdata 00012354..0001245f. Semantic name remains unreviewed. */

undefined4 FUN_00012354(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_000239e8;
  puVar3 = DAT_000239e4;
  iVar4 = (int)DAT_000239e4 - (int)DAT_000239e8;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_00012398:
    param_1 = 0;
  }
  else {
    if (DAT_000239e8 != (void *)0x0) {
      uVar1 = _msize(DAT_000239e8);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_0001240c:
        if (pvVar2 == (void *)0x0) goto LAB_00012398;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_0001240c;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_000239e4 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_000239e8 = pvVar2;
  }
  return param_1;
}



/* 00012460 FUN_00012460 */

/* Boundary evidence: original MIPS .pdata 00012460..0001254b. Semantic name remains unreviewed. */

undefined4 FUN_00012460(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_000239ec == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_000239ec,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_000239ec == (LPCRITICAL_SECTION)0x0) goto LAB_00012504;
  }
  EnterCriticalSection(DAT_000239ec);
LAB_00012504:
  uVar2 = FUN_00012354(param_1);
  FUN_0001254c();
  return uVar2;
}



/* 0001254c FUN_0001254c */

/* Boundary evidence: original MIPS .pdata 0001254c..00012597. Semantic name remains unreviewed. */

void FUN_0001254c(void)

{
  if (DAT_000239ec != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_000239ec);
  }
  return;
}



/* 00012598 FUN_00012598 */

/* Boundary evidence: original MIPS .pdata 00012598..000125c7. Semantic name remains unreviewed. */

undefined4 FUN_00012598(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00012460(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 000126a8 FUN_000126a8 */

/* Boundary evidence: original MIPS .pdata 000126a8..0001270b. Semantic name remains unreviewed. */

LRESULT FUN_000126a8(HWND param_1,WPARAM param_2,uint param_3)

{
  LRESULT LVar1;
  BOOL BVar2;
  
  LVar1 = SendMessageW(param_1,0x100c,param_2,param_3 & 0xffff);
  if ((LVar1 == 0) && (BVar2 = IsWindow(param_1), BVar2 == 0)) {
    LVar1 = -1;
  }
  return LVar1;
}



/* 0001270c FUN_0001270c */

/* Boundary evidence: original MIPS .pdata 0001270c..00012923. Semantic name remains unreviewed. */

undefined4 FUN_0001270c(void)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  int *piVar3;
  
  pHVar1 = LoadLibraryW(L"commctrl.dll");
  if (pHVar1 == (HMODULE)0x0) {
LAB_00012908:
    uVar2 = 0;
  }
  else {
    DAT_00023404 = GetProcAddressW(pHVar1,L"InitCommonControls");
    piVar3 = &DAT_00023404;
    DAT_00023408 = GetProcAddressW(pHVar1,L"InitCommonControlsEx");
    DAT_0002340c = GetProcAddressW(pHVar1,L"CreateStatusWindowW");
    DAT_00023410 = GetProcAddressW(pHVar1,L"DrawStatusTextW");
    DAT_00023414 = GetProcAddressW(pHVar1,L"CommandBar_Create");
    DAT_00023418 = GetProcAddressW(pHVar1,L"CommandBar_Show");
    DAT_0002341c = GetProcAddressW(pHVar1,L"CommandBar_AddBitmap");
    DAT_00023420 = GetProcAddressW(pHVar1,L"CommandBar_InsertComboBox");
    DAT_00023424 = GetProcAddressW(pHVar1,L"CommandBar_InsertMenubar");
    DAT_00023428 = GetProcAddressW(pHVar1,L"CommandBar_GetMenu");
    DAT_0002342c = GetProcAddressW(pHVar1,L"CommandBar_AddAdornments");
    DAT_00023430 = GetProcAddressW(pHVar1,L"CommandBar_Height");
    DAT_00023434 = GetProcAddressW(pHVar1,L"IsCommandBarMessage");
    DAT_00023438 = GetProcAddressW(pHVar1,L"PropertySheetW");
    DAT_0002343c = GetProcAddressW(pHVar1,L"CreatePropertySheetPageW");
    DAT_00023440 = GetProcAddressW(pHVar1,L"DestroyPropertySheetPage");
    DAT_00023444 = GetProcAddressW(pHVar1,L"CreateUpDownControl");
    do {
      if (*piVar3 == 0) goto LAB_00012908;
      piVar3 = piVar3 + 1;
    } while ((int)piVar3 < 0x23448);
    uVar2 = 1;
  }
  return uVar2;
}



/* 00012924 FUN_00012924 */

/* Boundary evidence: original MIPS .pdata 00012924..00012ae3. Semantic name remains unreviewed. */

undefined4 FUN_00012924(void)

{
  HMENU hmenu;
  undefined4 uVar1;
  
  uVar1 = 1;
  DAT_00023454 = (HWND)(*DAT_00023414)(DAT_0002344c,DAT_00023450,1);
  if (DAT_00023454 == (HWND)0x0) {
    uVar1 = 0;
  }
  else {
    if (DAT_00023448 == 0) {
      (*DAT_00023424)(DAT_00023454,DAT_0002344c,1000,0);
      (*DAT_0002341c)(DAT_00023454,0xffffffff,0,0,0x10,0x10);
      (*DAT_0002341c)(DAT_00023454,0xffffffff,4,0,0x10,0x10);
      SendMessageW(DAT_00023454,0x444,7,0x1104c);
      SendMessageW(DAT_00023454,0x402,0x7dc,1);
      hmenu = (HMENU)(*DAT_00023428)(DAT_00023454,0);
      CheckMenuRadioItem(hmenu,0x7dc,0x7de,0x7dc,0);
    }
    else {
      (*DAT_00023424)(DAT_00023454,DAT_0002344c,0x3e9);
      (*DAT_0002341c)(DAT_00023454,0xffffffff,0,0,0x10,0x10);
      (*DAT_0002341c)(DAT_00023454,DAT_0002344c,0xbbf,1,0x10,0x10);
      SendMessageW(DAT_00023454,0x444,5,0x110d8);
    }
    (*DAT_0002342c)(DAT_00023454,0xb,0);
  }
  return uVar1;
}



/* 00012ae4 FUN_00012ae4 */

/* Boundary evidence: original MIPS .pdata 00012ae4..00012d0f. Semantic name remains unreviewed. */

undefined4 FUN_00012ae4(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_448;
  int local_444 [2];
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_42c;
  int *local_428;
  WCHAR aWStack_418 [512];
  uint local_18;
  
  local_18 = DAT_00023314;
  if (DAT_00023458 == (HWND)0x0) {
    FUN_000219a0(DAT_00023314);
    uVar4 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00023464);
    memset(local_444,0,0x28);
    local_448 = 0xf;
    local_434 = 0xffffffff;
    SendMessageW(DAT_00023458,0x1009,0,0);
    LoadStringW(DAT_0002344c,0x1774,aWStack_418,0x200);
    puVar1 = operator_new(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_00015600(puVar1,aWStack_418);
    }
    if (piVar2 == (int *)0x0) {
      uVar4 = 0;
    }
    else {
      local_438 = 3;
      local_43c = 3;
      local_428 = piVar2;
      local_42c = (**(code **)(*piVar2 + 0xc))(piVar2);
      SendMessageW(DAT_00023458,0x104d,0,(LPARAM)&local_448);
      piVar2 = FUN_0001f514();
      while (piVar2 != (int *)0x0) {
        local_444[0] = local_444[0] + 1;
        local_42c = (**(code **)(*piVar2 + 0xc))(piVar2);
        local_428 = piVar2;
        iVar3 = (**(code **)(*piVar2 + 0x44))(piVar2);
        if (iVar3 == 0) {
          local_438 = 0;
          local_43c = 0;
        }
        else {
          local_438 = 0xf00;
          local_43c = 0x100;
        }
        SendMessageW(DAT_00023458,0x104d,0,(LPARAM)&local_448);
        piVar2 = FUN_0001eac8();
      }
      local_438 = 0;
      local_43c = 0;
      piVar2 = FUN_0001a7bc();
      while (piVar2 != (int *)0x0) {
        local_444[0] = local_444[0] + 1;
        local_42c = (**(code **)(*piVar2 + 0xc))(piVar2);
        local_428 = piVar2;
        SendMessageW(DAT_00023458,0x104d,0,(LPARAM)&local_448);
        piVar2 = FUN_0001a0ec();
      }
      uVar4 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00023464);
    FUN_000219a0(local_18);
  }
  return uVar4;
}



/* 00012d10 FUN_00012d10 */

/* Boundary evidence: original MIPS .pdata 00012d10..0001321f. Semantic name remains unreviewed. */

void FUN_00012d10(HMENU param_1)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  LRESULT LVar5;
  uint uVar6;
  int iVar7;
  HMENU pHVar8;
  size_t sVar9;
  WPARAM WVar10;
  UINT uCheck;
  uint uVar11;
  int iVar12;
  uint local_1a0;
  int local_19c;
  int local_198;
  uint local_194;
  undefined4 local_190;
  WPARAM local_18c [7];
  int *local_170;
  MENUITEMINFOW local_160;
  WCHAR local_130;
  undefined1 auStack_12e [254];
  uint local_30;
  
  local_30 = DAT_00023314;
  uVar11 = 1;
  iVar12 = 1;
  bVar2 = false;
  uVar6 = (uint)(DAT_00023448 == 0);
  local_194 = 1;
  local_198 = 1;
  local_1a0 = 1;
  local_19c = 1;
  uVar4 = SendMessageW(DAT_00023458,0x1032,0,0);
  bVar1 = 1 < uVar4;
  memset(local_18c,0,0x28);
  local_190 = 4;
  if (uVar4 == 0) {
    uVar11 = 0;
    local_194 = 0;
    iVar12 = 0;
    local_198 = 0;
    uVar6 = 0;
    local_19c = 0;
    local_1a0 = 0;
  }
  else {
    WVar10 = 0xffffffff;
    while ((local_18c[0] = FUN_000126a8(DAT_00023458,WVar10,2), local_18c[0] != 0xffffffff &&
           (LVar5 = SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_190), piVar3 = local_170,
           LVar5 != 0))) {
      WVar10 = local_18c[0];
      if (local_170 != (int *)0x0) {
        if (uVar11 != 0) {
          uVar11 = (**(code **)(*local_170 + 0x10))(local_170,bVar1,0);
        }
        if (iVar12 != 0) {
          iVar12 = (**(code **)(*piVar3 + 0x3c))(piVar3,bVar1,0);
        }
        if (uVar6 != 0) {
          uVar6 = (**(code **)(*piVar3 + 0x34))(piVar3,bVar1,0);
        }
        if (local_194 != 0) {
          local_194 = (**(code **)(*piVar3 + 0x1c))(piVar3,bVar1,0);
        }
        if (local_198 != 0) {
          local_198 = (**(code **)(*piVar3 + 0x24))(piVar3,bVar1,0);
        }
        if (local_1a0 != 0) {
          local_1a0 = (**(code **)(*piVar3 + 0x4c))(piVar3,bVar1,0);
        }
        WVar10 = local_18c[0];
        if (local_19c != 0) {
          local_19c = (**(code **)(*piVar3 + 0x2c))(piVar3,bVar1,0);
          WVar10 = local_18c[0];
        }
      }
    }
  }
  local_18c[0] = FUN_000126a8(DAT_00023458,0xffffffff,3);
  SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_190);
  if ((local_18c[0] != 0xffffffff) && (local_170 != (int *)0x0)) {
    local_130 = L'\0';
    memset(auStack_12e,0,0xfe);
    local_160.cbSize = 0;
    memset(&local_160.fMask,0,0x28);
    iVar7 = (**(code **)(*local_170 + 0x14))(local_170,DAT_0002344c,&local_130,0);
    if (iVar7 != 0) {
      if (((uVar4 == 1) &&
          (iVar7 = (**(code **)(*local_170 + 4))(local_170,L"NewConnInfo"), iVar7 != 0)) &&
         (pHVar8 = (HMENU)(*DAT_00023428)(DAT_00023454,0), pHVar8 == param_1)) {
        LoadStringW(DAT_0002344c,0x1839,&local_130,0x80);
        uVar11 = 0;
      }
      local_160.dwTypeData = &local_130;
      local_160.cbSize = 0x2c;
      local_160.fMask = 0x10;
      local_160.fType = 0;
      sVar9 = wcslen(&local_130);
      local_160.cch = sVar9 + 1;
      SetMenuItemInfoW(param_1,2000,0,&local_160);
    }
    if (uVar4 == 1) {
      iVar7 = (**(code **)(*local_170 + 0x44))(local_170);
      bVar2 = true;
      if (iVar7 != 0) goto LAB_00013090;
    }
    bVar2 = false;
  }
LAB_00013090:
  EnableMenuItem(param_1,2000,(uint)(uVar11 == 0));
  EnableMenuItem(param_1,0x7e4,(uint)(iVar12 == 0));
  uCheck = 8;
  if (!bVar2) {
    uCheck = 0;
  }
  CheckMenuItem(param_1,0x7e4,uCheck);
  EnableMenuItem(param_1,0x7d2,(uint)(uVar6 == 0));
  EnableMenuItem(param_1,0x7d3,(uint)(local_194 == 0));
  EnableMenuItem(param_1,0x7d4,(uint)(local_198 == 0));
  EnableMenuItem(param_1,0x7d5,(uint)(local_1a0 == 0));
  EnableMenuItem(param_1,0x7d9,(uint)(local_19c == 0));
  if (DAT_00023448 != 0) {
    SendMessageW(DAT_00023454,0x401,2000,uVar11 & 0xffff);
  }
  SendMessageW(DAT_00023454,0x401,0x7d3,local_194 & 0xffff);
  SendMessageW(DAT_00023454,0x401,0x7d5,local_1a0 & 0xffff);
  FUN_000219a0(local_30);
  return;
}



/* 00013220 FUN_00013220 */

/* Boundary evidence: original MIPS .pdata 00013220..0001330f. Semantic name remains unreviewed. */

void FUN_00013220(UINT param_1)

{
  HMENU hmenu;
  
  hmenu = (HMENU)(*DAT_00023428)(DAT_00023454,0);
  if (hmenu != (HMENU)0x0) {
    CheckMenuRadioItem(hmenu,0x7dc,0x7de,param_1,0);
    SendMessageW(DAT_00023454,0x402,0x7dc,(uint)(param_1 == 0x7dc));
    SendMessageW(DAT_00023454,0x402,0x7dd,(uint)(param_1 == 0x7dd));
    SendMessageW(DAT_00023454,0x402,0x7de,(uint)(param_1 == 0x7de));
  }
  return;
}



/* 00013310 FUN_00013310 */

/* Boundary evidence: original MIPS .pdata 00013310..000133b7. Semantic name remains unreviewed. */

void FUN_00013310(void)

{
  HMENU hMenu;
  HMENU pHVar1;
  DWORD DVar2;
  
  hMenu = LoadMenuW(DAT_0002344c,(LPCWSTR)0x3ea);
  if (hMenu != (HMENU)0x0) {
    pHVar1 = GetSubMenu(hMenu,0);
    if (pHVar1 != (HMENU)0x0) {
      FUN_00012d10(pHVar1);
      DVar2 = GetMessagePos();
      TrackPopupMenuEx(pHVar1,0,(int)(short)DVar2,(int)DVar2 >> 0x10,DAT_00023450,(LPTPMPARAMS)0x0);
    }
    DestroyMenu(hMenu);
  }
  return;
}



/* 000133b8 FUN_000133b8 */

/* Boundary evidence: original MIPS .pdata 000133b8..0001346b. Semantic name remains unreviewed. */

int FUN_000133b8(UINT param_1,UINT param_2,UINT param_3)

{
  int iVar1;
  WCHAR aWStack_418 [256];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00023314;
  LoadStringW(DAT_0002344c,param_1,aWStack_218,0x100);
  if ((param_2 == 0) && (param_2 = 0x1771, DAT_00023448 == 0)) {
    param_2 = 6000;
  }
  LoadStringW(DAT_0002344c,param_2,aWStack_418,0x100);
  iVar1 = MessageBoxW(DAT_00023450,aWStack_218,aWStack_418,param_3);
  FUN_000219a0(local_18);
  return iVar1;
}



/* 0001346c FUN_0001346c */

/* Boundary evidence: original MIPS .pdata 0001346c..000135c3. Semantic name remains unreviewed. */

undefined4 FUN_0001346c(void)

{
  DWORD DVar1;
  int iVar2;
  undefined4 local_240;
  undefined4 local_23c;
  HANDLE local_238;
  undefined4 local_234;
  uint local_230;
  undefined1 auStack_22c [528];
  uint local_1c;
  
  local_1c = DAT_00023314;
  local_230 = 0;
  memset(auStack_22c,0,0x210);
  local_240 = 0;
  local_23c = 0;
  WaitForAPIReady(0x55,0);
  local_238 = DAT_00023478;
  local_234 = DAT_00023480;
  DVar1 = WaitForMultipleObjects(2,&local_238,0,0xffffffff);
  while (DVar1 == 0) {
    iVar2 = ReadMsgQueue(DAT_00023478,&local_230,0x214,&local_240,1,&local_23c);
    while (iVar2 != 0) {
      if (((local_230 & 0x10) != 0) || ((local_230 & 0x20) != 0)) {
        PostMessageW(DAT_00023450,0x219,0,0);
      }
      iVar2 = ReadMsgQueue(DAT_00023478,&local_230,0x214,&local_240,1,&local_23c);
    }
    DVar1 = WaitForMultipleObjects(2,&local_238,0,0xffffffff);
  }
  FUN_000219a0(local_1c);
  return 0;
}



/* 000135c4 FUN_000135c4 */

/* Boundary evidence: original MIPS .pdata 000135c4..0001368f. Semantic name remains unreviewed. */

void FUN_000135c4(void)

{
  if (DAT_0002331c != -1) {
    CloseHandle((HANDLE)DAT_0002331c);
    DAT_0002331c = -1;
  }
  if (DAT_00023478 != 0) {
    CloseMsgQueue();
    DAT_00023478 = 0;
  }
  if (DAT_0002347c != (HANDLE)0x0) {
    EventModify(DAT_00023480,3);
    WaitForSingleObject(DAT_00023480,0xffffffff);
    CloseHandle(DAT_00023480);
    DAT_00023480 = (HANDLE)0x0;
    CloseHandle(DAT_0002347c);
    DAT_0002347c = (HANDLE)0x0;
  }
  return;
}



/* 00013690 FUN_00013690 */

void FUN_00013690(short *param_1)

{
  short sVar1;
  short *psVar2;
  
  if ((param_1 != (short *)0x0) && (sVar1 = *param_1, sVar1 != 0)) {
    psVar2 = param_1 + -1;
    do {
      if (sVar1 != 0x20) {
        psVar2 = param_1;
      }
      param_1 = param_1 + 1;
      sVar1 = *param_1;
    } while (sVar1 != 0);
    if (*psVar2 != 0) {
      psVar2[1] = 0;
    }
  }
  return;
}



/* 000136e8 FUN_000136e8 */

void FUN_000136e8(short *param_1,int param_2)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  
  if (((param_1 != (short *)0x0) && (sVar2 = *param_1, sVar2 != 0)) &&
     (psVar3 = param_1, iVar1 = param_2, param_2 != 0)) {
    do {
      if ((sVar2 != 0x20) || (iVar1 == 0)) break;
      psVar3 = psVar3 + 1;
      sVar2 = *psVar3;
      iVar1 = iVar1 + -1;
    } while (sVar2 != 0);
    if (psVar3 != param_1) {
      for (iVar1 = param_2 - ((int)psVar3 - (int)param_1 >> 1); (*psVar3 != 0 && (iVar1 != 0));
          iVar1 = iVar1 + -1) {
        *param_1 = *psVar3;
        param_1 = param_1 + 1;
        psVar3 = psVar3 + 1;
      }
      *param_1 = 0;
    }
  }
  return;
}



/* 00013784 FUN_00013784 */

/* Boundary evidence: original MIPS .pdata 00013784..000137d3. Semantic name remains unreviewed. */

void FUN_00013784(wchar_t *param_1)

{
  size_t sVar1;
  
  if ((param_1 != (wchar_t *)0x0) && (FUN_00013690(param_1), *param_1 != L'\0')) {
    sVar1 = wcslen(param_1);
    FUN_000136e8(param_1,sVar1);
  }
  return;
}



/* 000137d4 FUN_000137d4 */

/* Boundary evidence: original MIPS .pdata 000137d4..0001384b. Semantic name remains unreviewed. */

undefined4 FUN_000137d4(wchar_t *param_1)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == (wchar_t *)0x0) {
LAB_00013830:
    uVar2 = 0;
  }
  else {
    uVar3 = 0;
    do {
      pwVar1 = wcschr(param_1,*(wchar_t *)((int)&DAT_0001113c + uVar3));
      if (pwVar1 != (wchar_t *)0x0) goto LAB_00013830;
      uVar3 = uVar3 + 2;
    } while (uVar3 < 0x12);
    uVar2 = 1;
  }
  return uVar2;
}



/* 0001384c FUN_0001384c */

/* Boundary evidence: original MIPS .pdata 0001384c..0001390b. Semantic name remains unreviewed. */

void FUN_0001384c(wchar_t *param_1,undefined4 *param_2)

{
  int iVar1;
  LRESULT LVar2;
  undefined4 uVar3;
  undefined4 local_28;
  wchar_t *local_24;
  
  if ((param_1 != (wchar_t *)0x0) && (param_2 != (undefined4 *)0x0)) {
    if (*param_1 == L'\0') {
      *param_2 = 0x1909;
    }
    else {
      FUN_00013784(param_1);
      if (*param_1 == L'\0') {
        uVar3 = 0x1911;
      }
      else {
        iVar1 = FUN_000137d4(param_1);
        if (iVar1 == 0) {
          uVar3 = 0x190b;
        }
        else {
          local_28 = 2;
          local_24 = param_1;
          LVar2 = SendMessageW(DAT_00023458,0x1053,0xffffffff,(LPARAM)&local_28);
          if (LVar2 == -1) {
            return;
          }
          uVar3 = 0x1912;
        }
      }
      *param_2 = uVar3;
    }
  }
  return;
}



/* 0001390c FUN_0001390c */

/* Boundary evidence: original MIPS .pdata 0001390c..00013d5f. Semantic name remains unreviewed. */

undefined4 FUN_0001390c(int param_1)

{
  SHORT SVar1;
  int iVar2;
  undefined2 extraout_var;
  HWND hWnd;
  short extraout_var_00;
  short extraout_var_01;
  HMENU pHVar3;
  undefined4 *puVar4;
  WPARAM wParam;
  uint uVar5;
  int *piVar6;
  UINT local_48 [2];
  undefined4 local_40;
  int local_3c [2];
  undefined4 local_34;
  undefined4 local_30;
  int *local_20;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar5 = *(uint *)(param_1 + 8);
  if (uVar5 < 0xffffff9a) {
    if (uVar5 == 0xffffff99) {
      puVar4 = *(undefined4 **)(param_1 + 0x28);
      if (puVar4 != (undefined4 *)0x0) {
        (**(code **)*puVar4)(puVar4,1);
        return 1;
      }
      return 1;
    }
    if (uVar5 == 0xffffff4f) {
      piVar6 = *(int **)(param_1 + 0x2c);
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 0x48))
                  (piVar6,*(undefined4 *)(param_1 + 0x14),DAT_0002344c,
                   *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),0);
        return 1;
      }
      return 1;
    }
    if (uVar5 == 0xffffff50) {
      DAT_00023490 = 0;
      piVar6 = *(int **)(param_1 + 0x2c);
      if ((piVar6 != (int *)0x0) && (*(int *)(param_1 + 0x20) != 0)) {
        local_48[0] = 0;
        iVar2 = (**(code **)(*piVar6 + 0x28))(piVar6,*(int *)(param_1 + 0x20),local_48);
        if (iVar2 != 0) {
          local_30 = 3;
          local_34 = 3;
          SendMessageW(DAT_00023458,0x102b,*(WPARAM *)(param_1 + 0x10),(LPARAM)&local_40);
          SetFocus(DAT_00023458);
          return 1;
        }
        FUN_000133b8(local_48[0],0,0x30);
        PostMessageW(DAT_00023458,0x1076,*(WPARAM *)(param_1 + 0x10),0);
      }
      return 0;
    }
    if (uVar5 == 0xffffff51) {
      piVar6 = *(int **)(param_1 + 0x2c);
      if (piVar6 == (int *)0x0) {
        return 1;
      }
      DAT_00023490 = 1;
      SendMessageW(DAT_00023458,0x1013,*(WPARAM *)(param_1 + 0x10),0);
      local_48[0] = 0;
      iVar2 = (**(code **)(*piVar6 + 0x24))(piVar6,0,local_48);
      if (iVar2 != 0) {
        hWnd = (HWND)SendMessageW(DAT_00023458,0x1018,0,0);
        if (hWnd == (HWND)0x0) {
          return 0;
        }
        SendMessageW(hWnd,0xc5,0x14,0);
        return 0;
      }
      FUN_000133b8(local_48[0],0,0x30);
      return 1;
    }
    if (uVar5 != 0xffffff65) {
      if (uVar5 != 0xffffff94) {
        return 0;
      }
      return 1;
    }
    if (*(short *)(param_1 + 0xc) != 0xd) {
      if (*(short *)(param_1 + 0xc) != 0x11) {
        return 0;
      }
      SVar1 = GetAsyncKeyState(0x12);
      if (CONCAT22(extraout_var,SVar1) == 0) {
        return 0;
      }
      goto LAB_00013a80;
    }
    memset(local_3c,0,0x28);
    local_40 = 4;
    local_3c[0] = FUN_000126a8(DAT_00023458,0xffffffff,3);
    SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_40);
    if (local_3c[0] == -1) {
      return 1;
    }
    if (local_20 != (int *)0x0) {
      iVar2 = (**(code **)(*local_20 + 4))(local_20,L"LanConnInfo");
      wParam = 0x7d5;
      if (iVar2 != 0) goto LAB_00013a48;
    }
  }
  else {
    if (uVar5 == 0xffffff9b) {
      pHVar3 = (HMENU)(*DAT_00023428)(DAT_00023454,0);
      FUN_00012d10(pHVar3);
      return 1;
    }
    if (uVar5 == 0xfffffffb) {
LAB_00013a80:
      FUN_00013310();
      return 1;
    }
    if (uVar5 != 0xfffffffd) {
      if (uVar5 != 0xfffffffe) {
        return 0;
      }
      GetKeyState(0x12);
      if (-1 < extraout_var_00) {
        return 1;
      }
      goto LAB_00013a80;
    }
    GetKeyState(0x12);
    if (extraout_var_01 < 0) goto LAB_00013a80;
    memset(local_3c,0,0x28);
    local_40 = 4;
    local_3c[0] = FUN_000126a8(DAT_00023458,0xffffffff,3);
    SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_40);
    if (local_3c[0] == -1) {
      return 1;
    }
    if ((local_20 != (int *)0x0) &&
       (iVar2 = (**(code **)(*local_20 + 4))(local_20,L"LanConnInfo"), iVar2 != 0)) {
      wParam = 0x7d5;
      goto LAB_00013a48;
    }
  }
  wParam = 2000;
LAB_00013a48:
  SendMessageW(DAT_00023450,0x111,wParam,0);
  return 1;
}



/* 00013d60 FUN_00013d60 */

/* Boundary evidence: original MIPS .pdata 00013d60..000145c7. Semantic name remains unreviewed. */

undefined4 FUN_00013d60(undefined4 param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  LRESULT LVar4;
  int iVar5;
  uint uVar6;
  UINT UVar7;
  UINT UVar8;
  UINT UVar9;
  WPARAM wParam;
  undefined1 *lParam;
  UINT local_80 [2];
  undefined4 local_78;
  WPARAM local_74 [7];
  int *local_58;
  undefined1 auStack_48 [12];
  undefined4 local_3c;
  undefined4 local_38;
  
  local_78 = 0;
  memset(local_74,0,0x28);
  switch(param_1) {
  case 2000:
    local_78 = 4;
    for (local_74[0] = FUN_000126a8(DAT_00023458,0xffffffff,2); local_74[0] != 0xffffffff;
        local_74[0] = FUN_000126a8(DAT_00023458,local_74[0],2)) {
      LVar4 = SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_78);
      if ((LVar4 != 0) && (local_58 != (int *)0x0)) {
        (**(code **)(*local_58 + 0x18))(local_58,DAT_0002344c,DAT_00023450,0);
      }
    }
    break;
  default:
    return 0;
  case 0x7d2:
    if (DAT_00023448 != 0) {
      return 1;
    }
    local_78 = 4;
    for (local_74[0] = FUN_000126a8(DAT_00023458,0xffffffff,2); local_74[0] != 0xffffffff;
        local_74[0] = FUN_000126a8(DAT_00023458,local_74[0],2)) {
      LVar4 = SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_78);
      piVar2 = local_58;
      if ((LVar4 != 0) && (local_58 != (int *)0x0)) {
        local_80[0] = 0;
        iVar5 = (**(code **)(*local_58 + 0x34))(local_58,1,local_80);
        if ((iVar5 == 0) ||
           (iVar5 = (**(code **)(*piVar2 + 0x38))(piVar2,DAT_0002344c,local_80), iVar5 == 0)) {
          FUN_000133b8(local_80[0],0,0x30);
        }
      }
    }
    return 1;
  case 0x7d3:
    LVar4 = SendMessageW(DAT_00023458,0x1032,0,0);
    local_78 = 4;
    local_74[0] = FUN_000126a8(DAT_00023458,0xffffffff,2);
    SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_78);
    if (LVar4 != 1) {
      UVar8 = 0x1777;
LAB_00014008:
      iVar5 = FUN_000133b8(UVar8,0x1775,0x134);
      if (iVar5 != 6) {
        return 1;
      }
      bVar1 = true;
      local_78 = 4;
      local_74[0] = FUN_000126a8(DAT_00023458,0xffffffff,2);
      if (local_74[0] != 0xffffffff) {
        do {
          LVar4 = SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_78);
          if ((LVar4 != 0) && (local_58 != (int *)0x0)) {
            iVar5 = (**(code **)(*local_58 + 0x20))(local_58,0);
            if (iVar5 == 0) {
              bVar1 = false;
            }
            else {
              SendMessageW(DAT_00023458,0x1008,local_74[0],0);
            }
          }
          local_74[0] = FUN_000126a8(DAT_00023458,0xffffffff,2);
        } while (local_74[0] != 0xffffffff);
        if (!bVar1) {
          FUN_000133b8(0x190c,0,0x30);
        }
      }
      SetFocus(DAT_00023458);
      return 1;
    }
    local_80[0] = 0;
    iVar5 = (**(code **)(*local_58 + 0x1c))(local_58,0,local_80);
    if (iVar5 != 0) {
      UVar8 = 0x1776;
      goto LAB_00014008;
    }
    UVar8 = 0;
    goto LAB_00013ff0;
  case 0x7d4:
    LVar4 = SendMessageW(DAT_00023458,0x1032,0,0);
    if (LVar4 == 1) {
      local_74[0] = FUN_000126a8(DAT_00023458,0xffffffff,2);
      SetFocus(DAT_00023458);
      lParam = (undefined1 *)0x0;
      UVar8 = 0x1076;
      wParam = local_74[0];
      goto LAB_000144a4;
    }
    goto LAB_000141d8;
  case 0x7d5:
    LVar4 = SendMessageW(DAT_00023458,0x1032,0,0);
    if (LVar4 == 1) {
      local_78 = 4;
      local_74[0] = FUN_000126a8(DAT_00023458,0xffffffff,2);
      SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_78);
      if (local_58 == (int *)0x0) {
        return 1;
      }
      DAT_00023488 = 1;
      iVar5 = (**(code **)(*local_58 + 0x54))(local_58,DAT_0002344c,DAT_00023450,local_80);
      if (iVar5 == 0) {
        FUN_000133b8(local_80[0],0x1900,0x30);
      }
      DAT_00023488 = 0;
      if (DAT_0002348c == 0) {
        DAT_00023488 = 0;
        return 1;
      }
      DAT_0002348c = 0;
      break;
    }
LAB_000141d8:
    UVar9 = 0x30;
    UVar8 = 0x1900;
    UVar7 = 0x1902;
    goto LAB_00013e10;
  case 0x7d6:
    DestroyWindow(DAT_00023450);
    return 1;
  case 0x7d9:
    if (DAT_00023448 != 0) {
      return 1;
    }
    bVar1 = true;
    local_78 = 4;
    local_74[0] = FUN_000126a8(DAT_00023458,0xffffffff,2);
    if (local_74[0] != 0xffffffff) {
      do {
        LVar4 = SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_78);
        if (((LVar4 != 0) && (local_58 != (int *)0x0)) &&
           (iVar5 = (**(code **)(*local_58 + 0x30))(local_58,DAT_0002344c,0), iVar5 == 0)) {
          bVar1 = false;
        }
        local_74[0] = FUN_000126a8(DAT_00023458,local_74[0],2);
      } while (local_74[0] != 0xffffffff);
      if (!bVar1) {
        FUN_000133b8(0x190d,0,0x30);
      }
    }
    break;
  case 0x7db:
    lParam = auStack_48;
    local_38 = 2;
    UVar8 = 0x102b;
    local_3c = 2;
    wParam = 0xffffffff;
LAB_000144a4:
    SendMessageW(DAT_00023458,UVar8,wParam,(LPARAM)lParam);
    return 1;
  case 0x7dc:
    if (DAT_00023448 != 0) {
      return 1;
    }
    FUN_00013220(0x7dc);
    uVar6 = GetWindowLongW(DAT_00023458,-0x10);
    uVar6 = uVar6 & 0xfffffffc;
    goto LAB_00014508;
  case 0x7dd:
    if (DAT_00023448 != 0) {
      return 1;
    }
    FUN_00013220(0x7dd);
    uVar6 = GetWindowLongW(DAT_00023458,-0x10);
    uVar6 = uVar6 & 0xfffffffe | 2;
    goto LAB_00014508;
  case 0x7de:
    if (DAT_00023448 != 0) {
      return 1;
    }
    FUN_00013220(0x7de);
    uVar6 = GetWindowLongW(DAT_00023458,-0x10);
    uVar6 = uVar6 & 0xfffffffd | 1;
LAB_00014508:
    SetWindowLongW(DAT_00023458,-0x10,uVar6);
    return 1;
  case 0x7df:
    break;
  case 0x7e0:
    local_78 = 4;
    local_74[0] = 0;
    iVar5 = SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_78);
    piVar2 = local_58;
    while (iVar5 != 0) {
      local_58 = piVar2;
      if (piVar2 != (int *)0x0) {
        iVar5 = (**(code **)(*piVar2 + 4))(piVar2,L"NewConnInfo");
        if (iVar5 != 0) {
          (**(code **)(*piVar2 + 0x18))(piVar2,DAT_0002344c,DAT_00023450,0);
          break;
        }
        local_74[0] = local_74[0] + 1;
      }
      iVar5 = SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_78);
      piVar2 = local_58;
    }
    break;
  case 0x7e2:
    if (DAT_00023448 != 0) {
      return 1;
    }
    UVar9 = 0;
    UVar8 = 0x1772;
    UVar7 = 0x1773;
    goto LAB_00013e10;
  case 0x7e3:
    puVar3 = operator_new(0x20);
    if (puVar3 == (undefined4 *)0x0) {
      DAT_00023484 = (undefined4 *)0x0;
    }
    else {
      DAT_00023484 = FUN_0001c0e8(puVar3,DAT_0002344c,DAT_00023450);
    }
    if (DAT_00023484 == (undefined4 *)0x0) {
      return 1;
    }
    FUN_0001c21c((int)DAT_00023484);
    FUN_0001b7a4((int)DAT_00023484);
    puVar3 = DAT_00023484;
    if (DAT_00023484 != (undefined4 *)0x0) {
      FUN_0001adcc((int)DAT_00023484);
      operator_delete(puVar3);
    }
    DAT_00023484 = (undefined4 *)0x0;
    break;
  case 0x7e4:
    LVar4 = SendMessageW(DAT_00023458,0x1032,0,0);
    if (LVar4 != 1) goto LAB_000141d8;
    local_78 = 4;
    local_74[0] = FUN_000126a8(DAT_00023458,0xffffffff,2);
    SendMessageW(DAT_00023458,0x104b,0,(LPARAM)&local_78);
    if (local_58 == (int *)0x0) {
      return 1;
    }
    iVar5 = (**(code **)(*local_58 + 0x44))(local_58);
    iVar5 = (**(code **)(*local_58 + 0x40))(local_58,iVar5 == 0,local_80);
    if (iVar5 != 0) break;
    UVar8 = 0x1900;
LAB_00013ff0:
    UVar9 = 0x30;
    UVar7 = local_80[0];
LAB_00013e10:
    FUN_000133b8(UVar7,UVar8,UVar9);
    return 1;
  }
  FUN_00012ae4();
  return 1;
}



/* 000145c8 FUN_000145c8 */

/* Boundary evidence: original MIPS .pdata 000145c8..00014d7b. Semantic name remains unreviewed. */

undefined4 FUN_000145c8(void)

{
  int iVar1;
  int iVar2;
  HICON pHVar3;
  undefined4 uVar4;
  WPARAM wParam;
  tagRECT local_260;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  WCHAR *local_244;
  WPARAM local_23c;
  WCHAR aWStack_230 [256];
  uint local_30;
  
  local_30 = DAT_00023314;
  local_260.left = 0;
  memset(&local_260.top,0,0xc);
  GetClientRect(DAT_00023450,&local_260);
  iVar1 = (*DAT_00023430)(DAT_00023454);
  local_260.top = iVar1 + local_260.top;
  DAT_00023458 = CreateWindowExW(0,L"SysListView32",L"",0x50200348,local_260.left,local_260.top,
                                 local_260.right - local_260.left,local_260.bottom - local_260.top,
                                 DAT_00023450,(HMENU)0x0,DAT_0002344c,(LPVOID)0x0);
  if (DAT_00023458 != (HWND)0x0) {
    iVar1 = GetSystemMetrics(0xc);
    iVar2 = GetSystemMetrics(0xb);
    DAT_0002345c = ImageList_Create(iVar2,iVar1,1,4,1);
    iVar1 = GetSystemMetrics(0x32);
    iVar2 = GetSystemMetrics(0x31);
    DAT_00023460 = ImageList_Create(iVar2,iVar1,1,4,1);
    if ((DAT_0002345c != (HIMAGELIST)0x0) && (DAT_00023460 != (HIMAGELIST)0x0)) {
      pHVar3 = LoadIconW(DAT_0002344c,(LPCWSTR)0xbb9);
      if ((pHVar3 != (HICON)0x0) &&
         ((iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3), iVar1 != -1 &&
          (DAT_00023320 = iVar1, pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbb9,1,0x10,0x10,0),
          pHVar3 != (HICON)0x0)))) {
        ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
        DestroyIcon(pHVar3);
      }
      pHVar3 = LoadIconW(DAT_0002344c,(LPCWSTR)0xbba);
      if (((pHVar3 != (HICON)0x0) &&
          (iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3), iVar1 != -1)) &&
         (DAT_00023324 = iVar1, pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbba,1,0x10,0x10,0),
         pHVar3 != (HICON)0x0)) {
        ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
        DestroyIcon(pHVar3);
      }
      pHVar3 = LoadIconW(DAT_0002344c,(LPCWSTR)0xbbb);
      if (((pHVar3 != (HICON)0x0) &&
          (iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3), iVar1 != -1)) &&
         (DAT_00023328 = iVar1, pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbbb,1,0x10,0x10,0),
         pHVar3 != (HICON)0x0)) {
        ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
        DestroyIcon(pHVar3);
      }
      pHVar3 = LoadIconW(DAT_0002344c,(LPCWSTR)0xbbc);
      if (((pHVar3 != (HICON)0x0) &&
          (iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3), iVar1 != -1)) &&
         (DAT_0002332c = iVar1, pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbbc,1,0x10,0x10,0),
         pHVar3 != (HICON)0x0)) {
        ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
        DestroyIcon(pHVar3);
      }
      pHVar3 = LoadIconW(DAT_0002344c,(LPCWSTR)0xbbc);
      if (((pHVar3 != (HICON)0x0) &&
          (iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3), iVar1 != -1)) &&
         (DAT_00023360 = iVar1, pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbbc,1,0x10,0x10,0),
         pHVar3 != (HICON)0x0)) {
        ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
        DestroyIcon(pHVar3);
      }
      pHVar3 = LoadIconW(DAT_0002344c,(LPCWSTR)0xbbd);
      if (((pHVar3 != (HICON)0x0) &&
          (iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3), iVar1 != -1)) &&
         (DAT_00023350 = iVar1, pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbbd,1,0x10,0x10,0),
         pHVar3 != (HICON)0x0)) {
        ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
        DestroyIcon(pHVar3);
      }
      pHVar3 = LoadIconW(DAT_0002344c,(LPCWSTR)0xbbe);
      if (((pHVar3 != (HICON)0x0) &&
          (iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3), iVar1 != -1)) &&
         (DAT_00023354 = iVar1, pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbbe,1,0x10,0x10,0),
         pHVar3 != (HICON)0x0)) {
        ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
        DestroyIcon(pHVar3);
      }
      pHVar3 = LoadIconW(DAT_0002344c,(LPCWSTR)0xbc0);
      if (((pHVar3 != (HICON)0x0) &&
          (iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3), iVar1 != -1)) &&
         (DAT_00023358 = iVar1, pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbc0,1,0x10,0x10,0),
         pHVar3 != (HICON)0x0)) {
        ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
        DestroyIcon(pHVar3);
      }
      pHVar3 = LoadIconW(DAT_0002344c,(LPCWSTR)0xbc1);
      if (((pHVar3 != (HICON)0x0) &&
          (iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3), iVar1 != -1)) &&
         (DAT_0002335c = iVar1, pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbc1,1,0x10,0x10,0),
         pHVar3 != (HICON)0x0)) {
        ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
        DestroyIcon(pHVar3);
      }
      pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbc6,1,0x20,0x20,0);
      if (pHVar3 != (HICON)0x0) {
        iVar1 = ImageList_ReplaceIcon(DAT_0002345c,-1,pHVar3);
        DestroyIcon(pHVar3);
        if (iVar1 != -1) {
          pHVar3 = LoadImageW(DAT_0002344c,(LPCWSTR)0xbc6,1,0x10,0x10,0);
          if (pHVar3 != (HICON)0x0) {
            ImageList_ReplaceIcon(DAT_00023460,-1,pHVar3);
            DestroyIcon(pHVar3);
          }
          ImageList_SetOverlayImage(DAT_0002345c,iVar1,1);
          ImageList_SetOverlayImage(DAT_00023460,iVar1,1);
        }
      }
      SendMessageW(DAT_00023458,0x1003,0,(LPARAM)DAT_0002345c);
      SendMessageW(DAT_00023458,0x1003,1,(LPARAM)DAT_00023460);
      memset(&local_24c,0,0x1c);
      local_244 = aWStack_230;
      local_250 = 0xf;
      local_24c = 0;
      wParam = 0;
      do {
        if (wParam == 0) {
          local_248 = 0x96;
        }
        else if (wParam == 2) {
          local_248 = 0xe1;
        }
        else {
          local_248 = 100;
        }
        local_23c = wParam;
        LoadStringW(DAT_0002344c,wParam + 0x177a,aWStack_230,0x100);
        SendMessageW(DAT_00023458,0x1061,wParam,(LPARAM)&local_250);
        wParam = wParam + 1;
      } while ((int)wParam < 4);
      uVar4 = FUN_00012ae4();
      FUN_000219a0(local_30);
      return uVar4;
    }
  }
  FUN_000219a0(local_30);
  return 0;
}



/* 00014d7c FUN_00014d7c */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 00014d7c..00014ef7. Semantic name remains unreviewed. */

undefined4 FUN_00014d7c(void)

{
  int iVar1;
  BOOL BVar2;
  int local_30 [8];
  
  DAT_0002331c = CreateFileW(L"UIO1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff
                            );
  if (DAT_0002331c != (HANDLE)0xffffffff) {
    memset(local_30 + 3,0,0x10);
    local_30[2] = 0x14;
    local_30[3] = 0;
    local_30[4] = 0x19;
    local_30[5] = 0x214;
    local_30[6] = 1;
    iVar1 = CreateMsgQueue(0,local_30 + 2);
    DAT_00023478 = iVar1;
    if (iVar1 != 0) {
      memset(local_30 + 1,0,4);
      local_30[1] = 0x30;
      local_30[0] = iVar1;
      BVar2 = DeviceIoControl(DAT_0002331c,0x12081c,local_30,8,(LPVOID)0x0,0,(LPDWORD)0x0,
                              (LPOVERLAPPED)0x0);
      if (((BVar2 != 0) &&
          (DAT_00023480 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0),
          DAT_00023480 != (HANDLE)0x0)) &&
         (DAT_0002347c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001346c,(LPVOID)0x0,0,
                                      (LPDWORD)0x0), DAT_0002347c != (HANDLE)0x0)) {
        return 1;
      }
    }
    FUN_000135c4();
  }
  return 0;
}



/* 00014ef8 FUN_00014ef8 */

/* Boundary evidence: original MIPS .pdata 00014ef8..00015203. Semantic name remains unreviewed. */

LRESULT FUN_00014ef8(HWND param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  LRESULT LVar1;
  int iVar2;
  tagRECT local_228;
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00023314;
  if (param_2 < 0x54) {
    if (param_2 == 0x53) {
      wcscpy(awStack_218,L"file:rnetw.htm#Main_Contents");
      CreateProcessW(L"peghelp",awStack_218,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,
                     0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
      goto LAB_000151b8;
    }
    if (param_2 == 2) {
      DestroyWindow(DAT_00023458);
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00023464);
      ImageList_Destroy(DAT_0002345c);
      ImageList_Destroy(DAT_00023460);
      PostQuitMessage(0);
      goto LAB_000151b8;
    }
    if (param_2 == 5) {
      local_228.left = 0;
      memset(&local_228.top,0,0xc);
      GetClientRect(DAT_00023450,&local_228);
      iVar2 = (*DAT_00023430)(DAT_00023454);
      local_228.top = iVar2 + local_228.top;
      MoveWindow(DAT_00023458,local_228.left,local_228.top,local_228.right - local_228.left,
                 local_228.bottom - local_228.top,1);
      goto LAB_000151b8;
    }
    if (param_2 == 6) {
      if ((param_3 & 0xffff) != 0) {
        SetFocus(DAT_00023458);
      }
      goto LAB_000151b8;
    }
    if (param_2 == 0x15) {
      SendMessageW(DAT_00023458,0x15,param_3,(LPARAM)param_4);
      SendMessageW(DAT_00023454,0x15,param_3,(LPARAM)param_4);
      goto LAB_000151b8;
    }
    if (param_2 == 0x4e) {
      if ((param_4 != (undefined4 *)0x0) && ((HWND)*param_4 == DAT_00023458)) {
        LVar1 = FUN_0001390c((int)param_4);
        goto LAB_00014f94;
      }
      goto LAB_000151b8;
    }
LAB_0001514c:
    LVar1 = DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
LAB_00014f94:
    FUN_000219a0(local_18);
    return LVar1;
  }
  if (param_2 == 0x7b) {
    FUN_00013310();
    FUN_000219a0(local_18);
    return 1;
  }
  if (param_2 == 0x111) {
    LVar1 = FUN_00013d60(param_3 & 0xffff);
    goto LAB_00014f94;
  }
  if (param_2 == 0x219) {
    if (DAT_00023488 != 0) {
      DAT_0002348c = 1;
      goto LAB_000151b8;
    }
    if (DAT_00023484 != 0) {
      FUN_0001c21c(DAT_00023484);
    }
  }
  else if (param_2 != 0x3fe) {
    if (param_2 == 0x401) {
      FUN_000133b8((UINT)param_4,param_3,0x30);
      goto LAB_000151b8;
    }
    goto LAB_0001514c;
  }
  FUN_00012ae4();
LAB_000151b8:
  FUN_000219a0(local_18);
  return 0;
}



/* 00015204 FUN_00015204 */

/* Boundary evidence: original MIPS .pdata 00015204..0001532f. Semantic name remains unreviewed. */

undefined4 FUN_00015204(LPCWSTR param_1,HINSTANCE param_2)

{
  HANDLE lParam;
  int iVar1;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00023464);
  DAT_00023450 = CreateWindowExW(0,param_1,param_1,0x2000000,-0x80000000,-0x80000000,-0x80000000,
                                 -0x80000000,(HWND)0x0,(HMENU)0x0,DAT_0002344c,(LPVOID)0x0);
  if (DAT_00023450 != (HWND)0x0) {
    lParam = LoadImageW(param_2,(LPCWSTR)0xbb8,1,0x10,0x10,0);
    if (lParam != (HANDLE)0x0) {
      SendMessageW(DAT_00023450,0x80,0,(LPARAM)lParam);
    }
    iVar1 = FUN_00012924();
    if (iVar1 != 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00023464);
      iVar1 = FUN_000145c8();
      if (iVar1 != 0) {
        ShowWindow(DAT_00023450,5);
        UpdateWindow(DAT_00023450);
        SetFocus(DAT_00023458);
        return 1;
      }
    }
  }
  return 0;
}



/* 00015330 FUN_00015330 */

/* Boundary evidence: original MIPS .pdata 00015330..00015557. Semantic name remains unreviewed. */

undefined4 FUN_00015330(HINSTANCE param_1)

{
  ATOM AVar1;
  int iVar2;
  HWND pHVar3;
  undefined2 extraout_var;
  HMENU pHVar4;
  HACCEL hAccTable;
  UINT uID;
  tagMSG local_168;
  WNDCLASSW local_148;
  WCHAR aWStack_120 [128];
  uint local_20;
  
  local_20 = DAT_00023314;
  local_168.hwnd = (HWND)0x0;
  memset(&local_168.message,0,0x18);
  DAT_0002344c = param_1;
  iVar2 = GetSystemMetrics(0);
  if (iVar2 < 0x1e0) {
    DAT_00023448 = 1;
  }
  uID = 0x1771;
  if (DAT_00023448 == 0) {
    uID = 6000;
  }
  LoadStringW(param_1,uID,aWStack_120,0x80);
  pHVar3 = FindWindowW(aWStack_120,aWStack_120);
  if (pHVar3 == (HWND)0x0) {
    iVar2 = FUN_0001270c();
    if (iVar2 != 0) {
      InitCommonControls();
      FUN_00020d30(param_1);
      local_148.style = 0;
      memset(&local_148.lpfnWndProc,0,0x24);
      local_148.lpfnWndProc = FUN_00014ef8;
      local_148.hInstance = param_1;
      local_148.hbrBackground = GetStockObject(1);
      local_148.lpszClassName = aWStack_120;
      AVar1 = RegisterClassW(&local_148);
      if ((CONCAT22(extraout_var,AVar1) != 0) &&
         (iVar2 = FUN_00015204(aWStack_120,param_1), iVar2 != 0)) {
        pHVar4 = (HMENU)(*DAT_00023428)(DAT_00023454,0);
        FUN_00012d10(pHVar4);
        FUN_00014d7c();
        hAccTable = LoadAcceleratorsW(param_1,L"CONNMC_ACCEL");
        iVar2 = GetMessageW(&local_168,(HWND)0x0,0,0);
        while (iVar2 != 0) {
          if ((DAT_00023490 != 0) ||
             (iVar2 = TranslateAcceleratorW(DAT_00023450,hAccTable,&local_168), iVar2 == 0)) {
            TranslateMessage(&local_168);
            DispatchMessageW(&local_168);
          }
          iVar2 = GetMessageW(&local_168,(HWND)0x0,0,0);
        }
        FUN_000135c4();
      }
      FUN_0001f9fc(param_1);
      FUN_000219a0(local_20);
      return local_168.wParam;
    }
  }
  else {
    SetForegroundWindow((HWND)((uint)pHVar3 | 1));
  }
  FUN_000219a0(local_20);
  return 0;
}



/* 00015558 FUN_00015558 */

/* Boundary evidence: original MIPS .pdata 00015558..000155ff. Semantic name remains unreviewed. */

void FUN_00015558(int param_1,wchar_t *param_2)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  wchar_t *pwVar4;
  
  if (param_2 != (wchar_t *)0x0) {
    pwVar4 = *(wchar_t **)(param_1 + 4);
    if (pwVar4 != (wchar_t *)0x0) {
      iVar1 = wcscmp(param_2,pwVar4);
      if (iVar1 == 0) {
        return;
      }
      operator_delete(pwVar4);
    }
    sVar2 = wcslen(param_2);
    if (sVar2 + 1 < 0x80000000) {
      uVar3 = (sVar2 + 1) * 2;
    }
    else {
      uVar3 = 0xffffffff;
    }
    pwVar4 = operator_new(uVar3);
    *(wchar_t **)(param_1 + 4) = pwVar4;
    if (pwVar4 != (wchar_t *)0x0) {
      wcscpy(pwVar4,param_2);
    }
  }
  return;
}



/* 00015600 FUN_00015600 */

/* Boundary evidence: original MIPS .pdata 00015600..0001568f. Semantic name remains unreviewed. */

undefined4 * FUN_00015600(undefined4 *param_1,wchar_t *param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  uint uVar2;
  
  FUN_00020d9c(param_1);
  *param_1 = &PTR_FUN_000114fc;
  if (param_2 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_2);
    if (sVar1 + 1 < 0x80000000) {
      uVar2 = (sVar1 + 1) * 2;
    }
    else {
      uVar2 = 0xffffffff;
    }
    _Dest = operator_new(uVar2);
    param_1[1] = _Dest;
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,param_2);
    }
  }
  return param_1;
}



/* 000156c0 FUN_000156c0 */

/* Boundary evidence: original MIPS .pdata 000156c0..000156f7. Semantic name remains unreviewed. */

bool FUN_000156c0(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = wcscmp(param_2,L"NewConnInfo");
  return iVar1 == 0;
}



/* 00015704 FUN_00015704 */

/* Boundary evidence: original MIPS .pdata 00015704..00015747. Semantic name remains unreviewed. */

undefined4 FUN_00015704(undefined4 param_1,HINSTANCE param_2,LPWSTR param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_3 == (LPWSTR)0x0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x1900;
    }
    uVar1 = 0;
  }
  else {
    LoadStringW(param_2,0x17d4,param_3,0x80);
    uVar1 = 1;
  }
  return uVar1;
}



/* 00015748 FUN_00015748 */

/* Boundary evidence: original MIPS .pdata 00015748..0001582f. Semantic name remains unreviewed. */

undefined4 FUN_00015748(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_28;
  int *local_20;
  
  if (param_1[3] == 0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x1900;
    }
  }
  else {
    local_40 = 0;
    memset(&local_3c,0,0x24);
    local_48[0] = 0;
    local_48[0] = (**(code **)(*param_1 + 0x50))(param_1,0,param_2);
    if (local_48[0] != 0) {
      local_40 = 0x28;
      local_3c = 0xa0;
      local_20 = local_48;
      local_28 = 1;
      local_38 = param_3;
      local_34 = param_2;
      (*(code *)param_1[3])(&local_40);
      return 1;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x1900;
    }
  }
  return 0;
}



/* 00015878 FUN_00015878 */

/* Boundary evidence: original MIPS .pdata 00015878..00016117. Semantic name remains unreviewed. */

undefined4 FUN_00015878(HWND param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  LONG LVar2;
  HWND pHVar3;
  int iVar4;
  int iVar5;
  int bEnable;
  int bEnable_00;
  int bEnable_01;
  LRESULT LVar6;
  undefined4 *puVar7;
  LPARAM LVar8;
  WPARAM wParam;
  LONG dwNewLong;
  int local_60 [2];
  wchar_t local_58;
  undefined1 auStack_56 [42];
  uint local_2c;
  
  local_2c = DAT_00023314;
  LVar2 = GetWindowLongW(param_1,-0x15);
  if (param_2 == 2) {
    if (DAT_00023494 != (int *)0x0) {
      (**(code **)*DAT_00023494)(DAT_00023494,1);
      DAT_00023494 = (int *)0x0;
    }
    goto LAB_000160e0;
  }
  if (param_2 == 0x4e) {
    dwNewLong = 0;
    if (*(int *)(param_4 + 8) == -0xcf) {
      local_58 = L'\0';
      bVar1 = true;
      memset(auStack_56,0,0x28);
      GetDlgItemTextW(param_1,5000,&local_58,0x15);
      local_60[0] = 0;
      FUN_0001384c(&local_58,local_60);
      if (local_60[0] == 0) {
        SetDlgItemTextW(param_1,5000,&local_58);
        pHVar3 = GetDlgItem(param_1,0x1389);
        LVar6 = SendMessageW(pHVar3,0xf0,0,0);
        if (LVar6 == 1) {
          if (DAT_00023494 != (int *)0x0) {
            iVar4 = (**(code **)(*DAT_00023494 + 4))(DAT_00023494,L"RnaConnInfo");
            if (iVar4 != 0) {
LAB_00015cd0:
              FUN_00015558((int)DAT_00023494,&local_58);
              if (DAT_00023498 < 2) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
              goto LAB_00015f3c;
            }
            if (DAT_00023494 != (int *)0x0) {
              (**(code **)*DAT_00023494)(DAT_00023494,1);
            }
          }
          puVar7 = operator_new(0xdbc);
          if (puVar7 == (undefined4 *)0x0) goto LAB_00015f34;
          DAT_00023494 = FUN_00016204(puVar7,&local_58);
        }
        else {
          pHVar3 = GetDlgItem(param_1,0x138a);
          LVar6 = SendMessageW(pHVar3,0xf0,0,0);
          if (LVar6 == 1) {
            if (DAT_00023494 != (int *)0x0) {
              iVar4 = (**(code **)(*DAT_00023494 + 4))(DAT_00023494,L"DccConnInfo");
              if (iVar4 != 0) goto LAB_00015cd0;
              if (DAT_00023494 != (int *)0x0) {
                (**(code **)*DAT_00023494)(DAT_00023494,1);
              }
            }
            puVar7 = operator_new(0xdbc);
            if (puVar7 == (undefined4 *)0x0) {
LAB_00015f34:
              DAT_00023494 = (int *)0x0;
            }
            else {
              DAT_00023494 = FUN_000172b0(puVar7,&local_58);
            }
          }
          else {
            pHVar3 = GetDlgItem(param_1,0x138b);
            LVar6 = SendMessageW(pHVar3,0xf0,0,0);
            if (LVar6 != 1) {
              pHVar3 = GetDlgItem(param_1,0x138d);
              LVar6 = SendMessageW(pHVar3,0xf0,0,0);
              if (LVar6 != 1) {
                pHVar3 = GetDlgItem(param_1,0x138c);
                LVar6 = SendMessageW(pHVar3,0xf0,0,0);
                if (LVar6 == 1) {
                  if (DAT_00023494 != (int *)0x0) {
                    iVar4 = (**(code **)(*DAT_00023494 + 4))(DAT_00023494,L"PPPOEConnInfo");
                    if (iVar4 != 0) goto LAB_00015cd0;
                    if (DAT_00023494 != (int *)0x0) {
                      (**(code **)*DAT_00023494)(DAT_00023494,1);
                    }
                  }
                  puVar7 = operator_new(0xdbc);
                  if (puVar7 == (undefined4 *)0x0) goto LAB_00015f34;
                  DAT_00023494 = FUN_0001a828(puVar7,&local_58);
                }
                goto LAB_00015f3c;
              }
            }
            pHVar3 = GetDlgItem(param_1,0x138d);
            LVar6 = SendMessageW(pHVar3,0xf0,0,0);
            if (DAT_00023494 != (int *)0x0) {
              iVar4 = (**(code **)(*DAT_00023494 + 4))(DAT_00023494,L"VpnConnInfo");
              if (iVar4 != 0) goto LAB_00015cd0;
              if (DAT_00023494 != (int *)0x0) {
                (**(code **)*DAT_00023494)(DAT_00023494,1);
              }
            }
            puVar7 = operator_new(0xdc0);
            if (puVar7 == (undefined4 *)0x0) goto LAB_00015f34;
            DAT_00023494 = FUN_000179d4(puVar7,&local_58,(uint)(LVar6 == 1));
          }
        }
LAB_00015f3c:
        if (DAT_00023494 == (int *)0x0) {
          pHVar3 = GetParent(param_1);
          EnableWindow(pHVar3,0);
          pHVar3 = GetParent(param_1);
          pHVar3 = GetParent(pHVar3);
          LVar8 = 0x1901;
        }
        else {
          (**(code **)(*DAT_00023494 + 8))(DAT_00023494,local_60);
          if (local_60[0] == 0x190e) {
            if (bVar1) {
              for (; 1 < DAT_00023498; DAT_00023498 = DAT_00023498 - 1) {
                wParam = DAT_00023498 - 1;
                pHVar3 = GetParent(param_1);
                SendMessageW(pHVar3,0x466,wParam,0);
              }
              iVar4 = 0;
              while (iVar5 = (**(code **)(*DAT_00023494 + 0x50))
                                       (DAT_00023494,iVar4,*(undefined4 *)(LVar2 + 8)), iVar5 != 0)
              {
                pHVar3 = GetParent(param_1);
                SendMessageW(pHVar3,0x467,0,iVar5);
                DAT_00023498 = DAT_00023498 + 1;
                iVar4 = iVar4 + 1;
              }
            }
            goto LAB_000160a0;
          }
          pHVar3 = GetParent(param_1);
          EnableWindow(pHVar3,0);
          pHVar3 = GetParent(param_1);
          pHVar3 = GetParent(pHVar3);
          LVar8 = local_60[0];
        }
        SendMessageW(pHVar3,0x401,0,LVar8);
        pHVar3 = GetParent(param_1);
        EnableWindow(pHVar3,1);
        pHVar3 = GetDlgItem(param_1,5000);
        SetFocus(pHVar3);
      }
      else {
        pHVar3 = GetParent(param_1);
        EnableWindow(pHVar3,0);
        pHVar3 = GetParent(param_1);
        pHVar3 = GetParent(pHVar3);
        SendMessageW(pHVar3,0x401,0,local_60[0]);
        pHVar3 = GetParent(param_1);
        EnableWindow(pHVar3,1);
        pHVar3 = GetDlgItem(param_1,5000);
        SetFocus(pHVar3);
        SetDlgItemTextW(param_1,5000,&local_58);
      }
      dwNewLong = 1;
    }
    else if (*(int *)(param_4 + 8) == -200) {
      iVar4 = FUN_0001d9a8(L"modem",(wchar_t *)0x0);
      if ((((iVar4 == 0) && (iVar4 = FUN_0001d9a8(L"direct",(wchar_t *)0x0), iVar4 == 0)) &&
          (iVar4 = FUN_0001d9a8(L"vpn",(wchar_t *)0x0), iVar4 == 0)) &&
         (iVar4 = FUN_0001d9a8(L"PPPoE",(wchar_t *)0x0), iVar4 == 0)) {
        pHVar3 = GetParent(param_1);
        LVar8 = 0;
      }
      else {
        pHVar3 = GetParent(param_1);
        LVar8 = 2;
      }
      PostMessageW(pHVar3,0x470,0,LVar8);
    }
LAB_000160a0:
    SetWindowLongW(param_1,0,dwNewLong);
LAB_000160e0:
    FUN_000219a0(local_2c);
    return 1;
  }
  if (param_2 != 0x110) goto LAB_00015ac0;
  SetWindowLongW(param_1,-0x15,param_4);
  FUN_0001d838(*(HINSTANCE *)(param_4 + 8),&local_58);
  pHVar3 = GetDlgItem(param_1,5000);
  SendMessageW(pHVar3,0xc5,0x14,0);
  pHVar3 = GetDlgItem(param_1,5000);
  SetWindowTextW(pHVar3,&local_58);
  pHVar3 = GetDlgItem(param_1,5000);
  SendMessageW(pHVar3,0xb1,0,-1);
  iVar4 = FUN_0001d9a8(L"modem",(wchar_t *)0x0);
  iVar5 = FUN_0001d9a8(L"direct",(wchar_t *)0x0);
  bEnable = FUN_0001d9a8(L"vpn",L"RAS VPN Line");
  bEnable_00 = FUN_0001d9a8(L"vpn",L"L2TP Line");
  bEnable_01 = FUN_0001d9a8(L"PPPoE",(wchar_t *)0x0);
  pHVar3 = GetDlgItem(param_1,0x1389);
  EnableWindow(pHVar3,iVar4);
  pHVar3 = GetDlgItem(param_1,0x138a);
  EnableWindow(pHVar3,iVar5);
  pHVar3 = GetDlgItem(param_1,0x138b);
  EnableWindow(pHVar3,bEnable);
  pHVar3 = GetDlgItem(param_1,0x138d);
  EnableWindow(pHVar3,bEnable_00);
  pHVar3 = GetDlgItem(param_1,0x138c);
  EnableWindow(pHVar3,bEnable_01);
  if (iVar4 == 0) {
    if (iVar5 != 0) {
      iVar4 = 0x138a;
      goto LAB_00015a90;
    }
    if (bEnable != 0) {
      iVar4 = 0x138b;
      goto LAB_00015a90;
    }
    if (bEnable_00 != 0) {
      iVar4 = 0x138d;
      goto LAB_00015a90;
    }
    if (bEnable_01 != 0) {
      iVar4 = 0x138c;
      goto LAB_00015a90;
    }
  }
  else {
    iVar4 = 0x1389;
LAB_00015a90:
    CheckRadioButton(param_1,0x1389,0x138d,iVar4);
  }
  DAT_00023498 = 1;
  pHVar3 = GetDlgItem(param_1,5000);
  SetFocus(pHVar3);
LAB_00015ac0:
  FUN_000219a0(local_2c);
  return 0;
}



/* 00016118 FUN_00016118 */

/* Boundary evidence: original MIPS .pdata 00016118..00016163. Semantic name remains unreviewed. */

undefined4 * FUN_00016118(undefined4 *param_1,uint param_2)

{
  FUN_00020e58(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00016164 FUN_00016164 */

/* Boundary evidence: original MIPS .pdata 00016164..00016203. Semantic name remains unreviewed. */

undefined4 FUN_00016164(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 local_40;
  undefined1 auStack_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  code *local_28;
  int local_24;
  
  pcVar2 = *(code **)(param_1 + 0x10);
  if (pcVar2 != (code *)0x0) {
    memset(auStack_3c,0,0x24);
    local_40 = 0x28;
    if (param_2 == 0) {
      local_34 = 0x1004;
      if (DAT_00023448 == 0) {
        local_34 = 4000;
      }
      local_28 = FUN_00015878;
      local_38 = param_3;
      local_24 = param_1;
      uVar1 = (*pcVar2)(&local_40);
      return uVar1;
    }
  }
  return 0;
}



/* 00016204 FUN_00016204 */

/* Boundary evidence: original MIPS .pdata 00016204..00016317. Semantic name remains unreviewed. */

undefined4 * FUN_00016204(undefined4 *param_1,wchar_t *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  wchar_t *_Str1;
  uint uVar4;
  void *local_28 [2];
  
  FUN_0001e910(param_1,param_2);
  *param_1 = &PTR_FUN_0001161c;
  iVar2 = wcscmp((wchar_t *)(param_1 + 0x1de),L"modem");
  if (iVar2 != 0) {
    local_28[0] = (void *)0x0;
    uVar3 = FUN_0001d91c(local_28);
    pvVar1 = local_28[0];
    uVar4 = 0;
    if (uVar3 != 0) {
      _Str1 = (wchar_t *)((int)local_28[0] + 4);
      do {
        if (pvVar1 == (void *)0x0) {
          return param_1;
        }
        iVar2 = wcscmp(_Str1,L"modem");
        if (iVar2 == 0) {
          wcscpy((wchar_t *)((int)param_1 + 0x79a),(wchar_t *)((int)pvVar1 + uVar4 * 0x128 + 0x26));
          wcscpy((wchar_t *)(param_1 + 0x1de),L"modem");
          break;
        }
        uVar4 = uVar4 + 1;
        _Str1 = _Str1 + 0x94;
      } while (uVar4 < uVar3);
    }
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
  }
  return param_1;
}



/* 0001632c FUN_0001632c */

/* Boundary evidence: original MIPS .pdata 0001632c..00016363. Semantic name remains unreviewed. */

bool FUN_0001632c(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = wcscmp(param_2,L"RnaConnInfo");
  return iVar1 == 0;
}



/* 00016370 FUN_00016370 */

/* Boundary evidence: original MIPS .pdata 00016370..0001638f. Semantic name remains unreviewed. */

void FUN_00016370(undefined4 param_1,HINSTANCE param_2,LPWSTR param_3,int param_4)

{
  LoadStringW(param_2,0x1840,param_3,param_4);
  return;
}



/* 00016390 FUN_00016390 */

/* Boundary evidence: original MIPS .pdata 00016390..000168db. Semantic name remains unreviewed. */

undefined4 FUN_00016390(HWND param_1,int param_2,short param_3,int param_4)

{
  LONG LVar1;
  HCURSOR pHVar2;
  uint uVar3;
  int iVar4;
  WPARAM WVar5;
  HWND pHVar6;
  HMODULE hLibModule;
  code *pcVar7;
  DWORD DVar8;
  int iVar9;
  LPVOID pvVar10;
  void *pvVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  void *local_138 [2];
  WCHAR local_130 [130];
  uint local_2c;
  
  local_2c = DAT_00023314;
  LVar1 = GetWindowLongW(param_1,-0x15);
  pvVar10 = (LPVOID)0x0;
  if (LVar1 != 0) {
    pvVar10 = *(LPVOID *)(LVar1 + 0x1c);
  }
  if (param_2 == 0x4e) {
    if (pvVar10 != (LPVOID)0x0) {
      iVar12 = *(int *)(param_4 + 8);
      if (iVar12 == -0xca) {
        FUN_0001ebc8((int)pvVar10);
      }
      else if (iVar12 == -0xc9) {
        pHVar6 = GetDlgItem(param_1,0x13a8);
        GetWindowTextW(pHVar6,(LPWSTR)((int)pvVar10 + 0x79a),0x81);
      }
      else if (iVar12 == -200) {
        pHVar6 = GetParent(param_1);
        PostMessageW(pHVar6,0x470,0,3);
        pHVar6 = GetDlgItem(param_1,0x138c);
        SetWindowTextW(pHVar6,*(LPCWSTR *)((int)pvVar10 + 4));
      }
      SetWindowLongW(param_1,0,0);
      goto LAB_000168a0;
    }
  }
  else {
    if (param_2 != 0x110) {
      if (param_2 == 0x111) {
        if (param_3 == 0x138e) {
          if (pvVar10 != (LPVOID)0x0) {
            FUN_0001ec20(pvVar10,param_1);
          }
        }
        else if (param_3 == 0x138f) {
          if (pvVar10 != (LPVOID)0x0) {
            FUN_0001f664(pvVar10,param_1,*(HINSTANCE *)(LVar1 + 8));
          }
        }
        else if (param_3 == 0x13a8) {
          if (pvVar10 != (LPVOID)0x0) {
            local_130[0] = L'\0';
            pHVar6 = GetDlgItem(param_1,0x13a8);
            GetWindowTextW(pHVar6,local_130,0x81);
            iVar12 = wcscmp((wchar_t *)((int)pvVar10 + 0x79a),local_130);
            if (iVar12 != 0) {
              wcscpy((wchar_t *)((int)pvVar10 + 0x79a),local_130);
              operator_delete(*(void **)((int)pvVar10 + 0xdb4));
              *(undefined4 *)((int)pvVar10 + 0xdb4) = 0;
              *(undefined4 *)((int)pvVar10 + 0xdb8) = 0;
            }
          }
        }
        else if (param_3 == 0x13aa) {
          if (pvVar10 != (LPVOID)0x0) {
            FUN_0001f798(pvVar10,param_1,*(HINSTANCE *)(LVar1 + 8));
          }
        }
        else if ((param_3 == 0x13bc) &&
                (hLibModule = LoadLibraryW(L"netui.dll"), hLibModule != (HMODULE)0x0)) {
          pcVar7 = (code *)GetProcAddressW(hLibModule,L"CreateScanDevice");
          if (pcVar7 != (code *)0x0) {
            (*pcVar7)(hLibModule,param_1);
            PostMessageW(param_1,0x219,0,0);
          }
          FreeLibrary(hLibModule);
        }
      }
      else {
        if (param_2 != 0x219) goto LAB_000167d8;
        if (pvVar10 != (LPVOID)0x0) {
          pHVar2 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
          pHVar2 = SetCursor(pHVar2);
          SendDlgItemMessageW(param_1,0x13a8,0x14b,0,0);
          local_138[0] = (void *)0x0;
          uVar3 = FUN_0001d91c(local_138);
          uVar14 = 0;
          pvVar11 = local_138[0];
          if (uVar3 != 0) {
            iVar12 = 0;
            do {
              if (pvVar11 == (void *)0x0) goto LAB_000164e0;
              iVar4 = wcscmp((wchar_t *)((int)pvVar11 + iVar12 + 4),L"modem");
              if (iVar4 == 0) {
                SendDlgItemMessageW(param_1,0x13a8,0x143,0,(int)pvVar11 + iVar12 + 0x26);
                pvVar11 = local_138[0];
              }
              uVar14 = uVar14 + 1;
              iVar12 = iVar12 + 0x128;
            } while (uVar14 < uVar3);
          }
          if (pvVar11 != (void *)0x0) {
            operator_delete(pvVar11);
          }
LAB_000164e0:
          WVar5 = SendDlgItemMessageW(param_1,0x13a8,0x158,0,(int)pvVar10 + 0x79a);
          if (WVar5 == 0xffffffff) {
            WVar5 = 0;
          }
          pHVar6 = GetDlgItem(param_1,0x13a8);
          SendMessageW(pHVar6,0x14e,WVar5,0);
          SetCursor(pHVar2);
        }
      }
LAB_000168a0:
      FUN_000219a0(local_2c);
      return 1;
    }
    SetWindowLongW(param_1,-0x15,param_4);
    iVar12 = *(int *)(param_4 + 0x1c);
    DVar8 = GetFileAttributesW(L"\\Windows\\btd.dll");
    if (DVar8 != 0xffffffff) {
      pHVar6 = GetDlgItem(param_1,0x13bc);
      ShowWindow(pHVar6,5);
    }
    local_138[0] = (void *)0x0;
    iVar4 = FUN_0001d91c(local_138);
    pvVar11 = local_138[0];
    if (iVar4 != 0) {
      iVar13 = 0;
      do {
        iVar9 = wcscmp((wchar_t *)((int)pvVar11 + iVar13 + 4),L"modem");
        if (iVar9 == 0) {
          SendDlgItemMessageW(param_1,0x13a8,0x143,0,(int)pvVar11 + iVar13 + 0x26);
          pvVar11 = local_138[0];
        }
        iVar4 = iVar4 + -1;
        iVar13 = iVar13 + 0x128;
      } while (iVar4 != 0);
    }
    if (pvVar11 != (void *)0x0) {
      operator_delete(pvVar11);
    }
    WVar5 = SendDlgItemMessageW(param_1,0x13a8,0x158,0,iVar12 + 0x79a);
    if (WVar5 == 0xffffffff) {
      WVar5 = 0;
    }
    pHVar6 = GetDlgItem(param_1,0x13a8);
    SendMessageW(pHVar6,0x14e,WVar5,0);
    pHVar6 = GetDlgItem(param_1,0x13a8);
    SetFocus(pHVar6);
  }
LAB_000167d8:
  FUN_000219a0(local_2c);
  return 0;
}



/* 000168dc FUN_000168dc */

/* Boundary evidence: original MIPS .pdata 000168dc..00016933. Semantic name remains unreviewed. */

void FUN_000168dc(int param_1)

{
  if ((*(HWND *)(param_1 + 0x104) != (HWND)0x0) && (*(int *)(param_1 + 0x108) != 0)) {
    SetWindowLongW(*(HWND *)(param_1 + 0x104),-4,*(int *)(param_1 + 0x108));
    SetWindowLongW(*(HWND *)(param_1 + 0x104),-0x15,0);
  }
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  return;
}



/* 00016934 FUN_00016934 */

/* Boundary evidence: original MIPS .pdata 00016934..000169ff. Semantic name remains unreviewed. */

LRESULT FUN_00016934(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  wchar_t *_Str;
  wchar_t *pwVar1;
  LRESULT LVar2;
  
  _Str = (wchar_t *)GetWindowLongW(param_1,-0x15);
  if ((_Str == (wchar_t *)0x0) || (*(int *)(_Str + 0x84) == 0)) {
    LVar2 = DefWindowProcW(param_1,param_2,param_3,param_4);
  }
  else if ((param_2 == 0x102) && (pwVar1 = wcschr(_Str,(wchar_t)param_3), pwVar1 == (wchar_t *)0x0))
  {
    LVar2 = 0;
  }
  else {
    LVar2 = CallWindowProcW(*(WNDPROC *)(_Str + 0x84),param_1,param_2,param_3,param_4);
  }
  return LVar2;
}



/* 00016a00 FUN_00016a00 */

/* Boundary evidence: original MIPS .pdata 00016a00..00016a4b. Semantic name remains unreviewed. */

undefined4 * FUN_00016a00(undefined4 *param_1,uint param_2)

{
  FUN_0001c4a8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00016a4c FUN_00016a4c */

/* Boundary evidence: original MIPS .pdata 00016a4c..00016ae7. Semantic name remains unreviewed. */

undefined4 FUN_00016a4c(STRSAFE_LPWSTR param_1,STRSAFE_LPCWSTR param_2,HWND param_3)

{
  LONG LVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  LVar1 = GetWindowLongW(param_3,-4);
  *(LONG *)(param_1 + 0x84) = LVar1;
  if (LVar1 != 0) {
    *(HWND *)(param_1 + 0x82) = param_3;
    SetWindowLongW(param_3,-0x15,(LONG)param_1);
    SetWindowLongW(*(HWND *)(param_1 + 0x82),-4,0x16934);
    StringCchCopyW(param_1,0x80,param_2);
    uVar2 = 0;
  }
  return uVar2;
}



/* 00016ae8 FUN_00016ae8 */

/* Boundary evidence: original MIPS .pdata 00016ae8..00016b4f. Semantic name remains unreviewed. */

undefined4 FUN_00016ae8(STRSAFE_LPWSTR param_1,STRSAFE_LPCWSTR param_2,HWND param_3,int param_4)

{
  HWND pHVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  pHVar1 = GetDlgItem(param_3,param_4);
  if (pHVar1 != (HWND)0x0) {
    uVar2 = FUN_00016a4c(param_1,param_2,pHVar1);
  }
  return uVar2;
}



/* 00016b50 FUN_00016b50 */

/* Boundary evidence: original MIPS .pdata 00016b50..000171df. Semantic name remains unreviewed. */

undefined4 FUN_00016b50(HWND param_1,int param_2,short param_3,int param_4)

{
  WCHAR WVar1;
  LONG LVar2;
  LRESULT LVar3;
  LPLINETRANSLATECAPS hMem;
  int iVar4;
  HWND pHVar5;
  UINT UVar6;
  WCHAR *pWVar7;
  int iVar8;
  WCHAR *lpString;
  WCHAR local_50 [16];
  uint local_30;
  
  local_30 = DAT_00023314;
  LVar2 = GetWindowLongW(param_1,-0x15);
  iVar8 = 0;
  if (LVar2 != 0) {
    iVar8 = *(int *)(LVar2 + 0x1c);
  }
  if (param_2 == 2) {
    FUN_000168dc(0x2349c);
LAB_000171a4:
    FUN_000219a0(local_30);
    return 0;
  }
  if (param_2 != 0x4e) {
    if (param_2 == 0x110) {
      SetWindowLongW(param_1,-0x15,param_4);
      iVar8 = *(int *)(param_4 + 0x1c);
      hMem = FUN_0001daac(*(HINSTANCE *)(param_4 + 8));
      if (hMem != (LPLINETRANSLATECAPS)0x0) {
        if (*(int *)(iVar8 + 0x20) == 0) {
          iVar4 = FUN_0001db84((int)hMem);
          *(int *)(iVar8 + 0x20) = iVar4;
        }
        if (*(wchar_t *)(iVar8 + 0x24) == L'\0') {
          FUN_0001dbd0((int)hMem,(wchar_t *)(iVar8 + 0x24),10);
        }
        LocalFree(hMem);
      }
      pHVar5 = GetDlgItem(param_1,0x1391);
      SendMessageW(pHVar5,0xc5,10,0);
      pHVar5 = GetDlgItem(param_1,0x1392);
      SendMessageW(pHVar5,0xc5,0x80,0);
      pHVar5 = GetDlgItem(param_1,0x1390);
      SendMessageW(pHVar5,0xc5,0x10,0);
      pHVar5 = GetDlgItem(param_1,0x1391);
      SetWindowTextW(pHVar5,(LPCWSTR)(iVar8 + 0x24));
      pHVar5 = GetDlgItem(param_1,0x1392);
      SetWindowTextW(pHVar5,(LPCWSTR)(iVar8 + 0x3a));
      local_50[0] = L'\0';
      if (*(int *)(iVar8 + 0x20) != 0) {
        wsprintfW(local_50,L"%u");
      }
      pHVar5 = GetDlgItem(param_1,0x1390);
      SetWindowTextW(pHVar5,local_50);
      if ((*(uint *)(iVar8 + 0x18) & 1) != 0) {
        SendDlgItemMessageW(param_1,0x1393,0xf1,1,0);
      }
      if ((*(uint *)(iVar8 + 0x18) & 0x20000) != 0) {
        SendDlgItemMessageW(param_1,0x1394,0xf1,1,0);
      }
      pHVar5 = GetDlgItem(param_1,0x1390);
      ImmAssociateContext(pHVar5,(HIMC)0x0);
      pHVar5 = GetDlgItem(param_1,0x1391);
      ImmAssociateContext(pHVar5,(HIMC)0x0);
      pHVar5 = GetDlgItem(param_1,0x1392);
      ImmAssociateContext(pHVar5,(HIMC)0x0);
      FUN_00016ae8((STRSAFE_LPWSTR)&DAT_0002349c,L"1234567890*#\b",param_1,0x1392);
      pHVar5 = GetDlgItem(param_1,0x1392);
      SetFocus(pHVar5);
    }
    else if (param_2 == 0x111) {
      if (param_3 == 0x1393) {
        LVar3 = SendDlgItemMessageW(param_1,0x1393,0xf0,0,0);
        if (LVar3 == 1) {
          SendDlgItemMessageW(param_1,0x1394,0xf1,0,0);
        }
      }
      else if ((param_3 == 0x1394) &&
              (LVar3 = SendDlgItemMessageW(param_1,0x1394,0xf0,0,0), LVar3 == 1)) {
        SendDlgItemMessageW(param_1,0x1393,0xf1,0,0);
      }
      goto LAB_00017188;
    }
    goto LAB_000171a4;
  }
  if (iVar8 == 0) goto LAB_00017188;
  iVar4 = *(int *)(param_4 + 8);
  LVar2 = 0;
  if (iVar4 == -0xd0) {
LAB_00016f10:
    GetDlgItemTextW(param_1,0x1391,(LPWSTR)(iVar8 + 0x24),0xb);
    lpString = (WCHAR *)(iVar8 + 0x3a);
    GetDlgItemTextW(param_1,0x1392,lpString,0x81);
    WVar1 = *lpString;
    pWVar7 = lpString;
    for (; (WVar1 != L'\0' && (WVar1 = *lpString, WVar1 != L'\0')); lpString = lpString + 1) {
      if (WVar1 != L' ') {
        *pWVar7 = WVar1;
        pWVar7 = pWVar7 + 1;
      }
      WVar1 = *pWVar7;
    }
    UVar6 = GetDlgItemInt(param_1,0x1390,(BOOL *)0x0,0);
    *(UINT *)(iVar8 + 0x20) = UVar6;
    LVar3 = SendDlgItemMessageW(param_1,0x1393,0xf0,0,0);
    if (LVar3 == 1) {
      *(uint *)(iVar8 + 0x18) = *(uint *)(iVar8 + 0x18) | 1;
    }
    else {
      *(uint *)(iVar8 + 0x18) = *(uint *)(iVar8 + 0x18) & 0xfffffffe;
    }
    LVar3 = SendDlgItemMessageW(param_1,0x1394,0xf0,0,0);
    if (LVar3 == 1) {
      *(uint *)(iVar8 + 0x18) = *(uint *)(iVar8 + 0x18) | 0x20000;
    }
    else {
      *(uint *)(iVar8 + 0x18) = *(uint *)(iVar8 + 0x18) & 0xfffdffff;
    }
    if (*(int *)(param_4 + 8) == -0xd0) {
LAB_00017024:
      if (*(wchar_t *)(iVar8 + 0x3a) == L'\0') {
        pHVar5 = GetParent(param_1);
        EnableWindow(pHVar5,0);
        pHVar5 = GetParent(param_1);
        pHVar5 = GetParent(pHVar5);
        SendMessageW(pHVar5,0x401,0,0x1907);
        pHVar5 = GetParent(param_1);
        EnableWindow(pHVar5,1);
        iVar8 = 0x1392;
      }
      else {
        iVar4 = FUN_0001dc80((wchar_t *)(iVar8 + 0x3a));
        if (iVar4 == 0) {
          pHVar5 = GetParent(param_1);
          EnableWindow(pHVar5,0);
          pHVar5 = GetParent(param_1);
          pHVar5 = GetParent(pHVar5);
          SendMessageW(pHVar5,0x401,0,0x1907);
          pHVar5 = GetParent(param_1);
          EnableWindow(pHVar5,1);
          iVar8 = 0x190b;
        }
        else {
          if (((*(uint *)(iVar8 + 0x18) & 0x20000) == 0) || (*(short *)(iVar8 + 0x24) != 0)) {
            FUN_0001ebc8(iVar8);
            goto LAB_00017178;
          }
          pHVar5 = GetParent(param_1);
          EnableWindow(pHVar5,0);
          pHVar5 = GetParent(param_1);
          pHVar5 = GetParent(pHVar5);
          SendMessageW(pHVar5,0x401,0,0x1908);
          pHVar5 = GetParent(param_1);
          EnableWindow(pHVar5,1);
          iVar8 = 0x1391;
        }
      }
      pHVar5 = GetDlgItem(param_1,iVar8);
      SetFocus(pHVar5);
      LVar2 = 1;
    }
  }
  else {
    if (iVar4 == -0xca) goto LAB_00017024;
    if (iVar4 == -0xc9) goto LAB_00016f10;
    if (iVar4 == -200) {
      pHVar5 = GetParent(param_1);
      PostMessageW(pHVar5,0x470,0,5);
      pHVar5 = GetDlgItem(param_1,0x138c);
      SetWindowTextW(pHVar5,*(LPCWSTR *)(iVar8 + 4));
    }
  }
LAB_00017178:
  SetWindowLongW(param_1,0,LVar2);
LAB_00017188:
  FUN_000219a0(local_30);
  return 1;
}



/* 000171e0 FUN_000171e0 */

/* Boundary evidence: original MIPS .pdata 000171e0..000172af. Semantic name remains unreviewed. */

undefined4 FUN_000171e0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 local_40;
  undefined1 auStack_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  code *local_28;
  int local_24;
  
  pcVar2 = *(code **)(param_1 + 0x10);
  if (pcVar2 == (code *)0x0) {
LAB_0001720c:
    uVar1 = 0;
  }
  else {
    memset(auStack_3c,0,0x24);
    local_40 = 0x28;
    if (param_2 == 0) {
      local_34 = 0x1005;
      if (DAT_00023448 == 0) {
        local_34 = 0xfa1;
      }
      local_28 = FUN_00016390;
    }
    else {
      if (param_2 != 1) goto LAB_0001720c;
      local_34 = 0x1006;
      if (DAT_00023448 == 0) {
        local_34 = 0xfa2;
      }
      local_28 = FUN_00016b50;
    }
    local_38 = param_3;
    local_24 = param_1;
    uVar1 = (*pcVar2)(&local_40);
  }
  return uVar1;
}



/* 000172b0 FUN_000172b0 */

/* Boundary evidence: original MIPS .pdata 000172b0..000173c3. Semantic name remains unreviewed. */

undefined4 * FUN_000172b0(undefined4 *param_1,wchar_t *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  wchar_t *_Str1;
  uint uVar4;
  void *local_28 [2];
  
  FUN_0001e910(param_1,param_2);
  *param_1 = &PTR_FUN_000116f8;
  iVar2 = wcscmp((wchar_t *)(param_1 + 0x1de),L"direct");
  if (iVar2 != 0) {
    local_28[0] = (void *)0x0;
    uVar3 = FUN_0001d91c(local_28);
    pvVar1 = local_28[0];
    uVar4 = 0;
    if (uVar3 != 0) {
      _Str1 = (wchar_t *)((int)local_28[0] + 4);
      do {
        if (pvVar1 == (void *)0x0) {
          return param_1;
        }
        iVar2 = wcscmp(_Str1,L"direct");
        if (iVar2 == 0) {
          wcscpy((wchar_t *)((int)param_1 + 0x79a),(wchar_t *)((int)pvVar1 + uVar4 * 0x128 + 0x26));
          wcscpy((wchar_t *)(param_1 + 0x1de),L"direct");
          break;
        }
        uVar4 = uVar4 + 1;
        _Str1 = _Str1 + 0x94;
      } while (uVar4 < uVar3);
    }
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
  }
  return param_1;
}



/* 000173c4 FUN_000173c4 */

/* Boundary evidence: original MIPS .pdata 000173c4..000173fb. Semantic name remains unreviewed. */

bool FUN_000173c4(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = wcscmp(param_2,L"DccConnInfo");
  return iVar1 == 0;
}



/* 00017408 FUN_00017408 */

/* Boundary evidence: original MIPS .pdata 00017408..00017427. Semantic name remains unreviewed. */

void FUN_00017408(undefined4 param_1,HINSTANCE param_2,LPWSTR param_3,int param_4)

{
  LoadStringW(param_2,0x183f,param_3,param_4);
  return;
}



/* 00017428 FUN_00017428 */

/* Boundary evidence: original MIPS .pdata 00017428..000178e7. Semantic name remains unreviewed. */

undefined4 FUN_00017428(HWND param_1,int param_2,short param_3,int param_4)

{
  LONG LVar1;
  HCURSOR pHVar2;
  uint uVar3;
  int iVar4;
  WPARAM WVar5;
  HWND pHVar6;
  int iVar7;
  void *pvVar8;
  LPVOID pvVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  void *local_138 [2];
  WCHAR local_130 [130];
  uint local_2c;
  
  local_2c = DAT_00023314;
  LVar1 = GetWindowLongW(param_1,-0x15);
  pvVar9 = (LPVOID)0x0;
  if (LVar1 != 0) {
    pvVar9 = *(LPVOID *)(LVar1 + 0x1c);
  }
  if (param_2 != 0x4e) {
    if (param_2 == 0x110) {
      SetWindowLongW(param_1,-0x15,param_4);
      if ((param_4 != 0) && (iVar10 = *(int *)(param_4 + 0x1c), iVar10 != 0)) {
        local_138[0] = (void *)0x0;
        iVar4 = FUN_0001d91c(local_138);
        pvVar8 = local_138[0];
        if (iVar4 != 0) {
          iVar11 = 0;
          do {
            iVar7 = wcscmp((wchar_t *)((int)pvVar8 + iVar11 + 4),L"direct");
            if (iVar7 == 0) {
              pHVar6 = GetDlgItem(param_1,0x13a8);
              SendMessageW(pHVar6,0x143,0,(int)pvVar8 + iVar11 + 0x26);
              pvVar8 = local_138[0];
            }
            iVar4 = iVar4 + -1;
            iVar11 = iVar11 + 0x128;
          } while (iVar4 != 0);
        }
        if (pvVar8 != (void *)0x0) {
          operator_delete(pvVar8);
        }
        pHVar6 = GetDlgItem(param_1,0x13a8);
        WVar5 = SendMessageW(pHVar6,0x158,0,iVar10 + 0x79a);
        if (WVar5 == 0xffffffff) {
          WVar5 = 0;
        }
        pHVar6 = GetDlgItem(param_1,0x13a8);
        SendMessageW(pHVar6,0x14e,WVar5,0);
        pHVar6 = GetDlgItem(param_1,0x13a8);
        SetFocus(pHVar6);
      }
LAB_000176cc:
      FUN_000219a0(local_2c);
      return 0;
    }
    if (param_2 == 0x111) {
      if (pvVar9 != (LPVOID)0x0) {
        if (param_3 == 0x138e) {
          FUN_0001ec20(pvVar9,param_1);
        }
        else if (param_3 == 0x138f) {
          FUN_0001f664(pvVar9,param_1,*(HINSTANCE *)(LVar1 + 8));
        }
        else if (param_3 == 0x13a8) {
          local_130[0] = L'\0';
          pHVar6 = GetDlgItem(param_1,0x13a8);
          GetWindowTextW(pHVar6,local_130,0x81);
          iVar10 = wcscmp((wchar_t *)((int)pvVar9 + 0x79a),local_130);
          if (iVar10 != 0) {
            wcscpy((wchar_t *)((int)pvVar9 + 0x79a),local_130);
            operator_delete(*(void **)((int)pvVar9 + 0xdb4));
            *(undefined4 *)((int)pvVar9 + 0xdb4) = 0;
            *(undefined4 *)((int)pvVar9 + 0xdb8) = 0;
          }
        }
        else if (param_3 == 0x13aa) {
          FUN_0001f798(pvVar9,param_1,*(HINSTANCE *)(LVar1 + 8));
        }
        goto LAB_000178ac;
      }
      goto LAB_000176cc;
    }
    if ((param_2 != 0x219) || (pvVar9 == (LPVOID)0x0)) goto LAB_000176cc;
    pHVar2 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar2 = SetCursor(pHVar2);
    SendDlgItemMessageW(param_1,0x13a8,0x14b,0,0);
    local_138[0] = (void *)0x0;
    uVar3 = FUN_0001d91c(local_138);
    uVar12 = 0;
    pvVar8 = local_138[0];
    if (uVar3 != 0) {
      iVar10 = 0;
      do {
        if (pvVar8 == (void *)0x0) goto LAB_00017578;
        iVar4 = wcscmp((wchar_t *)((int)pvVar8 + iVar10 + 4),L"direct");
        if (iVar4 == 0) {
          SendDlgItemMessageW(param_1,0x13a8,0x143,0,(int)pvVar8 + iVar10 + 0x26);
          pvVar8 = local_138[0];
        }
        uVar12 = uVar12 + 1;
        iVar10 = iVar10 + 0x128;
      } while (uVar12 < uVar3);
    }
    if (pvVar8 != (void *)0x0) {
      operator_delete(pvVar8);
    }
LAB_00017578:
    WVar5 = SendDlgItemMessageW(param_1,0x13a8,0x158,0,(int)pvVar9 + 0x79a);
    if (WVar5 == 0xffffffff) {
      WVar5 = 0;
    }
    pHVar6 = GetDlgItem(param_1,0x13a8);
    SendMessageW(pHVar6,0x14e,WVar5,0);
    SetCursor(pHVar2);
    goto LAB_000178ac;
  }
  if (pvVar9 == (LPVOID)0x0) goto LAB_000176cc;
  iVar10 = *(int *)(param_4 + 8);
  if (iVar10 == -0xd0) {
LAB_00017868:
    pHVar6 = GetDlgItem(param_1,0x13a8);
    GetWindowTextW(pHVar6,(LPWSTR)((int)pvVar9 + 0x79a),0x81);
    if (*(int *)(param_4 + 8) == -0xd0) {
LAB_00017894:
      FUN_0001ebc8((int)pvVar9);
    }
  }
  else {
    if (iVar10 == -0xca) goto LAB_00017894;
    if (iVar10 == -0xc9) goto LAB_00017868;
    if (iVar10 == -200) {
      pHVar6 = GetParent(param_1);
      PostMessageW(pHVar6,0x470,0,5);
      pHVar6 = GetDlgItem(param_1,0x138c);
      SetWindowTextW(pHVar6,*(LPCWSTR *)((int)pvVar9 + 4));
    }
  }
  SetWindowLongW(param_1,0,0);
LAB_000178ac:
  FUN_000219a0(local_2c);
  return 1;
}



/* 000178e8 FUN_000178e8 */

/* Boundary evidence: original MIPS .pdata 000178e8..00017933. Semantic name remains unreviewed. */

undefined4 * FUN_000178e8(undefined4 *param_1,uint param_2)

{
  FUN_0001c4a8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00017934 FUN_00017934 */

/* Boundary evidence: original MIPS .pdata 00017934..000179d3. Semantic name remains unreviewed. */

undefined4 FUN_00017934(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 local_40;
  undefined1 auStack_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  code *local_28;
  int local_24;
  
  pcVar2 = *(code **)(param_1 + 0x10);
  if (pcVar2 != (code *)0x0) {
    memset(auStack_3c,0,0x24);
    local_40 = 0x28;
    if (param_2 == 0) {
      local_34 = 0x1007;
      if (DAT_00023448 == 0) {
        local_34 = 0xfa3;
      }
      local_28 = FUN_00017428;
      local_38 = param_3;
      local_24 = param_1;
      uVar1 = (*pcVar2)(&local_40);
      return uVar1;
    }
  }
  return 0;
}



/* 000179d4 FUN_000179d4 */

/* Boundary evidence: original MIPS .pdata 000179d4..00017b53. Semantic name remains unreviewed. */

undefined4 * FUN_000179d4(undefined4 *param_1,wchar_t *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  size_t _MaxCount;
  wchar_t *_Str1;
  uint uVar4;
  wchar_t *_Str;
  void *local_30 [2];
  
  FUN_0001e910(param_1,param_2);
  *param_1 = &PTR_FUN_000117d8;
  param_1[0x36f] = param_3;
  iVar2 = wcscmp((wchar_t *)(param_1 + 0x1de),L"vpn");
  if (iVar2 != 0) {
    local_30[0] = (void *)0x0;
    if (param_3 == 0) {
      _Str = L"RAS VPN Line";
    }
    else {
      _Str = L"L2TP Line";
    }
    uVar3 = FUN_0001d91c(local_30);
    pvVar1 = local_30[0];
    uVar4 = 0;
    if (uVar3 != 0) {
      _Str1 = (wchar_t *)((int)local_30[0] + 4);
      do {
        if (pvVar1 == (void *)0x0) {
          return param_1;
        }
        iVar2 = wcscmp(_Str1,L"vpn");
        if (iVar2 == 0) {
          _MaxCount = wcslen(_Str);
          iVar2 = wcsncmp(_Str1 + 0x11,_Str,_MaxCount);
          if (iVar2 == 0) {
            wcscpy((wchar_t *)((int)param_1 + 0x79a),(wchar_t *)((int)pvVar1 + uVar4 * 0x128 + 0x26)
                  );
            wcscpy((wchar_t *)(param_1 + 0x1de),L"vpn");
            param_1[6] = 0x4c0800;
            if (param_3 == 0) {
              param_1[6] = 0x4c1800;
            }
            break;
          }
        }
        uVar4 = uVar4 + 1;
        _Str1 = _Str1 + 0x94;
      } while (uVar4 < uVar3);
    }
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
  }
  return param_1;
}



/* 00017b54 FUN_00017b54 */

/* Boundary evidence: original MIPS .pdata 00017b54..00017b8b. Semantic name remains unreviewed. */

bool FUN_00017b54(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = wcscmp(param_2,L"VpnConnInfo");
  return iVar1 == 0;
}



/* 00017b98 FUN_00017b98 */

/* Boundary evidence: original MIPS .pdata 00017b98..00017bb7. Semantic name remains unreviewed. */

void FUN_00017b98(undefined4 param_1,HINSTANCE param_2,LPWSTR param_3,int param_4)

{
  LoadStringW(param_2,0x1841,param_3,param_4);
  return;
}



/* 00017bb8 FUN_00017bb8 */

/* Boundary evidence: original MIPS .pdata 00017bb8..00017f63. Semantic name remains unreviewed. */

undefined4 FUN_00017bb8(HWND param_1,int param_2,ushort param_3,int param_4)

{
  LONG LVar1;
  HWND pHVar2;
  LRESULT LVar3;
  int iVar4;
  undefined4 *_Dst;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  size_t sVar9;
  WCHAR *pWVar10;
  undefined4 uVar11;
  WCHAR local_130 [130];
  uint local_2c;
  
  local_2c = DAT_00023314;
  LVar1 = GetWindowLongW(param_1,-0x15);
  iVar7 = 0;
  if (LVar1 != 0) {
    iVar7 = *(int *)(LVar1 + 0x1c);
  }
  if (param_2 != 0x4e) {
    if (param_2 == 0x110) {
      SetWindowLongW(param_1,-0x15,param_4);
      iVar7 = *(int *)(param_4 + 0x1c);
      pHVar2 = GetDlgItem(param_1,0x13bb);
      SendMessageW(pHVar2,0xc5,0x80,0);
      piVar8 = *(int **)(iVar7 + 0xdb4);
      if ((piVar8 == (int *)0x0) || (*(uint *)(iVar7 + 0xdb8) < 0x20)) {
        piVar8 = &DAT_00023330;
      }
      if ((piVar8 != (int *)0x0) && (*piVar8 == 1)) {
        if ((piVar8[1] & 2U) == 0) {
          pHVar2 = GetDlgItem(param_1,0x13b9);
          SendMessageW(pHVar2,0xf1,1,0);
        }
        else {
          pHVar2 = GetDlgItem(param_1,0x13ba);
          SendMessageW(pHVar2,0xf1,1,0);
          pHVar2 = GetDlgItem(param_1,0x13bb);
          EnableWindow(pHVar2,1);
          if ((piVar8[3] != 0) && ((uint)(piVar8[4] + piVar8[3]) <= *(uint *)(iVar7 + 0xdb8))) {
            SetDlgItemTextW(param_1,0x13bb,L"******");
          }
        }
      }
    }
    else if (param_2 == 0x111) {
      if ((0x13b8 < param_3) && (param_3 < 0x13bb)) {
        pHVar2 = GetDlgItem(param_1,0x13ba);
        LVar3 = SendMessageW(pHVar2,0xf0,0,0);
        pHVar2 = GetDlgItem(param_1,0x13bb);
        EnableWindow(pHVar2,(uint)(LVar3 == 1));
      }
      goto LAB_00017f2c;
    }
    goto LAB_00017db4;
  }
  pWVar10 = (WCHAR *)0x0;
  if (*(int *)(param_4 + 8) == -0xca) {
    if (iVar7 == 0) goto LAB_00017db4;
    pHVar2 = GetDlgItem(param_1,0x13ba);
    LVar3 = SendMessageW(pHVar2,0xf0,0,0);
    if (LVar3 == 1) {
      GetDlgItemTextW(param_1,0x13bb,local_130,0x81);
      iVar4 = wcscmp(local_130,L"******");
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar7 + 0xdb4);
        if (iVar4 == 0) {
LAB_00017db4:
          FUN_000219a0(local_2c);
          return 0;
        }
        uVar6 = *(uint *)(iVar4 + 0x10);
        uVar5 = *(uint *)(iVar7 + 0xdb8);
        if (((uVar5 < uVar6) || (sVar9 = *(uint *)(iVar4 + 0xc), uVar5 < sVar9)) ||
           (uVar5 < uVar6 + sVar9)) goto LAB_00017db4;
        pWVar10 = (WCHAR *)(uVar6 + iVar4);
      }
      else {
        pWVar10 = local_130;
        sVar9 = wcslen(local_130);
        sVar9 = sVar9 << 1;
      }
      uVar11 = 2;
    }
    else {
      sVar9 = 0;
      uVar11 = 1;
    }
    _Dst = operator_new(sVar9 + 0x20);
    if (_Dst != (undefined4 *)0x0) {
      memset(_Dst,0,0x20);
      *_Dst = 1;
      _Dst[1] = uVar11;
      _Dst[3] = sVar9;
      _Dst[4] = 0x20;
      if (sVar9 != 0) {
        memcpy(_Dst + 8,pWVar10,sVar9);
      }
      if (*(void **)(iVar7 + 0xdb4) != (void *)0x0) {
        memset(*(void **)(iVar7 + 0xdb4),0,*(size_t *)(iVar7 + 0xdb8));
      }
      operator_delete(*(void **)(iVar7 + 0xdb4));
      *(undefined4 **)(iVar7 + 0xdb4) = _Dst;
      *(size_t *)(iVar7 + 0xdb8) = sVar9 + 0x20;
    }
    iVar7 = 0x102;
    pWVar10 = local_130;
    do {
      *(undefined1 *)pWVar10 = 0;
      iVar7 = iVar7 + -1;
      pWVar10 = (WCHAR *)((int)pWVar10 + 1);
    } while (iVar7 != 0);
  }
LAB_00017f2c:
  FUN_000219a0(local_2c);
  return 1;
}



/* 00017f64 FUN_00017f64 */

/* Boundary evidence: original MIPS .pdata 00017f64..00018233. Semantic name remains unreviewed. */

undefined1 FUN_00017f64(wchar_t *param_1)

{
  wchar_t wVar1;
  undefined1 uVar2;
  int iVar3;
  size_t sVar4;
  wchar_t *pwVar5;
  LSTATUS LVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  int local_458;
  HKEY local_454;
  DWORD local_450 [2];
  undefined4 local_448;
  undefined4 local_444;
  CHAR aCStack_428 [1028];
  uint local_24;
  
  local_24 = DAT_00023314;
  if (param_1 == (wchar_t *)0x0) {
    FUN_000219a0(DAT_00023314);
    return 0;
  }
  iVar3 = WideCharToMultiByte(0,0,param_1,-1,aCStack_428,0x401,(LPCSTR)0x0,(LPBOOL)0x0);
  if (iVar3 != 0) {
    memset(&local_448,0,0x20);
    local_444 = 0;
    local_448 = 4;
    iVar3 = getaddrinfo(aCStack_428,&DAT_00011834,&local_448,&local_458);
    freeaddrinfo(local_458);
    uVar2 = 1;
    if (iVar3 == 0) goto LAB_00018204;
  }
  sVar4 = wcslen(param_1);
  pwVar7 = param_1;
  pwVar8 = param_1;
  if (sVar4 < 0x10) {
    do {
      wVar1 = *pwVar8;
      pwVar8 = pwVar8 + 1;
      if (wVar1 == L'\0') goto LAB_0001809c;
      iVar3 = iswctype(wVar1,0x10f);
    } while ((iVar3 != 0) || (pwVar5 = wcschr(L"!@#$%^&\')(.-_{}~",wVar1), pwVar5 != (wchar_t *)0x0)
            );
    if (wVar1 != L'\0') goto LAB_000180a8;
  }
  else {
LAB_000180a8:
    do {
      wVar1 = *pwVar7;
      pwVar7 = pwVar7 + 1;
      if (wVar1 == L'\0') break;
    } while ((((0x60 < (ushort)wVar1) && ((ushort)wVar1 < 0x7b)) ||
             ((0x40 < (ushort)wVar1 && ((ushort)wVar1 < 0x5b)))) ||
            ((((0x2f < (ushort)wVar1 && ((ushort)wVar1 < 0x3a)) || (wVar1 == L'-')) ||
             ((wVar1 == L'.' || (wVar1 == L'_'))))));
    if (wVar1 != L'\0') {
      uVar2 = 0;
      local_454 = (HKEY)0x0;
      local_458 = 0;
      local_450[0] = 4;
      LVar6 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\TCPIP\\Parms",0,0x20019,&local_454);
      if (LVar6 == 0) {
        RegQueryValueExW(local_454,L"VPNStrictDNSNamesOnly",(LPDWORD)0x0,(LPDWORD)0x0,
                         (LPBYTE)&local_458,local_450);
      }
      if (local_454 != (HKEY)0x0) {
        RegCloseKey(local_454);
      }
      if ((local_458 == 0) &&
         ((iVar3 = WideCharToMultiByte(0xfde9,0,param_1,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0),
          iVar3 < 1 || (uVar2 = 1, 0xff < iVar3)))) {
        uVar2 = 0;
      }
      goto LAB_00018204;
    }
  }
LAB_0001809c:
  uVar2 = 1;
LAB_00018204:
  FUN_000219a0(local_24);
  return uVar2;
}



/* 00018234 FUN_00018234 */

/* Boundary evidence: original MIPS .pdata 00018234..0001827f. Semantic name remains unreviewed. */

undefined4 * FUN_00018234(undefined4 *param_1,uint param_2)

{
  FUN_0001c4a8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00018280 FUN_00018280 */

/* Boundary evidence: original MIPS .pdata 00018280..00018387. Semantic name remains unreviewed. */

undefined4 FUN_00018280(undefined4 param_1,undefined4 param_2,HINSTANCE param_3)

{
  undefined4 uVar1;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  HINSTANCE local_9c;
  WCHAR *local_94;
  undefined4 local_90;
  undefined4 *local_88;
  undefined4 local_80;
  undefined1 auStack_7c [4];
  HINSTANCE local_78;
  undefined4 local_74;
  code *local_68;
  undefined4 local_64;
  WCHAR aWStack_58 [30];
  uint local_1c;
  
  local_1c = DAT_00023314;
  memset(auStack_7c,0,0x24);
  local_a8 = 0;
  memset(&local_a4,0,0x24);
  local_80 = 0x28;
  local_74 = 0x100e;
  if (DAT_00023448 == 0) {
    local_74 = 0xfaa;
  }
  local_68 = FUN_00017bb8;
  local_78 = param_3;
  local_64 = param_1;
  LoadStringW(param_3,0x1846,aWStack_58,0x1e);
  local_a4 = 8;
  local_94 = aWStack_58;
  local_88 = &local_80;
  local_a8 = 0x28;
  local_90 = 1;
  local_a0 = param_2;
  local_9c = param_3;
  uVar1 = (*DAT_00023438)(&local_a8);
  FUN_000219a0(local_1c);
  return uVar1;
}



/* 00018388 FUN_00018388 */

/* Boundary evidence: original MIPS .pdata 00018388..00018683. Semantic name remains unreviewed. */

undefined4 FUN_00018388(HWND param_1,int param_2,short param_3,int param_4)

{
  undefined1 uVar1;
  LONG LVar2;
  HWND pHVar3;
  undefined3 extraout_var;
  LPARAM lParam;
  int iVar4;
  int iVar5;
  
  LVar2 = GetWindowLongW(param_1,-0x15);
  iVar5 = 0;
  if (LVar2 != 0) {
    iVar5 = *(int *)(LVar2 + 0x1c);
  }
  if (param_2 != 0x4e) {
    if (param_2 == 0x110) {
      SetWindowLongW(param_1,-0x15,param_4);
      iVar5 = *(int *)(param_4 + 0x1c);
      pHVar3 = GetDlgItem(param_1,0x1396);
      SendMessageW(pHVar3,0xc5,0x80,0);
      SetDlgItemTextW(param_1,0x1396,(LPCWSTR)(iVar5 + 0x3a));
      pHVar3 = GetDlgItem(param_1,0x1396);
      SetFocus(pHVar3);
      pHVar3 = GetDlgItem(param_1,0x138e);
      EnableWindow(pHVar3,*(BOOL *)(iVar5 + 0xdbc));
    }
    else if (param_2 == 0x111) {
      if (iVar5 == 0) {
        return 1;
      }
      if (param_3 == 0x138e) {
        FUN_00018280(iVar5,param_1,*(HINSTANCE *)(LVar2 + 8));
        return 1;
      }
      if (param_3 == 0x138f) {
        FUN_0001f664(iVar5,param_1,*(HINSTANCE *)(LVar2 + 8));
        return 1;
      }
      if (param_3 != 0x13aa) {
        return 1;
      }
      FUN_0001f798(iVar5,param_1,*(HINSTANCE *)(LVar2 + 8));
      return 1;
    }
    return 0;
  }
  if (iVar5 == 0) {
    return 1;
  }
  iVar4 = *(int *)(param_4 + 8);
  LVar2 = 0;
  if (iVar4 == -0xd0) {
LAB_00018570:
    GetDlgItemTextW(param_1,0x1396,(LPWSTR)(iVar5 + 0x3a),0x81);
    if (*(int *)(param_4 + 8) != -0xd0) goto LAB_0001864c;
  }
  else if (iVar4 != -0xca) {
    if (iVar4 != -0xc9) {
      if (iVar4 == -200) {
        pHVar3 = GetParent(param_1);
        PostMessageW(pHVar3,0x470,0,5);
        pHVar3 = GetDlgItem(param_1,0x138c);
        SetWindowTextW(pHVar3,*(LPCWSTR *)(iVar5 + 4));
      }
      goto LAB_0001864c;
    }
    goto LAB_00018570;
  }
  if (*(wchar_t *)(iVar5 + 0x3a) == L'\0') {
    pHVar3 = GetParent(param_1);
    EnableWindow(pHVar3,0);
    pHVar3 = GetParent(param_1);
    pHVar3 = GetParent(pHVar3);
    lParam = 0x190f;
  }
  else {
    uVar1 = FUN_00017f64((wchar_t *)(iVar5 + 0x3a));
    if (CONCAT31(extraout_var,uVar1) != 0) {
      FUN_0001ebc8(iVar5);
      goto LAB_0001864c;
    }
    pHVar3 = GetParent(param_1);
    EnableWindow(pHVar3,0);
    pHVar3 = GetParent(param_1);
    pHVar3 = GetParent(pHVar3);
    lParam = 0x1910;
  }
  SendMessageW(pHVar3,0x401,0,lParam);
  pHVar3 = GetParent(param_1);
  EnableWindow(pHVar3,1);
  pHVar3 = GetDlgItem(param_1,0x1396);
  SetFocus(pHVar3);
  LVar2 = 1;
LAB_0001864c:
  SetWindowLongW(param_1,0,LVar2);
  return 1;
}



/* 00018684 FUN_00018684 */

/* Boundary evidence: original MIPS .pdata 00018684..00018723. Semantic name remains unreviewed. */

undefined4 FUN_00018684(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 local_40;
  undefined1 auStack_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  code *local_28;
  int local_24;
  
  pcVar2 = *(code **)(param_1 + 0x10);
  if (pcVar2 != (code *)0x0) {
    memset(auStack_3c,0,0x24);
    local_40 = 0x28;
    if (param_2 == 0) {
      local_34 = 0x1008;
      if (DAT_00023448 == 0) {
        local_34 = 0xfa4;
      }
      local_28 = FUN_00018388;
      local_38 = param_3;
      local_24 = param_1;
      uVar1 = (*pcVar2)(&local_40);
      return uVar1;
    }
  }
  return 0;
}



/* 00018724 FUN_00018724 */

/* Boundary evidence: original MIPS .pdata 00018724..0001879b. Semantic name remains unreviewed. */

bool FUN_00018724(void)

{
  HANDLE hHandle;
  
  hHandle = OpenEventW(0x1f0003,0,L"SYSTEM/GweApiSetReady");
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  return hHandle != (HANDLE)0x0;
}



/* 0001879c FUN_0001879c */

/* Boundary evidence: original MIPS .pdata 0001879c..00018837. Semantic name remains unreviewed. */

int FUN_0001879c(undefined4 *param_1,undefined4 param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  HMODULE pHVar2;
  int iVar3;
  
  bVar1 = FUN_00018724();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    pHVar2 = LoadLibraryW(L"netui.dll");
    *param_1 = pHVar2;
    if (pHVar2 != (HMODULE)0x0) {
      iVar3 = GetProcAddressW(pHVar2,param_2);
      if (iVar3 != 0) {
        return iVar3;
      }
      SetLastError(2);
      return 0;
    }
    SetLastError(3);
  }
  return 0;
}



/* 00018838 FUN_00018838 */

/* Boundary evidence: original MIPS .pdata 00018838..000188bb. Semantic name remains unreviewed. */

undefined4 FUN_00018838(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  HMODULE local_18 [2];
  
  local_18[0] = (HMODULE)0x0;
  uVar2 = 0;
  pcVar1 = (code *)FUN_0001879c(local_18,L"AdapterIPProperties");
  if (pcVar1 != (code *)0x0) {
    uVar2 = (*pcVar1)(param_1,param_2);
  }
  if (local_18[0] != (HMODULE)0x0) {
    FreeLibrary(local_18[0]);
  }
  return uVar2;
}



/* 000188bc FUN_000188bc */

/* Boundary evidence: original MIPS .pdata 000188bc..00018977. Semantic name remains unreviewed. */

undefined4 FUN_000188bc(undefined4 param_1,undefined4 param_2)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"WaitForAPIReady");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* 00018978 FUN_00018978 */

/* Boundary evidence: original MIPS .pdata 00018978..00018a67. Semantic name remains unreviewed. */

undefined4
FUN_00018978(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"CeCallUserProc");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 00018a68 FUN_00018a68 */

/* Boundary evidence: original MIPS .pdata 00018a68..00018b57. Semantic name remains unreviewed. */

int FUN_00018a68(wchar_t *param_1)

{
  size_t sVar1;
  int *hMem;
  int iVar2;
  int iVar3;
  SIZE_T uBytes;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  iVar3 = 0;
  sVar1 = wcslen(param_1);
  sVar1 = (sVar1 + 1) * 2;
  uBytes = sVar1 + 0xc;
  hMem = LocalAlloc(0x40,uBytes);
  if (hMem == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    *hMem = 0;
    memcpy(hMem + 2,param_1,sVar1);
    hMem[1] = 0;
    iVar2 = FUN_00018978(L"netui.dll",L"LoadLibraryExt",hMem,uBytes,hMem,uBytes,local_20);
    if ((iVar2 != 0) && (iVar3 = *hMem, iVar3 == 0)) {
      SetLastError(hMem[1]);
    }
    LocalFree(hMem);
  }
  return iVar3;
}



/* 00018b58 FUN_00018b58 */

/* Boundary evidence: original MIPS .pdata 00018b58..00018bdf. Semantic name remains unreviewed. */

int FUN_00018b58(undefined4 param_1)

{
  int iVar1;
  undefined4 local_20 [2];
  int local_18;
  DWORD local_14;
  undefined4 local_10;
  
  local_20[0] = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = param_1;
  iVar1 = FUN_00018978(L"netui.dll",L"FreeLibraryExt",&local_18,0xc,&local_18,0xc,local_20);
  if (iVar1 == 0) {
    local_18 = 0;
  }
  else if (local_18 == 0) {
    SetLastError(local_14);
  }
  return local_18;
}



/* 00018be0 FUN_00018be0 */

/* Boundary evidence: original MIPS .pdata 00018be0..00018d2b. Semantic name remains unreviewed. */

int FUN_00018be0(int param_1,wchar_t *param_2)

{
  int iVar1;
  size_t sVar2;
  int *hMem;
  DWORD dwErrCode;
  int iVar3;
  SIZE_T uBytes;
  undefined4 local_28 [2];
  
  local_28[0] = 0;
  iVar3 = 0;
  if (param_2 == (wchar_t *)0x0) {
    SetLastError(0x57);
    return 0;
  }
  iVar1 = FUN_000188bc(0x51,60000);
  if (iVar1 != 0) {
    return 0;
  }
  sVar2 = wcslen(param_2);
  uBytes = sVar2 * 2 + 0xc;
  hMem = LocalAlloc(0x40,uBytes);
  if (hMem == (int *)0x0) {
    return 0;
  }
  *hMem = 0;
  hMem[1] = param_1;
  memcpy(hMem + 3,param_2,sVar2 * 2);
  hMem[2] = 0;
  iVar1 = FUN_00018a68(L"netui.dll");
  if (iVar1 == 0) {
    dwErrCode = 3;
  }
  else {
    FUN_00018b58(iVar1);
    iVar1 = FUN_00018978(L"netui.dll",L"AdapterIPPropertiesExt",hMem,uBytes,hMem,uBytes,local_28);
    if ((iVar1 == 0) || (iVar3 = *hMem, iVar3 != 0)) goto LAB_00018cfc;
    dwErrCode = hMem[2];
  }
  SetLastError(dwErrCode);
LAB_00018cfc:
  LocalFree(hMem);
  return iVar3;
}



/* 00018d2c FUN_00018d2c */

/* Boundary evidence: original MIPS .pdata 00018d2c..00018d9b. Semantic name remains unreviewed. */

undefined4 FUN_00018d2c(void)

{
  HMODULE hLibModule;
  int iVar1;
  undefined4 uVar2;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if ((hLibModule == (HMODULE)0x0) ||
     (iVar1 = GetProcAddressW(hLibModule,L"CeCallUserProc"), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    FreeLibrary(hLibModule);
    uVar2 = 1;
  }
  return uVar2;
}



/* 00018d9c FUN_00018d9c */

/* WARNING: Removing unreachable block (ram,0x00018dc8) */
/* WARNING: Removing unreachable block (ram,0x00018dec) */
/* WARNING: Removing unreachable block (ram,0x00018dd8) */
/* Boundary evidence: original MIPS .pdata 00018d9c..00018e13. Semantic name remains unreviewed. */

int FUN_00018d9c(int param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00018838(param_1,param_2);
  return iVar1;
}



/* 00018e14 FUN_00018e14 */

/* Boundary evidence: original MIPS .pdata 00018e14..00018e57. Semantic name remains unreviewed. */

void FUN_00018e14(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000119c4;
  if ((void *)param_1[5] != (void *)0x0) {
    operator_delete((void *)param_1[5]);
  }
  FUN_00020e58(param_1);
  return;
}



/* 00018e60 FUN_00018e60 */

/* Boundary evidence: original MIPS .pdata 00018e60..00018e97. Semantic name remains unreviewed. */

bool FUN_00018e60(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = wcscmp(param_2,L"LanConnInfo");
  return iVar1 == 0;
}



/* 00018ea0 FUN_00018ea0 */

/* Boundary evidence: original MIPS .pdata 00018ea0..00018ef7. Semantic name remains unreviewed. */

undefined4 FUN_00018ea0(int param_1,HINSTANCE param_2,LPWSTR param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  UINT uID;
  
  if (param_3 == (LPWSTR)0x0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x1900;
    }
    uVar1 = 0;
  }
  else {
    uID = 0x189d;
    if (*(int *)(param_1 + 0x18) == 0) {
      uID = 0x189c;
    }
    LoadStringW(param_2,uID,param_3,0x80);
    uVar1 = 1;
  }
  return uVar1;
}



/* 00018ef8 FUN_00018ef8 */

/* Boundary evidence: original MIPS .pdata 00018ef8..00018fbf. Semantic name remains unreviewed. */

undefined4
FUN_00018ef8(int param_1,int param_2,HINSTANCE param_3,STRSAFE_LPWSTR param_4,size_t param_5,
            undefined4 *param_6)

{
  UINT uID;
  STRSAFE_LPCWSTR pszSrc;
  
  if ((param_4 == (STRSAFE_LPWSTR)0x0) ||
     (pszSrc = *(STRSAFE_LPCWSTR *)(param_1 + 4), pszSrc == (STRSAFE_LPCWSTR)0x0)) {
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 0x1900;
    }
    return 0;
  }
  if (param_2 != 0) {
    if (param_2 == 1) {
      uID = 0x18a0;
    }
    else {
      if (param_2 != 2) {
        if (param_2 != 3) {
          *param_4 = L'\0';
          return 1;
        }
        pszSrc = *(STRSAFE_LPCWSTR *)(param_1 + 0x14);
        goto LAB_00018f50;
      }
      uID = 0x189e;
      if (*(int *)(param_1 + 0x18) == 0) {
        uID = 0x189f;
      }
    }
    LoadStringW(param_3,uID,param_4,param_5);
    return 1;
  }
LAB_00018f50:
  StringCchCopyW(param_4,param_5,pszSrc);
  return 1;
}



/* 00018fc0 FUN_00018fc0 */

/* Boundary evidence: original MIPS .pdata 00018fc0..000190b7. Semantic name remains unreviewed. */

BOOL FUN_00018fc0(DWORD param_1,LPVOID param_2,DWORD param_3,LPVOID param_4,LPDWORD param_5)

{
  HANDLE hDevice;
  DWORD nOutBufferSize;
  BOOL BVar1;
  
  BVar1 = 0;
  hDevice = CreateFileW(L"NDS0:",0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,4,0,(HANDLE)0x0);
  if (hDevice != (HANDLE)0xffffffff) {
    if (param_5 == (LPDWORD)0x0) {
      nOutBufferSize = 0;
    }
    else {
      nOutBufferSize = *param_5;
    }
    BVar1 = DeviceIoControl(hDevice,param_1,param_2,param_3,param_4,nOutBufferSize,param_5,
                            (LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  return BVar1;
}



/* 000190b8 FUN_000190b8 */

/* Boundary evidence: original MIPS .pdata 000190b8..000192ef. Semantic name remains unreviewed. */

undefined4 FUN_000190b8(int param_1)

{
  HKEY pHVar1;
  code *pcVar2;
  int iVar3;
  code *pcVar4;
  LSTATUS LVar5;
  undefined4 uVar6;
  HKEY local_80;
  undefined4 local_7c;
  DWORD local_78 [2];
  undefined4 local_70;
  undefined1 auStack_6c [84];
  
  uVar6 = 0;
  if (*(int *)(param_1 + 0x14) == 0) {
LAB_000190e4:
    uVar6 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x18) == 0) {
      local_80 = (HKEY)0x0;
      LVar5 = RegOpenKeyExW((HKEY)0x80000001,L"Comm\\WirelessAdapterCache",0,0x20019,&local_80);
      if (LVar5 != 0) {
        return 0;
      }
      local_78[0] = 4;
      local_7c = 0;
      LVar5 = RegQueryValueExW(local_80,*(LPCWSTR *)(param_1 + 0x14),(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)&local_7c,local_78);
      pHVar1 = local_80;
      pcVar4 = RegCloseKey_exref;
      if (LVar5 == 0) {
        uVar6 = local_7c;
      }
    }
    else {
      pHVar1 = (HKEY)LoadLibraryW(L"wzcsapi.dll");
      if (pHVar1 == (HKEY)0x0) goto LAB_000190e4;
      pcVar2 = (code *)GetProcAddressW(pHVar1,L"WZCQueryInterface");
      pcVar4 = FreeLibrary_exref;
      if (pcVar2 != (code *)0x0) {
        memset(auStack_6c,0,0x54);
        local_70 = *(undefined4 *)(param_1 + 0x14);
        local_7c = 0;
        iVar3 = (*pcVar2)(0,0x7fffffff,&local_70,&local_7c);
        pcVar4 = FreeLibrary_exref;
        if (iVar3 == 0) {
          pcVar4 = (code *)GetProcAddressW(pHVar1,L"WZCDeleteIntfObj");
          if (pcVar4 != (code *)0x0) {
            (*pcVar4)(&local_70);
          }
          uVar6 = 1;
          local_80 = (HKEY)0x0;
          LVar5 = RegCreateKeyExW((HKEY)0x80000001,L"Comm\\WirelessAdapterCache",0,(LPWSTR)0x0,0,
                                  0x20006,(LPSECURITY_ATTRIBUTES)0x0,&local_80,(LPDWORD)0x0);
          pcVar4 = FreeLibrary_exref;
          if (LVar5 == 0) {
            local_78[0] = 1;
            RegSetValueExW(local_80,*(LPCWSTR *)(param_1 + 0x14),0,4,(BYTE *)local_78,4);
            RegCloseKey(local_80);
            pcVar4 = FreeLibrary_exref;
          }
        }
      }
    }
    (*pcVar4)(pHVar1);
  }
  return uVar6;
}



/* 000192f0 FUN_000192f0 */

/* Boundary evidence: original MIPS .pdata 000192f0..0001945f. Semantic name remains unreviewed. */

undefined4 FUN_000192f0(int param_1)

{
  LSTATUS LVar1;
  int iVar2;
  size_t sVar3;
  wchar_t *_Dest;
  uint uVar4;
  HKEY local_118;
  DWORD local_114;
  wchar_t local_110;
  undefined1 auStack_10e [254];
  uint local_10;
  
  local_10 = DAT_00023314;
  local_118 = (HKEY)0x0;
  local_110 = L'\0';
  memset(auStack_10e,0,0xfe);
  local_114 = 0x80;
  if ((*(int *)(param_1 + 0x14) != 0) &&
     (LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"Comm\\AdapterNameMappings",0,0x20019,&local_118),
     LVar1 == 0)) {
    LVar1 = RegQueryValueExW(local_118,*(LPCWSTR *)(param_1 + 0x14),(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPBYTE)&local_110,&local_114);
    if (LVar1 == 0) {
      RegCloseKey(local_118);
      iVar2 = FUN_00020eb0(&local_110);
      if (iVar2 != 0) {
        if (*(void **)(param_1 + 4) != (void *)0x0) {
          operator_delete(*(void **)(param_1 + 4));
        }
        sVar3 = wcslen(&local_110);
        if (sVar3 + 1 < 0x80000000) {
          uVar4 = (sVar3 + 1) * 2;
        }
        else {
          uVar4 = 0xffffffff;
        }
        _Dest = operator_new(uVar4);
        *(wchar_t **)(param_1 + 4) = _Dest;
        if (_Dest != (wchar_t *)0x0) {
          wcscpy(_Dest,&local_110);
          FUN_000219a0(local_10);
          return 1;
        }
      }
    }
    else {
      RegCloseKey(local_118);
    }
  }
  FUN_000219a0(local_10);
  return 0;
}



/* 00019460 FUN_00019460 */

/* Boundary evidence: original MIPS .pdata 00019460..00019587. Semantic name remains unreviewed. */

undefined4 FUN_00019460(int param_1)

{
  int iVar1;
  LSTATUS LVar2;
  size_t sVar3;
  wchar_t *_Str;
  HKEY local_18 [2];
  
  local_18[0] = (HKEY)0x0;
  if ((((*(int *)(param_1 + 0x14) != 0) && (*(wchar_t **)(param_1 + 4) != (wchar_t *)0x0)) &&
      (iVar1 = FUN_00020eb0(*(wchar_t **)(param_1 + 4)), iVar1 != 0)) &&
     (LVar2 = RegCreateKeyExW((HKEY)0x80000001,L"Comm\\AdapterNameMappings",0,(LPWSTR)0x0,0,0x20006,
                              (LPSECURITY_ATTRIBUTES)0x0,local_18,(LPDWORD)0x0), LVar2 == 0)) {
    _Str = *(wchar_t **)(param_1 + 4);
    sVar3 = wcslen(_Str);
    LVar2 = RegSetValueExW(local_18[0],*(LPCWSTR *)(param_1 + 0x14),0,1,(BYTE *)_Str,(sVar3 + 1) * 2
                          );
    if (LVar2 == 0) {
      SendMessageW((HWND)0xffff,0x1a,0,0x11a8c);
      RegCloseKey(local_18[0]);
      return 1;
    }
    RegCloseKey(local_18[0]);
  }
  return 0;
}



/* 00019588 FUN_00019588 */

/* Boundary evidence: original MIPS .pdata 00019588..0001966b. Semantic name remains unreviewed. */

uint FUN_00019588(uint param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint local_18 [2];
  
  local_18[0] = 0;
  uVar5 = 0xffffffff;
  iVar1 = GetIpAddrTable(0,local_18,0);
  if (((iVar1 == 0x7a) || (iVar1 == 0x6f)) &&
     (puVar2 = operator_new(local_18[0]), puVar2 != (uint *)0x0)) {
    iVar1 = GetIpAddrTable(puVar2,local_18,0);
    if (iVar1 == 0) {
      uVar4 = 0;
      if (*puVar2 != 0) {
        puVar3 = puVar2 + 2;
        do {
          if (*puVar3 == param_1) {
            uVar5 = puVar2[uVar4 * 6 + 1];
            break;
          }
          uVar4 = uVar4 + 1;
          puVar3 = puVar3 + 6;
        } while (uVar4 < *puVar2);
      }
    }
    operator_delete(puVar2);
  }
  return uVar5;
}



/* 0001966c FUN_0001966c */

/* Boundary evidence: original MIPS .pdata 0001966c..00019793. Semantic name remains unreviewed. */

undefined4 FUN_0001966c(int param_1,void *param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint local_28 [2];
  
  local_28[0] = 0;
  uVar6 = 0;
  iVar1 = GetIpForwardTable(0,local_28,0);
  if (((iVar1 == 0x7a) || (iVar1 == 0x6f)) &&
     (puVar2 = operator_new(local_28[0]), puVar2 != (uint *)0x0)) {
    iVar1 = GetIpForwardTable(puVar2,local_28,0);
    if ((iVar1 == 0) && (uVar5 = 0, *puVar2 != 0)) {
      puVar4 = puVar2 + 4;
      do {
        uVar3 = FUN_00019588(puVar4[1]);
        if ((uVar3 == *(uint *)(param_1 + 0x24)) && (*puVar4 == *(uint *)(param_1 + 0x28))) {
          memcpy(param_2,puVar2 + uVar5 * 0xe + 1,0x38);
          uVar6 = 1;
          break;
        }
        uVar5 = uVar5 + 1;
        puVar4 = puVar4 + 0xe;
      } while (uVar5 < *puVar2);
    }
    operator_delete(puVar2);
  }
  return uVar6;
}



/* 00019794 FUN_00019794 */

/* Boundary evidence: original MIPS .pdata 00019794..000198b3. Semantic name remains unreviewed. */

undefined4 FUN_00019794(int param_1)

{
  int iVar1;
  LSTATUS LVar2;
  undefined4 local_268;
  HKEY local_264;
  DWORD local_260 [2];
  undefined1 auStack_258 [4];
  undefined1 auStack_254 [32];
  undefined4 local_234;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_00023314;
  memset(auStack_254,0,0x34);
  local_268 = 0xffffffff;
  iVar1 = FUN_0001966c(param_1,auStack_258);
  if (iVar1 == 0) {
    local_264 = (HKEY)0x0;
    StringCchPrintfW(awStack_220,0x104,L"Comm\\%s\\Parms\\TCPIP",*(undefined4 *)(param_1 + 0x14));
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,awStack_220,0,0x20019,&local_264);
    local_234 = local_268;
    if (LVar2 == 0) {
      local_260[0] = 4;
      LVar2 = RegQueryValueExW(local_264,L"InterfaceMetric",(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)&local_268,local_260);
      if (LVar2 != 0) {
        local_268 = 0xffffffff;
      }
      RegCloseKey(local_264);
      local_234 = local_268;
    }
  }
  FUN_000219a0(local_18);
  return local_234;
}



/* 000198b4 FUN_000198b4 */

/* Boundary evidence: original MIPS .pdata 000198b4..000199ef. Semantic name remains unreviewed. */

bool FUN_000198b4(int param_1,undefined4 param_2)

{
  int iVar1;
  LSTATUS LVar2;
  int iVar3;
  undefined4 local_res4 [3];
  HKEY local_260 [2];
  undefined4 local_258;
  undefined1 auStack_254 [32];
  undefined4 local_234;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_00023314;
  local_258 = 0;
  local_res4[0] = param_2;
  memset(auStack_254,0,0x34);
  iVar3 = 0;
  iVar1 = FUN_0001966c(param_1,&local_258);
  if (iVar1 != 0) {
    local_234 = local_res4[0];
    iVar3 = SetIpForwardEntry(&local_258);
  }
  local_260[0] = (HKEY)0x0;
  StringCchPrintfW(awStack_220,0x104,L"Comm\\%s\\Parms\\TCPIP",*(undefined4 *)(param_1 + 0x14));
  LVar2 = RegCreateKeyExW((HKEY)0x80000002,awStack_220,0,(LPWSTR)0x0,0,0x20006,
                          (LPSECURITY_ATTRIBUTES)0x0,local_260,(LPDWORD)0x0);
  if (LVar2 == 0) {
    RegSetValueExW(local_260[0],L"InterfaceMetric",0,4,(BYTE *)local_res4,4);
    RegCloseKey(local_260[0]);
  }
  FUN_000219a0(local_18);
  return iVar3 == 0;
}



/* 000199f0 FUN_000199f0 */

/* Boundary evidence: original MIPS .pdata 000199f0..00019b2b. Semantic name remains unreviewed. */

undefined4 FUN_000199f0(int param_1)

{
  HANDLE hDevice;
  BOOL BVar1;
  undefined4 uVar2;
  DWORD aDStack_20 [2];
  undefined4 local_18;
  int local_14;
  
  hDevice = CreateFileW(L"NPW1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff);
  if (hDevice == (HANDLE)0xffffffff) {
    local_14 = 0;
  }
  else {
    local_18 = *(undefined4 *)(param_1 + 0x14);
    BVar1 = DeviceIoControl(hDevice,0x120804,(LPVOID)0x0,0,&local_18,8,aDStack_20,(LPOVERLAPPED)0x0)
    ;
    if (BVar1 == 0) {
      local_14 = 0;
    }
    CloseHandle(hDevice);
  }
  if ((*(int *)(param_1 + 0x18) == 0) || (local_14 != 0)) {
    uVar2 = DAT_00023354;
    if (*(int *)(param_1 + 0x20) != 0) {
      uVar2 = DAT_0002335c;
    }
  }
  else {
    uVar2 = DAT_00023350;
    if (*(int *)(param_1 + 0x20) != 0) {
      uVar2 = DAT_00023358;
    }
  }
  return uVar2;
}



/* 00019b2c FUN_00019b2c */

/* Boundary evidence: original MIPS .pdata 00019b2c..00019c5b. Semantic name remains unreviewed. */

undefined4 FUN_00019b2c(int param_1)

{
  HANDLE hDevice;
  BOOL BVar1;
  undefined4 uVar2;
  DWORD local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  
  local_1c = DAT_00023314;
  local_30[0] = 0;
  hDevice = CreateFileW(L"UIO1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff);
  uVar2 = 0;
  if (hDevice != (HANDLE)0xffffffff) {
    memset(&local_28,0,0xc);
    local_24 = *(undefined4 *)(param_1 + 0x14);
    local_28 = 0x10202;
    BVar1 = DeviceIoControl(hDevice,0x120804,&local_28,0xc,&local_28,0xc,local_30,(LPOVERLAPPED)0x0)
    ;
    uVar2 = local_20;
    if (BVar1 == 0) {
      GetLastError();
      uVar2 = 0;
    }
    CloseHandle(hDevice);
  }
  FUN_000219a0(local_1c);
  return uVar2;
}



/* 00019c5c FUN_00019c5c */

/* Boundary evidence: original MIPS .pdata 00019c5c..00019d6f. Semantic name remains unreviewed. */

DWORD FUN_00019c5c(wchar_t *param_1,undefined4 *param_2)

{
  DWORD DVar1;
  int iVar2;
  tagRASDEVINFOW *hMem;
  WCHAR *_Str1;
  undefined4 uVar3;
  uint uVar4;
  DWORD local_28;
  DWORD local_24;
  
  local_28 = 0;
  local_24 = 0x128;
  uVar3 = 0;
  hMem = (tagRASDEVINFOW *)0x0;
  do {
    LocalFree(hMem);
    hMem = LocalAlloc(0x40,local_24);
    if (hMem == (tagRASDEVINFOW *)0x0) {
      DVar1 = 8;
      break;
    }
    hMem->dwSize = 0x128;
    DVar1 = RasEnumDevicesW(hMem,&local_24,&local_28);
  } while (DVar1 == 0x25b);
  if ((DVar1 == 0) && (uVar4 = 0, local_28 != 0)) {
    _Str1 = hMem->szDeviceName;
    do {
      iVar2 = _wcsicmp(_Str1,param_1);
      if (iVar2 == 0) {
        uVar3 = 1;
        break;
      }
      uVar4 = uVar4 + 1;
      _Str1 = _Str1 + 0x94;
    } while (uVar4 < local_28);
  }
  LocalFree(hMem);
  *param_2 = uVar3;
  return DVar1;
}



/* 00019d70 FUN_00019d70 */

/* Boundary evidence: original MIPS .pdata 00019d70..0001a09f. Semantic name remains unreviewed. */

undefined4 * FUN_00019d70(undefined4 *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  size_t sVar2;
  BOOL BVar3;
  int iVar4;
  wchar_t *pwVar5;
  undefined4 *puVar6;
  ulong uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  uint local_740;
  int local_73c;
  DWORD local_738 [2];
  char acStack_730 [256];
  wchar_t awStack_630 [259];
  undefined2 local_42a;
  wchar_t local_428;
  undefined1 auStack_426 [1022];
  uint local_28;
  
  local_28 = DAT_00023314;
  FUN_00020d9c(param_1);
  *param_1 = &PTR_FUN_000119c4;
  param_1[6] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  if (param_2 != (wchar_t *)0x0) {
    local_428 = L'\0';
    memset(auStack_426,0,0x3fe);
    local_738[0] = 0x400;
    sVar2 = wcslen(param_2);
    BVar3 = FUN_00018fc0(0x170042,param_2,(sVar2 + 1) * 2,&local_428,local_738);
    uVar10 = 1;
    if (BVar3 != 0) {
      pwVar5 = &local_428;
      wVar1 = local_428;
      while (wVar1 != L'\0') {
        iVar4 = _wcsicmp(pwVar5,L"TCPIP");
        if ((iVar4 == 0) || (iVar4 = _wcsicmp(pwVar5,L"MSTCP"), iVar4 == 0)) {
          param_1[6] = 1;
          break;
        }
        sVar2 = wcslen(pwVar5);
        pwVar5 = pwVar5 + sVar2 + 1;
        wVar1 = *pwVar5;
      }
    }
    sVar2 = wcslen(param_2);
    uVar8 = (sVar2 + 1) * 2;
    if (0x7fffffff < sVar2 + 1) {
      uVar8 = 0xffffffff;
    }
    pwVar5 = operator_new(uVar8);
    param_1[5] = pwVar5;
    if (pwVar5 != (wchar_t *)0x0) {
      wcscpy(pwVar5,param_2);
      iVar4 = FUN_000192f0((int)param_1);
      if (iVar4 == 0) {
        sVar2 = wcslen((wchar_t *)param_1[5]);
        uVar8 = (sVar2 + 1) * 2;
        if (0x7fffffff < sVar2 + 1) {
          uVar8 = 0xffffffff;
        }
        pwVar5 = operator_new(uVar8);
        param_1[1] = pwVar5;
        if (pwVar5 != (wchar_t *)0x0) {
          wcscpy(pwVar5,(wchar_t *)param_1[5]);
          for (pwVar5 = wcschr((wchar_t *)param_1[1],L'\\'); pwVar5 != (wchar_t *)0x0;
              pwVar5 = wcsrchr(pwVar5,L'\\')) {
            *pwVar5 = L'-';
          }
        }
      }
      local_73c = -1;
      iVar4 = _snwprintf(awStack_630,0x103,L"%s\\%s",L"{98C5250D-C29A-4985-AE5F-AFE5367E5006}",
                         param_1[5]);
      local_42a = 0;
      if (iVar4 != -1) {
        GetDevicePower(awStack_630,1,&local_73c);
      }
      if ((local_73c < 0) || (4 < local_73c)) {
        uVar10 = 0;
      }
      param_1[7] = uVar10;
      if (param_1[6] != 0) {
        local_740 = 0;
        iVar4 = GetAdaptersInfo(0,&local_740);
        if ((iVar4 == 0x6f) && (puVar6 = operator_new(local_740), puVar6 != (undefined4 *)0x0)) {
          iVar4 = GetAdaptersInfo(puVar6,&local_740);
          if ((iVar4 == 0) && (local_740 != 0)) {
            pwVar5 = (wchar_t *)param_1[5];
            sVar2 = wcslen(pwVar5);
            wcstombs(acStack_730,pwVar5,sVar2 + 1);
            puVar9 = puVar6;
            do {
              iVar4 = strcmp(acStack_730,(char *)(puVar9 + 2));
              if (iVar4 == 0) {
                uVar7 = inet_addr((char *)(puVar9 + 0x6c));
                param_1[9] = uVar7;
                uVar7 = inet_addr((char *)(puVar9 + 0x76));
                param_1[10] = uVar7;
                break;
              }
              puVar9 = (undefined4 *)*puVar9;
            } while (puVar9 != (undefined4 *)0x0);
          }
          operator_delete(puVar6);
        }
      }
      uVar10 = FUN_000190b8((int)param_1);
      param_1[8] = uVar10;
    }
  }
  FUN_000219a0(local_28);
  return param_1;
}



/* 0001a0a0 FUN_0001a0a0 */

/* Boundary evidence: original MIPS .pdata 0001a0a0..0001a0eb. Semantic name remains unreviewed. */

undefined4 * FUN_0001a0a0(undefined4 *param_1,uint param_2)

{
  FUN_00018e14(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0001a0ec FUN_0001a0ec */

/* Boundary evidence: original MIPS .pdata 0001a0ec..0001a20f. Semantic name remains unreviewed. */

int * FUN_0001a0ec(void)

{
  wchar_t *pwVar1;
  undefined4 *puVar2;
  int iVar3;
  size_t sVar4;
  int *piVar5;
  int local_18 [2];
  
  piVar5 = (int *)0x0;
  local_18[0] = 0;
  if (DAT_000239a8 != (wchar_t *)0x0) {
    if (*DAT_000239a8 != L'\0') {
      do {
        if (piVar5 != (int *)0x0) {
          return piVar5;
        }
        puVar2 = operator_new(0x2c);
        if (puVar2 == (undefined4 *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = FUN_00019d70(puVar2,DAT_000239a8);
        }
        if (piVar5 != (int *)0x0) {
          iVar3 = (**(code **)(*piVar5 + 8))(piVar5,0);
          if (iVar3 == 0) {
            local_18[0] = 1;
          }
          else {
            FUN_00019c5c((wchar_t *)piVar5[5],local_18);
          }
          if (local_18[0] != 0) {
            local_18[0] = 0;
            (**(code **)*piVar5)(piVar5,1);
            piVar5 = (int *)0x0;
          }
        }
        pwVar1 = DAT_000239a8;
        sVar4 = wcslen(DAT_000239a8);
        DAT_000239a8 = pwVar1 + sVar4 + 1;
      } while (*DAT_000239a8 != L'\0');
      if (piVar5 != (int *)0x0) {
        return piVar5;
      }
    }
    DAT_000239a8 = (wchar_t *)0x0;
  }
  return (int *)0x0;
}



/* 0001a210 FUN_0001a210 */

/* Boundary evidence: original MIPS .pdata 0001a210..0001a3a7. Semantic name remains unreviewed. */

undefined4 FUN_0001a210(int param_1,undefined4 *param_2)

{
  int iVar1;
  size_t sVar2;
  BOOL BVar3;
  undefined4 uVar4;
  int local_630 [2];
  wchar_t awStack_628 [259];
  undefined2 local_422;
  short local_420;
  undefined1 auStack_41e [1022];
  uint local_20;
  
  local_20 = DAT_00023314;
  if ((*(int *)(param_1 + 0x14) == 0) ||
     (iVar1 = FUN_00020eb0(*(wchar_t **)(param_1 + 4)), iVar1 == 0)) {
    if (param_2 == (undefined4 *)0x0) goto LAB_0001a258;
    uVar4 = 0x190b;
  }
  else {
    local_420 = 0;
    memset(auStack_41e,0,0x3fe);
    local_630[1] = 0x400;
    sVar2 = wcslen(*(wchar_t **)(param_1 + 0x14));
    BVar3 = FUN_00018fc0(0x170042,*(LPVOID *)(param_1 + 4),(sVar2 + 1) * 2,&local_420,
                         (LPDWORD)(local_630 + 1));
    if (((BVar3 != 0) && (*(int *)(param_1 + 0x18) == 0)) && (local_420 != 0)) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = 0x1900;
      }
      goto LAB_0001a258;
    }
    if (*(int *)(param_1 + 0x1c) == 0) {
LAB_0001a380:
      FUN_000219a0(local_20);
      return 1;
    }
    local_630[0] = -1;
    iVar1 = _snwprintf(awStack_628,0x103,L"%s\\%s",L"{98C5250D-C29A-4985-AE5F-AFE5367E5006}",
                       *(undefined4 *)(param_1 + 0x14));
    local_422 = 0;
    if (iVar1 != -1) {
      GetDevicePower(awStack_628,1,local_630);
    }
    if (((-1 < local_630[0]) && (local_630[0] < 5)) &&
       ((local_630[0] != 0 || (*(int *)(param_1 + 0x18) != 0)))) goto LAB_0001a380;
    if (param_2 == (undefined4 *)0x0) goto LAB_0001a258;
    uVar4 = 0x1900;
  }
  *param_2 = uVar4;
LAB_0001a258:
  FUN_000219a0(local_20);
  return 0;
}



/* 0001a3a8 FUN_0001a3a8 */

/* Boundary evidence: original MIPS .pdata 0001a3a8..0001a613. Semantic name remains unreviewed. */

undefined4 FUN_0001a3a8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  HCURSOR pHVar1;
  size_t sVar2;
  HANDLE hDevice;
  int iVar3;
  BOOL BVar4;
  undefined4 uVar5;
  wchar_t *_Str;
  undefined4 local_440;
  undefined4 local_43c;
  DWORD local_438 [2];
  wchar_t local_430;
  undefined2 auStack_42e [259];
  wchar_t awStack_228 [259];
  undefined2 local_22;
  uint local_20;
  
  local_20 = DAT_00023314;
  pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
  pHVar1 = SetCursor(pHVar1);
  local_438[0] = 0x202;
  StringCchCopyW(&local_430,0xff,*(STRSAFE_LPCWSTR *)(param_1 + 0x14));
  sVar2 = wcslen(&local_430);
  auStack_42e[sVar2] = 0;
  hDevice = CreateFileW(L"NPW1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff);
  if (hDevice != (HANDLE)0xffffffff) {
    local_440 = *(undefined4 *)(param_1 + 0x14);
    local_43c = 4;
    if (*(int *)(param_1 + 0x18) == 0) {
      local_43c = 0xffffffff;
    }
    DeviceIoControl(hDevice,0x120800,&local_440,8,(LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar3 = _snwprintf(awStack_228,0x103,L"%s\\%s",L"{98C5250D-C29A-4985-AE5F-AFE5367E5006}",
                       *(undefined4 *)(param_1 + 0x14));
    local_22 = 0;
    if (iVar3 != -1) {
      uVar5 = 4;
      if (*(int *)(param_1 + 0x18) == 0) {
        uVar5 = 0xffffffff;
      }
      iVar3 = SetDevicePower(awStack_228,1,uVar5);
      if ((iVar3 != 0) && (param_4 != (undefined4 *)0x0)) {
        *param_4 = 0x1900;
      }
    }
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    sVar2 = wcslen(&local_430);
    FUN_00018fc0(0x170032,&local_430,(sVar2 + 2) * 2,(LPVOID)0x0,(LPDWORD)0x0);
  }
  else {
    sVar2 = wcslen(&local_430);
    FUN_00018fc0(0x170036,&local_430,(sVar2 + 2) * 2,(LPVOID)0x0,(LPDWORD)0x0);
  }
  _Str = *(wchar_t **)(param_1 + 4);
  sVar2 = wcslen(_Str);
  BVar4 = FUN_00018fc0(0x170042,_Str,(sVar2 + 1) * 2,&local_430,local_438);
  if (BVar4 != 0) {
    *(uint *)(param_1 + 0x18) = (uint)(local_430 != L'\0');
  }
  SetCursor(pHVar1);
  FUN_000219a0(local_20);
  return 1;
}



/* 0001a614 FUN_0001a614 */

/* Boundary evidence: original MIPS .pdata 0001a614..0001a6ff. Semantic name remains unreviewed. */

undefined4 FUN_0001a614(int param_1,wchar_t *param_2,int *param_3)

{
  int iVar1;
  size_t sVar2;
  wchar_t *_Dest;
  uint uVar3;
  
  if ((param_2 != (wchar_t *)0x0) && (param_3 != (int *)0x0)) {
    *param_3 = 0;
    iVar1 = _wcsicmp(param_2,*(wchar_t **)(param_1 + 4));
    if (iVar1 == 0) {
      return 1;
    }
    FUN_0001384c(param_2,param_3);
    if (*param_3 == 0) {
      if (*(void **)(param_1 + 4) != (void *)0x0) {
        operator_delete(*(void **)(param_1 + 4));
      }
      sVar2 = wcslen(param_2);
      if (sVar2 + 1 < 0x80000000) {
        uVar3 = (sVar2 + 1) * 2;
      }
      else {
        uVar3 = 0xffffffff;
      }
      _Dest = operator_new(uVar3);
      *(wchar_t **)(param_1 + 4) = _Dest;
      if (_Dest != (wchar_t *)0x0) {
        wcscpy(_Dest,param_2);
        FUN_00019460(param_1);
        return 1;
      }
      *param_3 = 0x1901;
    }
  }
  return 0;
}



/* 0001a700 FUN_0001a700 */

/* Boundary evidence: original MIPS .pdata 0001a700..0001a7bb. Semantic name remains unreviewed. */

undefined4 FUN_0001a700(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  HCURSOR pHVar3;
  wchar_t wStack_210;
  undefined2 auStack_20e [257];
  uint local_c;
  
  local_c = DAT_00023314;
  iVar1 = FUN_00018d9c(param_3,*(wchar_t **)(param_1 + 0x14));
  if (iVar1 != 0) {
    StringCchCopyW(&wStack_210,0x100,*(STRSAFE_LPCWSTR *)(param_1 + 0x14));
    sVar2 = wcslen(&wStack_210);
    auStack_20e[sVar2] = 0;
    pHVar3 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar3 = SetCursor(pHVar3);
    sVar2 = wcslen(&wStack_210);
    FUN_00018fc0(0x17002e,&wStack_210,(sVar2 + 2) * 2,(LPVOID)0x0,(LPDWORD)0x0);
    SetCursor(pHVar3);
  }
  FUN_000219a0(local_c);
  return 1;
}



/* 0001a7bc FUN_0001a7bc */

/* Boundary evidence: original MIPS .pdata 0001a7bc..0001a827. Semantic name remains unreviewed. */

int * FUN_0001a7bc(void)

{
  BOOL BVar1;
  int *piVar2;
  DWORD local_10 [2];
  
  local_10[0] = 0x400;
  BVar1 = FUN_00018fc0(0x17003a,(LPVOID)0x0,0,&DAT_000235a8,local_10);
  if (BVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    DAT_000239a8 = &DAT_000235a8;
    piVar2 = FUN_0001a0ec();
  }
  return piVar2;
}



/* 0001a828 FUN_0001a828 */

/* Boundary evidence: original MIPS .pdata 0001a828..0001a93f. Semantic name remains unreviewed. */

undefined4 * FUN_0001a828(undefined4 *param_1,wchar_t *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  wchar_t *_Str1;
  uint uVar4;
  void *local_28 [2];
  
  FUN_0001e910(param_1,param_2);
  *param_1 = &PTR_FUN_00011b60;
  iVar2 = wcscmp((wchar_t *)(param_1 + 0x1de),L"PPPoE");
  if (iVar2 != 0) {
    local_28[0] = (void *)0x0;
    uVar3 = FUN_0001d91c(local_28);
    pvVar1 = local_28[0];
    uVar4 = 0;
    if (uVar3 != 0) {
      _Str1 = (wchar_t *)((int)local_28[0] + 4);
      do {
        iVar2 = wcscmp(_Str1,L"PPPoE");
        if (iVar2 == 0) {
          wcscpy((wchar_t *)((int)param_1 + 0x79a),(wchar_t *)((int)pvVar1 + uVar4 * 0x128 + 0x26));
          wcscpy((wchar_t *)(param_1 + 0x1de),L"PPPoE");
          param_1[6] = 0x4c1800;
          break;
        }
        uVar4 = uVar4 + 1;
        _Str1 = _Str1 + 0x94;
      } while (uVar4 < uVar3);
    }
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
  }
  return param_1;
}



/* 0001a940 FUN_0001a940 */

/* Boundary evidence: original MIPS .pdata 0001a940..0001a977. Semantic name remains unreviewed. */

bool FUN_0001a940(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = wcscmp(param_2,L"PPPOEConnInfo");
  return iVar1 == 0;
}



/* 0001a984 FUN_0001a984 */

/* Boundary evidence: original MIPS .pdata 0001a984..0001a9a3. Semantic name remains unreviewed. */

void FUN_0001a984(undefined4 param_1,HINSTANCE param_2,LPWSTR param_3,int param_4)

{
  LoadStringW(param_2,0x1842,param_3,param_4);
  return;
}



/* 0001a9a4 FUN_0001a9a4 */

/* Boundary evidence: original MIPS .pdata 0001a9a4..0001acdf. Semantic name remains unreviewed. */

undefined4 FUN_0001a9a4(HWND param_1,int param_2,short param_3,int param_4)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  WPARAM wParam;
  void *pvVar5;
  int iVar6;
  int iVar7;
  void *local_28 [2];
  
  LVar1 = GetWindowLongW(param_1,-0x15);
  iVar6 = 0;
  if (LVar1 != 0) {
    iVar6 = *(int *)(LVar1 + 0x1c);
  }
  if (param_2 != 0x4e) {
    if (param_2 == 0x110) {
      SetWindowLongW(param_1,-0x15,param_4);
      if ((param_4 != 0) && (iVar6 = *(int *)(param_4 + 0x1c), iVar6 != 0)) {
        local_28[0] = (void *)0x0;
        iVar2 = FUN_0001d91c(local_28);
        pvVar5 = local_28[0];
        if (iVar2 != 0) {
          iVar7 = 0;
          do {
            iVar3 = wcscmp((wchar_t *)((int)pvVar5 + iVar7 + 4),L"PPPoE");
            if (iVar3 == 0) {
              pHVar4 = GetDlgItem(param_1,0x13a8);
              SendMessageW(pHVar4,0x143,0,(int)pvVar5 + iVar7 + 0x26);
              pvVar5 = local_28[0];
            }
            iVar2 = iVar2 + -1;
            iVar7 = iVar7 + 0x128;
          } while (iVar2 != 0);
        }
        if (pvVar5 != (void *)0x0) {
          operator_delete(pvVar5);
        }
        pHVar4 = GetDlgItem(param_1,0x13a8);
        wParam = SendMessageW(pHVar4,0x158,0,iVar6 + 0x79a);
        if (wParam == 0xffffffff) {
          wParam = 0;
        }
        pHVar4 = GetDlgItem(param_1,0x13a8);
        SendMessageW(pHVar4,0x14e,wParam,0);
        pHVar4 = GetDlgItem(param_1,0x13a8);
        SetFocus(pHVar4);
        pHVar4 = GetDlgItem(param_1,0x1396);
        SendMessageW(pHVar4,0xc5,0x80,0);
        SetDlgItemTextW(param_1,0x1396,(LPCWSTR)(iVar6 + 0x3a));
        pHVar4 = GetDlgItem(param_1,0x1396);
        SetFocus(pHVar4);
      }
      return 0;
    }
    if (param_2 != 0x111) {
      return 0;
    }
    if (iVar6 == 0) {
      return 0;
    }
    if (param_3 != 0x138f) {
      if (param_3 != 0x13aa) {
        return 1;
      }
      FUN_0001f798(iVar6,param_1,*(HINSTANCE *)(LVar1 + 8));
      return 1;
    }
    FUN_0001f664(iVar6,param_1,*(HINSTANCE *)(LVar1 + 8));
    return 1;
  }
  if (iVar6 == 0) {
    return 0;
  }
  iVar2 = *(int *)(param_4 + 8);
  if (iVar2 == -0xd0) {
LAB_0001ac5c:
    pHVar4 = GetDlgItem(param_1,0x13a8);
    GetWindowTextW(pHVar4,(LPWSTR)(iVar6 + 0x79a),0x81);
    GetDlgItemTextW(param_1,0x1396,(LPWSTR)(iVar6 + 0x3a),0x81);
    if (*(int *)(param_4 + 8) != -0xd0) goto LAB_0001aca4;
  }
  else if (iVar2 != -0xca) {
    if (iVar2 != -0xc9) {
      if (iVar2 == -200) {
        pHVar4 = GetParent(param_1);
        PostMessageW(pHVar4,0x470,0,5);
        pHVar4 = GetDlgItem(param_1,0x138c);
        SetWindowTextW(pHVar4,*(LPCWSTR *)(iVar6 + 4));
      }
      goto LAB_0001aca4;
    }
    goto LAB_0001ac5c;
  }
  FUN_0001ebc8(iVar6);
LAB_0001aca4:
  SetWindowLongW(param_1,0,0);
  return 1;
}



/* 0001ace0 FUN_0001ace0 */

/* Boundary evidence: original MIPS .pdata 0001ace0..0001ad2b. Semantic name remains unreviewed. */

undefined4 * FUN_0001ace0(undefined4 *param_1,uint param_2)

{
  FUN_0001c4a8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0001ad2c FUN_0001ad2c */

/* Boundary evidence: original MIPS .pdata 0001ad2c..0001adcb. Semantic name remains unreviewed. */

undefined4 FUN_0001ad2c(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 local_40;
  undefined1 auStack_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  code *local_28;
  int local_24;
  
  pcVar2 = *(code **)(param_1 + 0x10);
  if (pcVar2 != (code *)0x0) {
    memset(auStack_3c,0,0x24);
    local_40 = 0x28;
    if (param_2 == 0) {
      local_34 = 0x1009;
      if (DAT_00023448 == 0) {
        local_34 = 0xfa5;
      }
      local_28 = FUN_0001a9a4;
      local_38 = param_3;
      local_24 = param_1;
      uVar1 = (*pcVar2)(&local_40);
      return uVar1;
    }
  }
  return 0;
}



/* 0001adcc FUN_0001adcc */

/* Boundary evidence: original MIPS .pdata 0001adcc..0001ae3b. Semantic name remains unreviewed. */

void FUN_0001adcc(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    EventModify(*(undefined4 *)(param_1 + 0xc),3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 4),0xffffffff);
    CloseHandle(*(HANDLE *)(param_1 + 0xc));
    CloseHandle(*(HANDLE *)(param_1 + 4));
  }
  return;
}



/* 0001ae80 FUN_0001ae80 */

/* Boundary evidence: original MIPS .pdata 0001ae80..0001b03b. Semantic name remains unreviewed. */

LRESULT FUN_0001ae80(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  undefined4 *puVar1;
  LRESULT LVar2;
  HDC hdc;
  HWND pHVar3;
  BOOL BVar4;
  HICON hIcon;
  LPCWSTR name;
  int iVar5;
  int iVar6;
  tagRECT local_28;
  
  puVar1 = (undefined4 *)GetWindowLongW(param_1,-0x15);
  if (((param_2 == 0xf) || (param_2 == 0xf3)) || (param_2 == 0xf1)) {
    CallWindowProcW((WNDPROC)puVar1[6],param_1,param_2,param_3,param_4);
    hdc = GetDC(param_1);
    if (hdc != (HDC)0x0) {
      pHVar3 = GetDlgItem((HWND)puVar1[5],0x13a6);
      if (pHVar3 == param_1) {
        BVar4 = IsWindowEnabled(param_1);
        if (BVar4 == 0) {
          name = (LPCWSTR)0xbc3;
        }
        else {
          name = (LPCWSTR)0xbc2;
        }
      }
      else {
        BVar4 = IsWindowEnabled(param_1);
        name = (LPCWSTR)0xbc4;
        if (BVar4 == 0) {
          name = (LPCWSTR)0xbc5;
        }
      }
      hIcon = LoadImageW((HINSTANCE)*puVar1,name,1,0,0,0);
      local_28.left = 0;
      memset(&local_28.top,0,0xc);
      GetClientRect(param_1,&local_28);
      iVar5 = local_28.bottom + -0xd;
      if (iVar5 < 0) {
        iVar5 = local_28.bottom + -0xc;
      }
      iVar6 = local_28.right + -10;
      if (iVar6 < 0) {
        iVar6 = local_28.right + -9;
      }
      DrawIconEx(hdc,iVar6 >> 1,iVar5 >> 1,hIcon,0,0,0,(HBRUSH)0x0,3);
      DestroyIcon(hIcon);
      ReleaseDC(param_1,hdc);
    }
    LVar2 = 0;
  }
  else {
    LVar2 = CallWindowProcW((WNDPROC)puVar1[6],param_1,param_2,param_3,param_4);
  }
  return LVar2;
}



/* 0001b03c FUN_0001b03c */

/* Boundary evidence: original MIPS .pdata 0001b03c..0001b097. Semantic name remains unreviewed. */

int * FUN_0001b03c(int *param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0001b098 FUN_0001b098 */

/* Boundary evidence: original MIPS .pdata 0001b098..0001b217. Semantic name remains unreviewed. */

void FUN_0001b098(int param_1)

{
  HWND hWnd;
  HWND pHVar1;
  LONG LVar2;
  tagRECT local_40;
  undefined4 local_30;
  undefined4 local_2c [7];
  
  hWnd = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a5);
  SendMessageW(hWnd,0x1003,1,DAT_00023460);
  local_30 = 0;
  memset(local_2c,0,0x1c);
  local_40.left = 0;
  memset(&local_40.top,0,0xc);
  GetClientRect(hWnd,&local_40);
  local_30 = 1;
  local_2c[0] = 0x800;
  SendMessageW(hWnd,0x1061,0,(LPARAM)&local_30);
  SendMessageW(hWnd,0x1036,0,0x20);
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a6);
  LVar2 = GetWindowLongW(pHVar1,-4);
  *(LONG *)(param_1 + 0x18) = LVar2;
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a6);
  SetWindowLongW(pHVar1,-4,0x1ae80);
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a6);
  SetWindowLongW(pHVar1,-0x15,param_1);
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a7);
  SetWindowLongW(pHVar1,-4,0x1ae80);
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a7);
  SetWindowLongW(pHVar1,-0x15,param_1);
  GetClientRect(hWnd,&local_40);
  SendMessageW(hWnd,0x101e,0,(uint)(ushort)local_40.right);
  return;
}



/* 0001b218 FUN_0001b218 */

/* Boundary evidence: original MIPS .pdata 0001b218..0001b347. Semantic name remains unreviewed. */

void FUN_0001b218(int param_1)

{
  HWND hWnd;
  HWND hWnd_00;
  HWND hWnd_01;
  LRESULT LVar1;
  LRESULT LVar2;
  BOOL BVar3;
  
  hWnd = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a5);
  hWnd_00 = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a6);
  hWnd_01 = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a7);
  LVar1 = FUN_000126a8(hWnd,0xffffffff,2);
  LVar2 = SendMessageW(hWnd,0x1004,0,0);
  if (LVar2 < 2) {
LAB_0001b2e4:
    BVar3 = 0;
LAB_0001b2e8:
    EnableWindow(hWnd_00,BVar3);
    BVar3 = 0;
  }
  else {
    if (LVar1 == 0) {
      BVar3 = 0;
    }
    else {
      if (LVar2 + -1 == LVar1) {
        BVar3 = 1;
        goto LAB_0001b2e8;
      }
      if ((LVar1 < 1) || (LVar2 + -1 <= LVar1)) goto LAB_0001b2e4;
      BVar3 = 1;
    }
    EnableWindow(hWnd_00,BVar3);
    BVar3 = 1;
  }
  EnableWindow(hWnd_01,BVar3);
  InvalidateRect(hWnd_00,(RECT *)0x0,1);
  InvalidateRect(hWnd_01,(RECT *)0x0,1);
  UpdateWindow(hWnd_00);
  UpdateWindow(hWnd_01);
  return;
}



/* 0001b348 FUN_0001b348 */

/* Boundary evidence: original MIPS .pdata 0001b348..0001b47f. Semantic name remains unreviewed. */

void FUN_0001b348(int param_1)

{
  HWND hWnd;
  LRESULT LVar1;
  uint uVar2;
  undefined4 local_70;
  LRESULT local_6c [7];
  int local_50;
  undefined4 local_40;
  int local_3c [7];
  int local_20;
  
  hWnd = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a5);
  local_70 = 0;
  memset(local_6c,0,0x28);
  local_40 = 0;
  memset(local_3c,0,0x28);
  local_6c[0] = FUN_000126a8(hWnd,0xffffffff,2);
  local_3c[0] = local_6c[0] + -1;
  local_70 = 4;
  local_40 = 4;
  if ((((local_6c[0] != -1) && (LVar1 = SendMessageW(hWnd,0x104b,0,(LPARAM)&local_70), LVar1 != 0))
      && (LVar1 = SendMessageW(hWnd,0x104b,0,(LPARAM)&local_40), LVar1 != 0)) &&
     ((local_50 != 0 && (local_20 != 0)))) {
    uVar2 = *(uint *)(local_50 + 4);
    if (uVar2 == *(uint *)(local_20 + 4)) {
      if (1 < uVar2) {
        *(uint *)(local_50 + 4) = uVar2 - 1;
      }
    }
    else {
      *(uint *)(local_50 + 4) = *(uint *)(local_20 + 4);
      *(uint *)(local_20 + 4) = uVar2;
    }
    SendMessageW(hWnd,0x1030,0,0x1ae3c);
    FUN_0001b218(param_1);
  }
  return;
}



/* 0001b480 FUN_0001b480 */

/* Boundary evidence: original MIPS .pdata 0001b480..0001b5ab. Semantic name remains unreviewed. */

void FUN_0001b480(int param_1)

{
  HWND hWnd;
  LRESULT LVar1;
  int iVar2;
  undefined4 local_70;
  LRESULT local_6c [7];
  int local_50;
  undefined4 local_40;
  int local_3c [7];
  int local_20;
  
  hWnd = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a5);
  local_70 = 0;
  memset(local_6c,0,0x28);
  local_40 = 0;
  memset(local_3c,0,0x28);
  local_6c[0] = FUN_000126a8(hWnd,0xffffffff,2);
  local_3c[0] = local_6c[0] + 1;
  local_70 = 4;
  local_40 = 4;
  if ((((local_6c[0] != -1) && (LVar1 = SendMessageW(hWnd,0x104b,0,(LPARAM)&local_70), LVar1 != 0))
      && (LVar1 = SendMessageW(hWnd,0x104b,0,(LPARAM)&local_40), LVar1 != 0)) &&
     ((local_50 != 0 && (local_20 != 0)))) {
    iVar2 = *(int *)(local_50 + 4);
    if (iVar2 == *(int *)(local_20 + 4)) {
      *(int *)(local_50 + 4) = iVar2 + 1;
    }
    else {
      *(int *)(local_50 + 4) = *(int *)(local_20 + 4);
      *(int *)(local_20 + 4) = iVar2;
    }
    SendMessageW(hWnd,0x1030,0,0x1ae3c);
    FUN_0001b218(param_1);
  }
  return;
}



/* 0001b5ac FUN_0001b5ac */

/* Boundary evidence: original MIPS .pdata 0001b5ac..0001b6df. Semantic name remains unreviewed. */

undefined4 FUN_0001b5ac(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  HWND hWnd;
  LRESULT LVar3;
  undefined4 local_48;
  LRESULT local_44 [4];
  undefined4 local_34;
  undefined4 local_2c;
  int *local_28;
  
  if (((param_2 != (int *)0x0) && (*(int *)(param_1 + 0x14) != 0)) &&
     (iVar1 = FUN_00019794((int)param_2), iVar1 != -1)) {
    piVar2 = operator_new(8);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      *piVar2 = 0;
      piVar2[1] = 0;
    }
    if (piVar2 != (int *)0x0) {
      *piVar2 = (int)param_2;
      piVar2[1] = iVar1;
      hWnd = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a5);
      memset(local_44,0,0x28);
      local_48 = 7;
      local_44[0] = SendMessageW(hWnd,0x1004,0,0);
      local_34 = 0xffffffff;
      local_2c = (**(code **)(*param_2 + 0xc))(param_2);
      local_28 = piVar2;
      LVar3 = SendMessageW(hWnd,0x104d,0,(LPARAM)&local_48);
      if (LVar3 != -1) {
        return 1;
      }
      FUN_0001b03c(piVar2,1);
    }
  }
  return 0;
}



/* 0001b6e0 FUN_0001b6e0 */

/* Boundary evidence: original MIPS .pdata 0001b6e0..0001b7a3. Semantic name remains unreviewed. */

void FUN_0001b6e0(int param_1)

{
  HWND hWnd;
  LRESULT LVar1;
  LRESULT LVar2;
  undefined4 local_40;
  int local_3c [7];
  int *local_20;
  
  hWnd = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a5);
  LVar1 = SendMessageW(hWnd,0x1004,0,0);
  memset(local_3c,0,0x28);
  local_40 = 4;
  SendMessageW(hWnd,0x1004,0,0);
  local_3c[0] = 0;
  if (0 < LVar1) {
    do {
      LVar2 = SendMessageW(hWnd,0x104b,0,(LPARAM)&local_40);
      if (LVar2 != 0) {
        FUN_000198b4(*local_20,local_20[1]);
      }
      local_3c[0] = local_3c[0] + 1;
    } while (local_3c[0] < LVar1);
  }
  return;
}



/* 0001b7a4 FUN_0001b7a4 */

/* Boundary evidence: original MIPS .pdata 0001b7a4..0001b8eb. Semantic name remains unreviewed. */

undefined4 FUN_0001b7a4(int param_1)

{
  BOOL BVar1;
  HWND hWnd;
  HCURSOR pHVar2;
  int iVar3;
  tagMSG local_60;
  undefined1 auStack_40 [12];
  undefined4 local_34;
  undefined4 local_30;
  
  if (*(HWND *)(param_1 + 0x14) != (HWND)0x0) {
    BVar1 = IsWindowVisible(*(HWND *)(param_1 + 0x14));
    if (BVar1 != 0) {
      return 1;
    }
    hWnd = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a5);
    if (hWnd != (HWND)0x0) {
      pHVar2 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      pHVar2 = SetCursor(pHVar2);
      local_30 = 3;
      local_34 = 3;
      SendMessageW(hWnd,0x102b,0,(LPARAM)auStack_40);
      ShowWindow(*(HWND *)(param_1 + 0x14),5);
      UpdateWindow(*(HWND *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x1c) = 1;
      if (*(HWND *)(param_1 + 0x10) != (HWND)0x0) {
        EnableWindow(*(HWND *)(param_1 + 0x10),0);
      }
      SetCursor(pHVar2);
      local_60.hwnd = (HWND)0x0;
      memset(&local_60.message,0,0x18);
      iVar3 = *(int *)(param_1 + 0x1c);
      while (iVar3 != 0) {
        BVar1 = GetMessageW(&local_60,*(HWND *)(param_1 + 0x10),0xf,0xf);
        if (BVar1 != 0) {
          DispatchMessageW(&local_60);
        }
        iVar3 = *(int *)(param_1 + 0x1c);
      }
      if (*(HWND *)(param_1 + 0x10) == (HWND)0x0) {
        return 1;
      }
      EnableWindow(*(HWND *)(param_1 + 0x10),1);
      return 1;
    }
  }
  return 0;
}



/* 0001b8ec FUN_0001b8ec */

/* Boundary evidence: original MIPS .pdata 0001b8ec..0001b98f. Semantic name remains unreviewed. */

bool FUN_0001b8ec(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  wchar_t awStack_818 [512];
  wchar_t awStack_418 [512];
  uint local_18;
  
  local_18 = DAT_00023314;
  (**(code **)(*param_2 + 0x48))(param_2,0,0,awStack_418,0x200,0);
  (**(code **)(*param_3 + 0x48))(param_3,0,0,awStack_818,0x200,0);
  iVar1 = wcscmp(awStack_418,awStack_818);
  FUN_000219a0(local_18);
  return iVar1 == 0;
}



/* 0001b990 FUN_0001b990 */

/* Boundary evidence: original MIPS .pdata 0001b990..0001ba83. Semantic name remains unreviewed. */

undefined4 FUN_0001b990(int param_1,int *param_2)

{
  bool bVar1;
  HWND hWnd;
  LRESULT LVar2;
  LRESULT LVar3;
  undefined3 extraout_var;
  undefined4 local_48;
  int local_44 [7];
  undefined4 *local_28;
  
  hWnd = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a5);
  LVar2 = SendMessageW(hWnd,0x1004,0,0);
  memset(local_44,0,0x28);
  local_48 = 4;
  SendMessageW(hWnd,0x1004,0,0);
  local_44[0] = 0;
  if (0 < LVar2) {
    do {
      LVar3 = SendMessageW(hWnd,0x104b,0,(LPARAM)&local_48);
      if ((LVar3 != 0) &&
         (bVar1 = FUN_0001b8ec(param_1,(int *)*local_28,param_2), CONCAT31(extraout_var,bVar1) != 0)
         ) {
        return 1;
      }
      local_44[0] = local_44[0] + 1;
    } while (local_44[0] < LVar2);
  }
  return 0;
}



/* 0001ba84 FUN_0001ba84 */

/* Boundary evidence: original MIPS .pdata 0001ba84..0001baeb. Semantic name remains unreviewed. */

void * FUN_0001ba84(int param_1,int param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(int *)((int)pvVar1 + 4) = param_2;
    *(undefined4 *)((int)pvVar1 + 8) = *(undefined4 *)(param_2 + 8);
    *(void **)(*(int *)(param_2 + 8) + 4) = pvVar1;
    *(void **)(param_2 + 8) = pvVar1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return pvVar1;
}



/* 0001baec FUN_0001baec */

/* Boundary evidence: original MIPS .pdata 0001baec..0001bdab. Semantic name remains unreviewed. */

undefined4 FUN_0001baec(HWND param_1,int param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  size_t sVar2;
  int *piVar3;
  uint uVar4;
  wchar_t *_Str;
  int *piVar5;
  
  puVar1 = (undefined4 *)GetWindowLongW(param_1,-0x15);
  if (param_2 == 0x10) {
LAB_0001bc58:
    ShowWindow((HWND)puVar1[5],0);
    puVar1[7] = 0;
    return 1;
  }
  if (param_2 == 0x4e) {
    if (*(int *)(param_4 + 4) == 0x13a5) {
      if (*(int *)(param_4 + 8) == -0x65) {
        if ((*(uint *)(param_4 + 0x1c) & 8) != 0) {
          FUN_0001b218((int)puVar1);
          return 1;
        }
        return 1;
      }
      if (*(int *)(param_4 + 8) == -0x67) {
        if (*(int **)(param_4 + 0x28) != (int *)0x0) {
          FUN_0001b03c(*(int **)(param_4 + 0x28),1);
          return 1;
        }
        return 1;
      }
      if (*(int *)(param_4 + 8) == -0xb1) {
        piVar5 = *(int **)(param_4 + 0x2c);
        if (piVar5 == (int *)0x0) {
          return 1;
        }
        piVar3 = (int *)*piVar5;
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x48))
                    (piVar3,0,*puVar1,*(undefined4 *)(param_4 + 0x20),
                     *(undefined4 *)(param_4 + 0x24),0);
          wcscat(*(wchar_t **)(param_4 + 0x20),L" (");
          _Str = *(wchar_t **)(param_4 + 0x20);
          sVar2 = wcslen(_Str);
          _itow(piVar5[1],_Str + sVar2,10);
          wcscat(*(wchar_t **)(param_4 + 0x20),L")");
          return 1;
        }
        return 1;
      }
    }
  }
  else {
    if (param_2 == 0x102) {
      if (param_3 != 0x1b) {
        return 1;
      }
      if (param_4 != 0) {
        return 1;
      }
      goto LAB_0001bc58;
    }
    if (param_2 == 0x110) {
      SetWindowLongW(param_1,-0x15,param_4);
      *(HWND *)(param_4 + 0x14) = param_1;
      FUN_0001b098(param_4);
      return 1;
    }
    if (param_2 == 0x111) {
      uVar4 = param_3 & 0xffff;
      if ((uVar4 == 1) && (param_3 >> 0x10 == 0)) {
        FUN_0001b6e0((int)puVar1);
      }
      else if ((uVar4 != 2) || (param_3 >> 0x10 != 0)) {
        if ((uVar4 == 0x13a6) && (param_3 >> 0x10 == 0)) {
          FUN_0001b348((int)puVar1);
          return 1;
        }
        if (uVar4 != 0x13a7) {
          return 0;
        }
        if (param_3 >> 0x10 != 0) {
          return 0;
        }
        FUN_0001b480((int)puVar1);
        return 1;
      }
      PostMessageW(param_1,0x10,0,0);
      return 1;
    }
  }
  return 0;
}



/* 0001bdac FUN_0001bdac */

/* Boundary evidence: original MIPS .pdata 0001bdac..0001be17. Semantic name remains unreviewed. */

undefined4 * FUN_0001bdac(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)((int)param_3 + 4);
  *(undefined4 *)(*(int *)((int)param_3 + 8) + 4) = uVar2;
  *(undefined4 *)(*(int *)((int)param_3 + 4) + 8) = *(undefined4 *)((int)param_3 + 8);
  operator_delete(param_3);
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = uVar2;
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  return param_2;
}



/* 0001be18 FUN_0001be18 */

/* Boundary evidence: original MIPS .pdata 0001be18..0001be77. Semantic name remains unreviewed. */

undefined * FUN_0001be18(void)

{
  if ((DAT_000239c0 & 1) == 0) {
    DAT_000239c0 = DAT_000239c0 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_000239ac);
    FUN_00012598(FUN_00022334);
  }
  return &DAT_000239ac;
}



/* 0001be78 FUN_0001be78 */

/* Boundary evidence: original MIPS .pdata 0001be78..0001bff3. Semantic name remains unreviewed. */

undefined4 FUN_0001be78(undefined4 *param_1)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  DWORD DVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 uVar4;
  LPCWSTR lpName;
  tagMSG local_30;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    lpName = (LPCWSTR)0x100c;
    if (DAT_00023448 == 0) {
      lpName = (LPCWSTR)0xfa8;
    }
    hResInfo = FindResourceW((HMODULE)*param_1,lpName,(LPCWSTR)0x5);
    lpTemplate = LoadResource((HMODULE)*param_1,hResInfo);
    CreateDialogIndirectParamW
              ((HINSTANCE)*param_1,lpTemplate,(HWND)param_1[4],FUN_0001baec,(LPARAM)param_1);
    EventModify(param_1[2],3);
    DVar1 = MsgWaitForMultipleObjectsEx(1,(HANDLE *)(param_1 + 3),0xffffffff,0x7f,0);
    while (DVar1 != 0) {
      local_30.hwnd = (HWND)0x0;
      memset(&local_30.message,0,0x18);
      iVar2 = PeekMessageW(&local_30,(HWND)0x0,0,0,1);
      while (iVar2 != 0) {
        BVar3 = IsDialogMessageW((HWND)param_1[5],&local_30);
        if (BVar3 == 0) {
          TranslateMessage(&local_30);
          DispatchMessageW(&local_30);
        }
        iVar2 = PeekMessageW(&local_30,(HWND)0x0,0,0,1);
      }
      DVar1 = MsgWaitForMultipleObjectsEx(1,(HANDLE *)(param_1 + 3),0xffffffff,0x7f,0);
    }
    DestroyWindow((HWND)param_1[5]);
    uVar4 = 0;
  }
  return uVar4;
}



/* 0001bff4 FUN_0001bff4 */

/* Boundary evidence: original MIPS .pdata 0001bff4..0001c07f. Semantic name remains unreviewed. */

undefined4 * FUN_0001bff4(int param_1,undefined4 *param_2,void *param_3,void *param_4)

{
  void *pvVar1;
  undefined4 auStack_20 [2];
  
  while (param_3 != param_4) {
    pvVar1 = *(void **)((int)param_3 + 4);
    FUN_0001bdac(param_1,auStack_20,param_3);
    param_3 = pvVar1;
  }
  *param_2 = param_3;
  return param_2;
}



/* 0001c080 FUN_0001c080 */

/* Boundary evidence: original MIPS .pdata 0001c080..0001c0e7. Semantic name remains unreviewed. */

undefined4 * FUN_0001c080(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_0001ba84((int)param_1,param_3);
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  else {
    *puVar1 = *param_4;
    *param_2 = puVar1;
  }
  return param_2;
}



/* 0001c0e8 FUN_0001c0e8 */

/* Boundary evidence: original MIPS .pdata 0001c0e8..0001c1c3. Semantic name remains unreviewed. */

undefined4 * FUN_0001c0e8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  
  *param_1 = param_2;
  param_1[4] = param_3;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_1[2] = pvVar1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_1[3] = pvVar1;
  if ((param_1[2] != 0) && (pvVar1 != (HANDLE)0x0)) {
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001be78,param_1,0,(LPDWORD)0x0);
    param_1[1] = pvVar1;
    if (pvVar1 != (HANDLE)0x0) {
      WaitForSingleObject((HANDLE)param_1[2],0xffffffff);
    }
    CloseHandle((HANDLE)param_1[2]);
    param_1[2] = 0;
  }
  return param_1;
}



/* 0001c1c4 FUN_0001c1c4 */

/* Boundary evidence: original MIPS .pdata 0001c1c4..0001c21b. Semantic name remains unreviewed. */

bool FUN_0001c1c4(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 auStack_10 [2];
  
  iVar2 = *param_1;
  piVar1 = FUN_0001c080(param_1,auStack_10,*(int *)(iVar2 + 4),param_2);
  return iVar2 != *piVar1;
}



/* 0001c21c FUN_0001c21c */

/* Boundary evidence: original MIPS .pdata 0001c21c..0001c4a7. Semantic name remains unreviewed. */

void FUN_0001c21c(int param_1)

{
  undefined4 **ppuVar1;
  bool bVar2;
  HWND hWnd;
  LRESULT LVar3;
  LRESULT LVar4;
  int *piVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined4 ***pppuVar7;
  undefined4 **ppuVar8;
  int *local_68 [2];
  undefined4 **local_60;
  undefined4 **local_5c;
  undefined4 **local_58;
  undefined4 local_54;
  undefined4 local_50;
  WPARAM local_4c [7];
  undefined4 *local_30;
  
  hWnd = GetDlgItem(*(HWND *)(param_1 + 0x14),0x13a5);
  local_50 = 0;
  memset(local_4c,0,0x28);
  LVar3 = SendMessageW(hWnd,0x1004,0,0);
  local_60 = &local_60;
  local_5c = &local_60;
  local_58 = &local_60;
  local_54 = 0;
  if (hWnd == (HWND)0x0) {
    pppuVar7 = &local_60;
  }
  else {
    LVar4 = SendMessageW(hWnd,0x1004,0,0);
    if (LVar4 == 0) {
      piVar5 = FUN_0001a7bc();
      while (piVar5 != (int *)0x0) {
        FUN_0001b5ac(param_1,piVar5);
        piVar5 = FUN_0001a0ec();
      }
    }
    else {
      local_68[0] = FUN_0001a7bc();
      while (local_68[0] != (int *)0x0) {
        FUN_0001c1c4((int *)&local_60,local_68);
        local_68[0] = FUN_0001a0ec();
      }
      local_50 = 4;
      SendMessageW(hWnd,0x1004,0,0);
      local_4c[0] = 0;
      if (0 < LVar3) {
        do {
          LVar4 = SendMessageW(hWnd,0x104b,0,(LPARAM)&local_50);
          ppuVar1 = local_60;
          if (LVar4 != 0) {
            piVar5 = (int *)*local_30;
            for (pppuVar7 = (undefined4 ***)local_60[1]; pppuVar7 != (undefined4 ***)ppuVar1;
                pppuVar7 = (undefined4 ***)pppuVar7[1]) {
              bVar2 = FUN_0001b8ec(param_1,piVar5,(int *)*pppuVar7);
              if (CONCAT31(extraout_var,bVar2) != 0) goto LAB_0001c414;
            }
            SendMessageW(hWnd,0x1008,local_4c[0],0);
          }
LAB_0001c414:
          local_4c[0] = local_4c[0] + 1;
        } while ((int)local_4c[0] < LVar3);
      }
      ppuVar1 = local_60;
      for (pppuVar7 = (undefined4 ***)local_60[1]; pppuVar7 != (undefined4 ***)ppuVar1;
          pppuVar7 = (undefined4 ***)pppuVar7[1]) {
        ppuVar8 = *pppuVar7;
        iVar6 = FUN_0001b990(param_1,(int *)ppuVar8);
        if (iVar6 == 0) {
          FUN_0001b5ac(param_1,(int *)ppuVar8);
        }
        else if (ppuVar8 != (undefined4 **)0x0) {
          (*(code *)**ppuVar8)(ppuVar8,1);
        }
      }
    }
    SendMessageW(hWnd,0x1030,0,0x1ae3c);
    pppuVar7 = (undefined4 ***)local_60[1];
  }
  FUN_0001bff4((int)&local_60,local_68,pppuVar7,local_60);
  return;
}



/* 0001c4a8 FUN_0001c4a8 */

/* Boundary evidence: original MIPS .pdata 0001c4a8..0001c4fb. Semantic name remains unreviewed. */

void FUN_0001c4a8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00011bd8;
  if ((void *)param_1[0x36d] != (void *)0x0) {
    operator_delete((void *)param_1[0x36d]);
  }
  LocalFree((HLOCAL)param_1[0x369]);
  LocalFree((HLOCAL)param_1[0x36b]);
  FUN_00020e58(param_1);
  return;
}



/* 0001c504 FUN_0001c504 */

/* Boundary evidence: original MIPS .pdata 0001c504..0001c53b. Semantic name remains unreviewed. */

bool FUN_0001c504(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = wcscmp(param_2,L"RasConnInfo");
  return iVar1 == 0;
}



/* 0001c53c FUN_0001c53c */

/* Boundary evidence: original MIPS .pdata 0001c53c..0001c5fb. Semantic name remains unreviewed. */

undefined4 FUN_0001c53c(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(short **)(param_1 + 4) == (short *)0x0) || (**(short **)(param_1 + 4) == 0)) {
    if (param_2 == (undefined4 *)0x0) {
      return 0;
    }
    uVar2 = 0x1909;
  }
  else {
    iVar1 = RasValidateEntryName(0);
    if (iVar1 == 0) {
      if (param_2 == (undefined4 *)0x0) {
        return 0;
      }
      uVar2 = 0x190e;
    }
    else {
      if (iVar1 != 0x7b) {
        if (iVar1 == 0xb7) {
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = 0x190a;
          }
          return 1;
        }
        if (param_2 == (undefined4 *)0x0) {
          return 0;
        }
        *param_2 = 0x1900;
        return 0;
      }
      if (param_2 == (undefined4 *)0x0) {
        return 0;
      }
      uVar2 = 0x190b;
    }
  }
  *param_2 = uVar2;
  return 0;
}



/* 0001c5fc FUN_0001c5fc */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 0001c5fc..0001c767. Semantic name remains unreviewed. */

uint FUN_0001c5fc(int param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  wchar_t *_Str2;
  wchar_t *_Str1;
  uint local_60;
  uint local_5c [2];
  undefined1 auStack_54 [48];
  uint local_24;
  
  local_24 = DAT_00023314;
  uVar4 = 0;
  memset(auStack_54,0,0x30);
  local_5c[0] = 0x34;
  local_60 = 1;
  local_5c[1] = 0x34;
  puVar3 = local_5c + 1;
  iVar2 = RasEnumConnections(local_5c + 1,local_5c,&local_60);
  if (iVar2 == 0) {
LAB_0001c6d0:
    uVar1 = local_60;
    uVar5 = 0;
    if (local_60 != 0) {
      _Str1 = *(wchar_t **)(param_1 + 4);
      _Str2 = (wchar_t *)(puVar3 + 2);
      do {
        iVar2 = wcscmp(_Str1,_Str2);
        if (iVar2 == 0) {
          uVar4 = puVar3[uVar5 * 0xd + 1];
          break;
        }
        uVar5 = uVar5 + 1;
        _Str2 = _Str2 + 0x1a;
      } while (uVar5 < uVar1);
    }
    if (puVar3 != local_5c + 1) {
      operator_delete(puVar3);
    }
    FUN_000219a0(local_24);
  }
  else {
    if ((iVar2 == 0x25b) && (puVar3 = operator_new(local_5c[0]), puVar3 != (uint *)0x0)) {
      *puVar3 = 0x34;
      iVar2 = RasEnumConnections(puVar3,local_5c,&local_60);
      if (iVar2 == 0) goto LAB_0001c6d0;
      operator_delete(puVar3);
    }
    FUN_000219a0(local_24);
    uVar4 = 0;
  }
  return uVar4;
}



/* 0001c768 FUN_0001c768 */

/* Boundary evidence: original MIPS .pdata 0001c768..0001c887. Semantic name remains unreviewed. */

undefined4 FUN_0001c768(int param_1)

{
  uint *puVar1;
  int iVar2;
  void *_Dst;
  uint uVar3;
  
  if (param_1 != 0) {
    uVar3 = 0x18;
    puVar1 = operator_new(0x18);
    if (puVar1 != (uint *)0x0) {
      do {
        *puVar1 = uVar3;
        iVar2 = RasDevConfigDialogEditW
                          (param_1 + 0x79a,param_1 + 0x778,0,*(undefined4 *)(param_1 + 0xdb4),
                           *(undefined4 *)(param_1 + 0xdb8),puVar1);
        if (iVar2 != 0) {
LAB_0001c85c:
          operator_delete(puVar1);
          return 0;
        }
        uVar3 = puVar1[1];
        if (uVar3 <= *puVar1) {
          if (*(void **)(param_1 + 0xdb4) != (void *)0x0) {
            operator_delete(*(void **)(param_1 + 0xdb4));
            *(undefined4 *)(param_1 + 0xdb4) = 0;
            *(undefined4 *)(param_1 + 0xdb8) = 0;
          }
          _Dst = operator_new(puVar1[4]);
          *(void **)(param_1 + 0xdb4) = _Dst;
          if (_Dst != (void *)0x0) {
            memcpy(_Dst,(void *)(puVar1[5] + (int)puVar1),puVar1[4]);
            *(uint *)(param_1 + 0xdb8) = puVar1[4];
          }
          goto LAB_0001c85c;
        }
        operator_delete(puVar1);
        puVar1 = operator_new(uVar3);
      } while (puVar1 != (uint *)0x0);
    }
  }
  return 0;
}



/* 0001c888 FUN_0001c888 */

/* Boundary evidence: original MIPS .pdata 0001c888..0001c8af. Semantic name remains unreviewed. */

void FUN_0001c888(int param_1,undefined4 param_2,wchar_t *param_3,int param_4)

{
  wcsncpy(param_3,(wchar_t *)(param_1 + 0x79a),param_4 - 1);
  return;
}



/* 0001c8b0 FUN_0001c8b0 */

/* Boundary evidence: original MIPS .pdata 0001c8b0..0001c923. Semantic name remains unreviewed. */

undefined4 FUN_0001c8b0(int param_1,HINSTANCE param_2,LPWSTR param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  UINT uID;
  
  if (param_3 == (LPWSTR)0x0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x1900;
    }
    uVar1 = 0;
  }
  else {
    uVar2 = FUN_0001c5fc(param_1);
    uID = 0x1847;
    if (uVar2 == 0) {
      uID = 0x1839;
    }
    LoadStringW(param_2,uID,param_3,0x80);
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001c924 FUN_0001c924 */

/* Boundary evidence: original MIPS .pdata 0001c924..0001ca1b. Semantic name remains unreviewed. */

undefined4 FUN_0001c924(HWND param_1,undefined4 *param_2)

{
  int iVar1;
  LONG LVar2;
  LRESULT LVar3;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  WCHAR local_58;
  undefined1 auStack_56 [62];
  uint local_18;
  
  local_18 = DAT_00023314;
  local_58 = L'\0';
  memset(auStack_56,0,0x3e);
  GetClassNameW(param_1,&local_58,0x20);
  iVar1 = wcscmp(&local_58,L"Dialog");
  if ((iVar1 == 0) && (LVar2 = GetWindowLongW(param_1,8), LVar2 == 0x6a6d6d)) {
    local_64 = 0x2a;
    local_68 = 0;
    local_60 = DAT_000239d4;
    SendMessageW(param_1,0x4a,0,(LPARAM)&local_68);
    LVar3 = SendMessageW(param_1,0x4ca,0,0);
    if (LVar3 == 0) {
      *param_2 = param_1;
      FUN_000219a0(local_18);
      return 0;
    }
  }
  FUN_000219a0(local_18);
  return 1;
}



/* 0001ca1c FUN_0001ca1c */

/* Boundary evidence: original MIPS .pdata 0001ca1c..0001cb4b. Semantic name remains unreviewed. */

undefined4 FUN_0001ca1c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  uint uVar1;
  BOOL BVar2;
  HWND local_58 [2];
  wchar_t awStack_50 [26];
  uint local_1c;
  
  local_1c = DAT_00023314;
  uVar1 = FUN_0001c5fc(param_1);
  if (uVar1 == 0) {
    StringCchPrintfW(awStack_50,0x19,L"-e\"%s\"",*(undefined4 *)(param_1 + 4));
    BVar2 = CreateProcessW(L"rnaapp",awStack_50,(LPSECURITY_ATTRIBUTES)0x0,
                           (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                           (LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
    if (BVar2 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0x1901;
      }
      FUN_000219a0(local_1c);
      return 0;
    }
  }
  else {
    DAT_000239d4 = *(undefined4 *)(param_1 + 4);
    local_58[0] = (HWND)0x0;
    BVar2 = EnumWindows(FUN_0001c924,(LPARAM)local_58);
    if ((BVar2 == 0) || (local_58[0] == (HWND)0x0)) {
      RasHangUp(uVar1);
    }
    else {
      SetForegroundWindow(local_58[0]);
      ShowWindow(local_58[0],1);
    }
  }
  FUN_000219a0(local_1c);
  return 1;
}



/* 0001cb4c FUN_0001cb4c */

/* Boundary evidence: original MIPS .pdata 0001cb4c..0001cbd7. Semantic name remains unreviewed. */

undefined4 FUN_0001cb4c(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = RasDeleteEntry(0,param_1[1]);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x44))(param_1);
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0x40))(param_1,0,0);
    }
    uVar2 = 1;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x1900;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 0001cbd8 FUN_0001cbd8 */

/* Boundary evidence: original MIPS .pdata 0001cbd8..0001cd87. Semantic name remains unreviewed. */

undefined4 FUN_0001cbd8(int *param_1,wchar_t *param_2,int *param_3)

{
  size_t sVar1;
  wchar_t *_Dest;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if (param_2 == (wchar_t *)0x0) {
    if (param_3 == (int *)0x0) {
      return 0;
    }
    iVar3 = 0x1909;
  }
  else {
    iVar3 = _wcsicmp(param_2,(wchar_t *)param_1[1]);
    if (iVar3 != 0) {
      if ((param_3 != (int *)0x0) && (FUN_0001384c(param_2,param_3), *param_3 != 0)) {
        return 0;
      }
      iVar3 = RasValidateEntryName(0,param_2);
      if (iVar3 != 0) {
        if (param_3 == (int *)0x0) {
          return 0;
        }
        if (iVar3 == 0xb7) {
          *param_3 = 0x190a;
          return 0;
        }
        *param_3 = 0x190b;
        return 0;
      }
    }
    iVar3 = RasRenameEntry(0,param_1[1],param_2);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*param_1 + 0x44))(param_1);
      pvVar4 = (void *)param_1[1];
      sVar1 = wcslen(param_2);
      if (sVar1 + 1 < 0x80000000) {
        uVar2 = (sVar1 + 1) * 2;
      }
      else {
        uVar2 = 0xffffffff;
      }
      _Dest = operator_new(uVar2);
      param_1[1] = (int)_Dest;
      if (_Dest != (wchar_t *)0x0) {
        wcscpy(_Dest,param_2);
        if (iVar3 != 0) {
          (**(code **)(*param_1 + 0x40))(param_1,1,0);
        }
        if (pvVar4 != (void *)0x0) {
          operator_delete(pvVar4);
          return 1;
        }
        return 1;
      }
      param_1[1] = (int)pvVar4;
      if (param_3 == (int *)0x0) {
        return 0;
      }
      iVar3 = 0x1901;
    }
    else {
      if (param_3 == (int *)0x0) {
        return 0;
      }
      iVar3 = 0x1900;
    }
  }
  *param_3 = iVar3;
  return 0;
}



/* 0001cd88 FUN_0001cd88 */

/* Boundary evidence: original MIPS .pdata 0001cd88..0001cfaf. Semantic name remains unreviewed. */

undefined4 FUN_0001cd88(int param_1,HINSTANCE param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  uint uVar4;
  uint local_e08;
  undefined4 local_e04;
  undefined4 local_e00;
  undefined1 auStack_dfc [3468];
  wchar_t local_70;
  undefined1 auStack_6e [46];
  WCHAR local_40;
  undefined1 auStack_3e [42];
  uint local_14;
  
  local_14 = DAT_00023314;
  if (*(int *)(param_1 + 4) == 0) {
    if (param_3 != (undefined4 *)0x0) {
      uVar2 = 0x190e;
LAB_0001cdcc:
      *param_3 = uVar2;
    }
LAB_0001cdd0:
    FUN_000219a0(local_14);
    uVar2 = 0;
  }
  else {
    local_70 = L'\0';
    memset(auStack_6e,0,0x28);
    local_40 = L'\0';
    memset(auStack_3e,0,0x28);
    LoadStringW(param_2,0x183c,&local_40,0x15);
    _snwprintf(&local_70,0x14,L"%s %s",&local_40,*(undefined4 *)(param_1 + 4));
    iVar1 = RasValidateEntryName(0,&local_70);
    if (iVar1 != 0) {
      LoadStringW(param_2,0x183d,&local_40,0x15);
      uVar4 = 2;
      do {
        if (99 < uVar4) {
          if (param_3 == (undefined4 *)0x0) goto LAB_0001cdd0;
          uVar2 = 0x1900;
          goto LAB_0001cdcc;
        }
        StringCchPrintfW(&local_70,0x14,&local_40,uVar4,*(undefined4 *)(param_1 + 4));
        uVar4 = uVar4 + 1;
        iVar1 = RasValidateEntryName(0,&local_70);
      } while (iVar1 != 0);
    }
    memset(auStack_dfc,0,0xd8c);
    local_e00 = 0xd90;
    local_e04 = 0xd90;
    local_e08 = 0;
    pvVar3 = (void *)0x0;
    iVar1 = RasGetEntryProperties(0,*(undefined4 *)(param_1 + 4),&local_e00,&local_e04,0,&local_e08)
    ;
    if (((local_e08 != 0) && (iVar1 == 0x25b)) &&
       (pvVar3 = operator_new(local_e08), pvVar3 != (void *)0x0)) {
      RasGetEntryProperties(0,*(undefined4 *)(param_1 + 4),&local_e00,&local_e04,pvVar3,&local_e08);
    }
    RasSetEntryProperties(0,&local_70,&local_e00,local_e04,pvVar3,local_e08);
    RasSetEapConnectionData
              (0,&local_70,*(undefined4 *)(param_1 + 0xdac),*(undefined4 *)(param_1 + 0xdb0));
    if (pvVar3 != (void *)0x0) {
      operator_delete(pvVar3);
    }
    FUN_000219a0(local_14);
    uVar2 = 1;
  }
  return uVar2;
}



/* 0001cfb0 FUN_0001cfb0 */

/* Boundary evidence: original MIPS .pdata 0001cfb0..0001d183. Semantic name remains unreviewed. */

undefined4 FUN_0001cfb0(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  LSTATUS LVar2;
  size_t sVar3;
  wchar_t *_Str;
  HKEY local_20 [2];
  
  iVar1 = (**(code **)(*param_1 + 0x44))(param_1);
  if (param_1[1] == 0) {
    if (param_3 == (undefined4 *)0x0) {
      return 0;
    }
    *param_3 = 0x190e;
    return 0;
  }
  if (iVar1 == 0) {
    if (param_2 == 0) {
      return 1;
    }
    local_20[0] = (HKEY)0x0;
    LVar2 = RegCreateKeyExW((HKEY)0x80000002,L"Comm\\Autoras",0,(LPWSTR)0x0,0,0x20006,
                            (LPSECURITY_ATTRIBUTES)0x0,local_20,(LPDWORD)0x0);
    if (LVar2 == 0) {
      _Str = (wchar_t *)param_1[1];
      sVar3 = wcslen(_Str);
      LVar2 = RegSetValueExW(local_20[0],L"RasEntry",0,1,(BYTE *)_Str,(sVar3 + 1) * 2);
      if (LVar2 == 0) {
        iVar1 = 1;
      }
LAB_0001d11c:
      RegCloseKey(local_20[0]);
      goto LAB_0001d12c;
    }
  }
  else {
    if (param_2 == 0) {
      local_20[0] = (HKEY)0x0;
      LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Autoras",0,0x20006,local_20);
      if (LVar2 == 0) {
        LVar2 = RegDeleteValueW(local_20[0],L"RasEntry");
        if (LVar2 == 0) {
          iVar1 = 0;
        }
        goto LAB_0001d11c;
      }
    }
LAB_0001d12c:
    if (iVar1 != 0) {
      if (param_2 != 0) {
        return 1;
      }
      goto LAB_0001d14c;
    }
  }
  if (param_2 == 0) {
    return 1;
  }
LAB_0001d14c:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0x1900;
  }
  return 0;
}



/* 0001d184 FUN_0001d184 */

/* Boundary evidence: original MIPS .pdata 0001d184..0001d283. Semantic name remains unreviewed. */

undefined4 FUN_0001d184(int param_1)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 uVar3;
  HKEY local_220;
  DWORD local_21c;
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00023314;
  uVar3 = 0;
  if (*(int *)(param_1 + 4) == 0) {
    FUN_000219a0(DAT_00023314);
    uVar3 = 0;
  }
  else {
    local_220 = (HKEY)0x0;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Autoras",0,0x20019,&local_220);
    if (LVar1 == 0) {
      local_21c = 0xff;
      LVar1 = RegQueryValueExW(local_220,L"RasEntry",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)awStack_218,
                               &local_21c);
      if (LVar1 == 0) {
        iVar2 = wcscmp(awStack_218,*(wchar_t **)(param_1 + 4));
        uVar3 = 1;
        if (iVar2 != 0) {
          uVar3 = 0;
        }
      }
      RegCloseKey(local_220);
    }
    FUN_000219a0(local_18);
  }
  return uVar3;
}



/* 0001d284 FUN_0001d284 */

/* Boundary evidence: original MIPS .pdata 0001d284..0001d527. Semantic name remains unreviewed. */

undefined4 FUN_0001d284(int param_1,HINSTANCE param_2,undefined4 *param_3)

{
  HANDLE hFile;
  wchar_t *_String;
  undefined4 uVar1;
  wchar_t *_Format;
  size_t local_550 [2];
  wchar_t local_548;
  undefined1 auStack_546 [518];
  CHAR local_340;
  undefined1 auStack_33f [263];
  WCHAR local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_00023314;
  if (*(int *)(param_1 + 4) == 0) {
LAB_0001d2d4:
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0x1903;
    }
    FUN_000219a0(local_30);
    uVar1 = 0;
  }
  else {
    local_548 = L'\0';
    memset(auStack_546,0,0x206);
    local_238 = L'\0';
    memset(auStack_236,0,0x206);
    LoadStringW(param_2,0x1778,&local_238,0x104);
    StringCchPrintfW(&local_548,0x104,&local_238,*(undefined4 *)(param_1 + 4));
    StringCchCatW(&local_548,0x104,L".lnk");
    uVar1 = 1;
    hFile = CreateFileW(&local_548,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,1,0x80,(HANDLE)0x0);
    if (hFile == (HANDLE)0xffffffff) {
      _Format = (wchar_t *)0x2;
      _String = wcsstr(&local_548,L".lnk");
      do {
        if ((wchar_t *)0x63 < _Format) goto LAB_0001d2d4;
        swprintf(_String,0x11cc4,_Format);
        hFile = CreateFileW(&local_548,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,1,0x80,(HANDLE)0x0);
        _Format = (wchar_t *)((int)_Format + 1);
      } while (hFile == (HANDLE)0xffffffff);
    }
    LoadStringW(param_2,0x1779,&local_238,0x104);
    StringCchPrintfW(&local_548,0x104,&local_238,*(undefined4 *)(param_1 + 4));
    local_550[0] = wcslen(&local_548);
    StringCchPrintfW(&local_238,0x104,L"%u#%s",local_550[0],&local_548);
    local_340 = '\0';
    memset(auStack_33f,0,0x103);
    local_550[0] = WideCharToMultiByte(0,0,&local_238,-1,&local_340,0x104,(LPCSTR)0x0,(LPBOOL)0x0);
    WriteFile(hFile,&local_340,local_550[0],local_550,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
    FUN_000219a0(local_30);
  }
  return uVar1;
}



/* 0001d528 FUN_0001d528 */

/* Boundary evidence: original MIPS .pdata 0001d528..0001d683. Semantic name remains unreviewed. */

undefined4
FUN_0001d528(int *param_1,int param_2,HINSTANCE param_3,STRSAFE_LPWSTR param_4,size_t param_5,
            undefined4 *param_6)

{
  uint uVar1;
  int iVar2;
  UINT uID;
  STRSAFE_LPCWSTR pszSrc;
  undefined1 auStack_148 [4];
  int local_144;
  uint local_18;
  
  uVar1 = DAT_00023314;
  local_18 = DAT_00023314;
  if (param_4 == (STRSAFE_LPWSTR)0x0) {
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 0x1900;
    }
    FUN_000219a0(uVar1);
    return 0;
  }
  if (param_2 == 0) {
    pszSrc = (STRSAFE_LPCWSTR)param_1[1];
  }
  else {
    if (param_2 == 1) {
      (**(code **)(*param_1 + 0x58))(param_1,param_3,param_4,param_5);
      goto LAB_0001d63c;
    }
    if (param_2 == 2) {
      uVar1 = FUN_0001c5fc((int)param_1);
      if ((uVar1 == 0) || (iVar2 = RasGetConnectStatus(uVar1,auStack_148), iVar2 != 0)) {
LAB_0001d5f8:
        uID = 0x1845;
      }
      else if (local_144 == 0x2000) {
        uID = 0x1844;
      }
      else {
        if (local_144 == 0x2001) goto LAB_0001d5f8;
        uID = 0x1838;
      }
      LoadStringW(param_3,uID,param_4,param_5);
      goto LAB_0001d63c;
    }
    if (param_2 != 3) {
      *param_4 = L'\0';
      goto LAB_0001d63c;
    }
    pszSrc = (STRSAFE_LPCWSTR)((int)param_1 + 0x79a);
  }
  StringCchCopyW(param_4,param_5,pszSrc);
LAB_0001d63c:
  FUN_000219a0(local_18);
  return 1;
}



/* 0001d684 FUN_0001d684 */

/* Boundary evidence: original MIPS .pdata 0001d684..0001d837. Semantic name remains unreviewed. */

undefined4 * FUN_0001d684(wchar_t *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_db0 [2];
  undefined4 local_da8;
  undefined1 auStack_da4 [1888];
  wchar_t awStack_644 [17];
  wchar_t awStack_622 [773];
  uint local_18;
  
  local_18 = DAT_00023314;
  if (param_1 == (wchar_t *)0x0) {
LAB_0001d814:
    FUN_000219a0(local_18);
    return (undefined4 *)0x0;
  }
  memset(auStack_da4,0,0xd8c);
  local_da8 = 0xd90;
  local_db0[0] = 0xd90;
  iVar1 = RasGetEntryProperties(0,param_1,&local_da8,local_db0,0,0);
  if (iVar1 != 0) goto LAB_0001d814;
  iVar1 = wcscmp(L"modem",awStack_644);
  if (iVar1 == 0) {
    puVar2 = operator_new(0xdbc);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2 = FUN_00016204(puVar2,param_1);
      goto LAB_0001d72c;
    }
  }
  else {
    iVar1 = wcscmp(L"direct",awStack_644);
    if (iVar1 == 0) {
      puVar2 = operator_new(0xdbc);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2 = FUN_000172b0(puVar2,param_1);
        goto LAB_0001d72c;
      }
    }
    else {
      iVar1 = wcscmp(L"vpn",awStack_644);
      if (iVar1 == 0) {
        iVar1 = wcsncmp(awStack_622,L"L2TP Line",9);
        puVar2 = operator_new(0xdc0);
        if (puVar2 != (undefined4 *)0x0) {
          puVar2 = FUN_000179d4(puVar2,param_1,(uint)(iVar1 == 0));
          goto LAB_0001d72c;
        }
      }
      else {
        iVar1 = wcscmp(L"PPPoE",awStack_644);
        if (iVar1 != 0) goto LAB_0001d814;
        puVar2 = operator_new(0xdbc);
        if (puVar2 != (undefined4 *)0x0) {
          puVar2 = FUN_0001a828(puVar2,param_1);
          goto LAB_0001d72c;
        }
      }
    }
  }
  puVar2 = (undefined4 *)0x0;
LAB_0001d72c:
  FUN_000219a0(local_18);
  return puVar2;
}



/* 0001d838 FUN_0001d838 */

/* Boundary evidence: original MIPS .pdata 0001d838..0001d91b. Semantic name remains unreviewed. */

undefined4 FUN_0001d838(HINSTANCE param_1,wchar_t *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  wchar_t local_40;
  undefined1 auStack_3e [42];
  uint local_14;
  
  local_14 = DAT_00023314;
  if (param_2 == (wchar_t *)0x0) {
    FUN_000219a0(DAT_00023314);
    uVar1 = 0;
  }
  else {
    LoadStringW(param_1,0x183b,param_2,0x15);
    iVar2 = RasValidateEntryName(0,param_2);
    if (iVar2 != 0) {
      local_40 = L'\0';
      memset(auStack_3e,0,0x28);
      iVar2 = 2;
      do {
        _snwprintf(&local_40,0x14,L"%s %u",param_2,iVar2);
        iVar2 = iVar2 + 1;
        iVar3 = RasValidateEntryName(0,&local_40);
      } while (iVar3 != 0);
      wcsncpy(param_2,&local_40,0x14);
    }
    FUN_000219a0(local_14);
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001d91c FUN_0001d91c */

/* Boundary evidence: original MIPS .pdata 0001d91c..0001d9a7. Semantic name remains unreviewed. */

undefined4 FUN_0001d91c(undefined4 *param_1)

{
  DWORD DVar1;
  undefined4 *puVar2;
  DWORD local_10;
  DWORD local_c;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    local_c = 0;
    local_10 = 0;
    DVar1 = RasEnumDevicesW((tagRASDEVINFOW *)0x0,&local_c,&local_10);
    if (DVar1 != 0) {
      return local_10;
    }
    if (local_c == 0) {
      return local_10;
    }
    puVar2 = operator_new(local_c);
    *param_1 = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 0x128;
      RasEnumDevicesW((tagRASDEVINFOW *)*param_1,&local_c,&local_10);
      return local_10;
    }
  }
  return 0;
}



/* 0001d9a8 FUN_0001d9a8 */

/* Boundary evidence: original MIPS .pdata 0001d9a8..0001daa3. Semantic name remains unreviewed. */

undefined4 FUN_0001d9a8(wchar_t *param_1,wchar_t *param_2)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  size_t _MaxCount;
  undefined4 uVar4;
  wchar_t *_Str1;
  uint uVar5;
  void *local_28 [2];
  
  uVar4 = 0;
  if (param_1 != (wchar_t *)0x0) {
    local_28[0] = (void *)0x0;
    uVar2 = FUN_0001d91c(local_28);
    pvVar1 = local_28[0];
    if ((uVar2 == 0) || (local_28[0] == (void *)0x0)) {
      uVar4 = 0;
    }
    else {
      uVar5 = 0;
      if (uVar2 != 0) {
        _Str1 = (wchar_t *)((int)local_28[0] + 4);
        do {
          iVar3 = wcscmp(_Str1,param_1);
          if (iVar3 == 0) {
            if (param_2 != (wchar_t *)0x0) {
              _MaxCount = wcslen(param_2);
              iVar3 = wcsncmp(_Str1 + 0x11,param_2,_MaxCount);
              if (iVar3 != 0) goto LAB_0001da48;
            }
            uVar4 = 1;
            break;
          }
LAB_0001da48:
          uVar5 = uVar5 + 1;
          _Str1 = _Str1 + 0x94;
        } while (uVar5 < uVar2);
      }
      operator_delete(pvVar1);
    }
  }
  return uVar4;
}



/* 0001daac FUN_0001daac */

/* Boundary evidence: original MIPS .pdata 0001daac..0001db83. Semantic name remains unreviewed. */

LPLINETRANSLATECAPS FUN_0001daac(HINSTANCE param_1)

{
  LONG LVar1;
  LPLINETRANSLATECAPS lpTranslateCaps;
  SIZE_T uBytes;
  HLINEAPP local_18;
  DWORD local_14;
  
  local_18 = 0;
  local_14 = 0;
  uBytes = 0x2c;
  LVar1 = lineInitialize(&local_18,param_1,(LINECALLBACK)&LAB_0001daa4,(LPCSTR)0x0,&local_14);
  if (LVar1 == 0) {
    while (lpTranslateCaps = LocalAlloc(0x40,uBytes), lpTranslateCaps != (LPLINETRANSLATECAPS)0x0) {
      lpTranslateCaps->dwTotalSize = uBytes;
      LVar1 = lineGetTranslateCaps(local_18,0x20000,lpTranslateCaps);
      if (LVar1 != 0) {
        LocalFree(lpTranslateCaps);
        lpTranslateCaps = (LPLINETRANSLATECAPS)0x0;
        break;
      }
      uBytes = lpTranslateCaps->dwNeededSize;
      if (uBytes <= lpTranslateCaps->dwTotalSize) break;
      LocalFree(lpTranslateCaps);
    }
    lineShutdown(local_18);
  }
  else {
    lpTranslateCaps = (LPLINETRANSLATECAPS)0x0;
  }
  return lpTranslateCaps;
}



/* 0001db84 FUN_0001db84 */

int FUN_0001db84(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
    iVar3 = *(int *)(param_1 + 0xc);
    piVar2 = (int *)(*(int *)(param_1 + 0x14) + param_1);
    if (0 < iVar3) {
      do {
        if (*piVar2 == *(int *)(param_1 + 0x18)) {
          iVar1 = piVar2[3];
        }
        iVar3 = iVar3 + -1;
        piVar2 = piVar2 + 0x11;
      } while (iVar3 != 0);
    }
  }
  return iVar1;
}



/* 0001dbd0 FUN_0001dbd0 */

/* Boundary evidence: original MIPS .pdata 0001dbd0..0001dc7f. Semantic name remains unreviewed. */

void FUN_0001dbd0(int param_1,wchar_t *param_2,size_t param_3)

{
  int *piVar1;
  int iVar2;
  
  if (((param_2 != (wchar_t *)0x0) && (*param_2 = L'\0', param_1 != 0)) &&
     (*(int *)(param_1 + 0x10) != 0)) {
    piVar1 = (int *)(*(int *)(param_1 + 0x14) + param_1);
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0xc)) {
      do {
        if (*piVar1 == *(int *)(param_1 + 0x18)) {
          wcsncpy(param_2,(wchar_t *)(piVar1[5] + param_1),param_3);
        }
        iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 0x11;
      } while (iVar2 < *(int *)(param_1 + 0xc));
    }
  }
  return;
}



/* 0001dc80 FUN_0001dc80 */

/* Boundary evidence: original MIPS .pdata 0001dc80..0001dcf7. Semantic name remains unreviewed. */

undefined4 FUN_0001dc80(wchar_t *param_1)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == (wchar_t *)0x0) {
LAB_0001dcdc:
    uVar2 = 0;
  }
  else {
    uVar3 = 0;
    do {
      pwVar1 = wcschr(param_1,*(wchar_t *)((int)&DAT_00011bc8 + uVar3));
      if (pwVar1 != (wchar_t *)0x0) goto LAB_0001dcdc;
      uVar3 = uVar3 + 2;
    } while (uVar3 < 0x10);
    uVar2 = 1;
  }
  return uVar2;
}



/* 0001dcf8 FUN_0001dcf8 */

/* Boundary evidence: original MIPS .pdata 0001dcf8..0001e217. Semantic name remains unreviewed. */

undefined4 FUN_0001dcf8(HWND param_1,int param_2,short param_3,int param_4)

{
  LONG LVar1;
  HWND pHVar2;
  LRESULT LVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  LVar1 = GetWindowLongW(param_1,-0x15);
  iVar5 = 0;
  if (LVar1 != 0) {
    iVar5 = *(int *)(LVar1 + 0x1c);
  }
  uVar6 = 1;
  if (param_2 == 0x4e) {
    if (*(int *)(param_4 + 8) == -0xca) {
      if (iVar5 == 0) goto LAB_0001e124;
      SendDlgItemMessageW(param_1,0x13a1,0x466,0,iVar5 + 0x144);
      SendDlgItemMessageW(param_1,0x13a2,0x466,0,iVar5 + 0x148);
      SendDlgItemMessageW(param_1,0x13a3,0x466,0,iVar5 + 0x14c);
      SendDlgItemMessageW(param_1,0x13a4,0x466,0,iVar5 + 0x150);
      LVar3 = SendDlgItemMessageW(param_1,0x139c,0xf0,0,0);
      if (LVar3 == 1) {
        *(uint *)(iVar5 + 0x18) = *(uint *)(iVar5 + 0x18) & 0xfffffffb;
      }
      else {
        *(uint *)(iVar5 + 0x18) = *(uint *)(iVar5 + 0x18) | 4;
      }
    }
    SetWindowLongW(param_1,0,0);
  }
  else {
    if (param_2 == 0x110) {
      SetWindowLongW(param_1,-0x15,param_4);
      iVar5 = *(int *)(param_4 + 0x1c);
      pHVar2 = GetParent(param_1);
      uVar4 = GetWindowLongW(pHVar2,-0x14);
      pHVar2 = GetParent(param_1);
      SetWindowLongW(pHVar2,-0x14,uVar4 | 0x40000000);
      pHVar2 = GetDlgItem(param_1,0x138c);
      SetWindowTextW(pHVar2,*(LPCWSTR *)(iVar5 + 4));
      if ((*(uint *)(iVar5 + 0x18) & 4) != 0) {
        SendDlgItemMessageW(param_1,0x139c,0xf1,0,0);
        SendDlgItemMessageW(param_1,0x13a1,0x465,0,*(LPARAM *)(iVar5 + 0x144));
        SendDlgItemMessageW(param_1,0x13a2,0x465,0,*(LPARAM *)(iVar5 + 0x148));
        SendDlgItemMessageW(param_1,0x13a3,0x465,0,*(LPARAM *)(iVar5 + 0x14c));
        SendDlgItemMessageW(param_1,0x13a4,0x465,0,*(LPARAM *)(iVar5 + 0x150));
        return 1;
      }
      SendDlgItemMessageW(param_1,0x139c,0xf1,1,0);
      pHVar2 = GetDlgItem(param_1,0x139d);
      EnableWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x13a1);
      EnableWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x139e);
      EnableWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x13a2);
      EnableWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x139f);
      EnableWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x13a3);
      EnableWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x13a0);
      EnableWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x13a4);
      EnableWindow(pHVar2,0);
      return 1;
    }
    if (param_2 == 0x111) {
      if (param_3 != 0x139c) {
        return 1;
      }
      pHVar2 = GetDlgItem(param_1,0x139c);
      LVar3 = SendMessageW(pHVar2,0xf0,0,0);
      uVar4 = (uint)(LVar3 != 1);
      pHVar2 = GetDlgItem(param_1,0x139d);
      EnableWindow(pHVar2,uVar4);
      pHVar2 = GetDlgItem(param_1,0x13a1);
      EnableWindow(pHVar2,uVar4);
      pHVar2 = GetDlgItem(param_1,0x139e);
      EnableWindow(pHVar2,uVar4);
      pHVar2 = GetDlgItem(param_1,0x13a2);
      EnableWindow(pHVar2,uVar4);
      pHVar2 = GetDlgItem(param_1,0x139f);
      EnableWindow(pHVar2,uVar4);
      pHVar2 = GetDlgItem(param_1,0x13a3);
      EnableWindow(pHVar2,uVar4);
      pHVar2 = GetDlgItem(param_1,0x13a0);
      EnableWindow(pHVar2,uVar4);
      pHVar2 = GetDlgItem(param_1,0x13a4);
      EnableWindow(pHVar2,uVar4);
      if (uVar4 != 0) {
        SendDlgItemMessageW(param_1,0x13a1,0x465,0,*(LPARAM *)(iVar5 + 0x144));
        SendDlgItemMessageW(param_1,0x13a2,0x465,0,*(LPARAM *)(iVar5 + 0x148));
        SendDlgItemMessageW(param_1,0x13a3,0x465,0,*(LPARAM *)(iVar5 + 0x14c));
        SendDlgItemMessageW(param_1,0x13a4,0x465,0,*(LPARAM *)(iVar5 + 0x150));
        return 1;
      }
      SendDlgItemMessageW(param_1,0x13a1,0x464,0,0);
      SendDlgItemMessageW(param_1,0x13a2,0x464,0,0);
      SendDlgItemMessageW(param_1,0x13a3,0x464,0,0);
      SendDlgItemMessageW(param_1,0x13a4,0x464,0,0);
      return 1;
    }
LAB_0001e124:
    uVar6 = 0;
  }
  return uVar6;
}



/* 0001e218 FUN_0001e218 */

/* Boundary evidence: original MIPS .pdata 0001e218..0001e2bf. Semantic name remains unreviewed. */

undefined4 FUN_0001e218(int param_1,void *param_2,uint param_3)

{
  HLOCAL _Dst;
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_3 < 0x20001) {
    LocalFree(*(HLOCAL *)(param_1 + 0xdac));
    *(undefined4 *)(param_1 + 0xdac) = 0;
    *(undefined4 *)(param_1 + 0xdb0) = 0;
    if (param_3 != 0) {
      _Dst = LocalAlloc(0x40,param_3);
      *(HLOCAL *)(param_1 + 0xdac) = _Dst;
      if (_Dst == (HLOCAL)0x0) {
        uVar1 = 0xe;
      }
      else {
        *(uint *)(param_1 + 0xdb0) = param_3;
        memcpy(_Dst,param_2,param_3);
      }
    }
  }
  else {
    uVar1 = 0x57;
  }
  return uVar1;
}



/* 0001e2c0 FUN_0001e2c0 */

/* Boundary evidence: original MIPS .pdata 0001e2c0..0001e34f. Semantic name remains unreviewed. */

int FUN_0001e2c0(int param_1)

{
  int iVar1;
  HLOCAL pvVar2;
  SIZE_T local_10 [2];
  
  LocalFree(*(HLOCAL *)(param_1 + 0xdac));
  *(undefined4 *)(param_1 + 0xdac) = 0;
  *(undefined4 *)(param_1 + 0xdb0) = 0;
  local_10[0] = 0;
  iVar1 = RasGetEapConnectionData(0,*(undefined4 *)(param_1 + 4),0,local_10);
  if ((iVar1 == 0) && (local_10[0] != 0)) {
    pvVar2 = LocalAlloc(0x40,local_10[0]);
    *(HLOCAL *)(param_1 + 0xdac) = pvVar2;
    if (pvVar2 == (HLOCAL)0x0) {
      iVar1 = 0xe;
    }
    else {
      *(SIZE_T *)(param_1 + 0xdb0) = local_10[0];
      iVar1 = RasGetEapConnectionData(0,*(undefined4 *)(param_1 + 4),pvVar2,local_10);
    }
  }
  return iVar1;
}



/* 0001e350 FUN_0001e350 */

/* Boundary evidence: original MIPS .pdata 0001e350..0001e3ff. Semantic name remains unreviewed. */

int FUN_0001e350(int param_1)

{
  int iVar1;
  HLOCAL pvVar2;
  undefined4 *puVar3;
  uint local_18 [2];
  
  iVar1 = 0;
  local_18[0] = 0;
  if (*(int *)(param_1 + 0xda4) == 0) {
    puVar3 = (undefined4 *)(param_1 + 0xda8);
    *puVar3 = 0;
    iVar1 = FUN_00021410(0,0,puVar3,local_18);
    while (iVar1 == 0x7a) {
      LocalFree(*(HLOCAL *)(param_1 + 0xda4));
      pvVar2 = LocalAlloc(0x40,local_18[0]);
      *(HLOCAL *)(param_1 + 0xda4) = pvVar2;
      if (pvVar2 == (HLOCAL)0x0) {
        *puVar3 = 0;
        return 0xe;
      }
      iVar1 = FUN_00021410(local_18[0],pvVar2,puVar3,local_18);
    }
  }
  return iVar1;
}



/* 0001e400 FUN_0001e400 */

/* Boundary evidence: original MIPS .pdata 0001e400..0001e557. Semantic name remains unreviewed. */

undefined4 FUN_0001e400(int param_1,HWND param_2,int param_3)

{
  bool bVar1;
  int *lParam;
  HWND hWnd;
  WPARAM wParam;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  bVar1 = false;
  FUN_0001e350(param_1);
  lParam = LocalAlloc(0x40,*(int *)(param_1 + 0xda8) << 3);
  if (lParam == (int *)0x0) {
    LocalFree((HLOCAL)0x0);
    uVar2 = 0;
  }
  else {
    hWnd = GetDlgItem(param_2,0x13af);
    piVar4 = *(int **)(param_1 + 0xda4);
    iVar3 = 0;
    uVar2 = 1;
    if (0 < *(int *)(param_1 + 0xda8)) {
      do {
        wParam = SendMessageW(hWnd,0x143,0,(LPARAM)(piVar4 + 0x209));
        *lParam = iVar3;
        lParam[1] = (int)piVar4;
        SendMessageW(hWnd,0x151,wParam,(LPARAM)lParam);
        if (*(int *)(param_3 + 0xda0) == *piVar4) {
          SendMessageW(hWnd,0x14e,wParam,0);
          bVar1 = true;
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 0x312;
        lParam = lParam + 2;
      } while (iVar3 < *(int *)(param_1 + 0xda8));
      if (bVar1) {
        return 1;
      }
    }
    SendMessageW(hWnd,0x14e,0,0);
  }
  return uVar2;
}



/* 0001e558 FUN_0001e558 */

/* Boundary evidence: original MIPS .pdata 0001e558..0001e5cf. Semantic name remains unreviewed. */

LRESULT FUN_0001e558(HWND param_1)

{
  HWND hWnd;
  WPARAM wParam;
  LRESULT LVar1;
  
  hWnd = GetDlgItem(param_1,0x13af);
  wParam = SendMessageW(hWnd,0x147,0,0);
  if (((wParam == 0xffffffff) || (LVar1 = SendMessageW(hWnd,0x150,wParam,0), LVar1 == 0)) ||
     (LVar1 == -1)) {
    LVar1 = 0;
  }
  return LVar1;
}



/* 0001e5d0 FUN_0001e5d0 */

/* Boundary evidence: original MIPS .pdata 0001e5d0..0001e683. Semantic name remains unreviewed. */

undefined4 FUN_0001e5d0(HWND param_1)

{
  LRESULT LVar1;
  HWND hWnd;
  short *psVar2;
  BOOL bEnable;
  undefined4 uVar3;
  
  bEnable = 0;
  LVar1 = SendDlgItemMessageW(param_1,0x13ae,0xf0,0,0);
  uVar3 = 1;
  if (LVar1 == 1) {
    LVar1 = FUN_0001e558(param_1);
    if (LVar1 != 0) {
      psVar2 = (short *)(*(int *)(LVar1 + 4) + 0x61c);
      if ((psVar2 == (short *)0x0) || (*psVar2 == 0)) {
        bEnable = 0;
      }
      else {
        bEnable = 1;
      }
    }
  }
  else {
    uVar3 = 0;
  }
  hWnd = GetDlgItem(param_1,0x13b0);
  EnableWindow(hWnd,bEnable);
  return uVar3;
}



/* 0001e684 FUN_0001e684 */

/* Boundary evidence: original MIPS .pdata 0001e684..0001e737. Semantic name remains unreviewed. */

void FUN_0001e684(HWND param_1)

{
  HWND hWnd;
  LRESULT LVar1;
  int *piVar2;
  WPARAM wParam;
  int *hMem;
  
  hMem = (int *)0x0;
  hWnd = GetDlgItem(param_1,0x13af);
  LVar1 = SendMessageW(hWnd,0x146,0,0);
  wParam = 0;
  if (0 < LVar1) {
    do {
      piVar2 = (int *)SendMessageW(hWnd,0x150,wParam,0);
      if (((piVar2 != (int *)0x0) && (piVar2 != (int *)0xffffffff)) && (*piVar2 == 0)) {
        hMem = piVar2;
      }
      wParam = wParam + 1;
    } while ((int)wParam < LVar1);
  }
  LocalFree(hMem);
  return;
}



/* 0001e738 FUN_0001e738 */

/* Boundary evidence: original MIPS .pdata 0001e738..0001e7a3. Semantic name remains unreviewed. */

void FUN_0001e738(undefined4 param_1,HWND param_2,int param_3)

{
  LRESULT LVar1;
  
  LVar1 = SendDlgItemMessageW(param_2,0x13ae,0xf0,0,0);
  if ((LVar1 == 1) && (LVar1 = FUN_0001e558(param_2), LVar1 != 0)) {
    *(undefined4 *)(param_3 + 0xda0) = **(undefined4 **)(LVar1 + 4);
  }
  return;
}



/* 0001e7a4 FUN_0001e7a4 */

/* Boundary evidence: original MIPS .pdata 0001e7a4..0001e82b. Semantic name remains unreviewed. */

void FUN_0001e7a4(HWND param_1,int param_2,uint *param_3)

{
  for (; *param_3 != 0; param_3 = param_3 + 3) {
    if (param_3[2] != (uint)((*(uint *)(param_2 + 0x18) & *param_3) != 0)) {
      SendDlgItemMessageW(param_1,param_3[1],0xf1,1,0);
    }
  }
  return;
}



/* 0001e82c FUN_0001e82c */

/* Boundary evidence: original MIPS .pdata 0001e82c..0001e90f. Semantic name remains unreviewed. */

void FUN_0001e82c(HWND param_1,int param_2,uint *param_3)

{
  LRESULT LVar1;
  uint uVar2;
  
  uVar2 = *param_3;
  while (uVar2 != 0) {
    LVar1 = SendDlgItemMessageW(param_1,param_3[1],0xf0,0,0);
    if (param_3[2] == (uint)(LVar1 == 1)) {
      *(uint *)(param_2 + 0x18) = ~*param_3 & *(uint *)(param_2 + 0x18);
    }
    else {
      *(uint *)(param_2 + 0x18) = *param_3 | *(uint *)(param_2 + 0x18);
    }
    param_3 = param_3 + 3;
    uVar2 = *param_3;
  }
  uVar2 = *(uint *)(param_2 + 0x18);
  if ((uVar2 & 0x1000) == 0) {
    *(uint *)(param_2 + 0x18) = uVar2 & 0xfffff7ff;
  }
  else {
    *(uint *)(param_2 + 0x18) = uVar2 | 0x800;
  }
  return;
}



/* 0001e910 FUN_0001e910 */

/* Boundary evidence: original MIPS .pdata 0001e910..0001ea7b. Semantic name remains unreviewed. */

undefined4 * FUN_0001e910(undefined4 *param_1,wchar_t *param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  wchar_t local_20 [2];
  undefined4 local_1c;
  
  FUN_00020d9c(param_1);
  puVar5 = param_1 + 0x36e;
  *param_1 = &PTR_FUN_00011bd8;
  param_1[0x36d] = 0;
  *puVar5 = 0;
  if (param_2 != (wchar_t *)0x0) {
    param_1[0x369] = 0;
    param_1[0x36a] = 0;
    param_1[0x36b] = 0;
    param_1[0x36c] = 0;
    local_20[0] = L'\0';
    sVar1 = wcslen(param_2);
    if (sVar1 + 1 < 0x80000000) {
      uVar4 = (sVar1 + 1) * 2;
    }
    else {
      uVar4 = 0xffffffff;
    }
    _Dest = operator_new(uVar4);
    param_1[1] = _Dest;
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,param_2);
      puVar6 = param_1 + 5;
      local_1c = 0xd90;
      *puVar6 = 0xd90;
      iVar2 = RasGetEntryProperties(0,param_2,puVar6,&local_1c,param_1[0x36d],puVar5);
      if (iVar2 == 0x26f) {
        param_2 = local_20;
        RasGetEntryProperties(0,local_20,puVar6,&local_1c,param_1[0x36d],puVar5);
      }
      if (*puVar5 != 0) {
        pvVar3 = operator_new(*puVar5);
        param_1[0x36d] = pvVar3;
        if (pvVar3 == (void *)0x0) {
          *puVar5 = 0;
        }
        else {
          RasGetEntryProperties(0,param_2,puVar6,&local_1c,pvVar3,puVar5);
        }
      }
      FUN_0001e2c0((int)param_1);
    }
  }
  return param_1;
}



/* 0001ea7c FUN_0001ea7c */

/* Boundary evidence: original MIPS .pdata 0001ea7c..0001eac7. Semantic name remains unreviewed. */

undefined4 * FUN_0001ea7c(undefined4 *param_1,uint param_2)

{
  FUN_0001c4a8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0001eac8 FUN_0001eac8 */

/* Boundary evidence: original MIPS .pdata 0001eac8..0001ebc7. Semantic name remains unreviewed. */

undefined4 * FUN_0001eac8(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x0;
  if ((DAT_000239c8 == (void *)0x0) || (DAT_000239cc == 0)) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    for (; DAT_000239d0 < DAT_000239cc; DAT_000239d0 = DAT_000239d0 + 1) {
      if (*(short *)((int)DAT_000239c8 + DAT_000239d0 * 0x30 + 4) != 0x60) {
        iVar1 = DAT_000239d0 * 0x30;
        DAT_000239d0 = DAT_000239d0 + 1;
        puVar2 = FUN_0001d684((wchar_t *)((int)DAT_000239c8 + iVar1 + 4));
        break;
      }
    }
    if (DAT_000239d0 == DAT_000239cc) {
      operator_delete(DAT_000239c8);
      DAT_000239c8 = (void *)0x0;
      DAT_000239d0 = 0;
      DAT_000239cc = 0;
    }
  }
  return puVar2;
}



/* 0001ebc8 FUN_0001ebc8 */

/* Boundary evidence: original MIPS .pdata 0001ebc8..0001ec1f. Semantic name remains unreviewed. */

void FUN_0001ebc8(int param_1)

{
  RasSetEntryProperties
            (0,*(undefined4 *)(param_1 + 4),param_1 + 0x14,0xd90,*(undefined4 *)(param_1 + 0xdb4),
             *(undefined4 *)(param_1 + 0xdb8));
  RasSetEapConnectionData
            (0,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xdac),
             *(undefined4 *)(param_1 + 0xdb0));
  return;
}



/* 0001ec20 FUN_0001ec20 */

/* Boundary evidence: original MIPS .pdata 0001ec20..0001ed47. Semantic name remains unreviewed. */

void FUN_0001ec20(LPVOID param_1,HWND param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  tagMSG local_38;
  
  local_38.hwnd = (HWND)0x0;
  memset(&local_38.message,0,0x18);
  if ((DAT_000239d8 == (HANDLE)0x0) &&
     (DAT_000239d8 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001c768,param_1,0,(LPDWORD)0x0),
     DAT_000239d8 != (HANDLE)0x0)) {
    DVar1 = MsgWaitForMultipleObjectsEx(1,&DAT_000239d8,0xffffffff,0x20,4);
    while (DVar1 == 1) {
      BVar2 = PeekMessageW(&local_38,(HWND)0x0,0xf,0xf,1);
      if ((BVar2 != 0) && (BVar2 = IsDialogMessageW(param_2,&local_38), BVar2 == 0)) {
        DispatchMessageW(&local_38);
      }
      DVar1 = MsgWaitForMultipleObjectsEx(1,&DAT_000239d8,0xffffffff,0x20,4);
    }
    CloseHandle(DAT_000239d8);
    DAT_000239d8 = (HANDLE)0x0;
  }
  return;
}



/* 0001ed48 FUN_0001ed48 */

/* Boundary evidence: original MIPS .pdata 0001ed48..0001f013. Semantic name remains unreviewed. */

undefined4 FUN_0001ed48(HWND param_1,int param_2,short param_3,int param_4)

{
  LONG LVar1;
  LRESULT LVar2;
  uint uVar3;
  int iVar4;
  HWND pHVar5;
  BOOL bEnable;
  int iVar6;
  
  LVar1 = GetWindowLongW(param_1,-0x15);
  iVar6 = 0;
  if (LVar1 != 0) {
    iVar6 = *(int *)(LVar1 + 0x1c);
  }
  if (param_2 == 0x4e) {
    if (*(int *)(param_4 + 8) == -0xca) {
      if (iVar6 == 0) {
        return 0;
      }
      SendDlgItemMessageW(param_1,0x139b,0x466,0,iVar6 + 0x140);
      FUN_0001e82c(param_1,iVar6,(uint *)&DAT_00023364);
      LVar2 = SendDlgItemMessageW(param_1,0x1398,0xf0,0,0);
      if (LVar2 == 1) {
        *(undefined4 *)(iVar6 + 0x15c) = 2;
      }
      else {
        *(undefined4 *)(iVar6 + 0x15c) = 1;
      }
    }
    SetWindowLongW(param_1,0,0);
    return 1;
  }
  if (param_2 == 0x110) {
    SetWindowLongW(param_1,-0x15,param_4);
    iVar6 = *(int *)(param_4 + 0x1c);
    pHVar5 = GetParent(param_1);
    uVar3 = GetWindowLongW(pHVar5,-0x14);
    pHVar5 = GetParent(param_1);
    SetWindowLongW(pHVar5,-0x14,uVar3 | 0x40000000);
    pHVar5 = GetDlgItem(param_1,0x138c);
    SetWindowTextW(pHVar5,*(LPCWSTR *)(iVar6 + 4));
    FUN_0001e7a4(param_1,iVar6,(uint *)&DAT_00023364);
    if ((*(uint *)(iVar6 + 0x18) & 2) == 0) {
      pHVar5 = GetDlgItem(param_1,0x139b);
      EnableWindow(pHVar5,0);
    }
    else {
      SendDlgItemMessageW(param_1,0x139b,0x465,0,*(LPARAM *)(iVar6 + 0x140));
    }
    if (*(int *)(iVar6 + 0x15c) == 2) {
      SendDlgItemMessageW(param_1,0x1398,0xf1,1,0);
    }
    iVar4 = wcscmp(L"vpn",(wchar_t *)(iVar6 + 0x778));
    if ((iVar4 != 0) && (iVar6 = wcscmp(L"PPPoE",(wchar_t *)(iVar6 + 0x778)), iVar6 != 0)) {
      return 1;
    }
    iVar6 = 0x1398;
  }
  else {
    if (param_2 != 0x111) {
      return 0;
    }
    if (param_3 != 0x1397) {
      return 1;
    }
    LVar2 = SendDlgItemMessageW(param_1,0x1397,0xf0,0,0);
    if (LVar2 != 1) {
      SendDlgItemMessageW(param_1,0x139b,0x465,0,*(LPARAM *)(iVar6 + 0x140));
      pHVar5 = GetDlgItem(param_1,0x139b);
      bEnable = 1;
      goto LAB_0001ef48;
    }
    SendDlgItemMessageW(param_1,0x139b,0x464,0,0);
    iVar6 = 0x139b;
  }
  pHVar5 = GetDlgItem(param_1,iVar6);
  bEnable = 0;
LAB_0001ef48:
  EnableWindow(pHVar5,bEnable);
  return 1;
}



/* 0001f014 FUN_0001f014 */

/* Boundary evidence: original MIPS .pdata 0001f014..0001f507. Semantic name remains unreviewed. */

undefined4 FUN_0001f014(HWND param_1,int param_2,uint param_3,int param_4)

{
  LONG LVar1;
  LRESULT LVar2;
  HMODULE hLibModule;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  HWND pHVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  void *local_38;
  int local_34;
  uint local_30;
  HMODULE local_2c;
  code *local_28;
  int local_24;
  
  LVar1 = GetWindowLongW(param_1,-0x15);
  local_34 = 0;
  if (LVar1 != 0) {
    local_34 = *(int *)(LVar1 + 0x1c);
  }
  iVar5 = local_34;
  if (param_2 == 0x4e) {
    if (*(int *)(param_4 + 8) != -0xd1) {
      if (*(int *)(param_4 + 8) != -0xca) {
        return 1;
      }
      if (local_34 == 0) {
        return 0;
      }
      FUN_0001e82c(param_1,local_34,(uint *)&DAT_00023394);
      FUN_0001e738(iVar5,param_1,iVar5);
    }
    FUN_0001e684(param_1);
    return 1;
  }
  if (param_2 == 0x110) {
    SetWindowLongW(param_1,-0x15,param_4);
    iVar8 = *(int *)(param_4 + 0x1c);
    pHVar6 = GetParent(param_1);
    uVar7 = GetWindowLongW(pHVar6,-0x14);
    pHVar6 = GetParent(param_1);
    SetWindowLongW(pHVar6,-0x14,uVar7 | 0x40000000);
    iVar5 = FUN_0001e400(iVar8,param_1,iVar8);
    if (iVar5 == 0) {
      *(uint *)(iVar8 + 0x18) = *(uint *)(iVar8 + 0x18) | 0x400000;
    }
    iVar5 = wcscmp((wchar_t *)(iVar8 + 0x778),L"modem");
    if (iVar5 == 0) {
      SendDlgItemMessageW(param_1,0x13b8,0xf1,1,0);
      pHVar6 = GetDlgItem(param_1,0x13b8);
      EnableWindow(pHVar6,0);
    }
    pHVar6 = GetDlgItem(param_1,0x13b7);
    ShowWindow(pHVar6,0);
    FUN_0001e7a4(param_1,iVar8,(uint *)&DAT_00023394);
    iVar5 = FUN_0001e5d0(param_1);
  }
  else {
    if (param_2 != 0x111) {
      return 0;
    }
    uVar7 = param_3 & 0xffff;
    if (uVar7 != 0x13ae) {
      if (uVar7 == 0x13af) {
        if (param_3 >> 0x10 == 1) {
          if (local_34 != 0) {
            LocalFree(*(HLOCAL *)(local_34 + 0xdac));
            *(undefined4 *)(iVar5 + 0xdac) = 0;
            *(undefined4 *)(iVar5 + 0xdb0) = 0;
          }
          FUN_0001e5d0(param_1);
          return 1;
        }
        return 1;
      }
      if (uVar7 != 0x13b0) {
        return 1;
      }
      puVar9 = (undefined4 *)0x0;
      local_38 = (void *)0x0;
      local_30 = 0;
      LVar2 = FUN_0001e558(param_1);
      if (LVar2 != 0) {
        puVar9 = *(undefined4 **)(LVar2 + 4);
      }
      if (puVar9 == (undefined4 *)0x0) {
        return 1;
      }
      if ((LPCWSTR)(puVar9 + 0x187) == (LPCWSTR)0x0) {
        return 1;
      }
      hLibModule = LoadLibraryW((LPCWSTR)(puVar9 + 0x187));
      if (hLibModule == (HMODULE)0x0) {
        return 1;
      }
      local_2c = hLibModule;
      pcVar3 = (code *)GetProcAddressW(hLibModule,L"RasEapInvokeConfigUI");
      pcVar4 = (code *)GetProcAddressW(hLibModule,L"RasEapFreeMemory");
      local_28 = pcVar4;
      if ((((pcVar3 != (code *)0x0) && (pcVar4 != (code *)0x0)) &&
          (local_24 = (*pcVar3)(*puVar9,param_1,0,*(undefined4 *)(iVar5 + 0xdac),
                                *(undefined4 *)(iVar5 + 0xdb0),&local_38,&local_30), local_24 == 0))
         && (local_30 < 0x20001)) {
        FUN_0001e218(iVar5,local_38,local_30);
        (*pcVar4)(local_38);
      }
      FreeLibrary(hLibModule);
      return 1;
    }
    iVar5 = FUN_0001e5d0(param_1);
  }
  uVar7 = (uint)(iVar5 == 0);
  pHVar6 = GetDlgItem(param_1,0x13b2);
  EnableWindow(pHVar6,uVar7);
  pHVar6 = GetDlgItem(param_1,0x13b4);
  EnableWindow(pHVar6,uVar7);
  pHVar6 = GetDlgItem(param_1,0x13b5);
  EnableWindow(pHVar6,uVar7);
  pHVar6 = GetDlgItem(param_1,0x13b6);
  EnableWindow(pHVar6,uVar7);
  return 1;
}



/* 0001f508 FUN_0001f508 */

/* Boundary evidence: original MIPS .pdata 0001f508..0001f513. Semantic name remains unreviewed. */

undefined4 FUN_0001f508(void)

{
  return 1;
}



/* 0001f514 FUN_0001f514 */

/* Boundary evidence: original MIPS .pdata 0001f514..0001f663. Semantic name remains unreviewed. */

undefined4 * FUN_0001f514(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint local_50 [2];
  undefined4 local_48;
  undefined1 auStack_44 [44];
  uint local_18;
  
  local_18 = DAT_00023314;
  memset(auStack_44,0,0x2c);
  local_48 = 0x30;
  local_50[0] = 0x30;
  if (DAT_000239c8 != (undefined4 *)0x0) {
    operator_delete(DAT_000239c8);
    DAT_000239d0 = 0;
    DAT_000239c8 = (undefined4 *)0x0;
    DAT_000239cc = 0;
  }
  RasEnumEntries(0,0,&local_48,local_50,0);
  if (local_50[0] != 0) {
    if (local_50[0] / 0x30 < 0x5555556) {
      uVar3 = (local_50[0] / 0x30) * 0x30;
    }
    else {
      uVar3 = 0xffffffff;
    }
    DAT_000239c8 = operator_new(uVar3);
    if (DAT_000239c8 != (undefined4 *)0x0) {
      *DAT_000239c8 = 0x30;
      iVar1 = RasEnumEntries(0,0,DAT_000239c8,local_50,&DAT_000239cc);
      if (iVar1 == 0) {
        puVar2 = FUN_0001eac8();
        FUN_000219a0(local_18);
        return puVar2;
      }
      operator_delete(DAT_000239c8);
      DAT_000239c8 = (undefined4 *)0x0;
      DAT_000239cc = 0;
    }
  }
  FUN_000219a0(local_18);
  return (undefined4 *)0x0;
}



/* 0001f664 FUN_0001f664 */

/* Boundary evidence: original MIPS .pdata 0001f664..0001f797. Semantic name remains unreviewed. */

undefined4 FUN_0001f664(undefined4 param_1,undefined4 param_2,HINSTANCE param_3)

{
  undefined4 uVar1;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  HINSTANCE local_c4;
  WCHAR *local_bc;
  undefined4 local_b8;
  undefined4 *local_b0;
  undefined4 local_a8;
  undefined1 auStack_a4 [4];
  HINSTANCE local_a0;
  undefined4 local_9c;
  code *local_90;
  undefined4 local_8c;
  undefined4 local_80;
  HINSTANCE local_78;
  undefined4 local_74;
  code *local_68;
  undefined4 local_64;
  WCHAR aWStack_58 [30];
  uint local_1c;
  
  local_1c = DAT_00023314;
  memset(auStack_a4,0,0x4c);
  local_d0 = 0;
  memset(&local_cc,0,0x24);
  local_a8 = 0x28;
  local_9c = 0x100a;
  if (DAT_00023448 == 0) {
    local_9c = 0xfa6;
  }
  local_90 = FUN_0001ed48;
  local_80 = 0x28;
  if (DAT_00023448 == 0) {
    local_74 = 0xfa7;
  }
  else {
    local_74 = 0x100b;
  }
  local_68 = FUN_0001dcf8;
  local_a0 = param_3;
  local_8c = param_1;
  local_78 = param_3;
  local_64 = param_1;
  LoadStringW(param_3,0x183e,aWStack_58,0x1e);
  local_cc = 8;
  local_bc = aWStack_58;
  local_b0 = &local_a8;
  local_d0 = 0x28;
  local_b8 = 2;
  local_c8 = param_2;
  local_c4 = param_3;
  uVar1 = (*DAT_00023438)(&local_d0);
  FUN_000219a0(local_1c);
  return uVar1;
}



/* 0001f798 FUN_0001f798 */

/* Boundary evidence: original MIPS .pdata 0001f798..0001f89f. Semantic name remains unreviewed. */

undefined4 FUN_0001f798(undefined4 param_1,undefined4 param_2,HINSTANCE param_3)

{
  undefined4 uVar1;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  HINSTANCE local_9c;
  WCHAR *local_94;
  undefined4 local_90;
  undefined4 *local_88;
  undefined4 local_80;
  undefined1 auStack_7c [4];
  HINSTANCE local_78;
  undefined4 local_74;
  code *local_68;
  undefined4 local_64;
  WCHAR aWStack_58 [30];
  uint local_1c;
  
  local_1c = DAT_00023314;
  memset(auStack_7c,0,0x24);
  local_a8 = 0;
  memset(&local_a4,0,0x24);
  local_80 = 0x28;
  local_74 = 0x100d;
  if (DAT_00023448 == 0) {
    local_74 = 0xfa9;
  }
  local_68 = FUN_0001f014;
  local_78 = param_3;
  local_64 = param_1;
  LoadStringW(param_3,0x1843,aWStack_58,0x1e);
  local_a4 = 8;
  local_94 = aWStack_58;
  local_88 = &local_80;
  local_a8 = 0x28;
  local_90 = 1;
  local_a0 = param_2;
  local_9c = param_3;
  uVar1 = (*DAT_00023438)(&local_a8);
  FUN_000219a0(local_1c);
  return uVar1;
}



/* 0001f8a0 FUN_0001f8a0 */

/* Boundary evidence: original MIPS .pdata 0001f8a0..0001f9b3. Semantic name remains unreviewed. */

int FUN_0001f8a0(HWND param_1,HINSTANCE param_2,UINT param_3,UINT param_4,UINT param_5)

{
  LPWSTR lpBuffer;
  int iVar1;
  int iVar2;
  
  if (param_2 == (HINSTANCE)0x0) {
    param_2 = DAT_000239dc;
  }
  lpBuffer = LocalAlloc(0,0x500);
  if (lpBuffer == (LPWSTR)0x0) {
    iVar2 = 2;
  }
  else {
    if (param_4 == 0) {
      param_4 = 7000;
    }
    iVar2 = LoadStringW(DAT_000239dc,param_4,lpBuffer,0x80);
    iVar2 = iVar2 + 1;
    iVar1 = LoadStringW(param_2,param_5,lpBuffer + iVar2,0x280 - iVar2);
    iVar1 = iVar1 + iVar2 + 1;
    StringCchVPrintfW(lpBuffer + iVar1,0x280 - iVar1,lpBuffer + iVar2,&stack0x00000014);
    iVar2 = MessageBoxW(param_1,lpBuffer + iVar1,lpBuffer,param_3);
    LocalFree(lpBuffer);
  }
  return iVar2;
}



/* 0001f9b4 FUN_0001f9b4 */

int FUN_0001f9b4(ushort *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  for (; (uVar2 = (uint)*param_1, 0x2f < uVar2 && (uVar2 < 0x3a)); param_1 = param_1 + 1) {
    iVar1 = iVar1 * 10 + uVar2 + -0x30;
  }
  return iVar1;
}



/* 0001f9fc FUN_0001f9fc */

/* Boundary evidence: original MIPS .pdata 0001f9fc..0001fa1f. Semantic name remains unreviewed. */

void FUN_0001f9fc(HINSTANCE param_1)

{
  UnregisterClassW(L"RNA_IPAddress",param_1);
  return;
}



/* 0001fa20 FUN_0001fa20 */

/* Boundary evidence: original MIPS .pdata 0001fa20..0001fa73. Semantic name remains unreviewed. */

void FUN_0001fa20(undefined4 *param_1,WPARAM param_2,LPARAM param_3)

{
  SetFocus((HWND)*param_1);
  SendMessageW((HWND)*param_1,0xb1,param_2,param_3);
  return;
}



/* 0001fa74 FUN_0001fa74 */

/* Boundary evidence: original MIPS .pdata 0001fa74..0001fb73. Semantic name remains unreviewed. */

void FUN_0001fa74(int param_1,int param_2)

{
  WCHAR WVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  WCHAR *pWVar5;
  WCHAR *pWVar6;
  int iVar7;
  WCHAR WStack_18;
  undefined1 auStack_15 [5];
  uint local_10;
  
  local_10 = DAT_00023314;
  if ((*(uint *)(param_1 + 0xc) & 8) != 0) {
    uVar3 = (uint)auStack_15 & 3;
    puVar2 = (uint *)(auStack_15 + -uVar3);
    *puVar2 = *puVar2 & -1 << (uVar3 + 1) * 8 | 3U >> (3 - uVar3) * 8;
    iVar7 = param_2 * 0xc + param_1;
    _WStack_18 = 3;
    uVar3 = SendMessageW(*(HWND *)(iVar7 + 0x20),0xc4,0,(LPARAM)&WStack_18);
    if ((uVar3 != 0) && (uVar3 < 3)) {
      (&WStack_18)[uVar3] = L'\0';
      pWVar5 = (WCHAR *)(auStack_15 + 1);
      pWVar6 = &WStack_18 + (uVar3 - 1);
      iVar4 = 2 - uVar3;
      do {
        WVar1 = *pWVar6;
        pWVar6 = pWVar6 + -1;
        *pWVar5 = WVar1;
        uVar3 = uVar3 - 1;
        pWVar5 = pWVar5 + -1;
      } while (uVar3 != 0);
      if (-1 < iVar4) {
        pWVar5 = &WStack_18 + iVar4;
        do {
          *pWVar5 = L'0';
          iVar4 = iVar4 + -1;
          pWVar5 = pWVar5 + -1;
        } while (-1 < iVar4);
      }
      auStack_15._3_2_ = 0;
      SetWindowTextW(*(HWND *)(iVar7 + 0x20),&WStack_18);
    }
  }
  FUN_000219a0(local_10);
  return;
}



/* 0001fb74 FUN_0001fb74 */

/* Boundary evidence: original MIPS .pdata 0001fb74..0001fc33. Semantic name remains unreviewed. */

uint FUN_0001fb74(undefined4 *param_1)

{
  LRESULT LVar1;
  uint uVar2;
  ushort local_20 [4];
  uint local_18;
  
  local_18 = DAT_00023314;
  local_20[0] = 3;
  local_20[1] = 0;
  LVar1 = SendMessageW((HWND)*param_1,0xc4,0,(LPARAM)local_20);
  if (LVar1 == 0) {
    FUN_000219a0(local_18);
    uVar2 = 0xffffffff;
  }
  else {
    local_20[LVar1] = 0;
    uVar2 = FUN_0001f9b4(local_20);
    if (((int)uVar2 < (int)(uint)*(byte *)((int)param_1 + 9)) ||
       ((int)(uint)*(byte *)((int)param_1 + 10) < (int)uVar2)) {
      uVar2 = (uint)*(byte *)(param_1 + 2);
    }
    FUN_000219a0(local_18);
  }
  return uVar2;
}



/* 0001fc34 FUN_0001fc34 */

/* Boundary evidence: original MIPS .pdata 0001fc34..0001fde3. Semantic name remains unreviewed. */

undefined4 FUN_0001fc34(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  HWND pHVar4;
  int iVar5;
  undefined4 *puVar6;
  WCHAR WStack_28;
  WCHAR aWStack_25 [2];
  uint local_20;
  
  local_20 = DAT_00023314;
  uVar2 = (uint)aWStack_25 & 3;
  puVar1 = (uint *)((int)aWStack_25 - uVar2);
  *puVar1 = *puVar1 & -1 << (uVar2 + 1) * 8 | 3U >> (3 - uVar2) * 8;
  iVar5 = param_2 * 0xc + param_1;
  puVar6 = (undefined4 *)(iVar5 + 0x20);
  _WStack_28 = 3;
  uVar2 = SendMessageW((HWND)*puVar6,0xc4,0,(LPARAM)&WStack_28);
  if (uVar2 != 0) {
    (&WStack_28)[uVar2] = L'\0';
    iVar3 = FUN_0001f9b4((ushort *)&WStack_28);
    if ((iVar3 < (int)(uint)*(byte *)(iVar5 + 0x29)) || ((int)(uint)*(byte *)(iVar5 + 0x2a) < iVar3)
       ) {
      pHVar4 = GetParent((HWND)*puVar6);
      if ((pHVar4 != (HWND)0x0) && (pHVar4 = GetParent(pHVar4), pHVar4 != (HWND)0x0)) {
        *(undefined4 *)(param_1 + 0x18) = 1;
        if (iVar3 == 0x159) {
          DAT_000239e0 = DAT_000239e0 + 1;
        }
        FUN_0001f8a0(pHVar4,(HINSTANCE)0x0,0x30,0,0x1b59);
        *(undefined4 *)(param_1 + 0x18) = 0;
        wsprintfW(&WStack_28,L"%d",(uint)*(byte *)(iVar5 + 0x28));
        SetWindowTextW((HWND)*puVar6,&WStack_28);
        SendMessageW((HWND)*puVar6,0xb1,0,3);
        FUN_000219a0(local_20);
        return 0;
      }
    }
    else if (uVar2 < 3) {
      FUN_0001fa74(param_1,param_2);
    }
    *(char *)(iVar5 + 0x28) = (char)iVar3;
  }
  FUN_000219a0(local_20);
  return 1;
}



/* 0001fde4 FUN_0001fde4 */

/* Boundary evidence: original MIPS .pdata 0001fde4..0001fe57. Semantic name remains unreviewed. */

bool FUN_0001fde4(int param_1,int param_2,int param_3,WPARAM param_4,LPARAM param_5)

{
  int iVar1;
  
  iVar1 = FUN_0001fc34(param_1,param_2);
  if (iVar1 != 0) {
    FUN_0001fa20((undefined4 *)(param_3 * 0xc + param_1 + 0x20),param_4,param_5);
  }
  return iVar1 != 0;
}



/* 0001fe58 FUN_0001fe58 */

/* Boundary evidence: original MIPS .pdata 0001fe58..0002049f. Semantic name remains unreviewed. */

LRESULT FUN_0001fe58(HWND param_1,UINT param_2,uint param_3,LPARAM param_4)

{
  bool bVar1;
  HKL pHVar2;
  HWND hWnd;
  LONG LVar3;
  uint uVar4;
  BOOL BVar5;
  HIMC pHVar6;
  LONG LVar7;
  LRESULT LVar8;
  int iVar9;
  undefined3 extraout_var;
  uint uVar10;
  short extraout_var_00;
  uint uVar11;
  int iVar12;
  uint local_res8 [2];
  WCHAR local_40 [4];
  undefined1 auStack_38 [8];
  uint local_30;
  
  local_30 = DAT_00023314;
  local_res8[0] = param_3;
  pHVar2 = GetKeyboardLayout(0);
  hWnd = GetParent(param_1);
  if (hWnd == (HWND)0x0) goto LAB_0001febc;
  LVar3 = GetWindowLongW(hWnd,0);
  uVar4 = GetWindowLongW(param_1,-0xc);
  iVar12 = uVar4 * 0xc + LVar3;
  if (*(HWND *)(iVar12 + 0x20) != param_1) goto LAB_0001febc;
  if (param_2 == 8) {
    FUN_0001fa74(LVar3,uVar4);
  }
  else {
    if (param_2 == 0x87) {
      FUN_000219a0(local_30);
      return 0x81;
    }
    if (param_2 == 0x100) {
      if (local_res8[0] == 0x23) {
        if (uVar4 < 3) {
          FUN_0001fde4(LVar3,uVar4,3,3,3);
          goto LAB_0001febc;
        }
      }
      else if (local_res8[0] == 0x24) {
        if (uVar4 != 0) {
          FUN_0001fde4(LVar3,uVar4,0,0,0);
          goto LAB_0001febc;
        }
      }
      else if ((0x24 < local_res8[0]) && (local_res8[0] < 0x29)) {
        GetKeyState(0x11);
        if (extraout_var_00 < 0) {
          if (((local_res8[0] == 0x25) || (local_res8[0] == 0x26)) && (uVar4 != 0)) {
            FUN_0001fde4(LVar3,uVar4,uVar4 - 1,0,3);
            goto LAB_0001febc;
          }
          if (((local_res8[0] == 0x27) || (local_res8[0] == 0x28)) && (uVar4 < 3)) {
            FUN_0001fde4(LVar3,uVar4,uVar4 + 1,0,3);
            goto LAB_0001febc;
          }
        }
        else {
          uVar10 = SendMessageW(param_1,0xb0,0,0);
          uVar11 = uVar10 & 0xffff;
          if (uVar11 == uVar10 >> 0x10) {
            if ((((local_res8[0] == 0x25) || (local_res8[0] == 0x26)) && (uVar11 == 0)) &&
               (uVar4 != 0)) {
              FUN_0001fde4(LVar3,uVar4,uVar4 - 1,3,3);
              goto LAB_0001febc;
            }
            if (((local_res8[0] == 0x27) || (local_res8[0] == 0x28)) &&
               ((uVar4 < 3 && (uVar10 = SendMessageW(param_1,0xc1,0,0), uVar10 <= uVar11)))) {
              FUN_0001fde4(LVar3,uVar4,uVar4 + 1,0,0);
              goto LAB_0001febc;
            }
          }
          if (local_res8[0] == 0x26) {
            local_res8[0] = 0x25;
          }
          else if (local_res8[0] == 0x28) {
            local_res8[0] = 0x27;
          }
        }
      }
    }
    else if (param_2 == 0x102) {
      local_40[0] = L'\0';
      LCMapStringW(0x400,0x400000,(LPCWSTR)local_res8,1,local_40,1);
      local_res8[0] = (uint)(ushort)local_40[0];
      if ((0x2f < local_res8[0]) && (local_res8[0] < 0x3a)) {
        CallWindowProcW(*(WNDPROC *)((uVar4 + 3) * 0xc + LVar3),param_1,0x102,local_res8[0],param_4)
        ;
        LVar8 = SendMessageW(param_1,0xb0,0,0);
        iVar9 = FUN_0001fc34(LVar3,uVar4);
        if (((LVar8 == 0x30003) && (iVar9 != 0)) && (uVar4 < 3)) {
          FUN_0001fa20((undefined4 *)(iVar12 + 0x2c),0,3);
        }
        goto LAB_00020464;
      }
      if ((local_res8[0] == 0x2e) || (local_res8[0] == 0x20)) {
        uVar10 = SendMessageW(param_1,0xb0,0,0);
        if (((uVar10 == 0) || (uVar10 >> 0x10 != (uVar10 & 0xffff))) ||
           (iVar9 = FUN_0001fc34(LVar3,uVar4), iVar9 == 0)) goto LAB_0001febc;
        if (uVar4 < 3) {
          FUN_0001fa20((undefined4 *)(iVar12 + 0x2c),0,3);
          goto LAB_0001febc;
        }
LAB_000201c0:
        MessageBeep(0xffffffff);
LAB_0001febc:
        FUN_000219a0(local_30);
        return 0;
      }
      if (local_res8[0] == 8) {
        if ((uVar4 != 0) && (LVar8 = SendMessageW(param_1,0xb0,0,0), LVar8 == 0)) {
          bVar1 = FUN_0001fde4(LVar3,uVar4,uVar4 - 1,3,3);
          if ((CONCAT31(extraout_var,bVar1) != 0) &&
             (LVar8 = SendMessageW(*(HWND *)(iVar12 + 0x14),0xc1,0,0), LVar8 != 0)) {
            SendMessageW(*(HWND *)(iVar12 + 0x14),0x102,local_res8[0],param_4);
          }
          goto LAB_0001febc;
        }
      }
      else if (0x20 < local_res8[0]) goto LAB_000201c0;
    }
    else if (((param_2 == 0x10f) && (BVar5 = ImmIsIME(pHVar2), BVar5 != 0)) &&
            ((((uint)pHVar2 & 0xffff) == 0x412 &&
             (pHVar6 = ImmGetContext(param_1), pHVar6 != (HIMC)0x0)))) {
      LVar7 = ImmGetCompositionStringW(pHVar6,8,auStack_38,4);
      if (0 < LVar7) {
        ImmNotifyIME(pHVar6,0x15,4,0);
      }
      ImmReleaseContext(param_1,pHVar6);
      LVar8 = CallWindowProcW(*(WNDPROC *)((uVar4 + 3) * 0xc + LVar3),param_1,0x10f,local_res8[0],
                              param_4);
      goto LAB_00020464;
    }
  }
  LVar8 = CallWindowProcW(*(WNDPROC *)((uVar4 + 3) * 0xc + LVar3),param_1,param_2,local_res8[0],
                          param_4);
LAB_00020464:
  FUN_000219a0(local_30);
  return LVar8;
}



/* 000204a0 FUN_000204a0 */

/* Boundary evidence: original MIPS .pdata 000204a0..00020d2f. Semantic name remains unreviewed. */

LRESULT FUN_000204a0(HWND param_1,uint param_2,uint param_3,int *param_4)

{
  LONG LVar1;
  DWORD DVar2;
  HBRUSH h;
  HGDIOBJ h_00;
  HPEN h_01;
  HGDIOBJ h_02;
  uint uVar3;
  HLOCAL hMem;
  int *dwNewLong;
  HDC hdc;
  HWND pHVar4;
  COLORREF color;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  LRESULT LVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  HMENU hMenu;
  tagSIZE local_90;
  tagRECT tStack_88;
  tagPAINTSTRUCT local_78;
  WCHAR aWStack_38 [4];
  uint local_30;
  
  local_30 = DAT_00023314;
  LVar8 = 1;
  if (param_2 < 0x112) {
    if (param_2 == 0x111) {
      if ((param_3 & 0xffff) == 0x100) {
        puVar7 = (undefined4 *)GetWindowLongW(param_1,0);
        if (puVar7[7] == 0) {
          puVar7[7] = 1;
          uVar3 = GetWindowLongW(param_1,-0xc);
          SendMessageW((HWND)*puVar7,0x111,uVar3 & 0xffff | 0x1000000,(LPARAM)param_1);
        }
      }
      else if (((param_3 & 0xffff) == 0x200) &&
              (puVar7 = (undefined4 *)GetWindowLongW(param_1,0), puVar7[6] == 0)) {
        pHVar4 = GetFocus();
        iVar9 = 0;
        puVar5 = puVar7 + 8;
        do {
          if ((HWND)*puVar5 == pHVar4) break;
          iVar9 = iVar9 + 1;
          puVar5 = puVar5 + 3;
        } while (iVar9 < 4);
        if (3 < iVar9) {
          uVar3 = GetWindowLongW(param_1,-0xc);
          SendMessageW((HWND)*puVar7,0x111,uVar3 & 0xffff | 0x2000000,(LPARAM)param_1);
          puVar7[7] = 0;
        }
      }
      goto LAB_00020cf4;
    }
    if (param_2 == 1) {
      dwNewLong = LocalAlloc(0x40,0x50);
      if (dwNewLong == (int *)0x0) {
        DestroyWindow(param_1);
      }
      else {
        dwNewLong[4] = 1;
        dwNewLong[5] = 0;
        dwNewLong[6] = 0;
        *dwNewLong = param_4[3];
        uVar3 = param_4[8];
        dwNewLong[3] = uVar3;
        if ((uVar3 & 2) == 0) {
          uVar11 = 1;
          if ((uVar3 & 4) == 0) {
            uVar11 = 0;
          }
        }
        else {
          uVar11 = 2;
        }
        hdc = GetDC(param_1);
        GetTextExtentExPointW(hdc,L".",1,0,(LPINT)0x0,(LPINT)0x0,&local_90);
        dwNewLong[2] = local_90.cx;
        ReleaseDC(param_1,hdc);
        iVar9 = 2;
        hMenu = (HMENU)0x0;
        piVar6 = dwNewLong + 8;
        dwNewLong[1] = (param_4[5] + dwNewLong[2] * -3) - 4U >> 2;
        do {
          *(undefined1 *)((int)piVar6 + 9) = 0;
          *(undefined1 *)((int)piVar6 + 10) = 0xff;
          pHVar4 = CreateWindowExW(0,L"Edit",(LPCWSTR)0x0,uVar11 | 0x50000004,iVar9,2,dwNewLong[1],
                                   param_4[4] + -4,param_1,hMenu,(HINSTANCE)param_4[1],(LPVOID)0x0);
          *piVar6 = (int)pHVar4;
          SendMessageW(pHVar4,0xc5,3,0);
          LVar1 = GetWindowLongW((HWND)*piVar6,-4);
          piVar6[1] = LVar1;
          SetWindowLongW((HWND)*piVar6,-4,0x1fe58);
          iVar9 = dwNewLong[1] + dwNewLong[2] + iVar9;
          ImmAssociateContext((HWND)*piVar6,(HIMC)0x0);
          hMenu = (HMENU)((int)&hMenu->unused + 1);
          piVar6 = piVar6 + 3;
        } while ((int)hMenu < 4);
        SetWindowLongW(param_1,0,(LONG)dwNewLong);
        LVar8 = 1;
      }
      goto LAB_00020cf4;
    }
    if (param_2 == 2) {
      hMem = (HLOCAL)GetWindowLongW(param_1,0);
      puVar7 = (undefined4 *)((int)hMem + 0x20);
      iVar9 = 4;
      do {
        SetWindowLongW((HWND)*puVar7,-4,puVar7[1]);
        iVar9 = iVar9 + -1;
        puVar7 = puVar7 + 3;
      } while (iVar9 != 0);
      LocalFree(hMem);
      goto LAB_00020cf4;
    }
    if (param_2 == 7) {
      iVar9 = GetWindowLongW(param_1,0);
LAB_000207c4:
      FUN_0001fa20((undefined4 *)(iVar9 + 0x20),0,3);
      goto LAB_00020cf4;
    }
    if (param_2 == 10) {
      LVar1 = GetWindowLongW(param_1,0);
      *(uint *)(LVar1 + 0x10) = param_3;
      puVar7 = (undefined4 *)(LVar1 + 0x20);
      iVar9 = 4;
      do {
        EnableWindow((HWND)*puVar7,param_3);
        iVar9 = iVar9 + -1;
        puVar7 = puVar7 + 3;
      } while (iVar9 != 0);
      if ((*(uint *)(LVar1 + 0xc) & 0x10000) != 0) {
        uVar3 = GetWindowLongW(param_1,-0x10);
        if (param_3 == 0) {
          uVar3 = uVar3 & 0xfffeffff;
        }
        else {
          uVar3 = uVar3 | 0x10000;
        }
        SetWindowLongW(param_1,-0x10,uVar3);
      }
      if (*(int *)(LVar1 + 0x14) != 0) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      goto LAB_00020cf4;
    }
    if (param_2 == 0xf) {
      BeginPaint(param_1,&local_78);
      GetClientRect(param_1,&tStack_88);
      LVar1 = GetWindowLongW(param_1,0);
      DVar2 = GetSysColor(0x40000005);
      h = CreateSolidBrush(DVar2);
      h_00 = SelectObject(local_78.hdc,h);
      DVar2 = GetSysColor(0x40000005);
      if (DVar2 == 0) {
        color = 0xffffff;
      }
      else {
        color = 0;
      }
      h_01 = CreatePen(0,1,color);
      h_02 = SelectObject(local_78.hdc,h_01);
      Rectangle(local_78.hdc,0,0,tStack_88.right,tStack_88.bottom);
      SelectObject(local_78.hdc,h_00);
      if (h != (HBRUSH)0x0) {
        DeleteObject(h);
      }
      SelectObject(local_78.hdc,h_02);
      if (h_01 != (HPEN)0x0) {
        DeleteObject(h_01);
      }
      if (*(int *)(LVar1 + 0x10) == 0) {
        iVar9 = 0x40000011;
      }
      else {
        iVar9 = 0x40000008;
      }
      DVar2 = GetSysColor(iVar9);
      if (DVar2 != 0) {
        SetTextColor(local_78.hdc,DVar2);
      }
      DVar2 = GetSysColor(0x40000005);
      SetBkColor(local_78.hdc,DVar2);
      iVar9 = *(int *)(LVar1 + 4) + 2;
      iVar10 = 3;
      do {
        ExtTextOutW(local_78.hdc,iVar9,2,0,(RECT *)0x0,L".",1,(INT *)0x0);
        iVar10 = iVar10 + -1;
        iVar9 = *(int *)(LVar1 + 4) + *(int *)(LVar1 + 8) + iVar9;
      } while (iVar10 != 0);
      *(undefined4 *)(LVar1 + 0x14) = 1;
      EndPaint(param_1,&local_78);
      goto LAB_00020cf4;
    }
    if (param_2 == 0x30) {
      LVar1 = GetWindowLongW(param_1,0);
      puVar7 = (undefined4 *)(LVar1 + 0x20);
      iVar9 = 4;
      do {
        SendMessageW((HWND)*puVar7,0x30,param_3,(LPARAM)param_4);
        iVar9 = iVar9 + -1;
        puVar7 = puVar7 + 3;
      } while (iVar9 != 0);
      goto LAB_00020cf4;
    }
  }
  else {
    if (param_2 == 0x201) {
      SetFocus(param_1);
      goto LAB_00020cf4;
    }
    if (param_2 == 0x464) {
      LVar1 = GetWindowLongW(param_1,0);
      puVar7 = (undefined4 *)(LVar1 + 0x20);
      iVar9 = 4;
      do {
        SetWindowTextW((HWND)*puVar7,L"");
        iVar9 = iVar9 + -1;
        puVar7 = puVar7 + 3;
      } while (iVar9 != 0);
      goto LAB_00020cf4;
    }
    if (param_2 == 0x465) {
      LVar1 = GetWindowLongW(param_1,0);
      puVar7 = (undefined4 *)(LVar1 + 0x20);
      iVar9 = 4;
      do {
        wsprintfW(aWStack_38,L"%d",(uint)param_4 >> 0x18);
        *(char *)(puVar7 + 2) = (char)((uint)param_4 >> 0x18);
        SetWindowTextW((HWND)*puVar7,aWStack_38);
        param_4 = (int *)((int)param_4 << 8);
        iVar9 = iVar9 + -1;
        puVar7 = puVar7 + 3;
      } while (iVar9 != 0);
      goto LAB_00020cf4;
    }
    if (param_2 == 0x466) {
      LVar1 = GetWindowLongW(param_1,0);
      LVar8 = 0;
      iVar9 = 0;
      puVar7 = (undefined4 *)(LVar1 + 0x20);
      iVar10 = 4;
      do {
        uVar3 = FUN_0001fb74(puVar7);
        if (uVar3 == 0xffffffff) {
          uVar3 = 0;
        }
        else {
          LVar8 = LVar8 + 1;
        }
        iVar9 = iVar9 * 0x100 + uVar3;
        iVar10 = iVar10 + -1;
        puVar7 = puVar7 + 3;
      } while (iVar10 != 0);
      *param_4 = iVar9;
      goto LAB_00020cf4;
    }
    if (param_2 == 0x467) {
      if (param_3 < 4) {
        LVar1 = GetWindowLongW(param_1,0);
        iVar9 = param_3 * 0xc + LVar1;
        *(char *)(iVar9 + 0x29) = (char)param_4;
        *(char *)(iVar9 + 0x2a) = (char)((uint)param_4 >> 8);
      }
      goto LAB_00020cf4;
    }
    if (param_2 == 0x468) {
      LVar1 = GetWindowLongW(param_1,0);
      if (3 < param_3) {
        param_3 = 0;
        puVar7 = (undefined4 *)(LVar1 + 0x20);
        do {
          uVar3 = FUN_0001fb74(puVar7);
          if (uVar3 == 0xffffffff) break;
          param_3 = param_3 + 1;
          puVar7 = puVar7 + 3;
        } while (param_3 < 4);
        if (3 < param_3) {
          param_3 = 0;
        }
      }
      iVar9 = param_3 * 0xc + LVar1;
      goto LAB_000207c4;
    }
  }
  LVar8 = DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
LAB_00020cf4:
  FUN_000219a0(local_30);
  return LVar8;
}



/* 00020d30 FUN_00020d30 */

/* Boundary evidence: original MIPS .pdata 00020d30..00020d9b. Semantic name remains unreviewed. */

void FUN_00020d30(HINSTANCE param_1)

{
  WNDCLASSW local_30;
  
  local_30.style = 8;
  local_30.lpszClassName = L"RNA_IPAddress";
  local_30.hCursor = (HCURSOR)0x0;
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.lpfnWndProc = FUN_000204a0;
  local_30.hIcon = (HICON)0x0;
  local_30.cbWndExtra = 4;
  local_30.cbClsExtra = 0;
  local_30.hbrBackground = (HBRUSH)0x40000006;
  DAT_000239dc = param_1;
  local_30.hInstance = param_1;
  RegisterClassW(&local_30);
  return;
}



/* 00020d9c FUN_00020d9c */

/* Boundary evidence: original MIPS .pdata 00020d9c..00020e1f. Semantic name remains unreviewed. */

undefined4 * FUN_00020d9c(undefined4 *param_1)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_FUN_00011d88;
  param_1[1] = 0;
  pHVar1 = LoadLibraryW(L"commctrl.dll");
  param_1[2] = pHVar1;
  if (pHVar1 != (HMODULE)0x0) {
    uVar2 = GetProcAddressW(pHVar1,L"PropertySheetW");
    param_1[3] = uVar2;
    uVar2 = GetProcAddressW(param_1[2],L"CreatePropertySheetPageW");
    param_1[4] = uVar2;
  }
  return param_1;
}



/* 00020e20 FUN_00020e20 */

/* Boundary evidence: original MIPS .pdata 00020e20..00020e57. Semantic name remains unreviewed. */

bool FUN_00020e20(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = wcscmp(param_2,L"ConnInfo");
  return iVar1 == 0;
}



/* 00020e58 FUN_00020e58 */

/* Boundary evidence: original MIPS .pdata 00020e58..00020eaf. Semantic name remains unreviewed. */

void FUN_00020e58(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00011d88;
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
  }
  if ((HMODULE)param_1[2] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)param_1[2]);
  }
  return;
}



/* 00020eb0 FUN_00020eb0 */

/* Boundary evidence: original MIPS .pdata 00020eb0..00020f27. Semantic name remains unreviewed. */

undefined4 FUN_00020eb0(wchar_t *param_1)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == (wchar_t *)0x0) {
LAB_00020f0c:
    uVar2 = 0;
  }
  else {
    uVar3 = 0;
    do {
      pwVar1 = wcschr(param_1,*(wchar_t *)((int)&DAT_00011d78 + uVar3));
      if (pwVar1 != (wchar_t *)0x0) goto LAB_00020f0c;
      uVar3 = uVar3 + 2;
    } while (uVar3 < 0x10);
    uVar2 = 1;
  }
  return uVar2;
}



/* 00020f54 FUN_00020f54 */

/* Boundary evidence: original MIPS .pdata 00020f54..00020fb7. Semantic name remains unreviewed. */

undefined4
FUN_00020f54(int param_1,int param_2,undefined4 param_3,STRSAFE_LPWSTR param_4,size_t param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  
  if ((param_4 == (STRSAFE_LPWSTR)0x0) ||
     (*(STRSAFE_LPCWSTR *)(param_1 + 4) == (STRSAFE_LPCWSTR)0x0)) {
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 0x1900;
    }
    uVar1 = 0;
  }
  else {
    if (param_2 == 0) {
      StringCchCopyW(param_4,param_5,*(STRSAFE_LPCWSTR *)(param_1 + 4));
    }
    else {
      *param_4 = L'\0';
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 00020fb8 FUN_00020fb8 */

/* Boundary evidence: original MIPS .pdata 00020fb8..000210bb. Semantic name remains unreviewed. */

undefined4 FUN_00020fb8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  int local_22c;
  uint local_228;
  int *local_220;
  int local_218;
  undefined1 auStack_214 [508];
  
  if (param_1[3] == 0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x1900;
    }
    uVar2 = 0;
  }
  else {
    local_240 = 0;
    memset(&local_23c,0,0x24);
    local_218 = 0;
    memset(auStack_214,0,0x1fc);
    local_228 = 0;
    piVar3 = &local_218;
    do {
      iVar1 = (**(code **)(*param_1 + 0x50))(param_1,local_228,param_2);
      *piVar3 = iVar1;
      if (iVar1 == 0) break;
      local_228 = local_228 + 1;
      piVar3 = piVar3 + 1;
    } while (local_228 < 0x80);
    local_240 = 0x28;
    local_220 = &local_218;
    local_22c = param_1[1];
    uVar2 = 1;
    local_23c = 1;
    local_238 = param_3;
    local_234 = param_2;
    (*(code *)param_1[3])(&local_240);
  }
  return uVar2;
}



/* 000210bc FUN_000210bc */

/* Boundary evidence: original MIPS .pdata 000210bc..00021107. Semantic name remains unreviewed. */

undefined4 * FUN_000210bc(undefined4 *param_1,uint param_2)

{
  FUN_00020e58(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00021158 FUN_00021158 */

/* Boundary evidence: original MIPS .pdata 00021158..0002134b. Semantic name remains unreviewed. */

undefined4 FUN_00021158(HKEY param_1,LPCWSTR param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x64a;
  memset(param_4,0,0xc48);
  *param_4 = param_3;
  if ((3 < param_3) && (param_3 < 0x100)) {
    iVar1 = FUN_000214a0(param_1,param_2,L"Path",1);
    if (iVar1 == 1) {
      FUN_000214a0(param_1,param_2,L"ConfigUIPath",1);
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* 0002134c FUN_0002134c */

/* Boundary evidence: original MIPS .pdata 0002134c..0002140f. Semantic name remains unreviewed. */

int FUN_0002134c(HKEY param_1,wchar_t *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint auStack_c60 [786];
  uint local_18;
  
  local_18 = DAT_00023314;
  uVar1 = _wtol(param_2);
  iVar2 = FUN_00021158(param_1,param_2,uVar1,auStack_c60);
  if (iVar2 == 0) {
    uVar1 = param_3[3];
    param_3[3] = uVar1 + 0xc48;
    if (uVar1 + 0xc48 <= *param_3) {
      memcpy((void *)(param_3[2] * 0xc48 + param_3[1]),auStack_c60,0xc48);
    }
    param_3[2] = param_3[2] + 1;
  }
  FUN_000219a0(local_18);
  return iVar2;
}



/* 00021410 FUN_00021410 */

/* Boundary evidence: original MIPS .pdata 00021410..0002149f. Semantic name remains unreviewed. */

LSTATUS FUN_00021410(uint param_1,undefined4 param_2,undefined4 *param_3,uint *param_4)

{
  LSTATUS LVar1;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  
  local_18 = 0;
  local_14 = 0;
  local_20 = param_1;
  local_1c = param_2;
  LVar1 = FUN_000217c4((HKEY)0x80000002,L"Comm\\EAP\\Extension",FUN_0002134c,&local_20);
  if (LVar1 == 0) {
    *param_3 = local_18;
    *param_4 = local_14;
    if (param_1 < local_14) {
      LVar1 = 0x7a;
    }
  }
  return LVar1;
}



/* 000214a0 FUN_000214a0 */

/* Boundary evidence: original MIPS .pdata 000214a0..000217c3. Semantic name remains unreviewed. */

int FUN_000214a0(HKEY param_1,LPCWSTR param_2,undefined4 param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  DWORD dwErrCode;
  LPBYTE lpData;
  uint *puVar2;
  int iVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  uint uVar6;
  LPCWSTR lpValueName;
  LPCWSTR pWVar7;
  HKEY local_res0;
  LPCWSTR local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  DWORD local_38;
  SIZE_T local_34;
  DWORD local_30;
  LPCWSTR local_2c;
  
  iVar3 = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  local_2c = param_2;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar1 = RegOpenKeyExW(param_1,param_2,0,0x20019,&local_res0), LVar1 == 0)) {
    puVar5 = &local_res8;
    pWVar7 = local_2c;
    while (lpValueName = (LPCWSTR)*puVar5, lpValueName != (LPCWSTR)0x0) {
      DVar4 = puVar5[1];
      puVar2 = (uint *)0x0;
      uVar6 = puVar5[2] & 1;
      if (uVar6 == 0) {
        lpData = (LPBYTE)puVar5[3];
        if (DVar4 == 3) {
          puVar2 = (uint *)puVar5[4];
          local_38 = *puVar2;
        }
        else {
          local_38 = puVar5[4];
        }
      }
      else {
        local_38 = 0;
        pWVar7 = (LPCWSTR)puVar5[3];
        puVar2 = (uint *)puVar5[4];
        lpData = (LPBYTE)0x0;
      }
      puVar5 = puVar5 + 5;
      LVar1 = RegQueryValueExW(local_res0,lpValueName,(LPDWORD)0x0,&local_30,(LPBYTE)0x0,&local_34);
      if (((LVar1 == 0) || (LVar1 == 0xea)) && (local_30 == DVar4)) {
        if (uVar6 == 0) {
          if ((local_38 < local_34) || (lpData == (LPBYTE)0x0)) {
            if (DVar4 == 3) {
              *puVar2 = local_34;
            }
            lpData = (LPBYTE)0x0;
            dwErrCode = 0x7a;
            goto LAB_000216d8;
          }
        }
        else {
          lpData = LocalAlloc(0x40,local_34);
          if (lpData == (LPBYTE)0x0) {
            dwErrCode = 0xe;
LAB_000216d8:
            SetLastError(dwErrCode);
          }
          else {
            local_38 = local_34;
          }
          if (lpData == (LPBYTE)0x0) goto LAB_00021754;
        }
        LVar1 = RegQueryValueExW(local_res0,lpValueName,(LPDWORD)0x0,(LPDWORD)0x0,lpData,&local_38);
        if (LVar1 == 0) {
          iVar3 = iVar3 + 1;
          if (DVar4 == 3) {
            *puVar2 = local_38;
          }
        }
        else if (uVar6 != 0) {
          LocalFree(lpData);
          local_38 = 0;
          lpData = (LPBYTE)0x0;
        }
      }
LAB_00021754:
      if ((uVar6 != 0) && (*(LPBYTE *)pWVar7 = lpData, puVar2 != (uint *)0x0)) {
        *puVar2 = local_38;
      }
    }
    if (local_2c != (LPCWSTR)0x0) {
      RegCloseKey(local_res0);
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



/* 000217c4 FUN_000217c4 */

/* Boundary evidence: original MIPS .pdata 000217c4..0002191f. Semantic name remains unreviewed. */

LSTATUS FUN_000217c4(HKEY param_1,LPCWSTR param_2,undefined *param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  DWORD dwIndex;
  HKEY local_230;
  DWORD local_22c;
  WCHAR aWStack_228 [258];
  uint local_24;
  
  local_24 = DAT_00023314;
  local_230 = param_1;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar1 = RegOpenKeyExW(param_1,param_2,0,0xf003f,&local_230), LVar1 == 0)) {
    local_22c = 0x101;
    dwIndex = 0;
    LVar1 = RegEnumKeyExW(local_230,0,aWStack_228,&local_22c,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          (PFILETIME)0x0);
    while (LVar1 == 0) {
      (*(code *)param_3)(local_230,aWStack_228,param_4);
      dwIndex = dwIndex + 1;
      local_22c = 0x101;
      LVar1 = RegEnumKeyExW(local_230,dwIndex,aWStack_228,&local_22c,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
    }
    if (LVar1 == 0x103) {
      LVar1 = 0;
    }
    if (param_2 != (LPCWSTR)0x0) {
      RegCloseKey(local_230);
    }
  }
  FUN_000219a0(local_24);
  return LVar1;
}



/* 00021920 FUN_00021920 */

/* Boundary evidence: original MIPS .pdata 00021920..00021973. Semantic name remains unreviewed. */

void FUN_00021920(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_000219a0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00021974 FUN_00021974 */

/* Boundary evidence: original MIPS .pdata 00021974..0002199f. Semantic name remains unreviewed. */

undefined4 FUN_00021974(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00021920(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 000219a0 FUN_000219a0 */

/* Boundary evidence: original MIPS .pdata 000219a0..000219e7. Semantic name remains unreviewed. */

void FUN_000219a0(uint param_1)

{
  if ((param_1 == DAT_00023314) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 000222d8 FUN_000222d8 */

/* Boundary evidence: original MIPS .pdata 000222d8..000222f7. Semantic name remains unreviewed. */

void FUN_000222d8(void)

{
  FUN_00012598(FUN_00022314);
  return;
}



/* 000222f8 FUN_000222f8 */

/* Boundary evidence: original MIPS .pdata 000222f8..00022313. Semantic name remains unreviewed. */

void FUN_000222f8(void)

{
  FUN_0001be18();
  return;
}



/* 00022314 FUN_00022314 */

/* Boundary evidence: original MIPS .pdata 00022314..00022333. Semantic name remains unreviewed. */

void FUN_00022314(void)

{
  FUN_000168dc(0x2349c);
  return;
}



/* 00022334 FUN_00022334 */

/* Boundary evidence: original MIPS .pdata 00022334..00022353. Semantic name remains unreviewed. */

void FUN_00022334(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_000239ac);
  return;
}


