/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..0001116b. Semantic name remains unreviewed. */

undefined4 FUN_00011000(int param_1,undefined4 *param_2)

{
  HDC hdc;
  int iVar1;
  undefined4 local_480 [2];
  undefined4 local_478 [2];
  undefined4 local_470;
  wchar_t *local_468;
  wchar_t *local_464;
  undefined4 local_45c;
  wchar_t local_438;
  undefined1 auStack_436 [1038];
  uint local_28;
  
  local_28 = DAT_0001306c;
  local_480[0] = 1;
  hdc = GetDC((HWND)0x0);
  ExtEscape(hdc,0x229c7c,4,(LPCSTR)local_480,0,(LPSTR)0x0);
  ReleaseDC((HWND)0x0,hdc);
  NKDbgPrintfW(L"setOSOverlayActivate(bActivate %d)",local_480[0]);
  local_438 = L'\0';
  memset(auStack_436,0,0x40e);
  iVar1 = 1;
  if (1 < param_1) {
    do {
      param_2 = param_2 + 1;
      wcscat(&local_438,(wchar_t *)*param_2);
      if (iVar1 != param_1 + -1) {
        wcscat(&local_438,L" ");
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1);
  }
  memset(local_478,0,0x3c);
  local_464 = &local_438;
  local_468 = L"\\Storage Card4\\NNG\\nngnavi.exe";
  local_478[0] = 0x3c;
  local_45c = 1;
  local_470 = 0;
  ShellExecuteEx(local_478);
  FUN_0001178c(local_28);
  return 0;
}



/* 000111ac FUN_000111ac */

/* Boundary evidence: original MIPS .pdata 000111ac..000111d7. Semantic name remains unreviewed. */

void FUN_000111ac(void)

{
  if (DAT_00013074 != (void *)0x0) {
    free(DAT_00013074);
  }
  return;
}



/* 000111d8 FUN_000111d8 */

/* Boundary evidence: original MIPS .pdata 000111d8..00011267. Semantic name remains unreviewed. */

int FUN_000111d8(wint_t *param_1)

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



/* 00011268 FUN_00011268 */

/* Boundary evidence: original MIPS .pdata 00011268..0001132b. Semantic name remains unreviewed. */

void FUN_00011268(int *param_1,int *param_2,wint_t *param_3)

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
    iVar2 = FUN_000111d8(pwVar3);
    *param_2 = *param_2 + iVar2 + 1;
    param_3 = pwVar3 + iVar2;
    *param_1 = *param_1 + 1;
    if (*param_3 == 0) {
      return;
    }
  }
  return;
}



/* 0001132c FUN_0001132c */

/* Boundary evidence: original MIPS .pdata 0001132c..00011503. Semantic name remains unreviewed. */

undefined4 FUN_0001132c(wchar_t *param_1,wint_t *param_2,int *param_3,undefined4 *param_4)

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
    FUN_00011268(&local_38,(int *)&local_34,param_2);
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
        iVar6 = FUN_000111d8(pwVar10);
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



/* 00011504 FUN_00011504 */

/* Boundary evidence: original MIPS .pdata 00011504..000115fb. Semantic name remains unreviewed. */

void FUN_00011504(HMODULE param_1,wint_t *param_2)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  int local_224;
  undefined4 *local_220 [2];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_0001306c;
  DAT_0001307c = param_1;
  DVar1 = GetModuleFileNameW(param_1,aWStack_218,0x100);
  if (DVar1 == 0) {
    FUN_00011974(0xfffffffd);
  }
  FUN_00011c94(FUN_000111ac);
  FUN_00011a14();
  iVar2 = FUN_0001132c(aWStack_218,param_2,&local_224,local_220);
  if (iVar2 == 0) {
    FUN_00011974(0xfffffffc);
  }
  DAT_00013078 = local_224;
  DAT_00013074 = local_220[0];
  UVar3 = FUN_00011000(local_224,local_220[0]);
  FUN_00011954(UVar3);
  FUN_00011974(UVar3);
  FUN_0001178c(local_18);
  return;
}



/* 000115fc FUN_000115fc */

/* Boundary evidence: original MIPS .pdata 000115fc..0001163b. Semantic name remains unreviewed. */

void FUN_000115fc(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x228) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x228),param_1);
  return;
}



/* 0001163c entry */

/* Boundary evidence: original MIPS .pdata 0001163c..00011677. Semantic name remains unreviewed. */

void entry(HMODULE param_1,undefined4 param_2,wint_t *param_3)

{
  FUN_00011678();
  FUN_00011504(param_1,param_3);
  return;
}



/* 00011678 FUN_00011678 */

/* Boundary evidence: original MIPS .pdata 00011678..000116eb. Semantic name remains unreviewed. */

void FUN_00011678(void)

{
  uint uVar1;
  
  if ((DAT_0001306c == 0) || (DAT_0001306c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0001306c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0001306c == 0) {
      DAT_0001306c = 0xb064;
    }
  }
  DAT_00013070 = ~DAT_0001306c;
  return;
}



/* 000116ec FUN_000116ec */

/* Boundary evidence: original MIPS .pdata 000116ec..0001173f. Semantic name remains unreviewed. */

void FUN_000116ec(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0001178c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00011740 FUN_00011740 */

/* Boundary evidence: original MIPS .pdata 00011740..0001176b. Semantic name remains unreviewed. */

undefined4 FUN_00011740(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_000116ec(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0001178c FUN_0001178c */

/* Boundary evidence: original MIPS .pdata 0001178c..000117d3. Semantic name remains unreviewed. */

void FUN_0001178c(uint param_1)

{
  if ((param_1 == DAT_0001306c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00011834 FUN_00011834 */

/* Boundary evidence: original MIPS .pdata 00011834..00011953. Semantic name remains unreviewed. */

void FUN_00011834(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00013080 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00013088;
    if (DAT_00013088 != (undefined4 *)0x0) {
      while (DAT_00013084 = DAT_00013084 + -1, _Memory <= DAT_00013084) {
        if ((code *)*DAT_00013084 != (code *)0x0) {
          (*(code *)*DAT_00013084)();
          _Memory = DAT_00013088;
        }
      }
      free(_Memory);
      DAT_00013084 = (undefined4 *)0x0;
      DAT_00013088 = (undefined4 *)0x0;
    }
    FUN_000119c0((undefined4 *)&DAT_00012010,(undefined4 *)&DAT_00012014);
  }
  FUN_000119c0((undefined4 *)&DAT_00012018,(undefined4 *)&DAT_0001201c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_0001308c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011954 FUN_00011954 */

/* Boundary evidence: original MIPS .pdata 00011954..00011973. Semantic name remains unreviewed. */

void FUN_00011954(UINT param_1)

{
  FUN_00011834(param_1,0,0);
  return;
}



/* 00011974 FUN_00011974 */

/* Boundary evidence: original MIPS .pdata 00011974..000119bf. Semantic name remains unreviewed. */

void FUN_00011974(UINT param_1)

{
  DAT_00013080 = 0;
  FUN_000119c0((undefined4 *)&DAT_00012018,(undefined4 *)&DAT_0001201c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000119c0 FUN_000119c0 */

/* Boundary evidence: original MIPS .pdata 000119c0..00011a13. Semantic name remains unreviewed. */

void FUN_000119c0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00011a14 FUN_00011a14 */

/* Boundary evidence: original MIPS .pdata 00011a14..00011a4f. Semantic name remains unreviewed. */

void FUN_00011a14(void)

{
  FUN_000119c0((undefined4 *)&DAT_00012008,(undefined4 *)&DAT_0001200c);
  FUN_000119c0((undefined4 *)&DAT_00012000,(undefined4 *)&DAT_00012004);
  return;
}



/* 00011a50 FUN_00011a50 */

/* Boundary evidence: original MIPS .pdata 00011a50..00011b5b. Semantic name remains unreviewed. */

undefined4 FUN_00011a50(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_00013088;
  puVar3 = DAT_00013084;
  iVar4 = (int)DAT_00013084 - (int)DAT_00013088;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_00011a94:
    param_1 = 0;
  }
  else {
    if (DAT_00013088 != (void *)0x0) {
      uVar1 = _msize(DAT_00013088);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_00011b08:
        if (pvVar2 == (void *)0x0) goto LAB_00011a94;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_00011b08;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00013084 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_00013088 = pvVar2;
  }
  return param_1;
}



/* 00011b5c FUN_00011b5c */

/* Boundary evidence: original MIPS .pdata 00011b5c..00011c47. Semantic name remains unreviewed. */

undefined4 FUN_00011b5c(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_0001308c == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_0001308c,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_0001308c == (LPCRITICAL_SECTION)0x0) goto LAB_00011c00;
  }
  EnterCriticalSection(DAT_0001308c);
LAB_00011c00:
  uVar2 = FUN_00011a50(param_1);
  FUN_00011c48();
  return uVar2;
}



/* 00011c48 FUN_00011c48 */

/* Boundary evidence: original MIPS .pdata 00011c48..00011c93. Semantic name remains unreviewed. */

void FUN_00011c48(void)

{
  if (DAT_0001308c != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_0001308c);
  }
  return;
}



/* 00011c94 FUN_00011c94 */

/* Boundary evidence: original MIPS .pdata 00011c94..00011cc3. Semantic name remains unreviewed. */

undefined4 FUN_00011c94(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00011b5c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00011cc4 FUN_00011cc4 */

/* Boundary evidence: original MIPS .pdata 00011cc4..00011d3f. Semantic name remains unreviewed. */

void FUN_00011cc4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_000116ec(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}


