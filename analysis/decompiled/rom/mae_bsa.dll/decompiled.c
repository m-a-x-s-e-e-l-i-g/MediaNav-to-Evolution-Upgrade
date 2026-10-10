/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c09b1000 FUN_c09b1000 */

/* Boundary evidence: original MIPS .pdata c09b1000..c09b131f. Semantic name remains unreviewed. */

bool FUN_c09b1000(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  DWORD DVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  iVar15 = *(int *)(param_1 + 0x30);
  bVar1 = *(int *)(param_2 + 0x24) != 0;
  bVar2 = *(int *)(param_2 + 0x2c) != 0;
  bVar3 = *(int *)(param_2 + 0x54) != 0;
  bVar4 = *(int *)(param_2 + 0x3c) != 0;
  bVar5 = *(int *)(param_2 + 0x48) != 0;
  bVar6 = *(int *)(param_2 + 0x40) != 0;
  bVar7 = *(int *)(param_2 + 0x4c) != 0;
  bVar8 = *(int *)(param_2 + 0x34) != 0;
  bVar9 = *(int *)(param_2 + 0x58) != 0;
  if ((*(int *)(param_2 + 0x5c) == 0) ||
     (!bVar9 || (!bVar8 ||
                (!bVar7 || (!bVar6 || (!bVar5 || (!bVar4 || (!bVar3 || (!bVar2 || !bVar1))))))))) {
    NKDbgPrintfW(L"Problem with BSA request\r\n");
    bVar12 = false;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 3;
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 2;
    *(undefined4 *)(iVar15 + 0x7440) = *(undefined4 *)(param_2 + 0x3c);
    *(undefined4 *)(iVar15 + 0x7444) = *(undefined4 *)(param_2 + 0x40);
    *(undefined4 *)(iVar15 + 0x7480) = *(undefined4 *)(param_2 + 0x48);
    *(undefined4 *)(iVar15 + 0x7484) = *(undefined4 *)(param_2 + 0x4c);
    iVar16 = 0x100000;
    *(uint *)(iVar15 + 0x7448) = *(uint *)(param_2 + 0x44) | 2;
    *(uint *)(iVar15 + 0x7488) = *(uint *)(param_2 + 0x50) | 2;
    *(undefined4 *)(iVar15 + 0x7654) = *(undefined4 *)(param_2 + 0x54);
    *(undefined4 *)(iVar15 + 0x74c0) = 0x8000;
    iVar14 = 0x100000;
    *(undefined4 *)(iVar15 + 0x74c4) = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 *)(iVar15 + 0x74d0) = *(undefined4 *)(param_2 + 0x28);
    *(uint *)(iVar15 + 0x74c8) = *(uint *)(param_2 + 0x20) | 3;
    do {
      if ((*(uint *)(iVar15 + 0x74cc) & 1) != 0) break;
      iVar14 = iVar14 + -1;
    } while (0 < iVar14);
    bVar10 = iVar14 != 0;
    if (!bVar10) {
      NKDbgPrintfW(L"error: IRAM load failed\n");
    }
    *(undefined4 *)(iVar15 + 0x74c0) = 0;
    *(undefined4 *)(iVar15 + 0x74c4) = *(undefined4 *)(param_2 + 0x2c);
    *(undefined4 *)(iVar15 + 0x74d0) = *(undefined4 *)(param_2 + 0x30);
    *(uint *)(iVar15 + 0x74c8) = *(uint *)(param_2 + 0x20) | 3;
    do {
      if ((*(uint *)(iVar15 + 0x74cc) & 1) != 0) break;
      iVar16 = iVar16 + -1;
    } while (0 < iVar16);
    bVar11 = iVar16 != 0;
    if (!bVar11) {
      NKDbgPrintfW(L"error: DRAM load failed\n");
    }
    bVar12 = bVar11 && (bVar10 &&
                       (bVar9 && (bVar8 && (bVar7 && (bVar6 && (bVar5 && (bVar4 && (bVar3 && (bVar2 
                                                  && bVar1)))))))));
    *(undefined4 *)(iVar15 + 0x7408) = *(undefined4 *)(param_2 + 0x60);
    *(undefined4 *)(iVar15 + 0x7410) = *(undefined4 *)(param_2 + 100);
    *(undefined4 *)(iVar15 + 0x7404) = 0;
    *(undefined4 *)(iVar15 + 0x7400) = *(undefined4 *)(param_2 + 0x58);
    *(undefined4 *)(iVar15 + 0x7404) = *(undefined4 *)(param_2 + 0x5c);
    *(undefined4 *)(iVar15 + 0x7584) = *(undefined4 *)(param_2 + 0x34);
    *(undefined4 *)(iVar15 + 0x764c) = 0;
    *(undefined4 *)(iVar15 + 0x7658) = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(iVar15 + 0x765c) = *(undefined4 *)(param_2 + 0x18);
    *(undefined4 *)(iVar15 + 0x7660) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(iVar15 + 0x7668) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)(iVar15 + 0x764c) = 0;
    *(undefined4 *)(iVar15 + 0x7650) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)(iVar15 + 0x7640) = *(undefined4 *)(param_2 + 0xc);
    if (bVar11 && (bVar10 &&
                  (bVar9 && (bVar8 && (bVar7 && (bVar6 && (bVar5 && (bVar4 && (bVar3 && (bVar2 && 
                                                  bVar1)))))))))) {
      *(undefined4 *)(iVar15 + 0x7644) = 1;
      DVar13 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x1c),*(DWORD *)(param_1 + 0x38));
      if ((DVar13 == 0x102) || (*(int *)(iVar15 + 0x764c) != 0x80)) {
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 3;
      }
    }
    *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1 + 0x3c);
    *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_1 + 0x40);
    *(undefined4 *)(param_2 + 0x70) = *(undefined4 *)(param_1 + 0x44);
    *(undefined4 *)(param_2 + 0x74) = *(undefined4 *)(param_1 + 0x48);
    *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(param_1 + 0x50);
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x54);
    *(undefined4 *)(param_2 + 0x84) = *(undefined4 *)(param_1 + 0x58);
  }
  return bVar12;
}



/* c09b1320 BSA_IOControl */

/* Boundary evidence: original MIPS .pdata c09b1320..c09b13ab. Semantic name remains unreviewed. */

bool BSA_IOControl(int param_1,int param_2,int *param_3)

{
  bool bVar1;
  
                    /* 0x1320  3  BSA_IOControl */
  if ((param_3 != (int *)0x0) && (param_1 != 0)) {
    if (*param_3 == 0x3210090) {
      if (param_2 != 0x23200c) {
        NKDbgPrintfW(L"BAD BSA_IOControl request %08X\r\n");
        return false;
      }
      bVar1 = FUN_c09b1000(param_1,(int)param_3);
      return bVar1;
    }
    NKDbgPrintfW(L"BAD BSA_IOControl %08X\r\n",*param_3);
  }
  return false;
}



/* c09b13ac BSA_Init */

/* Boundary evidence: original MIPS .pdata c09b13ac..c09b14f7. Semantic name remains unreviewed. */

undefined4 * BSA_Init(void)

{
  undefined4 *_Dst;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x13ac  4  BSA_Init */
  _Dst = LocalAlloc(0x40,0x60);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x60);
    *_Dst = 0x60;
    iVar1 = MmMapIoSpace(0x14030000,0,0x10000,0);
    _Dst[0xc] = iVar1;
    if (iVar1 != 0) {
      iVar1 = MmMapIoSpace(0x11003000,0,0x30,0);
      _Dst[0xd] = iVar1;
      if (iVar1 != 0) {
        _Dst[0xe] = 300;
        InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 1));
        local_20 = 1;
        local_1c = 0;
        uVar3 = 0;
        uVar2 = 0;
        KernelIoControl(0x1032c9f,&local_20,0x10,0,0,0);
        iVar1 = _Dst[0xd];
        *(undefined4 *)(iVar1 + 0x10) = 3;
        uVar2 = InterruptConnect(0,0,0x5e,0,uVar2,uVar3,*(undefined4 *)(iVar1 + 0x10));
        _Dst[0xb] = uVar2;
        InterruptDone(uVar2);
        NKDbgPrintfW(L"BSA: Driver, v%d.%d %s.%s\r\n",1,2,L"Sep 26 2011",L"23:43:31");
        return _Dst;
      }
    }
    LocalFree(_Dst);
  }
  return (undefined4 *)0x0;
}



/* c09b14f8 BSA_Deinit */

/* Boundary evidence: original MIPS .pdata c09b14f8..c09b15a3. Semantic name remains unreviewed. */

int * BSA_Deinit(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x14f8  2  BSA_Deinit */
  if (*param_1 != 0x60) {
    return (int *)0x0;
  }
  InterruptDisconnect(param_1[0xb]);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  MmUnmapIoSpace(param_1[0xc],0x10000);
  LocalFree(param_1);
  local_18 = 1;
  local_14 = 0;
  KernelIoControl(0x1032c9f,&local_18,0x10,0,0,0);
  *(undefined4 *)(param_1[0xd] + 0x10) = 3;
  return param_1;
}



/* c09b15a4 BSA_Close */

/* Boundary evidence: original MIPS .pdata c09b15a4..c09b16bb. Semantic name remains unreviewed. */

undefined4 BSA_Close(int *param_1)

{
  undefined4 uVar1;
  LONG *lpAddend;
  undefined4 local_28;
  undefined4 local_24;
  
                    /* 0x15a4  1  BSA_Close */
  if (*param_1 == 0x60) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    lpAddend = param_1 + 6;
    if (*lpAddend != 0) {
      InterlockedDecrement(lpAddend);
    }
    if (*lpAddend == 0) {
      InterruptDisable(param_1[0xb]);
      local_28 = 1;
      local_24 = 0;
      KernelIoControl(0x1032c9f,&local_28,0x10,0,0,0);
      *(undefined4 *)(param_1[0xd] + 0x10) = 3;
      WaitForSingleObject((HANDLE)param_1[8],10);
      CloseHandle((HANDLE)param_1[9]);
      CloseHandle((HANDLE)param_1[10]);
      CloseHandle((HANDLE)param_1[7]);
      CloseHandle((HANDLE)param_1[8]);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c09b16bc FUN_c09b16bc */

/* Boundary evidence: original MIPS .pdata c09b16bc..c09b1813. Semantic name remains unreviewed. */

undefined4 FUN_c09b16bc(int *param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar2;
  
  iVar2 = param_1[0xc];
  if (*param_1 == 0x60) {
    CeSetThreadPriority(0x41,0);
    iVar1 = InterruptInitialize(param_1[0xb],param_1[9],0,0);
    if (iVar1 != 1) {
      return 1;
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
    while( true ) {
      EnterCriticalSection(lpCriticalSection);
      iVar1 = param_1[6];
      LeaveCriticalSection(lpCriticalSection);
      if (iVar1 < 1) break;
      InterruptDone(param_1[0xb]);
      WaitForSingleObject((HANDLE)param_1[9],0xffffffff);
      param_1[0xf] = *(int *)(iVar2 + 0x764c);
      param_1[0x10] = *(int *)(iVar2 + 0x7440);
      param_1[0x11] = *(int *)(iVar2 + 0x7480);
      param_1[0x12] = *(int *)(iVar2 + 0x7654);
      param_1[0x13] = *(int *)(iVar2 + 0x7658);
      param_1[0x14] = *(int *)(iVar2 + 0x765c);
      param_1[0x15] = *(int *)(iVar2 + 0x7660);
      param_1[0x16] = *(int *)(iVar2 + 0x7424);
      EnterCriticalSection(lpCriticalSection);
      *(undefined4 *)(iVar2 + 0x764c) = 0;
      EventModify(param_1[7],3);
      LeaveCriticalSection(lpCriticalSection);
    }
    EventModify(param_1[8],3);
  }
  return 0;
}



/* c09b1814 BSA_PowerDown */

/* Boundary evidence: original MIPS .pdata c09b1814..c09b188f. Semantic name remains unreviewed. */

void BSA_PowerDown(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1814  6  BSA_PowerDown */
  if (*(HANDLE *)(param_1 + 0x24) != (HANDLE)0x0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x24),0x32);
  }
  local_18 = 1;
  local_14 = 0;
  KernelIoControl(0x1032c9f,&local_18,0x10,0,0,0);
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 3;
  return;
}



/* c09b1890 BSA_PowerUp */

/* Boundary evidence: original MIPS .pdata c09b1890..c09b192b. Semantic name remains unreviewed. */

void BSA_PowerUp(int param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x1890  7  BSA_PowerUp */
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  if (0 < *(int *)(param_1 + 0x18)) {
    iVar1 = *(int *)(param_1 + 0x34);
    *(undefined4 *)(iVar1 + 0x10) = 3;
    local_20 = 1;
    local_1c = 1;
    KernelIoControl(0x1032c9f,&local_20,0x10,0,0,0,*(undefined4 *)(iVar1 + 0x10));
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



/* c09b192c FUN_c09b192c */

/* Boundary evidence: original MIPS .pdata c09b192c..c09b1a37. Semantic name remains unreviewed. */

int * FUN_c09b192c(int *param_1)

{
  HANDLE pvVar1;
  
  if (*param_1 != 0x60) {
    return (int *)0x0;
  }
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[7] = (int)pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    param_1[8] = (int)pvVar1;
    if (pvVar1 != (HANDLE)0x0) {
      pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      param_1[9] = (int)pvVar1;
      if (pvVar1 != (HANDLE)0x0) {
        pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c09b16bc,param_1,0,(LPDWORD)0x0);
        param_1[10] = (int)pvVar1;
        if (pvVar1 != (HANDLE)0x0) {
          CeSetThreadPriority(pvVar1,0);
          return param_1;
        }
      }
    }
  }
  return (int *)0x1;
}



/* c09b1a38 BSA_Open */

/* Boundary evidence: original MIPS .pdata c09b1a38..c09b1b03. Semantic name remains unreviewed. */

int * BSA_Open(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1a38  5  BSA_Open */
  if (*param_1 != 0x60) {
    return (int *)0x0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if (param_1[6] == 0) {
    iVar1 = param_1[0xd];
    *(undefined4 *)(iVar1 + 0x10) = 3;
    local_18 = 1;
    local_14 = 1;
    KernelIoControl(0x1032c9f,&local_18,0x10,0,0,0,*(undefined4 *)(iVar1 + 0x10));
    *(undefined4 *)(param_1[0xd] + 0x10) = 2;
    param_1 = FUN_c09b192c(param_1);
  }
  InterlockedIncrement(param_1 + 6);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return param_1;
}



/* c09b1c54 FUN_c09b1c54 */

/* Boundary evidence: original MIPS .pdata c09b1c54..c09b1d8f. Semantic name remains unreviewed. */

int FUN_c09b1c54(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c09b44d8 != (code *)0x0) {
      iVar2 = (*DAT_c09b44d8)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c09b1d04;
    FUN_c09b1fb4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c09b1f34(param_1,param_2);
  }
LAB_c09b1d04:
  if (((param_2 == 0) && (FUN_c09b1f10(), iVar1 != 0)) && (DAT_c09b44d8 != (code *)0x0)) {
    iVar1 = (*DAT_c09b44d8)(param_1,0,param_3);
  }
  return iVar1;
}



/* c09b1d90 FUN_c09b1d90 */

/* Boundary evidence: original MIPS .pdata c09b1d90..c09b1dbb. Semantic name remains unreviewed. */

void FUN_c09b1d90(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c09b1dbc entry */

/* Boundary evidence: original MIPS .pdata c09b1dbc..c09b1e13. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c09b2000();
  }
  FUN_c09b1c54(param_1,param_2,param_3);
  return;
}



/* c09b1e24 FUN_c09b1e24 */

/* Boundary evidence: original MIPS .pdata c09b1e24..c09b1f0f. Semantic name remains unreviewed. */

void FUN_c09b1e24(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_c09b44cc = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c09b44d4;
    if (DAT_c09b44d4 != (undefined4 *)0x0) {
      while (DAT_c09b44d0 = DAT_c09b44d0 + -1, _Memory <= DAT_c09b44d0) {
        if ((code *)*DAT_c09b44d0 != (code *)0x0) {
          (*(code *)*DAT_c09b44d0)();
          _Memory = DAT_c09b44d4;
        }
      }
      free(_Memory);
      DAT_c09b44d0 = (undefined4 *)0x0;
      DAT_c09b44d4 = (undefined4 *)0x0;
    }
    FUN_c09b1f60((undefined4 *)&DAT_c09b3010,(undefined4 *)&DAT_c09b3014);
  }
  FUN_c09b1f60((undefined4 *)&DAT_c09b3018,(undefined4 *)&DAT_c09b301c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* c09b1f10 FUN_c09b1f10 */

/* Boundary evidence: original MIPS .pdata c09b1f10..c09b1f33. Semantic name remains unreviewed. */

void FUN_c09b1f10(void)

{
  FUN_c09b1e24(0,0,1);
  return;
}



/* c09b1f34 FUN_c09b1f34 */

/* Boundary evidence: original MIPS .pdata c09b1f34..c09b1f5f. Semantic name remains unreviewed. */

undefined4 FUN_c09b1f34(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c09b1f60 FUN_c09b1f60 */

/* Boundary evidence: original MIPS .pdata c09b1f60..c09b1fb3. Semantic name remains unreviewed. */

void FUN_c09b1f60(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c09b1fb4 FUN_c09b1fb4 */

/* Boundary evidence: original MIPS .pdata c09b1fb4..c09b1fef. Semantic name remains unreviewed. */

void FUN_c09b1fb4(void)

{
  FUN_c09b1f60((undefined4 *)&DAT_c09b3008,(undefined4 *)&DAT_c09b300c);
  FUN_c09b1f60((undefined4 *)&DAT_c09b3000,(undefined4 *)&DAT_c09b3004);
  return;
}



/* c09b2000 FUN_c09b2000 */

/* Boundary evidence: original MIPS .pdata c09b2000..c09b2073. Semantic name remains unreviewed. */

void FUN_c09b2000(void)

{
  uint uVar1;
  
  if ((DAT_c09b44c4 == 0) || (DAT_c09b44c4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c09b44c4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c09b44c4 == 0) {
      DAT_c09b44c4 = 0xb064;
    }
  }
  DAT_c09b44c8 = ~DAT_c09b44c4;
  return;
}


