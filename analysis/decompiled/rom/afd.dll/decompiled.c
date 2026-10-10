/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0511fb4 FUN_c0511fb4 */

/* Boundary evidence: original MIPS .pdata c0511fb4..c051201f. Semantic name remains unreviewed. */

void * FUN_c0511fb4(uint param_1)

{
  void *_Dst;
  
  if (param_1 < 0x20001) {
    _Dst = (void *)CTEAllocMem(param_1);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,param_1);
    }
  }
  else {
    _Dst = (void *)0x0;
  }
  return _Dst;
}



/* c0512028 FUN_c0512028 */

/* Boundary evidence: original MIPS .pdata c0512028..c05120fb. Semantic name remains unreviewed. */

undefined4 FUN_c0512028(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x10);
  if (*(uint *)(param_1 + 0x10) <= param_2) {
    uVar2 = param_2;
  }
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = (*(code *)PTR_FUN_c052e2cc)(uVar2,DAT_c052e448);
    *(uint *)(param_1 + 8) = uVar2;
  }
  else {
    if (param_2 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc))) goto LAB_c05120cc;
    iVar1 = (*(code *)PTR_FUN_c052e2d4)
                      (*(int *)(param_1 + 4),*(int *)(param_1 + 8) + uVar2,DAT_c052e448);
    if (iVar1 == 0) {
      return 0;
    }
    *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar2;
  }
  *(int *)(param_1 + 4) = iVar1;
LAB_c05120cc:
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    return 0;
  }
  return 1;
}



/* c05120fc FUN_c05120fc */

/* Boundary evidence: original MIPS .pdata c05120fc..c051214b. Semantic name remains unreviewed. */

void FUN_c05120fc(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* c051214c FUN_c051214c */

/* Boundary evidence: original MIPS .pdata c051214c..c05121a7. Semantic name remains unreviewed. */

undefined4 FUN_c051214c(undefined4 *param_1,LPCWSTR param_2,LPBYTE param_3,int param_4)

{
  LSTATUS LVar1;
  DWORD local_resc;
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_resc = param_4 << 1;
    LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,param_3,&local_resc);
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c05121a8 FUN_c05121a8 */

undefined4 FUN_c05121a8(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  if ((uVar2 < *(uint *)(param_1 + 0x14)) && (uVar2 + 2 <= *(uint *)(param_1 + 0x14))) {
    puVar3 = (undefined1 *)(*(int *)(param_1 + 4) + uVar2);
    *param_2 = CONCAT11(*puVar3,puVar3[1]);
    uVar1 = 1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0512208 FUN_c0512208 */

undefined4 FUN_c0512208(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  if ((uVar2 < *(uint *)(param_1 + 0x14)) && (uVar2 + 4 <= *(uint *)(param_1 + 0x14))) {
    puVar3 = (undefined1 *)(*(int *)(param_1 + 4) + uVar2);
    *param_2 = CONCAT31(CONCAT21(CONCAT11(*puVar3,puVar3[1]),puVar3[2]),puVar3[3]);
    uVar1 = 1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0512280 FUN_c0512280 */

/* Boundary evidence: original MIPS .pdata c0512280..c0512307. Semantic name remains unreviewed. */

undefined4 FUN_c0512280(int param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0xc);
  uVar2 = *(uint *)(param_1 + 0x14);
  if (((uVar3 < uVar2) && (param_3 <= uVar2)) && (uVar3 + param_3 <= uVar2)) {
    memcpy(param_2,(void *)(*(int *)(param_1 + 4) + uVar3),param_3);
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0512308 FUN_c0512308 */

/* Boundary evidence: original MIPS .pdata c0512308..c0512383. Semantic name remains unreviewed. */

bool FUN_c0512308(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_c0512028(param_1,2);
  if (iVar1 != 0) {
    *(char *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4)) = (char)((uint)param_2 >> 8);
    *(char *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4) + 1) = (char)param_2;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 2;
  }
  return iVar1 != 0;
}



/* c0512384 FUN_c0512384 */

/* Boundary evidence: original MIPS .pdata c0512384..c0512433. Semantic name remains unreviewed. */

undefined4 FUN_c0512384(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c05121a8(param_1,param_2);
  if ((((iVar1 == 0) || (iVar1 = FUN_c05121a8(param_1,param_2 + 1), iVar1 == 0)) ||
      (iVar1 = FUN_c05121a8(param_1,param_2 + 2), iVar1 == 0)) ||
     (((iVar1 = FUN_c05121a8(param_1,param_2 + 3), iVar1 == 0 ||
       (iVar1 = FUN_c05121a8(param_1,param_2 + 4), iVar1 == 0)) ||
      (iVar1 = FUN_c05121a8(param_1,param_2 + 5), iVar1 == 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c0512434 FUN_c0512434 */

/* Boundary evidence: original MIPS .pdata c0512434..c05125cb. Semantic name remains unreviewed. */

undefined4 FUN_c0512434(int param_1,undefined1 *param_2,uint param_3)

{
  bool bVar1;
  uint _Size;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  undefined1 *_Dst;
  int iVar6;
  
  uVar3 = *(uint *)(param_1 + 0xc);
  *param_2 = 0;
  bVar1 = false;
  iVar6 = 0;
  _Dst = param_2;
  do {
    uVar2 = *(uint *)(param_1 + 0x14);
    if (uVar2 <= uVar3) {
      return 0;
    }
    pbVar5 = (byte *)(*(int *)(param_1 + 4) + uVar3);
    _Size = (uint)*pbVar5;
    if (_Size == 0) {
      if (!bVar1) {
        *(uint *)(param_1 + 0xc) = uVar3 + 1;
        return 1;
      }
      return 1;
    }
    if (((_Size & 0xc0) == 0xc0) && (uVar3 < uVar2 - 1)) {
      if (!bVar1) {
        *(uint *)(param_1 + 0xc) = uVar3 + 2;
        bVar1 = true;
      }
      uVar4 = CONCAT11(*pbVar5,pbVar5[1]) & 0xffff3fff;
    }
    else {
      if (0x3f < _Size) {
        return 0;
      }
      if (param_3 < _Size + 2) {
        return 0;
      }
      uVar4 = _Size + uVar3 + 1;
      if (uVar2 <= uVar4) {
        return 0;
      }
      if (_Dst != param_2) {
        *_Dst = 0x2e;
        _Dst = _Dst + 1;
      }
      memcpy(_Dst,(void *)(*(int *)(param_1 + 4) + uVar3 + 1),_Size);
      _Dst = _Dst + _Size;
      *_Dst = 0;
      param_3 = (param_3 - _Size) - 1;
    }
    iVar6 = iVar6 + 1;
    uVar3 = uVar4;
    if (0x7e < iVar6) {
      return 0;
    }
  } while( true );
}



/* c05125cc FUN_c05125cc */

/* Boundary evidence: original MIPS .pdata c05125cc..c051263b. Semantic name remains unreviewed. */

undefined4
FUN_c05125cc(int param_1,undefined1 *param_2,uint param_3,undefined2 *param_4,undefined2 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0512434(param_1,param_2,param_3);
  if (((iVar1 == 0) || (iVar1 = FUN_c05121a8(param_1,param_4), iVar1 == 0)) ||
     (iVar1 = FUN_c05121a8(param_1,param_5), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c051263c FUN_c051263c */

/* Boundary evidence: original MIPS .pdata c051263c..c05126c3. Semantic name remains unreviewed. */

undefined4 FUN_c051263c(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c05121a8(param_1,param_2);
  if ((((iVar1 == 0) || (iVar1 = FUN_c05121a8(param_1,param_2 + 1), iVar1 == 0)) ||
      (iVar1 = FUN_c0512208(param_1,(undefined4 *)(param_2 + 2)), iVar1 == 0)) ||
     (iVar1 = FUN_c05121a8(param_1,param_2 + 4), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c05126c4 FUN_c05126c4 */

/* Boundary evidence: original MIPS .pdata c05126c4..c051271f. Semantic name remains unreviewed. */

undefined4 FUN_c05126c4(int param_1,undefined1 *param_2,uint param_3,undefined2 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0512434(param_1,param_2,param_3);
  if ((iVar1 == 0) || (iVar1 = FUN_c051263c(param_1,param_4), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c0512720 FUN_c0512720 */

/* Boundary evidence: original MIPS .pdata c0512720..c05127b7. Semantic name remains unreviewed. */

undefined4 FUN_c0512720(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 auStack_120 [4];
  undefined1 auStack_118 [256];
  uint local_18;
  
  local_18 = DAT_c052e2d8;
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar1 = FUN_c05125cc(param_1,auStack_118,0x100,auStack_120,auStack_120);
      if (iVar1 == 0) {
        FUN_c052c8e4(local_18);
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  FUN_c052c8e4(local_18);
  return 1;
}



/* c05127b8 FUN_c05127b8 */

/* Boundary evidence: original MIPS .pdata c05127b8..c05127fb. Semantic name remains unreviewed. */

undefined4 * FUN_c05127b8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0511250;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0512824 FUN_c0512824 */

/* Boundary evidence: original MIPS .pdata c0512824..c051287f. Semantic name remains unreviewed. */

bool FUN_c0512824(PCNZWCH param_1,PCNZWCH param_2)

{
  int iVar1;
  
  iVar1 = CompareStringW(0x800,1,param_1,-1,param_2,-1);
  return iVar1 == 2;
}



/* c0512880 FUN_c0512880 */

/* Boundary evidence: original MIPS .pdata c0512880..c0512947. Semantic name remains unreviewed. */

undefined4 FUN_c0512880(int param_1)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  HKEY local_238 [2];
  undefined1 auStack_230 [32];
  wchar_t awStack_210 [256];
  uint local_10;
  
  local_10 = DAT_c052e2d8;
  memcpy(auStack_230,L"\\Parms\\Tcpip",0x1a);
  if (((param_1 != 0) &&
      (HVar1 = StringCchPrintfW(awStack_210,0xff,L"%s%s%s",L"Comm\\",param_1,auStack_230),
      -1 < HVar1)) &&
     (LVar2 = RegOpenKeyExW((HKEY)0x80000002,awStack_210,0,0x20019,local_238), LVar2 == 0)) {
    FUN_c052c8e4(local_10);
    return local_238[0];
  }
  FUN_c052c8e4(local_10);
  return 0;
}



/* c0512948 FUN_c0512948 */

/* Boundary evidence: original MIPS .pdata c0512948..c05129df. Semantic name remains unreviewed. */

bool FUN_c0512948(STRSAFE_LPCWSTR param_1,void *param_2)

{
  int iVar1;
  uint local_30 [2];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [20];
  uint local_c;
  
  local_c = DAT_c052e2d8;
  local_30[0] = 0x1c;
  iVar1 = FUN_c0520400(2,0x17,auStack_28,0x1c,local_30,0,0,param_1,0,(size_t *)0x0);
  if (iVar1 != 0) {
    FUN_c052c8e4(local_c);
  }
  else {
    memcpy(param_2,auStack_20,0x10);
    FUN_c052c8e4(local_c);
  }
  return iVar1 == 0;
}



/* c05129e0 FUN_c05129e0 */

/* Boundary evidence: original MIPS .pdata c05129e0..c0512b3f. Semantic name remains unreviewed. */

void FUN_c05129e0(int param_1)

{
  bool bVar1;
  HKEY hKey;
  int iVar2;
  size_t sVar3;
  undefined3 extraout_var;
  char *_Dst;
  STRSAFE_LPCWSTR _Str;
  uint uVar4;
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_c052e2d8;
  hKey = (HKEY)FUN_c0512880(*(int *)(param_1 + 0x4c));
  if (hKey != (HKEY)0x0) {
    _Dst = (char *)(param_1 + 8);
    memset(_Dst,0,0x40);
    iVar2 = GetRegMultiSZValue(hKey,L"DhcpV6DNS",awStack_220,0x200);
    if ((iVar2 != 0) && (sVar3 = wcslen(awStack_220), sVar3 != 0)) {
      _Str = awStack_220;
      uVar4 = 0;
      do {
        bVar1 = FUN_c0512948(_Str,_Dst);
        if (CONCAT31(extraout_var,bVar1) != 0) {
          if (((DAT_c052e3f4 == 0) && (*_Dst == -2)) && ((_Dst[1] & 0xc0U) == 0xc0)) {
            memset(_Dst,0,0x10);
            uVar4 = uVar4 - 1;
            _Dst = _Dst + -0x10;
          }
          sVar3 = wcslen(_Str);
          if ((0x40 < sVar3 + 1) || (_Str = _Str + sVar3 + 1, *_Str == L'\0')) break;
        }
        uVar4 = uVar4 + 1;
        _Dst = _Dst + 0x10;
      } while (uVar4 < 4);
    }
    RegCloseKey(hKey);
  }
  FUN_c052c8e4(local_20);
  return;
}



/* c0512b40 FUN_c0512b40 */

/* Boundary evidence: original MIPS .pdata c0512b40..c0512baf. Semantic name remains unreviewed. */

bool FUN_c0512b40(undefined4 param_1,undefined4 param_2,void *param_3)

{
  bool bVar1;
  int iVar2;
  wchar_t awStack_90 [64];
  uint local_10;
  
  local_10 = DAT_c052e2d8;
  iVar2 = GetRegSZValue(param_1,param_2,awStack_90,0x80);
  if (iVar2 == 0) {
    FUN_c052c8e4(local_10);
    bVar1 = false;
  }
  else {
    bVar1 = FUN_c0512948(awStack_90,param_3);
    FUN_c052c8e4(local_10);
  }
  return bVar1;
}



/* c0512bb0 FUN_c0512bb0 */

/* Boundary evidence: original MIPS .pdata c0512bb0..c0512c87. Semantic name remains unreviewed. */

void FUN_c0512bb0(undefined4 param_1,char *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  uint local_18;
  
  local_18 = DAT_c052e2d8;
  local_28 = 0xff;
  local_27 = 2;
  local_26 = 0;
  local_25 = 0;
  local_24 = 0;
  local_23 = 0;
  local_22 = 0;
  local_21 = 0;
  local_20 = 0;
  local_1f = 0;
  local_1e = 0;
  local_1d = 0;
  local_1c = 0;
  local_1b = 1;
  local_1a = 0;
  local_19 = 3;
  bVar1 = FUN_c0512b40(param_1,L"LLMNRv6Address",param_2);
  if (((CONCAT31(extraout_var,bVar1) == 0) || (*param_2 != -1)) || ((param_2[1] & 0xfU) != 2)) {
    memcpy(param_2,&local_28,0x10);
  }
  FUN_c052c8e4(local_18);
  return;
}



/* c0512c88 FUN_c0512c88 */

/* Boundary evidence: original MIPS .pdata c0512c88..c0512ccf. Semantic name remains unreviewed. */

uint FUN_c0512c88(undefined4 param_1)

{
  uint local_10 [2];
  
  local_10[0] = 0x14eb;
  GetRegDWORDValue(param_1,L"LLMNRPort",local_10);
  return (local_10[0] & 0xff) << 8 | local_10[0] >> 8 & 0xff;
}



/* c0512cd0 FUN_c0512cd0 */

/* Boundary evidence: original MIPS .pdata c0512cd0..c0512d73. Semantic name remains unreviewed. */

void FUN_c0512cd0(void)

{
  LSTATUS LVar1;
  uint uVar2;
  HKEY local_18 [2];
  
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\AFD",0,0x20019,local_18);
  if (LVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
    FUN_c0512bb0(local_18[0],&DAT_c052e308);
    uVar2 = FUN_c0512c88(local_18[0]);
    DAT_c052e302 = (undefined2)uVar2;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
    RegCloseKey(local_18[0]);
  }
  return;
}



/* c0512d74 FUN_c0512d74 */

/* Boundary evidence: original MIPS .pdata c0512d74..c0512fcf. Semantic name remains unreviewed. */

void FUN_c0512d74(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_30;
  int local_2c;
  
  local_2c = 1;
  local_30 = 1;
  if (param_1 == 0) {
LAB_c0512ed0:
    iVar3 = 3;
    iVar5 = 4;
LAB_c0512ed8:
    iVar1 = 0;
  }
  else {
    GetRegDWORDValue(param_1,L"NameResolutionOrdering",&local_2c);
    iVar1 = GetRegDWORDValue(param_1,L"EnableMDNS",&local_30);
    if (iVar1 == 0) {
      GetRegDWORDValue(param_1,L"EnableLLMNR",&local_30);
    }
    GetRegDWORDValue(param_1,L"EnableSingleLabelDNS",&DAT_c052e3f0);
    GetRegDWORDValue(param_1,L"QuerySiteLocalDNS",&DAT_c052e3f4);
    GetRegDWORDValue(param_1,L"DNSManagedNet",&DAT_c052e180);
    if (local_2c == 2) {
      iVar3 = 0;
      iVar1 = 1;
      iVar5 = 4;
      goto LAB_c0512edc;
    }
    if (local_2c == 3) {
      iVar3 = 0;
      iVar5 = 1;
    }
    else {
      if (local_2c == 4) {
        iVar5 = 0;
        iVar1 = 3;
        iVar3 = 6;
        goto LAB_c0512edc;
      }
      if (local_2c != 5) {
        if (local_2c != 6) goto LAB_c0512ed0;
        iVar5 = 3;
        iVar3 = 6;
        goto LAB_c0512ed8;
      }
      iVar5 = 0;
      iVar3 = 3;
    }
    iVar1 = 4;
  }
LAB_c0512edc:
  puVar4 = &DAT_c052e2e0;
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  } while (puVar4 != &DAT_c052e2fc);
  (&DAT_c052e2e4)[iVar1] = 2;
  (&DAT_c052e2e0)[iVar1] = 1;
  (&DAT_c052e2e8)[iVar1] = 3;
  if (local_30 == 0) {
    DAT_c052e17c = 0;
  }
  else {
    (&DAT_c052e2e0)[iVar3] = 7;
    DAT_c052e300 = 0x17;
    FUN_c0512bb0(param_1,&DAT_c052e308);
    uVar2 = FUN_c0512c88(param_1);
    DAT_c052e302 = (undefined2)uVar2;
    DAT_c052e304 = 0;
    DAT_c052e318 = 0;
  }
  (&DAT_c052e2e4)[iVar5] = 5;
  (&DAT_c052e2e0)[iVar5] = 4;
  (&DAT_c052e2e8)[iVar5] = 6;
  return;
}



/* c0512fd0 FUN_c0512fd0 */

/* Boundary evidence: original MIPS .pdata c0512fd0..c051306f. Semantic name remains unreviewed. */

undefined4 FUN_c0512fd0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar4;
  piVar3 = DAT_c052e37c;
  piVar2 = DAT_c052e37c;
  if (iVar4 == 0) {
    while (piVar1 = piVar3, piVar1 != (int *)0x0) {
      if (piVar1 == (int *)param_1) {
        if (piVar1 == DAT_c052e37c) {
          DAT_c052e37c = (int *)*piVar1;
        }
        else {
          *piVar2 = *piVar1;
        }
        if (*(int *)(param_1 + 0x58) != 0) {
          CTEFreeMem();
        }
        CTEFreeMem(param_1);
        return 1;
      }
      piVar2 = piVar1;
      piVar3 = (int *)*piVar1;
    }
  }
  return 0;
}



/* c0513070 FUN_c0513070 */

/* Boundary evidence: original MIPS .pdata c0513070..c051310f. Semantic name remains unreviewed. */

undefined4 FUN_c0513070(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar4;
  piVar3 = DAT_c052e3d8;
  piVar2 = DAT_c052e3d8;
  if (iVar4 == 0) {
    while (piVar1 = piVar3, piVar1 != (int *)0x0) {
      if (piVar1 == (int *)param_1) {
        if (piVar1 == DAT_c052e3d8) {
          DAT_c052e3d8 = (int *)*piVar1;
        }
        else {
          *piVar2 = *piVar1;
        }
        if (*(int *)(param_1 + 0x4c) != 0) {
          CTEFreeMem();
        }
        CTEFreeMem(param_1);
        return 1;
      }
      piVar2 = piVar1;
      piVar3 = (int *)*piVar1;
    }
  }
  return 0;
}



/* c0513110 FUN_c0513110 */

/* Boundary evidence: original MIPS .pdata c0513110..c05131df. Semantic name remains unreviewed. */

void FUN_c0513110(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = PTR_FUN_c052e1ec;
  if ((code *)PTR_FUN_c052e1ec != FUN_c052c76c) {
    iVar3 = 4;
    do {
      uVar2 = *param_4;
      if (uVar2 != 0) {
        (*(code *)puVar1)(param_3,3,param_2,
                          (uVar2 & 0xff0000 | uVar2 >> 0x10) >> 8 |
                          (uVar2 << 0x10 | uVar2 & 0xff00) << 8,0,param_1,0);
      }
      param_4 = param_4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}



/* c05131e0 FUN_c05131e0 */

/* Boundary evidence: original MIPS .pdata c05131e0..c0513333. Semantic name remains unreviewed. */

undefined4 FUN_c05131e0(int param_1,char *param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  int *piVar2;
  undefined4 uVar3;
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_c052e2d8;
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  piVar2 = DAT_c052e3d8;
  do {
    if (piVar2 == (int *)0x0) {
      piVar2 = FUN_c0511fb4(0x60);
      if (piVar2 != (int *)0x0) {
        *piVar2 = (int)DAT_c052e3d8;
        uVar3 = 1;
        DAT_c052e3d8 = piVar2;
        piVar2[0x12] = param_1;
        piVar2[0x14] = 2;
        piVar2[0x15] = 6000;
        piVar2[0x16] = 1000;
        piVar2[1] = 1;
        if (param_2 == (char *)0x0) {
          piVar2[0x13] = 0;
        }
        else {
          sVar1 = strlen(param_2);
          mbstowcs(awStack_228,param_2,sVar1 + 1);
          sVar1 = wcslen(awStack_228);
          _Dest = FUN_c0511fb4((sVar1 + 1) * 2);
          piVar2[0x13] = (int)_Dest;
          if (_Dest != (wchar_t *)0x0) {
            wcscpy(_Dest,awStack_228);
            FUN_c05129e0((int)piVar2);
          }
        }
      }
LAB_c05132fc:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
      FUN_c052c8e4(local_28);
      return uVar3;
    }
    if (piVar2[0x12] == param_1) {
      FUN_c05129e0((int)piVar2);
      uVar3 = 0;
      goto LAB_c05132fc;
    }
    piVar2 = (int *)*piVar2;
  } while( true );
}



/* c0513334 FUN_c0513334 */

/* Boundary evidence: original MIPS .pdata c0513334..c05133f3. Semantic name remains unreviewed. */

int FUN_c0513334(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  piVar2 = (int *)DAT_c052e3d8;
  do {
    if (piVar2 == (int *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
      return iVar3;
    }
    if (param_1 != 0) {
      iVar1 = param_1;
      do {
        if (piVar2[0x12] == *(int *)(iVar1 + 0x48)) goto LAB_c05133c0;
        iVar1 = *(int *)(iVar1 + 8);
      } while (iVar1 != 0);
    }
    if (piVar2[0x17] == 0) {
      piVar2[0x17] = 1;
      iVar1 = *piVar2;
      FUN_c0513070((int)piVar2);
      iVar3 = iVar3 + 1;
      piVar2 = (int *)iVar1;
    }
    else {
LAB_c05133c0:
      piVar2 = (int *)*piVar2;
    }
  } while( true );
}



/* c05133f4 FUN_c05133f4 */

/* Boundary evidence: original MIPS .pdata c05133f4..c05134cf. Semantic name remains unreviewed. */

undefined4 FUN_c05133f4(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (DAT_c052e3b0 == (HMODULE)0x0) {
    DAT_c052e3b0 = LoadLibraryW(L"iphlpapi");
    if (DAT_c052e3b0 == (HMODULE)0x0) {
      uVar1 = 0;
      DAT_c052e3b0 = (HMODULE)0x0;
    }
    else {
      DAT_c052e398 = GetProcAddressW(DAT_c052e3b0,L"GetAdaptersAddresses");
      if ((DAT_c052e398 != 0) &&
         (DAT_c052e3b8 = GetProcAddressW(DAT_c052e3b0,L"GetBestInterfaceEx"), DAT_c052e3b8 != 0)) {
        return 1;
      }
      uVar1 = 0;
      FreeLibrary(DAT_c052e3b0);
      DAT_c052e3b0 = (HMODULE)0x0;
      DAT_c052e398 = 0;
      DAT_c052e3b8 = 0;
    }
  }
  return uVar1;
}



/* c05134d0 FUN_c05134d0 */

/* Boundary evidence: original MIPS .pdata c05134d0..c051354f. Semantic name remains unreviewed. */

int FUN_c05134d0(undefined4 param_1,int param_2)

{
  int iVar1;
  int local_18 [2];
  
  iVar1 = FUN_c05133f4();
  if ((iVar1 != 0) && (iVar1 = (*DAT_c052e3b8)(param_1,local_18), iVar1 == 0)) {
    for (; param_2 != 0; param_2 = *(int *)(param_2 + 8)) {
      if (*(int *)(param_2 + 0x48) == local_18[0]) {
        return param_2;
      }
    }
  }
  return 0;
}



/* c0513550 FUN_c0513550 */

/* Boundary evidence: original MIPS .pdata c0513550..c0513603. Semantic name remains unreviewed. */

undefined4 FUN_c0513550(undefined4 *param_1)

{
  int iVar1;
  HLOCAL pvVar2;
  SIZE_T local_18 [2];
  
  iVar1 = FUN_c05133f4();
  if (((iVar1 != 0) && (iVar1 = (*DAT_c052e398)(0x17,0xe,0,0,local_18), iVar1 == 0x6f)) &&
     (pvVar2 = LocalAlloc(0x40,local_18[0]), pvVar2 != (HLOCAL)0x0)) {
    (*DAT_c052e398)(0x17,0xe,0,pvVar2,local_18);
    *param_1 = pvVar2;
    return 1;
  }
  return 0;
}



/* c0513604 FUN_c0513604 */

undefined4 FUN_c0513604(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)&UNK_c051104c;
  iVar1 = 2;
  do {
    if (*(int *)(param_1 + 0x40) == iVar1) {
      if (*(int *)(param_1 + 0x44) == 1) {
        return 1;
      }
      return 0;
    }
    piVar2 = piVar2 + 1;
    iVar1 = *piVar2;
  } while (iVar1 != -1);
  return 0;
}



/* c051365c FUN_c051365c */

/* Boundary evidence: original MIPS .pdata c051365c..c05137bb. Semantic name remains unreviewed. */

void FUN_c051365c(HKEY param_1,int param_2,int param_3)

{
  LSTATUS LVar1;
  int iVar2;
  int *piVar3;
  HKEY local_res0 [4];
  
  local_res0[0] = param_1;
  if ((param_1 != (HKEY)0x0) ||
     (LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Tcpip\\Parms",0,0x20019,local_res0), LVar1 == 0
     )) {
    if (param_2 != 0) {
      piVar3 = (int *)(param_2 + 0x5c);
      iVar2 = GetRegDWORDValue(local_res0[0],L"ResolverRetryCount",piVar3);
      if (iVar2 != 0) {
        *piVar3 = *piVar3 + 1;
      }
      GetRegDWORDValue(local_res0[0],L"DNSTimeout",param_2 + 0x60);
      GetRegDWORDValue(local_res0[0],L"WINSTimeout",param_2 + 100);
      GetRegDWORDValue(local_res0[0],L"WINSBroadcastTimeout",param_2 + 0x68);
    }
    if (param_3 != 0) {
      piVar3 = (int *)(param_3 + 0x50);
      iVar2 = GetRegDWORDValue(local_res0[0],L"ResolverRetryCount",piVar3);
      if (iVar2 != 0) {
        *piVar3 = *piVar3 + 1;
      }
      GetRegDWORDValue(local_res0[0],L"DNSTimeout",param_3 + 0x54);
      GetRegDWORDValue(local_res0[0],L"MDNSTimeout",param_3 + 0x58);
    }
    RegCloseKey(local_res0[0]);
  }
  return;
}



/* c05137bc FUN_c05137bc */

/* Boundary evidence: original MIPS .pdata c05137bc..c051383b. Semantic name remains unreviewed. */

void FUN_c05137bc(int param_1,int param_2)

{
  HKEY pHVar1;
  int iVar2;
  
  FUN_c051365c((HKEY)0x0,param_1,param_2);
  if (param_1 == 0) {
    if (param_2 == 0) {
      return;
    }
    iVar2 = *(int *)(param_2 + 0x4c);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x58);
  }
  if ((iVar2 != 0) && (pHVar1 = (HKEY)FUN_c0512880(iVar2), pHVar1 != (HKEY)0x0)) {
    FUN_c051365c(pHVar1,param_1,param_2);
  }
  return;
}



/* c051383c FUN_c051383c */

/* Boundary evidence: original MIPS .pdata c051383c..c05138d7. Semantic name remains unreviewed. */

undefined4 FUN_c051383c(int param_1,wchar_t *param_2)

{
  HKEY hKey;
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  hKey = (HKEY)FUN_c0512880(param_1);
  if (hKey != (HKEY)0x0) {
    memset(param_2,0,0x1fe);
    iVar1 = GetRegSZValue(hKey,L"Domain",param_2,0x1fc);
    if ((iVar1 != 0) && (sVar2 = wcslen(param_2), sVar2 != 0)) {
      uVar3 = 1;
    }
    RegCloseKey(hKey);
  }
  return uVar3;
}



/* c05138d8 FUN_c05138d8 */

/* Boundary evidence: original MIPS .pdata c05138d8..c0513a87. Semantic name remains unreviewed. */

void FUN_c05138d8(void)

{
  int iVar1;
  size_t sVar2;
  void *_Dst;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int local_258 [14];
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_c052e2d8;
  iVar4 = 0;
  memset(local_258,0,0x34);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  piVar3 = local_258;
  piVar5 = (int *)DAT_c052e37c;
  do {
    if ((piVar5 == (int *)0x0) || (0xb < iVar4)) goto LAB_c05139a0;
    if ((piVar5[0x16] != 0) && (iVar1 = FUN_c051383c(piVar5[0x16],awStack_220), iVar1 != 0)) {
      sVar2 = wcslen(awStack_220);
      sVar2 = (sVar2 + 1) * 2;
      _Dst = (void *)CTEAllocMem(sVar2);
      *piVar3 = (int)_Dst;
      if (_Dst == (void *)0x0) {
LAB_c05139a0:
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
        if (iVar4 != 0) {
          sVar2 = (iVar4 + 1) * 4;
          piVar3 = (int *)CTEAllocMem(sVar2);
          if (piVar3 == (int *)0x0) {
            piVar3 = local_258;
            while (local_258[0] != 0) {
              CTEFreeMem(local_258[0]);
              piVar3 = piVar3 + 1;
              local_258[0] = *piVar3;
            }
          }
          else {
            memcpy(piVar3,local_258,sVar2);
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
            piVar5 = DAT_c052e2fc;
            DAT_c052e2fc = piVar3;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
            if (piVar5 != (int *)0x0) {
              iVar4 = *piVar5;
              piVar3 = piVar5;
              while (iVar4 != 0) {
                CTEFreeMem(iVar4);
                piVar3 = piVar3 + 1;
                iVar4 = *piVar3;
              }
              CTEFreeMem(piVar5);
            }
          }
        }
        FUN_c052c8e4(local_20);
        return;
      }
      memcpy(_Dst,awStack_220,sVar2);
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    }
    piVar5 = (int *)*piVar5;
  } while( true );
}



/* c0513a88 FUN_c0513a88 */

/* Boundary evidence: original MIPS .pdata c0513a88..c0513b4f. Semantic name remains unreviewed. */

undefined4 FUN_c0513a88(int *param_1,int *param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_c052e2d8;
  if (param_2 == (int *)0x0) {
    iVar1 = *(int *)(*param_1 + 0x58);
  }
  else {
    iVar1 = *(int *)(*param_2 + 0x4c);
  }
  iVar1 = FUN_c051383c(iVar1,awStack_218);
  if (iVar1 != 0) {
    *param_3 = 0x2e;
    iVar1 = WideCharToMultiByte(0,0,awStack_218,-1,param_3 + 1,param_4 + -1,(LPCSTR)0x0,(LPBOOL)0x0)
    ;
    if (iVar1 != 0) {
      FUN_c052c8e4(local_18);
      return 1;
    }
  }
  FUN_c052c8e4(local_18);
  return 0;
}



/* c0513b50 FUN_c0513b50 */

/* Boundary evidence: original MIPS .pdata c0513b50..c0513caf. Semantic name remains unreviewed. */

undefined4 FUN_c0513b50(char *param_1,uint param_2)

{
  undefined4 uVar1;
  LSTATUS LVar2;
  HKEY local_228;
  DWORD local_224;
  DWORD local_220 [2];
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_c052e2d8;
  if ((int)param_2 < 1) {
    SetLastError(0x271e);
LAB_c0513b90:
    FUN_c052c8e4(local_18);
    uVar1 = 0xffffffff;
  }
  else {
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0,&local_228);
    if (LVar2 == 0) {
      local_224 = 0x1fe;
      LVar2 = RegQueryValueExW(local_228,L"Name",(LPDWORD)0x0,local_220,(LPBYTE)awStack_218,
                               &local_224);
      RegCloseKey(local_228);
      if ((LVar2 != 0) || (local_220[0] != 1)) goto LAB_c0513c54;
      wcstombs(param_1,awStack_218,param_2);
      param_1[param_2 - 1] = '\0';
    }
    else {
LAB_c0513c54:
      if (param_2 < 10) {
        SetLastError(0x271e);
        goto LAB_c0513b90;
      }
      memcpy(param_1,"WindowsCE",10);
    }
    FUN_c052c8e4(local_18);
    uVar1 = 0;
  }
  return uVar1;
}



/* c0513cb0 FUN_c0513cb0 */

/* Boundary evidence: original MIPS .pdata c0513cb0..c0513e0b. Semantic name remains unreviewed. */

undefined4 FUN_c0513cb0(byte *param_1,wchar_t *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  iVar7 = 0;
  bVar1 = *param_1;
  pwVar4 = param_2;
  while (uVar6 = (uint)bVar1, uVar6 != 0) {
    if ((uVar6 < 0x41) || (uVar8 = uVar6 + 0x20, 0x5a < uVar6)) {
      uVar8 = uVar6;
    }
    uVar6 = (uint)(ushort)*pwVar4;
    if ((uVar6 < 0x41) || (uVar5 = uVar6 + 0x20, 0x5a < uVar6)) {
      uVar5 = uVar6;
    }
    if (uVar8 != uVar5) break;
    iVar7 = iVar7 + 1;
    pwVar4 = pwVar4 + 1;
    bVar1 = param_1[iVar7];
  }
  if ((param_1[iVar7] == 0) && (param_2[iVar7] == L'\0')) {
LAB_c0513d68:
    uVar2 = 1;
  }
  else {
    sVar3 = strlen((char *)param_1);
    uVar6 = (sVar3 + 1) * 4;
    pwVar4 = FUN_c0511fb4(uVar6);
    if (pwVar4 != (wchar_t *)0x0) {
      iVar7 = MultiByteToWideChar(0xfde9,0,(LPCSTR)param_1,-1,pwVar4,uVar6);
      if ((iVar7 != 0) && (iVar7 = wcscmp(pwVar4,param_2), iVar7 == 0)) {
        CTEFreeMem(pwVar4);
        goto LAB_c0513d68;
      }
      CTEFreeMem(pwVar4);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* c0513e0c FUN_c0513e0c */

/* Boundary evidence: original MIPS .pdata c0513e0c..c0513f37. Semantic name remains unreviewed. */

undefined4 FUN_c0513e0c(void *param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  memcpy(param_1,param_2,0x450);
  *(int *)((int)param_1 + 0x14) = (int)param_1 + 100;
  *(int *)((int)param_1 + 0x18) = (int)param_1 + 0x24;
  *(int *)((int)param_1 + 0x20) = (int)param_1 + 0x2e4;
  if (*(int *)((int)param_2 + 0x18) != 0) {
    iVar2 = 0;
    while( true ) {
      iVar1 = *(int *)(iVar2 * 4 + *(int *)((int)param_2 + 0x18));
      if (iVar1 == 0) break;
      *(int *)(*(int *)((int)param_1 + 0x18) + iVar2 * 4) = (iVar1 - (int)param_2) + (int)param_1;
      iVar2 = iVar2 + 1;
    }
  }
  iVar2 = 0;
  while( true ) {
    piVar3 = (int *)(iVar2 * 4 + *(int *)((int)param_1 + 0x20));
    if (*piVar3 == 0) break;
    *piVar3 = (int)param_1 + *(short *)((int)param_1 + 0x1e) * iVar2 + 0x324;
    iVar2 = iVar2 + 1;
  }
  return 0;
}



/* c0513f38 FUN_c0513f38 */

/* Boundary evidence: original MIPS .pdata c0513f38..c0513f43. Semantic name remains unreviewed. */

undefined4 FUN_c0513f38(void)

{
  return 1;
}



/* c0513f44 FUN_c0513f44 */

/* Boundary evidence: original MIPS .pdata c0513f44..c051403f. Semantic name remains unreviewed. */

int FUN_c0513f44(short *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  short *_Dst;
  
  pbVar3 = (byte *)(param_2 + 3);
  iVar4 = 4;
  _Dst = param_1;
  do {
    bVar1 = *pbVar3;
    uVar2 = (uint)bVar1;
    if (uVar2 < 100) {
      if (9 < uVar2) {
        *_Dst = bVar1 / 10 + 0x30;
        _Dst = _Dst + 1;
        goto LAB_c0513fe4;
      }
    }
    else {
      uVar2 = uVar2 % 100;
      *_Dst = bVar1 / 100 + 0x30;
      _Dst[1] = (short)(uVar2 / 10) + 0x30;
      _Dst = _Dst + 2;
LAB_c0513fe4:
      uVar2 = uVar2 % 10;
    }
    *_Dst = (short)uVar2 + 0x30;
    _Dst[1] = 0x2e;
    _Dst = _Dst + 2;
    iVar4 = iVar4 + -1;
    pbVar3 = pbVar3 + -1;
    if (iVar4 == 0) {
      memcpy(_Dst,L"in-addr.arpa",0x1a);
      return (int)_Dst - (int)param_1 >> 1;
    }
  } while( true );
}



/* c0514040 FUN_c0514040 */

/* Boundary evidence: original MIPS .pdata c0514040..c0514097. Semantic name remains unreviewed. */

void FUN_c0514040(int param_1)

{
  CTEFreeMem(*(undefined4 *)(param_1 + 4));
  if (*(int *)(param_1 + 0x10) != 0) {
    CTEFreeMem();
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    CTEFreeMem();
  }
  CTEFreeMem(param_1);
  return;
}



/* c0514098 FUN_c0514098 */

/* Boundary evidence: original MIPS .pdata c0514098..c05142a7. Semantic name remains unreviewed. */

void FUN_c0514098(int param_1,int param_2,int param_3)

{
  size_t sVar1;
  undefined4 *puVar2;
  int iVar3;
  char *_Dest;
  char *_Str;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_30;
  
  memset((undefined4 *)(param_1 + 0x14),0,0x10);
  if (param_3 == 0) {
    *(undefined2 *)(param_1 + 0x1c) = 2;
  }
  else {
    *(undefined2 *)(param_1 + 0x1c) = 0x17;
  }
  *(short *)(param_1 + 0x1e) = (short)*(undefined4 *)(param_2 + 0x18);
  strcpy((char *)(param_1 + 100),*(char **)(param_2 + 4));
  *(undefined4 *)(param_1 + 0x14) = (char *)(param_1 + 100);
  *(int *)(param_1 + 0x18) = param_1 + 0x24;
  sVar1 = strlen(*(char **)(param_2 + 4));
  _Str = *(char **)(param_2 + 0x1c);
  iVar6 = 0;
  if (_Str != (char *)0x0) {
    local_30 = 0;
    iVar5 = 1;
    iVar3 = sVar1 + 1;
    while (*_Str != '\0') {
      sVar1 = strlen(_Str);
      if ((iVar5 == 0xf) || (iVar4 = sVar1 + 1 + iVar3, 0x280 < iVar4 + 1U)) break;
      _Dest = (char *)(param_1 + 100 + iVar3);
      strcpy(_Dest,_Str);
      _Str = _Str + sVar1 + 1;
      iVar6 = iVar6 + 1;
      puVar2 = (undefined4 *)(local_30 + *(int *)(param_1 + 0x18));
      local_30 = local_30 + 4;
      *puVar2 = _Dest;
      iVar5 = iVar5 + 1;
      iVar3 = iVar4;
      if (_Str == (char *)0x0) break;
    }
  }
  *(undefined4 *)(iVar6 * 4 + *(int *)(param_1 + 0x18)) = 0;
  *(int *)(param_1 + 0x20) = param_1 + 0x2e4;
  if (*(void **)(param_2 + 0x10) != (void *)0x0) {
    if ((0xf < *(int *)(param_2 + 0x14)) || (0x14 < *(uint *)(param_2 + 0x18))) {
      *(undefined4 *)(param_1 + 0x20) = 0;
      return;
    }
    memcpy((void *)(param_1 + 0x324),*(void **)(param_2 + 0x10),
           *(int *)(param_2 + 0x14) * *(uint *)(param_2 + 0x18));
  }
  iVar3 = 0;
  iVar6 = 0;
  if (0 < *(int *)(param_2 + 0x14)) {
    iVar5 = 0;
    do {
      if (0x3b < iVar5) break;
      *(int *)(*(int *)(param_1 + 0x20) + iVar5) = iVar3 + param_1 + 0x324;
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 4;
      iVar3 = iVar3 + *(int *)(param_2 + 0x18);
    } while (iVar6 < *(int *)(param_2 + 0x14));
  }
  *(undefined4 *)(iVar6 * 4 + *(int *)(param_1 + 0x20)) = 0;
  return;
}



/* c05142a8 FUN_c05142a8 */

/* Boundary evidence: original MIPS .pdata c05142a8..c051438b. Semantic name remains unreviewed. */

undefined4 FUN_c05142a8(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c052e2d8;
  iVar1 = MultiByteToWideChar(0,0,*(LPCSTR *)(param_3 + 4),-1,aWStack_228,0x104);
  if (iVar1 == 0) {
    FUN_c052c8e4(local_20);
    uVar2 = 0x54f;
  }
  else {
    iVar1 = FUN_c052c76c();
    *param_2 = iVar1;
    if (iVar1 == 0) {
      FUN_c052c8e4(local_20);
      uVar2 = 0xe;
    }
    else {
      FUN_c052c8e4(local_20);
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* c051438c FUN_c051438c */

/* Boundary evidence: original MIPS .pdata c051438c..c05143f3. Semantic name remains unreviewed. */

void FUN_c051438c(longlong *param_1,uint param_2)

{
  GetCurrentFT(param_1);
  *param_1 = (ulonglong)param_2 * 10000000 + *param_1;
  return;
}



/* c05143f4 FUN_c05143f4 */

/* Boundary evidence: original MIPS .pdata c05143f4..c05145e7. Semantic name remains unreviewed. */

undefined4 * FUN_c05143f4(wchar_t *param_1,uint param_2)

{
  wchar_t wVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  LONG LVar4;
  int iVar5;
  wchar_t *pwVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  FILETIME FStack_438;
  wchar_t local_430 [512];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  sVar2 = wcslen(param_1);
  if ((int)sVar2 < 0x100) {
    pwVar3 = local_430;
  }
  else {
    pwVar3 = FUN_c0511fb4((sVar2 + 0x100) * 2);
  }
  wVar1 = *param_1;
  iVar7 = 0;
  *pwVar3 = wVar1;
  if (wVar1 != L'\0') {
    pwVar6 = pwVar3;
    do {
      pwVar6 = pwVar6 + 1;
      wVar1 = *(wchar_t *)(((int)param_1 - (int)pwVar3) + (int)pwVar6);
      iVar7 = iVar7 + 1;
      *pwVar6 = wVar1;
    } while (wVar1 != L'\0');
  }
  pwVar3[iVar7] = L'.';
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
  GetCurrentFT(&FStack_438);
  puVar8 = &DAT_c052e394;
  puVar9 = DAT_c052e394;
  do {
    if (puVar9 == (undefined4 *)0x0) {
LAB_c0514594:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
LAB_c051459c:
      if (pwVar3 != local_430) {
        CTEFreeMem(pwVar3);
      }
      FUN_c052c8e4(local_30);
      return puVar9;
    }
    LVar4 = CompareFileTime(&FStack_438,(FILETIME *)(puVar9 + 2));
    if (LVar4 < 0) {
      if (param_2 == (puVar9[9] & 1)) {
        iVar5 = FUN_c0513cb0((byte *)puVar9[1],param_1);
        if (iVar5 != 0) {
LAB_c051458c:
          if (puVar9 != (undefined4 *)0x0) goto LAB_c051459c;
          goto LAB_c0514594;
        }
        puVar8 = DAT_c052e2fc;
        if (DAT_c052e2fc != (undefined4 *)0x0) {
          for (; (wchar_t *)*puVar8 != (wchar_t *)0x0; puVar8 = puVar8 + 1) {
            wcsncpy(pwVar3 + iVar7 + 1,(wchar_t *)*puVar8,0xff);
            iVar5 = FUN_c0513cb0((byte *)puVar9[1],pwVar3);
            if (iVar5 != 0) goto LAB_c051458c;
          }
        }
      }
    }
    else {
      *puVar8 = *puVar9;
      FUN_c0514040((int)puVar9);
      DAT_c052e3d0 = DAT_c052e3d0 + -1;
      puVar9 = puVar8;
    }
    puVar8 = puVar9;
    puVar9 = (undefined4 *)*puVar9;
  } while( true );
}



/* c05145e8 FUN_c05145e8 */

/* Boundary evidence: original MIPS .pdata c05145e8..c051464f. Semantic name remains unreviewed. */

void FUN_c05145e8(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
  puVar2 = DAT_c052e394;
  DAT_c052e394 = (undefined4 *)0x0;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    FUN_c0514040((int)puVar2);
    puVar2 = puVar1;
  }
  DAT_c052e3d0 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
  return;
}



/* c0514650 FUN_c0514650 */

/* Boundary evidence: original MIPS .pdata c0514650..c05146b7. Semantic name remains unreviewed. */

void FUN_c0514650(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = &DAT_c052e394;
  puVar2 = DAT_c052e394;
  do {
    if (puVar2 == (undefined4 *)0x0) {
LAB_c0514694:
      FUN_c0514040((int)param_1);
      DAT_c052e3d0 = DAT_c052e3d0 + -1;
      return;
    }
    if (puVar2 == param_1) {
      *puVar1 = *param_1;
      goto LAB_c0514694;
    }
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}



/* c05146b8 FUN_c05146b8 */

/* Boundary evidence: original MIPS .pdata c05146b8..c0514937. Semantic name remains unreviewed. */

void FUN_c05146b8(char *param_1,int *param_2,uint param_3,undefined4 *param_4,uint param_5,
                 undefined4 param_6)

{
  undefined4 *puVar1;
  size_t sVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  uint _Size;
  uint _Size_00;
  uint uVar6;
  undefined1 auStack_3b8 [304];
  char local_288 [600];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  _Size = 0;
  if (((param_5 == 0) || (0x14 < param_3)) ||
     (puVar1 = FUN_c0511fb4(0x28), puVar1 == (undefined4 *)0x0)) goto LAB_c05148f4;
  _Size_00 = 0;
  if (param_2 != (int *)0x0) {
    iVar4 = *param_2;
    uVar6 = 0;
    for (; ((iVar4 != 0 && (uVar6 < 0x10)) && ((_Size_00 < 0xf0 && (param_3 <= 0xf0 - _Size_00))));
        _Size_00 = _Size_00 + param_3) {
      memcpy(auStack_3b8 + _Size_00,(void *)*param_2,param_3);
      param_2 = param_2 + 1;
      iVar4 = *param_2;
      uVar6 = uVar6 + 1;
    }
    puVar1[5] = uVar6;
  }
  if (param_4 == (undefined4 *)0x0) {
    _Size = 0;
  }
  else {
    for (uVar6 = 0; (pcVar5 = (char *)*param_4, pcVar5 != (char *)0x0 && (uVar6 < 0x10));
        uVar6 = uVar6 + 1) {
      for (; (*pcVar5 != '\0' && (_Size < 599)); _Size = _Size + 1) {
        local_288[_Size] = *pcVar5;
        pcVar5 = pcVar5 + 1;
      }
      param_4 = param_4 + 1;
      local_288[_Size] = '\0';
      _Size = _Size + 1;
    }
  }
  sVar2 = strlen(param_1);
  if (sVar2 + 1 == 0) {
LAB_c0514850:
    if (_Size_00 != 0) {
      pvVar3 = FUN_c0511fb4(_Size_00);
      puVar1[4] = pvVar3;
      if (pvVar3 == (void *)0x0) goto LAB_c0514928;
      memcpy(pvVar3,auStack_3b8,_Size_00);
      puVar1[6] = param_3;
    }
    if (_Size != 0) {
      pvVar3 = FUN_c0511fb4(_Size);
      puVar1[7] = pvVar3;
      if (pvVar3 == (void *)0x0) goto LAB_c0514928;
      memcpy(pvVar3,local_288,_Size);
    }
    puVar1[8] = param_5;
    puVar1[9] = param_6;
    FUN_c051438c((longlong *)(puVar1 + 2),param_5);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
    *puVar1 = DAT_c052e394;
    DAT_c052e3d0 = DAT_c052e3d0 + 1;
    DAT_c052e394 = puVar1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
  }
  else {
    pcVar5 = FUN_c0511fb4(sVar2 + 1);
    puVar1[1] = pcVar5;
    if (pcVar5 != (char *)0x0) {
      strcpy(pcVar5,param_1);
      goto LAB_c0514850;
    }
LAB_c0514928:
    FUN_c0514040((int)puVar1);
  }
LAB_c05148f4:
  FUN_c052c8e4(local_30);
  return;
}



/* c0514938 FUN_c0514938 */

/* Boundary evidence: original MIPS .pdata c0514938..c05149ef. Semantic name remains unreviewed. */

LPSTR FUN_c0514938(LPCWSTR param_1)

{
  uint cbMultiByte;
  LPSTR lpMultiByteStr;
  
  cbMultiByte = WideCharToMultiByte(0,0,param_1,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if ((cbMultiByte == 0) ||
     (lpMultiByteStr = FUN_c0511fb4(cbMultiByte), lpMultiByteStr == (LPSTR)0x0)) {
    lpMultiByteStr = (LPSTR)0x0;
  }
  else {
    WideCharToMultiByte(0,0,param_1,-1,lpMultiByteStr,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
  }
  return lpMultiByteStr;
}



/* c05149f0 FUN_c05149f0 */

/* Boundary evidence: original MIPS .pdata c05149f0..c0514b9f. Semantic name remains unreviewed. */

void FUN_c05149f0(int *param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  LPSTR pCVar2;
  ushort uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 != 0) {
    uVar3 = 0;
    for (piVar4 = param_1; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      if (*(short *)(piVar4 + 2) == 1) {
        uVar3 = uVar3 + 1;
      }
    }
    if (uVar3 < 0xf) {
      uVar6 = 0;
      for (piVar4 = param_1; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        if (*(short *)(piVar4 + 2) == 1) {
          uVar6 = uVar6 + 1 & 0xffff;
        }
      }
    }
    else {
      uVar6 = 0xf;
    }
    if ((uVar6 != 0) && (puVar1 = FUN_c0511fb4(0x28), puVar1 != (undefined4 *)0x0)) {
      pCVar2 = FUN_c0514938((LPCWSTR)param_1[1]);
      puVar1[1] = pCVar2;
      if ((pCVar2 != (LPSTR)0x0) && (uVar6 <= uVar6 << 2)) {
        piVar4 = FUN_c0511fb4(uVar6 << 2);
        puVar1[4] = piVar4;
        if (piVar4 != (int *)0x0) {
          uVar5 = 0;
          if (uVar6 != 0) {
            do {
              if ((short)param_1[2] == 1) {
                uVar5 = uVar5 + 1;
                *piVar4 = param_1[6];
                piVar4 = piVar4 + 1;
              }
              param_1 = (int *)*param_1;
            } while (uVar5 < uVar6);
          }
          puVar1[8] = param_2;
          puVar1[9] = param_3;
          puVar1[6] = 4;
          puVar1[5] = uVar6;
          FUN_c051438c((longlong *)(puVar1 + 2),param_2);
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
          *puVar1 = DAT_c052e394;
          DAT_c052e3d0 = DAT_c052e3d0 + 1;
          DAT_c052e394 = puVar1;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
          return;
        }
      }
      FUN_c0514040((int)puVar1);
    }
  }
  return;
}



/* c0514ba0 FUN_c0514ba0 */

/* Boundary evidence: original MIPS .pdata c0514ba0..c05150fb. Semantic name remains unreviewed. */

undefined4 FUN_c0514ba0(int *param_1,int param_2,PCNZWCH param_3,void *param_4,int param_5)

{
  WCHAR WVar1;
  bool bVar2;
  LSTATUS LVar3;
  int iVar4;
  LONG LVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  size_t sVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  PCNZWCH _Str;
  wchar_t *pwVar10;
  size_t _MaxCount;
  void *_Dst;
  wchar_t *_Source;
  uint _Size;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  DWORD dwIndex;
  undefined1 *puVar14;
  char *_Dest;
  uint uVar15;
  DWORD local_888;
  int local_884;
  HKEY local_880;
  PCNZWCH local_87c;
  HKEY local_878;
  wchar_t *local_874;
  DWORD local_870;
  int *local_86c;
  int local_868;
  wchar_t *local_864;
  void *local_860;
  _FILETIME _Stack_858;
  FILETIME FStack_850;
  wchar_t awStack_848 [12];
  undefined1 auStack_830 [304];
  WCHAR aWStack_700 [256];
  WCHAR local_500 [616];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  iVar9 = 0;
  uVar11 = 0;
  local_884 = 0;
  local_87c = param_3;
  local_86c = param_1;
  local_868 = param_2;
  local_860 = param_4;
  LVar3 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Tcpip\\Hosts",0,0x20019,&local_878);
  if (LVar3 != 0) {
LAB_c05150c4:
    FUN_c052c8e4(local_30);
    return uVar11;
  }
  GetCurrentFT(&FStack_850);
  pwVar10 = L"ipaddr";
  _Source = L"ipaddr6";
  local_864 = L"ipaddr";
  local_874 = L"ipaddr6";
LAB_c0514c58:
  dwIndex = 0;
  do {
    local_870 = dwIndex;
    if (iVar9 != 0) {
LAB_c05150b4:
      RegCloseKey(local_878);
      goto LAB_c05150c4;
    }
    local_888 = 0xff;
    LVar3 = RegEnumKeyExW(local_878,dwIndex,aWStack_700,&local_888,(LPDWORD)0x0,(LPWSTR)0x0,
                          (LPDWORD)0x0,&_Stack_858);
    if (LVar3 != 0) goto LAB_c05150b4;
    LVar3 = RegOpenKeyExW(local_878,aWStack_700,0,0x20019,&local_880);
    if (LVar3 == 0) {
      local_888 = 8;
      iVar4 = GetRegBinaryValue(local_880,L"ExpireTime",&_Stack_858,&local_888);
      if (((iVar4 != 0) && (local_888 == 8)) &&
         (LVar5 = CompareFileTime(&FStack_850,&_Stack_858), 0 < LVar5)) break;
      local_888 = 300;
      if (param_5 == 0) {
        wcscpy(awStack_848,pwVar10);
        _Size = 4;
      }
      else {
        wcscpy(awStack_848,_Source);
        _Size = 0x14;
      }
      iVar4 = GetRegBinaryValue(local_880,awStack_848,auStack_830,&local_888);
      if (iVar4 == 0) {
        RegCloseKey(local_880);
        _Source = local_874;
      }
      else {
        uVar15 = local_888 / _Size;
        if (_Size == 0) {
          trap(0x1c00);
        }
        if (0xf < (int)uVar15) {
          uVar15 = 0xf;
        }
        local_888 = 0x4ce;
        local_500[0] = L'\0';
        GetRegMultiSZValue(local_880,L"aliases",local_500,0x4ce);
        if (param_3 == (PCNZWCH)0x0) {
          iVar4 = 0;
          param_3 = local_87c;
          if (0 < (int)uVar15) {
            puVar14 = auStack_830;
            do {
              iVar9 = memcmp(puVar14,local_860,_Size);
              param_3 = local_87c;
              if (iVar9 == 0) goto LAB_c0514e9c;
              iVar4 = iVar4 + 1;
              puVar14 = puVar14 + _Size;
              iVar9 = local_884;
            } while (iVar4 < (int)uVar15);
          }
        }
        else {
          bVar2 = FUN_c0512824(param_3,aWStack_700);
          if (CONCAT31(extraout_var,bVar2) == 0) {
            _Str = local_500;
            iVar9 = local_884;
            WVar1 = local_500[0];
            while (local_884 = iVar9, WVar1 != L'\0') {
              bVar2 = FUN_c0512824(param_3,_Str);
              if (CONCAT31(extraout_var_00,bVar2) != 0) goto LAB_c0514e9c;
              sVar6 = wcslen(_Str);
              _Str = _Str + sVar6 + 1;
              iVar9 = local_884;
              WVar1 = *_Str;
            }
          }
          else {
LAB_c0514e9c:
            iVar4 = local_868;
            local_884 = 1;
            if (param_1 == (int *)0x0) {
              uVar7 = FUN_c052c76c();
              **(undefined4 **)(iVar4 + 0xc) = uVar7;
              iVar9 = 1;
              if (**(int **)(iVar4 + 0xc) != 0) {
                uVar11 = 1;
              }
            }
            else {
              iVar9 = *param_1;
              memset((undefined4 *)(iVar9 + 0x14),0,0x10);
              if (param_5 == 0) {
                *(undefined2 *)(iVar9 + 0x1c) = 2;
              }
              else {
                *(undefined2 *)(iVar9 + 0x1c) = 0x17;
              }
              *(short *)(iVar9 + 0x1e) = (short)_Size;
              sVar6 = wcslen(aWStack_700);
              local_888 = sVar6 + 1;
              CharLowerBuffW(aWStack_700,sVar6);
              _Dest = (char *)(iVar9 + 100);
              wcstombs(_Dest,aWStack_700,local_888);
              *(undefined4 *)(iVar9 + 0x14) = _Dest;
              *(int *)(iVar9 + 0x18) = iVar9 + 0x24;
              iVar4 = 0;
              pwVar10 = local_500;
              if (local_500[0] != L'\0') {
                iVar12 = 0;
                do {
                  sVar6 = wcslen(pwVar10);
                  _MaxCount = sVar6 + 1;
                  CharLowerBuffW(pwVar10,sVar6);
                  if ((iVar12 == 0x3c) || (0x280 < _MaxCount + local_888 + 1)) break;
                  wcstombs(_Dest + local_888,pwVar10,_MaxCount);
                  *(char **)(iVar12 + *(int *)(iVar9 + 0x18)) = _Dest + local_888;
                  local_888 = _MaxCount + local_888;
                  pwVar10 = pwVar10 + _MaxCount;
                  iVar4 = iVar4 + 1;
                  iVar12 = iVar12 + 4;
                } while (*pwVar10 != L'\0');
              }
              *(undefined4 *)(iVar4 * 4 + *(int *)(iVar9 + 0x18)) = 0;
              *(int *)(iVar9 + 0x20) = iVar9 + 0x2e4;
              uVar13 = 0;
              if (0 < (int)uVar15) {
                iVar4 = 0;
                puVar14 = auStack_830;
                _Dst = (void *)(iVar9 + 0x324);
                uVar8 = uVar15;
                do {
                  *(void **)(iVar4 + *(int *)(iVar9 + 0x20)) = _Dst;
                  memcpy(_Dst,puVar14,_Size);
                  uVar8 = uVar8 - 1;
                  iVar4 = iVar4 + 4;
                  puVar14 = puVar14 + _Size;
                  _Dst = (void *)((int)_Dst + _Size);
                  uVar13 = uVar15;
                } while (uVar8 != 0);
              }
              uVar11 = 1;
              *(undefined4 *)(uVar13 * 4 + *(int *)(iVar9 + 0x20)) = 0;
              iVar9 = local_884;
              param_3 = local_87c;
              dwIndex = local_870;
              param_1 = local_86c;
            }
          }
        }
        RegCloseKey(local_880);
        pwVar10 = local_864;
        _Source = local_874;
      }
    }
    dwIndex = dwIndex + 1;
  } while( true );
  RegCloseKey(local_880);
  LVar3 = RegDeleteKeyW(local_878,aWStack_700);
  if (LVar3 != 0) goto LAB_c05150c4;
  goto LAB_c0514c58;
}



/* c05150fc FUN_c05150fc */

/* Boundary evidence: original MIPS .pdata c05150fc..c0515167. Semantic name remains unreviewed. */

void FUN_c05150fc(void)

{
  uint *puVar1;
  
  puVar1 = &DAT_c052e31c;
  do {
    if (*puVar1 != 0) {
      FUN_c051f5fc(*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < -0x3fad1cb4);
  DAT_c052e3e8 = DAT_c052e3e8 + 1;
  return;
}



/* c0515168 FUN_c0515168 */

/* Boundary evidence: original MIPS .pdata c0515168..c05151b3. Semantic name remains unreviewed. */

bool FUN_c0515168(void)

{
  uint uVar1;
  
  uVar1 = FUN_c051f8b0(0x80000017,2,0,0,0);
  if (uVar1 != 0) {
    FUN_c051f5fc(uVar1);
  }
  return uVar1 != 0;
}



/* c05151b4 FUN_c05151b4 */

/* Boundary evidence: original MIPS .pdata c05151b4..c051526f. Semantic name remains unreviewed. */

undefined1 * FUN_c05151b4(undefined1 *param_1,void *param_2,size_t param_3,void *param_4)

{
  undefined1 *puVar1;
  
  *param_1 = (char)param_3;
  memcpy(param_1 + 1,param_2,param_3);
  puVar1 = param_1 + 1 + param_3;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0x1c;
  puVar1[3] = 0;
  puVar1[4] = 1;
  puVar1[8] = 0xff;
  puVar1[7] = 0;
  puVar1[6] = 0;
  puVar1[5] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0x10;
  memcpy(puVar1 + 0xb,param_4,0x10);
  return puVar1 + 0x1b;
}



/* c0515270 FUN_c0515270 */

/* Boundary evidence: original MIPS .pdata c0515270..c0515537. Semantic name remains unreviewed. */

void FUN_c0515270(uint param_1,int param_2,uint param_3,ushort *param_4)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  HLOCAL hMem;
  uint uVar8;
  char *pcVar9;
  uint local_res8 [2];
  HLOCAL local_40;
  undefined *local_3c;
  uint local_38;
  int local_30;
  int local_2c;
  
  uVar2 = DAT_c052e3ec;
  if ((((DAT_c052e3ec < 0x11) && (DAT_c052e3ec + 0x12 <= param_3)) &&
      ((*(byte *)(param_2 + 2) & 0x80) == 0)) &&
     (((*(byte *)(param_2 + 2) & 0x78) == 0 &&
      ((ushort)(*(ushort *)(param_2 + 4) << 8 | *(ushort *)(param_2 + 4) >> 8) == 1)))) {
    pcVar9 = (char *)(param_2 + 0xc);
    if (((int)*pcVar9 == DAT_c052e3ec) &&
       (pcVar6 = (char *)(param_2 + 0xd) + *pcVar9, *pcVar6 == '\0')) {
      local_3c = &DAT_c052e34c;
      local_res8[0] = param_3;
      local_38 = param_1;
      iVar3 = _stricmp(&DAT_c052e34c,(char *)(param_2 + 0xd));
      if ((((iVar3 == 0) && ((ushort)((short)pcVar6[2] | (short)pcVar6[1] << 8) == 0x1c)) &&
          ((ushort)((short)pcVar6[3] << 8 | (short)pcVar6[4]) == 1)) &&
         (iVar3 = FUN_c0513550(&local_40), hMem = local_40, iVar3 != 0)) {
        iVar3 = FUN_c05134d0(param_4,(int)local_40);
        if (iVar3 == 0) {
LAB_c05153c8:
          LocalFree(hMem);
        }
        else {
          puVar1 = local_3c;
          for (iVar7 = *(int *)(iVar3 + 0x10); local_3c = puVar1, iVar7 != 0;
              iVar7 = *(int *)(iVar7 + 8)) {
            if ((*(int *)(iVar7 + 0xc) != 0) &&
               (iVar4 = memcmp(param_4 + 4,(void *)(*(int *)(iVar7 + 0xc) + 8),0x10), iVar4 == 0))
            goto LAB_c05153c8;
            puVar1 = local_3c;
          }
          *(undefined1 *)(param_2 + 2) = 0x84;
          *(undefined2 *)(param_2 + 4) = 0;
          uVar5 = 500;
          *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) & 0x30;
          *(undefined2 *)(param_2 + 8) = 0;
          *(undefined2 *)(param_2 + 10) = 0;
          local_res8[0] = 500;
          iVar3 = *(int *)(iVar3 + 0x10);
          uVar8 = 0;
          while ((iVar3 != 0 && (hMem = local_40, uVar2 + 0x28 < uVar5))) {
            if (*(int *)(iVar3 + 0xc) != 0) {
              pcVar9 = FUN_c05151b4(pcVar9,puVar1,DAT_c052e3ec,(void *)(*(int *)(iVar3 + 0xc) + 8));
              uVar5 = local_res8[0] - (uVar2 + 0x28);
              uVar8 = uVar8 + 1;
              local_res8[0] = uVar5;
            }
            iVar3 = *(int *)(iVar3 + 8);
            hMem = local_40;
          }
          LocalFree(hMem);
          *(ushort *)(param_2 + 6) =
               (ushort)((uVar8 & 0xffff) << 8) | (ushort)((uVar8 & 0xffff) >> 8);
          if (uVar8 != 0) {
            local_30 = (int)pcVar9 - param_2;
            local_2c = param_2;
            FUN_c0521f80(local_38,&local_30,1,local_res8,0,param_4,(undefined4 *)0x1c,0,0,
                         (undefined4 *)0x0,0);
          }
        }
      }
    }
  }
  return;
}



/* c0515538 FUN_c0515538 */

/* Boundary evidence: original MIPS .pdata c0515538..c05155eb. Semantic name remains unreviewed. */

void FUN_c0515538(int *param_1,undefined4 param_2,int *param_3)

{
  undefined4 *_Src;
  uint uVar1;
  int *_Dst;
  
  if (DAT_c052e3d8 == (void *)0x0) {
    *param_3 = 0;
  }
  else {
    uVar1 = 0;
    _Src = DAT_c052e3d8;
    _Dst = param_1;
    do {
      if (_Src == (void *)0x0) break;
      memcpy(_Dst,_Src,0x60);
      uVar1 = uVar1 + 1;
      *_Dst = (int)(_Dst + 0x18);
      _Src = (undefined4 *)*_Src;
      _Dst = _Dst + 0x18;
    } while (uVar1 < 0xc);
    param_1[uVar1 * 0x18 + -0x18] = 0;
    *param_3 = (int)param_1;
  }
  return;
}



/* c05155ec FUN_c05155ec */

/* Boundary evidence: original MIPS .pdata c05155ec..c051562f. Semantic name remains unreviewed. */

void FUN_c05155ec(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
  Sleep(10000);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
  return;
}



/* c0515630 FUN_c0515630 */

/* Boundary evidence: original MIPS .pdata c0515630..c05156bf. Semantic name remains unreviewed. */

uint FUN_c0515630(void)

{
  int iVar1;
  uint uVar2;
  uint local_18 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  iVar1 = CeGenRandom(4,local_18);
  if (iVar1 == 0) {
    DAT_c052e3f8 = DAT_c052e3f8 + 1;
  }
  else {
    DAT_c052e3f8 = local_18[0] % 0x3ff + DAT_c052e3f8;
  }
  uVar2 = DAT_c052e3f8 & 0xffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  return uVar2;
}



/* c05156c0 FUN_c05156c0 */

/* Boundary evidence: original MIPS .pdata c05156c0..c0515763. Semantic name remains unreviewed. */

uint FUN_c05156c0(void)

{
  int iVar1;
  uint uVar2;
  uint local_18 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  iVar1 = CeGenRandom(4,local_18);
  if (iVar1 == 0) {
    DAT_c052e184 = DAT_c052e184 + 1;
  }
  else {
    DAT_c052e184 = local_18[0] % 0x1ff + DAT_c052e184;
  }
  if (0xffff < DAT_c052e184) {
    DAT_c052e184 = DAT_c052e184 - 0x3fff;
  }
  uVar2 = DAT_c052e184 & 0xffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  return uVar2;
}



/* c0515764 FUN_c0515764 */

/* Boundary evidence: original MIPS .pdata c0515764..c051580b. Semantic name remains unreviewed. */

undefined4 FUN_c0515764(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ushort local_28;
  undefined2 local_26;
  undefined4 local_24;
  uint local_18;
  
  local_18 = DAT_c052e2d8;
  memset(&local_28,0,0x10);
  local_28 = 2;
  iVar3 = 0;
  local_24 = param_2;
  do {
    uVar1 = FUN_c05156c0();
    local_26 = (undefined2)uVar1;
    iVar2 = FUN_c051fdb0(param_1,&local_28,0x10);
    if (iVar2 == 0) {
      FUN_c052c8e4(local_18);
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  FUN_c052c8e4(local_18);
  return 0;
}



/* c051580c FUN_c051580c */

/* Boundary evidence: original MIPS .pdata c051580c..c0515bf3. Semantic name remains unreviewed. */

undefined4
FUN_c051580c(int param_1,int param_2,short param_3,int param_4,uint *param_5,char *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  undefined2 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *_Dst;
  undefined4 *_Dst_00;
  uint uVar9;
  char *local_160;
  short local_158;
  short local_156;
  uint local_154;
  ushort local_150;
  short local_14e;
  undefined4 *local_14c;
  short local_148;
  int local_144;
  char *local_140;
  int local_13c;
  uint *local_138;
  undefined1 auStack_130 [256];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  local_138 = param_5;
  iVar8 = 0;
  local_140 = param_6;
  *(undefined4 *)(param_1 + 0xc) = 0;
  local_148 = param_3;
  local_13c = param_4;
  iVar2 = FUN_c0512384(param_1,&local_158);
  if (iVar2 == 0) {
LAB_c0515884:
    FUN_c052c8e4(local_30);
    return 0x2af9;
  }
  _Dst = (undefined4 *)(param_2 + 0x14);
  local_144 = 0;
  memset(_Dst,0,0x10);
  uVar1 = local_154 >> 0x10;
  if (((uVar1 == 0) && (local_14e == 0)) ||
     (iVar2 = FUN_c0512720(param_1,local_154 & 0xffff), iVar2 == 0)) goto LAB_c0515884;
  iVar2 = 0;
  if (uVar1 != 0) {
    local_14c = (undefined4 *)(param_2 + 0x2e4);
    pcVar6 = (char *)(param_2 + 0x324);
    _Dst_00 = (undefined4 *)(param_2 + 0x334);
    local_160 = pcVar6;
    do {
      if (0xe < iVar8) break;
      iVar3 = FUN_c05126c4(param_1,auStack_130,0x100,&local_158);
      if (iVar3 == 0) goto LAB_c0515884;
      if (local_158 == local_148) {
        *local_138 = local_154;
        if (local_148 == 1) {
          if ((local_150 != 4) || (iVar3 = FUN_c0512280(param_1,local_160,4), iVar3 == 0))
          goto LAB_c0515884;
          *(undefined2 *)(param_2 + 0x1e) = 4;
          *local_14c = local_160;
          local_14c = local_14c + 1;
          *local_14c = 0;
LAB_c0515ac0:
          local_160 = local_160 + 4;
          _Dst_00 = _Dst_00 + 5;
          pcVar6 = pcVar6 + 0x14;
          iVar8 = iVar8 + 1;
        }
        else {
          if (local_148 == 0xc) {
            if (local_150 < 0x281) {
              *(undefined2 *)(param_2 + 0x1c) = 2;
              *_Dst = (undefined1 *)(param_2 + 100);
              *(undefined2 *)(param_2 + 0x1e) = 4;
              iVar2 = FUN_c0512434(param_1,(undefined1 *)(param_2 + 100),(uint)local_150);
              if (iVar2 != 0) {
                FUN_c052c8e4(local_30);
                return 0;
              }
            }
            goto LAB_c0515884;
          }
          if (local_148 == 0x1c) {
            if ((local_150 == 0x10) && (iVar3 = FUN_c0512280(param_1,pcVar6,0x10), iVar3 != 0)) {
              if ((*pcVar6 == -2) && ((pcVar6[1] & 0xc0U) == 0x80)) {
                *_Dst_00 = *(undefined4 *)(local_13c + 0x48);
              }
              else {
                memset(_Dst_00,0,4);
              }
              *(undefined2 *)(param_2 + 0x1e) = 0x14;
              *local_14c = pcVar6;
              local_14c = local_14c + 1;
              *local_14c = 0;
              goto LAB_c0515ac0;
            }
            goto LAB_c0515884;
          }
        }
        if (local_144 == 0) {
          sVar4 = strlen(local_140);
          if (0x280 < sVar4 + 1) goto LAB_c0515884;
          if (local_156 == 1) {
            uVar5 = 2;
          }
          else {
            uVar5 = 0;
          }
          *(undefined2 *)(param_2 + 0x1c) = uVar5;
          *(int *)(param_2 + 0x20) = param_2 + 0x2e4;
          *_Dst = (char *)(param_2 + 100);
          strcpy((char *)(param_2 + 100),local_140);
          local_144 = 1;
        }
      }
      else {
        uVar9 = (uint)local_150 + *(int *)(param_1 + 0xc);
        if (*(uint *)(param_1 + 0x14) < uVar9) goto LAB_c0515884;
        *(uint *)(param_1 + 0xc) = uVar9;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar1);
    uVar7 = 0;
    if (0 < iVar8) goto LAB_c0515b60;
  }
  uVar7 = 0x2af9;
LAB_c0515b60:
  FUN_c052c8e4(local_30);
  return uVar7;
}



/* c0515bf4 FUN_c0515bf4 */

/* Boundary evidence: original MIPS .pdata c0515bf4..c0515c5b. Semantic name remains unreviewed. */

bool FUN_c0515bf4(int *param_1,short *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 1;
  if (param_3 == 0) {
    uVar2 = 2;
  }
  iVar1 = FUN_c051f8b0((int)*param_2 | 0x80000000,uVar2,0,0,0);
  *param_1 = iVar1;
  return iVar1 != 0;
}



/* c0515c5c FUN_c0515c5c */

/* Boundary evidence: original MIPS .pdata c0515c5c..c0515cd3. Semantic name remains unreviewed. */

void FUN_c0515c5c(uint *param_1,ushort *param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 auStack_18 [2];
  int local_10;
  undefined4 local_c;
  
  if (param_2 == (ushort *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else if (*param_2 == 2) {
    puVar1 = (undefined4 *)0x10;
  }
  else {
    puVar1 = (undefined4 *)0x1c;
  }
  local_10 = param_4;
  local_c = param_3;
  FUN_c0521f80(*param_1,&local_10,1,auStack_18,0,param_2,puVar1,0,0,(undefined4 *)0x0,0);
  return;
}



/* c0515cd4 FUN_c0515cd4 */

/* Boundary evidence: original MIPS .pdata c0515cd4..c0515d4f. Semantic name remains unreviewed. */

DWORD FUN_c0515cd4(uint *param_1,undefined4 param_2,int param_3,uint *param_4)

{
  DWORD DVar1;
  uint local_18 [2];
  int local_10;
  undefined4 local_c;
  
  local_18[0] = 0;
  local_10 = param_3;
  local_c = param_2;
  DVar1 = FUN_c051c258(*param_1,&local_10,1,param_4,(uint *)0x0,local_18,(void *)0x0,(uint *)0x0,
                       (undefined4 *)0x0,0,(int *)0x0,0);
  if ((DVar1 == 0) && (*param_4 == 0)) {
    DVar1 = 0x2afc;
  }
  return DVar1;
}



/* c0515d50 FUN_c0515d50 */

/* Boundary evidence: original MIPS .pdata c0515d50..c0515e3f. Semantic name remains unreviewed. */

undefined4 FUN_c0515d50(int *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (param_1[2] == 0) {
    DVar1 = GetTickCount();
    uVar3 = param_1[1];
    param_1[2] = DVar1;
  }
  else {
    DVar1 = GetTickCount();
    uVar3 = param_1[1] - (DVar1 - param_1[2]);
    if ((int)uVar3 < 1) {
      return 0x2afa;
    }
  }
  local_28 = uVar3 / 1000;
  local_1c = *param_1;
  local_18 = 0x29;
  local_20 = 0;
  local_14 = 0;
  local_24 = (uVar3 % 1000) * 1000;
  uVar2 = FUN_c052479c(1,&local_20,0,(int *)0x0,0,(int *)0x0,(int *)&local_28);
  if (local_1c == 0) {
    return 0x2afa;
  }
  return uVar2;
}



/* c0515e40 FUN_c0515e40 */

undefined4
FUN_c0515e40(undefined1 *param_1,int param_2,int param_3,uint *param_4,undefined4 *param_5)

{
  byte bVar1;
  uint uVar2;
  
  if (0xb < param_2) {
    if (CONCAT11(*param_1,param_1[1]) == *(short *)(param_3 + 0x1c)) {
      bVar1 = param_1[2];
      uVar2 = (uint)CONCAT11(bVar1,param_1[3]);
      if (((bVar1 & 0x80) != 0) && ((uVar2 & 0x7800) >> 0xb == (uint)*(ushort *)(param_3 + 0x1e))) {
        if ((param_1[3] & 0xf) == 0) {
          if (param_4 != (uint *)0x0) {
            *param_4 = bVar1 & 2;
          }
        }
        else {
          if ((uVar2 & 0xf) != 3) {
            return 0;
          }
          if (*(int *)(param_3 + 0x18) == 0) {
            return 0;
          }
        }
        return 1;
      }
    }
    else if (param_5 != (undefined4 *)0x0) {
      *param_5 = 1;
    }
  }
  return 0;
}



/* c0515f10 FUN_c0515f10 */

undefined4 FUN_c0515f10(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x2afc;
  }
  else if (param_1 == 2) {
    uVar1 = 0x2afa;
  }
  else if (param_1 == 3) {
    uVar1 = 0x2af9;
  }
  else {
    uVar1 = 5;
    if (param_1 != 5) {
      uVar1 = 0x2afb;
    }
  }
  return uVar1;
}



/* c0515f64 FUN_c0515f64 */

/* Boundary evidence: original MIPS .pdata c0515f64..c0516217. Semantic name remains unreviewed. */

DWORD FUN_c0515f64(undefined4 *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  uint uVar6;
  short *psVar7;
  DWORD DVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined1 local_40;
  undefined1 local_3f;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  psVar7 = (short *)*param_1;
  (**(code **)(*param_3 + 4))(param_3);
  local_34 = param_1[1];
  uVar10 = 0;
  iVar11 = 0;
  local_38 = 0;
  iVar9 = 0;
  local_30 = 0;
  bVar2 = FUN_c0515bf4((int *)&local_38,psVar7,1);
  uVar1 = local_38;
  if (CONCAT31(extraout_var,bVar2) == 0) {
    if (local_38 != 0) {
      FUN_c051f5fc(local_38);
    }
    DVar8 = 0x2747;
  }
  else {
    if (psVar7 == (short *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0x10;
      if (*psVar7 != 2) {
        uVar6 = 0x1c;
      }
    }
    DVar8 = FUN_c0522fc8(local_38,psVar7,uVar6);
    if (DVar8 == 0) {
      iVar3 = (**(code **)(*param_2 + 0xc))(param_2);
      uVar4 = (**(code **)(*param_2 + 0x10))(param_2);
      DVar8 = FUN_c0515c5c(&local_38,(ushort *)0x0,uVar4,iVar3);
      if (DVar8 == 0) {
        DVar8 = FUN_c0515d50((int *)&local_38);
        while (DVar8 == 0) {
          if (iVar9 == 0) {
            local_3c = 2;
            puVar5 = &local_40;
          }
          else {
            local_3c = uVar10 - iVar11;
            puVar5 = (undefined1 *)(param_3[1] + iVar11);
          }
          DVar8 = FUN_c0515cd4(&local_38,puVar5,local_3c,&local_3c);
          uVar1 = local_38;
          if (DVar8 != 0) goto joined_r0xc051618c;
          if (iVar9 == 0) {
            uVar10 = (uint)CONCAT11(local_40,local_3f);
            if (uVar10 < 0xc) {
              DVar8 = 0x2af9;
              goto joined_r0xc051618c;
            }
            iVar9 = FUN_c0512028((int)param_3,uVar10);
            if (iVar9 == 0) {
              DVar8 = 0x2747;
              uVar1 = local_38;
              goto joined_r0xc051618c;
            }
            iVar9 = 1;
          }
          else {
            param_3[5] = local_3c + param_3[5];
            if (iVar9 == 1) {
              iVar9 = FUN_c0515e40((undefined1 *)param_3[1],local_3c,(int)param_1,(uint *)0x0,
                                   (undefined4 *)0x0);
              if (iVar9 == 0) {
                if (local_3c < 0xc) {
                  DVar8 = 0x2af9;
                }
                else {
                  DVar8 = FUN_c0515f10(*(byte *)(param_3[1] + 3) & 0xf);
                }
                param_1[4] = 1;
                uVar1 = local_38;
                goto joined_r0xc051618c;
              }
              iVar9 = 2;
            }
            iVar11 = local_3c + iVar11;
            if ((int)(uVar10 - iVar11) < 1) {
              param_3[3] = 0;
              DVar8 = 0;
              uVar1 = local_38;
              goto joined_r0xc051618c;
            }
          }
          DVar8 = FUN_c0515d50((int *)&local_38);
        }
        uVar1 = local_38;
        if (DVar8 == 0x2afa) {
          param_1[5] = 1;
        }
      }
    }
joined_r0xc051618c:
    if (uVar1 != 0) {
      FUN_c051f5fc(uVar1);
    }
  }
  return DVar8;
}



/* c0516218 FUN_c0516218 */

/* Boundary evidence: original MIPS .pdata c0516218..c051631b. Semantic name remains unreviewed. */

undefined4 FUN_c0516218(int param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  size_t _Size;
  
  while( true ) {
    pcVar1 = strchr(param_2,0x2e);
    if (pcVar1 == (char *)0x0) {
      _Size = strlen(param_2);
    }
    else {
      _Size = (int)pcVar1 - (int)param_2;
    }
    if (_Size == 0) break;
    if ((0x3f < _Size) || (iVar2 = FUN_c0512028(param_1,_Size + 2), iVar2 == 0)) {
      return 0;
    }
    *(char *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc)) = (char)_Size;
    iVar2 = *(int *)(param_1 + 0xc) + 1;
    *(int *)(param_1 + 0xc) = iVar2;
    memcpy((void *)(*(int *)(param_1 + 4) + iVar2),param_2,_Size);
    *(size_t *)(param_1 + 0xc) = _Size + *(int *)(param_1 + 0xc);
    if (pcVar1 == (char *)0x0) break;
    param_2 = param_2 + _Size + 1;
  }
  *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc)) = 0;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return 1;
}



/* c051631c FUN_c051631c */

/* Boundary evidence: original MIPS .pdata c051631c..c05163d3. Semantic name remains unreviewed. */

undefined4
FUN_c051631c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,ushort param_5,
            ushort param_6,ushort param_7)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined4 uVar2;
  
  bVar1 = FUN_c0512308(param_1,param_2);
  if ((((CONCAT31(extraout_var,bVar1) == 0) ||
       (bVar1 = FUN_c0512308(param_1,param_3), CONCAT31(extraout_var_00,bVar1) == 0)) ||
      (bVar1 = FUN_c0512308(param_1,param_4), CONCAT31(extraout_var_01,bVar1) == 0)) ||
     (((bVar1 = FUN_c0512308(param_1,(uint)param_5), CONCAT31(extraout_var_02,bVar1) == 0 ||
       (bVar1 = FUN_c0512308(param_1,(uint)param_6), CONCAT31(extraout_var_03,bVar1) == 0)) ||
      (bVar1 = FUN_c0512308(param_1,(uint)param_7), CONCAT31(extraout_var_04,bVar1) == 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c05163d4 FUN_c05163d4 */

/* Boundary evidence: original MIPS .pdata c05163d4..c05165e3. Semantic name remains unreviewed. */

int FUN_c05163d4(int param_1,wchar_t *param_2,int param_3)

{
  size_t cchSrc;
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  byte abStack_58 [16];
  WCHAR aWStack_48 [16];
  uint local_28;
  
  local_28 = DAT_c052e2d8;
  puVar2 = (undefined1 *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc));
  pcVar5 = puVar2 + 1;
  iVar6 = 0;
  *puVar2 = 0x20;
  if (param_3 == 0) {
    cchSrc = wcslen(param_2);
    if (param_2[cchSrc - 1] == L'.') {
      cchSrc = cchSrc - 1;
    }
    iVar3 = LCMapStringW(0x800,0x200,param_2,cchSrc,aWStack_48,0x10);
    if (iVar3 != 0) {
      aWStack_48[iVar3] = L'\0';
      iVar3 = WideCharToMultiByte(1,0,aWStack_48,-1,(LPSTR)abStack_58,0x10,(LPCSTR)0x0,(LPBOOL)0x0);
      if (iVar3 != 0) {
        iVar3 = 0;
        goto LAB_c051657c;
      }
    }
    FUN_c052c8e4(local_28);
    iVar4 = 0;
  }
  else {
    *pcVar5 = 'C';
    puVar2[2] = 0x4b;
    pcVar5 = puVar2 + 3;
    iVar6 = 1;
    iVar3 = 1;
LAB_c051657c:
    for (; iVar4 = 1, iVar3 < 0xf; iVar3 = iVar3 + 1) {
      if (iVar6 == 0) {
        if (abStack_58[iVar3] == 0) {
          uVar1 = 0x20;
          iVar6 = iVar4;
        }
        else {
          uVar1 = (uint)abStack_58[iVar3];
        }
      }
      else {
        uVar1 = 0;
        if (param_3 == 0) {
          uVar1 = 0x20;
        }
      }
      *pcVar5 = (char)(uVar1 >> 4) + 'A';
      pcVar5[1] = ((byte)uVar1 & 0xf) + 0x41;
      pcVar5 = pcVar5 + 2;
    }
    *pcVar5 = 'A';
    pcVar5[1] = 'A';
    pcVar5[2] = '\0';
    *(char **)(param_1 + 0xc) = pcVar5 + 2 + (1 - *(int *)(param_1 + 4));
    FUN_c052c8e4(local_28);
  }
  return iVar4;
}



/* c05165e4 FUN_c05165e4 */

/* Boundary evidence: original MIPS .pdata c05165e4..c0516703. Semantic name remains unreviewed. */

undefined4 FUN_c05165e4(int *param_1,undefined4 param_2,wchar_t *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  (**(code **)(*param_1 + 4))(param_1);
  iVar1 = FUN_c0512028((int)param_1,0x240);
  if (iVar1 == 0) {
    uVar2 = 0xe;
  }
  else {
    memset((void *)param_1[1],0,0xc);
    uVar3 = 0x10;
    if (param_4 == 0) {
      uVar3 = 0;
    }
    if (param_5 == 0) {
      uVar3 = uVar3 | 0x100;
    }
    FUN_c0512308((int)param_1,param_2);
    FUN_c0512308((int)param_1,uVar3);
    FUN_c0512308((int)param_1,1);
    param_1[3] = 0xc;
    iVar1 = FUN_c05163d4((int)param_1,param_3,param_5);
    if (iVar1 == 0) {
      uVar2 = 0x54f;
    }
    else {
      uVar2 = 0x21;
      if (param_5 == 0) {
        uVar2 = 0x20;
      }
      FUN_c0512308((int)param_1,uVar2);
      FUN_c0512308((int)param_1,1);
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* c0516704 FUN_c0516704 */

/* Boundary evidence: original MIPS .pdata c0516704..c05167b3. Semantic name remains unreviewed. */

undefined4 FUN_c0516704(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c05121a8(param_1,param_2);
  if ((((iVar1 == 0) || (iVar1 = FUN_c05121a8(param_1,param_2 + 1), iVar1 == 0)) ||
      (iVar1 = FUN_c05121a8(param_1,param_2 + 2), iVar1 == 0)) ||
     (((iVar1 = FUN_c05121a8(param_1,param_2 + 3), iVar1 == 0 ||
       (iVar1 = FUN_c05121a8(param_1,param_2 + 4), iVar1 == 0)) ||
      (iVar1 = FUN_c05121a8(param_1,param_2 + 5), iVar1 == 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c05167b4 FUN_c05167b4 */

/* Boundary evidence: original MIPS .pdata c05167b4..c0516807. Semantic name remains unreviewed. */

undefined4 FUN_c05167b4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 auStack_10 [4];
  
  iVar1 = FUN_c05121a8(param_1,auStack_10);
  if ((iVar1 == 0) || (iVar1 = FUN_c05121a8(param_1,auStack_10), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c0516808 FUN_c0516808 */

/* Boundary evidence: original MIPS .pdata c0516808..c05168d7. Semantic name remains unreviewed. */

undefined4 FUN_c0516808(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < param_2) {
    do {
      while( true ) {
        bVar1 = *(byte *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4));
        uVar3 = (uint)bVar1;
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        if (uVar3 == 0) break;
        uVar4 = *(int *)(param_1 + 0xc) + uVar3;
        if (*(uint *)(param_1 + 0x14) < uVar4) {
          return 0;
        }
        if ((bVar1 & 0xc0) == 0) {
          *(uint *)(param_1 + 0xc) = uVar4;
        }
        else if ((uVar3 & 0xc0) == 0xc0) {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        }
      }
      iVar2 = FUN_c05167b4(param_1);
      if (iVar2 == 0) {
        return 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_2);
  }
  return 1;
}



/* c05168d8 FUN_c05168d8 */

/* Boundary evidence: original MIPS .pdata c05168d8..c0516bb7. Semantic name remains unreviewed. */

undefined4
FUN_c05168d8(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5,
            char *param_6)

{
  char cVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  short sVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *_Dst;
  char local_48 [2];
  ushort local_46;
  undefined2 auStack_44 [2];
  undefined4 local_40 [2];
  undefined2 uStack_38;
  ushort local_36;
  ushort local_34;
  short local_32;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar2 = FUN_c0516704(param_1,&uStack_38);
  if (iVar2 != 0) {
    _Dst = (undefined4 *)(param_2 + 0x14);
    memset(_Dst,0,0x10);
    if ((((local_36 & 0xf) == 0) && (iVar2 = FUN_c0516808(param_1,(uint)local_34), iVar2 != 0)) &&
       (iVar2 = 0, local_32 != 0)) {
      do {
        sVar5 = local_32 + -1;
        if (param_3 == 0xc) {
          iVar3 = FUN_c0512280(param_1,local_48,1);
          if (iVar3 == 0) {
            return 0x2af9;
          }
          uVar7 = local_48[0] + 1 + *(int *)(param_1 + 0xc);
          if (*(uint *)(param_1 + 0x14) < uVar7) {
            return 0x2af9;
          }
          *(uint *)(param_1 + 0xc) = uVar7;
          iVar3 = FUN_c05167b4(param_1);
          if (iVar3 == 0) {
            return 0x2af9;
          }
        }
        else {
          FUN_c0516808(param_1,1);
        }
        iVar3 = FUN_c0512208(param_1,param_5);
        if (iVar3 == 0) {
          return 0x2af9;
        }
        iVar3 = FUN_c05121a8(param_1,&local_46);
        if (iVar3 == 0) {
          return 0x2af9;
        }
        if (param_3 == 0xc) {
          uVar7 = *(int *)(param_1 + 0xc) + 1;
          cVar1 = *(char *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc));
          if (*(uint *)(param_1 + 0x14) < uVar7) {
            return 0x2af9;
          }
          *(uint *)(param_1 + 0xc) = uVar7;
          if (cVar1 == '\0') {
            return 0x2af9;
          }
          iVar2 = FUN_c0512280(param_1,(void *)(param_2 + 100),0xf);
          if (iVar2 == 0) {
            return 0x2af9;
          }
          pcVar6 = (char *)(param_2 + 0x72);
          *(undefined1 *)(param_2 + 0x73) = 0;
          cVar1 = *pcVar6;
          while (cVar1 == ' ') {
            *pcVar6 = '\0';
            pcVar6 = pcVar6 + -1;
            cVar1 = *pcVar6;
          }
          *(undefined2 *)(param_2 + 0x1c) = 2;
          *(undefined2 *)(param_2 + 0x1e) = 4;
          *_Dst = (void *)(param_2 + 100);
          return 0;
        }
        uVar7 = (uint)local_46;
        if (-1 < (int)(uVar7 - 6)) {
          puVar8 = (undefined4 *)((iVar2 + 0xb9) * 4 + param_2);
          do {
            iVar3 = FUN_c05121a8(param_1,auStack_44);
            if (iVar3 == 0) {
              return 0x2af9;
            }
            iVar3 = FUN_c0512280(param_1,local_40,4);
            if (iVar3 == 0) {
              return 0x2af9;
            }
            puVar8[0x10] = local_40[0];
            *(undefined2 *)(param_2 + 0x1e) = 4;
            *puVar8 = puVar8 + 0x10;
            puVar8 = puVar8 + 1;
            iVar2 = iVar2 + 1;
            *puVar8 = 0;
            if (iVar2 == 0xf) goto LAB_c0516ae8;
            uVar7 = uVar7 + 0xfffa & 0xffff;
          } while (-1 < (int)(uVar7 - 6));
        }
        local_32 = sVar5;
      } while (sVar5 != 0);
      if (0 < iVar2) {
LAB_c0516ae8:
        sVar4 = strlen(param_6);
        if (sVar4 + 1 < 0x281) {
          *(undefined2 *)(param_2 + 0x1c) = 2;
          *_Dst = (char *)(param_2 + 100);
          *(int *)(param_2 + 0x20) = param_2 + 0x2e4;
          strcpy((char *)(param_2 + 100),param_6);
          return 0;
        }
      }
    }
  }
  return 0x2af9;
}



/* c0516bb8 FUN_c0516bb8 */

/* Boundary evidence: original MIPS .pdata c0516bb8..c0516c97. Semantic name remains unreviewed. */

void FUN_c0516bb8(int param_1,char *param_2,int param_3)

{
  char *_Dest;
  
  memset((undefined4 *)(param_1 + 0x14),0,0x10);
  if (param_3 == 0) {
    *(undefined2 *)(param_1 + 0x1c) = 2;
    *(undefined2 *)(param_1 + 0x1e) = 4;
  }
  else {
    *(undefined2 *)(param_1 + 0x1c) = 0x17;
    *(undefined2 *)(param_1 + 0x1e) = 0x14;
  }
  _Dest = (char *)(param_1 + 100);
  if (param_2 == (char *)0xffffffff) {
    builtin_strncpy(_Dest,"loca",4);
    builtin_strncpy((char *)(param_1 + 0x68),"lhos",4);
    ((char *)(param_1 + 0x6c))[0] = 't';
    ((char *)(param_1 + 0x6c))[1] = '\0';
  }
  else if (param_2 == (char *)0x0) {
    FUN_c0513b50(_Dest,0x280);
  }
  else {
    strcpy(_Dest,param_2);
  }
  *(undefined4 *)(param_1 + 0x14) = _Dest;
  *(int *)(param_1 + 0x18) = param_1 + 0x24;
  return;
}



/* c0516c98 FUN_c0516c98 */

/* Boundary evidence: original MIPS .pdata c0516c98..c0516cfb. Semantic name remains unreviewed. */

void FUN_c0516c98(int param_1,int param_2)

{
  undefined4 *_Dst;
  
  _Dst = (undefined4 *)(param_1 + 0x324);
  *(undefined4 **)(param_1 + 0x20) = (undefined4 *)(param_1 + 0x2e4);
  *(undefined4 *)(param_1 + 0x2e4) = _Dst;
  *(undefined4 *)(*(int *)(param_1 + 0x20) + 4) = 0;
  if (param_2 == 0) {
    *_Dst = 0x100007f;
  }
  else {
    memset(_Dst,0,0x14);
    *(undefined1 *)(param_1 + 0x333) = 1;
  }
  return;
}



/* c0516cfc FUN_c0516cfc */

/* Boundary evidence: original MIPS .pdata c0516cfc..c0516d73. Semantic name remains unreviewed. */

int FUN_c0516cfc(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  puVar2 = (undefined4 *)(param_1 + 0x2e4);
  *(undefined4 **)(param_1 + 0x20) = puVar2;
  if (param_2 == 0) {
    piVar3 = (int *)(param_1 + 0x324);
    iVar1 = FUN_c0527514(puVar2,piVar3);
    if (iVar1 == 0) {
      **(undefined4 **)(param_1 + 0x20) = piVar3;
      *piVar3 = 0x100007f;
      *(undefined4 *)(*(int *)(param_1 + 0x20) + 4) = 0;
    }
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_c0527b24((int)puVar2,param_1 + 0x324);
  }
  return iVar1;
}



/* c0516d74 FUN_c0516d74 */

undefined4 FUN_c0516d74(int param_1,int param_2,int param_3)

{
  if (param_1 == 0xc) {
    if (param_3 == 0) {
      if (*(int *)((*(int *)(param_2 + 0x20) + 1) * 4 + param_2) == 6) {
        return 0;
      }
    }
    else if (*(int *)((*(int *)(param_3 + 0x20) + 1) * 4 + param_3) == 7) {
      return 0;
    }
  }
  return 1;
}



/* c0516ddc FUN_c0516ddc */

undefined4 FUN_c0516ddc(ushort *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (*param_1 != 0) {
    do {
      if (3 < iVar2) break;
      uVar3 = (uint)*param_1;
      iVar1 = 0;
      if (uVar3 != 0) {
        do {
          if (uVar3 == 0x2e) break;
          if (uVar3 < 0x30) {
            return 0;
          }
          if (0x39 < uVar3) {
            return 0;
          }
          param_1 = param_1 + 1;
          iVar1 = iVar1 * 10 + uVar3;
          uVar3 = (uint)*param_1;
          iVar1 = iVar1 + -0x30;
        } while (uVar3 != 0);
        if (0xff < iVar1) {
          return 0;
        }
      }
      *(char *)(iVar2 + param_2) = (char)iVar1;
      if (*param_1 == 0x2e) {
        param_1 = param_1 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (*param_1 != 0);
    if (iVar2 == 4) {
      return 1;
    }
  }
  return 0;
}



/* c0516e94 FUN_c0516e94 */

/* Boundary evidence: original MIPS .pdata c0516e94..c0516f53. Semantic name remains unreviewed. */

undefined4 FUN_c0516e94(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  wchar_t *_Str;
  wchar_t local_218 [256];
  uint local_18;
  
  local_18 = DAT_c052e2d8;
  _Str = local_218;
  local_218[0] = L'\0';
  iVar1 = GetRegMultiSZValue(param_1,param_2,local_218,0x1fe);
  if (iVar1 == 0) {
    FUN_c052c8e4(local_18);
    uVar2 = 0;
  }
  else {
    for (; param_4 != 0; param_4 = param_4 + -1) {
      if (*_Str == L'\0') {
        *param_3 = 0;
      }
      else {
        FUN_c0516ddc((ushort *)_Str,(int)param_3);
        sVar3 = wcslen(_Str);
        _Str = _Str + sVar3 + 1;
      }
      param_3 = param_3 + 1;
    }
    FUN_c052c8e4(local_18);
    uVar2 = 1;
  }
  return uVar2;
}



/* c0516f54 FUN_c0516f54 */

/* Boundary evidence: original MIPS .pdata c0516f54..c05170e3. Semantic name remains unreviewed. */

void FUN_c0516f54(int param_1)

{
  HKEY hKey;
  int iVar1;
  uint *_Dst;
  int local_30 [2];
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_30[0] = 0;
  hKey = (HKEY)FUN_c0512880(*(int *)(param_1 + 0x58));
  if (hKey != (HKEY)0x0) {
    GetRegDWORDValue(hKey,L"EnableDHCP",local_30);
    if (local_30[0] == 0) {
      _Dst = (uint *)(param_1 + 0x38);
      local_28 = *_Dst;
      local_24 = *(undefined4 *)(param_1 + 0x3c);
      local_20 = *(undefined4 *)(param_1 + 0x40);
      local_1c = *(undefined4 *)(param_1 + 0x44);
      memset((undefined4 *)(param_1 + 0x18),0,0x10);
      memset(_Dst,0,0x10);
      FUN_c0516e94(hKey,&DAT_c05115c0,(undefined4 *)(param_1 + 0x18),4);
      FUN_c0516e94(hKey,L"WINS",_Dst,4);
      iVar1 = memcmp(&local_28,_Dst,0x10);
      if (iVar1 != 0) {
        FUN_c0513110(1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),&local_28);
        FUN_c0513110(0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),_Dst);
      }
    }
    else {
      memset((undefined4 *)(param_1 + 0x28),0,0x10);
      memset((undefined4 *)(param_1 + 0x48),0,0x10);
      FUN_c0516e94(hKey,&DAT_c05115c0,(undefined4 *)(param_1 + 0x28),4);
      FUN_c0516e94(hKey,L"WINS",(undefined4 *)(param_1 + 0x48),4);
    }
    RegCloseKey(hKey);
  }
  return;
}



/* c05170e4 FUN_c05170e4 */

/* Boundary evidence: original MIPS .pdata c05170e4..c0517157. Semantic name remains unreviewed. */

bool FUN_c05170e4(void *param_1)

{
  int iVar1;
  undefined1 local_20;
  undefined1 auStack_1f [15];
  uint local_10;
  
  local_10 = DAT_c052e2d8;
  local_20 = 0;
  memset(auStack_1f,0,0xf);
  iVar1 = memcmp(param_1,&local_20,0x10);
  if (iVar1 != 0) {
    FUN_c052c8e4(local_10);
  }
  else {
    FUN_c052c8e4(local_10);
  }
  return iVar1 == 0;
}



/* c0517158 FUN_c0517158 */

undefined4 FUN_c0517158(int param_1,int param_2)

{
  if (param_1 == 0) {
    if ((*(uint *)(param_2 + 8) & 8) == 0) {
      if (*(short *)(param_2 + 4) == 1) {
        return 1;
      }
      if (*(short *)(param_2 + 4) == 0x1c) {
        return 1;
      }
    }
  }
  else if ((DAT_c052e374 != 0) && (*(int *)(param_1 + 8) == 0)) {
    return 1;
  }
  return 0;
}



/* c05171c0 FUN_c05171c0 */

/* Boundary evidence: original MIPS .pdata c05171c0..c0517443. Semantic name remains unreviewed. */

undefined4 FUN_c05171c0(int *param_1,int *param_2,uint *param_3,undefined2 *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined2 *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  short local_38;
  undefined1 auStack_30 [16];
  uint local_20;
  
  local_20 = DAT_c052e2d8;
  if (param_2 == (int *)0x0) {
    iVar4 = param_1[param_1[8] + 1];
    if (0 < iVar4) {
      if (iVar4 < 3) {
        local_38 = 0x3500;
      }
      else if ((3 < iVar4) && (iVar4 < 7)) {
        local_38 = -0x7700;
      }
    }
    if (iVar4 == 1) {
      iVar4 = param_1[9] + 10;
LAB_c05173e4:
      puVar3 = (uint *)(iVar4 * 4 + *param_1);
LAB_c05173f0:
      uVar6 = *puVar3;
    }
    else {
      if (iVar4 == 2) {
        iVar4 = param_1[9] + 6;
        goto LAB_c05173e4;
      }
      if (iVar4 == 4) {
        if ((param_1[9] == 0) && (param_3 != (uint *)0x0)) goto LAB_c0517394;
        iVar4 = param_1[9] + 0x12;
LAB_c05173a4:
        puVar3 = (uint *)(iVar4 * 4 + *param_1);
        goto LAB_c05173f0;
      }
      if (iVar4 == 5) {
        if ((param_1[9] != 0) || (param_3 == (uint *)0x0)) {
          iVar4 = param_1[9] + 0xe;
          goto LAB_c05173a4;
        }
LAB_c0517394:
        uVar6 = *param_3;
      }
      else {
        if (iVar4 != 6) goto LAB_c0517274;
        uVar6 = ~*(uint *)(*param_1 + 0x14) | *(uint *)(*param_1 + 0x10);
      }
    }
    if (uVar6 != 0) {
      memset(param_4,0,0x80);
      *param_4 = 2;
      param_4[1] = local_38;
      *(uint *)(param_4 + 2) = uVar6;
      FUN_c052c8e4(local_20);
      return 1;
    }
    goto LAB_c0517274;
  }
  if (param_2[param_2[8] + 1] == 3) {
    puVar2 = (undefined2 *)(param_2[9] * 0x10 + *param_2);
    local_38 = 0x3500;
LAB_c0517258:
    memcpy(auStack_30,puVar2 + 4,0x10);
  }
  else if (param_2[param_2[8] + 1] == 7) {
    puVar2 = &DAT_c052e300;
    local_38 = DAT_c052e302;
    goto LAB_c0517258;
  }
  bVar1 = FUN_c05170e4(auStack_30);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (local_38 == 0x3500) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(*param_2 + 0x48);
    }
    memset(param_4,0,0x80);
    *param_4 = 0x17;
    param_4[1] = local_38;
    memcpy(param_4 + 4,auStack_30,0x10);
    *(undefined4 *)(param_4 + 0xc) = uVar5;
    FUN_c052c8e4(local_20);
    return 1;
  }
LAB_c0517274:
  FUN_c052c8e4(local_20);
  return 0;
}



/* c0517444 FUN_c0517444 */

/* Boundary evidence: original MIPS .pdata c0517444..c05174db. Semantic name remains unreviewed. */

int FUN_c0517444(wchar_t *param_1,int *param_2)

{
  int iVar1;
  wchar_t *_Str2;
  int iVar2;
  int *piVar3;
  
  if (param_1 != (wchar_t *)0x0) {
    iVar2 = 0;
    piVar3 = param_2;
    do {
      if ((int *)*piVar3 == (int *)0x0) {
        return 0;
      }
      _Str2 = *(wchar_t **)(*(int *)*piVar3 + 0x58);
      if ((_Str2 != (wchar_t *)0x0) && (iVar1 = _wcsicmp(param_1,_Str2), iVar1 == 0)) {
        return param_2[iVar2];
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < 0xc);
  }
  return 0;
}



/* c05174dc FUN_c05174dc */

/* Boundary evidence: original MIPS .pdata c05174dc..c0517573. Semantic name remains unreviewed. */

int FUN_c05174dc(wchar_t *param_1,int *param_2)

{
  int iVar1;
  wchar_t *_Str2;
  int iVar2;
  int *piVar3;
  
  if (param_1 != (wchar_t *)0x0) {
    iVar2 = 0;
    piVar3 = param_2;
    do {
      if ((int *)*piVar3 == (int *)0x0) {
        return 0;
      }
      _Str2 = *(wchar_t **)(*(int *)*piVar3 + 0x4c);
      if ((_Str2 != (wchar_t *)0x0) && (iVar1 = _wcsicmp(param_1,_Str2), iVar1 == 0)) {
        return param_2[iVar2];
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < 0xc);
  }
  return 0;
}



/* c0517574 FUN_c0517574 */

/* Boundary evidence: original MIPS .pdata c0517574..c051766f. Semantic name remains unreviewed. */

undefined4 FUN_c0517574(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (DAT_c052e180 != 0) {
    if (param_2 == (int *)0x0) {
      if (((uint)param_1[param_1[8] + 1] < 4) || (6 < (uint)param_1[param_1[8] + 1])) {
        if (param_1[0x21] != 0) {
          return 1;
        }
        iVar1 = FUN_c05174dc(*(wchar_t **)(*param_1 + 0x58),param_3);
        if ((iVar1 != 0) && (*(int *)(iVar1 + 0x54) != 0)) {
          param_1[0x21] = 1;
          return 1;
        }
      }
      else if (param_1[0x22] != 0) {
        return 1;
      }
    }
    else {
      if (param_2[0x15] != 0) {
        return 1;
      }
      iVar1 = FUN_c0517444(*(wchar_t **)(*param_2 + 0x4c),param_3);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x84) != 0)) {
        param_2[0x15] = 1;
        return 1;
      }
    }
  }
  return 0;
}



/* c0517670 FUN_c0517670 */

void FUN_c0517670(int *param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    iVar2 = param_1[param_1[8] + 1];
    if (iVar2 < 1) {
      return;
    }
    if (iVar2 < 3) {
      uVar1 = *(uint *)(*param_1 + 0x60);
    }
    else {
      if (iVar2 < 4) {
        return;
      }
      if (iVar2 < 6) {
        uVar1 = *(uint *)(*param_1 + 100);
        if (uVar1 <= *param_3) {
          return;
        }
        goto LAB_c05176dc;
      }
      if (iVar2 != 6) {
        return;
      }
      uVar1 = *(uint *)(*param_1 + 0x68);
    }
    if (uVar1 <= *param_3) {
      return;
    }
  }
  else {
    if (param_2[param_2[8] + 1] == 3) {
      uVar1 = *(uint *)(*param_2 + 0x54);
      if (uVar1 <= *param_3) {
        return;
      }
LAB_c05176dc:
      *param_3 = uVar1;
      return;
    }
    if (param_2[param_2[8] + 1] != 7) {
      return;
    }
    uVar1 = *(uint *)(*param_2 + 0x58);
    if (uVar1 <= *param_3) {
      return;
    }
  }
  *param_3 = uVar1;
  return;
}



/* c0517780 FUN_c0517780 */

/* Boundary evidence: original MIPS .pdata c0517780..c05179f7. Semantic name remains unreviewed. */

int FUN_c0517780(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  iVar3 = 0;
  if (param_1 == 0) {
    if (*(int *)(param_2 + 0x20) < 7) {
      if (3 < *(int *)(param_2 + 0x24)) {
        *(undefined4 *)(param_2 + 0x24) = 0;
      }
      do {
        iVar1 = *(int *)((*(int *)(param_2 + 0x20) + 1) * 4 + param_2);
        if (iVar1 == 3) {
          iVar1 = *(int *)(param_2 + 0x24);
          if (iVar1 < 4) {
            piVar2 = (int *)((iVar1 + 0xf) * 4 + param_2);
            do {
              if (*piVar2 != 0) {
                *piVar2 = *piVar2 + -1;
                if (iVar1 == 0) {
                  return 1;
                }
                iVar3 = iVar3 + 1;
              }
              iVar1 = iVar1 + 1;
              piVar2 = piVar2 + 1;
            } while (iVar1 < 4);
            if (iVar3 != 0) {
              *(undefined4 *)(param_2 + 0x24) = 1;
              return iVar3;
            }
          }
        }
        else if (iVar1 == 7) {
          if ((param_3 != 0) && (DAT_c052e180 != 0)) {
            return 0;
          }
          if (*(int *)(param_2 + 0x4c) != 0) {
            *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) + -1;
            return 1;
          }
        }
        *(undefined4 *)(param_2 + 0x24) = 0;
        iVar1 = *(int *)(param_2 + 0x20) + 1;
        *(int *)(param_2 + 0x20) = iVar1;
      } while (iVar1 < 7);
    }
  }
  else if (*(int *)(param_1 + 0x20) < 7) {
    if (3 < *(int *)(param_1 + 0x24)) {
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    do {
      iVar1 = *(int *)((*(int *)(param_1 + 0x20) + 1) * 4 + param_1);
      if (iVar1 == 1) {
        local_8 = param_1 + 0x4c;
      }
      else if (iVar1 == 2) {
        local_8 = param_1 + 0x3c;
      }
      else if (iVar1 == 4) {
        local_8 = param_1 + 0x6c;
      }
      else if (iVar1 == 5) {
        local_8 = param_1 + 0x5c;
      }
      else if (iVar1 == 6) {
        if ((param_3 != 0) && (DAT_c052e180 != 0)) {
          return 0;
        }
        if (*(int *)(param_1 + 0x7c) != 0) {
          *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + -1;
          return 1;
        }
      }
      if ((0 < iVar1) &&
         (((iVar1 < 3 || ((3 < iVar1 && (iVar1 < 6)))) &&
          (iVar1 = *(int *)(param_1 + 0x24), iVar1 < 4)))) {
        piVar2 = (int *)(iVar1 * 4 + local_8);
        do {
          if (*piVar2 != 0) {
            *piVar2 = *piVar2 + -1;
            if (iVar1 == 0) {
              return 1;
            }
            iVar3 = iVar3 + 1;
          }
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar1 < 4);
        if (iVar3 != 0) {
          *(undefined4 *)(param_1 + 0x24) = 1;
          return iVar3;
        }
      }
      *(undefined4 *)(param_1 + 0x24) = 0;
      iVar1 = *(int *)(param_1 + 0x20) + 1;
      *(int *)(param_1 + 0x20) = iVar1;
    } while (iVar1 < 7);
  }
  return 0;
}



/* c05179f8 FUN_c05179f8 */

/* Boundary evidence: original MIPS .pdata c05179f8..c0517abf. Semantic name remains unreviewed. */

void FUN_c05179f8(ushort *param_1,int *param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 auStack_28 [2];
  int local_20;
  undefined4 local_1c;
  
  if (param_4 == 0) {
    uVar2 = *(uint *)(param_3 + 0x38);
  }
  else {
    uVar2 = *(uint *)(param_4 + 0x38);
  }
  if (param_1 == (ushort *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)0x10;
    if (*param_1 != 2) {
      puVar1 = (undefined4 *)0x1c;
    }
  }
  local_1c = (**(code **)(*param_2 + 0x10))(param_2);
  local_20 = (**(code **)(*param_2 + 0xc))(param_2);
  FUN_c0521f80(uVar2,&local_20,1,auStack_28,0,param_1,puVar1,0,0,(undefined4 *)0x0,0);
  return;
}



/* c0517ac0 FUN_c0517ac0 */

/* Boundary evidence: original MIPS .pdata c0517ac0..c0517b93. Semantic name remains unreviewed. */

undefined4 FUN_c0517ac0(int param_1,void *param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  DWORD DVar3;
  uint uVar4;
  uint local_20 [3];
  undefined4 local_14;
  
  local_20[1] = 0;
  local_20[0] = 0x80;
  if (param_4 == 0) {
    uVar4 = *(uint *)(param_3 + 0x38);
  }
  else {
    uVar4 = *(uint *)(param_4 + 0x38);
  }
  iVar1 = FUN_c0512028(param_1,0x240);
  if (iVar1 == 0) {
    uVar2 = 0xe;
  }
  else {
    local_14 = *(undefined4 *)(param_1 + 4);
    local_20[2] = *(undefined4 *)(param_1 + 8);
    DVar3 = FUN_c051c258(uVar4,(int *)(local_20 + 2),1,(uint *)(param_1 + 0x14),(uint *)0x0,
                         local_20 + 1,param_2,local_20,(undefined4 *)0x0,0,(int *)0x0,0);
    if ((DVar3 != 0) || (uVar2 = 0, *(uint *)(param_1 + 0x14) == 0)) {
      uVar2 = 0x2afc;
    }
  }
  return uVar2;
}



/* c0517b94 FUN_c0517b94 */

void FUN_c0517b94(int *param_1)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = (int *)DAT_c052e37c;
  if (DAT_c052e37c != 0) {
    do {
      if (piVar2 == (int *)0x0) {
        return;
      }
      piVar2[1] = piVar2[1] + 1;
      uVar1 = uVar1 + 1;
      *param_1 = (int)piVar2;
      piVar2 = (int *)*piVar2;
      param_1 = param_1 + 1;
    } while (uVar1 < 0xc);
  }
  return;
}



/* c0517bdc FUN_c0517bdc */

void FUN_c0517bdc(int *param_1)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = (int *)DAT_c052e3d8;
  if (DAT_c052e3d8 != 0) {
    do {
      if (piVar2 == (int *)0x0) {
        return;
      }
      piVar2[1] = piVar2[1] + 1;
      uVar1 = uVar1 + 1;
      *param_1 = (int)piVar2;
      piVar2 = (int *)*piVar2;
      param_1 = param_1 + 1;
    } while (uVar1 < 0xc);
  }
  return;
}



/* c0517c24 FUN_c0517c24 */

/* Boundary evidence: original MIPS .pdata c0517c24..c0517cb3. Semantic name remains unreviewed. */

undefined4 FUN_c0517c24(wchar_t *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  
  sVar1 = wcslen(param_1);
  if ((((int)sVar1 < 9) || (iVar2 = memcmp(L"L2TP LINE",param_1,0x12), iVar2 != 0)) &&
     (((int)sVar1 < 0xc || (iVar2 = memcmp(L"RAS VPN LINE",param_1,0x18), iVar2 != 0)))) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* c0517cb4 FUN_c0517cb4 */

/* Boundary evidence: original MIPS .pdata c0517cb4..c051833f. Semantic name remains unreviewed. */

undefined4
FUN_c0517cb4(int *param_1,int *param_2,int param_3,short param_4,int param_5,int param_6,
            undefined4 param_7,int param_8)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint local_44;
  int local_40;
  int *local_3c;
  undefined4 *local_38;
  uint uStack_34;
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  iVar13 = -1;
  local_40 = param_3;
  local_3c = param_1;
  if ((param_5 == 0) || (**(short **)(param_5 + 0xc) != -0x7fe4)) {
    iVar12 = 0x90;
    piVar2 = FUN_c0511fb4(param_3 * 0x90);
    *param_1 = (int)piVar2;
    if (piVar2 == (int *)0x0) {
LAB_c0517d44:
      FUN_c052c8e4(local_30);
      return 0x2747;
    }
    *piVar2 = *param_2;
    iVar3 = FUN_c0517c24(*(wchar_t **)(*param_2 + 0x58));
    bVar1 = iVar3 != 0;
    if (bVar1) {
      iVar13 = 0;
    }
    iVar3 = 1;
    if (1 < param_3) {
      iVar11 = (int)param_1 - (int)param_2;
      do {
        param_2 = param_2 + 1;
        iVar7 = *param_1;
        *(int **)(iVar11 + (int)param_2) = (int *)(iVar7 + iVar12);
        *(int *)(iVar7 + iVar12) = *param_2;
        if ((!bVar1) && (iVar7 = FUN_c0517c24(*(wchar_t **)(*param_2 + 0x58)), iVar7 != 0)) {
          bVar1 = true;
          iVar13 = iVar3;
        }
        iVar3 = iVar3 + 1;
        iVar12 = iVar12 + 0x90;
      } while (iVar3 < param_3);
    }
    iVar12 = 0;
    if (0 < param_3) {
      local_38 = &DAT_c052e2e0;
      piVar2 = param_1;
      do {
        FUN_c05137bc(*(int *)*param_1,0);
        FUN_c0516f54(*(int *)*param_1);
        pvVar4 = FUN_c0511fb4(0x100);
        *(void **)(*param_1 + 0x8c) = pvVar4;
        if (*(int *)(*param_1 + 0x8c) == 0) goto LAB_c0517d44;
        uVar5 = FUN_c051f8b0(0x80000002,2,0,0,0);
        *(undefined4 *)(*param_1 + 0x38) = uVar5;
        if (*(int *)(*param_1 + 0x38) == 0) goto LAB_c0517d44;
        *(undefined4 *)(*param_1 + 0x80) = param_7;
        local_44 = 1;
        FUN_c0526a14(*(uint *)(*param_1 + 0x38),0x8004667e,&local_44,4,(uint *)0x0,0,(uint *)0x0,0,0
                    );
        uVar6 = 0;
        piVar10 = (int *)(*(int *)*param_1 + 0x18);
        do {
          if (*piVar10 == 0x100007f) goto LAB_c0517f68;
          uVar6 = uVar6 + 1;
          piVar10 = piVar10 + 1;
        } while (uVar6 < 4);
        if (bVar1) {
          uVar5 = *(undefined4 *)(*(int *)piVar2[iVar13] + 0x10);
          uVar6 = ((int *)*param_1)[0xe];
        }
        else {
          uVar5 = *(undefined4 *)(*(int *)*param_1 + 0x10);
          uVar6 = ((int *)*param_1)[0xe];
        }
        FUN_c0515764(uVar6,uVar5);
        local_44 = 1;
        FUN_c0526a14(*(uint *)(*param_1 + 0x38),0x98000006,&local_44,4,(uint *)0x0,0,&uStack_34,0,0)
        ;
LAB_c0517f68:
        iVar3 = local_40;
        iVar11 = 0;
        do {
          puVar9 = (undefined4 *)(iVar11 + (int)local_38);
          iVar7 = *param_1 + iVar11;
          iVar11 = iVar11 + 4;
          *(undefined4 *)(iVar7 + 4) = *puVar9;
        } while (iVar11 < 0x1c);
        iVar11 = 0;
        piVar10 = (int *)(*param_1 + 4);
        do {
          if (*piVar10 == 7) {
            ((int *)(*param_1 + 4))[iVar11] = 0;
            break;
          }
          iVar11 = iVar11 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar11 < 7);
        iVar11 = 0;
        piVar10 = (int *)(*param_1 + 4);
        do {
          if (*piVar10 == 3) {
            ((int *)(*param_1 + 4))[iVar11] = 0;
            break;
          }
          iVar11 = iVar11 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar11 < 7);
        if ((param_8 != 0) || (param_4 == 0x1c)) {
          puVar8 = (uint *)*param_1;
          iVar11 = 7;
          do {
            puVar8 = puVar8 + 1;
            if ((3 < *puVar8) && (*puVar8 < 7)) {
              *puVar8 = 0;
            }
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
        if (param_6 == 0) {
          iVar3 = 0;
          do {
            piVar2 = (int *)*param_1;
            if (*(int *)((iVar3 + 6) * 4 + *piVar2) != 0) {
              piVar2[iVar3 + 0xf] = *(int *)(*piVar2 + 0x5c);
            }
            piVar2 = (int *)*param_1;
            iVar11 = (iVar3 + 10) * 4;
            if (*(int *)(*piVar2 + iVar11) != 0) {
              piVar2[iVar3 + 0x13] = *(int *)(*piVar2 + 0x5c);
            }
            piVar2 = (int *)*param_1;
            if (*(int *)((iVar3 + 0xe) * 4 + *piVar2) == 0) {
              if ((param_4 == 0xc) && (iVar3 == 0)) {
                ((int *)*param_1)[0x17] = *(int *)(*(int *)*param_1 + 0x5c);
              }
            }
            else {
              piVar2[iVar3 + 0x17] = *(int *)(*piVar2 + 0x5c);
            }
            piVar2 = (int *)*param_1;
            if (*(int *)((iVar3 + 0x12) * 4 + *piVar2) == 0) {
              if ((param_4 == 0xc) && (iVar3 == 0)) {
                ((int *)*param_1)[0x1b] = *(int *)(*(int *)*param_1 + 0x5c);
              }
            }
            else {
              piVar2[iVar3 + 0x1b] = *(int *)(*piVar2 + 0x5c);
            }
            uVar6 = FUN_c0515630();
            iVar3 = iVar3 + 1;
            *(uint *)(iVar11 + *param_1) = uVar6;
          } while (iVar3 < 4);
          ((int *)*param_1)[0x1f] = *(int *)(*(int *)*param_1 + 0x5c);
          iVar3 = local_40;
          piVar2 = local_3c;
        }
        else {
          puVar8 = (uint *)*param_1;
          if (*(uint *)(param_6 + 0x14) == 0) {
            iVar11 = 7;
            do {
              puVar8 = puVar8 + 1;
              if ((3 < *puVar8) && (*puVar8 < 7)) {
                *puVar8 = 0;
              }
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            iVar11 = 0x18;
            do {
              piVar10 = (int *)*param_1;
              if (*(int *)(*piVar10 + iVar11) != 0) {
                *(undefined4 *)((int)piVar10 + iVar11 + 0x24) = *(undefined4 *)(*piVar10 + 0x5c);
              }
              piVar10 = (int *)*param_1;
              iVar7 = iVar11 + 0x10;
              if (*(int *)(*piVar10 + iVar7) != 0) {
                *(undefined4 *)((int)piVar10 + iVar11 + 0x34) = *(undefined4 *)(*piVar10 + 0x5c);
              }
              uVar6 = FUN_c0515630();
              iVar11 = iVar11 + 4;
              *(uint *)(*param_1 + iVar7) = uVar6;
            } while (iVar11 < 0x28);
          }
          else {
            puVar8[1] = *(uint *)(param_6 + 0x14);
            iVar11 = 4;
            do {
              iVar7 = *param_1 + iVar11;
              iVar11 = iVar11 + 4;
              *(undefined4 *)(iVar7 + 4) = 0;
            } while (iVar11 < 0x1c);
            ((int *)*param_1)[0xf] = *(int *)(*(int *)*param_1 + 0x5c);
          }
        }
        iVar12 = iVar12 + 1;
        param_1 = param_1 + 1;
      } while (iVar12 < iVar3);
    }
  }
  FUN_c052c8e4(local_30);
  return 0;
}



/* c0518340 FUN_c0518340 */

/* Boundary evidence: original MIPS .pdata c0518340..c0518763. Semantic name remains unreviewed. */

undefined4
FUN_c0518340(int *param_1,undefined4 *param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined3 extraout_var_00;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint local_2c;
  
  iVar11 = 0x5c;
  puVar2 = FUN_c0511fb4(param_3 * 0x5c);
  *param_1 = (int)puVar2;
  if (puVar2 == (undefined4 *)0x0) {
LAB_c0518390:
    uVar3 = 0x2747;
  }
  else {
    *puVar2 = *param_2;
    if (1 < param_3) {
      iVar10 = (int)param_1 - (int)param_2;
      iVar8 = param_3 + -1;
      do {
        param_2 = param_2 + 1;
        puVar2 = (undefined4 *)(*param_1 + iVar11);
        *(undefined4 **)(iVar10 + (int)param_2) = puVar2;
        iVar11 = iVar11 + 0x5c;
        iVar8 = iVar8 + -1;
        *puVar2 = *param_2;
      } while (iVar8 != 0);
    }
    iVar11 = 0;
    if (0 < param_3) {
      do {
        FUN_c05137bc(0,*(int *)*param_1);
        FUN_c05129e0(*(int *)*param_1);
        pvVar4 = FUN_c0511fb4(0x100);
        *(void **)(*param_1 + 0x58) = pvVar4;
        if (*(int *)(*param_1 + 0x58) == 0) goto LAB_c0518390;
        uVar3 = FUN_c051f8b0(0x80000017,2,0,0,0);
        *(undefined4 *)(*param_1 + 0x38) = uVar3;
        if (*(int *)(*param_1 + 0x38) == 0) goto LAB_c0518390;
        local_2c = 1;
        FUN_c0526a14(*(uint *)(*param_1 + 0x38),0x8004667e,&local_2c,4,(uint *)0x0,0,(uint *)0x0,0,0
                    );
        iVar8 = 0;
        *(undefined4 *)(*param_1 + 0x50) = param_7;
        do {
          puVar2 = (undefined4 *)((int)&DAT_c052e2e0 + iVar8);
          iVar10 = iVar8 + *param_1;
          iVar8 = iVar8 + 4;
          *(undefined4 *)(iVar10 + 4) = *puVar2;
        } while (iVar8 < 0x1c);
        puVar6 = (uint *)*param_1;
        iVar8 = 7;
        do {
          puVar6 = puVar6 + 1;
          if ((3 < *puVar6) && (*puVar6 < 7)) {
            *puVar6 = 0;
          }
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        if ((param_5 != 0) && (**(short **)(param_5 + 0xc) == -0x7fe4)) {
          iVar8 = 0;
          piVar7 = (int *)(*param_1 + 4);
          do {
            if (*piVar7 == 3) {
              ((int *)(*param_1 + 4))[iVar8] = 0;
              break;
            }
            iVar8 = iVar8 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar8 < 7);
        }
        if ((param_4 == 1) || (param_4 == 0xc)) {
          iVar8 = 0;
          piVar7 = (int *)(*param_1 + 4);
          do {
            if (*piVar7 == 7) {
              ((int *)(*param_1 + 4))[iVar8] = 0;
              break;
            }
            iVar8 = iVar8 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar8 < 7);
        }
        if (param_6 == 0) {
          iVar10 = 0;
          iVar8 = 0x28;
          do {
            bVar1 = FUN_c05170e4((void *)(*(int *)*param_1 + iVar10 + 8));
            if (CONCAT31(extraout_var_00,bVar1) == 0) {
              *(undefined4 *)(*param_1 + iVar8 + 0x14) = *(undefined4 *)(*(int *)*param_1 + 0x50);
              uVar5 = FUN_c0515630();
              *(uint *)(iVar8 + *param_1) = uVar5;
            }
            iVar8 = iVar8 + 4;
            iVar10 = iVar10 + 0x10;
          } while (iVar8 < 0x38);
          ((int *)*param_1)[0x13] = *(int *)(*(int *)*param_1 + 0x50);
        }
        else if (*(int *)(param_6 + 0x14) == 0) {
          piVar9 = (int *)(*param_1 + 4);
          iVar8 = 0;
          piVar7 = piVar9;
          do {
            if (*piVar7 == 7) {
              piVar9[iVar8] = 0;
              break;
            }
            iVar8 = iVar8 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar8 < 7);
          iVar10 = 0;
          iVar8 = 0x28;
          do {
            bVar1 = FUN_c05170e4((void *)(*(int *)*param_1 + iVar10 + 8));
            if (CONCAT31(extraout_var,bVar1) == 0) {
              *(undefined4 *)(*param_1 + iVar8 + 0x14) = *(undefined4 *)(*(int *)*param_1 + 0x50);
              uVar5 = FUN_c0515630();
              *(uint *)(iVar8 + *param_1) = uVar5;
            }
            iVar8 = iVar8 + 4;
            iVar10 = iVar10 + 0x10;
          } while (iVar8 < 0x38);
        }
        else {
          *(undefined4 *)(*param_1 + 4) = 3;
          iVar8 = 4;
          do {
            iVar10 = iVar8 + *param_1;
            iVar8 = iVar8 + 4;
            *(undefined4 *)(iVar10 + 4) = 0;
          } while (iVar8 < 0x1c);
          ((int *)*param_1)[0xf] = *(int *)(*(int *)*param_1 + 0x50);
        }
        iVar11 = iVar11 + 1;
        param_1 = param_1 + 1;
      } while (iVar11 < param_3);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* c0518764 FUN_c0518764 */

/* Boundary evidence: original MIPS .pdata c0518764..c05187eb. Semantic name remains unreviewed. */

undefined4 FUN_c0518764(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  if (DAT_c052e37c != (int *)0x0) {
    piVar1 = DAT_c052e37c;
    do {
      if (*param_1 == piVar1[4]) {
        uVar2 = 1;
        break;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  return uVar2;
}



/* c05187ec FUN_c05187ec */

/* Boundary evidence: original MIPS .pdata c05187ec..c0518837. Semantic name remains unreviewed. */

void FUN_c05187ec(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0511248;
  if (param_1[1] != 0) {
    (*(code *)PTR_FUN_c052e2d0)(param_1[1],DAT_c052e44c);
  }
  param_1[1] = 0;
  return;
}



/* c0518838 FUN_c0518838 */

/* Boundary evidence: original MIPS .pdata c0518838..c0518893. Semantic name remains unreviewed. */

undefined4 * FUN_c0518838(undefined4 *param_1,uint param_2)

{
  FUN_c05187ec(param_1);
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_c052e2d0)(param_1,DAT_c052e44c);
  }
  return param_1;
}



/* c0518894 FUN_c0518894 */

/* Boundary evidence: original MIPS .pdata c0518894..c051892b. Semantic name remains unreviewed. */

bool FUN_c0518894(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

{
  LSTATUS LVar1;
  
  if (*param_1 != (HKEY)0x0) {
    RegCloseKey(*param_1);
    *param_1 = (HKEY)0x0;
  }
  param_1[1] = (HKEY)0x0;
  LVar1 = RegOpenKeyExW(param_2,param_3,0,param_4,param_1);
  return LVar1 == 0;
}



/* c051892c FUN_c051892c */

void FUN_c051892c(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* c0518940 FUN_c0518940 */

/* Boundary evidence: original MIPS .pdata c0518940..c05189a7. Semantic name remains unreviewed. */

undefined4 * FUN_c0518940(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0511610;
  FUN_c05187ec(param_1);
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_c052e2d0)(param_1,DAT_c052e44c);
  }
  return param_1;
}



/* c05189a8 AfdAddInterface */

/* Boundary evidence: original MIPS .pdata c05189a8..c0518c63. Semantic name remains unreviewed. */

undefined4
AfdAddInterface(wchar_t *param_1,uint param_2,int param_3,uint param_4,int param_5,int param_6,
               int param_7,int param_8,int param_9,int *param_10)

{
  int *piVar1;
  size_t sVar2;
  wchar_t *_Dest;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
                    /* 0x89a8  1  AfdAddInterface */
  uVar7 = param_2 & 0xffffff;
  uVar5 = 1;
  iVar6 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  piVar1 = DAT_c052e37c;
  if ((param_5 == 0) && ((param_4 & 1) == 0)) {
LAB_c0518a18:
    uVar5 = 0;
  }
  else {
    for (; (piVar1 != (int *)0x0 &&
           (((uVar7 != piVar1[2] || (param_3 != piVar1[3])) || (piVar1[0x1c] != 0))));
        piVar1 = (int *)*piVar1) {
    }
    if ((param_4 & 1) == 0) {
      if (piVar1 == (int *)0x0) {
        piVar1 = FUN_c0511fb4(0x74);
        if (piVar1 == (int *)0x0) goto LAB_c0518a18;
        sVar2 = wcslen(param_1);
        _Dest = FUN_c0511fb4((sVar2 + 1) * 2);
        piVar1[0x16] = (int)_Dest;
        if (_Dest != (wchar_t *)0x0) {
          wcscpy(_Dest,param_1);
        }
        piVar1[1] = 1;
        *piVar1 = (int)DAT_c052e37c;
        DAT_c052e37c = piVar1;
      }
      else {
        FUN_c0513110(1,piVar1[2],piVar1[3],(uint *)(piVar1 + 0xe));
      }
      piVar1[4] = param_5;
      piVar1[5] = param_6;
      piVar1[0x1a] = 500;
      iVar4 = 0;
      piVar3 = piVar1 + 6;
      iVar8 = param_8 - (int)param_10;
      piVar1[2] = uVar7;
      piVar1[3] = param_3;
      piVar1[0x17] = 2;
      piVar1[0x18] = 6000;
      piVar1[0x19] = 2000;
      do {
        if (iVar4 < param_7) {
          *piVar3 = *(int *)(iVar8 + (int)param_10);
        }
        if (iVar4 < param_9) {
          piVar3[8] = *param_10;
        }
        iVar4 = iVar4 + 1;
        param_10 = param_10 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < 4);
      FUN_c051de94();
    }
    else {
      if (piVar1 == (int *)0x0) goto LAB_c0518a18;
      iVar6 = 1;
      iVar4 = 0;
      piVar3 = piVar1 + 0xe;
      do {
        if (*piVar3 == 0) break;
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < 4);
    }
    FUN_c0513110(iVar6,uVar7,param_3,(uint *)(piVar1 + 0xe));
    if ((iVar6 != 0) && (FUN_c05145e8(), piVar1[0x1c] == 0)) {
      piVar1[0x1c] = 1;
      FUN_c0512fd0((int)piVar1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  FUN_c05138d8();
  if (DAT_c052e3d4 != 0) {
    if ((param_4 & 1) == 0) {
      FUN_c052c76c();
    }
    else {
      FUN_c052c76c();
    }
  }
  return uVar5;
}



/* c0518c64 FUN_c0518c64 */

/* Boundary evidence: original MIPS .pdata c0518c64..c0518cfb. Semantic name remains unreviewed. */

void FUN_c0518c64(void)

{
  int iVar1;
  int iVar2;
  HLOCAL pvVar3;
  HLOCAL local_18 [2];
  
  iVar1 = FUN_c0513550(local_18);
  if (iVar1 != 0) {
    iVar1 = FUN_c0513334((int)local_18[0]);
    pvVar3 = local_18[0];
    if (local_18[0] != (HLOCAL)0x0) {
      do {
        iVar2 = FUN_c0513604((int)pvVar3);
        if (iVar2 != 0) {
          iVar2 = FUN_c05131e0(*(int *)((int)pvVar3 + 0x48),*(char **)((int)pvVar3 + 0xc));
          iVar1 = iVar2 + iVar1;
        }
        pvVar3 = *(HLOCAL *)((int)pvVar3 + 8);
      } while (pvVar3 != (HLOCAL)0x0);
      LocalFree(local_18[0]);
    }
    if (iVar1 != 0) {
      FUN_c05138d8();
    }
  }
  return;
}



/* c0518cfc FUN_c0518cfc */

/* Boundary evidence: original MIPS .pdata c0518cfc..c0518d8f. Semantic name remains unreviewed. */

void FUN_c0518cfc(wchar_t *param_1,int param_2)

{
  int iVar1;
  HKEY local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_20 = (HKEY)0x0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  FUN_c0518894(&local_20,(HKEY)0x80000002,L"IDENT",0x20019);
  iVar1 = FUN_c051214c(&local_20,L"Name",(LPBYTE)param_1,param_2);
  if (iVar1 == 0) {
    wcscpy(param_1,L"WindowsCE");
  }
  FUN_c05120fc(&local_20);
  return;
}



/* c0518d90 FUN_c0518d90 */

/* Boundary evidence: original MIPS .pdata c0518d90..c0518ebf. Semantic name remains unreviewed. */

void FUN_c0518d90(wchar_t *param_1,undefined4 param_2)

{
  uint uVar1;
  size_t sVar2;
  char *_Dest;
  undefined4 *puVar3;
  char *_Dest_00;
  uint _MaxCount;
  
  uVar1 = DAT_c052e2d8;
  sVar2 = wcslen(param_1);
  _MaxCount = (sVar2 + 1) * 2;
  _Dest = FUN_c0511fb4(_MaxCount);
  if (_Dest == (char *)0x0) goto LAB_c0518e8c;
  wcstombs(_Dest,param_1,_MaxCount);
  puVar3 = FUN_c0511fb4(0x28);
  if (puVar3 != (undefined4 *)0x0) {
    sVar2 = strlen(_Dest);
    if (sVar2 + 1 != 0) {
      _Dest_00 = FUN_c0511fb4(sVar2 + 1);
      puVar3[1] = _Dest_00;
      if (_Dest_00 == (char *)0x0) {
        FUN_c0514040((int)puVar3);
        goto LAB_c0518e84;
      }
      strcpy(_Dest_00,_Dest);
    }
    puVar3[8] = 600;
    puVar3[9] = param_2;
    FUN_c051438c((longlong *)(puVar3 + 2),600);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
    *puVar3 = DAT_c052e394;
    DAT_c052e3d0 = DAT_c052e3d0 + 1;
    DAT_c052e394 = puVar3;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
  }
LAB_c0518e84:
  CTEFreeMem(_Dest);
LAB_c0518e8c:
  FUN_c052c8e4(uVar1);
  return;
}



/* c0518ec0 FUN_c0518ec0 */

/* Boundary evidence: original MIPS .pdata c0518ec0..c0518fc3. Semantic name remains unreviewed. */

undefined4
FUN_c0518ec0(int *param_1,undefined4 param_2,undefined4 param_3,char *param_4,ushort param_5,
            ushort param_6)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  
  (**(code **)(*param_1 + 4))(param_1);
  bVar1 = FUN_c0512308((int)param_1,0);
  if ((((CONCAT31(extraout_var,bVar1) != 0) &&
       (iVar2 = FUN_c051631c((int)param_1,param_3,(uint)param_6,1,0,0,param_5), iVar2 != 0)) &&
      (iVar2 = FUN_c0516218((int)param_1,param_4), iVar2 != 0)) &&
     ((bVar1 = FUN_c0512308((int)param_1,param_2), CONCAT31(extraout_var_00,bVar1) != 0 &&
      (bVar1 = FUN_c0512308((int)param_1,1), CONCAT31(extraout_var_01,bVar1) != 0)))) {
    if (0x23f < (uint)param_1[3]) {
      (**(code **)(param_1[6] + 4))();
    }
    return 0;
  }
  return 0x8007000e;
}



/* c0519010 FUN_c0519010 */

/* Boundary evidence: original MIPS .pdata c0519010..c0519057. Semantic name remains unreviewed. */

int FUN_c0519010(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 8))(param_1);
  if (iVar1 == 0) {
    iVar1 = param_1[-3] + -2;
  }
  else {
    iVar1 = param_1[-3];
  }
  return iVar1;
}



/* c0519058 FUN_c0519058 */

/* Boundary evidence: original MIPS .pdata c0519058..c051909f. Semantic name remains unreviewed. */

int FUN_c0519058(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 8))(param_1);
  if (iVar1 == 0) {
    iVar1 = param_1[-5] + 2;
  }
  else {
    iVar1 = param_1[-5];
  }
  return iVar1;
}



/* c05190b4 FUN_c05190b4 */

/* Boundary evidence: original MIPS .pdata c05190b4..c0519133. Semantic name remains unreviewed. */

undefined4 * FUN_c05190b4(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 6;
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_c0511250;
  *param_1 = &PTR_FUN_c0511610;
  FUN_c05187ec(param_1);
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_c052e2d0)(param_1,DAT_c052e44c);
  }
  return param_1;
}



/* c0519134 FUN_c0519134 */

/* Boundary evidence: original MIPS .pdata c0519134..c0519227. Semantic name remains unreviewed. */

DWORD FUN_c0519134(undefined4 *param_1,int *param_2,char *param_3,undefined4 param_4,ushort param_5)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  undefined **local_30;
  undefined1 *local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined **local_18 [2];
  
  local_20 = 0x400;
  local_2c = (undefined1 *)0x0;
  local_24 = 0;
  local_28 = 0;
  local_1c = 0;
  local_30 = &PTR_FUN_c0511688;
  local_18[0] = &PTR_LAB_c0511674;
  iVar1 = FUN_c0518ec0((int *)&local_30,param_4,(uint)param_5,param_3,0,0x100);
  if (iVar1 == 0) {
    uVar2 = local_24 + 0xfffeU & 0xffff;
    *local_2c = (char)(uVar2 >> 8);
    local_2c[1] = (char)uVar2;
    param_1[2] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    DVar3 = FUN_c0515f64(param_1,(int *)local_18,param_2);
  }
  else {
    DVar3 = 0x2747;
  }
  local_18[0] = &PTR_FUN_c0511250;
  local_30 = &PTR_FUN_c0511610;
  FUN_c05187ec(&local_30);
  return DVar3;
}



/* c0519228 FUN_c0519228 */

/* Boundary evidence: original MIPS .pdata c0519228..c0519637. Semantic name remains unreviewed. */

DWORD FUN_c0519228(undefined4 *param_1,int param_2,ushort param_3,int *param_4,int *param_5,
                  uint *param_6,undefined4 *param_7)

{
  bool bVar1;
  ushort uVar2;
  DWORD DVar3;
  undefined **ppuVar4;
  uint *puVar5;
  int iVar6;
  undefined ***pppuVar7;
  uint uVar8;
  char *local_11c;
  uint local_118;
  uint *local_114;
  undefined4 *local_110;
  undefined **local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined **local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined1 *local_d8;
  undefined4 local_d4;
  uint local_d0;
  int local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  ushort local_bc;
  undefined2 local_ba;
  undefined4 auStack_b8 [2];
  undefined1 auStack_b0 [128];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  bVar1 = param_5 == (int *)0x0;
  local_114 = param_6;
  local_f8 = 0x400;
  local_e0 = 0x400;
  local_104 = 0;
  local_fc = 0;
  local_100 = 0;
  local_f4 = 0;
  local_108 = &PTR_FUN_c051161c;
  local_ec = 0;
  local_e4 = 0;
  local_e8 = 0;
  local_dc = 0;
  local_f0 = &PTR_FUN_c0511668;
  if (bVar1) {
    local_11c = (char *)param_4[0x23];
    puVar5 = (uint *)(param_4 + param_4[8] + 1);
  }
  else {
    local_11c = (char *)param_5[0x16];
    puVar5 = (uint *)(param_5 + param_5[8] + 1);
  }
  uVar8 = *puVar5;
  if ((uVar8 < 4) || (pppuVar7 = &local_f0, 6 < uVar8)) {
    pppuVar7 = &local_108;
  }
  local_110 = param_1;
  DVar3 = FUN_c0517ac0((int)pppuVar7,auStack_b0,(int)param_4,(int)param_5);
  if (DVar3 != 0) goto LAB_c05193a4;
  if ((undefined **)0xb < pppuVar7[5]) {
    ppuVar4 = pppuVar7[1];
    uVar2 = CONCAT11(*(undefined1 *)ppuVar4,*(undefined1 *)((int)ppuVar4 + 1));
    if (bVar1) {
      iVar6 = 0;
      puVar5 = (uint *)(param_4 + 10);
      do {
        if ((uint)uVar2 == *puVar5) goto LAB_c051942c;
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar6 < 4);
    }
    else {
      iVar6 = 0;
      puVar5 = (uint *)(param_5 + 10);
      do {
        if ((uint)uVar2 == *puVar5) goto LAB_c051942c;
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar6 < 4);
    }
  }
  goto LAB_c05193a0;
LAB_c051942c:
  if (param_2 == 0) {
    local_c0 = 1;
  }
  else {
    local_c0 = *(undefined4 *)(param_2 + 0x18);
  }
  if (bVar1) {
    local_cc = 0;
  }
  else {
    local_cc = *param_5;
  }
  local_d0 = (uint)(uVar8 == 7);
  if (bVar1) {
    local_d4 = *(undefined4 *)(*param_4 + 0x60);
  }
  else {
    local_d4 = *(undefined4 *)(*param_5 + 0x54);
  }
  local_d8 = auStack_b0;
  local_ba = 0;
  local_c4 = 0;
  local_c8 = 0;
  local_118 = 0;
  local_bc = uVar2;
  iVar6 = FUN_c0515e40((undefined1 *)ppuVar4,(int)pppuVar7[5],(int)&local_d8,&local_118,auStack_b8);
  if (iVar6 != 0) {
    if (local_118 != 0) {
      (*(code *)(*pppuVar7)[1])(pppuVar7);
      DVar3 = FUN_c0519134(&local_d8,(int *)pppuVar7,local_11c,(uint)param_3,uVar2);
      if (DVar3 != 0) goto LAB_c05193a4;
    }
    puVar5 = local_114;
    if (param_2 == 0) {
      if (*(short *)local_110[3] == -0x7fe4) goto LAB_c05195f8;
      if (bVar1) {
        if ((uVar8 < 4) || (6 < uVar8)) {
          param_4[0x21] = 1;
          goto LAB_c0519608;
        }
        param_4[0x22] = 1;
        *param_7 = 1;
LAB_c05195ac:
        iVar6 = 0;
      }
      else {
        param_5[0x15] = 1;
LAB_c0519608:
        *param_7 = 1;
        if (bVar1) goto LAB_c05195ac;
        iVar6 = *param_5;
      }
      iVar6 = (*(code *)(*pppuVar7)[2])(pppuVar7,*local_110,param_3,iVar6,local_114,local_11c);
      if (iVar6 != 0) goto LAB_c05193a0;
      if (*puVar5 < 0x259) {
        if ((uVar8 == 6) && (*puVar5 == 0)) {
          *puVar5 = 600;
        }
      }
      else {
        *puVar5 = 600;
      }
    }
    else {
      if (bVar1) {
        param_4[0x21] = 1;
      }
      else {
        param_5[0x15] = 1;
      }
      *param_7 = 1;
      iVar6 = FUN_c052c764();
      if (iVar6 != 0) {
        if (iVar6 == 0xe) {
          DVar3 = 0x2747;
          goto LAB_c05193a4;
        }
        goto LAB_c05193a0;
      }
    }
LAB_c05195f8:
    DVar3 = 0;
    goto LAB_c05193a4;
  }
LAB_c05193a0:
  DVar3 = 0x2af9;
LAB_c05193a4:
  local_f0 = &PTR_FUN_c0511610;
  FUN_c05187ec(&local_f0);
  local_108 = &PTR_FUN_c0511610;
  FUN_c05187ec(&local_108);
  FUN_c052c8e4(local_30);
  return DVar3;
}



/* c0519638 FUN_c0519638 */

/* Boundary evidence: original MIPS .pdata c0519638..c051969f. Semantic name remains unreviewed. */

undefined4 * FUN_c0519638(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0511610;
  FUN_c05187ec(param_1);
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_c052e2d0)(param_1,DAT_c052e44c);
  }
  return param_1;
}



/* c05196a0 FUN_c05196a0 */

/* Boundary evidence: original MIPS .pdata c05196a0..c051971f. Semantic name remains unreviewed. */

undefined4 * FUN_c05196a0(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 6;
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_c0511250;
  *param_1 = &PTR_FUN_c0511610;
  FUN_c05187ec(param_1);
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_c052e2d0)(param_1,DAT_c052e44c);
  }
  return param_1;
}



/* c0519720 FUN_c0519720 */

/* Boundary evidence: original MIPS .pdata c0519720..c0519787. Semantic name remains unreviewed. */

undefined4 * FUN_c0519720(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0511610;
  FUN_c05187ec(param_1);
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_c052e2d0)(param_1,DAT_c052e44c);
  }
  return param_1;
}



/* c0519788 FUN_c0519788 */

/* Boundary evidence: original MIPS .pdata c0519788..c0519ce7. Semantic name remains unreviewed. */

int FUN_c0519788(int param_1,int param_2,ushort param_3,wchar_t *param_4,int *param_5,int *param_6,
                uint *param_7,int *param_8,int param_9,int param_10)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  ushort uVar6;
  uint uVar7;
  ushort *puVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  LPSTR lpMultiByteStr;
  undefined **local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined **local_f0 [2];
  undefined **local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined **local_d0;
  LPSTR local_cc;
  uint local_c8;
  undefined ***local_c4;
  uint *local_c0;
  uint local_bc;
  uint *local_b8;
  int local_b4;
  ushort auStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  iVar11 = 0;
  local_b8 = param_7;
  local_108 = &PTR_FUN_c0511688;
  local_f0[0] = &PTR_LAB_c0511674;
  local_104 = 0;
  local_fc = 0;
  local_100 = 0;
  local_f8 = 0x400;
  local_f4 = 0;
  local_e4 = 0;
  local_dc = 0;
  local_e0 = 0;
  local_d8 = 0x400;
  local_d4 = 0;
  local_e8 = &PTR_FUN_c051165c;
  local_d0 = &PTR_LAB_c0511648;
  if (param_1 == 0) {
    local_c0 = (uint *)0x0;
  }
  else {
    local_c0 = *(uint **)(param_1 + 8);
  }
  local_bc = (uint)(local_c0 != (uint *)0x0);
  local_c8 = (uint)(param_6 != (int *)0x0);
  local_b4 = param_2;
  do {
    iVar2 = FUN_c0517780((int)param_5,(int)param_6,param_9);
    if (iVar2 == 0) goto LAB_c0519c7c;
    iVar3 = FUN_c0517574(param_5,param_6,param_8);
  } while (iVar3 != 0);
  if ((param_6 != (int *)0x0) == 0) {
    iVar12 = param_5[9];
    puVar9 = (uint *)(param_5 + param_5[8] + 1);
    iVar3 = param_5[0x20];
    lpMultiByteStr = (LPSTR)param_5[0x23];
    puVar8 = (ushort *)(param_5 + iVar12 + 10);
  }
  else {
    iVar12 = param_6[9];
    puVar9 = (uint *)(param_6 + param_6[8] + 1);
    iVar3 = param_6[0x14];
    lpMultiByteStr = (LPSTR)param_6[0x16];
    puVar8 = (ushort *)(param_6 + iVar12 + 10);
  }
  uVar10 = *puVar9;
  uVar1 = *puVar8;
  uVar6 = 0x100;
  if (uVar10 == 7) {
    uVar6 = 0;
  }
  local_cc = lpMultiByteStr;
  iVar4 = FUN_c0516d74((uint)param_3,(int)param_5,(int)param_6);
  if ((iVar4 == 0) || (((param_10 != 0 && (3 < uVar10)) && (uVar10 < 8)))) {
LAB_c0519c7c:
    local_d0 = &PTR_FUN_c0511250;
    local_e8 = &PTR_FUN_c0511610;
    FUN_c05187ec(&local_e8);
    local_f0[0] = &PTR_FUN_c0511250;
    local_108 = &PTR_FUN_c0511610;
    FUN_c05187ec(&local_108);
    FUN_c052c8e4(local_30);
    iVar11 = 0;
  }
  else {
    iVar4 = WideCharToMultiByte(0xfde9,0,param_4,-1,lpMultiByteStr,0x100,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((iVar4 == 0) &&
       (iVar4 = WideCharToMultiByte(0,0,param_4,-1,lpMultiByteStr,0x100,(LPCSTR)0x0,(LPBOOL)0x0),
       iVar4 == 0)) {
      iVar11 = 0;
    }
    else {
      if ((uVar10 < 4) || (6 < uVar10)) {
        local_c4 = local_f0;
        if ((iVar3 != 0) && (uVar10 != 7)) {
          FUN_c0513a88(param_5,param_6,lpMultiByteStr + iVar4 + -1,0x100 - (iVar4 + -1));
        }
      }
      else {
        local_c4 = &local_d0;
      }
      do {
        iVar2 = iVar2 + -1;
        if ((local_b4 == 0) || (*(void **)(local_b4 + 0x10) == (void *)0x0)) {
          iVar3 = FUN_c05171c0(param_5,param_6,local_c0,auStack_b0);
          if (iVar3 != 0) goto LAB_c0519a98;
        }
        else {
          memcpy(auStack_b0,*(void **)(local_b4 + 0x10),0x80);
LAB_c0519a98:
          if ((uVar10 < 4) || (6 < uVar10)) {
            iVar3 = FUN_c0518ec0((int *)&local_108,(uint)param_3,(uint)uVar1,local_cc,0,uVar6);
          }
          else {
            iVar3 = FUN_c05165e4((int *)&local_e8,(uint)uVar1,param_4,(uint)(uVar10 == 6),local_bc);
          }
          if ((iVar3 != 0) ||
             ((((5 < uVar10 && (uVar10 < 8)) && (param_4 != (wchar_t *)0x0)) &&
              ((puVar5 = FUN_c05143f4(param_4,(uint)(param_3 != 0x1c)), puVar5 != (undefined4 *)0x0
               && (uVar7 = puVar5[9], LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360),
                  (uVar7 & 6) == 4)))))) break;
          iVar3 = FUN_c05179f8(auStack_b0,(int *)local_c4,(int)param_5,(int)param_6);
          if (iVar3 == 0) {
            iVar11 = iVar11 + 1;
            FUN_c0517670(param_5,param_6,local_b8);
          }
          if (iVar12 == 0) break;
          if (local_c8 == 0) {
            iVar3 = param_5[9];
            param_5[9] = iVar3 + 1;
            if ((3 < iVar3 + 1) || (iVar2 == 0)) {
              param_5[9] = iVar12;
              break;
            }
          }
          else {
            iVar3 = param_6[9];
            param_6[9] = iVar3 + 1;
            if ((3 < iVar3 + 1) || (iVar2 == 0)) {
              param_6[9] = iVar12;
              break;
            }
          }
        }
      } while (iVar2 != 0);
    }
    local_d0 = &PTR_FUN_c0511250;
    local_e8 = &PTR_FUN_c0511610;
    FUN_c05187ec(&local_e8);
    local_f0[0] = &PTR_FUN_c0511250;
    local_108 = &PTR_FUN_c0511610;
    FUN_c05187ec(&local_108);
    FUN_c052c8e4(local_30);
  }
  return iVar11;
}



/* c0519ce8 FUN_c0519ce8 */

/* Boundary evidence: original MIPS .pdata c0519ce8..c051a53f. Semantic name remains unreviewed. */

DWORD FUN_c0519ce8(undefined4 *param_1,int param_2,wchar_t *param_3,uint *param_4,ushort param_5,
                  int *param_6,undefined4 param_7,int param_8)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  DWORD DVar8;
  int iVar9;
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined *puVar13;
  undefined4 *puVar14;
  uint local_390;
  DWORD local_38c;
  int *local_388;
  undefined *local_384;
  int local_380;
  int local_37c;
  uint local_378;
  undefined4 *local_374;
  int local_370;
  int local_36c;
  wchar_t *local_368;
  DWORD local_364;
  int local_360;
  uint *local_35c;
  LPCRITICAL_SECTION local_358;
  uint local_350;
  int local_34c;
  int local_348 [14];
  int local_310 [14];
  int local_2d8 [14];
  int aiStack_2a0 [14];
  int local_268;
  int local_264;
  undefined4 local_260;
  undefined4 local_25c [141];
  
  lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c052e39c;
  local_358 = (LPCRITICAL_SECTION)&DAT_c052e39c;
  iVar12 = 0;
  local_384 = &DAT_c052e39c;
  local_37c = param_2;
  local_374 = param_1;
  local_368 = param_3;
  local_35c = param_4;
  do {
    local_360 = iVar12;
    memset(local_310,0,0x34);
    memset(local_348,0,0x34);
    EnterCriticalSection(lpCriticalSection);
    if (DAT_c052e378 != 0) {
      DAT_c052e378 = DAT_c052e378 + -1;
      LeaveCriticalSection(lpCriticalSection);
      FUN_c0518c64();
      EnterCriticalSection(lpCriticalSection);
    }
    iVar2 = FUN_c0517b94(local_2d8);
    local_36c = iVar2;
    iVar3 = FUN_c0517bdc(aiStack_2a0);
    local_370 = iVar3;
    LeaveCriticalSection(lpCriticalSection);
    if ((iVar3 == 0) && (iVar2 == 0)) {
      DVar8 = 0x2742;
    }
    else {
      if ((param_1 != (undefined4 *)0x0) && (*(short *)param_1[3] == -0x7fe4)) {
        EnterCriticalSection(lpCriticalSection);
        if (0 < iVar2) {
          piVar7 = local_2d8;
          do {
            if (*piVar7 != 0) {
              FUN_c0512fd0(*piVar7);
            }
            iVar2 = iVar2 + -1;
            piVar7 = piVar7 + 1;
          } while (iVar2 != 0);
        }
        LeaveCriticalSection(lpCriticalSection);
        iVar2 = 0;
        local_36c = 0;
      }
      if (((iVar2 == 0) ||
          (DVar8 = FUN_c0517cb4(local_310,local_2d8,iVar2,param_5,(int)param_1,param_2,param_7,
                                param_8), DVar8 == 0)) &&
         ((iVar3 == 0 ||
          (DVar8 = FUN_c0518340(local_348,aiStack_2a0,iVar3,(uint)param_5,(int)param_1,param_2,
                                param_7), DVar8 == 0)))) {
        local_38c = 0x2af9;
        local_378 = 0;
        local_364 = GetTickCount();
        DVar8 = 0x2af9;
        do {
          local_380 = 1;
          do {
            if (local_380 != 0) {
              puVar13 = (undefined *)0x0;
              local_380 = 0;
              local_378 = 0;
              local_390 = 0;
              local_384 = (undefined *)0x0;
              if (0 < iVar3) {
                piVar7 = local_348;
                do {
                  iVar12 = FUN_c0519788((int)param_1,param_2,param_5,local_368,(int *)0x0,
                                        (int *)*piVar7,&local_390,local_310,*param_6,param_8);
                  puVar13 = puVar13 + iVar12;
                  iVar3 = iVar3 + -1;
                  piVar7 = piVar7 + 1;
                } while (iVar3 != 0);
                local_378 = local_390;
                DVar8 = local_38c;
                iVar2 = local_36c;
                local_384 = puVar13;
              }
              if (0 < iVar2) {
                piVar7 = local_310;
                puVar13 = local_384;
                local_390 = local_378;
                do {
                  iVar12 = FUN_c0519788((int)param_1,param_2,param_5,local_368,(int *)*piVar7,
                                        (int *)0x0,&local_390,local_348,*param_6,param_8);
                  puVar13 = puVar13 + iVar12;
                  iVar2 = iVar2 + -1;
                  piVar7 = piVar7 + 1;
                } while (iVar2 != 0);
                local_378 = local_390;
                DVar8 = local_38c;
                iVar2 = local_36c;
                local_384 = puVar13;
              }
              lpCriticalSection = local_358;
              iVar12 = local_360;
              local_390 = local_378;
              if (local_384 == (undefined *)0x0) goto LAB_c051a3a8;
              local_364 = GetTickCount();
            }
            iVar12 = local_370;
            uVar5 = 0;
            local_388 = &local_268;
            local_390 = 0;
            iVar3 = 0;
            puVar11 = &local_260;
            puVar14 = local_25c;
            piVar7 = &local_264;
            iVar9 = 0;
            do {
              if (((iVar3 < iVar12) &&
                  (piVar6 = *(int **)((int)local_348 + iVar9), uVar5 = local_390, piVar6[0xe] != 0))
                 && (iVar4 = FUN_c0517574((int *)0x0,piVar6,local_310), uVar5 = local_390,
                    iVar4 == 0)) {
                *local_388 = 0;
                *piVar7 = piVar6[0xe];
                local_390 = local_390 + 1;
                local_388 = local_388 + 6;
                *puVar14 = 0;
                *puVar11 = 0x29;
                piVar7 = piVar7 + 6;
                puVar14 = puVar14 + 6;
                puVar11 = puVar11 + 6;
                uVar5 = local_390;
              }
              if (((iVar3 < iVar2) &&
                  (piVar6 = *(int **)((int)local_310 + iVar9), uVar5 = local_390, piVar6[0xe] != 0))
                 && (iVar4 = FUN_c0517574(piVar6,(int *)0x0,local_348), uVar5 = local_390,
                    iVar4 == 0)) {
                *local_388 = 0;
                *piVar7 = piVar6[0xe];
                local_390 = local_390 + 1;
                local_388 = local_388 + 6;
                *puVar14 = 0;
                *puVar11 = 0x29;
                piVar7 = piVar7 + 6;
                puVar14 = puVar14 + 6;
                puVar11 = puVar11 + 6;
                uVar5 = local_390;
              }
              uVar10 = local_378;
              iVar9 = iVar9 + 4;
              iVar3 = iVar3 + 1;
            } while (iVar9 < 0x30);
            iVar3 = local_370;
            DVar8 = local_38c;
            param_1 = local_374;
            param_2 = local_37c;
            if (uVar5 == 0) break;
            local_350 = local_378 / 1000;
            local_34c = (local_378 % 1000) * 1000;
            iVar9 = FUN_c052479c(uVar5,&local_268,0,(int *)0x0,0,(int *)0x0,(int *)&local_350);
            puVar11 = local_374;
            iVar12 = local_37c;
            uVar1 = local_390;
            iVar3 = local_370;
            DVar8 = local_38c;
            param_1 = local_374;
            param_2 = local_37c;
            if (iVar9 != 0) break;
            iVar3 = 0;
            puVar13 = local_384;
            if (0 < (int)uVar5) {
              piVar7 = &local_264;
              do {
                iVar2 = *piVar7;
                if (iVar2 != 0) {
                  local_388 = (int *)0x0;
                  iVar4 = 0;
                  iVar9 = 0;
                  do {
                    if ((*(int *)((int)local_348 + iVar9) != 0) &&
                       (iVar2 == *(int *)(*(int *)((int)local_348 + iVar9) + 0x38))) {
                      DVar8 = FUN_c0519228(puVar11,iVar12,param_5,(int *)0x0,(int *)local_348[iVar4]
                                           ,local_35c,&local_388);
LAB_c051a2fc:
                      puVar13 = puVar13 + -1;
                      if (local_388 != (int *)0x0) {
                        *param_6 = 1;
                      }
                      break;
                    }
                    if ((*(int *)((int)local_310 + iVar9) != 0) &&
                       (iVar2 == *(int *)(*(int *)((int)local_310 + iVar9) + 0x38))) {
                      DVar8 = FUN_c0519228(puVar11,iVar12,param_5,(int *)local_310[iVar4],(int *)0x0
                                           ,local_35c,&local_388);
                      goto LAB_c051a2fc;
                    }
                    iVar9 = iVar9 + 4;
                    iVar4 = iVar4 + 1;
                  } while (iVar9 < 0x30);
                  iVar2 = local_36c;
                  uVar10 = local_378;
                  if (DVar8 == 0) break;
                }
                iVar3 = iVar3 + 1;
                piVar7 = piVar7 + 6;
                iVar2 = local_36c;
                uVar10 = local_378;
              } while (iVar3 < (int)uVar1);
            }
            local_384 = puVar13;
            local_38c = DVar8;
            DVar8 = GetTickCount();
            if (uVar10 < DVar8 - local_364) {
              local_380 = 1;
            }
            else {
              local_378 = uVar10 - (DVar8 - local_364);
            }
            DVar8 = local_38c;
            lpCriticalSection = local_358;
            param_1 = local_374;
            iVar12 = local_360;
            param_2 = local_37c;
            if (local_38c == 0) goto LAB_c051a3a8;
            iVar3 = local_370;
          } while (local_384 != (undefined *)0x0);
        } while( true );
      }
      iVar12 = 1;
LAB_c051a3a8:
      iVar3 = 0;
      do {
        iVar2 = *(int *)((int)local_348 + iVar3);
        if (iVar2 != 0) {
          uVar5 = *(uint *)(iVar2 + 0x38);
          if (uVar5 != 0) {
            *(undefined4 *)(iVar2 + 0x38) = 0;
            FUN_c051f5fc(uVar5);
          }
          if (*(int *)(iVar2 + 0x58) != 0) {
            *(undefined4 *)(iVar2 + 0x58) = 0;
            CTEFreeMem();
          }
        }
        iVar2 = *(int *)((int)local_310 + iVar3);
        if (iVar2 != 0) {
          uVar5 = *(uint *)(iVar2 + 0x38);
          if (uVar5 != 0) {
            *(undefined4 *)(iVar2 + 0x38) = 0;
            FUN_c051f5fc(uVar5);
          }
          if (*(int *)(iVar2 + 0x8c) != 0) {
            *(undefined4 *)(iVar2 + 0x8c) = 0;
            CTEFreeMem();
          }
        }
        iVar3 = iVar3 + 4;
      } while (iVar3 < 0x30);
      EnterCriticalSection(lpCriticalSection);
      iVar3 = 0;
      do {
        if ((*(int **)((int)local_348 + iVar3) != (int *)0x0) &&
           (iVar2 = **(int **)((int)local_348 + iVar3), iVar2 != 0)) {
          FUN_c0513070(iVar2);
        }
        if ((*(int **)((int)local_310 + iVar3) != (int *)0x0) &&
           (iVar2 = **(int **)((int)local_310 + iVar3), iVar2 != 0)) {
          FUN_c0512fd0(iVar2);
        }
        iVar3 = iVar3 + 4;
      } while (iVar3 < 0x30);
      LeaveCriticalSection(lpCriticalSection);
      if (local_348[0] != 0) {
        CTEFreeMem();
      }
      if (local_310[0] != 0) {
        CTEFreeMem();
      }
      if (DVar8 == 0) {
        return 0;
      }
    }
    if (iVar12 != 0) {
      return DVar8;
    }
    if (DAT_c052e3e0 == (code *)0x0) {
      return DVar8;
    }
    iVar12 = (*DAT_c052e3e0)();
    if (iVar12 == 0) {
      return DVar8;
    }
    iVar12 = 1;
  } while( true );
}



/* c051a540 FUN_c051a540 */

/* Boundary evidence: original MIPS .pdata c051a540..c051a697. Semantic name remains unreviewed. */

void FUN_c051a540(undefined4 *param_1,int param_2,wchar_t *param_3,uint *param_4,ushort param_5,
                 int *param_6)

{
  wchar_t wVar1;
  bool bVar2;
  DWORD DVar3;
  undefined4 uVar4;
  int iVar5;
  wchar_t *pwVar6;
  int iVar7;
  
  iVar7 = 0;
  bVar2 = false;
  if (param_5 != 0xc) {
    iVar5 = 1;
    wVar1 = *param_3;
    pwVar6 = param_3;
    while (wVar1 != L'\0') {
      pwVar6 = pwVar6 + 1;
      if (wVar1 == L'.') {
        bVar2 = true;
      }
      iVar5 = iVar5 + 1;
      if (0x10 < iVar5) {
        iVar7 = 1;
      }
      wVar1 = *pwVar6;
    }
    if (param_5 != 0xc) {
      uVar4 = 0;
      if (!bVar2) {
        uVar4 = 1;
      }
      goto LAB_c051a5f4;
    }
  }
  uVar4 = 0;
LAB_c051a5f4:
  DVar3 = FUN_c0519ce8(param_1,param_2,param_3,param_4,param_5,param_6,uVar4,iVar7);
  if ((((param_5 != 0xc) && (DVar3 != 0)) && (*param_6 != 0)) && (bVar2)) {
    FUN_c0519ce8(param_1,param_2,param_3,param_4,param_5,param_6,1,1);
  }
  return;
}



/* c051a698 FUN_c051a698 */

/* Boundary evidence: original MIPS .pdata c051a698..c051ac2b. Semantic name remains unreviewed. */

int FUN_c051a698(int *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  undefined4 *puVar5;
  PCNZWCH pWVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  wchar_t *_Str1;
  uint uVar10;
  uint uVar11;
  int local_240;
  uint local_23c;
  uint local_238 [2];
  wchar_t awStack_230 [256];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  if (param_1 == (int *)0x0) {
    _Str1 = (wchar_t *)*param_2;
    piVar9 = (int *)0x0;
  }
  else {
    _Str1 = (wchar_t *)param_1[1];
    piVar9 = (int *)param_1[2];
  }
  iVar2 = FUN_c0517158((int)param_1,(int)param_2);
  iVar7 = DAT_c052e3b4;
  if (param_1 == (int *)0x0) {
    iVar7 = 0;
  }
  local_240 = 0;
  if (param_1 == (int *)0x0) {
    uVar11 = (uint)*(ushort *)(param_2 + 1);
  }
  else {
    uVar11 = (uint)*(ushort *)param_1[3];
    if (piVar9 != (int *)0x0) {
      uVar11 = 0xc;
    }
  }
  uVar8 = (uint)(uVar11 == 0x1c);
  local_23c = uVar11;
  if (piVar9 == (int *)0x0) {
    iVar3 = _wcsicmp(_Str1,L"localhost");
    if ((iVar3 == 0) || (iVar3 = _wcsicmp(_Str1,L"loopback"), iVar3 == 0)) {
      if (param_1 != (int *)0x0) {
        FUN_c0516bb8(*param_1,(char *)0x0,uVar8);
        FUN_c0516c98(*param_1,uVar8);
        goto LAB_c051a7d0;
      }
      uVar4 = FUN_c052c76c();
      *(undefined4 *)param_2[3] = uVar4;
      iVar7 = *(int *)param_2[3];
    }
    else {
      FUN_c0518cfc(awStack_230,0xff);
      bVar1 = FUN_c0512824(_Str1,awStack_230);
      pWVar6 = _Str1;
      if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_c051a8c0;
      if (param_1 != (int *)0x0) {
        FUN_c0516bb8(*param_1,(char *)0x0,uVar8);
        iVar3 = FUN_c0516cfc(*param_1,uVar8);
        goto LAB_c051a880;
      }
      uVar4 = FUN_c052c76c();
      *(undefined4 *)param_2[3] = uVar4;
      iVar7 = *(int *)param_2[3];
    }
    if (iVar7 == 0) {
      FUN_c052c8e4(local_30);
      return 0x2747;
    }
LAB_c051a7d0:
    FUN_c052c8e4(local_30);
    return 0;
  }
  if ((*piVar9 == 0x100007f) || (iVar3 = FUN_c0518764(piVar9), iVar3 != 0)) {
    FUN_c0516bb8(*param_1,(char *)0xffffffff,0);
    iVar7 = *param_1;
    *(undefined4 **)(iVar7 + 0x20) = (undefined4 *)(iVar7 + 0x2e4);
    *(undefined4 *)(iVar7 + 0x2e4) = (int *)(iVar7 + 0x324);
    *(int *)(iVar7 + 0x324) = *piVar9;
    *(undefined4 *)(*(int *)(iVar7 + 0x20) + 4) = 0;
    goto LAB_c051a7d0;
  }
  pWVar6 = (PCNZWCH)0x0;
LAB_c051a8c0:
  iVar3 = FUN_c0514ba0(param_1,(int)param_2,pWVar6,piVar9,uVar8);
  if (iVar3 != 0) goto LAB_c051a7d0;
  if ((_Str1 != (wchar_t *)0x0) && (iVar3 = _wcsicmp(_Str1,L"ppp_peer"), iVar3 == 0)) {
    FUN_c052c8e4(local_30);
    return 0x2af9;
  }
  uVar10 = uVar11;
  if (iVar2 != 0) {
    bVar1 = false;
    puVar5 = FUN_c05143f4(_Str1,(uint)(uVar8 != 0));
    uVar10 = local_23c;
    if (puVar5 != (undefined4 *)0x0) {
      if ((puVar5[9] & 2) == 0) {
        if (param_1 == (int *)0x0) {
          iVar3 = FUN_c05142a8(param_2[7],(int *)param_2[3],(int)puVar5);
        }
        else {
          FUN_c0514098(*param_1,(int)puVar5,(uint)(uVar8 != 0));
          iVar3 = 0;
        }
        bVar1 = true;
      }
      else {
        iVar3 = iVar2;
        if ((iVar7 != 0) &&
           (puVar5 = FUN_c05143f4(_Str1,(uint)(uVar8 == 0)), puVar5 != (undefined4 *)0x0)) {
          bVar1 = (puVar5[9] & 2) == 0;
          if (bVar1) {
            iVar3 = 0x2af9;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
      uVar10 = local_23c;
      if (bVar1) goto LAB_c051a880;
    }
  }
  iVar3 = FUN_c051a540(param_1,(int)param_2,_Str1,local_238,(ushort)uVar11,&local_240);
  if (piVar9 == (int *)0x0) {
    if ((uVar10 == 1) || (uVar10 == 0x1c)) {
      uVar11 = (uint)(uVar8 != 0);
      puVar5 = FUN_c05143f4(_Str1,uVar11);
      if (local_240 != 0) {
        uVar11 = uVar11 | 4;
      }
      if (iVar3 == 0) {
        if (puVar5 != (undefined4 *)0x0) {
          FUN_c0514650(puVar5);
        }
        if (param_1 == (int *)0x0) {
          if (uVar10 == 1) {
            FUN_c05149f0(*(int **)param_2[3],local_238[0],uVar11);
          }
        }
        else {
          iVar7 = *param_1;
          if (*(char **)(iVar7 + 0x14) != (char *)0x0) {
            FUN_c05146b8(*(char **)(iVar7 + 0x14),*(int **)(iVar7 + 0x20),
                         (int)*(short *)(iVar7 + 0x1e),*(undefined4 **)(iVar7 + 0x18),local_238[0],
                         uVar11);
          }
        }
      }
      else if (iVar2 == 0) {
        if (puVar5 == (undefined4 *)0x0) goto LAB_c051a880;
        if (param_1 != (int *)0x0) {
          if ((iVar7 == 0) || ((puVar5[9] & 2) == 0)) {
            FUN_c0514098(*param_1,(int)puVar5,uVar11);
            iVar3 = 0;
          }
          else {
            iVar3 = 0x2af9;
          }
        }
      }
      else if (iVar7 != 0) {
        if (puVar5 == (undefined4 *)0x0) {
          FUN_c0518d90(_Str1,uVar11 | 2);
        }
        else {
          puVar5[9] = uVar11 | 2;
          FUN_c051438c((longlong *)(puVar5 + 2),600);
        }
      }
      if (puVar5 != (undefined4 *)0x0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
      }
    }
  }
  else if (iVar3 == 0) {
    iVar7 = *param_1;
    *(undefined4 **)(iVar7 + 0x20) = (undefined4 *)(iVar7 + 0x2e4);
    *(undefined4 *)(iVar7 + 0x2e4) = (int *)(iVar7 + 0x324);
    *(int *)(iVar7 + 0x324) = *piVar9;
    *(undefined4 *)(*(int *)(iVar7 + 0x20) + 4) = 0;
  }
LAB_c051a880:
  FUN_c052c8e4(local_30);
  return iVar3;
}



/* c051ac2c FUN_c051ac2c */

/* Boundary evidence: original MIPS .pdata c051ac2c..c051acfb. Semantic name remains unreviewed. */

undefined4 FUN_c051ac2c(int param_1,short *param_2,int param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  int local_228;
  short *local_224;
  int local_220;
  undefined4 local_21c;
  short asStack_218 [256];
  uint local_18;
  
  local_18 = DAT_c052e2d8;
  if (param_1 == 0) {
    dwErrCode = 0x2afb;
  }
  else {
    if (param_2 == (short *)0x0) {
      if (param_3 == 0) {
        dwErrCode = 0x271e;
        goto LAB_c051acc8;
      }
      FUN_c0513f44(asStack_218,param_3);
      param_2 = asStack_218;
    }
    local_228 = param_1;
    local_224 = param_2;
    local_220 = param_3;
    local_21c = param_4;
    dwErrCode = FUN_c051a698(&local_228,(undefined4 *)0x0);
    if (dwErrCode == 0) {
      FUN_c052c8e4(local_18);
      return 1;
    }
  }
LAB_c051acc8:
  SetLastError(dwErrCode);
  FUN_c052c8e4(local_18);
  return 0;
}



/* c051acfc FUN_c051acfc */

/* Boundary evidence: original MIPS .pdata c051acfc..c051ad83. Semantic name remains unreviewed. */

bool FUN_c051acfc(wchar_t *param_1)

{
  int iVar1;
  undefined2 local_480 [2];
  int local_47c;
  undefined1 *local_478;
  undefined4 local_474;
  undefined4 local_470;
  undefined2 *local_46c;
  uint auStack_468 [2];
  undefined1 auStack_460 [1104];
  uint local_10;
  
  local_10 = DAT_c052e2d8;
  local_478 = auStack_460;
  local_46c = local_480;
  local_47c = 0;
  local_474 = 0;
  local_470 = 0;
  local_480[0] = 0x801c;
  iVar1 = FUN_c051a540(&local_478,0,param_1,auStack_468,0x1c,&local_47c);
  FUN_c052c8e4(local_10);
  return iVar1 != 0;
}



/* c051ad84 FUN_c051ad84 */

/* Boundary evidence: original MIPS .pdata c051ad84..c051b007. Semantic name remains unreviewed. */

undefined4 FUN_c051ad84(int param_1)

{
  char *_Source;
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  undefined4 local_518;
  int local_514;
  char *local_510;
  uint *local_50c;
  undefined4 local_508;
  undefined4 local_504;
  undefined4 local_500;
  undefined4 local_4fc;
  undefined4 local_4f8;
  ushort local_4f0;
  undefined2 local_4ee;
  int aiStack_4d0 [288];
  wchar_t awStack_50 [18];
  uint local_2c;
  
  local_2c = DAT_c052e2d8;
  iVar4 = 6;
  local_50c = &DAT_c052e31c;
  local_510 = &DAT_c052e34c;
  puVar6 = local_50c;
  _Source = local_510;
  do {
    while( true ) {
      FUN_c0518c64();
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
      local_514 = DAT_c052e3d8;
      if (DAT_c052e3d8 != 0) break;
      iVar4 = iVar4 + -1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
      if (iVar4 == 0) goto LAB_c051afc0;
      FUN_c05155ec();
    }
    FUN_c0515538(aiStack_4d0,0xc,&local_514);
    mbstowcs(awStack_50,_Source,0x11);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
    FUN_c0512cd0();
    iVar8 = 0;
    iVar7 = 0;
    piVar5 = (int *)local_514;
    do {
      if (piVar5 == (int *)0x0) break;
      bVar1 = FUN_c051acfc(awStack_50);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        uVar2 = FUN_c051f8b0(0x80000017,2,0,0,0);
        *puVar6 = uVar2;
        if (uVar2 == 0) goto LAB_c051afc0;
        local_518 = 1;
        iVar3 = FUN_c05256b4(uVar2,0xffff,4,(int)&local_518,4);
        if (iVar3 != 0) goto LAB_c051afc0;
        memset(&local_4f0,0,0x1c);
        local_4ee = *(undefined2 *)(param_1 + 2);
        local_4f0 = 0x17;
        iVar3 = FUN_c051fdb0(*puVar6,&local_4f0,0x1c);
        if (iVar3 != 0) goto LAB_c051afc0;
        local_508 = *(undefined4 *)(param_1 + 8);
        local_504 = *(undefined4 *)(param_1 + 0xc);
        local_500 = *(undefined4 *)(param_1 + 0x10);
        local_4fc = *(undefined4 *)(param_1 + 0x14);
        local_4f8 = piVar5[0x12];
        iVar3 = FUN_c05256b4(*puVar6,0x29,0xc,(int)&local_508,0x14);
        if (iVar3 != 0) goto LAB_c051afc0;
        local_518 = 0xff;
        iVar3 = FUN_c05256b4(*puVar6,0x29,10,(int)&local_518,4);
        if (iVar3 != 0) goto LAB_c051afc0;
        iVar7 = iVar7 + 1;
        puVar6 = puVar6 + 1;
      }
      iVar8 = iVar8 + 1;
      piVar5 = (int *)*piVar5;
    } while (iVar8 < 0xc);
    if (iVar7 != 0) {
      FUN_c052c8e4(local_2c);
      return 1;
    }
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
LAB_c051afc0:
      FUN_c052c8e4(local_2c);
      return 0;
    }
    FUN_c05155ec();
    puVar6 = local_50c;
    _Source = local_510;
  } while( true );
}



/* c051b008 FUN_c051b008 */

/* Boundary evidence: original MIPS .pdata c051b008..c051b22f. Semantic name remains unreviewed. */

undefined4 FUN_c051b008(void)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint *puVar9;
  uint local_378;
  uint local_374;
  uint local_370 [2];
  int local_368;
  undefined1 *local_364;
  int local_360;
  uint local_35c [71];
  ushort auStack_240 [16];
  undefined1 auStack_220 [512];
  uint local_20;
  
  local_20 = DAT_c052e2d8;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
  iVar1 = FUN_c051ad84(-0x3fad1d00);
  do {
    if (iVar1 == 0) {
LAB_c051b118:
      DAT_c052e3e4 = 0;
      uVar8 = 0;
      do {
        puVar9 = (uint *)((int)&DAT_c052e31c + uVar8);
        uVar3 = *puVar9;
        if (uVar3 != 0) {
          FUN_c051f5fc(uVar3);
        }
        uVar8 = uVar8 + 4;
        *puVar9 = 0;
      } while (uVar8 < 0x30);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
      FUN_c052c8e4(local_20);
      return 0;
    }
LAB_c051b05c:
    iVar6 = 0;
    iVar1 = 0;
    piVar5 = &local_360;
    piVar7 = &DAT_c052e31c;
    do {
      piVar5[2] = 0x29;
      iVar4 = *piVar7;
      *piVar5 = 0;
      piVar5[3] = 0;
      if (iVar4 == 0) {
        local_35c[iVar6 * 6] = 0;
        break;
      }
      iVar6 = iVar6 + 1;
      piVar5[1] = iVar4;
      iVar1 = iVar1 + 1;
      piVar7 = piVar7 + 1;
      piVar5 = piVar5 + 6;
    } while (iVar6 < 0xc);
    if (iVar1 == 0) goto LAB_c051b118;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
    iVar6 = FUN_c052479c(iVar1,&local_360,0,(int *)0x0,0,(int *)0x0,(int *)0x0);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
    if (DAT_c052e31c != 0) {
      if ((iVar6 == 0) && (iVar1 != 0)) {
        puVar9 = local_35c;
        do {
          if (*puVar9 != 0) {
            local_364 = auStack_220;
            local_368 = 0x200;
            local_374 = 0x1c;
            local_378 = 0;
            DVar2 = FUN_c051c258(*puVar9,&local_368,1,local_370,(uint *)0x0,&local_378,auStack_240,
                                 &local_374,(undefined4 *)0x0,0,(int *)0x0,0);
            if (DVar2 == 0) {
              FUN_c0515270(*puVar9,(int)auStack_220,local_370[0],auStack_240);
            }
          }
          iVar1 = iVar1 + -1;
          puVar9 = puVar9 + 6;
        } while (iVar1 != 0);
      }
      goto LAB_c051b05c;
    }
    iVar1 = FUN_c051ad84(-0x3fad1d00);
  } while( true );
}



/* c051b230 FUN_c051b230 */

/* Boundary evidence: original MIPS .pdata c051b230..c051b37b. Semantic name remains unreviewed. */

int FUN_c051b230(void *param_1,undefined4 param_2,STRSAFE_LPCWSTR param_3,undefined4 *param_4,
                undefined4 param_5)

{
  int iVar1;
  HRESULT HVar2;
  HLOCAL hMem;
  int iVar3;
  DWORD dwErrCode;
  undefined4 *puVar4;
  wchar_t *pwVar5;
  undefined1 auStack_228 [4];
  undefined4 local_224;
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_c052e2d8;
  iVar1 = CeSafeCopyMemory(auStack_228,param_5,2);
  if (iVar1 == 0) {
LAB_c051b29c:
    dwErrCode = 0x271e;
  }
  else {
    if (param_3 == (STRSAFE_LPCWSTR)0x0) {
      pwVar5 = (wchar_t *)0x0;
    }
    else {
      pwVar5 = awStack_220;
      HVar2 = StringCchCopyW(awStack_220,0x100,param_3);
      if (HVar2 != 0) goto LAB_c051b29c;
    }
    if (param_4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      local_224 = *param_4;
      puVar4 = &local_224;
    }
    hMem = LocalAlloc(0x40,0x450);
    if (hMem != (HLOCAL)0x0) {
      iVar1 = FUN_c051ac2c((int)hMem,pwVar5,(int)puVar4,auStack_228);
      if ((iVar1 != 0) && (iVar3 = FUN_c0513e0c(param_1,hMem), iVar3 != 0)) {
        SetLastError(0x271e);
        iVar1 = 0;
      }
      LocalFree(hMem);
      FUN_c052c8e4(local_20);
      return iVar1;
    }
    dwErrCode = 0x2747;
  }
  SetLastError(dwErrCode);
  FUN_c052c8e4(local_20);
  return 0;
}



/* c051b37c FUN_c051b37c */

/* Boundary evidence: original MIPS .pdata c051b37c..c051b3db. Semantic name remains unreviewed. */

bool FUN_c051b37c(void)

{
  HANDLE hObject;
  
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c051b008,(LPVOID)0x0,0,(LPDWORD)0x0);
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
    DAT_c052e3e4 = 1;
  }
  return hObject != (HANDLE)0x0;
}



/* c051b3dc FUN_c051b3dc */

/* Boundary evidence: original MIPS .pdata c051b3dc..c051b457. Semantic name remains unreviewed. */

void FUN_c051b3dc(void)

{
  if (DAT_c052e17c != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
    if ((DAT_c052e3e4 == 0) && (DAT_c052e3ec != 0)) {
      FUN_c051b37c();
    }
    else {
      FUN_c05150fc();
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
  }
  return;
}



/* c051b458 FUN_c051b458 */

/* Boundary evidence: original MIPS .pdata c051b458..c051b58f. Semantic name remains unreviewed. */

undefined4 FUN_c051b458(wchar_t *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar2;
  char acStack_30 [20];
  uint local_1c;
  
  local_1c = DAT_c052e2d8;
  if (DAT_c052e17c == 0) {
    FUN_c052c8e4(DAT_c052e2d8);
    uVar2 = 0;
  }
  else {
    bVar1 = FUN_c0515168();
    if (CONCAT31(extraout_var,bVar1) == 0) {
      FUN_c052c8e4(local_1c);
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0xffffffff;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
      wcstombs(acStack_30,param_1,0x10);
      memset(&DAT_c052e34c,0,0x11);
      strncpy(&DAT_c052e34c,acStack_30,0x10);
      DAT_c052e3ec = strlen(&DAT_c052e34c);
      if (0x10 < DAT_c052e3ec) {
        DAT_c052e3ec = 0x10;
      }
      if (DAT_c052e3e4 == 0) {
        bVar1 = FUN_c051b37c();
        if (CONCAT31(extraout_var_00,bVar1) != 0) {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
        FUN_c05150fc();
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
      FUN_c052c8e4(local_1c);
    }
  }
  return uVar2;
}



/* c051b590 FUN_c051b590 */

/* Boundary evidence: original MIPS .pdata c051b590..c051b6d7. Semantic name remains unreviewed. */

undefined4 FUN_c051b590(void)

{
  bool bVar1;
  LSTATUS LVar2;
  undefined3 extraout_var;
  HKEY local_70;
  DWORD local_6c;
  DWORD aDStack_68 [2];
  WCHAR aWStack_60 [16];
  undefined2 local_40;
  WCHAR aWStack_38 [16];
  undefined2 local_18;
  uint local_14;
  
  local_14 = DAT_c052e2d8;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c052e380);
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0,&local_70);
  if (LVar2 == 0) {
    local_6c = 0x22;
    LVar2 = RegQueryValueExW(local_70,L"OrigName",(LPDWORD)0x0,aDStack_68,(LPBYTE)aWStack_38,
                             &local_6c);
    if (LVar2 == 0) {
      local_6c = 0x22;
      LVar2 = RegQueryValueExW(local_70,L"Name",(LPDWORD)0x0,aDStack_68,(LPBYTE)aWStack_60,&local_6c
                              );
      if (LVar2 == 0) {
        local_18 = 0;
        local_40 = 0;
        bVar1 = FUN_c0512824(aWStack_38,aWStack_60);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          RegCloseKey(local_70);
          FUN_c051b458(aWStack_60);
          FUN_c052c8e4(local_14);
          return 1;
        }
      }
    }
    RegCloseKey(local_70);
  }
  FUN_c052c8e4(local_14);
  return 0;
}



/* c051b6d8 FUN_c051b6d8 */

/* Boundary evidence: original MIPS .pdata c051b6d8..c051b71f. Semantic name remains unreviewed. */

void FUN_c051b6d8(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  DAT_c052e378 = 3;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  FUN_c051b3dc();
  return;
}



/* c051b720 FUN_c051b720 */

/* Boundary evidence: original MIPS .pdata c051b720..c051b80b. Semantic name remains unreviewed. */

void FUN_c051b720(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    CeFreeAsynchronousBuffer
              (*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x28),
               8);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    CeFreeAsynchronousBuffer(*(undefined4 *)(param_1 + 0x2c),*(int *)(param_1 + 0x30),4,0xc);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    CeFreeAsynchronousBuffer
              (*(undefined4 *)(param_1 + 0x38),*(int *)(param_1 + 0x3c),
               *(undefined4 *)(param_1 + 0x40),0xc);
    CeFreeAsynchronousBuffer(*(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),4,0xc);
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  if ((iVar1 != 0) && (iVar1 != *(int *)(param_1 + 0x20))) {
    CeFreeAsynchronousBuffer(iVar1,*(int *)(param_1 + 0x20),0x14,0xc);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (*(HANDLE *)(param_1 + 0x14) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x800;
  return;
}



/* c051b80c FUN_c051b80c */

/* Boundary evidence: original MIPS .pdata c051b80c..c051b84b. Semantic name remains unreviewed. */

void FUN_c051b80c(undefined4 param_1,int param_2)

{
  if ((*(uint *)(param_2 + 4) & 0x800) == 0) {
    FUN_c051b720(param_2);
  }
  FUN_c0527bfc();
  return;
}



/* c051b84c FUN_c051b84c */

/* Boundary evidence: original MIPS .pdata c051b84c..c051b987. Semantic name remains unreviewed. */

void FUN_c051b84c(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,int *param_8,int param_9)

{
  bool bVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  bVar1 = true;
  uVar3 = 1;
  param_1[1] = param_3;
  param_1[3] = param_5;
  param_1[2] = param_4;
  if (param_2 == 0) {
    if (((param_9 != 0) || (param_1[4] != 0)) && (*param_1 = 0, param_9 == 0)) {
      param_9 = param_1[4];
      bVar1 = false;
      uVar3 = 0;
    }
  }
  else {
    *param_1 = param_2;
  }
  if (param_8 != param_1) {
    CeFreeAsynchronousBuffer(param_1,param_8,0x14,0xc,uVar3);
  }
  if (((param_2 != 0) && (pcVar2 = ResumeThread_exref, param_6 != 0)) ||
     ((param_9 != 0 &&
      (EventModify(param_9,3), param_6 = param_9, pcVar2 = CloseHandle_exref, bVar1)))) {
    (*pcVar2)(param_6);
  }
  return;
}



/* c051b988 FUN_c051b988 */

/* Boundary evidence: original MIPS .pdata c051b988..c051b993. Semantic name remains unreviewed. */

undefined4 FUN_c051b988(void)

{
  return 1;
}



/* c051b994 FUN_c051b994 */

/* Boundary evidence: original MIPS .pdata c051b994..c051ba13. Semantic name remains unreviewed. */

void FUN_c051b994(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  
  while (param_2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_2;
    if ((param_3 != 0) && (param_2[2] != 0)) {
      CeFreeAsynchronousBuffer(param_2[1],0xffffffff,param_2[2],0x80000008);
    }
    FUN_c0527df4(param_1,param_2);
    param_2 = puVar1;
  }
  return;
}



/* c051ba14 FUN_c051ba14 */

/* Boundary evidence: original MIPS .pdata c051ba14..c051bb5f. Semantic name remains unreviewed. */

void FUN_c051ba14(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  iVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x20;
  if (param_2 == 0) {
    puVar1[0x36] = param_3;
    if (param_3 < (uint)puVar1[0x30]) {
      puVar1[0x30] = puVar1[0x30] - param_3;
    }
    else {
      puVar1[0x30] = puVar1[0x31];
      puVar1[0x31] = 0;
    }
  }
  else {
    puVar1[0x36] = 0;
    iVar2 = FUN_c051f74c(param_2);
  }
  puVar1[0x38] = puVar1[0x38] + -1;
  FUN_c0528468((int)puVar1,1,iVar2,0);
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_c051b994((int)puVar1,*(undefined4 **)(param_1 + 0x28),
                 (uint)(*(int *)(param_1 + 0x38) != *(int *)(param_1 + 0x34)));
    *(undefined4 *)(param_1 + 0x28) = 0;
    FUN_c051b84c(*(int **)(param_1 + 0x34),*(int *)(param_1 + 0x3c),param_3,
                 (uint)((*(ushort *)(param_1 + 0x44) & 0x40) != 0),iVar2,*(int *)(param_1 + 0x30),
                 puVar1[9],*(int **)(param_1 + 0x38),*(int *)(param_1 + 0x40));
    FUN_c0527bfc();
  }
  FUN_c051eabc(puVar1);
  return;
}



/* c051bb60 FUN_c051bb60 */

/* Boundary evidence: original MIPS .pdata c051bb60..c051bceb. Semantic name remains unreviewed. */

uint FUN_c051bb60(int param_1,uint param_2,void *param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint _Size;
  
  piVar2 = (int *)(param_1 + 0xcc);
  piVar1 = (int *)*piVar2;
  uVar3 = 0;
  if (piVar1 != piVar2) {
    if (piVar1[3] == 0x1ff0) {
      piVar1 = (int *)0x0;
    }
    if (piVar1 != (int *)0x0) goto LAB_c051bbf8;
  }
  piVar1 = FUN_c0527b7c(0x2000,0x20);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  piVar1[2] = 0;
  piVar1[3] = 0;
  *piVar1 = *piVar2;
  piVar1[1] = (int)piVar2;
  *(int **)(*piVar2 + 4) = piVar1;
  *piVar2 = (int)piVar1;
LAB_c051bbf8:
  if (param_2 != 0) {
    while( true ) {
      _Size = 0x1ff0 - piVar1[3];
      if (param_2 < _Size) {
        _Size = param_2;
      }
      memcpy((void *)((int)piVar1 + piVar1[3] + 0x10),param_3,_Size);
      piVar1[3] = piVar1[3] + _Size;
      param_3 = (void *)(_Size + (int)param_3);
      param_2 = param_2 - _Size;
      uVar3 = _Size + uVar3;
      if ((param_2 == 0) || (piVar1 = FUN_c0527b7c(0x2000,0x20), piVar1 == (int *)0x0)) break;
      piVar1[2] = 0;
      piVar1[3] = 0;
      *piVar1 = *piVar2;
      piVar1[1] = (int)piVar2;
      *(int **)(*piVar2 + 4) = piVar1;
      *piVar2 = (int)piVar1;
    }
  }
  *(uint *)(param_1 + 200) = *(int *)(param_1 + 200) + uVar3;
  if (uVar3 < *(uint *)(param_1 + 0xc0)) {
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) - uVar3;
  }
  else {
    *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0xc4);
    *(undefined4 *)(param_1 + 0xc4) = 0;
  }
  return uVar3;
}



/* c051bcec FUN_c051bcec */

/* Boundary evidence: original MIPS .pdata c051bcec..c051bdfb. Semantic name remains unreviewed. */

int * FUN_c051bcec(int *param_1,void *param_2,uint param_3,uint *param_4,int *param_5)

{
  uint uVar1;
  uint _Size;
  void *_Dst;
  int iVar2;
  void *local_30;
  
  uVar1 = *param_4;
  iVar2 = 0;
  *param_5 = 0;
  if (param_1 != (int *)0x0) {
    if (uVar1 < (uint)param_1[2]) {
      _Dst = (void *)(param_1[1] + uVar1);
      uVar1 = param_1[2] - uVar1;
      local_30 = param_2;
      while( true ) {
        _Size = param_3;
        if (uVar1 <= param_3) {
          _Size = uVar1;
        }
        memcpy(_Dst,local_30,_Size);
        _Dst = (void *)(_Size + (int)_Dst);
        iVar2 = _Size + iVar2;
        local_30 = (void *)(_Size + (int)local_30);
        param_3 = param_3 - _Size;
        if (param_3 == 0) break;
        uVar1 = uVar1 - _Size;
        if (uVar1 == 0) {
          param_1 = (int *)*param_1;
          if (param_1 == (int *)0x0) goto LAB_c051bdc8;
          _Dst = (void *)param_1[1];
          uVar1 = param_1[2];
        }
      }
      if (param_1 != (int *)0x0) {
        *param_4 = (int)_Dst - param_1[1];
      }
LAB_c051bdc8:
      *param_5 = iVar2;
    }
  }
  return param_1;
}



/* c051bdfc FUN_c051bdfc */

/* Boundary evidence: original MIPS .pdata c051bdfc..c051bf43. Semantic name remains unreviewed. */

int FUN_c051bdfc(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint local_20;
  int local_1c;
  
  piVar5 = (int *)(param_1 + 0xcc);
  local_20 = 0;
  iVar4 = 0;
  if ((int *)*piVar5 == piVar5) {
    iVar4 = 0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0xd0);
    while ((param_2 != (int *)0x0 && (iVar1 = piVar3[3], iVar1 != 0))) {
      iVar2 = piVar3[2];
      if (iVar1 == iVar2) {
        *(int *)piVar3[1] = *piVar3;
        *(int *)(*piVar3 + 4) = piVar3[1];
        FUN_c0527bfc();
        if ((int *)*piVar5 == piVar5) break;
        piVar3 = *(int **)(param_1 + 0xd0);
      }
      else {
        param_2 = FUN_c051bcec(param_2,(void *)((int)piVar3 + iVar2 + 0x10),iVar1 - iVar2,&local_20,
                               &local_1c);
        if (local_1c == 0) break;
        piVar3[2] = piVar3[2] + local_1c;
        iVar4 = local_1c + iVar4;
      }
    }
    iVar1 = *(int *)(param_1 + 200) - iVar4;
    *(int *)(param_1 + 200) = iVar1;
    if ((iVar1 == 0) && ((*(uint *)(param_1 + 0x10) & 0x4000) != 0)) {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffbfff;
      FUN_c0528468(param_1,0x20,0,0x20);
      FUN_c0528710(param_1,0);
    }
  }
  return iVar4;
}



/* c051bf44 FUN_c051bf44 */

/* Boundary evidence: original MIPS .pdata c051bf44..c051c057. Semantic name remains unreviewed. */

void FUN_c051bf44(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = param_1[3];
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x104));
  uVar1 = *(uint *)(iVar3 + 0x10);
  *(int *)(iVar3 + 0xe0) = *(int *)(iVar3 + 0xe0) + -1;
  if (param_2 == 0) {
    if (param_3 < *(uint *)(iVar3 + 0xc0)) {
      *(uint *)(iVar3 + 0xc0) = *(uint *)(iVar3 + 0xc0) - param_3;
    }
    else {
      *(undefined4 *)(iVar3 + 0xc0) = *(undefined4 *)(iVar3 + 0xc4);
      *(undefined4 *)(iVar3 + 0xc4) = 0;
    }
    *(uint *)(iVar3 + 200) = *(int *)(iVar3 + 200) + param_3;
    piVar2 = (int *)(iVar3 + 0xcc);
    param_1[3] = param_3;
    *param_1 = *piVar2;
    param_1[1] = (int)piVar2;
    *(int **)(*piVar2 + 4) = param_1;
    *piVar2 = (int)param_1;
  }
  else {
    FUN_c0527bfc();
  }
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) | 0x10000;
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x104));
  if ((uVar1 & 0x8000) != 0) {
    EventModify(*(undefined4 *)(iVar3 + 0xd4),3);
  }
  return;
}



/* c051c058 FUN_c051c058 */

/* Boundary evidence: original MIPS .pdata c051c058..c051c257. Semantic name remains unreviewed. */

int FUN_c051c058(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined2 local_50 [2];
  uint local_4c;
  undefined4 local_48;
  code *local_44;
  int *local_40;
  undefined4 local_30;
  int *local_2c;
  uint local_28;
  undefined2 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  piVar1 = FUN_c0527b7c(0x2000,0x20);
  if (piVar1 == (int *)0x0) {
    iVar2 = 0x2747;
  }
  else {
    piVar1[2] = 0;
    piVar1[3] = 0;
    local_4c = *(uint *)(param_1 + 0xc0);
    if (0x1ff0 < local_4c) {
      local_4c = 0x1ff0;
    }
    local_2c = piVar1 + 4;
    local_48 = *(undefined4 *)(param_1 + 0x168);
    local_44 = FUN_c051bf44;
    local_30 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_50[0] = 0x20;
    piVar1[3] = param_1;
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x104);
    *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;
    *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 1;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xe7fff;
    local_40 = piVar1;
    local_28 = local_4c;
    LeaveCriticalSection(lpCriticalSection);
    iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x28))
                      (&local_48,local_50,&local_4c,&local_30);
    EnterCriticalSection(lpCriticalSection);
    *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + -1;
    if (iVar2 == 0) {
      *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + -1;
      if (local_4c < *(uint *)(param_1 + 0xc0)) {
        *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) - local_4c;
      }
      else {
        *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0xc4);
        *(undefined4 *)(param_1 + 0xc4) = 0;
      }
      *(uint *)(param_1 + 200) = *(int *)(param_1 + 200) + local_4c;
      piVar1[3] = local_4c;
      piVar3 = (int *)(param_1 + 0xcc);
      *piVar1 = *piVar3;
      piVar1[1] = (int)piVar3;
      *(int **)(*piVar3 + 4) = piVar1;
      *piVar3 = (int)piVar1;
    }
    else {
      if (iVar2 != 0xff) {
        *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + -1;
        FUN_c0527bfc();
        return iVar2;
      }
      if ((*(uint *)(param_1 + 0x10) & 0x10000) == 0) {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x8000;
        LeaveCriticalSection(lpCriticalSection);
        WaitForSingleObject(*(HANDLE *)(param_1 + 0xd4),0xffffffff);
        EnterCriticalSection(lpCriticalSection);
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}



/* c051c258 FUN_c051c258 */

/* Boundary evidence: original MIPS .pdata c051c258..c051d4b3. Semantic name remains unreviewed. */

DWORD FUN_c051c258(uint param_1,int *param_2,int param_3,uint *param_4,uint *param_5,uint *param_6,
                  void *param_7,uint *param_8,undefined4 *param_9,int param_10,int *param_11,
                  int param_12)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  int *piVar5;
  HANDLE pvVar6;
  BOOL BVar7;
  undefined4 uVar8;
  uint uVar9;
  void *pvVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  undefined4 *puVar14;
  uint uVar15;
  int *piVar16;
  uint uVar17;
  int *local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  HANDLE local_54;
  void *local_50;
  uint local_4c;
  DWORD local_48;
  void *local_44;
  void *local_40;
  uint local_3c;
  uint local_38;
  undefined4 *local_34;
  int *local_30;
  
  local_60 = (int *)0x0;
  puVar3 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar3 == (undefined4 *)0x0) {
    return 0x2736;
  }
  *param_4 = 0;
  if (param_6 == (uint *)0x0) {
    local_3c = 0;
  }
  else {
    local_3c = *param_6;
  }
  puVar3[0x23] = puVar3[0x23] | 1;
  local_54 = param_7;
  if ((param_7 == (void *)0x0) || (param_8 == (uint *)0x0)) {
    param_8 = (uint *)0x0;
    local_54 = (void *)0x0;
  }
  pvVar6 = local_54;
  if ((param_9 == (undefined4 *)0x0) || ((puVar3[5] & 0x200) == 0)) {
    bVar1 = false;
    bVar2 = false;
    local_5c = 0;
    if (puVar3[7] == 1) {
      if (puVar3[0x32] == 0) {
        local_44 = (void *)0x0;
        piVar5 = param_2;
        for (iVar12 = param_3; iVar12 != 0; iVar12 = iVar12 + -1) {
          local_44 = (void *)(*piVar5 + (int)local_44);
          piVar5 = piVar5 + 2;
        }
        if ((void *)0x1fef < local_44) goto LAB_c051c408;
      }
    }
    else if (puVar3[0x57] == 0) goto LAB_c051c408;
    param_12 = 0;
  }
  else {
    bVar1 = true;
    bVar2 = true;
    local_5c = 1;
  }
LAB_c051c408:
  if ((puVar3[4] & 0x2800) != 0) {
    param_12 = 0;
  }
  local_58 = puVar3;
  DVar4 = FUN_c052800c((int)puVar3,param_2,param_3,&local_60,(int *)&local_44,1,param_12);
  if (DVar4 == 0) {
    if (param_5 != (uint *)0x0) {
      local_4c = *param_5;
      local_50 = (void *)param_5[1];
      local_40 = local_50;
      if (local_50 == (void *)0x0) {
        DVar4 = 0x271e;
        goto LAB_c051c4dc;
      }
    }
    uVar11 = local_4c;
    local_50 = local_40;
    if ((local_3c & 3) == 0) {
      iVar12 = puVar3[3];
      if (iVar12 == 0x400) {
        DVar4 = 0x2742;
      }
      else if ((puVar3[5] & 0x20) == 0) {
        if (puVar3[7] == 1) {
          if (param_5 != (uint *)0x0) goto LAB_c051c5b8;
          uVar11 = puVar3[4];
          if ((uVar11 & 0x400) == 0) {
            if (((iVar12 != 0x20) || ((uVar11 & 1) == 0)) || (bVar1)) {
              if (iVar12 == 0x40) {
                if (((uVar11 & 0x200) == 0) || (puVar3[0x32] != 0)) {
                  if ((((uVar11 & 1) != 0) && ((puVar3[0x32] == 0 && (puVar3[0x30] == 0)))) &&
                     (!bVar1)) goto LAB_c051ce30;
                  if (local_44 == (void *)0x0) {
                    DVar4 = 0;
                    goto LAB_c051c4dc;
                  }
                  if ((bVar1) || ((void *)0x1fef < local_44)) {
                    local_50 = (void *)0x0;
                    if (puVar3[0x32] == 0) {
                      piVar5 = FUN_c0527b7c(0x48,0x1a);
                      local_30 = piVar5;
                      if (piVar5 == (int *)0x0) goto LAB_c051cde0;
                      piVar5[4] = puVar3[0x5a];
                      piVar5[3] = (int)puVar3;
                      piVar5[1] = piVar5[1] & 0xfU | 0x10;
                      if (bVar1) {
                        piVar5[0xe] = (int)param_9;
                        if (param_12 == 0) {
                          piVar5[0xd] = (int)param_9;
                        }
                        else {
                          iVar12 = CeAllocAsynchronousBuffer(piVar5 + 0xd,param_9,0x14,0xc);
                          if (iVar12 != 0) {
                            DVar4 = 0x271e;
                          }
                        }
                        local_54 = (HANDLE)param_9[4];
                        piVar5[0xf] = param_10;
                        if (param_10 == 0) {
                          if ((param_12 != 0) && (local_54 != (void *)0x0)) {
                            pvVar6 = (HANDLE)__GetUserKData(0xc);
                            BVar7 = DuplicateHandle((HANDLE)puVar3[9],local_54,pvVar6,&local_54,0,0,
                                                    2);
                            if (BVar7 == 0) {
                              DVar4 = GetLastError();
                              local_48 = DVar4;
                            }
                            else {
                              piVar5[0x10] = (int)local_54;
                            }
                          }
                        }
                        else {
                          piVar5[0xc] = *param_11;
                        }
                        *param_9 = 0x103;
                        piVar5[1] = piVar5[1] | 0x40;
                        if ((param_10 == 0) && (local_54 != (void *)0x0)) {
                          EventModify(local_54,2);
                        }
                      }
                      piVar5[5] = (int)FUN_c051ba14;
                      piVar5[6] = (int)piVar5;
                      *(undefined2 *)(piVar5 + 0x11) = 0x20;
                      piVar5[10] = (int)local_60;
                      local_50 = local_44;
                      puVar3[0x37] = puVar3[0x37] + 1;
                      puVar3[0x38] = puVar3[0x38] + 1;
                      puVar3[1] = puVar3[1] + 1;
                      LeaveCriticalSection((LPCRITICAL_SECTION)(puVar3 + 0x41));
                      iVar12 = (**(code **)(*(int *)(puVar3[0x14] + 8) + 0x28))
                                         (piVar5 + 4,piVar5 + 0x11,&local_50,piVar5[10]);
                      EnterCriticalSection((LPCRITICAL_SECTION)(puVar3 + 0x41));
                      puVar3[0x37] = puVar3[0x37] + -1;
                      if (iVar12 == 0x19) {
                        iVar12 = 0;
                        local_50 = (void *)0x0;
                      }
                      if (iVar12 == 0xff) {
LAB_c051d2b0:
                        if (bVar1) {
                          DVar4 = 0x3e5;
                        }
                        else {
                          uVar11 = piVar5[1];
                          while ((uVar11 & 0x20) == 0) {
                            DVar4 = FUN_c05282e4((int)puVar3,1,0xffffffff);
                            if ((puVar3[4] & 0x1000) != 0) {
                              DVar4 = 0x2714;
                              FUN_c05226f0((int)puVar3);
                            }
                            uVar11 = piVar5[1];
                          }
                        }
                        if (DVar4 == 0) {
                          uVar8 = puVar3[0x36];
                        }
                        else {
                          uVar8 = 0;
                        }
                        FUN_c0527ce8(param_4,uVar8);
                      }
                      else {
                        puVar3[1] = puVar3[1] + -1;
                        puVar3[0x38] = puVar3[0x38] + -1;
                        FUN_c0527ce8(param_4,local_50);
                        if (iVar12 == 0xff) goto LAB_c051d2b0;
                        if (iVar12 == 0) {
                          if (local_50 < (void *)puVar3[0x30]) {
                            puVar3[0x30] = (int)puVar3[0x30] - (int)local_50;
                          }
                          else {
                            puVar3[0x30] = puVar3[0x31];
                            puVar3[0x31] = 0;
                          }
                        }
                        else {
                          FUN_c0527ce8(param_4,0);
                          DVar4 = FUN_c051f74c(iVar12);
                        }
                      }
                      if ((!bVar1) || (DVar4 != 0x3e5)) {
                        piVar5[10] = 0;
                        FUN_c0527bfc();
                      }
                      if (((puVar3[4] & 0x200) != 0) && (puVar3[0x30] == 0)) {
                        FUN_c0528468((int)puVar3,0x20,DVar4,0x20);
                      }
                      goto LAB_c051c4dc;
                    }
                    pvVar10 = (void *)FUN_c051bdfc((int)puVar3,local_60);
                    local_50 = pvVar10;
                  }
                  else {
                    if (((puVar3[0x32] == 0) && (puVar3[0x30] == 0)) && (puVar3[0x31] == 0)) {
                      if ((uVar11 & 1) == 0) {
                        DVar4 = FUN_c05282e4((int)puVar3,1,0xffffffff);
                        if ((puVar3[4] & 0x1000) != 0) {
                          DVar4 = 0x2714;
                          FUN_c05226f0((int)puVar3);
                        }
                      }
                      else {
                        DVar4 = 0x2733;
                      }
                    }
                    if (DVar4 == 0) {
                      if ((puVar3[0x32] == 0) && ((puVar3[0x30] != 0 || (puVar3[0x31] != 0)))) {
                        DVar4 = FUN_c051c058((int)puVar3);
                      }
                      if (DVar4 == 0) {
                        pvVar10 = (void *)FUN_c051bdfc((int)puVar3,local_60);
                        goto LAB_c051cfac;
                      }
                    }
                    pvVar10 = (void *)0x0;
                  }
LAB_c051cfac:
                  FUN_c0527ce8(param_4,pvVar10);
                }
                else {
                  DVar4 = FUN_c0527ce8(param_4,0);
                }
              }
              else {
                DVar4 = 0x2749;
              }
            }
            else {
LAB_c051ce30:
              DVar4 = 0x2733;
            }
          }
          else {
            DVar4 = 0x2746;
          }
        }
        else {
          if ((iVar12 != 4) && (iVar12 != 0x40)) {
LAB_c051c5b8:
            DVar4 = 0x2726;
            goto LAB_c051c4dc;
          }
          if ((local_3c & 1) != 0) goto LAB_c051c550;
          uVar17 = local_38;
          if (param_8 != (uint *)0x0) {
            uVar17 = *param_8;
            local_38 = uVar17;
            if (uVar17 < *(uint *)(puVar3[0x14] + 0xc)) {
              DVar4 = 0x271e;
              local_48 = 0x271e;
              goto LAB_c051c4dc;
            }
            memset(pvVar6,0,uVar17);
          }
          puVar14 = (undefined4 *)puVar3[0x57];
          local_34 = puVar14;
          if (puVar14 == (undefined4 *)0x0) {
            if (((puVar3[4] & 1) == 0) || (bVar2)) {
              piVar5 = FUN_c0527b7c(0x50,0x19);
              local_30 = piVar5;
              if (piVar5 == (int *)0x0) {
LAB_c051cde0:
                DVar4 = 0x2747;
              }
              else {
                *piVar5 = 0;
                piVar5[1] = piVar5[1] & 0xfU | 0x10;
                piVar5[10] = uVar17;
                if (param_12 != 0) {
                  if (local_54 != (void *)0x0) {
                    iVar12 = CeAllocAsynchronousBuffer(piVar5 + 2,local_54,uVar17,8);
                    if (iVar12 == 0) {
                      piVar5[3] = (int)local_54;
                    }
                    else {
                      DVar4 = 0x271e;
                    }
                  }
                  if (param_8 != (uint *)0x0) {
                    iVar12 = CeAllocAsynchronousBuffer(piVar5 + 0xb,param_8,4,0xc);
                    if (iVar12 == 0) {
                      piVar5[0xc] = (int)param_8;
                      goto LAB_c051c990;
                    }
                    goto LAB_c051c980;
                  }
LAB_c051c990:
                  if (DVar4 == 0) {
                    piVar5[1] = piVar5[1] | 0x400;
                    goto LAB_c051c9d8;
                  }
LAB_c051c998:
                  uVar11 = piVar5[1];
joined_r0xc051c9a0:
                  if ((uVar11 & 0x800) == 0) {
                    FUN_c051b720((int)piVar5);
                  }
                  goto LAB_c051c890;
                }
                piVar5[2] = (int)local_54;
                piVar5[0xb] = (int)param_8;
LAB_c051c9d8:
                pvVar10 = local_50;
                piVar5[4] = (int)local_60;
                *(short *)(piVar5 + 0xd) = (short)local_44;
                if (param_5 == (uint *)0x0) {
                  piVar5[0xe] = 0;
                  piVar5[0x11] = 0;
                  piVar5[0x13] = 0;
                }
                else {
                  if (param_12 != 0) {
                    iVar12 = CeAllocAsynchronousBuffer(piVar5 + 0xe,local_50,uVar11,0xc);
                    if (iVar12 == 0) {
                      iVar12 = CeAllocAsynchronousBuffer(piVar5 + 0x11,param_5,4,0xc);
                      if (iVar12 == 0) {
                        piVar5[0xf] = (int)pvVar10;
                        piVar5[0x10] = uVar11;
                        piVar5[0x12] = (int)param_5;
                        if (DVar4 != 0) goto LAB_c051c998;
                        goto LAB_c051ca8c;
                      }
                      CeFreeAsynchronousBuffer(piVar5[0xe],pvVar10,uVar11,0xc);
                    }
LAB_c051c980:
                    DVar4 = 0x271e;
                    goto LAB_c051c998;
                  }
                  piVar5[0xe] = (int)local_50;
                  piVar5[0x11] = (int)param_5;
LAB_c051ca8c:
                  piVar5[0x13] = (int)param_6;
                }
                if (bVar2) {
                  piVar5[8] = (int)param_9;
                  piVar13 = piVar5 + 7;
                  if (param_12 == 0) {
                    *piVar13 = (int)param_9;
                  }
                  else {
                    iVar12 = CeAllocAsynchronousBuffer(piVar13,param_9,0x14,0xc);
                    if (iVar12 != 0) {
                      DVar4 = 0x271e;
                    }
                  }
                  if (*piVar13 == 0) {
                    DVar4 = 0x271e;
                    uVar11 = piVar5[1];
                    goto joined_r0xc051c9a0;
                  }
                  local_34 = (undefined4 *)param_9[4];
                  piVar5[9] = param_10;
                  if (param_10 == 0) {
                    if ((param_12 != 0) && (local_34 != (undefined4 *)0x0)) {
                      pvVar6 = (HANDLE)__GetUserKData(0xc);
                      BVar7 = DuplicateHandle((HANDLE)puVar3[9],local_34,pvVar6,&local_34,0,0,2);
                      if (BVar7 == 0) {
                        DVar4 = GetLastError();
                        local_48 = DVar4;
                        if ((piVar5[1] & 0x800U) == 0) {
                          FUN_c051b720((int)piVar5);
                        }
                        FUN_c0527bfc();
                        goto LAB_c051c4dc;
                      }
                      piVar5[5] = (int)local_34;
                    }
                  }
                  else {
                    piVar5[6] = *param_11;
                  }
                  *param_9 = 0x103;
                  piVar5[1] = piVar5[1] | 0x40;
                  if ((param_10 == 0) && (local_34 != (undefined4 *)0x0)) {
                    EventModify(local_34,2);
                  }
                }
                piVar16 = puVar3 + 0x56;
                iVar12 = *piVar16;
                piVar13 = piVar16;
                while (iVar12 != 0) {
                  piVar13 = (int *)*piVar13;
                  iVar12 = *piVar13;
                }
                *piVar13 = (int)piVar5;
                if (bVar2) {
                  local_60 = (int *)0x0;
                  DVar4 = 0x3e5;
                }
                else {
                  uVar11 = piVar5[1];
                  while ((uVar11 & 0x20) == 0) {
                    DVar4 = FUN_c05282e4((int)puVar3,1,0xffffffff);
                    if (((DVar4 == 0) || (DVar4 == 0x2738)) &&
                       (iVar12 = FUN_c0527ce8(param_4,(uint)*(ushort *)(piVar5 + 0xd)), iVar12 != 0)
                       ) {
                      DVar4 = 0x271e;
                      break;
                    }
                    if (((0xff < (int)puVar3[3]) || (DVar4 == 0x2714)) ||
                       ((puVar3[4] & 0x1000) != 0)) {
                      DVar4 = 0x2714;
                      break;
                    }
                    uVar11 = piVar5[1];
                  }
                  if ((piVar5[1] & 0x20U) == 0) {
                    iVar12 = *piVar16;
                    while (iVar12 != 0) {
                      piVar13 = (int *)*piVar16;
                      if (piVar13 == piVar5) {
                        *piVar16 = *piVar5;
                        break;
                      }
                      piVar16 = piVar13;
                      iVar12 = *piVar13;
                    }
                  }
                  if ((piVar5[1] & 0x800U) == 0) {
                    FUN_c051b720((int)piVar5);
                  }
                  FUN_c0527bfc();
                }
              }
            }
            else {
              DVar4 = 0x2733;
            }
          }
          else {
            uVar15 = 0;
            local_30 = (int *)0x0;
            uVar9 = (uint)*(ushort *)(puVar14 + 1);
            if ((uVar9 != 0) && (param_8 != (uint *)0x0)) {
              if (uVar9 < uVar17) {
                *param_8 = uVar9;
                uVar17 = uVar9;
                local_38 = uVar9;
              }
              memcpy(local_54,puVar14 + 4,uVar17);
            }
            if (param_5 != (uint *)0x0) {
              uVar17 = puVar14[2];
              if (uVar17 < uVar11) {
                *param_5 = uVar17;
                uVar11 = uVar17;
                local_4c = uVar17;
              }
              memcpy(local_50,(void *)((int)puVar14 + *(ushort *)(puVar14 + 1) + 0x10),uVar11);
            }
            pvVar10 = (void *)(uint)*(ushort *)((int)puVar14 + 6);
            if (local_44 < pvVar10) {
              DVar4 = 0x2738;
              pvVar10 = local_44;
            }
            if (param_6 != (uint *)0x0) {
              if ((puVar14[3] & 4) != 0) {
                uVar15 = 0x400;
              }
              if ((puVar14[3] & 8) != 0) {
                uVar15 = uVar15 | 0x800;
              }
              if (DVar4 == 0x2738) {
                uVar15 = uVar15 | 0x100;
              }
              if ((param_5 != (uint *)0x0) && (uVar11 < (uint)puVar14[2])) {
                uVar15 = uVar15 | 0x200;
                DVar4 = 0x2738;
              }
              FUN_c0527ce8(param_6,uVar15);
            }
            local_3c = 0;
            *param_4 = (uint)pvVar10;
            if (pvVar10 != (void *)0x0) {
              FUN_c052c5b8(local_60,(void *)((int)puVar14 +
                                            (uint)*(ushort *)(puVar14 + 1) + puVar14[2] + 0x10),
                           (uint)pvVar10,(int *)&local_3c);
            }
            puVar3[0x57] = *puVar14;
            puVar3[0x36] = puVar3[0x36] - (uint)*(ushort *)((int)puVar14 + 6);
LAB_c051c890:
            FUN_c0527bfc();
          }
        }
      }
      else {
        DVar4 = 0x274a;
      }
    }
    else {
LAB_c051c550:
      DVar4 = 0x273d;
    }
  }
LAB_c051c4dc:
  if ((local_60 != (int *)0x0) && ((!bVar2 || (DVar4 != 0x3e5)))) {
    FUN_c051b994((int)puVar3,local_60,param_12);
    local_60 = (int *)0x0;
  }
  if (puVar3[7] == 2) {
    iVar12 = puVar3[0x57];
joined_r0xc051d440:
    if (iVar12 == 0) goto LAB_c051d460;
  }
  else if ((puVar3[0x30] == 0) && (puVar3[0x31] == 0)) {
    iVar12 = puVar3[0x32];
    goto joined_r0xc051d440;
  }
  FUN_c0528468((int)puVar3,1,0,1);
LAB_c051d460:
  FUN_c051eabc(puVar3);
  return DVar4;
}



/* c051d4b4 FUN_c051d4b4 */

/* Boundary evidence: original MIPS .pdata c051d4b4..c051d4bf. Semantic name remains unreviewed. */

undefined4 FUN_c051d4b4(void)

{
  return 1;
}



/* c051d4c0 FUN_c051d4c0 */

/* Boundary evidence: original MIPS .pdata c051d4c0..c051d4cb. Semantic name remains unreviewed. */

undefined4 FUN_c051d4c0(void)

{
  return 1;
}



/* c051d4cc FUN_c051d4cc */

/* Boundary evidence: original MIPS .pdata c051d4cc..c051d4d7. Semantic name remains unreviewed. */

undefined4 FUN_c051d4cc(void)

{
  return 1;
}



/* c051d4d8 FUN_c051d4d8 */

/* Boundary evidence: original MIPS .pdata c051d4d8..c051d4e3. Semantic name remains unreviewed. */

undefined4 FUN_c051d4d8(void)

{
  return 1;
}



/* c051d4e4 FUN_c051d4e4 */

/* Boundary evidence: original MIPS .pdata c051d4e4..c051d4ef. Semantic name remains unreviewed. */

undefined4 FUN_c051d4e4(void)

{
  return 1;
}



/* c051d4f0 FUN_c051d4f0 */

/* Boundary evidence: original MIPS .pdata c051d4f0..c051d4fb. Semantic name remains unreviewed. */

undefined4 FUN_c051d4f0(void)

{
  return 1;
}



/* c051d4fc FUN_c051d4fc */

/* Boundary evidence: original MIPS .pdata c051d4fc..c051d507. Semantic name remains unreviewed. */

undefined4 FUN_c051d4fc(void)

{
  return 1;
}



/* c051d508 FUN_c051d508 */

/* Boundary evidence: original MIPS .pdata c051d508..c051d513. Semantic name remains unreviewed. */

undefined4 FUN_c051d508(void)

{
  return 1;
}



/* c051d514 FUN_c051d514 */

/* Boundary evidence: original MIPS .pdata c051d514..c051d5cb. Semantic name remains unreviewed. */

void FUN_c051d514(uint param_1,int *param_2,int param_3,uint *param_4,uint *param_5,uint *param_6,
                 void *param_7,uint *param_8,undefined4 *param_9,int param_10,int *param_11)

{
  int iVar1;
  int iVar2;
  
  iVar1 = GetCallerProcess();
  iVar2 = __GetUserKData(0xc);
  FUN_c051c258(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,(uint)(iVar2 != iVar1));
  return;
}



/* c051d5cc AfdRecvInternal */

/* Boundary evidence: original MIPS .pdata c051d5cc..c051d61f. Semantic name remains unreviewed. */

void AfdRecvInternal(uint param_1,int *param_2,int param_3,uint *param_4,uint *param_5,uint *param_6
                    ,void *param_7,uint *param_8,undefined4 *param_9,int param_10,int *param_11)

{
                    /* 0xd5cc  2  AfdRecvInternal */
  FUN_c051c258(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,0);
  return;
}



/* c051d628 FUN_c051d628 */

/* Boundary evidence: original MIPS .pdata c051d628..c051d6bb. Semantic name remains unreviewed. */

undefined4 FUN_c051d628(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x57;
  switch(param_1) {
  case 3:
  case 10:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
    uVar1 = 0x271e;
    break;
  case 4:
  case 9:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x21:
  case 0x23:
    break;
  default:
    uVar1 = 0;
    break;
  case 0x24:
    uVar1 = 2;
  }
  SetLastError(0x57);
  return uVar1;
}



/* c051d6bc Deinit */

undefined4 Deinit(void)

{
                    /* 0xd6bc  3  Deinit */
  return 1;
}



/* c051d6c4 Init */

/* Boundary evidence: original MIPS .pdata c051d6c4..c051dd77. Semantic name remains unreviewed. */

undefined4 Init(void)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  int iVar3;
  LSTATUS LVar4;
  HANDLE hObject;
  int iVar5;
  HKEY local_748;
  DWORD local_744;
  HKEY local_740;
  int local_73c;
  DWORD local_738 [2];
  BYTE aBStack_730 [256];
  wchar_t awStack_630 [256];
  WCHAR aWStack_430 [256];
  WCHAR aWStack_230 [256];
  uint local_30;
  
                    /* 0xd6c4  5  Init */
  local_30 = DAT_c052e2d8;
  pHVar1 = LoadLibraryW(L"ppp.dll");
  if (pHVar1 != (HMODULE)0x0) {
    iVar5 = 0;
    do {
      if (*(int *)((int)&PTR_u_AfdRasDial_c0511960 + iVar5) != 0) {
        uVar2 = GetProcAddressW(pHVar1);
        *(undefined4 *)((int)&PTR_FUN_c052e1a0 + iVar5) = uVar2;
        *(undefined4 *)((int)&PTR_FUN_c052e238 + iVar5) = uVar2;
      }
      iVar5 = iVar5 + 4;
    } while (iVar5 < 0x4c);
  }
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
  iVar5 = FUN_c0527e50();
  if (((((iVar5 == 0) ||
        (iVar5 = CreateAPISet(&DAT_c0511e94,0x26,&PTR_FUN_c052e18c,&DAT_c05119f8), iVar5 == 0)) ||
       (iVar3 = RegisterAPISet(iVar5,0x53), iVar3 == 0)) ||
      ((iVar3 = RegisterDirectMethods(iVar5,&PTR_FUN_c052e224), iVar3 == 0 ||
       (iVar5 = SetAPIErrorHandler(iVar5,FUN_c051d628), iVar5 == 0)))) ||
     ((DAT_c052e45c = CreateAPISet("Socket",0x13,&PTR_FUN_c05119ac,&DAT_c0511b28), DAT_c052e45c == 0
      || ((iVar5 = SetAPIErrorHandler(DAT_c052e45c,&LAB_c051d620), iVar5 == 0 ||
          (iVar5 = RegisterAPISet(DAT_c052e45c,0x8000000b), iVar5 == 0)))))) {
    FUN_c052c8e4(local_30);
    return 0;
  }
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c052e360);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4c0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4e0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c052e3bc);
  FUN_c051df70();
  memcpy(aWStack_230,L"tcpstk",0x36);
  memcpy(aWStack_430,L"Netbios",0x56);
  DAT_c052e374 = 1;
  DAT_c052e3b4 = 1;
  DAT_c052e3d4 = 1;
  wcscpy(awStack_630,L"Comm\\");
  wcscat(awStack_630,L"AFD");
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,awStack_630,0,0,&local_748);
  if (LVar4 == 0) {
    GetRegDWORDValue(local_748,L"DgramBufferBytes",&DAT_c052e2c8);
    GetRegDWORDValue(local_748,L"ResolverCheckCacheFirst",&DAT_c052e374);
    GetRegDWORDValue(local_748,L"ResolverCacheFailures",&DAT_c052e3b4);
    GetRegDWORDValue(local_748,L"UpdateDnsName",&DAT_c052e3d4);
    GetRegDWORDValue(local_748,L"TCPSendQuota",&DAT_c052e188);
    if (DAT_c052e188 < 0x4000) {
      DAT_c052e188 = 0x4000;
    }
    if (0x80000 < DAT_c052e188) {
      DAT_c052e188 = 0x80000;
    }
    FUN_c0512d74((int)local_748);
    iVar5 = GetRegMultiSZValue(local_748,L"Stacks",aWStack_230,0x200);
    if (iVar5 == 0) {
      SetRegMultiSZValue(local_748,L"Stacks",L"tcpstk");
    }
    GetRegMultiSZValue(local_748,L"Helpers",aWStack_430,0x200);
  }
  else {
    LVar4 = RegCreateKeyExW((HKEY)0x80000002,awStack_630,0,(LPWSTR)0x0,0,0,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_748,(LPDWORD)&local_740);
    if (LVar4 != 0) {
      FUN_c0512d74(0);
      goto LAB_c051dac8;
    }
    SetRegMultiSZValue(local_748,L"Stacks",L"tcpstk");
    FUN_c0512d74((int)local_748);
  }
  RegCloseKey(local_748);
LAB_c051dac8:
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0,&local_748);
  if (LVar4 == 0) {
    local_744 = 0x100;
    LVar4 = RegQueryValueExW(local_748,L"OrigName",(LPDWORD)0x0,local_738,aBStack_730,&local_744);
    if (LVar4 != 0) {
      local_744 = 0x100;
      LVar4 = RegQueryValueExW(local_748,L"Name",(LPDWORD)0x0,local_738,aBStack_730,&local_744);
      if (LVar4 == 0) {
        RegSetValueExW(local_748,L"OrigName",0,local_738[0],aBStack_730,local_744);
      }
    }
    RegCloseKey(local_748);
  }
  FUN_c052b4f0(aWStack_230);
  FUN_c052b4d4(aWStack_430);
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"Comm",0,0,&local_740);
  if (LVar4 == 0) {
    local_73c = 0;
    GetRegDWORDValue(local_740,L"BootCount",&local_73c);
    local_73c = local_73c + 1;
    SetRegDWORDValue(local_740,L"BootCount");
    RegCloseKey(local_740);
  }
  DAT_c052e504 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"IP_ADDR_CHANGE_EVENT");
  DAT_c052e4fc = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"IP_ROUTE_CHANGE_EVENT");
  DAT_c052e500 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"IP6_ADDR_CHANGE_EVENT");
  DAT_c052e4f8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"IP6_ROUTE_CHANGE_EVENT");
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05262cc,(LPVOID)0x0,0,(LPDWORD)0x0);
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
  }
  pHVar1 = LoadLibraryW(L"Autoras.dll");
  if (pHVar1 != (HMODULE)0x0) {
    DAT_c052e3e0 = GetProcAddressW(pHVar1,L"Autoras_Dial_Sync");
  }
  FUN_c051b590();
  FUN_c052c76c();
  FUN_c052b514(aWStack_230,aWStack_430);
  FUN_c052c8e4(local_30);
  return 1;
}



/* c051dd78 DllEntry */

/* Boundary evidence: original MIPS .pdata c051dd78..c051ddcf. Semantic name remains unreviewed. */

undefined4 DllEntry(HMODULE param_1,int param_2)

{
                    /* 0xdd78  4  DllEntry */
  if (param_2 == 0) {
    FUN_c051de94();
  }
  else if (param_2 == 1) {
    DAT_c052e3fc = param_1;
    DisableThreadLibraryCalls(param_1);
    FUN_c051de94();
  }
  return 1;
}



/* c051ddd0 FUN_c051ddd0 */

/* Boundary evidence: original MIPS .pdata c051ddd0..c051de93. Semantic name remains unreviewed. */

void FUN_c051ddd0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 4) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
    for (iVar1 = DAT_c052e428; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
      if (param_2 == *(int *)(iVar1 + 0x24)) {
        EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x104));
        *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x1000;
        FUN_c0528710(iVar1,0x2714);
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x104));
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
  }
  else if (param_1 == 0) {
    FUN_c051de94();
  }
  return;
}



/* c051de94 FUN_c051de94 */

void FUN_c051de94(void)

{
  return;
}



/* c051de9c FUN_c051de9c */

/* Boundary evidence: original MIPS .pdata c051de9c..c051df07. Semantic name remains unreviewed. */

void * FUN_c051de9c(uint param_1)

{
  void *_Dst;
  
  if (param_1 < 0x20001) {
    _Dst = (void *)CTEAllocMem(param_1);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,param_1);
    }
  }
  else {
    _Dst = (void *)0x0;
  }
  return _Dst;
}



/* c051df08 FUN_c051df08 */

/* Boundary evidence: original MIPS .pdata c051df08..c051df3b. Semantic name remains unreviewed. */

void FUN_c051df08(uint param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_c052e660 + (param_1 & 0x3f) * 0x14));
  return;
}



/* c051df3c FUN_c051df3c */

/* Boundary evidence: original MIPS .pdata c051df3c..c051df6f. Semantic name remains unreviewed. */

void FUN_c051df3c(uint param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_c052e660 + (param_1 & 0x3f) * 0x14));
  return;
}



/* c051df70 FUN_c051df70 */

/* Boundary evidence: original MIPS .pdata c051df70..c051dfbb. Semantic name remains unreviewed. */

void FUN_c051df70(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c052e660;
  do {
    InitializeCriticalSection(lpCriticalSection);
    lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection->SpinCount;
  } while ((int)lpCriticalSection < -0x3fad14a0);
  return;
}



/* c051dfbc FUN_c051dfbc */

void FUN_c051dfbc(uint param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(&DAT_c052e560 + (param_1 & 0x3f) * 4);
  while ((iVar2 = *piVar1, iVar2 != 0 && (*(uint *)(iVar2 + 8) != param_1))) {
    piVar1 = (int *)(iVar2 + 0x40);
  }
  return;
}



/* c051dff8 FUN_c051dff8 */

/* Boundary evidence: original MIPS .pdata c051dff8..c051e14f. Semantic name remains unreviewed. */

uint FUN_c051dff8(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 1;
  uVar3 = DAT_c052e400;
  do {
    uVar3 = uVar3 + 1;
    if ((uVar3 != 0xffffffff) && (uVar3 != 0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_c052e660 + (uVar3 & 0x3f) * 0x14));
      piVar2 = (int *)(&DAT_c052e560 + (uVar3 & 0x3f) * 4);
      iVar1 = *piVar2;
      if (iVar1 == 0) break;
      do {
        if (*(uint *)(iVar1 + 8) == uVar3) break;
        piVar2 = (int *)(iVar1 + 0x40);
        iVar1 = *piVar2;
      } while (iVar1 != 0);
      if (*piVar2 == 0) break;
      LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_c052e660 + (uVar3 & 0x3f) * 0x14));
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x2711);
  uVar5 = 0xffffffff;
  if (uVar4 < 0x2711) {
    *(uint *)(param_1 + 8) = uVar3;
    DAT_c052e400 = DAT_c052e400 + uVar4;
    *(int *)(param_1 + 0x40) = *(int *)(&DAT_c052e560 + (uVar3 & 0x3f) * 4);
    *(int *)(&DAT_c052e560 + (uVar3 & 0x3f) * 4) = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_c052e660 + (uVar3 & 0x3f) * 0x14));
    uVar5 = uVar3;
  }
  return uVar5;
}



/* c051e150 FUN_c051e150 */

/* Boundary evidence: original MIPS .pdata c051e150..c051e21f. Semantic name remains unreviewed. */

undefined4 FUN_c051e150(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 8);
  iVar2 = *(int *)(param_1 + 0x118);
  uVar1 = 0;
  if ((iVar2 != 0) && ((*(uint *)(param_1 + 0x11c) & param_2) != 0)) {
    uVar1 = 0;
    if (*(undefined4 **)(param_1 + 0x120) != (undefined4 *)0x0) {
      uVar1 = **(undefined4 **)(param_1 + 0x120);
    }
    uVar3 = *(undefined4 *)(param_1 + 0x168);
    if (param_2 == 0x80) {
      *(undefined4 *)(param_1 + 0x118) = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
    uVar1 = (**(code **)(iVar4 + 0x60))(iVar2,param_1,uVar1,uVar3,param_2);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
  }
  return uVar1;
}



/* c051e220 FUN_c051e220 */

/* Boundary evidence: original MIPS .pdata c051e220..c051e64b. Semantic name remains unreviewed. */

undefined4 *
FUN_c051e220(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  undefined4 *puVar1;
  HANDLE pvVar2;
  HLOCAL pvVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  undefined1 auStack_68 [60];
  uint local_2c;
  
  local_2c = DAT_c052e2d8;
  uVar9 = *(int *)(param_1 + 0x10) + 3U & 0xfffffffc;
  iVar8 = 0x2747;
  puVar1 = FUN_c0527b7c((uVar9 + 0xe2) * 2,0x16);
  if (puVar1 == (undefined4 *)0x0) goto LAB_c051e60c;
  puVar4 = puVar1 + 0x33;
  puVar1[0x34] = puVar4;
  *puVar4 = puVar4;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  puVar1[0x35] = pvVar2;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  puVar1[0x19] = pvVar2;
  if (pvVar2 == (HANDLE)0x0) {
LAB_c051e5c4:
    if ((HANDLE)puVar1[0x19] != (HANDLE)0x0) {
      CloseHandle((HANDLE)puVar1[0x19]);
      if ((HANDLE)puVar1[0x1a] != (HANDLE)0x0) {
        CloseHandle((HANDLE)puVar1[0x1a]);
      }
    }
    CloseHandle((HANDLE)puVar1[0x35]);
  }
  else {
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    puVar1[0x1a] = pvVar2;
    if (pvVar2 == (HANDLE)0x0) goto LAB_c051e5c4;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    puVar1[0x1d] = pvVar2;
    if (pvVar2 == (HANDLE)0x0) goto LAB_c051e5c4;
    puVar1[6] = param_2;
    puVar1[7] = param_3;
    puVar1[8] = param_4;
    puVar1[0x1b] = 0;
    puVar1[100] = 10;
    pvVar3 = LocalAlloc(0x40,0xf0);
    puVar1[0x61] = pvVar3;
    puVar1[0x5c] = pvVar3;
    if ((int)((ulonglong)(uint)puVar1[100] * 0x14 >> 0x20) == 0) {
      pvVar3 = LocalAlloc(0x40,(SIZE_T)((ulonglong)(uint)puVar1[100] * 0x14));
      puVar1[0x62] = pvVar3;
      puVar1[0x5e] = pvVar3;
    }
    uVar5 = uVar9 + 0x78;
    puVar1[0x65] = 0xffffffff;
    if (0x77 < uVar5) {
      puVar1[0x65] = uVar5;
      if ((int)((ulonglong)uVar5 * (ulonglong)(uint)puVar1[100] >> 0x20) == 0) {
        pvVar3 = LocalAlloc(0x40,(SIZE_T)((ulonglong)uVar5 * (ulonglong)(uint)puVar1[100]));
        puVar1[99] = pvVar3;
        puVar1[0x5d] = pvVar3;
      }
    }
    if (((puVar1[0x5c] != 0) && (puVar1[0x5e] != 0)) && ((int *)puVar1[0x5d] != (int *)0x0)) {
      if (puVar1[100] != 1) {
        uVar5 = 0;
        piVar7 = (int *)puVar1[0x5d];
        do {
          piVar6 = (int *)(uVar5 * 0x18 + puVar1[0x5c]);
          *piVar6 = (int)(piVar6 + 6);
          piVar6 = (int *)(uVar5 * 0x14 + puVar1[0x5e]);
          *piVar6 = (int)(piVar6 + 5);
          iVar8 = puVar1[0x65];
          *piVar7 = (int)piVar7 + iVar8;
          uVar5 = uVar5 + 1 & 0xffff;
          piVar7 = (int *)((int)piVar7 + iVar8);
        } while (uVar5 < puVar1[100] - 1);
      }
      iVar8 = (**(code **)(*(int *)(param_1 + 8) + 100))
                        (puVar1 + 6,puVar1 + 7,puVar1 + 8,auStack_68,puVar1 + 0x46,puVar1 + 0x47);
      if (iVar8 == 0) {
        puVar1[1] = 1;
        puVar1[3] = 1;
        puVar1[0x4a] = puVar1 + 0x70;
        puVar1[0x4c] = (int)puVar1 + uVar9 + 0x1c0;
        puVar1[0x14] = param_1;
        puVar1[5] = puVar1[5] | 0x200;
        puVar1[0x5a] = 0;
        puVar1[0x48] = 0;
        puVar1[0x13] = 0;
        puVar1[0x12] = 0;
        puVar1[0x11] = 0;
        puVar1[0x3c] = DAT_c052e188;
        puVar1[0x3d] = DAT_c052e2c8;
        puVar1[0x3f] = 0xffffffff;
        puVar1[0x3e] = 0xffffffff;
        *(undefined2 *)((int)puVar1 + 0x102) = 0;
        *(undefined2 *)(puVar1 + 0x40) = 0;
        InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
        iVar8 = 0;
        puVar1[0x50] = DAT_c052e464 + -4;
        puVar1[0x6f] = 0xff11ee22;
        *puVar1 = 0xff11ee22;
        goto LAB_c051e60c;
      }
    }
    CloseHandle((HANDLE)puVar1[0x19]);
    CloseHandle((HANDLE)puVar1[0x1a]);
    CloseHandle((HANDLE)puVar1[0x1d]);
    CloseHandle((HANDLE)puVar1[0x35]);
    if ((HLOCAL)puVar1[0x61] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)puVar1[0x61]);
    }
    if ((HLOCAL)puVar1[99] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)puVar1[99]);
    }
    if ((HLOCAL)puVar1[0x62] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)puVar1[0x62]);
    }
  }
  FUN_c0527bfc();
  puVar1 = (undefined4 *)0x0;
LAB_c051e60c:
  *param_5 = iVar8;
  FUN_c052c8e4(local_2c);
  return puVar1;
}



/* c051e64c FUN_c051e64c */

/* Boundary evidence: original MIPS .pdata c051e64c..c051ea87. Semantic name remains unreviewed. */

void FUN_c051e64c(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1[3] == 0x200) {
    if ((param_1[7] != 1) && (param_1[0x49] != 0)) {
      param_1[0x48] = param_1[0x49];
      param_1[0x49] = 0;
      FUN_c051fa74((int)param_1);
    }
    CloseHandle((HANDLE)param_1[0x19]);
    CloseHandle((HANDLE)param_1[0x1a]);
    CloseHandle((HANDLE)param_1[0x1d]);
    CloseHandle((HANDLE)param_1[0x35]);
    if ((HANDLE)param_1[0x20] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[0x20]);
    }
    if ((HANDLE)param_1[0x1f] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[0x1f]);
    }
    if (param_1[0x11] == 0) {
      while (puVar2 = (undefined4 *)param_1[0x13], puVar2 != (undefined4 *)0x0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
        FUN_c05226f0((int)puVar2);
        FUN_c051fa74((int)puVar2);
        param_1[0x13] = puVar2[0x13];
        param_1[0x16] = param_1[0x16] + -1;
        puVar2[3] = 0x200;
        FUN_c051eabc(puVar2);
      }
      while (puVar2 = (undefined4 *)param_1[0x12], puVar2 != (undefined4 *)0x0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
        FUN_c05226f0((int)puVar2);
        FUN_c051fa74((int)puVar2);
        param_1[0x12] = puVar2[0x12];
        param_1[0x15] = 0;
        puVar2[3] = 0x200;
        FUN_c051eabc(puVar2);
      }
    }
    FUN_c051e150((int)param_1,0x80);
    FUN_c0520c98(param_1 + 0x4f);
    while ((undefined4 *)param_1[0x57] != (undefined4 *)0x0) {
      param_1[0x57] = *(undefined4 *)param_1[0x57];
      FUN_c0527bfc();
    }
    puVar2 = (undefined4 *)param_1[0x56];
    while (puVar2 != (undefined4 *)0x0) {
      param_1[0x56] = *puVar2;
      puVar2[1] = puVar2[1] | 0x20;
      FUN_c051b994((int)param_1,(undefined4 *)puVar2[4],(uint)(puVar2[7] != puVar2[8]));
      puVar2[4] = 0;
      FUN_c0528468((int)param_1,1,0x2714,1);
      if (((puVar2[1] & 0x40) != 0) && (piVar4 = (int *)puVar2[7], piVar4 != (int *)0x0)) {
        iVar3 = puVar2[5];
        puVar2[7] = 0;
        puVar2[5] = 0;
        FUN_c051b720((int)puVar2);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
        FUN_c051b84c(piVar4,puVar2[9],(uint)*(ushort *)(puVar2 + 0xd),0,0x2714,puVar2[9],param_1[9],
                     (int *)puVar2[8],iVar3);
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
      }
      FUN_c051b80c(param_1,(int)puVar2);
      puVar2 = (undefined4 *)param_1[0x56];
    }
    FUN_c0528468((int)param_1,0,0,0x100);
    FUN_c0528468((int)param_1,0,0,0x200);
    while (puVar2 = (undefined4 *)param_1[0x2e], puVar2 != (undefined4 *)0x0) {
      param_1[0x2e] = *puVar2;
      if (puVar2[1] != puVar2[2]) {
        CeFreeAsynchronousBuffer(puVar2[1],puVar2[2],0x14,0xc);
      }
      LocalFree(puVar2);
    }
    while (puVar2 = (undefined4 *)param_1[0x2f], puVar2 != (undefined4 *)0x0) {
      param_1[0x2f] = *puVar2;
      if (puVar2[1] != puVar2[2]) {
        CeFreeAsynchronousBuffer(puVar2[1],puVar2[2],0x14,0xc);
      }
      LocalFree(puVar2);
    }
    piVar4 = param_1 + 0x33;
    while (piVar1 = (int *)*piVar4, piVar1 != piVar4) {
      *(int **)(*piVar1 + 4) = piVar4;
      *piVar4 = *piVar1;
      FUN_c0527bfc();
    }
    if ((param_1[0x1e] != 0) && (EventModify(param_1[0x1e],3), param_1[9] != -1)) {
      CloseHandle((HANDLE)param_1[0x1e]);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
    param_1[0x6f] = 0xcc33bb44;
    *param_1 = 0xcc33bb44;
    if ((HLOCAL)param_1[0x61] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[0x61]);
    }
    if ((HLOCAL)param_1[0x62] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[0x62]);
    }
    if ((HLOCAL)param_1[99] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[99]);
    }
    FUN_c0527bfc();
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
  }
  return;
}



/* c051ea88 FUN_c051ea88 */

/* Boundary evidence: original MIPS .pdata c051ea88..c051eabb. Semantic name remains unreviewed. */

void FUN_c051ea88(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return;
}



/* c051eabc FUN_c051eabc */

/* Boundary evidence: original MIPS .pdata c051eabc..c051eaf7. Semantic name remains unreviewed. */

void FUN_c051eabc(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  param_1[1] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    FUN_c051e64c(param_1);
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
  }
  return;
}



/* c051eaf8 FUN_c051eaf8 */

/* Boundary evidence: original MIPS .pdata c051eaf8..c051eba7. Semantic name remains unreviewed. */

int FUN_c051eaf8(uint param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_c052e660 + (param_1 & 0x3f) * 0x14));
  iVar1 = *(int *)(&DAT_c052e560 + (param_1 & 0x3f) * 4);
  do {
    if (iVar1 == 0) {
LAB_c051eb84:
      LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_c052e660 + (param_1 & 0x3f) * 0x14));
      return iVar1;
    }
    if (*(uint *)(iVar1 + 8) == param_1) {
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x104));
      *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
      goto LAB_c051eb84;
    }
    iVar1 = *(int *)(iVar1 + 0x40);
  } while( true );
}



/* c051eba8 FUN_c051eba8 */

/* Boundary evidence: original MIPS .pdata c051eba8..c051eee3. Semantic name remains unreviewed. */

HANDLE FUN_c051eba8(uint param_1,uint param_2,uint param_3,undefined4 param_4,int param_5,
                   uint param_6)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 *puVar4;
  HANDLE pvVar5;
  undefined4 uVar6;
  BOOL BVar7;
  DWORD dwErrCode;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *piVar12;
  HANDLE local_48;
  DWORD local_44;
  undefined4 local_40 [4];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  if (param_5 == 0) {
    puVar11 = (undefined4 *)0x0;
  }
  else {
    iVar3 = CeSafeCopyMemory(local_40,param_5,0x10);
    if (iVar3 == 0) {
      dwErrCode = 0x271e;
      goto LAB_c051ee98;
    }
    puVar11 = local_40;
  }
  bVar1 = (param_1 & 0x80000000) == 0;
  if (!bVar1) {
    param_1 = param_1 & 0x7fffffff;
  }
  dwErrCode = 0x273f;
  iVar3 = 0;
  local_44 = 0x273f;
  if (0 < DAT_c052e460) {
    piVar12 = &DAT_c052e470;
    do {
      uVar10 = **(uint **)(*piVar12 + 4);
      uVar9 = 0;
      if (uVar10 != 0) {
        puVar8 = *(uint **)(*piVar12 + 4) + 4;
        do {
          if (param_1 == puVar8[-2]) {
            if (param_2 == puVar8[-1]) {
              if (param_3 == *puVar8) {
                if (param_2 == 3) goto LAB_c051ed00;
              }
              else {
                if (param_2 != 3) {
                  DVar2 = 0x273b;
                  goto LAB_c051ecc8;
                }
LAB_c051ed00:
                if (param_3 == 6) {
                  dwErrCode = 0x273b;
                  goto LAB_c051ee98;
                }
              }
              if (*(int *)((&DAT_c052e470)[iVar3] + 8) == 0) {
                dwErrCode = 0x2742;
              }
              else {
                puVar4 = FUN_c051e220((&DAT_c052e470)[iVar3],param_1,param_2,param_3,
                                      (int *)&local_44);
                dwErrCode = local_44;
                if (puVar4 != (undefined4 *)0x0) {
                  puVar4[10] = param_4;
                  if (param_5 == 0) {
                    memset(puVar4 + 0xb,0,0x10);
                  }
                  else {
                    puVar4[0xb] = *puVar11;
                    puVar4[0xc] = puVar11[1];
                    puVar4[0xd] = puVar11[2];
                    puVar4[0xe] = puVar11[3];
                  }
                  pvVar5 = (HANDLE)FUN_c051dff8((int)puVar4);
                  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
                  puVar4[0xf] = DAT_c052e428;
                  DAT_c052e454 = DAT_c052e454 + 1;
                  DAT_c052e428 = puVar4;
                  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
                  if (bVar1) {
                    uVar6 = GetCallerProcess();
                    puVar4[9] = uVar6;
                    pvVar5 = (HANDLE)CreateAPIHandle(DAT_c052e45c,pvVar5);
                    local_48 = pvVar5;
                    if ((param_6 & 0x2000) == 0) {
                      if (pvVar5 == (HANDLE)0xffffffff) goto LAB_c051ee84;
                      pvVar5 = (HANDLE)__GetUserKData(0xc);
                      BVar7 = DuplicateHandle(pvVar5,local_48,(HANDLE)puVar4[9],&local_48,0,0,3);
                      pvVar5 = (HANDLE)0xffffffff;
                      if (BVar7 == 0) goto LAB_c051ee84;
                    }
                    else {
                      puVar4[4] = puVar4[4] | 0x2000;
                    }
                  }
                  else {
                    puVar4[9] = 0xffffffff;
                    puVar4[4] = puVar4[4] | 0x800;
                    local_48 = pvVar5;
                  }
                  pvVar5 = local_48;
LAB_c051ee84:
                  FUN_c052c8e4(local_30);
                  return pvVar5;
                }
              }
              goto LAB_c051ee98;
            }
            DVar2 = 0x273c;
            if (dwErrCode == 0x273f) {
LAB_c051ecc8:
              dwErrCode = DVar2;
              local_44 = dwErrCode;
            }
          }
          uVar9 = uVar9 + 1;
          puVar8 = puVar8 + 3;
        } while (uVar9 < uVar10);
      }
      iVar3 = iVar3 + 1;
      piVar12 = piVar12 + 1;
    } while (iVar3 < DAT_c052e460);
  }
LAB_c051ee98:
  SetLastError(dwErrCode);
  FUN_c052c8e4(local_30);
  return (HANDLE)0x0;
}



/* c051eee4 FUN_c051eee4 */

/* Boundary evidence: original MIPS .pdata c051eee4..c051f1cb. Semantic name remains unreviewed. */

int FUN_c051eee4(undefined4 *param_1)

{
  bool bVar1;
  DWORD DVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0;
  if (*(short *)(param_1 + 0x40) == 0) {
    uVar6 = 0xffffffff;
  }
  else {
    uVar6 = (uint)*(ushort *)((int)param_1 + 0x102) * 1000;
  }
  if (uVar6 != 0) {
    if ((param_1[4] & 0x20) != 0) {
      DVar2 = GetTickCount();
      iVar7 = FUN_c05282e4((int)param_1,0x20,uVar6);
      if (iVar7 == 0x274c) {
        uVar6 = 0;
        goto LAB_c051f128;
      }
      if (uVar6 != 0xffffffff) {
        DVar3 = GetTickCount();
        uVar5 = DVar3 - DVar2;
        if ((-1 < (int)uVar5) && (bVar1 = uVar6 < uVar5, uVar6 = uVar6 - uVar5, bVar1)) {
          uVar6 = 0;
        }
      }
    }
    if (uVar6 != 0) {
      uVar5 = param_1[4];
      if ((uVar5 & 0x100) == 0) {
        while( true ) {
          if ((param_1[0x54] == 0) && (param_1[0x3a] == 0)) goto LAB_c051f058;
          DVar2 = GetTickCount();
          iVar7 = FUN_c05282e4((int)param_1,2,uVar6);
          if (iVar7 == 0x274c) break;
          if (uVar6 != 0xffffffff) {
            DVar3 = GetTickCount();
            uVar5 = DVar3 - DVar2;
            if (-1 < (int)uVar5) {
              if (uVar6 < uVar5) {
                uVar6 = 0;
              }
              else {
                uVar6 = uVar6 - uVar5;
              }
            }
          }
        }
        uVar6 = 0;
LAB_c051f058:
        *(short *)((int)param_1 + 0x102) = (short)(uVar6 / 1000);
        if (((iVar7 != 0x274c) && (param_1[0x30] == 0)) && (param_1[0x31] == 0)) {
          if ((param_1[4] & 0x20) == 0) {
            FUN_c0522b84(param_1,0);
          }
          do {
            if ((param_1[4] & 0x600) != 0) break;
            iVar7 = FUN_c05282e4((int)param_1,0x20,uVar6);
          } while (iVar7 != 0x274c);
        }
      }
      else if ((param_1[0x30] == 0) && (param_1[0x31] == 0)) {
        while (((uVar5 & 0x600) == 0 &&
               (iVar7 = FUN_c05282e4((int)param_1,0x20,uVar6), iVar7 != 0x274c))) {
          uVar5 = param_1[4];
        }
      }
    }
  }
LAB_c051f128:
  FUN_c0528468((int)param_1,1,0x2714,0);
  iVar4 = FUN_c05226f0((int)param_1);
  if (iVar4 != 0xf) {
    FUN_c05282e4((int)param_1,0x20,uVar6);
  }
  FUN_c051fa74((int)param_1);
  FUN_c0528710((int)param_1,0x2714);
  iVar4 = param_1[1];
  param_1[1] = iVar4 + -2;
  if (iVar4 + -2 == 0) {
    FUN_c051e64c(param_1);
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
  }
  return iVar7;
}



/* c051f1cc FUN_c051f1cc */

/* Boundary evidence: original MIPS .pdata c051f1cc..c051f1fb. Semantic name remains unreviewed. */

void FUN_c051f1cc(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
  FUN_c051eee4(param_1);
  return;
}



/* c051f1fc FUN_c051f1fc */

/* Boundary evidence: original MIPS .pdata c051f1fc..c051f5db. Semantic name remains unreviewed. */

undefined4 FUN_c051f1fc(uint param_1,int param_2)

{
  HANDLE hObject;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *lpParameter;
  int *piVar3;
  DWORD dwErrCode;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  DWORD aDStack_30 [2];
  
  dwErrCode = 0x2736;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
  lpCriticalSection = (LPCRITICAL_SECTION)(&DAT_c052e660 + (param_1 & 0x3f) * 0x14);
  EnterCriticalSection(lpCriticalSection);
  for (piVar3 = (int *)(&DAT_c052e560 + (param_1 & 0x3f) * 4);
      (*piVar3 != 0 && (*(uint *)(*piVar3 + 8) != param_1)); piVar3 = (int *)(*piVar3 + 0x40)) {
  }
  lpParameter = (undefined4 *)*piVar3;
  if (lpParameter == (undefined4 *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
    goto LAB_c051f594;
  }
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(lpParameter + 0x41);
  dwErrCode = 0;
  EnterCriticalSection(lpCriticalSection_00);
  lpParameter[1] = lpParameter[1] + 1;
  if ((lpParameter[3] == 0x200) || (lpParameter[3] == 0x100)) {
    dwErrCode = 0x2735;
LAB_c051f53c:
    LeaveCriticalSection(lpCriticalSection);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
    iVar1 = lpParameter[1];
    lpParameter[1] = iVar1 + -1;
    if (iVar1 + -1 != 0) goto LAB_c051f56c;
    FUN_c051e64c(lpParameter);
  }
  else {
    if (((((lpParameter[4] & 1) != 0) && (*(short *)(lpParameter + 0x40) != 0)) &&
        (*(short *)((int)lpParameter + 0x102) != 0)) && (lpParameter[0x3a] != 0)) {
      dwErrCode = 0x2733;
      goto LAB_c051f53c;
    }
    *piVar3 = lpParameter[0x10];
    lpParameter[0x10] = 0;
    LeaveCriticalSection(lpCriticalSection);
    piVar3 = &DAT_c052e428;
    while (puVar2 = (undefined4 *)*piVar3, puVar2 != (undefined4 *)0x0) {
      if (puVar2 == lpParameter) goto LAB_c051f35c;
      piVar3 = puVar2 + 0xf;
    }
    if (lpParameter == (undefined4 *)0x0) {
LAB_c051f35c:
      *piVar3 = lpParameter[0xf];
    }
    lpParameter[0xf] = 0;
    DAT_c052e454 = DAT_c052e454 + -1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
    lpParameter[3] = 0x200;
    lpParameter[0x59] = 0x2714;
    if (param_2 == 1) {
      *(undefined2 *)(lpParameter + 0x40) = 1;
      *(undefined2 *)((int)lpParameter + 0x102) = 0;
    }
    if ((lpParameter[0x38] != 0) && (lpParameter[7] == 1)) {
      lpParameter[4] = lpParameter[4] | 0x400;
    }
    if ((((lpParameter[4] & 0x400) == 0) && (lpParameter[0x5a] != 0)) && (lpParameter[7] != 2)) {
      if (*(short *)(lpParameter + 0x40) == 0) {
        hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c051f1cc,lpParameter,0,aDStack_30);
        if (hObject != (HANDLE)0x0) {
          FUN_c0528468((int)lpParameter,1,0x2714,0);
          LeaveCriticalSection(lpCriticalSection_00);
          iVar1 = CeGetThreadPriority(0x41);
          CeSetThreadPriority(hObject,iVar1 + -1);
          CloseHandle(hObject);
          return 1;
        }
        *(undefined2 *)(lpParameter + 0x40) = 1;
        *(undefined2 *)((int)lpParameter + 0x102) = 0;
      }
      FUN_c051eee4(lpParameter);
      return 1;
    }
    if ((lpParameter[0x11] == 0) && (lpParameter[7] == 1)) {
      FUN_c051fc84((int)lpParameter,0);
    }
    if (lpParameter[0x38] == 0) {
      FUN_c0528710((int)lpParameter,0x2714);
      FUN_c05226f0((int)lpParameter);
    }
    else {
      FUN_c05226f0((int)lpParameter);
      FUN_c0528710((int)lpParameter,0x2714);
    }
    if (lpParameter[7] == 1) {
      FUN_c051fa74((int)lpParameter);
    }
    else {
      lpParameter[0x49] = lpParameter[0x48];
      lpParameter[0x48] = 0;
    }
    iVar1 = lpParameter[1];
    lpParameter[1] = iVar1 + -2;
    if (iVar1 + -2 == 0) {
      FUN_c051e64c(lpParameter);
      return 1;
    }
LAB_c051f56c:
    LeaveCriticalSection(lpCriticalSection_00);
  }
  if (dwErrCode == 0) {
    return 1;
  }
LAB_c051f594:
  SetLastError(dwErrCode);
  return 0;
}



/* c051f5dc FUN_c051f5dc */

/* Boundary evidence: original MIPS .pdata c051f5dc..c051f5fb. Semantic name remains unreviewed. */

undefined4 FUN_c051f5dc(uint param_1)

{
  FUN_c051f1fc(param_1,1);
  return 1;
}



/* c051f5fc FUN_c051f5fc */

/* Boundary evidence: original MIPS .pdata c051f5fc..c051f617. Semantic name remains unreviewed. */

void FUN_c051f5fc(uint param_1)

{
  FUN_c051f1fc(param_1,0);
  return;
}



/* c051f618 FUN_c051f618 */

/* Boundary evidence: original MIPS .pdata c051f618..c051f74b. Semantic name remains unreviewed. */

int FUN_c051f618(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  uint local_28 [2];
  
  iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x58))
                    (*(undefined4 *)(param_1 + 0x118),0,0,0,0xfffe,1,0,local_28);
  if (iVar1 == 0) {
    pvVar2 = FUN_c051de9c(local_28[0]);
    if (pvVar2 == (void *)0x0) {
      iVar1 = 0x2747;
    }
    else {
      iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x58))
                        (*(undefined4 *)(param_1 + 0x118),0,0,0,0xfffe,1,pvVar2,local_28);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*(int *)(*(int *)(param_2 + 0x50) + 8) + 0x68))
                          (*(undefined4 *)(param_2 + 0x118),0,0,0,0xfffe,1,pvVar2,local_28[0]);
      }
      CTEFreeMem(pvVar2);
    }
  }
  return iVar1;
}



/* c051f74c FUN_c051f74c */

/* Boundary evidence: original MIPS .pdata c051f74c..c051f887. Semantic name remains unreviewed. */

undefined4 FUN_c051f74c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0xff) {
    switch(param_1) {
    case 0:
      uVar1 = 0;
      break;
    case 1:
    case 4:
      uVar1 = 0x2747;
      break;
    case 2:
      uVar1 = 0x2740;
      break;
    case 3:
    case 6:
      uVar1 = 0x2741;
      break;
    default:
      goto switchD_c051f790_caseD_5;
    case 9:
    case 0x23:
      uVar1 = 0x2738;
      break;
    case 0xe:
      uVar1 = 0x274d;
      break;
    case 0xf:
    case 0x13:
      uVar1 = 0x2745;
      break;
    case 0x14:
      uVar1 = 0x2746;
      break;
    case 0x15:
      uVar1 = 0x274c;
      break;
    case 0x16:
      uVar1 = 0x2775;
      break;
    case 0x1b:
    case 0x1d:
      uVar1 = 0x2743;
      break;
    case 0x1c:
      uVar1 = 0x2751;
      break;
    case 0x1e:
      uVar1 = 0x2757;
      break;
    case 0x20:
    case 0x22:
      uVar1 = 0x2714;
      break;
    case 0x21:
      uVar1 = 0x271e;
      break;
    case 0x25:
      uVar1 = 0x2748;
      break;
    case 0x26:
      uVar1 = 0x2742;
      break;
    case 0x27:
      uVar1 = 0x2734;
    }
  }
  else {
switchD_c051f790_caseD_5:
    uVar1 = 0x2726;
  }
  return uVar1;
}



/* c051f888 FUN_c051f888 */

/* Boundary evidence: original MIPS .pdata c051f888..c051f8af. Semantic name remains unreviewed. */

void FUN_c051f888(uint param_1,uint param_2,uint param_3,undefined4 param_4,int param_5)

{
  FUN_c051eba8(param_1,param_2,param_3,param_4,param_5,0x2000);
  return;
}



/* c051f8b0 FUN_c051f8b0 */

/* Boundary evidence: original MIPS .pdata c051f8b0..c051f8d3. Semantic name remains unreviewed. */

void FUN_c051f8b0(uint param_1,uint param_2,uint param_3,undefined4 param_4,int param_5)

{
  FUN_c051eba8(param_1,param_2,param_3,param_4,param_5,0);
  return;
}



/* c051f8d4 FUN_c051f8d4 */

undefined4 FUN_c051f8d4(short *param_1,int param_2)

{
  uint uVar1;
  
  if (*param_1 == 2) {
    if ((param_1[1] != 0) || (*(int *)(param_1 + 2) != 0)) {
      return 0;
    }
  }
  else {
    uVar1 = 0;
    if (param_2 != 2) {
      do {
        if (*(char *)((int)param_1 + uVar1 + 2) != '\0') {
          return 0;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_2 - 2U);
    }
  }
  return 1;
}



/* c051f940 FUN_c051f940 */

/* Boundary evidence: original MIPS .pdata c051f940..c051fa43. Semantic name remains unreviewed. */

undefined4 FUN_c051f940(short *param_1,size_t param_2,int param_3)

{
  int iVar1;
  size_t _Size;
  int iVar2;
  undefined4 uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
  iVar2 = DAT_c052e428;
  do {
    if (iVar2 == 0) {
      uVar3 = 0;
LAB_c051fa04:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
      return uVar3;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x104));
    if (((param_3 == *(int *)(iVar2 + 0x1c)) && (3 < *(int *)(iVar2 + 0xc))) &&
       (*(int *)(iVar2 + 0xc) < 0x100)) {
      _Size = 8;
      if (*param_1 != 2) {
        _Size = param_2;
      }
      iVar1 = memcmp(param_1,*(void **)(iVar2 + 0x128),_Size);
      if (iVar1 == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x104));
        uVar3 = 1;
        goto LAB_c051fa04;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x104));
    iVar2 = *(int *)(iVar2 + 0x3c);
  } while( true );
}



/* c051fa44 FUN_c051fa44 */

/* Boundary evidence: original MIPS .pdata c051fa44..c051fa73. Semantic name remains unreviewed. */

void FUN_c051fa44(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_c0527bfc();
  return;
}



/* c051fa74 FUN_c051fa74 */

/* Boundary evidence: original MIPS .pdata c051fa74..c051fb7f. Semantic name remains unreviewed. */

int FUN_c051fa74(int param_1)

{
  int iVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar3;
  int local_30;
  code *local_2c;
  int *local_28;
  
  piVar2 = *(int **)(param_1 + 0x120);
  iVar3 = 0;
  if (piVar2 != (int *)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(piVar2 + 3);
    *(undefined4 *)(param_1 + 0x120) = 0;
    EnterCriticalSection(lpCriticalSection);
    iVar1 = piVar2[1];
    piVar2[1] = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      LeaveCriticalSection(lpCriticalSection);
      local_30 = *piVar2;
      if (local_30 == 0) {
        DeleteCriticalSection(lpCriticalSection);
        FUN_c0527bfc();
      }
      else {
        local_2c = FUN_c051fa44;
        local_28 = piVar2;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
        iVar3 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 4))(&local_30);
        if (iVar3 != 0xff) {
          DeleteCriticalSection(lpCriticalSection);
          FUN_c0527bfc();
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
      }
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar3;
}



/* c051fb80 FUN_c051fb80 */

/* Boundary evidence: original MIPS .pdata c051fb80..c051fc83. Semantic name remains unreviewed. */

undefined4 FUN_c051fb80(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_78 [2];
  undefined4 local_70 [6];
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  undefined4 *local_40;
  undefined1 *local_3c;
  undefined4 local_38;
  undefined1 auStack_28 [8];
  int local_20;
  uint local_18;
  
  local_18 = DAT_c052e2d8;
  local_40 = &local_58;
  local_54 = *(undefined4 *)(param_1 + 0x128);
  local_3c = auStack_28;
  iVar2 = *(int *)(param_1 + 0x50);
  local_38 = 0xc;
  local_50 = *(int *)(iVar2 + 0x10);
  local_78[0] = local_50 + 0xc;
  local_58 = 0;
  memset(local_70,0,0x14);
  if (param_2 == 0) {
    local_70[0] = **(undefined4 **)(param_1 + 0x120);
  }
  else {
    local_70[0] = *(undefined4 *)(param_1 + 0x168);
  }
  uVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x3c))(local_70,3,&local_40,local_78,param_2);
  *(int *)(param_1 + 300) = local_20 + 2;
  if (**(short **)(param_1 + 0x128) == 2) {
    memset(*(short **)(param_1 + 0x128) + 4,0,8);
  }
  FUN_c052c8e4(local_18);
  return uVar1;
}



/* c051fc84 FUN_c051fc84 */

/* Boundary evidence: original MIPS .pdata c051fc84..c051fdaf. Semantic name remains unreviewed. */

int FUN_c051fc84(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  
  piVar3 = *(int **)(param_1 + 0x120);
  if (piVar3 == (int *)0x0) {
    return 6;
  }
  iVar2 = *piVar3;
  if (iVar2 == 0) {
    return 6;
  }
  if (param_2 == 0) {
    if (piVar3[2] == 0) {
      return 6;
    }
    pcVar4 = (code *)0x0;
  }
  else {
    pcVar4 = FUN_c052b748;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x38))(iVar2,0,pcVar4,piVar3);
  if (param_2 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(piVar3 + 3));
    piVar3[2] = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0x200) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x38))(iVar2,0,0,piVar3);
      return 0x22;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(piVar3 + 3));
    piVar3[2] = param_1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(piVar3 + 3));
  return iVar1;
}



/* c051fdb0 FUN_c051fdb0 */

/* Boundary evidence: original MIPS .pdata c051fdb0..c0520387. Semantic name remains unreviewed. */

int FUN_c051fdb0(uint param_1,ushort *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  int local_48;
  int local_44;
  undefined4 local_40 [6];
  
  puVar7 = (undefined4 *)0x0;
  local_50 = 0;
  puVar2 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar2 == (undefined4 *)0x0) {
    return 0x2736;
  }
  local_4c = puVar2;
  if (puVar2[3] == 0x400) {
    iVar5 = 0x2742;
    goto LAB_c051fe3c;
  }
  if (puVar2[3] != 1) {
LAB_c051fe94:
    iVar5 = 0x2726;
    goto LAB_c051fe3c;
  }
  puVar2[3] = 2;
  if ((uint)*param_2 != puVar2[6]) {
    iVar5 = 0x273f;
    local_54 = 0x273f;
    goto LAB_c051fe3c;
  }
  iVar4 = puVar2[0x14];
  if (*(uint *)(iVar4 + 0x10) < param_3) {
    param_3 = *(uint *)(iVar4 + 0x10);
  }
  if (param_3 < *(uint *)(iVar4 + 0xc)) {
LAB_c051ff20:
    iVar5 = 0x271e;
  }
  else {
    puVar7 = FUN_c0527b7c(*(size_t *)(iVar4 + 0x18),0x11);
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = 1;
      puVar7[1] = param_3 + 0xfffe & 0xffff;
      puVar6 = (ushort *)(puVar7 + 2);
      iVar5 = CeSafeCopyMemory(puVar6,param_2,param_3);
      if (iVar5 == 0) goto LAB_c051ff20;
      if ((uint)*puVar6 != puVar2[6]) goto LAB_c051fe94;
      if ((puVar2[5] & 1) == 0) {
        lpCriticalSection = (LPCRITICAL_SECTION)(puVar2 + 0x41);
        LeaveCriticalSection(lpCriticalSection);
        iVar5 = (**(code **)(*(int *)(iVar4 + 8) + 0x50))(puVar6,param_3,&local_48);
        if (iVar5 == 0) {
          if (((local_48 == 1) && (local_44 == 1)) ||
             (iVar5 = FUN_c051f940((short *)(puVar7 + 2),param_3,puVar2[7]), iVar5 == 0)) {
            EnterCriticalSection(lpCriticalSection);
            goto LAB_c0520044;
          }
          iVar5 = 0x2740;
        }
        EnterCriticalSection(lpCriticalSection);
        goto LAB_c051fe3c;
      }
LAB_c0520044:
      puVar3 = FUN_c0527b7c(0x20,0x10);
      if (puVar3 != (undefined4 *)0x0) {
        InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 3));
        local_58 = 1;
        if ((puVar2[5] & 0x10) == 0) {
          local_57 = 0;
        }
        else {
          local_57 = 2;
          local_56 = 0;
        }
        memset(local_40,0,0x14);
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
        local_4c = (undefined4 *)
                   (*(code *)**(undefined4 **)(iVar4 + 8))(local_40,puVar7,puVar2[8],&local_58);
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
        puVar1 = local_4c;
        if (local_4c == (undefined4 *)0x0) {
          puVar3[1] = 1;
          *puVar3 = local_40[0];
          puVar3[2] = 0;
          *(short *)puVar2[0x4a] = (short)puVar2[6];
          puVar2[0x48] = puVar3;
          if (puVar2[3] == 2) {
            iVar5 = FUN_c051fb80((int)puVar2,0);
            if (iVar5 == 0) {
              LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
              iVar5 = (**(code **)(*(int *)(iVar4 + 8) + 0x38))(local_40[0],1,FUN_c052b874,puVar2);
              if (((iVar5 == 0) &&
                  (iVar5 = (**(code **)(*(int *)(iVar4 + 8) + 0x38))
                                     (local_40[0],5,FUN_c052c76c,puVar2), iVar5 == 0)) &&
                 ((iVar5 = (**(code **)(*(int *)(iVar4 + 8) + 0x38))
                                     (local_40[0],4,FUN_c052c084,puVar2), iVar5 == 0 &&
                  (iVar5 = (**(code **)(*(int *)(iVar4 + 8) + 0x38))
                                     (local_40[0],3,FUN_c052b9b8,puVar2), iVar5 == 0)))) {
                EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
                if (puVar2[3] != 2) {
                  FUN_c051fa74((int)puVar2);
                  iVar5 = 0x2714;
                  goto LAB_c051fe3c;
                }
                iVar5 = FUN_c051e150((int)puVar2,1);
                if (iVar5 == 0) {
                  puVar2[3] = 4;
                  iVar5 = 0;
                  goto LAB_c051fe3c;
                }
              }
              else {
                iVar5 = FUN_c051f74c(iVar5);
                EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
              }
              FUN_c051fa74((int)puVar2);
            }
            else {
              iVar5 = FUN_c051f74c(iVar5);
              FUN_c051fa74((int)puVar2);
            }
          }
          else {
            FUN_c051fa74((int)puVar2);
            iVar5 = 0x2714;
          }
        }
        else {
          DeleteCriticalSection((LPCRITICAL_SECTION)(puVar3 + 3));
          FUN_c0527bfc();
          iVar5 = FUN_c051f74c((int)puVar1);
        }
        goto LAB_c051fe3c;
      }
    }
    iVar5 = 0x2747;
  }
LAB_c051fe3c:
  if (puVar2[7] != 1) {
    FUN_c0528468((int)puVar2,2,0,0);
  }
  if (puVar7 != (undefined4 *)0x0) {
    FUN_c0527bfc();
  }
  if (puVar2[3] == 2) {
    puVar2[3] = 1;
  }
  else if (((puVar2[0x6c] != 0) && (puVar2[3] == 4)) &&
          (iVar4 = FUN_c0525538((int)puVar2,100,puVar2[0x6c]), iVar4 != 0)) {
    puVar2[0x6c] = 0;
  }
  FUN_c051eabc(puVar2);
  return iVar5;
}



/* c0520388 FUN_c0520388 */

/* Boundary evidence: original MIPS .pdata c0520388..c0520393. Semantic name remains unreviewed. */

undefined4 FUN_c0520388(void)

{
  return 1;
}



/* c0520394 FUN_c0520394 */

int FUN_c0520394(uint param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = 0;
  if (0 < DAT_c052e460) {
    piVar5 = &DAT_c052e470;
    iVar2 = iVar1;
    iVar4 = DAT_c052e460;
    do {
      puVar3 = *(uint **)(*piVar5 + 4);
      uVar6 = *puVar3;
      uVar7 = 0;
      iVar1 = iVar2;
      if (uVar6 != 0) {
        puVar3 = puVar3 + 2;
        do {
          iVar1 = *piVar5;
          if (param_1 == *puVar3) break;
          uVar7 = uVar7 + 1;
          puVar3 = puVar3 + 3;
          iVar1 = iVar2;
        } while (uVar7 < uVar6);
      }
      iVar4 = iVar4 + -1;
      piVar5 = piVar5 + 1;
      iVar2 = iVar1;
    } while (iVar4 != 0);
  }
  return iVar1;
}



/* c0520400 FUN_c0520400 */

/* Boundary evidence: original MIPS .pdata c0520400..c0520643. Semantic name remains unreviewed. */

int FUN_c0520400(int param_1,uint param_2,undefined4 param_3,uint param_4,uint *param_5,int param_6,
                undefined4 param_7,STRSAFE_LPCWSTR param_8,uint param_9,size_t *param_10)

{
  uint cchDest;
  HRESULT HVar1;
  int iVar2;
  int iVar3;
  uint local_resc;
  uint local_530 [2];
  undefined1 auStack_528 [128];
  undefined1 auStack_4a8 [632];
  wchar_t awStack_230 [256];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  local_530[0] = param_9 >> 1;
  local_resc = param_4;
  if ((0x80 < param_4) || ((param_10 == (size_t *)0x0 && (param_1 == 1)))) {
LAB_c0520468:
    FUN_c052c8e4(DAT_c052e2d8);
    return 0x2726;
  }
  if (0xfe < local_530[0]) {
    local_530[0] = 0xfe;
  }
  if (((param_2 != 0x17) && (param_2 != 2)) && (param_2 != 0)) goto LAB_c0520468;
  if (((param_1 == 2) && (HVar1 = StringCchCopyW(awStack_230,0xff,param_8), HVar1 != 0)) ||
     (iVar2 = CeSafeCopyMemory(auStack_528,param_3,local_resc), iVar2 == 0)) {
LAB_c05204d8:
    FUN_c052c8e4(local_30);
    return 0x271e;
  }
  if (param_6 == 0) {
    memset(auStack_4a8,0,0x274);
  }
  else {
    iVar2 = CeSafeCopyMemory(auStack_4a8,param_6);
    if (iVar2 == 0) goto LAB_c05204d8;
  }
  iVar2 = FUN_c0520394(param_2);
  cchDest = local_530[0];
  if (iVar2 != 0) {
    if (param_1 == 1) {
      iVar2 = (**(code **)(*(int *)(iVar2 + 8) + 0x7c))
                        (auStack_528,local_resc,auStack_4a8,awStack_230,local_530);
      if ((iVar2 == 0) && (HVar1 = StringCchCopyW(param_8,cchDest,awStack_230), HVar1 != 0)) {
        iVar2 = 0x271e;
      }
      *param_10 = local_530[0];
      goto LAB_c052060c;
    }
    if (param_1 == 2) {
      iVar2 = (**(code **)(*(int *)(iVar2 + 8) + 0x80))
                        (awStack_230,param_2,auStack_4a8,auStack_528,&local_resc);
      if ((iVar2 == 0) && (iVar3 = CeSafeCopyMemory(param_3,auStack_528,local_resc), iVar3 == 0)) {
        iVar2 = 0x271e;
      }
      *param_5 = local_resc;
      goto LAB_c052060c;
    }
  }
  iVar2 = 0x2726;
LAB_c052060c:
  FUN_c052c8e4(local_30);
  return iVar2;
}



/* c0520644 FUN_c0520644 */

/* Boundary evidence: original MIPS .pdata c0520644..c052069b. Semantic name remains unreviewed. */

undefined4 * FUN_c0520644(int param_1)

{
  undefined4 *_Dst;
  
  _Dst = *(undefined4 **)(param_1 + 0x178);
  if (_Dst == (undefined4 *)0x0) {
    _Dst = FUN_c051de9c(0x14);
  }
  else {
    *(undefined4 *)(param_1 + 0x178) = *_Dst;
    memset(_Dst,0,0x14);
  }
  return _Dst;
}



/* c052069c FUN_c052069c */

/* Boundary evidence: original MIPS .pdata c052069c..c05206f7. Semantic name remains unreviewed. */

void FUN_c052069c(int param_1,undefined4 *param_2)

{
  if ((param_2 < *(undefined4 **)(param_1 + 0x188)) ||
     (*(undefined4 **)(param_1 + 0x188) + *(int *)(param_1 + 400) * 5 <= param_2)) {
    CTEFreeMem(param_2);
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x178);
    *(undefined4 **)(param_1 + 0x178) = param_2;
  }
  return;
}



/* c05206f8 FUN_c05206f8 */

/* Boundary evidence: original MIPS .pdata c05206f8..c052077b. Semantic name remains unreviewed. */

undefined4 * FUN_c05206f8(int param_1,uint param_2)

{
  undefined4 *_Dst;
  undefined4 uVar1;
  
  if (param_2 < 0x8001) {
    _Dst = *(undefined4 **)(param_1 + 0x174);
    uVar1 = *(undefined4 *)(param_1 + 0x18);
    if (_Dst == (undefined4 *)0x0) {
      _Dst = FUN_c051de9c(param_2 + 0x78);
    }
    else {
      *(undefined4 *)(param_1 + 0x174) = *_Dst;
      memset(_Dst,0,param_2 + 0x78);
    }
    if (_Dst != (undefined4 *)0x0) {
      _Dst[2] = uVar1;
    }
  }
  else {
    _Dst = (undefined4 *)0x0;
  }
  return _Dst;
}



/* c052077c FUN_c052077c */

/* Boundary evidence: original MIPS .pdata c052077c..c0520843. Semantic name remains unreviewed. */

void FUN_c052077c(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (((param_2[1] & 0x40) != 0) && (param_2[10] != 0)) {
    while (puVar1 = (undefined4 *)param_2[8], puVar1 != (undefined4 *)0x0) {
      param_2[8] = *puVar1;
      CTEFreeMem(puVar1[1]);
      FUN_c0527df4(param_1,puVar1);
    }
    param_2[10] = 0;
  }
  if ((param_2 < *(undefined4 **)(param_1 + 0x18c)) ||
     ((undefined4 *)
      (*(int *)(param_1 + 0x194) * *(int *)(param_1 + 400) + (int)*(undefined4 **)(param_1 + 0x18c))
      <= param_2)) {
    CTEFreeMem(param_2);
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x174);
    *(undefined4 **)(param_1 + 0x174) = param_2;
  }
  return;
}



/* c0520844 FUN_c0520844 */

/* Boundary evidence: original MIPS .pdata c0520844..c0520b33. Semantic name remains unreviewed. */

int FUN_c0520844(int param_1,int param_2,int *param_3,size_t param_4,uint param_5,
                undefined4 *param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  void *_Dst;
  uint uVar5;
  uint _Size;
  int iVar6;
  int *piVar7;
  size_t local_40;
  int *local_3c;
  void *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  
  piVar7 = (int *)(param_2 + 0x28);
  iVar6 = 0;
  local_3c = (int *)(param_1 + 0x13c);
  iVar3 = *piVar7;
  while (iVar3 != 0) {
    piVar7 = (int *)*piVar7;
    iVar3 = *piVar7;
  }
  puVar1 = FUN_c0520644(param_1);
  *param_6 = puVar1;
  *piVar7 = (int)puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    iVar6 = 0x2747;
  }
  else {
    local_30 = puVar1 + 3;
    puVar1[2] = param_2;
    puVar1[4] = 0;
    *local_30 = 0;
  }
  piVar4 = (int *)*local_3c;
  local_40 = param_4;
  local_34 = local_30;
  if (piVar4 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined4 *)(param_1 + 0x148) = 0;
  }
  else {
    iVar3 = *piVar4;
    while (iVar3 != 0) {
      iVar3 = *(int *)*piVar4;
      local_3c = piVar4;
      piVar4 = (int *)*piVar4;
    }
  }
  while ((param_3 != (int *)0x0 && (param_4 != 0))) {
    if (iVar6 != 0) goto LAB_c0520ac0;
    for (; uVar5 = param_3[2], uVar5 <= param_5; param_3 = (int *)*param_3) {
      param_5 = param_5 - uVar5;
    }
    local_38 = (void *)param_3[1];
    if (param_5 != 0) {
      local_38 = (void *)((int)local_38 + param_5);
      uVar5 = uVar5 - param_5;
      param_5 = 0;
    }
    while( true ) {
      if ((uVar5 == 0) || (param_4 == 0)) goto LAB_c0520aac;
      puVar2 = (undefined4 *)FUN_c0527dbc(param_1);
      *local_34 = puVar2;
      if (puVar2 == (undefined4 *)0x0) break;
      _Size = *(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x148);
      if (_Size == 0) {
        local_3c = (int *)*local_3c;
      }
      if (*local_3c == 0) {
        iVar3 = FUN_c0527e84();
        *local_3c = iVar3;
        if (iVar3 == 0) {
          FUN_c0527df4(param_1,puVar2);
          *local_34 = 0;
          param_4 = local_40;
          break;
        }
        _Size = *(uint *)(param_1 + 0x140);
        *(undefined4 *)(param_1 + 0x148) = 0;
      }
      if (uVar5 < _Size) {
        _Size = uVar5;
      }
      if ((int)local_40 < (int)_Size) {
        _Size = local_40;
      }
      _Dst = (void *)(*(int *)(param_1 + 0x148) + *local_3c + 4);
      puVar2[1] = _Dst;
      puVar2[2] = _Size;
      *puVar2 = 0;
      memcpy(_Dst,local_38,_Size);
      *(uint *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + _Size;
      *(uint *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + _Size;
      puVar1[4] = _Size + puVar1[4];
      local_38 = (void *)(_Size + (int)local_38);
      param_4 = local_40 - _Size;
      uVar5 = uVar5 - _Size;
      local_40 = param_4;
      local_34 = puVar2;
    }
    iVar6 = 0x2747;
LAB_c0520aac:
    param_3 = (int *)*param_3;
  }
  if (iVar6 != 0) {
LAB_c0520ac0:
    if (puVar1 != (undefined4 *)0x0) {
      while (puVar2 = (undefined4 *)puVar1[3], puVar2 != (undefined4 *)0x0) {
        puVar1[3] = *puVar2;
        FUN_c0527df4(param_1,puVar2);
      }
      FUN_c052069c(param_1,puVar1);
      *param_6 = 0;
      *piVar7 = 0;
    }
  }
  return iVar6;
}



/* c0520b34 FUN_c0520b34 */

/* Boundary evidence: original MIPS .pdata c0520b34..c0520c97. Semantic name remains unreviewed. */

void FUN_c0520b34(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while( true ) {
    puVar2 = *(undefined4 **)(param_1 + 0x150);
    if ((puVar2 == (undefined4 *)0x0) || ((puVar2[1] & 0x100) == 0)) {
      return;
    }
    if ((puVar2[1] & 0x40) == 0) {
      while ((puVar3 = (undefined4 *)puVar2[10], puVar3 != (undefined4 *)0x0 &&
             ((puVar3[1] & 0x100) != 0))) {
        if ((puVar3[1] & 0x200) != 0) {
          puVar3[3] = *(undefined4 *)puVar3[3];
          CTEFreeMem();
        }
        while (puVar4 = (undefined4 *)puVar3[3], puVar4 != (undefined4 *)0x0) {
          iVar1 = puVar4[2] + *(int *)(param_1 + 0x144);
          *(int *)(param_1 + 0x144) = iVar1;
          if (*(int *)(param_1 + 0x140) <= iVar1) {
            *(undefined4 *)(param_1 + 0x144) = 0;
            *(undefined4 *)(param_1 + 0x13c) = **(undefined4 **)(param_1 + 0x13c);
            FUN_c0527eb4();
          }
          puVar3[3] = *puVar4;
          FUN_c0527df4(param_1,puVar4);
        }
        puVar3[3] = 0;
        puVar2[10] = *puVar3;
        FUN_c052069c(param_1,puVar3);
      }
    }
    else if ((*(uint *)(puVar2[10] + 4) & 0x200) != 0) {
      CTEFreeMem(*(undefined4 *)(puVar2[10] + 0xc));
    }
    if ((puVar2[10] != 0) && ((puVar2[1] & 0x40) == 0)) break;
    *(undefined4 *)(param_1 + 0x150) = *puVar2;
    FUN_c052077c(param_1,puVar2);
  }
  return;
}



/* c0520c98 FUN_c0520c98 */

/* Boundary evidence: original MIPS .pdata c0520c98..c0520cd7. Semantic name remains unreviewed. */

void FUN_c0520c98(undefined4 *param_1)

{
  while ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)*param_1;
    FUN_c0527eb4();
  }
  return;
}



/* c0520cd8 FUN_c0520cd8 */

/* Boundary evidence: original MIPS .pdata c0520cd8..c0520e83. Semantic name remains unreviewed. */

void FUN_c0520cd8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *local_30;
  
  iVar3 = *(int *)(param_1 + 8);
  puVar4 = *(undefined4 **)(iVar3 + 0xc);
  EnterCriticalSection((LPCRITICAL_SECTION)(puVar4 + 0x41));
  puVar4[0x6b] = puVar4[0x6b] + 1;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x100;
  puVar4[0x3a] = puVar4[0x3a] - *(int *)(param_1 + 0x10);
  if (puVar4[7] != 1) {
    *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 0x20;
  }
  if (param_2 == 0) {
    *(int *)(iVar3 + 0x60) = *(int *)(iVar3 + 0x60) + param_3;
  }
  else {
    *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 0x1100;
  }
  uVar1 = *(uint *)(iVar3 + 4);
  *(int *)(iVar3 + 0x68) = *(int *)(iVar3 + 0x68) + 1;
  if ((uVar1 & 0x40) == 0) {
    piVar2 = (int *)0x0;
    piVar5 = local_30;
    piVar6 = local_30;
    piVar7 = local_30;
    piVar8 = local_30;
    if (*(int *)(iVar3 + 0x60) == *(int *)(iVar3 + 0x5c)) {
      *(uint *)(iVar3 + 4) = uVar1 | 0x100;
    }
  }
  else {
    *(uint *)(iVar3 + 4) = uVar1 | 0x100;
    piVar2 = *(int **)(iVar3 + 0x30);
    local_30 = *(int **)(iVar3 + 0x54);
    piVar5 = *(int **)(iVar3 + 0x2c);
    piVar6 = *(int **)(iVar3 + 0x38);
    piVar7 = (int *)puVar4[9];
    piVar8 = *(int **)(iVar3 + 0x34);
  }
  FUN_c0520b34((int)puVar4);
  iVar3 = 0;
  if (param_2 != 0) {
    iVar3 = FUN_c051f74c(param_2);
  }
  FUN_c0528468((int)puVar4,2,iVar3,2);
  FUN_c051eabc(puVar4);
  if (piVar2 != (int *)0x0) {
    FUN_c051b84c(piVar2,(int)piVar6,param_3,0,iVar3,(int)piVar5,piVar7,piVar8,(int)local_30);
  }
  return;
}



/* c0520e84 FUN_c0520e84 */

/* Boundary evidence: original MIPS .pdata c0520e84..c0521133. Semantic name remains unreviewed. */

int FUN_c0520e84(int *param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  void *_Src;
  int *piVar1;
  uint uVar2;
  uint _Size;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  void *_Dst;
  
  iVar3 = 0;
  pvVar4 = (void *)0x0;
  uVar5 = 0;
  if (param_2 < 0x14) {
    iVar3 = 0x271e;
  }
  else {
    uVar2 = 0;
    for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (piVar1[2] != 0) {
        uVar2 = (uint)*(byte *)piVar1[1];
        if (((uVar2 & 0xf0) != 0x40) || (uVar2 = uVar2 & 0xf, uVar2 < 5)) {
          iVar3 = 0x271e;
        }
        if ((piVar1 != (int *)0x0) && (uVar2 != 0)) goto LAB_c0520f78;
        break;
      }
    }
    iVar3 = 0x271e;
LAB_c0520f78:
    if (iVar3 == 0) {
      uVar5 = uVar2 * 4;
      if (param_2 < uVar5) {
        iVar3 = 0x271e;
      }
      else {
        pvVar4 = FUN_c051de9c(0x54);
        if (pvVar4 == (void *)0x0) {
          iVar3 = 0x2747;
        }
        else {
          _Dst = (void *)((int)pvVar4 + 0x18);
          *(void **)((int)pvVar4 + 4) = _Dst;
          *(uint *)((int)pvVar4 + 8) = uVar5;
          piVar1 = (int *)*param_1;
          uVar6 = 0;
          while ((uVar6 < uVar5 && (piVar1 != (int *)0x0))) {
            _Src = (void *)piVar1[1];
            _Size = piVar1[2];
            if (uVar5 < uVar6 + _Size) {
              piVar1[1] = (int)((int)_Src + uVar5);
              piVar1[2] = _Size + uVar2 * -4;
              _Size = uVar5;
            }
            else {
              *param_1 = *piVar1;
            }
            memcpy(_Dst,_Src,_Size);
            uVar6 = _Size + uVar6;
            _Dst = (void *)(_Size + (int)_Dst);
          }
          if (uVar6 < uVar5) {
            iVar3 = 0x271e;
          }
        }
      }
    }
    if (iVar3 == 0) goto LAB_c05210e4;
  }
  if (pvVar4 != (void *)0x0) {
    CTEFreeMem(pvVar4);
  }
  pvVar4 = (void *)0x0;
  uVar5 = 0;
LAB_c05210e4:
  *param_3 = pvVar4;
  *param_4 = uVar5;
  return iVar3;
}



/* c0521134 FUN_c0521134 */

/* Boundary evidence: original MIPS .pdata c0521134..c052113f. Semantic name remains unreviewed. */

undefined4 FUN_c0521134(void)

{
  return 1;
}



/* c0521140 FUN_c0521140 */

/* Boundary evidence: original MIPS .pdata c0521140..c052128f. Semantic name remains unreviewed. */

DWORD FUN_c0521140(int param_1,int param_2,undefined4 *param_3)

{
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  HANDLE local_28;
  DWORD local_24;
  
  DVar2 = 0;
  iVar3 = *(int *)(param_1 + 0x30);
  local_28 = *(HANDLE *)(iVar3 + 0x10);
  if ((param_2 == 0) && (local_28 != (HANDLE)0x0)) {
    if (*(int *)(param_1 + 0x34) != iVar3) {
      hTargetProcessHandle = (HANDLE)__GetUserKData(0xc);
      BVar1 = DuplicateHandle(*(HANDLE *)(*(int *)(param_1 + 0xc) + 0x24),*(HANDLE *)(iVar3 + 0x10),
                              hTargetProcessHandle,&local_28,0,0,2);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        local_24 = DVar2;
      }
      else {
        *(HANDLE *)(param_1 + 0x54) = local_28;
      }
    }
    if (DVar2 == 0) {
      EventModify(local_28,2);
    }
  }
  **(undefined4 **)(param_1 + 0x30) = 0x103;
  *(int *)(param_1 + 0x38) = param_2;
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x2c) = *param_3;
  }
  return DVar2;
}



/* c0521290 FUN_c0521290 */

/* Boundary evidence: original MIPS .pdata c0521290..c052129b. Semantic name remains unreviewed. */

undefined4 FUN_c0521290(void)

{
  return 1;
}



/* c052129c FUN_c052129c */

/* Boundary evidence: original MIPS .pdata c052129c..c0521953. Semantic name remains unreviewed. */

DWORD FUN_c052129c(int param_1,int *param_2,uint param_3,int param_4,int param_5,undefined4 *param_6
                  ,undefined4 param_7,int param_8,int param_9,undefined4 *param_10,int param_11)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  DWORD DVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int *local_res4 [3];
  int local_68;
  undefined4 *local_64;
  undefined4 local_60;
  undefined4 *local_5c;
  uint local_58;
  uint local_54;
  int *local_50;
  undefined4 *local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  code *local_3c;
  undefined4 *local_38;
  
  local_54 = 0;
  local_58 = 0;
  local_60 = 0;
  local_68 = 0;
  local_5c = (undefined4 *)0x0;
  local_res4[0] = param_2;
  local_50 = param_2;
  local_48 = param_4;
  puVar1 = FUN_c05206f8(param_1,*(uint *)(*(int *)(param_1 + 0x50) + 0x10));
  local_4c = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    DVar5 = 0x2747;
    iVar10 = local_44;
    goto LAB_c05218dc;
  }
  uVar4 = puVar1[1];
  piVar7 = puVar1 + 0xc;
  *puVar1 = 0;
  puVar1[3] = param_1;
  puVar1[1] = uVar4 & 0xf;
  puVar1[10] = 0;
  *piVar7 = 0;
  puVar1[0x17] = param_3;
  if ((param_8 == 0) || ((*(uint *)(param_1 + 0x14) & 0x200) == 0)) {
    iVar10 = 0;
    puVar6 = local_64;
LAB_c0521420:
    puVar8 = (undefined4 *)0x0;
    if ((*(int *)(param_1 + 0x1c) == 3) && ((*(uint *)(param_1 + 0x14) & 0x400) != 0)) {
      DVar5 = FUN_c0520e84((int *)local_res4,param_3,&local_5c,&local_58);
      if (DVar5 == 0) {
        if ((local_5c == (undefined4 *)0x0) || (*(char *)(local_5c[1] + 9) != '\x06')) {
          param_3 = param_3 - local_58;
          local_54 = local_58;
          param_2 = local_res4[0];
          puVar8 = local_5c;
          goto LAB_c05214a4;
        }
        DVar5 = 0x273b;
      }
    }
    else {
LAB_c05214a4:
      piVar7 = (int *)(param_1 + 0x150);
      if (*piVar7 != 0) {
        local_68 = 0;
        do {
          *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x19c) + 1;
          piVar7 = (int *)*piVar7;
          if ((piVar7[1] & 0x40U) == 0) {
            local_68 = local_68 + 1;
          }
          puVar1 = local_4c;
        } while (*piVar7 != 0);
      }
      *piVar7 = (int)puVar1;
      if ((iVar10 == 0) || (local_68 == 0)) {
        if (*(int *)(param_1 + 0x154) == 0) {
          *(undefined4 **)(param_1 + 0x154) = puVar1;
        }
        if (iVar10 == 0) {
          do {
            iVar2 = *(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0xe8);
            if ((0 < iVar2) && (*(undefined4 **)(param_1 + 0x154) == puVar1)) goto LAB_c05215b0;
            *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + 1;
            if (((*(uint *)(param_1 + 0x10) & 1) != 0) && (iVar2 < 1)) {
              puVar1[1] = puVar1[1] | 0x80;
              if (puVar1 == *(undefined4 **)(param_1 + 0x154)) {
                *(undefined4 *)(param_1 + 0x154) = *puVar1;
              }
              *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xfffffffd;
              *piVar7 = 0;
              FUN_c052077c(param_1,puVar1);
              DVar5 = 0x2733;
              goto LAB_c05218dc;
            }
            iVar2 = FUN_c05282e4(param_1,2,0xffffffff);
            if ((*(int *)(param_1 + 0xc) != 4) && (*(int *)(param_1 + 0xc) != 0x40)) {
              DVar5 = 0x2714;
              goto LAB_c05213c8;
            }
          } while (iVar2 == 0);
          puVar1[1] = puVar1[1] | 0x100;
          FUN_c0520b34(param_1);
LAB_c05215b0:
          DVar5 = FUN_c0520844(param_1,(int)puVar1,param_2,param_3,0,&local_64);
          puVar6 = local_64;
          if (DVar5 != 0) {
            if (puVar1 == *(undefined4 **)(param_1 + 0x154)) {
              *(undefined4 *)(param_1 + 0x154) = *puVar1;
            }
            puVar1[1] = puVar1[1] | 0x1100;
            FUN_c0520b34(param_1);
            goto LAB_c05218dc;
          }
        }
        if (puVar1 == *(undefined4 **)(param_1 + 0x154)) {
          *(undefined4 *)(param_1 + 0x154) = *puVar1;
        }
        if (puVar8 != (undefined4 *)0x0) {
          *puVar8 = puVar6[3];
          puVar6[3] = puVar8;
          puVar6[4] = puVar6[4] + local_54;
          puVar6[1] = puVar6[1] | 0x200;
        }
        iVar9 = puVar6[4];
        local_3c = FUN_c0520cd8;
        *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + iVar9;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
        *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + 1;
        iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x18);
        puVar1[0x1b] = 1;
        puVar1[0x1c] = iVar2 + -10;
        puVar1[0x12] = 0;
        puVar1[0x10] = 0;
        puVar1[0x14] = puVar1 + 0x1b;
        puVar1[0x13] = iVar2;
        *(short *)(puVar1 + 0x1d) = (short)*(undefined4 *)(param_1 + 0x18);
        local_38 = puVar6;
        if (local_48 == 0) {
          if (*(int *)(param_1 + 0xc) == 0x40) {
            memcpy((void *)((int)puVar1 + 0x76),(void *)(*(int *)(param_1 + 0x130) + 2),
                   *(int *)(param_1 + 0x134) - 2);
          }
        }
        else {
          iVar2 = CeSafeCopyMemory((void *)((int)puVar1 + 0x76),local_48 + 2,param_5 - 2U);
          if (iVar2 == 0) {
            memset((void *)((int)puVar1 + 0x76),0,param_5 - 2U);
          }
        }
        local_40 = **(undefined4 **)(param_1 + 0x120);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
        iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x30))
                          (&local_40,puVar1 + 0xf,puVar6[4],&local_44,puVar6[3]);
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
        if (iVar2 == 0) {
          *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
          *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) - iVar9;
          *(int *)(param_1 + 0x1ac) = *(int *)(param_1 + 0x1ac) + 1;
          DVar5 = FUN_c0527ce8(param_6,local_44);
          puVar1[1] = puVar1[1] | 0x1a0;
          FUN_c0520b34(param_1);
          uVar4 = 2;
          DVar3 = 0;
        }
        else {
          if (iVar2 == 0xff) {
            if (iVar10 == 0) {
              DVar5 = FUN_c0527ce8(param_6,iVar9);
            }
            else {
              DVar5 = 0x3e5;
            }
            goto LAB_c05218dc;
          }
          *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) - iVar9;
          *(int *)(param_1 + 0x1ac) = *(int *)(param_1 + 0x1ac) + 1;
          *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
          puVar1[1] = puVar1[1] | 0x1a0;
          puVar6[1] = puVar6[1] | 0x100;
          FUN_c0520b34(param_1);
          DVar3 = FUN_c051f74c(iVar2);
          FUN_c0527ce8(param_6,0);
          uVar4 = 0;
          DVar5 = DVar3;
        }
        FUN_c0528468(param_1,2,DVar3,uVar4);
        goto LAB_c05218dc;
      }
      DVar5 = 0x2734;
      *piVar7 = 0;
    }
  }
  else {
    iVar10 = 1;
    puVar1[1] = uVar4 & 0xf | 0x40;
    puVar1[0xd] = param_8;
    if (param_11 == 0) {
      *piVar7 = param_8;
LAB_c05213e0:
      puVar6 = puVar1 + 5;
      *puVar6 = 0;
      puVar1[7] = puVar1;
      puVar1[8] = local_60;
      puVar1[9] = param_3;
      puVar1[10] = puVar6;
      local_64 = puVar6;
      DVar5 = FUN_c0521140((int)puVar1,param_9,param_10);
      param_2 = local_50;
      if (DVar5 == 0) goto LAB_c0521420;
    }
    else {
      iVar2 = CeAllocAsynchronousBuffer(piVar7,param_8,0x14,0xc);
      if (iVar2 == 0) {
        DVar5 = FUN_c0527ed0(param_1,param_2,param_3,&local_60);
        if (DVar5 == 0) goto LAB_c05213e0;
      }
      else {
        DVar5 = 0x271e;
      }
    }
  }
LAB_c05213c8:
  FUN_c052077c(param_1,puVar1);
LAB_c05218dc:
  if (*(int *)(param_1 + 0x150) != 0) {
    if (((DVar5 == 0x2733) || (DVar5 == 0x2747)) ||
       ((DVar3 = DVar5, iVar10 != 0 && (DVar5 == 0x3e5)))) {
      DVar3 = 0;
    }
    FUN_c0528468(param_1,2,DVar3,0);
  }
  return DVar5;
}



/* c0521954 FUN_c0521954 */

/* Boundary evidence: original MIPS .pdata c0521954..c0521f7f. Semantic name remains unreviewed. */

DWORD FUN_c0521954(int param_1,int *param_2,uint param_3,undefined4 *param_4,undefined4 param_5,
                  int param_6,int param_7,undefined4 *param_8)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  code *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  DWORD DVar9;
  DWORD DVar10;
  undefined4 *puVar11;
  int *piVar12;
  uint uVar13;
  uint local_5c;
  undefined4 *local_58;
  int local_54;
  undefined4 local_50;
  int *local_4c;
  code *local_48;
  undefined4 *local_44;
  undefined4 local_40;
  code *local_3c;
  undefined4 *local_38;
  
  local_50 = 0;
  uVar13 = 0;
  DVar9 = 0;
  iVar8 = 0;
  local_5c = 0;
  local_4c = param_2;
  local_44 = param_4;
  puVar5 = FUN_c05206f8(param_1,*(uint *)(*(int *)(param_1 + 0x50) + 0x10));
  if (puVar5 == (undefined4 *)0x0) {
    DVar10 = 0x2747;
    local_5c = uVar13;
  }
  else {
    uVar7 = puVar5[1];
    *puVar5 = 0;
    puVar5[3] = param_1;
    puVar5[1] = uVar7 & 0xf;
    puVar5[10] = 0;
    puVar5[0xc] = 0;
    puVar5[0x17] = param_3;
    if ((param_6 == 0) || ((*(uint *)(param_1 + 0x14) & 0x200) == 0)) {
      bVar1 = false;
      bVar3 = false;
      puVar11 = local_58;
LAB_c0521aa8:
      piVar12 = (int *)(param_1 + 0x150);
      while (*piVar12 != 0) {
        *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x19c) + 1;
        piVar12 = (int *)*piVar12;
        if ((piVar12[1] & 0x40U) == 0) {
          iVar8 = iVar8 + 1;
        }
      }
      *piVar12 = (int)puVar5;
      if ((bVar1) && (iVar8 != 0)) {
        *piVar12 = 0;
        DVar9 = 0x2734;
        FUN_c052077c(param_1,puVar5);
        bVar1 = bVar3;
      }
      else {
        if (*(int *)(param_1 + 0x154) == 0) {
          *(undefined4 **)(param_1 + 0x154) = puVar5;
        }
        if (param_3 != 0) {
          local_48 = FUN_c0520cd8;
          while (pcVar4 = local_48, DVar9 == 0) {
            *(int *)(param_1 + 0x1a0) = *(int *)(param_1 + 0x1a0) + 1;
            bVar2 = true;
            if (bVar1) {
LAB_c0521bfc:
              uVar13 = param_3;
              if (!bVar2) goto LAB_c0521c04;
            }
            else {
              do {
                iVar8 = *(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0xe8);
                if ((0 < iVar8) && (*(undefined4 **)(param_1 + 0x154) == puVar5)) goto LAB_c0521bc8;
                *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + 1;
                if (((*(uint *)(param_1 + 0x10) & 1) != 0) && (iVar8 < 1)) {
                  puVar5[0x17] = local_5c;
                  puVar5[1] = puVar5[1] | 0x80;
                  if (puVar5 == *(undefined4 **)(param_1 + 0x154)) {
                    *(undefined4 *)(param_1 + 0x154) = *puVar5;
                  }
                  if (local_5c != 0) {
                    if (puVar5[0x19] == puVar5[0x1a]) {
                      puVar5[1] = puVar5[1] | 0x100;
                      FUN_c0520b34(param_1);
                    }
                    goto LAB_c0521eec;
                  }
                  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xfffffffd;
                  *piVar12 = 0;
                  FUN_c052077c(param_1,puVar5);
                  DVar10 = 0x2733;
                  goto LAB_c0521f1c;
                }
                DVar9 = FUN_c05282e4(param_1,2,0xffffffff);
              } while (DVar9 == 0);
              puVar5[1] = puVar5[1] | 0x100;
              FUN_c0520b34(param_1);
LAB_c0521bc8:
              if (DVar9 != 0) break;
              uVar13 = *(uint *)(param_1 + 0xf0) >> 1;
              bVar2 = bVar3;
              if (param_3 <= uVar13) goto LAB_c0521bfc;
              if (*(uint *)(param_1 + 0xf0) == 1) {
                uVar13 = 1;
              }
LAB_c0521c04:
              DVar9 = FUN_c0520844(param_1,(int)puVar5,local_4c,uVar13,local_5c,&local_58);
              puVar11 = local_58;
              if (DVar9 != 0) {
                puVar5[1] = puVar5[1] | 0x1100;
                break;
              }
            }
            local_54 = puVar11[4];
            puVar5[3] = param_1;
            param_3 = param_3 - local_54;
            *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + local_54;
            *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
            if ((param_3 == 0) &&
               (puVar5[1] = puVar5[1] | 0x80, puVar5 == *(undefined4 **)(param_1 + 0x154))) {
              *(undefined4 *)(param_1 + 0x154) = *puVar5;
            }
            local_40 = *(undefined4 *)(param_1 + 0x168);
            *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + 1;
            puVar5[0x19] = puVar5[0x19] + 1;
            local_3c = pcVar4;
            local_38 = puVar11;
            LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
            iVar6 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x2c))
                              (&local_40,0,puVar11[4],puVar11[3]);
            EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
            iVar8 = local_54;
            if (iVar6 == 0) {
              *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) - local_54;
              *(int *)(param_1 + 0x1ac) = *(int *)(param_1 + 0x1ac) + 1;
              iVar6 = puVar5[0x18];
              local_5c = local_54 + local_5c;
              puVar5[0x1a] = puVar5[0x1a] + 1;
              puVar5[0x18] = iVar6 + local_54;
              if (bVar3) {
                puVar5[1] = puVar5[1] | 0x100;
                puVar11[1] = puVar11[1] | 0x100;
              }
              else if (iVar6 + local_54 == puVar5[0x17]) {
                puVar5[1] = puVar5[1] | 0x100;
                puVar11[1] = puVar11[1] | 0x100;
              }
              FUN_c0520b34(param_1);
              *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
              FUN_c0528468(param_1,2,0,2);
            }
            else if (iVar6 != 0xff) {
              if (iVar6 == 0x19) {
                DVar9 = 0x2746;
              }
              else {
                DVar9 = FUN_c051f74c(iVar6);
              }
              *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) - local_54;
              *(int *)(param_1 + 0x1ac) = *(int *)(param_1 + 0x1ac) + 1;
              puVar5[0x1a] = puVar5[0x1a] + 1;
              *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
              puVar5[1] = puVar5[1] | 0x1100;
              puVar11[1] = puVar11[1] | 0x1100;
              FUN_c0520b34(param_1);
              FUN_c0528468(param_1,2,DVar9,0);
              break;
            }
            if (bVar3) {
              DVar9 = 0x3e5;
            }
            local_5c = iVar8 + local_5c;
            bVar1 = bVar3;
            if (param_3 == 0) break;
          }
          goto LAB_c0521eec;
        }
      }
    }
    else {
      bVar3 = true;
      puVar5[1] = uVar7 & 0xf | 0x40;
      puVar5[0xd] = param_6;
      iVar6 = CeAllocAsynchronousBuffer(puVar5 + 0xc,param_6,0x14,0xc);
      if (iVar6 == 0) {
        DVar9 = FUN_c0527ed0(param_1,param_2,param_3,&local_50);
        if (DVar9 == 0) {
          puVar11 = puVar5 + 5;
          *puVar11 = 0;
          puVar5[7] = puVar5;
          puVar5[8] = local_50;
          puVar5[9] = param_3;
          puVar5[10] = puVar11;
          local_58 = puVar11;
          DVar9 = FUN_c0521140((int)puVar5,param_7,param_8);
          if (DVar9 == 0) {
            bVar1 = true;
            goto LAB_c0521aa8;
          }
        }
      }
      else {
        DVar9 = 0x271e;
      }
      FUN_c052077c(param_1,puVar5);
      local_5c = uVar13;
LAB_c0521eec:
      DVar10 = DVar9;
      if ((DVar9 == 0x2733) || (uVar13 = local_5c, bVar1 = bVar3, DVar9 == 0x2747))
      goto LAB_c0521f1c;
    }
    local_5c = uVar13;
    DVar10 = DVar9;
    if ((!bVar1) || (DVar9 != 0x3e5)) goto LAB_c0521f28;
  }
LAB_c0521f1c:
  DVar9 = 0;
LAB_c0521f28:
  FUN_c0528468(param_1,2,DVar9,0);
  iVar8 = FUN_c0527ce8(local_44,local_5c);
  if (iVar8 != 0) {
    DVar10 = 0x271e;
  }
  return DVar10;
}



/* c0521f80 FUN_c0521f80 */

/* WARNING: Removing unreachable block (ram,0xc05221cc) */
/* Boundary evidence: original MIPS .pdata c0521f80..c05224c7. Semantic name remains unreviewed. */

DWORD FUN_c0521f80(uint param_1,int *param_2,int param_3,undefined4 *param_4,uint param_5,
                  ushort *param_6,undefined4 *param_7,int param_8,int param_9,undefined4 *param_10,
                  int param_11)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  ushort *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  int *local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  uint local_30 [2];
  
  local_40 = (int *)0x0;
  local_34 = param_4;
  puVar4 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar4 == (undefined4 *)0x0) {
    return 0x2736;
  }
  puVar4[0x23] = puVar4[0x23] | 2;
  if (((param_8 == 0) || ((puVar4[5] & 0x200) == 0)) || ((puVar4[4] & 0x2800) != 0)) {
    param_11 = 0;
  }
  local_3c = puVar4;
  DVar5 = FUN_c052800c((int)puVar4,param_2,param_3,&local_40,(int *)local_30,0,param_11);
  if ((DVar5 != 0) || (DVar5 = FUN_c0527ce8(param_4,0), DVar5 != 0)) goto LAB_c0522448;
  if ((param_5 & 1) != 0) {
    DVar5 = 0x273d;
    goto LAB_c0522448;
  }
  iVar9 = puVar4[3];
  if (iVar9 == 0x400) {
    DVar5 = 0x2742;
    goto LAB_c0522448;
  }
  if ((puVar4[5] & 0x40) != 0) {
    DVar5 = 0x274a;
    goto LAB_c0522448;
  }
  if (puVar4[7] == 1) {
    if ((iVar9 == 0x20) && ((puVar4[4] & 1) != 0)) {
      DVar5 = 0x2733;
      goto LAB_c0522448;
    }
    if ((puVar4[4] & 0x400) != 0) {
      DVar5 = 0x2746;
      goto LAB_c0522448;
    }
    if (iVar9 == 0x40) {
      if (local_30[0] == 0) {
        DVar5 = FUN_c0527ce8(param_4,0);
      }
      else {
        DVar5 = FUN_c0521954((int)puVar4,local_40,local_30[0],param_4,local_30,param_8,param_9,
                             param_10);
      }
      goto LAB_c0522448;
    }
LAB_c0522104:
    DVar5 = 0x2749;
    goto LAB_c0522448;
  }
  if (iVar9 == 0x40) {
    if (param_6 != (ushort *)0x0) goto LAB_c0522118;
  }
  else {
    if (param_6 == (ushort *)0x0) goto LAB_c0522104;
LAB_c0522118:
    if ((uint)*param_6 == puVar4[6]) {
      if (param_7 < *(undefined4 **)(puVar4[0x14] + 0xc)) {
        DVar5 = 0x271e;
        local_38 = 0x271e;
      }
      else {
        puVar8 = *(undefined4 **)(puVar4[0x14] + 0x10);
        if (puVar8 < param_7) {
          param_7 = puVar8;
        }
      }
    }
    else {
      DVar5 = 0x273f;
      local_38 = 0x273f;
    }
  }
  if ((DVar5 != 0) ||
     ((puVar4[3] == 2 && (DVar5 = FUN_c05282e4((int)puVar4,2,0xffffffff), DVar5 != 0))))
  goto LAB_c0522448;
  if (puVar4[3] == 1) {
    local_3c = param_7;
    puVar6 = FUN_c0527b7c(*(size_t *)(puVar4[0x14] + 0x10),0x13);
    if (puVar6 == (ushort *)0x0) {
      DVar5 = 0x2747;
      goto LAB_c0522448;
    }
    DVar5 = (**(code **)(*(int *)(puVar4[0x14] + 8) + 0x54))(puVar4[0x46],puVar6,&local_3c);
    if (DVar5 == 0) {
      if (local_3c == param_7) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar4 + 0x41));
        DVar5 = FUN_c051fdb0(puVar4[2],puVar6,(uint)local_3c);
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar4 + 0x41));
      }
      else {
        DVar5 = 0x271e;
      }
    }
    FUN_c0527bfc();
    if (DVar5 != 0) goto LAB_c0522448;
  }
  if (((puVar4[3] == 4) || (puVar4[3] == 0x40)) && (puVar4[0x48] != 0)) {
    DVar5 = FUN_c052129c((int)puVar4,local_40,local_30[0],(int)param_6,(int)param_7,local_34,
                         local_30,param_8,param_9,param_10,param_11);
  }
  else {
    DVar5 = 0x2741;
  }
LAB_c0522448:
  while (piVar3 = local_40, local_40 != (int *)0x0) {
    piVar7 = (int *)*local_40;
    if ((param_11 != 0) && (piVar1 = local_40 + 2, *piVar1 != 0)) {
      piVar2 = local_40 + 1;
      local_40 = piVar7;
      CeFreeAsynchronousBuffer(*piVar2,0xffffffff,*piVar1,0x80000004);
      piVar7 = local_40;
    }
    local_40 = piVar7;
    FUN_c0527df4((int)puVar4,piVar3);
  }
  if ((puVar4[0x22] & 2) != 0) {
    FUN_c0528468((int)puVar4,0,0,2);
  }
  FUN_c051eabc(puVar4);
  return DVar5;
}



/* c05224c8 FUN_c05224c8 */

/* Boundary evidence: original MIPS .pdata c05224c8..c05224d3. Semantic name remains unreviewed. */

undefined4 FUN_c05224c8(void)

{
  return 1;
}



/* c05224d4 FUN_c05224d4 */

/* Boundary evidence: original MIPS .pdata c05224d4..c0522523. Semantic name remains unreviewed. */

void FUN_c05224d4(uint param_1,int *param_2,int param_3,undefined4 *param_4,uint param_5,
                 ushort *param_6,undefined4 *param_7,int param_8,int param_9,undefined4 *param_10)

{
  FUN_c0521f80(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,1);
  return;
}



/* c0522524 FUN_c0522524 */

/* Boundary evidence: original MIPS .pdata c0522524..c052256f. Semantic name remains unreviewed. */

void FUN_c0522524(uint param_1,int *param_2,int param_3,undefined4 *param_4,uint param_5,
                 ushort *param_6,undefined4 *param_7,int param_8,int param_9,undefined4 *param_10)

{
  FUN_c0521f80(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,0);
  return;
}



/* c0522570 FUN_c0522570 */

/* Boundary evidence: original MIPS .pdata c0522570..c05225bb. Semantic name remains unreviewed. */

void FUN_c0522570(int param_1)

{
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
    FUN_c0528468(param_1,0x20,0,0x20);
    FUN_c051eabc((undefined4 *)param_1);
  }
  return;
}



/* c05225bc FUN_c05225bc */

/* Boundary evidence: original MIPS .pdata c05225bc..c05226ef. Semantic name remains unreviewed. */

int FUN_c05225bc(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar2;
  undefined4 local_30;
  code *local_2c;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 8);
  memset(&local_30,0,0x14);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x104);
  LeaveCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(iVar2 + 8))(&local_30,param_1);
  EnterCriticalSection(lpCriticalSection);
  if (iVar1 == 0) {
    if (((*(int *)(param_1 + 0xc) == 0x200) || (*(int **)(param_1 + 0x120) == (int *)0x0)) ||
       (iVar1 = **(int **)(param_1 + 0x120), iVar1 == 0)) {
      iVar1 = 0x22;
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
      iVar1 = (**(code **)(iVar2 + 0x10))(&local_30,iVar1);
      EnterCriticalSection(lpCriticalSection);
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x168) = local_30;
    }
    else {
      memset(&local_30,0,0x14);
      local_2c = FUN_c0522570;
      LeaveCriticalSection(lpCriticalSection);
      (**(code **)(iVar2 + 0xc))(&local_30);
      EnterCriticalSection(lpCriticalSection);
    }
  }
  return iVar1;
}



/* c05226f0 FUN_c05226f0 */

/* Boundary evidence: original MIPS .pdata c05226f0..c05227a3. Semantic name remains unreviewed. */

int FUN_c05226f0(int param_1)

{
  int iVar1;
  int local_28;
  code *local_24;
  int local_20;
  
  local_28 = *(int *)(param_1 + 0x168);
  if (local_28 == 0) {
    iVar1 = 0xf;
  }
  else {
    local_24 = FUN_c0522570;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    *(undefined4 *)(param_1 + 0x168) = 0;
    local_20 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
    iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0xc))(&local_28);
    if (iVar1 != 0xff) {
      FUN_c0522570(param_1);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
  }
  return iVar1;
}



/* c05227a4 FUN_c05227a4 */

/* Boundary evidence: original MIPS .pdata c05227a4..c05229ab. Semantic name remains unreviewed. */

void FUN_c05227a4(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  size_t _Size;
  int iVar3;
  uint uVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_28;
  code *local_24;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x41);
  EnterCriticalSection(lpCriticalSection);
  uVar1 = FUN_c051f74c(param_2);
  param_1[0x59] = uVar1;
  if (param_1[3] == 0x20) {
    if (param_2 == 0) {
      param_1[3] = 0x40;
      _Size = *(int *)(param_1[0x5b] + 0x34) + 2;
      param_1[0x4d] = _Size;
      memcpy((void *)param_1[0x4c],(void *)(param_1[0x5b] + 0x38),_Size);
      FUN_c051fb80((int)param_1,1);
      if ((param_1[5] & 2) != 0) {
        FUN_c0525488((int)param_1,2,1);
      }
      if ((param_1[5] & 8) != 0) {
        FUN_c0525488((int)param_1,1,1);
      }
      if ((param_1[5] & 0x80) != 0) {
        FUN_c0525488((int)param_1,3,1);
      }
      FUN_c051e150((int)param_1,4);
      FUN_c0528468((int)param_1,2,0,2);
      uVar4 = 0x10;
      uVar2 = 0x10;
      goto LAB_c0522974;
    }
    iVar3 = param_1[0x5a];
    if (iVar3 != 0) {
      memset(&local_28,0,0x14);
      local_24 = FUN_c0522570;
      param_1[0x5a] = 0;
      local_28 = iVar3;
      LeaveCriticalSection(lpCriticalSection);
      (**(code **)(*(int *)(param_1[0x14] + 8) + 0xc))(&local_28);
      EnterCriticalSection(lpCriticalSection);
    }
    iVar3 = param_1[0x59];
    uVar4 = 0x10;
    param_1[3] = 4;
    uVar2 = 0x100;
  }
  else {
    param_1[0x59] = 0x2714;
    param_1[4] = param_1[4] | 0x400;
    FUN_c0528468((int)param_1,0x100,0x2714,0x10);
    FUN_c0528468((int)param_1,2,0x2714,0);
    if (param_1[3] != 0x200) goto LAB_c0522980;
    uVar4 = 0;
    uVar2 = 0x20;
LAB_c0522974:
    iVar3 = 0;
  }
  FUN_c0528468((int)param_1,uVar2,iVar3,uVar4);
LAB_c0522980:
  FUN_c0527bfc();
  param_1[0x5b] = 0;
  FUN_c051eabc(param_1);
  return;
}



/* c05229ac FUN_c05229ac */

/* Boundary evidence: original MIPS .pdata c05229ac..c0522b17. Semantic name remains unreviewed. */

int FUN_c05229ac(undefined4 *param_1,void *param_2,size_t param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_40 [2];
  undefined4 local_38;
  code *local_34;
  undefined4 *local_30;
  
  iVar4 = param_1[0x14];
  local_40[0] = 0xffffffff;
  puVar1 = FUN_c0527b7c(*(int *)(iVar4 + 0x18) + 0x33,0x12);
  param_1[0x5b] = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    iVar4 = 1;
  }
  else {
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[1] = 0;
    puVar1[8] = 0;
    puVar1[6] = 0;
    puVar1[9] = 0;
    puVar1[7] = 0;
    puVar1[4] = *(undefined4 *)(iVar4 + 0x18);
    puVar1[10] = *(undefined4 *)(iVar4 + 0x18);
    iVar2 = param_1[0x5b];
    puVar3 = (undefined4 *)(iVar2 + 0x30);
    puVar1[5] = puVar3;
    puVar1[0xb] = puVar3;
    *puVar3 = 1;
    *(size_t *)(iVar2 + 0x34) = param_3 + 0xfffe & 0xffff;
    memcpy((void *)(iVar2 + 0x38),param_2,param_3);
    local_38 = param_1[0x5a];
    param_1[1] = param_1[1] + 1;
    local_34 = FUN_c05227a4;
    local_30 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
    iVar4 = (**(code **)(*(int *)(iVar4 + 8) + 0x18))(&local_38,local_40,puVar1,puVar1 + 6);
    if (iVar4 != 0xff) {
      FUN_c05227a4(param_1,iVar4);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
  }
  return iVar4;
}



/* c0522b18 FUN_c0522b18 */

/* Boundary evidence: original MIPS .pdata c0522b18..c0522b83. Semantic name remains unreviewed. */

void FUN_c0522b18(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
  param_1[4] = param_1[4] & 0xffffffdf | 0x100;
  FUN_c0528468((int)param_1,0x20,0,0x20);
  FUN_c0528468((int)param_1,2,0x2745,2);
  FUN_c051eabc(param_1);
  return;
}



/* c0522b84 FUN_c0522b84 */

/* Boundary evidence: original MIPS .pdata c0522b84..c0522ca3. Semantic name remains unreviewed. */

int FUN_c0522b84(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_30 [2];
  int local_28;
  code *local_24;
  undefined4 *local_20;
  
  local_30[0] = 0;
  uVar2 = 0;
  if ((param_2 == 0) && (*(short *)(param_1 + 0x40) != 0)) {
    if (*(ushort *)((int)param_1 + 0x102) == 0) {
      uVar2 = 2;
    }
    else {
      local_30[0] = (uint)*(ushort *)((int)param_1 + 0x102) * 1000;
    }
  }
  uVar1 = param_1[4];
  param_1[4] = uVar1 | 0x20;
  if ((uVar1 & 0x100) == 0) {
    local_28 = param_1[0x5a];
    if (local_28 == 0) {
      iVar3 = 0xf;
    }
    else {
      param_1[1] = param_1[1] + 1;
      local_24 = FUN_c0522b18;
      local_20 = param_1;
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
      iVar3 = (**(code **)(*(int *)(param_1[0x14] + 8) + 0x1c))(&local_28,local_30,uVar2,0,0);
      if (iVar3 != 0xff) {
        FUN_c0522b18(param_1);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
    }
  }
  else {
    iVar3 = 0x19;
  }
  return iVar3;
}



/* c0522ca4 FUN_c0522ca4 */

/* Boundary evidence: original MIPS .pdata c0522ca4..c0522e5f. Semantic name remains unreviewed. */

int FUN_c0522ca4(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  size_t _Size;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int local_20 [2];
  
  puVar1 = FUN_c051e220(*(int *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x18),
                        *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),local_20);
  if (puVar1 == (undefined4 *)0x0) {
    return local_20[0];
  }
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(puVar1 + 0x41);
  EnterCriticalSection(lpCriticalSection_00);
  puVar1[9] = *(undefined4 *)(param_1 + 0x24);
  puVar1[10] = *(undefined4 *)(param_1 + 0x28);
  puVar1[0xb] = *(undefined4 *)(param_1 + 0x2c);
  puVar1[0xc] = *(undefined4 *)(param_1 + 0x30);
  puVar1[0xd] = *(undefined4 *)(param_1 + 0x34);
  puVar1[0xe] = *(undefined4 *)(param_1 + 0x38);
  EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x120) + 0xc));
  iVar2 = *(int *)(param_1 + 0x120);
  puVar1[0x48] = iVar2;
  *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x120) + 0xc));
  _Size = *(size_t *)(param_1 + 300);
  puVar1[0x4b] = _Size;
  memcpy((void *)puVar1[0x4a],*(void **)(param_1 + 0x128),_Size);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x104);
  LeaveCriticalSection(lpCriticalSection);
  local_20[0] = FUN_c05225bc((int)puVar1);
  if (local_20[0] == 0) {
    puVar1[0x11] = param_1;
    LeaveCriticalSection(lpCriticalSection_00);
    EnterCriticalSection(lpCriticalSection);
    EnterCriticalSection(lpCriticalSection_00);
    if ((*(int *)(param_1 + 0xc) != 4) && (*(int *)(param_1 + 0xc) != 8)) {
      LeaveCriticalSection(lpCriticalSection);
      FUN_c05226f0((int)puVar1);
      FUN_c051fa74((int)puVar1);
      EnterCriticalSection(lpCriticalSection);
      local_20[0] = 0x2714;
      goto LAB_c0522e20;
    }
    puVar1[0x13] = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 **)(param_1 + 0x4c) = puVar1;
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  }
  else {
    local_20[0] = FUN_c051f74c(local_20[0]);
    EnterCriticalSection(lpCriticalSection);
  }
  if (local_20[0] == 0) {
    LeaveCriticalSection(lpCriticalSection_00);
    return local_20[0];
  }
LAB_c0522e20:
  puVar1[3] = 0x200;
  FUN_c051eabc(puVar1);
  return local_20[0];
}



/* c0522e60 FUN_c0522e60 */

/* Boundary evidence: original MIPS .pdata c0522e60..c0522fc7. Semantic name remains unreviewed. */

int FUN_c0522e60(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = 0x2736;
  }
  else {
    if (puVar1[7] == 1) {
      iVar2 = puVar1[3];
      if (iVar2 == 0x400) {
        iVar2 = 0x2742;
      }
      else if ((iVar2 == 0x40) || (iVar2 == 0x20)) {
        iVar2 = 0x2748;
      }
      else if (iVar2 == 4) {
        if ((puVar1[4] & 2) == 0) {
          if (5 < param_2) {
            param_2 = 5;
          }
          puVar1[0x17] = param_2;
          puVar1[4] = puVar1[4] | 2;
          do {
            iVar2 = FUN_c0522ca4((int)puVar1);
            if (iVar2 != 0) break;
          } while ((uint)puVar1[0x16] < (uint)puVar1[0x17]);
          if ((puVar1[0x16] != 0) && (puVar1[3] == 4)) {
            FUN_c051fc84((int)puVar1,1);
            iVar2 = FUN_c051e150((int)puVar1,2);
            if (iVar2 == 0) {
              puVar1[3] = 8;
            }
          }
        }
        else {
          iVar2 = 0x2734;
        }
      }
      else {
        iVar2 = 0x2726;
      }
    }
    else {
      iVar2 = 0x273d;
    }
    puVar1[4] = puVar1[4] & 0xfffffffd;
    FUN_c051eabc(puVar1);
  }
  return iVar2;
}



/* c0522fc8 FUN_c0522fc8 */

/* Boundary evidence: original MIPS .pdata c0522fc8..c0523373. Semantic name remains unreviewed. */

int FUN_c0522fc8(uint param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  ushort *_Src;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  size_t local_30 [2];
  
  iVar5 = 0;
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x2736;
  }
  iVar3 = puVar1[3];
  if (iVar3 == 0x400) {
    iVar5 = 0x2742;
    goto LAB_c052333c;
  }
  if (iVar3 == 0x40) {
    if (puVar1[7] == 1) {
      iVar5 = 0x2748;
      goto LAB_c052333c;
    }
  }
  else if ((iVar3 != 1) && (iVar3 != 4)) {
    iVar5 = 0x2726;
    goto LAB_c052333c;
  }
  if ((puVar1[4] & 2) != 0) {
    iVar5 = 0x2734;
    goto LAB_c052333c;
  }
  if (param_3 < *(uint *)(puVar1[0x14] + 0xc)) {
    iVar5 = 0x271e;
    goto LAB_c052333c;
  }
  uVar2 = *(uint *)(puVar1[0x14] + 0x10);
  if (uVar2 < param_3) {
    param_3 = uVar2;
  }
  _Src = FUN_c0527b7c(uVar2,0x13);
  if (_Src == (ushort *)0x0) {
    iVar5 = 0x2747;
  }
  else {
    local_30[0] = param_3;
    if (puVar1[3] == 1) {
      iVar5 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x54))(puVar1[0x46],_Src,local_30);
      if (iVar5 == 0) {
        if (local_30[0] != param_3) goto LAB_c052318c;
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
        iVar5 = FUN_c051fdb0(puVar1[2],_Src,local_30[0]);
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
        if (iVar5 == 0) {
          if (puVar1[3] == 4) {
            if ((puVar1[4] & 2) != 0) {
              iVar5 = 0x2734;
            }
            if (iVar5 == 0) goto LAB_c0523178;
          }
          else {
            iVar5 = 0x2726;
          }
        }
      }
    }
    else {
LAB_c0523178:
      iVar3 = CeSafeCopyMemory(_Src,param_2,local_30[0]);
      if (iVar3 == 0) {
LAB_c052318c:
        iVar5 = 0x271e;
      }
      else if ((uint)*_Src == puVar1[6]) {
        if ((puVar1[7] == 2) || (puVar1[7] == 3)) {
          iVar3 = FUN_c051f8d4((short *)_Src,param_3);
          if (iVar3 == 0) {
            memcpy((void *)puVar1[0x4c],_Src,param_3);
            puVar1[0x4d] = param_3;
            puVar1[3] = 0x40;
            puVar6 = puVar1 + 0x57;
            while (puVar4 = (undefined4 *)*puVar6, puVar4 != (undefined4 *)0x0) {
              if ((*(short *)(puVar4 + 1) == 0) ||
                 (iVar3 = memcmp(puVar4 + 4,_Src,param_3), iVar3 != 0)) {
                *puVar6 = *puVar4;
                puVar1[0x36] = puVar1[0x36] + -1;
                FUN_c0527bfc();
              }
              else {
                puVar1[0x58] = puVar4;
                puVar6 = puVar4;
              }
            }
          }
          else {
            puVar1[3] = 4;
            memset((void *)puVar1[0x4c],0,param_3);
            puVar1[0x4d] = 0;
          }
        }
        else {
          puVar1[3] = 0x20;
          EventModify(puVar1[0x1a],2);
          puVar1[0x59] = 0;
          iVar3 = FUN_c05225bc((int)puVar1);
          if (iVar3 == 0) {
            iVar3 = FUN_c05229ac(puVar1,_Src,param_3);
            if (iVar3 == 0) {
              iVar5 = 0;
            }
            else {
              if (iVar3 != 0xff) goto LAB_c0523204;
              if (puVar1[3] == 0x20) {
                if ((puVar1[4] & 1) == 0) {
                  iVar5 = FUN_c05282e4((int)puVar1,0x10,0xffffffff);
                }
                else {
                  iVar5 = 0x2733;
                }
              }
              else if (puVar1[0x59] != 0) {
                iVar5 = puVar1[0x59];
              }
            }
          }
          else {
            if ((int)puVar1[3] < 0x41) {
              puVar1[3] = 4;
            }
LAB_c0523204:
            iVar5 = FUN_c051f74c(iVar3);
          }
        }
      }
      else {
        iVar5 = 0x273f;
      }
    }
  }
  if (_Src != (ushort *)0x0) {
    FUN_c0527bfc();
  }
LAB_c052333c:
  FUN_c051eabc(puVar1);
  return iVar5;
}



/* c0523374 FUN_c0523374 */

/* Boundary evidence: original MIPS .pdata c0523374..c0523c47. Semantic name remains unreviewed. */

int FUN_c0523374(uint param_1,uint *param_2,void *param_3,uint param_4,uint *param_5,
                undefined *param_6,undefined4 param_7)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  HANDLE pvVar4;
  BOOL BVar5;
  uint *puVar6;
  undefined4 *puVar7;
  HLOCAL hMem;
  int iVar8;
  HLOCAL hMem_00;
  HANDLE local_78;
  undefined4 *local_74;
  uint local_70;
  undefined4 *local_6c;
  HANDLE local_68;
  HLOCAL local_64;
  HLOCAL local_60;
  uint *local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  HLOCAL local_4c;
  undefined4 local_48;
  HLOCAL local_44;
  undefined4 local_40;
  undefined4 local_3c;
  HANDLE local_38;
  undefined *local_34;
  undefined4 *local_30;
  
  iVar8 = 0;
  local_58 = 0;
  local_54 = 0;
  local_70 = param_4;
  local_5c = param_2;
  puVar2 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar2 == (undefined4 *)0x0) {
    return 0x2736;
  }
  if ((param_3 == (void *)0x0) || (param_5 == (uint *)0x0)) {
    param_4 = 0;
    local_70 = 0;
  }
  local_6c = puVar2;
  if (puVar2[7] == 1) {
    if (puVar2[3] == 0x400) {
      iVar8 = 0x2742;
    }
    else if (puVar2[3] == 8) {
      if ((param_3 == (void *)0x0) || ((param_5 != (uint *)0x0 && ((uint)puVar2[0x4b] <= param_4))))
      {
        if ((param_5 != (uint *)0x0) && ((param_3 == (void *)0x0 || (param_4 == 0)))) {
          param_3 = (void *)0x0;
          iVar8 = FUN_c0527ce8(param_5,0);
        }
        if (iVar8 == 0) {
          if (puVar2[0x15] == 0) {
            if ((puVar2[4] & 1) == 0) {
              do {
                iVar8 = FUN_c05282e4((int)puVar2,8,0xffffffff);
                if (iVar8 != 0) goto LAB_c0523894;
              } while (puVar2[0x15] == 0);
            }
            else {
              iVar8 = 0x2733;
            }
          }
          if ((iVar8 == 0) && (param_6 != (undefined *)0x0)) {
            puVar7 = (undefined4 *)puVar2[0x12];
            local_74 = puVar7;
            FUN_c051ea88((int)puVar7);
            if ((puVar7[0x4d] == 0) ||
               (local_4c = LocalAlloc(0x40,puVar7[0x4d]), local_64 = local_4c,
               local_4c == (HLOCAL)0x0)) {
              local_50 = 0;
              local_4c = (HLOCAL)0x0;
              hMem = local_64;
            }
            else {
              local_50 = 1;
              memcpy(local_4c,(void *)puVar7[0x4c],puVar7[0x4d]);
              hMem = local_4c;
            }
            iVar3 = FUN_c051fb80((int)puVar7,1);
            if (iVar3 != 0) {
              if (hMem != (HLOCAL)0x0) {
                LocalFree(hMem);
              }
              puVar2[0x12] = puVar7[0x12];
              puVar2[0x15] = puVar2[0x15] + -1;
              *(undefined2 *)(puVar7 + 0x40) = 1;
              *(undefined2 *)((int)puVar7 + 0x102) = 0;
              puVar7[3] = 0x200;
              FUN_c051eee4(puVar7);
              FUN_c0522ca4((int)puVar2);
              iVar8 = FUN_c051f74c(iVar3);
              goto LAB_c0523424;
            }
            if ((puVar7[0x4b] == 0) ||
               (local_44 = LocalAlloc(0x40,puVar7[0x4b]), local_60 = local_44,
               local_44 == (HLOCAL)0x0)) {
              local_48 = 0;
              local_44 = (HLOCAL)0x0;
              hMem_00 = local_60;
            }
            else {
              local_48 = 1;
              memcpy(local_44,(void *)puVar7[0x4a],puVar7[0x4b]);
              hMem_00 = local_44;
            }
            local_40 = 0;
            local_3c = 0;
            local_78 = (HANDLE)GetCallerProcess();
            pvVar4 = (HANDLE)__GetUserKData(0xc);
            if (local_78 == pvVar4) {
              local_78 = (HANDLE)(*(code *)param_6)(&local_50);
            }
            else {
              local_38 = local_78;
              local_34 = param_6;
              local_30 = &local_50;
              local_78 = (HANDLE)(*(code *)&SUB_ffffbb8a)
                                           (&local_38,0,0,0,&local_48,&local_40,0,param_7);
            }
            local_68 = local_78;
            if (hMem != (HLOCAL)0x0) {
              LocalFree(hMem);
            }
            if (hMem_00 != (HLOCAL)0x0) {
              LocalFree(hMem_00);
            }
            if (local_78 == (HANDLE)0x2) {
              FUN_c051eabc(puVar7);
              iVar8 = 0x2afa;
            }
            else if (local_78 == (HANDLE)0x1) {
              puVar7 = (undefined4 *)puVar2[0x12];
              puVar2[0x12] = puVar7[0x12];
              puVar2[0x15] = puVar2[0x15] + -1;
              *(undefined2 *)(puVar7 + 0x40) = 1;
              *(undefined2 *)((int)puVar7 + 0x102) = 0;
              puVar7[3] = 0x200;
              FUN_c051eee4(puVar7);
              FUN_c0522ca4((int)puVar2);
              iVar8 = 0x274d;
            }
            else {
              FUN_c051eabc(puVar7);
            }
          }
        }
LAB_c0523894:
        if (iVar8 == 0) {
          puVar7 = (undefined4 *)puVar2[0x12];
          local_74 = puVar7;
          FUN_c051ea88((int)puVar7);
          puVar7[0x1e] = puVar2[0x1e];
          puVar7[0x21] = puVar2[0x21];
          puVar7[0x23] = 0xfffffcff;
          puVar2[0x12] = puVar7[0x12];
          puVar2[0x15] = puVar2[0x15] + -1;
          FUN_c0522ca4((int)puVar2);
          if ((puVar2[4] & 0x800) != 0) {
            local_58 = 1;
          }
          if ((puVar2[4] & 0x2000) != 0) {
            local_54 = 1;
            puVar7[4] = puVar7[4] | 0x2000;
          }
          if (puVar2[0x12] == 0) {
            puVar2[0x22] = puVar2[0x22] & 0xfffffff7;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
          local_60 = (HLOCAL)FUN_c051fb80((int)puVar7,1);
          if (local_60 == (HLOCAL)0x0) {
            FUN_c051e150((int)puVar7,8);
            FUN_c051f618((int)puVar2,(int)puVar7);
            puVar7[3] = 0x40;
            FUN_c0528468((int)puVar7,2,0,2);
            if (puVar7[0x30] != 0) {
              FUN_c0528468((int)puVar7,1,0,1);
            }
            if (param_3 != (void *)0x0) {
              if (local_70 < (uint)puVar7[0x4d]) {
                *param_5 = 0;
              }
              else {
                *param_5 = puVar7[0x4d];
                memcpy(param_3,(void *)puVar7[0x4c],puVar7[0x4d]);
              }
            }
            puVar1 = local_5c;
            LeaveCriticalSection((LPCRITICAL_SECTION)(puVar7 + 0x41));
            local_5c = (uint *)FUN_c051dff8((int)puVar7);
            puVar6 = local_5c;
            if (((local_58 == 0) &&
                (local_78 = (HANDLE)CreateAPIHandle(DAT_c052e45c,local_5c), puVar6 = local_78,
                local_54 == 0)) && (local_78 != (HANDLE)0xffffffff)) {
              pvVar4 = (HANDLE)__GetUserKData(0xc);
              BVar5 = DuplicateHandle(pvVar4,local_78,(HANDLE)puVar7[9],&local_78,0,0,3);
              puVar6 = local_78;
              if (BVar5 == 0) {
                local_78 = (HANDLE)0xffffffff;
                puVar6 = (HANDLE)0xffffffff;
              }
            }
            *puVar1 = (uint)puVar6;
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
            EnterCriticalSection((LPCRITICAL_SECTION)(puVar7 + 0x41));
            puVar7[0xf] = DAT_c052e428;
            DAT_c052e454 = DAT_c052e454 + 1;
            DAT_c052e428 = puVar7;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
            FUN_c051eabc(puVar7);
          }
          else {
            *(undefined2 *)(puVar7 + 0x40) = 1;
            *(undefined2 *)((int)puVar7 + 0x102) = 0;
            puVar7[3] = 0x200;
            FUN_c051eee4(puVar7);
            iVar8 = FUN_c051f74c((int)local_60);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
        }
      }
      else {
        iVar8 = 0x271e;
      }
    }
    else {
      iVar8 = 0x2726;
    }
  }
  else {
    iVar8 = 0x273d;
  }
LAB_c0523424:
  puVar2[0x23] = puVar2[0x23] | 8;
  if (puVar2[0x12] != 0) {
    FUN_c0528468((int)puVar2,0,0,8);
  }
  FUN_c051eabc(puVar2);
  return iVar8;
}



/* c0523c48 FUN_c0523c48 */

/* Boundary evidence: original MIPS .pdata c0523c48..c0523c53. Semantic name remains unreviewed. */

undefined4 FUN_c0523c48(void)

{
  return 1;
}



/* c0523c54 FUN_c0523c54 */

/* Boundary evidence: original MIPS .pdata c0523c54..c0523c5f. Semantic name remains unreviewed. */

undefined4 FUN_c0523c54(void)

{
  return 1;
}



/* c0523c60 FUN_c0523c60 */

/* Boundary evidence: original MIPS .pdata c0523c60..c0523c6b. Semantic name remains unreviewed. */

undefined4 FUN_c0523c60(void)

{
  return 1;
}



/* c0523c6c FUN_c0523c6c */

/* Boundary evidence: original MIPS .pdata c0523c6c..c0523d13. Semantic name remains unreviewed. */

HANDLE FUN_c0523c6c(void)

{
  HANDLE pvVar1;
  LONG *Target;
  
  Target = &DAT_c052e520;
  while ((*Target == 0 || (pvVar1 = (HANDLE)InterlockedExchange(Target,0), pvVar1 == (HANDLE)0x0)))
  {
    Target = Target + 1;
    if (-0x3fad1ab9 < (int)Target) {
      pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      return pvVar1;
    }
  }
  EventModify(pvVar1,2);
  return pvVar1;
}



/* c0523d14 FUN_c0523d14 */

/* Boundary evidence: original MIPS .pdata c0523d14..c0523d8b. Semantic name remains unreviewed. */

void FUN_c0523d14(HANDLE param_1)

{
  LONG *Target;
  
  Target = &DAT_c052e520;
  while ((*Target != 0 ||
         (param_1 = (HANDLE)InterlockedExchange(Target,(LONG)param_1), param_1 != (HANDLE)0x0))) {
    Target = Target + 1;
    if (-0x3fad1ab9 < (int)Target) {
      CloseHandle(param_1);
      return;
    }
  }
  return;
}



/* c0523d8c FUN_c0523d8c */

/* Boundary evidence: original MIPS .pdata c0523d8c..c052406b. Semantic name remains unreviewed. */

int FUN_c0523d8c(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  
  iVar6 = 0;
  if (param_1 != 0) {
    while( true ) {
      puVar5 = (uint *)(param_2 + 1);
      param_1 = param_1 + -1;
      param_2[5] = 0;
      if (*param_2 != 0) {
        if (param_5 == 0) {
          uVar1 = GetCallerProcess();
        }
        else {
          uVar1 = 0x42;
        }
        iVar2 = LockAPIHandle(DAT_c052e45c,uVar1,*param_2,puVar5);
        param_2[5] = iVar2;
        if (iVar2 == 0) {
          *puVar5 = 0;
        }
      }
      if (*puVar5 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_c051eaf8(*puVar5);
      }
      param_2[4] = iVar2;
      if (iVar2 == 0) break;
      if (*param_2 == 0) {
        *param_2 = -1;
      }
      iVar4 = *(int *)(iVar2 + 0xc);
      if ((iVar4 == 0x100) || (iVar4 == 0x200)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x104));
        break;
      }
      if (iVar4 == 0x400) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x104));
        return 0x2742;
      }
      if (param_3 == 0x29) {
        if ((*(int *)(iVar2 + 0x1c) == 2) || (*(int *)(iVar2 + 0x1c) == 3)) {
          uVar3 = *(uint *)(iVar2 + 0x15c);
LAB_c0523f20:
          if (uVar3 == 0) {
            iVar4 = 0x29;
            goto LAB_c0523f2c;
          }
LAB_c0523ff0:
          EventModify(param_4,3);
        }
        else {
          if ((*(uint *)(iVar2 + 0x10) & 8) == 0) {
            if (((((iVar4 == 8) && (*(int *)(iVar2 + 0x48) != 0)) || (*(int *)(iVar2 + 0xc0) != 0))
                || ((*(int *)(iVar2 + 0xc4) != 0 || (*(int *)(iVar2 + 200) != 0)))) ||
               (0x7f < iVar4)) goto LAB_c0523ff0;
            uVar3 = *(uint *)(iVar2 + 0x10) & 0x600;
            goto LAB_c0523f20;
          }
          iVar6 = 0x2734;
        }
      }
      else {
        if (param_3 == 0x12) {
          if ((((*(int *)(iVar2 + 0x1c) == 2) || (*(int *)(iVar2 + 0x1c) == 3)) ||
              ((iVar4 == 0x40 &&
               ((*(int *)(iVar2 + 0x154) == 0 && (*(uint *)(iVar2 + 0xe8) < *(uint *)(iVar2 + 0xf0))
                ))))) ||
             ((0x40 < iVar4 ||
              (((*(uint *)(iVar2 + 0x10) & 0x500) != 0 || ((*(uint *)(iVar2 + 0x14) & 0x40) != 0))))
             )) goto LAB_c0523ff0;
          iVar4 = 0x12;
        }
        else if (((0x7f < iVar4) || ((*(uint *)(iVar2 + 0x10) & 0x600) != 0)) ||
                (iVar4 = param_3, *(int *)(iVar2 + 0x164) != 0)) goto LAB_c0523ff0;
LAB_c0523f2c:
        iVar6 = FUN_c052878c(iVar2,iVar4,param_4);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x104));
      if (iVar6 != 0) {
        return iVar6;
      }
      param_2 = param_2 + 6;
      if (param_1 == 0) {
        return 0;
      }
    }
    iVar6 = 0x2736;
  }
  return iVar6;
}



/* c052406c FUN_c052406c */

/* Boundary evidence: original MIPS .pdata c052406c..c0524157. Semantic name remains unreviewed. */

void FUN_c052406c(int param_1,int *param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  
  while (param_1 != 0) {
    param_1 = param_1 + -1;
    if (param_2[5] != 0) {
      UnlockAPIHandle(DAT_c052e45c);
    }
    if ((param_2[1] != 0) && (*param_2 != 0)) {
      if (*param_2 == -1) {
        *param_2 = 0;
      }
      puVar2 = (undefined4 *)param_2[4];
      if (puVar2 != (undefined4 *)0x0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
        bVar1 = FUN_c05287f8((int)puVar2,param_2[2],param_3);
        if ((CONCAT31(extraout_var,bVar1) != 0) && (param_4 == 0)) {
          param_2[1] = 0;
          param_2[4] = 0;
        }
        FUN_c051eabc(puVar2);
        param_2 = param_2 + 6;
      }
    }
  }
  return;
}



/* c0524158 FUN_c0524158 */

/* Boundary evidence: original MIPS .pdata c0524158..c05243f7. Semantic name remains unreviewed. */

undefined4 FUN_c0524158(uint param_1,HANDLE param_2,uint param_3)

{
  undefined4 *puVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  HANDLE local_20 [2];
  
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x2736;
  }
  pvVar2 = param_2;
  if (puVar1[9] != -1) {
    pvVar2 = (HANDLE)__GetUserKData(0xc);
    BVar3 = DuplicateHandle((HANDLE)puVar1[9],param_2,pvVar2,local_20,0,0,2);
    pvVar2 = local_20[0];
    if (BVar3 == 0) {
      pvVar2 = (HANDLE)0x0;
    }
  }
  local_20[0] = pvVar2;
  if (param_3 == 0) {
    if (((HANDLE)puVar1[0x1e] != (HANDLE)0x0) && (puVar1[9] != -1)) {
      CloseHandle((HANDLE)puVar1[0x1e]);
    }
    puVar1[0x1e] = 0;
    uVar6 = 0;
    puVar1[0x22] = 0;
    puVar1[0x21] = 0;
    goto LAB_c05243cc;
  }
  if (local_20[0] == (HANDLE)0x0) {
    uVar6 = 0x2726;
    goto LAB_c05243cc;
  }
  puVar1[4] = puVar1[4] | 1;
  if (((HANDLE)puVar1[0x1e] != (HANDLE)0x0) && (puVar1[9] != -1)) {
    CloseHandle((HANDLE)puVar1[0x1e]);
  }
  puVar1[0x1e] = local_20[0];
  uVar6 = 0;
  uVar5 = 0;
  puVar1[0x21] = param_3;
  puVar1[0x22] = 0;
  puVar1[0x23] = 0xfffffcff;
  if ((param_3 & 1) != 0) {
    if ((puVar1[7] == 2) || (puVar1[7] == 3)) {
      iVar4 = puVar1[0x57];
joined_r0xc05242dc:
      if (iVar4 == 0) goto LAB_c05242e8;
    }
    else if ((puVar1[0x30] == 0) && (puVar1[0x31] == 0)) {
      iVar4 = puVar1[0x32];
      goto joined_r0xc05242dc;
    }
    uVar5 = 1;
  }
LAB_c05242e8:
  if (((param_3 & 2) != 0) &&
     (((puVar1[7] == 2 || (puVar1[7] == 3)) ||
      ((puVar1[3] == 0x40 && ((uint)puVar1[0x3a] < (uint)puVar1[0x3c])))))) {
    uVar5 = uVar5 | 2;
  }
  if ((((param_3 & 8) != 0) && (puVar1[3] == 8)) && (puVar1[0x12] != 0)) {
    uVar5 = uVar5 | 8;
  }
  if (((param_3 & 0x10) != 0) && (puVar1[3] == 0x40)) {
    uVar5 = uVar5 | 0x10;
  }
  if (((param_3 & 0x20) != 0) && ((puVar1[4] & 0x600) != 0)) {
    uVar5 = uVar5 | 0x20;
  }
  if (uVar5 != 0) {
    EventModify(local_20[0],3);
    puVar1[0x23] = ~uVar5 & puVar1[0x23];
    puVar1[0x22] = puVar1[0x22] | uVar5;
  }
LAB_c05243cc:
  FUN_c051eabc(puVar1);
  return uVar6;
}



/* c05243f8 FUN_c05243f8 */

/* Boundary evidence: original MIPS .pdata c05243f8..c05245f7. Semantic name remains unreviewed. */

undefined4 FUN_c05243f8(uint param_1,HANDLE param_2,uint *param_3)

{
  undefined4 *puVar1;
  HANDLE hTargetProcessHandle;
  BOOL BVar2;
  uint uVar3;
  undefined4 uVar4;
  HANDLE local_1c;
  
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar4 = 0x2736;
  }
  else {
    uVar3 = puVar1[0x22] & puVar1[0x21];
    *param_3 = uVar3;
    local_1c = (HANDLE)0x0;
    for (; uVar3 != 0; uVar3 = (int)uVar3 >> 1) {
      if ((uVar3 & 1) != 0) {
        param_3[(int)local_1c + 1] = puVar1[(int)local_1c + 0x24];
      }
      local_1c = (HANDLE)((int)local_1c + 1);
    }
    uVar4 = 0;
    puVar1[0x22] = 0;
    if (param_2 != (HANDLE)0x0) {
      if (puVar1[9] == -1) {
        EventModify(param_2,2);
      }
      else {
        hTargetProcessHandle = (HANDLE)__GetUserKData(0xc);
        BVar2 = DuplicateHandle((HANDLE)puVar1[9],param_2,hTargetProcessHandle,&local_1c,0,0,2);
        if (BVar2 == 0) {
          uVar4 = 0x2726;
        }
        else {
          EventModify(local_1c,2);
          CloseHandle(local_1c);
        }
      }
    }
    FUN_c051eabc(puVar1);
  }
  return uVar4;
}



/* c05245f8 FUN_c05245f8 */

/* Boundary evidence: original MIPS .pdata c05245f8..c0524603. Semantic name remains unreviewed. */

undefined4 FUN_c05245f8(void)

{
  return 1;
}



/* c0524604 FUN_c0524604 */

/* Boundary evidence: original MIPS .pdata c0524604..c052460f. Semantic name remains unreviewed. */

undefined4 FUN_c0524604(void)

{
  return 1;
}



/* c0524610 FUN_c0524610 */

/* Boundary evidence: original MIPS .pdata c0524610..c052479b. Semantic name remains unreviewed. */

int FUN_c0524610(int param_1,int *param_2,int param_3,int *param_4,int param_5,int *param_6,
                int *param_7,int param_8)

{
  HANDLE hHandle;
  int iVar1;
  DWORD dwMilliseconds;
  
  hHandle = FUN_c0523c6c();
  iVar1 = FUN_c0523d8c(param_1,param_2,0x29,hHandle,param_8);
  if (iVar1 == 0) {
    iVar1 = FUN_c0523d8c(param_3,param_4,0x12,hHandle,param_8);
    if (iVar1 == 0) {
      iVar1 = FUN_c0523d8c(param_5,param_6,0x104,hHandle,param_8);
      if (iVar1 == 0) {
        if (param_7 == (int *)0x0) {
          dwMilliseconds = 0xffffffff;
        }
        else {
          dwMilliseconds = param_7[1] / 1000 + *param_7 * 1000;
          if (dwMilliseconds == 0) goto LAB_c0524720;
        }
        WaitForSingleObject(hHandle,dwMilliseconds);
      }
    }
  }
LAB_c0524720:
  FUN_c052406c(param_1,param_2,(int)hHandle,iVar1);
  FUN_c052406c(param_3,param_4,(int)hHandle,iVar1);
  FUN_c052406c(param_5,param_6,(int)hHandle,iVar1);
  if (hHandle != (HANDLE)0x0) {
    FUN_c0523d14(hHandle);
  }
  return iVar1;
}



/* c052479c FUN_c052479c */

/* Boundary evidence: original MIPS .pdata c052479c..c05247cf. Semantic name remains unreviewed. */

void FUN_c052479c(int param_1,int *param_2,int param_3,int *param_4,int param_5,int *param_6,
                 int *param_7)

{
  FUN_c0524610(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



/* c05247d0 FUN_c05247d0 */

/* Boundary evidence: original MIPS .pdata c05247d0..c0524807. Semantic name remains unreviewed. */

void FUN_c05247d0(int param_1,int *param_2,int param_3,int *param_4,int param_5,int *param_6,
                 int *param_7)

{
  FUN_c0524610(param_1,param_2,param_3,param_4,param_5,param_6,param_7,1);
  return;
}



/* c0524808 FUN_c0524808 */

/* Boundary evidence: original MIPS .pdata c0524808..c0524adb. Semantic name remains unreviewed. */

int FUN_c0524808(uint param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
                int param_7)

{
  int iVar1;
  int *hMem;
  int iVar2;
  int *piVar3;
  int aiStack_30 [2];
  
  if (((0x40 < param_1) || (0x40 < param_3)) || (0x40 < param_5)) {
    return 0x2747;
  }
  if (((((param_7 != 0) && (iVar1 = CeSafeCopyMemory(aiStack_30,param_7,8), iVar1 == 0)) ||
       ((param_2 != 0 && ((param_2 < 0x10000 || (0x6fffffff < param_2 + 0x18U)))))) ||
      ((param_4 != 0 && ((param_4 < 0x10000 || (0x6fffffff < param_4 + 0x18U)))))) ||
     ((param_6 != 0 && ((param_6 < 0x10000 || (0x6fffffff < param_6 + 0x18U)))))) {
    return 0x271e;
  }
  hMem = LocalAlloc(0,(param_1 + param_3 + param_5) * 0x18);
  if (hMem == (int *)0x0) {
    return 0x2747;
  }
  if ((((param_1 == 0) || (iVar1 = CeSafeCopyMemory(hMem,param_2,param_1 * 0x18), iVar1 != 0)) &&
      ((param_3 == 0 ||
       (iVar1 = CeSafeCopyMemory(hMem + param_1 * 6,param_4,param_3 * 0x18), iVar1 != 0)))) &&
     ((param_5 == 0 ||
      (iVar1 = CeSafeCopyMemory(hMem + (param_1 + param_3) * 6,param_6,param_5 * 0x18), iVar1 != 0))
     )) {
    piVar3 = aiStack_30;
    if (param_7 == 0) {
      piVar3 = (int *)0x0;
    }
    iVar1 = FUN_c0524610(param_1,hMem,param_3,hMem + param_1 * 6,param_5,
                         hMem + (param_1 + param_3) * 6,piVar3,0);
    if ((((param_1 == 0) || (iVar2 = CeSafeCopyMemory(param_2,hMem,param_1 * 0x18), iVar2 != 0)) &&
        ((param_3 == 0 ||
         (iVar2 = CeSafeCopyMemory(param_4,hMem + param_1 * 6,param_3 * 0x18), iVar2 != 0)))) &&
       ((param_5 == 0 ||
        (iVar2 = CeSafeCopyMemory(param_6,hMem + (param_1 + param_3) * 6,param_5 * 0x18), iVar2 != 0
        )))) goto LAB_c0524a98;
  }
  iVar1 = 0x271e;
LAB_c0524a98:
  LocalFree(hMem);
  return iVar1;
}



/* c0524adc FUN_c0524adc */

/* Boundary evidence: original MIPS .pdata c0524adc..c0524bfb. Semantic name remains unreviewed. */

int FUN_c0524adc(int param_1,void *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 local_498;
  undefined4 local_494;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c052e2d8;
  if (param_3 < 0x274) {
    iVar1 = 0x271e;
  }
  else {
    local_4a0 = *(undefined4 *)(param_1 + 0x2c);
    local_49c = *(undefined4 *)(param_1 + 0x30);
    local_498 = *(undefined4 *)(param_1 + 0x34);
    local_494 = *(undefined4 *)(param_1 + 0x38);
    iVar1 = FUN_c0529d68(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x20),
                         *(int *)(param_1 + 0x28),2,&local_4a0,0x274,awStack_228);
    if (iVar1 == 0) {
      *param_4 = 0x274;
      memcpy(param_2,&local_4a0,0x274);
    }
  }
  FUN_c052c8e4(local_20);
  return iVar1;
}



/* c0524bfc FUN_c0524bfc */

/* Boundary evidence: original MIPS .pdata c0524bfc..c0524c07. Semantic name remains unreviewed. */

undefined4 FUN_c0524bfc(void)

{
  return 1;
}



/* c0524c08 FUN_c0524c08 */

/* Boundary evidence: original MIPS .pdata c0524c08..c052543f. Semantic name remains unreviewed. */

int FUN_c0524c08(uint param_1,int param_2,uint param_3,undefined4 *param_4,uint param_5,
                size_t *param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uBytes;
  HLOCAL _Src;
  int iVar5;
  HLOCAL pvVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  iVar4 = 0;
  iVar5 = 1;
  _Src = (HLOCAL)0x0;
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  uBytes = param_5;
  if (puVar1 == (undefined4 *)0x0) {
    return 0x2736;
  }
  if (10000000 < param_5) {
    iVar4 = 0x2726;
    goto LAB_c05253d8;
  }
  if (puVar1[3] == 0x400) {
    iVar4 = 0x2742;
    goto LAB_c05253d8;
  }
  puVar7 = puVar1;
  if (((param_2 == 0xffff) || (param_2 == 6)) || (param_2 == 0)) {
    memset(param_4,0,param_5);
  }
  if (param_2 == 0) {
    if ((puVar1[7] == 1) && (param_3 != 100)) {
LAB_c0524f14:
      iVar4 = 0x273a;
      goto LAB_c05253d8;
    }
    if (param_3 == 2) {
      puVar3 = (undefined4 *)puVar1[0x6d];
    }
    else if (param_3 == 3) {
      puVar3 = (undefined4 *)(uint)*(byte *)(puVar1 + 0x6e);
    }
    else if (param_3 == 4) {
LAB_c05250d0:
      puVar3 = (undefined4 *)0x0;
    }
    else {
      if (param_3 != 100) goto LAB_c0524f14;
      puVar3 = (undefined4 *)puVar1[0x6c];
    }
LAB_c052538c:
    if ((iVar4 != 0) || (iVar5 == 0)) goto LAB_c05253d8;
    if (3 < uBytes) {
      *param_6 = 4;
      *param_4 = puVar3;
      goto LAB_c05253d8;
    }
  }
  else {
    if (param_2 == 6) {
      if ((param_3 != 1) || (puVar1[7] != 1)) goto LAB_c0524f14;
      puVar3 = (undefined4 *)(puVar1[5] & 8);
      goto LAB_c052538c;
    }
    if (param_2 != 0xff) {
      if (param_2 == 0xffff) {
        puVar3 = (undefined4 *)puVar1[7];
        if ((puVar3 != (undefined4 *)0x1) &&
           (((((param_3 == 8 || (param_3 == 0x80)) || (param_3 == 0xff7f)) ||
             ((param_3 == 2 || (param_3 == 0x100)))) || (param_3 == 0xffffff7f))))
        goto LAB_c0524f14;
        if (param_3 < 0x1003) {
          if (param_3 == 0x1002) {
            puVar3 = (undefined4 *)puVar1[0x3d];
          }
          else if (param_3 == 2) {
            puVar3 = (undefined4 *)0x1;
            if (puVar1[3] != 8) {
              puVar3 = (undefined4 *)0x0;
            }
          }
          else if (param_3 == 4) {
            puVar3 = (undefined4 *)(puVar1[5] & 1);
          }
          else if (param_3 == 8) {
            puVar3 = (undefined4 *)(puVar1[5] & 2);
          }
          else if (param_3 == 0x20) {
            if (puVar3 == (undefined4 *)0x1) goto LAB_c0524f14;
            puVar3 = (undefined4 *)(puVar1[5] & 4);
          }
          else if (param_3 == 0x80) {
            if (uBytes < 4) {
              iVar4 = 0x271e;
            }
            else {
              *param_6 = 4;
              *param_4 = puVar1[0x40];
            }
            iVar5 = 0;
            puVar3 = puVar7;
          }
          else if (param_3 == 0x100) {
            puVar3 = (undefined4 *)(puVar1[5] & 0x80);
          }
          else {
            if (param_3 != 0x1001) goto LAB_c05250cc;
            puVar3 = (undefined4 *)puVar1[0x3c];
          }
        }
        else if (param_3 == 0x1005) {
          puVar3 = (undefined4 *)puVar1[0x3f];
        }
        else if (param_3 == 0x1006) {
          puVar3 = (undefined4 *)puVar1[0x3e];
        }
        else if (param_3 == 0x1007) {
          puVar3 = (undefined4 *)puVar1[0x18];
          puVar1[0x18] = 0;
          uBytes = param_5;
        }
        else if (param_3 != 0x1008) {
          if (param_3 == 0x2005) {
            iVar4 = FUN_c0524adc((int)puVar1,param_4,uBytes,param_6);
            uBytes = param_5;
            goto LAB_c05252e4;
          }
          if ((param_3 != 0xff7f) && (param_3 != 0xffffff7f)) {
LAB_c05250cc:
            iVar4 = 0x273a;
            goto LAB_c05250d0;
          }
          puVar3 = (undefined4 *)(uint)(*(short *)(puVar1 + 0x40) == 0);
        }
      }
      else if ((puVar1[0x14] == 0) || (puVar1[0x46] == 0)) {
        iVar4 = 0x2726;
        puVar3 = puVar7;
      }
      else {
        iVar5 = 0;
        uVar8 = 0;
        _Src = LocalAlloc(0,uBytes);
        if (_Src == (HLOCAL)0x0) goto LAB_c0524dbc;
        puVar3 = param_4;
        pvVar6 = _Src;
        iVar4 = CeSafeCopyMemory(_Src,param_4,param_5);
        if (iVar4 == 0) goto LAB_c05253a8;
        if ((undefined4 *)puVar1[0x48] == (undefined4 *)0x0) {
          uVar2 = 0;
        }
        else {
          uVar2 = *(undefined4 *)puVar1[0x48];
        }
        iVar4 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x58))
                          (puVar1[0x46],puVar1,uVar2,puVar1[0x5a],param_2,param_3,_Src,&param_5,
                           puVar3,iVar5,pvVar6,puVar7,uVar8);
        uBytes = param_5;
        *param_6 = param_5;
        memcpy(param_4,_Src,param_5);
        param_4 = puVar3;
        puVar3 = puVar7;
      }
      goto LAB_c052538c;
    }
    _Src = LocalAlloc(0,uBytes);
    if (_Src == (HLOCAL)0x0) {
LAB_c0524dbc:
      iVar4 = 0x2747;
      goto LAB_c05253d8;
    }
    puVar3 = param_4;
    pvVar6 = _Src;
    iVar4 = CeSafeCopyMemory(_Src,param_4,param_5);
    if (iVar4 != 0) {
      if ((param_3 == 0x10) || (param_3 == 0x12)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
        iVar4 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x58))
                          (0,0,0,0,0xff,param_3,_Src,&param_5,puVar3,iVar5,pvVar6);
        *param_6 = param_5;
        memcpy(param_4,_Src,param_5);
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
        uBytes = param_5;
      }
      else {
        if (param_3 != 0x13) goto LAB_c0524f14;
        if (puVar1[0x5a] == 0) {
          iVar4 = 0x2749;
        }
        else {
          iVar4 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x58))
                            (0,0,0,puVar1[0x5a],0xff,0x13,_Src,&param_5);
        }
        uBytes = param_5;
        *param_6 = param_5;
        memcpy(param_4,_Src,param_5);
      }
LAB_c05252e4:
      iVar5 = 0;
      puVar3 = puVar7;
      goto LAB_c052538c;
    }
  }
LAB_c05253a8:
  iVar4 = 0x271e;
LAB_c05253d8:
  if (_Src != (HLOCAL)0x0) {
    LocalFree(_Src);
  }
  FUN_c051eabc(puVar1);
  return iVar4;
}



/* c0525440 FUN_c0525440 */

/* Boundary evidence: original MIPS .pdata c0525440..c052544b. Semantic name remains unreviewed. */

undefined4 FUN_c0525440(void)

{
  return 1;
}



/* c052544c FUN_c052544c */

/* Boundary evidence: original MIPS .pdata c052544c..c0525457. Semantic name remains unreviewed. */

undefined4 FUN_c052544c(void)

{
  return 1;
}



/* c0525458 FUN_c0525458 */

/* Boundary evidence: original MIPS .pdata c0525458..c0525463. Semantic name remains unreviewed. */

undefined4 FUN_c0525458(void)

{
  return 1;
}



/* c0525464 FUN_c0525464 */

/* Boundary evidence: original MIPS .pdata c0525464..c052546f. Semantic name remains unreviewed. */

undefined4 FUN_c0525464(void)

{
  return 1;
}



/* c0525470 FUN_c0525470 */

/* Boundary evidence: original MIPS .pdata c0525470..c052547b. Semantic name remains unreviewed. */

undefined4 FUN_c0525470(void)

{
  return 1;
}



/* c052547c FUN_c052547c */

/* Boundary evidence: original MIPS .pdata c052547c..c0525487. Semantic name remains unreviewed. */

undefined4 FUN_c052547c(void)

{
  return 1;
}



/* c0525488 FUN_c0525488 */

/* Boundary evidence: original MIPS .pdata c0525488..c0525513. Semantic name remains unreviewed. */

undefined4 FUN_c0525488(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_28 [6];
  
  iVar2 = *(int *)(param_1 + 0x168);
  uVar1 = 0;
  if (iVar2 != 0) {
    local_40 = 0x400;
    local_3c = 0;
    local_38 = 0x200;
    local_34 = 0x300;
    local_48[0] = param_3;
    local_30 = param_2;
    memset(local_28,0,0x14);
    local_28[0] = iVar2;
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x4c))
                      (local_28,&local_40,local_48,4);
  }
  return uVar1;
}



/* c0525514 FUN_c0525514 */

/* Boundary evidence: original MIPS .pdata c0525514..c0525537. Semantic name remains unreviewed. */

void FUN_c0525514(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  EventModify(*(undefined4 *)(param_1 + 8),3);
  return;
}



/* c0525538 FUN_c0525538 */

/* Boundary evidence: original MIPS .pdata c0525538..c05256b3. Semantic name remains unreviewed. */

undefined4 FUN_c0525538(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *hMem;
  HANDLE pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  code *local_2c;
  undefined4 *local_28;
  
  if (*(int *)(param_1 + 0x120) == 0) {
    uVar3 = 0x2726;
  }
  else {
    hMem = LocalAlloc(0,0xc);
    if (hMem == (undefined4 *)0x0) {
      uVar3 = 0x2747;
    }
    else {
      pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
      hMem[2] = pvVar1;
      local_50 = hMem;
      if (pvVar1 == (HANDLE)0x0) {
        uVar3 = 0x2747;
      }
      else {
        *hMem = param_3;
        hMem[1] = 0;
        local_48 = 0x401;
        local_44 = 0;
        local_40 = 0x200;
        local_3c = 0x200;
        local_38 = param_2;
        memset(&local_30,0,0x14);
        local_30 = **(undefined4 **)(param_1 + 0x120);
        local_2c = FUN_c0525514;
        local_28 = hMem;
        iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x4c))
                          (&local_30,&local_48,hMem,4);
        if (iVar2 == 0xff) {
          WaitForSingleObject((HANDLE)hMem[2],0xffffffff);
          iVar2 = hMem[1];
        }
        uVar3 = FUN_c051f74c(iVar2);
      }
    }
    if (hMem != (undefined4 *)0x0) {
      if ((HANDLE)local_50[2] != (HANDLE)0x0) {
        CloseHandle((HANDLE)local_50[2]);
      }
      LocalFree(hMem);
    }
  }
  return uVar3;
}



/* c05256b4 FUN_c05256b4 */

/* Boundary evidence: original MIPS .pdata c05256b4..c052604b. Semantic name remains unreviewed. */

int FUN_c05256b4(uint param_1,int param_2,uint param_3,int param_4,SIZE_T param_5)

{
  undefined4 *puVar1;
  int iVar2;
  HANDLE pvVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  size_t _Size;
  uint *_Src;
  uint *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  code *local_3c;
  uint *local_38;
  
  local_60 = (uint *)0x0;
  iVar7 = 0;
  _Src = (uint *)0x0;
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x2736;
  }
  if (((10000000 < param_5) || (param_5 < 2)) || (param_4 == 0)) goto LAB_c0525fe4;
  _Src = LocalAlloc(0,param_5);
  if (_Src == (uint *)0x0) {
    iVar7 = 0x2747;
    goto LAB_c0525fec;
  }
  iVar2 = CeSafeCopyMemory(_Src,param_4,param_5);
  if (iVar2 == 0) goto LAB_c0525778;
  if (puVar1[3] == 0x400) {
    iVar7 = 0x2742;
    goto LAB_c0525fec;
  }
  uVar6 = *_Src;
  if (param_2 == 0) {
    if (puVar1[7] == 1) {
      if (param_3 == 100) {
        if (puVar1[3] == 0x40) {
LAB_c0525ad8:
          iVar7 = 0x2748;
          goto LAB_c0525fec;
        }
      }
      else if (param_3 != 0x65) goto LAB_c0525830;
    }
    if (((puVar1[0x48] == 0) && (param_3 != 100)) && (param_3 != 0x65)) goto LAB_c0525fe4;
    if (param_3 < 9) {
      _Size = 8;
      if (param_3 == 8) {
        if ((0xff < uVar6) || ((int)uVar6 < 0)) goto LAB_c0525fe4;
        local_48 = 8;
        goto LAB_c0525d04;
      }
      if (param_3 == 2) {
        if (param_5 < 4) goto LAB_c0525778;
        local_48 = 3;
        goto LAB_c0525d04;
      }
      if (param_3 == 3) {
        if ((uVar6 < 0x100) && (-1 < (int)uVar6)) {
          local_48 = 2;
          goto LAB_c0525d04;
        }
      }
      else {
        if (param_3 == 4) goto LAB_c0525830;
        if ((param_3 < 5) || (6 < param_3)) goto LAB_c0525ca8;
        if (7 < param_5) {
          param_5 = 0x14;
          if (param_3 == 5) {
            local_48 = 6;
          }
          else {
            local_48 = 7;
          }
          goto LAB_c0525d08;
        }
      }
LAB_c0525fe4:
      iVar7 = 0x2726;
      goto LAB_c0525fec;
    }
    if (param_3 == 9) {
      if (param_5 < 4) {
LAB_c0525778:
        iVar7 = 0x271e;
        goto LAB_c0525fec;
      }
      local_48 = 0xc;
LAB_c0525d04:
      param_5 = 0xc;
      _Size = 4;
    }
    else {
      if (param_3 == 100) {
        if ((6 < uVar6) || ((int)uVar6 < 0)) goto LAB_c0525fe4;
        if (puVar1[0x48] == 0) {
          puVar1[0x6c] = uVar6;
          goto LAB_c0525fec;
        }
        local_48 = 100;
        goto LAB_c0525d04;
      }
      if (param_3 == 0x65) {
        local_48 = 0x65;
        goto LAB_c0525d04;
      }
LAB_c0525ca8:
      if (0x400 < param_5) goto LAB_c0525fe4;
      _Size = 0;
    }
LAB_c0525d08:
    local_60 = LocalAlloc(0,param_5);
    if (local_60 == (uint *)0x0) {
      iVar7 = 0x2747;
      goto LAB_c0525fec;
    }
    if (param_3 < 10) {
      if (7 < param_3) goto LAB_c0525da0;
      if (param_3 < 2) {
LAB_c0525f40:
        memcpy(local_60,_Src,param_5);
        _Src = local_60;
        goto LAB_c0525f5c;
      }
      if (param_3 < 4) goto LAB_c0525da0;
      if ((param_3 < 5) || (6 < param_3)) goto LAB_c0525f40;
      memcpy(local_60,_Src,_Size);
      *(uint *)(_Size + (int)local_60) = 0;
      puVar8 = (uint *)(_Size + (int)local_60);
    }
    else {
      if ((param_3 < 100) || (0x65 < param_3)) goto LAB_c0525f40;
LAB_c0525da0:
      *local_60 = uVar6;
      puVar8 = local_60;
    }
    pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    puVar8[2] = (uint)pvVar3;
    if (pvVar3 == (HANDLE)0x0) {
      iVar7 = 0x2747;
    }
    else {
      puVar8[1] = 0;
      local_58 = 0x401;
      local_54 = 0;
      local_50 = 0x200;
      local_4c = 0x200;
      memset(&local_40,0,0x14);
      if ((undefined4 *)puVar1[0x48] == (undefined4 *)0x0) {
        local_40 = 0;
      }
      else {
        local_40 = *(undefined4 *)puVar1[0x48];
      }
      local_3c = FUN_c0525514;
      local_38 = puVar8;
      LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
      uVar4 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x4c))(&local_40,&local_58,local_60,_Size);
      if (uVar4 == 0xff) {
        WaitForSingleObject((HANDLE)puVar8[2],0xffffffff);
        uVar4 = puVar8[1];
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
      if (uVar4 != 0) {
        iVar7 = FUN_c051f74c(uVar4);
      }
      CloseHandle((HANDLE)puVar8[2]);
    }
    if (iVar7 != 0) goto LAB_c0525fec;
    if (param_3 == 2) {
      puVar1[0x6d] = uVar6;
      goto LAB_c0525fec;
    }
    if (param_3 == 3) {
      *(char *)(puVar1 + 0x6e) = (char)uVar6;
      goto LAB_c0525fec;
    }
    if (param_3 < 5) goto LAB_c0525fec;
    if (param_3 < 7) {
      puVar1[0x6d] = *_Src;
      goto LAB_c0525fec;
    }
    if (param_3 != 9) {
      if (param_3 == 100) {
        puVar1[0x6c] = uVar6;
      }
      goto LAB_c0525fec;
    }
    if (uVar6 == 0) {
      uVar6 = 0xfffffbff;
      goto LAB_c0525938;
    }
    uVar6 = puVar1[5] | 0x400;
LAB_c05258d0:
    puVar1[5] = uVar6;
  }
  else {
    if (param_2 == 6) {
      if ((param_3 == 1) && (puVar1[7] == 1)) {
        if (uVar6 == 0) {
          puVar1[5] = puVar1[5] & 0xfffffff7;
        }
        else {
          puVar1[5] = puVar1[5] | 8;
        }
        uVar5 = 1;
        goto LAB_c0525870;
      }
    }
    else {
      if (param_2 != 0xff) {
        if (param_2 != 0xffff) {
LAB_c0525f5c:
          if ((puVar1[0x14] != 0) && (puVar1[0x46] != 0)) {
            if ((undefined4 *)puVar1[0x48] == (undefined4 *)0x0) {
              uVar5 = 0;
            }
            else {
              uVar5 = *(undefined4 *)puVar1[0x48];
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
            iVar7 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x68))
                              (puVar1[0x46],puVar1,uVar5,puVar1[0x5a],param_2,param_3,_Src,param_5);
            EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
            goto LAB_c0525fec;
          }
          goto LAB_c0525fe4;
        }
        if (0x1001 < param_3) {
          if (param_3 == 0x1002) {
            if (0x100000 < uVar6) {
              uVar6 = 0x100000;
            }
            puVar1[0x3d] = uVar6;
            goto LAB_c0525fec;
          }
          if (param_3 == 0x8000) {
            if ((3 < param_5) && (uVar6 == 0x4d2)) {
              puVar1[5] = puVar1[5] | 0x10;
              iVar7 = 0;
              goto LAB_c0525fec;
            }
          }
          else if (param_3 == 0x8001) {
            if (puVar1[7] != 1) {
              if (uVar6 == 0) {
                uVar6 = 0xfffffeff;
                goto LAB_c0525938;
              }
              uVar6 = puVar1[5] | 0x100;
              local_60 = (uint *)0x0;
              goto LAB_c05258d0;
            }
          }
          else if (((param_3 == 0xff7f) || (param_3 == 0xffffff7f)) && (puVar1[7] == 1)) {
            *(ushort *)(puVar1 + 0x40) = (ushort)(uVar6 == 0);
            goto LAB_c0525fec;
          }
          goto LAB_c0525830;
        }
        if (param_3 == 0x1001) {
          local_60 = (uint *)0x0;
          if (uVar6 == 0) {
            iVar7 = 0x2726;
          }
          else {
            puVar1[0x3c] = uVar6;
          }
          goto LAB_c0525fec;
        }
        if (param_3 != 4) {
          if (param_3 == 8) {
            if (puVar1[7] == 1) {
              if (uVar6 == 0) {
                puVar1[5] = puVar1[5] & 0xfffffffd;
              }
              else {
                puVar1[5] = puVar1[5] | 2;
              }
              uVar5 = 2;
LAB_c0525870:
              FUN_c0525488((int)puVar1,uVar5,uVar6);
              goto LAB_c0525fec;
            }
          }
          else if (param_3 == 0x20) {
            if (puVar1[7] != 1) {
              local_60 = (uint *)0x0;
              if (uVar6 == 0) {
                uVar6 = 0xfffffffb;
                goto LAB_c0525938;
              }
              uVar6 = puVar1[5] | 4;
              goto LAB_c05258d0;
            }
          }
          else if (param_3 == 0x80) {
            if (puVar1[7] == 1) {
              local_60 = (uint *)0x0;
              if (param_5 < 4) {
                iVar7 = 0x271e;
              }
              else {
                puVar1[0x40] = uVar6;
              }
              goto LAB_c0525fec;
            }
          }
          else if ((param_3 == 0x100) && (puVar1[7] == 1)) {
            if (uVar6 == 0) {
              puVar1[5] = puVar1[5] & 0xffffff7f;
            }
            else {
              puVar1[5] = puVar1[5] | 0x80;
            }
            if (puVar1[0x5a] == 0) goto LAB_c0525fec;
            uVar5 = 3;
            goto LAB_c0525870;
          }
          goto LAB_c0525830;
        }
        if (uVar6 == 0) {
          uVar6 = 0xfffffffe;
          local_60 = (uint *)0x0;
LAB_c0525938:
          puVar1[5] = puVar1[5] & uVar6;
          goto LAB_c0525fec;
        }
        uVar6 = puVar1[5] | 1;
        goto LAB_c05258d0;
      }
      if (param_3 == 0x11) {
        iVar7 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x68))
                          (puVar1[0x46],0,0,0,0xff,0x11,_Src,param_5);
        goto LAB_c0525fec;
      }
      if ((0x13 < param_3) && ((param_3 < 0x17 || (param_3 == 0x20)))) {
        if (puVar1[0x5a] == 0) {
          iVar7 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x68))
                            (puVar1[0x46],0,0,0,0xff,param_3,_Src,param_5);
          goto LAB_c0525fec;
        }
        goto LAB_c0525ad8;
      }
    }
LAB_c0525830:
    iVar7 = 0x273a;
  }
LAB_c0525fec:
  FUN_c051eabc(puVar1);
  if (_Src != (uint *)0x0) {
    LocalFree(_Src);
  }
  if ((local_60 != (uint *)0x0) && (local_60 != _Src)) {
    LocalFree(local_60);
  }
  return iVar7;
}



/* c052604c FUN_c052604c */

/* Boundary evidence: original MIPS .pdata c052604c..c05262cb. Semantic name remains unreviewed. */

void FUN_c052604c(int param_1)

{
  bool bVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  HANDLE hTargetProcessHandle;
  BOOL BVar2;
  int iVar3;
  PRTL_CRITICAL_SECTION_DEBUG hMem;
  LPCRITICAL_SECTION p_Var4;
  LPCRITICAL_SECTION p_Var5;
  HANDLE local_38;
  int local_34;
  LPCRITICAL_SECTION local_30;
  
  local_30 = (LPCRITICAL_SECTION)&DAT_c052e4a0;
  local_34 = param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4a0);
  lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c052e4a0;
  iVar3 = DAT_c052e428;
  p_Var4 = local_30;
  p_Var5 = local_30;
  do {
    if (iVar3 == 0) {
      LeaveCriticalSection(lpCriticalSection);
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x104));
    if (*(int *)(iVar3 + 0x18) == 2) {
      if (param_1 != 0) {
        if (param_1 != 1) goto LAB_c05260e4;
        goto LAB_c0526100;
      }
LAB_c0526140:
      if (*(int *)(iVar3 + 0x80) != 0) {
        EventModify(*(int *)(iVar3 + 0x80),1);
      }
      p_Var4 = (LPCRITICAL_SECTION)(iVar3 + 0xb8);
      p_Var5 = (LPCRITICAL_SECTION)0x200;
LAB_c052615c:
      hMem = p_Var4->DebugInfo;
      while (hMem != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        bVar1 = hMem->CriticalSection != (_RTL_CRITICAL_SECTION *)(hMem->ProcessLocksList).Flink;
        hMem->CriticalSection->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
        local_38 = hMem->CriticalSection->LockSemaphore;
        if (local_38 == (HANDLE)0x0) {
LAB_c05261ec:
          if (bVar1) {
            CeFreeAsynchronousBuffer(hMem->CriticalSection,(hMem->ProcessLocksList).Flink,0x14,0xc);
          }
        }
        else if (bVar1) {
          hTargetProcessHandle = (HANDLE)__GetUserKData(0xc);
          BVar2 = DuplicateHandle(*(HANDLE *)(iVar3 + 0x24),hMem->CriticalSection->LockSemaphore,
                                  hTargetProcessHandle,&local_38,0,0,2);
          if (BVar2 == 0) {
            local_38 = (HANDLE)0x0;
          }
          goto LAB_c05261ec;
        }
        if ((local_38 != (HANDLE)0x0) && (EventModify(local_38,3), bVar1)) {
          CloseHandle(local_38);
        }
        p_Var4->DebugInfo = *(PRTL_CRITICAL_SECTION_DEBUG *)hMem;
        LocalFree(hMem);
        param_1 = local_34;
        hMem = p_Var4->DebugInfo;
      }
      FUN_c0528468(iVar3,0,0,(uint)p_Var5);
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x104));
    }
    else {
LAB_c05260e4:
      if ((*(int *)(iVar3 + 0x18) == 0x17) && ((param_1 == 2 || (param_1 == 3)))) {
LAB_c0526100:
        if (param_1 == 0) goto LAB_c0526140;
        if (param_1 == 1) {
LAB_c0526120:
          if (*(int *)(iVar3 + 0x7c) != 0) {
            EventModify(*(int *)(iVar3 + 0x7c),1);
          }
          p_Var4 = (LPCRITICAL_SECTION)(iVar3 + 0xbc);
          p_Var5 = (LPCRITICAL_SECTION)0x100;
        }
        else {
          if (param_1 == 2) goto LAB_c0526140;
          if (param_1 == 3) goto LAB_c0526120;
        }
        goto LAB_c052615c;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x104));
    }
    iVar3 = *(int *)(iVar3 + 0x3c);
    lpCriticalSection = local_30;
  } while( true );
}



/* c05262cc FUN_c05262cc */

/* Boundary evidence: original MIPS .pdata c05262cc..c05264cf. Semantic name remains unreviewed. */

void FUN_c05262cc(void)

{
  HMODULE pHVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  code *pcVar7;
  uint uVar8;
  uint local_40;
  HANDLE local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  pcVar6 = (code *)0x0;
  pcVar7 = (code *)0x0;
  pHVar1 = LoadLibraryW(L"TcpStk.dll");
  if (pHVar1 != (HMODULE)0x0) {
    pcVar6 = (code *)GetProcAddressW(pHVar1,L"CEGetNotifyStatus");
  }
  iVar5 = 0;
  if (0 < DAT_c052e460) {
    piVar3 = &DAT_c052e470;
    iVar2 = DAT_c052e460;
    do {
      uVar8 = 0;
      if (**(int **)(*piVar3 + 4) != 0) {
        iVar4 = 0;
        do {
          if ((*(int *)(*(int *)(*piVar3 + 4) + iVar4 + 8) == 0x17) &&
             (pHVar1 = LoadLibraryW(L"TcpIp6.dll"), pHVar1 != (HMODULE)0x0)) {
            pcVar7 = (code *)GetProcAddressW(pHVar1,L"CEGetNotifyStatus");
            goto LAB_c05263e4;
          }
          uVar8 = uVar8 + 1;
          iVar4 = iVar4 + 0xc;
          iVar2 = DAT_c052e460;
        } while (uVar8 < **(uint **)(*piVar3 + 4));
      }
      iVar5 = iVar5 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar5 < iVar2);
  }
LAB_c05263e4:
  local_38 = DAT_c052e504;
  local_34 = DAT_c052e4fc;
  local_30 = DAT_c052e500;
  local_2c = DAT_c052e4f8;
  uVar8 = local_40;
  do {
    WaitForMultipleObjects(4,&local_38,0,0xffffffff);
    while (((pcVar6 != (code *)0x0 && (local_40 = (*pcVar6)(), local_40 != 0)) ||
           ((pcVar7 != (code *)0x0 && (uVar8 = (*pcVar7)(), uVar8 != 0))))) {
      if ((local_40 & 1) != 0) {
        FUN_c052604c(0);
      }
      if ((local_40 & 2) != 0) {
        FUN_c052604c(1);
      }
      if ((uVar8 & 1) != 0) {
        FUN_c052604c(2);
        FUN_c051b6d8();
      }
      if ((uVar8 & 2) != 0) {
        FUN_c052604c(3);
      }
    }
  } while( true );
}



/* c05264d0 FUN_c05264d0 */

/* Boundary evidence: original MIPS .pdata c05264d0..c0526657. Semantic name remains unreviewed. */

undefined4 FUN_c05264d0(undefined4 param_1,int *param_2,uint param_3,uint *param_4)

{
  uint _Size;
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  iVar2 = 0;
  for (piVar1 = (int *)DAT_c052e37c; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    iVar2 = iVar2 + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  _Size = iVar2 * 0x18 + 4;
  *param_4 = _Size;
  if (param_3 < _Size) {
    uVar4 = 0x271e;
  }
  else {
    memset(param_2,0,_Size);
    *param_2 = iVar2;
    piVar5 = param_2 + 1;
    piVar3 = piVar5 + iVar2 * 2;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
    for (piVar1 = (int *)DAT_c052e37c; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      piVar5[1] = 0x10;
      *piVar5 = (int)piVar3;
      *(undefined2 *)piVar3 = 2;
      piVar3[1] = piVar1[4];
      piVar5 = piVar5 + 2;
      piVar3 = piVar3 + 4;
    }
    uVar4 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e39c);
  }
  return uVar4;
}



/* c0526658 FUN_c0526658 */

/* Boundary evidence: original MIPS .pdata c0526658..c0526663. Semantic name remains unreviewed. */

undefined4 FUN_c0526658(void)

{
  return 1;
}



/* c0526664 FUN_c0526664 */

/* Boundary evidence: original MIPS .pdata c0526664..c052681b. Semantic name remains unreviewed. */

undefined4 FUN_c0526664(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  HANDLE pvVar1;
  HLOCAL hMem;
  int iVar2;
  int *piVar3;
  
  if (param_2 == 0) {
    if ((*(uint *)(param_1 + 0x10) & 1) != 0) {
      return 0x2733;
    }
    if (param_4 == 0) {
      if (*(int *)(param_1 + 0x80) == 0) {
        pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
        *(HANDLE *)(param_1 + 0x80) = pvVar1;
      }
      pvVar1 = *(HANDLE *)(param_1 + 0x80);
    }
    else {
      if (*(int *)(param_1 + 0x7c) == 0) {
        pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
        *(HANDLE *)(param_1 + 0x7c) = pvVar1;
      }
      pvVar1 = *(HANDLE *)(param_1 + 0x7c);
    }
    if (pvVar1 != (HANDLE)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
      WaitForSingleObject(pvVar1,0xffffffff);
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
      return 0;
    }
  }
  else {
    hMem = LocalAlloc(0x40,0x10);
    if (hMem != (HLOCAL)0x0) {
      if (param_2 < 0x80000000) {
        iVar2 = CeAllocAsynchronousBuffer((int)hMem + 4,param_2,0x14,0xc);
        if (iVar2 != 0) {
          LocalFree(hMem);
          return 0x2747;
        }
      }
      else {
        *(uint *)((int)hMem + 4) = param_2;
      }
      *(uint *)((int)hMem + 8) = param_2;
      *(undefined4 *)((int)hMem + 0xc) = param_3;
      piVar3 = (int *)(param_1 + 0xbc);
      if (param_4 == 0) {
        piVar3 = (int *)(param_1 + 0xb8);
      }
      iVar2 = *piVar3;
      while (iVar2 != 0) {
        piVar3 = (int *)*piVar3;
        iVar2 = *piVar3;
      }
      *piVar3 = (int)hMem;
      return 0x3e5;
    }
  }
  return 0x2747;
}



/* c052681c FUN_c052681c */

/* Boundary evidence: original MIPS .pdata c052681c..c0526a13. Semantic name remains unreviewed. */

int FUN_c052681c(int param_1,int param_2,uint param_3,undefined4 param_4,undefined2 *param_5,
                undefined4 param_6,undefined4 *param_7)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 *local_a4;
  undefined4 local_a0;
  undefined1 auStack_90 [24];
  undefined4 uStack_78;
  undefined1 auStack_74 [16];
  undefined4 local_64;
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined4 local_50;
  undefined1 auStack_4c [4];
  undefined4 local_48;
  undefined4 local_44 [7];
  uint local_28;
  
  local_28 = DAT_c052e2d8;
  local_50 = 0x200;
  puVar1 = auStack_4c + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x100U >> (3 - uVar2) * 8;
  puVar1 = auStack_58 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x301U >> (3 - uVar2) * 8;
  puVar1 = auStack_54 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  auStack_4c = (undefined1  [4])0x100;
  auStack_58 = (undefined1  [4])0x301;
  auStack_54 = (undefined1  [4])0x0;
  if (*(int *)(param_1 + 0x18) == 2) {
    local_44[0] = *(undefined4 *)(param_2 + 4);
    local_a4 = &local_ac;
    local_48 = 0x105;
    local_b0 = 4;
    local_a0 = 4;
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0x17) {
      FUN_c052c8e4(local_28);
      return 0x273f;
    }
    if (param_3 < 0x1c) {
      FUN_c052c8e4(local_28);
      return 0x271e;
    }
    memcpy(local_44,(void *)(param_2 + 2),0x1a);
    local_a4 = &uStack_78;
    local_48 = 3;
    local_b0 = 0x1c;
    local_a0 = 0x1c;
  }
  local_a8 = 0;
  iVar3 = (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x48))
                    (auStack_90,auStack_58,&local_a8,&local_b0,local_44);
  if (iVar3 < 0) goto LAB_c05269e4;
  *param_5 = (short)*(undefined4 *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x18) == 2) {
    memset(param_5 + 4,0,8);
    *(undefined4 *)(param_5 + 2) = local_ac;
    *(undefined1 *)((int)param_5 + 3) = 0;
LAB_c05269d4:
    *(undefined1 *)(param_5 + 1) = 0;
  }
  else if (*(int *)(param_1 + 0x18) == 0x17) {
    memcpy(param_5 + 4,auStack_74,0x10);
    *(undefined4 *)(param_5 + 2) = 0;
    *(undefined1 *)((int)param_5 + 3) = 0;
    *(undefined4 *)(param_5 + 0xc) = local_64;
    goto LAB_c05269d4;
  }
  *param_7 = *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10);
LAB_c05269e4:
  FUN_c052c8e4(local_28);
  return iVar3;
}



/* c0526a14 FUN_c0526a14 */

/* Boundary evidence: original MIPS .pdata c0526a14..c052744f. Semantic name remains unreviewed. */

int FUN_c0526a14(uint param_1,uint param_2,uint *param_3,uint param_4,uint *param_5,uint param_6,
                uint *param_7,uint param_8,undefined4 param_9)

{
  undefined4 *puVar1;
  SIZE_T uBytes;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  SIZE_T SVar6;
  int iVar7;
  uint *_Dst;
  undefined2 *_Src;
  uint local_5c;
  uint local_58;
  uint *local_54;
  uint *local_50;
  undefined2 *local_4c;
  uint *local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  uint *local_38;
  int local_34;
  int local_30 [2];
  
  iVar7 = 0;
  local_54 = (uint *)0x0;
  local_38 = (uint *)0x0;
  _Dst = (uint *)0x0;
  local_50 = (uint *)0x0;
  _Src = (undefined2 *)0x0;
  local_4c = (undefined2 *)0x0;
  local_40 = 0;
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x2736;
  }
  local_3c = puVar1;
  if (param_7 == (uint *)0x0) {
    puVar3 = (uint *)0x0;
    local_48 = (uint *)0x0;
    local_58 = 0;
  }
  else {
    local_48 = &local_58;
    iVar7 = FUN_c0527d50(param_7,&local_58);
    if (iVar7 != 0) goto LAB_c05273c0;
    puVar3 = &local_58;
  }
  if (64000 < param_4) {
    iVar7 = 0x2726;
    goto LAB_c05273c0;
  }
  if (puVar1[3] == 0x400) {
    iVar7 = 0x2742;
    goto LAB_c05273c0;
  }
  if (param_2 < 0x8004667f) {
    if (param_2 == 0x8004667e) {
      if (*param_3 != 0) {
        puVar1[4] = puVar1[4] | 1;
        goto LAB_c05273c0;
      }
      if (puVar1[0x1e] == 0) {
        puVar1[4] = puVar1[4] & 0xfffffffe;
        goto LAB_c05273c0;
      }
LAB_c0526d0c:
      iVar7 = 0x2726;
      goto LAB_c05273c0;
    }
    if (param_2 < 0x40047308) {
      if (((param_2 != 0x40047307) && (param_2 != 0x28000002)) && (param_2 != 0x28000004)) {
        if (param_2 == 0x28000017) {
          puVar1[0x23] = puVar1[0x23] | 0x200;
          iVar7 = 0;
LAB_c0526c64:
          iVar7 = FUN_c0526664((int)puVar1,param_8,param_9,iVar7);
          goto LAB_c05273c0;
        }
        if (param_2 == 0x4004667f) {
          if (param_7 != (uint *)0x0) {
            *param_7 = 4;
          }
          if ((3 < param_6) && (param_5 != (uint *)0x0)) {
            if ((puVar1[7] == 2) || (puVar1[7] == 3)) {
              if (puVar1[0x57] != 0) {
                *param_5 = (uint)*(ushort *)(puVar1[0x57] + 6);
                goto LAB_c05273c0;
              }
            }
            else if (puVar1[3] == 0x40) {
              if (puVar1[0x32] == 0) {
                *param_5 = puVar1[0x30];
              }
              else {
                *param_5 = puVar1[0x32];
              }
              goto LAB_c05273c0;
            }
            *param_5 = 0;
            goto LAB_c05273c0;
          }
          goto LAB_c0526c48;
        }
        goto LAB_c0527090;
      }
    }
    else if (param_2 != 0x48000003) {
      if (param_2 == 0x48000005) {
        if (puVar1[7] != 2) goto LAB_c0526d0c;
        if (*(int *)(*(int *)(puVar1[0x14] + 8) + 0x74) == 0) {
          local_5c = param_6;
          iVar7 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x74))(puVar1[0x46],param_5,&local_5c);
          if (((iVar7 == 0) || ((iVar7 == 0x271e && (param_6 < local_5c)))) &&
             (param_7 != (uint *)0x0)) {
            *param_7 = local_5c;
          }
          goto LAB_c05273c0;
        }
      }
      else {
        if (param_2 == 0x48000016) {
          iVar7 = FUN_c05264d0(puVar1,(int *)param_5,param_6,puVar3);
          if (param_7 != (uint *)0x0) {
            *param_7 = local_58;
          }
          goto LAB_c05273c0;
        }
        if (param_2 != 0x48000018) goto LAB_c0527090;
      }
    }
  }
  else if (param_2 < 0xc8000009) {
    if ((param_2 < 0xc8000006) && (param_2 != 0x88000001)) {
      if ((param_2 == 0x88000009) || (param_2 + 0x77fffff7 < 2)) {
        if (puVar1[7] != 2) goto LAB_c0527370;
        if (param_4 < 4) {
LAB_c0526c48:
          iVar7 = 0x271e;
          goto LAB_c05273c0;
        }
        _Dst = LocalAlloc(0,4);
        local_50 = _Dst;
        if (_Dst == (uint *)0x0) goto LAB_c0526f0c;
        *_Dst = *param_3;
        param_3 = _Dst;
      }
      else {
        if ((param_2 == 0x8800000b) || (param_2 + 0x77fffff5 < 2)) goto LAB_c0527370;
        if (param_2 == 0x88000015) {
          puVar1[0x23] = puVar1[0x23] | 0x100;
          if ((param_3 == (uint *)0x0) || (param_4 < *(uint *)(puVar1[0x14] + 0xc)))
          goto LAB_c0526d0c;
          local_5c = *(uint *)(puVar1[0x14] + 0x10);
          if (param_4 <= local_5c) {
            local_5c = param_4;
          }
          _Dst = LocalAlloc(0,param_4);
          local_50 = _Dst;
          if (_Dst != (uint *)0x0) {
            memcpy(_Dst,param_3,param_4);
            iVar7 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x50))(_Dst,local_5c,local_30);
            if (iVar7 != 0) goto LAB_c05273c0;
            iVar7 = 1;
            goto LAB_c0526c64;
          }
          goto LAB_c0526f0c;
        }
      }
LAB_c0527090:
      if ((uint *)puVar1[0x48] == (uint *)0x0) {
        local_44 = 0;
      }
      else {
        local_44 = *(uint *)puVar1[0x48];
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
      local_40 = 1;
      if (*(int *)(*(int *)(puVar1[0x14] + 8) + 0x88) == 0) {
        iVar7 = 0x2726;
      }
      else {
        _Dst = LocalAlloc(0,param_4);
        local_50 = _Dst;
        if (param_5 == (uint *)0x0) {
          _Src = (undefined2 *)0x0;
        }
        else {
          _Src = LocalAlloc(0x40,param_6);
        }
        local_4c = _Src;
        if ((_Dst == (uint *)0x0) || ((_Src == (undefined2 *)0x0 && (param_5 != (uint *)0x0)))) {
          iVar7 = 0x2747;
        }
        else {
          memcpy(_Dst,param_3,param_4);
          iVar7 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x88))
                            (puVar1[0x46],puVar1,local_44,puVar1[0x5a],param_2,_Dst,param_4,_Src,
                             param_6,local_48,param_8,param_9,&local_5c);
          uVar5 = local_58;
          if (param_5 != (uint *)0x0) {
            memcpy(param_5,_Src,local_58);
          }
          if (param_7 != (uint *)0x0) {
            *param_7 = uVar5;
          }
        }
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x41));
      goto LAB_c05273c0;
    }
  }
  else if (param_2 != 0xc800000d) {
    if (param_2 == 0xc8000014) {
      if ((param_3 != (uint *)0x0) && (iVar7 = puVar1[0x14], *(uint *)(iVar7 + 0xc) <= param_4)) {
        if ((param_5 == (uint *)0x0) || (uVar5 = *(uint *)(iVar7 + 0x10), param_6 < uVar5)) {
          if (param_7 != (uint *)0x0) {
            *param_7 = *(uint *)(iVar7 + 0x10);
          }
          goto LAB_c0526c48;
        }
        local_5c = uVar5;
        if (param_4 <= uVar5) {
          local_5c = param_4;
        }
        _Dst = LocalAlloc(0,param_4);
        local_50 = _Dst;
        _Src = LocalAlloc(0x40,param_6);
        local_4c = _Src;
        if ((_Dst == (uint *)0x0) || (_Src == (undefined2 *)0x0)) goto LAB_c0526f0c;
        memcpy(_Dst,param_3,param_4);
        iVar7 = (**(code **)(*(int *)(puVar1[0x14] + 8) + 0x50))(_Dst,local_5c,local_30);
        if (iVar7 != 0) goto LAB_c05273c0;
        if (local_30[0] != 1) {
          iVar7 = FUN_c052681c((int)puVar1,(int)_Dst,param_4,local_5c,_Src,param_6,local_48);
          uVar5 = local_58;
          memcpy(param_5,_Src,local_58);
          if (param_7 != (uint *)0x0) {
            *param_7 = uVar5;
          }
          goto LAB_c05273c0;
        }
      }
      goto LAB_c0526d0c;
    }
    if (param_2 == 0xc8000019) {
      local_44 = *param_3;
      iVar4 = -0x3fffff6b;
      iVar2 = iVar4;
      SVar6 = 0xffffffff;
      if ((int)((ulonglong)local_44 * 8 >> 0x20) == 0) {
        iVar2 = 0;
        SVar6 = (SIZE_T)((ulonglong)local_44 * 8);
      }
      if (iVar2 == 0) {
        uBytes = 0xffffffff;
        if (3 < SVar6 + 4) {
          iVar4 = 0;
          uBytes = SVar6 + 4;
        }
        if ((iVar4 == 0) &&
           (local_54 = LocalAlloc(0x40,uBytes), local_38 = local_54, local_54 != (uint *)0x0)) {
          *local_54 = local_44;
          for (local_34 = 0; local_34 < (int)local_44; local_34 = local_34 + 1) {
            local_5c = param_3[local_34 * 2 + 2];
            uVar5 = param_3[local_34 * 2 + 1];
            local_54[local_34 * 2 + 1] = uVar5;
            if (uVar5 == 0) {
              iVar7 = 0x271e;
              break;
            }
            local_54[local_34 * 2 + 2] = local_5c;
          }
          param_3 = local_54;
          if (iVar7 != 0) goto LAB_c05273c0;
          goto LAB_c0527090;
        }
      }
LAB_c0526f0c:
      iVar7 = 0x2747;
      goto LAB_c05273c0;
    }
    goto LAB_c0527090;
  }
LAB_c0527370:
  iVar7 = 0x273a;
LAB_c05273c0:
  puVar3 = local_54;
  FUN_c051eabc(puVar1);
  if (puVar3 != (uint *)0x0) {
    LocalFree(puVar3);
  }
  if (_Dst != (uint *)0x0) {
    LocalFree(_Dst);
  }
  if (_Src != (undefined2 *)0x0) {
    LocalFree(_Src);
  }
  return iVar7;
}



/* c0527450 FUN_c0527450 */

/* Boundary evidence: original MIPS .pdata c0527450..c052745b. Semantic name remains unreviewed. */

undefined4 FUN_c0527450(void)

{
  return 1;
}



/* c052745c FUN_c052745c */

/* Boundary evidence: original MIPS .pdata c052745c..c0527513. Semantic name remains unreviewed. */

void * FUN_c052745c(uint *param_1)

{
  void *pvVar1;
  int iVar2;
  uint local_40 [2];
  uint local_38 [10];
  
  *param_1 = 0;
  memset(local_38,0,0x24);
  local_38[2] = 0x100;
  local_38[3] = 0x100;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[4] = 0;
  local_40[0] = 0xc0;
  pvVar1 = FUN_c051de9c(0xc0);
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_c052ace8(6,0,local_38,0x24,(int)pvVar1,local_40);
    if (iVar2 == 0) {
      *param_1 = local_40[0] >> 3;
    }
    else {
      CTEFreeMem(pvVar1);
      pvVar1 = (void *)0x0;
    }
  }
  return pvVar1;
}



/* c0527514 FUN_c0527514 */

/* Boundary evidence: original MIPS .pdata c0527514..c05277e3. Semantic name remains unreviewed. */

int FUN_c0527514(undefined4 *param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint local_c8;
  undefined4 *local_c4;
  uint local_c0 [2];
  uint local_b8;
  uint local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  int local_94;
  uint local_90;
  uint local_8c;
  undefined1 auStack_88 [84];
  uint local_34;
  
  iVar10 = 0;
  local_c4 = param_1;
  puVar1 = FUN_c052745c(local_c0);
  iVar8 = 0xf;
  iVar9 = 0;
  puVar7 = puVar1;
  uVar12 = local_c0[0];
  if (0 < (int)local_c0[0]) {
    do {
      if (iVar8 == 0) break;
      if (*puVar7 == 0x301) {
        memset(&local_b8,0,0x24);
        uVar5 = *puVar7;
        uVar11 = puVar7[1];
        local_b0 = 0x100;
        local_ac = 0x100;
        local_a8 = 1;
        local_c8 = 4;
        local_b8 = uVar5;
        local_b4 = uVar11;
        local_90 = uVar5;
        local_8c = uVar11;
        iVar2 = FUN_c052ace8(6,0,&local_b8,0x24,(int)&local_94,&local_c8);
        if (iVar2 != 0) break;
        if (local_94 == 0x303) {
          memset(&local_b8,0,0x24);
          local_b0 = 0x200;
          local_ac = 0x100;
          local_a8 = 1;
          local_c8 = 0x5c;
          local_b8 = uVar5;
          local_b4 = uVar11;
          iVar2 = FUN_c052ace8(6,0,&local_b8,0x24,(int)auStack_88,&local_c8);
          if (iVar2 != 0) break;
          if (local_34 != 0) {
            local_c8 = local_34 * 0x18;
            piVar3 = FUN_c051de9c(local_c8);
            if (piVar3 == (int *)0x0) break;
            memset(&local_b8,0,0x24);
            local_b8 = local_90;
            local_b0 = 0x200;
            local_a8 = 0x102;
            local_b4 = local_8c;
            local_ac = 0x100;
            iVar2 = FUN_c052ace8(6,0,&local_b8,0x24,(int)piVar3,&local_c8);
            if (iVar2 != 0) {
              CTEFreeMem(piVar3);
              break;
            }
            uVar5 = local_c8 / 0x18;
            if ((int)local_34 < (int)(local_c8 / 0x18)) {
              uVar5 = local_34;
            }
            iVar2 = 0;
            piVar6 = piVar3;
            if (0 < (int)uVar5) {
              do {
                uVar12 = local_c0[0];
                if (iVar8 == 0) break;
                iVar4 = *piVar6;
                if ((iVar4 != 0) && (iVar4 != 0x100007f)) {
                  *param_2 = iVar4;
                  *local_c4 = param_2;
                  local_c4 = local_c4 + 1;
                  param_2 = param_2 + 1;
                  iVar10 = iVar10 + 1;
                  iVar8 = iVar8 + -1;
                }
                iVar2 = iVar2 + 1;
                piVar6 = piVar6 + 6;
              } while (iVar2 < (int)uVar5);
            }
            CTEFreeMem(piVar3);
          }
        }
      }
      iVar9 = iVar9 + 1;
      puVar7 = puVar7 + 2;
    } while (iVar9 < (int)uVar12);
  }
  if (puVar1 != (uint *)0x0) {
    CTEFreeMem(puVar1);
  }
  return iVar10;
}



/* c05277e4 FUN_c05277e4 */

/* Boundary evidence: original MIPS .pdata c05277e4..c0527b23. Semantic name remains unreviewed. */

int FUN_c05277e4(int param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *hMem;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined1 auStack_138 [8];
  int *local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined1 auStack_110 [8];
  int *local_108;
  uint local_f8;
  undefined4 local_e8;
  undefined1 local_a8;
  undefined1 auStack_a7 [15];
  int local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 auStack_84 [36];
  undefined1 auStack_60 [16];
  int local_50;
  int local_4c;
  uint local_44;
  uint local_2c;
  
  local_2c = DAT_c052e2d8;
  hMem = (int *)0x0;
  if (param_1 == 0) {
    piVar7 = (int *)0x158;
    hMem = LocalAlloc(0x40,0x158);
    if (hMem == (int *)0x0) {
      iVar1 = 0x2747;
LAB_c05278a4:
      if (hMem != (int *)0x0) {
        LocalFree(hMem);
      }
      FUN_c052c8e4(local_2c);
      return iVar1;
    }
    *hMem = -1;
    piVar5 = param_2;
    piVar6 = hMem;
  }
  else {
    local_98 = *(int *)(param_1 + 0x14);
    local_94 = *(undefined4 *)(param_1 + 0x18);
    local_90 = *(undefined4 *)(param_1 + 0x1c);
    local_8c = *(undefined4 *)(param_1 + 0x20);
    local_88 = *(undefined4 *)(param_1 + 0x24);
    memset(auStack_84,0,0x10);
    piVar5 = &local_98;
    piVar6 = param_2;
    piVar7 = param_2;
  }
  iVar4 = 0;
  do {
    if (param_1 == 0) {
      local_12c = 0x14;
      local_128 = 0x120004;
      local_130 = piVar7;
      local_108 = piVar6;
    }
    else {
      local_12c = 0x24;
      local_128 = 0x120008;
      local_130 = (int *)0x6c;
      local_108 = piVar5;
    }
    local_e8 = 0;
    iVar1 = (*DAT_c052e4f4)(auStack_110,auStack_138);
    if (iVar1 != 0) goto LAB_c05278a4;
    if (param_1 == 0) {
      if (iVar4 == 0) {
        if (local_f8 != 0x14) goto LAB_c05278a4;
      }
      else {
        if ((local_f8 < 0xd8) || ((uint)hMem[10] < 0xd8)) goto LAB_c05278a4;
        if (hMem[0xc] == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = hMem[0xb];
        }
        if (hMem[0xd] == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = hMem[0xb];
        }
        if (local_f8 != hMem[10] + iVar2 + iVar3) goto LAB_c05278a4;
        iVar1 = FUN_c05277e4((int)hMem,param_2,param_3,param_4);
      }
      if (*hMem == -1) goto LAB_c05278a4;
    }
    else {
      local_a8 = 0;
      memset(auStack_a7,0,0xf);
      if (iVar4 == 0) {
        if (local_f8 != 0x24) goto LAB_c05278a4;
      }
      else {
        if (local_f8 != 0x6c) goto LAB_c05278a4;
        if ((((local_50 == 0) && (2 < local_44)) && ((local_4c == 0xe || (local_4c == 5)))) &&
           (*param_4 < 0xf)) {
          *param_4 = *param_4 + 1;
          memcpy((void *)*param_3,auStack_60,0x10);
          *(int *)*param_2 = *param_3;
          *param_2 = *param_2 + 4;
          iVar3 = *param_3;
          *param_3 = iVar3 + 0x10;
          memset((void *)(iVar3 + 0x10),0,4);
          *param_3 = *param_3 + 4;
        }
      }
      iVar3 = memcmp(piVar5 + 5,&local_a8,0x10);
      if (iVar3 == 0) goto LAB_c05278a4;
    }
    iVar4 = iVar4 + 1;
  } while( true );
}



/* c0527b24 FUN_c0527b24 */

/* Boundary evidence: original MIPS .pdata c0527b24..c0527b7b. Semantic name remains unreviewed. */

int FUN_c0527b24(int param_1,int param_2)

{
  int iVar1;
  int local_res0;
  int local_res4 [3];
  int local_10 [2];
  
  if (DAT_c052e4f4 != 0) {
    local_10[0] = 0;
    local_res0 = param_1;
    local_res4[0] = param_2;
    iVar1 = FUN_c05277e4(0,&local_res0,local_res4,local_10);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (local_10[0] != 0) {
      return 0;
    }
  }
  return 0x2afc;
}



/* c0527b7c FUN_c0527b7c */

/* Boundary evidence: original MIPS .pdata c0527b7c..c0527bfb. Semantic name remains unreviewed. */

void * FUN_c0527b7c(size_t param_1,uint param_2)

{
  void *_Dst;
  
  _Dst = (void *)CTEAllocMem(param_1);
  if (((_Dst != (void *)0x0) && (param_2 != 0x14)) && ((param_2 < 0x1f || (0x20 < param_2)))) {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}



/* c0527bfc FUN_c0527bfc */

/* Boundary evidence: original MIPS .pdata c0527bfc..c0527c17. Semantic name remains unreviewed. */

void FUN_c0527bfc(void)

{
  CTEFreeMem();
  return;
}



/* c0527c18 FUN_c0527c18 */

/* Boundary evidence: original MIPS .pdata c0527c18..c0527cdb. Semantic name remains unreviewed. */

undefined4 FUN_c0527c18(undefined1 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_2 < 1) {
    if (param_2 < 0) {
      uVar1 = 0x271e;
    }
  }
  else {
    puVar2 = param_1 + param_2;
    iVar3 = DAT_c052e464;
    do {
      if (param_3 != 0) {
        *param_1 = 0;
        iVar3 = DAT_c052e464;
      }
      param_1 = param_1 + iVar3;
    } while (param_1 < puVar2);
    if (param_3 != 0) {
      puVar2[-1] = 0;
    }
  }
  return uVar1;
}



/* c0527cdc FUN_c0527cdc */

/* Boundary evidence: original MIPS .pdata c0527cdc..c0527ce7. Semantic name remains unreviewed. */

undefined4 FUN_c0527cdc(void)

{
  return 1;
}



/* c0527ce8 FUN_c0527ce8 */

/* Boundary evidence: original MIPS .pdata c0527ce8..c0527d43. Semantic name remains unreviewed. */

void FUN_c0527ce8(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = param_2;
  }
  return;
}



/* c0527d44 FUN_c0527d44 */

/* Boundary evidence: original MIPS .pdata c0527d44..c0527d4f. Semantic name remains unreviewed. */

undefined4 FUN_c0527d44(void)

{
  return 1;
}



/* c0527d50 FUN_c0527d50 */

/* Boundary evidence: original MIPS .pdata c0527d50..c0527daf. Semantic name remains unreviewed. */

void FUN_c0527d50(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  return;
}



/* c0527db0 FUN_c0527db0 */

/* Boundary evidence: original MIPS .pdata c0527db0..c0527dbb. Semantic name remains unreviewed. */

undefined4 FUN_c0527db0(void)

{
  return 1;
}



/* c0527dbc FUN_c0527dbc */

/* Boundary evidence: original MIPS .pdata c0527dbc..c0527df3. Semantic name remains unreviewed. */

void FUN_c0527dbc(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x170);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_c051de9c(0x18);
  }
  else {
    *(undefined4 *)(param_1 + 0x170) = *puVar1;
    *puVar1 = 0;
  }
  return;
}



/* c0527df4 FUN_c0527df4 */

/* Boundary evidence: original MIPS .pdata c0527df4..c0527e4f. Semantic name remains unreviewed. */

void FUN_c0527df4(int param_1,undefined4 *param_2)

{
  if ((param_2 < *(undefined4 **)(param_1 + 0x184)) ||
     (*(undefined4 **)(param_1 + 0x184) + *(int *)(param_1 + 400) * 6 <= param_2)) {
    CTEFreeMem(param_2);
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x170);
    *(undefined4 **)(param_1 + 0x170) = param_2;
  }
  return;
}



/* c0527e50 FUN_c0527e50 */

/* Boundary evidence: original MIPS .pdata c0527e50..c0527e83. Semantic name remains unreviewed. */

undefined4 FUN_c0527e50(void)

{
  _SYSTEM_INFO _Stack_30;
  
  GetSystemInfo(&_Stack_30);
  DAT_c052e464 = _Stack_30.dwPageSize;
  return 1;
}



/* c0527e84 FUN_c0527e84 */

/* Boundary evidence: original MIPS .pdata c0527e84..c0527eb3. Semantic name remains unreviewed. */

void FUN_c0527e84(void)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_c0527b7c(DAT_c052e464,0x1f);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  return;
}



/* c0527eb4 FUN_c0527eb4 */

/* Boundary evidence: original MIPS .pdata c0527eb4..c0527ecf. Semantic name remains unreviewed. */

void FUN_c0527eb4(void)

{
  FUN_c0527bfc();
  return;
}



/* c0527ed0 FUN_c0527ed0 */

/* Boundary evidence: original MIPS .pdata c0527ed0..c052800b. Semantic name remains unreviewed. */

undefined4 FUN_c0527ed0(int param_1,int *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar3 = *(undefined4 **)(param_1 + 0x170);
  uVar5 = 0;
  uVar4 = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = FUN_c051de9c(0x18);
  }
  else {
    *(undefined4 *)(param_1 + 0x170) = *puVar3;
    *puVar3 = 0;
  }
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 0x2747;
  }
  else {
    iVar1 = CTEAllocMem(param_3);
    if (iVar1 == 0) {
      uVar4 = 0x2747;
LAB_c0527fe8:
      FUN_c0527df4(param_1,puVar3);
      if (iVar1 != 0) {
        CTEFreeMem(iVar1);
      }
    }
    else {
      if (param_3 != 0) {
        do {
          if (param_2 == (int *)0x0) {
            uVar4 = 0x2726;
            goto LAB_c0527fe8;
          }
          iVar2 = CeSafeCopyMemory(uVar5 + iVar1,param_2[1],param_2[2]);
          if (iVar2 == 0) {
            uVar4 = 0x271e;
            goto LAB_c0527fe8;
          }
          uVar5 = param_2[2] + uVar5;
          param_2 = (int *)*param_2;
        } while (uVar5 < param_3);
      }
      *puVar3 = 0;
      puVar3[1] = iVar1;
      puVar3[2] = param_3;
      *param_4 = puVar3;
    }
  }
  return uVar4;
}



/* c052800c FUN_c052800c */

/* Boundary evidence: original MIPS .pdata c052800c..c05282d7. Semantic name remains unreviewed. */

int FUN_c052800c(int param_1,int *param_2,int param_3,undefined4 *param_4,int *param_5,int param_6,
                int param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *local_38;
  undefined4 *local_34;
  int local_30;
  undefined4 *local_2c;
  
  iVar4 = 0;
  local_30 = 0;
  uVar7 = 0x80000008;
  local_34 = param_4;
  local_2c = param_4;
  do {
    iVar1 = local_30;
    if (param_3 == 0) {
LAB_c05281c8:
      if (iVar4 == 0) {
        *param_5 = iVar1;
      }
      else {
        if (param_6 == 0) {
          uVar7 = 0x80000004;
        }
        puVar2 = (undefined4 *)*param_4;
        while (puVar2 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*puVar2;
          if ((param_7 != 0) && (puVar2[2] != 0)) {
            CeFreeAsynchronousBuffer(puVar2[1],0xffffffff,puVar2[2],uVar7);
          }
          FUN_c0527df4(param_1,puVar2);
          puVar2 = puVar5;
        }
        *param_4 = 0;
        *param_5 = 0;
      }
      return iVar4;
    }
    if (param_2 == (int *)0x0) {
      iVar4 = 0x271e;
      goto LAB_c05281c8;
    }
    iVar6 = *param_2;
    if ((param_7 == 0) || (iVar6 == 0)) {
      local_38 = (undefined1 *)param_2[1];
    }
    else {
      uVar3 = uVar7;
      if (param_6 == 0) {
        uVar3 = 0x80000004;
      }
      iVar4 = CeAllocAsynchronousBuffer(&local_38,param_2[1],iVar6,uVar3);
      if (iVar4 != 0) {
        iVar4 = 0x271e;
        goto LAB_c05281c8;
      }
    }
    iVar4 = FUN_c0527c18(local_38,iVar6,param_6);
    if (iVar4 != 0) goto LAB_c05281c8;
    puVar2 = *(undefined4 **)(param_1 + 0x170);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = FUN_c051de9c(0x18);
    }
    else {
      *(undefined4 *)(param_1 + 0x170) = *puVar2;
      *puVar2 = 0;
    }
    if (puVar2 == (undefined4 *)0x0) {
      iVar4 = 0x2747;
      goto LAB_c05281c8;
    }
    *local_34 = puVar2;
    *puVar2 = 0;
    puVar2[1] = local_38;
    puVar2[2] = iVar6;
    local_30 = iVar6 + iVar1;
    param_2 = param_2 + 2;
    param_3 = param_3 + -1;
    local_34 = puVar2;
  } while( true );
}



/* c05282d8 FUN_c05282d8 */

/* Boundary evidence: original MIPS .pdata c05282d8..c05282e3. Semantic name remains unreviewed. */

undefined4 FUN_c05282d8(void)

{
  return 1;
}



/* c05282e4 FUN_c05282e4 */

/* Boundary evidence: original MIPS .pdata c05282e4..c0528467. Semantic name remains unreviewed. */

undefined4 FUN_c05282e4(int param_1,int param_2,DWORD param_3)

{
  undefined4 uVar1;
  DWORD DVar2;
  HANDLE hHandle;
  
  if (param_2 == 1) {
    if (*(int *)(param_1 + 0x70) == 0) {
      EventModify(*(undefined4 *)(param_1 + 100),2);
    }
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
LAB_c052839c:
    hHandle = *(HANDLE *)(param_1 + 100);
LAB_c05283a0:
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
    DVar2 = WaitForSingleObject(hHandle,param_3);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
    if (DVar2 == 0x102) {
      return 0x274c;
    }
    if (param_2 == 1) {
      *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
    }
    else {
      if (param_2 == 2) {
        uVar1 = *(undefined4 *)(param_1 + 0xec);
        *(undefined4 *)(param_1 + 0xec) = 0;
        *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
        return uVar1;
      }
      if (param_2 != 8) {
        if (param_2 == 0x10) {
          uVar1 = *(undefined4 *)(param_1 + 0x164);
          *(undefined4 *)(param_1 + 0x164) = 0;
          return uVar1;
        }
        goto LAB_c0528354;
      }
    }
    uVar1 = *(undefined4 *)(param_1 + 0xe4);
    *(undefined4 *)(param_1 + 0xe4) = 0;
  }
  else {
    if (param_2 == 2) {
      *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
LAB_c0528370:
      hHandle = *(HANDLE *)(param_1 + 0x68);
      goto LAB_c05283a0;
    }
    if (param_2 == 8) goto LAB_c052839c;
    if (param_2 == 0x10) goto LAB_c0528370;
    if (param_2 == 0x20) {
      hHandle = *(HANDLE *)(param_1 + 0x74);
      goto LAB_c05283a0;
    }
LAB_c0528354:
    uVar1 = 0;
  }
  return uVar1;
}



/* c0528468 FUN_c0528468 */

/* Boundary evidence: original MIPS .pdata c0528468..c052870f. Semantic name remains unreviewed. */

void FUN_c0528468(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  
  if (param_3 != 0) {
    *(int *)(param_1 + 0x60) = param_3;
  }
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
      if ((param_2 & 0x110) == 0) {
        if ((param_2 & 8) == 0) goto LAB_c0528570;
        EventModify(*(undefined4 *)(param_1 + 100),3);
        goto LAB_c052856c;
      }
    }
    else {
      if (*(int *)(param_1 + 0x150) != 0) {
        if (*(int *)(param_1 + 0x6c) != 0) {
          EventModify(*(undefined4 *)(param_1 + 0x68),3);
        }
        *(int *)(param_1 + 0xec) = param_3;
        goto LAB_c0528570;
      }
      if (*(int *)(param_1 + 0xc) != 0x200) goto LAB_c0528570;
    }
    EventModify(*(undefined4 *)(param_1 + 0x68),3);
  }
  else {
    if (*(int *)(param_1 + 0x70) != 0) {
      EventModify(*(undefined4 *)(param_1 + 100),3);
    }
    if (param_3 == 0x70077007) goto LAB_c0528570;
LAB_c052856c:
    *(int *)(param_1 + 0xe4) = param_3;
  }
LAB_c0528570:
  if (param_2 == 0x20) {
    EventModify(*(undefined4 *)(param_1 + 0x74),3);
  }
  if (((*(uint *)(param_1 + 0x84) != 0) && (param_4 != 0)) &&
     ((*(uint *)(param_1 + 0x84) & param_4) != 0)) {
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | param_4;
    if (param_4 == 1) {
      *(int *)(param_1 + 0x90) = param_3;
    }
    else if (param_4 == 2) {
      *(int *)(param_1 + 0x94) = param_3;
    }
    else if (param_4 == 8) {
      *(int *)(param_1 + 0x9c) = param_3;
    }
    else if (param_4 == 0x10) {
      *(int *)(param_1 + 0xa0) = param_3;
    }
    else if (param_4 == 0x20) {
      *(int *)(param_1 + 0xa4) = param_3;
    }
    else if (param_4 == 0x100) {
      *(int *)(param_1 + 0xb0) = param_3;
    }
    else if (param_4 == 0x200) {
      *(int *)(param_1 + 0xb4) = param_3;
    }
    if ((*(int *)(param_1 + 0x78) != 0) && ((*(uint *)(param_1 + 0x8c) & param_4) != 0)) {
      EventModify(*(int *)(param_1 + 0x78),3);
    }
    *(uint *)(param_1 + 0x8c) = ~param_4 & *(uint *)(param_1 + 0x8c);
  }
  if (param_2 != 0) {
    for (puVar1 = *(undefined4 **)(param_1 + 0x138); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[3]) {
      if ((puVar1[1] == 0x12) && (param_2 == 2)) {
        if ((*(int *)(param_1 + 0x150) == 0) &&
           (*(uint *)(param_1 + 0xe8) < *(uint *)(param_1 + 0xf0))) {
LAB_c05286c4:
          puVar1[2] = 1;
LAB_c05286c8:
          EventModify(*puVar1,3);
        }
      }
      else if ((puVar1[1] & param_2) != 0) {
        if (param_3 != 0x70077007) goto LAB_c05286c4;
        goto LAB_c05286c8;
      }
    }
  }
  return;
}



/* c0528710 FUN_c0528710 */

/* Boundary evidence: original MIPS .pdata c0528710..c052878b. Semantic name remains unreviewed. */

void FUN_c0528710(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  EventModify(*(undefined4 *)(param_1 + 100),3);
  EventModify(*(undefined4 *)(param_1 + 0x68),3);
  *(undefined4 *)(param_1 + 0xec) = param_2;
  *(undefined4 *)(param_1 + 0xe4) = param_2;
  *(undefined4 *)(param_1 + 0x164) = param_2;
  for (puVar1 = *(undefined4 **)(param_1 + 0x138); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[3]) {
    puVar1[2] = 1;
    EventModify(*puVar1,3);
  }
  return;
}



/* c052878c FUN_c052878c */

/* Boundary evidence: original MIPS .pdata c052878c..c05287f7. Semantic name remains unreviewed. */

undefined4 FUN_c052878c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_c0527b7c(0x10,0x15);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x2747;
  }
  else {
    *puVar1 = param_3;
    puVar1[1] = param_2;
    puVar1[3] = *(undefined4 *)(param_1 + 0x138);
    *(undefined4 **)(param_1 + 0x138) = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* c05287f8 FUN_c05287f8 */

/* Boundary evidence: original MIPS .pdata c05287f8..c0528873. Semantic name remains unreviewed. */

bool FUN_c05287f8(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x138);
  while( true ) {
    piVar1 = (int *)*piVar3;
    if (piVar1 == (int *)0x0) {
      return false;
    }
    if ((param_3 == *piVar1) && (param_2 == piVar1[1])) break;
    piVar3 = piVar1 + 3;
  }
  *piVar3 = piVar1[3];
  iVar2 = piVar1[2];
  FUN_c0527bfc();
  return iVar2 == 0;
}



/* c0528874 FUN_c0528874 */

/* Boundary evidence: original MIPS .pdata c0528874..c05288cf. Semantic name remains unreviewed. */

undefined4 FUN_c0528874(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x2736;
  }
  else {
    FUN_c0528468((int)puVar1,1,0x70077007,0);
    FUN_c051eabc(puVar1);
    uVar2 = 0;
  }
  return uVar2;
}



/* c05288d0 FUN_c05288d0 */

/* Boundary evidence: original MIPS .pdata c05288d0..c05289fb. Semantic name remains unreviewed. */

undefined4 FUN_c05288d0(uint param_1,void *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar3 = 0x2736;
  }
  else {
    iVar2 = puVar1[3];
    if (iVar2 == 0x400) {
      uVar3 = 0x2742;
    }
    else if ((iVar2 == 0x40) || (iVar2 == 0x80)) {
      if (param_3 < (uint)puVar1[0x4d]) {
        uVar3 = 0x271e;
      }
      else {
        memcpy(param_2,(void *)puVar1[0x4c],puVar1[0x4d]);
        *param_4 = puVar1[0x4d];
      }
    }
    else {
      uVar3 = 0x2749;
    }
    FUN_c051eabc(puVar1);
  }
  return uVar3;
}



/* c05289fc FUN_c05289fc */

/* Boundary evidence: original MIPS .pdata c05289fc..c0528a07. Semantic name remains unreviewed. */

undefined4 FUN_c05289fc(void)

{
  return 1;
}



/* c0528a08 FUN_c0528a08 */

/* Boundary evidence: original MIPS .pdata c0528a08..c0528b1f. Semantic name remains unreviewed. */

undefined4 FUN_c0528a08(uint param_1,void *param_2,undefined4 param_3,uint *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x2736;
  }
  else {
    if (puVar1[3] == 0x400) {
      uVar2 = 0x2742;
    }
    else if (puVar1[3] == 1) {
      uVar2 = 0x2726;
    }
    else if (*param_4 < (uint)puVar1[0x4b]) {
      uVar2 = 0x271e;
    }
    else {
      memcpy(param_2,(void *)puVar1[0x4a],puVar1[0x4b]);
      *param_4 = puVar1[0x4b];
    }
    FUN_c051eabc(puVar1);
  }
  return uVar2;
}



/* c0528b20 FUN_c0528b20 */

/* Boundary evidence: original MIPS .pdata c0528b20..c0528b2b. Semantic name remains unreviewed. */

undefined4 FUN_c0528b20(void)

{
  return 1;
}



/* c0528b2c FUN_c0528b2c */

/* Boundary evidence: original MIPS .pdata c0528b2c..c0528d0b. Semantic name remains unreviewed. */

int FUN_c0528b2c(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (2 < param_2) {
    return 0x2726;
  }
  puVar1 = (undefined4 *)FUN_c051eaf8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x2736;
  }
  iVar2 = puVar1[3];
  if (iVar2 == 0x400) {
    iVar2 = 0x2742;
  }
  else if (((puVar1[7] == 1) && (iVar2 != 0x40)) && (iVar2 != 0x20)) {
    iVar2 = 0x2749;
  }
  else {
    iVar2 = FUN_c051e150((int)puVar1,*(uint *)(&DAT_c052e2bc + param_2 * 4));
    if (iVar2 == 0) {
      if (param_2 == 0) {
        puVar1[5] = puVar1[5] | 0x20;
        if (((puVar1[7] == 1) && (puVar1[3] == 0x40)) &&
           ((puVar1[0x30] != 0 || (puVar1[0x31] != 0)))) {
          puVar1[4] = puVar1[4] | 0x400;
          FUN_c05226f0((int)puVar1);
        }
      }
      else {
        if (param_2 != 1) {
          if (param_2 != 2) goto LAB_c0528ce0;
          puVar1[5] = puVar1[5] | 0x20;
          if (((puVar1[7] == 1) && (puVar1[3] == 0x40)) &&
             ((puVar1[0x30] != 0 || (puVar1[0x31] != 0)))) {
            puVar1[4] = puVar1[4] | 0x400;
            FUN_c05226f0((int)puVar1);
          }
        }
        puVar1[5] = puVar1[5] | 0x40;
        if (((puVar1[7] == 1) && (puVar1[3] == 0x40)) && ((puVar1[4] & 0x120) == 0)) {
          FUN_c0522b84(puVar1,1);
        }
      }
    }
  }
LAB_c0528ce0:
  FUN_c051eabc(puVar1);
  return iVar2;
}



/* c0528d0c FUN_c0528d0c */

/* WARNING: Removing unreachable block (ram,0xc0529050) */
/* Boundary evidence: original MIPS .pdata c0528d0c..c05290bb. Semantic name remains unreviewed. */

undefined4
FUN_c0528d0c(wchar_t *param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,uint *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *hMem;
  undefined4 *puVar6;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  uVar4 = 0;
  if ((*param_6 & 1) == 0) {
    if ((*param_6 & 6) == 0) {
      sVar3 = wcslen(param_1);
      puVar5 = LocalAlloc(0x40,(sVar3 + 0x11a) * 2);
      if (puVar5 == (undefined4 *)0x0) {
        uVar4 = 0x2747;
        goto LAB_c0529068;
      }
      wcsncpy((wchar_t *)(puVar5 + 9),param_2,0x103);
      *(undefined2 *)((int)puVar5 + 0x22a) = 0;
      puVar5[1] = *param_5;
      puVar5[2] = param_5[1];
      puVar5[3] = param_5[2];
      puVar5[4] = param_5[3];
      puVar5[5] = param_3;
      puVar5[6] = 1;
      puVar5[7] = param_4;
      puVar5[0x8b] = (sVar3 + 1) * 2;
      puVar5[8] = puVar5 + 0x8c;
      wcscpy((wchar_t *)(puVar5 + 0x8c),param_1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4e0);
      puVar1 = puVar5;
      if (DAT_c052e408 != (undefined4 *)0x0) {
        *DAT_c052e404 = puVar5;
        puVar1 = DAT_c052e408;
      }
      DAT_c052e408 = puVar1;
      DAT_c052e40c = DAT_c052e40c + 1;
      DAT_c052e404 = puVar5;
    }
    else {
      local_40 = *param_5;
      local_3c = param_5[1];
      local_38 = param_5[2];
      local_34 = param_5[3];
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4e0);
      puVar5 = DAT_c052e408;
      if (DAT_c052e408 != (undefined4 *)0x0) {
        do {
          iVar2 = memcmp(puVar5 + 1,&local_40,0x10);
          if (iVar2 == 0) break;
          puVar5 = (undefined4 *)*puVar5;
        } while (puVar5 != (undefined4 *)0x0);
        if (puVar5 != (undefined4 *)0x0) {
          puVar5[6] = *param_6 & 2;
        }
      }
    }
  }
  else {
    local_40 = *param_5;
    local_3c = param_5[1];
    local_38 = param_5[2];
    local_34 = param_5[3];
    uVar4 = 0x2726;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4e0);
    puVar5 = &DAT_c052e408;
    puVar1 = (undefined4 *)0x0;
    for (hMem = DAT_c052e408; hMem != (undefined4 *)0x0; hMem = (undefined4 *)*hMem) {
      iVar2 = memcmp(hMem + 1,&local_40,0x10);
      puVar6 = hMem;
      if (iVar2 == 0) {
        uVar4 = 0;
        DAT_c052e40c = DAT_c052e40c + -1;
        *puVar5 = *hMem;
        if (hMem == DAT_c052e404) {
          DAT_c052e404 = puVar1;
        }
        LocalFree(hMem);
        hMem = puVar5;
        puVar6 = puVar1;
      }
      puVar5 = hMem;
      puVar1 = puVar6;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4e0);
LAB_c0529068:
  FUN_c052c8e4(local_30);
  return uVar4;
}



/* c05290bc FUN_c05290bc */

/* Boundary evidence: original MIPS .pdata c05290bc..c05290c7. Semantic name remains unreviewed. */

undefined4 FUN_c05290bc(void)

{
  return 1;
}



/* c05290c8 FUN_c05290c8 */

/* Boundary evidence: original MIPS .pdata c05290c8..c05290d3. Semantic name remains unreviewed. */

undefined4 FUN_c05290c8(void)

{
  return 1;
}



/* c05290d4 FUN_c05290d4 */

/* Boundary evidence: original MIPS .pdata c05290d4..c05290df. Semantic name remains unreviewed. */

undefined4 FUN_c05290d4(void)

{
  return 1;
}



/* c05290e0 FUN_c05290e0 */

/* Boundary evidence: original MIPS .pdata c05290e0..c05290eb. Semantic name remains unreviewed. */

undefined4 FUN_c05290e0(void)

{
  return 1;
}



/* c05290ec FUN_c05290ec */

/* Boundary evidence: original MIPS .pdata c05290ec..c0529413. Semantic name remains unreviewed. */

int FUN_c05290ec(int *param_1,wchar_t *param_2,uint param_3,undefined4 param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  wchar_t *_Dst;
  int iVar4;
  int iVar5;
  wchar_t *local_68;
  int local_64;
  int local_60;
  uint local_50;
  int local_4c;
  wchar_t *local_48;
  
  iVar2 = 0;
  if (param_1 == (int *)0x0) {
    iVar4 = 0x271e;
  }
  else {
    local_60 = 0;
    local_50 = 0;
    local_64 = 0;
    iVar4 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4e0);
    piVar1 = DAT_c052e408;
    for (iVar5 = 0; piVar3 = piVar1, _Dst = param_2, local_68 = local_48, iVar5 < 2;
        iVar5 = iVar5 + 1) {
      for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
        if (iVar5 == 0) {
          local_50 = local_50 + 0x20;
          local_60 = piVar3[0x8b] + local_60 + 0x20;
          if (local_50 <= param_3) {
            iVar2 = iVar2 + 1;
            memcpy(_Dst,piVar3 + 1,0x20);
            goto LAB_c05292b0;
          }
          local_64 = 0x271e;
        }
        else {
          local_50 = piVar3[0x8b] + local_50;
          if (param_3 < local_50) {
            local_64 = 0x271e;
            break;
          }
          *(wchar_t **)(_Dst + 0xe) = local_68;
          wcscpy(local_68,(wchar_t *)piVar3[8]);
          local_68 = (wchar_t *)(piVar3[0x8b] + (int)local_68);
LAB_c05292b0:
          _Dst = _Dst + 0x10;
          piVar1 = DAT_c052e408;
        }
      }
      if (local_64 != 0) break;
      local_48 = _Dst;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4e0);
    local_4c = local_60;
  }
  if ((iVar4 != 0) || (local_64 != 0)) {
    *param_5 = 0x271e;
    iVar2 = -1;
    if (iVar4 == 0) {
      *param_1 = local_4c;
    }
  }
  return iVar2;
}



/* c0529414 FUN_c0529414 */

/* Boundary evidence: original MIPS .pdata c0529414..c052941f. Semantic name remains unreviewed. */

undefined4 FUN_c0529414(void)

{
  return 1;
}



/* c0529420 FUN_c0529420 */

/* Boundary evidence: original MIPS .pdata c0529420..c052942b. Semantic name remains unreviewed. */

undefined4 FUN_c0529420(void)

{
  return 1;
}



/* c052942c FUN_c052942c */

/* Boundary evidence: original MIPS .pdata c052942c..c05294e3. Semantic name remains unreviewed. */

undefined4 FUN_c052942c(undefined4 *param_1,int param_2)

{
  *param_1 = 0;
  memcpy(param_1 + 1,(void *)(param_2 + 4),0x20);
  wcscpy((wchar_t *)(param_1 + 9),(wchar_t *)(param_2 + 0x24));
  wcsncpy((wchar_t *)(param_1 + 0x8b),(wchar_t *)(param_2 + 0x230),0x1f);
  *(undefined2 *)((int)param_1 + 0x26a) = 0;
  param_1[8] = param_1 + 0x8b;
  return 0;
}



/* c05294e4 FUN_c05294e4 */

/* Boundary evidence: original MIPS .pdata c05294e4..c05294ef. Semantic name remains unreviewed. */

undefined4 FUN_c05294e4(void)

{
  return 1;
}



/* c05294f0 FUN_c05294f0 */

/* Boundary evidence: original MIPS .pdata c05294f0..c052977b. Semantic name remains unreviewed. */

int FUN_c05294f0(int param_1,undefined4 *param_2,undefined4 param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined4 *_Buf1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_64;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  _Buf1 = (undefined4 *)0x0;
  iVar6 = 0;
  iVar5 = 0;
  iVar3 = 0;
  if (param_1 == 0) {
    iVar3 = 0x271e;
  }
  else {
    local_64 = *(int *)(param_1 + 0x14);
    puVar2 = *(undefined4 **)(param_1 + 0x18);
    _Buf1 = (undefined4 *)0x0;
    if (puVar2 != (undefined4 *)0x0) {
      if (((int)puVar2 < 0x10000) || ((undefined4 *)0x7fffffff < puVar2 + 4)) {
        iVar3 = 0x271e;
      }
      else {
        local_40 = *puVar2;
        local_3c = puVar2[1];
        local_38 = puVar2[2];
        local_34 = puVar2[3];
      }
      _Buf1 = &local_40;
    }
  }
  if (iVar3 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4e0);
    for (piVar4 = (int *)DAT_c052e408; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      if (piVar4[6] != 0) {
        if (_Buf1 == (undefined4 *)0x0) {
          if ((local_64 == 0) || (local_64 == piVar4[5])) {
            if (iVar6 + 0x26c <= *param_4) goto LAB_c0529754;
LAB_c052969c:
            iVar6 = iVar6 + 0x26c;
            iVar3 = 0x271e;
          }
        }
        else {
          iVar1 = memcmp(_Buf1,piVar4 + 1,0x10);
          if (iVar1 == 0) {
            if (*param_4 < iVar6 + 0x26c) goto LAB_c052969c;
LAB_c0529754:
            iVar6 = iVar6 + 0x26c;
            iVar1 = FUN_c052942c(param_2,(int)piVar4);
            if (iVar1 != 0) break;
            iVar5 = iVar5 + 1;
            param_2 = param_2 + 0x9b;
          }
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4e0);
    if (iVar3 == 0) goto LAB_c05296e4;
  }
  *param_5 = iVar3;
  if (*param_4 < iVar6) {
    *param_4 = iVar6;
  }
  iVar5 = -1;
LAB_c05296e4:
  FUN_c052c8e4(local_30);
  return iVar5;
}



/* c052977c FUN_c052977c */

/* Boundary evidence: original MIPS .pdata c052977c..c0529787. Semantic name remains unreviewed. */

undefined4 FUN_c052977c(void)

{
  return 1;
}



/* c0529788 FUN_c0529788 */

/* Boundary evidence: original MIPS .pdata c0529788..c0529a57. Semantic name remains unreviewed. */

undefined4
FUN_c0529788(int *param_1,wchar_t *param_2,int param_3,undefined4 param_4,uint param_5,uint param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *hMem;
  undefined4 *puVar5;
  uint uVar6;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  uVar4 = 0;
  if ((param_6 & 1) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4c0);
    for (uVar6 = 0; uVar6 < param_5; uVar6 = uVar6 + 1) {
      puVar3 = LocalAlloc(0x40,0x480);
      if (puVar3 == (undefined4 *)0x0) {
        uVar4 = 0x2747;
        break;
      }
      memcpy(puVar3 + 1,(void *)(uVar6 * 0x274 + param_3),0x274);
      wcsncpy((wchar_t *)(puVar3 + 0x9e),param_2,0x103);
      *(undefined2 *)((int)puVar3 + 0x47e) = 0;
      puVar3[6] = *param_1;
      puVar3[7] = param_1[1];
      puVar3[8] = param_1[2];
      puVar3[9] = param_1[3];
      puVar3[10] = DAT_c052e414;
      DAT_c052e414 = DAT_c052e414 + 1;
      *puVar3 = DAT_c052e410;
      if (DAT_c052e418 == (undefined4 *)0x0) {
        DAT_c052e418 = puVar3;
      }
      DAT_c052e41c = DAT_c052e41c + 1;
      DAT_c052e410 = puVar3;
    }
  }
  else {
    local_40 = *param_1;
    local_3c = param_1[1];
    local_38 = param_1[2];
    local_34 = param_1[3];
    uVar4 = 0x2726;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4c0);
    puVar3 = &DAT_c052e410;
    puVar1 = (undefined4 *)0x0;
    for (hMem = DAT_c052e410; hMem != (undefined4 *)0x0; hMem = (undefined4 *)*hMem) {
      iVar2 = memcmp(hMem + 6,&local_40,0x10);
      puVar5 = hMem;
      if (iVar2 == 0) {
        uVar4 = 0;
        DAT_c052e41c = DAT_c052e41c + -1;
        *puVar3 = *hMem;
        if (hMem == DAT_c052e418) {
          DAT_c052e418 = puVar1;
        }
        LocalFree(hMem);
        hMem = puVar3;
        puVar5 = puVar1;
      }
      puVar3 = hMem;
      puVar1 = puVar5;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4c0);
  FUN_c052c8e4(local_30);
  return uVar4;
}



/* c0529a58 FUN_c0529a58 */

/* Boundary evidence: original MIPS .pdata c0529a58..c0529a63. Semantic name remains unreviewed. */

undefined4 FUN_c0529a58(void)

{
  return 1;
}



/* c0529a64 FUN_c0529a64 */

/* Boundary evidence: original MIPS .pdata c0529a64..c0529a6f. Semantic name remains unreviewed. */

undefined4 FUN_c0529a64(void)

{
  return 1;
}



/* c0529a70 FUN_c0529a70 */

/* Boundary evidence: original MIPS .pdata c0529a70..c0529d43. Semantic name remains unreviewed. */

int FUN_c0529a70(int param_1,void *param_2,undefined4 param_3,uint *param_4,uint *param_5,
                int *param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint local_2c;
  
  uVar7 = 0;
  iVar6 = 0;
  bVar1 = true;
  iVar2 = FUN_c0527d50(param_4,&local_2c);
  if (iVar2 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4c0);
    for (piVar5 = (int *)DAT_c052e410; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
      if (param_1 != 0) {
        bVar1 = false;
        for (iVar4 = 0; iVar3 = *(int *)(iVar4 * 4 + param_1), iVar3 != 0; iVar4 = iVar4 + 1) {
          if ((piVar5[0x18] <= iVar3) && (iVar3 <= piVar5[0x19] + piVar5[0x18])) {
            bVar1 = true;
            goto LAB_c0529be8;
          }
        }
      }
      if (bVar1) {
LAB_c0529be8:
        if (((*param_5 & 1) == 0) || (((piVar5[5] & 4U) == 0 && (0 < piVar5[0xb])))) {
          iVar6 = iVar6 + 1;
          uVar7 = uVar7 + 0x274;
          if (local_2c < uVar7) {
            iVar2 = 0x2747;
          }
          else {
            memcpy(param_2,piVar5 + 1,0x274);
            param_2 = (void *)((int)param_2 + 0x274);
          }
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4c0);
    if (iVar2 != 0x271e) {
      *param_4 = uVar7;
    }
    if (iVar2 == 0) {
      return iVar6;
    }
  }
  *param_6 = iVar2;
  return -1;
}



/* c0529d44 FUN_c0529d44 */

/* Boundary evidence: original MIPS .pdata c0529d44..c0529d4f. Semantic name remains unreviewed. */

undefined4 FUN_c0529d44(void)

{
  return 1;
}



/* c0529d50 FUN_c0529d50 */

/* Boundary evidence: original MIPS .pdata c0529d50..c0529d5b. Semantic name remains unreviewed. */

undefined4 FUN_c0529d50(void)

{
  return 1;
}



/* c0529d5c FUN_c0529d5c */

/* Boundary evidence: original MIPS .pdata c0529d5c..c0529d67. Semantic name remains unreviewed. */

undefined4 FUN_c0529d5c(void)

{
  return 1;
}



/* c0529d68 FUN_c0529d68 */

/* Boundary evidence: original MIPS .pdata c0529d68..c052a03b. Semantic name remains unreviewed. */

int FUN_c0529d68(int param_1,int param_2,int param_3,int param_4,uint param_5,void *param_6,
                undefined4 param_7,wchar_t *param_8)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined1 auStack_40 [16];
  uint local_30;
  
  local_30 = DAT_c052e2d8;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4c0);
  piVar2 = DAT_c052e410;
  if ((param_5 & 1) == 0) {
    if ((param_5 & 2) == 0) {
      if ((param_1 == 0) && (param_3 == 0)) {
        iVar3 = 0x2726;
        goto LAB_c0529e48;
      }
      iVar3 = 0x273f;
      if (DAT_c052e410 == (int *)0x0) goto LAB_c0529e48;
      do {
        if ((piVar2[0xb] != 0) && ((param_1 == 0 || (param_1 == piVar2[0x14])))) {
          if ((param_2 == 0) || (param_2 == piVar2[0x17])) {
            if (((param_3 == 0) && ((piVar2[5] & 8U) != 0)) ||
               ((piVar2[0x18] <= param_3 && (param_3 <= piVar2[0x19] + piVar2[0x18])))) break;
            iVar1 = 0x273b;
          }
          else {
            iVar1 = 0x273c;
          }
          if ((iVar1 == 0x273b) || (iVar3 == 0x273f)) {
            iVar3 = iVar1;
          }
        }
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)0x0);
      goto LAB_c0529fdc;
    }
    iVar3 = 0x2726;
    iVar1 = CeSafeCopyMemory(auStack_40,param_6,0x10);
    if (iVar1 == 0) {
      iVar3 = 0x271e;
      goto LAB_c0529e48;
    }
    piVar4 = (int *)0x0;
    piVar2 = DAT_c052e410;
    if (DAT_c052e410 == (int *)0x0) {
LAB_c0529ef0:
      if (piVar4 != (int *)0x0) {
        piVar2 = piVar4;
      }
      goto LAB_c0529fdc;
    }
    do {
      iVar1 = memcmp(piVar2 + 6,auStack_40,0x10);
      piVar5 = piVar4;
      if ((iVar1 == 0) && (piVar5 = piVar2, param_4 == piVar2[10])) break;
      piVar2 = (int *)*piVar2;
      piVar4 = piVar5;
    } while (piVar2 != (int *)0x0);
    if (piVar2 == (int *)0x0) goto LAB_c0529ef0;
  }
  else {
    iVar3 = 0x2726;
    if (DAT_c052e410 == (int *)0x0) goto LAB_c0529e48;
    do {
      if (param_4 == piVar2[10]) break;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
LAB_c0529fdc:
    if (piVar2 == (int *)0x0) goto LAB_c0529e48;
  }
  iVar3 = 0;
  if (param_6 != (void *)0x0) {
    memcpy(param_6,piVar2 + 1,0x274);
  }
  wcscpy(param_8,(wchar_t *)(piVar2 + 0x9e));
LAB_c0529e48:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c052e4c0);
  FUN_c052c8e4(local_30);
  return iVar3;
}



/* c052a03c FUN_c052a03c */

/* Boundary evidence: original MIPS .pdata c052a03c..c052a047. Semantic name remains unreviewed. */

undefined4 FUN_c052a03c(void)

{
  return 1;
}



/* c052a048 FUN_c052a048 */

undefined4 FUN_c052a048(int param_1)

{
  undefined4 uVar1;
  
  if (((param_1 < 0x61) || (0x7a < param_1)) && ((param_1 < 0x41 || (0x5a < param_1)))) {
    if ((param_1 < 0x30) || (uVar1 = 1, 0x39 < param_1)) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c052a0a8 FUN_c052a0a8 */

/* Boundary evidence: original MIPS .pdata c052a0a8..c052a40f. Semantic name remains unreviewed. */

int FUN_c052a0a8(LPCSTR param_1,int param_2)

{
  char cVar1;
  int iVar2;
  LSTATUS LVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  DWORD local_170;
  HKEY local_16c;
  wchar_t awStack_168 [15];
  undefined2 local_14a;
  WCHAR aWStack_e8 [64];
  CHAR aCStack_68 [64];
  uint local_28;
  
  local_28 = DAT_c052e2d8;
  if ((param_2 < 0x40) && (1 < param_2)) {
    cVar1 = *param_1;
    if (((cVar1 < 'a') || ('z' < cVar1)) && ((cVar1 < 'A' || ('Z' < cVar1)))) {
      LVar3 = 0x2726;
LAB_c052a3d4:
      if (LVar3 == 0x2735) {
        LVar3 = 0;
      }
      goto LAB_c052a3e0;
    }
    iVar5 = param_2 + -2;
    iVar4 = 1;
    if (1 < iVar5) {
      do {
        iVar6 = (int)param_1[iVar4];
        iVar2 = FUN_c052a048(iVar6);
        if (((iVar2 == 0) && (iVar6 != 0x2d)) && (iVar6 != 0x5f)) goto LAB_c052a0e8;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar5);
    }
    iVar4 = FUN_c052a048((int)param_1[iVar5]);
    if ((iVar4 != 0) && ((param_1 + iVar5)[1] == '\0')) {
      iVar4 = MultiByteToWideChar(0,0,param_1,-1,aWStack_e8,param_2);
      if (iVar4 == param_2) {
        LVar3 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0,&local_16c);
        if (LVar3 == 0) {
          local_170 = 0x80;
          memset(awStack_168,0,0x80);
          LVar3 = RegQueryValueExW(local_16c,L"Name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)awStack_168,
                                   &local_170);
          if (LVar3 == 0) {
            iVar4 = wcscmp(aWStack_e8,awStack_168);
            if (iVar4 == 0) {
              LVar3 = 0x2735;
            }
            local_170 = (local_170 >> 1) - 1;
          }
          else if (LVar3 == 0xea) {
            LVar3 = 0;
          }
          if (0xf < local_170) {
            local_170 = 0xf;
            local_14a = 0;
          }
          if (LVar3 == 0) {
            LVar3 = RegSetValueExW(local_16c,L"Name",0,1,(BYTE *)aWStack_e8,param_2 << 1);
            if ((LVar3 == 0) && (iVar4 = _wcsicmp(aWStack_e8,awStack_168), iVar4 != 0)) {
              CeEventHasOccurred(0xd,0);
              if ((code *)PTR_FUN_c052e1ec != FUN_c052c76c) {
                WideCharToMultiByte(1,0,awStack_168,0x10,aCStack_68,0x10,(LPCSTR)0x0,(LPBOOL)0x0);
                iVar4 = (*(code *)PTR_FUN_c052e1ec)(0,5,0,local_170,aCStack_68,0,0);
                LVar3 = 0;
                if (iVar4 == 0) {
                  LVar3 = 0x2a94;
                }
              }
              FUN_c051b458(aWStack_e8);
              FUN_c051de94();
            }
          }
          RegCloseKey(local_16c);
        }
        goto LAB_c052a3d4;
      }
    }
  }
LAB_c052a0e8:
  LVar3 = 0x2726;
LAB_c052a3e0:
  FUN_c052c8e4(local_28);
  return LVar3;
}



/* c052a410 FUN_c052a410 */

/* Boundary evidence: original MIPS .pdata c052a410..c052a6fb. Semantic name remains unreviewed. */

int FUN_c052a410(int *param_1,void *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  DWORD dwErrCode;
  HLOCAL _Src;
  HLOCAL _Dst;
  int iVar4;
  uint _Size;
  undefined4 *puVar5;
  HLOCAL _Src_00;
  SIZE_T uBytes;
  uint *puVar6;
  uint local_48;
  uint *local_44;
  undefined4 local_40;
  int local_3c;
  HLOCAL local_38;
  HLOCAL local_34;
  HLOCAL local_30;
  void *local_2c;
  
  dwErrCode = 0x57;
  iVar4 = 0;
  local_3c = 0;
  _Size = 0;
  _Src = (HLOCAL)0x0;
  local_38 = (HLOCAL)0x0;
  _Dst = (HLOCAL)0x0;
  local_44 = param_4;
  local_2c = param_2;
  if ((10000000 < param_3) || (param_3 != *param_4)) goto LAB_c052a4ec;
  if (param_1 == (int *)0x0) {
LAB_c052a59c:
    puVar6 = local_44;
    _Dst = LocalAlloc(0,param_3);
    local_34 = _Dst;
    local_30 = _Dst;
    if (_Dst != (HLOCAL)0x0) {
      if (_Src != (void *)0x0) {
        memcpy(_Dst,_Src,param_3);
      }
      iVar3 = 0;
      _Src_00 = _Dst;
      local_48 = param_3;
      if (0 < DAT_c052e460) {
        puVar5 = &DAT_c052e470;
        do {
          if (param_3 < _Size) {
            local_48 = 0;
          }
          else {
            local_48 = param_3 - _Size;
          }
          iVar1 = (**(code **)(((undefined4 *)*puVar5)[2] + 0x6c))
                            (_Src,*(undefined4 *)*puVar5,_Dst,&local_48);
          _Size = local_48 + _Size;
          if (0 < iVar1) {
            iVar4 = iVar1 + iVar4;
            _Dst = (HLOCAL)(iVar1 * 0x20 + (int)_Dst);
            local_3c = iVar4;
            local_34 = _Dst;
          }
          iVar3 = iVar3 + 1;
          puVar5 = puVar5 + 1;
          _Src_00 = local_30;
          puVar6 = local_44;
        } while (iVar3 < DAT_c052e460);
      }
      if (param_3 < _Size) {
        *puVar6 = _Size;
        dwErrCode = 0x7a;
        local_40 = 0x7a;
      }
      else {
        memcpy(local_2c,_Src_00,_Size);
        dwErrCode = 0;
        local_40 = 0;
        *puVar6 = _Size;
      }
      goto LAB_c052a4ec;
    }
  }
  else {
    iVar3 = 0;
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
      iVar1 = *piVar2;
    }
    uBytes = (iVar3 + 1) * 4;
    _Src = LocalAlloc(0,uBytes);
    local_38 = _Src;
    if (_Src != (HLOCAL)0x0) {
      iVar3 = CeSafeCopyMemory(_Src,param_1,uBytes);
      if (iVar3 == 0) goto LAB_c052a4ec;
      *(undefined4 *)((int)_Src + (uBytes - 4)) = 0;
      goto LAB_c052a59c;
    }
  }
  dwErrCode = 8;
LAB_c052a4ec:
  if (_Src != (HLOCAL)0x0) {
    LocalFree(_Src);
  }
  if (_Dst != (HLOCAL)0x0) {
    LocalFree(_Dst);
  }
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
    iVar4 = -1;
  }
  return iVar4;
}



/* c052a6fc FUN_c052a6fc */

/* Boundary evidence: original MIPS .pdata c052a6fc..c052a707. Semantic name remains unreviewed. */

undefined4 FUN_c052a6fc(void)

{
  return 1;
}



/* c052a708 FUN_c052a708 */

/* Boundary evidence: original MIPS .pdata c052a708..c052a74f. Semantic name remains unreviewed. */

undefined4 FUN_c052a708(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((HLOCAL)*param_1 != (HLOCAL)0x0) {
      LocalFree((HLOCAL)*param_1);
    }
    LocalFree(param_1);
  }
  return 0;
}



/* c052a750 FUN_c052a750 */

/* Boundary evidence: original MIPS .pdata c052a750..c052a777. Semantic name remains unreviewed. */

undefined4 FUN_c052a750(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    LocalFree(param_1);
  }
  return 0;
}



/* c052a778 FUN_c052a778 */

/* Boundary evidence: original MIPS .pdata c052a778..c052a987. Semantic name remains unreviewed. */

int FUN_c052a778(undefined4 *param_1,int param_2,uint param_3,int param_4,uint *param_5,int param_6)

{
  undefined4 *hMem;
  int iVar1;
  int iVar2;
  HLOCAL hMem_00;
  undefined4 *puVar3;
  undefined1 auStack_70 [4];
  code *local_6c;
  undefined4 *local_68;
  undefined1 auStack_58 [24];
  undefined4 local_40;
  undefined4 *local_3c;
  uint local_38;
  
  iVar2 = 0x57;
  hMem_00 = (HLOCAL)0x0;
  if (param_2 == 0) {
    return 0x57;
  }
  if (param_4 == 0) {
    return 0x57;
  }
  if (param_5 == (uint *)0x0) {
    return 0x57;
  }
  if (param_6 == 0) {
    return 0x57;
  }
  if (param_3 < 0x18) {
    return 0x57;
  }
  if (10000000 < param_3) {
    return 0x57;
  }
  if (10000000 < *param_5) {
    return 0x57;
  }
  hMem = LocalAlloc(0x40,*param_5 + 4);
  if ((hMem == (undefined4 *)0x0) ||
     (hMem_00 = LocalAlloc(0,param_3 - 0x14), hMem_00 == (HLOCAL)0x0)) {
    iVar2 = 8;
  }
  else {
    *hMem = hMem_00;
    puVar3 = hMem + 1;
    iVar1 = CeSafeCopyMemory(auStack_58,param_2,0x14);
    if (((iVar1 == 0) || (iVar1 = CeSafeCopyMemory(hMem_00,param_6,param_3 - 0x14), iVar1 == 0)) ||
       (iVar1 = CeSafeCopyMemory(puVar3,param_4,*param_5), iVar1 == 0)) goto LAB_c052a938;
    memset(auStack_70,0,0x14);
    local_6c = FUN_c052a708;
    local_38 = *param_5;
    local_40 = 0;
    local_68 = hMem;
    local_3c = puVar3;
    iVar2 = (**(code **)(param_1[2] + 0x48))(auStack_70,param_2,&local_40,param_5,hMem_00);
    param_1 = puVar3;
  }
  if (iVar2 == 0xff) {
    return 0xff;
  }
  if (((iVar2 == 0) || (iVar2 == 9)) &&
     (iVar1 = CeSafeCopyMemory(param_4,param_1,*param_5), iVar1 == 0)) {
    iVar2 = 0x271e;
  }
LAB_c052a938:
  if (hMem != (undefined4 *)0x0) {
    LocalFree(hMem);
  }
  if (hMem_00 != (HLOCAL)0x0) {
    LocalFree(hMem_00);
  }
  return iVar2;
}



/* c052a988 FUN_c052a988 */

/* Boundary evidence: original MIPS .pdata c052a988..c052aaaf. Semantic name remains unreviewed. */

int FUN_c052a988(int param_1,int param_2,int param_3,uint param_4)

{
  HLOCAL hMem;
  int iVar1;
  undefined1 auStack_48 [4];
  code *local_44;
  HLOCAL local_40;
  undefined1 auStack_30 [24];
  
  if (((param_2 != 0) && (param_3 != 0)) && (param_4 < 0x989681)) {
    hMem = LocalAlloc(0x40,param_4);
    if (hMem == (HLOCAL)0x0) {
      return 8;
    }
    iVar1 = CeSafeCopyMemory(auStack_30,param_2,0x14);
    if ((iVar1 != 0) && (iVar1 = CeSafeCopyMemory(hMem,param_3,param_4), iVar1 != 0)) {
      memset(auStack_48,0,0x14);
      local_44 = FUN_c052a750;
      local_40 = hMem;
      iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(auStack_48,param_2,hMem,param_4);
      if (iVar1 == 0xff) {
        return 0xff;
      }
      LocalFree(hMem);
      return iVar1;
    }
    LocalFree(hMem);
  }
  return 0x57;
}



/* c052aab0 FUN_c052aab0 */

/* Boundary evidence: original MIPS .pdata c052aab0..c052ac6f. Semantic name remains unreviewed. */

undefined4 FUN_c052aab0(int param_1,SIZE_T *param_2,int param_3,SIZE_T *param_4)

{
  HLOCAL hMem;
  int iVar1;
  undefined4 uVar2;
  HLOCAL hMem_00;
  
  if (((((param_1 == 0) || (param_2 == (SIZE_T *)0x0)) || (param_3 == 0)) ||
      ((param_4 == (SIZE_T *)0x0 || (10000000 < *param_2)))) || (10000000 < *param_4)) {
    return 0x57;
  }
  if (DAT_c052e424 == (code *)0x0) {
    DAT_c052e420 = LoadLibraryW(L"TcpStk.dll");
    if (DAT_c052e420 != (HMODULE)0x0) {
      DAT_c052e424 = (code *)GetProcAddressW(DAT_c052e420,L"VXDEchoRequest");
    }
    if (DAT_c052e424 == (code *)0x0) {
      return 0x2747;
    }
  }
  hMem_00 = (HLOCAL)0x0;
  hMem = LocalAlloc(0,*param_2);
  if ((hMem == (HLOCAL)0x0) || (hMem_00 = LocalAlloc(0,*param_4), hMem_00 == (HLOCAL)0x0)) {
    uVar2 = 0x2747;
  }
  else {
    iVar1 = CeSafeCopyMemory(hMem,param_1,*param_2);
    if (iVar1 != 0) {
      uVar2 = (*DAT_c052e424)(hMem,param_2,hMem_00,param_4);
      iVar1 = CeSafeCopyMemory(param_3,hMem_00,*param_4);
      if (iVar1 != 0) goto LAB_c052ac18;
    }
    uVar2 = 0x271e;
  }
LAB_c052ac18:
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
  if (hMem_00 != (HLOCAL)0x0) {
    LocalFree(hMem_00);
  }
  return uVar2;
}



/* c052ac70 FUN_c052ac70 */

/* Boundary evidence: original MIPS .pdata c052ac70..c052ace7. Semantic name remains unreviewed. */

void FUN_c052ac70(void)

{
  int nPriority;
  int iVar1;
  
  nPriority = GetThreadPriority((HANDLE)0x41);
  SetThreadPriority((HANDLE)0x41,1);
  for (iVar1 = DAT_c052e428; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
  }
  SetThreadPriority((HANDLE)0x41,nPriority);
  return;
}



/* c052ace8 FUN_c052ace8 */

/* Boundary evidence: original MIPS .pdata c052ace8..c052b023. Semantic name remains unreviewed. */

int FUN_c052ace8(uint param_1,int param_2,uint *param_3,uint param_4,int param_5,uint *param_6)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  SIZE_T local_70;
  uint local_6c;
  CHAR aCStack_68 [68];
  uint local_24;
  
  local_24 = DAT_c052e2d8;
  iVar5 = 0x2726;
  if (param_1 == 0xffffffff) {
    if (param_2 == 4) {
      if (param_4 == 4) {
        uVar2 = *param_3 & 0xffff;
        if ((((uVar2 == 2) || (uVar2 == 4)) || (uVar2 == 8)) || (uVar2 == 0x10)) {
          FUN_c052ac70();
        }
        else if ((uVar2 == 0x20) && (iVar4 = 0, 0 < DAT_c052e460)) {
          puVar7 = &DAT_c052e470;
          iVar6 = DAT_c052e460;
          do {
            puVar8 = (undefined4 *)*puVar7;
            iVar1 = wcscmp(L"MSIrDA",(wchar_t *)*puVar8);
            if (iVar1 == 0) {
              (**(code **)(puVar8[2] + 0x58))(0,0,0,0,0xfffe,0x2a,0,0);
              iVar6 = DAT_c052e460;
            }
            iVar4 = iVar4 + 1;
            puVar7 = puVar7 + 1;
          } while (iVar4 < iVar6);
        }
      }
    }
    else if (param_2 == 5) {
      if (*param_6 == 4) {
        iVar5 = 0x273d;
      }
    }
    else if (param_2 == 6) {
      iVar5 = 0;
      FUN_c05145e8();
    }
    else if ((param_2 == 0x80) && (param_4 < 0x40)) {
      iVar5 = CeSafeCopyMemory(aCStack_68,param_3,param_4);
      if (iVar5 == 0) {
        iVar5 = 0x271e;
      }
      else {
        iVar5 = FUN_c052a0a8(aCStack_68,param_4);
      }
    }
    goto LAB_c052afec;
  }
  iVar4 = 0;
  piVar9 = &DAT_c052e470;
  if (0 < DAT_c052e460) {
    do {
      local_70 = 0;
      puVar3 = *(uint **)(*piVar9 + 4);
      if (*puVar3 != 0) {
        do {
          if (param_1 == puVar3[local_70 * 3 + 4]) goto LAB_c052adb8;
          local_70 = local_70 + 1;
          puVar3 = *(uint **)(*piVar9 + 4);
        } while (local_70 < *puVar3);
      }
      iVar4 = iVar4 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar4 < DAT_c052e460);
  }
LAB_c052adb8:
  if (iVar4 == DAT_c052e460) {
    SetLastError(0x273b);
    FUN_c052c8e4(local_24);
    return -1;
  }
  local_70 = *param_6;
  if (param_2 == 0) {
    iVar5 = FUN_c052a778((undefined4 *)(&DAT_c052e470)[iVar4],(int)param_3,param_4,param_5,&local_70
                         ,(int)(param_3 + 5));
  }
  else {
    if (param_2 == 1) {
      iVar5 = FUN_c052a988((int)(&DAT_c052e470)[iVar4],(int)param_3,(int)(param_3 + 6),param_3[5]);
      goto LAB_c052afec;
    }
    if (param_2 != 2) goto LAB_c052afec;
    local_6c = param_4;
    iVar5 = FUN_c052aab0((int)param_3,&local_6c,param_5,&local_70);
  }
  if (iVar5 == 0) {
    *param_6 = local_70;
  }
LAB_c052afec:
  FUN_c052c8e4(local_24);
  return iVar5;
}



/* c052b024 FUN_c052b024 */

/* Boundary evidence: original MIPS .pdata c052b024..c052b08f. Semantic name remains unreviewed. */

void FUN_c052b024(uint param_1,int param_2,uint *param_3,uint param_4,int param_5,undefined4 param_6
                 ,uint *param_7)

{
  uint *puVar1;
  uint local_18 [2];
  
  if (param_7 == (uint *)0x0) {
    puVar1 = (uint *)0x0;
    local_18[0] = 0;
  }
  else {
    local_18[0] = *param_7;
    puVar1 = local_18;
  }
  FUN_c052ace8(param_1,param_2,param_3,param_4,param_5,local_18);
  if (puVar1 != (uint *)0x0) {
    *param_7 = local_18[0];
  }
  return;
}



/* c052b090 FUN_c052b090 */

/* Boundary evidence: original MIPS .pdata c052b090..c052b2cf. Semantic name remains unreviewed. */

undefined4 FUN_c052b090(wchar_t *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined4 *puVar4;
  uint uVar5;
  void *pvVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  uint local_28 [2];
  
  iVar1 = DAT_c052e460;
  puVar10 = &DAT_c052e470;
  iVar9 = DAT_c052e460;
  while (iVar9 != 0) {
    iVar9 = iVar9 + -1;
    iVar2 = wcscmp(*(wchar_t **)*puVar10,param_1);
    if (iVar2 == 0) {
      return 0x1a;
    }
    puVar10 = puVar10 + 1;
  }
  if (iVar1 < 4) {
    sVar3 = wcslen(param_1);
    puVar4 = FUN_c051de9c((sVar3 + 0x11) * 2);
    *puVar10 = puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = puVar4 + 7;
      wcscpy((wchar_t *)(puVar4 + 7),param_1);
      puVar4[2] = param_2;
      uVar5 = (**(code **)(param_2 + 0x5c))(0,0);
      pvVar6 = FUN_c051de9c(uVar5);
      puVar4[1] = pvVar6;
      if (pvVar6 != (void *)0x0) {
        uVar7 = (**(code **)(puVar4[2] + 0x5c))(pvVar6,uVar5);
        if ((uVar7 == uVar5) && (*(int *)(puVar4[1] + 4) == 3)) {
          local_28[0] = 0;
          (**(code **)(puVar4[2] + 0x6c))(0,0,0,local_28);
          pvVar6 = FUN_c051de9c(local_28[0]);
          if (pvVar6 != (void *)0x0) {
            iVar9 = (**(code **)(puVar4[2] + 0x6c))(0,0,pvVar6,local_28);
            puVar4[3] = 0xffff;
            puVar4[4] = 0;
            if (iVar9 != 0) {
              piVar8 = (int *)((int)pvVar6 + 8);
              do {
                if (piVar8[1] < (int)puVar4[3]) {
                  puVar4[3] = piVar8[1];
                }
                if ((int)puVar4[4] < *piVar8) {
                  puVar4[4] = *piVar8;
                }
                iVar9 = iVar9 + -1;
                piVar8 = piVar8 + 8;
              } while (iVar9 != 0);
            }
            CTEFreeMem(pvVar6);
          }
          uVar5 = puVar4[4];
          if (DAT_c052e458 < uVar5) {
            DAT_c052e480 = uVar5 + 6;
            DAT_c052e458 = uVar5;
          }
          puVar4[5] = puVar4[3] + 0xb & 0xfffffffc;
          puVar4[6] = puVar4[4] + 0xb & 0xfffffffc;
          DAT_c052e460 = DAT_c052e460 + 1;
          return 0;
        }
        CTEFreeMem(puVar4[1]);
      }
      CTEFreeMem(puVar4);
    }
  }
  return 0x1a;
}



/* c052b2d0 FUN_c052b2d0 */

/* Boundary evidence: original MIPS .pdata c052b2d0..c052b4d3. Semantic name remains unreviewed. */

undefined4 FUN_c052b2d0(LPCWSTR param_1,uint param_2)

{
  WCHAR WVar1;
  HMODULE pHVar2;
  code *pcVar3;
  int iVar4;
  size_t sVar5;
  undefined4 uVar6;
  int local_30 [2];
  
  WVar1 = *param_1;
  uVar6 = 1;
  do {
    if (WVar1 == L'\0') {
      return uVar6;
    }
    pHVar2 = LoadLibraryW(param_1);
    if (pHVar2 == (HMODULE)0x0) {
LAB_c052b34c:
      uVar6 = 0;
    }
    else if ((param_2 & 1) == 0) {
      if ((param_2 & 2) == 0) {
        if ((param_2 & 4) != 0) {
          pcVar3 = (code *)GetProcAddressW(pHVar2,L"ReadyToGo");
          if (pcVar3 == (code *)0x0) goto LAB_c052b34c;
          (*pcVar3)();
        }
      }
      else {
        pcVar3 = (code *)GetProcAddressW(pHVar2,param_1);
        if ((pcVar3 == (code *)0x0) ||
           (iVar4 = (*pcVar3)(0,1,&PTR_FUN_c052e224,0,&PTR_FUN_c0511bc0,0,local_30), iVar4 == 0))
        goto LAB_c052b34c;
        if (0 < local_30[0]) {
          (&PTR_FUN_c052e18c)[local_30[0]] = pcVar3;
          (&PTR_FUN_c052e224)[local_30[0]] = pcVar3;
        }
      }
    }
    else {
      pcVar3 = (code *)GetProcAddressW(pHVar2,L"Register");
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(FUN_c052b090,0);
        iVar4 = _wcsicmp(param_1,L"tcpip6");
        if (iVar4 == 0) {
          DAT_c052e4f4 = GetProcAddressW(pHVar2,L"IPDispatchDeviceControl");
        }
      }
    }
    sVar5 = wcslen(param_1);
    param_1 = param_1 + sVar5 + 1;
    WVar1 = *param_1;
  } while( true );
}



/* c052b4d4 FUN_c052b4d4 */

/* Boundary evidence: original MIPS .pdata c052b4d4..c052b4ef. Semantic name remains unreviewed. */

void FUN_c052b4d4(LPCWSTR param_1)

{
  FUN_c052b2d0(param_1,2);
  return;
}



/* c052b4f0 FUN_c052b4f0 */

/* Boundary evidence: original MIPS .pdata c052b4f0..c052b513. Semantic name remains unreviewed. */

undefined4 FUN_c052b4f0(LPCWSTR param_1)

{
  FUN_c052b2d0(param_1,1);
  return DAT_c052e460;
}



/* c052b514 FUN_c052b514 */

/* Boundary evidence: original MIPS .pdata c052b514..c052b56f. Semantic name remains unreviewed. */

undefined4 FUN_c052b514(LPCWSTR param_1,LPCWSTR param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_c052b2d0(param_1,4);
  iVar2 = FUN_c052b2d0(param_2,4);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* c052b570 FUN_c052b570 */

undefined4 FUN_c052b570(uint param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + param_2;
  *param_5 = 0xffffffff;
  if (param_1 <= uVar1) {
    uVar2 = uVar1 + param_3;
    *param_5 = uVar1;
    *param_5 = 0xffffffff;
    if (uVar1 <= uVar2) {
      *param_5 = 0xffffffff;
      if (uVar2 <= uVar2 + param_4) {
        *param_5 = uVar2 + param_4;
        return 0;
      }
    }
  }
  return 0xc0000095;
}



/* c052b5d0 FUN_c052b5d0 */

/* Boundary evidence: original MIPS .pdata c052b5d0..c052b747. Semantic name remains unreviewed. */

void FUN_c052b5d0(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x41));
  puVar3 = (undefined4 *)param_1[0x11];
  param_1[3] = 0x20;
  lpCriticalSection = (LPCRITICAL_SECTION)(puVar3 + 0x41);
  param_1[4] = param_1[4] & 0xfffffffb;
  EnterCriticalSection(lpCriticalSection);
  if ((param_2 == 0) && (puVar3[3] == 8)) {
    piVar2 = puVar3 + 0x12;
    iVar1 = *piVar2;
    while (iVar1 != 0) {
      piVar2 = (int *)(*piVar2 + 0x48);
      iVar1 = *piVar2;
    }
    *piVar2 = (int)param_1;
    param_1[0x12] = 0;
    puVar3[0x15] = puVar3[0x15] + 1;
    FUN_c0528468((int)puVar3,8,0,8);
  }
  else {
    if (puVar3[3] == 8) {
      param_1[3] = 1;
      memset((void *)param_1[0x4c],0,param_1[0x4d]);
      param_1[0x4d] = 0;
      param_1[0x13] = puVar3[0x13];
      puVar3[0x13] = param_1;
      puVar3[0x16] = puVar3[0x16] + 1;
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
      iVar1 = param_1[1];
      param_1[1] = iVar1 + -1;
      if (iVar1 + -1 == 0) {
        param_1[3] = 0x200;
        FUN_c051e64c(param_1);
        return;
      }
      FUN_c05226f0((int)param_1);
      FUN_c051fa74((int)param_1);
      EnterCriticalSection(lpCriticalSection);
    }
    param_1[3] = 0x200;
  }
  FUN_c051eabc(param_1);
  FUN_c051eabc(puVar3);
  return;
}



/* c052b748 FUN_c052b748 */

/* Boundary evidence: original MIPS .pdata c052b748..c052b873. Semantic name remains unreviewed. */

undefined4 FUN_c052b748(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint _Size;
  int *in_stack_0000001c;
  undefined4 *in_stack_00000020;
  
  iVar3 = *(int *)(param_1 + 8);
  _Size = param_2 - 8;
  uVar1 = 0xe;
  if (iVar3 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x104));
    if ((((*(int *)(iVar3 + 0xc) == 8) &&
         ((uint)*(ushort *)(param_3 + 8) == *(uint *)(iVar3 + 0x18))) &&
        (_Size <= *(uint *)(*(int *)(iVar3 + 0x50) + 0x10))) &&
       ((*(uint *)(*(int *)(iVar3 + 0x50) + 0xc) <= _Size && (*(int *)(iVar3 + 0x58) != 0)))) {
      iVar2 = *(int *)(iVar3 + 0x4c);
      *(undefined4 *)(iVar3 + 0x4c) = *(undefined4 *)(iVar2 + 0x4c);
      *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + -1;
      *(undefined4 *)(iVar2 + 0x4c) = 0;
      *(uint *)(iVar2 + 0x134) = _Size;
      memcpy(*(void **)(iVar2 + 0x130),(ushort *)(param_3 + 8),_Size);
      *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
      *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
      *(undefined4 *)(iVar2 + 0x10) = 4;
      *in_stack_00000020 = FUN_c052b5d0;
      in_stack_00000020[1] = iVar2;
      in_stack_00000020[2] = 0;
      in_stack_00000020[3] = 0;
      *in_stack_0000001c = iVar2;
      uVar1 = 0x18;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x104));
  }
  return uVar1;
}



/* c052b874 FUN_c052b874 */

/* Boundary evidence: original MIPS .pdata c052b874..c052b9b7. Semantic name remains unreviewed. */

undefined4 FUN_c052b874(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint in_stack_00000018;
  
  uVar3 = 0;
  if ((*param_2 != param_2[0x6f]) || (*param_2 != -0xee11de)) {
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x41));
  if (param_2[3] < 0x20) {
    uVar2 = param_2[4];
    if ((uVar2 & 4) == 0) {
      uVar3 = 0xfe;
    }
    else {
      param_2[4] = uVar2 | 0x200;
      if ((in_stack_00000018 & 2) != 0) {
        param_2[4] = uVar2 | 0x600;
      }
    }
  }
  else {
    uVar2 = param_2[4];
    param_2[4] = uVar2 | 0x200;
    if ((in_stack_00000018 & 2) == 0) {
      if (param_2[0x32] != 0) {
        param_2[4] = uVar2 | 0x4200;
        goto LAB_c052b988;
      }
      FUN_c0528468((int)param_2,0x20,0,0x20);
      uVar1 = 0;
    }
    else {
      param_2[4] = uVar2 | 0x600;
      FUN_c0528468((int)param_2,1,0x2746,0);
      FUN_c0528468((int)param_2,0x20,0x2746,0x20);
      uVar1 = 0x2746;
    }
    FUN_c0528710((int)param_2,uVar1);
  }
LAB_c052b988:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x41));
  return uVar3;
}



/* c052b9b8 FUN_c052b9b8 */

/* Boundary evidence: original MIPS .pdata c052b9b8..c052baeb. Semantic name remains unreviewed. */

undefined4
FUN_c052b9b8(undefined4 param_1,int param_2,undefined4 param_3,uint param_4,uint param_5,
            uint *param_6,void *param_7)

{
  uint uVar1;
  undefined4 uVar2;
  
  *param_6 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x104));
  if (((*(uint *)(param_2 + 0x14) & 0x20) == 0) && (*(int *)(param_2 + 0xc) != 0x200)) {
    uVar2 = 0x17;
    if ((*(int *)(param_2 + 0xe0) == 0) || (*(int *)(param_2 + 0xc0) == 0)) {
      *(uint *)(param_2 + 0xc0) = param_5;
    }
    else {
      *(uint *)(param_2 + 0xc4) = param_5;
    }
    if ((((param_7 != (void *)0x0) && (*(uint *)(param_2 + 200) < *(uint *)(param_2 + 0xf4))) &&
        (*(int *)(param_2 + 0xdc) == 0)) &&
       (uVar1 = FUN_c051bb60(param_2,param_4,param_7), uVar1 != 0)) {
      uVar2 = 0;
      *param_6 = uVar1;
    }
    FUN_c0528468(param_2,1,0,1);
  }
  else {
    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 0x400;
    FUN_c05226f0(param_2);
    uVar2 = 0;
    *param_6 = param_5;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x104));
  return uVar2;
}



/* c052baec FUN_c052baec */

/* Boundary evidence: original MIPS .pdata c052baec..c052bf87. Semantic name remains unreviewed. */

undefined4
FUN_c052baec(int param_1,uint param_2,void *param_3,uint param_4,void *param_5,uint param_6,
            uint param_7,void *param_8,undefined4 *param_9,undefined4 *param_10)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  size_t local_38 [2];
  undefined4 *local_30;
  
  local_38[1] = 0;
  puVar4 = *(undefined4 **)(param_1 + 0x158);
  local_30 = puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x158) = *puVar4;
    puVar4[1] = puVar4[1] | 0x20;
    if (puVar4[2] != 0) {
      puVar2 = (uint *)puVar4[0xb];
      if ((puVar2 != (uint *)0x0) && (param_2 < *puVar2)) {
        puVar4[10] = param_2;
        *puVar2 = param_2;
      }
      memcpy((void *)puVar4[2],param_3,puVar4[10]);
    }
    if (puVar4[0xe] != 0) {
      if (param_4 < *(uint *)puVar4[0x11]) {
        *(uint *)puVar4[0x11] = param_4;
      }
      if ((uint)puVar4[0x10] < param_4) {
        param_4 = puVar4[0x10];
      }
      memcpy((void *)puVar4[0xe],param_5,param_4);
    }
    if (*(ushort *)(puVar4 + 0xd) < param_7) {
      iVar6 = 0x2738;
    }
    else {
      *(short *)(puVar4 + 0xd) = (short)param_7;
      iVar6 = 0;
    }
    if ((undefined4 *)puVar4[0x13] != (undefined4 *)0x0) {
      uVar1 = 0;
      if ((param_6 & 4) != 0) {
        uVar1 = 0x400;
      }
      if ((param_6 & 8) != 0) {
        uVar1 = uVar1 | 0x800;
      }
      if (((uint *)puVar4[0x11] != (uint *)0x0) && (*(uint *)puVar4[0x11] < param_4)) {
        uVar1 = uVar1 | 0x200;
      }
      if (iVar6 == 0x2738) {
        uVar1 = uVar1 | 0x100;
      }
      FUN_c0527ce8((undefined4 *)puVar4[0x13],uVar1);
    }
    local_38[0] = 0;
    if (*(ushort *)(puVar4 + 0xd) != 0) {
      FUN_c052c5b8((int *)puVar4[4],param_8,(uint)*(ushort *)(puVar4 + 0xd),(int *)local_38);
    }
    if (param_9 != (undefined4 *)0x0) {
      FUN_c0527bfc();
    }
    FUN_c0528468(param_1,1,iVar6,1);
    if ((puVar4[1] & 0x40) != 0) {
      piVar5 = (int *)puVar4[7];
      if (piVar5 != (int *)0x0) {
        iVar7 = puVar4[5];
        *param_10 = 0;
        FUN_c051b994(param_1,(undefined4 *)puVar4[4],(uint)(puVar4[8] != puVar4[7]));
        puVar4[4] = 0;
        uVar3 = *(undefined4 *)(param_1 + 0x24);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
        puVar4[7] = 0;
        puVar4[5] = 0;
        FUN_c051b720((int)puVar4);
        FUN_c051b84c(piVar5,puVar4[9],(uint)*(ushort *)(puVar4 + 0xd),0,iVar6,puVar4[6],uVar3,
                     (int *)puVar4[8],iVar7);
        FUN_c051b80c(param_1,(int)puVar4);
        return 0;
      }
      return 0;
    }
    return 0;
  }
  if (*(int *)(param_1 + 0xc) == 0x40) {
    param_2 = 0;
  }
  local_38[0] = param_2;
  if (param_9 == (undefined4 *)0x0) {
    if (param_7 <= *(uint *)(param_1 + 0xf4)) {
      param_9 = FUN_c0527b7c(param_2 + param_4 + param_7 + 0x14,0x14);
      if (param_9 == (undefined4 *)0x0) {
        return 0x17;
      }
      *param_9 = 0;
      *(short *)(param_9 + 1) = (short)local_38[0];
      if (local_38[0] != 0) {
        memcpy(param_9 + 4,param_3,local_38[0]);
      }
      param_9[2] = param_4;
      memcpy((void *)((int)param_9 + local_38[0] + 0x10),param_5,param_4);
      param_9[3] = param_6;
      memcpy((void *)((int)param_9 + local_38[0] + param_4 + 0x10),param_8,param_7);
    }
    if (param_9 == (undefined4 *)0x0) {
      return 0x17;
    }
  }
  *(short *)((int)param_9 + 6) = (short)param_7;
  uVar1 = (param_7 & 0xffff) + *(int *)(param_1 + 0xd8);
  *(uint *)(param_1 + 0xd8) = uVar1;
  if (*(uint *)(param_1 + 0xf4) < uVar1) {
    do {
      puVar4 = *(undefined4 **)(param_1 + 0x15c);
      if (puVar4 != (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0x15c) = *puVar4;
        *(uint *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) - (uint)*(ushort *)((int)puVar4 + 6);
        FUN_c0527bfc();
      }
    } while (*(uint *)(param_1 + 0xf4) < *(uint *)(param_1 + 0xd8));
  }
  if (*(int *)(param_1 + 0x15c) == 0) {
    *(undefined4 **)(param_1 + 0x15c) = param_9;
  }
  else {
    if (*(undefined4 **)(param_1 + 0x160) == (undefined4 *)0x0) goto LAB_c052bf2c;
    **(undefined4 **)(param_1 + 0x160) = param_9;
  }
  *(undefined4 **)(param_1 + 0x160) = param_9;
LAB_c052bf2c:
  FUN_c0528468(param_1,1,0,1);
  return 0;
}



/* c052bf88 FUN_c052bf88 */

/* Boundary evidence: original MIPS .pdata c052bf88..c052bf93. Semantic name remains unreviewed. */

undefined4 FUN_c052bf88(void)

{
  return 1;
}



/* c052bf94 FUN_c052bf94 */

/* Boundary evidence: original MIPS .pdata c052bf94..c052c083. Semantic name remains unreviewed. */

void FUN_c052bf94(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_20 [2];
  
  puVar2 = (undefined4 *)*param_1;
  puVar3 = (undefined4 *)param_1[1];
  EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
  local_20[0] = 1;
  if (((int)puVar2[3] < 0x100) && ((puVar2[4] & 0x1000) == 0)) {
    uVar1 = (uint)*(ushort *)(puVar3 + 1);
    FUN_c052baec((int)puVar2,uVar1,puVar3 + 4,puVar3[2],(void *)((int)puVar3 + uVar1 + 0x10),
                 puVar3[3],param_3,(void *)((int)puVar3 + puVar3[2] + uVar1 + 0x10),puVar3,local_20)
    ;
    if (local_20[0] == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x41));
    }
  }
  FUN_c0527bfc();
  FUN_c051eabc(puVar2);
  return;
}



/* c052c084 FUN_c052c084 */

/* Boundary evidence: original MIPS .pdata c052c084..c052c367. Semantic name remains unreviewed. */

undefined4
FUN_c052c084(int param_1,undefined4 param_2,int param_3,uint param_4,void *param_5,uint param_6,
            uint param_7,uint param_8,undefined4 *param_9,void *param_10,undefined4 *param_11)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *_Buf1;
  short *_Buf2;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  short *_Src;
  uint _Size;
  uint local_38;
  uint local_34;
  LPCRITICAL_SECTION local_30;
  
  iVar5 = *(int *)(param_3 + 4);
  *param_9 = 0;
  local_30 = (LPCRITICAL_SECTION)(param_1 + 0x104);
  _Src = (short *)(param_3 + 8);
  _Size = iVar5 + 2;
  uVar6 = 0x17;
  local_34 = param_4;
  EnterCriticalSection(local_30);
  local_38 = 1;
  if ((((*(uint *)(param_1 + 0x14) & 0x20) == 0) && (*(int *)(param_1 + 0xc) < 0x100)) &&
     ((*(uint *)(param_1 + 0x10) & 0x1000) == 0)) {
    uVar4 = _Size;
    if (*_Src == 2) {
      if ((*(uint *)(param_1 + 0x14) & 0x100) == 0) {
        memset((void *)(param_3 + 0x10),0,8);
      }
      else {
        uVar4 = 8;
      }
    }
    if (*(int *)(param_1 + 0xc) == 0x40) {
      if (*_Src == 0x17) {
        if (*(short *)(*(int *)(param_1 + 0x130) + 2) != *(short *)(param_3 + 10))
        goto LAB_c052c330;
        _Buf2 = (short *)(param_3 + 0x10);
        _Buf1 = (void *)(*(int *)(param_1 + 0x130) + 8);
        uVar4 = 0x10;
      }
      else {
        _Buf1 = *(void **)(param_1 + 0x130);
        _Buf2 = _Src;
      }
      iVar1 = memcmp(_Buf1,_Buf2,uVar4);
      if (iVar1 != 0) goto LAB_c052c330;
    }
    if (param_7 < param_8) {
      if (((param_8 <= *(uint *)(param_1 + 0xf4)) &&
          (iVar1 = FUN_c052b570(_Size,param_8,param_4,0x14,&local_38), iVar1 == 0)) &&
         (piVar2 = FUN_c0527b7c(0x40,0x18), piVar2 != (int *)0x0)) {
        puVar3 = FUN_c0527b7c(local_38,0x14);
        if (puVar3 == (undefined4 *)0x0) {
          FUN_c0527bfc();
        }
        else {
          *piVar2 = param_1;
          *(undefined2 *)(piVar2 + 9) = 0x20;
          *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
          piVar2[1] = (int)puVar3;
          piVar2[2] = (int)(piVar2 + 10);
          piVar2[3] = param_8;
          piVar2[4] = (int)FUN_c052bf94;
          piVar2[5] = (int)piVar2;
          piVar2[7] = (int)(piVar2 + 9);
          piVar2[8] = 0;
          *puVar3 = 0;
          *(short *)(puVar3 + 1) = (short)_Size;
          *(undefined2 *)((int)puVar3 + 6) = 0;
          memcpy(puVar3 + 4,_Src,_Size);
          uVar4 = local_34;
          puVar3[2] = local_34;
          memcpy((void *)((int)puVar3 + iVar5 + 0x12),param_5,local_34);
          puVar3[3] = param_6;
          piVar2[0xb] = (int)puVar3 + uVar4 + _Size + 0x10;
          piVar2[0xc] = param_8;
          piVar2[10] = 0;
          *param_9 = 0;
          uVar6 = 0x18;
          *param_11 = piVar2 + 2;
        }
      }
    }
    else {
      uVar6 = FUN_c052baec(param_1,_Size,_Src,param_4,param_5,param_6,param_7,param_10,
                           (undefined4 *)0x0,&local_38);
      if (local_38 == 0) {
        return uVar6;
      }
    }
  }
LAB_c052c330:
  LeaveCriticalSection(local_30);
  return uVar6;
}



/* c052c5b8 FUN_c052c5b8 */

/* Boundary evidence: original MIPS .pdata c052c5b8..c052c6af. Semantic name remains unreviewed. */

int * FUN_c052c5b8(int *param_1,void *param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *_Dst;
  uint _Size;
  
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
    iVar2 = 0;
  }
  else {
    iVar1 = param_1[1];
    iVar2 = param_1[2];
  }
  _Dst = (void *)(iVar1 + *param_4);
  uVar3 = iVar2 - *param_4;
  while( true ) {
    _Size = param_3;
    if (uVar3 <= param_3) {
      _Size = uVar3;
    }
    memcpy(_Dst,param_2,_Size);
    _Dst = (void *)(_Size + (int)_Dst);
    param_3 = param_3 - _Size;
    param_2 = (void *)(_Size + (int)param_2);
    if (param_3 == 0) break;
    uVar3 = uVar3 - _Size;
    if (uVar3 == 0) {
      param_1 = (int *)*param_1;
      if (param_1 == (int *)0x0) {
        _Dst = (void *)0x0;
        uVar3 = 0;
      }
      else {
        _Dst = (void *)param_1[1];
        uVar3 = param_1[2];
      }
    }
  }
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = param_1[1];
  }
  *param_4 = (int)_Dst - iVar1;
  return param_1;
}



/* c052c6b0 FUN_c052c6b0 */

/* Boundary evidence: original MIPS .pdata c052c6b0..c052c70f. Semantic name remains unreviewed. */

undefined * FUN_c052c6b0(void)

{
  if ((DAT_c052e440 & 1) == 0) {
    DAT_c052e440 = DAT_c052e440 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c052e42c);
    FUN_c052cbec(FUN_c052cfbc);
  }
  return &DAT_c052e42c;
}



/* c052c710 FUN_c052c710 */

/* Boundary evidence: original MIPS .pdata c052c710..c052c72b. Semantic name remains unreviewed. */

void FUN_c052c710(size_t param_1)

{
  malloc(param_1);
  return;
}



/* c052c72c FUN_c052c72c */

/* Boundary evidence: original MIPS .pdata c052c72c..c052c747. Semantic name remains unreviewed. */

void FUN_c052c72c(void *param_1,size_t param_2)

{
  realloc(param_1,param_2);
  return;
}



/* c052c748 FUN_c052c748 */

/* Boundary evidence: original MIPS .pdata c052c748..c052c763. Semantic name remains unreviewed. */

void FUN_c052c748(void *param_1)

{
  free(param_1);
  return;
}



/* c052c764 FUN_c052c764 */

undefined4 FUN_c052c764(void)

{
  return 0x78;
}



/* c052c76c FUN_c052c76c */

undefined4 FUN_c052c76c(void)

{
  return 0;
}



/* c052c77c entry */

/* Boundary evidence: original MIPS .pdata c052c77c..c052c7ef. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c052c7f0();
    FUN_c052cdb4();
  }
  uVar1 = DllEntry(param_1,param_2);
  if (param_2 == 0) {
    FUN_c052cd3c();
  }
  return uVar1;
}



/* c052c7f0 FUN_c052c7f0 */

/* Boundary evidence: original MIPS .pdata c052c7f0..c052c863. Semantic name remains unreviewed. */

void FUN_c052c7f0(void)

{
  uint uVar1;
  
  if ((DAT_c052e2d8 == 0) || (DAT_c052e2d8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c052e2d8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c052e2d8 == 0) {
      DAT_c052e2d8 = 0xb064;
    }
  }
  DAT_c052e2dc = ~DAT_c052e2d8;
  return;
}



/* c052c864 FUN_c052c864 */

/* Boundary evidence: original MIPS .pdata c052c864..c052c8b7. Semantic name remains unreviewed. */

void FUN_c052c864(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c052c8e4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c052c8b8 FUN_c052c8b8 */

/* Boundary evidence: original MIPS .pdata c052c8b8..c052c8e3. Semantic name remains unreviewed. */

undefined4 FUN_c052c8b8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c052c864(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c052c8e4 FUN_c052c8e4 */

/* Boundary evidence: original MIPS .pdata c052c8e4..c052c92b. Semantic name remains unreviewed. */

void FUN_c052c8e4(uint param_1)

{
  if ((param_1 == DAT_c052e2d8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c052c92c FUN_c052c92c */

/* Boundary evidence: original MIPS .pdata c052c92c..c052c9a7. Semantic name remains unreviewed. */

void FUN_c052c92c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c052c864(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c052c9a8 FUN_c052c9a8 */

/* Boundary evidence: original MIPS .pdata c052c9a8..c052cab3. Semantic name remains unreviewed. */

undefined4 FUN_c052c9a8(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c052eb64;
  puVar3 = DAT_c052eb60;
  iVar4 = (int)DAT_c052eb60 - (int)DAT_c052eb64;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c052c9ec:
    param_1 = 0;
  }
  else {
    if (DAT_c052eb64 != (void *)0x0) {
      uVar1 = _msize(DAT_c052eb64);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c052ca60:
        if (pvVar2 == (void *)0x0) goto LAB_c052c9ec;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c052ca60;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c052eb60 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c052eb64 = pvVar2;
  }
  return param_1;
}



/* c052cab4 FUN_c052cab4 */

/* Boundary evidence: original MIPS .pdata c052cab4..c052cb9f. Semantic name remains unreviewed. */

undefined4 FUN_c052cab4(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c052eb68 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c052eb68,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c052eb68 == (LPCRITICAL_SECTION)0x0) goto LAB_c052cb58;
  }
  EnterCriticalSection(DAT_c052eb68);
LAB_c052cb58:
  uVar2 = FUN_c052c9a8(param_1);
  FUN_c052cba0();
  return uVar2;
}



/* c052cba0 FUN_c052cba0 */

/* Boundary evidence: original MIPS .pdata c052cba0..c052cbeb. Semantic name remains unreviewed. */

void FUN_c052cba0(void)

{
  if (DAT_c052eb68 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c052eb68);
  }
  return;
}



/* c052cbec FUN_c052cbec */

/* Boundary evidence: original MIPS .pdata c052cbec..c052cc1b. Semantic name remains unreviewed. */

undefined4 FUN_c052cbec(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c052cab4(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c052cc1c FUN_c052cc1c */

/* Boundary evidence: original MIPS .pdata c052cc1c..c052cd3b. Semantic name remains unreviewed. */

void FUN_c052cc1c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c052e450 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c052eb64;
    if (DAT_c052eb64 != (undefined4 *)0x0) {
      while (DAT_c052eb60 = DAT_c052eb60 + -1, _Memory <= DAT_c052eb60) {
        if ((code *)*DAT_c052eb60 != (code *)0x0) {
          (*(code *)*DAT_c052eb60)();
          _Memory = DAT_c052eb64;
        }
      }
      free(_Memory);
      DAT_c052eb60 = (undefined4 *)0x0;
      DAT_c052eb64 = (undefined4 *)0x0;
    }
    FUN_c052cd60((undefined4 *)&DAT_c0511014,(undefined4 *)&DAT_c0511018);
  }
  FUN_c052cd60((undefined4 *)&DAT_c051101c,(undefined4 *)&DAT_c0511020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c052eb68,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c052cd3c FUN_c052cd3c */

/* Boundary evidence: original MIPS .pdata c052cd3c..c052cd5f. Semantic name remains unreviewed. */

void FUN_c052cd3c(void)

{
  FUN_c052cc1c(0,0,1);
  return;
}



/* c052cd60 FUN_c052cd60 */

/* Boundary evidence: original MIPS .pdata c052cd60..c052cdb3. Semantic name remains unreviewed. */

void FUN_c052cd60(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c052cdb4 FUN_c052cdb4 */

/* Boundary evidence: original MIPS .pdata c052cdb4..c052cdef. Semantic name remains unreviewed. */

void FUN_c052cdb4(void)

{
  FUN_c052cd60((undefined4 *)&DAT_c051100c,(undefined4 *)&DAT_c0511010);
  FUN_c052cd60((undefined4 *)&DAT_c0511000,(undefined4 *)&DAT_c0511008);
  return;
}



/* c052cfa0 FUN_c052cfa0 */

/* Boundary evidence: original MIPS .pdata c052cfa0..c052cfbb. Semantic name remains unreviewed. */

void FUN_c052cfa0(void)

{
  FUN_c052c6b0();
  return;
}



/* c052cfbc FUN_c052cfbc */

/* Boundary evidence: original MIPS .pdata c052cfbc..c052cfdb. Semantic name remains unreviewed. */

void FUN_c052cfbc(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c052e42c);
  return;
}


