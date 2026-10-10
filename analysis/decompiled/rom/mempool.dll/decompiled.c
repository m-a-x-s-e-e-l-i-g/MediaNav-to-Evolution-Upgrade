/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c09612f0 FUN_c09612f0 */

/* Boundary evidence: original MIPS .pdata c09612f0..c09613e3. Semantic name remains unreviewed. */

int FUN_c09612f0(int param_1,uint param_2)

{
  HLOCAL pvVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_2;
  if ((param_2 & 0xffff) != 0) {
    uVar3 = (param_2 & 0xffff0000) + 0x10000;
  }
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    if ((*(int *)(param_1 + 0x1c) == 0) && (uVar3 <= *(uint *)(param_1 + 0x20))) break;
    param_1 = *(int *)(param_1 + 0x14);
  }
  if (*(uint *)(param_1 + 0x20) != uVar3) {
    pvVar1 = LocalAlloc(0x40,0x24);
    if (pvVar1 == (HLOCAL)0x0) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x20);
    *(undefined4 *)((int)pvVar1 + 0x1c) = 0;
    *(uint *)((int)pvVar1 + 0x20) = iVar2 - uVar3;
    *(uint *)((int)pvVar1 + 8) = *(int *)(param_1 + 8) + uVar3;
    iVar2 = *(int *)(param_1 + 4);
    *(int *)((int)pvVar1 + 0x18) = param_1;
    *(uint *)((int)pvVar1 + 4) = iVar2 + uVar3;
    *(undefined4 *)((int)pvVar1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(HLOCAL *)(param_1 + 0x14) = pvVar1;
    *(uint *)(param_1 + 0x20) = uVar3;
    *(uint *)(param_1 + 0x10) = param_2;
  }
  *(undefined4 *)(param_1 + 0x1c) = 1;
  return param_1;
}



/* c09613e4 FUN_c09613e4 */

/* Boundary evidence: original MIPS .pdata c09613e4..c09614c3. Semantic name remains unreviewed. */

undefined4 FUN_c09613e4(HLOCAL param_1)

{
  bool bVar1;
  HLOCAL hMem;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)((int)param_1 + 0x18);
  hMem = *(HLOCAL *)((int)param_1 + 0x14);
  bVar1 = false;
  if ((hMem != (HLOCAL)0x0) && (*(int *)((int)hMem + 0x1c) == 0)) {
    iVar2 = *(int *)((int)hMem + 0x20);
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
    *(int *)((int)param_1 + 0x20) = iVar2 + *(int *)((int)param_1 + 0x20);
    *(undefined4 *)((int)param_1 + 0x14) = *(undefined4 *)((int)hMem + 0x14);
    if (*(int *)((int)hMem + 0x14) != 0) {
      *(HLOCAL *)(*(int *)((int)hMem + 0x14) + 0x18) = param_1;
    }
    LocalFree(hMem);
    bVar1 = true;
  }
  if ((iVar3 == 0) || (*(int *)(iVar3 + 0x1c) != 0)) {
    if (!bVar1) {
      *(undefined4 *)((int)param_1 + 0x1c) = 0;
    }
  }
  else {
    iVar2 = *(int *)((int)param_1 + 0x18);
    iVar3 = *(int *)((int)param_1 + 0x20);
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(int *)(iVar2 + 0x20) = iVar3 + *(int *)(iVar2 + 0x20);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)((int)param_1 + 0x14);
    if (*(int *)((int)param_1 + 0x14) != 0) {
      *(int *)(*(int *)((int)param_1 + 0x14) + 0x18) = iVar2;
    }
    LocalFree(param_1);
  }
  return 1;
}



/* c09614c4 FUN_c09614c4 */

/* Boundary evidence: original MIPS .pdata c09614c4..c0961523. Semantic name remains unreviewed. */

void FUN_c09614c4(undefined4 *param_1)

{
  BOOL BVar1;
  
  if ((LPVOID)param_1[3] != (LPVOID)0x0) {
    BVar1 = VirtualFreeEx((HANDLE)*param_1,(LPVOID)param_1[3],0,0x8000);
    if (BVar1 == 0) {
      GetLastError();
    }
    param_1[3] = 0;
  }
  FUN_c09613e4(param_1);
  return;
}



/* c0961524 FUN_c0961524 */

/* Boundary evidence: original MIPS .pdata c0961524..c0961603. Semantic name remains unreviewed. */

undefined4 *
FUN_c0961524(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = GetCallerVMProcessId();
  puVar2 = (undefined4 *)FUN_c09612f0(*(int *)(param_1 + 0x214),param_2);
  if (puVar2 == (undefined4 *)0x0) {
LAB_c09615c0:
    puVar2 = (undefined4 *)0x0;
  }
  else {
    if ((param_5 & 2) == 0) {
      uVar4 = 4;
      if ((param_5 & 8) != 0) {
        uVar4 = 0x204;
      }
      iVar3 = VirtualAllocCopyEx(0x42,uVar1,puVar2[1],param_2,uVar4);
      puVar2[3] = iVar3;
      if ((iVar3 == 0) && (iVar3 = FUN_c09613e4(puVar2), iVar3 == 0)) goto LAB_c09615c0;
    }
    else {
      puVar2[3] = 0;
    }
    *param_3 = puVar2[3];
    *param_4 = puVar2[2];
    *puVar2 = uVar1;
  }
  return puVar2;
}



/* c0961604 FUN_c0961604 */

/* Boundary evidence: original MIPS .pdata c0961604..c096166f. Semantic name remains unreviewed. */

undefined4 FUN_c0961604(int param_1)

{
  HLOCAL pvVar1;
  
  pvVar1 = LocalAlloc(0x40,0x24);
  *(HLOCAL *)(param_1 + 0x214) = pvVar1;
  *(undefined4 *)((int)pvVar1 + 8) = *(undefined4 *)(param_1 + 0x208);
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 4) = *(undefined4 *)(param_1 + 0x20c);
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x20) = *(undefined4 *)(param_1 + 0x210);
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x1c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x18) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x14) = 0;
  return 1;
}



/* c0961670 FUN_c0961670 */

/* Boundary evidence: original MIPS .pdata c0961670..c0961703. Semantic name remains unreviewed. */

undefined4 FUN_c0961670(int param_1)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  for (puVar3 = *(undefined4 **)(param_1 + 0x214); puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)puVar3[5]) {
    if ((LPVOID)puVar3[3] != (LPVOID)0x0) {
      BVar1 = VirtualFreeEx((HANDLE)*puVar3,(LPVOID)puVar3[3],0,0x8000);
      if (BVar1 == 0) {
        GetLastError();
      }
      puVar3[3] = 0;
    }
    iVar2 = FUN_c09613e4(puVar3);
    if (iVar2 == 0) {
      uVar4 = 0;
    }
  }
  return uVar4;
}



/* c0961704 MEM_IOControl */

/* Boundary evidence: original MIPS .pdata c0961704..c09618a3. Semantic name remains unreviewed. */

undefined4
MEM_IOControl(int param_1,int param_2,undefined4 *param_3,int param_4,undefined4 *param_5,
             int param_6,undefined4 *param_7)

{
  undefined4 *puVar1;
  
                    /* 0x1704  3  MEM_IOControl */
  if (param_2 == 0x220404) {
    if (param_4 == 0x20) {
      if ((param_5 == (undefined4 *)0x0) || (param_6 != 0x20)) {
        param_5 = param_3;
      }
      if (*(int *)(param_3[5] * 0x220 + param_1 + 0x228) == 0) {
        NKDbgPrintfW(L"MEMPOOL: Invalid Region Index(%d)!\r\n");
      }
      else {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        puVar1 = FUN_c0961524(param_3[5] * 0x220 + param_1 + 0x1c,param_3[3],param_5 + 1,param_5 + 2
                              ,param_3[4]);
        *param_5 = puVar1;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
      }
      if (param_7 == (undefined4 *)0x0) {
        return 1;
      }
      *param_7 = 0x20;
      return 1;
    }
  }
  else {
    if (param_2 != 0x220408) {
      if (param_2 != 0x22040c) {
        return 0;
      }
      *param_5 = *(undefined4 *)(param_3[5] * 0x220 + param_1 + 0x22c);
      return 1;
    }
    if (param_4 == 0x20) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
      FUN_c09614c4((undefined4 *)*param_3);
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
      if (param_7 == (undefined4 *)0x0) {
        return 1;
      }
      *param_7 = 0x20;
      return 1;
    }
  }
  SetLastError(0x57);
  return 0;
}



/* c09618a4 MEM_PreDeinit */

undefined4 MEM_PreDeinit(void)

{
                    /* 0x18a4  6  MEM_PreDeinit */
  return 1;
}



/* c09618ac MEM_Deinit */

/* Boundary evidence: original MIPS .pdata c09618ac..c0961917. Semantic name remains unreviewed. */

undefined4 MEM_Deinit(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
                    /* 0x18ac  2  MEM_Deinit */
  uVar3 = 0;
  iVar2 = param_1 + 0x1c;
  do {
    iVar1 = FUN_c0961670(iVar2);
    if (iVar1 == 0) {
      return 0;
    }
    uVar3 = uVar3 + 1;
    iVar2 = iVar2 + 0x220;
  } while (uVar3 < 10);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return 1;
}



/* c0961918 MEM_Open */

/* Boundary evidence: original MIPS .pdata c0961918..c096196f. Semantic name remains unreviewed. */

int * MEM_Open(int *param_1)

{
                    /* 0x1918  5  MEM_Open */
  if ((param_1 != (int *)0x0) && (*param_1 != 0x155c)) {
    return (int *)0x0;
  }
  InterlockedIncrement(param_1 + 1);
  return param_1;
}



/* c0961970 MEM_Close */

/* Boundary evidence: original MIPS .pdata c0961970..c09619c3. Semantic name remains unreviewed. */

undefined4 MEM_Close(int *param_1)

{
                    /* 0x1970  1  MEM_Close */
  if ((param_1 != (int *)0x0) && (*param_1 != 0x155c)) {
    return 0;
  }
  if (param_1[1] != 0) {
    InterlockedDecrement(param_1 + 1);
  }
  return 1;
}



/* c09619c4 FUN_c09619c4 */

/* Boundary evidence: original MIPS .pdata c09619c4..c0961e3b. Semantic name remains unreviewed. */

undefined4 FUN_c09619c4(HKEY param_1,LPCWSTR param_2)

{
  WCHAR WVar1;
  int iVar2;
  int iVar3;
  wchar_t *lpValueName;
  wchar_t *lpValueName_00;
  LSTATUS LVar4;
  LPVOID pvVar5;
  LPCWSTR pWVar6;
  HKEY lpData;
  HKEY lpData_00;
  DWORD dwIndex;
  DWORD local_260 [2];
  HKEY local_258;
  int local_254;
  HKEY local_250;
  LPCWSTR local_24c;
  DWORD local_248;
  wchar_t *local_244;
  HKEY local_240;
  wchar_t *local_23c;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c09634a8;
  dwIndex = 0;
  local_254 = 0;
  pWVar6 = param_2;
  local_258 = param_1;
  local_24c = param_2;
  if ((LPCWSTR)0xffff < param_2) {
    do {
      WVar1 = *pWVar6;
      pWVar6 = pWVar6 + 1;
    } while (WVar1 != L'\0');
    local_260[0] = ((uint)((int)pWVar6 - (int)param_2) >> 1) - 1;
    if (local_260[0] != 0) {
      NKDbgPrintfW(L"MEMPOOL: Built on %s.%s\r\n",L"Nov 28 2014",L"11:54:44");
      LVar4 = RegOpenKeyExW((HKEY)&DAT_80000002,param_2,0,0,&local_240);
      if (LVar4 == 0) {
        local_260[0] = 0x104;
        RegQueryValueExW(local_240,L"Key",(LPDWORD)0x0,local_260 + 1,(LPBYTE)aWStack_238,local_260);
        LVar4 = RegOpenKeyExW((HKEY)&DAT_80000002,L"Drivers\\BuiltIn\\mempool\\Regions",0,0,
                              &local_250);
        if (LVar4 == 0) {
          local_248 = 0x104;
          LVar4 = RegEnumKeyExW(local_250,0,aWStack_238,&local_248,(LPDWORD)0x0,(LPWSTR)0x0,
                                (LPDWORD)0x0,(PFILETIME)0x0);
          if (LVar4 == 0) {
            local_24c = L"Base";
            local_23c = L"FriendlyName";
            local_244 = L"Index";
            do {
              lpValueName_00 = local_23c;
              lpValueName = local_244;
              pWVar6 = local_24c;
              dwIndex = dwIndex + 1;
              local_248 = 0x104;
              RegOpenKeyExW(local_250,aWStack_238,0,0,&local_258);
              local_260[1] = 4;
              local_260[0] = 4;
              RegQueryValueExW(local_258,lpValueName,(LPDWORD)0x0,local_260 + 1,(LPBYTE)&local_254,
                               local_260);
              iVar3 = local_254;
              iVar2 = local_254 * 0x88;
              local_260[1] = 1;
              local_260[0] = 0x208;
              RegQueryValueExW(local_258,lpValueName_00,(LPDWORD)0x0,local_260 + 1,
                               (LPBYTE)(param_1 + iVar2 + 7),local_260);
              local_260[1] = 4;
              local_260[0] = 4;
              lpData_00 = param_1 + iVar3 * 0x88 + 0x89;
              RegQueryValueExW(local_258,pWVar6,(LPDWORD)0x0,local_260 + 1,(LPBYTE)lpData_00,
                               local_260);
              local_260[1] = 4;
              local_260[0] = 4;
              lpData = param_1 + iVar3 * 0x88 + 0x8b;
              RegQueryValueExW(local_258,L"Size",(LPDWORD)0x0,local_260 + 1,(LPBYTE)lpData,local_260
                              );
              RegCloseKey(local_258);
              pvVar5 = VirtualAlloc((LPVOID)0x0,lpData->unused,0x2000,1);
              param_1[iVar3 * 0x88 + 0x8a].unused = (int)pvVar5;
              VirtualCopy(pvVar5,(uint)lpData_00->unused >> 8,lpData->unused,0x404);
              NKDbgPrintfW(L"MEMPOOL: Found %8s Memory Region(%d). Phys:0x%08X Virt:0x%08X Size:0x%08X\r\n"
                           ,param_1 + iVar2 + 7,local_254,lpData_00->unused,
                           param_1[iVar3 * 0x88 + 0x8a].unused,lpData->unused);
              LVar4 = RegEnumKeyExW(local_250,dwIndex,aWStack_238,&local_248,(LPDWORD)0x0,
                                    (LPWSTR)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
            } while (LVar4 == 0);
          }
          RegCloseKey(local_240);
          RegCloseKey(local_250);
          FUN_c09620c8(local_30);
          return 1;
        }
      }
    }
  }
  FUN_c09620c8(local_30);
  return 0;
}



/* c0961e3c FUN_c0961e3c */

/* Boundary evidence: original MIPS .pdata c0961e3c..c0961e47. Semantic name remains unreviewed. */

undefined4 FUN_c0961e3c(void)

{
  return 1;
}



/* c0961e48 entry */

/* Boundary evidence: original MIPS .pdata c0961e48..c0961e7b. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0961e7c MEM_Init */

/* Boundary evidence: original MIPS .pdata c0961e7c..c0961f6b. Semantic name remains unreviewed. */

HKEY MEM_Init(LPCWSTR param_1)

{
  HKEY _Dst;
  int iVar1;
  HKEY pHVar2;
  uint uVar3;
  
                    /* 0x1e7c  4  MEM_Init */
  _Dst = LocalAlloc(0x40,0x155c);
  if (_Dst != (HKEY)0x0) {
    memset(_Dst,0,0x155c);
    _Dst->unused = 0x155c;
    iVar1 = FUN_c09619c4(_Dst,param_1);
    if (iVar1 == 0) {
      NKDbgPrintfW(L"MEMPOOL: Failed to retrieve Region configuration from registry!\r\n");
    }
    else {
      InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 2));
      uVar3 = 0;
      pHVar2 = _Dst + 0x8a;
      while ((pHVar2->unused == 0 || (iVar1 = FUN_c0961604((int)(pHVar2 + -0x83)), iVar1 != 0))) {
        uVar3 = uVar3 + 1;
        pHVar2 = pHVar2 + 0x88;
        if (9 < uVar3) {
          return _Dst;
        }
      }
      NKDbgPrintfW(L"MEMPOOL: Failed to create POOL for %s region!\r\n",_Dst + uVar3 * 0x88 + 7);
    }
  }
  return (HKEY)0x0;
}



/* c096204c FUN_c096204c */

/* Boundary evidence: original MIPS .pdata c096204c..c09620c7. Semantic name remains unreviewed. */

void FUN_c096204c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c0962110(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c09620c8 FUN_c09620c8 */

/* Boundary evidence: original MIPS .pdata c09620c8..c096210f. Semantic name remains unreviewed. */

void FUN_c09620c8(uint param_1)

{
  if ((param_1 == DAT_c09634a8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0962110 FUN_c0962110 */

/* Boundary evidence: original MIPS .pdata c0962110..c0962163. Semantic name remains unreviewed. */

void FUN_c0962110(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c09620c8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}


