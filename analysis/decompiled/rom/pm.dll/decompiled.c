/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0301b24 FUN_c0301b24 */

uint FUN_c0301b24(uint param_1,uint param_2)

{
  if (param_1 == 3) {
    if ((param_2 & 8) != 0) {
      return 3;
    }
    param_1 = 4;
  }
  if (param_1 == 4) {
    if ((param_2 & 0x10) == 0) {
      param_1 = 3;
    }
    if ((1 << (param_1 & 0x1f) & param_2) == 0) {
      param_1 = 2;
    }
  }
  if (param_1 == 2) {
    if ((param_2 & 4) != 0) {
      return 2;
    }
    param_1 = 1;
  }
  if ((param_1 == 1) && ((param_2 & 2) == 0)) {
    param_1 = 0;
  }
  return param_1;
}



/* c0301bac FUN_c0301bac */

/* Boundary evidence: original MIPS .pdata c0301bac..c0301e53. Semantic name remains unreviewed. */

DWORD FUN_c0301bac(undefined4 *param_1,uint param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 **ppuVar10;
  int iVar11;
  uint local_48;
  uint local_44;
  undefined1 auStack_40 [8];
  undefined4 *local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  
  DVar5 = 0;
  iVar11 = 0;
  ppuVar10 = (undefined4 **)0x0;
  bVar2 = false;
  iVar8 = -1;
  local_44 = param_2;
  local_48 = FUN_c0301b24(param_2,(uint)*(byte *)(param_1 + 10));
  FUN_c0305c30();
  uVar7 = param_1[6];
  if (((local_48 == uVar7) && (param_1[8] == 0)) && (param_3 == 0)) {
    bVar1 = false;
    uVar7 = local_44;
    uVar9 = local_44;
  }
  else {
    param_1[7] = local_48;
    bVar2 = true;
    iVar11 = DAT_c030d5ec + 1;
    uVar9 = param_1[1];
    iVar8 = param_1[0x17];
    bVar1 = true;
    param_1[8] = param_1[8] + 1;
    DAT_c030d5ec = iVar11;
    if (iVar8 != -1) {
      bVar2 = false;
    }
  }
  FUN_c0305c50();
  if (bVar1) {
    uVar6 = 0x10;
    memset(&local_38,0,0x10);
    puVar4 = (undefined4 *)param_1[9];
    if (puVar4 != (undefined4 *)0x0) {
      local_34 = *puVar4;
      local_2c = *param_1;
      ppuVar10 = &local_38;
      local_38 = puVar4;
      local_30 = param_1;
    }
    if (bVar2) {
      iVar8 = (**(code **)(param_1[0x18] + 4))(param_1);
    }
    if (iVar8 == -1) {
      DVar5 = 6;
    }
    else {
      if (ppuVar10 == (undefined4 **)0x0) {
        uVar6 = 0;
      }
      iVar3 = (**(code **)(param_1[0x18] + 0xc))
                        (iVar8,0x321008,ppuVar10,uVar6,&local_48,4,auStack_40);
      if (iVar3 == 0) {
        DVar5 = GetLastError();
        if (DVar5 == 0) {
          DVar5 = 0x1f;
        }
        FUN_c0305c30();
        if (local_48 == uVar7) {
          param_1[1] = uVar9;
          param_1[6] = uVar7;
        }
      }
      else {
        FUN_c0305c30();
        if (param_1[7] == local_48) {
          param_1[1] = local_44;
          param_1[6] = local_48;
        }
        else if ((iVar11 != DAT_c030d5ec) || (DVar5 = 0x1f, 1 < (uint)param_1[8])) {
          DVar5 = 0x4d5;
        }
        DAT_c030d5ec = DAT_c030d5ec + 1;
      }
      FUN_c0305c50();
      if (bVar2) {
        (**(code **)(param_1[0x18] + 8))(iVar8);
      }
    }
    FUN_c0305c30();
    iVar8 = param_1[8];
    param_1[8] = iVar8 + -1;
    if (iVar8 + -1 == 0) {
      param_1[7] = 0xffffffff;
    }
    FUN_c0305c50();
  }
  return DVar5;
}



/* c0301e54 FUN_c0301e54 */

/* Boundary evidence: original MIPS .pdata c0301e54..c0301fdb. Semantic name remains unreviewed. */

DWORD FUN_c0301e54(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  int iVar5;
  undefined4 **ppuVar6;
  undefined4 uVar7;
  int local_40;
  undefined1 auStack_3c [4];
  undefined4 *local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  
  DVar4 = 0x1f;
  ppuVar6 = (undefined4 **)0x0;
  uVar7 = 0x10;
  memset(&local_38,0,0x10);
  puVar3 = (undefined4 *)param_1[9];
  if (puVar3 != (undefined4 *)0x0) {
    local_34 = *puVar3;
    local_2c = *param_1;
    ppuVar6 = &local_38;
    local_38 = puVar3;
    local_30 = param_1;
  }
  iVar5 = param_1[0x17];
  bVar1 = iVar5 == -1;
  if (bVar1) {
    iVar5 = (**(code **)(param_1[0x18] + 4))(param_1);
  }
  if (iVar5 != -1) {
    local_40 = -1;
    if (ppuVar6 == (undefined4 **)0x0) {
      uVar7 = 0;
    }
    iVar2 = (**(code **)(param_1[0x18] + 0xc))(iVar5,0x321004,ppuVar6,uVar7,&local_40,4,auStack_3c);
    if (iVar2 == 0) {
      DVar4 = GetLastError();
    }
    else if ((local_40 < 0) || (4 < local_40)) {
      DVar4 = 0xd;
    }
    else {
      *param_2 = local_40;
      DVar4 = 0;
    }
    if (bVar1) {
      (**(code **)(param_1[0x18] + 8))(iVar5);
    }
  }
  return DVar4;
}



/* c0301fdc FUN_c0301fdc */

int FUN_c0301fdc(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  if (param_3 == -1) {
    param_3 = param_1;
    if (param_1 < param_5) {
      param_3 = param_5;
    }
    if (param_4 < param_3) {
      param_3 = param_4;
    }
  }
  if (((param_2 == param_3) || (param_3 < 0)) || (4 < param_3)) {
    param_3 = -1;
  }
  return param_3;
}



/* c0302034 FUN_c0302034 */

/* Boundary evidence: original MIPS .pdata c0302034..c0302273. Semantic name remains unreviewed. */

undefined4
FUN_c0302034(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int local_30;
  undefined4 local_2c;
  
  local_30 = *(int *)param_3[0x19];
  uVar4 = param_4[1];
  local_2c = 0;
  puVar2 = FUN_c0306dd0(param_6,&local_30,(wchar_t *)0x0);
  if (puVar2 != (undefined4 *)0x0) {
    uVar4 = puVar2[2];
  }
  local_2c = *param_3;
  puVar2 = FUN_c0306dd0(param_6,&local_30,(wchar_t *)0x0);
  if (puVar2 != (undefined4 *)0x0) {
    uVar4 = puVar2[2];
  }
  iVar3 = 4;
  if ((param_4[2] & 0x60000) == 0) {
    bVar1 = (param_4[2] & 0x200000) == 0;
    local_2c = 0;
    puVar2 = param_5;
    while (puVar2 = FUN_c0306dd0(puVar2,&local_30,(wchar_t *)0x0), puVar2 != (undefined4 *)0x0) {
      if (((int)puVar2[2] < iVar3) && ((bVar1 || ((puVar2[4] & 0x1000) != 0)))) {
        iVar3 = puVar2[2];
      }
      puVar2 = (undefined4 *)puVar2[5];
    }
    local_2c = 0;
    puVar2 = param_5;
    while (puVar2 = FUN_c0306dd0(puVar2,&local_30,(wchar_t *)*param_4), puVar2 != (undefined4 *)0x0)
    {
      if (((int)puVar2[2] < iVar3) && ((bVar1 || ((puVar2[4] & 0x1000) != 0)))) {
        iVar3 = puVar2[2];
      }
      puVar2 = (undefined4 *)puVar2[5];
    }
    local_2c = *param_3;
    puVar2 = param_5;
    while (puVar2 = FUN_c0306dd0(puVar2,&local_30,(wchar_t *)0x0), puVar2 != (undefined4 *)0x0) {
      if (((int)puVar2[2] < iVar3) && ((bVar1 || ((puVar2[4] & 0x1000) != 0)))) {
        iVar3 = puVar2[2];
      }
      puVar2 = (undefined4 *)puVar2[5];
    }
    local_2c = *param_3;
    while (puVar2 = FUN_c0306dd0(param_5,&local_30,(wchar_t *)*param_4), puVar2 != (undefined4 *)0x0
          ) {
      if (((int)puVar2[2] < iVar3) && ((bVar1 || ((puVar2[4] & 0x1000) != 0)))) {
        iVar3 = puVar2[2];
      }
      param_5 = (undefined4 *)puVar2[5];
    }
  }
  *param_2 = uVar4;
  *param_1 = iVar3;
  return 1;
}



/* c0302274 FUN_c0302274 */

/* Boundary evidence: original MIPS .pdata c0302274..c030240f. Semantic name remains unreviewed. */

int FUN_c0302274(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  int local_30;
  
  DVar3 = 0;
  while( true ) {
    uVar2 = 0xffffffff;
    iVar5 = 0;
    FUN_c0305c30();
    iVar1 = FUN_c0302034(param_1 + 2,param_1 + 3,param_1,DAT_c030d654,DAT_c030d610,DAT_c030d61c);
    if (iVar1 != 0) {
      uVar4 = param_1[1];
      local_30 = param_1[5];
      uVar2 = FUN_c0301fdc(local_30,uVar4,param_1[4],param_1[2],param_1[3]);
      if ((uVar2 == 0xffffffff) && ((param_1[8] != 0 || (DVar3 == 0x4d5)))) {
        iVar5 = 1;
        uVar2 = uVar4;
      }
      DVar3 = 0;
    }
    FUN_c0305c50();
    if (iVar1 == 0) {
      return 0;
    }
    if (uVar2 != 0xffffffff) {
      DVar3 = FUN_c0301bac(param_1,uVar2,iVar5);
      if (DVar3 == 0) {
        FUN_c0305c30();
        if (param_1[5] != local_30) {
          DVar3 = 0x4d5;
        }
        FUN_c0305c50();
      }
      if ((DVar3 != 0x4d5) && (DVar3 != 0)) {
        iVar1 = 0;
      }
    }
    if (iVar1 == 0) break;
    if (DVar3 != 0x4d5) {
      return iVar1;
    }
  }
  return 0;
}



/* c0302410 FUN_c0302410 */

/* Boundary evidence: original MIPS .pdata c0302410..c03024b7. Semantic name remains unreviewed. */

void FUN_c0302410(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *local_20;
  
  FUN_c0305c30();
  do {
    bVar1 = false;
    puVar2 = *(undefined4 **)(param_1 + 4);
    do {
      if (puVar2 == (undefined4 *)0x0) {
        FUN_c0305c50();
        return;
      }
      FUN_c0306754((int)puVar2);
      FUN_c0305c50();
      FUN_c0302274(puVar2);
      FUN_c0305c30();
      if (puVar2[0x19] == 0) {
        bVar1 = true;
      }
      else {
        local_20 = (undefined4 *)puVar2[0x1a];
      }
      FUN_c03067a0(puVar2);
      puVar2 = local_20;
    } while (!bVar1);
  } while( true );
}



/* c03024b8 FUN_c03024b8 */

/* Boundary evidence: original MIPS .pdata c03024b8..c03024f7. Semantic name remains unreviewed. */

void FUN_c03024b8(void)

{
  int iVar1;
  
  for (iVar1 = DAT_c030d638; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    FUN_c0302410(iVar1);
  }
  return;
}



/* c03024f8 FUN_c03024f8 */

/* Boundary evidence: original MIPS .pdata c03024f8..c0302593. Semantic name remains unreviewed. */

int FUN_c03024f8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_c0305c30();
  iVar2 = DAT_c030d638;
  if (DAT_c030d638 != 0) {
    do {
      if (iVar3 != 0) goto LAB_c030256c;
      for (iVar1 = *(int *)(iVar2 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x68)) {
        if (iVar1 == param_1) {
          iVar3 = 1;
          break;
        }
      }
      iVar2 = *(int *)(iVar2 + 0x14);
    } while (iVar2 != 0);
    if (iVar3 != 0) {
LAB_c030256c:
      FUN_c0306754(param_1);
    }
  }
  FUN_c0305c50();
  return iVar3;
}



/* c0302594 FUN_c0302594 */

/* Boundary evidence: original MIPS .pdata c0302594..c030287f. Semantic name remains unreviewed. */

void FUN_c0302594(void *param_1,wchar_t *param_2,int param_3,void *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 **ppuVar5;
  undefined4 uVar6;
  int local_40 [2];
  undefined4 *local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  
  puVar1 = FUN_c0307364(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  puVar2 = FUN_c0306948((int)puVar1,param_2);
  if (puVar2 != (undefined4 *)0x0) goto LAB_c0302844;
  iVar4 = 0;
  local_40[0] = 0;
  puVar2 = FUN_c030657c(param_2);
  if (puVar2 == (undefined4 *)0x0) {
    return;
  }
  if (param_4 != (void *)0x0) {
    memcpy(puVar2 + 10,param_4,0x30);
  }
  if (param_3 != 0) {
    FUN_c0306754(param_3);
  }
  puVar2[9] = param_3;
  iVar3 = FUN_c0306810((int)puVar1,(int)puVar2);
  if (iVar3 == 0) goto LAB_c0302844;
  iVar3 = (**(code **)(puVar2[0x18] + 4))();
  puVar2[0x17] = iVar3;
  if (iVar3 == -1) {
LAB_c03027c8:
    if (iVar4 == 0) goto LAB_c03027d0;
    iVar4 = (**(code **)(puVar2[0x18] + 4))(puVar2);
    if (iVar4 == -1) {
      (**(code **)(puVar2[0x18] + 8))(puVar2[0x17]);
      puVar2[0x17] = 0xffffffff;
    }
    else {
      (**(code **)(puVar2[0x18] + 8))(iVar4);
    }
    FUN_c0302274(puVar2);
  }
  else {
    iVar4 = 1;
    if (param_4 == (void *)0x0) {
      ppuVar5 = (undefined4 **)0x0;
      uVar6 = 0x10;
      memset(&local_38,0,0x10);
      puVar1 = (undefined4 *)puVar2[9];
      if (puVar1 != (undefined4 *)0x0) {
        local_34 = *puVar1;
        local_2c = *puVar2;
        ppuVar5 = &local_38;
        local_38 = puVar1;
        local_30 = puVar2;
      }
      if (ppuVar5 == (undefined4 **)0x0) {
        uVar6 = 0;
      }
      iVar4 = (**(code **)(puVar2[0x18] + 0xc))
                        (iVar3,0x321000,ppuVar5,uVar6,puVar2 + 10,0x30,local_40);
      if (iVar4 != 0) {
        if (local_40[0] != 0x30) {
          iVar4 = 0;
        }
        goto LAB_c0302780;
      }
    }
    else {
LAB_c0302780:
      if (iVar4 != 0) {
        if ((puVar2[0x15] & 1) != 0) {
          (**(code **)(puVar2[0x18] + 0xc))(puVar2[0x17],0x321018,0,0,0,0,0);
        }
        goto LAB_c03027c8;
      }
    }
LAB_c03027d0:
    FUN_c0306894(puVar2);
  }
  if (puVar2 == (undefined4 *)0x0) {
    return;
  }
LAB_c0302844:
  FUN_c03067a0(puVar2);
  return;
}



/* c0302880 FUN_c0302880 */

/* Boundary evidence: original MIPS .pdata c0302880..c030288b. Semantic name remains unreviewed. */

undefined4 FUN_c0302880(void)

{
  return 1;
}



/* c030288c FUN_c030288c */

/* Boundary evidence: original MIPS .pdata c030288c..c030295f. Semantic name remains unreviewed. */

void FUN_c030288c(void *param_1,wchar_t *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = FUN_c0307364(param_1);
  if ((puVar3 != (undefined4 *)0x0) &&
     (puVar3 = FUN_c0306948((int)puVar3,param_2), puVar3 != (undefined4 *)0x0)) {
    FUN_c0306894(puVar3);
    if ((LPVOID)puVar3[9] != (LPVOID)0x0) {
      FUN_c03067a0((LPVOID)puVar3[9]);
      puVar3[9] = 0;
    }
    puVar1 = DAT_c030d638;
    if ((puVar3[0x15] & 1) != 0) {
      for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[5]) {
        puVar4 = (undefined4 *)puVar1[1];
        while (puVar2 = puVar4, puVar2 != (undefined4 *)0x0) {
          puVar4 = (undefined4 *)puVar2[0x1a];
          if ((undefined4 *)puVar2[9] == puVar3) {
            FUN_c030288c((void *)*puVar1,(wchar_t *)*puVar2);
          }
        }
      }
    }
    FUN_c03067a0(puVar3);
  }
  return;
}



/* c0302960 PmGetDevicePower */

/* Boundary evidence: original MIPS .pdata c0302960..c0302acf. Semantic name remains unreviewed. */

DWORD PmGetDevicePower(wchar_t *param_1,uint param_2,int *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  
                    /* 0x2960  2  PmGetDevicePower */
  DVar2 = 2;
  puVar3 = (undefined4 *)0x0;
  if (((param_1 == (wchar_t *)0x0) || (param_3 == (int *)0x0)) ||
     (puVar3 = FUN_c0306270(param_1,param_2), local_2c = puVar3, puVar3 == (undefined4 *)0x0)) {
    DVar2 = 0x57;
    goto LAB_c0302a8c;
  }
  puVar1 = FUN_c0307364((void *)*puVar3);
  if ((puVar1 == (undefined4 *)0x0) ||
     (puVar1 = FUN_c0306948((int)puVar1,(wchar_t *)puVar3[1]), local_28 = puVar1,
     puVar1 == (undefined4 *)0x0)) goto LAB_c0302a8c;
  local_30 = -1;
  if ((param_2 & 0x1000) == 0) {
    FUN_c0305c30();
    iVar4 = puVar1[1];
    FUN_c0305c50();
    DVar2 = 0;
LAB_c0302a48:
    *param_3 = iVar4;
  }
  else {
    DVar2 = FUN_c0301e54(puVar1,&local_30);
    iVar4 = local_30;
    if (DVar2 == 0) goto LAB_c0302a48;
  }
  FUN_c03067a0(puVar1);
LAB_c0302a8c:
  if (puVar3 != (undefined4 *)0x0) {
    FUN_c0306498(puVar3);
  }
  return DVar2;
}



/* c0302ad0 FUN_c0302ad0 */

/* Boundary evidence: original MIPS .pdata c0302ad0..c0302adb. Semantic name remains unreviewed. */

undefined4 FUN_c0302ad0(void)

{
  return 1;
}



/* c0302adc PmSetDevicePower */

/* Boundary evidence: original MIPS .pdata c0302adc..c0302c37. Semantic name remains unreviewed. */

undefined4 PmSetDevicePower(wchar_t *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
                    /* 0x2adc  11  PmSetDevicePower */
  uVar3 = 2;
  puVar4 = (undefined4 *)0x0;
  FUN_c0305c70();
  if (((param_1 == (wchar_t *)0x0) || (((param_3 < 0 || (4 < param_3)) && (param_3 != -1)))) ||
     (puVar4 = FUN_c0306270(param_1,param_2), puVar4 == (undefined4 *)0x0)) {
    uVar3 = 0x57;
    goto LAB_c0302bf8;
  }
  iVar1 = CeGetCallerTrust();
  if (iVar1 != 2) {
    uVar3 = 5;
    goto LAB_c0302bf8;
  }
  puVar2 = FUN_c0307364((void *)*puVar4);
  if ((puVar2 == (undefined4 *)0x0) ||
     (puVar2 = FUN_c0306948((int)puVar2,(wchar_t *)puVar4[1]), puVar2 == (undefined4 *)0x0))
  goto LAB_c0302bf8;
  FUN_c0305c30();
  if (param_3 == -1) {
    puVar2[4] = 0xffffffff;
    FUN_c0305c50();
    FUN_c0302274(puVar2);
LAB_c0302bb0:
    uVar3 = 0;
  }
  else {
    puVar2[4] = param_3;
    FUN_c0305c50();
    iVar1 = FUN_c0302274(puVar2);
    if (iVar1 != 0) goto LAB_c0302bb0;
    FUN_c0305c30();
    puVar2[4] = 0xffffffff;
    FUN_c0305c50();
    uVar3 = 0x1d;
  }
  FUN_c03067a0(puVar2);
LAB_c0302bf8:
  FUN_c0305c90();
  if (puVar4 != (undefined4 *)0x0) {
    FUN_c0306498(puVar4);
  }
  return uVar3;
}



/* c0302c38 PmDevicePowerNotify */

/* Boundary evidence: original MIPS .pdata c0302c38..c0302d1f. Semantic name remains unreviewed. */

undefined4 PmDevicePowerNotify(wchar_t *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
                    /* 0x2c38  1  PmDevicePowerNotify */
  uVar3 = 0;
  puVar4 = (undefined4 *)0x0;
  if ((((param_1 == (wchar_t *)0x0) || (param_2 < 0)) || (4 < param_2)) ||
     (puVar4 = FUN_c0306270(param_1,param_3), puVar4 == (undefined4 *)0x0)) {
    uVar3 = 0x57;
  }
  else {
    puVar1 = FUN_c0307364((void *)*puVar4);
    if ((puVar1 == (undefined4 *)0x0) ||
       (puVar1 = FUN_c0306948((int)puVar1,(wchar_t *)puVar4[1]), puVar1 == (undefined4 *)0x0)) {
      uVar3 = 2;
    }
    else {
      FUN_c0305c30();
      puVar1[5] = param_2;
      FUN_c0305c50();
      iVar2 = FUN_c0302274(puVar1);
      if (iVar2 == 0) {
        uVar3 = 0x1d;
      }
      FUN_c03067a0(puVar1);
    }
  }
  if (puVar4 != (undefined4 *)0x0) {
    FUN_c0306498(puVar4);
  }
  return uVar3;
}



/* c0302d20 FUN_c0302d20 */

/* Boundary evidence: original MIPS .pdata c0302d20..c0302d93. Semantic name remains unreviewed. */

BOOL FUN_c0302d20(int param_1)

{
  BOOL BVar1;
  
  if (*(HANDLE *)(param_1 + 8) == (HANDLE)0x0) {
    BVar1 = 1;
  }
  else {
    BVar1 = TerminateThread(*(HANDLE *)(param_1 + 8),0xffffffff);
    *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    CloseHandle(*(HANDLE *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return BVar1;
}



/* c0302d94 FUN_c0302d94 */

/* Boundary evidence: original MIPS .pdata c0302d94..c0302dd3. Semantic name remains unreviewed. */

void FUN_c0302d94(undefined4 *param_1)

{
  DWORD dwExitCode;
  
  dwExitCode = (**(code **)*param_1)(param_1);
                    /* WARNING: Subroutine does not return */
  param_1[5] = dwExitCode;
  ExitThread(dwExitCode);
}



/* c0302dd4 FUN_c0302dd4 */

/* Boundary evidence: original MIPS .pdata c0302dd4..c0302e73. Semantic name remains unreviewed. */

undefined4 *
FUN_c0302dd4(undefined4 *param_1,undefined4 param_2,wchar_t *param_3,undefined4 param_4)

{
  size_t sVar1;
  wchar_t *_Dest;
  uint uVar2;
  
  *param_1 = &PTR_LAB_c030103c;
  param_1[2] = param_2;
  param_1[3] = param_4;
  param_1[1] = 0;
  if (param_3 == (wchar_t *)0x0) {
    param_1[1] = 0;
  }
  else {
    sVar1 = wcslen(param_3);
    if (sVar1 + 1 < 0x80000000) {
      uVar2 = (sVar1 + 1) * 2;
    }
    else {
      uVar2 = 0xffffffff;
    }
    _Dest = operator_new(uVar2);
    param_1[1] = _Dest;
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,param_3);
    }
  }
  return param_1;
}



/* c0302e8c FUN_c0302e8c */

/* Boundary evidence: original MIPS .pdata c0302e8c..c0302eeb. Semantic name remains unreviewed. */

undefined4 * FUN_c0302e8c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_c030103c;
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0302eec FUN_c0302eec */

/* Boundary evidence: original MIPS .pdata c0302eec..c0302fc3. Semantic name remains unreviewed. */

undefined4 FUN_c0302eec(int param_1)

{
  LSTATUS LVar1;
  void *pvVar2;
  LPDWORD lpcbData;
  DWORD local_18 [2];
  
  if (*(LPCWSTR *)(param_1 + 4) != (LPCWSTR)0x0) {
    if (*(int *)(param_1 + 0x18) == 0) {
      lpcbData = (LPDWORD)(param_1 + 0x14);
      *lpcbData = 0;
      LVar1 = RegQueryValueExW(*(HKEY *)(param_1 + 8),*(LPCWSTR *)(param_1 + 4),(LPDWORD)0x0,
                               (LPDWORD)(param_1 + 0x10),(LPBYTE)0x0,lpcbData);
      if ((LVar1 == 0) || (LVar1 == 0xea)) {
        pvVar2 = operator_new(*lpcbData);
        *(void **)(param_1 + 0x18) = pvVar2;
      }
    }
    if (*(LPBYTE *)(param_1 + 0x18) != (LPBYTE)0x0) {
      local_18[0] = *(DWORD *)(param_1 + 0x14);
      LVar1 = RegQueryValueExW(*(HKEY *)(param_1 + 8),*(LPCWSTR *)(param_1 + 4),(LPDWORD)0x0,
                               (LPDWORD)(param_1 + 0x10),*(LPBYTE *)(param_1 + 0x18),local_18);
      if (LVar1 == 0) {
        return 1;
      }
    }
  }
  return 0;
}



/* c0302fc4 FUN_c0302fc4 */

/* Boundary evidence: original MIPS .pdata c0302fc4..c030301b. Semantic name remains unreviewed. */

int FUN_c0302fc4(int param_1,wchar_t *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = _wcsicmp(*(wchar_t **)(iVar2 + 4),param_2);
    if (iVar1 == 0) break;
    iVar2 = *(int *)(iVar2 + 0xc);
  }
  return iVar2;
}



/* c030301c FUN_c030301c */

/* Boundary evidence: original MIPS .pdata c030301c..c03030bb. Semantic name remains unreviewed. */

undefined4
FUN_c030301c(int param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0x103;
    }
    iVar1 = _wcsicmp((wchar_t *)piVar2[1],param_2);
    if (iVar1 == 0) break;
    piVar2 = (int *)piVar2[3];
  }
  iVar1 = (**(code **)(*piVar2 + 8))(piVar2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    return 0;
  }
  return 0x57;
}



/* c03030bc FUN_c03030bc */

/* Boundary evidence: original MIPS .pdata c03030bc..c030318f. Semantic name remains unreviewed. */

undefined4 FUN_c03030bc(undefined4 param_1,int param_2,uint param_3,wchar_t *param_4,uint *param_5)

{
  size_t sVar1;
  uint _Count;
  uint uVar2;
  undefined4 uVar3;
  wchar_t *_Str;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      if (param_3 <= uVar2) break;
      param_2 = *(int *)(param_2 + 0xc);
      uVar2 = uVar2 + 1;
    } while (param_2 != 0);
    if ((param_2 != 0) && (_Str = *(wchar_t **)(param_2 + 4), _Str != (wchar_t *)0x0)) {
      uVar3 = 0;
      if (param_5 == (uint *)0x0) {
        return 0;
      }
      sVar1 = wcslen(_Str);
      uVar2 = sVar1 + 1;
      if (param_4 != (wchar_t *)0x0) {
        _Count = *param_5;
        if (uVar2 < *param_5) {
          _Count = uVar2;
        }
        wcsncpy(param_4,_Str,_Count);
        if (*param_5 < uVar2) {
          uVar3 = 0xea;
        }
      }
      *param_5 = uVar2;
      return uVar3;
    }
  }
  return 0x103;
}



/* c0303190 FUN_c0303190 */

/* Boundary evidence: original MIPS .pdata c0303190..c030321b. Semantic name remains unreviewed. */

void FUN_c0303190(int param_1)

{
  int *piVar1;
  int iVar2;
  
  while (*(int *)(param_1 + 0x14) != 0) {
    piVar1 = *(int **)(param_1 + 0x14);
    iVar2 = piVar1[3];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1,1);
    }
    *(int *)(param_1 + 0x14) = iVar2;
  }
  iVar2 = *(int *)(param_1 + 0x18);
  while (iVar2 != 0) {
    piVar1 = *(int **)(param_1 + 0x18);
    iVar2 = piVar1[3];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1,1);
    }
    *(int *)(param_1 + 0x18) = iVar2;
  }
  return;
}



/* c030321c FUN_c030321c */

/* Boundary evidence: original MIPS .pdata c030321c..c030336b. Semantic name remains unreviewed. */

undefined4 FUN_c030321c(int param_1)

{
  LSTATUS LVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  DWORD dwIndex;
  DWORD local_238 [2];
  WCHAR aWStack_230 [259];
  undefined2 local_2a;
  uint local_28;
  
  local_28 = DAT_c030d5b0;
  uVar4 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar4 = 1;
    dwIndex = 0;
    while( true ) {
      local_238[0] = 0x104;
      LVar1 = RegEnumKeyExW(*(HKEY *)(param_1 + 0x10),dwIndex,aWStack_230,local_238,(LPDWORD)0x0,
                            (LPWSTR)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
      if ((LVar1 != 0) && (LVar1 != 0xea)) break;
      local_2a = 0;
      piVar2 = operator_new(0x1c);
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        FUN_c0302dd4(piVar2,*(undefined4 *)(param_1 + 0x10),aWStack_230,
                     *(undefined4 *)(param_1 + 0x18));
        *piVar2 = (int)&PTR_FUN_c0301044;
        piVar2[5] = 0;
        piVar2[6] = 0;
        piVar2[4] = 0;
      }
      if (piVar2 == (int *)0x0) {
LAB_c0303330:
        uVar4 = 0;
      }
      else {
        iVar3 = (**(code **)*piVar2)(piVar2);
        if (iVar3 == 0) {
          (**(code **)(*piVar2 + 4))(piVar2,1);
          goto LAB_c0303330;
        }
        *(int **)(param_1 + 0x18) = piVar2;
      }
      dwIndex = dwIndex + 1;
    }
  }
  FUN_c0308a9c(local_28);
  return uVar4;
}



/* c030336c FUN_c030336c */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c030336c..c03034d7. Semantic name remains unreviewed. */

undefined4 * FUN_c030336c(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint local_250 [4];
  int local_240;
  wchar_t *local_23c;
  uint local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c030d5b0;
  uVar4 = 0;
  local_240 = param_2;
  do {
    local_238[0] = 0x104;
    local_250[1] = 4;
    iVar1 = FUN_c03030bc(param_1,*(int *)(param_1 + 0x14),uVar4,awStack_230,local_238);
    if (iVar1 == 0) {
      iVar1 = FUN_c030301c(param_1,awStack_230,local_250,local_250 + 1,local_250 + 2);
      if ((((iVar1 == 0) && (local_250[2] == 4)) &&
          (iVar2 = _wcsicmp(awStack_230,L"Flags"), iVar2 != 0)) && (local_250[0] < 5)) {
        iVar2 = _wcsicmp(awStack_230,L"default");
        if (iVar2 == 0) {
          local_23c = (wchar_t *)0x0;
        }
        else {
          local_23c = awStack_230;
        }
        puVar3 = FUN_c0306a24(&local_240,0,local_250[0],(wchar_t *)0x0,0);
        if (puVar3 != (undefined4 *)0x0) {
          puVar3[5] = param_3;
          param_3 = puVar3;
        }
      }
    }
    uVar4 = uVar4 + 1;
  } while (iVar1 != 0x103);
  FUN_c0308a9c(local_28);
  return param_3;
}



/* c03034d8 FUN_c03034d8 */

/* Boundary evidence: original MIPS .pdata c03034d8..c03035cf. Semantic name remains unreviewed. */

undefined4 * FUN_c03034d8(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint local_240 [2];
  int aiStack_238 [4];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c030d5b0;
  puVar4 = (undefined4 *)0x0;
  uVar3 = 0;
  do {
    local_240[0] = 0x104;
    iVar1 = FUN_c03030bc(param_1,*(int *)(param_1 + 0x18),uVar3,awStack_228,local_240);
    if ((iVar1 == 0) && (iVar2 = FUN_c0305fa0(awStack_228,aiStack_238), iVar2 != 0)) {
      iVar2 = FUN_c0302fc4(param_1,awStack_228);
      if (iVar2 == 0) {
        iVar1 = 0x103;
      }
      else {
        puVar4 = FUN_c030336c(iVar2,(int)aiStack_238,puVar4);
      }
    }
    uVar3 = uVar3 + 1;
  } while (iVar1 != 0x103);
  puVar4 = FUN_c030336c(param_1,-0x3fcf2eb4,puVar4);
  FUN_c0308a9c(local_20);
  return puVar4;
}



/* c03035d0 PmGetSystemPowerState */

/* Boundary evidence: original MIPS .pdata c03035d0..c03036b3. Semantic name remains unreviewed. */

undefined4 PmGetSystemPowerState(STRSAFE_LPWSTR param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  size_t sVar2;
  undefined4 uVar3;
  
                    /* 0x35d0  3  PmGetSystemPowerState */
  FUN_c0305c30();
  puVar1 = DAT_c030d654;
  sVar2 = wcslen((wchar_t *)*DAT_c030d654);
  if (param_2 < sVar2 + 1) {
    uVar3 = 0x7a;
  }
  else {
    StringCchCopyW(param_1,param_2,(STRSAFE_LPCWSTR)*puVar1);
    *param_3 = DAT_c030d654[2];
    uVar3 = 0;
  }
  FUN_c0305c50();
  return uVar3;
}



/* c03036b4 FUN_c03036b4 */

/* Boundary evidence: original MIPS .pdata c03036b4..c03036bf. Semantic name remains unreviewed. */

undefined4 FUN_c03036b4(void)

{
  return 1;
}



/* c03036c0 FUN_c03036c0 */

/* Boundary evidence: original MIPS .pdata c03036c0..c03037e7. Semantic name remains unreviewed. */

int FUN_c03036c0(wchar_t *param_1,undefined4 param_2)

{
  int iVar1;
  wchar_t awStack_230 [259];
  undefined2 local_2a;
  uint local_28;
  
  local_28 = DAT_c030d5b0;
  iVar1 = 0;
  FUN_c0305c70();
  if (param_1 == (wchar_t *)0x0) {
    iVar1 = FUN_c0309158(param_2,awStack_230,0x104);
  }
  else {
    wcsncpy(awStack_230,param_1,0x103);
    local_2a = 0;
  }
  if (iVar1 == 0) {
    iVar1 = FUN_c0309198(awStack_230);
  }
  FUN_c0305c90();
  FUN_c0308a9c(local_28);
  return iVar1;
}



/* c03037e8 FUN_c03037e8 */

/* Boundary evidence: original MIPS .pdata c03037e8..c03037f3. Semantic name remains unreviewed. */

undefined4 FUN_c03037e8(void)

{
  return 1;
}



/* c03037f4 PmSetSystemPowerState */

/* Boundary evidence: original MIPS .pdata c03037f4..c030394f. Semantic name remains unreviewed. */

int PmSetSystemPowerState(int param_1,undefined4 param_2,undefined4 param_3)

{
  wint_t wVar1;
  wint_t *pwVar2;
  int iVar3;
  uint uVar4;
  wint_t local_230 [260];
  uint local_28;
  
                    /* 0x37f4  13  PmSetSystemPowerState */
  local_28 = DAT_c030d5b0;
  pwVar2 = (wint_t *)0x0;
  iVar3 = 0;
  if (param_1 != 0) {
    uVar4 = 0;
    while( true ) {
      wVar1 = *(wint_t *)(uVar4 * 2 + param_1);
      if ((wVar1 == 0) || (0x102 < uVar4)) break;
      wVar1 = towlower(wVar1);
      local_230[uVar4] = wVar1;
      uVar4 = uVar4 + 1;
    }
    local_230[uVar4] = 0;
    pwVar2 = local_230;
    if (*(short *)(uVar4 * 2 + param_1) != 0) {
      iVar3 = 0x57;
    }
  }
  if (iVar3 == 0) {
    iVar3 = FUN_c03099dc(pwVar2,param_2,param_3);
  }
  FUN_c0308a9c(local_28);
  return iVar3;
}



/* c0303950 FUN_c0303950 */

/* Boundary evidence: original MIPS .pdata c0303950..c030395b. Semantic name remains unreviewed. */

undefined4 FUN_c0303950(void)

{
  return 1;
}



/* c030395c FUN_c030395c */

/* Boundary evidence: original MIPS .pdata c030395c..c03039db. Semantic name remains unreviewed. */

undefined4 * FUN_c030395c(undefined4 *param_1,SIZE_T param_2,int param_3)

{
  HANDLE pvVar1;
  DWORD dwCreationFlags;
  
  param_1[5] = 0xffffffff;
  *param_1 = &PTR_LAB_c0301068;
  dwCreationFlags = 4;
  param_1[1] = 0;
  if (param_3 == 0) {
    dwCreationFlags = 0;
  }
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,param_2,FUN_c0302d94,param_1,dwCreationFlags,
                        param_1 + 3);
  param_1[2] = pvVar1;
  param_1[4] = param_3;
  return param_1;
}



/* c03039dc FUN_c03039dc */

/* Boundary evidence: original MIPS .pdata c03039dc..c0303a33. Semantic name remains unreviewed. */

void FUN_c03039dc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c030106c;
  if ((void *)param_1[6] != (void *)0x0) {
    operator_delete((void *)param_1[6]);
  }
  *param_1 = &PTR_LAB_c030103c;
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
  }
  return;
}



/* c0303a34 FUN_c0303a34 */

undefined4 FUN_c0303a34(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) || (uVar1 = 1, *(int *)(param_1 + 0x18) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0303a58 FUN_c0303a58 */

/* Boundary evidence: original MIPS .pdata c0303a58..c0303aeb. Semantic name remains unreviewed. */

undefined4 FUN_c0303a58(int param_1,void *param_2,uint *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint _Size;
  
  if ((*(void **)(param_1 + 0x18) == (void *)0x0) || (param_3 == (uint *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (param_2 != (void *)0x0) {
      _Size = *param_3;
      if (*(uint *)(param_1 + 0x14) <= *param_3) {
        _Size = *(uint *)(param_1 + 0x14);
      }
      memcpy(param_2,*(void **)(param_1 + 0x18),_Size);
    }
    *param_3 = *(uint *)(param_1 + 0x14);
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(param_1 + 0x10);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* c0303aec FUN_c0303aec */

/* Boundary evidence: original MIPS .pdata c0303aec..c0303b37. Semantic name remains unreviewed. */

undefined4 * FUN_c0303aec(undefined4 *param_1,uint param_2)

{
  FUN_c03039dc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0303b38 FUN_c0303b38 */

/* Boundary evidence: original MIPS .pdata c0303b38..c0303ba3. Semantic name remains unreviewed. */

void FUN_c0303b38(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0301044;
  FUN_c0303190((int)param_1);
  if ((HKEY)param_1[4] != (HKEY)0x0) {
    RegCloseKey((HKEY)param_1[4]);
  }
  *param_1 = &PTR_LAB_c030103c;
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
  }
  return;
}



/* c0303ba4 FUN_c0303ba4 */

/* Boundary evidence: original MIPS .pdata c0303ba4..c0303cfb. Semantic name remains unreviewed. */

undefined4 FUN_c0303ba4(int param_1)

{
  LSTATUS LVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  DWORD dwIndex;
  DWORD local_238 [2];
  WCHAR aWStack_230 [259];
  undefined2 local_2a;
  uint local_28;
  
  local_28 = DAT_c030d5b0;
  uVar4 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar4 = 1;
    dwIndex = 0;
    while( true ) {
      local_238[0] = 0x104;
      LVar1 = RegEnumValueW(*(HKEY *)(param_1 + 0x10),dwIndex,aWStack_230,local_238,(LPDWORD)0x0,
                            (LPDWORD)0x0,(LPBYTE)0x0,(LPDWORD)0x0);
      if ((LVar1 != 0) && (LVar1 != 0xea)) break;
      local_2a = 0;
      piVar2 = operator_new(0x1c);
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        FUN_c0302dd4(piVar2,*(undefined4 *)(param_1 + 0x10),aWStack_230,
                     *(undefined4 *)(param_1 + 0x14));
        *piVar2 = (int)&PTR_FUN_c030106c;
        piVar2[5] = 0;
        piVar2[6] = 0;
        FUN_c0302eec((int)piVar2);
      }
      if (piVar2 == (int *)0x0) {
LAB_c0303cc0:
        uVar4 = 0;
      }
      else {
        iVar3 = (**(code **)*piVar2)(piVar2);
        if (iVar3 == 0) {
          (**(code **)(*piVar2 + 4))(piVar2,1);
          goto LAB_c0303cc0;
        }
        *(int **)(param_1 + 0x14) = piVar2;
      }
      dwIndex = dwIndex + 1;
    }
  }
  FUN_c0308a9c(local_28);
  return uVar4;
}



/* c0303cfc FUN_c0303cfc */

/* Boundary evidence: original MIPS .pdata c0303cfc..c0303d47. Semantic name remains unreviewed. */

undefined4 * FUN_c0303cfc(undefined4 *param_1,uint param_2)

{
  FUN_c0303b38(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0303d48 FUN_c0303d48 */

/* Boundary evidence: original MIPS .pdata c0303d48..c0303e57. Semantic name remains unreviewed. */

undefined4 * FUN_c0303d48(undefined4 *param_1,undefined4 param_2,wchar_t *param_3)

{
  HANDLE pvVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  PHKEY phkResult;
  
  FUN_c0302dd4(param_1,param_2,param_3,0);
  phkResult = (PHKEY)(param_1 + 4);
  *param_1 = &PTR_FUN_c0301044;
  param_1[5] = 0;
  param_1[6] = 0;
  *phkResult = (HKEY)0x0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd));
  FUN_c030395c(param_1 + 7,0,1);
  *param_1 = &PTR_FUN_c0301080;
  param_1[7] = &PTR_FUN_c030107c;
  param_1[0x12] = 0xffffffff;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_1[0x13] = pvVar1;
  if (*phkResult == (HKEY)0x0) {
    LVar2 = RegOpenKeyExW((HKEY)param_1[2],(LPCWSTR)param_1[1],0,0,phkResult);
    if (LVar2 != 0) {
      *phkResult = (HKEY)0x0;
    }
  }
  if (*phkResult != (HKEY)0x0) {
    uVar3 = CeFindFirstRegChange(*phkResult,1,4);
    param_1[0x12] = uVar3;
  }
  return param_1;
}



/* c0303e58 FUN_c0303e58 */

/* Boundary evidence: original MIPS .pdata c0303e58..c0303eb3. Semantic name remains unreviewed. */

undefined4 FUN_c0303e58(int param_1)

{
  DWORD DVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    DVar1 = ResumeThread(*(HANDLE *)(param_1 + 8));
    if (DVar1 == 0xffffffff) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 1;
}



/* c0303eb4 FUN_c0303eb4 */

/* Boundary evidence: original MIPS .pdata c0303eb4..c0303f33. Semantic name remains unreviewed. */

undefined4 FUN_c0303eb4(int param_1,DWORD param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  if (((*(int *)(param_1 + 8) == 0) || (iVar1 = FUN_c0303e58(param_1), iVar1 == 0)) ||
     (DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 8),param_2), DVar2 != 0)) {
    uVar3 = 0;
  }
  else {
    CloseHandle(*(HANDLE *)(param_1 + 8));
    uVar3 = 1;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return uVar3;
}



/* c0303f34 FUN_c0303f34 */

/* Boundary evidence: original MIPS .pdata c0303f34..c0304017. Semantic name remains unreviewed. */

void FUN_c0303f34(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 7;
  *param_1 = &PTR_FUN_c0301080;
  *puVar1 = &PTR_FUN_c030107c;
  param_1[8] = 1;
  FUN_c0303e58((int)puVar1);
  if (param_1[0x13] != 0) {
    EventModify(param_1[0x13],3);
  }
  FUN_c0303eb4((int)puVar1,1000);
  if ((HANDLE)param_1[0x13] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x13]);
  }
  if (param_1[0x12] != -1) {
    CeFindCloseRegChange();
    param_1[0x12] = 0xffffffff;
  }
  *puVar1 = &PTR_LAB_c0301068;
  FUN_c0302d20((int)puVar1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd));
  FUN_c0303b38(param_1);
  return;
}



/* c0304018 FUN_c0304018 */

/* Boundary evidence: original MIPS .pdata c0304018..c0304063. Semantic name remains unreviewed. */

undefined4 * FUN_c0304018(undefined4 *param_1,uint param_2)

{
  FUN_c0303f34(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0304064 FUN_c0304064 */

/* Boundary evidence: original MIPS .pdata c0304064..c03041b3. Semantic name remains unreviewed. */

undefined4 FUN_c0304064(int param_1,int param_2)

{
  LSTATUS LVar1;
  int iVar2;
  int *piVar3;
  PHKEY phkResult;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  
  phkResult = (PHKEY)(param_1 + 0x10);
  if ((*phkResult == (HKEY)0x0) &&
     (LVar1 = RegOpenKeyExW(*(HKEY *)(param_1 + 8),*(LPCWSTR *)(param_1 + 4),0,0,phkResult),
     LVar1 != 0)) {
    *phkResult = (HKEY)0x0;
  }
  if (*phkResult == (HKEY)0x0) {
    return 0;
  }
  piVar5 = *(int **)(param_1 + 0x14);
  piVar4 = *(int **)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  iVar2 = FUN_c030321c(param_1);
  if (iVar2 != 0) {
    iVar2 = FUN_c0303ba4(param_1);
    uVar6 = 1;
    if (iVar2 != 0) {
      while (piVar5 != (int *)0x0) {
        piVar3 = (int *)piVar5[3];
        (**(code **)(*piVar5 + 4))(piVar5,1);
        piVar5 = piVar3;
      }
      while (piVar4 != (int *)0x0) {
        piVar5 = (int *)piVar4[3];
        (**(code **)(*piVar4 + 4))(piVar4,1);
        piVar4 = piVar5;
      }
      goto LAB_c0304170;
    }
  }
  FUN_c0303190(param_1);
  *(int **)(param_1 + 0x14) = piVar5;
  *(int **)(param_1 + 0x18) = piVar4;
  uVar6 = 0;
LAB_c0304170:
  if (param_2 == 0) {
    RegCloseKey(*phkResult);
    *phkResult = (HKEY)0x0;
  }
  return uVar6;
}



/* c03041b4 FUN_c03041b4 */

/* Boundary evidence: original MIPS .pdata c03041b4..c030424b. Semantic name remains unreviewed. */

undefined4 FUN_c03041b4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x48) == -1) {
    uVar2 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
    CeFindNextRegChange(*(undefined4 *)(param_1 + 0x48));
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x50) = 0;
    iVar1 = FUN_c0304064(param_1,1);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x50) = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
  }
  return uVar2;
}



/* c030424c FUN_c030424c */

/* Boundary evidence: original MIPS .pdata c030424c..c03042ab. Semantic name remains unreviewed. */

undefined4 FUN_c030424c(int param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  if ((*(HANDLE *)(param_1 + 0x48) == (HANDLE)0xffffffff) ||
     (DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x48),0), DVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_c03041b4(param_1);
  }
  return uVar2;
}



/* c03042ac FUN_c03042ac */

/* Boundary evidence: original MIPS .pdata c03042ac..c0304357. Semantic name remains unreviewed. */

undefined4 FUN_c03042ac(int param_1)

{
  DWORD DVar1;
  int iVar2;
  HANDLE local_18;
  int local_14;
  
  iVar2 = *(int *)(param_1 + 4);
  while( true ) {
    if (iVar2 != 0) {
      return 0;
    }
    local_18 = *(HANDLE *)(param_1 + 0x2c);
    if (local_18 == (HANDLE)0xffffffff) break;
    local_14 = *(int *)(param_1 + 0x30);
    if (local_14 == 0) {
      return 0;
    }
    DVar1 = WaitForMultipleObjects(2,&local_18,0,0xffffffff);
    if (DVar1 == 0) {
      if (*(int *)(param_1 + 4) != 0) {
        return 0;
      }
      FUN_c03041b4(param_1 + -0x1c);
    }
    iVar2 = *(int *)(param_1 + 4);
  }
  return 0;
}



/* c0304358 FUN_c0304358 */

/* Boundary evidence: original MIPS .pdata c0304358..c030438f. Semantic name remains unreviewed. */

undefined4 FUN_c0304358(void)

{
  undefined4 uVar1;
  
  if (DAT_c030d65c == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c030424c(DAT_c030d65c);
  }
  return uVar1;
}



/* c0304390 FUN_c0304390 */

/* Boundary evidence: original MIPS .pdata c0304390..c03043af. Semantic name remains unreviewed. */

undefined4 FUN_c0304390(int param_1)

{
  FUN_c0304064(param_1,0);
  return 1;
}



/* c03043b0 FUN_c03043b0 */

/* Boundary evidence: original MIPS .pdata c03043b0..c030441f. Semantic name remains unreviewed. */

undefined4 FUN_c03043b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0x4c) == 0)) ||
     (iVar1 = FUN_c03041b4(param_1), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x50) = 1;
    FUN_c0303e58(param_1 + 0x1c);
  }
  return uVar2;
}



/* c0304420 FUN_c0304420 */

/* Boundary evidence: original MIPS .pdata c0304420..c0304847. Semantic name remains unreviewed. */

int FUN_c0304420(wchar_t *param_1,undefined4 *param_2,undefined4 *param_3)

{
  HANDLE hHandle;
  DWORD DVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  size_t sVar7;
  undefined4 *local_248;
  wchar_t *local_244;
  undefined4 *local_240;
  int local_23c;
  wchar_t awStack_238 [259];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_c030d5b0;
  sVar7 = 0x104;
  local_248 = param_2;
  local_244 = param_1;
  local_240 = param_3;
  FUN_c0305c30();
  if (DAT_c030d5f0 == 0) {
    hHandle = OpenEventW(0x1f0003,0,L"SYSTEM/BootPhase2");
    if (hHandle == (HANDLE)0x0) {
      DAT_c030d5f0 = 1;
    }
    else {
      DVar1 = WaitForSingleObject(hHandle,0);
      if (DVar1 == 0) {
        if (DAT_c030d65c != (int *)0x0) {
          (**(code **)(*DAT_c030d65c + 4))(DAT_c030d65c,1);
          DAT_c030d65c = (int *)0x0;
        }
        DAT_c030d5f0 = 1;
      }
      CloseHandle(hHandle);
    }
  }
  if (DAT_c030d65c == (int *)0x0) {
    StringCbPrintfW(awStack_238,0x208,L"%s\\%s",L"SYSTEM\\CurrentControlSet\\Control\\Power",
                    L"State");
    sVar7 = wcslen(awStack_238);
    sVar7 = 0x103 - sVar7;
    puVar2 = operator_new(0x54);
    if (puVar2 == (undefined4 *)0x0) {
      DAT_c030d65c = (int *)0x0;
    }
    else {
      DAT_c030d65c = FUN_c0303d48(puVar2,0x80000002,awStack_238);
    }
    if ((DAT_c030d65c != (int *)0x0) &&
       (iVar3 = (**(code **)*DAT_c030d65c)(DAT_c030d65c), iVar3 == 0)) {
      if (DAT_c030d65c != (int *)0x0) {
        (**(code **)(*DAT_c030d65c + 4))(DAT_c030d65c,1);
      }
      DAT_c030d65c = (int *)0x0;
    }
  }
  FUN_c0305c50();
  piVar5 = DAT_c030d65c;
  if (DAT_c030d65c == (int *)0x0) {
    FUN_c0308a9c(local_30);
    return 0x57;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(DAT_c030d65c + 0xd));
  if (piVar5[0x14] == 0) {
    FUN_c03041b4((int)piVar5);
  }
  wcsncpy(awStack_238,param_1,sVar7);
  local_32 = 0;
  iVar3 = FUN_c0302fc4((int)DAT_c030d65c,awStack_238);
  if (iVar3 == 0) {
    iVar6 = 0x103;
  }
  else {
    local_248 = (undefined4 *)0x4;
    iVar4 = FUN_c030301c(iVar3,L"Default",&local_244,&local_248,&local_240);
    iVar6 = 0;
    if (iVar4 != 0) {
      iVar6 = iVar4;
    }
    if ((wchar_t *)0x4 < local_244) {
      iVar6 = 0xd;
    }
    if (iVar6 == 0) {
      local_248 = (undefined4 *)0x4;
      iVar4 = FUN_c030301c(iVar3,L"Flags",&local_23c,&local_248,&local_240);
      if (iVar4 != 0) {
        iVar6 = iVar4;
      }
      if (iVar6 == 0) {
        if (param_2 != (undefined4 *)0x0) {
          piVar5 = FUN_c0307408(param_1);
          if (piVar5 == (int *)0x0) {
            iVar6 = 0xe;
            goto LAB_c03047e4;
          }
          piVar5[1] = (int)local_244;
          piVar5[2] = local_23c;
          *param_2 = piVar5;
        }
        if (param_3 != (undefined4 *)0x0) {
          puVar2 = FUN_c03034d8(iVar3);
          *param_3 = puVar2;
        }
      }
    }
  }
LAB_c03047e4:
  LeaveCriticalSection((LPCRITICAL_SECTION)(DAT_c030d65c + 0xd));
  FUN_c0308a9c(local_30);
  return iVar6;
}



/* c0304848 FUN_c0304848 */

/* Boundary evidence: original MIPS .pdata c0304848..c0304853. Semantic name remains unreviewed. */

undefined4 FUN_c0304848(void)

{
  return 1;
}



/* c0304854 FUN_c0304854 */

/* Boundary evidence: original MIPS .pdata c0304854..c0304a6f. Semantic name remains unreviewed. */

bool FUN_c0304854(void)

{
  undefined4 *puVar1;
  bool bVar2;
  bool bVar3;
  LSTATUS LVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  DWORD dwIndex;
  HKEY local_258;
  DWORD local_254 [3];
  int aiStack_248 [4];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c030d5b0;
  StringCchPrintfW(awStack_238,0x104,L"%s\\Interfaces",L"SYSTEM\\CurrentControlSet\\Control\\Power")
  ;
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,awStack_238,0,0,&local_258);
  if (LVar4 == 0) {
    dwIndex = 0;
    while( true ) {
      local_254[1] = 0x104;
      LVar4 = RegEnumValueW(local_258,dwIndex,awStack_238,local_254 + 1,(LPDWORD)0x0,local_254,
                            (LPBYTE)0x0,(LPDWORD)0x0);
      if (LVar4 != 0) break;
      if ((((local_254[0] == 1) && (iVar5 = FUN_c0305fa0(awStack_238,aiStack_248), iVar5 != 0)) &&
          (iVar5 = memcmp(aiStack_248,&DAT_c030d14c,0x10), iVar5 != 0)) &&
         (puVar6 = FUN_c03071f0(aiStack_248), puVar6 != (undefined4 *)0x0)) {
        bVar2 = FUN_c03090d4(puVar6);
        if (CONCAT31(extraout_var,bVar2) == 0) {
          FUN_c030731c(puVar6);
        }
        else {
          puVar6[5] = DAT_c030d638;
          DAT_c030d638 = puVar6;
        }
      }
      dwIndex = dwIndex + 1;
    }
    bVar2 = LVar4 == 0x103;
    RegCloseKey(local_258);
    if (!bVar2) goto LAB_c0304a2c;
  }
  bVar2 = false;
  puVar6 = FUN_c03071f0(&DAT_c030d14c);
  if (puVar6 == (undefined4 *)0x0) goto LAB_c0304a2c;
  bVar3 = FUN_c03090d4(puVar6);
  if (CONCAT31(extraout_var_00,bVar3) == 0) {
    while( true ) {
      FUN_c030731c(puVar6);
LAB_c0304a2c:
      puVar6 = DAT_c030d638;
      if (DAT_c030d638 == (undefined4 *)0x0) break;
      puVar1 = DAT_c030d638 + 5;
      DAT_c030d638 = (undefined4 *)DAT_c030d638[5];
      *puVar1 = 0;
    }
  }
  else {
    bVar2 = true;
    puVar6[5] = DAT_c030d638;
    DAT_c030d638 = puVar6;
  }
  FUN_c0308a9c(local_30);
  return bVar2;
}



/* c0304a70 PmInit */

/* Boundary evidence: original MIPS .pdata c0304a70..c030508f. Semantic name remains unreviewed. */

int PmInit(void)

{
  bool bVar1;
  DWORD DVar2;
  LSTATUS LVar3;
  undefined3 extraout_var;
  int iVar4;
  HANDLE lpParameter;
  int iVar5;
  HANDLE lpParameter_00;
  HANDLE lpParameter_01;
  HANDLE hObject;
  HANDLE lpParameter_02;
  HANDLE local_48;
  HANDLE local_44;
  HANDLE local_40;
  HANDLE local_3c;
  HANDLE local_38;
  HANDLE local_34 [3];
  
                    /* 0x4a70  4  PmInit */
  lpParameter_02 = (HANDLE)0x0;
  lpParameter_01 = (HANDLE)0x0;
  lpParameter = (HANDLE)0x0;
  lpParameter_00 = (HANDLE)0x0;
  hObject = (HANDLE)0x0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c030d63c);
  DAT_c030d610 = 0;
  DAT_c030d61c = 0;
  DAT_c030d60c = 0;
  DAT_c030d654 = 0;
  DAT_c030d618 = GetProcessHeap();
  DAT_c030d638 = 0;
  DAT_c030d614 = (HANDLE)0x0;
  DAT_c030d5f4 = (HANDLE)0x0;
  DAT_c030d608 = (HANDLE)0x0;
  DAT_c030d634 = (HANDLE)0x0;
  DAT_c030d600 = 0;
  DAT_c030d604 = (HANDLE)0x0;
  DAT_c030d658 = (HANDLE)0x0;
  DAT_c030d650 = (HANDLE)0x0;
  DAT_c030d5f8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  if ((DAT_c030d5f8 == (HANDLE)0x0) || (LVar3 = FUN_c0308e54(), LVar3 != 0)) {
    iVar4 = 0;
  }
  else {
    bVar1 = FUN_c0304854();
    iVar4 = CONCAT31(extraout_var,bVar1);
    if (iVar4 != 0) {
      DAT_c030d614 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"SYSTEM/PowerManagerReady");
      DAT_c030d634 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      DAT_c030d5f4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      lpParameter_02 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      lpParameter_01 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      lpParameter = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      lpParameter_00 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if ((((lpParameter_02 == (HANDLE)0x0) || (lpParameter_01 == (HANDLE)0x0)) ||
          (lpParameter == (HANDLE)0x0)) ||
         (((lpParameter_00 == (HANDLE)0x0 || (hObject == (HANDLE)0x0)) ||
          ((DAT_c030d614 == (HANDLE)0x0 ||
           ((DAT_c030d5f4 == (HANDLE)0x0 || (DAT_c030d634 == (HANDLE)0x0)))))))) {
        iVar4 = 0;
      }
      if (iVar4 != 0) {
        DAT_c030d604 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c030852c,lpParameter_02,0,
                                    (LPDWORD)0x0);
        DAT_c030d658 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0305140,lpParameter_01,0,
                                    (LPDWORD)0x0);
        DAT_c030d650 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0307ff4,lpParameter_00,0,
                                    (LPDWORD)0x0);
        if (((DAT_c030d604 == (HANDLE)0x0) || (DAT_c030d658 == (HANDLE)0x0)) ||
           (DAT_c030d650 == (HANDLE)0x0)) {
          iVar4 = 0;
        }
      }
    }
  }
  iVar5 = 0;
  local_40 = lpParameter_02;
  local_3c = lpParameter_01;
  local_38 = lpParameter_00;
  local_34[0] = DAT_c030d604;
  local_34[1] = DAT_c030d658;
  local_34[2] = DAT_c030d650;
  do {
    if (iVar4 == 0) goto LAB_c0304e8c;
    DVar2 = WaitForMultipleObjects(6,&local_40,0,0xffffffff);
    if (DVar2 < 3) {
      local_34[DVar2] = hObject;
      iVar5 = iVar5 + 1;
    }
    else {
      iVar4 = 0;
    }
  } while (iVar5 < 3);
  if (iVar4 != 0) {
    DAT_c030d608 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0307a9c,lpParameter,0,(LPDWORD)0x0
                               );
    if (DAT_c030d608 == (HANDLE)0x0) {
      iVar4 = 0;
    }
    local_48 = lpParameter;
    local_44 = DAT_c030d608;
    DVar2 = WaitForMultipleObjects(2,&local_48,0,0xffffffff);
    if (DVar2 != 0) {
      iVar4 = 0;
    }
    if (iVar4 != 0) {
      PmSetSystemPowerState(0,0x10000,0x1000);
      EventModify(DAT_c030d614,3);
      goto LAB_c0304ff8;
    }
  }
LAB_c0304e8c:
  if (DAT_c030d5f8 != (HANDLE)0x0) {
    EventModify(DAT_c030d5f8,3);
  }
  if (DAT_c030d604 != (HANDLE)0x0) {
    WaitForSingleObject(DAT_c030d604,0xffffffff);
    CloseHandle(DAT_c030d604);
  }
  if (DAT_c030d658 != (HANDLE)0x0) {
    WaitForSingleObject(DAT_c030d658,0xffffffff);
    CloseHandle(DAT_c030d658);
  }
  if (DAT_c030d608 != (HANDLE)0x0) {
    WaitForSingleObject(DAT_c030d608,0xffffffff);
    CloseHandle(DAT_c030d608);
  }
  if (DAT_c030d650 != (HANDLE)0x0) {
    WaitForSingleObject(DAT_c030d650,0xffffffff);
    CloseHandle(DAT_c030d650);
  }
  if (DAT_c030d5f8 != (HANDLE)0x0) {
    CloseHandle(DAT_c030d5f8);
  }
  if (DAT_c030d614 != (HANDLE)0x0) {
    CloseHandle(DAT_c030d614);
  }
  if (DAT_c030d634 != (HANDLE)0x0) {
    CloseHandle(DAT_c030d634);
  }
  if (DAT_c030d5f4 != (HANDLE)0x0) {
    CloseHandle(DAT_c030d5f4);
  }
LAB_c0304ff8:
  if (lpParameter_02 != (HANDLE)0x0) {
    CloseHandle(lpParameter_02);
  }
  if (lpParameter_01 != (HANDLE)0x0) {
    CloseHandle(lpParameter_01);
  }
  if (lpParameter != (HANDLE)0x0) {
    CloseHandle(lpParameter);
  }
  if (lpParameter_00 != (HANDLE)0x0) {
    CloseHandle(lpParameter_00);
  }
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
  }
  return iVar4;
}



/* c0305090 PmNotify */

/* Boundary evidence: original MIPS .pdata c0305090..c03050c3. Semantic name remains unreviewed. */

void PmNotify(int param_1,int param_2)

{
                    /* 0x5090  5  PmNotify */
  if (param_1 == 0) {
    FUN_c030552c(param_2);
    FUN_c0305950(param_2);
  }
  return;
}



/* c03050c4 FUN_c03050c4 */

/* Boundary evidence: original MIPS .pdata c03050c4..c030513f. Semantic name remains unreviewed. */

undefined4 FUN_c03050c4(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    if (DAT_c030d65c != (int *)0x0) {
      (**(code **)(*DAT_c030d65c + 4))(DAT_c030d65c,1);
    }
    DAT_c030d65c = (int *)0x0;
  }
  else if (param_2 == 1) {
    DAT_c030d5fc = param_1;
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0305140 FUN_c0305140 */

/* Boundary evidence: original MIPS .pdata c0305140..c03051f3. Semantic name remains unreviewed. */

undefined4 FUN_c0305140(undefined4 param_1)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_18 [2];
  HANDLE local_10;
  undefined4 local_c;
  
  iVar1 = FUN_c0305b50(L"ResumePriority256",local_18);
  if (iVar1 == 0) {
    local_18[0] = 99;
  }
  CeSetThreadPriority(0x41,local_18[0]);
  EventModify(param_1,3);
  local_10 = DAT_c030d634;
  local_c = DAT_c030d5f8;
  while (DVar2 = WaitForMultipleObjects(2,&local_10,0,0xffffffff), DVar2 == 0) {
    FUN_c03099a4();
  }
  return 0;
}



/* c03051f4 PmPowerHandler */

/* Boundary evidence: original MIPS .pdata c03051f4..c030523f. Semantic name remains unreviewed. */

void PmPowerHandler(int param_1)

{
                    /* 0x51f4  6  PmPowerHandler */
  if (param_1 == 0) {
    if (DAT_c030d634 != 0) {
      CeSetPowerOnEvent();
    }
    if (DAT_c030d5f4 != 0) {
      CeSetPowerOnEvent();
    }
  }
  return;
}



/* c0305240 PmRegisterPowerRelationship */

/* Boundary evidence: original MIPS .pdata c0305240..c03053df. Semantic name remains unreviewed. */

undefined4 *
PmRegisterPowerRelationship(wchar_t *param_1,wchar_t *param_2,void *param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  DWORD dwErrCode;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
                    /* 0x5240  7  PmRegisterPowerRelationship */
  puVar4 = (undefined4 *)0x0;
  puVar3 = (undefined4 *)0x0;
  puVar5 = (undefined4 *)0x0;
  dwErrCode = 0;
  if ((((param_1 != (wchar_t *)0x0) && (param_2 != (wchar_t *)0x0)) &&
      (puVar4 = FUN_c0306270(param_1,param_4), puVar4 != (undefined4 *)0x0)) &&
     (puVar3 = FUN_c0306270(param_2,param_4), puVar3 != (undefined4 *)0x0)) {
    puVar1 = FUN_c0307364((void *)*puVar3);
    puVar2 = FUN_c0307364((void *)*puVar4);
    if ((puVar2 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      puVar5 = FUN_c0306948((int)puVar1,(wchar_t *)puVar3[1]);
      if (puVar5 == (undefined4 *)0x0) {
        puVar2 = FUN_c0306948((int)puVar2,(wchar_t *)puVar4[1]);
        if (puVar2 == (undefined4 *)0x0) {
          dwErrCode = 0x57;
        }
        else {
          FUN_c0302594((void *)*puVar3,(wchar_t *)puVar3[1],(int)puVar2,param_3);
          puVar5 = FUN_c0306948((int)puVar1,(wchar_t *)puVar3[1]);
          if (puVar5 == (undefined4 *)0x0) {
            dwErrCode = 0x1f;
          }
          else {
            FUN_c03067a0(puVar5);
          }
        }
        if (puVar2 != (undefined4 *)0x0) {
          FUN_c03067a0(puVar2);
        }
      }
      else {
        FUN_c03067a0(puVar5);
        dwErrCode = 0x50;
      }
      goto LAB_c0305384;
    }
  }
  dwErrCode = 0x57;
LAB_c0305384:
  if (puVar4 != (undefined4 *)0x0) {
    FUN_c0306498(puVar4);
  }
  if (puVar3 != (undefined4 *)0x0) {
    FUN_c0306498(puVar3);
  }
  SetLastError(dwErrCode);
  return puVar5;
}



/* c03053e0 PmReleasePowerRelationship */

/* Boundary evidence: original MIPS .pdata c03053e0..c030543f. Semantic name remains unreviewed. */

undefined4 PmReleasePowerRelationship(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x53e0  8  PmReleasePowerRelationship */
  uVar2 = 0x57;
  if ((param_1 != (undefined4 *)0x0) && (iVar1 = FUN_c03024f8((int)param_1), iVar1 != 0)) {
    FUN_c030288c(*(void **)param_1[0x19],(wchar_t *)*param_1);
    FUN_c03067a0(param_1);
    uVar2 = 0;
  }
  return uVar2;
}



/* c0305440 FUN_c0305440 */

/* Boundary evidence: original MIPS .pdata c0305440..c030552b. Semantic name remains unreviewed. */

void FUN_c0305440(undefined4 *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *local_20;
  
  puVar2 = FUN_c0307364((void *)*param_1);
  if ((wchar_t *)param_1[1] != (wchar_t *)0x0) {
    puVar2 = FUN_c0306948((int)puVar2,(wchar_t *)param_1[1]);
    if (puVar2 != (undefined4 *)0x0) {
      FUN_c0302274(puVar2);
      FUN_c03067a0(puVar2);
    }
    return;
  }
  FUN_c0305c30();
  do {
    bVar1 = false;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      if (puVar3 == (undefined4 *)0x0) {
        FUN_c0305c50();
        return;
      }
      FUN_c0306754((int)puVar3);
      FUN_c0305c50();
      FUN_c0302274(puVar3);
      FUN_c0305c30();
      if (puVar3[0x19] == 0) {
        bVar1 = true;
      }
      else {
        local_20 = (undefined4 *)puVar3[0x1a];
      }
      FUN_c03067a0(puVar3);
      puVar3 = local_20;
    } while (!bVar1);
  } while( true );
}



/* c030552c FUN_c030552c */

/* Boundary evidence: original MIPS .pdata c030552c..c0305623. Semantic name remains unreviewed. */

void FUN_c030552c(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  bVar1 = false;
  FUN_c0305c70();
  do {
    FUN_c0305c30();
    for (puVar4 = DAT_c030d610; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)puVar4[5]) {
      if (puVar4[1] == param_1) {
        puVar2 = FUN_c03061d0((int *)*puVar4);
        iVar3 = FUN_c0306d20(&DAT_c030d610,(int)puVar4);
        if (iVar3 != 0) {
          FUN_c0306c7c(puVar4);
        }
        if (puVar2 != (undefined4 *)0x0) {
          FUN_c0305c50();
          FUN_c0305440(puVar2);
          FUN_c0306498(puVar2);
          FUN_c0305c30();
        }
        break;
      }
    }
    FUN_c0305c50();
    if (puVar4 == (undefined4 *)0x0) {
      bVar1 = true;
    }
    if (bVar1) {
      FUN_c0305c90();
      return;
    }
  } while( true );
}



/* c0305624 PmReleasePowerRequirement */

/* Boundary evidence: original MIPS .pdata c0305624..c03056f7. Semantic name remains unreviewed. */

undefined4 PmReleasePowerRequirement(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
                    /* 0x5624  9  PmReleasePowerRequirement */
  uVar3 = 6;
  puVar2 = (undefined4 *)0x0;
  FUN_c0305c70();
  FUN_c0305c30();
  iVar1 = FUN_c0306ee4(DAT_c030d610,(int)param_1);
  if ((iVar1 != 0) && (iVar1 = GetCallerProcess(), param_1[1] == iVar1)) {
    puVar2 = FUN_c03061d0((int *)*param_1);
    iVar1 = FUN_c0306d20(&DAT_c030d610,(int)param_1);
    if (iVar1 != 0) {
      FUN_c0306c7c(param_1);
    }
  }
  FUN_c0305c50();
  if (puVar2 != (undefined4 *)0x0) {
    FUN_c0305440(puVar2);
    FUN_c0306498(puVar2);
    uVar3 = 0;
  }
  FUN_c0305c90();
  return uVar3;
}



/* c03056f8 PmSetPowerRequirement */

/* Boundary evidence: original MIPS .pdata c03056f8..c030588b. Semantic name remains unreviewed. */

undefined4 * PmSetPowerRequirement(wchar_t *param_1,uint param_2,uint param_3,wchar_t *param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  DWORD dwErrCode;
  
                    /* 0x56f8  12  PmSetPowerRequirement */
  puVar6 = (undefined4 *)0x0;
  bVar1 = false;
  piVar5 = (int *)0x0;
  uVar2 = GetCallerProcess();
  dwErrCode = 0;
  FUN_c0305c70();
  if ((((param_1 == (wchar_t *)0x0) || ((int)param_2 < 0)) || (4 < (int)param_2)) ||
     ((piVar5 = FUN_c0306270(param_1,param_3), piVar5 == (int *)0x0 ||
      (puVar3 = FUN_c0307364((void *)*piVar5), puVar3 == (undefined4 *)0x0)))) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0305c30();
    puVar6 = FUN_c0306a24(piVar5,uVar2,param_2,param_4,param_3 & 0x1000);
    if (puVar6 == (undefined4 *)0x0) {
      dwErrCode = 8;
    }
    else {
      FUN_c0306cb0(&DAT_c030d610,(int)puVar6);
      if (((wchar_t *)puVar6[3] == (wchar_t *)0x0) ||
         (iVar4 = wcscmp((wchar_t *)puVar6[3],(wchar_t *)*DAT_c030d654), iVar4 == 0)) {
        bVar1 = true;
      }
    }
    FUN_c0305c50();
    if (bVar1) {
      FUN_c0305440(piVar5);
    }
  }
  FUN_c0305c90();
  if (piVar5 != (int *)0x0) {
    FUN_c0306498(piVar5);
  }
  SetLastError(dwErrCode);
  return puVar6;
}



/* c030588c FUN_c030588c */

/* Boundary evidence: original MIPS .pdata c030588c..c03058af. Semantic name remains unreviewed. */

void FUN_c030588c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  WriteMsgQueue(*param_1,param_2,param_3,0,0);
  return;
}



/* c03058b0 FUN_c03058b0 */

/* Boundary evidence: original MIPS .pdata c03058b0..c030594f. Semantic name remains unreviewed. */

void FUN_c03058b0(uint *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = param_1[2] + 0xc;
  if (uVar2 < 0x10) {
    uVar2 = 0x10;
  }
  FUN_c0305c30();
  for (puVar1 = DAT_c030d60c; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[3]) {
    if ((puVar1[1] & *param_1) != 0) {
      WriteMsgQueue(*puVar1,param_1,uVar2,0,0);
    }
  }
  FUN_c0305c50();
  return;
}



/* c0305950 FUN_c0305950 */

/* Boundary evidence: original MIPS .pdata c0305950..c03059db. Semantic name remains unreviewed. */

void FUN_c0305950(int param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  
  bVar1 = false;
  FUN_c0305c30();
  piVar3 = DAT_c030d60c;
  piVar2 = DAT_c030d60c;
joined_r0xc0305980:
  do {
    if (piVar3 == (int *)0x0) {
      bVar1 = true;
      piVar3 = piVar2;
    }
    else {
      if (piVar3[2] != param_1) {
        piVar3 = (int *)piVar3[3];
        goto joined_r0xc0305980;
      }
      FUN_c03070f8((int *)&DAT_c030d60c,piVar3);
      piVar3 = DAT_c030d60c;
    }
    piVar2 = piVar3;
    if (bVar1) {
      FUN_c0305c50();
      return;
    }
  } while( true );
}



/* c03059dc PmRequestPowerNotifications */

/* Boundary evidence: original MIPS .pdata c03059dc..c0305aa3. Semantic name remains unreviewed. */

int * PmRequestPowerNotifications(int param_1,uint param_2)

{
  int iVar1;
  DWORD dwErrCode;
  int *piVar2;
  
                    /* 0x59dc  10  PmRequestPowerNotifications */
  iVar1 = GetCallerProcess();
  dwErrCode = 0;
  piVar2 = (int *)0x0;
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    piVar2 = FUN_c0306f68(param_1,iVar1);
    if (piVar2 == (int *)0x0) {
      dwErrCode = GetLastError();
    }
    else {
      piVar2[1] = param_2;
      FUN_c0305c30();
      FUN_c0307088(&DAT_c030d60c,(int)piVar2);
      FUN_c03086cc(piVar2,param_2);
      FUN_c0305c50();
    }
  }
  SetLastError(dwErrCode);
  return piVar2;
}



/* c0305aa4 PmStopPowerNotifications */

/* Boundary evidence: original MIPS .pdata c0305aa4..c0305b03. Semantic name remains unreviewed. */

undefined4 PmStopPowerNotifications(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x5aa4  14  PmStopPowerNotifications */
  uVar2 = 0x57;
  if (param_1 != (int *)0x0) {
    FUN_c0305c30();
    iVar1 = FUN_c03070f8(&DAT_c030d60c,param_1);
    uVar2 = 0;
    if (iVar1 == 0) {
      uVar2 = 2;
    }
    FUN_c0305c50();
  }
  return uVar2;
}



/* c0305b04 FUN_c0305b04 */

/* Boundary evidence: original MIPS .pdata c0305b04..c0305b4f. Semantic name remains unreviewed. */

LSTATUS FUN_c0305b04(HKEY param_1,LPCWSTR param_2,LPBYTE param_3,LPDWORD param_4,DWORD param_5)

{
  LSTATUS LVar1;
  DWORD local_10 [2];
  
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,local_10,param_3,param_4);
  if ((LVar1 == 0) && (local_10[0] != param_5)) {
    LVar1 = 0xd;
  }
  return LVar1;
}



/* c0305b50 FUN_c0305b50 */

/* Boundary evidence: original MIPS .pdata c0305b50..c0305c2f. Semantic name remains unreviewed. */

undefined4 FUN_c0305b50(LPCWSTR param_1,undefined4 *param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_28;
  DWORD local_24;
  DWORD local_20;
  undefined4 local_1c;
  
  uVar2 = 0;
  local_28 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Power",0,0,&local_28)
  ;
  if (LVar1 == 0) {
    local_24 = 4;
    LVar1 = RegQueryValueExW(local_28,param_1,(LPDWORD)0x0,&local_20,(LPBYTE)&local_1c,&local_24);
    if ((LVar1 == 0) && (local_20 == 4)) {
      uVar2 = 1;
      *param_2 = local_1c;
    }
    RegCloseKey(local_28);
  }
  return uVar2;
}



/* c0305c30 FUN_c0305c30 */

/* Boundary evidence: original MIPS .pdata c0305c30..c0305c4f. Semantic name remains unreviewed. */

void FUN_c0305c30(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return;
}



/* c0305c50 FUN_c0305c50 */

/* Boundary evidence: original MIPS .pdata c0305c50..c0305c6f. Semantic name remains unreviewed. */

void FUN_c0305c50(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return;
}



/* c0305c70 FUN_c0305c70 */

/* Boundary evidence: original MIPS .pdata c0305c70..c0305c8f. Semantic name remains unreviewed. */

void FUN_c0305c70(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d63c);
  return;
}



/* c0305c90 FUN_c0305c90 */

/* Boundary evidence: original MIPS .pdata c0305c90..c0305caf. Semantic name remains unreviewed. */

void FUN_c0305c90(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d63c);
  return;
}



/* c0305cb0 FUN_c0305cb0 */

/* Boundary evidence: original MIPS .pdata c0305cb0..c0305cd7. Semantic name remains unreviewed. */

void FUN_c0305cb0(SIZE_T param_1)

{
  HeapAlloc(DAT_c030d618,0,param_1);
  return;
}



/* c0305cd8 FUN_c0305cd8 */

/* Boundary evidence: original MIPS .pdata c0305cd8..c0305cff. Semantic name remains unreviewed. */

void FUN_c0305cd8(LPVOID param_1)

{
  HeapFree(DAT_c030d618,0,param_1);
  return;
}



/* c0305d00 FUN_c0305d00 */

undefined4 FUN_c0305d00(int *param_1,int *param_2,int param_3,uint param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  *param_2 = 0;
  iVar4 = 0;
  if (0 < param_3) {
    do {
      uVar2 = (uint)*(ushort *)*param_1;
      if ((uVar2 < 0x30) || (0x39 < uVar2)) {
        if ((uVar2 < 0x41) || (0x46 < uVar2)) {
          if ((uVar2 < 0x61) || (0x66 < uVar2)) {
            return 0;
          }
          iVar3 = *param_2 * 0x10 + uVar2 + -0x57;
        }
        else {
          iVar3 = *param_2 * 0x10 + uVar2 + -0x37;
        }
      }
      else {
        iVar3 = *param_2 * 0x10 + uVar2 + -0x30;
      }
      *param_2 = iVar3;
      iVar4 = iVar4 + 1;
      *param_1 = *param_1 + 2;
    } while (iVar4 < param_3);
  }
  if ((param_4 != 0) &&
     (uVar1 = *(ushort *)*param_1, *param_1 = (int)((ushort *)*param_1 + 1), uVar1 != param_4)) {
    return 0;
  }
  return 1;
}



/* c0305dec FUN_c0305dec */

/* Boundary evidence: original MIPS .pdata c0305dec..c0305f9f. Semantic name remains unreviewed. */

undefined4 FUN_c0305dec(int param_1,int *param_2)

{
  int iVar1;
  int local_res0 [4];
  undefined1 local_10 [8];
  
  local_res0[0] = param_1;
  iVar1 = FUN_c0305d00(local_res0,param_2,8,0x2d);
  if ((iVar1 != 0) && (iVar1 = FUN_c0305d00(local_res0,(int *)local_10,4,0x2d), iVar1 != 0)) {
    *(short *)(param_2 + 1) = (short)local_10._0_4_;
    iVar1 = FUN_c0305d00(local_res0,(int *)local_10,4,0x2d);
    if (iVar1 != 0) {
      *(short *)((int)param_2 + 6) = (short)local_10._0_4_;
      iVar1 = FUN_c0305d00(local_res0,(int *)local_10,2,0);
      if (iVar1 != 0) {
        *(undefined1 *)(param_2 + 2) = local_10[0];
        iVar1 = FUN_c0305d00(local_res0,(int *)local_10,2,0x2d);
        if (iVar1 != 0) {
          *(undefined1 *)((int)param_2 + 9) = local_10[0];
          iVar1 = FUN_c0305d00(local_res0,(int *)local_10,2,0);
          if (iVar1 != 0) {
            *(undefined1 *)((int)param_2 + 10) = local_10[0];
            iVar1 = FUN_c0305d00(local_res0,(int *)local_10,2,0);
            if (iVar1 != 0) {
              *(undefined1 *)((int)param_2 + 0xb) = local_10[0];
              iVar1 = FUN_c0305d00(local_res0,(int *)local_10,2,0);
              if (iVar1 != 0) {
                *(undefined1 *)(param_2 + 3) = local_10[0];
                iVar1 = FUN_c0305d00(local_res0,(int *)local_10,2,0);
                if (iVar1 != 0) {
                  *(undefined1 *)((int)param_2 + 0xd) = local_10[0];
                  iVar1 = FUN_c0305d00(local_res0,(int *)local_10,2,0);
                  if (iVar1 != 0) {
                    *(undefined1 *)((int)param_2 + 0xe) = local_10[0];
                    iVar1 = FUN_c0305d00(local_res0,(int *)local_10,2,0);
                    if (iVar1 != 0) {
                      *(undefined1 *)((int)param_2 + 0xf) = local_10[0];
                      return 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



/* c0305fa0 FUN_c0305fa0 */

/* Boundary evidence: original MIPS .pdata c0305fa0..c0306007. Semantic name remains unreviewed. */

void FUN_c0305fa0(short *param_1,int *param_2)

{
  if (*param_1 == 0x7b) {
    FUN_c0305dec((int)(param_1 + 1),param_2);
  }
  return;
}



/* c0306008 FUN_c0306008 */

/* Boundary evidence: original MIPS .pdata c0306008..c0306013. Semantic name remains unreviewed. */

undefined4 FUN_c0306008(void)

{
  return 1;
}



/* c0306014 FUN_c0306014 */

/* Boundary evidence: original MIPS .pdata c0306014..c03060b3. Semantic name remains unreviewed. */

int FUN_c0306014(int *param_1)

{
  int iVar1;
  size_t sVar2;
  
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 8;
    if ((wchar_t *)param_1[1] != (wchar_t *)0x0) {
      sVar2 = wcslen((wchar_t *)param_1[1]);
      iVar1 = (sVar2 + 5) * 2;
    }
    if (*param_1 != 0) {
      iVar1 = iVar1 + 0x10;
    }
  }
  return iVar1;
}



/* c03060b4 FUN_c03060b4 */

/* Boundary evidence: original MIPS .pdata c03060b4..c03060bf. Semantic name remains unreviewed. */

undefined4 FUN_c03060b4(void)

{
  return 1;
}



/* c03060c0 FUN_c03060c0 */

/* Boundary evidence: original MIPS .pdata c03060c0..c03061c3. Semantic name remains unreviewed. */

undefined4 * FUN_c03060c0(int *param_1,undefined4 *param_2,uint param_3)

{
  uint _Size;
  int iVar1;
  undefined4 *puVar2;
  
  _Size = FUN_c0306014(param_1);
  if (param_3 < _Size) {
    param_2 = (undefined4 *)0x0;
  }
  else {
    memset(param_2,0,_Size);
    *param_2 = 0;
    param_2[1] = 0;
    iVar1 = 8;
    puVar2 = (undefined4 *)*param_1;
    if (puVar2 != (undefined4 *)0x0) {
      param_2[2] = *puVar2;
      param_2[3] = puVar2[1];
      param_2[4] = puVar2[2];
      param_2[5] = puVar2[3];
      *param_2 = param_2 + 2;
      iVar1 = 0x18;
    }
    if ((wchar_t *)param_1[1] != (wchar_t *)0x0) {
      wcscpy((wchar_t *)(iVar1 + (int)param_2),(wchar_t *)param_1[1]);
      param_2[1] = (wchar_t *)(iVar1 + (int)param_2);
    }
  }
  return param_2;
}



/* c03061c4 FUN_c03061c4 */

/* Boundary evidence: original MIPS .pdata c03061c4..c03061cf. Semantic name remains unreviewed. */

undefined4 FUN_c03061c4(void)

{
  return 1;
}



/* c03061d0 FUN_c03061d0 */

/* Boundary evidence: original MIPS .pdata c03061d0..c030626f. Semantic name remains unreviewed. */

undefined4 * FUN_c03061d0(int *param_1)

{
  SIZE_T dwBytes;
  undefined4 *lpMem;
  undefined4 *puVar1;
  
  dwBytes = FUN_c0306014(param_1);
  if (dwBytes == 0) {
    lpMem = (undefined4 *)0x0;
  }
  else {
    lpMem = HeapAlloc(DAT_c030d618,0,dwBytes);
  }
  if ((lpMem != (undefined4 *)0x0) &&
     (puVar1 = FUN_c03060c0(param_1,lpMem,dwBytes), puVar1 == (undefined4 *)0x0)) {
    HeapFree(DAT_c030d618,0,lpMem);
    lpMem = (undefined4 *)0x0;
  }
  return lpMem;
}



/* c0306270 FUN_c0306270 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0306270..c030647f. Semantic name remains unreviewed. */

undefined4 * FUN_c0306270(wchar_t *param_1,uint param_2)

{
  wint_t wVar1;
  int iVar2;
  size_t sVar3;
  wchar_t **ppwVar4;
  uint uVar5;
  wchar_t *local_48 [3];
  wchar_t **local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  local_28 = DAT_c030d5b0;
  local_48[1] = (wchar_t *)0x0;
  if ((param_2 & 1) == 0) {
    FUN_c0308a9c(DAT_c030d5b0);
    return (undefined4 *)0x0;
  }
  if (*param_1 == L'{') {
    iVar2 = FUN_c0305fa0(param_1,&local_38);
    if (iVar2 == 0) {
      param_1 = (wchar_t *)0x0;
      local_48[0] = param_1;
    }
    else {
      while ((*param_1 != L'}' && (*param_1 != L'\0'))) {
        param_1 = param_1 + 1;
        local_48[0] = param_1;
      }
      if ((*param_1 != L'}') || (local_48[0] = param_1 + 1, *local_48[0] != L'\\'))
      goto LAB_c0306438;
      param_1 = param_1 + 2;
      local_48[0] = param_1;
    }
  }
  else {
    local_38 = DAT_c030d14c;
    local_34 = DAT_c030d150;
    local_30 = DAT_c030d154;
    local_2c = DAT_c030d158;
  }
  if (*param_1 != L'\0') {
    local_48[2] = (wchar_t *)&local_38;
    sVar3 = wcslen(param_1);
    ppwVar4 = local_48 + ((int)((sVar3 + 1) * 2 + 7) >> 3) * -2;
    for (uVar5 = 0; uVar5 < sVar3; uVar5 = uVar5 + 1) {
      wVar1 = towlower(param_1[uVar5]);
      *(wint_t *)(uVar5 * 2 + (int)ppwVar4) = wVar1;
    }
    *(undefined2 *)(sVar3 * 2 + (int)ppwVar4) = 0;
    local_3c = ppwVar4;
    if (ppwVar4 != (wchar_t **)0x0) {
      local_48[1] = (wchar_t *)FUN_c03061d0((int *)(local_48 + 2));
    }
  }
LAB_c0306438:
  FUN_c0308a9c(local_28);
  return (undefined4 *)local_48[1];
}



/* c0306480 FUN_c0306480 */

/* Boundary evidence: original MIPS .pdata c0306480..c030648b. Semantic name remains unreviewed. */

undefined4 FUN_c0306480(void)

{
  return 1;
}



/* c030648c FUN_c030648c */

/* Boundary evidence: original MIPS .pdata c030648c..c0306497. Semantic name remains unreviewed. */

undefined4 FUN_c030648c(void)

{
  return 1;
}



/* c0306498 FUN_c0306498 */

/* Boundary evidence: original MIPS .pdata c0306498..c03064c7. Semantic name remains unreviewed. */

void FUN_c0306498(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    HeapFree(DAT_c030d618,0,param_1);
  }
  return;
}



/* c03064c8 FUN_c03064c8 */

/* Boundary evidence: original MIPS .pdata c03064c8..c030657b. Semantic name remains unreviewed. */

undefined4 FUN_c03064c8(undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  if ((wchar_t *)param_1[1] == (wchar_t *)0x0) {
    iVar1 = param_2[1];
  }
  else {
    if ((wchar_t *)param_2[1] == (wchar_t *)0x0) {
      return 0;
    }
    iVar1 = wcscmp((wchar_t *)param_1[1],(wchar_t *)param_2[1]);
  }
  if (iVar1 == 0) {
    if ((void *)*param_1 == (void *)0x0) {
      iVar1 = *param_2;
    }
    else {
      if ((void *)*param_2 == (void *)0x0) {
        return 0;
      }
      iVar1 = memcmp((void *)*param_1,(void *)*param_2,0x10);
    }
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c030657c FUN_c030657c */

/* WARNING: Removing unreachable block (ram,0xc0306680) */
/* Boundary evidence: original MIPS .pdata c030657c..c03066cf. Semantic name remains unreviewed. */

undefined4 * FUN_c030657c(wchar_t *param_1)

{
  size_t sVar1;
  undefined4 *_Dst;
  
  sVar1 = wcslen(param_1);
  _Dst = HeapAlloc(DAT_c030d618,0,(sVar1 + 0x39) * 2);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x70);
    wcscpy((wchar_t *)(_Dst + 0x1c),param_1);
    *_Dst = _Dst + 0x1c;
    _Dst[1] = 0;
    _Dst[2] = 0xffffffff;
    _Dst[3] = 0xffffffff;
    _Dst[4] = 0xffffffff;
    _Dst[5] = 0;
    _Dst[6] = 0;
    _Dst[7] = 0xffffffff;
    _Dst[8] = 0;
    _Dst[9] = 0;
    _Dst[0x16] = 1;
    _Dst[0x17] = 0xffffffff;
    _Dst[0x19] = 0;
    _Dst[0x1a] = 0;
    _Dst[0x1b] = 0;
  }
  return _Dst;
}



/* c03066d0 FUN_c03066d0 */

/* Boundary evidence: original MIPS .pdata c03066d0..c03066db. Semantic name remains unreviewed. */

undefined4 FUN_c03066d0(void)

{
  return 1;
}



/* c03066dc FUN_c03066dc */

/* Boundary evidence: original MIPS .pdata c03066dc..c0306753. Semantic name remains unreviewed. */

undefined4 FUN_c03066dc(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    if (*(LPVOID *)((int)param_1 + 0x24) != (LPVOID)0x0) {
      FUN_c03067a0(*(LPVOID *)((int)param_1 + 0x24));
    }
    if (*(int *)((int)param_1 + 0x5c) != -1) {
      (**(code **)(*(int *)((int)param_1 + 0x60) + 8))();
    }
    HeapFree(DAT_c030d618,0,param_1);
  }
  return 1;
}



/* c0306754 FUN_c0306754 */

/* Boundary evidence: original MIPS .pdata c0306754..c030679f. Semantic name remains unreviewed. */

void FUN_c0306754(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return;
}



/* c03067a0 FUN_c03067a0 */

/* Boundary evidence: original MIPS .pdata c03067a0..c030680f. Semantic name remains unreviewed. */

void FUN_c03067a0(LPVOID param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  iVar1 = *(int *)((int)param_1 + 0x58) + -1;
  *(int *)((int)param_1 + 0x58) = iVar1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  if (iVar1 == 0) {
    FUN_c03066dc(param_1);
  }
  return;
}



/* c0306810 FUN_c0306810 */

/* Boundary evidence: original MIPS .pdata c0306810..c0306893. Semantic name remains unreviewed. */

undefined4 FUN_c0306810(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  *(int *)(param_2 + 100) = param_1;
  *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_2 + 0x6c) = 0;
  if (*(int *)(param_1 + 4) != 0) {
    *(int *)(*(int *)(param_1 + 4) + 0x6c) = param_2;
  }
  *(int *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(param_1 + 0x10);
  FUN_c0306754(param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return 1;
}



/* c0306894 FUN_c0306894 */

/* Boundary evidence: original MIPS .pdata c0306894..c0306947. Semantic name remains unreviewed. */

undefined4 FUN_c0306894(LPVOID param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  if (*(int *)((int)param_1 + 0x6c) == 0) {
    if (*(int *)((int)param_1 + 0x68) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x68) + 0x6c) = 0;
    }
    *(undefined4 *)(*(int *)((int)param_1 + 100) + 4) = *(undefined4 *)((int)param_1 + 0x68);
  }
  else {
    *(undefined4 *)(*(int *)((int)param_1 + 0x6c) + 0x68) = *(undefined4 *)((int)param_1 + 0x68);
  }
  if (*(int *)((int)param_1 + 0x68) == 0) {
    if (*(int *)((int)param_1 + 0x6c) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x6c) + 0x68) = 0;
    }
  }
  else {
    *(undefined4 *)(*(int *)((int)param_1 + 0x68) + 0x6c) = *(undefined4 *)((int)param_1 + 0x6c);
  }
  *(undefined4 *)((int)param_1 + 0x68) = 0;
  *(undefined4 *)((int)param_1 + 0x6c) = 0;
  *(undefined4 *)((int)param_1 + 100) = 0;
  FUN_c03067a0(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return 1;
}



/* c0306948 FUN_c0306948 */

/* Boundary evidence: original MIPS .pdata c0306948..c0306a17. Semantic name remains unreviewed. */

undefined4 * FUN_c0306948(int param_1,wchar_t *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  puVar2 = *(undefined4 **)(param_1 + 4);
  do {
    if (puVar2 == (undefined4 *)0x0) {
LAB_c03069d8:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
      return puVar2;
    }
    iVar1 = wcscmp((wchar_t *)*puVar2,param_2);
    if (iVar1 == 0) {
      FUN_c0306754((int)puVar2);
      goto LAB_c03069d8;
    }
    puVar2 = (undefined4 *)puVar2[0x1a];
  } while( true );
}



/* c0306a18 FUN_c0306a18 */

/* Boundary evidence: original MIPS .pdata c0306a18..c0306a23. Semantic name remains unreviewed. */

undefined4 FUN_c0306a18(void)

{
  return 1;
}



/* c0306a24 FUN_c0306a24 */

/* Boundary evidence: original MIPS .pdata c0306a24..c0306c6f. Semantic name remains unreviewed. */

undefined4 *
FUN_c0306a24(int *param_1,undefined4 param_2,uint param_3,wchar_t *param_4,undefined4 param_5)

{
  bool bVar1;
  wint_t wVar2;
  uint uVar3;
  size_t sVar4;
  undefined4 *_Dst;
  SIZE_T dwBytes;
  uint uVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)0x0;
  uVar3 = FUN_c0306014(param_1);
  dwBytes = uVar3 + 0x1c;
  sVar4 = param_3;
  if (param_4 != (wchar_t *)0x0) {
    sVar4 = wcslen(param_4);
    dwBytes = (sVar4 + 1) * 2 + dwBytes;
  }
  _Dst = HeapAlloc(DAT_c030d618,0,dwBytes);
  bVar1 = _Dst != (undefined4 *)0x0;
  uVar5 = param_3;
  if (bVar1) {
    if ((param_1 != (int *)0x0) &&
       (puVar6 = FUN_c03060c0(param_1,_Dst + 7,uVar3), puVar6 == (undefined4 *)0x0)) {
      bVar1 = false;
    }
    if (bVar1) {
      if (param_4 == (wchar_t *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = (int)_Dst + uVar3 + 0x1c;
        for (uVar3 = 0; uVar3 < sVar4; uVar3 = uVar3 + 1) {
          wVar2 = towlower(param_4[uVar3]);
          *(wint_t *)(uVar3 * 2 + uVar5) = wVar2;
        }
        *(undefined2 *)(sVar4 * 2 + uVar5) = 0;
      }
    }
  }
  if (bVar1) {
    memset(_Dst,0,0x1c);
    *_Dst = puVar6;
    _Dst[1] = param_2;
    _Dst[2] = param_3;
    _Dst[3] = uVar5;
    _Dst[4] = param_5;
    _Dst[5] = 0;
    _Dst[6] = 0;
  }
  else if (_Dst != (undefined4 *)0x0) {
    HeapFree(DAT_c030d618,0,_Dst);
    _Dst = (undefined4 *)0x0;
  }
  return _Dst;
}



/* c0306c70 FUN_c0306c70 */

/* Boundary evidence: original MIPS .pdata c0306c70..c0306c7b. Semantic name remains unreviewed. */

undefined4 FUN_c0306c70(void)

{
  return 1;
}



/* c0306c7c FUN_c0306c7c */

/* Boundary evidence: original MIPS .pdata c0306c7c..c0306caf. Semantic name remains unreviewed. */

undefined4 FUN_c0306c7c(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    HeapFree(DAT_c030d618,0,param_1);
  }
  return 1;
}



/* c0306cb0 FUN_c0306cb0 */

/* Boundary evidence: original MIPS .pdata c0306cb0..c0306d1f. Semantic name remains unreviewed. */

undefined4 FUN_c0306cb0(int *param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  *(int *)(param_2 + 0x14) = *param_1;
  *(undefined4 *)(param_2 + 0x18) = 0;
  if (*param_1 != 0) {
    *(int *)(*param_1 + 0x18) = param_2;
  }
  *param_1 = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return 1;
}



/* c0306d20 FUN_c0306d20 */

/* Boundary evidence: original MIPS .pdata c0306d20..c0306dcf. Semantic name remains unreviewed. */

undefined4 FUN_c0306d20(undefined4 *param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  if (*(int *)(param_2 + 0x18) == 0) {
    if (*(int *)(param_2 + 0x14) != 0) {
      *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x18) = 0;
    }
    *param_1 = *(undefined4 *)(param_2 + 0x14);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0x18) + 0x14) = *(undefined4 *)(param_2 + 0x14);
  }
  if (*(int *)(param_2 + 0x14) == 0) {
    if (*(int *)(param_2 + 0x18) != 0) {
      *(undefined4 *)(*(int *)(param_2 + 0x18) + 0x14) = 0;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x18) = *(undefined4 *)(param_2 + 0x18);
  }
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return 1;
}



/* c0306dd0 FUN_c0306dd0 */

/* Boundary evidence: original MIPS .pdata c0306dd0..c0306ed7. Semantic name remains unreviewed. */

undefined4 * FUN_c0306dd0(undefined4 *param_1,int *param_2,wchar_t *param_3)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)param_1[5]) {
    iVar1 = FUN_c03064c8((undefined4 *)*param_1,param_2);
    if (iVar1 != 0) {
      if (param_3 == (wchar_t *)0x0) {
        iVar1 = param_1[3];
      }
      else {
        if ((wchar_t *)param_1[3] == (wchar_t *)0x0) goto LAB_c0306e70;
        iVar1 = wcscmp(param_3,(wchar_t *)param_1[3]);
      }
      if (iVar1 == 0) break;
    }
LAB_c0306e70:
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return param_1;
}



/* c0306ed8 FUN_c0306ed8 */

/* Boundary evidence: original MIPS .pdata c0306ed8..c0306ee3. Semantic name remains unreviewed. */

undefined4 FUN_c0306ed8(void)

{
  return 1;
}



/* c0306ee4 FUN_c0306ee4 */

/* Boundary evidence: original MIPS .pdata c0306ee4..c0306f67. Semantic name remains unreviewed. */

undefined4 FUN_c0306ee4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  do {
    if (param_1 == 0) {
LAB_c0306f40:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
      return uVar1;
    }
    if (param_1 == param_2) {
      uVar1 = 1;
      goto LAB_c0306f40;
    }
    param_1 = *(int *)(param_1 + 0x14);
  } while( true );
}



/* c0306f68 FUN_c0306f68 */

/* Boundary evidence: original MIPS .pdata c0306f68..c0307033. Semantic name remains unreviewed. */

int * FUN_c0306f68(undefined4 param_1,int param_2)

{
  int *_Dst;
  int iVar1;
  undefined4 local_30 [4];
  undefined4 local_20;
  
  _Dst = HeapAlloc(DAT_c030d618,0,0x14);
  if (_Dst != (int *)0x0) {
    memset(_Dst,0,0x14);
    _Dst[2] = param_2;
    _Dst[3] = 0;
    _Dst[4] = 0;
    memset(local_30,0,0x14);
    local_30[0] = 0x14;
    local_20 = 0;
    iVar1 = OpenMsgQueue(param_2,param_1,local_30);
    *_Dst = iVar1;
    if (iVar1 == 0) {
      HeapFree(DAT_c030d618,0,_Dst);
      _Dst = (int *)0x0;
    }
  }
  return _Dst;
}



/* c0307034 FUN_c0307034 */

/* Boundary evidence: original MIPS .pdata c0307034..c0307087. Semantic name remains unreviewed. */

undefined4 FUN_c0307034(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      CloseMsgQueue();
    }
    HeapFree(DAT_c030d618,0,param_1);
  }
  return 1;
}



/* c0307088 FUN_c0307088 */

/* Boundary evidence: original MIPS .pdata c0307088..c03070f7. Semantic name remains unreviewed. */

undefined4 FUN_c0307088(int *param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  *(int *)(param_2 + 0xc) = *param_1;
  *(undefined4 *)(param_2 + 0x10) = 0;
  if (*param_1 != 0) {
    *(int *)(*param_1 + 0x10) = param_2;
  }
  *param_1 = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return 1;
}



/* c03070f8 FUN_c03070f8 */

/* Boundary evidence: original MIPS .pdata c03070f8..c03071ef. Semantic name remains unreviewed. */

undefined4 FUN_c03070f8(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    do {
      if (piVar1 == param_2) break;
      piVar1 = (int *)piVar1[3];
    } while (piVar1 != (int *)0x0);
    if (piVar1 != (int *)0x0) {
      if (param_2[4] == 0) {
        if (param_2[3] != 0) {
          *(undefined4 *)(param_2[3] + 0x10) = 0;
        }
        *param_1 = param_2[3];
      }
      else {
        *(int *)(param_2[4] + 0xc) = param_2[3];
      }
      if (param_2[3] == 0) {
        if (param_2[4] != 0) {
          *(undefined4 *)(param_2[4] + 0xc) = 0;
        }
      }
      else {
        *(int *)(param_2[3] + 0x10) = param_2[4];
      }
      param_2[3] = 0;
      param_2[4] = 0;
      FUN_c0307034(param_2);
      goto LAB_c03071c8;
    }
  }
  uVar2 = 0;
LAB_c03071c8:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return uVar2;
}



/* c03071f0 FUN_c03071f0 */

/* Boundary evidence: original MIPS .pdata c03071f0..c030731b. Semantic name remains unreviewed. */

undefined4 * FUN_c03071f0(undefined4 *param_1)

{
  undefined4 *lpMem;
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  
  lpMem = HeapAlloc(DAT_c030d618,0,0x28);
  memset(&local_30,0,0x14);
  local_30 = 0x14;
  local_2c = 0;
  local_24 = 0x360;
  local_20 = 1;
  iVar1 = CreateMsgQueue(0,&local_30);
  if (iVar1 == 0) {
    GetLastError();
  }
  if (lpMem != (undefined4 *)0x0) {
    if (iVar1 != 0) {
      memset(lpMem,0,4);
      lpMem[6] = *param_1;
      lpMem[7] = param_1[1];
      lpMem[8] = param_1[2];
      lpMem[9] = param_1[3];
      *lpMem = lpMem + 6;
      lpMem[2] = iVar1;
      lpMem[3] = 0;
      lpMem[4] = 0;
      lpMem[1] = 0;
      lpMem[5] = 0;
      return lpMem;
    }
    HeapFree(DAT_c030d618,0,lpMem);
  }
  if (iVar1 != 0) {
    CloseMsgQueue(iVar1);
  }
  return (undefined4 *)0x0;
}



/* c030731c FUN_c030731c */

/* Boundary evidence: original MIPS .pdata c030731c..c0307363. Semantic name remains unreviewed. */

void FUN_c030731c(LPVOID param_1)

{
  if (*(int *)((int)param_1 + 8) != 0) {
    CloseMsgQueue();
  }
  HeapFree(DAT_c030d618,0,param_1);
  return;
}



/* c0307364 FUN_c0307364 */

/* Boundary evidence: original MIPS .pdata c0307364..c03073fb. Semantic name remains unreviewed. */

undefined4 * FUN_c0307364(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_c030d638;
  while ((puVar2 != (undefined4 *)0x0 && (iVar1 = memcmp((void *)*puVar2,param_1,0x10), iVar1 != 0))
        ) {
    puVar2 = (undefined4 *)puVar2[5];
  }
  return puVar2;
}



/* c03073fc FUN_c03073fc */

/* Boundary evidence: original MIPS .pdata c03073fc..c0307407. Semantic name remains unreviewed. */

undefined4 FUN_c03073fc(void)

{
  return 1;
}



/* c0307408 FUN_c0307408 */

/* Boundary evidence: original MIPS .pdata c0307408..c0307557. Semantic name remains unreviewed. */

int * FUN_c0307408(wchar_t *param_1)

{
  wint_t wVar1;
  size_t sVar2;
  int *_Dst;
  uint uVar3;
  int *piVar4;
  
  sVar2 = wcslen(param_1);
  _Dst = HeapAlloc(DAT_c030d618,0,(sVar2 + 7) * 2);
  if (_Dst != (int *)0x0) {
    memset(_Dst,0,0xc);
    piVar4 = _Dst + 3;
    for (uVar3 = 0; uVar3 < sVar2; uVar3 = uVar3 + 1) {
      wVar1 = towlower(param_1[uVar3]);
      *(wint_t *)(uVar3 * 2 + (int)piVar4) = wVar1;
    }
    *(undefined2 *)(sVar2 * 2 + (int)piVar4) = 0;
    *_Dst = (int)piVar4;
  }
  return _Dst;
}



/* c0307558 FUN_c0307558 */

/* Boundary evidence: original MIPS .pdata c0307558..c0307563. Semantic name remains unreviewed. */

undefined4 FUN_c0307558(void)

{
  return 1;
}



/* c0307564 FUN_c0307564 */

/* Boundary evidence: original MIPS .pdata c0307564..c030756f. Semantic name remains unreviewed. */

undefined4 FUN_c0307564(void)

{
  return 1;
}



/* c0307570 FUN_c0307570 */

/* Boundary evidence: original MIPS .pdata c0307570..c03075a3. Semantic name remains unreviewed. */

undefined4 FUN_c0307570(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    HeapFree(DAT_c030d618,0,param_1);
  }
  return 1;
}



/* c03075a4 FUN_c03075a4 */

/* Boundary evidence: original MIPS .pdata c03075a4..c03078bb. Semantic name remains unreviewed. */

undefined4 * FUN_c03075a4(wchar_t *param_1,int param_2,wchar_t *param_3)

{
  wchar_t wVar1;
  bool bVar2;
  size_t sVar3;
  undefined4 *_Dst;
  int iVar4;
  HANDLE pvVar5;
  long lVar6;
  wchar_t *_Str;
  uint uVar7;
  uint uVar8;
  wchar_t *local_240 [2];
  wchar_t awStack_238 [259];
  undefined2 local_32;
  uint local_30;
  
  bVar2 = true;
  uVar8 = 0;
  wVar1 = *param_3;
  _Str = param_3;
  local_30 = DAT_c030d5b0;
  while (wVar1 != L'\0') {
    sVar3 = wcslen(_Str);
    _Str = _Str + sVar3 + 1;
    uVar8 = uVar8 + 1;
    wVar1 = *_Str;
  }
  sVar3 = wcslen(param_1);
  _Dst = HeapAlloc(DAT_c030d618,0,(uVar8 * 2 + sVar3 + 0x15) * 2);
  if (_Dst == (undefined4 *)0x0) goto LAB_c0307884;
  memset(_Dst,0,0x24);
  _Dst[1] = param_2;
  if (param_2 == 0) {
    _Dst[2] = 0xffffffff;
  }
  else {
    _Dst[2] = param_2;
  }
  _Dst[6] = _Dst + 9;
  *_Dst = _Dst + 9 + uVar8 + 1;
  iVar4 = _snwprintf(awStack_238,0x104,L"PowerManager/ActivityTimer/%s",param_1);
  if (iVar4 == -1) {
    bVar2 = false;
LAB_c03076b4:
    local_32 = 0;
    pvVar5 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,awStack_238);
    _Dst[4] = pvVar5;
    if ((!bVar2) ||
       (iVar4 = _snwprintf(awStack_238,0x104,L"PowerManager/%s_Inactive",param_1), iVar4 != -1))
    goto LAB_c0307744;
    bVar2 = false;
  }
  else {
    local_32 = 0;
    pvVar5 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,awStack_238);
    _Dst[3] = pvVar5;
    iVar4 = _snwprintf(awStack_238,0x104,L"PowerManager/%s_Active",param_1);
    if (iVar4 != -1) goto LAB_c03076b4;
    bVar2 = false;
LAB_c0307744:
    local_32 = 0;
    pvVar5 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,awStack_238);
    _Dst[5] = pvVar5;
  }
  if (((_Dst[3] == 0) || (_Dst[4] == 0)) || (_Dst[5] == 0)) {
    bVar2 = false;
  }
  else {
    wcscpy((wchar_t *)*_Dst,param_1);
    uVar7 = 0;
    if (bVar2) {
      iVar4 = 0;
      do {
        if ((*param_3 == L'\0') || (uVar8 <= uVar7)) break;
        lVar6 = wcstol(param_3,local_240,0);
        *(long *)(iVar4 + _Dst[6]) = lVar6;
        if (*local_240[0] != L'\0') {
          bVar2 = false;
        }
        sVar3 = wcslen(param_3);
        param_3 = param_3 + sVar3 + 1;
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 4;
      } while (bVar2);
    }
    *(undefined4 *)(uVar7 * 4 + _Dst[6]) = 0;
  }
  if (!bVar2) {
    if ((HANDLE)_Dst[3] != (HANDLE)0x0) {
      CloseHandle((HANDLE)_Dst[3]);
    }
    if ((HANDLE)_Dst[4] != (HANDLE)0x0) {
      CloseHandle((HANDLE)_Dst[4]);
    }
    if ((HANDLE)_Dst[5] != (HANDLE)0x0) {
      CloseHandle((HANDLE)_Dst[5]);
    }
    HeapFree(DAT_c030d618,0,_Dst);
    _Dst = (undefined4 *)0x0;
  }
LAB_c0307884:
  FUN_c0308a9c(local_30);
  return _Dst;
}



/* c03078bc FUN_c03078bc */

/* Boundary evidence: original MIPS .pdata c03078bc..c030794b. Semantic name remains unreviewed. */

undefined4 FUN_c03078bc(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    if (*(HANDLE *)((int)param_1 + 0xc) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)param_1 + 0xc));
    }
    if (*(HANDLE *)((int)param_1 + 0x10) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)param_1 + 0x10));
    }
    if (*(HANDLE *)((int)param_1 + 0x14) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)param_1 + 0x14));
    }
    HeapFree(DAT_c030d618,0,param_1);
  }
  return 1;
}



/* c030794c FUN_c030794c */

/* Boundary evidence: original MIPS .pdata c030794c..c03079df. Semantic name remains unreviewed. */

undefined4 * FUN_c030794c(wchar_t *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  puVar3 = DAT_c030d600;
  if (DAT_c030d600 != (undefined4 *)0x0) {
    while ((puVar2 = (undefined4 *)*puVar3, puVar2 != (undefined4 *)0x0 &&
           (iVar1 = wcscmp((wchar_t *)*puVar2,param_1), iVar1 != 0))) {
      puVar3 = puVar3 + 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return puVar2;
}



/* c03079e0 FUN_c03079e0 */

/* Boundary evidence: original MIPS .pdata c03079e0..c0307a9b. Semantic name remains unreviewed. */

int FUN_c03079e0(int param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  bVar1 = false;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  piVar3 = DAT_c030d600;
  if (DAT_c030d600 != (int *)0x0) {
    do {
      iVar5 = *piVar3;
      if (iVar5 == 0) break;
      iVar4 = 0;
      iVar2 = **(int **)(iVar5 + 0x18);
      while (iVar2 != 0) {
        if (iVar2 == param_1) {
          bVar1 = true;
          break;
        }
        iVar4 = iVar4 + 1;
        iVar2 = (*(int **)(iVar5 + 0x18))[iVar4];
      }
      piVar3 = piVar3 + 1;
    } while (!bVar1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c030d620);
  return iVar5;
}



/* c0307a9c FUN_c0307a9c */

/* Boundary evidence: original MIPS .pdata c0307a9c..c0307aff. Semantic name remains unreviewed. */

undefined4 FUN_c0307a9c(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  iVar1 = FUN_c0305b50(L"SystemPriority256",local_10);
  if (iVar1 == 0) {
    local_10[0] = 0xf9;
  }
  CeSetThreadPriority(0x41,local_10[0]);
  FUN_c030979c(param_1);
  return 0;
}



/* c0307b00 FUN_c0307b00 */

/* Boundary evidence: original MIPS .pdata c0307b00..c0307f37. Semantic name remains unreviewed. */

int FUN_c0307b00(void)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  DWORD dwIndex;
  uint uVar6;
  DWORD local_a50;
  HKEY local_a4c;
  HKEY local_a48;
  DWORD local_a44;
  uint local_a40;
  DWORD local_a3c [2];
  undefined4 *local_a34;
  WCHAR aWStack_a30 [256];
  WCHAR local_830 [1022];
  undefined2 local_34;
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_c030d5b0;
  local_a48 = (HKEY)0x0;
  local_a50 = 0;
  wsprintfW(local_830,L"%s\\ActivityTimers",L"SYSTEM\\CurrentControlSet\\Control\\Power");
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,local_830,0,0,&local_a48);
  if (LVar1 == 0) {
    iVar2 = RegQueryInfoKeyW(local_a48,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_a50,(LPDWORD)0x0
                             ,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                             (PFILETIME)0x0);
  }
  else {
    local_a50 = 0;
    iVar2 = 0;
  }
  if (iVar2 != 0) goto LAB_c0307ee4;
  puVar3 = (undefined4 *)FUN_c0305cb0((local_a50 + 1) * 4);
  local_a34 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    iVar2 = 8;
LAB_c0307e80:
    puVar3 = local_a34;
    if (local_a34 != (undefined4 *)0x0) {
      uVar6 = 0;
      uVar5 = local_a50;
      puVar4 = local_a34;
      if (local_a50 != 0) {
        do {
          if ((LPVOID)*puVar4 != (LPVOID)0x0) {
            FUN_c03078bc((LPVOID)*puVar4);
            uVar5 = local_a50;
          }
          uVar6 = uVar6 + 1;
          puVar4 = puVar4 + 1;
        } while (uVar6 < uVar5);
      }
      FUN_c0305cd8(puVar3);
    }
  }
  else {
    memset(puVar3,0,(local_a50 + 1) * 4);
    puVar3[local_a50] = 0;
    if (local_a50 != 0) {
      dwIndex = 0;
      do {
        local_a3c[1] = 0x100;
        iVar2 = RegEnumKeyExW(local_a48,dwIndex,aWStack_a30,local_a3c + 1,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,(PFILETIME)0x0);
        if (iVar2 == 0) {
          local_a4c = (HKEY)0x0;
          iVar2 = RegOpenKeyExW(local_a48,aWStack_a30,0,0,&local_a4c);
          if (iVar2 == 0) {
            local_a44 = 4;
            LVar1 = RegQueryValueExW(local_a4c,L"Timeout",(LPDWORD)0x0,local_a3c,(LPBYTE)&local_a40,
                                     &local_a44);
            if (LVar1 == 0) {
              if ((local_a3c[0] != 4) || (iVar2 = 0, 0x418937 < local_a40)) {
                iVar2 = 0xd;
              }
              local_a40 = local_a40 * 1000;
            }
            else {
              local_a44 = 4;
              LVar1 = RegQueryValueExW(local_a4c,L"TimeoutMs",(LPDWORD)0x0,local_a3c,
                                       (LPBYTE)&local_a40,&local_a44);
              if (((LVar1 != 0) || (local_a3c[0] != 4)) || (iVar2 = 0, 0xfffffed8 < local_a40)) {
                iVar2 = 0xd;
              }
            }
            if (iVar2 == 0) {
              local_a44 = 0x800;
              LVar1 = RegQueryValueExW(local_a4c,L"WakeSources",(LPDWORD)0x0,local_a3c,
                                       (LPBYTE)local_830,&local_a44);
              if (LVar1 == 0) {
                if (local_a3c[0] != 7) {
                  iVar2 = 0x70c;
                  goto LAB_c0307e38;
                }
                local_34 = 0;
                local_32 = 0;
              }
              else {
                local_830[0] = L'\0';
                local_830[1] = 0;
              }
              iVar2 = 0;
              puVar4 = FUN_c03075a4(aWStack_a30,local_a40,local_830);
              *puVar3 = puVar4;
              if (puVar4 == (undefined4 *)0x0) {
                iVar2 = 8;
              }
            }
          }
LAB_c0307e38:
          RegCloseKey(local_a4c);
        }
        dwIndex = dwIndex + 1;
        puVar3 = puVar3 + 1;
      } while ((iVar2 == 0) && (dwIndex < local_a50));
      if (iVar2 == 0x103) {
        iVar2 = 0;
      }
      local_a34[dwIndex] = 0;
      puVar3 = local_a34;
      if (iVar2 != 0) goto LAB_c0307e80;
    }
    FUN_c0305c30();
    DAT_c030d600 = puVar3;
    FUN_c0305c50();
  }
LAB_c0307ee4:
  if (local_a48 != (HKEY)0x0) {
    RegCloseKey(local_a48);
  }
  FUN_c0308a9c(local_30);
  return iVar2;
}



/* c0307f38 FUN_c0307f38 */

/* Boundary evidence: original MIPS .pdata c0307f38..c0307ff3. Semantic name remains unreviewed. */

uint FUN_c0307f38(uint param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0xffffffff;
  FUN_c0305c30();
  iVar2 = *DAT_c030d600;
  if (iVar2 != 0) {
    iVar4 = 0;
    piVar3 = DAT_c030d600;
    do {
      uVar1 = *(uint *)(iVar2 + 8);
      if (uVar1 != 0xffffffff) {
        if (uVar1 < param_1) {
          uVar1 = 0;
        }
        else {
          uVar1 = uVar1 - param_1;
        }
        if ((uVar5 == 0xffffffff) || (uVar1 < uVar5)) {
          uVar5 = uVar1;
        }
        *(uint *)(iVar2 + 8) = uVar1;
        piVar3 = DAT_c030d600;
      }
      iVar4 = iVar4 + 4;
      iVar2 = *(int *)(iVar4 + (int)piVar3);
    } while (iVar2 != 0);
  }
  FUN_c0305c50();
  return uVar5;
}



/* c0307ff4 FUN_c0307ff4 */

/* Boundary evidence: original MIPS .pdata c0307ff4..c030840f. Semantic name remains unreviewed. */

undefined4 FUN_c0307ff4(undefined4 param_1)

{
  int iVar1;
  HANDLE hObject;
  DWORD DVar2;
  DWORD DVar3;
  DWORD DVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  uint nCount;
  uint uVar9;
  undefined4 local_130 [2];
  HANDLE local_128 [64];
  
  iVar1 = FUN_c0305b50(L"TimerPriority256",local_130);
  if (iVar1 == 0) {
    local_130[0] = 0xf9;
  }
  CeSetThreadPriority(0x41,local_130[0]);
  iVar1 = FUN_c0307b00();
  if ((iVar1 == 0) &&
     (hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0), hObject != (HANDLE)0x0))
  {
    nCount = 2;
    local_128[0] = DAT_c030d5f8;
    local_128[1] = (HANDLE)DAT_c030d5f4;
    FUN_c0305c30();
    if (*DAT_c030d600 == 0) {
      FUN_c0305cd8(DAT_c030d600);
      DAT_c030d600 = (int *)0x0;
    }
    else {
      piVar5 = DAT_c030d600;
      do {
        if (*piVar5 == 0) break;
        nCount = nCount + 1;
        *(undefined4 *)((int)local_128 + (8 - (int)DAT_c030d600) + (int)piVar5) =
             *(undefined4 *)(*piVar5 + 0xc);
        piVar5 = piVar5 + 1;
      } while (nCount < 0x40);
    }
    FUN_c0305c50();
    EventModify(param_1,3);
    if (nCount < 3) {
      Sleep(1000);
    }
    else {
      uVar9 = 0;
      while( true ) {
        uVar9 = FUN_c0307f38(uVar9);
        DVar2 = GetTickCount();
        DVar3 = WaitForMultipleObjects(nCount,local_128,0,uVar9);
        DVar4 = GetTickCount();
        uVar9 = DVar4 - DVar2;
        if (DVar3 == 0) break;
        if (DVar3 == 1) {
          FUN_c0305c30();
          iVar1 = *DAT_c030d600;
          if (iVar1 != 0) {
            iVar6 = 0;
            do {
              puVar7 = (undefined4 *)((int)local_128 + iVar6 + 8);
              if ((HANDLE)*puVar7 == hObject) {
                *puVar7 = *(undefined4 *)(iVar1 + 0xc);
              }
              *(uint *)(iVar1 + 8) = *(int *)(iVar1 + 4) + uVar9;
              iVar6 = iVar6 + 4;
              iVar1 = *(int *)(iVar6 + (int)DAT_c030d600);
            } while (iVar1 != 0);
          }
        }
        else if (DVar3 == 0x102) {
          FUN_c0305c30();
          iVar1 = *DAT_c030d600;
          iVar6 = 0;
          if (iVar1 != 0) {
            iVar8 = 0;
            piVar5 = DAT_c030d600;
            do {
              if ((*(uint *)(iVar1 + 8) <= uVar9) && (*(uint *)(iVar1 + 8) != 0xffffffff)) {
                DVar2 = WaitForSingleObject(*(HANDLE *)(iVar1 + 0xc),0);
                if (DVar2 == 0) {
                  *(uint *)(iVar1 + 8) = *(int *)(iVar1 + 4) + uVar9;
                  *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
                  piVar5 = DAT_c030d600;
                }
                else {
                  EventModify(*(undefined4 *)(iVar1 + 0x10),2);
                  EventModify(*(undefined4 *)(iVar1 + 0x14),3);
                  *(undefined4 *)((int)local_128 + iVar8 + 8) = *(undefined4 *)(iVar1 + 0xc);
                  *(undefined4 *)(iVar1 + 8) = 0xffffffff;
                  *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + 1;
                  piVar5 = DAT_c030d600;
                }
              }
              iVar6 = iVar6 + 1;
              iVar8 = iVar6 * 4;
              iVar1 = piVar5[iVar6];
            } while (iVar1 != 0);
          }
        }
        else {
          if ((DVar3 == 0) || (nCount <= DVar3)) break;
          FUN_c0305c30();
          iVar1 = DAT_c030d600[DVar3 - 2];
          if (*(int *)(iVar1 + 4) == 0) {
            *(undefined4 *)(iVar1 + 8) = 0xffffffff;
          }
          else {
            EventModify(*(undefined4 *)(iVar1 + 0x14),2);
            EventModify(*(undefined4 *)(iVar1 + 0x10),3);
            local_128[DVar3] = hObject;
            *(uint *)(iVar1 + 8) = *(int *)(iVar1 + 4) + uVar9;
          }
          *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
        }
        FUN_c0305c50();
      }
    }
    CloseHandle(hObject);
  }
  FUN_c0305c30();
  if (DAT_c030d600 != (int *)0x0) {
    iVar1 = 0;
    iVar6 = *DAT_c030d600;
    piVar5 = DAT_c030d600;
    while (iVar6 != 0) {
      FUN_c03078bc((LPVOID)*piVar5);
      iVar1 = iVar1 + 1;
      piVar5 = DAT_c030d600 + iVar1;
      iVar6 = *piVar5;
    }
    FUN_c0305cd8(DAT_c030d600);
    DAT_c030d600 = (int *)0x0;
  }
  FUN_c0305c50();
  return 0;
}



/* c0308410 FUN_c0308410 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0308410..c030852b. Semantic name remains unreviewed. */

undefined4 FUN_c0308410(undefined4 param_1)

{
  wchar_t wVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  uint local_380 [2];
  undefined1 auStack_378 [20];
  int local_364;
  uint local_360;
  wchar_t local_35c [418];
  uint local_18;
  
  local_18 = DAT_c030d5b0;
  uVar4 = 0;
  local_380[0] = 0;
  local_380[1] = 0;
  memset(auStack_378,0,0x360);
  iVar2 = ReadMsgQueue(param_1,auStack_378,0x360,local_380,0,local_380 + 1);
  if (((iVar2 != 0) && (0x1f < local_380[0])) && (local_360 < 0xff)) {
    iVar2 = 0;
    pwVar3 = local_35c;
    do {
      if (*pwVar3 == L'\0') break;
      wVar1 = towlower(*pwVar3);
      iVar2 = iVar2 + 1;
      *pwVar3 = wVar1;
      pwVar3 = pwVar3 + 1;
    } while (iVar2 < 0x7f);
    local_35c[iVar2] = L'\0';
    if (local_364 == 0) {
      FUN_c030288c(auStack_378,local_35c);
    }
    else {
      FUN_c0302594(auStack_378,local_35c,0,(void *)0x0);
    }
    uVar4 = 1;
  }
  FUN_c0308a9c(local_18);
  return uVar4;
}



/* c030852c FUN_c030852c */

/* Boundary evidence: original MIPS .pdata c030852c..c03086cb. Semantic name remains unreviewed. */

undefined4 FUN_c030852c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  DWORD DVar3;
  DWORD nCount;
  undefined4 *puVar4;
  HANDLE *ppvVar5;
  undefined4 local_130 [2];
  HANDLE local_128;
  HANDLE local_124;
  HANDLE local_120 [64];
  
  iVar1 = FUN_c0305b50(L"PnPPriority256",local_130);
  if (iVar1 == 0) {
    local_130[0] = 0xf9;
  }
  CeSetThreadPriority(0x41,local_130[0]);
  nCount = 1;
  local_120[0] = DAT_c030d5f8;
  if (DAT_c030d638 != (undefined4 *)0x0) {
    ppvVar5 = local_120;
    puVar4 = DAT_c030d638;
    do {
      ppvVar5 = ppvVar5 + 1;
      if (0x3f < nCount) break;
      *ppvVar5 = (HANDLE)puVar4[2];
      nCount = nCount + 1;
      uVar2 = RequestDeviceNotifications(*puVar4,puVar4[2],1);
      puVar4[3] = uVar2;
      puVar4 = (undefined4 *)puVar4[5];
    } while (puVar4 != (undefined4 *)0x0);
  }
  EventModify(param_1,3);
  local_128 = DAT_c030d614;
  local_124 = DAT_c030d5f8;
  DVar3 = WaitForMultipleObjects(2,&local_128,0,0xffffffff);
  puVar4 = DAT_c030d638;
  if (DVar3 == 0) {
    while (((DVar3 = WaitForMultipleObjects(nCount,local_120,0,0xffffffff), puVar4 = DAT_c030d638,
            DVar3 != 0 && (DVar3 != 0)) && (DVar3 < 0x41))) {
      FUN_c0308410(local_120[DVar3]);
    }
  }
  for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)puVar4[5]) {
    if (puVar4[3] != 0) {
      StopDeviceNotifications();
    }
  }
  return 0;
}



/* c03086cc FUN_c03086cc */

/* Boundary evidence: original MIPS .pdata c03086cc..c03087a3. Semantic name remains unreviewed. */

void FUN_c03086cc(undefined4 *param_1,uint param_2)

{
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined2 local_224 [262];
  uint local_18;
  
  local_18 = DAT_c030d5b0;
  if (((param_2 & 4) != 0) && ((DAT_c030d67c == '\0' || (DAT_c030d67c == '\x01')))) {
    local_230 = 4;
    local_22c = 0;
    local_228 = 0;
    local_224[0] = 0;
    FUN_c030588c(param_1,&local_230,0x10);
  }
  if ((param_2 & 8) != 0) {
    local_230 = 8;
    local_22c = 0;
    local_228 = 0x1c;
    memcpy(local_224,&DAT_c030d668,0x1c);
    FUN_c030588c(param_1,&local_230,0x28);
  }
  FUN_c0308a9c(local_18);
  return;
}



/* c0308934 entry */

/* Boundary evidence: original MIPS .pdata c0308934..c03089a7. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c03089a8();
    FUN_c0308cf8();
  }
  uVar1 = FUN_c03050c4(param_1,param_2);
  if (param_2 == 0) {
    FUN_c0308c80();
  }
  return uVar1;
}



/* c03089a8 FUN_c03089a8 */

/* Boundary evidence: original MIPS .pdata c03089a8..c0308a1b. Semantic name remains unreviewed. */

void FUN_c03089a8(void)

{
  uint uVar1;
  
  if ((DAT_c030d5b0 == 0) || (DAT_c030d5b0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c030d5b0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c030d5b0 == 0) {
      DAT_c030d5b0 = 0xb064;
    }
  }
  DAT_c030d5b4 = ~DAT_c030d5b0;
  return;
}



/* c0308a1c FUN_c0308a1c */

/* Boundary evidence: original MIPS .pdata c0308a1c..c0308a6f. Semantic name remains unreviewed. */

void FUN_c0308a1c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0308a9c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0308a70 FUN_c0308a70 */

/* Boundary evidence: original MIPS .pdata c0308a70..c0308a9b. Semantic name remains unreviewed. */

undefined4 FUN_c0308a70(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0308a1c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0308a9c FUN_c0308a9c */

/* Boundary evidence: original MIPS .pdata c0308a9c..c0308ae3. Semantic name remains unreviewed. */

void FUN_c0308a9c(uint param_1)

{
  if ((param_1 == DAT_c030d5b0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0308ae4 FUN_c0308ae4 */

/* Boundary evidence: original MIPS .pdata c0308ae4..c0308b5f. Semantic name remains unreviewed. */

void FUN_c0308ae4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c0308a1c(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c0308b60 FUN_c0308b60 */

/* Boundary evidence: original MIPS .pdata c0308b60..c0308c7f. Semantic name remains unreviewed. */

void FUN_c0308b60(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c030d660 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c030d6f0;
    if (DAT_c030d6f0 != (undefined4 *)0x0) {
      while (DAT_c030d6ec = DAT_c030d6ec + -1, _Memory <= DAT_c030d6ec) {
        if ((code *)*DAT_c030d6ec != (code *)0x0) {
          (*(code *)*DAT_c030d6ec)();
          _Memory = DAT_c030d6f0;
        }
      }
      free(_Memory);
      DAT_c030d6ec = (undefined4 *)0x0;
      DAT_c030d6f0 = (undefined4 *)0x0;
    }
    FUN_c0308ca4((undefined4 *)&DAT_c0301010,(undefined4 *)&DAT_c0301014);
  }
  FUN_c0308ca4((undefined4 *)&DAT_c0301018,(undefined4 *)&DAT_c030101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c030d6f4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0308c80 FUN_c0308c80 */

/* Boundary evidence: original MIPS .pdata c0308c80..c0308ca3. Semantic name remains unreviewed. */

void FUN_c0308c80(void)

{
  FUN_c0308b60(0,0,1);
  return;
}



/* c0308ca4 FUN_c0308ca4 */

/* Boundary evidence: original MIPS .pdata c0308ca4..c0308cf7. Semantic name remains unreviewed. */

void FUN_c0308ca4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0308cf8 FUN_c0308cf8 */

/* Boundary evidence: original MIPS .pdata c0308cf8..c0308d33. Semantic name remains unreviewed. */

void FUN_c0308cf8(void)

{
  FUN_c0308ca4((undefined4 *)&DAT_c0301008,(undefined4 *)&DAT_c030100c);
  FUN_c0308ca4((undefined4 *)&DAT_c0301000,(undefined4 *)&DAT_c0301004);
  return;
}



/* c0308e54 FUN_c0308e54 */

/* Boundary evidence: original MIPS .pdata c0308e54..c03090d3. Semantic name remains unreviewed. */

LSTATUS FUN_c0308e54(void)

{
  LSTATUS LVar1;
  size_t sVar2;
  HKEY local_30;
  int local_2c;
  HKEY local_28;
  DWORD local_24;
  DWORD local_20 [2];
  
  local_30 = (HKEY)0x0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Power",0,
                          (LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_30,local_20);
  if (LVar1 == 0) {
    if (local_20[0] != 1) {
      local_2c = 0;
      local_24 = 4;
      LVar1 = FUN_c0305b04(local_30,L"SupportPowerButtonRelease",(LPBYTE)&local_2c,&local_24,4);
      if (LVar1 == 0) {
        if (local_2c == 0) {
          DAT_c030d6a4 = 0;
        }
        else {
          DAT_c030d6a4 = 1;
        }
      }
      local_24 = 4;
      LVar1 = FUN_c0305b04(local_30,L"PageOutAllModules",(LPBYTE)&local_2c,&local_24,4);
      if ((LVar1 == 0) && (local_2c != 0)) {
        DAT_c030d6a8 = 1;
      }
      else {
        DAT_c030d6a8 = 0;
      }
    }
    LVar1 = RegCreateKeyExW(local_30,L"Interfaces",0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,
                            &local_28,local_20);
    if (LVar1 == 0) {
      if (local_20[0] == 1) {
        sVar2 = wcslen(L"Generic power-manageable devices");
        LVar1 = RegSetValueExW(local_28,L"{A32942B7-920C-486b-B0E6-92A702A99B35}",0,1,
                               (BYTE *)L"Generic power-manageable devices",(sVar2 + 1) * 2);
        if (LVar1 == 0) {
          sVar2 = wcslen(L"Power-manageable block devices");
          LVar1 = RegSetValueExW(local_28,L"{8DD679CE-8AB4-43c8-A14A-EA4963FAA715}",0,1,
                                 (BYTE *)L"Power-manageable block devices",(sVar2 + 1) * 2);
          if (LVar1 == 0) {
            sVar2 = wcslen(L"Power-manageable display drivers");
            LVar1 = RegSetValueExW(local_28,L"{EB91C7C9-8BF6-4a2d-9AB8-69724EED97D1}",0,1,
                                   (BYTE *)L"Power-manageable display drivers",(sVar2 + 1) * 2);
          }
        }
      }
      RegCloseKey(local_28);
    }
  }
  if (local_30 != (HKEY)0x0) {
    RegCloseKey(local_30);
  }
  return LVar1;
}



/* c03090d4 FUN_c03090d4 */

/* Boundary evidence: original MIPS .pdata c03090d4..c0309157. Semantic name remains unreviewed. */

bool FUN_c03090d4(undefined4 *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = memcmp((void *)*param_1,&DAT_c030d15c,0x10);
  if (iVar1 == 0) {
    ppuVar2 = &PTR_FUN_c030d5dc;
  }
  else {
    ppuVar2 = &PTR_FUN_c030d5cc;
  }
  iVar1 = (*(code *)*ppuVar2)();
  if (iVar1 != 0) {
    param_1[4] = ppuVar2;
  }
  return iVar1 != 0;
}



/* c0309158 FUN_c0309158 */

/* Boundary evidence: original MIPS .pdata c0309158..c0309197. Semantic name remains unreviewed. */

undefined4 FUN_c0309158(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (DAT_c030d6ac != (int *)0x0) {
    uVar1 = (**(code **)(*DAT_c030d6ac + 0x10))(DAT_c030d6ac,param_1,param_2,param_3);
  }
  return uVar1;
}



/* c0309198 FUN_c0309198 */

/* Boundary evidence: original MIPS .pdata c0309198..c0309707. Semantic name remains unreviewed. */

int FUN_c0309198(wchar_t *param_1)

{
  bool bVar1;
  bool bVar2;
  LPVOID pvVar3;
  undefined4 *puVar4;
  size_t sVar5;
  DWORD DVar6;
  int iVar7;
  undefined4 *puVar8;
  LPVOID pvVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 *local_258;
  LPVOID local_254;
  int local_250;
  uint local_248;
  undefined4 local_244;
  size_t local_240;
  wchar_t local_23c [262];
  uint local_30;
  
  local_30 = DAT_c030d5b0;
  iVar12 = 0;
  local_258 = (undefined4 *)0x0;
  local_254 = (LPVOID)0x0;
  if (DAT_c030d5b8 != 0) {
    FUN_c0304358();
  }
  local_250 = FUN_c0304420(param_1,&local_258,&local_254);
  puVar4 = local_258;
  if (local_250 == 0) {
    uVar10 = local_258[2];
    uVar11 = (uint)((uVar10 & 0x10000000) != 0);
    bVar1 = (uVar10 & 0xa60000) == 0;
    local_248 = 1;
    local_244 = local_258[2];
    bVar2 = false;
    sVar5 = wcslen((wchar_t *)*local_258);
    local_240 = sVar5 + 1;
    if (0x104 < local_240) {
      local_240 = 0x104;
    }
    wcsncpy(local_23c,(wchar_t *)*puVar4,local_240);
    local_240 = local_240 << 1;
    FUN_c03058b0(&local_248);
    if (((DAT_c030d664 == 0) && (DAT_c030d688 != (HANDLE)0x0)) &&
       (DVar6 = WaitForSingleObject(DAT_c030d688,0), DVar6 == 0)) {
      DAT_c030d664 = 1;
      CloseHandle(DAT_c030d688);
      DAT_c030d688 = (HANDLE)0x0;
    }
    if (((!bVar1) && (DAT_c030d690 != (code *)0x0)) && (DAT_c030d664 != 0)) {
      DAT_c030d6b0 = (*DAT_c030d690)();
    }
    FUN_c0305c30();
    puVar4 = DAT_c030d654;
    pvVar3 = DAT_c030d61c;
    if ((DAT_c030d654 != (undefined4 *)0x0) && ((DAT_c030d654[2] & 0x260000) != 0)) {
      bVar2 = true;
    }
    DAT_c030d654 = local_258;
    DAT_c030d61c = local_254;
    FUN_c0305c50();
    puVar8 = DAT_c030d638;
    if (bVar1) {
      if (bVar2) {
        puVar8 = FUN_c0307364(&DAT_c030d5bc);
        if (puVar8 != (undefined4 *)0x0) {
          FUN_c0302410((int)puVar8);
        }
        FileSystemPowerFunction(1);
        DAT_c030d5b8 = 1;
        for (puVar8 = DAT_c030d638; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)puVar8[5]) {
          iVar7 = memcmp((void *)*puVar8,&DAT_c030d5bc,0x10);
          if (iVar7 != 0) {
            FUN_c0302410((int)puVar8);
          }
        }
        if ((DAT_c030d694 != (code *)0x0) && (DAT_c030d664 != 0)) {
          (*DAT_c030d694)(DAT_c030d6b0);
          DAT_c030d6b0 = 0;
        }
        local_248 = 2;
        local_244 = 0;
        local_240 = 0;
        local_23c[0] = L'\0';
        FUN_c03058b0(&local_248);
      }
      else {
        FUN_c03024b8();
      }
    }
    else {
      for (; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)puVar8[5]) {
        iVar7 = memcmp((void *)*puVar8,&DAT_c030d5bc,0x10);
        if (iVar7 != 0) {
          FUN_c0302410((int)puVar8);
        }
      }
      KernelIoControl(0x10100f4,0,0,0,0,0);
      iVar7 = CeGetThreadPriority(0x41);
      if (iVar7 != 0x7fffffff) {
        CeSetThreadPriority(0x41,DAT_c030d684);
        Sleep(0);
        CeSetThreadPriority(0x41,iVar7);
      }
      if (DAT_c030d68c != 0) {
        iVar12 = CeGetThreadPriority(0x41);
        CeSetThreadPriority(0x41,DAT_c030d68c);
      }
      FileSystemPowerFunction(2);
      DAT_c030d5b8 = 0;
      puVar8 = FUN_c0307364(&DAT_c030d5bc);
      if (puVar8 != (undefined4 *)0x0) {
        FUN_c0302410((int)puVar8);
      }
      if ((uVar10 & 0x800000) != 0) {
        iVar7 = wcscmp(param_1,L"coldreboot");
        if (iVar7 == 0) {
          SetCleanRebootFlag();
        }
        KernelLibIoControl(5,0x101003c,0,0,0,0,0);
      }
    }
    FUN_c0307570(puVar4);
    while (pvVar3 != (LPVOID)0x0) {
      pvVar9 = *(LPVOID *)((int)pvVar3 + 0x14);
      FUN_c0306c7c(pvVar3);
      pvVar3 = pvVar9;
    }
    if (bVar1) {
      FUN_c0305c30();
      uVar10 = DAT_c030d6a0;
      if ((((uVar11 != DAT_c030d6a0) && (uVar10 = uVar11, DAT_c030d664 != 0)) &&
          (DAT_c030d698 != (code *)0x0)) && (uVar11 != 0)) {
        (*DAT_c030d698)();
      }
      DAT_c030d6a0 = uVar10;
      FUN_c0305c50();
    }
    else {
      if (DAT_c030d6a8 != 0) {
        PageOutModule(0x42,2);
      }
      DAT_c030d69c = 1;
      PowerOffSystem();
      Sleep(0);
      DAT_c030d69c = 0;
      DAT_c030d6a0 = 0;
    }
  }
  iVar7 = local_250;
  if ((DAT_c030d68c != 0) && (iVar12 != 0)) {
    CeSetThreadPriority(0x41,iVar12);
  }
  FUN_c0308a9c(local_30);
  return iVar7;
}



/* c0309708 FUN_c0309708 */

/* Boundary evidence: original MIPS .pdata c0309708..c030979b. Semantic name remains unreviewed. */

uint FUN_c0309708(HKEY param_1,LPCWSTR param_2,uint param_3)

{
  LSTATUS LVar1;
  DWORD local_10;
  uint local_c;
  
  local_10 = 4;
  LVar1 = FUN_c0305b04(param_1,param_2,(LPBYTE)&local_c,&local_10,4);
  if (LVar1 == 0) {
    if (local_c == 0) {
      return 0xffffffff;
    }
    param_3 = local_c;
    if (0x418937 < local_c) {
      param_3 = 0x418937;
    }
  }
  if (param_3 != 0xffffffff) {
    param_3 = param_3 * 1000;
  }
  return param_3;
}



/* c030979c FUN_c030979c */

/* Boundary evidence: original MIPS .pdata c030979c..c03099a3. Semantic name remains unreviewed. */

void FUN_c030979c(undefined4 param_1)

{
  int iVar1;
  HMODULE hLibModule;
  int *piVar2;
  
  iVar1 = FUN_c0305b50(L"PreSuspendPriority256",&DAT_c030d684);
  if (iVar1 == 0) {
    DAT_c030d684 = 0xf9;
  }
  iVar1 = FUN_c0305b50(L"SuspendPriority256",&DAT_c030d68c);
  if (iVar1 == 0) {
    DAT_c030d68c = 0;
  }
  hLibModule = LoadLibraryW(L"coredll.dll");
  DAT_c030d664 = 0;
  FUN_c030c478(hLibModule);
  if (hLibModule != (HMODULE)0x0) {
    DAT_c030d690 = GetProcAddressW(hLibModule,L"GwesPowerDown");
    DAT_c030d694 = GetProcAddressW(hLibModule,L"GwesPowerUp");
    DAT_c030d698 = GetProcAddressW(hLibModule,L"ShowStartupWindow");
    if ((DAT_c030d690 == 0) || (DAT_c030d694 == 0)) {
      DAT_c030d690 = 0;
      DAT_c030d694 = 0;
    }
    else {
      DAT_c030d688 = OpenEventW(0x1f0003,0,L"SYSTEM/GweApiSetReady");
    }
  }
  piVar2 = FUN_c030a900();
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))(piVar2);
    if (iVar1 == 0) {
      (**(code **)*piVar2)(piVar2,1);
    }
    else {
      DAT_c030d6ac = piVar2;
      EventModify(param_1,3);
      (**(code **)(*DAT_c030d6ac + 0x2c))();
    }
  }
  if (DAT_c030d6ac != (int *)0x0) {
    (**(code **)*DAT_c030d6ac)(DAT_c030d6ac,1);
    DAT_c030d6ac = (int *)0x0;
  }
  if (hLibModule != (HMODULE)0x0) {
    FreeLibrary(hLibModule);
  }
  return;
}



/* c03099a4 FUN_c03099a4 */

/* Boundary evidence: original MIPS .pdata c03099a4..c03099db. Semantic name remains unreviewed. */

void FUN_c03099a4(void)

{
  if (DAT_c030d6ac != (int *)0x0) {
    (**(code **)(*DAT_c030d6ac + 0xc))(DAT_c030d6ac,DAT_c030d69c);
  }
  return;
}



/* c03099dc FUN_c03099dc */

/* Boundary evidence: original MIPS .pdata c03099dc..c0309a1b. Semantic name remains unreviewed. */

undefined4 FUN_c03099dc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x1f;
  if (DAT_c030d6ac != (int *)0x0) {
    uVar1 = (**(code **)(*DAT_c030d6ac + 0x1c))(DAT_c030d6ac,param_1,param_2,param_3);
  }
  return uVar1;
}



/* c0309a24 FUN_c0309a24 */

/* Boundary evidence: original MIPS .pdata c0309a24..c0309a8f. Semantic name remains unreviewed. */

void FUN_c0309a24(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_FUN_c0301630;
  while (param_1[0xe] != 0) {
    puVar1 = (undefined4 *)param_1[0xe];
    uVar2 = puVar1[5];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    param_1[0xe] = uVar2;
  }
  FUN_c030b718(param_1);
  return;
}



/* c0309a90 FUN_c0309a90 */

/* Boundary evidence: original MIPS .pdata c0309a90..c0309b13. Semantic name remains unreviewed. */

undefined4 FUN_c0309a90(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c030b7c8((int)param_1);
  if (((iVar1 == 0) || (param_1[0xd] == 0)) || (param_1[0xc] == 0)) {
    uVar2 = 0;
  }
  else {
    (**(code **)(*param_1 + 0x48))(param_1);
    (**(code **)(*param_1 + 0x44))(param_1);
    uVar2 = (**(code **)(*param_1 + 0x4c))(param_1);
  }
  return uVar2;
}



/* c0309b84 FUN_c0309b84 */

/* Boundary evidence: original MIPS .pdata c0309b84..c0309d6b. Semantic name remains unreviewed. */

undefined4 FUN_c0309b84(int *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if ((param_1[0xe] != 0) &&
     (piVar2 = (int *)(**(code **)(*param_1 + 0x14))(param_1), piVar2 != (int *)0x0)) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
    EnterCriticalSection(lpCriticalSection);
    param_1[0xf] = (int)piVar2;
    (**(code **)(*piVar2 + 4))(piVar2);
    bVar1 = false;
    do {
      if (piVar2 == (int *)0x0) break;
      (**(code **)(*piVar2 + 0x18))(piVar2);
      LeaveCriticalSection(lpCriticalSection);
      uVar3 = (**(code **)(*piVar2 + 0xc))(piVar2,0xffffffff,0,0);
      EnterCriticalSection(lpCriticalSection);
      piVar5 = (int *)param_1[0xf];
      if (piVar2 != piVar5) {
        (**(code **)(*piVar5 + 0x18))(piVar5);
        iVar4 = (**(code **)(*piVar5 + 0x18))(piVar5);
        piVar2 = piVar5;
        if ((iVar4 == 3) || (iVar4 = (**(code **)(*piVar5 + 0x18))(piVar5), iVar4 == 4)) {
          (**(code **)(*param_1 + 0x44))(param_1);
        }
      }
      switch(uVar3) {
      default:
        pcVar6 = *(code **)(*piVar2 + 0x10);
LAB_c0309d14:
        (*pcVar6)(piVar2,uVar3);
        break;
      case 0xc:
        break;
      case 0xd:
        bVar1 = true;
        break;
      case 0xe:
        (**(code **)(*param_1 + 0x48))(param_1);
      case 8:
      case 9:
      case 0xb:
      case 0xf:
      case 0x10:
        (**(code **)(*param_1 + 0x44))(param_1);
        pcVar6 = *(code **)(*piVar2 + 0x10);
        goto LAB_c0309d14;
      }
      piVar2 = (int *)(**(code **)(*param_1 + 0x18))(param_1,piVar2);
      param_1[0xf] = (int)piVar2;
    } while (!bVar1);
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* c0309dd0 FUN_c0309dd0 */

/* Boundary evidence: original MIPS .pdata c0309dd0..c0309f37. Semantic name remains unreviewed. */

void FUN_c0309dd0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_230;
  int local_22c;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c030d5b0;
  if (param_2 == 0) {
    (**(code **)(*param_1 + 0x10))(param_1,0x10000,awStack_228,0x104);
    FUN_c03036c0(awStack_228,0);
  }
  else if (param_1[0x19] != 0) {
    iVar1 = KernelIoControl(0x10100a8,0,0,&local_230,4,&local_22c);
    if ((((iVar1 == 0) || (local_22c != 4)) || (iVar1 = FUN_c03079e0(local_230), iVar1 == 0)) ||
       (iVar1 = *(int *)(iVar1 + 0xc), iVar1 == 0)) {
      if (param_1[0xc] == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(param_1[0xc] + 0xc);
      }
      if (iVar1 == 0) goto LAB_c0309f14;
    }
    uVar2 = CeGetThreadPriority(DAT_c030d650);
    iVar3 = CeGetThreadPriority(0x41);
    EventModify(iVar1,3);
    CeSetThreadPriority(DAT_c030d650,iVar3 + -1);
    CeSetThreadPriority(DAT_c030d650,uVar2);
  }
LAB_c0309f14:
  FUN_c0308a9c(local_20);
  return;
}



/* c0309f38 FUN_c0309f38 */

/* Boundary evidence: original MIPS .pdata c0309f38..c030a08f. Semantic name remains unreviewed. */

void FUN_c0309f38(int param_1)

{
  LSTATUS LVar1;
  uint uVar2;
  HKEY local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c030d5b0;
  *(undefined4 *)(param_1 + 0x48) = 60000;
  *(undefined4 *)(param_1 + 0x54) = 60000;
  *(undefined4 *)(param_1 + 0x40) = 600000;
  *(undefined4 *)(param_1 + 0x44) = 300000;
  *(undefined4 *)(param_1 + 0x4c) = 600000;
  *(undefined4 *)(param_1 + 0x50) = 300000;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"SYSTEM\\CurrentControlSet\\Control\\Power",
                   L"Timeouts");
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,awStack_218,0,0,local_220);
  if (LVar1 == 0) {
    uVar2 = FUN_c0309708(local_220[0],L"ACSuspend",600);
    *(uint *)(param_1 + 0x40) = uVar2;
    uVar2 = FUN_c0309708(local_220[0],L"ACSystemIdle",300);
    *(uint *)(param_1 + 0x44) = uVar2;
    uVar2 = FUN_c0309708(local_220[0],L"ACUserIdle",0x3c);
    *(uint *)(param_1 + 0x48) = uVar2;
    uVar2 = FUN_c0309708(local_220[0],L"BattSuspend",0x3c);
    *(uint *)(param_1 + 0x4c) = uVar2;
    uVar2 = FUN_c0309708(local_220[0],L"BattSystemIdle",300);
    *(uint *)(param_1 + 0x50) = uVar2;
    uVar2 = FUN_c0309708(local_220[0],L"BattUserIdle",600);
    *(uint *)(param_1 + 0x54) = uVar2;
    RegCloseKey(local_220[0]);
  }
  FUN_c0308a9c(local_10);
  return;
}



/* c030a090 FUN_c030a090 */

/* Boundary evidence: original MIPS .pdata c030a090..c030a0db. Semantic name remains unreviewed. */

undefined4 * FUN_c030a090(undefined4 *param_1,uint param_2)

{
  FUN_c0309a24(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030a0dc FUN_c030a0dc */

/* Boundary evidence: original MIPS .pdata c030a0dc..c030a0ff. Semantic name remains unreviewed. */

void FUN_c030a0dc(int *param_1)

{
  (**(code **)(*param_1 + 0x28))();
  return;
}



/* c030a12c FUN_c030a12c */

/* Boundary evidence: original MIPS .pdata c030a12c..c030a167. Semantic name remains unreviewed. */

void FUN_c030a12c(int *param_1)

{
  FUN_c030b0d8(param_1);
  (**(code **)(*(int *)param_1[3] + 0x44))();
  return;
}



/* c030a168 FUN_c030a168 */

/* Boundary evidence: original MIPS .pdata c030a168..c030a203. Semantic name remains unreviewed. */

void FUN_c030a168(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  DWORD DVar1;
  int iVar2;
  int local_18 [2];
  
  *(undefined4 *)(param_1[3] + 0x58) = 0xffffffff;
  *(undefined4 *)(param_1[3] + 0x5c) = 0xffffffff;
  DVar1 = (**(code **)(*(int *)param_1[3] + 0x40))((int *)param_1[3],local_18);
  iVar2 = FUN_c030b15c(param_1,DVar1,param_3,param_4);
  if ((iVar2 == 7) && (local_18[0] == 3)) {
    param_1[1] = 1;
  }
  return;
}



/* c030a210 FUN_c030a210 */

/* Boundary evidence: original MIPS .pdata c030a210..c030a22f. Semantic name remains unreviewed. */

void FUN_c030a210(int *param_1)

{
  FUN_c030b410(param_1,0,0x10010000);
  return;
}



/* c030a230 FUN_c030a230 */

/* Boundary evidence: original MIPS .pdata c030a230..c030a26b. Semantic name remains unreviewed. */

void FUN_c030a230(int *param_1)

{
  FUN_c030b0d8(param_1);
  (**(code **)(*(int *)param_1[3] + 0x44))();
  return;
}



/* c030a26c FUN_c030a26c */

/* Boundary evidence: original MIPS .pdata c030a26c..c030a317. Semantic name remains unreviewed. */

void FUN_c030a26c(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  DWORD DVar1;
  int iVar2;
  int local_18 [2];
  
  *(undefined4 *)(param_1[3] + 0x60) = 0xffffffff;
  *(undefined4 *)(param_1[3] + 0x58) = 0xffffffff;
  DVar1 = (**(code **)(*(int *)param_1[3] + 0x40))((int *)param_1[3],local_18);
  iVar2 = FUN_c030b15c(param_1,DVar1,param_3,param_4);
  if (iVar2 == 1) {
    param_1[1] = 0;
  }
  else if ((iVar2 == 7) && (local_18[0] == 2)) {
    param_1[1] = 2;
  }
  return;
}



/* c030a318 FUN_c030a318 */

undefined4 FUN_c030a318(void)

{
  return 1;
}



/* c030a32c FUN_c030a32c */

/* Boundary evidence: original MIPS .pdata c030a32c..c030a34b. Semantic name remains unreviewed. */

void FUN_c030a32c(int *param_1)

{
  FUN_c030b410(param_1,1,0x11000000);
  return;
}



/* c030a354 FUN_c030a354 */

/* Boundary evidence: original MIPS .pdata c030a354..c030a38f. Semantic name remains unreviewed. */

void FUN_c030a354(int *param_1)

{
  FUN_c030b0d8(param_1);
  (**(code **)(*(int *)param_1[3] + 0x44))();
  return;
}



/* c030a390 FUN_c030a390 */

/* Boundary evidence: original MIPS .pdata c030a390..c030a43b. Semantic name remains unreviewed. */

void FUN_c030a390(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  DWORD DVar1;
  int iVar2;
  int local_18 [2];
  
  *(undefined4 *)(param_1[3] + 0x60) = 0xffffffff;
  *(undefined4 *)(param_1[3] + 0x5c) = 0xffffffff;
  DVar1 = (**(code **)(*(int *)param_1[3] + 0x40))((int *)param_1[3],local_18);
  iVar2 = FUN_c030b15c(param_1,DVar1,param_3,param_4);
  if (iVar2 == 1) {
    param_1[1] = 0;
  }
  else if ((iVar2 == 7) && (local_18[0] == 1)) {
    param_1[1] = 4;
  }
  return;
}



/* c030a450 FUN_c030a450 */

/* Boundary evidence: original MIPS .pdata c030a450..c030a46f. Semantic name remains unreviewed. */

void FUN_c030a450(int *param_1)

{
  FUN_c030b410(param_1,2,0);
  return;
}



/* c030a470 FUN_c030a470 */

/* Boundary evidence: original MIPS .pdata c030a470..c030a4bb. Semantic name remains unreviewed. */

void FUN_c030a470(int *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = (wchar_t *)(**(code **)(*param_1 + 0x1c))(param_1);
  FUN_c03036c0(pwVar1,0);
  param_1[1] = 3;
  return;
}



/* c030a4d0 FUN_c030a4d0 */

/* Boundary evidence: original MIPS .pdata c030a4d0..c030a4ef. Semantic name remains unreviewed. */

void FUN_c030a4d0(int *param_1)

{
  FUN_c030b410(param_1,3,0x200000);
  return;
}



/* c030a4f0 FUN_c030a4f0 */

/* Boundary evidence: original MIPS .pdata c030a4f0..c030a567. Semantic name remains unreviewed. */

void FUN_c030a4f0(int *param_1)

{
  int *piVar1;
  
  FUN_c030b0d8(param_1);
  (**(code **)(*(int *)param_1[3] + 0x44))();
  piVar1 = (int *)param_1[3];
  if (piVar1[0xc] != 0) {
    param_1[0xb] = *(int *)(piVar1[0xc] + 0x10);
  }
  if (piVar1[0xd] != 0) {
    param_1[0xc] = *(int *)(piVar1[0xd] + 0x10);
  }
  (**(code **)(*piVar1 + 0x34))(piVar1,1);
  return;
}



/* c030a568 FUN_c030a568 */

/* Boundary evidence: original MIPS .pdata c030a568..c030a5c7. Semantic name remains unreviewed. */

void FUN_c030a568(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = FUN_c030b15c(param_1,0,param_3,param_4);
  if (iVar1 != 1) {
    if (iVar1 == 3) {
      param_1[1] = 2;
      return;
    }
    if (iVar1 != 7) {
      return;
    }
  }
  param_1[1] = 0;
  return;
}



/* c030a5dc FUN_c030a5dc */

/* Boundary evidence: original MIPS .pdata c030a5dc..c030a5fb. Semantic name remains unreviewed. */

void FUN_c030a5dc(int *param_1)

{
  FUN_c030b410(param_1,2,0);
  return;
}



/* c030a5fc FUN_c030a5fc */

/* Boundary evidence: original MIPS .pdata c030a5fc..c030a633. Semantic name remains unreviewed. */

void FUN_c030a5fc(int *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = (wchar_t *)(**(code **)(*param_1 + 0x1c))();
  FUN_c03036c0(pwVar1,0);
  return;
}



/* c030a648 FUN_c030a648 */

/* Boundary evidence: original MIPS .pdata c030a648..c030a667. Semantic name remains unreviewed. */

void FUN_c030a648(int *param_1)

{
  FUN_c030b410(param_1,4,0x800000);
  return;
}



/* c030a668 FUN_c030a668 */

/* Boundary evidence: original MIPS .pdata c030a668..c030a69f. Semantic name remains unreviewed. */

void FUN_c030a668(int *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = (wchar_t *)(**(code **)(*param_1 + 0x1c))();
  FUN_c03036c0(pwVar1,0);
  return;
}



/* c030a6b4 FUN_c030a6b4 */

/* Boundary evidence: original MIPS .pdata c030a6b4..c030a6d3. Semantic name remains unreviewed. */

void FUN_c030a6b4(int *param_1)

{
  FUN_c030b410(param_1,4,0x800000);
  return;
}



/* c030a6d4 FUN_c030a6d4 */

/* Boundary evidence: original MIPS .pdata c030a6d4..c030a8ff. Semantic name remains unreviewed. */

undefined4 FUN_c030a6d4(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  
  if (param_1[0xe] == 0) {
    puVar1 = operator_new(0x11c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar2 = operator_new(0x11c);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar3 = operator_new(0x11c);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar4 = operator_new(0x11c);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            puVar5 = operator_new(0x11c);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar6 = operator_new(0x11c);
              if (puVar6 == (undefined4 *)0x0) {
                puVar6 = (undefined4 *)0x0;
              }
              else {
                puVar7 = operator_new(0x11c);
                if (puVar7 == (undefined4 *)0x0) {
                  puVar7 = (undefined4 *)0x0;
                }
                else {
                  FUN_c030adc4(puVar7,param_1,0);
                  *puVar7 = &PTR_FUN_c03018a0;
                }
                FUN_c030adc4(puVar6,param_1,puVar7);
                *puVar6 = &PTR_FUN_c03018d8;
              }
              FUN_c030adc4(puVar5,param_1,puVar6);
              *puVar5 = &PTR_FUN_c030180c;
            }
            FUN_c030adc4(puVar4,param_1,puVar5);
            *puVar4 = &PTR_FUN_c0301854;
          }
          FUN_c030adc4(puVar3,param_1,puVar4);
          *puVar3 = &PTR_FUN_c03017bc;
        }
        FUN_c030adc4(puVar2,param_1,puVar3);
        *puVar2 = &PTR_FUN_c0301770;
      }
      FUN_c030adc4(puVar1,param_1,puVar2);
      *puVar1 = &PTR_FUN_c0301730;
    }
    param_1[0xe] = (int)puVar1;
  }
  piVar10 = (int *)param_1[0xe];
  if (piVar10 == (int *)0x0) {
LAB_c030a8d0:
    uVar9 = 0;
  }
  else {
    do {
      iVar8 = (**(code **)(*piVar10 + 8))(piVar10);
      if (iVar8 == 0) goto LAB_c030a8d0;
      piVar10 = (int *)piVar10[5];
    } while (piVar10 != (int *)0x0);
    uVar9 = 1;
  }
  return uVar9;
}



/* c030a900 FUN_c030a900 */

/* Boundary evidence: original MIPS .pdata c030a900..c030a967. Semantic name remains unreviewed. */

undefined4 * FUN_c030a900(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x68);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_c030b61c(puVar1);
    *puVar1 = &PTR_FUN_c0301630;
    puVar1[0x19] = 1;
  }
  return puVar1;
}



/* c030abb0 FUN_c030abb0 */

/* Boundary evidence: original MIPS .pdata c030abb0..c030abfb. Semantic name remains unreviewed. */

undefined4 * FUN_c030abb0(undefined4 *param_1,uint param_2)

{
  FUN_c030af44(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030abfc FUN_c030abfc */

/* Boundary evidence: original MIPS .pdata c030abfc..c030ac47. Semantic name remains unreviewed. */

undefined4 * FUN_c030abfc(undefined4 *param_1,uint param_2)

{
  FUN_c030af44(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030ac48 FUN_c030ac48 */

/* Boundary evidence: original MIPS .pdata c030ac48..c030ac93. Semantic name remains unreviewed. */

undefined4 * FUN_c030ac48(undefined4 *param_1,uint param_2)

{
  FUN_c030af44(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030ac94 FUN_c030ac94 */

/* Boundary evidence: original MIPS .pdata c030ac94..c030acdf. Semantic name remains unreviewed. */

undefined4 * FUN_c030ac94(undefined4 *param_1,uint param_2)

{
  FUN_c030af44(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030ace0 FUN_c030ace0 */

/* Boundary evidence: original MIPS .pdata c030ace0..c030ad2b. Semantic name remains unreviewed. */

undefined4 * FUN_c030ace0(undefined4 *param_1,uint param_2)

{
  FUN_c030af44(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030ad2c FUN_c030ad2c */

/* Boundary evidence: original MIPS .pdata c030ad2c..c030ad77. Semantic name remains unreviewed. */

undefined4 * FUN_c030ad2c(undefined4 *param_1,uint param_2)

{
  FUN_c030af44(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030ad78 FUN_c030ad78 */

/* Boundary evidence: original MIPS .pdata c030ad78..c030adc3. Semantic name remains unreviewed. */

undefined4 * FUN_c030ad78(undefined4 *param_1,uint param_2)

{
  FUN_c030af44(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030adc4 FUN_c030adc4 */

/* Boundary evidence: original MIPS .pdata c030adc4..c030af43. Semantic name remains unreviewed. */

undefined4 * FUN_c030adc4(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  int iVar2;
  undefined4 uVar3;
  int *_Dst;
  
  _Dst = param_1 + 7;
  param_1[5] = param_3;
  *param_1 = &PTR_FUN_c0301920;
  param_1[3] = param_2;
  memset(_Dst,0,0x100);
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[4] = pvVar1;
  iVar2 = (**(code **)(*param_2 + 8))(param_2,0);
  *_Dst = iVar2;
  uVar3 = (**(code **)(*param_2 + 8))(param_2,1);
  param_1[8] = uVar3;
  uVar3 = (**(code **)(*param_2 + 8))(param_2,2);
  param_1[9] = uVar3;
  uVar3 = (**(code **)(*param_2 + 8))(param_2,3);
  param_1[10] = uVar3;
  if (param_2[0xc] == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_2[0xc] + 0x10);
  }
  param_1[0xb] = uVar3;
  if (param_2[0xd] == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_2[0xd] + 0x10);
  }
  param_1[0xc] = uVar3;
  uVar3 = (**(code **)(*param_2 + 8))(param_2,6);
  param_1[0xd] = uVar3;
  uVar3 = (**(code **)(*param_2 + 8))(param_2,7);
  iVar2 = 8;
  param_1[0xe] = uVar3;
  param_1[6] = 8;
  do {
    if (*_Dst == 0) {
      *_Dst = param_1[4];
    }
    iVar2 = iVar2 + -1;
    _Dst = _Dst + 1;
  } while (iVar2 != 0);
  param_1[2] = 0;
  param_1[1] = 0xffffffff;
  return param_1;
}



/* c030af44 FUN_c030af44 */

/* Boundary evidence: original MIPS .pdata c030af44..c030af7f. Semantic name remains unreviewed. */

void FUN_c030af44(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0301920;
  if ((HANDLE)param_1[4] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[4]);
  }
  return;
}



/* c030af80 FUN_c030af80 */

/* Boundary evidence: original MIPS .pdata c030af80..c030b027. Semantic name remains unreviewed. */

undefined4 FUN_c030af80(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  uint uVar4;
  
  if ((param_1[3] != 0) && (param_1[4] != 0)) {
    uVar4 = 0;
    if (param_1[6] != 0) {
      piVar3 = param_1 + 7;
      do {
        if (*piVar3 == 0) {
          return 0;
        }
        uVar4 = uVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (uVar4 < (uint)param_1[6]);
    }
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1);
    pcVar2 = *(code **)(*param_1 + 0x24);
    param_1[1] = iVar1;
    iVar1 = (*pcVar2)(param_1,0,0x10000);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c030b028 FUN_c030b028 */

/* Boundary evidence: original MIPS .pdata c030b028..c030b0d7. Semantic name remains unreviewed. */

undefined4 FUN_c030b028(int param_1)

{
  bool bVar1;
  DWORD DVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  int local_18;
  int local_14;
  
  uVar3 = 0;
  DVar2 = FUN_c030c72c(*(undefined4 *)(param_1 + 0x24),&local_18,0xc);
  if (DVar2 == 0) {
    if (local_18 == 2) {
      bVar1 = FUN_c030c514();
      if (CONCAT31(extraout_var,bVar1) != 0) {
        uVar3 = 9;
      }
    }
    else if (local_18 == 3) {
      if (local_14 == 0) {
        uVar3 = 6;
      }
      else {
        uVar3 = 5;
      }
    }
    else if (local_18 == 4) {
      uVar3 = 0xf;
    }
    else if (local_18 == 6) {
      uVar3 = 0x10;
    }
  }
  return uVar3;
}



/* c030b0d8 FUN_c030b0d8 */

/* Boundary evidence: original MIPS .pdata c030b0d8..c030b15b. Semantic name remains unreviewed. */

void FUN_c030b0d8(int *param_1)

{
  wchar_t *pwVar1;
  int iVar2;
  
  pwVar1 = (wchar_t *)(**(code **)(*param_1 + 0x1c))(param_1);
  FUN_c03036c0(pwVar1,0);
  iVar2 = (**(code **)(*param_1 + 0x18))(param_1);
  param_1[1] = iVar2;
  iVar2 = *(int *)(param_1[3] + 0x30);
  if (iVar2 != 0) {
    param_1[0xb] = *(int *)(iVar2 + 0x10);
  }
  iVar2 = *(int *)(param_1[3] + 0x34);
  if (iVar2 != 0) {
    param_1[0xc] = *(int *)(iVar2 + 0x10);
  }
  return;
}



/* c030b15c FUN_c030b15c */

/* Boundary evidence: original MIPS .pdata c030b15c..c030b40f. Semantic name remains unreviewed. */

int FUN_c030b15c(int *param_1,DWORD param_2,int param_3,int *param_4)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  int *piVar4;
  DWORD DVar5;
  
  DVar5 = param_1[6];
  if ((param_3 != 0) && (param_4 != (int *)0x0)) {
    piVar4 = param_1 + DVar5 + 7;
    do {
      if (0x3f < DVar5) break;
      if (*param_4 == 0) {
        return 0;
      }
      *piVar4 = *param_4;
      param_4 = param_4 + 1;
      param_3 = param_3 + -1;
      DVar5 = DVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (param_3 != 0);
  }
  DVar1 = GetTickCount();
  if (0x3f < DVar5) {
    DVar5 = 0x40;
  }
  DVar5 = WaitForMultipleObjects(DVar5,(HANDLE *)(param_1 + 7),0,param_2);
  DVar2 = GetTickCount();
  (**(code **)(*(int *)param_1[3] + 0x38))((int *)param_1[3],DVar2 - DVar1);
  if (DVar5 == 0x102) {
    iVar3 = 7;
  }
  else if (DVar5 < (uint)param_1[6]) {
    iVar3 = 0;
    switch(DVar5) {
    case 0:
      iVar3 = 0xd;
      break;
    case 1:
      iVar3 = 0xe;
      break;
    case 2:
      iVar3 = (**(code **)(*param_1 + 0x34))(param_1);
      break;
    case 3:
      iVar3 = 8;
      break;
    case 4:
      piVar4 = (int *)param_1[3];
      if (piVar4[0xc] != 0) {
        if (param_1[0xb] == *(int *)(piVar4[0xc] + 0x10)) {
          param_1[0xb] = *(int *)(piVar4[0xc] + 0x14);
          (**(code **)(*piVar4 + 0x30))(piVar4,0);
          (**(code **)(*(int *)param_1[3] + 0x34))((int *)param_1[3],0);
          iVar3 = 1;
        }
        else {
          param_1[0xb] = *(int *)(piVar4[0xc] + 0x10);
          (**(code **)(*piVar4 + 0x30))(piVar4,1);
          (**(code **)(*(int *)param_1[3] + 0x34))((int *)param_1[3],1);
          iVar3 = 2;
        }
      }
      break;
    case 5:
      piVar4 = (int *)param_1[3];
      if (piVar4[0xd] != 0) {
        if (param_1[0xc] == *(int *)(piVar4[0xd] + 0x10)) {
          param_1[0xc] = *(int *)(piVar4[0xd] + 0x14);
          (**(code **)(*piVar4 + 0x34))(piVar4,0);
          iVar3 = 3;
        }
        else {
          param_1[0xc] = *(int *)(piVar4[0xd] + 0x10);
          (**(code **)(*piVar4 + 0x34))(piVar4,1);
          iVar3 = 4;
        }
      }
      break;
    case 6:
      iVar3 = 0xc;
      break;
    case 7:
      iVar3 = 8;
      param_1[0xe] = param_1[4];
      break;
    default:
      iVar3 = (**(code **)(*param_1 + 0x14))(param_1,DVar5);
    }
  }
  else {
    iVar3 = (DVar5 - param_1[6]) + 0x1000;
  }
  return iVar3;
}



/* c030b410 FUN_c030b410 */

/* Boundary evidence: original MIPS .pdata c030b410..c030b61b. Semantic name remains unreviewed. */

LSTATUS FUN_c030b410(int *param_1,int param_2,int param_3)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  LSTATUS LVar3;
  int local_248;
  HKEY local_244;
  HKEY local_240;
  DWORD local_23c [3];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c030d5b0;
  local_240 = (HKEY)0x0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Power",0,
                          (LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_240,local_23c);
  if (LVar1 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x1c))(param_1);
    StringCchPrintfW(awStack_230,0x104,L"State\\%s",uVar2);
    LVar1 = RegCreateKeyExW(local_240,awStack_230,0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,
                            &local_244,local_23c);
    if (LVar1 == 0) {
      if (local_23c[0] == 1) {
        local_248 = param_2;
        LVar1 = RegSetValueExW(local_244,(LPCWSTR)0x0,0,4,(BYTE *)&local_248,4);
        if (LVar1 == 0) {
          param_1[2] = param_3;
          local_248 = param_3;
          LVar1 = RegSetValueExW(local_244,L"Flags",0,4,(BYTE *)&local_248,4);
        }
      }
      else {
        local_23c[2] = 4;
        local_248 = 0;
        local_23c[1] = 0;
        LVar3 = RegQueryValueExW(local_244,L"Flags",(LPDWORD)0x0,local_23c + 1,(LPBYTE)&local_248,
                                 local_23c + 2);
        if (LVar3 == 0) {
          param_1[2] = local_248;
        }
      }
      RegCloseKey(local_244);
    }
  }
  if (local_240 != (HKEY)0x0) {
    RegCloseKey(local_240);
  }
  FUN_c0308a9c(local_28);
  return LVar1;
}



/* c030b61c FUN_c030b61c */

/* Boundary evidence: original MIPS .pdata c030b61c..c030b717. Semantic name remains unreviewed. */

undefined4 * FUN_c030b61c(undefined4 *param_1)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  *param_1 = &PTR_FUN_c03019f0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"PowerManager/ReloadActivityTimeouts");
  param_1[6] = pvVar1;
  pvVar1 = OpenEventW(0x1f0003,0,L"SYSTEM/BootPhase2");
  param_1[7] = pvVar1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[8] = pvVar1;
  uVar2 = FUN_c030c6ac();
  param_1[0xb] = uVar2;
  param_1[10] = DAT_c030d5f8;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[9] = pvVar1;
  puVar3 = FUN_c030794c(L"UserActivity");
  param_1[0xc] = puVar3;
  puVar3 = FUN_c030794c(L"SystemActivity");
  param_1[0xd] = puVar3;
  return param_1;
}



/* c030b718 FUN_c030b718 */

/* Boundary evidence: original MIPS .pdata c030b718..c030b7c7. Semantic name remains unreviewed. */

void FUN_c030b718(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03019f0;
  if ((HANDLE)param_1[6] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[6]);
  }
  if ((HANDLE)param_1[7] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[7]);
  }
  if ((HANDLE)param_1[8] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[8]);
  }
  if (param_1[0xb] != 0) {
    FUN_c030c710();
  }
  if ((HANDLE)param_1[9] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[9]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return;
}



/* c030b7c8 FUN_c030b7c8 */

undefined4 FUN_c030b7c8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((((((*(int *)(param_1 + 0x18) == 0) || (*(int *)(param_1 + 0x20) == 0)) ||
        (*(int *)(param_1 + 0x2c) == 0)) || (*(int *)(param_1 + 0x24) == 0)) ||
      ((iVar2 = *(int *)(param_1 + 0x30), iVar2 != 0 &&
       ((*(int *)(iVar2 + 0x10) == 0 || (*(int *)(iVar2 + 0x14) == 0)))))) ||
     ((iVar2 = *(int *)(param_1 + 0x34), iVar2 != 0 &&
      ((*(int *)(iVar2 + 0x10) == 0 || (*(int *)(iVar2 + 0x14) == 0)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c030b854 FUN_c030b854 */

/* Boundary evidence: original MIPS .pdata c030b854..c030b8f3. Semantic name remains unreviewed. */

int FUN_c030b854(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_c030d5f8;
  if (param_2 != 0) {
    if (param_2 == 1) {
      iVar1 = param_1[6];
    }
    else if (param_2 == 2) {
      iVar1 = param_1[0xb];
    }
    else if (param_2 == 3) {
      iVar1 = param_1[8];
    }
    else if (param_2 == 6) {
      iVar1 = (**(code **)(*param_1 + 0x20))();
    }
    else if (param_2 == 7) {
      iVar1 = param_1[7];
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* c030b8f4 FUN_c030b8f4 */

/* Boundary evidence: original MIPS .pdata c030b8f4..c030b91b. Semantic name remains unreviewed. */

void FUN_c030b8f4(int param_1,int param_2)

{
  if (param_2 != 0) {
    EventModify(*(undefined4 *)(param_1 + 0x20),3);
  }
  return;
}



/* c030b91c FUN_c030b91c */

/* Boundary evidence: original MIPS .pdata c030b91c..c030ba9f. Semantic name remains unreviewed. */

undefined4 FUN_c030b91c(int param_1,uint param_2,wchar_t *param_3,uint param_4)

{
  int iVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  LPVOID local_28 [2];
  
  uVar8 = 2;
  if (((param_2 != 0) && (param_3 != (wchar_t *)0x0)) && (param_4 != 0)) {
    piVar6 = *(int **)(param_1 + 0x38);
    piVar7 = (int *)0x0;
    uVar9 = 0;
    if (piVar6 != (int *)0x0) {
      do {
        local_28[0] = (LPVOID)0x0;
        iVar1 = (**(code **)(*piVar6 + 0x30))(piVar6);
        if (iVar1 == 0) {
LAB_c030ba00:
          if (local_28[0] != (LPVOID)0x0) {
            FUN_c0307570(local_28[0]);
          }
        }
        else {
          pwVar2 = (wchar_t *)(**(code **)(*piVar6 + 0x1c))(piVar6);
          iVar1 = FUN_c0304420(pwVar2,local_28,(undefined4 *)0x0);
          if (iVar1 != 0) goto LAB_c030ba00;
          if (local_28[0] != (LPVOID)0x0) {
            uVar5 = *(uint *)((int)local_28[0] + 8) & param_2;
            uVar4 = 0;
            if (uVar5 != 0) {
              do {
                uVar5 = uVar5 - 1 & uVar5;
                uVar4 = uVar4 + 1;
              } while (uVar5 != 0);
              if (uVar9 < uVar4) {
                piVar7 = piVar6;
                uVar9 = uVar4;
              }
            }
            goto LAB_c030ba00;
          }
        }
        piVar6 = (int *)piVar6[5];
      } while (piVar6 != (int *)0x0);
      if (piVar7 != (int *)0x0) {
        pwVar2 = (wchar_t *)(**(code **)(*piVar7 + 0x1c))(piVar7);
        sVar3 = wcslen(pwVar2);
        if (param_4 < sVar3 + 1) {
          uVar8 = 0x7a;
        }
        else {
          pwVar2 = (wchar_t *)(**(code **)(*piVar7 + 0x1c))(piVar7);
          wcscpy(param_3,pwVar2);
          uVar8 = 0;
        }
      }
    }
  }
  return uVar8;
}



/* c030baa0 FUN_c030baa0 */

/* Boundary evidence: original MIPS .pdata c030baa0..c030bb1b. Semantic name remains unreviewed. */

int FUN_c030baa0(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  HANDLE local_18;
  undefined4 local_14;
  
  local_18 = DAT_c030d5f8;
  iVar2 = 0;
  local_14 = (**(code **)(*param_1 + 0x20))(param_1);
  DVar1 = WaitForMultipleObjects(2,&local_18,0,0xffffffff);
  if (DVar1 == 1) {
    iVar2 = param_1[0xf];
  }
  return iVar2;
}



/* c030bb1c FUN_c030bb1c */

/* Boundary evidence: original MIPS .pdata c030bb1c..c030bba7. Semantic name remains unreviewed. */

undefined4 FUN_c030bb1c(int param_1,wchar_t *param_2)

{
  wchar_t *_Str1;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_2 != (wchar_t *)0x0) {
    for (piVar3 = *(int **)(param_1 + 0x38); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[5]) {
      _Str1 = (wchar_t *)(**(code **)(*piVar3 + 0x1c))(piVar3);
      iVar1 = _wcsicmp(_Str1,param_2);
      if (iVar1 == 0) {
        uVar2 = (**(code **)(*piVar3 + 0x18))(piVar3);
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}



/* c030bba8 FUN_c030bba8 */

/* Boundary evidence: original MIPS .pdata c030bba8..c030bc17. Semantic name remains unreviewed. */

undefined4 FUN_c030bba8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x38);
  while( true ) {
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    iVar1 = (**(code **)(*piVar3 + 0x18))(piVar3);
    if (iVar1 == param_2) break;
    piVar3 = (int *)piVar3[5];
  }
  uVar2 = (**(code **)(*piVar3 + 0x1c))(piVar3);
  return uVar2;
}



/* c030bc18 FUN_c030bc18 */

/* Boundary evidence: original MIPS .pdata c030bc18..c030bc73. Semantic name remains unreviewed. */

int * FUN_c030bc18(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x38);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar1 = (**(code **)(*piVar2 + 0x18))(piVar2);
    if (iVar1 == param_2) break;
    piVar2 = (int *)piVar2[5];
  }
  return piVar2;
}



/* c030bc74 FUN_c030bc74 */

/* Boundary evidence: original MIPS .pdata c030bc74..c030bcdb. Semantic name remains unreviewed. */

undefined4 * FUN_c030bc74(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0301920;
  if ((HANDLE)param_1[4] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[4]);
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030bcdc FUN_c030bcdc */

/* Boundary evidence: original MIPS .pdata c030bcdc..c030bd27. Semantic name remains unreviewed. */

undefined4 * FUN_c030bcdc(undefined4 *param_1,uint param_2)

{
  FUN_c030b718(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c030bd28 FUN_c030bd28 */

/* Boundary evidence: original MIPS .pdata c030bd28..c030bdff. Semantic name remains unreviewed. */

int * FUN_c030bd28(int param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x18))(param_2);
    do {
      iVar3 = (**(code **)(*param_2 + 0x28))(param_2);
      if (iVar3 == iVar2) {
        return param_2;
      }
      piVar4 = FUN_c030bc18(param_1,iVar3);
      if (piVar4 == (int *)0x0) {
        return param_2;
      }
      iVar5 = iVar2;
      if (piVar4 != param_2) {
        (**(code **)(*piVar4 + 4))(piVar4);
        iVar2 = (**(code **)(*piVar4 + 0x28))(piVar4);
        param_2 = piVar4;
        iVar5 = iVar3;
      }
      bVar1 = iVar2 != iVar5;
      iVar2 = iVar5;
    } while (bVar1);
  }
  return param_2;
}



/* c030be00 FUN_c030be00 */

/* Boundary evidence: original MIPS .pdata c030be00..c030bfff. Semantic name remains unreviewed. */

int FUN_c030be00(int *param_1,STRSAFE_LPCWSTR param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  wchar_t local_230 [260];
  uint local_28;
  
  local_28 = DAT_c030d5b0;
  iVar5 = 0;
  local_230[0] = L'\0';
  if (param_2 == (STRSAFE_LPCWSTR)0x0) {
    iVar5 = (**(code **)(*param_1 + 0x10))(param_1,param_3,local_230,0x104,param_1);
  }
  else {
    StringCchCopyW(local_230,0x104,param_2);
  }
  if (iVar5 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,local_230);
    if (((iVar1 == -1) || (piVar2 = FUN_c030bc18((int)param_1,iVar1), piVar2 == (int *)0x0)) ||
       (iVar1 = (**(code **)(*piVar2 + 0x30))(piVar2), iVar1 == 0)) {
      iVar5 = 0x57;
    }
    else {
      if ((param_4 & 0x2000) != 0) {
        uVar3 = __GetUserKData(8);
        uVar4 = __GetUserKData(0xc);
        CaptureDumpFileOnDevice(uVar4,uVar3,0);
      }
      (**(code **)(*piVar2 + 4))(piVar2);
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,piVar2);
      param_1[0xf] = iVar1;
      EventModify(param_1[9],3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  }
  FUN_c0308a9c(local_28);
  return iVar5;
}



/* c030c000 FUN_c030c000 */

/* Boundary evidence: original MIPS .pdata c030c000..c030c00b. Semantic name remains unreviewed. */

undefined4 FUN_c030c000(void)

{
  return 1;
}



/* c030c00c FUN_c030c00c */

/* Boundary evidence: original MIPS .pdata c030c00c..c030c05b. Semantic name remains unreviewed. */

void FUN_c030c00c(undefined4 *param_1)

{
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    param_1 = (undefined4 *)param_1[9];
  }
  CreateFileW((LPCWSTR)*param_1,0,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  return;
}



/* c030c05c FUN_c030c05c */

/* Boundary evidence: original MIPS .pdata c030c05c..c030c07f. Semantic name remains unreviewed. */

void FUN_c030c05c(HANDLE param_1)

{
  CloseHandle(param_1);
  return;
}



/* c030c080 FUN_c030c080 */

/* Boundary evidence: original MIPS .pdata c030c080..c030c0f3. Semantic name remains unreviewed. */

void FUN_c030c080(HANDLE param_1,DWORD param_2,LPVOID param_3,DWORD param_4,LPVOID param_5,
                 DWORD param_6,LPDWORD param_7)

{
  DeviceIoControl(param_1,param_2,param_3,param_4,param_5,param_6,param_7,(LPOVERLAPPED)0x0);
  return;
}



/* c030c0f4 FUN_c030c0f4 */

/* Boundary evidence: original MIPS .pdata c030c0f4..c030c0ff. Semantic name remains unreviewed. */

undefined4 FUN_c030c0f4(void)

{
  return 1;
}



/* c030c100 FUN_c030c100 */

/* Boundary evidence: original MIPS .pdata c030c100..c030c257. Semantic name remains unreviewed. */

undefined4 FUN_c030c100(void)

{
  HMODULE hLibModule;
  
  if (DAT_c030d6b4 == 0) {
    hLibModule = LoadLibraryW(L"coredll.dll");
    if (hLibModule != (HMODULE)0x0) {
      DAT_c030d6b4 = GetProcAddressW(hLibModule,L"CreateDCW");
      DAT_c030d6b8 = GetProcAddressW(hLibModule,L"DeleteDC");
      DAT_c030d6bc = GetProcAddressW(hLibModule,L"ExtEscape");
      if (((DAT_c030d6b4 == 0) || (DAT_c030d6bc == 0)) || (DAT_c030d6b8 == 0)) {
        DAT_c030d6b4 = 0;
        DAT_c030d6b8 = 0;
        DAT_c030d6bc = 0;
        FreeLibrary(hLibModule);
      }
    }
    if (DAT_c030d6b4 == 0) goto LAB_c030c1e0;
  }
  if ((DAT_c030d6bc != 0) && (DAT_c030d6b8 != 0)) {
    if (DAT_c030d6c0 != (HANDLE)0x0) {
      return 1;
    }
    DAT_c030d6c0 = OpenEventW(0x1f0003,0,L"SYSTEM/GweApiSetReady");
  }
LAB_c030c1e0:
  if (DAT_c030d6c0 != (HANDLE)0x0) {
    return 1;
  }
  return 0;
}



/* c030c258 FUN_c030c258 */

/* Boundary evidence: original MIPS .pdata c030c258..c030c39f. Semantic name remains unreviewed. */

int FUN_c030c258(undefined4 *param_1)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (DAT_c030d6c4 == 0) {
    DVar1 = WaitForSingleObject(DAT_c030d6c0,0xffffffff);
    if (DVar1 == 0) {
      CloseHandle(DAT_c030d6c0);
      DAT_c030d6c4 = 1;
    }
    if (DAT_c030d6c4 == 0) {
      return 0;
    }
  }
  iVar2 = (*DAT_c030d6b4)(*param_1,0,0,0);
  if (iVar2 != 0) {
    uVar4 = 0;
    puVar5 = &local_28;
    local_28 = 0x321000;
    local_24 = 0x321008;
    local_20 = 0x321004;
    do {
      iVar3 = (*DAT_c030d6bc)(iVar2,8,4,puVar5,0,0);
      if (iVar3 < 1) break;
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar4 < 3);
    if (2 < uVar4) {
      return iVar2;
    }
    (*DAT_c030d6b8)(iVar2);
  }
  return -1;
}



/* c030c3a0 FUN_c030c3a0 */

/* Boundary evidence: original MIPS .pdata c030c3a0..c030c3c3. Semantic name remains unreviewed. */

void FUN_c030c3a0(void)

{
  (*DAT_c030d6b8)();
  return;
}



/* c030c3c4 FUN_c030c3c4 */

/* Boundary evidence: original MIPS .pdata c030c3c4..c030c46b. Semantic name remains unreviewed. */

undefined4
FUN_c030c3c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = (*DAT_c030d6bc)(param_1,param_2,param_4,param_3,param_6,param_5);
  if (0 < iVar1) {
    uVar2 = 1;
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = param_6;
    }
  }
  return uVar2;
}



/* c030c46c FUN_c030c46c */

/* Boundary evidence: original MIPS .pdata c030c46c..c030c477. Semantic name remains unreviewed. */

undefined4 FUN_c030c46c(void)

{
  return 1;
}



/* c030c478 FUN_c030c478 */

/* Boundary evidence: original MIPS .pdata c030c478..c030c513. Semantic name remains unreviewed. */

undefined4 FUN_c030c478(undefined4 param_1)

{
  undefined4 uVar1;
  
  memset(&DAT_c030d668,0xff,0x1c);
  DAT_c030d6cc = GetProcAddressW(param_1,L"GetSystemPowerStatusEx2");
  DAT_c030d6c8 = GetProcAddressW(param_1,L"BatteryDrvrGetLevels");
  if ((DAT_c030d6cc == 0) || (DAT_c030d6c8 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c030c514 FUN_c030c514 */

/* Boundary evidence: original MIPS .pdata c030c514..c030c6ab. Semantic name remains unreviewed. */

bool FUN_c030c514(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  char local_280;
  undefined1 local_27f;
  undefined1 local_27e;
  undefined4 local_27c;
  undefined4 local_278;
  undefined1 local_273;
  undefined1 local_272;
  undefined4 local_270;
  undefined4 local_26c;
  uint local_248 [3];
  undefined2 local_23c;
  uint local_238 [3];
  undefined1 auStack_22c [524];
  uint local_20;
  
  local_20 = DAT_c030d5b0;
  bVar2 = false;
  if ((DAT_c030d6d0 != 0) || (DAT_c030d6d0 = (*DAT_c030d6c8)(), DAT_c030d6d0 != 0)) {
    iVar5 = (*DAT_c030d6cc)(&local_280,0x38,0);
    if (iVar5 != 0) {
      DAT_c030d6d4 = local_27c;
      DAT_c030d6d8 = local_278;
      DAT_c030d6dc = local_270;
      DAT_c030d6e0 = local_26c;
      DAT_c030d6e4 = local_280;
      DAT_c030d6e5 = local_27f;
      DAT_c030d6e6 = local_27e;
      DAT_c030d6e7 = local_273;
      DAT_c030d6e8 = local_272;
    }
    FUN_c0305c30();
    iVar5 = memcmp(&DAT_c030d668,&DAT_c030d6d0,0x1c);
    cVar4 = DAT_c030d6e4;
    cVar3 = DAT_c030d67c;
    bVar1 = iVar5 != 0;
    if (bVar1) {
      memcpy(&DAT_c030d668,&DAT_c030d6d0,0x1c);
    }
    bVar2 = bVar1 && cVar3 != cVar4;
    FUN_c0305c50();
    if (bVar2) {
      local_248[0] = 4;
      local_248[1] = 0;
      local_248[2] = 0;
      local_23c = 0;
      FUN_c03058b0(local_248);
    }
    if (bVar1) {
      local_238[0] = 8;
      local_238[1] = 0;
      local_238[2] = 0x1c;
      memcpy(auStack_22c,&DAT_c030d6d0,0x1c);
      FUN_c03058b0(local_238);
    }
  }
  FUN_c0308a9c(local_20);
  return bVar2;
}



/* c030c6ac FUN_c030c6ac */

/* Boundary evidence: original MIPS .pdata c030c6ac..c030c70f. Semantic name remains unreviewed. */

void FUN_c030c6ac(void)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  memset(&local_20,0,0x14);
  local_1c = 2;
  local_20 = 0x14;
  local_18 = 10;
  local_14 = 0xc;
  local_10 = 1;
  CreateMsgQueue(L"PowerManager/NotificationQueue",&local_20);
  return;
}



/* c030c710 FUN_c030c710 */

/* Boundary evidence: original MIPS .pdata c030c710..c030c72b. Semantic name remains unreviewed. */

void FUN_c030c710(void)

{
  CloseMsgQueue();
  return;
}



/* c030c72c FUN_c030c72c */

/* Boundary evidence: original MIPS .pdata c030c72c..c030c793. Semantic name remains unreviewed. */

DWORD FUN_c030c72c(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  DWORD DVar2;
  int local_10;
  undefined1 auStack_c [4];
  
  iVar1 = ReadMsgQueue(param_1,param_2,param_3,&local_10,0,auStack_c);
  if (iVar1 == 0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = 0x18;
    if (local_10 == param_3) {
      DVar2 = 0;
    }
  }
  return DVar2;
}


