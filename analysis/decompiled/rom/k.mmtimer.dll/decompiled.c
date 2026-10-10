/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0731098 FUN_c0731098 */

/* Boundary evidence: original MIPS .pdata c0731098..c0731143. Semantic name remains unreviewed. */

int FUN_c0731098(void)

{
  uint uVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
  iVar2 = 0;
  uVar1 = 0;
  while ((*(int *)((int)&DAT_c07330d4 + uVar1) != 0 || (*(int *)((int)&DAT_c07330dc + uVar1) != 0)))
  {
    uVar1 = uVar1 + 0x28;
    iVar2 = iVar2 + 1;
    if (0x27f < uVar1) {
LAB_c0731124:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
      return iVar2;
    }
  }
  (&DAT_c07330dc)[iVar2 * 10] = 1;
  goto LAB_c0731124;
}



/* c0731144 FUN_c0731144 */

/* Boundary evidence: original MIPS .pdata c0731144..c073121b. Semantic name remains unreviewed. */

undefined4 FUN_c0731144(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
  if (DAT_c07330b0 == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
LAB_c0731188:
    uVar3 = 1;
    DAT_c07330b0 = param_1;
  }
  else {
    iVar1 = DAT_c07330b0;
    do {
      if (0 < *(int *)(iVar1 + 0x18) - *(int *)(param_1 + 0x18)) {
        *(int *)(param_1 + 0x20) = iVar1;
        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
        *(int *)(iVar1 + 0x24) = param_1;
        if (*(int *)(param_1 + 0x24) == 0) goto LAB_c0731188;
        *(int *)(*(int *)(param_1 + 0x24) + 0x20) = param_1;
        break;
      }
      iVar2 = *(int *)(iVar1 + 0x20);
      if (iVar2 == 0) {
        *(int *)(iVar1 + 0x20) = param_1;
        *(int *)(param_1 + 0x24) = iVar1;
        *(undefined4 *)(param_1 + 0x20) = 0;
        break;
      }
      iVar1 = iVar2;
    } while (iVar2 != 0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
  return uVar3;
}



/* c073121c FUN_c073121c */

/* Boundary evidence: original MIPS .pdata c073121c..c07312a7. Semantic name remains unreviewed. */

bool FUN_c073121c(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
  if (*(int *)(param_1 + 0x20) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24) = *(undefined4 *)(param_1 + 0x24);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    DAT_c07330b0 = *(undefined4 *)(param_1 + 0x20);
  }
  else {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_1 + 0x20);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
  return iVar1 == 0;
}



/* c07312a8 FUN_c07312a8 */

/* Boundary evidence: original MIPS .pdata c07312a8..c073137f. Semantic name remains unreviewed. */

bool FUN_c07312a8(void)

{
  int iVar1;
  DWORD DVar2;
  bool bVar3;
  
  bVar3 = false;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
  do {
    iVar1 = DAT_c07330b0;
    if (DAT_c07330b0 == 0) {
LAB_c0731300:
      DAT_c0733074 = -1;
LAB_c0731310:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
      return bVar3;
    }
    if (*(int *)(DAT_c07330b0 + 0x1c) != 0) {
      DVar2 = GetTickCount();
      DAT_c0733074 = *(int *)(iVar1 + 0x18) - DVar2;
      bVar3 = DAT_c0733074 < DAT_c0733070;
      if (DAT_c07330b0 != 0) goto LAB_c0731310;
      goto LAB_c0731300;
    }
    FUN_c073121c(DAT_c07330b0);
    *(undefined4 *)(iVar1 + 0x14) = 0;
  } while( true );
}



/* c0731380 FUN_c0731380 */

/* Boundary evidence: original MIPS .pdata c0731380..c07314d3. Semantic name remains unreviewed. */

void FUN_c0731380(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_c07330ac != (HANDLE)0x0) {
    uVar1 = CeGetThreadPriority(0x41);
    uVar2 = CeGetThreadPriority(DAT_c07330ac);
    DAT_c0733078 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
    DAT_c07330b0 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
    if (uVar1 <= uVar2) {
      if (uVar1 < 0xf9) {
        SetThreadPriority((HANDLE)0x41,3);
        SetThreadPriority(DAT_c07330ac,2);
      }
      else {
        CeSetThreadPriority(DAT_c07330ac,uVar1 - 1);
      }
    }
    EventModify(DAT_c07330a0,3);
    CeSetThreadPriority(0x41,uVar1);
    WaitForSingleObject(DAT_c07330ac,10000);
    CloseHandle(DAT_c07330a0);
    CloseHandle(DAT_c07330ac);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0733360);
  }
  return;
}



/* c07314d4 timeBeginPeriod */

/* Boundary evidence: original MIPS .pdata c07314d4..c07315a3. Semantic name remains unreviewed. */

MMRESULT timeBeginPeriod(UINT uPeriod)

{
  short sVar1;
  MMRESULT MVar2;
  
                    /* 0x14d4  1  timeBeginPeriod */
  if (uPeriod == 0) {
    MVar2 = 0x61;
  }
  else if (uPeriod < DAT_c073306c) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733360);
    sVar1 = *(short *)(&DAT_c073339e + uPeriod * 2);
    if (sVar1 == -1) {
      MVar2 = 0x61;
    }
    else {
      *(short *)(&DAT_c073339e + uPeriod * 2) = sVar1 + 1;
      if ((sVar1 == 0) && (uPeriod < DAT_c0733070)) {
        DAT_c0733070 = uPeriod;
      }
      MVar2 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733360);
  }
  else {
    MVar2 = 0;
  }
  return MVar2;
}



/* c07315a4 timeEndPeriod */

/* Boundary evidence: original MIPS .pdata c07315a4..c073169f. Semantic name remains unreviewed. */

MMRESULT timeEndPeriod(UINT uPeriod)

{
  short sVar1;
  short *psVar2;
  MMRESULT MVar3;
  
                    /* 0x15a4  2  timeEndPeriod */
  if (uPeriod == 0) {
    MVar3 = 0x61;
  }
  else if (uPeriod < DAT_c073306c) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733360);
    psVar2 = (short *)(&DAT_c073339e + uPeriod * 2);
    sVar1 = *psVar2;
    if (sVar1 == 0) {
      MVar3 = 0x61;
    }
    else {
      *psVar2 = sVar1 + -1;
      if ((sVar1 == 1) && (uPeriod == DAT_c0733070)) {
        for (; (DAT_c0733070 = uPeriod, uPeriod < DAT_c073306c && (*psVar2 == 0));
            psVar2 = psVar2 + 1) {
          uPeriod = uPeriod + 1;
        }
      }
      MVar3 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733360);
  }
  else {
    MVar3 = 0;
  }
  return MVar3;
}



/* c07316a0 timeGetDevCaps */

MMRESULT timeGetDevCaps(LPTIMECAPS ptc,UINT cbtc)

{
  MMRESULT MVar1;
  
                    /* 0x16a0  3  timeGetDevCaps */
  if ((ptc == (LPTIMECAPS)0x0) || (cbtc < 8)) {
    MVar1 = 0x81;
  }
  else {
    MVar1 = 0;
    ptc->wPeriodMin = 1;
    ptc->wPeriodMax = 1000000;
  }
  return MVar1;
}



/* c07316e4 timeGetTime */

/* Boundary evidence: original MIPS .pdata c07316e4..c0731707. Semantic name remains unreviewed. */

DWORD timeGetTime(void)

{
  DWORD DVar1;
  
                    /* 0x16e4  5  timeGetTime */
  DVar1 = GetTickCount();
  return DVar1;
}



/* c0731708 timeGetTimeSinceInterrupt */

undefined4 timeGetTimeSinceInterrupt(void)

{
                    /* 0x1708  6  timeGetTimeSinceInterrupt */
  return 0xffffffff;
}



/* c0731710 timeGetHardwareFrequency */

/* Boundary evidence: original MIPS .pdata c0731710..c073173f. Semantic name remains unreviewed. */

DWORD timeGetHardwareFrequency(void)

{
  BOOL BVar1;
  LARGE_INTEGER local_10;
  
                    /* 0x1710  4  timeGetHardwareFrequency */
  BVar1 = QueryPerformanceFrequency(&local_10);
  if (BVar1 == 0) {
    local_10.s.LowPart = 0;
  }
  return local_10.s.LowPart;
}



/* c0731740 FUN_c0731740 */

/* Boundary evidence: original MIPS .pdata c0731740..c073183f. Semantic name remains unreviewed. */

void FUN_c0731740(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
  piVar1 = DAT_c07330b0;
  if (DAT_c07330b0 == (int *)0x0) goto LAB_c0731804;
  uVar3 = DAT_c07330b0[4] & 0xf0;
  if (uVar3 == 0) {
    (*(code *)DAT_c07330b0[2])(DAT_c07330b0[5],0,DAT_c07330b0[3],0,0);
  }
  else {
    if (uVar3 == 0x10) {
      uVar2 = 3;
    }
    else {
      if (uVar3 != 0x20) goto LAB_c07317d0;
      uVar2 = 1;
    }
    EventModify(DAT_c07330b0[2],uVar2);
  }
LAB_c07317d0:
  FUN_c073121c((int)piVar1);
  if (piVar1[7] != 0) {
    if ((piVar1[4] & 1U) != 0) {
      piVar1[6] = piVar1[6] + *piVar1;
      FUN_c0731144((int)piVar1);
      goto LAB_c0731804;
    }
    piVar1[7] = 0;
    timeEndPeriod(piVar1[1]);
  }
  piVar1[5] = 0;
LAB_c0731804:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
  return;
}



/* c0731840 FUN_c0731840 */

/* Boundary evidence: original MIPS .pdata c0731840..c0731903. Semantic name remains unreviewed. */

undefined4 FUN_c0731840(void)

{
  bool bVar1;
  DWORD DVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  while (DAT_c0733078 != 0) {
    DVar2 = WaitForSingleObject(DAT_c07330a0,DAT_c0733074);
    if (DVar2 == 0) {
      while (bVar1 = FUN_c07312a8(), CONCAT31(extraout_var,bVar1) != 0) {
        FUN_c0731740();
      }
    }
    else if (DVar2 == 0x102) {
      while (bVar1 = FUN_c07312a8(), CONCAT31(extraout_var_00,bVar1) != 0) {
        FUN_c0731740();
      }
    }
  }
  return 1;
}



/* c0731904 FUN_c0731904 */

/* Boundary evidence: original MIPS .pdata c0731904..c0731b5b. Semantic name remains unreviewed. */

undefined4 FUN_c0731904(void)

{
  bool bVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint local_30;
  HKEY local_2c;
  DWORD local_28;
  DWORD local_24;
  
  uVar6 = 0;
  DAT_c07330a0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (DAT_c07330a0 != (HANDLE)0x0) {
    iVar2 = CeGetCurrentTrust();
    if (iVar2 == 2) {
      DAT_c07330b8 = CeSetThreadPriority_exref;
      DAT_c07330a4 = 0xf8;
      DAT_c0733340 = CeGetThreadPriority_exref;
    }
    else {
      DAT_c07330b8 = SetThreadPriority_exref;
      DAT_c07330a4 = 0;
      DAT_c0733340 = GetThreadPriority_exref;
    }
    LVar3 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\MMTIMER",0,0,&local_2c);
    if (LVar3 == 0) {
      local_28 = 4;
      LVar3 = RegQueryValueExW(local_2c,L"Priority256",(LPDWORD)0x0,&local_24,(LPBYTE)&local_30,
                               &local_28);
      if ((((LVar3 == 0) && (local_24 == 4)) &&
          (DAT_c07330a4 = local_30, DAT_c07330b8 == SetThreadPriority_exref)) &&
         (bVar1 = local_30 < 0xf9, DAT_c07330a4 = local_30 - 0xf8, local_30 = DAT_c07330a4, bVar1))
      {
        DAT_c07330a4 = 0;
        local_30 = DAT_c07330a4;
      }
      RegCloseKey(local_2c);
    }
    DAT_c07330ac = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0731840,(LPVOID)0x0,0,(LPDWORD)0x0
                               );
    if (DAT_c07330ac == (HANDLE)0x0) {
      CloseHandle(DAT_c07330a0);
    }
    else {
      (*DAT_c07330b8)(DAT_c07330ac,DAT_c07330a4);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0733360);
      puVar4 = &DAT_c07333a0;
      do {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      } while (puVar4 != (undefined2 *)0xc073340e);
      puVar5 = &DAT_c07330d4;
      do {
        *puVar5 = 0;
        puVar5[2] = 0;
        puVar5 = puVar5 + 10;
      } while ((int)puVar5 < -0x3f8cccac);
      uVar6 = 1;
    }
  }
  return uVar6;
}



/* c0731b5c timeSetEvent */

/* Boundary evidence: original MIPS .pdata c0731b5c..c0731d6b. Semantic name remains unreviewed. */

MMRESULT timeSetEvent(UINT uDelay,UINT uResolution,LPTIMECALLBACK fptc,DWORD_PTR dwUser,UINT fuEvent
                     )

{
  int iVar1;
  undefined4 uVar2;
  MMRESULT MVar3;
  int iVar4;
  DWORD DVar5;
  int iVar6;
  uint uPeriod;
  
                    /* 0x1b5c  8  timeSetEvent */
  if ((((fuEvent & 0xffffff0e) == 0) && (uDelay < 0xf4241)) && (uDelay != 0)) {
    uVar2 = (*DAT_c0733340)(0x41);
    (*DAT_c07330b8)(0x41,DAT_c07330a4);
    uPeriod = DAT_c073306c;
    if ((uResolution <= DAT_c073306c) && (uPeriod = uResolution, uResolution == 0)) {
      uPeriod = 1;
    }
    if (uDelay < uPeriod) {
      uPeriod = DAT_c073306c;
    }
    MVar3 = timeBeginPeriod(uPeriod);
    if (MVar3 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
      iVar4 = FUN_c0731098();
      if (iVar4 == 0x10) {
        MVar3 = 0;
      }
      else {
        iVar1 = iVar4 * 0x28;
        *(UINT *)(&DAT_c07330c0 + iVar1) = uDelay;
        *(uint *)(&DAT_c07330c4 + iVar1) = uPeriod;
        *(LPTIMECALLBACK *)(&DAT_c07330c8 + iVar1) = fptc;
        *(DWORD_PTR *)(&DAT_c07330cc + iVar1) = dwUser;
        *(UINT *)(&DAT_c07330d0 + iVar1) = fuEvent;
        (&DAT_c07330dc)[iVar4 * 10] = 1;
        do {
          iVar6 = DAT_c07330a8 + 0x10;
          DAT_c07330a8 = 0;
        } while (iVar6 == 0);
        MVar3 = iVar6 + iVar4;
        DAT_c07330a8 = iVar6;
        (&DAT_c07330d4)[iVar4 * 10] = MVar3;
        DVar5 = GetTickCount();
        *(DWORD *)(iVar1 + -0x3f8ccf28) = DVar5 + uDelay;
        iVar4 = FUN_c0731144((int)(&DAT_c07330c0 + iVar1));
        if (iVar4 != 0) {
          EventModify(DAT_c07330a0,3);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
      if (MVar3 == 0) {
        timeEndPeriod(uPeriod);
      }
    }
    else {
      MVar3 = 0;
    }
    (*DAT_c07330b8)(0x41,uVar2);
  }
  else {
    MVar3 = 0;
  }
  return MVar3;
}



/* c0731d6c timeKillEvent */

/* Boundary evidence: original MIPS .pdata c0731d6c..c0731eaf. Semantic name remains unreviewed. */

MMRESULT timeKillEvent(UINT uTimerID)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  MMRESULT MVar5;
  UINT local_28;
  
                    /* 0x1d6c  7  timeKillEvent */
  MVar5 = 0xb;
  bVar2 = false;
  if (uTimerID != 0) {
    uVar3 = (*DAT_c0733340)(0x41);
    (*DAT_c07330b8)(0x41,DAT_c07330a4);
    uVar4 = uTimerID & 0xf;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
    if (((&DAT_c07330d4)[uVar4 * 10] == uTimerID) && ((&DAT_c07330dc)[uVar4 * 10] != 0)) {
      local_28 = *(UINT *)(&DAT_c07330c4 + uVar4 * 0x28);
      MVar5 = 0;
      bVar1 = &DAT_c07330c0 + uVar4 * 0x28 == DAT_c07330b0;
      (&DAT_c07330dc)[uVar4 * 10] = 0;
      if (bVar1) {
        bVar2 = true;
      }
      else {
        FUN_c073121c((int)(&DAT_c07330c0 + uVar4 * 0x28));
        (&DAT_c07330d4)[uVar4 * 10] = 0;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0733380);
    if ((MVar5 == 0) && (timeEndPeriod(local_28), bVar2)) {
      EventModify(DAT_c07330a0,3);
    }
    (*DAT_c07330b8)(0x41,uVar3);
  }
  return MVar5;
}



/* c0731eb0 FUN_c0731eb0 */

/* Boundary evidence: original MIPS .pdata c0731eb0..c0731f07. Semantic name remains unreviewed. */

undefined4 FUN_c0731eb0(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_2 == 0) {
    FUN_c0731380();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    uVar1 = FUN_c0731904();
  }
  return uVar1;
}



/* c0731f88 FUN_c0731f88 */

/* Boundary evidence: original MIPS .pdata c0731f88..c07320c3. Semantic name remains unreviewed. */

int FUN_c0731f88(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c073341c != (code *)0x0) {
      iVar2 = (*DAT_c073341c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0732038;
    FUN_c07322e0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0731eb0(param_1,param_2);
  }
LAB_c0732038:
  if (((param_2 == 0) && (FUN_c0732268(), iVar1 != 0)) && (DAT_c073341c != (code *)0x0)) {
    iVar1 = (*DAT_c073341c)(param_1,0,param_3);
  }
  return iVar1;
}



/* c07320c4 FUN_c07320c4 */

/* Boundary evidence: original MIPS .pdata c07320c4..c07320ef. Semantic name remains unreviewed. */

void FUN_c07320c4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c07320f0 entry */

/* Boundary evidence: original MIPS .pdata c07320f0..c0732147. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c073231c();
  }
  FUN_c0731f88(param_1,param_2,param_3);
  return;
}



/* c0732148 FUN_c0732148 */

/* Boundary evidence: original MIPS .pdata c0732148..c0732267. Semantic name remains unreviewed. */

void FUN_c0732148(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c07330b4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c0733414;
    if (DAT_c0733414 != (undefined4 *)0x0) {
      while (DAT_c0733410 = DAT_c0733410 + -1, _Memory <= DAT_c0733410) {
        if ((code *)*DAT_c0733410 != (code *)0x0) {
          (*(code *)*DAT_c0733410)();
          _Memory = DAT_c0733414;
        }
      }
      free(_Memory);
      DAT_c0733410 = (undefined4 *)0x0;
      DAT_c0733414 = (undefined4 *)0x0;
    }
    FUN_c073228c((undefined4 *)&DAT_c0731010,(undefined4 *)&DAT_c0731014);
  }
  FUN_c073228c((undefined4 *)&DAT_c0731018,(undefined4 *)&DAT_c073101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0733418,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0732268 FUN_c0732268 */

/* Boundary evidence: original MIPS .pdata c0732268..c073228b. Semantic name remains unreviewed. */

void FUN_c0732268(void)

{
  FUN_c0732148(0,0,1);
  return;
}



/* c073228c FUN_c073228c */

/* Boundary evidence: original MIPS .pdata c073228c..c07322df. Semantic name remains unreviewed. */

void FUN_c073228c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c07322e0 FUN_c07322e0 */

/* Boundary evidence: original MIPS .pdata c07322e0..c073231b. Semantic name remains unreviewed. */

void FUN_c07322e0(void)

{
  FUN_c073228c((undefined4 *)&DAT_c0731008,(undefined4 *)&DAT_c073100c);
  FUN_c073228c((undefined4 *)&DAT_c0731000,(undefined4 *)&DAT_c0731004);
  return;
}



/* c073231c FUN_c073231c */

/* Boundary evidence: original MIPS .pdata c073231c..c073238f. Semantic name remains unreviewed. */

void FUN_c073231c(void)

{
  uint uVar1;
  
  if ((DAT_c073307c == 0) || (DAT_c073307c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c073307c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c073307c == 0) {
      DAT_c073307c = 0xb064;
    }
  }
  DAT_c0733080 = ~DAT_c073307c;
  return;
}


