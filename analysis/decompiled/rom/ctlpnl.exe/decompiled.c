/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011130 FUN_00011130 */

/* Boundary evidence: original MIPS .pdata 00011130..000111c3. Semantic name remains unreviewed. */

void FUN_00011130(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  UINT UVar1;
  
  FUN_00011440();
  UVar1 = FUN_00011748(param_1,param_2,param_3);
  FUN_00011380(UVar1);
  FUN_000113a0(UVar1);
  return;
}



/* 000111c4 FUN_000111c4 */

/* Boundary evidence: original MIPS .pdata 000111c4..00011203. Semantic name remains unreviewed. */

void FUN_000111c4(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00011204 entry */

/* Boundary evidence: original MIPS .pdata 00011204..0001125f. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  FUN_0001147c();
  FUN_00011130(param_1,param_2,param_3);
  return;
}



/* 00011260 FUN_00011260 */

/* Boundary evidence: original MIPS .pdata 00011260..0001137f. Semantic name remains unreviewed. */

void FUN_00011260(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00013110 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00013120;
    if (DAT_00013120 != (undefined4 *)0x0) {
      while (DAT_0001311c = DAT_0001311c + -1, _Memory <= DAT_0001311c) {
        if ((code *)*DAT_0001311c != (code *)0x0) {
          (*(code *)*DAT_0001311c)();
          _Memory = DAT_00013120;
        }
      }
      free(_Memory);
      DAT_0001311c = (undefined4 *)0x0;
      DAT_00013120 = (undefined4 *)0x0;
    }
    FUN_000113ec((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_000113ec((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_00013124,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011380 FUN_00011380 */

/* Boundary evidence: original MIPS .pdata 00011380..0001139f. Semantic name remains unreviewed. */

void FUN_00011380(UINT param_1)

{
  FUN_00011260(param_1,0,0);
  return;
}



/* 000113a0 FUN_000113a0 */

/* Boundary evidence: original MIPS .pdata 000113a0..000113eb. Semantic name remains unreviewed. */

void FUN_000113a0(UINT param_1)

{
  DAT_00013110 = 0;
  FUN_000113ec((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000113ec FUN_000113ec */

/* Boundary evidence: original MIPS .pdata 000113ec..0001143f. Semantic name remains unreviewed. */

void FUN_000113ec(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00011440 FUN_00011440 */

/* Boundary evidence: original MIPS .pdata 00011440..0001147b. Semantic name remains unreviewed. */

void FUN_00011440(void)

{
  FUN_000113ec((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_000113ec((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 0001147c FUN_0001147c */

/* Boundary evidence: original MIPS .pdata 0001147c..000114ef. Semantic name remains unreviewed. */

void FUN_0001147c(void)

{
  uint uVar1;
  
  if ((DAT_0001309c == 0) || (DAT_0001309c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0001309c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0001309c == 0) {
      DAT_0001309c = 0xb064;
    }
  }
  DAT_000130a0 = ~DAT_0001309c;
  return;
}



/* 00011560 FUN_00011560 */

/* Boundary evidence: original MIPS .pdata 00011560..000115c7. Semantic name remains unreviewed. */

undefined4 FUN_00011560(STRSAFE_LPCWSTR param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00011cd4(param_1);
  if (param_1 != (STRSAFE_LPCWSTR)0x0) {
    LocalFree(param_1);
  }
  InterlockedDecrement(&DAT_00013118);
  PostMessageW(DAT_00013114,0xfad,0,0);
  return uVar1;
}



/* 000115c8 FUN_000115c8 */

/* Boundary evidence: original MIPS .pdata 000115c8..0001169f. Semantic name remains unreviewed. */

undefined4 FUN_000115c8(int param_1)

{
  HLOCAL _Dst;
  HANDLE hObject;
  uint uVar1;
  
  if ((((param_1 != 0) && (uVar1 = *(uint *)(param_1 + 4), uVar1 != 0)) &&
      (*(int *)(param_1 + 8) != 0)) &&
     ((uVar1 <= uVar1 + 2 && (_Dst = LocalAlloc(0x40,uVar1 + 2), _Dst != (HLOCAL)0x0)))) {
    memcpy(_Dst,*(void **)(param_1 + 8),*(size_t *)(param_1 + 4));
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00011560,_Dst,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      InterlockedIncrement(&DAT_00013118);
      CloseHandle(hObject);
      return 1;
    }
    LocalFree(_Dst);
  }
  return 0;
}



/* 000116a0 FUN_000116a0 */

/* Boundary evidence: original MIPS .pdata 000116a0..00011747. Semantic name remains unreviewed. */

LRESULT FUN_000116a0(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  
  if (param_2 != 1) {
    if (param_2 == 2) {
      PostQuitMessage(0);
    }
    else if (param_2 == 0x4a) {
      if (DAT_00013118 != 0) {
        LVar1 = FUN_000115c8(param_4);
        return LVar1;
      }
    }
    else {
      if (param_2 != 0xfad) {
        LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
        return LVar1;
      }
      if (DAT_00013118 == 0) {
        PostMessageW(param_1,0x10,0,0);
      }
    }
  }
  return 0;
}



/* 00011748 FUN_00011748 */

/* Boundary evidence: original MIPS .pdata 00011748..000118bb. Semantic name remains unreviewed. */

undefined4 FUN_00011748(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  ATOM AVar1;
  size_t sVar2;
  HWND hWnd;
  LRESULT LVar3;
  undefined2 extraout_var;
  int iVar4;
  BOOL BVar5;
  undefined1 auStack_68 [4];
  int local_64;
  wchar_t *local_60;
  MSG MStack_58;
  WNDCLASSW WStack_38;
  
  if ((param_3 == (wchar_t *)0x0) || (*param_3 == L'\0')) {
    return 0;
  }
  memset(auStack_68,0,0xc);
  sVar2 = wcslen(param_3);
  local_64 = (sVar2 + 1) * 2;
  local_60 = param_3;
  hWnd = FindWindowW(L"CTLPNL_Class",(LPCWSTR)0x0);
  if ((hWnd == (HWND)0x0) || (LVar3 = SendMessageW(hWnd,0x4a,0,(LPARAM)auStack_68), LVar3 == 0)) {
    DAT_00013118 = 0;
    memset(&WStack_38,0,0x28);
    WStack_38.lpfnWndProc = FUN_000116a0;
    WStack_38.lpszClassName = L"CTLPNL_Class";
    WStack_38.hInstance = param_1;
    AVar1 = RegisterClassW(&WStack_38);
    if (CONCAT22(extraout_var,AVar1) == 0) {
      return 0;
    }
    DAT_00013114 = CreateWindowExW(0,L"CTLPNL_Class",(LPCWSTR)0x0,0,0,0,0,0,(HWND)0x0,(HMENU)0x0,
                                   param_1,(LPVOID)0x0);
    if (DAT_00013114 == (HWND)0x0) {
      return 0;
    }
    iVar4 = FUN_000115c8((int)auStack_68);
    if (iVar4 == 0) {
      return 0;
    }
    while (BVar5 = GetMessageW(&MStack_58,(HWND)0x0,0,0), BVar5 != 0) {
      TranslateMessage(&MStack_58);
      DispatchMessageW(&MStack_58);
    }
    UnregisterClassW(L"CTLPNL_Class",param_1);
  }
  return 1;
}



/* 000118bc FUN_000118bc */

/* Boundary evidence: original MIPS .pdata 000118bc..00011927. Semantic name remains unreviewed. */

wchar_t * FUN_000118bc(wchar_t *param_1)

{
  size_t sVar1;
  wchar_t *_Dest;
  
  if (param_1 == (wchar_t *)0x0) {
    _Dest = (wchar_t *)0x0;
  }
  else {
    sVar1 = wcslen(param_1);
    _Dest = LocalAlloc(0x40,(sVar1 + 1) * 2);
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,param_1);
    }
  }
  return _Dest;
}



/* 00011928 FUN_00011928 */

/* Boundary evidence: original MIPS .pdata 00011928..00011b07. Semantic name remains unreviewed. */

void FUN_00011928(long *param_1,STRSAFE_LPCWSTR param_2)

{
  size_t sVar1;
  wchar_t *pwVar2;
  long lVar3;
  wchar_t *pwVar4;
  wchar_t awStack_c0 [79];
  undefined2 local_22;
  uint local_20;
  
  local_20 = DAT_0001309c;
  StringCchCopyExW(awStack_c0,0x50,param_2,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800);
  local_22 = 0;
  sVar1 = wcslen(awStack_c0);
  pwVar4 = awStack_c0 + sVar1;
  pwVar2 = wcstok(awStack_c0,L" ,");
  if ((pwVar2 != (wchar_t *)0x0) && (pwVar2 < pwVar4)) {
    StringCbCopyExW((STRSAFE_LPWSTR)(param_1 + 2),0x208,pwVar2,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,
                    0x800);
    sVar1 = wcslen(pwVar2);
    pwVar2 = pwVar2 + sVar1 + 1;
    if ((pwVar2 != (wchar_t *)0x0) &&
       (((pwVar2 < pwVar4 && (pwVar2 = wcstok(pwVar2,L" ,"), pwVar2 != (wchar_t *)0x0)) &&
        (pwVar2 < pwVar4)))) {
      if (((ushort)*pwVar2 < 0x30) || (0x39 < (ushort)*pwVar2)) {
        sVar1 = wcslen(pwVar2);
        pwVar2 = pwVar2 + sVar1 + 1;
        if ((pwVar2 == (wchar_t *)0x0) ||
           (((pwVar4 <= pwVar2 || (pwVar2 = wcstok(pwVar2,L" ,"), pwVar2 == (wchar_t *)0x0)) ||
            (pwVar4 <= pwVar2)))) goto LAB_00011ae0;
      }
      lVar3 = _wtol(pwVar2);
      *param_1 = lVar3;
      sVar1 = wcslen(pwVar2);
      pwVar2 = pwVar2 + sVar1 + 1;
      if ((((pwVar2 != (wchar_t *)0x0) && (pwVar2 < pwVar4)) &&
          (pwVar2 = wcstok(pwVar2,L" ,"), pwVar2 != (wchar_t *)0x0)) && (pwVar2 < pwVar4)) {
        lVar3 = _wtol(pwVar2);
        param_1[1] = lVar3;
      }
    }
  }
LAB_00011ae0:
  FUN_00011ed4(local_20);
  return;
}



/* 00011b08 FUN_00011b08 */

/* Boundary evidence: original MIPS .pdata 00011b08..00011cd3. Semantic name remains unreviewed. */

undefined4 FUN_00011b08(int *param_1)

{
  wchar_t *_Str;
  wchar_t *pwVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  wchar_t *_Str_00;
  uint uVar5;
  int iVar6;
  
  iVar4 = *param_1;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  if (1 < iVar4) {
    iVar4 = 0;
  }
  _Str = FUN_000118bc((wchar_t *)(param_1 + 2));
  _Str_00 = _Str;
  if (_Str != (wchar_t *)0x0) {
    pwVar1 = wcsrchr(_Str,L'.');
    if (pwVar1 != (wchar_t *)0x0) {
      *pwVar1 = L'\0';
    }
    pwVar1 = wcsrchr(_Str,L'\\');
    if (pwVar1 != (wchar_t *)0x0) {
      *pwVar1 = L'\0';
      _Str_00 = pwVar1 + 1;
    }
    sVar2 = wcslen(_Str_00);
    if (sVar2 != 0) {
      if ((_Str_00[sVar2 - 1] == L'g') || (_Str_00[sVar2 - 1] == L'G')) {
        _Str_00[sVar2 - 1] = L'\0';
      }
    }
  }
  iVar6 = 0;
  uVar5 = 0;
  do {
    iVar3 = lstrcmpiW(_Str_00,*(LPCWSTR *)((int)&PTR_u_comm_000130a4 + uVar5));
    if (iVar3 == 0) {
      iVar4 = (&DAT_000130a8)[iVar6 * 3 + iVar4];
      if (iVar4 == -1) {
        iVar4 = (&DAT_000130a8)[iVar6 * 3];
      }
      *param_1 = iVar4;
      wcscpy((wchar_t *)(param_1 + 2),L"CPLMAIN.CPL");
      if (_Str != (wchar_t *)0x0) {
        LocalFree(_Str);
      }
      return 1;
    }
    uVar5 = uVar5 + 0xc;
    iVar6 = iVar6 + 1;
  } while (uVar5 < 0x6c);
  if (_Str != (wchar_t *)0x0) {
    LocalFree(_Str);
  }
  return 0;
}



/* 00011cd4 FUN_00011cd4 */

/* Boundary evidence: original MIPS .pdata 00011cd4..00011e53. Semantic name remains unreviewed. */

undefined4 FUN_00011cd4(STRSAFE_LPCWSTR param_1)

{
  HMODULE hLibModule;
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  long local_230;
  undefined2 local_22c [2];
  WCHAR local_228 [260];
  uint local_20;
  
  local_20 = DAT_0001309c;
  local_230 = 0;
  memset(local_22c,0,0x20c);
  uVar3 = 0;
  FUN_00011928(&local_230,param_1);
  if (local_228[0] == L'\0') goto LAB_00011e2c;
  hLibModule = LoadLibraryW(local_228);
  if ((hLibModule == (HMODULE)0x0) || (iVar1 = GetProcAddressW(hLibModule,L"CPlApplet"), iVar1 == 0)
     ) {
    iVar1 = FUN_00011b08(&local_230);
    if (iVar1 != 0) {
      hLibModule = LoadLibraryW(local_228);
      if (hLibModule == (HMODULE)0x0) goto LAB_00011e2c;
      goto LAB_00011d84;
    }
  }
  else {
LAB_00011d84:
    pcVar2 = (code *)GetProcAddressW(hLibModule,L"CPlApplet");
    if (pcVar2 != (code *)0x0) {
      uVar3 = 1;
      (*pcVar2)(0,1,0,0);
      (*pcVar2)(0,5,CONCAT22(local_22c[0],(undefined2)local_230),0);
      iVar1 = local_230;
      if (local_230 < 0) {
        iVar1 = -local_230;
      }
      (*pcVar2)(0,6,iVar1,0);
      (*pcVar2)(0,7,0,0);
    }
  }
  if (hLibModule != (HMODULE)0x0) {
    FreeLibrary(hLibModule);
  }
LAB_00011e2c:
  FUN_00011ed4(local_20);
  return uVar3;
}



/* 00011e54 FUN_00011e54 */

/* Boundary evidence: original MIPS .pdata 00011e54..00011ea7. Semantic name remains unreviewed. */

void FUN_00011e54(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00011ed4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00011ea8 FUN_00011ea8 */

/* Boundary evidence: original MIPS .pdata 00011ea8..00011ed3. Semantic name remains unreviewed. */

undefined4 FUN_00011ea8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00011e54(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00011ed4 FUN_00011ed4 */

/* Boundary evidence: original MIPS .pdata 00011ed4..00011f1b. Semantic name remains unreviewed. */

void FUN_00011ed4(uint param_1)

{
  if ((param_1 == DAT_0001309c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


