/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 4028112c FUN_4028112c */

void FUN_4028112c(int *param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0x100;
  uVar4 = 1;
  uVar2 = DAT_4028b180;
  do {
    uVar2 = uVar2 + 1;
    if (uVar2 == 0xffffffff) {
      uVar3 = uVar3 + 1;
    }
    else {
      piVar1 = (int *)(&DAT_4028b260)[uVar2 & 0x3f];
      if (piVar1 == (int *)0x0) break;
      do {
        if (piVar1[4] == uVar2) break;
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
      if (piVar1 == (int *)0x0) break;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 <= uVar3);
  if (uVar4 <= uVar3) {
    DAT_4028b180 = DAT_4028b180 + uVar4;
    param_1[4] = DAT_4028b180;
    *param_1 = (&DAT_4028b260)[DAT_4028b180 & 0x3f];
    (&DAT_4028b260)[DAT_4028b180 & 0x3f] = param_1;
  }
  return;
}



/* 402811e0 FUN_402811e0 */

/* Boundary evidence: original MIPS .pdata 402811e0..402812db. Semantic name remains unreviewed. */

int FUN_402811e0(uint param_1,int *param_2)

{
  int iVar1;
  int *local_20;
  
  if (DAT_4028b1dc != 0) {
    return 0x2742;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  if (DAT_4028b1d8 == 0) {
    iVar1 = 0x276d;
  }
  else {
    local_20 = (int *)(&DAT_4028b260)[param_1 & 0x3f];
    if (local_20 != (int *)0x0) {
      do {
        if (param_1 == local_20[4]) break;
        local_20 = (int *)*local_20;
      } while (local_20 != (int *)0x0);
      if ((local_20 != (int *)0x0) && ((local_20[3] & 1U) == 0)) {
        local_20[2] = local_20[2] + 1;
        iVar1 = 0;
        goto LAB_402812a0;
      }
    }
    iVar1 = 0x2736;
  }
LAB_402812a0:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  if (iVar1 == 0) {
    *param_2 = (int)local_20;
  }
  return iVar1;
}



/* 402812dc FUN_402812dc */

/* Boundary evidence: original MIPS .pdata 402812dc..40281343. Semantic name remains unreviewed. */

undefined4 * FUN_402812dc(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_4028b364;
  do {
    puVar2 = puVar3;
    puVar3 = (undefined4 *)*puVar2;
    if (puVar3 == (undefined4 *)0x0) {
      return puVar2;
    }
    iVar1 = memcmp(puVar3 + 3,param_1,0x10);
  } while (iVar1 != 0);
  return puVar2;
}



/* 40281344 FUN_40281344 */

/* Boundary evidence: original MIPS .pdata 40281344..4028139f. Semantic name remains unreviewed. */

void FUN_40281344(HLOCAL param_1)

{
  undefined1 auStack_10 [8];
  
  if (DAT_4028b1dc == 0) {
    (**(code **)((int)param_1 + 0x30))(auStack_10);
    if (*(HMODULE *)((int)param_1 + 8) != (HMODULE)0x0) {
      FreeLibrary(*(HMODULE *)((int)param_1 + 8));
    }
  }
  LocalFree(param_1);
  return;
}



/* 402813a0 FUN_402813a0 */

/* Boundary evidence: original MIPS .pdata 402813a0..4028141f. Semantic name remains unreviewed. */

undefined4 FUN_402813a0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
  puVar1 = &DAT_4028b364;
  while (puVar2 = puVar1, puVar1 = (undefined4 *)*puVar2, puVar1 != (undefined4 *)0x0) {
    if ((int)puVar1[1] < 1) {
      *puVar2 = *puVar1;
      FUN_40281344(puVar1);
      puVar1 = puVar2;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
  return 0;
}



/* 40281420 FUN_40281420 */

/* Boundary evidence: original MIPS .pdata 40281420..4028151b. Semantic name remains unreviewed. */

undefined4 FUN_40281420(void *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *local_20;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  iVar2 = FUN_40284704();
  uVar3 = 1;
  if ((iVar2 != 0) || (bVar1 = false, DAT_4028b1dc != 0)) {
    bVar1 = true;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
  if ((param_2 == (undefined4 *)0x0) || (bVar1)) {
    local_20 = FUN_402812dc(param_1);
    param_2 = (undefined4 *)*local_20;
  }
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0;
  }
  else {
    iVar2 = param_2[1];
    param_2[1] = iVar2 + -1;
    if ((bVar1) && (iVar2 + -1 == 0)) {
      *local_20 = *param_2;
      FUN_40281344(param_2);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
  return uVar3;
}



/* 4028151c FUN_4028151c */

/* Boundary evidence: original MIPS .pdata 4028151c..402818bf. Semantic name remains unreviewed. */

int FUN_4028151c(undefined4 param_1,undefined4 param_2,undefined4 param_3,void *param_4,
                void *param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  HMODULE pHVar3;
  code *pcVar4;
  undefined4 uVar5;
  uint local_4e0;
  void *local_4dc;
  undefined4 local_4d8;
  WCHAR *local_4d4;
  undefined4 local_4d0;
  undefined4 *local_4a8;
  int local_4a0;
  undefined4 *local_49c;
  undefined4 local_498;
  undefined4 *local_494;
  undefined4 local_490;
  void *local_48c;
  undefined4 local_488;
  undefined4 local_480;
  undefined1 auStack_47c [60];
  short local_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_4028b178;
  local_48c = param_5;
  local_494 = param_6;
  local_49c = param_6;
  uVar5 = 0;
  local_498 = 0;
  local_4a0 = 0;
  local_488 = param_1;
  if (param_4 != (void *)0x0) {
    local_490 = 1;
    uVar5 = *(undefined4 *)((int)param_4 + 0x24);
    local_498 = uVar5;
    memcpy(param_5,param_4,0x274);
  }
  local_4e0 = (uint)(param_4 != (void *)0x0);
  local_4d0 = 0x104;
  local_4d4 = aWStack_238;
  local_4d8 = 0x274;
  local_4dc = param_5;
  local_4a0 = (*(code *)&SUB_fffe6f92)(local_488,param_2,param_3,uVar5);
  puVar2 = local_49c;
  if (local_4a0 != 0) goto LAB_40281868;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
  puVar2 = FUN_402812dc((undefined4 *)((int)param_5 + 0x14));
  puVar2 = (undefined4 *)*puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = LocalAlloc(0x40,0x29c);
    if (puVar2 == (undefined4 *)0x0) {
      local_4a0 = 0x2747;
    }
    else {
      *puVar2 = DAT_4028b364;
      puVar2[1] = 1;
      puVar2[3] = *(undefined4 *)((int)param_5 + 0x14);
      puVar2[4] = *(undefined4 *)((int)param_5 + 0x18);
      puVar2[5] = *(undefined4 *)((int)param_5 + 0x1c);
      puVar2[6] = *(undefined4 *)((int)param_5 + 0x20);
      pHVar3 = LoadLibraryW(aWStack_238);
      puVar2[2] = pHVar3;
      if (pHVar3 == (HMODULE)0x0) {
        local_4a0 = 0x277a;
LAB_40281808:
        if (local_4a0 == 0) goto LAB_4028184c;
      }
      else {
        pcVar4 = (code *)GetProcAddressW(pHVar3,L"WSPStartup");
        memcpy(&local_480,&PTR_FUN_4028b0c8,0x3c);
        if (pcVar4 == (code *)0x0) {
          local_4a0 = 0x277a;
        }
        else {
          local_4a8 = puVar2 + 7;
          memcpy(&local_4e0,auStack_47c,0x38);
          local_4a0 = (*pcVar4)(0x202,local_440,param_5,local_480);
          if (local_4a0 == 0) {
            if (local_440[0] == 0x202) {
              DAT_4028b364 = puVar2;
              wcscpy((wchar_t *)(puVar2 + 0x25),aWStack_238);
              goto LAB_40281808;
            }
            (*(code *)puVar2[0xc])(&local_4a0);
            local_4a0 = 0x2779;
          }
        }
      }
      if ((HANDLE)puVar2[2] != (HANDLE)0x0) {
        CloseHandle((HANDLE)puVar2[2]);
      }
      LocalFree(puVar2);
      puVar2 = (undefined4 *)0x0;
    }
  }
  else {
    puVar2[1] = puVar2[1] + 1;
  }
LAB_4028184c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
LAB_40281868:
  iVar1 = local_4a0;
  if (local_4a0 == 0) {
    *local_494 = puVar2;
  }
  FUN_40289f58(local_30);
  return iVar1;
}



/* 402818c0 FUN_402818c0 */

/* Boundary evidence: original MIPS .pdata 402818c0..402818cb. Semantic name remains unreviewed. */

undefined4 FUN_402818c0(void)

{
  return 1;
}



/* 402818cc FUN_402818cc */

/* Boundary evidence: original MIPS .pdata 402818cc..40281bf7. Semantic name remains unreviewed. */

int FUN_402818cc(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int *hMem;
  int *piVar1;
  HMODULE pHVar2;
  code *pcVar3;
  undefined4 *hMem_00;
  int iVar4;
  undefined4 local_740;
  undefined1 *local_73c;
  undefined4 local_738;
  WCHAR *local_734;
  undefined4 local_730;
  undefined4 *local_708;
  int local_700 [2];
  undefined4 local_6f8;
  undefined1 auStack_6f4 [60];
  undefined1 auStack_6b8 [20];
  undefined4 local_6a4;
  undefined4 local_6a0;
  undefined4 local_69c;
  undefined4 local_698;
  short local_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_4028b178;
  iVar4 = -1;
  hMem = LocalAlloc(0x40,0x28c);
  if (hMem == (int *)0x0) {
    local_700[0] = 0x2747;
    goto LAB_40281bac;
  }
  local_730 = 0x104;
  local_738 = 0x274;
  local_734 = aWStack_238;
  local_73c = auStack_6b8;
  local_740 = 1;
  local_700[0] = (*(code *)&SUB_fffe6f92)(0,0,0,param_1);
  if (local_700[0] == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
    piVar1 = FUN_402812dc(&local_6a4);
    hMem_00 = (undefined4 *)*piVar1;
    if (hMem_00 == (undefined4 *)0x0) {
      hMem_00 = LocalAlloc(0x40,0x29c);
      if (hMem_00 == (undefined4 *)0x0) {
        local_700[0] = 0x2747;
      }
      else {
        *hMem_00 = DAT_4028b364;
        hMem_00[1] = 1;
        hMem_00[3] = local_6a4;
        hMem_00[4] = local_6a0;
        hMem_00[5] = local_69c;
        hMem_00[6] = local_698;
        pHVar2 = LoadLibraryW(aWStack_238);
        hMem_00[2] = pHVar2;
        if (pHVar2 == (HMODULE)0x0) {
          local_700[0] = 0x277a;
LAB_40281acc:
          if (local_700[0] == 0) goto LAB_40281b08;
        }
        else {
          pcVar3 = (code *)GetProcAddressW(pHVar2,L"WSPStartup");
          memcpy(&local_6f8,&PTR_FUN_4028b0c8,0x3c);
          if (pcVar3 == (code *)0x0) {
            local_700[0] = 0x277a;
          }
          else {
            local_708 = hMem_00 + 7;
            memcpy(&local_740,auStack_6f4,0x38);
            local_700[0] = (*pcVar3)(0x202,local_440,auStack_6b8,local_6f8);
            if (local_700[0] == 0) {
              if (local_440[0] == 0x202) {
                DAT_4028b364 = hMem_00;
                wcscpy((wchar_t *)(hMem_00 + 0x25),aWStack_238);
                goto LAB_40281acc;
              }
              (*(code *)hMem_00[0xc])(local_700);
              local_700[0] = 0x2779;
            }
          }
        }
        if ((HANDLE)hMem_00[2] != (HANDLE)0x0) {
          CloseHandle((HANDLE)hMem_00[2]);
        }
        LocalFree(hMem_00);
        hMem_00 = (undefined4 *)0x0;
      }
    }
    else {
      hMem_00[1] = hMem_00[1] + 1;
    }
LAB_40281b08:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
    if (local_700[0] == 0) {
      hMem[2] = 1;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
      iVar4 = FUN_4028112c(hMem);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
      if (iVar4 == -1) {
        LocalFree(hMem);
        FUN_40281420(&local_6a4,hMem_00);
        local_700[0] = 0x2728;
      }
      else {
        hMem[1] = (int)hMem_00;
        memcpy(hMem + 6,auStack_6b8,0x274);
        hMem[5] = param_2;
        hMem[3] = hMem[3] | 2;
      }
      goto LAB_40281bac;
    }
  }
  LocalFree(hMem);
LAB_40281bac:
  if (local_700[0] != 0) {
    FUN_40284c64(local_700[0],param_3);
    iVar4 = -1;
  }
  FUN_40289f58(local_30);
  return iVar4;
}



/* 40281bf8 FUN_40281bf8 */

/* Boundary evidence: original MIPS .pdata 40281bf8..40281e1f. Semantic name remains unreviewed. */

undefined4 FUN_40281bf8(undefined4 *param_1,wchar_t *param_2,size_t *param_3,undefined4 *param_4)

{
  int *piVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  wchar_t *_Str;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  uint local_24;
  
  local_24 = DAT_4028b178;
  iVar3 = 0;
  local_2a8 = *param_1;
  local_2a4 = param_1[1];
  local_2a0 = param_1[2];
  local_29c = param_1[3];
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
  piVar1 = FUN_402812dc(&local_2a8);
  if (*piVar1 == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
    memset(&local_298,0,0x274);
    local_298 = *param_1;
    local_294 = param_1[1];
    local_290 = param_1[2];
    local_28c = param_1[3];
    iVar3 = (*(code *)&SUB_fffe6f92)(0,0,0,0,2,&local_298,0x274,param_2,*param_3);
    sVar2 = wcslen(param_2);
    *param_3 = sVar2;
  }
  else {
    _Str = (wchar_t *)(*piVar1 + 0x94);
    sVar2 = wcslen(_Str);
    if ((int)*param_3 < (int)sVar2) {
      iVar3 = 0x271e;
    }
    else {
      wcscpy(param_2,_Str);
    }
    *param_3 = sVar2;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
  }
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    FUN_40284c64(iVar3,param_4);
    uVar4 = 0xffffffff;
  }
  FUN_40289f58(local_24);
  return uVar4;
}



/* 40281e20 FUN_40281e20 */

/* Boundary evidence: original MIPS .pdata 40281e20..40281e2b. Semantic name remains unreviewed. */

undefined4 FUN_40281e20(void)

{
  return 1;
}



/* 40281e2c FUN_40281e2c */

/* Boundary evidence: original MIPS .pdata 40281e2c..40281e37. Semantic name remains unreviewed. */

undefined4 FUN_40281e2c(void)

{
  return 1;
}



/* 40281e38 FUN_40281e38 */

/* Boundary evidence: original MIPS .pdata 40281e38..40281f67. Semantic name remains unreviewed. */

undefined4 FUN_40281e38(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  iVar4 = 0;
  piVar2 = &DAT_4028b260 + (param_1 & 0x3f);
  do {
    piVar3 = piVar2;
    piVar2 = (int *)*piVar3;
    if (piVar2 == (int *)0x0) break;
  } while (piVar2[4] != param_1);
  iVar1 = *piVar3;
  if ((iVar1 == 0) || ((*(uint *)(iVar1 + 0xc) & 2) == 0)) {
    iVar4 = 0x2736;
  }
  else {
    *param_2 = *(undefined4 *)(iVar1 + 0x14);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  uVar5 = 0;
  if (iVar4 != 0) {
    FUN_40284c64(iVar4,param_3);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



/* 40281f68 FUN_40281f68 */

/* Boundary evidence: original MIPS .pdata 40281f68..40281f73. Semantic name remains unreviewed. */

undefined4 FUN_40281f68(void)

{
  return 1;
}



/* 40281f74 WPUCompleteOverlappedRequest */

/* Boundary evidence: original MIPS .pdata 40281f74..4028205b. Semantic name remains unreviewed. */

undefined4
WPUCompleteOverlappedRequest
          (uint param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
          undefined4 *param_5)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
                    /* 0x1f74  1  WPUCompleteOverlappedRequest */
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x57;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    piVar2 = (int *)(&DAT_4028b260)[param_1 & 0x3f];
    piVar4 = &DAT_4028b260 + (param_1 & 0x3f);
    if (piVar2 != (int *)0x0) {
      do {
        piVar3 = piVar2;
        if (piVar3[4] == param_1) break;
        piVar2 = (int *)*piVar3;
        piVar4 = piVar3;
      } while ((int *)*piVar3 != (int *)0x0);
      if (*piVar4 != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
        param_2[1] = param_4;
        *param_2 = 0x104;
        if (param_2[4] != 0) {
          EventModify(param_2[4],3);
        }
        return 0;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    uVar1 = 0x2726;
  }
  FUN_40284c64(uVar1,param_5);
  return 0xffffffff;
}



/* 4028205c FUN_4028205c */

/* Boundary evidence: original MIPS .pdata 4028205c..4028223f. Semantic name remains unreviewed. */

void FUN_4028205c(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *hMem;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  
  local_2c = 0;
  hMem = (undefined4 *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  if (DAT_4028b360 == 0) {
    puVar5 = &DAT_4028b260;
    DAT_4028b360 = 1;
    do {
      puVar3 = (undefined4 *)*puVar5;
      puVar1 = puVar5;
      while (puVar4 = hMem, puVar3 != (undefined4 *)0x0) {
        puVar4 = puVar3;
        if ((puVar3[3] & 2) == 0) {
          *puVar1 = *puVar3;
          puVar4 = puVar1;
          if ((puVar3[3] & 1) == 0) {
            *puVar3 = hMem;
            puVar3[3] = puVar3[3] | 1;
            hMem = puVar3;
          }
        }
        puVar1 = puVar4;
        puVar3 = (undefined4 *)*puVar4;
      }
      while (hMem = puVar4, hMem != (undefined4 *)0x0) {
        puVar4 = (undefined4 *)*hMem;
        hMem[3] = hMem[3] | 1;
        puVar3 = (undefined4 *)hMem[1];
        if (((DAT_4028b1dc == 0) && (puVar3 != (undefined4 *)0x0)) && (hMem[5] != 0)) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
          local_30 = 1;
          local_2e = 0;
          (*(code *)puVar3[0x21])(hMem[5],0xffff,0x80,&local_30,4,&local_2c);
          (*(code *)puVar3[0xd])(hMem[5],&local_2c);
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
        }
        iVar2 = hMem[2];
        hMem[2] = iVar2 + -1;
        if (iVar2 + -1 < 1) {
          hMem[1] = 0;
          LocalFree(hMem);
          if (puVar3 != (undefined4 *)0x0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
            FUN_40281420(puVar3 + 3,puVar3);
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
          }
        }
      }
      puVar5 = puVar5 + 1;
    } while ((int)puVar5 < 0x4028b360);
    DAT_4028b360 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  return;
}



/* 40282240 FUN_40282240 */

/* Boundary evidence: original MIPS .pdata 40282240..4028235f. Semantic name remains unreviewed. */

int FUN_40282240(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  
  local_20 = DAT_4028b178;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  iVar4 = param_1[2] + -1;
  param_1[2] = iVar4;
  if (iVar4 < 1) {
    piVar1 = &DAT_4028b260 + (param_1[4] & 0x3f);
    if ((&DAT_4028b260)[param_1[4] & 0x3f] != 0) {
      do {
        piVar2 = (int *)*piVar1;
        if (piVar2[4] == param_1[4]) break;
        piVar1 = piVar2;
      } while (*piVar2 != 0);
      if (*piVar1 != 0) {
        *piVar1 = *param_1;
      }
    }
    puVar3 = (undefined4 *)param_1[1];
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    LocalFree(param_1);
    if (puVar3 != (undefined4 *)0x0) {
      local_30 = puVar3[3];
      local_2c = puVar3[4];
      local_28 = puVar3[5];
      local_24 = puVar3[6];
      FUN_40281420(&local_30,puVar3);
    }
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  }
  FUN_40289f58(local_20);
  return iVar4;
}



/* 40282360 FUN_40282360 */

/* Boundary evidence: original MIPS .pdata 40282360..4028246b. Semantic name remains unreviewed. */

int FUN_40282360(uint param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  
  local_18 = DAT_4028b178;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  piVar1 = &DAT_4028b260 + (param_1 & 0x3f);
  do {
    piVar2 = piVar1;
    if (*piVar2 == 0) break;
    piVar1 = (int *)*piVar2;
  } while (((int *)*piVar2)[4] != param_1);
  piVar1 = (int *)*piVar2;
  if (piVar1 == (int *)0x0) {
    iVar4 = -1;
  }
  else {
    iVar4 = piVar1[2] + -1;
    piVar1[2] = iVar4;
    if (iVar4 < 1) {
      *piVar2 = *piVar1;
      puVar3 = (undefined4 *)piVar1[1];
      LocalFree(piVar1);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
      if (puVar3 != (undefined4 *)0x0) {
        local_28 = puVar3[3];
        local_24 = puVar3[4];
        local_20 = puVar3[5];
        local_1c = puVar3[6];
        FUN_40281420(&local_28,puVar3);
      }
      goto LAB_40282448;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
LAB_40282448:
  FUN_40289f58(local_18);
  return iVar4;
}



/* 4028246c WSASocketW */

/* Boundary evidence: original MIPS .pdata 4028246c..40282733. Semantic name remains unreviewed. */

int WSASocketW(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4,
              undefined4 param_5,uint param_6)

{
  int *hMem;
  int iVar1;
  uint *puVar2;
  int iVar3;
  DWORD local_2a8;
  undefined4 *local_2a4;
  uint local_2a0 [157];
  uint local_2c;
  
                    /* 0x246c  37  WSASocketW */
  local_2c = DAT_4028b178;
  iVar3 = -1;
  if (DAT_4028b1dc == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    local_2a8 = FUN_40284704();
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    if (local_2a8 == 0) {
      puVar2 = param_4;
      if (param_4 == (uint *)0x0) {
        puVar2 = local_2a0;
      }
      local_2a8 = FUN_4028151c(param_1,param_2,param_3,param_4,local_2a0,&local_2a4);
      if (local_2a8 == 0) {
        if ((param_6 & 6) == 0) {
          if ((param_6 & 0x18) != 0) goto LAB_402825d8;
LAB_402825e8:
          hMem = LocalAlloc(0x40,0x28c);
          if (hMem == (int *)0x0) goto LAB_402826c4;
          hMem[2] = 1;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
          iVar3 = FUN_4028112c(hMem);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
          if (iVar3 == -1) {
            LocalFree(hMem);
            FUN_40281420(puVar2 + 5,local_2a4);
            local_2a8 = 0x2728;
          }
          else {
            iVar1 = (*(code *)local_2a4[0x23])
                              (param_1,param_2,param_3,puVar2,param_5,param_6,&local_2a8);
            hMem[5] = iVar1;
            if (iVar1 == -1) {
              hMem[3] = hMem[3] | 1;
              FUN_40282360(hMem[4]);
              iVar3 = -1;
            }
            else {
              hMem[1] = (int)local_2a4;
              memcpy(hMem + 6,local_2a0,0x274);
            }
          }
        }
        else {
          if (((local_2a0[0] & 0x400) == 0) ||
             (((param_6 & 2) != 0 && (((param_6 & 4) != 0 || ((local_2a0[0] & 0x800) == 0)))))) {
            local_2a8 = 0x2726;
          }
          if ((param_6 & 8) == 0) {
            if ((param_6 & 0x10) == 0) goto LAB_402825d8;
          }
          else if (((local_2a0[0] & 0x1000) == 0) || ((param_6 & 0x10) != 0)) {
LAB_402825d8:
            local_2a8 = 0x2726;
          }
          if (local_2a8 == 0) goto LAB_402825e8;
LAB_402826c4:
          FUN_40281420(puVar2 + 5,local_2a4);
          if (local_2a8 != 0) goto LAB_402826ec;
          local_2a8 = 0x2747;
        }
        if (local_2a8 == 0) goto LAB_402826fc;
      }
    }
  }
  else {
    local_2a8 = 0x2742;
    iVar3 = -1;
  }
LAB_402826ec:
  SetLastError(local_2a8);
LAB_402826fc:
  FUN_40289f58(local_2c);
  return iVar3;
}



/* 40282734 socket */

/* Boundary evidence: original MIPS .pdata 40282734..40282757. Semantic name remains unreviewed. */

SOCKET socket(int af,int type,int protocol)

{
  SOCKET SVar1;
  
                    /* 0x2734  82  socket */
  SVar1 = WSASocketW(af,type,protocol,(uint *)0x0,0,0);
  return SVar1;
}



/* 40282758 closesocket */

/* Boundary evidence: original MIPS .pdata 40282758..402828af. Semantic name remains unreviewed. */

int closesocket(SOCKET s)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  DWORD local_18 [2];
  
                    /* 0x2758  49  closesocket */
  iVar4 = -1;
  local_18[0] = 0;
  if (DAT_4028b1dc == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    local_18[0] = FUN_40284704();
    if (local_18[0] == 0) {
      puVar1 = &DAT_4028b260 + (s & 0x3f);
      do {
        puVar2 = puVar1;
        puVar1 = (undefined4 *)*puVar2;
        if (puVar1 == (undefined4 *)0x0) break;
      } while (puVar1[4] != s);
      piVar3 = (int *)*puVar2;
      if ((piVar3 == (int *)0x0) || ((piVar3[3] & 1U) != 0)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
        local_18[0] = 0x2736;
      }
      else {
        piVar3[3] = piVar3[3] | 1;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
        iVar4 = (**(code **)(piVar3[1] + 0x34))(piVar3[5],local_18);
        if (iVar4 == 0) {
          FUN_40282240(piVar3);
        }
        else {
          piVar3[3] = piVar3[3] & 0xfffffffe;
        }
      }
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    }
    if (local_18[0] == 0) {
      return iVar4;
    }
  }
  else {
    local_18[0] = 0x2742;
  }
  SetLastError(local_18[0]);
  return iVar4;
}



/* 402828b0 WSAAccept */

/* Boundary evidence: original MIPS .pdata 402828b0..40282a87. Semantic name remains unreviewed. */

int * WSAAccept(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  DWORD local_30;
  int *local_2c;
  
                    /* 0x28b0  2  WSAAccept */
  local_30 = FUN_402811e0(param_1,(int *)&local_2c);
  if (local_30 == 0) {
    piVar1 = LocalAlloc(0x40,0x28c);
    if (piVar1 == (int *)0x0) {
      local_30 = 8;
      piVar2 = local_2c;
    }
    else {
      piVar1[2] = 1;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
      *(int *)(local_2c[1] + 4) = *(int *)(local_2c[1] + 4) + 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
      piVar1[1] = local_2c[1];
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
      piVar2 = (int *)FUN_4028112c(piVar1);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
      if (piVar2 == (int *)0xffffffff) {
        LocalFree(local_2c);
        FUN_40281420((undefined4 *)local_2c[1] + 3,(undefined4 *)local_2c[1]);
        local_30 = 0x2728;
      }
      else {
        iVar3 = (**(code **)(local_2c[1] + 0x1c))
                          (local_2c[5],param_2,param_3,param_4,param_5,&local_30);
        piVar1[5] = iVar3;
        if (iVar3 == -1) {
          if (local_30 == 0) {
            local_30 = 0x277b;
          }
          piVar1[3] = piVar1[3] | 1;
          FUN_40282360(piVar1[4]);
        }
        else {
          memcpy(piVar1 + 6,local_2c + 6,0x274);
        }
      }
    }
    FUN_40282240(local_2c);
    local_2c = piVar2;
  }
  else {
    local_30 = 0x2736;
  }
  if (local_30 != 0) {
    SetLastError(local_30);
    local_2c = (int *)0xffffffff;
  }
  return local_2c;
}



/* 40282a88 accept */

/* Boundary evidence: original MIPS .pdata 40282a88..40282aa7. Semantic name remains unreviewed. */

SOCKET accept(SOCKET s,sockaddr *addr,int *addrlen)

{
  int *piVar1;
  
                    /* 0x2a88  47  accept */
  piVar1 = WSAAccept(s,addr,addrlen,0,0);
  return (SOCKET)piVar1;
}



/* 40282aa8 WSAGetOverlappedResult */

/* Boundary evidence: original MIPS .pdata 40282aa8..40282b9f. Semantic name remains unreviewed. */

int * WSAGetOverlappedResult(uint param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  DWORD local_20;
  int *local_1c;
  
                    /* 0x2aa8  18  WSAGetOverlappedResult */
  if (((param_2 == 0) || (param_3 == 0)) || (param_5 == 0)) {
    local_20 = 0x271e;
  }
  else {
    local_20 = FUN_402811e0(param_1,(int *)&local_1c);
    if (local_20 != 0) goto LAB_40282b68;
    piVar1 = (int *)(**(code **)(local_1c[1] + 0x48))
                              (local_1c[5],param_2,param_3,param_4,param_5,&local_20);
    if ((piVar1 == (int *)0x0) && (local_20 == 0)) {
      local_20 = 0x277b;
    }
    FUN_40282240(local_1c);
    local_1c = piVar1;
  }
  if (local_20 == 0) {
    return local_1c;
  }
LAB_40282b68:
  SetLastError(local_20);
  return (int *)0x0;
}



/* 40282ba0 FUN_40282ba0 */

/* Boundary evidence: original MIPS .pdata 40282ba0..40282c67. Semantic name remains unreviewed. */

undefined4 FUN_40282ba0(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  piVar1 = &DAT_4028b260 + (param_1 & 0x3f);
  do {
    piVar3 = piVar1;
    piVar1 = (int *)*piVar3;
    if (piVar1 == (int *)0x0) break;
  } while (piVar1[4] != param_1);
  iVar2 = *piVar3;
  if ((iVar2 == 0) || ((*(uint *)(iVar2 + 0xc) & 2) == 0)) {
    FUN_40284c64(0x2736,param_2);
    uVar4 = 0xffffffff;
  }
  else {
    *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 1;
    FUN_40282360(*(uint *)(iVar2 + 0x10));
    uVar4 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  return uVar4;
}



/* 40282c68 FUN_40282c68 */

/* Boundary evidence: original MIPS .pdata 40282c68..40282cd3. Semantic name remains unreviewed. */

undefined4 FUN_40282c68(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x271e;
  if ((param_1 != 0) && (1 < param_2)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40282cd4 FUN_40282cd4 */

/* Boundary evidence: original MIPS .pdata 40282cd4..40282cdf. Semantic name remains unreviewed. */

undefined4 FUN_40282cd4(void)

{
  return 1;
}



/* 40282ce0 bind */

/* Boundary evidence: original MIPS .pdata 40282ce0..40282d9b. Semantic name remains unreviewed. */

int bind(SOCKET s,sockaddr *addr,int namelen)

{
  int iVar1;
  DWORD local_18;
  int *local_14;
  
                    /* 0x2ce0  48  bind */
  local_18 = FUN_402811e0(s,(int *)&local_14);
  if (local_18 == 0) {
    local_18 = FUN_40282c68((int)addr,namelen);
    if (((local_18 == 0) &&
        (iVar1 = (**(code **)(local_14[1] + 0x28))(local_14[5],addr,namelen,&local_18), iVar1 != 0))
       && (local_18 == 0)) {
      local_18 = 0x277b;
    }
    FUN_40282240(local_14);
    if (local_18 == 0) {
      return 0;
    }
  }
  SetLastError(local_18);
  return -1;
}



/* 40282d9c getpeername */

/* Boundary evidence: original MIPS .pdata 40282d9c..40282e67. Semantic name remains unreviewed. */

int getpeername(SOCKET s,sockaddr *name,int *namelen)

{
  int iVar1;
  DWORD dwErrCode;
  DWORD local_18;
  int *local_14;
  
                    /* 0x2d9c  57  getpeername */
  if (namelen == (int *)0x0) {
    dwErrCode = 0x271e;
  }
  else {
    local_18 = FUN_402811e0(s,(int *)&local_14);
    dwErrCode = local_18;
    if (local_18 == 0) {
      local_18 = FUN_40282c68((int)name,*namelen);
      if (((local_18 == 0) &&
          (iVar1 = (**(code **)(local_14[1] + 0x4c))(local_14[5],name,namelen,&local_18), iVar1 != 0
          )) && (local_18 == 0)) {
        local_18 = 0x277b;
      }
      FUN_40282240(local_14);
      dwErrCode = local_18;
      if (local_18 == 0) {
        return 0;
      }
    }
  }
  SetLastError(dwErrCode);
  return -1;
}



/* 40282e68 getsockname */

/* Boundary evidence: original MIPS .pdata 40282e68..40282f33. Semantic name remains unreviewed. */

int getsockname(SOCKET s,sockaddr *name,int *namelen)

{
  int iVar1;
  DWORD dwErrCode;
  DWORD local_18;
  int *local_14;
  
                    /* 0x2e68  62  getsockname */
  if (namelen == (int *)0x0) {
    dwErrCode = 0x271e;
  }
  else {
    local_18 = FUN_402811e0(s,(int *)&local_14);
    dwErrCode = local_18;
    if (local_18 == 0) {
      local_18 = FUN_40282c68((int)name,*namelen);
      if (((local_18 == 0) &&
          (iVar1 = (**(code **)(local_14[1] + 0x50))(local_14[5],name,namelen,&local_18), iVar1 != 0
          )) && (local_18 == 0)) {
        local_18 = 0x277b;
      }
      FUN_40282240(local_14);
      dwErrCode = local_18;
      if (local_18 == 0) {
        return 0;
      }
    }
  }
  SetLastError(dwErrCode);
  return -1;
}



/* 40282f34 htons */

u_short htons(u_short netshort)

{
  undefined2 in_register_00000012;
  
                    /* 0x2f34  65  htons
                       0x2f34  73  ntohs */
  return netshort << 8 | (ushort)(CONCAT22(in_register_00000012,netshort) >> 8);
}



/* 40282f4c htonl */

u_long htonl(u_long netlong)

{
                    /* 0x2f4c  64  htonl
                       0x2f4c  72  ntohl */
  return (netlong & 0xff00 | netlong << 0x10) << 8 | (netlong & 0xff0000 | netlong >> 0x10) >> 8;
}



/* 40282f78 inet_addr */

/* Boundary evidence: original MIPS .pdata 40282f78..4028323b. Semantic name remains unreviewed. */

ulong inet_addr(char *cp)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint local_28 [4];
  
                    /* 0x2f78  68  inet_addr */
  uVar5 = 0xffffffff;
  uVar6 = uVar5;
  if (cp != (char *)0x0) {
    memset(local_28,0,0x10);
    uVar4 = 0;
    puVar7 = local_28;
    do {
      if (*cp == 0) break;
      if (*cp == 0x30) {
        cp = cp + 1;
        if ((*cp == 0x58) || (*cp == 0x78)) {
          uVar3 = 0x10;
          goto LAB_40283094;
        }
        uVar3 = 8;
      }
      else {
        uVar3 = 10;
      }
      for (; bVar2 = *cp, bVar2 != 0; cp = cp + 1) {
        if ((bVar2 < 0x30) || (0x39 < bVar2)) {
          if ((bVar2 < 0x41) || (0x46 < bVar2)) {
            if ((bVar2 < 0x61) || (0x66 < bVar2)) break;
            bVar2 = bVar2 + 0xa9;
          }
          else {
            bVar2 = bVar2 - 0x37;
          }
        }
        else {
          bVar2 = bVar2 - 0x30;
        }
        if (uVar3 < bVar2) goto LAB_402831fc;
        *puVar7 = *puVar7 * uVar3 + (uint)bVar2;
LAB_40283094:
      }
      iVar1 = (int)*cp;
      if (iVar1 == 0x2e) {
        if (2 < uVar4) goto LAB_402831fc;
        cp = cp + 1;
      }
      else if ((iVar1 != 0) && (iVar1 = _isctype(iVar1,8), iVar1 == 0)) goto LAB_402831fc;
      if (*cp == 0) break;
      uVar4 = uVar4 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar4 < 4);
    uVar6 = local_28[0];
    if (uVar4 != 0) {
      if (uVar4 == 1) {
        uVar6 = uVar5;
        if ((local_28[0] < 0x100) && (local_28[1] < 0x1000000)) {
          uVar6 = local_28[0] << 0x18 | local_28[1];
        }
      }
      else if (uVar4 == 2) {
        uVar6 = uVar5;
        if (((local_28[0] < 0x100) && (local_28[1] < 0x100)) && (local_28[2] < 0x10000)) {
          uVar6 = (local_28[0] << 8 | local_28[1]) << 0x10 | local_28[2];
        }
      }
      else {
        uVar6 = uVar5;
        if ((((local_28[0] < 0x100) && (local_28[1] < 0x100)) && (local_28[2] < 0x100)) &&
           (local_28[3] < 0x100)) {
          uVar6 = ((local_28[0] << 8 | local_28[1]) << 8 | local_28[2]) << 8 | local_28[3];
        }
      }
    }
  }
LAB_402831fc:
  return uVar6 >> 8 & 0xff00 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18 | uVar6 >> 0x18;
}



/* 4028323c inet_ntoa */

/* Boundary evidence: original MIPS .pdata 4028323c..4028330f. Semantic name remains unreviewed. */

char * inet_ntoa(in_addr in)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  _union_1226 local_res0;
  char *local_10 [2];
  
                    /* 0x323c  69  inet_ntoa */
  local_res0 = in.S_un;
  iVar3 = FUN_40284a24(local_10);
  pcVar6 = (char *)0x0;
  if (iVar3 != 0) {
    iVar3 = 3;
    pcVar6 = local_10[0];
    do {
      do {
        pcVar4 = pcVar6;
        bVar2 = *(byte *)((int)&local_res0 + iVar3);
        uVar7 = bVar2 / 10;
        *pcVar4 = bVar2 % 10 + 0x30;
        *(byte *)((int)&local_res0 + iVar3) = (byte)uVar7;
        pcVar6 = pcVar4 + 1;
      } while (uVar7 != 0);
      pcVar4[1] = '.';
      iVar3 = iVar3 + -1;
      pcVar6 = pcVar4 + 2;
    } while (-1 < iVar3);
    pcVar4[1] = '\0';
    for (pcVar5 = local_10[0]; pcVar6 = local_10[0], pcVar5 < pcVar4; pcVar5 = pcVar5 + 1) {
      cVar1 = *pcVar4;
      *pcVar4 = *pcVar5;
      *pcVar5 = cVar1;
      pcVar4 = pcVar4 + -1;
    }
  }
  return pcVar6;
}



/* 40283310 WSAHtonl */

/* Boundary evidence: original MIPS .pdata 40283310..40283413. Semantic name remains unreviewed. */

undefined4 WSAHtonl(uint param_1,uint param_2,uint *param_3)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int *local_20;
  undefined4 local_1c;
  
                    /* 0x3310  19  WSAHtonl */
  uVar1 = 0;
  local_1c = 0;
  dwErrCode = FUN_402811e0(param_1,(int *)&local_20);
  if (dwErrCode == 0) {
    if (local_20[0x1f] == 0) {
      *param_3 = (param_2 & 0xff0000 | param_2 >> 0x10) >> 8 |
                 (param_2 & 0xff00 | param_2 << 0x10) << 8;
    }
    else {
      *param_3 = param_2;
    }
    FUN_40282240(local_20);
  }
  else {
    uVar1 = 0xffffffff;
    SetLastError(dwErrCode);
  }
  return uVar1;
}



/* 40283414 FUN_40283414 */

/* Boundary evidence: original MIPS .pdata 40283414..4028341f. Semantic name remains unreviewed. */

undefined4 FUN_40283414(void)

{
  return 1;
}



/* 40283420 WSAHtons */

/* Boundary evidence: original MIPS .pdata 40283420..4028350f. Semantic name remains unreviewed. */

undefined4 WSAHtons(uint param_1,int param_2,ushort *param_3)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int *local_20;
  undefined4 local_1c;
  
                    /* 0x3420  20  WSAHtons */
  uVar1 = 0;
  local_1c = 0;
  dwErrCode = FUN_402811e0(param_1,(int *)&local_20);
  if (dwErrCode == 0) {
    if (local_20[0x1f] == 0) {
      *param_3 = (ushort)(param_2 << 8) | (ushort)((uint)param_2 >> 8);
    }
    else {
      *param_3 = (ushort)param_2;
    }
    FUN_40282240(local_20);
  }
  else {
    uVar1 = 0xffffffff;
    SetLastError(dwErrCode);
  }
  return uVar1;
}



/* 40283510 FUN_40283510 */

/* Boundary evidence: original MIPS .pdata 40283510..4028351b. Semantic name remains unreviewed. */

undefined4 FUN_40283510(void)

{
  return 1;
}



/* 4028351c WSANtohl */

/* Boundary evidence: original MIPS .pdata 4028351c..40283537. Semantic name remains unreviewed. */

void WSANtohl(uint param_1,uint param_2,uint *param_3)

{
                    /* 0x351c  27  WSANtohl */
  WSAHtonl(param_1,param_2,param_3);
  return;
}



/* 40283538 WSANtohs */

/* Boundary evidence: original MIPS .pdata 40283538..40283553. Semantic name remains unreviewed. */

void WSANtohs(uint param_1,int param_2,ushort *param_3)

{
                    /* 0x3538  28  WSANtohs */
  WSAHtons(param_1,param_2,param_3);
  return;
}



/* 40283554 WSAAddressToStringW */

/* Boundary evidence: original MIPS .pdata 40283554..402836cf. Semantic name remains unreviewed. */

int WSAAddressToStringW(ushort *param_1,uint param_2,undefined1 *param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  DWORD local_298;
  undefined4 *local_294;
  undefined1 auStack_290 [20];
  undefined1 auStack_27c [608];
  uint local_1c;
  
                    /* 0x3554  3  WSAAddressToStringW */
  local_1c = DAT_4028b178;
  if (((param_1 == (ushort *)0x0) || (param_4 == 0)) || (param_5 == 0)) {
    SetLastError(0x271e);
LAB_402836a0:
    FUN_40289f58(local_1c);
    return -1;
  }
  if (param_3 == (undefined1 *)0x0) {
    if (param_2 < 2) {
      SetLastError(0x271e);
      goto LAB_402836a0;
    }
    uVar2 = (uint)*param_1;
    puVar3 = auStack_290;
  }
  else {
    uVar2 = 0;
    puVar3 = param_3;
  }
  local_298 = FUN_4028151c(uVar2,0,0,param_3,auStack_290,&local_294);
  if (local_298 == 0) {
    iVar1 = (*(code *)local_294[8])(param_1,param_2,puVar3,param_4,param_5,&local_298);
    if ((iVar1 != 0) && (local_298 == 0)) {
      local_298 = 0x277b;
    }
    FUN_40281420(auStack_27c,local_294);
    if (local_298 == 0) goto LAB_40283680;
  }
  SetLastError(local_298);
  iVar1 = -1;
LAB_40283680:
  FUN_40289f58(local_1c);
  return iVar1;
}



/* 402836d0 WSAStringToAddressW */

/* Boundary evidence: original MIPS .pdata 402836d0..40283807. Semantic name remains unreviewed. */

int WSAStringToAddressW(undefined4 param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4
                       ,int param_5)

{
  int iVar1;
  undefined1 *puVar2;
  DWORD local_298;
  undefined4 *local_294;
  undefined1 auStack_290 [20];
  undefined1 auStack_27c [608];
  uint local_1c;
  
                    /* 0x36d0  39  WSAStringToAddressW */
  local_1c = DAT_4028b178;
  if (param_5 == 0) {
    SetLastError(0x271e);
    FUN_40289f58(local_1c);
    return -1;
  }
  puVar2 = param_3;
  if (param_3 == (undefined1 *)0x0) {
    puVar2 = auStack_290;
  }
  local_298 = FUN_4028151c(param_2,0,0,param_3,auStack_290,&local_294);
  if (local_298 == 0) {
    iVar1 = (*(code *)local_294[0x24])(param_1,param_2,puVar2,param_4,param_5,&local_298);
    if ((iVar1 != 0) && (local_298 == 0)) {
      local_298 = 0x277b;
    }
    FUN_40281420(auStack_27c,local_294);
    if (local_298 == 0) goto LAB_402837dc;
  }
  SetLastError(local_298);
  iVar1 = -1;
LAB_402837dc:
  FUN_40289f58(local_1c);
  return iVar1;
}



/* 40283808 WSAJoinLeaf */

/* Boundary evidence: original MIPS .pdata 40283808..402838f3. Semantic name remains unreviewed. */

int WSAJoinLeaf(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  DWORD local_20;
  int *local_1c;
  
                    /* 0x3808  22  WSAJoinLeaf */
  local_20 = FUN_402811e0(param_1,(int *)&local_1c);
  if (local_20 == 0) {
    iVar1 = (**(code **)(local_1c[1] + 0x60))
                      (local_1c[5],param_2,param_3,param_4,param_5,param_6,param_7,param_8,&local_20
                      );
    if ((iVar1 == -1) && (local_20 == 0)) {
      local_20 = 0x277b;
    }
    FUN_40282240(local_1c);
    if (local_20 == 0) {
      return iVar1;
    }
  }
  SetLastError(local_20);
  return -1;
}



/* 402838f4 FUN_402838f4 */

/* Boundary evidence: original MIPS .pdata 402838f4..40283a53. Semantic name remains unreviewed. */

undefined4 FUN_402838f4(void)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  
  iVar1 = WaitForAPIReady(0x51,0);
  if (iVar1 != 0) {
    SetLastError(0x276b);
    return 0;
  }
  uVar2 = 1;
  if (DAT_4028b22c == 0) {
    DAT_4028b22c = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
    DAT_4028b228 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    DAT_4028b218 = 0;
    DAT_4028b220 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
  }
  if (DAT_4028b21c == (HMODULE)0x0) {
    DAT_4028b21c = GetModuleHandleW(L"coredll");
    if (DAT_4028b21c == (HMODULE)0x0) {
      dwErrCode = 0x2747;
    }
    else {
      DAT_4028b1f8 = GetProcAddressW(DAT_4028b21c,L"PostMessageW");
      if (DAT_4028b1f8 != 0) goto LAB_40283a30;
      FreeLibrary(DAT_4028b21c);
      dwErrCode = 0x276b;
      DAT_4028b21c = (HMODULE)0x0;
    }
    SetLastError(dwErrCode);
    uVar2 = 0;
  }
LAB_40283a30:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
  return uVar2;
}



/* 40283a54 FUN_40283a54 */

/* Boundary evidence: original MIPS .pdata 40283a54..40283a97. Semantic name remains unreviewed. */

void FUN_40283a54(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CeGetThreadPriority(0x41);
  CeSetThreadPriority(param_1,uVar1);
  return;
}



/* 40283a98 WSACancelAsyncRequest */

/* Boundary evidence: original MIPS .pdata 40283a98..40283b4b. Semantic name remains unreviewed. */

int WSACancelAsyncRequest(HANDLE hAsyncTaskHandle)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0x3a98  7  WSACancelAsyncRequest */
  iVar1 = FUN_402838f4();
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
    puVar2 = DAT_4028b224;
    if (DAT_4028b224 != (undefined4 *)0x0) {
      do {
        if (puVar2 == hAsyncTaskHandle) break;
        puVar2 = (undefined4 *)*puVar2;
      } while (puVar2 != (undefined4 *)0x0);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[6] = 0xffffffff;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
        return 0;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
    SetLastError(0x2726);
  }
  return -1;
}



/* 40283b4c FUN_40283b4c */

/* Boundary evidence: original MIPS .pdata 40283b4c..40283d7b. Semantic name remains unreviewed. */

undefined4 FUN_40283b4c(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  short sVar1;
  size_t sVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  char *_Str;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  
  sVar2 = strlen((char *)*param_2);
  iVar8 = (sVar2 + 4 & 0xfffffffc) + 0x10;
  iVar12 = 0;
  for (puVar6 = (undefined4 *)param_2[1];
      (puVar6 != (undefined4 *)0x0 && ((char *)*puVar6 != (char *)0x0)); puVar6 = puVar6 + 1) {
    sVar2 = strlen((char *)*puVar6);
    iVar8 = (sVar2 + 4 & 0xfffffffc) + iVar8;
    iVar12 = iVar12 + 1;
  }
  piVar5 = (int *)param_2[3];
  iVar10 = 0;
  iVar4 = *piVar5;
  while (iVar4 != 0) {
    piVar5 = piVar5 + 1;
    iVar10 = iVar10 + 1;
    iVar4 = *piVar5;
  }
  iVar8 = ((*(short *)((int)param_2 + 10) + 4) * iVar10 + 3U & 0xfffffffc) + iVar12 * 4 + 4 + iVar8;
  if (*param_3 < iVar8) {
    *param_3 = iVar8;
    uVar3 = 0x2747;
  }
  else {
    *(short *)((int)param_1 + 10) = *(short *)((int)param_2 + 10);
    pcVar7 = (char *)((int)param_1 + 0x13U & 0xfffffffc);
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
    *param_1 = pcVar7;
    _Str = (char *)*param_2;
    sVar2 = strlen(_Str);
    uVar11 = (uint)(pcVar7 + sVar2 + 4) & 0xfffffffc;
    strcpy(pcVar7,_Str);
    if (param_2[1] == 0) {
      param_1[1] = 0;
    }
    else {
      param_1[1] = uVar11;
      puVar6 = (undefined4 *)param_2[1];
      puVar9 = (uint *)param_1[1];
      uVar11 = iVar12 * 4 + uVar11 + 4;
      if (0 < iVar12) {
        do {
          *puVar9 = uVar11;
          pcVar7 = (char *)*puVar6;
          sVar2 = strlen(pcVar7);
          uVar11 = sVar2 + uVar11 + 4 & 0xfffffffc;
          strcpy((char *)*puVar9,pcVar7);
          iVar12 = iVar12 + -1;
          puVar9 = puVar9 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar12 != 0);
      }
      *puVar9 = 0;
    }
    param_1[3] = uVar11;
    sVar1 = *(short *)((int)param_2 + 10);
    puVar6 = (undefined4 *)param_2[3];
    puVar9 = (uint *)param_1[3];
    uVar11 = iVar10 * 4 + uVar11 + 4;
    if (0 < iVar10) {
      do {
        *puVar9 = uVar11;
        uVar11 = (int)sVar1 + 3U + uVar11 & 0xfffffffc;
        memcpy((void *)*puVar9,(void *)*puVar6,(int)sVar1);
        iVar10 = iVar10 + -1;
        puVar9 = puVar9 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar10 != 0);
    }
    *puVar9 = 0;
    uVar3 = 0;
  }
  return uVar3;
}



/* 40283d7c FUN_40283d7c */

/* Boundary evidence: original MIPS .pdata 40283d7c..40283e2b. Semantic name remains unreviewed. */

void FUN_40283d7c(HLOCAL param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = DAT_4028b214;
  piVar2 = DAT_4028b214;
  do {
    piVar1 = piVar3;
    if (piVar1 == (int *)0x0) {
LAB_40283ddc:
      if (piVar1 == param_1) {
        DAT_4028b220 = DAT_4028b220 + -1;
        WSAEventSelect(*(uint *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 0x14),0);
        CloseHandle(*(HANDLE *)((int)param_1 + 0x14));
        LocalFree(param_1);
      }
      return;
    }
    if (piVar1 == param_1) {
      if (piVar1 == DAT_4028b214) {
        DAT_4028b214 = (undefined4 *)*piVar1;
      }
      else {
        *piVar2 = *piVar1;
      }
      goto LAB_40283ddc;
    }
    piVar3 = (int *)*piVar1;
    piVar2 = piVar1;
  } while( true );
}



/* 40283e2c FUN_40283e2c */

/* Boundary evidence: original MIPS .pdata 40283e2c..40283f37. Semantic name remains unreviewed. */

void FUN_40283e2c(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  ushort *puVar5;
  uint local_48;
  ushort local_44 [22];
  
  for (piVar3 = (int *)DAT_4028b214; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    if ((param_1 != 0) && (piVar3[5] == param_1)) goto LAB_40283e7c;
  }
  piVar3 = (HLOCAL)0x0;
LAB_40283e7c:
  if (piVar3 != (HLOCAL)0x0) {
    iVar1 = WSAEnumNetworkEvents
                      (*(uint *)((int)piVar3 + 4),*(undefined4 *)((int)piVar3 + 0x14),&local_48);
    if (iVar1 != -1) {
      uVar4 = 1;
      puVar5 = local_44;
      iVar1 = 10;
      uVar2 = local_48;
      do {
        if ((*(uint *)((int)piVar3 + 0x10) & uVar2 & uVar4) != 0) {
          (*DAT_4028b1f8)(*(undefined4 *)((int)piVar3 + 8),*(undefined4 *)((int)piVar3 + 0xc),
                          *(undefined4 *)((int)piVar3 + 4),(uint)*puVar5 << 0x10 | uVar4 & 0xffff);
          uVar2 = local_48;
        }
        puVar5 = puVar5 + 2;
        iVar1 = iVar1 + -1;
        uVar4 = uVar4 << 1;
      } while (iVar1 != 0);
      if ((uVar2 & 0x20) == 0) {
        return;
      }
    }
    FUN_40283d7c(piVar3);
  }
  return;
}



/* 40283f38 FUN_40283f38 */

/* Boundary evidence: original MIPS .pdata 40283f38..402840b3. Semantic name remains unreviewed. */

undefined4 FUN_40283f38(void)

{
  DWORD DVar1;
  int *piVar2;
  HANDLE *ppvVar3;
  HANDLE *lpHandles;
  uint nCount;
  uint uVar4;
  
  lpHandles = (HANDLE *)0x0;
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
  while (nCount = 1, piVar2 = DAT_4028b214, DAT_4028b214 != (int *)0x0) {
    do {
      piVar2 = (int *)*piVar2;
      nCount = nCount + 1;
    } while (piVar2 != (int *)0x0);
    if (nCount == 1) break;
    if ((int)uVar4 < (int)nCount) {
      if (lpHandles != (HANDLE *)0x0) {
        LocalFree(lpHandles);
      }
      lpHandles = LocalAlloc(0,nCount * 4);
      uVar4 = nCount;
      if (lpHandles == (HANDLE *)0x0) goto LAB_40284070;
    }
    *lpHandles = DAT_4028b228;
    ppvVar3 = lpHandles;
    for (piVar2 = DAT_4028b214; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      ppvVar3 = ppvVar3 + 1;
      *ppvVar3 = (HANDLE)piVar2[5];
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
    DVar1 = WaitForMultipleObjects(nCount,lpHandles,0,0xffffffff);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
    if (DVar1 != 0) {
      if (nCount <= DVar1) break;
      FUN_40283e2c((int)lpHandles[DVar1]);
    }
  }
  if (lpHandles != (HANDLE *)0x0) {
    LocalFree(lpHandles);
  }
LAB_40284070:
  DAT_4028b218 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
  return 0;
}



/* 402840b4 FUN_402840b4 */

/* Boundary evidence: original MIPS .pdata 402840b4..4028427f. Semantic name remains unreviewed. */

undefined4 FUN_402840b4(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  hostent *phVar4;
  DWORD DVar5;
  int iVar6;
  DWORD DVar7;
  uint uVar8;
  hostent *local_38 [2];
  char acStack_30 [16];
  uint local_20;
  
  local_20 = DAT_4028b178;
  DVar7 = 0;
  if ((char *)param_1[5] == (char *)0x0) {
    DVar7 = 0x2726;
    phVar4 = local_38[0];
  }
  else if (param_1[3] == 0) {
    sprintf(acStack_30,"%hu",(uint)*(ushort *)(param_1 + 7));
    DVar5 = getaddrinfo((char *)param_1[5],acStack_30,(uint *)0x0,(int *)param_1[8]);
    phVar4 = local_38[0];
    if (DVar5 != 0) {
      DVar7 = GetLastError();
      phVar4 = local_38[0];
    }
  }
  else {
    phVar4 = gethostbyname((char *)param_1[5]);
    if (phVar4 == (hostent *)0x0) {
      DVar7 = GetLastError();
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
  piVar3 = DAT_4028b224;
  piVar2 = DAT_4028b224;
  if (param_1 == DAT_4028b224) {
    DAT_4028b224 = (int *)*param_1;
  }
  else {
    while ((piVar1 = piVar3, piVar1 != (int *)0x0 && (piVar1 != param_1))) {
      piVar2 = piVar1;
      piVar3 = (int *)*piVar1;
    }
    *piVar2 = *param_1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
  if (param_1[6] != -1) {
    if (DVar7 == 0) {
      uVar8 = 0;
      if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
        local_38[0] = (hostent *)param_1[4];
        iVar6 = FUN_40283b4c((undefined4 *)param_1[3],&phVar4->h_name,(int *)local_38);
        uVar8 = iVar6 << 0x10 | (uint)local_38[0];
      }
    }
    else {
      uVar8 = DVar7 << 0x10;
    }
    (*DAT_4028b1f8)(param_1[1],param_1[2],param_1,uVar8);
  }
  if ((HLOCAL)param_1[5] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[5]);
  }
  LocalFree(param_1);
  FUN_40289f58(local_20);
  return 0;
}



/* 40284280 FUN_40284280 */

/* Boundary evidence: original MIPS .pdata 40284280..402843ff. Semantic name remains unreviewed. */

undefined4 *
FUN_40284280(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,
            undefined4 param_5,undefined2 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *lpParameter;
  size_t sVar2;
  HLOCAL _Dst;
  HANDLE hThread;
  DWORD aDStack_20 [2];
  
  iVar1 = FUN_402838f4();
  if (iVar1 != 0) {
    lpParameter = LocalAlloc(0x40,0x24);
    if (lpParameter != (undefined4 *)0x0) {
      lpParameter[1] = param_1;
      lpParameter[2] = param_2;
      lpParameter[3] = param_4;
      lpParameter[4] = param_5;
      *(undefined2 *)(lpParameter + 7) = param_6;
      lpParameter[8] = param_7;
      sVar2 = strlen(param_3);
      _Dst = LocalAlloc(0x40,sVar2 + 1);
      lpParameter[5] = _Dst;
      if (_Dst != (HLOCAL)0x0) {
        memcpy(_Dst,param_3,sVar2 + 1);
        lpParameter[6] = 0;
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
        hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402840b4,lpParameter,4,aDStack_20);
        if (hThread != (HANDLE)0x0) {
          *lpParameter = DAT_4028b224;
          DAT_4028b224 = lpParameter;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
          FUN_40283a54(hThread);
          ResumeThread(hThread);
          CloseHandle(hThread);
          return lpParameter;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
        LocalFree((HLOCAL)lpParameter[5]);
      }
      LocalFree(lpParameter);
    }
    SetLastError(0x2747);
  }
  return (undefined4 *)0x0;
}



/* 40284400 WSAAsyncGetHostByName */

/* Boundary evidence: original MIPS .pdata 40284400..40284427. Semantic name remains unreviewed. */

HANDLE WSAAsyncGetHostByName(HWND hWnd,u_int wMsg,char *name,char *buf,int buflen)

{
  undefined4 *puVar1;
  
                    /* 0x4400  5  WSAAsyncGetHostByName */
  puVar1 = FUN_40284280(hWnd,wMsg,name,buf,buflen,0,0);
  return puVar1;
}



/* 40284428 WSAAsyncGetAddrInfo */

/* Boundary evidence: original MIPS .pdata 40284428..40284453. Semantic name remains unreviewed. */

void WSAAsyncGetAddrInfo(undefined4 param_1,undefined4 param_2,char *param_3,undefined2 param_4,
                        undefined4 param_5)

{
                    /* 0x4428  4  WSAAsyncGetAddrInfo */
  FUN_40284280(param_1,param_2,param_3,0,0,param_4,param_5);
  return;
}



/* 40284454 FUN_40284454 */

/* Boundary evidence: original MIPS .pdata 40284454..4028457b. Semantic name remains unreviewed. */

HLOCAL FUN_40284454(uint param_1,undefined4 param_2)

{
  HANDLE hObject;
  HLOCAL hMem;
  int iVar1;
  
  if (DAT_4028b218 == 0) {
    DAT_4028b218 = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40283f38,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject == (HANDLE)0x0) {
      DAT_4028b218 = 0;
      return (HLOCAL)0x0;
    }
    FUN_40283a54(hObject);
    CloseHandle(hObject);
  }
  if ((DAT_4028b220 < 0x3f) && (hMem = LocalAlloc(0,0x18), hMem != (HLOCAL)0x0)) {
    iVar1 = WSACreateEvent();
    *(int *)((int)hMem + 0x14) = iVar1;
    if (iVar1 != 0) {
      iVar1 = WSAEventSelect(param_1,iVar1,param_2);
      if (iVar1 == 0) {
        DAT_4028b220 = DAT_4028b220 + 1;
        return hMem;
      }
      CloseHandle(*(HANDLE *)((int)hMem + 0x14));
    }
    LocalFree(hMem);
  }
  return (HLOCAL)0x0;
}



/* 4028457c WSAAsyncSelect */

/* Boundary evidence: original MIPS .pdata 4028457c..40284703. Semantic name remains unreviewed. */

int WSAAsyncSelect(SOCKET s,HWND hWnd,u_int wMsg,long lEvent)

{
  int iVar1;
  DWORD dwErrCode;
  int *piVar2;
  u_long local_30 [2];
  
                    /* 0x457c  6  WSAAsyncSelect */
  iVar1 = FUN_402838f4();
  if (iVar1 == 0) {
    return -1;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
  for (piVar2 = DAT_4028b214; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    if ((s != 0) && (piVar2[1] == s)) goto LAB_4028460c;
  }
  piVar2 = (int *)0x0;
LAB_4028460c:
  if (lEvent == 0) {
    if (piVar2 == (int *)0x0) {
      dwErrCode = 0x2726;
LAB_40284684:
      SetLastError(dwErrCode);
      local_30[0] = 0xffffffff;
      goto LAB_402846cc;
    }
    FUN_40283d7c(piVar2);
  }
  else {
    if (piVar2 == (int *)0x0) {
      piVar2 = FUN_40284454(s,lEvent);
      if (piVar2 != (int *)0x0) {
        local_30[0] = 1;
        iVar1 = ioctlsocket(s,-0x7ffb9982,local_30);
        if (iVar1 != -1) {
          piVar2[1] = s;
          *piVar2 = (int)DAT_4028b214;
          DAT_4028b214 = piVar2;
          goto LAB_402846ac;
        }
        FUN_40283d7c(piVar2);
      }
      dwErrCode = 0x2747;
      goto LAB_40284684;
    }
LAB_402846ac:
    piVar2[2] = (int)hWnd;
    piVar2[3] = wMsg;
    piVar2[4] = lEvent;
  }
  EventModify(DAT_4028b228,3);
  local_30[0] = 0;
LAB_402846cc:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
  return local_30[0];
}



/* 40284704 FUN_40284704 */

undefined4 FUN_40284704(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_4028b1d8 == 0) {
    uVar1 = 0x276d;
  }
  return uVar1;
}



/* 40284720 WSAStartup */

/* Boundary evidence: original MIPS .pdata 40284720..40284923. Semantic name remains unreviewed. */

int WSAStartup(WORD wVersionRequired,LPWSADATA lpWSAData)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  
                    /* 0x4720  38  WSAStartup */
  iVar4 = 0;
  if (DAT_4028b1dc != 0) {
    iVar4 = 0x2742;
  }
  if (DAT_4028b1f4 == 0) {
    iVar4 = 0x276b;
  }
  if (iVar4 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    if (DAT_4028b1d4 != 0) {
      iVar4 = 0x276b;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  }
  if (iVar4 == 0) {
    uVar1 = wVersionRequired & 0xff;
    uVar3 = wVersionRequired >> 8;
    if ((wVersionRequired & 0xff) == 0) {
      iVar4 = 0x276c;
    }
    else {
      if (uVar1 == 1) {
        uVar2 = 1;
        if (1 < uVar3) {
          uVar3 = 1;
        }
      }
      else {
        uVar2 = 2;
        if ((2 < uVar1) || (2 < uVar3)) {
          uVar3 = 2;
        }
      }
      lpWSAData->wVersion = uVar3 << 8 | uVar2;
      lpWSAData->wHighVersion = 0x202;
      builtin_strncpy(lpWSAData->szDescription,"Winsock 2.2",0xc);
      lpWSAData->szSystemStatus[0] = '\0';
      lpWSAData->iMaxUdpDg = 0;
      if (uVar1 == 1) {
        lpWSAData->iMaxSockets = 200;
        lpWSAData->lpVendorInfo = (char *)0x0;
      }
      else {
        lpWSAData->iMaxSockets = 0;
      }
    }
    if (iVar4 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
      DAT_4028b1d8 = DAT_4028b1d8 + 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    }
  }
  return iVar4;
}



/* 40284924 FUN_40284924 */

/* Boundary evidence: original MIPS .pdata 40284924..4028492f. Semantic name remains unreviewed. */

undefined4 FUN_40284924(void)

{
  return 1;
}



/* 40284930 WSACleanup */

/* Boundary evidence: original MIPS .pdata 40284930..40284a23. Semantic name remains unreviewed. */

int WSACleanup(void)

{
  bool bVar1;
  DWORD dwErrCode;
  
                    /* 0x4930  8  WSACleanup */
  dwErrCode = 0;
  bVar1 = false;
  if (DAT_4028b1dc == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    if ((DAT_4028b1d8 == 0) || (DAT_4028b1f4 == 0)) {
      dwErrCode = 0x276d;
    }
    else {
      DAT_4028b1d8 = DAT_4028b1d8 + -1;
      if (DAT_4028b1d8 == 0) {
        bVar1 = true;
        DAT_4028b1d4 = 1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    if (bVar1) {
      FUN_4028205c();
      FUN_40286e98();
      FUN_402813a0();
      FUN_402865b4();
      DAT_4028b1d4 = 0;
    }
    if (dwErrCode == 0) {
      return 0;
    }
  }
  else {
    dwErrCode = 0x2742;
  }
  SetLastError(dwErrCode);
  return -1;
}



/* 40284a24 FUN_40284a24 */

/* Boundary evidence: original MIPS .pdata 40284a24..40284acb. Semantic name remains unreviewed. */

undefined4 FUN_40284a24(undefined4 *param_1)

{
  LPVOID _Dst;
  undefined4 uVar1;
  
  if (DAT_4028b104 == 0xffffffff) {
LAB_40284ab0:
    uVar1 = 0;
  }
  else {
    _Dst = TlsGetValue(DAT_4028b104);
    if (_Dst == (LPVOID)0x0) {
      _Dst = LocalAlloc(0,0x450);
      if (_Dst != (HLOCAL)0x0) {
        memset(_Dst,0,0x450);
      }
      TlsSetValue(DAT_4028b104,_Dst);
      if (_Dst == (HLOCAL)0x0) goto LAB_40284ab0;
    }
    *param_1 = _Dst;
    uVar1 = 1;
  }
  return uVar1;
}



/* 40284acc FUN_40284acc */

/* Boundary evidence: original MIPS .pdata 40284acc..40284c63. Semantic name remains unreviewed. */

undefined4 FUN_40284acc(int param_1,int param_2)

{
  int iVar1;
  LPVOID hMem;
  undefined4 uVar2;
  
  uVar2 = 1;
  iVar1 = DAT_4028b1f4;
  if (param_2 == 0) {
    if (DAT_4028b1f4 != 0) {
      DAT_4028b1dc = 1;
      FUN_4028205c();
      FUN_40286e98();
      FUN_402813a0();
      FUN_402865b4();
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
      TlsCall(1,DAT_4028b104);
      iVar1 = DAT_4028b1f4;
      if (DAT_4028b22c != 0) {
        DAT_4028b22c = 0;
        DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4028b200);
        CloseHandle(DAT_4028b228);
        iVar1 = DAT_4028b1f4;
      }
    }
  }
  else if (param_2 == 1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4028b240);
    DAT_4028b104 = TlsCall(0,0);
    iVar1 = param_1;
    if (DAT_4028b104 == 0xffffffff) {
      uVar2 = 0;
      iVar1 = DAT_4028b1f4;
    }
  }
  else if (((param_2 == 3) && (DAT_4028b104 != 0xffffffff)) &&
          (hMem = TlsGetValue(DAT_4028b104), iVar1 = DAT_4028b1f4, hMem != (LPVOID)0x0)) {
    LocalFree(hMem);
    TlsSetValue(DAT_4028b104,(LPVOID)0x0);
    iVar1 = DAT_4028b1f4;
  }
  DAT_4028b1f4 = iVar1;
  return uVar2;
}



/* 40284c64 FUN_40284c64 */

/* Boundary evidence: original MIPS .pdata 40284c64..40284cab. Semantic name remains unreviewed. */

void FUN_40284c64(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = param_1;
  return;
}



/* 40284cac FUN_40284cac */

/* Boundary evidence: original MIPS .pdata 40284cac..40284cb7. Semantic name remains unreviewed. */

undefined4 FUN_40284cac(void)

{
  return 1;
}



/* 40284cb8 FUN_40284cb8 */

/* Boundary evidence: original MIPS .pdata 40284cb8..40284d27. Semantic name remains unreviewed. */

HANDLE FUN_40284cb8(undefined4 *param_1)

{
  HANDLE pvVar1;
  DWORD DVar2;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  if (pvVar1 == (HANDLE)0x0) {
    DVar2 = GetLastError();
    FUN_40284c64(DVar2,param_1);
  }
  return pvVar1;
}



/* 40284d28 FUN_40284d28 */

/* Boundary evidence: original MIPS .pdata 40284d28..40284d83. Semantic name remains unreviewed. */

bool FUN_40284d28(HANDLE param_1,undefined4 *param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = CloseHandle(param_1);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_40284c64(DVar2,param_2);
  }
  return BVar1 != 0;
}



/* 40284d84 FUN_40284d84 */

/* Boundary evidence: original MIPS .pdata 40284d84..40284dc3. Semantic name remains unreviewed. */

int FUN_40284d84(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_2 == -1) {
    FUN_40284c64(0x2726,param_3);
  }
  return param_2;
}



/* 40284dcc FUN_40284dcc */

/* Boundary evidence: original MIPS .pdata 40284dcc..40284e33. Semantic name remains unreviewed. */

void FUN_40284dcc(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = 0;
  *param_3 = 0;
  return;
}



/* 40284e34 FUN_40284e34 */

/* Boundary evidence: original MIPS .pdata 40284e34..40284e3f. Semantic name remains unreviewed. */

undefined4 FUN_40284e34(void)

{
  return 1;
}



/* 40284e40 FUN_40284e40 */

/* Boundary evidence: original MIPS .pdata 40284e40..40284e63. Semantic name remains unreviewed. */

undefined4 FUN_40284e40(void)

{
  undefined4 *in_a3;
  
  FUN_40284c64(0x273d,in_a3);
  return 0xffffffff;
}



/* 40284e64 FUN_40284e64 */

/* Boundary evidence: original MIPS .pdata 40284e64..40284ebb. Semantic name remains unreviewed. */

bool FUN_40284e64(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = EventModify(param_1,2);
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    FUN_40284c64(DVar2,param_2);
  }
  return iVar1 != 0;
}



/* 40284ebc FUN_40284ebc */

/* Boundary evidence: original MIPS .pdata 40284ebc..40284f13. Semantic name remains unreviewed. */

bool FUN_40284ebc(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = EventModify(param_1,3);
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    FUN_40284c64(DVar2,param_2);
  }
  return iVar1 != 0;
}



/* 40284f14 FUN_40284f14 */

/* Boundary evidence: original MIPS .pdata 40284f14..40284f33. Semantic name remains unreviewed. */

undefined4 FUN_40284f14(undefined4 param_1,undefined4 *param_2)

{
  FUN_40284c64(0x273d,param_2);
  return 0xffffffff;
}



/* 40284f34 FUN_40284f34 */

/* Boundary evidence: original MIPS .pdata 40284f34..40284f53. Semantic name remains unreviewed. */

undefined4 FUN_40284f34(undefined4 param_1,undefined4 *param_2)

{
  FUN_40284c64(0x273d,param_2);
  return 0xffffffff;
}



/* 40284f54 WSACreateEvent */

/* Boundary evidence: original MIPS .pdata 40284f54..40284f83. Semantic name remains unreviewed. */

void WSACreateEvent(void)

{
                    /* 0x4f54  12  WSACreateEvent */
  CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  return;
}



/* 40284f84 WSACloseEvent */

/* Boundary evidence: original MIPS .pdata 40284f84..40284fa7. Semantic name remains unreviewed. */

void WSACloseEvent(HANDLE param_1)

{
                    /* 0x4f84  9  WSACloseEvent */
  CloseHandle(param_1);
  return;
}



/* 40284fa8 WSAResetEvent */

/* Boundary evidence: original MIPS .pdata 40284fa8..40284fc3. Semantic name remains unreviewed. */

void WSAResetEvent(undefined4 param_1)

{
                    /* 0x4fa8  31  WSAResetEvent */
  EventModify(param_1,2);
  return;
}



/* 40284fc4 WSASetEvent */

/* Boundary evidence: original MIPS .pdata 40284fc4..40284fdf. Semantic name remains unreviewed. */

void WSASetEvent(undefined4 param_1)

{
                    /* 0x4fc4  34  WSASetEvent */
  EventModify(param_1,3);
  return;
}



/* 40284fe0 WSAWaitForMultipleEvents */

/* Boundary evidence: original MIPS .pdata 40284fe0..40285003. Semantic name remains unreviewed. */

void WSAWaitForMultipleEvents(DWORD param_1,HANDLE *param_2,BOOL param_3,DWORD param_4)

{
                    /* 0x4fe0  40  WSAWaitForMultipleEvents */
  WaitForMultipleObjects(param_1,param_2,param_3,param_4);
  return;
}



/* 40285004 WSAGetLastError */

/* Boundary evidence: original MIPS .pdata 40285004..40285027. Semantic name remains unreviewed. */

int WSAGetLastError(void)

{
  DWORD DVar1;
  
                    /* 0x5004  17  WSAGetLastError */
  DVar1 = GetLastError();
  return DVar1;
}



/* 40285028 WSASetLastError */

/* Boundary evidence: original MIPS .pdata 40285028..4028504b. Semantic name remains unreviewed. */

void WSASetLastError(int iError)

{
                    /* 0x5028  35  WSASetLastError */
  SetLastError(iError);
  return;
}



/* 4028504c WSAControl */

/* Boundary evidence: original MIPS .pdata 4028504c..402850a7. Semantic name remains unreviewed. */

void WSAControl(void)

{
                    /* 0x504c  11  WSAControl */
  (*(code *)&SUB_fffe6ff6)();
  return;
}



/* 402850a8 listen */

/* Boundary evidence: original MIPS .pdata 402850a8..4028513f. Semantic name remains unreviewed. */

int listen(SOCKET s,int backlog)

{
  int iVar1;
  DWORD local_10;
  int *local_c;
  
                    /* 0x50a8  71  listen */
  local_10 = FUN_402811e0(s,(int *)&local_c);
  if (local_10 == 0) {
    iVar1 = (**(code **)(local_c[1] + 100))(local_c[5],backlog,&local_10);
    if ((iVar1 != 0) && (local_10 == 0)) {
      local_10 = 0x277b;
    }
    FUN_40282240(local_c);
    if (local_10 == 0) {
      return iVar1;
    }
  }
  SetLastError(local_10);
  return -1;
}



/* 40285140 WSAConnect */

/* Boundary evidence: original MIPS .pdata 40285140..4028522f. Semantic name remains unreviewed. */

int * WSAConnect(uint param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  DWORD local_18;
  int *local_14;
  
                    /* 0x5140  10  WSAConnect */
  local_18 = FUN_402811e0(param_1,(int *)&local_14);
  if (local_18 == 0) {
    local_18 = FUN_40282c68(param_2,param_3);
    piVar1 = local_14;
    if (((local_18 == 0) &&
        (piVar1 = (int *)(**(code **)(local_14[1] + 0x38))
                                   (local_14[5],param_2,param_3,param_4,param_5,param_6,param_7,
                                    &local_18), piVar1 != (int *)0x0)) && (local_18 == 0)) {
      local_18 = 0x277b;
    }
    FUN_40282240(local_14);
    if (local_18 == 0) {
      return piVar1;
    }
  }
  SetLastError(local_18);
  return (int *)0xffffffff;
}



/* 40285230 shutdown */

/* Boundary evidence: original MIPS .pdata 40285230..402852f3. Semantic name remains unreviewed. */

int shutdown(SOCKET s,int how)

{
  int iVar1;
  DWORD local_10;
  int *local_c;
  
                    /* 0x5230  81  shutdown */
  if (((how == 2) || (how == 0)) || (how == 1)) {
    local_10 = FUN_402811e0(s,(int *)&local_c);
    if (local_10 == 0) {
      iVar1 = (**(code **)(local_c[1] + 0x88))(local_c[5],how,&local_10);
      if ((iVar1 != 0) && (local_10 == 0)) {
        local_10 = 0x277b;
      }
      FUN_40282240(local_c);
      if (local_10 == 0) {
        return iVar1;
      }
    }
  }
  else {
    local_10 = 0x2726;
  }
  SetLastError(local_10);
  return -1;
}



/* 402852f4 connect */

/* Boundary evidence: original MIPS .pdata 402852f4..4028531b. Semantic name remains unreviewed. */

int connect(SOCKET s,sockaddr *name,int namelen)

{
  int *piVar1;
  
                    /* 0x52f4  50  connect */
  piVar1 = WSAConnect(s,(int)name,namelen,0,0,0,0);
  return (int)piVar1;
}



/* 4028531c WSCInstallProvider */

/* Boundary evidence: original MIPS .pdata 4028531c..402853a7. Semantic name remains unreviewed. */

undefined4 WSCInstallProvider(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_stack_00000010;
  
                    /* 0x531c  44  WSCInstallProvider */
  iVar1 = (*(code *)&SUB_fffe6f9a)();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *in_stack_00000010 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402853a8 FUN_402853a8 */

/* Boundary evidence: original MIPS .pdata 402853a8..402853b3. Semantic name remains unreviewed. */

undefined4 FUN_402853a8(void)

{
  return 1;
}



/* 402853b4 WSCDeinstallProvider */

/* Boundary evidence: original MIPS .pdata 402853b4..40285453. Semantic name remains unreviewed. */

undefined4 WSCDeinstallProvider(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x53b4  41  WSCDeinstallProvider */
  iVar1 = (*(code *)&SUB_fffe6f9a)(param_1,0,0,0,0,1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *param_2 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 40285454 FUN_40285454 */

/* Boundary evidence: original MIPS .pdata 40285454..4028545f. Semantic name remains unreviewed. */

undefined4 FUN_40285454(void)

{
  return 1;
}



/* 40285460 WSCEnumProtocols */

/* Boundary evidence: original MIPS .pdata 40285460..40285527. Semantic name remains unreviewed. */

int WSCEnumProtocols(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  
                    /* 0x5460  42  WSCEnumProtocols */
  uVar2 = *param_3;
  iVar1 = (*(code *)&SUB_fffe6f96)();
  if (iVar1 == -1) {
    *param_3 = uVar2;
    *param_4 = local_18;
    iVar1 = -1;
  }
  return iVar1;
}



/* 40285528 FUN_40285528 */

/* Boundary evidence: original MIPS .pdata 40285528..40285533. Semantic name remains unreviewed. */

undefined4 FUN_40285528(void)

{
  return 1;
}



/* 40285534 WSAEnumProtocolsW */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40285534..402855bf. Semantic name remains unreviewed. */

int WSAEnumProtocolsW(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  DWORD local_18 [2];
  
                    /* 0x5534  15  WSAEnumProtocolsW */
  local_18[1] = 1;
  if (param_3 == (undefined4 *)0x0) {
    local_18[0] = 0x271e;
    iVar1 = -1;
  }
  else {
    iVar1 = (*(code *)&SUB_fffe6f96)(param_1,param_2,*param_3,param_3,local_18 + 1,local_18);
  }
  if (iVar1 == -1) {
    SetLastError(local_18[0]);
  }
  return iVar1;
}



/* 402855c0 WSCInstallNameSpace */

/* Boundary evidence: original MIPS .pdata 402855c0..4028560f. Semantic name remains unreviewed. */

undefined4 WSCInstallNameSpace(void)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  
                    /* 0x55c0  43  WSCInstallNameSpace */
  dwErrCode = (*(code *)&SUB_fffe6f8e)();
  uVar1 = 0;
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* 40285610 WSCUnInstallNameSpace */

/* Boundary evidence: original MIPS .pdata 40285610..4028566f. Semantic name remains unreviewed. */

undefined4 WSCUnInstallNameSpace(undefined4 param_1)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  undefined4 local_10 [2];
  
                    /* 0x5610  45  WSCUnInstallNameSpace */
  local_10[0] = 1;
  dwErrCode = (*(code *)&SUB_fffe6f8e)(0,0,0,0,param_1,local_10);
  uVar1 = 0;
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* 40285670 WSAEnumNameSpaceProvidersW */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40285670..402856ef. Semantic name remains unreviewed. */

int WSAEnumNameSpaceProvidersW(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  DWORD local_18 [2];
  
                    /* 0x5670  13  WSAEnumNameSpaceProvidersW */
  local_18[1] = 0;
  if (param_1 == (undefined4 *)0x0) {
    local_18[0] = 0x271e;
    iVar1 = -1;
  }
  else {
    iVar1 = (*(code *)&SUB_fffe6f8a)(param_1,param_2,*param_1,local_18 + 1,local_18);
  }
  if (iVar1 == -1) {
    SetLastError(local_18[0]);
  }
  return iVar1;
}



/* 402856f0 FUN_402856f0 */

/* Boundary evidence: original MIPS .pdata 402856f0..4028579b. Semantic name remains unreviewed. */

void FUN_402856f0(uint *param_1,int *param_2)

{
  uint uVar1;
  
  if (param_1 != (uint *)0x0) {
    uVar1 = 0;
    while ((uVar1 < *param_1 && (0 < *param_2))) {
      FUN_40282360(param_1[uVar1 + 1]);
      *param_2 = *param_2 + -1;
      uVar1 = uVar1 + 1;
    }
  }
  return;
}



/* 4028579c FUN_4028579c */

/* Boundary evidence: original MIPS .pdata 4028579c..402857a7. Semantic name remains unreviewed. */

undefined4 FUN_4028579c(void)

{
  return 1;
}



/* 402857a8 FUN_402857a8 */

/* Boundary evidence: original MIPS .pdata 402857a8..402859db. Semantic name remains unreviewed. */

int FUN_402857a8(undefined4 *param_1,undefined4 *param_2,uint *param_3,int *param_4,int *param_5,
                int *param_6,uint *param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int local_48;
  int local_44;
  uint *local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  
  iVar3 = 0;
  local_40 = (uint *)0x0;
  bVar1 = true;
  local_38 = 1;
  puVar4 = (uint *)0x0;
  local_34 = param_1;
  local_30 = param_2;
  if ((param_3 != (uint *)0x0) && (uVar5 = *param_3, uVar5 != 0)) {
    iVar2 = uVar5 + 1;
    local_3c = iVar2 * 4;
    bVar1 = 2 < uVar5;
    if (bVar1) {
      param_7 = LocalAlloc(0x40,iVar2 * 8);
    }
    else {
      local_38 = 0;
    }
    puVar4 = param_7;
    local_40 = param_7;
    if (param_7 == (uint *)0x0) {
      iVar3 = 8;
      local_44 = 8;
    }
    else {
      puVar7 = param_7 + iVar2;
      *param_4 = *param_4 + uVar5;
      *puVar7 = uVar5;
      *param_7 = uVar5;
      for (uVar6 = 0; local_3c = uVar6, uVar6 < uVar5; uVar6 = uVar6 + 1) {
        iVar3 = FUN_402811e0(param_3[uVar6 + 1],&local_48);
        local_44 = iVar3;
        if (iVar3 != 0) goto LAB_40285958;
        *param_5 = *param_5 + 1;
        puVar7[uVar6 + 1] = *(uint *)(local_48 + 0x14);
        param_7[uVar6 + 1] = *(uint *)(local_48 + 0x14);
        if (*param_6 == 0) {
          *param_6 = *(int *)(local_48 + 4);
        }
        else if (*param_6 != *(int *)(local_48 + 4)) {
          iVar3 = 0x2726;
          local_44 = 0x2726;
          break;
        }
      }
      if (iVar3 == 0) {
        *local_34 = param_7;
        *local_30 = puVar7;
      }
    }
  }
LAB_40285958:
  if (((iVar3 != 0) && (bVar1)) && (puVar4 != (uint *)0x0)) {
    LocalFree(puVar4);
  }
  return iVar3;
}



/* 402859dc FUN_402859dc */

/* Boundary evidence: original MIPS .pdata 402859dc..402859e7. Semantic name remains unreviewed. */

undefined4 FUN_402859dc(void)

{
  return 1;
}



/* 402859e8 FUN_402859e8 */

/* Boundary evidence: original MIPS .pdata 402859e8..40285aef. Semantic name remains unreviewed. */

void FUN_402859e8(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_1 != (uint *)0x0) {
    if ((param_2 == (uint *)0x0) || (param_3 == (uint *)0x0)) {
      if (param_1 != (uint *)0x0) {
        *param_1 = 0;
      }
    }
    else {
      uVar7 = *param_3;
      uVar4 = *param_2;
      puVar5 = param_2;
      for (uVar6 = uVar4; uVar6 != 0; uVar6 = uVar6 - 1) {
        puVar5 = puVar5 + 1;
        uVar1 = 0;
        if (uVar7 != 0) {
          puVar2 = param_3;
          do {
            puVar2 = puVar2 + 1;
            if (*puVar5 == *puVar2) {
              *puVar5 = param_1[uVar1 + 1];
              break;
            }
            uVar1 = uVar1 + 1;
          } while (uVar1 < uVar7);
        }
      }
      *param_1 = uVar4;
      if (uVar4 != 0) {
        iVar3 = (int)param_2 - (int)param_1;
        do {
          param_1 = param_1 + 1;
          *param_1 = *(uint *)(iVar3 + (int)param_1);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
    }
  }
  return;
}



/* 40285af0 FUN_40285af0 */

/* Boundary evidence: original MIPS .pdata 40285af0..40285afb. Semantic name remains unreviewed. */

undefined4 FUN_40285af0(void)

{
  return 1;
}



/* 40285afc select */

/* Boundary evidence: original MIPS .pdata 40285afc..40285d83. Semantic name remains unreviewed. */

int select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,timeval *timeout)

{
  undefined4 *puVar1;
  long *plVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint *hMem;
  DWORD local_d0;
  int local_cc [2];
  long *local_c4;
  int local_c0 [2];
  undefined4 local_b8 [4];
  fd_set *local_a8 [4];
  long local_98;
  long local_94;
  undefined4 local_90 [4];
  uint auStack_80 [24];
  
                    /* 0x5afc  76  select */
  local_cc[1] = 0;
  local_c0[0] = 0;
  local_d0 = 0;
  puVar1 = local_b8;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != local_b8 + 3);
  puVar1 = local_90;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != local_90 + 3);
  local_a8[0] = readfds;
  local_a8[1] = writefds;
  local_a8[2] = exceptfds;
  iVar4 = -1;
  plVar2 = (long *)0x0;
  if (timeout != (timeval *)0x0) {
    plVar2 = &local_98;
    local_98 = timeout->tv_sec;
    local_94 = timeout->tv_usec;
  }
  local_cc[0] = 0;
  puVar6 = auStack_80;
  iVar5 = 0;
  local_c4 = plVar2;
  do {
    if (local_d0 != 0) goto LAB_40285cb8;
    local_d0 = FUN_402857a8((undefined4 *)((int)local_b8 + iVar5),
                            (undefined4 *)((int)local_90 + iVar5),*(uint **)((int)local_a8 + iVar5),
                            local_c0,local_cc + 1,local_cc,puVar6);
    puVar6 = puVar6 + 8;
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0xc);
  if (local_d0 == 0) {
    if ((local_c0[0] == 0) || (local_cc[0] == 0)) {
      local_d0 = 0x2726;
    }
    else {
      iVar4 = (**(code **)(local_cc[0] + 0x74))
                        (nfds,local_b8[0],local_b8[1],local_b8[2],plVar2,&local_d0);
    }
  }
LAB_40285cb8:
  puVar6 = auStack_80;
  iVar5 = 0;
  do {
    puVar3 = *(uint **)((int)local_a8 + iVar5);
    FUN_402856f0(puVar3,local_cc + 1);
    hMem = *(uint **)((int)local_b8 + iVar5);
    FUN_402859e8(puVar3,hMem,*(uint **)((int)local_90 + iVar5));
    if ((hMem != (uint *)0x0) && (hMem != puVar6)) {
      LocalFree(hMem);
    }
    puVar6 = puVar6 + 8;
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0xc);
  if (iVar4 == -1) {
    SetLastError(local_d0);
  }
  return iVar4;
}



/* 40285d84 FUN_40285d84 */

/* Boundary evidence: original MIPS .pdata 40285d84..40285d8f. Semantic name remains unreviewed. */

undefined4 FUN_40285d84(void)

{
  return 1;
}



/* 40285d90 __WSAFDIsSet */

/* WARNING: Type propagation algorithm not settling */

int __WSAFDIsSet(SOCKET param_1,fd_set *param_2)

{
  uint uVar1;
  fd_set *pfVar2;
  
                    /* 0x5d90  46  __WSAFDIsSet */
  uVar1 = param_2->fd_count & 0xffff;
  if (uVar1 != 0) {
    pfVar2 = (fd_set *)(param_2->fd_array + uVar1);
    do {
      pfVar2 = (fd_set *)((int)(pfVar2 + 0xffffffff) + 0x100);
      uVar1 = uVar1 - 1;
      if (*(SOCKET *)pfVar2 == param_1) {
        return 1;
      }
    } while (uVar1 != 0);
  }
  return 0;
}



/* 40285dd8 FUN_40285dd8 */

/* Boundary evidence: original MIPS .pdata 40285dd8..40285df3. Semantic name remains unreviewed. */

void FUN_40285dd8(SOCKET param_1,fd_set *param_2)

{
  __WSAFDIsSet(param_1,param_2);
  return;
}



/* 40285df4 WSAEventSelect */

/* Boundary evidence: original MIPS .pdata 40285df4..40285e9f. Semantic name remains unreviewed. */

undefined4 WSAEventSelect(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  DWORD local_18;
  int *local_14;
  
                    /* 0x5df4  16  WSAEventSelect */
  local_18 = FUN_402811e0(param_1,(int *)&local_14);
  if (local_18 == 0) {
    iVar1 = (**(code **)(local_14[1] + 0x44))(local_14[5],param_2,param_3,&local_18);
    if ((iVar1 != 0) && (local_18 == 0)) {
      local_18 = 0x277b;
    }
    FUN_40282240(local_14);
    if (local_18 == 0) {
      return 0;
    }
  }
  SetLastError(local_18);
  return 0xffffffff;
}



/* 40285ea0 WSAEnumNetworkEvents */

/* Boundary evidence: original MIPS .pdata 40285ea0..40285f4b. Semantic name remains unreviewed. */

undefined4 WSAEnumNetworkEvents(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  DWORD local_18;
  int *local_14;
  
                    /* 0x5ea0  14  WSAEnumNetworkEvents */
  local_18 = FUN_402811e0(param_1,(int *)&local_14);
  if (local_18 == 0) {
    iVar1 = (**(code **)(local_14[1] + 0x40))(local_14[5],param_2,param_3,&local_18);
    if ((iVar1 != 0) && (local_18 == 0)) {
      local_18 = 0x277b;
    }
    FUN_40282240(local_14);
    if (local_18 == 0) {
      return 0;
    }
  }
  SetLastError(local_18);
  return 0xffffffff;
}



/* 40285f4c FUN_40285f4c */

/* Boundary evidence: original MIPS .pdata 40285f4c..40285fc7. Semantic name remains unreviewed. */

undefined4 FUN_40285f4c(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
    uVar1 = 0x271e;
  }
  else if (*param_2 < 4) {
    uVar1 = 0x271e;
  }
  return uVar1;
}



/* 40285fc8 FUN_40285fc8 */

/* Boundary evidence: original MIPS .pdata 40285fc8..40285fd3. Semantic name remains unreviewed. */

undefined4 FUN_40285fc8(void)

{
  return 1;
}



/* 40285fd4 getsockopt */

/* Boundary evidence: original MIPS .pdata 40285fd4..402860b7. Semantic name remains unreviewed. */

int getsockopt(SOCKET s,int level,int optname,char *optval,int *optlen)

{
  int iVar1;
  DWORD local_20;
  int local_1c;
  
                    /* 0x5fd4  63  getsockopt */
  local_20 = FUN_402811e0(s,&local_1c);
  if (local_20 == 0) {
    local_20 = FUN_40285f4c((int)optval,(uint *)optlen);
    if (((local_20 == 0) &&
        (iVar1 = (**(code **)(*(int *)(local_1c + 4) + 0x54))
                           (*(undefined4 *)(local_1c + 0x14),level,optname,optval,optlen,&local_20),
        iVar1 != 0)) && (local_20 == 0)) {
      local_20 = 0x277b;
    }
    FUN_40282360(*(uint *)(local_1c + 0x10));
    if (local_20 == 0) {
      return 0;
    }
  }
  SetLastError(local_20);
  return -1;
}



/* 402860b8 setsockopt */

/* Boundary evidence: original MIPS .pdata 402860b8..40286193. Semantic name remains unreviewed. */

int setsockopt(SOCKET s,int level,int optname,char *optval,int optlen)

{
  int iVar1;
  DWORD local_18;
  int local_14;
  
                    /* 0x60b8  80  setsockopt */
  local_18 = FUN_402811e0(s,&local_14);
  if (local_18 == 0) {
    local_18 = FUN_40285f4c((int)optval,(uint *)&optlen);
    if (((local_18 == 0) &&
        (iVar1 = (**(code **)(*(int *)(local_14 + 4) + 0x84))
                           (*(undefined4 *)(local_14 + 0x14),level,optname,optval,optlen,&local_18),
        iVar1 != 0)) && (local_18 == 0)) {
      local_18 = 0x277b;
    }
    FUN_40282360(*(uint *)(local_14 + 0x10));
    if (local_18 == 0) {
      return 0;
    }
  }
  SetLastError(local_18);
  return -1;
}



/* 40286194 WSAIoctl */

/* Boundary evidence: original MIPS .pdata 40286194..402863a3. Semantic name remains unreviewed. */

undefined4
WSAIoctl(uint param_1,int param_2,void *param_3,uint param_4,undefined4 *param_5,uint param_6,
        undefined4 *param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  DWORD local_48;
  int local_44;
  undefined4 local_40 [2];
  undefined4 local_38;
  undefined2 local_34;
  undefined2 local_32;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  uint local_28;
  
                    /* 0x6194  21  WSAIoctl */
  local_28 = DAT_4028b178;
  local_48 = FUN_402811e0(param_1,&local_44);
  if (local_48 == 0) {
    local_40[0] = __GetUserKData(8);
    iVar1 = (**(code **)(*(int *)(local_44 + 4) + 0x5c))
                      (*(undefined4 *)(local_44 + 0x14),param_2,param_3,param_4,param_5,param_6,
                       param_7,param_8,param_9,local_40,&local_48);
    if ((iVar1 != 0) && (local_48 == 0)) {
      local_48 = 0x277b;
    }
    if (param_2 == -0x37fffffa) {
      local_38 = 0xf689d7c8;
      local_2e = 0xe5;
      local_34 = 0x6f1f;
      local_32 = 0x436b;
      local_30 = 0x8a;
      local_2f = 0x53;
      local_29 = 0x22;
      local_2d = 0x4f;
      local_2c = 0xe3;
      local_2b = 0x51;
      local_2a = 0xc3;
      if ((param_4 < 0x10) || (param_3 == (void *)0x0)) {
        FUN_40289f58(local_28);
        return 0xffffffff;
      }
      iVar1 = memcmp(param_3,&local_38,0x10);
      if (iVar1 == 0) {
        if ((param_6 < 4) || (param_5 == (undefined4 *)0x0)) {
          local_48 = 0x271e;
        }
        else {
          *param_5 = FUN_40287410;
          *param_7 = 4;
          local_48 = 0;
        }
      }
    }
    FUN_40282360(*(uint *)(local_44 + 0x10));
    if (local_48 == 0) {
      uVar2 = 0;
      goto LAB_40286370;
    }
  }
  SetLastError(local_48);
  uVar2 = 0xffffffff;
LAB_40286370:
  FUN_40289f58(local_28);
  return uVar2;
}



/* 402863a4 ioctlsocket */

/* Boundary evidence: original MIPS .pdata 402863a4..402863db. Semantic name remains unreviewed. */

int ioctlsocket(SOCKET s,long cmd,u_long *argp)

{
  int iVar1;
  undefined4 auStack_10 [2];
  
                    /* 0x63a4  70  ioctlsocket */
  iVar1 = WSAIoctl(s,cmd,argp,4,argp,4,auStack_10,0,0);
  return iVar1;
}



/* 402863dc FUN_402863dc */

/* Boundary evidence: original MIPS .pdata 402863dc..40286437. Semantic name remains unreviewed. */

int FUN_402863dc(void *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)DAT_4028b18c;
  while ((piVar2 != (int *)0x0 && (iVar1 = memcmp(piVar2 + 3,param_1,0x10), iVar1 != 0))) {
    piVar2 = (int *)*piVar2;
  }
  return (int)piVar2;
}



/* 40286438 FUN_40286438 */

/* Boundary evidence: original MIPS .pdata 40286438..402864bf. Semantic name remains unreviewed. */

void FUN_40286438(HLOCAL param_1)

{
  int iVar1;
  
  if ((DAT_4028b1dc == 0) &&
     (iVar1 = (**(code **)((int)param_1 + 0x28))((int)param_1 + 0xc), iVar1 != 0)) {
    GetLastError();
  }
  if ((*(HMODULE *)((int)param_1 + 8) != (HMODULE)0x0) && (DAT_4028b1dc == 0)) {
    FreeLibrary(*(HMODULE *)((int)param_1 + 8));
  }
  LocalFree(param_1);
  return;
}



/* 402864c0 FUN_402864c0 */

/* Boundary evidence: original MIPS .pdata 402864c0..402865b3. Semantic name remains unreviewed. */

void FUN_402864c0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  if (DAT_4028b1dc == 0) {
    iVar5 = FUN_40284704();
  }
  else {
    iVar5 = 0x2742;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
  iVar1 = param_1[1];
  param_1[1] = iVar1 + -1;
  puVar4 = (undefined4 *)0x0;
  if ((iVar1 + -1 == 0) && (iVar5 != 0)) {
    puVar2 = &DAT_4028b18c;
    puVar3 = DAT_4028b18c;
    puVar4 = DAT_4028b18c;
    if (DAT_4028b18c != (undefined4 *)0x0) {
      do {
        puVar4 = puVar3;
        if (puVar3 == param_1) break;
        puVar4 = (undefined4 *)*puVar3;
        puVar2 = puVar3;
        puVar3 = puVar4;
      } while (puVar4 != (undefined4 *)0x0);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar2 = *puVar4;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
  if (puVar4 == param_1) {
    FUN_40286438(param_1);
  }
  return;
}



/* 402865b4 FUN_402865b4 */

/* Boundary evidence: original MIPS .pdata 402865b4..40286643. Semantic name remains unreviewed. */

void FUN_402865b4(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
  puVar1 = &DAT_4028b18c;
  while (puVar2 = puVar1, puVar1 = (undefined4 *)*puVar2, puVar1 != (undefined4 *)0x0) {
    if (puVar1[1] == 0) {
      *puVar2 = *puVar1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
      FUN_40286438(puVar1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
      puVar1 = puVar2;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
  return;
}



/* 40286644 FUN_40286644 */

/* Boundary evidence: original MIPS .pdata 40286644..4028682f. Semantic name remains unreviewed. */

int FUN_40286644(int param_1,int param_2,int param_3)

{
  undefined4 *hMem;
  undefined4 *hMem_00;
  HMODULE pHVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  puVar6 = (undefined4 *)(param_3 + 4);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
  if (0 < param_2) {
    puVar4 = (undefined4 *)(param_1 + 4);
    do {
      hMem = LocalAlloc(0x40,0x10);
      if (hMem != (HLOCAL)0x0) {
        hMem_00 = (undefined4 *)FUN_402863dc(puVar4);
        if (hMem_00 == (undefined4 *)0x0) {
          hMem_00 = LocalAlloc(0x40,0x4c);
          if (hMem_00 != (undefined4 *)0x0) {
            *hMem_00 = DAT_4028b18c;
            hMem_00[1] = 1;
            hMem_00[3] = *puVar4;
            hMem_00[4] = puVar4[1];
            hMem_00[5] = puVar4[2];
            hMem_00[6] = puVar4[3];
            hMem_00[7] = 0x30;
            pHVar1 = LoadLibraryW((LPCWSTR)(puVar4 + 8));
            hMem_00[2] = pHVar1;
            if (pHVar1 == (HMODULE)0x0) {
              iVar3 = 0x277a;
LAB_402867a8:
              if (iVar3 == 0) goto LAB_402867bc;
            }
            else {
              pcVar2 = (code *)GetProcAddressW(pHVar1,L"NSPStartup");
              if (pcVar2 != (code *)0x0) {
                iVar3 = (*pcVar2)(puVar4,hMem_00 + 7);
                if (iVar3 == 0) {
                  iVar3 = 0;
                  DAT_4028b18c = hMem_00;
                }
                else {
                  CloseHandle((HANDLE)hMem_00[2]);
                  hMem_00[2] = 0;
                }
                goto LAB_402867a8;
              }
            }
            LocalFree(hMem_00);
            hMem_00 = (undefined4 *)0x0;
            goto LAB_402867bc;
          }
        }
        else {
          hMem_00[1] = hMem_00[1] + 1;
LAB_402867bc:
          if (hMem_00 != (undefined4 *)0x0) {
            hMem[1] = hMem_00;
            *puVar6 = hMem;
            iVar5 = iVar5 + 1;
            puVar6 = hMem;
            goto LAB_402867e0;
          }
        }
        LocalFree(hMem);
      }
LAB_402867e0:
      param_2 = param_2 + -1;
      puVar4 = puVar4 + 0x9b;
    } while (param_2 != 0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1c0);
  return iVar5;
}



/* 40286830 FUN_40286830 */

/* Boundary evidence: original MIPS .pdata 40286830..4028691b. Semantic name remains unreviewed. */

int FUN_40286830(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(param_1 + 4);
  iVar1 = 0;
  iVar3 = 0;
  if (piVar2 != (int *)0x0) {
    do {
      iVar1 = piVar2[1];
      if (param_6 == 0) {
        iVar1 = (**(code **)(iVar1 + 0x2c))(iVar1 + 0xc,param_2,param_3,param_4,piVar2 + 3);
        if (iVar1 == 0) {
          iVar3 = iVar3 + 1;
        }
        else {
          piVar2[2] = piVar2[2] | 1;
        }
      }
      else {
        iVar1 = (**(code **)(iVar1 + 0x38))(iVar1 + 0xc,param_3,param_2,param_5,param_4);
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    if (iVar3 != 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 4028691c FUN_4028691c */

/* Boundary evidence: original MIPS .pdata 4028691c..4028697f. Semantic name remains unreviewed. */

void FUN_4028691c(HLOCAL param_1)

{
  undefined4 *hMem;
  HLOCAL pvVar1;
  
  hMem = *(HLOCAL *)((int)param_1 + 4);
  while (hMem != (HLOCAL)0x0) {
    FUN_402864c0((undefined4 *)hMem[1]);
    pvVar1 = (HLOCAL)*hMem;
    LocalFree(hMem);
    hMem = pvVar1;
  }
  LocalFree(param_1);
  return;
}



/* 40286980 FUN_40286980 */

/* Boundary evidence: original MIPS .pdata 40286980..40286d07. Semantic name remains unreviewed. */

DWORD FUN_40286980(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                  int param_5)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  SIZE_T uBytes;
  HLOCAL hMem;
  DWORD local_48;
  SIZE_T local_44;
  undefined4 *local_40;
  HLOCAL local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *local_30;
  
  hMem = (HLOCAL)0x0;
  local_3c = (HLOCAL)0x0;
  local_40 = param_1;
  local_38 = param_2;
  local_34 = param_3;
  local_30 = param_4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  local_48 = FUN_40284704();
  if (local_48 == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    puVar3 = local_40;
    puVar2 = local_40;
    if ((param_1 == (undefined4 *)0x0) || ((param_5 == 0 && (param_4 == (undefined4 *)0x0)))) {
      local_48 = 0x271e;
    }
    else {
      uBytes = 0x1838;
      do {
        bVar1 = false;
        hMem = LocalAlloc(0x40,uBytes);
        local_3c = hMem;
        if (hMem == (HLOCAL)0x0) {
          local_48 = 8;
        }
        else {
          local_44 = uBytes;
          puVar2 = (undefined4 *)(*(code *)&SUB_fffe6f86)(puVar3,hMem,uBytes,&local_44,&local_48);
          if (((puVar2 == (undefined4 *)0xffffffff) && (local_48 == 0x271e)) &&
             ((int)uBytes < (int)local_44)) {
            LocalFree(hMem);
            bVar1 = true;
            local_48 = 0;
            uBytes = local_44;
          }
        }
        param_1 = local_40;
      } while (bVar1);
    }
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
    puVar2 = local_40;
  }
  if (local_48 != 0) {
    puVar2 = (undefined4 *)0xffffffff;
  }
  if (puVar2 != (undefined4 *)0xffffffff) {
    puVar3 = LocalAlloc(0x40,0x20);
    local_40 = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      local_48 = 8;
    }
    else if ((puVar2 == (undefined4 *)0x0) ||
            (iVar4 = FUN_40286644((int)hMem,(int)puVar2,(int)puVar3), iVar4 == 0)) {
      FUN_4028691c(puVar3);
      local_48 = 0x277c;
    }
    else {
      iVar4 = FUN_40286830((int)puVar3,param_1,0,local_34,local_38,param_5);
      if (iVar4 == -1) {
        local_48 = GetLastError();
      }
      if ((local_48 == 0) && (param_5 == 0)) {
        *local_30 = puVar3;
        InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 2));
        puVar3[7] = 1;
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
        *puVar3 = DAT_4028b188;
        DAT_4028b188 = puVar3;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
      }
      else {
        FUN_4028691c(puVar3);
      }
    }
  }
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
  if (local_48 != 0) {
    SetLastError(local_48);
    local_48 = 0xffffffff;
  }
  return local_48;
}



/* 40286d08 FUN_40286d08 */

/* Boundary evidence: original MIPS .pdata 40286d08..40286d13. Semantic name remains unreviewed. */

undefined4 FUN_40286d08(void)

{
  return 1;
}



/* 40286d14 WSASetServiceW */

/* Boundary evidence: original MIPS .pdata 40286d14..40286d37. Semantic name remains unreviewed. */

void WSASetServiceW(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x6d14  36  WSASetServiceW */
  FUN_40286980(param_1,param_2,param_3,(undefined4 *)0x0,1);
  return;
}



/* 40286d38 WSALookupServiceBeginW */

/* Boundary evidence: original MIPS .pdata 40286d38..40286d5f. Semantic name remains unreviewed. */

void WSALookupServiceBeginW(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
                    /* 0x6d38  23  WSALookupServiceBeginW */
  FUN_40286980(param_1,0,param_2,param_3,0);
  return;
}



/* 40286d60 FUN_40286d60 */

/* Boundary evidence: original MIPS .pdata 40286d60..40286e1f. Semantic name remains unreviewed. */

undefined4 * FUN_40286d60(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
  puVar1 = &DAT_4028b188;
  puVar2 = DAT_4028b188;
  do {
    if (puVar2 == (undefined4 *)0x0) {
LAB_40286df8:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
      return puVar2;
    }
    if (puVar2 == param_1) {
      if (param_2 == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 2));
        puVar2[7] = puVar2[7] + 1;
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 2));
      }
      else {
        *puVar1 = *puVar2;
      }
      goto LAB_40286df8;
    }
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}



/* 40286e20 FUN_40286e20 */

/* Boundary evidence: original MIPS .pdata 40286e20..40286e97. Semantic name remains unreviewed. */

void FUN_40286e20(HLOCAL param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 8);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = *(int *)((int)param_1 + 0x1c) + -1;
  *(int *)((int)param_1 + 0x1c) = iVar1;
  if (iVar1 == 0) {
    iVar1 = *(int *)((int)param_1 + 4);
  }
  else {
    iVar1 = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  if (iVar1 != 0) {
    DeleteCriticalSection(lpCriticalSection);
    FUN_4028691c(param_1);
  }
  return;
}



/* 40286e98 FUN_40286e98 */

/* Boundary evidence: original MIPS .pdata 40286e98..40286f0b. Semantic name remains unreviewed. */

void FUN_40286e98(void)

{
  undefined4 *puVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
  while (puVar1 = DAT_4028b188, DAT_4028b188 != (HLOCAL)0x0) {
    DAT_4028b188 = (undefined4 *)*DAT_4028b188;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
    FUN_40286e20(puVar1);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1a0);
  return;
}



/* 40286f0c WSALookupServiceNextW */

/* Boundary evidence: original MIPS .pdata 40286f0c..40287087. Semantic name remains unreviewed. */

undefined4
WSALookupServiceNextW(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0x6f0c  25  WSALookupServiceNextW */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  dwErrCode = FUN_40284704();
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  if (param_3 == 0) {
    dwErrCode = 0x271e;
  }
  if (dwErrCode == 0) {
    puVar1 = FUN_40286d60(param_1,0);
    if (puVar1 == (undefined4 *)0x0) {
      dwErrCode = 6;
    }
    else {
      dwErrCode = 0x277e;
      for (piVar3 = (int *)puVar1[1]; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
        if (((piVar3[2] & 1U) == 0) && ((piVar3[2] & 2U) == 0)) {
          iVar2 = (**(code **)(piVar3[1] + 0x30))(piVar3[3],param_2,param_3,param_4);
          dwErrCode = 0;
          if ((iVar2 == 0) || (dwErrCode = GetLastError(), dwErrCode == 0x271e)) break;
          if (dwErrCode != 0x277e) {
            piVar3[2] = piVar3[2] | 2;
          }
        }
      }
      FUN_40286e20(puVar1);
    }
    if (dwErrCode == 0) {
      return 0;
    }
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* 40287088 WSALookupServiceEnd */

/* Boundary evidence: original MIPS .pdata 40287088..4028715f. Semantic name remains unreviewed. */

undefined4 WSALookupServiceEnd(undefined4 *param_1)

{
  DWORD dwErrCode;
  undefined4 *puVar1;
  int *piVar2;
  
                    /* 0x7088  24  WSALookupServiceEnd */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  dwErrCode = FUN_40284704();
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  if (dwErrCode == 0) {
    puVar1 = FUN_40286d60(param_1,1);
    if (puVar1 != (undefined4 *)0x0) {
      for (piVar2 = (int *)puVar1[1]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        if ((piVar2[2] & 1U) == 0) {
          (**(code **)(piVar2[1] + 0x34))(piVar2[3]);
        }
      }
      FUN_40286e20(puVar1);
      return 0;
    }
    dwErrCode = 6;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* 40287160 WSANSPIoctl */

/* Boundary evidence: original MIPS .pdata 40287160..40287323. Semantic name remains unreviewed. */

undefined4
WSANSPIoctl(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,int param_7,int param_8)

{
  DWORD dwErrCode;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  undefined1 auStack_30 [16];
  
                    /* 0x7160  26  WSANSPIoctl */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  dwErrCode = FUN_40284704();
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4028b1e0);
  if (dwErrCode != 0) goto LAB_402872e4;
  if (((param_8 != 0) && (iVar1 = CeSafeCopyMemory(auStack_30,param_8,0x10), iVar1 == 0)) ||
     (param_7 == 0)) {
    dwErrCode = 0x2726;
    goto LAB_402872e4;
  }
  if (param_1 == (undefined4 *)0x0) {
    dwErrCode = 6;
    goto LAB_402872e4;
  }
  puVar2 = FUN_40286d60(param_1,0);
  if (puVar2 == (undefined4 *)0x0) {
    dwErrCode = 6;
  }
  else {
    piVar4 = (int *)puVar2[1];
    uVar5 = 0;
    piVar6 = (int *)0x0;
    if (piVar4 != (int *)0x0) {
      do {
        if ((*(int *)(piVar4[1] + 0x48) != 0) && (uVar5 = uVar5 + 1, piVar6 = piVar4, 1 < uVar5))
        goto LAB_4028726c;
        piVar4 = (int *)*piVar4;
      } while (piVar4 != (int *)0x0);
      if (1 < uVar5) {
LAB_4028726c:
        dwErrCode = 0x2726;
        goto LAB_402872d4;
      }
      if (piVar6 != (int *)0x0) {
        uVar3 = (**(code **)(piVar6[1] + 0x48))
                          (piVar6[3],param_2,param_3,param_4,param_5,param_6,param_7,param_8,0);
        FUN_40286e20(puVar2);
        return uVar3;
      }
    }
    dwErrCode = 0x273d;
  }
LAB_402872d4:
  if (puVar2 != (undefined4 *)0x0) {
    FUN_40286e20(puVar2);
  }
LAB_402872e4:
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* 40287324 WSARecv */

/* Boundary evidence: original MIPS .pdata 40287324..4028740f. Semantic name remains unreviewed. */

undefined4
WSARecv(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
       undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  DWORD local_20;
  int *local_1c;
  undefined4 local_18 [2];
  
                    /* 0x7324  29  WSARecv */
  local_20 = FUN_402811e0(param_1,(int *)&local_1c);
  if (local_20 == 0) {
    local_18[0] = __GetUserKData(8);
    iVar1 = (**(code **)(local_1c[1] + 0x68))
                      (local_1c[5],param_2,param_3,param_4,param_5,param_6,param_7,local_18,
                       &local_20);
    if ((iVar1 != 0) && (local_20 == 0)) {
      local_20 = 0x277b;
    }
    FUN_40282240(local_1c);
    if (local_20 == 0) {
      return 0;
    }
  }
  SetLastError(local_20);
  return 0xffffffff;
}



/* 40287410 FUN_40287410 */

/* Boundary evidence: original MIPS .pdata 40287410..402874ff. Semantic name remains unreviewed. */

undefined4
FUN_40287410(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  DWORD local_20;
  int local_1c;
  undefined4 local_18 [2];
  
  local_20 = FUN_402811e0(param_1,&local_1c);
  if (local_20 == 0) {
    local_18[0] = __GetUserKData(8);
    iVar1 = (**(code **)(*(int *)(local_1c + 4) + 0x5c))
                      (*(undefined4 *)(local_1c + 0x14),0xd8004153,param_2,0x1c,0,0,param_3,param_4,
                       param_5,local_18,&local_20);
    if ((iVar1 != 0) && (local_20 == 0)) {
      local_20 = 0x277b;
    }
    FUN_40282360(*(uint *)(local_1c + 0x10));
    if (local_20 == 0) {
      return 0;
    }
  }
  SetLastError(local_20);
  return 0xffffffff;
}



/* 40287500 recv */

/* Boundary evidence: original MIPS .pdata 40287500..4028754b. Semantic name remains unreviewed. */

int recv(SOCKET s,char *buf,int len,int flags)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  char *local_c;
  
                    /* 0x7500  74  recv */
  local_18 = flags;
  local_10 = len;
  local_c = buf;
  iVar1 = WSARecv(s,&local_10,1,&local_14,&local_18,0,0);
  if (iVar1 == 0) {
    iVar1 = local_14;
  }
  return iVar1;
}



/* 4028754c WSARecvFrom */

/* Boundary evidence: original MIPS .pdata 4028754c..40287687. Semantic name remains unreviewed. */

undefined4
WSARecvFrom(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
           ,int param_6,int *param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  DWORD local_28;
  int *local_24;
  undefined4 local_20 [2];
  
                    /* 0x754c  30  WSARecvFrom */
  local_28 = FUN_402811e0(param_1,(int *)&local_24);
  if (local_28 != 0) goto LAB_40287650;
  if (param_6 == 0) {
LAB_402875bc:
    local_20[0] = __GetUserKData(8);
    iVar1 = (**(code **)(local_24[1] + 0x70))
                      (local_24[5],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       local_20,&local_28);
    if ((iVar1 != 0) && (local_28 == 0)) {
      local_28 = 0x277b;
    }
  }
  else {
    if (param_7 == (int *)0x0) {
      local_28 = 0x271e;
    }
    else {
      local_28 = FUN_40282c68(param_6,*param_7);
    }
    if (local_28 == 0) goto LAB_402875bc;
  }
  FUN_40282240(local_24);
  if (local_28 == 0) {
    return 0;
  }
LAB_40287650:
  SetLastError(local_28);
  return 0xffffffff;
}



/* 40287688 recvfrom */

/* Boundary evidence: original MIPS .pdata 40287688..402876e3. Semantic name remains unreviewed. */

int recvfrom(SOCKET s,char *buf,int len,int flags,sockaddr *from,int *fromlen)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  char *local_c;
  
                    /* 0x7688  75  recvfrom */
  local_18 = flags;
  local_10 = len;
  local_c = buf;
  iVar1 = WSARecvFrom(s,&local_10,1,&local_14,&local_18,(int)from,fromlen,0,0);
  if (iVar1 == 0) {
    iVar1 = local_14;
  }
  return iVar1;
}



/* 402876e4 WSASend */

/* Boundary evidence: original MIPS .pdata 402876e4..402877cf. Semantic name remains unreviewed. */

undefined4
WSASend(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
       undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  DWORD local_20;
  int *local_1c;
  undefined4 local_18 [2];
  
                    /* 0x76e4  32  WSASend */
  local_20 = FUN_402811e0(param_1,(int *)&local_1c);
  if (local_20 == 0) {
    local_18[0] = __GetUserKData(8);
    iVar1 = (**(code **)(local_1c[1] + 0x78))
                      (local_1c[5],param_2,param_3,param_4,param_5,param_6,param_7,local_18,
                       &local_20);
    if ((iVar1 != 0) && (local_20 == 0)) {
      local_20 = 0x277b;
    }
    FUN_40282240(local_1c);
    if (local_20 == 0) {
      return 0;
    }
  }
  SetLastError(local_20);
  return 0xffffffff;
}



/* 402877d0 send */

/* Boundary evidence: original MIPS .pdata 402877d0..40287813. Semantic name remains unreviewed. */

int send(SOCKET s,char *buf,int len,int flags)

{
  int iVar1;
  int local_18 [2];
  int local_10;
  char *local_c;
  
                    /* 0x77d0  77  send */
  local_10 = len;
  local_c = buf;
  iVar1 = WSASend(s,&local_10,1,local_18,flags,0,0);
  if (iVar1 == 0) {
    iVar1 = local_18[0];
  }
  return iVar1;
}



/* 40287814 WSASendTo */

/* Boundary evidence: original MIPS .pdata 40287814..4028790f. Semantic name remains unreviewed. */

undefined4
WSASendTo(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
         undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  DWORD local_20;
  int *local_1c;
  undefined4 local_18 [2];
  
                    /* 0x7814  33  WSASendTo */
  local_20 = FUN_402811e0(param_1,(int *)&local_1c);
  if (local_20 == 0) {
    local_18[0] = __GetUserKData(8);
    iVar1 = (**(code **)(local_1c[1] + 0x80))
                      (local_1c[5],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       local_18,&local_20);
    if ((iVar1 != 0) && (local_20 == 0)) {
      local_20 = 0x277b;
    }
    FUN_40282240(local_1c);
    if (local_20 == 0) {
      return 0;
    }
  }
  SetLastError(local_20);
  return 0xffffffff;
}



/* 40287910 sendto */

/* Boundary evidence: original MIPS .pdata 40287910..40287963. Semantic name remains unreviewed. */

int sendto(SOCKET s,char *buf,int len,int flags,sockaddr *to,int tolen)

{
  int iVar1;
  int local_18 [2];
  int local_10;
  char *local_c;
  
                    /* 0x7910  78  sendto */
  local_10 = len;
  local_c = buf;
  iVar1 = WSASendTo(s,&local_10,1,local_18,flags,to,tolen,0,0);
  if (iVar1 == 0) {
    iVar1 = local_18[0];
  }
  return iVar1;
}



/* 40287964 FUN_40287964 */

undefined4 FUN_40287964(short *param_1)

{
  undefined4 uVar1;
  
  if (((((*param_1 != 0) || (param_1[1] != 0)) || (param_1[2] != 0)) ||
      ((param_1[3] != 0 || (param_1[4] != 0)))) ||
     ((param_1[5] != 0 || ((param_1[6] != 0 || (uVar1 = 1, param_1[7] != 0x100)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 402879d4 FUN_402879d4 */

/* Boundary evidence: original MIPS .pdata 402879d4..40287d33. Semantic name remains unreviewed. */

int FUN_402879d4(undefined4 *param_1,uint param_2,char *param_3,undefined *param_4,
                undefined4 *param_5)

{
  size_t sVar1;
  LPWSTR lpWideCharStr;
  DWORD dwErrCode;
  undefined4 *_Dst;
  int iVar2;
  int iVar3;
  uint local_res4;
  char *local_res8;
  undefined *local_resc;
  undefined4 *local_3c;
  int local_38;
  LPWSTR local_34;
  int local_30;
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  iVar2 = 0;
  _Dst = (undefined4 *)*param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  sVar1 = strlen(param_3);
  iVar3 = sVar1 + 1;
  local_38 = iVar3;
  lpWideCharStr = LocalAlloc(0x40,iVar3 * 2);
  local_34 = lpWideCharStr;
  if (lpWideCharStr == (LPWSTR)0x0) {
    dwErrCode = 8;
  }
  else {
    local_30 = MultiByteToWideChar(0,0,param_3,-1,lpWideCharStr,iVar3);
    if (local_30 == 0) {
      dwErrCode = 0x2afb;
    }
    else {
      memset(_Dst,0,0x3c);
      *_Dst = 0x3c;
      _Dst[1] = lpWideCharStr;
      _Dst[2] = param_4;
      if (param_4 == &DAT_4028b128) {
        _Dst[5] = 0xc;
      }
      else {
        _Dst[5] = 0;
      }
      _Dst[8] = 2;
      _Dst[9] = &DAT_4028b168;
      iVar3 = WSALookupServiceBeginW(_Dst,0x210,&local_3c);
      if (iVar3 == 0) {
        do {
          iVar3 = WSALookupServiceNextW(local_3c,0,(int)&local_res4,_Dst);
          if (iVar3 == 0) {
            iVar2 = _Dst[0xe];
            if ((iVar2 == 0) && (param_4 != (undefined *)0x4028b108)) {
              dwErrCode = 0x2afc;
            }
            else {
              dwErrCode = 0;
              if (param_5 != (undefined4 *)0x0) {
                *param_5 = _Dst[1];
              }
            }
            goto LAB_40287c84;
          }
          dwErrCode = GetLastError();
          if ((dwErrCode != 0x271e) || (local_res4 <= param_2)) goto LAB_40287c84;
          LocalFree((HLOCAL)*param_1);
          _Dst = LocalAlloc(0x40,local_res4);
          *param_1 = _Dst;
          param_2 = local_res4;
        } while (_Dst != (undefined4 *)0x0);
        dwErrCode = 8;
LAB_40287c84:
        WSALookupServiceEnd(local_3c);
      }
      else {
        dwErrCode = GetLastError();
      }
    }
    LocalFree(lpWideCharStr);
  }
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return iVar2;
}



/* 40287d34 FUN_40287d34 */

/* Boundary evidence: original MIPS .pdata 40287d34..40287d3f. Semantic name remains unreviewed. */

undefined4 FUN_40287d34(void)

{
  return 1;
}



/* 40287d40 FUN_40287d40 */

/* Boundary evidence: original MIPS .pdata 40287d40..40287d4b. Semantic name remains unreviewed. */

undefined4 FUN_40287d40(void)

{
  return 1;
}



/* 40287d4c FUN_40287d4c */

void FUN_40287d4c(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  *param_1 = *param_1 + (int)param_1;
  if (param_1[1] != 0) {
    piVar1 = (int *)(param_1[1] + (int)param_1);
    param_1[1] = (int)piVar1;
    iVar3 = 0;
    if (*piVar1 != 0) {
      iVar2 = 0;
      do {
        *(int *)(param_1[1] + iVar2) = *(int *)(param_1[1] + iVar2) + (int)param_1;
        iVar3 = iVar3 + 1;
        iVar2 = iVar3 * 4;
      } while (*(int *)(param_1[1] + iVar2) != 0);
    }
  }
  iVar3 = param_1[3];
  param_1[3] = iVar3 + (int)param_1;
  iVar2 = 0;
  if (*(int *)(iVar3 + (int)param_1) != 0) {
    iVar3 = 0;
    do {
      *(int *)(param_1[3] + iVar3) = *(int *)(param_1[3] + iVar3) + (int)param_1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar2 * 4;
    } while (*(int *)(param_1[3] + iVar3) != 0);
  }
  return;
}



/* 40287dfc FUN_40287dfc */

/* Boundary evidence: original MIPS .pdata 40287dfc..40287f77. Semantic name remains unreviewed. */

void FUN_40287dfc(undefined4 *param_1,int param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  char *_Dest;
  
  *(undefined2 *)(param_2 + 0x1c) = *(undefined2 *)(param_1 + 2);
  puVar3 = (undefined4 *)(param_2 + 0x2e4);
  *(undefined2 *)(param_2 + 0x1e) = *(undefined2 *)((int)param_1 + 10);
  *(undefined4 **)(param_2 + 0x20) = puVar3;
  puVar4 = (undefined4 *)(param_2 + 0x324);
  iVar5 = 0;
  if (*(int *)param_1[3] != 0) {
    iVar2 = 0;
    do {
      *puVar3 = puVar4;
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 1;
      *puVar4 = **(undefined4 **)(iVar2 + param_1[3]);
      iVar2 = iVar5 * 4;
      puVar4 = puVar4 + 1;
    } while (*(int *)(iVar2 + param_1[3]) != 0);
  }
  *(undefined4 *)((iVar5 + 0xb9) * 4 + param_2) = 0;
  *(char **)(param_2 + 0x14) = (char *)(param_2 + 100);
  strcpy((char *)(param_2 + 100),(char *)*param_1);
  sVar1 = strlen(*(char **)(param_2 + 0x14));
  iVar2 = 0x280 - (sVar1 + 1);
  puVar3 = (undefined4 *)(param_2 + 0x24);
  *(undefined4 **)(param_2 + 0x18) = puVar3;
  _Dest = (char *)(sVar1 + 1 + param_2 + 100);
  iVar5 = 0;
  puVar4 = (undefined4 *)param_1[1];
  while ((char *)*puVar4 != (char *)0x0) {
    sVar1 = strlen((char *)*puVar4);
    iVar6 = sVar1 + 1;
    if (iVar2 < iVar6) break;
    strcpy(_Dest,(char *)*puVar4);
    *puVar3 = _Dest;
    iVar5 = iVar5 + 1;
    _Dest = _Dest + iVar6;
    iVar2 = iVar2 - iVar6;
    puVar3 = puVar3 + 1;
    puVar4 = (undefined4 *)(iVar5 * 4 + param_1[1]);
  }
  *(undefined4 *)((iVar5 + 9) * 4 + param_2) = 0;
  return;
}



/* 40287f78 getservbyname */

/* Boundary evidence: original MIPS .pdata 40287f78..40287f9f. Semantic name remains unreviewed. */

servent * getservbyname(char *name,char *proto)

{
                    /* 0x7f78  60  getservbyname */
  SetLastError(0x2afb);
  return (servent *)0x0;
}



/* 40287fa0 getservbyport */

/* Boundary evidence: original MIPS .pdata 40287fa0..40287fc7. Semantic name remains unreviewed. */

servent * getservbyport(int port,char *proto)

{
                    /* 0x7fa0  61  getservbyport */
  SetLastError(0x2afb);
  return (servent *)0x0;
}



/* 40287fc8 gethostbyaddr */

/* Boundary evidence: original MIPS .pdata 40287fc8..4028810b. Semantic name remains unreviewed. */

hostent * gethostbyaddr(char *addr,int len,int type)

{
  int iVar1;
  hostent *phVar2;
  int *piVar3;
  DWORD dwErrCode;
  HLOCAL local_40;
  int local_3c;
  char acStack_38 [32];
  uint local_18;
  
                    /* 0x7fc8  53  gethostbyaddr */
  local_18 = DAT_4028b178;
  dwErrCode = 0;
  phVar2 = (hostent *)0x0;
  if (addr == (char *)0x0) {
    dwErrCode = 0x2726;
  }
  else {
    sprintf(acStack_38,"%u.%u.%u.%u",(uint)(byte)*addr,(uint)(byte)addr[1],(uint)(byte)addr[2],
            (uint)(byte)addr[3]);
    iVar1 = FUN_40284a24(&local_3c);
    if (iVar1 != 0) {
      local_40 = LocalAlloc(0x40,0x43c);
      if (local_40 != (HLOCAL)0x0) {
        iVar1 = FUN_402879d4(&local_40,0x43c,acStack_38,&DAT_4028b118,(undefined4 *)0x0);
        if (iVar1 == 0) {
          dwErrCode = GetLastError();
          if (dwErrCode == 0x277c) {
            dwErrCode = 0x2af9;
          }
        }
        else {
          piVar3 = *(int **)(iVar1 + 4);
          FUN_40287d4c(piVar3);
          FUN_40287dfc(piVar3,local_3c);
          phVar2 = (hostent *)(local_3c + 0x14);
        }
        LocalFree(local_40);
        goto LAB_402880d4;
      }
    }
    dwErrCode = 8;
  }
LAB_402880d4:
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  FUN_40289f58(local_18);
  return phVar2;
}



/* 4028810c gethostbyname */

/* Boundary evidence: original MIPS .pdata 4028810c..4028820f. Semantic name remains unreviewed. */

hostent * gethostbyname(char *name)

{
  int iVar1;
  int *piVar2;
  DWORD dwErrCode;
  hostent *phVar3;
  int local_18;
  HLOCAL local_14;
  
                    /* 0x810c  54  gethostbyname */
  dwErrCode = 0;
  phVar3 = (hostent *)0x0;
  if (name == (char *)0x0) {
    dwErrCode = 0x271e;
  }
  else {
    iVar1 = FUN_40284a24(&local_18);
    if ((iVar1 == 0) || (local_14 = LocalAlloc(0x40,0x43c), local_14 == (HLOCAL)0x0)) {
      dwErrCode = 8;
    }
    else {
      iVar1 = FUN_402879d4(&local_14,0x43c,name,&DAT_4028b128,(undefined4 *)0x0);
      if (iVar1 == 0) {
        dwErrCode = GetLastError();
        if (dwErrCode == 0x277c) {
          dwErrCode = 0x2af9;
        }
      }
      else {
        piVar2 = *(int **)(iVar1 + 4);
        FUN_40287d4c(piVar2);
        FUN_40287dfc(piVar2,local_18);
        phVar3 = (hostent *)(local_18 + 0x14);
      }
      LocalFree(local_14);
    }
    if (dwErrCode == 0) {
      return phVar3;
    }
  }
  SetLastError(dwErrCode);
  return phVar3;
}



/* 40288210 sethostname */

/* Boundary evidence: original MIPS .pdata 40288210..402882db. Semantic name remains unreviewed. */

undefined4 sethostname(int param_1,int param_2)

{
  DWORD dwErrCode;
  int iVar1;
  
                    /* 0x8210  79  sethostname */
  if (param_1 == 0) {
    dwErrCode = 0x271e;
  }
  else {
    if ((param_2 < 2) || (0x10 < param_2)) {
      dwErrCode = 0x2726;
    }
    else {
      iVar1 = WaitForAPIReady(0x53,0);
      if (iVar1 != 0) {
        dwErrCode = 0x2742;
        goto LAB_402882b0;
      }
      dwErrCode = (*(code *)&SUB_fffe6ff6)(0xffffffff,0x80,param_1,param_2,0,0,0);
    }
    if (dwErrCode == 0) {
      return 0;
    }
  }
LAB_402882b0:
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* 402882dc gethostname */

/* Boundary evidence: original MIPS .pdata 402882dc..402884c3. Semantic name remains unreviewed. */

int gethostname(char *name,int namelen)

{
  LSTATUS LVar1;
  DWORD dwErrCode;
  int iVar2;
  wchar_t *_Source;
  DWORD local_150 [3];
  HKEY local_144;
  wchar_t awStack_140 [12];
  wchar_t awStack_128 [128];
  uint local_28;
  
                    /* 0x82dc  55  gethostname */
  local_28 = DAT_4028b178;
  dwErrCode = 0x271e;
  local_150[1] = 0x271e;
  memcpy(awStack_140,L"WindowsCE",0x14);
  if ((0 < namelen) && (name != (char *)0x0)) {
    _Source = (wchar_t *)0x0;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0,&local_144);
    if (LVar1 == 0) {
      local_150[0] = 0x100;
      LVar1 = RegQueryValueExW(local_144,L"Name",(LPDWORD)0x0,local_150 + 2,(LPBYTE)awStack_128,
                               local_150);
      RegCloseKey(local_144);
      if ((LVar1 == 0) && (local_150[2] == 1)) {
        _Source = awStack_128;
        local_150[0] = (int)local_150[0] >> 1;
      }
    }
    if (_Source == (wchar_t *)0x0) {
      _Source = awStack_140;
      local_150[0] = 10;
    }
    if ((int)local_150[0] <= namelen) {
      wcstombs(name,_Source,local_150[0]);
      name[namelen + -1] = '\0';
      dwErrCode = 0;
      local_150[1] = 0;
    }
  }
  iVar2 = 0;
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
    iVar2 = -1;
  }
  FUN_40289f58(local_28);
  return iVar2;
}



/* 402884c4 FUN_402884c4 */

/* Boundary evidence: original MIPS .pdata 402884c4..402884cf. Semantic name remains unreviewed. */

undefined4 FUN_402884c4(void)

{
  return 1;
}



/* 402884d0 getprotobynumber */

/* Boundary evidence: original MIPS .pdata 402884d0..402884f7. Semantic name remains unreviewed. */

protoent * getprotobynumber(int proto)

{
                    /* 0x84d0  59  getprotobynumber */
  SetLastError(0x2afb);
  return (protoent *)0x0;
}



/* 402884f8 getprotobyname */

/* Boundary evidence: original MIPS .pdata 402884f8..4028851f. Semantic name remains unreviewed. */

protoent * getprotobyname(char *name)

{
                    /* 0x84f8  58  getprotobyname */
  SetLastError(0x2afb);
  return (protoent *)0x0;
}



/* 40288520 FUN_40288520 */

/* Boundary evidence: original MIPS .pdata 40288520..402885fb. Semantic name remains unreviewed. */

HLOCAL FUN_40288520(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  HLOCAL hMem;
  HLOCAL pvVar1;
  SIZE_T uBytes;
  undefined4 uVar2;
  
  hMem = LocalAlloc(0x40,0x20);
  if (hMem == (HLOCAL)0x0) {
    return (HLOCAL)0x0;
  }
  if (param_1 == 2) {
    uVar2 = 0x10;
    uBytes = 0x10;
  }
  else {
    if (param_1 != 0x17) goto LAB_402885a0;
    uVar2 = 0x1c;
    uBytes = 0x1c;
  }
  *(undefined4 *)((int)hMem + 0x10) = uVar2;
  pvVar1 = LocalAlloc(0x40,uBytes);
  *(HLOCAL *)((int)hMem + 0x18) = pvVar1;
LAB_402885a0:
  if (*(int *)((int)hMem + 0x18) == 0) {
    LocalFree(hMem);
    hMem = (HLOCAL)0x0;
  }
  else {
    *(int *)((int)hMem + 4) = param_1;
    *(undefined4 *)((int)hMem + 8) = param_2;
    *(undefined4 *)((int)hMem + 0xc) = param_3;
    *(HLOCAL *)*param_4 = hMem;
    *param_4 = (int)hMem + 0x1c;
  }
  return hMem;
}



/* 402885fc FUN_402885fc */

/* Boundary evidence: original MIPS .pdata 402885fc..402886cf. Semantic name remains unreviewed. */

undefined4 FUN_402885fc(int param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  
  iVar3 = *(int *)(param_1 + 0x2c);
  iVar6 = 0;
  if (iVar3 == 0) {
    iVar3 = 1;
  }
  piVar1 = LocalAlloc(0x40,(iVar3 + -1) * 8 + 0xc);
  iVar3 = *(int *)(param_1 + 0x2c);
  *param_3 = piVar1;
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x2747;
  }
  else {
    if (iVar3 != 0) {
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0x30) + 8);
      piVar5 = piVar1 + 1;
      do {
        if (param_2 == *(ushort *)*puVar4) {
          *piVar5 = (int)*puVar4;
          iVar6 = iVar6 + 1;
          piVar5[1] = puVar4[1];
          piVar5 = piVar5 + 2;
        }
        iVar3 = iVar3 + -1;
        puVar4 = puVar4 + 6;
      } while (iVar3 != 0);
    }
    *piVar1 = iVar6;
    uVar2 = 0;
  }
  if (iVar6 == 0) {
    uVar2 = 0x2afc;
  }
  return uVar2;
}



/* 402886d0 FUN_402886d0 */

/* Boundary evidence: original MIPS .pdata 402886d0..4028883b. Semantic name remains unreviewed. */

undefined4
FUN_402886d0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5,
            int *param_6)

{
  uint *puVar1;
  undefined4 uVar2;
  short *_Src;
  int *piVar3;
  size_t _Size;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  uVar2 = 0;
  _Size = 0x1c;
  if (param_2 != 0x17) {
    _Size = 0x10;
  }
  piVar3 = param_1 + 1;
  iVar5 = 0;
  if (0 < *param_1) {
    do {
      _Src = (short *)*piVar3;
      if (((_Src != (short *)0x0) && ((int)_Size <= piVar3[1])) && ((*_Src == 0x17 || (*_Src == 2)))
         ) {
        puVar1 = FUN_40288520(param_2,param_3,param_4,param_6);
        if (puVar1 == (uint *)0x0) {
          uVar2 = 8;
          break;
        }
        memcpy((void *)puVar1[6],_Src,_Size);
        iVar4 = iVar4 + 1;
        *(undefined2 *)(puVar1[6] + 2) = param_5;
        *puVar1 = *puVar1 | 4;
      }
      iVar5 = iVar5 + 1;
      piVar3 = piVar3 + 2;
    } while (iVar5 < *param_1);
    if (iVar4 != 0) {
      return uVar2;
    }
  }
  return 0x2afc;
}



/* 4028883c FUN_4028883c */

/* Boundary evidence: original MIPS .pdata 4028883c..40288a73. Semantic name remains unreviewed. */

DWORD FUN_4028883c(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4,uint param_5,
                  undefined4 *param_6,int *param_7)

{
  int iVar1;
  DWORD DVar2;
  size_t sVar3;
  STRSAFE_LPWSTR pszDest;
  undefined4 *_Dst;
  SIZE_T uBytes;
  uint local_res4 [3];
  undefined4 *local_30 [2];
  
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  _Dst = (undefined4 *)*param_1;
  local_res4[0] = param_2;
  memset(_Dst,0,0x3c);
  *_Dst = 0x3c;
  _Dst[1] = param_3;
  _Dst[2] = param_4;
  _Dst[5] = 0xc;
  iVar1 = WSALookupServiceBeginW(_Dst,param_5,local_30);
  if (iVar1 == 0) {
    do {
      iVar1 = WSALookupServiceNextW(local_30[0],0,(int)local_res4,_Dst);
      if (iVar1 == 0) {
        DVar2 = 0;
        if (((param_5 & 0x100) != 0) && (_Dst[0xb] == 0)) {
          DVar2 = 0x2afc;
        }
        if (((((param_5 & 0x10) != 0) && (param_7 != (int *)0x0)) && (*param_7 == 0)) &&
           ((wchar_t *)_Dst[1] != (wchar_t *)0x0)) {
          sVar3 = wcslen((wchar_t *)_Dst[1]);
          uBytes = (sVar3 + 1) * 2;
          pszDest = LocalAlloc(0x40,uBytes);
          *param_7 = (int)pszDest;
          if (pszDest != (STRSAFE_LPWSTR)0x0) {
            StringCbCopyW(pszDest,uBytes,(STRSAFE_LPCWSTR)_Dst[1]);
          }
        }
        if ((param_5 & 0x200) != 0) {
          if (_Dst[0xe] == 0) {
            if (param_4 == 0x4028b108) {
              if (param_6 != (undefined4 *)0x0) {
                *param_6 = _Dst[1];
              }
            }
            else {
              DVar2 = 0x2afc;
            }
          }
          else if (param_6 != (undefined4 *)0x0) {
            *param_6 = _Dst[1];
          }
        }
        goto LAB_40288a20;
      }
      DVar2 = GetLastError();
      if ((DVar2 != 0x271e) || (local_res4[0] <= param_2)) goto LAB_40288a20;
      LocalFree((HLOCAL)*param_1);
      _Dst = LocalAlloc(0x40,local_res4[0]);
      *param_1 = _Dst;
      param_2 = local_res4[0];
    } while (_Dst != (undefined4 *)0x0);
    DVar2 = 8;
LAB_40288a20:
    WSALookupServiceEnd(local_30[0]);
  }
  else {
    DVar2 = GetLastError();
  }
  return DVar2;
}



/* 40288a74 FUN_40288a74 */

int FUN_40288a74(char *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (; ((cVar1 = *param_1, cVar1 == ' ' || (cVar1 == '\t')) || (cVar1 == '\n'));
      param_1 = param_1 + 1) {
  }
  cVar1 = *param_1;
  while ((iVar2 = (int)cVar1, 0x2f < iVar2 && (iVar2 < 0x3a))) {
    param_1 = param_1 + 1;
    iVar3 = iVar3 * 10 + iVar2 + -0x30;
    cVar1 = *param_1;
  }
  *param_2 = param_1;
  return iVar3;
}



/* 40288af8 FUN_40288af8 */

/* Boundary evidence: original MIPS .pdata 40288af8..40288bb3. Semantic name remains unreviewed. */

undefined4 FUN_40288af8(uint param_1,char *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  char local_19 [9];
  uint local_10;
  
  local_10 = DAT_4028b178;
  uVar3 = 0;
  iVar2 = 0;
  do {
    local_19[iVar2 + 1] = (char)((int)param_1 % 10) + '0';
    param_1 = (int)param_1 / 10 & 0xffff;
    iVar2 = iVar2 + 1;
  } while (param_1 != 0);
  while ((iVar2 != 0 && (bVar1 = param_3 != 0, param_3 = param_3 + -1, bVar1))) {
    *param_2 = local_19[iVar2];
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  }
  if (param_3 < 1) {
    uVar3 = 8;
  }
  else {
    *param_2 = '\0';
  }
  FUN_40289f58(local_10);
  return uVar3;
}



/* 40288bb4 FUN_40288bb4 */

/* Boundary evidence: original MIPS .pdata 40288bb4..40288bfb. Semantic name remains unreviewed. */

bool FUN_40288bb4(void)

{
  SOCKET s;
  
  s = socket(0x17,2,0);
  if (s != 0xffffffff) {
    closesocket(s);
  }
  return s != 0xffffffff;
}



/* 40288bfc FUN_40288bfc */

/* Boundary evidence: original MIPS .pdata 40288bfc..40288c8f. Semantic name remains unreviewed. */

undefined4 FUN_40288bfc(int *param_1)

{
  SOCKET s;
  uint local_18 [2];
  
  s = socket(0x17,2,0);
  if (s != 0xffffffff) {
    local_18[0] = *param_1 * 8 + 4;
    WSAIoctl(s,-0x37ffffe7,param_1,local_18[0],param_1,local_18[0],local_18,0,0);
    closesocket(s);
  }
  return 0;
}



/* 40288c90 FUN_40288c90 */

/* Boundary evidence: original MIPS .pdata 40288c90..40288d13. Semantic name remains unreviewed. */

undefined4 FUN_40288c90(int param_1)

{
  HLOCAL pvVar1;
  DWORD DVar2;
  int *piVar3;
  
  pvVar1 = LocalAlloc(0x40,0x43c);
  *(undefined4 *)(param_1 + 0x14) = pvVar1;
  if (pvVar1 == (HLOCAL)0x0) {
    *(undefined4 *)(param_1 + 4) = 8;
  }
  else {
    piVar3 = (int *)(param_1 + 0x10);
    if ((*(uint *)(param_1 + 8) & 2) == 0) {
      piVar3 = (int *)0x0;
    }
    DVar2 = FUN_4028883c((undefined4 *)(param_1 + 0x14),0x43c,*(undefined4 *)(param_1 + 0xc),
                         0x4028b158,0x110,(undefined4 *)0x0,piVar3);
    *(DWORD *)(param_1 + 4) = DVar2;
  }
  return 0;
}



/* 40288d14 FUN_40288d14 */

/* Boundary evidence: original MIPS .pdata 40288d14..40288d77. Semantic name remains unreviewed. */

undefined4 FUN_40288d14(undefined4 *param_1)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40288c90,param_1,0,(LPDWORD)0x0);
  param_1[6] = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    uVar2 = 8;
  }
  else {
    *param_1 = 1;
    FUN_40283a54(pvVar1);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40288d78 FUN_40288d78 */

/* Boundary evidence: original MIPS .pdata 40288d78..40288e93. Semantic name remains unreviewed. */

int FUN_40288d78(int param_1)

{
  int iVar1;
  LPSTR lpMultiByteStr;
  int iVar2;
  SIZE_T local_a0 [2];
  WCHAR aWStack_98 [66];
  uint local_14;
  
  local_14 = DAT_4028b178;
  iVar2 = 0;
  local_a0[0] = 0x41;
  iVar1 = WSAAddressToStringW(*(ushort **)(param_1 + 0x18),*(uint *)(param_1 + 0x10),
                              (undefined1 *)0x0,(int)aWStack_98,(int)local_a0);
  if (iVar1 == -1) {
    iVar2 = WSAGetLastError();
    goto LAB_40288e70;
  }
  local_a0[0] = local_a0[0] << 1;
  lpMultiByteStr = LocalAlloc(0x40,local_a0[0]);
  *(LPSTR *)(param_1 + 0x14) = lpMultiByteStr;
  if (lpMultiByteStr != (LPSTR)0x0) {
    iVar1 = WideCharToMultiByte(0xfde9,0,aWStack_98,-1,lpMultiByteStr,local_a0[0],(LPCSTR)0x0,
                                (LPBOOL)0x0);
    if (iVar1 != 0) goto LAB_40288e70;
    iVar1 = WideCharToMultiByte(0,0,aWStack_98,-1,*(LPSTR *)(param_1 + 0x14),local_a0[0],(LPCSTR)0x0
                                ,(LPBOOL)0x0);
    if (iVar1 != 0) goto LAB_40288e70;
  }
  iVar2 = 8;
LAB_40288e70:
  FUN_40289f58(local_14);
  return iVar2;
}



/* 40288e94 FUN_40288e94 */

/* Boundary evidence: original MIPS .pdata 40288e94..40288f7f. Semantic name remains unreviewed. */

undefined4 FUN_40288e94(int param_1,wchar_t *param_2)

{
  size_t sVar1;
  LPSTR lpMultiByteStr;
  int iVar2;
  SIZE_T uBytes;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    return 0;
  }
  sVar1 = wcslen(param_2);
  uBytes = (sVar1 + 1) * 2;
  lpMultiByteStr = LocalAlloc(0x40,uBytes);
  *(LPSTR *)(param_1 + 0x14) = lpMultiByteStr;
  if (lpMultiByteStr != (LPSTR)0x0) {
    iVar2 = WideCharToMultiByte(0xfde9,0,param_2,-1,lpMultiByteStr,uBytes,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar2 != 0) {
      return 0;
    }
    iVar2 = WideCharToMultiByte(0,0,param_2,-1,*(LPSTR *)(param_1 + 0x14),uBytes,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    if (iVar2 != 0) {
      return 0;
    }
  }
  return 8;
}



/* 40288f80 getnameinfo */

/* Boundary evidence: original MIPS .pdata 40288f80..40289323. Semantic name remains unreviewed. */

DWORD getnameinfo(ushort *param_1,uint param_2,LPSTR param_3,uint param_4,char *param_5,int param_6,
                 uint param_7)

{
  ushort uVar1;
  WCHAR WVar2;
  u_short uVar3;
  undefined2 extraout_var;
  int iVar4;
  WCHAR *pWVar5;
  DWORD dwErrCode;
  uint uVar6;
  HLOCAL hMem;
  LPCWSTR lpWideCharStr;
  HLOCAL local_e0;
  undefined4 local_dc;
  ushort auStack_d8 [16];
  WCHAR local_b8 [68];
  uint local_30;
  
                    /* 0x8f80  56  getnameinfo */
  local_30 = DAT_4028b178;
  if ((param_1 == (ushort *)0x0) || (param_2 < 0x10)) {
    dwErrCode = 0x271e;
LAB_402892d4:
    if (dwErrCode == 0) goto LAB_402892ec;
  }
  else {
    uVar1 = *param_1;
    if ((uVar1 == 2) || (uVar1 == 0x17)) {
      if ((uVar1 == 0x17) && (param_2 < 0x1c)) {
LAB_40289014:
        dwErrCode = 0x271e;
      }
      else {
        dwErrCode = 0;
        if (param_5 != (char *)0x0) {
          if ((param_7 & 8) == 0) {
            dwErrCode = 0x2afc;
          }
          else {
            uVar3 = htons(param_1[1]);
            dwErrCode = FUN_40288af8(CONCAT22(extraout_var,uVar3),param_5,param_6);
          }
          if (dwErrCode != 0) goto LAB_402892dc;
        }
        if (param_3 == (LPSTR)0x0) goto LAB_402892ec;
        local_dc = 0x43;
        lpWideCharStr = local_b8;
        if (*param_1 == 2) {
          uVar6 = 0x10;
LAB_402890a4:
          if (((int)param_2 < (int)uVar6) ||
             (iVar4 = CeSafeCopyMemory(auStack_d8,param_1,uVar6), iVar4 == 0)) goto LAB_40289014;
          auStack_d8[1] = 0;
          iVar4 = WSAAddressToStringW(auStack_d8,uVar6,(undefined1 *)0x0,(int)local_b8,
                                      (int)&local_dc);
        }
        else {
          if (*param_1 == 0x17) {
            uVar6 = 0x1c;
            goto LAB_402890a4;
          }
          iVar4 = WSAAddressToStringW(param_1,param_2,(undefined1 *)0x0,(int)local_b8,(int)&local_dc
                                     );
        }
        if (iVar4 == 0) {
          dwErrCode = 0;
          hMem = (HLOCAL)0x0;
          if ((param_7 & 2) == 0) {
            if (*param_1 == 0x17) {
              iVar4 = FUN_40287964((short *)(param_1 + 4));
              if (iVar4 == 0) {
                dwErrCode = 0x2afc;
              }
              else {
                if (9 < param_4) {
                  memcpy(param_3,"localhost",param_4);
                  goto LAB_402892ec;
                }
                dwErrCode = 8;
              }
              goto LAB_402892dc;
            }
            local_e0 = LocalAlloc(0x40,0x43c);
            if (local_e0 == (HLOCAL)0x0) {
              dwErrCode = 8;
            }
            else {
              dwErrCode = FUN_4028883c(&local_e0,0x43c,local_b8,0x4028b118,0x10,(undefined4 *)0x0,
                                       (int *)0x0);
              if (dwErrCode == 0) {
                lpWideCharStr = *(LPCWSTR *)((int)local_e0 + 4);
              }
              else if ((param_7 & 4) != 0) {
                dwErrCode = 0x2af9;
              }
            }
            hMem = local_e0;
            if (dwErrCode == 0) goto LAB_40289208;
          }
          else {
LAB_40289208:
            if (((param_7 & 1) != 0) && ((param_7 & 2) == 0)) {
              WVar2 = *lpWideCharStr;
              pWVar5 = lpWideCharStr;
              while (WVar2 != L'\0') {
                if (*pWVar5 == L'.') {
                  *pWVar5 = L'\0';
                }
                else {
                  pWVar5 = pWVar5 + 1;
                }
                WVar2 = *pWVar5;
              }
            }
            iVar4 = WideCharToMultiByte(0xfde9,0,lpWideCharStr,-1,param_3,param_4,(LPCSTR)0x0,
                                        (LPBOOL)0x0);
            if ((iVar4 == 0) &&
               (iVar4 = WideCharToMultiByte(0,0,lpWideCharStr,-1,param_3,param_4,(LPCSTR)0x0,
                                            (LPBOOL)0x0), iVar4 == 0)) {
              dwErrCode = 8;
            }
          }
          if (hMem != (HLOCAL)0x0) {
            LocalFree(hMem);
          }
          goto LAB_402892d4;
        }
        dwErrCode = 0x2afb;
      }
    }
    else {
      dwErrCode = 0x273f;
    }
  }
LAB_402892dc:
  SetLastError(dwErrCode);
LAB_402892ec:
  FUN_40289f58(local_30);
  return dwErrCode;
}



/* 40289324 freeaddrinfo */

/* Boundary evidence: original MIPS .pdata 40289324..40289387. Semantic name remains unreviewed. */

void freeaddrinfo(HLOCAL param_1)

{
  HLOCAL pvVar1;
  
                    /* 0x9324  51  freeaddrinfo */
  while (param_1 != (HLOCAL)0x0) {
    pvVar1 = *(HLOCAL *)((int)param_1 + 0x1c);
    if (*(HLOCAL *)((int)param_1 + 0x18) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)((int)param_1 + 0x18));
    }
    if (*(HLOCAL *)((int)param_1 + 0x14) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)((int)param_1 + 0x14));
    }
    LocalFree(param_1);
    param_1 = pvVar1;
  }
  return;
}



/* 40289388 getaddrinfo */

/* Boundary evidence: original MIPS .pdata 40289388..40289cf3. Semantic name remains unreviewed. */

DWORD getaddrinfo(char *param_1,char *param_2,uint *param_3,int *param_4)

{
  int *piVar1;
  LPWSTR pWVar2;
  bool bVar3;
  int iVar4;
  undefined3 extraout_var;
  HLOCAL pvVar5;
  int iVar6;
  uint *puVar7;
  u_long uVar8;
  size_t _Size;
  undefined *puVar9;
  DWORD DVar10;
  undefined2 *puVar11;
  int *hMem;
  short sVar12;
  wchar_t **ppwVar13;
  uint uVar14;
  uint uVar15;
  u_short local_78;
  uint local_74;
  int *local_70;
  int *local_6c;
  HLOCAL local_68;
  uint local_64;
  size_t local_60;
  LPWSTR local_5c;
  HLOCAL local_58;
  int local_54;
  wchar_t *local_50;
  int *local_4c;
  short local_48;
  u_short local_46;
  uint local_2c;
  
                    /* 0x9388  52  getaddrinfo */
  local_2c = DAT_4028b178;
  local_64 = 0;
  local_78 = 0;
  sVar12 = 0;
  local_74 = 0;
  uVar14 = 0;
  local_68 = (HLOCAL)0x0;
  hMem = (int *)0x0;
  local_50 = (wchar_t *)0x0;
  ppwVar13 = (wchar_t **)0x0;
  local_6c = param_4;
  if (param_4 == (int *)0x0) {
    DVar10 = 0x271e;
  }
  else {
    *param_4 = 0;
    DVar10 = 0;
    local_70 = param_4;
    local_4c = param_4;
    if ((param_1 == (char *)0x0) && (param_2 == (char *)0x0)) {
      DVar10 = 0x2af9;
    }
    else {
      uVar15 = 2;
      if (param_3 != (uint *)0x0) {
        if ((((param_3[4] == 0) && (param_3[5] == 0)) && (param_3[6] == 0)) && (param_3[7] == 0)) {
          uVar14 = *param_3;
          if (((uVar14 & 2) == 0) || (param_1 != (char *)0x0)) {
            sVar12 = (short)param_3[1];
            if ((sVar12 == 0) || ((sVar12 == 2 || (sVar12 == 0x17)))) {
              local_74 = param_3[2];
              if ((local_74 == 0) || ((local_74 == 1 || (local_74 == 2)))) {
                local_64 = param_3[3];
              }
              else {
                DVar10 = 0x273c;
              }
            }
            else {
              DVar10 = 0x273f;
            }
          }
          else {
            DVar10 = 0x2726;
          }
        }
        else {
          DVar10 = 0x2afb;
        }
      }
      if (param_2 != (char *)0x0) {
        iVar4 = FUN_40288a74(param_2,&local_54);
        local_78 = htons((u_short)iVar4);
      }
      if (DVar10 == 0) {
        bVar3 = FUN_40288bb4();
        local_54 = CONCAT31(extraout_var,bVar3);
        if (param_1 == (char *)0x0) {
          if (((sVar12 == 0) || (sVar12 == 0x17)) && (local_54 != 0)) {
            pvVar5 = FUN_40288520(0x17,local_74,local_64,(int *)&local_70);
            if (pvVar5 != (HLOCAL)0x0) {
              puVar11 = *(undefined2 **)((int)pvVar5 + 0x18);
              *puVar11 = 0x17;
              puVar11[1] = 0;
              *(undefined4 *)(puVar11 + 2) = 0;
              if ((uVar14 & 1) == 0) {
                memset(puVar11 + 4,0,0x10);
                *(undefined1 *)((int)puVar11 + 0x17) = 1;
              }
              else {
                memset(puVar11 + 4,0,0x10);
              }
              *(undefined4 *)(puVar11 + 0xc) = 0;
              puVar11[1] = local_78;
              goto LAB_40289650;
            }
LAB_40289644:
            DVar10 = 8;
            goto LAB_40289430;
          }
LAB_40289650:
          if ((sVar12 == 0) || (sVar12 == 2)) {
            pvVar5 = FUN_40288520(2,local_74,local_64,(int *)&local_70);
            if (pvVar5 == (HLOCAL)0x0) goto LAB_40289644;
            puVar11 = *(undefined2 **)((int)pvVar5 + 0x18);
            *puVar11 = 2;
            if ((uVar14 & 1) == 0) {
              uVar8 = 0x7f000001;
            }
            else {
              uVar8 = 0;
            }
            uVar8 = htonl(uVar8);
            *(u_long *)(puVar11 + 2) = uVar8;
            puVar11[1] = local_78;
          }
        }
        else {
          local_60 = strlen(param_1);
          local_60 = local_60 + 1;
          if (0x100 < (int)local_60) {
            DVar10 = 0x2afb;
            goto LAB_40289430;
          }
          local_5c = LocalAlloc(0x40,local_60 * 2);
          if (local_5c == (LPWSTR)0x0) goto LAB_40289c8c;
          iVar6 = MultiByteToWideChar(0,0,param_1,-1,local_5c,local_60);
          iVar4 = local_54;
          if (iVar6 == 0) {
            DVar10 = 0x2afb;
          }
          else if (((sVar12 == 0) || (sVar12 == 0x17)) && (local_54 != 0)) {
            local_60 = 0x1c;
            local_48 = 0x17;
            iVar6 = WSAStringToAddressW(local_5c,0x17,(undefined1 *)0x0,&local_48,(int)&local_60);
            if (iVar6 == -1) goto LAB_402897e4;
            puVar7 = FUN_40288520((int)local_48,local_74,local_64,(int *)&local_70);
            _Size = local_60;
            if (puVar7 == (uint *)0x0) goto LAB_40289c8c;
LAB_402897b0:
            local_46 = local_78;
            memcpy((void *)puVar7[6],&local_48,_Size);
            *puVar7 = *puVar7 | 4;
            if ((uVar14 & 2) != 0) {
              DVar10 = FUN_40288d78((int)puVar7);
            }
          }
          else {
LAB_402897e4:
            if ((sVar12 == 0) || (sVar12 == 2)) {
              local_60 = 0x10;
              local_48 = 2;
              iVar6 = WSAStringToAddressW(local_5c,2,(undefined1 *)0x0,&local_48,(int)&local_60);
              if (iVar6 != -1) {
                puVar7 = FUN_40288520(2,local_74,local_64,(int *)&local_70);
                if (puVar7 == (uint *)0x0) goto LAB_40289c8c;
                _Size = local_60;
                if (0xf < local_60) {
                  _Size = 0x10;
                }
                goto LAB_402897b0;
              }
            }
            if ((uVar14 & 4) == 0) {
              local_68 = LocalAlloc(0x40,0x43c);
              local_58 = local_68;
              if (local_68 == (HLOCAL)0x0) {
LAB_40289c8c:
                DVar10 = 8;
              }
              else {
                if ((uVar14 & 2) != 0) {
                  ppwVar13 = &local_50;
                }
                if (sVar12 == 0) {
                  if (iVar4 != 0) {
                    hMem = LocalAlloc(0,0x1c);
                    pWVar2 = local_5c;
                    if (hMem == (int *)0x0) goto LAB_40289c8c;
                    *hMem = 0;
                    hMem[1] = 0;
                    hMem[2] = uVar14;
                    hMem[3] = (int)local_5c;
                    hMem[4] = 0;
                    hMem[6] = 0;
                    iVar4 = FUN_40288d14(hMem);
                    if (iVar4 == 8) {
                      if ((HANDLE)hMem[6] != (HANDLE)0x0) {
                        CloseHandle((HANDLE)hMem[6]);
                        hMem[6] = 0;
                      }
                      DVar10 = FUN_4028883c(&local_58,0x43c,pWVar2,0x4028b158,0x110,
                                            (undefined4 *)0x0,(int *)ppwVar13);
                      local_68 = local_58;
                      if ((DVar10 == 0) &&
                         (iVar4 = FUN_402885fc((int)local_58,0x17,&local_70), piVar1 = local_70,
                         iVar4 == 0)) {
                        FUN_40288bfc(local_70);
                        FUN_402886d0(piVar1,0x17,local_74,local_64,local_78,(int *)&local_6c);
                        LocalFree(piVar1);
                        param_4 = local_6c;
                        if (((uVar14 & 2) != 0) && (*ppwVar13 != (wchar_t *)0x0)) {
                          FUN_40288e94(*local_4c,local_50);
                          uVar14 = 0;
                          param_4 = local_6c;
                        }
                      }
                      if ((ppwVar13 != (wchar_t **)0x0) && (*ppwVar13 != (wchar_t *)0x0)) {
                        LocalFree(*ppwVar13);
                        *ppwVar13 = (wchar_t *)0x0;
                      }
                    }
                  }
LAB_40289a60:
                  puVar9 = &DAT_4028b128;
                }
                else {
                  if ((sVar12 != 0x17) || (iVar4 == 0)) {
                    if (sVar12 != 2) {
                      DVar10 = 0x273f;
                      goto LAB_40289c90;
                    }
                    goto LAB_40289a60;
                  }
                  puVar9 = &DAT_4028b158;
                  uVar15 = 0x17;
                }
                memset(local_68,0,0x43c);
                DVar10 = FUN_4028883c(&local_58,0x43c,local_5c,(int)puVar9,0x110,(undefined4 *)0x0,
                                      (int *)ppwVar13);
                if ((hMem != (int *)0x0) && (*hMem != 0)) {
                  if ((HANDLE)hMem[6] != (HANDLE)0x0) {
                    WaitForSingleObject((HANDLE)hMem[6],0xffffffff);
                    CloseHandle((HANDLE)hMem[6]);
                    if (hMem[1] == 0) {
                      iVar4 = FUN_402885fc(hMem[5],0x17,&local_70);
                      piVar1 = local_70;
                      hMem[1] = iVar4;
                      if (iVar4 == 0) {
                        FUN_40288bfc(local_70);
                        iVar4 = FUN_402886d0(piVar1,0x17,local_74,local_64,local_78,(int *)&local_6c
                                            );
                        hMem[1] = iVar4;
                        LocalFree(piVar1);
                        param_4 = local_6c;
                        if (((uVar14 & 2) != 0) && ((wchar_t *)hMem[4] != (wchar_t *)0x0)) {
                          FUN_40288e94(*local_4c,(wchar_t *)hMem[4]);
                          uVar14 = 0;
                          param_4 = local_6c;
                        }
                      }
                    }
                    if ((HLOCAL)hMem[4] != (HLOCAL)0x0) {
                      LocalFree((HLOCAL)hMem[4]);
                      hMem[4] = 0;
                    }
                  }
                  if ((HLOCAL)hMem[5] != (HLOCAL)0x0) {
                    LocalFree((HLOCAL)hMem[5]);
                  }
                }
                local_68 = local_58;
                if ((DVar10 == 0) &&
                   (DVar10 = FUN_402885fc((int)local_58,uVar15,&local_70), piVar1 = local_70,
                   DVar10 == 0)) {
                  if ((local_54 != 0) && (uVar15 == 0x17)) {
                    FUN_40288bfc(local_70);
                  }
                  DVar10 = FUN_402886d0(piVar1,uVar15,local_74,local_64,local_78,(int *)&local_6c);
                  LocalFree(piVar1);
                  param_4 = local_6c;
                  if (ppwVar13 == (wchar_t **)0x0) goto LAB_40289c90;
                  if ((*ppwVar13 != (wchar_t *)0x0) && ((uVar14 & 2) != 0)) {
                    FUN_40288e94(*local_4c,local_50);
                    param_4 = local_6c;
                  }
                }
                if ((ppwVar13 != (wchar_t **)0x0) && (*ppwVar13 != (wchar_t *)0x0)) {
                  LocalFree(*ppwVar13);
                  *ppwVar13 = (wchar_t *)0x0;
                }
              }
            }
            else {
              DVar10 = 0x2af9;
            }
          }
LAB_40289c90:
          if (local_5c != (LPWSTR)0x0) {
            LocalFree(local_5c);
          }
          if ((((hMem == (int *)0x0) || (*hMem == 0)) && (DVar10 != 0)) ||
             (((hMem != (int *)0x0 && (*hMem == 1)) && ((DVar10 != 0 && (hMem[1] != 0))))))
          goto LAB_40289430;
        }
        DVar10 = 0;
        goto LAB_40289460;
      }
    }
LAB_40289430:
    if ((param_4 != (int *)0x0) && ((HLOCAL)*param_4 != (HLOCAL)0x0)) {
      freeaddrinfo((HLOCAL)*param_4);
      *param_4 = 0;
    }
  }
  SetLastError(DVar10);
LAB_40289460:
  if (hMem != (int *)0x0) {
    LocalFree(hMem);
  }
  if (local_68 != (HLOCAL)0x0) {
    LocalFree(local_68);
  }
  FUN_40289f58(local_2c);
  return DVar10;
}



/* 40289df4 entry */

/* Boundary evidence: original MIPS .pdata 40289df4..40289e67. Semantic name remains unreviewed. */

undefined4 entry(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_40289e68();
    FUN_4028a1b8();
  }
  uVar1 = FUN_40284acc(param_1,param_2);
  if (param_2 == 0) {
    FUN_4028a140();
  }
  return uVar1;
}



/* 40289e68 FUN_40289e68 */

/* Boundary evidence: original MIPS .pdata 40289e68..40289edb. Semantic name remains unreviewed. */

void FUN_40289e68(void)

{
  uint uVar1;
  
  if ((DAT_4028b178 == 0) || (DAT_4028b178 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4028b178 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4028b178 == 0) {
      DAT_4028b178 = 0xb064;
    }
  }
  DAT_4028b17c = ~DAT_4028b178;
  return;
}



/* 40289edc FUN_40289edc */

/* Boundary evidence: original MIPS .pdata 40289edc..40289f57. Semantic name remains unreviewed. */

void FUN_40289edc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_40289fa0(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 40289f58 FUN_40289f58 */

/* Boundary evidence: original MIPS .pdata 40289f58..40289f9f. Semantic name remains unreviewed. */

void FUN_40289f58(uint param_1)

{
  if ((param_1 == DAT_4028b178) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40289fa0 FUN_40289fa0 */

/* Boundary evidence: original MIPS .pdata 40289fa0..40289ff3. Semantic name remains unreviewed. */

void FUN_40289fa0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40289f58(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40289ff4 FUN_40289ff4 */

/* Boundary evidence: original MIPS .pdata 40289ff4..4028a01f. Semantic name remains unreviewed. */

undefined4 FUN_40289ff4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40289fa0(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 4028a020 FUN_4028a020 */

/* Boundary evidence: original MIPS .pdata 4028a020..4028a13f. Semantic name remains unreviewed. */

void FUN_4028a020(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4028b184 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_4028b36c;
    if (DAT_4028b36c != (undefined4 *)0x0) {
      while (DAT_4028b368 = DAT_4028b368 + -1, _Memory <= DAT_4028b368) {
        if ((code *)*DAT_4028b368 != (code *)0x0) {
          (*(code *)*DAT_4028b368)();
          _Memory = DAT_4028b36c;
        }
      }
      free(_Memory);
      DAT_4028b368 = (undefined4 *)0x0;
      DAT_4028b36c = (undefined4 *)0x0;
    }
    FUN_4028a164((undefined4 *)&DAT_40281010,(undefined4 *)&DAT_40281014);
  }
  FUN_4028a164((undefined4 *)&DAT_40281018,(undefined4 *)&DAT_4028101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_4028b370,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 4028a140 FUN_4028a140 */

/* Boundary evidence: original MIPS .pdata 4028a140..4028a163. Semantic name remains unreviewed. */

void FUN_4028a140(void)

{
  FUN_4028a020(0,0,1);
  return;
}



/* 4028a164 FUN_4028a164 */

/* Boundary evidence: original MIPS .pdata 4028a164..4028a1b7. Semantic name remains unreviewed. */

void FUN_4028a164(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4028a1b8 FUN_4028a1b8 */

/* Boundary evidence: original MIPS .pdata 4028a1b8..4028a1f3. Semantic name remains unreviewed. */

void FUN_4028a1b8(void)

{
  FUN_4028a164((undefined4 *)&DAT_40281008,(undefined4 *)&DAT_4028100c);
  FUN_4028a164((undefined4 *)&DAT_40281000,(undefined4 *)&DAT_40281004);
  return;
}


