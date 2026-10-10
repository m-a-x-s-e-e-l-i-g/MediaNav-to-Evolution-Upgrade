/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c05427a0 FUN_c05427a0 */

/* Boundary evidence: original MIPS .pdata c05427a0..c05427ef. Semantic name remains unreviewed. */

void * FUN_c05427a0(size_t param_1)

{
  void *_Dst;
  
  _Dst = (void *)CTEAllocMem(param_1);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}



/* c05427f0 EthCreateFilter */

/* Boundary evidence: original MIPS .pdata c05427f0..c05428ab. Semantic name remains unreviewed. */

bool EthCreateFilter(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  void *_Dst;
  
                    /* 0x27f0  4  EthCreateFilter */
  _Dst = FUN_c05427a0(0x68);
  *param_3 = _Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x68);
    *(undefined4 *)((int)_Dst + 0x30) = *param_2;
    uVar1 = *(undefined1 *)((int)param_2 + 5);
    *(undefined1 *)((int)_Dst + 0x34) = *(undefined1 *)(param_2 + 1);
    *(undefined1 *)((int)_Dst + 0x35) = uVar1;
    *(undefined4 *)((int)_Dst + 0x40) = param_1;
    InitializeCriticalSection((LPCRITICAL_SECTION)((int)_Dst + 4));
  }
  return _Dst != (void *)0x0;
}



/* c05428ac EthDeleteFilter */

/* Boundary evidence: original MIPS .pdata c05428ac..c05428ef. Semantic name remains unreviewed. */

void EthDeleteFilter(int param_1)

{
                    /* 0x28ac  5  EthDeleteFilter */
  if (*(int *)(param_1 + 0x38) != 0) {
    CTEFreeMem();
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  CTEFreeMem(param_1);
  return;
}



/* c05428f0 FUN_c05428f0 */

/* Boundary evidence: original MIPS .pdata c05428f0..c0542a2b. Semantic name remains unreviewed. */

void FUN_c05428f0(int param_1,int param_2,int param_3,int param_4)

{
  undefined2 local_20 [4];
  
  if (param_4 == 0) {
    local_20[0] = 1;
    (**(code **)(*(int *)(param_1 + 0x18) + 0x1e4))(param_1,local_20);
  }
  if (param_3 == 0) {
    param_3 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0x3c) != 0) {
      CTEFreeMem();
      *(undefined4 *)(param_1 + 0x3c) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
    }
    if ((param_3 != 0) && (*(int *)(param_3 + 0x28) != 0)) {
      CTEFreeMem();
      *(undefined4 *)(param_3 + 0x28) = 0;
      *(undefined4 *)(param_3 + 0x2c) = 0;
    }
  }
  else {
    if (param_3 != 0) {
      if (*(int *)(param_3 + 0x20) != 0) {
        CTEFreeMem();
      }
      *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(param_3 + 0x28);
      *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(param_3 + 0x2c);
      *(undefined4 *)(param_3 + 0x28) = 0;
      *(undefined4 *)(param_3 + 0x2c) = 0;
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      CTEFreeMem();
    }
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x3c);
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x48);
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  if (param_4 == 0) {
    (**(code **)(*(int *)(param_1 + 0x18) + 0x1e4))(param_1,local_20);
  }
  return;
}



/* c0542a2c EthNumberOfOpenFilterAddresses */

undefined4 EthNumberOfOpenFilterAddresses(undefined4 param_1,int param_2)

{
                    /* 0x2a2c  9  EthNumberOfOpenFilterAddresses */
  return *(undefined4 *)(param_2 + 0x24);
}



/* c0542a34 EthQueryOpenFilterAddresses */

/* Boundary evidence: original MIPS .pdata c0542a34..c0542ad7. Semantic name remains unreviewed. */

void EthQueryOpenFilterAddresses
               (undefined4 *param_1,int param_2,int param_3,uint param_4,undefined4 *param_5,
               void *param_6)

{
  size_t _Size;
  
                    /* 0x2a34  11  EthQueryOpenFilterAddresses */
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
  _Size = *(int *)(param_3 + 0x24) * 6;
  if (param_4 < _Size) {
    *param_1 = 0xc0000001;
    *param_5 = 0;
  }
  else {
    memmove(param_6,*(void **)(param_3 + 0x20),_Size);
    *param_1 = 0;
    *param_5 = *(undefined4 *)(param_3 + 0x24);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
  return;
}



/* c0542ad8 EthQueryGlobalFilterAddresses */

/* Boundary evidence: original MIPS .pdata c0542ad8..c0542b8b. Semantic name remains unreviewed. */

void EthQueryGlobalFilterAddresses
               (undefined4 *param_1,int param_2,uint param_3,undefined4 *param_4,void *param_5)

{
                    /* 0x2ad8  10  EthQueryGlobalFilterAddresses */
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
  if (param_3 < (uint)(*(int *)(param_2 + 0x44) * 6)) {
    *param_1 = 0xc0000001;
    *param_4 = 0;
  }
  else {
    *param_1 = 0;
    *param_4 = *(undefined4 *)(param_2 + 0x44);
    memmove(param_5,*(void **)(param_2 + 0x38),*(int *)(param_2 + 0x44) * 6);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
  return;
}



/* c0542b8c EthFilterDprIndicateReceiveComplete */

/* Boundary evidence: original MIPS .pdata c0542b8c..c0542c1b. Semantic name remains unreviewed. */

void EthFilterDprIndicateReceiveComplete(int *param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar2;
  
                    /* 0x2b8c  8  EthFilterDprIndicateReceiveComplete */
  if (param_1 != (int *)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
    EnterCriticalSection(lpCriticalSection);
    piVar2 = (int *)*param_1;
    while (piVar1 = piVar2, piVar1 != (int *)0x0) {
      piVar2 = (int *)*piVar1;
      if (*(char *)(piVar1 + 7) != '\0') {
        *(undefined1 *)(piVar1 + 7) = 0;
        LeaveCriticalSection(lpCriticalSection);
        (**(code **)(piVar1[1] + 0x54))(*(undefined4 *)(piVar1[1] + 0x10));
        EnterCriticalSection(lpCriticalSection);
      }
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return;
}



/* c0542c1c FUN_c0542c1c */

undefined4 FUN_c0542c1c(uint param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar4 = param_1 >> 1;
  if ((param_1 != 0) && (uVar6 = param_1 - 1, uVar4 <= uVar6)) {
    do {
      if (uVar4 < uVar5) {
        return 0;
      }
      puVar3 = (ushort *)(uVar4 * 6 + param_2);
      uVar2 = *(uint *)(puVar3 + 1);
      if (*(uint *)(param_3 + 1) < uVar2) {
LAB_c0542cd4:
        if (uVar4 == 0) {
          return 0;
        }
        uVar6 = uVar4 - 1;
      }
      else {
        if (*(uint *)(param_3 + 1) <= uVar2) {
          uVar1 = *puVar3;
          if (*param_3 < uVar1) goto LAB_c0542cd4;
          if (*param_3 <= uVar1) {
            return 1;
          }
        }
        uVar5 = uVar4 + 1;
      }
      uVar4 = ((uVar6 - uVar5) + 1 >> 1) + uVar5;
    } while (uVar4 <= uVar6);
  }
  return 0;
}



/* c0542d10 EthChangeFilterAddresses */

/* Boundary evidence: original MIPS .pdata c0542d10..c05432a7. Semantic name remains unreviewed. */

int EthChangeFilterAddresses(int *param_1,int *param_2,uint param_3,ushort *param_4,char param_5)

{
  ushort uVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  short *psVar11;
  int *piVar12;
  int iVar13;
  undefined2 local_40 [2];
  int local_3c;
  int local_38;
  int local_34;
  int *local_30;
  
                    /* 0x2d10  3  EthChangeFilterAddresses */
  iVar13 = param_1[6];
  local_38 = 0;
  local_34 = 0;
  local_40[0] = 1;
  iVar6 = 0;
  local_3c = iVar13;
  local_30 = param_1;
  (**(code **)(iVar13 + 0x1e4))(param_1,local_40);
  piVar7 = param_2;
  if (param_1[0x10] == 0) goto LAB_c0542e28;
  param_2[10] = param_2[8];
  param_2[0xb] = param_2[9];
  param_2[8] = 0;
  param_2[9] = 0;
  if (param_5 == '\0') {
    local_38 = param_1[0xf];
    local_34 = param_1[0x12];
  }
  else {
    param_1[10] = (int)param_2;
  }
  param_1[0xf] = param_1[0xe];
  param_1[0x12] = param_1[0x11];
  param_1[0xe] = 0;
  param_1[0x11] = 0;
  if (param_3 == 0) {
LAB_c0542fa4:
    pvVar2 = FUN_c05427a0(param_1[0x10] * 6);
    param_1[0xe] = (int)pvVar2;
    if (pvVar2 != (void *)0x0) {
      piVar7 = (int *)*param_1;
      if (piVar7 != (int *)0x0) {
        do {
          iVar13 = local_3c;
          if (iVar6 != 0) goto LAB_c0542e28;
          uVar9 = 0;
          if (piVar7[9] != 0) {
            iVar13 = 0;
            do {
              iVar5 = -1;
              uVar8 = 0;
              if (param_1[0x11] != 0) {
                puVar10 = (ushort *)param_1[0xe];
                uVar3 = *(uint *)((ushort *)(piVar7[8] + iVar13) + 1);
                iVar5 = -1;
                do {
                  if (uVar3 < *(uint *)(puVar10 + 1)) {
LAB_c05430ac:
                    iVar5 = 1;
                    break;
                  }
                  if (uVar3 <= *(uint *)(puVar10 + 1)) {
                    uVar1 = *(ushort *)(piVar7[8] + iVar13);
                    if (uVar1 < *puVar10) goto LAB_c05430ac;
                    if (uVar1 <= *puVar10) goto LAB_c0543124;
                  }
                  uVar8 = uVar8 + 1;
                  puVar10 = puVar10 + 3;
                } while (uVar8 < (uint)param_1[0x11]);
              }
              uVar3 = param_1[0x11] + 1;
              param_1[0x11] = uVar3;
              if ((uint)param_1[0x10] < uVar3) {
                iVar6 = -0x3ffefff7;
                break;
              }
              if (0 < iVar5) {
                pvVar2 = (void *)(uVar8 * 6 + param_1[0xe]);
                memmove((void *)((int)pvVar2 + 6),pvVar2,((uVar3 - uVar8) + -1) * 6);
              }
              memmove((void *)(uVar8 * 6 + param_1[0xe]),(void *)(piVar7[8] + iVar13),6);
LAB_c0543124:
              uVar9 = uVar9 + 1;
              iVar13 = iVar13 + 6;
            } while (uVar9 < (uint)piVar7[9]);
          }
          piVar7 = (int *)*piVar7;
        } while (piVar7 != (int *)0x0);
        iVar13 = local_3c;
        if (iVar6 != 0) goto LAB_c0542e28;
      }
      iVar13 = local_3c;
      if ((param_1[0x11] == param_1[0x12]) && (uVar9 = 0, param_1[0x11] != 0)) {
        iVar4 = param_1[0xf];
        psVar11 = (short *)param_1[0xe];
        piVar12 = (int *)(iVar4 + 2);
        iVar5 = iVar4 - (int)psVar11;
        do {
          if ((*(int *)(psVar11 + 1) != *piVar12) || (*psVar11 != *(short *)(iVar5 + (int)psVar11)))
          goto LAB_c054323c;
          uVar9 = uVar9 + 1;
          piVar12 = (int *)((int)piVar12 + 6);
          psVar11 = psVar11 + 3;
        } while (uVar9 < (uint)param_1[0x11]);
        if ((param_5 != '\0') && (param_3 == 0)) {
          if (iVar4 != 0) {
            CTEFreeMem();
            param_1[0xf] = 0;
            param_1[0x12] = 0;
          }
          piVar7 = param_2;
          iVar13 = local_3c;
          if (param_2[10] != 0) {
            CTEFreeMem();
            param_2[10] = 0;
            param_2[0xb] = 0;
            iVar13 = local_3c;
          }
        }
      }
      else {
LAB_c054323c:
        iVar6 = 0x103;
      }
      goto LAB_c0542e28;
    }
  }
  else {
    if ((int)((ulonglong)param_3 * 6 >> 0x20) != 0) {
      iVar6 = -0x3ffeffeb;
      iVar13 = local_3c;
      goto LAB_c0542e28;
    }
    pvVar2 = FUN_c05427a0((size_t)((ulonglong)param_3 * 6));
    param_2[8] = (int)pvVar2;
    uVar9 = param_3;
    if (pvVar2 != (void *)0x0) {
      for (; uVar9 != 0; uVar9 = uVar9 - 1) {
        iVar13 = -1;
        uVar8 = 0;
        if (param_2[9] != 0) {
          puVar10 = (ushort *)param_2[8];
          iVar13 = -1;
          do {
            if (*(uint *)(param_4 + 1) < *(uint *)(puVar10 + 1)) {
LAB_c0542f30:
              iVar13 = 1;
              break;
            }
            if (*(uint *)(param_4 + 1) <= *(uint *)(puVar10 + 1)) {
              if (*param_4 < *puVar10) goto LAB_c0542f30;
              if (*param_4 <= *puVar10) goto LAB_c0542f84;
            }
            uVar8 = uVar8 + 1;
            puVar10 = puVar10 + 3;
          } while (uVar8 < (uint)param_2[9]);
        }
        iVar5 = param_2[9] + 1;
        param_2[9] = iVar5;
        if (0 < iVar13) {
          pvVar2 = (void *)(uVar8 * 6 + param_2[8]);
          memmove((void *)((int)pvVar2 + 6),pvVar2,((iVar5 - uVar8) + -1) * 6);
        }
        memmove((void *)(uVar8 * 6 + param_2[8]),param_4,6);
LAB_c0542f84:
        param_4 = param_4 + 3;
        param_1 = local_30;
      }
      goto LAB_c0542fa4;
    }
  }
  iVar6 = -0x3fffff66;
  iVar13 = local_3c;
LAB_c0542e28:
  if (param_1[0x10] != 0) {
    if (param_5 == '\0') {
      if (iVar6 == 0x103) {
        iVar6 = 0;
      }
      FUN_c05428f0((int)param_1,iVar6,(int)piVar7,1);
      param_1[0xf] = local_38;
      param_1[0x12] = local_34;
    }
    else if (iVar6 != 0x103) {
      FUN_c05428f0((int)param_1,iVar6,0,1);
    }
  }
  (**(code **)(iVar13 + 0x1e4))(param_1,local_40);
  return iVar6;
}



/* c05432a8 FUN_c05432a8 */

/* Boundary evidence: original MIPS .pdata c05432a8..c05434eb. Semantic name remains unreviewed. */

int FUN_c05432a8(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int local_28;
  undefined4 uStack_24;
  
  bVar1 = false;
  if (*(int *)(param_1 + 0x11c) != 0) {
    *(undefined4 *)(param_2 + 0x20) = 0;
    *(undefined4 *)(param_2 + 0x24) = 0;
    return -0x3fffff45;
  }
  if (*(uint *)(param_2 + 0x1c) % 6 != 0) {
    *(undefined4 *)(param_2 + 0x20) = 0;
    *(undefined4 *)(param_2 + 0x24) = 0;
    return -0x3ffeffec;
  }
  uVar4 = *(uint *)(param_2 + 0x1c) / 6;
  if ((uint)(*(int **)(param_1 + 0xf8))[0x10] < uVar4) {
    *(undefined4 *)(param_2 + 0x20) = 0;
    *(undefined4 *)(param_2 + 0x24) = 0;
    return -0x3ffefff7;
  }
  if ((*(uint *)(*(int *)(param_2 + 4) + 0x7c) & 0x8000) == 0) {
    iVar2 = EthChangeFilterAddresses
                      (*(int **)(param_1 + 0xf8),*(int **)(*(int *)(param_2 + 4) + 0x98),uVar4,
                       *(ushort **)(param_2 + 0x18),'\x01');
    if (iVar2 != 0x103) goto LAB_c0543434;
    bVar1 = true;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0xf8) + 0x44);
  local_28 = iVar2;
  if (iVar2 != 0) {
    pvVar3 = FUN_c05427a0(iVar2 * 6);
    *(void **)(param_1 + 0x194) = pvVar3;
    if (pvVar3 == (void *)0x0) {
      iVar2 = -0x3fffff66;
      goto LAB_c0543434;
    }
  }
  EthQueryGlobalFilterAddresses
            (&uStack_24,*(int *)(param_1 + 0xf8),iVar2 * 6,&local_28,*(void **)(param_1 + 0x194));
  *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
  *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_2 + 0x18);
  *(short *)(param_1 + 0x1dc) = (short)*(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x194);
  *(int *)(param_2 + 0x1c) = local_28 * 6;
  iVar2 = FUN_c05574b4(param_1,param_2,0);
  if (iVar2 == 0x103) {
    return 0x103;
  }
LAB_c0543434:
  if ((*(uint *)(param_2 + 0xc) & 8) != 0) {
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xfffffff7;
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x1d8);
    *(uint *)(param_2 + 0x1c) = (uint)*(ushort *)(param_1 + 0x1dc);
    *(undefined4 *)(param_1 + 0x1d8) = 0;
    *(undefined2 *)(param_1 + 0x1dc) = 0;
  }
  if (iVar2 == 0) {
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_2 + 0x1c);
  }
  else {
    *(undefined4 *)(param_2 + 0x20) = 0;
    *(undefined4 *)(param_2 + 0x24) = 0;
    if (iVar2 == 0x103) {
      return 0x103;
    }
  }
  if (*(int *)(param_1 + 0x194) != 0) {
    CTEFreeMem();
    *(undefined4 *)(param_1 + 0x194) = 0;
  }
  if (bVar1) {
    FUN_c05428f0(*(int *)(param_1 + 0xf8),iVar2,0,0);
  }
  return iVar2;
}



/* c05434ec EthFilterDprIndicateReceive */

/* Boundary evidence: original MIPS .pdata c05434ec..c054386f. Semantic name remains unreviewed. */

void EthFilterDprIndicateReceive
               (int *param_1,undefined4 param_2,ushort *param_3,undefined4 param_4,uint param_5,
               undefined4 param_6,undefined4 param_7,int param_8)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar6;
  
                    /* 0x34ec  7  EthFilterDprIndicateReceive */
  if (param_1 == (int *)0x0) {
    return;
  }
  if ((*(uint *)(param_1[6] + 0x54) & 0x20000000) == 0) {
    return;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
  EnterCriticalSection(lpCriticalSection);
  if (param_1[0xb] == 0) {
    if ((param_5 < 0xe) || (param_8 == 0)) {
      iVar5 = 0x20;
    }
    else {
      if (((byte)*param_3 & 1) == 0) {
        bVar1 = false;
        *(int *)(param_1[6] + 0x3a4) = *(int *)(param_1[6] + 0x3a4) + 1;
        if (((param_1[7] & 0xa4U) != 0) &&
           ((*(int *)((int)param_1 + 0x32) != *(int *)(param_3 + 1) ||
            (bVar1 = false, *(ushort *)(param_1 + 0xc) != *param_3)))) {
          bVar1 = true;
        }
        piVar6 = (int *)*param_1;
        while (piVar2 = piVar6, piVar2 != (int *)0x0) {
          piVar6 = (int *)*piVar2;
          if (((piVar2[3] & 0xa0U) != 0) || ((!bVar1 && ((piVar2[3] & 1U) != 0)))) {
            LeaveCriticalSection(lpCriticalSection);
            (**(code **)(piVar2[1] + 0x50))
                      (*(undefined4 *)(piVar2[1] + 0x10),param_2,param_4,param_5,param_6,param_7,
                       param_8);
            EnterCriticalSection(lpCriticalSection);
            *(undefined1 *)(piVar2 + 7) = 1;
          }
        }
        goto LAB_c0543838;
      }
      if (((byte)*param_3 == 0xff) && (*(char *)((int)param_3 + 1) == -1)) {
        iVar5 = 8;
      }
      else {
        iVar5 = 2;
      }
    }
    piVar6 = (int *)*param_1;
    while (piVar2 = piVar6, piVar2 != (int *)0x0) {
      uVar4 = piVar2[3];
      piVar6 = (int *)*piVar2;
      if ((((uVar4 & 0xa0) != 0) || ((iVar5 == 8 && ((uVar4 & 8) != 0)))) ||
         ((iVar5 == 2 &&
          (((uVar4 & 4) != 0 ||
           (((uVar4 & 2) != 0 && (iVar3 = FUN_c0542c1c(piVar2[9],piVar2[8],param_3), iVar3 != 0)))))
          ))) {
        LeaveCriticalSection(lpCriticalSection);
        (**(code **)(piVar2[1] + 0x50))
                  (*(undefined4 *)(piVar2[1] + 0x10),param_2,param_4,param_5,param_6,param_7,param_8
                  );
        EnterCriticalSection(lpCriticalSection);
        *(undefined1 *)(piVar2 + 7) = 1;
      }
    }
  }
  else if (((0xd < param_5) && (param_8 != 0)) || ((param_1[7] & 0xa0U) != 0)) {
    if ((*param_3 & 1) == 0) {
      *(int *)(param_1[6] + 0x3a4) = *(int *)(param_1[6] + 0x3a4) + 1;
    }
    iVar5 = param_1[0xb];
    if (iVar5 != 0) {
      *(undefined1 *)(iVar5 + 0x1c) = 1;
      LeaveCriticalSection(lpCriticalSection);
      (**(code **)(*(int *)(iVar5 + 4) + 0x50))
                (*(undefined4 *)(*(int *)(iVar5 + 4) + 0x10),param_2,param_4,param_5,param_6,param_7
                 ,param_8);
      EnterCriticalSection(lpCriticalSection);
    }
  }
LAB_c0543838:
  LeaveCriticalSection(lpCriticalSection);
  return;
}



/* c0543870 FUN_c0543870 */

/* Boundary evidence: original MIPS .pdata c0543870..c0543dbf. Semantic name remains unreviewed. */

void FUN_c0543870(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  ushort *puVar14;
  LPCRITICAL_SECTION lpCriticalSection;
  char local_48 [4];
  uint local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  
  piVar12 = *(int **)(param_1 + 0xf8);
  iVar11 = 0;
  local_40 = 0;
  local_38 = param_2;
  local_34 = param_3;
  EnterCriticalSection((LPCRITICAL_SECTION)(piVar12 + 1));
  if (param_3 != 0) {
    do {
      iVar13 = *param_2;
      uVar5 = *(int *)(iVar13 + -4) + 1;
      *(uint *)(iVar13 + -4) = uVar5;
      if (uVar5 < DAT_c05653bc) {
        iVar6 = (uVar5 - DAT_c05653bc) * 0x28 + iVar13 + -8;
      }
      else {
        iVar6 = 0;
      }
      piVar10 = (int *)(iVar6 + 8);
      local_30 = (uint)*(ushort *)(iVar13 + 0x1e) + iVar13;
      piVar4 = *(int **)(iVar13 + 8);
      puVar14 = (ushort *)0x0;
      if (piVar4 != (int *)0x0) {
        puVar14 = *(ushort **)((int)piVar4 + 4);
      }
      local_44 = 0;
      for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        local_44 = piVar4[2] + local_44;
      }
      *(undefined4 *)(iVar6 + 0xc) = 0xffffffff;
      *(undefined4 *)(iVar6 + 0x10) = 0;
      *piVar10 = param_1;
      *(undefined1 *)(iVar13 + 0x1c) = 0;
      if (*(int *)(local_30 + 0x1c) == -0x3fffff66) {
        local_48[0] = '\x01';
      }
      else {
        if ((*(uint *)(param_1 + 0x54) & 0x8000) == 0) {
          *(undefined4 *)(local_30 + 0x1c) = 0;
        }
        local_48[0] = '\0';
      }
      iVar7 = piVar12[0xb];
      piVar4 = piVar10;
      iVar6 = local_40;
      if (iVar7 == 0) {
        if (local_44 < 0xe) {
          iVar7 = 0x20;
        }
        else {
          if (((byte)*puVar14 & 1) == 0) {
            if ((*(byte *)(iVar13 + 0x1d) & 2) == 0) {
              *(int *)(param_1 + 0x3a4) = *(int *)(param_1 + 0x3a4) + 1;
            }
            bVar2 = false;
            if (((piVar12[7] & 0xa4U) != 0) &&
               ((*(int *)((int)piVar12 + 0x32) != *(int *)(puVar14 + 1) ||
                (bVar2 = false, *(ushort *)(piVar12 + 0xc) != *puVar14)))) {
              bVar2 = true;
            }
            piVar9 = (int *)*piVar12;
            uVar5 = local_44;
            while (piVar3 = piVar9, local_3c = piVar4, piVar3 != (int *)0x0) {
              piVar9 = (int *)*piVar3;
              bVar1 = (piVar3[3] & 0xa0U) != 0;
              iVar6 = iVar11;
              if (((bVar1) || ((!bVar2 && ((piVar3[3] & 1U) != 0)))) &&
                 (((*(uint *)(iVar13 + 0x18) & 0x80) == 0 || (*(int *)(iVar13 + 0x20) != piVar3[1]))
                 )) {
                *(undefined1 *)(piVar3 + 7) = 1;
                iVar11 = iVar11 + 1;
                FUN_c055bbe8(param_1,(int)piVar12,piVar3[1],iVar13,(int)piVar10,(int)puVar14,uVar5,
                             0xe,local_48,bVar1);
                piVar4 = local_3c;
                iVar6 = iVar11;
                uVar5 = local_44;
              }
            }
            goto LAB_c0543ce4;
          }
          if (((byte)*puVar14 == 0xff) && (*(char *)((int)puVar14 + 1) == -1)) {
            iVar7 = 8;
          }
          else {
            iVar7 = 2;
          }
        }
        piVar9 = (int *)*piVar12;
        uVar5 = local_44;
        while (piVar3 = piVar9, iVar6 = local_40, local_3c = piVar4, piVar3 != (int *)0x0) {
          piVar9 = (int *)*piVar3;
          iVar11 = local_40;
          if (((*(uint *)(iVar13 + 0x18) & 0x80) == 0) || (*(int *)(iVar13 + 0x20) != piVar3[1])) {
            uVar8 = piVar3[3];
            if ((((uVar8 & 0xa0) != 0) || ((iVar7 == 8 && ((uVar8 & 8) != 0)))) ||
               ((iVar7 == 2 &&
                (((uVar8 & 4) != 0 ||
                 (((uVar8 & 2) != 0 &&
                  (iVar6 = FUN_c0542c1c(piVar3[9],piVar3[8],puVar14), uVar5 = local_44,
                  piVar4 = local_3c, iVar11 = local_40, iVar6 != 0)))))))) {
              local_40 = local_40 + 1;
              *(undefined1 *)(piVar3 + 7) = 1;
              FUN_c055bbe8(param_1,(int)piVar12,piVar3[1],iVar13,(int)piVar10,(int)puVar14,uVar5,0xe
                           ,local_48,(uVar8 & 0xa0) != 0);
              piVar4 = local_3c;
              iVar11 = local_40;
              uVar5 = local_44;
            }
          }
        }
      }
      else {
        local_3c = piVar10;
        if ((local_44 >= 0xe) || ((piVar12[7] & 0xa0U) != 0)) {
          uVar5 = *(uint *)(iVar7 + 0xc);
          iVar11 = iVar11 + 1;
          iVar6 = *(int *)(iVar7 + 4);
          *(undefined1 *)(iVar7 + 0x1c) = 1;
          if ((*puVar14 & 1) == 0) {
            *(int *)(param_1 + 0x3a4) = *(int *)(param_1 + 0x3a4) + 1;
          }
          local_40 = iVar11;
          FUN_c055bbe8(param_1,(int)piVar12,iVar6,iVar13,(int)piVar10,(int)puVar14,local_44,0xe,
                       local_48,(uVar5 & 0xa0) != 0);
          iVar6 = local_40;
        }
      }
LAB_c0543ce4:
      local_40 = iVar6;
      lpCriticalSection = (LPCRITICAL_SECTION)(piVar12 + 1);
      LeaveCriticalSection(lpCriticalSection);
      FUN_c055bad8(param_1,iVar13,piVar4,local_30);
      EnterCriticalSection(lpCriticalSection);
      param_2 = local_38 + 1;
      local_34 = local_34 + -1;
      local_38 = param_2;
    } while (local_34 != 0);
    local_34 = 0;
    if (iVar11 != 0) {
      piVar4 = (int *)*piVar12;
      while (piVar10 = piVar4, piVar10 != (int *)0x0) {
        piVar4 = (int *)*piVar10;
        if (*(char *)(piVar10 + 7) != '\0') {
          *(undefined1 *)(piVar10 + 7) = 0;
          LeaveCriticalSection(lpCriticalSection);
          (**(code **)(piVar10[1] + 0x54))(*(undefined4 *)(piVar10[1] + 0x10));
          EnterCriticalSection(lpCriticalSection);
        }
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(piVar12 + 1));
  return;
}



/* c0543dc0 EthDeleteFilterOpenAdapter */

/* Boundary evidence: original MIPS .pdata c0543dc0..c0543e97. Semantic name remains unreviewed. */

int EthDeleteFilterOpenAdapter(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x3dc0  6  EthDeleteFilterOpenAdapter */
  iVar1 = FUN_c055b990(param_1,(int)param_2,0);
  if ((iVar1 == 0) || (iVar1 == 0x103)) {
    iVar2 = EthChangeFilterAddresses(param_1,param_2,0,(ushort *)0x0,'\0');
    if (iVar2 != 0) {
      iVar1 = iVar2;
    }
  }
  if (((iVar1 == 0) || (iVar1 == 0x103)) || (iVar1 == -0x3fffff66)) {
    iVar2 = param_2[5];
    param_2[5] = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_c055bfdc(param_1,param_2);
    }
    else {
      iVar1 = -0x3ffefff2;
    }
  }
  return iVar1;
}



/* c0543e98 FUN_c0543e98 */

/* Boundary evidence: original MIPS .pdata c0543e98..c0543f67. Semantic name remains unreviewed. */

void FUN_c0543e98(int *param_1,undefined4 param_2,ushort *param_3,undefined4 param_4,uint param_5,
                 undefined4 param_6,undefined4 param_7,int param_8)

{
  if (*(code **)g_pLogMiniportIndicateReceive_exref != (code *)0x0) {
    (**(code **)g_pLogMiniportIndicateReceive_exref)
              (0,param_2,0,param_4,param_5,param_6,param_7,param_8,0);
  }
  EthFilterDprIndicateReceive(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c0543f68 FUN_c0543f68 */

/* Boundary evidence: original MIPS .pdata c0543f68..c0543fd7. Semantic name remains unreviewed. */

void FUN_c0543f68(int param_1,int *param_2,int param_3)

{
  if (*(code **)g_pLogMiniportIndicateReceivePackets_exref != (code *)0x0) {
    (**(code **)g_pLogMiniportIndicateReceivePackets_exref)(param_1,param_2,param_3,0);
  }
  FUN_c0543870(param_1,param_2,param_3);
  return;
}



/* c0543fd8 FUN_c0543fd8 */

/* Boundary evidence: original MIPS .pdata c0543fd8..c054414f. Semantic name remains unreviewed. */

void FUN_c0543fd8(int param_1,int *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  LONG *Addend;
  code *pcVar9;
  
  iVar2 = DAT_c05653c0;
  iVar4 = *(int *)(*(int *)(param_1 + 0xf8) + 0x2c);
  if (iVar4 == 0) {
    FUN_c0543870(param_1,param_2,param_3);
  }
  else {
    iVar4 = *(int *)(iVar4 + 4);
    uVar3 = *(undefined4 *)(iVar4 + 0x10);
    piVar7 = param_2 + param_3;
    pcVar9 = *(code **)(iVar4 + 0x60);
    for (; param_2 < piVar7; param_2 = param_2 + 1) {
      iVar8 = *param_2;
      iVar5 = *(int *)(iVar8 + -4) + 1;
      *(int *)(iVar8 + -4) = iVar5;
      uVar1 = *(ushort *)(iVar8 + 0x1e);
      iVar6 = (iVar5 * 0x28 - iVar2) + iVar8;
      Addend = (LONG *)(iVar6 + 0xc);
      *Addend = -1;
      *(undefined4 *)(iVar6 + 0x10) = 0;
      *(int *)(iVar6 + 8) = param_1;
      *(undefined1 *)(iVar8 + 0x1c) = 0;
      iVar5 = (*pcVar9)(uVar3,iVar8);
      if (iVar5 < 1) {
        *Addend = 0;
        *(int *)(iVar8 + -4) = *(int *)(iVar8 + -4) + -1;
        *(int *)(iVar6 + 8) = 0;
        *(undefined4 *)((uint)uVar1 + iVar8 + 0x1c) = 0x103;
        (**(code **)(*(int *)(param_1 + 8) + 0x5c))(*(undefined4 *)(param_1 + 0xc),iVar8);
      }
      else {
        InterlockedExchangeAdd(Addend,iVar5 + 1);
      }
    }
    (**(code **)(iVar4 + 0x54))(*(undefined4 *)(iVar4 + 0x10));
  }
  return;
}



/* c0544150 NdisAllocateSpinLock */

/* Boundary evidence: original MIPS .pdata c0544150..c054416b. Semantic name remains unreviewed. */

void NdisAllocateSpinLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x4150  32  NdisAllocateSpinLock */
  InitializeCriticalSection(param_1);
  return;
}



/* c054416c NdisFreeSpinLock */

/* Boundary evidence: original MIPS .pdata c054416c..c0544187. Semantic name remains unreviewed. */

void NdisFreeSpinLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x416c  66  NdisFreeSpinLock */
  DeleteCriticalSection(param_1);
  return;
}



/* c0544188 NdisAcquireSpinLock */

/* Boundary evidence: original MIPS .pdata c0544188..c05441a3. Semantic name remains unreviewed. */

void NdisAcquireSpinLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x4188  22  NdisAcquireSpinLock */
  EnterCriticalSection(param_1);
  return;
}



/* c05441a4 NdisReleaseSpinLock */

/* Boundary evidence: original MIPS .pdata c05441a4..c05441bf. Semantic name remains unreviewed. */

void NdisReleaseSpinLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x41a4  193  NdisReleaseSpinLock */
  LeaveCriticalSection(param_1);
  return;
}



/* c05441c0 NdisDprAcquireSpinLock */

/* Boundary evidence: original MIPS .pdata c05441c0..c05441db. Semantic name remains unreviewed. */

void NdisDprAcquireSpinLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x41c0  51  NdisDprAcquireSpinLock */
  EnterCriticalSection(param_1);
  return;
}



/* c05441dc NdisDprReleaseSpinLock */

/* Boundary evidence: original MIPS .pdata c05441dc..c05441f7. Semantic name remains unreviewed. */

void NdisDprReleaseSpinLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x41dc  56  NdisDprReleaseSpinLock */
  LeaveCriticalSection(param_1);
  return;
}



/* c05441f8 NdisFreeBuffer */

/* Boundary evidence: original MIPS .pdata c05441f8..c0544213. Semantic name remains unreviewed. */

void NdisFreeBuffer(void)

{
                    /* 0x41f8  59  NdisFreeBuffer */
  FUN_c055f43c();
  return;
}



/* c0544214 NdisQueryBuffer */

void NdisQueryBuffer(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
                    /* 0x4214  177  NdisQueryBuffer
                       0x4214  179  NdisQueryBufferSafe */
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = 0;
    if (param_1 != 0) {
      uVar1 = *(undefined4 *)(param_1 + 4);
    }
    *param_2 = uVar1;
  }
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  *param_3 = uVar1;
  return;
}



/* c0544240 NdisQueryBufferOffset */

void NdisQueryBufferOffset(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
                    /* 0x4240  178  NdisQueryBufferOffset */
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  *param_2 = uVar1;
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  *param_3 = uVar1;
  return;
}



/* c0544264 NdisGetFirstBufferFromPacket */

void NdisGetFirstBufferFromPacket(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x4264  76  NdisGetFirstBufferFromPacket
                       0x4264  77  NdisGetFirstBufferFromPacketSafe */
  piVar2 = *(int **)(param_1 + 8);
  *param_2 = (int)piVar2;
  if (piVar2 == (int *)0x0) {
    *param_3 = 0;
    *param_4 = 0;
    *param_5 = 0;
  }
  else {
    *param_3 = piVar2[1];
    iVar1 = piVar2[2];
    *param_5 = iVar1;
    *param_4 = iVar1;
    while (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0) {
      *param_5 = *param_5 + piVar2[2];
    }
  }
  return;
}



/* c05442c8 NdisBufferLength */

undefined4 NdisBufferLength(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x42c8  35  NdisBufferLength */
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  return uVar1;
}



/* c05442dc NdisBufferVirtualAddress */

undefined4 NdisBufferVirtualAddress(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x42dc  36  NdisBufferVirtualAddress */
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 4);
  }
  return uVar1;
}



/* c05442f0 NDIS_BUFFER_TO_SPAN_PAGES */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint NDIS_BUFFER_TO_SPAN_PAGES(int param_1)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x42f0  12  NDIS_BUFFER_TO_SPAN_PAGES */
  if ((param_1 == 0) || (*(int *)(param_1 + 8) == 0)) {
    uVar1 = 1;
  }
  else {
    iVar2 = 0xc;
    if (_DAT_00005b04 != 0x1000) {
      iVar2 = 10;
    }
    uVar1 = ((_DAT_00005b04 - 1U & *(uint *)(param_1 + 4)) + _DAT_00005b04 + *(int *)(param_1 + 8))
            - 1 >> iVar2;
  }
  return uVar1;
}



/* c054434c NdisGetBufferPhysicalArraySize */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NdisGetBufferPhysicalArraySize(int param_1,uint *param_2)

{
  int iVar1;
  
                    /* 0x434c  71  NdisGetBufferPhysicalArraySize */
  if ((param_1 == 0) || (*(int *)(param_1 + 8) == 0)) {
    *param_2 = 1;
  }
  else {
    iVar1 = 0xc;
    if (_DAT_00005b04 != 0x1000) {
      iVar1 = 10;
    }
    *param_2 = ((_DAT_00005b04 - 1U & *(uint *)(param_1 + 4)) + _DAT_00005b04 +
               *(int *)(param_1 + 8)) - 1 >> iVar1;
  }
  return;
}



/* c05443b0 NdisAnsiStringToUnicodeString */

/* Boundary evidence: original MIPS .pdata c05443b0..c05443cb. Semantic name remains unreviewed. */

void NdisAnsiStringToUnicodeString(ushort *param_1,ushort *param_2)

{
                    /* 0x43b0  33  NdisAnsiStringToUnicodeString */
  FUN_c055f5f8(param_1,param_2,0);
  return;
}



/* c05443cc NdisUnicodeStringToAnsiString */

/* Boundary evidence: original MIPS .pdata c05443cc..c05443e7. Semantic name remains unreviewed. */

void NdisUnicodeStringToAnsiString(ushort *param_1,ushort *param_2)

{
                    /* 0x43cc  216  NdisUnicodeStringToAnsiString */
  FUN_c055f6d4(param_1,param_2,0);
  return;
}



/* c05443e8 NdisUpcaseUnicodeString */

/* Boundary evidence: original MIPS .pdata c05443e8..c0544403. Semantic name remains unreviewed. */

void NdisUpcaseUnicodeString(ushort *param_1,ushort *param_2)

{
                    /* 0x43e8  218  NdisUpcaseUnicodeString */
  FUN_c055f8ec(param_1,param_2,0);
  return;
}



/* c0544404 NdisMStartBufferPhysicalMapping */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0544404..c05445df. Semantic name remains unreviewed. */

void NdisMStartBufferPhysicalMapping
               (undefined4 param_1,int param_2,undefined4 param_3,int param_4,uint *param_5,
               int *param_6)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int aiStack_70 [20];
  
                    /* 0x4404  156  NdisMStartBufferPhysicalMapping */
  uVar1 = _DAT_00005b08;
  *param_6 = 0;
  uVar8 = *(uint *)(param_2 + 4);
  uVar7 = *(uint *)(param_2 + 8);
  if (((uVar8 & 0xe0000000) == 0xa0000000) || ((uVar8 & 0xe0000000) == 0x80000000)) {
    *param_6 = 1;
    *param_5 = uVar8 & 0x1fffffff;
    param_5[1] = 0;
    param_5[2] = uVar7;
  }
  else {
    iVar5 = 0xc;
    if (_DAT_00005b04 != 0x1000) {
      iVar5 = 10;
    }
    uVar6 = ((_DAT_00005b04 - 1U & uVar8) + _DAT_00005b04 + uVar7) - 1 >> iVar5;
    if (uVar6 < 0x15) {
      piVar2 = aiStack_70;
    }
    else {
      piVar2 = FUN_c05427a0(uVar6 << 2);
    }
    if (piVar2 != (int *)0x0) {
      uVar4 = 1;
      if (param_4 == 0) {
        uVar4 = 4;
      }
      iVar5 = LockPages(uVar8,uVar7,piVar2,uVar4);
      if (iVar5 != 0) {
        iVar5 = 0;
        if (uVar7 != 0) {
          puVar9 = param_5 + 2;
          piVar3 = piVar2;
          do {
            uVar6 = uVar7;
            if (_DAT_00005b04 - (_DAT_00005b04 - 1U & uVar8) < uVar7) {
              uVar6 = _DAT_00005b04 - (_DAT_00005b04 - 1U & uVar8);
            }
            puVar9[-2] = (_DAT_00005b04 - 1U & uVar8) + (*piVar3 << (uVar1 & 0x1f));
            puVar9[-1] = 0;
            *puVar9 = uVar6;
            uVar8 = uVar6 + uVar8;
            uVar7 = uVar7 - uVar6;
            iVar5 = iVar5 + 1;
            piVar3 = piVar3 + 1;
            puVar9 = puVar9 + 4;
          } while (uVar7 != 0);
        }
        *param_6 = iVar5;
      }
      if (piVar2 != aiStack_70) {
        CTEFreeMem(piVar2);
      }
    }
  }
  return;
}



/* c05445e0 NdisMCompleteBufferPhysicalMapping */

/* Boundary evidence: original MIPS .pdata c05445e0..c0544613. Semantic name remains unreviewed. */

void NdisMCompleteBufferPhysicalMapping(undefined4 param_1,int param_2)

{
                    /* 0x45e0  120  NdisMCompleteBufferPhysicalMapping */
  if ((*(uint *)(param_2 + 4) & 0xe0000000) != 0xa0000000) {
    UnlockPages(*(uint *)(param_2 + 4),*(undefined4 *)(param_2 + 8));
  }
  return;
}



/* c0544614 NdisInterlockedIncrement */

/* Boundary evidence: original MIPS .pdata c0544614..c054462f. Semantic name remains unreviewed. */

void NdisInterlockedIncrement(LONG *param_1)

{
                    /* 0x4614  112  NdisInterlockedIncrement */
  InterlockedIncrement(param_1);
  return;
}



/* c0544630 NdisInterlockedDecrement */

/* Boundary evidence: original MIPS .pdata c0544630..c054464b. Semantic name remains unreviewed. */

void NdisInterlockedDecrement(LONG *param_1)

{
                    /* 0x4630  111  NdisInterlockedDecrement */
  InterlockedDecrement(param_1);
  return;
}



/* c054464c NdisInterlockedAddUlong */

/* Boundary evidence: original MIPS .pdata c054464c..c054469f. Semantic name remains unreviewed. */

void NdisInterlockedAddUlong(int *param_1,int param_2,LPCRITICAL_SECTION param_3)

{
                    /* 0x464c  110  NdisInterlockedAddUlong */
  EnterCriticalSection(param_3);
  *param_1 = *param_1 + param_2;
  LeaveCriticalSection(param_3);
  return;
}



/* c05446a0 NdisInterlockedInsertHeadList */

/* Boundary evidence: original MIPS .pdata c05446a0..c05446bb. Semantic name remains unreviewed. */

void NdisInterlockedInsertHeadList(undefined4 *param_1,int *param_2,LPCRITICAL_SECTION param_3)

{
                    /* 0x46a0  113  NdisInterlockedInsertHeadList */
  FUN_c055f218(param_1,param_2,param_3);
  return;
}



/* c05446bc NdisInterlockedInsertTailList */

/* Boundary evidence: original MIPS .pdata c05446bc..c05446d7. Semantic name remains unreviewed. */

void NdisInterlockedInsertTailList(undefined4 *param_1,int *param_2,LPCRITICAL_SECTION param_3)

{
                    /* 0x46bc  114  NdisInterlockedInsertTailList */
  FUN_c055f290(param_1,param_2,param_3);
  return;
}



/* c05446d8 NdisInterlockedRemoveHeadList */

/* Boundary evidence: original MIPS .pdata c05446d8..c05446f3. Semantic name remains unreviewed. */

void NdisInterlockedRemoveHeadList(int *param_1,LPCRITICAL_SECTION param_2)

{
                    /* 0x46d8  115  NdisInterlockedRemoveHeadList */
  FUN_c055f308(param_1,param_2);
  return;
}



/* c05446f4 NdisMCreateLog */

/* Boundary evidence: original MIPS .pdata c05446f4..c0544803. Semantic name remains unreviewed. */

undefined4 NdisMCreateLog(int param_1,int param_2,undefined4 *param_3)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  int *piVar3;
  
                    /* 0x46f4  121  NdisMCreateLog */
  piVar3 = (int *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (*(int *)(param_1 + 0x25c) == 0) {
    if (param_2 + 0x30U < 0x30) {
      uVar2 = 0xc0010015;
    }
    else {
      piVar3 = FUN_c05427a0(param_2 + 0x30U);
      if (piVar3 == (int *)0x0) {
        uVar2 = 0xc000009a;
      }
      else {
        *(int **)(param_1 + 0x25c) = piVar3;
        uVar2 = 0;
        InitializeCriticalSection((LPCRITICAL_SECTION)(piVar3 + 1));
        *piVar3 = param_1;
        pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
        piVar3[6] = (int)pvVar1;
        piVar3[7] = param_2;
        piVar3[8] = 0;
        piVar3[9] = 0;
        piVar3[10] = 0;
      }
    }
  }
  else {
    uVar2 = 0xc0000001;
  }
  *param_3 = piVar3;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return uVar2;
}



/* c0544804 NdisMCloseLog */

/* Boundary evidence: original MIPS .pdata c0544804..c054487f. Semantic name remains unreviewed. */

void NdisMCloseLog(int *param_1)

{
  int iVar1;
  
                    /* 0x4804  119  NdisMCloseLog */
  iVar1 = *param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  *(undefined4 *)(iVar1 + 0x25c) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  EventModify(param_1[6],3);
  CloseHandle((HANDLE)param_1[6]);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  CTEFreeMem(param_1);
  return;
}



/* c0544880 NdisMWriteLogData */

/* Boundary evidence: original MIPS .pdata c0544880..c05449ab. Semantic name remains unreviewed. */

undefined4 NdisMWriteLogData(int param_1,void *param_2,uint param_3)

{
  void *_Dst;
  size_t _Size;
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
                    /* 0x4880  163  NdisMWriteLogData */
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (*(uint *)(param_1 + 0x1c) < param_3) {
    uVar2 = 0x80000005;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x1c) - *(int *)(param_1 + 0x24);
    _Dst = (void *)(*(int *)(param_1 + 0x24) + param_1 + 0x2c);
    _Size = param_3;
    if (uVar3 < param_3) {
      memcpy(_Dst,param_2,uVar3);
      param_2 = (void *)(uVar3 + (int)param_2);
      _Dst = (void *)(param_1 + 0x2c);
      _Size = param_3 - uVar3;
    }
    memcpy(_Dst,param_2,_Size);
    uVar1 = *(uint *)(param_1 + 0x1c);
    uVar3 = param_3 + *(int *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar3;
    if (uVar1 < uVar3) {
      *(uint *)(param_1 + 0x20) = uVar1;
    }
    uVar3 = *(int *)(param_1 + 0x24) + param_3;
    *(uint *)(param_1 + 0x24) = uVar3;
    if (uVar1 <= uVar3) {
      *(uint *)(param_1 + 0x24) = uVar3 - uVar1;
    }
    if (*(uint *)(param_1 + 0x20) == uVar1) {
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
    }
    EventModify(*(undefined4 *)(param_1 + 0x18),3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return uVar2;
}



/* c05449ac NdisGetLogData */

/* Boundary evidence: original MIPS .pdata c05449ac..c0544b5b. Semantic name remains unreviewed. */

undefined4 NdisGetLogData(wchar_t *param_1,void *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  HANDLE hHandle;
  undefined4 uVar4;
  
                    /* 0x49ac  78  NdisGetLogData */
  uVar4 = 0xc0000001;
  while( true ) {
    if (param_2 == (void *)0x0) {
      return 0xc000009a;
    }
    iVar1 = FUN_c0545da8(param_1);
    if (iVar1 == 0) {
      return 0xc0000001;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = *(int *)(iVar1 + 0x25c);
    if (iVar1 == 0) break;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if (*(int *)(iVar1 + 0x20) != 0) {
      if (*(uint *)(iVar1 + 0x20) < param_3) {
        param_3 = *(uint *)(iVar1 + 0x20);
      }
      iVar3 = *(int *)(iVar1 + 0x28);
      uVar2 = *(int *)(iVar1 + 0x1c) - iVar3;
      if (uVar2 < param_3) {
        memcpy(param_2,(void *)(iVar3 + iVar1 + 0x2c),uVar2);
        uVar2 = (*(int *)(iVar1 + 0x28) - *(int *)(iVar1 + 0x1c)) + param_3;
        param_2 = (void *)((*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x28)) + (int)param_2);
        iVar3 = iVar1;
      }
      else {
        uVar2 = param_3;
        iVar3 = iVar3 + iVar1;
      }
      memcpy(param_2,(void *)(iVar3 + 0x2c),uVar2);
      uVar2 = *(int *)(iVar1 + 0x28) + param_3;
      *(uint *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) - param_3;
      *(uint *)(iVar1 + 0x28) = uVar2;
      if (*(uint *)(iVar1 + 0x1c) <= uVar2) {
        *(uint *)(iVar1 + 0x28) = uVar2 - *(uint *)(iVar1 + 0x1c);
      }
      *param_4 = param_3;
      uVar4 = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      break;
    }
    hHandle = *(HANDLE *)(iVar1 + 0x18);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    WaitForSingleObject(hHandle,0xffffffff);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return uVar4;
}



/* c0544b5c NdisMFlushLog */

/* Boundary evidence: original MIPS .pdata c0544b5c..c0544bb3. Semantic name remains unreviewed. */

void NdisMFlushLog(int param_1)

{
                    /* 0x4b5c  125  NdisMFlushLog */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  EventModify(*(undefined4 *)(param_1 + 0x18),2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c0544bb4 NdisMQueryAdapterInstanceName */

/* Boundary evidence: original MIPS .pdata c0544bb4..c0544c87. Semantic name remains unreviewed. */

undefined4 NdisMQueryAdapterInstanceName(ushort *param_1,int param_2)

{
  ushort uVar1;
  void *_Dst;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0x4bb4  136  NdisMQueryAdapterInstanceName */
  uVar3 = 0xc0000001;
  if (*(int *)(param_2 + 0x1e8) != 0) {
    uVar1 = *(ushort *)(*(int *)(param_2 + 0x1e8) + 2);
    _Dst = FUN_c05427a0((uint)uVar1);
    if (_Dst == (void *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(uint)uVar1);
      *(void **)(param_1 + 2) = _Dst;
      *param_1 = 0;
      param_1[1] = uVar1;
      iVar2 = FUN_c055fac4(param_1,*(ushort **)(param_2 + 0x1e8));
      if (-1 < iVar2) {
        return 0;
      }
    }
    if (_Dst != (void *)0x0) {
      CTEFreeMem(_Dst);
    }
  }
  return uVar3;
}



/* c0544c88 NdisInitializeReadWriteLock */

/* Boundary evidence: original MIPS .pdata c0544c88..c0544ca3. Semantic name remains unreviewed. */

void NdisInitializeReadWriteLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x4c88  106  NdisInitializeReadWriteLock */
  InitializeCriticalSection(param_1);
  return;
}



/* c0544ca4 NdisFreeReadWriteLock */

/* Boundary evidence: original MIPS .pdata c0544ca4..c0544cbf. Semantic name remains unreviewed. */

void NdisFreeReadWriteLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x4ca4  65  NdisFreeReadWriteLock */
  DeleteCriticalSection(param_1);
  return;
}



/* c0544cc0 NdisAcquireReadWriteLock */

/* Boundary evidence: original MIPS .pdata c0544cc0..c0544cdb. Semantic name remains unreviewed. */

void NdisAcquireReadWriteLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x4cc0  21  NdisAcquireReadWriteLock */
  EnterCriticalSection(param_1);
  return;
}



/* c0544cdc NdisReleaseReadWriteLock */

/* Boundary evidence: original MIPS .pdata c0544cdc..c0544cf7. Semantic name remains unreviewed. */

void NdisReleaseReadWriteLock(LPCRITICAL_SECTION param_1)

{
                    /* 0x4cdc  192  NdisReleaseReadWriteLock */
  LeaveCriticalSection(param_1);
  return;
}



/* c0544cf8 FUN_c0544cf8 */

/* Boundary evidence: original MIPS .pdata c0544cf8..c0544f13. Semantic name remains unreviewed. */

undefined4 FUN_c0544cf8(HKEY param_1,HKEY param_2,int param_3)

{
  LSTATUS LVar1;
  LPBYTE lpData;
  LPWSTR lpValueName;
  int iVar2;
  undefined4 uVar3;
  DWORD local_40;
  DWORD local_3c;
  DWORD local_38;
  DWORD local_34;
  SIZE_T local_30;
  DWORD local_2c;
  
  LVar1 = RegQueryInfoKeyW(param_2,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_40,&local_2c,
                           &local_3c,&local_34,&local_38,&local_30,(LPDWORD)0x0,(PFILETIME)0x0);
  if (LVar1 == 0) {
    lpData = LocalAlloc(0x40,local_30);
    local_38 = local_38 + 1;
    lpValueName = LocalAlloc(0x40,local_38 * 2);
    if ((lpData == (LPBYTE)0x0) || (lpValueName == (LPWSTR)0x0)) {
      uVar3 = 0;
    }
    else {
      local_40 = 0;
      uVar3 = 1;
      do {
        local_2c = local_38;
        local_3c = local_30;
        LVar1 = RegEnumValueW(param_2,local_40,lpValueName,&local_2c,(LPDWORD)0x0,&local_34,lpData,
                              &local_3c);
        if (LVar1 == 0x103) break;
        if ((param_3 == 1) &&
           (LVar1 = RegQueryValueExW(param_1,lpValueName,(LPDWORD)0x0,&local_34,lpData,&local_3c),
           LVar1 == 0)) {
          local_40 = local_40 + 1;
          iVar2 = 0;
        }
        else {
          iVar2 = RegSetValueExW(param_1,lpValueName,0,local_34,lpData,local_3c);
          if (iVar2 != 0) {
            uVar3 = 0;
          }
        }
        local_40 = local_40 + 1;
      } while (iVar2 == 0);
    }
    if (lpData != (LPBYTE)0x0) {
      LocalFree(lpData);
    }
    if (lpValueName != (LPWSTR)0x0) {
      LocalFree(lpValueName);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* c0544f14 FUN_c0544f14 */

/* Boundary evidence: original MIPS .pdata c0544f14..c05450c7. Semantic name remains unreviewed. */

int FUN_c0544f14(HKEY param_1,HKEY param_2,int param_3)

{
  int iVar1;
  LPCWSTR lpName;
  LSTATUS LVar2;
  DWORD dwIndex;
  HKEY local_38;
  HKEY local_34;
  DWORD local_30 [2];
  
  iVar1 = FUN_c0544cf8(param_1,param_2,param_3);
  if ((iVar1 == 0) || (lpName = LocalAlloc(0x40,0x100), lpName == (LPCWSTR)0x0)) {
    iVar1 = 0;
  }
  else {
    dwIndex = 0;
    while (iVar1 == 1) {
      local_30[0] = 0x80;
      LVar2 = RegEnumKeyExW(param_2,dwIndex,lpName,local_30,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            (PFILETIME)0x0);
      if (LVar2 == 0x103) break;
      LVar2 = RegCreateKeyExW(param_1,lpName,0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_38,
                              (LPDWORD)0x0);
      if (LVar2 != 0) {
LAB_c0545088:
        iVar1 = 0;
        break;
      }
      LVar2 = RegOpenKeyExW(param_2,lpName,0,0,&local_34);
      if (LVar2 != 0) {
        RegCloseKey(local_38);
        goto LAB_c0545088;
      }
      iVar1 = FUN_c0544f14(local_38,local_34,param_3);
      RegCloseKey(local_38);
      RegCloseKey(local_34);
      dwIndex = dwIndex + 1;
    }
    LocalFree(lpName);
  }
  return iVar1;
}



/* c05450c8 FUN_c05450c8 */

/* Boundary evidence: original MIPS .pdata c05450c8..c05451a7. Semantic name remains unreviewed. */

int FUN_c05450c8(LPCWSTR param_1,LPCWSTR param_2,int param_3)

{
  LSTATUS LVar1;
  int iVar2;
  HKEY local_20;
  HKEY local_1c;
  
  iVar2 = 0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,param_1,0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_1c,(LPDWORD)0x0);
  if (LVar1 == 0) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_2,0,0,&local_20);
    if (LVar1 == 0) {
      iVar2 = FUN_c0544f14(local_1c,local_20,param_3);
      RegCloseKey(local_20);
    }
    RegCloseKey(local_1c);
  }
  return iVar2;
}



/* c05451a8 FUN_c05451a8 */

/* Boundary evidence: original MIPS .pdata c05451a8..c054531f. Semantic name remains unreviewed. */

void FUN_c05451a8(LPCWSTR param_1,short *param_2,short *param_3,int param_4,undefined4 *param_5,
                 undefined4 param_6)

{
  int iVar1;
  int local_440 [2];
  wchar_t awStack_438 [260];
  short asStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c05653c8;
  *param_5 = 0;
  StringCchPrintfW(awStack_438,0x104,L"%s\\%s\\%s",L"Comm",param_2,L"Parms");
  iVar1 = FUN_c05450c8(awStack_438,param_1,0);
  if (iVar1 != 0) {
    FUN_c05605b8((HKEY)0x80000002,awStack_438,L"BusType",param_4);
    FUN_c05605b8((HKEY)0x80000002,awStack_438,L"PlugAndPlay",1);
    iVar1 = FUN_c0560544((HKEY)0x80000002,awStack_438,L"Miniport",(LPBYTE)asStack_230,0x208);
    if (iVar1 != 0) {
      param_3 = asStack_230;
    }
    iVar1 = FUN_c0560594((HKEY)0x80000002,awStack_438,L"BusNumber",(LPBYTE)local_440);
    if (iVar1 != 0) {
      FUN_c0560094(L"\\Comm",param_3,L"NDIS",param_2,param_4,local_440[0],FUN_c055173c,param_5,
                   param_6);
    }
  }
  FUN_c05625b0(local_28);
  return;
}



/* c0545320 FUN_c0545320 */

/* Boundary evidence: original MIPS .pdata c0545320..c05453cb. Semantic name remains unreviewed. */

bool FUN_c0545320(undefined4 param_1)

{
  LSTATUS LVar1;
  HKEY local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c05653c8;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s\\%s",L"Comm",L"BusFriendlyNameList",param_1);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,awStack_218,0,0,local_220);
  if (LVar1 == 0) {
    RegCloseKey(local_220[0]);
  }
  FUN_c05625b0(local_10);
  return LVar1 == 0;
}



/* c05453cc FUN_c05453cc */

/* Boundary evidence: original MIPS .pdata c05453cc..c054546f. Semantic name remains unreviewed. */

void FUN_c05453cc(undefined4 param_1)

{
  LSTATUS LVar1;
  HKEY local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c05653c8;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s\\%s",L"Comm",L"BusFriendlyNames",param_1);
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,awStack_218,0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,
                          local_220,(LPDWORD)0x0);
  if (LVar1 == 0) {
    RegCloseKey(local_220[0]);
  }
  FUN_c05625b0(local_10);
  return;
}



/* c0545470 NdisPCIBusDeviceInit */

/* Boundary evidence: original MIPS .pdata c0545470..c0545553. Semantic name remains unreviewed. */

undefined4 NdisPCIBusDeviceInit(LPCWSTR param_1)

{
  wchar_t *pwVar1;
  size_t sVar2;
  LPCWSTR _Str;
  undefined4 local_430;
  wchar_t awStack_42a [261];
  wchar_t awStack_220 [260];
  uint local_18;
  
                    /* 0x5470  172  NdisPCIBusDeviceInit */
  local_18 = DAT_c05653c8;
  local_430 = 0;
  _Str = param_1;
  while (pwVar1 = wcschr(_Str,L'\\'), pwVar1 != (wchar_t *)0x0) {
    _Str = pwVar1 + 1;
  }
  if (_Str == (wchar_t *)0x0) {
    FUN_c05625b0(local_18);
    local_430 = 0x32;
  }
  else {
    StringCchPrintfW(awStack_220,0x104,L"%s\\%s",&DAT_c0541094,_Str);
    wcscpy(awStack_42a + 1,_Str);
    sVar2 = wcslen(awStack_42a + 1);
    awStack_42a[sVar2] = L'\0';
    FUN_c05451a8(param_1,awStack_220,awStack_42a + 1,5,&local_430,0);
    FUN_c05625b0(local_18);
  }
  return local_430;
}



/* c0545554 FUN_c0545554 */

/* Boundary evidence: original MIPS .pdata c0545554..c0545767. Semantic name remains unreviewed. */

undefined4 FUN_c0545554(LPCWSTR param_1)

{
  bool bVar1;
  LSTATUS LVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined3 extraout_var;
  int iVar5;
  size_t sVar6;
  wchar_t *_Str;
  HKEY local_640;
  int local_63c;
  undefined4 local_638 [2];
  wchar_t awStack_630 [259];
  wchar_t awStack_42a [261];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c05653c8;
  local_638[0] = 0;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_640);
  if (LVar2 != 0) goto LAB_c0545744;
  iVar3 = FUN_c0560544(local_640,(LPCWSTR)0x0,L"key",(LPBYTE)awStack_220,0x208);
  if ((iVar3 != 0) &&
     (iVar3 = FUN_c0560544(local_640,(LPCWSTR)0x0,L"BusName",(LPBYTE)awStack_630,0x208), iVar3 != 0)
     ) {
    _Str = awStack_220;
    pwVar4 = wcschr(awStack_220,L'\\');
    if (pwVar4 != (wchar_t *)0x0) {
      do {
        _Str = pwVar4 + 1;
        pwVar4 = wcschr(_Str,L'\\');
      } while (pwVar4 != (wchar_t *)0x0);
      if (_Str == (wchar_t *)0x0) goto LAB_c0545734;
    }
    wcscat(awStack_630,L"\\");
    wcscat(awStack_630,_Str);
    FUN_c05453cc(awStack_630);
    bVar1 = FUN_c0545320(awStack_630);
    iVar3 = local_63c;
    if (CONCAT31(extraout_var,bVar1) == 0) {
      iVar3 = CreateBusAccessHandle(param_1);
      if ((iVar3 == 0) || (iVar5 = GetBusNamePrefix(iVar3,awStack_630,0x104), iVar5 != 0)) {
        wcscat(awStack_630,L"\\");
      }
      else {
        wcscpy(awStack_630,L"???\\");
      }
      wcscat(awStack_630,_Str);
    }
    wcscpy(awStack_42a + 1,_Str);
    sVar6 = wcslen(awStack_42a + 1);
    awStack_42a[sVar6] = L'\0';
    iVar5 = FUN_c0560594(local_640,(LPCWSTR)0x0,L"InterfaceType",(LPBYTE)&local_63c);
    if (iVar5 != 0) {
      FUN_c05451a8(awStack_220,awStack_630,awStack_42a + 1,local_63c,local_638,iVar3);
    }
  }
LAB_c0545734:
  RegCloseKey(local_640);
LAB_c0545744:
  FUN_c05625b0(local_18);
  return local_638[0];
}



/* c0545768 NDS_Deinit */

/* Boundary evidence: original MIPS .pdata c0545768..c0545797. Semantic name remains unreviewed. */

undefined4 NDS_Deinit(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
                    /* 0x5768  14  NDS_Deinit */
  if (param_1 != (int *)0x4d15ba5e) {
    FUN_c054c04c(param_1,param_2,param_3,param_4);
  }
  return 1;
}



/* c0545798 NDS_Open */

undefined4 NDS_Open(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x5798  17  NDS_Open */
  uVar1 = 0x4d15ba5e;
  if (param_1 != 0x4d15ba5e) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c05457b4 FUN_c05457b4 */

/* Boundary evidence: original MIPS .pdata c05457b4..c05458eb. Semantic name remains unreviewed. */

undefined4 FUN_c05457b4(void)

{
  bool bVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  for (iVar2 = DAT_c0565408; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x250)) {
    if (((*(uint *)(iVar2 + 0x490) & 4) != 0) || (bVar1 = true, (*(uint *)(iVar2 + 0x248) & 1) == 0)
       ) {
      bVar1 = false;
    }
    if ((((*(int *)(iVar2 + 0x124) != -2) && (*(int *)(iVar2 + 0x488) != 0)) &&
        ((!bVar1 || (*(int *)(iVar2 + 0x49c) == 0)))) &&
       (((*(uint *)(iVar2 + 0x54) & 0x1000000) == 0 && (*(int *)(*(int *)(iVar2 + 8) + 0x4c) != 0)))
       ) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      *(uint *)(iVar2 + 0x490) = *(uint *)(iVar2 + 0x490) | 1;
      if ((*(uint *)(iVar2 + 0x54) & 0x40000) == 0) {
        FUN_c054cc28(iVar2,3,0);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      }
      else {
        FUN_c0554eb0(iVar2);
      }
    }
  }
  DAT_c0565694 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  return 0;
}



/* c05458ec FUN_c05458ec */

/* Boundary evidence: original MIPS .pdata c05458ec..c05459db. Semantic name remains unreviewed. */

undefined4 FUN_c05458ec(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  iVar1 = DAT_c0565408;
  do {
    if (iVar1 == 0) {
LAB_c05459b8:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
      return 0;
    }
    if (iVar1 == param_1) {
      if (((*(uint *)(iVar1 + 0x54) & 0x1000000) == 0) &&
         (*(int *)(*(int *)(iVar1 + 8) + 0x4c) != 0)) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        *(uint *)(iVar1 + 0x490) = *(uint *)(iVar1 + 0x490) | 1;
        if ((*(uint *)(iVar1 + 0x54) & 0x40000) == 0) {
          FUN_c054cc28(iVar1,3,0);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        }
        else {
          FUN_c0554eb0(iVar1);
        }
      }
      goto LAB_c05459b8;
    }
    iVar1 = *(int *)(iVar1 + 0x250);
  } while( true );
}



/* c05459dc FUN_c05459dc */

/* Boundary evidence: original MIPS .pdata c05459dc..c0545a93. Semantic name remains unreviewed. */

void FUN_c05459dc(void)

{
  HANDLE hObject;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  if (DAT_c0565694 == 1) {
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05457b4,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CeSetThreadPriority(hObject,DAT_c0565698 + 8);
      CloseHandle(hObject);
      DAT_c0565694 = 2;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  return;
}



/* c0545a94 FUN_c0545a94 */

/* Boundary evidence: original MIPS .pdata c0545a94..c0545b2f. Semantic name remains unreviewed. */

bool FUN_c0545a94(int *param_1,uint *param_2,wchar_t *param_3)

{
  size_t sVar1;
  uint uVar2;
  uint _Size;
  
  sVar1 = wcslen(param_3);
  uVar2 = *param_2;
  _Size = (sVar1 + 1) * 2;
  if (_Size <= uVar2) {
    memmove((void *)*param_1,param_3,_Size);
    *param_1 = *param_1 + _Size;
    *param_2 = *param_2 + (sVar1 + 1) * -2;
  }
  return _Size <= uVar2;
}



/* c0545b30 NdisGetAdapterNames */

/* Boundary evidence: original MIPS .pdata c0545b30..c0545c6f. Semantic name remains unreviewed. */

void NdisGetAdapterNames(undefined4 *param_1,int param_2,uint param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  int local_res4 [3];
  uint local_30 [2];
  
                    /* 0x5b30  70  NdisGetAdapterNames */
  *param_1 = 0;
  local_res4[0] = param_2;
  local_30[0] = param_3;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  for (iVar2 = DAT_c0565408; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x250)) {
    if ((*(int *)(iVar2 + 0x354) == 1) &&
       (bVar1 = FUN_c0545a94(local_res4,local_30,*(wchar_t **)(iVar2 + 0x14)),
       CONCAT31(extraout_var,bVar1) == 0)) {
      *param_1 = 0xc0000001;
    }
  }
  bVar1 = FUN_c0545a94(local_res4,local_30,L"");
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    *param_1 = 0xc0000001;
  }
  *param_4 = param_3 - local_30[0];
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  return;
}



/* c0545c70 FUN_c0545c70 */

/* Boundary evidence: original MIPS .pdata c0545c70..c0545c7b. Semantic name remains unreviewed. */

undefined4 FUN_c0545c70(void)

{
  return 1;
}



/* c0545c7c NdisGetProtocolNames */

/* Boundary evidence: original MIPS .pdata c0545c7c..c0545d9b. Semantic name remains unreviewed. */

void NdisGetProtocolNames(undefined4 *param_1,int param_2,uint param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  int local_res4 [3];
  uint local_28 [2];
  
  local_res4[0] = param_2;
                    /* 0x5c7c  81  NdisGetProtocolNames */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  *param_1 = 0;
  iVar2 = DAT_c0565404;
  local_28[0] = param_3;
  while( true ) {
    if (iVar2 == 0) break;
    bVar1 = FUN_c0545a94(local_res4,local_28,*(wchar_t **)(iVar2 + 0x58));
    if (CONCAT31(extraout_var,bVar1) == 0) {
      *param_1 = 0xc0000001;
    }
    iVar2 = *(int *)(iVar2 + 0x20);
  }
  bVar1 = FUN_c0545a94(local_res4,local_28,L"");
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    *param_1 = 0xc0000001;
  }
  *param_4 = param_3 - local_28[0];
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c0545d9c FUN_c0545d9c */

/* Boundary evidence: original MIPS .pdata c0545d9c..c0545da7. Semantic name remains unreviewed. */

undefined4 FUN_c0545d9c(void)

{
  return 1;
}



/* c0545da8 FUN_c0545da8 */

/* Boundary evidence: original MIPS .pdata c0545da8..c0545dff. Semantic name remains unreviewed. */

int FUN_c0545da8(wchar_t *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_c0565408;
  while ((iVar2 != 0 && (iVar1 = _wcsicmp(param_1,*(wchar_t **)(iVar2 + 0x14)), iVar1 != 0))) {
    iVar2 = *(int *)(iVar2 + 0x250);
  }
  return iVar2;
}



/* c0545e00 NdisGetAdapterBindings */

/* Boundary evidence: original MIPS .pdata c0545e00..c0545fa3. Semantic name remains unreviewed. */

void NdisGetAdapterBindings
               (undefined4 *param_1,wchar_t *param_2,int param_3,uint param_4,int *param_5)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int local_res8 [2];
  uint local_28 [2];
  
                    /* 0x5e00  69  NdisGetAdapterBindings */
  local_28[1] = 0;
  local_res8[0] = param_3;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  iVar2 = FUN_c0545da8(param_2);
  if (iVar2 == 0) {
    *param_1 = 0xc0010006;
  }
  else {
    *param_1 = 0;
    local_28[0] = param_4;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    local_28[1] = 1;
    for (iVar2 = *(int *)(iVar2 + 0x18); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
      bVar1 = FUN_c0545a94(local_res8,local_28,*(wchar_t **)(*(int *)(iVar2 + 0xc) + 0x58));
      if (CONCAT31(extraout_var,bVar1) == 0) {
        *param_1 = 0xc0000001;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    local_28[1] = 0;
    bVar1 = FUN_c0545a94(local_res8,local_28,L"");
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      *param_1 = 0xc0000001;
    }
    *param_5 = param_4 - local_28[0];
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  return;
}



/* c0545fa4 FUN_c0545fa4 */

/* Boundary evidence: original MIPS .pdata c0545fa4..c0545faf. Semantic name remains unreviewed. */

undefined4 FUN_c0545fa4(void)

{
  return 1;
}



/* c0545fb0 NdisRegisterAdapter */

/* Boundary evidence: original MIPS .pdata c0545fb0..c0545ff7. Semantic name remains unreviewed. */

void NdisRegisterAdapter(int *param_1,short *param_2,short *param_3)

{
  int iVar1;
  
                    /* 0x5fb0  189  NdisRegisterAdapter */
  iVar1 = FUN_c0560120(L"\\Comm",param_2,L"NDIS",param_3,FUN_c055173c);
  *param_1 = iVar1;
  return;
}



/* c0545ff8 NdisDeregisterAdapter */

/* Boundary evidence: original MIPS .pdata c0545ff8..c05460f3. Semantic name remains unreviewed. */

void NdisDeregisterAdapter
               (undefined4 *param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  wchar_t *pwVar4;
  int *piVar5;
  
                    /* 0x5ff8  49  NdisDeregisterAdapter */
  *param_1 = 0xc0000001;
  pwVar4 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  iVar2 = FUN_c0545da8(param_2);
  if ((((iVar2 == 0) || ((*(ushort *)(*(int *)(iVar2 + 8) + 0xb8) & 1) != 0)) ||
      ((*(uint *)(iVar2 + 0x248) & 0x80000000) != 0)) ||
     (bVar1 = FUN_c055a404(iVar2 + 0x20), CONCAT31(extraout_var,bVar1) == 0)) {
    iVar2 = 0;
  }
  else {
    *(uint *)(iVar2 + 0x248) = *(uint *)(iVar2 + 0x248) | 0x80000000;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  if (iVar2 != 0) {
    piVar5 = *(int **)(iVar2 + 0x1c8);
    if ((*(int **)(iVar2 + 0x50) != (int *)0x0) &&
       (pwVar4 = *(wchar_t **)(iVar2 + 0x170), pwVar4 != (wchar_t *)0x0)) {
      param_3 = *(undefined4 *)(iVar2 + 0xc);
      FUN_c0554db0(*(int **)(iVar2 + 0x50),(undefined *)pwVar4,param_3);
    }
    FUN_c0559738(iVar2);
    uVar3 = FUN_c054c04c(piVar5,pwVar4,param_3,param_4);
    *param_1 = uVar3;
  }
  return;
}



/* c05460f4 FUN_c05460f4 */

/* Boundary evidence: original MIPS .pdata c05460f4..c0546133. Semantic name remains unreviewed. */

undefined4 FUN_c05460f4(int *param_1)

{
  undefined4 uVar1;
  
  if ((char)param_1[2] == '\0') {
    uVar1 = FUN_c0559364(*param_1,param_1[1]);
  }
  else {
    FUN_c0551fd4(*param_1,(int *)param_1[1],1);
    uVar1 = 0;
  }
  return uVar1;
}



/* c0546134 FUN_c0546134 */

/* Boundary evidence: original MIPS .pdata c0546134..c0546247. Semantic name remains unreviewed. */

DWORD FUN_c0546134(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *lpParameter;
  HANDLE hHandle;
  BOOL BVar1;
  DWORD local_20 [2];
  
  local_20[0] = 0xc000009a;
  lpParameter = FUN_c05427a0(0xc);
  if (lpParameter != (undefined4 *)0x0) {
    *lpParameter = param_1;
    lpParameter[1] = param_2;
    *(undefined1 *)(lpParameter + 2) = param_3;
    hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05460f4,lpParameter,0,(LPDWORD)0x0);
    if (hHandle != (HANDLE)0x0) {
      CeSetThreadPriority(hHandle,DAT_c0565698 + 0xc);
      WaitForSingleObject(hHandle,0xffffffff);
      BVar1 = GetExitCodeThread(hHandle,local_20);
      if (BVar1 == 0) {
        local_20[0] = 0xc0000001;
      }
      CloseHandle(hHandle);
    }
    CTEFreeMem(lpParameter);
  }
  return local_20[0];
}



/* c0546248 FUN_c0546248 */

/* Boundary evidence: original MIPS .pdata c0546248..c0546333. Semantic name remains unreviewed. */

void FUN_c0546248(int *param_1,short *param_2,short *param_3,undefined *param_4,undefined4 param_5)

{
  int iVar1;
  int local_28;
  int local_24;
  ushort auStack_20 [4];
  ushort auStack_18 [4];
  
  FUN_c055f4e4(auStack_20,param_2);
  local_28 = 0;
  FUN_c054af98(auStack_20,&local_28);
  *param_1 = 0;
  if (local_28 == 0) {
    *param_1 = -0x3ffefffa;
    return;
  }
  local_24 = 0;
  if (param_3 != (short *)0x0) {
    FUN_c055f4e4(auStack_18,param_3);
    FUN_c0548940(auStack_18,&local_24,0);
    if (local_24 == 0) {
      *param_1 = -0x3fffffff;
    }
    if (*param_1 != 0) goto LAB_c0546304;
  }
  iVar1 = (*(code *)param_4)(local_28,local_24,param_5);
  *param_1 = iVar1;
LAB_c0546304:
  if (local_24 != 0) {
    FUN_c0548ad8(local_24);
  }
  FUN_c0559738(local_28);
  return;
}



/* c0546334 NdisBindProtocolsToAdapter */

/* Boundary evidence: original MIPS .pdata c0546334..c054635b. Semantic name remains unreviewed. */

void NdisBindProtocolsToAdapter(int *param_1,short *param_2,short *param_3)

{
                    /* 0x6334  34  NdisBindProtocolsToAdapter */
  FUN_c0546248(param_1,param_2,param_3,FUN_c0546134,1);
  return;
}



/* c054635c NdisUnbindProtocolsFromAdapter */

/* Boundary evidence: original MIPS .pdata c054635c..c054637f. Semantic name remains unreviewed. */

void NdisUnbindProtocolsFromAdapter(int *param_1,short *param_2,short *param_3)

{
                    /* 0x635c  213  NdisUnbindProtocolsFromAdapter */
  FUN_c0546248(param_1,param_2,param_3,FUN_c0546134,0);
  return;
}



/* c0546380 NdisRebindProtocolsToAdapter */

/* Boundary evidence: original MIPS .pdata c0546380..c05463fb. Semantic name remains unreviewed. */

void NdisRebindProtocolsToAdapter(int *param_1,short *param_2,short *param_3)

{
                    /* 0x6380  188  NdisRebindProtocolsToAdapter */
  FUN_c0546248(param_1,param_2,param_3,FUN_c0546134,0);
  FUN_c0546248(param_1,param_2,param_3,FUN_c0546134,1);
  return;
}



/* c05463fc NdisMRebindProtocolsToAdapter */

/* Boundary evidence: original MIPS .pdata c05463fc..c054647f. Semantic name remains unreviewed. */

void NdisMRebindProtocolsToAdapter(int param_1)

{
  bool bVar1;
  int iVar2;
  
                    /* 0x63fc  139  NdisMRebindProtocolsToAdapter */
  iVar2 = __GetUserKData(8);
  bVar1 = *(int *)(param_1 + 0x4b4) == iVar2;
  if (bVar1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
    *(undefined4 *)(param_1 + 0x454) = 0;
    *(undefined4 *)(param_1 + 0x458) = 0;
  }
  FUN_c0546134(param_1,0,0);
  FUN_c0546134(param_1,0,1);
  if (bVar1) {
    FUN_c054b758(param_1);
  }
  return;
}



/* c0546480 FUN_c0546480 */

undefined4 FUN_c0546480(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_1 != 1) && (uVar1 = 2, param_1 != 2)) {
    if (param_1 == 3) {
      uVar1 = 4;
    }
    else {
      uVar1 = 0;
      if (param_1 == 4) {
        uVar1 = 8;
      }
    }
  }
  return uVar1;
}



/* c05464cc FUN_c05464cc */

/* Boundary evidence: original MIPS .pdata c05464cc..c0546523. Semantic name remains unreviewed. */

undefined4 FUN_c05464cc(int param_1,int param_2,int param_3)

{
  int local_10 [2];
  
  if ((-1 < param_1) && (2 < param_1)) {
    if (param_1 == 3) {
      FUN_c055cb54(param_2,local_10,param_3);
      return local_10[0];
    }
    if (param_1 == 4) {
      return 4;
    }
  }
  return 1;
}



/* c0546524 FUN_c0546524 */

/* Boundary evidence: original MIPS .pdata c0546524..c0546603. Semantic name remains unreviewed. */

undefined4 FUN_c0546524(int param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  
  if (((*(uint *)(param_1 + 0x490) & 4) == 0) && ((*(uint *)(param_1 + 0x248) & 1) != 0)) {
    memset(param_2,0,0x30);
    uVar1 = FUN_c0546480(*(int *)(param_1 + 0x27c));
    uVar2 = FUN_c0546480(*(int *)(param_1 + 0x278));
    uVar3 = FUN_c0546480(*(int *)(param_1 + 0x274));
    uVar3 = uVar1 | uVar2 | uVar3;
    uVar5 = 0x11;
    if (uVar3 != 0) {
      uVar5 = 0x19;
    }
    *param_2 = uVar5;
    uVar4 = 0;
    param_2[1] = (char)uVar3;
    param_2[2] = 0;
    *(undefined4 *)(param_2 + 4) = 0xffffffff;
    *(undefined4 *)(param_2 + 8) = 0xffffffff;
    *(undefined4 *)(param_2 + 0xc) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x18) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x1c) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x20) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x24) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x28) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x2c) = 0;
  }
  else {
    uVar4 = 0xc00000bb;
  }
  return uVar4;
}



/* c0546604 FUN_c0546604 */

/* Boundary evidence: original MIPS .pdata c0546604..c054671f. Semantic name remains unreviewed. */

void FUN_c0546604(int param_1)

{
  int iVar1;
  HMODULE hLibModule;
  code *pcVar2;
  undefined1 auStack_250 [48];
  wchar_t awStack_220 [259];
  undefined2 local_1a;
  uint local_18;
  
  local_18 = DAT_c05653c8;
  iVar1 = FUN_c0546524(param_1,auStack_250);
  if ((iVar1 == 0) && (hLibModule = LoadLibraryW(L"coredll.dll"), hLibModule != (HMODULE)0x0)) {
    pcVar2 = (code *)GetProcAddressW(hLibModule,L"RegisterPowerRelationship");
    if (pcVar2 != (code *)0x0) {
      iVar1 = _snwprintf(awStack_220,0x103,L"%s\\%s",L"{98C5250D-C29A-4985-AE5F-AFE5367E5006}",
                         *(undefined4 *)(param_1 + 0x14));
      local_1a = 0;
      if (iVar1 != -1) {
        iVar1 = (*pcVar2)(&UNK_c05411a4,awStack_220,auStack_250,1);
        if (iVar1 != 0) {
          *(int *)(param_1 + 0x498) = iVar1;
          *(uint *)(param_1 + 0x490) = *(uint *)(param_1 + 0x490) | 2;
          AdvertiseInterface(&DAT_c05651dc,*(undefined4 *)(param_1 + 0x14),1);
        }
        *(undefined4 *)(param_1 + 0x49c) = 0;
      }
    }
    FreeLibrary(hLibModule);
  }
  FUN_c05625b0(local_18);
  return;
}



/* c0546720 FUN_c0546720 */

/* Boundary evidence: original MIPS .pdata c0546720..c05467cf. Semantic name remains unreviewed. */

void FUN_c0546720(int param_1)

{
  HMODULE hLibModule;
  code *pcVar1;
  
  if (((*(uint *)(param_1 + 0x490) & 2) != 0) &&
     (hLibModule = LoadLibraryW(L"coredll.dll"), hLibModule != (HMODULE)0x0)) {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"ReleasePowerRelationship");
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(*(undefined4 *)(param_1 + 0x498));
      *(uint *)(param_1 + 0x490) = *(uint *)(param_1 + 0x490) & 0xfffffffd;
      AdvertiseInterface(&DAT_c05651dc,*(undefined4 *)(param_1 + 0x14),0);
    }
    FreeLibrary(hLibModule);
  }
  return;
}



/* c05467d0 FUN_c05467d0 */

/* Boundary evidence: original MIPS .pdata c05467d0..c05468b3. Semantic name remains unreviewed. */

undefined4 FUN_c05467d0(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  short *local_20 [2];
  ushort auStack_18 [4];
  
  uVar2 = 0xc0000001;
  local_20[0] = (short *)0x0;
  if ((param_1 != 0) && (0xf < param_2)) {
    iVar1 = CeOpenCallerBuffer(local_20,*(undefined4 *)(param_1 + 0xc),0,5,0);
    if (iVar1 < 0) {
      uVar2 = 0xc0010015;
    }
    else {
      FUN_c055f4e4(auStack_18,local_20[0]);
      *param_3 = 0;
      FUN_c054af98(auStack_18,param_3);
      if (*param_3 == 0) {
        uVar2 = 0xc0010006;
      }
      else if ((*(uint *)(*param_3 + 0x490) & 4) == 0) {
        uVar2 = 0;
      }
    }
    if (local_20[0] != (short *)0x0) {
      CeCloseCallerBuffer(local_20[0],*(undefined4 *)(param_1 + 0xc),0,5);
    }
  }
  return uVar2;
}



/* c05468b4 FUN_c05468b4 */

/* Boundary evidence: original MIPS .pdata c05468b4..c054690b. Semantic name remains unreviewed. */

undefined4 FUN_c05468b4(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  *param_4 = 0;
  if (param_1 != 0) {
    if (param_2 == 0) {
      return 0;
    }
    param_2 = CeAllocAsynchronousBuffer(param_4,param_1,param_2,param_3);
  }
  if (param_2 != 0) {
    return 0;
  }
  return 1;
}



/* c054690c NDS_IOControl */

/* Boundary evidence: original MIPS .pdata c054690c..c0547217. Semantic name remains unreviewed. */

bool NDS_IOControl(int param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6,
                  int param_7)

{
  bool bVar1;
  wchar_t *pwVar2;
  int iVar3;
  size_t sVar4;
  int *piVar5;
  undefined4 uVar6;
  wchar_t *pwVar7;
  uint **ppuVar8;
  code *pcVar9;
  int iVar10;
  uint local_260;
  int local_25c;
  wchar_t *local_258;
  int *local_254;
  int local_250;
  uint *local_24c;
  int local_248;
  int local_244;
  int local_240;
  int local_23c;
  undefined1 auStack_238 [520];
  uint local_30;
  
                    /* 0x690c  15  NDS_IOControl */
  local_30 = DAT_c05653c8;
  local_244 = param_5;
  local_23c = param_5;
  local_248 = param_7;
  local_260 = 0;
  local_258 = (wchar_t *)0x0;
  local_254 = (int *)0x0;
  local_24c = (uint *)0x0;
  iVar10 = 4;
  if (param_7 == 0) {
    iVar10 = 0;
  }
  local_25c = param_3;
  local_250 = iVar10;
  local_240 = param_3;
  iVar3 = FUN_c05468b4(param_3,param_4,4,&local_258);
  if ((iVar3 == 0) || (iVar3 = FUN_c05468b4(local_244,param_6,0xc,&local_254), iVar3 == 0)) {
LAB_c0547168:
    if (local_258 != (wchar_t *)0x0) {
      CeFreeAsynchronousBuffer(local_258,param_3,param_4,4);
    }
    if (local_254 != (int *)0x0) {
      CeFreeAsynchronousBuffer(local_254,local_244,param_6,0xc);
    }
    if (local_24c != (uint *)0x0) {
      CeFreeAsynchronousBuffer(local_24c,param_7,iVar10,0xc);
    }
    FUN_c05625b0(local_30);
    return false;
  }
  ppuVar8 = &local_24c;
  uVar6 = 0xc;
  iVar3 = FUN_c05468b4(param_7,iVar10,0xc,ppuVar8);
  piVar5 = local_254;
  pwVar2 = local_258;
  if (iVar3 == 0) goto LAB_c0547168;
  if (0x17003e < param_2) {
    if (0x321004 < param_2) {
      if ((param_2 != 0x321008) && (param_2 != 0x32100c)) {
        if (param_2 != 0x321018) goto switchD_c0546a58_caseD_17001f;
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        DAT_c05653f0 = 1;
        for (piVar5 = (int *)DAT_c0565400; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          for (iVar3 = piVar5[1]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x1c)) {
            FUN_c0546604(iVar3);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        goto LAB_c05470c0;
      }
LAB_c0546ee0:
      if (((local_254 == (int *)0x0) || (param_6 < 4)) || (local_24c == (uint *)0x0)) {
        local_260 = 0xc0000001;
      }
      else {
        *local_24c = 4;
        local_260 = FUN_c05467d0((int)local_258,param_4,&local_250);
        if (local_260 == 0) {
          local_248 = FUN_c05464cc(*piVar5,local_250,(uint)(param_2 == 0x32100c));
          if (param_2 == 0x32100c) {
            local_260 = FUN_c055cdec(&local_248,local_250);
          }
          else if (param_2 == 0x321008) {
            local_260 = FUN_c055c9b4(local_248,local_250);
            if (local_260 == 0) {
              *(int *)(local_250 + 0x49c) = *piVar5;
            }
          }
          else {
            local_260 = 0;
          }
          *piVar5 = *(int *)(local_250 + 0x49c);
          FUN_c0559738(local_250);
        }
        else {
          *piVar5 = -1;
        }
      }
      goto LAB_c05470c0;
    }
    if (param_2 == 0x321004) goto LAB_c0546ee0;
    if (param_2 == 0x170042) {
      local_260 = 0xc000000d;
      if ((param_4 < 0x209) && (iVar3 = CeSafeCopyMemory(auStack_238,local_258,param_4), iVar3 != 0)
         ) {
        NdisGetAdapterBindings(&local_260,local_258,(int)local_254,param_6,(int *)local_24c);
      }
      goto LAB_c05470c0;
    }
    if (param_2 == 0x170046) {
      piVar5 = FUN_c0560fcc(L"\\Comm",local_258,L"NDIS");
      if (piVar5 == (int *)0x0) {
        local_260 = 0xc0000001;
      }
      goto LAB_c05470c0;
    }
    if (param_2 == 0x17004a) {
      if (3 < param_6) {
        iVar3 = NdisGetVersion();
        *local_254 = iVar3;
        if (7 < param_6) {
          local_254[1] = DAT_c056549c;
        }
        goto LAB_c05470c0;
      }
      local_260 = 0xc0000023;
    }
    else {
      if (param_2 == 0x321000) {
        if (param_1 != 0x4d15ba5e) {
          local_260 = 0xc0000001;
          goto LAB_c05470cc;
        }
        if (((local_254 != (int *)0x0) && (0x2f < param_6)) && (local_24c != (uint *)0x0)) {
          memset(local_254,0,0x30);
          if (local_258 == (wchar_t *)0x0) {
            piVar5[0xb] = 1;
            *(undefined1 *)piVar5 = 0;
          }
          else {
            if (param_4 < 0x10) {
              local_260 = 0xc0010016;
              goto LAB_c05470cc;
            }
            local_260 = FUN_c05467d0((int)local_258,param_4,&local_248);
            iVar3 = local_248;
            if (local_260 != 0) goto LAB_c05470c0;
            local_260 = FUN_c0546524(local_248,(undefined1 *)piVar5);
            FUN_c0559738(iVar3);
          }
          *local_24c = 0x30;
          goto LAB_c05470c0;
        }
      }
switchD_c0546a58_caseD_17001f:
      local_260 = 0xc0000001;
    }
    goto LAB_c05470cc;
  }
  if (param_2 == 0x17003e) {
    NdisGetProtocolNames(&local_260,(int)local_254,param_6,(int *)local_24c);
    goto LAB_c05470c0;
  }
  switch(param_2) {
  case 0x17001e:
    local_260 = NdisGetLogData(local_258,local_254,param_6,local_24c);
    break;
  default:
    goto switchD_c0546a58_caseD_17001f;
  case 0x170022:
    DAT_c0565694 = 1;
    FUN_c0560f08(FUN_c05459dc);
    break;
  case 0x170026:
    sVar4 = wcslen(local_258);
    local_260 = FUN_c0560120(L"\\Comm",pwVar2,L"NDIS",pwVar2 + sVar4 + 1,FUN_c055173c);
    break;
  case 0x17002a:
    NdisDeregisterAdapter(&local_260,local_258,uVar6,ppuVar8);
    break;
  case 0x17002e:
    pcVar9 = NdisRebindProtocolsToAdapter;
    goto LAB_c0546b70;
  case 0x170032:
    pcVar9 = NdisBindProtocolsToAdapter;
    goto LAB_c0546b70;
  case 0x170036:
    pcVar9 = NdisUnbindProtocolsFromAdapter;
LAB_c0546b70:
    sVar4 = wcslen(local_258);
    pwVar7 = pwVar2 + sVar4 + 1;
    if (*pwVar7 == L'\0') {
      pwVar7 = (wchar_t *)0x0;
    }
    (*pcVar9)(&local_260,pwVar2,pwVar7);
    break;
  case 0x17003a:
    NdisGetAdapterNames(&local_260,(int)local_254,param_6,(int *)local_24c);
  }
LAB_c05470c0:
  iVar3 = local_25c;
  if (local_260 != 0) {
LAB_c05470cc:
    iVar3 = local_25c;
    SetLastError(local_260);
  }
  if (local_258 != (wchar_t *)0x0) {
    CeFreeAsynchronousBuffer(local_258,iVar3,param_4,4);
  }
  if (local_254 != (int *)0x0) {
    CeFreeAsynchronousBuffer(local_254,local_244,param_6,0xc);
  }
  if (local_24c != (uint *)0x0) {
    CeFreeAsynchronousBuffer(local_24c,param_7,iVar10,0xc);
  }
  bVar1 = local_260 == 0;
  FUN_c05625b0(local_30);
  return bVar1;
}



/* c0547218 FUN_c0547218 */

/* Boundary evidence: original MIPS .pdata c0547218..c0547223. Semantic name remains unreviewed. */

undefined4 FUN_c0547218(void)

{
  return 1;
}



/* c0547224 FUN_c0547224 */

/* Boundary evidence: original MIPS .pdata c0547224..c054722f. Semantic name remains unreviewed. */

undefined4 FUN_c0547224(void)

{
  return 1;
}



/* c0547230 FUN_c0547230 */

/* Boundary evidence: original MIPS .pdata c0547230..c0547273. Semantic name remains unreviewed. */

void FUN_c0547230(int param_1)

{
  uint local_10 [2];
  
  DAT_c05653c4 = (uint)*(byte *)(param_1 + 0x14);
  local_10[0] = (uint)(DAT_c05653c4 == 1);
  FUN_c054bbf8(0,5,local_10,4);
  return;
}



/* c0547274 FUN_c0547274 */

/* Boundary evidence: original MIPS .pdata c0547274..c05474e7. Semantic name remains unreviewed. */

void FUN_c0547274(void)

{
  int *piVar1;
  HMODULE hLibModule;
  code *pcVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  DWORD DVar7;
  int *piVar8;
  uint local_2d8 [2];
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined4 local_2c0;
  undefined1 auStack_2bc [4];
  int local_2b8 [162];
  uint local_30;
  
  local_30 = DAT_c05653c8;
  local_2d0 = 0;
  memset(&local_2cc,0,0x10);
  hLibModule = LoadLibraryW(L"coredll.dll");
  if (hLibModule != (HMODULE)0x0) {
    pcVar2 = (code *)GetProcAddressW(hLibModule,L"RequestPowerNotifications");
    pcVar3 = (code *)GetProcAddressW(hLibModule,L"StopPowerNotifications");
    if ((pcVar2 != (code *)0x0) && (pcVar3 != (code *)0x0)) {
      local_2d0 = 0x14;
      local_2cc = 0;
      local_2c8 = 4;
      local_2c4 = 0x288;
      local_2c0 = 1;
      iVar4 = CreateMsgQueue(0,&local_2d0);
      if (iVar4 == 0) {
        GetLastError();
      }
      else {
        iVar5 = (*pcVar2)(iVar4,10);
        if (iVar5 == 0) {
          GetLastError();
        }
        else {
          do {
            while( true ) {
              memset(local_2b8,0,0x288);
              local_2d8[0] = 0;
              iVar6 = ReadMsgQueue(iVar4,local_2b8,0x288,local_2d8,0xffffffff,auStack_2bc);
              if (iVar6 == 0) break;
              piVar8 = local_2b8;
              for (; (0 < (int)local_2d8[0] && (0xf < local_2d8[0]));
                  local_2d8[0] = (local_2d8[0] - *piVar1) - 0x10) {
                if (*piVar8 == 2) {
                  DAT_c0565694 = 1;
                  FUN_c0560f08(FUN_c05459dc);
                }
                else if (*piVar8 == 8) {
                  FUN_c0547230((int)(piVar8 + 3));
                }
                piVar1 = piVar8 + 2;
                piVar8 = (int *)((int)piVar8 + piVar8[2] + 0x10);
              }
            }
            DVar7 = GetLastError();
          } while ((DVar7 == 0xe8) || (DVar7 == 0x5b4));
        }
        if (iVar5 != 0) {
          (*pcVar3)(iVar5);
        }
        CloseMsgQueue(iVar4);
      }
    }
    FreeLibrary(hLibModule);
  }
  FUN_c05625b0(local_30);
  return;
}



/* c05474e8 NdisQueryPacket */

/* Boundary evidence: original MIPS .pdata c05474e8..c0547603. Semantic name remains unreviewed. */

void NdisQueryPacket(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_30;
  undefined4 uStack_2c;
  
                    /* 0x74e8  181  NdisQueryPacket */
  if (param_4 != (int *)0x0) {
    *param_4 = param_1[2];
  }
  if (((param_5 != (int *)0x0) || (param_3 != (int *)0x0)) || (param_2 != (int *)0x0)) {
    if ((char)param_1[7] == '\0') {
      iVar3 = 0;
      iVar4 = 0;
      iVar5 = 0;
      for (piVar2 = (int *)param_1[2]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        NdisQueryBufferOffset((int)piVar2,&uStack_2c,&local_30);
        iVar3 = local_30 + iVar3;
        uVar1 = NDIS_BUFFER_TO_SPAN_PAGES((int)piVar2);
        iVar4 = uVar1 + iVar4;
        iVar5 = iVar5 + 1;
      }
      param_1[5] = iVar5;
      param_1[1] = iVar3;
      *param_1 = iVar4;
      *(undefined1 *)(param_1 + 7) = 1;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = *param_1;
    }
    if (param_3 != (int *)0x0) {
      *param_3 = param_1[5];
    }
    if (param_5 != (int *)0x0) {
      *param_5 = param_1[1];
    }
  }
  return;
}



/* c0547604 NDS_Init */

/* Boundary evidence: original MIPS .pdata c0547604..c05476c7. Semantic name remains unreviewed. */

int NDS_Init(LPCWSTR param_1)

{
  HANDLE hObject;
  int iVar1;
  
                    /* 0x7604  16  NDS_Init */
  if (DAT_c05653e0 == 0) {
    DAT_c05653e0 = 1;
    FUN_c055eda8();
    FUN_c0560294(L"Comm",L"NDIS",FUN_c055173c);
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0547274,(LPVOID)0x0,0,(LPDWORD)0x0);
    CloseHandle(hObject);
    RegDeleteKeyW((HKEY)0x80000002,L"Comm\\BusFriendlyNames");
    iVar1 = 0x4d15ba5e;
  }
  else {
    iVar1 = FUN_c055e534(param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_c0545554(param_1);
    }
  }
  return iVar1;
}



/* c05476c8 NdisStallExecution */

/* Boundary evidence: original MIPS .pdata c05476c8..c05476e3. Semantic name remains unreviewed. */

void NdisStallExecution(void)

{
                    /* 0x76c8  209  NdisStallExecution */
  StallExecution();
  return;
}



/* c05476e4 NdisFlushBuffer */

/* Boundary evidence: original MIPS .pdata c05476e4..c054771f. Semantic name remains unreviewed. */

void NdisFlushBuffer(int param_1)

{
                    /* 0x76e4  58  NdisFlushBuffer */
  if ((*(uint *)(param_1 + 4) & 0xe0000000) != 0xa0000000) {
    CacheRangeFlush(*(uint *)(param_1 + 4),*(undefined4 *)(param_1 + 8),4);
  }
  return;
}



/* c0547720 NdisInitializeListHead */

void NdisInitializeListHead(int param_1)

{
                    /* 0x7720  104  NdisInitializeListHead */
  *(int *)(param_1 + 4) = param_1;
  *(int *)param_1 = param_1;
  return;
}



/* c054772c NdisAllocateMemory */

/* Boundary evidence: original MIPS .pdata c054772c..c05477bb. Semantic name remains unreviewed. */

undefined4 NdisAllocateMemory(int *param_1,size_t param_2,uint param_3)

{
  void *pvVar1;
  
                    /* 0x772c  27  NdisAllocateMemory */
  if (param_3 == 0) {
    pvVar1 = FUN_c05427a0(param_2);
  }
  else {
    if ((param_3 & 2) == 0) {
      *param_1 = 0;
      if ((param_3 & 1) != 0) {
        return 0xc0000001;
      }
      goto LAB_c0547790;
    }
    pvVar1 = VirtualAlloc((LPVOID)0x0,param_2,0x1000,0x204);
  }
  *param_1 = (int)pvVar1;
LAB_c0547790:
  if (*param_1 == 0) {
    return 0xc0000001;
  }
  return 0;
}



/* c05477bc NdisAllocateMemoryWithTag */

/* Boundary evidence: original MIPS .pdata c05477bc..c0547803. Semantic name remains unreviewed. */

undefined4 NdisAllocateMemoryWithTag(undefined4 *param_1,size_t param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
                    /* 0x77bc  28  NdisAllocateMemoryWithTag */
  pvVar1 = FUN_c05427a0(param_2);
  *param_1 = pvVar1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0xc0000001;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c0547804 NdisFreeMemory */

/* Boundary evidence: original MIPS .pdata c0547804..c0547847. Semantic name remains unreviewed. */

void NdisFreeMemory(LPVOID param_1,undefined4 param_2,uint param_3)

{
                    /* 0x7804  62  NdisFreeMemory */
  if (param_3 == 0) {
    CTEFreeMem();
  }
  else if ((param_3 & 2) != 0) {
    VirtualFree(param_1,0,0x8000);
  }
  return;
}



/* c0547848 NdisPacketSize */

int NdisPacketSize(int param_1)

{
                    /* 0x7848  174  NdisPacketSize */
  return (param_1 + 0x3fU & 0xfffffff8) + DAT_c05653bc * 0x28 + 0x58;
}



/* c054787c NdisGetPoolFromPacket */

undefined4 NdisGetPoolFromPacket(int param_1)

{
                    /* 0x787c  80  NdisGetPoolFromPacket */
  return *(undefined4 *)(param_1 + 0x10);
}



/* c0547884 NdisIMGetCurrentPacketStack */

int NdisIMGetCurrentPacketStack(int param_1,undefined1 *param_2)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x7884  92  NdisIMGetCurrentPacketStack */
  uVar2 = *(uint *)(param_1 + -4);
  if (uVar2 < DAT_c05653bc) {
    iVar1 = (uVar2 - DAT_c05653bc) * 0x28 + param_1 + -8;
    *param_2 = DAT_c05653bc - uVar2 != 1;
  }
  else {
    iVar1 = 0;
    *param_2 = 0;
  }
  return iVar1;
}



/* c05478e0 NdisAllocatePacketPoolEx */

/* Boundary evidence: original MIPS .pdata c05478e0..c0547a1f. Semantic name remains unreviewed. */

void NdisAllocatePacketPoolEx
               (undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4,int param_5)

{
  int *_Dst;
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  size_t _Size;
  
                    /* 0x78e0  31  NdisAllocatePacketPoolEx */
  uVar5 = (param_5 + 0x3fU & 0xfff8) + DAT_c05653bc * 0x28 + 0x5b & 0xfff8;
  _Size = uVar5 * param_3 + 0x38;
  uVar4 = 0xc000009a;
  _Dst = FUN_c05427a0(_Size);
  if (_Dst != (int *)0x0) {
    memset(_Dst,0,_Size);
    *_Dst = (int)_Dst + _Size;
    *(short *)(_Dst + 1) = (short)uVar5;
    _Dst[2] = param_3;
    _Dst[3] = 0;
    _Dst[4] = param_4;
    _Dst[5] = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 7));
    if (param_3 == 0) {
      _Dst[0xc] = 0;
    }
    else {
      piVar1 = _Dst + 0xd;
      _Dst[0xc] = (int)piVar1;
      if (1 < param_3) {
        iVar3 = param_3 - 1;
        piVar2 = piVar1;
        do {
          piVar1 = (int *)((int)piVar2 + uVar5);
          *piVar2 = (int)piVar1;
          iVar3 = iVar3 + -1;
          piVar2 = piVar1;
        } while (iVar3 != 0);
      }
      *piVar1 = 0;
    }
    uVar4 = 0;
  }
  *param_1 = uVar4;
  *param_2 = _Dst;
  return;
}



/* c0547a20 NdisAllocatePacket */

/* Boundary evidence: original MIPS .pdata c0547a20..c0547bab. Semantic name remains unreviewed. */

void NdisAllocatePacket(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *_Dst;
  
                    /* 0x7a20  29  NdisAllocatePacket
                       0x7a20  52  NdisDprAllocatePacket
                       0x7a20  53  NdisDprAllocatePacketNonInterlocked */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  puVar2 = *(undefined4 **)(param_3 + 0x30);
  if (puVar2 == (undefined4 *)0x0) {
    if ((*(uint *)(param_3 + 0x14) < *(uint *)(param_3 + 0x10)) &&
       (puVar2 = FUN_c05427a0((uint)*(ushort *)(param_3 + 4)), puVar2 != (undefined4 *)0x0)) {
      *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + 1;
    }
  }
  else {
    *(undefined4 *)(param_3 + 0x30) = *puVar2;
    *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (puVar2 == (undefined4 *)0x0) {
    *param_2 = 0;
    *param_1 = 0xc000009a;
  }
  else {
    puVar2 = puVar2 + DAT_c05653bc * 10;
    _Dst = puVar2 + 2;
    memset(_Dst,0,((uint)*(ushort *)(param_3 + 4) + DAT_c05653bc * -0x28) - 8);
    *(undefined1 *)((int)puVar2 + 0x25) = 0;
    puVar2[6] = param_3;
    puVar2[8] = *(undefined4 *)(param_3 + 0x18);
    uVar1 = (uint)*(ushort *)(param_3 + 4) + DAT_c05653bc * -0x28 + 0xffac;
    *(short *)((int)puVar2 + 0x26) = (short)uVar1;
    *(undefined4 **)((int)_Dst + (uVar1 & 0xffff) + 0x3c) = _Dst;
    puVar2[1] = 0xffffffff;
    *puVar2 = 0xffffffff;
    *(undefined4 **)((int)_Dst + *(ushort *)((int)puVar2 + 0x26) + 0x3c) = _Dst;
    puVar2[4] = 0;
    *(undefined1 *)(puVar2 + 9) = 0;
    *(undefined1 *)((int)puVar2 + 0x25) = 0x80;
    *param_2 = _Dst;
    *param_1 = 0;
  }
  return;
}



/* c0547bac NdisDprFreePacket */

/* Boundary evidence: original MIPS .pdata c0547bac..c0547c5f. Semantic name remains unreviewed. */

void NdisDprFreePacket(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  
                    /* 0x7bac  54  NdisDprFreePacket
                       0x7bac  55  NdisDprFreePacketNonInterlocked
                       0x7bac  63  NdisFreePacket */
  *(undefined1 *)(param_1 + 0x1d) = 0;
  puVar1 = *(uint **)(param_1 + 0x10);
  puVar2 = (uint *)(param_1 + DAT_c05653bc * -0x28 + -8);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((puVar2 < puVar1) || ((uint *)*puVar1 <= puVar2)) {
    CTEFreeMem(puVar2);
    puVar1[5] = puVar1[5] - 1;
  }
  else {
    *puVar2 = puVar1[0xc];
    puVar1[0xc] = (uint)puVar2;
    puVar1[3] = puVar1[3] - 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c0547c60 NdisPacketPoolUsage */

undefined4 NdisPacketPoolUsage(int param_1)

{
                    /* 0x7c60  173  NdisPacketPoolUsage */
  return *(undefined4 *)(param_1 + 0xc);
}



/* c0547c68 NdisSetPacketPoolProtocolId */

void NdisSetPacketPoolProtocolId(int param_1,undefined4 param_2)

{
                    /* 0x7c68  204  NdisSetPacketPoolProtocolId */
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}



/* c0547c70 NdisAllocateBufferPool */

void NdisAllocateBufferPool(undefined4 *param_1,undefined4 *param_2)

{
                    /* 0x7c70  25  NdisAllocateBufferPool */
  *param_2 = 0;
  *param_1 = 0;
  return;
}



/* c0547c7c NdisAllocateBuffer */

/* Boundary evidence: original MIPS .pdata c0547c7c..c0547ccf. Semantic name remains unreviewed. */

void NdisAllocateBuffer(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,
                       undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  
                    /* 0x7c7c  24  NdisAllocateBuffer */
  *param_1 = 0xc0000001;
  puVar1 = FUN_c055f3d4(param_4,param_5);
  *param_2 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *param_1 = 0;
  }
  return;
}



/* c0547cd0 NdisAdjustBufferLength */

void NdisAdjustBufferLength(int param_1,undefined4 param_2)

{
                    /* 0x7cd0  23  NdisAdjustBufferLength */
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}



/* c0547cd8 NdisCopyBuffer */

/* Boundary evidence: original MIPS .pdata c0547cd8..c0547d77. Semantic name remains unreviewed. */

void NdisCopyBuffer(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,int param_4,
                   int param_5,undefined4 param_6)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x7cd8  46  NdisCopyBuffer */
  iVar3 = *(int *)(param_4 + 0x14);
  iVar2 = *(int *)(param_4 + 4);
  *param_1 = 0xc0000001;
  pvVar1 = FUN_c055f3d4(iVar3 + iVar2 + param_5,param_6);
  *param_2 = pvVar1;
  if (pvVar1 != (void *)0x0) {
    NdisFreeBufferPool();
    *(undefined4 *)*param_2 = 0;
    *param_1 = 0;
  }
  return;
}



/* c0547d78 NdisUnchainBufferAtFront */

void NdisUnchainBufferAtFront(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
                    /* 0x7d78  215  NdisUnchainBufferAtFront */
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      *param_2 = 0;
    }
    else {
      puVar1 = *(undefined4 **)(param_1 + 8);
      *param_2 = (int)puVar1;
      if (puVar1 != (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 8) = *puVar1;
        *(undefined4 *)*param_2 = 0;
        *(undefined1 *)(param_1 + 0x1c) = 0;
      }
    }
  }
  return;
}



/* c0547db8 NdisUnchainBufferAtBack */

void NdisUnchainBufferAtBack(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
                    /* 0x7db8  214  NdisUnchainBufferAtBack */
  puVar3 = *(undefined4 **)(param_1 + 8);
  if (param_2 != (undefined4 *)0x0) {
    if (puVar3 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = *(undefined4 **)(param_1 + 0xc);
      if (puVar3 == puVar2) {
        *(undefined4 *)(param_1 + 8) = 0;
      }
      else {
        puVar1 = (undefined4 *)*puVar3;
        while (puVar1 != puVar2) {
          puVar3 = (undefined4 *)*puVar3;
          puVar1 = (undefined4 *)*puVar3;
        }
        *(undefined4 **)(param_1 + 0xc) = puVar3;
        *puVar3 = 0;
      }
      *puVar2 = 0;
      *(undefined1 *)(param_1 + 0x1c) = 0;
    }
    *param_2 = puVar2;
  }
  return;
}



/* c0547e1c NdisCopyFromPacketToPacket */

/* Boundary evidence: original MIPS .pdata c0547e1c..c0547fd3. Semantic name remains unreviewed. */

void NdisCopyFromPacketToPacket
               (int param_1,uint param_2,uint param_3,int param_4,uint param_5,uint *param_6)

{
  void *_Src;
  void *_Dst;
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  uint _Size;
  uint uVar5;
  void *local_30;
  void *local_2c;
  
                    /* 0x7e1c  47  NdisCopyFromPacketToPacket */
  uVar5 = 0;
  *param_6 = 0;
  if ((param_3 != 0) && (piVar3 = *(int **)(param_1 + 8), piVar3 != (int *)0x0)) {
    _Dst = (void *)piVar3[1];
    uVar2 = piVar3[2];
    piVar4 = *(int **)(param_4 + 8);
    if (piVar4 != (int *)0x0) {
      _Src = (void *)piVar4[1];
      uVar1 = piVar4[2];
      local_30 = _Dst;
      local_2c = _Src;
      if (param_3 != 0) {
        do {
          if (uVar2 == 0) {
            piVar3 = (int *)*piVar3;
            if (piVar3 == (int *)0x0) break;
            _Dst = (void *)piVar3[1];
            uVar2 = piVar3[2];
            local_30 = _Dst;
          }
          else if (uVar1 == 0) {
            piVar4 = (int *)*piVar4;
            if (piVar4 == (int *)0x0) break;
            _Src = (void *)piVar4[1];
            uVar1 = piVar4[2];
            local_2c = _Src;
          }
          else {
            if (param_2 != 0) {
              if (uVar2 < param_2) {
                param_2 = param_2 - uVar2;
                uVar2 = 0;
                goto LAB_c0547f90;
              }
              _Dst = (void *)((int)_Dst + param_2);
              uVar2 = uVar2 - param_2;
              param_2 = 0;
              local_30 = _Dst;
            }
            if (param_5 != 0) {
              if (uVar1 < param_5) {
                param_5 = param_5 - uVar1;
                uVar1 = 0;
                goto LAB_c0547f90;
              }
              _Src = (void *)((int)_Src + param_5);
              uVar1 = uVar1 - param_5;
              param_5 = 0;
              local_2c = _Src;
            }
            _Size = uVar1;
            if (uVar2 < uVar1) {
              _Size = uVar2;
            }
            if (param_3 - uVar5 < _Size) {
              _Size = param_3 - uVar5;
            }
            memcpy(_Dst,_Src,_Size);
            uVar5 = _Size + uVar5;
            uVar1 = uVar1 - _Size;
            _Src = (void *)(_Size + (int)local_2c);
            _Dst = (void *)(_Size + (int)local_30);
            uVar2 = uVar2 - _Size;
            local_30 = _Dst;
            local_2c = _Src;
          }
LAB_c0547f90:
        } while (uVar5 < param_3);
      }
      *param_6 = uVar5;
    }
  }
  return;
}



/* c0547fd4 NdisUpdateSharedMemory */

/* Boundary evidence: original MIPS .pdata c0547fd4..c0547ff3. Semantic name remains unreviewed. */

void NdisUpdateSharedMemory(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x7fd4  219  NdisUpdateSharedMemory */
  CacheRangeFlush(param_3,param_2,4);
  return;
}



/* c0547ff4 NdisOpenFile */

/* Boundary evidence: original MIPS .pdata c0547ff4..c054822b. Semantic name remains unreviewed. */

void NdisOpenFile(undefined4 *param_1,undefined4 *param_2,DWORD *param_3,ushort *param_4)

{
  HANDLE hFile;
  DWORD nNumberOfBytesToRead;
  void *lpBuffer;
  BOOL BVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  DWORD local_38 [2];
  ushort local_30;
  ushort local_2e;
  LPCWSTR local_2c;
  
                    /* 0x7ff4  170  NdisOpenFile */
  local_2e = param_4[1] + 0x14;
  local_2c = FUN_c05427a0((uint)local_2e);
  if (local_2c == (LPCWSTR)0x0) {
    *param_1 = 0xc000009a;
    return;
  }
  local_30 = 0x12;
  memcpy(local_2c,L"\\windows\\",0x14);
  FUN_c055fac4(&local_30,param_4);
  hFile = CreateFileW(local_2c,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    iVar4 = -0x3fffffff;
  }
  else {
    iVar4 = 0;
  }
  CTEFreeMem(local_2c);
  if (iVar4 < 0) {
    uVar3 = 0xc001001b;
  }
  else {
    nNumberOfBytesToRead = GetFileSize(hFile,(LPDWORD)0x0);
    if (nNumberOfBytesToRead == 0) {
      *param_1 = 0xc001001c;
      goto LAB_c05481e8;
    }
    lpBuffer = FUN_c05427a0(nNumberOfBytesToRead);
    if (lpBuffer != (void *)0x0) {
      BVar1 = ReadFile(hFile,lpBuffer,nNumberOfBytesToRead,local_38,(LPOVERLAPPED)0x0);
      if ((BVar1 == 0) || (local_38[0] != nNumberOfBytesToRead)) {
        uVar3 = 0xc001001c;
      }
      else {
        puVar2 = FUN_c05427a0(0x1c);
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = lpBuffer;
          InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 1));
          *(undefined1 *)(puVar2 + 6) = 0;
          *param_2 = puVar2;
          *param_3 = nNumberOfBytesToRead;
          *param_1 = 0;
          goto LAB_c05481e8;
        }
        uVar3 = 0xc000009a;
      }
      *param_1 = uVar3;
      CTEFreeMem(lpBuffer);
      goto LAB_c05481e8;
    }
    uVar3 = 0xc001001c;
  }
  *param_1 = uVar3;
LAB_c05481e8:
  if (hFile != (HANDLE)0xffffffff) {
    CloseHandle(hFile);
  }
  return;
}



/* c054822c NdisCloseFile */

/* Boundary evidence: original MIPS .pdata c054822c..c0548263. Semantic name remains unreviewed. */

void NdisCloseFile(undefined4 *param_1)

{
                    /* 0x822c  41  NdisCloseFile */
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  CTEFreeMem(*param_1);
  CTEFreeMem(param_1);
  return;
}



/* c0548264 NdisMapFile */

void NdisMapFile(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
                    /* 0x8264  164  NdisMapFile */
  if (*(char *)(param_3 + 6) == '\x01') {
    *param_1 = 0xc001001d;
  }
  else {
    *(undefined1 *)(param_3 + 6) = 1;
    *param_2 = *param_3;
    *param_1 = 0;
  }
  return;
}



/* c054829c NdisUnmapFile */

void NdisUnmapFile(int param_1)

{
                    /* 0x829c  217  NdisUnmapFile */
  *(undefined1 *)(param_1 + 0x18) = 0;
  return;
}



/* c05482a4 NdisSystemProcessorCount */

undefined4 NdisSystemProcessorCount(void)

{
                    /* 0x82a4  210  NdisSystemProcessorCount */
  return 1;
}



/* c05482ac NdisGetSystemUpTime */

/* Boundary evidence: original MIPS .pdata c05482ac..c05482db. Semantic name remains unreviewed. */

void NdisGetSystemUpTime(DWORD *param_1)

{
  DWORD DVar1;
  
                    /* 0x82ac  83  NdisGetSystemUpTime */
  DVar1 = GetTickCount();
  *param_1 = DVar1;
  return;
}



/* c05482dc NdisGetCurrentProcessorCpuUsage */

void NdisGetCurrentProcessorCpuUsage(undefined4 *param_1)

{
                    /* 0x82dc  73  NdisGetCurrentProcessorCpuUsage */
  *param_1 = 0x32;
  return;
}



/* c05482e8 NdisGetCurrentProcessorCounts */

void NdisGetCurrentProcessorCounts(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
                    /* 0x82e8  72  NdisGetCurrentProcessorCounts */
  *param_1 = 0;
  *param_2 = 0;
  *param_3 = 0;
  return;
}



/* c05482f8 NdisGetCurrentSystemTime */

/* Boundary evidence: original MIPS .pdata c05482f8..c0548313. Semantic name remains unreviewed. */

void NdisGetCurrentSystemTime(DWORD *param_1)

{
                    /* 0x82f8  74  NdisGetCurrentSystemTime */
  FUN_c055f458(param_1);
  return;
}



/* c0548314 NdisQueryMapRegisterCount */

undefined4 NdisQueryMapRegisterCount(undefined4 param_1,undefined4 *param_2)

{
                    /* 0x8314  180  NdisQueryMapRegisterCount */
  *param_2 = 0;
  return 0xc00000bb;
}



/* c0548324 NdisInitializeEvent */

/* Boundary evidence: original MIPS .pdata c0548324..c0548363. Semantic name remains unreviewed. */

void NdisInitializeEvent(undefined4 *param_1)

{
  HANDLE pvVar1;
  
                    /* 0x8324  103  NdisInitializeEvent */
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return;
}



/* c0548364 NdisFreeEvent */

/* Boundary evidence: original MIPS .pdata c0548364..c0548387. Semantic name remains unreviewed. */

void NdisFreeEvent(undefined4 *param_1)

{
                    /* 0x8364  61  NdisFreeEvent */
  CloseHandle((HANDLE)*param_1);
  return;
}



/* c0548388 NdisSetEvent */

/* Boundary evidence: original MIPS .pdata c0548388..c05483a7. Semantic name remains unreviewed. */

void NdisSetEvent(undefined4 *param_1)

{
                    /* 0x8388  201  NdisSetEvent */
  EventModify(*param_1,3);
  return;
}



/* c05483a8 NdisResetEvent */

/* Boundary evidence: original MIPS .pdata c05483a8..c05483c7. Semantic name remains unreviewed. */

void NdisResetEvent(undefined4 *param_1)

{
                    /* 0x83a8  196  NdisResetEvent */
  EventModify(*param_1,2);
  return;
}



/* c05483c8 NdisWaitEvent */

/* Boundary evidence: original MIPS .pdata c05483c8..c054840b. Semantic name remains unreviewed. */

bool NdisWaitEvent(undefined4 *param_1,DWORD param_2)

{
  DWORD DVar1;
  
                    /* 0x83c8  220  NdisWaitEvent */
  if (param_2 == 0) {
    param_2 = 0xffffffff;
  }
  DVar1 = WaitForSingleObject((HANDLE)*param_1,param_2);
  return DVar1 == 0;
}



/* c054840c FUN_c054840c */

/* Boundary evidence: original MIPS .pdata c054840c..c0548437. Semantic name remains unreviewed. */

void FUN_c054840c(undefined4 *param_1)

{
  (*(code *)param_1[1])(param_1,*param_1);
  return;
}



/* c0548438 NdisInitializeString */

/* Boundary evidence: original MIPS .pdata c0548438..c05484c7. Semantic name remains unreviewed. */

void NdisInitializeString(undefined2 *param_1,byte *param_2)

{
  size_t sVar1;
  ushort *puVar2;
  uint uVar3;
  
                    /* 0x8438  107  NdisInitializeString */
  sVar1 = strlen((char *)param_2);
  *param_1 = (short)(sVar1 * 2);
  uVar3 = sVar1 * 2 + 2;
  param_1[1] = (short)uVar3;
  puVar2 = FUN_c05427a0(uVar3 & 0xffff);
  *(ushort **)(param_1 + 2) = puVar2;
  if (puVar2 != (ushort *)0x0) {
    for (; sVar1 != 0; sVar1 = sVar1 - 1) {
      *puVar2 = (ushort)*param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
    *puVar2 = 0;
  }
  return;
}



/* c05484c8 NdisSetPacketStatus */

void NdisSetPacketStatus(int param_1,undefined4 param_2)

{
                    /* 0x84c8  205  NdisSetPacketStatus */
  *(undefined4 *)((uint)*(ushort *)(param_1 + 0x1e) + param_1 + 0x1c) = param_2;
  return;
}



/* c05484d8 NdisAllocatePacketPool */

/* Boundary evidence: original MIPS .pdata c05484d8..c05484f7. Semantic name remains unreviewed. */

void NdisAllocatePacketPool(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4)

{
                    /* 0x84d8  30  NdisAllocatePacketPool */
  NdisAllocatePacketPoolEx(param_1,param_2,param_3,0,param_4);
  return;
}



/* c05484f8 NdisFreePacketPool */

/* Boundary evidence: original MIPS .pdata c05484f8..c0548527. Semantic name remains unreviewed. */

void NdisFreePacketPool(int param_1)

{
                    /* 0x84f8  64  NdisFreePacketPool */
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  CTEFreeMem(param_1);
  return;
}



/* c0548528 NdisScheduleWorkItem */

/* Boundary evidence: original MIPS .pdata c0548528..c054855f. Semantic name remains unreviewed. */

undefined4 NdisScheduleWorkItem(int param_1)

{
                    /* 0x8528  198  NdisScheduleWorkItem */
  *(code **)(param_1 + 0x10) = FUN_c054840c;
  *(int *)(param_1 + 0x14) = param_1;
  FUN_c055f0e8((LPCRITICAL_SECTION)&DAT_c0565454,(LPCRITICAL_SECTION)(param_1 + 8));
  return 0;
}



/* c0548560 FUN_c0548560 */

/* Boundary evidence: original MIPS .pdata c0548560..c05485bf. Semantic name remains unreviewed. */

void FUN_c0548560(undefined4 *param_1,undefined4 *param_2,LPCRITICAL_SECTION param_3)

{
  EnterCriticalSection(param_3);
  *param_2 = *param_1;
  *param_1 = param_2;
  *(short *)(param_1 + 1) = *(short *)(param_1 + 1) + 1;
  LeaveCriticalSection(param_3);
  return;
}



/* c05485c0 FUN_c05485c0 */

/* Boundary evidence: original MIPS .pdata c05485c0..c054862b. Semantic name remains unreviewed. */

undefined4 * FUN_c05485c0(undefined4 *param_1,LPCRITICAL_SECTION param_2)

{
  undefined4 *puVar1;
  
  EnterCriticalSection(param_2);
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    *param_1 = *puVar1;
    *(short *)(param_1 + 1) = *(short *)(param_1 + 1) + -1;
  }
  LeaveCriticalSection(param_2);
  return puVar1;
}



/* c054862c NDS_Close */

undefined4 NDS_Close(void)

{
                    /* 0x862c  13  NDS_Close
                       0x862c  18  NDS_Read
                       0x862c  19  NDS_Seek
                       0x862c  20  NDS_Write
                       0x862c  116  NdisMAllocateMapRegisters */
  return 0;
}



/* c0548634 NdisAllocateFromNPagedLookasideList */

/* Boundary evidence: original MIPS .pdata c0548634..c05486e7. Semantic name remains unreviewed. */

undefined4 * NdisAllocateFromNPagedLookasideList(undefined4 *param_1)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
                    /* 0x8634  26  NdisAllocateFromNPagedLookasideList */
  if ((code *)param_1[10] == CTEAllocMem) {
    puVar1 = (undefined4 *)CTEAllocMem(param_1[9]);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x12);
    EnterCriticalSection(lpCriticalSection);
    param_1[3] = param_1[3] + 1;
    puVar1 = FUN_c05485c0(param_1,lpCriticalSection);
    if (puVar1 == (undefined4 *)0x0) {
      param_1[4] = param_1[4] + 1;
      puVar1 = (undefined4 *)(*(code *)param_1[10])(param_1[7],param_1[9],param_1[8]);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return puVar1;
}



/* c05486e8 NdisFreeToNPagedLookasideList */

/* Boundary evidence: original MIPS .pdata c05486e8..c054879b. Semantic name remains unreviewed. */

void NdisFreeToNPagedLookasideList(undefined4 *param_1,undefined4 *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
                    /* 0x86e8  67  NdisFreeToNPagedLookasideList */
  if ((code *)param_1[0xb] == CTEFreeMem) {
    CTEFreeMem(param_2);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x12);
    EnterCriticalSection(lpCriticalSection);
    param_1[5] = param_1[5] + 1;
    if (*(ushort *)(param_1 + 1) < *(ushort *)(param_1 + 2)) {
      FUN_c0548560(param_1,param_2,lpCriticalSection);
    }
    else {
      param_1[6] = param_1[6] + 1;
      (*(code *)param_1[0xb])(param_2);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return;
}



/* c054879c NdisInitializeNPagedLookasideList */

/* Boundary evidence: original MIPS .pdata c054879c..c054882b. Semantic name remains unreviewed. */

void NdisInitializeNPagedLookasideList
               (undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined2 param_7)

{
                    /* 0x879c  105  NdisInitializeNPagedLookasideList */
  *(undefined2 *)(param_1 + 2) = param_7;
  *(undefined2 *)((int)param_1 + 10) = param_7;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = param_4;
  param_1[8] = param_6;
  param_1[9] = param_5;
  if (param_2 == 0) {
    param_1[10] = CTEAllocMem;
  }
  else {
    param_1[10] = param_2;
  }
  if (param_3 == 0) {
    param_1[0xb] = CTEFreeMem;
  }
  else {
    param_1[0xb] = param_3;
  }
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x12));
  return;
}



/* c054882c NdisDeleteNPagedLookasideList */

/* Boundary evidence: original MIPS .pdata c054882c..c054887f. Semantic name remains unreviewed. */

void NdisDeleteNPagedLookasideList(undefined4 *param_1)

{
  undefined4 *puVar1;
  
                    /* 0x882c  48  NdisDeleteNPagedLookasideList */
  param_1[10] = NDS_Close;
  while (puVar1 = NdisAllocateFromNPagedLookasideList(param_1), puVar1 != (undefined4 *)0x0) {
    (*(code *)param_1[0xb])(puVar1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x12));
  return;
}



/* c0548880 NdisCloseAdapter */

/* Boundary evidence: original MIPS .pdata c0548880..c054891f. Semantic name remains unreviewed. */

void NdisCloseAdapter(undefined4 *param_1,int param_2)

{
  int iVar1;
  
                    /* 0x8880  39  NdisCloseAdapter */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  for (iVar1 = DAT_c056540c; (iVar1 != 0 && (iVar1 != param_2)); iVar1 = *(int *)(iVar1 + 0xd8)) {
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((iVar1 == 0) || (iVar1 = FUN_c0559fac(param_2), iVar1 != 0)) {
    *param_1 = 0;
  }
  else {
    *param_1 = 0x103;
  }
  return;
}



/* c0548920 NdisSetProtocolFilter */

void NdisSetProtocolFilter(undefined4 *param_1)

{
                    /* 0x8920  206  NdisSetProtocolFilter */
  *param_1 = 0xc00000bb;
  return;
}



/* c0548930 NdisGetDriverHandle */

void NdisGetDriverHandle(int param_1,undefined4 *param_2)

{
                    /* 0x8930  75  NdisGetDriverHandle */
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 8) + 8);
  return;
}



/* c0548940 FUN_c0548940 */

/* Boundary evidence: original MIPS .pdata c0548940..c0548ad7. Semantic name remains unreviewed. */

undefined4 FUN_c0548940(ushort *param_1,int *param_2,int param_3)

{
  void *_Buf1;
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  ushort local_30;
  ushort local_2e;
  void *local_2c;
  
  local_30 = *param_1;
  local_2e = local_30 + 2;
  uVar7 = 0xc0000034;
  local_2c = FUN_c05427a0((uint)local_2e);
  if (local_2c == (void *)0x0) {
    uVar7 = 0xc000009a;
    *param_2 = 0;
  }
  else {
    FUN_c055f8ec(&local_30,param_1,0);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    _Buf1 = local_2c;
    iVar8 = *param_2;
    iVar5 = DAT_c0565404;
    if (iVar8 != 0) {
      iVar5 = *(int *)(iVar8 + 0x20);
    }
    if (iVar5 != 0) {
      uVar6 = (uint)local_30;
      do {
        uVar3 = uVar6;
        if (param_3 == 0) {
          if (uVar6 == *(ushort *)(iVar5 + 0x54)) goto LAB_c0548a50;
        }
        else if ((iVar5 != iVar8) && (uVar4 = (uint)*(ushort *)(iVar5 + 0x54), uVar6 != uVar4)) {
          if (uVar4 <= uVar6) {
            uVar3 = uVar4;
          }
LAB_c0548a50:
          iVar2 = memcmp(_Buf1,*(void **)(iVar5 + 0x58),uVar3);
          if (iVar2 == 0) {
            bVar1 = FUN_c055a404(iVar5 + 4);
            if (CONCAT31(extraout_var,bVar1) == 0) {
              iVar5 = 0;
            }
            else {
              uVar7 = 0;
            }
            break;
          }
        }
        iVar5 = *(int *)(iVar5 + 0x20);
      } while (iVar5 != 0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    *param_2 = iVar5;
    CTEFreeMem(local_2c);
  }
  return uVar7;
}



/* c0548ad8 FUN_c0548ad8 */

/* Boundary evidence: original MIPS .pdata c0548ad8..c0548b9b. Semantic name remains unreviewed. */

void FUN_c0548ad8(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  
  bVar1 = FUN_c055a474(param_1 + 4);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    for (piVar2 = &DAT_c0565404; *piVar2 != 0; piVar2 = (int *)(*piVar2 + 0x20)) {
      if (*piVar2 == param_1) {
        *piVar2 = *(int *)(param_1 + 0x20);
        break;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if (*(undefined4 **)(param_1 + 0x1c) != (undefined4 *)0x0) {
      EventModify(**(undefined4 **)(param_1 + 0x1c),3);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
    FUN_c055a518((LPCRITICAL_SECTION)(param_1 + 4));
    CTEFreeMem(param_1);
  }
  return;
}



/* c0548b9c FUN_c0548b9c */

/* Boundary evidence: original MIPS .pdata c0548b9c..c0548d83. Semantic name remains unreviewed. */

void FUN_c0548b9c(int *param_1)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int *piVar4;
  int iVar5;
  HANDLE local_70 [2];
  undefined4 local_68 [3];
  HANDLE *local_5c;
  
  bVar3 = FUN_c055a404((int)(param_1 + 1));
  if (CONCAT31(extraout_var,bVar3) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    piVar4 = DAT_c0565400;
    while (piVar1 = piVar4, piVar1 != (int *)0x0) {
      piVar4 = (int *)*piVar1;
      bVar3 = FUN_c055a404((int)(piVar1 + 0x28));
      if (CONCAT31(extraout_var_00,bVar3) != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        iVar5 = piVar1[1];
        while (iVar2 = iVar5, iVar2 != 0) {
          iVar5 = *(int *)(iVar2 + 0x1c);
          if (((*(uint *)(iVar2 + 0x248) & 0x2000000) == 0) &&
             (bVar3 = FUN_c055a404(iVar2 + 0x20), CONCAT31(extraout_var_01,bVar3) != 0)) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
            FUN_c0551fd4(iVar2,param_1,0);
            iVar5 = *(int *)(iVar2 + 0x1c);
            FUN_c0559738(iVar2);
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        piVar4 = (int *)*piVar1;
        FUN_c055915c(piVar1,1);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if (param_1[0x1a] != 0) {
      local_70[0] = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
      memset(local_68,0,0x4c);
      local_68[0] = 6;
      local_5c = local_70;
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
      param_1[0x2d] = 0xf053a;
      iVar5 = (*(code *)param_1[0x1a])(0,local_68);
      if (iVar5 == 0x103) {
        WaitForSingleObject(local_70[0],0xffffffff);
      }
      CloseHandle(local_70[0]);
      param_1[0x2d] = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
    }
    FUN_c0548ad8((int)param_1);
  }
  FUN_c0548ad8((int)param_1);
  return;
}



/* c0548d84 NdisOpenProtocolConfiguration */

/* Boundary evidence: original MIPS .pdata c0548d84..c0548e33. Semantic name remains unreviewed. */

void NdisOpenProtocolConfiguration(int *param_1,undefined4 *param_2,ushort *param_3)

{
  ushort uVar1;
  WCHAR aWStack_220 [260];
  uint local_18;
  
                    /* 0x8d84  171  NdisOpenProtocolConfiguration */
  local_18 = DAT_c05653c8;
  uVar1 = *param_3;
  if (uVar1 < 0x208) {
    memcpy(aWStack_220,*(void **)(param_3 + 2),(uint)uVar1);
    aWStack_220[uVar1 >> 1] = L'\0';
    FUN_c0549b10(param_1,(HKEY)0x80000002,aWStack_220,(HKEY)0x0,param_2);
  }
  else {
    *param_1 = -0x3ffeffec;
  }
  FUN_c05625b0(local_18);
  return;
}



/* c0548e34 FUN_c0548e34 */

/* Boundary evidence: original MIPS .pdata c0548e34..c0548eb3. Semantic name remains unreviewed. */

bool FUN_c0548e34(int param_1,int *param_2)

{
  bool bVar1;
  
  if (param_2 == (int *)0x0) {
    bVar1 = false;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    bVar1 = *(char *)((int)param_2 + 0x1a) == '\0';
    if (bVar1) {
      *(int *)(param_1 + 0x18) = *param_2;
      *param_2 = param_1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return bVar1;
}



/* c0548eb4 FUN_c0548eb4 */

/* Boundary evidence: original MIPS .pdata c0548eb4..c0548f4f. Semantic name remains unreviewed. */

void FUN_c0548eb4(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = *param_2;
    if (param_1 == iVar1) {
      *param_2 = *(int *)(param_1 + 0x18);
    }
    else if (iVar1 != 0) {
      do {
        iVar2 = *(int *)(iVar1 + 0x18);
        if (param_1 == iVar2) break;
        iVar1 = iVar2;
      } while (iVar2 != 0);
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(*(int *)(iVar1 + 0x18) + 0x18);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c0548f50 NdisQueryBindInstanceName */

/* Boundary evidence: original MIPS .pdata c0548f50..c0549023. Semantic name remains unreviewed. */

undefined4 NdisQueryBindInstanceName(ushort *param_1,int param_2)

{
  ushort uVar1;
  void *_Dst;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  
                    /* 0x8f50  176  NdisQueryBindInstanceName */
  puVar4 = *(ushort **)(*(int *)(param_2 + 8) + 0x1e8);
  uVar3 = 0xc0000001;
  if (puVar4 != (ushort *)0x0) {
    uVar1 = puVar4[1];
    _Dst = FUN_c05427a0((uint)uVar1);
    if (_Dst == (void *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(uint)uVar1);
      *(void **)(param_1 + 2) = _Dst;
      *param_1 = 0;
      param_1[1] = uVar1;
      iVar2 = FUN_c055fac4(param_1,puVar4);
      if (-1 < iVar2) {
        return 0;
      }
    }
    if (_Dst != (void *)0x0) {
      CTEFreeMem(_Dst);
    }
  }
  return uVar3;
}



/* c0549024 NdisQueryAdapterInstanceName */

/* Boundary evidence: original MIPS .pdata c0549024..c05490f7. Semantic name remains unreviewed. */

undefined4 NdisQueryAdapterInstanceName(ushort *param_1,int param_2)

{
  ushort uVar1;
  void *_Dst;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  
                    /* 0x9024  175  NdisQueryAdapterInstanceName */
  puVar4 = *(ushort **)(*(int *)(param_2 + 8) + 0x1e8);
  uVar3 = 0xc0000001;
  if (puVar4 != (ushort *)0x0) {
    uVar1 = puVar4[1];
    _Dst = FUN_c05427a0((uint)uVar1);
    if (_Dst == (void *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(uint)uVar1);
      *(void **)(param_1 + 2) = _Dst;
      *param_1 = 0;
      param_1[1] = uVar1;
      iVar2 = FUN_c055fac4(param_1,puVar4);
      if (-1 < iVar2) {
        return 0;
      }
    }
    if (_Dst != (void *)0x0) {
      CTEFreeMem(_Dst);
    }
  }
  return uVar3;
}



/* c05490f8 FUN_c05490f8 */

/* Boundary evidence: original MIPS .pdata c05490f8..c0549237. Semantic name remains unreviewed. */

int FUN_c05490f8(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  while( true ) {
    for (iVar2 = *param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      uVar1 = *(uint *)(iVar2 + 0x7c);
      if (((uVar1 & 0x8010) == 0) &&
         (*(uint *)(iVar2 + 0x7c) = uVar1 | 0x10, (uVar1 & 0x10000) == 0)) {
        *(uint *)(iVar2 + 0x7c) = uVar1 | 0x210010;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        iVar3 = FUN_c054acf4(iVar2,0);
        goto LAB_c05491f8;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    iVar2 = *param_1;
    if (iVar2 == 0) break;
    do {
      if ((*(uint *)(iVar2 + 0x7c) & 0x10000) == 0) break;
      iVar2 = *(int *)(iVar2 + 0x18);
    } while (iVar2 != 0);
    if (iVar2 == 0) break;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    Sleep(1);
LAB_c05491f8:
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return iVar3;
}



/* c0549238 NdisSetPacketCancelId */

void NdisSetPacketCancelId(int param_1,undefined4 param_2)

{
                    /* 0x9238  203  NdisSetPacketCancelId */
  *(undefined4 *)((uint)*(ushort *)(param_1 + 0x1e) + param_1 + 0x40) = param_2;
  return;
}



/* c0549248 NdisGetPacketCancelId */

undefined4 NdisGetPacketCancelId(int param_1)

{
                    /* 0x9248  79  NdisGetPacketCancelId */
  return *(undefined4 *)((uint)*(ushort *)(param_1 + 0x1e) + param_1 + 0x40);
}



/* c0549258 NdisCancelSendPackets */

/* Boundary evidence: original MIPS .pdata c0549258..c05492e7. Semantic name remains unreviewed. */

void NdisCancelSendPackets(int ****param_1,int param_2)

{
                    /* 0x9258  37  NdisCancelSendPackets */
  if (((uint)param_1[2][0x15] & 0x40000) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c054d51c((int)param_1[2],param_1,param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  else if (param_1[0x2d] != (int ***)0x0) {
    (*(code *)param_1[0x2d])(param_1[7],param_2);
  }
  return;
}



/* c05492e8 NdisQueryPendingIOCount */

/* Boundary evidence: original MIPS .pdata c05492e8..c054936f. Semantic name remains unreviewed. */

undefined4 NdisQueryPendingIOCount(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x92e8  182  NdisQueryPendingIOCount */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((*(uint *)(param_1 + 0x7c) & 0x8000) == 0) {
    iVar1 = (*(int *)(param_1 + 0x80) - *(int *)(param_1 + 0xd4)) + -1;
    uVar2 = 0;
  }
  else {
    iVar1 = 0;
    uVar2 = 0xc0010002;
  }
  *param_2 = iVar1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return uVar2;
}



/* c0549370 NdisGeneratePartialCancelId */

/* Boundary evidence: original MIPS .pdata c0549370..c0549393. Semantic name remains unreviewed. */

uint NdisGeneratePartialCancelId(void)

{
  uint uVar1;
  
                    /* 0x9370  68  NdisGeneratePartialCancelId */
  uVar1 = InterlockedIncrement((LONG *)&DAT_c0565450);
  return uVar1 & 0xff;
}



/* c0549394 NdisRegisterProtocol */

/* Boundary evidence: original MIPS .pdata c0549394..c054959b. Semantic name remains unreviewed. */

void NdisRegisterProtocol(undefined4 *param_1,undefined4 *param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined3 extraout_var;
  byte *pbVar4;
  uint uVar5;
  uint _Size;
  undefined4 uVar6;
  ushort *puVar7;
  
                    /* 0x9394  190  NdisRegisterProtocol */
  bVar1 = *param_3;
  _Size = 0;
  puVar3 = param_2;
  pbVar4 = param_3;
  uVar5 = param_4;
  if (bVar1 < 4) {
    DbgPrint("Ndis: NdisRegisterProtocol Ndis 3.0 protocols are not supported.\n",param_2,param_3,
             param_4);
  }
  else if ((bVar1 == 4) && (param_3[1] == 0)) {
    _Size = 0x4c;
  }
  else if ((bVar1 == 5) && (param_3[1] < 2)) {
    _Size = 0x6c;
  }
  if (_Size != 0) {
    if ((*(int *)(param_3 + 0x3c) != 0) && (*(int *)(param_3 + 0x40) != 0)) {
      if (param_4 < _Size) {
        uVar6 = 0xc0010005;
      }
      else {
        puVar7 = (ushort *)(param_3 + 0x30);
        puVar3 = FUN_c05427a0(*puVar7 + 0xca);
        if (puVar3 == (undefined4 *)0x0) {
          uVar6 = 0xc000009a;
        }
        else {
          memset(puVar3,0,*puVar7 + 0xca);
          InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 0x28));
          memcpy(puVar3 + 9,param_3,_Size);
          puVar3[0x16] = puVar3 + 0x32;
          *(ushort *)(puVar3 + 0x15) = *puVar7;
          *(ushort *)((int)puVar3 + 0x56) = *puVar7;
          FUN_c055f8ec((ushort *)(puVar3 + 0x15),puVar7,0);
          *puVar3 = 0;
          FUN_c055a4ec((LPCRITICAL_SECTION)(puVar3 + 1));
          *param_2 = puVar3;
          uVar6 = 0;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          puVar3[8] = DAT_c0565404;
          DAT_c0565404 = puVar3;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          bVar2 = FUN_c055a404((int)(puVar3 + 1));
          if (CONCAT31(extraout_var,bVar2) != 0) {
            puVar3[0x26] = FUN_c0548b9c;
            puVar3[0x27] = puVar3;
            FUN_c055f0e8((LPCRITICAL_SECTION)&DAT_c0565454,(LPCRITICAL_SECTION)(puVar3 + 0x24));
          }
        }
      }
      goto LAB_c0549574;
    }
    DbgPrint("Ndis: NdisRegisterProtocol protocol does not have Bind/UnbindAdapterHandler and it is not supported.\n"
             ,puVar3,pbVar4,uVar5);
  }
  uVar6 = 0xc0010004;
LAB_c0549574:
  *param_1 = uVar6;
  return;
}



/* c054959c NdisDeregisterProtocol */

/* Boundary evidence: original MIPS .pdata c054959c..c05496af. Semantic name remains unreviewed. */

void NdisDeregisterProtocol(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  HANDLE local_20 [2];
  
                    /* 0x959c  50  NdisDeregisterProtocol */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  for (piVar2 = DAT_c0565404; (piVar2 != (int *)0x0 && (piVar2 != param_2));
      piVar2 = (int *)piVar2[8]) {
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (piVar2 != (int *)0x0) {
    bVar1 = FUN_c055a534((int)(param_2 + 1));
    if (CONCAT31(extraout_var,bVar1) == 0) {
      *param_1 = 0xc0000001;
      return;
    }
    if (param_2[0x30] != 0) {
      *(undefined4 *)(param_2[0x30] + 0xc) = 0;
      param_2[0x30] = 0;
    }
    local_20[0] = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    param_2[7] = (int)local_20;
    FUN_c05490f8(param_2);
    FUN_c0548ad8((int)param_2);
    WaitForSingleObject(local_20[0],0xffffffff);
    CloseHandle(local_20[0]);
  }
  *param_1 = 0;
  return;
}



/* c05496b0 NdisOpenAdapter */

/* Boundary evidence: original MIPS .pdata c05496b0..c0549983. Semantic name remains unreviewed. */

void NdisOpenAdapter(int *param_1,undefined4 *param_2,undefined4 *param_3,uint *param_4,int *param_5
                    ,uint param_6,int param_7,undefined4 param_8,ushort *param_9)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined3 extraout_var;
  int iVar4;
  uint uVar5;
  undefined4 *_Dst;
  int local_38;
  int local_34;
  undefined4 local_30 [2];
  
                    /* 0x96b0  166  NdisOpenAdapter */
  *param_2 = 0;
  *param_3 = 0;
  _Dst = (undefined4 *)0x0;
  bVar1 = false;
  bVar2 = false;
  bVar3 = FUN_c055a404(param_7 + 4);
  if (CONCAT31(extraout_var,bVar3) == 0) {
    iVar4 = -0x3ffefffe;
  }
  else {
    local_34 = *(int *)(param_7 + 0xb8);
    bVar1 = true;
    if (local_34 == 0) {
      FUN_c054b344(param_9,(uint)((*(uint *)(param_7 + 0x28) & 0x20000000) != 0),&local_34,local_30,
                   &local_38);
    }
    else {
      local_30[0] = *(undefined4 *)(param_7 + 0xbc);
      local_38 = *(int *)(param_7 + 0xc4);
    }
    if (local_38 == 0) {
      iVar4 = -0x3ffefffa;
    }
    else {
      _Dst = FUN_c05427a0(0xe0);
      if (_Dst != (undefined4 *)0x0) {
        memset(_Dst,0,0xe0);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        _Dst[0x36] = DAT_c056540c;
        bVar2 = true;
        DAT_c056540c = _Dst;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        uVar5 = 0;
        _Dst[9] = local_34;
        _Dst[0xf] = local_30[0];
        _Dst[2] = local_38;
        _Dst[3] = param_7;
        _Dst[4] = param_8;
        *param_3 = _Dst;
        if (param_6 != 0) {
          do {
            if (*param_5 == *(int *)(local_38 + 0x11c)) break;
            uVar5 = uVar5 + 1;
            param_5 = param_5 + 1;
          } while (uVar5 < param_6);
        }
        if (uVar5 == param_6) {
          *param_1 = -0x3ffeffe7;
        }
        else {
          *param_4 = uVar5;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          if ((*(uint *)(local_38 + 0x54) & 0x40000) == 0) {
            FUN_c054b758(local_38);
          }
          FUN_c05501e0(param_1,_Dst,0);
          if ((*param_1 == 0) && ((*(uint *)(local_38 + 0x54) & 0x20000000) == 0)) {
            FUN_c054e23c(local_38,0xc001001f,2);
          }
          if ((*(uint *)(local_38 + 0x54) & 0x40000) == 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)(local_38 + 0x4b0));
            *(undefined4 *)(local_38 + 0x454) = 0;
            *(undefined4 *)(local_38 + 0x458) = 0;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          if (*param_1 == 0) {
            return;
          }
          if (*param_1 == 0x103) {
            return;
          }
        }
        goto LAB_c0549920;
      }
      iVar4 = -0x3fffff66;
    }
  }
  *param_1 = iVar4;
LAB_c0549920:
  if (bVar1) {
    FUN_c0548ad8(param_7);
  }
  if (bVar2) {
    FUN_c054dfe8((int)_Dst);
  }
  if (_Dst != (undefined4 *)0x0) {
    CTEFreeMem(_Dst);
  }
  *param_3 = 0;
  return;
}



/* c0549984 NdisReEnumerateProtocolBindings */

/* Boundary evidence: original MIPS .pdata c0549984..c05499bb. Semantic name remains unreviewed. */

void NdisReEnumerateProtocolBindings(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
                    /* 0x9984  183  NdisReEnumerateProtocolBindings */
  bVar1 = FUN_c055a404((int)(param_1 + 1));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_c0548b9c(param_1);
  }
  return;
}



/* c05499bc NdisInitializeTimer */

/* Boundary evidence: original MIPS .pdata c05499bc..c0549a0b. Semantic name remains unreviewed. */

void NdisInitializeTimer(int *param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x99bc  108  NdisInitializeTimer */
  FUN_c0560c90(param_1);
  FUN_c0561494((int)(param_1 + 8),param_2,param_3);
  return;
}



/* c0549a0c NdisSetTimer */

/* Boundary evidence: original MIPS .pdata c0549a0c..c0549a5b. Semantic name remains unreviewed. */

void NdisSetTimer(int *param_1,int param_2)

{
                    /* 0x9a0c  207  NdisSetTimer */
  if (((code *)param_1[0xb] == FUN_c0554b0c) || ((code *)param_1[0xb] == FUN_c0554c04)) {
    NdisMSetTimer(param_1,param_2);
  }
  else {
    FUN_c0560db4(param_1,param_2,(int)(param_1 + 8));
  }
  return;
}



/* c0549a5c NdisSetTimerEx */

/* Boundary evidence: original MIPS .pdata c0549a5c..c0549a77. Semantic name remains unreviewed. */

void NdisSetTimerEx(int *param_1,int param_2,int param_3)

{
                    /* 0x9a5c  208  NdisSetTimerEx */
  param_1[0xc] = param_3;
  NdisSetTimer(param_1,param_2);
  return;
}



/* c0549a78 NdisCancelTimer */

/* Boundary evidence: original MIPS .pdata c0549a78..c0549a9f. Semantic name remains unreviewed. */

void NdisCancelTimer(int *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
                    /* 0x9a78  38  NdisCancelTimer */
  uVar1 = FUN_c0560bd8(param_1);
  *param_2 = (char)uVar1;
  return;
}



/* c0549aa0 FUN_c0549aa0 */

/* Boundary evidence: original MIPS .pdata c0549aa0..c0549b0f. Semantic name remains unreviewed. */

void FUN_c0549aa0(undefined4 *param_1,HKEY param_2,LPCWSTR param_3,HKEY param_4,PHKEY param_5)

{
  LSTATUS LVar1;
  
  *param_1 = 0;
  param_5[1] = param_4;
  param_5[2] = (HKEY)0x0;
  LVar1 = RegOpenKeyExW(param_2,param_3,0,0x2001f,param_5);
  if (LVar1 != 0) {
    *param_1 = 0xc000009a;
  }
  return;
}



/* c0549b10 FUN_c0549b10 */

/* Boundary evidence: original MIPS .pdata c0549b10..c0549bc7. Semantic name remains unreviewed. */

void FUN_c0549b10(int *param_1,HKEY param_2,LPCWSTR param_3,HKEY param_4,undefined4 *param_5)

{
  PHKEY ppHVar1;
  int iVar2;
  
  ppHVar1 = FUN_c05427a0(0xc);
  if (ppHVar1 == (PHKEY)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    iVar2 = 0;
  }
  *param_1 = iVar2;
  if (iVar2 == 0) {
    FUN_c0549aa0(param_1,param_2,param_3,param_4,ppHVar1);
    if (*param_1 != 0) {
      CTEFreeMem(ppHVar1);
      ppHVar1 = (PHKEY)0x0;
    }
  }
  *param_5 = ppHVar1;
  return;
}



/* c0549bc8 NdisOpenConfiguration */

/* Boundary evidence: original MIPS .pdata c0549bc8..c0549c4b. Semantic name remains unreviewed. */

void NdisOpenConfiguration(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  wchar_t awStack_218 [256];
  uint local_18;
  
                    /* 0x9bc8  167  NdisOpenConfiguration */
  local_18 = DAT_c05653c8;
  StringCchPrintfW(awStack_218,0x100,L"Comm\\%s\\Parms",*(undefined4 *)(param_3[3] + 4));
  FUN_c0549b10(param_1,(HKEY)0x80000002,awStack_218,(HKEY)*param_3,param_2);
  FUN_c05625b0(local_18);
  return;
}



/* c0549c4c NdisOpenConfigurationKeyByName */

/* Boundary evidence: original MIPS .pdata c0549c4c..c0549c73. Semantic name remains unreviewed. */

void NdisOpenConfigurationKeyByName
               (int *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
                    /* 0x9c4c  169  NdisOpenConfigurationKeyByName */
  FUN_c0549b10(param_1,(HKEY)*param_2,*(LPCWSTR *)(param_3 + 4),(HKEY)param_2[1],param_4);
  return;
}



/* c0549c74 NdisOpenConfigurationKeyByIndex */

/* Boundary evidence: original MIPS .pdata c0549c74..c0549dbf. Semantic name remains unreviewed. */

void NdisOpenConfigurationKeyByIndex
               (int *param_1,undefined4 *param_2,DWORD param_3,undefined2 *param_4,
               undefined4 *param_5)

{
  LSTATUS LVar1;
  LPCWSTR lpName;
  undefined2 uVar2;
  DWORD local_28 [2];
  
                    /* 0x9c74  168  NdisOpenConfigurationKeyByIndex */
  local_28[0] = 0;
  LVar1 = RegEnumKeyExW((HKEY)*param_2,param_3,(LPWSTR)0x0,local_28,(LPDWORD)0x0,(LPWSTR)0x0,
                        (LPDWORD)0x0,(PFILETIME)0x0);
  *param_1 = -0x3fffffff;
  if (LVar1 == 0) {
    lpName = FUN_c05427a0((local_28[0] + 1) * 2);
    if (lpName == (LPCWSTR)0x0) {
      *param_1 = -0x3fffff66;
    }
    else {
      lpName[local_28[0]] = L'\0';
      LVar1 = RegEnumKeyExW((HKEY)*param_2,param_3,lpName,local_28,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
      if (LVar1 == 0) {
        *(LPCWSTR *)(param_4 + 2) = lpName;
        uVar2 = (undefined2)(local_28[0] << 1);
        *param_4 = uVar2;
        param_4[1] = uVar2;
        FUN_c0549b10(param_1,(HKEY)*param_2,lpName,(HKEY)param_2[1],param_5);
      }
      if (*param_1 != 0) {
        CTEFreeMem(lpName);
      }
    }
  }
  return;
}



/* c0549dc0 FUN_c0549dc0 */

/* Boundary evidence: original MIPS .pdata c0549dc0..c0549e9b. Semantic name remains unreviewed. */

undefined4 FUN_c0549dc0(ushort *param_1,int *param_2,int *param_3,undefined1 *param_4)

{
  void *_Dst;
  
  if ((uint)param_1[1] < *param_1 + 2) {
    _Dst = FUN_c05427a0(*param_1 + 2);
    *param_2 = (int)_Dst;
    if (_Dst == (void *)0x0) {
      return 0;
    }
    memcpy(_Dst,*(void **)(param_1 + 2),(uint)*param_1);
    *param_4 = 1;
  }
  else {
    *param_2 = *(int *)(param_1 + 2);
    *param_4 = 0;
  }
  if (*(short *)((uint)*param_1 + *param_2) != 0) {
    *(short *)((uint)*param_1 + *param_2) = 0;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_1 + 2;
  }
  return 1;
}



/* c0549e9c NdisWriteConfiguration */

/* Boundary evidence: original MIPS .pdata c0549e9c..c054a03b. Semantic name remains unreviewed. */

void NdisWriteConfiguration(undefined4 *param_1,undefined4 *param_2,ushort *param_3,int *param_4)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  int iVar3;
  DWORD dwType;
  char local_30;
  char local_2f [3];
  int *local_2c;
  uint local_28;
  LPCWSTR local_24;
  
                    /* 0x9e9c  221  NdisWriteConfiguration */
  *param_1 = 0;
  local_24 = *(LPCWSTR *)(param_3 + 2);
  iVar3 = *param_4;
  local_30 = '\0';
  local_2f[0] = '\0';
  if (iVar3 < 0) {
LAB_c0549fe4:
    *param_1 = 0xc00000bb;
  }
  else {
    if (iVar3 < 2) {
      dwType = 4;
      local_28 = 4;
      local_2c = param_4 + 1;
    }
    else if (iVar3 == 2) {
      dwType = 1;
    }
    else if (iVar3 == 3) {
      dwType = 7;
    }
    else {
      if (iVar3 != 4) goto LAB_c0549fe4;
      local_28 = (uint)*(ushort *)(param_4 + 1);
      local_2c = (int *)param_4[2];
      dwType = 3;
    }
    iVar3 = FUN_c0549dc0(param_3,(int *)&local_24,(int *)0x0,&local_30);
    if ((iVar3 == 0) ||
       (((*param_4 == 2 || (*param_4 == 3)) &&
        (iVar3 = FUN_c0549dc0((ushort *)(param_4 + 1),(int *)&local_2c,(int *)&local_28,local_2f),
        iVar3 == 0)))) {
      uVar2 = 0xc000009a;
    }
    else {
      LVar1 = RegSetValueExW((HKEY)*param_2,local_24,0,dwType,(BYTE *)local_2c,local_28);
      if (LVar1 == 0) goto LAB_c0549ff0;
      uVar2 = 0xc0000001;
    }
    *param_1 = uVar2;
  }
LAB_c0549ff0:
  if (local_30 != '\0') {
    CTEFreeMem(local_24);
  }
  if (local_2f[0] != '\0') {
    CTEFreeMem(local_2c);
  }
  return;
}



/* c054a03c FUN_c054a03c */

/* Boundary evidence: original MIPS .pdata c054a03c..c054a08b. Semantic name remains unreviewed. */

void FUN_c054a03c(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  while (puVar1 = (undefined4 *)param_1[2], puVar1 != (undefined4 *)0x0) {
    param_1[2] = *puVar1;
    CTEFreeMem(puVar1);
  }
  RegCloseKey((HKEY)*param_1);
  return;
}



/* c054a08c NdisCloseConfiguration */

/* Boundary evidence: original MIPS .pdata c054a08c..c054a0bb. Semantic name remains unreviewed. */

void NdisCloseConfiguration(undefined4 *param_1)

{
                    /* 0xa08c  40  NdisCloseConfiguration */
  FUN_c054a03c(param_1);
  CTEFreeMem(param_1);
  return;
}



/* c054a0bc NdisConvertStringToAtmAddress */

/* Boundary evidence: original MIPS .pdata c054a0bc..c054a313. Semantic name remains unreviewed. */

void NdisConvertStringToAtmAddress(int *param_1,ushort *param_2,int *param_3)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  short *psVar6;
  short *psVar7;
  ushort uVar8;
  void *pvVar9;
  char local_30;
  char local_2f;
  undefined1 local_2e;
  long local_2c;
  ushort local_28;
  undefined2 local_26;
  void *local_24;
  ushort local_20;
  ushort local_1e;
  short *local_1c;
  
                    /* 0xa0bc  45  NdisConvertStringToAtmAddress */
  uVar1 = *param_2;
  psVar6 = *(short **)(param_2 + 2);
  uVar4 = 0;
  uVar8 = 0;
  psVar7 = psVar6;
  if (uVar1 >> 1 != 0) {
    do {
      sVar2 = *psVar6;
      if (sVar2 == 0) break;
      if ((sVar2 != 0x20) && (sVar2 != 0x2e)) {
        *psVar7 = sVar2;
        psVar7 = psVar7 + 1;
        uVar4 = uVar4 + 1 & 0xffff;
      }
      uVar8 = uVar8 + 1;
      psVar6 = psVar6 + 1;
    } while (uVar8 < uVar1 >> 1);
  }
  local_1c = *(short **)(param_2 + 2);
  if (*local_1c == 0x2b) {
LAB_c054a1ac:
    local_1c = local_1c + 1;
    uVar4 = uVar4 + 0xffff & 0xffff;
LAB_c054a1bc:
    if ((uVar4 == 0) || (0x14 < uVar4)) {
      iVar3 = -0x3ffeffec;
      goto LAB_c054a2f0;
    }
    *param_3 = 1;
    param_3[1] = uVar4;
  }
  else {
    if (uVar4 < 0x10) {
      if (*local_1c == 0x2b) goto LAB_c054a1ac;
      goto LAB_c054a1bc;
    }
    if (uVar4 != 0x28) {
      *param_1 = -0x3ffeffec;
      return;
    }
    *param_3 = 0;
    param_3[1] = 0x14;
  }
  local_20 = (ushort)(uVar4 << 1);
  local_1e = local_20;
  local_24 = FUN_c05427a0(uVar4 + 1);
  local_28 = 0;
  local_26 = (undefined2)(uVar4 + 1);
  if (local_24 != (void *)0x0) {
    iVar3 = NdisUnicodeStringToAnsiString(&local_28,&local_20);
    pvVar9 = local_24;
    *param_1 = iVar3;
    if (iVar3 < 0) {
LAB_c054a234:
      CTEFreeMem(local_24);
      *param_1 = -0x3fffffff;
      return;
    }
    if (*param_3 == 1) {
      memcpy(param_3 + 2,local_24,uVar4);
    }
    else {
      local_2e = 0;
      uVar4 = 0;
      do {
        pcVar5 = (char *)(uVar4 * 2 + (int)local_24);
        local_30 = *pcVar5;
        local_2f = pcVar5[1];
        iVar3 = FUN_c055fb9c(&local_30,0x10,&local_2c);
        *param_1 = iVar3;
        if (iVar3 < 0) goto LAB_c054a234;
        *(char *)((int)param_3 + uVar4 + 8) = (char)local_2c;
        uVar4 = uVar4 + 1 & 0xffff;
        pvVar9 = local_24;
      } while (uVar4 < 0x14);
    }
    CTEFreeMem(pvVar9);
    *param_1 = 0;
    return;
  }
  iVar3 = -0x3fffff66;
LAB_c054a2f0:
  *param_1 = iVar3;
  return;
}



/* c054a314 FUN_c054a314 */

/* Boundary evidence: original MIPS .pdata c054a314..c054a4cf. Semantic name remains unreviewed. */

undefined4
FUN_c054a314(undefined4 param_1,int param_2,undefined4 *param_3,size_t param_4,int param_5,
            int *param_6)

{
  undefined4 *puVar1;
  size_t sVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  
  sVar2 = 0x10;
  uVar4 = 3;
  if (((param_2 == 1) || (param_2 == 7)) || (param_2 == 3)) {
    sVar2 = param_4 + 0x10;
  }
  puVar1 = FUN_c05427a0(sVar2);
  if (puVar1 == (undefined4 *)0x0) {
    return 0xc000009a;
  }
  puVar3 = puVar1 + 1;
  *param_6 = (int)puVar3;
  if (param_2 == 4) {
    *puVar3 = 0;
    *(undefined4 *)(*param_6 + 4) = *param_3;
  }
  else {
    uVar5 = (undefined2)param_4;
    if (param_2 == 1) {
      uVar4 = 2;
    }
    else if (param_2 != 7) {
      if (param_2 != 3) {
        CTEFreeMem(puVar1);
        return 0xc0000034;
      }
      *puVar3 = 4;
      *(undefined4 **)(*param_6 + 8) = param_3;
      *(undefined2 *)(*param_6 + 4) = uVar5;
      *(undefined4 **)(*param_6 + 8) = puVar1 + 4;
      memcpy(*(void **)(*param_6 + 8),param_3,param_4);
      goto LAB_c054a490;
    }
    *puVar3 = uVar4;
    *(undefined4 **)(*param_6 + 8) = puVar1 + 4;
    memcpy(*(void **)(*param_6 + 8),param_3,param_4);
    *(undefined2 *)(*param_6 + 4) = uVar5;
    *(undefined2 *)(*param_6 + 6) = uVar5;
    if (((param_2 == 1) && (*(char *)((int)param_3 + (param_4 - 1)) == '\0')) &&
       (*(char *)((int)param_3 + (param_4 - 2)) == '\0')) {
      *(short *)(*param_6 + 4) = *(short *)(*param_6 + 4) + -2;
    }
  }
LAB_c054a490:
  *puVar1 = *(undefined4 *)(param_5 + 8);
  *(undefined4 **)(param_5 + 8) = puVar1;
  return 0;
}



/* c054a4d0 NdisReadConfiguration */

/* Boundary evidence: original MIPS .pdata c054a4d0..c054a947. Semantic name remains unreviewed. */

void NdisReadConfiguration
               (undefined4 *param_1,int *param_2,undefined4 *param_3,ushort *param_4,int param_5)

{
  char cVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined3 extraout_var_01;
  LSTATUS LVar4;
  LPBYTE lpData;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  LPCWSTR lpValueName;
  uint uVar10;
  ushort *puVar11;
  undefined4 local_44;
  size_t local_40;
  DWORD local_3c;
  char local_38 [12];
  uint local_2c;
  
                    /* 0xa4d0  184  NdisReadConfiguration */
  local_2c = DAT_c05653c8;
  local_38[0] = '\x01';
  local_38[4] = 1;
  local_38[6] = 1;
  puVar11 = (ushort *)&DAT_c05651ec;
  lpValueName = *(LPCWSTR *)(param_4 + 2);
  iVar8 = 0;
  local_38[1] = 2;
  local_38[2] = 3;
  local_38[3] = 4;
  local_38[5] = 2;
  local_38[7] = 2;
  local_38[8] = 3;
  do {
    bVar2 = FUN_c055f908(param_4,puVar11,1);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      iVar3 = 0;
      *param_2 = (int)(&DAT_c056525c + iVar8 * 0xc);
      goto LAB_c054a8e8;
    }
    iVar8 = iVar8 + 1;
    puVar11 = puVar11 + 4;
  } while (iVar8 < 3);
  iVar8 = param_3[1];
  if (iVar8 != 0) {
    bVar2 = FUN_c055f908(param_4,(ushort *)&DAT_c0565204,1);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      iVar3 = FUN_c054a314(PTR_u_MiniportName_c0565208,1,*(undefined4 **)(iVar8 + 0x14),
                           (uint)*(ushort *)(iVar8 + 0x10),(int)param_3,param_2);
      goto LAB_c054a8e8;
    }
    uVar10 = 0;
    puVar11 = (ushort *)&DAT_c0565214;
    do {
      bVar2 = FUN_c055f908(param_4,puVar11,1);
      if (CONCAT31(extraout_var_01,bVar2) != 0) break;
      uVar10 = uVar10 + 1;
      puVar11 = puVar11 + 4;
    } while ((int)uVar10 < 9);
    if (uVar10 < 9) {
      pcVar6 = *(char **)(iVar8 + 0x264);
      iVar3 = -0x3fffffff;
      if (pcVar6 != (char *)0x0) {
        uVar9 = 0;
        iVar3 = -0x3fffffff;
        if (*(uint *)(pcVar6 + 0x14) != 0) {
          cVar1 = local_38[uVar10];
          pcVar7 = pcVar6;
          do {
            pcVar7 = pcVar7 + 0x18;
            if (*pcVar7 == cVar1) {
              if ((((cVar1 == '\x01') || (cVar1 == '\x02')) || (cVar1 == '\x03')) ||
                 (cVar1 == '\x04')) {
                local_44 = *(undefined4 *)(pcVar6 + uVar9 * 0x18 + 0x20);
              }
              iVar3 = FUN_c054a314(*(undefined4 *)(uVar10 * 8 + -0x3fa9ade8),4,&local_44,4,
                                   (int)param_3,param_2);
              break;
            }
            uVar9 = uVar9 + 1;
            iVar3 = -0x3fffffff;
          } while (uVar9 < *(uint *)(pcVar6 + 0x14));
        }
        if (*(uint *)(pcVar6 + 0x14) <= uVar9) {
          iVar3 = -0x3fffffff;
        }
      }
      goto LAB_c054a8e8;
    }
  }
  if ((uint)param_4[1] < *param_4 + 2) {
    lpValueName = FUN_c05427a0(*param_4 + 2);
    if (lpValueName != (LPCWSTR)0x0) {
      memcpy(lpValueName,*(void **)(param_4 + 2),(uint)*param_4);
      goto LAB_c054a76c;
    }
  }
  else {
LAB_c054a76c:
    if (*(short *)((uint)*param_4 + (int)lpValueName) != 0) {
      *(short *)((uint)*param_4 + (int)lpValueName) = 0;
    }
    LVar4 = RegQueryValueExW((HKEY)*param_3,lpValueName,(LPDWORD)0x0,&local_3c,(LPBYTE)0x0,&local_40
                            );
    if (LVar4 == 0) {
      lpData = FUN_c05427a0(local_40);
      if (lpData == (LPBYTE)0x0) {
        *param_1 = 0xc000009a;
        iVar3 = -0x3fffffff;
        goto LAB_c054a8e8;
      }
      LVar4 = RegQueryValueExW((HKEY)*param_3,lpValueName,(LPDWORD)0x0,&local_3c,lpData,&local_40);
      if (LVar4 == 0) {
        iVar3 = FUN_c054a314(lpValueName,local_3c,(undefined4 *)lpData,local_40,(int)param_3,param_2
                            );
        CTEFreeMem(lpData);
        if ((-1 < iVar3) && (piVar5 = (int *)*param_2, *piVar5 == 2)) {
          if (param_5 == 0) {
            FUN_c055fb64((int)(piVar5 + 1),10,piVar5 + 1);
            *(undefined4 *)*param_2 = 0;
          }
          else if (param_5 == 1) {
            FUN_c055fb64((int)(piVar5 + 1),0x10,piVar5 + 1);
            *(undefined4 *)*param_2 = 1;
          }
        }
        goto LAB_c054a8e8;
      }
      CTEFreeMem(lpData);
    }
  }
  iVar3 = -0x3fffffff;
LAB_c054a8e8:
  if (lpValueName != *(LPCWSTR *)(param_4 + 2)) {
    CTEFreeMem(lpValueName);
  }
  if (iVar3 < 0) {
    *param_1 = 0xc0000001;
  }
  else {
    *param_1 = 0;
  }
  FUN_c05625b0(local_2c);
  return;
}



/* c054a948 NdisReadNetworkAddress */

/* Boundary evidence: original MIPS .pdata c054a948..c054ab0b. Semantic name remains unreviewed. */

void NdisReadNetworkAddress(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  short *psVar9;
  char local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  int *local_3c;
  long local_38 [2];
  ushort local_30 [2];
  wchar_t *local_2c;
  
                    /* 0xa948  185  NdisReadNetworkAddress */
  local_30[0] = 0x1c;
  *param_1 = -0x3fffffff;
  piVar2 = (int *)param_4[1];
  local_30[1] = 0x1e;
  local_2c = L"NetworkAddress";
  if (*piVar2 == 0x504d444e) {
    piVar2[0x7c] = piVar2[0x7c] | 0x80;
    piVar2[0x117] = piVar2[0x117] | 0x10000;
  }
  NdisReadConfiguration(param_1,(int *)&local_3c,param_4,local_30,2);
  if (((*param_1 == 0) && (*local_3c == 2)) && ((short)local_3c[1] != 0)) {
    local_3e = 0;
    psVar3 = (short *)local_3c[2];
    psVar9 = psVar3 + (*(ushort *)(local_3c + 1) >> 1);
    iVar6 = 0;
    psVar4 = psVar3;
    psVar7 = psVar3 + 2;
    if (psVar3 + 2 <= psVar9) {
      do {
        local_40 = (char)*psVar4;
        local_3f = (undefined1)psVar4[1];
        psVar5 = psVar4 + 2;
        psVar8 = psVar7 + 2;
        iVar1 = FUN_c055fb9c(&local_40,0x10,local_38);
        if (iVar1 < 0) break;
        iVar6 = iVar6 + 1;
        *(char *)psVar3 = (char)local_38[0];
        psVar3 = (short *)((int)psVar3 + 1);
        if ((psVar5 < psVar9) && (*psVar5 == 0x2d)) {
          psVar5 = psVar4 + 3;
          psVar8 = psVar7 + 3;
        }
        psVar4 = psVar5;
        psVar7 = psVar8;
      } while (psVar8 <= psVar9);
      if (iVar1 == 0) {
        *param_2 = local_3c[2];
        *param_3 = iVar6;
        if (iVar6 != 0) {
          *param_1 = 0;
        }
      }
    }
  }
  return;
}



/* c054ab0c FUN_c054ab0c */

/* Boundary evidence: original MIPS .pdata c054ab0c..c054ac2b. Semantic name remains unreviewed. */

void FUN_c054ab0c(void)

{
  FUN_c0560680((HKEY)0x80000002,L"Comm\\NDIS\\Parms",(undefined *)0x0,(undefined *)0x0);
  if (DAT_c05653bc == 0) {
    DAT_c05653bc = 1;
  }
  DAT_c05653c0 = DAT_c05653bc * 0x28 + 8;
  return;
}



/* c054ac2c FUN_c054ac2c */

/* Boundary evidence: original MIPS .pdata c054ac2c..c054ac57. Semantic name remains unreviewed. */

undefined4 FUN_c054ac2c(int param_1)

{
  (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc));
  return 0;
}



/* c054ac58 FUN_c054ac58 */

/* Boundary evidence: original MIPS .pdata c054ac58..c054acf3. Semantic name remains unreviewed. */

void FUN_c054ac58(void)

{
  PRTL_CRITICAL_SECTION_DEBUG p_Var1;
  int iVar2;
  _LIST_ENTRY *p_Var3;
  _LIST_ENTRY *p_Var4;
  _LIST_ENTRY *local_28 [2];
  
  do {
    p_Var1 = FUN_c055f180((LPCRITICAL_SECTION)&DAT_c0565454);
    iVar2 = FUN_c055f374(local_28,FUN_c054ac2c,p_Var1);
    if (iVar2 < 0) {
      p_Var3 = (p_Var1->ProcessLocksList).Blink;
      p_Var4 = (p_Var1->ProcessLocksList).Flink;
    }
    else {
      CeSetThreadPriority(local_28[0],DAT_c0565698 + 10);
      p_Var3 = local_28[0];
      p_Var4 = (_LIST_ENTRY *)CloseHandle_exref;
    }
    (*(code *)p_Var4)(p_Var3);
  } while( true );
}



/* c054acf4 FUN_c054acf4 */

/* Boundary evidence: original MIPS .pdata c054acf4..c054af97. Semantic name remains unreviewed. */

int FUN_c054acf4(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int local_b8;
  HANDLE local_b4;
  undefined1 auStack_b0 [40];
  int local_88;
  HANDLE local_84;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  HANDLE *local_6c;
  int local_68;
  
  piVar4 = *(int **)(param_1 + 0xc);
  local_b8 = 0;
  bVar2 = FUN_c055a404((int)(piVar4 + 1));
  puVar5 = *(undefined4 **)(param_1 + 0xbc);
  EnterCriticalSection((LPCRITICAL_SECTION)(piVar4 + 0x28));
  piVar4[0x2d] = 0x10908;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  for (iVar3 = *piVar4; (iVar3 != 0 && (iVar3 != param_1)); iVar3 = *(int *)(iVar3 + 0x18)) {
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (iVar3 != 0) {
    if ((param_2 != 0) && (piVar4[0x1a] != 0)) {
      memset(&local_78,0,0x4c);
      local_b4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
      local_78 = 2;
      local_6c = &local_b4;
      local_74 = 0;
      local_70 = 0;
      local_b8 = (*(code *)piVar4[0x1a])(*(undefined4 *)(param_1 + 0x10),&local_78);
      if (local_b8 == 0x103) {
        WaitForSingleObject(local_b4,0xffffffff);
        local_b8 = local_68;
      }
      CloseHandle(local_b4);
      if (local_b8 != 0) goto LAB_c054aef4;
    }
    if (puVar5 != (undefined4 *)0x0) {
      EventModify(*puVar5,2);
    }
    local_84 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    local_b8 = 0;
    (*(code *)piVar4[0x19])(&local_b8,*(undefined4 *)(param_1 + 0x10),auStack_b0);
    if (local_b8 == 0x103) {
      WaitForSingleObject(local_84,0xffffffff);
      local_b8 = local_88;
    }
    CloseHandle(local_84);
    if (puVar5 != (undefined4 *)0x0) {
      WaitForSingleObject((HANDLE)*puVar5,0xffffffff);
    }
  }
LAB_c054aef4:
  LeaveCriticalSection((LPCRITICAL_SECTION)(piVar4 + 0x28));
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  bVar1 = (*(uint *)(param_1 + 0x7c) & 0x100000) == 0;
  if (bVar1) {
    *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xffdeffef;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (!bVar1) {
    FUN_c054dfe8(param_1);
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x84));
    CTEFreeMem(param_1);
  }
  if (CONCAT31(extraout_var,bVar2) != 0) {
    FUN_c0548ad8((int)piVar4);
  }
  return local_b8;
}



/* c054af98 FUN_c054af98 */

/* Boundary evidence: original MIPS .pdata c054af98..c054b0fb. Semantic name remains unreviewed. */

void FUN_c054af98(ushort *param_1,int *param_2)

{
  void *_Buf1;
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  int *piVar4;
  uint _Size;
  ushort local_28;
  ushort local_26;
  void *local_24;
  
  *param_2 = 0;
  local_28 = *param_1;
  local_26 = local_28 + 2;
  local_24 = FUN_c05427a0((uint)local_26);
  if (local_24 != (void *)0x0) {
    FUN_c055f8ec(&local_28,param_1,0);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    for (piVar4 = (int *)DAT_c0565400; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      _Buf1 = local_24;
      iVar3 = piVar4[1];
      if (iVar3 != 0) {
        _Size = (uint)local_28;
        do {
          if ((((*(uint *)(iVar3 + 0x248) & 0x2000000) == 0) && (_Size == *(ushort *)(iVar3 + 0x10))
              ) && (iVar2 = memcmp(_Buf1,*(void **)(iVar3 + 0x14),_Size), iVar2 == 0)) {
            if (*param_2 != 0) {
              FUN_c0559738(*param_2);
              *param_2 = 0;
            }
            bVar1 = FUN_c055a404(iVar3 + 0x20);
            if (CONCAT31(extraout_var,bVar1) != 0) {
              *param_2 = iVar3;
            }
            break;
          }
          iVar3 = *(int *)(iVar3 + 0x1c);
        } while (iVar3 != 0);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    CTEFreeMem(local_24);
  }
  return;
}



/* c054b0fc FUN_c054b0fc */

/* Boundary evidence: original MIPS .pdata c054b0fc..c054b2cb. Semantic name remains unreviewed. */

void FUN_c054b0fc(int param_1,int *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  undefined4 uVar3;
  int local_268 [2];
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  int *local_254;
  int local_250;
  undefined4 local_24c;
  undefined4 local_248;
  int local_244;
  int local_230;
  HANDLE local_22c;
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_c05653c8;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x28));
  param_2[0x2d] = 0x10b0b;
  bVar1 = FUN_c054dce8(param_1);
  if (((CONCAT31(extraout_var,bVar1) != 0) &&
      (((iVar2 = *(int *)(param_1 + 0x354), iVar2 == 1 || (iVar2 == 2)) || (iVar2 == 4)))) &&
     ((iVar2 = FUN_c0552154(param_2,param_1), iVar2 != 1 &&
      (bVar1 = FUN_c055a404((int)(param_2 + 1)), CONCAT31(extraout_var_00,bVar1) != 0)))) {
    StringCchPrintfW(awStack_220,0x100,L"Comm\\%s\\Parms\\%s",*(undefined4 *)(param_1 + 0x14),
                     param_2[0x16]);
    FUN_c055f4e4((undefined2 *)&local_260,awStack_220);
    iVar2 = param_1 + 0x10;
    local_24c = local_260;
    param_2[0x2e] = iVar2;
    param_2[0x2f] = iVar2;
    uVar3 = *(undefined4 *)(param_1 + 0x1c8);
    local_258 = 0;
    local_248 = local_25c;
    local_254 = param_2;
    local_250 = param_1;
    local_244 = iVar2;
    local_22c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    if (*(char *)((int)param_2 + 0x1a) == '\0') {
      local_268[0] = 0;
      param_2[0x31] = param_1;
      (*(code *)param_2[0x18])(local_268,&local_258,iVar2,&local_260,uVar3);
      if (local_268[0] == 0x103) {
        WaitForSingleObject(local_22c,0xffffffff);
        local_268[0] = local_230;
      }
      param_2[0x31] = 0;
    }
    CloseHandle(local_22c);
    param_2[0x2e] = 0;
    FUN_c0548ad8((int)param_2);
  }
  param_2[0x2d] = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x28));
  FUN_c05625b0(local_20);
  return;
}



/* c054b2cc NdisCompleteBindAdapter */

/* Boundary evidence: original MIPS .pdata c054b2cc..c054b2ef. Semantic name remains unreviewed. */

void NdisCompleteBindAdapter(int param_1,undefined4 param_2)

{
                    /* 0xb2cc  42  NdisCompleteBindAdapter */
  *(undefined4 *)(param_1 + 0x28) = param_2;
  EventModify(*(undefined4 *)(param_1 + 0x2c),3);
  return;
}



/* c054b2f0 NdisCompleteUnbindAdapter */

/* Boundary evidence: original MIPS .pdata c054b2f0..c054b313. Semantic name remains unreviewed. */

void NdisCompleteUnbindAdapter(int param_1,undefined4 param_2)

{
                    /* 0xb2f0  44  NdisCompleteUnbindAdapter */
  *(undefined4 *)(param_1 + 0x28) = param_2;
  EventModify(*(undefined4 *)(param_1 + 0x2c),3);
  return;
}



/* c054b314 NdisRegisterTdiCallBack */

void NdisRegisterTdiCallBack(int param_1,int param_2)

{
                    /* 0xb314  191  NdisRegisterTdiCallBack */
  if (DAT_c0565418 == 0) {
    DAT_c0565418 = param_1;
  }
  if (DAT_c056541c == 0) {
    DAT_c056541c = param_2;
  }
  return;
}



/* c054b344 FUN_c054b344 */

/* Boundary evidence: original MIPS .pdata c054b344..c054b4cb. Semantic name remains unreviewed. */

void FUN_c054b344(ushort *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 int *param_5)

{
  ushort uVar1;
  bool bVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  int *piVar8;
  ushort local_30;
  ushort local_2e;
  ushort *local_2c;
  
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  local_30 = *param_1;
  bVar2 = false;
  local_2e = local_30 + 2;
  puVar3 = FUN_c05427a0((uint)local_2e);
  if (puVar3 != (ushort *)0x0) {
    local_2c = puVar3;
    FUN_c055f8ec(&local_30,param_1,0);
    puVar6 = &local_30;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    puVar7 = puVar3;
    for (piVar8 = (int *)DAT_c0565400; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      iVar5 = piVar8[1];
      if (iVar5 != 0) {
        uVar1 = *puVar6;
        do {
          if (((uint)uVar1 == (uint)*(ushort *)(iVar5 + 0x10)) &&
             (iVar4 = memcmp(*(void **)(puVar6 + 2),*(void **)(iVar5 + 0x14),(uint)uVar1),
             iVar4 == 0)) {
            puVar6 = (ushort *)(iVar5 + 0x10);
            *param_5 = iVar5;
            bVar2 = true;
            puVar7 = puVar6;
            break;
          }
          iVar5 = *(int *)(iVar5 + 0x1c);
        } while (iVar5 != 0);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      if (bVar2) break;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    CTEFreeMem(puVar3);
    if (bVar2) {
      *param_3 = puVar6;
      *param_4 = puVar7;
    }
  }
  return;
}



/* c054b4cc NdisMatchPdoWithPacket */

bool NdisMatchPdoWithPacket(int param_1,int param_2)

{
  int iVar1;
  
                    /* 0xb4cc  165  NdisMatchPdoWithPacket */
  if (*(uint *)(param_1 + -4) < DAT_c05653bc) {
    iVar1 = (*(uint *)(param_1 + -4) - DAT_c05653bc) * 0x28 + param_1 + -8;
  }
  else {
    iVar1 = 0;
  }
  return param_2 == *(int *)(*(int *)(iVar1 + 8) + 0x1c8);
}



/* c054b520 FUN_c054b520 */

/* Boundary evidence: original MIPS .pdata c054b520..c054b5f7. Semantic name remains unreviewed. */

int FUN_c054b520(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar2 = *(int *)(param_1 + 4);
  do {
    if (iVar2 == 0) {
LAB_c054b5d4:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      return iVar2;
    }
    if (((((*(uint *)(iVar2 + 0x54) & 0x80200020) == 0) &&
         ((*(uint *)(iVar2 + 0x248) & 0x10c4110) == 0)) && (*(int *)(iVar2 + 0x354) == 1)) &&
       ((*(int *)(iVar2 + 0x2c4) == 1 &&
        (bVar1 = FUN_c055a404(iVar2 + 0x20), CONCAT31(extraout_var,bVar1) != 0)))) {
      *(uint *)(iVar2 + 0x248) = *(uint *)(iVar2 + 0x248) | 0x40000;
      goto LAB_c054b5d4;
    }
    iVar2 = *(int *)(iVar2 + 0x1c);
  } while( true );
}



/* c054b5f8 FUN_c054b5f8 */

/* Boundary evidence: original MIPS .pdata c054b5f8..c054b69f. Semantic name remains unreviewed. */

void FUN_c054b5f8(int param_1)

{
  int iVar1;
  
  do {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
      if ((*(uint *)(iVar1 + 0x248) & 0x40000) != 0) {
        *(uint *)(iVar1 + 0x248) = *(uint *)(iVar1 + 0x248) & 0xfffbffff;
        break;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if (iVar1 == 0) {
      return;
    }
    FUN_c0559738(iVar1);
  } while( true );
}



/* c054b6a0 NdisGetVersion */

undefined4 NdisGetVersion(void)

{
                    /* 0xb6a0  84  NdisGetVersion */
  return 0x50001;
}



/* c054b6ac FUN_c054b6ac */

/* Boundary evidence: original MIPS .pdata c054b6ac..c054b70b. Semantic name remains unreviewed. */

int FUN_c054b6ac(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = __GetUserKData(8);
  while (DAT_c0565604 == iVar1) {
    iVar2 = iVar2 + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = __GetUserKData(8);
  }
  return iVar2;
}



/* c054b70c FUN_c054b70c */

/* Boundary evidence: original MIPS .pdata c054b70c..c054b757. Semantic name remains unreviewed. */

void FUN_c054b70c(undefined4 param_1,int param_2)

{
  for (; 0 < param_2; param_2 = param_2 + -1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c054b758 FUN_c054b758 */

/* Boundary evidence: original MIPS .pdata c054b758..c054b81f. Semantic name remains unreviewed. */

void FUN_c054b758(int param_1)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  iVar3 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x4b0);
  while (BVar1 = TryEnterCriticalSection(lpCriticalSection), BVar1 != 1) {
    iVar2 = FUN_c054b6ac();
    if (iVar3 == 0) {
      iVar3 = iVar2 + -1;
    }
    EnterCriticalSection(lpCriticalSection);
    BVar1 = TryEnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if (BVar1 == 1) break;
    LeaveCriticalSection(lpCriticalSection);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  FUN_c054b70c(param_1,iVar3);
  return;
}



/* c054b820 NdisSetLoggingState */

/* Boundary evidence: original MIPS .pdata c054b820..c054b90b. Semantic name remains unreviewed. */

void NdisSetLoggingState(int param_1)

{
  int iVar1;
  
                    /* 0xb820  202  NdisSetLoggingState */
  if (DAT_c05653f4 != param_1) {
    DAT_c05653f4 = param_1;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    for (iVar1 = DAT_c0565408; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x250)) {
      if (DAT_c05653f4 == 0) {
        *(code **)(iVar1 + 0x208) = EthFilterDprIndicateReceive;
      }
      else {
        *(code **)(iVar1 + 0x208) = FUN_c0543e98;
      }
      FUN_c054dde0(iVar1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    for (iVar1 = DAT_c056540c; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xd8)) {
      FUN_c054e074(*(int *)(iVar1 + 8),iVar1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c054b90c FUN_c054b90c */

/* Boundary evidence: original MIPS .pdata c054b90c..c054ba5b. Semantic name remains unreviewed. */

int FUN_c054b90c(void)

{
  int iVar1;
  undefined4 local_10 [2];
  
  NdisInitializeString((undefined2 *)&DAT_c0565480,(byte *)"Sep  6 2006");
  NdisInitializeString((undefined2 *)&DAT_c0565488,(byte *)"19:01:08");
  NdisInitializeString((undefined2 *)&DAT_c0565490,(byte *)"BUILT_BY");
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05655a0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0565660);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0565680);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0565580);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05655c0);
  DAT_c0565420 = 8;
  DAT_c0565424 = 10000;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0565428);
  FUN_c054ab0c();
  DAT_c056543c = 0x42;
  FUN_c055f094((LPCRITICAL_SECTION)&DAT_c0565454);
  iVar1 = FUN_c055f374(local_10,FUN_c054ac58,(LPVOID)0x0);
  if (-1 < iVar1) {
    DAT_c0565440 = local_10[0];
    CeSetThreadPriority(local_10[0],DAT_c0565698 + 10);
  }
  DAT_c0565414 = &DAT_c0565410;
  DAT_c0565410 = &DAT_c0565410;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05655e0);
  return iVar1;
}



/* c054ba5c FUN_c054ba5c */

/* Boundary evidence: original MIPS .pdata c054ba5c..c054bbf7. Semantic name remains unreviewed. */

undefined4 FUN_c054ba5c(HMODULE param_1,int param_2)

{
  int iVar1;
  undefined2 auStack_20 [4];
  
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
    iVar1 = FUN_c0560594((HKEY)0x80000002,L"Drivers\\Builtin\\NDIS",L"Priority256",
                         (LPBYTE)&DAT_c0565698);
    if (iVar1 == 0) {
      DAT_c0565698 = 0x74;
    }
    iVar1 = FUN_c0560594((HKEY)0x80000002,L"Drivers\\Builtin\\NDIS",L"PcmciaPriority256",
                         (LPBYTE)&DAT_c0565644);
    if (iVar1 == 0) {
      DAT_c0565644 = 100;
    }
    DAT_c0565694 = 0;
    DAT_c0565594 = 0;
    FUN_c0560594((HKEY)0x80000002,L"Drivers\\Builtin\\NDIS",L"RebindOnResume",(LPBYTE)&DAT_c0565594)
    ;
    DAT_c0565640 = 0;
    FUN_c0560594((HKEY)0x80000002,L"Drivers\\Builtin\\NDIS",L"NeedsMapToScrap",(LPBYTE)&DAT_c0565640
                );
    DAT_c0565614 = FUN_c0561518((LPCRITICAL_SECTION)&DAT_c0565620,DAT_c0565698 + 2);
    FUN_c0560e04(&DAT_c0565620,DAT_c0565698 + 4);
    FUN_c0561474();
    FUN_c0560448();
    FUN_c055ec30();
    FUN_c055f4e4(auStack_20,L"\\Comm");
    FUN_c054b90c();
    memset(&DAT_c05656e0,0,0x80);
  }
  return 1;
}



/* c054bbf8 FUN_c054bbf8 */

/* Boundary evidence: original MIPS .pdata c054bbf8..c054bd0b. Semantic name remains unreviewed. */

void FUN_c054bbf8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  
  if (param_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    piVar1 = DAT_c0565400;
    while ((piVar1 != (int *)0x0 &&
           (bVar2 = FUN_c055a404((int)(piVar1 + 0x28)), CONCAT31(extraout_var,bVar2) != 0))) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      while (iVar3 = FUN_c054b520((int)piVar1), iVar3 != 0) {
        pcVar4 = *(code **)(*(int *)(iVar3 + 8) + 0x84);
        if (pcVar4 != (code *)0x0) {
          (*pcVar4)(*(undefined4 *)(iVar3 + 0xc),5,param_3,param_4);
        }
      }
      FUN_c054b5f8((int)piVar1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      piVar5 = (int *)*piVar1;
      FUN_c055915c(piVar1,1);
      piVar1 = piVar5;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  else {
    pcVar4 = *(code **)(*(int *)(param_1 + 8) + 0x84);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4);
    }
  }
  return;
}



/* c054bd0c NdisCompletePnPEvent */

/* Boundary evidence: original MIPS .pdata c054bd0c..c054bd33. Semantic name remains unreviewed. */

void NdisCompletePnPEvent(undefined4 param_1,undefined4 param_2,int param_3)

{
                    /* 0xbd0c  43  NdisCompletePnPEvent */
  *(undefined4 *)(param_3 + 0x10) = param_1;
  EventModify(**(undefined4 **)(param_3 + 0xc),3);
  return;
}



/* c054bd34 FUN_c054bd34 */

/* Boundary evidence: original MIPS .pdata c054bd34..c054bdd7. Semantic name remains unreviewed. */

int FUN_c054bd34(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar1 = *(int *)(param_1 + 0x18);
  do {
    if (iVar1 == 0) {
LAB_c054bdb8:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      return iVar1;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if ((*(uint *)(iVar1 + 0x7c) & 0x18010) == 0) {
      *(uint *)(iVar1 + 0x7c) = *(uint *)(iVar1 + 0x7c) | 0x80010;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      goto LAB_c054bdb8;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = *(int *)(iVar1 + 0x14);
  } while( true );
}



/* c054bdd8 FUN_c054bdd8 */

/* Boundary evidence: original MIPS .pdata c054bdd8..c054be77. Semantic name remains unreviewed. */

void FUN_c054bdd8(int param_1)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar1 = *(int *)(param_1 + 0x18);
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x14);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if ((*(uint *)(iVar1 + 0x7c) & 0x80010) == 0x80010) {
      *(uint *)(iVar1 + 0x7c) = *(uint *)(iVar1 + 0x7c) & 0xfff7ffef;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = iVar2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c054be78 FUN_c054be78 */

/* Boundary evidence: original MIPS .pdata c054be78..c054c04b. Semantic name remains unreviewed. */

int FUN_c054be78(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  HANDLE local_28 [2];
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar4 = -0x3fffff45;
  uVar3 = *(undefined4 *)(param_1 + 0x10);
  if (*(int *)(iVar2 + 0x68) == 0) {
    iVar2 = *param_2;
    if (iVar2 == 2) {
      return 0;
    }
    if (iVar2 == 1) {
      return 0;
    }
    if (iVar2 == 3) {
      return 0;
    }
  }
  else {
    uVar1 = 0;
    local_28[0] = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    param_2[3] = (int)local_28;
    iVar4 = (**(code **)(iVar2 + 0x68))(uVar3,param_2);
    if (iVar4 == 0x103) {
      WaitForSingleObject(local_28[0],0xffffffff);
      iVar4 = param_2[4];
    }
    if (((*param_2 == 1) && (iVar4 != 0)) && (iVar4 != -0x3fffff45)) {
      DbgPrint("***NDIS***: Protocol %Z failed QueryPower %lx\n",iVar2 + 0x54,iVar4,uVar1);
    }
    CloseHandle(local_28[0]);
  }
  if (iVar4 != -0x3fffff45) {
    return iVar4;
  }
  if (*param_2 == 0) {
    if (*(int *)param_2[1] < 2) {
      return -0x3fffff45;
    }
    if (*(int *)param_2[1] < 5) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      if ((*(uint *)(param_1 + 0x7c) & 0x18000) == 0) {
        *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 0x210000;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        FUN_c054acf4(param_1,0);
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      }
      return 0;
    }
    return -0x3fffff45;
  }
  return -0x3fffff45;
}



/* c054c04c FUN_c054c04c */

/* Boundary evidence: original MIPS .pdata c054c04c..c054c29b. Semantic name remains unreviewed. */

undefined4 FUN_c054c04c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 auStack_28 [4];
  HANDLE local_24;
  
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  piVar3 = &DAT_c0565408;
  for (iVar2 = DAT_c0565408; (iVar2 != 0 && (*(int **)(iVar2 + 0x1c8) != param_1));
      iVar2 = *(int *)(iVar2 + 0x250)) {
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
  if (iVar2 == 0) {
    uVar4 = 0xc000000d;
  }
  else {
    if (*(int *)(iVar2 + 0x124) == -2) {
      FUN_c055e1cc(iVar2);
    }
    if (*(int *)(iVar2 + 0x354) != 6) {
      *(undefined4 *)(iVar2 + 0x354) = 5;
      *(uint *)(iVar2 + 0x248) = *(uint *)(iVar2 + 0x248) & 0xfffeffff | 0x10;
      bVar1 = FUN_c055a404(iVar2 + 0x20);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        *(undefined4 *)(iVar2 + 0x3ac) = 0;
      }
      else {
        param_4 = 0;
        param_3 = 0;
        local_24 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
        *(HANDLE **)(iVar2 + 0x3ac) = &local_24;
      }
      uVar4 = FUN_c0551048(*(int *)(iVar2 + 0x1c4),0,param_3,param_4);
      if (*(int *)(iVar2 + 0x3ac) != 0) {
        FUN_c0559738(iVar2);
        WaitForSingleObject(local_24,0xffffffff);
        CloseHandle(local_24);
      }
    }
    if (*(int *)(iVar2 + 0x124) == -2) {
      FUN_c055e6e0(iVar2);
    }
    if (DAT_c05653f0 == 1) {
      FUN_c0546720(iVar2);
    }
    NdisCancelTimer((int *)(iVar2 + 0xb8),auStack_28);
    if (*(int *)(iVar2 + 0x1e8) != 0) {
      CTEFreeMem();
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
    for (; *piVar3 != 0; piVar3 = (int *)(*piVar3 + 0x250)) {
      if (*piVar3 == iVar2) {
        *piVar3 = *(int *)(iVar2 + 0x250);
        break;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
    if (*(int *)(iVar2 + 0x240) != 0) {
      CTEFreeMem();
    }
    NdisFreeEvent((undefined4 *)(iVar2 + 0x350));
    DeleteCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x3c));
    DeleteCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x4b0));
    FUN_c055a518((LPCRITICAL_SECTION)(iVar2 + 0x20));
    FUN_c055fd24(*(int **)(iVar2 + 0x1c4));
    FUN_c055fd24(param_1);
  }
  return uVar4;
}



/* c054c29c FUN_c054c29c */

/* Boundary evidence: original MIPS .pdata c054c29c..c054c373. Semantic name remains unreviewed. */

int FUN_c054c29c(int param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int local_68;
  int *local_64;
  undefined4 local_60;
  
  iVar2 = 0;
  memset(&local_68,0,0x4c);
  local_68 = param_2;
  local_64 = param_3;
  local_60 = param_4;
  while (iVar1 = FUN_c054bd34(param_1), iVar1 != 0) {
    iVar2 = FUN_c054be78(iVar1,&local_68);
    if (iVar2 != 0) {
      if (((param_2 == 1) || (param_2 == 2)) || ((param_2 == 0 && (1 < *param_3)))) break;
      iVar2 = 0;
    }
  }
  FUN_c054bdd8(param_1);
  return iVar2;
}



/* c054c374 NdisIMNotifyPnPEvent */

/* Boundary evidence: original MIPS .pdata c054c374..c054c3bb. Semantic name remains unreviewed. */

int NdisIMNotifyPnPEvent(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0xc374  96  NdisIMNotifyPnPEvent */
  iVar2 = *param_2;
  iVar1 = 0;
  if ((-1 < iVar2) && ((iVar2 < 4 || (iVar2 == 7)))) {
    iVar1 = FUN_c054c29c(param_1,iVar2,(int *)param_2[1],param_2[2]);
  }
  return iVar1;
}



/* c054c3bc NdisMNotifyPnPEvent */

/* Boundary evidence: original MIPS .pdata c054c3bc..c054c3d7. Semantic name remains unreviewed. */

void NdisMNotifyPnPEvent(int param_1,int *param_2)

{
                    /* 0xc3bc  133  NdisMNotifyPnPEvent */
  NdisIMNotifyPnPEvent(param_1,param_2);
  return;
}



/* c054c3d8 NdisInitAnsiString */

/* Boundary evidence: original MIPS .pdata c054c3d8..c054c3f3. Semantic name remains unreviewed. */

void NdisInitAnsiString(short *param_1,char *param_2)

{
                    /* 0xc3d8  101  NdisInitAnsiString */
  FUN_c055f49c(param_1,param_2);
  return;
}



/* c054c3f4 NdisInitUnicodeString */

/* Boundary evidence: original MIPS .pdata c054c3f4..c054c40f. Semantic name remains unreviewed. */

void NdisInitUnicodeString(undefined2 *param_1,short *param_2)

{
                    /* 0xc3f4  102  NdisInitUnicodeString */
  FUN_c055f4e4(param_1,param_2);
  return;
}



/* c054c410 NdisEqualString */

/* Boundary evidence: original MIPS .pdata c054c410..c054c42b. Semantic name remains unreviewed. */

void NdisEqualString(ushort *param_1,ushort *param_2,int param_3)

{
                    /* 0xc410  57  NdisEqualString */
  FUN_c055f908(param_1,param_2,param_3);
  return;
}



/* c054c42c FUN_c054c42c */

/* Boundary evidence: original MIPS .pdata c054c42c..c054c483. Semantic name remains unreviewed. */

int FUN_c054c42c(wchar_t *param_1)

{
  wchar_t wVar1;
  size_t sVar2;
  int iVar3;
  
  iVar3 = 0;
  wVar1 = *param_1;
  while (wVar1 != L'\0') {
    sVar2 = wcslen(param_1);
    param_1 = param_1 + sVar2 + 1;
    iVar3 = iVar3 + 1;
    wVar1 = *param_1;
  }
  return iVar3;
}



/* c054c484 FUN_c054c484 */

/* Boundary evidence: original MIPS .pdata c054c484..c054c69b. Semantic name remains unreviewed. */

undefined1 *
FUN_c054c484(undefined1 *param_1,LPCWSTR param_2,int param_3,undefined4 param_4,int param_5,
            int param_6,undefined4 param_7,wchar_t *param_8,LPCWSTR param_9)

{
  wchar_t wVar1;
  int iVar2;
  ulong uVar3;
  size_t sVar4;
  ulong uVar5;
  wchar_t *_Str;
  ulong local_248;
  wchar_t *local_244;
  int local_240 [2];
  undefined1 auStack_238 [8];
  wchar_t local_230 [260];
  uint local_28;
  
  local_28 = DAT_c05653c8;
  if ((param_6 == 1) && (*param_8 == L'\0')) {
    local_248 = 0;
    FUN_c0560594((HKEY)0x80000002,param_2,param_9,(LPBYTE)&local_248);
    *param_1 = (char)param_5;
    param_1[1] = 0;
    *(undefined2 *)(param_1 + 2) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (param_5 == 1) {
      local_240[0] = 1;
      *(undefined4 *)(param_1 + 8) = param_7;
      *(ulong *)(param_1 + 0x10) = local_248;
      if (((param_3 != -2) &&
          (iVar2 = HalTranslateBusAddress
                             (param_3,param_4,*(undefined4 *)(param_1 + 8),0,local_240,auStack_238),
          iVar2 != 0)) && (local_240[0] != 0)) {
        *(undefined2 *)(param_1 + 2) = 1;
      }
    }
    else {
      *(undefined4 *)(param_1 + 8) = param_7;
      *(ulong *)(param_1 + 0x10) = local_248;
    }
    param_1 = param_1 + 0x18;
LAB_c054c668:
    FUN_c05625b0(local_28);
    return param_1;
  }
  local_230[0] = L'\0';
  _Str = local_230;
  FUN_c056056c((HKEY)0x80000002,param_2,param_9,(LPBYTE)local_230,0x208);
  wVar1 = *param_8;
  do {
    if (((wVar1 == L'\0') || (uVar3 = wcstoul(param_8,&local_244,0x10), local_244 == param_8)) ||
       (*local_244 != L'\0')) goto LAB_c054c668;
    uVar5 = 0;
    local_248 = 0;
    if (*_Str != L'\0') {
      uVar5 = wcstoul(_Str,&local_244,0x10);
      local_248 = uVar5;
      if ((local_244 == _Str) || (*local_244 != L'\0')) goto LAB_c054c668;
      sVar4 = wcslen(_Str);
      _Str = _Str + sVar4 + 1;
    }
    *param_1 = (char)param_5;
    param_1[1] = 0;
    *(undefined2 *)(param_1 + 2) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(ulong *)(param_1 + 8) = uVar3;
    *(ulong *)(param_1 + 0x10) = uVar5;
    param_1 = param_1 + 0x18;
    sVar4 = wcslen(param_8);
    param_8 = param_8 + sVar4 + 1;
    wVar1 = *param_8;
  } while( true );
}



/* c054c69c FUN_c054c69c */

/* Boundary evidence: original MIPS .pdata c054c69c..c054ca7f. Semantic name remains unreviewed. */

undefined4 FUN_c054c69c(int param_1,LPCWSTR param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448 [2];
  wchar_t local_440 [260];
  wchar_t local_238 [260];
  uint local_30;
  
  local_30 = DAT_c05653c8;
  uVar7 = 0;
  local_440[0] = L'\0';
  iVar6 = 0;
  local_238[0] = L'\0';
  iVar5 = 0;
  iVar1 = FUN_c0560594((HKEY)0x80000002,param_2,L"InterruptNumber",(LPBYTE)&local_450);
  if (((iVar1 == 0) &&
      (iVar1 = FUN_c0560594((HKEY)0x80000002,param_2,L"Interrupt",(LPBYTE)&local_450), iVar1 == 0))
     && (iVar1 = FUN_c0560594((HKEY)0x80000002,param_2,L"Irq",(LPBYTE)&local_450), iVar1 == 0)) {
    local_450 = 0xff;
  }
  iVar1 = FUN_c0560594((HKEY)0x80000002,param_2,L"IoBaseAddress",(LPBYTE)local_448);
  if (((iVar1 == 0) &&
      (iVar1 = FUN_c0560594((HKEY)0x80000002,param_2,L"IoAddress",(LPBYTE)local_448), iVar1 == 0))
     && (iVar1 = FUN_c0560594((HKEY)0x80000002,param_2,L"IOBase",(LPBYTE)local_448), iVar1 == 0)) {
    iVar1 = FUN_c056056c((HKEY)0x80000002,param_2,L"IoBaseAddress",(LPBYTE)local_440,0x208);
    if (((iVar1 != 0) ||
        (iVar1 = FUN_c056056c((HKEY)0x80000002,param_2,L"IoAddress",(LPBYTE)local_440,0x208),
        iVar1 != 0)) ||
       (iVar1 = FUN_c056056c((HKEY)0x80000002,param_2,L"IOBase",(LPBYTE)local_440,0x208), iVar1 != 0
       )) {
      iVar6 = FUN_c054c42c(local_440);
    }
  }
  else {
    iVar6 = 1;
  }
  iVar1 = FUN_c0560594((HKEY)0x80000002,param_2,L"MemoryMappedBaseAddress",(LPBYTE)&local_44c);
  if (((iVar1 == 0) &&
      (iVar1 = FUN_c0560594((HKEY)0x80000002,param_2,L"RamAddress",(LPBYTE)&local_44c), iVar1 == 0))
     && (iVar1 = FUN_c0560594((HKEY)0x80000002,param_2,L"MemBase",(LPBYTE)&local_44c), iVar1 == 0))
  {
    iVar1 = FUN_c056056c((HKEY)0x80000002,param_2,L"MemoryMappedBaseAddress",(LPBYTE)local_238,0x208
                        );
    if (((iVar1 != 0) ||
        (iVar1 = FUN_c056056c((HKEY)0x80000002,param_2,L"RamAddress",(LPBYTE)local_238,0x208),
        iVar1 != 0)) ||
       (iVar1 = FUN_c056056c((HKEY)0x80000002,param_2,L"MemBase",(LPBYTE)local_238,0x208),
       iVar1 != 0)) {
      iVar5 = FUN_c054c42c(local_238);
    }
  }
  else {
    iVar5 = 1;
  }
  puVar2 = FUN_c05427a0((iVar5 + iVar6 + 2) * 0x18);
  if (puVar2 == (undefined4 *)0x0) {
    uVar7 = 0xc000009a;
  }
  else {
    *puVar2 = 1;
    puVar2[2] = *(undefined4 *)(param_1 + 0x124);
    uVar4 = *(undefined4 *)(param_1 + 0x120);
    puVar2[5] = iVar5 + iVar6 + 1;
    puVar2[3] = uVar4;
    *(undefined2 *)(puVar2 + 4) = 0;
    *(undefined2 *)((int)puVar2 + 0x12) = 0;
    *(undefined1 *)(puVar2 + 6) = 2;
    *(undefined1 *)((int)puVar2 + 0x19) = 3;
    *(undefined2 *)((int)puVar2 + 0x1a) = 0;
    puVar3 = puVar2 + 0xc;
    puVar2[8] = local_450;
    puVar2[9] = local_450;
    puVar2[10] = 0;
    if (iVar6 != 0) {
      puVar3 = (undefined4 *)
               FUN_c054c484((undefined1 *)puVar3,param_2,*(int *)(param_1 + 0x124),
                            *(undefined4 *)(param_1 + 0x120),1,iVar6,local_448[0],local_440,L"IOLen"
                           );
    }
    if (iVar5 != 0) {
      FUN_c054c484((undefined1 *)puVar3,param_2,*(int *)(param_1 + 0x124),
                   *(undefined4 *)(param_1 + 0x120),3,iVar5,local_44c,local_238,L"MemLen");
    }
    *(undefined4 **)(param_1 + 0x264) = puVar2;
  }
  FUN_c05625b0(local_30);
  return uVar7;
}



/* c054ca80 NdisIMSwitchToMiniport */

/* Boundary evidence: original MIPS .pdata c054ca80..c054cb5b. Semantic name remains unreviewed. */

uint NdisIMSwitchToMiniport(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
                    /* 0xca80  100  NdisIMSwitchToMiniport */
  *(undefined1 *)param_2 = 0;
  iVar1 = __GetUserKData(8);
  if (*(int *)(param_1 + 0x4b4) == iVar1) {
    *param_2 = 0xffffffff;
    uVar3 = 1;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = __GetUserKData(8);
    uVar3 = (uint)(*(int *)(param_1 + 0x4b4) != iVar1);
    if (uVar3 == 1) {
      uVar3 = TryEnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
      uVar3 = uVar3 & 0xff;
      if (uVar3 == 1) {
        *(undefined4 *)(param_1 + 0x454) = 0xb0a38;
        uVar2 = __GetUserKData(8);
        *(undefined4 *)(param_1 + 0x458) = uVar2;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return uVar3;
}



/* c054cb5c FUN_c054cb5c */

/* Boundary evidence: original MIPS .pdata c054cb5c..c054cc27. Semantic name remains unreviewed. */

void FUN_c054cb5c(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)((param_2 + 0x1b) * 4 + param_1);
  puVar2 = (undefined4 *)*puVar1;
  if ((puVar2 != (undefined4 *)0x0) && (*puVar1 = *puVar2, puVar2 != (undefined4 *)0x0)) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = puVar2[2];
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = puVar2[3];
    }
    if (param_2 == 3) {
      puVar2[1] = 4;
      *puVar2 = *(undefined4 *)(param_1 + 0x7c);
      *(undefined4 **)(param_1 + 0x7c) = puVar2;
    }
    else if (param_2 == 4) {
      *puVar2 = *(undefined4 *)(param_1 + 0x160);
      *(undefined4 **)(param_1 + 0x160) = puVar2;
    }
    else if (param_2 == 6) {
      CTEFreeMem(puVar2);
    }
    else {
      puVar1 = (undefined4 *)((param_2 + 0x55) * 4 + param_1);
      *puVar2 = *puVar1;
      *puVar1 = puVar2;
    }
  }
  return;
}



/* c054cc28 FUN_c054cc28 */

/* Boundary evidence: original MIPS .pdata c054cc28..c054cd07. Semantic name remains unreviewed. */

int FUN_c054cc28(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)((param_2 + 0x55) * 4 + param_1);
  puVar2 = (undefined4 *)*puVar1;
  if ((puVar2 == (undefined4 *)0x0) || (*puVar1 = *puVar2, puVar2 == (undefined4 *)0x0)) {
    iVar3 = 0x10003;
  }
  else {
    puVar1 = (undefined4 *)((param_2 + 0x1b) * 4 + param_1);
    puVar2[1] = param_2;
    puVar2[2] = param_3;
    iVar3 = 0;
    *puVar2 = *puVar1;
    *puVar1 = puVar2;
  }
  if (((*(uint *)(param_1 + 0x54) & 0x48000) == 0x8000) && (iVar3 == 0)) {
    FUN_c05614a0((LPCRITICAL_SECTION)&DAT_c0565620,param_1 + 0x364);
  }
  else if ((((*(uint *)(param_1 + 0x54) & 0x40000) != 0) ||
           ((*(uint *)(param_1 + 0x248) & 0x4000) != 0)) && (param_2 == 0)) {
    FUN_c05584e8(param_1);
  }
  return iVar3;
}



/* c054cd08 FUN_c054cd08 */

/* Boundary evidence: original MIPS .pdata c054cd08..c054cddf. Semantic name remains unreviewed. */

int FUN_c054cd08(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 4;
  if (param_4 == 0) {
    iVar2 = 0;
  }
  puVar1 = FUN_c05427a0(iVar2 + 0xc);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = -0x3fffffff;
  }
  else {
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    if (param_4 != 0) {
      puVar1[3] = param_4;
    }
    puVar3 = (undefined4 *)((param_2 + 0x1b) * 4 + param_1);
    iVar2 = 0;
    *puVar1 = *puVar3;
    *puVar3 = puVar1;
  }
  if (((*(uint *)(param_1 + 0x54) & 0x48000) == 0x8000) && (iVar2 == 0)) {
    FUN_c05614a0((LPCRITICAL_SECTION)&DAT_c0565620,param_1 + 0x364);
  }
  return iVar2;
}



/* c054cde0 NdisMIndicateStatusComplete */

/* Boundary evidence: original MIPS .pdata c054cde0..c054ced7. Semantic name remains unreviewed. */

void NdisMIndicateStatusComplete(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* 0xcde0  130  NdisMIndicateStatusComplete */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar3 = *(int *)(param_1 + 0x18);
  while (iVar1 = iVar3, iVar1 != 0) {
    if ((*(uint *)(iVar1 + 0x7c) & 0x18000) == 0) {
      NdisInterlockedIncrement((LONG *)(iVar1 + 0x80));
      if ((*(int *)(iVar1 + 0x78) != 0) && ((*(uint *)(iVar1 + 0x7c) & 0x100) != 0)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        (**(code **)(iVar1 + 0x78))(*(undefined4 *)(iVar1 + 0x10));
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      }
      iVar3 = *(int *)(iVar1 + 0x14);
      *(uint *)(iVar1 + 0x7c) = *(uint *)(iVar1 + 0x7c) & 0xfffffeff;
      iVar2 = NdisInterlockedDecrement((LONG *)(iVar1 + 0x80));
      if (iVar2 == 0) {
        FUN_c0559efc(iVar1);
      }
    }
    else {
      iVar3 = *(int *)(iVar1 + 0x14);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c054ced8 NdisMWanIndicateReceive */

/* Boundary evidence: original MIPS .pdata c054ced8..c054cfb7. Semantic name remains unreviewed. */

void NdisMWanIndicateReceive
               (undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
                    /* 0xced8  160  NdisMWanIndicateReceive */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (*(code **)g_pLogRxContigPacket_exref != (code *)0x0) {
    (**(code **)g_pLogRxContigPacket_exref)
              (0,*(undefined4 *)(param_2 + 0x14),&DAT_c054174c,param_4,param_5);
  }
  for (iVar2 = *(int *)(param_2 + 0x18); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    uVar1 = (**(code **)(*(int *)(iVar2 + 0xc) + 0x44))(param_3,param_4,param_5);
    *param_1 = uVar1;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c054cfb8 NdisMWanIndicateReceiveComplete */

/* Boundary evidence: original MIPS .pdata c054cfb8..c054d037. Semantic name remains unreviewed. */

void NdisMWanIndicateReceiveComplete(int param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0xcfb8  161  NdisMWanIndicateReceiveComplete */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  for (iVar1 = *(int *)(param_1 + 0x18); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    (**(code **)(iVar1 + 0x54))(param_2);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c054d038 NdisGetReceivedPacket */

/* Boundary evidence: original MIPS .pdata c054d038..c054d0b3. Semantic name remains unreviewed. */

undefined4 NdisGetReceivedPacket(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0xd038  82  NdisGetReceivedPacket */
  iVar1 = *(int *)(param_1 + 8);
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((*(int *)(iVar1 + 0x3a8) == param_2) && (param_2 != 0)) {
    uVar2 = *(undefined4 *)((uint)*(ushort *)(param_2 + 0x1e) + param_2 + 0x3c);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return uVar2;
}



/* c054d0b4 FUN_c054d0b4 */

/* Boundary evidence: original MIPS .pdata c054d0b4..c054d2a3. Semantic name remains unreviewed. */

void FUN_c054d0b4(int *param_1,int param_2)

{
  LONG LVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  
  uVar4 = DAT_c05653bc;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    iVar9 = *param_1;
    uVar7 = 0;
    if (*(uint *)(iVar9 + -4) < uVar4) {
      iVar5 = (*(uint *)(iVar9 + -4) - uVar4) * 0x28 + iVar9 + -8;
    }
    else {
      iVar5 = 0;
    }
    piVar8 = (int *)(iVar5 + 8);
    iVar6 = *piVar8;
    if ((iVar6 != 0) &&
       (LVar1 = InterlockedDecrement((LONG *)(iVar5 + 0xc)), uVar4 = DAT_c05653bc, LVar1 == 0)) {
      if ((*(uint *)(iVar6 + 0x54) & 0x40000) == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        iVar5 = __GetUserKData(8);
        uVar7 = (uint)(*(int *)(iVar6 + 0x4b4) != iVar5);
        if (uVar7 == 1) {
          uVar7 = TryEnterCriticalSection((LPCRITICAL_SECTION)(iVar6 + 0x4b0));
          uVar7 = uVar7 & 0xff;
          if (uVar7 == 1) {
            *(undefined4 *)(iVar6 + 0x454) = 0xb0fc8;
            uVar2 = __GetUserKData(8);
            *(undefined4 *)(iVar6 + 0x458) = uVar2;
          }
        }
      }
      if (((*(uint *)(iVar6 + 0x54) & 0x40000) == 0) && (uVar7 == 0)) {
        *piVar8 = *(int *)(iVar6 + 0x18c);
        *(int *)(iVar6 + 0x18c) = iVar9;
        FUN_c054cc28(iVar6,2,0);
      }
      else {
        pcVar3 = *(code **)(*(int *)(iVar6 + 8) + 0x5c);
        *piVar8 = 0;
        *(int *)(iVar9 + -4) = *(int *)(iVar9 + -4) + -1;
        (*pcVar3)(*(undefined4 *)(iVar6 + 0xc),iVar9);
      }
      uVar4 = DAT_c05653bc;
      if ((*(uint *)(iVar6 + 0x54) & 0x40000) == 0) {
        if (uVar7 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar6 + 0x4b0));
          *(undefined4 *)(iVar6 + 0x454) = 0;
          *(undefined4 *)(iVar6 + 0x458) = 0;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        uVar4 = DAT_c05653bc;
      }
    }
    param_1 = param_1 + 1;
  }
  return;
}



/* c054d2a4 NdisReturnPackets */

/* Boundary evidence: original MIPS .pdata c054d2a4..c054d3bb. Semantic name remains unreviewed. */

void NdisReturnPackets(int *param_1,int param_2)

{
  int iVar1;
  LONG LVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  
                    /* 0xd2a4  197  NdisReturnPackets */
  iVar1 = DAT_c05653c0;
  iVar5 = 0;
  pcVar6 = (code *)0x0;
  uVar9 = 0;
  if (DAT_c05653fc == 0) {
    FUN_c054d0b4(param_1,param_2);
  }
  else {
    piVar7 = param_1 + param_2;
    for (; param_1 < piVar7; param_1 = param_1 + 1) {
      iVar4 = *param_1;
      iVar3 = (*(int *)(iVar4 + -4) * 0x28 - iVar1) + iVar4;
      piVar8 = (int *)(iVar3 + 8);
      LVar2 = InterlockedDecrement((LONG *)(iVar3 + 0xc));
      if (LVar2 == 0) {
        iVar3 = *piVar8;
        if (iVar5 != iVar3) {
          pcVar6 = *(code **)(*(int *)(iVar3 + 8) + 0x5c);
          uVar9 = *(undefined4 *)(iVar3 + 0xc);
          iVar5 = iVar3;
        }
        *piVar8 = 0;
        *(int *)(iVar4 + -4) = *(int *)(iVar4 + -4) + -1;
        if (pcVar6 != (code *)0x0) {
          (*pcVar6)(uVar9,iVar4);
        }
      }
    }
  }
  return;
}



/* c054d3bc FUN_c054d3bc */

/* Boundary evidence: original MIPS .pdata c054d3bc..c054d463. Semantic name remains unreviewed. */

void FUN_c054d3bc(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  pcVar4 = *(code **)(*(int *)(param_1 + 8) + 0x5c);
  iVar1 = *(int *)(param_1 + 0x18c);
  while (iVar1 != 0) {
    if (*(uint *)(iVar1 + -4) < DAT_c05653bc) {
      iVar2 = (*(uint *)(iVar1 + -4) - DAT_c05653bc) * 0x28 + iVar1 + -8;
    }
    else {
      iVar2 = 0;
    }
    iVar3 = *(int *)(iVar2 + 8);
    *(undefined4 *)(iVar2 + 8) = 0;
    *(int *)(iVar1 + -4) = *(int *)(iVar1 + -4) + -1;
    (*pcVar4)(*(undefined4 *)(param_1 + 0xc));
    iVar1 = iVar3;
  }
  *(undefined4 *)(param_1 + 0x18c) = 0;
  return;
}



/* c054d464 FUN_c054d464 */

/* Boundary evidence: original MIPS .pdata c054d464..c054d51b. Semantic name remains unreviewed. */

void FUN_c054d464(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffeff;
  FUN_c054cb5c(param_1,0,(undefined4 *)0x0,(undefined4 *)0x0);
  puVar1 = *(undefined4 **)(param_1 + 500);
  *(undefined4 *)(param_1 + 500) = 0;
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    *puVar1 = 0;
    *(undefined4 **)(param_1 + 500) = puVar1;
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x400;
    if (puVar1[4] == 1) {
      FUN_c05577ec(param_1,-0x3ffefff4);
      puVar1 = puVar2;
    }
    else {
      FUN_c0556d30(param_1,-0x3ffefff4);
      puVar1 = puVar2;
    }
  }
  return;
}



/* c054d51c FUN_c054d51c */

/* Boundary evidence: original MIPS .pdata c054d51c..c054d773. Semantic name remains unreviewed. */

void FUN_c054d51c(int param_1,int ****param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int *****pppppiVar3;
  int *****pppppiVar4;
  int *****pppppiVar5;
  int *****pppppiVar6;
  int ****ppppiVar7;
  int *****pppppiVar8;
  int *****pppppiVar9;
  int ****local_30;
  int ****local_2c;
  
  FUN_c054cb5c(param_1,1,(undefined4 *)0x0,(undefined4 *)0x0);
  pppppiVar9 = *(int ******)(param_1 + 0x188);
  local_30 = (int ****)&local_30;
  bVar1 = param_3 != 0;
  pppppiVar8 = (int *****)0x0;
  pppppiVar5 = (int *****)(param_1 + 0x180);
  *(undefined4 *)(param_1 + 0x188) = 0;
  local_2c = (int ****)&local_30;
  do {
    while( true ) {
      pppppiVar3 = (int *****)*pppppiVar5;
      if (pppppiVar3 == pppppiVar5) {
        *(int ******)(param_1 + 0x188) = pppppiVar8;
        if (param_3 == 0) {
          *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x400000;
        }
        else {
          while (ppppiVar7 = local_30, (int *****)local_30 != &local_30) {
            (*local_30)[1] = (int **)&local_30;
            pppppiVar8 = (int *****)*local_30;
            *local_30 = (int ***)pppppiVar5;
            local_30 = (int ****)pppppiVar8;
            ppppiVar7[1] = (int ***)*(int *****)(param_1 + 0x184);
            **(undefined4 **)(param_1 + 0x184) = ppppiVar7;
            *(int *****)(param_1 + 0x184) = ppppiVar7;
          }
        }
        return;
      }
      pppppiVar6 = pppppiVar3 + -10;
      (*pppppiVar3)[1] = (int ***)pppppiVar5;
      *pppppiVar5 = *pppppiVar3;
      if (bVar1) break;
LAB_c054d5f8:
      if (pppppiVar3[-0xb] < DAT_c05653bc) {
        pppppiVar4 = pppppiVar6 + ((int)pppppiVar3[-0xb] - (int)DAT_c05653bc) * 10 + -2;
      }
      else {
        pppppiVar4 = (int *****)0x0;
      }
      ppppiVar7 = pppppiVar4[2];
      if ((param_3 == 0) ||
         ((ppppiVar7 == param_2 &&
          (param_3 == *(int *)((int)pppppiVar6 + *(ushort *)((int)pppppiVar3 + -10) + 0x40))))) {
        pppppiVar4[2] = (int ****)0x4d4f4337;
        pppppiVar3[-0xb] = (int ****)((int)pppppiVar3[-0xb] + -1);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        *(byte *)((int)pppppiVar3 + -0xb) = *(byte *)((int)pppppiVar3 + -0xb) & 0xc0;
        (*(code *)ppppiVar7[0x12])(ppppiVar7[4],pppppiVar6,0xc001000c);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        iVar2 = NdisInterlockedDecrement((LONG *)(ppppiVar7 + 0x20));
        if (iVar2 == 0) {
          FUN_c0559efc((int)ppppiVar7);
        }
      }
      else {
        if (pppppiVar8 == (int *****)0x0) {
          pppppiVar8 = pppppiVar6;
        }
        *pppppiVar3 = (int ****)&local_30;
        pppppiVar3[1] = local_2c;
        *local_2c = (int ***)pppppiVar3;
        local_2c = (int ****)pppppiVar3;
      }
    }
    if (pppppiVar6 == pppppiVar9) {
      bVar1 = false;
      goto LAB_c054d5f8;
    }
    *pppppiVar3 = (int ****)&local_30;
    pppppiVar3[1] = local_2c;
    *local_2c = (int ***)pppppiVar3;
    local_2c = (int ****)pppppiVar3;
  } while( true );
}



/* c054d774 FUN_c054d774 */

/* Boundary evidence: original MIPS .pdata c054d774..c054d86b. Semantic name remains unreviewed. */

void FUN_c054d774(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 == -0x7ffeffff) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfff7ffff;
  }
  else {
    FUN_c054d51c(param_1,(int ****)0x0,0);
    FUN_c054d464(param_1);
    uVar1 = *(uint *)(param_1 + 0x54);
    *(uint *)(param_1 + 0x54) = uVar1 & 0xfff7ffff;
    if (((uVar1 & 0x2000) == 0) && (*(char *)(param_1 + 0x255) == '\x01')) {
      if (param_2 == 0) {
        *(undefined1 *)(param_1 + 0x255) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x255) = 0xf;
      }
    }
    if (((param_3 != 0) && (param_2 == 0)) &&
       ((*(int *)(param_1 + 0xf8) != 0 || (*(int *)(param_1 + 0xfc) != 0)))) {
      FUN_c055701c(param_1,0,1);
    }
  }
  *(int *)(param_1 + 0x1bc) = param_2;
  return;
}



/* c054d86c FUN_c054d86c */

/* Boundary evidence: original MIPS .pdata c054d86c..c054d90f. Semantic name remains unreviewed. */

void FUN_c054d86c(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x11c) == 7)) {
    uVar2 = 0xc0000001;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x1e0);
  }
  for (; param_3 != 0; param_3 = param_3 + -1) {
    iVar1 = *param_2;
    *(byte *)(iVar1 + 0x1d) = *(byte *)(iVar1 + 0x1d) & 0xc0;
    (**(code **)(param_1 + 0x48))(*(undefined4 *)(param_1 + 0x10),iVar1,uVar2);
    param_2 = param_2 + 1;
  }
  return;
}



/* c054d934 NdisMSetAttributesEx */

/* Boundary evidence: original MIPS .pdata c054d934..c054db63. Semantic name remains unreviewed. */

void NdisMSetAttributesEx
               (int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  
                    /* 0xd934  150  NdisMSetAttributesEx */
  iVar2 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(uint *)(param_1 + 0x430) = param_4;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
    *(undefined4 *)(iVar2 + 0x1c) = param_2;
  }
  *(undefined4 *)(param_1 + 0x128) = param_5;
  if (param_3 != 0) {
    if (param_3 < 2) {
      param_3 = 2;
    }
    *(short *)(param_1 + 0x1b8) = (short)(param_3 >> 1);
  }
  if ((param_4 & 8) != 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 8;
    *(uint *)(param_1 + 0x45c) = *(uint *)(param_1 + 0x45c) | 1;
  }
  if ((param_4 & 1) != 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x800;
    *(uint *)(param_1 + 0x45c) = *(uint *)(param_1 + 0x45c) | 0x20;
  }
  if ((param_4 & 2) != 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x1000;
    *(uint *)(param_1 + 0x45c) = *(uint *)(param_1 + 0x45c) | 0x40;
  }
  if ((param_4 & 4) != 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x2000;
    *(uint *)(param_1 + 0x45c) = *(uint *)(param_1 + 0x45c) | 0x80;
  }
  if ((param_4 & 0x10) != 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x8000;
    *(uint *)(param_1 + 0x45c) = *(uint *)(param_1 + 0x45c) | 0x100;
  }
  if ((param_4 & 0x40) != 0) {
    *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0x8000;
    *(uint *)(param_1 + 0x45c) = *(uint *)(param_1 + 0x45c) | 0x200000;
  }
  if ((param_4 & 0x20) == 0) {
    NdisInitializeTimer((int *)(param_1 + 0xb8),FUN_c05551a0,param_1);
  }
  else {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x40000;
    *(uint *)(param_1 + 0x45c) = *(uint *)(param_1 + 0x45c) | 0x800;
    NdisInitializeTimer((int *)(param_1 + 0xb8),FUN_c0554ff0,param_1);
    *(code **)(param_1 + 0x10c) = FUN_c0552d48;
  }
  if ((param_4 & 0x400) != 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x80;
  }
  bVar1 = *(byte *)(*(int *)(param_1 + 8) + 0x20);
  if ((5 < bVar1) ||
     (((bVar1 == 5 && (*(char *)(*(int *)(param_1 + 8) + 0x21) != '\0')) || ((param_4 & 0x200) != 0)
      ))) {
    *(byte *)(param_1 + 0x254) = *(byte *)(param_1 + 0x254) | 2;
    *(uint *)(param_1 + 0x45c) = *(uint *)(param_1 + 0x45c) | 0x20000;
  }
  if ((param_4 & 0x80) != 0) {
    *(uint *)(param_1 + 0x45c) = *(uint *)(param_1 + 0x45c) | 0x100000;
  }
  return;
}



/* c054db64 NdisMSetMiniportSecondary */

/* Boundary evidence: original MIPS .pdata c054db64..c054dbe3. Semantic name remains unreviewed. */

undefined4 NdisMSetMiniportSecondary(int param_1,int param_2)

{
  undefined4 uVar1;
  
                    /* 0xdb64  152  NdisMSetMiniportSecondary */
  uVar1 = 0;
  if ((*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) && (*(int *)(param_1 + 0x198) == param_1)) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x10000000;
    FUN_c0559364(param_1,0);
    *(int *)(param_1 + 0x198) = param_2;
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



/* c054dbe4 FUN_c054dbe4 */

/* Boundary evidence: original MIPS .pdata c054dbe4..c054dce7. Semantic name remains unreviewed. */

void FUN_c054dbe4(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  uVar2 = *(uint *)(param_2 + 0x248);
  if ((((uVar2 & 0x20000) == 0) && ((*(uint *)(param_2 + 0x54) & 0x10000000) == 0)) &&
     ((iVar1 = *(int *)(param_2 + 0x354), iVar1 == 1 || ((iVar1 == 2 || (iVar1 == 4)))))) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c0551fd4(param_2,(int *)0x0,0);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    uVar2 = *(uint *)(param_2 + 0x248);
  }
  *(uint *)(param_2 + 0x248) = uVar2 & 0xfbffffff;
  if (*(undefined4 **)(param_2 + 0x478) != (undefined4 *)0x0) {
    EventModify(**(undefined4 **)(param_2 + 0x478),3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  FUN_c0559738(param_2);
  CTEFreeMem(param_1);
  return;
}



/* c054dce8 FUN_c054dce8 */

/* Boundary evidence: original MIPS .pdata c054dce8..c054dd73. Semantic name remains unreviewed. */

bool FUN_c054dce8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = 0;
  if (iVar2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    for (iVar1 = *(int *)(iVar2 + 4); (iVar1 != 0 && (iVar1 != param_1));
        iVar1 = *(int *)(iVar1 + 0x1c)) {
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return iVar1 == param_1;
}



/* c054dd74 FUN_c054dd74 */

/* Boundary evidence: original MIPS .pdata c054dd74..c054dddf. Semantic name remains unreviewed. */

undefined4 FUN_c054dd74(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x354);
  uVar2 = 1;
  if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 4)) {
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x18);
    *(int *)(param_1 + 0x18) = param_2;
    *(short *)(param_1 + 0x438) = *(short *)(param_1 + 0x438) + 1;
    FUN_c055691c(param_1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c054dde0 FUN_c054dde0 */

/* Boundary evidence: original MIPS .pdata c054dde0..c054df17. Semantic name remains unreviewed. */

void FUN_c054dde0(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar1 = *(int *)(param_1 + 0x11c);
  if (iVar1 == 0) {
    *(code **)(param_1 + 0x47c) = FUN_c0543870;
    if ((((DAT_c05653f8 != 0) && ((*(uint *)(param_1 + 0x54) & 0x40000) != 0)) &&
        (*(int *)(param_1 + 0xf8) != 0)) &&
       (((iVar1 = *(int *)(*(int *)(param_1 + 0xf8) + 0x2c), iVar1 != 0 &&
         (*(int *)(*(int *)(iVar1 + 4) + 0x60) != 0)) && ((*(uint *)(param_1 + 0x54) & 0x80) != 0)))
       ) {
      *(code **)(param_1 + 0x47c) = FUN_c0543fd8;
    }
    if (DAT_c05653f4 == 0) goto LAB_c054ded0;
    pcVar2 = FUN_c0543f68;
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 != 3) {
        *(code **)(param_1 + 0x47c) = FUN_c055bd70;
      }
      goto LAB_c054ded0;
    }
    pcVar2 = FUN_c055af14;
  }
  *(code **)(param_1 + 0x47c) = pcVar2;
LAB_c054ded0:
  if ((*(uint *)(param_1 + 0x54) & 0x20000000) == 0) {
    *(code **)(param_1 + 0x108) = FUN_c055b714;
  }
  else {
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x47c);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c054df18 FUN_c054df18 */

/* Boundary evidence: original MIPS .pdata c054df18..c054dfe7. Semantic name remains unreviewed. */

undefined4 FUN_c054df18(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar1 = DAT_c056540c;
  do {
    if (iVar1 == 0) {
LAB_c054dfc0:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      return uVar2;
    }
    if (iVar1 == param_1) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      if (param_2 == 0) {
LAB_c054dfb4:
        uVar2 = 1;
      }
      else if (((*(uint *)(param_1 + 0x7c) & 0x8000) == 0) && (*(LONG *)(param_1 + 0x80) != 0)) {
        NdisInterlockedIncrement((LONG *)(param_1 + 0x80));
        goto LAB_c054dfb4;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      goto LAB_c054dfc0;
    }
    iVar1 = *(int *)(iVar1 + 0xd8);
  } while( true );
}



/* c054dfe8 FUN_c054dfe8 */

/* Boundary evidence: original MIPS .pdata c054dfe8..c054e073. Semantic name remains unreviewed. */

undefined4 FUN_c054dfe8(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  piVar1 = &DAT_c056540c;
  do {
    if (*piVar1 == 0) {
LAB_c054e050:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      return uVar2;
    }
    if (*piVar1 == param_1) {
      uVar2 = 1;
      *piVar1 = *(int *)(param_1 + 0xd8);
      goto LAB_c054e050;
    }
    piVar1 = (int *)(*piVar1 + 0xd8);
  } while( true );
}



/* c054e074 FUN_c054e074 */

void FUN_c054e074(int param_1,int param_2)

{
  bool bVar1;
  undefined **ppuVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x80);
  bVar1 = true;
  if (((DAT_c05653ec != 0) || ((*(uint *)(param_2 + 0xdc) & 0x40000000) != 0)) ||
     (((*(uint *)(param_1 + 0x1f0) & 8) == 0 &&
      (((*(uint *)(param_1 + 0x54) & 0x4000) == 0 && ((*(uint *)(param_1 + 0x54) & 0x800000) == 0)))
      ))) {
    bVar1 = false;
  }
  if ((*(uint *)(param_1 + 0x54) & 0x40000) == 0) {
    ppuVar2 = &PTR_FUN_c0565280 + (uint)(DAT_c05653f4 == 0) * 5;
  }
  else if (DAT_c05653f4 == 0) {
    ppuVar2 = &PTR_FUN_c05652bc;
    if ((!bVar1) && (*(int *)(param_1 + 0x42c) != 0)) {
      ppuVar2 = &PTR_FUN_c05652d0;
    }
  }
  else {
    ppuVar2 = &PTR_FUN_c05652a8;
  }
  puVar3 = ppuVar2[4];
  if ((*(byte *)(param_1 + 599) & 7) != 0) {
    if ((*(byte *)(param_1 + 599) & 2) != 2) {
      puVar3 = &LAB_c054d910;
    }
    ppuVar2 = &PTR_LAB_c05652e4;
    uVar4 = 0;
  }
  *(undefined **)(param_2 + 0x40) = *ppuVar2;
  if ((*(int *)(param_1 + 0x11c) == 3) && ((*(uint *)(param_1 + 0x54) & 0x30000) == 0)) {
    *(undefined **)(param_2 + 0x40) = ppuVar2[1];
  }
  *(undefined **)(param_2 + 100) = ppuVar2[2];
  *(undefined4 *)(param_2 + 0xb4) = uVar4;
  *(undefined **)(param_2 + 0x68) = ppuVar2[3];
  *(undefined1 **)(param_2 + 0x6c) = puVar3;
  return;
}



/* c054e1e4 FUN_c054e1e4 */

/* Boundary evidence: original MIPS .pdata c054e1e4..c054e23b. Semantic name remains unreviewed. */

void FUN_c054e1e4(int param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  *(byte *)(param_1 + 599) = ~param_2 & *(byte *)(param_1 + 599);
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    FUN_c054e074(param_1,iVar1);
  }
  return;
}



/* c054e23c FUN_c054e23c */

/* Boundary evidence: original MIPS .pdata c054e23c..c054e293. Semantic name remains unreviewed. */

void FUN_c054e23c(int param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  *(byte *)(param_1 + 599) = param_3 | *(byte *)(param_1 + 599);
  *(undefined4 *)(param_1 + 0x1e0) = param_2;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    FUN_c054e074(param_1,iVar1);
  }
  return;
}



/* c054e294 NdisMSetAttributes */

/* Boundary evidence: original MIPS .pdata c054e294..c054e2c3. Semantic name remains unreviewed. */

void NdisMSetAttributes(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  
                    /* 0xe294  149  NdisMSetAttributes */
  uVar1 = 8;
  if (param_3 == 0) {
    uVar1 = 0;
  }
  NdisMSetAttributesEx(param_1,param_2,0,uVar1,param_4);
  return;
}



/* c054e2c4 NdisMPromoteMiniport */

/* Boundary evidence: original MIPS .pdata c054e2c4..c054e423. Semantic name remains unreviewed. */

undefined4 NdisMPromoteMiniport(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
                    /* 0xe2c4  135  NdisMPromoteMiniport */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((((*(uint *)(param_1 + 0x54) & 0x10000000) == 0) || (*(int *)(param_1 + 0x198) == param_1)) ||
     ((*(uint *)(param_1 + 0x248) & 0x20000) != 0)) {
    uVar3 = 0xc00000bb;
  }
  else {
    piVar1 = FUN_c05427a0(0x28);
    if (piVar1 != (int *)0x0) {
      iVar4 = *(int *)(param_1 + 0x198);
      piVar1[1] = (int)FUN_c054dbe4;
      *piVar1 = param_1;
      *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xefffffff;
      *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0x4000000;
      FUN_c055a404(param_1 + 0x20);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      iVar2 = *(int *)(param_1 + 8);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      for (iVar2 = *(int *)(iVar2 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
        if (*(int *)(iVar2 + 0x198) == iVar4) {
          *(int *)(iVar2 + 0x198) = param_1;
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      NdisScheduleWorkItem((int)piVar1);
      return 0;
    }
    uVar3 = 0xc000009a;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return uVar3;
}



/* c054e424 NdisMIndicateStatus */

/* Boundary evidence: original MIPS .pdata c054e424..c054e873. Semantic name remains unreviewed. */

void NdisMIndicateStatus(int param_1,int param_2,uint *param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined1 auStack_37 [3];
  int local_34;
  uint *local_30;
  int local_2c;
  
                    /* 0xe424  129  NdisMIndicateStatus */
  bVar3 = false;
  bVar1 = false;
  if (((param_2 == 0x4001000b) || (param_2 == 0x4001000c)) &&
     ((param_4 != -2 || (bVar3 = true, param_3 != (uint *)0xffffffff)))) {
    bVar3 = false;
  }
  local_34 = param_4;
  local_30 = param_3;
  local_2c = param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (param_2 == 0x40010006) {
    if (param_4 == 4) {
      if ((*param_3 & 0xc800) == 0) {
        *(undefined1 *)(param_1 + 0x255) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x255) = 0xf;
      }
    }
  }
  else if (param_2 == 0x4001000b) {
    uVar8 = *(uint *)(param_1 + 0x54);
    bVar1 = (uVar8 & 0x20000000) == 0;
    *(short *)(param_1 + 0x414) = *(short *)(param_1 + 0x414) + 1;
    *(uint *)(param_1 + 0x54) = uVar8 | 0x20000000;
    if (!bVar3) {
      *(uint *)(param_1 + 0x54) = uVar8 & 0xfdffffff | 0x24000000;
      if ((*(uint *)(param_1 + 0x248) & 8) != 0) {
        *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) & 0xfffffff7 | 0x200;
        NdisCancelTimer((int *)(param_1 + 0x30c),auStack_37);
      }
    }
  }
  else if (param_2 == 0x4001000c) {
    uVar8 = *(uint *)(param_1 + 0x54);
    bVar1 = (uVar8 & 0x20000000) != 0;
    *(short *)(param_1 + 0x416) = *(short *)(param_1 + 0x416) + 1;
    *(uint *)(param_1 + 0x54) = uVar8 & 0xdfffffff;
    if (((((!bVar3) && (*(uint *)(param_1 + 0x54) = uVar8 & 0xddffffff | 0x4000000, bVar1)) &&
         (uVar8 = *(uint *)(param_1 + 0x248), (uVar8 & 0x20) != 0)) &&
        (((*(uint *)(param_1 + 0x2c0) & 4) != 0 && (*(ushort *)(param_1 + 0x34c) != 0xffff)))) &&
       ((uVar8 & 8) == 0)) {
      *(uint *)(param_1 + 0x248) = uVar8 & 0xfffffdff | 8;
      NdisSetTimer((int *)(param_1 + 0x30c),(uint)*(ushort *)(param_1 + 0x34c) * 1000);
    }
  }
  puVar6 = local_30;
  iVar5 = local_34;
  uVar8 = *(uint *)(param_1 + 0x490);
  if (param_2 == 0x4001000c) {
    *(undefined4 *)(param_1 + 0x494) = 1;
  }
  iVar9 = *(int *)(param_1 + 0x18);
  do {
    while( true ) {
      iVar4 = iVar9;
      if (iVar4 == 0) {
        if (bVar1) {
          if (param_2 == 0x4001000b) {
            *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) & 0xefffffff;
            FUN_c054e1e4(param_1,2);
            *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x47c);
          }
          else {
            *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0x10000000;
            FUN_c054e23c(param_1,0xc001001f,2);
            *(undefined4 *)(param_1 + 0x47c) = *(undefined4 *)(param_1 + 0x108);
            *(code **)(param_1 + 0x108) = FUN_c055b714;
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        return;
      }
      if ((*(uint *)(iVar4 + 0x7c) & 0x8000) == 0) break;
      iVar9 = *(int *)(iVar4 + 0x14);
      param_1 = local_2c;
    }
    NdisInterlockedIncrement((LONG *)(iVar4 + 0x80));
    if (*(int *)(iVar4 + 0x74) != 0) {
      *(uint *)(iVar4 + 0x7c) = *(uint *)(iVar4 + 0x7c) | 0x100;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      if ((param_2 == 0x4001000b) && ((uVar8 & 0x80000000) != 0)) {
        bVar2 = (*(uint *)(iVar4 + 0xdc) & 0x80000000) == 0;
        if (bVar3) {
          if (!bVar2) {
            if (bVar3) goto LAB_c054e794;
            goto LAB_c054e74c;
          }
        }
        else {
LAB_c054e74c:
          if (bVar2) goto LAB_c054e794;
        }
        (**(code **)(iVar4 + 0x74))(*(undefined4 *)(iVar4 + 0x10),0x4001000b,puVar6,iVar5);
      }
      else {
        (**(code **)(iVar4 + 0x74))(*(undefined4 *)(iVar4 + 0x10),param_2,puVar6,iVar5);
      }
LAB_c054e794:
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    iVar9 = *(int *)(iVar4 + 0x14);
    iVar7 = NdisInterlockedDecrement((LONG *)(iVar4 + 0x80));
    param_1 = local_2c;
    if (iVar7 == 0) {
      FUN_c0559efc(iVar4);
      param_1 = local_2c;
    }
  } while( true );
}



/* c054e874 FUN_c054e874 */

/* Boundary evidence: original MIPS .pdata c054e874..c054e973. Semantic name remains unreviewed. */

undefined4 FUN_c054e874(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_c054cb5c(param_1,3,(undefined4 *)0x0,(undefined4 *)0x0);
  if ((*(uint *)(param_1 + 0x248) & 0x80000) == 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xffefffff | 0x200000;
    FUN_c054e23c(param_1,0xc001000d,1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    NdisMIndicateStatus(param_1,0x40010004,(uint *)0x0,0);
    NdisMIndicateStatusComplete(param_1);
    uVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(param_2,*(undefined4 *)(param_1 + 0xc));
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  else {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xffefffff;
    uVar1 = 0x80010001;
  }
  return uVar1;
}



/* c054e974 FUN_c054e974 */

/* Boundary evidence: original MIPS .pdata c054e974..c054eadf. Semantic name remains unreviewed. */

void FUN_c054e974(int param_1)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  local_20[0] = 0;
  if ((*(uint *)(param_1 + 0x54) & 0x40000) == 0) {
    FUN_c054cb5c(param_1,4,local_20,(undefined4 *)0x0);
    iVar2 = local_20[0];
  }
  else {
    iVar2 = *(int *)(param_1 + 0x1c0);
    *(undefined4 *)(param_1 + 0x1c0) = 0;
  }
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xffdfffff;
  FUN_c054e1e4(param_1,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  NdisMIndicateStatus(param_1,0x40010005,(uint *)(param_1 + 0x1bc),4);
  NdisMIndicateStatusComplete(param_1);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (iVar2 == 0) {
    if (((*(uint *)(param_1 + 0x490) & 1) != 0) &&
       (*(uint *)(param_1 + 0x490) = *(uint *)(param_1 + 0x490) & 0xfffffffe,
       *(int *)(param_1 + 0x484) != 0)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      NdisMRebindProtocolsToAdapter(param_1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    (**(code **)(iVar2 + 0x70))(*(undefined4 *)(iVar2 + 0x10),*(uint *)(param_1 + 0x1bc));
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = NdisInterlockedDecrement((LONG *)(iVar2 + 0x80));
    if (iVar1 == 0) {
      FUN_c0559efc(iVar2);
    }
  }
  if (*(undefined4 **)(param_1 + 0x474) != (undefined4 *)0x0) {
    EventModify(**(undefined4 **)(param_1 + 0x474),3);
  }
  return;
}



/* c054eae0 FUN_c054eae0 */

/* Boundary evidence: original MIPS .pdata c054eae0..c054ecff. Semantic name remains unreviewed. */

void FUN_c054eae0(int param_1)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  byte local_28 [4];
  code *local_24;
  undefined4 local_20 [2];
  
  local_28[0] = 0;
  do {
    bVar1 = false;
    if ((*(int *)(param_1 + 0x70) != 0) && ((*(uint *)(param_1 + 0x54) & 0x80300000) == 0)) {
      FUN_c054cb5c(param_1,1,(undefined4 *)0x0,(undefined4 *)0x0);
      (**(code **)(param_1 + 0x17c))(param_1);
      bVar1 = true;
    }
    if (*(int *)(param_1 + 0x7c) != 0) {
      if (*(int *)(param_1 + 0x6c) == 0) {
        return;
      }
      FUN_c054cb5c(param_1,0,(undefined4 *)0x0,(undefined4 *)0x0);
      FUN_c05584e8(param_1);
      return;
    }
    if (*(int *)(param_1 + 0x74) != 0) {
      FUN_c054cb5c(param_1,2,(undefined4 *)0x0,(undefined4 *)0x0);
      FUN_c054d3bc(param_1);
    }
    if ((*(uint *)(param_1 + 0x54) & 0x80000000) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x84) != 0) {
      local_24 = (code *)0x0;
      FUN_c054cb5c(param_1,6,local_20,&local_24);
      pcVar2 = local_24;
      if (local_24 != (code *)0x0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        (*pcVar2)(*(undefined4 *)(param_1 + 0xc),local_20[0]);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      }
      bVar1 = true;
    }
    if (*(int *)(param_1 + 0x78) == 0) {
LAB_c054ec50:
      if (*(int *)(param_1 + 0x6c) != 0) {
        FUN_c054cb5c(param_1,0,(undefined4 *)0x0,(undefined4 *)0x0);
        FUN_c05584e8(param_1);
        bVar1 = true;
      }
      if (*(int *)(param_1 + 0x70) != 0) {
        FUN_c054cb5c(param_1,1,(undefined4 *)0x0,(undefined4 *)0x0);
        (**(code **)(param_1 + 0x17c))(param_1);
        goto LAB_c054eca8;
      }
    }
    else {
      iVar3 = FUN_c054e874(param_1,local_28);
      if (iVar3 == 0x103) {
        return;
      }
      FUN_c054d774(param_1,iVar3,(uint)local_28[0]);
      if (*(int *)(param_1 + 0x6c) == 0) {
        local_28[0] = 0;
      }
      if ((local_28[0] == 0) || (iVar3 != 0)) {
        FUN_c054e974(param_1);
        goto LAB_c054ec50;
      }
LAB_c054eca8:
      bVar1 = true;
    }
    if (!bVar1) {
      return;
    }
  } while( true );
}



/* c054ed00 NdisMResetComplete */

/* Boundary evidence: original MIPS .pdata c054ed00..c054edbf. Semantic name remains unreviewed. */

void NdisMResetComplete(int param_1,int param_2,int param_3)

{
                    /* 0xed00  146  NdisMResetComplete */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((*(uint *)(param_1 + 0x54) & 0x200000) == 0) {
    DbgPrint(" ***NDIS*** : Miniport %Z - %s\n",*(undefined4 *)(param_1 + 0x1e8),
             "Completing reset when one is not pending",*(uint *)(param_1 + 0x54));
    trap(0x400);
  }
  FUN_c054d774(param_1,param_2,param_3);
  if (*(int *)(param_1 + 0x6c) == 0) {
    param_3 = 0;
  }
  if ((param_3 == 0) || (param_2 != 0)) {
    FUN_c054e974(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c054edc0 FUN_c054edc0 */

/* Boundary evidence: original MIPS .pdata c054edc0..c054fd1b. Semantic name remains unreviewed. */

int FUN_c054edc0(int *param_1,int *param_2,int param_3,uint *param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  void *_Dst;
  HANDLE pvVar5;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  char *pcVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  uint uVar14;
  char *pcVar15;
  undefined4 *_Dst_00;
  LPBYTE pBVar16;
  int iVar17;
  int iVar18;
  char cVar19;
  char *pcVar20;
  uint local_37c;
  char *local_378;
  char *local_374;
  char local_370;
  uint local_36c;
  uint local_368;
  uint local_364;
  int local_360;
  int local_35c [3];
  char *local_350;
  int local_34c;
  undefined1 auStack_348 [8];
  undefined2 auStack_340 [4];
  uint auStack_338 [2];
  wchar_t awStack_330 [128];
  wchar_t awStack_230 [256];
  uint local_30;
  
  local_30 = DAT_c05653c8;
  local_360 = 0;
  puVar7 = param_4;
  memset(local_35c,0,0xc);
  iVar18 = 1;
  bVar3 = false;
  local_37c = 0;
  local_370 = '\0';
  bVar2 = false;
  iVar17 = 0;
  bVar1 = false;
  bVar4 = FUN_c055a404((int)(param_1 + 0x28));
  local_374 = "Unloading without deregistering timer";
  pcVar20 = " ***NDIS*** : Miniport %Z - %s\n";
  local_350 = " ***NDIS*** : Miniport %Z - %s\n";
  local_378 = "Unloading without deregistering interrupt";
  pcVar15 = local_374;
  pcVar6 = local_378;
  cVar19 = '\0';
  if (CONCAT31(extraout_var,bVar4) == 0) goto LAB_c054fc5c;
  bVar3 = true;
  iVar9 = *(int *)(param_2[2] + 0x14);
  iVar17 = iVar9 + 0x28;
  uVar10 = *(uint *)(iVar9 + 0x7c);
  *(code **)(iVar9 + 0x130) = FUN_c055b714;
  *(code **)(iVar9 + 0x4a4) = FUN_c055b714;
  *(uint **)(iVar9 + 0x2c) = param_4;
  *(undefined1 *)(iVar9 + 0x274) = 0;
  *(uint *)(iVar9 + 0x7c) = uVar10 | 0x400000;
  *(code **)(iVar9 + 0x230) = EthFilterDprIndicateReceive;
  if (DAT_c05653f4 != 0) {
    *(code **)(iVar9 + 0x230) = FUN_c0543e98;
  }
  *(code **)(iVar9 + 0x23c) = EthFilterDprIndicateReceiveComplete;
  *(code **)(iVar9 + 0x234) = TrFilterDprIndicateReceive;
  *(code **)(iVar9 + 0x240) = TrFilterDprIndicateReceiveComplete;
  *(code **)(iVar9 + 0x250) = NdisMTransferDataComplete;
  *(code **)(iVar9 + 0x134) = NdisMSendComplete;
  *(code **)(iVar9 + 0x13c) = NdisMResetComplete;
  *(code **)(iVar9 + 0x24c) = NdisMIndicateStatusComplete;
  *(code **)(iVar9 + 0x248) = NdisMIndicateStatus;
  *(code **)(iVar9 + 0x138) = NdisMSendResourcesAvailable;
  *(code **)(iVar9 + 600) = NdisMSetInformationComplete;
  *(code **)(iVar9 + 0x254) = NdisMQueryInformationComplete;
  *(code **)(iVar9 + 0x25c) = NdisMWanSendComplete;
  iVar11 = *(int *)(iVar9 + 0x30);
  *(code **)(iVar9 + 0x264) = NdisMWanIndicateReceiveComplete;
  *(code **)(iVar9 + 0x260) = NdisMWanIndicateReceive;
  *(undefined4 *)(iVar9 + 0x194) = *(undefined4 *)(iVar11 + 0x38);
  iVar8 = iVar9 + 0x314;
  *(undefined4 *)(iVar9 + 0x198) = *(undefined4 *)(iVar11 + 0x2c);
  uVar12 = *(undefined4 *)(iVar11 + 0x30);
  *(int *)(iVar9 + 0x318) = iVar8;
  *(int *)iVar8 = iVar8;
  *(undefined4 *)(iVar9 + 0x19c) = uVar12;
  *(code **)(iVar9 + 0x1a4) = FUN_c05546d4;
  if (3 < *(byte *)(param_1 + 8)) {
    if (param_1[0x17] != 0) {
      *(uint *)(iVar9 + 0x484) = *(uint *)(iVar9 + 0x484) | 0x10;
    }
    if (param_1[0x18] != 0) {
      *(byte *)(iVar9 + 0x27c) = *(byte *)(iVar9 + 0x27c) | 1;
      *(code **)(iVar9 + 0x1a4) = FUN_c0554378;
      *(int *)(iVar9 + 0x454) = param_1[0x18];
    }
    if ((char)param_1[8] == '\x05') {
      *(uint *)(iVar9 + 0x7c) = uVar10 | 0x410000;
      *(uint *)(iVar9 + 0x484) = *(uint *)(iVar9 + 0x484) | 0x200;
    }
  }
  FUN_c055a404(iVar9 + 0x48);
  StringCchPrintfW(awStack_330,0x80,L"%s\\%s\\Parms",L"\\Comm",*(undefined4 *)(param_3 + 4));
  *(undefined4 *)(iVar9 + 0x4ac) = DAT_c0565594;
  FUN_c0560594((HKEY)0x80000002,awStack_330,L"RebindOnResume",(LPBYTE)(iVar9 + 0x4ac));
  FUN_c054c69c(iVar17,awStack_330);
  *(uint *)(iVar9 + 0x4b0) = (uint)(*(int *)(iVar9 + 0x14c) != -2);
  FUN_c0560594((HKEY)0x80000002,awStack_330,L"ResetOnResume",(LPBYTE)(iVar9 + 0x4b0));
  if (*(int *)(iVar9 + 0x14c) == -2) {
    StringCchPrintfW(awStack_230,0x100,L"%s\\%s\\Parms",L"\\Comm",*(undefined4 *)(iVar9 + 0x3c));
    FUN_c055f4e4(auStack_340,awStack_230);
    FUN_c055e7b0(*(undefined4 *)(iVar9 + 0x148),(int)auStack_340);
  }
  puVar7 = &local_368;
  local_368 = 0;
  FUN_c0560594((HKEY)0x80000002,awStack_330,L"DisablePowerManagement",(LPBYTE)puVar7);
  if (local_368 == 0) {
    *(uint *)(iVar9 + 0x4b8) = *(uint *)(iVar9 + 0x4b8) & 0xfffffffb;
  }
  else {
    *(uint *)(iVar9 + 0x4b8) = *(uint *)(iVar9 + 0x4b8) | 4;
  }
  *(undefined2 *)(iVar9 + 0x1e0) = 1;
  uVar10 = 0;
  do {
    _Dst_00 = (undefined4 *)(uVar10 * 0xc + iVar17 + 0x3bc);
    memset(_Dst_00,0,0xc);
    puVar13 = (undefined4 *)((uVar10 + 0x55) * 4 + iVar17);
    *_Dst_00 = *puVar13;
    *puVar13 = _Dst_00;
    uVar10 = uVar10 + 1 & 0xff;
  } while (uVar10 < 6);
  bVar4 = FUN_c0559058(iVar17,(int)param_1);
  pcVar20 = local_350;
  pcVar15 = local_374;
  pcVar6 = local_378;
  cVar19 = local_370;
  if (CONCAT31(extraout_var_00,bVar4) == 0) goto LAB_c054fc5c;
  cVar19 = '\x01';
  FUN_c0561494(iVar9 + 0x38c,FUN_c05559e4,iVar17);
  *(code **)(iVar9 + 0x20c) = FUN_c055b83c;
  if (*(int *)(iVar9 + 0x2ec) == 0) {
    *(undefined4 *)(iVar9 + 0x2ec) = 1;
  }
  FUN_c055c0c4(iVar17);
  *(uint *)(iVar9 + 0x7c) = *(uint *)(iVar9 + 0x7c) & 0xfffffffe | 2;
  if ((*(ushort *)(param_1 + 0x2e) & 2) != 0) {
    *(uint *)(iVar9 + 0x270) = *(uint *)(iVar9 + 0x270) | 0x100000;
  }
  *param_2 = iVar17;
  *(undefined4 *)(iVar9 + 0x218) = 0;
  puVar7 = (uint *)(DAT_c05653b4 >> 2);
  iVar18 = (*(code *)param_1[0xf])(auStack_348,&local_34c,PTR_DAT_c05653b0,puVar7,iVar17,param_2);
  uVar10 = *(uint *)(iVar9 + 0x7c);
  uVar14 = uVar10 & 0xfffffffd;
  *(uint *)(iVar9 + 0x7c) = uVar14;
  if (iVar18 != 0) {
    if (*(int *)(iVar9 + 0x14c) == -2) {
      FUN_c055e6e0(iVar17);
    }
    NdisMDeregisterAdapterShutdownHandler(iVar17);
    pcVar15 = local_374;
    pcVar6 = local_378;
    DAT_c0565444 = iVar18;
    if ((*(int *)(iVar9 + 0x214) != 0) || (*(int *)(iVar9 + 0x78) != 0)) {
      if (*(int *)(iVar9 + 0x78) == 0) {
        DbgPrint(pcVar20,*(undefined4 *)(iVar9 + 0x210),local_374,puVar7);
        pcVar6 = local_378;
      }
      else {
        DbgPrint(pcVar20,*(undefined4 *)(iVar9 + 0x210),local_378,puVar7);
        pcVar15 = local_374;
      }
      trap(0x400);
    }
    goto LAB_c054fc5c;
  }
  iVar18 = *(int *)(iVar9 + 0x78);
  bVar2 = true;
  if (((iVar18 == 0) || (*(char *)(iVar18 + 0x4a) != '\0')) || (*(char *)(iVar18 + 0x49) != '\0')) {
    *(uint *)(iVar9 + 0x7c) = uVar10 & 0xfffffffc;
  }
  else {
    *(uint *)(iVar9 + 0x7c) = uVar14 | 1;
  }
  if (param_1[0x22] != 0) {
    NdisMRegisterAdapterShutdownHandler(iVar17,*(undefined4 *)(iVar9 + 0x34),param_1[0x22]);
  }
  iVar18 = *(int *)(PTR_DAT_c05653b0 + local_34c * 4);
  *(int *)(iVar9 + 0x144) = iVar18;
  if (iVar18 != 1) {
    *(uint *)(iVar9 + 0x7c) = *(uint *)(iVar9 + 0x7c) | 0x2000;
  }
  if ((*(int *)(iVar9 + 0x144) == 3) && ((*(uint *)(iVar9 + 0x7c) & 0x30000) == 0)) {
    *(code **)(iVar9 + 0x1a4) = FUN_c055339c;
  }
  if (param_1[0x34] == 0) {
    FUN_c0556230(iVar17,1,0x10116,param_1 + 0x34,4,0,'\x01');
  }
  iVar18 = *(int *)(iVar9 + 0x144);
  if (((-1 < iVar18) && (iVar18 < 0x11)) && ((iVar18 != 3 && ((&DAT_c0565348)[iVar18] != '\0')))) {
    puVar7 = &local_37c;
    iVar18 = FUN_c0556230(iVar17,1,0x10105,puVar7,4,1,'\x01');
    pcVar15 = local_374;
    pcVar6 = local_378;
    if (iVar18 != 0) goto LAB_c054fc5c;
  }
  iVar18 = *(int *)(iVar9 + 0x144);
  uVar10 = local_37c;
  if (iVar18 == 0) {
    if (0x200 < local_37c) {
      uVar10 = 0x200;
    }
LAB_c054f4fc:
    *(uint *)(iVar9 + 0x22c) = uVar10;
  }
  else {
    if (iVar18 == 1) {
      if (0x1ee < local_37c) {
        uVar10 = 0x1ee;
      }
      goto LAB_c054f4fc;
    }
    if (iVar18 == 3) {
      *(undefined4 *)(iVar9 + 0x22c) = 0x200;
    }
    else if ((iVar18 == 4) || ((8 < iVar18 && ((iVar18 < 0xb || (iVar18 == 0x10)))))) {
      *(uint *)(iVar9 + 0x22c) = local_37c;
    }
  }
  iVar18 = *(int *)(iVar9 + 0x144);
  if ((((-1 < iVar18) && (iVar18 < 0x11)) && ((&DAT_c0565348)[iVar18] != '\0')) || (iVar18 == 3)) {
    puVar7 = &local_37c;
    iVar18 = FUN_c0556230(iVar17,1,0x10113,puVar7,4,3,'\x01');
    pcVar15 = local_374;
    pcVar6 = local_378;
    if (iVar18 != 0) goto LAB_c054fc5c;
    uVar10 = *(uint *)(iVar9 + 0x218) | local_37c;
    *(uint *)(iVar9 + 0x218) = uVar10;
    if ((uVar10 & 8) != 0) {
      *(uint *)(iVar9 + 0x7c) = *(uint *)(iVar9 + 0x7c) | 0x8000000;
    }
    if ((*(uint *)(iVar9 + 0x218) & 0x80000001) == 0x80000001) {
      *(undefined4 *)(iVar9 + 0x22c) = 0x200;
    }
  }
  uVar10 = *(uint *)(iVar9 + 0x7c);
  *(uint *)(iVar9 + 0x7c) = uVar10 | 0x20000000;
  if ((((uVar10 & 0x2000000) == 0) || (*(int *)(iVar9 + 0x144) == 3)) ||
     (((&DAT_c0565348)[*(int *)(iVar9 + 0x144)] == '\0' ||
      (((*(uint *)(iVar9 + 0x218) & 0x80000001) == 0x80000001 || (param_1[3] != 0)))))) {
LAB_c054f724:
    *(int *)(iVar9 + 0x1dc) = (uint)*(ushort *)(iVar9 + 0x1e0) << 1;
    *(undefined2 *)(iVar9 + 0x1e0) = 1;
    FUN_c0560594((HKEY)0x80000002,awStack_330,L"CheckForHangTimeInSeconds",(LPBYTE)(iVar9 + 0x1dc));
    *(uint *)(iVar9 + 0x7c) = *(uint *)(iVar9 + 0x7c) & 0xfdffffff;
  }
  else {
    puVar7 = &local_37c;
    iVar18 = FUN_c0556230(iVar17,1,0x10114,puVar7,4,0,'\x01');
    if (iVar18 != 0) goto LAB_c054f724;
    if (local_37c == 0) {
      *(uint *)(iVar9 + 0x7c) = *(uint *)(iVar9 + 0x7c) | 0x20000000;
    }
    else {
      *(uint *)(iVar9 + 0x7c) = *(uint *)(iVar9 + 0x7c) & 0xdfffffff;
    }
    _Dst = FUN_c05427a0(0x60);
    if (_Dst == (void *)0x0) {
      iVar18 = 1;
      pcVar15 = local_374;
      pcVar6 = local_378;
      goto LAB_c054fc5c;
    }
    *(void **)(iVar9 + 0x26c) = _Dst;
    memset(_Dst,0,0x60);
    pvVar5 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(undefined4 *)((int)_Dst + 0x1c) = 4;
    *(undefined4 *)((int)_Dst + 0x14) = 0x10114;
    *(int *)((int)_Dst + 0x18) = (int)_Dst + 0x5c;
    *(HANDLE *)((int)_Dst + 0x30) = pvVar5;
    *(undefined4 *)((int)_Dst + 0x10) = 0;
    *(uint *)(iVar9 + 0x484) = *(uint *)(iVar9 + 0x484) | 8;
    *(undefined4 *)((int)_Dst + 0xc) = 0x80000000;
    pBVar16 = (LPBYTE)(iVar9 + 0x1dc);
    pBVar16[0] = '\x02';
    pBVar16[1] = '\0';
    pBVar16[2] = '\0';
    pBVar16[3] = '\0';
    FUN_c0560594((HKEY)0x80000002,awStack_330,L"CheckForHangTimeInSeconds",pBVar16);
  }
  *(undefined2 *)(iVar9 + 0x1e2) = *(undefined2 *)(iVar9 + 0x1e0);
  if ((*(byte *)(iVar9 + 0x27c) & 1) != 0) {
    FUN_c0556230(iVar17,1,0x10115,&local_37c,4,2,'\x01');
    *(undefined2 *)(iVar9 + 0x206) = 0x10;
    if (local_37c < 0x10) {
      *(short *)(iVar9 + 0x206) = (short)local_37c;
    }
  }
  iVar18 = *(int *)(iVar9 + 0x144);
  if (iVar18 == 0) {
    puVar7 = &local_364;
    iVar18 = FUN_c0556230(iVar17,1,0x1010104,puVar7,4,7,'\x01');
    if (iVar18 == 0) {
      puVar7 = auStack_338;
      *(uint *)(iVar9 + 0x220) = local_364;
      iVar18 = FUN_c0556230(iVar17,1,0x1010102,puVar7,6,9,'\x01');
      if (iVar18 != 0) goto LAB_c054f8a0;
      puVar7 = &local_37c;
      iVar18 = FUN_c0556230(iVar17,1,0x10202,puVar7,4,10,'\x01');
      if (iVar18 != 0) goto LAB_c054f824;
      *(uint *)(iVar9 + 0x46c) = local_37c;
      FUN_c055686c(iVar17,(uint *)0x0);
      iVar18 = 0;
    }
    else {
LAB_c054f8a0:
      bVar1 = true;
    }
    pcVar15 = local_374;
    pcVar6 = local_378;
    if (iVar18 != 0) goto LAB_c054fc5c;
  }
  else if (iVar18 == 1) {
    puVar7 = auStack_338;
    iVar18 = FUN_c0556230(iVar17,1,0x2010102,puVar7,6,0xb,'\x01');
    if (iVar18 != 0) goto LAB_c054f8a0;
  }
  else {
    if (iVar18 == 3) {
      puVar7 = auStack_338;
      iVar18 = FUN_c0556230(iVar17,1,0x4010102,puVar7,6,0x17,'\x01');
      if (iVar18 != 0) goto LAB_c054f8a0;
    }
LAB_c054f824:
    iVar18 = 0;
  }
  if (*(int *)(iVar9 + 0x144) == 0) {
    bVar4 = EthCreateFilter(local_364,auStack_338,&local_360);
    local_35c[0] = local_360;
    if (CONCAT31(extraout_var_03,bVar4) != 0) goto LAB_c054f9b4;
    iVar18 = 9;
LAB_c054f9a8:
    bVar1 = true;
  }
  else {
    if (*(int *)(iVar9 + 0x144) != 1) {
      bVar4 = FUN_c055b6a4(&local_360);
      local_35c[0] = local_360;
      if (CONCAT31(extraout_var_01,bVar4) != 0) goto LAB_c054f9b4;
      iVar18 = 0x1e;
      goto LAB_c054f9a8;
    }
    bVar4 = FUN_c055a59c(auStack_338,local_35c);
    if (CONCAT31(extraout_var_02,bVar4) == 0) {
      iVar18 = 0xc;
      goto LAB_c054f9a8;
    }
LAB_c054f9b4:
    *(int *)(local_35c[0] + 0x18) = iVar17;
  }
  if (bVar1) {
    puVar7 = (uint *)0xff00ff00;
    NdisFreeBufferPool();
    pcVar15 = local_374;
    pcVar6 = local_378;
  }
  else {
    if (((((*(uint *)(iVar9 + 0x270) & 0x8001) != 0) ||
         ((*(ushort *)(*(int *)(iVar9 + 0x30) + 0xb8) & 1) != 0)) && (-1 < *(int *)(iVar9 + 0x144)))
       && (*(int *)(iVar9 + 0x144) < 0x11)) {
      puVar7 = (uint *)(iVar9 + 0x298);
      iVar18 = FUN_c0556230(iVar17,1,0xfd010100,puVar7,0x10,0x19,'\0');
      *puVar7 = 0;
      if (iVar18 == 0) {
        uVar10 = *(uint *)(iVar9 + 0x270);
        *(uint *)(iVar9 + 0x270) = uVar10 | 1;
        if (((*(int *)(iVar9 + 0x2a4) != 0) || (*(int *)(iVar9 + 0x29c) != 0)) ||
           (bVar1 = false, *(int *)(iVar9 + 0x2a0) != 0)) {
          bVar1 = true;
        }
        if (!bVar1) {
          *(undefined4 *)(iVar9 + 0x2d4) = 1;
        }
        uVar14 = *(uint *)(iVar9 + 0x1c8);
        if ((uVar14 & 8) == 0) {
          *(uint *)(iVar9 + 0x270) = uVar10 | 0x21;
          if ((*(int *)(iVar9 + 0x2a4) != 0) && (*(short *)(iVar9 + 0x374) != -1)) {
            *(uint *)(iVar9 + 0x2e8) = *(uint *)(iVar9 + 0x2e8) | 4;
          }
          if (((uVar14 & 0x10) == 0) && (bVar1)) {
            if ((*(int *)(iVar9 + 0x2a0) != 0) && ((uVar14 & 0x100) == 0)) {
              *(uint *)(iVar9 + 0x270) = uVar10 | 0x61;
              *puVar7 = 3;
            }
            if ((*(int *)(iVar9 + 0x29c) != 0) && ((uVar14 & 0x80) == 0)) {
              *(uint *)(iVar9 + 0x270) = *(uint *)(iVar9 + 0x270) | 0x40;
              *puVar7 = *puVar7 | 4;
              *(uint *)(iVar9 + 0x2e8) = *(uint *)(iVar9 + 0x2e8) | 1;
            }
          }
          if (DAT_c05653f0 == 1) {
            FUN_c0546604(iVar17);
          }
        }
      }
      else {
        if (*(int *)(iVar9 + 0x14c) == -2) {
          FUN_c055cea0(iVar17,0);
        }
        *(uint *)(iVar9 + 0x270) = *(uint *)(iVar9 + 0x270) & 0xfffffffe;
      }
    }
    NdisInitializeTimer((int *)(iVar9 + 0x334),FUN_c055cd44,iVar17);
    bVar2 = false;
    bVar3 = false;
    iVar18 = 0;
    NdisMSetPeriodicTimer((int *)(iVar9 + 0xe0),*(int *)(iVar9 + 0x1dc) * 1000);
    local_36c = (uint)((char)DAT_c05653c4 == '\x01');
    puVar7 = (uint *)0x4;
    FUN_c054bbf8(iVar17,5,&local_36c,4);
    FUN_c055672c(iVar17,&local_360);
    if ((*(uint *)(iVar9 + 0x7c) & 0x40000) == 0) {
      *(code **)(iVar9 + 0x1a0) = FUN_c05527dc;
    }
    else {
      *(code **)(iVar9 + 0x1a0) = FUN_c0554038;
    }
    FUN_c054dde0(iVar17);
    *(undefined4 *)(iVar9 + 0x4a4) = *(undefined4 *)(iVar9 + 0x130);
    pcVar15 = local_374;
    pcVar6 = local_378;
    cVar19 = '\0';
  }
LAB_c054fc5c:
  if ((bVar2) &&
     (((**(code **)(*(int *)(iVar17 + 8) + 0x34))(*(undefined4 *)(iVar17 + 0xc)),
      *(int *)(iVar17 + 0x1ec) != 0 || (*(int *)(iVar17 + 0x50) != 0)))) {
    if (*(int *)(iVar17 + 0x50) == 0) {
      pcVar6 = pcVar15;
    }
    DbgPrint(pcVar20,*(undefined4 *)(iVar17 + 0x1e8),pcVar6,puVar7);
    trap(0x400);
  }
  if (cVar19 != '\0') {
    FUN_c05590d8(iVar17,(int)param_1);
  }
  if (bVar3) {
    FUN_c055915c(param_1,0);
  }
  FUN_c05625b0(local_30);
  return iVar18;
}



/* c054fd1c NdisIMRevertBack */

/* Boundary evidence: original MIPS .pdata c054fd1c..c054fdab. Semantic name remains unreviewed. */

void NdisIMRevertBack(int param_1,int param_2)

{
  int iVar1;
  
                    /* 0xfd1c  99  NdisIMRevertBack */
  iVar1 = __GetUserKData(8);
  if (*(int *)(param_1 + 0x4b4) == iVar1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c054eae0(param_1);
    if (param_2 != -1) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
      *(undefined4 *)(param_1 + 0x454) = 0;
      *(undefined4 *)(param_1 + 0x458) = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c054fdac NdisIMQueueMiniportCallback */

/* Boundary evidence: original MIPS .pdata c054fdac..c054ff17. Semantic name remains unreviewed. */

undefined4 NdisIMQueueMiniportCallback(int param_1,undefined *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
                    /* 0xfdac  97  NdisIMQueueMiniportCallback */
  iVar1 = __GetUserKData(8);
  if (*(int *)(param_1 + 0x4b4) == iVar1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    uVar3 = 1;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = __GetUserKData(8);
    uVar3 = (uint)(*(int *)(param_1 + 0x4b4) != iVar1);
    if (uVar3 == 1) {
      uVar3 = TryEnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
      uVar3 = uVar3 & 0xff;
      if (uVar3 == 1) {
        *(undefined4 *)(param_1 + 0x454) = 0xb0add;
        uVar2 = __GetUserKData(8);
        *(undefined4 *)(param_1 + 0x458) = uVar2;
      }
    }
  }
  if (uVar3 == 0) {
    iVar1 = FUN_c054cd08(param_1,6,param_3,(int)param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if (iVar1 == 0) {
      uVar2 = 0x103;
    }
    else {
      uVar2 = 0xc000009a;
    }
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    (*(code *)param_2)(*(undefined4 *)(param_1 + 0xc),param_3);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c054eae0(param_1);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
    *(undefined4 *)(param_1 + 0x454) = 0;
    *(undefined4 *)(param_1 + 0x458) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    uVar2 = 0;
  }
  return uVar2;
}



/* c054ff18 FUN_c054ff18 */

/* Boundary evidence: original MIPS .pdata c054ff18..c05501df. Semantic name remains unreviewed. */

int FUN_c054ff18(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte local_30 [8];
  
  iVar4 = *(int *)(param_1 + 8);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  bVar1 = true;
  if ((*(uint *)(iVar4 + 0x248) & 0x80000) == 0) {
    if ((*(uint *)(iVar4 + 0x54) & 0x40000) == 0) {
      uVar3 = FUN_c054cc28(iVar4,3,param_1);
    }
    else {
      uVar3 = *(uint *)(iVar4 + 0x54) & 0x200000;
    }
    iVar5 = -0x3ffefff3;
    if ((uVar3 == 0) && (iVar5 = -0x7ffeffff, *(int *)(*(int *)(iVar4 + 8) + 0x4c) != 0)) {
      NdisInterlockedIncrement((LONG *)(param_1 + 0x80));
      uVar3 = *(uint *)(iVar4 + 0x54);
      *(int *)(iVar4 + 0x1c0) = param_1;
      if ((uVar3 & 0x40000) == 0) {
        *(uint *)(iVar4 + 0x54) = uVar3 | 0x100000;
        iVar5 = __GetUserKData(8);
        uVar3 = (uint)(*(int *)(iVar4 + 0x4b4) != iVar5);
        if (uVar3 == 1) {
          uVar3 = TryEnterCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x4b0));
          uVar3 = uVar3 & 0xff;
          if (uVar3 == 1) {
            *(undefined4 *)(iVar4 + 0x454) = 0xb12a5;
            uVar2 = __GetUserKData(8);
            *(undefined4 *)(iVar4 + 0x458) = uVar2;
          }
        }
        if ((uVar3 != 0) && (FUN_c054eae0(iVar4), uVar3 != 0)) {
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x4b0));
          *(undefined4 *)(iVar4 + 0x454) = 0;
          *(undefined4 *)(iVar4 + 0x458) = 0;
        }
        iVar5 = 0x103;
      }
      else {
        local_30[0] = 0;
        *(uint *)(iVar4 + 0x54) = uVar3 | 0x280000;
        FUN_c054e23c(iVar4,0xc001000d,1);
        iVar5 = *(int *)(iVar4 + 0x43c);
        while (iVar5 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          Sleep(1);
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          iVar5 = *(int *)(iVar4 + 0x43c);
        }
        if (*(int *)(iVar4 + 0x2c4) == 1) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          bVar1 = false;
          NdisMIndicateStatus(iVar4,0x40010004,(uint *)0x0,0);
          NdisMIndicateStatusComplete(iVar4);
          iVar5 = (**(code **)(*(int *)(iVar4 + 8) + 0x4c))(local_30,*(undefined4 *)(iVar4 + 0xc));
          if (iVar5 != 0x103) {
            NdisMResetComplete(iVar4,iVar5,(uint)local_30[0]);
            iVar5 = 0x103;
          }
        }
        else {
          iVar5 = -0x3fffff45;
          *(undefined4 *)(iVar4 + 0x1c0) = 0;
          *(byte *)(iVar4 + 599) = *(byte *)(iVar4 + 599) & 0xfe;
          *(undefined4 *)(iVar4 + 0x1e0) = 0xc00000bb;
          *(uint *)(iVar4 + 0x54) = *(uint *)(iVar4 + 0x54) & 0xffd7ffff;
          iVar4 = NdisInterlockedDecrement((LONG *)(param_1 + 0x80));
          if (iVar4 == 0) {
            FUN_c0559efc(param_1);
          }
        }
      }
    }
  }
  else {
    iVar5 = -0x7ffeffff;
  }
  if (bVar1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return iVar5;
}



/* c05501e0 FUN_c05501e0 */

/* Boundary evidence: original MIPS .pdata c05501e0..c05504cb. Semantic name remains unreviewed. */

void FUN_c05501e0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  void *_Dst;
  int *piVar10;
  
  iVar9 = param_2[2];
  piVar10 = (int *)param_2[3];
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  bVar1 = false;
  bVar5 = FUN_c055a404(iVar9 + 0x20);
  if (CONCAT31(extraout_var,bVar5) == 0) {
    uVar7 = 0xc0010002;
  }
  else {
    _Dst = *(void **)(iVar9 + 0x44c);
    bVar3 = true;
    if (_Dst == (void *)0x0) {
      _Dst = FUN_c05427a0(0x6c);
      if (_Dst == (void *)0x0) {
        uVar7 = 0xc000009a;
        goto LAB_c055024c;
      }
      memset(_Dst,0,0x6c);
      *(void **)(iVar9 + 0x44c) = _Dst;
      bVar1 = true;
    }
    *param_2 = _Dst;
    param_2[7] = *(undefined4 *)(iVar9 + 0xc);
    *(short *)(param_2 + 0x28) = (short)*(undefined4 *)(iVar9 + 0x200);
    InitializeCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x21));
    param_2[0x20] = 1;
    if (param_3 != 0) {
      param_2[0x1f] = param_2[0x1f] | 1;
    }
    param_2[0x2a] = *(undefined4 *)(*(int *)(iVar9 + 8) + 0x50);
    param_2[0x2c] = *(undefined4 *)(iVar9 + 0x42c);
    param_2[0x2b] = *(undefined4 *)(*(int *)(iVar9 + 8) + 0x58);
    param_2[0x12] = piVar10[0xd];
    param_2[0x13] = piVar10[0xe];
    param_2[0x14] = piVar10[0x11];
    param_2[0x15] = piVar10[0x12];
    param_2[0x1d] = piVar10[0x13];
    param_2[0x1e] = piVar10[0x14];
    param_2[0x1c] = piVar10[0xf];
    param_2[0x17] = piVar10[0x10];
    param_2[0x1a] = FUN_c054ff18;
    iVar8 = piVar10[0x17];
    param_2[0x1b] = FUN_c0558a84;
    param_2[0x18] = iVar8;
    if ((*(uint *)(iVar9 + 0x54) & 0x40000) != 0) {
      param_2[0x1b] = FUN_c0558df4;
    }
    param_2[1] = param_2;
    param_2[0x11] = FUN_c0552f18;
    FUN_c054e074(iVar9,(int)param_2);
    param_2[0x2d] = *(undefined4 *)(*(int *)(iVar9 + 8) + 0x80);
    *(undefined4 *)(iVar9 + 0x420) = param_2[0x10];
    *(undefined4 *)(iVar9 + 0x424) = param_2[0x19];
    *(undefined4 *)(iVar9 + 0x428) = param_2[0x2d];
    iVar8 = FUN_c054dd74(iVar9,(int)param_2);
    if (iVar8 == 0) {
      *param_1 = 0xc0010007;
      goto LAB_c0550460;
    }
    bVar4 = true;
    bVar5 = FUN_c0548e34((int)param_2,piVar10);
    if (CONCAT31(extraout_var_00,bVar5) != 0) {
      bVar2 = true;
      if ((*(int *)(iVar9 + 0x11c) == 0) || (*(int *)(iVar9 + 0x11c) != 1)) {
        puVar6 = *(undefined4 **)(iVar9 + 0xf8);
      }
      else {
        puVar6 = *(undefined4 **)(iVar9 + 0xfc);
      }
      bVar5 = FUN_c055ba0c(puVar6,param_2,param_2 + 0x26);
      if (CONCAT31(extraout_var_01,bVar5) != 0) {
        if (bVar1) {
          *(code **)((int)_Dst + 0x3c) = FUN_c0552f18;
          *(code **)((int)_Dst + 0x40) = FUN_c054ff18;
          *(undefined4 *)((int)_Dst + 0x44) = param_2[0x1b];
          *(undefined4 *)((int)_Dst + 0x38) = param_2[0x10];
        }
        *param_1 = 0;
        return;
      }
    }
    uVar7 = 0xc0010007;
  }
LAB_c055024c:
  *param_1 = uVar7;
LAB_c0550460:
  if (bVar4) {
    FUN_c0558f9c((int)param_2,iVar9);
  }
  if (bVar2) {
    FUN_c0548eb4((int)param_2,piVar10);
  }
  if (bVar3) {
    FUN_c0559738(iVar9);
  }
  return;
}



/* c05504cc NdisIMDeregisterLayeredMiniport */

/* Boundary evidence: original MIPS .pdata c05504cc..c05504e7. Semantic name remains unreviewed. */

void NdisIMDeregisterLayeredMiniport(int param_1)

{
                    /* 0x104cc  90  NdisIMDeregisterLayeredMiniport */
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xbc));
  return;
}



/* c05504e8 NdisIMAssociateMiniport */

void NdisIMAssociateMiniport(int param_1,int param_2)

{
                    /* 0x104e8  85  NdisIMAssociateMiniport */
  *(int *)(param_1 + 0xc) = param_2;
  *(int *)(param_2 + 0xc0) = param_1;
  return;
}



/* c05504f4 FUN_c05504f4 */

/* Boundary evidence: original MIPS .pdata c05504f4..c0550713. Semantic name remains unreviewed. */

undefined4 FUN_c05504f4(int *param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  HANDLE pvVar5;
  uint _Size;
  undefined4 *local_20 [2];
  
  if (param_1 == (int *)0x0) {
    uVar3 = 0xc0000001;
  }
  else {
    cVar1 = param_2[1];
    _Size = 0;
    if (cVar1 == '\0') {
      cVar2 = *param_2;
      if (cVar2 == '\x03') {
        _Size = 0x3c;
      }
      else if (cVar2 == '\x04') {
        _Size = 0x48;
      }
      else if (cVar2 == '\x05') {
        _Size = 0x60;
      }
    }
    else if ((cVar1 == '\x01') && (*param_2 == '\x05')) {
      _Size = 0x7c;
    }
    if (_Size == 0) {
      uVar3 = 0xc0010004;
    }
    else if ((param_3 < _Size) ||
            ((*param_2 == '\x05' &&
             (((*(int *)(param_2 + 0x58) != 0 && (*(int *)(param_2 + 0x5c) == 0)) ||
              ((cVar1 != '\0' && (*(int *)(param_2 + 0x68) == 0)))))))) {
      uVar3 = 0xc0010005;
    }
    else {
      iVar4 = FUN_c05612ac(*param_1,0x4e4d4944,0xd4,local_20);
      if (iVar4 < 0) {
        uVar3 = 0xc000009a;
      }
      else {
        memset(local_20[0],0,0xd4);
        memcpy(local_20[0] + 8,param_2,_Size);
        local_20[0][1] = 0;
        *(code **)(*param_1 + 0x24) = FUN_c0559240;
        pvVar5 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
        local_20[0][0x27] = pvVar5;
        local_20[0][2] = param_1;
        local_20[0][5] = local_20[0] + 4;
        local_20[0][4] = local_20[0][5];
        FUN_c055a4ec((LPCRITICAL_SECTION)(local_20[0] + 0x28));
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        *local_20[0] = DAT_c0565400;
        DAT_c0565400 = local_20[0];
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        uVar3 = 0;
        *param_4 = local_20[0];
      }
    }
  }
  return uVar3;
}



/* c0550714 NdisMRegisterUnloadHandler */

/* Boundary evidence: original MIPS .pdata c0550714..c0550757. Semantic name remains unreviewed. */

void NdisMRegisterUnloadHandler(int *param_1,int param_2)

{
                    /* 0x10714  144  NdisMRegisterUnloadHandler */
  if (*param_1 != 0) {
    param_1 = (int *)FUN_c0561324(*param_1);
  }
  if (param_1 != (int *)0x0) {
    param_1[7] = param_2;
  }
  return;
}



/* c0550758 NdisMRegisterIoPortRange */

/* Boundary evidence: original MIPS .pdata c0550758..c0550893. Semantic name remains unreviewed. */

undefined4 NdisMRegisterIoPortRange(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_28 [2];
  int local_20;
  undefined4 local_1c;
  
                    /* 0x10758  142  NdisMRegisterIoPortRange */
  if ((*(uint *)(param_2 + 0x408) & 0x20) == 0) {
    if (*(int *)(param_2 + 0x120) == -1) {
      return 0xc0000001;
    }
    iVar1 = *(int *)(param_2 + 0x124);
    if (iVar1 == -2) {
      uVar2 = FUN_c055dfd8(param_2,param_3,param_4,param_1);
      return uVar2;
    }
    if (iVar1 < 0) {
      return 0xc0000001;
    }
    if (((1 < iVar1) && (iVar1 != 5)) && (iVar1 != 8)) {
      return 0xc0000001;
    }
    local_28[0] = 1;
    iVar1 = HalTranslateBusAddress(iVar1,*(int *)(param_2 + 0x120),param_3,0,local_28,&local_20);
    if (iVar1 == 0) {
      return 0xc0000001;
    }
    if (local_28[0] == 0) {
      iVar1 = MmMapIoSpace(local_20,local_1c,param_4,0);
      *(int *)(param_2 + 0x4a4) = iVar1;
      if (iVar1 == 0) goto LAB_c0550790;
      *param_1 = iVar1;
    }
    else {
      *param_1 = local_20;
    }
    uVar2 = 0;
  }
  else {
LAB_c0550790:
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



/* c0550894 NdisMDeregisterIoPortRange */

/* Boundary evidence: original MIPS .pdata c0550894..c055094b. Semantic name remains unreviewed. */

void NdisMDeregisterIoPortRange(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int local_20 [2];
  undefined1 auStack_18 [8];
  
                    /* 0x10894  124  NdisMDeregisterIoPortRange */
  iVar1 = *(int *)(param_1 + 0x124);
  if (iVar1 == -2) {
    FUN_c055e0b0(param_1,param_2,param_3,param_4);
  }
  else if ((-1 < iVar1) && (((iVar1 < 2 || (iVar1 == 5)) || (iVar1 == 8)))) {
    local_20[0] = 1;
    HalTranslateBusAddress(iVar1,*(undefined4 *)(param_1 + 0x120),param_2,0,local_20,auStack_18);
    if (local_20[0] == 0) {
      MmUnmapIoSpace(*(undefined4 *)(param_1 + 0x4a4),param_3);
    }
  }
  return;
}



/* c055094c NdisMMapIoSpace */

/* Boundary evidence: original MIPS .pdata c055094c..c0550a47. Semantic name remains unreviewed. */

undefined4 NdisMMapIoSpace(int *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1094c  132  NdisMMapIoSpace */
  local_20[0] = 0;
  if ((*(uint *)(param_2 + 0x408) & 0x10) == 0) {
    if (*(int *)(param_2 + 0x120) == -1) {
      return 0xc0000001;
    }
    iVar2 = *(int *)(param_2 + 0x124);
    if (iVar2 == -2) {
      uVar1 = FUN_c055e0cc(param_2,param_3,param_5,param_1);
      return uVar1;
    }
    if (((iVar2 != 0) && (iVar2 != 5)) && (iVar2 != 8)) {
      return 0xc0000001;
    }
    iVar2 = HalTranslateBusAddress
                      (iVar2,*(int *)(param_2 + 0x120),param_3,param_4,local_20,&local_18);
    if (iVar2 == 0) {
      return 0xc0000001;
    }
    iVar2 = MmMapIoSpace(local_18,local_14,param_5,0);
    *param_1 = iVar2;
    if (iVar2 != 0) {
      return 0;
    }
  }
  else {
    *param_1 = 0;
  }
  return 0xc000009a;
}



/* c0550a48 NdisMUnmapIoSpace */

/* Boundary evidence: original MIPS .pdata c0550a48..c0550aab. Semantic name remains unreviewed. */

void NdisMUnmapIoSpace(int param_1,int param_2,int param_3)

{
  int iVar1;
  
                    /* 0x10a48  159  NdisMUnmapIoSpace */
  iVar1 = *(int *)(param_1 + 0x124);
  if (iVar1 == -2) {
    FUN_c055e0f0(param_1,param_3,param_2);
  }
  else if (((iVar1 == 0) || (iVar1 == 5)) || (iVar1 == 8)) {
    MmUnmapIoSpace(param_2,param_3);
  }
  return;
}



/* c0550aac NdisMAllocateSharedMemory */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0550aac..c0550cdb. Semantic name remains unreviewed. */

void NdisMAllocateSharedMemory(int param_1,int param_2,uint *param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined2 local_38 [2];
  undefined4 local_34;
  undefined4 local_30;
  
                    /* 0x10aac  117  NdisMAllocateSharedMemory */
  iVar8 = *(int *)(param_1 + 0x118);
  if ((*(uint *)(param_1 + 0x408) & 4) != 0) {
    *param_4 = 0;
    return;
  }
  uVar7 = (DAT_c0565420 + param_2) - 1U & ~(DAT_c0565420 - 1U);
  uVar1 = (uint)(param_3 != (uint *)0x0);
  puVar3 = param_4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565428);
  local_34 = *(undefined4 *)(param_1 + 0x124);
  local_30 = *(undefined4 *)(param_1 + 0x120);
  puVar6 = (uint *)((uVar1 + 4) * 4 + iVar8);
  local_38[0] = 0xc;
  if (*puVar6 < uVar7) {
    if (_DAT_00005b04 <= uVar7 + 8) {
      uVar1 = HalAllocateCommonBuffer(local_38,uVar7,param_5);
      *param_4 = uVar1;
      goto LAB_c0550ca4;
    }
    iVar2 = HalAllocateCommonBuffer(local_38,_DAT_00005b04,(uVar1 + 3) * 8 + iVar8);
    *(int *)((uVar1 + 2) * 4 + iVar8) = iVar2;
    if (iVar2 == 0) {
      *puVar6 = 0;
      *param_4 = 0;
      goto LAB_c0550ca4;
    }
    iVar2 = _DAT_00005b04 + iVar2;
    *(undefined4 *)(iVar2 + -8) = 0x6873444e;
    *(undefined4 *)(iVar2 + -4) = 0;
    *puVar6 = _DAT_00005b04 - 8;
    puVar3 = param_3;
  }
  iVar9 = *(int *)((uVar1 + 2) * 4 + iVar8);
  iVar2 = _DAT_00005b04 + iVar9;
  if (*(int *)(iVar2 + -8) != 0x6873444e) {
    DbgPrint(" ***NDIS*** : Miniport %Z - %s\n",*(undefined4 *)(param_1 + 0x1e8),
             "Overwrote past allocated shared memory",puVar3);
    trap(0x400);
  }
  *(int *)(iVar2 + -4) = *(int *)(iVar2 + -4) + 1;
  uVar4 = ((_DAT_00005b04 - *puVar6) + iVar9) - 8;
  *param_4 = uVar4;
  uVar4 = _DAT_00005b04 - 1 & uVar4;
  piVar5 = (int *)((uVar1 + 3) * 8 + iVar8);
  iVar8 = piVar5[1];
  uVar1 = uVar4 + *piVar5;
  *param_5 = uVar1;
  param_5[1] = iVar8 + (uint)(uVar1 < uVar4);
  *puVar6 = *puVar6 - uVar7;
LAB_c0550ca4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565428);
  return;
}



/* c0550cdc FUN_c0550cdc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0550cdc..c0550e73. Semantic name remains unreviewed. */

void FUN_c0550cdc(int param_1,int param_2,int param_3,uint param_4,uint param_5,undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  undefined2 local_30 [2];
  undefined4 local_2c;
  undefined4 local_28;
  
  local_30[0] = 0xc;
  local_2c = *(undefined4 *)(param_1 + 0x124);
  local_28 = *(undefined4 *)(param_1 + 0x120);
  iVar6 = *(int *)(param_1 + 0x118);
  uVar5 = (DAT_c0565420 + param_2) - 1U & ~(DAT_c0565420 - 1U);
  uVar1 = param_4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565428);
  if (uVar5 + 8 < _DAT_00005b04) {
    uVar5 = ~(_DAT_00005b04 - 1) & param_4;
    iVar3 = _DAT_00005b04 + uVar5;
    if (*(int *)(iVar3 + -8) != 0x6873444e) {
      DbgPrint(" ***NDIS*** : Miniport %Z - %s\n",*(undefined4 *)(param_1 + 0x1e8),
               "Freeing shared memory not allocated",uVar1);
      trap(0x400);
    }
    iVar2 = *(int *)(iVar3 + -4) + -1;
    *(int *)(iVar3 + -4) = iVar2;
    if (iVar2 == 0) {
      HalFreeCommonBuffer(local_30,_DAT_00005b04,~(_DAT_00005b04 - 1) & param_5,param_6,uVar5,
                          (char)param_3);
      puVar4 = (uint *)(((param_3 != 0) + 2) * 4 + iVar6);
      if (uVar5 == *puVar4) {
        *(undefined4 *)(((param_3 != 0) + 4) * 4 + iVar6) = 0;
        *puVar4 = 0;
      }
    }
  }
  else {
    HalFreeCommonBuffer(local_30,uVar5,param_5,param_6,param_4,(char)param_3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565428);
  return;
}



/* c0550e74 NdisMFreeSharedMemory */

/* Boundary evidence: original MIPS .pdata c0550e74..c0550e9b. Semantic name remains unreviewed. */

void NdisMFreeSharedMemory
               (int param_1,int param_2,int param_3,uint param_4,uint param_5,undefined4 param_6)

{
                    /* 0x10e74  127  NdisMFreeSharedMemory */
  FUN_c0550cdc(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



/* c0550e9c NdisFreeBufferPool */

void NdisFreeBufferPool(void)

{
                    /* 0x10e9c  60  NdisFreeBufferPool
                       0x10e9c  126  NdisMFreeMapRegisters
                       0x10e9c  222  NdisWriteErrorLogEntry */
  return;
}



/* c0550ea4 NdisMRegisterAdapterShutdownHandler */

void NdisMRegisterAdapterShutdownHandler(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
                    /* 0x10ea4  140  NdisMRegisterAdapterShutdownHandler */
  puVar1 = *(undefined4 **)(param_1 + 0x118);
  if (puVar1[1] == 0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return;
}



/* c0550ec4 NdisMDeregisterAdapterShutdownHandler */

void NdisMDeregisterAdapterShutdownHandler(int param_1)

{
                    /* 0x10ec4  122  NdisMDeregisterAdapterShutdownHandler */
  if (*(int *)(*(int *)(param_1 + 0x118) + 4) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x118) + 4) = 0;
  }
  return;
}



/* c0550ee0 NdisMPciAssignResources */

undefined4 NdisMPciAssignResources(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  
                    /* 0x10ee0  134  NdisMPciAssignResources */
  if ((*(int *)(param_1 + 0x124) == 5) && (*(int *)(param_1 + 0x264) != 0)) {
    *param_3 = *(int *)(param_1 + 0x264) + 0x10;
    uVar1 = 0;
  }
  else {
    *param_3 = 0;
    uVar1 = 0xc0000001;
  }
  return uVar1;
}



/* c0550f20 NdisMQueryAdapterResources */

/* Boundary evidence: original MIPS .pdata c0550f20..c0550fdf. Semantic name remains unreviewed. */

void NdisMQueryAdapterResources(undefined4 *param_1,int param_2,void *param_3,uint *param_4)

{
  uint _Size;
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x10f20  137  NdisMQueryAdapterResources */
  if (param_1 != (undefined4 *)0x0) {
    if (((param_4 == (uint *)0x0) || (param_2 == 0)) ||
       ((*param_4 != 0 && (param_3 == (void *)0x0)))) {
      *param_1 = 0x80000005;
    }
    else {
      iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 8) + 0x14) + 0x28c);
      if (iVar1 == 0) {
        uVar2 = 0xc0000001;
      }
      else {
        _Size = *(int *)(iVar1 + 0x14) * 0x18 + 8;
        if (_Size <= *param_4) {
          memcpy(param_3,(void *)(iVar1 + 0x10),_Size);
          *param_1 = 0;
          return;
        }
        *param_4 = _Size;
        uVar2 = 0xc000009a;
      }
      *param_1 = uVar2;
    }
  }
  return;
}



/* c0550fe0 FUN_c0550fe0 */

/* Boundary evidence: original MIPS .pdata c0550fe0..c0551047. Semantic name remains unreviewed. */

void FUN_c0550fe0(ushort *param_1,ushort *param_2,ushort *param_3,undefined4 param_4)

{
  ushort uVar1;
  
  *(undefined4 *)(param_2 + 2) = param_4;
  uVar1 = *param_1;
  *param_2 = uVar1;
  param_2[1] = uVar1 + 2;
  FUN_c055f8ec(param_2,param_1,0);
  *(undefined4 *)(param_3 + 2) = *(undefined4 *)(param_2 + 2);
  uVar1 = *param_2;
  *param_3 = uVar1;
  param_3[1] = uVar1 + 2;
  return;
}



/* c0551048 FUN_c0551048 */

/* Boundary evidence: original MIPS .pdata c0551048..c05511bf. Semantic name remains unreviewed. */

undefined4 FUN_c0551048(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  
  iVar3 = *(int *)(param_1 + 0x14);
  iVar4 = iVar3 + 0x28;
  piVar6 = *(int **)(iVar3 + 0x30);
  bVar1 = false;
  lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  if (piVar6 != (int *)0x0) {
    bVar1 = (*(ushort *)(piVar6 + 0x2e) & 1) != 0;
    if (bVar1) {
      lpCriticalSection = (LPCRITICAL_SECTION)(piVar6 + 0x2f);
      EnterCriticalSection(lpCriticalSection);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    for (iVar5 = piVar6[1]; (iVar5 != 0 && (iVar5 != iVar4)); iVar5 = *(int *)(iVar5 + 0x1c)) {
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if ((iVar5 == iVar4) && (*(char *)(iVar3 + 0x5e) != '\x01')) {
      FUN_c055a404((int)(piVar6 + 0x28));
      NdisResetEvent((undefined4 *)(iVar3 + 0x378));
      iVar5 = 0;
      FUN_c0559364(iVar4,0);
      iVar2 = *(int *)(iVar3 + 0x294);
      while (iVar2 != 0) {
        if (*(undefined4 **)(iVar3 + 0x294) != (undefined4 *)0x0) {
          *(undefined4 *)(iVar3 + 0x294) = **(undefined4 **)(iVar3 + 0x294);
        }
        CTEFreeMem();
        iVar5 = *(int *)(iVar3 + 0x294);
        iVar2 = iVar5;
      }
      FUN_c0559d80(iVar4,iVar5,param_3,param_4);
      if (*(int *)(iVar3 + 0x26c) != 0) {
        CloseHandle(*(HANDLE *)(*(int *)(iVar3 + 0x26c) + 0x30));
        CTEFreeMem(*(undefined4 *)(iVar3 + 0x26c));
        *(undefined4 *)(iVar3 + 0x26c) = 0;
      }
      FUN_c055915c(piVar6,0);
    }
  }
  if (bVar1) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* c05511c0 FUN_c05511c0 */

/* Boundary evidence: original MIPS .pdata c05511c0..c05513df. Semantic name remains unreviewed. */

void FUN_c05511c0(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  
  uVar2 = param_1[0x72];
  uVar3 = param_1[0x71];
  uVar4 = param_1[0x73];
  iVar5 = param_1[2];
  uVar6 = param_1[0x46];
  uVar7 = param_1[0x69];
  uVar8 = param_1[0x6a];
  uVar9 = param_1[4];
  uVar10 = param_1[5];
  uVar11 = param_1[0x7a];
  uVar12 = param_1[1];
  uVar13 = param_1[0x90];
  uVar14 = param_1[0x68];
  uVar15 = param_1[0x92];
  uVar17 = param_1[0x15];
  uVar20 = param_1[0xb1];
  uVar19 = param_1[0x94];
  uVar18 = param_1[0x66];
  uVar1 = *(undefined2 *)((int)param_1 + 0x34e);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 300));
  FUN_c055a518((LPCRITICAL_SECTION)(param_1 + 8));
  memset(param_1,0,0x350);
  memset(param_1 + 0xd5,0,0x174);
  FUN_c055a4ec((LPCRITICAL_SECTION)(param_1 + 8));
  param_1[0xd5] = 0;
  *(undefined2 *)(param_1 + 0xd) = 0;
  *param_1 = 0x504d444e;
  param_1[2] = iVar5;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 300));
  param_1[0x71] = uVar3;
  param_1[0x73] = uVar4;
  param_1[0x46] = uVar6;
  param_1[0x72] = uVar2;
  param_1[0x69] = uVar7;
  param_1[0x6a] = uVar8;
  param_1[4] = uVar9;
  param_1[5] = uVar10;
  param_1[0x7a] = uVar11;
  param_1[1] = uVar12;
  param_1[0x90] = uVar13;
  param_1[0x68] = uVar14;
  puVar16 = param_1 + 0x60;
  param_1[0x15] = uVar17 & 0x2000000;
  param_1[0x92] = uVar15 & 0x8613000;
  param_1[0xb1] = uVar20;
  param_1[0x94] = uVar19;
  param_1[0x66] = uVar18;
  *(undefined2 *)((int)param_1 + 0x34e) = uVar1;
  param_1[0x61] = puVar16;
  *puVar16 = puVar16;
  param_1[0x62] = 0;
  if ((*(ushort *)(iVar5 + 0xb8) & 1) != 0) {
    param_1[0x15] = uVar17 & 0x2000000 | 0x8000;
  }
  return;
}



/* c05513e0 NdisMGetDeviceProperty */

void NdisMGetDeviceProperty
               (int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5,undefined4 *param_6)

{
                    /* 0x113e0  128  NdisMGetDeviceProperty */
  if ((*(uint *)(param_1 + 0x248) & 0x200000) == 0) {
    *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0x400000;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x1c8);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x1c4);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = **(undefined4 **)(*(int *)(param_1 + 8) + 8);
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = *(undefined4 *)(param_1 + 0x264);
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = *(undefined4 *)(param_1 + 0x268);
  }
  return;
}



/* c0551468 NdisMRemoveMiniport */

/* Boundary evidence: original MIPS .pdata c0551468..c0551493. Semantic name remains unreviewed. */

undefined4 NdisMRemoveMiniport(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
                    /* 0x11468  145  NdisMRemoveMiniport */
  *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0x100;
  FUN_c054c04c(*(int **)(param_1 + 0x1c8),param_2,param_3,param_4);
  return 0;
}



/* c0551494 FUN_c0551494 */

/* Boundary evidence: original MIPS .pdata c0551494..c055158b. Semantic name remains unreviewed. */

int FUN_c0551494(ushort *param_1)

{
  void *_Buf1;
  void *pvVar1;
  int iVar2;
  uint _Size;
  int iVar3;
  ushort local_20;
  ushort local_1e;
  void *local_1c;
  
  local_20 = *param_1;
  local_1e = local_20 + 2;
  pvVar1 = FUN_c05427a0((uint)local_1e);
  if (pvVar1 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    local_1c = pvVar1;
    FUN_c055f8ec(&local_20,param_1,0);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
    _Buf1 = local_1c;
    iVar3 = DAT_c0565408;
    if (DAT_c0565408 != 0) {
      _Size = (uint)local_20;
      do {
        if ((_Size == *(ushort *)(iVar3 + 0x10)) &&
           (iVar2 = memcmp(_Buf1,*(void **)(iVar3 + 0x14),_Size), iVar2 == 0)) break;
        iVar3 = *(int *)(iVar3 + 0x250);
      } while (iVar3 != 0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
    CTEFreeMem(pvVar1);
  }
  return iVar3;
}



/* c055158c NdisMRegisterMiniport */

/* Boundary evidence: original MIPS .pdata c055158c..c05515a7. Semantic name remains unreviewed. */

void NdisMRegisterMiniport(int *param_1,char *param_2,uint param_3)

{
  undefined4 auStack_10 [2];
  
                    /* 0x1158c  143  NdisMRegisterMiniport */
  FUN_c05504f4(param_1,param_2,param_3,auStack_10);
  return;
}



/* c05515a8 NdisIMRegisterLayeredMiniport */

/* Boundary evidence: original MIPS .pdata c05515a8..c05515ff. Semantic name remains unreviewed. */

int NdisIMRegisterLayeredMiniport(int *param_1,char *param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x115a8  98  NdisIMRegisterLayeredMiniport */
  iVar1 = FUN_c05504f4(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    iVar2 = *param_4;
    *(ushort *)(iVar2 + 0xb8) = *(ushort *)(iVar2 + 0xb8) | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xbc));
  }
  return iVar1;
}



/* c0551600 NdisIMDeInitializeDeviceInstance */

/* Boundary evidence: original MIPS .pdata c0551600..c0551687. Semantic name remains unreviewed. */

undefined4
NdisIMDeInitializeDeviceInstance
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  int *piVar3;
  
                    /* 0x11600  89  NdisIMDeInitializeDeviceInstance */
  piVar3 = *(int **)(param_1 + 8);
  uVar2 = 0xc0000001;
  bVar1 = FUN_c055a404(param_1 + 0x20);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_c055a404((int)(piVar3 + 0x28));
    *(undefined4 *)(param_1 + 0x354) = 3;
    FUN_c0551048(*(int *)(param_1 + 0x1c4),0,param_3,param_4);
    *(undefined4 *)(param_1 + 0x2c4) = 0;
    FUN_c0559738(param_1);
    FUN_c055915c(piVar3,0);
    uVar2 = 0;
  }
  return uVar2;
}



/* c0551688 FUN_c0551688 */

/* Boundary evidence: original MIPS .pdata c0551688..c055173b. Semantic name remains unreviewed. */

int FUN_c0551688(int param_1)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14);
  if (*(int *)(iVar3 + 0x37c) == 3) {
    FUN_c05511c0((undefined4 *)(iVar3 + 0x28));
    *(uint *)(iVar3 + 0x270) = *(uint *)(iVar3 + 0x270) | 0x10000;
  }
  *(undefined4 *)(iVar3 + 0x28c) = 0;
  *(undefined4 *)(iVar3 + 0x290) = 0;
  iVar1 = FUN_c0551e2c(*(int **)(iVar3 + 0x30),param_1,*(undefined4 *)(iVar3 + 0x210),
                       *(uint **)(iVar3 + 0x2c));
  if (iVar1 == 0) {
    *(undefined4 *)(iVar3 + 0x37c) = 1;
    NdisSetEvent((undefined4 *)(iVar3 + 0x378));
    DVar2 = GetTickCount();
    *(DWORD *)(iVar3 + 0x3c0) = DVar2;
    *(undefined4 *)(iVar3 + 0x3c4) = 0;
  }
  return iVar1;
}



/* c055173c FUN_c055173c */

/* Boundary evidence: original MIPS .pdata c055173c..c055199f. Semantic name remains unreviewed. */

int FUN_c055173c(int *param_1,ushort *param_2,ushort *param_3,int **param_4,int param_5)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  LONG LVar5;
  undefined4 uVar6;
  ushort *puVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  iVar11 = -0x3fffffff;
  bVar2 = false;
  puVar7 = param_3;
  iVar3 = FUN_c0561324((int)param_1);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  for (piVar9 = (int *)DAT_c0565400; (piVar9 != (int *)0x0 && (piVar9 != (int *)iVar3));
      piVar9 = (int *)*piVar9) {
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  piVar10 = local_30[0];
  if (piVar9 == (int *)iVar3) {
    uVar1 = *param_2;
    param_4 = local_30;
    puVar7 = param_2;
    iVar4 = FUN_c055fbd0(param_1,uVar1 + 0x4f4,param_2,param_4);
    local_30[0][7] = param_5;
    piVar10 = local_30[0];
    if (-1 < iVar4) {
      bVar2 = true;
      memset((void *)local_30[0][5],0,uVar1 + 0x4f4);
      iVar8 = local_30[0][5];
      piVar10 = (int *)(iVar8 + 0x28);
      *piVar10 = 0x504d444e;
      *(int *)(iVar8 + 0x30) = iVar3;
      NdisInitializeEvent((undefined4 *)(iVar8 + 0x378));
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar8 + 100));
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar8 + 0x4d8));
      *(int **)(iVar8 + 0x1c0) = piVar10;
      iVar4 = iVar8 + 0x1a8;
      *(undefined4 *)(iVar8 + 0x37c) = 0;
      *(ushort **)(iVar8 + 0x1f0) = param_3;
      *(int **)(iVar8 + 0x1ec) = local_30[0];
      *(ushort **)(iVar8 + 500) = param_3;
      *(int *)(iVar8 + 0x140) = local_30[0][5];
      *(int *)(iVar8 + 0x1ac) = iVar4;
      *(int *)iVar4 = iVar4;
      FUN_c055a4ec((LPCRITICAL_SECTION)(iVar8 + 0x48));
      param_4 = (int **)(iVar8 + 0x4f0);
      puVar7 = (ushort *)(iVar8 + 0x1cc);
      *(undefined2 *)(iVar8 + 0x5c) = 0;
      FUN_c0550fe0(param_2,(ushort *)(iVar8 + 0x38),puVar7,param_4);
      iVar4 = FUN_c0551d6c((undefined4 *)(iVar8 + 0x210),(int)param_3);
      if (-1 < iVar4) {
        LVar5 = InterlockedIncrement((LONG *)&DAT_c05653e8);
        *(short *)(iVar8 + 0x376) = (short)LVar5;
        iVar11 = 0;
        bVar2 = false;
      }
    }
  }
  if (bVar2) {
    FUN_c055fd24(local_30[0]);
    local_30[0] = (int *)0x0;
  }
  if ((local_30[0] != (int *)0x0) && (-1 < iVar11)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
    piVar10[0x94] = (int)DAT_c0565408;
    DAT_c0565408 = piVar10;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656a0);
    if ((*(ushort *)(iVar3 + 0xb8) & 1) == 0) {
      uVar6 = 0;
      iVar11 = FUN_c0551688((int)local_30[0]);
      if (iVar11 == 0) {
        FUN_c0551fd4((int)piVar10,(int *)0x0,0);
      }
      else {
        FUN_c0559738((int)piVar10);
        FUN_c054c04c((int *)param_3,uVar6,puVar7,param_4);
      }
    }
  }
  return iVar11;
}



/* c05519a0 FUN_c05519a0 */

/* Boundary evidence: original MIPS .pdata c05519a0..c0551d6b. Semantic name remains unreviewed. */

int FUN_c05519a0(undefined4 param_1,int param_2,undefined2 *param_3)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_278;
  int local_274;
  HKEY apHStack_270 [4];
  ushort local_260 [2];
  wchar_t *local_25c;
  ushort local_258 [2];
  wchar_t *local_254;
  ushort local_250 [2];
  wchar_t *local_24c;
  ushort local_248 [2];
  wchar_t *local_244;
  ushort local_240 [2];
  wchar_t *local_23c;
  ushort local_238 [2];
  wchar_t *local_234;
  ushort local_230 [2];
  wchar_t *local_22c;
  ushort local_228 [2];
  wchar_t *local_224;
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_c05653c8;
  local_230[0] = 0x14;
  local_230[1] = 0x16;
  local_238[1] = 0x1a;
  local_22c = L"SlotNumber";
  local_234 = L"DeviceNumber";
  local_25c = L"FunctionNumber";
  local_248[1] = 0x20;
  local_238[0] = 0x18;
  local_244 = L"PnPCapabilities";
  local_260[1] = 0x1e;
  local_248[0] = 0x1e;
  local_228[1] = 0x1e;
  local_224 = L"RemoteBootCard";
  local_258[1] = 0x2e;
  local_258[0] = 0x2c;
  local_240[1] = 0x2c;
  local_240[0] = 0x2a;
  local_254 = L"RequiresMediaStatePoll";
  local_260[0] = 0x1c;
  local_228[0] = 0x1c;
  local_23c = L"NdisDriverVerifyFlags";
  local_250[0] = 0xe;
  local_250[1] = 0x10;
  local_24c = L"SysIntr";
  StringCchPrintfW(awStack_220,0x100,L"Comm\\%s\\Parms",*(undefined4 *)(param_2 + 0x14));
  FUN_c0549aa0(&local_278,(HKEY)0x80000002,awStack_220,(HKEY)0x0,apHStack_270);
  if (local_278 == 0) {
    iVar2 = *(int *)(param_2 + 0x1c8);
    uVar3 = *(undefined4 *)(iVar2 + 0xc);
    if (param_3 != (undefined2 *)0x0) {
      _Dst = FUN_c05427a0((uint)*(ushort *)(param_2 + 0x12));
      *(void **)(param_3 + 2) = _Dst;
      *param_3 = *(undefined2 *)(param_2 + 0x10);
      param_3[1] = *(undefined2 *)(param_2 + 0x12);
      memcpy(_Dst,*(void **)(param_2 + 0x14),(uint)*(ushort *)(param_2 + 0x12));
    }
    *(undefined4 *)(param_2 + 0x124) = uVar3;
    *(undefined4 *)(param_2 + 0x1a0) = 0;
    NdisReadConfiguration(&local_278,&local_274,apHStack_270,local_248,0);
    if (local_278 == 0) {
      *(undefined4 *)(param_2 + 0x1a0) = *(undefined4 *)(local_274 + 4);
    }
    *(undefined4 *)(param_2 + 0x120) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(param_2 + 0x260) = 0xffffffff;
    NdisReadConfiguration(&local_278,&local_274,apHStack_270,local_230,0);
    if (local_278 == 0) {
      *(undefined4 *)(param_2 + 0x260) = *(undefined4 *)(local_274 + 4);
    }
    else {
      uVar1 = 0;
      iVar2 = 0;
      NdisReadConfiguration(&local_278,&local_274,apHStack_270,local_238,0);
      if (local_278 == 0) {
        uVar1 = *(uint *)(local_274 + 4);
      }
      NdisReadConfiguration(&local_278,&local_274,apHStack_270,local_260,0);
      if (local_278 == 0) {
        iVar2 = *(int *)(local_274 + 4);
      }
      *(uint *)(param_2 + 0x260) = iVar2 << 5 | uVar1;
    }
    NdisReadConfiguration(&local_278,&local_274,apHStack_270,local_228,1);
    if ((local_278 == 0) && (*(int *)(local_274 + 4) != 0)) {
      *(uint *)(param_2 + 0x54) = *(uint *)(param_2 + 0x54) | 0x40000000;
      *(uint *)(param_2 + 0x45c) = *(uint *)(param_2 + 0x45c) | 0x4000;
    }
    *(undefined2 *)(param_2 + 0x34c) = 0xffff;
    *(uint *)(param_2 + 0x1a0) = *(uint *)(param_2 + 0x1a0) | 0x20;
    NdisReadConfiguration(&local_278,&local_274,apHStack_270,local_258,0);
    if ((local_278 == 0) && (*(int *)(local_274 + 4) == 1)) {
      *(uint *)(param_2 + 0x54) = *(uint *)(param_2 + 0x54) | 0x2000000;
    }
    *(undefined4 *)(param_2 + 0x48c) = 0xffffffff;
    NdisReadConfiguration(&local_278,&local_274,apHStack_270,local_250,0);
    if (local_278 == 0) {
      *(undefined4 *)(param_2 + 0x48c) = *(undefined4 *)(local_274 + 4);
    }
    NdisReadConfiguration(&local_278,&local_274,apHStack_270,local_240,1);
    if (local_278 == 0) {
      *(undefined4 *)(param_2 + 0x408) = *(undefined4 *)(local_274 + 4);
    }
    local_278 = 0;
    FUN_c054a03c(apHStack_270);
    FUN_c05625b0(local_20);
  }
  else {
    FUN_c05625b0(local_20);
  }
  return local_278;
}



/* c0551d6c FUN_c0551d6c */

/* Boundary evidence: original MIPS .pdata c0551d6c..c0551e2b. Semantic name remains unreviewed. */

undefined4 FUN_c0551d6c(undefined4 *param_1,int param_2)

{
  size_t sVar1;
  ushort *_Dst;
  undefined4 uVar2;
  wchar_t *_Str;
  
  *param_1 = 0;
  _Str = *(wchar_t **)(param_2 + 4);
  uVar2 = 0;
  sVar1 = wcslen(_Str);
  sVar1 = (sVar1 + 5) * 2;
  _Dst = FUN_c05427a0(sVar1);
  if (_Dst == (ushort *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,sVar1);
    *(ushort **)(_Dst + 2) = _Dst + 4;
    *_Dst = 0;
    _Dst[1] = (short)sVar1 - 8;
    FUN_c055fa0c(_Dst,_Str);
    *param_1 = _Dst;
  }
  return uVar2;
}



/* c0551e2c FUN_c0551e2c */

/* Boundary evidence: original MIPS .pdata c0551e2c..c0551f4f. Semantic name remains unreviewed. */

int FUN_c0551e2c(int *param_1,int param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  DWORD DVar2;
  DWORD DVar3;
  int iVar4;
  undefined2 auStack_38 [2];
  int local_34;
  int iStack_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  
  iVar4 = *(int *)(param_2 + 0x14);
  memset(&iStack_30,0,0x10);
  local_34 = 0;
  iVar1 = FUN_c05519a0(&iStack_30,iVar4 + 0x28,auStack_38);
  if (iVar1 == 0) {
    local_28 = param_2;
    local_24 = param_3;
    DVar2 = GetTickCount();
    local_2c = *(undefined4 *)param_1[2];
    iVar1 = FUN_c054edc0(param_1,&iStack_30,(int)auStack_38,param_4);
    DVar3 = GetTickCount();
    *(DWORD *)(iVar4 + 0x3e0) = DVar2 - DVar3;
    if ((DAT_c0565474 & 1) != 0) {
      DbgPrint("NDIS: Init time (%Z) %ld ms\n",*(undefined4 *)(iVar4 + 0x210),DVar2 - DVar3,param_4)
      ;
    }
    if (iVar1 != 0) {
      FUN_c055a534(iVar4 + 0x48);
    }
  }
  if (local_34 != 0) {
    CTEFreeMem();
  }
  return iVar1;
}



/* c0551f50 FUN_c0551f50 */

/* Boundary evidence: original MIPS .pdata c0551f50..c0551fd3. Semantic name remains unreviewed. */

undefined4 FUN_c0551f50(wchar_t *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  int iVar2;
  size_t sVar3;
  
  wVar1 = *param_2;
  while( true ) {
    if (wVar1 == L'\0') {
      return 0;
    }
    iVar2 = _wcsicmp(param_1,param_2);
    if (iVar2 == 0) break;
    sVar3 = wcslen(param_2);
    param_2 = param_2 + sVar3 + 1;
    wVar1 = *param_2;
  }
  return 1;
}



/* c0551fd4 FUN_c0551fd4 */

/* Boundary evidence: original MIPS .pdata c0551fd4..c0552153. Semantic name remains unreviewed. */

void FUN_c0551fd4(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  wchar_t *_Str1;
  wchar_t awStack_328 [128];
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_c05653c8;
  _Str1 = (wchar_t *)0x0;
  if ((*(uint *)(param_1 + 0x54) & 0x10000000) == 0) {
    StringCchPrintfW(awStack_328,0x80,L"%s\\%s\\Parms",L"\\Comm",*(undefined4 *)(param_1 + 0x14));
    iVar2 = FUN_c056056c((HKEY)0x80000002,awStack_328,L"UpperBind",(LPBYTE)awStack_228,0x200);
    if ((iVar2 != 0) ||
       (iVar2 = FUN_c056056c((HKEY)0x80000002,awStack_328,L"ProtocolsToBindTo",(LPBYTE)awStack_228,
                             0x200), iVar2 != 0)) {
      _Str1 = awStack_228;
    }
    iVar2 = 1;
    piVar1 = DAT_c0565404;
    if ((_Str1 != (wchar_t *)0x0) &&
       (iVar3 = wcscmp(_Str1,L"NOT"), piVar1 = DAT_c0565404, iVar3 == 0)) {
      _Str1 = _Str1 + 4;
      iVar2 = 0;
    }
    for (; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[8]) {
      if (((param_2 == (int *)0x0) || (piVar1 == param_2)) &&
         (((param_3 != 0 && (param_2 != (int *)0x0)) ||
          ((_Str1 == (wchar_t *)0x0 ||
           (iVar3 = FUN_c0551f50((wchar_t *)piVar1[0x16],_Str1), iVar3 == iVar2)))))) {
        FUN_c054b0fc(param_1,piVar1);
      }
    }
  }
  FUN_c05625b0(local_28);
  return;
}



/* c0552154 FUN_c0552154 */

/* Boundary evidence: original MIPS .pdata c0552154..c05521df. Semantic name remains unreviewed. */

undefined4 FUN_c0552154(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar1 = *param_1;
  do {
    if (iVar1 == 0) {
LAB_c05521b8:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      return uVar2;
    }
    if (*(int *)(iVar1 + 8) == param_2) {
      uVar2 = 1;
      goto LAB_c05521b8;
    }
    iVar1 = *(int *)(iVar1 + 0x18);
  } while( true );
}



/* c05521e0 FUN_c05521e0 */

/* Boundary evidence: original MIPS .pdata c05521e0..c0552253. Semantic name remains unreviewed. */

undefined4 FUN_c05521e0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_c05511c0(param_1);
  param_1[1] = param_2;
  iVar1 = FUN_c0551688(param_1[0x71]);
  if (iVar1 == 0) {
    FUN_c0551fd4((int)param_1,(int *)0x0,0);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



/* c0552254 FUN_c0552254 */

/* Boundary evidence: original MIPS .pdata c0552254..c0552417. Semantic name remains unreviewed. */

int FUN_c0552254(int param_1,ushort *param_2,undefined4 *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  HANDLE local_80 [2];
  undefined4 local_78 [3];
  HANDLE *local_6c;
  
  iVar6 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  puVar4 = *(undefined4 **)(param_1 + 0x18);
  if (puVar4 != (undefined4 *)0x0) {
    uVar1 = *param_2;
    puVar7 = (undefined4 *)(param_1 + 0x18);
    do {
      puVar5 = puVar4;
      if (((uint)*(ushort *)(puVar5 + 2) == (uint)uVar1) &&
         (iVar2 = memcmp((void *)puVar5[3],*(void **)(param_2 + 2),(uint)*(ushort *)(puVar5 + 2)),
         iVar2 == 0)) {
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = puVar5[1];
        }
        *puVar7 = *puVar5;
        CTEFreeMem(puVar5);
        iVar6 = 1;
        break;
      }
      puVar4 = (undefined4 *)*puVar5;
      puVar7 = puVar5;
    } while ((undefined4 *)*puVar5 != (undefined4 *)0x0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((((iVar6 == 0) && (param_3 != (undefined4 *)0x0)) &&
      (iVar2 = *(int *)(param_1 + 0xc), iVar2 != 0)) && (*(int *)(iVar2 + 0x68) != 0)) {
    memset(local_78,0,0x4c);
    local_80[0] = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    local_6c = local_80;
    local_78[0] = 4;
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xa0));
    *(undefined4 *)(iVar2 + 0xb4) = 0x40799;
    iVar3 = (**(code **)(iVar2 + 0x68))(0,local_78);
    if (iVar3 == 0x103) {
      WaitForSingleObject(local_80[0],0xffffffff);
    }
    *(undefined4 *)(iVar2 + 0xb4) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xa0));
    CloseHandle(local_80[0]);
  }
  return iVar6;
}



/* c0552418 NdisIMCancelInitializeDeviceInstance */

/* Boundary evidence: original MIPS .pdata c0552418..c05524c3. Semantic name remains unreviewed. */

undefined4 NdisIMCancelInitializeDeviceInstance(int param_1,ushort *param_2)

{
  int iVar1;
  undefined4 uVar2;
  ushort local_18;
  ushort local_16;
  void *local_14;
  
                    /* 0x12418  86  NdisIMCancelInitializeDeviceInstance */
  local_18 = *param_2;
  local_16 = local_18 + 2;
  local_14 = FUN_c05427a0((uint)local_16);
  if (local_14 == (void *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    FUN_c055f8ec(&local_18,param_2,0);
    iVar1 = FUN_c0552254(param_1,&local_18,(undefined4 *)0x0);
    if (iVar1 == 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xc0000001;
    }
    CTEFreeMem(local_14);
  }
  return uVar2;
}



/* c05524c4 NdisIMGetDeviceContext */

undefined4 NdisIMGetDeviceContext(int param_1)

{
                    /* 0x124c4  93  NdisIMGetDeviceContext */
  return *(undefined4 *)(param_1 + 4);
}



/* c05524cc NdisIMGetBindingContext */

undefined4 NdisIMGetBindingContext(int param_1)

{
                    /* 0x124cc  91  NdisIMGetBindingContext */
  return *(undefined4 *)(*(int *)(param_1 + 8) + 4);
}



/* c05524d8 NdisIMInitializeDeviceInstanceEx */

/* Boundary evidence: original MIPS .pdata c05524d8..c055265f. Semantic name remains unreviewed. */

int NdisIMInitializeDeviceInstanceEx(int param_1,ushort *param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  int iVar3;
  int *local_28 [2];
  
                    /* 0x124d8  95  NdisIMInitializeDeviceInstanceEx */
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xbc));
  puVar2 = (undefined4 *)FUN_c0551494(param_2);
  if (puVar2 == (undefined4 *)0x0) {
    iVar3 = FUN_c055ffd4((int *)**(undefined4 **)(param_1 + 8),*(short **)(param_2 + 2),0,0,
                         FUN_c055173c,local_28,0);
    if (iVar3 != 0) goto LAB_c0552630;
    puVar2 = (undefined4 *)FUN_c0551494(param_2);
    if (puVar2 == (undefined4 *)0x0) {
      FUN_c055fd24(local_28[0]);
      goto LAB_c0552630;
    }
  }
  else if (((puVar2[0x92] & 0x10000) != 0) && ((puVar2[0x92] & 0x4010) == 0)) {
    bVar1 = FUN_c054dce8((int)puVar2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      iVar3 = FUN_c05521e0(puVar2,param_3);
      if (iVar3 != 0) {
        puVar2[0x92] = puVar2[0x92] | 0x100;
      }
    }
    else {
      iVar3 = 0x10003;
    }
    goto LAB_c0552630;
  }
  puVar2[0x92] = puVar2[0x92] & 0xffffffef | 0x10000;
  puVar2[0x15] = puVar2[0x15] | 0x8000;
  EnterCriticalSection((LPCRITICAL_SECTION)(puVar2[2] + 0xbc));
  iVar3 = FUN_c05521e0(puVar2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2[2] + 0xbc));
LAB_c0552630:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xbc));
  return iVar3;
}



/* c0552660 NdisIMInitializeDeviceInstance */

/* Boundary evidence: original MIPS .pdata c0552660..c055267b. Semantic name remains unreviewed. */

void NdisIMInitializeDeviceInstance(int param_1,ushort *param_2)

{
                    /* 0x12660  94  NdisIMInitializeDeviceInstance */
  NdisIMInitializeDeviceInstanceEx(param_1,param_2,0);
  return;
}



/* c055267c FUN_c055267c */

/* Boundary evidence: original MIPS .pdata c055267c..c05527db. Semantic name remains unreviewed. */

void FUN_c055267c(int param_1,int param_2,int *param_3,undefined4 param_4,char param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  
  if (param_5 == '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  piVar1 = (int *)(param_2 + 0x28);
  iVar2 = *param_3;
  **(int **)(param_2 + 0x2c) = *piVar1;
  *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_2 + 0x2c);
  *(int **)(param_2 + 0x2c) = piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(param_2 + -4) = *(int *)(param_2 + -4) + -1;
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x400000;
  *param_3 = param_6 + 0x4d4f4330;
  *(int *)(iVar2 + 0x80) = *(int *)(iVar2 + 0x80) + -1;
  if ((param_5 == '\0') && (*(int *)(param_1 + 0x188) != 0)) {
    FUN_c054cc28(param_1,1,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  param_3[1] = 0;
  *(byte *)(param_2 + 0x1d) = *(byte *)(param_2 + 0x1d) & 0xc0;
  param_3[1] = 0;
  (**(code **)(iVar2 + 0x48))(*(undefined4 *)(iVar2 + 0x10),param_2,param_4);
  if (*(int *)(iVar2 + 0x80) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c0559efc(iVar2);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  if (param_5 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c05527dc FUN_c05527dc */

/* Boundary evidence: original MIPS .pdata c05527dc..c05529b3. Semantic name remains unreviewed. */

void FUN_c05527dc(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *(int *)(param_1 + 8);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (param_3 != 0) {
    do {
      iVar5 = *param_2;
      uVar2 = *(int *)(iVar5 + -4) + 1;
      *(uint *)(iVar5 + -4) = uVar2;
      if (uVar2 < DAT_c05653bc) {
        iVar6 = (uVar2 - DAT_c05653bc) * 0x28 + iVar5 + -8;
      }
      else {
        iVar6 = 0;
      }
      *(undefined4 *)((uint)*(ushort *)(iVar5 + 0x1e) + iVar5 + 0x1c) = 0x103;
      *(byte *)(iVar5 + 0x1d) = *(byte *)(iVar5 + 0x1d) & 0xfb;
      NdisInterlockedIncrement((LONG *)(param_1 + 0x80));
      piVar3 = (int *)(iVar5 + 0x28);
      *(int *)(iVar6 + 8) = param_1;
      *(int **)(iVar5 + 0x2c) = piVar3;
      *piVar3 = (int)piVar3;
      *piVar3 = iVar4 + 0x180;
      *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar4 + 0x184);
      **(int **)(iVar4 + 0x184) = (int)piVar3;
      *(int **)(iVar4 + 0x184) = piVar3;
      if (*(int *)(iVar4 + 0x188) == 0) {
        *(int *)(iVar4 + 0x188) = iVar5;
      }
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
    } while (param_3 != 0);
  }
  FUN_c054cc28(iVar4,1,0);
  iVar5 = __GetUserKData(8);
  uVar2 = (uint)(*(int *)(iVar4 + 0x4b4) != iVar5);
  if (uVar2 == 1) {
    uVar2 = TryEnterCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x4b0));
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 1) {
      *(undefined4 *)(iVar4 + 0x454) = 0x170109;
      uVar1 = __GetUserKData(8);
      *(undefined4 *)(iVar4 + 0x458) = uVar1;
    }
  }
  if (uVar2 != 0) {
    FUN_c054eae0(iVar4);
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x4b0));
    *(undefined4 *)(iVar4 + 0x454) = 0;
    *(undefined4 *)(iVar4 + 0x458) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c05529b4 FUN_c05529b4 */

/* Boundary evidence: original MIPS .pdata c05529b4..c0552a83. Semantic name remains unreviewed. */

void FUN_c05529b4(int param_1,int *param_2,LONG param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = DAT_c05653c0;
  iVar5 = *(int *)(param_1 + 8);
  InterlockedExchangeAdd((LONG *)(param_1 + 0x80),param_3);
  for (piVar4 = param_2; piVar4 < param_2 + param_3; piVar4 = piVar4 + 1) {
    iVar3 = *piVar4;
    iVar2 = *(int *)(iVar3 + -4) + 1;
    *(int *)(iVar3 + -4) = iVar2;
    *(int *)((iVar2 * 0x28 - iVar1) + iVar3 + 8) = param_1;
    *(byte *)(iVar3 + 0x1d) = *(byte *)(iVar3 + 0x1d) & 0xeb | 0x10;
  }
  (**(code **)(iVar5 + 0x42c))(*(undefined4 *)(iVar5 + 0xc),param_2,(int)piVar4 - (int)param_2 >> 2)
  ;
  return;
}



/* c0552a84 FUN_c0552a84 */

/* Boundary evidence: original MIPS .pdata c0552a84..c0552c07. Semantic name remains unreviewed. */

undefined4 FUN_c0552a84(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 8);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  *(byte *)(param_2 + 0x1d) = *(byte *)(param_2 + 0x1d) & 0xfb;
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
  uVar4 = *(int *)(param_2 + -4) + 1;
  *(uint *)(param_2 + -4) = uVar4;
  if (uVar4 < DAT_c05653bc) {
    iVar2 = (uVar4 - DAT_c05653bc) * 0x28 + param_2 + -8;
  }
  else {
    iVar2 = 0;
  }
  *(int *)(iVar2 + 8) = param_1;
  piVar3 = (int *)(param_2 + 0x28);
  *(int **)(param_2 + 0x2c) = piVar3;
  *piVar3 = (int)piVar3;
  *piVar3 = iVar5 + 0x180;
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(iVar5 + 0x184);
  **(undefined4 **)(iVar5 + 0x184) = piVar3;
  *(int **)(iVar5 + 0x184) = piVar3;
  if (*(int *)(iVar5 + 0x188) == 0) {
    *(int *)(iVar5 + 0x188) = param_2;
  }
  iVar2 = __GetUserKData(8);
  uVar4 = (uint)(*(int *)(iVar5 + 0x4b4) != iVar2);
  if (uVar4 == 1) {
    uVar4 = TryEnterCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x4b0));
    uVar4 = uVar4 & 0xff;
    if (uVar4 == 1) {
      *(undefined4 *)(iVar5 + 0x454) = 0x1702ef;
      uVar1 = __GetUserKData(8);
      *(undefined4 *)(iVar5 + 0x458) = uVar1;
    }
  }
  FUN_c054cc28(iVar5,1,0);
  if ((uVar4 != 0) && (FUN_c054eae0(iVar5), uVar4 != 0)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x4b0));
    *(undefined4 *)(iVar5 + 0x454) = 0;
    *(undefined4 *)(iVar5 + 0x458) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return 0x103;
}



/* c0552c08 FUN_c0552c08 */

/* Boundary evidence: original MIPS .pdata c0552c08..c0552c8b. Semantic name remains unreviewed. */

undefined4 FUN_c0552c08(int param_1,int param_2)

{
  int iVar1;
  int local_res4 [3];
  
  iVar1 = *(int *)(param_1 + 8);
  *(int *)(param_2 + -4) = *(int *)(param_2 + -4) + 1;
  *(int *)((*(int *)(param_2 + -4) * 0x28 - DAT_c05653c0) + param_2 + 8) = param_1;
  local_res4[0] = param_2;
  NdisInterlockedIncrement((LONG *)(param_1 + 0x80));
  (**(code **)(param_1 + 0xb0))(*(undefined4 *)(iVar1 + 0xc),local_res4,1);
  return 0x103;
}



/* c0552c8c NdisMSendComplete */

/* Boundary evidence: original MIPS .pdata c0552c8c..c0552d47. Semantic name remains unreviewed. */

void NdisMSendComplete(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
                    /* 0x12c8c  147  NdisMSendComplete */
  if (*(uint *)(param_2 + -4) < DAT_c05653bc) {
    iVar1 = (*(uint *)(param_2 + -4) - DAT_c05653bc) * 0x28 + param_2 + -8;
  }
  else {
    iVar1 = 0;
  }
  if (((*(uint *)(iVar1 + 8) & 0xffffff00) != 0x4d4f4300) &&
     ((*(byte *)(param_2 + 0x1d) & 0x10) != 0)) {
    if ((*(byte *)(param_2 + 0x1d) & 8) == 0) {
      FUN_c055267c(param_1,param_2,(int *)(iVar1 + 8),param_3,'\0',1);
    }
    else {
      *(undefined4 *)((uint)*(ushort *)(param_2 + 0x1e) + param_2 + 0x1c) = param_3;
      *(byte *)(param_2 + 0x1d) = *(byte *)(param_2 + 0x1d) & 0xf7;
    }
  }
  return;
}



/* c0552d48 FUN_c0552d48 */

/* Boundary evidence: original MIPS .pdata c0552d48..c0552e07. Semantic name remains unreviewed. */

void FUN_c0552d48(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_2 + -4);
  if (uVar2 < DAT_c05653bc) {
    iVar1 = (uVar2 - DAT_c05653bc) * 0x28 + param_2 + -8;
  }
  else {
    iVar1 = 0;
  }
  *(uint *)(param_2 + -4) = uVar2 - 1;
  iVar3 = *(int *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 8) = 0x4d4f4336;
  *(byte *)(param_2 + 0x1d) = *(byte *)(param_2 + 0x1d) & 0xc0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  (**(code **)(iVar3 + 0x48))(*(undefined4 *)(iVar3 + 0x10));
  iVar1 = NdisInterlockedDecrement((LONG *)(iVar3 + 0x80));
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c0559efc(iVar3);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c0552e08 NdisMSendResourcesAvailable */

/* Boundary evidence: original MIPS .pdata c0552e08..c0552e6f. Semantic name remains unreviewed. */

void NdisMSendResourcesAvailable(int param_1)

{
                    /* 0x12e08  148  NdisMSendResourcesAvailable */
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x400000;
  if (*(int *)(param_1 + 0x188) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c054cc28(param_1,1,0);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c0552e70 NdisMTransferDataComplete */

/* Boundary evidence: original MIPS .pdata c0552e70..c0552f17. Semantic name remains unreviewed. */

void NdisMTransferDataComplete(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
                    /* 0x12e70  158  NdisMTransferDataComplete */
  uVar3 = *(uint *)(param_2 + -8);
  if (uVar3 < (uint)(DAT_c05653bc * 3)) {
    piVar1 = (int *)((uVar3 % 3 + 2) * 4 + (uVar3 / 3 - DAT_c05653bc) * 0x28 + param_2 + -8);
    iVar2 = *piVar1;
    *piVar1 = 0;
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != 0) {
    *(int *)(param_2 + -8) = *(int *)(param_2 + -8) + -1;
    (**(code **)(iVar2 + 0x4c))(*(undefined4 *)(iVar2 + 0x10));
  }
  return;
}



/* c0552f18 FUN_c0552f18 */

/* Boundary evidence: original MIPS .pdata c0552f18..c055314b. Semantic name remains unreviewed. */

int FUN_c0552f18(int param_1,int param_2,int param_3,uint param_4,int param_5,uint *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 8);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar2 = *(int *)(iVar2 + 0x3a8);
  if ((param_2 == iVar2) && (iVar2 != 0)) {
    NdisCopyFromPacketToPacket
              (param_5,0,param_4,param_2,
               *(int *)((uint)*(ushort *)(param_2 + 0x1e) + param_2 + 0x10) + param_3,param_6);
    if (*param_6 == param_4) {
      iVar3 = 0;
    }
    else {
      iVar3 = -0x3fffffff;
    }
  }
  else {
    iVar2 = *(int *)(param_5 + -8);
    uVar1 = iVar2 + 1;
    *(uint *)(param_5 + -8) = uVar1;
    if (uVar1 < (uint)(DAT_c05653bc * 3)) {
      *(int *)(((uVar1 / 3 - DAT_c05653bc) * 10 + uVar1 % 3) * 4 + param_5) = param_1;
      iVar3 = (**(code **)(param_1 + 0xac))
                        (param_5,param_6,*(undefined4 *)(param_1 + 0x1c),param_2,param_3,param_4);
      if (*(code **)g_pLogNdisTransferData_exref != (code *)0x0) {
        (**(code **)g_pLogNdisTransferData_exref)
                  (param_5,param_6,*(undefined4 *)(param_1 + 0x1c),param_2,param_3,param_4);
      }
      if (iVar3 != 0x103) {
        uVar1 = *(uint *)(param_5 + -8);
        if (uVar1 < (uint)(DAT_c05653bc * 3)) {
          *(undefined4 *)(((uVar1 / 3 - DAT_c05653bc) * 10 + uVar1 % 3) * 4 + param_5) = 0;
        }
        *(int *)(param_5 + -8) = *(int *)(param_5 + -8) + -1;
      }
    }
    else {
      iVar3 = -0x3fffff66;
      *(int *)(param_5 + -8) = iVar2;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return iVar3;
}



/* c055314c FUN_c055314c */

/* Boundary evidence: original MIPS .pdata c055314c..c0553303. Semantic name remains unreviewed. */

undefined4 FUN_c055314c(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar4 = 0;
  if ((*(uint *)(iVar3 + 0x54) & 0x80000000) != 0) {
    return 0xc0000001;
  }
  if ((*(uint *)(iVar3 + 0x54) & 0x40000) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = __GetUserKData(8);
    uVar4 = (uint)(*(int *)(iVar3 + 0x4b4) != iVar1);
    if (uVar4 == 1) {
      uVar4 = TryEnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x4b0));
      uVar4 = uVar4 & 0xff;
      if (uVar4 == 1) {
        *(undefined4 *)(iVar3 + 0x454) = 0x1708d6;
        uVar2 = __GetUserKData(8);
        *(undefined4 *)(iVar3 + 0x458) = uVar2;
      }
    }
  }
  if ((*(uint *)(iVar3 + 0x54) & 0x40000) == 0) {
    if (uVar4 == 0) {
      param_3[1] = (int)param_3;
      *param_3 = iVar3 + 0x180;
      param_3[1] = *(int *)(iVar3 + 0x184);
      **(undefined4 **)(iVar3 + 0x184) = param_3;
      *(int **)(iVar3 + 0x184) = param_3;
      param_3[10] = param_2;
      FUN_c054cc28(iVar3,1,0);
      uVar2 = 0x103;
      goto LAB_c05532a8;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  uVar2 = (**(code **)(*(int *)(iVar3 + 8) + 0x50))(*(undefined4 *)(iVar3 + 0xc),param_2,param_3);
  if ((*(uint *)(iVar3 + 0x54) & 0x40000) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
LAB_c05532a8:
  if ((*(uint *)(iVar3 + 0x54) & 0x40000) == 0) {
    if (uVar4 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x4b0));
      *(undefined4 *)(iVar3 + 0x454) = 0;
      *(undefined4 *)(iVar3 + 0x458) = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return uVar2;
}



/* c0553304 NdisMWanSendComplete */

/* Boundary evidence: original MIPS .pdata c0553304..c055339b. Semantic name remains unreviewed. */

void NdisMWanSendComplete(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
                    /* 0x13304  162  NdisMWanSendComplete */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  for (iVar1 = *(int *)(param_1 + 0x18); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    (**(code **)(*(int *)(iVar1 + 0xc) + 0x34))(*(undefined4 *)(iVar1 + 0x10),param_2,param_3);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c055339c FUN_c055339c */

/* Boundary evidence: original MIPS .pdata c055339c..c055345b. Semantic name remains unreviewed. */

undefined4 FUN_c055339c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  while (piVar2 = *(int **)(param_1 + 0x180), piVar2 != (int *)(param_1 + 0x180)) {
    *(int *)piVar2[1] = *piVar2;
    *(int *)(*piVar2 + 4) = piVar2[1];
    piVar2[1] = (int)piVar2;
    *piVar2 = (int)piVar2;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x50))
                      (*(undefined4 *)(param_1 + 0xc),piVar2[10],piVar2);
    if (iVar1 != 0x103) {
      NdisMWanSendComplete(param_1,piVar2,iVar1);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return 0;
}



/* c055345c FUN_c055345c */

/* Boundary evidence: original MIPS .pdata c055345c..c05535a7. Semantic name remains unreviewed. */

void FUN_c055345c(int *param_1,uint param_2,uint param_3,void *param_4,uint *param_5)

{
  int *piVar1;
  uint uVar2;
  void *_Src;
  uint _Size;
  uint uVar3;
  int *local_30;
  int local_2c;
  
  *param_5 = 0;
  uVar3 = 0;
  if (param_3 != 0) {
    NdisQueryPacket(param_1,(int *)0x0,&local_2c,(int *)&local_30,(int *)0x0);
    if (local_2c != 0) {
      if (local_30 == (int *)0x0) {
        _Src = (void *)0x0;
        uVar2 = 0;
      }
      else {
        _Src = (void *)local_30[1];
        uVar2 = local_30[2];
      }
      piVar1 = local_30;
      if (param_3 != 0) {
        do {
          if (uVar2 == 0) {
            local_30 = (int *)*piVar1;
            if (local_30 == (int *)0x0) break;
            _Src = (void *)local_30[1];
            uVar2 = local_30[2];
            piVar1 = local_30;
          }
          else {
            if (param_2 != 0) {
              if (uVar2 < param_2) {
                param_2 = param_2 - uVar2;
                uVar2 = 0;
                goto LAB_c055356c;
              }
              _Src = (void *)((int)_Src + param_2);
              uVar2 = uVar2 - param_2;
              param_2 = 0;
            }
            _Size = param_3 - uVar3;
            if (uVar2 <= param_3 - uVar3) {
              _Size = uVar2;
            }
            memmove(param_4,_Src,_Size);
            param_4 = (void *)(_Size + (int)param_4);
            _Src = (void *)(_Size + (int)_Src);
            uVar3 = _Size + uVar3;
            uVar2 = uVar2 - _Size;
            piVar1 = local_30;
          }
LAB_c055356c:
        } while (uVar3 < param_3);
      }
      *param_5 = uVar3;
    }
  }
  return;
}



/* c05535a8 NdisIMCopySendPerPacketInfo */

void NdisIMCopySendPerPacketInfo(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x135a8  88  NdisIMCopySendPerPacketInfo */
  iVar2 = (uint)*(ushort *)(param_2 + 0x1e) + param_2;
  iVar3 = (uint)*(ushort *)(param_1 + 0x1e) + param_1;
  *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar2 + 0x20);
  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
  *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar2 + 0x28);
  *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar2 + 0x2c);
  *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar2 + 0x38);
  *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(iVar2 + 0x40);
  bVar1 = *(byte *)(param_1 + 0x1d) & 0xc0;
  *(byte *)(param_1 + 0x1d) = bVar1;
  *(byte *)(param_1 + 0x1d) = *(byte *)(param_2 + 0x1d) & 0x3f | bVar1;
  return;
}



/* c0553608 NdisIMCopySendCompletePerPacketInfo */

void NdisIMCopySendCompletePerPacketInfo(int param_1,int param_2)

{
                    /* 0x13608  87  NdisIMCopySendCompletePerPacketInfo */
  *(undefined4 *)((uint)*(ushort *)(param_1 + 0x1e) + param_1 + 0x28) =
       *(undefined4 *)((uint)*(ushort *)(param_2 + 0x1e) + param_2 + 0x28);
  return;
}



/* c0553624 FUN_c0553624 */

/* Boundary evidence: original MIPS .pdata c0553624..c055368f. Semantic name remains unreviewed. */

void FUN_c0553624(int param_1,int *param_2,int param_3)

{
  if (*(code **)g_pLogNdisSendPackets_exref != (code *)0x0) {
    (**(code **)g_pLogNdisSendPackets_exref)(param_1,param_2,param_3);
  }
  FUN_c05527dc(param_1,param_2,param_3);
  return;
}



/* c0553690 FUN_c0553690 */

/* Boundary evidence: original MIPS .pdata c0553690..c05536eb. Semantic name remains unreviewed. */

void FUN_c0553690(int param_1,int param_2)

{
  if (*(code **)g_pLogNdisSend_exref != (code *)0x0) {
    (**(code **)g_pLogNdisSend_exref)(0,0,param_2);
  }
  FUN_c0552a84(param_1,param_2);
  return;
}



/* c05536ec FUN_c05536ec */

/* Boundary evidence: original MIPS .pdata c05536ec..c0553747. Semantic name remains unreviewed. */

void FUN_c05536ec(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0xa8))
                    (*(undefined4 *)(param_1 + 0x1c),param_2,*(undefined4 *)(param_2 + 0x18));
  if (iVar1 != 0x103) {
    FUN_c0552d48(*(undefined4 *)(param_1 + 8),param_2);
  }
  return;
}



/* c0553748 FUN_c0553748 */

/* Boundary evidence: original MIPS .pdata c0553748..c0553dc7. Semantic name remains unreviewed. */

bool FUN_c0553748(int param_1,int *param_2,int *param_3)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  short sVar8;
  uint uVar9;
  size_t _Size;
  void *_Dst;
  int iVar10;
  uint uVar11;
  size_t sVar12;
  int iVar13;
  ushort *puVar14;
  ushort *puVar15;
  uint local_38;
  int local_34;
  undefined4 local_30;
  uint uStack_2c;
  
  bVar6 = false;
  bVar7 = false;
  if ((param_2[2] == 0) || (puVar14 = *(ushort **)(param_2[2] + 4), puVar14 == (ushort *)0x0)) {
    if (param_3 == (int *)0x0) {
      return false;
    }
    goto LAB_c0553d8c;
  }
  if (*(int *)(param_1 + 0x11c) == 0) {
    if ((*(uint *)(param_1 + 0x54) & 0x800000) == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0xf8) + 4));
      iVar10 = *(int *)(param_1 + 0xf8);
      uVar9 = *(uint *)(iVar10 + 0x1c);
      bVar6 = false;
      bVar7 = false;
      if (((byte)*puVar14 & 1) == 0) {
        if ((*(int *)(puVar14 + 1) == *(int *)(iVar10 + 0x32)) &&
           (*puVar14 == *(ushort *)(iVar10 + 0x30))) {
          bVar7 = true;
          goto LAB_c0553b84;
        }
      }
      else {
        if (((byte)*puVar14 == 0xff) && (*(char *)((int)puVar14 + 1) == -1)) {
          uVar11 = uVar9 & 8;
        }
        else {
          if ((uVar9 & 4) != 0) goto LAB_c0553b84;
          if ((uVar9 & 2) == 0) goto LAB_c0553b88;
          uVar11 = FUN_c0542c1c(*(uint *)(*(int *)(param_1 + 0xf8) + 0x44),
                                *(int *)(*(int *)(param_1 + 0xf8) + 0x38),puVar14);
        }
        if (uVar11 != 0) {
LAB_c0553b84:
          bVar6 = true;
        }
      }
LAB_c0553b88:
      if ((uVar9 & 0xa0) != 0) {
        bVar6 = true;
      }
      iVar10 = *(int *)(param_1 + 0xf8);
LAB_c0553ba0:
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar10 + 4));
      goto LAB_c0553ba8;
    }
    if ((*puVar14 & 1) != 0) goto LAB_c0553a90;
    if (*(int *)(puVar14 + 1) == *(int *)(*(int *)(param_1 + 0xf8) + 0x32)) {
      sVar8 = *(short *)(*(int *)(param_1 + 0xf8) + 0x30);
      uVar1 = *(undefined1 *)((int)puVar14 + 1);
      uVar4 = (undefined1)*puVar14;
LAB_c0553a64:
      bVar6 = false;
      if (CONCAT11(uVar1,uVar4) != sVar8) goto LAB_c0553a78;
    }
    else {
LAB_c0553a78:
      bVar6 = true;
    }
    if (bVar6) {
LAB_c0553a90:
      bVar6 = true;
    }
    else {
      bVar6 = true;
      bVar7 = true;
    }
  }
  else if (*(int *)(param_1 + 0x11c) == 1) {
    if ((*(uint *)(param_1 + 0x54) & 0x800000) == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0xfc) + 4));
      puVar15 = puVar14 + 2;
      bVar2 = (byte)*puVar15;
      bVar3 = (byte)puVar14[1];
      iVar10 = *(int *)(param_1 + 0xfc);
      uVar9 = *(uint *)(iVar10 + 0x1c);
      bVar6 = false;
      bVar7 = false;
      if (((((bVar2 & bVar3 & 0x80) == 0) ||
           (CONCAT31(CONCAT21(CONCAT11(bVar2,*(undefined1 *)((int)puVar14 + 5)),(char)puVar14[3]),
                     *(undefined1 *)((int)puVar14 + 7)) != *(int *)(iVar10 + 0x3c))) ||
          (*(int *)(iVar10 + 0x40) == 0)) && (((puVar14[4] & 0x80) == 0 || ((uVar9 & 0x10) == 0))))
      {
        if ((bVar3 & 0x80) == 0) {
          if ((*(int *)puVar15 == *(int *)(iVar10 + 0x32)) &&
             (puVar14[1] == *(ushort *)(iVar10 + 0x30))) {
            bVar7 = true;
            goto LAB_c05539e4;
          }
        }
        else {
          if (((puVar14[1] != 0xffff) && (puVar14[1] != 0xc0)) ||
             (bVar5 = true, *(int *)puVar15 != -1)) {
            bVar5 = false;
          }
          if (bVar5) {
            uVar11 = uVar9 & 8;
          }
          else {
            if (((bVar3 & 0x80) == 0) || (bVar5 = true, (bVar2 & 0x80) != 0)) {
              bVar5 = false;
            }
            if ((!bVar5) || ((uVar9 & 0x6000) == 0)) goto LAB_c05539e8;
            uVar11 = CONCAT31(CONCAT21(CONCAT11((byte)*puVar15,*(undefined1 *)((int)puVar14 + 5)),
                                       (char)puVar14[3]),*(undefined1 *)((int)puVar14 + 7)) &
                     *(uint *)(iVar10 + 0x38);
          }
          if (uVar11 != 0) goto LAB_c05539e4;
        }
      }
      else {
LAB_c05539e4:
        bVar6 = true;
      }
LAB_c05539e8:
      if ((uVar9 & 0xa0) != 0) {
        bVar6 = true;
      }
      goto LAB_c0553ba0;
    }
    if ((puVar14[1] & 0x80) == 0) {
      if (*(int *)(puVar14 + 2) == *(int *)(*(int *)(param_1 + 0xfc) + 0x32)) {
        sVar8 = *(short *)(*(int *)(param_1 + 0xfc) + 0x30);
        uVar1 = *(undefined1 *)((int)puVar14 + 3);
        uVar4 = (undefined1)puVar14[1];
        goto LAB_c0553a64;
      }
      goto LAB_c0553a78;
    }
    goto LAB_c0553a90;
  }
LAB_c0553ba8:
  if ((bVar6) && ((param_2[6] & 0x200U) != 0)) {
    bVar7 = true;
  }
  if (bVar7) {
    *(byte *)((int)param_2 + 0x1d) = *(byte *)((int)param_2 + 0x1d) | 4;
  }
  if (!bVar6) {
    return (param_2[6] & 0x200U) != 0;
  }
  if ((char)param_2[7] == '\0') {
    NdisQueryPacket(param_2,(int *)0x0,(int *)0x0,(int *)0x0,(int *)&local_38);
  }
  else {
    local_38 = param_2[1];
  }
  _Size = NdisPacketSize(0x10);
  sVar12 = _Size + local_38;
  if (sVar12 < local_38) {
    local_34 = -0x3ffeffeb;
    sVar12 = 0xffffffff;
  }
  _Dst = FUN_c05427a0(sVar12);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,_Size);
    iVar10 = DAT_c05653bc;
    iVar13 = (int)_Dst + DAT_c05653bc * 0x28 + 8;
    *(undefined4 *)((int)_Dst + DAT_c05653bc * 0x28 + 4) = 0xffffffff;
    NdisAllocateBuffer(&local_34,&local_30,0,(void *)(_Size + (int)_Dst),local_38);
    if (local_34 == 0) {
      *(undefined4 *)((int)_Dst + iVar10 * 0x28 + 0x10) = local_30;
      *(undefined4 *)((int)_Dst + iVar10 * 0x28 + 0x14) = local_30;
      *(undefined4 *)((int)_Dst + iVar10 * 0x28 + 0x18) = 0x706f6f4c;
      *(short *)((int)_Dst + iVar10 * 0x28 + 0x26) =
           (short)_Size + (short)DAT_c05653bc * -0x28 + -0x54;
      FUN_c055345c(param_2,0,local_38,(void *)(_Size + (int)_Dst),&uStack_2c);
      if (param_3 != (int *)0x0) {
        *param_3 = iVar13;
        *(byte *)((int)_Dst + iVar10 * 0x28 + 0x25) =
             *(byte *)((int)_Dst + iVar10 * 0x28 + 0x25) | 2;
        *(uint *)((int)_Dst + iVar10 * 0x28 + 0x20) = param_2[6] & 0x80;
      }
      if (local_34 == 0) {
        return bVar7;
      }
    }
    CTEFreeMem(iVar13 + DAT_c05653bc * -0x28 + -8);
  }
LAB_c0553d8c:
  *param_3 = 0;
  return false;
}



/* c0553dc8 FUN_c0553dc8 */

/* Boundary evidence: original MIPS .pdata c0553dc8..c0553fbf. Semantic name remains unreviewed. */

undefined4 FUN_c0553dc8(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int local_30 [2];
  
  local_30[0] = 0;
  if ((*(byte *)((int)param_2 + 0x1d) & 0x20) == 0) {
    bVar1 = FUN_c0553748(param_1,param_2,local_30);
    uVar3 = 1;
    if (CONCAT31(extraout_var,bVar1) != 0) goto LAB_c0553e30;
  }
  uVar3 = 0;
LAB_c0553e30:
  if (local_30[0] != 0) {
    *(byte *)((int)param_2 + 0x1d) = *(byte *)((int)param_2 + 0x1d) | 0x20;
    iVar5 = (uint)*(ushort *)(local_30[0] + 0x1e) + local_30[0];
    if ((uint)param_2[-1] < DAT_c05653bc) {
      piVar4 = param_2 + (param_2[-1] - DAT_c05653bc) * 10 + -2;
    }
    else {
      piVar4 = (int *)0x0;
    }
    *(undefined4 *)(iVar5 + 0x1c) = 0xc000009a;
    *(int *)(local_30[0] + 0x20) = piVar4[2];
    if ((*(uint *)(param_1 + 0x54) & 0x40000) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    if (*(int *)(param_1 + 0x11c) == 0) {
      *(undefined4 *)(iVar5 + 0x10) = 0xe;
      FUN_c0543870(param_1,local_30,1);
    }
    else if (*(int *)(param_1 + 0x11c) == 1) {
      *(undefined4 *)(iVar5 + 0x10) = 0xe;
      iVar2 = NdisPacketSize(0x10);
      iVar2 = iVar2 + local_30[0] + DAT_c05653bc * -0x28 + -8;
      if ((*(byte *)(iVar2 + 8) & 0x80) != 0) {
        *(uint *)(iVar5 + 0x10) = (*(byte *)(iVar2 + 0xe) & 0x1f) + *(int *)(iVar5 + 0x10);
      }
      FUN_c055af14(param_1,local_30,1,param_4);
    }
    if ((*(uint *)(param_1 + 0x54) & 0x40000) == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    NdisFreeBuffer();
    local_30[0] = local_30[0] + DAT_c05653bc * -0x28 + -8;
    CTEFreeMem();
  }
  return uVar3;
}



/* c0553fc0 FUN_c0553fc0 */

/* Boundary evidence: original MIPS .pdata c0553fc0..c0554037. Semantic name remains unreviewed. */

void FUN_c0553fc0(int param_1,int param_2,int *param_3)

{
  if (*(code **)g_pLogTxNdisWanPacket_exref != (code *)0x0) {
    (**(code **)g_pLogTxNdisWanPacket_exref)
              (*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x58),
               *(undefined4 *)(*(int *)(param_1 + 0x24) + 4),&DAT_c054174c,param_3);
  }
  FUN_c055314c(param_1,param_2,param_3);
  return;
}



/* c0554038 FUN_c0554038 */

/* Boundary evidence: original MIPS .pdata c0554038..c05541cf. Semantic name remains unreviewed. */

void FUN_c0554038(int param_1,undefined4 *param_2,LONG param_3,int param_4)

{
  int iVar1;
  LONG LVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  code *pcVar7;
  undefined4 *puVar8;
  
  iVar1 = DAT_c05653c0;
  iVar6 = *(int *)(param_1 + 8);
  pcVar7 = *(code **)(iVar6 + 0x42c);
  LVar2 = param_3;
  InterlockedExchangeAdd((LONG *)(param_1 + 0x80),param_3);
  puVar8 = param_2 + param_3;
  puVar4 = param_2;
  if (param_2 < puVar8) {
    do {
      piVar5 = (int *)*param_2;
      iVar3 = piVar5[-1];
      piVar5[-1] = iVar3 + 1;
      *(int *)((int)piVar5 + ((iVar3 + 1) * 0x28 - iVar1) + 8) = param_1;
      *(byte *)((int)piVar5 + 0x1d) = *(byte *)((int)piVar5 + 0x1d) & 0xfb;
      if ((((*(uint *)(iVar6 + 0x54) & 0x4000) == 0) &&
          (((*(uint *)(iVar6 + 0x54) & 0x8800000) == 0 || ((piVar5[6] & 0x80U) != 0)))) ||
         (FUN_c0553dc8(iVar6,piVar5,LVar2,param_4), (*(byte *)((int)piVar5 + 0x1d) & 4) == 0)) {
        *(byte *)((int)piVar5 + 0x1d) = *(byte *)((int)piVar5 + 0x1d) | 0x10;
        if (pcVar7 == (code *)0x0) {
          FUN_c05536ec(param_1,(int)piVar5);
          goto LAB_c0554170;
        }
      }
      else {
        LVar2 = 0;
        FUN_c0552d48(iVar6,(int)piVar5);
        if (puVar4 < param_2) {
          LVar2 = (int)param_2 - (int)puVar4 >> 2;
          (*pcVar7)(*(undefined4 *)(iVar6 + 0xc),puVar4);
        }
LAB_c0554170:
        puVar4 = param_2 + 1;
      }
      param_2 = param_2 + 1;
    } while (param_2 < puVar8);
    if (puVar4 < param_2) {
      (*pcVar7)(*(undefined4 *)(iVar6 + 0xc),puVar4,(int)param_2 - (int)puVar4 >> 2);
    }
  }
  return;
}



/* c05541d0 FUN_c05541d0 */

/* Boundary evidence: original MIPS .pdata c05541d0..c0554377. Semantic name remains unreviewed. */

undefined4 FUN_c05541d0(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *local_res4 [3];
  
  iVar2 = *(int *)(param_1 + 8);
  *(byte *)((int)param_2 + 0x1d) = *(byte *)((int)param_2 + 0x1d) & 0xfb;
  *(undefined4 *)((int)param_2 + *(ushort *)((int)param_2 + 0x1e) + 0x34) = 0;
  param_2[-1] = param_2[-1] + 1;
  if ((uint)param_2[-1] < DAT_c05653bc) {
    piVar3 = param_2 + (param_2[-1] - DAT_c05653bc) * 10 + -2;
  }
  else {
    piVar3 = (int *)0x0;
  }
  piVar3[2] = param_1;
  local_res4[0] = param_2;
  NdisInterlockedIncrement((LONG *)(param_1 + 0x80));
  if (((*(uint *)(iVar2 + 0x54) & 0x4000) != 0) ||
     (((local_res4[0][6] & 0x80U) == 0 && ((*(uint *)(iVar2 + 0x54) & 0x8800000) != 0)))) {
    FUN_c0553dc8(iVar2,local_res4[0],param_3,param_4);
  }
  if ((*(byte *)((int)local_res4[0] + 0x1d) & 4) == 0) {
    uVar4 = 0x103;
    if ((*(byte *)(iVar2 + 0x254) & 1) == 0) {
      *(byte *)((int)local_res4[0] + 0x1d) = *(byte *)((int)local_res4[0] + 0x1d) | 0x10;
      iVar1 = (**(code **)(param_1 + 0xa8))
                        (*(undefined4 *)(param_1 + 0x1c),local_res4[0],local_res4[0][6]);
      if (iVar1 != 0x103) {
        FUN_c0552d48(iVar2,(int)local_res4[0]);
      }
    }
    else {
      (**(code **)(param_1 + 0xb0))(*(undefined4 *)(iVar2 + 0xc),local_res4,1);
    }
  }
  else {
    NdisInterlockedDecrement((LONG *)(param_1 + 0x80));
    piVar3[3] = 0;
    uVar4 = 0;
    local_res4[0][-1] = local_res4[0][-1] + -1;
    *(byte *)((int)local_res4[0] + 0x1d) = *(byte *)((int)local_res4[0] + 0x1d) & 0xc0;
  }
  return uVar4;
}



/* c0554378 FUN_c0554378 */

/* Boundary evidence: original MIPS .pdata c0554378..c05546d3. Semantic name remains unreviewed. */

undefined4 FUN_c0554378(int param_1,undefined4 param_2,uint *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  uint *puVar8;
  int *piVar9;
  code *pcVar10;
  int local_68 [16];
  
  uVar1 = *(ushort *)(param_1 + 0x1de);
  pcVar10 = *(code **)(param_1 + 0x42c);
  if (((*(uint *)(param_1 + 0x54) & 0x400000) == 0) && (*(int *)(param_1 + 0x188) == 0)) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x400000;
  }
  piVar9 = (int *)(param_1 + 0x180);
  if ((int *)*piVar9 == piVar9) {
    *(undefined4 *)(param_1 + 0x188) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x188);
  do {
    if ((iVar2 == 0) || ((*(uint *)(param_1 + 0x54) & 0x400000) == 0)) {
      return 0;
    }
    piVar3 = local_68;
    puVar8 = (uint *)0x0;
    if ((uint *)(uint)uVar1 == (uint *)0x0) {
      return 0;
    }
    do {
      piVar6 = *(int **)(param_1 + 0x188);
      if (piVar6 == (int *)0x0) break;
      if ((uint)piVar6[-1] < DAT_c05653bc) {
        piVar4 = piVar6 + (piVar6[-1] - DAT_c05653bc) * 10 + -2;
      }
      else {
        piVar4 = (int *)0x0;
      }
      *(undefined4 *)(param_1 + 0x188) = 0;
      puVar7 = (uint *)(piVar4 + 2);
      if ((int *)piVar6[10] != piVar9) {
        *(int **)(param_1 + 0x188) = (int *)piVar6[10] + -10;
      }
      if (((*(uint *)(param_1 + 0x54) & 0x4000) == 0) &&
         (((piVar6[6] & 0x80U) != 0 || ((*(uint *)(param_1 + 0x54) & 0x8800000) == 0)))) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_c0553dc8(param_1,piVar6,param_3,param_4);
      }
      if (iVar2 == 0) {
        *piVar3 = (int)piVar6;
        *(byte *)((int)piVar6 + 0x1d) = *(byte *)((int)piVar6 + 0x1d) | 0x18;
        puVar8 = (uint *)((int)puVar8 + 1);
        piVar3 = piVar3 + 1;
        *(undefined4 *)((int)piVar6 + *(ushort *)((int)piVar6 + 0x1e) + 0x1c) = 0;
      }
      else {
        param_4 = 0;
        FUN_c055267c(param_1,(int)piVar6,(int *)puVar7,0,'\x01',2);
        param_3 = puVar7;
      }
    } while (puVar8 < (uint *)(uint)uVar1);
    if (puVar8 == (uint *)0x0) {
      return 0;
    }
    piVar3 = local_68;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    param_3 = puVar8;
    (*pcVar10)(*(undefined4 *)(param_1 + 0xc),local_68);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    puVar7 = (uint *)0x0;
    if (puVar8 != (uint *)0x0) {
      do {
        iVar2 = *piVar3;
        param_4 = *(int *)((uint)*(ushort *)(iVar2 + 0x1e) + iVar2 + 0x1c);
        *(byte *)(iVar2 + 0x1d) = *(byte *)(iVar2 + 0x1d) & 0xf7;
        if (param_4 != 0x103) {
          if (param_4 == -0x3fffff66) {
            *(int *)(param_1 + 0x188) = iVar2;
            *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xffbfffff;
            if (puVar7 < puVar8) {
              piVar3 = local_68 + (int)puVar7;
              iVar2 = (int)puVar8 - (int)puVar7;
              do {
                iVar5 = *piVar3;
                piVar3 = piVar3 + 1;
                iVar2 = iVar2 + -1;
                *(byte *)(iVar5 + 0x1d) = *(byte *)(iVar5 + 0x1d) & 0xef;
              } while (iVar2 != 0);
            }
            break;
          }
          if (*(uint *)(iVar2 + -4) < DAT_c05653bc) {
            iVar5 = (*(uint *)(iVar2 + -4) - DAT_c05653bc) * 0x28 + iVar2 + -8;
          }
          else {
            iVar5 = 0;
          }
          param_3 = (uint *)(iVar5 + 8);
          if ((*param_3 & 0xffffff00) != 0x4d4f4300) {
            FUN_c055267c(param_1,iVar2,(int *)param_3,param_4,'\x01',3);
          }
        }
        puVar7 = (uint *)((int)puVar7 + 1);
        piVar3 = piVar3 + 1;
      } while (puVar7 < puVar8);
    }
    iVar2 = *(int *)(param_1 + 0x188);
  } while( true );
}



/* c05546d4 FUN_c05546d4 */

/* Boundary evidence: original MIPS .pdata c05546d4..c05548a7. Semantic name remains unreviewed. */

undefined4 FUN_c05546d4(int param_1,undefined4 param_2,int *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  iVar3 = *(int *)(param_1 + 0x188);
  do {
    if ((iVar3 == 0) || (uVar4 = *(uint *)(param_1 + 0x54), (uVar4 & 0x400000) == 0)) {
      return 0;
    }
    piVar6 = *(int **)(param_1 + 0x188);
    if ((uint)piVar6[-1] < DAT_c05653bc) {
      piVar5 = piVar6 + (piVar6[-1] - DAT_c05653bc) * 10 + -2;
    }
    else {
      piVar5 = (int *)0x0;
    }
    *(undefined4 *)(param_1 + 0x188) = 0;
    piVar5 = piVar5 + 2;
    if (piVar6[10] != param_1 + 0x180) {
      *(int *)(param_1 + 0x188) = piVar6[10] + -0x28;
    }
    iVar3 = *piVar5;
    if (((uVar4 & 0x4000) == 0) && (((piVar6[6] & 0x80U) != 0 || ((uVar4 & 0x8800000) == 0)))) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_c0553dc8(param_1,piVar6,param_3,param_4);
    }
    if (iVar2 == 0) {
      param_3 = (int *)piVar6[6];
      *(byte *)((int)piVar6 + 0x1d) = *(byte *)((int)piVar6 + 0x1d) | 0x10;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      iVar2 = (**(code **)(iVar3 + 0xa8))(*(undefined4 *)(iVar3 + 0x1c),piVar6);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      iVar3 = param_4;
      if (iVar2 != 0x103) goto LAB_c0554810;
    }
    else {
      iVar3 = param_4;
      iVar2 = 0;
LAB_c0554810:
      param_4 = iVar2;
      bVar1 = *(byte *)((int)piVar6 + 0x1d);
      *(byte *)((int)piVar6 + 0x1d) = bVar1 & 0xef;
      if (param_4 == -0x3fffff66) {
        *(byte *)((int)piVar6 + 0x1d) = bVar1 & 0xef;
        *(int **)(param_1 + 0x188) = piVar6;
        *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xffbfffff;
        param_4 = iVar3;
      }
      else {
        FUN_c055267c(param_1,(int)piVar6,piVar5,param_4,'\x01',4);
        param_3 = piVar5;
      }
    }
    iVar3 = *(int *)(param_1 + 0x188);
  } while( true );
}



/* c05548a8 FUN_c05548a8 */

/* Boundary evidence: original MIPS .pdata c05548a8..c0554913. Semantic name remains unreviewed. */

void FUN_c05548a8(int param_1,undefined4 *param_2,LONG param_3,int param_4)

{
  if (*(code **)g_pLogNdisSendPackets_exref != (code *)0x0) {
    (**(code **)g_pLogNdisSendPackets_exref)(param_1,param_2,param_3);
  }
  FUN_c0554038(param_1,param_2,param_3,param_4);
  return;
}



/* c0554914 FUN_c0554914 */

/* Boundary evidence: original MIPS .pdata c0554914..c055496f. Semantic name remains unreviewed. */

void FUN_c0554914(int param_1,int *param_2,int *param_3,int param_4)

{
  if (*(code **)g_pLogNdisSend_exref != (code *)0x0) {
    param_3 = param_2;
    (**(code **)g_pLogNdisSend_exref)(0,0);
  }
  FUN_c05541d0(param_1,param_2,param_3,param_4);
  return;
}



/* c0554970 NdisInitializeWrapper */

/* Boundary evidence: original MIPS .pdata c0554970..c0554a1f. Semantic name remains unreviewed. */

void NdisInitializeWrapper(undefined4 *param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  undefined4 *_Dst;
  
                    /* 0x14970  109  NdisInitializeWrapper */
  *param_1 = 0;
  uVar1 = *param_3;
  _Dst = FUN_c05427a0(uVar1 + 0xe);
  if (_Dst != (undefined4 *)0x0) {
    *param_1 = _Dst;
    memset(_Dst,0,uVar1 + 0xe);
    *_Dst = param_2;
    _Dst[2] = _Dst + 3;
    uVar1 = *param_3;
    *(ushort *)(_Dst + 1) = uVar1;
    *(ushort *)((int)_Dst + 6) = uVar1 + 2;
    memcpy(_Dst + 3,*(void **)(param_3 + 2),(uint)*(ushort *)(_Dst + 1));
  }
  return;
}



/* c0554a20 NdisTerminateWrapper */

/* Boundary evidence: original MIPS .pdata c0554a20..c0554aab. Semantic name remains unreviewed. */

void NdisTerminateWrapper(int *param_1)

{
  ushort uVar1;
  int iVar2;
  
                    /* 0x14a20  211  NdisTerminateWrapper */
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    iVar2 = FUN_c0561324(*param_1);
    if (iVar2 == 0) {
      CTEFreeMem(param_1);
    }
    else {
      uVar1 = *(ushort *)(iVar2 + 0xb8);
      *(ushort *)(iVar2 + 0xb8) = uVar1 | 4;
      if ((*(int *)(iVar2 + 4) == 0) && ((uVar1 & 0x8000) == 0)) {
        *(undefined4 *)(iVar2 + 0x1c) = 0;
        *(ushort *)(iVar2 + 0xb8) = uVar1 | 0x14;
        FUN_c0559240(*param_1);
      }
    }
  }
  return;
}



/* c0554aac NdisMSetTimer */

/* Boundary evidence: original MIPS .pdata c0554aac..c0554ac7. Semantic name remains unreviewed. */

void NdisMSetTimer(int *param_1,int param_2)

{
                    /* 0x14aac  154  NdisMSetTimer */
  FUN_c0560db4(param_1,param_2,(int)(param_1 + 8));
  return;
}



/* c0554ac8 NdisMCancelTimer */

/* Boundary evidence: original MIPS .pdata c0554ac8..c0554b0b. Semantic name remains unreviewed. */

void NdisMCancelTimer(int *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
                    /* 0x14ac8  118  NdisMCancelTimer */
  if ((*(uint *)(param_1[0x12] + 0x408) & 8) == 0) {
    uVar1 = FUN_c0560bd8(param_1);
    *param_2 = (char)uVar1;
  }
  else {
    *param_2 = 0;
  }
  return;
}



/* c0554b0c FUN_c0554b0c */

/* Boundary evidence: original MIPS .pdata c0554b0c..c0554c03. Semantic name remains unreviewed. */

void FUN_c0554b0c(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = param_2[0x12];
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  FUN_c054b758(iVar2);
  if ((*(uint *)(iVar2 + 0x54) & 2) == 0) {
    if ((*(uint *)(iVar2 + 0x248) & 0x1000000) == 0) {
      pcVar1 = (code *)param_2[0x10];
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      (*pcVar1)(0,param_2[0x11],0,0);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      FUN_c054eae0(iVar2);
    }
  }
  else {
    FUN_c0560db4(param_2,10,(int)(param_2 + 8));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x4b0));
  *(undefined4 *)(iVar2 + 0x454) = 0;
  *(undefined4 *)(iVar2 + 0x458) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  return;
}



/* c0554c04 FUN_c0554c04 */

/* Boundary evidence: original MIPS .pdata c0554c04..c0554c9b. Semantic name remains unreviewed. */

void FUN_c0554c04(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_2 + 0x48);
  piVar2 = *(int **)(iVar1 + 8);
  FUN_c055a404((int)(piVar2 + 0x28));
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  if ((*(uint *)(iVar1 + 0x248) & 0x1000000) == 0) {
    (**(code **)(param_2 + 0x40))(0,*(undefined4 *)(param_2 + 0x44),0,0);
  }
  FUN_c055915c(piVar2,0);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  return;
}



/* c0554c9c NdisMDeregisterInterrupt */

/* Boundary evidence: original MIPS .pdata c0554c9c..c0554daf. Semantic name remains unreviewed. */

void NdisMDeregisterInterrupt(int *param_1)

{
  int *piVar1;
  
                    /* 0x14c9c  123  NdisMDeregisterInterrupt */
  if ((*(int *)(param_1[0x11] + 0x124) == -2) || (*param_1 != 0)) {
    *(uint *)(param_1[0x11] + 0x54) = *(uint *)(param_1[0x11] + 0x54) | 0x20;
    if (*(int *)(param_1[0x11] + 0x124) == -2) {
      FUN_c055e1cc(param_1[0x11]);
    }
    else {
      piVar1 = (int *)*param_1;
      if ((piVar1 != (int *)0x0) && (*piVar1 == 0xe)) {
        (&DAT_c05656e0)[piVar1[6]] = 0;
      }
      FUN_c0561ca8((int *)*param_1);
    }
    if ((char)param_1[0x12] != '\0') {
      WaitForSingleObject((HANDLE)param_1[0x13],1000);
      EventModify(param_1[0x13],2);
    }
    CloseHandle((HANDLE)param_1[0x13]);
    *(undefined4 *)(param_1[0x11] + 0x50) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    if ((LPCRITICAL_SECTION)param_1[6] != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection((LPCRITICAL_SECTION)param_1[6]);
      CTEFreeMem(param_1[6]);
    }
  }
  return;
}



/* c0554db0 FUN_c0554db0 */

/* Boundary evidence: original MIPS .pdata c0554db0..c0554e93. Semantic name remains unreviewed. */

undefined4 FUN_c0554db0(int *param_1,undefined *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  if (piVar3 == (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)param_1[6]);
  }
  else if (*piVar3 == 0xe) {
    FUN_c0561648((int)piVar3,1);
  }
  else {
    InterruptMask();
  }
  uVar1 = (*(code *)param_2)(param_3);
  if (piVar3 == (int *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)param_1[6]);
  }
  else {
    iVar2 = *(int *)*param_1;
    if (iVar2 == 0xe) {
      FUN_c0561648(*param_1,0);
    }
    else {
      InterruptMask(iVar2);
    }
  }
  return uVar1;
}



/* c0554e94 NdisMSynchronizeWithInterrupt */

/* Boundary evidence: original MIPS .pdata c0554e94..c0554eaf. Semantic name remains unreviewed. */

void NdisMSynchronizeWithInterrupt(int *param_1,undefined *param_2,undefined4 param_3)

{
                    /* 0x14e94  157  NdisMSynchronizeWithInterrupt */
  FUN_c0554db0(param_1,param_2,param_3);
  return;
}



/* c0554eb0 FUN_c0554eb0 */

/* Boundary evidence: original MIPS .pdata c0554eb0..c0554fef. Semantic name remains unreviewed. */

void FUN_c0554eb0(int param_1)

{
  bool bVar1;
  int iVar2;
  byte local_18 [8];
  
  bVar1 = false;
  local_18[0] = 0;
  if (((*(uint *)(param_1 + 0x54) & 0x200000) == 0) && ((*(uint *)(param_1 + 0x248) & 0x80000) == 0)
     ) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x200000;
    *(undefined4 *)(param_1 + 0x1c0) = 0;
  }
  else {
    bVar1 = true;
  }
  FUN_c054e23c(param_1,0xc001000d,1);
  if (bVar1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x43c);
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x80000;
    while (iVar2 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      Sleep(1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      iVar2 = *(int *)(param_1 + 0x43c);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    NdisMIndicateStatus(param_1,0x40010004,(uint *)0x0,0);
    NdisMIndicateStatusComplete(param_1);
    iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(local_18,*(undefined4 *)(param_1 + 0xc));
    if (iVar2 != 0x103) {
      NdisMResetComplete(param_1,iVar2,(uint)local_18[0]);
    }
  }
  return;
}



/* c0554ff0 FUN_c0554ff0 */

/* Boundary evidence: original MIPS .pdata c0554ff0..c055519f. Semantic name remains unreviewed. */

void FUN_c0554ff0(undefined4 param_1,int param_2)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  if ((*(uint *)(param_2 + 0x54) & 0x80000000) == 0) {
    sVar1 = *(short *)(param_2 + 0x1ba) + -1;
    *(short *)(param_2 + 0x1ba) = sVar1;
    if (sVar1 == 0) {
      *(undefined2 *)(param_2 + 0x1ba) = *(undefined2 *)(param_2 + 0x1b8);
      pcVar2 = *(code **)(*(int *)(param_2 + 8) + 0x28);
      if (pcVar2 != (code *)0x0) {
        iVar4 = (*pcVar2)(*(undefined4 *)(param_2 + 0xc));
      }
      if ((*(uint *)(param_2 + 0x54) & 0x1000000) != 0) goto LAB_c0555178;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      if (iVar4 == 0) {
        uVar3 = *(uint *)(param_2 + 0x54);
        if (((uVar3 & 0x1000) == 0) && ((uVar3 & 0x400) != 0)) {
          if ((uVar3 & 0x100) == 0) {
            if (*(short *)(param_2 + 0x43a) == 0) {
              *(uint *)(param_2 + 0x54) = uVar3 | 0x100;
            }
            else {
              *(short *)(param_2 + 0x43a) = *(short *)(param_2 + 0x43a) + -1;
            }
          }
          else {
            *(short *)(param_2 + 0x410) = *(short *)(param_2 + 0x410) + 1;
            iVar4 = 1;
          }
        }
      }
      else {
        *(short *)(param_2 + 0x412) = *(short *)(param_2 + 0x412) + 1;
      }
      if (*(int *)(*(int *)(param_2 + 8) + 0x4c) == 0) {
        iVar4 = 0;
      }
      if (iVar4 == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      }
      else {
        FUN_c0554eb0(param_2);
      }
    }
    if ((iVar4 == 0) && ((*(uint *)(param_2 + 0x54) & 0x2000000) != 0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      FUN_c05589f4(param_2);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
  }
LAB_c0555178:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  return;
}



/* c05551a0 FUN_c05551a0 */

/* Boundary evidence: original MIPS .pdata c05551a0..c05554b3. Semantic name remains unreviewed. */

void FUN_c05551a0(undefined4 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  short sVar5;
  int *piVar6;
  int iVar7;
  
  iVar7 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((*(uint *)(param_2 + 0x54) & 0x80000000) != 0) goto LAB_c0555480;
  iVar2 = __GetUserKData(8);
  uVar3 = (uint)(*(int *)(param_2 + 0x4b4) != iVar2);
  if (uVar3 == 1) {
    uVar3 = TryEnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x4b0));
    uVar3 = uVar3 & 0xff;
    if (uVar3 == 1) {
      *(undefined4 *)(param_2 + 0x454) = 0xa04f8;
      uVar4 = __GetUserKData(8);
      *(undefined4 *)(param_2 + 0x458) = uVar4;
    }
  }
  if (uVar3 == 0) goto LAB_c0555480;
  if ((*(uint *)(param_2 + 0x54) & 0x300000) == 0) {
    sVar5 = *(short *)(param_2 + 0x1ba) + -1;
    *(short *)(param_2 + 0x1ba) = sVar5;
    if (sVar5 == 0) {
      *(undefined2 *)(param_2 + 0x1ba) = *(undefined2 *)(param_2 + 0x1b8);
      if (*(int *)(*(int *)(param_2 + 8) + 0x28) != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        iVar7 = (**(code **)(*(int *)(param_2 + 8) + 0x28))(*(undefined4 *)(param_2 + 0xc));
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      }
      uVar3 = *(uint *)(param_2 + 0x54);
      if ((uVar3 & 0x1000000) != 0) goto LAB_c0555470;
      if (iVar7 == 0) {
        if ((uVar3 & 0x1400) == 0x400) {
          if ((uVar3 & 0x100) == 0) {
            if (*(short *)(param_2 + 0x43a) == 0) {
              *(uint *)(param_2 + 0x54) = uVar3 | 0x100;
            }
            else {
              *(short *)(param_2 + 0x43a) = *(short *)(param_2 + 0x43a) + -1;
            }
            goto LAB_c0555348;
          }
          *(short *)(param_2 + 0x410) = *(short *)(param_2 + 0x410) + 1;
LAB_c055531c:
          iVar7 = 1;
          goto LAB_c05553fc;
        }
LAB_c0555348:
        if ((*(uint *)(param_2 + 0x54) & 0x800) != 0) {
LAB_c05553b8:
          if ((*(uint *)(param_2 + 0x54) & 0x2000) == 0) {
            bVar1 = *(byte *)(param_2 + 0x255);
            if (bVar1 == 1) {
              *(short *)(param_2 + 0x410) = *(short *)(param_2 + 0x410) + 1;
              goto LAB_c055531c;
            }
            if (1 < bVar1) {
              *(byte *)(param_2 + 0x255) = bVar1 - 1;
            }
          }
          goto LAB_c05553fc;
        }
        piVar6 = *(int **)(param_2 + 0x180);
        if (((piVar6 == (int *)(param_2 + 0x180)) || (piVar6 == (int *)0x28)) ||
           (bVar1 = *(byte *)((int)piVar6 + -0xb), (bVar1 & 0x10) == 0)) goto LAB_c05553fc;
        if ((bVar1 & 1) == 0) {
          *(byte *)((int)piVar6 + -0xb) = bVar1 | 1;
        }
        else {
          *(short *)(param_2 + 0x410) = *(short *)(param_2 + 0x410) + 1;
          iVar7 = 1;
        }
        if (iVar7 == 0) goto LAB_c05553b8;
LAB_c0555404:
        if (((*(uint *)(param_2 + 0x54) & 0x1000000) == 0) &&
           (*(int *)(*(int *)(param_2 + 8) + 0x4c) != 0)) {
          FUN_c054cc28(param_2,3,0);
        }
        goto LAB_c0555434;
      }
      *(short *)(param_2 + 0x412) = *(short *)(param_2 + 0x412) + 1;
LAB_c05553fc:
      if (iVar7 != 0) goto LAB_c0555404;
LAB_c055543c:
      if ((*(uint *)(param_2 + 0x54) & 0x2000000) != 0) {
        FUN_c05589f4(param_2);
      }
    }
    else {
LAB_c0555434:
      if (iVar7 == 0) goto LAB_c055543c;
    }
    FUN_c054eae0(param_2);
  }
  else if (uVar3 == 0) goto LAB_c0555480;
LAB_c0555470:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x4b0));
  *(undefined4 *)(param_2 + 0x454) = 0;
  *(undefined4 *)(param_2 + 0x458) = 0;
LAB_c0555480:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  return;
}



/* c05554b4 FUN_c05554b4 */

/* Boundary evidence: original MIPS .pdata c05554b4..c055565f. Semantic name remains unreviewed. */

void FUN_c05554b4(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  HANDLE hHandle;
  
  hHandle = (HANDLE)param_1[1];
  uVar1 = *param_1;
  pcVar3 = *(code **)(param_2 + 0x20);
  iVar5 = *(int *)(param_2 + 0x44);
  pcVar4 = *(code **)(*(int *)(iVar5 + 8) + 0x2c);
  uVar2 = *(undefined4 *)(iVar5 + 0xc);
  do {
    (*pcVar4)(uVar2);
    InterruptDone(uVar1);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
    if ((*(uint *)(iVar5 + 0x54) & 0x80000020) == 0) {
      (*pcVar3)(uVar2);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
    WaitForSingleObject(hHandle,0xffffffff);
  } while (*(char *)(param_1 + 5) != '\0');
  EventModify(*(undefined4 *)(param_2 + 0x4c),3);
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* c0555660 FUN_c0555660 */

/* Boundary evidence: original MIPS .pdata c0555660..c055566b. Semantic name remains unreviewed. */

undefined4 FUN_c0555660(void)

{
  return 1;
}



/* c055566c FUN_c055566c */

/* Boundary evidence: original MIPS .pdata c055566c..c05557e3. Semantic name remains unreviewed. */

undefined1 FUN_c055566c(undefined4 param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  char local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  
  iVar3 = param_2[0x11];
  local_20 = '\0';
  if ((*(uint *)(iVar3 + 0x54) & 1) == 0) {
    bVar1 = *param_2 == 0;
    local_1e = bVar1;
    if (bVar1) {
      EnterCriticalSection((LPCRITICAL_SECTION)param_2[6]);
    }
    (*(code *)param_2[7])(&local_1f,&local_20,*(undefined4 *)(iVar3 + 0xc));
    if (bVar1) {
      LeaveCriticalSection((LPCRITICAL_SECTION)param_2[6]);
    }
  }
  else {
    (**(code **)(*(int *)(iVar3 + 8) + 0x2c))(*(undefined4 *)(iVar3 + 0xc));
    local_20 = '\x01';
    local_1f = 1;
  }
  piVar2 = (int *)*param_2;
  if (piVar2 != (int *)0x0) {
    if (*piVar2 == 0xe) {
      FUN_c0561598((int)piVar2);
    }
    else {
      InterruptDone(*piVar2);
    }
  }
  if (local_20 != '\0') {
    InterlockedIncrement(param_2 + 0x12);
    (*(code *)param_2[0xc])(param_2[0xd]);
  }
  return local_1f;
}



/* c05557e4 FUN_c05557e4 */

/* Boundary evidence: original MIPS .pdata c05557e4..c05557ef. Semantic name remains unreviewed. */

undefined4 FUN_c05557e4(void)

{
  return 1;
}



/* c05557f0 FUN_c05557f0 */

/* Boundary evidence: original MIPS .pdata c05557f0..c05557fb. Semantic name remains unreviewed. */

undefined4 FUN_c05557f0(void)

{
  return 1;
}



/* c05557fc FUN_c05557fc */

/* Boundary evidence: original MIPS .pdata c05557fc..c0555917. Semantic name remains unreviewed. */

void FUN_c05557fc(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *(int *)(param_1 + 0x44);
  pcVar2 = *(code **)(param_1 + 0x20);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((*(uint *)(iVar1 + 0x54) & 0x80000020) == 0) {
    FUN_c054b758(iVar1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    (*pcVar2)(*(undefined4 *)(iVar1 + 0xc));
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    InterlockedDecrement((LONG *)(param_1 + 0x48));
    if ((*(int **)(iVar1 + 0x50) != (int *)0x0) &&
       (*(undefined **)(iVar1 + 0x174) != (undefined *)0x0)) {
      FUN_c0554db0(*(int **)(iVar1 + 0x50),*(undefined **)(iVar1 + 0x174),
                   *(undefined4 *)(iVar1 + 0xc));
    }
    FUN_c054eae0(iVar1);
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x4b0));
    *(undefined4 *)(iVar1 + 0x454) = 0;
    *(undefined4 *)(iVar1 + 0x458) = 0;
  }
  else {
    InterlockedDecrement((LONG *)(param_1 + 0x48));
    if (*(char *)(param_1 + 0x48) == '\0') {
      EventModify(*(undefined4 *)(param_1 + 0x4c),3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  return;
}



/* c0555918 FUN_c0555918 */

/* Boundary evidence: original MIPS .pdata c0555918..c05559e3. Semantic name remains unreviewed. */

void FUN_c0555918(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *(int *)(param_1 + 0x44);
  pcVar2 = *(code **)(param_1 + 0x20);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  if ((*(uint *)(iVar1 + 0x54) & 0x80000020) == 0) {
    (*pcVar2)(*(undefined4 *)(iVar1 + 0xc));
    InterlockedDecrement((LONG *)(param_1 + 0x48));
    if ((*(int **)(iVar1 + 0x50) != (int *)0x0) &&
       (*(undefined **)(iVar1 + 0x174) != (undefined *)0x0)) {
      FUN_c0554db0(*(int **)(iVar1 + 0x50),*(undefined **)(iVar1 + 0x174),
                   *(undefined4 *)(iVar1 + 0xc));
    }
  }
  else {
    InterlockedDecrement((LONG *)(param_1 + 0x48));
    if (*(char *)(param_1 + 0x48) == '\0') {
      EventModify(*(undefined4 *)(param_1 + 0x4c),3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  return;
}



/* c05559e4 FUN_c05559e4 */

/* Boundary evidence: original MIPS .pdata c05559e4..c0555a63. Semantic name remains unreviewed. */

void FUN_c05559e4(undefined4 param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  FUN_c054b758(param_2);
  FUN_c054eae0(param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x4b0));
  *(undefined4 *)(param_2 + 0x454) = 0;
  *(undefined4 *)(param_2 + 0x458) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05656c0);
  return;
}



/* c0555a64 NdisMInitializeTimer */

/* Boundary evidence: original MIPS .pdata c0555a64..c0555aef. Semantic name remains unreviewed. */

void NdisMInitializeTimer(int *param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  
                    /* 0x15a64  131  NdisMInitializeTimer */
  FUN_c0560c90(param_1);
  param_1[0x12] = param_2;
  param_1[0x10] = param_3;
  param_1[0x11] = param_4;
  if ((*(uint *)(param_2 + 0x54) & 0x40000) == 0) {
    pcVar1 = FUN_c0554b0c;
  }
  else {
    pcVar1 = FUN_c0554c04;
  }
  FUN_c0561494((int)(param_1 + 8),pcVar1,param_1);
  return;
}



/* c0555af0 FUN_c0555af0 */

/* Boundary evidence: original MIPS .pdata c0555af0..c0555b4f. Semantic name remains unreviewed. */

void FUN_c0555af0(uint param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_c05656e0;
  while( true ) {
    if ((param_1 & 1) != 0) {
      FUN_c055566c(0,*(int **)(*piVar1 + 0x50));
    }
    param_1 = param_1 >> 1;
    if (param_1 == 0) break;
    piVar1 = piVar1 + 1;
  }
  return;
}



/* c0555b50 NdisMRegisterInterrupt */

/* Boundary evidence: original MIPS .pdata c0555b50..c0555e07. Semantic name remains unreviewed. */

int NdisMRegisterInterrupt
              (int *param_1,int param_2,uint param_3,undefined4 param_4,char param_5,char param_6)

{
  LPCRITICAL_SECTION lpCriticalSection;
  HANDLE pvVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined4 in_stack_fffffdb0;
  wchar_t awStack_238 [260];
  uint local_30;
  
                    /* 0x15b50  141  NdisMRegisterInterrupt */
  local_30 = DAT_c05653c8;
  if ((*(uint *)(param_2 + 0x408) & 2) != 0) {
    FUN_c05625b0(DAT_c05653c8);
    return -0x3fffff66;
  }
  iVar4 = 0;
  lpCriticalSection = FUN_c05427a0(0x14);
  param_1[6] = (int)lpCriticalSection;
  if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    InitializeCriticalSection(lpCriticalSection);
    InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    *(int **)(param_2 + 0x50) = param_1;
    *(undefined1 *)(param_1 + 0x12) = 0;
    param_1[0x11] = param_2;
    param_1[7] = *(int *)(*(int *)(param_2 + 8) + 0x40);
    param_1[8] = *(int *)(param_2 + 0x16c);
    *(char *)((int)param_1 + 0x49) = param_6;
    *(char *)((int)param_1 + 0x4a) = param_5;
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    param_1[0x13] = (int)pvVar1;
    if ((*(uint *)(param_2 + 0x54) & 0x40000) == 0) {
      pcVar3 = FUN_c05557fc;
    }
    else {
      pcVar3 = FUN_c0555918;
    }
    FUN_c0561494((int)(param_1 + 9),pcVar3,param_1);
    *(uint *)(param_2 + 0x54) = *(uint *)(param_2 + 0x54) & 0xffffffdf;
    if (*(int *)(param_2 + 0x124) == -2) {
      *param_1 = 0;
      iVar4 = FUN_c055e134(param_2);
    }
    else {
      swprintf(awStack_238,0xc05414e8,*(wchar_t **)(param_2 + 0x14));
      pcVar3 = FUN_c055566c;
      if (((((*(uint *)(param_2 + 0x54) & 0x40000) != 0) && (param_5 == '\0')) && (param_6 == '\0'))
         && ((*(int *)(param_2 + 0x48c) != 0xe && (*(int *)(param_2 + 0x174) == 0)))) {
        pcVar3 = FUN_c05554b4;
      }
      iVar2 = FUN_c0561d84(param_1,(int)pcVar3,(int)param_1,param_3,*(int *)(param_2 + 0x48c),1,
                           CONCAT31((int3)((uint)in_stack_fffffdb0 >> 8),param_6),
                           *(int *)(param_2 + 0x124),DAT_c0565698,awStack_238,DAT_c0565698,
                           FUN_c0555af0);
      if (iVar2 < 0) {
        iVar4 = -0x3fffffff;
        *param_1 = 0;
        goto LAB_c0555d98;
      }
      if (((int *)*param_1 == (int *)0x0) || (*(int *)*param_1 != 0xe)) goto LAB_c0555dd0;
      (&DAT_c05656e0)[param_3] = param_2;
    }
    if (iVar4 == 0) goto LAB_c0555dd0;
  }
LAB_c0555d98:
  if ((LPCRITICAL_SECTION)param_1[6] != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)param_1[6]);
    CTEFreeMem(param_1[6]);
    CloseHandle((HANDLE)param_1[0x13]);
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    *(undefined4 *)(param_2 + 0x50) = 0;
  }
LAB_c0555dd0:
  FUN_c05625b0(local_30);
  return iVar4;
}



/* c0555e08 FUN_c0555e08 */

/* Boundary evidence: original MIPS .pdata c0555e08..c0555e57. Semantic name remains unreviewed. */

void FUN_c0555e08(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x494) == 0) {
    iVar1 = 0x4001000b;
  }
  else {
    iVar1 = 0x4001000c;
  }
  NdisMIndicateStatus(param_2,iVar1,(uint *)0xffffffff,-2);
  NdisMIndicateStatusComplete(param_2);
  return;
}



/* c0555e58 FUN_c0555e58 */

/* Boundary evidence: original MIPS .pdata c0555e58..c0556073. Semantic name remains unreviewed. */

undefined4 FUN_c0555e58(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  
  *param_4 = 0;
  if (*(int *)(param_3 + 0x10) == 1) {
    iVar1 = *(int *)(param_3 + 0x14);
    if (iVar1 == -0xffff) {
      if ((*(uint *)(param_1 + 0xdc) & 0x80000000) != 0) {
        return 1;
      }
      if ((*(uint *)(param_2 + 0x490) & 0x80000000) != 0) {
        *param_4 = 0xc0000001;
        return 1;
      }
      *(uint *)(param_2 + 0x490) = *(uint *)(param_2 + 0x490) | 0x80000000;
      *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x80000000;
      *(undefined4 *)(param_2 + 0x494) = 1;
      return 1;
    }
    if (iVar1 == -0xfffe) {
      if ((*(uint *)(param_1 + 0xdc) & 0x80000000) != 0) {
        *(uint *)(param_2 + 0x490) = *(uint *)(param_2 + 0x490) & 0x7fffffff;
        *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0x7fffffff;
        return 1;
      }
      *param_4 = 0xc0000001;
      return 1;
    }
    if ((iVar1 == -0xfffd) || (iVar1 + 0xfffdU < 2)) {
      if ((*(uint *)(param_1 + 0xdc) & 0x80000000) != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        if (*(int *)(param_3 + 0x14) == -0xfffd) {
          *(undefined4 *)(param_2 + 0x494) = 0;
        }
        else {
          *(undefined4 *)(param_2 + 0x494) = 1;
        }
        NdisIMQueueMiniportCallback(param_2,FUN_c0555e08,param_2);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        return 1;
      }
      *param_4 = 0xc0000001;
      return 1;
    }
  }
  else if ((((*(int *)(param_3 + 0x10) == 0) && (*(int *)(param_3 + 0x14) == 0x10114)) &&
           ((*(uint *)(param_2 + 0x490) & 0x80000000) != 0)) &&
          ((*(uint *)(param_1 + 0xdc) & 0x80000000) == 0)) {
    if ((*(undefined4 **)(param_3 + 0x18) != (undefined4 *)0x0) && (3 < *(uint *)(param_3 + 0x1c)))
    {
      **(undefined4 **)(param_3 + 0x18) = *(undefined4 *)(param_2 + 0x494);
      *(undefined4 *)(param_3 + 0x20) = 4;
      return 1;
    }
    *(undefined4 *)(param_3 + 0x24) = 4;
    return 1;
  }
  return 0;
}



/* c0556074 FUN_c0556074 */

/* Boundary evidence: original MIPS .pdata c0556074..c05561bf. Semantic name remains unreviewed. */

undefined4 FUN_c0556074(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(param_1 + 0x1c);
  *param_2 = 0;
  if (((param_1 < 0x10000) || (0x6fffffff < param_1 + 0x5cU)) &&
     ((iVar4 == 0 || (((iVar3 < 0 || (iVar4 < 0x10000)) || (0x6fffffff < (uint)(iVar3 + iVar4)))))))
  {
    *param_2 = param_1;
    *(undefined4 *)(param_1 + 0x28) = 0;
    return 0;
  }
  iVar1 = CeAllocDuplicateBuffer(param_2,param_1,0x5c,0xc);
  if (iVar1 == 0) {
    if (iVar4 == 0) {
      if (iVar3 == 0) {
LAB_c0556168:
        *(int *)(*param_2 + 0x28) = param_1;
        return 0;
      }
    }
    else if (iVar3 != 0) {
      iVar3 = CeAllocAsynchronousBuffer(*param_2 + 0x18,iVar4,iVar3,0xc);
      if (iVar3 == 0) goto LAB_c0556168;
      CeFreeDuplicateBuffer(*param_2,param_1,0x5c,0xc);
      *param_2 = 0;
      goto LAB_c0556108;
    }
    CeFreeDuplicateBuffer(*param_2,param_1,0x5c,0xc);
    uVar2 = 0xc0010015;
    *param_2 = 0;
  }
  else {
LAB_c0556108:
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



/* c05561c0 FUN_c05561c0 */

/* Boundary evidence: original MIPS .pdata c05561c0..c055622f. Semantic name remains unreviewed. */

int FUN_c05561c0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (*(int *)(iVar1 + 0x18) != 0) {
      CeFreeAsynchronousBuffer
                (*(undefined4 *)(param_1 + 0x18),*(int *)(iVar1 + 0x18),
                 *(undefined4 *)(iVar1 + 0x1c),0xc);
    }
    CeFreeDuplicateBuffer(param_1,iVar1,0x5c,0xc);
    param_1 = iVar1;
  }
  return param_1;
}



/* c0556230 FUN_c0556230 */

/* Boundary evidence: original MIPS .pdata c0556230..c0556333. Semantic name remains unreviewed. */

int FUN_c0556230(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                int param_6,char param_7)

{
  uint uVar1;
  int iVar2;
  int aiStack_80 [3];
  undefined4 local_74;
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_24;
  
  local_24 = DAT_c05653c8;
  memset(aiStack_80,0,0x5c);
  local_70 = (uint)(param_2 == 0);
  local_64 = param_5;
  if (param_7 != '\0') {
    local_74 = 0x20;
  }
  local_6c = param_3;
  local_68 = param_4;
  uVar1 = FUN_c055edd4(param_1,0,(uint)(param_2 == 0),aiStack_80);
  iVar2 = 0;
  if ((uVar1 != 0) && (iVar2 = param_6, uVar1 != 0xffffffff)) {
    iVar2 = param_6 + 1;
  }
  FUN_c05625b0(local_24);
  return iVar2;
}



/* c0556384 FUN_c0556384 */

/* Boundary evidence: original MIPS .pdata c0556384..c05563f3. Semantic name remains unreviewed. */

undefined4 FUN_c0556384(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  if (*(uint *)(param_2 + 0x1c) < 4) {
    uVar1 = 0xc0010014;
    *(undefined4 *)(param_2 + 0x24) = 4;
  }
  else {
    if ((*(int *)(param_1 + 0x11c) == 0) || (*(int *)(param_1 + 0x11c) == 1)) {
      local_8 = *(undefined4 *)(*(int *)(*(int *)(param_2 + 4) + 0x98) + 0xc);
    }
    **(undefined4 **)(param_2 + 0x18) = local_8;
    uVar1 = 0;
    *(undefined4 *)(param_2 + 0x20) = 4;
  }
  return uVar1;
}



/* c05563f4 FUN_c05563f4 */

/* Boundary evidence: original MIPS .pdata c05563f4..c05564a3. Semantic name remains unreviewed. */

int FUN_c05563f4(int param_1,int param_2)

{
  int iVar1;
  int local_18;
  int local_14;
  
  EthQueryOpenFilterAddresses
            (&local_18,*(int *)(param_1 + 0xf8),*(int *)(*(int *)(param_2 + 4) + 0x98),
             *(uint *)(param_2 + 0x1c),&local_14,*(void **)(param_2 + 0x18));
  if (local_18 == -0x3fffffff) {
    iVar1 = EthNumberOfOpenFilterAddresses
                      (*(undefined4 *)(param_1 + 0xf8),*(int *)(*(int *)(param_2 + 4) + 0x98));
    *(undefined4 *)(param_2 + 0x20) = 0;
    local_18 = -0x3ffeffec;
    *(int *)(param_2 + 0x24) = iVar1 * 6;
  }
  else {
    *(undefined4 *)(param_2 + 0x24) = 0;
    *(int *)(param_2 + 0x20) = local_14 * 6;
  }
  return local_18;
}



/* c05564a4 FUN_c05564a4 */

/* Boundary evidence: original MIPS .pdata c05564a4..c05565cf. Semantic name remains unreviewed. */

undefined4 FUN_c05564a4(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  size_t _Size;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  void *_Dst;
  
  iVar6 = *(int *)(param_2 + 4);
  iVar5 = *(int *)(param_2 + 0x10);
  uVar1 = 0;
  iVar7 = 0;
  piVar3 = *(int **)(param_1 + 0x26c);
  for (piVar2 = piVar3; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    if ((piVar2[1] == iVar6) || (iVar5 == 2)) {
      uVar1 = piVar2[6] + piVar2[4] + uVar1 + 0x18;
    }
  }
  uVar4 = 0;
  if (*(uint *)(param_2 + 0x1c) < uVar1) {
    uVar4 = 0xc0010014;
    *(uint *)(param_2 + 0x24) = uVar1;
  }
  else {
    _Dst = *(void **)(param_2 + 0x18);
    for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      if ((piVar3[1] == iVar6) || (iVar5 == 2)) {
        _Size = piVar3[6] + piVar3[4] + 0x18;
        memcpy(_Dst,piVar3 + 2,_Size);
        _Dst = (void *)((int)_Dst + _Size);
        iVar7 = iVar7 + _Size;
      }
    }
  }
  *(int *)(param_2 + 0x20) = iVar7;
  return uVar4;
}



/* c05565d0 FUN_c05565d0 */

undefined4 FUN_c05565d0(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)0x0;
  piVar3 = (int *)param_2[10];
  if ((int *)param_2[10] == (int *)0x0) {
    piVar3 = param_2;
  }
  *param_2 = 0;
  piVar1 = (int *)(param_1 + 500);
  do {
    if (*piVar1 == 0) {
      if (piVar2 == piVar3) {
        return 0;
      }
      *piVar1 = (int)param_2;
      return 1;
    }
    piVar1 = (int *)*piVar1;
    piVar2 = (int *)piVar1[10];
    if ((int *)piVar1[10] == (int *)0x0) {
      piVar2 = piVar1;
    }
  } while (piVar2 != piVar3);
  return 0;
}



/* c0556634 FUN_c0556634 */

/* Boundary evidence: original MIPS .pdata c0556634..c055672b. Semantic name remains unreviewed. */

undefined4 FUN_c0556634(undefined4 *param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  void *_Dst;
  undefined4 uVar1;
  HANDLE pvVar2;
  uint _Size;
  
  _Size = param_4 + 0x5c;
  if (_Size < 0x5c) {
    uVar1 = 0xc0010015;
  }
  else {
    _Dst = FUN_c05427a0(_Size);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
      pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
      *(HANDLE *)((int)_Dst + 0x30) = pvVar2;
      *(undefined4 *)((int)_Dst + 0x10) = 1;
      *(undefined4 *)((int)_Dst + 0x14) = param_2;
      *(void **)((int)_Dst + 0x18) = (void *)((int)_Dst + 0x5c);
      *(size_t *)((int)_Dst + 0x1c) = param_4;
      if (param_3 != (void *)0x0) {
        memmove((void *)((int)_Dst + 0x5c),param_3,param_4);
      }
      *param_1 = _Dst;
      return 0;
    }
    uVar1 = 0xc000009a;
  }
  *param_1 = 0;
  return uVar1;
}



/* c055672c FUN_c055672c */

void FUN_c055672c(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0xf8) = *param_2;
  *(undefined4 *)(param_1 + 0xfc) = param_2[1];
  return;
}



/* c0556740 FUN_c0556740 */

/* Boundary evidence: original MIPS .pdata c0556740..c055686b. Semantic name remains unreviewed. */

undefined4 FUN_c0556740(wchar_t *param_1,uint *param_2)

{
  LSTATUS LVar1;
  uint uVar2;
  undefined4 uVar3;
  DWORD local_128;
  HKEY local_124;
  DWORD local_120 [2];
  wchar_t awStack_118 [128];
  uint local_18;
  
  local_18 = DAT_c05653c8;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0,&local_124);
  if (LVar1 == 0) {
    local_128 = 0x100;
    LVar1 = RegQueryValueExW(local_124,L"Name",(LPDWORD)0x0,local_120,(LPBYTE)awStack_118,&local_128
                            );
    RegCloseKey(local_124);
    if ((LVar1 == 0) && (uVar2 = local_128, local_120[0] == 1)) goto LAB_c055681c;
  }
  wcscpy(awStack_118,L"WinCE");
  uVar2 = 0xc;
LAB_c055681c:
  if (*param_2 < uVar2) {
    uVar3 = 0x7a;
  }
  else {
    wcscpy(param_1,awStack_118);
    uVar3 = 0;
  }
  *param_2 = uVar2;
  FUN_c05625b0(local_18);
  return uVar3;
}



/* c055686c FUN_c055686c */

/* Boundary evidence: original MIPS .pdata c055686c..c055691b. Semantic name remains unreviewed. */

void FUN_c055686c(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  wchar_t *pwVar3;
  uint local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c05653c8;
  if (param_2 == (uint *)0x0) {
    local_228[0] = 0x208;
    pwVar3 = awStack_220;
    iVar2 = FUN_c0556740(awStack_220,local_228);
    if (iVar2 < 0) goto LAB_c0556900;
    uVar1 = local_228[0] + 0xfffe;
  }
  else {
    local_228[0] = *param_2;
    pwVar3 = (wchar_t *)param_2[1];
    uVar1 = local_228[0];
  }
  FUN_c0556230(param_1,0,0x1021a,pwVar3,uVar1 & 0xffff,0x77,'\0');
LAB_c0556900:
  FUN_c05625b0(local_18);
  return;
}



/* c055691c FUN_c055691c */

/* Boundary evidence: original MIPS .pdata c055691c..c05569d7. Semantic name remains unreviewed. */

void FUN_c055691c(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xf8) == 0) || (*(int *)(*(int *)(param_1 + 0xf8) + 0x2c) == 0)) {
    if ((*(char *)(param_1 + 0x3b) == '\0') || (*(ushort *)(param_1 + 0x438) < 2)) {
      *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xffffbfff;
    }
    else {
      *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x4000;
    }
  }
  else {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xffffbfff;
  }
  for (iVar1 = *(int *)(param_1 + 0x18); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    FUN_c054e074(param_1,iVar1);
  }
  return;
}



/* c05569d8 FUN_c05569d8 */

/* Boundary evidence: original MIPS .pdata c05569d8..c0556d2f. Semantic name remains unreviewed. */

void FUN_c05569d8(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *_Buf1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  
  uVar3 = *(uint *)(param_2 + 0x14);
  iVar8 = *(int *)(param_2 + 4);
  if (0x2010104 < uVar3) {
    if (uVar3 == 0xfd010102) {
      *(int *)(param_2 + 0x2c) = param_3;
      return;
    }
    if (uVar3 == 0xfd010103) {
      piVar7 = *(int **)(param_2 + 8);
      if (param_3 == 0) {
        *piVar7 = *(undefined4 *)(param_1 + 0x26c);
        *(int **)(param_1 + 0x26c) = piVar7;
        return;
      }
      if (piVar7 == (undefined4 *)0x0) {
        return;
      }
    }
    else {
      if (uVar3 != 0xfd010104) {
        return;
      }
      if (param_3 != 0) {
        return;
      }
      piVar6 = (int *)*(int *)(param_1 + 0x26c);
      piVar5 = (undefined4 *)0x0;
      while( true ) {
        piVar7 = piVar6;
        if (piVar7 == (int *)0x0) {
          return;
        }
        if ((((piVar7[1] == iVar8) &&
             (_Buf1 = *(void **)(param_2 + 0x18), *(int *)((int)_Buf1 + 0x10) == piVar7[6])) &&
            (*(int *)((int)_Buf1 + 8) == piVar7[4])) &&
           (iVar1 = memcmp(_Buf1,piVar7 + 2,*(size_t *)(param_2 + 0x1c)), iVar1 == 0)) break;
        piVar6 = (int *)*piVar7;
        piVar5 = piVar7;
      }
      if (piVar5 == (undefined4 *)0x0) {
        *(int *)(param_1 + 0x26c) = *piVar7;
      }
      else {
        *piVar5 = *piVar7;
      }
    }
    CTEFreeMem(piVar7);
    return;
  }
  if (uVar3 == 0x2010104) {
    if (*(int *)(param_1 + 0x11c) != 1) {
      return;
    }
    if (param_3 == 0) {
      return;
    }
    if (iVar8 == 0) {
      return;
    }
    if ((*(uint *)(iVar8 + 0x7c) & 0x8000) != 0) {
      return;
    }
    FUN_c055a830(*(int *)(param_1 + 0xfc),*(int *)(iVar8 + 0x98));
    return;
  }
  if (uVar3 != 0x1010e) {
    if (uVar3 == 0x1010f) {
      if (param_3 != 0) {
        return;
      }
      uVar2 = 4;
      uVar4 = **(undefined4 **)(param_2 + 0x18);
      *(undefined4 *)(param_1 + 0x200) = uVar4;
      *(short *)(iVar8 + 0xa0) = (short)uVar4;
    }
    else {
      if (uVar3 != 0x1010103) {
        if (uVar3 != 0x2010103) {
          return;
        }
        if (*(int *)(param_1 + 0x11c) != 1) {
          return;
        }
        if (param_3 == 0) {
          return;
        }
        if (iVar8 == 0) {
          return;
        }
        if ((*(uint *)(iVar8 + 0x7c) & 0x8000) != 0) {
          return;
        }
        FUN_c055a704(*(int *)(param_1 + 0xfc),*(int *)(iVar8 + 0x98));
        return;
      }
      if (*(int *)(param_1 + 0x11c) == 0) {
        FUN_c05428f0(*(int *)(param_1 + 0xf8),param_3,0,0);
      }
      if (param_3 != 0) {
        return;
      }
      uVar2 = *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x20) = uVar2;
    return;
  }
  if ((param_3 != 0) && (iVar8 != 0)) {
    if (*(int *)(param_1 + 0x11c) == 0) {
      if ((*(uint *)(iVar8 + 0x7c) & 0x8000) == 0) {
        iVar1 = *(int *)(param_1 + 0xf8);
        goto LAB_c0556b58;
      }
    }
    else if ((*(int *)(param_1 + 0x11c) == 1) && ((*(uint *)(iVar8 + 0x7c) & 0x8000) == 0)) {
      iVar1 = *(int *)(param_1 + 0xfc);
LAB_c0556b58:
      FUN_c055b9f8(iVar1,*(int *)(iVar8 + 0x98));
    }
  }
  if (*(int *)(param_1 + 0x11c) != 0) {
    return;
  }
  piVar6 = *(int **)(param_1 + 0xf8);
  piVar7 = (int *)0x0;
  piVar5 = (int *)*piVar6;
  uVar3 = 0;
  if (piVar5 != (int *)0x0) {
    do {
      if (1 < uVar3) break;
      if (piVar5[3] != 0) {
        uVar3 = uVar3 + 1;
        piVar7 = piVar5;
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)0x0);
    if (uVar3 == 1) {
      piVar6[0xb] = (int)piVar7;
      goto LAB_c0556bc0;
    }
  }
  piVar6[0xb] = 0;
LAB_c0556bc0:
  FUN_c054dde0(param_1);
  FUN_c055691c(param_1);
  return;
}



/* c0556d30 FUN_c0556d30 */

/* Boundary evidence: original MIPS .pdata c0556d30..c0556f9b. Semantic name remains unreviewed. */

void FUN_c0556d30(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = *(undefined4 **)(param_1 + 500);
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffaff;
  *(undefined2 *)(param_1 + 0x43a) = 0;
  *(undefined4 *)(param_1 + 500) = *puVar4;
  iVar5 = puVar4[1];
  puVar4[3] = puVar4[3] | 0x80000000;
  if (iVar5 == 0) {
    puVar4[0xb] = param_2;
    if (((*(undefined4 **)(param_1 + 0x244) == puVar4) && (param_2 == 0)) &&
       (iVar5 = *(int *)puVar4[6],
       (iVar5 == 0) != ((*(uint *)(param_1 + 0x54) & 0x20000000) == 0x20000000))) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      if (iVar5 == 0) {
        iVar5 = 0x4001000b;
      }
      else {
        iVar5 = 0x4001000c;
      }
      NdisMIndicateStatus(param_1,iVar5,(uint *)0xffffffff,-2);
      NdisMIndicateStatusComplete(param_1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    if ((puVar4[3] & 4) == 4) {
      EventModify(puVar4[0xc],3);
    }
    else if ((puVar4[3] & 2) == 2) {
      CloseHandle((HANDLE)puVar4[0xc]);
      CTEFreeMem(puVar4);
    }
    goto LAB_c0556f58;
  }
  iVar1 = puVar4[5];
  if (iVar1 == 0x10101) {
    if (param_2 != 0) {
      puVar4[8] = 0;
    }
  }
  else if (iVar1 == -0x2feff00) {
    if ((param_2 == 0) && ((*(uint *)(param_1 + 0x54) & 0x8000) == 0)) {
      puVar3 = (uint *)puVar4[6];
      uVar2 = *(uint *)(param_1 + 0x270);
LAB_c0556e14:
      *puVar3 = uVar2;
    }
  }
  else if ((iVar1 == 0x10113) && (param_2 == 0)) {
    puVar3 = (uint *)puVar4[6];
    uVar2 = *(uint *)(param_1 + 0x1f0) & 0x80 | *puVar3;
    goto LAB_c0556e14;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar1 = FUN_c05561c0((int)puVar4);
  (**(code **)(iVar5 + 0x5c))(*(undefined4 *)(iVar5 + 0x10),iVar1,param_2);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar1 = NdisInterlockedDecrement((LONG *)(iVar5 + 0x80));
  if (iVar1 == 0) {
    FUN_c0559efc(iVar5);
  }
LAB_c0556f58:
  if ((*(int *)(param_1 + 500) == 0) && (*(undefined4 **)(param_1 + 0x3b4) != (undefined4 *)0x0)) {
    EventModify(**(undefined4 **)(param_1 + 0x3b4),3);
  }
  return;
}



/* c0556f9c NdisMQueryInformationComplete */

/* Boundary evidence: original MIPS .pdata c0556f9c..c055701b. Semantic name remains unreviewed. */

void NdisMQueryInformationComplete(int param_1,int param_2)

{
                    /* 0x16f9c  138  NdisMQueryInformationComplete */
  if ((*(uint *)(param_1 + 0x54) & 0x400) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c0556d30(param_1,param_2);
    if (*(int *)(param_1 + 500) != 0) {
      FUN_c054cc28(param_1,0,0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c055701c FUN_c055701c */

/* Boundary evidence: original MIPS .pdata c055701c..c05574b3. Semantic name remains unreviewed. */

void FUN_c055701c(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *local_48;
  int local_44;
  uint local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  uint local_30 [2];
  
  local_48 = (int *)0x0;
  local_44 = 0;
  bVar1 = true;
  if (*(int *)(param_1 + 0x11c) == 0) {
    local_3c = *(undefined4 *)(*(int *)(param_1 + 0xf8) + 0x1c);
  }
  else if (*(int *)(param_1 + 0x11c) == 1) {
    local_3c = *(undefined4 *)(*(int *)(param_1 + 0xfc) + 0x1c);
  }
  else {
    bVar1 = false;
  }
  piVar5 = (int *)0x0;
  if (bVar1) {
    local_44 = FUN_c0556634(&local_48,0x1010e,&local_3c,4);
    piVar4 = local_48;
    if (local_44 != 0) goto LAB_c055743c;
    local_48[1] = param_2;
    local_48[3] = 2;
    if (param_2 != 0) {
      NdisInterlockedIncrement((LONG *)(param_2 + 0x80));
    }
    FUN_c05565d0(param_1,piVar4);
    piVar5 = piVar4;
  }
  iVar8 = -0x3ffeffeb;
  piVar4 = piVar5;
  if (*(int *)(param_1 + 0x11c) == 0) {
    local_38 = *(uint *)(*(int *)(param_1 + 0xf8) + 0x44);
    iVar2 = iVar8;
    if ((int)((ulonglong)local_38 * 6 >> 0x20) == 0) {
      iVar2 = FUN_c0556634(&local_48,0x1010103,(void *)0x0,(size_t)((ulonglong)local_38 * 6));
      piVar4 = local_48;
    }
    local_44 = iVar2;
    if (iVar2 != 0) goto LAB_c055743c;
    EthQueryGlobalFilterAddresses
              (&local_44,*(int *)(param_1 + 0xf8),local_38 * 6,&local_38,piVar4 + 0x17);
LAB_c0557244:
    piVar4[1] = param_2;
    piVar4[3] = 2;
    if (param_2 != 0) {
      NdisInterlockedIncrement((LONG *)(param_2 + 0x80));
    }
    FUN_c05565d0(param_1,piVar4);
  }
  else if (*(int *)(param_1 + 0x11c) == 1) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xfc) + 0x38);
    local_34 = (uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8 | (uVar3 << 0x10 | uVar3 & 0xff00) << 8;
    local_44 = FUN_c0556634(&local_48,0x2010103,&local_34,4);
    piVar7 = local_48;
    if (local_44 != 0) goto LAB_c055743c;
    local_48[1] = param_2;
    local_48[3] = 2;
    if (param_2 != 0) {
      NdisInterlockedIncrement((LONG *)(param_2 + 0x80));
    }
    FUN_c05565d0(param_1,piVar7);
    uVar3 = *(uint *)(*(int *)(param_1 + 0xfc) + 0x3c);
    local_30[0] = (uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8 | (uVar3 << 0x10 | uVar3 & 0xff00) << 8;
    local_44 = FUN_c0556634(&local_48,0x2010104,local_30,4);
    piVar4 = local_48;
    piVar5 = piVar7;
    if (local_44 != 0) goto LAB_c055743c;
    goto LAB_c0557244;
  }
  piVar5 = piVar4;
  if (local_44 != 0) goto LAB_c055743c;
  local_40 = *(uint *)(param_1 + 0x2c0) & 5;
  if ((param_3 == 0) && (param_2 != 0)) {
    piVar6 = *(int **)(param_1 + 0x26c);
    piVar7 = piVar4;
    if (piVar6 != (int *)0x0) {
      do {
        if (piVar6[1] == param_2) {
          uVar3 = piVar6[4] + 0x18;
          iVar2 = iVar8;
          if ((0x17 < uVar3) && (uVar3 <= uVar3 + piVar6[6])) {
            iVar2 = FUN_c0556634(&local_48,0xfd010104,piVar6 + 2,uVar3 + piVar6[6]);
            piVar7 = local_48;
          }
          local_44 = iVar2;
          if (iVar2 != 0) goto LAB_c055743c;
          piVar7[1] = param_2;
          piVar7[3] = 2;
          NdisInterlockedIncrement((LONG *)(param_2 + 0x80));
          FUN_c05565d0(param_1,piVar7);
        }
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)0x0);
LAB_c05573b0:
      piVar5 = piVar4;
      if (local_44 != 0) goto LAB_c055743c;
    }
  }
  else {
    piVar7 = *(int **)(param_1 + 0x26c);
    if (piVar7 != (int *)0x0) {
      do {
        uVar3 = piVar7[4] + 0x18;
        iVar2 = iVar8;
        piVar4 = piVar5;
        if ((0x17 < uVar3) && (uVar3 <= uVar3 + piVar7[6])) {
          iVar2 = FUN_c0556634(&local_48,0xfd010104,piVar7 + 2,uVar3 + piVar7[6]);
          piVar4 = local_48;
        }
        local_44 = iVar2;
        if (iVar2 != 0) goto LAB_c055743c;
        piVar4[1] = param_2;
        piVar4[3] = 2;
        if (param_2 != 0) {
          NdisInterlockedIncrement((LONG *)(param_2 + 0x80));
        }
        FUN_c05565d0(param_1,piVar4);
        piVar7 = (int *)*piVar7;
        piVar5 = piVar4;
      } while (piVar7 != (int *)0x0);
      goto LAB_c05573b0;
    }
  }
  uVar3 = local_40;
  for (iVar8 = *(int *)(param_1 + 0x18); iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x14)) {
    if (param_2 != iVar8) {
      uVar3 = *(uint *)(iVar8 + 0xb8) | uVar3;
      local_40 = uVar3;
    }
  }
  piVar5 = piVar4;
  if ((uVar3 != *(uint *)(param_1 + 0x2c0)) &&
     (local_44 = FUN_c0556634(&local_48,0xfd010106,&local_40,4), piVar4 = local_48, local_44 == 0))
  {
    local_48[1] = param_2;
    local_48[3] = 2;
    if (param_2 != 0) {
      NdisInterlockedIncrement((LONG *)(param_2 + 0x80));
    }
    FUN_c05565d0(param_1,piVar4);
    piVar5 = piVar4;
  }
LAB_c055743c:
  if ((param_3 != 0) && (piVar5 != (int *)0x0)) {
    piVar5[3] = piVar5[3] | 0x10;
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x1000000;
  }
  if (*(int *)(param_1 + 500) != 0) {
    FUN_c054cc28(param_1,0,0);
  }
  return;
}



/* c05574b4 FUN_c05574b4 */

/* Boundary evidence: original MIPS .pdata c05574b4..c0557743. Semantic name remains unreviewed. */

undefined4 FUN_c05574b4(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  
  if (*(int *)(param_1 + 0x354) == 5) {
    return 0xc0010018;
  }
  if (((*(uint *)(param_1 + 0x54) & 0x40000) != 0) && ((*(uint *)(param_1 + 0x54) & 0x80000) != 0))
  {
    return 0xc001000d;
  }
  if ((*(int *)(param_2 + 0x10) == 2) && (1 < *(int *)(param_1 + 0x2c4))) {
    return 0x8000000f;
  }
  if (((*(uint *)(param_1 + 0x248) & 0x20100) == 0) &&
     ((*(int *)(param_1 + 0x2c4) < 2 || (*(int *)(param_2 + 0x14) == -0x2fefeff)))) {
    if (*(int *)(param_2 + 0x10) == 1) {
      if (*(int *)(param_2 + 0x14) == 0x20213) {
        **(undefined4 **)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x3b8);
        *(undefined4 *)(param_2 + 0x20) = 4;
        *(undefined4 *)(param_2 + 0x24) = 4;
        goto LAB_c05575c4;
      }
      if (*(int *)(param_2 + 0x14) == 0x1010e) {
        iVar2 = *(int *)(param_2 + 4);
        puVar4 = *(uint **)(param_2 + 0x18);
        if (iVar2 != 0) {
          if ((*puVar4 & 0xa0) == 0) {
            if ((*(uint *)(iVar2 + 0x7c) & 4) != 0) {
              *(uint *)(iVar2 + 0x7c) = *(uint *)(iVar2 + 0x7c) & 0xfffffffb;
              cVar1 = *(char *)(param_1 + 0x3b) + -1;
              goto LAB_c0557670;
            }
          }
          else if ((*(uint *)(iVar2 + 0x7c) & 4) == 0) {
            *(uint *)(iVar2 + 0x7c) = *(uint *)(iVar2 + 0x7c) | 4;
            cVar1 = *(char *)(param_1 + 0x3b) + '\x01';
LAB_c0557670:
            *(char *)(param_1 + 0x3b) = cVar1;
            FUN_c055691c(param_1);
          }
        }
        *puVar4 = *puVar4 & 0xffffff7f;
      }
    }
    if ((*(uint *)(param_1 + 0x54) & 0x40000) != 0) {
      *(int *)(param_1 + 0x43c) = *(int *)(param_1 + 0x43c) + 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if (param_3 == 0) {
      uVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x54))
                        (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x14),
                         *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                         param_2 + 0x20,param_2 + 0x24);
    }
    else {
      uVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x44))();
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if ((*(uint *)(param_1 + 0x54) & 0x40000) != 0) {
      *(int *)(param_1 + 0x43c) = *(int *)(param_1 + 0x43c) + -1;
    }
  }
  else {
    if (param_3 != 0) {
      return 0xc0000001;
    }
LAB_c05575c4:
    uVar3 = 0;
  }
  return uVar3;
}



/* c0557744 FUN_c0557744 */

/* Boundary evidence: original MIPS .pdata c0557744..c05577eb. Semantic name remains unreviewed. */

undefined4 FUN_c0557744(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_18;
  
  bVar1 = false;
  if ((*(int *)(param_2 + 4) != 0) && (piVar3 = &DAT_c05652f8, DAT_c05652f8 != 0)) {
    iVar2 = DAT_c05652f8;
    do {
      if (iVar2 == *(int *)(param_2 + 0x14)) {
        bVar1 = true;
        local_18 = (*(code *)piVar3[1])(param_1,param_2);
        break;
      }
      piVar3 = piVar3 + 2;
      iVar2 = *piVar3;
    } while (iVar2 != 0);
  }
  if (!bVar1) {
    local_18 = FUN_c05574b4(param_1,param_2,0);
  }
  return local_18;
}



/* c05577ec FUN_c05577ec */

/* Boundary evidence: original MIPS .pdata c05577ec..c0557ab3. Semantic name remains unreviewed. */

void FUN_c05577ec(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = *(undefined4 **)(param_1 + 500);
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffaff;
  *(undefined2 *)(param_1 + 0x43a) = 0;
  *(undefined4 *)(param_1 + 500) = *puVar4;
  *(undefined4 **)(param_1 + 0x448) = puVar4;
  uVar3 = puVar4[3];
  bVar1 = (uVar3 & 2) != 2;
  iVar5 = puVar4[1];
  puVar4[3] = uVar3 | 0x80000000;
  if ((uVar3 & 8) != 0) {
    puVar4[3] = uVar3 & 0xfffffff7 | 0x80000000;
    puVar4[6] = *(undefined4 *)(param_1 + 0x1d8);
    puVar4[7] = (uint)*(ushort *)(param_1 + 0x1dc);
    *(undefined4 *)(param_1 + 0x1d8) = 0;
    *(undefined2 *)(param_1 + 0x1dc) = 0;
  }
  iVar2 = puVar4[5];
  if ((iVar2 != 0x1010102) &&
     (((iVar2 == 0x1010103 ||
       (((iVar2 != 0x2010102 && (iVar2 != 0x3010102)) &&
        ((iVar2 == 0x3010103 || ((iVar2 != 0x3010106 && (iVar2 == 0x3010107)))))))) &&
      (*(int *)(param_1 + 0x194) != 0)))) {
    CTEFreeMem();
    *(undefined4 *)(param_1 + 0x194) = 0;
  }
  if (iVar5 == 0) {
    puVar4[0xb] = param_2;
    if ((((*(uint *)(param_1 + 0x54) & 0x200000) != 0) && (*(int *)(param_1 + 500) == 0)) &&
       ((puVar4[3] & 0x10) != 0)) {
      FUN_c054e974(param_1);
    }
    if ((puVar4[3] & 0x10) == 0x10) {
      *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfeffffff;
    }
    if ((puVar4[3] & 4) == 4) {
      EventModify(puVar4[0xc],3);
      goto LAB_c0557a6c;
    }
  }
  else {
    FUN_c05569d8(param_1,(int)puVar4,param_2);
    if ((puVar4[3] & 0x10) != 0) {
      *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfeffffff;
    }
    if (bVar1) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      iVar2 = FUN_c05561c0((int)puVar4);
      (**(code **)(iVar5 + 0x5c))(*(undefined4 *)(iVar5 + 0x10),iVar2,param_2);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    iVar2 = NdisInterlockedDecrement((LONG *)(iVar5 + 0x80));
    if (iVar2 == 0) {
      FUN_c0559efc(iVar5);
    }
  }
  if (!bVar1) {
    CloseHandle((HANDLE)puVar4[0xc]);
    CTEFreeMem(puVar4);
  }
LAB_c0557a6c:
  if ((*(int *)(param_1 + 500) == 0) && (*(undefined4 **)(param_1 + 0x3b4) != (undefined4 *)0x0)) {
    EventModify(**(undefined4 **)(param_1 + 0x3b4),3);
  }
  return;
}



/* c0557ab4 FUN_c0557ab4 */

/* Boundary evidence: original MIPS .pdata c0557ab4..c0557cff. Semantic name remains unreviewed. */

int FUN_c0557ab4(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = 0;
  if (*(uint *)(param_2 + 0x1c) < 4) {
    *(undefined4 *)(param_2 + 0x24) = 4;
    return -0x3ffeffec;
  }
  iVar4 = *(int *)(param_2 + 4);
  uVar5 = **(uint **)(param_2 + 0x18);
  if ((*(uint *)(iVar4 + 0x7c) & 0x8000) == 0) {
    if (*(int *)(param_1 + 0x11c) == 0) {
      iVar3 = FUN_c055b990(*(int **)(param_1 + 0xf8),*(int *)(iVar4 + 0x98),uVar5);
      iVar1 = *(int *)(param_1 + 0xf8);
    }
    else {
      if (*(int *)(param_1 + 0x11c) != 1) goto LAB_c0557b7c;
      iVar3 = FUN_c055b990(*(int **)(param_1 + 0xfc),*(int *)(iVar4 + 0x98),uVar5);
      iVar1 = *(int *)(param_1 + 0xfc);
    }
    uVar5 = *(uint *)(iVar1 + 0x1c);
  }
  else {
    iVar3 = 0x103;
  }
LAB_c0557b7c:
  if ((**(uint **)(param_2 + 0x18) & 0xa0) == 0) {
    if ((*(uint *)(iVar4 + 0x7c) & 4) == 0) goto LAB_c0557be8;
    *(uint *)(iVar4 + 0x7c) = *(uint *)(iVar4 + 0x7c) & 0xfffffffb;
    cVar2 = *(char *)(param_1 + 0x3b) + -1;
  }
  else {
    if ((*(uint *)(iVar4 + 0x7c) & 4) != 0) goto LAB_c0557be8;
    *(uint *)(iVar4 + 0x7c) = *(uint *)(iVar4 + 0x7c) | 4;
    cVar2 = *(char *)(param_1 + 0x3b) + '\x01';
  }
  *(char *)(param_1 + 0x3b) = cVar2;
  FUN_c055691c(param_1);
LAB_c0557be8:
  if (((uVar5 & 0x80) == 0) || ((*(uint *)(param_1 + 0x1f0) & 8) != 0)) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xff7fffff;
  }
  else {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x800000;
  }
  if (iVar3 == 0x103) {
    *(uint *)(param_1 + 400) = uVar5 & 0xffffff7f;
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
    *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_2 + 0x18);
    *(short *)(param_1 + 0x1dc) = (short)*(undefined4 *)(param_2 + 0x1c);
    *(uint **)(param_2 + 0x18) = (uint *)(param_1 + 400);
    *(undefined4 *)(param_2 + 0x1c) = 4;
    iVar3 = FUN_c05574b4(param_1,param_2,0);
    if (iVar3 == 0x103) {
      return 0x103;
    }
  }
  if ((*(uint *)(param_2 + 0xc) & 8) != 0) {
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xfffffff7;
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x1d8);
    *(uint *)(param_2 + 0x1c) = (uint)*(ushort *)(param_1 + 0x1dc);
    *(undefined4 *)(param_1 + 0x1d8) = 0;
    *(undefined2 *)(param_1 + 0x1dc) = 0;
  }
  if (iVar3 == 0) {
    *(undefined4 *)(param_2 + 0x20) = 4;
  }
  else {
    *(undefined4 *)(param_2 + 0x20) = 0;
    *(undefined4 *)(param_2 + 0x24) = 0;
  }
  return iVar3;
}



/* c0557d00 FUN_c0557d00 */

/* Boundary evidence: original MIPS .pdata c0557d00..c0557e87. Semantic name remains unreviewed. */

int FUN_c0557d00(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(uint *)(param_2 + 0x1c) < 4) {
    iVar1 = -0x3ffeffec;
    *(undefined4 *)(param_2 + 0x24) = 4;
  }
  else {
    uVar3 = **(uint **)(param_2 + 0x18);
    if (*(uint *)(param_1 + 0x204) < uVar3) {
      iVar1 = -0x3ffeffec;
    }
    else {
      uVar2 = 0;
      for (iVar1 = *(int *)(param_1 + 0x18); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
        if (uVar2 < *(ushort *)(iVar1 + 0xa0)) {
          uVar2 = (uint)*(ushort *)(iVar1 + 0xa0);
        }
      }
      if (uVar2 < uVar3) {
        uVar2 = uVar3;
      }
      if (uVar2 == 0) {
        uVar2 = *(uint *)(param_1 + 0x204);
      }
      iVar1 = 0;
      if (*(uint *)(param_1 + 0x200) != uVar2) {
        *(uint *)(param_1 + 400) = uVar2;
        *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
        *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_2 + 0x18);
        *(short *)(param_1 + 0x1dc) = (short)*(undefined4 *)(param_2 + 0x1c);
        *(uint **)(param_2 + 0x18) = (uint *)(param_1 + 400);
        *(undefined4 *)(param_2 + 0x1c) = 4;
        iVar1 = FUN_c05574b4(param_1,param_2,0);
        if (iVar1 == 0x103) {
          return 0x103;
        }
      }
      if ((*(uint *)(param_2 + 0xc) & 8) != 0) {
        *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xfffffff7;
        *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x1d8);
        *(uint *)(param_2 + 0x1c) = (uint)*(ushort *)(param_1 + 0x1dc);
        *(undefined4 *)(param_1 + 0x1d8) = 0;
        *(undefined2 *)(param_1 + 0x1dc) = 0;
      }
      if (iVar1 == 0) {
        *(short *)(*(int *)(param_2 + 4) + 0xa0) = (short)uVar3;
        *(undefined4 *)(param_2 + 0x20) = 4;
        *(uint *)(param_1 + 0x200) = uVar2;
        return 0;
      }
    }
    *(undefined4 *)(param_2 + 0x24) = 0;
    *(undefined4 *)(param_2 + 0x20) = 0;
  }
  return iVar1;
}



/* c0557e88 FUN_c0557e88 */

/* Boundary evidence: original MIPS .pdata c0557e88..c0557f4f. Semantic name remains unreviewed. */

undefined4 FUN_c0557e88(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  uint uVar3;
  
  if (*(uint *)(param_2 + 0x1c) < 0x18) {
    uVar1 = 0xc0010014;
    *(undefined4 *)(param_2 + 0x24) = 0x18;
  }
  else {
    uVar3 = *(uint *)(param_2 + 0x1c) + 8;
    if (uVar3 < 8) {
      uVar1 = 0xc0010015;
    }
    else {
      pvVar2 = FUN_c05427a0(uVar3);
      if (pvVar2 != (void *)0x0) {
        memmove((void *)((int)pvVar2 + 8),*(void **)(param_2 + 0x18),*(size_t *)(param_2 + 0x1c));
        *(undefined4 *)((int)pvVar2 + 4) = *(undefined4 *)(param_2 + 4);
        *(void **)(param_2 + 8) = pvVar2;
        uVar1 = FUN_c05574b4(param_1,param_2,0);
        return uVar1;
      }
      uVar1 = 0xc000009a;
    }
    *(undefined4 *)(param_2 + 8) = 0;
  }
  return uVar1;
}



/* c0557f50 FUN_c0557f50 */

/* Boundary evidence: original MIPS .pdata c0557f50..c0557f8f. Semantic name remains unreviewed. */

undefined4 FUN_c0557f50(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(uint *)(param_2 + 0x1c) < 0x18) {
    uVar1 = 0xc0010014;
    *(undefined4 *)(param_2 + 0x24) = 0x18;
  }
  else {
    uVar1 = FUN_c05574b4(param_1,param_2,0);
  }
  return uVar1;
}



/* c0557f90 FUN_c0557f90 */

/* Boundary evidence: original MIPS .pdata c0557f90..c055800f. Semantic name remains unreviewed. */

undefined4 FUN_c0557f90(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  if (*(uint *)(param_2 + 0x1c) < 4) {
    uVar1 = 0xc0010014;
    *(undefined4 *)(param_2 + 0x24) = 4;
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 4) + 0xb8) = **(undefined4 **)(param_2 + 0x18);
    uVar2 = *(uint *)(param_1 + 0x2c0) & 5;
    for (iVar3 = *(int *)(param_1 + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
      uVar2 = *(uint *)(iVar3 + 0xb8) | uVar2;
    }
    *(uint *)(param_1 + 0x2c0) = uVar2;
    if ((*(uint *)(param_1 + 0x54) & 0x8000) != 0) {
      uVar1 = FUN_c05574b4(param_1,param_2,0);
    }
  }
  return uVar1;
}



/* c0558010 NdisMSetInformationComplete */

/* Boundary evidence: original MIPS .pdata c0558010..c055808f. Semantic name remains unreviewed. */

void NdisMSetInformationComplete(int param_1,int param_2)

{
                    /* 0x18010  151  NdisMSetInformationComplete */
  if ((*(uint *)(param_1 + 0x54) & 0x400) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c05577ec(param_1,param_2);
    if (*(int *)(param_1 + 500) != 0) {
      FUN_c054cc28(param_1,0,0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c0558090 FUN_c0558090 */

/* Boundary evidence: original MIPS .pdata c0558090..c05584e7. Semantic name remains unreviewed. */

int FUN_c0558090(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  void *_Dst;
  
  iVar5 = *(int *)(param_2 + 4);
  if (iVar5 == 0) goto LAB_c05580b4;
  puVar6 = *(uint **)(param_2 + 0x18);
  if ((*(int *)(param_2 + 0x14) == 0x10114) || (*(int *)(param_2 + 0x14) == 0x10107)) {
    *(undefined2 *)(param_1 + 0x43a) = 2;
  }
  uVar4 = *(uint *)(param_2 + 0x14);
  if (0x1010102 < uVar4) {
    if (uVar4 == 0x1010103) {
      if (*(int *)(param_1 + 0x11c) == 0) {
        iVar5 = FUN_c05563f4(param_1,param_2);
        return iVar5;
      }
      return -0x3ffeffe9;
    }
    if (uVar4 == 0x1010104) {
      iVar5 = 0;
      if (*(uint *)(param_2 + 0x1c) < 4) {
        *(undefined4 *)(param_2 + 0x24) = 4;
        iVar5 = -0x3ffeffec;
      }
      if (*(int *)(param_1 + 0x11c) != 0) {
        iVar5 = -0x3ffeffe9;
      }
      if (iVar5 != 0) {
        return iVar5;
      }
      *puVar6 = *(uint *)(param_1 + 0x1f8);
      goto LAB_c05584a4;
    }
    if (uVar4 == 0x2010103) {
      iVar1 = 0;
      if (*(uint *)(param_2 + 0x1c) < 4) {
        *(undefined4 *)(param_2 + 0x24) = 4;
        iVar1 = -0x3ffeffec;
      }
      if (*(int *)(param_1 + 0x11c) != 1) {
        iVar1 = -0x3ffeffe9;
      }
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar4 = *(uint *)(*(int *)(iVar5 + 0x98) + 0x20);
    }
    else {
      if (uVar4 != 0x2010104) {
        if (uVar4 == 0xfd010105) {
          iVar5 = FUN_c05564a4(param_1,param_2);
          return iVar5;
        }
        if (uVar4 != 0xfd010106) goto LAB_c05580b4;
        if (3 < *(uint *)(param_2 + 0x1c)) {
          **(undefined4 **)(param_2 + 0x18) = *(undefined4 *)(*(int *)(param_2 + 4) + 0xb8);
          *(undefined4 *)(param_2 + 0x20) = 4;
          *(undefined4 *)(param_2 + 0x24) = 0;
          return 0;
        }
        goto LAB_c05581b8;
      }
      iVar5 = 0;
      if (*(uint *)(param_2 + 0x1c) < 4) {
        *(undefined4 *)(param_2 + 0x24) = 4;
        iVar5 = -0x3ffeffec;
      }
      if (*(int *)(param_1 + 0x11c) != 1) {
        iVar5 = -0x3ffeffe9;
      }
      if (iVar5 != 0) {
        return iVar5;
      }
      uVar4 = *(uint *)(*(int *)(param_1 + 0xfc) + 0x3c);
    }
    *puVar6 = (uVar4 & 0xff0000 | uVar4 >> 0x10) >> 8 | (uVar4 << 0x10 | uVar4 & 0xff00) << 8;
LAB_c05584a4:
    *(undefined4 *)(param_2 + 0x20) = 4;
    return 0;
  }
  if (uVar4 < 0x1010101) {
    if (uVar4 < 0x1010f) {
      if (uVar4 == 0x1010e) {
        iVar5 = FUN_c0556384(param_1,param_2);
        return iVar5;
      }
      uVar3 = uVar4 - 0x10103;
      if ((uVar4 == 0x10103) || (uVar3 < 2)) {
        if (3 < *(uint *)(param_2 + 0x1c)) {
          **(undefined4 **)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x11c);
          *(undefined4 *)(param_2 + 0x20) = 4;
          return 0;
        }
        uVar2 = 4;
        goto LAB_c05581e0;
      }
      if (uVar3 != 2) {
        if ((uVar3 == 3) && (*(uint *)(param_2 + 0x1c) < 4)) {
          *(undefined4 *)(param_2 + 0x24) = 4;
          return -0x3ffeffec;
        }
        goto LAB_c05580b4;
      }
      if (3 < *(uint *)(param_2 + 0x1c)) {
        *puVar6 = *(uint *)(param_1 + 0x204);
        goto LAB_c05582dc;
      }
    }
    else {
      if (uVar4 == 0x1010f) {
        if (*(uint *)(param_2 + 0x1c) < 2) {
          *(undefined4 *)(param_2 + 0x24) = 2;
          return -0x3ffeffec;
        }
        *puVar6 = (uint)*(ushort *)(iVar5 + 0xa0);
LAB_c05582dc:
        *(undefined4 *)(param_2 + 0x20) = 4;
        return 0;
      }
      if (uVar4 != 0x10111) {
        if (uVar4 == 0x20216) {
          uVar4 = (uint)**(ushort **)(param_1 + 0x1e8);
          if (uVar4 + 2 <= *(uint *)(param_2 + 0x1c)) {
            _Dst = *(void **)(param_2 + 0x18);
            memcpy(_Dst,*(void **)(*(ushort **)(param_1 + 0x1e8) + 2),uVar4);
            *(undefined2 *)((uint)**(ushort **)(param_1 + 0x1e8) + (int)_Dst) = 0;
            iVar5 = **(ushort **)(param_1 + 0x1e8) + 2;
            *(int *)(param_2 + 0x24) = iVar5;
            *(int *)(param_2 + 0x20) = iVar5;
            return 0;
          }
          return -0x3ffeffea;
        }
LAB_c05580b4:
        iVar5 = FUN_c05574b4(param_1,param_2,1);
        return iVar5;
      }
      if (3 < *(uint *)(param_2 + 0x1c)) goto LAB_c05580b4;
    }
LAB_c05581b8:
    *(undefined4 *)(param_2 + 0x24) = 4;
  }
  else {
    if (5 < *(uint *)(param_2 + 0x1c)) goto LAB_c05580b4;
    uVar2 = 6;
LAB_c05581e0:
    *(undefined4 *)(param_2 + 0x24) = uVar2;
  }
  return -0x3ffeffec;
}



/* c05584e8 FUN_c05584e8 */

/* Boundary evidence: original MIPS .pdata c05584e8..c05589f3. Semantic name remains unreviewed. */

void FUN_c05584e8(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint _Size;
  uint *_Src;
  uint uVar7;
  int local_38;
  uint local_34;
  uint local_30 [2];
  
  iVar6 = *(int *)(param_1 + 500);
  uVar7 = local_30[0];
  do {
    if ((iVar6 == 0) || ((*(uint *)(param_1 + 0x54) & 0x400) != 0)) {
      return;
    }
    *(undefined2 *)(param_1 + 0x43a) = 0;
    local_38 = 0;
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffeff | 0x400;
    iVar3 = *(int *)(iVar6 + 0x10);
    bVar1 = true;
    if (iVar3 == 0) {
      local_38 = FUN_c0558090(param_1,iVar6);
LAB_c05589bc:
      if (local_38 != 0x103) goto LAB_c0558644;
      if ((*(uint *)(param_1 + 0x54) & 0x400) != 0) {
        return;
      }
    }
    else {
      if (iVar3 == 1) {
        local_38 = FUN_c0557744(param_1,iVar6);
        goto LAB_c05589bc;
      }
      if (iVar3 == 2) {
        uVar4 = *(uint *)(iVar6 + 0x14);
        _Src = &local_34;
        _Size = 4;
        if (uVar4 < 0x10114) {
          if (uVar4 == 0x10113) {
            bVar1 = false;
            local_38 = FUN_c05574b4(param_1,iVar6,1);
            if (local_38 == 0) {
              puVar5 = *(uint **)(iVar6 + 0x18);
              uVar4 = *(uint *)(param_1 + 0x1f0) & 0x80 | *puVar5;
LAB_c055872c:
              bVar1 = false;
              *puVar5 = uVar4;
            }
          }
          else {
            uVar2 = uVar4 - 0x10103;
            if ((uVar4 == 0x10103) || (uVar2 < 2)) {
              _Src = (uint *)(param_1 + 0x11c);
              _Size = 4;
            }
            else if (uVar2 == 2) {
              local_34 = *(uint *)(param_1 + 0x204);
            }
            else if (uVar2 == 0xb) {
              if (*(int *)(param_1 + 0x11c) == 0) {
                uVar7 = *(uint *)(*(int *)(param_1 + 0xf8) + 0x1c);
                local_34 = uVar7;
              }
              else {
                local_34 = uVar7;
                if (*(int *)(param_1 + 0x11c) == 1) {
                  uVar7 = *(uint *)(*(int *)(param_1 + 0xfc) + 0x1c);
                  local_34 = uVar7;
                }
              }
            }
            else {
              if (uVar2 != 0xc) goto LAB_c055878c;
              local_34 = *(uint *)(param_1 + 0x200);
            }
          }
        }
        else if ((uVar4 == 0x1010103) || (uVar4 + 0xfefefefd < 2)) {
          if (*(int *)(param_1 + 0x11c) == 0) {
            if (uVar4 == 0x1010103) {
              EthQueryGlobalFilterAddresses
                        (&local_38,*(int *)(param_1 + 0xf8),*(uint *)(iVar6 + 0x1c),local_30,
                         *(void **)(iVar6 + 0x18));
              if (local_38 == 0) {
                *(uint *)(iVar6 + 0x20) = local_30[0] * 6;
              }
              else {
                *(int *)(iVar6 + 0x24) = *(int *)(*(int *)(param_1 + 0xf8) + 0x44) * 6;
                local_38 = -0x3ffeffec;
              }
              bVar1 = false;
            }
            else if (uVar4 == 0x1010104) {
              local_34 = *(uint *)(param_1 + 0x1f8);
            }
          }
          else {
            local_38 = -0x3ffeffe9;
            _Size = 0;
          }
        }
        else {
          uVar2 = uVar4 + 0xfdfefefd;
          if ((uVar4 == 0x2010103) || (uVar2 < 2)) {
            if (*(int *)(param_1 + 0x11c) == 1) {
              if (uVar4 == 0x2010103) {
                uVar4 = *(uint *)(*(int *)(param_1 + 0xfc) + 0x38);
                uVar2 = uVar4 & 0xff0000 | uVar4 >> 0x10;
                uVar4 = uVar4 << 0x10 | uVar4 & 0xff00;
              }
              else {
                if (uVar4 != 0x2010104) goto LAB_c0558618;
                uVar4 = *(uint *)(*(int *)(param_1 + 0xfc) + 0x3c);
                uVar2 = uVar4 & 0xff0000 | uVar4 >> 0x10;
                uVar4 = uVar4 << 0x10 | uVar4 & 0xff00;
              }
              local_34 = uVar2 >> 8 | uVar4 << 8;
            }
            else {
              local_38 = -0x3ffeffe9;
              _Size = 0;
            }
          }
          else if (uVar2 == 0xfafffffd) {
            bVar1 = false;
            local_38 = FUN_c05574b4(param_1,iVar6,1);
            if ((local_38 == 0) && ((*(uint *)(param_1 + 0x54) & 0x8000) == 0)) {
              puVar5 = *(uint **)(iVar6 + 0x18);
              uVar4 = *(uint *)(param_1 + 0x270);
              goto LAB_c055872c;
            }
          }
          else {
            if (uVar2 == 0xfb000002) {
              bVar1 = false;
              local_38 = FUN_c05574b4(param_1,iVar6,1);
              if (local_38 != -0x3fffff45) goto LAB_c0558618;
              local_38 = FUN_c05564a4(param_1,iVar6);
            }
            else {
LAB_c055878c:
              local_38 = FUN_c05574b4(param_1,iVar6,1);
            }
            bVar1 = false;
          }
        }
LAB_c0558618:
        if (bVar1) {
          if (local_38 == 0) {
            if (*(uint *)(iVar6 + 0x1c) < _Size) {
              *(uint *)(iVar6 + 0x24) = _Size;
              local_38 = -0x3ffeffec;
              goto LAB_c0558644;
            }
            *(uint *)(iVar6 + 0x20) = _Size;
            if ((_Size != 0) && (_Src != *(uint **)(iVar6 + 0x18))) {
              memmove(*(uint **)(iVar6 + 0x18),_Src,_Size);
            }
          }
          else {
            *(uint *)(iVar6 + 0x24) = _Size;
          }
        }
        goto LAB_c05589bc;
      }
LAB_c0558644:
      iVar6 = *(int *)(iVar6 + 0x10);
      if (iVar6 == 0) {
LAB_c0558660:
        FUN_c0556d30(param_1,local_38);
      }
      else if (iVar6 == 1) {
        FUN_c05577ec(param_1,local_38);
      }
      else if (iVar6 == 2) goto LAB_c0558660;
    }
    iVar6 = *(int *)(param_1 + 500);
  } while( true );
}



/* c05589f4 FUN_c05589f4 */

/* Boundary evidence: original MIPS .pdata c05589f4..c0558a83. Semantic name remains unreviewed. */

void FUN_c05589f4(int param_1)

{
  if (((*(uint *)(*(int *)(param_1 + 0x244) + 0xc) & 0x80000000) != 0) &&
     (*(int *)(param_1 + 0x354) == 1)) {
    *(undefined4 *)(*(int *)(param_1 + 0x244) + 4) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x244) + 0xc) = 0;
    FUN_c05565d0(param_1,*(int **)(param_1 + 0x244));
    if ((*(uint *)(param_1 + 0x54) & 0x40000) == 0) {
      FUN_c054cc28(param_1,0,0);
    }
    else {
      FUN_c05584e8(param_1);
    }
  }
  return;
}



/* c0558a84 FUN_c0558a84 */

/* Boundary evidence: original MIPS .pdata c0558a84..c0558cf3. Semantic name remains unreviewed. */

int FUN_c0558a84(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  int *local_28;
  int local_24;
  
  iVar5 = *(int *)(param_1 + 8);
  local_28 = (int *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (*(int *)(iVar5 + 0x354) < 5) {
    iVar1 = FUN_c0555e58(param_1,iVar5,(int)param_2,&local_24);
    if (iVar1 == 0) {
      param_2[1] = param_1;
      param_2[3] = 0;
      NdisInterlockedIncrement((LONG *)(param_1 + 0x80));
      param_2[2] = 0;
      if (((param_2[4] == 1) && (param_2[5] == 0x10112)) &&
         (puVar4 = (uint *)param_2[6], puVar4 != (uint *)0x0)) {
        if ((*puVar4 & 4) != 0) {
          *puVar4 = *puVar4 & 0xfffffffb;
          *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 8;
        }
        if (((*puVar4 & 2) != 0) && ((*(uint *)(iVar5 + 0x1f0) & 8) != 0)) {
          *puVar4 = *puVar4 & 0xfffffffd;
          *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 2;
        }
      }
      if (((*(uint *)(iVar5 + 0x54) & 0x40000) == 0) &&
         (iVar1 = FUN_c0556074((int)param_2,(int *)&local_28), param_2 = local_28, iVar1 != 0)) {
        NdisInterlockedDecrement((LONG *)(param_1 + 0x80));
        local_24 = iVar1;
      }
      else {
        iVar1 = FUN_c05565d0(iVar5,param_2);
        if (iVar1 == 0) {
          local_24 = -0x3ffffff0;
        }
        else {
          if ((*(uint *)(iVar5 + 0x54) & 0x40000) == 0) {
            iVar1 = __GetUserKData(8);
            uVar2 = (uint)(*(int *)(iVar5 + 0x4b4) != iVar1);
            if (uVar2 == 1) {
              uVar2 = TryEnterCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x4b0));
              uVar2 = uVar2 & 0xff;
              if (uVar2 == 1) {
                *(undefined4 *)(iVar5 + 0x454) = 0xc0221;
                uVar3 = __GetUserKData(8);
                *(undefined4 *)(iVar5 + 0x458) = uVar3;
              }
            }
            FUN_c054cc28(iVar5,0,0);
            if ((uVar2 != 0) && (FUN_c054eae0(iVar5), uVar2 != 0)) {
              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x4b0));
              *(undefined4 *)(iVar5 + 0x454) = 0;
              *(undefined4 *)(iVar5 + 0x458) = 0;
            }
          }
          else {
            FUN_c05584e8(iVar5);
          }
          local_24 = 0x103;
        }
      }
    }
  }
  else {
    local_24 = -0x3ffeffe8;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return local_24;
}



/* c0558cf4 FUN_c0558cf4 */

/* Boundary evidence: original MIPS .pdata c0558cf4..c0558df3. Semantic name remains unreviewed. */

void FUN_c0558cf4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *param_1;
  iVar4 = *(int *)(iVar5 + 0x2c);
  iVar1 = FUN_c054df18(iVar4,0);
  if (iVar1 == 0) {
    DbgPrint("Ndis: ndisMRundownRequests Open is gone. DeferredRequestWorkItem %p\n",iVar5,param_3,
             param_4);
    DbgBreakPoint();
  }
  else {
    piVar3 = *(int **)(iVar5 + 0x28);
    iVar1 = FUN_c0558a84(iVar4,piVar3);
    if (iVar1 != 0x103) {
      piVar3[3] = piVar3[3] | 0x80000000;
      iVar2 = FUN_c05561c0((int)piVar3);
      (**(code **)(iVar4 + 0x5c))(*(undefined4 *)(iVar4 + 0x10),iVar2,iVar1);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    NdisInterlockedDecrement((LONG *)(iVar4 + 0x80));
    iVar1 = NdisInterlockedDecrement((LONG *)(iVar4 + 0x80));
    if (iVar1 == 0) {
      FUN_c0559efc(iVar4);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    CTEFreeMem(iVar5);
  }
  return;
}



/* c0558df4 FUN_c0558df4 */

/* Boundary evidence: original MIPS .pdata c0558df4..c0558f9b. Semantic name remains unreviewed. */

int FUN_c0558df4(int param_1,int param_2)

{
  void *_Dst;
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_20 [2];
  
  _Dst = FUN_c05427a0(0x38);
  if (_Dst == (void *)0x0) {
    local_20[0] = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0x38);
    iVar1 = FUN_c054df18(param_1,1);
    if (iVar1 == 0) {
      CTEFreeMem(_Dst);
      local_20[0] = -0x3ffefffe;
    }
    else {
      iVar1 = *(int *)(param_1 + 8);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      iVar1 = FUN_c0555e58(param_1,iVar1,param_2,local_20);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      if (iVar1 == 0) {
        piVar3 = (int *)((int)_Dst + 0x28);
        iVar1 = FUN_c0556074(param_2,piVar3);
        if (iVar1 == 0) {
          *(int *)((int)_Dst + 0x2c) = param_1;
          *(undefined4 *)((int)_Dst + 0x30) = *(undefined4 *)(param_2 + 0x14);
          *(undefined4 *)((int)_Dst + 0x34) = *(undefined4 *)(*piVar3 + 0x18);
          *(int *)(*piVar3 + 4) = param_1;
          *(undefined4 *)(*piVar3 + 0xc) = 0;
          NdisInterlockedIncrement((LONG *)(param_1 + 0x80));
          *(void **)_Dst = _Dst;
          *(code **)((int)_Dst + 4) = FUN_c0558cf4;
          *(code **)((int)_Dst + 0x10) = FUN_c0558cf4;
          *(void **)((int)_Dst + 0x14) = _Dst;
          FUN_c055f0e8((LPCRITICAL_SECTION)&DAT_c0565454,(LPCRITICAL_SECTION)((int)_Dst + 8));
          local_20[0] = 0x103;
        }
        else {
          CTEFreeMem(_Dst);
          iVar2 = NdisInterlockedDecrement((LONG *)(param_1 + 0x80));
          local_20[0] = iVar1;
          if (iVar2 == 0) {
            FUN_c0559efc(param_1);
          }
        }
      }
      else {
        CTEFreeMem(_Dst);
        iVar1 = NdisInterlockedDecrement((LONG *)(param_1 + 0x80));
        if (iVar1 == 0) {
          FUN_c0559efc(param_1);
        }
      }
    }
  }
  return local_20[0];
}



/* c0558f9c FUN_c0558f9c */

/* Boundary evidence: original MIPS .pdata c0558f9c..c0559057. Semantic name remains unreviewed. */

void FUN_c0558f9c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0xdc) & 0x80000000) != 0) {
    *(uint *)(param_2 + 0x490) = *(uint *)(param_2 + 0x490) & 0x7fffffff;
    *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0x7fffffff;
  }
  iVar2 = *(int *)(param_2 + 0x18);
  if (iVar2 == param_1) {
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x14);
    *(short *)(param_2 + 0x438) = *(short *)(param_2 + 0x438) + -1;
  }
  else if (iVar2 != 0) {
    do {
      iVar1 = *(int *)(iVar2 + 0x14);
      if (iVar1 == param_1) break;
      iVar2 = iVar1;
    } while (iVar1 != 0);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x14);
      *(short *)(param_2 + 0x438) = *(short *)(param_2 + 0x438) + -1;
    }
  }
  FUN_c055691c(param_2);
  return;
}



/* c0559058 FUN_c0559058 */

/* Boundary evidence: original MIPS .pdata c0559058..c05590d7. Semantic name remains unreviewed. */

bool FUN_c0559058(int param_1,int param_2)

{
  bool bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  bVar1 = *(char *)(param_2 + 0xb6) == '\0';
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 4);
    *(int *)(param_2 + 4) = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return bVar1;
}



/* c05590d8 FUN_c05590d8 */

/* Boundary evidence: original MIPS .pdata c05590d8..c055915b. Semantic name remains unreviewed. */

void FUN_c05590d8(int param_1,int param_2)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  piVar1 = (int *)(param_2 + 4);
  do {
    if (*piVar1 == 0) {
LAB_c0559138:
      *(undefined4 *)(param_1 + 0x1c) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      return;
    }
    if (*piVar1 == param_1) {
      *piVar1 = *(int *)(param_1 + 0x1c);
      goto LAB_c0559138;
    }
    piVar1 = (int *)(*piVar1 + 0x1c);
  } while( true );
}



/* c055915c FUN_c055915c */

/* Boundary evidence: original MIPS .pdata c055915c..c055923f. Semantic name remains unreviewed. */

void FUN_c055915c(int *param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int *piVar3;
  
  bVar1 = FUN_c055a474((int)(param_1 + 0x28));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    if (param_2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    piVar2 = &DAT_c0565400;
    do {
      piVar3 = piVar2;
      if (*piVar3 == 0) goto LAB_c05591d8;
      piVar2 = (int *)*piVar3;
    } while ((int *)*piVar3 != param_1);
    *piVar3 = *param_1;
LAB_c05591d8:
    if (param_2 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    if (param_1[2] != 0) {
      CTEFreeMem();
      param_1[2] = 0;
    }
    piVar2 = (int *)param_1[6];
    while (piVar2 != (int *)0x0) {
      piVar2 = (int *)*piVar2;
      CTEFreeMem();
    }
    EventModify(param_1[0x27],3);
  }
  return;
}



/* c0559240 FUN_c0559240 */

/* Boundary evidence: original MIPS .pdata c0559240..c0559363. Semantic name remains unreviewed. */

void FUN_c0559240(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_c0561324(param_1);
  if ((iVar1 != 0) && ((*(ushort *)(iVar1 + 0xb8) & 0x10) == 0)) {
    *(ushort *)(iVar1 + 0xb8) = *(ushort *)(iVar1 + 0xb8) | 8;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  for (piVar2 = DAT_c0565400; (piVar2 != (int *)0x0 && (*(int *)piVar2[2] != param_1));
      piVar2 = (int *)*piVar2) {
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (piVar2 != (int *)0x0) {
    *(ushort *)(piVar2 + 0x2e) = *(ushort *)(piVar2 + 0x2e) | 0x8000;
    if ((code *)piVar2[7] != (code *)0x0) {
      (*(code *)piVar2[7])(param_1);
    }
    if (piVar2[3] != 0) {
      *(undefined4 *)(piVar2[3] + 0xc0) = 0;
      piVar2[3] = 0;
    }
    FUN_c055915c(piVar2,0);
    WaitForSingleObject((HANDLE)piVar2[0x27],0xffffffff);
    EventModify(piVar2[0x27],2);
    CloseHandle((HANDLE)piVar2[0x27]);
    FUN_c055a518((LPCRITICAL_SECTION)(piVar2 + 0x28));
  }
  return;
}



/* c0559364 FUN_c0559364 */

/* Boundary evidence: original MIPS .pdata c0559364..c05596e7. Semantic name remains unreviewed. */

undefined4 FUN_c0559364(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  HANDLE *ppvVar4;
  HANDLE local_30;
  HANDLE *local_2c;
  
  uVar2 = 1;
  do {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c054b758(param_1);
    if ((*(uint *)(param_1 + 0x248) & 0x40000000) == 0) {
      *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0x40000000;
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
      *(undefined4 *)(param_1 + 0x454) = 0;
      *(undefined4 *)(param_1 + 0x458) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      break;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
    *(undefined4 *)(param_1 + 0x454) = 0;
    *(undefined4 *)(param_1 + 0x458) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    Sleep(500);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 10);
  if (uVar2 == 10) {
    return 0xc0000001;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  FUN_c054b758(param_1);
  bVar1 = (*(uint *)(param_1 + 0x248) & 0x4000000) != 0;
  if (bVar1) {
    local_30 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE **)(param_1 + 0x478) = &local_30;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (*(int *)(param_1 + 0x478) != 0) {
    WaitForSingleObject(local_30,0xffffffff);
  }
  if (bVar1) {
    CloseHandle(local_30);
  }
  *(undefined4 *)(param_1 + 0x478) = 0;
  if (param_2 == 0) {
    local_30 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  }
  local_2c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  ppvVar4 = local_2c;
  if (param_2 == 0) {
    if ((*(int *)(param_1 + 0x18) == 0) || (*(int *)(param_1 + 0x3b0) != 0)) {
      ppvVar4 = (HANDLE *)0x0;
    }
    else {
      *(HANDLE **)(param_1 + 0x3b0) = &local_30;
      ppvVar4 = &local_30;
    }
  }
LAB_c0559560:
  do {
    for (iVar3 = *(int *)(param_1 + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      if ((((param_2 == 0) || (*(int *)(iVar3 + 0xc) == param_2)) &&
          (uVar2 = *(uint *)(iVar3 + 0x7c), (uVar2 & 0x8010) == 0)) &&
         (*(uint *)(iVar3 + 0x7c) = uVar2 | 0x10, (uVar2 & 0x10000) == 0)) {
        *(uint *)(iVar3 + 0x7c) = uVar2 | 0x210010;
        *(HANDLE ***)(iVar3 + 0xbc) = &local_2c;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        FUN_c054acf4(iVar3,0);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        if (param_2 == 0) goto LAB_c0559560;
        break;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    }
    if ((param_2 != 0) || (iVar3 = *(int *)(param_1 + 0x18), iVar3 == 0)) {
LAB_c0559660:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      if (param_2 == 0) {
        if (ppvVar4 != (HANDLE *)0x0) {
          WaitForSingleObject(*ppvVar4,0xffffffff);
        }
        CloseHandle(local_30);
      }
      CloseHandle(local_2c);
      *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) & 0xbfffffff;
      return 0;
    }
    do {
      if ((*(uint *)(iVar3 + 0x7c) & 0x10000) == 0) break;
      iVar3 = *(int *)(iVar3 + 0x14);
    } while (iVar3 != 0);
    if (iVar3 == 0) goto LAB_c0559660;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    Sleep(1);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  } while( true );
}



/* c05596e8 NdisMSetPeriodicTimer */

/* Boundary evidence: original MIPS .pdata c05596e8..c0559703. Semantic name remains unreviewed. */

void NdisMSetPeriodicTimer(int *param_1,int param_2)

{
                    /* 0x196e8  153  NdisMSetPeriodicTimer */
  FUN_c0560ddc(param_1,param_2,(int)(param_1 + 8));
  return;
}



/* c0559704 NdisMSleep */

/* Boundary evidence: original MIPS .pdata c0559704..c0559737. Semantic name remains unreviewed. */

void NdisMSleep(int param_1)

{
                    /* 0x19704  155  NdisMSleep */
  Sleep((param_1 + 999U) / 1000);
  return;
}



/* c0559738 FUN_c0559738 */

/* Boundary evidence: original MIPS .pdata c0559738..c055990f. Semantic name remains unreviewed. */

void FUN_c0559738(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  undefined4 *puVar3;
  char local_18 [8];
  
  bVar1 = FUN_c055a474(param_1 + 0x20);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    puVar3 = *(undefined4 **)(param_1 + 0x3ac);
    bVar1 = FUN_c054dce8(param_1);
    if ((CONCAT31(extraout_var_00,bVar1) != 0) && (*(short *)(param_1 + 0x34) == 0)) {
      if (*(int *)(param_1 + 0xf8) != 0) {
        EthDeleteFilter(*(int *)(param_1 + 0xf8));
        *(undefined4 *)(param_1 + 0xf8) = 0;
      }
      if (*(int *)(param_1 + 0xfc) != 0) {
        FUN_c055a654(*(int *)(param_1 + 0xfc));
        *(undefined4 *)(param_1 + 0xfc) = 0;
      }
      if (*(int *)(param_1 + 0x264) != 0) {
        CTEFreeMem();
      }
      iVar2 = *(int *)(param_1 + 0x84);
      while (iVar2 != 0) {
        if (*(undefined4 **)(param_1 + 0x84) != (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 0x84) = **(undefined4 **)(param_1 + 0x84);
        }
        CTEFreeMem();
        iVar2 = *(int *)(param_1 + 0x84);
      }
      if (*(int *)(param_1 + 0x40c) != 0) {
        CTEFreeMem();
        *(undefined4 *)(param_1 + 0x40c) = 0;
      }
      if ((*(uint *)(param_1 + 0x248) & 8) != 0) {
        *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) & 0xfffffff7 | 0x200;
        NdisCancelTimer((int *)(param_1 + 0x30c),local_18);
        if (local_18[0] == '\0') {
          Sleep(((uint)*(ushort *)(param_1 + 0x34c) * 1000000 + 999) / 1000);
        }
      }
      if (*(int *)(param_1 + 0x2f4) != 0) {
        CTEFreeMem();
        *(undefined4 *)(param_1 + 0x2f4) = 0;
      }
      if (*(int *)(param_1 + 0x44c) != 0) {
        CTEFreeMem();
        *(undefined4 *)(param_1 + 0x44c) = 0;
      }
      FUN_c05590d8(param_1,*(int *)(param_1 + 8));
      FUN_c055915c(*(int **)(param_1 + 8),0);
      NdisMDeregisterAdapterShutdownHandler(param_1);
      if (*(int *)(param_1 + 0x1b0) != 0) {
        FUN_c055f5d0(param_1 + 0x1ac);
        *(undefined4 *)(param_1 + 0x1b0) = 0;
      }
    }
    if (puVar3 != (undefined4 *)0x0) {
      EventModify(*puVar3,3);
    }
  }
  return;
}



/* c0559910 FUN_c0559910 */

/* Boundary evidence: original MIPS .pdata c0559910..c0559d73. Semantic name remains unreviewed. */

void FUN_c0559910(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char *pcVar2;
  undefined4 uVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  char local_38 [4];
  HANDLE local_34;
  undefined4 local_30;
  
  uVar3 = 0;
  local_30 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  FUN_c054b758(param_1);
  *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0xa0000;
  if ((*(uint *)(param_1 + 0x54) & 0x200000) != 0) {
    param_4 = 0;
    local_34 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE **)(param_1 + 0x474) = &local_34;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x4b0);
  LeaveCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (*(int *)(param_1 + 0x474) != 0) {
    WaitForSingleObject(local_34,0xffffffff);
  }
  *(undefined4 *)(param_1 + 0x474) = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  FUN_c054b758(param_1);
  if ((*(uint *)(param_1 + 0x248) & 0x4000000) != 0) {
    param_4 = 0;
    local_34 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE **)(param_1 + 0x478) = &local_34;
  }
  LeaveCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (*(int *)(param_1 + 0x478) != 0) {
    WaitForSingleObject(local_34,0xffffffff);
  }
  *(undefined4 *)(param_1 + 0x478) = 0;
  NdisCancelTimer((int *)(param_1 + 0xb8),local_38);
  if (local_38[0] == '\0') {
    Sleep(2000);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  FUN_c054b758(param_1);
  if (*(int *)(param_1 + 500) != 0) {
    param_4 = 0;
    local_34 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE **)(param_1 + 0x3b4) = &local_34;
  }
  LeaveCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (*(int *)(param_1 + 0x3b4) != 0) {
    WaitForSingleObject(local_34,0xffffffff);
    CloseHandle(local_34);
  }
  *(undefined4 *)(param_1 + 0x3b4) = 0;
  if ((*(uint *)(param_1 + 0x54) & 0x8000) != 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x108);
    *(code **)(param_1 + 0x108) = FUN_c055b714;
    local_30 = uVar3;
    Sleep(1);
  }
  (**(code **)(*(int *)(param_1 + 8) + 0x34))(*(undefined4 *)(param_1 + 0xc));
  if ((*(uint *)(param_1 + 0x54) & 0x8000) != 0) {
    *(undefined4 *)(param_1 + 0x108) = uVar3;
  }
  *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) & 0xfff7ffff;
  memset((void *)(param_1 + 0x388),0,0x20);
  if ((*(int *)(param_1 + 0x1ec) != 0) || (*(int *)(param_1 + 0x50) != 0)) {
    if (*(int *)(param_1 + 0x50) == 0) {
      pcVar2 = "Unloading without deregistering timer";
    }
    else {
      pcVar2 = "Unloading without deregistering interrupt";
    }
    DbgPrint(" ***NDIS*** : Miniport %Z - %s\n",*(undefined4 *)(param_1 + 0x1e8),pcVar2,param_4);
    trap(0x400);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  FUN_c054b758(param_1);
  FUN_c054d51c(param_1,(int ****)0x0,0);
  FUN_c054cb5c(param_1,0,(undefined4 *)0x0,(undefined4 *)0x0);
  FUN_c054d464(param_1);
  piVar1 = *(int **)(param_1 + 0x1d0);
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  while (piVar1 != (int *)0x0) {
    piVar1 = (int *)*piVar1;
    CTEFreeMem();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return;
}



/* c0559d74 FUN_c0559d74 */

/* Boundary evidence: original MIPS .pdata c0559d74..c0559d7f. Semantic name remains unreviewed. */

undefined4 FUN_c0559d74(void)

{
  return 1;
}



/* c0559d80 FUN_c0559d80 */

/* Boundary evidence: original MIPS .pdata c0559d80..c0559dd7. Semantic name remains unreviewed. */

void FUN_c0559d80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_c055a534(param_1 + 0x20);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    if ((*(uint *)(param_1 + 0x248) & 0x4000) == 0) {
      FUN_c0559910(param_1,param_2,param_3,param_4);
      NdisMDeregisterAdapterShutdownHandler(param_1);
    }
    FUN_c0559738(param_1);
  }
  return;
}



/* c0559dd8 FUN_c0559dd8 */

/* Boundary evidence: original MIPS .pdata c0559dd8..c0559efb. Semantic name remains unreviewed. */

void FUN_c0559dd8(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  FUN_c055a404(iVar3 + 0x20);
  (**(code **)(*(int *)(param_1 + 0xc) + 0x30))(*(undefined4 *)(param_1 + 0x10),0);
  FUN_c0559738(iVar3);
  FUN_c0548ad8(*(int *)(param_1 + 0xc));
  if (*(undefined4 **)(param_1 + 0xbc) != (undefined4 *)0x0) {
    EventModify(**(undefined4 **)(param_1 + 0xbc),3);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  puVar2 = *(undefined4 **)(iVar3 + 0x3b0);
  if ((puVar2 != (undefined4 *)0x0) && (*(int *)(iVar3 + 0x18) == 0)) {
    *(undefined4 *)(iVar3 + 0x3b0) = 0;
    EventModify(*puVar2,3);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  bVar1 = (*(uint *)(param_1 + 0x7c) & 0x200000) == 0;
  if (!bVar1) {
    *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 0x100000;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (bVar1) {
    FUN_c054dfe8(param_1);
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x84));
    CTEFreeMem(param_1);
  }
  FUN_c0559738(iVar3);
  return;
}



/* c0559efc FUN_c0559efc */

/* Boundary evidence: original MIPS .pdata c0559efc..c0559fab. Semantic name remains unreviewed. */

void FUN_c0559efc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  FUN_c055a404(iVar1 + 0x20);
  FUN_c0548eb4(param_1,*(int **)(param_1 + 0xc));
  if ((*(uint *)(param_1 + 0x7c) & 4) != 0) {
    *(char *)(iVar1 + 0x3b) = *(char *)(iVar1 + 0x3b) + -1;
    *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xfffffffb;
    FUN_c055691c(iVar1);
  }
  FUN_c0558f9c(param_1,iVar1);
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(code **)(param_1 + 0xcc) = FUN_c0559dd8;
  *(int *)(param_1 + 0xd0) = param_1;
  FUN_c055f0e8((LPCRITICAL_SECTION)&DAT_c0565454,(LPCRITICAL_SECTION)(param_1 + 0xc4));
  FUN_c0559738(iVar1);
  return;
}



/* c0559fac FUN_c0559fac */

/* Boundary evidence: original MIPS .pdata c0559fac..c055a167. Semantic name remains unreviewed. */

undefined4 FUN_c0559fac(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar5 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  for (iVar4 = *(int *)(iVar3 + 0x18); (iVar4 != 0 && (iVar4 != param_1));
      iVar4 = *(int *)(iVar4 + 0x14)) {
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if (iVar4 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    if ((*(uint *)(param_1 + 0x7c) & 0x8000) == 0) {
      *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 0x8000;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      FUN_c054b758(iVar3);
      piVar1 = *(int **)(param_1 + 0x98);
      if (*(int *)(iVar3 + 0x11c) == 0) {
        iVar4 = EthDeleteFilterOpenAdapter(*(int **)(iVar3 + 0xf8),piVar1);
      }
      else if (*(int *)(iVar3 + 0x11c) == 1) {
        iVar4 = FUN_c055b568(*(int **)(iVar3 + 0xfc),piVar1);
      }
      else {
        iVar4 = FUN_c055c078(*(int **)(iVar3 + 0xf8),piVar1);
      }
      for (iVar2 = *(int *)(iVar3 + 0x18); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
      }
      if (((-1 < *(int *)(iVar3 + 0x11c)) && (*(int *)(iVar3 + 0x11c) < 2)) &&
         ((*(uint *)(iVar3 + 0x248) & 0x4010) == 0)) {
        FUN_c055701c(iVar3,param_1,0);
      }
      if (iVar4 == -0x3ffefff2) {
        iVar4 = -1;
      }
      else {
        iVar4 = NdisInterlockedDecrement((LONG *)(param_1 + 0x80));
      }
      uVar5 = 0;
      if (iVar4 == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x4b0));
        *(undefined4 *)(iVar3 + 0x454) = 0;
        *(undefined4 *)(iVar3 + 0x458) = 0;
        FUN_c0559efc(param_1);
      }
      else {
        FUN_c05584e8(iVar3);
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x4b0));
        *(undefined4 *)(iVar3 + 0x454) = 0;
        *(undefined4 *)(iVar3 + 0x458) = 0;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return uVar5;
}



/* c055a168 NdisReadPciSlotInformation */

/* Boundary evidence: original MIPS .pdata c055a168..c055a197. Semantic name remains unreviewed. */

void NdisReadPciSlotInformation
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
                    /* 0x1a168  186  NdisReadPciSlotInformation */
  HalGetBusDataByOffset
            (4,*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x260),param_4,param_3,
             param_5);
  return;
}



/* c055a198 NdisWritePciSlotInformation */

/* Boundary evidence: original MIPS .pdata c055a198..c055a1c7. Semantic name remains unreviewed. */

void NdisWritePciSlotInformation
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
                    /* 0x1a198  223  NdisWritePciSlotInformation */
  HalSetBusDataByOffset
            (4,*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x260),param_4,param_3,
             param_5);
  return;
}



/* c055a1c8 FUN_c055a1c8 */

/* Boundary evidence: original MIPS .pdata c055a1c8..c055a24f. Semantic name remains unreviewed. */

undefined4
FUN_c055a1c8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x1c);
  if (iVar1 != 0) {
    if (param_5 == 0) {
      iVar1 = SetDeviceConfigurationData
                        (iVar1,1,*(undefined4 *)(param_1 + 0x120),0,param_2,param_4,param_3);
    }
    else {
      iVar1 = GetDeviceConfigurationData
                        (iVar1,1,*(undefined4 *)(param_1 + 0x120),0,param_2,param_4,param_3);
    }
    if (iVar1 != 0) {
      return param_4;
    }
  }
  return 0;
}



/* c055a250 NdisReadPcmciaAttributeMemory */

/* Boundary evidence: original MIPS .pdata c055a250..c055a293. Semantic name remains unreviewed. */

void NdisReadPcmciaAttributeMemory(int param_1,int param_2,undefined1 *param_3,uint param_4)

{
                    /* 0x1a250  187  NdisReadPcmciaAttributeMemory */
  if (*(int *)(param_1 + 0x124) == -2) {
    FUN_c055ead0(param_1,param_2,param_3,param_4,1);
  }
  else {
    FUN_c055a1c8(param_1,param_2,param_3,param_4,1);
  }
  return;
}



/* c055a294 NdisWritePcmciaAttributeMemory */

/* Boundary evidence: original MIPS .pdata c055a294..c055a2cf. Semantic name remains unreviewed. */

void NdisWritePcmciaAttributeMemory(int param_1,int param_2,undefined1 *param_3,uint param_4)

{
                    /* 0x1a294  224  NdisWritePcmciaAttributeMemory */
  if (*(int *)(param_1 + 0x124) == -2) {
    FUN_c055ead0(param_1,param_2,param_3,param_4,0);
  }
  else {
    FUN_c055a1c8(param_1,param_2,param_3,param_4,0);
  }
  return;
}



/* c055a2d0 NdisSend */

/* Boundary evidence: original MIPS .pdata c055a2d0..c055a307. Semantic name remains unreviewed. */

void NdisSend(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
                    /* 0x1a2d0  199  NdisSend */
  uVar1 = (**(code **)(param_2 + 0x40))(param_2,param_3);
  *param_1 = uVar1;
  return;
}



/* c055a308 NdisSendPackets */

/* Boundary evidence: original MIPS .pdata c055a308..c055a32f. Semantic name remains unreviewed. */

void NdisSendPackets(int param_1)

{
                    /* 0x1a308  200  NdisSendPackets */
  (**(code **)(param_1 + 100))(param_1);
  return;
}



/* c055a330 NdisTransferData */

/* Boundary evidence: original MIPS .pdata c055a330..c055a387. Semantic name remains unreviewed. */

void NdisTransferData(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
                    /* 0x1a330  212  NdisTransferData */
  uVar1 = (**(code **)(param_2 + 0x44))(param_2,param_3,param_4,param_5,param_6,param_7);
  *param_1 = uVar1;
  return;
}



/* c055a388 NdisReset */

/* Boundary evidence: original MIPS .pdata c055a388..c055a3cb. Semantic name remains unreviewed. */

void NdisReset(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
                    /* 0x1a388  195  NdisReset */
  *param_1 = 0x80010001;
  if (*(code **)(param_2 + 0x68) != (code *)0x0) {
    uVar1 = (**(code **)(param_2 + 0x68))(param_2);
    *param_1 = uVar1;
  }
  return;
}



/* c055a3cc NdisRequest */

/* Boundary evidence: original MIPS .pdata c055a3cc..c055a403. Semantic name remains unreviewed. */

void NdisRequest(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
                    /* 0x1a3cc  194  NdisRequest */
  uVar1 = (**(code **)(param_2 + 0x6c))(param_2,param_3);
  *param_1 = uVar1;
  return;
}



/* c055a404 FUN_c055a404 */

/* Boundary evidence: original MIPS .pdata c055a404..c055a473. Semantic name remains unreviewed. */

bool FUN_c055a404(int param_1)

{
  bool bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  bVar1 = *(char *)(param_1 + 0x16) == '\0';
  if (bVar1) {
    *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return bVar1;
}



/* c055a474 FUN_c055a474 */

/* Boundary evidence: original MIPS .pdata c055a474..c055a4eb. Semantic name remains unreviewed. */

bool FUN_c055a474(int param_1)

{
  short sVar1;
  bool bVar2;
  
  if (param_1 == 0) {
    bVar2 = false;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    sVar1 = *(short *)(param_1 + 0x14) + -1;
    bVar2 = sVar1 == 0;
    *(short *)(param_1 + 0x14) = sVar1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return bVar2;
}



/* c055a4ec FUN_c055a4ec */

/* Boundary evidence: original MIPS .pdata c055a4ec..c055a517. Semantic name remains unreviewed. */

void FUN_c055a4ec(LPCRITICAL_SECTION param_1)

{
  if (param_1 != (LPCRITICAL_SECTION)0x0) {
    *(undefined1 *)((int)&param_1->SpinCount + 2) = 0;
    *(undefined2 *)&param_1->SpinCount = 1;
    InitializeCriticalSection(param_1);
  }
  return;
}



/* c055a518 FUN_c055a518 */

/* Boundary evidence: original MIPS .pdata c055a518..c055a533. Semantic name remains unreviewed. */

void FUN_c055a518(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* c055a534 FUN_c055a534 */

/* Boundary evidence: original MIPS .pdata c055a534..c055a59b. Semantic name remains unreviewed. */

bool FUN_c055a534(int param_1)

{
  bool bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  bVar1 = *(char *)(param_1 + 0x16) == '\0';
  if (bVar1) {
    *(undefined1 *)(param_1 + 0x16) = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return bVar1;
}



/* c055a59c FUN_c055a59c */

/* Boundary evidence: original MIPS .pdata c055a59c..c055a653. Semantic name remains unreviewed. */

bool FUN_c055a59c(undefined4 *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  void *_Dst;
  
  _Dst = FUN_c05427a0(0x68);
  *param_2 = _Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x68);
    *(int *)((int)_Dst + 0x24) = *(int *)((int)_Dst + 0x24) + 1;
    *(undefined4 *)((int)_Dst + 0x30) = *param_1;
    uVar1 = *(undefined1 *)((int)param_1 + 5);
    *(undefined1 *)((int)_Dst + 0x34) = *(undefined1 *)(param_1 + 1);
    *(undefined1 *)((int)_Dst + 0x35) = uVar1;
    InitializeCriticalSection((LPCRITICAL_SECTION)((int)_Dst + 4));
  }
  return _Dst != (void *)0x0;
}



/* c055a654 FUN_c055a654 */

/* Boundary evidence: original MIPS .pdata c055a654..c055a683. Semantic name remains unreviewed. */

void FUN_c055a654(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  CTEFreeMem(param_1);
  return;
}



/* c055a684 FUN_c055a684 */

undefined4 FUN_c055a684(int *param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  int *piVar6;
  
  uVar1 = *param_3;
  uVar2 = param_3[1];
  uVar3 = param_3[2];
  uVar4 = param_3[3];
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_2 + 0x20);
  *(uint *)(param_2 + 0x20) = CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4);
  piVar6 = (int *)*param_1;
  param_1[0x11] = param_1[0xe];
  param_1[0xe] = 0;
  for (; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
    param_1[0xe] = piVar6[8] | param_1[0xe];
  }
  uVar5 = 0x103;
  if (param_1[0x11] == param_1[0xe]) {
    uVar5 = 0;
  }
  return uVar5;
}



/* c055a704 FUN_c055a704 */

void FUN_c055a704(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_2 + 0x24);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x44);
  return;
}



/* c055a718 FUN_c055a718 */

undefined4 FUN_c055a718(int param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  
  uVar1 = *param_3;
  uVar2 = param_3[1];
  uVar3 = param_3[2];
  uVar4 = param_3[3];
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x40);
  cVar5 = *(char *)(param_2 + 0x28);
  iVar6 = CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4);
  *(char *)(param_2 + 0x29) = cVar5;
  if (iVar6 == 0) {
    if (cVar5 == '\0') {
      if (*(int *)(param_1 + 0x40) != 0) {
        return 0xc001001a;
      }
    }
    else {
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -1;
      *(undefined1 *)(param_2 + 0x28) = 0;
      if (*(int *)(param_1 + 0x40) == 0) goto LAB_c055a808;
    }
  }
  else {
    if (iVar6 != *(int *)(param_1 + 0x3c)) {
      if (1 < *(uint *)(param_1 + 0x40)) {
        return 0xc001001a;
      }
      if (*(uint *)(param_1 + 0x40) == 1) {
        if (cVar5 == '\0') {
          return 0xc001001a;
        }
        if (cVar5 != '\0') {
          *(undefined4 *)(param_1 + 0x40) = 0;
          *(undefined1 *)(param_2 + 0x28) = 0;
        }
      }
LAB_c055a808:
      *(int *)(param_1 + 0x3c) = iVar6;
      if (iVar6 == 0) {
        *(undefined1 *)(param_2 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x40) = 0;
      }
      else {
        *(undefined1 *)(param_2 + 0x28) = 1;
        *(undefined4 *)(param_1 + 0x40) = 1;
      }
      return 0x103;
    }
    if (cVar5 == '\0') {
      if (*(int *)(param_1 + 0x40) == 0) goto LAB_c055a808;
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      *(undefined1 *)(param_2 + 0x28) = 1;
    }
  }
  return 0;
}



/* c055a830 FUN_c055a830 */

void FUN_c055a830(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined1 *)(param_2 + 0x28) = *(undefined1 *)(param_2 + 0x29);
  return;
}



/* c055a84c FUN_c055a84c */

/* Boundary evidence: original MIPS .pdata c055a84c..c055a9af. Semantic name remains unreviewed. */

int FUN_c055a84c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x11c) == 1) {
    if (*(uint *)(param_2 + 0x1c) < 4) {
      *(undefined4 *)(param_2 + 0x24) = 4;
      return -0x3ffeffec;
    }
    if (((*(uint *)(*(int *)(param_2 + 4) + 0x7c) & 0x8000) != 0) ||
       (iVar1 = FUN_c055a684(*(int **)(param_1 + 0xfc),*(int *)(*(int *)(param_2 + 4) + 0x98),
                             *(undefined1 **)(param_2 + 0x18)), iVar1 == 0x103)) {
      uVar2 = *(uint *)(*(int *)(param_1 + 0xfc) + 0x38);
      *(uint *)(param_1 + 400) =
           uVar2 >> 8 & 0xff00 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18 | uVar2 >> 0x18;
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
      *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_2 + 0x18);
      *(short *)(param_1 + 0x1dc) = (short)*(undefined4 *)(param_2 + 0x1c);
      *(uint **)(param_2 + 0x18) = (uint *)(param_1 + 400);
      *(undefined4 *)(param_2 + 0x1c) = 4;
      iVar1 = FUN_c05574b4(param_1,param_2,0);
      if (iVar1 == 0x103) {
        return 0x103;
      }
    }
    if ((*(uint *)(param_2 + 0xc) & 8) != 0) {
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xfffffff7;
      *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x1d8);
      *(uint *)(param_2 + 0x1c) = (uint)*(ushort *)(param_1 + 0x1dc);
      *(undefined4 *)(param_1 + 0x1d8) = 0;
      *(undefined2 *)(param_1 + 0x1dc) = 0;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_2 + 0x1c);
      return 0;
    }
  }
  else {
    iVar1 = -0x3fffff45;
  }
  *(undefined4 *)(param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 0x20) = 0;
  return iVar1;
}



/* c055a9b0 FUN_c055a9b0 */

/* Boundary evidence: original MIPS .pdata c055a9b0..c055ab13. Semantic name remains unreviewed. */

int FUN_c055a9b0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x11c) == 1) {
    if (*(uint *)(param_2 + 0x1c) < 4) {
      *(undefined4 *)(param_2 + 0x24) = 4;
      return -0x3ffeffec;
    }
    if (((*(uint *)(*(int *)(param_2 + 4) + 0x7c) & 0x8000) != 0) ||
       (iVar1 = FUN_c055a718(*(int *)(param_1 + 0xfc),*(int *)(*(int *)(param_2 + 4) + 0x98),
                             *(undefined1 **)(param_2 + 0x18)), iVar1 == 0x103)) {
      uVar2 = *(uint *)(*(int *)(param_1 + 0xfc) + 0x3c);
      *(uint *)(param_1 + 400) =
           uVar2 >> 8 & 0xff00 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18 | uVar2 >> 0x18;
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
      *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_2 + 0x18);
      *(short *)(param_1 + 0x1dc) = (short)*(undefined4 *)(param_2 + 0x1c);
      *(uint **)(param_2 + 0x18) = (uint *)(param_1 + 400);
      *(undefined4 *)(param_2 + 0x1c) = 4;
      iVar1 = FUN_c05574b4(param_1,param_2,0);
      if (iVar1 == 0x103) {
        return 0x103;
      }
    }
    if ((*(uint *)(param_2 + 0xc) & 8) != 0) {
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xfffffff7;
      *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x1d8);
      *(uint *)(param_2 + 0x1c) = (uint)*(ushort *)(param_1 + 0x1dc);
      *(undefined4 *)(param_1 + 0x1d8) = 0;
      *(undefined2 *)(param_1 + 0x1dc) = 0;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_2 + 0x1c);
      return 0;
    }
  }
  else {
    iVar1 = -0x3fffff45;
  }
  *(undefined4 *)(param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 0x20) = 0;
  return iVar1;
}



/* c055ab14 TrFilterDprIndicateReceive */

/* Boundary evidence: original MIPS .pdata c055ab14..c055af13. Semantic name remains unreviewed. */

void TrFilterDprIndicateReceive
               (int *param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,
               undefined4 param_6,int param_7)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  byte *pbVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar9;
  
                    /* 0x1ab14  225  TrFilterDprIndicateReceive */
  pbVar5 = (byte *)(param_3 + 2);
  if (param_1 == (int *)0x0) {
    return;
  }
  if ((*(uint *)(param_1[6] + 0x54) & 0x20000000) == 0) {
    return;
  }
  if (*(code **)g_pLogMiniportIndicateReceive_exref != (code *)0x0) {
    (**(code **)g_pLogMiniportIndicateReceive_exref)
              (0,param_2,0,param_3,param_4,param_5,param_6,param_7,1);
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
  EnterCriticalSection(lpCriticalSection);
  uVar8 = param_4;
  if ((param_4 < 0xe) || (param_7 == 0)) {
    uVar7 = 0x20;
    uVar9 = 0;
    bVar1 = false;
  }
  else {
    if (((int)(char)*pbVar5 & 0x80U) == 0) {
      *(int *)(param_1[6] + 0x3a4) = *(int *)(param_1[6] + 0x3a4) + 1;
      bVar1 = false;
      if (((param_1[7] & 0x20a0U) != 0) &&
         ((*(int *)((int)param_1 + 0x32) != *(int *)(param_3 + 4) ||
          (bVar1 = false, (short)param_1[0xc] != *(short *)pbVar5)))) {
        bVar1 = true;
      }
      piVar6 = (int *)*param_1;
      while (piVar3 = piVar6, piVar3 != (int *)0x0) {
        piVar6 = (int *)*piVar3;
        if (((piVar3[3] & 0x20U) != 0) || ((!bVar1 && ((piVar3[3] & 1U) != 0)))) {
          LeaveCriticalSection(lpCriticalSection);
          (**(code **)(piVar3[1] + 0x50))
                    (*(undefined4 *)(piVar3[1] + 0x10),param_2,param_3,param_4,param_5,param_6,
                     param_7);
          EnterCriticalSection(lpCriticalSection);
          *(undefined1 *)(piVar3 + 7) = 1;
        }
      }
      goto LAB_c055aedc;
    }
    uVar9 = (int)*(char *)(param_3 + 8) & 0x80;
    bVar1 = (*(byte *)(param_3 + 1) & 0xfc) == 0;
    if (((*(short *)pbVar5 == -1) || (*(short *)pbVar5 == 0xc0)) && (*(int *)(param_3 + 4) == -1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      uVar7 = 8;
    }
    else {
      uVar7 = 0x1000;
      if (((int)(char)(*(byte *)(param_3 + 4) & *pbVar5) & 0x80U) == 0) {
        uVar7 = 0x4000;
      }
      uVar8 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_3 + 4),*(undefined1 *)(param_3 + 5)),
                                *(undefined1 *)(param_3 + 6)),*(undefined1 *)(param_3 + 7));
    }
  }
  piVar6 = (int *)*param_1;
  while (piVar3 = piVar6, piVar3 != (int *)0x0) {
    uVar4 = piVar3[3];
    piVar6 = (int *)*piVar3;
    if ((((((uVar4 & 0xa0) != 0) || ((uVar7 == 8 && ((uVar4 & 8) != 0)))) ||
         ((uVar7 == 0x4000 &&
          (((uVar4 & 0x2000) != 0 || (((uVar4 & 0x4000) != 0 && ((piVar3[8] & uVar8) != 0)))))))) ||
        (((uVar4 & uVar7 & 0x1000) != 0 &&
         ((*(char *)(piVar3 + 10) != '\0' && (uVar8 == param_1[0xf])))))) ||
       ((((uVar4 & 0x10) != 0 && (uVar9 != 0)) || (((uVar4 & 0x8000) != 0 && (bVar1)))))) {
      LeaveCriticalSection(lpCriticalSection);
      (**(code **)(piVar3[1] + 0x50))
                (*(undefined4 *)(piVar3[1] + 0x10),param_2,param_3,param_4,param_5,param_6,param_7);
      EnterCriticalSection(lpCriticalSection);
      *(undefined1 *)(piVar3 + 7) = 1;
    }
  }
LAB_c055aedc:
  LeaveCriticalSection(lpCriticalSection);
  return;
}



/* c055af14 FUN_c055af14 */

/* Boundary evidence: original MIPS .pdata c055af14..c055b4f3. Semantic name remains unreviewed. */

void FUN_c055af14(int param_1,int *param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  byte *pbVar14;
  int *piVar15;
  char local_58 [4];
  char *local_54;
  int local_50;
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  int *local_3c;
  char *local_38;
  char *local_34;
  int iStack_30;
  int iStack_2c;
  
  piVar11 = *(int **)(param_1 + 0xfc);
  iVar12 = 0;
  local_50 = 0;
  local_40 = param_3;
  local_3c = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)(piVar11 + 1));
  if (*(code **)g_pLogMiniportIndicateReceivePackets_exref != (code *)0x0) {
    param_4 = 1;
    (**(code **)g_pLogMiniportIndicateReceivePackets_exref)(param_1,param_2,param_3);
  }
  if (param_3 != 0) {
    local_34 = "Indicating packet not owned by it";
    local_38 = " ***NDIS*** : Miniport %Z - %s\n";
    local_54 = "Indicating packet not owned by it";
    do {
      iVar10 = *param_2;
      uVar5 = *(int *)(iVar10 + -4) + 1;
      *(uint *)(iVar10 + -4) = uVar5;
      if (uVar5 < DAT_c05653bc) {
        iVar6 = (uVar5 - DAT_c05653bc) * 0x28 + iVar10 + -8;
      }
      else {
        iVar6 = 0;
      }
      piVar15 = (int *)(iVar6 + 8);
      if (*(int *)(iVar6 + 0xc) != 0) {
        DbgPrint(local_38,*(undefined4 *)(param_1 + 0x1e8),local_34,param_4);
        trap(0x400);
      }
      iVar8 = (uint)*(ushort *)(iVar10 + 0x1e) + iVar10;
      local_44 = iVar8;
      NdisGetFirstBufferFromPacket(iVar10,&iStack_2c,&local_48,&iStack_30,(int *)&local_4c);
      iVar4 = local_44;
      *(undefined4 *)(iVar6 + 0xc) = 0xffffffff;
      *(undefined4 *)(iVar6 + 0x10) = 0;
      *piVar15 = param_1;
      *(undefined1 *)(iVar10 + 0x1c) = 0;
      local_58[0] = *(int *)(iVar8 + 0x1c) == -0x3fffff66;
      if (!(bool)local_58[0]) {
        *(undefined4 *)(iVar8 + 0x1c) = 0;
      }
      pbVar14 = (byte *)(local_48 + 2);
      if (local_4c < *(uint *)(iVar8 + 0x10)) {
        uVar5 = 0x20;
        uVar13 = 0;
        bVar1 = false;
LAB_c055b2e4:
        piVar9 = (int *)*piVar11;
        iVar12 = local_50;
        while (piVar3 = piVar9, iVar6 = iVar12, piVar3 != (int *)0x0) {
          uVar7 = piVar3[3];
          piVar9 = (int *)*piVar3;
          param_3 = local_40;
          if ((((*(uint *)(iVar10 + 0x18) & 0x80) == 0) || (*(int *)(iVar10 + 0x20) != piVar3[1]))
             && ((((((uVar7 & 0xa0) != 0 || ((uVar5 == 8 && ((uVar7 & 8) != 0)))) ||
                   ((uVar5 == 0x4000 &&
                    (((uVar7 & 0x2000) != 0 ||
                     (((uVar7 & 0x4000) != 0 && ((piVar3[8] & (uint)local_54) != 0)))))))) ||
                  (((uVar7 & uVar5 & 0x1000) != 0 &&
                   ((*(char *)(piVar3 + 10) != '\0' && (local_54 == (char *)piVar11[0xf])))))) ||
                 ((((uVar7 & 0x10) != 0 && (uVar13 != 0)) || (((uVar7 & 0x8000) != 0 && (bVar1))))))
                )) {
            local_50 = iVar12 + 1;
            *(undefined1 *)(piVar3 + 7) = 1;
            FUN_c055bbe8(param_1,(int)piVar11,piVar3[1],iVar10,(int)piVar15,local_48,local_4c,
                         *(int *)(iVar4 + 0x10),local_58,(uVar7 & 0xa0) != 0);
            param_3 = local_40;
            iVar12 = local_50;
          }
        }
      }
      else {
        if (((int)(char)*pbVar14 & 0x80U) != 0) {
          uVar13 = (int)*(char *)(local_48 + 8) & 0x80;
          bVar1 = (*(byte *)(local_48 + 1) & 0xfc) == 0;
          if (((*(short *)pbVar14 == -1) || (*(short *)pbVar14 == 0xc0)) &&
             (*(int *)(local_48 + 4) == -1)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (bVar2) {
            uVar5 = 8;
          }
          else {
            if (((int)(char)(*(byte *)(local_48 + 4) & *pbVar14) & 0x80U) == 0) {
              uVar5 = 0x4000;
            }
            else {
              uVar5 = 0x1000;
            }
            local_54 = (char *)CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(local_48 + 4),
                                                          *(undefined1 *)(local_48 + 5)),
                                                 *(undefined1 *)(local_48 + 6)),
                                        *(undefined1 *)(local_48 + 7));
          }
          goto LAB_c055b2e4;
        }
        if ((*(byte *)(iVar10 + 0x1d) & 2) == 0) {
          *(int *)(param_1 + 0x3a4) = *(int *)(param_1 + 0x3a4) + 1;
        }
        bVar1 = false;
        if (((piVar11[7] & 0x20a0U) != 0) &&
           ((*(int *)((int)piVar11 + 0x32) != *(int *)(local_48 + 4) ||
            (bVar1 = false, (short)piVar11[0xc] != *(short *)pbVar14)))) {
          bVar1 = true;
        }
        piVar9 = (int *)*piVar11;
        iVar6 = local_50;
        while (piVar3 = piVar9, piVar3 != (int *)0x0) {
          piVar9 = (int *)*piVar3;
          bVar2 = (piVar3[3] & 0xa0U) != 0;
          iVar6 = iVar12;
          param_3 = local_40;
          if (((bVar2) || ((!bVar1 && ((piVar3[3] & 1U) != 0)))) &&
             (((*(uint *)(iVar10 + 0x18) & 0x80) == 0 || (*(int *)(iVar10 + 0x20) != piVar3[1])))) {
            *(undefined1 *)(piVar3 + 7) = 1;
            iVar12 = iVar12 + 1;
            FUN_c055bbe8(param_1,(int)piVar11,piVar3[1],iVar10,(int)piVar15,local_48,local_4c,
                         *(int *)(iVar4 + 0x10),local_58,bVar2);
            param_3 = local_40;
            iVar6 = iVar12;
          }
        }
      }
      local_50 = iVar6;
      param_4 = local_44;
      FUN_c055bad8(param_1,iVar10,piVar15,local_44);
      param_3 = param_3 + -1;
      param_2 = local_3c + 1;
      local_40 = param_3;
      local_3c = param_2;
    } while (param_3 != 0);
    local_40 = 0;
    if (iVar12 != 0) {
      piVar15 = (int *)*piVar11;
      while (piVar9 = piVar15, piVar9 != (int *)0x0) {
        piVar15 = (int *)*piVar9;
        if (*(char *)(piVar9 + 7) != '\0') {
          *(undefined1 *)(piVar9 + 7) = 0;
          (**(code **)(piVar9[1] + 0x54))(*(undefined4 *)(piVar9[1] + 0x10));
        }
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(piVar11 + 1));
  return;
}



/* c055b4f4 TrFilterDprIndicateReceiveComplete */

/* Boundary evidence: original MIPS .pdata c055b4f4..c055b567. Semantic name remains unreviewed. */

void TrFilterDprIndicateReceiveComplete(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
                    /* 0x1b4f4  226  TrFilterDprIndicateReceiveComplete */
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  piVar2 = (int *)*param_1;
  while (piVar1 = piVar2, piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    if (*(char *)(piVar1 + 7) != '\0') {
      *(undefined1 *)(piVar1 + 7) = 0;
      (**(code **)(piVar1[1] + 0x54))(*(undefined4 *)(piVar1[1] + 0x10));
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return;
}



/* c055b568 FUN_c055b568 */

/* Boundary evidence: original MIPS .pdata c055b568..c055b6a3. Semantic name remains unreviewed. */

int FUN_c055b568(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_c055b990(param_1,(int)param_2,0);
  if (((iVar1 == 0) || (iVar1 == 0x103)) &&
     (iVar2 = FUN_c055a684(param_1,(int)param_2,&DAT_c05653e4), iVar2 != 0)) {
    iVar1 = iVar2;
  }
  if (((iVar1 == 0) || (iVar1 == 0x103)) && ((char)param_2[10] != '\0')) {
    param_1[0x10] = param_1[0x10] + -1;
    *(undefined1 *)(param_2 + 10) = 0;
    if ((param_1[0x10] == 0) &&
       (iVar2 = FUN_c055a718((int)param_1,(int)param_2,&DAT_c05653e4), iVar2 != 0)) {
      iVar1 = iVar2;
    }
  }
  if (((iVar1 == 0) || (iVar1 == 0x103)) || (iVar1 == -0x3fffff66)) {
    iVar2 = param_2[5];
    param_2[5] = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_c055bfdc(param_1,param_2);
    }
    else {
      iVar1 = -0x3ffefff2;
    }
  }
  return iVar1;
}



/* c055b6a4 FUN_c055b6a4 */

/* Boundary evidence: original MIPS .pdata c055b6a4..c055b713. Semantic name remains unreviewed. */

bool FUN_c055b6a4(undefined4 *param_1)

{
  void *_Dst;
  
  _Dst = FUN_c05427a0(0x68);
  *param_1 = _Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x68);
    InitializeCriticalSection((LPCRITICAL_SECTION)((int)_Dst + 4));
  }
  return _Dst != (void *)0x0;
}



/* c055b714 FUN_c055b714 */

/* Boundary evidence: original MIPS .pdata c055b714..c055b83b. Semantic name remains unreviewed. */

void FUN_c055b714(int param_1,int *param_2,int param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    iVar3 = *param_2;
    uVar1 = *(int *)(iVar3 + -4) + 1;
    *(uint *)(iVar3 + -4) = uVar1;
    iVar4 = (uint)*(ushort *)(iVar3 + 0x1e) + iVar3;
    if (uVar1 < DAT_c05653bc) {
      iVar5 = (uVar1 - DAT_c05653bc) * 0x28 + iVar3 + -8;
    }
    else {
      iVar5 = 0;
    }
    *(int *)(param_1 + 0x3a4) = *(int *)(param_1 + 0x3a4) + 1;
    if (*(int *)(iVar4 + 0x1c) == -0x3fffff66) {
      *(int *)(iVar3 + -4) = *(int *)(iVar3 + -4) + -1;
    }
    else if ((*(uint *)(param_1 + 0x54) & 0x40000) == 0) {
      *(int *)(iVar3 + -4) = *(int *)(iVar3 + -4) + -1;
      *(undefined4 *)(iVar4 + 0x1c) = 0;
    }
    else {
      pcVar2 = *(code **)(*(int *)(param_1 + 8) + 0x5c);
      *(undefined4 *)(iVar4 + 0x1c) = 0x103;
      *(undefined4 *)(iVar5 + 8) = 0;
      *(int *)(iVar3 + -4) = *(int *)(iVar3 + -4) + -1;
      (*pcVar2)(*(undefined4 *)(param_1 + 0xc),iVar3);
    }
    param_2 = param_2 + 1;
  }
  return;
}



/* c055b83c FUN_c055b83c */

/* Boundary evidence: original MIPS .pdata c055b83c..c055b8d3. Semantic name remains unreviewed. */

void FUN_c055b83c(int param_1,short *param_2)

{
  short sVar1;
  
  sVar1 = *param_2;
  if (sVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    sVar1 = 3;
  }
  else {
    if (sVar1 != 1) {
      if (sVar1 == 3) {
        *param_2 = -1;
      }
      else {
        if (sVar1 != 4) {
          return;
        }
        *param_2 = -1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    sVar1 = 4;
  }
  *param_2 = sVar1;
  return;
}



/* c055b8d4 FUN_c055b8d4 */

/* Boundary evidence: original MIPS .pdata c055b8d4..c055b98f. Semantic name remains unreviewed. */

void FUN_c055b8d4(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined2 local_18 [4];
  
  local_18[0] = 1;
  (**(code **)(param_1[6] + 0x1e4))(param_1,local_18);
  if ((int *)param_1[0xb] == param_2) {
    param_1[0xb] = 0;
    FUN_c055691c(param_1[6]);
  }
  iVar2 = *param_1;
  piVar1 = param_1;
  do {
    if (iVar2 == 0) {
LAB_c055b958:
      *param_2 = 0;
      param_1[9] = param_1[9] + -1;
      (**(code **)(param_1[6] + 0x1e4))(param_1,local_18);
      return;
    }
    piVar3 = (int *)*piVar1;
    if (piVar3 == param_2) {
      *piVar1 = *param_2;
      goto LAB_c055b958;
    }
    iVar2 = *piVar3;
    piVar1 = piVar3;
  } while( true );
}



/* c055b990 FUN_c055b990 */

undefined4 FUN_c055b990(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_2 + 0xc) = param_3;
  piVar2 = (int *)*param_1;
  param_1[8] = param_1[7];
  param_1[7] = 0;
  for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    param_1[7] = piVar2[3] | param_1[7];
  }
  uVar1 = 0x103;
  if (((param_1[8] ^ param_1[7]) & 0xffffff7fU) == 0) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c055b9f8 FUN_c055b9f8 */

void FUN_c055b9f8(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x20);
  return;
}



/* c055ba0c FUN_c055ba0c */

/* Boundary evidence: original MIPS .pdata c055ba0c..c055bad7. Semantic name remains unreviewed. */

bool FUN_c055ba0c(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *_Dst;
  undefined2 local_20 [4];
  
  _Dst = FUN_c05427a0(0x40);
  *param_3 = _Dst;
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x40);
    _Dst[1] = param_2;
    _Dst[5] = 1;
    local_20[0] = 1;
    (**(code **)(param_1[6] + 0x1e4))(param_1,local_20);
    *_Dst = *param_1;
    *param_1 = _Dst;
    param_1[9] = param_1[9] + 1;
    (**(code **)(param_1[6] + 0x1e4))(param_1,local_20);
  }
  return _Dst != (undefined4 *)0x0;
}



/* c055bad8 FUN_c055bad8 */

/* Boundary evidence: original MIPS .pdata c055bad8..c055bbe7. Semantic name remains unreviewed. */

void FUN_c055bad8(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  LONG LVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = param_3[2];
  if (iVar3 == 0) {
    iVar3 = 0;
    param_3[1] = 0;
  }
  else {
    LVar1 = InterlockedExchangeAdd(param_3 + 1,iVar3 + 1);
    iVar3 = LVar1 + iVar3 + 1;
    if ((0 < iVar3) && ((*(uint *)(param_1 + 0x54) & 0x40000) == 0)) {
      *(undefined4 *)((uint)*(ushort *)(param_2 + 0x1e) + param_2 + 0x1c) = 0x103;
    }
  }
  if ((iVar3 == 0) &&
     (*(int *)(param_2 + -4) = *(int *)(param_2 + -4) + -1, *(int *)(param_4 + 0x1c) != -0x3fffff66)
     ) {
    if ((*(uint *)(param_1 + 0x54) & 0x40000) == 0) {
      *(undefined4 *)(param_4 + 0x1c) = 0;
    }
    else {
      pcVar2 = *(code **)(*(int *)(param_1 + 8) + 0x5c);
      *param_3 = 0;
      *(undefined4 *)(param_4 + 0x1c) = 0x103;
      (*pcVar2)(*(undefined4 *)(param_1 + 0xc),param_2);
    }
  }
  return;
}



/* c055bbe8 FUN_c055bbe8 */

/* Boundary evidence: original MIPS .pdata c055bbe8..c055bd6f. Semantic name remains unreviewed. */

void FUN_c055bbe8(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,char *param_9,char param_10)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = *(undefined4 *)(param_1 + 0x3a8);
  *(int *)(param_1 + 0x3a8) = param_4;
  if (((*param_9 == '\0') && (*(int *)(param_3 + 0x60) != 0)) &&
     ((param_10 == '\0' || (*(int *)(param_2 + 0x2c) != 0)))) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
    sVar1 = (**(code **)(param_3 + 0x60))(*(undefined4 *)(param_3 + 0x10),param_4);
    *(int *)(param_5 + 8) = (int)sVar1 + *(int *)(param_5 + 8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
  }
  else {
    iVar2 = (uint)*(ushort *)(param_4 + 0x1e) + param_4;
    uVar4 = *(undefined4 *)(iVar2 + 0x1c);
    *(undefined4 *)(iVar2 + 0x1c) = 0xc000009a;
    iVar2 = 0;
    if (*(int *)(param_4 + 8) != 0) {
      iVar2 = *(int *)(*(int *)(param_4 + 8) + 8);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
    (**(code **)(param_3 + 0x50))
              (*(undefined4 *)(param_3 + 0x10),param_4,param_6,param_8,param_6 + param_8,
               iVar2 - param_8,param_7 - param_8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
    *(undefined4 *)((uint)*(ushort *)(param_4 + 0x1e) + param_4 + 0x1c) = uVar4;
  }
  if ((0 < *(int *)(param_5 + 8)) && ((*(uint *)(param_3 + 0x7c) & 8) == 0)) {
    *param_9 = '\x01';
  }
  *(undefined4 *)(param_1 + 0x3a8) = uVar3;
  return;
}



/* c055bd70 FUN_c055bd70 */

/* Boundary evidence: original MIPS .pdata c055bd70..c055bfdb. Semantic name remains unreviewed. */

void FUN_c055bd70(int param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  char local_50 [4];
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  char *local_3c;
  char *local_38;
  int iStack_34;
  int aiStack_30 [2];
  
  piVar5 = *(int **)(param_1 + 0xf8);
  local_48 = 0;
  local_4c = param_3;
  EnterCriticalSection((LPCRITICAL_SECTION)(piVar5 + 1));
  if (param_3 != 0) {
    local_3c = " ***NDIS*** : Miniport %Z - %s\n";
    local_38 = "Indicating packet not owned by it";
    iVar8 = local_48;
    do {
      iVar6 = *param_2;
      uVar2 = *(int *)(iVar6 + -4) + 1;
      *(uint *)(iVar6 + -4) = uVar2;
      if (uVar2 < DAT_c05653bc) {
        iVar3 = (uVar2 - DAT_c05653bc) * 0x28 + iVar6 + -8;
      }
      else {
        iVar3 = 0;
      }
      piVar7 = (int *)(iVar3 + 8);
      if (*(int *)(iVar3 + 0xc) != 0) {
        DbgPrint(local_3c,*(undefined4 *)(param_1 + 0x1e8),local_38,param_4);
        trap(0x400);
      }
      param_4 = (uint)*(ushort *)(iVar6 + 0x1e) + iVar6;
      NdisGetFirstBufferFromPacket(iVar6,aiStack_30,&local_40,&iStack_34,&local_44);
      *(int *)(param_1 + 0x3a4) = *(int *)(param_1 + 0x3a4) + 1;
      *(undefined4 *)(iVar3 + 0xc) = 0xffffffff;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      *piVar7 = param_1;
      *(undefined1 *)(iVar6 + 0x1c) = 0;
      local_50[0] = *(int *)(param_4 + 0x1c) == -0x3fffff66;
      if (!(bool)local_50[0]) {
        *(undefined4 *)(param_4 + 0x1c) = 0;
      }
      piVar4 = (int *)*piVar5;
      while (piVar4 != (int *)0x0) {
        *(undefined1 *)(piVar4 + 7) = 1;
        piVar1 = piVar4 + 1;
        piVar4 = (int *)*piVar4;
        iVar8 = iVar8 + 1;
        FUN_c055bbe8(param_1,(int)piVar5,*piVar1,iVar6,(int)piVar7,local_40,local_44,
                     *(int *)(param_4 + 0x10),local_50,'\0');
        param_3 = local_4c;
      }
      FUN_c055bad8(param_1,iVar6,piVar7,param_4);
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
      local_4c = param_3;
    } while (param_3 != 0);
    local_4c = 0;
    if (iVar8 != 0) {
      piVar7 = (int *)*piVar5;
      while (piVar4 = piVar7, piVar4 != (int *)0x0) {
        piVar7 = (int *)*piVar4;
        if (*(char *)(piVar4 + 7) != '\0') {
          *(undefined1 *)(piVar4 + 7) = 0;
          (**(code **)(piVar4[1] + 0x54))(*(undefined4 *)(piVar4[1] + 0x10));
        }
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(piVar5 + 1));
  return;
}



/* c055bfdc FUN_c055bfdc */

/* Boundary evidence: original MIPS .pdata c055bfdc..c055c077. Semantic name remains unreviewed. */

void FUN_c055bfdc(int *param_1,int *param_2)

{
  int iVar1;
  
  FUN_c055b8d4(param_1,param_2);
  if (*(int *)(param_1[6] + 0x11c) == 0) {
    iVar1 = param_2[10];
  }
  else {
    if (*(int *)(param_1[6] + 0x11c) != 2) goto LAB_c055c04c;
    if (param_2[0xc] != 0) {
      CTEFreeMem();
    }
    iVar1 = param_2[0xe];
  }
  if (iVar1 != 0) {
    CTEFreeMem();
  }
LAB_c055c04c:
  if ((int *)param_1[10] == param_2) {
    param_1[10] = 0;
  }
  CTEFreeMem(param_2);
  return;
}



/* c055c078 FUN_c055c078 */

/* Boundary evidence: original MIPS .pdata c055c078..c055c0c3. Semantic name remains unreviewed. */

undefined4 FUN_c055c078(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_2[5];
  uVar2 = 0;
  param_2[5] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    FUN_c055bfdc(param_1,param_2);
  }
  else {
    uVar2 = 0xc001000e;
  }
  return uVar2;
}



/* c055c0c4 FUN_c055c0c4 */

/* Boundary evidence: original MIPS .pdata c055c0c4..c055c143. Semantic name remains unreviewed. */

undefined4 FUN_c055c0c4(int param_1)

{
  memset((void *)(param_1 + 0x280),0,0x40);
  *(uint *)(param_1 + 0x284) = *(uint *)(param_1 + 0x284) | 0x3c03;
  *(undefined4 *)(param_1 + 0x2ac) = 6;
  *(undefined4 *)(param_1 + 0x2b0) = 4;
  *(undefined4 *)(param_1 + 0x294) = 0;
  *(undefined4 *)(param_1 + 0x298) = 0;
  *(undefined4 *)(param_1 + 0x29c) = 0;
  *(undefined4 *)(param_1 + 0x2a0) = 0;
  *(undefined4 *)(param_1 + 0x2a4) = 0;
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 1;
  return 0;
}



/* c055c144 FUN_c055c144 */

/* Boundary evidence: original MIPS .pdata c055c144..c055c1df. Semantic name remains unreviewed. */

void FUN_c055c144(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  NdisResetEvent((undefined4 *)(param_1 + 0x350));
  if ((*(uint *)(param_1 + 0x248) & 0x4000) == 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffffe | 0x80000000;
    *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0x4004;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    FUN_c0559910(param_1,param_2,param_3,param_4);
    NdisMDeregisterAdapterShutdownHandler(param_1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  return;
}



/* c055c1e0 FUN_c055c1e0 */

/* Boundary evidence: original MIPS .pdata c055c1e0..c055c52b. Semantic name remains unreviewed. */

int FUN_c055c1e0(int param_1)

{
  undefined1 uVar1;
  DWORD DVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  uVar6 = *(uint *)(param_1 + 0x54);
  iVar7 = *(int *)(param_1 + 8);
  uVar1 = *(undefined1 *)(param_1 + 0x254);
  *(uint *)(param_1 + 0x54) = uVar6 & 0x7fcfffdf;
  *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) & 0xffffffef;
  FUN_c054cb5c(param_1,6,(undefined4 *)0x0,(undefined4 *)0x0);
  FUN_c054cb5c(param_1,0,(undefined4 *)0x0,(undefined4 *)0x0);
  FUN_c054cb5c(param_1,1,(undefined4 *)0x0,(undefined4 *)0x0);
  FUN_c054cb5c(param_1,3,(undefined4 *)0x0,(undefined4 *)0x0);
  uVar5 = 0;
  FUN_c054cb5c(param_1,4,(undefined4 *)0x0,(undefined4 *)0x0);
  iVar3 = param_1 + 0x180;
  *(int *)(param_1 + 0x184) = iVar3;
  *(int *)iVar3 = iVar3;
  local_24 = param_1 + 0x1a4;
  local_2c = **(undefined4 **)(*(int *)(param_1 + 8) + 8);
  local_28 = *(undefined4 *)(param_1 + 0x1c4);
  local_30 = param_1;
  iVar3 = FUN_c05519a0(&local_30,param_1,(undefined2 *)0x0);
  if (iVar3 == 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffffe | 2;
    *(undefined4 *)(param_1 + 0x2c4) = 1;
    uVar5 = DAT_c05653b4 >> 2;
    iVar3 = (**(code **)(iVar7 + 0x3c))
                      (auStack_34,auStack_38,PTR_DAT_c05653b0,uVar5,param_1,&local_30);
    if (iVar3 == 0) {
      uVar5 = *(uint *)(param_1 + 0x248);
      iVar3 = *(int *)(param_1 + 0x50);
      *(undefined1 *)(param_1 + 0x254) = uVar1;
      *(uint *)(param_1 + 0x248) = uVar5 & 0xfffdbfff;
      *(uint *)(param_1 + 0x54) = uVar6 & 0x7fcfffdd;
      if (((iVar3 == 0) || (*(char *)(iVar3 + 0x4a) != '\0')) || (*(char *)(iVar3 + 0x49) != '\0'))
      {
        *(uint *)(param_1 + 0x54) = uVar6 & 0x7fcfffdc;
      }
      else {
        *(uint *)(param_1 + 0x54) = uVar6 & 0x7fcfffdd | 1;
      }
      *(uint *)(param_1 + 0x248) = uVar5 & 0xfffdbffb;
      if ((*(uint *)(param_1 + 0x54) & 0x2000000) == 0) {
        *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x20000000;
      }
      if ((*(uint *)(param_1 + 0x54) & 0x20000000) != 0) {
        FUN_c054dde0(param_1);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      FUN_c054b758(param_1);
      FUN_c055701c(param_1,0,0);
      if ((*(uint *)(param_1 + 0x54) & 0x40000) == 0) {
        FUN_c054eae0(param_1);
      }
      else {
        FUN_c05584e8(param_1);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
      *(undefined4 *)(param_1 + 0x454) = 0;
      *(undefined4 *)(param_1 + 0x458) = 0;
      NdisMSetPeriodicTimer((int *)(param_1 + 0xb8),*(int *)(param_1 + 0x1b4) * 1000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      DVar2 = GetTickCount();
      *(DWORD *)(param_1 + 0x398) = DVar2;
      *(undefined4 *)(param_1 + 0x39c) = 0;
      return 0;
    }
  }
  NdisMDeregisterAdapterShutdownHandler(param_1);
  DAT_c0565444 = iVar3;
  if ((*(int *)(param_1 + 0x1ec) != 0) || (*(int *)(param_1 + 0x50) != 0)) {
    if (*(int *)(param_1 + 0x50) == 0) {
      pcVar4 = "Unloading without deregistering timer";
    }
    else {
      pcVar4 = "Unloading without deregistering interrupt";
    }
    DbgPrint(" ***NDIS*** : Miniport %Z - %s\n",*(undefined4 *)(param_1 + 0x1e8),pcVar4,uVar5);
    trap(0x400);
  }
  *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0x4000;
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffffe | 0x80000000;
  return iVar3;
}



/* c055c52c FUN_c055c52c */

/* Boundary evidence: original MIPS .pdata c055c52c..c055c5ab. Semantic name remains unreviewed. */

uint FUN_c055c52c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 local_res4 [3];
  int aiStack_68 [4];
  uint local_58;
  undefined4 local_54;
  undefined4 *local_50;
  undefined4 local_4c;
  uint local_c;
  
  local_c = DAT_c05653c8;
  local_58 = (uint)(param_4 != 0);
  local_50 = local_res4;
  local_4c = 4;
  local_res4[0] = param_2;
  local_54 = param_3;
  uVar1 = FUN_c055edd4(param_1,0,param_4,aiStack_68);
  FUN_c05625b0(local_c);
  return uVar1;
}



/* c055c5ac FUN_c055c5ac */

/* Boundary evidence: original MIPS .pdata c055c5ac..c055c8a3. Semantic name remains unreviewed. */

uint FUN_c055c5ac(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar4;
  uint uVar5;
  int local_28;
  uint local_24;
  
  uVar5 = 0;
  bVar2 = false;
  bVar1 = false;
  local_28 = param_1;
  if (*(int *)(param_2 + 0x2c4) == 1) {
    bVar3 = FUN_c054dce8(param_2);
    if ((CONCAT31(extraout_var_00,bVar3) != 0) && (*(int *)(param_2 + 0x354) == 1)) {
      NdisSetEvent((undefined4 *)(param_2 + 0x350));
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      FUN_c054e1e4(param_2,4);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      bVar2 = true;
      bVar1 = false;
    }
  }
  else {
    if ((*(uint *)(param_2 + 0x248) & 0x20) == 0) {
      if (((*(ushort *)(*(int *)(param_2 + 8) + 0xb8) & 1) == 0) &&
         ((*(uint *)(param_2 + 0x248) & 0x4000) != 0)) {
        uVar5 = FUN_c055c1e0(param_2);
      }
      else {
        uVar5 = 0;
      }
    }
    else {
      uVar5 = FUN_c055c52c(param_2,param_1,0xfd010101,1);
      if (uVar5 == 0) {
        *(int *)(param_2 + 0x2c4) = local_28;
      }
      NdisMSetPeriodicTimer((int *)(param_2 + 0xb8),*(int *)(param_2 + 0x1b4) * 1000);
    }
    if (uVar5 == 0) {
      bVar2 = FUN_c054dce8(param_2);
      bVar2 = CONCAT31(extraout_var,bVar2) != 0;
      if (bVar2) {
        NdisSetEvent((undefined4 *)(param_2 + 0x350));
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        FUN_c054e1e4(param_2,4);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        local_24 = (uint)((char)DAT_c05653c4 == '\x01');
        FUN_c054bbf8(param_2,5,&local_24,4);
      }
      *(int *)(param_2 + 0x2c4) = local_28;
      bVar1 = bVar2;
    }
  }
  if (bVar2) {
    FUN_c0551fd4(param_2,(int *)0x0,0);
    FUN_c054c29c(param_2,0,&local_28,4);
    if (((*(uint *)(param_2 + 0x248) & 0x10000000) != 0) &&
       ((*(uint *)(param_2 + 0x54) & 0x20000000) != 0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      FUN_c054b758(param_2);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      *(uint *)(param_2 + 0x54) = *(uint *)(param_2 + 0x54) & 0xdfffffff;
      NdisMIndicateStatus(param_2,0x4001000b,(uint *)0xffffffff,-2);
      NdisMIndicateStatusComplete(param_2);
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x4b0));
      *(undefined4 *)(param_2 + 0x454) = 0;
      *(undefined4 *)(param_2 + 0x458) = 0;
    }
    if (((((*(uint *)(param_2 + 0x54) & 0x20000000) == 0) && (bVar1)) &&
        (uVar4 = *(uint *)(param_2 + 0x248), (uVar4 & 0x20) != 0)) &&
       ((((*(uint *)(param_2 + 0x2c0) & 4) != 0 && (*(ushort *)(param_2 + 0x34c) != 0xffff)) &&
        ((uVar4 & 8) == 0)))) {
      *(uint *)(param_2 + 0x248) = uVar4 & 0xfffffdff | 8;
      NdisSetTimer((int *)(param_2 + 0x30c),(uint)*(ushort *)(param_2 + 0x34c) * 1000);
    }
  }
  FUN_c0559738(param_2);
  return uVar5;
}



/* c055c8a4 FUN_c055c8a4 */

/* Boundary evidence: original MIPS .pdata c055c8a4..c055c8fb. Semantic name remains unreviewed. */

uint FUN_c055c8a4(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_3 + 0x354) == 1) {
    FUN_c055a404(param_3 + 0x20);
    uVar1 = FUN_c055c5ac(param_2,param_3);
  }
  else {
    *(int *)(param_3 + 0x2c4) = param_2;
  }
  return uVar1;
}



/* c055c8fc FUN_c055c8fc */

/* Boundary evidence: original MIPS .pdata c055c8fc..c055c94f. Semantic name remains unreviewed. */

undefined4 FUN_c055c8fc(int param_1,int param_2)

{
  if ((*(int *)(param_2 + 0x124) == -2) && (param_1 == 4)) {
    FUN_c055ed0c(param_2);
  }
  *(int *)(param_2 + 0x2c4) = param_1;
  return 0;
}



/* c055c950 FUN_c055c950 */

/* Boundary evidence: original MIPS .pdata c055c950..c055c9b3. Semantic name remains unreviewed. */

void FUN_c055c950(undefined4 param_1,int param_2,int param_3)

{
  undefined1 auStack_18 [8];
  
  if ((*(uint *)(param_3 + 0x248) & 8) != 0) {
    *(uint *)(param_3 + 0x248) = *(uint *)(param_3 + 0x248) & 0xfffffff7 | 0x200;
    NdisCancelTimer((int *)(param_3 + 0x30c),auStack_18);
  }
  FUN_c055c8fc(param_2,param_3);
  return;
}



/* c055c9b4 FUN_c055c9b4 */

/* Boundary evidence: original MIPS .pdata c055c9b4..c055cb53. Semantic name remains unreviewed. */

uint FUN_c055c9b4(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char local_18 [4];
  int local_14;
  
  local_14 = param_1;
  if (param_1 == 1) {
    if (*(int *)(param_2 + 0x124) == -2) {
      FUN_c055ec50(param_2);
    }
    uVar5 = FUN_c055c8a4(*(undefined4 *)(param_2 + 0x1cc),local_14,param_2);
  }
  else if ((param_1 < 2) || (4 < param_1)) {
    uVar5 = 0xc0000001;
  }
  else {
    bVar1 = FUN_c054dce8(param_2);
    if ((CONCAT31(extraout_var,bVar1) != 0) && (*(int *)(param_2 + 0x354) == 1)) {
      NdisResetEvent((undefined4 *)(param_2 + 0x350));
      uVar4 = 4;
      FUN_c054c29c(param_2,0,&local_14,4);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      uVar3 = 4;
      uVar2 = 0xc0010011;
      FUN_c054e23c(param_2,0xc0010011,4);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      uVar5 = *(uint *)(param_2 + 0x248);
      if ((uVar5 & 0x20) == 0) {
        if (((*(ushort *)(*(int *)(param_2 + 8) + 0xb8) & 1) == 0) && ((uVar5 & 0x100) == 0)) {
          FUN_c055c144(param_2,uVar2,uVar3,uVar4);
        }
      }
      else {
        if ((uVar5 & 0x400) != 0) {
          *(uint *)(param_2 + 0x248) = uVar5 & 0xfffffbff;
        }
        uVar5 = FUN_c055c52c(param_2,local_14,0xfd010101,1);
        if (uVar5 != 0) {
          return uVar5;
        }
        NdisCancelTimer((int *)(param_2 + 0xb8),local_18);
        if (local_18[0] == '\0') {
          NdisStallExecution();
        }
      }
    }
    uVar5 = FUN_c055c950(*(undefined4 *)(param_2 + 0x1cc),local_14,param_2);
  }
  return uVar5;
}



/* c055cb54 FUN_c055cb54 */

/* Boundary evidence: original MIPS .pdata c055cb54..c055cccf. Semantic name remains unreviewed. */

undefined4 FUN_c055cb54(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if ((((*(uint *)(param_1 + 0x248) & 0x20) == 0) ||
      (bVar1 = FUN_c054dce8(param_1), CONCAT31(extraout_var,bVar1) == 0)) ||
     (*(int *)(param_1 + 0x354) != 1)) {
    *param_2 = 4;
  }
  else {
    iVar6 = 4;
    if ((*(uint *)(param_1 + 0x248) & 0x40) != 0) {
      uVar4 = *(uint *)(param_1 + 0x2c0);
      iVar5 = 0;
      if (((uVar4 & 1) == 1) && (*(int *)(param_1 + 0x274) != 0)) {
        iVar5 = *(int *)(param_1 + 0x274);
      }
      if ((((uVar4 & 2) == 2) && (iVar3 = *(int *)(param_1 + 0x278), iVar3 != 0)) &&
         ((iVar5 == 0 || (iVar3 < iVar5)))) {
        iVar5 = iVar3;
      }
      if ((iVar5 != 0) && (iVar6 = iVar5, param_3 == 0)) {
        uVar2 = uVar4 & 0xfffffffb;
        if ((*(uint *)(param_1 + 0x1a0) & 0x100) != 0) {
          uVar2 = uVar4 & 0xfffffff9;
        }
        if ((*(uint *)(param_1 + 0x1a0) & 0x80) != 0) {
          uVar2 = uVar2 & 0xfffffffe;
        }
        uVar4 = FUN_c055c52c(param_1,uVar2,0xfd010106,1);
        if (uVar4 == 0) {
          *(uint *)(param_1 + 0x248) = *(uint *)(param_1 + 0x248) | 0x400;
        }
        else {
          iVar6 = 4;
        }
      }
    }
    *param_2 = iVar6;
  }
  return 0;
}



/* c055ccd0 FUN_c055ccd0 */

/* Boundary evidence: original MIPS .pdata c055ccd0..c055cd43. Semantic name remains unreviewed. */

void FUN_c055ccd0(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x2c0);
  if ((*(uint *)(param_2 + 0x1a0) & 0x100) != 0) {
    uVar1 = uVar1 & 0xfffffffd;
  }
  if ((*(uint *)(param_2 + 0x1a0) & 0x80) != 0) {
    uVar1 = uVar1 & 0xfffffffe;
  }
  FUN_c055c52c(param_2,uVar1,0xfd010106,1);
  CTEFreeMem(param_1);
  return;
}



/* c055cd44 FUN_c055cd44 */

/* Boundary evidence: original MIPS .pdata c055cd44..c055cdeb. Semantic name remains unreviewed. */

void FUN_c055cd44(undefined4 param_1,int param_2)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  if ((*(uint *)(param_2 + 0x248) & 8) == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  }
  else {
    *(uint *)(param_2 + 0x248) = *(uint *)(param_2 + 0x248) & 0xfffffff7;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
    piVar1 = FUN_c05427a0(0x2c);
    if (piVar1 != (int *)0x0) {
      *piVar1 = param_2;
      piVar1[1] = (int)FUN_c055ccd0;
      *(uint *)(param_2 + 0x248) = *(uint *)(param_2 + 0x248) | 0x400;
      NdisScheduleWorkItem((int)piVar1);
    }
  }
  return;
}



/* c055cdec FUN_c055cdec */

/* Boundary evidence: original MIPS .pdata c055cdec..c055ce9f. Semantic name remains unreviewed. */

int FUN_c055cdec(int *param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int local_18 [2];
  
  local_18[0] = *param_1;
  bVar1 = FUN_c054dce8(param_2);
  if (((CONCAT31(extraout_var,bVar1) == 0) || (*(int *)(param_2 + 0x354) != 1)) ||
     ((iVar2 = FUN_c054c29c(param_2,1,local_18,4), iVar2 == 0 &&
      ((iVar2 = 0, (*(uint *)(param_2 + 0x248) & 0x20) != 0 &&
       (uVar3 = FUN_c055c52c(param_2,local_18[0],0xfd010102,0), uVar3 != 0)))))) {
    iVar2 = -0x3fffffff;
  }
  return iVar2;
}



/* c055cea0 FUN_c055cea0 */

/* Boundary evidence: original MIPS .pdata c055cea0..c055cf0f. Semantic name remains unreviewed. */

void FUN_c055cea0(int param_1,int param_2)

{
  ushort local_10;
  undefined2 local_e;
  
  local_10 = 6;
  local_e = (undefined2)*(undefined4 *)(param_1 + 0x120);
  if (param_2 == 0) {
    local_10 = 2;
  }
  if (*(int *)(param_1 + 0x488) != 0) {
    local_10 = local_10 | 0x10;
  }
  (*DAT_c056551c)(DAT_c05654dc,local_e,&local_10);
  return;
}



/* c055cf10 FUN_c055cf10 */

undefined4 * FUN_c055cf10(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = &DAT_c056555c;
  puVar2 = DAT_c056555c;
  do {
    if (puVar2 == (undefined4 *)0x0) {
      return puVar1;
    }
    iVar3 = puVar2[7];
    if (DAT_c0565640 != 0) {
      iVar3 = puVar2[10];
    }
    if ((puVar2[1] == param_1) && (param_2 == -1)) {
      return puVar1;
    }
    if (((puVar2[3] == param_2) && (puVar2[4] == param_3)) &&
       ((param_4 == 0 || (param_4 == puVar2[5])))) {
      if (param_5 == 0) {
        return puVar1;
      }
      if (iVar3 == param_5) {
        return puVar1;
      }
    }
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}



/* c055cfac FUN_c055cfac */

undefined4 * FUN_c055cfac(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cStackX_1;
  
  puVar2 = &DAT_c056555c;
  if (DAT_c056555c != (undefined4 *)0x0) {
    cStackX_1 = (char)(param_1 >> 8);
    puVar3 = puVar2;
    puVar1 = DAT_c056555c;
    do {
      puVar2 = puVar1;
      if (((uint)*(byte *)(puVar2 + 2) == (param_1 & 0xff)) &&
         (*(char *)((int)puVar2 + 9) == cStackX_1)) {
        return puVar3;
      }
      puVar3 = puVar2;
      puVar1 = (undefined4 *)*puVar2;
    } while ((undefined4 *)*puVar2 != (undefined4 *)0x0);
  }
  return puVar2;
}



/* c055d000 FUN_c055d000 */

/* Boundary evidence: original MIPS .pdata c055d000..c055d077. Semantic name remains unreviewed. */

int FUN_c055d000(int param_1)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
  piVar1 = (int *)DAT_c056555c;
  while ((piVar1 != (int *)0x0 && (*(int *)(piVar1[1] + 0x120) != param_1))) {
    piVar1 = (int *)*piVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
  return (int)piVar1;
}



/* c055d078 FUN_c055d078 */

/* Boundary evidence: original MIPS .pdata c055d078..c055d123. Semantic name remains unreviewed. */

void FUN_c055d078(int param_1)

{
  if (param_1 != 0) {
    if ((DAT_c0565640 != 0) && (*(LPVOID *)(param_1 + 0x2c) != (LPVOID)0x0)) {
      VirtualFree(*(LPVOID *)(param_1 + 0x2c),*(SIZE_T *)(param_1 + 0x24),0x4000);
      VirtualFree(*(LPVOID *)(param_1 + 0x2c),0,0x8000);
    }
    if (*(int *)(param_1 + 0x18) != 0) {
      (*DAT_c0565560)(DAT_c05654dc,*(undefined2 *)(param_1 + 8));
      (*DAT_c0565520)(*(undefined4 *)(param_1 + 0x18));
    }
    CTEFreeMem(param_1);
  }
  return;
}



/* c055d124 FUN_c055d124 */

/* Boundary evidence: original MIPS .pdata c055d124..c055d1a3. Semantic name remains unreviewed. */

undefined4 FUN_c055d124(int param_1)

{
  LPVOID pvVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(int *)(param_1 + 0x30) == 0) {
    VirtualFree(*(LPVOID *)(param_1 + 0x2c),*(SIZE_T *)(param_1 + 0x24),0x4000);
    CacheRangeFlush(0,0,1);
    pvVar1 = VirtualAlloc(*(LPVOID *)(param_1 + 0x2c),*(SIZE_T *)(param_1 + 0x24),0x1000,0x204);
    if (pvVar1 == (LPVOID)0x0) {
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x30) = 1;
    }
  }
  return uVar2;
}



/* c055d1a4 FUN_c055d1a4 */

/* Boundary evidence: original MIPS .pdata c055d1a4..c055d223. Semantic name remains unreviewed. */

undefined4 FUN_c055d1a4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(int *)(param_1 + 0x30) != 0) {
    VirtualFree(*(LPVOID *)(param_1 + 0x2c),*(SIZE_T *)(param_1 + 0x24),0x4000);
    CacheRangeFlush(0,0,1);
    iVar1 = VirtualCopy(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x20),
                        *(undefined4 *)(param_1 + 0x24),0x204);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  return uVar2;
}



/* c055d224 FUN_c055d224 */

/* Boundary evidence: original MIPS .pdata c055d224..c055d403. Semantic name remains unreviewed. */

int FUN_c055d224(uint param_1,int param_2,undefined *param_3)

{
  bool bVar1;
  HANDLE hObject;
  LPVOID lpParameter;
  int *piVar2;
  int iVar3;
  char cStackX_1;
  
  iVar3 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
  if (DAT_c056555c != (int *)0x0) {
    cStackX_1 = (char)(param_1 >> 8);
    piVar2 = DAT_c056555c;
    do {
      if (((uint)*(byte *)(piVar2 + 2) == (param_1 & 0xff)) &&
         (*(char *)((int)piVar2 + 9) == cStackX_1)) {
        if ((iVar3 == 0) || (iVar3 = (*(code *)param_3)(piVar2), iVar3 == 0)) {
          iVar3 = 0;
        }
        else {
          iVar3 = 1;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
          if ((code *)param_3 == FUN_c055d124) {
            *(uint *)(piVar2[1] + 0x490) = *(uint *)(piVar2[1] + 0x490) | 0x10;
          }
          else {
            *(uint *)(piVar2[1] + 0x490) = *(uint *)(piVar2[1] + 0x490) & 0xffffffef;
            if (((*(uint *)(piVar2[1] + 0x490) & 4) != 0) ||
               (bVar1 = true, (*(uint *)(piVar2[1] + 0x248) & 1) == 0)) {
              bVar1 = false;
            }
            if (((param_2 != 0) &&
                (lpParameter = (LPVOID)piVar2[1], *(int *)((int)lpParameter + 0x488) != 0)) &&
               ((!bVar1 || (*(int *)((int)lpParameter + 0x49c) == 0)))) {
              hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05458ec,lpParameter,0,
                                     (LPDWORD)0x0);
              CloseHandle(hObject);
            }
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
        }
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
  return iVar3;
}



/* c055d404 FUN_c055d404 */

/* Boundary evidence: original MIPS .pdata c055d404..c055d4bb. Semantic name remains unreviewed. */

undefined4 FUN_c055d404(int param_1,uint param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  
  if (param_1 == 0xb) {
    if (DAT_c0565640 == 0) {
      return 0;
    }
    pcVar2 = FUN_c055d1a4;
    iVar1 = 1;
  }
  else {
    if (param_1 != 0xc) {
      if (param_1 != 0x82) {
        return 0;
      }
      if (DAT_c05654dc != 0) {
        return 0;
      }
      DAT_c05654dc = *(undefined4 *)(param_3 + 4);
      return 0;
    }
    if (DAT_c0565640 == 0) {
      return 0;
    }
    pcVar2 = FUN_c055d124;
    iVar1 = 0;
  }
  FUN_c055d224(param_2 & 0xffff,iVar1,pcVar2);
  return 0;
}



/* c055d4bc FUN_c055d4bc */

/* Boundary evidence: original MIPS .pdata c055d4bc..c055d5db. Semantic name remains unreviewed. */

DWORD FUN_c055d4bc(LPCWSTR param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  HMODULE hLibModule;
  int iVar1;
  int *piVar2;
  DWORD DVar3;
  undefined1 auStackX_0 [8];
  undefined4 local_res8;
  undefined4 local_resc;
  
  DVar3 = 0;
  local_res8 = param_3;
  local_resc = param_4;
  hLibModule = LoadLibraryW(param_1);
  if (hLibModule == (HMODULE)0x0) {
    DVar3 = GetLastError();
  }
  else {
    do {
      if (*(int *)((int)register0x00000074 + 8) == 0) goto LAB_c055d5ac;
      piVar2 = *(int **)((int)register0x00000074 + 0xc);
      iVar1 = GetProcAddressW(hLibModule);
      *piVar2 = iVar1;
      register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + 8);
    } while (iVar1 != 0);
    DVar3 = GetLastError();
    if (DVar3 != 0) {
      FreeLibrary(hLibModule);
      hLibModule = (HMODULE)0x0;
    }
  }
LAB_c055d5ac:
  *param_2 = hLibModule;
  return DVar3;
}



/* c055d5dc FUN_c055d5dc */

/* Boundary evidence: original MIPS .pdata c055d5dc..c055d85f. Semantic name remains unreviewed. */

undefined4 FUN_c055d5dc(void)

{
  DWORD DVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
  DVar1 = FUN_c055d4bc(L"PCMCIA.DLL",&DAT_c0565524,L"CardGetStatus",&DAT_c05654e8);
  if (DVar1 == 0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
    DAT_c056555c = 0;
    local_16 = 0x80;
    local_18 = 0x19;
    local_15 = 1;
    local_17 = 0;
    DAT_c05654dc = (*DAT_c05654e0)(FUN_c055d404,&local_18);
    if (DAT_c05654dc != 0) {
      return 1;
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0565540);
  }
  return 0;
}



/* c055d860 FUN_c055d860 */

uint FUN_c055d860(uint param_1)

{
  if ((param_1 < 0x1e) || (0x24 < param_1)) {
    if ((0x2c < param_1) && (param_1 < 0x38)) {
      param_1 = 0x32;
    }
  }
  else {
    param_1 = 0x21;
  }
  return param_1;
}



/* c055d8a8 FUN_c055d8a8 */

/* Boundary evidence: original MIPS .pdata c055d8a8..c055da4b. Semantic name remains unreviewed. */

undefined4 FUN_c055d8a8(undefined2 param_1,int param_2,void *param_3,undefined2 *param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint local_3b8 [2];
  byte abStack_3b0 [64];
  int local_370 [214];
  
  local_3b8[0] = 10;
  uVar8 = 0;
  iVar2 = (*DAT_c056556c)(param_1,0x1b,abStack_3b0,local_3b8);
  if (iVar2 != 0) {
    return 0xc000009a;
  }
  uVar10 = 0xffffffff;
  uVar9 = 0;
  uVar6 = 0;
  if (local_3b8[0] == 0) {
LAB_c055da20:
    uVar8 = 0xc0010022;
  }
  else {
    piVar5 = local_370;
    do {
      uVar3 = (uint)*(byte *)(piVar5 + 4);
      piVar4 = piVar5;
      for (uVar7 = uVar3; uVar7 != 0; uVar7 = uVar7 - 1) {
        if ((*piVar4 == param_2) && (uVar9 < uVar3)) {
          uVar10 = uVar6;
          uVar9 = uVar3;
        }
        piVar4 = piVar4 + 1;
      }
      uVar6 = uVar6 + 1;
      piVar5 = piVar5 + 0x17;
    } while (uVar6 < local_3b8[0]);
    if (uVar10 == 0xffffffff) {
      if (local_3b8[0] == 0) goto LAB_c055da20;
      uVar10 = 0;
    }
    iVar2 = uVar10 * 0x5c;
    memcpy(param_3,abStack_3b0 + iVar2,0x5c);
    bVar1 = abStack_3b0[iVar2 + 1];
    *param_4 = 0x32;
    if ((bVar1 & 1) != 0) {
      uVar10 = FUN_c055d860((uint)CONCAT11(abStack_3b0[iVar2 + 3],abStack_3b0[iVar2 + 2]));
      *param_4 = (short)uVar10;
    }
  }
  return uVar8;
}



/* c055da4c FUN_c055da4c */

/* Boundary evidence: original MIPS .pdata c055da4c..c055dc3f. Semantic name remains unreviewed. */

undefined4 FUN_c055da4c(int param_1,uint param_2,byte *param_3,uint param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 local_res4;
  undefined1 uStackX_5;
  undefined1 auStack_50 [8];
  undefined1 local_48;
  undefined1 local_47;
  byte local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  byte local_3f;
  undefined1 local_3e;
  uint local_30;
  
  local_30 = DAT_c05653c8;
  uStackX_5 = (undefined1)(param_2 >> 8);
  local_res4 = (undefined1)param_2;
  uVar4 = 0xc0000001;
  iVar2 = (*DAT_c0565554)(DAT_c05654dc,param_2 & 0xffff);
  if (iVar2 == 0) {
    while( true ) {
      local_46 = 6;
      local_48 = local_res4;
      local_47 = uStackX_5;
      if (param_5 != 0) {
        local_46 = 0x16;
      }
      local_45 = 0;
      local_40 = 3;
      local_3f = param_3[0x51];
      local_44 = 2;
      local_43 = (undefined1)param_4;
      local_42 = 0;
      local_41 = 0;
      local_3e = 0;
      iVar2 = (*DAT_c0565558)(DAT_c05654dc,&local_48);
      if (iVar2 == 0) break;
      if (((iVar2 != 0xe) || ((*param_3 & 4) == 0)) ||
         (uVar3 = FUN_c055d860((uint)*(ushort *)(param_3 + 6)), bVar1 = param_4 == uVar3,
         param_4 = uVar3, bVar1)) goto LAB_c055dc08;
    }
    uVar4 = 0;
    (*DAT_c0565528)(DAT_c05654dc,param_2 & 0xffff,0,0,auStack_50);
    if ((local_46 & 4) == 0) {
      *(uint *)(param_1 + 0x490) = *(uint *)(param_1 + 0x490) & 0xfffffff7;
    }
    else {
      *(uint *)(param_1 + 0x490) = *(uint *)(param_1 + 0x490) | 8;
    }
  }
LAB_c055dc08:
  FUN_c05625b0(local_30);
  return uVar4;
}



/* c055dc40 FUN_c055dc40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c055dc40..c055dfd7. Semantic name remains unreviewed. */

int FUN_c055dc40(int param_1,int param_2,int param_3,uint param_4,int param_5,int *param_6)

{
  bool bVar1;
  int *piVar2;
  undefined4 *_Dst;
  uint uVar3;
  DWORD DVar4;
  LPVOID pvVar5;
  uint dwSize;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  ushort local_a0 [4];
  undefined1 local_98;
  undefined1 local_97;
  byte local_96;
  undefined1 local_95;
  int local_94;
  undefined1 local_90;
  byte abStack_88 [96];
  
  iVar8 = 0;
  if (DAT_c0565524 == 0) {
    return -0x3fffffff;
  }
  if (param_5 != 0) {
    piVar2 = FUN_c055cf10(param_1,param_2,param_3,param_4,0);
    iVar7 = *piVar2;
    if (iVar7 != 0) {
      if (DAT_c0565640 == 0) {
        *param_6 = *(int *)(iVar7 + 0x1c);
      }
      else {
        *param_6 = *(int *)(iVar7 + 0x28);
      }
      return 0;
    }
  }
  _Dst = FUN_c05427a0(0x34);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x34);
    *(char *)(_Dst + 2) = (char)*(undefined4 *)(param_1 + 0x120);
    uVar6 = *(undefined4 *)(param_1 + 0x120);
    _Dst[1] = param_1;
    *(char *)((int)_Dst + 9) = (char)((uint)uVar6 >> 8);
    _Dst[3] = param_2;
    _Dst[4] = param_3;
    _Dst[5] = param_4;
    iVar7 = FUN_c055d000(*(int *)(param_1 + 0x120));
    bVar1 = true;
    if (iVar7 == 0) {
      iVar8 = FUN_c055d8a8(*(undefined2 *)(_Dst + 2),param_2,abStack_88,local_a0);
      if (iVar8 != 0) goto LAB_c055dd20;
    }
    else {
      bVar1 = false;
    }
    local_97 = *(undefined1 *)((int)_Dst + 9);
    local_98 = *(undefined1 *)(_Dst + 2);
    local_96 = (byte)(param_4 & 0xffff) | 8;
    local_95 = (undefined1)((param_4 & 0xffff) >> 8);
    local_90 = 0x80;
    local_94 = param_3;
    iVar7 = (*DAT_c0565530)(DAT_c05654dc,&local_98);
    _Dst[6] = iVar7;
    if (iVar7 == 0) {
      local_96 = (byte)param_4;
      local_95 = (undefined1)(param_4 >> 8);
      iVar7 = (*DAT_c0565530)(DAT_c05654dc,&local_98);
      _Dst[6] = iVar7;
      if (iVar7 == 0) goto LAB_c055dd18;
    }
    uVar3 = (*DAT_c0565568)(_Dst[6],param_2,param_3,0);
    _Dst[7] = uVar3;
    if (uVar3 != 0) {
      uVar3 = uVar3 % _DAT_00005b04;
      if (_DAT_00005b04 == 0) {
        trap(0x1c00);
      }
      if ((bVar1) &&
         (iVar8 = FUN_c055da4c(param_1,(uint)*(ushort *)(_Dst + 2),abStack_88,(uint)local_a0[0],
                               *(int *)(param_1 + 0x488)), iVar8 != 0)) goto LAB_c055dd20;
      *param_6 = _Dst[7];
      if (DAT_c0565640 != 0) {
        dwSize = uVar3 + param_3;
        if (dwSize < uVar3) {
          iVar8 = -0x3ffeffeb;
          goto LAB_c055dd20;
        }
        _Dst[9] = dwSize;
        iVar8 = -0x3fffff66;
        _Dst[8] = _Dst[7] - uVar3;
        pvVar5 = VirtualAlloc((LPVOID)0x0,dwSize,0x2000,1);
        _Dst[0xb] = pvVar5;
        if ((pvVar5 == (LPVOID)0x0) ||
           (iVar7 = VirtualCopy(pvVar5,_Dst[8],_Dst[9],0x204), iVar7 == 0)) goto LAB_c055dd20;
        _Dst[10] = _Dst[0xb] + uVar3;
        iVar8 = 0;
        *param_6 = _Dst[0xb] + uVar3;
      }
      if (iVar8 == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
        *_Dst = DAT_c056555c;
        DAT_c056555c = _Dst;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
        return 0;
      }
      goto LAB_c055dd20;
    }
    DVar4 = GetLastError();
    if (DVar4 == 0x1e) {
      iVar8 = -0x3ffeffe2;
      goto LAB_c055dd20;
    }
  }
LAB_c055dd18:
  iVar8 = -0x3fffff66;
LAB_c055dd20:
  *param_6 = 0;
  FUN_c055d078((int)_Dst);
  return iVar8;
}



/* c055dfd8 FUN_c055dfd8 */

/* Boundary evidence: original MIPS .pdata c055dfd8..c055dffb. Semantic name remains unreviewed. */

void FUN_c055dfd8(int param_1,int param_2,int param_3,int *param_4)

{
  FUN_c055dc40(param_1,param_2,param_3,1,0,param_4);
  return;
}



/* c055dffc FUN_c055dffc */

/* Boundary evidence: original MIPS .pdata c055dffc..c055e0af. Semantic name remains unreviewed. */

undefined4 FUN_c055dffc(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_c0565524 == 0) {
    uVar1 = 0xc0000001;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
    puVar2 = FUN_c055cf10(param_1,param_2,param_3,0,param_4);
    puVar3 = (undefined4 *)*puVar2;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar2 = *puVar3;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
    FUN_c055d078((int)puVar3);
    uVar1 = 0;
  }
  return uVar1;
}



/* c055e0b0 FUN_c055e0b0 */

/* Boundary evidence: original MIPS .pdata c055e0b0..c055e0cb. Semantic name remains unreviewed. */

void FUN_c055e0b0(int param_1,int param_2,int param_3,int param_4)

{
  FUN_c055dffc(param_1,param_2,param_3,param_4);
  return;
}



/* c055e0cc FUN_c055e0cc */

/* Boundary evidence: original MIPS .pdata c055e0cc..c055e0ef. Semantic name remains unreviewed. */

void FUN_c055e0cc(int param_1,int param_2,int param_3,int *param_4)

{
  FUN_c055dc40(param_1,param_2,param_3,0,0,param_4);
  return;
}



/* c055e0f0 FUN_c055e0f0 */

/* Boundary evidence: original MIPS .pdata c055e0f0..c055e113. Semantic name remains unreviewed. */

void FUN_c055e0f0(int param_1,int param_2,int param_3)

{
  FUN_c055dffc(param_1,-1,param_2,param_3);
  return;
}



/* c055e114 FUN_c055e114 */

/* Boundary evidence: original MIPS .pdata c055e114..c055e133. Semantic name remains unreviewed. */

void FUN_c055e114(int *param_1)

{
  FUN_c055566c(0,param_1);
  return;
}



/* c055e134 FUN_c055e134 */

/* Boundary evidence: original MIPS .pdata c055e134..c055e1cb. Semantic name remains unreviewed. */

undefined4 FUN_c055e134(int param_1)

{
  int iVar1;
  
  if (DAT_c0565524 != 0) {
    iVar1 = (*DAT_c0565514)(DAT_c05654dc,
                            *(uint *)(param_1 + 0x120) & 0xff |
                            (*(uint *)(param_1 + 0x120) >> 8 & 0xff) << 8,FUN_c055e114,
                            *(undefined4 *)(param_1 + 0x50));
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar1 == 0x1e) {
      return 0xc001001e;
    }
  }
  return 0xc0000001;
}



/* c055e1cc FUN_c055e1cc */

/* Boundary evidence: original MIPS .pdata c055e1cc..c055e237. Semantic name remains unreviewed. */

undefined4 FUN_c055e1cc(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_c0565524 == 0) {
    uVar1 = 0xc0000001;
  }
  else {
    (*DAT_c0565570)(DAT_c05654dc,
                    *(uint *)(param_1 + 0x120) & 0xff |
                    (*(uint *)(param_1 + 0x120) >> 8 & 0xff) << 8);
    uVar1 = 0;
  }
  return uVar1;
}



/* c055e238 FUN_c055e238 */

/* Boundary evidence: original MIPS .pdata c055e238..c055e2df. Semantic name remains unreviewed. */

int FUN_c055e238(short *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  piVar2 = (int *)FUN_c0560f34(param_1);
  piVar1 = DAT_c0565400;
  if (piVar2 != (int *)0x0) {
    while (piVar3 = piVar1, piVar3 != (int *)0x0) {
      if (*(int **)piVar3[2] == piVar2) {
        FUN_c055a404((int)(piVar3 + 0x28));
        break;
      }
      piVar1 = (int *)*piVar3;
    }
    FUN_c05613c8(piVar2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  return (int)piVar3;
}



/* c055e2e0 FUN_c055e2e0 */

/* Boundary evidence: original MIPS .pdata c055e2e0..c055e373. Semantic name remains unreviewed. */

undefined4 FUN_c055e2e0(int param_1,short *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  ushort auStack_18 [4];
  
  uVar3 = 0;
  FUN_c055f4e4(auStack_18,param_2);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
  iVar2 = *(int *)(param_1 + 4);
  do {
    if (iVar2 == 0) {
LAB_c055e350:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      return uVar3;
    }
    bVar1 = FUN_c055f908((ushort *)(iVar2 + 0x10),auStack_18,1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      uVar3 = 1;
      goto LAB_c055e350;
    }
    iVar2 = *(int *)(iVar2 + 0x1c);
  } while( true );
}



/* c055e374 FUN_c055e374 */

/* Boundary evidence: original MIPS .pdata c055e374..c055e4c3. Semantic name remains unreviewed. */

undefined4 FUN_c055e374(short *param_1,int param_2,STRSAFE_LPWSTR param_3,LPCWSTR param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_30;
  wchar_t *local_2c;
  
  uVar4 = 0;
  piVar1 = (int *)FUN_c055e238(param_1);
  local_2c = L"%s%u";
  uVar3 = 1;
  while( true ) {
    StringCchPrintfW(param_3,0x80,local_2c,param_1,uVar3);
    StringCchPrintfW(param_4,0x104,L"%s\\%s\\Parms",L"\\Comm",param_3);
    if (((piVar1 == (int *)0x0) || (iVar2 = FUN_c055e2e0((int)piVar1,param_3), iVar2 == 0)) &&
       ((iVar2 = FUN_c0560594((HKEY)0x80000002,param_4,L"BusType",(LPBYTE)&local_30), iVar2 == 0 ||
        (local_30 == param_2)))) break;
    uVar3 = uVar3 + 1;
    if (9 < uVar3) {
LAB_c055e47c:
      if (piVar1 != (int *)0x0) {
        FUN_c055915c(piVar1,0);
      }
      return uVar4;
    }
  }
  uVar4 = 1;
  goto LAB_c055e47c;
}



/* c055e4c4 FUN_c055e4c4 */

/* Boundary evidence: original MIPS .pdata c055e4c4..c055e533. Semantic name remains unreviewed. */

undefined4 FUN_c055e4c4(LPCWSTR param_1,LPBYTE param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_c0560468((HKEY)0x80000002,param_1,L"Sckt",param_2,2,4);
  if (iVar1 != 0) {
    uVar2 = OpenDeviceKey(param_1);
  }
  return uVar2;
}



/* c055e534 FUN_c055e534 */

/* Boundary evidence: original MIPS .pdata c055e534..c055e6df. Semantic name remains unreviewed. */

undefined4 FUN_c055e534(LPCWSTR param_1)

{
  HKEY hKey;
  int iVar1;
  int iVar2;
  byte local_430;
  byte local_42f;
  undefined4 local_42c;
  short asStack_428 [128];
  wchar_t awStack_328 [128];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c05653c8;
  local_42c = 0;
  hKey = (HKEY)FUN_c055e4c4(param_1,&local_430);
  if (hKey != (HKEY)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565540);
    if ((DAT_c05654dc != 0) || (iVar1 = FUN_c055d5dc(), iVar1 != 0)) {
      iVar1 = FUN_c0560544(hKey,(LPCWSTR)0x0,L"Miniport",(LPBYTE)asStack_428,0x100);
      if ((iVar1 != 0) && (iVar1 = FUN_c055e374(asStack_428,8,awStack_328,aWStack_228), iVar1 != 0))
      {
        iVar2 = (uint)local_42f * 0x100 + (uint)local_430;
        iVar1 = FUN_c05605b8((HKEY)0x80000002,aWStack_228,L"BusType",8);
        if (((iVar1 != 0) &&
            (iVar1 = FUN_c05605b8((HKEY)0x80000002,aWStack_228,L"BusNumber",iVar2), iVar1 != 0)) &&
           (iVar1 = FUN_c05605b8((HKEY)0x80000002,aWStack_228,L"PlugAndPlay",0), iVar1 != 0)) {
          FUN_c0560094(L"\\Comm",asStack_428,L"NDIS",awStack_328,-2,iVar2,FUN_c055173c,&local_42c,0)
          ;
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565540);
    RegCloseKey(hKey);
  }
  FUN_c05625b0(local_20);
  return local_42c;
}



/* c055e6e0 FUN_c055e6e0 */

/* Boundary evidence: original MIPS .pdata c055e6e0..c055e7af. Semantic name remains unreviewed. */

undefined4 FUN_c055e6e0(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  if (DAT_c0565524 == 0) {
    uVar1 = 0xc0000001;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x120) & 0xff | (*(uint *)(param_1 + 0x120) >> 8 & 0xff) << 8;
    (*DAT_c0565570)(DAT_c05654dc,uVar4);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
    while( true ) {
      piVar2 = FUN_c055cfac(uVar4);
      iVar3 = *piVar2;
      if (iVar3 == 0) break;
      if ((int *)*piVar2 != (int *)0x0) {
        *piVar2 = *(int *)*piVar2;
      }
      FUN_c055d078(iVar3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
    uVar1 = 0;
  }
  return uVar1;
}



/* c055e7b0 FUN_c055e7b0 */

/* Boundary evidence: original MIPS .pdata c055e7b0..c055eacf. Semantic name remains unreviewed. */

undefined4 FUN_c055e7b0(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  LSTATUS LVar4;
  ushort uVar5;
  short sVar6;
  short *psVar7;
  uint uVar8;
  HKEY__ *pHVar9;
  HKEY__ *pHVar10;
  undefined4 local_188;
  DWORD DStack_184;
  DWORD aDStack_180 [2];
  undefined1 local_178;
  undefined1 local_177;
  undefined1 local_176;
  undefined1 local_175;
  undefined1 local_174;
  undefined1 local_173;
  undefined1 local_168;
  undefined1 local_167;
  char local_164;
  byte local_163;
  HKEY__ aHStack_162 [64];
  short local_60 [34];
  uint local_1c;
  
  local_1c = DAT_c05653c8;
  if (DAT_c0565524 == 0) {
    FUN_c05625b0(DAT_c05653c8);
    return 0xc0000001;
  }
  local_177 = (undefined1)((uint)param_1 >> 8);
  local_176 = 0;
  local_178 = (undefined1)param_1;
  local_188 = (HKEY__ *)CONCAT31(CONCAT21(local_188._2_2_,local_177),local_178);
  local_174 = 0x21;
  local_175 = 0;
  iVar3 = (*DAT_c056552c)(&local_178);
  while (iVar3 == 0) {
    local_168 = 0;
    local_167 = 1;
    local_173 = 0;
    iVar3 = (*DAT_c0565518)(&local_178);
    if (iVar3 != 0) break;
    if (local_164 == '\x06') {
      local_174 = 0x22;
      iVar3 = (*DAT_c0565564)(&local_178);
      if (iVar3 == 0) goto LAB_c055e8d0;
      break;
    }
    iVar3 = (*DAT_c0565564)();
  }
  goto LAB_c055eaa8;
  while (iVar3 = (*DAT_c0565564)(&local_178), pHVar9 = local_188, pHVar10 = local_188, iVar3 == 0) {
LAB_c055e8d0:
    local_168 = 0;
    local_167 = 1;
    local_173 = 0;
    iVar3 = (*DAT_c0565518)(&local_178);
    if (iVar3 != 0) goto LAB_c055eaa8;
    if (local_164 == '\x04') {
      iVar3 = 0;
      pHVar9 = aHStack_162;
      pHVar10 = (HKEY__ *)(uint)local_163;
      break;
    }
  }
  if (((iVar3 == 0) && (uVar8 = (int)pHVar10 * 2, uVar8 < 0x21)) &&
     (LVar4 = RegOpenKeyExW((HKEY)0x80000002,*(LPCWSTR *)(param_2 + 4),0,0x20019,(PHKEY)&local_188),
     LVar4 == 0)) {
    LVar4 = RegQueryValueExW(local_188,L"NetworkAddress",(LPDWORD)0x0,&DStack_184,(LPBYTE)0x0,
                             aDStack_180);
    if (LVar4 != 0) {
      if (uVar8 != 0) {
        psVar7 = local_60;
        iVar3 = (uVar8 - 1 >> 1) + 1;
        do {
          bVar1 = (byte)pHVar9->unused;
          bVar2 = bVar1 >> 4;
          if (bVar2 < 10) {
            sVar6 = bVar2 + 0x30;
          }
          else if (bVar2 < 0x10) {
            sVar6 = bVar2 + 0x37;
          }
          else {
            sVar6 = 0x30;
          }
          uVar5 = bVar1 & 0xf;
          *psVar7 = sVar6;
          if (uVar5 < 10) {
            sVar6 = uVar5 + 0x30;
          }
          else if (uVar5 < 0x10) {
            sVar6 = uVar5 + 0x37;
          }
          else {
            sVar6 = 0x30;
          }
          psVar7[1] = sVar6;
          pHVar9 = (HKEY__ *)((int)&pHVar9->unused + 1);
          iVar3 = iVar3 + -1;
          psVar7 = psVar7 + 2;
        } while (iVar3 != 0);
      }
      local_60[(int)pHVar10 * 2] = 0;
      RegSetValueExW(local_188,L"NetworkAddress",0,1,(BYTE *)local_60,(int)pHVar10 * 4 + 2);
    }
    RegCloseKey(local_188);
  }
LAB_c055eaa8:
  FUN_c05625b0(local_1c);
  return 0;
}



/* c055ead0 FUN_c055ead0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c055ead0..c055ec2f. Semantic name remains unreviewed. */

uint FUN_c055ead0(int param_1,int param_2,undefined1 *param_3,uint param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *local_30;
  undefined1 *local_2c;
  
  uVar3 = 0;
  uVar2 = param_2 << 1;
  if (param_4 != 0) {
    do {
      uVar5 = uVar2 % _DAT_00005b04;
      if (_DAT_00005b04 == 0) {
        trap(0x1c00);
      }
      iVar4 = uVar2 - uVar5;
      iVar1 = FUN_c055dc40(param_1,iVar4,_DAT_00005b04,2,1,(int *)&local_30);
      if (iVar1 != 0) {
        return 0;
      }
      local_30 = local_30 + uVar5;
      local_2c = local_30 + (_DAT_00005b04 - 1);
      for (; (local_30 <= local_2c && (uVar3 < param_4)); uVar3 = uVar3 + 1) {
        if (param_5 == 0) {
          *local_30 = *param_3;
        }
        else {
          *param_3 = *local_30;
        }
        local_30 = local_30 + 2;
        param_3 = param_3 + 1;
      }
      uVar2 = _DAT_00005b04 + iVar4;
    } while (uVar3 < param_4);
  }
  return uVar3;
}



/* c055ec30 FUN_c055ec30 */

/* Boundary evidence: original MIPS .pdata c055ec30..c055ec4f. Semantic name remains unreviewed. */

void FUN_c055ec30(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0565540);
  return;
}



/* c055ec50 FUN_c055ec50 */

/* Boundary evidence: original MIPS .pdata c055ec50..c055ed0b. Semantic name remains unreviewed. */

void FUN_c055ec50(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x120) & 0xff | (*(uint *)(param_1 + 0x120) >> 8 & 0xff) << 8;
  (*DAT_c05654d8)(DAT_c05654dc,uVar2);
  if (DAT_c0565640 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
    if (((*(uint *)(param_1 + 0x490) & 0x10) == 0) &&
       (piVar1 = FUN_c055cfac(uVar2), piVar1 != (int *)0x0)) {
      FUN_c055d1a4(*piVar1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
  }
  return;
}



/* c055ed0c FUN_c055ed0c */

/* Boundary evidence: original MIPS .pdata c055ed0c..c055eda7. Semantic name remains unreviewed. */

void FUN_c055ed0c(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x120) & 0xff | (*(uint *)(param_1 + 0x120) >> 8 & 0xff) << 8;
  if (DAT_c0565640 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
    piVar1 = FUN_c055cfac(uVar2);
    if (piVar1 != (int *)0x0) {
      FUN_c055d124(*piVar1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565500);
  }
  (*DAT_c0565534)(DAT_c05654dc,uVar2);
  return;
}



/* c055eda8 FUN_c055eda8 */

/* Boundary evidence: original MIPS .pdata c055eda8..c055edd3. Semantic name remains unreviewed. */

void FUN_c055eda8(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05654c0);
  DAT_c05654d4 = 0;
  return;
}



/* c055edd4 FUN_c055edd4 */

/* Boundary evidence: original MIPS .pdata c055edd4..c055f023. Semantic name remains unreviewed. */

uint FUN_c055edd4(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  HANDLE pvVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD DVar4;
  uint uVar5;
  
  if ((*(uint *)(param_1 + 0x248) & 0x4100) != 0) {
    if (param_3 == 0) {
      return 0xc0000001;
    }
    return 0;
  }
  param_4[1] = 0;
  param_4[3] = param_4[3] & 0x20U | 4;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_4[0xc] = (int)pvVar1;
  uVar5 = 0;
  do {
    if ((*(uint *)(param_1 + 0x54) & 0x300000) == 0) break;
    NdisMSleep(1000);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 5000);
  if (uVar5 == 5000) {
    uVar5 = 0xc0010000;
  }
  else {
    if (((param_3 != 0) && (*(int *)(*(int *)(param_1 + 8) + 0x54) != 0)) ||
       ((param_3 == 0 && (*(int *)(*(int *)(param_1 + 8) + 0x44) != 0)))) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      FUN_c05565d0(param_1,param_4);
      iVar2 = __GetUserKData(8);
      uVar5 = (uint)(*(int *)(param_1 + 0x4b4) != iVar2);
      if (uVar5 == 1) {
        uVar5 = TryEnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
        uVar5 = uVar5 & 0xff;
        if (uVar5 == 1) {
          *(undefined4 *)(param_1 + 0x454) = 0x1b0123;
          uVar3 = __GetUserKData(8);
          *(undefined4 *)(param_1 + 0x458) = uVar3;
        }
      }
      if ((uVar5 == 0) && ((*(uint *)(param_1 + 0x54) & 0x40000) == 0)) {
        FUN_c054cc28(param_1,0,0);
      }
      else {
        FUN_c05584e8(param_1);
      }
      if (uVar5 != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4b0));
        *(undefined4 *)(param_1 + 0x454) = 0;
        *(undefined4 *)(param_1 + 0x458) = 0;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565600);
      uVar5 = 0xffffffff;
      DVar4 = WaitForSingleObject((HANDLE)param_4[0xc],0xffffffff);
      if (-1 < (int)DVar4) {
        uVar5 = param_4[0xb];
      }
      goto LAB_c055efec;
    }
    uVar5 = 0xc0000000;
  }
  uVar5 = uVar5 | 0xd;
LAB_c055efec:
  CloseHandle((HANDLE)param_4[0xc]);
  return uVar5;
}



/* c055f024 DbgBreakPoint */

void DbgBreakPoint(void)

{
                    /* 0x1f024  1  DbgBreakPoint */
  trap(0x400);
  return;
}



/* c055f030 DbgPrint */

/* Boundary evidence: original MIPS .pdata c055f030..c055f093. Semantic name remains unreviewed. */

size_t DbgPrint(STRSAFE_LPCSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  char acStack_210 [512];
  uint local_10;
  
                    /* 0x1f030  2  DbgPrint */
  local_10 = DAT_c05653c8;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  StringCbVPrintfA(acStack_210,0x200,param_1,(va_list)&local_res4);
  sVar1 = strlen(acStack_210);
  FUN_c05625b0(local_10);
  return sVar1;
}



/* c055f094 FUN_c055f094 */

/* Boundary evidence: original MIPS .pdata c055f094..c055f0e7. Semantic name remains unreviewed. */

void FUN_c055f094(LPCRITICAL_SECTION param_1)

{
  HANDLE pvVar1;
  PRTL_CRITICAL_SECTION_DEBUG p_Var2;
  
  InitializeCriticalSection(param_1);
  p_Var2 = (PRTL_CRITICAL_SECTION_DEBUG)(param_1 + 1);
  param_1[1].LockCount = (LONG)p_Var2;
  *(PRTL_CRITICAL_SECTION_DEBUG *)&p_Var2->Type = p_Var2;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1->SpinCount = (ULONG_PTR)pvVar1;
  return;
}



/* c055f0e8 FUN_c055f0e8 */

/* Boundary evidence: original MIPS .pdata c055f0e8..c055f17f. Semantic name remains unreviewed. */

undefined4 FUN_c055f0e8(LPCRITICAL_SECTION param_1,LPCRITICAL_SECTION param_2)

{
  PRTL_CRITICAL_SECTION_DEBUG p_Var1;
  PRTL_CRITICAL_SECTION_DEBUG p_Var2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  EnterCriticalSection(param_1);
  p_Var1 = (PRTL_CRITICAL_SECTION_DEBUG)(param_1 + 1);
  p_Var2 = *(PRTL_CRITICAL_SECTION_DEBUG *)&p_Var1->Type;
  do {
    if (p_Var2 == p_Var1) {
      puVar3 = (undefined4 *)param_1[1].LockCount;
      param_2->DebugInfo = p_Var1;
      param_2->LockCount = (LONG)puVar3;
      *puVar3 = param_2;
      param_1[1].LockCount = (LONG)param_2;
LAB_c055f148:
      LeaveCriticalSection(param_1);
      EventModify(param_1->SpinCount,3);
      return uVar4;
    }
    if (p_Var2 == (PRTL_CRITICAL_SECTION_DEBUG)param_2) {
      uVar4 = 0;
      goto LAB_c055f148;
    }
    p_Var2 = *(PRTL_CRITICAL_SECTION_DEBUG *)&p_Var2->Type;
  } while( true );
}



/* c055f180 FUN_c055f180 */

/* Boundary evidence: original MIPS .pdata c055f180..c055f217. Semantic name remains unreviewed. */

PRTL_CRITICAL_SECTION_DEBUG FUN_c055f180(LPCRITICAL_SECTION param_1)

{
  WORD WVar1;
  DWORD DVar2;
  PRTL_CRITICAL_SECTION_DEBUG p_Var3;
  PRTL_CRITICAL_SECTION_DEBUG p_Var4;
  PRTL_CRITICAL_SECTION_DEBUG p_Var5;
  
  p_Var4 = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  p_Var5 = (PRTL_CRITICAL_SECTION_DEBUG)(param_1 + 1);
  do {
    EnterCriticalSection(param_1);
    p_Var3 = *(PRTL_CRITICAL_SECTION_DEBUG *)p_Var5;
    if (p_Var3 != p_Var5) {
      p_Var4 = p_Var3;
    }
    *(PRTL_CRITICAL_SECTION_DEBUG *)(*(int *)p_Var3 + 4) = p_Var5;
    WVar1 = p_Var3->CreatorBackTraceIndex;
    p_Var5->Type = p_Var3->Type;
    p_Var5->CreatorBackTraceIndex = WVar1;
    LeaveCriticalSection(param_1);
  } while ((p_Var4 == (PRTL_CRITICAL_SECTION_DEBUG)0x0) &&
          (DVar2 = WaitForSingleObject((HANDLE)param_1->SpinCount,0xffffffff), DVar2 == 0));
  return p_Var4;
}



/* c055f218 FUN_c055f218 */

/* Boundary evidence: original MIPS .pdata c055f218..c055f28f. Semantic name remains unreviewed. */

undefined4 * FUN_c055f218(undefined4 *param_1,int *param_2,LPCRITICAL_SECTION param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection(param_3);
  puVar1 = (undefined4 *)*param_1;
  puVar2 = puVar1;
  if (puVar1 == param_1) {
    puVar2 = (undefined4 *)0x0;
  }
  *param_2 = (int)puVar1;
  param_2[1] = (int)param_1;
  puVar1[1] = param_2;
  *param_1 = param_2;
  LeaveCriticalSection(param_3);
  return puVar2;
}



/* c055f290 FUN_c055f290 */

/* Boundary evidence: original MIPS .pdata c055f290..c055f307. Semantic name remains unreviewed. */

undefined4 * FUN_c055f290(undefined4 *param_1,int *param_2,LPCRITICAL_SECTION param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection(param_3);
  puVar1 = (undefined4 *)param_1[1];
  puVar2 = puVar1;
  if (puVar1 == param_1) {
    puVar2 = (undefined4 *)0x0;
  }
  *param_2 = (int)param_1;
  param_2[1] = (int)puVar1;
  *puVar1 = param_2;
  param_1[1] = param_2;
  LeaveCriticalSection(param_3);
  return puVar2;
}



/* c055f308 FUN_c055f308 */

/* Boundary evidence: original MIPS .pdata c055f308..c055f373. Semantic name remains unreviewed. */

int FUN_c055f308(int *param_1,LPCRITICAL_SECTION param_2)

{
  int *piVar1;
  int *piVar2;
  
  EnterCriticalSection(param_2);
  piVar1 = (int *)*param_1;
  piVar2 = (int *)0x0;
  if (piVar1 != param_1) {
    *(int **)(*piVar1 + 4) = param_1;
    *param_1 = *piVar1;
    piVar2 = piVar1;
  }
  LeaveCriticalSection(param_2);
  return (int)piVar2;
}



/* c055f374 FUN_c055f374 */

/* Boundary evidence: original MIPS .pdata c055f374..c055f3d3. Semantic name remains unreviewed. */

undefined4 FUN_c055f374(undefined4 *param_1,LPTHREAD_START_ROUTINE param_2,LPVOID param_3)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  DWORD aDStack_18 [2];
  
  uVar2 = 0;
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,param_2,param_3,0,aDStack_18);
  *param_1 = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    uVar2 = 0xc0000017;
  }
  return uVar2;
}



/* c055f3d4 FUN_c055f3d4 */

/* Boundary evidence: original MIPS .pdata c055f3d4..c055f43b. Semantic name remains unreviewed. */

void * FUN_c055f3d4(undefined4 param_1,undefined4 param_2)

{
  void *_Dst;
  
  _Dst = (void *)CTEAllocMem(0x18);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x18);
    *(undefined4 *)((int)_Dst + 0x10) = param_1;
    *(undefined4 *)((int)_Dst + 4) = param_1;
    *(undefined4 *)((int)_Dst + 8) = param_2;
  }
  return _Dst;
}



/* c055f43c FUN_c055f43c */

/* Boundary evidence: original MIPS .pdata c055f43c..c055f457. Semantic name remains unreviewed. */

void FUN_c055f43c(void)

{
  CTEFreeMem();
  return;
}



/* c055f458 FUN_c055f458 */

/* Boundary evidence: original MIPS .pdata c055f458..c055f49b. Semantic name remains unreviewed. */

void FUN_c055f458(DWORD *param_1)

{
  _FILETIME local_20;
  _SYSTEMTIME _Stack_18;
  
  GetSystemTime(&_Stack_18);
  SystemTimeToFileTime(&_Stack_18,&local_20);
  param_1[1] = local_20.dwHighDateTime;
  *param_1 = local_20.dwLowDateTime;
  return;
}



/* c055f49c FUN_c055f49c */

void FUN_c055f49c(short *param_1,char *param_2)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  
  *(char **)(param_1 + 2) = param_2;
  if (param_2 == (char *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    cVar1 = *param_2;
    pcVar3 = param_2;
    while (cVar1 != '\0') {
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
    sVar2 = (short)pcVar3 - (short)param_2;
    *param_1 = sVar2;
    param_1[1] = sVar2 + 4;
  }
  return;
}



/* c055f4e4 FUN_c055f4e4 */

void FUN_c055f4e4(undefined2 *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  
  *(short **)(param_1 + 2) = param_2;
  if (param_2 != (short *)0x0) {
    sVar1 = *param_2;
    psVar3 = param_2;
    while (sVar1 != 0) {
      psVar3 = psVar3 + 1;
      sVar1 = *psVar3;
    }
    uVar2 = (int)psVar3 - (int)param_2;
    param_1[1] = (short)(uVar2 + 2);
    *param_1 = (short)uVar2;
    if ((uVar2 & 0xffff) <= (uVar2 + 2 & 0xffff)) {
      return;
    }
    *(undefined4 *)(param_1 + 2) = 0;
  }
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



/* c055f53c FUN_c055f53c */

/* Boundary evidence: original MIPS .pdata c055f53c..c055f5cf. Semantic name remains unreviewed. */

bool FUN_c055f53c(undefined2 *param_1,short *param_2)

{
  short sVar1;
  HLOCAL _Dst;
  short *psVar2;
  SIZE_T uBytes;
  
  sVar1 = *param_2;
  psVar2 = param_2;
  while (sVar1 != 0) {
    psVar2 = psVar2 + 1;
    sVar1 = *psVar2;
  }
  uBytes = ((int)psVar2 - (int)param_2 & 0xffffU) + 2;
  *param_1 = (short)((int)psVar2 - (int)param_2);
  param_1[1] = (short)uBytes;
  _Dst = LocalAlloc(0x40,uBytes);
  *(HLOCAL *)(param_1 + 2) = _Dst;
  if (_Dst != (HLOCAL)0x0) {
    memmove(_Dst,param_2,uBytes);
  }
  return _Dst != (HLOCAL)0x0;
}



/* c055f5d0 FUN_c055f5d0 */

/* Boundary evidence: original MIPS .pdata c055f5d0..c055f5f7. Semantic name remains unreviewed. */

void FUN_c055f5d0(int param_1)

{
  if (*(HLOCAL *)(param_1 + 4) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 4));
  }
  return;
}



/* c055f5f8 FUN_c055f5f8 */

/* Boundary evidence: original MIPS .pdata c055f5f8..c055f6d3. Semantic name remains unreviewed. */

undefined4 FUN_c055f5f8(ushort *param_1,ushort *param_2,int param_3)

{
  char cVar1;
  ushort uVar2;
  HLOCAL pvVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  uVar4 = (*param_2 & 0x7fff) * 2;
  *param_1 = (ushort)uVar4;
  uVar8 = 0;
  if (param_3 == 0) {
    uVar2 = param_1[1];
    if (uVar2 <= uVar4) {
      uVar8 = 0x80000005;
      if (uVar2 == 0) {
        return 0x80000005;
      }
      *param_1 = uVar2 - 2;
    }
  }
  else {
    param_1[1] = (ushort)(uVar4 + 2);
    pvVar3 = LocalAlloc(0,uVar4 + 2);
    *(HLOCAL *)(param_1 + 2) = pvVar3;
    if (pvVar3 == (HLOCAL)0x0) {
      return 0xc0000017;
    }
  }
  pcVar7 = *(char **)(param_2 + 2);
  psVar5 = *(short **)(param_1 + 2);
  if (*param_1 != 0) {
    iVar6 = (*param_1 - 1 >> 1) + 1;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      *psVar5 = (short)cVar1;
      iVar6 = iVar6 + -1;
      psVar5 = psVar5 + 1;
    } while (iVar6 != 0);
  }
  *psVar5 = 0;
  return uVar8;
}



/* c055f6d4 FUN_c055f6d4 */

/* Boundary evidence: original MIPS .pdata c055f6d4..c055f79f. Semantic name remains unreviewed. */

undefined4 FUN_c055f6d4(ushort *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  HLOCAL pvVar4;
  SIZE_T uBytes;
  uint uVar5;
  undefined1 *puVar6;
  undefined2 *puVar7;
  undefined4 uVar8;
  
  uVar3 = *param_2 >> 1;
  *param_1 = uVar3;
  uVar8 = 0;
  if (param_3 == 0) {
    uVar1 = param_1[1];
    if ((uint)uVar1 <= (uint)uVar3) {
      uVar8 = 0x80000005;
      if (uVar1 == 0) {
        return 0x80000005;
      }
      *param_1 = uVar1 - 1;
    }
  }
  else {
    uBytes = uVar3 + 1;
    param_1[1] = (ushort)uBytes;
    pvVar4 = LocalAlloc(0,uBytes);
    *(HLOCAL *)(param_1 + 2) = pvVar4;
    if (pvVar4 == (HLOCAL)0x0) {
      return 0xc0000017;
    }
  }
  puVar7 = *(undefined2 **)(param_2 + 2);
  puVar6 = *(undefined1 **)(param_1 + 2);
  for (uVar5 = (uint)*param_1; uVar5 != 0; uVar5 = uVar5 - 1) {
    uVar2 = *puVar7;
    puVar7 = puVar7 + 1;
    *puVar6 = (char)uVar2;
    puVar6 = puVar6 + 1;
  }
  *puVar6 = 0;
  return uVar8;
}



/* c055f7a0 FUN_c055f7a0 */

/* Boundary evidence: original MIPS .pdata c055f7a0..c055f8eb. Semantic name remains unreviewed. */

undefined4 FUN_c055f7a0(ushort *param_1,ushort *param_2,int param_3,int param_4)

{
  HLOCAL pvVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  if (param_3 == 0) {
    if (*param_2 <= *param_1) goto LAB_c055f80c;
  }
  else {
    *param_1 = *param_2;
    uVar2 = *param_2;
    param_1[1] = uVar2 + 2;
    pvVar1 = LocalAlloc(0,(uint)(ushort)(uVar2 + 2));
    *(HLOCAL *)(param_1 + 2) = pvVar1;
    if (pvVar1 != (HLOCAL)0x0) {
LAB_c055f80c:
      puVar4 = *(ushort **)(param_2 + 2);
      uVar3 = (uint)(*param_2 >> 1);
      puVar5 = *(ushort **)(param_1 + 2);
      if (uVar3 != 0) {
        if (param_4 == 0) {
          do {
            uVar2 = *puVar4;
            if ((0x40 < uVar2) && (uVar2 < 0x5b)) {
              uVar2 = uVar2 + 0x20;
            }
            *puVar5 = uVar2;
            puVar4 = puVar4 + 1;
            uVar3 = uVar3 - 1;
            puVar5 = puVar5 + 1;
          } while (uVar3 != 0);
        }
        else {
          do {
            uVar2 = *puVar4;
            if ((0x60 < uVar2) && (uVar2 < 0x7b)) {
              uVar2 = uVar2 - 0x20;
            }
            *puVar5 = uVar2;
            puVar4 = puVar4 + 1;
            uVar3 = uVar3 - 1;
            puVar5 = puVar5 + 1;
          } while (uVar3 != 0);
        }
      }
      if ((*param_2 < param_2[1]) && (1 < (uint)param_1[1] - (uint)*param_1)) {
        *puVar5 = 0;
      }
      return 0;
    }
  }
  return 0xc0000017;
}



/* c055f8ec FUN_c055f8ec */

/* Boundary evidence: original MIPS .pdata c055f8ec..c055f907. Semantic name remains unreviewed. */

void FUN_c055f8ec(ushort *param_1,ushort *param_2,int param_3)

{
  FUN_c055f7a0(param_1,param_2,param_3,1);
  return;
}



/* c055f908 FUN_c055f908 */

bool FUN_c055f908(ushort *param_1,ushort *param_2,int param_3)

{
  ushort *puVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint uVar8;
  
  uVar2 = (uint)*param_1;
  uVar5 = (uint)*param_2;
  puVar6 = *(ushort **)(param_1 + 2);
  puVar1 = *(ushort **)(param_2 + 2);
  uVar8 = uVar2;
  if (uVar5 < uVar2) {
    uVar8 = uVar5;
  }
  puVar7 = (ushort *)(uVar8 + (int)puVar6);
  if (puVar6 < puVar7) {
    if (param_3 == 0) {
      do {
        uVar3 = *puVar6;
        uVar4 = *puVar1;
        puVar6 = puVar6 + 1;
        puVar1 = puVar1 + 1;
        if (uVar3 != uVar4) {
          return false;
        }
      } while (puVar6 < puVar7);
    }
    else {
      do {
        uVar3 = *puVar6;
        uVar4 = *puVar1;
        puVar6 = puVar6 + 1;
        puVar1 = puVar1 + 1;
        if (uVar3 != uVar4) {
          if ((0x60 < uVar3) && (uVar3 < 0x7b)) {
            uVar3 = uVar3 - 0x20;
          }
          if ((0x60 < uVar4) && (uVar4 < 0x7b)) {
            uVar4 = uVar4 - 0x20;
          }
          if (uVar3 != uVar4) {
            return false;
          }
        }
      } while (puVar6 < puVar7);
    }
  }
  return uVar2 == uVar5;
}



/* c055fa0c FUN_c055fa0c */

undefined4 FUN_c055fa0c(ushort *param_1,short *param_2)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  
  if (param_2 != (short *)0x0) {
    sVar1 = *param_2;
    psVar4 = param_2;
    while (sVar1 != 0) {
      psVar4 = psVar4 + 1;
      sVar1 = *psVar4;
    }
    uVar3 = (int)psVar4 - (int)param_2 & 0xffff;
    if ((uint)param_1[1] < *param_1 + uVar3) {
      return 0xc0000023;
    }
    psVar5 = (short *)(uVar3 + (int)param_2);
    psVar4 = (short *)((uint)(*param_1 >> 1) * 2 + *(int *)(param_1 + 2));
    for (; param_2 < psVar5; param_2 = param_2 + 1) {
      *psVar4 = *param_2;
      psVar4 = psVar4 + 1;
    }
    uVar2 = *param_1;
    *param_1 = (ushort)(uVar2 + uVar3);
    if ((uVar2 + uVar3 & 0xffff) < (uint)param_1[1]) {
      *psVar4 = 0;
    }
  }
  return 0;
}



/* c055fac4 FUN_c055fac4 */

undefined4 FUN_c055fac4(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  uVar2 = (uint)*param_2;
  if (uVar2 != 0) {
    if ((uint)param_1[1] < *param_1 + uVar2) {
      return 0xc0000023;
    }
    puVar3 = *(undefined2 **)(param_2 + 2);
    puVar5 = (undefined2 *)(uVar2 + (int)puVar3);
    puVar4 = (undefined2 *)((uint)(*param_1 >> 1) * 2 + *(int *)(param_1 + 2));
    for (; puVar3 < puVar5; puVar3 = puVar3 + 1) {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
    uVar1 = *param_1;
    *param_1 = (ushort)(uVar1 + uVar2);
    if ((uVar1 + uVar2 & 0xffff) < (uint)param_1[1]) {
      *puVar4 = 0;
    }
  }
  return 0;
}



/* c055fb64 FUN_c055fb64 */

/* Boundary evidence: original MIPS .pdata c055fb64..c055fb9b. Semantic name remains unreviewed. */

undefined4 FUN_c055fb64(int param_1,int param_2,long *param_3)

{
  long lVar1;
  
  lVar1 = wcstol(*(wchar_t **)(param_1 + 4),(wchar_t **)0x0,param_2);
  *param_3 = lVar1;
  return 0;
}



/* c055fb9c FUN_c055fb9c */

/* Boundary evidence: original MIPS .pdata c055fb9c..c055fbcf. Semantic name remains unreviewed. */

undefined4 FUN_c055fb9c(char *param_1,int param_2,long *param_3)

{
  long lVar1;
  
  lVar1 = strtol(param_1,(char **)0x0,param_2);
  *param_3 = lVar1;
  return 0;
}



/* c055fbd0 FUN_c055fbd0 */

/* Boundary evidence: original MIPS .pdata c055fbd0..c055fd23. Semantic name remains unreviewed. */

undefined4 FUN_c055fbd0(int *param_1,int param_2,ushort *param_3,undefined4 *param_4)

{
  undefined4 *hMem;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0xc0000017;
  iVar1 = 0;
  if (param_3 != (ushort *)0x0) {
    iVar1 = *param_3 + 2;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565800);
  uVar2 = (iVar1 + 8U & 0xfffffff8) + 0x28;
  if ((0x27 < uVar2) && (uVar2 <= uVar2 + param_2)) {
    hMem = LocalAlloc(0x40,uVar2 + param_2);
    if (hMem == (undefined4 *)0x0) goto LAB_c055fce8;
    iVar1 = FUN_c056132c(param_1);
    if (iVar1 == 0) {
      hMem[2] = param_1;
      hMem[1] = 0;
      if (param_3 != (ushort *)0x0) {
        hMem[1] = hMem + 8;
        wcscpy((wchar_t *)(hMem + 8),*(wchar_t **)(param_3 + 2));
      }
      hMem[3] = 0xffffffff;
      hMem[4] = 0xffffffff;
      hMem[5] = uVar2 + (int)hMem;
      hMem[6] = param_2;
      *hMem = DAT_c05657e8;
      uVar3 = 0;
      DAT_c05657e8 = hMem;
      goto LAB_c055fce8;
    }
    LocalFree(hMem);
  }
  hMem = (undefined4 *)0x0;
  uVar3 = 0xc000000d;
LAB_c055fce8:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565800);
  *param_4 = hMem;
  return uVar3;
}



/* c055fd24 FUN_c055fd24 */

/* Boundary evidence: original MIPS .pdata c055fd24..c055fddb. Semantic name remains unreviewed. */

undefined4 FUN_c055fd24(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0xc000000d;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565800);
  piVar1 = &DAT_c05657e8;
  do {
    piVar2 = piVar1;
    if (*piVar2 == 0) goto LAB_c055fdb8;
    piVar1 = (int *)*piVar2;
  } while ((int *)*piVar2 != param_1);
  *piVar2 = *(int *)*piVar2;
  FUN_c05613c8((int *)param_1[2]);
  if (param_1[7] != 0) {
    CloseBusAccessHandle();
  }
  LocalFree(param_1);
  uVar3 = 0;
LAB_c055fdb8:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565800);
  return uVar3;
}



/* c055fddc FUN_c055fddc */

/* Boundary evidence: original MIPS .pdata c055fddc..c055ff17. Semantic name remains unreviewed. */

LPBYTE FUN_c055fddc(HKEY param_1,undefined4 param_2)

{
  LSTATUS LVar1;
  LPBYTE lpData;
  HKEY local_228;
  SIZE_T local_224;
  DWORD local_220 [2];
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_c05653c8;
  lpData = (LPBYTE)0x0;
  StringCchPrintfW(awStack_218,0x100,L"%s\\Linkage",param_2);
  LVar1 = RegOpenKeyExW(param_1,awStack_218,0,0x20019,&local_228);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_228,L"Route",(LPDWORD)0x0,local_220,(LPBYTE)0x0,&local_224);
    if (((LVar1 == 0) && (local_220[0] == 7)) &&
       (lpData = LocalAlloc(0x40,local_224), lpData != (LPBYTE)0x0)) {
      LVar1 = RegQueryValueExW(local_228,L"Route",(LPDWORD)0x0,(LPDWORD)0x0,lpData,&local_224);
      if (LVar1 != 0) {
        LocalFree(lpData);
        lpData = (LPBYTE)0x0;
      }
    }
    RegCloseKey(local_228);
  }
  FUN_c05625b0(local_18);
  return lpData;
}



/* c055ff18 FUN_c055ff18 */

/* Boundary evidence: original MIPS .pdata c055ff18..c055ffd3. Semantic name remains unreviewed. */

undefined4 FUN_c055ff18(undefined4 param_1,undefined4 param_2,LPBYTE param_3,LPBYTE param_4)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_c05653c8;
  uVar2 = 0xc0000001;
  StringCchPrintfW(awStack_218,0x100,L"%s\\%s\\Parms",param_1,param_2);
  iVar1 = FUN_c0560594((HKEY)0x80000002,awStack_218,L"BusType",param_3);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_c0560594((HKEY)0x80000002,awStack_218,L"BusNumber",param_4), iVar1 != 0)) {
    uVar2 = 0;
  }
  FUN_c05625b0(local_18);
  return uVar2;
}



/* c055ffd4 FUN_c055ffd4 */

/* Boundary evidence: original MIPS .pdata c055ffd4..c0560093. Semantic name remains unreviewed. */

int FUN_c055ffd4(int *param_1,short *param_2,int param_3,int param_4,undefined *param_5,
                undefined4 *param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  int *local_28 [2];
  ushort auStack_20 [4];
  
  local_28[0] = (int *)0x0;
  FUN_c055f4e4(auStack_20,param_2);
  iVar1 = FUN_c055fbd0(param_1,0,auStack_20,local_28);
  piVar2 = local_28[0];
  if (iVar1 == 0) {
    local_28[0][3] = param_3;
    local_28[0][4] = param_4;
    iVar1 = (*(code *)param_5)(param_1,auStack_20,local_28[0],0,param_7);
    if (iVar1 != 0) {
      FUN_c055fd24(piVar2);
      piVar2 = (int *)0x0;
    }
  }
  *param_6 = piVar2;
  return iVar1;
}



/* c0560094 FUN_c0560094 */

/* Boundary evidence: original MIPS .pdata c0560094..c056011f. Semantic name remains unreviewed. */

int FUN_c0560094(undefined4 param_1,short *param_2,wchar_t *param_3,short *param_4,int param_5,
                int param_6,undefined *param_7,undefined4 *param_8,undefined4 param_9)

{
  int *piVar1;
  int iVar2;
  
  *param_8 = 0;
  piVar1 = FUN_c0560fcc(param_1,param_2,param_3);
  if (piVar1 == (int *)0x0) {
    iVar2 = -0x3fffffff;
  }
  else {
    iVar2 = FUN_c055ffd4(piVar1,param_4,param_5,param_6,param_7,param_8,param_9);
    FUN_c05613c8(piVar1);
  }
  return iVar2;
}



/* c0560120 FUN_c0560120 */

/* Boundary evidence: original MIPS .pdata c0560120..c05601df. Semantic name remains unreviewed. */

int FUN_c0560120(undefined4 param_1,short *param_2,wchar_t *param_3,short *param_4,
                undefined *param_5)

{
  int iVar1;
  int local_28;
  int local_24;
  undefined4 auStack_20 [2];
  
  iVar1 = FUN_c055ff18(param_1,param_4,(LPBYTE)&local_28,(LPBYTE)&local_24);
  if (iVar1 == 0) {
    if ((local_28 == 8) || (local_28 == 0xf)) {
      iVar1 = -0x3ffffff3;
    }
    else {
      iVar1 = FUN_c0560094(param_1,param_2,param_3,param_4,local_28,local_24,param_5,auStack_20,0);
    }
  }
  return iVar1;
}



/* c05601e0 FUN_c05601e0 */

/* Boundary evidence: original MIPS .pdata c05601e0..c0560293. Semantic name remains unreviewed. */

undefined4
FUN_c05601e0(HKEY param_1,undefined4 param_2,LPCWSTR param_3,wchar_t *param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_20 [2];
  
  uVar3 = 0xc0000001;
  piVar2 = (int *)0x0;
  iVar1 = FUN_c0560594(param_1,param_3,L"NoDeviceCreate",(LPBYTE)local_20);
  if (((iVar1 != 0) && (local_20[0] == 1)) &&
     (piVar2 = FUN_c0560fcc(param_2,param_3,param_4), piVar2 != (int *)0x0)) {
    uVar3 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = piVar2;
  }
  return uVar3;
}



/* c0560294 FUN_c0560294 */

/* Boundary evidence: original MIPS .pdata c0560294..c0560447. Semantic name remains unreviewed. */

void FUN_c0560294(LPCWSTR param_1,wchar_t *param_2,undefined *param_3)

{
  wchar_t wVar1;
  LSTATUS LVar2;
  int iVar3;
  wchar_t *hMem;
  size_t sVar4;
  wchar_t *_Str;
  DWORD dwIndex;
  HKEY local_138;
  DWORD local_134;
  WCHAR aWStack_130 [128];
  uint local_30;
  
  local_30 = DAT_c05653c8;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0x20019,&local_138);
  if (LVar2 == 0) {
    dwIndex = 0;
    local_134 = 0x80;
    iVar3 = RegEnumKeyExW(local_138,0,aWStack_130,&local_134,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          (PFILETIME)0x0);
    while (iVar3 == 0) {
      iVar3 = FUN_c05601e0(local_138,param_1,aWStack_130,param_2,(undefined4 *)0x0);
      if ((iVar3 != 0) &&
         (hMem = (wchar_t *)FUN_c055fddc(local_138,aWStack_130), hMem != (wchar_t *)0x0)) {
        wVar1 = *hMem;
        _Str = hMem;
        while (wVar1 != L'\0') {
          FUN_c0560120(param_1,aWStack_130,param_2,_Str,param_3);
          sVar4 = wcslen(_Str);
          _Str = _Str + sVar4 + 1;
          wVar1 = *_Str;
        }
        LocalFree(hMem);
      }
      dwIndex = dwIndex + 1;
      local_134 = 0x80;
      iVar3 = RegEnumKeyExW(local_138,dwIndex,aWStack_130,&local_134,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
    }
    RegCloseKey(local_138);
  }
  FUN_c05625b0(local_30);
  return;
}



/* c0560448 FUN_c0560448 */

/* Boundary evidence: original MIPS .pdata c0560448..c0560467. Semantic name remains unreviewed. */

void FUN_c0560448(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0565800);
  return;
}



/* c0560468 FUN_c0560468 */

/* Boundary evidence: original MIPS .pdata c0560468..c0560543. Semantic name remains unreviewed. */

undefined4
FUN_c0560468(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,LPBYTE param_4,undefined4 param_5,
            DWORD param_6)

{
  LSTATUS LVar1;
  HKEY local_res0 [4];
  DWORD local_18 [2];
  
  local_res0[0] = param_1;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar1 = RegOpenKeyExW(param_1,param_2,0,0x20019,local_res0), LVar1 == 0)) {
    LVar1 = RegQueryValueExW(local_res0[0],param_3,(LPDWORD)0x0,local_18,param_4,&param_5);
    if ((LVar1 == 0) && (local_18[0] != param_6)) {
      LVar1 = 1;
    }
    if (param_2 != (LPCWSTR)0x0) {
      RegCloseKey(local_res0[0]);
    }
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c0560544 FUN_c0560544 */

/* Boundary evidence: original MIPS .pdata c0560544..c056056b. Semantic name remains unreviewed. */

void FUN_c0560544(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,LPBYTE param_4,undefined4 param_5)

{
  FUN_c0560468(param_1,param_2,param_3,param_4,param_5,1);
  return;
}



/* c056056c FUN_c056056c */

/* Boundary evidence: original MIPS .pdata c056056c..c0560593. Semantic name remains unreviewed. */

void FUN_c056056c(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,LPBYTE param_4,undefined4 param_5)

{
  FUN_c0560468(param_1,param_2,param_3,param_4,param_5,7);
  return;
}



/* c0560594 FUN_c0560594 */

/* Boundary evidence: original MIPS .pdata c0560594..c05605b7. Semantic name remains unreviewed. */

void FUN_c0560594(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,LPBYTE param_4)

{
  FUN_c0560468(param_1,param_2,param_3,param_4,4,4);
  return;
}



/* c05605b8 FUN_c05605b8 */

/* Boundary evidence: original MIPS .pdata c05605b8..c056067f. Semantic name remains unreviewed. */

undefined4 FUN_c05605b8(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  HKEY local_res0 [3];
  undefined4 local_resc;
  
  local_res0[0] = param_1;
  local_resc = param_4;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                              local_res0,(LPDWORD)0x0), LVar1 == 0)) {
    LVar1 = RegSetValueExW(local_res0[0],param_3,0,4,(BYTE *)&local_resc,4);
    if (param_2 != (LPCWSTR)0x0) {
      RegCloseKey(local_res0[0]);
    }
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c0560680 FUN_c0560680 */

/* Boundary evidence: original MIPS .pdata c0560680..c05609af. Semantic name remains unreviewed. */

int FUN_c0560680(HKEY param_1,LPCWSTR param_2,undefined *param_3,undefined *param_4)

{
  code *pcVar1;
  LSTATUS LVar2;
  LPBYTE lpData;
  uint *puVar3;
  int iVar4;
  DWORD DVar5;
  undefined4 *puVar6;
  uint uVar7;
  LPCWSTR lpValueName;
  LPCWSTR pWVar8;
  HKEY local_res0 [3];
  undefined *local_resc;
  DWORD local_40;
  uint local_3c;
  code *local_38;
  DWORD local_34;
  code *local_30;
  LPCWSTR local_2c;
  
  iVar4 = 0;
  local_res0[0] = param_1;
  local_resc = param_4;
  local_38 = (code *)param_4;
  local_30 = (code *)param_3;
  local_2c = param_2;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar2 = RegOpenKeyExW(param_1,param_2,0,0x20019,local_res0), LVar2 == 0)) {
    pcVar1 = local_38;
    puVar6 = (undefined4 *)&stack0x00000010;
    pWVar8 = local_2c;
    while (lpValueName = (LPCWSTR)*puVar6, lpValueName != (LPCWSTR)0x0) {
      DVar5 = puVar6[1];
      puVar3 = (uint *)0x0;
      uVar7 = puVar6[2] & 1;
      if (uVar7 == 0) {
        lpData = (LPBYTE)puVar6[3];
        if (DVar5 == 3) {
          puVar3 = (uint *)puVar6[4];
          local_40 = *puVar3;
        }
        else {
          local_40 = puVar6[4];
        }
      }
      else {
        local_40 = 0;
        pWVar8 = (LPCWSTR)puVar6[3];
        puVar3 = (uint *)puVar6[4];
        lpData = (LPBYTE)0x0;
      }
      puVar6 = puVar6 + 5;
      LVar2 = RegQueryValueExW(local_res0[0],lpValueName,(LPDWORD)0x0,&local_34,(LPBYTE)0x0,
                               &local_3c);
      if (((LVar2 == 0) || (LVar2 == 0xea)) && (local_34 == DVar5)) {
        if (uVar7 == 0) {
          if ((local_40 < local_3c) || (lpData == (LPBYTE)0x0)) {
            if (DVar5 == 3) {
              *puVar3 = local_3c;
            }
            lpData = (LPBYTE)0x0;
            DVar5 = 0x7a;
            goto LAB_c0560920;
          }
        }
        else {
          lpData = (LPBYTE)(*local_30)(local_3c);
          if (lpData == (LPBYTE)0x0) {
            DVar5 = 0xe;
LAB_c0560920:
            SetLastError(DVar5);
            goto LAB_c0560934;
          }
        }
        LVar2 = RegQueryValueExW(local_res0[0],lpValueName,(LPDWORD)0x0,(LPDWORD)0x0,lpData,
                                 &local_40);
        if (LVar2 == 0) {
          iVar4 = iVar4 + 1;
          if (DVar5 == 3) {
            *puVar3 = local_40;
          }
        }
        else if (uVar7 != 0) {
          (*pcVar1)(lpData,local_3c);
          lpData = (LPBYTE)0x0;
          local_40 = 0;
        }
      }
LAB_c0560934:
      if (uVar7 != 0) {
        if (pWVar8 != (LPCWSTR)0x0) {
          *(LPBYTE *)pWVar8 = lpData;
        }
        if (puVar3 != (uint *)0x0) {
          *puVar3 = local_40;
        }
      }
    }
    if (local_2c != (LPCWSTR)0x0) {
      RegCloseKey(local_res0[0]);
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}



/* c05609b0 FUN_c05609b0 */

void FUN_c05609b0(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  puVar3 = DAT_c05657d8;
  while( true ) {
    if ((undefined4 **)puVar3 == &DAT_c05657d8) {
      *param_1 = (int)&DAT_c05657d8;
      param_1[1] = (int)DAT_c05657dc;
      *DAT_c05657dc = (int)param_1;
      DAT_c05657dc = param_1;
      return;
    }
    if ((uint)param_1[5] <= (uint)puVar3[5]) break;
    param_1[5] = param_1[5] - puVar3[5];
    puVar3 = (undefined4 *)*puVar3;
  }
  piVar2 = (int *)puVar3[1];
  iVar1 = *piVar2;
  *param_1 = iVar1;
  param_1[1] = (int)piVar2;
  *(int **)(iVar1 + 4) = param_1;
  *piVar2 = (int)param_1;
  puVar3[5] = puVar3[5] - param_1[5];
  return;
}



/* c0560a34 FUN_c0560a34 */

/* Boundary evidence: original MIPS .pdata c0560a34..c0560bd7. Semantic name remains unreviewed. */

undefined4 FUN_c0560a34(void)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  DWORD DVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  
  pcVar3 = DAT_c05654ac;
  do {
    DAT_c05654ac = pcVar3;
    if (DAT_c05654a0 == '\0') {
      return 0;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657c0);
    DVar4 = GetTickCount();
    uVar7 = DVar4 - DAT_c05654a4;
    DAT_c05654a4 = DVar4;
    while (piVar2 = DAT_c05657d8, (int **)DAT_c05657d8 != &DAT_c05657d8) {
      if (uVar7 < (uint)DAT_c05657d8[5]) {
        DVar4 = DAT_c05657d8[5] - uVar7;
        DAT_c05657d8[5] = DVar4;
        goto LAB_c0560b4c;
      }
      *(int ***)(*DAT_c05657d8 + 4) = &DAT_c05657d8;
      piVar5 = (int *)*DAT_c05657d8;
      uVar6 = DAT_c05657d8[6];
      uVar7 = uVar7 - DAT_c05657d8[5];
      if (uVar6 != 0) {
        if (uVar7 < uVar6) {
          piVar1 = DAT_c05657d8 + 5;
          DAT_c05657d8 = piVar5;
          *piVar1 = uVar6 - uVar7;
        }
        else {
          piVar1 = DAT_c05657d8 + 5;
          DAT_c05657d8 = piVar5;
          *piVar1 = uVar7 + 1;
        }
        FUN_c05609b0(piVar2);
        piVar5 = DAT_c05657d8;
      }
      DAT_c05657d8 = piVar5;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657c0);
      if (DAT_c05654a8 != (LPCRITICAL_SECTION)0x0) {
        FUN_c05614a0(DAT_c05654a8,piVar2[2]);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657c0);
    }
    DVar4 = 0xffffffff;
LAB_c0560b4c:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657c0);
    WaitForSingleObject(DAT_c05657e4,DVar4);
    pcVar3 = (code *)0x0;
    if (DAT_c05654ac != (code *)0x0) {
      (*DAT_c05654ac)();
      DAT_c05654ac = (code *)0x0;
      pcVar3 = DAT_c05654ac;
    }
  } while( true );
}



/* c0560bd8 FUN_c0560bd8 */

/* Boundary evidence: original MIPS .pdata c0560bd8..c0560c8f. Semantic name remains unreviewed. */

undefined4 FUN_c0560bd8(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657c0);
  piVar2 = DAT_c05657d8;
  if ((int **)DAT_c05657d8 != &DAT_c05657d8) {
    do {
      if (piVar2 == param_1) {
        puVar1 = (undefined4 *)*piVar2;
        if ((int **)puVar1 != &DAT_c05657d8) {
          puVar1[5] = piVar2[5] + puVar1[5];
        }
        uVar3 = 1;
        *(int *)piVar2[1] = *piVar2;
        *(int *)(*piVar2 + 4) = piVar2[1];
        break;
      }
      piVar2 = (int *)*piVar2;
    } while ((int **)piVar2 != &DAT_c05657d8);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657c0);
  return uVar3;
}



/* c0560c90 FUN_c0560c90 */

/* Boundary evidence: original MIPS .pdata c0560c90..c0560ccb. Semantic name remains unreviewed. */

void FUN_c0560c90(int *param_1)

{
  FUN_c0560bd8(param_1);
  param_1[5] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[6] = 0;
  return;
}



/* c0560ccc FUN_c0560ccc */

/* Boundary evidence: original MIPS .pdata c0560ccc..c0560db3. Semantic name remains unreviewed. */

void FUN_c0560ccc(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  DWORD DVar2;
  uint uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657c0);
  FUN_c0560bd8(param_1);
  param_1[5] = param_3;
  param_1[6] = param_4;
  param_1[2] = param_2;
  DVar2 = GetTickCount();
  puVar1 = DAT_c05657d8;
  uVar3 = DVar2 - DAT_c05654a4;
  DAT_c05654a4 = DVar2;
  if ((undefined4 **)DAT_c05657d8 != &DAT_c05657d8) {
    if (uVar3 < (uint)DAT_c05657d8[5]) {
      DAT_c05657d8[5] = DAT_c05657d8[5] - uVar3;
    }
    else {
      DAT_c05657d8[5] = 0;
    }
  }
  FUN_c05609b0(param_1);
  if (DAT_c05657d8 != puVar1) {
    EventModify(DAT_c05657e4,3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657c0);
  return;
}



/* c0560db4 FUN_c0560db4 */

/* Boundary evidence: original MIPS .pdata c0560db4..c0560ddb. Semantic name remains unreviewed. */

void FUN_c0560db4(int *param_1,int param_2,int param_3)

{
  FUN_c0560ccc(param_1,param_3,param_2,0);
  return;
}



/* c0560ddc FUN_c0560ddc */

/* Boundary evidence: original MIPS .pdata c0560ddc..c0560e03. Semantic name remains unreviewed. */

void FUN_c0560ddc(int *param_1,int param_2,int param_3)

{
  FUN_c0560ccc(param_1,param_3,param_2,param_2);
  return;
}



/* c0560e04 FUN_c0560e04 */

/* Boundary evidence: original MIPS .pdata c0560e04..c0560f07. Semantic name remains unreviewed. */

undefined4 FUN_c0560e04(undefined4 param_1,undefined4 param_2)

{
  DWORD aDStack_18 [2];
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05657c0);
  DAT_c05657dc = &DAT_c05657d8;
  DAT_c05657d8 = &DAT_c05657d8;
  DAT_c05657e4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_c05654a4 = GetTickCount();
  if (DAT_c05657e4 != (HANDLE)0x0) {
    DAT_c05654a0 = 1;
    DAT_c05654a8 = param_1;
    DAT_c05657e0 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0560a34,(LPVOID)0x0,0,aDStack_18);
    if (DAT_c05657e0 != (HANDLE)0x0) {
      CeSetThreadPriority(DAT_c05657e0,param_2);
      return 0;
    }
    CloseHandle(DAT_c05657e4);
  }
  return 0xe;
}



/* c0560f08 FUN_c0560f08 */

/* Boundary evidence: original MIPS .pdata c0560f08..c0560f33. Semantic name remains unreviewed. */

void FUN_c0560f08(undefined4 param_1)

{
  DAT_c05654ac = param_1;
  EventModify(DAT_c05657e4,3);
  return;
}



/* c0560f34 FUN_c0560f34 */

/* Boundary evidence: original MIPS .pdata c0560f34..c0560fcb. Semantic name remains unreviewed. */

int FUN_c0560f34(short *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  ushort auStack_18 [4];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
  FUN_c055f4e4(auStack_18,param_1);
  piVar2 = (int *)DAT_c05657b4;
  do {
    if (piVar2 == (int *)0x0) {
LAB_c0560fac:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
      return (int)piVar2;
    }
    bVar1 = FUN_c055f908((ushort *)(piVar2 + 2),auStack_18,1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      piVar2[8] = piVar2[8] + 1;
      goto LAB_c0560fac;
    }
    piVar2 = (int *)*piVar2;
  } while( true );
}



/* c0560fcc FUN_c0560fcc */

/* Boundary evidence: original MIPS .pdata c0560fcc..c0561213. Semantic name remains unreviewed. */

int * FUN_c0560fcc(undefined4 param_1,short *param_2,wchar_t *param_3)

{
  bool bVar1;
  int *_Dst;
  int iVar2;
  HMODULE pHVar3;
  code *pcVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  wchar_t awStack_1c0 [12];
  wchar_t awStack_1a8 [64];
  WCHAR aWStack_128 [128];
  uint local_28;
  
  local_28 = DAT_c05653c8;
  _Dst = (int *)FUN_c0560f34(param_2);
  if (_Dst == (int *)0x0) {
    StringCchPrintfW(awStack_1a8,0x40,L"%s\\%s",param_1,param_2);
    iVar2 = FUN_c0560544((HKEY)0x80000002,awStack_1a8,L"Group",(LPBYTE)awStack_1c0,0x14);
    if ((((iVar2 != 0) &&
         (iVar2 = FUN_c0560544((HKEY)0x80000002,awStack_1a8,L"ImagePath",(LPBYTE)aWStack_128,0x100),
         iVar2 != 0)) && (iVar2 = _wcsicmp(awStack_1c0,param_3), iVar2 == 0)) &&
       (_Dst = LocalAlloc(0x40,0x28), _Dst != (int *)0x0)) {
      memset(_Dst,0,0x28);
      _Dst[8] = 1;
      pHVar3 = LoadLibraryW(aWStack_128);
      _Dst[1] = (int)pHVar3;
      if (pHVar3 != (HMODULE)0x0) {
        pcVar4 = (code *)GetProcAddressW(pHVar3,L"DriverEntry");
        if (pcVar4 != (code *)0x0) {
          bVar1 = FUN_c055f53c((undefined2 *)(_Dst + 2),param_2);
          if (CONCAT31(extraout_var,bVar1) != 0) {
            piVar7 = _Dst + 4;
            bVar1 = FUN_c055f53c((undefined2 *)piVar7,awStack_1a8);
            if (CONCAT31(extraout_var_00,bVar1) != 0) {
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
              *_Dst = (int)DAT_c05657b4;
              DAT_c05657b4 = _Dst;
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
              iVar2 = (*pcVar4)(_Dst,piVar7);
              if (iVar2 == 0) goto LAB_c05611e4;
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
              piVar5 = (int *)&DAT_c05657b4;
              do {
                piVar6 = piVar5;
                piVar5 = (int *)*piVar6;
                if (piVar5 == (int *)0x0) break;
              } while (piVar5 != _Dst);
              if (*piVar6 != 0) {
                *piVar6 = *_Dst;
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
              FUN_c055f5d0((int)piVar7);
            }
            FUN_c055f5d0((int)(_Dst + 2));
          }
        }
        FreeLibrary((HMODULE)_Dst[1]);
      }
      LocalFree(_Dst);
      _Dst = (int *)0x0;
    }
  }
LAB_c05611e4:
  FUN_c05625b0(local_28);
  return _Dst;
}



/* c0561214 FUN_c0561214 */

/* Boundary evidence: original MIPS .pdata c0561214..c05612ab. Semantic name remains unreviewed. */

void FUN_c0561214(undefined4 *param_1)

{
  undefined4 *hMem;
  
  hMem = (undefined4 *)*param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
  if ((code *)hMem[9] != (code *)0x0) {
    (*(code *)hMem[9])(hMem);
  }
  *param_1 = *hMem;
  LocalFree((HLOCAL)hMem[6]);
  FUN_c055f5d0((int)(hMem + 2));
  FUN_c055f5d0((int)(hMem + 4));
  FreeLibrary((HMODULE)hMem[1]);
  LocalFree(hMem);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
  return;
}



/* c05612ac FUN_c05612ac */

/* Boundary evidence: original MIPS .pdata c05612ac..c0561323. Semantic name remains unreviewed. */

undefined4 FUN_c05612ac(int param_1,undefined4 param_2,SIZE_T param_3,undefined4 *param_4)

{
  HLOCAL pvVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000001;
  if (*(int *)(param_1 + 0x18) == 0) {
    pvVar1 = LocalAlloc(0x40,param_3);
    *(HLOCAL *)(param_1 + 0x18) = pvVar1;
    if (pvVar1 != (HLOCAL)0x0) {
      *(SIZE_T *)(param_1 + 0x1c) = param_3;
      uVar2 = 0;
    }
  }
  *param_4 = *(undefined4 *)(param_1 + 0x18);
  return uVar2;
}



/* c0561324 FUN_c0561324 */

undefined4 FUN_c0561324(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



/* c056132c FUN_c056132c */

/* Boundary evidence: original MIPS .pdata c056132c..c05613c7. Semantic name remains unreviewed. */

undefined4 FUN_c056132c(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0xc000000d;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
  piVar1 = DAT_c05657b4;
  piVar3 = (int *)&DAT_c05657b4;
  if (DAT_c05657b4 != (int *)0x0) {
    do {
      piVar2 = piVar1;
      if (piVar2 == param_1) break;
      piVar1 = (int *)*piVar2;
      piVar3 = piVar2;
    } while ((int *)*piVar2 != (int *)0x0);
    if (*piVar3 != 0) {
      uVar4 = 0;
      param_1[8] = param_1[8] + 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
  return uVar4;
}



/* c05613c8 FUN_c05613c8 */

/* Boundary evidence: original MIPS .pdata c05613c8..c0561473. Semantic name remains unreviewed. */

undefined4 FUN_c05613c8(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0xc000000d;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
  piVar2 = &DAT_c05657b4;
  do {
    piVar1 = piVar2;
    piVar2 = (int *)*piVar1;
    if (piVar2 == (int *)0x0) break;
  } while (piVar2 != param_1);
  if (*piVar1 != 0) {
    uVar3 = 0;
    if (0 < param_1[8]) {
      param_1[8] = param_1[8] + -1;
    }
    if (param_1[8] == 0) {
      FUN_c0561214(piVar1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
  return uVar3;
}



/* c0561474 FUN_c0561474 */

/* Boundary evidence: original MIPS .pdata c0561474..c0561493. Semantic name remains unreviewed. */

void FUN_c0561474(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05657a0);
  return;
}



/* c0561494 FUN_c0561494 */

void FUN_c0561494(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  return;
}



/* c05614a0 FUN_c05614a0 */

/* Boundary evidence: original MIPS .pdata c05614a0..c05614bb. Semantic name remains unreviewed. */

void FUN_c05614a0(LPCRITICAL_SECTION param_1,int param_2)

{
  FUN_c055f0e8(param_1,(LPCRITICAL_SECTION)(param_2 + 4));
  return;
}



/* c05614bc FUN_c05614bc */

/* Boundary evidence: original MIPS .pdata c05614bc..c0561517. Semantic name remains unreviewed. */

undefined4 FUN_c05614bc(LPCRITICAL_SECTION param_1)

{
  PRTL_CRITICAL_SECTION_DEBUG p_Var1;
  
  while (p_Var1 = FUN_c055f180(param_1), p_Var1 != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    (*(code *)(p_Var1->ProcessLocksList).Flink)
              (&p_Var1[-1].CreatorBackTraceIndexHigh,(p_Var1->ProcessLocksList).Blink,
               p_Var1->EntryCount,p_Var1->ContentionCount);
  }
  return 0;
}



/* c0561518 FUN_c0561518 */

/* Boundary evidence: original MIPS .pdata c0561518..c0561597. Semantic name remains unreviewed. */

HANDLE FUN_c0561518(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  HANDLE pvVar1;
  DWORD aDStack_18 [2];
  
  FUN_c055f094(param_1);
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05614bc,param_1,0,aDStack_18);
  if (pvVar1 != (HANDLE)0x0) {
    CeSetThreadPriority(pvVar1,param_2);
  }
  return pvVar1;
}



/* c0561598 FUN_c0561598 */

/* Boundary evidence: original MIPS .pdata c0561598..c05615ef. Semantic name remains unreviewed. */

void FUN_c0561598(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565780);
  *DAT_c0565794 = *(undefined4 *)(param_1 + 0x18);
  InterruptDone(0xe);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565780);
  return;
}



/* c05615f0 FUN_c05615f0 */

/* Boundary evidence: original MIPS .pdata c05615f0..c0561647. Semantic name remains unreviewed. */

void FUN_c05615f0(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565780);
  *DAT_c0565794 = *(undefined4 *)(param_1 + 0x18);
  InterruptDisable(0xe);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565780);
  return;
}



/* c0561648 FUN_c0561648 */

/* Boundary evidence: original MIPS .pdata c0561648..c05616af. Semantic name remains unreviewed. */

void FUN_c0561648(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0565780);
  *DAT_c0565794 = *(undefined4 *)(param_1 + 0x18);
  InterruptMask(0xe,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0565780);
  return;
}



/* c05616b0 FUN_c05616b0 */

/* Boundary evidence: original MIPS .pdata c05616b0..c0561737. Semantic name remains unreviewed. */

undefined4 FUN_c05616b0(undefined *param_1)

{
  HANDLE hHandle;
  LONG *Target;
  LONG LVar1;
  DWORD DVar2;
  
  Target = DAT_c0565798;
  hHandle = DAT_c0565760;
  while (DVar2 = WaitForSingleObject(hHandle,0xffffffff), DVar2 == 0) {
    while (LVar1 = InterlockedExchange(Target,0), LVar1 != 0) {
      (*(code *)param_1)(LVar1);
    }
  }
  return 0;
}



/* c0561738 FUN_c0561738 */

/* Boundary evidence: original MIPS .pdata c0561738..c05617bf. Semantic name remains unreviewed. */

undefined4 FUN_c0561738(int param_1)

{
  DWORD DVar1;
  HANDLE hHandle;
  code *pcVar2;
  undefined4 uVar3;
  
  hHandle = *(HANDLE *)(param_1 + 4);
  pcVar2 = *(code **)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  while ((DVar1 = WaitForSingleObject(hHandle,0xffffffff), DVar1 == 0 &&
         (*(char *)(param_1 + 0x14) != '\0'))) {
    (*pcVar2)(param_1,uVar3);
  }
  return 0;
}



/* c05617c0 FUN_c05617c0 */

/* Boundary evidence: original MIPS .pdata c05617c0..c05618e3. Semantic name remains unreviewed. */

int FUN_c05617c0(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,int param_4,ulong *param_5)

{
  int iVar1;
  size_t sVar2;
  ulong uVar3;
  wchar_t *_Str;
  wchar_t *local_238 [2];
  wchar_t local_230 [260];
  uint local_28;
  
  local_28 = DAT_c05653c8;
  iVar1 = FUN_c0560594(param_1,param_2,param_3,(LPBYTE)param_5);
  if (iVar1 == 1) {
    iVar1 = 1;
    if (param_4 == 0) goto LAB_c05618b0;
  }
  else {
    iVar1 = FUN_c056056c(param_1,param_2,param_3,(LPBYTE)local_230,0x208);
    if (iVar1 != 1) goto LAB_c05618b0;
    _Str = local_230;
    for (; param_4 != 0; param_4 = param_4 + -1) {
      if (*_Str == L'\0') goto LAB_c05618ac;
      sVar2 = wcslen(_Str);
      _Str = _Str + sVar2 + 1;
    }
    uVar3 = wcstoul(_Str,local_238,0x10);
    *param_5 = uVar3;
    if (local_238[0] != _Str) goto LAB_c05618b0;
  }
LAB_c05618ac:
  iVar1 = 0;
LAB_c05618b0:
  FUN_c05625b0(local_28);
  return iVar1;
}



/* c05618e4 FUN_c05618e4 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c05618e4..c0561ca7. Semantic name remains unreviewed. */

undefined4
FUN_c05618e4(uint param_1,undefined4 param_2,undefined4 param_3,LPCWSTR param_4,int *param_5)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 uVar10;
  wchar_t *pwVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 uVar15;
  wchar_t *pwVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *piVar19;
  undefined4 uVar20;
  wchar_t *pwVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  int *piVar24;
  undefined4 uVar25;
  wchar_t *pwVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  int *piVar29;
  undefined4 uVar30;
  wchar_t *pwVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  int *piVar34;
  undefined4 uVar35;
  wchar_t *pwVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  int *piVar39;
  undefined4 uVar40;
  wchar_t *pwVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  int *piVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 local_478;
  int local_474;
  ulong local_470;
  int local_46c;
  undefined4 local_468;
  int local_464;
  int local_460;
  int local_45c [6];
  int local_444;
  wchar_t awStack_440 [260];
  undefined1 auStack_238 [520];
  uint local_30;
  
  local_30 = DAT_c05653c8;
  uVar3 = 0xc0000001;
  *param_5 = 0;
  if (param_1 < 0xff) {
    iVar1 = FUN_c0560680((HKEY)0x80000002,param_4,(undefined *)0x0,(undefined *)0x0);
    if ((iVar1 == 2) && (iVar1 = _wcsicmp(awStack_440,L"giisr.dll"), iVar1 == 0)) {
      iVar1 = LoadIntChainHandler(awStack_440,auStack_238,param_1 & 0xff);
      *param_5 = iVar1;
      if (iVar1 == 0) goto LAB_c0561c70;
      piVar44 = &local_444;
      piVar39 = local_45c;
      pwVar41 = L"MaskOffset";
      piVar34 = local_45c + 3;
      pwVar36 = L"UseMaskReg";
      piVar29 = local_45c + 2;
      pwVar31 = L"PortMask";
      piVar24 = local_45c + 5;
      pwVar26 = L"PortSize";
      piVar19 = &local_46c;
      pwVar21 = L"PortOffset";
      piVar14 = &local_460;
      pwVar16 = L"PortIndex";
      piVar9 = &local_464;
      pwVar11 = L"PortIsIO";
      puVar4 = &local_478;
      local_464 = 1;
      local_460 = 0;
      local_45c[0] = 0;
      local_45c[1] = 0;
      local_45c[2] = 1;
      local_45c[3] = 0;
      local_45c[4] = 0;
      local_478 = 0;
      local_46c = 0;
      uVar46 = 0;
      uVar45 = 4;
      uVar43 = 0;
      uVar42 = 4;
      uVar40 = 4;
      uVar38 = 0;
      uVar37 = 4;
      uVar35 = 4;
      uVar33 = 0;
      uVar32 = 4;
      uVar30 = 4;
      uVar28 = 0;
      uVar27 = 4;
      uVar25 = 4;
      uVar23 = 0;
      uVar22 = 4;
      uVar20 = 4;
      uVar18 = 0;
      uVar17 = 4;
      uVar15 = 4;
      uVar13 = 0;
      uVar12 = 4;
      uVar10 = 4;
      uVar8 = 0;
      uVar7 = 4;
      pwVar6 = L"CheckPort";
      uVar5 = 4;
      local_468 = param_2;
      FUN_c0560680((HKEY)0x80000002,param_4,(undefined *)0x0,(undefined *)0x0);
      if (local_464 == 0) goto LAB_c0561c28;
      local_470 = 0;
      if (local_460 == 0) {
        pwVar2 = L"MemBase";
      }
      else {
        pwVar2 = L"IoBase";
      }
      iVar1 = FUN_c05617c0((HKEY)0x80000002,param_4,pwVar2,local_46c,&local_470);
      if (iVar1 != 0) {
        local_474 = local_460;
        iVar1 = TransBusAddrToStatic
                          (param_3,local_478,local_470 + local_45c[5],0,local_45c[2],&local_474,
                           local_45c + 1,puVar4,uVar5,pwVar6,uVar7,uVar8,piVar9,uVar10,pwVar11,
                           uVar12,uVar13,piVar14,uVar15,pwVar16,uVar17,uVar18,piVar19,uVar20,pwVar21
                           ,uVar22,uVar23,piVar24,uVar25,pwVar26,uVar27,uVar28,piVar29,uVar30,
                           pwVar31,uVar32,uVar33,piVar34,uVar35,pwVar36,uVar37,uVar38,piVar39,uVar40
                           ,pwVar41,uVar42,uVar43,piVar44,uVar45,uVar46);
        if (iVar1 != 0) {
          if (local_45c[0] != 0) {
            local_474 = local_460;
            iVar1 = TransBusAddrToStatic
                              (param_3,local_478,local_470 + local_444,0,local_45c[2],&local_474,
                               local_45c + 4,puVar4,uVar5,pwVar6,uVar7,uVar8,piVar9,uVar10,pwVar11,
                               uVar12,uVar13,piVar14,uVar15,pwVar16,uVar17,uVar18,piVar19,uVar20,
                               pwVar21,uVar22,uVar23,piVar24,uVar25,pwVar26,uVar27,uVar28,piVar29,
                               uVar30,pwVar31,uVar32,uVar33,piVar34,uVar35,pwVar36,uVar37,uVar38,
                               piVar39,uVar40,pwVar41,uVar42,uVar43,piVar44,uVar45,uVar46);
            if (iVar1 == 0) goto LAB_c0561c50;
          }
LAB_c0561c28:
          iVar1 = KernelLibIoControl(*param_5,0x100,&local_468,0x20,0,0,0);
          if (iVar1 != 0) goto LAB_c0561c6c;
        }
      }
LAB_c0561c50:
      if (*param_5 != 0) {
        FreeIntChainHandler();
      }
      goto LAB_c0561c70;
    }
  }
LAB_c0561c6c:
  uVar3 = 0;
LAB_c0561c70:
  FUN_c05625b0(local_30);
  return uVar3;
}



/* c0561ca8 FUN_c0561ca8 */

/* Boundary evidence: original MIPS .pdata c0561ca8..c0561d83. Semantic name remains unreviewed. */

undefined4 FUN_c0561ca8(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0xe) {
      FUN_c05615f0((int)param_1);
    }
    else {
      InterruptDisable();
    }
    *(undefined1 *)(param_1 + 5) = 0;
    if (param_1[1] != 0) {
      EventModify(param_1[1],3);
      if ((HANDLE)param_1[4] != (HANDLE)0x0) {
        WaitForSingleObject((HANDLE)param_1[4],0xffffffff);
        CloseHandle((HANDLE)param_1[4]);
      }
      CloseHandle((HANDLE)param_1[1]);
    }
    if ((char)param_1[7] != '\0') {
      ResourceRelease(1,param_1[6],1);
    }
    if (param_1[8] != 0) {
      FreeIntChainHandler();
    }
    CTEFreeMem(param_1);
  }
  return 0;
}



/* c0561d84 FUN_c0561d84 */

/* Boundary evidence: original MIPS .pdata c0561d84..c0562057. Semantic name remains unreviewed. */

int FUN_c0561d84(undefined4 *param_1,int param_2,int param_3,uint param_4,int param_5,
                undefined4 param_6,undefined4 param_7,int param_8,undefined4 param_9,
                LPCWSTR param_10,undefined4 param_11,LPVOID param_12)

{
  char cVar1;
  int *_Dst;
  int iVar2;
  int iVar3;
  HANDLE pvVar4;
  uint local_resc;
  undefined4 local_28;
  int *local_24;
  
  local_resc = param_4;
  _Dst = (int *)CTEAllocMem(0x24);
  if (_Dst == (int *)0x0) {
LAB_c0561ffc:
    iVar2 = -0x3fffffe9;
  }
  else {
    memset(_Dst,0,0x24);
    _Dst[6] = local_resc;
    if (param_5 == -1) {
      iVar2 = KernelIoControl(0x1010098,&local_resc,4,_Dst,4,0);
      if (iVar2 != 0) {
        if (param_8 != 0) {
          cVar1 = ResourceRequest(1,local_resc,1);
          *(char *)(_Dst + 7) = cVar1;
          if (cVar1 == '\0') goto LAB_c0561ffc;
        }
        goto LAB_c0561e84;
      }
LAB_c0561e50:
      iVar2 = -0x3fffffff;
    }
    else {
      *_Dst = param_5;
      iVar2 = FUN_c05618e4(local_resc,param_5,param_8,param_10,_Dst + 8);
      if (iVar2 == 0) {
LAB_c0561e84:
        _Dst[2] = param_2;
        _Dst[3] = param_3;
        *(undefined1 *)(_Dst + 5) = 1;
        if (*_Dst != 0xe) {
          pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
          _Dst[1] = (int)pvVar4;
          if (pvVar4 != (HANDLE)0x0) {
            iVar2 = InterruptInitialize(*_Dst,pvVar4,0,0);
            if (iVar2 == 0) goto LAB_c0561e50;
            pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0561738,_Dst,0,(LPDWORD)0x0);
            _Dst[4] = (int)pvVar4;
            if (pvVar4 != (HANDLE)0x0) {
LAB_c0562018:
              CeSetThreadPriority(pvVar4,param_9);
              goto LAB_c0562028;
            }
          }
          goto LAB_c0561ffc;
        }
        if (DAT_c05654b0 != (HANDLE)0x0) {
          FUN_c0561598((int)_Dst);
LAB_c0562028:
          iVar2 = 0;
          goto LAB_c056202c;
        }
        iVar2 = -0x3fffffff;
        iVar3 = KernelIoControl(0x1010110,0,0,&local_28,8,0);
        if (iVar3 != 0) {
          DAT_c0565798 = local_28;
          DAT_c0565794 = local_24;
          DAT_c0565760 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
          if (DAT_c0565760 != (HANDLE)0x0) {
            *DAT_c0565794 = _Dst[6];
            iVar3 = InterruptInitialize(0xe,DAT_c0565760,0,0);
            if (iVar3 != 0) {
              InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0565780);
              pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05616b0,param_12,0,
                                    (LPDWORD)0x0);
              param_9 = param_11;
              DAT_c05654b0 = pvVar4;
              if (pvVar4 != (HANDLE)0x0) goto LAB_c0562018;
            }
          }
        }
      }
    }
  }
  FUN_c0561ca8(_Dst);
  _Dst = (int *)0x0;
LAB_c056202c:
  *param_1 = _Dst;
  return iVar2;
}



/* c0562448 entry */

/* Boundary evidence: original MIPS .pdata c0562448..c05624bb. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c05624bc();
    FUN_c056280c();
  }
  uVar1 = FUN_c054ba5c(param_1,param_2);
  if (param_2 == 0) {
    FUN_c0562794();
  }
  return uVar1;
}



/* c05624bc FUN_c05624bc */

/* Boundary evidence: original MIPS .pdata c05624bc..c056252f. Semantic name remains unreviewed. */

void FUN_c05624bc(void)

{
  uint uVar1;
  
  if ((DAT_c05653c8 == 0) || (DAT_c05653c8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c05653c8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c05653c8 == 0) {
      DAT_c05653c8 = 0xb064;
    }
  }
  DAT_c05653cc = ~DAT_c05653c8;
  return;
}



/* c0562530 FUN_c0562530 */

/* Boundary evidence: original MIPS .pdata c0562530..c0562583. Semantic name remains unreviewed. */

void FUN_c0562530(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c05625b0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0562584 FUN_c0562584 */

/* Boundary evidence: original MIPS .pdata c0562584..c05625af. Semantic name remains unreviewed. */

undefined4 FUN_c0562584(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0562530(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c05625b0 FUN_c05625b0 */

/* Boundary evidence: original MIPS .pdata c05625b0..c05625f7. Semantic name remains unreviewed. */

void FUN_c05625b0(uint param_1)

{
  if ((param_1 == DAT_c05653c8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c05625f8 FUN_c05625f8 */

/* Boundary evidence: original MIPS .pdata c05625f8..c0562673. Semantic name remains unreviewed. */

void FUN_c05625f8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c0562530(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c0562674 FUN_c0562674 */

/* Boundary evidence: original MIPS .pdata c0562674..c0562793. Semantic name remains unreviewed. */

void FUN_c0562674(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c05654b4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c0565818;
    if (DAT_c0565818 != (undefined4 *)0x0) {
      while (DAT_c0565814 = DAT_c0565814 + -1, _Memory <= DAT_c0565814) {
        if ((code *)*DAT_c0565814 != (code *)0x0) {
          (*(code *)*DAT_c0565814)();
          _Memory = DAT_c0565818;
        }
      }
      free(_Memory);
      DAT_c0565814 = (undefined4 *)0x0;
      DAT_c0565818 = (undefined4 *)0x0;
    }
    FUN_c05627b8((undefined4 *)&DAT_c0541010,(undefined4 *)&DAT_c0541014);
  }
  FUN_c05627b8((undefined4 *)&DAT_c0541018,(undefined4 *)&DAT_c054101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c056581c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0562794 FUN_c0562794 */

/* Boundary evidence: original MIPS .pdata c0562794..c05627b7. Semantic name remains unreviewed. */

void FUN_c0562794(void)

{
  FUN_c0562674(0,0,1);
  return;
}



/* c05627b8 FUN_c05627b8 */

/* Boundary evidence: original MIPS .pdata c05627b8..c056280b. Semantic name remains unreviewed. */

void FUN_c05627b8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c056280c FUN_c056280c */

/* Boundary evidence: original MIPS .pdata c056280c..c0562847. Semantic name remains unreviewed. */

void FUN_c056280c(void)

{
  FUN_c05627b8((undefined4 *)&DAT_c0541008,(undefined4 *)&DAT_c054100c);
  FUN_c05627b8((undefined4 *)&DAT_c0541000,(undefined4 *)&DAT_c0541004);
  return;
}


