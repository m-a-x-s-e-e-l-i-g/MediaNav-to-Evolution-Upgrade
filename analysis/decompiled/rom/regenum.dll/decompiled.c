/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c02e10cc FUN_c02e10cc */

/* Boundary evidence: original MIPS .pdata c02e10cc..c02e10ff. Semantic name remains unreviewed. */

undefined4 FUN_c02e10cc(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c02e1100 FUN_c02e1100 */

/* Boundary evidence: original MIPS .pdata c02e1100..c02e1143. Semantic name remains unreviewed. */

void FUN_c02e1100(undefined4 param_1,undefined4 *param_2)

{
  if ((param_2 == (undefined4 *)0x0) || (param_2[1] == 0)) {
    ActivateDevice(param_1,0);
  }
  else {
    ActivateDeviceEx(param_1,*param_2,param_2[1],0);
  }
  return;
}



/* c02e1144 FUN_c02e1144 */

/* Boundary evidence: original MIPS .pdata c02e1144..c02e176b. Semantic name remains unreviewed. */

LPCWSTR FUN_c02e1144(LPCWSTR param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  DWORD dwIndex;
  LSTATUS LVar2;
  LPCWSTR pWVar3;
  size_t sVar4;
  HMODULE hLibModule;
  code *pcVar5;
  undefined4 uVar6;
  int iVar7;
  wchar_t *_Dest;
  wchar_t *_Dest_00;
  wchar_t *lpValueName;
  uint uVar8;
  uint uVar9;
  wchar_t local_368 [2];
  DWORD local_364;
  LPCWSTR local_360;
  HKEY local_35c;
  DWORD local_358;
  HKEY local_354;
  LPCWSTR local_350;
  DWORD local_34c;
  DWORD local_348;
  DWORD DStack_344;
  uint local_340;
  DWORD local_33c;
  wchar_t *local_338;
  WCHAR aWStack_330 [64];
  undefined1 auStack_2b0 [128];
  WCHAR aWStack_230 [256];
  uint local_30;
  
  local_30 = DAT_c02e306c;
  local_360 = param_1;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_35c);
  if (LVar2 == 0) {
    local_358 = 0x40;
    LVar2 = RegQueryInfoKeyW(local_35c,aWStack_330,&local_358,(LPDWORD)0x0,&local_364,&local_33c,
                             (LPDWORD)local_368,&local_34c,&local_348,(LPDWORD)local_368,
                             (LPDWORD)0x0,(PFILETIME)0x0);
    if ((LVar2 == 0) &&
       (pWVar3 = LocalAlloc(0,(local_364 + 3) * 4), local_350 = pWVar3, pWVar3 != (LPCWSTR)0x0)) {
      *(int *)(pWVar3 + 2) = param_2;
      *(int *)(pWVar3 + 4) = param_3;
      pWVar3[0] = L'\0';
      pWVar3[1] = L'\0';
      sVar4 = wcslen(param_1);
      iVar7 = (int)((sVar4 + local_33c + 2) * 2 + 7) >> 3;
      iVar1 = iVar7 * -8;
      _Dest = local_368 + iVar7 * -4;
      local_338 = _Dest;
      if (_Dest != (wchar_t *)0x0) {
        wcscpy(_Dest,param_1);
        sVar4 = wcslen(_Dest);
        _Dest[sVar4] = L'\\';
        _Dest_00 = _Dest + sVar4 + 1;
        local_360 = _Dest_00;
        local_358 = 0;
        local_34c = 0;
        if (local_364 != 0) {
          lpValueName = L"Flags";
          local_350 = L"Flags";
          uVar9 = 0x100;
          do {
            dwIndex = local_358;
            local_368[0] = L'Ā';
            local_368[1] = L'\0';
            *(undefined4 *)(&stack0xfffffc84 + iVar1) = 0;
            *(undefined4 *)(&stack0xfffffc80 + iVar1) = 0;
            *(undefined4 *)(&stack0xfffffc7c + iVar1) = 0;
            *(undefined4 *)(&stack0xfffffc78 + iVar1) = 0;
            LVar2 = RegEnumKeyExW(local_35c,dwIndex,aWStack_230,(LPDWORD)local_368,
                                  *(LPDWORD *)(&stack0xfffffc78 + iVar1),
                                  *(LPWSTR *)(&stack0xfffffc7c + iVar1),
                                  *(LPDWORD *)(&stack0xfffffc80 + iVar1),
                                  *(PFILETIME *)(&stack0xfffffc84 + iVar1));
            if (LVar2 == 0x103) {
              local_358 = 0;
              local_34c = uVar9;
              uVar8 = 0x100;
              if (0xff < uVar9) break;
            }
            else {
              if (LVar2 == 0) {
                *(HKEY **)(&stack0xfffffc78 + iVar1) = &local_354;
                LVar2 = RegOpenKeyExW(local_35c,aWStack_230,0,0,*(PHKEY *)(&stack0xfffffc78 + iVar1)
                                     );
                if (LVar2 == 0) {
                  local_368[0] = L'\x04';
                  local_368[1] = L'\0';
                  *(wchar_t **)(&stack0xfffffc7c + iVar1) = local_368;
                  *(DWORD **)(&stack0xfffffc78 + iVar1) = &local_348;
                  LVar2 = RegQueryValueExW(local_354,L"Order",(LPDWORD)0x0,&DStack_344,
                                           *(LPBYTE *)(&stack0xfffffc78 + iVar1),
                                           *(LPDWORD *)(&stack0xfffffc7c + iVar1));
                  if ((LVar2 != 0) || (0xff < local_348)) {
                    local_348 = 0xff;
                  }
                  if (local_348 == local_34c) {
                    local_368[0] = L'\x80';
                    local_368[1] = L'\0';
                    *(wchar_t **)(&stack0xfffffc7c + iVar1) = local_368;
                    *(undefined1 **)(&stack0xfffffc78 + iVar1) = auStack_2b0;
                    LVar2 = RegQueryValueExW(local_354,L"Entry",(LPDWORD)0x0,&DStack_344,
                                             *(LPBYTE *)(&stack0xfffffc78 + iVar1),
                                             *(LPDWORD *)(&stack0xfffffc7c + iVar1));
                    if (LVar2 == 0) {
                      local_368[0] = L'\x80';
                      local_368[1] = L'\0';
                      *(wchar_t **)(&stack0xfffffc7c + iVar1) = local_368;
                      *(WCHAR **)(&stack0xfffffc78 + iVar1) = aWStack_330;
                      LVar2 = RegQueryValueExW(local_354,L"Dll",(LPDWORD)0x0,&DStack_344,
                                               *(LPBYTE *)(&stack0xfffffc78 + iVar1),
                                               *(LPDWORD *)(&stack0xfffffc7c + iVar1));
                      if (LVar2 == 0) {
                        local_368[0] = L'\x04';
                        local_368[1] = L'\0';
                        *(wchar_t **)(&stack0xfffffc7c + iVar1) = local_368;
                        *(uint **)(&stack0xfffffc78 + iVar1) = &local_340;
                        LVar2 = RegQueryValueExW(local_354,lpValueName,(LPDWORD)0x0,&DStack_344,
                                                 *(LPBYTE *)(&stack0xfffffc78 + iVar1),
                                                 *(LPDWORD *)(&stack0xfffffc7c + iVar1));
                        if (LVar2 != 0) {
                          local_340 = 0;
                        }
                        if ((local_340 & 4) == 0) {
                          if ((local_340 & 2) == 0) {
                            hLibModule = (HMODULE)LoadDriver();
                          }
                          else {
                            hLibModule = LoadLibraryW(aWStack_330);
                          }
                          _Dest_00 = local_360;
                          if (hLibModule != (HMODULE)0x0) {
                            pcVar5 = (code *)GetProcAddressW(hLibModule,auStack_2b0);
                            if (pcVar5 == (code *)0x0) {
                              FreeLibrary(hLibModule);
                              _Dest_00 = local_360;
                              lpValueName = local_350;
                            }
                            else {
                              wcscpy(local_360,aWStack_230);
                              (*pcVar5)(_Dest);
                              local_364 = local_364 - 1;
                              _Dest_00 = local_360;
                              lpValueName = local_350;
                              if ((local_340 & 1) != 0) {
                                FreeLibrary(hLibModule);
                                _Dest_00 = local_360;
                                lpValueName = local_350;
                              }
                            }
                          }
                        }
                      }
                    }
                    else {
                      wcscpy(_Dest_00,aWStack_230);
                      uVar6 = (**(code **)(pWVar3 + 2))(_Dest,param_4);
                      *(undefined4 *)(pWVar3 + (*(int *)pWVar3 + 3) * 2) = uVar6;
                      *(int *)pWVar3 = *(int *)pWVar3 + 1;
                      local_364 = local_364 - 1;
                    }
                  }
                  else if ((local_348 < uVar9) && (local_34c < local_348)) {
                    uVar9 = local_348;
                  }
                  RegCloseKey(local_354);
                }
              }
              else if (local_34c == 0) {
                local_364 = local_364 - 1;
              }
              local_358 = local_358 + 1;
              uVar8 = uVar9;
            }
            uVar9 = uVar8;
          } while (local_364 != 0);
        }
        RegCloseKey(local_35c);
        FUN_c02e200c(local_30);
        return pWVar3;
      }
    }
    RegCloseKey(local_35c);
  }
  FUN_c02e200c(local_30);
  return (LPCWSTR)0x0;
}



/* c02e176c FUN_c02e176c */

/* Boundary evidence: original MIPS .pdata c02e176c..c02e1777. Semantic name remains unreviewed. */

undefined4 FUN_c02e176c(void)

{
  return 1;
}



/* c02e1778 Enum */

/* Boundary evidence: original MIPS .pdata c02e1778..c02e1793. Semantic name remains unreviewed. */

void Enum(LPCWSTR param_1,int param_2,int param_3)

{
                    /* 0x1778  2  Enum */
  FUN_c02e1144(param_1,param_2,param_3,0);
  return;
}



/* c02e1794 Init */

/* Boundary evidence: original MIPS .pdata c02e1794..c02e1c5f. Semantic name remains unreviewed. */

LPCWSTR Init(LPCWSTR param_1)

{
  short sVar1;
  LSTATUS LVar2;
  HKEY hKey;
  HLOCAL pvVar3;
  LPCWSTR pWVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  short *lpData;
  short *psVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  HLOCAL local_248;
  uint local_244;
  DWORD local_240;
  HKEY local_23c;
  undefined4 local_238;
  DWORD local_234;
  WCHAR aWStack_230 [255];
  undefined2 local_32;
  uint local_30;
  
                    /* 0x1794  3  Init */
  local_30 = DAT_c02e306c;
  lpData = (short *)0x0;
  local_248 = (HLOCAL)0x0;
  local_244 = 0;
  local_238 = 0xffffffff;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_23c);
  if (LVar2 != 0) {
LAB_c02e1814:
    FUN_c02e200c(local_30);
    return (LPCWSTR)0x0;
  }
  local_240 = 0x200;
  LVar2 = RegQueryValueExW(local_23c,L"Key",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)aWStack_230,&local_240
                          );
  if (LVar2 != 0) {
    RegCloseKey(local_23c);
    goto LAB_c02e1814;
  }
  local_32 = 0;
  hKey = (HKEY)OpenDeviceKey(param_1);
  if (hKey != (HKEY)0x0) {
    local_240 = 4;
    LVar2 = RegQueryValueExW(hKey,L"InterfaceType",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_238,
                             &local_240);
    if (LVar2 != 0) {
      local_238 = 0xffffffff;
    }
    RegCloseKey(hKey);
  }
  local_240 = 0;
  LVar2 = RegQueryValueExW(local_23c,L"RegenumParms",(LPDWORD)0x0,&local_234,(LPBYTE)0x0,&local_240)
  ;
  if ((LVar2 == 0) && (local_234 == 7)) {
    lpData = LocalAlloc(0,local_240);
    if ((lpData == (short *)0x0) ||
       (LVar2 = RegQueryValueExW(local_23c,L"RegenumParms",(LPDWORD)0x0,&local_234,(LPBYTE)lpData,
                                 &local_240), LVar2 != 0)) goto LAB_c02e1ba0;
    uVar6 = local_240 >> 1;
    uVar5 = 1;
    uVar10 = 0;
    psVar8 = lpData;
    if (1 < uVar6) {
      do {
        if ((*psVar8 == 0) && (uVar10 = uVar10 + 1, psVar8[1] == 0)) break;
        uVar5 = uVar5 + 1;
        psVar8 = psVar8 + 1;
      } while (uVar5 < uVar6);
    }
    if ((((uVar6 <= uVar5) || (lpData[uVar5] != 0)) || ((lpData + uVar5)[-1] != 0)) ||
       (local_248 = LocalAlloc(0,(uVar10 + 1) * 0x10), local_248 == (HLOCAL)0x0)) goto LAB_c02e1ba0;
    uVar5 = 0;
    if (uVar10 != 0) {
      iVar11 = 0;
      psVar8 = lpData;
      do {
        *(short **)(iVar11 + (int)local_248) = psVar8;
        *(undefined4 *)((int)local_248 + iVar11 + 4) = 0;
        *(undefined4 *)((int)local_248 + iVar11 + 8) = 0;
        puVar7 = (undefined4 *)(iVar11 + (int)local_248);
        LVar2 = RegQueryValueExW(local_23c,(LPCWSTR)*puVar7,(LPDWORD)0x0,puVar7 + 3,(LPBYTE)0x0,
                                 puVar7 + 2);
        if (LVar2 != 0) break;
        pvVar3 = LocalAlloc(0,*(SIZE_T *)((int)local_248 + iVar11 + 8));
        *(HLOCAL *)((int)local_248 + iVar11 + 4) = pvVar3;
        puVar7 = (undefined4 *)(iVar11 + (int)local_248);
        if ((LPBYTE)puVar7[1] == (LPBYTE)0x0) break;
        RegQueryValueExW(local_23c,(LPCWSTR)*puVar7,(LPDWORD)0x0,puVar7 + 3,(LPBYTE)puVar7[1],
                         puVar7 + 2);
        sVar1 = *psVar8;
        while (sVar1 != 0) {
          psVar8 = psVar8 + 1;
          sVar1 = *psVar8;
        }
        uVar5 = uVar5 + 1;
        psVar8 = psVar8 + 1;
        iVar11 = iVar11 + 0x10;
      } while (uVar5 < uVar10);
    }
  }
  else {
    local_244 = 0;
    local_248 = LocalAlloc(0,0x10);
    uVar5 = local_244;
  }
  local_244 = uVar5;
  if (local_248 != (HLOCAL)0x0) {
    *(wchar_t **)(local_244 * 0x10 + (int)local_248) = L"InterfaceType";
    *(undefined4 *)((int)local_248 + local_244 * 0x10 + 0xc) = 4;
    pvVar3 = LocalAlloc(0,4);
    *(HLOCAL *)((int)local_248 + local_244 * 0x10 + 4) = pvVar3;
    *(undefined4 *)((int)local_248 + local_244 * 0x10 + 8) = 4;
    puVar7 = *(undefined4 **)((int)local_248 + local_244 * 0x10 + 4);
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = local_238;
    }
    local_244 = local_244 + 1;
  }
LAB_c02e1ba0:
  RegCloseKey(local_23c);
  pWVar4 = FUN_c02e1144(aWStack_230,-0x3fd1ef00,-0x3fd1e2c4,&local_248);
  if (local_244 != 0) {
    iVar11 = 0;
    if (0 < (int)local_244) {
      iVar9 = 0;
      uVar5 = local_244;
      do {
        pvVar3 = *(HLOCAL *)((int)local_248 + iVar9 + 4);
        if (pvVar3 != (HLOCAL)0x0) {
          LocalFree(pvVar3);
          uVar5 = local_244;
        }
        iVar11 = iVar11 + 1;
        iVar9 = iVar9 + 0x10;
      } while (iVar11 < (int)uVar5);
    }
    LocalFree(local_248);
  }
  if (lpData != (short *)0x0) {
    LocalFree(lpData);
  }
  FUN_c02e200c(local_30);
  return pWVar4;
}



/* c02e1c60 Deinit */

/* Boundary evidence: original MIPS .pdata c02e1c60..c02e1cdb. Semantic name remains unreviewed. */

void Deinit(int *param_1)

{
  int iVar1;
  
                    /* 0x1c60  1  Deinit */
  if (param_1[2] != 0) {
    iVar1 = *param_1;
    while (iVar1 != 0) {
      iVar1 = *param_1;
      *param_1 = iVar1 + -1;
      if (param_1[iVar1 + 2] != 0) {
        (*(code *)param_1[2])();
      }
      iVar1 = *param_1;
    }
  }
  LocalFree(param_1);
  return;
}



/* c02e1d5c FUN_c02e1d5c */

/* Boundary evidence: original MIPS .pdata c02e1d5c..c02e1e97. Semantic name remains unreviewed. */

int FUN_c02e1d5c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c02e3084 != (code *)0x0) {
      iVar2 = (*DAT_c02e3084)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c02e1e0c;
    FUN_c02e226c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c02e10cc(param_1,param_2);
  }
LAB_c02e1e0c:
  if (((param_2 == 0) && (FUN_c02e21f4(), iVar1 != 0)) && (DAT_c02e3084 != (code *)0x0)) {
    iVar1 = (*DAT_c02e3084)(param_1,0,param_3);
  }
  return iVar1;
}



/* c02e1e98 FUN_c02e1e98 */

/* Boundary evidence: original MIPS .pdata c02e1e98..c02e1ec3. Semantic name remains unreviewed. */

void FUN_c02e1e98(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c02e1ec4 entry */

/* Boundary evidence: original MIPS .pdata c02e1ec4..c02e1f1b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c02e1f1c();
  }
  FUN_c02e1d5c(param_1,param_2,param_3);
  return;
}



/* c02e1f1c FUN_c02e1f1c */

/* Boundary evidence: original MIPS .pdata c02e1f1c..c02e1f8f. Semantic name remains unreviewed. */

void FUN_c02e1f1c(void)

{
  uint uVar1;
  
  if ((DAT_c02e306c == 0) || (DAT_c02e306c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c02e306c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c02e306c == 0) {
      DAT_c02e306c = 0xb064;
    }
  }
  DAT_c02e3070 = ~DAT_c02e306c;
  return;
}



/* c02e1f90 FUN_c02e1f90 */

/* Boundary evidence: original MIPS .pdata c02e1f90..c02e200b. Semantic name remains unreviewed. */

void FUN_c02e1f90(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c02e2054(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c02e200c FUN_c02e200c */

/* Boundary evidence: original MIPS .pdata c02e200c..c02e2053. Semantic name remains unreviewed. */

void FUN_c02e200c(uint param_1)

{
  if ((param_1 == DAT_c02e306c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c02e2054 FUN_c02e2054 */

/* Boundary evidence: original MIPS .pdata c02e2054..c02e20a7. Semantic name remains unreviewed. */

void FUN_c02e2054(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c02e200c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c02e20a8 FUN_c02e20a8 */

/* Boundary evidence: original MIPS .pdata c02e20a8..c02e20d3. Semantic name remains unreviewed. */

undefined4 FUN_c02e20a8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c02e2054(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c02e20d4 FUN_c02e20d4 */

/* Boundary evidence: original MIPS .pdata c02e20d4..c02e21f3. Semantic name remains unreviewed. */

void FUN_c02e20d4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c02e3074 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c02e307c;
    if (DAT_c02e307c != (undefined4 *)0x0) {
      while (DAT_c02e3078 = DAT_c02e3078 + -1, _Memory <= DAT_c02e3078) {
        if ((code *)*DAT_c02e3078 != (code *)0x0) {
          (*(code *)*DAT_c02e3078)();
          _Memory = DAT_c02e307c;
        }
      }
      free(_Memory);
      DAT_c02e3078 = (undefined4 *)0x0;
      DAT_c02e307c = (undefined4 *)0x0;
    }
    FUN_c02e2218((undefined4 *)&DAT_c02e1010,(undefined4 *)&DAT_c02e1014);
  }
  FUN_c02e2218((undefined4 *)&DAT_c02e1018,(undefined4 *)&DAT_c02e101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c02e3080,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c02e21f4 FUN_c02e21f4 */

/* Boundary evidence: original MIPS .pdata c02e21f4..c02e2217. Semantic name remains unreviewed. */

void FUN_c02e21f4(void)

{
  FUN_c02e20d4(0,0,1);
  return;
}



/* c02e2218 FUN_c02e2218 */

/* Boundary evidence: original MIPS .pdata c02e2218..c02e226b. Semantic name remains unreviewed. */

void FUN_c02e2218(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c02e226c FUN_c02e226c */

/* Boundary evidence: original MIPS .pdata c02e226c..c02e22a7. Semantic name remains unreviewed. */

void FUN_c02e226c(void)

{
  FUN_c02e2218((undefined4 *)&DAT_c02e1008,(undefined4 *)&DAT_c02e100c);
  FUN_c02e2218((undefined4 *)&DAT_c02e1000,(undefined4 *)&DAT_c02e1004);
  return;
}


