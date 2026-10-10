/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00012294 FUN_00012294 */

/* Boundary evidence: original MIPS .pdata 00012294..000122bf. Semantic name remains unreviewed. */

void FUN_00012294(void)

{
  if (DAT_00015128 != (void *)0x0) {
    free(DAT_00015128);
  }
  return;
}



/* 000122c0 FUN_000122c0 */

/* Boundary evidence: original MIPS .pdata 000122c0..0001234f. Semantic name remains unreviewed. */

int FUN_000122c0(wint_t *param_1)

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



/* 00012350 FUN_00012350 */

/* Boundary evidence: original MIPS .pdata 00012350..00012413. Semantic name remains unreviewed. */

void FUN_00012350(int *param_1,int *param_2,wint_t *param_3)

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
    iVar2 = FUN_000122c0(pwVar3);
    *param_2 = *param_2 + iVar2 + 1;
    param_3 = pwVar3 + iVar2;
    *param_1 = *param_1 + 1;
    if (*param_3 == 0) {
      return;
    }
  }
  return;
}



/* 00012414 FUN_00012414 */

/* Boundary evidence: original MIPS .pdata 00012414..000125eb. Semantic name remains unreviewed. */

undefined4 FUN_00012414(wchar_t *param_1,wint_t *param_2,int *param_3,undefined4 *param_4)

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
    FUN_00012350(&local_38,(int *)&local_34,param_2);
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
        iVar6 = FUN_000122c0(pwVar10);
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



/* 000125ec FUN_000125ec */

/* Boundary evidence: original MIPS .pdata 000125ec..000126e3. Semantic name remains unreviewed. */

void FUN_000125ec(HMODULE param_1,wint_t *param_2)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  int *piVar4;
  wchar_t **ppwVar5;
  int local_224;
  wchar_t *local_220 [2];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_000150d0;
  DAT_00015130 = param_1;
  DVar1 = GetModuleFileNameW(param_1,aWStack_218,0x100);
  if (DVar1 == 0) {
    FUN_000128a0(0xfffffffd);
  }
  FUN_00012bc0(FUN_00012294);
  FUN_00012940();
  ppwVar5 = local_220;
  piVar4 = &local_224;
  iVar2 = FUN_00012414(aWStack_218,param_2,piVar4,ppwVar5);
  if (iVar2 == 0) {
    FUN_000128a0(0xfffffffc);
  }
  DAT_0001512c = local_224;
  DAT_00015128 = local_220[0];
  UVar3 = FUN_000142a8(local_224,local_220[0],piVar4,ppwVar5);
  FUN_00012880(UVar3);
  FUN_000128a0(UVar3);
  FUN_00012ce0(local_18);
  return;
}



/* 000126e4 FUN_000126e4 */

/* Boundary evidence: original MIPS .pdata 000126e4..00012723. Semantic name remains unreviewed. */

void FUN_000126e4(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x228) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x228),param_1);
  return;
}



/* 00012724 entry */

/* Boundary evidence: original MIPS .pdata 00012724..0001275f. Semantic name remains unreviewed. */

void entry(HMODULE param_1,undefined4 param_2,wint_t *param_3)

{
  FUN_00012bf0();
  FUN_000125ec(param_1,param_3);
  return;
}



/* 00012760 FUN_00012760 */

/* Boundary evidence: original MIPS .pdata 00012760..0001287f. Semantic name remains unreviewed. */

void FUN_00012760(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00015134 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_0001514c;
    if (DAT_0001514c != (undefined4 *)0x0) {
      while (DAT_00015148 = DAT_00015148 + -1, _Memory <= DAT_00015148) {
        if ((code *)*DAT_00015148 != (code *)0x0) {
          (*(code *)*DAT_00015148)();
          _Memory = DAT_0001514c;
        }
      }
      free(_Memory);
      DAT_00015148 = (undefined4 *)0x0;
      DAT_0001514c = (undefined4 *)0x0;
    }
    FUN_000128ec((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_000128ec((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_00015150,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00012880 FUN_00012880 */

/* Boundary evidence: original MIPS .pdata 00012880..0001289f. Semantic name remains unreviewed. */

void FUN_00012880(UINT param_1)

{
  FUN_00012760(param_1,0,0);
  return;
}



/* 000128a0 FUN_000128a0 */

/* Boundary evidence: original MIPS .pdata 000128a0..000128eb. Semantic name remains unreviewed. */

void FUN_000128a0(UINT param_1)

{
  DAT_00015134 = 0;
  FUN_000128ec((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000128ec FUN_000128ec */

/* Boundary evidence: original MIPS .pdata 000128ec..0001293f. Semantic name remains unreviewed. */

void FUN_000128ec(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00012940 FUN_00012940 */

/* Boundary evidence: original MIPS .pdata 00012940..0001297b. Semantic name remains unreviewed. */

void FUN_00012940(void)

{
  FUN_000128ec((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_000128ec((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 0001297c FUN_0001297c */

/* Boundary evidence: original MIPS .pdata 0001297c..00012a87. Semantic name remains unreviewed. */

undefined4 FUN_0001297c(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_0001514c;
  puVar3 = DAT_00015148;
  iVar4 = (int)DAT_00015148 - (int)DAT_0001514c;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_000129c0:
    param_1 = 0;
  }
  else {
    if (DAT_0001514c != (void *)0x0) {
      uVar1 = _msize(DAT_0001514c);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_00012a34:
        if (pvVar2 == (void *)0x0) goto LAB_000129c0;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_00012a34;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00015148 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_0001514c = pvVar2;
  }
  return param_1;
}



/* 00012a88 FUN_00012a88 */

/* Boundary evidence: original MIPS .pdata 00012a88..00012b73. Semantic name remains unreviewed. */

undefined4 FUN_00012a88(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_00015150 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_00015150,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_00015150 == (LPCRITICAL_SECTION)0x0) goto LAB_00012b2c;
  }
  EnterCriticalSection(DAT_00015150);
LAB_00012b2c:
  uVar2 = FUN_0001297c(param_1);
  FUN_00012b74();
  return uVar2;
}



/* 00012b74 FUN_00012b74 */

/* Boundary evidence: original MIPS .pdata 00012b74..00012bbf. Semantic name remains unreviewed. */

void FUN_00012b74(void)

{
  if (DAT_00015150 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_00015150);
  }
  return;
}



/* 00012bc0 FUN_00012bc0 */

/* Boundary evidence: original MIPS .pdata 00012bc0..00012bef. Semantic name remains unreviewed. */

undefined4 FUN_00012bc0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00012a88(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00012bf0 FUN_00012bf0 */

/* Boundary evidence: original MIPS .pdata 00012bf0..00012c63. Semantic name remains unreviewed. */

void FUN_00012bf0(void)

{
  uint uVar1;
  
  if ((DAT_000150d0 == 0) || (DAT_000150d0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000150d0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000150d0 == 0) {
      DAT_000150d0 = 0xb064;
    }
  }
  DAT_000150d4 = ~DAT_000150d0;
  return;
}



/* 00012c64 FUN_00012c64 */

/* Boundary evidence: original MIPS .pdata 00012c64..00012cdf. Semantic name remains unreviewed. */

void FUN_00012c64(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_00012d28(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 00012ce0 FUN_00012ce0 */

/* Boundary evidence: original MIPS .pdata 00012ce0..00012d27. Semantic name remains unreviewed. */

void FUN_00012ce0(uint param_1)

{
  if ((param_1 == DAT_000150d0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00012d28 FUN_00012d28 */

/* Boundary evidence: original MIPS .pdata 00012d28..00012d7b. Semantic name remains unreviewed. */

void FUN_00012d28(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012ce0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00012d7c FUN_00012d7c */

/* Boundary evidence: original MIPS .pdata 00012d7c..00012da7. Semantic name remains unreviewed. */

undefined4 FUN_00012d7c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00012d28(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00012ed8 FUN_00012ed8 */

/* Boundary evidence: original MIPS .pdata 00012ed8..00012ff7. Semantic name remains unreviewed. */

size_t FUN_00012ed8(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                   )

{
  HRESULT HVar1;
  size_t sVar2;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_000150d0;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  HVar1 = StringCchVPrintfW(awStack_218,0x100,param_1,(va_list)&local_res4);
  if (HVar1 != 0) {
    FUN_00012ce0(local_18);
    return 0;
  }
  sVar2 = wcslen(awStack_218);
  if (DAT_00015144 == 0) {
    if (DAT_0001513c == (code *)0x0) {
      DAT_00015138 = LoadLibraryW(L"coredll.dll");
      if (DAT_00015138 != (HMODULE)0x0) {
        DAT_0001513c = (code *)GetProcAddressW(DAT_00015138,L"wprintf");
      }
      if (DAT_0001513c != (code *)0x0) goto LAB_00012fac;
      DAT_00015144 = 1;
    }
    else {
LAB_00012fac:
      (*DAT_0001513c)(&UNK_00011170,awStack_218);
    }
    if (DAT_00015144 == 0) goto LAB_00012fd4;
  }
  OutputDebugStringW(awStack_218);
LAB_00012fd4:
  FUN_00012ce0(local_18);
  return sVar2;
}



/* 00012ff8 FUN_00012ff8 */

/* Boundary evidence: original MIPS .pdata 00012ff8..0001305b. Semantic name remains unreviewed. */

void FUN_00012ff8(DWORD param_1)

{
  undefined4 uVar1;
  HLOCAL local_10 [2];
  
  uVar1 = 0x400;
  local_10[0] = (HLOCAL)0x0;
  FormatMessageW(0x1300,(LPCVOID)0x0,param_1,0x400,(LPWSTR)local_10,0,(va_list *)0x0);
  if (local_10[0] != (HLOCAL)0x0) {
    FUN_00012ed8(L"%ls",local_10[0],param_1,uVar1);
    LocalFree(local_10[0]);
  }
  return;
}



/* 0001305c FUN_0001305c */

/* Boundary evidence: original MIPS .pdata 0001305c..0001313b. Semantic name remains unreviewed. */

undefined4 FUN_0001305c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  undefined4 uVar2;
  size_t *psVar3;
  int *_Memory;
  size_t local_18 [2];
  
  psVar3 = local_18;
  uVar2 = 0;
  local_18[0] = 0;
  _Memory = (int *)0x0;
  DVar1 = GetPerAdapterInfo(param_1);
  if (DVar1 == 0x6f) {
    _Memory = malloc(local_18[0]);
    if (_Memory == (int *)0x0) {
      FUN_00012ed8(L"Insufficient Memory\n",uVar2,psVar3,param_4);
      FUN_00012880(1);
    }
    DVar1 = GetPerAdapterInfo(param_1,_Memory,local_18);
    if (DVar1 != 0) {
      FUN_00012ff8(DVar1);
      FUN_00012880(1);
    }
    if (*_Memory != 0) {
      uVar2 = 1;
      goto LAB_00013114;
    }
  }
  else if (DVar1 != 0) {
    FUN_00012ff8(DVar1);
    FUN_00012880(1);
  }
  uVar2 = 0;
LAB_00013114:
  if (_Memory != (int *)0x0) {
    free(_Memory);
  }
  return uVar2;
}



/* 0001313c FUN_0001313c */

/* Boundary evidence: original MIPS .pdata 0001313c..0001317f. Semantic name remains unreviewed. */

void FUN_0001313c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00012ed8(L"usage : ipconfig [/? | /all | /d |/renew [adapter index] | /release [adapter index] ] /flushdns\r\n\r\n    /d    Display redirected to the Debug Output Port \r\n"
               ,param_2,param_3,param_4);
  FUN_00012ed8(L"    /?    Display this help message. \r\n    /all  Display full configuration information.\r\n"
               ,param_2,param_3,param_4);
  FUN_00012ed8(L"    /release   Release the IP address for the specified adapter \r\n",param_2,
               param_3,param_4);
  FUN_00012ed8(L"    /renew     Renew the IP address for the specified adapter \r\n    /flushdns  Clear the name resolution client cache \r\n\r\n The default is to display only the IP address, subnet mask and default gateway  for each adapter bound to TCP/IP. \r\n"
               ,param_2,param_3,param_4);
  return;
}



/* 00013180 FUN_00013180 */

/* Boundary evidence: original MIPS .pdata 00013180..0001325f. Semantic name remains unreviewed. */

LPWSTR FUN_00013180(int param_1,uint param_2)

{
  bool bVar1;
  LPWSTR pWVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint uVar5;
  LPWSTR pWVar6;
  
  bVar1 = true;
  pWVar2 = LocalAlloc(0x40,param_2 * 6 + 2);
  if (pWVar2 == (LPWSTR)0x0) {
    pWVar2 = (LPWSTR)0x0;
  }
  else {
    uVar5 = 0;
    if (param_2 != 0) {
      pWVar6 = pWVar2;
      do {
        pwVar4 = L"%02x";
        if (!bVar1) {
          pwVar4 = L" %02x";
        }
        iVar3 = wsprintfW(pWVar6,pwVar4,(uint)*(byte *)(uVar5 + param_1));
        uVar5 = uVar5 + 1;
        pWVar6 = pWVar6 + iVar3;
        bVar1 = false;
      } while (uVar5 < param_2);
    }
  }
  return pWVar2;
}



/* 00013260 FUN_00013260 */

/* Boundary evidence: original MIPS .pdata 00013260..0001333f. Semantic name remains unreviewed. */

void FUN_00013260(undefined4 param_1,int param_2,wchar_t *param_3)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  undefined4 local_120 [2];
  wchar_t awStack_118 [128];
  uint local_18;
  
  local_18 = DAT_000150d0;
  local_120[0] = 0x80;
  pwVar3 = awStack_118;
  uVar2 = 0;
  iVar1 = WSAAddressToStringW(param_1,0x1c,0,pwVar3,local_120);
  if (iVar1 == 0) {
    if (param_3 != (wchar_t *)0x0) {
      wcscat(awStack_118,L" ");
      wcscat(awStack_118,param_3);
    }
  }
  else {
    wcscpy(awStack_118,L"<invalid>");
  }
  if (param_2 == 0) {
    FUN_00012ed8(L"\t                       %s\n",awStack_118,uVar2,pwVar3);
  }
  else {
    FUN_00012ed8(L"\t %s %s\n",param_2,awStack_118,pwVar3);
  }
  FUN_00012ce0(local_18);
  return;
}



/* 00013340 FUN_00013340 */

/* Boundary evidence: original MIPS .pdata 00013340..000136ff. Semantic name remains unreviewed. */

void FUN_00013340(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  HANDLE hDevice;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  DWORD aDStack_120 [2];
  undefined1 auStack_118 [88];
  undefined2 local_c0;
  undefined2 local_be;
  uint local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 auStack_a0 [16];
  int local_90;
  int local_8c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 auStack_68 [20];
  int local_54;
  uint local_30;
  
  local_30 = DAT_000150d0;
  if (param_1 != 0) {
    if (param_2 == 0) goto LAB_000136c8;
    do {
      if (*(int *)(param_2 + 4) == *(int *)(param_1 + 0x19c)) break;
      param_2 = *(int *)(param_2 + 8);
    } while (param_2 != 0);
  }
  if (((param_2 != 0) && (*(int *)(param_2 + 0x48) != 0)) &&
     (bVar1 = param_4 == 0, (*(uint *)(param_2 + 0x44) & 1) != 0)) {
    if (param_3 == 0) {
      iVar5 = *(int *)(param_2 + 0x10);
      if (iVar5 != 0) {
        do {
          if (**(short **)(iVar5 + 0xc) == 0x17) {
            iVar4 = *(int *)(iVar5 + 0x14);
            if ((iVar4 != 1) || (pwVar2 = L"[Manual]", *(int *)(iVar5 + 0x18) != 1)) {
              if (iVar4 == 4) {
                if (*(int *)(iVar5 + 0x18) == 4) {
                  pwVar2 = L"[Public]";
                }
                else {
                  if (*(int *)(iVar5 + 0x18) != 5) goto LAB_00013684;
                  pwVar2 = L"[Temporary]";
                }
              }
              else {
LAB_00013684:
                if ((iVar4 != 3) || (pwVar2 = L"[DHCP]", *(int *)(iVar5 + 0x18) != 3)) {
                  pwVar2 = (wchar_t *)0x0;
                }
              }
            }
            pwVar3 = L"IP Address ........ :";
            if (!bVar1) {
              pwVar3 = (wchar_t *)0x0;
            }
            FUN_00013260(*(short **)(iVar5 + 0xc),(int)pwVar3,pwVar2);
            bVar1 = false;
          }
          iVar5 = *(int *)(iVar5 + 8);
        } while (iVar5 != 0);
      }
    }
    else if (param_3 == 3) {
      iVar5 = *(int *)(param_2 + 0x1c);
      if (iVar5 != 0) {
        do {
          if (**(short **)(iVar5 + 0xc) == 0x17) {
            pwVar2 = L"DNS Servers ......  :";
            if (!bVar1) {
              pwVar2 = (wchar_t *)0x0;
            }
            FUN_00013260(*(short **)(iVar5 + 0xc),(int)pwVar2,(wchar_t *)0x0);
            bVar1 = false;
          }
          iVar5 = *(int *)(iVar5 + 8);
        } while (iVar5 != 0);
      }
    }
    else if (param_3 == 4) {
      hDevice = CreateFileW(L"IP60:",0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
      local_54 = 0;
      do {
        memcpy(auStack_a0,auStack_68,0x38);
        DeviceIoControl(hDevice,0x120034,auStack_a0,0x38,auStack_118,0x54,aDStack_120,
                        (LPOVERLAPPED)0x0);
        memcpy(auStack_68,auStack_118,0x38);
        iVar5 = local_8c;
        if (((local_8c != 0) && (memcpy(auStack_118,auStack_a0,0x38), local_90 == 0)) &&
           (*(int *)(param_2 + 0x48) == iVar5)) {
          local_b8 = local_78;
          local_b4 = local_74;
          local_c0 = 0x17;
          local_b0 = local_70;
          local_ac = local_6c;
          local_be = 0;
          if ((local_78 & 0xff) == 0xfe) {
            if ((local_78._1_1_ & 0xc0) == 0x80) {
              local_a8 = *(undefined4 *)(param_2 + 0x54);
            }
            else {
              if ((local_78._1_1_ & 0xc0) != 0xc0) goto LAB_00013540;
              local_a8 = *(undefined4 *)(param_2 + 0x60);
            }
          }
          else {
LAB_00013540:
            local_a8 = 0;
          }
          pwVar2 = L"Default Gateway ... :";
          if (!bVar1) {
            pwVar2 = (wchar_t *)0x0;
          }
          FUN_00013260(&local_c0,(int)pwVar2,(wchar_t *)0x0);
          bVar1 = false;
        }
      } while (local_54 != 0);
      CloseHandle(hDevice);
    }
  }
LAB_000136c8:
  FUN_00012ce0(local_30);
  return;
}



/* 00013700 FUN_00013700 */

/* Boundary evidence: original MIPS .pdata 00013700..000137e3. Semantic name remains unreviewed. */

void FUN_00013700(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 8)) {
    if ((((*(int *)(param_1 + 4) == 0) && (*(int *)(param_1 + 0x48) != 0)) &&
        (*(int *)(param_1 + 0x40) != 0x18)) && ((*(uint *)(param_1 + 0x44) & 1) != 0)) {
      FUN_00012ed8(L"Tunnel adapter [%s]: \n",*(undefined4 *)(param_1 + 0x24),param_3,param_4);
      FUN_00012ed8(L"\t Interface Number .. : %d\n",*(undefined4 *)(param_1 + 0x48),param_3,param_4)
      ;
      FUN_00013340(0,param_1,0,0);
      param_4 = 0;
      param_3 = 4;
      iVar1 = param_1;
      FUN_00013340(0,param_1,4,0);
      FUN_00012ed8(L"\n",iVar1,param_3,param_4);
    }
  }
  return;
}



/* 000137e4 FUN_000137e4 */

/* Boundary evidence: original MIPS .pdata 000137e4..00013ff7. Semantic name remains unreviewed. */

undefined4 FUN_000137e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  bool bVar2;
  STRSAFE_LPCWSTR pwVar3;
  size_t *psVar4;
  DWORD DVar5;
  LPWSTR hMem;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  size_t *psVar9;
  undefined4 uVar10;
  size_t *psVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  int *piVar17;
  undefined **ppuVar18;
  size_t *psVar19;
  wchar_t *pwVar20;
  size_t local_a4;
  size_t local_a0;
  size_t local_9c;
  undefined **local_98;
  wchar_t *local_94;
  wchar_t *local_90;
  wchar_t *local_8c;
  wchar_t *local_88;
  wchar_t *local_84;
  wchar_t *local_80;
  wchar_t *local_7c;
  wchar_t *local_78;
  wchar_t *local_74;
  undefined4 *local_70;
  FILETIME local_68;
  FILETIME local_60;
  _FILETIME _Stack_58;
  _FILETIME _Stack_50;
  _SYSTEMTIME local_48;
  _SYSTEMTIME local_38;
  
  puVar15 = (undefined4 *)0x0;
  local_a4 = 0;
  FUN_00012ed8(L"Windows IP configuration \r\n\r\n",param_2,param_3,param_4);
  psVar11 = (size_t *)0x0;
  uVar10 = 0;
  psVar9 = (size_t *)0x6;
  GetAdaptersAddresses(0);
  psVar4 = malloc(local_9c);
  if (psVar4 == (size_t *)0x0) {
LAB_00013854:
    pwVar6 = L"Insufficient Memory\n";
LAB_0001385c:
    FUN_00012ed8(pwVar6,psVar9,uVar10,psVar11);
  }
  else {
    uVar10 = 0;
    psVar11 = psVar4;
    DVar5 = GetAdaptersAddresses(0,6,0,psVar4,&local_9c);
    if (DVar5 == 0) {
      psVar9 = &local_a4;
      DVar5 = GetAdaptersInfo(0);
      if (DVar5 == 0x6f) {
        puVar15 = malloc(local_a4);
        if (puVar15 == (undefined4 *)0x0) goto LAB_00013854;
        psVar9 = &local_a4;
        DVar5 = GetAdaptersInfo(puVar15);
      }
      else if (DVar5 == 0xe8) {
        pwVar6 = L"No IPv4 adapter found.\r\n\r\n";
        goto LAB_0001385c;
      }
      if (DVar5 == 0) {
        puVar16 = puVar15;
        if (local_a4 == 0) {
          puVar16 = (undefined4 *)0x0;
        }
        local_70 = puVar15;
        if (puVar16 == (undefined4 *)0x0) {
          FUN_00012ed8(L"No Interfaces Present.\n",psVar9,uVar10,psVar11);
        }
        else {
          local_98 = &PTR_u_Sunday_0001510c;
          local_7c = L"\t Secondary WinsServer: %hs\n";
          local_80 = L"\t Primary WinsServer  : %hs\n";
          local_84 = L"\t DHCP Server........ : %hs\n";
          local_88 = L"\t Default Gateway ... : %hs\n";
          local_94 = L"\t Subnet Mask ....... : %hs\n";
          local_90 = L"\t IP Address ........ : %hs\n";
          pwVar6 = L"Ethernet adapter Local Area Connection: \n";
          pwVar20 = L"IP connection:\n\n";
          local_78 = L"PPP Adapter [%hs]:\n";
          local_74 = L"Ethernet adapter [%hs]: \n";
          local_8c = L"Ethernet adapter Local Area Connection: \n";
          do {
            iVar13 = puVar16[0x68];
            pwVar7 = pwVar20;
            if (iVar13 == 1) {
LAB_00013a20:
              FUN_00012ed8(pwVar7,psVar9,uVar10,psVar11);
            }
            else {
              if (iVar13 != 6) {
                if ((iVar13 != 9) && (iVar13 != 0xf)) {
                  pwVar8 = local_78;
                  if (iVar13 == 0x17) goto LAB_00013cf0;
                  if ((iVar13 != 0x18) && (iVar13 != 0x1c)) goto LAB_00013a28;
                }
                goto LAB_00013a20;
              }
              pwVar8 = local_74;
              pwVar7 = pwVar6;
              if (DAT_00015140 != 0) goto LAB_00013a20;
LAB_00013cf0:
              FUN_00012ed8(pwVar8,puVar16 + 2,uVar10,psVar11);
            }
LAB_00013a28:
            pwVar7 = local_90;
            pwVar6 = local_94;
            puVar15 = puVar16 + 0x6b;
            do {
              FUN_00012ed8(pwVar7,puVar15 + 1,uVar10,psVar11);
              FUN_00012ed8(pwVar6,puVar15 + 5,uVar10,psVar11);
              puVar15 = (undefined4 *)*puVar15;
            } while (puVar15 != (undefined4 *)0x0);
            uVar12 = 0;
            uVar10 = 0;
            FUN_00013340((int)puVar16,(int)psVar4,0,0);
            pwVar7 = local_88;
            pwVar6 = local_8c;
            puVar15 = puVar16 + 0x75;
            if (*(char *)(puVar16 + 0x76) != '\0') {
              do {
                FUN_00012ed8(pwVar7,puVar15 + 1,uVar10,uVar12);
                puVar15 = (undefined4 *)*puVar15;
              } while (puVar15 != (undefined4 *)0x0);
            }
            psVar11 = (size_t *)0x1;
            uVar10 = 4;
            psVar9 = psVar4;
            FUN_00013340((int)puVar16,(int)psVar4,4,1);
            if (DAT_00015140 == 1) {
              FUN_00012ed8(L"\t Adapter Name ...... : %hs\n",puVar16 + 2,uVar10,psVar11);
              FUN_00012ed8(L"\t Description ....... : %hs\n",puVar16 + 0x43,uVar10,psVar11);
              FUN_00012ed8(L"\t Adapter Index ..... : %lu\n",puVar16[0x67],uVar10,psVar11);
              hMem = FUN_00013180((int)(puVar16 + 0x65),puVar16[100]);
              if (hMem != (LPWSTR)0x0) {
                FUN_00012ed8(L"\t Address............ : %s\n",hMem,uVar10,psVar11);
                LocalFree(hMem);
              }
              psVar9 = (size_t *)&DAT_00011f2c;
              if (puVar16[0x69] == 0) {
                psVar9 = (size_t *)&DAT_00011f34;
              }
              FUN_00012ed8(L"\t DHCP Enabled....... : %s\n",psVar9,uVar10,psVar11);
              pwVar7 = local_84;
              if (puVar16[0x69] != 0) {
                puVar15 = puVar16 + 0x7f;
                do {
                  FUN_00012ed8(pwVar7,puVar15 + 1,uVar10,psVar11);
                  puVar15 = (undefined4 *)*puVar15;
                } while (puVar15 != (undefined4 *)0x0);
              }
              pwVar7 = local_80;
              pwVar3 = local_7c;
              for (piVar17 = puVar16 + 0x8a; local_7c = pwVar3, piVar17 != (int *)0x0;
                  piVar17 = (int *)*piVar17) {
                FUN_00012ed8(pwVar7,piVar17 + 1,uVar10,psVar11);
                pwVar3 = local_7c;
              }
              for (piVar17 = puVar16 + 0x94; piVar17 != (int *)0x0; piVar17 = (int *)*piVar17) {
                FUN_00012ed8(pwVar3,piVar17 + 1,uVar10,psVar11);
              }
              psVar11 = (size_t *)0x0;
              uVar10 = 3;
              psVar9 = psVar4;
              FUN_00013340((int)puVar16,(int)psVar4,3,0);
              if (puVar16[0x69] != 0) {
                uVar14 = puVar16[0x9e];
                if (uVar14 == 0) {
                  FUN_00012ed8(L"\t Lease obtained on   : Not Available\n",psVar9,uVar10,psVar11);
                  ppuVar18 = local_98;
                }
                else {
                  lVar1 = (ulonglong)(uVar14 + 0xb6109100) * 10000000;
                  local_68.dwLowDateTime = (DWORD)lVar1;
                  local_68.dwHighDateTime =
                       ((uVar14 + 0xb6109100 < uVar14) + 2) * 10000000 +
                       (int)((ulonglong)lVar1 >> 0x20);
                  FileTimeToLocalFileTime(&local_68,&_Stack_58);
                  FileTimeToSystemTime(&_Stack_58,&local_48);
                  ppuVar18 = local_98;
                  psVar11 = (size_t *)(uint)local_48.wDay;
                  uVar10 = *(undefined4 *)(&DAT_000150d8 + (uint)local_48.wMonth * 4);
                  psVar9 = (size_t *)local_98[local_48.wDayOfWeek];
                  FUN_00012ed8(L"\t Lease obtained on   : %s, %s %lu ,%lu %lu : %lu : %lu  \n",
                               psVar9,uVar10,psVar11);
                }
                uVar14 = puVar16[0x9f];
                if (uVar14 == 0) {
                  FUN_00012ed8(L"\t Lease expires on    : Not Available\n",psVar9,uVar10,psVar11);
                }
                else {
                  lVar1 = (ulonglong)(uVar14 + 0xb6109100) * 10000000;
                  local_60.dwLowDateTime = (DWORD)lVar1;
                  local_60.dwHighDateTime =
                       ((uVar14 + 0xb6109100 < uVar14) + 2) * 10000000 +
                       (int)((ulonglong)lVar1 >> 0x20);
                  FileTimeToLocalFileTime(&local_60,&_Stack_50);
                  FileTimeToSystemTime(&_Stack_50,&local_38);
                  psVar11 = (size_t *)(uint)local_38.wDay;
                  uVar10 = *(undefined4 *)(&DAT_000150d8 + (uint)local_38.wMonth * 4);
                  psVar9 = (size_t *)ppuVar18[local_38.wDayOfWeek];
                  FUN_00012ed8(L"\t Lease expires on    : %s, %s %lu ,%lu %lu : %lu : %lu  \n",
                               psVar9,uVar10,psVar11);
                }
                iVar13 = FUN_0001305c(puVar16[0x67],psVar9,uVar10,psVar11);
                psVar9 = (size_t *)&DAT_00011f2c;
                if (iVar13 == 0) {
                  psVar9 = (size_t *)&DAT_00011f34;
                }
                FUN_00012ed8(L"\t AutoConfig Enabled  : %s\n",psVar9,uVar10,psVar11);
              }
            }
            FUN_00012ed8(L"\n",psVar9,uVar10,psVar11);
            puVar16 = (undefined4 *)*puVar16;
            puVar15 = local_70;
          } while (puVar16 != (undefined4 *)0x0);
        }
        FUN_00013700((int)psVar4,psVar9,uVar10,psVar11);
        psVar9 = &local_a0;
        local_a0 = 0;
        psVar4 = (size_t *)0x0;
        DVar5 = GetNetworkParams(0);
        if (DVar5 == 0x6f) {
          psVar4 = malloc(local_a0);
          if (psVar4 == (size_t *)0x0) {
            FUN_00012ed8(L"Insufficient Memory\n",psVar9,uVar10,psVar11);
            return 1;
          }
          psVar9 = &local_a0;
          DVar5 = GetNetworkParams(psVar4);
        }
        if (DVar5 != 0) {
          FUN_00012ff8(DVar5);
          return 1;
        }
        if ((DAT_00015140 == 1) &&
           (psVar9 = psVar4, FUN_00012ed8(L"\t Host name.......... : %hs\n",psVar4,uVar10,psVar11),
           DAT_00015140 == 1)) {
          psVar9 = psVar4 + 0x21;
          FUN_00012ed8(L"\t Domain Name........ : %hs\n",psVar9,uVar10,psVar11);
        }
        psVar19 = psVar4 + 0x43;
        if ((char)psVar4[0x44] != '\0') {
          bVar2 = true;
          do {
            psVar9 = psVar19 + 1;
            pwVar6 = L"\t DNS Servers........ : %hs\n";
            if (!bVar2) {
              pwVar6 = L"\t                       %hs\n";
            }
            FUN_00012ed8(pwVar6,psVar9,uVar10,psVar11);
            psVar19 = (size_t *)*psVar19;
            bVar2 = false;
          } while (psVar19 != (size_t *)0x0);
        }
        if (DAT_00015140 == 1) {
          FUN_00012ed8(L"\t NODETYPE........... :  %u ",psVar4[0x4d],uVar10,psVar11);
          psVar9 = (size_t *)&DAT_00011f2c;
          if (psVar4[0x8f] == 0) {
            psVar9 = (size_t *)&DAT_00011868;
          }
          FUN_00012ed8(L"\t Routing Enabled.... : %s\n",psVar9,uVar10,psVar11);
          psVar9 = (size_t *)&DAT_00011f2c;
          if (psVar4[0x90] == 0) {
            psVar9 = (size_t *)&DAT_00011f34;
          }
          FUN_00012ed8(L"\t Proxy Enabled...... :  %s\n",psVar9,uVar10,psVar11);
        }
        FUN_00012ed8(L"\n",psVar9,uVar10,psVar11);
        if (psVar4 != (size_t *)0x0) {
          free(psVar4);
        }
        if (puVar15 != (undefined4 *)0x0) {
          free(puVar15);
        }
        return 0;
      }
    }
    FUN_00012ff8(DVar5);
  }
  return 1;
}



/* 00013ff8 FUN_00013ff8 */

/* Boundary evidence: original MIPS .pdata 00013ff8..0001414f. Semantic name remains unreviewed. */

void FUN_00013ff8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  DWORD DVar2;
  size_t *psVar3;
  int *_Memory;
  int *piVar4;
  int iVar5;
  size_t local_30 [2];
  
  psVar3 = local_30;
  local_30[0] = 0;
  _Memory = (int *)0x0;
  bVar1 = false;
  DVar2 = GetInterfaceInfo(0);
  if (DVar2 == 0x7a) {
    _Memory = malloc(local_30[0]);
    if (_Memory != (int *)0x0) {
      psVar3 = local_30;
      DVar2 = GetInterfaceInfo(_Memory);
      goto LAB_00014070;
    }
LAB_00014078:
    FUN_00012ff8(DVar2);
    FUN_00012880(1);
  }
  else {
LAB_00014070:
    if (DVar2 != 0) goto LAB_00014078;
  }
  iVar5 = 0;
  if (0 < *_Memory) {
    piVar4 = _Memory + 1;
    do {
      if ((*piVar4 == param_1) || (param_1 == 0)) {
        bVar1 = true;
        DVar2 = IpRenewAddress(piVar4);
        psVar3 = (size_t *)*piVar4;
        if (DVar2 == 0) {
          FUN_00012ed8(L"Successfully Renewed Adapter with Index Number %lu\n",psVar3,param_3,
                       param_4);
        }
        else {
          FUN_00012ed8(L"Failed to renew Adpter with Index Number %lu\n",psVar3,param_3,param_4);
          FUN_00012ff8(DVar2);
        }
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 0x41;
    } while (iVar5 < *_Memory);
    if (bVar1) goto LAB_0001411c;
  }
  FUN_00012ed8(L"Adapter with given Index Number not found\n",psVar3,param_3,param_4);
LAB_0001411c:
  free(_Memory);
  return;
}



/* 00014150 FUN_00014150 */

/* Boundary evidence: original MIPS .pdata 00014150..000142a7. Semantic name remains unreviewed. */

void FUN_00014150(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  DWORD DVar2;
  size_t *psVar3;
  int *_Memory;
  int *piVar4;
  int iVar5;
  size_t local_30 [2];
  
  psVar3 = local_30;
  local_30[0] = 0;
  bVar1 = false;
  _Memory = (int *)0x0;
  DVar2 = GetInterfaceInfo(0);
  if (DVar2 == 0x7a) {
    _Memory = malloc(local_30[0]);
    if (_Memory != (int *)0x0) {
      psVar3 = local_30;
      DVar2 = GetInterfaceInfo(_Memory);
      goto LAB_000141c8;
    }
LAB_000141d0:
    FUN_00012ff8(DVar2);
    FUN_00012880(1);
  }
  else {
LAB_000141c8:
    if (DVar2 != 0) goto LAB_000141d0;
  }
  iVar5 = 0;
  if (0 < *_Memory) {
    piVar4 = _Memory + 1;
    do {
      if ((param_1 == 0) || (*piVar4 == param_1)) {
        bVar1 = true;
        DVar2 = IpReleaseAddress(piVar4);
        psVar3 = (size_t *)*piVar4;
        if (DVar2 == 0) {
          FUN_00012ed8(L"Successfully Released adapter with index Number %lu\n",psVar3,param_3,
                       param_4);
        }
        else {
          FUN_00012ed8(L"Failed to release Adapter with index Number %lu\n",psVar3,param_3,param_4);
          FUN_00012ff8(DVar2);
        }
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 0x41;
    } while (iVar5 < *_Memory);
    if (bVar1) goto LAB_00014274;
  }
  FUN_00012ed8(L"Adapter with the given index Number not found\n",psVar3,param_3,param_4);
LAB_00014274:
  free(_Memory);
  return;
}



/* 000142a8 FUN_000142a8 */

/* Boundary evidence: original MIPS .pdata 000142a8..000145cf. Semantic name remains unreviewed. */

undefined4 FUN_000142a8(int param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  DWORD DVar7;
  uint _C;
  undefined4 uVar8;
  LPWSADATA lpWSAData;
  wchar_t *_Str;
  wchar_t *pwVar9;
  long lVar10;
  int iVar11;
  WSADATA WStack_1c0;
  uint local_30;
  
  local_30 = DAT_000150d0;
  lVar10 = 0;
  bVar1 = false;
  bVar4 = false;
  bVar2 = false;
  bVar3 = false;
  bVar5 = false;
  iVar11 = 1;
  pwVar9 = param_2;
  if (1 < param_1) {
    do {
      pwVar9 = pwVar9 + 2;
      _Str = *(wchar_t **)pwVar9;
      if ((*_Str == L'-') || (*_Str == L'/')) {
        if (bVar1) {
          bVar4 = true;
        }
        _C = (uint)(ushort)_Str[1];
        iVar6 = toupper(_C);
        if (iVar6 == 0x3f) goto LAB_000144cc;
        if (iVar6 == 0x41) {
          param_2 = L"ALL";
          iVar6 = _wcsicmp((wchar_t *)(*(int *)pwVar9 + 2),L"ALL");
          if (iVar6 == 0) {
            DAT_00015140 = 1;
          }
        }
        else if (iVar6 == 0x44) {
          param_2 = L"D";
          iVar6 = _wcsicmp((wchar_t *)(*(int *)pwVar9 + 2),L"D");
          if (iVar6 != 0) goto LAB_000143b0;
          DAT_00015144 = 1;
        }
        else if (iVar6 == 0x46) {
          param_2 = L"FLUSHDNS";
          iVar6 = _wcsicmp((wchar_t *)(*(int *)pwVar9 + 2),L"FLUSHDNS");
          if (iVar6 == 0) {
            bVar5 = true;
          }
        }
        else {
          if (iVar6 != 0x52) goto LAB_000143b0;
          param_2 = L"RENEW";
          iVar6 = _wcsicmp((wchar_t *)(*(int *)pwVar9 + 2),L"RENEW");
          if (iVar6 == 0) {
            bVar2 = true;
          }
          else {
            param_2 = L"RELEASE";
            iVar6 = _wcsicmp((wchar_t *)(*(int *)pwVar9 + 2),L"RELEASE");
            if (iVar6 != 0) goto LAB_0001448c;
            bVar3 = true;
          }
          bVar1 = true;
        }
      }
      else {
        if ((bVar1) && (lVar10 = _wtol(_Str), lVar10 != 0)) break;
LAB_000143b0:
        bVar4 = true;
      }
LAB_0001448c:
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_1);
    if (((bVar2) && (bVar3)) || (bVar4)) {
      FUN_00012ed8(L"Incorrect Parameters\n",param_2,param_3,param_4);
      _C = 1;
      FUN_00012880(1);
LAB_000144cc:
      FUN_0001313c(_C,param_2,param_3,param_4);
      FUN_00012880(1);
    }
  }
  lpWSAData = &WStack_1c0;
  uVar8 = 0x101;
  iVar11 = WSAStartup(0x101,lpWSAData);
  if (iVar11 == 0) {
    if (bVar3) {
      FUN_00014150(lVar10,lpWSAData,param_3,param_4);
    }
    else if (bVar2) {
      FUN_00013ff8(lVar10,lpWSAData,param_3,param_4);
    }
    else if (bVar5) {
      WSAControl(0xffffffff,6,0,0,0,0);
    }
    else {
      FUN_000137e4(uVar8,lpWSAData,param_3,param_4);
    }
    WSACleanup();
  }
  else {
    DVar7 = GetLastError();
    FUN_00012ed8(L"WSAStartup failed (error %ld)\n",DVar7,param_3,param_4);
  }
  FUN_00012ce0(local_30);
  return 0;
}


