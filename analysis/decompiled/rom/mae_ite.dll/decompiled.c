/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c09c1000 FUN_c09c1000 */

/* Boundary evidence: original MIPS .pdata c09c1000..c09c11af. Semantic name remains unreviewed. */

void FUN_c09c1000(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0x30);
  *(undefined4 *)(param_2 + 0x398) = 0;
  if ((*(uint *)(param_2 + 4) & 1) != 0) {
    CacheRangeFlush(param_2,0x4000,4);
  }
  puVar2 = puVar5 + 0x40;
  puVar3 = (undefined4 *)(param_2 + 0x14);
  iVar4 = 0x20;
  do {
    iVar4 = iVar4 + -1;
    *puVar2 = *puVar3;
    puVar2[0x20] = puVar3[0x20];
    puVar2[0x40] = puVar3[0x40];
    puVar2[0x60] = puVar3[0x60];
    puVar2[0x80] = puVar3[0x80];
    puVar1 = puVar3 + 0xa0;
    puVar3 = puVar3 + 1;
    puVar2[0xa0] = *puVar1;
    puVar2 = puVar2 + 1;
  } while (iVar4 != 0);
  puVar5[0x100] = *(undefined4 *)(param_2 + 0x314);
  puVar5[0x101] = *(undefined4 *)(param_2 + 0x318);
  puVar5[0x102] = *(undefined4 *)(param_2 + 0x31c);
  puVar5[0x103] = *(undefined4 *)(param_2 + 800);
  puVar5[0x104] = *(undefined4 *)(param_2 + 0x324);
  puVar5[0x105] = *(undefined4 *)(param_2 + 0x328);
  puVar5[0x106] = *(undefined4 *)(param_2 + 0x32c);
  puVar5[0x107] = *(undefined4 *)(param_2 + 0x330);
  puVar5[0x108] = *(undefined4 *)(param_2 + 0x334);
  puVar5[0x109] = *(undefined4 *)(param_2 + 0x338);
  puVar5[0x10a] = *(undefined4 *)(param_2 + 0x33c);
  puVar5[0x10b] = *(undefined4 *)(param_2 + 0x340);
  puVar5[0x10c] = *(undefined4 *)(param_2 + 0x344);
  *puVar5 = *(undefined4 *)(param_2 + 8);
  puVar5[1] = *(undefined4 *)(param_2 + 0xc);
  puVar5[2] = *(undefined4 *)(param_2 + 0x10);
  puVar5[0x140] = *(undefined4 *)(param_2 + 0x348);
  puVar5[0x141] = *(undefined4 *)(param_2 + 0x34c);
  puVar5[0x142] = *(undefined4 *)(param_2 + 0x350);
  puVar5[0x144] = *(undefined4 *)(param_2 + 0x358);
  puVar5[0x146] = *(undefined4 *)(param_2 + 0x360);
  puVar5[0x143] = *(undefined4 *)(param_2 + 0x354);
  puVar5[0x145] = *(undefined4 *)(param_2 + 0x35c);
  puVar5[0x147] = *(undefined4 *)(param_2 + 0x364);
  puVar5[0x182] = *(undefined4 *)(param_2 + 0x370);
  puVar5[0x183] = *(undefined4 *)(param_2 + 0x374);
  puVar5[0x181] = *(undefined4 *)(param_2 + 0x36c);
  puVar5[0x180] = *(undefined4 *)(param_2 + 0x368);
  puVar5[0x1c4] = 0xffffffff;
  puVar5[0x1c3] = 1;
  puVar5[0x1c1] = 1;
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x1c),0xffffffff);
  return;
}



/* c09c11b0 ITE_IOControl */

/* Boundary evidence: original MIPS .pdata c09c11b0..c09c123b. Semantic name remains unreviewed. */

undefined4 ITE_IOControl(int param_1,int param_2,int *param_3)

{
                    /* 0x11b0  3  ITE_IOControl */
  if ((param_3 != (int *)0x0) && (param_1 != 0)) {
    if (*param_3 != 0x50903a0) {
      NKDbgPrintfW(L"maebe: bad magic %08X\n");
    }
    if (param_2 == 0x232008) {
      FUN_c09c1000(param_1,(int)param_3);
      return 1;
    }
  }
  return 0;
}



/* c09c123c ITE_PowerDown */

void ITE_PowerDown(void)

{
                    /* 0x123c  6  ITE_PowerDown
                       0x123c  7  ITE_PowerUp */
  return;
}



/* c09c1244 ITE_Init */

/* Boundary evidence: original MIPS .pdata c09c1244..c09c133b. Semantic name remains unreviewed. */

undefined4 * ITE_Init(void)

{
  undefined4 *_Dst;
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x1244  4  ITE_Init */
  _Dst = LocalAlloc(0x40,0x38);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x38);
    *_Dst = 0x38;
    iVar1 = MmMapIoSpace(0x14010000,0,0x714,0);
    _Dst[0xc] = iVar1;
    if (iVar1 != 0) {
      NKDbgPrintfW(L"ITE: Driver, v%d.%d %s.%s\r\n",1,0,L"Sep 26 2011",L"23:43:31");
      InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 1));
      iVar1 = _Dst[0xc];
      *(undefined4 *)(iVar1 + 0x700) = 1;
      *(undefined4 *)(iVar1 + 0x704) = 2;
      uVar2 = InterruptConnect(0,0,0x5c,0);
      _Dst[0xb] = uVar2;
      InterruptDone(uVar2);
      return _Dst;
    }
    LocalFree(_Dst);
  }
  return (undefined4 *)0x0;
}



/* c09c133c ITE_Deinit */

/* Boundary evidence: original MIPS .pdata c09c133c..c09c13a7. Semantic name remains unreviewed. */

int * ITE_Deinit(int *param_1)

{
                    /* 0x133c  2  ITE_Deinit */
  if (*param_1 != 0x38) {
    return (int *)0x0;
  }
  InterruptDisconnect(param_1[0xb]);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  MmUnmapIoSpace(param_1[0xc],0x714);
  LocalFree(param_1);
  return param_1;
}



/* c09c13a8 ITE_Close */

/* Boundary evidence: original MIPS .pdata c09c13a8..c09c147b. Semantic name remains unreviewed. */

undefined4 ITE_Close(int *param_1)

{
  undefined4 uVar1;
  LONG *lpAddend;
  
                    /* 0x13a8  1  ITE_Close */
  if (*param_1 == 0x38) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    lpAddend = param_1 + 6;
    if (*lpAddend != 0) {
      InterlockedDecrement(lpAddend);
    }
    if (*lpAddend == 0) {
      InterruptDisable(param_1[0xb]);
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



/* c09c147c FUN_c09c147c */

/* Boundary evidence: original MIPS .pdata c09c147c..c09c15a3. Semantic name remains unreviewed. */

undefined4 FUN_c09c147c(int *param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar2;
  
  iVar2 = param_1[0xc];
  if (*param_1 == 0x38) {
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
      EnterCriticalSection(lpCriticalSection);
      *(undefined4 *)(iVar2 + 0x710) = 0xffffffff;
      EventModify(param_1[7],3);
      LeaveCriticalSection(lpCriticalSection);
    }
    EventModify(param_1[8],3);
  }
  return 0;
}



/* c09c15a4 FUN_c09c15a4 */

/* Boundary evidence: original MIPS .pdata c09c15a4..c09c16af. Semantic name remains unreviewed. */

int * FUN_c09c15a4(int *param_1)

{
  HANDLE pvVar1;
  
  if (*param_1 != 0x38) {
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
        pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c09c147c,param_1,0,(LPDWORD)0x0);
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



/* c09c16b0 ITE_Open */

/* Boundary evidence: original MIPS .pdata c09c16b0..c09c1727. Semantic name remains unreviewed. */

int * ITE_Open(int *param_1)

{
                    /* 0x16b0  5  ITE_Open */
  if (*param_1 != 0x38) {
    return (int *)0x0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if (param_1[6] == 0) {
    param_1 = FUN_c09c15a4(param_1);
  }
  InterlockedIncrement(param_1 + 6);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return param_1;
}



/* c09c1878 FUN_c09c1878 */

/* Boundary evidence: original MIPS .pdata c09c1878..c09c19b3. Semantic name remains unreviewed. */

int FUN_c09c1878(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c09c34d8 != (code *)0x0) {
      iVar2 = (*DAT_c09c34d8)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c09c1928;
    FUN_c09c1bd8();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c09c1b58(param_1,param_2);
  }
LAB_c09c1928:
  if (((param_2 == 0) && (FUN_c09c1b34(), iVar1 != 0)) && (DAT_c09c34d8 != (code *)0x0)) {
    iVar1 = (*DAT_c09c34d8)(param_1,0,param_3);
  }
  return iVar1;
}



/* c09c19b4 FUN_c09c19b4 */

/* Boundary evidence: original MIPS .pdata c09c19b4..c09c19df. Semantic name remains unreviewed. */

void FUN_c09c19b4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c09c19e0 entry */

/* Boundary evidence: original MIPS .pdata c09c19e0..c09c1a37. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c09c1c24();
  }
  FUN_c09c1878(param_1,param_2,param_3);
  return;
}



/* c09c1a48 FUN_c09c1a48 */

/* Boundary evidence: original MIPS .pdata c09c1a48..c09c1b33. Semantic name remains unreviewed. */

void FUN_c09c1a48(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_c09c34cc = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c09c34d4;
    if (DAT_c09c34d4 != (undefined4 *)0x0) {
      while (DAT_c09c34d0 = DAT_c09c34d0 + -1, _Memory <= DAT_c09c34d0) {
        if ((code *)*DAT_c09c34d0 != (code *)0x0) {
          (*(code *)*DAT_c09c34d0)();
          _Memory = DAT_c09c34d4;
        }
      }
      free(_Memory);
      DAT_c09c34d0 = (undefined4 *)0x0;
      DAT_c09c34d4 = (undefined4 *)0x0;
    }
    FUN_c09c1b84((undefined4 *)&DAT_c09c2010,(undefined4 *)&DAT_c09c2014);
  }
  FUN_c09c1b84((undefined4 *)&DAT_c09c2018,(undefined4 *)&DAT_c09c201c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* c09c1b34 FUN_c09c1b34 */

/* Boundary evidence: original MIPS .pdata c09c1b34..c09c1b57. Semantic name remains unreviewed. */

void FUN_c09c1b34(void)

{
  FUN_c09c1a48(0,0,1);
  return;
}



/* c09c1b58 FUN_c09c1b58 */

/* Boundary evidence: original MIPS .pdata c09c1b58..c09c1b83. Semantic name remains unreviewed. */

undefined4 FUN_c09c1b58(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c09c1b84 FUN_c09c1b84 */

/* Boundary evidence: original MIPS .pdata c09c1b84..c09c1bd7. Semantic name remains unreviewed. */

void FUN_c09c1b84(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c09c1bd8 FUN_c09c1bd8 */

/* Boundary evidence: original MIPS .pdata c09c1bd8..c09c1c13. Semantic name remains unreviewed. */

void FUN_c09c1bd8(void)

{
  FUN_c09c1b84((undefined4 *)&DAT_c09c2008,(undefined4 *)&DAT_c09c200c);
  FUN_c09c1b84((undefined4 *)&DAT_c09c2000,(undefined4 *)&DAT_c09c2004);
  return;
}



/* c09c1c24 FUN_c09c1c24 */

/* Boundary evidence: original MIPS .pdata c09c1c24..c09c1c97. Semantic name remains unreviewed. */

void FUN_c09c1c24(void)

{
  uint uVar1;
  
  if ((DAT_c09c34c4 == 0) || (DAT_c09c34c4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c09c34c4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c09c34c4 == 0) {
      DAT_c09c34c4 = 0xb064;
    }
  }
  DAT_c09c34c8 = ~DAT_c09c34c4;
  return;
}


