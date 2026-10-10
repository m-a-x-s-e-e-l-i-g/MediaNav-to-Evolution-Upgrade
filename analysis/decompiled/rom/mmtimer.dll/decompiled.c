/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40341098 FUN_40341098 */

/* Boundary evidence: original MIPS .pdata 40341098..40341143. Semantic name remains unreviewed. */

int FUN_40341098(void)

{
  uint uVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
  iVar2 = 0;
  uVar1 = 0;
  while ((*(int *)((int)&DAT_403430d4 + uVar1) != 0 || (*(int *)((int)&DAT_403430dc + uVar1) != 0)))
  {
    uVar1 = uVar1 + 0x28;
    iVar2 = iVar2 + 1;
    if (0x27f < uVar1) {
LAB_40341124:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
      return iVar2;
    }
  }
  (&DAT_403430dc)[iVar2 * 10] = 1;
  goto LAB_40341124;
}



/* 40341144 FUN_40341144 */

/* Boundary evidence: original MIPS .pdata 40341144..4034121b. Semantic name remains unreviewed. */

undefined4 FUN_40341144(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
  if (DAT_403430b0 == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
LAB_40341188:
    uVar3 = 1;
    DAT_403430b0 = param_1;
  }
  else {
    iVar1 = DAT_403430b0;
    do {
      if (0 < *(int *)(iVar1 + 0x18) - *(int *)(param_1 + 0x18)) {
        *(int *)(param_1 + 0x20) = iVar1;
        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
        *(int *)(iVar1 + 0x24) = param_1;
        if (*(int *)(param_1 + 0x24) == 0) goto LAB_40341188;
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
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
  return uVar3;
}



/* 4034121c FUN_4034121c */

/* Boundary evidence: original MIPS .pdata 4034121c..403412a7. Semantic name remains unreviewed. */

bool FUN_4034121c(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
  if (*(int *)(param_1 + 0x20) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24) = *(undefined4 *)(param_1 + 0x24);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    DAT_403430b0 = *(undefined4 *)(param_1 + 0x20);
  }
  else {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_1 + 0x20);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
  return iVar1 == 0;
}



/* 403412a8 FUN_403412a8 */

/* Boundary evidence: original MIPS .pdata 403412a8..4034137f. Semantic name remains unreviewed. */

bool FUN_403412a8(void)

{
  int iVar1;
  DWORD DVar2;
  bool bVar3;
  
  bVar3 = false;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
  do {
    iVar1 = DAT_403430b0;
    if (DAT_403430b0 == 0) {
LAB_40341300:
      DAT_40343074 = -1;
LAB_40341310:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
      return bVar3;
    }
    if (*(int *)(DAT_403430b0 + 0x1c) != 0) {
      DVar2 = GetTickCount();
      DAT_40343074 = *(int *)(iVar1 + 0x18) - DVar2;
      bVar3 = DAT_40343074 < DAT_40343070;
      if (DAT_403430b0 != 0) goto LAB_40341310;
      goto LAB_40341300;
    }
    FUN_4034121c(DAT_403430b0);
    *(undefined4 *)(iVar1 + 0x14) = 0;
  } while( true );
}



/* 40341380 FUN_40341380 */

/* Boundary evidence: original MIPS .pdata 40341380..403414d3. Semantic name remains unreviewed. */

void FUN_40341380(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_403430ac != (HANDLE)0x0) {
    uVar1 = CeGetThreadPriority(0x41);
    uVar2 = CeGetThreadPriority(DAT_403430ac);
    DAT_40343078 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
    DAT_403430b0 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
    if (uVar1 <= uVar2) {
      if (uVar1 < 0xf9) {
        SetThreadPriority((HANDLE)0x41,3);
        SetThreadPriority(DAT_403430ac,2);
      }
      else {
        CeSetThreadPriority(DAT_403430ac,uVar1 - 1);
      }
    }
    EventModify(DAT_403430a0,3);
    CeSetThreadPriority(0x41,uVar1);
    WaitForSingleObject(DAT_403430ac,10000);
    CloseHandle(DAT_403430a0);
    CloseHandle(DAT_403430ac);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_40343360);
  }
  return;
}



/* 403414d4 timeBeginPeriod */

/* Boundary evidence: original MIPS .pdata 403414d4..403415a3. Semantic name remains unreviewed. */

MMRESULT timeBeginPeriod(UINT uPeriod)

{
  short sVar1;
  MMRESULT MVar2;
  
                    /* 0x14d4  1  timeBeginPeriod */
  if (uPeriod == 0) {
    MVar2 = 0x61;
  }
  else if (uPeriod < DAT_4034306c) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343360);
    sVar1 = *(short *)(&DAT_4034339e + uPeriod * 2);
    if (sVar1 == -1) {
      MVar2 = 0x61;
    }
    else {
      *(short *)(&DAT_4034339e + uPeriod * 2) = sVar1 + 1;
      if ((sVar1 == 0) && (uPeriod < DAT_40343070)) {
        DAT_40343070 = uPeriod;
      }
      MVar2 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343360);
  }
  else {
    MVar2 = 0;
  }
  return MVar2;
}



/* 403415a4 timeEndPeriod */

/* Boundary evidence: original MIPS .pdata 403415a4..4034169f. Semantic name remains unreviewed. */

MMRESULT timeEndPeriod(UINT uPeriod)

{
  short sVar1;
  short *psVar2;
  MMRESULT MVar3;
  
                    /* 0x15a4  2  timeEndPeriod */
  if (uPeriod == 0) {
    MVar3 = 0x61;
  }
  else if (uPeriod < DAT_4034306c) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343360);
    psVar2 = (short *)(&DAT_4034339e + uPeriod * 2);
    sVar1 = *psVar2;
    if (sVar1 == 0) {
      MVar3 = 0x61;
    }
    else {
      *psVar2 = sVar1 + -1;
      if ((sVar1 == 1) && (uPeriod == DAT_40343070)) {
        for (; (DAT_40343070 = uPeriod, uPeriod < DAT_4034306c && (*psVar2 == 0));
            psVar2 = psVar2 + 1) {
          uPeriod = uPeriod + 1;
        }
      }
      MVar3 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343360);
  }
  else {
    MVar3 = 0;
  }
  return MVar3;
}



/* 403416a0 timeGetDevCaps */

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



/* 403416e4 timeGetTime */

/* Boundary evidence: original MIPS .pdata 403416e4..40341707. Semantic name remains unreviewed. */

DWORD timeGetTime(void)

{
  DWORD DVar1;
  
                    /* 0x16e4  5  timeGetTime */
  DVar1 = GetTickCount();
  return DVar1;
}



/* 40341708 timeGetTimeSinceInterrupt */

undefined4 timeGetTimeSinceInterrupt(void)

{
                    /* 0x1708  6  timeGetTimeSinceInterrupt */
  return 0xffffffff;
}



/* 40341710 timeGetHardwareFrequency */

/* Boundary evidence: original MIPS .pdata 40341710..4034173f. Semantic name remains unreviewed. */

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



/* 40341740 FUN_40341740 */

/* Boundary evidence: original MIPS .pdata 40341740..4034183f. Semantic name remains unreviewed. */

void FUN_40341740(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
  piVar1 = DAT_403430b0;
  if (DAT_403430b0 == (int *)0x0) goto LAB_40341804;
  uVar3 = DAT_403430b0[4] & 0xf0;
  if (uVar3 == 0) {
    (*(code *)DAT_403430b0[2])(DAT_403430b0[5],0,DAT_403430b0[3],0,0);
  }
  else {
    if (uVar3 == 0x10) {
      uVar2 = 3;
    }
    else {
      if (uVar3 != 0x20) goto LAB_403417d0;
      uVar2 = 1;
    }
    EventModify(DAT_403430b0[2],uVar2);
  }
LAB_403417d0:
  FUN_4034121c((int)piVar1);
  if (piVar1[7] != 0) {
    if ((piVar1[4] & 1U) != 0) {
      piVar1[6] = piVar1[6] + *piVar1;
      FUN_40341144((int)piVar1);
      goto LAB_40341804;
    }
    piVar1[7] = 0;
    timeEndPeriod(piVar1[1]);
  }
  piVar1[5] = 0;
LAB_40341804:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
  return;
}



/* 40341840 FUN_40341840 */

/* Boundary evidence: original MIPS .pdata 40341840..40341903. Semantic name remains unreviewed. */

undefined4 FUN_40341840(void)

{
  bool bVar1;
  DWORD DVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  while (DAT_40343078 != 0) {
    DVar2 = WaitForSingleObject(DAT_403430a0,DAT_40343074);
    if (DVar2 == 0) {
      while (bVar1 = FUN_403412a8(), CONCAT31(extraout_var,bVar1) != 0) {
        FUN_40341740();
      }
    }
    else if (DVar2 == 0x102) {
      while (bVar1 = FUN_403412a8(), CONCAT31(extraout_var_00,bVar1) != 0) {
        FUN_40341740();
      }
    }
  }
  return 1;
}



/* 40341904 FUN_40341904 */

/* Boundary evidence: original MIPS .pdata 40341904..40341b5b. Semantic name remains unreviewed. */

undefined4 FUN_40341904(void)

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
  DAT_403430a0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (DAT_403430a0 != (HANDLE)0x0) {
    iVar2 = CeGetCurrentTrust();
    if (iVar2 == 2) {
      DAT_403430b8 = CeSetThreadPriority_exref;
      DAT_403430a4 = 0xf8;
      DAT_40343340 = CeGetThreadPriority_exref;
    }
    else {
      DAT_403430b8 = SetThreadPriority_exref;
      DAT_403430a4 = 0;
      DAT_40343340 = GetThreadPriority_exref;
    }
    LVar3 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\MMTIMER",0,0,&local_2c);
    if (LVar3 == 0) {
      local_28 = 4;
      LVar3 = RegQueryValueExW(local_2c,L"Priority256",(LPDWORD)0x0,&local_24,(LPBYTE)&local_30,
                               &local_28);
      if ((((LVar3 == 0) && (local_24 == 4)) &&
          (DAT_403430a4 = local_30, DAT_403430b8 == SetThreadPriority_exref)) &&
         (bVar1 = local_30 < 0xf9, DAT_403430a4 = local_30 - 0xf8, local_30 = DAT_403430a4, bVar1))
      {
        DAT_403430a4 = 0;
        local_30 = DAT_403430a4;
      }
      RegCloseKey(local_2c);
    }
    DAT_403430ac = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40341840,(LPVOID)0x0,0,(LPDWORD)0x0
                               );
    if (DAT_403430ac == (HANDLE)0x0) {
      CloseHandle(DAT_403430a0);
    }
    else {
      (*DAT_403430b8)(DAT_403430ac,DAT_403430a4);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_40343360);
      puVar4 = &DAT_403433a0;
      do {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      } while (puVar4 != (undefined2 *)0x4034340e);
      puVar5 = &DAT_403430d4;
      do {
        *puVar5 = 0;
        puVar5[2] = 0;
        puVar5 = puVar5 + 10;
      } while ((int)puVar5 < 0x40343354);
      uVar6 = 1;
    }
  }
  return uVar6;
}



/* 40341b5c timeSetEvent */

/* Boundary evidence: original MIPS .pdata 40341b5c..40341d6b. Semantic name remains unreviewed. */

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
    uVar2 = (*DAT_40343340)(0x41);
    (*DAT_403430b8)(0x41,DAT_403430a4);
    uPeriod = DAT_4034306c;
    if ((uResolution <= DAT_4034306c) && (uPeriod = uResolution, uResolution == 0)) {
      uPeriod = 1;
    }
    if (uDelay < uPeriod) {
      uPeriod = DAT_4034306c;
    }
    MVar3 = timeBeginPeriod(uPeriod);
    if (MVar3 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
      iVar4 = FUN_40341098();
      if (iVar4 == 0x10) {
        MVar3 = 0;
      }
      else {
        iVar1 = iVar4 * 0x28;
        *(UINT *)(&DAT_403430c0 + iVar1) = uDelay;
        *(uint *)(&DAT_403430c4 + iVar1) = uPeriod;
        *(LPTIMECALLBACK *)(&DAT_403430c8 + iVar1) = fptc;
        *(DWORD_PTR *)(&DAT_403430cc + iVar1) = dwUser;
        *(UINT *)(&DAT_403430d0 + iVar1) = fuEvent;
        (&DAT_403430dc)[iVar4 * 10] = 1;
        do {
          iVar6 = DAT_403430a8 + 0x10;
          DAT_403430a8 = 0;
        } while (iVar6 == 0);
        MVar3 = iVar6 + iVar4;
        DAT_403430a8 = iVar6;
        (&DAT_403430d4)[iVar4 * 10] = MVar3;
        DVar5 = GetTickCount();
        *(DWORD *)(iVar1 + 0x403430d8) = DVar5 + uDelay;
        iVar4 = FUN_40341144((int)(&DAT_403430c0 + iVar1));
        if (iVar4 != 0) {
          EventModify(DAT_403430a0,3);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
      if (MVar3 == 0) {
        timeEndPeriod(uPeriod);
      }
    }
    else {
      MVar3 = 0;
    }
    (*DAT_403430b8)(0x41,uVar2);
  }
  else {
    MVar3 = 0;
  }
  return MVar3;
}



/* 40341d6c timeKillEvent */

/* Boundary evidence: original MIPS .pdata 40341d6c..40341eaf. Semantic name remains unreviewed. */

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
    uVar3 = (*DAT_40343340)(0x41);
    (*DAT_403430b8)(0x41,DAT_403430a4);
    uVar4 = uTimerID & 0xf;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
    if (((&DAT_403430d4)[uVar4 * 10] == uTimerID) && ((&DAT_403430dc)[uVar4 * 10] != 0)) {
      local_28 = *(UINT *)(&DAT_403430c4 + uVar4 * 0x28);
      MVar5 = 0;
      bVar1 = &DAT_403430c0 + uVar4 * 0x28 == DAT_403430b0;
      (&DAT_403430dc)[uVar4 * 10] = 0;
      if (bVar1) {
        bVar2 = true;
      }
      else {
        FUN_4034121c((int)(&DAT_403430c0 + uVar4 * 0x28));
        (&DAT_403430d4)[uVar4 * 10] = 0;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40343380);
    if ((MVar5 == 0) && (timeEndPeriod(local_28), bVar2)) {
      EventModify(DAT_403430a0,3);
    }
    (*DAT_403430b8)(0x41,uVar3);
  }
  return MVar5;
}



/* 40341eb0 FUN_40341eb0 */

/* Boundary evidence: original MIPS .pdata 40341eb0..40341f07. Semantic name remains unreviewed. */

undefined4 FUN_40341eb0(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_2 == 0) {
    FUN_40341380();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    uVar1 = FUN_40341904();
  }
  return uVar1;
}



/* 40341f88 FUN_40341f88 */

/* Boundary evidence: original MIPS .pdata 40341f88..403420c3. Semantic name remains unreviewed. */

int FUN_40341f88(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_4034341c != (code *)0x0) {
      iVar2 = (*DAT_4034341c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40342038;
    FUN_403422e0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40341eb0(param_1,param_2);
  }
LAB_40342038:
  if (((param_2 == 0) && (FUN_40342268(), iVar1 != 0)) && (DAT_4034341c != (code *)0x0)) {
    iVar1 = (*DAT_4034341c)(param_1,0,param_3);
  }
  return iVar1;
}



/* 403420c4 FUN_403420c4 */

/* Boundary evidence: original MIPS .pdata 403420c4..403420ef. Semantic name remains unreviewed. */

void FUN_403420c4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 403420f0 entry */

/* Boundary evidence: original MIPS .pdata 403420f0..40342147. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_4034231c();
  }
  FUN_40341f88(param_1,param_2,param_3);
  return;
}



/* 40342148 FUN_40342148 */

/* Boundary evidence: original MIPS .pdata 40342148..40342267. Semantic name remains unreviewed. */

void FUN_40342148(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_403430b4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40343414;
    if (DAT_40343414 != (undefined4 *)0x0) {
      while (DAT_40343410 = DAT_40343410 + -1, _Memory <= DAT_40343410) {
        if ((code *)*DAT_40343410 != (code *)0x0) {
          (*(code *)*DAT_40343410)();
          _Memory = DAT_40343414;
        }
      }
      free(_Memory);
      DAT_40343410 = (undefined4 *)0x0;
      DAT_40343414 = (undefined4 *)0x0;
    }
    FUN_4034228c((undefined4 *)&DAT_40341010,(undefined4 *)&DAT_40341014);
  }
  FUN_4034228c((undefined4 *)&DAT_40341018,(undefined4 *)&DAT_4034101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_40343418,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40342268 FUN_40342268 */

/* Boundary evidence: original MIPS .pdata 40342268..4034228b. Semantic name remains unreviewed. */

void FUN_40342268(void)

{
  FUN_40342148(0,0,1);
  return;
}



/* 4034228c FUN_4034228c */

/* Boundary evidence: original MIPS .pdata 4034228c..403422df. Semantic name remains unreviewed. */

void FUN_4034228c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 403422e0 FUN_403422e0 */

/* Boundary evidence: original MIPS .pdata 403422e0..4034231b. Semantic name remains unreviewed. */

void FUN_403422e0(void)

{
  FUN_4034228c((undefined4 *)&DAT_40341008,(undefined4 *)&DAT_4034100c);
  FUN_4034228c((undefined4 *)&DAT_40341000,(undefined4 *)&DAT_40341004);
  return;
}



/* 4034231c FUN_4034231c */

/* Boundary evidence: original MIPS .pdata 4034231c..4034238f. Semantic name remains unreviewed. */

void FUN_4034231c(void)

{
  uint uVar1;
  
  if ((DAT_4034307c == 0) || (DAT_4034307c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4034307c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4034307c == 0) {
      DAT_4034307c = 0xb064;
    }
  }
  DAT_40343080 = ~DAT_4034307c;
  return;
}


