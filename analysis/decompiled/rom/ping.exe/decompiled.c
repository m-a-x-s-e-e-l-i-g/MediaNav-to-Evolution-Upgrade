/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011c1c FUN_00011c1c */

/* Boundary evidence: original MIPS .pdata 00011c1c..00011c47. Semantic name remains unreviewed. */

void FUN_00011c1c(void)

{
  if (DAT_000150e0 != (void *)0x0) {
    free(DAT_000150e0);
  }
  return;
}



/* 00011c48 FUN_00011c48 */

/* Boundary evidence: original MIPS .pdata 00011c48..00011cd7. Semantic name remains unreviewed. */

int FUN_00011c48(wint_t *param_1)

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



/* 00011cd8 FUN_00011cd8 */

/* Boundary evidence: original MIPS .pdata 00011cd8..00011d9b. Semantic name remains unreviewed. */

void FUN_00011cd8(int *param_1,int *param_2,wint_t *param_3)

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
    iVar2 = FUN_00011c48(pwVar3);
    *param_2 = *param_2 + iVar2 + 1;
    param_3 = pwVar3 + iVar2;
    *param_1 = *param_1 + 1;
    if (*param_3 == 0) {
      return;
    }
  }
  return;
}



/* 00011d9c FUN_00011d9c */

/* Boundary evidence: original MIPS .pdata 00011d9c..00011f73. Semantic name remains unreviewed. */

undefined4 FUN_00011d9c(wchar_t *param_1,wint_t *param_2,int *param_3,undefined4 *param_4)

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
    FUN_00011cd8(&local_38,(int *)&local_34,param_2);
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
        iVar6 = FUN_00011c48(pwVar10);
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



/* 00011f74 FUN_00011f74 */

/* Boundary evidence: original MIPS .pdata 00011f74..0001206b. Semantic name remains unreviewed. */

void FUN_00011f74(HMODULE param_1,wint_t *param_2)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  LPCWSTR *ppWVar4;
  wchar_t **ppwVar5;
  LPCWSTR local_224;
  wchar_t *local_220 [2];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_000150cc;
  DAT_000150e8 = param_1;
  DVar1 = GetModuleFileNameW(param_1,aWStack_218,0x100);
  if (DVar1 == 0) {
    FUN_00012228(0xfffffffd);
  }
  FUN_00012548(FUN_00011c1c);
  FUN_000122c8();
  ppwVar5 = local_220;
  ppWVar4 = &local_224;
  iVar2 = FUN_00011d9c(aWStack_218,param_2,(int *)ppWVar4,ppwVar5);
  if (iVar2 == 0) {
    FUN_00012228(0xfffffffc);
  }
  DAT_000150e4 = local_224;
  DAT_000150e0 = local_220[0];
  UVar3 = FUN_0001327c(local_224,local_220[0],ppWVar4,ppwVar5);
  FUN_00012208(UVar3);
  FUN_00012228(UVar3);
  FUN_00012668(local_18);
  return;
}



/* 0001206c FUN_0001206c */

/* Boundary evidence: original MIPS .pdata 0001206c..000120ab. Semantic name remains unreviewed. */

void FUN_0001206c(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x228) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x228),param_1);
  return;
}



/* 000120ac entry */

/* Boundary evidence: original MIPS .pdata 000120ac..000120e7. Semantic name remains unreviewed. */

void entry(HMODULE param_1,undefined4 param_2,wint_t *param_3)

{
  FUN_00012578();
  FUN_00011f74(param_1,param_3);
  return;
}



/* 000120e8 FUN_000120e8 */

/* Boundary evidence: original MIPS .pdata 000120e8..00012207. Semantic name remains unreviewed. */

void FUN_000120e8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_000150ec = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00015f14;
    if (DAT_00015f14 != (undefined4 *)0x0) {
      while (DAT_00015f10 = DAT_00015f10 + -1, _Memory <= DAT_00015f10) {
        if ((code *)*DAT_00015f10 != (code *)0x0) {
          (*(code *)*DAT_00015f10)();
          _Memory = DAT_00015f14;
        }
      }
      free(_Memory);
      DAT_00015f10 = (undefined4 *)0x0;
      DAT_00015f14 = (undefined4 *)0x0;
    }
    FUN_00012274((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00012274((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_00015f18,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00012208 FUN_00012208 */

/* Boundary evidence: original MIPS .pdata 00012208..00012227. Semantic name remains unreviewed. */

void FUN_00012208(UINT param_1)

{
  FUN_000120e8(param_1,0,0);
  return;
}



/* 00012228 FUN_00012228 */

/* Boundary evidence: original MIPS .pdata 00012228..00012273. Semantic name remains unreviewed. */

void FUN_00012228(UINT param_1)

{
  DAT_000150ec = 0;
  FUN_00012274((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00012274 FUN_00012274 */

/* Boundary evidence: original MIPS .pdata 00012274..000122c7. Semantic name remains unreviewed. */

void FUN_00012274(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000122c8 FUN_000122c8 */

/* Boundary evidence: original MIPS .pdata 000122c8..00012303. Semantic name remains unreviewed. */

void FUN_000122c8(void)

{
  FUN_00012274((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00012274((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00012304 FUN_00012304 */

/* Boundary evidence: original MIPS .pdata 00012304..0001240f. Semantic name remains unreviewed. */

undefined4 FUN_00012304(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_00015f14;
  puVar3 = DAT_00015f10;
  iVar4 = (int)DAT_00015f10 - (int)DAT_00015f14;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_00012348:
    param_1 = 0;
  }
  else {
    if (DAT_00015f14 != (void *)0x0) {
      uVar1 = _msize(DAT_00015f14);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_000123bc:
        if (pvVar2 == (void *)0x0) goto LAB_00012348;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_000123bc;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00015f10 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_00015f14 = pvVar2;
  }
  return param_1;
}



/* 00012410 FUN_00012410 */

/* Boundary evidence: original MIPS .pdata 00012410..000124fb. Semantic name remains unreviewed. */

undefined4 FUN_00012410(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_00015f18 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_00015f18,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_00015f18 == (LPCRITICAL_SECTION)0x0) goto LAB_000124b4;
  }
  EnterCriticalSection(DAT_00015f18);
LAB_000124b4:
  uVar2 = FUN_00012304(param_1);
  FUN_000124fc();
  return uVar2;
}



/* 000124fc FUN_000124fc */

/* Boundary evidence: original MIPS .pdata 000124fc..00012547. Semantic name remains unreviewed. */

void FUN_000124fc(void)

{
  if (DAT_00015f18 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_00015f18);
  }
  return;
}



/* 00012548 FUN_00012548 */

/* Boundary evidence: original MIPS .pdata 00012548..00012577. Semantic name remains unreviewed. */

undefined4 FUN_00012548(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00012410(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00012578 FUN_00012578 */

/* Boundary evidence: original MIPS .pdata 00012578..000125eb. Semantic name remains unreviewed. */

void FUN_00012578(void)

{
  uint uVar1;
  
  if ((DAT_000150cc == 0) || (DAT_000150cc == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000150cc = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000150cc == 0) {
      DAT_000150cc = 0xb064;
    }
  }
  DAT_000150d0 = ~DAT_000150cc;
  return;
}



/* 000125ec FUN_000125ec */

/* Boundary evidence: original MIPS .pdata 000125ec..00012667. Semantic name remains unreviewed. */

void FUN_000125ec(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_000126b0(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 00012668 FUN_00012668 */

/* Boundary evidence: original MIPS .pdata 00012668..000126af. Semantic name remains unreviewed. */

void FUN_00012668(uint param_1)

{
  if ((param_1 == DAT_000150cc) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 000126b0 FUN_000126b0 */

/* Boundary evidence: original MIPS .pdata 000126b0..00012703. Semantic name remains unreviewed. */

void FUN_000126b0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012668(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00012704 FUN_00012704 */

/* Boundary evidence: original MIPS .pdata 00012704..0001272f. Semantic name remains unreviewed. */

undefined4 FUN_00012704(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_000126b0(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00012860 FUN_00012860 */

/* Boundary evidence: original MIPS .pdata 00012860..00012963. Semantic name remains unreviewed. */

int FUN_00012860(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t awStack_218 [255];
  undefined2 local_1a;
  uint local_18;
  
  local_18 = DAT_000150cc;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  iVar1 = _vsnwprintf(awStack_218,0xff,param_1,(va_list)&local_res4);
  local_1a = 0;
  if (DAT_00015f04 == 0) {
    if (DAT_00015f0c == (code *)0x0) {
      DAT_000150f0 = LoadLibraryW(L"coredll.dll");
      if (DAT_000150f0 != (HMODULE)0x0) {
        DAT_00015f0c = (code *)GetProcAddressW(DAT_000150f0,L"wprintf");
      }
      if (DAT_00015f0c != (code *)0x0) goto LAB_00012918;
      DAT_00015f04 = 1;
    }
    else {
LAB_00012918:
      (*DAT_00015f0c)(&DAT_0001103c,awStack_218);
    }
    if (DAT_00015f04 == 0) goto LAB_00012940;
  }
  OutputDebugStringW(awStack_218);
LAB_00012940:
  FUN_00012668(local_18);
  return iVar1;
}



/* 00012964 FUN_00012964 */

/* Boundary evidence: original MIPS .pdata 00012964..00012a4b. Semantic name remains unreviewed. */

void FUN_00012964(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00012860(L"Usage: ping [-l size] [-n count] [-d] [-i TTL] [-v TOS] [-w timeout] address\r\n",
               param_2,param_3,param_4);
  FUN_00012860(L"\r\n",param_2,param_3,param_4);
  FUN_00012860(L"Options:\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -d            Send output to the debug output port.\r\n",param_2,param_3,
               param_4);
  FUN_00012860(L"    -t            Ping the specifed host until interrupted.\r\n",param_2,param_3,
               param_4);
  FUN_00012860(L"    -l size       Send buffer size.\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -n count      Send count.\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -f            Don\'t fragment.\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -i TTL        Time to live.\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -v TOS        Type of service\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -w timeout    Timeout (in milliseconds)\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -r count      Record route for count hops.\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -s count      Timestamp route for count hops.\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -S address    Source address to use (IPv6-only).\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -4            Force using IPv4.\r\n",param_2,param_3,param_4);
  FUN_00012860(L"    -6            Force using IPv6.\r\n",param_2,param_3,param_4);
  FUN_00012860(L"\r\n",param_2,param_3,param_4);
  return;
}



/* 00012a4c FUN_00012a4c */

/* Boundary evidence: original MIPS .pdata 00012a4c..00012f87. Semantic name remains unreviewed. */

void FUN_00012a4c(int param_1,char *param_2,char *param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  hostent *phVar4;
  char *pcVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  char *pcVar14;
  _union_1226 local_48;
  _union_1226 local_44;
  byte *local_40;
  wchar_t *local_3c;
  uint local_38;
  wchar_t *local_34;
  wchar_t *local_30;
  
  pbVar8 = *(byte **)(param_1 + 0x18);
  pbVar13 = pbVar8 + *(byte *)(param_1 + 0x17);
  bVar2 = false;
  bVar3 = false;
  if (pbVar8 < pbVar13) {
    local_3c = L"TS %hs ";
    local_34 = L"Route %hs ";
    local_30 = L"Route Header2 --\r\n";
    pcVar5 = param_2;
    pcVar14 = param_2;
    local_40 = pbVar13;
    do {
      pwVar7 = L"Invalid RR option\r\n";
      pwVar6 = L"Invalid TS Option\r\n";
      if (bVar2) {
        return;
      }
      bVar1 = *pbVar8;
      if (bVar1 < 0x83) {
        if (bVar1 == 0x82) {
          pbVar8 = pbVar8 + 0xb;
        }
        else if (bVar1 == 0) {
LAB_00012d3c:
          bVar2 = true;
          bVar3 = true;
        }
        else {
          if (bVar1 != 1) {
            if (bVar1 == 7) goto LAB_00012d98;
            if (bVar1 != 0x44) goto LAB_00012d74;
            if (pbVar8 + 4 <= pbVar13) {
              uVar9 = (uint)pbVar8[2];
              uVar10 = (uint)pbVar8[1];
              if (4 < uVar9) {
                bVar1 = pbVar8[3];
                if (uVar10 + 1 < uVar9) {
                  uVar9 = uVar10 + 1 & 0xff;
                }
                uVar11 = 5;
                iVar12 = 0;
                local_38 = uVar10;
                FUN_00012860(L"\tTimestamp:\t",pcVar5,param_3,param_4);
                pwVar6 = local_3c;
                if (8 < uVar9) {
                  do {
                    if ((iVar12 != 0) &&
                       (FUN_00012860(L"\r\n\t\t\t",pcVar5,param_3,param_4), iVar12 == 1)) {
                      FUN_00012860(L"\r\n",pcVar5,param_3,param_4);
                      FUN_00012860(L"Timestamp Hd2 \r\n",pcVar5,param_3,param_4);
                    }
                    iVar12 = iVar12 + 1;
                    if ((bVar1 & 1) != 0) {
                      pbVar13 = local_40;
                      uVar10 = local_38;
                      bVar2 = bVar3;
                      if (uVar9 < uVar11 + 8) break;
                      local_48 = (_union_1226)
                                 *(_union_1226 *)&((_union_1226 *)(pbVar8 + (uVar11 - 1)))->S_un_b;
                      if ((char)param_2 == '\0') {
LAB_00012ca8:
                        pcVar5 = inet_ntoa((in_addr)local_48.S_un_b);
                        FUN_00012860(pwVar6,pcVar5,param_3,param_4);
                      }
                      else {
                        param_3 = (char *)0x2;
                        phVar4 = gethostbyaddr((char *)&local_48.S_addr,4,2);
                        if (phVar4 == (hostent *)0x0) goto LAB_00012ca8;
                        param_3 = inet_ntoa((in_addr)local_48.S_un_b);
                        FUN_00012860(L"TS %hs %hs ",phVar4->h_name,param_3,param_4);
                      }
                      uVar11 = uVar11 + 4 & 0xff;
                    }
                    pcVar5 = (char *)ntohl(*(u_long *)(pbVar8 + (uVar11 - 1)));
                    FUN_00012860(L"TimeStamp %u ",pcVar5,param_3,param_4);
                    uVar11 = uVar11 + 4 & 0xff;
                    pbVar13 = local_40;
                    uVar10 = local_38;
                    bVar2 = bVar3;
                  } while (uVar11 + 3 < uVar9);
                }
                FUN_00012860(L"\r\n",pcVar5,param_3,param_4);
                pbVar8 = pbVar8 + uVar10;
                goto LAB_00012f4c;
              }
              goto LAB_00012b80;
            }
            goto LAB_00012f2c;
          }
          pbVar8 = pbVar8 + 1;
        }
      }
      else if (bVar1 == 0x83) {
LAB_00012d98:
        pwVar6 = pwVar7;
        if (((pbVar13 < pbVar8 + 3) || (uVar10 = (uint)pbVar8[1], pbVar13 < pbVar8 + uVar10)) ||
           (uVar10 < 3)) {
LAB_00012f2c:
          FUN_00012860(pwVar6,pcVar5,param_3,param_4);
          bVar2 = true;
          bVar3 = true;
        }
        else {
          uVar9 = (uint)pbVar8[2];
          if (uVar9 < 4) {
LAB_00012b80:
            FUN_00012860(pwVar6,pcVar5,param_3,param_4);
            pbVar8 = pbVar8 + uVar10;
          }
          else {
            if (uVar10 + 1 < uVar9) {
              uVar9 = uVar10 + 1 & 0xff;
            }
            uVar11 = 4;
            iVar12 = 0;
            local_38 = uVar10;
            FUN_00012860(L"Route Header --- \r\n",pcVar5,param_3,param_4);
            pwVar7 = local_30;
            pwVar6 = local_34;
            if (7 < uVar9) {
              do {
                if ((iVar12 != 0) && (FUN_00012860(L"\r\n",pcVar5,param_3,param_4), iVar12 == 1)) {
                  FUN_00012860(L"\r\n",pcVar5,param_3,param_4);
                  FUN_00012860(pwVar7,pcVar5,param_3,param_4);
                  iVar12 = 0;
                }
                local_44 = (_union_1226)
                           *(_union_1226 *)&((_union_1226 *)(pbVar8 + (uVar11 - 1)))->S_un_b;
                iVar12 = iVar12 + 1;
                if (pcVar14 == (char *)0x0) {
LAB_00012ed0:
                  pcVar5 = inet_ntoa((in_addr)local_44.S_un_b);
                  FUN_00012860(pwVar6,pcVar5,param_3,param_4);
                }
                else {
                  param_3 = (char *)0x2;
                  phVar4 = gethostbyaddr((char *)&local_44.S_addr,4,2);
                  if (phVar4 == (hostent *)0x0) goto LAB_00012ed0;
                  param_3 = inet_ntoa((in_addr)local_44.S_un_b);
                  pcVar5 = phVar4->h_name;
                  FUN_00012860(L"Route %hs %hs ",pcVar5,param_3,param_4);
                }
                uVar11 = uVar11 + 4 & 0xff;
                uVar10 = local_38;
                pbVar13 = local_40;
                bVar2 = bVar3;
              } while (uVar11 + 3 < uVar9);
            }
            FUN_00012860(L"\r\n",pcVar5,param_3,param_4);
            pbVar8 = pbVar8 + uVar10;
          }
        }
      }
      else if (bVar1 == 0x88) {
        pbVar8 = pbVar8 + 4;
      }
      else {
        if (bVar1 == 0x89) goto LAB_00012d98;
LAB_00012d74:
        if (pbVar13 < pbVar8 + 2) goto LAB_00012d3c;
        pbVar8 = pbVar8 + pbVar8[1];
      }
LAB_00012f4c:
      pcVar14 = (char *)((uint)param_2 & 0xff);
    } while (pbVar8 < pbVar13);
  }
  return;
}



/* 00012f88 FUN_00012f88 */

/* Boundary evidence: original MIPS .pdata 00012f88..0001314b. Semantic name remains unreviewed. */

undefined4
FUN_00012f88(undefined4 param_1,LPCWSTR param_2,void *param_3,undefined4 *param_4,char *param_5,
            undefined4 param_6,char param_7)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *_Source;
  int local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  
  iVar1 = WideCharToMultiByte(0,0,param_2,-1,&DAT_00015b00,0x402,(LPCSTR)0x0,(LPBOOL)0x0);
  if (iVar1 == 0) {
LAB_00013124:
    uVar3 = 0;
  }
  else {
    *param_5 = '\0';
    memset(&local_40,0,0x20);
    local_40 = 4;
    local_3c = param_1;
    iVar2 = getaddrinfo(&DAT_00015b00,&DAT_00011714,&local_40,local_48);
    iVar1 = local_48[0];
    if (iVar2 == 0) {
      *param_4 = *(undefined4 *)(local_48[0] + 0x10);
      memcpy(param_3,*(void **)(local_48[0] + 0x18),*(size_t *)(local_48[0] + 0x10));
      if (param_7 != '\0') {
        getnameinfo(*(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x10),param_5,param_6,0,0,
                    4);
        iVar1 = local_48[0];
      }
      freeaddrinfo(iVar1);
    }
    else {
      local_40 = 2;
      iVar1 = getaddrinfo(&DAT_00015b00,0,&local_40,local_48);
      if (iVar1 != 0) goto LAB_00013124;
      *param_4 = *(undefined4 *)(local_48[0] + 0x10);
      memcpy(param_3,*(void **)(local_48[0] + 0x18),*(size_t *)(local_48[0] + 0x10));
      _Source = &DAT_00015b00;
      if (*(char **)(local_48[0] + 0x14) != (char *)0x0) {
        _Source = *(char **)(local_48[0] + 0x14);
      }
      strcpy(param_5,_Source);
      DAT_00015900 = *(undefined4 *)(local_48[0] + 0x1c);
      DAT_00015f08 = local_48[0];
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* 0001314c FUN_0001314c */

/* Boundary evidence: original MIPS .pdata 0001314c..000131d7. Semantic name remains unreviewed. */

undefined4 FUN_0001314c(void *param_1,undefined4 *param_2,char *param_3)

{
  undefined4 uVar1;
  char *_Source;
  
  if (DAT_00015900 == 0) {
    uVar1 = 0;
  }
  else {
    *param_2 = *(undefined4 *)(DAT_00015900 + 0x10);
    memcpy(param_1,*(void **)(DAT_00015900 + 0x18),*(size_t *)(DAT_00015900 + 0x10));
    _Source = *(char **)(DAT_00015900 + 0x14);
    if (_Source == (char *)0x0) {
      _Source = &DAT_00015b00;
    }
    strcpy(param_3,_Source);
    DAT_00015900 = *(int *)(DAT_00015900 + 0x1c);
    uVar1 = 1;
  }
  return uVar1;
}



/* 000131d8 FUN_000131d8 */

/* Boundary evidence: original MIPS .pdata 000131d8..0001327b. Semantic name remains unreviewed. */

uint FUN_000131d8(int param_1,int param_2,int param_3,uint param_4,uint param_5,undefined4 *param_6)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = 0;
  uVar3 = param_4;
  if (param_3 == param_2 + -1) {
    uVar2 = *(undefined4 *)(param_3 * 4 + param_1);
    pwVar1 = L"Value must be supplied for option %s.\r\n";
  }
  else {
    puVar5 = (undefined4 *)(param_3 * 4 + param_1);
    uVar4 = _wtol((wchar_t *)puVar5[1]);
    if ((param_4 <= uVar4) && (uVar4 <= param_5)) {
      return uVar4;
    }
    uVar2 = *puVar5;
    pwVar1 = L"Bad value for option %s.\r\n";
  }
  FUN_00012860(pwVar1,uVar2,param_3,uVar3);
  *param_6 = 0;
  return uVar4;
}



/* 0001327c FUN_0001327c */

/* Boundary evidence: original MIPS .pdata 0001327c..0001409f. Semantic name remains unreviewed. */

undefined4 FUN_0001327c(LPCWSTR param_1,wchar_t *param_2,undefined4 param_3,wchar_t **param_4)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  int iVar8;
  DWORD DVar9;
  char *RequestData;
  HANDLE IcmpHandle;
  SOCKET s;
  LPCWSTR _Src;
  SIZE_T SVar10;
  LPCWSTR pWVar11;
  CHAR *pCVar12;
  int iVar13;
  undefined4 uVar14;
  wchar_t *pwVar15;
  char *pcVar16;
  char *pcVar17;
  wchar_t *pwVar18;
  wchar_t *pwVar19;
  wchar_t *pwVar20;
  undefined4 uVar21;
  wchar_t *pwVar22;
  LPWSTR pWVar23;
  LPCWSTR pWVar24;
  wchar_t *pwVar25;
  PUCHAR pUVar26;
  int iVar27;
  LPCWSTR pWVar28;
  SIZE_T uBytes;
  uint uVar29;
  byte local_9f8;
  wchar_t *local_9f4;
  UCHAR local_9f0;
  undefined2 local_9ee;
  wchar_t *local_9ec;
  PUCHAR local_9e8;
  PUCHAR local_9e4;
  wchar_t *local_9e0;
  wchar_t *local_9dc;
  wchar_t *local_9d8;
  LPCWSTR local_9d4;
  int local_9d0;
  wchar_t *local_9cc;
  uint local_9c8;
  SIZE_T local_9c4;
  HANDLE local_9c0;
  ip_option_information local_9b8;
  wchar_t *local_9b0;
  wchar_t *local_9ac;
  char *local_9a8;
  wchar_t *local_9a4;
  WCHAR local_9a0 [16];
  WCHAR local_980 [2];
  IPAddr local_97c;
  char local_978;
  byte local_977;
  int local_968;
  wchar_t local_900 [64];
  CHAR local_880;
  undefined1 auStack_87f [71];
  CHAR local_838;
  undefined1 auStack_837 [1031];
  char local_430;
  undefined1 auStack_42f [1027];
  uint local_2c;
  
  local_2c = DAT_000150cc;
  uVar21 = 1;
  local_9f4 = (wchar_t *)0x1;
  local_9f8 = 0;
  local_430 = '\0';
  pWVar28 = (LPCWSTR)0x0;
  memset(auStack_42f,0,0x400);
  local_880 = '\0';
  memset(auStack_87f,0,0x40);
  pWVar11 = (LPCWSTR)0x400;
  local_838 = '\0';
  memset(auStack_837,0,0x400);
  local_9f0 = '\0';
  local_9e4 = (PUCHAR)0x4;
  local_9ee = (ushort)local_9ee._1_1_ << 8;
  local_9c8 = 1000;
  local_9d8 = (wchar_t *)0x20;
  local_9e8 = (PUCHAR)0x0;
  local_9ec = (wchar_t *)0x0;
  local_9d4 = (LPCWSTR)0x20;
  iVar27 = 0;
  pwVar18 = (wchar_t *)0x0;
  iVar8 = WSAStartup(0x202,(LPWSADATA)&DAT_00015920);
  if (iVar8 != 0) {
    DVar9 = GetLastError();
    pwVar18 = L"WsaStartup Failed %d\r\n";
LAB_00013384:
    FUN_00012860(pwVar18,DVar9,pWVar11,param_4);
    goto LAB_00014064;
  }
  pWVar11 = (LPCWSTR)0x80;
  _Src = (LPCWSTR)0x0;
  pwVar22 = local_900;
  memset(pwVar22,0,0x80);
  DAT_00015f08 = 0;
  DAT_00015900 = 0;
  local_9d0 = 0;
  if ((int)param_1 < 2) {
LAB_00013900:
    FUN_00012964(pwVar22,_Src,pWVar11,param_4);
    goto LAB_00014064;
  }
  pWVar24 = (LPCWSTR)0x1;
  pwVar25 = param_2;
  if ((LPCWSTR)0x1 < param_1) {
LAB_000133f4:
    pwVar15 = pwVar25 + 2;
    sVar3 = **(short **)pwVar15;
    if ((sVar3 == 0x2d) || (sVar3 == 0x2f)) {
      uVar4 = (*(short **)pwVar15)[1];
      if (uVar4 < 0x6a) {
        if (uVar4 != 0x69) {
          if (uVar4 == 0x34) {
            pwVar18 = (wchar_t *)0x2;
          }
          else {
            if (uVar4 == 0x36) {
              pwVar18 = (wchar_t *)0x17;
              goto LAB_00013818;
            }
            if (uVar4 == 0x3f) {
              uVar21 = 0;
              goto LAB_00013900;
            }
            if (uVar4 == 0x53) {
              if ((LPCWSTR)((int)pWVar24 + 1) < param_1) {
                memset(local_9a0,0,0x20);
                pWVar11 = *(LPCWSTR *)(pwVar25 + 4);
                local_9a0[2] = L'\x17';
                local_9a0[3] = L'\0';
                param_4 = (wchar_t **)0xffffffff;
                _Src = (LPCWSTR)0x0;
                local_9a0[0] = L'\x01';
                local_9a0[1] = L'\0';
                iVar8 = WideCharToMultiByte(1,0,pWVar11,-1,&local_838,0x401,(LPCSTR)0x0,(LPBOOL)0x0)
                ;
                if (iVar8 != 0) {
                  param_4 = &local_9cc;
                  pWVar11 = local_9a0;
                  _Src = (LPCWSTR)0x0;
                  iVar8 = getaddrinfo(&local_838);
                  pwVar22 = local_9cc;
                  if (iVar8 == 0) {
                    pWVar11 = *(LPCWSTR *)(local_9cc + 8);
                    _Src = *(LPCWSTR *)(local_9cc + 0xc);
                    memcpy(local_900,_Src,(size_t)pWVar11);
                    local_9dc = (wchar_t *)0x17;
                    freeaddrinfo();
                    pwVar18 = local_9dc;
                    goto LAB_00013800;
                  }
                }
              }
              pwVar18 = L"-S option must be followed by an IPv6 IP address.\r\n";
              goto LAB_0001405c;
            }
            if (uVar4 == 0x61) {
              local_9f8 = 1;
            }
            else if (uVar4 == 100) {
              DAT_00015f04 = 1;
            }
            else {
              if (uVar4 != 0x66) goto LAB_000138e8;
              local_9ee = CONCAT11(local_9ee._1_1_,2);
            }
          }
          goto LAB_00013818;
        }
        param_4 = (wchar_t **)0x0;
        _Src = param_1;
        pWVar11 = pWVar24;
        uVar29 = FUN_000131d8((int)param_2,(int)param_1,(int)pWVar24,0,0xff,&local_9f4);
        pwVar22 = (wchar_t *)(uVar29 & 0xff);
        local_9d8 = pwVar22;
      }
      else if (uVar4 == 0x6c) {
        param_4 = (wchar_t **)0x0;
        pwVar22 = param_2;
        _Src = param_1;
        pWVar11 = pWVar24;
        local_9d4 = (LPCWSTR)FUN_000131d8((int)param_2,(int)param_1,(int)pWVar24,0,0xfff7,&local_9f4
                                         );
      }
      else if (uVar4 == 0x6e) {
        param_4 = (wchar_t **)0x1;
        pwVar22 = param_2;
        _Src = param_1;
        pWVar11 = pWVar24;
        local_9e4 = (PUCHAR)FUN_000131d8((int)param_2,(int)param_1,(int)pWVar24,1,0xffffffff,
                                         &local_9f4);
      }
      else {
        if (uVar4 == 0x72) {
          if (iVar27 + 3 < 0x29) {
            (&DAT_00015ac0)[iVar27] = 7;
            (&DAT_00015ac2)[iVar27] = 4;
            param_4 = (wchar_t **)0x0;
            local_9e8 = &DAT_00015ac0;
            _Src = param_1;
            pWVar11 = pWVar24;
            uVar29 = FUN_000131d8((int)param_2,(int)param_1,(int)pWVar24,0,9,&local_9f4);
            pwVar22 = (wchar_t *)(uVar29 * 4);
            uVar29 = (int)pwVar22 + 3U & 0xff;
            iVar8 = uVar29 + iVar27;
            if (iVar8 < 0x29) {
              local_9ec = (wchar_t *)(uVar29 + (int)local_9ec);
              (&DAT_00015ac1)[iVar27] = (char)((int)pwVar22 + 3U);
              iVar27 = iVar8;
              goto LAB_00013800;
            }
          }
LAB_00013910:
          pwVar18 = L"Too many options\r\n";
          goto LAB_0001405c;
        }
        if (uVar4 == 0x73) {
          if (iVar27 + 4 < 0x29) {
            (&DAT_00015ac0)[iVar27] = 0x44;
            (&DAT_00015ac2)[iVar27] = 5;
            param_4 = (wchar_t **)0x1;
            local_9e8 = &DAT_00015ac0;
            _Src = param_1;
            pWVar11 = pWVar24;
            uVar29 = FUN_000131d8((int)param_2,(int)param_1,(int)pWVar24,1,4,&local_9f4);
            pwVar22 = (wchar_t *)(uVar29 * 8);
            uVar29 = (uint)(pwVar22 + 2) & 0xff;
            iVar8 = uVar29 + iVar27;
            if (iVar8 < 0x29) {
              local_9ec = (wchar_t *)(uVar29 + (int)local_9ec);
              (&DAT_00015ac1)[iVar27] = (char)(pwVar22 + 2);
              (&DAT_00015ac3)[iVar27] = 1;
              iVar27 = iVar8;
              goto LAB_00013800;
            }
          }
          goto LAB_00013910;
        }
        if (uVar4 == 0x74) {
          local_9e4 = (PUCHAR)0xffffffff;
          goto LAB_00013818;
        }
        if (uVar4 != 0x76) {
          if (uVar4 == 0x77) {
            param_4 = (wchar_t **)0x0;
            pwVar22 = param_2;
            _Src = param_1;
            pWVar11 = pWVar24;
            local_9c8 = FUN_000131d8((int)param_2,(int)param_1,(int)pWVar24,0,0xffffffff,&local_9f4)
            ;
            goto LAB_00013800;
          }
LAB_000138e8:
          _Src = *(LPCWSTR *)(param_2 + (int)pWVar24 * 2);
          pwVar22 = L"Bad option %s.\r\n\r\n";
          FUN_00012860(L"Bad option %s.\r\n\r\n",_Src,pWVar11,param_4);
          goto LAB_00013900;
        }
        param_4 = (wchar_t **)0x0;
        pwVar22 = param_2;
        _Src = param_1;
        pWVar11 = pWVar24;
        uVar29 = FUN_000131d8((int)param_2,(int)param_1,(int)pWVar24,0,0xff,&local_9f4);
        local_9f0 = (UCHAR)uVar29;
      }
LAB_00013800:
      pwVar15 = pwVar25 + 4;
      pWVar24 = (LPCWSTR)((int)pWVar24 + 1);
    }
    else {
      bVar1 = pWVar28 != (LPCWSTR)0x0;
      pWVar28 = pWVar24;
      if (bVar1) {
        DVar9 = *(DWORD *)(param_2 + (int)pWVar24 * 2);
        pwVar18 = L"Bad parameter %s.\r\n";
        goto LAB_00013384;
      }
    }
LAB_00013818:
    pWVar24 = (LPCWSTR)((int)pWVar24 + 1);
    pwVar25 = pwVar15;
    if (param_1 <= pWVar24) goto code_r0x00013828;
    goto LAB_000133f4;
  }
LAB_00014054:
  pwVar18 = L"IP address must be specified.\r\n";
  goto LAB_0001405c;
code_r0x00013828:
  if (pWVar28 == (LPCWSTR)0x0) goto LAB_00014054;
  if (local_9f4 != (wchar_t *)0x1) goto LAB_00014064;
  _Src = *(LPCWSTR *)(param_2 + (int)pWVar28 * 2);
  param_4 = &local_9e0;
  pWVar11 = local_980;
  iVar27 = FUN_00012f88(pwVar18,_Src,pWVar11,param_4,&local_430,0x401,local_9f8);
  pWVar28 = local_9d4;
  if (iVar27 == 0) {
    DVar9 = *(DWORD *)(param_2 + (int)pWVar24 * 2);
    pwVar18 = L"Bad IP address %s.\r\n";
    goto LAB_00013384;
  }
  if ((((local_980[0] == L'\x17') && (local_978 == -2)) && ((local_977 & 0xc0) == 0x80)) &&
     (local_968 == 0)) {
    pwVar18 = L"Scope Id must be specified for link local address.\r\n";
  }
  else {
    _Src = local_9d4;
    RequestData = LocalAlloc(0,(SIZE_T)local_9d4);
    local_9a8 = RequestData;
    if (RequestData != (char *)0x0) {
      if (pWVar28 < (LPCWSTR)0x21) {
        uBytes = 0x1ff8;
      }
      else {
        uBytes = 0x1003b;
      }
      SVar10 = uBytes;
      local_9c4 = uBytes;
      pwVar18 = LocalAlloc(0,uBytes);
      local_9cc = pwVar18;
      if (pwVar18 == (wchar_t *)0x0) {
        FUN_00012860(L"No Memory\r\n",SVar10,pWVar11,param_4);
        LocalFree(RequestData);
        goto LAB_00014064;
      }
      if (local_980[0] == 2) {
        IcmpHandle = IcmpCreateFile();
        goto LAB_00013a84;
      }
      if (local_900[0] == L'\0') {
        pWVar11 = (LPCWSTR)0x0;
        s = socket((int)local_980[0],2,0);
        if (s == 0xffffffff) {
          DVar9 = WSAGetLastError();
          pwVar18 = L"Can\'t create socket: %d";
          goto LAB_00013384;
        }
        WSAIoctl(s,0xc8000014,local_980,0x80,local_900,0x80,&local_9dc,0,0);
        closesocket(s);
        getnameinfo(local_900,local_9dc,&local_838,0x401,0,0,2);
        pWVar28 = local_9d4;
      }
      IcmpHandle = (HANDLE)Icmp6CreateFile();
LAB_00013a84:
      pWVar11 = (LPCWSTR)0x0;
      if (pWVar28 != (LPCWSTR)0x0) {
        do {
          uVar29 = (uint)pWVar11 % 0x17;
          pcVar16 = RequestData + (int)pWVar11;
          pWVar11 = (LPCWSTR)((int)pWVar11 + 1);
          *pcVar16 = (char)uVar29 + 'a';
        } while (pWVar11 < pWVar28);
      }
      local_9b8.OptionsData = local_9e8;
      local_9b8.Tos = local_9f0;
      local_9b8.Ttl = (UCHAR)local_9d8;
      local_9b8.OptionsSize = (UCHAR)local_9ec;
      local_9b8.Flags = (UCHAR)local_9ee;
      local_9b0 = L"Error %d\r\n";
      local_9d8 = L"%s";
      local_9ec = L"time<1ms ";
      local_9ac = L"time=%lums ";
      pwVar22 = L"PING: transmit failed, error code %lu\r\n";
      local_9dc = L"Reply from %hs: ";
      local_9f4 = L"PING: transmit failed, error code %lu\r\n";
      local_9a4 = L"Pinging Host %hs\r\n";
      local_9c0 = IcmpHandle;
      do {
        pwVar15 = local_9a4;
        pwVar25 = local_9e0;
        uVar21 = 0x41;
        pCVar12 = &local_880;
        getnameinfo(local_980,local_9e0,pCVar12,0x41,0,0,2);
        if (local_430 == '\0') {
          pcVar16 = &local_880;
          if (local_838 != '\0') {
            pCVar12 = &local_838;
            pwVar15 = L"Pinging Host %hs\r\nfrom %hs\r\n";
            goto LAB_00013bc0;
          }
          FUN_00012860(pwVar15,pcVar16,pCVar12,uVar21);
        }
        else {
          pCVar12 = &local_880;
          pcVar16 = &local_430;
          if (local_838 == '\0') {
            pwVar15 = L"Pinging Host %hs [%hs]\r\n";
LAB_00013bc0:
            FUN_00012860(pwVar15,pcVar16,pCVar12,uVar21);
          }
          else {
            FUN_00012860(L"Pinging Host %hs [%hs]\r\nfrom %hs\r\n",pcVar16,pCVar12,&local_838);
          }
        }
        local_9e8 = (PUCHAR)0x0;
        if (local_9e4 != (PUCHAR)0x0) {
          uVar29 = (uint)pWVar28 & 0xffff;
          local_9ee = (ushort)pWVar28;
          do {
            pUVar26 = local_9e8;
            if (local_980[0] == L'\x02') {
              pcVar16 = RequestData;
              DVar9 = IcmpSendEcho(IcmpHandle,local_97c,RequestData,(WORD)uVar29,&local_9b8,pwVar18,
                                   uBytes,local_9c8);
              pwVar6 = local_9ac;
              pwVar5 = local_9b0;
              pwVar15 = local_9d8;
              pwVar25 = local_9ec;
              if (DVar9 == 0) {
                DVar9 = GetLastError();
                FUN_00012860(pwVar22,DVar9,pcVar16,uVar29);
                pwVar25 = local_9e0;
              }
              else {
                local_9d0 = DVar9 + local_9d0;
                pwVar22 = pwVar18;
                do {
                  pwVar19 = pwVar22;
                  DVar9 = DVar9 - 1;
                  iVar27 = wsprintfW((LPWSTR)&DAT_00015100,local_9dc,&local_880);
                  iVar8 = *(int *)(pwVar19 + 2);
                  pWVar23 = (LPWSTR)(&DAT_00015100 + iVar27 * 2);
                  if (iVar8 == 0) {
                    iVar27 = wsprintfW(pWVar23,L"Echo size=%d ",(uint)(ushort)pwVar19[6]);
                    pWVar23 = pWVar23 + iVar27;
                    if ((LPCWSTR)(uint)(ushort)pwVar19[6] == local_9d4) {
                      pWVar11 = (LPCWSTR)0x0;
                      if (local_9d4 != (LPCWSTR)0x0) {
                        pcVar16 = RequestData;
                        do {
                          pcVar17 = pcVar16 + (*(int *)(pwVar19 + 8) - (int)RequestData);
                          cVar2 = *pcVar16;
                          pcVar16 = pcVar16 + 1;
                          if (cVar2 != *pcVar17) {
                            pwVar18 = L"- MISCOMPARE at offset %d - ";
                            goto LAB_00013d2c;
                          }
                          pWVar11 = (LPCWSTR)((int)pWVar11 + 1);
                        } while (pWVar11 < local_9d4);
                      }
                    }
                    else {
                      pwVar18 = L"(sent %d) ";
                      pWVar11 = local_9d4;
LAB_00013d2c:
                      iVar27 = wsprintfW(pWVar23,pwVar18,pWVar11);
                      pWVar23 = pWVar23 + iVar27;
                    }
                    if (*(int *)(pwVar19 + 4) == 0) {
                      iVar27 = wsprintfW(pWVar23,pwVar25);
                    }
                    else {
                      iVar27 = wsprintfW(pWVar23,pwVar6);
                    }
                    pcVar16 = (char *)(uint)(byte)pwVar19[10];
                    wsprintfW(pWVar23 + iVar27,L"TTL=%u\r\n");
                    FUN_00012860(pwVar15,&DAT_00015100,pcVar16,uVar29);
                    if (*(char *)((int)pwVar19 + 0x17) != '\0') {
                      FUN_00012a4c((int)pwVar19,(char *)(uint)local_9f8,pcVar16,uVar29);
                    }
                  }
                  else {
                    wsprintfW(pWVar23,pwVar5);
                    FUN_00012860(pwVar15,&DAT_00015100,iVar8,uVar29);
                  }
                  IcmpHandle = local_9c0;
                  uBytes = local_9c4;
                  pwVar18 = local_9cc;
                  pUVar26 = local_9e8;
                  pwVar22 = pwVar19 + 0xe;
                } while (DVar9 != 0);
                pwVar22 = local_9f4;
                pwVar25 = local_9e0;
                if ((local_9e8 < local_9e4 + -1) && (*(uint *)(pwVar19 + 4) < 1000)) {
                  Sleep(1000 - *(uint *)(pwVar19 + 4));
                  pwVar22 = local_9f4;
                  pwVar25 = local_9e0;
                }
              }
            }
            else {
              uVar14 = 0;
              uVar21 = 0;
              iVar27 = Icmp6SendEcho2(0,0,0,0,local_900,local_980,RequestData,uVar29,&local_9b8,
                                      pwVar18,uBytes,local_9c8);
              pwVar19 = local_9ac;
              pwVar6 = local_9b0;
              pwVar5 = local_9d8;
              pwVar15 = local_9dc;
              pwVar22 = local_9ec;
              if (iVar27 == 0) {
                DVar9 = GetLastError();
                pwVar22 = local_9f4;
                FUN_00012860(local_9f4,DVar9,uVar21,uVar14);
              }
              else {
                local_9d0 = iVar27 + local_9d0;
                pwVar7 = pwVar18;
                do {
                  pwVar20 = pwVar7;
                  uVar21 = 0x41;
                  iVar27 = iVar27 + -1;
                  getnameinfo(local_980,pwVar25,&local_880,0x41,0,0,2);
                  iVar8 = wsprintfW((LPWSTR)&DAT_00015100,pwVar15,&local_880);
                  iVar13 = *(int *)(pwVar20 + 0xe);
                  pWVar23 = (LPWSTR)(&DAT_00015100 + iVar8 * 2);
                  if (iVar13 == 0) {
                    iVar13 = *(int *)(pwVar20 + 0x10);
                    if (iVar13 == 0) {
                      wsprintfW(pWVar23,pwVar22);
                    }
                    else {
                      wsprintfW(pWVar23,pwVar19);
                    }
                    pwVar18 = L"%s\r\n";
                  }
                  else {
                    wsprintfW(pWVar23,pwVar6);
                    pwVar18 = pwVar5;
                  }
                  FUN_00012860(pwVar18,&DAT_00015100,iVar13,uVar21);
                  RequestData = local_9a8;
                  IcmpHandle = local_9c0;
                  uBytes = local_9c4;
                  pwVar18 = local_9cc;
                  pUVar26 = local_9e8;
                  pwVar7 = pwVar20 + 0x12;
                } while (iVar27 != 0);
                pwVar22 = local_9f4;
                if ((local_9e8 < local_9e4 + -1) && (*(uint *)(pwVar20 + 0x10) < 1000)) {
                  Sleep(1000 - *(uint *)(pwVar20 + 0x10));
                  pwVar22 = local_9f4;
                }
              }
            }
            local_9e8 = pUVar26 + 1;
            uVar29 = (uint)local_9ee;
          } while (local_9e8 < local_9e4);
          pWVar28 = local_9d4;
          if (local_9d0 != 0) break;
        }
        iVar27 = FUN_0001314c(local_980,&local_9e0,&local_430);
      } while (iVar27 != 0);
      LocalFree(RequestData);
      LocalFree(pwVar18);
      if (DAT_00015f08 != 0) {
        freeaddrinfo();
      }
      IcmpCloseHandle(IcmpHandle);
      FUN_00012668(local_2c);
      return 0;
    }
    pwVar18 = L"No Memory\r\n";
  }
LAB_0001405c:
  FUN_00012860(pwVar18,_Src,pWVar11,param_4);
LAB_00014064:
  FUN_00012668(local_2c);
  return uVar21;
}


