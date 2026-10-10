/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c02f122c FUN_c02f122c */

/* Boundary evidence: original MIPS .pdata c02f122c..c02f128b. Semantic name remains unreviewed. */

PHKEY FUN_c02f122c(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

{
  LSTATUS LVar1;
  
  *param_1 = (HKEY)0x0;
  if (param_3 != (LPCWSTR)0x0) {
    LVar1 = RegOpenKeyExW(param_2,param_3,0,0,param_1);
    if (LVar1 != 0) {
      *param_1 = (HKEY)0x0;
    }
  }
  return param_1;
}



/* c02f128c FUN_c02f128c */

/* Boundary evidence: original MIPS .pdata c02f128c..c02f1303. Semantic name remains unreviewed. */

bool FUN_c02f128c(undefined4 *param_1,LPWSTR param_2,LPDWORD param_3,LPDWORD param_4,LPDWORD param_5
                 ,LPDWORD param_6,LPDWORD param_7,LPDWORD param_8,LPDWORD param_9,LPDWORD param_10,
                 LPDWORD param_11,PFILETIME param_12)

{
  LSTATUS LVar1;
  
  LVar1 = RegQueryInfoKeyW((HKEY)*param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                           param_9,param_10,param_11,param_12);
  return LVar1 == 0;
}



/* c02f1304 FUN_c02f1304 */

/* Boundary evidence: original MIPS .pdata c02f1304..c02f1357. Semantic name remains unreviewed. */

void FUN_c02f1304(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  if (*(int *)(param_1 + 0x28) != 0) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



/* c02f1358 FUN_c02f1358 */

/* Boundary evidence: original MIPS .pdata c02f1358..c02f14cf. Semantic name remains unreviewed. */

undefined4 * FUN_c02f1358(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  wchar_t *_Dest;
  uint uVar5;
  uint uVar6;
  undefined4 local_650 [6];
  wchar_t awStack_638 [520];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c02f50d8;
  FUN_c02f2a20(param_1,param_2);
  *param_1 = &PTR_FUN_c02f103c;
  param_1[0xc] = 0;
  if (param_2 != 0) {
    uVar1 = OpenDeviceKey(param_2);
    param_1[0xc] = uVar1;
  }
  param_1[0xe] = 0;
  param_1[0xb] = 0;
  iVar2 = GetDeviceHandleFromContext(param_2);
  if (iVar2 != 0) {
    memset(local_650,0,0x630);
    local_650[0] = 0x630;
    iVar2 = GetDeviceInformationByDeviceHandle(iVar2,local_650);
    if (iVar2 != 0) {
      sVar3 = wcslen(awStack_638);
      uVar6 = 0xffffffff;
      uVar5 = (sVar3 + 1) * 2;
      if (0x7fffffff < sVar3 + 1) {
        uVar5 = uVar6;
      }
      pwVar4 = operator_new(uVar5);
      param_1[0xb] = pwVar4;
      if (pwVar4 != (wchar_t *)0x0) {
        wcscpy(pwVar4,awStack_638);
      }
      pwVar4 = wcschr(awStack_228,L'\\');
      if ((pwVar4 != (wchar_t *)0x0) && (pwVar4 = pwVar4 + 1, *pwVar4 != L'\0')) {
        sVar3 = wcslen(pwVar4);
        if (sVar3 + 1 < 0x80000000) {
          uVar6 = (sVar3 + 1) * 2;
        }
        _Dest = operator_new(uVar6);
        param_1[0xe] = _Dest;
        if (_Dest != (wchar_t *)0x0) {
          wcscpy(_Dest,pwVar4);
        }
      }
    }
  }
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  FUN_c02f3af0(local_20);
  return param_1;
}



/* c02f14d0 FUN_c02f14d0 */

/* Boundary evidence: original MIPS .pdata c02f14d0..c02f150b. Semantic name remains unreviewed. */

void FUN_c02f14d0(int *param_1)

{
  (**(code **)(*param_1 + 0x58))();
  return;
}



/* c02f1514 FUN_c02f1514 */

/* Boundary evidence: original MIPS .pdata c02f1514..c02f159b. Semantic name remains unreviewed. */

void FUN_c02f1514(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c02f103c;
  if ((void *)param_1[0x11] != (void *)0x0) {
    operator_delete((void *)param_1[0x11]);
  }
  if ((void *)param_1[0xe] != (void *)0x0) {
    operator_delete((void *)param_1[0xe]);
  }
  if ((void *)param_1[0xb] != (void *)0x0) {
    operator_delete((void *)param_1[0xb]);
  }
  if ((HKEY)param_1[0xc] != (HKEY)0x0) {
    RegCloseKey((HKEY)param_1[0xc]);
  }
  FUN_c02f2ab8(param_1);
  return;
}



/* c02f159c FUN_c02f159c */

/* Boundary evidence: original MIPS .pdata c02f159c..c02f1813. Semantic name remains unreviewed. */

undefined4 FUN_c02f159c(int *param_1)

{
  short sVar1;
  LSTATUS LVar2;
  LPBYTE lpData;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  DWORD local_28;
  DWORD local_24;
  DWORD local_20 [2];
  
  if (param_1[0xb] != 0) {
    if (((HKEY)param_1[0xc] != (HKEY)0x0) && (param_1[0x11] == 0)) {
      local_28 = 0;
      LVar2 = RegQueryValueExW((HKEY)param_1[0xc],L"RegenumParms",(LPDWORD)0x0,&local_24,(LPBYTE)0x0
                               ,&local_28);
      if (((LVar2 == 0) || (LVar2 == 0xea)) && ((local_24 == 7 && (local_28 != 0)))) {
        local_28 = local_28 + 1 >> 1;
        uVar5 = local_28 << 1;
        if (0x7fffffff < local_28) {
          uVar5 = 0xffffffff;
        }
        lpData = operator_new(uVar5);
        param_1[0x11] = (int)lpData;
        if (lpData != (LPBYTE)0x0) {
          local_20[0] = local_28 << 1;
          local_20[1] = 0;
          LVar2 = RegQueryValueExW((HKEY)param_1[0xc],L"RegenumParms",(LPDWORD)0x0,local_20 + 1,
                                   lpData,local_20);
          if (LVar2 == 0) {
            uVar4 = param_1[0x12];
            uVar5 = local_28;
            for (psVar6 = (short *)param_1[0x11]; ((uVar4 < 0x20 && (uVar5 != 0)) && (*psVar6 != 0))
                ; psVar6 = psVar6 + 1) {
              param_1[param_1[0x12] + 0x13] = (int)psVar6;
              sVar1 = *psVar6;
              while (sVar1 != 0) {
                if (uVar5 == 0) goto LAB_c02f1738;
                psVar6 = psVar6 + 1;
                uVar5 = uVar5 - 1;
                sVar1 = *psVar6;
              }
              if (uVar5 == 0) break;
              uVar4 = param_1[0x12] + 1;
              param_1[0x12] = uVar4;
              uVar5 = uVar5 - 1;
            }
          }
        }
      }
    }
LAB_c02f1738:
    if ((param_1[8] != 0) && ((HKEY)param_1[0xc] != (HKEY)0x0)) {
      local_20[1] = 4;
      local_20[0] = 0;
      LVar2 = RegQueryValueExW((HKEY)param_1[0xc],L"InterfaceType",(LPDWORD)0x0,local_20,
                               (LPBYTE)(param_1 + 0xd),local_20 + 1);
      if (LVar2 != 0) {
        param_1[0xd] = -1;
      }
      local_20[1] = 4;
      local_20[0] = 0;
      LVar2 = RegQueryValueExW((HKEY)param_1[0xc],L"BusNumber",(LPDWORD)0x0,local_20,
                               (LPBYTE)(param_1 + 0xf),local_20 + 1);
      if (LVar2 != 0) {
        param_1[0xf] = 0;
      }
      iVar3 = (**(code **)(*param_1 + 0x5c))(param_1);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  return 0;
}



/* c02f1814 FUN_c02f1814 */

/* Boundary evidence: original MIPS .pdata c02f1814..c02f184f. Semantic name remains unreviewed. */

undefined4 FUN_c02f1814(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1[8] != 0) && (param_1[0xc] != 0)) {
    uVar1 = (**(code **)(*param_1 + 0x60))();
  }
  return uVar1;
}



/* c02f1850 FUN_c02f1850 */

/* Boundary evidence: original MIPS .pdata c02f1850..c02f1b5f. Semantic name remains unreviewed. */

undefined4 FUN_c02f1850(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  LSTATUS LVar3;
  int iVar4;
  size_t sVar5;
  undefined4 *puVar6;
  wchar_t *pwVar7;
  DWORD dwIndex;
  int *piVar8;
  int local_498;
  HKEY local_494;
  uint local_490;
  DWORD local_48c [4];
  DWORD DStack_47c;
  DWORD DStack_478;
  DWORD DStack_474;
  DWORD aDStack_470 [2];
  undefined4 local_468;
  int local_464;
  int local_460;
  wchar_t awStack_430 [254];
  undefined2 local_234;
  undefined2 local_232;
  WCHAR aWStack_230 [256];
  uint local_30;
  
  local_30 = DAT_c02f50d8;
  piVar8 = param_1 + 0xc;
  bVar1 = FUN_c02f128c(piVar8,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_490,&DStack_47c,
                       &DStack_474,aDStack_470,&DStack_478,local_48c + 3,(LPDWORD)0x0,(PFILETIME)0x0
                      );
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_c02f3af0(local_30);
    uVar2 = 0;
  }
  else {
    dwIndex = 0;
    if (local_490 != 0) {
      do {
        local_48c[1] = 0x100;
        LVar3 = RegEnumKeyExW((HKEY)*piVar8,dwIndex,aWStack_230,local_48c + 1,(LPDWORD)0x0,
                              (LPWSTR)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
        if (LVar3 != 0) break;
        FUN_c02f122c(&local_494,(HKEY)*piVar8,aWStack_230);
        if (local_494 != (HKEY)0x0) {
          local_464 = -1;
          local_460 = -1;
          local_468 = 0x34;
          iVar4 = DDKReg_GetPciInfo(local_494,&local_468);
          if (((iVar4 != 0) || (local_464 == -1)) || (local_460 == -1)) {
            local_464 = param_1[0x10];
            param_1[0x10] = local_464 + 1;
            local_460 = 0;
          }
          local_498 = -1;
          local_48c[0] = 4;
          local_48c[2] = 0;
          LVar3 = RegQueryValueExW(local_494,L"BusNumber",(LPDWORD)0x0,local_48c + 2,
                                   (LPBYTE)&local_498,local_48c);
          if ((LVar3 != 0) || (local_498 == -1)) {
            local_498 = param_1[0xf];
          }
          wcsncpy(awStack_430,(wchar_t *)param_1[0xb],0xff);
          local_234 = 0;
          sVar5 = wcslen(awStack_430);
          awStack_430[sVar5] = L'\\';
          awStack_430[sVar5 + 1] = L'\0';
          wcsncat(awStack_430,aWStack_230,0xff - (sVar5 + 1));
          local_232 = 0;
          puVar6 = operator_new(0x60);
          if (puVar6 == (undefined4 *)0x0) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            pwVar7 = (wchar_t *)param_1[0xe];
            if ((wchar_t *)param_1[0xe] == (wchar_t *)0x0) {
              pwVar7 = L"UnknownBus";
            }
            puVar6 = FUN_c02f21e8(puVar6,pwVar7,awStack_430,param_1[0xd],local_498,local_464,
                                  local_460,param_1[8],8,(wchar_t *)0x0);
          }
          if (puVar6 != (undefined4 *)0x0) {
            (**(code **)(*param_1 + 0x44))(param_1,puVar6);
          }
          if (local_494 != (HKEY)0x0) {
            RegCloseKey(local_494);
          }
        }
        dwIndex = dwIndex + 1;
      } while (dwIndex < local_490);
    }
    FUN_c02f3af0(local_30);
    uVar2 = 1;
  }
  return uVar2;
}



/* c02f1b60 FUN_c02f1b60 */

/* Boundary evidence: original MIPS .pdata c02f1b60..c02f1c03. Semantic name remains unreviewed. */

size_t FUN_c02f1b60(int param_1,wchar_t *param_2,size_t param_3)

{
  size_t sVar1;
  wchar_t *_Str;
  
  _Str = *(wchar_t **)(param_1 + 0x38);
  if (((_Str == (wchar_t *)0x0) || (param_2 == (wchar_t *)0x0)) || (param_3 == 0)) {
    param_3 = FUN_c02f2ed4(param_1,param_2,param_3);
  }
  else {
    sVar1 = wcslen(_Str);
    if (sVar1 + 1 < param_3) {
      sVar1 = wcslen(_Str);
      param_3 = sVar1 + 1;
    }
    wcsncpy(param_2,_Str,param_3);
    param_2[param_3 - 1] = L'\0';
  }
  return param_3;
}



/* c02f1c04 FUN_c02f1c04 */

/* Boundary evidence: original MIPS .pdata c02f1c04..c02f1d9b. Semantic name remains unreviewed. */

undefined4 FUN_c02f1c04(int param_1)

{
  LSTATUS LVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  DWORD local_238;
  DWORD local_234;
  int local_230;
  BYTE *local_22c;
  DWORD local_228;
  DWORD local_224;
  BYTE aBStack_220 [512];
  uint local_20;
  
  local_20 = DAT_c02f50d8;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  for (iVar3 = *(int *)(param_1 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x5c)) {
    uVar6 = 0;
    if (*(int *)(param_1 + 0x48) != 0) {
      piVar4 = (int *)(param_1 + 0x4c);
      do {
        local_238 = 0x200;
        if ((*(HKEY *)(param_1 + 0x30) != (HKEY)0x0) &&
           (LVar1 = RegQueryValueExW(*(HKEY *)(param_1 + 0x30),(LPCWSTR)*piVar4,(LPDWORD)0x0,
                                     &local_234,aBStack_220,&local_238), LVar1 == 0)) {
          local_230 = *piVar4;
          local_22c = aBStack_220;
          local_224 = local_234;
          local_228 = local_238;
          FUN_c02f2540(iVar3,1,&local_230);
        }
        uVar6 = uVar6 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x48));
    }
  }
  uVar6 = 0;
  do {
    uVar5 = 0xffffffff;
    for (piVar4 = *(int **)(param_1 + 0x1c); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x17]) {
      uVar2 = piVar4[0xf];
      if (uVar2 == uVar6) {
        (**(code **)(*piVar4 + 8))(piVar4);
      }
      else if ((uVar6 < uVar2) && (uVar2 < uVar5)) {
        uVar5 = uVar2;
      }
    }
    uVar6 = uVar5;
  } while (uVar5 != 0xffffffff);
  FUN_c02f1304(param_1);
  FUN_c02f3af0(local_20);
  return 1;
}



/* c02f1d9c FUN_c02f1d9c */

/* Boundary evidence: original MIPS .pdata c02f1d9c..c02f1dcf. Semantic name remains unreviewed. */

undefined4 FUN_c02f1d9c(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c02f1dd0 Init */

/* Boundary evidence: original MIPS .pdata c02f1dd0..c02f1e53. Semantic name remains unreviewed. */

int * Init(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
                    /* 0x1dd0  4  Init */
  puVar1 = operator_new(0xcc);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c02f1358(puVar1,param_1);
  }
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)*piVar2)(piVar2);
    if (iVar3 != 0) {
      return piVar2;
    }
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  return (int *)0x0;
}



/* c02f1e54 Deinit */

/* Boundary evidence: original MIPS .pdata c02f1e54..c02f1e7f. Semantic name remains unreviewed. */

void Deinit(int *param_1)

{
                    /* 0x1e54  2  Deinit */
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1,1);
  }
  return;
}



/* c02f1e80 PowerUp */

/* Boundary evidence: original MIPS .pdata c02f1e80..c02f1eaf. Semantic name remains unreviewed. */

undefined4 PowerUp(int *param_1)

{
                    /* 0x1e80  7  PowerUp */
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x2c))();
  }
  return 1;
}



/* c02f1eb0 PowerDown */

/* Boundary evidence: original MIPS .pdata c02f1eb0..c02f1edf. Semantic name remains unreviewed. */

undefined4 PowerDown(int *param_1)

{
                    /* 0x1eb0  6  PowerDown */
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x30))();
  }
  return 1;
}



/* c02f1ee0 Open */

/* Boundary evidence: original MIPS .pdata c02f1ee0..c02f1f27. Semantic name remains unreviewed. */

int * Open(int *param_1)

{
  int iVar1;
  
                    /* 0x1ee0  5  Open */
  if ((param_1 == (int *)0x0) || (iVar1 = (**(code **)(*param_1 + 0x34))(param_1), iVar1 == 0)) {
    param_1 = (int *)0x0;
  }
  return param_1;
}



/* c02f1f28 Close */

/* Boundary evidence: original MIPS .pdata c02f1f28..c02f1f5f. Semantic name remains unreviewed. */

undefined4 Close(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x1f28  1  Close */
  if (param_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x38))();
  }
  return uVar1;
}



/* c02f1f60 IOControl */

/* Boundary evidence: original MIPS .pdata c02f1f60..c02f1fab. Semantic name remains unreviewed. */

undefined4 IOControl(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x1f60  3  IOControl */
  if (param_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x3c))();
  }
  return uVar1;
}



/* c02f1fac FUN_c02f1fac */

/* Boundary evidence: original MIPS .pdata c02f1fac..c02f1ff7. Semantic name remains unreviewed. */

undefined4 * FUN_c02f1fac(undefined4 *param_1,uint param_2)

{
  FUN_c02f1514(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c02f1ff8 FUN_c02f1ff8 */

/* Boundary evidence: original MIPS .pdata c02f1ff8..c02f2053. Semantic name remains unreviewed. */

LONG FUN_c02f1ff8(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 < 1) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(param_1,1);
  }
  return LVar1;
}



/* c02f2054 FUN_c02f2054 */

/* Boundary evidence: original MIPS .pdata c02f2054..c02f2097. Semantic name remains unreviewed. */

undefined4 * FUN_c02f2054(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c02f1104;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c02f2098 FUN_c02f2098 */

/* Boundary evidence: original MIPS .pdata c02f2098..c02f210b. Semantic name remains unreviewed. */

void FUN_c02f2098(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  if (*(int *)(param_1 + 0x24) == 0) {
    HalTranslateBusAddress(param_2,param_3,param_5,param_6,param_7,param_8);
  }
  else {
    TranslateBusAddr(*(int *)(param_1 + 0x24),param_2,param_3,param_4,param_5,param_6,param_7,
                     param_8);
  }
  return;
}



/* c02f210c FUN_c02f210c */

/* Boundary evidence: original MIPS .pdata c02f210c..c02f2173. Semantic name remains unreviewed. */

void FUN_c02f210c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  if (*(int *)(param_1 + 0x24) == 0) {
    HalTranslateSystemAddress(param_2,param_3,param_5,param_6,param_7);
  }
  else {
    TranslateSystemAddr(*(int *)(param_1 + 0x24),param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}



/* c02f2174 FUN_c02f2174 */

/* Boundary evidence: original MIPS .pdata c02f2174..c02f21e7. Semantic name remains unreviewed. */

void FUN_c02f2174(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = *(int *)(param_1 + 0x28);
  while (iVar1 != 0) {
    LeaveCriticalSection(lpCriticalSection);
    Sleep(10);
    EnterCriticalSection(lpCriticalSection);
    iVar1 = *(int *)(param_1 + 0x28);
  }
  return;
}



/* c02f21e8 FUN_c02f21e8 */

/* Boundary evidence: original MIPS .pdata c02f21e8..c02f2513. Semantic name remains unreviewed. */

undefined4 *
FUN_c02f21e8(undefined4 *param_1,wchar_t *param_2,wchar_t *param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,
            wchar_t *param_10)

{
  void *_Dst;
  wchar_t *pwVar1;
  STRSAFE_LPWSTR pszDest;
  size_t sVar2;
  LSTATUS LVar3;
  uint uVar4;
  uint uVar5;
  PHKEY ppHVar6;
  DWORD local_30 [2];
  
  ppHVar6 = (PHKEY)(param_1 + 2);
  *param_1 = &PTR_FUN_c02f1104;
  param_1[1] = 0;
  FUN_c02f122c(ppHVar6,(HKEY)0x80000002,param_3);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  *param_1 = &PTR_FUN_c02f115c;
  param_1[0xc] = param_5;
  param_1[0xb] = param_4;
  param_1[0x16] = param_8;
  param_1[0xd] = param_6;
  uVar5 = 0xffffffff;
  param_1[0xe] = param_7;
  param_1[0x11] = param_9;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0x12] = 0;
  param_1[8] = 0;
  uVar4 = (param_9 + 3U) * 0x10;
  if (0xfffffff < param_9 + 3U) {
    uVar4 = uVar5;
  }
  _Dst = operator_new(uVar4);
  param_1[0x13] = _Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,(param_1[0x11] + 3) * 0x10);
    *(wchar_t **)param_1[0x13] = L"BusParent";
    *(undefined4 *)(param_1[0x13] + 0xc) = 4;
    *(undefined4 **)(param_1[0x13] + 4) = param_1 + 0x16;
    *(undefined4 *)(param_1[0x13] + 8) = 4;
    *(wchar_t **)(param_1[0x13] + 0x10) = L"InterfaceType";
    *(undefined4 *)(param_1[0x13] + 0x1c) = 4;
    *(undefined4 **)(param_1[0x13] + 0x14) = param_1 + 0xb;
    *(undefined4 *)(param_1[0x13] + 0x18) = 4;
  }
  param_1[0x14] = 0;
  if (param_10 == (wchar_t *)0x0) {
    if (param_2 != (wchar_t *)0x0) {
      sVar2 = wcslen(param_2);
      pszDest = malloc((sVar2 + 0x2a) * 2);
      param_1[0x14] = pszDest;
      if (pszDest != (STRSAFE_LPWSTR)0x0) {
        StringCchPrintfW(pszDest,sVar2 + 0x2a,L"%s_%d_%d_%d",param_2,param_1[0xc],param_1[0xd],
                         param_1[0xe]);
      }
    }
  }
  else {
    pwVar1 = _wcsdup(param_10);
    param_1[0x14] = pwVar1;
  }
  if ((param_1[0x14] != 0) && (param_1[0x13] != 0)) {
    *(wchar_t **)(param_1[0x13] + 0x20) = L"BusName";
    *(undefined4 *)(param_1[0x13] + 0x2c) = 1;
    *(undefined4 *)(param_1[0x13] + 0x24) = param_1[0x14];
    sVar2 = wcslen((wchar_t *)param_1[0x14]);
    *(size_t *)(param_1[0x13] + 0x28) = (sVar2 + 1) * 2;
  }
  param_1[0x15] = 0;
  if (param_3 != (wchar_t *)0x0) {
    sVar2 = wcslen(param_3);
    if (sVar2 + 1 < 0x80000000) {
      uVar5 = (sVar2 + 1) * 2;
    }
    pwVar1 = operator_new(uVar5);
    param_1[0x15] = pwVar1;
    if (pwVar1 != (wchar_t *)0x0) {
      wcscpy(pwVar1,param_3);
    }
  }
  param_1[0x12] = 3;
  if (*ppHVar6 != (HKEY)0x0) {
    local_30[0] = 4;
    local_30[1] = 0;
    LVar3 = RegQueryValueExW(*ppHVar6,L"Order",(LPDWORD)0x0,local_30 + 1,(LPBYTE)(param_1 + 0xf),
                             local_30);
    if (LVar3 == 0) goto LAB_c02f249c;
  }
  param_1[0xf] = 0xfffffffe;
LAB_c02f249c:
  if (*ppHVar6 != (HKEY)0x0) {
    local_30[1] = 4;
    local_30[0] = 0;
    LVar3 = RegQueryValueExW(*ppHVar6,L"Flags",(LPDWORD)0x0,local_30,(LPBYTE)(param_1 + 0x10),
                             local_30 + 1);
    if (LVar3 == 0) {
      return param_1;
    }
  }
  param_1[0x10] = 0;
  return param_1;
}



/* c02f2540 FUN_c02f2540 */

/* Boundary evidence: original MIPS .pdata c02f2540..c02f26e3. Semantic name remains unreviewed. */

undefined4 FUN_c02f2540(int param_1,int param_2,int *param_3)

{
  size_t sVar1;
  void *pvVar2;
  wchar_t *_Dest;
  int *piVar3;
  uint uVar4;
  size_t *psVar5;
  
  if (param_2 != 0) {
    if ((((param_3 != (int *)0x0) && (*param_3 != 0)) && (param_3[1] != 0)) &&
       (*(int *)(param_1 + 0x4c) != 0)) {
      psVar5 = (size_t *)(param_3 + 2);
      do {
        if ((psVar5 == (size_t *)0x8) ||
           (*(int *)(param_1 + 0x44) + 3U <= *(uint *)(param_1 + 0x48))) break;
        sVar1 = wcslen((wchar_t *)psVar5[-2]);
        uVar4 = (*psVar5 + 2 >> 1) + sVar1 + 1;
        if (uVar4 < 0x80000000) {
          uVar4 = uVar4 * 2;
        }
        else {
          uVar4 = 0xffffffff;
        }
        pvVar2 = operator_new(uVar4);
        *(void **)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c)) = pvVar2;
        _Dest = *(wchar_t **)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c));
        if (_Dest == (wchar_t *)0x0) break;
        wcscpy(_Dest,(wchar_t *)psVar5[-2]);
        piVar3 = (int *)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c));
        piVar3[1] = (sVar1 + 1) * 2 + *piVar3;
        memcpy(*(void **)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c) + 4),
               (void *)psVar5[-1],*psVar5);
        param_2 = param_2 + -1;
        *(size_t *)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c) + 0xc) = psVar5[1];
        sVar1 = *psVar5;
        psVar5 = psVar5 + 4;
        *(size_t *)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c) + 8) = sVar1;
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
      } while (param_2 != 0);
    }
    if (param_2 != 0) {
      return 0;
    }
  }
  return 1;
}



/* c02f26e4 FUN_c02f26e4 */

/* Boundary evidence: original MIPS .pdata c02f26e4..c02f28eb. Semantic name remains unreviewed. */

undefined4 FUN_c02f26e4(int param_1)

{
  LSTATUS LVar1;
  HMODULE hLibModule;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  DWORD local_120 [2];
  WCHAR aWStack_118 [64];
  BYTE aBStack_98 [128];
  uint local_18;
  
  local_18 = DAT_c02f50d8;
  if (*(int *)(param_1 + 0x24) == 0) {
    if ((((*(int *)(param_1 + 0x28) == 0) && (*(int *)(param_1 + 0x54) != 0)) &&
        (*(int *)(param_1 + 0x50) != 0)) && (*(int *)(param_1 + 0x4c) != 0)) {
      GetTickCount();
      if (*(HKEY *)(param_1 + 8) == (HKEY)0x0) {
LAB_c02f2760:
        FUN_c02f3af0(local_18);
        return 0;
      }
      local_120[1] = 0x80;
      local_120[0] = 0;
      LVar1 = RegQueryValueExW(*(HKEY *)(param_1 + 8),L"Entry",(LPDWORD)0x0,local_120,aBStack_98,
                               local_120 + 1);
      if (LVar1 == 0) {
        local_120[0] = 0x80;
        local_120[1] = 0;
        LVar1 = RegQueryValueExW(*(HKEY *)(param_1 + 8),L"Dll",(LPDWORD)0x0,local_120 + 1,
                                 (LPBYTE)aWStack_118,local_120);
        if ((LVar1 == 0) && ((*(uint *)(param_1 + 0x40) & 4) == 0)) {
          if ((*(uint *)(param_1 + 0x40) & 2) == 0) {
            hLibModule = (HMODULE)LoadDriver();
          }
          else {
            hLibModule = LoadLibraryW(aWStack_118);
          }
          if (hLibModule != (HMODULE)0x0) {
            pcVar2 = (code *)GetProcAddressW(hLibModule,aBStack_98);
            if (pcVar2 != (code *)0x0) {
              (*pcVar2)(*(undefined4 *)(param_1 + 0x54));
              uVar4 = 1;
              *(undefined4 *)(param_1 + 0x28) = 1;
              goto LAB_c02f28b8;
            }
            FreeLibrary(hLibModule);
          }
        }
        goto LAB_c02f2760;
      }
      if (*(int *)(param_1 + 0x4c) == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(param_1 + 0x48);
      }
      iVar3 = ActivateDeviceEx(*(undefined4 *)(param_1 + 0x54),*(int *)(param_1 + 0x4c),uVar4,0);
      uVar4 = 1;
      *(int *)(param_1 + 0x24) = iVar3;
      *(uint *)(param_1 + 0x28) = (uint)(iVar3 != 0);
      if (iVar3 != 0) goto LAB_c02f28b8;
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
LAB_c02f28b8:
  FUN_c02f3af0(local_18);
  return uVar4;
}



/* c02f28ec FUN_c02f28ec */

/* Boundary evidence: original MIPS .pdata c02f28ec..c02f292f. Semantic name remains unreviewed. */

int FUN_c02f28ec(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  if ((*(int *)(param_1 + 0x24) != 0) && (iVar1 = DeactivateDevice(), iVar1 != 0)) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return iVar1;
}



/* c02f2930 FUN_c02f2930 */

/* Boundary evidence: original MIPS .pdata c02f2930..c02f29a7. Semantic name remains unreviewed. */

undefined4 FUN_c02f2930(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 4) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = HalSetBusDataByOffset
                      (4,*(undefined4 *)(param_1 + 0x30),
                       (*(uint *)(param_1 + 0x38) & 7) << 5 | *(uint *)(param_1 + 0x34) & 0x1f,
                       *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 8),
                       *(undefined4 *)(param_2 + 0xc));
    *(undefined4 *)(param_2 + 0xc) = uVar1;
    uVar1 = 1;
  }
  return uVar1;
}



/* c02f29a8 FUN_c02f29a8 */

/* Boundary evidence: original MIPS .pdata c02f29a8..c02f2a1f. Semantic name remains unreviewed. */

undefined4 FUN_c02f29a8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 4) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = HalGetBusDataByOffset
                      (4,*(undefined4 *)(param_1 + 0x30),
                       (*(uint *)(param_1 + 0x38) & 7) << 5 | *(uint *)(param_1 + 0x34) & 0x1f,
                       *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 8),
                       *(undefined4 *)(param_2 + 0xc));
    *(undefined4 *)(param_2 + 0xc) = uVar1;
    uVar1 = 1;
  }
  return uVar1;
}



/* c02f2a20 FUN_c02f2a20 */

/* Boundary evidence: original MIPS .pdata c02f2a20..c02f2a8b. Semantic name remains unreviewed. */

undefined4 * FUN_c02f2a20(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  *param_1 = &PTR_LAB_c02f1190;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  uVar1 = CreateBusAccessHandle(param_2);
  param_1[9] = uVar1;
  uVar1 = GetDeviceHandleFromContext(param_2);
  param_1[8] = uVar1;
  return param_1;
}



/* c02f2ab8 FUN_c02f2ab8 */

/* Boundary evidence: original MIPS .pdata c02f2ab8..c02f2b53. Semantic name remains unreviewed. */

void FUN_c02f2ab8(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_LAB_c02f1190;
  FUN_c02f2174((int)param_1);
  while (param_1[7] != 0) {
    puVar1 = (undefined4 *)param_1[7];
    uVar2 = puVar1[0x17];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    param_1[7] = uVar2;
  }
  if (param_1[9] != 0) {
    CloseBusAccessHandle();
    param_1[9] = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return;
}



/* c02f2b54 FUN_c02f2b54 */

/* Boundary evidence: original MIPS .pdata c02f2b54..c02f2ba7. Semantic name remains unreviewed. */

undefined4 FUN_c02f2b54(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c02f2098(param_1,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),param_4,
                         *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                         *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c));
  }
  return uVar1;
}



/* c02f2ba8 FUN_c02f2ba8 */

/* Boundary evidence: original MIPS .pdata c02f2ba8..c02f2bf3. Semantic name remains unreviewed. */

undefined4 FUN_c02f2ba8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c02f210c(param_1,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),param_4,
                         *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                         *(undefined4 *)(param_2 + 0x18));
  }
  return uVar1;
}



/* c02f2bf4 FUN_c02f2bf4 */

/* Boundary evidence: original MIPS .pdata c02f2bf4..c02f2c6b. Semantic name remains unreviewed. */

undefined4 FUN_c02f2bf4(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 != (undefined4 *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 0x40))(param_1,*param_2), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,param_2);
    FUN_c02f1ff8(piVar1);
  }
  return uVar2;
}



/* c02f2c6c FUN_c02f2c6c */

/* Boundary evidence: original MIPS .pdata c02f2c6c..c02f2ce3. Semantic name remains unreviewed. */

undefined4 FUN_c02f2c6c(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 != (undefined4 *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 0x40))(param_1,*param_2), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_2);
    FUN_c02f1ff8(piVar1);
  }
  return uVar2;
}



/* c02f2ce4 FUN_c02f2ce4 */

/* Boundary evidence: original MIPS .pdata c02f2ce4..c02f2d77. Semantic name remains unreviewed. */

undefined4 FUN_c02f2ce4(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((((param_2 != (int *)0x0) && (*param_2 != 0)) && (param_2[1] != 0)) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 0x40))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,*(undefined4 *)param_2[1]);
    FUN_c02f1ff8(piVar1);
  }
  return uVar2;
}



/* c02f2d78 FUN_c02f2d78 */

/* Boundary evidence: original MIPS .pdata c02f2d78..c02f2e0b. Semantic name remains unreviewed. */

undefined4 FUN_c02f2d78(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((((param_2 != (int *)0x0) && (*param_2 != 0)) && (param_2[1] != 0)) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 0x40))(), piVar1 != (int *)0x0)) {
    uVar3 = 1;
    uVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
    *(undefined4 *)param_2[1] = uVar2;
    FUN_c02f1ff8(piVar1);
  }
  return uVar3;
}



/* c02f2e0c FUN_c02f2e0c */

/* Boundary evidence: original MIPS .pdata c02f2e0c..c02f2e6f. Semantic name remains unreviewed. */

undefined4 FUN_c02f2e0c(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)(**(code **)(*param_1 + 0x40))(param_1,param_2,0);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 8))(piVar1);
    FUN_c02f1ff8(piVar1);
  }
  return uVar2;
}



/* c02f2e70 FUN_c02f2e70 */

/* Boundary evidence: original MIPS .pdata c02f2e70..c02f2ed3. Semantic name remains unreviewed. */

undefined4 FUN_c02f2e70(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)(**(code **)(*param_1 + 0x40))(param_1,param_2,0);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1);
    FUN_c02f1ff8(piVar1);
  }
  return uVar2;
}



/* c02f2ed4 FUN_c02f2ed4 */

/* Boundary evidence: original MIPS .pdata c02f2ed4..c02f2f47. Semantic name remains unreviewed. */

size_t FUN_c02f2ed4(undefined4 param_1,wchar_t *param_2,uint param_3)

{
  if (7 < param_3) {
    param_3 = 8;
  }
  if ((param_2 == (wchar_t *)0x0) || (param_3 == 0)) {
    param_3 = 0;
  }
  else {
    wcsncpy(param_2,L"UNKNOWN",param_3);
    param_2[param_3 - 1] = L'\0';
  }
  return param_3;
}



/* c02f2f48 FUN_c02f2f48 */

/* Boundary evidence: original MIPS .pdata c02f2f48..c02f3387. Semantic name remains unreviewed. */

int FUN_c02f2f48(int *param_1,uint param_2,wchar_t *param_3,uint param_4,uint *param_5,uint param_6,
                int *param_7,undefined4 param_8)

{
  int iVar1;
  size_t sVar2;
  code *pcVar3;
  wchar_t *local_40;
  uint *local_3c;
  uint local_38;
  uint local_34;
  uint *local_30;
  uint local_2c;
  uint *local_28;
  uint *local_24;
  
  if (0x2a0018 < param_2) {
    if ((param_2 == 0x2a0040) || (param_2 == 0x2a0044)) {
      if ((param_3 != (wchar_t *)0x0) && (sVar2 = wcslen(param_3), (sVar2 + 1) * 2 <= param_4)) {
        if (param_2 == 0x2a0040) {
          pcVar3 = *(code **)(*param_1 + 0x24);
        }
        else {
          pcVar3 = *(code **)(*param_1 + 0x28);
        }
        iVar1 = (*pcVar3)(param_1,param_3);
        return iVar1;
      }
    }
    else {
      if (param_2 == 0x2a0048) {
        iVar1 = (**(code **)(*param_1 + 4))(param_1);
        return iVar1;
      }
      if (param_2 == 0x2a0080) {
        if ((((param_3 != (wchar_t *)0x0) && (sVar2 = wcslen(param_3), (sVar2 + 1) * 2 <= param_4))
            && (param_5 != (uint *)0x0)) && (3 < param_6)) {
          iVar1 = (**(code **)(*param_1 + 0x50))(param_1,param_3);
          *param_5 = (uint)(iVar1 != 0);
          if (param_7 == (int *)0x0) {
            return 1;
          }
          *param_7 = 4;
          return 1;
        }
      }
      else {
        if (param_2 != 0x2a0084) {
          return 0;
        }
        if ((param_5 != (uint *)0x0) && (1 < param_6)) {
          iVar1 = (**(code **)(*param_1 + 0x54))(param_1,param_5,param_6 >> 1);
          if (param_7 != (int *)0x0) {
            *param_7 = iVar1 << 1;
          }
          return 1;
        }
      }
    }
    goto LAB_c02f334c;
  }
  local_40 = param_3;
  if (param_2 == 0x2a0018) {
LAB_c02f2fe0:
    if (((param_3 == (wchar_t *)0x0) || (param_4 < 2)) &&
       ((param_5 == (uint *)0x0 || (param_6 < 0x10)))) {
LAB_c02f334c:
      SetLastError(0x57);
      return 0;
    }
    local_3c = (uint *)*param_5;
    local_38 = param_5[1];
    local_34 = param_5[2];
    local_30 = param_5 + 3;
    if (param_2 == 0x2a0014) {
      pcVar3 = *(code **)(*param_1 + 0x20);
    }
    else {
      pcVar3 = *(code **)(*param_1 + 0x1c);
    }
  }
  else {
    if (param_2 == 0x2a0004) {
      if (((param_3 != (wchar_t *)0x0) && (1 < param_4)) ||
         ((param_5 != (uint *)0x0 && (0x1f < param_6)))) {
        local_3c = (uint *)*param_5;
        local_38 = param_5[1];
        local_30 = (uint *)param_5[2];
        local_24 = param_5 + 6;
        local_2c = param_5[3];
        pcVar3 = *(code **)(*param_1 + 0xc);
LAB_c02f314c:
        local_28 = param_5 + 4;
        iVar1 = (*pcVar3)(param_1,&local_40);
        return iVar1;
      }
      goto LAB_c02f334c;
    }
    if (param_2 == 0x2a0008) {
      if (((param_3 != (wchar_t *)0x0) && (1 < param_4)) ||
         ((param_5 != (uint *)0x0 && (0x17 < param_6)))) {
        local_38 = param_5[1];
        local_3c = (uint *)*param_5;
        local_30 = (uint *)param_5[2];
        local_2c = param_5[3];
        pcVar3 = *(code **)(*param_1 + 0x10);
        goto LAB_c02f314c;
      }
      goto LAB_c02f334c;
    }
    if ((param_2 != 0x2a000c) && (param_2 != 0x2a0010)) {
      if (param_2 != 0x2a0014) {
        return 0;
      }
      goto LAB_c02f2fe0;
    }
    if (((param_3 == (wchar_t *)0x0) || (param_4 < 2)) &&
       ((param_5 == (uint *)0x0 || (param_6 < 8)))) goto LAB_c02f334c;
    local_38 = param_5[1];
    local_3c = param_5;
    if (param_2 == 0x2a000c) {
      pcVar3 = *(code **)(*param_1 + 0x18);
    }
    else {
      if (param_2 != 0x2a0010) goto LAB_c02f30e0;
      pcVar3 = *(code **)(*param_1 + 0x14);
    }
  }
  iVar1 = (*pcVar3)(param_1,&local_40,param_8);
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_c02f30e0:
  SetLastError(0x57);
  return 0;
}



/* c02f3388 FUN_c02f3388 */

/* Boundary evidence: original MIPS .pdata c02f3388..c02f34bb. Semantic name remains unreviewed. */

int FUN_c02f3388(int param_1,wchar_t *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  iVar1 = 0;
  if ((param_2 != (wchar_t *)0x0) && (iVar2 = *(int *)(param_1 + 0x1c), iVar2 != 0)) {
    if ((param_3 == (int *)0x0) || (*param_3 == 0)) {
      iVar1 = _wcsnicmp(param_2,L"$bus\\",5);
      if (iVar1 == 0) {
        param_2 = param_2 + 5;
      }
      iVar2 = *(int *)(param_1 + 0x1c);
      iVar1 = iVar2;
      if (iVar2 == 0) goto LAB_c02f3490;
      do {
        iVar1 = _wcsicmp(*(wchar_t **)(iVar2 + 0x50),param_2);
        if (iVar1 == 0) break;
        iVar2 = *(int *)(iVar2 + 0x5c);
      } while (iVar2 != 0);
    }
    else {
      do {
        if (iVar2 == *param_3) break;
        iVar2 = *(int *)(iVar2 + 0x5c);
      } while (iVar2 != 0);
    }
    iVar1 = iVar2;
    if (iVar2 != 0) {
      if ((param_3 != (int *)0x0) && (*param_3 == 0)) {
        *param_3 = iVar2;
      }
      InterlockedIncrement((LONG *)(iVar2 + 4));
    }
  }
LAB_c02f3490:
  FUN_c02f1304(param_1);
  return iVar1;
}



/* c02f34bc FUN_c02f34bc */

/* Boundary evidence: original MIPS .pdata c02f34bc..c02f354b. Semantic name remains unreviewed. */

undefined4 FUN_c02f34bc(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = 0;
  if (param_2 != 0) {
    FUN_c02f2174(param_1);
    iVar3 = *(int *)(param_1 + 0x1c);
    if (iVar3 == 0) {
      *(int *)(param_1 + 0x1c) = param_2;
    }
    else {
      piVar4 = (int *)(iVar3 + 0x5c);
      iVar2 = *piVar4;
      while (iVar2 != 0) {
        iVar3 = *piVar4;
        piVar4 = (int *)(iVar3 + 0x5c);
        iVar2 = *piVar4;
      }
      *(int *)(iVar3 + 0x5c) = param_2;
    }
    *(undefined4 *)(param_2 + 0x5c) = 0;
    InterlockedIncrement((LONG *)(param_2 + 4));
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    uVar1 = 1;
  }
  return uVar1;
}



/* c02f354c FUN_c02f354c */

/* Boundary evidence: original MIPS .pdata c02f354c..c02f35c7. Semantic name remains unreviewed. */

undefined4 FUN_c02f354c(int *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 != 0) &&
     (puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x40))(param_1,param_2,0),
     puVar1 != (undefined4 *)0x0)) {
    uVar2 = (**(code **)(*param_1 + 0x4c))(param_1,puVar1);
    FUN_c02f1ff8(puVar1);
  }
  return uVar2;
}



/* c02f35c8 FUN_c02f35c8 */

/* Boundary evidence: original MIPS .pdata c02f35c8..c02f3667. Semantic name remains unreviewed. */

undefined4 FUN_c02f35c8(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (param_2 != (undefined4 *)0x0) {
    FUN_c02f2174(param_1);
    puVar3 = *(undefined4 **)(param_1 + 0x1c);
    puVar2 = (undefined4 *)0x0;
    while (puVar1 = puVar3, puVar1 != (undefined4 *)0x0) {
      if (puVar1 == param_2) goto LAB_c02f3620;
      puVar2 = puVar1;
      puVar3 = (undefined4 *)puVar1[0x17];
    }
    if (param_2 == (undefined4 *)0x0) {
LAB_c02f3620:
      uVar4 = 1;
      if (puVar2 == (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0x1c) = puVar1[0x17];
      }
      else {
        puVar2[0x17] = puVar1[0x17];
      }
      puVar1[0x17] = 0;
      FUN_c02f1ff8(puVar1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return uVar4;
}



/* c02f3680 FUN_c02f3680 */

/* Boundary evidence: original MIPS .pdata c02f3680..c02f377f. Semantic name remains unreviewed. */

void FUN_c02f3680(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  *param_1 = &PTR_FUN_c02f115c;
  if (param_1[9] != 0) {
    FUN_c02f28ec((int)param_1);
  }
  if ((void *)param_1[0x14] != (void *)0x0) {
    free((void *)param_1[0x14]);
  }
  if ((void *)param_1[0x15] != (void *)0x0) {
    operator_delete((void *)param_1[0x15]);
  }
  uVar2 = 3;
  if (3 < (uint)param_1[0x12]) {
    iVar1 = 0x30;
    do {
      if (*(void **)(param_1[0x13] + iVar1) != (void *)0x0) {
        operator_delete(*(void **)(param_1[0x13] + iVar1));
      }
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0x10;
    } while (uVar2 < (uint)param_1[0x12]);
  }
  if ((void *)param_1[0x13] != (void *)0x0) {
    operator_delete((void *)param_1[0x13]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  if ((HKEY)param_1[2] != (HKEY)0x0) {
    RegCloseKey((HKEY)param_1[2]);
  }
  *param_1 = &PTR_FUN_c02f1104;
  return;
}



/* c02f3780 FUN_c02f3780 */

/* Boundary evidence: original MIPS .pdata c02f3780..c02f37cb. Semantic name remains unreviewed. */

undefined4 * FUN_c02f3780(undefined4 *param_1,uint param_2)

{
  FUN_c02f2ab8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c02f37cc FUN_c02f37cc */

/* Boundary evidence: original MIPS .pdata c02f37cc..c02f3817. Semantic name remains unreviewed. */

undefined4 * FUN_c02f37cc(undefined4 *param_1,uint param_2)

{
  FUN_c02f3680(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c02f3988 entry */

/* Boundary evidence: original MIPS .pdata c02f3988..c02f39fb. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c02f39fc();
    FUN_c02f3cd0();
  }
  uVar1 = FUN_c02f1d9c(param_1,param_2);
  if (param_2 == 0) {
    FUN_c02f3c58();
  }
  return uVar1;
}



/* c02f39fc FUN_c02f39fc */

/* Boundary evidence: original MIPS .pdata c02f39fc..c02f3a6f. Semantic name remains unreviewed. */

void FUN_c02f39fc(void)

{
  uint uVar1;
  
  if ((DAT_c02f50d8 == 0) || (DAT_c02f50d8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c02f50d8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c02f50d8 == 0) {
      DAT_c02f50d8 = 0xb064;
    }
  }
  DAT_c02f50dc = ~DAT_c02f50d8;
  return;
}



/* c02f3a70 FUN_c02f3a70 */

/* Boundary evidence: original MIPS .pdata c02f3a70..c02f3ac3. Semantic name remains unreviewed. */

void FUN_c02f3a70(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c02f3af0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c02f3ac4 FUN_c02f3ac4 */

/* Boundary evidence: original MIPS .pdata c02f3ac4..c02f3aef. Semantic name remains unreviewed. */

undefined4 FUN_c02f3ac4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c02f3a70(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c02f3af0 FUN_c02f3af0 */

/* Boundary evidence: original MIPS .pdata c02f3af0..c02f3b37. Semantic name remains unreviewed. */

void FUN_c02f3af0(uint param_1)

{
  if ((param_1 == DAT_c02f50d8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c02f3b38 FUN_c02f3b38 */

/* Boundary evidence: original MIPS .pdata c02f3b38..c02f3c57. Semantic name remains unreviewed. */

void FUN_c02f3b38(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c02f50e0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c02f50e8;
    if (DAT_c02f50e8 != (undefined4 *)0x0) {
      while (DAT_c02f50e4 = DAT_c02f50e4 + -1, _Memory <= DAT_c02f50e4) {
        if ((code *)*DAT_c02f50e4 != (code *)0x0) {
          (*(code *)*DAT_c02f50e4)();
          _Memory = DAT_c02f50e8;
        }
      }
      free(_Memory);
      DAT_c02f50e4 = (undefined4 *)0x0;
      DAT_c02f50e8 = (undefined4 *)0x0;
    }
    FUN_c02f3c7c((undefined4 *)&DAT_c02f1010,(undefined4 *)&DAT_c02f1014);
  }
  FUN_c02f3c7c((undefined4 *)&DAT_c02f1018,(undefined4 *)&DAT_c02f101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c02f50ec,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c02f3c58 FUN_c02f3c58 */

/* Boundary evidence: original MIPS .pdata c02f3c58..c02f3c7b. Semantic name remains unreviewed. */

void FUN_c02f3c58(void)

{
  FUN_c02f3b38(0,0,1);
  return;
}



/* c02f3c7c FUN_c02f3c7c */

/* Boundary evidence: original MIPS .pdata c02f3c7c..c02f3ccf. Semantic name remains unreviewed. */

void FUN_c02f3c7c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c02f3cd0 FUN_c02f3cd0 */

/* Boundary evidence: original MIPS .pdata c02f3cd0..c02f3d0b. Semantic name remains unreviewed. */

void FUN_c02f3cd0(void)

{
  FUN_c02f3c7c((undefined4 *)&DAT_c02f1008,(undefined4 *)&DAT_c02f100c);
  FUN_c02f3c7c((undefined4 *)&DAT_c02f1000,(undefined4 *)&DAT_c02f1004);
  return;
}


