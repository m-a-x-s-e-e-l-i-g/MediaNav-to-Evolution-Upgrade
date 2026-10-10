/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c06f1670 FUN_c06f1670 */

/* Boundary evidence: original MIPS .pdata c06f1670..c06f16a3. Semantic name remains unreviewed. */

undefined4 FUN_c06f1670(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c06f16a4 FUN_c06f16a4 */

/* Boundary evidence: original MIPS .pdata c06f16a4..c06f17f3. Semantic name remains unreviewed. */

void FUN_c06f16a4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_20 [2];
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x28) + 8);
  uVar2 = *(undefined4 *)(param_1 + 0x2c);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd0));
  if (*(int *)(param_1 + 0x90) == 0) {
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
  }
  if ((*(int *)(param_1 + 0xcc) == 0) || (*(int *)(param_1 + 200) == *(int *)(param_1 + 0xc4))) {
    local_20[0] = 0;
    (**(code **)(iVar1 + 0x1c))(uVar2,0,local_20);
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    EventModify(*(undefined4 *)(param_1 + 0x3c),3);
  }
  else {
    if ((*(uint *)(param_1 + 0x68) & 0x3000) == 0x3000) {
      (**(code **)(iVar1 + 0x40))(uVar2);
    }
    if ((*(uint *)(param_1 + 0x94) & 4) == 0) {
      local_20[0] = *(int *)(param_1 + 200) - *(int *)(param_1 + 0xc4);
    }
    else {
      local_20[0] = 0;
    }
    (**(code **)(iVar1 + 0x1c))(uVar2,*(int *)(param_1 + 0xcc) + *(int *)(param_1 + 0xc4),local_20);
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + local_20[0];
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + local_20[0];
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + local_20[0];
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd0));
  return;
}



/* c06f17f4 FUN_c06f17f4 */

/* Boundary evidence: original MIPS .pdata c06f17f4..c06f18b7. Semantic name remains unreviewed. */

undefined4 FUN_c06f17f4(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    uVar1 = CeGetThreadPriority(0x41);
    CeSetThreadPriority(*(undefined4 *)(param_1 + 0x40),uVar1);
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 1;
    EventModify(*(undefined4 *)(param_1 + 0x30),3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x38),3000);
    Sleep(10);
    CloseHandle(*(HANDLE *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    InterruptDone(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
    InterruptDisable(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
  }
  return 1;
}



/* c06f18b8 FUN_c06f18b8 */

/* Boundary evidence: original MIPS .pdata c06f18b8..c06f1bf3. Semantic name remains unreviewed. */

undefined4 FUN_c06f18b8(int param_1,void *param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x28);
  if ((((*(uint *)(param_1 + 0xa4) <= (uint)*(ushort *)((int)param_2 + 0x10)) ||
       (*(uint *)(param_1 + 0xa4) - (uint)*(ushort *)((int)param_2 + 0x10) <=
        (uint)*(ushort *)((int)param_2 + 0xe))) ||
      ((((*(uint *)((int)param_2 + 8) & 0x100) != 0 || ((*(uint *)((int)param_2 + 8) & 0x200) != 0))
       && (*(char *)((int)param_2 + 0x15) == *(char *)((int)param_2 + 0x16))))) ||
     (iVar1 = (**(code **)(*(int *)(iVar5 + 8) + 0x6c))(*(undefined4 *)(param_1 + 0x2c),param_2),
     iVar1 == 0)) {
    return 0;
  }
  if (param_3 == 0) {
    return 1;
  }
  memcpy((void *)(param_1 + 0x60),param_2,0x1c);
  uVar3 = *(uint *)(param_1 + 0x68) >> 4 & 3;
  if (uVar3 == 0) {
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x34);
LAB_c06f19a0:
    (*pcVar2)(*(undefined4 *)(param_1 + 0x2c));
  }
  else if (uVar3 == 1) {
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x38);
    goto LAB_c06f19a0;
  }
  uVar3 = *(uint *)(param_1 + 0x68) >> 0xc & 3;
  if (uVar3 == 0) {
    (**(code **)(*(int *)(iVar5 + 8) + 0x3c))(*(undefined4 *)(param_1 + 0x2c));
  }
  else if (uVar3 == 1) {
    (**(code **)(*(int *)(iVar5 + 8) + 0x40))(*(undefined4 *)(param_1 + 0x2c));
  }
  if ((*(uint *)(param_1 + 0x68) & 0x30) == 0x20) {
    uVar3 = *(uint *)(param_1 + 0x94);
    if ((uVar3 & 0x10) == 0) {
      uVar4 = *(uint *)(param_1 + 0x9c);
      if (*(uint *)(param_1 + 0xa0) < uVar4) {
        iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
      }
      else {
        iVar1 = -uVar4;
      }
      if ((uint)*(ushort *)(param_1 + 0x70) <
          *(int *)(param_1 + 0xa4) - (*(uint *)(param_1 + 0xa0) + iVar1)) goto LAB_c06f1a64;
      *(uint *)(param_1 + 0x94) = uVar3 | 0x10;
      pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x34);
    }
    else {
LAB_c06f1a64:
      uVar4 = *(uint *)(param_1 + 0x9c);
      if (*(uint *)(param_1 + 0xa0) < uVar4) {
        iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
      }
      else {
        iVar1 = -uVar4;
      }
      if ((uint)*(ushort *)(param_1 + 0x6e) < *(uint *)(param_1 + 0xa0) + iVar1) goto LAB_c06f1abc;
      *(uint *)(param_1 + 0x94) = uVar3 & 0xffffffef;
      pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x38);
    }
    (*pcVar2)(*(undefined4 *)(param_1 + 0x2c));
  }
LAB_c06f1abc:
  if ((*(uint *)(param_1 + 0x68) & 0x3000) != 0x2000) goto LAB_c06f1b8c;
  uVar3 = *(uint *)(param_1 + 0x94);
  if ((uVar3 & 0x20) == 0) {
    uVar4 = *(uint *)(param_1 + 0x9c);
    if (*(uint *)(param_1 + 0xa0) < uVar4) {
      iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
    }
    else {
      iVar1 = -uVar4;
    }
    if ((uint)*(ushort *)(param_1 + 0x70) <
        *(int *)(param_1 + 0xa4) - (*(uint *)(param_1 + 0xa0) + iVar1)) goto LAB_c06f1b34;
    *(uint *)(param_1 + 0x94) = uVar3 | 0x20;
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x3c);
  }
  else {
LAB_c06f1b34:
    uVar4 = *(uint *)(param_1 + 0x9c);
    if (*(uint *)(param_1 + 0xa0) < uVar4) {
      iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
    }
    else {
      iVar1 = -uVar4;
    }
    if ((uint)*(ushort *)(param_1 + 0x6e) < *(uint *)(param_1 + 0xa0) + iVar1) goto LAB_c06f1b8c;
    *(uint *)(param_1 + 0x94) = uVar3 & 0xffffffdf;
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x40);
  }
  (*pcVar2)(*(undefined4 *)(param_1 + 0x2c));
LAB_c06f1b8c:
  if (((*(uint *)(param_1 + 0x68) & 0x100) == 0) && ((*(uint *)(param_1 + 0x68) & 0x200) == 0)) {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfffffffd;
  }
  else {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 2;
  }
  return 1;
}



/* c06f1bf4 COM_PreClose */

/* Boundary evidence: original MIPS .pdata c06f1bf4..c06f1cff. Semantic name remains unreviewed. */

undefined4 COM_PreClose(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x1bf4  8  COM_PreClose */
  iVar1 = *param_1;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xec));
    uVar2 = 1;
    if ((param_1[1] & 0x100U) == 0) {
      if (*(int *)(iVar1 + 0x90) == 0) {
        SetLastError(6);
      }
      else {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        param_1[5] = 0;
        param_1[7] = 1;
        EventModify(param_1[4],3);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        if ((param_1[1] & 0xc0000000U) != 0) {
          *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) | 0x40;
          EventModify(*(undefined4 *)(iVar1 + 0x34),3);
          *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) | 0x80;
          EventModify(*(undefined4 *)(iVar1 + 0x3c),3);
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xec));
  }
  return uVar2;
}



/* c06f1d00 COM_Close */

/* Boundary evidence: original MIPS .pdata c06f1d00..c06f1ea7. Semantic name remains unreviewed. */

undefined4 COM_Close(int *param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  
                    /* 0x1d00  1  COM_Close */
  iVar2 = *param_1;
  uVar4 = 1;
  if (iVar2 == 0) {
    SetLastError(6);
    return 0;
  }
  puVar3 = *(uint **)(iVar2 + 0x28);
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xec));
  if ((param_1[1] & 0x100U) == 0) {
    if (*(int *)(iVar2 + 0x90) == 0) {
      SetLastError(6);
      uVar4 = 0;
      goto LAB_c06f1e7c;
    }
    iVar1 = *(int *)(iVar2 + 0x90) + -1;
    *(int *)(iVar2 + 0x90) = iVar1;
    if ((((puVar3 != (uint *)0x0) && (iVar1 == 0)) && ((*puVar3 & 3) != 0)) &&
       (*(HANDLE *)(iVar2 + 0x40) != (HANDLE)0x0)) {
      SetThreadPriority(*(HANDLE *)(iVar2 + 0x40),3);
    }
    if (*(int *)(iVar2 + 0x90) == 0) {
      if (puVar3 != (uint *)0x0) {
        (**(code **)(puVar3[2] + 0x10))(*(undefined4 *)(iVar2 + 0x2c));
      }
      if ((**(uint **)(iVar2 + 0x28) & 2) != 0) {
        FUN_c06f17f4(iVar2);
      }
    }
    if (param_1 == *(int **)(iVar2 + 0x100)) {
      *(undefined4 *)(iVar2 + 0x100) = 0;
    }
    *(int *)param_1[0xe] = param_1[0xd];
    *(int *)(param_1[0xd] + 4) = param_1[0xe];
  }
  else {
    *(int *)param_1[0xe] = param_1[0xd];
    *(int *)(param_1[0xd] + 4) = param_1[0xe];
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if ((HANDLE)param_1[4] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[4]);
  }
  LocalFree(param_1);
LAB_c06f1e7c:
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xec));
  return uVar4;
}



/* c06f1ea8 FUN_c06f1ea8 */

/* Boundary evidence: original MIPS .pdata c06f1ea8..c06f1eeb. Semantic name remains unreviewed. */

bool FUN_c06f1ea8(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    COM_PreClose(param_1);
  }
  else {
    SetLastError(6);
  }
  return iVar1 != 0;
}



/* c06f1eec COM_PreDeinit */

/* Boundary evidence: original MIPS .pdata c06f1eec..c06f1fbb. Semantic name remains unreviewed. */

undefined4 COM_PreDeinit(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
                    /* 0x1eec  9  COM_PreDeinit */
  if (param_1 == 0) {
    SetLastError(6);
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x90) != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xec));
      piVar4 = *(int **)(param_1 + 0xe4);
      while (piVar4 != (int *)(param_1 + 0xe4)) {
        piVar2 = piVar4 + -0xd;
        piVar4 = (int *)*piVar4;
        COM_PreClose(piVar2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xec));
    }
    if (((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0x28) != 0)) &&
       (iVar3 = *(int *)(*(int *)(param_1 + 0x28) + 8), iVar3 != 0)) {
      (**(code **)(iVar3 + 0x5c))();
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* c06f1fbc COM_Deinit */

/* Boundary evidence: original MIPS .pdata c06f1fbc..c06f2153. Semantic name remains unreviewed. */

undefined4 COM_Deinit(LPCRITICAL_SECTION param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  ULONG_PTR *lpCriticalSection;
  
                    /* 0x1fbc  2  COM_Deinit */
  if (param_1 == (LPCRITICAL_SECTION)0x0) {
    SetLastError(6);
    uVar1 = 0;
  }
  else {
    if ((param_1[1].LockSemaphore != (uint *)0x0) && ((*(uint *)param_1[1].LockSemaphore & 3) != 0))
    {
      FUN_c06f17f4((int)param_1);
    }
    lpCriticalSection = &param_1[9].SpinCount;
    EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
    if (param_1[6].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
      piVar4 = param_1[9].OwningThread;
      while ((HANDLE *)piVar4 != &param_1[9].OwningThread) {
        piVar2 = piVar4 + -0xd;
        piVar4 = (int *)*piVar4;
        COM_Close(piVar2);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
    if (param_1[2].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
      CloseHandle(param_1[2].DebugInfo);
    }
    if ((HANDLE)param_1[2].RecursionCount != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[2].RecursionCount);
    }
    if (param_1[2].OwningThread != (HANDLE)0x0) {
      CloseHandle(param_1[2].OwningThread);
    }
    if ((HANDLE)param_1[2].LockCount != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[2].LockCount);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&param_1->SpinCount);
    DeleteCriticalSection(param_1);
    DeleteCriticalSection((LPCRITICAL_SECTION)&param_1[7].RecursionCount);
    DeleteCriticalSection((LPCRITICAL_SECTION)&param_1[8].LockSemaphore);
    DeleteCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
    if ((HLOCAL)param_1[7].LockCount != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[7].LockCount);
    }
    if (((param_1[1].SpinCount != 0) && (param_1[1].LockSemaphore != (HANDLE)0x0)) &&
       (iVar3 = *(int *)((int)param_1[1].LockSemaphore + 8), iVar3 != 0)) {
      (**(code **)(iVar3 + 8))();
    }
    LocalFree(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* c06f2154 COM_Read */

/* Boundary evidence: original MIPS .pdata c06f2154..c06f25eb. Semantic name remains unreviewed. */

int COM_Read(int *param_1,int param_2,uint param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
                    /* 0x2154  10  COM_Read */
  iVar11 = 0;
  uVar14 = 0;
  if (((param_1 == (int *)0x0) || (iVar9 = *param_1, iVar9 == 0)) || (*(int *)(iVar9 + 0x90) == 0))
  {
    DVar1 = 6;
  }
  else {
    iVar3 = *(int *)(*(int *)(iVar9 + 0x28) + 8);
    uVar4 = *(undefined4 *)(iVar9 + 0x2c);
    if ((param_1[1] & 0x80000000U) == 0) {
      SetLastError(0xc);
      return -1;
    }
    if ((param_2 != 0) && (param_3 != 0)) {
      InterlockedIncrement(param_1 + 3);
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0x14));
      iVar5 = *(int *)(iVar9 + 0x80);
      *(uint *)(iVar9 + 0x94) = *(uint *)(iVar9 + 0x94) & 0xffffffbf;
      if (iVar5 == -1) {
        uVar13 = *(uint *)(iVar9 + 0x84);
        iVar6 = 0;
      }
      else {
        iVar6 = iVar5 << 3;
        uVar13 = iVar5 * param_3 + *(int *)(iVar9 + 0x84);
      }
      uVar12 = *(uint *)(iVar9 + 0x7c);
      if ((uVar12 < -iVar6 - 1U) && (uVar12 != 0)) {
        uVar12 = uVar12 + iVar6;
      }
      do {
        uVar8 = 0xffffffff;
        uVar7 = *(uint *)(iVar9 + 0x9c);
        if (*(uint *)(iVar9 + 0xa0) < uVar7) {
          iVar5 = *(int *)(iVar9 + 0xa4) - uVar7;
        }
        else {
          iVar5 = -uVar7;
        }
        if (*(uint *)(iVar9 + 0xa0) + iVar5 == 0) {
          if ((uVar12 == 0xffffffff) && ((uVar13 == 0 || (iVar11 != 0)))) goto LAB_c06f257c;
          uVar7 = uVar13;
          if (uVar13 == 0) {
            uVar7 = uVar8;
          }
          if (uVar7 <= uVar14) goto LAB_c06f257c;
          uVar7 = uVar7 - uVar14;
          if (iVar11 != 0) {
            uVar10 = uVar12;
            if (uVar12 == 0) {
              uVar10 = uVar8;
            }
            if ((uVar10 <= uVar7) && (uVar7 = uVar12, uVar12 == 0)) {
              uVar7 = uVar8;
            }
          }
          DVar1 = GetTickCount();
          DVar2 = WaitForSingleObject(*(HANDLE *)(iVar9 + 0x34),uVar7);
          if (DVar2 == 0x102) goto LAB_c06f257c;
          DVar2 = GetTickCount();
          uVar14 = DVar2 + (uVar14 - DVar1);
          if ((*(uint *)(iVar9 + 0x94) & 0x40) != 0) goto LAB_c06f257c;
          if (*(int *)(iVar9 + 0x90) == 0) {
            SetLastError(6);
            goto LAB_c06f257c;
          }
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0xb0));
          uVar7 = *(uint *)(iVar9 + 0xa0);
          uVar8 = *(uint *)(iVar9 + 0x9c);
          if (uVar7 < uVar8) {
            iVar5 = *(int *)(iVar9 + 0xa4) - uVar8;
          }
          else {
            iVar5 = -uVar8;
          }
          uVar10 = *(int *)(iVar9 + 0xa4) - uVar8;
          if (uVar7 + iVar5 < uVar10) {
            if (uVar7 < uVar8) {
              uVar10 = (*(int *)(iVar9 + 0xa4) - uVar8) + uVar7;
            }
            else {
              uVar10 = uVar7 - uVar8;
            }
          }
          if (param_3 <= uVar10) {
            uVar10 = param_3;
          }
          CeSafeCopyMemory(param_2,*(int *)(iVar9 + 0xac) + uVar8,uVar10);
          uVar7 = *(int *)(iVar9 + 0x9c) + uVar10;
          if (*(uint *)(iVar9 + 0xa4) <= uVar7) {
            uVar7 = (*(int *)(iVar9 + 0x9c) - *(uint *)(iVar9 + 0xa4)) + uVar10;
          }
          *(uint *)(iVar9 + 0x9c) = uVar7;
          param_3 = param_3 - uVar10;
          param_2 = uVar10 + param_2;
          iVar11 = uVar10 + iVar11;
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0xb0));
        }
        uVar7 = *(uint *)(iVar9 + 0x9c);
        if (*(uint *)(iVar9 + 0xa0) < uVar7) {
          iVar5 = *(int *)(iVar9 + 0xa4) - uVar7;
        }
        else {
          iVar5 = -uVar7;
        }
        if (*(uint *)(iVar9 + 0xa0) + iVar5 <= (uint)*(ushort *)(iVar9 + 0x6e)) {
          if (((*(uint *)(iVar9 + 0x68) & 0x200) != 0) &&
             (uVar7 = *(uint *)(iVar9 + 0x94), (uVar7 & 8) != 0)) {
            *(uint *)(iVar9 + 0x94) = uVar7 & 0xfffffff7;
            if ((*(uint *)(iVar9 + 0x68) & 0x80) == 0) {
              *(uint *)(iVar9 + 0x94) = uVar7 & 0xfffffff3;
            }
            (**(code **)(*(int *)(*(int *)(iVar9 + 0x28) + 8) + 0x54))
                      (*(undefined4 *)(iVar9 + 0x2c),*(undefined1 *)(iVar9 + 0x75));
          }
          if (((*(uint *)(iVar9 + 0x94) & 0x20) != 0) &&
             ((*(uint *)(iVar9 + 0x68) & 0x3000) == 0x2000)) {
            *(uint *)(iVar9 + 0x94) = *(uint *)(iVar9 + 0x94) & 0xffffffdf;
            (**(code **)(iVar3 + 0x40))(uVar4);
          }
          if (((*(uint *)(iVar9 + 0x94) & 0x10) != 0) && ((*(uint *)(iVar9 + 0x68) & 0x30) == 0x20))
          {
            *(uint *)(iVar9 + 0x94) = *(uint *)(iVar9 + 0x94) & 0xffffffef;
            (**(code **)(iVar3 + 0x38))(uVar4);
          }
        }
        if (param_3 == 0) {
LAB_c06f257c:
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0x14));
          InterlockedDecrement(param_1 + 3);
          return iVar11;
        }
      } while( true );
    }
    DVar1 = 0x57;
  }
  SetLastError(DVar1);
  return -1;
}



/* c06f25ec COM_Seek */

undefined4 COM_Seek(void)

{
                    /* 0x25ec  11  COM_Seek */
  return 0xffffffff;
}



/* c06f25f4 COM_PowerUp */

/* Boundary evidence: original MIPS .pdata c06f25f4..c06f2637. Semantic name remains unreviewed. */

undefined4 COM_PowerUp(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x25f4  7  COM_PowerUp */
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x28) + 8) + 0x30))
                      (*(undefined4 *)(param_1 + 0x2c));
  }
  return uVar1;
}



/* c06f2638 COM_PowerDown */

/* Boundary evidence: original MIPS .pdata c06f2638..c06f267b. Semantic name remains unreviewed. */

undefined4 COM_PowerDown(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x2638  6  COM_PowerDown */
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x28) + 8) + 0x2c))
                      (*(undefined4 *)(param_1 + 0x2c));
  }
  return uVar1;
}



/* c06f267c FUN_c06f267c */

/* Boundary evidence: original MIPS .pdata c06f267c..c06f284f. Semantic name remains unreviewed. */

undefined4 FUN_c06f267c(int *param_1,uint *param_2)

{
  uint uVar1;
  DWORD dwErrCode;
  int iVar2;
  
  iVar2 = *param_1;
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x90) != 0)) {
    if (param_1[5] == 0) {
      dwErrCode = 0x57;
      goto LAB_c06f2810;
    }
    InterlockedIncrement(param_1 + 3);
    param_1[7] = 0;
    if (*(int *)(iVar2 + 0x90) != 0) {
      do {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        EventModify(param_1[4],2);
        uVar1 = InterlockedExchange(param_1 + 6,0);
        if (((param_1[5] & uVar1) != 0) || (param_1[5] == 0)) {
          *param_2 = param_1[5] & uVar1;
          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        WaitForSingleObject((HANDLE)param_1[4],0xffffffff);
        if (param_1[7] != 0) {
          *param_2 = 0;
          break;
        }
      } while (*(int *)(iVar2 + 0x90) != 0);
    }
    InterlockedDecrement(param_1 + 3);
    if (*(int *)(iVar2 + 0x90) != 0) {
      return 1;
    }
  }
  dwErrCode = 6;
LAB_c06f2810:
  *param_2 = 0;
  SetLastError(dwErrCode);
  return 0;
}



/* c06f2850 FUN_c06f2850 */

/* Boundary evidence: original MIPS .pdata c06f2850..c06f285b. Semantic name remains unreviewed. */

undefined4 FUN_c06f2850(void)

{
  return 1;
}



/* c06f285c FUN_c06f285c */

/* Boundary evidence: original MIPS .pdata c06f285c..c06f294b. Semantic name remains unreviewed. */

void FUN_c06f285c(int param_1,uint param_2)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  if (*(int *)(param_1 + 0x90) == 0) {
    SetLastError(6);
  }
  else if ((*(uint *)(param_1 + 0x98) & param_2) != 0) {
    piVar2 = (int *)*(int *)(param_1 + 0xe4);
    while (piVar2 != (int *)(param_1 + 0xe4)) {
      piVar5 = (int *)*piVar2;
      EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + -5));
      if ((piVar2[-8] & param_2) != 0) {
        uVar3 = piVar2[-7];
        do {
          uVar4 = InterlockedExchange(piVar2 + -7,uVar3 | param_2);
          bVar1 = uVar3 != uVar4;
          uVar3 = uVar4;
        } while (bVar1);
        EventModify(piVar2[-9],3);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + -5));
      piVar2 = piVar5;
    }
  }
  return;
}



/* c06f294c COM_IOControl */

/* Boundary evidence: original MIPS .pdata c06f294c..c06f33b7. Semantic name remains unreviewed. */

bool COM_IOControl(int *param_1,int param_2,uint *param_3,uint param_4,uint *param_5,uint param_6,
                  undefined4 *param_7)

{
  DWORD DVar1;
  undefined1 *_Src;
  size_t _Size;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  uint uVar11;
  int iVar12;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar13;
  uint local_a0;
  int *local_9c;
  LONG *local_98;
  uint local_90;
  uint local_8c [7];
  undefined1 auStack_70 [64];
  uint local_30;
  
                    /* 0x294c  3  COM_IOControl */
  local_30 = DAT_c06f90d8;
  bVar9 = true;
  bVar10 = true;
  local_a0 = param_4;
  local_9c = param_1;
  if ((param_1 == (int *)0x0) || (iVar7 = *param_1, iVar7 == 0)) {
    SetLastError(6);
    goto LAB_c06f337c;
  }
  iVar12 = *(int *)(*(int *)(iVar7 + 0x28) + 8);
  uVar13 = *(undefined4 *)(iVar7 + 0x2c);
  if ((param_1[1] & 0x100U) != 0) {
    if ((((param_2 == 0x321000) || (param_2 == 0x321004)) || (param_2 == 0x321008)) ||
       ((param_2 == 0x32100c || (param_2 == 0x321018)))) {
      if ((*(code **)(iVar12 + 0x74) != (code *)0x0) &&
         (iVar7 = (**(code **)(iVar12 + 0x74))
                            (uVar13,param_2,param_3,param_4,param_5,param_6,param_7), iVar7 != 0))
      goto LAB_c06f2a74;
      SetLastError(0x57);
    }
    else {
      SetLastError(6);
    }
    bVar10 = false;
    goto LAB_c06f2a74;
  }
  if (*(int *)(iVar7 + 0x90) == 0) {
    DVar1 = 6;
LAB_c06f2a9c:
    SetLastError(DVar1);
LAB_c06f337c:
    FUN_c06f7da0(local_30);
    return false;
  }
  if (param_2 == 0x10303ff) {
    if ((*param_3 == 0x10) && (param_3[1] == 4)) {
      FUN_c06f1ea8(param_1);
    }
    goto LAB_c06f2a74;
  }
  if ((((param_2 != 0x1b0024) && (param_2 != 0x1b0028)) && (param_2 != 0x1b002c)) &&
     (((((param_2 != 0x1b0034 && (param_2 != 0x1b0038)) &&
        ((param_2 != 0x1b0040 && ((param_2 != 0x321000 && (param_2 != 0x32100c)))))) &&
       (param_2 != 0x321008)) && ((param_1[1] & 0xc0000000U) == 0)))) {
    DVar1 = 0xc;
    goto LAB_c06f2a9c;
  }
  local_98 = param_1 + 3;
  InterlockedIncrement(local_98);
  piVar4 = local_9c;
  bVar10 = bVar9;
  switch(param_2) {
  case 0x1b0004:
    (**(code **)(iVar12 + 0x50))(uVar13);
    break;
  default:
    if (*(code **)(iVar12 + 0x74) != (code *)0x0) {
      iVar7 = (**(code **)(iVar12 + 0x74))(uVar13,param_2,param_3,local_a0,param_5,param_6,param_7);
LAB_c06f333c:
      if (iVar7 != 0) break;
    }
    goto LAB_c06f334c;
  case 0x1b0008:
    pcVar3 = *(code **)(iVar12 + 0x4c);
    goto LAB_c06f2cb0;
  case 0x1b000c:
    if ((*(uint *)(iVar7 + 0x68) & 0x30) == 0x20) goto LAB_c06f334c;
    pcVar3 = *(code **)(iVar12 + 0x38);
LAB_c06f2cd8:
    (*pcVar3)(uVar13);
    break;
  case 0x1b0010:
    if ((*(uint *)(iVar7 + 0x68) & 0x30) != 0x20) {
      pcVar3 = *(code **)(iVar12 + 0x34);
      goto LAB_c06f2cd8;
    }
    goto LAB_c06f334c;
  case 0x1b0014:
    if ((*(uint *)(iVar7 + 0x68) & 0x3000) != 0x2000) {
      pcVar3 = *(code **)(iVar12 + 0x40);
      goto LAB_c06f2cd8;
    }
    goto LAB_c06f334c;
  case 0x1b0018:
    if ((*(uint *)(iVar7 + 0x68) & 0x3000) != 0x2000) {
      pcVar3 = *(code **)(iVar12 + 0x3c);
      goto LAB_c06f2cd8;
    }
    goto LAB_c06f334c;
  case 0x1b001c:
    if ((*(uint *)(iVar7 + 0x94) & 2) != 0) {
      uVar11 = *(uint *)(iVar7 + 0x94) | 0xc;
LAB_c06f2d50:
      *(uint *)(iVar7 + 0x94) = uVar11;
    }
    break;
  case 0x1b0020:
    if ((*(uint *)(iVar7 + 0x94) & 2) != 0) {
      uVar11 = *(uint *)(iVar7 + 0x94) & 0xfffffff3;
      goto LAB_c06f2d50;
    }
    break;
  case 0x1b0024:
    if (((param_6 < 4) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c06f334c;
    *param_5 = local_9c[5];
    *param_7 = 4;
    break;
  case 0x1b0028:
    if ((local_a0 < 4) || (param_3 == (uint *)0x0)) goto LAB_c06f334c;
    uVar11 = *param_3;
    lpCriticalSection = (LPCRITICAL_SECTION)(local_9c + 8);
    EnterCriticalSection(lpCriticalSection);
    piVar4[5] = uVar11;
    piVar4[7] = 1;
    EventModify(piVar4[4],3);
    uVar11 = 0;
    for (piVar4 = *(int **)(iVar7 + 0xe4); piVar4 != (int *)(iVar7 + 0xe4); piVar4 = (int *)*piVar4)
    {
      uVar11 = piVar4[-8] | uVar11;
    }
    *(uint *)(iVar7 + 0x98) = uVar11;
    LeaveCriticalSection(lpCriticalSection);
    break;
  case 0x1b002c:
    if (((param_6 < 4) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c06f334c;
    local_a0 = 0;
    iVar7 = FUN_c06f267c(local_9c,&local_a0);
    *param_5 = local_a0;
    *param_7 = 4;
    bVar10 = iVar7 != 0;
    break;
  case 0x1b0030:
    if (((param_6 < 0x10) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c06f334c;
    memset(local_8c,0,0xc);
    local_90 = InterlockedExchange((LONG *)(iVar7 + 0x104),0);
    uVar11 = (**(code **)(iVar12 + 0x58))(uVar13,local_8c);
    uVar6 = *(uint *)(iVar7 + 0xa0);
    uVar5 = *(uint *)(iVar7 + 0x9c);
    if (uVar6 < uVar5) {
      iVar12 = *(int *)(iVar7 + 0xa4) - uVar5;
    }
    else {
      iVar12 = -uVar5;
    }
    iVar2 = *(int *)(iVar7 + 0x94);
    uVar5 = *(uint *)(iVar7 + 0x58);
    *param_5 = uVar11 | local_90;
    param_5[1] = (iVar2 << 1 ^ local_8c[0]) & 0x18 ^ local_8c[0];
    param_5[2] = uVar6 + iVar12;
    param_5[3] = uVar5;
    *param_7 = 0x10;
    break;
  case 0x1b0034:
    local_9c = (int *)0x0;
    if (((param_6 < 4) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c06f334c;
    (**(code **)(iVar12 + 0x60))(uVar13,&local_9c);
    *param_7 = 4;
    *param_5 = (uint)local_9c;
    break;
  case 0x1b0038:
    if (((param_6 < 0x40) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c06f334c;
    uVar8 = 0x40;
    memset(auStack_70,0,0x40);
    (**(code **)(iVar12 + 100))(uVar13,auStack_70);
    _Src = auStack_70;
    _Size = 0x40;
LAB_c06f2fdc:
    memcpy(param_5,_Src,_Size);
    *param_7 = uVar8;
    break;
  case 0x1b003c:
    if ((local_a0 < 0x14) || (param_3 == (uint *)0x0)) goto LAB_c06f334c;
    *(uint *)(iVar7 + 0x7c) = *param_3;
    *(uint *)(iVar7 + 0x80) = param_3[1];
    *(uint *)(iVar7 + 0x84) = param_3[2];
    *(uint *)(iVar7 + 0x88) = param_3[3];
    *(uint *)(iVar7 + 0x8c) = param_3[4];
    (**(code **)(iVar12 + 0x70))(uVar13);
    break;
  case 0x1b0040:
    if (((param_6 < 0x14) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c06f334c;
    memset(param_5,0,0x14);
    *param_5 = *(uint *)(iVar7 + 0x7c);
    param_5[1] = *(uint *)(iVar7 + 0x80);
    param_5[2] = *(uint *)(iVar7 + 0x84);
    param_5[3] = *(uint *)(iVar7 + 0x88);
    param_5[4] = *(uint *)(iVar7 + 0x8c);
    *param_7 = 0x14;
    break;
  case 0x1b0044:
    if ((local_a0 < 4) || (param_3 == (uint *)0x0)) goto LAB_c06f334c;
    uVar11 = *param_3;
    (**(code **)(iVar12 + 0x68))(uVar13,uVar11);
    if ((uVar11 & 8) != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar7 + 0xb0));
      *(undefined4 *)(iVar7 + 0x9c) = *(undefined4 *)(iVar7 + 0xa0);
      memset(*(void **)(iVar7 + 0xac),0,*(size_t *)(iVar7 + 0xa4));
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar7 + 0xb0));
      if (((*(uint *)(iVar7 + 0x68) & 0x200) != 0) &&
         (uVar5 = *(uint *)(iVar7 + 0x94), (uVar5 & 8) != 0)) {
        *(uint *)(iVar7 + 0x94) = uVar5 & 0xfffffff7;
        if ((*(uint *)(iVar7 + 0x68) & 0x80) == 0) {
          *(uint *)(iVar7 + 0x94) = uVar5 & 0xfffffff3;
        }
        (**(code **)(iVar12 + 0x54))(*(undefined4 *)(iVar7 + 0x2c),*(undefined1 *)(iVar7 + 0x75));
      }
      if (((*(uint *)(iVar7 + 0x94) & 0x20) != 0) && ((*(uint *)(iVar7 + 0x68) & 0x3000) == 0x2000))
      {
        *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) & 0xffffffdf;
        (**(code **)(iVar12 + 0x40))(*(undefined4 *)(iVar7 + 0x2c));
      }
      if (((*(uint *)(iVar7 + 0x94) & 0x10) != 0) && ((*(uint *)(iVar7 + 0x68) & 0x30) == 0x20)) {
        *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) & 0xffffffef;
        (**(code **)(iVar12 + 0x38))(uVar13);
      }
    }
    if ((uVar11 & 2) != 0) {
      *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) | 0x40;
      EventModify(*(undefined4 *)(iVar7 + 0x34),1);
    }
    if ((uVar11 & 1) != 0) {
      *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) | 0x80;
      EventModify(*(undefined4 *)(iVar7 + 0x3c),3);
    }
    break;
  case 0x1b0048:
    DVar1 = 0x32;
    goto LAB_c06f3350;
  case 0x1b004c:
    if ((local_a0 == 0) || (param_3 == (uint *)0x0)) goto LAB_c06f334c;
    (**(code **)(iVar12 + 0x54))(uVar13,(char)*param_3);
    break;
  case 0x1b0050:
    if (((0x1b < param_6) && (param_5 != (uint *)0x0)) && (param_7 != (undefined4 *)0x0)) {
      _Src = (undefined1 *)(iVar7 + 0x60);
      uVar8 = 0x1c;
      _Size = 0x1c;
      goto LAB_c06f2fdc;
    }
    goto LAB_c06f334c;
  case 0x1b0054:
    if ((0x1b < local_a0) && (param_3 != (uint *)0x0)) {
      memcpy(&local_90,param_3,0x1c);
      iVar7 = FUN_c06f18b8(iVar7,&local_90,1);
      goto LAB_c06f333c;
    }
LAB_c06f334c:
    DVar1 = 0x57;
LAB_c06f3350:
    SetLastError(DVar1);
LAB_c06f3358:
    bVar10 = false;
    break;
  case 0x1b0058:
    iVar7 = (**(code **)(iVar12 + 0x44))(uVar13,*(undefined4 *)(iVar7 + 100));
    if (iVar7 != 0) break;
    goto LAB_c06f3358;
  case 0x1b005c:
    pcVar3 = *(code **)(iVar12 + 0x48);
LAB_c06f2cb0:
    (*pcVar3)(uVar13);
  }
  InterlockedDecrement(local_98);
LAB_c06f2a74:
  FUN_c06f7da0(local_30);
  return bVar10;
}



/* c06f33b8 FUN_c06f33b8 */

/* Boundary evidence: original MIPS .pdata c06f33b8..c06f37ab. Semantic name remains unreviewed. */

void FUN_c06f33b8(int param_1)

{
  bool bVar1;
  uint uVar2;
  byte *_Dst;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint local_40 [2];
  undefined1 auStack_38 [16];
  uint local_28;
  
  local_28 = DAT_c06f90d8;
  iVar7 = *(int *)(*(int *)(param_1 + 0x28) + 8);
  uVar8 = *(undefined4 *)(param_1 + 0x2c);
  bVar1 = false;
  local_40[0] = 0;
  if (((*(uint *)(param_1 + 0x94) & 1) != 0) || (*(int *)(param_1 + 0x30) == 0)) {
    EventModify(*(undefined4 *)(param_1 + 0x38),3);
                    /* WARNING: Subroutine does not return */
    ExitThread(0);
  }
  if (*(int *)(param_1 + 0x100) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(param_1 + 0x100) + 0xc));
  }
  uVar2 = (**(code **)(iVar7 + 0x14))(uVar8);
  if (uVar2 != 0) {
    do {
      if ((uVar2 & 2) != 0) {
        uVar4 = *(uint *)(param_1 + 0xa0);
        uVar5 = *(uint *)(param_1 + 0x9c);
        if (uVar5 == 0) {
          iVar3 = *(int *)(param_1 + 0xa4) - uVar4;
LAB_c06f3498:
          local_40[0] = iVar3 - 1;
        }
        else {
          local_40[0] = *(int *)(param_1 + 0xa4) - uVar4;
          if (uVar4 < uVar5) {
            iVar3 = uVar5 - uVar4;
            goto LAB_c06f3498;
          }
        }
        if (local_40[0] == 0) {
          local_40[0] = 0x10;
          (**(code **)(iVar7 + 0x18))(uVar8,auStack_38,local_40);
          uVar4 = local_40[0];
          local_40[0] = 0;
          *(uint *)(param_1 + 0x48) = uVar4 + *(int *)(param_1 + 0x48);
          do {
            uVar5 = *(uint *)(param_1 + 0x104);
            uVar4 = InterlockedCompareExchange((LONG *)(param_1 + 0x104),uVar5 | 1,uVar5);
          } while (uVar5 != uVar4);
        }
        else {
          iVar3 = (**(code **)(iVar7 + 0x18))(uVar8,*(int *)(param_1 + 0xac) + uVar4);
          *(int *)(param_1 + 0x4c) = iVar3 + *(int *)(param_1 + 0x4c);
        }
        uVar4 = local_40[0];
        if (((*(uint *)(param_1 + 0x94) & 2) != 0) && (uVar5 = 0, local_40[0] != 0)) {
          do {
            _Dst = (byte *)(*(int *)(param_1 + 0xac) + uVar5 + *(int *)(param_1 + 0xa0));
            if ((uint)*_Dst == (int)*(char *)(param_1 + 0x76)) {
              *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 4;
              memmove(_Dst,_Dst + 1,uVar4 - uVar5);
              uVar4 = local_40[0] - 1;
              local_40[0] = uVar4;
            }
            else if ((uint)*_Dst == (int)*(char *)(param_1 + 0x75)) {
              *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfffffffb;
              memmove(_Dst,_Dst + 1,uVar4 - uVar5);
              uVar2 = uVar2 | 4;
              uVar4 = local_40[0] - 1;
              local_40[0] = uVar4;
            }
            else {
              uVar5 = uVar5 + 1;
            }
          } while (uVar5 < uVar4);
        }
        uVar6 = *(uint *)(param_1 + 0xa4);
        uVar5 = *(int *)(param_1 + 0xa0) + uVar4;
        *(uint *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + uVar4;
        if (uVar6 <= uVar5) {
          uVar5 = (*(int *)(param_1 + 0xa0) - uVar6) + uVar4;
        }
        *(uint *)(param_1 + 0xa0) = uVar5;
        if (uVar4 != 0) {
          bVar1 = true;
        }
        uVar4 = *(uint *)(param_1 + 0x9c);
        if (uVar5 < uVar4) {
          iVar3 = uVar6 - uVar4;
        }
        else {
          iVar3 = -uVar4;
        }
        if (uVar6 - (uVar5 + iVar3) <= (uint)*(ushort *)(param_1 + 0x70)) {
          if (((*(uint *)(param_1 + 0x68) & 0x30) == 0x20) &&
             ((*(uint *)(param_1 + 0x94) & 0x10) == 0)) {
            *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x10;
            (**(code **)(iVar7 + 0x34))(uVar8);
          }
          if (((*(uint *)(param_1 + 0x68) & 0x3000) == 0x2000) &&
             ((*(uint *)(param_1 + 0x94) & 0x20) == 0)) {
            *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x20;
            (**(code **)(iVar7 + 0x3c))(uVar8);
          }
          if (((*(uint *)(param_1 + 0x68) & 0x200) != 0) && ((*(uint *)(param_1 + 0x94) & 8) == 0))
          {
            (**(code **)(iVar7 + 0x54))(uVar8,*(undefined1 *)(param_1 + 0x76));
            uVar4 = *(uint *)(param_1 + 0x94);
            *(uint *)(param_1 + 0x94) = uVar4 | 8;
            if ((*(uint *)(param_1 + 0x68) & 0x80) == 0) {
              *(uint *)(param_1 + 0x94) = uVar4 | 0xc;
            }
          }
        }
      }
      if ((uVar2 & 4) != 0) {
        FUN_c06f16a4(param_1);
      }
      if ((uVar2 & 8) != 0) {
        (**(code **)(iVar7 + 0x20))(uVar8);
      }
      if ((uVar2 & 1) != 0) {
        (**(code **)(iVar7 + 0x24))(uVar8);
      }
      uVar2 = (**(code **)(iVar7 + 0x14))(uVar8);
    } while (uVar2 != 0);
    if (bVar1) {
      EventModify(*(undefined4 *)(param_1 + 0x34),3);
      FUN_c06f285c(param_1,1);
    }
  }
  if (*(int *)(param_1 + 0x100) != 0) {
    InterlockedDecrement((LONG *)(*(int *)(param_1 + 0x100) + 0xc));
  }
  FUN_c06f7da0(local_28);
  return;
}



/* c06f37ac FUN_c06f37ac */

/* Boundary evidence: original MIPS .pdata c06f37ac..c06f385b. Semantic name remains unreviewed. */

undefined4 FUN_c06f37ac(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((**(uint **)(param_1 + 0x28) & 3) != 0) {
    iVar2 = *(int *)(param_1 + 0x40);
    while (iVar2 == 0) {
      Sleep(0x14);
      iVar2 = *(int *)(param_1 + 0x40);
    }
  }
  uVar1 = *(uint *)(param_1 + 0x94);
  while ((uVar1 & 1) == 0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x30),0xffffffff);
    FUN_c06f33b8(param_1);
    InterruptDone(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
    uVar1 = *(uint *)(param_1 + 0x94);
  }
  return 0;
}



/* c06f385c FUN_c06f385c */

/* Boundary evidence: original MIPS .pdata c06f385c..c06f38f3. Semantic name remains unreviewed. */

undefined4 FUN_c06f385c(LPVOID param_1)

{
  int iVar1;
  HANDLE pvVar2;
  
  iVar1 = InterruptInitialize(*(undefined4 *)(*(int *)((int)param_1 + 0x28) + 4),
                              *(undefined4 *)((int)param_1 + 0x30),0,0);
  if (iVar1 != 0) {
    InterruptDone(*(undefined4 *)(*(int *)((int)param_1 + 0x28) + 4));
    *(uint *)((int)param_1 + 0x94) = *(uint *)((int)param_1 + 0x94) & 0xfffffffe;
    *(undefined4 *)((int)param_1 + 0x40) = 0;
    pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c06f37ac,param_1,0,(LPDWORD)0x0);
    *(HANDLE *)((int)param_1 + 0x40) = pvVar2;
    if (pvVar2 != (HANDLE)0x0) {
      return 1;
    }
  }
  return 0;
}



/* c06f38f4 COM_Init */

/* Boundary evidence: original MIPS .pdata c06f38f4..c06f3bcf. Semantic name remains unreviewed. */

LPCRITICAL_SECTION COM_Init(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  PRTL_CRITICAL_SECTION_DEBUG p_Var1;
  HANDLE pvVar2;
  HKEY hKey;
  LSTATUS LVar3;
  undefined4 *puVar4;
  ULONG_PTR UVar5;
  int iVar6;
  HLOCAL pvVar7;
  HANDLE *ppvVar8;
  SIZE_T uBytes;
  uint *puVar9;
  DWORD local_28;
  DWORD DStack_24;
  BYTE local_20 [8];
  
                    /* 0x38f4  4  COM_Init */
  local_28 = 4;
  lpCriticalSection = LocalAlloc(0x40,0x108);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    memset(lpCriticalSection,0,0x108);
    ppvVar8 = &lpCriticalSection[9].OwningThread;
    lpCriticalSection[9].LockSemaphore = ppvVar8;
    *ppvVar8 = ppvVar8;
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection[9].SpinCount);
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection->SpinCount);
    InitializeCriticalSection(lpCriticalSection);
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection[7].RecursionCount);
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection[8].LockSemaphore);
    lpCriticalSection[5].LockCount = 0xfa;
    lpCriticalSection[10].LockSemaphore = (HANDLE)0x0;
    lpCriticalSection[6].RecursionCount = 0;
    lpCriticalSection[5].RecursionCount = 10;
    lpCriticalSection[5].OwningThread = (HANDLE)0x64;
    lpCriticalSection[5].LockSemaphore = (HANDLE)0x0;
    lpCriticalSection[5].SpinCount = 0;
    p_Var1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].DebugInfo = p_Var1;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].RecursionCount = (LONG)pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].OwningThread = pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].LockCount = (LONG)pvVar2;
    if ((((lpCriticalSection[2].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) &&
         (lpCriticalSection[2].RecursionCount != 0)) &&
        (lpCriticalSection[2].OwningThread != (HANDLE)0x0)) &&
       ((pvVar2 != (HANDLE)0x0 && (hKey = (HKEY)OpenDeviceKey(param_1), hKey != (HKEY)0x0)))) {
      local_28 = 4;
      LVar3 = RegQueryValueExW(hKey,L"DeviceArrayIndex",(LPDWORD)0x0,&DStack_24,local_20,&local_28);
      if (LVar3 == 0) {
        local_28 = 4;
        LVar3 = RegQueryValueExW(hKey,L"Priority256",(LPDWORD)0x0,&DStack_24,
                                 (LPBYTE)&lpCriticalSection[2].SpinCount,&local_28);
        if (LVar3 != 0) {
          lpCriticalSection[2].SpinCount = 0x67;
        }
        RegCloseKey(hKey);
        puVar4 = FUN_c06f5314();
        lpCriticalSection[1].LockSemaphore = puVar4;
        if (puVar4 != (undefined4 *)0x0) {
          UVar5 = (**(code **)puVar4[2])(param_1,lpCriticalSection,puVar4);
          lpCriticalSection[1].SpinCount = UVar5;
          if (UVar5 != 0) {
            iVar6 = (**(code **)(*(int *)((int)lpCriticalSection[1].LockSemaphore + 8) + 0x28))
                              (UVar5);
            uBytes = iVar6 << 1;
            if (uBytes < 0x801) {
              uBytes = 0x800;
            }
            lpCriticalSection[6].SpinCount = uBytes;
            pvVar7 = LocalAlloc(0x40,uBytes);
            lpCriticalSection[7].LockCount = (LONG)pvVar7;
            if (pvVar7 != (HLOCAL)0x0) {
              puVar9 = lpCriticalSection[1].LockSemaphore;
              lpCriticalSection[6].OwningThread = (HANDLE)0x0;
              lpCriticalSection[6].LockSemaphore = (HANDLE)0x0;
              if (((*puVar9 & 1) == 0) || (iVar6 = FUN_c06f385c(lpCriticalSection), iVar6 != 0)) {
                (**(code **)(*(int *)((int)lpCriticalSection[1].LockSemaphore + 8) + 4))(UVar5);
                return lpCriticalSection;
              }
            }
          }
        }
      }
      else {
        RegCloseKey(hKey);
      }
    }
    COM_Deinit(lpCriticalSection);
  }
  return (LPCRITICAL_SECTION)0x0;
}



/* c06f3bd0 COM_Open */

/* Boundary evidence: original MIPS .pdata c06f3bd0..c06f3f0b. Semantic name remains unreviewed. */

undefined4 * COM_Open(LPVOID param_1,uint param_2,undefined4 param_3)

{
  undefined4 *hMem;
  HANDLE pvVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar7;
  
                    /* 0x3bd0  5  COM_Open */
  puVar7 = *(uint **)((int)param_1 + 0x28);
  if ((param_2 & 0x100) != 0) {
    param_2 = param_2 & 0xfffffff;
  }
  if (((param_2 & 0xc0000000) != 0) && (*(int *)((int)param_1 + 0x100) != 0)) {
    SetLastError(0xc);
    return (undefined4 *)0x0;
  }
  hMem = LocalAlloc(0x40,0x3c);
  if (hMem == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *hMem = param_1;
  hMem[3] = 0;
  hMem[1] = param_2;
  hMem[2] = param_3;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  hMem[4] = pvVar1;
  hMem[5] = 0;
  hMem[6] = 0;
  hMem[7] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(hMem + 8));
  if ((param_2 & 0xc0000000) != 0) {
    *(undefined4 **)((int)param_1 + 0x100) = hMem;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0xec);
  EnterCriticalSection(lpCriticalSection);
  piVar2 = (int *)((int)param_1 + 0xe4);
  iVar3 = *piVar2;
  piVar6 = hMem + 0xd;
  *piVar6 = iVar3;
  hMem[0xe] = piVar2;
  *(int **)(iVar3 + 4) = piVar6;
  *piVar2 = (int)piVar6;
  if ((hMem[1] & 0x100) == 0) {
    if (*(int *)((int)param_1 + 0x90) == 0) {
      if (((**(uint **)((int)param_1 + 0x28) & 2) != 0) &&
         (iVar3 = FUN_c06f385c(param_1), iVar3 == 0)) {
LAB_c06f3e0c:
        SetLastError(0x6e);
        if (hMem == *(undefined4 **)((int)param_1 + 0x100)) {
          *(undefined4 *)((int)param_1 + 0x100) = 0;
        }
        *(int *)hMem[0xe] = *piVar6;
        *(undefined4 *)(*piVar6 + 4) = hMem[0xe];
        LeaveCriticalSection(lpCriticalSection);
        if ((HANDLE)hMem[4] != (HANDLE)0x0) {
          CloseHandle((HANDLE)hMem[4]);
        }
        DeleteCriticalSection((LPCRITICAL_SECTION)(hMem + 8));
        LocalFree(hMem);
        return (undefined4 *)0x0;
      }
      *(undefined4 *)((int)param_1 + 0x60) = 0x1c;
      uVar4 = *(uint *)((int)param_1 + 0xa4);
      *(undefined4 *)((int)param_1 + 100) = 0x2580;
      *(uint *)((int)param_1 + 0x68) = *(uint *)((int)param_1 + 0x68) & 0xffff9011 | 0x1011;
      uVar5 = uVar4 - (uVar4 >> 3 & 0xffff);
      *(short *)((int)param_1 + 0x70) = (short)(uVar4 >> 3);
      *(undefined4 *)((int)param_1 + 0x50) = 0;
      *(undefined4 *)((int)param_1 + 0x54) = 0;
      *(undefined4 *)((int)param_1 + 0x58) = 0;
      *(undefined4 *)((int)param_1 + 0x48) = 0;
      *(undefined4 *)((int)param_1 + 0x4c) = 0;
      *(short *)((int)param_1 + 0x6e) = (short)(uVar4 >> 1);
      if (uVar5 <= (uVar4 >> 1 & 0xffff)) {
        *(short *)((int)param_1 + 0x6e) = (short)uVar5 + -1;
      }
      *(undefined1 *)((int)param_1 + 0x72) = 8;
      *(undefined1 *)((int)param_1 + 0x76) = 0x13;
      *(undefined1 *)((int)param_1 + 0x75) = 0x11;
      *(undefined1 *)((int)param_1 + 0x73) = 0;
      *(undefined1 *)((int)param_1 + 0x74) = 0;
      *(undefined1 *)((int)param_1 + 0x77) = 0xd;
      *(undefined1 *)((int)param_1 + 0x78) = 0xd;
      *(undefined1 *)((int)param_1 + 0x79) = 0xd;
      *(uint *)((int)param_1 + 0x94) = *(uint *)((int)param_1 + 0x94) & 0xffffffc3;
      FUN_c06f18b8((int)param_1,(undefined4 *)((int)param_1 + 0x60),0);
      (**(code **)(puVar7[2] + 0x70))(*(undefined4 *)((int)param_1 + 0x2c),(int)param_1 + 0x7c);
      iVar3 = (**(code **)(puVar7[2] + 0xc))(*(undefined4 *)((int)param_1 + 0x2c));
      if (iVar3 == 0) goto LAB_c06f3e0c;
      (**(code **)(puVar7[2] + 0x68))(*(undefined4 *)((int)param_1 + 0x2c),8);
      memset(*(void **)((int)param_1 + 0xac),0,*(size_t *)((int)param_1 + 0xa4));
      if ((*puVar7 & 3) != 0) {
        CeSetThreadPriority(*(undefined4 *)((int)param_1 + 0x40),
                            *(undefined4 *)((int)param_1 + 0x44));
      }
      *(undefined4 *)((int)param_1 + 0x9c) = 0;
      *(undefined4 *)((int)param_1 + 0xa0) = 0;
    }
    *(int *)((int)param_1 + 0x90) = *(int *)((int)param_1 + 0x90) + 1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return hMem;
}



/* c06f3f0c COM_Write */

/* Boundary evidence: original MIPS .pdata c06f3f0c..c06f4167. Semantic name remains unreviewed. */

ULONG_PTR COM_Write(undefined4 *param_1,int param_2,HANDLE param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  HANDLE *lpCriticalSection_00;
  ULONG_PTR UVar4;
  HANDLE local_30 [2];
  
                    /* 0x3f0c  12  COM_Write */
  lpCriticalSection = (LPCRITICAL_SECTION)*param_1;
  local_30[0] = (HANDLE)0x0;
  if ((lpCriticalSection == (LPCRITICAL_SECTION)0x0) ||
     (lpCriticalSection[6].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0)) {
    DVar2 = 6;
  }
  else if ((param_1[1] & 0x40000000) == 0) {
    DVar2 = 0xc;
  }
  else {
    if ((param_2 != 0) && (param_3 != (HANDLE)0x0)) {
      iVar1 = CeAllocAsynchronousBuffer(local_30,param_2,param_3,4);
      if (iVar1 < 0) {
        return 0xffffffff;
      }
      if (local_30[0] == (HANDLE)0x0) {
        return 0xffffffff;
      }
      InterlockedIncrement(param_1 + 3);
      UVar4 = lpCriticalSection[1].SpinCount;
      iVar1 = *(int *)((int)lpCriticalSection[1].LockSemaphore + 8);
      EnterCriticalSection(lpCriticalSection);
      lpCriticalSection_00 = &lpCriticalSection[8].LockSemaphore;
      EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      lpCriticalSection[6].LockCount = lpCriticalSection[6].LockCount & 0xffffff7f;
      WaitForSingleObject(lpCriticalSection[2].OwningThread,0);
      pvVar3 = lpCriticalSection[2].OwningThread;
      lpCriticalSection[8].OwningThread = local_30[0];
      lpCriticalSection[8].RecursionCount = (LONG)param_3;
      lpCriticalSection[8].LockCount = 0;
      lpCriticalSection[3].SpinCount = 0;
      lpCriticalSection[3].LockSemaphore = param_3;
      EventModify(pvVar3,2);
      LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      FUN_c06f16a4((int)lpCriticalSection);
      DVar2 = (int)lpCriticalSection[5].LockSemaphore * (int)param_3 +
              lpCriticalSection[5].SpinCount;
      if (DVar2 == 0) {
        DVar2 = 0xffffffff;
      }
      WaitForSingleObject(lpCriticalSection[2].OwningThread,DVar2);
      if (((lpCriticalSection[6].LockCount & 0x80U) == 0) &&
         (lpCriticalSection[6].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0)) {
        SetLastError(6);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      lpCriticalSection[8].OwningThread = (HANDLE)0x0;
      lpCriticalSection[8].RecursionCount = 0;
      lpCriticalSection[3].LockSemaphore = (HANDLE)0x0;
      lpCriticalSection[8].LockCount = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      LeaveCriticalSection(lpCriticalSection);
      FUN_c06f285c((int)lpCriticalSection,4);
      if ((lpCriticalSection[4].RecursionCount & 0x3000U) == 0x3000) {
        (**(code **)(iVar1 + 0x3c))(UVar4);
      }
      InterlockedDecrement(param_1 + 3);
      if (local_30[0] != (HANDLE)0x0) {
        CeFreeAsynchronousBuffer(local_30[0],param_2,param_3,4);
      }
      return lpCriticalSection[3].SpinCount;
    }
    DVar2 = 0x57;
  }
  SetLastError(DVar2);
  return 0xffffffff;
}



/* c06f4168 FUN_c06f4168 */

/* Boundary evidence: original MIPS .pdata c06f4168..c06f446b. Semantic name remains unreviewed. */

HMODULE FUN_c06f4168(void)

{
  HMODULE hLibModule;
  int *piVar1;
  
  hLibModule = LoadLibraryW(L"pcmcia.dll");
  if (hLibModule != (HMODULE)0x0) {
    DAT_c06f9100 = GetProcAddressW(hLibModule,L"CardRegisterClient");
    piVar1 = &DAT_c06f9100;
    DAT_c06f9104 = GetProcAddressW(hLibModule,L"CardDeregisterClient");
    DAT_c06f9108 = GetProcAddressW(hLibModule,L"CardGetFirstTuple");
    DAT_c06f910c = GetProcAddressW(hLibModule,L"CardGetNextTuple");
    DAT_c06f9110 = GetProcAddressW(hLibModule,L"CardGetTupleData");
    DAT_c06f9114 = GetProcAddressW(hLibModule,L"CardGetParsedTuple");
    DAT_c06f9118 = GetProcAddressW(hLibModule,L"CardRequestExclusive");
    DAT_c06f911c = GetProcAddressW(hLibModule,L"CardReleaseExclusive");
    DAT_c06f9120 = GetProcAddressW(hLibModule,L"CardRequestSocketMask");
    DAT_c06f9124 = GetProcAddressW(hLibModule,L"CardReleaseSocketMask");
    DAT_c06f9128 = GetProcAddressW(hLibModule,L"CardGetEventMask");
    DAT_c06f912c = GetProcAddressW(hLibModule,L"CardSetEventMask");
    DAT_c06f9130 = GetProcAddressW(hLibModule,L"CardResetFunction");
    DAT_c06f9134 = GetProcAddressW(hLibModule,L"CardRequestWindow");
    DAT_c06f9138 = GetProcAddressW(hLibModule,L"CardReleaseWindow");
    DAT_c06f913c = GetProcAddressW(hLibModule,L"CardModifyWindow");
    DAT_c06f9140 = GetProcAddressW(hLibModule,L"CardMapWindow");
    DAT_c06f9144 = GetProcAddressW(hLibModule,L"CardGetStatus");
    DAT_c06f9148 = GetProcAddressW(hLibModule,L"CardRequestIRQ");
    DAT_c06f914c = GetProcAddressW(hLibModule,L"CardReleaseIRQ");
    DAT_c06f9150 = GetProcAddressW(hLibModule,L"CardRequestConfiguration");
    DAT_c06f9154 = GetProcAddressW(hLibModule,L"CardReleaseConfiguration");
    DAT_c06f9158 = GetProcAddressW(hLibModule,L"CardAccessConfigurationRegister");
    DAT_c06f915c = GetProcAddressW(hLibModule,L"CardPowerOn");
    DAT_c06f9160 = GetProcAddressW(hLibModule,L"CardPowerOff");
    DAT_c06f9164 = GetProcAddressW(hLibModule,L"CardModifyConfiguration");
    do {
      if (*piVar1 == 0) {
        FreeLibrary(hLibModule);
        return (HMODULE)0x0;
      }
      piVar1 = piVar1 + 1;
    } while ((int)piVar1 < -0x3f906e98);
  }
  return hLibModule;
}



/* c06f446c FUN_c06f446c */

/* Boundary evidence: original MIPS .pdata c06f446c..c06f4757. Semantic name remains unreviewed. */

undefined4
FUN_c06f446c(undefined2 param_1,undefined1 *param_2,undefined4 *param_3,int *param_4,
            undefined4 *param_5,undefined4 param_6,int *param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint local_458;
  undefined1 *local_454;
  undefined4 *local_450;
  int *local_44c;
  undefined4 local_448;
  undefined4 local_444;
  uint local_440 [4];
  undefined1 local_430 [1024];
  uint local_30;
  
  local_30 = DAT_c06f90d8;
  local_444 = param_6;
  local_448 = param_8;
  local_440[3] = 0x3f8;
  local_458 = 0xb;
  local_440[0] = 0x2e8;
  local_440[1] = 1000;
  local_440[2] = 0x2f8;
  local_454 = param_2;
  local_450 = param_3;
  local_44c = param_4;
  iVar1 = (*DAT_c06f9114)(param_1,0x1b,local_430,&local_458);
  if (iVar1 == 0) {
    uVar6 = 0;
    uVar3 = local_458;
    do {
      uVar9 = 0;
      puVar8 = local_440;
      do {
        uVar10 = 0;
        puVar4 = local_430;
        if (uVar3 != 0) {
          do {
            uVar7 = 0;
            if (puVar4[0x50] != '\0') {
              puVar5 = (uint *)(puVar4 + 0x30);
              do {
                if (((uVar6 != 0) ||
                    ((((puVar4[1] & 1) != 0 && (0x1d < *(ushort *)(puVar4 + 2))) &&
                     (*(ushort *)(puVar4 + 2) < 0x22)))) ||
                   ((((puVar4[1] & 2) != 0 && (0x1d < *(ushort *)(puVar4 + 4))) &&
                    (*(ushort *)(puVar4 + 4) < 0x22)))) {
                  if (param_7 != (int *)0x0) {
                    iVar1 = (*DAT_c06f9140)(local_444,puVar5[4],*puVar5 + 1,local_448);
                    *param_7 = iVar1;
                    if (iVar1 == 0) goto LAB_c06f466c;
                  }
                  if ((6 < *puVar5) && (puVar5[4] == *puVar8)) {
                    *local_454 = puVar4[0x51];
                    *local_450 = *(undefined4 *)(puVar4 + (uVar7 + 0x10) * 4);
                    uVar2 = 0x21;
                    *local_44c = *(int *)(puVar4 + (uVar7 + 0xc) * 4) + 1;
                    if (uVar6 != 0) {
                      uVar2 = 0x32;
                    }
                    *param_5 = uVar2;
                    FUN_c06f7da0(local_30);
                    return 1;
                  }
                }
LAB_c06f466c:
                uVar7 = uVar7 + 1;
                puVar5 = puVar5 + 1;
                uVar3 = local_458;
              } while (uVar7 < (byte)puVar4[0x50]);
            }
            uVar10 = uVar10 + 1;
            puVar4 = puVar4 + 0x5c;
          } while (uVar10 < uVar3);
        }
        uVar9 = uVar9 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar9 < 4);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 2);
  }
  FUN_c06f7da0(local_30);
  return 0;
}



/* c06f4758 DetectModem */

/* Boundary evidence: original MIPS .pdata c06f4758..c06f49af. Semantic name remains unreviewed. */

wchar_t * DetectModem(undefined4 param_1,int param_2,wchar_t *param_3)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  HMODULE pHVar4;
  int iVar5;
  int iVar6;
  undefined2 local_res0;
  undefined1 auStack_70 [4];
  int iStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 local_60;
  undefined1 local_5f;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 local_5b;
  char local_50;
  undefined1 local_4f;
  char local_4c;
  uint local_2c;
  
                    /* 0x4758  13  DetectModem */
  local_2c = DAT_c06f90d8;
  if (((param_2 == 2) || (param_2 == 0xff)) && (pHVar4 = FUN_c06f4168(), pHVar4 != (HMODULE)0x0)) {
    local_res0._1_1_ = (undefined1)((uint)param_1 >> 8);
    uVar3 = local_res0._1_1_;
    local_res0._0_1_ = (undefined1)param_1;
    uVar2 = (undefined1)local_res0;
    local_res0 = (undefined2)param_1;
    iVar5 = FUN_c06f446c(local_res0,auStack_70,&uStack_68,&iStack_6c,&uStack_64,0,(int *)0x0,0);
    if (iVar5 == 1) {
      wcscpy(param_3,L"Modem");
      if (param_2 == 2) {
        local_5f = uVar3;
        local_5e = 0;
        bVar1 = false;
        local_60 = uVar2;
        local_5d = 0;
        local_5c = 0xff;
        iVar5 = (*DAT_c06f9108)(&local_60);
        if (iVar5 == 0) {
          iVar5 = 0;
          do {
            if (local_50 == '!') {
              local_50 = ' ';
              local_4f = 0;
              local_5b = 0;
              iVar6 = (*DAT_c06f9110)(&local_60);
              if (iVar6 != 0) break;
              if (local_4c == '\x02') {
                bVar1 = true;
              }
              else if (bVar1) {
                wcscpy(param_3,L"Serial");
                break;
              }
            }
            else if ((bVar1) && (local_50 == '\"')) {
              local_50 = ' ';
              local_4f = 0;
              local_5b = 0;
              iVar6 = (*DAT_c06f9110)(&local_60);
              if ((iVar6 != 0) || (local_4c != '\0')) break;
            }
            iVar6 = (*DAT_c06f910c)(&local_60);
            if (iVar6 == 0x1f) {
              wcscpy(param_3,L"Serial");
            }
            if ((iVar6 != 0) || (iVar5 = iVar5 + 1, 0x7ff < iVar5)) break;
          } while( true );
        }
      }
      FUN_c06f7da0(local_2c);
      return param_3;
    }
  }
  FUN_c06f7da0(local_2c);
  return (wchar_t *)0x0;
}



/* c06f49b0 FUN_c06f49b0 */

/* Boundary evidence: original MIPS .pdata c06f49b0..c06f4a17. Semantic name remains unreviewed. */

undefined4 FUN_c06f49b0(int param_1,undefined4 param_2,int *param_3)

{
  undefined1 local_10;
  undefined1 local_f;
  
  if ((param_3 != (int *)0x0) && (param_1 == 5)) {
    local_f = *(undefined1 *)(*param_3 + 0x1e9);
    local_10 = *(undefined1 *)(*param_3 + 0x1e8);
    (*DAT_c06f9144)(&local_10);
  }
  return 0;
}



/* c06f4a18 FUN_c06f4a18 */

/* Boundary evidence: original MIPS .pdata c06f4a18..c06f4afb. Semantic name remains unreviewed. */

undefined4 FUN_c06f4a18(LPCWSTR param_1,BYTE *param_2)

{
  LSTATUS LVar1;
  BYTE local_18;
  BYTE local_17;
  HKEY local_14;
  DWORD local_10;
  DWORD DStack_c;
  
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_14);
  if (LVar1 == 0) {
    local_10 = 2;
    LVar1 = RegQueryValueExW(local_14,L"Sckt",(LPDWORD)0x0,&DStack_c,&local_18,&local_10);
    if (LVar1 == 0) {
      RegCloseKey(local_14);
      *param_2 = local_18;
      param_2[1] = local_17;
      return 1;
    }
    RegCloseKey(local_14);
  }
  return 0;
}



/* c06f4afc FUN_c06f4afc */

/* Boundary evidence: original MIPS .pdata c06f4afc..c06f4cb3. Semantic name remains unreviewed. */

void FUN_c06f4afc(LPCWSTR param_1,int param_2)

{
  LSTATUS LVar1;
  HKEY local_290;
  DWORD local_28c;
  undefined4 local_288;
  int local_284;
  DWORD aDStack_280 [2];
  WCHAR aWStack_278 [299];
  undefined2 local_22;
  uint local_20;
  
  local_20 = DAT_c06f90d8;
  local_288 = 0;
  local_284 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_290);
  if (LVar1 == 0) {
    local_28c = 600;
    LVar1 = RegQueryValueExW(local_290,L"Key",(LPDWORD)0x0,aDStack_280,(LPBYTE)aWStack_278,
                             &local_28c);
    if (LVar1 == 0) {
      RegCloseKey(local_290);
      local_22 = 0;
      LVar1 = RegOpenKeyExW((HKEY)0x80000002,aWStack_278,0,0,&local_290);
      if (LVar1 != 0) goto LAB_c06f4c70;
      local_28c = 4;
      LVar1 = RegQueryValueExW(local_290,L"ResetDelay",(LPDWORD)0x0,aDStack_280,(LPBYTE)&local_288,
                               &local_28c);
      if (LVar1 != 0) {
        local_288 = 300;
      }
      local_28c = 4;
      RegQueryValueExW(local_290,L"NoScratchPad",(LPDWORD)0x0,aDStack_280,(LPBYTE)&local_284,
                       &local_28c);
    }
    RegCloseKey(local_290);
  }
LAB_c06f4c70:
  if (local_284 != 0) {
    *(undefined4 *)(param_2 + 0x250) = 1;
  }
  *(undefined4 *)(param_2 + 0x24c) = local_288;
  FUN_c06f7da0(local_20);
  return;
}



/* c06f4cb4 FUN_c06f4cb4 */

/* Boundary evidence: original MIPS .pdata c06f4cb4..c06f4f07. Semantic name remains unreviewed. */

undefined4 FUN_c06f4cb4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_68 [8];
  undefined1 local_60;
  undefined1 local_5f;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined4 local_5c;
  undefined1 local_58;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  int local_4c;
  undefined1 local_48 [4];
  undefined4 local_44;
  int aiStack_40 [2];
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  uint local_20;
  
  local_20 = DAT_c06f90d8;
  local_4e = 0xff;
  local_50 = 0x1c;
  local_4d = 0xff;
  local_4f = 0;
  local_4c = param_1;
  iVar1 = (*DAT_c06f9100)(FUN_c06f49b0,&local_50);
  *(int *)(param_1 + 0x1ec) = iVar1;
  if (iVar1 != 0) {
    local_5c = 0x10;
    local_5f = *(undefined1 *)(param_1 + 0x1e9);
    local_58 = 0x80;
    local_5d = 0;
    local_60 = *(undefined1 *)(param_1 + 0x1e8);
    local_5e = 1;
    iVar1 = (*DAT_c06f9134)(iVar1,&local_60);
    uVar2 = *(undefined4 *)(param_1 + 0x1ec);
    *(int *)(param_1 + 0x1f0) = iVar1;
    if (iVar1 != 0) {
      (*DAT_c06f9130)(uVar2,*(undefined2 *)(param_1 + 0x1e8));
      local_48._0_2_ = local_48._1_2_;
      iVar1 = FUN_c06f446c(*(undefined2 *)(param_1 + 0x1e8),local_68,(undefined4 *)local_48,
                           aiStack_40,&local_44,*(undefined4 *)(param_1 + 0x1f0),
                           (int *)(param_1 + 500),param_1 + 0x1f8);
      if (iVar1 != 0) {
        local_37 = *(undefined1 *)(param_1 + 0x1e9);
        local_38 = *(undefined1 *)(param_1 + 0x1e8);
        local_35 = 1;
        local_30 = 0x23;
        local_34 = 2;
        local_2f = local_68[0];
        local_2a = 3;
        local_27 = SUB21(local_48._0_2_,1);
        local_36 = 2;
        local_32 = 0;
        local_31 = 0;
        local_2e = 0x29;
        local_2d = 0;
        local_2c = 0;
        local_2b = 0;
        local_29 = 0;
        local_28 = (undefined1)local_48._0_2_;
        if (*(int *)(param_1 + 500) == 0) {
          (*DAT_c06f9104)();
          goto LAB_c06f4d28;
        }
        iVar1 = (*DAT_c06f9150)(*(undefined4 *)(param_1 + 0x1ec),&local_38);
        if (iVar1 == 0) {
          FUN_c06f7da0(local_20);
          return 1;
        }
      }
      uVar2 = *(undefined4 *)(param_1 + 0x1ec);
    }
    (*DAT_c06f9104)(uVar2);
  }
LAB_c06f4d28:
  FUN_c06f7da0(local_20);
  return 0;
}



/* c06f4f08 FUN_c06f4f08 */

/* Boundary evidence: original MIPS .pdata c06f4f08..c06f5037. Semantic name remains unreviewed. */

HLOCAL FUN_c06f4f08(LPCWSTR param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  HLOCAL hMem;
  HMODULE pHVar2;
  BYTE local_20;
  undefined1 local_1f;
  
  iVar1 = FUN_c06f4a18(param_1,&local_20);
  if ((iVar1 != 0) && (hMem = LocalAlloc(0x40,0x260), hMem != (HLOCAL)0x0)) {
    pHVar2 = FUN_c06f4168();
    if (pHVar2 != (HMODULE)0x0) {
      *(undefined2 *)((int)hMem + 0x204) = 0xffff;
      *(undefined2 *)((int)hMem + 0x206) = 0xffff;
      *(undefined4 *)((int)hMem + 0x208) = 1;
      *(undefined4 *)((int)hMem + 0x21c) = 1;
      *(BYTE *)((int)hMem + 0x1e8) = local_20;
      *(undefined1 *)((int)hMem + 0x1e9) = local_1f;
      *(undefined4 *)((int)hMem + 0x210) = 0x10;
      *(undefined4 *)((int)hMem + 0x214) = 0x10;
      *(undefined4 *)((int)hMem + 0x218) = 0x20000;
      *(undefined4 *)((int)hMem + 0x244) = param_2;
      *(undefined4 *)((int)hMem + 0x25c) = param_3;
      *(undefined1 *)((int)hMem + 0x1fc) = 0;
      *(undefined4 *)((int)hMem + 600) = 0;
      *(undefined4 *)((int)hMem + 0x20c) = 0;
      *(undefined4 *)((int)hMem + 0x220) = 0x1ff;
      *(undefined4 *)((int)hMem + 0x228) = 0x1007fffb;
      *(undefined4 *)((int)hMem + 0x224) = 0x7f;
      *(undefined2 *)((int)hMem + 0x22c) = 0xf;
      *(undefined2 *)((int)hMem + 0x22e) = 0x1f05;
      FUN_c06f4afc(param_1,(int)hMem);
      return hMem;
    }
    LocalFree(hMem);
  }
  return (HLOCAL)0x0;
}



/* c06f5038 FUN_c06f5038 */

/* Boundary evidence: original MIPS .pdata c06f5038..c06f512b. Semantic name remains unreviewed. */

undefined4 FUN_c06f5038(int param_1)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  undefined4 uVar4;
  uint uVar5;
  
  cVar1 = *(char *)(param_1 + 0x1fc);
  uVar4 = 0;
  if (cVar1 == '\0') {
    uVar4 = 0xffffffff;
  }
  else {
    *(char *)(param_1 + 0x1fc) = cVar1 + -1;
    if (cVar1 == '\x01') {
      uVar5 = 0;
      if (*(int *)(param_1 + 600) != 1) {
        bVar3 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 4));
        *(byte *)(param_1 + 0x24) = bVar3;
        while ((((bVar3 & 2) != 0 && (bVar2 = uVar5 < 100, uVar5 = uVar5 + 1, bVar2)) &&
               ((*(byte *)(param_1 + 0x22) & 0x40) == 0))) {
          Sleep(10);
          bVar3 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 4));
          *(byte *)(param_1 + 0x24) = bVar3;
        }
        FUN_c06f599c(param_1);
      }
      FUN_c06f5bc8(param_1);
      (*DAT_c06f9104)(*(undefined4 *)(param_1 + 0x1ec));
    }
  }
  return uVar4;
}



/* c06f512c FUN_c06f512c */

/* Boundary evidence: original MIPS .pdata c06f512c..c06f5153. Semantic name remains unreviewed. */

void FUN_c06f512c(int param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0x204),0x40);
  return;
}



/* c06f5174 FUN_c06f5174 */

/* Boundary evidence: original MIPS .pdata c06f5174..c06f51cb. Semantic name remains unreviewed. */

undefined4 FUN_c06f5174(HLOCAL param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (HLOCAL)0x0) {
    uVar1 = 0;
  }
  else {
    if (*(char *)((int)param_1 + 0x1fc) != '\0') {
      FUN_c06f5038((int)param_1);
    }
    LocalFree(*(HLOCAL *)((int)param_1 + 0x25c));
    LocalFree(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* c06f51cc FUN_c06f51cc */

/* Boundary evidence: original MIPS .pdata c06f51cc..c06f5313. Semantic name remains unreviewed. */

undefined4 FUN_c06f51cc(int *param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_c06f4cb4((int)param_1);
  if (iVar1 == 0) {
LAB_c06f51f4:
    uVar4 = 0;
  }
  else {
    Sleep(param_1[0x93]);
    FUN_c06f5a64(param_1,param_1[0x7d],(uint)*(byte *)(param_1 + 0x7e),-0x3f90d7a4,param_1[0x91],0);
    if ((param_1[0x94] == 0) || (param_1[7] = (int)(param_1 + 0x95), param_1[0x94] == 0)) {
      WRITE_PORT_UCHAR(param_1[7],0xc6);
      WRITE_PORT_UCHAR(param_1[1],0);
      iVar1 = READ_PORT_UCHAR(param_1[7]);
      if (iVar1 != 0xc6) {
        (*DAT_c06f9104)(param_1[0x7b]);
        goto LAB_c06f51f4;
      }
    }
    pcVar3 = FUN_c06f33b8;
    uVar4 = 1;
    param_1[0x2e] = 1;
    iVar1 = param_1[0x91];
    uVar2 = (uint)*(ushort *)(param_1 + 0x7a);
    (*DAT_c06f9148)(param_1[0x7b]);
    FUN_c06f5ba8((int)param_1,uVar2,pcVar3,iVar1);
    FUN_c06f7894(param_1,uVar2,pcVar3,iVar1);
    param_1[0x92] = 0;
    if ((char)param_1[0x7f] == '\0') {
      param_1[0x96] = 0;
    }
    *(char *)(param_1 + 0x7f) = (char)param_1[0x7f] + '\x01';
  }
  return uVar4;
}



/* c06f5314 FUN_c06f5314 */

/* Boundary evidence: original MIPS .pdata c06f5314..c06f5357. Semantic name remains unreviewed. */

undefined4 * FUN_c06f5314(void)

{
  undefined4 *puVar1;
  
  puVar1 = LocalAlloc(0x40,0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = &PTR_FUN_c06f1078;
  }
  return puVar1;
}



/* c06f5358 FUN_c06f5358 */

/* Boundary evidence: original MIPS .pdata c06f5358..c06f53ff. Semantic name remains unreviewed. */

void FUN_c06f5358(int param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(param_1 + 0x22);
  uVar2 = 0;
  if ((bVar1 & 0xe) != 0) {
    if ((bVar1 & 2) != 0) {
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
      *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 2;
    }
    if ((bVar1 & 4) != 0) {
      *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 4;
    }
    if ((bVar1 & 8) != 0) {
      *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 8;
    }
    uVar2 = 0x80;
  }
  if ((bVar1 & 0x10) != 0) {
    uVar2 = uVar2 | 0x40;
  }
  if (uVar2 != 0) {
    (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c));
  }
  return;
}



/* c06f5400 FUN_c06f5400 */

/* Boundary evidence: original MIPS .pdata c06f5400..c06f5467. Semantic name remains unreviewed. */

void FUN_c06f5400(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0x14));
  *(undefined1 *)(param_1 + 0x22) = uVar1;
  FUN_c06f5358(param_1);
  return;
}



/* c06f5468 FUN_c06f5468 */

/* Boundary evidence: original MIPS .pdata c06f5468..c06f548f. Semantic name remains unreviewed. */

bool FUN_c06f5468(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f5490 FUN_c06f5490 */

/* Boundary evidence: original MIPS .pdata c06f5490..c06f5503. Semantic name remains unreviewed. */

void FUN_c06f5490(int param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(param_1 + 0x23);
  uVar2 = 0;
  if ((bVar1 & 1) != 0) {
    uVar2 = 8;
  }
  if ((bVar1 & 2) != 0) {
    uVar2 = uVar2 | 0x10;
  }
  if ((bVar1 & 4) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((bVar1 & 8) != 0) {
    uVar2 = uVar2 | 0x20;
  }
  if (uVar2 != 0) {
    (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c));
  }
  return;
}



/* c06f5504 FUN_c06f5504 */

/* Boundary evidence: original MIPS .pdata c06f5504..c06f556f. Semantic name remains unreviewed. */

void FUN_c06f5504(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0x18));
  *(undefined1 *)(param_1 + 0x23) = uVar1;
  FUN_c06f5490(param_1);
  return;
}



/* c06f5570 FUN_c06f5570 */

/* Boundary evidence: original MIPS .pdata c06f5570..c06f5597. Semantic name remains unreviewed. */

bool FUN_c06f5570(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f5598 FUN_c06f5598 */

int FUN_c06f5598(int param_1,uint *param_2,undefined4 *param_3)

{
  int *piVar1;
  uint uVar2;
  
  *param_3 = 0;
  uVar2 = 0;
  if (*param_2 != 0) {
    piVar1 = (int *)param_2[1];
    do {
      if (param_1 == *piVar1) {
        return ((int *)param_2[1])[uVar2 * 2 + 1];
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 2;
    } while (uVar2 < *param_2);
  }
  *param_3 = 0xffffffff;
  return 0;
}



/* c06f55f4 FUN_c06f55f4 */

/* Boundary evidence: original MIPS .pdata c06f55f4..c06f56b3. Semantic name remains unreviewed. */

void FUN_c06f55f4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 8));
  *(undefined1 *)(param_1 + 0x21) = uVar1;
  while ((*(byte *)(param_1 + 0x21) & 1) == 0) {
    FUN_c06f5400(param_1);
    WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 8),*(byte *)(param_1 + 0x20) | 2);
    FUN_c06f5504(param_1);
    uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 8));
    *(undefined1 *)(param_1 + 0x21) = uVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f56b4 FUN_c06f56b4 */

/* Boundary evidence: original MIPS .pdata c06f56b4..c06f56db. Semantic name remains unreviewed. */

bool FUN_c06f56b4(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f56dc FUN_c06f56dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c06f56dc..c06f594b. Semantic name remains unreviewed. */

undefined4 FUN_c06f56dc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 local_30 [2];
  
  piVar6 = (int *)(param_1 + 0x1d0);
  *piVar6 = 0;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  iVar1 = _DAT_00005b04;
  if (((*(int *)(param_1 + 0xc4) == -1) || (*(short *)(param_1 + 0xd0) == 0)) ||
     (*(short *)(param_1 + 0x150) == 0)) {
    uVar7 = 1;
  }
  else {
    local_30[0] = 0;
    KernelLibIoControl(1,0,piVar6,1,local_30,1,0);
    if ((undefined4 *)*piVar6 != (undefined4 *)0x0) {
      *(undefined4 *)*piVar6 = local_30[0];
      *(int *)(*piVar6 + 4) = iVar1;
      *(undefined4 *)(*piVar6 + 0xc) = 0;
      *(undefined4 *)(*piVar6 + 0x18) = 8;
      *(undefined4 *)(*piVar6 + 0x24) = 0x2c;
      uVar5 = (uint)((iVar1 + -0x2c) * 2) / 3 & 0xfffffffc;
      *(uint *)(*piVar6 + 0x28) = uVar5 + 0x2c;
      puVar3 = (uint *)(*(int *)(*piVar6 + 0x24) + *piVar6);
      *(uint **)(param_1 + 0x1d8) = puVar3;
      *puVar3 = uVar5 - 0x14 >> 1;
      (*(uint **)(param_1 + 0x1d8))[1] = **(uint **)(param_1 + 0x1d8) >> 1;
      *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 0xc) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 8) = 0;
      iVar2 = *piVar6;
      piVar4 = (int *)(*(int *)(iVar2 + 0x28) + iVar2);
      *(int **)(param_1 + 0x1d4) = piVar4;
      *piVar4 = (iVar1 - *(int *)(iVar2 + 0x28)) + -0x14;
      (*(uint **)(param_1 + 0x1d4))[1] = **(uint **)(param_1 + 0x1d4) >> 1;
      *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0xc) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 8) = 0;
      *(undefined4 *)(*piVar6 + 8) = *(undefined4 *)(param_1 + 200);
      *(undefined4 *)(*piVar6 + 0x10) = param_2;
      *(undefined4 *)(*piVar6 + 0x14) = 0;
      *(undefined4 *)(*piVar6 + 0x1c) = param_3;
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      *(undefined4 *)(*piVar6 + 0x20) = 0;
      iVar2 = LoadIntChainHandler((short *)(param_1 + 0xd0),(short *)(param_1 + 0x150),
                                  *(undefined1 *)(param_1 + 0xc4));
      *(int *)(param_1 + 0x1dc) = iVar2;
      if (iVar2 != 0) {
        iVar1 = KernelLibIoControl(iVar2,0x100,local_30[0],iVar1,0,0,0);
        if (iVar1 != 0) {
          return 1;
        }
        KernelLibIoControl(*(undefined4 *)(param_1 + 0x1dc),0x101,piVar6,0x2c,0,0,0);
      }
      FreePhysMem(*piVar6);
      *piVar6 = 0;
    }
    uVar7 = 0;
  }
  return uVar7;
}



/* c06f594c FUN_c06f594c */

/* Boundary evidence: original MIPS .pdata c06f594c..c06f599b. Semantic name remains unreviewed. */

undefined4 FUN_c06f594c(int param_1)

{
  if (*(int *)(param_1 + 0x1dc) != 0) {
    FreeIntChainHandler();
  }
  if (*(int *)(param_1 + 0x1d0) != 0) {
    FreePhysMem();
    *(undefined4 *)(param_1 + 0x1d0) = 0;
  }
  return 1;
}



/* c06f599c FUN_c06f599c */

/* Boundary evidence: original MIPS .pdata c06f599c..c06f5a3b. Semantic name remains unreviewed. */

void FUN_c06f599c(int param_1)

{
  undefined1 uVar1;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + -1;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 4),0);
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0x10),0);
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 8));
  *(undefined1 *)(param_1 + 0x21) = uVar1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f5a3c FUN_c06f5a3c */

/* Boundary evidence: original MIPS .pdata c06f5a3c..c06f5a63. Semantic name remains unreviewed. */

bool FUN_c06f5a3c(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f5a64 FUN_c06f5a64 */

/* Boundary evidence: original MIPS .pdata c06f5a64..c06f5ba7. Semantic name remains unreviewed. */

void FUN_c06f5a64(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  HANDLE pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  *param_1 = param_2;
  param_1[1] = param_3 + param_2;
  param_1[2] = param_3 * 2 + param_2;
  param_1[10] = param_4;
  param_1[3] = param_3 * 3 + param_2;
  param_1[4] = param_3 * 4 + param_2;
  param_1[5] = param_3 * 5 + param_2;
  param_1[6] = param_3 * 6 + param_2;
  param_1[0xb] = param_5;
  param_1[7] = param_3 * 7 + param_2;
  if (param_6 == 0) {
    param_1[0x19] = (int)&DAT_c06f1618;
  }
  else {
    param_1[0x19] = param_6;
  }
  uVar3 = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[0x1b] = (int)pvVar1;
  param_1[0x18] = 0;
  WRITE_PORT_UCHAR(param_1[1],0);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x29));
  iVar2 = param_1[0x33];
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  FUN_c06f56dc((int)param_1,iVar2,param_3);
  FUN_c06f55f4((int)param_1,iVar2,param_3,uVar3);
  return;
}



/* c06f5ba8 FUN_c06f5ba8 */

/* Boundary evidence: original MIPS .pdata c06f5ba8..c06f5bc7. Semantic name remains unreviewed. */

undefined4 FUN_c06f5ba8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c06f55f4(param_1,param_2,param_3,param_4);
  return 1;
}



/* c06f5bc8 FUN_c06f5bc8 */

/* Boundary evidence: original MIPS .pdata c06f5bc8..c06f5c1b. Semantic name remains unreviewed. */

void FUN_c06f5bc8(int param_1)

{
  FUN_c06f594c(param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x90));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  if (*(HANDLE *)(param_1 + 0x6c) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x6c));
  }
  return;
}



/* c06f5c1c FUN_c06f5c1c */

/* Boundary evidence: original MIPS .pdata c06f5c1c..c06f5c93. Semantic name remains unreviewed. */

void FUN_c06f5c1c(int param_1)

{
  uint uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0x10));
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0x10),uVar1 & 0xfe);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f5c94 FUN_c06f5c94 */

/* Boundary evidence: original MIPS .pdata c06f5c94..c06f5cbb. Semantic name remains unreviewed. */

bool FUN_c06f5c94(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f5cbc FUN_c06f5cbc */

/* Boundary evidence: original MIPS .pdata c06f5cbc..c06f5d33. Semantic name remains unreviewed. */

void FUN_c06f5cbc(int param_1)

{
  uint uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0x10));
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0x10),uVar1 | 1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f5d34 FUN_c06f5d34 */

/* Boundary evidence: original MIPS .pdata c06f5d34..c06f5d5b. Semantic name remains unreviewed. */

bool FUN_c06f5d34(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f5d5c FUN_c06f5d5c */

/* Boundary evidence: original MIPS .pdata c06f5d5c..c06f5dd3. Semantic name remains unreviewed. */

void FUN_c06f5d5c(int param_1)

{
  uint uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0x10));
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0x10),uVar1 & 0xfd);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f5dd4 FUN_c06f5dd4 */

/* Boundary evidence: original MIPS .pdata c06f5dd4..c06f5dfb. Semantic name remains unreviewed. */

bool FUN_c06f5dd4(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f5dfc FUN_c06f5dfc */

/* Boundary evidence: original MIPS .pdata c06f5dfc..c06f5e73. Semantic name remains unreviewed. */

void FUN_c06f5dfc(int param_1)

{
  uint uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0x10));
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0x10),uVar1 | 2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f5e74 FUN_c06f5e74 */

/* Boundary evidence: original MIPS .pdata c06f5e74..c06f5e9b. Semantic name remains unreviewed. */

bool FUN_c06f5e74(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f5e9c FUN_c06f5e9c */

/* Boundary evidence: original MIPS .pdata c06f5e9c..c06f5f13. Semantic name remains unreviewed. */

void FUN_c06f5e9c(int param_1)

{
  uint uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc));
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc),uVar1 & 0xbf);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f5f14 FUN_c06f5f14 */

/* Boundary evidence: original MIPS .pdata c06f5f14..c06f5f3b. Semantic name remains unreviewed. */

bool FUN_c06f5f14(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f5f3c FUN_c06f5f3c */

/* Boundary evidence: original MIPS .pdata c06f5f3c..c06f5fb3. Semantic name remains unreviewed. */

void FUN_c06f5f3c(int param_1)

{
  uint uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc));
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc),uVar1 | 0x40);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f5fb4 FUN_c06f5fb4 */

/* Boundary evidence: original MIPS .pdata c06f5fb4..c06f5fdb. Semantic name remains unreviewed. */

bool FUN_c06f5fb4(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f5fdc FUN_c06f5fdc */

/* Boundary evidence: original MIPS .pdata c06f5fdc..c06f60b7. Semantic name remains unreviewed. */

bool FUN_c06f5fdc(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int local_20 [2];
  
  local_20[0] = 0;
  uVar1 = FUN_c06f5598(param_2,(uint *)param_1[0x19],local_20);
  uVar1 = uVar1 & 0xffff;
  if (local_20[0] != 0) {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
    InterruptMask(param_1[0x32],1);
    uVar2 = READ_PORT_UCHAR(param_1[3]);
    WRITE_PORT_UCHAR(param_1[3],uVar2 | 0x80);
    WRITE_PORT_UCHAR(*param_1,uVar1 & 0xff);
    WRITE_PORT_UCHAR(param_1[1],uVar1 >> 8);
    WRITE_PORT_UCHAR(param_1[3],uVar2);
    InterruptMask(param_1[0x32],0);
  }
  return uVar1 != 0;
}



/* c06f60b8 FUN_c06f60b8 */

/* Boundary evidence: original MIPS .pdata c06f60b8..c06f618f. Semantic name remains unreviewed. */

bool FUN_c06f60b8(undefined4 *param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x29));
  bVar1 = FUN_c06f5fdc(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x29));
  bVar1 = CONCAT31(extraout_var,bVar1) != 0;
  if (bVar1) {
    param_1[0xd] = param_2;
  }
  return bVar1;
}



/* c06f6190 FUN_c06f6190 */

/* Boundary evidence: original MIPS .pdata c06f6190..c06f61b7. Semantic name remains unreviewed. */

bool FUN_c06f6190(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f61b8 FUN_c06f61b8 */

/* Boundary evidence: original MIPS .pdata c06f61b8..c06f62bb. Semantic name remains unreviewed. */

undefined4 FUN_c06f61b8(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc));
  uVar1 = uVar1 & 0xfc;
  if (param_2 != 5) {
    if (param_2 == 6) {
      uVar1 = uVar1 | 1;
    }
    else if (param_2 == 7) {
      uVar1 = uVar1 | 2;
    }
    else {
      if (param_2 != 8) {
        uVar2 = 0;
        goto LAB_c06f6268;
      }
      uVar1 = uVar1 | 3;
    }
  }
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc),uVar1);
LAB_c06f6268:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return uVar2;
}



/* c06f62bc FUN_c06f62bc */

/* Boundary evidence: original MIPS .pdata c06f62bc..c06f62e3. Semantic name remains unreviewed. */

bool FUN_c06f62bc(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f62e4 FUN_c06f62e4 */

/* Boundary evidence: original MIPS .pdata c06f62e4..c06f63f7. Semantic name remains unreviewed. */

undefined4 FUN_c06f62e4(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc));
  uVar1 = uVar1 & 199;
  if (param_2 != 0) {
    if (param_2 == 1) {
      uVar1 = uVar1 | 8;
    }
    else if (param_2 == 2) {
      uVar1 = uVar1 | 0x18;
    }
    else if (param_2 == 3) {
      uVar1 = uVar1 | 0x28;
    }
    else {
      if (param_2 != 4) {
        uVar2 = 0;
        goto LAB_c06f63a4;
      }
      uVar1 = uVar1 | 0x38;
    }
  }
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc),uVar1);
LAB_c06f63a4:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return uVar2;
}



/* c06f63f8 FUN_c06f63f8 */

/* Boundary evidence: original MIPS .pdata c06f63f8..c06f641f. Semantic name remains unreviewed. */

bool FUN_c06f63f8(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f6420 FUN_c06f6420 */

/* Boundary evidence: original MIPS .pdata c06f6420..c06f64f7. Semantic name remains unreviewed. */

undefined4 FUN_c06f6420(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  uVar1 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc));
  uVar1 = uVar1 & 0xfb;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) {
      uVar2 = 0;
      goto LAB_c06f64a4;
    }
    uVar1 = uVar1 | 4;
  }
  WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 0xc),uVar1);
LAB_c06f64a4:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return uVar2;
}



/* c06f64f8 FUN_c06f64f8 */

/* Boundary evidence: original MIPS .pdata c06f64f8..c06f651f. Semantic name remains unreviewed. */

bool FUN_c06f64f8(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f6520 FUN_c06f6520 */

/* Boundary evidence: original MIPS .pdata c06f6520..c06f68a3. Semantic name remains unreviewed. */

uint FUN_c06f6520(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  
  uVar10 = 0;
  do {
    bVar2 = false;
    if (*(int *)(param_1 + 0xc0) != 0) {
      *(undefined4 *)(param_1 + 0xc0) = 0;
      (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),0x2000);
    }
    if (*(int *)(param_1 + 0x1d0) == 0) {
      uVar3 = READ_PORT_UCHAR(*(undefined4 *)(param_1 + 8));
      *(undefined1 *)(param_1 + 0x21) = uVar3;
    }
    else {
      piVar7 = *(int **)(param_1 + 0x1d8);
      if (piVar7 != (int *)0x0) {
        uVar5 = piVar7[2];
        uVar6 = piVar7[3];
        if (uVar5 < uVar6) {
          iVar9 = (uVar5 - uVar6) + *piVar7;
        }
        else {
          iVar9 = uVar5 - uVar6;
        }
        if (iVar9 != 0) {
          *(undefined1 *)(param_1 + 0x21) = *(undefined1 *)((piVar7[3] + 8) * 2 + (int)piVar7);
          goto LAB_c06f663c;
        }
      }
      *(undefined1 *)(param_1 + 0x21) = 1;
    }
LAB_c06f663c:
    bVar1 = *(byte *)(param_1 + 0x21);
    if ((bVar1 & 1) == 0) {
      bVar4 = bVar1 & 0xf;
      if ((bVar1 & 0xf) == 0) {
        if (*(int *)(param_1 + 0x1d0) == 0) {
          uVar10 = 8;
        }
        else {
          puVar8 = *(uint **)(param_1 + 0x1d8);
          *(undefined1 *)(param_1 + 0x23) = *(undefined1 *)((int)puVar8 + puVar8[3] * 2 + 0x11);
          uVar5 = puVar8[3] + 1;
          if (*puVar8 <= uVar5) {
            uVar5 = 0;
          }
          puVar8[3] = uVar5;
          FUN_c06f5490(param_1);
LAB_c06f67d4:
          bVar2 = true;
        }
      }
      else if (bVar4 == 2) {
        uVar10 = 4;
        if (*(int *)(param_1 + 0x1d0) != 0) {
          puVar8 = *(uint **)(param_1 + 0x1d8);
          uVar5 = puVar8[3] + 1;
          if (*puVar8 <= uVar5) {
            uVar5 = 0;
          }
          puVar8[3] = uVar5;
        }
      }
      else {
        if (bVar4 != 4) {
          if (bVar4 == 6) {
            if (*(int *)(param_1 + 0x1d0) != 0) {
              puVar8 = *(uint **)(param_1 + 0x1d8);
              *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)((int)puVar8 + puVar8[3] * 2 + 0x11);
              uVar5 = puVar8[3] + 1;
              if (*puVar8 <= uVar5) {
                uVar5 = 0;
              }
              puVar8[3] = uVar5;
              FUN_c06f5358(param_1);
              goto LAB_c06f67d4;
            }
            uVar10 = uVar10 | 1;
            goto LAB_c06f67e8;
          }
          if ((bVar4 != 0xc) && (bVar4 != 0xe)) {
            if (*(int *)(param_1 + 0x1d0) != 0) {
              puVar8 = *(uint **)(param_1 + 0x1d8);
              uVar10 = puVar8[3] + 1;
              if (*puVar8 <= uVar10) {
                uVar10 = 0;
              }
              puVar8[3] = uVar10;
            }
            goto LAB_c06f6650;
          }
        }
        uVar10 = 2;
      }
    }
    else {
LAB_c06f6650:
      uVar10 = 0;
    }
LAB_c06f67e8:
    if ((*(int *)(param_1 + 0x1d0) != 0) &&
       (piVar7 = *(int **)(param_1 + 0x1d8), piVar7 != (int *)0x0)) {
      uVar5 = piVar7[2];
      uVar6 = piVar7[3];
      if (uVar5 < uVar6) {
        iVar9 = (uVar5 - uVar6) + *piVar7;
      }
      else {
        iVar9 = uVar5 - uVar6;
      }
      if (iVar9 != 0) {
        uVar10 = uVar10 | 2;
      }
    }
    if (*(int *)(param_1 + 0x78) != 0) {
      uVar10 = uVar10 | 4;
      *(undefined4 *)(param_1 + 0x78) = 0;
    }
    if ((!bVar2) || (uVar10 != 0)) {
      return uVar10;
    }
  } while( true );
}



/* c06f68a4 FUN_c06f68a4 */

/* Boundary evidence: original MIPS .pdata c06f68a4..c06f68cb. Semantic name remains unreviewed. */

bool FUN_c06f68a4(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f68cc FUN_c06f68cc */

/* Boundary evidence: original MIPS .pdata c06f68cc..c06f6b53. Semantic name remains unreviewed. */

undefined4 FUN_c06f68cc(undefined4 *param_1,undefined1 *param_2,int *param_3)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte bVar9;
  uint *puVar10;
  int iVar11;
  
  iVar11 = *param_3;
  bVar3 = false;
  bVar2 = false;
  *param_3 = 0;
  bVar1 = *(byte *)((int)param_1 + 0x49);
  uVar6 = param_1[0xe];
  if (((uVar6 & 0x400) != 0) && ((uVar6 & 2) != 0)) {
    bVar2 = true;
  }
  while (iVar11 != 0) {
    if ((param_1[0x74] == 0) || (puVar10 = (uint *)param_1[0x76], puVar10 == (uint *)0x0)) {
      FUN_c06f5400((int)param_1);
      if ((*(byte *)((int)param_1 + 0x22) & 1) == 0) break;
      uVar5 = READ_PORT_UCHAR(*param_1);
    }
    else {
      uVar5 = puVar10[2];
      uVar7 = puVar10[3];
      if (uVar5 < uVar7) {
        iVar8 = (uVar5 - uVar7) + *puVar10;
      }
      else {
        iVar8 = uVar5 - uVar7;
      }
      if ((iVar8 == 0) ||
         (((bVar9 = *(byte *)((puVar10[3] + 8) * 2 + (int)puVar10) & 0xf, bVar9 != 0xc &&
           (bVar9 != 0xe)) && (bVar9 != 4)))) break;
      uVar5 = (uint)*(byte *)((int)puVar10 + puVar10[3] * 2 + 0x11);
      uVar7 = puVar10[3] + 1;
      if (*puVar10 <= uVar7) {
        uVar7 = 0;
      }
      puVar10[3] = uVar7;
    }
    if ((((param_1[0xe] & 0x40) == 0) || ((*(byte *)((int)param_1 + 0x23) & 0x20) != 0)) &&
       ((uVar5 != 0 || ((uVar6 >> 0xb & 1) == 0)))) {
      if ((bVar2) && ((*(byte *)((int)param_1 + 0x22) & 4) != 0)) {
        uVar5 = (uint)*(byte *)((int)param_1 + 0x47);
      }
      else if (uVar5 == bVar1) {
        bVar3 = true;
      }
      *param_2 = (char)uVar5;
      param_2 = param_2 + 1;
      *param_3 = *param_3 + 1;
      iVar11 = iVar11 + -1;
    }
  }
  if (bVar3) {
    (*(code *)param_1[10])(param_1[0xb],2);
  }
  uVar4 = param_1[0x1a];
  param_1[0x1a] = 0;
  return uVar4;
}



/* c06f6b54 FUN_c06f6b54 */

/* Boundary evidence: original MIPS .pdata c06f6b54..c06f6b7b. Semantic name remains unreviewed. */

bool FUN_c06f6b54(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f6b7c FUN_c06f6b7c */

/* Boundary evidence: original MIPS .pdata c06f6b7c..c06f708f. Semantic name remains unreviewed. */

void FUN_c06f6b7c(undefined4 *param_1,undefined1 *param_2,int *param_3)

{
  undefined1 uVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar9;
  
  iVar9 = *param_3;
  if (iVar9 == 0) {
    if (((param_1[0x74] != 0) && (iVar9 = param_1[0x75], iVar9 != 0)) &&
       (param_1[0x78] = 0, *(int *)(iVar9 + 8) != *(int *)(iVar9 + 0xc))) {
      do {
        *(undefined4 *)(param_1[0x75] + 8) = *(undefined4 *)(param_1[0x75] + 0xc);
        WRITE_PORT_UCHAR(param_1[2],*(byte *)(param_1 + 8) | 4);
      } while (*(int *)(param_1[0x75] + 8) != *(int *)(param_1[0x75] + 0xc));
    }
    WRITE_PORT_UCHAR(param_1[1],0xd);
    return;
  }
  *param_3 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x29);
  EnterCriticalSection(lpCriticalSection);
  EventModify(param_1[0x1b],1);
  param_1[0x22] = param_1[0x22] & 0xfffffeff;
  if (((param_1[0xe] & 4) == 0) || ((*(byte *)((int)param_1 + 0x23) & 0x10) != 0)) {
    if (((param_1[0xe] & 8) == 0) || ((*(byte *)((int)param_1 + 0x23) & 0x20) != 0)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x29));
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x29));
      if ((param_1[0x74] != 0) && (piVar3 = (int *)param_1[0x75], piVar3 != (int *)0x0)) {
        uVar4 = piVar3[2];
        uVar6 = piVar3[3];
        if (uVar4 < uVar6) {
          iVar7 = (uVar4 - uVar6) + *piVar3;
        }
        else {
          iVar7 = uVar4 - uVar6;
        }
        if (iVar7 != 0) goto LAB_c06f7024;
      }
      FUN_c06f5400((int)param_1);
      if ((*(byte *)((int)param_1 + 0x22) & 0x20) != 0) {
        cVar2 = '\x10';
        if ((*(byte *)((int)param_1 + 0x21) & 0xc0) == 0) {
          cVar2 = '\x01';
        }
        if ((param_1[0x74] == 0) || (param_1[0x75] == 0)) {
          *param_3 = 0;
          for (; (iVar9 != 0 && (cVar2 != '\0')); cVar2 = cVar2 + -1) {
            WRITE_PORT_UCHAR(*param_1,*param_2);
            InterruptDone(param_1[0x32]);
            param_2 = param_2 + 1;
            *param_3 = *param_3 + 1;
            iVar9 = iVar9 + -1;
          }
        }
        else {
          uVar1 = *param_2;
          *param_3 = *param_3 + 1;
          WRITE_PORT_UCHAR(param_1[1],0xd);
          while( true ) {
            param_2 = param_2 + 1;
            iVar9 = iVar9 + -1;
            piVar3 = (int *)param_1[0x75];
            if ((uint)piVar3[1] < 2) {
              uVar4 = piVar3[1];
            }
            else {
              uVar4 = 2;
            }
            uVar6 = piVar3[2];
            uVar5 = piVar3[3];
            if (uVar6 < uVar5) {
              uVar5 = uVar5 - uVar6;
            }
            else {
              uVar5 = (uVar5 - uVar6) + *piVar3;
            }
            if ((uVar5 <= uVar4) || (iVar9 == 0)) break;
            *(undefined1 *)((int)piVar3 + piVar3[2] + 0x10) = *param_2;
            puVar8 = (uint *)param_1[0x75];
            uVar4 = puVar8[2] + 1;
            if (*puVar8 <= uVar4) {
              uVar4 = 0;
            }
            puVar8[2] = uVar4;
            *param_3 = *param_3 + 1;
          }
          WRITE_PORT_UCHAR(*param_1,uVar1);
          WRITE_PORT_UCHAR(param_1[1],0xf);
          param_1[0x78] = (uint)(iVar9 != 0);
        }
      }
LAB_c06f7024:
      WRITE_PORT_UCHAR(param_1[1],0xf);
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x29));
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
      return;
    }
    param_1[0x1d] = 1;
    if ((param_1[0x74] != 0) && (piVar3 = (int *)param_1[0x75], piVar3 != (int *)0x0)) {
      uVar4 = piVar3[2];
      uVar6 = piVar3[3];
      if (uVar4 < uVar6) {
        iVar9 = (uVar4 - uVar6) + *piVar3;
      }
      else {
        iVar9 = uVar4 - uVar6;
      }
      if (iVar9 != 0) goto LAB_c06f6dac;
    }
    WRITE_PORT_UCHAR(param_1[1],0xd);
LAB_c06f6dac:
    LeaveCriticalSection(lpCriticalSection);
    return;
  }
  param_1[0x1c] = 1;
  if ((param_1[0x74] != 0) && (piVar3 = (int *)param_1[0x75], piVar3 != (int *)0x0)) {
    uVar4 = piVar3[2];
    uVar6 = piVar3[3];
    if (uVar4 < uVar6) {
      iVar9 = (uVar4 - uVar6) + *piVar3;
    }
    else {
      iVar9 = uVar4 - uVar6;
    }
    if (iVar9 != 0) goto LAB_c06f6d1c;
  }
  uVar4 = READ_PORT_UCHAR(param_1[1]);
  WRITE_PORT_UCHAR(param_1[1],uVar4 & 0xfd);
LAB_c06f6d1c:
  LeaveCriticalSection(lpCriticalSection);
  return;
}



/* c06f7090 FUN_c06f7090 */

/* Boundary evidence: original MIPS .pdata c06f7090..c06f70b7. Semantic name remains unreviewed. */

bool FUN_c06f7090(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f70b8 FUN_c06f70b8 */

/* Boundary evidence: original MIPS .pdata c06f70b8..c06f70df. Semantic name remains unreviewed. */

bool FUN_c06f70b8(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f70e0 FUN_c06f70e0 */

/* Boundary evidence: original MIPS .pdata c06f70e0..c06f7167. Semantic name remains unreviewed. */

void FUN_c06f70e0(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_c06f5400((int)param_1);
  WRITE_PORT_UCHAR(param_1[2],*(byte *)(param_1 + 8) | 2);
  while (uVar1 = READ_PORT_UCHAR(param_1[5]), (uVar1 & 1) != 0) {
    READ_PORT_UCHAR(*param_1);
  }
  return;
}



/* c06f7168 FUN_c06f7168 */

/* Boundary evidence: original MIPS .pdata c06f7168..c06f718f. Semantic name remains unreviewed. */

bool FUN_c06f7168(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f7190 FUN_c06f7190 */

/* Boundary evidence: original MIPS .pdata c06f7190..c06f7277. Semantic name remains unreviewed. */

void FUN_c06f7190(int param_1)

{
  FUN_c06f5504(param_1);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  if ((*(int *)(param_1 + 0x74) != 0) && ((*(byte *)(param_1 + 0x23) & 0x20) != 0)) {
    *(undefined4 *)(param_1 + 0x74) = 0;
    WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 4),0xf);
    *(undefined4 *)(param_1 + 0x78) = 1;
  }
  if ((*(int *)(param_1 + 0x70) != 0) && ((*(byte *)(param_1 + 0x23) & 0x10) != 0)) {
    *(undefined4 *)(param_1 + 0x70) = 0;
    WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 4),0xf);
    *(undefined4 *)(param_1 + 0x78) = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f7278 FUN_c06f7278 */

/* Boundary evidence: original MIPS .pdata c06f7278..c06f729f. Semantic name remains unreviewed. */

bool FUN_c06f7278(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f72a0 FUN_c06f72a0 */

/* Boundary evidence: original MIPS .pdata c06f72a0..c06f72bb. Semantic name remains unreviewed. */

void FUN_c06f72a0(int param_1)

{
  FUN_c06f7190(param_1);
  return;
}



/* c06f72bc FUN_c06f72bc */

/* Boundary evidence: original MIPS .pdata c06f72bc..c06f73a7. Semantic name remains unreviewed. */

undefined4 FUN_c06f72bc(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x88) = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*(int *)(param_1 + 0x70) == 0) {
      *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xfffffffe;
    }
    else {
      *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 1;
    }
    if (*(int *)(param_1 + 0x74) == 0) {
      *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xfffffffd;
    }
    else {
      *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 2;
    }
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    *param_2 = *(undefined4 *)(param_1 + 0x7c);
    param_2[1] = *(undefined4 *)(param_1 + 0x80);
    param_2[2] = *(undefined4 *)(param_1 + 0x84);
  }
  return uVar1;
}



/* c06f73a8 FUN_c06f73a8 */

/* Boundary evidence: original MIPS .pdata c06f73a8..c06f73cf. Semantic name remains unreviewed. */

bool FUN_c06f73a8(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f73d8 FUN_c06f73d8 */

/* Boundary evidence: original MIPS .pdata c06f73d8..c06f7473. Semantic name remains unreviewed. */

void FUN_c06f73d8(int param_1,uint *param_2)

{
  byte bVar1;
  
  FUN_c06f5504(param_1);
  bVar1 = *(byte *)(param_1 + 0x23);
  if ((bVar1 & 0x10) != 0) {
    *param_2 = *param_2 | 0x10;
  }
  if ((bVar1 & 0x20) != 0) {
    *param_2 = *param_2 | 0x20;
  }
  if ((bVar1 & 0x40) != 0) {
    *param_2 = *param_2 | 0x40;
  }
  if ((bVar1 & 0x80) != 0) {
    *param_2 = *param_2 | 0x80;
  }
  return;
}



/* c06f7474 FUN_c06f7474 */

/* Boundary evidence: original MIPS .pdata c06f7474..c06f751b. Semantic name remains unreviewed. */

void FUN_c06f7474(int param_1,uint param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  if ((param_2 & 4) != 0) {
    WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 8),*(byte *)(param_1 + 0x20) | 4);
  }
  if ((param_2 & 8) != 0) {
    WRITE_PORT_UCHAR(*(undefined4 *)(param_1 + 8),*(byte *)(param_1 + 0x20) | 2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa4));
  return;
}



/* c06f751c FUN_c06f751c */

/* Boundary evidence: original MIPS .pdata c06f751c..c06f7543. Semantic name remains unreviewed. */

bool FUN_c06f751c(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f7544 FUN_c06f7544 */

/* Boundary evidence: original MIPS .pdata c06f7544..c06f774b. Semantic name remains unreviewed. */

undefined4 FUN_c06f7544(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x29);
    EnterCriticalSection(lpCriticalSection);
    if ((param_1[0x74] == 0) || (piVar3 = (int *)param_1[0x75], piVar3 == (int *)0x0)) {
LAB_c06f7670:
      FUN_c06f5400((int)param_1);
      if ((*(byte *)((int)param_1 + 0x22) & 0x20) != 0) {
        WRITE_PORT_UCHAR(*param_1,param_2);
        WRITE_PORT_UCHAR(param_1[1],0xf);
        goto LAB_c06f76e8;
      }
    }
    else {
      uVar1 = piVar3[2];
      uVar2 = piVar3[3];
      if (uVar1 < uVar2) {
        iVar4 = (uVar1 - uVar2) + *piVar3;
      }
      else {
        iVar4 = uVar1 - uVar2;
      }
      if (iVar4 == 0) goto LAB_c06f7670;
      uVar1 = piVar3[2];
      uVar2 = piVar3[3];
      if (uVar1 < uVar2) {
        uVar2 = uVar2 - uVar1;
      }
      else {
        uVar2 = (uVar2 - uVar1) + *piVar3;
      }
      if (2 < uVar2) {
        *(char *)(*(int *)(param_1[0x75] + 8) + param_1[0x75] + 0x10) = (char)param_2;
        puVar5 = (uint *)param_1[0x75];
        uVar1 = puVar5[2] + 1;
        if (*puVar5 <= uVar1) {
          uVar1 = 0;
        }
        puVar5[2] = uVar1;
        LeaveCriticalSection(lpCriticalSection);
        WRITE_PORT_UCHAR(param_1[1],0xf);
LAB_c06f76e8:
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x29));
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
        return 1;
      }
    }
    WRITE_PORT_UCHAR(param_1[1],0xf);
    LeaveCriticalSection(lpCriticalSection);
    WaitForSingleObject((HANDLE)param_1[0x1b],1000);
  } while( true );
}



/* c06f774c FUN_c06f774c */

/* Boundary evidence: original MIPS .pdata c06f774c..c06f7773. Semantic name remains unreviewed. */

bool FUN_c06f774c(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f7774 FUN_c06f7774 */

/* Boundary evidence: original MIPS .pdata c06f7774..c06f7863. Semantic name remains unreviewed. */

int FUN_c06f7774(undefined4 *param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  iVar2 = 1;
  if (param_1[0x18] != 0) {
    if (*(int *)((int)param_2 + 4) != param_1[0xd]) {
      bVar1 = FUN_c06f60b8(param_1,*(int *)((int)param_2 + 4));
      iVar2 = CONCAT31(extraout_var,bVar1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if ((uint)*(byte *)((int)param_2 + 0x12) != (uint)*(byte *)((int)param_1 + 0x42)) {
      iVar2 = FUN_c06f61b8((int)param_1,(uint)*(byte *)((int)param_2 + 0x12));
    }
    if (iVar2 == 0) {
      return 0;
    }
    if ((uint)*(byte *)((int)param_2 + 0x13) != (uint)*(byte *)((int)param_1 + 0x43)) {
      iVar2 = FUN_c06f62e4((int)param_1,(uint)*(byte *)((int)param_2 + 0x13));
    }
    if (iVar2 == 0) {
      return 0;
    }
    if ((uint)*(byte *)((int)param_2 + 0x14) != (uint)*(byte *)(param_1 + 0x11)) {
      iVar2 = FUN_c06f6420((int)param_1,(uint)*(byte *)((int)param_2 + 0x14));
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  memcpy(param_1 + 0xc,param_2,0x1c);
  return iVar2;
}



/* c06f7894 FUN_c06f7894 */

/* Boundary evidence: original MIPS .pdata c06f7894..c06f7a4f. Semantic name remains unreviewed. */

void FUN_c06f7894(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1[0x18];
  param_1[0x18] = iVar2 + 1;
  if (iVar2 == 0) {
    if (param_1[0x74] != 0) {
      *(undefined4 *)(param_1[0x74] + 0x18) = 8;
      iVar2 = param_1[0x76];
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
      }
      iVar2 = param_1[0x75];
      while ((iVar2 != 0 && (iVar2 = param_1[0x75], *(int *)(iVar2 + 8) != *(int *)(iVar2 + 0xc))))
      {
        *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0xc);
        iVar2 = param_1[0x75];
      }
    }
    *(undefined1 *)(param_1 + 8) = 0;
    *(undefined1 *)(param_1 + 9) = 0;
    *(undefined1 *)((int)param_1 + 0x21) = 0;
    *(undefined1 *)((int)param_1 + 0x22) = 0;
    *(undefined1 *)((int)param_1 + 0x23) = 0;
    param_1[0x1a] = 0;
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x22] = 0;
    param_1[0x23] = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x29));
    WRITE_PORT_UCHAR(param_1[1],0xd);
    WRITE_PORT_UCHAR(param_1[4],8);
    WRITE_PORT_UCHAR(param_1[3],3);
    FUN_c06f60b8(param_1,param_1[0xd]);
    FUN_c06f61b8((int)param_1,(uint)*(byte *)((int)param_1 + 0x42));
    FUN_c06f6420((int)param_1,(uint)*(byte *)(param_1 + 0x11));
    uVar1 = (uint)*(byte *)((int)param_1 + 0x43);
    FUN_c06f62e4((int)param_1,uVar1);
    if (param_1[0x2e] == 1) {
      *(undefined1 *)(param_1 + 8) = 0x81;
      uVar1 = 0x87;
      WRITE_PORT_UCHAR(param_1[2]);
    }
    FUN_c06f55f4((int)param_1,uVar1,param_3,param_4);
    FUN_c06f5504((int)param_1);
    FUN_c06f5400((int)param_1);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x29));
  }
  return;
}



/* c06f7a50 FUN_c06f7a50 */

/* Boundary evidence: original MIPS .pdata c06f7a50..c06f7a77. Semantic name remains unreviewed. */

bool FUN_c06f7a50(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c06f7c38 entry */

/* Boundary evidence: original MIPS .pdata c06f7c38..c06f7cab. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c06f7cac();
    FUN_c06f7f80();
  }
  uVar1 = FUN_c06f1670(param_1,param_2);
  if (param_2 == 0) {
    FUN_c06f7f08();
  }
  return uVar1;
}



/* c06f7cac FUN_c06f7cac */

/* Boundary evidence: original MIPS .pdata c06f7cac..c06f7d1f. Semantic name remains unreviewed. */

void FUN_c06f7cac(void)

{
  uint uVar1;
  
  if ((DAT_c06f90d8 == 0) || (DAT_c06f90d8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c06f90d8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c06f90d8 == 0) {
      DAT_c06f90d8 = 0xb064;
    }
  }
  DAT_c06f90dc = ~DAT_c06f90d8;
  return;
}



/* c06f7d20 FUN_c06f7d20 */

/* Boundary evidence: original MIPS .pdata c06f7d20..c06f7d73. Semantic name remains unreviewed. */

void FUN_c06f7d20(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c06f7da0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c06f7d74 FUN_c06f7d74 */

/* Boundary evidence: original MIPS .pdata c06f7d74..c06f7d9f. Semantic name remains unreviewed. */

undefined4 FUN_c06f7d74(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c06f7d20(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c06f7da0 FUN_c06f7da0 */

/* Boundary evidence: original MIPS .pdata c06f7da0..c06f7de7. Semantic name remains unreviewed. */

void FUN_c06f7da0(uint param_1)

{
  if ((param_1 == DAT_c06f90d8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c06f7de8 FUN_c06f7de8 */

/* Boundary evidence: original MIPS .pdata c06f7de8..c06f7f07. Semantic name remains unreviewed. */

void FUN_c06f7de8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c06f90e4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c06f916c;
    if (DAT_c06f916c != (undefined4 *)0x0) {
      while (DAT_c06f9168 = DAT_c06f9168 + -1, _Memory <= DAT_c06f9168) {
        if ((code *)*DAT_c06f9168 != (code *)0x0) {
          (*(code *)*DAT_c06f9168)();
          _Memory = DAT_c06f916c;
        }
      }
      free(_Memory);
      DAT_c06f9168 = (undefined4 *)0x0;
      DAT_c06f916c = (undefined4 *)0x0;
    }
    FUN_c06f7f2c((undefined4 *)&DAT_c06f1010,(undefined4 *)&DAT_c06f1014);
  }
  FUN_c06f7f2c((undefined4 *)&DAT_c06f1018,(undefined4 *)&DAT_c06f101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c06f9170,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c06f7f08 FUN_c06f7f08 */

/* Boundary evidence: original MIPS .pdata c06f7f08..c06f7f2b. Semantic name remains unreviewed. */

void FUN_c06f7f08(void)

{
  FUN_c06f7de8(0,0,1);
  return;
}



/* c06f7f2c FUN_c06f7f2c */

/* Boundary evidence: original MIPS .pdata c06f7f2c..c06f7f7f. Semantic name remains unreviewed. */

void FUN_c06f7f2c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c06f7f80 FUN_c06f7f80 */

/* Boundary evidence: original MIPS .pdata c06f7f80..c06f7fbb. Semantic name remains unreviewed. */

void FUN_c06f7f80(void)

{
  FUN_c06f7f2c((undefined4 *)&DAT_c06f1008,(undefined4 *)&DAT_c06f100c);
  FUN_c06f7f2c((undefined4 *)&DAT_c06f1000,(undefined4 *)&DAT_c06f1004);
  return;
}


