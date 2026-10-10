/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c03610c8 FUN_c03610c8 */

/* Boundary evidence: original MIPS .pdata c03610c8..c036113b. Semantic name remains unreviewed. */

int FUN_c03610c8(uint param_1)

{
  int iVar1;
  
  WaitForSingleObject(DAT_c0364094,0xffffffff);
  if ((DAT_c0364088 <= param_1) || (iVar1 = *(int *)(param_1 * 4 + DAT_c03640ac), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c036113c DeleteCache */

/* Boundary evidence: original MIPS .pdata c036113c..c0361203. Semantic name remains unreviewed. */

undefined4 DeleteCache(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  
                    /* 0x113c  5  DeleteCache */
  puVar1 = (undefined4 *)FUN_c03610c8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x57;
  }
  else {
    FUN_c03622c8(puVar1,0,0,0);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0364098);
    pvVar3 = *(void **)(param_1 * 4 + DAT_c03640ac);
    if (pvVar3 != (void *)0x0) {
      FUN_c03617a4((int)pvVar3);
      operator_delete(pvVar3);
    }
    *(undefined4 *)(param_1 * 4 + DAT_c03640ac) = 0;
    DAT_c03640b0 = DAT_c03640b0 + -1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0364098);
    uVar2 = 0;
  }
  return uVar2;
}



/* c0361204 ResizeCache */

/* Boundary evidence: original MIPS .pdata c0361204..c0361253. Semantic name remains unreviewed. */

undefined4 ResizeCache(uint param_1,SIZE_T param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
                    /* 0x1204  8  ResizeCache */
  puVar1 = (undefined4 *)FUN_c03610c8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x57;
  }
  else {
    uVar2 = FUN_c0362afc(puVar1,param_3,param_2);
  }
  return uVar2;
}



/* c0361254 CachedRead */

/* Boundary evidence: original MIPS .pdata c0361254..c03612b7. Semantic name remains unreviewed. */

DWORD CachedRead(uint param_1,uint param_2,uint param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  DWORD DVar2;
  
                    /* 0x1254  2  CachedRead */
  puVar1 = (undefined4 *)FUN_c03610c8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    DVar2 = 0x57;
  }
  else {
    DVar2 = FUN_c0362e04(puVar1,param_5,param_2,param_3,param_4);
  }
  return DVar2;
}



/* c03612b8 CachedWrite */

/* Boundary evidence: original MIPS .pdata c03612b8..c036131b. Semantic name remains unreviewed. */

DWORD CachedWrite(uint param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  undefined4 *puVar1;
  DWORD DVar2;
  
                    /* 0x12b8  3  CachedWrite */
  puVar1 = (undefined4 *)FUN_c03610c8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    DVar2 = 0x57;
  }
  else {
    DVar2 = FUN_c0363064(puVar1,param_5,param_2,param_3,param_4);
  }
  return DVar2;
}



/* c036131c FlushCache */

/* Boundary evidence: original MIPS .pdata c036131c..c036137b. Semantic name remains unreviewed. */

DWORD FlushCache(uint param_1,int param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  DWORD DVar2;
  
                    /* 0x131c  6  FlushCache */
  puVar1 = (undefined4 *)FUN_c03610c8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    DVar2 = 0x57;
  }
  else {
    DVar2 = FUN_c03622c8(puVar1,param_2,param_3,param_4);
  }
  return DVar2;
}



/* c036137c SyncCache */

undefined4 SyncCache(void)

{
                    /* 0x137c  9  SyncCache */
  return 0;
}



/* c0361384 InvalidateCache */

/* Boundary evidence: original MIPS .pdata c0361384..c03613e3. Semantic name remains unreviewed. */

undefined4 InvalidateCache(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x1384  7  InvalidateCache */
  iVar1 = FUN_c03610c8(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x57;
  }
  else {
    uVar2 = FUN_c03624fc(iVar1,param_2,param_3);
  }
  return uVar2;
}



/* c03613e4 CacheIoControl */

/* Boundary evidence: original MIPS .pdata c03613e4..c0361463. Semantic name remains unreviewed. */

undefined4 CacheIoControl(uint param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
                    /* 0x13e4  1  CacheIoControl */
  puVar1 = (undefined4 *)FUN_c03610c8(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x57;
  }
  else {
    uVar2 = FUN_c03632bc(puVar1,param_2,param_3,param_4);
  }
  return uVar2;
}



/* c0361464 FUN_c0361464 */

/* Boundary evidence: original MIPS .pdata c0361464..c03614fb. Semantic name remains unreviewed. */

undefined4 FUN_c0361464(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0364098);
    CloseHandle(DAT_c0364094);
    LocalFree(DAT_c03640ac);
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0364098);
    DAT_c0364094 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  }
  return 1;
}



/* c03614fc CreateCache */

/* Boundary evidence: original MIPS .pdata c03614fc..c0361763. Semantic name remains unreviewed. */

uint CreateCache(undefined4 param_1,int param_2,int param_3,uint param_4,uint param_5,
                undefined4 param_6)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint local_30;
  
  bVar1 = true;
                    /* 0x14fc  4  CreateCache */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0364098);
  if ((DAT_c03640ac != (int *)0x0) ||
     (DAT_c03640ac = LocalAlloc(0x40,DAT_c0364088 << 2), DAT_c03640ac != (int *)0x0)) {
    if (DAT_c03640b0 == DAT_c0364088) {
      EventModify(DAT_c0364094,2);
      piVar2 = LocalReAlloc(DAT_c03640ac,DAT_c0364088 << 3,0x42);
      if (piVar2 == (int *)0x0) {
        EventModify(DAT_c0364094,3);
        goto LAB_c03615c4;
      }
      DAT_c0364088 = DAT_c0364088 << 1;
      DAT_c03640ac = piVar2;
      EventModify(DAT_c0364094,3);
    }
    if (((param_5 - 1 & param_5) == 0) && (param_5 < 0x10001)) {
      uVar4 = (param_3 - param_2) + 1;
      if (uVar4 < param_4) {
        param_4 = uVar4;
      }
      local_30 = 0;
      piVar2 = DAT_c03640ac;
      if (DAT_c0364088 != 0) {
        do {
          if (*piVar2 == 0) {
            puVar5 = operator_new(0x48);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar5 = FUN_c0361764(puVar5,param_1,param_2,param_3,param_4,param_5,param_6);
            }
            DAT_c03640ac[local_30] = (int)puVar5;
            break;
          }
          local_30 = local_30 + 1;
          piVar2 = piVar2 + 1;
        } while (local_30 < DAT_c0364088);
      }
      if (param_4 != 0) {
        puVar5 = (undefined4 *)DAT_c03640ac[local_30];
        if ((puVar5 != (undefined4 *)0x0) && (iVar3 = FUN_c0362878(puVar5), iVar3 == 0)) {
          FUN_c03617a4((int)puVar5);
          operator_delete(puVar5);
          DAT_c03640ac[local_30] = 0;
          goto LAB_c03615c4;
        }
      }
      DAT_c03640b0 = DAT_c03640b0 + 1;
      bVar1 = false;
    }
  }
LAB_c03615c4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0364098);
  if (bVar1) {
    local_30 = 0xffffffff;
  }
  return local_30;
}



/* c0361764 FUN_c0361764 */

undefined4 *
FUN_c0361764(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  param_1[4] = param_6;
  param_1[5] = param_7;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  return param_1;
}



/* c03617a4 FUN_c03617a4 */

/* Boundary evidence: original MIPS .pdata c03617a4..c03618b7. Semantic name remains unreviewed. */

void FUN_c03617a4(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x14) & 2) != 0) {
    SetEventData(*(undefined4 *)(param_1 + 0x40),2);
    EventModify(*(undefined4 *)(param_1 + 0x40),3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x44),20000);
    CloseHandle(*(HANDLE *)(param_1 + 0x44));
    CloseHandle(*(HANDLE *)(param_1 + 0x40));
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  uVar1 = *(int *)(param_1 + 0x10) * *(int *)(param_1 + 0xc) + 0xffffU >> 0x10;
  if (uVar1 != 0) {
    iVar2 = 0;
    do {
      VirtualFree(*(LPVOID *)(iVar2 + *(int *)(param_1 + 0x28)),0,0x8000);
      uVar1 = uVar1 - 1;
      iVar2 = iVar2 + 4;
    } while (uVar1 != 0);
  }
  LocalFree(*(HLOCAL *)(param_1 + 0x28));
  LocalFree(*(HLOCAL *)(param_1 + 0x20));
  LocalFree(*(HLOCAL *)(param_1 + 0x24));
  LeaveCriticalSection(lpCriticalSection);
  DeleteCriticalSection(lpCriticalSection);
  return;
}



/* c03618b8 FUN_c03618b8 */

/* Boundary evidence: original MIPS .pdata c03618b8..c036194b. Semantic name remains unreviewed. */

DWORD FUN_c03618b8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                  undefined4 param_5)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  local_1c = 0x32;
  local_10 = param_1[4] * param_4;
  local_20 = 1;
  local_18 = 0;
  local_14 = param_5;
  local_28 = param_3;
  local_24 = param_4;
  iVar1 = FSDMGR_DiskIoControl(*param_1,param_2,&local_28,0x1c,0,0,0,0);
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 == 0) {
      DVar2 = 0x1f;
    }
  }
  else {
    DVar2 = 0;
  }
  return DVar2;
}



/* c036194c FUN_c036194c */

/* Boundary evidence: original MIPS .pdata c036194c..c03619d7. Semantic name remains unreviewed. */

undefined4 FUN_c036194c(int param_1,int param_2,void *param_3)

{
  uint uVar1;
  
  uVar1 = *(size_t *)(param_1 + 0x10) * param_2;
  memcpy(param_3,(void *)(*(int *)((uVar1 >> 0x10) * 4 + *(int *)(param_1 + 0x28)) +
                         (uVar1 & 0xffff)),*(size_t *)(param_1 + 0x10));
  return 0;
}



/* c03619d8 FUN_c03619d8 */

/* Boundary evidence: original MIPS .pdata c03619d8..c03619e3. Semantic name remains unreviewed. */

undefined4 FUN_c03619d8(void)

{
  return 1;
}



/* c03619e4 FUN_c03619e4 */

/* Boundary evidence: original MIPS .pdata c03619e4..c0361b3f. Semantic name remains unreviewed. */

void FUN_c03619e4(undefined4 *param_1)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar4 = param_1[1];
  uVar7 = 0x10000 / (uint)param_1[4];
  uVar6 = param_1[3] + uVar4;
  if (param_1[4] == 0) {
    trap(0x1c00);
  }
  while (uVar4 < uVar6) {
    if (uVar7 == 0) {
      trap(0x1c00);
    }
    uVar2 = param_1[3];
    iVar5 = uVar7 - uVar4 % uVar7;
    uVar8 = uVar4 % uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    if (uVar2 < uVar8 + iVar5) {
      iVar5 = param_1[3] - uVar8;
    }
    if (uVar6 < iVar5 + uVar4) {
      iVar5 = uVar6 - uVar4;
    }
    DVar1 = FUN_c03618b8(param_1,2,uVar4,iVar5,
                         *(int *)((param_1[4] * uVar8 >> 0x10) * 4 + param_1[10]) +
                         (param_1[4] * uVar8 & 0xffff));
    if (DVar1 == 0) {
      if (uVar8 < uVar8 + iVar5) {
        iVar3 = uVar8 << 2;
        iVar5 = (uVar8 + iVar5) - uVar8;
        do {
          *(uint *)(param_1[8] + iVar3) = uVar4;
          uVar4 = uVar4 + 1;
          iVar5 = iVar5 + -1;
          iVar3 = iVar3 + 4;
        } while (iVar5 != 0);
      }
    }
    else {
      uVar4 = iVar5 + uVar4;
    }
  }
  return;
}



/* c0361b40 FUN_c0361b40 */

/* Boundary evidence: original MIPS .pdata c0361b40..c0361b9f. Semantic name remains unreviewed. */

void FUN_c0361b40(int param_1,int param_2)

{
  byte *pbVar1;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    EventModify(*(undefined4 *)(param_1 + 0x40),3);
  }
  pbVar1 = (byte *)(*(int *)(param_1 + 0x24) + param_2);
  *pbVar1 = *pbVar1 | 1;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return;
}



/* c0361ba0 FUN_c0361ba0 */

/* Boundary evidence: original MIPS .pdata c0361ba0..c0361c07. Semantic name remains unreviewed. */

void FUN_c0361ba0(int param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  
  for (uVar2 = param_2; uVar2 <= param_3; uVar2 = uVar2 + 1) {
    pbVar1 = (byte *)(*(int *)(param_1 + 0x24) + uVar2);
    *pbVar1 = *pbVar1 & 0xfe;
  }
  iVar3 = (*(int *)(param_1 + 0x1c) - param_3) + param_2 + -1;
  *(int *)(param_1 + 0x1c) = iVar3;
  if (iVar3 == 0) {
    EventModify(*(undefined4 *)(param_1 + 0x40),2);
  }
  return;
}



/* c0361c08 FUN_c0361c08 */

/* Boundary evidence: original MIPS .pdata c0361c08..c0361f7f. Semantic name remains unreviewed. */

DWORD FUN_c0361c08(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 *hMem;
  SIZE_T uBytes;
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  DWORD DVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int local_3c;
  
  uVar10 = 0x10000 / (uint)param_1[4];
  if (param_1[4] == 0) {
    trap(0x1c00);
  }
  uVar11 = param_3 / uVar10;
  if (uVar10 == 0) {
    trap(0x1c00);
  }
  uVar12 = param_2 / uVar10;
  if (uVar10 == 0) {
    trap(0x1c00);
  }
  do {
    if (uVar11 < uVar12) {
      return 0;
    }
    uVar7 = uVar11;
    uVar8 = param_3;
    if (uVar12 + 8 <= uVar11) {
      uVar7 = uVar12 + 7;
      uVar8 = (uVar12 + 8) * uVar10 - 1;
    }
    if ((param_1[6] & 4) == 0) {
      uBytes = (uVar7 - uVar12) * 8 + 0x1c;
      hMem = LocalAlloc(0,uBytes);
      if (hMem == (undefined4 *)0x0) {
        return 0xe;
      }
      uVar1 = *(undefined4 *)(param_2 * 4 + param_1[8]);
      hMem[3] = 0x32;
      *hMem = uVar1;
      hMem[1] = (uVar8 - param_2) + 1;
      hMem[2] = (uVar7 - uVar12) + 1;
      hMem[4] = 0;
      if (uVar12 <= uVar7) {
        iVar9 = uVar12 << 2;
        piVar5 = hMem + 6;
        uVar4 = uVar12;
        do {
          if (uVar4 == uVar12) {
            uVar13 = param_2 % uVar10;
            if (uVar10 == 0) {
              trap(0x1c00);
            }
          }
          else {
            uVar13 = 0;
          }
          if (uVar4 == uVar7) {
            if (uVar10 == 0) {
              trap(0x1c00);
            }
            iVar3 = (uVar8 % uVar10 - uVar13) + 1;
          }
          else {
            iVar3 = uVar10 - uVar13;
          }
          piVar2 = (int *)(param_1[10] + iVar9);
          uVar4 = uVar4 + 1;
          iVar9 = iVar9 + 4;
          piVar5[-1] = *piVar2 + uVar13 * param_1[4];
          *piVar5 = iVar3 * param_1[4];
          piVar5 = piVar5 + 2;
        } while (uVar4 <= uVar7);
      }
      iVar9 = FSDMGR_DiskIoControl(*param_1,3,hMem,uBytes,0,0,0,0);
      if (iVar9 == 0) {
        DVar6 = hMem[3];
        SetLastError(DVar6);
        LocalFree(hMem);
        return DVar6;
      }
      LocalFree(hMem);
    }
    else {
      local_3c = 0;
      if (uVar12 <= uVar7) {
        iVar9 = uVar12 << 2;
        uVar4 = uVar12;
        do {
          if (uVar4 == uVar12) {
            uVar13 = param_2 % uVar10;
            if (uVar10 == 0) {
              trap(0x1c00);
            }
          }
          else {
            uVar13 = 0;
          }
          if (uVar4 == uVar7) {
            if (uVar10 == 0) {
              trap(0x1c00);
            }
            iVar3 = (uVar8 % uVar10 - uVar13) + 1;
          }
          else {
            iVar3 = uVar10 - uVar13;
          }
          DVar6 = FUN_c03618b8(param_1,3,*(undefined4 *)((local_3c + param_2) * 4 + param_1[8]),
                               iVar3,*(int *)(param_1[10] + iVar9) + uVar13 * param_1[4]);
          if (DVar6 != 0) {
            SetLastError(DVar6);
            return DVar6;
          }
          local_3c = iVar3 + local_3c;
          uVar4 = uVar4 + 1;
          iVar9 = iVar9 + 4;
        } while (uVar4 <= uVar7);
      }
    }
    FUN_c0361ba0((int)param_1,param_2,uVar8);
    uVar12 = uVar7 + 1;
    param_2 = uVar8 + 1;
  } while( true );
}



/* c0361f80 FUN_c0361f80 */

/* Boundary evidence: original MIPS .pdata c0361f80..c036212b. Semantic name remains unreviewed. */

DWORD FUN_c0361f80(undefined4 *param_1,uint param_2,uint param_3,int param_4)

{
  DWORD DVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  DWORD DVar6;
  uint uVar7;
  
  uVar7 = param_2 % (uint)param_1[3];
  if (param_1[3] == 0) {
    trap(0x1c00);
  }
  DVar6 = 0;
  if ((param_4 == 2) && ((uint)param_1[3] < param_3)) {
    param_4 = 1;
    uVar7 = 0;
    param_3 = param_1[3];
  }
  do {
    while( true ) {
      if (param_3 == 0) {
        return DVar6;
      }
      if (uVar7 == param_1[3]) {
        uVar7 = 0;
      }
      if (((*(byte *)(param_1[9] + uVar7) & 1) != 0) &&
         (((param_4 == 1 || ((param_4 == 2 && (*(uint *)(uVar7 * 4 + param_1[8]) != param_2)))) ||
          ((param_4 == 3 && (*(uint *)(uVar7 * 4 + param_1[8]) == param_2)))))) break;
      param_3 = param_3 - 1;
      uVar7 = uVar7 + 1;
      param_2 = param_2 + 1;
    }
    piVar3 = (int *)(uVar7 * 4 + param_1[8]);
    uVar5 = uVar7;
    do {
      uVar4 = uVar5;
      iVar2 = *piVar3;
      uVar5 = uVar4 + 1;
      piVar3 = piVar3 + 1;
      param_3 = param_3 - 1;
      param_2 = param_2 + 1;
      if (((param_3 == 0) || ((uint)param_1[3] <= uVar5)) ||
         ((*(byte *)(param_1[9] + uVar5) & 1) == 0)) break;
    } while (*piVar3 == iVar2 + 1);
    DVar1 = FUN_c0361c08(param_1,uVar7,uVar4);
    uVar7 = uVar5;
    if (DVar1 != 0) {
      DVar6 = DVar1;
    }
  } while( true );
}



/* c036212c FUN_c036212c */

/* Boundary evidence: original MIPS .pdata c036212c..c0362217. Semantic name remains unreviewed. */

uint FUN_c036212c(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  uVar1 = param_1[3];
  if (param_2 < uVar1) {
    do {
      if ((*(byte *)(param_1[9] + param_2) & 1) != 0) break;
      param_2 = param_2 + 1;
    } while (param_2 < uVar1);
  }
  if (param_2 != uVar1) {
    uVar4 = param_2 + 1;
    if (uVar4 < uVar1) {
      iVar2 = (*(int *)(param_2 * 4 + param_1[8]) - param_2) + uVar4;
      piVar3 = (int *)(uVar4 * 4 + param_1[8]);
      do {
        if (((*(byte *)(param_1[9] + uVar4) & 1) == 0) || (*piVar3 != iVar2)) break;
        uVar4 = uVar4 + 1;
        piVar3 = piVar3 + 1;
        iVar2 = iVar2 + 1;
      } while (uVar4 < uVar1);
    }
    FUN_c0361c08(param_1,param_2,uVar4 - 1);
    if (uVar4 != param_1[3]) {
      return uVar4;
    }
  }
  return 0;
}



/* c0362218 FUN_c0362218 */

/* Boundary evidence: original MIPS .pdata c0362218..c03622c7. Semantic name remains unreviewed. */

void FUN_c0362218(undefined4 *param_1)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  
  uVar3 = 0;
  while ((DVar2 = WaitForSingleObject((HANDLE)param_1[0x10],0xffffffff), DVar2 != 0xffffffff &&
         (iVar1 = GetEventData(param_1[0x10]), iVar1 != 2))) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
    if (param_1[7] != 0) {
      uVar3 = FUN_c036212c(param_1,uVar3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  }
  return;
}



/* c03622c8 FUN_c03622c8 */

/* Boundary evidence: original MIPS .pdata c03622c8..c036246f. Semantic name remains unreviewed. */

DWORD FUN_c03622c8(undefined4 *param_1,int param_2,uint param_3,uint param_4)

{
  DWORD DVar1;
  int iVar2;
  uint *puVar3;
  DWORD DVar4;
  uint uVar5;
  
  DVar4 = 0;
  if ((param_1[7] != 0) && ((param_1[5] & 2) != 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
    if (param_2 == 0) {
      DVar4 = FUN_c0361f80(param_1,0,param_1[3],1);
    }
    else {
      for (uVar5 = 0; uVar5 < param_3; uVar5 = uVar5 + 1) {
        puVar3 = (uint *)(uVar5 * 8 + param_2);
        DVar1 = FUN_c0361f80(param_1,*puVar3,puVar3[1],3);
        if (DVar1 != 0) {
          DVar4 = DVar1;
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  }
  if (((param_1[6] & 2) == 0) && ((param_4 & 1) == 0)) {
    iVar2 = FSDMGR_DiskIoControl(*param_1,0x71c54,0,0,0,0,0,0);
    if (iVar2 == 0) {
      param_1[6] = param_1[6] | 2;
    }
  }
  return DVar4;
}



/* c0362470 FUN_c0362470 */

/* Boundary evidence: original MIPS .pdata c0362470..c036247b. Semantic name remains unreviewed. */

undefined4 FUN_c0362470(void)

{
  return 1;
}



/* c036247c FUN_c036247c */

/* Boundary evidence: original MIPS .pdata c036247c..c03624fb. Semantic name remains unreviewed. */

void FUN_c036247c(int param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = param_2 % *(uint *)(param_1 + 0xc);
  if (*(uint *)(param_1 + 0xc) == 0) {
    trap(0x1c00);
  }
  puVar1 = (uint *)(uVar2 * 4 + *(int *)(param_1 + 0x20));
  if (((*puVar1 == param_2) && (*puVar1 = 0xffffffff, (*(uint *)(param_1 + 0x14) & 2) != 0)) &&
     ((*(byte *)(*(int *)(param_1 + 0x24) + uVar2) & 1) != 0)) {
    FUN_c0361ba0(param_1,uVar2,uVar2);
  }
  return;
}



/* c03624fc FUN_c03624fc */

/* Boundary evidence: original MIPS .pdata c03624fc..c036261b. Semantic name remains unreviewed. */

undefined4 FUN_c03624fc(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    puVar3 = (uint *)(uVar1 * 8 + param_2);
    for (uVar2 = *puVar3; uVar2 < puVar3[1] + *puVar3; uVar2 = uVar2 + 1) {
      FUN_c036247c(param_1,uVar2);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  return 0;
}



/* c036261c FUN_c036261c */

/* Boundary evidence: original MIPS .pdata c036261c..c0362627. Semantic name remains unreviewed. */

undefined4 FUN_c036261c(void)

{
  return 1;
}



/* c0362628 FUN_c0362628 */

/* Boundary evidence: original MIPS .pdata c0362628..c0362647. Semantic name remains unreviewed. */

undefined4 FUN_c0362628(undefined4 *param_1)

{
  FUN_c0362218(param_1);
  return 0;
}



/* c0362648 FUN_c0362648 */

/* Boundary evidence: original MIPS .pdata c0362648..c0362737. Semantic name remains unreviewed. */

undefined4 FUN_c0362648(int param_1,int param_2,void *param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = *(size_t *)(param_1 + 0x10) * param_2;
  memcpy((void *)(*(int *)((uVar1 >> 0x10) * 4 + *(int *)(param_1 + 0x28)) + (uVar1 & 0xffff)),
         param_3,*(size_t *)(param_1 + 0x10));
  if ((((*(uint *)(param_1 + 0x14) & 2) != 0) &&
      ((*(byte *)(*(int *)(param_1 + 0x24) + param_2) & 1) == 0)) && (param_4 != 0)) {
    FUN_c0361b40(param_1,param_2);
  }
  return 0;
}



/* c0362738 FUN_c0362738 */

/* Boundary evidence: original MIPS .pdata c0362738..c0362743. Semantic name remains unreviewed. */

undefined4 FUN_c0362738(void)

{
  return 1;
}



/* c0362744 FUN_c0362744 */

/* Boundary evidence: original MIPS .pdata c0362744..c036286b. Semantic name remains unreviewed. */

undefined4 FUN_c0362744(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_1c [4];
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  for (uVar2 = *(uint *)(param_2 + 4); uVar2 < (uint)(*(int *)(param_2 + 8) + *(int *)(param_2 + 4))
      ; uVar2 = uVar2 + 1) {
    FUN_c036247c((int)param_1,uVar2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  if ((param_1[6] & 1) == 0) {
    iVar1 = FSDMGR_DiskIoControl(*param_1,0x71c4c,param_2,0xc,0,0,auStack_1c,0,uVar2);
    if (iVar1 == 0) {
      param_1[6] = param_1[6] | 1;
    }
  }
  return 0;
}



/* c036286c FUN_c036286c */

/* Boundary evidence: original MIPS .pdata c036286c..c0362877. Semantic name remains unreviewed. */

undefined4 FUN_c036286c(void)

{
  return 1;
}



/* c0362878 FUN_c0362878 */

/* Boundary evidence: original MIPS .pdata c0362878..c0362afb. Semantic name remains unreviewed. */

undefined4 FUN_c0362878(undefined4 *param_1)

{
  HLOCAL pvVar1;
  LPVOID pvVar2;
  HANDLE pvVar3;
  uint dwSize;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_28;
  int local_24;
  
  uVar6 = param_1[3] * param_1[4] + 0xffff >> 0x10;
  uVar7 = param_1[3] * param_1[4] & 0xffff;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  pvVar1 = LocalAlloc(0,uVar6 << 2);
  param_1[10] = pvVar1;
  if (pvVar1 != (HLOCAL)0x0) {
    if ((uint)param_1[3] < 0x40000000) {
      pvVar1 = LocalAlloc(0,param_1[3] << 2);
      param_1[8] = pvVar1;
      if (pvVar1 == (HLOCAL)0x0) {
        pvVar1 = (HLOCAL)param_1[10];
      }
      else {
        memset(pvVar1,0xff,param_1[3] << 2);
        pvVar1 = LocalAlloc(0x40,param_1[3]);
        param_1[9] = pvVar1;
        if (pvVar1 != (HLOCAL)0x0) {
          uVar4 = 0;
          if (uVar6 != 0) {
            iVar5 = 0;
            do {
              if ((uVar7 == 0) || (dwSize = uVar7, uVar4 != uVar6 - 1)) {
                dwSize = 0x10000;
              }
              pvVar2 = VirtualAlloc((LPVOID)0x0,dwSize,0x1000,4);
              *(LPVOID *)(iVar5 + param_1[10]) = pvVar2;
              if (*(int *)(iVar5 + param_1[10]) == 0) {
                if (param_1[4] == 0) {
                  trap(0x1c00);
                }
                param_1[3] = (uVar4 << 0x10) / (uint)param_1[4];
                break;
              }
              uVar4 = uVar4 + 1;
              iVar5 = iVar5 + 4;
            } while (uVar4 < uVar6);
          }
          if ((param_1[5] & 1) != 0) {
            FUN_c03619e4(param_1);
          }
          if ((param_1[5] & 2) != 0) {
            pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
            param_1[0x10] = pvVar3;
            SetEventData(pvVar3,1);
            pvVar3 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0362628,param_1,0,(LPDWORD)0x0);
            param_1[0x11] = pvVar3;
            iVar5 = FSDMGR_GetRegistryValue(*param_1,L"LazyWriterThreadPrio256",&local_28);
            if (iVar5 == 0) {
              local_28 = 0xff;
            }
            CeSetThreadPriority(param_1[0x11],local_28);
          }
          local_24 = 0;
          iVar5 = FSDMGR_GetRegistryValue(*param_1,L"CacheDisableScatterGather",&local_24);
          if (iVar5 == 0) {
            return 1;
          }
          if (local_24 == 0) {
            return 1;
          }
          param_1[6] = param_1[6] | 4;
          return 1;
        }
        LocalFree((HLOCAL)param_1[10]);
        pvVar1 = (HLOCAL)param_1[8];
      }
    }
    LocalFree(pvVar1);
  }
  return 0;
}



/* c0362afc FUN_c0362afc */

/* Boundary evidence: original MIPS .pdata c0362afc..c0362e03. Semantic name remains unreviewed. */

undefined4 FUN_c0362afc(undefined4 *param_1,uint param_2,SIZE_T param_3)

{
  HLOCAL _Dst;
  undefined4 uVar1;
  HLOCAL pvVar2;
  HLOCAL pvVar3;
  LPVOID pvVar4;
  uint uVar5;
  SIZE_T SVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  
  SVar6 = param_1[4];
  uVar11 = SVar6 * param_1[3] >> 0x10;
  uVar12 = SVar6 * param_3 >> 0x10;
  if (SVar6 == param_3) {
LAB_c0362dd4:
    uVar1 = 0;
  }
  else {
    FUN_c03622c8(param_1,0,0,0);
    _Dst = LocalAlloc(0,param_3 << 2);
    if (_Dst != (HLOCAL)0x0) {
      pvVar2 = LocalAlloc(0,uVar12 * 4 + 4);
      if (pvVar2 != (HLOCAL)0x0) {
        pvVar3 = LocalAlloc(0x40,param_3);
        if (pvVar3 != (HLOCAL)0x0) {
          EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
          if ((param_1[3] * param_1[4] & 0xffff) != 0) {
            VirtualFree(*(LPVOID *)(uVar11 * 4 + param_1[10]),0,0x8000);
          }
          param_1[3] = param_3;
          uVar7 = uVar12;
          if (uVar11 <= uVar12) {
            uVar7 = uVar11;
          }
          uVar9 = 0;
          if (uVar7 != 0) {
            iVar8 = 0;
            uVar5 = uVar7;
            do {
              *(undefined4 *)(iVar8 + (int)pvVar2) = *(undefined4 *)(iVar8 + param_1[10]);
              uVar5 = uVar5 - 1;
              iVar8 = iVar8 + 4;
              uVar9 = uVar7;
            } while (uVar5 != 0);
          }
          if (uVar9 < uVar11) {
            iVar8 = uVar11 - uVar9;
            iVar13 = uVar9 << 2;
            uVar9 = iVar8 + uVar9;
            do {
              VirtualFree(*(LPVOID *)(iVar13 + param_1[10]),0,0x8000);
              iVar8 = iVar8 + -1;
              iVar13 = iVar13 + 4;
            } while (iVar8 != 0);
          }
          if (uVar9 < uVar12) {
            puVar10 = (undefined4 *)(uVar9 * 4 + (int)pvVar2);
            do {
              pvVar4 = VirtualAlloc((LPVOID)0x0,0x10000,0x1000,4);
              *puVar10 = pvVar4;
              if (pvVar4 == (LPVOID)0x0) {
                if (param_1[4] == 0) {
                  trap(0x1c00);
                }
                param_1[3] = (uVar9 << 0x10) / (uint)param_1[4];
                break;
              }
              uVar9 = uVar9 + 1;
              puVar10 = puVar10 + 1;
            } while (uVar9 < uVar12);
          }
          uVar11 = param_1[3] * param_1[4] & 0xffff;
          if (uVar11 != 0) {
            pvVar4 = VirtualAlloc((LPVOID)0x0,uVar11,0x1000,4);
            *(LPVOID *)(uVar12 * 4 + (int)pvVar2) = pvVar4;
            if (pvVar4 == (LPVOID)0x0) {
              if (param_1[4] == 0) {
                trap(0x1c00);
              }
              param_1[3] = (uVar12 << 0x10) / (uint)param_1[4];
            }
          }
          LocalFree((HLOCAL)param_1[8]);
          LocalFree((HLOCAL)param_1[10]);
          LocalFree((HLOCAL)param_1[9]);
          param_1[9] = pvVar3;
          param_1[8] = _Dst;
          param_1[10] = pvVar2;
          if ((param_2 & 1) == 0) {
            memset(_Dst,0xff,param_1[3] << 2);
          }
          else {
            FUN_c03619e4(param_1);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
          goto LAB_c0362dd4;
        }
        LocalFree(_Dst);
        _Dst = pvVar2;
      }
      LocalFree(_Dst);
    }
    uVar1 = 0xe;
  }
  return uVar1;
}



/* c0362e04 FUN_c0362e04 */

/* Boundary evidence: original MIPS .pdata c0362e04..c0363063. Semantic name remains unreviewed. */

DWORD FUN_c0362e04(undefined4 *param_1,undefined4 param_2,uint param_3,uint param_4,int param_5)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  DWORD DVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = param_3 + param_4;
  bVar1 = false;
  DVar5 = 0;
  if (((param_3 < (uint)param_1[1]) || ((uint)param_1[2] < uVar7 - 1)) || (uVar7 - 1 < param_3)) {
    return 0x57;
  }
  if (param_1[3] == 0) {
    DVar5 = FUN_c03618b8(param_1,2,param_3,param_4,param_5);
    return DVar5;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  uVar2 = param_1[3];
  if (uVar2 < param_4) {
LAB_c0362f08:
    bVar1 = true;
    if ((((param_1[5] & 2) != 0) && (DVar5 = FUN_c0361f80(param_1,param_3,param_4,1), DVar5 != 0))
       || (DVar5 = FUN_c03618b8(param_1,2,param_3,param_4,param_5), DVar5 != 0)) goto LAB_c0363004;
  }
  else if (param_3 < uVar7) {
    uVar4 = param_3;
    do {
      if (uVar2 == 0) {
        trap(0x1c00);
      }
      if (*(uint *)((uVar4 % uVar2) * 4 + param_1[8]) != uVar4) goto LAB_c0362f08;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar7);
  }
  if ((uint)param_1[3] < param_4) {
    param_4 = param_1[3];
  }
  uVar7 = param_3 + param_4;
  if (param_3 < uVar7) {
    iVar6 = 0;
    do {
      uVar2 = param_3 % (uint)param_1[3];
      if (param_1[3] == 0) {
        trap(0x1c00);
      }
      pvVar3 = (void *)(iVar6 * param_1[4] + param_5);
      if (bVar1) {
        if (*(uint *)(uVar2 * 4 + param_1[8]) != param_3) {
          DVar5 = FUN_c0362648((int)param_1,uVar2,pvVar3,0);
          if (DVar5 != 0) break;
          *(uint *)(uVar2 * 4 + param_1[8]) = param_3;
        }
      }
      else {
        DVar5 = FUN_c036194c((int)param_1,uVar2,pvVar3);
        if (DVar5 != 0) break;
      }
      param_3 = param_3 + 1;
      iVar6 = iVar6 + 1;
    } while (param_3 < uVar7);
  }
LAB_c0363004:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  return DVar5;
}



/* c0363064 FUN_c0363064 */

/* Boundary evidence: original MIPS .pdata c0363064..c03632bb. Semantic name remains unreviewed. */

DWORD FUN_c0363064(undefined4 *param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  DWORD DVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = (param_3 + param_4) - 1;
  if (((param_3 < (uint)param_1[1]) || ((uint)param_1[2] < uVar3)) || (uVar3 < param_3)) {
    return 0x57;
  }
  if (param_1[3] == 0) {
    DVar1 = FUN_c03618b8(param_1,3,param_3,param_4,param_5);
    return DVar1;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  if ((param_1[5] & 2) == 0) {
    DVar1 = FUN_c03618b8(param_1,3,param_3,param_4,param_5);
    if (DVar1 == 0) goto LAB_c03631b0;
  }
  else {
    DVar1 = FUN_c0361f80(param_1,param_3,param_4,2);
    if ((DVar1 == 0) &&
       (((param_4 <= (uint)param_1[3] && ((param_2 & 1) == 0)) ||
        (DVar1 = FUN_c03618b8(param_1,3,param_3,param_4,param_5), DVar1 == 0)))) {
      if ((uint)param_1[3] < param_4) {
        param_4 = param_1[3];
      }
LAB_c03631b0:
      if (param_3 < param_3 + param_4) {
        iVar4 = 0;
        uVar2 = param_3;
        do {
          uVar5 = uVar2 % (uint)param_1[3];
          if (param_1[3] == 0) {
            trap(0x1c00);
          }
          DVar1 = FUN_c0362648((int)param_1,uVar5,(void *)(param_1[4] * iVar4 + param_5),
                               (uint)((param_2 & 1) == 0));
          if (DVar1 != 0) goto LAB_c036325c;
          *(uint *)(uVar5 * 4 + param_1[8]) = uVar2;
          uVar2 = uVar2 + 1;
          iVar4 = iVar4 + 1;
        } while (uVar2 < param_3 + param_4);
      }
      if (DVar1 == 0) goto LAB_c0363278;
    }
  }
LAB_c036325c:
  do {
    FUN_c036247c((int)param_1,param_3);
    param_3 = param_3 + 1;
  } while (param_3 <= uVar3);
LAB_c0363278:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  return DVar1;
}



/* c03632bc FUN_c03632bc */

/* Boundary evidence: original MIPS .pdata c03632bc..c0363353. Semantic name remains unreviewed. */

undefined4 FUN_c03632bc(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  DWORD dwErrCode;
  
  if (param_2 == 0x71c4c) {
    if (param_4 == 0xc) {
      dwErrCode = FUN_c0362744(param_1,param_3);
    }
    else {
      dwErrCode = 0x57;
    }
    SetLastError(dwErrCode);
    uVar1 = 1;
    if (dwErrCode != 0) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FSDMGR_DiskIoControl(*param_1);
  }
  return uVar1;
}



/* c0363444 FUN_c0363444 */

/* Boundary evidence: original MIPS .pdata c0363444..c036357f. Semantic name remains unreviewed. */

int FUN_c0363444(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c03640c4 != (code *)0x0) {
      iVar2 = (*DAT_c03640c4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c03634f4;
    FUN_c036379c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0361464(param_1,param_2);
  }
LAB_c03634f4:
  if (((param_2 == 0) && (FUN_c0363724(), iVar1 != 0)) && (DAT_c03640c4 != (code *)0x0)) {
    iVar1 = (*DAT_c03640c4)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0363580 FUN_c0363580 */

/* Boundary evidence: original MIPS .pdata c0363580..c03635ab. Semantic name remains unreviewed. */

void FUN_c0363580(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c03635ac entry */

/* Boundary evidence: original MIPS .pdata c03635ac..c0363603. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c03637d8();
  }
  FUN_c0363444(param_1,param_2,param_3);
  return;
}



/* c0363604 FUN_c0363604 */

/* Boundary evidence: original MIPS .pdata c0363604..c0363723. Semantic name remains unreviewed. */

void FUN_c0363604(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c03640b4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c03640bc;
    if (DAT_c03640bc != (undefined4 *)0x0) {
      while (DAT_c03640b8 = DAT_c03640b8 + -1, _Memory <= DAT_c03640b8) {
        if ((code *)*DAT_c03640b8 != (code *)0x0) {
          (*(code *)*DAT_c03640b8)();
          _Memory = DAT_c03640bc;
        }
      }
      free(_Memory);
      DAT_c03640b8 = (undefined4 *)0x0;
      DAT_c03640bc = (undefined4 *)0x0;
    }
    FUN_c0363748((undefined4 *)&DAT_c0361010,(undefined4 *)&DAT_c0361014);
  }
  FUN_c0363748((undefined4 *)&DAT_c0361018,(undefined4 *)&DAT_c036101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c03640c0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0363724 FUN_c0363724 */

/* Boundary evidence: original MIPS .pdata c0363724..c0363747. Semantic name remains unreviewed. */

void FUN_c0363724(void)

{
  FUN_c0363604(0,0,1);
  return;
}



/* c0363748 FUN_c0363748 */

/* Boundary evidence: original MIPS .pdata c0363748..c036379b. Semantic name remains unreviewed. */

void FUN_c0363748(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c036379c FUN_c036379c */

/* Boundary evidence: original MIPS .pdata c036379c..c03637d7. Semantic name remains unreviewed. */

void FUN_c036379c(void)

{
  FUN_c0363748((undefined4 *)&DAT_c0361008,(undefined4 *)&DAT_c036100c);
  FUN_c0363748((undefined4 *)&DAT_c0361000,(undefined4 *)&DAT_c0361004);
  return;
}



/* c03637d8 FUN_c03637d8 */

/* Boundary evidence: original MIPS .pdata c03637d8..c036384b. Semantic name remains unreviewed. */

void FUN_c03637d8(void)

{
  uint uVar1;
  
  if ((DAT_c036408c == 0) || (DAT_c036408c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c036408c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c036408c == 0) {
      DAT_c036408c = 0xb064;
    }
  }
  DAT_c0364090 = ~DAT_c036408c;
  return;
}


