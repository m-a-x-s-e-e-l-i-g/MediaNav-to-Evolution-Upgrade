/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c04c1318 FUN_c04c1318 */

/* Boundary evidence: original MIPS .pdata c04c1318..c04c147b. Semantic name remains unreviewed. */

undefined4 FUN_c04c1318(LPCWSTR param_1,int param_2)

{
  wchar_t wVar1;
  LSTATUS LVar2;
  int iVar3;
  HMODULE hLibModule;
  wchar_t *_Str1;
  undefined4 uVar4;
  HKEY local_130;
  DWORD local_12c;
  DWORD local_128 [2];
  wchar_t local_120 [128];
  uint local_20;
  
  local_20 = DAT_c04c3084;
  uVar4 = 0;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\AFD",0,0x20019,&local_130);
  if (LVar2 == 0) {
    local_12c = 0x100;
    LVar2 = RegQueryValueExW(local_130,L"Stacks",(LPDWORD)0x0,local_128,(LPBYTE)local_120,&local_12c
                            );
    if (LVar2 == 0) {
      _Str1 = local_120;
      param_2 = 0;
      if (local_128[0] == 7) {
        while (local_120[0] != L'\0') {
          iVar3 = _wcsicmp(_Str1,param_1);
          if (iVar3 == 0) {
            param_2 = 1;
            break;
          }
          do {
            wVar1 = *_Str1;
            _Str1 = _Str1 + 1;
          } while (wVar1 != L'\0');
          local_120[0] = *_Str1;
        }
      }
    }
    RegCloseKey(local_130);
  }
  if ((param_2 != 0) && (hLibModule = LoadLibraryW(param_1), hLibModule != (HMODULE)0x0)) {
    FreeLibrary(hLibModule);
    uVar4 = 1;
  }
  FUN_c04c25c0(local_20);
  return uVar4;
}



/* c04c147c Ws2Instl */

/* Boundary evidence: original MIPS .pdata c04c147c..c04c195b. Semantic name remains unreviewed. */

undefined4 Ws2Instl(undefined4 param_1,undefined4 param_2,int param_3)

{
  SIZE_T uBytes;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *hMem;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *in_stack_00000018;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  wchar_t awStack_238 [260];
  uint local_30;
  
                    /* 0x147c  2  Ws2Instl */
  local_30 = DAT_c04c3084;
  local_248 = 0xaafc3764;
  *in_stack_00000018 = 0;
  DAT_c04c30b8 = *(code **)(param_3 + 0x68);
  DAT_c04c30b4 = *(undefined4 *)(param_3 + 0x74);
  local_244 = 0x427b763b;
  local_240 = 0xa6975bb1;
  local_23c = 0xce83c9e5;
  iVar1 = FUN_c04c1318(L"irdastk",1);
  iVar2 = FUN_c04c1318(L"btd",1);
  iVar3 = FUN_c04c1318(L"tcpip6",1);
  iVar5 = 2;
  if (iVar3 == 0) {
    iVar5 = 0;
  }
  iVar3 = iVar5 + iVar2 + (uint)(iVar1 != 0) + 3;
  uBytes = iVar3 * 0x274;
  hMem = LocalAlloc(0x40,uBytes);
  *hMem = 0x26;
  hMem[4] = 8;
  hMem[5] = local_248;
  hMem[6] = local_244;
  hMem[7] = local_240;
  hMem[8] = local_23c;
  hMem[0x17] = 6;
  hMem[10] = 1;
  hMem[0x12] = 2;
  hMem[0x13] = 2;
  hMem[0x14] = 0x10;
  hMem[0x15] = 0x10;
  hMem[0x16] = 1;
  wcscpy((wchar_t *)(hMem + 0x1d),L"Windows CE MS Tcpip [TCP/IP]");
  hMem[0x9d] = 0x609;
  hMem[0xa1] = 8;
  hMem[0xa2] = local_248;
  hMem[0xa3] = local_244;
  hMem[0xa4] = local_240;
  hMem[0xa5] = local_23c;
  hMem[0xaf] = 2;
  hMem[0xb0] = 2;
  hMem[0xb3] = 2;
  hMem[0xb4] = 0x11;
  hMem[0xa7] = 1;
  hMem[0xb1] = 0x10;
  hMem[0xb2] = 0x10;
  hMem[0xb8] = 0xffbb;
  wcscpy((wchar_t *)(hMem + 0xba),L"Windows CE MS Tcpip [UDP/IP]");
  puVar4 = hMem + 0x13a;
  *puVar4 = 0x609;
  hMem[0x13e] = 0xc;
  hMem[0x13f] = local_248;
  hMem[0x140] = local_244;
  hMem[0x141] = local_240;
  hMem[0x142] = local_23c;
  hMem[0x144] = 1;
  hMem[0x14c] = 2;
  hMem[0x14d] = 2;
  hMem[0x150] = 3;
  hMem[0x14e] = 0x10;
  hMem[0x14f] = 0x10;
  hMem[0x151] = 0;
  hMem[0x152] = 0xff;
  hMem[0x155] = 0xffbb;
  wcscpy((wchar_t *)(hMem + 0x157),L"Windows CE MS Tcpip [RAW/IP]");
  if (iVar5 != 0) {
    hMem[0x1d7] = 0x26;
    hMem[0x1db] = 8;
    hMem[0x1dc] = local_248;
    hMem[0x1dd] = local_244;
    hMem[0x1de] = local_240;
    hMem[0x1df] = local_23c;
    hMem[0x1e9] = 2;
    hMem[0x1ee] = 6;
    hMem[0x1e1] = 1;
    hMem[0x1ea] = 0x17;
    hMem[0x1eb] = 0x1c;
    hMem[0x1ec] = 0x1c;
    hMem[0x1ed] = 1;
    wcscpy((wchar_t *)(hMem + 500),L"Windows CE MS Tcpip [TCP/IPv6]");
    puVar4 = hMem + 0x274;
    *puVar4 = 0x609;
    hMem[0x278] = 8;
    hMem[0x279] = local_248;
    hMem[0x27a] = local_244;
    hMem[0x27b] = local_240;
    hMem[0x27c] = local_23c;
    hMem[0x28b] = 0x11;
    hMem[0x286] = 2;
    hMem[0x288] = 0x1c;
    hMem[0x289] = 0x1c;
    hMem[0x27e] = 1;
    hMem[0x287] = 0x17;
    hMem[0x28a] = 2;
    hMem[0x28f] = 0xfff7;
    wcscpy((wchar_t *)(hMem + 0x291),L"Windows CE MS Tcpip [UDP/IPv6]");
  }
  if ((iVar1 != 0) != 0) {
    puVar4[0x9d] = 6;
    puVar4[0xa1] = 8;
    puVar4[0xa2] = local_248;
    puVar4[0xa3] = local_244;
    puVar4[0xa4] = local_240;
    puVar4[0xa5] = local_23c;
    puVar4[0xb0] = 0x16;
    puVar4[0xb1] = 0x1f;
    puVar4[0xb2] = 0x1f;
    puVar4[0xa7] = 1;
    puVar4[0xaf] = 2;
    puVar4[0xb3] = 1;
    puVar4[0xb4] = 0;
    puVar4[0xb8] = 0x800;
    wcscpy((wchar_t *)(puVar4 + 0xba),L"Windows CE MS IrDA");
    puVar4 = puVar4 + 0x9d;
  }
  if (iVar2 != 0) {
    puVar4[0x9d] = 6;
    puVar4[0xa1] = 8;
    puVar4[0xa2] = local_248;
    puVar4[0xa3] = local_244;
    puVar4[0xa4] = local_240;
    puVar4[0xa5] = local_23c;
    puVar4[0xb0] = 0x20;
    puVar4[0xa7] = 1;
    puVar4[0xaf] = 2;
    puVar4[0xb1] = 0x28;
    puVar4[0xb2] = 0x28;
    puVar4[0xb3] = 1;
    puVar4[0xb4] = 3;
    wcscpy((wchar_t *)(puVar4 + 0xba),L"Windows CE MS Bluetooth");
  }
  wcscpy(awStack_238,L"wspm.dll");
  (*DAT_c04c30b8)(&local_248,awStack_238,hMem,uBytes,iVar3,0);
  LocalFree(hMem);
  FUN_c04c21c4();
  FUN_c04c25c0(local_30);
  return 1;
}



/* c04c195c InstallNSPM */

/* Boundary evidence: original MIPS .pdata c04c195c..c04c1a37. Semantic name remains unreviewed. */

undefined4 InstallNSPM(void)

{
  undefined4 uVar1;
  undefined4 local_38 [2];
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 auStack_20 [20];
  uint local_c;
  
                    /* 0x195c  1  InstallNSPM */
  local_c = DAT_c04c3084;
  local_2c = 0xb4f9;
  local_30 = 0x3c8441d3;
  local_25 = 0xc3;
  local_2a = 0x4ea0;
  local_28 = 0x89;
  local_27 = 0x74;
  local_26 = 0xf4;
  local_24 = 0x49;
  local_23 = 0x66;
  local_22 = 0x51;
  local_21 = 0x91;
  memcpy(auStack_20,L"nspm.dll",0x12);
  local_38[0] = 0;
  uVar1 = (*DAT_c04c30b4)(L"Windows CE DNS/WINS Name Resolver",auStack_20,0xc,0,&local_30,local_38);
  FUN_c04c25c0(local_c);
  return uVar1;
}



/* c04c1a38 FUN_c04c1a38 */

/* Boundary evidence: original MIPS .pdata c04c1a38..c04c1a87. Semantic name remains unreviewed. */

undefined4 FUN_c04c1a38(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_c04c23ac();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    FUN_c04c23ac();
  }
  return 1;
}



/* c04c1a88 FUN_c04c1a88 */

/* Boundary evidence: original MIPS .pdata c04c1a88..c04c1ad7. Semantic name remains unreviewed. */

void FUN_c04c1a88(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* c04c1ad8 FUN_c04c1ad8 */

/* Boundary evidence: original MIPS .pdata c04c1ad8..c04c1b3f. Semantic name remains unreviewed. */

undefined4 FUN_c04c1ad8(undefined4 *param_1,LPWSTR param_2,DWORD param_3)

{
  LSTATUS LVar1;
  DWORD dwIndex;
  DWORD local_res8 [2];
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    dwIndex = param_1[1];
    param_1[1] = dwIndex + 1;
    local_res8[0] = param_3;
    LVar1 = RegEnumKeyExW((HKEY)*param_1,dwIndex,param_2,local_res8,(LPDWORD)0x0,(LPWSTR)0x0,
                          (LPDWORD)0x0,(PFILETIME)0x0);
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c04c1b40 FUN_c04c1b40 */

/* Boundary evidence: original MIPS .pdata c04c1b40..c04c1c43. Semantic name remains unreviewed. */

int FUN_c04c1b40(undefined4 *param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  LPBYTE lpData;
  SIZE_T local_18 [2];
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_18[0] = param_1[3];
    LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)param_1[2],
                             local_18);
    if (LVar1 == 0) {
      if (param_1[2] != 0) {
        return param_1[2];
      }
    }
    else if (LVar1 != 0xea) {
      return 0;
    }
    if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[2]);
      param_1[2] = 0;
      param_1[3] = 0;
    }
    lpData = LocalAlloc(0,local_18[0]);
    param_1[2] = lpData;
    if (lpData != (LPBYTE)0x0) {
      param_1[3] = local_18[0];
      LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,lpData,local_18);
      if (LVar1 == 0) {
        return param_1[2];
      }
    }
  }
  return 0;
}



/* c04c1c44 FUN_c04c1c44 */

/* Boundary evidence: original MIPS .pdata c04c1c44..c04c1c97. Semantic name remains unreviewed. */

undefined4 FUN_c04c1c44(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  undefined4 local_10;
  DWORD local_c;
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_c = 4;
    local_10 = param_3;
    RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_10,&local_c);
    param_3 = local_10;
  }
  return param_3;
}



/* c04c1c98 FUN_c04c1c98 */

/* Boundary evidence: original MIPS .pdata c04c1c98..c04c1ccf. Semantic name remains unreviewed. */

void FUN_c04c1c98(undefined4 param_1,undefined *param_2)

{
  (*(code *)param_2)();
  return;
}



/* c04c1cd0 FUN_c04c1cd0 */

/* Boundary evidence: original MIPS .pdata c04c1cd0..c04c1cdb. Semantic name remains unreviewed. */

undefined4 FUN_c04c1cd0(void)

{
  return 1;
}



/* c04c1cdc FUN_c04c1cdc */

/* Boundary evidence: original MIPS .pdata c04c1cdc..c04c1d43. Semantic name remains unreviewed. */

void * FUN_c04c1cdc(int param_1,int param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(int *)((int)pvVar1 + 0x14) = param_2;
    *(undefined4 *)((int)pvVar1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
    *(void **)(*(int *)(param_2 + 0x18) + 0x14) = pvVar1;
    *(void **)(param_2 + 0x18) = pvVar1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return pvVar1;
}



/* c04c1d44 FUN_c04c1d44 */

/* Boundary evidence: original MIPS .pdata c04c1d44..c04c1ddb. Semantic name remains unreviewed. */

bool FUN_c04c1d44(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

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



/* c04c1ddc FUN_c04c1ddc */

/* Boundary evidence: original MIPS .pdata c04c1ddc..c04c1e93. Semantic name remains unreviewed. */

void FUN_c04c1ddc(int *param_1)

{
  LPCWSTR lpLibFileName;
  HMODULE hLibModule;
  wchar_t *pwVar1;
  undefined *puVar2;
  
  if (((*param_1 != 0) &&
      (lpLibFileName = (LPCWSTR)FUN_c04c1b40(param_1,L"Dll"), lpLibFileName != (LPCWSTR)0x0)) &&
     (hLibModule = LoadLibraryW(lpLibFileName), hLibModule != (HMODULE)0x0)) {
    pwVar1 = (wchar_t *)FUN_c04c1b40(param_1,L"Entry");
    if (pwVar1 == (wchar_t *)0x0) {
      pwVar1 = L"DllRegisterServer";
    }
    puVar2 = (undefined *)GetProcAddressW(hLibModule,pwVar1);
    if (puVar2 != (undefined *)0x0) {
      FUN_c04c1c98(param_1,puVar2);
    }
    FreeLibrary(hLibModule);
  }
  return;
}



/* c04c1e94 FUN_c04c1e94 */

/* Boundary evidence: original MIPS .pdata c04c1e94..c04c1ef3. Semantic name remains unreviewed. */

undefined * FUN_c04c1e94(void)

{
  if ((DAT_c04c30a0 & 1) == 0) {
    DAT_c04c30a0 = DAT_c04c30a0 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c04c308c);
    FUN_c04c284c(FUN_c04c2b7c);
  }
  return &DAT_c04c308c;
}



/* c04c1ef4 FUN_c04c1ef4 */

/* Boundary evidence: original MIPS .pdata c04c1ef4..c04c1f73. Semantic name remains unreviewed. */

undefined4 * FUN_c04c1ef4(undefined4 *param_1,int param_2,int param_3,undefined *param_4)

{
  for (; param_2 != param_3; param_2 = *(int *)(param_2 + 0x14)) {
    (*(code *)param_4)(param_2);
  }
  *param_1 = param_4;
  return param_1;
}



/* c04c1f74 FUN_c04c1f74 */

/* Boundary evidence: original MIPS .pdata c04c1f74..c04c1ff3. Semantic name remains unreviewed. */

undefined4 * FUN_c04c1f74(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_3[5];
  *(undefined4 *)(param_3[6] + 0x14) = uVar2;
  *(undefined4 *)(param_3[5] + 0x18) = param_3[6];
  FUN_c04c1a88(param_3);
  operator_delete(param_3);
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = uVar2;
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  return param_2;
}



/* c04c1ff4 FUN_c04c1ff4 */

/* Boundary evidence: original MIPS .pdata c04c1ff4..c04c207f. Semantic name remains unreviewed. */

undefined4 * FUN_c04c1ff4(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 auStack_20 [2];
  
  while (param_3 != param_4) {
    puVar1 = (undefined4 *)param_3[5];
    FUN_c04c1f74(param_1,auStack_20,param_3);
    param_3 = puVar1;
  }
  *param_2 = param_3;
  return param_2;
}



/* c04c2080 FUN_c04c2080 */

/* Boundary evidence: original MIPS .pdata c04c2080..c04c20f7. Semantic name remains unreviewed. */

undefined4 * FUN_c04c2080(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_c04c1cdc((int)param_1,param_3);
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  else {
    uVar2 = *param_4;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = uVar2;
    *param_2 = puVar1;
  }
  return param_2;
}



/* c04c20f8 FUN_c04c20f8 */

int * FUN_c04c20f8(int *param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  for (iVar2 = param_2; iVar2 != param_3; iVar2 = *(int *)(iVar2 + 0x14)) {
    iVar3 = iVar3 + 1;
  }
  if (0 < iVar3) {
    do {
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = iVar3 + 1;
      }
      iVar2 = iVar2 >> 1;
      iVar4 = param_2;
      for (iVar1 = iVar2; 0 < iVar1; iVar1 = iVar1 + -1) {
        iVar4 = *(int *)(iVar4 + 0x14);
      }
      if (iVar1 < 0) {
        iVar1 = -iVar1;
        do {
          iVar1 = iVar1 + -1;
          iVar4 = *(int *)(iVar4 + 0x18);
        } while (iVar1 != 0);
      }
      if (*(uint *)(iVar4 + 0x10) <= *param_4) {
        param_2 = *(int *)(iVar4 + 0x14);
        iVar2 = (iVar3 - iVar2) + -1;
      }
      iVar3 = iVar2;
    } while (0 < iVar2);
  }
  *param_1 = param_2;
  return param_1;
}



/* c04c21c4 FUN_c04c21c4 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Boundary evidence: original MIPS .pdata c04c21c4..c04c23ab. Semantic name remains unreviewed. */

void FUN_c04c21c4(void)

{
  PHKEY ppHVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  HKEY local_270 [2];
  undefined4 auStack_268 [2];
  HKEY *local_260;
  HKEY *local_25c;
  HKEY *local_258;
  undefined4 local_254;
  uint local_250 [2];
  HKEY local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  HKEY local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  int local_228;
  PHKEY local_224;
  WCHAR aWStack_220 [262];
  uint local_14;
  
  local_14 = DAT_c04c3084;
  local_248 = (HKEY)0x0;
  local_244 = 0;
  local_240 = 0;
  local_23c = 0;
  FUN_c04c1d44(&local_248,(HKEY)0x80000002,L"\\COMM\\WS2\\LSP",0x20019);
  if (local_248 != (HKEY)0x0) {
    local_260 = local_270;
    local_254 = 0;
    local_25c = local_260;
    local_258 = local_260;
    iVar3 = FUN_c04c1ad8(&local_248,aWStack_220,0x105);
    while (iVar3 != 0) {
      local_238 = (HKEY)0x0;
      local_234 = 0;
      local_230 = 0;
      local_22c = 0;
      FUN_c04c1d44(&local_238,local_248,aWStack_220,0x20019);
      if (local_238 != (HKEY)0x0) {
        local_250[0] = FUN_c04c1c44(&local_238,L"Order",0xffffffff);
        local_270[0] = (HKEY)0x0;
        FUN_c04c20f8(&local_228,(int)local_260[5],(int)local_260,local_250);
        FUN_c04c2080(&local_260,&local_224,local_228,local_250);
        ppHVar1 = local_224;
        if (local_224 == local_260) {
          FUN_c04c1a88(&local_238);
          goto LAB_c04c2360;
        }
        bVar2 = FUN_c04c1d44(local_224,local_238,(LPCWSTR)0x0,0x20019);
        if (CONCAT31(extraout_var,bVar2) == 0) {
          FUN_c04c1f74((int)&local_260,auStack_268,ppHVar1);
        }
      }
      FUN_c04c1a88(&local_238);
      iVar3 = FUN_c04c1ad8(&local_248,aWStack_220,0x105);
    }
    FUN_c04c1ef4(auStack_268,(int)local_260[5],(int)local_260,FUN_c04c1ddc);
LAB_c04c2360:
    FUN_c04c1ff4((int)&local_260,auStack_268,local_260[5],local_260);
  }
  FUN_c04c1a88(&local_248);
  FUN_c04c25c0(local_14);
  return;
}



/* c04c23ac FUN_c04c23ac */

void FUN_c04c23ac(void)

{
  return;
}



/* c04c23b4 FUN_c04c23b4 */

/* Boundary evidence: original MIPS .pdata c04c23b4..c04c23cf. Semantic name remains unreviewed. */

void FUN_c04c23b4(size_t param_1)

{
  malloc(param_1);
  return;
}



/* c04c23d0 FUN_c04c23d0 */

/* Boundary evidence: original MIPS .pdata c04c23d0..c04c23eb. Semantic name remains unreviewed. */

void FUN_c04c23d0(void *param_1,size_t param_2)

{
  realloc(param_1,param_2);
  return;
}



/* c04c23ec FUN_c04c23ec */

/* Boundary evidence: original MIPS .pdata c04c23ec..c04c2407. Semantic name remains unreviewed. */

void FUN_c04c23ec(void *param_1)

{
  free(param_1);
  return;
}



/* c04c2458 entry */

/* Boundary evidence: original MIPS .pdata c04c2458..c04c24cb. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c04c24cc();
    FUN_c04c2a14();
  }
  uVar1 = FUN_c04c1a38(param_1,param_2);
  if (param_2 == 0) {
    FUN_c04c299c();
  }
  return uVar1;
}



/* c04c24cc FUN_c04c24cc */

/* Boundary evidence: original MIPS .pdata c04c24cc..c04c253f. Semantic name remains unreviewed. */

void FUN_c04c24cc(void)

{
  uint uVar1;
  
  if ((DAT_c04c3084 == 0) || (DAT_c04c3084 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c04c3084 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c04c3084 == 0) {
      DAT_c04c3084 = 0xb064;
    }
  }
  DAT_c04c3088 = ~DAT_c04c3084;
  return;
}



/* c04c2540 FUN_c04c2540 */

/* Boundary evidence: original MIPS .pdata c04c2540..c04c2593. Semantic name remains unreviewed. */

void FUN_c04c2540(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c04c25c0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c04c2594 FUN_c04c2594 */

/* Boundary evidence: original MIPS .pdata c04c2594..c04c25bf. Semantic name remains unreviewed. */

undefined4 FUN_c04c2594(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c04c2540(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c04c25c0 FUN_c04c25c0 */

/* Boundary evidence: original MIPS .pdata c04c25c0..c04c2607. Semantic name remains unreviewed. */

void FUN_c04c25c0(uint param_1)

{
  if ((param_1 == DAT_c04c3084) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c04c2608 FUN_c04c2608 */

/* Boundary evidence: original MIPS .pdata c04c2608..c04c2713. Semantic name remains unreviewed. */

undefined4 FUN_c04c2608(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c04c30c0;
  puVar3 = DAT_c04c30bc;
  iVar4 = (int)DAT_c04c30bc - (int)DAT_c04c30c0;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c04c264c:
    param_1 = 0;
  }
  else {
    if (DAT_c04c30c0 != (void *)0x0) {
      uVar1 = _msize(DAT_c04c30c0);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c04c26c0:
        if (pvVar2 == (void *)0x0) goto LAB_c04c264c;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c04c26c0;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c04c30bc = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c04c30c0 = pvVar2;
  }
  return param_1;
}



/* c04c2714 FUN_c04c2714 */

/* Boundary evidence: original MIPS .pdata c04c2714..c04c27ff. Semantic name remains unreviewed. */

undefined4 FUN_c04c2714(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c04c30c4 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c04c30c4,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c04c30c4 == (LPCRITICAL_SECTION)0x0) goto LAB_c04c27b8;
  }
  EnterCriticalSection(DAT_c04c30c4);
LAB_c04c27b8:
  uVar2 = FUN_c04c2608(param_1);
  FUN_c04c2800();
  return uVar2;
}



/* c04c2800 FUN_c04c2800 */

/* Boundary evidence: original MIPS .pdata c04c2800..c04c284b. Semantic name remains unreviewed. */

void FUN_c04c2800(void)

{
  if (DAT_c04c30c4 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c04c30c4);
  }
  return;
}



/* c04c284c FUN_c04c284c */

/* Boundary evidence: original MIPS .pdata c04c284c..c04c287b. Semantic name remains unreviewed. */

undefined4 FUN_c04c284c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04c2714(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c04c287c FUN_c04c287c */

/* Boundary evidence: original MIPS .pdata c04c287c..c04c299b. Semantic name remains unreviewed. */

void FUN_c04c287c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c04c30b0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c04c30c0;
    if (DAT_c04c30c0 != (undefined4 *)0x0) {
      while (DAT_c04c30bc = DAT_c04c30bc + -1, _Memory <= DAT_c04c30bc) {
        if ((code *)*DAT_c04c30bc != (code *)0x0) {
          (*(code *)*DAT_c04c30bc)();
          _Memory = DAT_c04c30c0;
        }
      }
      free(_Memory);
      DAT_c04c30bc = (undefined4 *)0x0;
      DAT_c04c30c0 = (undefined4 *)0x0;
    }
    FUN_c04c29c0((undefined4 *)&DAT_c04c1014,(undefined4 *)&DAT_c04c1018);
  }
  FUN_c04c29c0((undefined4 *)&DAT_c04c101c,(undefined4 *)&DAT_c04c1020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c04c30c4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c04c299c FUN_c04c299c */

/* Boundary evidence: original MIPS .pdata c04c299c..c04c29bf. Semantic name remains unreviewed. */

void FUN_c04c299c(void)

{
  FUN_c04c287c(0,0,1);
  return;
}



/* c04c29c0 FUN_c04c29c0 */

/* Boundary evidence: original MIPS .pdata c04c29c0..c04c2a13. Semantic name remains unreviewed. */

void FUN_c04c29c0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c04c2a14 FUN_c04c2a14 */

/* Boundary evidence: original MIPS .pdata c04c2a14..c04c2a4f. Semantic name remains unreviewed. */

void FUN_c04c2a14(void)

{
  FUN_c04c29c0((undefined4 *)&DAT_c04c100c,(undefined4 *)&DAT_c04c1010);
  FUN_c04c29c0((undefined4 *)&DAT_c04c1000,(undefined4 *)&DAT_c04c1008);
  return;
}



/* c04c2b60 FUN_c04c2b60 */

/* Boundary evidence: original MIPS .pdata c04c2b60..c04c2b7b. Semantic name remains unreviewed. */

void FUN_c04c2b60(void)

{
  FUN_c04c1e94();
  return;
}



/* c04c2b7c FUN_c04c2b7c */

/* Boundary evidence: original MIPS .pdata c04c2b7c..c04c2b9b. Semantic name remains unreviewed. */

void FUN_c04c2b7c(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c04c308c);
  return;
}


