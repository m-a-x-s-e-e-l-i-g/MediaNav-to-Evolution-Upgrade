/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0432500 FUN_c0432500 */

/* Boundary evidence: original MIPS .pdata c0432500..c0432583. Semantic name remains unreviewed. */

undefined4 FUN_c0432500(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  DAT_c044d8dc = LoadLibraryW(L"coredll.dll");
  if (DAT_c044d8dc != (HMODULE)0x0) {
    DAT_c044d8d8 = GetProcAddressW(DAT_c044d8dc,L"PostMessageW");
    if (DAT_c044d8d8 == 0) {
      FreeLibrary(DAT_c044d8dc);
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* c0432584 DllEntry */

/* Boundary evidence: original MIPS .pdata c0432584..c04325cb. Semantic name remains unreviewed. */

undefined4 DllEntry(HMODULE param_1,int param_2)

{
                    /* 0x2584  17  DllEntry */
  if (param_2 == 1) {
    DAT_c044d8d4 = param_1;
    DisableThreadLibraryCalls(param_1);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  }
  return 1;
}



/* c04325cc Deinit */

undefined4 Deinit(void)

{
                    /* 0x25cc  16  Deinit */
  return 1;
}



/* c04325d4 Init */

/* Boundary evidence: original MIPS .pdata c04325d4..c043262f. Semantic name remains unreviewed. */

undefined4 Init(void)

{
                    /* 0x25d4  18  Init */
  if (DAT_c044d840 == 0) {
    FUN_c0432500();
    FUN_c04455ec();
    FUN_c043b030();
    FUN_c043b77c();
    DAT_c044d840 = 1;
  }
  return 1;
}



/* c0432630 FUN_c0432630 */

/* Boundary evidence: original MIPS .pdata c0432630..c04326eb. Semantic name remains unreviewed. */

undefined4 FUN_c0432630(undefined4 param_1,undefined4 param_2)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"WaitForAPIReady");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c04326ec FUN_c04326ec */

/* Boundary evidence: original MIPS .pdata c04326ec..c04327db. Semantic name remains unreviewed. */

undefined4
FUN_c04326ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"CeCallUserProc");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c04327dc FUN_c04327dc */

/* Boundary evidence: original MIPS .pdata c04327dc..c043287b. Semantic name remains unreviewed. */

undefined4 FUN_c04327dc(undefined4 param_1)

{
  int iVar1;
  undefined4 local_20 [2];
  DWORD local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_20[0] = 0;
  local_18 = 0;
  local_14 = param_1;
  iVar1 = FUN_c0432630(0x51,60000);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_c04326ec(L"netui.dll",L"GetIPAddressExt",&local_18,0xc,&local_18,0xc,local_20),
     iVar1 != 0)) {
    if (local_18 == 0) {
      return local_10;
    }
    SetLastError(local_18);
  }
  return 0;
}



/* c043287c FUN_c043287c */

/* Boundary evidence: original MIPS .pdata c043287c..c0432907. Semantic name remains unreviewed. */

undefined4 FUN_c043287c(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  piVar1 = &DAT_c044d8b0;
  do {
    piVar2 = piVar1;
    if (*piVar2 == 0) goto LAB_c04328e4;
    piVar1 = (int *)*piVar2;
  } while ((int *)*piVar2 != param_1);
  uVar3 = 1;
  *piVar2 = *param_1;
LAB_c04328e4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  return uVar3;
}



/* c0432908 FUN_c0432908 */

/* Boundary evidence: original MIPS .pdata c0432908..c0432c03. Semantic name remains unreviewed. */

int FUN_c0432908(HKEY param_1,LPCWSTR param_2,undefined4 param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPDWORD lpType;
  LPBYTE lpData;
  int iVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  LPCWSTR lpValueName;
  DWORD DVar8;
  undefined4 *puVar9;
  HKEY local_res0;
  LPCWSTR local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  DWORD local_38;
  size_t local_34;
  DWORD local_30;
  LPCWSTR local_2c;
  
  iVar4 = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  local_2c = param_2;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar1 = RegOpenKeyExW(param_1,param_2,0,0x20019,&local_res0), LVar1 == 0)) {
    puVar6 = &local_res8;
    while (lpValueName = (LPCWSTR)*puVar6, lpValueName != (LPCWSTR)0x0) {
      DVar8 = puVar6[1];
      puVar9 = (undefined4 *)0x0;
      puVar5 = (uint *)0x0;
      uVar7 = puVar6[2] & 1;
      if (uVar7 == 0) {
        lpData = (LPBYTE)puVar6[3];
        if (DVar8 == 3) {
          puVar5 = (uint *)puVar6[4];
          local_38 = *puVar5;
        }
        else {
          local_38 = puVar6[4];
        }
      }
      else {
        local_38 = 0;
        puVar9 = (undefined4 *)puVar6[3];
        puVar5 = (uint *)puVar6[4];
        lpData = (LPBYTE)0x0;
      }
      puVar6 = puVar6 + 5;
      lpType = &local_30;
      uVar3 = 0;
      pWVar2 = lpValueName;
      LVar1 = RegQueryValueExW(local_res0,lpValueName,(LPDWORD)0x0,lpType,(LPBYTE)0x0,&local_34);
      if (((LVar1 == 0) || (LVar1 == 0xea)) && (local_30 == DVar8)) {
        if (uVar7 == 0) {
          if (local_38 < local_34) {
            lpData = (LPBYTE)0x0;
          }
        }
        else {
          lpData = FUN_c0434330(local_34,pWVar2,uVar3,lpType);
          if (lpData == (LPBYTE)0x0) goto LAB_c0432b88;
          local_38 = local_34;
        }
        if (lpData != (LPBYTE)0x0) {
          LVar1 = RegQueryValueExW(local_res0,lpValueName,(LPDWORD)0x0,(LPDWORD)0x0,lpData,&local_38
                                  );
          if (LVar1 == 0) {
            iVar4 = iVar4 + 1;
            if (DVar8 == 3) {
              *puVar5 = local_38;
            }
          }
          else if (uVar7 != 0) {
            FUN_c04343a4((int)lpData,local_34);
            lpData = (LPBYTE)0x0;
            local_38 = 0;
          }
        }
      }
LAB_c0432b88:
      if (uVar7 != 0) {
        if (puVar9 != (undefined4 *)0x0) {
          *puVar9 = lpData;
        }
        if (puVar5 != (uint *)0x0) {
          *puVar5 = local_38;
        }
      }
    }
    if (local_2c != (LPCWSTR)0x0) {
      RegCloseKey(local_res0);
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}



/* c0432c04 FUN_c0432c04 */

/* Boundary evidence: original MIPS .pdata c0432c04..c0432d8b. Semantic name remains unreviewed. */

int FUN_c0432c04(HKEY param_1,LPCWSTR param_2,undefined4 param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  LPCWSTR lpValueName;
  undefined4 *puVar2;
  DWORD *pDVar3;
  DWORD *pDVar4;
  int iVar5;
  undefined4 *puVar6;
  HKEY local_res0;
  LPCWSTR local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  DWORD aDStack_20 [2];
  
  iVar5 = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                              &local_res0,aDStack_20), LVar1 == 0)) {
    puVar6 = &local_res8;
    while (lpValueName = (LPCWSTR)*puVar6, lpValueName != (LPCWSTR)0x0) {
      pDVar4 = puVar6 + 1;
      puVar2 = puVar6 + 3;
      pDVar3 = puVar6 + 4;
      puVar6 = puVar6 + 5;
      LVar1 = RegSetValueExW(local_res0,lpValueName,0,*pDVar4,(BYTE *)*puVar2,*pDVar3);
      if (LVar1 == 0) {
        iVar5 = iVar5 + 1;
      }
    }
    if (param_2 != (LPCWSTR)0x0) {
      RegCloseKey(local_res0);
    }
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}



/* c0432d8c FUN_c0432d8c */

/* Boundary evidence: original MIPS .pdata c0432d8c..c0432eab. Semantic name remains unreviewed. */

void FUN_c0432d8c(int *param_1)

{
  HANDLE hHeap;
  
  if (param_1 != (int *)0x0) {
    FUN_c043287c(param_1);
    hHeap = (HANDLE)param_1[6];
    if ((HANDLE)param_1[0x333] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[0x333]);
    }
    if (param_1[0x1b] == 0) {
      LocalFree((HLOCAL)param_1[0x19]);
    }
    if ((int *)param_1[0x2ac] != (int *)0x0) {
      FUN_c04367a0((int *)param_1[0x2ac]);
    }
    if ((int *)param_1[0x2ab] != (int *)0x0) {
      FUN_c043bc64((int *)param_1[0x2ab]);
    }
    if ((int *)param_1[0x2aa] != (int *)0x0) {
      FUN_c043a1dc((int *)param_1[0x2aa]);
    }
    if (param_1[0x2a9] != 0) {
      FUN_c0445fa0(param_1[0x2a9]);
    }
    if ((HANDLE)param_1[0x16] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[0x16]);
    }
    if ((HANDLE)param_1[0x17] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[0x17]);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
    FUN_c0434420((int)param_1,(LPVOID)param_1[0x337]);
    FUN_c0434420((int)param_1,param_1);
    HeapDestroy(hHeap);
  }
  return;
}



/* c0432eac FUN_c0432eac */

/* Boundary evidence: original MIPS .pdata c0432eac..c0432fdf. Semantic name remains unreviewed. */

void FUN_c0432eac(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((*(int *)(param_1 + 0xb2c) != 0) &&
     (iVar1 = wcscmp((wchar_t *)(param_1 + 0x76c),L"vpn"), iVar1 == 0)) {
    *(uint *)(param_1 + 0x62c) = *(uint *)(param_1 + 0x62c) | 0x1800;
  }
  uVar2 = *(uint *)(param_1 + 0x62c);
  uVar3 = 0x1f;
  if ((uVar2 & 0x400) != 0) {
    uVar3 = 0x1e;
  }
  if (((uVar2 & 0x800) != 0) || ((uVar2 & 0x1000) != 0)) {
    uVar3 = uVar3 & 0xfffffffc;
  }
  if ((uVar2 & 0x40000) != 0) {
    uVar3 = uVar3 & 0xfffffffe;
  }
  if ((uVar2 & 0x80000) != 0) {
    uVar3 = uVar3 & 0xfffffffd;
  }
  if ((uVar2 & 0x100000) != 0) {
    uVar3 = uVar3 & 0xfffffffb;
  }
  if ((uVar2 & 0x200000) != 0) {
    uVar3 = uVar3 & 0xfffffff7;
  }
  if ((((uVar2 & 0x400000) != 0) || (*(int *)(param_1 + 0xa98) == 0)) || (DAT_c044d908 == 0)) {
    uVar3 = uVar3 & 0xffffffef;
  }
  *(uint *)(param_1 + 0xad4) = uVar3;
  return;
}



/* c0432fe0 FUN_c0432fe0 */

/* Boundary evidence: original MIPS .pdata c0432fe0..c043304f. Semantic name remains unreviewed. */

undefined4 FUN_c0432fe0(wchar_t *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)DAT_c044d8b0;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    iVar1 = wcscmp((wchar_t *)(piVar2 + 0x33c),param_1);
    if (iVar1 == 0) break;
    piVar2 = (int *)*piVar2;
  }
  return 1;
}



/* c0433050 FUN_c0433050 */

/* Boundary evidence: original MIPS .pdata c0433050..c0433157. Semantic name remains unreviewed. */

void FUN_c0433050(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  code *pcVar2;
  
  bVar1 = false;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  if ((*(int *)(param_1 + 0x24) != param_2) || (param_2 == 0)) {
    *(int *)(param_1 + 0x24) = param_2;
    bVar1 = true;
    *(undefined4 *)(param_1 + 0x28) = param_3;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  if (bVar1) {
    pcVar2 = *(code **)(param_1 + 0xaa0);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(param_1 + 0xa9c) == 1) {
        (*pcVar2)(param_1,0xcccd,param_2,param_3,0);
      }
      else if ((*(int *)(param_1 + 0xa9c) == -1) && (DAT_c044d8d8 != (code *)0x0)) {
        (*DAT_c044d8d8)(pcVar2,0xcccd,param_2,param_3);
      }
    }
    EventModify(*(undefined4 *)(param_1 + 0x58),3);
  }
  return;
}



/* c0433158 FUN_c0433158 */

uint * FUN_c0433158(int param_1,undefined2 *param_2)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar3 = *(uint *)(param_2 + 2);
  pbVar5 = *(byte **)(param_2 + 4);
  uVar6 = 0;
  if ((1 < uVar3) && (*pbVar5 == 0xff)) {
    if (pbVar5[1] != 3) goto LAB_c04331e4;
    uVar3 = uVar3 - 2;
    pbVar5 = pbVar5 + 2;
  }
  *(byte **)(param_2 + 6) = pbVar5;
  *(uint *)(param_2 + 8) = uVar3;
  if (uVar3 != 0) {
    uVar6 = 0;
    do {
      if ((uVar6 & 0xff00) != 0) break;
      bVar1 = *pbVar5;
      uVar6 = (uVar6 & 0xff) << 8 | (uint)bVar1;
      pbVar5 = pbVar5 + 1;
      uVar3 = uVar3 - 1;
      if ((bVar1 & 1) != 0) {
        *(byte **)(param_2 + 4) = pbVar5;
        *(uint *)(param_2 + 2) = uVar3;
        goto LAB_c04331e4;
      }
    } while (uVar3 != 0);
  }
  uVar6 = 0;
LAB_c04331e4:
  *param_2 = (short)uVar6;
  if (uVar6 != 0) {
    puVar2 = *(uint **)(param_1 + 0xcdc);
    puVar4 = puVar2 + *(int *)(param_1 + 0xce4) * 3;
    for (; puVar2 < puVar4; puVar2 = puVar2 + 3) {
      if (*puVar2 == uVar6) {
        return puVar2;
      }
    }
  }
  return (uint *)0x0;
}



/* c0433240 FUN_c0433240 */

/* Boundary evidence: original MIPS .pdata c0433240..c043327b. Semantic name remains unreviewed. */

void FUN_c0433240(int param_1,undefined2 *param_2)

{
  uint *puVar1;
  
  puVar1 = FUN_c0433158(param_1,param_2);
  if ((puVar1 != (uint *)0x0) && (*(code **)(puVar1[1] + 4) != (code *)0x0)) {
    (**(code **)(puVar1[1] + 4))(puVar1[2]);
  }
  return;
}



/* c043327c FUN_c043327c */

/* Boundary evidence: original MIPS .pdata c043327c..c04332ff. Semantic name remains unreviewed. */

void FUN_c043327c(int param_1,undefined2 *param_2)

{
  uint *puVar1;
  
  *(undefined4 *)(param_1 + 0xcd0) = 1;
  puVar1 = FUN_c0433158(param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    FUN_c043a54c(*(int **)(param_1 + 0xaa8),(int)param_2);
  }
  else {
    if (*(int *)(param_2 + 10) == 0) {
      *(undefined4 *)(param_2 + 10) = *(undefined4 *)(param_2 + 2);
    }
    (**(code **)puVar1[1])(puVar1[2],param_2);
  }
  return;
}



/* c0433300 FUN_c0433300 */

/* Boundary evidence: original MIPS .pdata c0433300..c043336b. Semantic name remains unreviewed. */

void FUN_c0433300(int param_1,int param_2)

{
  DWORD DVar1;
  int iVar2;
  
  *(int *)(param_1 + 0xb8c) = *(int *)(param_2 + 0x14) + *(int *)(param_1 + 0xb8c);
  *(int *)(param_1 + 0xb84) = *(int *)(param_2 + 4) + *(int *)(param_1 + 0xb84);
  *(int *)(param_1 + 0xb64) = *(int *)(param_1 + 0xb64) + 1;
  iVar2 = *(int *)(param_1 + 0xab0);
  *(int *)(param_1 + 0xb5c) = *(int *)(param_2 + 4) + *(int *)(param_1 + 0xb5c);
  DVar1 = GetTickCount();
  *(DWORD *)(iVar2 + 0x54) = DVar1;
  return;
}



/* c043336c FUN_c043336c */

/* Boundary evidence: original MIPS .pdata c043336c..c04333ff. Semantic name remains unreviewed. */

undefined4 FUN_c043336c(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  if ((param_1 != (int *)0x0) && (piVar1 = DAT_c044d8b0, DAT_c044d8b0 != (int *)0x0)) {
    do {
      if (piVar1 == param_1) break;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (piVar1 != (int *)0x0) {
      uVar2 = 1;
      param_1[5] = param_1[5] + 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  return uVar2;
}



/* c0433400 FUN_c0433400 */

/* Boundary evidence: original MIPS .pdata c0433400..c0433497. Semantic name remains unreviewed. */

undefined4 FUN_c0433400(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[5] + -1;
  param_1[5] = iVar2;
  if (iVar2 == 0) {
    FUN_c043287c(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  if (iVar2 == 0) {
    VEMDeviceDestroy(param_1[2]);
    if (param_1[0x2d1] == 0) {
      CTEIOControl(2,0,0,0,0,0);
    }
    FUN_c0432d8c(param_1);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0433498 FUN_c0433498 */

/* Boundary evidence: original MIPS .pdata c0433498..c04334cb. Semantic name remains unreviewed. */

void FUN_c0433498(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  FUN_c0433400(param_1);
  return;
}



/* c04334cc FUN_c04334cc */

/* Boundary evidence: original MIPS .pdata c04334cc..c0433553. Semantic name remains unreviewed. */

int * FUN_c04334cc(int param_1)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  piVar1 = DAT_c044d8b0;
  if (DAT_c044d8b0 != (int *)0x0) {
    do {
      if (piVar1[0x2a9] == param_1) break;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (piVar1 != (int *)0x0) {
      piVar1[5] = piVar1[5] + 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  return piVar1;
}



/* c0433554 FUN_c0433554 */

/* Boundary evidence: original MIPS .pdata c0433554..c04335a7. Semantic name remains unreviewed. */

int FUN_c0433554(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = CTEStopTimer(param_2);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
    FUN_c0433400(param_1);
  }
  return iVar1;
}



/* c04335a8 FUN_c04335a8 */

/* Boundary evidence: original MIPS .pdata c04335a8..c04335c3. Semantic name remains unreviewed. */

void FUN_c04335a8(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x40));
  return;
}



/* c04335c4 FUN_c04335c4 */

/* Boundary evidence: original MIPS .pdata c04335c4..c04335df. Semantic name remains unreviewed. */

void FUN_c04335c4(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x40));
  return;
}



/* c04335e0 FUN_c04335e0 */

/* Boundary evidence: original MIPS .pdata c04335e0..c0433763. Semantic name remains unreviewed. */

undefined4 FUN_c04335e0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  SIZE_T _Size;
  void *pvVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  if (*(uint *)(param_1 + 0xce0) <= *(uint *)(param_1 + 0xce4)) {
    iVar4 = *(uint *)(param_1 + 0xce0) + 0xf;
    _Size = iVar4 * 0xc;
    pvVar1 = (void *)FUN_c04343d0(param_1,_Size);
    if (pvVar1 == (void *)0x0) {
      return 0xe;
    }
    memset(pvVar1,0,_Size);
    memcpy(pvVar1,*(void **)(param_1 + 0xcdc),*(int *)(param_1 + 0xce0) * 0xc);
    FUN_c0434420(param_1,*(LPVOID *)(param_1 + 0xcdc));
    *(void **)(param_1 + 0xcdc) = pvVar1;
    *(int *)(param_1 + 0xce0) = iVar4;
  }
  uVar3 = 0;
  if (*(int *)(param_1 + 0xce4) != 0) {
    puVar2 = *(uint **)(param_1 + 0xcdc);
    do {
      if (param_2 <= *puVar2) break;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 3;
    } while (uVar3 < *(uint *)(param_1 + 0xce4));
  }
  iVar4 = uVar3 * 0xc;
  pvVar1 = (void *)(iVar4 + *(int *)(param_1 + 0xcdc));
  memmove((void *)((int)pvVar1 + 0xc),pvVar1,(*(int *)(param_1 + 0xce4) - uVar3) * 0xc);
  *(uint *)(iVar4 + *(int *)(param_1 + 0xcdc)) = param_2;
  *(undefined4 *)(iVar4 + *(int *)(param_1 + 0xcdc) + 4) = param_3;
  *(undefined4 *)(iVar4 + *(int *)(param_1 + 0xcdc) + 8) = param_4;
  *(int *)(param_1 + 0xce4) = *(int *)(param_1 + 0xce4) + 1;
  return 0;
}



/* c0433764 FUN_c0433764 */

/* Boundary evidence: original MIPS .pdata c0433764..c043389b. Semantic name remains unreviewed. */

undefined4 FUN_c0433764(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  FUN_c0433050((int)param_1,0,0);
  iVar1 = FUN_c0445bd0((int *)param_1[0x2a9],(uint *)(param_1 + 0x18b),param_1 + 0x1d);
  if (iVar1 == 0) {
    if (((0 < param_1[8]) && (param_1[8] < 3)) && (param_1[0x1d4] == 0)) {
      iVar1 = FUN_c04327dc(0);
      if (iVar1 == 0) {
        iVar1 = 0x2d9;
        goto LAB_c0433810;
      }
      param_1[0x1d4] = iVar1;
    }
    uVar4 = 0;
    uVar3 = 3;
    FUN_c0433050((int)param_1,3,0);
    if (param_1[0x15] == 0) {
      FUN_c0446860((int)param_1,uVar3,uVar4,param_4);
    }
    DVar2 = GetTickCount();
    param_1[0x2d4] = DVar2;
  }
  else {
LAB_c0433810:
    if (param_1[0x15] != 0) {
      iVar1 = 0;
    }
    FUN_c0433050((int)param_1,0x2001,iVar1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  FUN_c0433400(param_1);
  return 0;
}



/* c043389c FUN_c043389c */

/* Boundary evidence: original MIPS .pdata c043389c..c04338eb. Semantic name remains unreviewed. */

void FUN_c043389c(int *param_1)

{
  if (param_1[0x1c] == 0) {
    param_1[0x1c] = 1;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
    FUN_c0433400(param_1);
  }
  FUN_c0434580(param_1 + 0x2e4);
  return;
}



/* c04338ec FUN_c04338ec */

/* Boundary evidence: original MIPS .pdata c04338ec..c0433913. Semantic name remains unreviewed. */

void FUN_c04338ec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0445f84(*(int **)(param_1 + 0xaa4),FUN_c043389c,param_1,param_4);
  return;
}



/* c0433914 FUN_c0433914 */

/* Boundary evidence: original MIPS .pdata c0433914..c0433a33. Semantic name remains unreviewed. */

int FUN_c0433914(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x40);
  EnterCriticalSection(lpCriticalSection);
  iVar2 = *(int *)(param_1 + 0xb90);
  iVar1 = FUN_c0434508((int *)(param_1 + 0xb90),param_2,param_3,param_4);
  if ((iVar1 == 0) && (iVar2 == 0)) {
    iVar2 = wcsncmp(L"L2TP",(wchar_t *)(param_1 + 0x78e),4);
    if ((iVar2 == 0) && (*(int *)(param_1 + 0x24) == 0)) {
      LeaveCriticalSection(lpCriticalSection);
      FUN_c0445f14(*(int *)(param_1 + 0xaa4));
      EnterCriticalSection(lpCriticalSection);
    }
    *(undefined4 *)(param_1 + 0x54) = 1;
    FUN_c0445f40(*(int *)(param_1 + 0xaa4));
    if (*(int *)(param_1 + 0x20) == 0) {
      FUN_c0439d7c(*(int **)(param_1 + 0xaa8),FUN_c04338ec,param_1);
    }
    else {
      FUN_c0445f84(*(int **)(param_1 + 0xaa4),FUN_c043389c,param_1,param_4);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* c0433a34 FUN_c0433a34 */

/* Boundary evidence: original MIPS .pdata c0433a34..c0433a83. Semantic name remains unreviewed. */

void FUN_c0433a34(int *param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 4);
  FUN_c0433300((int)param_1,param_2);
  FUN_c0434ccc(param_1,param_2,1);
  return;
}



/* c0433a84 FUN_c0433a84 */

/* Boundary evidence: original MIPS .pdata c0433a84..c0433b13. Semantic name remains unreviewed. */

void FUN_c0433a84(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 != 0) {
    FUN_c0433554(param_1,param_2);
    iVar1 = CTEStartTimer(param_2,param_3,param_4,param_5);
    if (iVar1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
      FUN_c0433400(param_1);
    }
  }
  return;
}



/* c0433b14 FUN_c0433b14 */

/* Boundary evidence: original MIPS .pdata c0433b14..c043422b. Semantic name remains unreviewed. */

int FUN_c0433b14(undefined4 *param_1)

{
  HANDLE pvVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  STRSAFE_LPWSTR _Dest;
  uint *puVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  wchar_t awStack_70 [32];
  uint local_30;
  
  local_30 = DAT_c044d82c;
  piVar7 = (int *)0x0;
  CTEInitialize();
  pvVar1 = HeapCreate(0,0x19000,0x32000);
  iVar5 = 8;
  if (pvVar1 != (HANDLE)0x0) {
    piVar7 = HeapAlloc(pvVar1,8,0xdf4);
    if (piVar7 == (int *)0x0) {
      HeapDestroy(pvVar1);
    }
    else {
      iVar3 = param_1[5];
      iVar5 = wcscmp((wchar_t *)(iVar3 + 0x786),L"Cellular Line");
      if (iVar5 == 0) {
        iVar5 = 1;
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
        do {
          if (iVar5 == 1) {
            StringCchCopyW(awStack_70,0x20,L"Cellular Line");
          }
          else {
            StringCchPrintfW(awStack_70,0x20,L"Cellular Line %u",iVar5);
          }
          iVar5 = iVar5 + 1;
          iVar3 = FUN_c0432fe0(awStack_70);
        } while (iVar3 != 0);
        _Dest = (STRSAFE_LPWSTR)(piVar7 + 0x33c);
        wcscpy(_Dest,awStack_70);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
      }
      else {
        _Dest = (STRSAFE_LPWSTR)(piVar7 + 0x33c);
        StringCchCopyW(_Dest,0x81,(wchar_t *)(iVar3 + 0x786));
      }
      for (; *_Dest != L'\0'; _Dest = _Dest + 1) {
        if (*_Dest == L'\\') {
          *_Dest = L'-';
        }
      }
      piVar7[6] = (int)pvVar1;
      piVar7[7] = 0xdf4;
      piVar7[5] = 1;
      piVar7[0x1c] = 0;
      piVar7[0x19] = param_1[6];
      piVar7[0x1a] = param_1[7];
      piVar7[0x1b] = param_1[8];
      param_1[6] = 0;
      InitializeCriticalSection((LPCRITICAL_SECTION)(piVar7 + 0x10));
      InitializeCriticalSection((LPCRITICAL_SECTION)(piVar7 + 0xb));
      piVar2 = piVar7 + 3;
      piVar7[4] = (int)piVar2;
      *piVar2 = (int)piVar2;
      CTEInitTimer(piVar7 + 0x2e9);
      piVar7[0x2e7] = 0xfa;
      piVar7[0x2b0] = 2;
      piVar7[0x2af] = 10;
      piVar7[0x2b2] = 5;
      piVar7[0x2b6] = 10;
      piVar7[0x2ca] = -1;
      piVar7[0x2b4] = 0x40;
      piVar2 = piVar7 + 0x2b1;
      piVar7[0x2e5] = 3;
      *piVar2 = 3;
      piVar7[0x2b3] = 1;
      piVar7[0x2cc] = 1;
      piVar7[0x2ce] = 1;
      piVar7[0x2b7] = 3;
      piVar9 = piVar7 + 0x2cf;
      piVar8 = piVar7 + 0x2d0;
      piVar7[0x2cb] = 0;
      piVar7[0x2cd] = 0;
      *piVar9 = 0;
      *piVar8 = 0;
      piVar7[0x2d1] = 0;
      piVar7[0x2d2] = 0;
      piVar7[0x2d3] = 0;
      FUN_c0432908((HKEY)0x80000002,L"Comm\\ppp\\Parms",L"MaxConfigure",4);
      *piVar2 = *piVar2 * 1000;
      if ((*piVar9 != 0) && (*piVar8 != 0)) {
        *piVar9 = 0;
        *piVar8 = 0;
      }
      piVar7[0x2e4] = 0;
      pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      piVar7[0x16] = (int)pvVar1;
      pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      piVar7[0x17] = (int)pvVar1;
      if ((piVar7[0x16] == 0) || (pvVar1 == (HANDLE)0x0)) {
        iVar5 = 0x25f;
      }
      else {
        puVar6 = (uint *)(piVar7 + 0x18b);
        FUN_c04428f4((int *)param_1[5],(int *)puVar6);
        FUN_c0432eac((int)piVar7);
        if ((piVar7[0x2cc] != 0) && (iVar5 = wcscmp((wchar_t *)(piVar7 + 0x1db),L"vpn"), iVar5 == 0)
           ) {
          *puVar6 = *puVar6 | 0x10;
        }
        if (piVar7[0x1da] == 2) {
          piVar7[8] = 1;
          pcVar4 = FUN_c0433a34;
          piVar7[0x2ae] = 0x3ee;
        }
        else {
          pcVar4 = FUN_c043327c;
          piVar7[8] = 0;
        }
        piVar7[0x33a] = (int)pcVar4;
        piVar7[0x2a7] = param_1[2];
        piVar7[0x2a8] = param_1[3];
        piVar7[9] = 0;
        if ((void *)param_1[4] != (void *)0x0) {
          memcpy(piVar7 + 0x1d,(void *)param_1[4],0x5b8);
          FUN_c044239c((int)(piVar7 + 0x1d));
        }
        iVar5 = FUN_c044603c(piVar7,piVar7 + 0x2a9,(STRSAFE_LPCWSTR)((int)piVar7 + 0x78e),
                             (STRSAFE_LPCWSTR)(piVar7 + 0x1db));
        if ((((iVar5 == 0) && (iVar5 = FUN_c0439fb8((int)piVar7,piVar7 + 0x2aa), iVar5 == 0)) &&
            (iVar5 = FUN_c043bb08((int)piVar7,piVar7 + 0x2ab), iVar5 == 0)) &&
           (iVar5 = FUN_c0436878((int)piVar7,piVar7 + 0x2ac), iVar5 == 0)) {
          *param_1 = piVar7;
          piVar7[1] = piVar7[1] | 1;
          if (piVar7[0x2d1] == 0) {
            CTEIOControl(1,0,0,0,0,0);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
          *piVar7 = (int)DAT_c044d8b0;
          DAT_c044d8b0 = piVar7;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
          goto LAB_c04341f0;
        }
      }
    }
  }
  FUN_c0432d8c(piVar7);
LAB_c04341f0:
  FUN_c0449d30(local_30);
  return iVar5;
}



/* c043422c FUN_c043422c */

/* Boundary evidence: original MIPS .pdata c043422c..c043432f. Semantic name remains unreviewed. */

DWORD FUN_c043422c(LPVOID param_1)

{
  HANDLE hObject;
  DWORD DVar1;
  int iVar2;
  
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0433764,param_1,0,(LPDWORD)0x0);
  *(HANDLE *)((int)param_1 + 0x60) = hObject;
  if (hObject == (HANDLE)0x0) {
    DVar1 = GetLastError();
  }
  else {
    CloseHandle(hObject);
    DVar1 = 0;
    if (*(int *)((int)param_1 + 0xaa0) == 0) {
      iVar2 = *(int *)((int)param_1 + 0x24);
      while ((iVar2 != 0x2000 && (iVar2 != 0x2001))) {
        WaitForSingleObject(*(HANDLE *)((int)param_1 + 0x58),0xffffffff);
        iVar2 = *(int *)((int)param_1 + 0x24);
      }
      if (*(int *)((int)param_1 + 0x24) != 0x2000) {
        if (*(int *)((int)param_1 + 0x24) == 0x2001) {
          DVar1 = *(DWORD *)((int)param_1 + 0x28);
          if (DVar1 == 0) {
            DVar1 = 0x277;
          }
        }
        else {
          DVar1 = 0x27b;
        }
      }
    }
  }
  return DVar1;
}



/* c0434330 FUN_c0434330 */

/* Boundary evidence: original MIPS .pdata c0434330..c04343a3. Semantic name remains unreviewed. */

void * FUN_c0434330(size_t param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  void *local_10 [2];
  
  iVar1 = NdisAllocateMemory(local_10,param_1,0,param_4,DAT_c044d250,DAT_c044d254);
  if (iVar1 == 0) {
    memset(local_10[0],0,param_1);
  }
  else {
    local_10[0] = (void *)0x0;
  }
  return local_10[0];
}



/* c04343a4 FUN_c04343a4 */

/* Boundary evidence: original MIPS .pdata c04343a4..c04343cf. Semantic name remains unreviewed. */

void FUN_c04343a4(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    NdisFreeMemory(param_1,param_2,0);
  }
  return;
}



/* c04343d0 FUN_c04343d0 */

/* Boundary evidence: original MIPS .pdata c04343d0..c043441f. Semantic name remains unreviewed. */

void FUN_c04343d0(int param_1,SIZE_T param_2)

{
  LPVOID pvVar1;
  
  pvVar1 = HeapAlloc(*(HANDLE *)(param_1 + 0x18),8,param_2);
  if (pvVar1 != (LPVOID)0x0) {
    *(SIZE_T *)(param_1 + 0x1c) = param_2 + *(int *)(param_1 + 0x1c);
  }
  return;
}



/* c0434420 FUN_c0434420 */

/* Boundary evidence: original MIPS .pdata c0434420..c043444b. Semantic name remains unreviewed. */

BOOL FUN_c0434420(int param_1,LPVOID param_2)

{
  BOOL BVar1;
  
  BVar1 = 1;
  if (param_2 != (LPVOID)0x0) {
    BVar1 = HeapFree(*(HANDLE *)(param_1 + 0x18),0,param_2);
  }
  return BVar1;
}



/* c043444c FUN_c043444c */

byte * FUN_c043444c(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  for (pbVar2 = param_1; *pbVar2 != 0; pbVar2 = pbVar2 + 1) {
    bVar1 = *pbVar2;
    if ((0x60 < bVar1) && (bVar1 < 0x7b)) {
      *pbVar2 = bVar1 - 0x20;
    }
  }
  return param_1;
}



/* c0434494 FUN_c0434494 */

uint FUN_c0434494(int param_1)

{
  uint uVar1;
  
  if ((param_1 < 0x30) || (0x39 < param_1)) {
    if ((param_1 < 0x41) || (0x46 < param_1)) {
      if ((param_1 < 0x61) || (0x66 < param_1)) {
        return 0xff;
      }
      uVar1 = param_1 + 0xa9;
    }
    else {
      uVar1 = param_1 + 0xc9;
    }
  }
  else {
    uVar1 = param_1 + 0xd0;
  }
  return uVar1 & 0xff;
}



/* c0434508 FUN_c0434508 */

/* Boundary evidence: original MIPS .pdata c0434508..c043457f. Semantic name remains unreviewed. */

undefined4 FUN_c0434508(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    puVar1 = FUN_c0434330(0xc,param_2,param_3,param_4);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0xe;
    }
    else {
      *puVar1 = *param_1;
      puVar1[1] = param_2;
      puVar1[2] = param_3;
      *param_1 = puVar1;
    }
  }
  return uVar2;
}



/* c0434580 FUN_c0434580 */

/* Boundary evidence: original MIPS .pdata c0434580..c04345f7. Semantic name remains unreviewed. */

void FUN_c0434580(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    (*(code *)piVar1[1])(piVar1[2]);
    NdisFreeMemory(piVar1,0xc,0);
    piVar1 = (int *)iVar2;
  }
  *param_1 = 0;
  return;
}



/* c04345f8 FUN_c04345f8 */

/* Boundary evidence: original MIPS .pdata c04345f8..c043480f. Semantic name remains unreviewed. */

undefined4
FUN_c04345f8(int param_1,int param_2,void *param_3,uint param_4,size_t *param_5,size_t *param_6)

{
  size_t sVar1;
  code *pcVar2;
  int iVar3;
  size_t *psVar4;
  size_t *psVar5;
  size_t *psVar6;
  uint uVar7;
  undefined4 uVar8;
  size_t local_30;
  void *local_2c;
  
  uVar8 = 0;
  uVar7 = param_4;
  local_2c = param_3;
  if (((DAT_c044d89c != (HMODULE)0x0) ||
      (DAT_c044d89c = LoadLibraryW(L"iphlpapi.dll"), DAT_c044d89c != (HMODULE)0x0)) &&
     (pcVar2 = (code *)GetProcAddressW(DAT_c044d89c,L"GetAdaptersInfo"), pcVar2 != (code *)0x0)) {
    psVar4 = &local_30;
    local_30 = 0;
    iVar3 = (*pcVar2)(0);
    if (iVar3 != 0xe8) {
      if (iVar3 == 0) {
        if (local_30 == 0) {
          return 0;
        }
      }
      else if (iVar3 != 0x6f) {
        return 0;
      }
      psVar4 = FUN_c0434330(local_30,psVar4,param_3,uVar7);
      if (psVar4 != (size_t *)0x0) {
        iVar3 = (*pcVar2)(psVar4,&local_30);
        sVar1 = local_30;
        psVar6 = psVar4;
        psVar5 = (size_t *)local_30;
        if (iVar3 == 0) {
          while (psVar5 != (size_t *)0x0) {
            uVar7 = psVar6[100];
            if (((1 << (uVar7 & 0x1f) & param_4) != 0) &&
               ((param_2 == 0 ||
                (((psVar6[0x69] != 0 && ((char)psVar6[0x80] != '\0')) &&
                 (iVar3 = memcmp(psVar6 + 0x80,"255.255.255.255",0xf), iVar3 != 0)))))) {
              psVar5 = psVar6 + 0x65;
              while (uVar7 != 0) {
                uVar7 = uVar7 - 1;
                if ((char)*psVar5 != '\0') {
                  if (param_1 == 0) {
                    *param_5 = psVar6[100];
                    memcpy(local_2c,psVar6 + 0x65,psVar6[100]);
                    if (param_6 != (size_t *)0x0) {
                      *param_6 = psVar6[0x67];
                    }
                    uVar8 = 1;
                    goto LAB_c04347c4;
                  }
                  param_1 = param_1 + -1;
                  break;
                }
                psVar5 = (size_t *)((int)psVar5 + 1);
              }
            }
            psVar6 = (size_t *)*psVar6;
            psVar5 = psVar6;
          }
        }
LAB_c04347c4:
        NdisFreeMemory(psVar4,sVar1,0);
      }
    }
  }
  return uVar8;
}



/* c0434810 FUN_c0434810 */

/* Boundary evidence: original MIPS .pdata c0434810..c043483b. Semantic name remains unreviewed. */

void FUN_c0434810(int param_1,void *param_2,size_t *param_3)

{
  FUN_c04345f8(param_1,0,param_2,0x140,param_3,(size_t *)0x0);
  return;
}



/* c043483c FUN_c043483c */

/* Boundary evidence: original MIPS .pdata c043483c..c0434923. Semantic name remains unreviewed. */

undefined4 FUN_c043483c(void *param_1,uint *param_2)

{
  int iVar1;
  size_t _Size;
  undefined4 uVar2;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 auStack_98 [104];
  undefined1 auStack_30 [16];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  local_a0 = 0x107;
  local_9c = 0x10;
  iVar1 = KernelIoControl(0x1010004,&local_a0,4,auStack_98,0x10,&local_9c);
  if (iVar1 == 0) {
    *param_2 = 0;
    uVar2 = 0;
  }
  else {
    FUN_c04497b8();
    FUN_c04497a8();
    FUN_c0449798();
    _Size = *param_2;
    if (0x10 < _Size) {
      _Size = 0x10;
    }
    memcpy(param_1,auStack_30,_Size);
    *param_2 = _Size;
    uVar2 = 1;
  }
  FUN_c0449d30(local_20);
  return uVar2;
}



/* c0434924 FUN_c0434924 */

/* Boundary evidence: original MIPS .pdata c0434924..c0434a27. Semantic name remains unreviewed. */

int FUN_c0434924(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int *piVar7;
  
  puVar5 = (uint *)(param_3 + 0xc);
  uVar1 = *(ushort *)(param_2 + 0xc);
  piVar3 = *(int **)(param_2 + 8);
  sVar2 = *(short *)(param_2 + 0xe);
  iVar4 = *(int *)(param_3 + 8) + 8;
  piVar7 = *(int **)(param_1 + 0xaa4);
  iVar6 = 0;
  *(int *)(param_3 + 8) = iVar4;
  *puVar5 = *puVar5 - 8;
  iVar4 = FUN_c0446e88(piVar3,(uint)uVar1,iVar4,puVar5);
  if (iVar4 == 0) {
    FUN_c04476a0((int)piVar7,param_3);
    iVar6 = -0x3ffefff1;
  }
  else if (*(int *)(param_1 + 0x20) == 0) {
    iVar4 = 1;
    if (sVar2 != 4) {
      iVar4 = 2;
    }
    iVar6 = FUN_c04367f4(*(int *)(param_1 + 0xab0),param_3,iVar4);
    if (iVar6 != 0) {
      FUN_c04476a0((int)piVar7,param_3);
    }
  }
  else if (*(int *)(param_1 + 0x20) == 1) {
    iVar6 = FUN_c0446f50(piVar7,0,param_3);
  }
  return iVar6;
}



/* c0434a28 FUN_c0434a28 */

/* Boundary evidence: original MIPS .pdata c0434a28..c0434af3. Semantic name remains unreviewed. */

int FUN_c0434a28(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 == 0) {
    iVar1 = -0x3ffefff1;
  }
  else {
    FUN_c04335a8((int)param_1);
    iVar1 = FUN_c04476cc(param_1[0x2a9]);
    if (iVar1 == 0) {
      iVar1 = -0x3fffffff;
      if (param_2 != 0) {
        *param_3 = param_1 + 3;
        iVar1 = 0x103;
        param_3[1] = param_1[4];
        *(undefined4 **)param_1[4] = param_3;
        param_1[4] = (int)param_3;
      }
    }
    else {
      iVar1 = FUN_c0434924((int)param_1,(int)param_3,iVar1);
    }
    FUN_c04335c4((int)param_1);
    FUN_c0433498(param_1);
  }
  return iVar1;
}



/* c0434af4 FUN_c0434af4 */

/* Boundary evidence: original MIPS .pdata c0434af4..c0434b8f. Semantic name remains unreviewed. */

void FUN_c0434af4(void)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  piVar1 = (int *)DAT_c044d8b0;
  do {
    if (piVar1 == (int *)0x0) {
LAB_c0434b6c:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
      FUN_c0435dec(uVar2);
      return;
    }
    if (((piVar1[1] & 2U) != 0) && (piVar1[8] == 0)) {
      uVar2 = 0;
      if (*(int *)(piVar1[0x2ac] + 0x24) != 0) {
        uVar2 = *(uint *)(*(int *)(piVar1[0x2ac] + 0x24) + 0x30);
      }
      goto LAB_c0434b6c;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



/* c0434b90 FUN_c0434b90 */

/* Boundary evidence: original MIPS .pdata c0434b90..c0434bd3. Semantic name remains unreviewed. */

void FUN_c0434b90(int *param_1,int param_2,undefined4 param_3,undefined2 param_4,int param_5)

{
  undefined2 uVar1;
  
  *(undefined4 *)(param_2 + 0x28) = param_3;
  *(undefined2 *)(param_2 + 0x2c) = param_4;
  if (param_5 == 1) {
    uVar1 = 4;
  }
  else {
    uVar1 = 6;
  }
  *(undefined2 *)(param_2 + 0x2e) = uVar1;
  FUN_c0434a28(param_1,param_2,(undefined4 *)(param_2 + 0x20));
  return;
}



/* c0434bd4 FUN_c0434bd4 */

/* Boundary evidence: original MIPS .pdata c0434bd4..c0434c3b. Semantic name remains unreviewed. */

undefined4 * FUN_c0434bd4(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xab4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_c04343d0(param_1,*(int *)(param_1 + 0xab8) + 0xc);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1[1] = *(undefined4 *)(param_1 + 0xab8);
  }
  else {
    *(undefined4 *)(param_1 + 0xab4) = *puVar1;
    *puVar1 = 0;
  }
  return puVar1 + 2;
}



/* c0434c3c FUN_c0434c3c */

/* Boundary evidence: original MIPS .pdata c0434c3c..c0434ccb. Semantic name remains unreviewed. */

undefined4 FUN_c0434c3c(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int local_10 [2];
  
  NdisUnchainBufferAtFront(param_2,local_10);
  iVar2 = 0;
  if (local_10[0] != 0) {
    iVar2 = *(int *)(local_10[0] + 4);
  }
  piVar1 = (int *)(iVar2 + -8);
  if (*(uint *)(iVar2 + -4) < (uint)param_1[0x2ae]) {
    FUN_c0434420((int)param_1,piVar1);
  }
  else {
    *piVar1 = param_1[0x2ad];
    param_1[0x2ad] = (int)piVar1;
  }
  VEMFreeNDISBuffer(param_1[2],local_10[0]);
  FUN_c0433498(param_1);
  return 0;
}



/* c0434ccc FUN_c0434ccc */

/* Boundary evidence: original MIPS .pdata c0434ccc..c0434eab. Semantic name remains unreviewed. */

void FUN_c0434ccc(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *_Dst;
  
  iVar5 = param_1[2];
  piVar4 = (int *)0x0;
  _Dst = (undefined4 *)0x0;
  if ((((param_3 != 1) || (param_1[0x2f0] == 0)) ||
      (iVar1 = FUN_c04364cc((int)param_1,*(char **)(param_2 + 8),*(uint *)(param_2 + 4)), iVar1 == 0
      )) && ((iVar5 != 0 && (*(uint *)(param_2 + 4) <= (uint)param_1[0x2ae])))) {
    iVar1 = VEMGetNDISPacket(iVar5);
    if (iVar1 != 0) {
      _Dst = FUN_c0434bd4((int)param_1);
      if (_Dst != (undefined4 *)0x0) {
        memcpy(_Dst,*(void **)(param_2 + 8),*(size_t *)(param_2 + 4));
        piVar4 = (int *)VEMGetNDISBuffer(iVar5,_Dst,*(undefined4 *)(param_2 + 4));
        if (piVar4 != (int *)0x0) {
          iVar2 = *piVar4;
          piVar3 = piVar4;
          while (iVar2 != 0) {
            piVar3 = (int *)*piVar3;
            iVar2 = *piVar3;
          }
          if (*(int *)(iVar1 + 8) == 0) {
            *(int **)(iVar1 + 8) = piVar4;
          }
          else {
            **(undefined4 **)(iVar1 + 0xc) = piVar4;
          }
          *(int **)(iVar1 + 0xc) = piVar3;
          *piVar3 = 0;
          *(undefined1 *)(iVar1 + 0x1c) = 0;
          FUN_c043336c(param_1);
          FUN_c04335c4((int)param_1);
          iVar2 = VEMReceivePacket(iVar5,iVar1,param_3);
          FUN_c04335a8((int)param_1);
          if (iVar2 == 0) {
            return;
          }
          FUN_c0433498(param_1);
        }
      }
      if (iVar1 != 0) {
        VEMFreeNDISPacket(iVar5,iVar1);
      }
    }
    if (piVar4 != (int *)0x0) {
      VEMFreeNDISBuffer(iVar5,piVar4);
    }
    if (_Dst != (undefined4 *)0x0) {
      piVar4 = _Dst + -2;
      if ((uint)_Dst[-1] < (uint)param_1[0x2ae]) {
        FUN_c0434420((int)param_1,piVar4);
      }
      else {
        *piVar4 = param_1[0x2ad];
        param_1[0x2ad] = (int)piVar4;
      }
    }
  }
  return;
}



/* c0434eac FUN_c0434eac */

/* Boundary evidence: original MIPS .pdata c0434eac..c0434eef. Semantic name remains unreviewed. */

undefined4 FUN_c0434eac(int param_1,uint *param_2)

{
  uint local_10 [2];
  
  FUN_c0446024(*(int *)(param_1 + 0xaa4),(int *)local_10);
  *param_2 = local_10[0] / 100;
  return 0;
}



/* c0434f50 FUN_c0434f50 */

/* Boundary evidence: original MIPS .pdata c0434f50..c04350d7. Semantic name remains unreviewed. */

undefined4 FUN_c0434f50(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_68;
  uint local_64;
  undefined4 local_60;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined4 local_5a;
  undefined1 local_56;
  undefined1 local_55;
  code *local_40;
  code *local_3c;
  code *local_38;
  undefined *local_34;
  undefined4 local_30;
  uint local_24;
  int aiStack_20 [4];
  
  aiStack_20[2] = DAT_c044d82c;
  iVar2 = *(int *)(param_1 + 0x20);
  uVar4 = 0;
  if (iVar2 == 0) {
    uVar4 = (uint)*(ushort *)(*(int *)(param_1 + 0xaa8) + 0x30);
  }
  else if ((0 < iVar2) && (iVar2 < 3)) {
    uVar4 = 0x3ee;
  }
  memset(&local_68,0,0x50);
  uVar3 = 0x4c;
  local_68 = 0;
  local_64 = 0x4c;
  if ((*(int *)(param_1 + 0x6c) != 0) ||
     ((*(int *)(param_1 + 0xb38) == 0 && ((*(uint *)(param_1 + 0x62c) & 0x10) == 0)))) {
    uVar3 = 0x5c;
    local_64 = 0x5c;
  }
  local_5c = 0x4c;
  local_60 = 0x53415220;
  local_5a = 0x53415220;
  local_55 = 0x73;
  local_5b = 0x73;
  local_56 = 0x50;
  if (*(int *)(param_1 + 0x6c) == 0) {
    local_5b = 99;
    local_55 = 99;
  }
  if ((*(uint *)(param_1 + 0x62c) & 0x10) != 0) {
    local_64 = uVar3 | 0x20;
  }
  local_3c = FUN_c0434c3c;
  local_40 = FUN_c0434b90;
  local_38 = FUN_c0439bb8;
  local_34 = &DAT_c044d258;
  local_30 = DAT_c044d27c;
  local_24 = uVar4;
  FUN_c0446024(*(int *)(param_1 + 0xaa4),aiStack_20);
  aiStack_20[1] = 0;
  uVar1 = VEMDeviceCreate(param_1 + 0xcf0,&local_68,param_1,param_1 + 8);
  FUN_c0449d30(aiStack_20[2]);
  return uVar1;
}



/* c04350d8 FUN_c04350d8 */

/* Boundary evidence: original MIPS .pdata c04350d8..c04351d3. Semantic name remains unreviewed. */

void FUN_c04350d8(LPCSTR param_1)

{
  LSTATUS LVar1;
  size_t sVar2;
  HKEY local_220 [2];
  WCHAR aWStack_218 [262];
  uint local_c;
  
  local_c = DAT_c044d82c;
  if (*param_1 != '\0') {
    memset(aWStack_218,0,0x20a);
    MultiByteToWideChar(1,0,param_1,-1,aWStack_218,0x104);
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Tcpip\\Parms",0,0,local_220);
    if (LVar1 == 0) {
      sVar2 = wcslen(aWStack_218);
      RegSetValueExW(local_220[0],L"DNSDomain",0,1,(BYTE *)aWStack_218,(sVar2 + 1) * 2);
      RegCloseKey(local_220[0]);
    }
  }
  FUN_c0449d30(local_c);
  return;
}



/* c04351d4 FUN_c04351d4 */

/* Boundary evidence: original MIPS .pdata c04351d4..c04352df. Semantic name remains unreviewed. */

void FUN_c04351d4(int param_1,wchar_t *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  memcpy(param_3,u_TCPIP_c044d280,0xe);
  iVar1 = wcscmp(param_2,L"IPV6Protocols");
  if (iVar1 == 0) {
    memcpy(param_3,u_TCPIP6_c044d290,0x10);
  }
  uVar4 = 0;
  uVar3 = 0x208;
  uVar2 = 0;
  FUN_c0432908((HKEY)0x80000002,L"Comm\\PPP\\Parms",param_2,7);
  StringCchPrintfW(awStack_228,0x104,L"Comm\\PPP\\Parms\\Line\\%s",param_1 + 0x78e,uVar2,param_3,
                   uVar3,uVar4);
  FUN_c0432908((HKEY)0x80000002,awStack_228,param_2,7);
  FUN_c0449d30(local_20);
  return;
}



/* c04352e0 FUN_c04352e0 */

/* Boundary evidence: original MIPS .pdata c04352e0..c0435397. Semantic name remains unreviewed. */

void FUN_c04352e0(int param_1,uint *param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x20);
  iVar3 = *(int *)(*(int *)(param_1 + 0xab0) + 0x24);
  if (iVar1 == 0) {
    local_8 = *(uint *)(iVar3 + 0x20);
    uVar4 = *(uint *)(iVar3 + 0x30);
    if ((uVar4 != 0) && (uVar4 != local_8)) goto LAB_c0435338;
  }
  else {
    uVar4 = local_8;
    if ((iVar1 < 1) || (2 < iVar1)) goto LAB_c0435338;
    local_8 = *(uint *)(param_1 + 0x750);
  }
  uVar4 = local_8;
LAB_c0435338:
  if (*(int *)(param_1 + 0x6c) == 0) {
    if (local_8 >> 0x18 < 0x80) {
      uVar2 = 0xff000000;
    }
    else if (local_8 >> 0x18 < 0xc0) {
      uVar2 = 0xffff0000;
    }
    else {
      uVar2 = 0xffffff00;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  *param_2 = local_8;
  *param_3 = uVar2;
  *param_4 = uVar4;
  return;
}



/* c0435398 FUN_c0435398 */

/* Boundary evidence: original MIPS .pdata c0435398..c0435523. Semantic name remains unreviewed. */

int FUN_c0435398(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_230;
  uint local_22c;
  uint local_228 [2];
  undefined1 auStack_220 [520];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  iVar3 = 0;
  FUN_c04350d8((LPCSTR)(param_1 + 0xbc4));
  if (((*(uint *)(param_1 + 4) & 2) == 0) &&
     ((*(int *)(param_1 + 8) != 0 || (iVar3 = FUN_c0434f50(param_1), iVar3 == 0)))) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xab0) + 0x24);
    local_230 = 0;
    if (iVar2 != 0) {
      local_230 = *(uint *)(iVar2 + 0x30);
    }
    if (local_230 != 0) {
      FUN_c0435dec(local_230);
    }
    FUN_c04352e0(param_1,local_228,&local_22c,&local_230);
    if (((*(uint *)(param_1 + 0x62c) & 0x10) != 0) && (*(int *)(param_1 + 0xb34) == 0)) {
      local_22c = 0xffffffff;
    }
    uVar1 = local_230;
    if ((local_228[0] & local_22c) != (local_22c & local_230)) {
      uVar1 = local_228[0];
    }
    VEMSetIPConfig(*(undefined4 *)(param_1 + 8),local_228[0],local_22c,uVar1,
                   *(undefined4 *)(param_1 + 0x754),*(undefined4 *)(param_1 + 0x758));
    VEMSetWINSConfig(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x75c),
                     *(undefined4 *)(param_1 + 0x760));
    VEMSetDomain(*(undefined4 *)(param_1 + 8),(LPCSTR)(param_1 + 0xbc4));
    FUN_c04351d4(param_1,L"IPV4Protocols",auStack_220);
    VEMSetMediaState(*(undefined4 *)(param_1 + 8),0);
    VEMAddBindings(*(undefined4 *)(param_1 + 8),auStack_220);
    uVar1 = *(uint *)(param_1 + 4);
    *(uint *)(param_1 + 4) = uVar1 | 2;
    if (*(int *)(param_1 + 0x6c) != 0) {
      *(uint *)(param_1 + 4) = uVar1 | 3;
      FUN_c043b77c();
    }
  }
  FUN_c0449d30(local_18);
  return iVar3;
}



/* c0435524 FUN_c0435524 */

/* Boundary evidence: original MIPS .pdata c0435524..c04355b7. Semantic name remains unreviewed. */

undefined4 FUN_c0435524(int param_1)

{
  undefined1 auStack_218 [520];
  uint local_10;
  
  local_10 = DAT_c044d82c;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffc;
  if (*(int *)(param_1 + 8) != 0) {
    FUN_c04351d4(param_1,L"IPV4Protocols",auStack_218);
    FUN_c0446318(param_1);
    FUN_c04335c4(param_1);
    VEMDeleteBindings(*(undefined4 *)(param_1 + 8),auStack_218);
    FUN_c04335a8(param_1);
  }
  FUN_c0434af4();
  FUN_c0449d30(local_10);
  return 0;
}



/* c04355b8 FUN_c04355b8 */

/* Boundary evidence: original MIPS .pdata c04355b8..c043563f. Semantic name remains unreviewed. */

void FUN_c04355b8(char *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar1 = DAT_c044d82c;
  FUN_c04497b8();
  strlen(param_1);
  FUN_c04497a8();
  FUN_c0449798();
  *param_2 = local_28;
  param_2[1] = local_24;
  param_2[2] = local_20;
  param_2[3] = local_1c;
  FUN_c0449d30(uVar1);
  return;
}



/* c0435640 FUN_c0435640 */

/* Boundary evidence: original MIPS .pdata c0435640..c0435727. Semantic name remains unreviewed. */

void FUN_c0435640(STRSAFE_LPSTR param_1,LPCWSTR param_2)

{
  undefined4 local_a0;
  ushort local_9c;
  ushort local_9a;
  byte local_98;
  byte local_97;
  byte local_96;
  byte local_95;
  byte local_94;
  byte local_93;
  byte local_92;
  byte local_91;
  byte abStack_90 [127];
  undefined1 local_11;
  uint local_10;
  
  local_10 = DAT_c044d82c;
  WideCharToMultiByte(1,0,param_2,-1,(LPSTR)abStack_90,0x80,(LPCSTR)0x0,(LPBOOL)0x0);
  local_11 = 0;
  FUN_c043444c(abStack_90);
  FUN_c04355b8((char *)abStack_90,&local_a0);
  StringCchPrintfA(param_1,0x27,"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",local_a0,
                   (uint)local_9c,(uint)local_9a,(uint)local_98,(uint)local_97,(uint)local_96,
                   (uint)local_95,(uint)local_94,(uint)local_93,(uint)local_92,(uint)local_91);
  FUN_c0449d30(local_10);
  return;
}



/* c0435728 FUN_c0435728 */

/* Boundary evidence: original MIPS .pdata c0435728..c0435a3b. Semantic name remains unreviewed. */

int FUN_c0435728(int param_1)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  wchar_t *pwVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 local_4b0 [2];
  char local_4a8 [40];
  char acStack_480 [64];
  wchar_t awStack_440 [260];
  undefined1 auStack_238 [520];
  uint local_30;
  
  local_30 = DAT_c044d82c;
  iVar4 = *(int *)(*(int *)(param_1 + 0xab0) + 0x3c);
  iVar6 = 0;
  if (((*(uint *)(param_1 + 4) & 4) == 0) &&
     ((*(int *)(param_1 + 8) != 0 || (iVar6 = FUN_c0434f50(param_1), iVar6 == 0)))) {
    if (*(int *)(param_1 + 0x6c) != 0) {
      FUN_c043b77c();
      FUN_c0435640(acStack_480,(LPCWSTR)(param_1 + 0xcf0));
      StringCchPrintfW(awStack_440,0x104,L"Comm\\TcpIp6\\Parms\\Interfaces\\%hs",acStack_480);
      iVar3 = *(int *)(iVar4 + 0x6c);
      if (iVar3 == 0) {
        RegDeleteKeyW((HKEY)0x80000002,awStack_440);
      }
      else {
        uVar9 = iVar3 + 7U >> 3;
        pwVar13 = L"Forwards";
        puVar16 = local_4b0;
        uVar7 = 1;
        puVar11 = local_4b0;
        local_4b0[0] = 1;
        uVar18 = 0;
        uVar17 = 4;
        uVar15 = 0;
        uVar14 = 4;
        uVar12 = 4;
        uVar10 = 0;
        FUN_c0432c04((HKEY)0x80000002,awStack_440,L"Advertises",4);
        StringCchCatW(awStack_440,0x104,L"\\Routes\\");
        local_4a8[0] = '\0';
        StringCchPrintfA(local_4a8,0x21,"%02X",(uint)*(byte *)(iVar4 + 0x5c),uVar10,puVar11,uVar12,
                         pwVar13,uVar14,uVar15,puVar16,uVar17,uVar18);
        pbVar8 = (byte *)(iVar4 + 0x5d);
        iVar3 = 2;
        if (1 < uVar9) {
          do {
            iVar5 = iVar3;
            if ((uVar7 & 1) == 0) {
              iVar5 = iVar3 + 1;
              local_4a8[iVar3] = ':';
              local_4a8[iVar3 + 1] = '\0';
            }
            StringCchPrintfA(local_4a8 + iVar5,0x21 - iVar5,"%02X",(uint)*pbVar8);
            uVar7 = uVar7 + 1;
            pbVar8 = pbVar8 + 1;
            iVar3 = iVar5 + 2;
          } while (uVar7 < uVar9);
        }
        sVar1 = wcslen(awStack_440);
        sVar2 = wcslen(awStack_440);
        StringCchPrintfW(awStack_440 + sVar2,0x104 - sVar1,L"%hs::0/%u->::0",local_4a8,
                         *(int *)(iVar4 + 0x6c));
        FUN_c0432c04((HKEY)0x80000002,awStack_440,L"Publish",4);
      }
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    FUN_c04351d4(param_1,L"IPV6Protocols",auStack_238);
    FUN_c04335c4(param_1);
    VEMSetMediaState(*(undefined4 *)(param_1 + 8),0);
    VEMAddBindings(*(undefined4 *)(param_1 + 8),auStack_238);
    FUN_c04335a8(param_1);
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
  }
  FUN_c0449d30(local_30);
  return iVar6;
}



/* c0435a3c FUN_c0435a3c */

/* Boundary evidence: original MIPS .pdata c0435a3c..c0435ac7. Semantic name remains unreviewed. */

undefined4 FUN_c0435a3c(int param_1)

{
  undefined1 auStack_218 [520];
  uint local_10;
  
  local_10 = DAT_c044d82c;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffb;
  if (*(int *)(param_1 + 8) != 0) {
    FUN_c04351d4(param_1,L"IPV6Protocols",auStack_218);
    FUN_c0446318(param_1);
    FUN_c04335c4(param_1);
    VEMDeleteBindings(*(undefined4 *)(param_1 + 8),auStack_218);
    FUN_c04335a8(param_1);
  }
  FUN_c0449d30(local_10);
  return 0;
}



/* c0435ac8 FUN_c0435ac8 */

/* Boundary evidence: original MIPS .pdata c0435ac8..c0435b17. Semantic name remains unreviewed. */

void FUN_c0435ac8(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* c0435b18 FUN_c0435b18 */

/* Boundary evidence: original MIPS .pdata c0435b18..c0435bbf. Semantic name remains unreviewed. */

bool FUN_c0435b18(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

{
  LSTATUS LVar1;
  DWORD aDStack_18 [2];
  
  if (*param_1 != (HKEY)0x0) {
    RegCloseKey(*param_1);
    *param_1 = (HKEY)0x0;
  }
  param_1[1] = (HKEY)0x0;
  LVar1 = RegCreateKeyExW(param_2,param_3,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,param_1
                          ,aDStack_18);
  return LVar1 == 0;
}



/* c0435bc0 FUN_c0435bc0 */

/* Boundary evidence: original MIPS .pdata c0435bc0..c0435c57. Semantic name remains unreviewed. */

bool FUN_c0435bc0(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

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



/* c0435c58 FUN_c0435c58 */

/* Boundary evidence: original MIPS .pdata c0435c58..c0435cbf. Semantic name remains unreviewed. */

bool FUN_c0435c58(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_c0435bc0(param_1,param_2,param_3,param_4);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_c0435b18(param_1,param_2,param_3);
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}



/* c0435cc0 FUN_c0435cc0 */

/* Boundary evidence: original MIPS .pdata c0435cc0..c0435deb. Semantic name remains unreviewed. */

bool FUN_c0435cc0(undefined4 param_1,int param_2)

{
  HRESULT HVar1;
  bool bVar2;
  int local_res4 [3];
  HKEY local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  wchar_t awStack_248 [20];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  local_res4[0] = param_2;
  memcpy(awStack_248,L"Comm\\Tcpip\\Hosts\\%s",0x28);
  HVar1 = StringCchPrintfW(awStack_220,0x104,awStack_248,param_1);
  if (HVar1 < 0) {
    FUN_c0449d30(local_18);
    bVar2 = false;
  }
  else {
    RegDeleteKeyW((HKEY)0x80000002,awStack_220);
    bVar2 = true;
    if (local_res4[0] != 0) {
      local_258 = (HKEY)0x0;
      local_254 = 0;
      local_250 = 0;
      local_24c = 0;
      FUN_c0435c58(&local_258,(HKEY)0x80000002,awStack_220,0x20019);
      bVar2 = local_258 != (HKEY)0x0;
      if (bVar2) {
        RegSetValueExW(local_258,L"ipaddr",0,3,(BYTE *)local_res4,4);
      }
      FUN_c0435ac8(&local_258);
    }
    FUN_c0449d30(local_18);
  }
  return bVar2;
}



/* c0435dec FUN_c0435dec */

/* Boundary evidence: original MIPS .pdata c0435dec..c0435e33. Semantic name remains unreviewed. */

void FUN_c0435dec(uint param_1)

{
  FUN_c0435cc0(L"ppp_peer",
               (param_1 & 0xff00 | param_1 << 0x10) << 8 |
               (param_1 & 0xff0000 | param_1 >> 0x10) >> 8);
  return;
}



/* c0435e34 FUN_c0435e34 */

/* Boundary evidence: original MIPS .pdata c0435e34..c0435e93. Semantic name remains unreviewed. */

undefined * FUN_c0435e34(void)

{
  if ((DAT_c044d858 & 1) == 0) {
    DAT_c044d858 = DAT_c044d858 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c044d844);
    FUN_c0449fbc(FUN_c044c118);
  }
  return &DAT_c044d844;
}



/* c0435e94 FUN_c0435e94 */

uint FUN_c0435e94(ushort *param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  ushort uVar2;
  uint uVar3;
  
  if (1 < param_2) {
    uVar3 = param_2 >> 1;
    param_2 = param_2 + uVar3 * -2;
    do {
      pbVar1 = (byte *)((int)param_1 + 1);
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = uVar3 - 1;
      param_3 = ((uVar2 & 0xff) << 8 | (uint)*pbVar1) + param_3;
    } while (uVar3 != 0);
  }
  if (0 < (int)param_2) {
    param_3 = (byte)*param_1 + param_3;
  }
  for (; param_3 >> 0x10 != 0; param_3 = (param_3 & 0xffff) + (param_3 >> 0x10)) {
  }
  return param_3 & 0xffff;
}



/* c0435f10 FUN_c0435f10 */

/* Boundary evidence: original MIPS .pdata c0435f10..c043607f. Semantic name remains unreviewed. */

uint FUN_c0435f10(uint param_1,uint param_2,int param_3,int param_4,ushort *param_5,int param_6)

{
  uint uVar1;
  
  uVar1 = param_6 + 0x1cU & 0xffff;
  *(undefined1 *)param_5 = 0x45;
  param_5[1] = (ushort)(uVar1 << 8) | (ushort)(uVar1 >> 8);
  *(undefined1 *)((int)param_5 + 9) = 0x11;
  *(undefined1 *)(param_5 + 4) = 0x80;
  *(uint *)(param_5 + 6) =
       (param_1 & 0xff0000 | param_1 >> 0x10) >> 8 | (param_1 & 0xff00 | param_1 << 0x10) << 8;
  *(undefined1 *)((int)param_5 + 1) = 0;
  param_5[2] = 0;
  param_5[3] = 0;
  param_5[5] = 0;
  *(uint *)(param_5 + 8) =
       (param_2 & 0xff0000 | param_2 >> 0x10) >> 8 | (param_2 & 0xff00 | param_2 << 0x10) << 8;
  uVar1 = FUN_c0435e94(param_5,0x14,0);
  param_5[5] = (ushort)((~uVar1 & 0xffff) << 8) | (ushort)((~uVar1 & 0xffff) >> 8);
  param_5[10] = (ushort)(param_3 << 8) | (ushort)((uint)param_3 >> 8);
  uVar1 = param_6 + 8U & 0xffff;
  param_5[0xb] = (ushort)(param_4 << 8) | (ushort)((uint)param_4 >> 8);
  param_5[0xc] = (ushort)(uVar1 << 8) | (ushort)(uVar1 >> 8);
  param_5[0xd] = 0;
  return param_6 + 0x1cU;
}



/* c0436080 FUN_c0436080 */

undefined4
FUN_c0436080(uint param_1,uint param_2,char *param_3,uint param_4,undefined4 *param_5,int *param_6)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((0x1b < param_4) && (*param_3 == 'E')) && (param_3[9] == '\x11')) &&
     ((CONCAT11(param_3[0x14],param_3[0x15]) == param_1 &&
      (CONCAT11(param_3[0x16],param_3[0x17]) == param_2)))) {
    *param_5 = param_3 + 0x1c;
    uVar1 = 1;
    *param_6 = param_4 - 0x1c;
  }
  return uVar1;
}



/* c0436108 FUN_c0436108 */

/* Boundary evidence: original MIPS .pdata c0436108..c043621b. Semantic name remains unreviewed. */

void FUN_c0436108(uint param_1,undefined1 *param_2,undefined4 *param_3)

{
  memset(param_2,0,0x130);
  *(undefined4 *)(param_2 + 4) = 0x78563412;
  param_2[2] = 6;
  *(undefined2 *)(param_2 + 8) = 0x600;
  param_2[0x1d] = 0x53;
  param_2[0x1e] = 0x45;
  *param_2 = 1;
  param_2[1] = 8;
  *(uint *)(param_2 + 0xc) =
       (param_1 & 0xff0000 | param_1 >> 0x10) >> 8 | (param_1 & 0xff00 | param_1 << 0x10) << 8;
  *(undefined4 *)(param_2 + 0xec) = DAT_c044d2a0;
  param_2[0xf0] = 0x35;
  param_2[0xf1] = 1;
  param_2[0xf2] = 8;
  param_2[0xf3] = 0x37;
  param_2[0xf4] = 1;
  param_2[0xf5] = 0xf;
  param_2[0xf6] = 0xff;
  *param_3 = param_2 + 0xf6 + (1 - (int)param_2);
  return;
}



/* c043621c FUN_c043621c */

/* Boundary evidence: original MIPS .pdata c043621c..c0436303. Semantic name remains unreviewed. */

undefined4 FUN_c043621c(int param_1,uint param_2,undefined1 *param_3,uint *param_4)

{
  uint _Size;
  char *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((0xef < param_2) && (2 < param_2 - 0xf0)) {
    pcVar1 = (char *)(param_1 + 0xf3);
    uVar2 = param_2 - 0xf3;
    if ((*(char *)(param_1 + 0xf0) == '5') &&
       ((*(char *)(param_1 + 0xf1) == '\x01' && (*(char *)(param_1 + 0xf2) == '\x05')))) {
      *param_3 = 0;
      uVar3 = 1;
      *param_4 = 0;
      while( true ) {
        if (uVar2 < 3) {
          return 1;
        }
        if (*pcVar1 == -1) {
          return 1;
        }
        _Size = (uint)(byte)pcVar1[1];
        if (uVar2 - 2 < _Size) {
          return 1;
        }
        uVar2 = (uVar2 - 2) - _Size;
        if (*pcVar1 == '\x0f') break;
        pcVar1 = pcVar1 + _Size + 2;
      }
      *param_4 = _Size;
      memcpy(param_3,pcVar1 + 2,_Size);
    }
  }
  return uVar3;
}



/* c0436304 FUN_c0436304 */

/* Boundary evidence: original MIPS .pdata c0436304..c0436363. Semantic name remains unreviewed. */

void FUN_c0436304(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_c043336c(param_2);
  if (iVar1 != 0) {
    FUN_c04335a8((int)param_2);
    if (param_2[0x2f0] != 0) {
      param_2[0x2f0] = 0;
      FUN_c04363bc(param_2);
    }
    FUN_c04335c4((int)param_2);
    FUN_c0433498(param_2);
  }
  return;
}



/* c0436364 FUN_c0436364 */

/* Boundary evidence: original MIPS .pdata c0436364..c04363bb. Semantic name remains unreviewed. */

void FUN_c0436364(int param_1)

{
  if (*(int *)(param_1 + 0xbc0) != 0) {
    CTEStopTimer(param_1 + 0xba4);
    *(undefined4 *)(param_1 + 0xbc0) = 0;
  }
  CTEStartTimer(param_1 + 0xba4,*(undefined4 *)(param_1 + 0xb9c),FUN_c0436304,param_1);
  *(undefined4 *)(param_1 + 0xbc0) = 1;
  return;
}



/* c04363bc FUN_c04363bc */

/* Boundary evidence: original MIPS .pdata c04363bc..c04364cb. Semantic name remains unreviewed. */

void FUN_c04363bc(int *param_1)

{
  uint uVar1;
  int local_190 [2];
  undefined4 local_188;
  ushort *local_184;
  uint local_180;
  undefined2 local_17c;
  ushort *local_178;
  undefined4 local_174;
  undefined4 auStack_170 [2];
  undefined4 *local_168;
  undefined2 local_164;
  undefined2 local_162;
  ushort auStack_160 [14];
  undefined1 auStack_144 [308];
  
  param_1[0x2e8] = 0;
  if ((uint)param_1[0x2e6] < (uint)param_1[0x2e5]) {
    uVar1 = param_1[0x1d4];
    param_1[0x2e6] = param_1[0x2e6] + 1;
    if (param_1[8] == 0) {
      uVar1 = *(uint *)(*(int *)(param_1[0x2ac] + 0x24) + 0x20);
    }
    FUN_c0436108(uVar1,auStack_144,local_190);
    uVar1 = FUN_c0435f10(uVar1,0xffffffff,0x44,0x43,auStack_160,local_190[0]);
    FUN_c0436364((int)param_1);
    local_178 = auStack_160;
    local_184 = auStack_160;
    local_168 = &local_188;
    local_17c = 0;
    local_174 = 0;
    local_188 = 0;
    local_164 = 0;
    local_162 = 4;
    local_180 = uVar1;
    FUN_c04335c4((int)param_1);
    FUN_c0434a28(param_1,0,auStack_170);
    FUN_c04335a8((int)param_1);
    param_1[0x2e8] = 1;
  }
  else {
    param_1[1] = param_1[1] | 8;
    FUN_c0436b1c((undefined4 *)param_1[0x2ac]);
  }
  return;
}



/* c04364cc FUN_c04364cc */

/* Boundary evidence: original MIPS .pdata c04364cc..c043658f. Semantic name remains unreviewed. */

undefined4 FUN_c04364cc(int param_1,char *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_18;
  uint local_14;
  
  uVar2 = 0;
  iVar1 = FUN_c0436080(0x43,0x44,param_2,param_3,&local_14,(int *)&local_18);
  if (iVar1 != 0) {
    memset((undefined1 *)(param_1 + 0xbc4),0,0x104);
    iVar1 = FUN_c043621c(local_14,local_18,(undefined1 *)(param_1 + 0xbc4),&local_14);
    if (iVar1 != 0) {
      if (*(int *)(param_1 + 0xbc0) != 0) {
        CTEStopTimer(param_1 + 0xba4);
        *(undefined4 *)(param_1 + 0xbc0) = 0;
      }
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 8;
      FUN_c0436b1c(*(undefined4 **)(param_1 + 0xab0));
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* c0436590 FUN_c0436590 */

/* Boundary evidence: original MIPS .pdata c0436590..c04365eb. Semantic name remains unreviewed. */

void FUN_c0436590(int *param_1)

{
  if ((param_1[1] & 8U) == 0) {
    if (param_1[0x1b] == 0) {
      if (param_1[0x2f0] == 0) {
        param_1[0x2e6] = 0;
        FUN_c04363bc(param_1);
      }
    }
    else {
      param_1[1] = param_1[1] | 8;
      FUN_c0436b1c((undefined4 *)param_1[0x2ac]);
    }
  }
  return;
}



/* c04365ec FUN_c04365ec */

/* Boundary evidence: original MIPS .pdata c04365ec..c0436623. Semantic name remains unreviewed. */

void FUN_c04365ec(int param_1)

{
  if (*(int *)(param_1 + 0xbc0) != 0) {
    CTEStopTimer(param_1 + 0xba4);
    *(undefined4 *)(param_1 + 0xbc0) = 0;
  }
  return;
}



/* c0436624 FUN_c0436624 */

/* Boundary evidence: original MIPS .pdata c0436624..c04366cf. Semantic name remains unreviewed. */

undefined4 FUN_c0436624(void)

{
  int iVar1;
  SOCKET s;
  undefined4 uVar2;
  WSADATA WStack_1a8;
  uint local_18;
  
  local_18 = DAT_c044d82c;
  uVar2 = 1;
  if (DAT_c044d860 == 0) {
    iVar1 = WSAStartup(0x202,&WStack_1a8);
    if (iVar1 == 0) {
      DAT_c044d860 = 1;
    }
    if (DAT_c044d860 != 0) goto LAB_c043667c;
  }
  else {
LAB_c043667c:
    s = socket(0x17,2,0);
    if (s != 0xffffffff) {
      closesocket(s);
      goto LAB_c04366b0;
    }
  }
  uVar2 = 0;
LAB_c04366b0:
  FUN_c0449d30(local_18);
  return uVar2;
}



/* c04366d0 FUN_c04366d0 */

/* Boundary evidence: original MIPS .pdata c04366d0..c04366eb. Semantic name remains unreviewed. */

void FUN_c04366d0(int param_1)

{
  CTEStopTimer(param_1 + 0x58);
  return;
}



/* c04366ec FUN_c04366ec */

/* Boundary evidence: original MIPS .pdata c04366ec..c043679f. Semantic name remains unreviewed. */

void FUN_c04366ec(undefined4 param_1,int *param_2)

{
  DWORD DVar1;
  int iVar2;
  
  DVar1 = GetTickCount();
  FUN_c04335a8(*param_2);
  if (DVar1 - param_2[0x15] < (uint)param_2[0x14]) {
    iVar2 = param_2[0x14] - (DVar1 - param_2[0x15]);
    if ((iVar2 != 0) && (param_2[1] != 0)) {
      CTEStartTimer(param_2 + 0x16,iVar2,FUN_c04366ec,param_2);
    }
  }
  else {
    *(undefined4 *)(*param_2 + 0xcd4) = 1;
    FUN_c0439d7c(*(int **)(*param_2 + 0xaa8),(undefined *)0x0,0);
  }
  FUN_c04335c4(*param_2);
  return;
}



/* c04367a0 FUN_c04367a0 */

/* Boundary evidence: original MIPS .pdata c04367a0..c04367f3. Semantic name remains unreviewed. */

void FUN_c04367a0(int *param_1)

{
  if (param_1 != (int *)0x0) {
    FUN_c04390f0((int *)param_1[0xf]);
    FUN_c0437230((int *)param_1[9]);
    FUN_c043f190((int *)param_1[3]);
    *(undefined4 *)(*param_1 + 0xab0) = 0;
    FUN_c0434420(*param_1,param_1);
  }
  return;
}



/* c04367f4 FUN_c04367f4 */

/* Boundary evidence: original MIPS .pdata c04367f4..c0436877. Semantic name remains unreviewed. */

undefined4 FUN_c04367f4(int param_1,undefined4 param_2,int param_3)

{
  DWORD DVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_3 * 0x18 + param_1;
  if (*(int *)(iVar3 + 8) == 0) {
    uVar2 = 0xc0000001;
  }
  else {
    DVar1 = GetTickCount();
    *(DWORD *)(param_1 + 0x54) = DVar1;
    uVar2 = (**(code **)(iVar3 + 0x1c))(*(undefined4 *)(iVar3 + 0xc),param_2);
  }
  return uVar2;
}



/* c0436878 FUN_c0436878 */

/* Boundary evidence: original MIPS .pdata c0436878..c0436b1b. Semantic name remains unreviewed. */

int FUN_c0436878(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  wchar_t local_438 [260];
  wchar_t local_230 [260];
  uint local_28;
  
  local_28 = DAT_c044d82c;
  piVar1 = (int *)FUN_c04343d0(param_1,0x74);
  if (piVar1 == (int *)0x0) {
    iVar3 = 8;
  }
  else {
    *piVar1 = param_1;
    CTEInitTimer(piVar1 + 0x16);
    piVar1[10] = (int)FUN_c0436fec;
    piVar1[8] = 1;
    piVar1[0xb] = (int)FUN_c0436d54;
    piVar1[0xc] = (int)FUN_c0436dc8;
    piVar1[0xd] = (int)FUN_c0437278;
    iVar3 = FUN_c0437040(param_1,piVar1 + 9);
    if (iVar3 == 0) {
      FUN_c0432908((HKEY)0x80000002,L"Comm\\ppp\\Parms",L"IPV6Disable",4);
      piVar1[0xe] = 0;
      iVar3 = FUN_c0436624();
      if (iVar3 != 0) {
        piVar1[0x10] = (int)FUN_c043909c;
        piVar1[0xe] = 1;
        piVar1[0x11] = (int)FUN_c043912c;
        piVar1[0x12] = (int)FUN_c0439148;
        piVar1[0x13] = (int)FUN_c0439214;
        iVar3 = FUN_c0438e5c(param_1,piVar1 + 0xf);
        if (iVar3 != 0) goto LAB_c04368cc;
      }
      piVar1[2] = 1;
      piVar1[4] = (int)FUN_c043f2bc;
      piVar1[5] = (int)FUN_c043f1f8;
      piVar1[6] = (int)FUN_c043f284;
      iVar3 = FUN_c043f058(param_1,piVar1 + 3);
      if (iVar3 == 0) {
        piVar1[0x14] = 0;
        local_438[0] = L'\0';
        local_230[0] = L'\0';
        FUN_c0432908((HKEY)0x80000002,L"Comm\\Autodial",L"RasEntryName1",1);
        iVar2 = _wcsicmp(local_438,(wchar_t *)(param_1 + 0x78));
        if ((iVar2 == 0) || (iVar2 = _wcsicmp(local_230,(wchar_t *)(param_1 + 0x78)), iVar2 == 0)) {
          piVar1[0x14] = 1800000;
        }
        goto LAB_c04368d8;
      }
    }
  }
LAB_c04368cc:
  FUN_c04367a0(piVar1);
  piVar1 = (int *)0x0;
LAB_c04368d8:
  *param_2 = piVar1;
  FUN_c0449d30(local_28);
  return iVar3;
}



/* c0436b1c FUN_c0436b1c */

/* Boundary evidence: original MIPS .pdata c0436b1c..c0436d53. Semantic name remains unreviewed. */

void FUN_c0436b1c(undefined4 *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  DWORD DVar6;
  int iVar7;
  int *piVar8;
  
  piVar8 = (int *)*param_1;
  iVar7 = param_1[9];
  if ((param_1[0xf] == 0) || (bVar4 = true, *(int *)(*(int *)(param_1[0xf] + 4) + 8) != 9)) {
    bVar4 = false;
  }
  if ((iVar7 == 0) || (bVar2 = true, *(int *)(*(int *)(iVar7 + 4) + 8) != 9)) {
    bVar2 = false;
  }
  if ((param_1[3] == 0) || (bVar3 = true, *(int *)(*(int *)(param_1[3] + 4) + 8) != 9)) {
    bVar3 = false;
  }
  if (((iVar7 == 0) || (iVar7 = *(int *)(*(int *)(iVar7 + 4) + 8), iVar7 < 4)) ||
     (bVar5 = true, 8 < iVar7)) {
    bVar5 = false;
  }
  bVar1 = (piVar8[1] & 8U) == 0;
  if ((bVar2) && ((bVar3 || ((piVar8[0x18b] & 0x1800U) != 0x1800)))) {
    if (bVar1) {
      FUN_c0436590(piVar8);
    }
    else {
      iVar7 = FUN_c0435398((int)piVar8);
      if (iVar7 != 0) goto LAB_c0436d14;
    }
  }
  if (((!bVar4) || ((!bVar3 && ((piVar8[0x18b] & 0x1800U) == 0x1800)))) ||
     (iVar7 = FUN_c0435728((int)piVar8), iVar7 == 0)) {
    if ((!bVar2) && (!bVar4)) {
      return;
    }
    if ((!bVar3) && ((piVar8[0x18b] & 0x1800U) == 0x1800)) {
      return;
    }
    if (bVar5) {
      return;
    }
    if (bVar1) {
      return;
    }
    DVar6 = GetTickCount();
    param_1[0x15] = DVar6;
    CTEStopTimer(param_1 + 0x16);
    if ((param_1[0x14] != 0) && (param_1[1] != 0)) {
      CTEStartTimer(param_1 + 0x16,param_1[0x14],FUN_c04366ec,param_1);
    }
    FUN_c0433050((int)piVar8,0x2000,0);
    return;
  }
LAB_c0436d14:
  FUN_c0439d7c((int *)piVar8[0x2aa],(undefined *)0x0,0);
  return;
}



/* c0436d54 FUN_c0436d54 */

/* Boundary evidence: original MIPS .pdata c0436d54..c0436dc7. Semantic name remains unreviewed. */

void FUN_c0436d54(int *param_1)

{
  HANDLE hObject;
  DWORD aDStack_10 [2];
  
  if (*(int *)(*param_1 + 0x6c) != 0) {
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0439bb8,(LPVOID)0x0,0,aDStack_10);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
  }
  FUN_c044af20((int *)param_1[1]);
  return;
}



/* c0436dc8 FUN_c0436dc8 */

/* Boundary evidence: original MIPS .pdata c0436dc8..c0436de3. Semantic name remains unreviewed. */

void FUN_c0436dc8(int param_1)

{
  FUN_c044aa3c(*(int **)(param_1 + 4));
  return;
}



/* c0436de4 FUN_c0436de4 */

/* Boundary evidence: original MIPS .pdata c0436de4..c0436dff. Semantic name remains unreviewed. */

void FUN_c0436de4(int *param_1,uint param_2,void *param_3,uint param_4)

{
  FUN_c0447448(*param_1,param_2,param_3,param_4);
  return;
}



/* c0436e00 FUN_c0436e00 */

/* Boundary evidence: original MIPS .pdata c0436e00..c0436f0b. Semantic name remains unreviewed. */

undefined4 FUN_c0436e00(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  SIZE_T SVar4;
  ushort local_20 [2];
  uint local_1c;
  
  iVar2 = *param_1;
  if ((param_1[6] != 0) || (param_1[10] != 0)) {
    local_1c = 2;
    iVar3 = 1;
    FUN_c043a220(*(int *)(iVar2 + 0xaa8),1,1,local_20,&local_1c);
    SVar4 = local_20[0] + 0xc2;
    if (SVar4 != param_1[0x492]) {
      FUN_c0434420(iVar2,(LPVOID)param_1[0x491]);
      param_1[0x492] = SVar4;
      iVar1 = FUN_c04343d0(iVar2,SVar4);
      param_1[0x491] = iVar1;
      if (iVar1 == 0) {
        param_1[6] = 0;
        param_1[0x492] = 0;
      }
    }
    if ((*(char *)((int)param_1 + 0x2d) == '\0') || (param_1[4] == 0)) {
      iVar3 = 0;
    }
    FUN_c04382f8(param_1 + 0xe,*(byte *)(param_1 + 7) + 1 & 0xff,*(byte *)(param_1 + 0xb) + 1 & 0xff
                 ,(uint)*(byte *)((int)param_1 + 0x1d),iVar3);
  }
  FUN_c0436b1c(*(undefined4 **)(iVar2 + 0xab0));
  return 0;
}



/* c0436f0c FUN_c0436f0c */

/* Boundary evidence: original MIPS .pdata c0436f0c..c0436f3f. Semantic name remains unreviewed. */

undefined4 FUN_c0436f0c(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  FUN_c04365ec(iVar1);
  FUN_c0435524(iVar1);
  return 0;
}



/* c0436f40 FUN_c0436f40 */

/* Boundary evidence: original MIPS .pdata c0436f40..c0436f5f. Semantic name remains unreviewed. */

undefined4 FUN_c0436f40(int *param_1)

{
  FUN_c04384e4(param_1);
  return 0;
}



/* c0436f60 FUN_c0436f60 */

/* Boundary evidence: original MIPS .pdata c0436f60..c0436f8f. Semantic name remains unreviewed. */

undefined4 FUN_c0436f60(int *param_1)

{
  if (*(int *)(*param_1 + 0x54) == 0) {
    FUN_c0436b1c(*(undefined4 **)(*param_1 + 0xab0));
  }
  return 0;
}



/* c0436f90 FUN_c0436f90 */

/* Boundary evidence: original MIPS .pdata c0436f90..c0436faf. Semantic name remains unreviewed. */

undefined4 FUN_c0436f90(int *param_1)

{
  FUN_c04335a8(*param_1);
  return 0;
}



/* c0436fb0 FUN_c0436fb0 */

/* Boundary evidence: original MIPS .pdata c0436fb0..c0436fcf. Semantic name remains unreviewed. */

undefined4 FUN_c0436fb0(int *param_1)

{
  FUN_c04335c4(*param_1);
  return 0;
}



/* c0436fd0 FUN_c0436fd0 */

/* Boundary evidence: original MIPS .pdata c0436fd0..c0436feb. Semantic name remains unreviewed. */

void FUN_c0436fd0(int param_1)

{
  FUN_c044adc0(*(int **)(param_1 + 4));
  return;
}



/* c0436fec FUN_c0436fec */

/* Boundary evidence: original MIPS .pdata c0436fec..c0437007. Semantic name remains unreviewed. */

void FUN_c0436fec(int param_1)

{
  FUN_c044a990(*(int **)(param_1 + 4));
  return;
}



/* c0437008 FUN_c0437008 */

/* Boundary evidence: original MIPS .pdata c0437008..c0437023. Semantic name remains unreviewed. */

void FUN_c0437008(int param_1)

{
  FUN_c044ae68(*(int **)(param_1 + 4));
  return;
}



/* c0437024 FUN_c0437024 */

/* Boundary evidence: original MIPS .pdata c0437024..c043703f. Semantic name remains unreviewed. */

void FUN_c0437024(int param_1)

{
  FUN_c044aad0(*(int **)(param_1 + 4));
  return;
}



/* c0437040 FUN_c0437040 */

/* Boundary evidence: original MIPS .pdata c0437040..c043722f. Semantic name remains unreviewed. */

int FUN_c0437040(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_c04343d0(param_1,0x1258);
  if (piVar1 == (int *)0x0) {
LAB_c0437078:
    iVar3 = 8;
  }
  else {
    iVar3 = FUN_c04335e0(param_1,0x8021,&PTR_FUN_c044d2d0,piVar1);
    if ((((iVar3 == 0) && (iVar3 = FUN_c04335e0(param_1,0x21,&PTR_FUN_c044d2ec,piVar1), iVar3 == 0))
        && (iVar3 = FUN_c04335e0(param_1,0x2d,&PTR_FUN_c044d308,piVar1), iVar3 == 0)) &&
       (iVar3 = FUN_c04335e0(param_1,0x2f,&PTR_FUN_c044d324,piVar1), iVar3 == 0)) {
      *piVar1 = param_1;
      piVar2 = FUN_c044a4d4(&PTR_DAT_c044d2a4,&LAB_c04384d8,(int)piVar1);
      piVar1[1] = (int)piVar2;
      if (piVar2 != (int *)0x0) {
        *(undefined1 *)(piVar2 + 0x12) = 1;
        piVar1[5] = 0;
        piVar1[2] = 0xf;
        piVar1[3] = 0xf;
        piVar1[4] = 0;
        FUN_c0432908((HKEY)0x80000002,L"Comm\\PPP\\Parms",L"VJMaxSlotIdTx",4);
        FUN_c0438c50(piVar1);
        FUN_c044adc0((int *)piVar1[1]);
        goto LAB_c043708c;
      }
      goto LAB_c0437078;
    }
  }
  FUN_c0434420(param_1,piVar1);
  piVar1 = (int *)0x0;
LAB_c043708c:
  *param_2 = piVar1;
  return iVar3;
}



/* c0437230 FUN_c0437230 */

/* Boundary evidence: original MIPS .pdata c0437230..c0437277. Semantic name remains unreviewed. */

void FUN_c0437230(int *param_1)

{
  if (param_1 != (int *)0x0) {
    FUN_c044a668((HLOCAL)param_1[1]);
    FUN_c0434420(*param_1,(LPVOID)param_1[0x491]);
    FUN_c0434420(*param_1,param_1);
  }
  return;
}



/* c0437278 FUN_c0437278 */

/* Boundary evidence: original MIPS .pdata c0437278..c0437393. Semantic name remains unreviewed. */

int FUN_c0437278(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_res4 [3];
  ushort local_20 [4];
  
  iVar2 = *param_1;
  iVar4 = *(int *)(iVar2 + 0xab0);
  piVar5 = *(int **)(iVar2 + 0xaa4);
  iVar3 = -0x3fffffff;
  if (*(int *)(param_1[1] + 8) == 9) {
    iVar6 = *(int *)(param_2 + 0xc);
    *(int *)(iVar2 + 0xb58) = *(int *)(iVar2 + 0xb58) + iVar6;
    *(int *)(*param_1 + 0xb60) = *(int *)(*param_1 + 0xb60) + 1;
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(*(int *)(param_2 + 8) + 0x10);
    local_20[0] = 0x21;
    local_res4[0] = param_2;
    if (param_1[10] != 0) {
      uVar1 = FUN_c04375f0(param_2,param_1 + 0xe);
      local_20[0] = (ushort)uVar1;
    }
    if ((*(int *)(iVar4 + 8) == 0) || (iVar4 = FUN_c043f5b0(iVar2,local_res4,local_20), iVar4 != 0))
    {
      *(int *)(iVar2 + 0xb80) = iVar6 + *(int *)(iVar2 + 0xb80);
      *(int *)(iVar2 + 0xb88) = *(int *)(local_res4[0] + 0xc) + *(int *)(iVar2 + 0xb88);
      iVar3 = FUN_c0446f50(piVar5,(uint)local_20[0],local_res4[0]);
    }
  }
  return iVar3;
}



/* c0437394 FUN_c0437394 */

/* Boundary evidence: original MIPS .pdata c0437394..c04373eb. Semantic name remains unreviewed. */

void FUN_c0437394(int *param_1,int param_2)

{
  if (*(int *)(param_1[1] + 8) < 2) {
    FUN_c043bdbc(*(int **)(*param_1 + 0xaac));
  }
  FUN_c044afb0((int *)param_1[1],*(byte **)(param_2 + 8),*(uint *)(param_2 + 4));
  return;
}



/* c04373ec FUN_c04373ec */

/* Boundary evidence: original MIPS .pdata c04373ec..c0437443. Semantic name remains unreviewed. */

void FUN_c04373ec(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (*(int *)(param_1[1] + 8) == 9) {
    FUN_c0433300((int)piVar1,param_2);
    FUN_c0434ccc(piVar1,param_2,1);
  }
  return;
}



/* c0437444 FUN_c0437444 */

/* Boundary evidence: original MIPS .pdata c0437444..c04374db. Semantic name remains unreviewed. */

void FUN_c0437444(undefined4 *param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  
  if ((*(int *)(param_1[1] + 8) == 9) && (param_1[6] != 0)) {
    memcpy((void *)(param_1[0x491] + 0x80),*(void **)(param_2 + 8),*(uint *)(param_2 + 4));
    iVar2 = param_1[0x491];
    *(byte **)(param_2 + 8) = (byte *)(iVar2 + 0x80);
    puVar1 = FUN_c0437e2c((byte *)(iVar2 + 0x80),(uint *)(param_2 + 4),(int)(param_1 + 0xe));
    if (puVar1 != (ushort *)0x0) {
      *(ushort **)(param_2 + 8) = puVar1;
      FUN_c04373ec(param_1,param_2);
    }
  }
  return;
}



/* c04374dc FUN_c04374dc */

/* Boundary evidence: original MIPS .pdata c04374dc..c0437547. Semantic name remains unreviewed. */

void FUN_c04374dc(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  if (((*(int *)(param_1[1] + 8) == 9) && (param_1[6] != 0)) &&
     (iVar1 = FUN_c0437d68(*(byte **)(param_2 + 8),*(uint *)(param_2 + 4),(int)(param_1 + 0xe)),
     iVar1 != 0)) {
    FUN_c04373ec(param_1,param_2);
  }
  return;
}



/* c0437548 FUN_c0437548 */

uint FUN_c0437548(undefined4 *param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar1 = (byte *)*param_1;
  if (pbVar1 < param_2) {
    uVar3 = (uint)*pbVar1;
    pbVar2 = pbVar1 + 1;
    if (uVar3 == 0) {
      if (pbVar1 + 2 < param_2) {
        uVar3 = (uint)CONCAT11(*pbVar2,pbVar1[2]);
      }
      pbVar2 = pbVar1 + 3;
    }
    *param_1 = pbVar2;
  }
  else {
    uVar3 = 0;
  }
  uVar3 = uVar3 + (param_3 >> 8 & 0xff00 |
                  (param_3 & 0xff00) << 8 | param_3 << 0x18 | param_3 >> 0x18);
  return (uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8 | (uVar3 * 0x10000 | uVar3 & 0xff00) << 8;
}



/* c04375f0 FUN_c04375f0 */

/* Boundary evidence: original MIPS .pdata c04375f0..c0437d67. Semantic name remains unreviewed. */

undefined4 FUN_c04375f0(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  size_t _Size;
  size_t _Size_00;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  ushort uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  byte bVar14;
  byte *pbVar15;
  byte *pbVar16;
  uint uVar17;
  uint uVar18;
  undefined1 local_40 [16];
  uint local_30;
  
  local_30 = DAT_c044d82c;
  bVar14 = 0;
  puVar13 = local_40;
  memset(local_40,0,0x10);
  if (*(uint *)(param_1 + 0xc) < 0x28) {
LAB_c0437658:
    FUN_c0449d30(local_30);
    return 0x21;
  }
  pbVar15 = *(byte **)(param_1 + 8);
  uVar4 = *pbVar15 & 0xf;
  uVar5 = uVar4 * 4;
  if (pbVar15[9] != 6) goto LAB_c0437658;
  pbVar16 = pbVar15 + uVar5;
  uVar6 = (pbVar16[0xc] & 0xf3) >> 2;
  _Size_00 = uVar5 + uVar6;
  if (((*(ushort *)(pbVar15 + 6) & 0xff3f) != 0) ||
     ((*(ushort *)(pbVar16 + 0xc) & 0x1700) != 0x1000)) goto LAB_c0437658;
  puVar9 = (undefined4 *)*param_2;
  puVar11 = (undefined4 *)*puVar9;
  if ((*(int *)(pbVar15 + 0xc) != puVar11[5]) ||
     (((*(int *)(pbVar15 + 0x10) != puVar11[6] || (*(short *)pbVar16 != *(short *)puVar11[0x22])) ||
      (*(short *)(pbVar16 + 2) != ((short *)puVar11[0x22])[1])))) {
    do {
      puVar12 = puVar11;
      puVar11 = (undefined4 *)*puVar12;
      if ((((*(int *)(pbVar15 + 0xc) == puVar11[5]) && (*(int *)(pbVar15 + 0x10) == puVar11[6])) &&
          (*(short *)pbVar16 == *(short *)puVar11[0x22])) &&
         (*(short *)(pbVar16 + 2) == ((short *)puVar11[0x22])[1])) {
        if (puVar9 == puVar11) {
          *param_2 = puVar12;
        }
        else {
          *puVar12 = *puVar11;
          *puVar11 = *puVar9;
          *puVar9 = puVar11;
        }
        goto LAB_c0437824;
      }
    } while (puVar11 != puVar9);
    *param_2 = puVar12;
LAB_c0437784:
    memcpy(puVar11 + 2,pbVar15,_Size_00);
    *(char *)(puVar11 + 0x23) = (char)uVar5;
    *(char *)((int)puVar11 + 0x8d) = (char)uVar6;
    puVar11[0x22] = puVar11 + uVar4 + 2;
    pbVar15[9] = *(byte *)((int)puVar11 + 6);
    *(undefined1 *)((int)param_2 + 5) = *(undefined1 *)((int)puVar11 + 6);
    FUN_c0449d30(local_30);
    return 0x2f;
  }
LAB_c0437824:
  if ((((*(short *)pbVar15 != *(short *)(puVar11 + 2)) ||
       (*(short *)(pbVar15 + 6) != *(short *)((int)puVar11 + 0xe))) ||
      (((*(short *)(pbVar15 + 8) != *(short *)(puVar11 + 4) ||
        (uVar6 != *(byte *)((int)puVar11 + 0x8d))) ||
       ((0x14 < uVar5 && (iVar3 = memcmp(pbVar15 + 0x14,puVar11 + 7,uVar5 - 0x14), iVar3 != 0))))))
     || ((0x14 < uVar6 &&
         (iVar3 = memcmp(pbVar16 + 0x14,(void *)(puVar11[0x22] + 0x14),uVar6 - 0x14), iVar3 != 0))))
  goto LAB_c0437784;
  if ((*(ushort *)(pbVar16 + 0xc) & 0x2000) == 0) {
    if (*(short *)(pbVar16 + 0x12) != *(short *)(puVar11[0x22] + 0x12)) goto LAB_c0437784;
  }
  else {
    uVar1 = *(ushort *)(pbVar16 + 0x12);
    uVar8 = uVar1 >> 8 | uVar1 << 8;
    uVar7 = (undefined1)(uVar1 >> 8);
    if ((uVar8 == 0) || (0xff < uVar8)) {
      local_40[1] = (undefined1)uVar1;
      local_40[0] = 0;
      puVar13 = local_40 + 3;
      local_40[2] = uVar7;
    }
    else {
      puVar13 = local_40 + 1;
      local_40[0] = uVar7;
    }
    bVar14 = 1;
  }
  uVar10 = ((*(ushort *)(pbVar16 + 0xe) & 0xff) << 8 | (uint)(*(ushort *)(pbVar16 + 0xe) >> 8)) -
           ((*(ushort *)(puVar11[0x22] + 0xe) & 0xff) << 8 |
           (uint)(*(ushort *)(puVar11[0x22] + 0xe) >> 8));
  if (uVar10 != 0) {
    uVar10 = uVar10 & 0xffff;
    if ((uVar10 == 0) || (0xff < uVar10)) {
      *puVar13 = 0;
      puVar13[1] = (char)(uVar10 >> 8);
      puVar13[2] = (char)uVar10;
      puVar13 = puVar13 + 3;
    }
    else {
      *puVar13 = (char)uVar10;
      puVar13 = puVar13 + 1;
    }
    bVar14 = bVar14 | 2;
  }
  uVar10 = *(uint *)(puVar11[0x22] + 8);
  uVar17 = *(uint *)(pbVar16 + 8);
  uVar10 = ((uVar17 & 0xff0000 | uVar17 >> 0x10) >> 8 | (uVar17 << 0x10 | uVar17 & 0xff00) << 8) -
           ((uVar10 & 0xff0000 | uVar10 >> 0x10) >> 8 | (uVar10 << 0x10 | uVar10 & 0xff00) << 8);
  if (0xffff < uVar10) goto LAB_c0437784;
  if (uVar10 != 0) {
    uVar17 = uVar10 & 0xffff;
    if ((uVar17 == 0) || (0xff < uVar17)) {
      *puVar13 = 0;
      puVar13[1] = (char)(uVar17 >> 8);
      puVar13[2] = (char)uVar17;
      puVar13 = puVar13 + 3;
    }
    else {
      *puVar13 = (char)uVar17;
      puVar13 = puVar13 + 1;
    }
    bVar14 = bVar14 | 4;
  }
  uVar17 = *(uint *)(puVar11[0x22] + 4);
  uVar18 = *(uint *)(pbVar16 + 4);
  uVar17 = ((uVar18 & 0xff0000 | uVar18 >> 0x10) >> 8 | (uVar18 << 0x10 | uVar18 & 0xff00) << 8) -
           ((uVar17 & 0xff0000 | uVar17 >> 0x10) >> 8 | (uVar17 << 0x10 | uVar17 & 0xff00) << 8);
  if (0xffff < uVar17) goto LAB_c0437784;
  if (uVar17 != 0) {
    uVar18 = uVar17 & 0xffff;
    if ((uVar18 == 0) || (0xff < uVar18)) {
      *puVar13 = 0;
      puVar13[1] = (char)(uVar18 >> 8);
      puVar13[2] = (char)uVar18;
      puVar13 = puVar13 + 3;
    }
    else {
      *puVar13 = (char)uVar18;
      puVar13 = puVar13 + 1;
    }
    bVar14 = bVar14 | 8;
  }
  if (bVar14 == 0) {
    uVar1 = *(ushort *)((int)puVar11 + 10);
    if (((uint)*(ushort *)(pbVar15 + 2) != (uint)uVar1) &&
       (((uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8)) == _Size_00)) goto LAB_c0437bdc;
    goto LAB_c0437784;
  }
  if (bVar14 == 8) {
    if (uVar17 != ((*(ushort *)((int)puVar11 + 10) & 0xff) << 8 |
                  (uint)(*(ushort *)((int)puVar11 + 10) >> 8)) - _Size_00) goto LAB_c0437bdc;
    bVar14 = 0xf;
  }
  else {
    if (bVar14 == 0xb) goto LAB_c0437784;
    if (bVar14 != 0xc) {
      if (bVar14 == 0xf) goto LAB_c0437784;
      goto LAB_c0437bdc;
    }
    if ((uVar17 != uVar10) ||
       (uVar17 != ((*(ushort *)((int)puVar11 + 10) & 0xff) << 8 |
                  (uint)(*(ushort *)((int)puVar11 + 10) >> 8)) - _Size_00)) goto LAB_c0437bdc;
    bVar14 = 0xb;
  }
  puVar13 = local_40;
LAB_c0437bdc:
  uVar10 = ((*(ushort *)(pbVar15 + 4) & 0xff) << 8 | (uint)(*(ushort *)(pbVar15 + 4) >> 8)) -
           ((*(ushort *)(puVar11 + 3) & 0xff) << 8 | (uint)(*(ushort *)(puVar11 + 3) >> 8));
  if (uVar10 != 1) {
    uVar10 = uVar10 & 0xffff;
    if ((uVar10 == 0) || (0xff < uVar10)) {
      *puVar13 = 0;
      puVar13[1] = (char)(uVar10 >> 8);
      puVar13[2] = (char)uVar10;
      puVar13 = puVar13 + 3;
    }
    else {
      *puVar13 = (char)uVar10;
      puVar13 = puVar13 + 1;
    }
    bVar14 = bVar14 | 0x20;
  }
  if ((*(ushort *)(pbVar16 + 0xc) & 0x800) != 0) {
    bVar14 = bVar14 | 0x10;
  }
  uVar2 = *(undefined2 *)(pbVar16 + 0x10);
  memcpy(puVar11 + 2,pbVar15,_Size_00);
  *(char *)((int)puVar11 + 0x8d) = (char)uVar6;
  puVar11[0x22] = puVar11 + uVar4 + 2;
  *(char *)(puVar11 + 0x23) = (char)uVar5;
  _Size = (int)puVar13 - (int)local_40;
  if (((*(byte *)((int)param_2 + 7) & 2) == 0) ||
     (*(char *)((int)param_2 + 5) != *(char *)((int)puVar11 + 6))) {
    uVar4 = (_Size_00 - _Size) + 0xfc & 0xff;
    *(undefined1 *)((int)param_2 + 5) = *(undefined1 *)((int)puVar11 + 6);
    pbVar15 = pbVar15 + uVar4;
    *pbVar15 = bVar14 | 0x40;
    pbVar15[1] = *(byte *)((int)puVar11 + 6);
    pbVar15 = pbVar15 + 2;
  }
  else {
    uVar4 = (_Size_00 - _Size) + 0xfd & 0xff;
    pbVar15[uVar4] = bVar14;
    pbVar15 = pbVar15 + uVar4 + 1;
  }
  *pbVar15 = (byte)uVar2;
  pbVar15[1] = (byte)((ushort)uVar2 >> 8);
  memcpy(pbVar15 + 2,local_40,_Size);
  *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) - uVar4;
  *(uint *)(param_1 + 8) = uVar4 + *(int *)(param_1 + 8);
  FUN_c0449d30(local_30);
  return 0x2d;
}



/* c0437d68 FUN_c0437d68 */

/* Boundary evidence: original MIPS .pdata c0437d68..c0437e2b. Semantic name remains unreviewed. */

undefined4 FUN_c0437d68(byte *param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint _Size;
  
  if (((0x13 < param_2) && (iVar2 = (*param_1 & 0xf) * 4, iVar2 + 0x14U <= param_2)) &&
     (_Size = (param_1[iVar2 + 0xc] >> 2 & 0x3c) + iVar2, _Size <= param_2)) {
    bVar1 = param_1[9];
    if (bVar1 < 0x10) {
      *(byte *)(param_3 + 4) = bVar1;
      *(undefined1 *)(param_3 + 6) = 0;
      iVar2 = (uint)bVar1 * 0x90 + param_3;
      param_1[9] = 6;
      memcpy((void *)(iVar2 + 0x914),param_1,_Size);
      *(undefined2 *)(iVar2 + 0x91e) = 0;
      *(short *)(iVar2 + 0x910) = (short)_Size;
      return 1;
    }
  }
  return 0;
}



/* c0437e2c FUN_c0437e2c */

/* Boundary evidence: original MIPS .pdata c0437e2c..c04382f7. Semantic name remains unreviewed. */

ushort * FUN_c0437e2c(byte *param_1,uint *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  ushort *puVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  byte *pbVar11;
  ushort *_Dst;
  int iVar12;
  byte *local_30 [2];
  
  pbVar11 = param_1 + *param_2;
  if (pbVar11 <= param_1) goto LAB_c04382bc;
  bVar1 = *param_1;
  pbVar9 = param_1 + 1;
  if ((bVar1 & 0x40) == 0) {
    if (*(char *)(param_3 + 6) != '\0') {
      return (ushort *)0x0;
    }
    uVar8 = (uint)*(byte *)(param_3 + 4);
  }
  else {
    if (pbVar11 <= pbVar9) goto LAB_c04382bc;
    bVar2 = *pbVar9;
    uVar8 = (uint)bVar2;
    pbVar9 = param_1 + 2;
    if (0xf < uVar8) goto LAB_c04382bc;
    *(undefined1 *)(param_3 + 6) = 0;
    *(byte *)(param_3 + 4) = bVar2;
  }
  iVar7 = uVar8 * 0x90 + param_3;
  bVar2 = *(byte *)(iVar7 + 0x914);
  iVar12 = (bVar2 & 0xf) * 4;
  iVar5 = iVar12 + iVar7 + 0x90c;
  if (pbVar11 <= pbVar9 + 1) goto LAB_c04382bc;
  *(undefined2 *)(iVar5 + 0x18) = *(undefined2 *)pbVar9;
  local_30[0] = pbVar9 + 2;
  uVar4 = *(ushort *)(iVar5 + 0x14) & 0xf7ff;
  if ((bVar1 & 0x10) != 0) {
    uVar4 = uVar4 | 0x800;
  }
  uVar8 = ((*(ushort *)(iVar7 + 0x916) & 0xff) << 8 | (uint)(*(ushort *)(iVar7 + 0x916) >> 8)) -
          (uint)*(ushort *)(iVar7 + 0x910) & 0xffff;
  if ((bVar1 & 0xf) == 0xb) {
    uVar10 = *(uint *)(iVar5 + 0x10);
    uVar10 = uVar8 + (uVar10 >> 8 & 0xff00 |
                     (uVar10 & 0xff00) << 8 | uVar10 << 0x18 | uVar10 >> 0x18);
    *(uint *)(iVar5 + 0x10) =
         (uVar10 & 0xff0000 | uVar10 >> 0x10) >> 8 | (uVar10 * 0x10000 | uVar10 & 0xff00) << 8;
LAB_c043810c:
    uVar10 = *(uint *)(iVar5 + 0xc);
    uVar8 = uVar8 + (uVar10 >> 8 & 0xff00 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18 | uVar10 >> 0x18
                    );
    *(uint *)(iVar5 + 0xc) =
         (uVar8 & 0xff0000 | uVar8 >> 0x10) >> 8 | (uVar8 * 0x10000 | uVar8 & 0xff00) << 8;
  }
  else {
    if ((bVar1 & 0xf) == 0xf) goto LAB_c043810c;
    uVar4 = uVar4 & 0xdfff;
    if ((bVar1 & 1) != 0) {
      uVar4 = uVar4 | 0x2000;
      if (local_30[0] < pbVar11) {
        uVar8 = (uint)*local_30[0];
        local_30[0] = pbVar9 + 3;
        if (uVar8 == 0) {
          if (pbVar9 + 4 < pbVar11) {
            uVar8 = (uint)CONCAT11(*local_30[0],pbVar9[4]);
          }
          local_30[0] = pbVar9 + 5;
        }
      }
      else {
        uVar8 = 0;
      }
      *(ushort *)(iVar5 + 0x1a) = (ushort)(uVar8 << 8) | (ushort)(uVar8 >> 8);
    }
    if ((bVar1 & 2) != 0) {
      if (local_30[0] < pbVar11) {
        uVar6 = (ushort)*local_30[0];
        pbVar9 = local_30[0] + 1;
        if (uVar6 == 0) {
          if (local_30[0] + 2 < pbVar11) {
            uVar6 = CONCAT11(local_30[0][1],local_30[0][2]);
          }
          pbVar9 = local_30[0] + 3;
        }
      }
      else {
        uVar6 = 0;
        pbVar9 = local_30[0];
      }
      local_30[0] = pbVar9;
      uVar6 = (*(ushort *)(iVar5 + 0x16) >> 8 | *(ushort *)(iVar5 + 0x16) << 8) + uVar6;
      *(ushort *)(iVar5 + 0x16) = uVar6 * 0x100 | uVar6 >> 8;
    }
    if ((bVar1 & 4) != 0) {
      uVar8 = FUN_c0437548(local_30,pbVar11,*(uint *)(iVar5 + 0x10));
      *(uint *)(iVar5 + 0x10) = uVar8;
    }
    if ((bVar1 & 8) != 0) {
      uVar8 = FUN_c0437548(local_30,pbVar11,*(uint *)(iVar5 + 0xc));
      *(uint *)(iVar5 + 0xc) = uVar8;
    }
  }
  *(ushort *)(iVar5 + 0x14) = uVar4;
  uVar4 = 1;
  pbVar9 = local_30[0];
  if ((bVar1 & 0x20) != 0) {
    if (local_30[0] < pbVar11) {
      uVar4 = (ushort)*local_30[0];
      pbVar9 = local_30[0] + 1;
      if (uVar4 == 0) {
        if (local_30[0] + 2 < pbVar11) {
          uVar4 = CONCAT11(*pbVar9,local_30[0][2]);
        }
        pbVar9 = local_30[0] + 3;
      }
    }
    else {
      uVar4 = 0;
    }
  }
  uVar4 = (*(ushort *)(iVar7 + 0x918) >> 8 | *(ushort *)(iVar7 + 0x918) << 8) + uVar4;
  *(ushort *)(iVar7 + 0x918) = uVar4 * 0x100 | uVar4 >> 8;
  if (pbVar9 <= pbVar11) {
    uVar8 = (int)pbVar11 - (int)pbVar9 & 0xffff;
    pbVar11 = pbVar9;
    if (((uint)pbVar9 & 3) != 0) {
      pbVar11 = (byte *)((uint)pbVar9 & 0xfffffffc);
      memmove(pbVar11,pbVar9,uVar8);
    }
    _Dst = (ushort *)(pbVar11 + -(uint)*(ushort *)(iVar7 + 0x910));
    uVar8 = *(ushort *)(iVar7 + 0x910) + uVar8 & 0xffff;
    *param_2 = uVar8;
    *(ushort *)(iVar7 + 0x916) = (ushort)(uVar8 << 8) | (ushort)(uVar8 >> 8);
    memcpy(_Dst,(byte *)(iVar7 + 0x914),(uint)*(ushort *)(iVar7 + 0x910));
    uVar8 = 0;
    if ((bVar2 & 0xf) != 0) {
      iVar5 = (iVar12 - 1U >> 1) + 1;
      puVar3 = _Dst;
      do {
        uVar8 = *puVar3 + uVar8;
        iVar5 = iVar5 + -1;
        puVar3 = puVar3 + 1;
      } while (iVar5 != 0);
    }
    iVar5 = (uVar8 >> 0x10) + (uVar8 & 0xffff);
    _Dst[5] = ~((short)((uint)iVar5 >> 0x10) + (short)iVar5);
    return _Dst;
  }
LAB_c04382bc:
  *(undefined1 *)(param_3 + 6) = 1;
  return (ushort *)0x0;
}



/* c04382f8 FUN_c04382f8 */

/* Boundary evidence: original MIPS .pdata c04382f8..c0438407. Semantic name remains unreviewed. */

void FUN_c04382f8(undefined4 *param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_1 + 3;
  memset(param_1,0,0x120c);
  if (0x10 < param_2) {
    param_2 = 0x10;
  }
  if (0x10 < param_3) {
    param_3 = 0x10;
  }
  iVar2 = param_3 - 1;
  if (iVar2 != 0) {
    puVar1 = puVar3 + iVar2 * 0x24;
    do {
      *(char *)((int)puVar1 + 6) = (char)iVar2;
      *puVar1 = puVar1 + -0x24;
      iVar2 = iVar2 + -1;
      puVar1 = puVar1 + -0x24;
    } while (iVar2 != 0);
  }
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *puVar3 = puVar3 + param_3 * 0x24 + -0x24;
  *param_1 = puVar3;
  *(undefined1 *)(param_1 + 1) = 0xff;
  *(undefined1 *)((int)param_1 + 5) = 0xff;
  *(undefined1 *)((int)param_1 + 6) = 1;
  if (param_4 != 0) {
    *(byte *)((int)param_1 + 7) = *(byte *)((int)param_1 + 7) | 4;
  }
  if (param_5 != 0) {
    *(byte *)((int)param_1 + 7) = *(byte *)((int)param_1 + 7) | 2;
  }
  *(char *)(param_1 + 2) = (char)param_3;
  *(char *)((int)param_1 + 9) = (char)param_2;
  return;
}



/* c0438408 FUN_c0438408 */

/* Boundary evidence: original MIPS .pdata c0438408..c0438473. Semantic name remains unreviewed. */

void FUN_c0438408(undefined4 param_1,undefined4 param_2,byte *param_3,int param_4,
                 undefined4 *param_5)

{
  int iVar1;
  char *_Dest;
  
  _Dest = (char *)*param_5;
  if (param_4 == 4) {
    iVar1 = sprintf(_Dest,"%u.%u.%u.%u",(uint)*param_3,(uint)param_3[1],(uint)param_3[2],
                    (uint)param_3[3]);
    _Dest = _Dest + iVar1;
  }
  *param_5 = _Dest;
  return;
}



/* c0438474 FUN_c0438474 */

/* Boundary evidence: original MIPS .pdata c0438474..c04384d7. Semantic name remains unreviewed. */

void FUN_c0438474(undefined4 param_1,undefined4 param_2,byte *param_3,undefined4 param_4,
                 int *param_5)

{
  int iVar1;
  char *_Dest;
  
  _Dest = (char *)*param_5;
  iVar1 = sprintf(_Dest,"%02X%02X,MaxSlot=%u,CompSlot=%u",(uint)*param_3,(uint)param_3[1],
                  (uint)param_3[2],(uint)param_3[3]);
  *param_5 = (int)(_Dest + iVar1);
  return;
}



/* c04384e4 FUN_c04384e4 */

void FUN_c04384e4(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  param_1[6] = 0;
  *(char *)(param_1 + 7) = (char)param_1[3];
  *(char *)((int)param_1 + 0x1d) = (char)param_1[5];
  param_1[8] = 0;
  param_1[0x495] = 0;
  if ((*(int *)(iVar1 + 0x6c) == 0) &&
     ((*(int *)(iVar1 + 0xb48) != 0 || ((*(uint *)(iVar1 + 0x62c) & 2) != 0)))) {
    param_1[8] = *(int *)(iVar1 + 0x750);
  }
  return;
}



/* c0438588 FUN_c0438588 */

/* Boundary evidence: original MIPS .pdata c0438588..c043860f. Semantic name remains unreviewed. */

undefined4 FUN_c0438588(int param_1,int param_2,void *param_3,uint param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  if ((param_4 < 4) || (iVar2 = memcmp(param_3,&DAT_c044d340,2), iVar2 != 0)) {
    *(undefined4 *)(param_2 + 0xc) = 4;
  }
  else {
    uVar1 = *(undefined1 *)((int)param_3 + 3);
    if ((uint)*(byte *)((int)param_3 + 2) <= *(uint *)(param_1 + 0xc)) {
      *(byte *)(param_1 + 0x1c) = *(byte *)((int)param_3 + 2);
    }
    *(undefined1 *)(param_1 + 0x1d) = uVar1;
  }
  return 0;
}



/* c0438610 FUN_c0438610 */

/* Boundary evidence: original MIPS .pdata c0438610..c0438717. Semantic name remains unreviewed. */

undefined4
FUN_c0438610(int param_1,undefined4 param_2,undefined1 *param_3,undefined4 *param_4,uint *param_5)

{
  undefined2 uVar1;
  int iVar2;
  void *_Buf1;
  
  _Buf1 = (void *)*param_4;
  if ((((_Buf1 == (void *)0x0) || (*param_5 < 4)) ||
      (iVar2 = memcmp(_Buf1,&DAT_c044d340,2), iVar2 != 0)) ||
     (*(uint *)(param_1 + 8) < (uint)*(byte *)((int)_Buf1 + 2))) {
    uVar1 = DAT_c044d340;
    *(char *)(param_1 + 0x124d) = (char)((ushort)DAT_c044d340 >> 8);
    *(undefined1 *)(param_1 + 0x124c) = (char)uVar1;
    *(char *)(param_1 + 0x124e) = (char)*(undefined4 *)(param_1 + 8);
    *(char *)(param_1 + 0x124f) = (char)*(undefined4 *)(param_1 + 0x10);
    *param_3 = 3;
    *param_4 = (undefined1 *)(param_1 + 0x124c);
    *param_5 = 4;
  }
  else {
    *param_3 = 2;
    *(undefined4 *)(param_1 + 0x28) = 1;
    *(undefined1 *)(param_1 + 0x2c) = *(undefined1 *)((int)_Buf1 + 2);
    *(undefined1 *)(param_1 + 0x2d) = *(undefined1 *)((int)_Buf1 + 3);
  }
  return 0;
}



/* c0438718 FUN_c0438718 */

/* Boundary evidence: original MIPS .pdata c0438718..c0438797. Semantic name remains unreviewed. */

undefined4 FUN_c0438718(int *param_1,undefined4 param_2,undefined1 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x6c) != 0) {
    iVar1 = FUN_c0439bb8();
    param_1[8] = iVar1;
  }
  *param_3 = *(undefined1 *)((int)param_1 + 0x23);
  param_3[1] = (char)*(undefined2 *)((int)param_1 + 0x22);
  param_3[2] = (char)((uint)param_1[8] >> 8);
  param_3[3] = (char)param_1[8];
  *param_4 = 4;
  return 0;
}



/* c04387f4 FUN_c04387f4 */

/* Boundary evidence: original MIPS .pdata c04387f4..c043886f. Semantic name remains unreviewed. */

undefined4 FUN_c04387f4(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = memcmp(param_1 + 8,(int *)(iVar2 + 0x750),4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 4) = 3;
  }
  else {
    *(undefined4 *)(param_2 + 0xc) = 3;
    param_1[8] = *(int *)(iVar2 + 0x750);
  }
  return 0;
}



/* c0438870 FUN_c0438870 */

/* Boundary evidence: original MIPS .pdata c0438870..c04389df. Semantic name remains unreviewed. */

undefined4
FUN_c0438870(int *param_1,undefined4 param_2,undefined1 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar3 = (undefined1 *)*param_4;
  if (puVar3 == (undefined1 *)0x0) {
    *param_4 = &DAT_c044d864;
    *param_5 = 4;
  }
  else {
    iVar4 = CONCAT31(CONCAT21(CONCAT11(*puVar3,puVar3[1]),puVar3[2]),puVar3[3]);
    if (*(int *)(*param_1 + 0x6c) == 0) {
      param_1[0xc] = iVar4;
      if (iVar4 == 0) {
        if (param_1[8] == 0) {
          param_1[8] = *(int *)(*param_1 + 0x750);
        }
        iVar4 = param_1[8];
        *(char *)(param_1 + 0x494) = (char)((uint)iVar4 >> 0x18);
        *(char *)((int)param_1 + 0x1251) = (char)((uint)iVar4 >> 0x10);
        *(char *)((int)param_1 + 0x1252) = (char)((uint)iVar4 >> 8);
        *(char *)((int)param_1 + 0x1253) = (char)iVar4 + '\x01';
        *param_3 = 3;
        *param_4 = param_1 + 0x494;
        return 0;
      }
      uVar2 = 2;
    }
    else {
      if (param_1[0xc] == 0) {
        iVar1 = FUN_c0439bb8();
        param_1[0xc] = iVar1;
      }
      iVar1 = param_1[0xc];
      if (iVar1 != 0) {
        if (iVar4 == iVar1) {
          *param_3 = 2;
          return 0;
        }
        *(char *)(param_1 + 0x494) = (char)((uint)iVar1 >> 0x18);
        *(char *)((int)param_1 + 0x1251) = (char)((uint)iVar1 >> 0x10);
        *(char *)((int)param_1 + 0x1252) = (char)((uint)iVar1 >> 8);
        *(char *)((int)param_1 + 0x1253) = (char)iVar1;
        *param_3 = 3;
        *param_4 = param_1 + 0x494;
        return 0;
      }
      uVar2 = 4;
    }
    *param_3 = uVar2;
  }
  return 0;
}



/* c0438c50 FUN_c0438c50 */

/* Boundary evidence: original MIPS .pdata c0438c50..c0438d37. Semantic name remains unreviewed. */

void FUN_c0438c50(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (*(uint *)(*param_1 + 0x62c) & 8) != 0;
  if (bVar1) {
    uVar2 = 2;
  }
  FUN_c044a6b8(param_1[1],&DAT_c044d344,uVar2,(uint)bVar1);
  return;
}



/* c0438d38 FUN_c0438d38 */

/* Boundary evidence: original MIPS .pdata c0438d38..c0438d5b. Semantic name remains unreviewed. */

undefined4 FUN_c0438d38(int *param_1)

{
  FUN_c0436b1c(*(undefined4 **)(*param_1 + 0xab0));
  return 0;
}



/* c0438d5c FUN_c0438d5c */

/* Boundary evidence: original MIPS .pdata c0438d5c..c0438d8b. Semantic name remains unreviewed. */

undefined4 FUN_c0438d5c(int *param_1)

{
  FUN_c0435a3c(*param_1);
  param_1[10] = 0;
  return 0;
}



/* c0438d8c FUN_c0438d8c */

/* Boundary evidence: original MIPS .pdata c0438d8c..c0438dab. Semantic name remains unreviewed. */

undefined4 FUN_c0438d8c(int param_1)

{
  FUN_c0439600(param_1);
  return 0;
}



/* c0438dac FUN_c0438dac */

/* Boundary evidence: original MIPS .pdata c0438dac..c0438ddb. Semantic name remains unreviewed. */

undefined4 FUN_c0438dac(int *param_1)

{
  if (*(int *)(*param_1 + 0x54) == 0) {
    FUN_c0436b1c(*(undefined4 **)(*param_1 + 0xab0));
  }
  return 0;
}



/* c0438ddc FUN_c0438ddc */

/* Boundary evidence: original MIPS .pdata c0438ddc..c0438df7. Semantic name remains unreviewed. */

void FUN_c0438ddc(int *param_1,uint param_2,void *param_3,uint param_4)

{
  FUN_c0447448(*param_1,param_2,param_3,param_4);
  return;
}



/* c0438df8 FUN_c0438df8 */

/* Boundary evidence: original MIPS .pdata c0438df8..c0438e1b. Semantic name remains unreviewed. */

void FUN_c0438df8(int param_1)

{
  memset((void *)(param_1 + 0x10),0,8);
  return;
}



/* c0438e1c FUN_c0438e1c */

/* Boundary evidence: original MIPS .pdata c0438e1c..c0438e3b. Semantic name remains unreviewed. */

undefined4 FUN_c0438e1c(int *param_1)

{
  FUN_c04335a8(*param_1);
  return 0;
}



/* c0438e3c FUN_c0438e3c */

/* Boundary evidence: original MIPS .pdata c0438e3c..c0438e5b. Semantic name remains unreviewed. */

undefined4 FUN_c0438e3c(int *param_1)

{
  FUN_c04335c4(*param_1);
  return 0;
}



/* c0438e5c FUN_c0438e5c */

/* Boundary evidence: original MIPS .pdata c0438e5c..c043907f. Semantic name remains unreviewed. */

int FUN_c0438e5c(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = (int *)FUN_c04343d0(param_1,0x70);
  if (piVar1 == (int *)0x0) {
LAB_c0438ea0:
    iVar4 = 8;
  }
  else {
    iVar4 = FUN_c04335e0(param_1,0x8057,&PTR_FUN_c044d430,piVar1);
    if ((iVar4 == 0) && (iVar4 = FUN_c04335e0(param_1,0x57,&PTR_FUN_c044d44c,piVar1), iVar4 == 0)) {
      *piVar1 = param_1;
      piVar2 = FUN_c044a4d4(&PTR_s_IPV6CP_c044d404,FUN_c0438df8,(int)piVar1);
      piVar1[1] = (int)piVar2;
      if (piVar2 != (int *)0x0) {
        FUN_c0432908((HKEY)0x80000002,L"Comm\\ppp\\Parms",L"IPV6Flags",4);
        iVar3 = FUN_c0432908((HKEY)0x80000002,L"Comm\\ppp\\Parms",L"IPV6IFID",3);
        piVar1[0xd] = (uint)(iVar3 == 1);
        iVar3 = FUN_c0432908((HKEY)0x80000002,L"Comm\\ppp\\Parms",L"IPV6RandomIFID",3);
        piVar1[0x10] = (uint)(iVar3 == 1);
        iVar3 = FUN_c0434810(0,piVar1 + 0x11,(size_t *)(piVar1 + 0x13));
        if (iVar3 == 0) {
          piVar1[0x13] = 0;
        }
        piVar1[0x16] = 8;
        FUN_c043483c(piVar1 + 0x14,(uint *)(piVar1 + 0x16));
        FUN_c04397e8((int)piVar1);
        FUN_c044adc0((int *)piVar1[1]);
        goto LAB_c0438eb4;
      }
      goto LAB_c0438ea0;
    }
  }
  FUN_c0434420(param_1,piVar1);
  piVar1 = (int *)0x0;
LAB_c0438eb4:
  *param_2 = piVar1;
  return iVar4;
}



/* c0439080 FUN_c0439080 */

/* Boundary evidence: original MIPS .pdata c0439080..c043909b. Semantic name remains unreviewed. */

void FUN_c0439080(int param_1)

{
  FUN_c044adc0(*(int **)(param_1 + 4));
  return;
}



/* c043909c FUN_c043909c */

/* Boundary evidence: original MIPS .pdata c043909c..c04390b7. Semantic name remains unreviewed. */

void FUN_c043909c(int param_1)

{
  FUN_c044a990(*(int **)(param_1 + 4));
  return;
}



/* c04390b8 FUN_c04390b8 */

/* Boundary evidence: original MIPS .pdata c04390b8..c04390d3. Semantic name remains unreviewed. */

void FUN_c04390b8(int param_1)

{
  FUN_c044ae68(*(int **)(param_1 + 4));
  return;
}



/* c04390d4 FUN_c04390d4 */

/* Boundary evidence: original MIPS .pdata c04390d4..c04390ef. Semantic name remains unreviewed. */

void FUN_c04390d4(int param_1)

{
  FUN_c044aad0(*(int **)(param_1 + 4));
  return;
}



/* c04390f0 FUN_c04390f0 */

/* Boundary evidence: original MIPS .pdata c04390f0..c043912b. Semantic name remains unreviewed. */

void FUN_c04390f0(int *param_1)

{
  if (param_1 != (int *)0x0) {
    FUN_c044a668((HLOCAL)param_1[1]);
    FUN_c0434420(*param_1,param_1);
  }
  return;
}



/* c043912c FUN_c043912c */

/* Boundary evidence: original MIPS .pdata c043912c..c0439147. Semantic name remains unreviewed. */

void FUN_c043912c(int param_1)

{
  FUN_c044af20(*(int **)(param_1 + 4));
  return;
}



/* c0439148 FUN_c0439148 */

/* Boundary evidence: original MIPS .pdata c0439148..c0439163. Semantic name remains unreviewed. */

void FUN_c0439148(int param_1)

{
  FUN_c044aa3c(*(int **)(param_1 + 4));
  return;
}



/* c0439164 FUN_c0439164 */

/* Boundary evidence: original MIPS .pdata c0439164..c04391bb. Semantic name remains unreviewed. */

void FUN_c0439164(int *param_1,int param_2)

{
  if (*(int *)(param_1[1] + 8) < 2) {
    FUN_c043bdbc(*(int **)(*param_1 + 0xaac));
  }
  FUN_c044afb0((int *)param_1[1],*(byte **)(param_2 + 8),*(uint *)(param_2 + 4));
  return;
}



/* c04391bc FUN_c04391bc */

/* Boundary evidence: original MIPS .pdata c04391bc..c0439213. Semantic name remains unreviewed. */

void FUN_c04391bc(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (*(int *)(param_1[1] + 8) == 9) {
    FUN_c0433300((int)piVar1,param_2);
    FUN_c0434ccc(piVar1,param_2,2);
  }
  return;
}



/* c0439214 FUN_c0439214 */

/* Boundary evidence: original MIPS .pdata c0439214..c04392ef. Semantic name remains unreviewed. */

int FUN_c0439214(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_res4 [3];
  ushort local_20 [4];
  
  iVar2 = *param_1;
  piVar5 = *(int **)(iVar2 + 0xaa4);
  iVar3 = -0x3fffffff;
  if (*(int *)(param_1[1] + 8) == 9) {
    iVar4 = *(int *)(param_2 + 0xc);
    *(int *)(iVar2 + 0xb58) = *(int *)(iVar2 + 0xb58) + iVar4;
    *(int *)(iVar2 + 0xb60) = *(int *)(iVar2 + 0xb60) + 1;
    local_20[0] = 0x57;
    local_res4[0] = param_2;
    if ((*(int *)(*(int *)(iVar2 + 0xab0) + 8) == 0) ||
       (iVar1 = FUN_c043f5b0(iVar2,local_res4,local_20), iVar1 != 0)) {
      *(int *)(iVar2 + 0xb80) = *(int *)(iVar2 + 0xb80) + iVar4;
      *(int *)(iVar2 + 0xb88) = *(int *)(local_res4[0] + 0xc) + *(int *)(iVar2 + 0xb88);
      iVar3 = FUN_c0446f50(piVar5,(uint)local_20[0],local_res4[0]);
    }
  }
  return iVar3;
}



/* c04392f0 FUN_c04392f0 */

void FUN_c04392f0(byte *param_1,int param_2,byte *param_3)

{
  byte bVar1;
  
  if (param_2 == 8) {
    *(undefined4 *)param_3 = *(undefined4 *)param_1;
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_1 + 4);
    *param_3 = *param_3 ^ 2;
  }
  else if (param_2 == 6) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    bVar1 = param_1[2];
    param_3[3] = 0xff;
    param_3[4] = 0xfe;
    param_3[2] = bVar1;
    param_3[5] = param_1[3];
    param_3[6] = param_1[4];
    param_3[7] = param_1[5];
    *param_3 = *param_3 ^ 2;
  }
  return;
}



/* c043938c FUN_c043938c */

/* Boundary evidence: original MIPS .pdata c043938c..c04395ff. Semantic name remains unreviewed. */

void FUN_c043938c(int param_1,byte *param_2,void *param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x28);
  bVar2 = false;
  do {
    if ((3 < uVar4) || ((1 << (uVar4 & 0x1f) & *(uint *)(param_1 + 0x24)) == 0)) {
      if (uVar4 == 0) {
        if (*(int *)(param_1 + 0x34) == 0) goto LAB_c0439548;
        *(undefined4 *)param_2 = *(undefined4 *)(param_1 + 0x2c);
        *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x30);
      }
      if (uVar4 != 1) {
        if (uVar4 == 2) {
          if (*(int *)(param_1 + 0x4c) != 0) {
            FUN_c04392f0((byte *)(param_1 + 0x44),*(int *)(param_1 + 0x4c),param_2);
            goto LAB_c0439508;
          }
        }
        else if (uVar4 == 3) {
          if (*(int *)(param_1 + 0x58) != 0) {
            *(undefined4 *)param_2 = *(undefined4 *)(param_1 + 0x50);
            *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x54);
            bVar1 = *param_2;
LAB_c0439504:
            *param_2 = bVar1 & 0xfd;
            goto LAB_c0439508;
          }
        }
        else if (uVar4 == 4) {
          FUN_c04496e4(8,param_2);
          bVar1 = *param_2;
          goto LAB_c0439504;
        }
        goto LAB_c0439548;
      }
      if (*(int *)(param_1 + 0x40) == 0) goto LAB_c0439548;
      *(undefined4 *)param_2 = *(undefined4 *)(param_1 + 0x38);
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x3c);
LAB_c0439508:
      if (((param_3 == (void *)0x0) || (iVar3 = memcmp(param_2,param_3,8), iVar3 != 0)) &&
         (iVar3 = memcmp(param_2,&DAT_c04318b8,8), iVar3 != 0)) {
        bVar2 = true;
      }
      else if (3 >= uVar4) goto LAB_c0439548;
    }
    else {
LAB_c0439548:
      uVar4 = uVar4 + 1;
    }
  } while (!bVar2);
  if (uVar4 == 4) {
    if (((param_3 != (void *)0x0) || ((*(uint *)(param_1 + 0x24) & 2) != 0)) ||
       (*(int *)(param_1 + 0x34) != 0)) goto LAB_c04395c4;
    FUN_c0432c04((HKEY)0x80000002,L"Comm\\ppp\\Parms",L"IPV6RandomIFID",3);
  }
  if (uVar4 < 4) {
    uVar4 = uVar4 + 1;
  }
LAB_c04395c4:
  *(uint *)(param_1 + 0x28) = uVar4;
  return;
}



/* c0439600 FUN_c0439600 */

/* Boundary evidence: original MIPS .pdata c0439600..c0439643. Semantic name remains unreviewed. */

void FUN_c0439600(int param_1)

{
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_c043938c(param_1,(byte *)(param_1 + 8),(void *)0x0);
  memset((void *)(param_1 + 0x10),0,8);
  return;
}



/* c0439644 FUN_c0439644 */

/* Boundary evidence: original MIPS .pdata c0439644..c0439753. Semantic name remains unreviewed. */

undefined4
FUN_c0439644(int param_1,undefined4 param_2,undefined1 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 *_Buf1;
  void *_Buf2;
  
  _Buf1 = (undefined4 *)*param_4;
  if (_Buf1 == (undefined4 *)0x0) {
    *param_4 = &DAT_c04318b8;
    *param_5 = 8;
    return 0;
  }
  iVar1 = memcmp(_Buf1,&DAT_c04318b8,8);
  _Buf2 = (void *)(param_1 + 8);
  if (iVar1 == 0) {
    iVar1 = memcmp(_Buf2,&DAT_c04318b8,8);
    if (iVar1 != 0) {
      uVar2 = 4;
      goto LAB_c0439704;
    }
  }
  else {
    iVar1 = memcmp(_Buf1,_Buf2,8);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x10) = *_Buf1;
      *(undefined4 *)(param_1 + 0x14) = _Buf1[1];
      *param_3 = 2;
      return 0;
    }
  }
  FUN_c043938c(param_1,(byte *)(param_1 + 0x18),_Buf2);
  *param_4 = (byte *)(param_1 + 0x18);
  uVar2 = 3;
LAB_c0439704:
  *param_3 = uVar2;
  return 0;
}



/* c043977c FUN_c043977c */

/* Boundary evidence: original MIPS .pdata c043977c..c04397e7. Semantic name remains unreviewed. */

undefined4 FUN_c043977c(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,&DAT_c04318b8,8);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = *param_3;
    *(undefined4 *)(param_1 + 0xc) = param_3[1];
  }
  return 0;
}



/* c04397e8 FUN_c04397e8 */

/* Boundary evidence: original MIPS .pdata c04397e8..c0439817. Semantic name remains unreviewed. */

void FUN_c04397e8(int param_1)

{
  FUN_c044a6b8(*(int *)(param_1 + 4),&DAT_c044d468,2,2);
  return;
}



/* c0439818 FUN_c0439818 */

/* Boundary evidence: original MIPS .pdata c0439818..c043997b. Semantic name remains unreviewed. */

void FUN_c0439818(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *param_1;
  uVar3 = 0x5dc;
  iVar1 = wcscmp((wchar_t *)(iVar5 + 0x76c),L"vpn");
  if (iVar1 == 0) {
    uVar3 = 0x578;
  }
  *(undefined2 *)(param_1 + 5) = uVar3;
  *(undefined2 *)((int)param_1 + 0x16) = uVar3;
  if (param_3 == 0) {
    *(short *)(param_1 + 5) = (short)*(undefined4 *)(param_2 + 4) + -2;
    *(short *)((int)param_1 + 0x16) = (short)*(undefined4 *)(param_2 + 8) + -2;
  }
  FUN_c043ae80(param_1);
  uVar4 = 1;
  uVar2 = 1;
  if ((short)param_1[6] != 0x5dc) {
    uVar2 = 2;
  }
  FUN_c044a770(param_1[1],1,uVar2,1);
  if (*(int *)(iVar5 + 0x6c) != 0) {
    iVar1 = FUN_c0439bb8();
    if (iVar1 != 0) {
      uVar4 = 3;
    }
    FUN_c044a770(param_1[1],3,uVar4,0);
  }
  if (param_1[2] != 0) {
    FUN_c044af20((int *)param_1[1]);
  }
  return;
}



/* c043997c FUN_c043997c */

/* Boundary evidence: original MIPS .pdata c043997c..c0439a3b. Semantic name remains unreviewed. */

void FUN_c043997c(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  wchar_t awStack_220 [262];
  uint local_14;
  
  local_14 = DAT_c044d82c;
  iVar2 = *param_1;
  param_1[2] = 1;
  FUN_c0445680(*(int *)(iVar2 + 0xaa4),param_1 + 3,param_1 + 4);
  StringCchPrintfW(awStack_220,0x105,L"Comm\\ppp\\Parms\\Line\\%s",iVar2 + 0x78e);
  uVar1 = 4;
  FUN_c0432908((HKEY)0x80000002,awStack_220,L"ACCM",4);
  FUN_c04470c8(*(int **)(iVar2 + 0xaa4),FUN_c0439818,param_1,uVar1);
  FUN_c0449d30(local_14);
  return;
}



/* c0439a3c FUN_c0439a3c */

/* Boundary evidence: original MIPS .pdata c0439a3c..c0439a7f. Semantic name remains unreviewed. */

void FUN_c0439a3c(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_c044aa3c(*(int **)(param_1 + 4));
  if (*(int *)(*(int *)(param_1 + 4) + 8) == 0) {
    FUN_c0434580((int *)(param_1 + 0x54));
  }
  return;
}



/* c0439a80 FUN_c0439a80 */

/* Boundary evidence: original MIPS .pdata c0439a80..c0439a9b. Semantic name remains unreviewed. */

void FUN_c0439a80(int *param_1,uint param_2,void *param_3,uint param_4)

{
  FUN_c0447448(*param_1,param_2,param_3,param_4);
  return;
}



/* c0439a9c FUN_c0439a9c */

/* Boundary evidence: original MIPS .pdata c0439a9c..c0439bb7. Semantic name remains unreviewed. */

void FUN_c0439a9c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iStack_40;
  uint local_3c;
  uint local_38;
  uint local_2c;
  uint local_28;
  int local_1c;
  int local_18;
  
  uVar1 = 0x2c;
  iVar4 = *param_1;
  memset(&iStack_40,0,0x2c);
  if (*(int *)(param_1[1] + 8) == 9) {
    local_3c = (uint)*(ushort *)(param_1 + 0xc);
    uVar3 = 0x100;
    local_1c = param_1[0xd];
    uVar2 = 0x100;
    local_2c = 0x100;
    if (param_1[0x10] != 0) {
      uVar2 = 0x500;
      local_2c = 0x500;
    }
    if (param_1[0x11] != 0) {
      local_2c = uVar2 | 0x200;
    }
    local_38 = (uint)*(ushort *)(param_1 + 6);
    local_18 = param_1[7];
    local_28 = 0x100;
    if (param_1[10] != 0) {
      uVar3 = 0x500;
      local_28 = 0x500;
    }
    if (param_1[0xb] != 0) {
      local_28 = uVar3 | 0x200;
    }
  }
  else {
    local_3c = 0x5dc;
    if (*(ushort *)(param_1 + 5) < 0x5dc) {
      local_3c = (uint)*(ushort *)(param_1 + 5);
    }
    local_38 = (uint)*(ushort *)((int)param_1 + 0x16);
    local_1c = -1;
    local_2c = 0x100;
    local_18 = -1;
    local_28 = 0x100;
  }
  FUN_c044721c(*(int **)(iVar4 + 0xaa4),&iStack_40,uVar1,param_4);
  return;
}



/* c0439bb8 FUN_c0439bb8 */

undefined4 FUN_c0439bb8(void)

{
  return 0;
}



/* c0439bc0 FUN_c0439bc0 */

/* Boundary evidence: original MIPS .pdata c0439bc0..c0439c0f. Semantic name remains unreviewed. */

undefined4 FUN_c0439bc0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0445f68(*(int **)(*param_1 + 0xaa4),0,0,param_4);
  if (*(int *)(param_1[1] + 8) == 0) {
    FUN_c0434580(param_1 + 0x15);
  }
  return 0;
}



/* c0439c10 FUN_c0439c10 */

/* Boundary evidence: original MIPS .pdata c0439c10..c0439c2f. Semantic name remains unreviewed. */

undefined4 FUN_c0439c10(int *param_1)

{
  FUN_c04335a8(*param_1);
  return 0;
}



/* c0439c30 FUN_c0439c30 */

/* Boundary evidence: original MIPS .pdata c0439c30..c0439c4f. Semantic name remains unreviewed. */

undefined4 FUN_c0439c30(int *param_1)

{
  FUN_c04335c4(*param_1);
  return 0;
}



/* c0439c50 FUN_c0439c50 */

/* Boundary evidence: original MIPS .pdata c0439c50..c0439c6b. Semantic name remains unreviewed. */

void FUN_c0439c50(int param_1)

{
  FUN_c044aad0(*(int **)(param_1 + 4));
  return;
}



/* c0439c6c FUN_c0439c6c */

/* Boundary evidence: original MIPS .pdata c0439c6c..c0439c97. Semantic name remains unreviewed. */

void FUN_c0439c6c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined2 auStack_20 [2];
  undefined4 local_1c;
  undefined4 local_18;
  
  local_1c = param_5;
  local_18 = param_4;
  FUN_c0433240(*param_1,auStack_20);
  return;
}



/* c0439c98 FUN_c0439c98 */

/* Boundary evidence: original MIPS .pdata c0439c98..c0439cdf. Semantic name remains unreviewed. */

void FUN_c0439c98(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4,uint param_5)

{
  if (3 < param_5) {
    *(undefined1 *)(param_4 + -1) = 10;
    *param_4 = param_1[9];
    FUN_c0447448(*param_1,0xc021,param_4 + -1,param_5 + 4);
  }
  return;
}



/* c0439ce0 FUN_c0439ce0 */

/* Boundary evidence: original MIPS .pdata c0439ce0..c0439d5f. Semantic name remains unreviewed. */

void FUN_c0439ce0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  uint local_10;
  
  local_10 = DAT_c044d82c;
  iVar1 = param_1[0x21];
  local_15 = 8;
  iVar2 = param_1[9];
  param_1[0x21] = iVar1 + 1;
  local_18 = 9;
  local_17 = (undefined1)(iVar1 + 1);
  local_16 = 0;
  local_14 = (undefined1)((uint)iVar2 >> 0x18);
  local_13 = (undefined1)((uint)iVar2 >> 0x10);
  local_12 = (undefined1)((uint)iVar2 >> 8);
  local_11 = (undefined1)iVar2;
  FUN_c0447448(*param_1,0xc021,&local_18,8);
  FUN_c0449d30(local_10);
  return;
}



/* c0439d60 FUN_c0439d60 */

/* Boundary evidence: original MIPS .pdata c0439d60..c0439d7b. Semantic name remains unreviewed. */

void FUN_c0439d60(int param_1)

{
  FUN_c044adc0(*(int **)(param_1 + 4));
  return;
}



/* c0439d7c FUN_c0439d7c */

/* Boundary evidence: original MIPS .pdata c0439d7c..c0439e23. Semantic name remains unreviewed. */

void FUN_c0439d7c(int *param_1,undefined *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_c044a990((int *)param_1[1]);
  iVar2 = param_1[1];
  if ((*(int *)(iVar2 + 8) == 0) ||
     (iVar1 = FUN_c0434508(param_1 + 0x15,(int)param_2,param_3,iVar2), iVar1 != 0)) {
    if (param_2 != (undefined *)0x0) {
      (*(code *)param_2)(param_3);
    }
  }
  else if (*(int *)(param_1[1] + 8) == 2) {
    FUN_c0445f68(*(int **)(*param_1 + 0xaa4),0,0,iVar2);
  }
  return;
}



/* c0439e24 FUN_c0439e24 */

/* Boundary evidence: original MIPS .pdata c0439e24..c0439e3f. Semantic name remains unreviewed. */

void FUN_c0439e24(int param_1)

{
  FUN_c044adc0(*(int **)(param_1 + 4));
  return;
}



/* c0439e40 FUN_c0439e40 */

/* Boundary evidence: original MIPS .pdata c0439e40..c0439e5b. Semantic name remains unreviewed. */

void FUN_c0439e40(int param_1)

{
  FUN_c044a990(*(int **)(param_1 + 4));
  return;
}



/* c0439e5c FUN_c0439e5c */

/* Boundary evidence: original MIPS .pdata c0439e5c..c0439e77. Semantic name remains unreviewed. */

void FUN_c0439e5c(int param_1)

{
  FUN_c044ae68(*(int **)(param_1 + 4));
  return;
}



/* c0439fb8 FUN_c0439fb8 */

/* Boundary evidence: original MIPS .pdata c0439fb8..c043a1db. Semantic name remains unreviewed. */

int FUN_c0439fb8(int param_1,undefined4 *param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  size_t sVar4;
  int *piVar5;
  wchar_t *_Str2;
  int iVar6;
  wchar_t local_238 [260];
  uint local_30;
  
  local_30 = DAT_c044d82c;
  piVar2 = (int *)FUN_c04343d0(param_1,0x88);
  if (piVar2 == (int *)0x0) {
LAB_c043a010:
    iVar6 = 8;
  }
  else {
    iVar6 = FUN_c04335e0(param_1,0xc021,&PTR_FUN_c044d4f0,piVar2);
    if (iVar6 == 0) {
      *piVar2 = param_1;
      piVar2[0x15] = 0;
      CTEInitTimer(piVar2 + 0x17);
      piVar2[0x1e] = 15000;
      piVar2[0x20] = 1000;
      memset(local_238,0,0x208);
      wcscpy(local_238,L"PPPoE");
      FUN_c0432908((HKEY)0x80000002,L"Comm\\ppp\\Parms",L"LcpIdleDisconnectMs",4);
      _Str2 = local_238;
      bVar1 = false;
      if (local_238[0] != L'\0') {
        do {
          iVar3 = _wcsicmp((wchar_t *)(param_1 + 0x76c),_Str2);
          if (iVar3 == 0) {
            bVar1 = true;
            break;
          }
          sVar4 = wcslen(_Str2);
          _Str2 = _Str2 + sVar4 + 1;
        } while (*_Str2 != L'\0');
      }
      if (!bVar1) {
        piVar2[0x1e] = 0;
      }
      piVar5 = FUN_c044a4d4(&PTR_DAT_c044d4c4,&LAB_c043ae40,(int)piVar2);
      piVar2[1] = (int)piVar5;
      if (piVar5 != (int *)0x0) {
        FUN_c043aef8(piVar2);
        FUN_c044adc0((int *)piVar2[1]);
        goto LAB_c043a024;
      }
      goto LAB_c043a010;
    }
  }
  FUN_c0434420(param_1,piVar2);
  piVar2 = (int *)0x0;
LAB_c043a024:
  *param_2 = piVar2;
  FUN_c0449d30(local_30);
  return iVar6;
}



/* c043a1dc FUN_c043a1dc */

/* Boundary evidence: original MIPS .pdata c043a1dc..c043a21f. Semantic name remains unreviewed. */

void FUN_c043a1dc(int *param_1)

{
  if (param_1 != (int *)0x0) {
    CTEStopTimer(param_1 + 0x17);
    FUN_c044a668((HLOCAL)param_1[1]);
    FUN_c0434420(*param_1,param_1);
  }
  return;
}



/* c043a220 FUN_c043a220 */

/* Boundary evidence: original MIPS .pdata c043a220..c043a2bf. Semantic name remains unreviewed. */

undefined4 FUN_c043a220(int param_1,int param_2,int param_3,void *param_4,uint *param_5)

{
  void *_Src;
  uint _Size;
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == 0) {
    _Src = (void *)(param_1 + 0x30);
  }
  else {
    _Src = (void *)(param_1 + 0x18);
  }
  if (param_3 == 1) {
    _Size = 2;
  }
  else {
    if (param_3 != 3) {
      return 0x57;
    }
    _Size = 4;
    _Src = (void *)((int)_Src + 8);
  }
  if (*param_5 < _Size) {
    uVar1 = 0x7a;
  }
  else {
    memcpy(param_4,_Src,_Size);
  }
  *param_5 = _Size;
  return uVar1;
}



/* c043a2c0 FUN_c043a2c0 */

/* Boundary evidence: original MIPS .pdata c043a2c0..c043a33b. Semantic name remains unreviewed. */

undefined4 FUN_c043a2c0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *param_1;
  CTEStopTimer(param_1 + 0x17);
  FUN_c043ae80(param_1);
  FUN_c0439a9c(param_1,param_2,param_3,param_4);
  FUN_c043c25c(*(int **)(iVar2 + 0xaac));
  while (puVar1 = *(undefined4 **)(iVar2 + 0xab4), puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(iVar2 + 0xab4) = *puVar1;
    *puVar1 = 0;
    FUN_c0434420(iVar2,puVar1);
  }
  return 0;
}



/* c043a33c FUN_c043a33c */

/* Boundary evidence: original MIPS .pdata c043a33c..c043a43b. Semantic name remains unreviewed. */

void FUN_c043a33c(undefined4 param_1,int *param_2)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  
  DVar1 = GetTickCount();
  FUN_c04335a8(*param_2);
  iVar2 = *param_2;
  if (*(int *)(iVar2 + 0xcd0) == 0) {
    if ((uint)param_2[0x1e] < DVar1 - param_2[0x1f]) {
      *(undefined4 *)(iVar2 + 0xcd4) = 1;
      FUN_c0439d7c(param_2,(undefined *)0x0,0);
      goto LAB_c043a420;
    }
    FUN_c0439ce0(param_2);
    uVar3 = param_2[0x20];
    if (uVar3 == 0) goto LAB_c043a420;
    iVar2 = *(int *)(param_2[1] + 8);
  }
  else {
    *(undefined4 *)(iVar2 + 0xcd0) = 0;
    uVar3 = (uint)param_2[0x1e] >> 1;
    param_2[0x1f] = DVar1;
    if (uVar3 == 0) goto LAB_c043a420;
    iVar2 = *(int *)(param_2[1] + 8);
  }
  if (iVar2 == 9) {
    CTEStartTimer(param_2 + 0x17,uVar3,FUN_c043a33c,param_2);
  }
LAB_c043a420:
  FUN_c04335c4(*param_2);
  return;
}



/* c043a43c FUN_c043a43c */

/* Boundary evidence: original MIPS .pdata c043a43c..c043a4c3. Semantic name remains unreviewed. */

void FUN_c043a43c(int param_1,undefined4 param_2)

{
  DWORD DVar1;
  uint uVar2;
  
  CTEStopTimer(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x78) = param_2;
  DVar1 = GetTickCount();
  uVar2 = *(uint *)(param_1 + 0x78) >> 1;
  *(DWORD *)(param_1 + 0x7c) = DVar1;
  if ((uVar2 != 0) && (*(int *)(*(int *)(param_1 + 4) + 8) == 9)) {
    CTEStartTimer(param_1 + 0x5c,uVar2,FUN_c043a33c,param_1);
  }
  return;
}



/* c043a4c4 FUN_c043a4c4 */

/* Boundary evidence: original MIPS .pdata c043a4c4..c043a527. Semantic name remains unreviewed. */

undefined4 FUN_c043a4c4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(uint *)(iVar1 + 0xab8) = (uint)*(ushort *)(param_1 + 6);
  FUN_c0439a9c(param_1,param_2,param_3,param_4);
  FUN_c0433050(iVar1,4,0);
  FUN_c043c630(*(int **)(iVar1 + 0xaac));
  FUN_c043a43c((int)param_1,param_1[0x1e]);
  return 0;
}



/* c043a528 FUN_c043a528 */

/* Boundary evidence: original MIPS .pdata c043a528..c043a54b. Semantic name remains unreviewed. */

void FUN_c043a528(int param_1,int param_2)

{
  FUN_c044afb0(*(int **)(param_1 + 4),*(byte **)(param_2 + 8),*(uint *)(param_2 + 4));
  return;
}



/* c043a54c FUN_c043a54c */

/* Boundary evidence: original MIPS .pdata c043a54c..c043a5fb. Semantic name remains unreviewed. */

void FUN_c043a54c(int *param_1,int param_2)

{
  size_t _Size;
  void *_Src;
  uint uVar1;
  int iVar2;
  undefined1 local_5f0;
  char local_5ef;
  undefined1 local_5ee;
  undefined1 local_5ed;
  undefined1 auStack_5ec [1496];
  uint local_14;
  
  local_14 = DAT_c044d82c;
  iVar2 = *param_1;
  _Src = *(void **)(param_2 + 0xc);
  _Size = *(size_t *)(param_2 + 0x10);
  if (*(int *)(param_1[1] + 8) == 9) {
    if (0x5dc < _Size + 4) {
      _Size = 0x5d8;
    }
    local_5ef = (char)param_1[0x14];
    uVar1 = _Size + 4;
    local_5f0 = 8;
    *(char *)(param_1 + 0x14) = local_5ef + '\x01';
    local_5ee = (undefined1)(uVar1 >> 8);
    local_5ed = (undefined1)uVar1;
    memcpy(auStack_5ec,_Src,_Size);
    FUN_c0447448(iVar2,0xc021,&local_5f0,uVar1);
  }
  FUN_c0449d30(local_14);
  return;
}



/* c043a5fc FUN_c043a5fc */

/* Boundary evidence: original MIPS .pdata c043a5fc..c043a657. Semantic name remains unreviewed. */

void FUN_c043a5fc(undefined4 param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4,
                 int *param_5)

{
  int iVar1;
  char *_Dest;
  
  _Dest = (char *)*param_5;
  iVar1 = sprintf(_Dest,"%u",(uint)CONCAT11(*param_3,param_3[1]));
  *param_5 = (int)(_Dest + iVar1);
  return;
}



/* c043a8b4 FUN_c043a8b4 */

undefined4 FUN_c043a8b4(uint param_1,uint param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  *param_3 = -1;
  uVar1 = (uint)DAT_c044d510;
  iVar2 = 0;
  if (uVar1 != 0) {
    iVar3 = 0;
    do {
      if ((uVar1 == param_1) && ((byte)(&DAT_c044d512)[iVar3] == param_2)) {
        *param_3 = iVar2;
        return 1;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar2 * 8;
      uVar1 = (uint)(&DAT_c044d510)[iVar2 * 4];
    } while (uVar1 != 0);
  }
  return 0;
}



/* c043a930 FUN_c043a930 */

/* Boundary evidence: original MIPS .pdata c043a930..c043a9ff. Semantic name remains unreviewed. */

undefined **
FUN_c043a930(undefined1 *param_1,uint param_2,ushort *param_3,undefined1 *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  undefined **ppuVar4;
  int local_20 [2];
  
  local_20[0] = -1;
  ppuVar4 = (undefined **)0x0;
  uVar3 = 0;
  uVar2 = 0;
  iVar1 = -1;
  if (1 < param_2) {
    uVar3 = CONCAT11(*param_1,param_1[1]);
    if (2 < param_2) {
      uVar2 = (uint)(byte)param_1[2];
    }
    FUN_c043a8b4((uint)uVar3,uVar2,local_20);
    iVar1 = local_20[0];
    if (-1 < local_20[0]) {
      ppuVar4 = &PTR_DAT_c044d50c + local_20[0] * 2;
    }
  }
  if (param_3 != (ushort *)0x0) {
    *param_3 = uVar3;
    *param_4 = (char)uVar2;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = iVar1;
  }
  return ppuVar4;
}



/* c043aa00 FUN_c043aa00 */

/* Boundary evidence: original MIPS .pdata c043aa00..c043aa73. Semantic name remains unreviewed. */

void FUN_c043aa00(undefined4 param_1,undefined4 param_2,undefined1 *param_3,uint param_4,
                 int *param_5)

{
  undefined **ppuVar1;
  size_t sVar2;
  char *_Source;
  char *_Dest;
  
  _Dest = (char *)*param_5;
  ppuVar1 = FUN_c043a930(param_3,param_4,(ushort *)0x0,(undefined1 *)0x0,(int *)0x0);
  if (ppuVar1 == (undefined **)0x0) {
    _Source = "???";
  }
  else {
    _Source = *ppuVar1;
  }
  strcpy(_Dest,_Source);
  sVar2 = strlen(_Dest);
  *param_5 = (int)(_Dest + sVar2);
  return;
}



/* c043aae0 FUN_c043aae0 */

undefined4 FUN_c043aae0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(*param_1 + 0xad4);
  uVar2 = 4;
  param_1[0x13] = -1;
  *(undefined2 *)(param_1 + 8) = 0;
  while ((uVar1 = 1 << (uVar2 & 0x1f), (uVar1 & uVar3) == 0 || ((param_1[0x12] & uVar1) != 0))) {
    uVar2 = uVar2 - 1;
    if ((int)uVar2 < 0) {
      return 0;
    }
  }
  param_1[0x13] = uVar2;
  *(undefined2 *)(param_1 + 8) = (&DAT_c044d510)[uVar2 * 4];
  *(undefined1 *)((int)param_1 + 0x22) = (&DAT_c044d512)[uVar2 * 8];
  return 0;
}



/* c043ab5c FUN_c043ab5c */

/* Boundary evidence: original MIPS .pdata c043ab5c..c043abff. Semantic name remains unreviewed. */

undefined4 FUN_c043ab5c(int *param_1,undefined4 param_2,undefined1 *param_3,uint param_4)

{
  undefined1 local_10 [2];
  ushort local_e;
  uint local_c;
  
  FUN_c043a930(param_3,param_4,&local_e,local_10,(int *)&local_c);
  if (((int)local_c < 0) || ((*(uint *)(*param_1 + 0xad4) & 1 << (local_c & 0x1f)) == 0)) {
    if (-1 < param_1[0x13]) {
      param_1[0x12] = 1 << (param_1[0x13] & 0x1fU) | param_1[0x12];
    }
    FUN_c043aae0(param_1);
  }
  else {
    *(ushort *)(param_1 + 8) = local_e;
    *(undefined1 *)((int)param_1 + 0x22) = local_10[0];
    param_1[0x13] = local_c;
  }
  return 0;
}



/* c043ac00 FUN_c043ac00 */

void FUN_c043ac00(int *param_1,undefined1 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  
  uVar1 = 4;
  do {
    if ((1 << (uVar1 & 0x1f) & *(uint *)(*param_1 + 0xad4)) != 0) {
      *(undefined1 *)(param_1 + 0x16) = *(undefined1 *)((int)&DAT_c044d510 + uVar1 * 8 + 1);
      *(char *)((int)param_1 + 0x59) = (char)(&DAT_c044d510)[uVar1 * 4];
      *param_4 = 2;
      if ((&DAT_c044d510)[uVar1 * 4] == -0x3ddd) {
        *(undefined1 *)((int)param_1 + 0x5a) = (&DAT_c044d512)[uVar1 * 8];
        *param_4 = 3;
      }
      *param_3 = param_1 + 0x16;
      *param_2 = 3;
      return;
    }
    uVar1 = uVar1 - 1;
  } while (-1 < (int)uVar1);
  *param_2 = 4;
  return;
}



/* c043ac90 FUN_c043ac90 */

/* Boundary evidence: original MIPS .pdata c043ac90..c043ad5b. Semantic name remains unreviewed. */

undefined4
FUN_c043ac90(int *param_1,undefined4 param_2,undefined1 *param_3,undefined4 *param_4,uint *param_5)

{
  uint uVar1;
  undefined1 local_20 [2];
  ushort local_1e;
  uint local_1c;
  
  uVar1 = *(uint *)(*param_1 + 0xad4);
  if ((((undefined1 *)*param_4 != (undefined1 *)0x0) &&
      (FUN_c043a930((undefined1 *)*param_4,*param_5,&local_1e,local_20,(int *)&local_1c),
      local_1c != 0xffffffff)) && ((1 << (local_1c & 0x1f) & uVar1) != 0)) {
    *(ushort *)(param_1 + 0xe) = local_1e;
    *(undefined1 *)((int)param_1 + 0x3a) = local_20[0];
    *param_3 = 2;
    return 0;
  }
  FUN_c043ac00(param_1,param_3,param_4,param_5);
  return 0;
}



/* c043ae80 FUN_c043ae80 */

/* Boundary evidence: original MIPS .pdata c043ae80..c043aef7. Semantic name remains unreviewed. */

void FUN_c043ae80(int *param_1)

{
  int iVar1;
  
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)((int)param_1 + 0x16);
  param_1[7] = -1;
  param_1[0x13] = -1;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined1 *)((int)param_1 + 0x22) = 0;
  param_1[0x12] = 0;
  if ((*(int *)(*param_1 + 0x6c) != 0) && (iVar1 = FUN_c0439bb8(), iVar1 != 0)) {
    FUN_c043aae0(param_1);
  }
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return;
}



/* c043aef8 FUN_c043aef8 */

/* Boundary evidence: original MIPS .pdata c043aef8..c043b02f. Semantic name remains unreviewed. */

void FUN_c043aef8(int *param_1)

{
  wcscmp((wchar_t *)(*param_1 + 0x76c),L"PPPoE");
  FUN_c044a6b8(param_1[1],&DAT_c044d53c,1,1);
  return;
}



/* c043b030 FUN_c043b030 */

/* Boundary evidence: original MIPS .pdata c043b030..c043b173. Semantic name remains unreviewed. */

void FUN_c043b030(void)

{
  CXUtilGetProcAddresses
            (L"eap.dll",&DAT_c044d908,L"EapSessionCreate",&DAT_c044d8e0,L"EapSessionDestroy",
             &DAT_c044d904,L"EapSessionGetIdentity",&DAT_c044d8e8,L"EapSessionProcessRxPacket",
             &DAT_c044d90c,L"EapSessionRxImpliedSuccessPacket",&DAT_c044d8e4,
             L"EapSessionProcessAuthenticationResult",&DAT_c044d900,L"EapSessionSetConnectionData",
             &DAT_c044d910,L"EapSessionSetUserData",&DAT_c044d8f4,L"EapSessionSetIdentity",
             &DAT_c044d8f0,L"EapSessionSetPassword",&DAT_c044d8f8,L"EapInvokeConfigUI",&DAT_c044d8ec
             ,L"EapUtilExtractMPPEKey",&DAT_c044d8fc,0);
  return;
}



/* c043b174 FUN_c043b174 */

/* Boundary evidence: original MIPS .pdata c043b174..c043b23b. Semantic name remains unreviewed. */

int FUN_c043b174(LPCWSTR param_1,int param_2,STRSAFE_LPCWSTR param_3,LPBYTE param_4,LPDWORD param_5)

{
  int iVar1;
  HKEY local_18;
  DWORD local_14;
  
  iVar1 = FUN_c0442ab4(param_2,param_3,&local_18);
  if (iVar1 == 0) {
    iVar1 = RegQueryValueExW(local_18,param_1,(LPDWORD)0x0,&local_14,param_4,param_5);
    if (iVar1 == 0) {
      if (local_14 != 3) {
        iVar1 = 0x271;
      }
    }
    else if (iVar1 == 0xea) {
      iVar1 = 0x25b;
    }
    RegCloseKey(local_18);
  }
  return iVar1;
}



/* c043b23c FUN_c043b23c */

/* Boundary evidence: original MIPS .pdata c043b23c..c043b263. Semantic name remains unreviewed. */

void FUN_c043b23c(undefined4 param_1,int param_2,STRSAFE_LPCWSTR param_3,LPBYTE param_4,
                 LPDWORD param_5)

{
  FUN_c043b174(L"EapUserData",param_2,param_3,param_4,param_5);
  return;
}



/* c043b264 FUN_c043b264 */

/* Boundary evidence: original MIPS .pdata c043b264..c043b293. Semantic name remains unreviewed. */

void FUN_c043b264(int param_1,STRSAFE_LPCWSTR param_2,LPBYTE param_3,LPDWORD param_4)

{
  FUN_c043b174(L"EapConnData",param_1,param_2,param_3,param_4);
  return;
}



/* c043b294 FUN_c043b294 */

/* Boundary evidence: original MIPS .pdata c043b294..c043b32b. Semantic name remains unreviewed. */

int FUN_c043b294(LPCWSTR param_1,int param_2,STRSAFE_LPCWSTR param_3,BYTE *param_4,DWORD param_5)

{
  int iVar1;
  HKEY local_18 [2];
  
  iVar1 = FUN_c0442ab4(param_2,param_3,local_18);
  if (iVar1 == 0) {
    iVar1 = RegSetValueExW(local_18[0],param_1,0,3,param_4,param_5);
    RegCloseKey(local_18[0]);
  }
  return iVar1;
}



/* c043b32c FUN_c043b32c */

/* Boundary evidence: original MIPS .pdata c043b32c..c043b353. Semantic name remains unreviewed. */

void FUN_c043b32c(undefined4 param_1,int param_2,STRSAFE_LPCWSTR param_3,BYTE *param_4,DWORD param_5
                 )

{
  FUN_c043b294(L"EapUserData",param_2,param_3,param_4,param_5);
  return;
}



/* c043b354 FUN_c043b354 */

/* Boundary evidence: original MIPS .pdata c043b354..c043b383. Semantic name remains unreviewed. */

void FUN_c043b354(int param_1,STRSAFE_LPCWSTR param_2,BYTE *param_3,DWORD param_4)

{
  FUN_c043b294(L"EapConnData",param_1,param_2,param_3,param_4);
  return;
}



/* c043b384 FUN_c043b384 */

/* Boundary evidence: original MIPS .pdata c043b384..c043b59f. Semantic name remains unreviewed. */

void FUN_c043b384(int *param_1,undefined4 param_2,undefined4 param_3,LPSTR param_4,int *param_5)

{
  int iVar1;
  size_t cchWideChar;
  wchar_t *pwVar2;
  int *piVar3;
  wchar_t *_Source;
  uint local_460;
  undefined1 auStack_45c [4];
  wchar_t local_458 [276];
  wchar_t local_230 [258];
  uint local_2c;
  
  local_2c = DAT_c044d82c;
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 != 0) {
    piVar3 = (int *)param_1[0x2ab];
    StringCchCopyW(local_458,0x111,(wchar_t *)((int)param_1 + 0x60a));
    if (local_458[0] != L'\0') {
      StringCchCatW(local_458,0x111,L"\\");
    }
    StringCchCatW(local_458,0x111,(wchar_t *)((int)param_1 + 0x206));
    StringCchCopyW(local_230,0x101,(STRSAFE_LPCWSTR)(param_1 + 0x102));
    local_460 = (uint)(local_230[0] != L'\0');
    iVar1 = (*DAT_c044d8e8)(piVar3[0x240],0,0,local_458,local_230,0,&local_460,auStack_45c);
    if (iVar1 == 0) {
      cchWideChar = wcslen(local_458);
      iVar1 = WideCharToMultiByte(1,0,local_458,cchWideChar,param_4,*param_5,(LPCSTR)0x0,(LPBOOL)0x0
                                 );
      *param_5 = iVar1;
      pwVar2 = wcschr(local_458,L'\\');
      if (pwVar2 == (wchar_t *)0x0) {
        _Source = L"";
        pwVar2 = local_458;
      }
      else {
        _Source = local_458;
        *pwVar2 = L'\0';
        pwVar2 = pwVar2 + 1;
      }
      wcscpy((wchar_t *)((int)param_1 + 0x206),pwVar2);
      wcscpy((wchar_t *)(param_1 + 0x102),local_230);
      wcscpy((wchar_t *)((int)param_1 + 0x60a),_Source);
      RasSetEntryDialParams(0,param_1 + 0x1d,local_460 == 0);
    }
    else {
      FUN_c04335a8((int)param_1);
      FUN_c043c354(piVar3,iVar1);
      FUN_c04335c4((int)param_1);
    }
    FUN_c0433498(param_1);
  }
  FUN_c0449d30(local_2c);
  return;
}



/* c043b5a0 FUN_c043b5a0 */

/* Boundary evidence: original MIPS .pdata c043b5a0..c043b60b. Semantic name remains unreviewed. */

void FUN_c043b5a0(int *param_1,BYTE *param_2,DWORD param_3)

{
  int iVar1;
  
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 != 0) {
    FUN_c043b294(L"EapConnData",0,(STRSAFE_LPCWSTR)(param_1 + 0x1e),param_2,param_3);
    FUN_c0433498(param_1);
  }
  return;
}



/* c043b60c FUN_c043b60c */

/* Boundary evidence: original MIPS .pdata c043b60c..c043b677. Semantic name remains unreviewed. */

void FUN_c043b60c(int *param_1,BYTE *param_2,DWORD param_3)

{
  int iVar1;
  
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 != 0) {
    FUN_c043b294(L"EapUserData",0,(STRSAFE_LPCWSTR)(param_1 + 0x1e),param_2,param_3);
    FUN_c0433498(param_1);
  }
  return;
}



/* c043b678 FUN_c043b678 */

/* Boundary evidence: original MIPS .pdata c043b678..c043b77b. Semantic name remains unreviewed. */

void FUN_c043b678(int *param_1,void *param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 != 0) {
    FUN_c04335a8((int)param_1);
    if (param_2 != (void *)0x0) {
      FUN_c0447448((int)param_1,0xc227,param_2,param_3);
    }
    if (param_4 != 0) {
      if (param_5 == 0) {
        uVar2 = *(undefined4 *)(*(int *)(param_1[0x2ab] + 0x900) + 0x74);
        (*DAT_c044d8fc)(param_1 + 0x2b8,param_1 + 0x2c0,uVar2,0x137,0x10);
        (*DAT_c044d8fc)(param_1 + 0x2c1,param_1 + 0x2c9,uVar2,0x137,0x11);
        FUN_c043c310((int *)param_1[0x2ab]);
      }
      else {
        FUN_c043c354((int *)param_1[0x2ab],param_5);
      }
    }
    FUN_c04335c4((int)param_1);
    FUN_c0433498(param_1);
  }
  return;
}



/* c043b77c FUN_c043b77c */

void FUN_c043b77c(void)

{
  return;
}



/* c043b784 FUN_c043b784 */

/* Boundary evidence: original MIPS .pdata c043b784..c043b7cf. Semantic name remains unreviewed. */

void FUN_c043b784(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 != 0) {
    (*DAT_c044d900)(param_1[0x2ab],0x2b3);
    FUN_c0433498(param_1);
  }
  return;
}



/* c043b7d0 FUN_c043b7d0 */

/* Boundary evidence: original MIPS .pdata c043b7d0..c043b7ff. Semantic name remains unreviewed. */

void FUN_c043b7d0(int param_1)

{
  if (*(int *)(param_1 + 0x900) != 0) {
    (*DAT_c044d90c)();
  }
  return;
}



/* c043b800 FUN_c043b800 */

/* Boundary evidence: original MIPS .pdata c043b800..c043b83f. Semantic name remains unreviewed. */

void FUN_c043b800(int param_1)

{
  if (*(int *)(param_1 + 0x900) != 0) {
    (*DAT_c044d904)();
    *(undefined4 *)(param_1 + 0x900) = 0;
  }
  return;
}



/* c043b840 FUN_c043b840 */

/* Boundary evidence: original MIPS .pdata c043b840..c043ba83. Semantic name remains unreviewed. */

int FUN_c043b840(int *param_1)

{
  int iVar1;
  LPBYTE pBVar2;
  int iVar3;
  STRSAFE_LPCWSTR pwVar4;
  DWORD local_248 [2];
  wchar_t local_240 [274];
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  iVar3 = *param_1;
  if (param_1[0x240] != 0) {
    (*DAT_c044d904)();
    param_1[0x240] = 0;
  }
  iVar1 = (*DAT_c044d8e0)(iVar3,0,*(undefined4 *)(iVar3 + 0x6c),*(undefined1 *)(iVar3 + 0xa98),0x5dc
                          ,0,&DAT_c044d5fc);
  param_1[0x240] = iVar1;
  if (iVar1 == 0) {
    FUN_c043c354(param_1,0x285);
    iVar3 = param_1[1];
  }
  else {
    FUN_c043be98(iVar3,local_240);
    if (((local_240[0] != L'\0') && (iVar1 = (*DAT_c044d8f0)(param_1[0x240],local_240), iVar1 == 0))
       && (*(short *)(iVar3 + 0x408) != 0)) {
      (*DAT_c044d8f8)(param_1[0x240]);
    }
    pwVar4 = (STRSAFE_LPCWSTR)(iVar3 + 0x78);
    local_248[0] = 0;
    pBVar2 = (LPBYTE)0x0;
    FUN_c043b174(L"EapConnData",0,pwVar4,(LPBYTE)0x0,local_248);
    if ((local_248[0] != 0) && (pBVar2 = LocalAlloc(0x40,local_248[0]), pBVar2 != (LPBYTE)0x0)) {
      iVar3 = FUN_c043b174(L"EapConnData",0,pwVar4,pBVar2,local_248);
      if (iVar3 == 0) {
        (*DAT_c044d910)(param_1[0x240],pBVar2,local_248[0]);
      }
    }
    LocalFree(pBVar2);
    local_248[0] = 0;
    pBVar2 = (LPBYTE)0x0;
    FUN_c043b174(L"EapUserData",0,pwVar4,(LPBYTE)0x0,local_248);
    if ((local_248[0] != 0) && (pBVar2 = LocalAlloc(0x40,local_248[0]), pBVar2 != (LPBYTE)0x0)) {
      iVar3 = FUN_c043b174(L"EapUserData",0,pwVar4,pBVar2,local_248);
      if (iVar3 == 0) {
        (*DAT_c044d8f4)(param_1[0x240],pBVar2,local_248[0]);
      }
    }
    LocalFree(pBVar2);
    iVar3 = 7;
  }
  FUN_c0449d30(local_1c);
  return iVar3;
}



/* c043ba84 FUN_c043ba84 */

/* Boundary evidence: original MIPS .pdata c043ba84..c043ba9f. Semantic name remains unreviewed. */

void FUN_c043ba84(int *param_1)

{
  FUN_c043c1bc(param_1);
  return;
}



/* c043baa0 FUN_c043baa0 */

/* Boundary evidence: original MIPS .pdata c043baa0..c043bb07. Semantic name remains unreviewed. */

undefined4 FUN_c043baa0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x32;
  if (((*(int *)(*param_1 + 0x6c) != 0) && (*(short *)((int)param_1 + 0x2e) == -0x3ddd)) &&
     (param_1[1] == 9)) {
    iVar2 = FUN_c043e264(param_1);
    FUN_c043c0b0(param_1,iVar2);
    uVar1 = 0;
  }
  return uVar1;
}



/* c043bb08 FUN_c043bb08 */

/* Boundary evidence: original MIPS .pdata c043bb08..c043bc63. Semantic name remains unreviewed. */

int FUN_c043bb08(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int local_5e0 [2];
  undefined4 local_5d8;
  wchar_t awStack_5d4 [730];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  piVar1 = (int *)FUN_c04343d0(param_1,0x904);
  if (piVar1 == (int *)0x0) {
    iVar4 = 8;
  }
  else {
    iVar4 = FUN_c04335e0(param_1,0xc223,&PTR_FUN_c044d620,piVar1);
    if (((iVar4 == 0) && (iVar4 = FUN_c04335e0(param_1,0xc023,&PTR_FUN_c044d620,piVar1), iVar4 == 0)
        ) && (iVar4 = FUN_c04335e0(param_1,0xc227,&PTR_FUN_c044d620,piVar1), iVar4 == 0)) {
      *piVar1 = param_1;
      CTEInitTimer(piVar1 + 3);
      FUN_c043c5d8(piVar1);
      iVar5 = 0x5b8;
      local_5d8 = 0x5b8;
      StringCchCopyW(awStack_5d4,0x15,(STRSAFE_LPCWSTR)(param_1 + 0x78));
      iVar2 = RasGetEntryDialParams(0,&local_5d8,local_5e0);
      if (iVar2 == 0) {
        piVar1[0x17b] = local_5e0[0];
      }
      puVar3 = &local_5d8;
      do {
        *(undefined1 *)puVar3 = 0;
        iVar5 = iVar5 + -1;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      } while (iVar5 != 0);
      goto LAB_c043bb64;
    }
  }
  FUN_c0434420(param_1,piVar1);
  piVar1 = (int *)0x0;
LAB_c043bb64:
  *param_2 = piVar1;
  FUN_c0449d30(local_20);
  return iVar4;
}



/* c043bc64 FUN_c043bc64 */

/* Boundary evidence: original MIPS .pdata c043bc64..c043bc97. Semantic name remains unreviewed. */

void FUN_c043bc64(int *param_1)

{
  FUN_c043b800((int)param_1);
  FUN_c0434420(*param_1,param_1);
  return;
}



/* c043bc98 FUN_c043bc98 */

/* Boundary evidence: original MIPS .pdata c043bc98..c043bd4f. Semantic name remains unreviewed. */

void FUN_c043bc98(int *param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_2 + 8);
  if ((((param_1[1] != 0) && (param_1[1] != 2)) && (3 < *(uint *)(param_2 + 4))) &&
     ((uVar2 = (uint)CONCAT11(pbVar3[2],pbVar3[3]), 3 < uVar2 && (uVar2 <= *(uint *)(param_2 + 4))))
     ) {
    sVar1 = *(short *)((int)param_1 + 0x2e);
    if (sVar1 == -0x3fdd) {
      FUN_c043e3b0(param_1,pbVar3,uVar2);
    }
    else if (sVar1 == -0x3ddd) {
      FUN_c043e0b4(param_1,pbVar3,uVar2);
    }
    else if (sVar1 == -0x3dd9) {
      FUN_c043b7d0((int)param_1);
    }
  }
  return;
}



/* c043bd50 FUN_c043bd50 */

/* Boundary evidence: original MIPS .pdata c043bd50..c043bd83. Semantic name remains unreviewed. */

void FUN_c043bd50(int *param_1,void *param_2,uint param_3)

{
  if (*(ushort *)((int)param_1 + 0x2e) != 0) {
    FUN_c0447448(*param_1,(uint)*(ushort *)((int)param_1 + 0x2e),param_2,param_3);
  }
  return;
}



/* c043bd84 FUN_c043bd84 */

/* Boundary evidence: original MIPS .pdata c043bd84..c043bdb3. Semantic name remains unreviewed. */

void FUN_c043bd84(int *param_1)

{
  FUN_c043e7c8(param_1);
  *(undefined2 *)((int)param_1 + 0x2e) = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  return;
}



/* c043bdb4 FUN_c043bdb4 */

int FUN_c043bdb4(int param_1)

{
  return param_1 + 0x4b4;
}



/* c043bdbc FUN_c043bdbc */

/* Boundary evidence: original MIPS .pdata c043bdbc..c043be97. Semantic name remains unreviewed. */

void FUN_c043bdbc(int *param_1)

{
  char cVar1;
  short sVar2;
  
  if (*(int *)(*param_1 + 0x6c) != 0) {
    return;
  }
  if (param_1[1] == 9) {
    return;
  }
  if (param_1[1] < 3) {
    return;
  }
  sVar2 = *(short *)((int)param_1 + 0x2e);
  if (sVar2 != -0x3fdd) {
    if (sVar2 != -0x3ddd) {
      if (sVar2 != -0x3dd9) {
        return;
      }
      if (param_1[0x240] == 0) {
        return;
      }
      if (DAT_c044d8e4 == (code *)0x0) {
        return;
      }
      (*DAT_c044d8e4)();
      return;
    }
    cVar1 = (char)param_1[0xc];
    if ((cVar1 != '\x05') && (cVar1 != -0x80)) {
      if (cVar1 != -0x7f) {
        return;
      }
      FUN_c043cd4c(param_1);
      return;
    }
  }
  FUN_c043c310(param_1);
  return;
}



/* c043be98 FUN_c043be98 */

/* Boundary evidence: original MIPS .pdata c043be98..c043beef. Semantic name remains unreviewed. */

void FUN_c043be98(int param_1,STRSAFE_LPWSTR param_2)

{
  undefined *puVar1;
  
  if (*(short *)(param_1 + 0x60a) == 0) {
    puVar1 = &DAT_c0431cb0;
  }
  else {
    puVar1 = &DAT_c0431cb4;
  }
  StringCchPrintfW(param_2,0x111,L"%s%s%s",(short *)(param_1 + 0x60a),puVar1,param_1 + 0x206);
  return;
}



/* c043bef0 FUN_c043bef0 */

/* Boundary evidence: original MIPS .pdata c043bef0..c043bf8f. Semantic name remains unreviewed. */

undefined4 FUN_c043bef0(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18 [2];
  DWORD local_10;
  undefined4 local_c;
  
  local_18[0] = 0;
  local_10 = 0;
  local_c = param_1;
  iVar1 = FUN_c0432630(0x51,60000);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_c04326ec(L"netui.dll",L"CloseUsernamePasswordDialogExt",&local_10,8,&local_10,8,
                           local_18), iVar1 != 0)) {
    if (local_10 == 0) {
      return 1;
    }
    SetLastError(local_10);
  }
  return 0;
}



/* c043bf90 FUN_c043bf90 */

/* Boundary evidence: original MIPS .pdata c043bf90..c043bfe7. Semantic name remains unreviewed. */

void FUN_c043bf90(int *param_1)

{
  FUN_c043e7c8(param_1);
  if (param_1[2] == 0) {
    param_1[2] = 1;
    FUN_c0433050(*param_1,0xe,0);
    FUN_c044c008(*(int *)(*param_1 + 0xab0));
  }
  return;
}



/* c043bfe8 FUN_c043bfe8 */

/* Boundary evidence: original MIPS .pdata c043bfe8..c043c02b. Semantic name remains unreviewed. */

void FUN_c043bfe8(int *param_1)

{
  if (param_1[2] != 0) {
    param_1[2] = 0;
    FUN_c044c06c(*(int *)(*param_1 + 0xab0));
  }
  FUN_c043bd84(param_1);
  return;
}



/* c043c02c FUN_c043c02c */

/* Boundary evidence: original MIPS .pdata c043c02c..c043c07f. Semantic name remains unreviewed. */

void FUN_c043c02c(int *param_1)

{
  if (*(int *)(*param_1 + 0xcec) != 0) {
    FUN_c043bef0(*(int *)(*param_1 + 0xcec));
    *(undefined4 *)(*param_1 + 0xcec) = 0;
  }
  FUN_c0439d7c(*(int **)(*param_1 + 0xaa8),(undefined *)0x0,0);
  return;
}



/* c043c080 FUN_c043c080 */

/* Boundary evidence: original MIPS .pdata c043c080..c043c0af. Semantic name remains unreviewed. */

void FUN_c043c080(undefined4 *param_1)

{
  if (param_1[10] != 0) {
    param_1[10] = 0;
    FUN_c0433554((int *)*param_1,param_1 + 3);
  }
  return;
}



/* c043c0b0 FUN_c043c0b0 */

/* Boundary evidence: original MIPS .pdata c043c0b0..c043c1bb. Semantic name remains unreviewed. */

void FUN_c043c0b0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[1];
  if (iVar1 != param_2) {
    param_1[1] = param_2;
    if (((param_2 < 4) || (param_2 == 9)) && (param_1[10] != 0)) {
      param_1[10] = 0;
      FUN_c0433554((int *)*param_1,param_1 + 3);
    }
    if (param_2 < 3) {
      FUN_c043bfe8(param_1);
    }
    if (param_2 == 1) {
      if (iVar1 == 0) {
        FUN_c0439d60(*(int *)(*param_1 + 0xaa8));
      }
    }
    else if (param_2 == 9) {
      FUN_c043bf90(param_1);
    }
    else if (((((param_2 == 0) || (param_2 == 2)) || (param_2 == 3)) &&
             ((iVar1 != 0 && (iVar1 != 2)))) && (iVar1 != 3)) {
      FUN_c043c02c(param_1);
    }
  }
  return;
}



/* c043c1bc FUN_c043c1bc */

/* Boundary evidence: original MIPS .pdata c043c1bc..c043c25b. Semantic name remains unreviewed. */

undefined4 FUN_c043c1bc(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  if (((iVar1 == 1) || ((5 < iVar1 && (iVar1 < 10)))) && (iVar1 != 2)) {
    param_1[1] = 2;
    if (param_1[10] != 0) {
      param_1[10] = 0;
      FUN_c0433554((int *)*param_1,param_1 + 3);
    }
    FUN_c043bfe8(param_1);
    if ((iVar1 != 0) && (iVar1 != 3)) {
      FUN_c043c02c(param_1);
    }
  }
  return 0;
}



/* c043c25c FUN_c043c25c */

/* WARNING: Removing unreachable block (ram,0xc043c2e4) */
/* WARNING: Removing unreachable block (ram,0xc043c2f0) */
/* Boundary evidence: original MIPS .pdata c043c25c..c043c30f. Semantic name remains unreviewed. */

void FUN_c043c25c(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  if (iVar1 == 2) {
    param_1[1] = 0;
    if (param_1[10] != 0) {
      param_1[10] = 0;
      FUN_c0433554((int *)*param_1,param_1 + 3);
    }
    FUN_c043bfe8(param_1);
  }
  else if ((5 < iVar1) && (iVar1 < 10)) {
    FUN_c043c0b0(param_1,1);
  }
  return;
}



/* c043c310 FUN_c043c310 */

/* Boundary evidence: original MIPS .pdata c043c310..c043c353. Semantic name remains unreviewed. */

void FUN_c043c310(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  param_1[0x23c] = 0;
  if ((iVar1 == 1) || ((5 < iVar1 && (iVar1 < 10)))) {
    FUN_c043c0b0(param_1,9);
  }
  return;
}



/* c043c354 FUN_c043c354 */

/* Boundary evidence: original MIPS .pdata c043c354..c043c39f. Semantic name remains unreviewed. */

void FUN_c043c354(int *param_1,int param_2)

{
  param_1[0x23c] = param_2;
  if (param_2 != 0) {
    *(undefined4 *)(*param_1 + 0xcd8) = 1;
    FUN_c0433050(*param_1,6,param_2);
  }
  FUN_c043c1bc(param_1);
  return;
}



/* c043c3a0 FUN_c043c3a0 */

/* Boundary evidence: original MIPS .pdata c043c3a0..c043c3d3. Semantic name remains unreviewed. */

void FUN_c043c3a0(int *param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_c043c310(param_1);
  }
  else {
    FUN_c043c354(param_1,param_2);
  }
  return;
}



/* c043c3d4 FUN_c043c3d4 */

/* Boundary evidence: original MIPS .pdata c043c3d4..c043c4b7. Semantic name remains unreviewed. */

void FUN_c043c3d4(undefined4 param_1,int *param_2)

{
  int iVar1;
  byte bVar2;
  
  FUN_c04335a8(*param_2);
  iVar1 = *param_2;
  if ((*(int *)(iVar1 + 0x54) == 0) && (param_2[10] != 0)) {
    bVar2 = (char)param_2[0xb] + 1;
    *(byte *)(param_2 + 0xb) = bVar2;
    if ((uint)bVar2 < *(uint *)(iVar1 + 0xad8)) {
      if (*(short *)((int)param_2 + 0x2e) == -0x3fdd) {
        FUN_c043e5f8(param_2);
      }
      else if (*(short *)((int)param_2 + 0x2e) == -0x3ddd) {
        FUN_c043e204(param_2);
      }
      FUN_c043c4b8(param_2);
    }
    else {
      param_2[0x23c] = 0x294;
      *(undefined4 *)(iVar1 + 0xcd8) = 1;
      FUN_c0433050(*param_2,6,0x294);
      FUN_c043c1bc(param_2);
    }
  }
  FUN_c04335c4(*param_2);
  FUN_c0433498((int *)*param_2);
  return;
}



/* c043c4b8 FUN_c043c4b8 */

/* Boundary evidence: original MIPS .pdata c043c4b8..c043c4f3. Semantic name remains unreviewed. */

void FUN_c043c4b8(undefined4 *param_1)

{
  param_1[10] = 1;
  FUN_c0433a84((int *)*param_1,param_1 + 3,((int *)*param_1)[0x2b1],FUN_c043c3d4,param_1);
  return;
}



/* c043c4f4 FUN_c043c4f4 */

/* Boundary evidence: original MIPS .pdata c043c4f4..c043c5d7. Semantic name remains unreviewed. */

int FUN_c043c4f4(int *param_1)

{
  short sVar1;
  int iVar2;
  undefined2 local_10;
  undefined1 local_e;
  uint local_c;
  
  *(undefined4 *)(*param_1 + 0xcd8) = 0;
  local_c = 4;
  FUN_c043a220(*(int *)(*param_1 + 0xaa8),*(int *)(*param_1 + 0x6c),3,&local_10,&local_c);
  *(undefined2 *)((int)param_1 + 0x2e) = local_10;
  *(undefined1 *)(param_1 + 0xc) = local_e;
  FUN_c0433050(*param_1,5,0);
  sVar1 = *(short *)((int)param_1 + 0x2e);
  if (sVar1 == 0) {
    FUN_c043c310(param_1);
    iVar2 = param_1[1];
  }
  else {
    *(undefined1 *)(param_1 + 0xb) = 0;
    if (sVar1 == -0x3fdd) {
      iVar2 = FUN_c043e764(param_1);
    }
    else if (sVar1 == -0x3ddd) {
      iVar2 = FUN_c043e264(param_1);
    }
    else if (sVar1 == -0x3dd9) {
      iVar2 = FUN_c043b840(param_1);
    }
    else {
      iVar2 = 2;
    }
  }
  return iVar2;
}



/* c043c5d8 FUN_c043c5d8 */

/* Boundary evidence: original MIPS .pdata c043c5d8..c043c62f. Semantic name remains unreviewed. */

undefined4 FUN_c043c5d8(int *param_1)

{
  int iVar1;
  
  if (param_1[1] == 0) {
    iVar1 = 1;
  }
  else {
    if (param_1[1] != 2) {
      return 0;
    }
    iVar1 = FUN_c043c4f4(param_1);
  }
  FUN_c043c0b0(param_1,iVar1);
  return 0;
}



/* c043c630 FUN_c043c630 */

/* WARNING: Removing unreachable block (ram,0xc043c6bc) */
/* WARNING: Removing unreachable block (ram,0xc043c6c8) */
/* Boundary evidence: original MIPS .pdata c043c630..c043c6e3. Semantic name remains unreviewed. */

void FUN_c043c630(int *param_1)

{
  int iVar1;
  
  FUN_c043c5d8(param_1);
  if (param_1[1] == 0) {
    param_1[1] = 2;
    if (param_1[10] != 0) {
      param_1[10] = 0;
      FUN_c0433554((int *)*param_1,param_1 + 3);
    }
    FUN_c043bfe8(param_1);
  }
  else if (param_1[1] == 1) {
    iVar1 = FUN_c043c4f4(param_1);
    FUN_c043c0b0(param_1,iVar1);
  }
  return;
}



/* c043c6e4 FUN_c043c6e4 */

/* Boundary evidence: original MIPS .pdata c043c6e4..c043c847. Semantic name remains unreviewed. */

undefined4 FUN_c043c6e4(undefined4 param_1,void *param_2,uint *param_3)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 local_5d8 [2];
  DWORD local_5d0;
  undefined4 local_5cc;
  undefined1 auStack_5c8 [1456];
  uint local_18;
  uint local_14;
  
  local_14 = DAT_c044d82c;
  local_5d8[0] = 0;
  local_5d0 = 0;
  local_18 = (uint)(param_3 != (uint *)0x0);
  local_5cc = param_1;
  memcpy(auStack_5c8,param_2,0x5b0);
  iVar1 = FUN_c0432630(0x51,60000);
  if (iVar1 == 0) {
    iVar1 = FUN_c04326ec(L"netui.dll",L"GetUsernamePasswordExExt",&local_5d0,0x5bc,&local_5d0,0x5bc,
                         local_5d8);
    if (iVar1 == 0) {
      dwErrCode = GetLastError();
      if (dwErrCode == 0) {
        dwErrCode = 0x57;
      }
    }
    else {
      dwErrCode = local_5d0;
      if (local_5d0 == 0) {
        memcpy(param_2,auStack_5c8,0x5b0);
        if (param_3 != (uint *)0x0) {
          *param_3 = local_18;
        }
        SetLastError(0);
        FUN_c0449d30(local_14);
        return 1;
      }
    }
  }
  else {
    dwErrCode = GetLastError();
    if (dwErrCode == 0) {
      dwErrCode = 0x1f;
    }
  }
  SetLastError(dwErrCode);
  FUN_c0449d30(local_14);
  return 0;
}



/* c043c848 FUN_c043c848 */

/* Boundary evidence: original MIPS .pdata c043c848..c043c963. Semantic name remains unreviewed. */

undefined4 FUN_c043c848(undefined4 param_1,void *param_2,uint *param_3)

{
  int iVar1;
  undefined4 local_230 [2];
  DWORD local_228;
  undefined4 local_224;
  undefined1 auStack_220 [516];
  uint local_1c;
  uint local_18;
  
  local_18 = DAT_c044d82c;
  local_230[0] = 0;
  local_228 = 0;
  local_1c = (uint)(param_3 != (uint *)0x0);
  local_224 = param_1;
  memcpy(auStack_220,param_2,0x202);
  iVar1 = FUN_c0432630(0x51,60000);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_c04326ec(L"netui.dll",L"GetNewPasswordExExt",&local_228,0x210,&local_228,0x210,
                           local_230), iVar1 != 0)) {
    if (local_228 == 0) {
      memcpy(param_2,auStack_220,0x202);
      if (param_3 != (uint *)0x0) {
        *param_3 = local_1c;
      }
      FUN_c0449d30(local_18);
      return 1;
    }
    SetLastError(local_228);
  }
  FUN_c0449d30(local_18);
  return 0;
}



/* c043c964 FUN_c043c964 */

undefined4 FUN_c043c964(char *param_1,uint param_2,int param_3,char *param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  do {
    uVar1 = param_2;
    pcVar3 = param_1;
    if (uVar1 < 2) {
      return 0;
    }
    param_1 = pcVar3 + 1;
    param_2 = uVar1 - 1;
  } while ((*pcVar3 != param_3) || (*param_1 != '='));
  pcVar3 = pcVar3 + 2;
  iVar2 = uVar1 - 2;
  while (iVar2 != 0) {
    param_5 = param_5 + -1;
    iVar2 = iVar2 + -1;
    if ((*pcVar3 == ' ') || (param_5 == 0)) break;
    *param_4 = *pcVar3;
    param_4 = param_4 + 1;
    pcVar3 = pcVar3 + 1;
  }
  *param_4 = '\0';
  return 1;
}



/* c043c9f8 FUN_c043c9f8 */

/* Boundary evidence: original MIPS .pdata c043c9f8..c043ca6f. Semantic name remains unreviewed. */

void FUN_c043c9f8(int *param_1,LPSTR param_2,int param_3)

{
  size_t cchWideChar;
  int iVar1;
  
  iVar1 = *param_1;
  cchWideChar = wcslen((wchar_t *)(iVar1 + 0x206));
  iVar1 = WideCharToMultiByte(1,0,(wchar_t *)(iVar1 + 0x206),cchWideChar,param_2,param_3,(LPCSTR)0x0
                              ,(LPBOOL)0x0);
  param_2[iVar1] = '\0';
  return;
}



/* c043ca70 FUN_c043ca70 */

/* Boundary evidence: original MIPS .pdata c043ca70..c043caf7. Semantic name remains unreviewed. */

int FUN_c043ca70(int *param_1,LPSTR param_2,int param_3)

{
  size_t cchWideChar;
  int iVar1;
  wchar_t awStack_238 [274];
  uint local_14;
  
  local_14 = DAT_c044d82c;
  FUN_c043be98(*param_1,awStack_238);
  cchWideChar = wcslen(awStack_238);
  iVar1 = WideCharToMultiByte(1,0,awStack_238,cchWideChar,param_2,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
  FUN_c0449d30(local_14);
  return iVar1;
}



/* c043caf8 FUN_c043caf8 */

/* Boundary evidence: original MIPS .pdata c043caf8..c043cb63. Semantic name remains unreviewed. */

void FUN_c043caf8(int param_1,LPSTR param_2,int param_3)

{
  size_t cchWideChar;
  
  cchWideChar = wcslen((wchar_t *)(param_1 + 0x408));
  WideCharToMultiByte(1,0,(wchar_t *)(param_1 + 0x408),cchWideChar,param_2,param_3,(LPCSTR)0x0,
                      (LPBOOL)0x0);
  return;
}



/* c043cb64 FUN_c043cb64 */

/* Boundary evidence: original MIPS .pdata c043cb64..c043ccdf. Semantic name remains unreviewed. */

void FUN_c043cb64(int param_1,undefined1 *param_2,uint *param_3)

{
  int iVar1;
  size_t _Size;
  uint uVar2;
  char *_Str;
  CHAR aCStack_338 [264];
  WCHAR aWStack_230 [262];
  uint local_24;
  
  local_24 = DAT_c044d82c;
  _Str = "WindowsCE";
  iVar1 = FUN_c0432908((HKEY)0x80000002,L"Ident",L"Name",1);
  if (iVar1 == 1) {
    WideCharToMultiByte(1,0,aWStack_230,-1,aCStack_338,0x105,(LPCSTR)0x0,(LPBOOL)0x0);
    _Str = aCStack_338;
  }
  _Size = strlen(_Str);
  if (0x40 < _Size) {
    _Size = 0x40;
  }
  *(ushort *)(param_1 + 0x4a8) = *(short *)(param_1 + 0x4a8) + 1U & 0xff;
  uVar2 = *(byte *)(param_1 + 0x5b4) + _Size + 5 & 0xffff;
  *param_2 = 1;
  param_2[1] = (char)*(undefined2 *)(param_1 + 0x4a8);
  param_2[2] = (char)(uVar2 >> 8);
  param_2[3] = (char)uVar2;
  param_2[4] = *(undefined1 *)(param_1 + 0x5b4);
  memcpy(param_2 + 5,(void *)(param_1 + 0x4b4),(uint)*(byte *)(param_1 + 0x5b4));
  memcpy(param_2 + *(byte *)(param_1 + 0x5b4) + 5,_Str,_Size);
  *param_3 = uVar2;
  FUN_c0449d30(local_24);
  return;
}



/* c043cce0 FUN_c043cce0 */

/* Boundary evidence: original MIPS .pdata c043cce0..c043cd4b. Semantic name remains unreviewed. */

void FUN_c043cce0(int *param_1)

{
  uint local_160 [2];
  undefined1 auStack_158 [328];
  uint local_10;
  
  local_10 = DAT_c044d82c;
  FUN_c04496e4((uint)*(byte *)(param_1 + 0x16d),(BYTE *)(param_1 + 0x12d));
  local_160[0] = 0x145;
  FUN_c043cb64((int)param_1,auStack_158,local_160);
  FUN_c043bd50(param_1,auStack_158,local_160[0]);
  FUN_c0449d30(local_10);
  return;
}



/* c043cd4c FUN_c043cd4c */

/* Boundary evidence: original MIPS .pdata c043cd4c..c043cd73. Semantic name remains unreviewed. */

void FUN_c043cd4c(int *param_1)

{
  if (param_1[0x129] != 0) {
    FUN_c043bd50(param_1,(void *)((int)param_1 + 0x25a),param_1[0x129]);
  }
  return;
}



/* c043cd74 FUN_c043cd74 */

/* Boundary evidence: original MIPS .pdata c043cd74..c043ce63. Semantic name remains unreviewed. */

void FUN_c043cd74(int *param_1)

{
  int iVar1;
  uint _Size;
  undefined1 *puVar2;
  uint uVar3;
  byte local_28 [4];
  void *local_24;
  
  (**(code **)(param_1[0xd] + 8))(param_1,&local_24,local_28);
  puVar2 = (undefined1 *)((int)param_1 + 0x25a);
  _Size = (uint)local_28[0];
  iVar1 = FUN_c043ca70(param_1,puVar2 + _Size + 5,0x110);
  uVar3 = iVar1 + _Size + 5;
  *puVar2 = 2;
  *(char *)((int)param_1 + 0x25b) = (char)(short)param_1[0x12a];
  *(char *)(param_1 + 0x97) = (char)(uVar3 >> 8);
  *(char *)((int)param_1 + 0x25d) = (char)uVar3;
  *(byte *)((int)param_1 + 0x25e) = local_28[0];
  memcpy((void *)((int)param_1 + 0x25f),local_24,_Size);
  param_1[0x129] = uVar3;
  if (uVar3 != 0) {
    FUN_c043bd50(param_1,puVar2,uVar3);
  }
  if (param_1[2] == 0) {
    FUN_c0433050(*param_1,0xc,0);
  }
  return;
}



/* c043ce64 FUN_c043ce64 */

/* Boundary evidence: original MIPS .pdata c043ce64..c043cf97. Semantic name remains unreviewed. */

void FUN_c043ce64(int *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined1 *_Dst;
  CHAR aCStack_128 [260];
  uint local_24;
  
  local_24 = DAT_c044d82c;
  iVar1 = *param_1;
  _Dst = (undefined1 *)((int)param_1 + 0x25a);
  memset(_Dst,0,0x24a);
  *_Dst = 7;
  pwVar2 = (wchar_t *)(param_1 + 0x17c);
  *(char *)((int)param_1 + 0x25b) = (char)(short)param_1[0x12a];
  *(undefined1 *)(param_1 + 0x97) = 2;
  *(undefined1 *)((int)param_1 + 0x25d) = 0x4a;
  FUN_c043ec2c(pwVar2,(wchar_t *)(iVar1 + 0x408),(void *)((int)param_1 + 0x25e));
  FUN_c043ecf8(pwVar2,(wchar_t *)(iVar1 + 0x408));
  FUN_c04496e4(0x10,(BYTE *)((int)param_1 + 0x5b5));
  memcpy((void *)((int)param_1 + 0x472),(BYTE *)((int)param_1 + 0x5b5),0x10);
  FUN_c043c9f8(param_1,aCStack_128,0x101);
  FUN_c043eafc(param_1 + 0x12d,(void *)((int)param_1 + 0x472),aCStack_128,pwVar2);
  memcpy((void *)((int)param_1 + 0x48a),(void *)((int)param_1 + 0x5cd),0x18);
  param_1[0x129] = 0x24a;
  FUN_c043bd50(param_1,_Dst,0x24a);
  FUN_c0449d30(local_24);
  return;
}



/* c043cf98 FUN_c043cf98 */

/* Boundary evidence: original MIPS .pdata c043cf98..c043d1bf. Semantic name remains unreviewed. */

int FUN_c043cf98(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  wchar_t awStack_7d8 [257];
  wchar_t awStack_5d6 [257];
  wchar_t awStack_3d4 [16];
  uint local_3b4;
  wchar_t awStack_228 [258];
  uint local_24;
  
  local_24 = DAT_c044d82c;
  piVar3 = (int *)*param_1;
  iVar4 = 0;
  iVar1 = FUN_c043336c(piVar3);
  if (iVar1 != 0) {
    iVar1 = 0;
    if (piVar3[0x2a7] == -1) {
      iVar1 = piVar3[0x2a8];
    }
    iVar5 = param_1[0x17a];
    if (iVar5 == 0) {
      memset(awStack_7d8,0,0x5b0);
      StringCchCopyW(awStack_7d8,0x101,(STRSAFE_LPCWSTR)((int)piVar3 + 0x206));
      StringCchCopyW(awStack_5d6,0x101,(STRSAFE_LPCWSTR)(piVar3 + 0x102));
      StringCchCopyW(awStack_3d4,0x10,(STRSAFE_LPCWSTR)((int)piVar3 + 0x60a));
      if (param_1[0x17b] != 0) {
        local_3b4 = local_3b4 | 1;
      }
      local_3b4 = local_3b4 | 2;
      iVar1 = FUN_c043c6e4(iVar1,awStack_7d8,(uint *)(piVar3 + 0x33b));
    }
    else {
      memset(awStack_228,0,0x202);
      iVar1 = FUN_c043c848(iVar1,awStack_228,(uint *)(piVar3 + 0x33b));
    }
    piVar3[0x33b] = 0;
    FUN_c04335a8((int)piVar3);
    if (iVar1 == 0) {
      iVar4 = 0x277;
    }
    else if (iVar5 == 0) {
      StringCchCopyW((STRSAFE_LPWSTR)((int)piVar3 + 0x206),0x101,awStack_7d8);
      StringCchCopyW((STRSAFE_LPWSTR)(piVar3 + 0x102),0x101,awStack_5d6);
      StringCchCopyW((STRSAFE_LPWSTR)((int)piVar3 + 0x60a),0x10,awStack_3d4);
      uVar2 = (uint)((local_3b4 & 1) != 0);
      param_1[0x17b] = uVar2;
      RasSetEntryDialParams(0,piVar3 + 0x1d,uVar2 == 0);
    }
    else {
      StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x17c),0x101,awStack_228);
    }
    param_1[299] = 0;
    if (iVar4 == 0) {
      if (iVar5 == 0) {
        FUN_c043cd74(param_1);
      }
      else {
        FUN_c043ce64(param_1);
      }
      FUN_c043c4b8(param_1);
    }
    else {
      FUN_c043c354(param_1,iVar4);
    }
    FUN_c04335c4((int)piVar3);
    FUN_c0433498(piVar3);
  }
  FUN_c0449d30(local_24);
  return iVar4;
}



/* c043d1c0 FUN_c043d1c0 */

/* Boundary evidence: original MIPS .pdata c043d1c0..c043d22f. Semantic name remains unreviewed. */

undefined4 FUN_c043d1c0(int *param_1)

{
  HANDLE hObject;
  
  if (((*(uint *)(*param_1 + 0x62c) & 0x2000000) == 0) &&
     (hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c043cf98,param_1,0,(LPDWORD)0x0),
     hObject != (HANDLE)0x0)) {
    CloseHandle(hObject);
    return 1;
  }
  return 0;
}



/* c043d230 FUN_c043d230 */

/* Boundary evidence: original MIPS .pdata c043d230..c043d2fb. Semantic name remains unreviewed. */

void FUN_c043d230(int *param_1,undefined4 *param_2,undefined1 *param_3)

{
  CHAR aCStack_58 [56];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  FUN_c043caf8(*param_1,aCStack_58,0x38);
  FUN_c04497b8();
  FUN_c04497a8();
  FUN_c04497a8();
  FUN_c04497a8();
  FUN_c0449798();
  *param_2 = param_1 + 0x235;
  *param_3 = 0x10;
  FUN_c0449d30(local_20);
  return;
}



/* c043d2fc FUN_c043d2fc */

/* Boundary evidence: original MIPS .pdata c043d2fc..c043d3b7. Semantic name remains unreviewed. */

undefined4 FUN_c043d2fc(int param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_c04497b8();
  FUN_c04497a8();
  FUN_c04497a8();
  FUN_c04497a8();
  FUN_c0449798();
  iVar1 = memcmp((void *)(param_1 + 0x8d4),param_2,0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x2b3;
  }
  return uVar2;
}



/* c043d3b8 FUN_c043d3b8 */

/* Boundary evidence: original MIPS .pdata c043d3b8..c043d483. Semantic name remains unreviewed. */

void FUN_c043d3b8(int *param_1,int *param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  CHAR aCStack_30 [16];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  iVar2 = *param_1;
  iVar1 = FUN_c043caf8(iVar2,aCStack_30,0xe);
  aCStack_30[iVar1] = '\0';
  if (*(int *)(iVar2 + 0xb3c) == 0) {
    FUN_c043e88c(param_1 + 0x12d,aCStack_30);
    *(undefined1 *)((int)param_1 + 0x5e5) = 0;
  }
  if (*(int *)(iVar2 + 0xb40) == 0) {
    FUN_c043e9c4(param_1 + 0x12d,(wchar_t *)(iVar2 + 0x408));
    *(undefined1 *)((int)param_1 + 0x5e5) = 1;
  }
  *(undefined1 *)((int)param_1 + 0x5e6) = 0x31;
  *param_2 = (int)param_1 + 0x5b5;
  *param_3 = 0x31;
  FUN_c0449d30(local_20);
  return;
}



/* c043d484 FUN_c043d484 */

/* Boundary evidence: original MIPS .pdata c043d484..c043d573. Semantic name remains unreviewed. */

undefined4 FUN_c043d484(int *param_1,void *param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint _Size;
  char acStack_48 [16];
  undefined1 auStack_38 [24];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  _Size = *(uint *)(param_4 + 0x324);
  uVar2 = 0x2b3;
  if ((_Size < 0xf) && (param_3 == 0x31)) {
    if (*(char *)((int)param_2 + 0x30) == '\0') {
      memcpy(acStack_48,(void *)(param_4 + 0x222),_Size);
      acStack_48[_Size] = '\0';
      FUN_c043e88c(param_1 + 0x12d,acStack_48);
    }
    else {
      if (*(char *)((int)param_2 + 0x30) != '\x01') goto LAB_c043d54c;
      FUN_c043e9c4(param_1 + 0x12d,(wchar_t *)(*param_1 + 0x408));
      param_2 = (void *)((int)param_2 + 0x18);
    }
    iVar1 = memcmp(param_2,auStack_38,0x18);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
LAB_c043d54c:
  FUN_c0449d30(local_20);
  return uVar2;
}



/* c043d574 FUN_c043d574 */

/* Boundary evidence: original MIPS .pdata c043d574..c043d7af. Semantic name remains unreviewed. */

int FUN_c043d574(int param_1,char *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  char local_230 [516];
  uint local_2c;
  
  local_2c = DAT_c044d82c;
  lVar6 = 0x2b3;
  iVar2 = FUN_c043c964(param_2,param_3,0x45,local_230,0x201);
  if (iVar2 != 0) {
    lVar6 = strtol(local_230,(char **)0x0,10);
  }
  *(undefined4 *)(param_1 + 0x8f4) = 0;
  iVar2 = FUN_c043c964(param_2,param_3,0x52,local_230,0x201);
  if ((iVar2 != 0) && (local_230[0] == '1')) {
    *(undefined4 *)(param_1 + 0x8f4) = 1;
    *(undefined4 *)(param_1 + 0x4ac) = 1;
  }
  *(undefined4 *)(param_1 + 0x8fc) = 0;
  iVar2 = FUN_c043c964(param_2,param_3,0x43,local_230,0x201);
  if (iVar2 != 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x34) + 4);
    uVar9 = (bVar1 & 0x7f) << 1;
    sVar3 = strlen(local_230);
    if (sVar3 == uVar9) {
      pbVar7 = (byte *)(param_1 + 0x4b4);
      uVar8 = 0;
      if ((bVar1 & 0x7f) != 0) {
        do {
          uVar4 = FUN_c0434494((int)local_230[uVar8]);
          if ((uVar8 & 1) == 0) {
            *pbVar7 = (byte)(uVar4 << 4);
          }
          else {
            *pbVar7 = *pbVar7 | (byte)uVar4;
            pbVar7 = pbVar7 + 1;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar9);
      }
      *(byte *)(param_1 + 0x5b4) = bVar1 & 0x7f;
      *(undefined4 *)(param_1 + 0x8fc) = 1;
    }
  }
  *(undefined4 *)(param_1 + 0x8f8) = 1;
  iVar2 = FUN_c043c964(param_2,param_3,0x56,local_230,0x201);
  if (iVar2 != 0) {
    lVar5 = strtol(local_230,(char **)0x0,10);
    *(long *)(param_1 + 0x8f8) = lVar5;
  }
  *(undefined4 *)(param_1 + 0x5e8) = 0;
  if (lVar6 == 0x288) {
    lVar6 = 0;
    *(undefined4 *)(param_1 + 0x5e8) = 1;
    if (*(int *)(param_1 + 0x8fc) == 0) {
      *(char *)(param_1 + 0x4b4) = *(char *)(param_1 + 0x4b4) + '\x17';
    }
  }
  else if (((lVar6 == 0x2b3) && (*(int *)(param_1 + 0x8f4) != 0)) &&
          (lVar6 = 0, *(int *)(param_1 + 0x8fc) == 0)) {
    *(char *)(param_1 + 0x4b4) = *(char *)(param_1 + 0x4b4) + '\x17';
  }
  FUN_c0449d30(local_2c);
  return lVar6;
}



/* c043d7b0 FUN_c043d7b0 */

/* Boundary evidence: original MIPS .pdata c043d7b0..c043d86f. Semantic name remains unreviewed. */

void FUN_c043d7b0(int *param_1,undefined4 *param_2,undefined1 *param_3)

{
  int iVar1;
  BYTE *pBVar2;
  CHAR aCStack_120 [260];
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  pBVar2 = (BYTE *)((int)param_1 + 0x5b5);
  iVar1 = *param_1;
  FUN_c04496e4(0x10,pBVar2);
  memset((void *)((int)param_1 + 0x5c5),0,8);
  FUN_c043c9f8(param_1,aCStack_120,0x101);
  FUN_c043eafc(param_1 + 0x12d,pBVar2,aCStack_120,(wchar_t *)(iVar1 + 0x408));
  *(undefined1 *)((int)param_1 + 0x5e5) = 0;
  *(undefined1 *)((int)param_1 + 0x5e6) = 0x31;
  *param_2 = pBVar2;
  *param_3 = 0x31;
  FUN_c0449d30(local_1c);
  return;
}



/* c043d870 FUN_c043d870 */

/* Boundary evidence: original MIPS .pdata c043d870..c043d9db. Semantic name remains unreviewed. */

void FUN_c043d870(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5,STRSAFE_LPSTR param_6)

{
  byte bVar1;
  HRESULT HVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 auStack_60 [2];
  byte local_58 [24];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  FUN_c043e960(param_1,auStack_30);
  FUN_c043e9a4(auStack_30,auStack_40);
  FUN_c04497e8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497c8();
  FUN_c043ea38(param_3,param_4,param_5,auStack_60);
  FUN_c04497e8();
  iVar4 = 0x14;
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497c8();
  *param_6 = 'S';
  param_6[1] = '=';
  pbVar3 = local_58;
  do {
    bVar1 = *pbVar3;
    iVar4 = iVar4 + -1;
    pbVar3 = pbVar3 + 1;
    HVar2 = StringCchPrintfA(param_6 + 2,3,"%02X",(uint)bVar1);
    param_6 = param_6 + 2 + HVar2;
  } while (iVar4 != 0);
  FUN_c0449d30(local_20);
  return;
}



/* c043d9dc FUN_c043d9dc */

/* Boundary evidence: original MIPS .pdata c043d9dc..c043da43. Semantic name remains unreviewed. */

void FUN_c043d9dc(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5,void *param_6,undefined4 param_7)

{
  int iVar1;
  char acStack_38 [44];
  uint local_c;
  
  local_c = DAT_c044d82c;
  FUN_c043d870(param_1,param_2,param_3,param_4,param_5,acStack_38);
  iVar1 = memcmp(param_6,acStack_38,0x2a);
  *(bool *)param_7 = iVar1 == 0;
  FUN_c0449d30(local_c);
  return;
}



/* c043da44 FUN_c043da44 */

/* Boundary evidence: original MIPS .pdata c043da44..c043db6b. Semantic name remains unreviewed. */

undefined4
FUN_c043da44(int *param_1,int param_2,undefined4 param_3,LPCWSTR param_4,char *param_5,
            size_t *param_6)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  CHAR aCStack_130 [260];
  uint local_2c;
  
  local_2c = DAT_c044d82c;
  uVar3 = 0x2b3;
  WideCharToMultiByte(1,0,param_4,-1,aCStack_130,0x101,(LPCSTR)0x0,(LPBOOL)0x0);
  FUN_c043eafc(param_1 + 0x12d,param_2,aCStack_130,(wchar_t *)(*param_1 + 0x408));
  iVar1 = memcmp((void *)(param_2 + 0x18),(void *)((int)param_1 + 0x5cd),0x18);
  if (iVar1 == 0) {
    uVar3 = 0;
    FUN_c043d870((wchar_t *)(*param_1 + 0x408),(void *)(param_2 + 0x18),param_2,param_1 + 0x12d,
                 aCStack_130,param_5);
    sVar2 = strlen(param_5);
    *param_6 = sVar2;
  }
  FUN_c0449d30(local_2c);
  return uVar3;
}



/* c043db6c FUN_c043db6c */

/* Boundary evidence: original MIPS .pdata c043db6c..c043dc77. Semantic name remains unreviewed. */

undefined4 FUN_c043db6c(int *param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  char local_128 [8];
  CHAR aCStack_120 [260];
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  uVar1 = 0x2b3;
  if (param_1[0x17a] != 0) {
    StringCchCopyW((STRSAFE_LPWSTR)(*param_1 + 0x408),0x101,(STRSAFE_LPCWSTR)(param_1 + 0x17c));
    memset(param_1 + 0x17c,0,0x202);
    RasSetEntryDialParams(0,*param_1 + 0x74,param_1[0x17b] == 0);
  }
  FUN_c043c9f8(param_1,aCStack_120,0x101);
  if ((0x29 < param_3) &&
     (FUN_c043d9dc((wchar_t *)(*param_1 + 0x408),(int)param_1 + 0x5cd,(int)param_1 + 0x5b5,
                   param_1 + 0x12d,aCStack_120,param_2,local_128), local_128[0] != '\0')) {
    uVar1 = 0;
  }
  FUN_c0449d30(local_1c);
  return uVar1;
}



/* c043dc78 FUN_c043dc78 */

/* Boundary evidence: original MIPS .pdata c043dc78..c043df6f. Semantic name remains unreviewed. */

void FUN_c043dc78(int *param_1,uint param_2,undefined4 param_3,uint param_4,LPCSTR param_5,
                 int param_6)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  STRSAFE_LPSTR pszDest;
  HRESULT local_788 [2];
  undefined1 auStack_780 [546];
  CHAR aCStack_55e [258];
  int local_45c;
  WCHAR aWStack_458 [276];
  char acStack_230 [516];
  uint local_2c;
  
  local_2c = DAT_c044d82c;
  iVar7 = param_1[0xd];
  if (((*(int *)(*param_1 + 0x6c) != 0) && (*(ushort *)(param_1 + 0x12a) == param_2)) &&
     (param_4 == *(byte *)(iVar7 + 5))) {
    FUN_c043c080(param_1);
    memset(aWStack_458,0,0x222);
    MultiByteToWideChar(1,0,param_5,param_6,aWStack_458,0x111);
    StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0xe),0x111,aWStack_458);
    local_788[0] = 0;
    pszDest = (STRSAFE_LPSTR)((int)param_1 + 0x7f6);
    iVar5 = 0x2b3;
    iVar2 = FUN_c0439bb8();
    if (iVar2 != 0) {
      iVar2 = MultiByteToWideChar(1,0,aCStack_55e,local_45c,(LPWSTR)(*param_1 + 0x408),0x100);
      *(undefined2 *)((iVar2 + 0x204) * 2 + *param_1) = 0;
      iVar5 = (**(code **)(iVar7 + 0xc))(param_1,param_3,param_4,auStack_780,pszDest,local_788);
      memset(auStack_780,0,0x328);
    }
    bVar1 = false;
    if (iVar5 == 0) {
      uVar4 = 3;
    }
    else {
      if ((char)param_1[0xc] != '\x05') {
        iVar2 = param_1[300];
        param_1[300] = iVar2 + 1U;
        if (iVar2 + 1U < *(uint *)(*param_1 + 0xadc)) {
          bVar1 = true;
          FUN_c04496e4((uint)*(byte *)(param_1 + 0x16d),(BYTE *)(param_1 + 0x12d));
          iVar2 = 0;
          if ((char)param_1[0x16d] != '\0') {
            iVar6 = 0;
            do {
              StringCchPrintfA(acStack_230 + iVar6,0x201 - iVar6,"%02X",
                               (uint)*(byte *)((int)(param_1 + 0x12d) + iVar2));
              iVar2 = iVar2 + 1;
              iVar6 = iVar6 + 2;
            } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x16d));
          }
          local_788[0] = StringCchPrintfA(pszDest,0x80,"E=%u R=1 C=%s V=%u",iVar5,acStack_230,
                                          (uint)*(byte *)(iVar7 + 6));
        }
        else {
          local_788[0] = StringCchPrintfA(pszDest,0x80,"E=%u R=0",iVar5);
        }
      }
      uVar4 = 4;
    }
    *(undefined1 *)((int)param_1 + 0x7f2) = uVar4;
    *(char *)((int)param_1 + 0x7f3) = (char)(short)param_1[0x12a];
    uVar3 = local_788[0] + 4;
    *(char *)(param_1 + 0x1fd) = (char)(uVar3 >> 8);
    *(char *)((int)param_1 + 0x7f5) = (char)uVar3;
    FUN_c043bd50(param_1,(undefined1 *)((int)param_1 + 0x7f2),uVar3);
    param_1[0x21e] = local_788[0] + 4;
    if (bVar1) {
      *(ushort *)(param_1 + 0x12a) = (short)param_1[0x12a] + 1U & 0xff;
      FUN_c043c4b8(param_1);
    }
    else {
      FUN_c043c3a0(param_1,iVar5);
    }
  }
  FUN_c0449d30(local_2c);
  return;
}



/* c043df70 FUN_c043df70 */

/* Boundary evidence: original MIPS .pdata c043df70..c043dff3. Semantic name remains unreviewed. */

void FUN_c043df70(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0xd];
  iVar2 = 0;
  FUN_c043c080(param_1);
  if (*(code **)(iVar1 + 0x10) != (code *)0x0) {
    iVar2 = (**(code **)(iVar1 + 0x10))(param_1,param_2,param_3);
  }
  FUN_c043c3a0(param_1,iVar2);
  return;
}



/* c043dff4 FUN_c043dff4 */

/* Boundary evidence: original MIPS .pdata c043dff4..c043e0b3. Semantic name remains unreviewed. */

void FUN_c043dff4(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[0xd];
  iVar1 = 0x2b3;
  if (param_1[299] == 0) {
    FUN_c043c080(param_1);
    if ((*(code **)(iVar2 + 0x14) != (code *)0x0) &&
       (iVar1 = (**(code **)(iVar2 + 0x14))(param_1,param_2,param_3), iVar1 == 0)) {
      param_1[299] = 1;
      *(ushort *)(param_1 + 0x12a) = (short)param_1[0x12a] + 1U & 0xff;
      iVar1 = FUN_c043d1c0(param_1);
      if (iVar1 != 0) {
        return;
      }
      iVar1 = 0x2b3;
    }
    FUN_c043c354(param_1,iVar1);
  }
  return;
}



/* c043e0b4 FUN_c043e0b4 */

/* Boundary evidence: original MIPS .pdata c043e0b4..c043e203. Semantic name remains unreviewed. */

void FUN_c043e0b4(int *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint _Size;
  byte *_Src;
  
  if (param_1[0xd] != 0) {
    bVar1 = *param_2;
    bVar2 = param_2[1];
    if (bVar1 != 0) {
      if (bVar1 < 3) {
        if (4 < param_3) {
          bVar3 = param_2[4];
          _Size = (uint)bVar3;
          _Src = param_2 + 5;
          if (_Size + 5 <= param_3) {
            if (bVar1 == 1) {
              if (*(int *)(*param_1 + 0x6c) == 0) {
                FUN_c043c080(param_1);
                *(ushort *)(param_1 + 0x12a) = (ushort)bVar2;
                *(byte *)(param_1 + 0x16d) = bVar3;
                memcpy(param_1 + 0x12d,_Src,_Size);
                FUN_c043cd74(param_1);
                FUN_c043c4b8(param_1);
              }
            }
            else {
              FUN_c043dc78(param_1,(uint)bVar2,_Src,_Size,(LPCSTR)(_Src + _Size),
                           (param_3 - _Size) + -5);
            }
          }
        }
      }
      else if ((bVar1 < 5) && ((uint)*(ushort *)(param_1 + 0x12a) == (uint)bVar2)) {
        if (bVar1 == 3) {
          FUN_c043df70(param_1,param_2 + 4,param_3 - 4);
        }
        else {
          FUN_c043dff4(param_1,param_2 + 4,param_3 - 4);
        }
      }
    }
  }
  return;
}



/* c043e204 FUN_c043e204 */

/* Boundary evidence: original MIPS .pdata c043e204..c043e263. Semantic name remains unreviewed. */

void FUN_c043e204(int *param_1)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(int *)(*param_1 + 0x6c) == 0) {
    uVar2 = param_1[0x129];
    if (uVar2 == 0) {
      return;
    }
    pvVar1 = (void *)((int)param_1 + 0x25a);
  }
  else {
    uVar2 = param_1[0x21e];
    if (uVar2 == 0) {
      FUN_c043cce0(param_1);
      return;
    }
    pvVar1 = (void *)((int)param_1 + 0x7f2);
  }
  FUN_c043bd50(param_1,pvVar1,uVar2);
  return;
}



/* c043e264 FUN_c043e264 */

/* Boundary evidence: original MIPS .pdata c043e264..c043e34f. Semantic name remains unreviewed. */

undefined4 FUN_c043e264(int *param_1)

{
  char cVar1;
  undefined **ppuVar2;
  undefined4 uVar3;
  
  cVar1 = (char)param_1[0xc];
  if (cVar1 == '\x05') {
    ppuVar2 = &PTR_DAT_c044d63c;
  }
  else {
    if (cVar1 == -0x80) {
      param_1[0xd] = (int)&PTR_DAT_c044d654;
      goto LAB_c043e2d4;
    }
    if (cVar1 != -0x7f) {
      return 0;
    }
    ppuVar2 = &PTR_DAT_c044d6c0;
  }
  param_1[0xd] = (int)ppuVar2;
LAB_c043e2d4:
  *(undefined2 *)(param_1 + 0xe) = 0;
  param_1[299] = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[0x17a] = 0;
  param_1[0x129] = 0;
  if (*(int *)(*param_1 + 0x6c) == 1) {
    *(undefined2 *)(param_1 + 0x12a) = 0;
    param_1[300] = 0;
    *(undefined1 *)(param_1 + 0x16d) = *(undefined1 *)(param_1[0xd] + 4);
    param_1[0x21e] = 0;
    FUN_c043cce0(param_1);
    uVar3 = 8;
  }
  else {
    *(undefined2 *)(param_1 + 0x12a) = 0x100;
    uVar3 = 7;
  }
  FUN_c043c4b8(param_1);
  return uVar3;
}



/* c043e350 FUN_c043e350 */

/* Boundary evidence: original MIPS .pdata c043e350..c043e3af. Semantic name remains unreviewed. */

undefined1 * FUN_c043e350(undefined1 *param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = WideCharToMultiByte(1,0,param_2,param_3,param_1 + 1,param_3 << 1,(LPCSTR)0x0,(LPBOOL)0x0);
  *param_1 = (char)iVar1;
  return param_1 + iVar1 + 1;
}



/* c043e3b0 FUN_c043e3b0 */

/* Boundary evidence: original MIPS .pdata c043e3b0..c043e5f7. Semantic name remains unreviewed. */

void FUN_c043e3b0(int *param_1,byte *param_2,uint param_3)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  uint _Size;
  byte *pbVar4;
  char *_Str;
  byte bVar5;
  undefined1 auStack_678 [546];
  undefined1 auStack_456 [258];
  uint local_354;
  byte local_350;
  byte local_34f;
  undefined1 local_34e;
  undefined1 local_34d;
  undefined1 local_34c;
  undefined1 auStack_34b [259];
  WCHAR aWStack_248 [274];
  uint local_24;
  
  local_24 = DAT_c044d82c;
  bVar5 = *param_2;
  if (bVar5 == 1) {
    if ((*(int *)(*param_1 + 0x6c) == 0) || (param_3 < 5)) goto LAB_c043e5c8;
    pbVar4 = param_2 + 4;
    uVar3 = (uint)*pbVar4;
    if ((param_3 < uVar3 + 6) || (_Size = (uint)pbVar4[uVar3 + 1], param_3 < _Size + uVar3 + 6))
    goto LAB_c043e5c8;
    bVar5 = 3;
    memset(aWStack_248,0,0x222);
    MultiByteToWideChar(1,0,(LPCSTR)(param_2 + 5),uVar3,aWStack_248,0x111);
    wcscpy((wchar_t *)(param_1 + 0xe),aWStack_248);
    iVar2 = FUN_c0439bb8();
    if (iVar2 == 0) {
      _Str = "Access Denied";
    }
    else {
      if ((local_354 == _Size) && (iVar2 = memcmp(auStack_456,pbVar4 + uVar3 + 2,_Size), iVar2 == 0)
         ) {
        bVar5 = 2;
        _Str = "OK";
      }
      else {
        _Str = "Access Denied";
      }
      memset(auStack_678,0,0x328);
    }
    sVar1 = strlen(_Str);
    local_34f = param_2[1];
    uVar3 = (sVar1 & 0xff) + 5;
    local_34e = (undefined1)(uVar3 >> 8);
    local_34d = (undefined1)uVar3;
    local_34c = (undefined1)sVar1;
    local_350 = bVar5;
    memcpy(auStack_34b,_Str,sVar1 & 0xff);
    FUN_c043bd50(param_1,&local_350,uVar3);
  }
  else {
    if ((((bVar5 < 2) || (3 < bVar5)) || (*(int *)(*param_1 + 0x6c) != 0)) ||
       (*(ushort *)((int)param_1 + 0x8e6) == (ushort)param_2[1])) goto LAB_c043e5c8;
    *(ushort *)((int)param_1 + 0x8e6) = (ushort)param_2[1];
    bVar5 = *param_2;
  }
  iVar2 = 0;
  if (bVar5 != 2) {
    iVar2 = 0x2b3;
  }
  FUN_c043c3a0(param_1,iVar2);
LAB_c043e5c8:
  FUN_c0449d30(local_24);
  return;
}



/* c043e5f8 FUN_c043e5f8 */

/* Boundary evidence: original MIPS .pdata c043e5f8..c043e647. Semantic name remains unreviewed. */

void FUN_c043e5f8(int *param_1)

{
  if ((*(int *)(*param_1 + 0x6c) == 0) && (param_1[0x23a] != 0)) {
    *(char *)(param_1[0x23a] + 1) = (char)param_1[0x239];
    *(char *)(param_1 + 0x239) = (char)param_1[0x239] + '\x01';
    FUN_c043bd50(param_1,(void *)param_1[0x23a],param_1[0x23b]);
  }
  return;
}



/* c043e648 FUN_c043e648 */

/* Boundary evidence: original MIPS .pdata c043e648..c043e763. Semantic name remains unreviewed. */

int FUN_c043e648(int *param_1)

{
  size_t sVar1;
  size_t sVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  wchar_t awStack_240 [274];
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  *(undefined2 *)((int)param_1 + 0x8e6) = 0x100;
  FUN_c043be98(*param_1,awStack_240);
  sVar1 = wcslen(awStack_240);
  iVar6 = *param_1;
  sVar2 = wcslen((wchar_t *)(iVar6 + 0x408));
  puVar3 = (undefined1 *)FUN_c04343d0(iVar6,(sVar2 + sVar1 + 3) * 2);
  param_1[0x23a] = (int)puVar3;
  if (puVar3 == (undefined1 *)0x0) {
    FUN_c043c354(param_1,0x285);
    FUN_c0449d30(local_1c);
    iVar6 = param_1[1];
  }
  else {
    puVar4 = FUN_c043e350(puVar3 + 4,awStack_240,sVar1);
    puVar4 = FUN_c043e350(puVar4,(LPCWSTR)(*param_1 + 0x408),sVar2);
    *puVar3 = 1;
    uVar5 = (int)puVar4 - (int)puVar3;
    puVar3[1] = (char)param_1[0x239];
    *(char *)(param_1 + 0x239) = (char)param_1[0x239] + '\x01';
    puVar3[2] = (char)(uVar5 >> 8);
    puVar3[3] = (char)uVar5;
    param_1[0x23b] = uVar5;
    FUN_c043bd50(param_1,puVar3,uVar5);
    FUN_c0449d30(local_1c);
    iVar6 = 8;
  }
  return iVar6;
}



/* c043e764 FUN_c043e764 */

/* Boundary evidence: original MIPS .pdata c043e764..c043e7c7. Semantic name remains unreviewed. */

int FUN_c043e764(int *param_1)

{
  int iVar1;
  
  *(undefined2 *)(param_1 + 0xe) = 0;
  if (*(int *)(*param_1 + 0x6c) == 0) {
    *(undefined1 *)(param_1 + 0x239) = 3;
    iVar1 = FUN_c043e648(param_1);
  }
  else {
    iVar1 = 7;
  }
  FUN_c043c4b8(param_1);
  return iVar1;
}



/* c043e7c8 FUN_c043e7c8 */

/* Boundary evidence: original MIPS .pdata c043e7c8..c043e823. Semantic name remains unreviewed. */

void FUN_c043e7c8(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)param_1[0x23a];
  if (puVar1 != (undefined1 *)0x0) {
    for (iVar2 = param_1[0x23b]; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    FUN_c0434420(*param_1,(LPVOID)param_1[0x23a]);
    param_1[0x23a] = 0;
    param_1[0x23b] = 0;
  }
  return;
}



/* c043e824 FUN_c043e824 */

/* Boundary evidence: original MIPS .pdata c043e824..c043e88b. Semantic name remains unreviewed. */

void FUN_c043e824(char *param_1)

{
  byte abStack_20 [14];
  undefined1 local_12;
  uint local_10;
  
  local_10 = DAT_c044d82c;
  strncpy((char *)abStack_20,param_1,0xe);
  local_12 = 0;
  FUN_c043444c(abStack_20);
  FUN_c043eda8();
  FUN_c043eda8();
  FUN_c0449d30(local_10);
  return;
}



/* c043e88c FUN_c043e88c */

/* Boundary evidence: original MIPS .pdata c043e88c..c043e8eb. Semantic name remains unreviewed. */

void FUN_c043e88c(undefined4 param_1,char *param_2)

{
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  FUN_c043e824(param_2);
  FUN_c043edd4(param_1,auStack_28);
  FUN_c0449d30(local_18);
  return;
}



/* c043e8ec FUN_c043e8ec */

/* Boundary evidence: original MIPS .pdata c043e8ec..c043e95f. Semantic name remains unreviewed. */

void FUN_c043e8ec(undefined4 param_1,undefined4 param_2,void *param_3)

{
  undefined1 auStack_30 [28];
  uint local_14;
  
  local_14 = DAT_c044d82c;
  FUN_c0449808();
  FUN_c04497f8();
  memcpy(param_3,auStack_30,0x10);
  FUN_c0449d30(local_14);
  return;
}



/* c043e960 FUN_c043e960 */

/* Boundary evidence: original MIPS .pdata c043e960..c043e9a3. Semantic name remains unreviewed. */

void FUN_c043e960(wchar_t *param_1,void *param_2)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  FUN_c043e8ec(param_1,sVar1 << 1,param_2);
  return;
}



/* c043e9a4 FUN_c043e9a4 */

/* Boundary evidence: original MIPS .pdata c043e9a4..c043e9c3. Semantic name remains unreviewed. */

void FUN_c043e9a4(undefined4 param_1,void *param_2)

{
  FUN_c043e8ec(param_1,0x10,param_2);
  return;
}



/* c043e9c4 FUN_c043e9c4 */

/* Boundary evidence: original MIPS .pdata c043e9c4..c043ea37. Semantic name remains unreviewed. */

void FUN_c043e9c4(undefined4 param_1,wchar_t *param_2)

{
  size_t sVar1;
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  sVar1 = wcslen(param_2);
  FUN_c043e8ec(param_2,sVar1 << 1,auStack_28);
  FUN_c043edd4(param_1,auStack_28);
  FUN_c0449d30(local_18);
  return;
}



/* c043ea38 FUN_c043ea38 */

/* Boundary evidence: original MIPS .pdata c043ea38..c043eafb. Semantic name remains unreviewed. */

void FUN_c043ea38(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar1 = DAT_c044d82c;
  FUN_c04497e8();
  FUN_c04497d8();
  FUN_c04497d8();
  strlen(param_3);
  FUN_c04497d8();
  FUN_c04497c8();
  *param_4 = local_30;
  param_4[1] = local_2c;
  FUN_c0449d30(uVar1);
  return;
}



/* c043eafc FUN_c043eafc */

/* Boundary evidence: original MIPS .pdata c043eafc..c043eb77. Semantic name remains unreviewed. */

void FUN_c043eafc(undefined4 param_1,undefined4 param_2,char *param_3,wchar_t *param_4)

{
  size_t sVar1;
  undefined4 auStack_30 [2];
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  FUN_c043ea38(param_2,param_1,param_3,auStack_30);
  sVar1 = wcslen(param_4);
  FUN_c043e8ec(param_4,sVar1 << 1,auStack_28);
  FUN_c043edd4(auStack_30,auStack_28);
  FUN_c0449d30(local_18);
  return;
}



/* c043eb78 FUN_c043eb78 */

/* Boundary evidence: original MIPS .pdata c043eb78..c043ec2b. Semantic name remains unreviewed. */

void FUN_c043eb78(wchar_t *param_1,undefined4 param_2,void *param_3)

{
  size_t sVar1;
  BYTE aBStack_220 [512];
  size_t local_20;
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  FUN_c04496e4(0x200,aBStack_220);
  sVar1 = wcslen(param_1);
  memcpy((void *)((int)&local_20 + sVar1 * -2),param_1,sVar1 * 2);
  local_20 = sVar1 * 2;
  memcpy(param_3,aBStack_220,0x204);
  FUN_c0449828();
  FUN_c0449818();
  FUN_c0449d30(local_1c);
  return;
}



/* c043ec2c FUN_c043ec2c */

/* Boundary evidence: original MIPS .pdata c043ec2c..c043ec9f. Semantic name remains unreviewed. */

void FUN_c043ec2c(wchar_t *param_1,wchar_t *param_2,void *param_3)

{
  size_t sVar1;
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  sVar1 = wcslen(param_2);
  FUN_c043e8ec(param_2,sVar1 << 1,auStack_28);
  FUN_c043eb78(param_1,auStack_28,param_3);
  FUN_c0449d30(local_18);
  return;
}



/* c043eca0 FUN_c043eca0 */

/* Boundary evidence: original MIPS .pdata c043eca0..c043ecf7. Semantic name remains unreviewed. */

void FUN_c043eca0(void)

{
  FUN_c043ed84();
  FUN_c043ed84();
  return;
}



/* c043ecf8 FUN_c043ecf8 */

/* Boundary evidence: original MIPS .pdata c043ecf8..c043ed83. Semantic name remains unreviewed. */

void FUN_c043ecf8(wchar_t *param_1,wchar_t *param_2)

{
  size_t sVar1;
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  sVar1 = wcslen(param_2);
  FUN_c043e8ec(param_2,sVar1 << 1,auStack_28);
  sVar1 = wcslen(param_1);
  FUN_c043e8ec(param_1,sVar1 << 1,auStack_38);
  FUN_c043eca0();
  FUN_c0449d30(local_18);
  return;
}



/* c043ed84 FUN_c043ed84 */

/* Boundary evidence: original MIPS .pdata c043ed84..c043eda7. Semantic name remains unreviewed. */

void FUN_c043ed84(void)

{
  FUN_c0449838();
  return;
}



/* c043eda8 FUN_c043eda8 */

/* Boundary evidence: original MIPS .pdata c043eda8..c043edd3. Semantic name remains unreviewed. */

void FUN_c043eda8(void)

{
  FUN_c0449838();
  return;
}



/* c043edd4 FUN_c043edd4 */

/* Boundary evidence: original MIPS .pdata c043edd4..c043ee77. Semantic name remains unreviewed. */

void FUN_c043edd4(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined1 auStack_38 [24];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  memset(auStack_38,0,0x15);
  memcpy(auStack_38,param_2,0x10);
  iVar1 = 3;
  do {
    FUN_c0449838();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_c0449d30(local_20);
  return;
}



/* c043ee78 FUN_c043ee78 */

/* Boundary evidence: original MIPS .pdata c043ee78..c043ee93. Semantic name remains unreviewed. */

void FUN_c043ee78(int *param_1,uint param_2,void *param_3,uint param_4)

{
  FUN_c0447448(*param_1,param_2,param_3,param_4);
  return;
}



/* c043ee94 FUN_c043ee94 */

/* Boundary evidence: original MIPS .pdata c043ee94..c043eeb3. Semantic name remains unreviewed. */

undefined4 FUN_c043ee94(int *param_1)

{
  FUN_c04335a8(*param_1);
  return 0;
}



/* c043eeb4 FUN_c043eeb4 */

/* Boundary evidence: original MIPS .pdata c043eeb4..c043eed3. Semantic name remains unreviewed. */

undefined4 FUN_c043eeb4(int *param_1)

{
  FUN_c04335c4(*param_1);
  return 0;
}



/* c043eed4 FUN_c043eed4 */

/* Boundary evidence: original MIPS .pdata c043eed4..c043eef3. Semantic name remains unreviewed. */

undefined4 FUN_c043eed4(int *param_1)

{
  FUN_c043f900(param_1);
  return 0;
}



/* c043eef4 FUN_c043eef4 */

/* Boundary evidence: original MIPS .pdata c043eef4..c043ef33. Semantic name remains unreviewed. */

undefined4 FUN_c043eef4(int *param_1)

{
  if ((*(uint *)(*param_1 + 0x62c) & 0x1800) == 0x1800) {
    FUN_c0439d7c(*(int **)(*param_1 + 0xaa8),(undefined *)0x0,0);
  }
  return 0;
}



/* c043ef34 FUN_c043ef34 */

/* Boundary evidence: original MIPS .pdata c043ef34..c043efef. Semantic name remains unreviewed. */

undefined4 FUN_c043ef34(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  FUN_c04410d8(param_1 + 6);
  FUN_c0441120(param_1 + 0x119a);
  param_1[4] = 1;
  *(undefined2 *)((int)param_1 + 0x4666) = 0;
  *(undefined2 *)(param_1 + 0x1199) = 0;
  param_1[0x199c] = 0;
  *(undefined2 *)(param_1 + 5) = 0;
  param_1[0x199d] = 0;
  if ((param_1[2] & param_1[0x199e]) != 0) {
    puVar1 = FUN_c04405c0(param_1,param_1[2],0);
    param_1[0x19a0] = (int)puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0xe;
    }
  }
  if ((param_1[3] & param_1[0x199e]) != 0) {
    puVar1 = FUN_c04405c0(param_1,param_1[3],2);
    param_1[0x199f] = (int)puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0xe;
    }
  }
  FUN_c0436b1c(*(undefined4 **)(*param_1 + 0xab0));
  return uVar2;
}



/* c043eff0 FUN_c043eff0 */

/* Boundary evidence: original MIPS .pdata c043eff0..c043f03b. Semantic name remains unreviewed. */

undefined4 FUN_c043eff0(int *param_1)

{
  FUN_c044056c(param_1,(LPVOID)param_1[0x19a0]);
  FUN_c044056c(param_1,(LPVOID)param_1[0x199f]);
  param_1[0x19a0] = 0;
  param_1[0x199f] = 0;
  FUN_c043f900(param_1);
  return 0;
}



/* c043f03c FUN_c043f03c */

/* Boundary evidence: original MIPS .pdata c043f03c..c043f057. Semantic name remains unreviewed. */

void FUN_c043f03c(int param_1)

{
  FUN_c044aad0(*(int **)(param_1 + 4));
  return;
}



/* c043f058 FUN_c043f058 */

/* Boundary evidence: original MIPS .pdata c043f058..c043f18f. Semantic name remains unreviewed. */

int FUN_c043f058(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  piVar1 = (int *)FUN_c04343d0(param_1,0x6694);
  if (piVar1 == (int *)0x0) {
LAB_c043f090:
    iVar4 = 8;
  }
  else {
    iVar4 = FUN_c04335e0(param_1,0x80fd,&PTR_FUN_c044d728,piVar1);
    if ((iVar4 == 0) && (iVar4 = FUN_c04335e0(param_1,0xfd,&PTR_FUN_c044d744,piVar1), iVar4 == 0)) {
      *piVar1 = param_1;
      uVar3 = *(uint *)(param_1 + 0xb28) & 0x60;
      piVar1[0x199e] = uVar3;
      if (((*(uint *)(param_1 + 0x62c) & 0x1800) != 0x1800) || (uVar3 != 0)) {
        piVar2 = FUN_c044a4d4(&PTR_DAT_c044d6fc,&LAB_c043f8f8,(int)piVar1);
        piVar1[1] = (int)piVar2;
        if (piVar2 != (int *)0x0) {
          FUN_c043fbd8(piVar1);
          FUN_c043f900(piVar1);
          if (piVar1[2] != 0) {
            FUN_c044adc0((int *)piVar1[1]);
          }
          goto LAB_c043f0a4;
        }
        goto LAB_c043f090;
      }
      iVar4 = 0x57;
    }
  }
  FUN_c0434420(param_1,piVar1);
  piVar1 = (int *)0x0;
LAB_c043f0a4:
  *param_2 = piVar1;
  return iVar4;
}



/* c043f190 FUN_c043f190 */

/* Boundary evidence: original MIPS .pdata c043f190..c043f1f7. Semantic name remains unreviewed. */

void FUN_c043f190(int *param_1)

{
  if (param_1 != (int *)0x0) {
    FUN_c044a668((HLOCAL)param_1[1]);
    FUN_c0434420(*param_1,(LPVOID)param_1[0x19a3]);
    param_1[0x19a3] = 0;
    param_1[0x19a4] = 0;
    FUN_c044056c(param_1,(LPVOID)param_1[0x199f]);
    FUN_c044056c(param_1,(LPVOID)param_1[0x19a0]);
    FUN_c0434420(*param_1,param_1);
  }
  return;
}



/* c043f1f8 FUN_c043f1f8 */

/* Boundary evidence: original MIPS .pdata c043f1f8..c043f283. Semantic name remains unreviewed. */

void FUN_c043f1f8(int *param_1)

{
  int iVar1;
  ushort local_18 [2];
  uint local_14;
  
  FUN_c0434420(*param_1,(LPVOID)param_1[0x19a3]);
  local_14 = 2;
  param_1[0x19a3] = 0;
  param_1[0x19a4] = 0;
  FUN_c043a220(*(int *)(*param_1 + 0xaa8),1,1,local_18,&local_14);
  iVar1 = FUN_c04343d0(*param_1,local_18[0] + 0x40);
  param_1[0x19a3] = iVar1;
  if (iVar1 != 0) {
    param_1[0x19a4] = local_18[0] + 0x40;
  }
  FUN_c044af20((int *)param_1[1]);
  return;
}



/* c043f284 FUN_c043f284 */

/* Boundary evidence: original MIPS .pdata c043f284..c043f29f. Semantic name remains unreviewed. */

void FUN_c043f284(int param_1)

{
  FUN_c044aa3c(*(int **)(param_1 + 4));
  return;
}



/* c043f2a0 FUN_c043f2a0 */

/* Boundary evidence: original MIPS .pdata c043f2a0..c043f2bb. Semantic name remains unreviewed. */

void FUN_c043f2a0(int param_1)

{
  FUN_c044adc0(*(int **)(param_1 + 4));
  return;
}



/* c043f2bc FUN_c043f2bc */

/* Boundary evidence: original MIPS .pdata c043f2bc..c043f2d7. Semantic name remains unreviewed. */

void FUN_c043f2bc(int param_1)

{
  FUN_c044a990(*(int **)(param_1 + 4));
  return;
}



/* c043f2d8 FUN_c043f2d8 */

/* Boundary evidence: original MIPS .pdata c043f2d8..c043f2f3. Semantic name remains unreviewed. */

void FUN_c043f2d8(int param_1)

{
  FUN_c044ae68(*(int **)(param_1 + 4));
  return;
}



/* c043f2f4 FUN_c043f2f4 */

/* Boundary evidence: original MIPS .pdata c043f2f4..c043f317. Semantic name remains unreviewed. */

void FUN_c043f2f4(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 1;
  FUN_c04410d8((void *)(param_1 + 0x18));
  return;
}



/* c043f318 FUN_c043f318 */

/* Boundary evidence: original MIPS .pdata c043f318..c043f363. Semantic name remains unreviewed. */

void FUN_c043f318(int *param_1)

{
  undefined1 local_10;
  char local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  local_e = 0;
  local_f = (char)param_1[0x19a2] + '\x01';
  *(char *)(param_1 + 0x19a2) = local_f;
  local_10 = 0xe;
  local_d = 4;
  FUN_c0447448(*param_1,0x80fd,&local_10,4);
  return;
}



/* c043f364 FUN_c043f364 */

/* Boundary evidence: original MIPS .pdata c043f364..c043f53b. Semantic name remains unreviewed. */

void FUN_c043f364(int *param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint local_18;
  void *local_14;
  
  if ((*(int *)(param_1[1] + 8) == 9) && (1 < *(uint *)(param_2 + 2))) {
    pbVar3 = *(byte **)(param_2 + 4);
    uVar2 = (uint)*pbVar3 * 0x100 + (uint)pbVar3[1];
    *(byte **)(param_2 + 4) = pbVar3 + 2;
    *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) - 2;
    if ((uVar2 & 0x8000) != 0) {
      if ((param_1[2] & 0x60U) != 0) {
        if (0xeff < (uVar2 - *(ushort *)(param_1 + 0x1199) & 0xfff)) {
          return;
        }
        FUN_c043ffd8();
      }
      if ((param_1[2] & 1U) != 0) {
        FUN_c0441120(param_1 + 0x119a);
      }
      *(ushort *)(param_1 + 0x1199) = (ushort)uVar2 & 0xfff;
      param_1[0x199c] = 0;
    }
    if ((param_1[0x199c] == 0) && ((uVar2 & 0xfff) == (uint)*(ushort *)(param_1 + 0x1199))) {
      *(ushort *)(param_1 + 0x1199) = *(ushort *)(param_1 + 0x1199) + 1 & 0xfff;
      if ((uVar2 & 0x1000) != 0) {
        FUN_c0440138((int)param_1);
      }
      if ((uVar2 & 0x2000) != 0) {
        if ((param_1[2] & 1U) == 0) {
          return;
        }
        iVar1 = FUN_c0441144(*(byte **)(param_2 + 4),*(int *)(param_2 + 2),uVar2 >> 8 & 0x40,
                             &local_14,(int *)&local_18,(byte *)(param_1 + 0x119a));
        if (iVar1 == 0) {
          FUN_c043f318(param_1);
          param_1[0x199c] = 1;
          return;
        }
        if ((uint)param_1[0x19a4] < local_18) {
          return;
        }
        memcpy((void *)param_1[0x19a3],local_14,local_18);
        *(int *)(param_2 + 4) = param_1[0x19a3];
        *(uint *)(param_2 + 2) = local_18;
      }
      FUN_c043327c(*param_1,param_2);
    }
    else {
      param_1[0x199c] = 1;
      FUN_c043f318(param_1);
    }
  }
  return;
}



/* c043f53c FUN_c043f53c */

/* Boundary evidence: original MIPS .pdata c043f53c..c043f5af. Semantic name remains unreviewed. */

void FUN_c043f53c(int *param_1,int param_2)

{
  if (*(int *)(param_1[1] + 8) < 2) {
    FUN_c043bdbc(*(int **)(*param_1 + 0xaac));
  }
  if (((int *)param_1[1])[2] == 2) {
    FUN_c044adc0((int *)param_1[1]);
  }
  FUN_c044afb0((int *)param_1[1],*(byte **)(param_2 + 8),*(uint *)(param_2 + 4));
  return;
}



/* c043f5b0 FUN_c043f5b0 */

/* Boundary evidence: original MIPS .pdata c043f5b0..c043f7b7. Semantic name remains unreviewed. */

undefined4 FUN_c043f5b0(int param_1,int *param_2,undefined2 *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  uint *puVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  ushort uVar9;
  
  iVar7 = *(int *)(*(int *)(param_1 + 0xab0) + 0xc);
  if ((*(int *)(*(int *)(iVar7 + 4) + 8) != 9) || (*(int *)(iVar7 + 0xc) == 0)) {
    if ((*(uint *)(param_1 + 0x62c) & 0x1800) == 0x1800) {
      return 0;
    }
    return 1;
  }
  iVar8 = *param_2;
  puVar6 = (undefined1 *)(*(int *)(iVar8 + 8) + -2);
  *(undefined1 **)(iVar8 + 8) = puVar6;
  *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + 2;
  *puVar6 = *(undefined1 *)((int)param_3 + 1);
  *(char *)(*(int *)(iVar8 + 8) + 1) = (char)*param_3;
  *param_3 = 0xfd;
  uVar9 = *(ushort *)(iVar7 + 0x14);
  *(ushort *)(iVar7 + 0x14) = uVar9 + 1 & 0xfff;
  iVar2 = iVar8;
  if ((*(uint *)(iVar7 + 0xc) & 1) != 0) {
    iVar2 = FUN_c04476cc(*(int *)(param_1 + 0xaa4));
    if (iVar2 == 0) {
      iVar2 = iVar8;
      if ((*(uint *)(iVar7 + 0xc) & 0x60) == 0) goto LAB_c043f70c;
      uVar9 = uVar9 | 0x8000;
      FUN_c04410d8((void *)(iVar7 + 0x18));
      *(undefined4 *)(iVar7 + 0x201c) = 0x2001;
    }
    else {
      puVar5 = (uint *)(iVar2 + 0xc);
      uVar3 = *(undefined4 *)(iVar8 + 0x1c);
      pbVar4 = (byte *)(*(int *)(iVar2 + 8) + 6);
      *puVar5 = *puVar5 - 6;
      *(undefined4 *)(iVar2 + 0x1c) = uVar3;
      *(byte **)(iVar2 + 8) = pbVar4;
      *puVar5 = *(uint *)(iVar8 + 0xc);
      uVar1 = FUN_c044065c(*(byte **)(iVar8 + 8),pbVar4,puVar5,(byte *)(iVar7 + 0x18));
      uVar9 = uVar1 | uVar9;
      if ((uVar9 & 0x8000) == 0) {
        FUN_c04476a0(*(int *)(param_1 + 0xaa4),iVar8);
        *param_2 = iVar2;
        goto LAB_c043f70c;
      }
      FUN_c04476a0(*(int *)(param_1 + 0xaa4),iVar2);
    }
    *(undefined4 *)(iVar7 + 0x10) = 1;
    iVar2 = iVar8;
  }
LAB_c043f70c:
  if ((*(uint *)(iVar7 + 0xc) & 0x60) != 0) {
    uVar3 = FUN_c04400a4(iVar7);
    uVar9 = (ushort)uVar3 | uVar9;
  }
  if (*(int *)(iVar7 + 0x10) != 0) {
    *(undefined4 *)(iVar7 + 0x10) = 0;
    uVar9 = uVar9 | 0x8000;
  }
  puVar6 = (undefined1 *)(*(int *)(iVar2 + 8) + -2);
  *(undefined1 **)(iVar2 + 8) = puVar6;
  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 2;
  *puVar6 = (char)(uVar9 >> 8);
  *(char *)(*(int *)(iVar2 + 8) + 1) = (char)uVar9;
  return 1;
}



/* c043f7b8 FUN_c043f7b8 */

/* Boundary evidence: original MIPS .pdata c043f7b8..c043f8f7. Semantic name remains unreviewed. */

void FUN_c043f7b8(undefined4 param_1,undefined4 param_2,byte *param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  size_t sVar5;
  int iVar6;
  char *pcVar7;
  
  pcVar7 = (char *)*param_5;
  *pcVar7 = '\0';
  bVar1 = *param_3;
  bVar2 = param_3[1];
  bVar3 = param_3[2];
  bVar4 = param_3[3];
  if ((bVar4 & 1) != 0) {
    strcat(pcVar7,"Compression,");
  }
  if ((bVar4 & 0x20) != 0) {
    strcat(pcVar7,"40-bit-encryption,");
  }
  if ((bVar4 & 0x80) != 0) {
    strcat(pcVar7,"56-bit-encryption,");
  }
  if ((bVar4 & 0x40) != 0) {
    strcat(pcVar7,"128-bit-encryption,");
  }
  if ((bVar1 & 1) != 0) {
    strcat(pcVar7,"Stateless,");
  }
  if ((bVar4 & 0x10) != 0) {
    strcat(pcVar7,"40-bit-encryption(obsolete),");
  }
  sVar5 = strlen(pcVar7);
  pcVar7 = pcVar7 + sVar5;
  if ((CONCAT31(CONCAT21(CONCAT11(bVar1,bVar2),bVar3),bVar4) & 0xfeffff0e) != 0) {
    iVar6 = sprintf(pcVar7,"Unknown(%x)");
    pcVar7 = pcVar7 + iVar6;
  }
  *param_5 = pcVar7;
  return;
}



/* c043f900 FUN_c043f900 */

void FUN_c043f900(int *param_1)

{
  param_1[2] = 0;
  if ((*(uint *)(*param_1 + 0x62c) & 0x200) != 0) {
    param_1[2] = 1;
  }
  if ((param_1[0x199e] != 0) && ((*(uint *)(*param_1 + 0x62c) & 0x1800) == 0x1800)) {
    param_1[2] = param_1[2] | param_1[0x199e];
  }
  return;
}



/* c043fbd8 FUN_c043fbd8 */

/* Boundary evidence: original MIPS .pdata c043fbd8..c043fc5f. Semantic name remains unreviewed. */

void FUN_c043fbd8(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((param_1[0x199e] == 0) || ((*(uint *)(*param_1 + 0x62c) & 0x1800) != 0x1800)) {
    if ((*(uint *)(*param_1 + 0x62c) & 0x200) == 0) {
      if (param_1[0x199e] == 0) {
        uVar1 = 0;
        uVar2 = 0;
      }
      else {
        uVar1 = 2;
        uVar2 = 1;
      }
    }
    else {
      uVar1 = 2;
      uVar2 = uVar1;
    }
  }
  else {
    uVar1 = 3;
    uVar2 = uVar1;
  }
  FUN_c044a6b8(param_1[1],&DAT_c044d760,uVar1,uVar2);
  return;
}



/* c043fc60 FUN_c043fc60 */

/* Boundary evidence: original MIPS .pdata c043fc60..c043fd2b. Semantic name remains unreviewed. */

void FUN_c043fc60(int param_1)

{
  size_t _Size;
  undefined1 auStack_28 [20];
  uint local_14;
  
  local_14 = DAT_c044d82c;
  _Size = *(size_t *)(param_1 + 0x20);
  memset(auStack_28,0,0x14);
  FUN_c04497e8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497c8();
  memcpy((void *)(param_1 + 0x10),auStack_28,_Size);
  FUN_c0449d30(local_14);
  return;
}



/* c043fd2c FUN_c043fd2c */

/* Boundary evidence: original MIPS .pdata c043fd2c..c043fde3. Semantic name remains unreviewed. */

void FUN_c043fd2c(int param_1)

{
  size_t _Size;
  undefined1 auStack_30 [20];
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  _Size = *(size_t *)(param_1 + 0x20);
  FUN_c04497e8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497c8();
  memcpy((void *)(param_1 + 0x10),auStack_30,_Size);
  FUN_c0449d30(local_1c);
  return;
}



/* c043fde4 FUN_c043fde4 */

/* Boundary evidence: original MIPS .pdata c043fde4..c043fea3. Semantic name remains unreviewed. */

void FUN_c043fde4(void *param_1)

{
  undefined1 auStack_30 [20];
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  memset(auStack_30,0,0x14);
  FUN_c04497e8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497c8();
  memcpy(param_1,auStack_30,0x10);
  FUN_c0449d30(local_1c);
  return;
}



/* c043fea4 FUN_c043fea4 */

/* Boundary evidence: original MIPS .pdata c043fea4..c043ffd7. Semantic name remains unreviewed. */

void FUN_c043fea4(void *param_1)

{
  uint uVar1;
  char *_Str;
  size_t _Size;
  char *local_38;
  undefined1 auStack_30 [20];
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  _Size = *(size_t *)((int)param_1 + 0x20);
  memset(auStack_30,0,0x14);
  uVar1 = *(uint *)((int)param_1 + 0x130) & 3;
  _Str = PTR_s_On_the_client_side__this_is_the_r_c044d7ac;
  if ((uVar1 != 0) &&
     ((uVar1 == 0 ||
      ((_Str = PTR_s_On_the_client_side__this_is_the_s_c044d7a8, 2 < uVar1 &&
       (_Str = PTR_s_On_the_client_side__this_is_the_r_c044d7ac, uVar1 != 3)))))) {
    _Str = local_38;
  }
  FUN_c04497e8();
  FUN_c04497d8();
  FUN_c04497d8();
  strlen(_Str);
  FUN_c04497d8();
  FUN_c04497d8();
  FUN_c04497c8();
  memcpy(param_1,auStack_30,_Size);
  memcpy((void *)((int)param_1 + 0x10),auStack_30,_Size);
  FUN_c0449d30(local_1c);
  return;
}



/* c043ffd8 FUN_c043ffd8 */

/* Boundary evidence: original MIPS .pdata c043ffd8..c043ffff. Semantic name remains unreviewed. */

void FUN_c043ffd8(void)

{
  FUN_c0449828();
  return;
}



/* c0440000 FUN_c0440000 */

/* Boundary evidence: original MIPS .pdata c0440000..c04400a3. Semantic name remains unreviewed. */

void FUN_c0440000(int param_1)

{
  FUN_c043fc60(param_1);
  FUN_c0449828();
  FUN_c0449818();
  if ((*(uint *)(param_1 + 300) & 0x20) != 0) {
    *(undefined1 *)(param_1 + 0x10) = 0xd1;
    *(undefined1 *)(param_1 + 0x11) = 0x26;
    *(undefined1 *)(param_1 + 0x12) = 0x9e;
  }
  FUN_c0449828();
  return;
}



/* c04400a4 FUN_c04400a4 */

/* Boundary evidence: original MIPS .pdata c04400a4..c0440137. Semantic name remains unreviewed. */

undefined4 FUN_c04400a4(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x667c);
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_c0449828();
  }
  if ((*(ushort *)(param_1 + 0x14) & 0xff) == 0) {
    FUN_c0440000(iVar1);
  }
  FUN_c0449818();
  return 0x1000;
}



/* c0440138 FUN_c0440138 */

/* Boundary evidence: original MIPS .pdata c0440138..c04401e3. Semantic name remains unreviewed. */

void FUN_c0440138(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x6680);
  if ((*(uint *)(param_1 + 8) & 0x60) != 0) {
    bVar1 = *(byte *)(param_1 + 0x4665);
    for (uVar2 = *(uint *)(param_1 + 0x6674); uVar2 != bVar1; uVar2 = uVar2 + 1 & 0xf) {
      FUN_c0440000(iVar3);
    }
    *(uint *)(param_1 + 0x6674) = (uint)bVar1;
    FUN_c0449818();
  }
  return;
}



/* c04401e4 FUN_c04401e4 */

/* Boundary evidence: original MIPS .pdata c04401e4..c04402d7. Semantic name remains unreviewed. */

void FUN_c04401e4(int *param_1,void *param_2)

{
  void *_Dst;
  void *_Src;
  uint _Size;
  int iVar1;
  undefined1 auStack_48 [16];
  CHAR aCStack_38 [16];
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  _Size = *(uint *)((int)param_2 + 0x20);
  iVar1 = *param_1;
  if (_Size < 0x11) {
    if ((*(uint *)((int)param_2 + 300) & 0x20) == 0) {
      FUN_c043e960((wchar_t *)(iVar1 + 0x408),auStack_48);
      FUN_c043e8ec(auStack_48,0x10,auStack_28);
      FUN_c043bdb4(*(int *)(iVar1 + 0xaac));
      FUN_c043fd2c((int)param_2);
      _Src = (void *)((int)param_2 + 0x10);
      _Dst = param_2;
    }
    else {
      iVar1 = FUN_c043caf8(iVar1,aCStack_38,0xe);
      aCStack_38[iVar1] = '\0';
      FUN_c043e824(aCStack_38);
      memcpy(param_2,auStack_48,_Size);
      _Dst = (void *)((int)param_2 + 0x10);
      _Src = param_2;
    }
    memcpy(_Dst,_Src,_Size);
    FUN_c043fc60((int)param_2);
  }
  FUN_c0449d30(local_18);
  return;
}



/* c04402d8 FUN_c04402d8 */

/* Boundary evidence: original MIPS .pdata c04402d8..c044035f. Semantic name remains unreviewed. */

void FUN_c04402d8(int *param_1,void *param_2)

{
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  FUN_c043e960((wchar_t *)(*param_1 + 0x408),auStack_38);
  FUN_c043e8ec(auStack_38,0x10,auStack_28);
  FUN_c043fde4(param_2);
  FUN_c043fea4(param_2);
  FUN_c043fc60((int)param_2);
  FUN_c0449d30(local_18);
  return;
}



/* c0440360 FUN_c0440360 */

/* Boundary evidence: original MIPS .pdata c0440360..c044043f. Semantic name remains unreviewed. */

undefined4 FUN_c0440360(int *param_1,undefined4 *param_2)

{
  undefined4 *_Dst;
  int iVar1;
  uint uVar2;
  uint _Size;
  undefined4 uVar3;
  void *_Src;
  
  iVar1 = *param_1;
  _Size = param_2[8];
  uVar3 = 0;
  if ((param_2[0x4c] & 2) == 0) {
    uVar2 = *(uint *)(iVar1 + 0xb24);
    _Src = (void *)(iVar1 + 0xb04);
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0xb00);
    _Src = (void *)(iVar1 + 0xae0);
  }
  if (uVar2 == 0) {
    uVar3 = 0x273;
  }
  else {
    _Dst = param_2;
    if (uVar2 <= _Size) {
      memset(param_2,0,_Size);
      _Dst = (undefined4 *)((_Size - uVar2) + (int)param_2);
      _Size = uVar2;
    }
    memcpy(_Dst,_Src,_Size);
    param_2[4] = *param_2;
    param_2[5] = param_2[1];
    param_2[6] = param_2[2];
    param_2[7] = param_2[3];
    FUN_c043fc60((int)param_2);
  }
  return uVar3;
}



/* c0440440 FUN_c0440440 */

/* Boundary evidence: original MIPS .pdata c0440440..c044056b. Semantic name remains unreviewed. */

int FUN_c0440440(int *param_1,undefined4 *param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = FUN_c04343d0(*param_1,0x5c);
  param_2[9] = iVar3;
  if (iVar3 == 0) {
    return -0x3fffff66;
  }
  if ((param_2[0x4b] & 0x20) == 0) {
    param_2[8] = 0x10;
  }
  else {
    param_2[8] = 8;
  }
  sVar2 = *(short *)(*(int *)(*param_1 + 0xaac) + 0x2e);
  if (sVar2 == -0x3ddd) {
    cVar1 = *(char *)(*(int *)(*param_1 + 0xaac) + 0x30);
    if (cVar1 == -0x80) {
      FUN_c04401e4(param_1,param_2);
    }
    else {
      if (cVar1 != -0x7f) {
        return 0;
      }
      FUN_c04402d8(param_1,param_2);
    }
  }
  else {
    if (sVar2 != -0x3dd9) {
      return 0;
    }
    iVar3 = FUN_c0440360(param_1,param_2);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  if (param_2[8] == 8) {
    *(undefined1 *)(param_2 + 4) = 0xd1;
    *(undefined1 *)((int)param_2 + 0x11) = 0x26;
    *(undefined1 *)((int)param_2 + 0x12) = 0x9e;
  }
  FUN_c0449828();
  return 0;
}



/* c044056c FUN_c044056c */

/* Boundary evidence: original MIPS .pdata c044056c..c04405bf. Semantic name remains unreviewed. */

void FUN_c044056c(int *param_1,LPVOID param_2)

{
  if (param_2 != (LPVOID)0x0) {
    if (*(LPVOID *)((int)param_2 + 0x24) != (LPVOID)0x0) {
      FUN_c0434420(*param_1,*(LPVOID *)((int)param_2 + 0x24));
      *(undefined4 *)((int)param_2 + 0x24) = 0;
    }
    FUN_c0434420(*param_1,param_2);
  }
  return;
}



/* c04405c0 FUN_c04405c0 */

/* Boundary evidence: original MIPS .pdata c04405c0..c044065b. Semantic name remains unreviewed. */

undefined4 * FUN_c04405c0(int *param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_c04343d0(*param_1,0x134);
  if (puVar1 != (undefined4 *)0x0) {
    if (*(int *)(*param_1 + 0x6c) != 0) {
      param_3 = param_3 | 1;
    }
    puVar1[0x4b] = param_2;
    puVar1[0x4c] = param_3;
    iVar2 = FUN_c0440440(param_1,puVar1);
    if (iVar2 != 0) {
      FUN_c0434420(*param_1,puVar1);
      puVar1 = (undefined4 *)0x0;
    }
  }
  return puVar1;
}



/* c044065c FUN_c044065c */

/* Boundary evidence: original MIPS .pdata c044065c..c04410d7. Semantic name remains unreviewed. */

ushort FUN_c044065c(byte *param_1,byte *param_2,uint *param_3,byte *param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  byte bVar11;
  int iVar12;
  byte *pbVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  byte *pbVar17;
  ushort local_38;
  
  uVar3 = 0;
  local_38 = 0;
  if ((0x1ffd < *(int *)(param_4 + 0x2004) + *param_3) || (*(int *)(param_4 + 0x2004) == 0)) {
    uVar3 = 0x4000;
    param_4[0x2004] = 0;
    param_4[0x2005] = 0;
    param_4[0x2006] = 0;
    param_4[0x2007] = 0;
    local_38 = 0x4000;
  }
  uVar10 = *param_3;
  uVar5 = 0;
  uVar16 = 0x10;
  pbVar9 = param_4 + *(int *)(param_4 + 0x2004);
  pbVar7 = param_1;
  pbVar17 = param_2;
joined_r0xc04406f4:
  do {
    if (param_1 + (uVar10 - 3) <= pbVar7) break;
    bVar11 = *pbVar7;
    uVar15 = (uint)bVar11;
    pbVar6 = pbVar7 + 1;
    *pbVar9 = bVar11;
    bVar1 = pbVar7[2];
    bVar2 = *pbVar6;
    pbVar8 = pbVar9 + 1;
    pbVar13 = param_4 + *(ushort *)
                         (param_4 +
                         (((uint)((*(int *)(&DAT_c0431f50 + (uint)bVar1 * 4) * 0x100 +
                                  *(int *)(&DAT_c0431f50 + (uint)bVar2 * 4)) * 0x100 +
                                 *(int *)(&DAT_c0431f50 + uVar15 * 4)) >> 0xc & 0xfff) + 0x1326) * 2
                         );
    if (pbVar13 != pbVar9) {
      *(short *)(param_4 +
                (((uint)((*(int *)(&DAT_c0431f50 + (uint)bVar1 * 4) * 0x100 +
                         *(int *)(&DAT_c0431f50 + (uint)bVar2 * 4)) * 0x100 +
                        *(int *)(&DAT_c0431f50 + uVar15 * 4)) >> 0xc & 0xfff) + 0x1326) * 2) =
           (short)pbVar8 - (short)param_4;
    }
    if (*(byte **)(param_4 + 0x2008) < pbVar8) {
      *(byte **)(param_4 + 0x2008) = pbVar8;
    }
    uVar3 = local_38;
    if (((((pbVar13 == param_4) || (pbVar13[-1] != uVar15)) || ((uint)*pbVar13 != (uint)bVar2)) ||
        (((uint)pbVar13[1] != (uint)bVar1 || (pbVar13 == pbVar9)))) ||
       ((pbVar13 == pbVar8 || (*(byte **)(param_4 + 0x2008) < pbVar13 + 1)))) {
      if ((bVar11 & 0x80) == 0) {
        uVar5 = uVar15 << (uVar16 - 8 & 0x1f) | uVar5;
LAB_c0440f78:
        bVar11 = (byte)(uVar5 >> 8);
LAB_c0440f80:
        uVar5 = uVar5 << 8;
        *pbVar17 = bVar11;
      }
      else {
        if ((int)uVar16 < 10) {
          uVar5 = uVar15 + 0x80 | uVar5;
LAB_c0440f4c:
          *pbVar17 = (byte)(uVar5 >> 8);
LAB_c0440f58:
          uVar16 = 0x10;
          pbVar17[1] = (byte)uVar5;
          pbVar17 = pbVar17 + 2;
          uVar5 = 0;
          pbVar9 = pbVar8;
          pbVar7 = pbVar6;
          goto joined_r0xc04406f4;
        }
        uVar5 = uVar15 + 0x80 << (uVar16 - 9 & 0x1f) | uVar5;
        *pbVar17 = (byte)(uVar5 >> 8);
LAB_c0440b14:
        uVar16 = uVar16 - 1;
        uVar5 = uVar5 << 8;
      }
LAB_c0440f84:
      pbVar17 = pbVar17 + 1;
      pbVar9 = pbVar8;
      pbVar7 = pbVar6;
      goto joined_r0xc04406f4;
    }
    *pbVar8 = bVar2;
    pbVar9[2] = bVar1;
    uVar15 = (int)pbVar8 - (int)pbVar13 & 0x1fff;
    pbVar8 = pbVar9 + 3;
    pbVar6 = pbVar7 + 3;
    iVar4 = 3;
    for (pbVar13 = pbVar13 + 2;
        ((*pbVar13 == *pbVar6 && (pbVar6 < param_1 + (uVar10 - 1))) &&
        (pbVar13 <= *(byte **)(param_4 + 0x2008))); pbVar13 = pbVar13 + 1) {
      *pbVar8 = *pbVar6;
      pbVar8 = pbVar8 + 1;
      pbVar6 = pbVar6 + 1;
      iVar4 = iVar4 + 1;
    }
    if (uVar15 < 0x140) {
      if (uVar15 < 0x40) {
        uVar15 = uVar15 + 0x3c0;
        if ((int)uVar16 < 0xb) {
          uVar14 = uVar16 - 2;
          goto LAB_c0440904;
        }
        uVar16 = uVar16 - 10;
        uVar15 = uVar15 << (uVar16 & 0x1f);
LAB_c04408d4:
        uVar15 = uVar15 | uVar5;
        uVar14 = uVar16 + 8;
      }
      else {
        uVar15 = uVar15 + 0xdc0;
        if (0xc < (int)uVar16) {
          uVar16 = uVar16 - 0xc;
          uVar15 = uVar15 << (uVar16 & 0x1f);
          goto LAB_c04408d4;
        }
        uVar14 = uVar16 - 4;
LAB_c0440904:
        uVar5 = ((int)uVar15 >> 8) << (uVar14 & 0x1f) | uVar5;
        if ((int)uVar14 < 9) {
          *pbVar17 = (byte)(uVar5 >> 8);
          pbVar17 = pbVar17 + 1;
          uVar5 = uVar5 << 8;
          uVar14 = uVar14 + 8;
        }
        uVar15 = (uVar15 & 0xff) << (uVar14 - 8 & 0x1f) | uVar5;
      }
      *pbVar17 = (byte)(uVar15 >> 8);
      pbVar17 = pbVar17 + 1;
    }
    else {
      uVar5 = ((int)(uVar15 + 0xbec0) >> 8) << (uVar16 - 8 & 0x1f) | uVar5;
      uVar15 = uVar15 - 0x140 << (uVar16 - 8 & 0x1f) | uVar5 << 8;
      *pbVar17 = (byte)(uVar5 >> 8);
      pbVar17[1] = (byte)(uVar15 >> 8);
      pbVar17 = pbVar17 + 2;
      uVar14 = uVar16;
    }
    uVar5 = uVar15 << 8;
    bVar11 = (byte)uVar15;
    pbVar9 = pbVar8;
    pbVar7 = pbVar6;
    if (iVar4 != 3) {
      if (iVar4 < 4) {
LAB_c04409dc:
        if (iVar4 < 0x40) {
          uVar16 = uVar14 - 4;
          uVar5 = 0xf << (uVar16 & 0x1f) | uVar5;
          if ((int)uVar16 < 9) {
            *pbVar17 = (byte)(uVar5 >> 8);
            pbVar17 = pbVar17 + 1;
            uVar16 = uVar14 + 4;
            uVar5 = uVar5 << 8;
          }
          uVar16 = uVar16 - 6;
          iVar4 = iVar4 + -0x20;
        }
        else {
          if (0x7f < iVar4) {
            if (iVar4 < 0x100) {
              uVar16 = uVar14 - 6;
              uVar5 = 0x3f << (uVar16 & 0x1f) | uVar5;
              if ((int)uVar16 < 9) {
                *pbVar17 = (byte)(uVar5 >> 8);
                pbVar17 = pbVar17 + 1;
                uVar16 = uVar14 + 2;
                uVar5 = uVar5 << 8;
              }
              uVar5 = iVar4 + -0x80 << (uVar16 - 8 & 0x1f) | uVar5;
              goto LAB_c0440f78;
            }
            if (iVar4 < 0x200) {
              uVar16 = uVar14 - 7;
              uVar5 = 0x7f << (uVar16 & 0x1f) | uVar5;
              if ((int)uVar16 < 9) {
                *pbVar17 = (byte)(uVar5 >> 8);
                pbVar17 = pbVar17 + 1;
                uVar16 = uVar14 + 1;
                uVar5 = uVar5 << 8;
              }
              if ((int)uVar16 < 10) {
                uVar5 = iVar4 - 0x100U | uVar5;
                goto LAB_c0440f4c;
              }
              uVar5 = iVar4 - 0x100U << (uVar16 - 9 & 0x1f) | uVar5;
              *pbVar17 = (byte)(uVar5 >> 8);
              goto LAB_c0440b14;
            }
            if (iVar4 < 0x400) {
              uVar5 = 0xff << (uVar14 - 8 & 0x1f) | uVar5;
              *pbVar17 = (byte)(uVar5 >> 8);
              pbVar17 = pbVar17 + 1;
              uVar5 = uVar5 << 8;
              uVar15 = iVar4 - 0x200;
              if ((int)uVar14 < 0xb) {
                uVar16 = uVar14 - 2;
                uVar5 = ((int)uVar15 >> 8) << (uVar16 & 0x1f) | uVar5;
                goto LAB_c0440ea8;
              }
              uVar5 = uVar15 << (uVar14 - 10 & 0x1f) | uVar5;
              uVar16 = uVar14 - 2;
LAB_c0440ed8:
              *pbVar17 = (byte)(uVar5 >> 8);
              pbVar17 = pbVar17 + 1;
            }
            else {
              if (0x7ff < iVar4) {
                if (iVar4 < 0x1000) {
                  if ((int)uVar14 < 0xb) {
                    uVar16 = uVar14 - 2;
                    uVar5 = 3 << (uVar16 & 0x1f) | uVar5;
                    if ((int)uVar16 < 9) {
                      *pbVar17 = (byte)(uVar5 >> 8);
                      pbVar17 = pbVar17 + 1;
                      uVar16 = uVar14 + 6;
                      uVar5 = uVar5 << 8;
                    }
                    uVar5 = 0xff << (uVar16 - 8 & 0x1f) | uVar5;
                    *pbVar17 = (byte)(uVar5 >> 8);
                  }
                  else {
                    uVar5 = 0x3ff << (uVar14 - 10 & 0x1f) | uVar5;
                    *pbVar17 = (byte)(uVar5 >> 8);
                    uVar16 = uVar14 - 2;
                  }
                  pbVar17 = pbVar17 + 1;
                  uVar15 = iVar4 - 0x800;
                  if (0xc < (int)uVar16) {
                    uVar16 = uVar16 - 0xc;
                    uVar5 = uVar15 << (uVar16 & 0x1f) | uVar5 << 8;
LAB_c0440cf0:
                    uVar16 = uVar16 + 8;
                    goto LAB_c0440ed8;
                  }
                  uVar16 = uVar16 - 4;
                  uVar5 = ((int)uVar15 >> 8) << (uVar16 & 0x1f) | uVar5 << 8;
                }
                else {
                  if (iVar4 < 0x2000) {
                    if ((int)uVar14 < 0xc) {
                      if (uVar14 == 0xb) {
                        *pbVar17 = bVar11 | 7;
                        pbVar17[1] = 0xff;
                        uVar14 = 0x10;
                        pbVar17 = pbVar17 + 2;
                        uVar5 = 0;
                      }
                      else {
                        iVar12 = 0x7ff >> (0xb - uVar14 & 0x1f);
                        *pbVar17 = (byte)((uint)iVar12 >> 8) | bVar11;
                        uVar14 = 0x10 - (0xb - uVar14);
                        pbVar17[1] = (byte)iVar12;
                        pbVar17 = pbVar17 + 2;
                        uVar5 = 0x7ff << (uVar14 & 0x1f);
                      }
                    }
                    else {
                      uVar5 = 0x7ff << (uVar14 - 0xb & 0x1f) | uVar5;
                      *pbVar17 = (byte)(uVar5 >> 8);
                      pbVar17 = pbVar17 + 1;
                      uVar14 = uVar14 - 3;
                      uVar5 = uVar5 << 8;
                    }
                    uVar15 = iVar4 - 0x1000;
                    if (0xd < (int)uVar14) {
                      uVar16 = uVar14 - 0xd;
                      uVar15 = uVar15 << (uVar16 & 0x1f);
                      goto LAB_c0440bf8;
                    }
                    uVar16 = uVar14 - 5;
                    uVar5 = ((int)uVar15 >> 8) << (uVar16 & 0x1f) | uVar5;
                    if ((int)uVar16 < 9) {
                      *pbVar17 = (byte)(uVar5 >> 8);
                      pbVar17 = pbVar17 + 1;
                      uVar16 = uVar14 + 3;
                      uVar5 = uVar5 << 8;
                    }
                    uVar5 = (uVar15 & 0xff) << (uVar16 - 8 & 0x1f) | uVar5;
                    *pbVar17 = (byte)(uVar5 >> 8);
                    pbVar17 = pbVar17 + 1;
                    goto LAB_c0440ee4;
                  }
                  if ((int)uVar14 < 0xd) {
                    uVar16 = uVar14 - 4;
                    uVar5 = 0xf << (uVar16 & 0x1f) | uVar5;
                    if ((int)uVar16 < 9) {
                      *pbVar17 = (byte)(uVar5 >> 8);
                      pbVar17 = pbVar17 + 1;
                      uVar16 = uVar14 + 4;
                      uVar5 = uVar5 << 8;
                    }
                    uVar5 = 0xff << (uVar16 - 8 & 0x1f) | uVar5;
                  }
                  else {
                    uVar5 = 0xfff << (uVar14 - 0xc & 0x1f) | uVar5;
                    uVar16 = uVar14 - 4;
                  }
                  *pbVar17 = (byte)(uVar5 >> 8);
                  pbVar17 = pbVar17 + 1;
                  uVar15 = iVar4 - 0x2000;
                  if (0xe < (int)uVar16) {
                    uVar16 = uVar16 - 0xe;
                    uVar5 = uVar15 << (uVar16 & 0x1f) | uVar5 << 8;
                    goto LAB_c0440cf0;
                  }
                  uVar16 = uVar16 - 6;
                  uVar5 = ((int)uVar15 >> 8) << (uVar16 & 0x1f) | uVar5 << 8;
                }
LAB_c0440ea8:
                if ((int)uVar16 < 9) {
                  *pbVar17 = (byte)(uVar5 >> 8);
                  pbVar17 = pbVar17 + 1;
                  uVar16 = uVar16 + 8;
                  uVar5 = uVar5 << 8;
                }
                uVar5 = (uVar15 & 0xff) << (uVar16 - 8 & 0x1f) | uVar5;
                goto LAB_c0440ed8;
              }
              if ((int)uVar14 < 10) {
                *pbVar17 = bVar11 | 1;
                pbVar17[1] = 0xff;
                iVar12 = 0x10;
                pbVar17 = pbVar17 + 2;
                uVar5 = 0;
              }
              else {
                uVar5 = 0x1ff << (uVar14 - 9 & 0x1f) | uVar5;
                *pbVar17 = (byte)(uVar5 >> 8);
                pbVar17 = pbVar17 + 1;
                iVar12 = uVar14 - 1;
                uVar5 = uVar5 << 8;
              }
              uVar15 = iVar4 - 0x400;
              if (iVar12 < 0xc) {
                if (iVar12 == 0xb) {
                  uVar5 = uVar15 | uVar5;
                  *pbVar17 = (byte)(uVar5 >> 8);
                  goto LAB_c0440f58;
                }
                iVar4 = (int)uVar15 >> (0xbU - iVar12 & 0x1f);
                uVar16 = 0x10 - (0xbU - iVar12);
                *pbVar17 = (byte)((uint)iVar4 >> 8) | (byte)(uVar5 >> 8);
                pbVar17[1] = (byte)iVar4;
                pbVar17 = pbVar17 + 2;
                uVar5 = uVar15 << (uVar16 & 0x1f);
                goto joined_r0xc04406f4;
              }
              uVar16 = iVar12 - 0xb;
              uVar15 = uVar15 << (uVar16 & 0x1f);
LAB_c0440bf8:
              uVar5 = uVar15 | uVar5;
              *pbVar17 = (byte)(uVar5 >> 8);
              pbVar17 = pbVar17 + 1;
              uVar16 = uVar16 + 8;
            }
LAB_c0440ee4:
            uVar5 = uVar5 << 8;
            goto joined_r0xc04406f4;
          }
          uVar16 = uVar14 - 5;
          uVar5 = 0x1f << (uVar16 & 0x1f) | uVar5;
          if ((int)uVar16 < 9) {
            *pbVar17 = (byte)(uVar5 >> 8);
            pbVar17 = pbVar17 + 1;
            uVar16 = uVar14 + 3;
            uVar5 = uVar5 << 8;
          }
          uVar16 = uVar16 - 7;
          iVar4 = iVar4 + -0x40;
        }
        uVar5 = iVar4 << (uVar16 & 0x1f) | uVar5;
      }
      else {
        if (iVar4 < 8) {
          uVar16 = uVar14 - 4;
          iVar4 = iVar4 + 4;
        }
        else {
          if (0xf < iVar4) {
            if (0x1f < iVar4) goto LAB_c04409dc;
            uVar5 = iVar4 + 0xd0 << (uVar14 - 8 & 0x1f) | uVar5;
            bVar11 = (byte)(uVar5 >> 8);
            uVar16 = uVar14;
            goto LAB_c0440f80;
          }
          uVar16 = uVar14 - 6;
          iVar4 = iVar4 + 0x28;
        }
        uVar5 = iVar4 << (uVar16 & 0x1f) | uVar5;
      }
      if ((int)uVar16 < 9) {
        *pbVar17 = (byte)(uVar5 >> 8);
        uVar16 = uVar16 + 8;
        uVar5 = uVar5 << 8;
        goto LAB_c0440f84;
      }
      goto joined_r0xc04406f4;
    }
    if ((int)uVar14 < 10) {
      *pbVar17 = bVar11;
      uVar5 = 0;
      uVar16 = 0x10;
      goto LAB_c0440f84;
    }
    uVar16 = uVar14 - 1;
  } while( true );
LAB_c0441034:
  if (param_1 + (uVar10 - 1) < pbVar7) {
    if (uVar16 != 0x10) {
      *pbVar17 = (byte)(uVar5 >> 8);
      pbVar17 = pbVar17 + 1;
    }
    if (*param_3 < (uint)((int)pbVar17 - (int)param_2)) {
      memset(param_4,0,0x2001);
      memset(param_4 + 0x264c,0,0x2000);
      param_4[0x2004] = 1;
      param_4[0x2005] = 0x20;
      param_4[0x2006] = 0;
      param_4[0x2007] = 0;
      uVar3 = 0x8000;
    }
    else {
      *param_3 = (int)pbVar17 - (int)param_2;
      uVar3 = uVar3 | 0x2000;
      *(int *)(param_4 + 0x2004) = (int)pbVar9 - (int)param_4;
    }
    return uVar3;
  }
  bVar11 = *pbVar7;
  if ((bVar11 & 0x80) == 0) {
    uVar5 = (uint)bVar11 << (uVar16 - 8 & 0x1f) | uVar5;
    bVar11 = (byte)(uVar5 >> 8);
LAB_c044101c:
    uVar5 = uVar5 << 8;
    *pbVar17 = bVar11;
    pbVar17 = pbVar17 + 1;
  }
  else {
    uVar15 = bVar11 + 0x80;
    if (9 < (int)uVar16) {
      uVar5 = uVar15 << (uVar16 - 9 & 0x1f) | uVar5;
      bVar11 = (byte)(uVar5 >> 8);
      uVar16 = uVar16 - 1;
      goto LAB_c044101c;
    }
    uVar15 = uVar15 | uVar5;
    *pbVar17 = (byte)(uVar15 >> 8);
    pbVar17[1] = (byte)uVar15;
    pbVar17 = pbVar17 + 2;
    uVar5 = 0;
    uVar16 = 0x10;
  }
  bVar11 = *pbVar7;
  pbVar7 = pbVar7 + 1;
  *pbVar9 = bVar11;
  pbVar9 = pbVar9 + 1;
  goto LAB_c0441034;
}



/* c04410d8 FUN_c04410d8 */

/* Boundary evidence: original MIPS .pdata c04410d8..c044111f. Semantic name remains unreviewed. */

void FUN_c04410d8(void *param_1)

{
  *(undefined4 *)((int)param_1 + 0x2004) = 0;
  *(undefined4 *)((int)param_1 + 0x2008) = 0;
  memset((void *)((int)param_1 + 0x264c),0,0x2000);
  memset(param_1,0,0x2001);
  return;
}



/* c0441120 FUN_c0441120 */

/* Boundary evidence: original MIPS .pdata c0441120..c0441143. Semantic name remains unreviewed. */

void FUN_c0441120(void *param_1)

{
  *(void **)((int)param_1 + 0x2004) = param_1;
  memset(param_1,0,0x2001);
  return;
}



/* c0441144 FUN_c0441144 */

/* Boundary evidence: original MIPS .pdata c0441144..c04418db. Semantic name remains unreviewed. */

undefined4
FUN_c0441144(byte *param_1,int param_2,int param_3,undefined4 *param_4,int *param_5,byte *param_6)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  
  pbVar8 = param_1 + 1;
  uVar4 = 0;
  pbVar3 = param_1 + param_2;
  uVar10 = 0x10;
  uVar9 = (uint)*param_1 * 0x100 + (uint)*pbVar8;
  if (param_3 == 0) {
    pbVar1 = *(byte **)(param_6 + 0x2004);
  }
  else {
    *(byte **)(param_6 + 0x2004) = param_6;
    pbVar1 = param_6;
  }
  pbVar12 = pbVar1;
  pbVar2 = pbVar1;
  if (pbVar8 < pbVar3) {
    do {
      uVar11 = uVar10 - 3;
      uVar5 = (int)uVar9 >> (uVar11 & 0x1f);
      if ((int)uVar11 < 9) {
        pbVar8 = pbVar8 + 1;
        uVar11 = uVar10 + 5;
        uVar9 = uVar9 << 8 | (uint)*pbVar8;
      }
      uVar10 = uVar11;
      switch(uVar5 & 7) {
      case 0:
        uVar10 = uVar11 - 5;
        bVar6 = (byte)((int)uVar9 >> (uVar10 & 0x1f)) & 0x1f;
        if ((int)uVar10 < 9) {
          pbVar8 = pbVar8 + 1;
          uVar10 = uVar11 + 3;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
        }
        break;
      case 1:
        uVar10 = uVar11 - 5;
        iVar7 = (int)uVar9 >> (uVar10 & 0x1f);
        if ((int)uVar10 < 9) {
          pbVar8 = pbVar8 + 1;
          uVar10 = uVar11 + 3;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
        }
        bVar6 = ((byte)iVar7 & 0x1f) + 0x20;
        break;
      case 2:
        uVar10 = uVar11 - 5;
        iVar7 = (int)uVar9 >> (uVar10 & 0x1f);
        if ((int)uVar10 < 9) {
          pbVar8 = pbVar8 + 1;
          uVar10 = uVar11 + 3;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
        }
        bVar6 = ((byte)iVar7 & 0x1f) + 0x40;
        break;
      case 3:
        uVar10 = uVar11 - 5;
        iVar7 = (int)uVar9 >> (uVar10 & 0x1f);
        if ((int)uVar10 < 9) {
          pbVar8 = pbVar8 + 1;
          uVar10 = uVar11 + 3;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
        }
        bVar6 = ((byte)iVar7 & 0x1f) + 0x60;
        break;
      case 4:
        uVar10 = uVar11 - 6;
        iVar7 = (int)uVar9 >> (uVar10 & 0x1f);
        if ((int)uVar10 < 9) {
          pbVar8 = pbVar8 + 1;
          uVar10 = uVar11 + 2;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
        }
        bVar6 = ((byte)iVar7 & 0x3f) + 0x80;
        break;
      case 5:
        uVar10 = uVar11 - 6;
        iVar7 = (int)uVar9 >> (uVar10 & 0x1f);
        if ((int)uVar10 < 9) {
          pbVar8 = pbVar8 + 1;
          uVar10 = uVar11 + 2;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
        }
        bVar6 = ((byte)iVar7 & 0x3f) - 0x40;
        break;
      case 6:
        if ((int)uVar11 < 0xe) {
          uVar10 = uVar11 - 5;
          uVar4 = (int)uVar9 >> (uVar10 & 0x1f);
          if ((int)uVar10 < 9) {
            pbVar8 = pbVar8 + 1;
            uVar10 = uVar11 + 3;
            uVar9 = uVar9 << 8 | (uint)*pbVar8;
          }
          uVar5 = (int)uVar9 >> (uVar10 - 8 & 0x1f);
          pbVar8 = pbVar8 + 1;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
          uVar4 = (uVar4 & 0x1f) * 0x100 + (uVar5 & 0xff);
        }
        else {
          pbVar8 = pbVar8 + 1;
          uVar10 = uVar11 - 5;
          uVar4 = (int)uVar9 >> (uVar11 - 0xd & 0x1f) & 0x1fff;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
        }
        uVar4 = uVar4 + 0x140;
      default:
switchD_c04411f4_default:
        uVar10 = uVar10 - 1;
        uVar5 = (int)uVar9 >> (uVar10 & 0x1f);
        if ((int)uVar10 < 9) {
          pbVar8 = pbVar8 + 1;
          uVar10 = 0x10;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
        }
        if ((uVar5 & 1) == 0) {
          iVar7 = 3;
        }
        else {
          uVar5 = uVar10 - 1;
          uVar10 = (int)uVar9 >> (uVar5 & 0x1f);
          pbVar2 = pbVar8;
          if ((int)uVar5 < 9) {
            pbVar2 = pbVar8 + 1;
            uVar5 = 0x10;
            uVar9 = uVar9 << 8 | (uint)*pbVar2;
          }
          if ((uVar10 & 1) == 0) {
            uVar10 = uVar5 - 2;
            uVar11 = (int)uVar9 >> (uVar10 & 0x1f);
            pbVar8 = pbVar2;
            if ((int)uVar10 < 9) {
              pbVar8 = pbVar2 + 1;
              uVar10 = uVar5 + 6;
              uVar9 = uVar9 << 8 | (uint)*pbVar8;
            }
            iVar7 = (uVar11 & 3) + 4;
          }
          else {
            uVar5 = uVar5 - 1;
            uVar10 = (int)uVar9 >> (uVar5 & 0x1f);
            if ((int)uVar5 < 9) {
              pbVar2 = pbVar2 + 1;
              uVar5 = 0x10;
              uVar9 = uVar9 << 8 | (uint)*pbVar2;
            }
            if ((uVar10 & 1) == 0) {
              uVar10 = uVar5 - 3;
              uVar11 = (int)uVar9 >> (uVar10 & 0x1f);
              pbVar8 = pbVar2;
              if ((int)uVar10 < 9) {
                pbVar8 = pbVar2 + 1;
                uVar10 = uVar5 + 5;
                uVar9 = uVar9 << 8 | (uint)*pbVar8;
              }
              iVar7 = (uVar11 & 7) + 8;
            }
            else {
              uVar5 = uVar5 - 1;
              uVar10 = (int)uVar9 >> (uVar5 & 0x1f);
              if ((int)uVar5 < 9) {
                pbVar2 = pbVar2 + 1;
                uVar5 = 0x10;
                uVar9 = uVar9 << 8 | (uint)*pbVar2;
              }
              if ((uVar10 & 1) == 0) {
                uVar10 = uVar5 - 4;
                uVar11 = (int)uVar9 >> (uVar10 & 0x1f);
                pbVar8 = pbVar2;
                if ((int)uVar10 < 9) {
                  pbVar8 = pbVar2 + 1;
                  uVar10 = uVar5 + 4;
                  uVar9 = uVar9 << 8 | (uint)*pbVar8;
                }
                iVar7 = (uVar11 & 0xf) + 0x10;
              }
              else {
                uVar5 = uVar5 - 1;
                uVar10 = (int)uVar9 >> (uVar5 & 0x1f);
                if ((int)uVar5 < 9) {
                  pbVar2 = pbVar2 + 1;
                  uVar5 = 0x10;
                  uVar9 = uVar9 << 8 | (uint)*pbVar2;
                }
                if ((uVar10 & 1) == 0) {
                  uVar10 = uVar5 - 5;
                  uVar11 = (int)uVar9 >> (uVar10 & 0x1f);
                  pbVar8 = pbVar2;
                  if ((int)uVar10 < 9) {
                    pbVar8 = pbVar2 + 1;
                    uVar10 = uVar5 + 3;
                    uVar9 = uVar9 << 8 | (uint)*pbVar8;
                  }
                  iVar7 = (uVar11 & 0x1f) + 0x20;
                }
                else {
                  uVar5 = uVar5 - 1;
                  uVar10 = (int)uVar9 >> (uVar5 & 0x1f);
                  if ((int)uVar5 < 9) {
                    pbVar2 = pbVar2 + 1;
                    uVar5 = 0x10;
                    uVar9 = uVar9 << 8 | (uint)*pbVar2;
                  }
                  if ((uVar10 & 1) == 0) {
                    uVar10 = uVar5 - 6;
                    uVar11 = (int)uVar9 >> (uVar10 & 0x1f);
                    pbVar8 = pbVar2;
                    if ((int)uVar10 < 9) {
                      pbVar8 = pbVar2 + 1;
                      uVar10 = uVar5 + 2;
                      uVar9 = uVar9 << 8 | (uint)*pbVar8;
                    }
                    iVar7 = (uVar11 & 0x3f) + 0x40;
                  }
                  else {
                    uVar5 = uVar5 - 1;
                    uVar10 = (int)uVar9 >> (uVar5 & 0x1f);
                    if ((int)uVar5 < 9) {
                      pbVar2 = pbVar2 + 1;
                      uVar5 = 0x10;
                      uVar9 = uVar9 << 8 | (uint)*pbVar2;
                    }
                    if ((uVar10 & 1) == 0) {
                      uVar10 = uVar5 - 7;
                      uVar11 = (int)uVar9 >> (uVar10 & 0x1f);
                      pbVar8 = pbVar2;
                      if ((int)uVar10 < 9) {
                        pbVar8 = pbVar2 + 1;
                        uVar10 = uVar5 + 1;
                        uVar9 = uVar9 << 8 | (uint)*pbVar8;
                      }
                      iVar7 = (uVar11 & 0x7f) + 0x80;
                    }
                    else {
                      uVar10 = uVar5 - 1;
                      uVar5 = (int)uVar9 >> (uVar10 & 0x1f);
                      if ((int)uVar10 < 9) {
                        pbVar2 = pbVar2 + 1;
                        uVar10 = 0x10;
                        uVar9 = uVar9 << 8 | (uint)*pbVar2;
                      }
                      if ((uVar5 & 1) == 0) {
                        pbVar8 = pbVar2 + 1;
                        uVar5 = (int)uVar9 >> (uVar10 - 8 & 0x1f);
                        uVar9 = uVar9 << 8 | (uint)*pbVar8;
                        iVar7 = (uVar5 & 0xff) + 0x100;
                      }
                      else {
                        uVar5 = uVar10 - 1;
                        uVar10 = (int)uVar9 >> (uVar5 & 0x1f);
                        if ((int)uVar5 < 9) {
                          pbVar2 = pbVar2 + 1;
                          uVar5 = 0x10;
                          uVar9 = uVar9 << 8 | (uint)*pbVar2;
                        }
                        if ((uVar10 & 1) == 0) {
                          pbVar8 = pbVar2 + 1;
                          uVar11 = (int)uVar9 >> (uVar5 - 9 & 0x1f);
                          uVar10 = uVar5 - 1;
                          uVar9 = uVar9 << 8 | (uint)*pbVar8;
                          if ((int)uVar10 < 9) {
                            pbVar8 = pbVar2 + 2;
                            uVar10 = uVar5 + 7;
                            uVar9 = uVar9 << 8 | (uint)*pbVar8;
                          }
                          iVar7 = (uVar11 & 0x1ff) + 0x200;
                        }
                        else {
                          uVar5 = uVar5 - 1;
                          uVar10 = (int)uVar9 >> (uVar5 & 0x1f);
                          if ((int)uVar5 < 9) {
                            pbVar2 = pbVar2 + 1;
                            uVar5 = 0x10;
                            uVar9 = uVar9 << 8 | (uint)*pbVar2;
                          }
                          if ((uVar10 & 1) != 0) {
                            return 0;
                          }
                          if ((int)uVar5 < 0xb) {
                            uVar10 = uVar5 - 2;
                            uVar11 = (int)uVar9 >> (uVar10 & 0x1f);
                            if ((int)uVar10 < 9) {
                              pbVar2 = pbVar2 + 1;
                              uVar10 = uVar5 + 6;
                              uVar9 = uVar9 << 8 | (uint)*pbVar2;
                            }
                            uVar5 = (int)uVar9 >> (uVar10 - 8 & 0x1f);
                            pbVar8 = pbVar2 + 1;
                            uVar9 = uVar9 << 8 | (uint)*pbVar8;
                            uVar5 = (uVar11 & 3) * 0x100 + (uVar5 & 0xff);
                          }
                          else {
                            pbVar8 = pbVar2 + 1;
                            uVar10 = uVar5 - 2;
                            uVar5 = (int)uVar9 >> (uVar5 - 10 & 0x1f) & 0x3ff;
                            uVar9 = uVar9 << 8 | (uint)*pbVar8;
                          }
                          iVar7 = uVar5 + 0x400;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        pbVar2 = pbVar12 + iVar7;
        pbVar13 = param_6 + ((uint)(pbVar12 + (-(int)param_6 - uVar4)) & 0x1fff);
        if (param_6 + 0x2000 <= pbVar2) {
          return 0;
        }
        *pbVar12 = *pbVar13;
        pbVar14 = pbVar13 + 2;
        pbVar12[1] = pbVar13[1];
        pbVar12 = pbVar12 + 2;
        for (iVar7 = iVar7 + -2; iVar7 != 0; iVar7 = iVar7 + -1) {
          bVar6 = *pbVar14;
          pbVar14 = pbVar14 + 1;
          *pbVar12 = bVar6;
          pbVar12 = pbVar12 + 1;
        }
        goto LAB_c0441878;
      case 7:
        uVar11 = uVar11 - 1;
        uVar10 = (int)uVar9 >> (uVar11 & 0x1f);
        if ((int)uVar11 < 9) {
          pbVar8 = pbVar8 + 1;
          uVar11 = 0x10;
          uVar9 = uVar9 << 8 | (uint)*pbVar8;
        }
        if ((uVar10 & 1) == 0) {
          uVar4 = ((int)uVar9 >> (uVar11 - 8 & 0x1f) & 0xffU) + 0x40;
        }
        else {
          uVar10 = uVar11 - 6;
          uVar4 = (int)uVar9 >> (uVar10 & 0x1f) & 0x3f;
          if (8 < (int)uVar10) goto switchD_c04411f4_default;
          uVar11 = uVar11 + 2;
        }
        pbVar8 = pbVar8 + 1;
        uVar9 = uVar9 << 8 | (uint)*pbVar8;
        uVar10 = uVar11;
        goto switchD_c04411f4_default;
      }
      *pbVar12 = bVar6;
      pbVar2 = pbVar12 + 1;
LAB_c0441878:
      pbVar12 = pbVar2;
    } while (pbVar8 < pbVar3);
    if (uVar10 != 0x10) goto LAB_c04418a0;
  }
  if (pbVar8 == pbVar3) {
    *pbVar2 = pbVar8[-1];
    pbVar2 = pbVar2 + 1;
  }
LAB_c04418a0:
  *param_5 = (int)pbVar2 - (int)pbVar1;
  *param_4 = *(undefined4 *)(param_6 + 0x2004);
  *(byte **)(param_6 + 0x2004) = pbVar2;
  return 1;
}



/* c04418dc FUN_c04418dc */

/* Boundary evidence: original MIPS .pdata c04418dc..c04419f7. Semantic name remains unreviewed. */

undefined4 FUN_c04418dc(undefined4 param_1,void *param_2,uint param_3)

{
  undefined4 *hMem;
  int iVar1;
  uint uBytes;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  if (((int)((ulonglong)param_3 * 2 >> 0x20) == 0) &&
     (uBytes = (int)((ulonglong)param_3 * 2) + 0x10, 0xf < uBytes)) {
    hMem = LocalAlloc(0x40,uBytes);
    if (hMem != (undefined4 *)0x0) {
      *hMem = 0;
      hMem[1] = param_1;
      hMem[2] = param_3;
      iVar1 = FUN_c0432630(0x51,60000);
      if ((iVar1 == 0) &&
         (iVar1 = FUN_c04326ec(L"netui.dll",L"GetNetStringExt",hMem,uBytes,hMem,uBytes,local_20),
         iVar1 != 0)) {
        memcpy(param_2,hMem + 3,hMem[2] << 1);
      }
      uVar2 = *hMem;
      LocalFree(hMem);
      return uVar2;
    }
  }
  else {
    SetLastError(0x57);
  }
  return 0;
}



/* c04419f8 FUN_c04419f8 */

/* Boundary evidence: original MIPS .pdata c04419f8..c0441b73. Semantic name remains unreviewed. */

undefined4 FUN_c04419f8(int param_1,int param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  short *psVar4;
  short *psVar5;
  wchar_t *_Str1;
  undefined4 local_2a0;
  undefined4 local_29c;
  wchar_t *local_298;
  int local_294;
  wchar_t *local_290;
  int local_28c;
  wchar_t *local_288;
  int local_284;
  undefined4 local_280;
  wchar_t awStack_278 [28];
  wchar_t awStack_240 [274];
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  wcscpy(awStack_278,L"PPP_");
  wcscat(awStack_278,(wchar_t *)(param_1 + 4));
  psVar4 = (short *)&DAT_c0431cb0;
  psVar5 = psVar4;
  if (*(short *)(param_1 + 0x596) != 0) {
    psVar4 = (short *)&DAT_c0431cb4;
    psVar5 = (short *)(param_1 + 0x596);
  }
  StringCchPrintfW(awStack_240,0x111,L"%s%s%s",psVar5,psVar4,param_1 + 0x192);
  local_290 = awStack_278;
  local_2a0 = 1;
  local_29c = 0x10006;
  sVar1 = wcslen(awStack_278);
  local_28c = sVar1 + 1;
  local_298 = awStack_240;
  local_280 = 1;
  sVar1 = wcslen(awStack_240);
  local_294 = sVar1 + 1;
  if (param_2 == 0) {
    _Str1 = (wchar_t *)(param_1 + 0x394);
    iVar2 = wcscmp(_Str1,u__________________c044d7b0);
    if (iVar2 == 0) {
      sVar1 = wcslen(awStack_278);
      uVar3 = CredUpdate(awStack_278,sVar1 + 1,0x10006,&local_2a0,0x280);
      goto LAB_c0441b48;
    }
    local_288 = _Str1;
    sVar1 = wcslen(_Str1);
    local_284 = (sVar1 + 1) * 2;
  }
  else {
    local_288 = (wchar_t *)0x0;
    local_284 = 0;
  }
  uVar3 = CredWrite(&local_2a0,0);
LAB_c0441b48:
  FUN_c0449d30(local_1c);
  return uVar3;
}



/* c0441b74 FUN_c0441b74 */

/* Boundary evidence: original MIPS .pdata c0441b74..c0441d5b. Semantic name remains unreviewed. */

int FUN_c0441b74(int param_1,int param_2,undefined4 *param_3)

{
  size_t sVar1;
  int iVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  wchar_t *_Str;
  int local_60 [2];
  wchar_t awStack_58 [26];
  uint local_24;
  
  local_24 = DAT_c044d82c;
  local_60[0] = 0;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  wcscpy(awStack_58,L"PPP_");
  wcscat(awStack_58,(wchar_t *)(param_1 + 4));
  sVar1 = wcslen(awStack_58);
  iVar2 = CredRead(awStack_58,sVar1 + 1,0x10006,0x1800,local_60);
  iVar5 = local_60[0];
  if (iVar2 == 0) {
    if (local_60[0] == 0) {
      iVar2 = 0x490;
    }
    else {
      if (param_2 == 0) {
        memset((void *)(param_1 + 0x596),0,0x20);
        _Str = *(wchar_t **)(iVar5 + 8);
        pwVar3 = wcschr(_Str,L'\\');
        if (pwVar3 != (wchar_t *)0x0) {
          iVar5 = (int)pwVar3 - (int)_Str >> 1;
          if (iVar5 < 0x10) {
            memcpy((void *)(param_1 + 0x596),_Str,iVar5 << 1);
          }
          else {
            iVar2 = 0x7a;
          }
          _Str = pwVar3 + 1;
        }
        sVar1 = wcslen(_Str);
        if (sVar1 < 0x101) {
          wcscpy((wchar_t *)(param_1 + 0x192),_Str);
        }
        else {
          iVar2 = 0x7a;
        }
      }
      iVar5 = local_60[0];
      iVar4 = 0x202;
      pwVar3 = (wchar_t *)(param_1 + 0x394);
      do {
        *(undefined1 *)pwVar3 = 0;
        iVar4 = iVar4 + -1;
        pwVar3 = (wchar_t *)((int)pwVar3 + 1);
      } while (iVar4 != 0);
      if ((*(int *)(local_60[0] + 0x18) != 0) && (*(uint *)(local_60[0] + 0x1c) != 0)) {
        if ((*(uint *)(local_60[0] + 0x1c) & 0xfffffffe) < 0x201) {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = 1;
          }
          wcsncpy((wchar_t *)(param_1 + 0x394),*(wchar_t **)(local_60[0] + 0x18),0x101);
          *(undefined2 *)(param_1 + 0x594) = 0;
        }
        else {
          iVar2 = 0x7a;
        }
      }
      CredFree(iVar5);
    }
  }
  FUN_c0449d30(local_24);
  return iVar2;
}



/* c0441d5c FUN_c0441d5c */

/* Boundary evidence: original MIPS .pdata c0441d5c..c0441f07. Semantic name remains unreviewed. */

LSTATUS FUN_c0441d5c(HKEY param_1,HKEY param_2)

{
  LSTATUS LVar1;
  LPWSTR lpValueName;
  LPBYTE lpData;
  DWORD dwIndex;
  DWORD local_40;
  DWORD local_3c;
  DWORD local_38;
  DWORD local_34;
  DWORD local_30;
  DWORD local_2c;
  
  LVar1 = RegQueryInfoKeyW(param_2,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (LPDWORD)0x0,&local_34,&local_40,&local_3c,(LPDWORD)0x0,(PFILETIME)0x0);
  if (LVar1 == 0) {
    lpValueName = LocalAlloc(0x40,(local_40 + 1) * 2);
    lpData = LocalAlloc(0x40,local_3c + 1);
    if ((lpValueName == (LPWSTR)0x0) || (lpData == (LPBYTE)0x0)) {
      LVar1 = 0x26f;
    }
    else {
      dwIndex = 0;
      if (local_34 != 0) {
        do {
          local_30 = local_40 + 1;
          local_38 = local_3c;
          LVar1 = RegEnumValueW(param_2,dwIndex,lpValueName,&local_30,(LPDWORD)0x0,&local_2c,lpData,
                                &local_38);
          if ((LVar1 != 0) ||
             (LVar1 = RegSetValueExW(param_1,lpValueName,0,local_2c,lpData,local_38), LVar1 != 0))
          break;
          dwIndex = dwIndex + 1;
        } while (dwIndex != local_34);
      }
    }
    LocalFree(lpValueName);
    LocalFree(lpData);
  }
  return LVar1;
}



/* c0441f08 FUN_c0441f08 */

/* Boundary evidence: original MIPS .pdata c0441f08..c0441f93. Semantic name remains unreviewed. */

LSTATUS FUN_c0441f08(HKEY param_1,LPCWSTR param_2,PHKEY param_3)

{
  LSTATUS LVar1;
  DWORD local_18 [2];
  
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,param_3,
                          local_18);
  if ((LVar1 == 0) && (local_18[0] == 2)) {
    LVar1 = 0xb7;
    RegCloseKey(*param_3);
    *param_3 = (HKEY)0x0;
  }
  return LVar1;
}



/* c0441f94 FUN_c0441f94 */

/* Boundary evidence: original MIPS .pdata c0441f94..c0442033. Semantic name remains unreviewed. */

bool FUN_c0441f94(HKEY param_1,LPCWSTR param_2,PHKEY param_3)

{
  LSTATUS LVar1;
  int iVar2;
  wchar_t *local_20 [2];
  
  iVar2 = 0x19;
  do {
    FUN_c04496e4(4,(BYTE *)local_20);
    swprintf(param_2,0xc043237c,local_20[0]);
    LVar1 = FUN_c0441f08(param_1,param_2,param_3);
    if (LVar1 == 0) break;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar2 != 0;
}



/* c0442034 FUN_c0442034 */

/* Boundary evidence: original MIPS .pdata c0442034..c04420f3. Semantic name remains unreviewed. */

LSTATUS FUN_c0442034(HKEY param_1,undefined4 *param_2,LPCWSTR param_3,undefined4 *param_4,
                    LPCWSTR param_5)

{
  LSTATUS LVar1;
  
  LVar1 = FUN_c0441d5c((HKEY)*param_2,(HKEY)*param_4);
  if (LVar1 == 0) {
    RegCloseKey((HKEY)*param_4);
    *param_4 = 0;
    LVar1 = RegDeleteKeyW(param_1,param_5);
  }
  else {
    RegCloseKey((HKEY)*param_2);
    *param_2 = 0;
    RegDeleteKeyW(param_1,param_3);
  }
  return LVar1;
}



/* c04420f4 FUN_c04420f4 */

/* Boundary evidence: original MIPS .pdata c04420f4..c04422ab. Semantic name remains unreviewed. */

LSTATUS FUN_c04420f4(HKEY param_1,wchar_t *param_2,wchar_t *param_3)

{
  bool bVar1;
  LSTATUS LVar2;
  int iVar3;
  undefined3 extraout_var;
  HKEY local_b0;
  HKEY local_ac;
  HKEY local_a8 [2];
  WCHAR aWStack_a0 [64];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  local_a8[0] = (HKEY)0x0;
  local_b0 = (HKEY)0x0;
  local_ac = (HKEY)0x0;
  LVar2 = RegOpenKeyExW(param_1,param_2,0,0,local_a8);
  if ((LVar2 == 0) && (iVar3 = wcscmp(param_2,param_3), iVar3 != 0)) {
    iVar3 = _wcsicmp(param_2,param_3);
    if (iVar3 == 0) {
      bVar1 = FUN_c0441f94(param_1,aWStack_a0,&local_ac);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        LVar2 = 0xe;
      }
      else {
        LVar2 = FUN_c0442034(param_1,&local_ac,aWStack_a0,local_a8,param_2);
        if ((LVar2 == 0) && (LVar2 = FUN_c0441f08(param_1,param_3,&local_b0), LVar2 == 0)) {
          LVar2 = FUN_c0442034(param_1,&local_b0,param_3,&local_ac,aWStack_a0);
        }
      }
    }
    else {
      LVar2 = FUN_c0441f08(param_1,param_3,&local_b0);
      if (LVar2 == 0) {
        LVar2 = FUN_c0442034(param_1,&local_b0,param_3,local_a8,param_2);
      }
    }
  }
  if (local_ac != (HKEY)0x0) {
    RegCloseKey(local_ac);
  }
  if (local_b0 != (HKEY)0x0) {
    RegCloseKey(local_b0);
  }
  if (local_a8[0] != (HKEY)0x0) {
    RegCloseKey(local_a8[0]);
  }
  FUN_c0449d30(local_20);
  return LVar2;
}



/* c04422ac AfdRasGetEntryDialParams */

/* Boundary evidence: original MIPS .pdata c04422ac..c044239b. Semantic name remains unreviewed. */

int AfdRasGetEntryDialParams(undefined4 param_1,int *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
                    /* 0x122ac  7  AfdRasGetEntryDialParams */
  if (((param_2 != (int *)0x0) && (param_4 != (int *)0x0)) && (*param_2 == 0x5b8)) {
    piVar3 = param_2 + 1;
    uVar4 = 0;
    if ((short)*piVar3 != 0) {
      do {
        uVar4 = uVar4 + 1;
        piVar3 = (int *)((int)piVar3 + 2);
        if (0x14 < uVar4) break;
      } while (*(short *)piVar3 != 0);
      if ((uVar4 != 0) && (uVar4 < 0x15)) {
        iVar1 = FUN_c0441b74((int)param_2,0,param_4);
        iVar2 = 0x202;
        piVar3 = param_2 + 0xe5;
        do {
          *(undefined1 *)piVar3 = 0;
          iVar2 = iVar2 + -1;
          piVar3 = (int *)((int)piVar3 + 1);
        } while (iVar2 != 0);
        if (*param_4 == 0) {
          return iVar1;
        }
        memcpy(param_2 + 0xe5,u__________________c044d7b0,0x22);
        return iVar1;
      }
    }
  }
  return 0x57;
}



/* c044239c FUN_c044239c */

/* Boundary evidence: original MIPS .pdata c044239c..c04423fb. Semantic name remains unreviewed. */

undefined4 FUN_c044239c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = wcscmp((wchar_t *)(param_1 + 0x394),u__________________c044d7b0);
  uVar2 = 1;
  if ((iVar1 == 0) && (iVar1 = FUN_c0441b74(param_1,1,(undefined4 *)0x0), iVar1 != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c04423fc AfdRasSetEntryDialParams */

/* Boundary evidence: original MIPS .pdata c04423fc..c0442563. Semantic name remains unreviewed. */

undefined4 AfdRasSetEntryDialParams(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  short *psVar2;
  uint uVar3;
  undefined1 auStack_5c8 [4];
  short local_5c4;
  short local_5c2 [20];
  short local_59a;
  short local_598 [177];
  short local_436;
  short local_434 [256];
  short local_234;
  short local_232 [256];
  short local_32;
  short local_30 [16];
  uint local_10;
  
                    /* 0x123fc  13  AfdRasSetEntryDialParams */
  local_10 = DAT_c044d82c;
  if ((param_2 != (int *)0x0) && (*param_2 == 0x5b8)) {
    memcpy(auStack_5c8,param_2,0x5b8);
    psVar2 = &local_5c4;
    uVar3 = 0;
    if (local_5c4 != 0) {
      do {
        uVar3 = uVar3 + 1;
        psVar2 = psVar2 + 1;
        if (0x14 < uVar3) break;
      } while (*psVar2 != 0);
      if ((uVar3 != 0) && (uVar3 < 0x15)) {
        psVar2 = &local_59a;
        uVar3 = 0;
        while (local_59a != 0) {
          uVar3 = uVar3 + 1;
          psVar2 = psVar2 + 1;
          if (0x80 < uVar3) goto LAB_c0442544;
          local_59a = *psVar2;
        }
        psVar2 = &local_436;
        uVar3 = 0;
        while (local_436 != 0) {
          uVar3 = uVar3 + 1;
          psVar2 = psVar2 + 1;
          if (0x100 < uVar3) goto LAB_c0442544;
          local_436 = *psVar2;
        }
        psVar2 = &local_234;
        uVar3 = 0;
        while (local_234 != 0) {
          uVar3 = uVar3 + 1;
          psVar2 = psVar2 + 1;
          if (0x100 < uVar3) goto LAB_c0442544;
          local_234 = *psVar2;
        }
        psVar2 = &local_32;
        uVar3 = 0;
        while (local_32 != 0) {
          uVar3 = uVar3 + 1;
          psVar2 = psVar2 + 1;
          if (0xf < uVar3) goto LAB_c0442544;
          local_32 = *psVar2;
        }
        uVar1 = FUN_c04419f8((int)auStack_5c8,param_4);
        goto LAB_c0442548;
      }
    }
  }
LAB_c0442544:
  uVar1 = 0x262;
LAB_c0442548:
  FUN_c0449d30(local_10);
  return uVar1;
}



/* c0442564 FUN_c0442564 */

/* Boundary evidence: original MIPS .pdata c0442564..c0442607. Semantic name remains unreviewed. */

undefined4 FUN_c0442564(HKEY param_1)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD local_488;
  DWORD DStack_484;
  BYTE aBStack_480 [320];
  wchar_t awStack_340 [408];
  uint local_10;
  
  local_10 = DAT_c044d82c;
  local_488 = 0x470;
  LVar1 = RegQueryValueExW(param_1,L"Entry",(LPDWORD)0x0,&DStack_484,aBStack_480,&local_488);
  if (((LVar1 == 0) && (local_488 == 0x470)) && (iVar2 = wcscmp(awStack_340,L"vpn"), iVar2 == 0)) {
    FUN_c0449d30(local_10);
    uVar3 = 1;
  }
  else {
    FUN_c0449d30(local_10);
    uVar3 = 0;
  }
  return uVar3;
}



/* c0442608 FUN_c0442608 */

/* Boundary evidence: original MIPS .pdata c0442608..c04426eb. Semantic name remains unreviewed. */

undefined4 FUN_c0442608(wchar_t *param_1)

{
  wchar_t *pwVar1;
  int iVar2;
  uint uVar3;
  wchar_t _Ch;
  undefined4 uVar4;
  
  uVar4 = 0x7b;
  if (param_1 != (wchar_t *)0x0) {
    _Ch = *param_1;
    uVar3 = 0;
    pwVar1 = param_1;
    if (_Ch != L'\0') {
      do {
        uVar3 = uVar3 + 1;
        pwVar1 = pwVar1 + 1;
        if (0x14 < uVar3) break;
      } while (*pwVar1 != L'\0');
      if ((uVar3 != 0) && (uVar3 < 0x15)) {
        do {
          if (((ushort)_Ch < 0x20) ||
             (pwVar1 = wcschr(L"*\\/?><:\"|",_Ch), pwVar1 != (wchar_t *)0x0)) {
            return 0x7b;
          }
          iVar2 = iswctype(*param_1,0x107);
          if (iVar2 != 0) {
            uVar4 = 0;
          }
          param_1 = param_1 + 1;
          _Ch = *param_1;
        } while (_Ch != L'\0');
      }
    }
  }
  return uVar4;
}



/* c04426ec FUN_c04426ec */

/* Boundary evidence: original MIPS .pdata c04426ec..c04427af. Semantic name remains unreviewed. */

void FUN_c04426ec(int *param_1)

{
  int iVar1;
  int local_148 [11];
  wchar_t awStack_11a [129];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  local_148[0] = 0;
  memset(param_1 + 1,0,*param_1 - 4);
  param_1[0x52] = 1;
  param_1[1] = 0x400208;
  param_1[0x51] = 4;
  wcscpy((wchar_t *)(param_1 + 0x1d9),L"direct");
  local_148[2] = 0x128;
  local_148[1] = 0x128;
  iVar1 = FUN_c0447d7c((uint *)(local_148 + 2),1,(uint *)(local_148 + 1),local_148);
  if ((iVar1 == 0) && (local_148[0] != 0)) {
    wcscpy((wchar_t *)((int)param_1 + 0x786),awStack_11a);
  }
  FUN_c0449d30(local_18);
  return;
}



/* c04427b0 FUN_c04427b0 */

/* Boundary evidence: original MIPS .pdata c04427b0..c04428f3. Semantic name remains unreviewed. */

void FUN_c04427b0(int *param_1,int *param_2)

{
  FUN_c04426ec(param_2);
  param_2[1] = *param_1;
  param_2[2] = param_1[1];
  param_2[3] = param_1[2];
  param_2[0x51] = 4;
  param_2[0x52] = 1;
  wcscpy((wchar_t *)(param_2 + 4),(wchar_t *)(param_1 + 3));
  wcscpy((wchar_t *)((int)param_2 + 0x26),(wchar_t *)((int)param_1 + 0x22));
  param_2[0x4b] = param_1[0x49];
  param_2[0x4c] = param_1[0x4a];
  param_2[0x4d] = param_1[0x4b];
  param_2[0x4e] = param_1[0x4c];
  param_2[0x4f] = param_1[0x4d];
  param_2[0x50] = param_1[0x4e];
  param_2[0x52] = param_1[0x4f];
  wcscpy((wchar_t *)(param_2 + 0x1d9),(wchar_t *)(param_1 + 0x50));
  if (*param_2 == 0xccc) {
    wcsncpy((wchar_t *)((int)param_2 + 0x786),(wchar_t *)((int)param_1 + 0x162),0x20);
    *(undefined2 *)((int)param_2 + 0x7c6) = 0;
    wcscpy((wchar_t *)(param_2 + 0x53),(wchar_t *)(param_1 + 0x99));
  }
  else {
    wcscpy((wchar_t *)((int)param_2 + 0x786),(wchar_t *)((int)param_1 + 0x162));
    wcscpy((wchar_t *)(param_2 + 0x53),(wchar_t *)(param_1 + 0x99));
    param_2[0x363] = param_1[0x11b];
  }
  return;
}



/* c04428f4 FUN_c04428f4 */

/* Boundary evidence: original MIPS .pdata c04428f4..c0442a0b. Semantic name remains unreviewed. */

void FUN_c04428f4(int *param_1,int *param_2)

{
  *param_2 = param_1[1];
  param_2[1] = param_1[2];
  param_2[2] = param_1[3];
  wcscpy((wchar_t *)(param_2 + 3),(wchar_t *)(param_1 + 4));
  wcscpy((wchar_t *)((int)param_2 + 0x22),(wchar_t *)((int)param_1 + 0x26));
  param_2[0x49] = param_1[0x4b];
  param_2[0x4a] = param_1[0x4c];
  param_2[0x4b] = param_1[0x4d];
  param_2[0x4c] = param_1[0x4e];
  param_2[0x4d] = param_1[0x4f];
  param_2[0x4e] = param_1[0x50];
  param_2[0x4f] = param_1[0x52];
  wcscpy((wchar_t *)(param_2 + 0x50),(wchar_t *)(param_1 + 0x1d9));
  wcscpy((wchar_t *)((int)param_2 + 0x162),(wchar_t *)((int)param_1 + 0x786));
  if (*param_1 == 0xccc) {
    wcscpy((wchar_t *)(param_2 + 0x99),(wchar_t *)(param_1 + 0x53));
  }
  else {
    wcscpy((wchar_t *)(param_2 + 0x99),(wchar_t *)(param_1 + 0x53));
    param_2[0x11b] = param_1[0x363];
  }
  return;
}



/* c0442a0c FUN_c0442a0c */

/* Boundary evidence: original MIPS .pdata c0442a0c..c0442aa7. Semantic name remains unreviewed. */

undefined4 FUN_c0442a0c(STRSAFE_LPWSTR param_1,STRSAFE_LPCWSTR param_2)

{
  undefined4 uVar1;
  HRESULT HVar2;
  
  if (param_2 == (STRSAFE_LPCWSTR)0x0) {
    uVar1 = 0x7b;
  }
  else {
    HVar2 = StringCchCopyW(param_1,0x15,param_2);
    if (HVar2 == 0) {
      uVar1 = FUN_c0442608(param_1);
    }
    else {
      uVar1 = 0x7b;
    }
  }
  return uVar1;
}



/* c0442aa8 FUN_c0442aa8 */

/* Boundary evidence: original MIPS .pdata c0442aa8..c0442ab3. Semantic name remains unreviewed. */

undefined4 FUN_c0442aa8(void)

{
  return 1;
}



/* c0442ab4 FUN_c0442ab4 */

/* Boundary evidence: original MIPS .pdata c0442ab4..c0442b73. Semantic name remains unreviewed. */

int FUN_c0442ab4(int param_1,STRSAFE_LPCWSTR param_2,PHKEY param_3)

{
  LSTATUS LVar1;
  int iVar2;
  wchar_t awStack_148 [24];
  wchar_t awStack_118 [128];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  if (param_1 == 0) {
    iVar2 = FUN_c0442a0c(awStack_148,param_2);
    if (iVar2 == 0) {
      StringCchPrintfW(awStack_118,0x80,L"%s\\%s",L"Comm\\RasBook",awStack_148);
      LVar1 = RegOpenKeyExW((HKEY)0x80000001,awStack_118,0,0xf003f,param_3);
      iVar2 = 0;
      if (LVar1 != 0) {
        iVar2 = 0x26f;
      }
    }
  }
  else {
    iVar2 = 0x26d;
  }
  FUN_c0449d30(local_18);
  return iVar2;
}



/* c0442b74 FUN_c0442b74 */

/* Boundary evidence: original MIPS .pdata c0442b74..c0442c53. Semantic name remains unreviewed. */

int FUN_c0442b74(int param_1,wchar_t *param_2,PHKEY param_3)

{
  LSTATUS LVar1;
  int iVar2;
  DWORD aDStack_120 [2];
  wchar_t awStack_118 [128];
  uint local_18;
  
  local_18 = DAT_c044d82c;
  if (param_1 == 0) {
    iVar2 = FUN_c0442608(param_2);
    if (iVar2 == 0) {
      StringCchPrintfW(awStack_118,0x80,L"%s\\%s",L"Comm\\RasBook",param_2);
      LVar1 = RegCreateKeyExW((HKEY)0x80000001,awStack_118,0,(LPWSTR)0x0,0,0xf003f,
                              (LPSECURITY_ATTRIBUTES)0x0,param_3,aDStack_120);
      iVar2 = 0;
      if (LVar1 != 0) {
        iVar2 = 0x26f;
      }
    }
  }
  else {
    iVar2 = 0x26d;
  }
  FUN_c0449d30(local_18);
  return iVar2;
}



/* c0442c54 AfdRasSetEntryProperties */

/* Boundary evidence: original MIPS .pdata c0442c54..c0442f4f. Semantic name remains unreviewed. */

int AfdRasSetEntryProperties
              (int param_1,wchar_t *param_2,void *param_3,uint param_4,wchar_t *param_5,
              wchar_t *param_6)

{
  int *_Dst;
  LSTATUS LVar1;
  int iVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  wchar_t *cbData;
  wchar_t *lpData;
  DATA_BLOB local_4c0;
  HKEY local_4b8 [2];
  DATA_BLOB local_4b0;
  int *local_4a8;
  int aiStack_4a0 [80];
  wchar_t awStack_360 [17];
  WCHAR aWStack_33e [391];
  uint local_30;
  
                    /* 0x12c54  14  AfdRasSetEntryProperties */
  local_30 = DAT_c044d82c;
  local_4c0.cbData = (DWORD)param_5;
  local_4b0.cbData = (DWORD)param_2;
  _Dst = LocalAlloc(0x40,0xd90);
  local_4a8 = _Dst;
  if (param_3 == (void *)0x0) {
    iVar5 = 0x262;
  }
  else if ((param_4 < 0xccc) || ((0xccc < param_4 && (param_4 < 0xd90)))) {
    iVar5 = 0x25b;
  }
  else if (_Dst == (int *)0x0) {
    iVar5 = 0xe;
  }
  else {
    if (0xd90 < param_4) {
      param_4 = 0xd90;
    }
    memcpy(_Dst,param_3,param_4);
    iVar5 = FUN_c0442b74(param_1,param_2,local_4b8);
    if (iVar5 == 0) {
      FUN_c04428f4(_Dst,aiStack_4a0);
      LVar1 = RegSetValueExW(local_4b8[0],L"Entry",0,3,(BYTE *)aiStack_4a0,0x470);
      if (LVar1 == 0) {
        if (param_5 != (wchar_t *)0x0) {
          local_4c0.cbData = 0;
          memset(&local_4c0.pbData,0,4);
          iVar2 = wcscmp(awStack_360,L"vpn");
          DVar4 = 0;
          cbData = param_6;
          lpData = param_5;
          if (iVar2 == 0) {
            local_4b0.cbData = (DWORD)param_6;
            local_4b0.pbData = (BYTE *)param_5;
            BVar3 = CryptProtectData(&local_4b0,aWStack_33e,(DATA_BLOB *)0x0,(PVOID)0x0,
                                     (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000000,&local_4c0);
            cbData = (wchar_t *)local_4c0.cbData;
            lpData = (wchar_t *)local_4c0.pbData;
            if (BVar3 == 0) {
              DVar4 = GetLastError();
              cbData = param_6;
              lpData = param_5;
            }
          }
          if ((DVar4 != 0) ||
             (LVar1 = RegSetValueExW(local_4b8[0],L"DevCfg",0,3,(BYTE *)lpData,(DWORD)cbData),
             LVar1 != 0)) {
            iVar5 = 0x26d;
          }
          if ((wchar_t *)local_4c0.pbData != (wchar_t *)0x0) {
            LocalFree(local_4c0.pbData);
          }
        }
      }
      else {
        iVar5 = 0x26d;
      }
      RegCloseKey(local_4b8[0]);
    }
  }
  LocalFree(_Dst);
  FUN_c0449d30(local_30);
  return iVar5;
}



/* c0442f50 FUN_c0442f50 */

/* Boundary evidence: original MIPS .pdata c0442f50..c0442f5b. Semantic name remains unreviewed. */

undefined4 FUN_c0442f50(void)

{
  return 1;
}



/* c0442f5c AfdRasGetEntryProperties */

/* Boundary evidence: original MIPS .pdata c0442f5c..c044337f. Semantic name remains unreviewed. */

int AfdRasGetEntryProperties
              (int param_1,STRSAFE_LPCWSTR param_2,uint *param_3,undefined4 param_4,uint *param_5,
              LPBYTE param_6,undefined4 param_7,uint *param_8)

{
  DWORD DVar1;
  BYTE *hMem;
  DWORD DVar2;
  HRESULT HVar3;
  LSTATUS LVar4;
  int iVar5;
  BOOL BVar6;
  uint uVar7;
  int iVar8;
  HLOCAL local_4f0;
  HKEY local_4ec;
  DWORD local_4e8 [2];
  DATA_BLOB local_4e0;
  int *local_4d8 [2];
  DATA_BLOB local_4d0;
  undefined4 local_4c8 [2];
  int aiStack_4c0 [80];
  wchar_t awStack_380 [408];
  wchar_t local_50 [22];
  uint local_24;
  
                    /* 0x12f5c  8  AfdRasGetEntryProperties */
  local_24 = DAT_c044d82c;
  iVar8 = 0;
  if ((param_3 != (uint *)0x0) && (param_5 == (uint *)0x0)) {
    FUN_c0449d30(DAT_c044d82c);
    return 0x57;
  }
  local_50[0] = L'\0';
  if (param_5 == (uint *)0x0) {
    iVar8 = 0x57;
LAB_c0443014:
    if (param_3 == (uint *)0x0) {
LAB_c044301c:
      iVar8 = 0x262;
      goto LAB_c0443350;
    }
  }
  else {
    if ((param_2 == (STRSAFE_LPCWSTR)0x0) ||
       (HVar3 = StringCchCopyW(local_50,0x15,param_2), HVar3 != 0)) {
      iVar8 = 0x7b;
      goto LAB_c0443014;
    }
    if ((local_50[0] != L'\0') && (iVar8 = FUN_c0442608(local_50), iVar8 != 0)) goto LAB_c0443014;
    if (param_3 == (uint *)0x0) {
      if (*param_5 == 0) {
        *param_5 = 0xd90;
        FUN_c0449d30(local_24);
        return 0x25b;
      }
      goto LAB_c044301c;
    }
  }
  uVar7 = *param_3;
  if ((uVar7 == 0xccc) || (uVar7 == 0xd90)) {
    if (*param_5 < uVar7) {
      *param_5 = uVar7;
      iVar8 = 0x25b;
    }
    if (iVar8 == 0) {
      if (local_50[0] == L'\0') {
        FUN_c04426ec((int *)param_3);
        FUN_c0449d30(local_24);
        return 0;
      }
      iVar8 = FUN_c0442ab4(param_1,local_50,&local_4ec);
      if (iVar8 == 0) {
        local_4f0 = (HLOCAL)0x470;
        LVar4 = RegQueryValueExW(local_4ec,L"Entry",(LPDWORD)0x0,local_4e8,(LPBYTE)aiStack_4c0,
                                 (LPDWORD)&local_4f0);
        if (LVar4 == 0) {
          if ((local_4e8[0] == 3) && (local_4f0 == (HLOCAL)0x470)) {
            FUN_c04427b0(aiStack_4c0,(int *)param_3);
            iVar8 = 0;
          }
          else {
            iVar8 = 0x271;
          }
        }
        else {
          iVar8 = 0x26f;
        }
        if (param_8 != (uint *)0x0) {
          LVar4 = RegQueryValueExW(local_4ec,L"DevCfg",(LPDWORD)0x0,local_4e8,(LPBYTE)0x0,
                                   (LPDWORD)&local_4f0);
          if (LVar4 == 0) {
            if ((param_6 == (LPBYTE)0x0) || ((HLOCAL)*param_8 < local_4f0)) {
              iVar8 = 0x25b;
            }
            else {
              LVar4 = RegQueryValueExW(local_4ec,L"DevCfg",(LPDWORD)0x0,local_4e8,param_6,
                                       (LPDWORD)&local_4f0);
              if ((LVar4 == 0) && (iVar5 = wcscmp(awStack_380,L"vpn"), iVar5 == 0)) {
                local_4d0.cbData = (DWORD)local_4f0;
                local_4d0.pbData = param_6;
                local_4e0.cbData = 0;
                local_4e0.pbData = (BYTE *)0x0;
                BVar6 = CryptUnprotectData(&local_4d0,(LPWSTR *)0x0,(DATA_BLOB *)0x0,(PVOID)0x0,
                                           (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000000,&local_4e0);
                hMem = local_4e0.pbData;
                DVar1 = local_4e0.cbData;
                if (BVar6 == 0) {
                  iVar8 = 0x271;
                  GetLastError();
                }
                else {
                  if (local_4f0 < local_4e0.cbData) {
                    iVar8 = 0x25b;
                  }
                  else {
                    memcpy(param_6,local_4e0.pbData,local_4e0.cbData);
                  }
                  local_4f0 = (HLOCAL)DVar1;
                  LocalFree(hMem);
                }
              }
            }
            *param_8 = (uint)local_4f0;
          }
          else {
            iVar5 = FUN_c0447cf8((int)param_3 + 0x786,param_3 + 0x1d9,local_4d8,local_4c8);
            if (iVar5 == 0) {
              iVar5 = FUN_c044860c((int)local_4d8[0],local_4c8[0],&local_4e0.cbData,
                                   &local_4d0.cbData);
              DVar2 = local_4d0.cbData;
              DVar1 = local_4e0.cbData;
              if (iVar5 == 0) {
                if ((param_6 != (LPBYTE)0x0) && (local_4d0.cbData <= (HLOCAL)*param_8)) {
                  memcpy(param_6,(void *)local_4e0.cbData,local_4d0.cbData);
                }
                *param_8 = DVar2;
                LocalFree((HLOCAL)DVar1);
              }
              else {
                *param_8 = 0;
              }
              FUN_c0447918(local_4d8[0]);
            }
            else {
              *param_8 = 0;
            }
          }
        }
        RegCloseKey(local_4ec);
      }
      else {
        iVar8 = 0x26f;
      }
    }
  }
  else {
    iVar8 = 0x278;
  }
LAB_c0443350:
  FUN_c0449d30(local_24);
  return iVar8;
}



/* c0443380 AfdRasValidateEntryName */

/* Boundary evidence: original MIPS .pdata c0443380..c04433df. Semantic name remains unreviewed. */

int AfdRasValidateEntryName(int param_1,STRSAFE_LPCWSTR param_2)

{
  int iVar1;
  HKEY local_10 [2];
  
                    /* 0x13380  15  AfdRasValidateEntryName */
  iVar1 = FUN_c0442ab4(param_1,param_2,local_10);
  if (iVar1 == 0) {
    iVar1 = 0xb7;
    RegCloseKey(local_10[0]);
  }
  else if (iVar1 == 0x26f) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c04433e0 AfdRasDeleteEntry */

/* Boundary evidence: original MIPS .pdata c04433e0..c0443477. Semantic name remains unreviewed. */

int AfdRasDeleteEntry(int param_1,STRSAFE_LPCWSTR param_2)

{
  int iVar1;
  wchar_t awStack_140 [24];
  wchar_t awStack_110 [128];
  uint local_10;
  
                    /* 0x133e0  1  AfdRasDeleteEntry */
  local_10 = DAT_c044d82c;
  if (param_1 == 0) {
    iVar1 = FUN_c0442a0c(awStack_140,param_2);
    if (iVar1 == 0) {
      StringCchPrintfW(awStack_110,0x80,L"%s\\%s",L"Comm\\RasBook",awStack_140);
      iVar1 = RegDeleteKeyW((HKEY)0x80000001,awStack_110);
    }
  }
  else {
    iVar1 = 0x26d;
  }
  FUN_c0449d30(local_10);
  return iVar1;
}



/* c0443478 AfdRasRenameEntry */

/* Boundary evidence: original MIPS .pdata c0443478..c0443703. Semantic name remains unreviewed. */

int AfdRasRenameEntry(undefined4 param_1,STRSAFE_LPCWSTR param_2,STRSAFE_LPCWSTR param_3)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  HKEY local_678 [2];
  undefined1 local_670 [4];
  wchar_t awStack_66c [730];
  wchar_t awStack_b8 [24];
  wchar_t awStack_88 [24];
  wchar_t awStack_58 [30];
  uint local_1c;
  
                    /* 0x13478  11  AfdRasRenameEntry */
  local_1c = DAT_c044d82c;
  iVar2 = FUN_c0442a0c(awStack_b8,param_2);
  if (((iVar2 != 0) || (iVar2 = FUN_c0442a0c(awStack_88,param_3), iVar2 != 0)) ||
     (iVar2 = RegOpenKeyExW((HKEY)0x80000001,L"Comm\\RasBook",0,0,local_678), iVar2 != 0))
  goto LAB_c04436dc;
  iVar2 = _wcsicmp(awStack_b8,awStack_88);
  if (iVar2 == 0) {
    bVar1 = false;
LAB_c0443598:
    iVar2 = FUN_c04420f4(local_678[0],awStack_b8,awStack_88);
    if (iVar2 == 0) {
      wcscpy(awStack_66c,awStack_b8);
    }
    if (bVar1) {
      wcscpy(awStack_58,L"PPP_");
      wcscat(awStack_58,awStack_66c);
      sVar3 = wcslen(awStack_58);
      iVar4 = CredDelete(awStack_58,sVar3 + 1,0x10006,0);
      if (iVar4 != 0) {
        iVar2 = 0x54f;
      }
    }
  }
  else {
    wcscpy(awStack_66c,awStack_b8);
    iVar2 = FUN_c0441b74((int)local_670,0,(undefined4 *)0x0);
    bVar1 = iVar2 != 0x490;
    if (!bVar1) {
      iVar2 = 0;
    }
    if (iVar2 == 0) {
      if (bVar1) {
        wcscpy(awStack_66c,awStack_88);
        iVar2 = FUN_c04419f8((int)local_670,0);
        if (iVar2 != 0) goto LAB_c0443610;
      }
      goto LAB_c0443598;
    }
  }
LAB_c0443610:
  iVar4 = 0x5b8;
  puVar5 = local_670;
  do {
    *puVar5 = 0;
    iVar4 = iVar4 + -1;
    puVar5 = puVar5 + 1;
  } while (iVar4 != 0);
  RegCloseKey(local_678[0]);
  if (iVar2 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
    for (piVar6 = DAT_c044d8b0; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      iVar4 = FUN_c043336c(piVar6);
      if (iVar4 != 0) {
        if (((piVar6[0x1b] == 0) && (param_2 != (STRSAFE_LPCWSTR)0x0)) &&
           (iVar4 = _wcsnicmp((wchar_t *)(piVar6 + 0x1e),awStack_b8,0x14), iVar4 == 0)) {
          wcsncpy((wchar_t *)(piVar6 + 0x1e),awStack_88,0x14);
          *(undefined2 *)(piVar6 + 0x28) = 0;
          FUN_c0433498(piVar6);
          break;
        }
        FUN_c0433498(piVar6);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  }
LAB_c04436dc:
  FUN_c0449d30(local_1c);
  return iVar2;
}



/* c0443704 AfdRasGetEntryDevConfig */

/* Boundary evidence: original MIPS .pdata c0443704..c044385f. Semantic name remains unreviewed. */

int AfdRasGetEntryDevConfig
              (int param_1,STRSAFE_LPCWSTR param_2,undefined4 *param_3,int *param_4,int *param_5,
              uint param_6)

{
  int iVar1;
  LSTATUS LVar2;
  uint uVar3;
  int iVar4;
  HKEY local_28;
  DWORD local_24;
  DWORD aDStack_20 [2];
  
                    /* 0x13704  6  AfdRasGetEntryDevConfig */
  if (param_4 == (int *)0x0) {
    iVar4 = 0x57;
  }
  else {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
    iVar4 = FUN_c0442ab4(param_1,param_2,&local_28);
    if (iVar4 == 0) {
      iVar1 = FUN_c0442564(local_28);
      if (iVar1 == 0) {
        LVar2 = RegQueryValueExW(local_28,L"DevCfg",(LPDWORD)0x0,aDStack_20,(LPBYTE)0x0,&local_24);
        if (LVar2 == 0) {
          if (param_5 == (int *)0x0) {
            *param_4 = local_24 + 0x18;
          }
          else {
            uVar3 = local_24 + 0x18;
            if (param_6 < uVar3) {
              iVar4 = 0x25b;
            }
            else {
              iVar1 = *param_4;
              param_5[5] = 0x18;
              *param_5 = iVar1;
              param_5[1] = uVar3;
              param_5[2] = uVar3;
              param_5[3] = 0;
              param_5[4] = local_24;
              RegQueryValueExW(local_28,L"DevCfg",(LPDWORD)0x0,aDStack_20,(LPBYTE)(param_5 + 6),
                               &local_24);
            }
          }
        }
        else {
          iVar4 = 0x26f;
        }
      }
      else {
        iVar4 = 0x297;
      }
      RegCloseKey(local_28);
    }
  }
  return iVar4;
}



/* c0443860 AfdRasSetEntryDevConfig */

/* Boundary evidence: original MIPS .pdata c0443860..c044393f. Semantic name remains unreviewed. */

int AfdRasSetEntryDevConfig(int param_1,STRSAFE_LPCWSTR param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  LSTATUS LVar2;
  HKEY local_18 [2];
  
                    /* 0x13860  12  AfdRasSetEntryDevConfig */
  if ((param_4 == 0) || (0x17 < *(uint *)(param_4 + 4))) {
    LVar2 = FUN_c0442ab4(param_1,param_2,local_18);
    if (LVar2 == 0) {
      iVar1 = FUN_c0442564(local_18[0]);
      if (iVar1 == 0) {
        if (param_4 == 0) {
          RegDeleteValueW(local_18[0],L"DevCfg");
        }
        else {
          LVar2 = RegSetValueExW(local_18[0],L"DevCfg",0,3,
                                 (BYTE *)(*(int *)(param_4 + 0x14) + param_4),
                                 *(DWORD *)(param_4 + 0x10));
        }
      }
      else {
        LVar2 = 0x297;
      }
      RegCloseKey(local_18[0]);
    }
  }
  else {
    LVar2 = 0x57;
  }
  return LVar2;
}



/* c0443940 FUN_c0443940 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0443940..c0443a43. Semantic name remains unreviewed. */

undefined4 FUN_c0443940(undefined4 param_1,int param_2)

{
  int iVar1;
  LSTATUS LVar2;
  HKEY local_ea8;
  DWORD aDStack_ea4 [76];
  undefined1 local_d74;
  undefined1 local_d73;
  undefined1 local_d72;
  undefined1 local_d71;
  wchar_t awStack_110 [128];
  uint local_10;
  
  local_10 = DAT_c044d82c;
  aDStack_ea4[1] = 0xd90;
  FUN_c04426ec((int *)(aDStack_ea4 + 1));
  local_d71 = 0xc0;
  local_d72 = 0xa8;
  local_d73 = 0x37;
  local_d74 = 100;
  iVar1 = FUN_c04418dc(0,awStack_110,0x80);
  if (iVar1 == 0) {
    LVar2 = RegCreateKeyExW((HKEY)0x80000001,L"Comm\\RasBook",0,(LPWSTR)0x0,0,0xf003f,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_ea8,aDStack_ea4);
    if (LVar2 == 0) {
      RegCloseKey(local_ea8);
    }
  }
  else {
    AfdRasSetEntryProperties
              (param_2,awStack_110,aDStack_ea4 + 1,0xd90,(wchar_t *)0x0,(wchar_t *)0x0);
  }
  FUN_c0449d30(local_10);
  return 0;
}



/* c0443a44 AfdRasEnumEntries */

/* Boundary evidence: original MIPS .pdata c0443a44..c0443c63. Semantic name remains unreviewed. */

int AfdRasEnumEntries(int param_1,int param_2,undefined4 *param_3,uint param_4,uint *param_5,
                     int *param_6)

{
  uint uVar1;
  LSTATUS LVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  DWORD dwIndex;
  int local_78;
  HKEY local_74;
  uint local_70;
  DWORD local_6c;
  uint *local_68;
  _FILETIME _Stack_60;
  WCHAR aWStack_58 [22];
  uint local_2c;
  
                    /* 0x13a44  4  AfdRasEnumEntries */
  local_2c = DAT_c044d82c;
  iVar3 = 0;
  uVar5 = 0;
  local_68 = param_5;
  local_78 = 0;
  if (param_1 != 0) {
    iVar3 = 0x27b;
    local_78 = 0x27b;
  }
  if (param_2 != 0) {
    iVar3 = 0x26d;
    local_78 = 0x26d;
  }
  if (param_5 == (uint *)0x0) {
    iVar3 = 0x278;
    local_78 = 0x278;
  }
  local_70 = param_4;
  if (iVar3 != 0) goto LAB_c0443c2c;
  if (param_6 != (int *)0x0) {
    *param_6 = 0;
  }
  LVar2 = RegOpenKeyExW((HKEY)0x80000001,L"Comm\\RasBook",0,0x20019,&local_74);
  if (LVar2 == 0) {
LAB_c0443b64:
    uVar1 = local_70;
    dwIndex = 0;
    puVar4 = param_3;
    do {
      local_6c = 0x15;
      LVar2 = RegEnumKeyExW(local_74,dwIndex,aWStack_58,&local_6c,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,&_Stack_60);
      if (LVar2 == 0) {
        uVar5 = uVar5 + 0x30;
        if ((uVar5 <= uVar1) && (param_3 != (undefined4 *)0x0)) {
          *puVar4 = 0x30;
          wcscpy((wchar_t *)(puVar4 + 1),aWStack_58);
          if (param_6 != (int *)0x0) {
            *param_6 = *param_6 + 1;
          }
        }
        puVar4 = puVar4 + 0xc;
      }
      dwIndex = dwIndex + 1;
    } while (LVar2 == 0);
    RegCloseKey(local_74);
    iVar3 = local_78;
    param_5 = local_68;
    if (local_70 < uVar5) {
      iVar3 = 0x25b;
    }
  }
  else {
    FUN_c0443940(param_1,param_2);
    LVar2 = RegOpenKeyExW((HKEY)0x80000001,L"Comm\\RasBook",0,0x20019,&local_74);
    if (LVar2 == 0) goto LAB_c0443b64;
  }
  *param_5 = uVar5;
LAB_c0443c2c:
  FUN_c0449d30(local_2c);
  return iVar3;
}



/* c0443c64 FUN_c0443c64 */

/* Boundary evidence: original MIPS .pdata c0443c64..c0443e07. Semantic name remains unreviewed. */

undefined4 FUN_c0443c64(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_b98 [2];
  wchar_t awStack_b90 [257];
  wchar_t awStack_98e [257];
  wchar_t awStack_78c [16];
  uint local_76c;
  undefined4 local_5e0;
  wchar_t awStack_5dc [730];
  uint local_28;
  
  local_28 = DAT_c044d82c;
  uVar3 = 0;
  uVar2 = 0;
  if (*(int *)(param_1 + 0xa9c) == -1) {
    uVar2 = *(undefined4 *)(param_1 + 0xaa0);
  }
  memset(awStack_b90,0,0x5b0);
  StringCchCopyW(awStack_b90,0x101,(wchar_t *)(param_1 + 0x206));
  StringCchCopyW(awStack_98e,0x101,(wchar_t *)(param_1 + 0x408));
  StringCchCopyW(awStack_78c,0x10,(wchar_t *)(param_1 + 0x60a));
  local_5e0 = 0x5b8;
  wcscpy(awStack_5dc,(wchar_t *)(param_1 + 0x78));
  iVar1 = RasGetEntryDialParams(0,&local_5e0,local_b98);
  if ((iVar1 == 0) && (local_b98[0] != 0)) {
    local_76c = local_76c | 1;
  }
  local_76c = local_76c | 2;
  iVar1 = FUN_c043c6e4(uVar2,awStack_b90,(uint *)(param_1 + 0xcec));
  *(uint *)(param_1 + 0xcec) = 0;
  FUN_c04335a8(param_1);
  if (iVar1 == 0) {
    uVar3 = 0x277;
  }
  else {
    wcscpy((wchar_t *)(param_1 + 0x206),awStack_b90);
    wcscpy((wchar_t *)(param_1 + 0x408),awStack_98e);
    wcscpy((wchar_t *)(param_1 + 0x60a),awStack_78c);
    RasSetEntryDialParams(0,param_1 + 0x74,(local_76c & 1) == 0);
  }
  FUN_c04335c4(param_1);
  FUN_c0449d30(local_28);
  return uVar3;
}



/* c0443e08 AfdRasDial */

/* Boundary evidence: original MIPS .pdata c0443e08..c0444057. Semantic name remains unreviewed. */

DWORD AfdRasDial(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                int param_6,int param_7,undefined4 *param_8)

{
  int *piVar1;
  uint *_Dst;
  int iVar2;
  DWORD DVar3;
  uint local_50 [2];
  int *local_48 [2];
  int local_40;
  int local_3c;
  int local_38;
  uint *local_34;
  uint *local_30;
  uint local_2c [3];
  
                    /* 0x13e08  2  AfdRasDial */
  if (DAT_c044d840 == 0) {
    return 0x426;
  }
  if ((param_8 == (undefined4 *)0x0) || ((param_7 != 0 && ((param_6 != -1 || (DAT_c044d8d8 == 0)))))
     ) {
    return 0x57;
  }
  _Dst = LocalAlloc(0,0xd90);
  if (_Dst == (uint *)0x0) {
    return 8;
  }
  memset(_Dst,0,0xd90);
  *_Dst = 0xd90;
  local_50[0] = 0xd90;
  local_2c[0] = 0;
  local_30 = (uint *)0x0;
  iVar2 = AfdRasGetEntryProperties
                    (param_3,(STRSAFE_LPCWSTR)(param_4 + 4),_Dst,0xd90,local_50,(LPBYTE)0x0,0,
                     local_2c);
  if ((iVar2 == 0) || (iVar2 == 0x25b)) {
    if (local_2c[0] != 0) {
      local_30 = LocalAlloc(0x40,local_2c[0]);
      iVar2 = AfdRasGetEntryProperties
                        (param_3,(STRSAFE_LPCWSTR)(param_4 + 4),_Dst,0xd90,local_50,(LPBYTE)local_30
                         ,local_2c[0],local_2c);
      if (iVar2 != 0) {
        LocalFree(_Dst);
        _Dst = local_30;
        goto LAB_c0443f20;
      }
    }
  }
  else if (local_2c[0] != 0) {
LAB_c0443f20:
    LocalFree(_Dst);
    return 0x26f;
  }
  *param_8 = 0;
  local_48[0] = (int *)0x0;
  local_40 = param_6;
  local_3c = param_7;
  local_2c[1] = 0;
  local_38 = param_4;
  local_34 = _Dst;
  DVar3 = FUN_c0433b14(local_48);
  piVar1 = local_48[0];
  LocalFree(_Dst);
  LocalFree(local_30);
  if ((DVar3 == 0) && (piVar1 != (int *)0x0)) {
    *param_8 = piVar1;
    iVar2 = FUN_c043336c(piVar1);
    if (iVar2 != 0) {
      if (((piVar1[0x18b] & 0x1000000U) == 0) || (DVar3 = FUN_c0443c64((int)piVar1), DVar3 == 0)) {
        DVar3 = FUN_c043422c(piVar1);
      }
      FUN_c0433498(piVar1);
    }
  }
  return DVar3;
}



/* c0444058 FUN_c0444058 */

/* Boundary evidence: original MIPS .pdata c0444058..c0444073. Semantic name remains unreviewed. */

void FUN_c0444058(undefined4 param_1)

{
  EventModify(param_1,3);
  return;
}



/* c0444074 AfdRasHangUp */

/* Boundary evidence: original MIPS .pdata c0444074..c044416b. Semantic name remains unreviewed. */

int AfdRasHangUp(int *param_1)

{
  int iVar1;
  HANDLE hHandle;
  undefined4 uVar2;
  
                    /* 0x14074  9  AfdRasHangUp */
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 == 0) {
    iVar1 = 0x57;
  }
  else {
    uVar2 = 0;
    hHandle = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hHandle == (HANDLE)0x0) {
      iVar1 = 0xe;
    }
    else {
      param_1[1] = param_1[1] & 0xfffffffe;
      if (param_1[0x33b] != 0) {
        FUN_c043bef0(param_1[0x33b]);
        param_1[0x33b] = 0;
      }
      iVar1 = FUN_c0433914((int)param_1,-0x3fbbbfa8,hHandle,uVar2);
      if (iVar1 == 0) {
        WaitForSingleObject(hHandle,0xffffffff);
      }
      CloseHandle(hHandle);
    }
    FUN_c0433498(param_1);
  }
  return iVar1;
}



/* c044416c AfdRasEnumConnections */

/* Boundary evidence: original MIPS .pdata c044416c..c04442ff. Semantic name remains unreviewed. */

undefined4 AfdRasEnumConnections(int *param_1,uint param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  
                    /* 0x1416c  3  AfdRasEnumConnections */
  uVar1 = 0;
  if (((param_1 == (int *)0x0) || (param_3 == (int *)0x0)) || (param_4 == (int *)0x0)) {
    uVar1 = 0x57;
  }
  else if (*param_1 == 0x34) {
    uVar3 = param_2 / 0x34;
    *param_3 = 0;
    *param_4 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
    for (piVar2 = (int *)DAT_c044d8b0; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if (piVar2[0x1b] == 0) {
        if (uVar3 == 0) {
          uVar1 = 0x25b;
        }
        else {
          *param_4 = *param_4 + 1;
          *param_1 = 0x34;
          param_1[1] = (int)piVar2;
          wcscpy((wchar_t *)(param_1 + 2),(wchar_t *)(piVar2 + 0x1e));
          param_1 = param_1 + 0xd;
          uVar3 = uVar3 - 1;
        }
        *param_3 = *param_3 + 0x34;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
  }
  else {
    uVar1 = 0x278;
  }
  return uVar1;
}



/* c0444300 FUN_c0444300 */

/* Boundary evidence: original MIPS .pdata c0444300..c044430b. Semantic name remains unreviewed. */

undefined4 FUN_c0444300(void)

{
  return 1;
}



/* c044430c AfdRasGetConnectStatus */

/* Boundary evidence: original MIPS .pdata c044430c..c04443d7. Semantic name remains unreviewed. */

undefined4 AfdRasGetConnectStatus(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x1430c  5  AfdRasGetConnectStatus */
  uVar2 = 0;
  iVar1 = FUN_c043336c(param_1);
  if (iVar1 == 0) {
    uVar2 = 6;
  }
  else {
    *(int *)(param_2 + 4) = param_1[9];
    *(int *)(param_2 + 8) = param_1[10];
    wcscpy((wchar_t *)(param_2 + 0xc),(wchar_t *)(param_1 + 0x1db));
    wcscpy((wchar_t *)(param_2 + 0x2e),(wchar_t *)((int)param_1 + 0x78e));
    FUN_c0433498(param_1);
  }
  return uVar2;
}



/* c04443d8 FUN_c04443d8 */

/* Boundary evidence: original MIPS .pdata c04443d8..c04443e3. Semantic name remains unreviewed. */

undefined4 FUN_c04443d8(void)

{
  return 1;
}



/* c04443e4 FUN_c04443e4 */

/* Boundary evidence: original MIPS .pdata c04443e4..c04446cf. Semantic name remains unreviewed. */

undefined4 FUN_c04443e4(int *param_1,int param_2,uint *param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar4 = 0;
  if (param_4 == 0) {
    return 0x57;
  }
  iVar2 = FUN_c043336c(param_1);
  if (iVar2 == 0) {
    return 6;
  }
  if (param_2 == 0x8021) {
    iVar2 = *(int *)(param_1[0x2ac] + 0x24);
    uVar3 = *(uint *)(iVar2 + 0x20);
    uVar5 = *(uint *)(iVar2 + 0x30);
    if (*(int *)(*(int *)(iVar2 + 4) + 8) < 9) {
LAB_c044455c:
      uVar4 = 0x2da;
      goto LAB_c0444664;
    }
    if (0x27 < *param_3) {
      param_3[1] = param_1[10];
      wsprintfW((LPWSTR)(param_3 + 2),L"%u.%u.%u.%u",uVar3 >> 0x18,uVar3 >> 0x10 & 0xff,
                uVar3 >> 8 & 0xff,uVar3 & 0xff);
      if (0x47 < *param_3) {
        *(WCHAR *)(param_3 + 10) = L'\0';
        if (uVar5 != 0) {
          wsprintfW((LPWSTR)(param_3 + 10),L"%u.%u.%u.%u",uVar5 >> 0x18,uVar5 >> 0x10 & 0xff,
                    uVar5 >> 8 & 0xff,uVar5 & 0xff);
        }
        if ((0x4b < *param_3) &&
           (param_3[0x12] = (uint)(*(int *)(iVar2 + 0x18) != 0), 0x4f < *param_3)) {
          param_3[0x13] = (uint)(*(int *)(iVar2 + 0x28) != 0);
        }
      }
      goto LAB_c0444664;
    }
LAB_c044457c:
    uVar4 = 0x25b;
  }
  else {
    if (param_2 == 0x8057) {
      iVar2 = *(int *)(param_1[0x2ac] + 0x3c);
      if (*param_3 < 0x1c) goto LAB_c044457c;
      if (*(int *)(param_1[0x2ac] + 0x38) != 0) {
        if (8 < *(int *)(*(int *)(iVar2 + 4) + 8)) {
          param_3[1] = 0;
          param_3[2] = *(uint *)(iVar2 + 8);
          param_3[3] = *(uint *)(iVar2 + 0xc);
          param_3[4] = *(uint *)(iVar2 + 0x10);
          param_3[5] = *(uint *)(iVar2 + 0x14);
          uVar1 = *(undefined1 *)(iVar2 + 0x21);
          *(undefined1 *)(param_3 + 6) = *(undefined1 *)(iVar2 + 0x20);
          *(undefined1 *)((int)param_3 + 0x19) = uVar1;
          uVar1 = *(undefined1 *)(iVar2 + 0x23);
          *(undefined1 *)((int)param_3 + 0x1a) = *(undefined1 *)(iVar2 + 0x22);
          *(undefined1 *)((int)param_3 + 0x1b) = uVar1;
          goto LAB_c0444664;
        }
        goto LAB_c044455c;
      }
    }
    uVar4 = 0x2db;
  }
LAB_c0444664:
  FUN_c0433498(param_1);
  return uVar4;
}



/* c04446d0 FUN_c04446d0 */

/* Boundary evidence: original MIPS .pdata c04446d0..c04446db. Semantic name remains unreviewed. */

undefined4 FUN_c04446d0(void)

{
  return 1;
}



/* c04446dc FUN_c04446dc */

/* Boundary evidence: original MIPS .pdata c04446dc..c04448eb. Semantic name remains unreviewed. */

undefined4 FUN_c04446dc(int *param_1,int *param_2)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 auStack_58 [4];
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  uVar4 = 0;
  if (*param_2 == 0x3c) {
    iVar1 = FUN_c043336c(param_1);
    if (iVar1 == 0) {
      uVar4 = 6;
    }
    else {
      memset(param_2,0,0x3c);
      *param_2 = 0x3c;
      iVar1 = FUN_c0447390(param_1[0x2a9],auStack_58);
      if (iVar1 == 0) {
        param_2[1] = local_54;
        param_2[2] = local_50;
        param_2[3] = local_4c;
        param_2[4] = local_48;
        param_2[5] = local_44;
        param_2[6] = local_40;
        param_2[7] = local_3c;
        param_2[8] = local_38;
        param_2[9] = local_34;
        param_2[10] = local_30;
      }
      else {
        param_2[1] = param_1[0x2d6];
        param_2[2] = param_1[0x2d7];
        param_2[3] = param_1[0x2d8];
        param_2[4] = param_1[0x2d9];
      }
      param_2[0xb] = 100;
      uVar3 = param_1[0x2e1];
      if (uVar3 != 0) {
        if (uVar3 == 0) {
          trap(0x1c00);
        }
        param_2[0xb] = (uint)(param_1[0x2e3] * 100) / uVar3;
      }
      param_2[0xc] = 100;
      uVar3 = param_1[0x2e0];
      if (uVar3 != 0) {
        if (uVar3 == 0) {
          trap(0x1c00);
        }
        param_2[0xc] = (uint)(param_1[0x2e2] * 100) / uVar3;
      }
      FUN_c0446024(param_1[0x2a9],param_2 + 0xd);
      DVar2 = GetTickCount();
      param_2[0xe] = DVar2 - param_1[0x2d4];
      FUN_c0433498(param_1);
    }
  }
  else {
    uVar4 = 0x57;
  }
  return uVar4;
}



/* c04448ec FUN_c04448ec */

/* Boundary evidence: original MIPS .pdata c04448ec..c04448f7. Semantic name remains unreviewed. */

undefined4 FUN_c04448ec(void)

{
  return 1;
}



/* c04448f8 FUN_c04448f8 */

/* Boundary evidence: original MIPS .pdata c04448f8..c044497b. Semantic name remains unreviewed. */

int FUN_c04448f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,HLOCAL param_4,
                uint param_5,size_t *param_6)

{
  int iVar1;
  int *local_18;
  undefined4 local_14;
  
  iVar1 = FUN_c0447cf8(param_1,param_2,&local_18,&local_14);
  if (iVar1 == 0) {
    iVar1 = FUN_c0449460((SIZE_T)local_18,local_14,param_3,(wchar_t *)0x0,param_4,param_5,param_6);
    FUN_c0447918(local_18);
  }
  return iVar1;
}



/* c044497c FUN_c044497c */

/* Boundary evidence: original MIPS .pdata c044497c..c0444ba7. Semantic name remains unreviewed. */

int FUN_c044497c(STRSAFE_LPCWSTR param_1,undefined4 param_2,wchar_t *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  STRSAFE_LPWSTR _Source;
  undefined4 uVar3;
  int *local_dbc;
  undefined4 local_db8;
  uint local_db4 [4];
  undefined4 local_da4;
  wchar_t awStack_da0 [11];
  wchar_t awStack_d8a [927];
  wchar_t awStack_64c [17];
  undefined1 auStack_62a [1546];
  uint local_20;
  
  local_20 = DAT_c044d82c;
  local_db4[0] = 0xd90;
  if (((param_4 == 0) || (param_3 == (wchar_t *)0x0)) || (param_1 == (STRSAFE_LPCWSTR)0x0)) {
    iVar1 = 0x57;
  }
  else {
    local_db4[1] = 0xd90;
    iVar1 = AfdRasGetEntryProperties
                      (0,param_1,local_db4 + 1,0xd90,local_db4,(LPBYTE)0x0,0,(uint *)0x0);
    if (iVar1 == 0) {
      iVar2 = wcscmp(awStack_64c,L"modem");
      if (iVar2 == 0) {
        iVar2 = FUN_c0447cf8(auStack_62a,awStack_64c,&local_dbc,&local_db8);
        if (iVar2 == 0) {
          uVar3 = 0;
          if ((local_db4[2] & 1) == 0) {
            if ((local_db4[2] & 0x20000) != 0) {
              uVar3 = 4;
            }
          }
          else {
            uVar3 = 8;
          }
          _Source = FUN_c04483b8((int)local_dbc,local_db8,local_da4,awStack_da0,awStack_d8a,0,uVar3)
          ;
          FUN_c0447918(local_dbc);
          if (_Source == (STRSAFE_LPWSTR)0x0) {
            iVar1 = 0x272;
          }
          else {
            wcsncpy(param_3,_Source,param_4 >> 1);
            LocalFree(_Source);
          }
        }
        else {
          iVar1 = 0x260;
        }
      }
      else {
        iVar2 = wcscmp(awStack_64c,L"vpn");
        if (iVar2 == 0) {
          wcsncpy(param_3,awStack_d8a,param_4 >> 1);
        }
        else {
          *param_3 = L'\0';
        }
      }
    }
  }
  FUN_c0449d30(local_20);
  return iVar1;
}



/* c0444ba8 FUN_c0444ba8 */

/* Boundary evidence: original MIPS .pdata c0444ba8..c0444bb3. Semantic name remains unreviewed. */

undefined4 FUN_c0444ba8(void)

{
  return 1;
}



/* c0444bb4 FUN_c0444bb4 */

/* Boundary evidence: original MIPS .pdata c0444bb4..c0444bbf. Semantic name remains unreviewed. */

undefined4 FUN_c0444bb4(void)

{
  return 1;
}



/* c0444bc0 FUN_c0444bc0 */

int * FUN_c0444bc0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (param_2 != 0) {
    piVar1 = *(int **)(param_1 + 0xcdc);
    piVar2 = piVar1 + *(int *)(param_1 + 0xce4) * 3;
    for (; piVar1 < piVar2; piVar1 = piVar1 + 3) {
      if (*piVar1 == param_2) {
        return piVar1;
      }
    }
  }
  return (int *)0x0;
}



/* c0444c0c FUN_c0444c0c */

/* Boundary evidence: original MIPS .pdata c0444c0c..c0444c37. Semantic name remains unreviewed. */

undefined4 FUN_c0444c0c(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 4) + 8);
  uVar1 = 0x57;
  if (pcVar2 != (code *)0x0) {
    uVar1 = (*pcVar2)(*(undefined4 *)(param_1 + 8));
  }
  return uVar1;
}



/* c0444c38 FUN_c0444c38 */

/* Boundary evidence: original MIPS .pdata c0444c38..c0444c63. Semantic name remains unreviewed. */

undefined4 FUN_c0444c38(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 4) + 0xc);
  uVar1 = 0x57;
  if (pcVar2 != (code *)0x0) {
    uVar1 = (*pcVar2)(*(undefined4 *)(param_1 + 8));
  }
  return uVar1;
}



/* c0444c64 FUN_c0444c64 */

/* Boundary evidence: original MIPS .pdata c0444c64..c0444c8f. Semantic name remains unreviewed. */

undefined4 FUN_c0444c64(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 4) + 0x10);
  uVar1 = 0x57;
  if (pcVar2 != (code *)0x0) {
    uVar1 = (*pcVar2)(*(undefined4 *)(param_1 + 8));
  }
  return uVar1;
}



/* c0444c90 FUN_c0444c90 */

/* Boundary evidence: original MIPS .pdata c0444c90..c0444d8f. Semantic name remains unreviewed. */

undefined4 FUN_c0444c90(int *param_1,int *param_2,uint param_3,undefined *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0x57;
  if ((((3 < param_3) && (param_2 != (int *)0x0)) && (param_1 != (int *)0x0)) &&
     (iVar1 = FUN_c043336c(param_1), iVar1 != 0)) {
    FUN_c04335a8((int)param_1);
    piVar2 = FUN_c0444bc0((int)param_1,*param_2);
    if (piVar2 != (int *)0x0) {
      uVar3 = (*(code *)param_4)(piVar2);
    }
    FUN_c04335c4((int)param_1);
    FUN_c0433498(param_1);
  }
  return uVar3;
}



/* c0444d90 FUN_c0444d90 */

/* Boundary evidence: original MIPS .pdata c0444d90..c0444d9b. Semantic name remains unreviewed. */

undefined4 FUN_c0444d90(void)

{
  return 1;
}



/* c0444d9c FUN_c0444d9c */

/* Boundary evidence: original MIPS .pdata c0444d9c..c0444f1f. Semantic name remains unreviewed. */

undefined4
FUN_c0444d9c(int *param_1,int *param_2,uint param_3,int *param_4,undefined4 param_5,
            undefined4 *param_6,int param_7)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0x57;
  if ((((0x13 < param_3) && (param_2 != (int *)0x0)) && (param_1 != (int *)0x0)) &&
     (iVar1 = FUN_c043336c(param_1), iVar1 != 0)) {
    FUN_c04335a8((int)param_1);
    iVar1 = *param_2;
    piVar2 = FUN_c0444bc0((int)param_1,iVar1);
    if (piVar2 != (int *)0x0) {
      if (param_7 == 0) {
        if (*(code **)(piVar2[1] + 0x18) != (code *)0x0) {
          uVar3 = (**(code **)(piVar2[1] + 0x18))(piVar2[2],param_2,param_3);
        }
      }
      else if (*(int *)(piVar2[1] + 0x14) != 0) {
        *param_4 = iVar1;
        param_4[1] = param_2[1];
        *param_6 = param_5;
        uVar3 = (**(code **)(piVar2[1] + 0x14))(piVar2[2],param_4);
      }
    }
    FUN_c04335c4((int)param_1);
    FUN_c0433498(param_1);
  }
  return uVar3;
}



/* c0444f20 FUN_c0444f20 */

/* Boundary evidence: original MIPS .pdata c0444f20..c0444f2b. Semantic name remains unreviewed. */

undefined4 FUN_c0444f20(void)

{
  return 1;
}



/* c0444f2c AfdRasIOControl */

/* Boundary evidence: original MIPS .pdata c0444f2c..c04454cf. Semantic name remains unreviewed. */

int AfdRasIOControl(int *param_1,int param_2,uint *param_3,uint param_4,uint *param_5,uint param_6,
                   uint *param_7)

{
  int iVar1;
  STRSAFE_LPCWSTR pwVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  STRSAFE_LPCWSTR local_38;
  DWORD local_34;
  wchar_t *local_30;
  uint local_2c;
  
                    /* 0x14f2c  10  AfdRasIOControl */
  local_2c = 0xc;
  iVar5 = 0x57;
  local_38 = (STRSAFE_LPCWSTR)0x0;
  local_30 = (wchar_t *)0x0;
  local_34 = param_6;
  uVar6 = param_4;
  puVar7 = param_3;
  if (DAT_c044d840 == 0) {
    iVar5 = 0x426;
    goto LAB_c0445450;
  }
  if (7 < param_2) {
    if ((param_2 < 0xc) ||
       (((0x18 < param_2 && (param_2 != 0x1b)) && ((param_2 < 0x1d || (0x22 < param_2))))))
    goto LAB_c0444fd8;
LAB_c0445070:
    uVar4 = 4;
    local_2c = 4;
LAB_c0444fdc:
    param_4 = local_2c;
    if (((param_3 == (uint *)0x0) || (uVar6 == 0)) ||
       (iVar5 = CeAllocDuplicateBuffer(&local_38,param_3,uVar6,uVar4), param_4 = local_2c,
       iVar5 == 0)) goto LAB_c04450c4;
LAB_c0445008:
    if (iVar5 == -0x7ff8fff2) {
      iVar5 = 0xe;
      goto LAB_c0445450;
    }
    goto switchD_c0445118_caseD_0;
  }
  if (param_2 == 7) {
    if (param_5 == (uint *)0x0) goto LAB_c0445450;
    param_6 = *param_5;
    goto LAB_c0445070;
  }
  if (param_2 == 4) {
    if (param_5 == (uint *)0x0) goto LAB_c0445450;
    param_4 = *param_5;
    param_6 = 4;
LAB_c0444fd8:
    uVar4 = 0xc;
    uVar6 = param_4;
    goto LAB_c0444fdc;
  }
  if (param_2 != 5) {
    if (param_2 == 6) goto LAB_c0445070;
    goto LAB_c0444fd8;
  }
  uVar6 = 0;
  if ((param_3 == (uint *)0x0) || (param_5 = param_3, puVar7 = (uint *)0x0, param_7 == (uint *)0x0))
  goto LAB_c0445450;
  param_6 = *param_7;
  local_34 = param_6;
LAB_c04450c4:
  if (((param_5 != (uint *)0x0) && (param_6 != 0)) &&
     (iVar5 = CeAllocDuplicateBuffer(&local_30,param_5,param_6,0xc), iVar5 != 0)) goto LAB_c0445008;
  switch(param_2) {
  default:
    goto switchD_c0445118_caseD_0;
  case 3:
    if (((0x3b < param_6) && (local_30 != (wchar_t *)0x0)) && (param_1 != (int *)0x0)) {
      iVar5 = FUN_c04446dc(param_1,(int *)local_30);
      local_34 = 0x3c;
      break;
    }
    goto switchD_c0445118_caseD_0;
  case 4:
    iVar5 = FUN_c0447d7c((uint *)local_38,0,(uint *)local_30,&local_34);
    break;
  case 5:
    iVar5 = FUN_c04443e4(param_1,param_4,(uint *)local_30,(int)&local_34);
    break;
  case 6:
    iVar5 = FUN_c044497c(local_38,uVar6,local_30,param_6);
    break;
  case 7:
    if (((0x12f < uVar6) && (local_38 != (STRSAFE_LPCWSTR)0x0)) && (local_30 != (wchar_t *)0x0)) {
      pwVar2 = local_38 + 0x96;
      if (*(uint *)(local_38 + 0x94) == 0) {
        pwVar2 = (STRSAFE_LPCWSTR)0x0;
      }
      iVar5 = FUN_c04448f8(local_38,local_38 + 0x81,*(undefined4 *)(local_38 + 0x92),pwVar2,
                           *(uint *)(local_38 + 0x94),(size_t *)local_30);
      break;
    }
switchD_c0445118_caseD_0:
    iVar5 = 0x57;
    break;
  case 8:
    iVar5 = FUN_c044a3fc();
    break;
  case 9:
  case 10:
    iVar5 = FUN_c044a3fc();
    break;
  case 0xb:
    iVar5 = FUN_c044a3fc();
    break;
  case 0xc:
    iVar5 = FUN_c044a3fc();
    break;
  case 0xd:
    iVar5 = FUN_c044a3fc();
    break;
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x1b:
    iVar5 = FUN_c044a3fc();
    break;
  case 0x13:
    iVar5 = FUN_c044a3fc();
    break;
  case 0x14:
    iVar5 = FUN_c044a3fc();
    break;
  case 0x15:
    iVar5 = FUN_c043b23c(0,0,local_38,(LPBYTE)local_30,&local_34);
    break;
  case 0x16:
    iVar5 = FUN_c043b32c(0,0,local_38,(BYTE *)local_30,param_6);
    break;
  case 0x17:
    iVar5 = FUN_c043b264(0,local_38,(LPBYTE)local_30,&local_34);
    break;
  case 0x18:
    iVar5 = FUN_c043b354(0,local_38,(BYTE *)local_30,param_6);
    break;
  case 0x1c:
    iVar5 = FUN_c044a3fc();
    break;
  case 0x1d:
    iVar5 = FUN_c044a3fc();
    break;
  case 0x1e:
    pcVar3 = FUN_c0444c0c;
    goto LAB_c044541c;
  case 0x1f:
    pcVar3 = FUN_c0444c38;
    goto LAB_c044541c;
  case 0x20:
    pcVar3 = FUN_c0444c64;
LAB_c044541c:
    iVar5 = FUN_c0444c90(param_1,(int *)local_38,uVar6,pcVar3);
    break;
  case 0x21:
    iVar5 = FUN_c0444d9c(param_1,(int *)local_38,uVar6,(int *)local_30,param_6,&local_34,1);
    break;
  case 0x22:
    iVar5 = FUN_c0444d9c(param_1,(int *)local_38,uVar6,(int *)local_30,param_6,&local_34,0);
  }
LAB_c0445450:
  CeFreeDuplicateBuffer(local_38,puVar7,uVar6,local_2c);
  iVar1 = CeFreeDuplicateBuffer(local_30,param_5,param_6,0xc);
  if (iVar1 == -0x7ff8fffb) {
    iVar5 = 0x57;
  }
  if (param_7 != (uint *)0x0) {
    *param_7 = local_34;
  }
  return iVar5;
}



/* c04454d0 FUN_c04454d0 */

undefined4 FUN_c04454d0(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0xc0012009) {
    if (param_1 == 0xc0012008) {
      return 0x25a;
    }
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 == 0x40010007) {
      return 0x26a;
    }
    if (param_1 != 0xc0000001) {
      if (param_1 == 0xc000009a) {
        return 8;
      }
      if ((param_1 != 0xc0010017) && (param_1 == 0xc0012002)) {
        return 0x279;
      }
    }
LAB_c0445550:
    uVar1 = 0x27b;
  }
  else {
    if (param_1 == 0xc0012012) {
      return 0x299;
    }
    if ((param_1 != 0xc0012015) && (param_1 != 0xc0012016)) {
      if (param_1 == 0xc0012018) {
        return 0x279;
      }
      if (param_1 == 0xc001201d) {
        return 0x25c;
      }
      if (param_1 != 0xc001201e) goto LAB_c0445550;
    }
    uVar1 = 0x29a;
  }
  return uVar1;
}



/* c04455ec FUN_c04455ec */

/* Boundary evidence: original MIPS .pdata c04455ec..c044567f. Semantic name remains unreviewed. */

int FUN_c04455ec(void)

{
  int iVar1;
  
  DAT_c044d95c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c044d940);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
  iVar1 = FUN_c0446210();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    CloseHandle(DAT_c044d95c);
  }
  return iVar1;
}



/* c0445680 FUN_c0445680 */

void FUN_c0445680(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = *(undefined4 *)(param_1 + 0x160);
  *param_3 = *(undefined4 *)(param_1 + 0x164);
  return;
}



/* c0445694 FUN_c0445694 */

/* Boundary evidence: original MIPS .pdata c0445694..c04456af. Semantic name remains unreviewed. */

void FUN_c0445694(undefined4 param_1)

{
  EventModify(param_1,3);
  return;
}



/* c04456b0 FUN_c04456b0 */

/* Boundary evidence: original MIPS .pdata c04456b0..c04456fb. Semantic name remains unreviewed. */

undefined4
FUN_c04456b0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  
  *param_2 = 0x5dc;
  uVar2 = 0;
  pvVar1 = FUN_c0434330(0x5dc,param_2,param_3,param_4);
  *param_1 = pvVar1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0x266;
  }
  return uVar2;
}



/* c04456fc FUN_c04456fc */

/* Boundary evidence: original MIPS .pdata c04456fc..c044571b. Semantic name remains unreviewed. */

undefined4 FUN_c04456fc(int param_1)

{
  FUN_c04343a4(param_1,0x5dc);
  return 0;
}



/* c044571c FUN_c044571c */

/* Boundary evidence: original MIPS .pdata c044571c..c04457db. Semantic name remains unreviewed. */

DWORD FUN_c044571c(int param_1,int param_2,uint param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  uint uVar3;
  DWORD local_28 [2];
  
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      BVar1 = WriteFile(*(HANDLE *)(param_1 + 0x1d4),(LPCVOID)(uVar3 + param_2),param_3 - uVar3,
                        local_28,(LPOVERLAPPED)0x0);
      if ((BVar1 == 0) || (local_28[0] == 0)) {
        DVar2 = GetLastError();
        return DVar2;
      }
      uVar3 = local_28[0] + uVar3;
    } while (uVar3 < param_3);
  }
  return 0;
}



/* c04457dc FUN_c04457dc */

/* Boundary evidence: original MIPS .pdata c04457dc..c0445837. Semantic name remains unreviewed. */

DWORD FUN_c04457dc(int param_1,LPVOID param_2,LPDWORD param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  BVar1 = ReadFile(*(HANDLE *)(param_1 + 0x1d4),param_2,0x5dc,param_3,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  return DVar2;
}



/* c0445838 FUN_c0445838 */

/* Boundary evidence: original MIPS .pdata c0445838..c04458bb. Semantic name remains unreviewed. */

undefined4 FUN_c0445838(int param_1)

{
  int iVar1;
  DWORD aDStack_18 [2];
  
  iVar1 = WaitCommEvent(*(HANDLE *)(param_1 + 0x1d4),aDStack_18,(LPOVERLAPPED)0x0);
  while (iVar1 == 1) {
    EventModify(*(undefined4 *)(param_1 + 0x1d8),3);
    Sleep(0x32);
    iVar1 = WaitCommEvent(*(HANDLE *)(param_1 + 0x1d4),aDStack_18,(LPOVERLAPPED)0x0);
  }
  return 0;
}



/* c04458bc FUN_c04458bc */

/* Boundary evidence: original MIPS .pdata c04458bc..c04459cb. Semantic name remains unreviewed. */

DWORD FUN_c04458bc(LPVOID param_1,undefined4 param_2,undefined4 *param_3,DWORD param_4,
                  undefined4 param_5)

{
  BOOL BVar1;
  HANDLE pvVar2;
  DWORD DVar3;
  DWORD aDStack_38 [2];
  _COMMTIMEOUTS local_30;
  
  BVar1 = SetCommMask(*(HANDLE *)((int)param_1 + 0x1d4),0x2021);
  if ((BVar1 != 0) &&
     (BVar1 = GetCommTimeouts(*(HANDLE *)((int)param_1 + 0x1d4),&local_30), BVar1 != 0)) {
    local_30.ReadTotalTimeoutMultiplier = 0;
    local_30.ReadTotalTimeoutConstant = 0;
    local_30.WriteTotalTimeoutMultiplier = 2;
    local_30.WriteTotalTimeoutConstant = 500;
    local_30.ReadIntervalTimeout = param_4;
    BVar1 = SetCommTimeouts(*(HANDLE *)((int)param_1 + 0x1d4),&local_30);
    if (BVar1 != 0) {
      *param_3 = 0;
      *(undefined4 *)((int)param_1 + 0x1e4) = 0x5dc;
      *(undefined4 *)((int)param_1 + 0x1e0) = param_2;
      *(undefined4 *)((int)param_1 + 0x1e8) = 0;
      *(undefined4 *)((int)param_1 + 0x1d8) = param_5;
      if (*(int *)((int)param_1 + 0x1dc) != 0) {
        return 0;
      }
      pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0445838,param_1,0,aDStack_38);
      *(HANDLE *)((int)param_1 + 0x1dc) = pvVar2;
      if (pvVar2 != (HANDLE)0x0) {
        return 0;
      }
    }
  }
  DVar3 = GetLastError();
  return DVar3;
}



/* c04459cc FUN_c04459cc */

/* Boundary evidence: original MIPS .pdata c04459cc..c0445bcf. Semantic name remains unreviewed. */

undefined4 FUN_c04459cc(int *param_1,undefined4 param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  HMODULE hLibModule;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *local_230 [2];
  wchar_t awStack_228 [262];
  uint local_1c;
  
  local_1c = DAT_c044d82c;
  iVar4 = *param_1;
  iVar1 = FUN_c0448c34(param_1,4,L"comm/datamodem",local_230);
  if (iVar1 == 0) {
    param_1[0x75] = *(int *)(local_230[0][5] + (int)local_230[0]);
    FUN_c04343a4((int)local_230[0],*local_230[0]);
    wcscpy(awStack_228,(wchar_t *)(iVar4 + 0x890));
    pwVar2 = wcschr(awStack_228,L'|');
    if (pwVar2 == (wchar_t *)0x0) {
      iVar1 = FUN_c0432908((HKEY)0x80000002,L"Comm\\PPP\\Parms",L"CustomScriptDllPath",1);
      if (iVar1 != 1) goto LAB_c0445a1c;
    }
    else {
      *pwVar2 = L'\0';
    }
    hLibModule = LoadLibraryW(awStack_228);
    if (hLibModule != (HMODULE)0x0) {
      pcVar3 = (code *)GetProcAddressW(hLibModule,L"RasCustomScriptExecute");
      if (pcVar3 == (code *)0x0) {
        uVar5 = 0x80004005;
      }
      else {
        uVar5 = (*pcVar3)(param_1,0,iVar4 + 0x78,FUN_c04456b0,FUN_c04456fc,FUN_c044571c,FUN_c04458bc
                          ,FUN_c04457dc,0,param_2,0);
        SetCommMask((HANDLE)param_1[0x75],0);
        if ((HANDLE)param_1[0x77] != (HANDLE)0x0) {
          WaitForSingleObject((HANDLE)param_1[0x77],0xffffffff);
          CloseHandle((HANDLE)param_1[0x77]);
          param_1[0x77] = 0;
        }
        param_1[0x76] = 0;
        param_1[0x78] = 0;
        param_1[0x79] = 0;
        param_1[0x7a] = 0;
      }
      FreeLibrary(hLibModule);
      goto LAB_c0445ba4;
    }
  }
LAB_c0445a1c:
  uVar5 = 0x80004005;
LAB_c0445ba4:
  param_1[0x75] = 0;
  FUN_c0449d30(local_1c);
  return uVar5;
}



/* c0445bd0 FUN_c0445bd0 */

/* Boundary evidence: original MIPS .pdata c0445bd0..c0445f13. Semantic name remains unreviewed. */

int FUN_c0445bd0(int *param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  STRSAFE_LPWSTR hMem;
  HANDLE hHandle;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  wchar_t *_Str1;
  int iVar5;
  
  _Str1 = (wchar_t *)(param_2 + 0x50);
  iVar5 = *param_1;
  iVar4 = 0;
  uVar3 = 0;
  iVar1 = wcscmp(_Str1,L"PPPoE");
  if (iVar1 == 0) {
    param_1[100] = 1;
  }
  iVar1 = wcscmp(_Str1,L"vpn");
  if ((iVar1 == 0) || (iVar1 = wcscmp(_Str1,L"PPPoE"), iVar1 == 0)) {
    hMem = (STRSAFE_LPWSTR)((int)param_2 + 0x22);
  }
  else {
    FUN_c04335c4(iVar5);
    uVar2 = 0;
    if ((*param_2 & 1) == 0) {
      if ((*param_2 & 0x20000) != 0) {
        uVar2 = 4;
      }
    }
    else {
      uVar2 = 8;
    }
    hMem = FUN_c04483b8(param_1[1],param_1[2],param_2[2],(wchar_t *)(param_2 + 3),
                        (wchar_t *)((int)param_2 + 0x22),1,uVar2);
    FUN_c04335a8(iVar5);
    if (hMem == (STRSAFE_LPWSTR)0x0) {
      iVar1 = 0x2ed;
      goto LAB_c0445da0;
    }
  }
  iVar1 = iVar4;
  if (*(int *)(*param_1 + 100) == 0) {
    FUN_c04335c4(iVar5);
    uVar3 = FUN_c044860c(param_1[1],param_1[2],(undefined4 *)(*param_1 + 100),
                         (size_t *)(*param_1 + 0x68));
    FUN_c04335a8(iVar5);
    if (uVar3 == 0) goto LAB_c0445d24;
LAB_c0445d38:
    if (((uVar3 != 0xc00000bb) && (uVar3 != 0x10001)) && (uVar3 != 0xc0010017)) goto LAB_c0445da0;
  }
  else {
LAB_c0445d24:
    uVar3 = FUN_c0448758(param_1);
    if (uVar3 != 0) goto LAB_c0445d38;
  }
  uVar3 = FUN_c044883c(param_1);
  if ((uVar3 == 0) && (iVar1 = param_1[0x4f], iVar1 == 0)) {
    uVar3 = FUN_c04488d8(param_1,hMem);
    iVar1 = iVar4;
  }
LAB_c0445da0:
  if (hMem != (STRSAFE_LPWSTR)((int)param_2 + 0x22)) {
    LocalFree(hMem);
  }
  if (uVar3 != 0) {
    iVar1 = FUN_c04454d0(uVar3);
  }
  if (iVar1 == 0) {
    FUN_c04335c4(iVar5);
    WaitForSingleObject((HANDLE)param_1[0x4e],0xffffffff);
    FUN_c04335a8(iVar5);
    if (param_1[0x4f] == 0) {
      if ((*(uint *)(iVar5 + 0x62c) & 0x80000000) != 0) {
        FUN_c0433050(*param_1,0x1000,0);
        iVar1 = FUN_c04459cc(param_1,param_3);
        param_1[0x4f] = iVar1;
      }
      if (param_1[0x4f] == 0) {
        FUN_c0433050(*param_1,3,0);
      }
      FUN_c0448c34(param_1,4,L"ndis",(undefined4 *)0x0);
    }
    if (param_1[0x4f] != 0) {
      uVar2 = 0;
      hHandle = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      FUN_c04491c0(param_1,FUN_c0445694,hHandle,uVar2);
      if (hHandle != (HANDLE)0x0) {
        FUN_c04335c4(iVar5);
        WaitForSingleObject(hHandle,0xffffffff);
        FUN_c04335a8(iVar5);
        CloseHandle(hHandle);
      }
    }
    iVar1 = param_1[0x4f];
  }
  return iVar1;
}



/* c0445f14 FUN_c0445f14 */

/* Boundary evidence: original MIPS .pdata c0445f14..c0445f3f. Semantic name remains unreviewed. */

void FUN_c0445f14(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  (**(code **)(iVar1 + 0x68))(iVar1);
  return;
}



/* c0445f40 FUN_c0445f40 */

/* Boundary evidence: original MIPS .pdata c0445f40..c0445f67. Semantic name remains unreviewed. */

void FUN_c0445f40(int param_1)

{
  *(undefined4 *)(param_1 + 0x13c) = 0x277;
  EventModify(*(undefined4 *)(param_1 + 0x138),3);
  return;
}



/* c0445f68 FUN_c0445f68 */

/* Boundary evidence: original MIPS .pdata c0445f68..c0445f83. Semantic name remains unreviewed. */

void FUN_c0445f68(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c04491c0(param_1,param_2,param_3,param_4);
  return;
}



/* c0445f84 FUN_c0445f84 */

/* Boundary evidence: original MIPS .pdata c0445f84..c0445f9f. Semantic name remains unreviewed. */

void FUN_c0445f84(int *param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c04492b4(param_1,param_2,param_3,param_4);
  return;
}



/* c0445fa0 FUN_c0445fa0 */

/* Boundary evidence: original MIPS .pdata c0445fa0..c0446023. Semantic name remains unreviewed. */

void FUN_c0445fa0(int param_1)

{
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    FUN_c0447918(*(int **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  CloseHandle(*(HANDLE *)(param_1 + 0x138));
  CloseHandle(*(HANDLE *)(param_1 + 0x1bc));
  NdisFreeSpinLock(param_1 + 0x17c);
  FUN_c04343a4(*(int *)(param_1 + 0x168),*(undefined4 *)(param_1 + 0x16c));
  FUN_c04343a4(param_1,0x230);
  return;
}



/* c0446024 FUN_c0446024 */

void FUN_c0446024(int param_1,int *param_2)

{
  *param_2 = *(int *)(param_1 + 0x1a4) * 100;
  return;
}



/* c044603c FUN_c044603c */

/* Boundary evidence: original MIPS .pdata c044603c..c044620f. Semantic name remains unreviewed. */

int FUN_c044603c(undefined4 param_1,undefined4 *param_2,STRSAFE_LPCWSTR param_3,
                STRSAFE_LPCWSTR param_4)

{
  undefined4 *puVar1;
  int iVar2;
  HANDLE pvVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int local_20 [2];
  
  puVar1 = FUN_c0434330(0x230,param_2,param_3,param_4);
  if (puVar1 == (undefined4 *)0x0) {
LAB_c04461ec:
    iVar2 = 8;
  }
  else {
    *puVar1 = param_1;
    puVar1[0x70] = 0;
    puVar1[0x71] = 1;
    puVar1[0x72] = 0;
    puVar1[0x73] = 1;
    puVar1[0x7b] = 0;
    puVar1[0x74] = 1;
    StringCchCopyW((STRSAFE_LPWSTR)(puVar1 + 3),0x81,param_3);
    StringCchCopyW((STRSAFE_LPWSTR)((int)puVar1 + 0x10e),0x11,param_4);
    puVar8 = puVar1 + 1;
    puVar1[0x4d] = 0xffffffff;
    puVar1[0x4c] = 0xffffffff;
    iVar2 = FUN_c0447cf8(param_3,param_4,puVar8,puVar1 + 2);
    if (iVar2 == 0) {
      piVar4 = (int *)*puVar8;
      if (piVar4[8] == 0) {
        puVar1[0x65] = 0;
        puVar1[0x66] = 0;
        puVar1[0x67] = 0;
        FUN_c04466d4(local_20,(int)piVar4,0,0x4010107,puVar1 + 0x50,0x28);
        if (local_20[0] == 0) {
          pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
          uVar7 = 0;
          uVar6 = 0;
          uVar5 = 1;
          puVar1[0x4e] = pvVar3;
          pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
          puVar1[0x6f] = pvVar3;
          if ((puVar1[0x4e] != 0) && (pvVar3 != (HANDLE)0x0)) {
            NdisAllocateSpinLock(puVar1 + 0x5f);
            local_20[0] = FUN_c04474e8((int)puVar1,uVar5,uVar6,uVar7);
            if (local_20[0] != 0) {
              FUN_c0445fa0((int)puVar1);
              return local_20[0];
            }
            *param_2 = puVar1;
            return 0;
          }
          goto LAB_c04461ec;
        }
        piVar4 = (int *)*puVar8;
      }
      FUN_c0447918(piVar4);
    }
    FUN_c04343a4((int)puVar1,0x230);
    iVar2 = 0x260;
  }
  return iVar2;
}



/* c0446210 FUN_c0446210 */

/* Boundary evidence: original MIPS .pdata c0446210..c0446257. Semantic name remains unreviewed. */

undefined4 FUN_c0446210(void)

{
  undefined4 uVar1;
  int local_10 [2];
  
  NdisRegisterProtocol(local_10,&DAT_c044d954,&DAT_c044d7dc,0x4c);
  uVar1 = 0x25f;
  if (local_10[0] == 0) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0446258 FUN_c0446258 */

/* Boundary evidence: original MIPS .pdata c0446258..c0446317. Semantic name remains unreviewed. */

void FUN_c0446258(int param_1)

{
  size_t sVar1;
  uint uVar2;
  wchar_t *_Str;
  int iVar3;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    NdisCompleteUnbindAdapter();
  }
  uVar2 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar3 = 0;
    do {
      LocalFree(*(HLOCAL *)(*(int *)(param_1 + 0x18) + iVar3 + 4));
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 0xc;
    } while (uVar2 < *(uint *)(param_1 + 0x14));
  }
  FUN_c04343a4(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x14) * 0xc);
  _Str = *(wchar_t **)(param_1 + 8);
  sVar1 = wcslen(_Str);
  FUN_c04343a4((int)_Str,(sVar1 + 1) * 2);
  FUN_c04343a4(param_1,0x28);
  return;
}



/* c0446318 FUN_c0446318 */

/* Boundary evidence: original MIPS .pdata c0446318..c0446397. Semantic name remains unreviewed. */

void FUN_c0446318(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0xc);
  while (piVar1 = (int *)*piVar2, piVar1 != piVar2) {
    *(int **)(*piVar1 + 4) = piVar2;
    *piVar2 = *piVar1;
    FUN_c04335c4(param_1);
    VEMSendComplete(*(undefined4 *)(param_1 + 8),piVar1 + -8,0x40010007);
    FUN_c04335a8(param_1);
  }
  return;
}



/* c0446398 FUN_c0446398 */

/* Boundary evidence: original MIPS .pdata c0446398..c0446443. Semantic name remains unreviewed. */

void FUN_c0446398(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0xc);
  while (((int *)*piVar3 != piVar3 && (iVar1 = FUN_c04476cc(*(int *)(param_1 + 0xaa4)), iVar1 != 0))
        ) {
    piVar2 = (int *)*piVar3;
    *(int **)(*piVar2 + 4) = piVar3;
    *piVar3 = *piVar2;
    iVar1 = FUN_c0434924(param_1,(int)piVar2,iVar1);
    FUN_c04335c4(param_1);
    VEMSendComplete(*(undefined4 *)(param_1 + 8),piVar2 + -8,iVar1);
    FUN_c04335a8(param_1);
  }
  return;
}



/* c0446444 FUN_c0446444 */

/* Boundary evidence: original MIPS .pdata c0446444..c04464b7. Semantic name remains unreviewed. */

void FUN_c0446444(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x18);
  piVar1 = FUN_c04334cc(iVar2);
  if (piVar1 != (int *)0x0) {
    FUN_c04476a0(iVar2,param_2);
    FUN_c04335a8((int)piVar1);
    FUN_c0446398((int)piVar1);
    FUN_c04335c4((int)piVar1);
    FUN_c0433498(piVar1);
  }
  return;
}



/* c04464b8 FUN_c04464b8 */

/* Boundary evidence: original MIPS .pdata c04464b8..c0446557. Semantic name remains unreviewed. */

void FUN_c04464b8(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x68) == 0) {
    *(undefined4 *)(param_1 + 0x5c) = param_2;
    NdisSetEvent(param_1 + 100);
  }
  else {
    if (*(int *)(param_1 + 0x60) != 0) {
      FUN_c04335a8(*(int *)(param_1 + 0x60));
    }
    (**(code **)(param_1 + 0x68))(param_1,*(undefined4 *)(param_1 + 0x6c),param_2);
    if (*(int *)(param_1 + 0x60) != 0) {
      FUN_c04335c4(*(int *)(param_1 + 0x60));
      FUN_c0433498(*(int **)(param_1 + 0x60));
    }
    FUN_c04343a4(param_1,0x70);
  }
  return;
}



/* c0446558 FUN_c0446558 */

/* Boundary evidence: original MIPS .pdata c0446558..c04465b3. Semantic name remains unreviewed. */

void FUN_c0446558(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_c044788c((int)param_1);
  if (iVar1 != 0) {
    FUN_c04464b8(param_2,param_3);
    FUN_c0447918(param_1);
  }
  return;
}



/* c04465b4 FUN_c04465b4 */

/* Boundary evidence: original MIPS .pdata c04465b4..c04466d3. Semantic name remains unreviewed. */

void FUN_c04465b4(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,int param_8,undefined4 param_9,undefined4 *param_10)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = -0x3fffff66;
  pvVar1 = FUN_c0434330(0x70,param_2,param_3,param_4);
  if (pvVar1 != (void *)0x0) {
    *(int *)((int)pvVar1 + 0x10) = param_3;
    *(undefined4 *)((int)pvVar1 + 0x14) = param_4;
    if (param_3 == 0) {
      *(undefined4 *)((int)pvVar1 + 0x18) = param_5;
      *(undefined4 *)((int)pvVar1 + 0x1c) = param_6;
    }
    else {
      *(undefined4 *)((int)pvVar1 + 0x18) = param_5;
      *(undefined4 *)((int)pvVar1 + 0x1c) = param_6;
    }
    piVar2 = (int *)0x0;
    if ((param_7 != 0) && (param_8 != 0)) {
      piVar2 = FUN_c04334cc(param_7);
    }
    *(int **)((int)pvVar1 + 0x60) = piVar2;
    *(int *)((int)pvVar1 + 0x68) = param_8;
    *(undefined4 *)((int)pvVar1 + 0x6c) = param_9;
    if (param_8 == 0) {
      NdisInitializeEvent((int)pvVar1 + 100);
      *param_10 = pvVar1;
    }
    iVar3 = (**(code **)(*(int *)(param_2 + 0xc) + 0x6c))(*(int *)(param_2 + 0xc),pvVar1);
    if (iVar3 != 0x103) {
      FUN_c04464b8((int)pvVar1,iVar3);
    }
  }
  *param_1 = iVar3;
  return;
}



/* c04466d4 FUN_c04466d4 */

/* Boundary evidence: original MIPS .pdata c04466d4..c044676f. Semantic name remains unreviewed. */

void FUN_c04466d4(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int local_18 [2];
  
  FUN_c04465b4(param_1,param_2,param_3,param_4,param_5,param_6,0,0,0,local_18);
  NdisWaitEvent(local_18[0] + 100,0);
  *param_1 = *(int *)(local_18[0] + 0x5c);
  NdisFreeEvent(local_18[0] + 100);
  FUN_c04343a4(local_18[0],0x70);
  return;
}



/* c0446770 FUN_c0446770 */

/* Boundary evidence: original MIPS .pdata c0446770..c04467eb. Semantic name remains unreviewed. */

undefined4 FUN_c0446770(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 auStack_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_14;
  
  piVar1 = FUN_c04334cc(param_1);
  if (piVar1 != (int *)0x0) {
    local_14 = 0;
    local_24 = param_3;
    local_20 = param_2;
    FUN_c04335a8((int)piVar1);
    (*(code *)piVar1[0x33a])(piVar1,auStack_28);
    FUN_c04335c4((int)piVar1);
    FUN_c0433498(piVar1);
  }
  return 0;
}



/* c04467ec FUN_c04467ec */

/* Boundary evidence: original MIPS .pdata c04467ec..c044685f. Semantic name remains unreviewed. */

void FUN_c04467ec(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_3 == 0) {
    param_2[5] = param_2[5] & 0xfffffeefU | 0x1000;
    param_2[6] = param_2[6] & 0xfffffeefU | 0x1000;
    FUN_c044721c(*(int **)(param_1 + 0xaa4),param_2,0,param_4);
    FUN_c0435398(param_1);
    iVar1 = 0x2000;
  }
  else {
    iVar1 = 0x2001;
  }
  FUN_c0433050(param_1,iVar1,0);
  return;
}



/* c0446860 FUN_c0446860 */

/* Boundary evidence: original MIPS .pdata c0446860..c04468b7. Semantic name remains unreviewed. */

void FUN_c0446860(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 == 0) {
    FUN_c043997c(*(int **)(param_1 + 0xaa8));
  }
  else if ((0 < iVar1) && (iVar1 < 3)) {
    FUN_c04470c8(*(int **)(param_1 + 0xaa4),FUN_c04467ec,param_1,param_4);
  }
  return;
}



/* c04468b8 FUN_c04468b8 */

/* Boundary evidence: original MIPS .pdata c04468b8..c0446977. Semantic name remains unreviewed. */

void FUN_c04468b8(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x20);
  if (iVar2 == 0) {
    FUN_c0439a3c(*(int *)(param_1 + 0xaa8));
  }
  else if ((0 < iVar2) && (iVar2 < 3)) {
    FUN_c0435524(param_1);
  }
  FUN_c0434580((int *)(param_2 + 0x198));
  if (*(int *)(param_1 + 0x54) == 0) {
    if (*(int *)(param_1 + 0xcd4) == 0) {
      if (*(int *)(param_1 + 0xcd8) == 0) {
        uVar1 = *(undefined4 *)(param_2 + 0x13c);
      }
      else {
        uVar1 = *(undefined4 *)(param_1 + 0x28);
      }
    }
    else {
      uVar1 = 0x39e;
    }
  }
  else {
    uVar1 = 0;
  }
  FUN_c0433050(param_1,0x2001,uVar1);
  EventModify(*(undefined4 *)(param_2 + 0x138),3);
  return;
}



/* c0446978 FUN_c0446978 */

/* Boundary evidence: original MIPS .pdata c0446978..c0446d6f. Semantic name remains unreviewed. */

void FUN_c0446978(int *param_1,int param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  if (param_2 == 0x40010008) {
    iVar4 = param_3[3];
    param_3[5] = iVar4;
    *(int *)(iVar4 + 0x1a0) = param_3[4];
    if (*param_3 == 0) {
      *(undefined4 *)(iVar4 + 0x1a4) = 0x120;
    }
    else {
      *(int *)(iVar4 + 0x1a4) = *param_3;
    }
    *(int *)(iVar4 + 0x1a8) = param_3[1];
    *(uint *)(iVar4 + 0x1ac) = (uint)*(ushort *)(param_3 + 2);
    return;
  }
  if (param_2 == 0x40010009) {
    iVar4 = *param_3;
    piVar1 = FUN_c04334cc(iVar4);
    if (piVar1 == (int *)0x0) {
      return;
    }
    FUN_c04335a8((int)piVar1);
    *(undefined4 *)(iVar4 + 0x13c) = 0x26b;
    FUN_c0439a3c(piVar1[0x2aa]);
    FUN_c04335c4((int)piVar1);
    goto LAB_c0446cc8;
  }
  if (param_2 != 0x40010080) {
    return;
  }
  iVar4 = param_3[2];
  if (iVar4 != 2) {
    if (iVar4 == 0xc) {
      iVar4 = *param_3;
      piVar1 = FUN_c04334cc(iVar4);
      if (piVar1 == (int *)0x0) {
        return;
      }
      if ((param_3[4] != 0) && (*(int *)(iVar4 + 0x13c) == 0)) {
        *(undefined4 *)(iVar4 + 0x13c) = 0x2a6;
        EventModify(*(undefined4 *)(iVar4 + 0x138),3);
      }
    }
    else {
      if (iVar4 == 0x13) {
        piVar1 = param_3;
        iVar4 = FUN_c044788c((int)param_1);
        if (iVar4 == 0) {
          return;
        }
        if ((uint)param_1[5] < param_3[3] + 1U) {
          FUN_c0448210((int)param_1,param_3[3] + 1U,piVar1,param_4);
          DAT_c044d894 = DAT_c044d894 + 1;
        }
        FUN_c0447918(param_1);
        return;
      }
      if (iVar4 != 500) {
        return;
      }
      iVar4 = *param_3;
      piVar1 = FUN_c04334cc(iVar4);
      if (piVar1 == (int *)0x0) {
        return;
      }
      *(int *)(iVar4 + 0x134) = param_3[3];
      *(undefined4 *)(iVar4 + 0x1c4) = 0;
      param_3[4] = iVar4;
    }
    goto LAB_c0446cc8;
  }
  piVar6 = (int *)*param_3;
  piVar1 = FUN_c04334cc((int)piVar6);
  if (piVar1 == (int *)0x0) {
    return;
  }
  FUN_c04335a8((int)piVar1);
  piVar6[0x74] = param_3[3];
  uVar5 = param_3[3];
  if (uVar5 < 0x41) {
    if (uVar5 == 0x40) {
      piVar6[0x4f] = 0x2a4;
LAB_c0446cb0:
      EventModify(piVar6[0x4e],3);
    }
    else {
      if (uVar5 == 1) {
        iVar4 = 0x26b;
        goto LAB_c0446c64;
      }
      if (uVar5 == 2) {
        if (piVar1[0x1b] != 0) {
          FUN_c0448db4(piVar6,(void *)0x0,0,param_4);
        }
      }
      else if ((uVar5 == 8) || (uVar5 == 0x10)) goto LAB_c0446b28;
    }
  }
  else if (uVar5 == 0x100) {
    if (piVar1[0x1b] == 0) {
      piVar6[0x4f] = 0;
      goto LAB_c0446cb0;
    }
    pwVar3 = L"ndis";
    uVar2 = 4;
    FUN_c0448b90(piVar6,4,L"ndis");
    FUN_c0446860((int)piVar1,uVar2,pwVar3,param_4);
  }
  else if (uVar5 == 0x200) {
LAB_c0446b28:
    FUN_c0433050(*piVar6,1,0);
  }
  else if (uVar5 == 0x4000) {
    uVar5 = param_3[4];
    if (uVar5 < 0x81) {
      if (uVar5 == 0x80) {
        iVar4 = 0x2ed;
LAB_c0446bec:
        piVar6[0x4f] = iVar4;
      }
      else {
        if (uVar5 == 1) {
          if (piVar6[0x4f] != 0) goto LAB_c0446c68;
          iVar4 = 0x2a7;
        }
        else {
          if (uVar5 != 4) {
            if (uVar5 == 0x20) {
              iVar4 = 0x2a4;
              goto LAB_c0446c64;
            }
            if (uVar5 != 0x40) goto LAB_c0446c44;
            iVar4 = 0x2a6;
            goto LAB_c0446bec;
          }
          iVar4 = 0x275;
        }
LAB_c0446c14:
        piVar6[0x4f] = iVar4;
      }
    }
    else {
      if (uVar5 == 0x100) {
        iVar4 = 0x2a7;
      }
      else {
        if (uVar5 == 0x800) {
          iVar4 = 0x279;
          goto LAB_c0446c14;
        }
        if (uVar5 != 0x1000) {
LAB_c0446c44:
          piVar6[0x4f] = 0x26b;
          goto LAB_c0446c68;
        }
        iVar4 = 0x2a8;
      }
LAB_c0446c64:
      piVar6[0x4f] = iVar4;
    }
LAB_c0446c68:
    FUN_c04468b8((int)piVar1,(int)piVar6);
  }
  FUN_c04335c4((int)piVar1);
LAB_c0446cc8:
  FUN_c0433498(piVar1);
  return;
}



/* c0446d70 FUN_c0446d70 */

/* Boundary evidence: original MIPS .pdata c0446d70..c0446d9b. Semantic name remains unreviewed. */

void FUN_c0446d70(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_c0447744(param_3,param_2,param_3,param_4);
  *param_1 = iVar1;
  return;
}



/* c0446d9c FUN_c0446d9c */

/* Boundary evidence: original MIPS .pdata c0446d9c..c0446e87. Semantic name remains unreviewed. */

void FUN_c0446d9c(undefined4 *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = 0xc0010006;
  iVar1 = FUN_c044788c((int)param_2);
  if (iVar1 != 0) {
    param_2[9] = param_3;
    param_2[8] = 1;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
    for (piVar2 = (int *)DAT_c044d8b0; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if ((piVar2[0x2a9] != 0) && (*(int **)(piVar2[0x2a9] + 4) == param_2)) {
        FUN_c0433914((int)piVar2,-0x3fbc4884,0,param_4);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d8c0);
    FUN_c0447918(param_2);
    FUN_c0447918(param_2);
    *param_1 = 0x103;
  }
  return;
}



/* c0446e88 FUN_c0446e88 */

/* Boundary evidence: original MIPS .pdata c0446e88..c0446f4f. Semantic name remains unreviewed. */

undefined4 FUN_c0446e88(int *param_1,uint param_2,int param_3,uint *param_4)

{
  uint uVar1;
  void *_Src;
  size_t _Size;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_4;
  uVar1 = 0;
  do {
    if (param_1 == (int *)0x0) {
      *param_4 = uVar1;
      return 1;
    }
    uVar2 = param_1[2];
    if (param_2 < uVar2) {
      _Size = uVar2 - param_2;
      uVar2 = _Size + uVar1;
      _Src = (void *)(param_1[1] + param_2);
      param_2 = 0;
      if (uVar3 < uVar2) {
        return 0;
      }
      memcpy((void *)(uVar1 + param_3),_Src,_Size);
    }
    else {
      param_2 = param_2 - uVar2;
      uVar2 = uVar1;
    }
    param_1 = (int *)*param_1;
    uVar1 = uVar2;
  } while( true );
}



/* c0446f50 FUN_c0446f50 */

/* Boundary evidence: original MIPS .pdata c0446f50..c0447073. Semantic name remains unreviewed. */

int FUN_c0446f50(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_3 + 8);
    puVar3 = (undefined1 *)(iVar1 + -1);
    *puVar3 = (char)param_2;
    if (((param_2 & 0xff00) != 0) || ((param_1[0x6d] & 0x400U) == 0)) {
      puVar3 = (undefined1 *)(iVar1 + -2);
      *puVar3 = (char)(param_2 >> 8);
    }
    if ((param_1[100] == 0) && ((param_2 == 0xc021 || ((param_1[0x6d] & 0x200U) == 0)))) {
      puVar2 = puVar3 + -1;
      puVar3 = puVar3 + -2;
      *puVar2 = 3;
      *puVar3 = 0xff;
    }
    *(int *)(param_3 + 0xc) = (*(int *)(param_3 + 0xc) - (int)puVar3) + *(int *)(param_3 + 8);
    *(undefined1 **)(param_3 + 8) = puVar3;
  }
  FUN_c04335c4(*param_1);
  iVar1 = (**(code **)(*(int *)(param_1[1] + 0xc) + 0x40))
                    (*(int *)(param_1[1] + 0xc),param_1[0x4d],param_3);
  FUN_c04335a8(*param_1);
  if ((iVar1 == 0) || (iVar1 != 0x103)) {
    FUN_c04476a0((int)param_1,param_3);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* c0447074 FUN_c0447074 */

/* Boundary evidence: original MIPS .pdata c0447074..c04470c7. Semantic name remains unreviewed. */

void FUN_c0447074(int param_1,undefined4 *param_2)

{
  (*(code *)*param_2)(param_2[1],*(undefined4 *)(param_1 + 0x18));
  FUN_c04343a4(*(int *)(param_1 + 0x18),0x2c);
  FUN_c04343a4((int)param_2,8);
  return;
}



/* c04470c8 FUN_c04470c8 */

/* Boundary evidence: original MIPS .pdata c04470c8..c04471fb. Semantic name remains unreviewed. */

void FUN_c04470c8(int *param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_28 [2];
  
  if (param_1[0x4d] == -1) {
    uVar4 = 0xc0010002;
  }
  else {
    puVar3 = param_2;
    uVar5 = param_3;
    puVar1 = FUN_c0434330(8,param_2,param_3,param_4);
    if (puVar1 == (undefined4 *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      *puVar1 = param_2;
      uVar4 = 0xc000009a;
      puVar1[1] = param_3;
      local_28[0] = -0x3fffff66;
      piVar2 = FUN_c0434330(0x2c,puVar3,uVar5,param_4);
      if (piVar2 != (int *)0x0) {
        *piVar2 = param_1[0x4d];
        FUN_c04335c4(*param_1);
        FUN_c04465b4(local_28,param_1[1],0,0x4010109,piVar2,0x2c,(int)param_1,-0x3fbb8f8c,puVar1,
                     (undefined4 *)0x0);
        FUN_c04335a8(*param_1);
        return;
      }
      FUN_c04343a4((int)puVar1,8);
    }
  }
  (*(code *)param_2)(param_3,0,uVar4);
  return;
}



/* c04471fc FUN_c04471fc */

/* Boundary evidence: original MIPS .pdata c04471fc..c044721b. Semantic name remains unreviewed. */

void FUN_c04471fc(int param_1)

{
  FUN_c04343a4(*(int *)(param_1 + 0x18),0x2c);
  return;
}



/* c044721c FUN_c044721c */

/* Boundary evidence: original MIPS .pdata c044721c..c044730f. Semantic name remains unreviewed. */

void FUN_c044721c(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *_Dst;
  int local_20 [2];
  
  param_2[3] = param_1[0x52];
  param_2[4] = param_1[0x53];
  if (param_1[0x4d] != -1) {
    local_20[0] = -0x3fffff66;
    _Dst = FUN_c0434330(0x2c,param_2,param_3,param_4);
    if (_Dst != (int *)0x0) {
      param_1[0x6d] = param_2[5];
      memcpy(_Dst,param_2,0x2c);
      *param_2 = param_1[0x4d];
      *_Dst = param_1[0x4d];
      FUN_c04335c4(*param_1);
      FUN_c04465b4(local_20,param_1[1],1,0x4010108,_Dst,0x2c,(int)param_1,-0x3fbb8e04,_Dst,
                   (undefined4 *)0x0);
      FUN_c04335a8(*param_1);
    }
  }
  return;
}



/* c0447324 FUN_c0447324 */

/* Boundary evidence: original MIPS .pdata c0447324..c044738f. Semantic name remains unreviewed. */

void FUN_c0447324(int param_1)

{
  int aiStack_10 [2];
  
  if (*(int *)(param_1 + 0x134) != -1) {
    *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x134);
    FUN_c04465b4(aiStack_10,*(int *)(param_1 + 4),0,0x401020e,(int *)(param_1 + 0x1f0),0x3c,param_1,
                 -0x3fbb8cf0,param_1,(undefined4 *)0x0);
  }
  return;
}



/* c0447390 FUN_c0447390 */

/* Boundary evidence: original MIPS .pdata c0447390..c0447447. Semantic name remains unreviewed. */

int FUN_c0447390(int param_1,void *param_2)

{
  int iVar1;
  int local_18 [2];
  
  iVar1 = 0;
  local_18[0] = 0;
  if (*(int *)(param_1 + 0x134) == -1) {
    if (*(int *)(param_1 + 0x1ec) == 0) {
      iVar1 = -0x3fffff45;
    }
  }
  else {
    *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x134);
    FUN_c04466d4(local_18,*(int *)(param_1 + 4),0,0x401020e,(int *)(param_1 + 0x1f0),0x3c);
    *(uint *)(param_1 + 0x1ec) = (uint)(local_18[0] == 0);
    iVar1 = local_18[0];
  }
  memcpy(param_2,(void *)(param_1 + 0x1f0),0x3c);
  return iVar1;
}



/* c0447448 FUN_c0447448 */

/* Boundary evidence: original MIPS .pdata c0447448..c04474e7. Semantic name remains unreviewed. */

undefined4 FUN_c0447448(int param_1,uint param_2,void *param_3,uint param_4)

{
  int iVar1;
  void *_Dst;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xaa4);
  iVar1 = FUN_c04476cc((int)piVar2);
  if (iVar1 != 0) {
    _Dst = (void *)(*(int *)(iVar1 + 8) + 4);
    *(void **)(iVar1 + 8) = _Dst;
    if (param_4 <= *(int *)(iVar1 + 0xc) - 4U) {
      memcpy(_Dst,param_3,param_4);
      *(uint *)(iVar1 + 0xc) = param_4;
      FUN_c0446f50(piVar2,param_2,iVar1);
    }
  }
  return 0;
}



/* c04474e8 FUN_c04474e8 */

/* Boundary evidence: original MIPS .pdata c04474e8..c044764b. Semantic name remains unreviewed. */

undefined4 FUN_c04474e8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  void *pvVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  
  if (((*(uint *)(param_1 + 0x140) < 0x20001) && (*(uint *)(param_1 + 0x148) < 0x10001)) &&
     (*(uint *)(param_1 + 0x14c) < 0x10001)) {
    if (500 < *(uint *)(param_1 + 0x144)) {
      *(undefined4 *)(param_1 + 0x144) = 500;
    }
    iVar4 = *(int *)(param_1 + 0x144) + 1;
    uVar5 = (*(uint *)(param_1 + 0x140) * 9 + 7 >> 3) + *(uint *)(param_1 + 0x14c) +
            *(uint *)(param_1 + 0x148) + 0xc & 0xfffffffc;
    sVar1 = (uVar5 + 0x38) * iVar4;
    pvVar2 = FUN_c0434330(sVar1,param_2,param_3,param_4);
    if (pvVar2 != (void *)0x0) {
      *(size_t *)(param_1 + 0x16c) = sVar1;
      *(void **)(param_1 + 0x168) = pvVar2;
      *(uint *)(param_1 + 0x170) = uVar5;
      NdisInitializeListHead(param_1 + 0x174);
      if (iVar4 != 0) {
        do {
          pvVar3 = (void *)(uVar5 + (int)pvVar2 + 0x38);
          *(int *)((int)pvVar2 + 0x10) = (int)pvVar2 + 0x38;
          *(int *)((int)pvVar2 + 0x14) = (int)pvVar3 + -5;
          NdisInterlockedInsertHeadList(param_1 + 0x174,pvVar2,param_1 + 0x17c);
          iVar4 = iVar4 + -1;
          pvVar2 = pvVar3;
        } while (iVar4 != 0);
      }
      return 0;
    }
  }
  return 0xc000009a;
}



/* c044764c FUN_c044764c */

/* Boundary evidence: original MIPS .pdata c044764c..c044769f. Semantic name remains unreviewed. */

undefined4 FUN_c044764c(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = NdisInterlockedRemoveHeadList(param_1 + 0x174,param_1 + 0x17c);
  *param_2 = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



/* c04476a0 FUN_c04476a0 */

/* Boundary evidence: original MIPS .pdata c04476a0..c04476cb. Semantic name remains unreviewed. */

undefined4 FUN_c04476a0(int param_1,undefined4 param_2)

{
  NdisInterlockedInsertHeadList(param_1 + 0x174,param_2,param_1 + 0x17c);
  return 0;
}



/* c04476cc FUN_c04476cc */

/* Boundary evidence: original MIPS .pdata c04476cc..c0447743. Semantic name remains unreviewed. */

int FUN_c04476cc(int param_1)

{
  int iVar1;
  int local_10 [2];
  
  iVar1 = FUN_c044764c(param_1,local_10);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x148) + *(int *)(local_10[0] + 0x10);
    *(int *)(local_10[0] + 8) = iVar1;
    *(int *)(local_10[0] + 0xc) = (*(int *)(local_10[0] + 0x14) - *(int *)(param_1 + 0x14c)) - iVar1
    ;
    *(int *)(local_10[0] + 0x18) = param_1;
    *(undefined4 *)(local_10[0] + 0x24) = 0;
    *(undefined4 *)(local_10[0] + 0x20) = 0;
    *(undefined4 *)(local_10[0] + 0x1c) = 0;
  }
  else {
    local_10[0] = 0;
  }
  return local_10[0];
}



/* c0447744 FUN_c0447744 */

/* Boundary evidence: original MIPS .pdata c0447744..c044788b. Semantic name remains unreviewed. */

int FUN_c0447744(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  size_t sVar2;
  wchar_t *_Dest;
  int local_20;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [8];
  
  puVar1 = FUN_c0434330(0x28,param_2,param_3,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    sVar2 = wcslen(*(wchar_t **)(param_1 + 4));
    sVar2 = (sVar2 + 1) * 2;
    _Dest = FUN_c0434330(sVar2,param_2,param_3,param_4);
    puVar1[2] = _Dest;
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,*(wchar_t **)(param_1 + 4));
      puVar1[9] = 0;
      puVar1[8] = 0;
      NdisOpenAdapter(&local_20,auStack_18,puVar1 + 3,auStack_1c,&DAT_c044d828,1,DAT_c044d954,puVar1
                      ,param_1,0,0);
      if (local_20 != 0) {
        FUN_c04343a4(puVar1[2],sVar2);
        FUN_c04343a4((int)puVar1,0x28);
        return local_20;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
      *puVar1 = DAT_c044d958;
      DAT_c044d958 = puVar1;
      puVar1[1] = 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
      FUN_c0448340((int)puVar1);
      return 0;
    }
    FUN_c04343a4((int)puVar1,0x28);
  }
  return -0x3fffff66;
}



/* c044788c FUN_c044788c */

/* Boundary evidence: original MIPS .pdata c044788c..c0447917. Semantic name remains unreviewed. */

undefined4 FUN_c044788c(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
  piVar1 = (int *)DAT_c044d958;
  do {
    if (piVar1 == (int *)0x0) {
LAB_c04478f4:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
      return uVar2;
    }
    if (piVar1 == (int *)param_1) {
      uVar2 = 1;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      goto LAB_c04478f4;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



/* c0447918 FUN_c0447918 */

/* Boundary evidence: original MIPS .pdata c0447918..c04479f3. Semantic name remains unreviewed. */

undefined4 FUN_c0447918(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int local_18 [2];
  
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
  piVar1 = (int *)0x0;
  piVar2 = (int *)DAT_c044d958;
  do {
    if (piVar2 == (int *)0x0) {
LAB_c04479d0:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
      return uVar4;
    }
    if (piVar2 == param_1) {
      iVar3 = param_1[1];
      uVar4 = 1;
      param_1[1] = iVar3 + -1;
      if (iVar3 + -1 == 0) {
        if (piVar1 == (int *)0x0) {
          DAT_c044d958 = *param_1;
        }
        else {
          *piVar1 = *param_1;
        }
        NdisCloseAdapter(local_18,param_1[3]);
        if (local_18[0] != 0x103) {
          FUN_c0446258((int)param_1);
        }
      }
      goto LAB_c04479d0;
    }
    piVar1 = piVar2;
    piVar2 = (int *)*piVar2;
  } while( true );
}



/* c04479f4 FUN_c04479f4 */

/* Boundary evidence: original MIPS .pdata c04479f4..c0447ab7. Semantic name remains unreviewed. */

undefined4
FUN_c04479f4(undefined4 param_1,undefined4 param_2,int *param_3,wchar_t *param_4,wchar_t *param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_3[5];
  uVar1 = param_3[2] + iVar2;
  piVar3 = (int *)(*param_3 + param_3[2]);
  param_3[2] = uVar1;
  if (uVar1 <= (uint)param_3[1]) {
    *piVar3 = iVar2;
    if (iVar2 == 0x68) {
      wcsncpy((wchar_t *)(piVar3 + 1),param_5,0x10);
      *(undefined2 *)(piVar3 + 9) = 0;
      wcsncpy((wchar_t *)((int)piVar3 + 0x26),param_4,0x20);
      *(undefined2 *)((int)piVar3 + 0x66) = 0;
    }
    else {
      wcsncpy((wchar_t *)(piVar3 + 1),param_5,0x10);
      *(undefined2 *)(piVar3 + 9) = 0;
      wcsncpy((wchar_t *)((int)piVar3 + 0x26),param_4,0x80);
      *(undefined2 *)((int)piVar3 + 0x126) = 0;
    }
    param_3[3] = param_3[3] + 1;
  }
  return 0;
}



/* c0447ab8 FUN_c0447ab8 */

/* Boundary evidence: original MIPS .pdata c0447ab8..c0447b8b. Semantic name remains unreviewed. */

int FUN_c0447ab8(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  
  pcVar5 = (code *)*param_2;
  iVar1 = 0;
  uVar4 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar3 = 0;
    do {
      piVar2 = (int *)(iVar3 + *(int *)(param_1 + 0x18));
      if (piVar2[1] == 0) {
        return iVar1;
      }
      if (*piVar2 == 0) {
        return iVar1;
      }
      if (((param_2[1] == 0) || (piVar2[2] == 1)) &&
         (iVar1 = (*pcVar5)(param_1,uVar4,param_3,piVar2[1],*piVar2), iVar1 != 0)) {
        return iVar1;
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0xc;
    } while (uVar4 < *(uint *)(param_1 + 0x14));
  }
  return iVar1;
}



/* c0447b8c FUN_c0447b8c */

/* Boundary evidence: original MIPS .pdata c0447b8c..c0447c6b. Semantic name remains unreviewed. */

void FUN_c0447b8c(undefined *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
  for (piVar2 = DAT_c044d958; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    piVar2[1] = piVar2[1] + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
    iVar1 = (*(code *)param_1)(piVar2,param_2,param_3);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
    if ((uint)piVar2[1] < 2) {
      FUN_c0447918(piVar2);
    }
    else {
      piVar2[1] = piVar2[1] - 1;
    }
    if (iVar1 != 0) break;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c044d920);
  return;
}



/* c0447c6c FUN_c0447c6c */

/* Boundary evidence: original MIPS .pdata c0447c6c..c0447cf7. Semantic name remains unreviewed. */

undefined4
FUN_c0447c6c(int param_1,undefined4 param_2,undefined4 *param_3,wchar_t *param_4,wchar_t *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = wcsncmp((wchar_t *)*param_3,param_4,0x80);
  if ((iVar1 == 0) && (iVar1 = wcscmp((wchar_t *)param_3[1],param_5), iVar1 == 0)) {
    param_3[2] = param_1;
    param_3[3] = param_2;
    param_3[4] = 0;
    FUN_c044788c(param_1);
    uVar2 = 1;
  }
  return uVar2;
}



/* c0447cf8 FUN_c0447cf8 */

/* Boundary evidence: original MIPS .pdata c0447cf8..c0447d7b. Semantic name remains unreviewed. */

void FUN_c0447cf8(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  code *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  
  local_18 = 0x293;
  local_20 = 0;
  local_1c = 0;
  local_30 = FUN_c0447c6c;
  local_2c = 0;
  local_28 = param_1;
  local_24 = param_2;
  FUN_c0447b8c(FUN_c0447ab8,&local_30,&local_28);
  if (local_18 == 0) {
    *param_3 = local_20;
    *param_4 = local_1c;
  }
  return;
}



/* c0447d7c FUN_c0447d7c */

/* Boundary evidence: original MIPS .pdata c0447d7c..c0447ebf. Semantic name remains unreviewed. */

int FUN_c0447d7c(uint *param_1,undefined4 param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  code *local_30;
  undefined4 local_2c;
  uint *local_28;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  local_18 = 0;
  if ((param_3 == (uint *)0x0) || (param_4 == (undefined4 *)0x0)) {
    local_18 = 0x57;
  }
  else {
    local_14 = 0x128;
    local_24 = 0;
    local_28 = param_1;
    if (param_1 != (uint *)0x0) {
      local_24 = *param_3;
      if ((local_24 < 4) || (uVar1 = *param_1, uVar1 < 0x68)) {
        return 0x25b;
      }
      if (uVar1 == 0x68) {
        local_14 = 0x68;
      }
      else {
        if (uVar1 < 0x128) {
          return 0x25b;
        }
        local_14 = 0x128;
      }
    }
  }
  if (local_18 == 0) {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_30 = FUN_c04479f4;
    local_2c = param_2;
    FUN_c0447b8c(FUN_c0447ab8,&local_30,&local_28);
    *param_3 = local_20;
    *param_4 = local_1c;
  }
  return local_18;
}



/* c0447ec0 FUN_c0447ec0 */

/* Boundary evidence: original MIPS .pdata c0447ec0..c0447ecb. Semantic name remains unreviewed. */

undefined4 FUN_c0447ec0(void)

{
  return 1;
}



/* c0447ecc FUN_c0447ecc */

/* Boundary evidence: original MIPS .pdata c0447ecc..c04480bb. Semantic name remains unreviewed. */

void FUN_c0447ecc(int param_1,int param_2)

{
  short sVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  int iVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  wchar_t *_Str1;
  undefined4 uVar7;
  undefined4 *_Dst;
  wchar_t *_Str;
  
  uVar7 = 0;
  if (*(uint *)(param_1 + 0x14) <= *(uint *)(param_2 + 4)) {
    return;
  }
  _Dst = (undefined4 *)(*(uint *)(param_2 + 4) * 0xc + *(int *)(param_1 + 0x18));
  LocalFree((HLOCAL)_Dst[1]);
  memset(_Dst,0,4);
  pwVar5 = L"modem";
  _Str = (wchar_t *)(*(int *)(param_2 + 0x30) + param_2 + 0xc);
  if (*(int *)(param_2 + 0x1c) != 0) {
    pwVar6 = (wchar_t *)(*(int *)(param_2 + 0x1c) + param_2 + 0xc);
    sVar3 = wcslen(pwVar6);
    _Str1 = pwVar6 + sVar3 + 1;
    if ((wchar_t *)(*(int *)(param_2 + 0x18) + (int)pwVar6) < _Str1) {
      _Str1 = (wchar_t *)0x0;
    }
    iVar4 = wcscmp(L"UNIMODEM",pwVar6);
    if (iVar4 == 0) {
      if (*(int *)(param_2 + 0xf4) != 0) {
        sVar1 = *(short *)(*(int *)(param_2 + 0xf4) + param_2 + 0xc);
        if (sVar1 == 0) {
          uVar7 = 1;
        }
        else if ((sVar1 != 6) && (sVar1 != 8)) goto LAB_c0448060;
        pwVar5 = L"direct";
      }
    }
    else {
      iVar4 = _wcsicmp(L"direct",pwVar6);
      pwVar2 = L"direct";
      if (iVar4 != 0) {
        iVar4 = _wcsicmp(L"modem",pwVar6);
        if (iVar4 == 0) goto LAB_c0448060;
        iVar4 = _wcsicmp(L"vpn",pwVar6);
        if ((iVar4 != 0) || (pwVar5 = L"vpn", _Str1 == (wchar_t *)0x0)) goto LAB_c0448060;
        iVar4 = _wcsicmp(_Str1,L"PPPoE");
        pwVar5 = L"vpn";
        pwVar2 = L"PPPoE";
        if (iVar4 != 0) goto LAB_c0448060;
      }
      pwVar5 = pwVar2;
    }
  }
LAB_c0448060:
  _Dst[2] = uVar7;
  sVar3 = wcslen(_Str);
  pwVar6 = LocalAlloc(0x40,(sVar3 + 1) * 2);
  _Dst[1] = pwVar6;
  if (pwVar6 != (wchar_t *)0x0) {
    wcscpy(pwVar6,_Str);
    *_Dst = pwVar5;
  }
  return;
}



/* c04480bc FUN_c04480bc */

/* Boundary evidence: original MIPS .pdata c04480bc..c044815b. Semantic name remains unreviewed. */

void FUN_c04480bc(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  *(undefined4 *)(param_2 + 0x1c) = 0;
  if ((param_3 == 0) && (0x12f < *(uint *)(param_1 + 0x1c))) {
    iVar1 = *(int *)(param_1 + 0x18);
    uVar2 = *(uint *)(iVar1 + 4);
    if (*(uint *)(iVar1 + 0xc) < *(uint *)(iVar1 + 0x10)) {
      iVar1 = *(uint *)(iVar1 + 0x10) - 0x124;
    }
    else {
      FUN_c0447ecc(param_2,iVar1);
      uVar2 = uVar2 + 1;
      iVar1 = 0;
    }
    if (uVar2 < *(uint *)(param_2 + 0x14)) {
      FUN_c044815c(param_2,uVar2,iVar1);
    }
  }
  LocalFree(*(HLOCAL *)(param_1 + 0x18));
  return;
}



/* c044815c FUN_c044815c */

/* Boundary evidence: original MIPS .pdata c044815c..c044820f. Semantic name remains unreviewed. */

void FUN_c044815c(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  uint uBytes;
  int aiStack_18 [2];
  
  if (((*(int *)(param_1 + 0x1c) == 0) && (uBytes = param_3 + 0x130, 0x12f < uBytes)) &&
     (puVar1 = LocalAlloc(0x40,uBytes), puVar1 != (undefined4 *)0x0)) {
    *(undefined4 *)(param_1 + 0x1c) = 1;
    puVar1[3] = param_3 + 0x124;
    *puVar1 = 0;
    puVar1[1] = param_2;
    puVar1[2] = 0;
    FUN_c04465b4(aiStack_18,param_1,0,0x7030110,puVar1,uBytes,0,-0x3fbb7f44,param_1,
                 (undefined4 *)0x0);
  }
  return;
}



/* c0448210 FUN_c0448210 */

/* Boundary evidence: original MIPS .pdata c0448210..c04482d7. Semantic name remains unreviewed. */

undefined4 FUN_c0448210(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  uVar1 = 0;
  if (uVar2 < param_2) {
    _Dst = FUN_c0434330(param_2 * 0xc,param_2,param_3,param_4);
    if (_Dst == (void *)0x0) {
      uVar1 = 0xc000009a;
    }
    else {
      memcpy(_Dst,*(void **)(param_1 + 0x18),uVar2 * 0xc);
      FUN_c04343a4(*(int *)(param_1 + 0x18),uVar2 * 0xc);
      *(void **)(param_1 + 0x18) = _Dst;
      *(uint *)(param_1 + 0x14) = param_2;
      FUN_c044815c(param_1,uVar2,0x100);
    }
  }
  return uVar1;
}



/* c04482d8 FUN_c04482d8 */

/* Boundary evidence: original MIPS .pdata c04482d8..c044833f. Semantic name remains unreviewed. */

void FUN_c04482d8(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_3 == 0) {
    if (0xf < *(uint *)(param_1 + 0x1c)) {
      iVar1 = *(int *)(param_1 + 0x18);
      param_2[4] = *(int *)(iVar1 + 0xc);
      FUN_c0448210((int)param_2,*(uint *)(iVar1 + 8),0,param_4);
    }
  }
  else {
    FUN_c0447918(param_2);
  }
  LocalFree(*(HLOCAL *)(param_1 + 0x18));
  return;
}



/* c0448340 FUN_c0448340 */

/* Boundary evidence: original MIPS .pdata c0448340..c04483b7. Semantic name remains unreviewed. */

void FUN_c0448340(int param_1)

{
  HLOCAL pvVar1;
  int aiStack_18 [2];
  
  pvVar1 = LocalAlloc(0x40,0x10);
  if (pvVar1 != (HLOCAL)0x0) {
    FUN_c04465b4(aiStack_18,param_1,0,0x7030118,pvVar1,0x10,0,-0x3fbb7d28,param_1,(undefined4 *)0x0)
    ;
  }
  return;
}



/* c04483b8 FUN_c04483b8 */

/* Boundary evidence: original MIPS .pdata c04483b8..c044860b. Semantic name remains unreviewed. */

STRSAFE_LPWSTR
FUN_c04483b8(int param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,wchar_t *param_5,
            int param_6,undefined4 param_7)

{
  size_t sVar1;
  size_t sVar2;
  STRSAFE_LPWSTR pszDest;
  undefined4 *hMem;
  wchar_t *_Dest;
  uint uVar3;
  int iVar4;
  wchar_t *pwVar5;
  uint *puVar6;
  SIZE_T uBytes;
  uint uVar7;
  int local_38;
  undefined4 local_34;
  int local_30;
  
  local_34 = param_2;
  local_30 = param_1;
  sVar1 = wcslen(param_4);
  sVar2 = wcslen(param_5);
  sVar1 = sVar2 + sVar1 + 0x14;
  pszDest = LocalAlloc(0x40,sVar1 * 2);
  if (pszDest == (STRSAFE_LPWSTR)0x0) {
    pwVar5 = (STRSAFE_LPWSTR)0x0;
  }
  else {
    if ((param_4 == (wchar_t *)0x0) || (*param_4 == L'\0')) {
      StringCchPrintfW(pszDest,sVar1,L"+%d %s",param_3,param_5);
    }
    else {
      StringCchPrintfW(pszDest,sVar1,L"+%d (%s) %s",param_3,param_4,param_5);
    }
    uVar7 = sVar1 * 2 + 3 & 0xfffffffc;
    uBytes = uVar7 + 0x44;
    pwVar5 = pszDest;
    while (hMem = LocalAlloc(0x40,uBytes), hMem != (undefined4 *)0x0) {
      hMem[1] = local_34;
      *hMem = 0;
      hMem[2] = sVar1;
      hMem[3] = 0;
      hMem[4] = param_7;
      memcpy(hMem + 6,pszDest,sVar1 * 2);
      puVar6 = (uint *)((int)hMem + uVar7 + 0x18);
      hMem[5] = uVar7;
      *puVar6 = (int)hMem + (uBytes - (int)puVar6);
      FUN_c04466d4(&local_38,local_30,0,0x7030200,hMem,uBytes);
      if (local_38 == 0) {
        uVar3 = *(uint *)((int)hMem + uVar7 + 0x1c);
        if (*puVar6 < uVar3) {
          uBytes = (uVar3 - *puVar6) + uBytes;
        }
        else {
          if (param_6 == 0) {
            iVar4 = *(int *)((int)hMem + uVar7 + 0x30);
          }
          else {
            iVar4 = *(int *)((int)hMem + uVar7 + 0x28);
          }
          sVar2 = wcslen((wchar_t *)(iVar4 + (int)puVar6));
          _Dest = LocalAlloc(0x40,(sVar2 + 1) * 2);
          pwVar5 = pszDest;
          if (_Dest != (wchar_t *)0x0) {
            wcscpy(_Dest,(wchar_t *)(iVar4 + (int)puVar6));
            LocalFree(pszDest);
            pwVar5 = _Dest;
          }
          uBytes = 0;
        }
      }
      LocalFree(hMem);
      if (local_38 != 0) {
        return pwVar5;
      }
      if (uBytes == 0) {
        return pwVar5;
      }
    }
  }
  return pwVar5;
}



/* c044860c FUN_c044860c */

/* Boundary evidence: original MIPS .pdata c044860c..c0448757. Semantic name remains unreviewed. */

int FUN_c044860c(int param_1,undefined4 param_2,undefined4 *param_3,size_t *param_4)

{
  undefined4 *hMem;
  HLOCAL pvVar1;
  size_t _Size;
  uint uVar2;
  int local_30 [2];
  
  uVar2 = 0x18;
  do {
    local_30[0] = -0x3fffff66;
    hMem = LocalAlloc(0x40,uVar2 + 0x28);
    if (hMem != (undefined4 *)0x0) {
      *hMem = 0;
      hMem[1] = param_2;
      hMem[2] = 0;
      hMem[3] = uVar2 + 0x10;
      hMem[4] = uVar2;
      FUN_c04466d4(local_30,param_1,0,0x7030111,hMem,uVar2 + 0x28);
      if ((local_30[0] == 0) && (uVar2 = hMem[5], uVar2 <= (uint)hMem[4])) {
        pvVar1 = LocalAlloc(0x40,hMem[8]);
        *param_3 = pvVar1;
        if (pvVar1 == (HLOCAL)0x0) {
          local_30[0] = -0x3fffff66;
        }
        else {
          _Size = hMem[8];
          *param_4 = _Size;
          memcpy((void *)*param_3,(void *)((int)hMem + hMem[9] + 0x10),_Size);
        }
        LocalFree(hMem);
        return local_30[0];
      }
      LocalFree(hMem);
    }
    if (local_30[0] != 0) {
      return local_30[0];
    }
  } while( true );
}



/* c0448758 FUN_c0448758 */

/* Boundary evidence: original MIPS .pdata c0448758..c044883b. Semantic name remains unreviewed. */

int FUN_c0448758(int *param_1)

{
  undefined4 *hMem;
  uint uBytes;
  size_t _Size;
  void *_Src;
  int local_20 [2];
  
  local_20[0] = -0x3fffff66;
  _Size = *(size_t *)(*param_1 + 0x68);
  _Src = *(void **)(*param_1 + 100);
  uBytes = _Size + 0x18;
  if ((0x17 < uBytes) && (hMem = LocalAlloc(0x40,uBytes), hMem != (undefined4 *)0x0)) {
    *hMem = 0;
    hMem[1] = param_1[2];
    hMem[2] = 0;
    hMem[3] = 0;
    hMem[4] = _Size;
    memcpy(hMem + 5,_Src,_Size);
    FUN_c04335c4(*param_1);
    FUN_c04466d4(local_20,param_1[1],1,0x7030120,hMem,uBytes);
    FUN_c04335a8(*param_1);
    LocalFree(hMem);
  }
  return local_20[0];
}



/* c044883c FUN_c044883c */

/* Boundary evidence: original MIPS .pdata c044883c..c04488d7. Semantic name remains unreviewed. */

void FUN_c044883c(int *param_1)

{
  int local_20 [2];
  undefined4 local_18;
  int local_14;
  int *local_10;
  int local_c;
  
  local_18 = *(undefined4 *)(*param_1 + 0x6c);
  local_14 = param_1[2];
  param_1[0x6e] = 1;
  local_10 = param_1;
  FUN_c04335c4(*param_1);
  FUN_c04466d4(local_20,param_1[1],0,0x7030117,&local_18,0x10);
  FUN_c04335a8(*param_1);
  param_1[0x6e] = 0;
  EventModify(param_1[0x6f],3);
  if (local_20[0] == 0) {
    param_1[0x4c] = local_c;
    param_1[0x73] = 0;
  }
  return;
}



/* c04488d8 FUN_c04488d8 */

/* Boundary evidence: original MIPS .pdata c04488d8..c0448a77. Semantic name remains unreviewed. */

int FUN_c04488d8(int *param_1,wchar_t *param_2)

{
  size_t sVar1;
  undefined4 *hMem;
  SIZE_T uBytes;
  size_t _Size;
  void *_Src;
  int local_28 [2];
  
  local_28[0] = -0x3fffff66;
  _Src = *(void **)(*param_1 + 100);
  _Size = *(size_t *)(*param_1 + 0x68);
  sVar1 = wcslen(param_2);
  uBytes = (sVar1 + 0x69) * 2;
  if (_Src != (void *)0x0) {
    uBytes = uBytes + _Size;
  }
  hMem = LocalAlloc(0x40,uBytes);
  if (hMem != (undefined4 *)0x0) {
    *hMem = 0;
    hMem[1] = param_1[0x4c];
    hMem[2] = param_1;
    *(undefined1 *)(hMem + 6) = 1;
    sVar1 = wcslen(param_2);
    hMem[4] = (sVar1 + 1) * 2;
    if (_Src == (void *)0x0) {
      *(undefined1 *)(hMem + 6) = 1;
      hMem[5] = 0xd0;
    }
    else {
      hMem[0xb] = 0x10;
      hMem[7] = _Size + 0xb4;
      *(undefined1 *)(hMem + 6) = 0;
      hMem[8] = 8;
      hMem[9] = 0;
      hMem[10] = 0;
      hMem[0xc] = 2;
      hMem[0xd] = 1;
      hMem[0xe] = 0;
      hMem[0x2c] = _Size;
      hMem[0x2d] = 0xb4;
      memcpy(hMem + 0x34,_Src,_Size);
      hMem[5] = _Size + 0xd0;
    }
    memcpy((void *)((int)hMem + hMem[5]),param_2,hMem[4]);
    FUN_c04335c4(*param_1);
    FUN_c04466d4(local_28,param_1[1],0,0x7030115,hMem,uBytes);
    FUN_c04335a8(*param_1);
    if (local_28[0] == 0) {
      param_1[0x4d] = hMem[3];
      param_1[0x71] = 0;
    }
    LocalFree(hMem);
  }
  return local_28[0];
}



/* c0448a78 FUN_c0448a78 */

/* Boundary evidence: original MIPS .pdata c0448a78..c0448b6f. Semantic name remains unreviewed. */

undefined4 * FUN_c0448a78(int param_1,undefined4 param_2,wchar_t *param_3,int param_4,uint *param_5)

{
  size_t sVar1;
  uint uVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar3 = param_2;
  pwVar4 = param_3;
  iVar5 = param_4;
  sVar1 = wcslen(param_3);
  uVar7 = param_4 + 0x34;
  sVar1 = (sVar1 + 1) * 2;
  *param_5 = 0xffffffff;
  puVar6 = (undefined4 *)0x0;
  if (0x33 < uVar7) {
    *param_5 = uVar7;
    uVar2 = uVar7 + sVar1;
    *param_5 = 0xffffffff;
    if (uVar7 <= uVar2) {
      *param_5 = uVar2;
      puVar6 = FUN_c0434330(uVar2,uVar3,pwVar4,iVar5);
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = 0;
        puVar6[1] = *(undefined4 *)(param_1 + 0x130);
        puVar6[2] = param_1;
        puVar6[3] = *(undefined4 *)(param_1 + 0x134);
        puVar6[4] = param_2;
        puVar6[5] = sVar1;
        puVar6[6] = uVar7;
        puVar6[7] = param_4 + 0x18;
        memcpy((void *)(uVar7 + (int)puVar6),param_3,sVar1);
      }
    }
  }
  return puVar6;
}



/* c0448b70 FUN_c0448b70 */

/* Boundary evidence: original MIPS .pdata c0448b70..c0448b8f. Semantic name remains unreviewed. */

void FUN_c0448b70(int param_1)

{
  FUN_c04343a4(*(int *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* c0448b90 FUN_c0448b90 */

/* Boundary evidence: original MIPS .pdata c0448b90..c0448c33. Semantic name remains unreviewed. */

int FUN_c0448b90(int *param_1,undefined4 param_2,wchar_t *param_3)

{
  undefined4 *puVar1;
  int local_18;
  uint local_14;
  
  local_18 = -0x3fffff66;
  puVar1 = FUN_c0448a78((int)param_1,param_2,param_3,0,&local_14);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c04335c4(*param_1);
    FUN_c04465b4(&local_18,param_1[1],0,0x7030113,puVar1,local_14,(int)param_1,-0x3fbb7490,0,
                 (undefined4 *)0x0);
    FUN_c04335a8(*param_1);
  }
  return local_18;
}



/* c0448c34 FUN_c0448c34 */

/* Boundary evidence: original MIPS .pdata c0448c34..c0448d93. Semantic name remains unreviewed. */

int FUN_c0448c34(int *param_1,undefined4 param_2,wchar_t *param_3,undefined4 *param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *_Dst;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint *_Src;
  int iVar7;
  int local_38;
  uint local_34;
  undefined4 local_30;
  
  bVar1 = false;
  iVar7 = 0;
  local_30 = param_2;
  do {
    puVar3 = FUN_c0448a78((int)param_1,local_30,param_3,iVar7,&local_34);
    if (puVar3 == (undefined4 *)0x0) {
      return -0x3fffff66;
    }
    FUN_c04335c4(*param_1);
    uVar2 = local_34;
    iVar4 = param_1[1];
    uVar6 = 0x7030113;
    uVar5 = 0;
    FUN_c04466d4(&local_38,iVar4,0,0x7030113,puVar3,local_34);
    FUN_c04335a8(*param_1);
    if (local_38 == 0) {
      _Src = puVar3 + 7;
      if (*_Src < (uint)puVar3[8]) {
        iVar7 = puVar3[8] - 0x18;
      }
      else {
        bVar1 = true;
        if (param_4 != (undefined4 *)0x0) {
          _Dst = FUN_c0434330(*_Src,iVar4,uVar5,uVar6);
          *param_4 = _Dst;
          if (_Dst == (void *)0x0) {
            local_38 = -0x3fffff66;
          }
          else {
            memcpy(_Dst,_Src,*_Src);
          }
        }
      }
    }
    else {
      bVar1 = true;
    }
    FUN_c04343a4((int)puVar3,uVar2);
  } while (!bVar1);
  return local_38;
}



/* c0448d94 FUN_c0448d94 */

/* Boundary evidence: original MIPS .pdata c0448d94..c0448db3. Semantic name remains unreviewed. */

void FUN_c0448d94(int param_1)

{
  FUN_c04343a4(*(int *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* c0448db4 FUN_c0448db4 */

/* Boundary evidence: original MIPS .pdata c0448db4..c0448e87. Semantic name remains unreviewed. */

int FUN_c0448db4(int *param_1,void *param_2,size_t param_3,undefined4 param_4)

{
  void *pvVar1;
  int local_20 [2];
  
  local_20[0] = -0x3fffff66;
  pvVar1 = FUN_c0434330(param_3 + 0x10,param_2,param_3,param_4);
  if (pvVar1 != (void *)0x0) {
    *(int *)((int)pvVar1 + 4) = param_1[0x4d];
    *(size_t *)((int)pvVar1 + 8) = param_3;
    memcpy((void *)((int)pvVar1 + 0xc),param_2,param_3);
    FUN_c04335c4(*param_1);
    FUN_c04465b4(local_20,param_1[1],1,0x7030102,pvVar1,param_3 + 0x10,(int)param_1,-0x3fbb726c,0,
                 (undefined4 *)0x0);
    FUN_c04335a8(*param_1);
  }
  return local_20[0];
}



/* c0448e88 FUN_c0448e88 */

/* Boundary evidence: original MIPS .pdata c0448e88..c0448ef7. Semantic name remains unreviewed. */

void FUN_c0448e88(int param_1,int param_2,int param_3)

{
  *(undefined4 *)(param_2 + 0x1c4) = 1;
  *(undefined4 *)(param_2 + 0x1c0) = 0;
  FUN_c0447324(param_2);
  if (param_3 == 0) {
    *(undefined4 *)(param_2 + 0x134) = 0xffffffff;
  }
  FUN_c0434580((int *)(param_2 + 0x19c));
  FUN_c04343a4(*(int *)(param_1 + 0x18),8);
  return;
}



/* c0448ef8 FUN_c0448ef8 */

/* Boundary evidence: original MIPS .pdata c0448ef8..c044902f. Semantic name remains unreviewed. */

int FUN_c0448ef8(int *param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  int iVar1;
  int local_28 [2];
  
  iVar1 = param_1[0x4d];
  local_28[0] = 0;
  if (param_1[0x71] == 0) {
    if (param_1[0x70] == 0) {
      local_28[0] = -0x3fffff66;
      _Dst = FUN_c0434330(8,param_2,param_3,param_4);
      if (_Dst != (void *)0x0) {
        memset(_Dst,0,8);
        *(int *)((int)_Dst + 4) = iVar1;
        FUN_c0434508(param_1 + 0x67,(int)param_2,param_3,param_4);
        param_1[0x70] = 1;
        FUN_c04335c4(*param_1);
        FUN_c04465b4(local_28,param_1[1],1,0x7030104,_Dst,8,(int)param_1,-0x3fbb7178,param_1,
                     (undefined4 *)0x0);
        FUN_c04335a8(*param_1);
      }
    }
    else {
      FUN_c0434508(param_1 + 0x67,(int)param_2,param_3,param_4);
    }
  }
  else if (param_2 != (undefined *)0x0) {
    (*(code *)param_2)(param_3);
  }
  return local_28[0];
}



/* c0449030 FUN_c0449030 */

/* Boundary evidence: original MIPS .pdata c0449030..c044904f. Semantic name remains unreviewed. */

void FUN_c0449030(int param_1)

{
  FUN_c04343a4(*(int *)(param_1 + 0x18),0x10);
  return;
}



/* c0449050 FUN_c0449050 */

/* Boundary evidence: original MIPS .pdata c0449050..c0449183. Semantic name remains unreviewed. */

int FUN_c0449050(int *param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  int *piVar1;
  int iVar2;
  int local_20 [2];
  
  iVar2 = param_1[0x4d];
  local_20[0] = 0;
  if ((((param_1[0x74] == 1) || (param_1[0x74] == 0x4000)) || (param_1[0x72] != 0)) ||
     (param_1[0x73] != 0)) {
    if (param_2 != (undefined *)0x0) {
      (*(code *)param_2)(param_3);
    }
  }
  else {
    piVar1 = param_1 + 0x66;
    if (*piVar1 == 0) {
      FUN_c0434508(piVar1,(int)param_2,param_3,param_4);
      local_20[0] = -0x3fffff66;
      _Dst = FUN_c0434330(0x10,param_2,param_3,param_4);
      if (_Dst != (void *)0x0) {
        memset(_Dst,0,0x10);
        *(int *)((int)_Dst + 4) = iVar2;
        FUN_c04335c4(*param_1);
        FUN_c04465b4(local_20,param_1[1],1,0x7030109,_Dst,0x10,(int)param_1,-0x3fbb6fd0,param_1,
                     (undefined4 *)0x0);
        FUN_c04335a8(*param_1);
      }
    }
    else {
      FUN_c0434508(piVar1,(int)param_2,param_3,param_4);
    }
  }
  return local_20[0];
}



/* c0449184 FUN_c0449184 */

/* Boundary evidence: original MIPS .pdata c0449184..c04491bf. Semantic name remains unreviewed. */

void FUN_c0449184(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0448ef8((int *)*param_1,(undefined *)param_1[1],param_1[2],param_4);
  FUN_c04343a4((int)param_1,0xc);
  return;
}



/* c04491c0 FUN_c04491c0 */

/* Boundary evidence: original MIPS .pdata c04491c0..c044923f. Semantic name remains unreviewed. */

int FUN_c04491c0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = -0x3fffff66;
  puVar1 = FUN_c0434330(0xc,param_2,param_3,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    iVar2 = FUN_c0449050(param_1,FUN_c0449184,puVar1,param_4);
  }
  return iVar2;
}



/* c0449240 FUN_c0449240 */

/* Boundary evidence: original MIPS .pdata c0449240..c0449293. Semantic name remains unreviewed. */

void FUN_c0449240(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x1cc) = 1;
  *(undefined4 *)(param_2 + 0x1c8) = 0;
  FUN_c0434580((int *)(param_2 + 0x198));
  FUN_c0434580((int *)(param_2 + 0x194));
  FUN_c04343a4(*(int *)(param_1 + 0x18),8);
  return;
}



/* c0449294 FUN_c0449294 */

/* Boundary evidence: original MIPS .pdata c0449294..c04492b3. Semantic name remains unreviewed. */

void FUN_c0449294(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c04492b4(param_1,(undefined *)0x0,0,param_4);
  return;
}



/* c04492b4 FUN_c04492b4 */

/* Boundary evidence: original MIPS .pdata c04492b4..c044945f. Semantic name remains unreviewed. */

int FUN_c04492b4(int *param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  undefined *puVar1;
  undefined4 uVar2;
  int local_28 [2];
  
  local_28[0] = 0;
  puVar1 = param_2;
  uVar2 = param_3;
  if (param_1[0x6e] != 0) {
    FUN_c04335c4(*param_1);
    puVar1 = (undefined *)0xffffffff;
    WaitForSingleObject((HANDLE)param_1[0x6f],0xffffffff);
    FUN_c04335a8(*param_1);
  }
  if (param_1[0x73] == 0) {
    if (param_1[0x72] == 0) {
      if (param_1[0x71] == 0) {
        FUN_c0434508(param_1 + 0x65,(int)param_2,param_3,param_4);
        local_28[0] = FUN_c0448ef8(param_1,FUN_c0449294,param_1,param_4);
      }
      else {
        local_28[0] = -0x3fffff66;
        _Dst = FUN_c0434330(8,puVar1,uVar2,param_4);
        if (_Dst != (void *)0x0) {
          memset(_Dst,0,8);
          *(int *)((int)_Dst + 4) = param_1[0x4c];
          param_1[0x4c] = -1;
          FUN_c0434508(param_1 + 0x65,(int)param_2,param_3,param_4);
          param_1[0x72] = 1;
          FUN_c04335c4(*param_1);
          FUN_c04465b4(local_28,param_1[1],1,0x7030103,_Dst,8,(int)param_1,-0x3fbb6dc0,param_1,
                       (undefined4 *)0x0);
          FUN_c04335a8(*param_1);
        }
      }
    }
    else {
      FUN_c0434508(param_1 + 0x65,(int)param_2,param_3,param_4);
    }
  }
  else if (param_2 != (undefined *)0x0) {
    (*(code *)param_2)(param_3);
  }
  return local_28[0];
}



/* c0449460 FUN_c0449460 */

/* Boundary evidence: original MIPS .pdata c0449460..c04496e3. Semantic name remains unreviewed. */

int FUN_c0449460(SIZE_T param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
                HLOCAL param_5,uint param_6,size_t *param_7)

{
  size_t *_Src;
  HLOCAL hMem;
  size_t sVar1;
  undefined4 *hMem_00;
  uint uVar2;
  int iVar3;
  uint uVar4;
  size_t *_Dst;
  SIZE_T uBytes;
  HLOCAL local_38;
  int local_34;
  undefined4 local_30;
  SIZE_T local_2c;
  
  local_38 = (HLOCAL)0x0;
  if (param_6 < 0x1000000) {
    local_30 = param_3;
    local_2c = param_1;
    if ((param_5 == (HLOCAL)0x0) &&
       (iVar3 = FUN_c044860c(param_1,param_2,&local_38,&param_6), param_5 = local_38, iVar3 != 0)) {
      if (local_38 != (HLOCAL)0x0) {
        LocalFree(local_38);
      }
    }
    else {
      hMem = local_38;
      uVar2 = param_6;
      if (param_4 == (wchar_t *)0x0) {
        sVar1 = 0;
      }
      else {
        sVar1 = wcslen(param_4);
      }
      _Src = param_7;
      if (((sVar1 < 0x100000) && (uVar2 < 0x100000)) && (*param_7 < 0x100000)) {
        uBytes = (sVar1 + 3 & 0xfffffffc) + (uVar2 + 3 & 0xfffffffc) + *param_7 + 0x20;
        hMem_00 = LocalAlloc(0x40,uBytes);
      }
      else {
        hMem_00 = (undefined4 *)0x0;
        uBytes = local_2c;
      }
      if (hMem_00 != (undefined4 *)0x0) {
        *hMem_00 = 0;
        hMem_00[1] = param_2;
        hMem_00[2] = local_30;
        hMem_00[3] = sVar1;
        if (sVar1 == 0) {
          uVar4 = 0;
        }
        else {
          memcpy(hMem_00 + 7,param_4,sVar1 * 2 + 2);
          uVar4 = sVar1 * 2 + 5 & 0xfffffffc;
        }
        hMem_00[4] = uVar4;
        hMem_00[5] = uVar2;
        memcpy((void *)((int)hMem_00 + uVar4 + 0x1c),param_5,uVar2);
        uVar2 = uVar4 + uVar2 + 3 & 0xfffffffc;
        hMem_00[6] = uVar2;
        _Dst = (size_t *)((int)hMem_00 + uVar2 + 0x1c);
        memcpy(_Dst,_Src,*_Src);
        FUN_c04466d4(&local_34,local_2c,0,0x7030201,hMem_00,uBytes);
        if (local_34 != 0) {
          LocalFree(hMem_00);
          if (hMem == (HLOCAL)0x0) {
            return local_34;
          }
          LocalFree(hMem);
          return local_34;
        }
        memcpy(_Src,_Dst,*_Dst);
        LocalFree(hMem_00);
      }
      if (hMem != (HLOCAL)0x0) {
        LocalFree(hMem);
      }
      iVar3 = 0;
    }
  }
  else {
    iVar3 = -0x3fffff66;
  }
  return iVar3;
}



/* c04496e4 FUN_c04496e4 */

/* Boundary evidence: original MIPS .pdata c04496e4..c0449797. Semantic name remains unreviewed. */

BOOL FUN_c04496e4(DWORD param_1,BYTE *param_2)

{
  BOOL BVar1;
  HCRYPTPROV local_18 [2];
  
  local_18[0] = 0;
  BVar1 = CryptAcquireContextW(local_18,(LPCWSTR)0x0,(LPCWSTR)0x0,1,0xf0000040);
  if (BVar1 == 0) {
    if (local_18[0] != 0) {
      CryptReleaseContext(local_18[0],0);
    }
    BVar1 = 0;
  }
  else {
    BVar1 = CryptGenRandom(local_18[0],param_1,param_2);
    if (local_18[0] != 0) {
      CryptReleaseContext(local_18[0],0);
    }
  }
  return BVar1;
}



/* c0449798 FUN_c0449798 */

void FUN_c0449798(void)

{
                    /* WARNING: Could not recover jumptable at 0xc04497a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1fc)();
  return;
}



/* c04497a8 FUN_c04497a8 */

void FUN_c04497a8(void)

{
                    /* WARNING: Could not recover jumptable at 0xc04497b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1f8)();
  return;
}



/* c04497b8 FUN_c04497b8 */

void FUN_c04497b8(void)

{
                    /* WARNING: Could not recover jumptable at 0xc04497c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1f4)();
  return;
}



/* c04497c8 FUN_c04497c8 */

void FUN_c04497c8(void)

{
                    /* WARNING: Could not recover jumptable at 0xc04497d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1f0)();
  return;
}



/* c04497d8 FUN_c04497d8 */

void FUN_c04497d8(void)

{
                    /* WARNING: Could not recover jumptable at 0xc04497e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1ec)();
  return;
}



/* c04497e8 FUN_c04497e8 */

void FUN_c04497e8(void)

{
                    /* WARNING: Could not recover jumptable at 0xc04497f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1e8)();
  return;
}



/* c04497f8 FUN_c04497f8 */

void FUN_c04497f8(void)

{
                    /* WARNING: Could not recover jumptable at 0xc0449800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1e4)();
  return;
}



/* c0449808 FUN_c0449808 */

void FUN_c0449808(void)

{
                    /* WARNING: Could not recover jumptable at 0xc0449810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1e0)();
  return;
}



/* c0449818 FUN_c0449818 */

void FUN_c0449818(void)

{
                    /* WARNING: Could not recover jumptable at 0xc0449820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1dc)();
  return;
}



/* c0449828 FUN_c0449828 */

void FUN_c0449828(void)

{
                    /* WARNING: Could not recover jumptable at 0xc0449830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1d8)();
  return;
}



/* c0449838 FUN_c0449838 */

void FUN_c0449838(void)

{
                    /* WARNING: Could not recover jumptable at 0xc0449840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c044d1d4)();
  return;
}



/* c0449bc8 entry */

/* Boundary evidence: original MIPS .pdata c0449bc8..c0449c3b. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c0449c3c();
    FUN_c044a200();
  }
  uVar1 = DllEntry(param_1,param_2);
  if (param_2 == 0) {
    FUN_c044a188();
  }
  return uVar1;
}



/* c0449c3c FUN_c0449c3c */

/* Boundary evidence: original MIPS .pdata c0449c3c..c0449caf. Semantic name remains unreviewed. */

void FUN_c0449c3c(void)

{
  uint uVar1;
  
  if ((DAT_c044d82c == 0) || (DAT_c044d82c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c044d82c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c044d82c == 0) {
      DAT_c044d82c = 0xb064;
    }
  }
  DAT_c044d830 = ~DAT_c044d82c;
  return;
}



/* c0449cb0 FUN_c0449cb0 */

/* Boundary evidence: original MIPS .pdata c0449cb0..c0449d03. Semantic name remains unreviewed. */

void FUN_c0449cb0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0449d30(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0449d04 FUN_c0449d04 */

/* Boundary evidence: original MIPS .pdata c0449d04..c0449d2f. Semantic name remains unreviewed. */

undefined4 FUN_c0449d04(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0449cb0(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0449d30 FUN_c0449d30 */

/* Boundary evidence: original MIPS .pdata c0449d30..c0449d77. Semantic name remains unreviewed. */

void FUN_c0449d30(uint param_1)

{
  if ((param_1 == DAT_c044d82c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0449d78 FUN_c0449d78 */

/* Boundary evidence: original MIPS .pdata c0449d78..c0449e83. Semantic name remains unreviewed. */

undefined4 FUN_c0449d78(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c044d964;
  puVar3 = DAT_c044d960;
  iVar4 = (int)DAT_c044d960 - (int)DAT_c044d964;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c0449dbc:
    param_1 = 0;
  }
  else {
    if (DAT_c044d964 != (void *)0x0) {
      uVar1 = _msize(DAT_c044d964);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c0449e30:
        if (pvVar2 == (void *)0x0) goto LAB_c0449dbc;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c0449e30;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c044d960 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c044d964 = pvVar2;
  }
  return param_1;
}



/* c0449e84 FUN_c0449e84 */

/* Boundary evidence: original MIPS .pdata c0449e84..c0449f6f. Semantic name remains unreviewed. */

undefined4 FUN_c0449e84(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c044d968 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c044d968,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c044d968 == (LPCRITICAL_SECTION)0x0) goto LAB_c0449f28;
  }
  EnterCriticalSection(DAT_c044d968);
LAB_c0449f28:
  uVar2 = FUN_c0449d78(param_1);
  FUN_c0449f70();
  return uVar2;
}



/* c0449f70 FUN_c0449f70 */

/* Boundary evidence: original MIPS .pdata c0449f70..c0449fbb. Semantic name remains unreviewed. */

void FUN_c0449f70(void)

{
  if (DAT_c044d968 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c044d968);
  }
  return;
}



/* c0449fbc FUN_c0449fbc */

/* Boundary evidence: original MIPS .pdata c0449fbc..c0449feb. Semantic name remains unreviewed. */

undefined4 FUN_c0449fbc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0449e84(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c0449fec FUN_c0449fec */

/* Boundary evidence: original MIPS .pdata c0449fec..c044a067. Semantic name remains unreviewed. */

void FUN_c0449fec(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c0449cb0(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c044a068 FUN_c044a068 */

/* Boundary evidence: original MIPS .pdata c044a068..c044a187. Semantic name remains unreviewed. */

void FUN_c044a068(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c044d890 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c044d964;
    if (DAT_c044d964 != (undefined4 *)0x0) {
      while (DAT_c044d960 = DAT_c044d960 + -1, _Memory <= DAT_c044d960) {
        if ((code *)*DAT_c044d960 != (code *)0x0) {
          (*(code *)*DAT_c044d960)();
          _Memory = DAT_c044d964;
        }
      }
      free(_Memory);
      DAT_c044d960 = (undefined4 *)0x0;
      DAT_c044d964 = (undefined4 *)0x0;
    }
    FUN_c044a1ac((undefined4 *)&DAT_c0431014,(undefined4 *)&DAT_c0431018);
  }
  FUN_c044a1ac((undefined4 *)&DAT_c043101c,(undefined4 *)&DAT_c0431020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c044d968,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c044a188 FUN_c044a188 */

/* Boundary evidence: original MIPS .pdata c044a188..c044a1ab. Semantic name remains unreviewed. */

void FUN_c044a188(void)

{
  FUN_c044a068(0,0,1);
  return;
}



/* c044a1ac FUN_c044a1ac */

/* Boundary evidence: original MIPS .pdata c044a1ac..c044a1ff. Semantic name remains unreviewed. */

void FUN_c044a1ac(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c044a200 FUN_c044a200 */

/* Boundary evidence: original MIPS .pdata c044a200..c044a23b. Semantic name remains unreviewed. */

void FUN_c044a200(void)

{
  FUN_c044a1ac((undefined4 *)&DAT_c043100c,(undefined4 *)&DAT_c0431010);
  FUN_c044a1ac((undefined4 *)&DAT_c0431000,(undefined4 *)&DAT_c0431008);
  return;
}



/* c044a3fc FUN_c044a3fc */

undefined4 FUN_c044a3fc(void)

{
  return 0x32;
}



/* c044a404 FUN_c044a404 */

/* Boundary evidence: original MIPS .pdata c044a404..c044a427. Semantic name remains unreviewed. */

void FUN_c044a404(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1[1]);
  return;
}



/* c044a428 FUN_c044a428 */

/* Boundary evidence: original MIPS .pdata c044a428..c044a44b. Semantic name remains unreviewed. */

void FUN_c044a428(int *param_1)

{
  (**(code **)(*param_1 + 0x14))(param_1[1]);
  return;
}



/* c044a44c FUN_c044a44c */

/* Boundary evidence: original MIPS .pdata c044a44c..c044a46f. Semantic name remains unreviewed. */

void FUN_c044a44c(int *param_1)

{
  (**(code **)(*param_1 + 0x18))(param_1[1]);
  return;
}



/* c044a470 FUN_c044a470 */

/* Boundary evidence: original MIPS .pdata c044a470..c044a4d3. Semantic name remains unreviewed. */

void FUN_c044a470(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(param_1 + 0x40);
  if (*(int *)(param_1 + 0x38) != 0) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
  }
  *puVar2 = 5;
  cVar1 = *(char *)(param_1 + 0x49) + '\x01';
  *(char *)(param_1 + 0x49) = cVar1;
  puVar2[1] = cVar1;
  puVar2[2] = 0;
  puVar2[3] = 4;
  *(undefined4 *)(param_1 + 0x44) = 4;
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
  FUN_c044acd4(param_1,*(undefined4 *)(param_1 + 0x2c));
  return;
}



/* c044a4d4 FUN_c044a4d4 */

/* WARNING: Removing unreachable block (ram,0xc044a630) */
/* Boundary evidence: original MIPS .pdata c044a4d4..c044a667. Semantic name remains unreviewed. */

int * FUN_c044a4d4(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if ((uint)param_1[2] < 0x10001) {
    piVar1 = LocalAlloc(0x40,param_1[2] + 0x64c);
    if (piVar1 != (int *)0x0) {
      *piVar1 = (int)param_1;
      piVar1[1] = param_3;
      piVar1[2] = 0;
      piVar1[10] = 0;
      CTEInitTimer(piVar1 + 3);
      piVar1[0xb] = 3000;
      piVar1[0xc] = 2;
      piVar1[0xd] = 10;
      piVar1[0x10] = (int)(piVar1 + 0x193);
      *(undefined1 *)(piVar1 + 0x12) = 0xff;
      FUN_c044b488(piVar1 + 0x13,*param_1,param_2,param_3);
      FUN_c0432908((HKEY)0x80000002,L"Comm\\ppp\\Parms",L"MaxConfigure",4);
    }
  }
  else {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



/* c044a668 FUN_c044a668 */

/* Boundary evidence: original MIPS .pdata c044a668..c044a6b7. Semantic name remains unreviewed. */

void FUN_c044a668(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    if (*(int *)((int)param_1 + 0x28) != 0) {
      CTEStopTimer((int)param_1 + 0xc);
      *(undefined4 *)((int)param_1 + 0x28) = 0;
    }
    FUN_c044b4a8((int)param_1 + 0x4c);
    LocalFree(param_1);
  }
  return;
}



/* c044a6b8 FUN_c044a6b8 */

/* Boundary evidence: original MIPS .pdata c044a6b8..c044a76f. Semantic name remains unreviewed. */

int FUN_c044a6b8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  do {
    piVar2 = (int *)((int)register0x00000074 + 4);
    if (*piVar2 == 0) {
      return 0;
    }
    puVar3 = (undefined4 *)((int)register0x00000074 + 8);
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + 0xc);
    iVar1 = FUN_c044b4e8(param_1 + 0x4c,*piVar2,*puVar3,*(undefined4 *)register0x00000074);
  } while (iVar1 == 0);
  return iVar1;
}



/* c044a770 FUN_c044a770 */

/* Boundary evidence: original MIPS .pdata c044a770..c044a82f. Semantic name remains unreviewed. */

undefined4 FUN_c044a770(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  int *piVar3;
  int local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  uVar1 = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  while( true ) {
    puVar2 = (uint *)((int)register0x00000074 + 4);
    if (*puVar2 == 0xffffffff) break;
    piVar3 = (int *)((int)register0x00000074 + 8);
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + 0xc);
    uVar1 = FUN_c044b588(param_1 + 0x4c,*puVar2 & 0xff,*piVar3,*(int *)register0x00000074);
  }
  return uVar1;
}



/* c044a830 FUN_c044a830 */

/* Boundary evidence: original MIPS .pdata c044a830..c044a98f. Semantic name remains unreviewed. */

void FUN_c044a830(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = param_1[2];
  pcVar3 = (code *)0x0;
  if (param_2 != iVar2) {
    if (((param_2 < 4) || (param_2 == 9)) && (param_1[10] != 0)) {
      CTEStopTimer(param_1 + 3);
      param_1[10] = 0;
    }
    if (param_2 == 1) {
      if ((iVar2 == 0) || (iVar2 == 3)) {
        pcVar3 = FUN_c044a428;
      }
    }
    else if (param_2 == 9) {
      pcVar3 = FUN_c044a404;
    }
    else if (((((param_2 == 0) || (param_2 == 2)) || (param_2 == 3)) &&
             ((iVar2 != 0 && (iVar2 != 2)))) && (iVar2 != 3)) {
      pcVar3 = FUN_c044a44c;
    }
    param_1[2] = param_2;
  }
  uVar1 = param_1[0xf];
  param_1[0xf] = 0;
  if ((uVar1 & 1) != 0) {
    (**(code **)(*param_1 + 0x1c))
              (param_1[1],*(undefined2 *)(*param_1 + 4),param_1[0x10],param_1[0x11]);
  }
  if ((uVar1 & 2) != 0) {
    (**(code **)(*param_1 + 0x1c))
              (param_1[1],*(undefined2 *)(*param_1 + 4),param_1 + 0x1c,param_1[0x1b]);
  }
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(param_1);
  }
  return;
}



/* c044a990 FUN_c044a990 */

/* Boundary evidence: original MIPS .pdata c044a990..c044aa3b. Semantic name remains unreviewed. */

undefined4 FUN_c044a990(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (iVar1 == 1) {
    iVar1 = 0;
  }
  else if (iVar1 == 3) {
    iVar1 = 2;
  }
  else {
    if (iVar1 != 5) {
      if (iVar1 < 6) goto LAB_c044aa20;
      if (8 < iVar1) {
        if (iVar1 != 9) goto LAB_c044aa20;
        (**(code **)(*param_1 + 0x10))(param_1[1]);
      }
      param_1[0xe] = param_1[0xc];
      FUN_c044a470((int)param_1);
    }
    iVar1 = 4;
  }
LAB_c044aa20:
  FUN_c044a830(param_1,iVar1);
  return 0;
}



/* c044aa3c FUN_c044aa3c */

/* Boundary evidence: original MIPS .pdata c044aa3c..c044aacf. Semantic name remains unreviewed. */

undefined4 FUN_c044aa3c(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (iVar1 == 2) {
LAB_c044aab0:
    iVar1 = 0;
  }
  else {
    if (iVar1 != 3) {
      if (iVar1 == 4) goto LAB_c044aab0;
      if (iVar1 < 5) {
        return 0;
      }
      if (8 < iVar1) {
        if (iVar1 != 9) {
          return 0;
        }
        (**(code **)(*param_1 + 0x10))(param_1[1]);
      }
    }
    iVar1 = 1;
  }
  FUN_c044a830(param_1,iVar1);
  return 0;
}



/* c044aad0 FUN_c044aad0 */

/* Boundary evidence: original MIPS .pdata c044aad0..c044ab7b. Semantic name remains unreviewed. */

undefined4 FUN_c044aad0(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (iVar1 == 2) {
LAB_c044ab5c:
    iVar1 = 2;
  }
  else {
    if (iVar1 != 3) {
      if (iVar1 == 4) goto LAB_c044ab5c;
      if (iVar1 < 5) {
        return 0;
      }
      if (8 < iVar1) {
        if (iVar1 != 9) {
          return 0;
        }
        (**(code **)(*param_1 + 0x10))(param_1[1]);
        param_1[0xe] = param_1[0xc];
        FUN_c044a470((int)param_1);
        iVar1 = 5;
        goto LAB_c044ab60;
      }
    }
    iVar1 = 3;
  }
LAB_c044ab60:
  FUN_c044a830(param_1,iVar1);
  return 0;
}



/* c044ab7c FUN_c044ab7c */

/* Boundary evidence: original MIPS .pdata c044ab7c..c044abe7. Semantic name remains unreviewed. */

void FUN_c044ab7c(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  if (0x5d8 < param_3) {
    param_3 = 0x5d8;
  }
  *(undefined1 *)(param_1 + 0x70) = 7;
  iVar1 = param_3 + 4;
  *(char *)(param_1 + 0x71) = *(char *)(param_1 + 0x4a);
  *(int *)(param_1 + 0x6c) = iVar1;
  *(char *)(param_1 + 0x72) = (char)((uint)iVar1 >> 8);
  *(char *)(param_1 + 0x73) = (char)iVar1;
  *(char *)(param_1 + 0x4a) = *(char *)(param_1 + 0x4a) + '\x01';
  memcpy((void *)(param_1 + 0x74),param_2,param_3);
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 2;
  return;
}



/* c044abe8 FUN_c044abe8 */

/* Boundary evidence: original MIPS .pdata c044abe8..c044acd3. Semantic name remains unreviewed. */

void FUN_c044abe8(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  (**(code **)(*param_2 + 0x20))(param_2[1]);
  if (param_2[10] == 0) goto LAB_c044acb0;
  iVar2 = param_2[2];
  param_2[10] = 0;
  if (3 < iVar2) {
    if (iVar2 < 6) {
      if (param_2[0xe] == 0) {
        if (iVar2 != 4) goto LAB_c044aca0;
        iVar2 = 2;
      }
      else {
        FUN_c044a470((int)param_2);
      }
    }
    else if (iVar2 < 9) {
      if ((param_2[0xe] == 0) || (iVar1 = FUN_c044ad34(param_2), iVar1 != 0)) {
LAB_c044aca0:
        iVar2 = 3;
      }
      else if (iVar2 == 7) {
        iVar2 = 6;
      }
    }
  }
  FUN_c044a830(param_2,iVar2);
LAB_c044acb0:
  (**(code **)(*param_2 + 0x24))(param_2[1]);
  return;
}



/* c044acd4 FUN_c044acd4 */

/* Boundary evidence: original MIPS .pdata c044acd4..c044ad33. Semantic name remains unreviewed. */

void FUN_c044acd4(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x28) != 0) {
    CTEStopTimer(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  CTEStartTimer(param_1 + 0xc,param_2,FUN_c044abe8,param_1);
  *(undefined4 *)(param_1 + 0x28) = 1;
  return;
}



/* c044ad34 FUN_c044ad34 */

/* Boundary evidence: original MIPS .pdata c044ad34..c044adbf. Semantic name remains unreviewed. */

int FUN_c044ad34(int *param_1)

{
  int iVar1;
  uint local_18 [2];
  
  local_18[0] = *(uint *)(*param_1 + 8);
  iVar1 = FUN_c044ba00((int)(param_1 + 0x13),(char)param_1[0x12],(undefined1 *)param_1[0x10],
                       local_18);
  if (iVar1 == 0) {
    if (param_1[0xe] != 0) {
      param_1[0xe] = param_1[0xe] + -1;
    }
    param_1[0x11] = local_18[0];
    param_1[0xf] = param_1[0xf] | 1;
    FUN_c044acd4((int)param_1,param_1[0xb]);
  }
  return iVar1;
}



/* c044adc0 FUN_c044adc0 */

/* Boundary evidence: original MIPS .pdata c044adc0..c044ae67. Semantic name remains unreviewed. */

int FUN_c044adc0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[2];
  iVar2 = 0;
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  else if (iVar1 == 2) {
    FUN_c044bc20((int)(param_1 + 0x13));
    param_1[0xe] = param_1[0xd];
    *(char *)(param_1 + 0x12) = (char)param_1[0x12] + '\x01';
    iVar2 = FUN_c044ad34(param_1);
    if (iVar2 == 0) {
      iVar1 = 6;
    }
  }
  else if (iVar1 == 4) {
    iVar1 = 5;
  }
  FUN_c044a830(param_1,iVar1);
  return iVar2;
}



/* c044ae68 FUN_c044ae68 */

/* Boundary evidence: original MIPS .pdata c044ae68..c044af1f. Semantic name remains unreviewed. */

int FUN_c044ae68(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[2];
  iVar2 = 0;
  if (iVar1 != 3) {
    if (iVar1 < 5) goto LAB_c044aef8;
    if (8 < iVar1) {
      if (iVar1 != 9) goto LAB_c044aef8;
      (**(code **)(*param_1 + 0x10))(param_1[1]);
    }
  }
  param_1[0xe] = param_1[0xd];
  FUN_c044bc20((int)(param_1 + 0x13));
  *(char *)(param_1 + 0x12) = (char)param_1[0x12] + '\x01';
  iVar2 = FUN_c044ad34(param_1);
  if (iVar2 == 0) {
    iVar1 = 6;
  }
LAB_c044aef8:
  FUN_c044a830(param_1,iVar1);
  return iVar2;
}



/* c044af20 FUN_c044af20 */

/* Boundary evidence: original MIPS .pdata c044af20..c044afaf. Semantic name remains unreviewed. */

int FUN_c044af20(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[2];
  iVar2 = 0;
  if (iVar1 == 0) {
    iVar1 = 2;
  }
  else if (iVar1 == 1) {
    FUN_c044bc20((int)(param_1 + 0x13));
    param_1[0xe] = param_1[0xd];
    *(char *)(param_1 + 0x12) = (char)param_1[0x12] + '\x01';
    iVar2 = FUN_c044ad34(param_1);
    if (iVar2 == 0) {
      iVar1 = 6;
    }
    else {
      iVar1 = 3;
    }
  }
  FUN_c044a830(param_1,iVar1);
  return iVar2;
}



/* c044afb0 FUN_c044afb0 */

/* Boundary evidence: original MIPS .pdata c044afb0..c044b487. Semantic name remains unreviewed. */

void FUN_c044afb0(int *param_1,byte *param_2,uint param_3)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  
  if (param_3 < 4) {
    return;
  }
  uVar6 = (uint)CONCAT11(param_2[2],param_2[3]);
  bVar8 = *param_2;
  bVar2 = param_2[1];
  if (uVar6 < 4) {
    return;
  }
  if (param_3 < uVar6) {
    return;
  }
  iVar7 = param_1[2];
  if (bVar8 == 1) {
    if (iVar7 == 2) goto LAB_c044b1a8;
    if ((iVar7 != 3) && ((iVar7 < 6 || (9 < iVar7)))) goto LAB_c044b1d0;
    param_1[0x1b] = 0x5dc;
    iVar4 = FUN_c044be50((int)(param_1 + 0x13),(char *)param_2,param_3,(char *)(param_1 + 0x1c),
                         (uint *)(param_1 + 0x1b));
    if (iVar4 != 0) {
      if (iVar4 != 0x2dc) goto LAB_c044b1d0;
LAB_c044b480:
      iVar7 = 3;
      goto LAB_c044b1d0;
    }
    iVar4 = 8;
    if ((char)param_1[0x1c] != '\x02') {
      iVar4 = 6;
    }
    if (iVar7 != 3) {
      if (iVar7 != 9) {
        bVar1 = iVar7 == 7;
        iVar7 = iVar4;
        if (bVar1) {
          if (iVar4 == 8) {
            iVar7 = 9;
          }
          else {
            iVar7 = 7;
          }
        }
        goto LAB_c044b1c4;
      }
      (**(code **)(*param_1 + 0x10))(param_1[1]);
    }
    FUN_c044bc20((int)(param_1 + 0x13));
    param_1[0xe] = param_1[0xd];
    *(char *)(param_1 + 0x12) = (char)param_1[0x12] + '\x01';
    iVar3 = FUN_c044ad34(param_1);
    iVar7 = iVar4;
    if (iVar3 != 0) {
      iVar7 = 3;
    }
LAB_c044b1c4:
    param_1[0xf] = param_1[0xf] | 2;
  }
  else {
    if (bVar8 < 2) {
LAB_c044b074:
      pbVar5 = *(byte **)(*param_1 + 0x28);
      if (pbVar5 != (byte *)0x0) {
        iVar4 = *(int *)(pbVar5 + 8);
        while (iVar4 != 0) {
          if (*pbVar5 == bVar8) goto LAB_c044b0b4;
          iVar4 = *(int *)(pbVar5 + 0x14);
          pbVar5 = pbVar5 + 0xc;
        }
        pbVar5 = (byte *)0x0;
LAB_c044b0b4:
        if (pbVar5 != (byte *)0x0) {
          (**(code **)(pbVar5 + 8))(param_1[1],bVar8,bVar2,param_2 + 4,uVar6 - 4);
          goto LAB_c044b1d0;
        }
      }
      FUN_c044ab7c((int)param_1,param_2,param_3);
      goto LAB_c044b1d0;
    }
    if (bVar8 < 5) {
      if ((bVar2 != *(byte *)(param_1 + 0x12)) || (iVar7 < 2)) goto LAB_c044b1d0;
      if (iVar7 < 4) goto LAB_c044b1a8;
      if (iVar7 == 6) {
LAB_c044b2a8:
        if ((bVar8 == 2) &&
           ((param_1[0x11] != uVar6 ||
            (iVar4 = memcmp((void *)(param_1[0x10] + 1),param_2 + 1,uVar6 - 1), iVar4 != 0))))
        goto LAB_c044b1d0;
        iVar4 = FUN_c044be50((int)(param_1 + 0x13),(char *)param_2,param_3,(char *)0x0,(uint *)0x0);
        if (iVar4 == 0x28c) {
          if (bVar8 != 2) goto LAB_c044b1d0;
          iVar4 = 0;
          bVar8 = 3;
        }
        if (iVar4 != 0) goto LAB_c044b1d0;
        param_1[0xe] = param_1[0xd];
        if (bVar8 == 2) {
          if (iVar7 == 6) {
            iVar7 = 7;
          }
          else {
            iVar7 = 9;
          }
          goto LAB_c044b1d0;
        }
        *(char *)(param_1 + 0x12) = (char)param_1[0x12] + '\x01';
        iVar4 = FUN_c044ad34(param_1);
        if (iVar4 == 0) goto LAB_c044b1d0;
        goto LAB_c044b480;
      }
      if (iVar7 != 7) {
        if (iVar7 == 8) goto LAB_c044b2a8;
        if (iVar7 != 9) goto LAB_c044b1d0;
        (**(code **)(*param_1 + 0x10))(param_1[1]);
      }
      *(char *)(param_1 + 0x12) = (char)param_1[0x12] + '\x01';
      iVar7 = FUN_c044ad34(param_1);
      if (iVar7 != 0) {
        FUN_c044a470((int)param_1);
        iVar7 = 5;
        goto LAB_c044b1d0;
      }
    }
    else {
      if (bVar8 == 5) {
        if (iVar7 < 2) goto LAB_c044b1d0;
        if (iVar7 < 7) {
LAB_c044b1a8:
          *(undefined1 *)(param_1 + 0x1c) = 6;
        }
        else {
          if (8 < iVar7) {
            if (iVar7 != 9) goto LAB_c044b1d0;
            (**(code **)(*param_1 + 0x10))(param_1[1]);
            param_1[0xe] = 0;
            FUN_c044acd4((int)param_1,100);
            iVar7 = 5;
            goto LAB_c044b1a8;
          }
          *(undefined1 *)(param_1 + 0x1c) = 6;
          iVar7 = 6;
        }
        *(byte *)((int)param_1 + 0x71) = bVar2;
        *(undefined1 *)((int)param_1 + 0x72) = 0;
        *(undefined1 *)((int)param_1 + 0x73) = 4;
        param_1[0x1b] = 4;
        goto LAB_c044b1c4;
      }
      if (bVar8 != 6) {
        if (bVar8 == 7) goto LAB_c044b1d0;
        goto LAB_c044b074;
      }
      if (iVar7 == 4) {
        iVar7 = 2;
        goto LAB_c044b1d0;
      }
      if (iVar7 == 5) {
LAB_c044b144:
        iVar7 = 3;
        goto LAB_c044b1d0;
      }
      if (iVar7 != 7) {
        if (iVar7 != 9) goto LAB_c044b1d0;
        (**(code **)(*param_1 + 0x10))(param_1[1]);
        *(char *)(param_1 + 0x12) = (char)param_1[0x12] + '\x01';
        iVar7 = FUN_c044ad34(param_1);
        if (iVar7 != 0) goto LAB_c044b144;
      }
    }
    iVar7 = 6;
  }
LAB_c044b1d0:
  FUN_c044a830(param_1,iVar7);
  return;
}



/* c044b488 FUN_c044b488 */

void FUN_c044b488(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[3] = 0;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[6] = 5;
  param_1[7] = 0;
  return;
}



/* c044b4a8 FUN_c044b4a8 */

/* Boundary evidence: original MIPS .pdata c044b4a8..c044b4e7. Semantic name remains unreviewed. */

void FUN_c044b4a8(int param_1)

{
  undefined4 *hMem;
  HLOCAL pvVar1;
  
  if (param_1 != 0) {
    hMem = *(HLOCAL *)(param_1 + 0xc);
    while (hMem != (HLOCAL)0x0) {
      pvVar1 = (HLOCAL)*hMem;
      LocalFree(hMem);
      hMem = pvVar1;
    }
  }
  return;
}



/* c044b4e8 FUN_c044b4e8 */

/* Boundary evidence: original MIPS .pdata c044b4e8..c044b587. Semantic name remains unreviewed. */

undefined4 FUN_c044b4e8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  puVar1 = LocalAlloc(0x40,0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    uVar4 = 0xe;
  }
  else {
    puVar1[6] = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = 0;
    puVar3 = (undefined4 *)(param_1 + 0xc);
    do {
      puVar2 = puVar3;
      puVar3 = (undefined4 *)*puVar2;
    } while (puVar3 != (undefined4 *)0x0);
    *puVar1 = 0;
    *puVar2 = puVar1;
  }
  return uVar4;
}



/* c044b588 FUN_c044b588 */

undefined4 FUN_c044b588(int param_1,uint param_2,int param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    do {
      if (*(byte *)piVar1[6] == param_2) break;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (piVar1 != (int *)0x0) {
      piVar1[1] = param_3;
      piVar1[2] = param_4;
      return 0;
    }
  }
  return 0x57;
}



/* c044b5d4 FUN_c044b5d4 */

/* Boundary evidence: original MIPS .pdata c044b5d4..c044b68f. Semantic name remains unreviewed. */

undefined4
FUN_c044b5d4(byte *param_1,uint param_2,uint param_3,byte param_4,void *param_5,size_t param_6)

{
  byte *pbVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (*param_1 <= param_3) {
    if (*param_1 < param_3) {
      *param_1 = (byte)param_3;
      param_1[2] = 0;
      param_1[3] = 4;
    }
    uVar3 = param_6 + 2 + (uint)CONCAT11(param_1[2],param_1[3]);
    if (uVar3 < param_2) {
      pbVar1 = param_1 + CONCAT11(param_1[2],param_1[3]);
      *pbVar1 = param_4;
      pbVar1[1] = (byte)(param_6 + 2);
      memcpy(pbVar1 + 2,param_5,param_6);
      param_1[2] = (byte)(uVar3 >> 8);
      param_1[3] = (byte)uVar3;
    }
    else {
      uVar2 = 0x7a;
    }
  }
  return uVar2;
}



/* c044b690 FUN_c044b690 */

/* Boundary evidence: original MIPS .pdata c044b690..c044b73f. Semantic name remains unreviewed. */

int FUN_c044b690(int param_1,uint param_2,undefined4 param_3,undefined *param_4)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (param_2 == 0) {
      return iVar1;
    }
    if (((param_2 < 2) || (*(byte *)(param_1 + 1) < 2)) || (param_2 < *(byte *)(param_1 + 1)))
    break;
    if ((param_4 != (undefined *)0x0) && (iVar1 = (*(code *)param_4)(param_3,param_1), iVar1 != 0))
    {
      return iVar1;
    }
    param_2 = param_2 - *(byte *)(param_1 + 1);
    param_1 = (uint)*(byte *)(param_1 + 1) + param_1;
  }
  return 0x2d2;
}



/* c044b740 FUN_c044b740 */

/* Boundary evidence: original MIPS .pdata c044b740..c044b867. Semantic name remains unreviewed. */

void FUN_c044b740(int param_1,byte *param_2)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  byte local_28 [4];
  byte *local_24;
  uint local_20 [2];
  
  uVar4 = param_2[1] - 2;
  bVar1 = *param_2;
  piVar2 = *(int **)(param_1 + 0xc);
  if (piVar2 != (int *)0x0) {
    do {
      if (*(byte *)piVar2[6] == bVar1) break;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    if ((piVar2 != (int *)0x0) && (piVar2[2] != 0)) {
      uVar3 = (uint)*(byte *)(piVar2[6] + 1);
      if ((uVar3 == 0xff) || (uVar3 == uVar4)) {
        piVar2[4] = 1;
        local_24 = param_2 + 2;
        local_20[0] = uVar4;
        (**(code **)(piVar2[6] + 0x18))
                  (*(undefined4 *)(param_1 + 8),piVar2,local_28,&local_24,local_20);
        uVar3 = (uint)local_28[0];
        if ((uVar3 != 3) || (*(uint *)(param_1 + 0x1c) < *(uint *)(param_1 + 0x18)))
        goto LAB_c044b828;
      }
    }
  }
  uVar3 = 4;
  local_28[0] = 4;
  local_24 = param_2 + 2;
  local_20[0] = uVar4;
LAB_c044b828:
  FUN_c044b5d4(*(byte **)(param_1 + 0x10),*(uint *)(param_1 + 0x14),uVar3,bVar1,local_24,local_20[0]
              );
  return;
}



/* c044b868 FUN_c044b868 */

/* Boundary evidence: original MIPS .pdata c044b868..c044b8e3. Semantic name remains unreviewed. */

undefined4 FUN_c044b868(int param_1,char *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  
  bVar1 = param_2[1];
  piVar3 = *(int **)(param_1 + 0xc);
  uVar2 = 0;
  if (piVar3 != (int *)0x0) {
    do {
      if (*(char *)piVar3[6] == *param_2) break;
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
    if (piVar3 != (int *)0x0) {
      piVar3[3] = 2;
      if (*(code **)(piVar3[6] + 0xc) != (code *)0x0) {
        uVar2 = (**(code **)(piVar3[6] + 0xc))
                          (*(undefined4 *)(param_1 + 8),piVar3,param_2 + 2,bVar1 - 2);
      }
    }
  }
  return uVar2;
}



/* c044b8e4 FUN_c044b8e4 */

/* Boundary evidence: original MIPS .pdata c044b8e4..c044b983. Semantic name remains unreviewed. */

undefined4 FUN_c044b8e4(int param_1,char *param_2)

{
  int *piVar1;
  code *pcVar2;
  uint uVar3;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    do {
      if (*(char *)piVar1[6] == *param_2) break;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      uVar3 = (uint)*(byte *)(piVar1[6] + 1);
      if ((uVar3 == 0xff) || (uVar3 == (byte)param_2[1] - 2)) {
        piVar1[3] = 3;
        pcVar2 = *(code **)(piVar1[6] + 0x10);
        if (pcVar2 != (code *)0x0) {
          (*pcVar2)(*(undefined4 *)(param_1 + 8),piVar1,param_2 + 2);
        }
      }
    }
  }
  return 0;
}



/* c044b984 FUN_c044b984 */

/* Boundary evidence: original MIPS .pdata c044b984..c044b9ff. Semantic name remains unreviewed. */

undefined4 FUN_c044b984(int param_1,char *param_2)

{
  byte bVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  bVar1 = param_2[1];
  if (piVar2 != (int *)0x0) {
    do {
      if (*(char *)piVar2[6] == *param_2) break;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    if (piVar2 != (int *)0x0) {
      piVar2[3] = 4;
      if (*(code **)(piVar2[6] + 0x14) != (code *)0x0) {
        (**(code **)(piVar2[6] + 0x14))(*(undefined4 *)(param_1 + 8),piVar2,param_2 + 2,bVar1 - 2);
      }
    }
  }
  return 0;
}



/* c044ba00 FUN_c044ba00 */

/* Boundary evidence: original MIPS .pdata c044ba00..c044bc1f. Semantic name remains unreviewed. */

int FUN_c044ba00(int param_1,undefined1 param_2,undefined1 *param_3,uint *param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  undefined1 *puVar8;
  int local_30 [2];
  
  uVar3 = *param_4;
  *param_4 = 0;
  iVar2 = 0;
  if (uVar3 < 4) {
    iVar2 = 0x7a;
  }
  else {
    piVar6 = *(int **)(param_1 + 0xc);
    uVar3 = uVar3 - 4;
    puVar8 = param_3 + 4;
    uVar7 = 0;
    if (piVar6 != (int *)0x0) {
      do {
        iVar4 = piVar6[1];
        if (iVar4 == 3) {
          if (piVar6[3] == 4) {
            return 0x3eb;
          }
LAB_c044bac4:
          uVar5 = 2;
          cVar1 = *(char *)(piVar6[6] + 1);
          if (cVar1 != -1) {
            uVar5 = (uint)(byte)(cVar1 + 2);
          }
          if (uVar3 < uVar5) {
            iVar2 = 0x7a;
            break;
          }
          if (*(int *)(piVar6[6] + 8) == 0) {
            local_30[0] = 0;
            iVar2 = 0;
          }
          else {
            local_30[0] = uVar3 - 2;
            iVar2 = (**(code **)(piVar6[6] + 8))
                              (*(undefined4 *)(param_1 + 8),piVar6,puVar8 + 2,local_30);
            if (iVar2 != 0) {
              if (iVar2 == 799) {
                iVar2 = 0;
                goto LAB_c044bba4;
              }
              break;
            }
          }
          *puVar8 = *(undefined1 *)piVar6[6];
          puVar8[1] = (char)local_30[0] + '\x02';
          puVar8 = puVar8 + local_30[0] + 2;
          uVar7 = (local_30[0] + 2U & 0xff) + uVar7 & 0xffff;
          uVar3 = (uVar3 - local_30[0]) - 2;
          piVar6[3] = 1;
        }
        else if (((iVar4 == 2) && (piVar6[3] != 4)) || ((iVar4 == 1 && (piVar6[3] == 3))))
        goto LAB_c044bac4;
LAB_c044bba4:
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)0x0);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = 0;
    uVar3 = uVar7 + 4 & 0xffff;
    *param_3 = 1;
    param_3[1] = param_2;
    param_3[2] = (char)(uVar3 >> 8);
    param_3[3] = (char)uVar3;
    *param_4 = uVar3;
  }
  return iVar2;
}



/* c044bc20 FUN_c044bc20 */

void FUN_c044bc20(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
  }
  return;
}



/* c044bc4c FUN_c044bc4c */

/* Boundary evidence: original MIPS .pdata c044bc4c..c044be4f. Semantic name remains unreviewed. */

int FUN_c044bc4c(int param_1,int param_2,uint param_3,char *param_4,uint *param_5,char param_6)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_38 [4];
  size_t local_34;
  void *local_30 [2];
  
  iVar2 = 0;
  (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 8));
  *param_4 = '\x02';
  param_4[1] = param_6;
  param_4[2] = '\0';
  param_4[3] = '\x04';
  for (piVar1 = *(int **)(param_1 + 0xc); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    piVar1[4] = 0;
  }
  *(char **)(param_1 + 0x10) = param_4;
  *(uint *)(param_1 + 0x14) = *param_5;
  FUN_c044b690(param_2,param_3,param_1,FUN_c044b740);
  if ((*param_4 != '\x04') && (piVar1 = *(int **)(param_1 + 0xc), piVar1 != (int *)0x0)) {
    do {
      if ((piVar1[4] == 0) && ((piVar1[2] == 3 || ((piVar1[2] == 2 && (piVar1[5] == 0)))))) {
        piVar1[5] = 1;
        if (*(uint *)(param_1 + 0x18) <= *(uint *)(param_1 + 0x1c)) {
          iVar2 = 0x2dc;
          break;
        }
        local_30[0] = (void *)0x0;
        local_34 = 0;
        iVar2 = (**(code **)(piVar1[6] + 0x18))
                          (*(undefined4 *)(param_1 + 8),piVar1,auStack_38,local_30,&local_34);
        if ((iVar2 != 0) ||
           (iVar2 = FUN_c044b5d4(*(byte **)(param_1 + 0x10),*(uint *)(param_1 + 0x14),3,
                                 *(byte *)piVar1[6],local_30[0],local_34), iVar2 != 0))
        goto LAB_c044be0c;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (iVar2 != 0) goto LAB_c044be0c;
  }
  if (*param_4 == '\x02') {
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  else if (*param_4 == '\x03') {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  }
LAB_c044be0c:
  *param_5 = (uint)CONCAT11(param_4[2],param_4[3]);
  return iVar2;
}



/* c044be50 FUN_c044be50 */

/* Boundary evidence: original MIPS .pdata c044be50..c044c007. Semantic name remains unreviewed. */

int FUN_c044be50(int param_1,char *param_2,uint param_3,char *param_4,uint *param_5)

{
  char cVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  uint local_30 [2];
  
  uVar7 = 4;
  if (param_5 != (uint *)0x0) {
    uVar7 = *param_5;
    *param_5 = 0;
    if (uVar7 < 4) {
      return 0x7a;
    }
  }
  if (3 < param_3) {
    uVar5 = (uint)CONCAT11(param_2[2],param_2[3]);
    cVar1 = *param_2;
    cVar2 = param_2[1];
    if ((3 < uVar5) && (uVar5 <= param_3)) {
      pcVar6 = param_2 + 4;
      uVar5 = uVar5 - 4;
      iVar3 = FUN_c044b690((int)pcVar6,uVar5,0,(undefined *)0x0);
      if (iVar3 == 0) {
        if (cVar1 == '\x01') {
          local_30[0] = uVar7;
          iVar3 = FUN_c044bc4c(param_1,(int)pcVar6,uVar5,param_4,local_30,cVar2);
          if (iVar3 != 0) {
            return iVar3;
          }
          *param_5 = local_30[0];
          return 0;
        }
        if (cVar1 != '\x02') {
          if (cVar1 == '\x03') {
            pcVar4 = FUN_c044b8e4;
          }
          else {
            if (cVar1 != '\x04') {
              return 0;
            }
            pcVar4 = FUN_c044b984;
          }
          FUN_c044b690((int)pcVar6,uVar5,param_1,pcVar4);
          return 0;
        }
        iVar3 = FUN_c044b690((int)pcVar6,uVar5,param_1,FUN_c044b868);
        return iVar3;
      }
    }
  }
  return 0x3ea;
}



/* c044c008 FUN_c044c008 */

/* Boundary evidence: original MIPS .pdata c044c008..c044c06b. Semantic name remains unreviewed. */

void FUN_c044c008(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = 1;
    piVar1 = (int *)(param_1 + 8);
    iVar2 = 3;
    do {
      if (*piVar1 != 0) {
        (*(code *)piVar1[3])(piVar1[1]);
      }
      iVar2 = iVar2 + -1;
      piVar1 = piVar1 + 6;
    } while (iVar2 != 0);
  }
  return;
}



/* c044c06c FUN_c044c06c */

/* Boundary evidence: original MIPS .pdata c044c06c..c044c0cb. Semantic name remains unreviewed. */

void FUN_c044c06c(int param_1)

{
  int *piVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_c04366d0(param_1);
  piVar1 = (int *)(param_1 + 8);
  iVar2 = 3;
  do {
    if (*piVar1 != 0) {
      (*(code *)piVar1[4])(piVar1[1]);
    }
    iVar2 = iVar2 + -1;
    piVar1 = piVar1 + 6;
  } while (iVar2 != 0);
  return;
}



/* c044c0fc FUN_c044c0fc */

/* Boundary evidence: original MIPS .pdata c044c0fc..c044c117. Semantic name remains unreviewed. */

void FUN_c044c0fc(void)

{
  FUN_c0435e34();
  return;
}



/* c044c118 FUN_c044c118 */

/* Boundary evidence: original MIPS .pdata c044c118..c044c137. Semantic name remains unreviewed. */

void FUN_c044c118(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c044d844);
  return;
}


