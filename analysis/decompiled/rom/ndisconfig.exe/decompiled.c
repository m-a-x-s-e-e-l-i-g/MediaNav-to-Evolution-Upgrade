/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011b34 FUN_00011b34 */

/* Boundary evidence: original MIPS .pdata 00011b34..00011bc7. Semantic name remains unreviewed. */

void FUN_00011b34(undefined4 param_1,undefined4 param_2,wint_t *param_3,undefined4 param_4)

{
  UINT UVar1;
  
  FUN_00011e44();
  UVar1 = FUN_000132c0(param_1,param_2,param_3,param_4);
  FUN_00011d84(UVar1);
  FUN_00011da4(UVar1);
  return;
}



/* 00011bc8 FUN_00011bc8 */

/* Boundary evidence: original MIPS .pdata 00011bc8..00011c07. Semantic name remains unreviewed. */

void FUN_00011bc8(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00011c08 entry */

/* Boundary evidence: original MIPS .pdata 00011c08..00011c63. Semantic name remains unreviewed. */

void entry(undefined4 param_1,undefined4 param_2,wint_t *param_3,undefined4 param_4)

{
  FUN_00011e80();
  FUN_00011b34(param_1,param_2,param_3,param_4);
  return;
}



/* 00011c64 FUN_00011c64 */

/* Boundary evidence: original MIPS .pdata 00011c64..00011d83. Semantic name remains unreviewed. */

void FUN_00011c64(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00014194 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000141d4;
    if (DAT_000141d4 != (undefined4 *)0x0) {
      while (DAT_000141d0 = DAT_000141d0 + -1, _Memory <= DAT_000141d0) {
        if ((code *)*DAT_000141d0 != (code *)0x0) {
          (*(code *)*DAT_000141d0)();
          _Memory = DAT_000141d4;
        }
      }
      free(_Memory);
      DAT_000141d0 = (undefined4 *)0x0;
      DAT_000141d4 = (undefined4 *)0x0;
    }
    FUN_00011df0((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00011df0((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_000141d8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011d84 FUN_00011d84 */

/* Boundary evidence: original MIPS .pdata 00011d84..00011da3. Semantic name remains unreviewed. */

void FUN_00011d84(UINT param_1)

{
  FUN_00011c64(param_1,0,0);
  return;
}



/* 00011da4 FUN_00011da4 */

/* Boundary evidence: original MIPS .pdata 00011da4..00011def. Semantic name remains unreviewed. */

void FUN_00011da4(UINT param_1)

{
  DAT_00014194 = 0;
  FUN_00011df0((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00011df0 FUN_00011df0 */

/* Boundary evidence: original MIPS .pdata 00011df0..00011e43. Semantic name remains unreviewed. */

void FUN_00011df0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00011e44 FUN_00011e44 */

/* Boundary evidence: original MIPS .pdata 00011e44..00011e7f. Semantic name remains unreviewed. */

void FUN_00011e44(void)

{
  FUN_00011df0((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00011df0((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00011e80 FUN_00011e80 */

/* Boundary evidence: original MIPS .pdata 00011e80..00011ef3. Semantic name remains unreviewed. */

void FUN_00011e80(void)

{
  uint uVar1;
  
  if ((DAT_00014068 == 0) || (DAT_00014068 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00014068 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00014068 == 0) {
      DAT_00014068 = 0xb064;
    }
  }
  DAT_0001406c = ~DAT_00014068;
  return;
}



/* 00011f64 FUN_00011f64 */

/* Boundary evidence: original MIPS .pdata 00011f64..0001206f. Semantic name remains unreviewed. */

void FUN_00011f64(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00014068;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  StringCchVPrintfW(awStack_218,0x100,param_1,(va_list)&local_res4);
  if (DAT_00014070 == 0) {
    OutputDebugStringW(awStack_218);
    OutputDebugStringW(L"\n");
  }
  else {
    if (DAT_000141cc == (code *)0x0) {
      DAT_000141c8 = LoadLibraryW(L"coredll.dll");
      if (DAT_000141c8 != (HMODULE)0x0) {
        DAT_000141cc = (code *)GetProcAddressW(DAT_000141c8,L"wprintf");
      }
      if (DAT_000141cc == (code *)0x0) {
        DAT_00014070 = 0;
        goto LAB_00012054;
      }
    }
    (*DAT_000141cc)(&UNK_000110f8,awStack_218);
    (*DAT_000141cc)(&UNK_000110f0,awStack_218);
  }
LAB_00012054:
  FUN_00013498(local_18);
  return;
}



/* 00012070 FUN_00012070 */

/* Boundary evidence: original MIPS .pdata 00012070..000120cf. Semantic name remains unreviewed. */

wchar_t * FUN_00012070(wchar_t *param_1)

{
  wchar_t wVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  wchar_t *_Str;
  
  wVar1 = *param_1;
  _Str = param_1;
  while (wVar1 != L'\0') {
    sVar2 = wcslen(_Str);
    pwVar3 = _Str + sVar2;
    _Str = pwVar3 + 1;
    *pwVar3 = L' ';
    wVar1 = *_Str;
  }
  return param_1;
}



/* 000120d0 FUN_000120d0 */

/* Boundary evidence: original MIPS .pdata 000120d0..0001218b. Semantic name remains unreviewed. */

void FUN_000120d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00011f64(L"Usage: ndisconfig [-d]  [Parameters]\n",param_2,param_3,param_4);
  FUN_00011f64(L"Parameters:",param_2,param_3,param_4);
  FUN_00011f64(L"            adapter  add    <miniportName> <adapterName>",param_2,param_3,param_4);
  FUN_00011f64(L"            adapter  del    <adapterName>",param_2,param_3,param_4);
  FUN_00011f64(L"            adapter  rebind <adapterName> [<protocolName>]",param_2,param_3,param_4
              );
  FUN_00011f64(L"            adapter  bind   <adapterName> [<protocolName>]",param_2,param_3,param_4
              );
  FUN_00011f64(L"            adapter  unbind <adapterName> [<protocolName>]",param_2,param_3,param_4
              );
  FUN_00011f64(L"            miniport add    <miniportName>",param_2,param_3,param_4);
  FUN_00011f64(L"            protocol",param_2,param_3,param_4);
  FUN_00011f64(L"            binding",param_2,param_3,param_4);
  FUN_00011f64(L"            resume",param_2,param_3,param_4);
  FUN_00011f64(L"            power",param_2,param_3,param_4);
  FUN_00011f64(L"            power    set    <adapterName> <power state> [Example: power set NE20001 D4]"
               ,param_2,param_3,param_4);
  FUN_00011f64(L"\n",param_2,param_3,param_4);
  return;
}



/* 0001218c FUN_0001218c */

/* Boundary evidence: original MIPS .pdata 0001218c..00012243. Semantic name remains unreviewed. */

undefined4 FUN_0001218c(wchar_t *param_1,wchar_t *param_2,undefined4 *param_3,undefined4 param_4)

{
  wchar_t *pwVar1;
  int iVar2;
  wchar_t *_Str2;
  undefined4 *puVar3;
  wchar_t *pwVar4;
  wchar_t *_Str1;
  
  _Str2 = param_2;
  puVar3 = param_3;
  if (*(wchar_t **)param_1 != (wchar_t *)0x0) {
    _Str1 = (wchar_t *)*param_3;
    pwVar1 = *(wchar_t **)param_1;
    pwVar4 = param_1;
    do {
      _Str2 = pwVar1;
      param_1 = _Str1;
      iVar2 = wcscmp(_Str1,_Str2);
      if (((iVar2 == 0) && (*(int *)(pwVar4 + 4) <= (int)param_2 + -1)) &&
         ((int)param_2 + -1 <= *(int *)(pwVar4 + 6))) {
        (**(code **)(pwVar4 + 2))((int)param_2 + -1,param_3 + 1);
        return 1;
      }
      pwVar4 = pwVar4 + 8;
      pwVar1 = *(wchar_t **)pwVar4;
    } while (*(wchar_t **)pwVar4 != (wchar_t *)0x0);
  }
  FUN_000120d0(param_1,_Str2,puVar3,param_4);
  return 0;
}



/* 00012244 FUN_00012244 */

/* Boundary evidence: original MIPS .pdata 00012244..000123ab. Semantic name remains unreviewed. */

BOOL FUN_00012244(DWORD param_1,LPVOID param_2,DWORD param_3,LPVOID param_4,DWORD *param_5)

{
  HANDLE hDevice;
  DWORD DVar1;
  undefined4 uVar2;
  BOOL BVar3;
  DWORD local_28 [2];
  
  uVar2 = 0;
  BVar3 = 0;
  hDevice = CreateFileW(L"NDS0:",0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,4,0,(HANDLE)0x0);
  if (hDevice == (HANDLE)0xffffffff) {
    DVar1 = GetLastError();
    FUN_00011f64(L"CreateFile of \'%s\' failed, error=%d",L"NDS0:",DVar1,uVar2);
  }
  else {
    local_28[0] = 0;
    if (param_5 != (DWORD *)0x0) {
      local_28[0] = *param_5;
    }
    BVar3 = DeviceIoControl(hDevice,param_1,param_2,param_3,param_4,local_28[0],local_28,
                            (LPOVERLAPPED)0x0);
    if ((DAT_00014198 != 0) || (BVar3 == 0)) {
      FUN_00011f64(L"IoControl result=%d",BVar3,param_2,param_3);
    }
    if (param_5 != (DWORD *)0x0) {
      *param_5 = local_28[0];
    }
    CloseHandle(hDevice);
  }
  return BVar3;
}



/* 000123ac FUN_000123ac */

/* Boundary evidence: original MIPS .pdata 000123ac..000124c3. Semantic name remains unreviewed. */

void FUN_000123ac(DWORD param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  undefined4 *puVar2;
  wchar_t *_Dest;
  wchar_t *_Str;
  DWORD local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t awStack_230 [260];
  uint local_28 [2];
  
  local_28[0] = DAT_00014068;
  _Dest = awStack_230;
  puVar2 = (undefined4 *)register0x00000074;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  do {
    puVar2 = puVar2 + 1;
    _Str = (wchar_t *)*puVar2;
    if (_Str == (wchar_t *)0x0) {
      *_Dest = L'\0';
      FUN_00012244(param_1,awStack_230,((int)_Dest + (2 - (int)awStack_230) >> 1) << 1,(LPVOID)0x0,
                   (DWORD *)0x0);
LAB_00012498:
      FUN_00013498(local_28[0]);
      return;
    }
    sVar1 = wcslen(_Str);
    if (local_28 <= _Dest + sVar1 + 1) {
      FUN_00011f64(L"Combined string length > buffer space %u",0x104,param_3,param_4);
      goto LAB_00012498;
    }
    wcscpy(_Dest,_Str);
    _Dest = _Dest + sVar1 + 1;
  } while( true );
}



/* 000124c4 FUN_000124c4 */

/* Boundary evidence: original MIPS .pdata 000124c4..0001251b. Semantic name remains unreviewed. */

void FUN_000124c4(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_00014198 != 0) {
    FUN_00011f64(L"Registering miniport %s, adapter %s",*param_2,param_2[1],param_4);
  }
  FUN_000123ac(0x170026,*param_2,param_2[1],0);
  return;
}



/* 0001251c FUN_0001251c */

/* Boundary evidence: original MIPS .pdata 0001251c..0001256b. Semantic name remains unreviewed. */

void FUN_0001251c(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_00014198 != 0) {
    FUN_00011f64(L"Deregistering adapter %s",*param_2,param_3,param_4);
  }
  FUN_000123ac(0x17002a,*param_2,0,param_4);
  return;
}



/* 0001256c FUN_0001256c */

/* Boundary evidence: original MIPS .pdata 0001256c..000125d7. Semantic name remains unreviewed. */

void FUN_0001256c(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (DAT_00014198 != 0) {
    FUN_00011f64(L"Rebinding adapter %s",*param_2,param_3,param_4);
  }
  uVar1 = 0;
  if (param_1 == 2) {
    uVar1 = param_2[1];
  }
  FUN_000123ac(0x17002e,*param_2,uVar1,0);
  return;
}



/* 000125d8 FUN_000125d8 */

/* Boundary evidence: original MIPS .pdata 000125d8..00012643. Semantic name remains unreviewed. */

void FUN_000125d8(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (DAT_00014198 != 0) {
    FUN_00011f64(L"Binding adapter %s",*param_2,param_3,param_4);
  }
  uVar1 = 0;
  if (param_1 == 2) {
    uVar1 = param_2[1];
  }
  FUN_000123ac(0x170032,*param_2,uVar1,0);
  return;
}



/* 00012644 FUN_00012644 */

/* Boundary evidence: original MIPS .pdata 00012644..000126af. Semantic name remains unreviewed. */

void FUN_00012644(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (DAT_00014198 != 0) {
    FUN_00011f64(L"Unbinding adapter %s",*param_2,param_3,param_4);
  }
  uVar1 = 0;
  if (param_1 == 2) {
    uVar1 = param_2[1];
  }
  FUN_000123ac(0x170036,*param_2,uVar1,0);
  return;
}



/* 000126b0 FUN_000126b0 */

int FUN_000126b0(uint param_1)

{
  int iVar1;
  
  if (param_1 < 10) {
    iVar1 = param_1 + 0x30;
  }
  else {
    if (0xf < param_1) {
      return 0x3f;
    }
    iVar1 = param_1 + 0x37;
  }
  return iVar1 * 0x1000000 >> 0x18;
}



/* 000126f4 FUN_000126f4 */

/* Boundary evidence: original MIPS .pdata 000126f4..0001290f. Semantic name remains unreviewed. */

void FUN_000126f4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte abStack_130 [256];
  uint local_30;
  
  local_30 = DAT_00014068;
  uVar7 = 0;
  if (param_2 != 0) {
    do {
      uVar3 = uVar7;
      sprintf((char *)abStack_130,"%04X ");
      uVar6 = 0;
      iVar2 = 5;
      do {
        iVar5 = iVar2;
        if (uVar6 + uVar7 < param_2) {
          bVar1 = *(byte *)(param_1 + uVar6);
          iVar2 = FUN_000126b0((uint)(bVar1 >> 4));
          abStack_130[iVar5] = (byte)iVar2;
          iVar2 = FUN_000126b0(bVar1 & 0xf);
          abStack_130[iVar5 + 1] = (byte)iVar2;
        }
        else {
          abStack_130[iVar5] = 0x20;
          abStack_130[iVar5 + 1] = 0x20;
        }
        if (uVar6 == 7) {
          abStack_130[iVar5 + 2] = 0x2d;
        }
        else {
          abStack_130[iVar5 + 2] = 0x20;
        }
        uVar6 = uVar6 + 1;
        iVar2 = iVar5 + 3;
      } while (uVar6 < 0x10);
      pbVar4 = abStack_130 + iVar5 + 3;
      do {
        *pbVar4 = 0x20;
        pbVar4 = pbVar4 + 1;
      } while (pbVar4 != abStack_130 + iVar5 + 5);
      uVar6 = 0;
      iVar2 = iVar5 + 5;
      do {
        iVar5 = iVar2;
        if (uVar6 + uVar7 < param_2) {
          bVar1 = *(byte *)(param_1 + uVar6);
          if ((bVar1 < 0x20) || (0x7e < bVar1)) {
            abStack_130[iVar5] = 0x2e;
          }
          else {
            abStack_130[iVar5] = bVar1;
          }
        }
        else {
          abStack_130[iVar5] = 0x20;
        }
        uVar6 = uVar6 + 1;
        iVar2 = iVar5 + 1;
      } while (uVar6 < 0x10);
      abStack_130[iVar5 + 1] = 0;
      FUN_00011f64(L"%hs",abStack_130,uVar3,param_4);
      uVar7 = uVar7 + 0x10;
      param_1 = param_1 + 0x10;
    } while (uVar7 < param_2);
  }
  FUN_00013498(local_30);
  return;
}



/* 00012910 FUN_00012910 */

/* Boundary evidence: original MIPS .pdata 00012910..000129e7. Semantic name remains unreviewed. */

void FUN_00012910(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  uint uVar2;
  DWORD DVar3;
  undefined1 *puVar4;
  wchar_t *_Str;
  DWORD local_120 [2];
  undefined1 auStack_118 [256];
  uint local_18;
  
  local_18 = DAT_00014068;
  _Str = (wchar_t *)*param_2;
  FUN_00011f64(L"Log for adapter %s",_Str,param_3,param_4);
  local_120[0] = 0x100;
  sVar1 = wcslen(_Str);
  DVar3 = (sVar1 + 1) * 2;
  puVar4 = auStack_118;
  uVar2 = FUN_00012244(0x17001e,_Str,DVar3,puVar4,local_120);
  while ((uVar2 & 0xff) != 0) {
    FUN_000126f4((int)auStack_118,local_120[0],DVar3,puVar4);
    local_120[0] = 0x100;
    sVar1 = wcslen(_Str);
    DVar3 = (sVar1 + 1) * 2;
    puVar4 = auStack_118;
    uVar2 = FUN_00012244(0x17001e,_Str,DVar3,puVar4,local_120);
  }
  FUN_00013498(local_18);
  return;
}



/* 000129e8 FUN_000129e8 */

/* Boundary evidence: original MIPS .pdata 000129e8..00012a57. Semantic name remains unreviewed. */

void FUN_000129e8(void)

{
  BOOL BVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  DWORD local_218 [2];
  wchar_t awStack_210 [256];
  uint local_10;
  
  local_10 = DAT_00014068;
  pwVar4 = awStack_210;
  uVar3 = 0;
  local_218[0] = 0x200;
  BVar1 = FUN_00012244(0x17003a,(LPVOID)0x0,0,pwVar4,local_218);
  if (BVar1 != 0) {
    pwVar2 = FUN_00012070(awStack_210);
    FUN_00011f64(L"Adapters: %s",pwVar2,uVar3,pwVar4);
  }
  FUN_00013498(local_10);
  return;
}



/* 00012a58 FUN_00012a58 */

/* Boundary evidence: original MIPS .pdata 00012a58..00012a97. Semantic name remains unreviewed. */

void FUN_00012a58(wchar_t *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == (undefined4 *)0x0) {
    FUN_000129e8();
  }
  else {
    FUN_0001218c((wchar_t *)&PTR_DAT_00014074,param_1,param_2,param_4);
  }
  return;
}



/* 00012a98 FUN_00012a98 */

/* Boundary evidence: original MIPS .pdata 00012a98..00012ae7. Semantic name remains unreviewed. */

void FUN_00012a98(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_00014198 != 0) {
    FUN_00011f64(L"Registering miniport %s",*param_2,param_3,param_4);
  }
  FUN_000123ac(0x170046,*param_2,0,param_4);
  return;
}



/* 00012ae8 FUN_00012ae8 */

/* Boundary evidence: original MIPS .pdata 00012ae8..00012b17. Semantic name remains unreviewed. */

void FUN_00012ae8(wchar_t *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 != (undefined4 *)0x0) {
    FUN_0001218c((wchar_t *)&PTR_DAT_000140e4,param_1,param_2,param_4);
  }
  return;
}



/* 00012b18 FUN_00012b18 */

/* Boundary evidence: original MIPS .pdata 00012b18..00012b87. Semantic name remains unreviewed. */

void FUN_00012b18(void)

{
  BOOL BVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  DWORD local_218 [2];
  wchar_t awStack_210 [256];
  uint local_10;
  
  local_10 = DAT_00014068;
  pwVar4 = awStack_210;
  uVar3 = 0;
  local_218[0] = 0x200;
  BVar1 = FUN_00012244(0x17003e,(LPVOID)0x0,0,pwVar4,local_218);
  if (BVar1 != 0) {
    pwVar2 = FUN_00012070(awStack_210);
    FUN_00011f64(L"Protocols: %s",pwVar2,uVar3,pwVar4);
  }
  FUN_00013498(local_10);
  return;
}



/* 00012b88 FUN_00012b88 */

/* Boundary evidence: original MIPS .pdata 00012b88..00012bc7. Semantic name remains unreviewed. */

void FUN_00012b88(wchar_t *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == (undefined4 *)0x0) {
    FUN_00012b18();
  }
  else {
    FUN_0001218c((wchar_t *)&DAT_000141a8,param_1,param_2,param_4);
  }
  return;
}



/* 00012bc8 FUN_00012bc8 */

/* Boundary evidence: original MIPS .pdata 00012bc8..00012c53. Semantic name remains unreviewed. */

void FUN_00012bc8(wchar_t *param_1)

{
  size_t sVar1;
  BOOL BVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  DWORD local_218 [2];
  wchar_t awStack_210 [256];
  uint local_10;
  
  local_10 = DAT_00014068;
  local_218[0] = 0x200;
  sVar1 = wcslen(param_1);
  pwVar4 = awStack_210;
  BVar2 = FUN_00012244(0x170042,param_1,(sVar1 + 1) * 2,pwVar4,local_218);
  if (BVar2 != 0) {
    pwVar3 = FUN_00012070(awStack_210);
    FUN_00011f64(L"%12s %s",param_1,pwVar3,pwVar4);
  }
  FUN_00013498(local_10);
  return;
}



/* 00012c54 FUN_00012c54 */

/* Boundary evidence: original MIPS .pdata 00012c54..00012d1f. Semantic name remains unreviewed. */

void FUN_00012c54(void)

{
  BOOL BVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  DWORD local_218 [2];
  wchar_t local_210 [256];
  uint local_10;
  
  local_10 = DAT_00014068;
  pwVar3 = local_210;
  local_218[0] = 0x200;
  BVar1 = FUN_00012244(0x17003a,(LPVOID)0x0,0,pwVar3,local_218);
  if (BVar1 != 0) {
    FUN_00011f64(L"%12s %s",L"Adapter",L"Bindings",pwVar3);
    FUN_00011f64(L"%12s %s",L"-------",L"--------",pwVar3);
    pwVar3 = local_210;
    while (local_210[0] != L'\0') {
      FUN_00012bc8(pwVar3);
      sVar2 = wcslen(pwVar3);
      pwVar3 = pwVar3 + sVar2 + 1;
      local_210[0] = *pwVar3;
    }
  }
  FUN_00013498(local_10);
  return;
}



/* 00012d20 FUN_00012d20 */

/* Boundary evidence: original MIPS .pdata 00012d20..00012d5f. Semantic name remains unreviewed. */

void FUN_00012d20(wchar_t *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == (undefined4 *)0x0) {
    FUN_00012c54();
  }
  else {
    FUN_0001218c((wchar_t *)&DAT_000141b8,param_1,param_2,param_4);
  }
  return;
}



/* 00012d60 FUN_00012d60 */

/* Boundary evidence: original MIPS .pdata 00012d60..00012d8f. Semantic name remains unreviewed. */

void FUN_00012d60(void)

{
  FUN_00012244(0x170022,(LPVOID)0x0,0,(LPVOID)0x0,(DWORD *)0x0);
  return;
}



/* 00012d90 FUN_00012d90 */

/* Boundary evidence: original MIPS .pdata 00012d90..00012eb7. Semantic name remains unreviewed. */

void FUN_00012d90(undefined4 param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  int local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_00014068;
  pwVar2 = L"{98C5250D-C29A-4985-AE5F-AFE5367E5006}";
  local_228[0] = -1;
  StringCchPrintfW(awStack_220,0x104,L"%s\\%s",L"{98C5250D-C29A-4985-AE5F-AFE5367E5006}",param_1);
  (*DAT_000141a0)(awStack_220,1,local_228);
  if (local_228[0] == -1) {
    pwVar1 = L"[Not power managed]";
  }
  else if (local_228[0] == 0) {
    pwVar1 = L"D0";
  }
  else if (local_228[0] == 1) {
    pwVar1 = L"D1";
  }
  else if (local_228[0] == 2) {
    pwVar1 = L"D2";
  }
  else if (local_228[0] == 3) {
    pwVar1 = L"D3";
  }
  else if (local_228[0] == 4) {
    pwVar1 = L"D4";
  }
  else {
    pwVar1 = L"Unknown";
  }
  FUN_00011f64(L"%12s   %s",param_1,pwVar1,pwVar2);
  FUN_00013498(local_18);
  return;
}



/* 00012eb8 FUN_00012eb8 */

/* Boundary evidence: original MIPS .pdata 00012eb8..00012f37. Semantic name remains unreviewed. */

void FUN_00012eb8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_00014068;
  pwVar3 = L"{98C5250D-C29A-4985-AE5F-AFE5367E5006}";
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"{98C5250D-C29A-4985-AE5F-AFE5367E5006}",param_1);
  uVar2 = 1;
  iVar1 = (*DAT_000141a4)(awStack_218);
  if (iVar1 != 0) {
    FUN_00011f64(L"Failed calling SetDevicePower().\r\n",uVar2,param_2,pwVar3);
  }
  FUN_00013498(local_10);
  return;
}



/* 00012f38 FUN_00012f38 */

/* Boundary evidence: original MIPS .pdata 00012f38..00013003. Semantic name remains unreviewed. */

void FUN_00012f38(void)

{
  BOOL BVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  DWORD local_218 [2];
  wchar_t local_210 [256];
  uint local_10;
  
  local_10 = DAT_00014068;
  pwVar3 = local_210;
  local_218[0] = 0x200;
  BVar1 = FUN_00012244(0x17003a,(LPVOID)0x0,0,pwVar3,local_218);
  if (BVar1 != 0) {
    FUN_00011f64(L"%12s    %s",L"Adapter",L"Power State",pwVar3);
    FUN_00011f64(L"%12s    %s",L"-------",L"-----------",pwVar3);
    pwVar3 = local_210;
    while (local_210[0] != L'\0') {
      FUN_00012d90(pwVar3);
      sVar2 = wcslen(pwVar3);
      pwVar3 = pwVar3 + sVar2 + 1;
      local_210[0] = *pwVar3;
    }
  }
  FUN_00013498(local_10);
  return;
}



/* 00013004 FUN_00013004 */

/* Boundary evidence: original MIPS .pdata 00013004..0001310f. Semantic name remains unreviewed. */

void FUN_00013004(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  wchar_t *_Str2;
  wchar_t *_Str1;
  int iVar2;
  undefined *local_40 [7];
  undefined4 local_24;
  undefined *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  _Str1 = L"D0";
  local_40[2] = &DAT_00011a1c;
  local_40[4] = &DAT_00011a14;
  local_40[3] = (undefined *)0x1;
  local_40[0] = &DAT_00011a24;
  local_40[1] = (undefined *)0x0;
  local_40[5] = (undefined *)0x2;
  local_40[6] = &DAT_00011a0c;
  iVar2 = 0;
  local_24 = 3;
  local_20 = &DAT_00011a04;
  local_1c = 4;
  local_18 = 0;
  local_14 = 0xffffffff;
  do {
    _Str2 = (wchar_t *)param_2[1];
    iVar1 = _wcsicmp(_Str1,_Str2);
    if (iVar1 == 0) {
      _Str2 = (wchar_t *)local_40[iVar2 * 2 + 1];
      if (_Str2 != (wchar_t *)0xffffffff) {
        FUN_00012eb8(*param_2,_Str2);
        FUN_00012f38();
        return;
      }
      break;
    }
    iVar2 = iVar2 + 1;
    _Str1 = (wchar_t *)local_40[iVar2 * 2];
  } while (_Str1 != (wchar_t *)0x0);
  FUN_00011f64(L"Error: Invalid power state, must be one of D0, D1, D2, D3, D4",_Str2,param_3,
               param_4);
  return;
}



/* 00013110 FUN_00013110 */

/* Boundary evidence: original MIPS .pdata 00013110..000131f7. Semantic name remains unreviewed. */

void FUN_00013110(wchar_t *param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4)

{
  wchar_t *pwVar1;
  
  pwVar1 = param_2;
  DAT_0001419c = LoadLibraryW(L"coredll.dll");
  if (DAT_0001419c != (HMODULE)0x0) {
    pwVar1 = L"GetDevicePower";
    DAT_000141a0 = GetProcAddressW(DAT_0001419c);
    if (DAT_000141a0 != 0) {
      pwVar1 = L"SetDevicePower";
      DAT_000141a4 = GetProcAddressW(DAT_0001419c);
      if (DAT_000141a4 != 0) {
        if (param_1 == (wchar_t *)0x0) {
          FUN_00012f38();
        }
        else {
          FUN_0001218c((wchar_t *)&PTR_LAB_00014104,param_1,(undefined4 *)param_2,param_4);
        }
        FreeLibrary(DAT_0001419c);
        return;
      }
    }
  }
  FUN_00011f64(L"Error: The Operating System may not support power management functions.",pwVar1,
               param_3,param_4);
  return;
}



/* 000131f8 FUN_000131f8 */

/* Boundary evidence: original MIPS .pdata 000131f8..000132bf. Semantic name remains unreviewed. */

undefined4 FUN_000131f8(wchar_t *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  wchar_t *pwVar2;
  undefined4 *puVar3;
  
  pwVar2 = param_1;
  for (puVar3 = (undefined4 *)(param_2 + 4);
      (pwVar2 = (wchar_t *)((int)pwVar2 + -1), pwVar2 != (wchar_t *)0x0 &&
      (*(short *)*puVar3 == 0x2d)); puVar3 = puVar3 + 1) {
    sVar1 = ((short *)*puVar3)[1];
    if (sVar1 == 100) {
      DAT_00014070 = 0;
    }
    else {
      if (sVar1 != 0x76) {
        FUN_000120d0(param_1,param_2,puVar3,param_4);
        return 0;
      }
      DAT_00014198 = 1;
    }
  }
  if (pwVar2 == (wchar_t *)0x0) {
    FUN_00012b18();
    FUN_000129e8();
    FUN_00012c54();
  }
  else {
    FUN_0001218c((wchar_t *)&PTR_u_adapter_00014124,pwVar2,puVar3,param_4);
  }
  return 0;
}



/* 000132c0 FUN_000132c0 */

/* Boundary evidence: original MIPS .pdata 000132c0..00013417. Semantic name remains unreviewed. */

undefined4 FUN_000132c0(undefined4 param_1,undefined4 param_2,wint_t *param_3,undefined4 param_4)

{
  wint_t wVar1;
  wint_t wVar2;
  int iVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  undefined4 *puVar6;
  wchar_t *pwVar7;
  int iVar8;
  wchar_t *local_60;
  undefined4 local_5c [15];
  
  uVar4 = 0x3c;
  local_60 = L"???.EXE";
  memset(local_5c,0,0x3c);
  pwVar7 = (wchar_t *)0x1;
  pwVar5 = (wchar_t *)0x2;
  puVar6 = local_5c;
  iVar8 = 0xf;
  do {
    while ((*param_3 != 0 && (iVar3 = iswctype(*param_3,8), iVar3 != 0))) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    wVar1 = *param_3;
    if (wVar1 == 0x22) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *puVar6 = param_3;
    if (*param_3 != 0) {
      pwVar7 = pwVar5;
    }
    wVar2 = *param_3;
    while (wVar2 != 0) {
      if (wVar1 != 0x22) {
        if (*param_3 == 0x22) break;
        iVar3 = iswctype(*param_3,8);
        if (iVar3 != 0) goto LAB_00013394;
      }
      else if (*param_3 == 0x22) {
LAB_00013394:
        *param_3 = 0;
        param_3 = param_3 + 1;
        break;
      }
      param_3 = param_3 + 1;
      wVar2 = *param_3;
    }
    puVar6 = puVar6 + 1;
    iVar8 = iVar8 + -1;
    pwVar5 = (wchar_t *)((int)pwVar5 + 1);
    if (iVar8 == 0) {
      FUN_000131f8(pwVar7,(int)&local_60,uVar4,param_4);
      return 0;
    }
  } while( true );
}



/* 00013418 FUN_00013418 */

/* Boundary evidence: original MIPS .pdata 00013418..0001346b. Semantic name remains unreviewed. */

void FUN_00013418(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00013498(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0001346c FUN_0001346c */

/* Boundary evidence: original MIPS .pdata 0001346c..00013497. Semantic name remains unreviewed. */

undefined4 FUN_0001346c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00013418(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00013498 FUN_00013498 */

/* Boundary evidence: original MIPS .pdata 00013498..000134df. Semantic name remains unreviewed. */

void FUN_00013498(uint param_1)

{
  if ((param_1 == DAT_00014068) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


