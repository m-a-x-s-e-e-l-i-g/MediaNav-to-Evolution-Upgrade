/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c09d1000 FUN_c09d1000 */

/* Boundary evidence: original MIPS .pdata c09d1000..c09d116f. Semantic name remains unreviewed. */

void FUN_c09d1000(int param_1,int param_2)

{
  DWORD DVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x30);
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x44),0xffffffff);
  if ((*(uint *)(param_2 + 4) & 1) != 0) {
    CacheRangeFlush(param_2,0x4000,4);
  }
  if (*(int *)(param_1 + 0x40) != *(int *)(param_2 + 0x24)) {
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 3;
    *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x24);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 2;
  puVar2[1] = *(undefined4 *)(param_2 + 8);
  puVar2[2] = *(undefined4 *)(param_2 + 0xc);
  puVar2[3] = *(undefined4 *)(param_2 + 0x10);
  puVar2[4] = *(undefined4 *)(param_2 + 0x14);
  puVar2[5] = *(undefined4 *)(param_2 + 0x18);
  puVar2[6] = *(undefined4 *)(param_2 + 0x1c);
  puVar2[7] = *(undefined4 *)(param_2 + 0x20);
  puVar2[8] = *(undefined4 *)(param_2 + 0x24);
  puVar2[9] = *(undefined4 *)(param_2 + 0x28);
  puVar2[10] = *(undefined4 *)(param_2 + 0x2c);
  puVar2[0xb] = *(undefined4 *)(param_2 + 0x30);
  puVar2[0xc] = *(undefined4 *)(param_2 + 0x34);
  puVar2[0xd] = *(undefined4 *)(param_2 + 0x38);
  puVar2[0xe] = *(undefined4 *)(param_2 + 0x3c);
  puVar2[0xf] = *(undefined4 *)(param_2 + 0x40);
  puVar2[0x12] = *(undefined4 *)(param_2 + 0x44);
  puVar2[0x13] = 1;
  *puVar2 = 1;
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x1c),*(DWORD *)(param_1 + 0x38));
  if (DVar1 == 0x102) {
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 3;
  }
  return;
}



/* c09d1170 MPE_IOControl */

/* Boundary evidence: original MIPS .pdata c09d1170..c09d11ff. Semantic name remains unreviewed. */

undefined4 MPE_IOControl(int param_1,int param_2,int *param_3)

{
                    /* 0x1170  3  MPE_IOControl */
  if ((param_3 != (int *)0x0) && (param_1 != 0)) {
    if (*param_3 == 0x4050050) {
      if (param_2 != 0x232010) {
        NKDbgPrintfW(L"BAD MPE IOCODE %08X\r\n");
        return 0;
      }
      FUN_c09d1000(param_1,(int)param_3);
      return 1;
    }
    NKDbgPrintfW(L"BAD MPE_IOControl %08X\r\n",*param_3);
  }
  return 0;
}



/* c09d1200 MPE_Init */

/* Boundary evidence: original MIPS .pdata c09d1200..c09d134b. Semantic name remains unreviewed. */

undefined4 * MPE_Init(void)

{
  undefined4 *_Dst;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x1200  4  MPE_Init */
  _Dst = LocalAlloc(0x40,0x48);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x48);
    *_Dst = 0x48;
    iVar1 = MmMapIoSpace(0x14014000,0,0x50,0);
    _Dst[0xc] = iVar1;
    if (iVar1 != 0) {
      iVar1 = MmMapIoSpace(0x11003000,0,0x30,0);
      _Dst[0xd] = iVar1;
      if (iVar1 != 0) {
        _Dst[0xe] = 300;
        InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 1));
        local_20 = 0;
        local_1c = 0;
        uVar3 = 0;
        uVar2 = 0;
        KernelIoControl(0x1032c9f,&local_20,0x10,0,0,0);
        iVar1 = _Dst[0xd];
        *(undefined4 *)(iVar1 + 4) = 3;
        uVar2 = InterruptConnect(0,0,0x5d,0,uVar2,uVar3,*(undefined4 *)(iVar1 + 4));
        _Dst[0xb] = uVar2;
        InterruptDone(uVar2);
        NKDbgPrintfW(L"MPE: Driver, v%d.%d %s.%s\r\n",1,2,L"Sep 26 2011",L"23:43:32");
        return _Dst;
      }
    }
    LocalFree(_Dst);
  }
  return (undefined4 *)0x0;
}



/* c09d134c MPE_Deinit */

/* Boundary evidence: original MIPS .pdata c09d134c..c09d13f3. Semantic name remains unreviewed. */

int * MPE_Deinit(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x134c  2  MPE_Deinit */
  if (*param_1 != 0x48) {
    return (int *)0x0;
  }
  InterruptDisconnect(param_1[0xb]);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  MmUnmapIoSpace(param_1[0xc],0x50);
  LocalFree(param_1);
  local_18 = 0;
  local_14 = 0;
  KernelIoControl(0x1032c9f,&local_18,0x10,0,0,0);
  *(undefined4 *)(param_1[0xd] + 4) = 3;
  return param_1;
}



/* c09d13f4 MPE_Close */

/* Boundary evidence: original MIPS .pdata c09d13f4..c09d150f. Semantic name remains unreviewed. */

undefined4 MPE_Close(int *param_1)

{
  undefined4 uVar1;
  LONG *lpAddend;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x13f4  1  MPE_Close */
  if (*param_1 == 0x48) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    lpAddend = param_1 + 6;
    if (*lpAddend != 0) {
      InterlockedDecrement(lpAddend);
    }
    if (*lpAddend == 0) {
      InterruptDisable(param_1[0xb]);
      local_20 = 0;
      local_1c = 0;
      KernelIoControl(0x1032c9f,&local_20,0x10,0,0,0);
      *(undefined4 *)(param_1[0xd] + 4) = 3;
      WaitForSingleObject((HANDLE)param_1[8],10);
      CloseHandle((HANDLE)param_1[9]);
      CloseHandle((HANDLE)param_1[10]);
      CloseHandle((HANDLE)param_1[7]);
      CloseHandle((HANDLE)param_1[8]);
      CloseHandle((HANDLE)param_1[0x11]);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c09d1510 FUN_c09d1510 */

/* Boundary evidence: original MIPS .pdata c09d1510..c09d1627. Semantic name remains unreviewed. */

undefined4 FUN_c09d1510(int *param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (*param_1 == 0x48) {
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
      EventModify(param_1[0x11],3);
      WaitForSingleObject((HANDLE)param_1[9],0xffffffff);
      EnterCriticalSection(lpCriticalSection);
      EventModify(param_1[7],3);
      LeaveCriticalSection(lpCriticalSection);
    }
    EventModify(param_1[8],3);
  }
  return 0;
}



/* c09d1628 MPE_PowerDown */

/* Boundary evidence: original MIPS .pdata c09d1628..c09d169f. Semantic name remains unreviewed. */

void MPE_PowerDown(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1628  6  MPE_PowerDown */
  if (*(HANDLE *)(param_1 + 0x24) != (HANDLE)0x0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x24),0x32);
  }
  local_18 = 0;
  local_14 = 0;
  KernelIoControl(0x1032c9f,&local_18,0x10,0,0,0);
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 3;
  return;
}



/* c09d16a0 MPE_PowerUp */

/* Boundary evidence: original MIPS .pdata c09d16a0..c09d173b. Semantic name remains unreviewed. */

void MPE_PowerUp(int param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x16a0  7  MPE_PowerUp */
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  if (0 < *(int *)(param_1 + 0x18)) {
    iVar1 = *(int *)(param_1 + 0x34);
    *(undefined4 *)(iVar1 + 4) = 3;
    local_20 = 0;
    local_1c = 1;
    KernelIoControl(0x1032c9f,&local_20,0x10,0,0,0,*(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



/* c09d173c FUN_c09d173c */

/* Boundary evidence: original MIPS .pdata c09d173c..c09d1873. Semantic name remains unreviewed. */

int * FUN_c09d173c(int *param_1)

{
  HANDLE pvVar1;
  
  if (*param_1 != 0x48) {
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
        pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
        param_1[0x11] = (int)pvVar1;
        if (pvVar1 != (HANDLE)0x0) {
          EventModify(pvVar1,2);
          pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c09d1510,param_1,0,(LPDWORD)0x0);
          param_1[10] = (int)pvVar1;
          if (pvVar1 != (HANDLE)0x0) {
            CeSetThreadPriority(pvVar1,0);
            return param_1;
          }
        }
      }
    }
  }
  return (int *)0x1;
}



/* c09d1874 MPE_Open */

/* Boundary evidence: original MIPS .pdata c09d1874..c09d193f. Semantic name remains unreviewed. */

int * MPE_Open(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1874  5  MPE_Open */
  if (*param_1 != 0x48) {
    return (int *)0x0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if (param_1[6] == 0) {
    iVar1 = param_1[0xd];
    *(undefined4 *)(iVar1 + 4) = 3;
    local_18 = 0;
    local_14 = 1;
    KernelIoControl(0x1032c9f,&local_18,0x10,0,0,0,*(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(param_1[0xd] + 4) = 2;
    param_1 = FUN_c09d173c(param_1);
  }
  InterlockedIncrement(param_1 + 6);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return param_1;
}



/* c09d1aa0 FUN_c09d1aa0 */

/* Boundary evidence: original MIPS .pdata c09d1aa0..c09d1bdb. Semantic name remains unreviewed. */

int FUN_c09d1aa0(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c09d34e4 != (code *)0x0) {
      iVar2 = (*DAT_c09d34e4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c09d1b50;
    FUN_c09d1e00();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c09d1d80(param_1,param_2);
  }
LAB_c09d1b50:
  if (((param_2 == 0) && (FUN_c09d1d5c(), iVar1 != 0)) && (DAT_c09d34e4 != (code *)0x0)) {
    iVar1 = (*DAT_c09d34e4)(param_1,0,param_3);
  }
  return iVar1;
}



/* c09d1bdc FUN_c09d1bdc */

/* Boundary evidence: original MIPS .pdata c09d1bdc..c09d1c07. Semantic name remains unreviewed. */

void FUN_c09d1bdc(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c09d1c08 entry */

/* Boundary evidence: original MIPS .pdata c09d1c08..c09d1c5f. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c09d1e4c();
  }
  FUN_c09d1aa0(param_1,param_2,param_3);
  return;
}



/* c09d1c70 FUN_c09d1c70 */

/* Boundary evidence: original MIPS .pdata c09d1c70..c09d1d5b. Semantic name remains unreviewed. */

void FUN_c09d1c70(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_c09d34d8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c09d34e0;
    if (DAT_c09d34e0 != (undefined4 *)0x0) {
      while (DAT_c09d34dc = DAT_c09d34dc + -1, _Memory <= DAT_c09d34dc) {
        if ((code *)*DAT_c09d34dc != (code *)0x0) {
          (*(code *)*DAT_c09d34dc)();
          _Memory = DAT_c09d34e0;
        }
      }
      free(_Memory);
      DAT_c09d34dc = (undefined4 *)0x0;
      DAT_c09d34e0 = (undefined4 *)0x0;
    }
    FUN_c09d1dac((undefined4 *)&DAT_c09d2010,(undefined4 *)&DAT_c09d2014);
  }
  FUN_c09d1dac((undefined4 *)&DAT_c09d2018,(undefined4 *)&DAT_c09d201c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* c09d1d5c FUN_c09d1d5c */

/* Boundary evidence: original MIPS .pdata c09d1d5c..c09d1d7f. Semantic name remains unreviewed. */

void FUN_c09d1d5c(void)

{
  FUN_c09d1c70(0,0,1);
  return;
}



/* c09d1d80 FUN_c09d1d80 */

/* Boundary evidence: original MIPS .pdata c09d1d80..c09d1dab. Semantic name remains unreviewed. */

undefined4 FUN_c09d1d80(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c09d1dac FUN_c09d1dac */

/* Boundary evidence: original MIPS .pdata c09d1dac..c09d1dff. Semantic name remains unreviewed. */

void FUN_c09d1dac(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c09d1e00 FUN_c09d1e00 */

/* Boundary evidence: original MIPS .pdata c09d1e00..c09d1e3b. Semantic name remains unreviewed. */

void FUN_c09d1e00(void)

{
  FUN_c09d1dac((undefined4 *)&DAT_c09d2008,(undefined4 *)&DAT_c09d200c);
  FUN_c09d1dac((undefined4 *)&DAT_c09d2000,(undefined4 *)&DAT_c09d2004);
  return;
}



/* c09d1e4c FUN_c09d1e4c */

/* Boundary evidence: original MIPS .pdata c09d1e4c..c09d1ebf. Semantic name remains unreviewed. */

void FUN_c09d1e4c(void)

{
  uint uVar1;
  
  if ((DAT_c09d34c8 == 0) || (DAT_c09d34c8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c09d34c8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c09d34c8 == 0) {
      DAT_c09d34c8 = 0xb064;
    }
  }
  DAT_c09d34cc = ~DAT_c09d34c8;
  return;
}


