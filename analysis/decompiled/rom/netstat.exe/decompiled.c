/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00013600 FUN_00013600 */

/* Boundary evidence: original MIPS .pdata 00013600..00013693. Semantic name remains unreviewed. */

void FUN_00013600(undefined4 param_1,undefined4 param_2,wint_t *param_3,undefined4 param_4)

{
  UINT UVar1;
  
  FUN_00013910();
  UVar1 = FUN_00014a0c(param_1,param_2,param_3,param_4);
  FUN_00013850(UVar1);
  FUN_00013870(UVar1);
  return;
}



/* 00013694 FUN_00013694 */

/* Boundary evidence: original MIPS .pdata 00013694..000136d3. Semantic name remains unreviewed. */

void FUN_00013694(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 000136d4 entry */

/* Boundary evidence: original MIPS .pdata 000136d4..0001372f. Semantic name remains unreviewed. */

void entry(undefined4 param_1,undefined4 param_2,wint_t *param_3,undefined4 param_4)

{
  FUN_0001394c();
  FUN_00013600(param_1,param_2,param_3,param_4);
  return;
}



/* 00013730 FUN_00013730 */

/* Boundary evidence: original MIPS .pdata 00013730..0001384f. Semantic name remains unreviewed. */

void FUN_00013730(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_000170b8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000170cc;
    if (DAT_000170cc != (undefined4 *)0x0) {
      while (DAT_000170c8 = DAT_000170c8 + -1, _Memory <= DAT_000170c8) {
        if ((code *)*DAT_000170c8 != (code *)0x0) {
          (*(code *)*DAT_000170c8)();
          _Memory = DAT_000170cc;
        }
      }
      free(_Memory);
      DAT_000170c8 = (undefined4 *)0x0;
      DAT_000170cc = (undefined4 *)0x0;
    }
    FUN_000138bc((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_000138bc((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_000170d0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00013850 FUN_00013850 */

/* Boundary evidence: original MIPS .pdata 00013850..0001386f. Semantic name remains unreviewed. */

void FUN_00013850(UINT param_1)

{
  FUN_00013730(param_1,0,0);
  return;
}



/* 00013870 FUN_00013870 */

/* Boundary evidence: original MIPS .pdata 00013870..000138bb. Semantic name remains unreviewed. */

void FUN_00013870(UINT param_1)

{
  DAT_000170b8 = 0;
  FUN_000138bc((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000138bc FUN_000138bc */

/* Boundary evidence: original MIPS .pdata 000138bc..0001390f. Semantic name remains unreviewed. */

void FUN_000138bc(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00013910 FUN_00013910 */

/* Boundary evidence: original MIPS .pdata 00013910..0001394b. Semantic name remains unreviewed. */

void FUN_00013910(void)

{
  FUN_000138bc((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_000138bc((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 0001394c FUN_0001394c */

/* Boundary evidence: original MIPS .pdata 0001394c..000139bf. Semantic name remains unreviewed. */

void FUN_0001394c(void)

{
  uint uVar1;
  
  if ((DAT_000170b0 == 0) || (DAT_000170b0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000170b0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000170b0 == 0) {
      DAT_000170b0 = 0xb064;
    }
  }
  DAT_000170b4 = ~DAT_000170b0;
  return;
}



/* 00013a40 FUN_00013a40 */

/* Boundary evidence: original MIPS .pdata 00013a40..00013b43. Semantic name remains unreviewed. */

int FUN_00013a40(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t awStack_218 [255];
  undefined2 local_1a;
  uint local_18;
  
  local_18 = DAT_000170b0;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  iVar1 = _vsnwprintf(awStack_218,0xff,param_1,(va_list)&local_res4);
  local_1a = 0;
  if (DAT_000170c0 == 0) {
    if (DAT_000170c4 == (code *)0x0) {
      DAT_000170bc = LoadLibraryW(L"coredll.dll");
      if (DAT_000170bc != (HMODULE)0x0) {
        DAT_000170c4 = (code *)GetProcAddressW(DAT_000170bc,L"wprintf");
      }
      if (DAT_000170c4 != (code *)0x0) goto LAB_00013af8;
      DAT_000170c0 = 1;
    }
    else {
LAB_00013af8:
      (*DAT_000170c4)(&UNK_0001103c,awStack_218);
    }
    if (DAT_000170c0 == 0) goto LAB_00013b20;
  }
  OutputDebugStringW(awStack_218);
LAB_00013b20:
  FUN_00015f64(local_18);
  return iVar1;
}



/* 00013b44 FUN_00013b44 */

/* Boundary evidence: original MIPS .pdata 00013b44..00013c47. Semantic name remains unreviewed. */

undefined4 FUN_00013b44(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *_Memory;
  DWORD DVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  _Memory = malloc(0x3c);
  if (_Memory == (undefined4 *)0x0) {
    FUN_00013a40(L"GetTcpStats Can not allocate memeory",param_2,param_3,param_4);
    uVar2 = 0;
  }
  else {
    if ((param_1 & 0x10) != 0) {
      param_2 = 0x17;
      DVar1 = GetTcpStatisticsEx(_Memory);
      if (DVar1 == 0) {
        param_2 = 0x10;
        FUN_000150b0(_Memory,0x10,param_3,param_4);
      }
      else {
        FUN_00013a40(L"GetTcpStatsEx.",param_2,param_3,param_4);
        FUN_00014a6c(DVar1);
        uVar2 = 0;
      }
    }
    if ((param_1 & 1) != 0) {
      DVar1 = GetTcpStatistics(_Memory);
      if (DVar1 == 0) {
        FUN_000150b0(_Memory,1,param_3,param_4);
      }
      else {
        FUN_00013a40(L"GetTcpStats.",param_2,param_3,param_4);
        FUN_00014a6c(DVar1);
        uVar2 = 0;
      }
    }
    free(_Memory);
  }
  return uVar2;
}



/* 00013c48 FUN_00013c48 */

/* Boundary evidence: original MIPS .pdata 00013c48..00013d4b. Semantic name remains unreviewed. */

undefined4 FUN_00013c48(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *_Memory;
  DWORD DVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  _Memory = malloc(0x14);
  if (_Memory == (undefined4 *)0x0) {
    FUN_00013a40(L"GetUdpStats Can not allocate memeory",param_2,param_3,param_4);
    uVar2 = 0;
  }
  else {
    if ((param_1 & 0x20) != 0) {
      param_2 = 0x17;
      DVar1 = GetUdpStatisticsEx(_Memory);
      if (DVar1 == 0) {
        param_2 = 0x20;
        FUN_00015238(_Memory,0x20,param_3,param_4);
      }
      else {
        FUN_00013a40(L"GetUdpStatsEx.",param_2,param_3,param_4);
        FUN_00014a6c(DVar1);
        uVar2 = 0;
      }
    }
    if ((param_1 & 2) != 0) {
      DVar1 = GetUdpStatistics(_Memory);
      if (DVar1 == 0) {
        FUN_00015238(_Memory,2,param_3,param_4);
      }
      else {
        FUN_00013a40(L"GetUdpStats.",param_2,param_3,param_4);
        FUN_00014a6c(DVar1);
        uVar2 = 0;
      }
    }
    free(_Memory);
  }
  return uVar2;
}



/* 00013d4c FUN_00013d4c */

/* Boundary evidence: original MIPS .pdata 00013d4c..00013e43. Semantic name remains unreviewed. */

bool FUN_00013d4c(undefined4 param_1,size_t *param_2,undefined4 param_3,undefined4 param_4)

{
  uint *_Memory;
  DWORD DVar1;
  wchar_t *pwVar2;
  bool bVar3;
  size_t local_18 [2];
  
  local_18[0] = 0x270;
  _Memory = malloc(0x270);
  if (_Memory == (uint *)0x0) {
    pwVar2 = L"GetTcpTable Can not allocate memeory";
LAB_00013d88:
    FUN_00013a40(pwVar2,param_2,param_3,param_4);
    bVar3 = false;
  }
  else {
    param_3 = 1;
    param_2 = local_18;
    DVar1 = GetTcpTable(_Memory);
    if (DVar1 == 0x7a) {
      free(_Memory);
      _Memory = malloc(local_18[0]);
      if (_Memory == (uint *)0x0) {
        pwVar2 = L"Can not allocate memeory";
        goto LAB_00013d88;
      }
      param_3 = 1;
      param_2 = local_18;
      DVar1 = GetTcpTable(_Memory);
    }
    bVar3 = DVar1 == 0;
    if (bVar3) {
      FUN_000152fc(_Memory,param_2,param_3,param_4);
    }
    else {
      FUN_00013a40(L"GetTcpTable.",param_2,param_3,param_4);
      FUN_00014a6c(DVar1);
    }
    free(_Memory);
  }
  return bVar3;
}



/* 00013e44 FUN_00013e44 */

/* Boundary evidence: original MIPS .pdata 00013e44..00013f3b. Semantic name remains unreviewed. */

bool FUN_00013e44(undefined4 param_1,size_t *param_2,undefined4 param_3,undefined4 param_4)

{
  uint *_Memory;
  DWORD DVar1;
  wchar_t *pwVar2;
  bool bVar3;
  size_t local_18 [2];
  
  local_18[0] = 0x100;
  _Memory = malloc(0x100);
  if (_Memory == (uint *)0x0) {
    pwVar2 = L"Can not allocate memeory\n";
LAB_00013e80:
    FUN_00013a40(pwVar2,param_2,param_3,param_4);
    bVar3 = false;
  }
  else {
    param_3 = 1;
    param_2 = local_18;
    DVar1 = GetUdpTable(_Memory);
    if (DVar1 == 0x7a) {
      free(_Memory);
      _Memory = malloc(local_18[0]);
      if (_Memory == (uint *)0x0) {
        pwVar2 = L"Can not allocate memeory";
        goto LAB_00013e80;
      }
      param_3 = 1;
      param_2 = local_18;
      DVar1 = GetUdpTable(_Memory);
    }
    bVar3 = DVar1 == 0;
    if (bVar3) {
      FUN_000155ec(_Memory,param_2,param_3,param_4);
    }
    else {
      FUN_00013a40(L"GetUdpTable.\n",param_2,param_3,param_4);
      FUN_00014a6c(DVar1);
    }
    free(_Memory);
  }
  return bVar3;
}



/* 00013f3c FUN_00013f3c */

/* Boundary evidence: original MIPS .pdata 00013f3c..0001403f. Semantic name remains unreviewed. */

undefined4 FUN_00013f3c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *_Memory;
  DWORD DVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  _Memory = malloc(0x5c);
  if (_Memory == (undefined4 *)0x0) {
    FUN_00013a40(L"Can not allocate memeory",param_2,param_3,param_4);
    uVar2 = 0;
  }
  else {
    if ((param_1 & 0x40) != 0) {
      param_2 = 0x17;
      DVar1 = GetIpStatisticsEx(_Memory);
      if (DVar1 == 0) {
        param_2 = 0x40;
        FUN_00014ad0(_Memory,0x40,param_3,param_4);
      }
      else {
        FUN_00013a40(L"GetIpStatsEx.",param_2,param_3,param_4);
        FUN_00014a6c(DVar1);
        uVar2 = 0;
      }
    }
    if ((param_1 & 4) != 0) {
      DVar1 = GetIpStatistics(_Memory);
      if (DVar1 == 0) {
        FUN_00014ad0(_Memory,4,param_3,param_4);
      }
      else {
        FUN_00013a40(L"GetIpStats.",param_2,param_3,param_4);
        FUN_00014a6c(DVar1);
        uVar2 = 0;
      }
    }
    free(_Memory);
  }
  return uVar2;
}



/* 00014040 FUN_00014040 */

/* Boundary evidence: original MIPS .pdata 00014040..0001418b. Semantic name remains unreviewed. */

undefined4 FUN_00014040(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  undefined4 *_Memory;
  undefined4 *_Memory_00;
  undefined4 uVar2;
  
  uVar2 = 1;
  _Memory_00 = (undefined4 *)0x0;
  if ((param_1 & 0x80) == 0) {
LAB_000140d4:
    if ((param_1 & 8) != 0) {
      _Memory = malloc(0x68);
      if (_Memory == (undefined4 *)0x0) {
        FUN_00013a40(L"Can not allocate memeory",param_2,param_3,param_4);
        if (_Memory_00 != (undefined4 *)0x0) {
          free(_Memory_00);
        }
        goto LAB_0001408c;
      }
      DVar1 = GetIcmpStatistics(_Memory);
      if (DVar1 == 0) {
        FUN_00014cb8(_Memory,8,param_3,param_4);
      }
      else {
        FUN_00013a40(L"GetIcmpStats.",param_2,param_3,param_4);
        FUN_00014a6c(DVar1);
        uVar2 = 0;
      }
      free(_Memory);
    }
    if (_Memory_00 != (undefined4 *)0x0) {
      free(_Memory_00);
    }
  }
  else {
    _Memory_00 = malloc(0x810);
    if (_Memory_00 != (undefined4 *)0x0) {
      param_2 = 0x17;
      DVar1 = GetIcmpStatisticsEx(_Memory_00);
      if (DVar1 == 0) {
        param_2 = 0x80;
        FUN_00014e90(_Memory_00,0x80,param_3,param_4);
      }
      else {
        FUN_00013a40(L"GetIcmpStatsFromStackEx.",param_2,param_3,param_4);
        FUN_00014a6c(DVar1);
        uVar2 = 0;
      }
      goto LAB_000140d4;
    }
    FUN_00013a40(L"Can not allocate memeory",param_2,param_3,param_4);
LAB_0001408c:
    uVar2 = 0;
  }
  return uVar2;
}



/* 0001418c FUN_0001418c */

/* Boundary evidence: original MIPS .pdata 0001418c..0001425f. Semantic name remains unreviewed. */

undefined4 * FUN_0001418c(undefined4 param_1,size_t *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD DVar3;
  size_t *psVar4;
  size_t local_18 [2];
  
  local_18[0] = 0x6828;
  puVar1 = malloc(0x6828);
  if (puVar1 != (undefined4 *)0x0) {
    param_2 = local_18;
    *puVar1 = 0x1e;
    param_3 = param_1;
    iVar2 = GetIfTable(puVar1);
    if (iVar2 == 0) {
      return puVar1;
    }
    free(puVar1);
    puVar1 = malloc(local_18[0]);
    if (puVar1 != (undefined4 *)0x0) {
      psVar4 = local_18;
      DVar3 = GetIfTable(puVar1);
      if (DVar3 != 0) {
        FUN_00013a40(L"GetIfTable",psVar4,param_1,param_4);
        FUN_00014a6c(DVar3);
        free(puVar1);
        return (undefined4 *)0x0;
      }
      return puVar1;
    }
  }
  FUN_00013a40(L"Can not allocate memeory",param_2,param_3,param_4);
  return (undefined4 *)0x0;
}



/* 00014260 FUN_00014260 */

/* Boundary evidence: original MIPS .pdata 00014260..00014303. Semantic name remains unreviewed. */

void FUN_00014260(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00013a40(L"\r\nNetstat (c) Microsoft -  Windows CE utility\r\n\r\n",param_2,param_3,param_4);
  FUN_00013a40(L"Displays protocol statistics and current TCP/IP network connections.\r\n",param_2,
               param_3,param_4);
  FUN_00013a40(L"NETSTAT  [-e] [-n] [-s] [-p proto] [-r] [interval]\r\n",param_2,param_3,param_4);
  FUN_00013a40(L"  -e            Displays Ethernet statistics.\n",param_2,param_3,param_4);
  FUN_00013a40(L"  -n            Displays addresses and port numbers in numerical form.\r\n",param_2
               ,param_3,param_4);
  FUN_00013a40(L"  -p proto      Shows statistics for the protocol specified by proto; proto\n                IP, IPv6, ICMP, ICMPv6, TCP, TCPv6, UDP, or UDPv6.\n"
               ,param_2,param_3,param_4);
  FUN_00013a40(L"  -r            Displays the routing table.\n  -s            Displays per-protocol statistics.  By default, statistics are\n"
               ,param_2,param_3,param_4);
  FUN_00013a40(L"                shown for IP, IPv6, ICMP, ICMPv6, TCP, TCPv6, UDP, and UDPv6;\n                the -p option may be used to specify a subset of the default.\n"
               ,param_2,param_3,param_4);
  FUN_00013a40(L"  interval      Redisplays selected statistics, pausing interval seconds\n                between each display.  Press CTRL+C to stop redisplaying\n"
               ,param_2,param_3,param_4);
  FUN_00013a40(L"                statistics.  If omitted, netstat will print the current\n                configuration information once.\n"
               ,param_2,param_3,param_4);
  FUN_00013a40(L"  -d            Display redirected to the Debug Output Port \r\n",param_2,param_3,
               param_4);
  FUN_00013a40(L"  -?            Displays help (for Debug Output Port preceed by -d)\r\n",param_2,
               param_3,param_4);
  return;
}



/* 00014304 FUN_00014304 */

/* Boundary evidence: original MIPS .pdata 00014304..000143a3. Semantic name remains unreviewed. */

void FUN_00014304(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (((param_1 & 1) != 0) || ((param_1 & 0x10) != 0)) {
    FUN_00013b44(param_1,param_2,param_3,param_4);
  }
  if (((param_1 & 2) != 0) || ((param_1 & 0x20) != 0)) {
    FUN_00013c48(param_1,param_2,param_3,param_4);
  }
  if (((param_1 & 4) != 0) || ((param_1 & 0x40) != 0)) {
    FUN_00013f3c(param_1,param_2,param_3,param_4);
  }
  if (((param_1 & 8) != 0) || ((param_1 & 0x80) != 0)) {
    FUN_00014040(param_1,param_2,param_3,param_4);
  }
  return;
}



/* 000143a4 FUN_000143a4 */

/* Boundary evidence: original MIPS .pdata 000143a4..0001452b. Semantic name remains unreviewed. */

void FUN_000143a4(wint_t *param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  wint_t wVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  bVar3 = false;
  if (((param_1 != (wint_t *)0x0) && (param_2 != (int *)0x0)) && (param_3 != (undefined4 *)0x0)) {
    iVar6 = 0;
    if (0 < *param_2) {
      do {
        if (bVar3) break;
        while ((*param_1 != 0 && (iVar4 = iswctype(*param_1,8), iVar4 != 0))) {
          *param_1 = 0;
          param_1 = param_1 + 1;
        }
        bVar1 = *param_1 == 0x22;
        if (bVar1) {
          *param_1 = 0;
          param_1 = param_1 + 1;
        }
        *param_3 = param_1;
        wVar2 = *param_1;
        if (wVar2 != 0) {
          iVar5 = iVar6 + 1;
          while (wVar2 != 0) {
            if (bVar1) {
              if (*param_1 == 0x22) {
LAB_00014484:
                *param_1 = 0;
                param_1 = param_1 + 1;
                break;
              }
            }
            else if (*param_1 == 0x22) {
              *param_1 = 0x20;
              param_1 = param_1 + 1;
              bVar1 = true;
            }
            else {
              iVar4 = iswctype(*param_1,8);
              if (iVar4 != 0) goto LAB_00014484;
            }
            param_1 = param_1 + 1;
            wVar2 = *param_1;
          }
        }
        if (*param_1 == 0) {
          bVar3 = true;
        }
        iVar6 = iVar6 + 1;
        param_3 = param_3 + 1;
      } while (iVar6 < *param_2);
    }
    *param_2 = iVar5;
  }
  return;
}



/* 0001452c FUN_0001452c */

/* Boundary evidence: original MIPS .pdata 0001452c..00014673. Semantic name remains unreviewed. */

undefined4 FUN_0001452c(undefined4 param_1,size_t *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *_Memory;
  DWORD DVar2;
  int *piVar3;
  undefined4 uVar4;
  size_t *psVar5;
  undefined1 auStack_388 [512];
  int local_188;
  uint local_2c;
  
  local_2c = DAT_000170b0;
  uVar4 = 1;
  _Memory = FUN_0001418c(0,param_2,param_3,param_4);
  if (_Memory == (int *)0x0) {
    FUN_00013a40(L"GetIfEntry\n",param_2,param_3,param_4);
    FUN_00014a6c(0);
    FUN_00015f64(local_2c);
    uVar4 = 0;
  }
  else {
    psVar5 = (size_t *)0x0;
    if (*_Memory != 0) {
      piVar3 = _Memory + 0x81;
      do {
        local_188 = *piVar3;
        iVar1 = *piVar3;
        if (local_188 != 1) {
          DVar2 = GetIfEntry(auStack_388);
          if (DVar2 == 0) {
            FUN_00015774((int)auStack_388,param_2,param_3,param_4);
            iVar1 = local_188;
          }
          else {
            FUN_00013a40(L"GetIfEntry\n",param_2,param_3,param_4);
            FUN_00014a6c(DVar2);
            param_3 = *piVar3;
            param_2 = psVar5;
            FUN_00013a40(L"i=%d, index=%d",psVar5,param_3,param_4);
            uVar4 = 0;
            iVar1 = local_188;
          }
        }
        local_188 = iVar1;
        psVar5 = (size_t *)((int)psVar5 + 1);
        piVar3 = piVar3 + 0xd7;
      } while (psVar5 < (size_t *)*_Memory);
    }
    free(_Memory);
    FUN_00015f64(local_2c);
  }
  return uVar4;
}



/* 00014674 FUN_00014674 */

/* Boundary evidence: original MIPS .pdata 00014674..00014a0b. Semantic name remains unreviewed. */

undefined4 FUN_00014674(wchar_t *param_1,wchar_t *param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  wchar_t *_Str1;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  uint uVar9;
  long lVar10;
  int iVar11;
  
  bVar5 = false;
  uVar9 = 0;
  lVar10 = 0;
  bVar1 = false;
  bVar2 = false;
  bVar3 = false;
  bVar4 = false;
  _Str1 = param_1;
  pwVar8 = param_2;
  if (param_1 == (wchar_t *)0x0) {
    FUN_00014260(0,param_2,param_3,param_4);
    _Str1 = (wchar_t *)0x1;
    FUN_00013850(1);
  }
  iVar11 = 0;
  pwVar7 = _Str1;
  if (0 < (int)param_1) {
    do {
      _Str1 = *(wchar_t **)param_2;
      if ((*_Str1 == L'-') || (*_Str1 == L'/')) {
        _Str1 = (wchar_t *)(uint)(ushort)_Str1[1];
        iVar6 = toupper((int)_Str1);
        if (iVar6 == 0x3f) goto LAB_00014950;
        if (iVar6 == 0x44) {
          DAT_000170c0 = 1;
        }
        else if (iVar6 == 0x45) {
          bVar2 = true;
        }
        else if (iVar6 == 0x4e) {
          bVar3 = true;
        }
        else {
          pwVar7 = _Str1;
          if (iVar6 == 0x50) {
            iVar11 = iVar11 + 1;
            param_2 = param_2 + 2;
            if (iVar11 < (int)param_1) {
              pwVar8 = L"TCP";
              _Str1 = *(wchar_t **)param_2;
              bVar4 = true;
              iVar6 = _wcsicmp(_Str1,L"TCP");
              if (iVar6 == 0) {
                uVar9 = 1;
              }
              else {
                pwVar8 = L"TCPv6";
                _Str1 = *(wchar_t **)param_2;
                iVar6 = _wcsicmp(_Str1,L"TCPv6");
                if (iVar6 == 0) {
                  uVar9 = 0x10;
                }
                else {
                  pwVar8 = L"UDP";
                  _Str1 = *(wchar_t **)param_2;
                  iVar6 = _wcsicmp(_Str1,L"UDP");
                  if (iVar6 == 0) {
                    uVar9 = 2;
                  }
                  else {
                    pwVar8 = L"UDPv6";
                    _Str1 = *(wchar_t **)param_2;
                    iVar6 = _wcsicmp(_Str1,L"UDPv6");
                    if (iVar6 == 0) {
                      uVar9 = 0x20;
                    }
                    else {
                      pwVar8 = L"IP";
                      _Str1 = *(wchar_t **)param_2;
                      iVar6 = _wcsicmp(_Str1,L"IP");
                      if (iVar6 == 0) {
                        uVar9 = 4;
                      }
                      else {
                        pwVar8 = L"IPv6";
                        _Str1 = *(wchar_t **)param_2;
                        iVar6 = _wcsicmp(_Str1,L"IPv6");
                        if (iVar6 == 0) {
                          uVar9 = 0x40;
                        }
                        else {
                          pwVar8 = L"ICMP";
                          _Str1 = *(wchar_t **)param_2;
                          iVar6 = _wcsicmp(_Str1,L"ICMP");
                          if (iVar6 == 0) {
                            uVar9 = 8;
                          }
                          else {
                            pwVar8 = L"ICMPv6";
                            _Str1 = *(wchar_t **)param_2;
                            iVar6 = _wcsicmp(_Str1,L"ICMPv6");
                            if (iVar6 == 0) {
                              uVar9 = 0x80;
                            }
                            else {
                              bVar1 = true;
                              bVar4 = false;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
LAB_000147bc:
              _Str1 = pwVar7;
              bVar1 = true;
            }
          }
          else if (iVar6 == 0x52) {
            bVar5 = true;
          }
          else {
            if (iVar6 != 0x53) goto LAB_000147bc;
            bVar4 = true;
            uVar9 = 0xff;
          }
        }
      }
      else if ((lVar10 != 0) || (lVar10 = _wtol(_Str1), pwVar7 = _Str1, lVar10 == 0))
      goto LAB_000147bc;
      iVar11 = iVar11 + 1;
      param_2 = param_2 + 2;
      pwVar7 = _Str1;
    } while (iVar11 < (int)param_1);
    if (bVar1) {
      FUN_00013a40(L"Incorrect Parameters\n",pwVar8,param_3,param_4);
      _Str1 = (wchar_t *)0x1;
      FUN_00013850(1);
LAB_00014950:
      FUN_00014260(_Str1,pwVar8,param_3,param_4);
      _Str1 = (wchar_t *)0x1;
      FUN_00013850(1);
    }
  }
  while( true ) {
    if (bVar2) {
      FUN_0001452c(_Str1,(size_t *)pwVar8,param_3,param_4);
    }
    if (bVar3) {
      FUN_00013d4c(_Str1,(size_t *)pwVar8,param_3,param_4);
      FUN_00013e44(_Str1,(size_t *)pwVar8,param_3,param_4);
    }
    if (bVar4) {
      FUN_00014304(uVar9,pwVar8,param_3,param_4);
    }
    if (bVar5) {
      FUN_00015c24();
    }
    if (lVar10 == 0) break;
    _Str1 = (wchar_t *)(lVar10 * 1000);
    Sleep((DWORD)_Str1);
  }
  return 0;
}



/* 00014a0c FUN_00014a0c */

/* Boundary evidence: original MIPS .pdata 00014a0c..00014a6b. Semantic name remains unreviewed. */

void FUN_00014a0c(undefined4 param_1,undefined4 param_2,wint_t *param_3,undefined4 param_4)

{
  undefined **ppuVar1;
  wchar_t *local_60 [2];
  undefined *local_58;
  undefined1 auStack_54 [76];
  
  local_58 = &DAT_00011c90;
  memset(auStack_54,0,0x4c);
  local_60[0] = (wchar_t *)0x14;
  ppuVar1 = &local_58;
  FUN_000143a4(param_3,(int *)local_60,ppuVar1);
  FUN_00014674(local_60[0],(wchar_t *)&local_58,(int)ppuVar1,param_4);
  return;
}



/* 00014a6c FUN_00014a6c */

/* Boundary evidence: original MIPS .pdata 00014a6c..00014acf. Semantic name remains unreviewed. */

void FUN_00014a6c(DWORD param_1)

{
  undefined4 uVar1;
  HLOCAL local_10 [2];
  
  uVar1 = 0x400;
  local_10[0] = (HLOCAL)0x0;
  FormatMessageW(0x1300,(LPCVOID)0x0,param_1,0x400,(LPWSTR)local_10,0,(va_list *)0x0);
  if (local_10[0] != (HLOCAL)0x0) {
    FUN_00013a40(L"%ls",local_10[0],param_1,uVar1);
    LocalFree(local_10[0]);
  }
  return;
}



/* 00014ad0 FUN_00014ad0 */

/* Boundary evidence: original MIPS .pdata 00014ad0..00014cb7. Semantic name remains unreviewed. */

void FUN_00014ad0(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_00013a40(L"\n",param_2,param_3,param_4);
    if (param_2 == 4) {
      puVar1 = &DAT_00011c60;
    }
    else {
      puVar1 = &DAT_00012354;
    }
    FUN_00013a40(L"%s Statistics:\n",puVar1,param_3,param_4);
    FUN_00013a40(L"--------------\n",puVar1,param_3,param_4);
    FUN_00013a40(L"Packets Received            = %lu\n",param_1[2],param_3,param_4);
    FUN_00013a40(L"Received Header Errors      = %lu\n",param_1[3],param_3,param_4);
    FUN_00013a40(L"Received Address Errors     = %lu\n",param_1[4],param_3,param_4);
    FUN_00013a40(L"Datagrams Forwarded         = %lu\n",param_1[5],param_3,param_4);
    FUN_00013a40(L"Unknown Protocols Received  = %lu\n",param_1[6],param_3,param_4);
    FUN_00013a40(L"Received Packets Discarded  = %lu\n",param_1[7],param_3,param_4);
    FUN_00013a40(L"Received Packets Delivered  = %lu\n",param_1[8],param_3,param_4);
    FUN_00013a40(L"Output Requests             = %lu\n",param_1[9],param_3,param_4);
    FUN_00013a40(L"Routing Discards            = %lu\n",param_1[10],param_3,param_4);
    FUN_00013a40(L"Discarded Output Packets    = %lu\n",param_1[0xb],param_3,param_4);
    FUN_00013a40(L"Output Packet No Route      = %lu\n",param_1[0xc],param_3,param_4);
    FUN_00013a40(L"Reassembly Required         = %lu\n",param_1[0xe],param_3,param_4);
    FUN_00013a40(L"Reassembly Successful       = %lu\n",param_1[0xf],param_3,param_4);
    FUN_00013a40(L"Reassembly Failures         = %lu\n",param_1[0x10],param_3,param_4);
    FUN_00013a40(L"Datagrams Fragmented OK     = %lu\n",param_1[0x11],param_3,param_4);
    FUN_00013a40(L"Datagrams Fragmented Fail   = %lu\n",param_1[0x12],param_3,param_4);
    FUN_00013a40(L"Fragments Created           = %lu\n",param_1[0x13],param_3,param_4);
    FUN_00013a40(L"DefaultTTL                  = %lu\n",param_1[1],param_3,param_4);
    FUN_00013a40(L"Datagrams All Frgs Not Rcvd = %lu\n",param_1[0xd],param_3,param_4);
    FUN_00013a40(L"Number of Interfaces        = %lu\n",param_1[0x14],param_3,param_4);
    FUN_00013a40(L"Number of Addresses         = %lu\n",param_1[0x15],param_3,param_4);
    FUN_00013a40(L"Number of Routes in Table   = %lu\n",param_1[0x16],param_3,param_4);
    FUN_00013a40(L"Forwarding Enabled          = %lu\n",*param_1,param_3,param_4);
  }
  return;
}



/* 00014cb8 FUN_00014cb8 */

/* Boundary evidence: original MIPS .pdata 00014cb8..00014e8f. Semantic name remains unreviewed. */

void FUN_00014cb8(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  wchar_t *pwVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_00013a40(L"\n",param_2,param_3,param_4);
    if (param_2 == 8) {
      pwVar1 = L"ICMP Statistics";
    }
    else {
      pwVar1 = L"ICMP6 Statistics";
    }
    FUN_00013a40(L"%25s %10s %10s\n",pwVar1,L"Received",L"Sent");
    FUN_00013a40(L"%25s %10s %10s\n",L"---------------",L"------",L"------");
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Messages",*param_1,param_1[0xd]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Errors",param_1[1],param_1[0xe]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Destination Unreachable",param_1[2],param_1[0xf]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Time Exceeded",param_1[3],param_1[0x10]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Parmeter Problems",param_1[4],param_1[0x11]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Source Quenches",param_1[5],param_1[0x12]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Redirects",param_1[6],param_1[0x13]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Echos",param_1[7],param_1[0x14]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Echo Replies",param_1[8],param_1[0x15]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Timestamps",param_1[9],param_1[0x16]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Timestamp Replies",param_1[10],param_1[0x17]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Address Masks",param_1[0xb],param_1[0x18]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Address Mask Replies",param_1[0xc],param_1[0x19]);
  }
  return;
}



/* 00014e90 FUN_00014e90 */

/* Boundary evidence: original MIPS .pdata 00014e90..000150af. Semantic name remains unreviewed. */

void FUN_00014e90(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  wchar_t *pwVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_00013a40(L"\n",param_2,param_3,param_4);
    if (param_2 == 8) {
      pwVar1 = L"ICMP Statistics";
    }
    else {
      pwVar1 = L"ICMP6 Statistics";
    }
    FUN_00013a40(L"%25s %10s %10s\n",pwVar1,L"Received",L"Sent");
    FUN_00013a40(L"%25s %10s %10s\n",L"---------------",L"------",L"------");
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Messages",*param_1,param_1[0x102]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Errors",param_1[1],param_1[0x103]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Destination Unreachable",param_1[3],param_1[0x105]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Packet Too Big",param_1[4],param_1[0x106]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Time Exceeded",param_1[5],param_1[0x107]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Param Problem",param_1[6],param_1[0x108]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Echo Request",param_1[0x82],param_1[0x184]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Echo Reply",param_1[0x83],param_1[0x185]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Membership Query",param_1[0x84],param_1[0x186]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Membership report",param_1[0x85],param_1[0x187]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Membership reduction",param_1[0x86],param_1[0x188]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Router Solicitation",param_1[0x87],param_1[0x189]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Router Advertisment",param_1[0x88],param_1[0x18a]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Neighbor Solicitation",param_1[0x89],param_1[0x18b]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Neighbor Advertisment",param_1[0x8a],param_1[0x18c]);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Redirect",param_1[0x8b],param_1[0x18d]);
  }
  return;
}



/* 000150b0 FUN_000150b0 */

/* Boundary evidence: original MIPS .pdata 000150b0..00015237. Semantic name remains unreviewed. */

void FUN_000150b0(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  wchar_t *pwVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_00013a40(L"\n",param_2,param_3,param_4);
    if (param_2 == 1) {
      pwVar1 = L"TCP";
    }
    else {
      pwVar1 = L"TCP6";
    }
    FUN_00013a40(L"%s Statistics:\n",pwVar1,param_3,param_4);
    FUN_00013a40(L"--------------\n",pwVar1,param_3,param_4);
    FUN_00013a40(L"Active Opens            = %lu\n",param_1[4],param_3,param_4);
    FUN_00013a40(L"Passive Opens           = %lu\n",param_1[5],param_3,param_4);
    FUN_00013a40(L"Connect Attempt Fails   = %lu\n",param_1[6],param_3,param_4);
    FUN_00013a40(L"Reset Connections       = %lu\n",param_1[7],param_3,param_4);
    FUN_00013a40(L"Current Connections     = %lu\n",param_1[8],param_3,param_4);
    FUN_00013a40(L"Segments Received       = %lu\n",param_1[9],param_3,param_4);
    FUN_00013a40(L"Segments Sent           = %lu\n",param_1[10],param_3,param_4);
    FUN_00013a40(L"Segments Retransmitted  = %lu\n",param_1[0xb],param_3,param_4);
    FUN_00013a40(L"Errors Received         = %lu\n",param_1[0xc],param_3,param_4);
    FUN_00013a40(L"Sgmnts sent w/Reset Flag= %lu\n",param_1[0xd],param_3,param_4);
    FUN_00013a40(L"Cumulative Connections  = %lu\n",param_1[0xe],param_3,param_4);
    FUN_00013a40(L"Time-Out Algorithm      = %lu\n",*param_1,param_3,param_4);
    FUN_00013a40(L"Time-Out Minimim        = %lu\n",param_1[1],param_3,param_4);
    FUN_00013a40(L"Time-Out Maximum        = %lu\n",param_1[2],param_3,param_4);
    if (param_1[3] == -1) {
      FUN_00013a40(L"Maximum Connections     = Dynamic (-1)\n",0xffffffff,param_3,param_4);
    }
    else {
      FUN_00013a40(L"Maximum Connections     = %lu\n",param_1[3],param_3,param_4);
    }
  }
  return;
}



/* 00015238 FUN_00015238 */

/* Boundary evidence: original MIPS .pdata 00015238..000152fb. Semantic name remains unreviewed. */

void FUN_00015238(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  wchar_t *pwVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_00013a40(L"\n",param_2,param_3,param_4);
    if (param_2 == 2) {
      pwVar1 = L"UDP";
    }
    else {
      pwVar1 = L"UDP6";
    }
    FUN_00013a40(L"%s Statistics:\n",pwVar1,param_3,param_4);
    FUN_00013a40(L"--------------\n",pwVar1,param_3,param_4);
    FUN_00013a40(L"Datagrams Received  = %lu\n",*param_1,param_3,param_4);
    FUN_00013a40(L"No Ports            = %lu\n",param_1[1],param_3,param_4);
    FUN_00013a40(L"Receive Errors      = %lu\n",param_1[2],param_3,param_4);
    FUN_00013a40(L"Datagrams Sent      = %lu\n",param_1[3],param_3,param_4);
    FUN_00013a40(L"Number UDP entries  = %lu\n",param_1[4],param_3,param_4);
  }
  return;
}



/* 000152fc FUN_000152fc */

/* Boundary evidence: original MIPS .pdata 000152fc..000155eb. Semantic name remains unreviewed. */

void FUN_000152fc(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  u_short uVar1;
  char *pcVar2;
  undefined2 extraout_var;
  wchar_t *_Source;
  _struct_1227 in;
  _union_1226 *p_Var3;
  uint local_170;
  undefined1 auStack_148 [24];
  wchar_t awStack_130 [128];
  uint local_30;
  
  local_30 = DAT_000170b0;
  if (param_1 != (uint *)0x0) {
    FUN_00013a40(L"\n",param_2,param_3,param_4);
    FUN_00013a40(L"TCP TABLE\n",param_2,param_3,param_4);
    FUN_00013a40(L"%20s %10s %20s %10s %s\n",L"Loc Addr",L"Loc Port",L"Rem Addr");
    local_170 = 0;
    if (*param_1 != 0) {
      p_Var3 = (_union_1226 *)(param_1 + 4);
      do {
        _Source = L"CLOSED\n";
        switch(p_Var3[-3].S_addr) {
        case 1:
          break;
        case 2:
          _Source = L"LISTEN\n";
          break;
        case 3:
          _Source = L"SYN_SENT\n";
          break;
        case 4:
          _Source = L"SYN_RCVD\n";
          break;
        case 5:
          _Source = L"ESTAB\n";
          break;
        case 6:
          _Source = L"FIN_WAIT1\n";
          break;
        default:
          wprintf(L"Error: unknown state!");
          goto LAB_000154e8;
        case 8:
          _Source = L"CLOSE_WAIT\n";
          break;
        case 9:
          _Source = L"CLOSING\n";
          break;
        case 10:
          _Source = L"LAST_ACK\n";
          break;
        case 0xb:
          _Source = L"TIME_WAIT\n";
          break;
        case 0xc:
          _Source = L"DELETE\n";
        }
        wcscpy(awStack_130,_Source);
LAB_000154e8:
        pcVar2 = inet_ntoa((in_addr)p_Var3[-2].S_un_b);
        memcpy(auStack_148,pcVar2,0x14);
        uVar1 = p_Var3[-1].S_un_w.s_w1;
        in = p_Var3->S_un_b;
        ntohs(p_Var3[1].S_un_w.s_w1);
        pcVar2 = inet_ntoa((in_addr)in);
        uVar1 = ntohs(uVar1);
        FUN_00013a40(L"%20hs %10lu %20hs %10lu %s",auStack_148,CONCAT22(extraout_var,uVar1),pcVar2);
        p_Var3 = p_Var3 + 5;
        local_170 = local_170 + 1;
      } while (local_170 < *param_1);
    }
  }
  FUN_00015f64(local_30);
  return;
}



/* 000155ec FUN_000155ec */

/* Boundary evidence: original MIPS .pdata 000155ec..000156e7. Semantic name remains unreviewed. */

void FUN_000155ec(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  u_short uVar2;
  undefined2 extraout_var;
  char *pcVar3;
  _struct_1227 in;
  uint uVar4;
  
  if (param_1 != (uint *)0x0) {
    FUN_00013a40(L"\n",param_2,param_3,param_4);
    FUN_00013a40(L"UDP TABLE\n",param_2,param_3,param_4);
    FUN_00013a40(L"%20s %10s\n",L"Loc Addr",L"Loc Port",param_4);
    uVar4 = 0;
    puVar1 = param_1;
    if (*param_1 != 0) {
      do {
        in = ((_union_1226 *)(puVar1 + 1))->S_un_b;
        uVar2 = ntohs((u_short)puVar1[2]);
        pcVar3 = inet_ntoa((in_addr)in);
        FUN_00013a40(L"%20hs %10lu \n",pcVar3,CONCAT22(extraout_var,uVar2),param_4);
        uVar4 = uVar4 + 1;
        puVar1 = puVar1 + 2;
      } while (uVar4 < *param_1);
    }
  }
  return;
}



/* 000156e8 FUN_000156e8 */

void FUN_000156e8(int param_1,uint param_2,short *param_3)

{
  byte bVar1;
  ushort uVar2;
  short *psVar3;
  uint uVar4;
  
  uVar4 = 0;
  psVar3 = param_3;
  if (param_2 != 0) {
    do {
      bVar1 = *(byte *)(uVar4 + param_1) >> 4;
      if (bVar1 < 10) {
        *psVar3 = bVar1 + 0x30;
      }
      else {
        *psVar3 = bVar1 + 0x37;
      }
      uVar2 = *(byte *)(uVar4 + param_1) & 0xf;
      if (uVar2 < 10) {
        psVar3[1] = uVar2 + 0x30;
      }
      else {
        psVar3[1] = uVar2 + 0x37;
      }
      uVar4 = uVar4 + 1;
      psVar3 = psVar3 + 2;
    } while (uVar4 < param_2);
  }
  param_3[param_2 * 2] = 0;
  return;
}



/* 00015774 FUN_00015774 */

/* Boundary evidence: original MIPS .pdata 00015774..0001595f. Semantic name remains unreviewed. */

void FUN_00015774(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  short *psVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short asStack_38 [18];
  uint local_14;
  
  local_14 = DAT_000170b0;
  if (param_1 == 0) {
    FUN_00013a40(L"pIfRow is NULL. Hence Return",param_2,param_3,param_4);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x210);
    if (7 < uVar1) {
      uVar1 = 8;
    }
    psVar2 = asStack_38;
    FUN_000156e8(param_1 + 0x214,uVar1,psVar2);
    *(undefined1 *)(*(int *)(param_1 + 600) + param_1 + 0x25c) = 0;
    FUN_00013a40(L"\n",uVar1,psVar2,param_4);
    FUN_00013a40(L"%25s %10s %10s\n",L"Interface Statistics",L"Received",L"Sent");
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Bytes",*(undefined4 *)(param_1 + 0x228),
                 *(undefined4 *)(param_1 + 0x240));
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Unicast Packets",*(undefined4 *)(param_1 + 0x22c),
                 *(undefined4 *)(param_1 + 0x244));
    FUN_00013a40(L"%25s %10lu %10lu\n",L"NonUnicast Packets",*(undefined4 *)(param_1 + 0x230),
                 *(undefined4 *)(param_1 + 0x248));
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Discards",*(undefined4 *)(param_1 + 0x234),
                 *(undefined4 *)(param_1 + 0x24c));
    uVar4 = *(undefined4 *)(param_1 + 0x250);
    FUN_00013a40(L"%25s %10lu %10lu\n",L"Errors",*(undefined4 *)(param_1 + 0x238),uVar4);
    uVar3 = *(undefined4 *)(param_1 + 0x23c);
    FUN_00013a40(L"%25s %10lu \n",L"Unknown Protocols",uVar3,uVar4);
    FUN_00013a40(L" Name                  =%s\n",param_1,uVar3,uVar4);
    FUN_00013a40(L" Index                 =%lu \n",*(undefined4 *)(param_1 + 0x200),uVar3,uVar4);
    FUN_00013a40(L" Physical Addrress     =%s \n",asStack_38,uVar3,uVar4);
    FUN_00013a40(L" Description           =%hs\n",param_1 + 0x25c,uVar3,uVar4);
    FUN_00013a40(L" Type                  =%lu\n",*(undefined4 *)(param_1 + 0x204),uVar3,uVar4);
    FUN_00013a40(L" Mtu                   =%lu\n",*(undefined4 *)(param_1 + 0x208),uVar3,uVar4);
    FUN_00013a40(L" Speed - bps           =%lu \n",*(undefined4 *)(param_1 + 0x20c),uVar3,uVar4);
    FUN_00013a40(L" Administrative Status =%lu \n",*(undefined4 *)(param_1 + 0x21c),uVar3,uVar4);
    FUN_00013a40(L" Oprerational Status   =%lu\n",*(undefined4 *)(param_1 + 0x220),uVar3,uVar4);
    FUN_00013a40(L" Output Queue Length   =%lu \n",*(undefined4 *)(param_1 + 0x254),uVar3,uVar4);
  }
  FUN_00015f64(local_14);
  return;
}



/* 00015960 FUN_00015960 */

/* Boundary evidence: original MIPS .pdata 00015960..00015a77. Semantic name remains unreviewed. */

uint FUN_00015960(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  size_t *psVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint *_Dst;
  size_t local_18 [2];
  
  uVar3 = 1;
  psVar2 = local_18;
  local_18[0] = 0;
  _Dst = (uint *)0x0;
  DVar1 = GetIpAddrTable(0);
  if (DVar1 == 0x7a) {
    _Dst = malloc(local_18[0]);
    if (_Dst == (uint *)0x0) {
      FUN_00013a40(L"\n Insufficient Memory",psVar2,uVar3,param_4);
      FUN_00013850(1);
    }
    memset(_Dst,0,local_18[0]);
    DVar1 = GetIpAddrTable(_Dst,local_18,1);
  }
  if ((DVar1 == 0) && (_Dst != (uint *)0x0)) {
    uVar5 = 0;
    if (*_Dst != 0) {
      puVar4 = _Dst + 2;
      do {
        if (*puVar4 == param_1) {
          uVar5 = _Dst[uVar5 * 6 + 1];
          free(_Dst);
          return uVar5;
        }
        uVar5 = uVar5 + 1;
        puVar4 = puVar4 + 6;
      } while (uVar5 < *_Dst);
    }
    free(_Dst);
    uVar5 = 0;
  }
  else {
    FUN_00014a6c(DVar1);
    uVar5 = FUN_00013850(1);
  }
  return uVar5;
}



/* 00015a78 FUN_00015a78 */

/* Boundary evidence: original MIPS .pdata 00015a78..00015c23. Semantic name remains unreviewed. */

void FUN_00015a78(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  size_t *psVar2;
  undefined4 uVar3;
  undefined4 *_Memory;
  undefined4 *puVar4;
  uint uVar5;
  size_t local_30 [2];
  
  psVar2 = local_30;
  local_30[0] = 0;
  _Memory = (undefined4 *)0x0;
  DVar1 = GetAdaptersInfo(0);
  if (DVar1 == 0x6f) {
    _Memory = malloc(local_30[0]);
    if (_Memory == (undefined4 *)0x0) {
      FUN_00013a40(L"\n Insufficient Memory",psVar2,param_3,param_4);
      FUN_00013850(1);
    }
    psVar2 = local_30;
    DVar1 = GetAdaptersInfo(_Memory);
  }
  if (DVar1 != 0) {
    FUN_00014a6c(DVar1);
    FUN_00013850(1);
  }
  puVar4 = _Memory;
  if (local_30[0] == 0) {
    puVar4 = (undefined4 *)0x0;
  }
  FUN_00013a40(L"\n=============================================================================\n",
               psVar2,param_3,param_4);
  FUN_00013a40(L"\n Interface List ",psVar2,param_3,param_4);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_00013a40(L"\n\n No Interfaces Present.",psVar2,param_3,param_4);
  }
  else {
    do {
      uVar3 = puVar4[0x67];
      FUN_00013a40(L"\n %lu",uVar3,param_3,param_4);
      FUN_00013a40(L" \t ",uVar3,param_3,param_4);
      uVar5 = 0;
      if (puVar4[100] != 0) {
        do {
          FUN_00013a40(L" %x",(uint)*(byte *)((int)puVar4 + uVar5 + 0x194),param_3,param_4);
          uVar5 = uVar5 + 1;
        } while (uVar5 < (uint)puVar4[100]);
      }
      psVar2 = puVar4 + 0x43;
      FUN_00013a40(L"\t %hs",psVar2,param_3,param_4);
      puVar4 = (undefined4 *)*puVar4;
    } while (puVar4 != (undefined4 *)0x0);
  }
  FUN_00013a40(L"\n=============================================================================\n",
               psVar2,param_3,param_4);
  if (_Memory != (undefined4 *)0x0) {
    free(_Memory);
  }
  return;
}



/* 00015c24 FUN_00015c24 */

/* Boundary evidence: original MIPS .pdata 00015c24..00015df3. Semantic name remains unreviewed. */

void FUN_00015c24(void)

{
  DWORD DVar1;
  char *pcVar2;
  in_addr in;
  ULONG *pUVar3;
  size_t *psVar4;
  _union_1226 _Var5;
  undefined4 uVar6;
  undefined4 in_a3;
  ULONG *_Memory;
  _union_1226 *p_Var7;
  uint uVar8;
  size_t local_28 [2];
  
  uVar6 = 0;
  psVar4 = local_28;
  pUVar3 = (ULONG *)0x0;
  local_28[0] = 0;
  _Memory = (ULONG *)0x0;
  DVar1 = GetIpForwardTable();
  if (DVar1 == 0x7a) {
    _Memory = malloc(local_28[0]);
    if (_Memory == (ULONG *)0x0) {
      FUN_00013a40(L"\n Insufficient Memory",psVar4,uVar6,in_a3);
      FUN_00013850(1);
    }
    uVar6 = 0;
    psVar4 = local_28;
    pUVar3 = _Memory;
    DVar1 = GetIpForwardTable();
  }
  if (DVar1 != 0) {
    FUN_00014a6c(DVar1);
    pUVar3 = (ULONG *)0x1;
    FUN_00013850(1);
  }
  FUN_00015a78(pUVar3,psVar4,uVar6,in_a3);
  FUN_00013a40(L"\n=============================================================================",
               psVar4,uVar6,in_a3);
  FUN_00013a40(L"\n Active Routes \n ",psVar4,uVar6,in_a3);
  _Var5.S_addr = *_Memory;
  FUN_00013a40(L" \n The no. of entries is ::: %lu",_Var5,uVar6,in_a3);
  FUN_00013a40(L"\n      Destination       Netmask       GatewayAddress     Interface    Metric  ",
               _Var5,uVar6,in_a3);
  FUN_00013a40(L"\n ----------------------------------------------------------------------------",
               _Var5,uVar6,in_a3);
  uVar8 = 0;
  if (*_Memory != 0) {
    p_Var7 = (_union_1226 *)(_Memory + 4);
    do {
      pcVar2 = inet_ntoa((in_addr)p_Var7[-3].S_un_b);
      FUN_00013a40(L"\n%17hs",pcVar2,uVar6,in_a3);
      pcVar2 = inet_ntoa((in_addr)p_Var7[-2].S_un_b);
      FUN_00013a40(L"%17hs",pcVar2,uVar6,in_a3);
      pcVar2 = inet_ntoa((in_addr)p_Var7->S_un_b);
      FUN_00013a40(L"%17hs",pcVar2,uVar6,in_a3);
      in.S_un = (_union_1226)FUN_00015960(p_Var7[1].S_addr,pcVar2,uVar6,in_a3);
      pcVar2 = inet_ntoa(in);
      FUN_00013a40(L"%17hs",pcVar2,uVar6,in_a3);
      _Var5 = p_Var7[6];
      FUN_00013a40(L"%8lu",_Var5,uVar6,in_a3);
      uVar8 = uVar8 + 1;
      p_Var7 = p_Var7 + 0xe;
    } while (uVar8 < *_Memory);
  }
  FUN_00013a40(L"\n=============================================================================\n",
               _Var5,uVar6,in_a3);
  free(_Memory);
  return;
}



/* 00015ee4 FUN_00015ee4 */

/* Boundary evidence: original MIPS .pdata 00015ee4..00015f37. Semantic name remains unreviewed. */

void FUN_00015ee4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00015f64(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00015f38 FUN_00015f38 */

/* Boundary evidence: original MIPS .pdata 00015f38..00015f63. Semantic name remains unreviewed. */

undefined4 FUN_00015f38(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00015ee4(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00015f64 FUN_00015f64 */

/* Boundary evidence: original MIPS .pdata 00015f64..00015fab. Semantic name remains unreviewed. */

void FUN_00015f64(uint param_1)

{
  if ((param_1 == DAT_000170b0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


