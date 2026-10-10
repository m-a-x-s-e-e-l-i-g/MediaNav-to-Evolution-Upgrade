/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0702310 FUN_c0702310 */

/* Boundary evidence: original MIPS .pdata c0702310..c070235f. Semantic name remains unreviewed. */

undefined4 FUN_c0702310(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x70) == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x80);
  }
  else if ((*(int *)(param_1 + 0x80) == 0) ||
          (iVar1 = FUN_c0702310(*(int *)(param_1 + 0x70)), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c0702360 FUN_c0702360 */

/* Boundary evidence: original MIPS .pdata c0702360..c07023bb. Semantic name remains unreviewed. */

LONG FUN_c0702360(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0x1f);
  if ((LVar1 < 1) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(param_1,1);
  }
  return LVar1;
}



/* c07023bc FUN_c07023bc */

void FUN_c07023bc(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x70);
  iVar1 = *piVar2;
  while (iVar1 != 0) {
    param_1 = *piVar2;
    piVar2 = (int *)(param_1 + 0x70);
    iVar1 = *piVar2;
  }
  *(undefined4 *)(param_1 + 0x70) = param_2;
  return;
}



/* c07023e8 FUN_c07023e8 */

undefined4 FUN_c07023e8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  while ((-1 < iVar1 && (iVar2 = *(int *)(param_1 + 0x70), iVar2 != 0))) {
    iVar1 = *(int *)(iVar2 + 0x3c);
    param_1 = iVar2;
  }
  return *(undefined4 *)(param_1 + 0x3c);
}



/* c0702418 FUN_c0702418 */

/* Boundary evidence: original MIPS .pdata c0702418..c0702473. Semantic name remains unreviewed. */

undefined4 FUN_c0702418(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)InterlockedExchange((LONG *)(param_1 + 0x70),0);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c0702360(puVar1);
  }
  puVar1 = (undefined4 *)InterlockedExchange((LONG *)(param_1 + 0x6c),0);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c0702360(puVar1);
  }
  return 1;
}



/* c0702474 FUN_c0702474 */

/* Boundary evidence: original MIPS .pdata c0702474..c070248f. Semantic name remains unreviewed. */

void FUN_c0702474(uint param_1)

{
  FUN_c070a040(param_1);
  return;
}



/* c0702490 FUN_c0702490 */

/* Boundary evidence: original MIPS .pdata c0702490..c070261f. Semantic name remains unreviewed. */

undefined4 *
FUN_c0702490(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint auStack_18 [2];
  
  *param_1 = &PTR_FUN_c070103c;
  param_1[0x1a] = param_2;
  param_1[0x1b] = param_5;
  param_1[0x21] = param_4;
  param_1[0x1f] = 0;
  param_1[0x19] = 0;
  param_1[0x1c] = 0;
  uVar1 = InterlockedIncrement((LONG *)&DAT_c0714148);
  param_1[0x1e] = uVar1 & 0xff;
  param_1[1] = 0;
  param_1[2] = 0;
  puVar2 = FUN_c07032bc(param_1[0x1a],auStack_18);
  param_1[3] = *puVar2;
  param_1[4] = *(undefined4 *)(param_3 + 0xc);
  param_1[5] = *(undefined4 *)(param_3 + 0x10);
  *(undefined1 *)(param_1 + 6) = *(undefined1 *)(param_3 + 0x14);
  param_1[7] = *(undefined4 *)(param_3 + 0x18);
  param_1[8] = *(undefined4 *)(param_3 + 0x1c);
  param_1[0xe] = *(undefined4 *)(param_3 + 0x34);
  param_1[0x10] = *(undefined4 *)(param_3 + 0x3c);
  param_1[0x11] = *(undefined4 *)(param_3 + 0x40);
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = *(undefined4 *)(param_3 + 0x4c);
  param_1[0x15] = 0;
  uVar1 = *(uint *)(param_3 + 0x54);
  param_1[0x16] = uVar1;
  param_1[0xf] = 1;
  param_1[0x22] = *(undefined4 *)(param_3 + 0x48);
  if ((((uVar1 & 0x8000) == 0) || (*(uint *)(param_3 + 0x58) == 0)) ||
     (*(int *)(param_3 + 0x5c) == 0)) {
    param_1[0x18] = 0;
    param_1[0x24] = 0;
  }
  else {
    uVar1 = *(uint *)(param_3 + 0x58) >> 4;
    param_1[0x17] = uVar1;
    uVar4 = *(undefined4 *)(param_3 + 0x5c);
    param_1[0x24] = uVar4;
    iVar3 = CeAllocAsynchronousBuffer(param_1 + 0x18,uVar4,uVar1 << 4,4);
    if (-1 < iVar3) goto LAB_c07025e8;
    param_1[0x16] = param_1[0x16] & 0xffff7fff;
    param_1[0x18] = 0;
  }
  param_1[0x17] = 0;
LAB_c07025e8:
  if (param_1[0x1b] != 0) {
    InterlockedIncrement((LONG *)(param_1[0x1b] + 0x7c));
  }
  param_1[0x23] = 0;
  param_1[0x20] = 0;
  param_1[0x1d] = 0;
  return param_1;
}



/* c0702620 FUN_c0702620 */

/* Boundary evidence: original MIPS .pdata c0702620..c07026c3. Semantic name remains unreviewed. */

void FUN_c0702620(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_c070103c;
  FUN_c0702418((int)param_1);
  iVar2 = param_1[0x22];
  if (((iVar2 != 0) && (iVar1 = param_1[0x13], iVar1 != 0)) && (iVar2 != iVar1)) {
    CeFreeAsynchronousBuffer(iVar1,iVar2,param_1[0x11] * param_1[0x10],param_1[0x23]);
  }
  iVar2 = param_1[0x18];
  if (((iVar2 != 0) && (param_1[0x17] != 0)) &&
     ((iVar1 = param_1[0x24], iVar1 != 0 && (iVar1 != iVar2)))) {
    CeFreeAsynchronousBuffer(iVar2,iVar1,param_1[0x17] << 4,4);
  }
  return;
}



/* c07026c4 FUN_c07026c4 */

/* Boundary evidence: original MIPS .pdata c07026c4..c070284f. Semantic name remains unreviewed. */

undefined4 FUN_c07026c4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint auStack_38 [2];
  code *local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(int *)(param_1 + 0x6c) == 0) {
    iVar2 = FUN_c0702310(param_1);
    if (iVar2 != 0) {
      if ((-1 < *(int *)(param_1 + 0x3c)) && (iVar2 = *(int *)(param_1 + 0x70), iVar2 != 0)) {
        iVar3 = *(int *)(iVar2 + 0x3c);
        if ((-1 < iVar3) && (*(int *)(iVar2 + 0x70) != 0)) {
          iVar3 = FUN_c07023e8(*(int *)(iVar2 + 0x70));
        }
        *(int *)(param_1 + 0x3c) = iVar3;
      }
      local_30 = (code *)InterlockedExchange((LONG *)(param_1 + 0x50),0);
      if (local_30 != (code *)0x0) {
        if (*(int *)(param_1 + 0x84) == 0) {
          uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x68) + 0x490);
          puVar4 = FUN_c07032bc(*(int *)(param_1 + 0x68),auStack_38);
          (*local_30)(*puVar4,*(undefined4 *)(param_1 + 0x74),uVar1,*(undefined4 *)(param_1 + 0x38))
          ;
        }
        else {
          puVar4 = FUN_c07032bc(*(int *)(param_1 + 0x68),auStack_38);
          local_2c = *puVar4;
          local_28 = *(undefined4 *)(param_1 + 0x74);
          local_24 = *(undefined4 *)(*(int *)(param_1 + 0x68) + 0x490);
          local_20 = *(undefined4 *)(param_1 + 0x38);
          CeDriverPerformCallback(*(undefined4 *)(param_1 + 0x84),0x2a0500,&local_30,0x14,0,0,0,0);
        }
      }
    }
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_c07026c4(*(int *)(param_1 + 0x6c));
  }
  return uVar1;
}



/* c0702850 FUN_c0702850 */

/* Boundary evidence: original MIPS .pdata c0702850..c070286f. Semantic name remains unreviewed. */

void FUN_c0702850(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c0702870 FUN_c0702870 */

undefined4 FUN_c0702870(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((((*(uint *)(*(int *)(param_1 + 0x68) + 0x488) & 1) != 0) ||
      (((iVar2 = *(int *)(param_1 + 0x3c), iVar2 != -0x3fffffec && (iVar2 != -0x3fffffeb)) &&
       (iVar2 != -0x3ffffff3)))) || (uVar1 = 1, (*(uint *)(param_1 + 0x10) & 0xff) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c07028d4 FUN_c07028d4 */

/* Boundary evidence: original MIPS .pdata c07028d4..c0702bbb. Semantic name remains unreviewed. */

int FUN_c07028d4(int param_1)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  bool bVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uStack_94;
  undefined4 local_90;
  undefined1 auStack_8c [4];
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  char local_7c;
  uint local_78;
  undefined4 local_74;
  undefined1 local_70;
  undefined1 auStack_6f [16];
  undefined1 auStack_5f [3];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [8];
  uint local_30;
  
  local_30 = DAT_c0714140;
  uVar10 = *(uint *)(param_1 + 0x44);
  uVar3 = uVar10 * *(int *)(param_1 + 0x40);
  cVar1 = *(char *)(param_1 + 0x18);
  iVar12 = 1;
  if (0x1ff < uVar10) {
    uVar10 = 0x200;
  }
  if (cVar1 == '5') {
    uVar9 = *(uint *)(param_1 + 0x1c) & 0xf7fffe00 | uVar10;
    if ((*(uint *)(param_1 + 0x1c) & 0x4000000) == 0) {
      bVar4 = false;
      goto LAB_c070298c;
    }
  }
  else {
    uVar9 = *(uint *)(param_1 + 0x1c);
    *(char *)(param_1 + 0x18) = cVar1 + -1;
  }
  bVar4 = true;
LAB_c070298c:
  *(undefined4 *)(param_1 + 0x40) = 1;
  *(uint *)(param_1 + 0x44) = uVar10;
  uVar11 = uVar3 - uVar10;
  *(uint *)(param_1 + 0x1c) = uVar9;
  if (uVar3 <= uVar10) {
    uVar11 = 0;
  }
  if (bVar4) {
    if (cVar1 == '5') {
      uVar9 = (uVar10 * 0x200 + uVar9 ^ uVar9) & 0x3fffe00 ^ uVar9;
    }
    else {
      uVar9 = uVar9 + uVar10;
    }
  }
  while ((uVar11 != 0 && (iVar12 != 0))) {
    local_90 = 0;
    memset(auStack_8c,0,4);
    puVar5 = FUN_c07032bc(*(int *)(param_1 + 0x68),&uStack_94);
    local_88 = *puVar5;
    local_80 = *(undefined4 *)(param_1 + 0x14);
    local_74 = *(undefined4 *)(param_1 + 0x20);
    local_84 = 0;
    local_70 = 0;
    local_7c = cVar1;
    local_78 = uVar9;
    memset(auStack_6f,0,0x10);
    memset(auStack_5f,0,3);
    local_3c = *(undefined4 *)(param_1 + 0x58);
    local_58 = 0xc0000003;
    local_54 = 1;
    local_48 = *(undefined4 *)(param_1 + 0x4c);
    local_5c = 0;
    local_4c = 0;
    local_44 = 0;
    local_40 = 0;
    local_50 = uVar10;
    memset(auStack_38,0,8);
    puVar6 = FUN_c070a040(0x94);
    if (puVar6 == (undefined4 *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = FUN_c0702490(puVar6,*(undefined4 *)(param_1 + 0x68),(int)&local_90,0,param_1);
    }
    if ((piVar7 == (int *)0x0) || (iVar8 = (**(code **)(*piVar7 + 4))(piVar7), iVar8 == 0)) {
      iVar12 = 0;
      if (piVar7 != (int *)0x0) {
        (**(code **)*piVar7)(piVar7,1);
      }
    }
    else {
      InterlockedIncrement(piVar7 + 0x1f);
      if (*(int *)(param_1 + 0x70) == 0) {
        *(int **)(param_1 + 0x70) = piVar7;
      }
      else {
        FUN_c07023bc(*(int *)(param_1 + 0x70),piVar7);
      }
      bVar2 = uVar11 <= uVar10;
      uVar11 = uVar11 - uVar10;
      if (bVar2) {
        uVar11 = 0;
      }
      if (bVar4) {
        if (cVar1 == '5') {
          uVar9 = (uVar10 * 0x200 + uVar9 ^ uVar9) & 0x3fffe00 ^ uVar9;
        }
        else {
          uVar9 = uVar9 + uVar10;
        }
      }
    }
  }
  FUN_c0712ee4(local_30);
  return iVar12;
}



/* c0702bbc FUN_c0702bbc */

/* Boundary evidence: original MIPS .pdata c0702bbc..c0702d8b. Semantic name remains unreviewed. */

undefined4 FUN_c0702bbc(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint auStack_80 [2];
  undefined4 local_78;
  undefined1 auStack_74 [4];
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64;
  uint local_60;
  undefined4 local_5c;
  undefined1 local_58;
  undefined1 auStack_57 [16];
  undefined1 auStack_47 [3];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 auStack_20 [8];
  uint local_18;
  
  local_18 = DAT_c0714140;
  uVar5 = 1;
  if ((*(uint *)(param_1 + 0x58) & 3) != 0) {
    local_78 = 0;
    memset(auStack_74,0,4);
    puVar1 = FUN_c07032bc(*(int *)(param_1 + 0x68),auStack_80);
    local_70 = *puVar1;
    local_6c = 0;
    local_68 = 2;
    local_64 = 0xc;
    local_60 = 0;
    local_5c = 2;
    local_58 = 0;
    memset(auStack_57,0,0x10);
    memset(auStack_47,0,3);
    local_44 = 0;
    local_40 = 0xc0000003;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    memset(auStack_20,0,8);
    if ((*(uint *)(param_1 + 0x58) & 2) != 0) {
      local_64 = 0x34;
      local_60 = *(byte *)(*(int *)(param_1 + 0x68) + 0x6d0) | 0x80000c00;
      local_5c = 6;
    }
    puVar2 = FUN_c070a040(0x94);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_c0702490(puVar2,*(undefined4 *)(param_1 + 0x68),(int)&local_78,0,param_1);
    }
    if ((piVar3 == (int *)0x0) || (iVar4 = (**(code **)(*piVar3 + 4))(piVar3), iVar4 == 0)) {
      uVar5 = 0;
      if (piVar3 != (int *)0x0) {
        (**(code **)*piVar3)(piVar3,1);
      }
    }
    else {
      InterlockedIncrement(piVar3 + 0x1f);
      if (*(int *)(param_1 + 0x70) == 0) {
        *(int **)(param_1 + 0x70) = piVar3;
      }
      else {
        FUN_c07023bc(*(int *)(param_1 + 0x70),piVar3);
      }
    }
  }
  FUN_c0712ee4(local_18);
  return uVar5;
}



/* c0702d8c FUN_c0702d8c */

/* Boundary evidence: original MIPS .pdata c0702d8c..c0702dd7. Semantic name remains unreviewed. */

undefined4 * FUN_c0702d8c(undefined4 *param_1,uint param_2)

{
  FUN_c0702620(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c070935c((int)param_1);
  }
  return param_1;
}



/* c0702dd8 FUN_c0702dd8 */

/* Boundary evidence: original MIPS .pdata c0702dd8..c0703067. Semantic name remains unreviewed. */

int FUN_c0702dd8(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = *(int *)(param_1 + 0x14);
  iVar7 = 1;
  if ((iVar3 == 0) || (iVar3 == 1)) {
    uVar5 = *(uint *)(param_1 + 0x40);
    if ((uVar5 == 0) || (iVar4 = *(int *)(param_1 + 0x88), iVar4 == 0)) {
      uVar2 = 0xc0000007;
LAB_c0702e28:
      *(undefined4 *)(param_1 + 0x3c) = uVar2;
      goto LAB_c070303c;
    }
    uVar6 = *(uint *)(param_1 + 0x44);
    if ((uVar6 == 0) || (*(int *)(param_1 + 0x84) == 0)) {
      *(int *)(param_1 + 0x4c) = iVar4;
    }
    else {
      uVar2 = 8;
      if (iVar3 != 0) {
        uVar2 = 4;
      }
      *(undefined4 *)(param_1 + 0x8c) = uVar2;
      if (((0xffff < uVar5) || (0xffff < uVar6)) ||
         (iVar3 = CeAllocAsynchronousBuffer(param_1 + 0x4c,iVar4,uVar6 * uVar5), iVar3 < 0)) {
        uVar2 = 0xc0000005;
        *(undefined4 *)(param_1 + 0x4c) = 0;
        goto LAB_c0702e28;
      }
    }
  }
  iVar3 = *(int *)(param_1 + 0x68);
  if ((*(int *)(iVar3 + 0x48c) == 2) || (*(int *)(iVar3 + 0x48c) == 1)) {
    if (*(int *)(param_1 + 0x14) == 0) {
      *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(iVar3 + 0x724);
    }
    else if (*(int *)(param_1 + 0x14) == 1) {
      *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(iVar3 + 0x720);
    }
  }
  *(undefined1 *)(param_1 + 0x10) = 0;
  if (DAT_c0714150 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(uint *)(DAT_c0714150 + 0xb0);
  }
  uVar6 = uVar5 & 0xff | *(uint *)(param_1 + 0x10);
  uVar5 = 0x1000;
  *(uint *)(param_1 + 0x10) = uVar6;
  if ((*(uint *)(param_1 + 0x58) & 8) == 0) {
    uVar5 = 0;
  }
  *(uint *)(param_1 + 0x10) = uVar6 | uVar5;
  if (*(int *)(param_1 + 0x6c) != 0) {
    return 1;
  }
  bVar1 = *(byte *)(iVar3 + 0x709);
  if ((((1 < *(uint *)(param_1 + 0x40)) && (*(char *)(param_1 + 0x18) == '5')) &&
      (((*(int *)(param_1 + 0x14) == 0 && ((bVar1 & 0x14) != 0)) ||
       ((*(int *)(param_1 + 0x14) == 1 && ((bVar1 & 0x18) != 0)))))) ||
     (((*(char *)(param_1 + 0x18) == '\x12' && ((bVar1 & 0x11) != 0)) ||
      ((*(char *)(param_1 + 0x18) == '\x19' && ((bVar1 & 0x12) != 0)))))) {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffff7fff;
    iVar7 = FUN_c07028d4(param_1);
  }
  if ((((*(char *)(param_1 + 0x18) != '\x12') || ((bVar1 & 0x11) == 0)) &&
      ((*(char *)(param_1 + 0x18) != '\x19' || ((bVar1 & 0x12) == 0)))) && ((bVar1 & 0x10) == 0)) {
    iVar7 = FUN_c0702bbc(param_1);
  }
  if (iVar7 != 0) {
    return iVar7;
  }
LAB_c070303c:
  *(undefined4 *)(param_1 + 0x80) = 1;
  return 0;
}



/* c0703068 FUN_c0703068 */

/* Boundary evidence: original MIPS .pdata c0703068..c07030b7. Semantic name remains unreviewed. */

void FUN_c0703068(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* c07030b8 FUN_c07030b8 */

/* Boundary evidence: original MIPS .pdata c07030b8..c070310b. Semantic name remains unreviewed. */

undefined4 FUN_c07030b8(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  undefined4 local_10;
  DWORD local_c;
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_c = 4;
    local_10 = param_3;
    RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_10,&local_c);
    param_3 = local_10;
  }
  return param_3;
}



/* c070310c FUN_c070310c */

/* Boundary evidence: original MIPS .pdata c070310c..c0703167. Semantic name remains unreviewed. */

LONG FUN_c070310c(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 < 1) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(param_1,1);
  }
  return LVar1;
}



/* c0703168 FUN_c0703168 */

/* Boundary evidence: original MIPS .pdata c0703168..c07031ab. Semantic name remains unreviewed. */

undefined4 * FUN_c0703168(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0701044;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c07031ac FUN_c07031ac */

/* Boundary evidence: original MIPS .pdata c07031ac..c07031cb. Semantic name remains unreviewed. */

void FUN_c07031ac(void)

{
  undefined4 in_a3;
  
  EventModify(in_a3,3);
  return;
}



/* c07031cc FUN_c07031cc */

/* Boundary evidence: original MIPS .pdata c07031cc..c0703257. Semantic name remains unreviewed. */

int FUN_c07031cc(int param_1,uint param_2)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  if (param_2 < 8) {
    iVar1 = *(int *)((param_2 + 0x32) * 4 + param_1);
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    InterlockedIncrement((LONG *)(iVar1 + 4));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  return iVar1;
}



/* c0703258 FUN_c0703258 */

/* Boundary evidence: original MIPS .pdata c0703258..c07032ab. Semantic name remains unreviewed. */

bool FUN_c0703258(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x42c) != 0;
  if (bVar1) {
    memset((void *)(param_1 + 0x738),0,0x20);
    *(undefined4 *)(param_1 + 0x73c) = 100000;
  }
  return bVar1;
}



/* c07032bc FUN_c07032bc */

uint * FUN_c07032bc(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x43c) == 0) {
    *param_2 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x438);
    *param_2 = ((*(uint *)(param_1 + 0x434) & 7) << 4 |
               *(uint *)(*(int *)(param_1 + 0x430) + 0x80) & 0xf) << 4 |
               *(uint *)(*(int *)(*(int *)(param_1 + 0x430) + 0x7c) + 0x5c) & 0xf |
               *param_2 & 0xfffff800;
    *(short *)((int)param_2 + 2) = (short)uVar1;
    *param_2 = *param_2 & 0xffff7fff | 0x7800;
  }
  return param_2;
}



/* c0703340 FUN_c0703340 */

/* Boundary evidence: original MIPS .pdata c0703340..c0703427. Semantic name remains unreviewed. */

undefined4 FUN_c0703340(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_30 [5];
  char local_2b;
  byte local_2a;
  uint local_18;
  
  local_18 = DAT_c0714140;
  uVar3 = 0;
  if ((param_1[0x123] != 3) && (param_1[0x123] != 4)) {
    uVar2 = 2;
    if ((*(uint *)(param_1[0x10c] + 0x6c) & 0xf80000) != 0) {
      uVar2 = 1;
    }
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1,8,uVar2 << 8 | 0x5a,2,8,auStack_30,0,0,0,8,0,0);
    if (((-1 < iVar1) && (local_2b == 'Z')) && (local_2a == uVar2)) {
      uVar3 = 1;
    }
  }
  FUN_c0712ee4(local_18);
  return uVar3;
}



/* c0703428 FUN_c0703428 */

/* Boundary evidence: original MIPS .pdata c0703428..c070352b. Semantic name remains unreviewed. */

int FUN_c0703428(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    iVar1 = *(int *)(param_1 + 0x424);
    iVar2 = iVar1;
    do {
      if (*(int *)((iVar2 + 7) * 4 + param_1) == 0) break;
      *(uint *)(param_1 + 0x424) = iVar2 + 1U;
      if (*(uint *)(param_1 + 0x41c) <= iVar2 + 1U) {
        *(undefined4 *)(param_1 + 0x424) = 0;
      }
      iVar2 = *(int *)(param_1 + 0x424);
    } while (iVar1 != iVar2);
    iVar2 = 0;
    if ((*(uint *)(param_1 + 0x424) < *(uint *)(param_1 + 0x41c)) &&
       (piVar3 = (int *)((*(uint *)(param_1 + 0x424) + 7) * 4 + param_1), *piVar3 == 0)) {
      *piVar3 = param_3;
      InterlockedIncrement((LONG *)(param_3 + 0x7c));
      iVar2 = param_3;
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(param_1 + 0x424);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  return iVar2;
}



/* c070352c FUN_c070352c */

/* Boundary evidence: original MIPS .pdata c070352c..c070369b. Semantic name remains unreviewed. */

int FUN_c070352c(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 local_40;
  byte local_3f [7];
  undefined1 auStack_38 [24];
  uint local_20;
  
  local_20 = DAT_c0714140;
  if (param_1[0x123] == 3) {
    bVar1 = true;
  }
  else {
    if (param_1[0x123] == 4) {
      bVar1 = true;
      iVar2 = (**(code **)(*param_1 + 0x10))(param_1,0,0,0,local_3f,1);
      if ((iVar2 < 0) || (local_3f[0] >> 4 == 0)) goto LAB_c07035c4;
    }
    bVar1 = false;
  }
LAB_c07035c4:
  if ((param_1[0x123] == 2) || (param_1[0x123] == 4)) {
    iVar2 = (**(code **)(*param_1 + 0x38))(param_1,0x2a,0,2,1,auStack_38,0,0,0);
    if (-1 < iVar2) goto LAB_c070362c;
LAB_c070361c:
    FUN_c0712ee4(local_20);
  }
  else {
LAB_c070362c:
    if (bVar1) {
      local_40 = 0x80;
      iVar2 = (**(code **)(*param_1 + 0x10))(param_1,1,7,1,&local_40,1);
      if (iVar2 < 0) goto LAB_c070361c;
    }
    FUN_c0712ee4(local_20);
    iVar2 = 0;
  }
  return iVar2;
}



/* c070369c FUN_c070369c */

/* Boundary evidence: original MIPS .pdata c070369c..c070398b. Semantic name remains unreviewed. */

int FUN_c070369c(int *param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  uint dwMilliseconds;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint local_50 [2];
  undefined1 auStack_48 [5];
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  byte local_40;
  uint local_30;
  
  local_30 = DAT_c0714140;
  bVar1 = false;
  if (param_2 == 1) {
    uVar6 = 1;
LAB_c070373c:
    uVar5 = 0x32;
    uVar7 = 4;
  }
  else {
    if (param_2 == 2) {
      uVar6 = 0x29;
      bVar1 = true;
      goto LAB_c070373c;
    }
    if (param_2 != 3) {
      FUN_c0712ee4(DAT_c0714140);
      return -0x3ffffff9;
    }
    uVar6 = 5;
    uVar7 = 5;
    uVar5 = 2;
  }
  if (param_4 != 0) {
    iVar4 = *(int *)(param_1[0x10c] + 0x7c);
    iVar3 = iVar4 + 8;
    if (iVar4 == 0) {
      iVar3 = 0;
    }
    local_50[0] = param_3;
    iVar3 = (**(code **)(iVar4 + 0x44))(iVar3,*(undefined4 *)(param_1[0x10c] + 0x80),0,local_50,4);
    if (iVar3 < 0) goto LAB_c0703950;
    FUN_c070d3c0(param_1[0x10c]);
  }
  if (param_2 != 3) {
    iVar3 = (**(code **)(*param_1 + 0x14))(param_1,0,0,2,0,0,0,0,0,8,0,0);
    if (iVar3 < 0) goto LAB_c0703950;
    if (((param_2 == 2) || (param_2 == 1)) && (iVar3 = FUN_c0703340(param_1), iVar3 != 0)) {
      param_3 = param_3 | 0x40000000;
    }
  }
  uVar2 = FUN_c070945c(L"PowerUpPollingTime",2000);
  dwMilliseconds = FUN_c070945c(L"PowerUpPollingInterval",uVar5);
  uVar2 = uVar2 / dwMilliseconds;
  if (dwMilliseconds == 0) {
    trap(0x1c00);
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    if (bVar1) {
      iVar3 = (**(code **)(*param_1 + 0x38))();
    }
    else {
      iVar3 = (**(code **)(*param_1 + 0x14))(param_1,uVar6,param_3,2,uVar7,auStack_48,0,0,0,8,0,0);
    }
    if (iVar3 < 0) {
LAB_c0703940:
      if (uVar2 != 0) goto LAB_c0703950;
      break;
    }
    if (param_2 == 3) {
      if ((local_40 & 0x80) != 0) {
LAB_c0703928:
        *(undefined1 *)((int)param_1 + 0x49a) = local_43;
        *(undefined1 *)((int)param_1 + 0x49b) = local_42;
        *(undefined1 *)(param_1 + 0x127) = local_41;
        goto LAB_c0703940;
      }
    }
    else if ((local_40 & 0x80) != 0) {
      *(byte *)((int)param_1 + 0x49d) = local_40;
      goto LAB_c0703928;
    }
    Sleep(dwMilliseconds);
  }
  iVar3 = -0x3fffffee;
LAB_c0703950:
  FUN_c0712ee4(local_30);
  return iVar3;
}



/* c070398c FUN_c070398c */

/* Boundary evidence: original MIPS .pdata c070398c..c0703d4b. Semantic name remains unreviewed. */

int FUN_c070398c(int *param_1,STRSAFE_LPWSTR param_2,size_t param_3,int param_4)

{
  wchar_t *pwVar1;
  int iVar2;
  uint uVar3;
  wchar_t *pszFormat;
  int iVar4;
  byte local_88;
  char local_87;
  char local_86;
  char local_84;
  char local_83;
  char local_82;
  char local_81;
  char local_80;
  wchar_t awStack_60 [4];
  wchar_t awStack_58 [4];
  wchar_t awStack_50 [4];
  wchar_t awStack_48 [4];
  wchar_t awStack_40 [4];
  wchar_t awStack_38 [4];
  wchar_t awStack_30 [4];
  uint local_28;
  
  local_28 = DAT_c0714140;
  iVar2 = param_1[0x123];
  iVar4 = 0;
  if (((iVar2 == 2) || (iVar2 == 1)) || (iVar2 == 4)) {
    iVar4 = (**(code **)(*param_1 + 0x34))(param_1,1,&local_88,0x28);
    if (-1 < iVar4) {
      uVar3 = (uint)local_87;
      pszFormat = L"%c";
      if (((int)uVar3 < 0x20) || (pwVar1 = pszFormat, 0x7e < (int)uVar3)) {
        pwVar1 = L"%02x";
      }
      StringCchPrintfW(awStack_40,3,pwVar1,uVar3 & 0xffff);
      uVar3 = (uint)local_86;
      if (((int)uVar3 < 0x20) || (pwVar1 = pszFormat, 0x7e < (int)uVar3)) {
        pwVar1 = L"%02x";
      }
      StringCchPrintfW(awStack_50,3,pwVar1,uVar3 & 0xffff);
      uVar3 = (uint)local_84;
      if (((int)uVar3 < 0x20) || (pwVar1 = pszFormat, 0x7e < (int)uVar3)) {
        pwVar1 = L"%02x";
      }
      StringCchPrintfW(awStack_58,3,pwVar1,uVar3 & 0xffff);
      uVar3 = (uint)local_83;
      if (((int)uVar3 < 0x20) || (pwVar1 = pszFormat, 0x7e < (int)uVar3)) {
        pwVar1 = L"%02x";
      }
      StringCchPrintfW(awStack_60,3,pwVar1,uVar3 & 0xffff);
      uVar3 = (uint)local_82;
      if (((int)uVar3 < 0x20) || (pwVar1 = pszFormat, 0x7e < (int)uVar3)) {
        pwVar1 = L"%02x";
      }
      StringCchPrintfW(awStack_38,3,pwVar1,uVar3 & 0xffff);
      uVar3 = (uint)local_81;
      if (((int)uVar3 < 0x20) || (pwVar1 = pszFormat, 0x7e < (int)uVar3)) {
        pwVar1 = L"%02x";
      }
      StringCchPrintfW(awStack_30,3,pwVar1,uVar3 & 0xffff);
      uVar3 = (uint)local_80;
      if (((int)uVar3 < 0x20) || (0x7e < (int)uVar3)) {
        pszFormat = L"%02x";
      }
      StringCchPrintfW(awStack_48,3,pszFormat,uVar3 & 0xffff);
      StringCchPrintfW(param_2,param_3,L"%s\\CID-%d-%s%s-%s%s%s%s%s",
                       L"\\Drivers\\SDCARD\\ClientDrivers\\Custom",(uint)local_88,awStack_40,
                       awStack_50,awStack_58,awStack_60,awStack_38,awStack_30,awStack_48);
    }
  }
  else if (iVar2 == 3) {
    if (param_4 == 0) {
      StringCchPrintfW(param_2,param_3,L"%s\\MANF-%04X-CARDID-%04X-FUNC-%d",
                       L"\\Drivers\\SDCARD\\ClientDrivers\\Custom",
                       (uint)*(ushort *)(param_1[0x1b9] + 8),(uint)*(ushort *)(param_1[0x1b9] + 10),
                       (uint)*(byte *)(param_1 + 0x1b4));
    }
    else {
      StringCchPrintfW(param_2,param_3,L"%s\\MANF-%04X-CARDID-%04X",
                       L"\\Drivers\\SDCARD\\ClientDrivers\\Custom",
                       (uint)*(ushort *)(param_1[0x1b9] + 8),(uint)*(ushort *)(param_1[0x1b9] + 10))
      ;
    }
  }
  else {
    iVar4 = -0x3ffffff9;
  }
  if (local_88 == 0x90) {
    param_1[0x1d8] = 1;
  }
  FUN_c0712ee4(local_28);
  return iVar4;
}



/* c0703d4c FUN_c0703d4c */

/* Boundary evidence: original MIPS .pdata c0703d4c..c0704173. Semantic name remains unreviewed. */

int FUN_c0703d4c(int *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  LSTATUS LVar4;
  HRESULT HVar5;
  uint *puVar6;
  undefined4 *puVar7;
  wchar_t *pwVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int local_258 [4];
  HKEY local_248 [2];
  wchar_t *local_240;
  int *local_23c;
  undefined4 local_238;
  undefined4 local_234;
  wchar_t awStack_230 [256];
  uint local_30;
  
  local_30 = DAT_c0714140;
  bVar1 = false;
  iVar3 = FUN_c070398c(param_1,awStack_230,0x100,0);
  if (iVar3 < 0) {
    FUN_c0712ee4(local_30);
    return iVar3;
  }
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,awStack_230,0,0xf003f,local_248);
  if (LVar4 == 0) {
    RegCloseKey(local_248[0]);
  }
  else {
    iVar3 = param_1[0x123];
    if ((iVar3 == 2) || (iVar3 == 4)) {
      pwVar8 = L"\\Drivers\\SDCARD\\ClientDrivers\\Class\\SDMemory_Class";
    }
    else {
      if (iVar3 != 1) {
        if ((iVar3 != 3) || (*(byte *)((int)param_1 + 0x6d1) == 0)) goto LAB_c0703ecc;
        StringCchPrintfW(awStack_230,0x100,L"%s\\%d",
                         L"\\Drivers\\SDCARD\\ClientDrivers\\Class\\SDIO_Class",
                         (uint)*(byte *)((int)param_1 + 0x6d1));
        goto LAB_c0703ec8;
      }
      pwVar8 = L"\\Drivers\\SDCARD\\ClientDrivers\\Class\\MMC_Class";
    }
    HVar5 = StringCchCopyW(awStack_230,0x100,pwVar8);
    if (HVar5 < 0) goto LAB_c0703ecc;
    iVar3 = FUN_c070e210((int)param_1);
    if (iVar3 != 0) {
      HVar5 = StringCchCatW(awStack_230,0x100,L"\\High_Capacity");
    }
    if (HVar5 < 0) goto LAB_c0703ecc;
  }
LAB_c0703ec8:
  bVar1 = true;
LAB_c0703ecc:
  piVar2 = DAT_c0714150;
  if (((bVar1) && (DAT_c0714150 != (int *)0x0)) && (param_1[0x108] == 0)) {
    iVar3 = -0x3ffffffd;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    puVar6 = FUN_c07032bc((int)param_1,(uint *)(local_258 + 1));
    local_258[3] = *puVar6;
    local_23c = local_258 + 3;
    local_240 = L"ClientInfo";
    local_238 = 4;
    local_234 = 4;
    puVar7 = operator_new(0x60);
    if (puVar7 == (undefined4 *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      uVar12 = *(undefined4 *)(param_1[0x10c] + 0x80);
      iVar13 = piVar2[8];
      uVar11 = *(undefined4 *)(*(int *)(param_1[0x10c] + 0x7c) + 0x5c);
      pwVar8 = FUN_c07094d4((int)piVar2);
      piVar9 = FUN_c07114f4(puVar7,pwVar8,awStack_230,0,uVar11,uVar12,param_1[0x10d],iVar13,8,
                            (wchar_t *)0x0);
    }
    param_1[0x108] = (int)piVar9;
    if (((piVar9 == (int *)0x0) || (iVar13 = (**(code **)(*piVar9 + 4))(piVar9), iVar13 == 0)) ||
       ((iVar13 = FUN_c071184c(param_1[0x108],1,(int *)&local_240), iVar13 == 0 ||
        (iVar13 = (**(code **)(*piVar2 + 0x44))(piVar2,param_1[0x108]), iVar13 == 0)))) {
      puVar7 = (undefined4 *)param_1[0x108];
      if (puVar7 != (undefined4 *)0x0) {
        (**(code **)*puVar7)(puVar7,1);
        param_1[0x108] = 0;
      }
    }
    else {
      InterlockedIncrement((LONG *)(param_1[0x108] + 4));
      *(undefined4 *)(param_1[0x10c] + 0x84) = 2;
      (**(code **)(*(int *)param_1[0x108] + 8))();
      if ((param_1[0x123] == 3) && (param_1[0x1ba] != 0)) {
        local_258[2] = 4;
        local_258[1] = 0;
        LVar4 = RegQueryValueExW(*(HKEY *)(param_1[0x108] + 8),L"WakeOnSDIOInterrupts",(LPDWORD)0x0,
                                 (LPDWORD)(local_258 + 1),(LPBYTE)local_258,(LPDWORD)(local_258 + 2)
                                );
        if (LVar4 != 0) {
          local_258[0] = 0;
        }
        if (local_258[0] != 0) {
          iVar10 = *(int *)(param_1[0x10c] + 0x7c);
          iVar13 = iVar10 + 8;
          if (iVar10 == 0) {
            iVar13 = 0;
          }
          (**(code **)(iVar10 + 0x44))(iVar13,*(undefined4 *)(param_1[0x10c] + 0x80),10,local_258,4)
          ;
        }
      }
      if (((undefined4 *)param_1[0x108])[10] == 0) {
        param_1[0x125] = 0;
      }
      else {
        iVar3 = 0;
      }
      FUN_c070310c((undefined4 *)param_1[0x108]);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c0712ee4(local_30);
    if (-1 < iVar3) {
      iVar3 = 0;
    }
  }
  else {
    FUN_c0712ee4(local_30);
    iVar3 = -0x3ffffff8;
  }
  return iVar3;
}



/* c0704174 FUN_c0704174 */

/* Boundary evidence: original MIPS .pdata c0704174..c07042c7. Semantic name remains unreviewed. */

int FUN_c0704174(int param_1,int param_2,undefined4 param_3,STRSAFE_LPCWSTR param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 0x444) == 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x444) = 0;
    }
    else {
      iVar1 = __GetUserKData(0xc);
      iVar2 = CeDriverGetDirectCaller();
      if (iVar2 == iVar1) {
        *(int *)(param_1 + 0x444) = param_2;
        *(undefined4 *)(param_1 + 0x440) = 0;
      }
      else {
        uVar3 = CeDriverDuplicateCallerHandle(param_2,0,0,2);
        *(undefined4 *)(param_1 + 0x444) = uVar3;
        *(undefined4 *)(param_1 + 0x440) = 1;
      }
      if (*(int *)(param_1 + 0x444) == 0) {
        iVar4 = -0x3ffffffa;
      }
    }
    if (-1 < iVar4) {
      StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x448),0x20,param_4);
      *(undefined4 *)(param_1 + 0x490) = param_3;
      *(undefined4 *)(param_1 + 0x494) = *(undefined4 *)(param_4 + 0x20);
      *(undefined4 *)(param_1 + 0x488) = *(undefined4 *)(param_4 + 0x22);
    }
  }
  else {
    iVar4 = -0x3ffffffb;
  }
  return iVar4;
}



/* c07042c8 FUN_c07042c8 */

/* Boundary evidence: original MIPS .pdata c07042c8..c07042e7. Semantic name remains unreviewed. */

void FUN_c07042c8(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c07042e8 FUN_c07042e8 */

/* Boundary evidence: original MIPS .pdata c07042e8..c07043af. Semantic name remains unreviewed. */

void FUN_c07042e8(int *param_1)

{
  int iVar1;
  int iVar2;
  uint local_120 [2];
  char local_118;
  byte local_117;
  uint local_18;
  
  local_18 = DAT_c0714140;
  iVar2 = 0;
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1,0x22,0,local_120,0);
  if ((-1 < iVar1) && (local_120[0] < 0x101)) {
    iVar1 = (**(code **)(*param_1 + 0x30))(param_1,0x22,&local_118,local_120,0);
    if ((-1 < iVar1) && ((local_118 == '\x01' && ((local_117 & 1) != 0)))) {
      iVar2 = 1;
    }
  }
  param_1[0x1ba] = iVar2;
  FUN_c0712ee4(local_18);
  return;
}



/* c07043b0 FUN_c07043b0 */

/* Boundary evidence: original MIPS .pdata c07043b0..c0704463. Semantic name remains unreviewed. */

void FUN_c07043b0(undefined4 param_1,char *param_2,short *param_3)

{
  char cVar1;
  size_t sVar2;
  short *psVar3;
  uint uVar4;
  
  uVar4 = 0;
  sVar2 = strlen(param_2);
  psVar3 = param_3;
  if (sVar2 != 0) {
    do {
      *psVar3 = (short)param_2[uVar4];
      cVar1 = param_2[uVar4];
      if ((cVar1 < '!') || ('~' < cVar1)) {
        *psVar3 = 0x5f;
      }
      uVar4 = uVar4 + 1;
      sVar2 = strlen(param_2);
      psVar3 = psVar3 + 1;
    } while (uVar4 < sVar2);
  }
  param_3[uVar4] = 0;
  return;
}



/* c0704464 FUN_c0704464 */

/* Boundary evidence: original MIPS .pdata c0704464..c07046d7. Semantic name remains unreviewed. */

void FUN_c0704464(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(*param_1 + 0x14))
                    (param_1,0x37,(uint)*(ushort *)(param_1 + 0x126) << 0x10,2,1,param_6,0,0,0,8,0,0
                    );
  if (-1 < iVar1) {
    uVar2 = param_1[0x122];
    if ((uVar2 & 1) == 0) {
      param_1[0x122] = uVar2 | 1;
      iVar1 = (**(code **)(*param_1 + 0x14))
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,8,0
                         ,0);
      if (iVar1 < 0) {
        if (DAT_c0714150 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(uint *)(DAT_c0714150 + 0xb0);
        }
        uVar4 = 0;
        if (uVar3 != 0) {
          do {
            if ((((iVar1 != -0x3fffffec) && (iVar1 != -0x3fffffeb)) && (iVar1 != -0x3ffffff3)) ||
               (iVar1 = (**(code **)(*param_1 + 0x14))
                                  (param_1,0x37,(uint)*(ushort *)(param_1 + 0x126) << 0x10,2,1,
                                   param_6,0,0,0,8,0,0), iVar1 < 0)) break;
            iVar1 = (**(code **)(*param_1 + 0x14))
                              (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                               param_9,8,0,0);
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar3);
        }
      }
      param_1[0x122] = uVar2;
    }
    else {
      (**(code **)(*param_1 + 0x14))();
    }
  }
  return;
}



/* c07046d8 FUN_c07046d8 */

/* Boundary evidence: original MIPS .pdata c07046d8..c070470b. Semantic name remains unreviewed. */

void FUN_c07046d8(int param_1,int param_2)

{
  *(undefined2 *)(param_1 + 0x498) = *(undefined2 *)(param_2 + 0x498);
  *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(param_2 + 0x6c8);
  memcpy((void *)(param_1 + 0x49a),(void *)(param_2 + 0x49a),0x22c);
  return;
}



/* c070470c FUN_c070470c */

/* Boundary evidence: original MIPS .pdata c070470c..c070483b. Semantic name remains unreviewed. */

void FUN_c070470c(int param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  code *pcVar3;
  uint auStack_38 [2];
  int local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if (*(int *)(param_1 + 0x420) != 0) {
    iVar2 = *(int *)(param_1 + 0x444);
    if ((iVar2 == 0) || (*(int *)(param_1 + 0x494) == 0)) {
      pcVar3 = *(code **)(param_1 + 0x494);
      if (pcVar3 != (code *)0x0) {
        puVar1 = FUN_c07032bc(param_1,auStack_38);
        (*pcVar3)(*puVar1,*(undefined4 *)(param_1 + 0x490),param_2,0,0);
      }
    }
    else {
      local_30 = *(int *)(param_1 + 0x494);
      puVar1 = FUN_c07032bc(param_1,auStack_38);
      local_2c = *puVar1;
      local_28 = *(undefined4 *)(param_1 + 0x490);
      local_20 = 0;
      local_1c = 0;
      local_24 = param_2;
      CeDriverPerformCallback(iVar2,0x2a0504,&local_30,0x18,0,0,0,0);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return;
}



/* c070483c FUN_c070483c */

/* Boundary evidence: original MIPS .pdata c070483c..c070485b. Semantic name remains unreviewed. */

void FUN_c070483c(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070485c FUN_c070485c */

/* WARNING: Removing unreachable block (ram,0xc07049f8) */
/* Boundary evidence: original MIPS .pdata c070485c..c0704d2f. Semantic name remains unreviewed. */

int FUN_c070485c(int param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uStack_9c;
  int local_98;
  undefined4 local_90;
  undefined1 auStack_8c [4];
  uint local_88;
  uint local_84;
  undefined4 local_80;
  undefined1 local_7c;
  uint local_78;
  undefined4 local_74;
  undefined1 local_70;
  undefined1 local_6f;
  byte local_6e;
  undefined1 auStack_5f [3];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  code *local_44;
  undefined4 local_40;
  uint local_3c [3];
  uint local_30;
  
  local_30 = DAT_c0714140;
  iVar6 = -0x3ffffffd;
  iVar4 = iVar6;
  local_98 = param_1;
  if ((param_5 != 0) && (iVar4 = -0x3ffffffd, param_6 != 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x430) + 0xe8));
    uVar10 = param_4;
    for (uVar9 = 0; uVar9 < param_6; uVar9 = uVar9 + 1) {
      if (param_2 == 0) {
        uVar11 = 0;
      }
      else {
        uVar11 = (uint)*(byte *)(param_5 + uVar9);
      }
      uVar7 = *(uint *)(param_1 + 0x434);
      local_90 = 0;
      memset(auStack_8c,0,4);
      puVar1 = FUN_c07032bc(param_1,&uStack_9c);
      local_88 = *puVar1;
      local_84 = 0;
      local_80 = 2;
      local_7c = 0x34;
      local_74 = 6;
      local_70 = 0;
      local_78 = (((param_2 & 0xff) << 3 | uVar7 & 7) << 1 | uVar10 & 1) << 0x1b |
                 (uVar9 + param_3) * 0x200 & 0x3fffe00 | uVar11;
      memset(&local_6f,0,0x10);
      memset(auStack_5f,0,3);
      local_58 = 0xc0000003;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_40 = 0;
      memset(local_3c,0,0xc);
      if ((*(byte *)(param_1 + 0x709) & 0x20) == 0) {
        local_3c[0] = local_3c[0] | 4;
        local_84 = local_84 | 0x80000000;
      }
      local_44 = FUN_c07031ac;
      local_5c = *(undefined4 *)(param_1 + 0x42c);
      EventModify(local_5c,2);
      puVar2 = (undefined4 *)FUN_c0702474(0x94);
      if (puVar2 == (undefined4 *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = FUN_c0702490(puVar2,param_1,(int)&local_90,0,0);
      }
      if (piVar3 != (int *)0x0) {
        iVar4 = (**(code **)(*piVar3 + 4))(piVar3);
        if (iVar4 == 0) {
          if (piVar3 != (int *)0x0) {
            (**(code **)*piVar3)(piVar3,1);
          }
        }
        else {
          InterlockedIncrement(piVar3 + 0x1f);
          piVar8 = piVar3;
          do {
            iVar4 = FUN_c070da4c((undefined4 *)(*(int *)(param_1 + 0x430) + 0x44),piVar3);
            if (iVar4 < 0) break;
            piVar8 = (int *)piVar8[0x1c];
          } while (piVar8 != (int *)0x0);
          for (; piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x1c]) {
            piVar8[0xf] = iVar4;
            piVar8[0x20] = 1;
            piVar5 = (int *)piVar8[0x1b];
            if ((int *)piVar8[0x1b] == (int *)0x0) {
              piVar5 = piVar8;
            }
            FUN_c07026c4((int)piVar5);
          }
          iVar4 = FUN_c0702310((int)piVar3);
          if (iVar4 == 0) {
            WaitForSingleObject(*(HANDLE *)(param_1 + 0x42c),0xffffffff);
          }
          memcpy(&local_90,piVar3 + 1,0x60);
          iVar6 = piVar3[0xf];
          if ((-1 < iVar6) && (piVar3[0x1c] != 0)) {
            iVar6 = FUN_c07023e8(piVar3[0x1c]);
          }
          FUN_c0702360(piVar3);
        }
      }
      if (iVar6 < 0) break;
      if ((local_6e & 0x4b) != 0) {
        iVar6 = -0x3fffffea;
        break;
      }
      iVar6 = 0;
      uVar10 = param_4 & 0xff;
      if ((uVar10 != 0) || (param_2 == 0)) {
        *(undefined1 *)(param_5 + uVar9) = local_6f;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x430) + 0xe8));
    iVar4 = iVar6;
  }
  FUN_c0712ee4(local_30);
  return iVar4;
}



/* c0704d30 FUN_c0704d30 */

/* Boundary evidence: original MIPS .pdata c0704d30..c0704d4f. Semantic name remains unreviewed. */

void FUN_c0704d30(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c0704d50 FUN_c0704d50 */

/* Boundary evidence: original MIPS .pdata c0704d50..c07050eb. Semantic name remains unreviewed. */

int FUN_c0704d50(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                void *param_6,int param_7,int param_8,undefined4 param_9,uint param_10,
                undefined4 param_11,undefined4 param_12)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  uint uStack_98;
  int local_94;
  undefined4 local_90;
  undefined1 auStack_8c [4];
  uint local_88;
  uint local_84;
  undefined4 local_80;
  undefined1 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 local_70;
  undefined1 auStack_6f [16];
  undefined1 auStack_5f [3];
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  code *local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  
  local_30 = DAT_c0714140;
  iVar7 = -0x3ffffffd;
  local_94 = param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x430) + 0xe8));
  local_90 = 0;
  memset(auStack_8c,0,4);
  puVar1 = FUN_c07032bc(param_1,&uStack_98);
  local_88 = *puVar1;
  local_84 = 0;
  local_7c = (undefined1)param_2;
  local_74 = param_5;
  local_70 = 0;
  local_80 = param_4;
  local_78 = param_3;
  memset(auStack_6f,0,0x10);
  memset(auStack_5f,0,3);
  local_58 = -0x3ffffffd;
  local_54 = param_7;
  local_50 = param_8;
  local_4c = 0;
  local_48 = param_9;
  local_40 = 0;
  local_3c = param_10;
  local_38 = param_11;
  local_34 = param_12;
  if (((param_2 == 2) || ((uint)(param_7 * param_8) <= *(uint *)(*(int *)(param_1 + 0x430) + 0x104))
      ) && ((*(byte *)(param_1 + 0x709) & 0x20) == 0)) {
    local_3c = param_10 | 4;
    local_84 = local_84 | 0x80000000;
  }
  local_44 = FUN_c07031ac;
  local_5c = *(undefined4 *)(param_1 + 0x42c);
  EventModify(local_5c,2);
  puVar2 = (undefined4 *)FUN_c0702474(0x94);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_c0702490(puVar2,param_1,(int)&local_90,0,0);
  }
  if (piVar3 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar3 + 4))(piVar3);
    if (iVar4 == 0) {
      if (piVar3 != (int *)0x0) {
        (**(code **)*piVar3)(piVar3,1);
      }
    }
    else {
      InterlockedIncrement(piVar3 + 0x1f);
      piVar6 = piVar3;
      do {
        iVar7 = FUN_c070da4c((undefined4 *)(*(int *)(param_1 + 0x430) + 0x44),piVar6);
        if (iVar7 < 0) break;
        piVar6 = (int *)piVar6[0x1c];
      } while (piVar6 != (int *)0x0);
      for (; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x1c]) {
        piVar6[0xf] = iVar7;
        piVar6[0x20] = 1;
        piVar5 = (int *)piVar6[0x1b];
        if ((int *)piVar6[0x1b] == (int *)0x0) {
          piVar5 = piVar6;
        }
        FUN_c07026c4((int)piVar5);
      }
      iVar4 = FUN_c0702310((int)piVar3);
      if (iVar4 == 0) {
        WaitForSingleObject(*(HANDLE *)(param_1 + 0x42c),0xffffffff);
      }
      memcpy(&local_90,piVar3 + 1,0x60);
      if (-1 < iVar7) {
        iVar7 = local_58;
      }
      FUN_c0702418((int)piVar3);
      FUN_c0702360(piVar3);
    }
  }
  if ((-1 < iVar7) && (param_6 != (void *)0x0)) {
    memcpy(param_6,&local_74,0x18);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x430) + 0xe8));
  FUN_c0712ee4(local_30);
  return iVar7;
}



/* c07050ec FUN_c07050ec */

/* Boundary evidence: original MIPS .pdata c07050ec..c070510b. Semantic name remains unreviewed. */

void FUN_c07050ec(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070510c FUN_c070510c */

/* WARNING: Removing unreachable block (ram,0xc07053d0) */
/* Boundary evidence: original MIPS .pdata c070510c..c0705493. Semantic name remains unreviewed. */

undefined4
FUN_c070510c(int *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,uint *param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  uint local_a0;
  int *local_9c;
  int *local_98;
  undefined4 local_90;
  undefined1 auStack_8c [4];
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 local_70;
  undefined1 auStack_6f [16];
  undefined1 auStack_5f [3];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  
  local_30 = DAT_c0714140;
  local_98 = param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1[0x10c] + 0xe8));
  local_90 = 0;
  memset(auStack_8c,0,4);
  puVar1 = FUN_c07032bc((int)param_1,(uint *)&local_9c);
  local_88 = *puVar1;
  local_84 = 0;
  local_74 = param_5;
  local_70 = 0;
  local_80 = param_4;
  local_7c = param_2;
  local_78 = param_3;
  memset(auStack_6f,0,0x10);
  memset(auStack_5f,0,3);
  local_5c = param_10;
  local_58 = 0xc0000003;
  local_54 = param_6;
  local_50 = param_7;
  local_4c = 0;
  local_48 = param_8;
  local_44 = param_9;
  local_40 = 0;
  local_3c = param_12;
  local_38 = param_13;
  local_34 = param_14;
  puVar2 = (undefined4 *)FUN_c0702474(0x94);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_c0702490(puVar2,param_1,(int)&local_90,param_1[0x111],0);
  }
  local_9c = piVar3;
  if (((param_11 == (uint *)0x0) || (piVar3 == (int *)0x0)) ||
     (iVar4 = (**(code **)(*piVar3 + 4))(piVar3), iVar4 == 0)) {
    uVar7 = 0xc000000a;
    if (piVar3 != (int *)0x0) {
      (**(code **)*piVar3)(piVar3,1);
    }
  }
  else {
    local_a0 = 0;
    InterlockedIncrement(piVar3 + 0x1f);
    iVar4 = FUN_c0703428((int)param_1,&local_a0,(int)piVar3);
    if (iVar4 == 0) {
      uVar7 = 0xc000000a;
    }
    else {
      local_a0 = (((piVar3[0x1e] << 8 | local_a0 & 0xff) << 8 | param_1[0x10d] & 7U | 0xf8) << 4 |
                 *(uint *)(param_1[0x10c] + 0x80) & 0xf) << 4 |
                 *(uint *)(*(int *)(param_1[0x10c] + 0x7c) + 0x5c) & 0xf;
      *param_11 = local_a0;
      piVar3[0x1d] = local_a0;
      piVar6 = piVar3;
      do {
        iVar4 = FUN_c070da4c((undefined4 *)(param_1[0x10c] + 0x44),piVar6);
        if (iVar4 < 0) break;
        piVar6 = (int *)piVar6[0x1c];
      } while (piVar6 != (int *)0x0);
      for (; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x1c]) {
        piVar6[0xf] = iVar4;
        piVar6[0x20] = 1;
        piVar5 = (int *)piVar6[0x1b];
        if ((int *)piVar6[0x1b] == (int *)0x0) {
          piVar5 = piVar6;
        }
        FUN_c07026c4((int)piVar5);
      }
      uVar7 = 1;
    }
    FUN_c0702360(piVar3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[0x10c] + 0xe8));
  FUN_c0712ee4(local_30);
  return uVar7;
}



/* c0705494 FUN_c0705494 */

/* Boundary evidence: original MIPS .pdata c0705494..c07054b3. Semantic name remains unreviewed. */

void FUN_c0705494(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c07054b4 FUN_c07054b4 */

/* Boundary evidence: original MIPS .pdata c07054b4..c0705587. Semantic name remains unreviewed. */

void FUN_c07054b4(int param_1)

{
  uint *puVar1;
  code *pcVar2;
  int iVar3;
  uint auStack_30 [2];
  code *local_28;
  uint local_24;
  undefined4 local_20;
  
  pcVar2 = *(code **)(param_1 + 0x6e0);
  if (pcVar2 != (code *)0x0) {
    iVar3 = *(int *)(param_1 + 0x444);
    if (iVar3 == 0) {
      puVar1 = FUN_c07032bc(param_1,auStack_30);
      (*pcVar2)(*puVar1,*(undefined4 *)(param_1 + 0x490));
    }
    else {
      local_28 = pcVar2;
      puVar1 = FUN_c07032bc(param_1,auStack_30);
      local_24 = *puVar1;
      local_20 = *(undefined4 *)(param_1 + 0x490);
      CeDriverPerformCallback(iVar3,0x2a0508,&local_28,0xc,0,0,0,0);
    }
  }
  return;
}



/* c0705588 FUN_c0705588 */

/* Boundary evidence: original MIPS .pdata c0705588..c07055a7. Semantic name remains unreviewed. */

void FUN_c0705588(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c07055a8 FUN_c07055a8 */

/* Boundary evidence: original MIPS .pdata c07055a8..c0705727. Semantic name remains unreviewed. */

int FUN_c07055a8(int param_1,int param_2,int param_3)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  byte local_20 [8];
  
  if (((*(int *)(param_1 + 0x48c) == 3) &&
      (((param_3 == 0 || (param_2 != 0)) && (*(int *)(param_1 + 0x434) != 0)))) &&
     (piVar1 = (int *)FUN_c07031cc(*(int *)(param_1 + 0x430),0), piVar1 != (int *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    if (param_3 == 0) {
      *(undefined4 *)(param_1 + 0x6e0) = 0;
      iVar3 = piVar1[0x1b9];
      bVar2 = ~(byte)(1 << (*(byte *)(param_1 + 0x6d0) & 0x1f)) & *(byte *)(iVar3 + 0x10);
    }
    else {
      *(int *)(param_1 + 0x6e0) = param_2;
      iVar3 = piVar1[0x1b9];
      bVar2 = (byte)(1 << (*(byte *)(param_1 + 0x6d0) & 0x1f)) | *(byte *)(iVar3 + 0x10) | 1;
    }
    *(byte *)(iVar3 + 0x10) = bVar2;
    local_20[0] = *(byte *)(piVar1[0x1b9] + 0x10);
    if ((local_20[0] & 0xfe) == 0) {
      *(byte *)(piVar1[0x1b9] + 0x10) = local_20[0] & 0xfe;
      local_20[0] = local_20[0] & 0xfe;
    }
    if (param_3 == 0) {
      if (local_20[0] == 0) {
        FUN_c070d684(*(int *)(param_1 + 0x430));
      }
    }
    else {
      FUN_c070d5e8(*(int *)(param_1 + 0x430));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    iVar3 = (**(code **)(*piVar1 + 0x10))(piVar1,1,4,0,local_20,1);
    if (iVar3 < 0) {
      *(undefined4 *)(param_1 + 0x6e0) = 0;
    }
    FUN_c070310c(piVar1);
  }
  else {
    iVar3 = -0x3ffffff9;
  }
  return iVar3;
}



/* c0705728 FUN_c0705728 */

/* Boundary evidence: original MIPS .pdata c0705728..c070577b. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_c0705728(LPCRITICAL_SECTION param_1)

{
  HANDLE pvVar1;
  ULONG_PTR *pUVar2;
  
  InitializeCriticalSection(param_1);
  param_1[0x2b].OwningThread = (HANDLE)0x100;
  pvVar1 = (HANDLE)0x0;
  pUVar2 = &param_1->SpinCount;
  do {
    *pUVar2 = 0;
    pvVar1 = (HANDLE)((int)pvVar1 + 1);
    pUVar2 = pUVar2 + 1;
  } while (pvVar1 < param_1[0x2b].OwningThread);
  return param_1;
}



/* c070577c FUN_c070577c */

/* Boundary evidence: original MIPS .pdata c070577c..c0705803. Semantic name remains unreviewed. */

void FUN_c070577c(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  ULONG_PTR *pUVar2;
  HANDLE pvVar3;
  
  EnterCriticalSection(param_1);
  pvVar3 = (HANDLE)0x0;
  if (param_1[0x2b].OwningThread != (HANDLE)0x0) {
    pUVar2 = &param_1->SpinCount;
    do {
      puVar1 = (undefined4 *)*pUVar2;
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(puVar1,1);
      }
      pvVar3 = (HANDLE)((int)pvVar3 + 1);
      pUVar2 = pUVar2 + 1;
    } while (pvVar3 < param_1[0x2b].OwningThread);
  }
  LeaveCriticalSection(param_1);
  DeleteCriticalSection(param_1);
  return;
}



/* c0705804 FUN_c0705804 */

/* Boundary evidence: original MIPS .pdata c0705804..c070587b. Semantic name remains unreviewed. */

ULONG_PTR FUN_c0705804(LPCRITICAL_SECTION param_1,HANDLE param_2)

{
  ULONG_PTR UVar1;
  
  EnterCriticalSection(param_1);
  if (param_2 < param_1[0x2b].OwningThread) {
    UVar1 = (&param_1->SpinCount)[(int)param_2];
  }
  else {
    UVar1 = 0;
  }
  if (UVar1 != 0) {
    InterlockedIncrement((LONG *)(UVar1 + 0x7c));
  }
  LeaveCriticalSection(param_1);
  return UVar1;
}



/* c070587c FUN_c070587c */

/* Boundary evidence: original MIPS .pdata c070587c..c07058f7. Semantic name remains unreviewed. */

undefined4 * FUN_c070587c(LPCRITICAL_SECTION param_1,HANDLE param_2)

{
  undefined4 *puVar1;
  
  EnterCriticalSection(param_1);
  puVar1 = (undefined4 *)0x0;
  if (param_2 < param_1[0x2b].OwningThread) {
    puVar1 = (undefined4 *)(&param_1->SpinCount)[(int)param_2];
    (&param_1->SpinCount)[(int)param_2] = 0;
  }
  LeaveCriticalSection(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c0702360(puVar1);
  }
  return puVar1;
}



/* c07058f8 FUN_c07058f8 */

/* Boundary evidence: original MIPS .pdata c07058f8..c070598f. Semantic name remains unreviewed. */

bool FUN_c07058f8(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

{
  LSTATUS LVar1;
  
  if (*param_1 != (HKEY)0x0) {
    RegCloseKey(*param_1);
    *param_1 = (HKEY)0x0;
  }
  param_1[1] = (HKEY)0x0;
  LVar1 = RegOpenKeyExW(param_2,param_3,0,param_4,param_1);
  return LVar1 == 0;
}



/* c0705990 FUN_c0705990 */

/* Boundary evidence: original MIPS .pdata c0705990..c0705a9b. Semantic name remains unreviewed. */

undefined4 * FUN_c0705990(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  LONG LVar1;
  HANDLE pvVar2;
  
  *param_1 = &PTR_FUN_c0701044;
  param_1[1] = 0;
  FUN_c0705728((LPCRITICAL_SECTION)(param_1 + 2));
  *param_1 = &PTR_FUN_c0701340;
  param_1[0x10c] = param_3;
  param_1[0x10d] = param_2;
  param_1[0x123] = 0;
  *(undefined2 *)(param_1 + 0x126) = 0;
  LVar1 = InterlockedIncrement((LONG *)&DAT_c071414c);
  param_1[0x10e] = LVar1;
  param_1[0x10f] = 0;
  param_1[0x108] = 0;
  param_1[0x111] = 0;
  param_1[0x110] = 0;
  *(undefined2 *)(param_1 + 0x112) = 0;
  param_1[0x122] = 0;
  param_1[0x123] = 0;
  param_1[0x124] = 0;
  param_1[0x125] = 0;
  *(undefined2 *)(param_1 + 0x126) = 0;
  param_1[0x1b2] = 0;
  param_1[0x1b3] = 0;
  memset(param_1 + 0x1b4,0,0x68);
  param_1[0x1c9] = 0xffffffff;
  param_1[0x1c8] = 0xffffffff;
  *(char *)(param_1 + 0x1b4) = (char)param_2;
  param_1[0x1d6] = 0;
  param_1[0x1d7] = 0;
  param_1[0x109] = 0;
  param_1[0x10a] = 0;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[0x10b] = pvVar2;
  param_1[0x1d8] = 0;
  return param_1;
}



/* c0705a9c FUN_c0705a9c */

/* Boundary evidence: original MIPS .pdata c0705a9c..c0705ed3. Semantic name remains unreviewed. */

int FUN_c0705a9c(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined1 auStack_48 [4];
  undefined1 uStack_44;
  undefined4 local_43;
  undefined1 auStack_30 [7];
  undefined1 local_29;
  uint local_28;
  
  local_28 = DAT_c0714140;
  if (param_1[0x10d] != 0) {
    FUN_c0712ee4(DAT_c0714140);
    return -0x3fffffe9;
  }
  if (param_1[0x123] != 3) {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1,2,0,2,3,auStack_48,0,0,0,8,0,0);
    if (iVar1 < 0) goto LAB_c0705b4c;
    memcpy((void *)((int)param_1 + 0x49e),&uStack_44,0x10);
  }
  if (param_1[0x123] == 1) {
    uVar2 = (uint)*(ushort *)((int)param_1 + 0x4ab) + *(int *)(param_1[0x10c] + 0x80);
    *(short *)(param_1 + 0x126) = (short)uVar2;
    if ((uVar2 & 0xffff) == 0) {
      *(undefined2 *)(param_1 + 0x126) = 1;
    }
    iVar1 = (**(code **)(*param_1 + 0x14))
                      (param_1,3,(uint)*(ushort *)(param_1 + 0x126) << 0x10,2,1,auStack_48,0,0,0,8,0
                       ,0);
    if (iVar1 < 0) goto LAB_c0705b4c;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1,3,0,2,7,auStack_48,0,0,0,8,0,0);
    if (iVar1 < 0) goto LAB_c0705b4c;
    *(undefined2 *)(param_1 + 0x126) = local_43._2_2_;
  }
  if (param_1[0x123] != 3) {
    iVar1 = (**(code **)(*param_1 + 0x14))
                      (param_1,9,(uint)*(ushort *)(param_1 + 0x126) << 0x10,2,3,auStack_48,0,0,0,8,0
                       ,0);
    if (iVar1 < 0) goto LAB_c0705b4c;
    memcpy((void *)((int)param_1 + 0x4ae),&uStack_44,0x10);
    iVar1 = (**(code **)(*param_1 + 0x14))
                      (param_1,0xd,(uint)*(ushort *)(param_1 + 0x126) << 0x10,2,1,auStack_48,0,0,0,8
                       ,0,0);
    if (iVar1 < 0) goto LAB_c0705b4c;
    if ((local_43 & 0x2000000) != 0) {
      param_1[0x1ca] = 1;
    }
  }
  iVar1 = (**(code **)(*param_1 + 0x14))
                    (param_1,7,(uint)*(ushort *)(param_1 + 0x126) << 0x10,2,2,auStack_48,0,0,0,8,0,0
                    );
  if (-1 < iVar1) {
    if (param_1[0x123] == 1) {
      iVar1 = (**(code **)(*param_1 + 0x14))
                        (param_1,8,0,0,1,auStack_48,1,0x200,(void *)((int)param_1 + 0x4c6),4,0,0);
      if (iVar1 < 0) {
        NKDbgPrintfW(L"CSDDevice(%d): ECSD Command FAILED!\r\n",0x1bd);
        memset((void *)((int)param_1 + 0x4c6),0,0x200);
      }
    }
    if (((param_1[0x123] == 2) || (param_1[0x123] == 4)) && (param_1[0x1ca] == 0)) {
      iVar1 = (**(code **)(*param_1 + 0x38))(param_1,0x33,0,0,1,auStack_48,1,8,auStack_30);
      if (iVar1 < 0) {
        memset((void *)((int)param_1 + 0x4be),0,8);
      }
      else {
        uVar2 = 0;
        puVar3 = &local_29;
        do {
          iVar1 = uVar2 + 0x4be;
          uVar2 = uVar2 + 1;
          *(undefined1 *)((int)param_1 + iVar1) = *puVar3;
          puVar3 = puVar3 + -1;
        } while (uVar2 < 8);
      }
    }
    FUN_c0712ee4(local_28);
    return 0;
  }
LAB_c0705b4c:
  FUN_c0712ee4(local_28);
  return iVar1;
}



/* c0705ed4 FUN_c0705ed4 */

/* Boundary evidence: original MIPS .pdata c0705ed4..c0706263. Semantic name remains unreviewed. */

int FUN_c0705ed4(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 local_48 [8];
  undefined1 auStack_40 [24];
  uint local_28;
  
  local_28 = DAT_c0714140;
  iVar4 = param_1[0x123];
  iVar5 = 0;
  bVar1 = false;
  bVar2 = false;
  if ((iVar4 == 3) || (iVar4 == 4)) {
    bVar1 = true;
  }
  if (((iVar4 == 1) || (iVar4 == 2)) || (iVar4 == 4)) {
    bVar2 = true;
  }
  if (param_3 == 0) {
    if ((param_2 == 7) || (param_2 == 5)) {
      if (param_1[0x10d] == 0) {
        if (bVar1) {
          local_48[0] = 8;
          iVar5 = (**(code **)(*param_1 + 0x10))(param_1,1,6,0,local_48,1);
          if (-1 < iVar5) {
            *(undefined1 *)(param_1[0x1b9] + 0x11) = 0;
          }
        }
        if ((bVar2) && (-1 < iVar5)) {
          iVar5 = (**(code **)(*param_1 + 0x14))(param_1,0,0,2,0,0,0,0,0,8,0,0);
        }
      }
      *(undefined2 *)(param_1 + 0x126) = 0;
      param_1[0x1d7] = 0;
    }
    goto LAB_c0706230;
  }
  if (param_1[0x10d] != 0) {
    puVar3 = (undefined4 *)FUN_c07031cc(param_1[0x10c],0);
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined2 *)(param_1 + 0x126) = *(undefined2 *)(puVar3 + 0x126);
      param_1[0x1b2] = puVar3[0x1b2];
      memcpy((void *)((int)param_1 + 0x49a),(void *)((int)puVar3 + 0x49a),0x22c);
      FUN_c070310c(puVar3);
    }
    goto LAB_c0706230;
  }
  if (bVar1) {
    if (*(int *)(param_1[0x10c] + 0x84) != 5) {
      local_48[0] = 8;
      iVar5 = (**(code **)(*param_1 + 0x14))(param_1,0x34,0x80000c08,2,6,auStack_40,0,0,0,8,0,0);
      *(undefined2 *)(param_1 + 0x126) = 0;
      if (iVar5 < 0) goto LAB_c0706050;
    }
    iVar5 = (**(code **)(*param_1 + 0x14))(param_1,5,0,2,5,auStack_40,0,0,0,8,0,0);
    if ((-1 < iVar5) && (iVar5 = FUN_c070369c(param_1,3,param_1[0x1b2],0), -1 < iVar5)) {
      iVar5 = FUN_c0705a9c(param_1);
    }
  }
LAB_c0706050:
  if (bVar2) {
    iVar5 = (**(code **)(*param_1 + 0x14))(param_1,0,0,2,0,0,0,0,0,8,0,0);
    if (-1 < iVar5) {
      *(undefined2 *)(param_1 + 0x126) = 0;
      if ((param_1[0x123] == 2) || (param_1[0x123] == 4)) {
        iVar5 = (**(code **)(*param_1 + 0x38))(param_1,0x29,0,2,4,auStack_40,0,0,0);
      }
      if ((-1 < iVar5) &&
         (iVar5 = FUN_c070369c(param_1,param_1[0x123],param_1[0x1b2],0), -1 < iVar5)) {
        iVar5 = FUN_c0705a9c(param_1);
      }
    }
  }
LAB_c0706230:
  FUN_c0712ee4(local_28);
  return iVar5;
}



/* c0706264 FUN_c0706264 */

/* Boundary evidence: original MIPS .pdata c0706264..c0706343. Semantic name remains unreviewed. */

int FUN_c0706264(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_20;
  
  iVar3 = -0x3fffffe9;
  if (param_3 != 0) {
    iVar2 = param_1[0x123];
    if ((((iVar2 == 2) || (iVar2 == 1)) || (iVar2 == 3)) || (iVar2 == 4)) {
      local_20 = (uint)*(ushort *)((int)param_1 + 0x49b) << 8 |
                 *(byte *)((int)param_1 + 0x49a) & 0xfffffff0;
    }
    uVar1 = FUN_c070d3f4(param_1[0x10c],local_20);
    param_1[0x1b2] = uVar1;
  }
  if (param_1[0x1b2] != 0) {
    iVar3 = FUN_c070369c(param_1,param_2,param_1[0x1b2],param_3);
  }
  return iVar3;
}



/* c0706344 FUN_c0706344 */

/* Boundary evidence: original MIPS .pdata c0706344..c070645b. Semantic name remains unreviewed. */

void FUN_c0706344(int *param_1)

{
  int iVar1;
  uint uVar2;
  HKEY local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_c0714140;
  iVar1 = FUN_c070398c(param_1,awStack_218,0x100,1);
  if (iVar1 < 0) goto LAB_c070643c;
  local_228 = (HKEY)0x0;
  local_224 = 0;
  local_220 = 0;
  local_21c = 0;
  FUN_c07058f8(&local_228,(HKEY)0x80000002,awStack_218,0x20019);
  if (local_228 != (HKEY)0x0) {
    iVar1 = FUN_c07030b8(&local_228,L"SDClockRateOverride",0xffffffff);
    if (iVar1 != -1) {
      param_1[0x1cf] = iVar1;
    }
    iVar1 = FUN_c07030b8(&local_228,L"SDInterfaceOverride",0xffffffff);
    if (iVar1 != -1) {
      if (iVar1 == 0) {
        uVar2 = param_1[0x1ce] & 0xfffffffe;
      }
      else {
        if (iVar1 != 1) goto LAB_c0706434;
        uVar2 = param_1[0x1ce] | 1;
      }
      param_1[0x1ce] = uVar2;
    }
  }
LAB_c0706434:
  FUN_c0703068(&local_228);
LAB_c070643c:
  FUN_c0712ee4(local_18);
  return;
}



/* c070645c FUN_c070645c */

/* Boundary evidence: original MIPS .pdata c070645c..c07064ef. Semantic name remains unreviewed. */

undefined4 FUN_c070645c(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  FUN_c070470c(param_1,1);
  piVar1 = DAT_c0714150;
  if (DAT_c0714150 != (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    if (*(int *)(param_1 + 0x420) != 0) {
      uVar2 = (**(code **)(*piVar1 + 0x4c))(piVar1);
      *(undefined4 *)(param_1 + 0x420) = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  return uVar2;
}



/* c07064f0 FUN_c07064f0 */

/* Boundary evidence: original MIPS .pdata c07064f0..c0706ae7. Semantic name remains unreviewed. */

int FUN_c07064f0(int *param_1,int *param_2)

{
  bool bVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte local_38 [4];
  int local_34;
  undefined1 local_30 [4];
  uint3 local_2c;
  uint3 local_29;
  uint local_24;
  
  local_24 = DAT_c0714140;
  iVar5 = 0;
  pvVar2 = operator_new(0x1c);
  param_1[0x1b9] = (int)pvVar2;
  if (pvVar2 == (void *)0x0) goto LAB_c0706538;
  memset(pvVar2,0,0x1c);
  if ((param_1[0x123] == 3) || (param_1[0x123] == 4)) {
    if (param_1[0x10d] == 0) {
      iVar5 = (**(code **)(*param_1 + 0x10))(param_1,0,0,0,local_38,1);
      if (-1 < iVar5) {
        *(byte *)param_1[0x1b9] = local_38[0];
        iVar5 = (**(code **)(*param_1 + 0x10))(param_1,0,8,0,local_38,1);
        if (-1 < iVar5) {
          *(byte *)(param_1[0x1b9] + 2) = local_38[0];
          iVar5 = (**(code **)(*param_1 + 0x10))(param_1,0,1,0,local_38,1);
          if (-1 < iVar5) {
            *(byte *)(param_1[0x1b9] + 1) = local_38[0];
            iVar5 = (**(code **)(*param_1 + 0x10))(param_1,0,9,0,&local_2c,3);
            if (-1 < iVar5) {
              *(uint *)(param_1[0x1b9] + 4) = (uint)local_2c;
              local_34 = 4;
              iVar5 = (**(code **)(*param_1 + 0x30))(param_1,0x20,local_30,&local_34,1);
              if (-1 < iVar5) {
                if (local_34 == 0) {
                  FUN_c0712ee4(local_24);
                  return -0x3fffffe9;
                }
                *(short *)(param_1[0x1b9] + 8) = local_30._0_2_;
                *(short *)(param_1[0x1b9] + 10) = local_30._2_2_;
                local_34 = 0;
                iVar5 = (**(code **)(*param_1 + 0x30))(param_1,0x15,0,&local_34,1);
                if (-1 < iVar5) {
                  bVar1 = local_34 == 0;
                  if (bVar1) {
                    local_34 = 0x40;
                  }
                  if (local_34 + 1U < 0x80000000) {
                    uVar3 = (local_34 + 1U) * 2;
                  }
                  else {
                    uVar3 = 0xffffffff;
                  }
                  pvVar2 = operator_new(uVar3);
                  *(void **)(param_1[0x1b9] + 0xc) = pvVar2;
                  iVar4 = param_1[0x1b9];
                  if (*(wchar_t **)(iVar4 + 0xc) == (wchar_t *)0x0) goto LAB_c0706538;
                  if (bVar1) {
                    swprintf(*(wchar_t **)(iVar4 + 0xc),0xc070144c,
                             (wchar_t *)(uint)*(ushort *)(iVar4 + 8),(uint)*(ushort *)(iVar4 + 10));
                  }
                  else {
                    pvVar2 = operator_new(local_34 + 1);
                    if (pvVar2 == (void *)0x0) goto LAB_c0706538;
                    iVar5 = (**(code **)(*param_1 + 0x30))(param_1,0x15,pvVar2,&local_34,1);
                    if (iVar5 < 0) {
                      operator_delete(pvVar2);
                      goto LAB_c0706ab8;
                    }
                    *(undefined1 *)((int)pvVar2 + local_34) = 0;
                    FUN_c07043b0(param_1,(char *)((int)pvVar2 + 2),*(short **)(param_1[0x1b9] + 0xc)
                                );
                    operator_delete(pvVar2);
                  }
                  *(undefined4 *)(param_1[0x1b9] + 0x14) = 0;
                  *(undefined4 *)(param_1[0x1b9] + 0x18) = 0;
                  if (((((*(byte *)param_1[0x1b9] & 0xf) == 1) &&
                       (iVar5 = (**(code **)(*param_1 + 0x10))(param_1,0,0x12,0,local_38,1),
                       -1 < iVar5)) && ((local_38[0] & 1) != 0)) &&
                     (*(undefined4 *)(param_1[0x1b9] + 0x14) = 1,
                     *(int *)(param_1[0x10c] + 0xac) != 0)) {
                    local_38[0] = local_38[0] | 2;
                    iVar5 = (**(code **)(*param_1 + 0x10))(param_1,1,0x12,0,local_38,1);
                    if (-1 < iVar5) {
                      *(undefined4 *)(param_1[0x1b9] + 0x18) = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
      *(undefined1 *)param_1[0x1b9] = *(undefined1 *)param_2[0x1b9];
      *(undefined1 *)(param_1[0x1b9] + 2) = *(undefined1 *)(param_2[0x1b9] + 2);
      *(undefined1 *)(param_1[0x1b9] + 1) = *(undefined1 *)(param_2[0x1b9] + 1);
      *(undefined4 *)(param_1[0x1b9] + 4) = 0;
      *(undefined2 *)(param_1[0x1b9] + 8) = *(undefined2 *)(param_2[0x1b9] + 8);
      *(undefined2 *)(param_1[0x1b9] + 10) = *(undefined2 *)(param_2[0x1b9] + 10);
      *(undefined4 *)(param_1[0x1b9] + 0xc) = 0;
      iVar4 = (uint)*(byte *)(param_1 + 0x1b4) * 0x100;
      iVar5 = (**(code **)(*param_2 + 0x10))(param_2,0,iVar4,0,local_38,1);
      if (-1 < iVar5) {
        *(byte *)((int)param_1 + 0x6d1) = local_38[0] & 0xf;
        if (((local_38[0] & 0xf) == 0xf) && ((*(byte *)param_2[0x1b9] & 0xf) == 1)) {
          iVar5 = (**(code **)(*param_2 + 0x10))(param_2,0,iVar4 + 1,0,local_38,1);
          if (iVar5 < 0) goto LAB_c0706ab8;
          *(byte *)((int)param_1 + 0x6d1) = local_38[0];
        }
        iVar5 = (**(code **)(*param_2 + 0x10))(param_2,0,iVar4 + 9,0,&local_2c,6);
        if (-1 < iVar5) {
          param_1[0x1b5] = (uint)local_2c;
          param_1[0x1b6] = (uint)local_29;
          pvVar2 = operator_new(0x82);
          param_1[0x1b7] = (int)pvVar2;
          if (pvVar2 == (void *)0x0) {
LAB_c0706538:
            FUN_c0712ee4(local_24);
            return -0x3ffffff2;
          }
          iVar5 = FUN_c070e374(param_1);
          swprintf((wchar_t *)param_1[0x1b7],0xc0701418,
                   (wchar_t *)(uint)*(byte *)((int)param_1 + 0x6d1));
        }
      }
    }
  }
LAB_c0706ab8:
  FUN_c0712ee4(local_24);
  return iVar5;
}



/* c0706ae8 FUN_c0706ae8 */

/* Boundary evidence: original MIPS .pdata c0706ae8..c0706bbf. Semantic name remains unreviewed. */

void FUN_c0706ae8(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  HANDLE pvVar5;
  
  if ((param_2 != 0) && ((param_2 & 0xf800) == 0xf800)) {
    pvVar5 = (HANDLE)(param_2 >> 0x10 & 0xff);
    puVar2 = (undefined4 *)FUN_c0705804((LPCRITICAL_SECTION)(param_1 + 8),pvVar5);
    if (puVar2 != (undefined4 *)0x0) {
      puVar4 = puVar2;
      if (puVar2[0x1e] == param_2 >> 0x18) {
        do {
          iVar3 = FUN_c0702310((int)puVar4);
          if (iVar3 == 0) {
            FUN_c070c5a0((int *)(*(int *)(param_1 + 0x430) + 0x44),puVar4);
          }
          puVar1 = puVar4 + 0x1c;
          puVar4 = (undefined4 *)*puVar1;
        } while ((undefined4 *)*puVar1 != (undefined4 *)0x0);
      }
      FUN_c070587c((LPCRITICAL_SECTION)(param_1 + 8),pvVar5);
      FUN_c0702418((int)puVar2);
      FUN_c0702360(puVar2);
    }
  }
  return;
}



/* c0706bc0 FUN_c0706bc0 */

/* Boundary evidence: original MIPS .pdata c0706bc0..c0706cc3. Semantic name remains unreviewed. */

undefined4 FUN_c0706bc0(int param_1,uint param_2,void *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000007;
  if ((param_2 != 0) && ((param_2 & 0xf800) == 0xf800)) {
    puVar1 = (undefined4 *)
             FUN_c0705804((LPCRITICAL_SECTION)(param_1 + 8),(HANDLE)(param_2 >> 0x10 & 0xff));
    if (puVar1 != (undefined4 *)0x0) {
      if ((param_3 != (void *)0x0) && (puVar1[0x1e] == param_2 >> 0x18)) {
        memcpy(param_3,puVar1 + 8,0x18);
        uVar2 = puVar1[0xf];
      }
      FUN_c0702360(puVar1);
    }
  }
  return uVar2;
}



/* c0706cc4 FUN_c0706cc4 */

/* Boundary evidence: original MIPS .pdata c0706cc4..c0706ccf. Semantic name remains unreviewed. */

undefined4 FUN_c0706cc4(void)

{
  return 1;
}



/* c0706cd0 FUN_c0706cd0 */

/* Boundary evidence: original MIPS .pdata c0706cd0..c0706d8f. Semantic name remains unreviewed. */

undefined4 FUN_c0706cd0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (((param_2 != 0) && ((param_2 & 0xf800) == 0xf800)) &&
     (puVar2 = (undefined4 *)
               FUN_c0705804((LPCRITICAL_SECTION)(param_1 + 8),(HANDLE)(param_2 >> 0x10 & 0xff)),
     puVar2 != (undefined4 *)0x0)) {
    puVar4 = puVar2;
    if (puVar2[0x1e] == param_2 >> 0x18) {
      do {
        iVar3 = FUN_c0702310((int)puVar4);
        if (iVar3 == 0) {
          FUN_c070c5a0((int *)(*(int *)(param_1 + 0x430) + 0x44),puVar4);
        }
        puVar1 = puVar4 + 0x1c;
        puVar4 = (undefined4 *)*puVar1;
      } while ((undefined4 *)*puVar1 != (undefined4 *)0x0);
      uVar5 = 1;
    }
    FUN_c0702360(puVar2);
  }
  return uVar5;
}



/* c0706d90 FUN_c0706d90 */

/* Boundary evidence: original MIPS .pdata c0706d90..c0707257. Semantic name remains unreviewed. */

int FUN_c0706d90(int *param_1,uint *param_2,int param_3)

{
  undefined1 uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  DWORD DVar5;
  DWORD DVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined1 auStack_88 [24];
  undefined1 local_70 [64];
  uint local_30;
  
  local_30 = DAT_c0714140;
  iVar10 = -0x3fffffe9;
  uVar11 = 0xffffff;
  iVar4 = -0x3fffffe9;
  if (((param_1[0x123] == 2) && (uVar3 = FUN_c070ca38(param_1[0x10c]), iVar4 = iVar10, uVar3 < 2))
     && (param_2 != (uint *)0x0)) {
    uVar12 = *param_2 & 0xffffff;
    uVar3 = FUN_c070ee10(param_1,(int)param_1 + 0x4be,8,0x3c,4);
    if ((uVar3 == 0) && (uVar3 = FUN_c070ee10(param_1,(int)param_1 + 0x4be,8,0x38,4), uVar3 != 0)) {
      if (param_3 == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1[0x10c] + 0xe8));
        DVar5 = GetTickCount();
        iVar4 = -0x3ffffffe;
        bVar2 = true;
        do {
          DVar6 = GetTickCount();
          if (param_2[2] <= DVar6 - DVar5) break;
          iVar4 = (**(code **)(*param_1 + 0x14))
                            (param_1,6,uVar12,0,1,auStack_88,1,0x40,local_70,8,0,0);
          if (iVar4 < 0) {
LAB_c07071e0:
            bVar2 = false;
          }
          else {
            uVar11 = 0;
            uVar3 = 0x3f;
            do {
              puVar7 = local_70 + uVar11;
              uVar1 = local_70[uVar3];
              local_70[uVar3] = *puVar7;
              uVar11 = uVar11 + 1;
              uVar3 = uVar3 - 1;
              *puVar7 = uVar1;
            } while (uVar11 < uVar3);
            uVar11 = FUN_c070ee10(param_1,(int)local_70,0x40,0x178,0x18);
            uVar3 = FUN_c070ee10(param_1,(int)local_70,0x40,0x1f0,0x10);
            if ((uVar11 == uVar12) && (uVar3 <= param_2[1])) {
              iVar4 = (**(code **)(*param_1 + 0x14))
                                (param_1,6,uVar12 | 0x80000000,0,1,auStack_88,1,0x40,local_70,8,0,0)
              ;
              if (iVar4 < 0) {
                *(undefined4 *)(param_1[0x10c] + 0x84) = 4;
                iVar4 = -0x3ffffffb;
                param_1[0x10a] = 0;
                goto LAB_c07071e0;
              }
              Sleep(1);
              uVar11 = 0;
              uVar3 = 0x3f;
              do {
                puVar7 = local_70 + uVar11;
                uVar1 = local_70[uVar3];
                local_70[uVar3] = *puVar7;
                uVar11 = uVar11 + 1;
                uVar3 = uVar3 - 1;
                *puVar7 = uVar1;
              } while (uVar11 < uVar3);
              uVar11 = FUN_c070ee10(param_1,(int)local_70,0x40,0x178,0x18);
              param_1[0x10a] = uVar11;
              if (uVar11 == uVar12) {
                memcpy(param_2 + 3,local_70,0x40);
                iVar4 = 0;
                break;
              }
              iVar4 = -0x3ffffffe;
            }
            else {
              uVar8 = 0;
              uVar9 = uVar11;
              do {
                if ((uVar9 & 0xf) == 0xf) break;
                uVar8 = uVar8 + 1;
                uVar9 = uVar9 >> 4;
              } while (uVar8 < 6);
              if ((uVar8 < 6) || (param_2[1] < uVar3)) {
                iVar4 = -0x3fffffe9;
                goto LAB_c07071e0;
              }
            }
          }
        } while (bVar2);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[0x10c] + 0xe8));
      }
      else {
        iVar4 = (**(code **)(*param_1 + 0x14))
                          (param_1,6,uVar12,0,1,auStack_88,1,0x40,local_70,8,0,0);
        if (iVar4 < 0) goto LAB_c0707220;
        uVar11 = 0;
        uVar3 = 0x3f;
        do {
          puVar7 = local_70 + uVar11;
          uVar1 = local_70[uVar3];
          local_70[uVar3] = *puVar7;
          uVar11 = uVar11 + 1;
          uVar3 = uVar3 - 1;
          *puVar7 = uVar1;
        } while (uVar11 < uVar3);
        uVar11 = FUN_c070ee10(param_1,(int)local_70,0x40,0x178,0x18);
        uVar3 = FUN_c070ee10(param_1,(int)local_70,0x40,0x1f0,0x10);
        param_2[1] = uVar3;
        memcpy(param_2 + 3,local_70,0x40);
      }
      if (-1 < iVar4) {
        *param_2 = uVar11;
      }
    }
  }
LAB_c0707220:
  FUN_c0712ee4(local_30);
  return iVar4;
}



/* c0707258 FUN_c0707258 */

/* Boundary evidence: original MIPS .pdata c0707258..c07073b7. Semantic name remains unreviewed. */

undefined4 FUN_c0707258(int *param_1)

{
  code *pcVar1;
  ULONG_PTR UVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar3;
  uint uVar4;
  uint local_20;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 2);
  EnterCriticalSection(lpCriticalSection);
  if (param_1[0x10f] != 0) {
    pcVar1 = *(code **)(*param_1 + 0x28);
    param_1[0x10f] = 0;
    (*pcVar1)(param_1,0,0);
    FUN_c070645c((int)param_1);
    uVar3 = 0;
    if (param_1[0x107] != 0) {
      do {
        uVar4 = param_1[0x109];
        if (param_1[uVar4 + 7] != 0) {
          if (uVar4 < (uint)param_1[0x107]) {
            UVar2 = (&lpCriticalSection->SpinCount)[uVar4];
          }
          else {
            UVar2 = 0;
          }
          local_20 = *(int *)(UVar2 + 0x78) << 0x18 |
                     ((param_1[0x10d] & 7U | (uVar3 & 0xff) << 8 | 0xf8) << 4 |
                     *(uint *)(param_1[0x10c] + 0x80) & 0xf) << 4 |
                     *(uint *)(*(int *)(param_1[0x10c] + 0x7c) + 0x5c) & 0xf | local_20 & 0xf800;
          (**(code **)(*param_1 + 0x1c))(param_1,local_20);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)param_1[0x107]);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* c07073b8 FUN_c07073b8 */

/* Boundary evidence: original MIPS .pdata c07073b8..c0707793. Semantic name remains unreviewed. */

int FUN_c07073b8(int *param_1,int *param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_48 [5];
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  byte local_40;
  uint local_30;
  
  local_30 = DAT_c0714140;
  if (param_1[0x10d] != 0) {
    FUN_c0712ee4(DAT_c0714140);
    return -0x3fffffe9;
  }
  *param_2 = 1;
  iVar6 = 0;
  iVar3 = (**(code **)(*param_1 + 0x14))(param_1,5,0,2,5,auStack_48,0,0,0,8,0,0);
  if (iVar3 < 0) {
    if (iVar3 == -0x3fffffec) {
LAB_c0707514:
      iVar6 = 0;
      iVar3 = 0;
    }
LAB_c0707528:
    if (iVar3 < 0) goto LAB_c070775c;
  }
  else {
    *(undefined1 *)(param_1 + 0x127) = local_41;
    *(undefined1 *)((int)param_1 + 0x49b) = local_42;
    bVar2 = local_40 >> 3;
    *(undefined1 *)((int)param_1 + 0x49a) = local_43;
    *param_2 = (local_40 >> 4 & 7) + 1;
    if ((local_40 >> 4 & 7) == 0) {
      if ((bVar2 & 1) == 0) {
        iVar3 = -0x3fffffe9;
      }
      goto LAB_c0707528;
    }
    iVar6 = 4;
    if ((bVar2 & 1) == 0) {
      iVar6 = 3;
    }
    param_1[0x123] = iVar6;
    iVar3 = FUN_c0706264(param_1,3,1);
    if (iVar3 < 0) {
      if ((bVar2 & 1) != 0) {
        param_1[0x123] = 0;
        goto LAB_c0707514;
      }
      goto LAB_c0707528;
    }
  }
  if ((iVar6 != 0) && (iVar6 != 4)) goto LAB_c070775c;
  iVar3 = (**(code **)(*param_1 + 0x14))(param_1,0,0,2,0,0,0,0,0,8,0,0);
  iVar4 = FUN_c0703340(param_1);
  if (-1 < iVar3) {
    if (iVar6 != 4) {
      iVar7 = 100;
      do {
        iVar3 = (**(code **)(*param_1 + 0x14))
                          (param_1,1,*(undefined4 *)(param_1[0x10c] + 0x6c),2,4,auStack_48,0,0,0,8,0
                           ,0);
        if (-1 < iVar3) {
          *(byte *)((int)param_1 + 0x49d) = local_40;
          *(undefined1 *)(param_1 + 0x127) = local_41;
          *(undefined1 *)((int)param_1 + 0x49b) = local_42;
          *(undefined1 *)((int)param_1 + 0x49a) = local_43;
        }
      } while (((*(byte *)((int)param_1 + 0x49d) & 0x80) == 0) &&
              (bVar1 = iVar7 != 0, iVar7 = iVar7 + -1, bVar1));
      if (iVar3 < 0) {
        if (iVar3 == -0x3fffffec) {
          iVar3 = 0;
        }
      }
      else {
        *(byte *)((int)param_1 + 0x49d) = local_40;
        *(undefined1 *)(param_1 + 0x127) = local_41;
        *(undefined1 *)((int)param_1 + 0x49b) = local_42;
        *(undefined1 *)((int)param_1 + 0x49a) = local_43;
        iVar6 = 1;
        param_1[0x123] = 1;
        iVar3 = FUN_c0706264(param_1,1,1);
      }
    }
    if (-1 < iVar3) {
      if ((iVar6 == 0) || (iVar6 == 4)) {
        if (iVar4 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(uint *)(param_1[0x10c] + 0x6c) | 0x40000000;
        }
        iVar3 = (**(code **)(*param_1 + 0x38))(param_1,0x29,uVar5,2,4,auStack_48,0,0,0);
        if (iVar3 < 0) goto LAB_c070773c;
        *(byte *)((int)param_1 + 0x49d) = local_40;
        *(undefined1 *)(param_1 + 0x127) = local_41;
        *(undefined1 *)((int)param_1 + 0x49b) = local_42;
        *(undefined1 *)((int)param_1 + 0x49a) = local_43;
        if (iVar6 == 0) {
          iVar6 = 2;
          param_1[0x123] = 2;
        }
        iVar3 = FUN_c0706264(param_1,2,(uint)(iVar6 == 2));
      }
      if (-1 < iVar3) goto LAB_c070775c;
    }
  }
LAB_c070773c:
  if (iVar6 == 4) {
    param_1[0x123] = 3;
    iVar3 = 0;
  }
  else {
    iVar3 = -0x3fffffe9;
  }
LAB_c070775c:
  FUN_c0712ee4(local_30);
  return iVar3;
}



/* c0707794 FUN_c0707794 */

/* Boundary evidence: original MIPS .pdata c0707794..c0707c43. Semantic name remains unreviewed. */

int FUN_c0707794(int *param_1,uint *param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *_Dst;
  byte local_b0 [8];
  undefined1 auStack_a8 [24];
  uint local_90 [3];
  undefined1 auStack_84 [68];
  undefined1 auStack_40 [24];
  uint local_28;
  
  local_28 = DAT_c0714140;
  iVar6 = 0;
  if (param_2 == (uint *)0x0) {
    param_2 = (uint *)(param_1 + 0x1ce);
  }
  if ((param_1[0x1b9] != 0) && ((*(byte *)(param_1[0x1b9] + 2) & 2) == 0)) {
    *(undefined1 *)((int)param_1 + 0x709) = 0xc;
  }
  iVar4 = param_1[0x10c];
  if ((*(uint *)(iVar4 + 0x68) & 0x200) != 0) {
    bVar1 = *(byte *)((int)param_1 + 0x709);
    *(byte *)((int)param_1 + 0x709) = bVar1 | 1;
    if ((*(uint *)(iVar4 + 0x68) & 0x400) != 0) {
      *(byte *)((int)param_1 + 0x709) = bVar1 | 3;
    }
    if ((*(uint *)(iVar4 + 0x68) & 0x800) != 0) {
      *(byte *)((int)param_1 + 0x709) = *(byte *)((int)param_1 + 0x709) | 4;
    }
    if ((*(uint *)(iVar4 + 0x68) & 0x1000) != 0) {
      *(byte *)((int)param_1 + 0x709) = *(byte *)((int)param_1 + 0x709) | 8;
    }
  }
  if ((*(uint *)(iVar4 + 0x68) & 0x400) != 0) {
    *(undefined1 *)((int)param_1 + 0x709) = 2;
  }
  if ((*(uint *)(iVar4 + 0x68) & 0x800) != 0) {
    *(undefined1 *)((int)param_1 + 0x709) = 4;
  }
  if ((*(uint *)(iVar4 + 0x68) & 0x1000) != 0) {
    *(undefined1 *)((int)param_1 + 0x709) = 8;
  }
  iVar3 = param_1[0x123];
  if (iVar3 == 3) {
    piVar2 = (int *)FUN_c07031cc(iVar4,0);
    iVar6 = -0x3fffffef;
    if (piVar2 == (int *)0x0) goto LAB_c0707c14;
    iVar6 = (**(code **)(*piVar2 + 0x10))(piVar2,0,7,0,local_b0,1);
    if (-1 < iVar6) {
      if ((*param_2 & 1) == 0) {
        local_b0[0] = local_b0[0] & 0xfd;
        iVar6 = (**(code **)(*piVar2 + 0x10))(piVar2,1,7,0,local_b0,1);
      }
      else {
        local_b0[0] = local_b0[0] | 2;
        iVar6 = (**(code **)(*piVar2 + 0x10))();
        if ((((-1 < iVar6) && ((*(uint *)(param_1[0x10c] + 0x68) & 0x100) != 0)) &&
            (iVar6 = (**(code **)(*piVar2 + 0x10))(piVar2,0,8,0,local_b0,1), -1 < iVar6)) &&
           ((local_b0[0] & 0x10) != 0)) {
          local_b0[0] = local_b0[0] | 0x20;
          iVar6 = (**(code **)(*piVar2 + 0x10))(piVar2,1,8,0,local_b0,1);
        }
      }
    }
    FUN_c070310c(piVar2);
LAB_c0707b4c:
    if (iVar6 < 0) goto LAB_c0707c14;
  }
  else if ((iVar3 == 2) || (iVar3 == 4)) {
    if (param_1[0x1ca] == 0) {
      if ((*param_2 & 1) == 0) {
        iVar6 = (**(code **)(*param_1 + 0x38))(param_1,6,0,2,1,auStack_a8,0,0,0);
      }
      else {
        iVar6 = (**(code **)(*param_1 + 0x38))(param_1,6,2,2,1,auStack_a8,0,0,0);
      }
      goto LAB_c0707b4c;
    }
  }
  else if (iVar3 == 1) {
    uVar5 = 0;
    if ((*(uint *)(iVar4 + 0x68) & 0x80000000) == 0) {
      if ((*(uint *)(iVar4 + 0x68) & 8) != 0) {
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 2;
    }
    iVar4 = (**(code **)(*param_1 + 0x14))
                      (param_1,6,(uVar5 | 0x3b700) << 8,2,2,auStack_40,0,0,0,4,0,0);
    if (iVar4 < 0) {
      NKDbgPrintfW(L"SDBusDriver(%d): Failed to switch bus width!\r\n",0x44d);
    }
  }
  _Dst = (uint *)(param_1 + 0x1ce);
  uVar5 = *param_2 >> 1 & 1;
  if (((*_Dst >> 1 & 1) != uVar5) && (uVar5 != 0)) {
    if ((param_1[0x123] == 2) && ((*(uint *)(param_1[0x10c] + 0x68) & 0x10) != 0)) {
      local_90[0] = 1;
      local_90[1] = 0xffffffff;
      local_90[2] = 2000;
      memset(auStack_84,0,0x40);
      iVar6 = FUN_c0706d90(param_1,local_90,0);
      if (iVar6 < 0) goto LAB_c0707c14;
      *_Dst = *_Dst | 2;
    }
    else {
      iVar6 = -0x3fffffe9;
    }
  }
  if (-1 < iVar6) {
    memcpy(_Dst,param_2,0x20);
  }
LAB_c0707c14:
  FUN_c0712ee4(local_28);
  return iVar6;
}



/* c0707c44 FUN_c0707c44 */

/* Boundary evidence: original MIPS .pdata c0707c44..c0707f97. Semantic name remains unreviewed. */

int FUN_c0707c44(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_280 [8];
  int local_278;
  undefined1 auStack_270 [24];
  int local_258;
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_c0714140;
  iVar1 = FUN_c070398c(param_1,awStack_220,0x100,1);
  if ((-1 < iVar1) &&
     (((param_1[0x123] != 2 && (param_1[0x123] != 1)) ||
      (iVar1 = (**(code **)(*param_1 + 0x34))(param_1,2,auStack_270,0x50), -1 < iVar1)))) {
    iVar3 = param_1[0x10c];
    iVar5 = param_1[0x123];
    uVar4 = *(uint *)(iVar3 + 0x68) & 8;
    if (iVar5 == 1) {
      param_1[0x1cf] = 20000000;
      param_1[0x1ce] = (uint)(uVar4 != 0) | param_1[0x1ce] & 0xfffffffcU;
    }
    else {
      uVar4 = ((uint)(uVar4 != 0) ^ param_1[0x1ce]) & 1 ^ param_1[0x1ce];
      param_1[0x1ce] = uVar4;
      if ((iVar5 == 3) && ((*(uint *)(iVar3 + 0x68) & 0x80) != 0)) {
        param_1[0x1ce] = uVar4 | 1;
      }
      if (((iVar5 == 2) || (iVar5 == 4)) && ((*(uint *)(iVar3 + 0x68) & 0x40) != 0)) {
        param_1[0x1ce] = param_1[0x1ce] | 1;
      }
      param_1[0x1cf] = 25000000;
    }
    if (iVar5 == 3) {
      puVar2 = (undefined4 *)FUN_c07031cc(iVar3,0);
      if (puVar2 == (undefined4 *)0x0) {
        iVar1 = -0x3ffffffd;
      }
      else {
        if (((*(byte *)(puVar2[0x1b9] + 2) & 0x40) != 0) &&
           (param_1[0x1cf] = 400000, (*(byte *)(puVar2[0x1b9] + 2) & 0x80) == 0)) {
          param_1[0x1ce] = param_1[0x1ce] & 0xfffffffe;
        }
        FUN_c070310c(puVar2);
      }
    }
    else if ((iVar5 == 2) || (iVar5 == 4)) {
      uVar4 = FUN_c070ee10(param_1,(int)param_1 + 0x4be,8,0x30,4);
      if ((uVar4 & 4) == 0) {
        param_1[0x1ce] = param_1[0x1ce] & 0xfffffffe;
      }
    }
    else {
      if (iVar5 != 1) goto LAB_c0707e70;
      if ((uint)(local_258 * 1000) < 20000000) {
        param_1[0x1cf] = local_258 * 1000;
      }
      if (param_1[0x1d8] != 0) {
        param_1[0x1cf] = 0x13ab668;
      }
    }
    if (-1 < iVar1) {
      FUN_c0706344(param_1);
      iVar3 = param_1[0x10c];
      uVar4 = *(uint *)(iVar3 + 0x68);
      if (((((uVar4 & 8) == 0) && ((param_1[0x1ce] & 1U) != 0)) && ((uVar4 & 0x40) == 0)) &&
         ((uVar4 & 0x80) == 0)) {
LAB_c0707e70:
        FUN_c0712ee4(local_20);
        return -0x3ffffff9;
      }
      if (param_1[0x123] == 2) {
        iVar5 = *(int *)(iVar3 + 0x7c);
        iVar1 = iVar5 + 8;
        if (iVar5 == 0) {
          iVar1 = 0;
        }
        iVar1 = (**(code **)(iVar5 + 0x44))(iVar1,*(undefined4 *)(iVar3 + 0x80),5,auStack_280,0xc);
        param_1[0x1ce] =
             ((uint)(local_278 != 0) << 0x1e ^ param_1[0x1ce]) & 0x40000000 ^ param_1[0x1ce];
      }
    }
  }
  FUN_c0712ee4(local_20);
  return iVar1;
}



/* c0707f98 FUN_c0707f98 */

/* Boundary evidence: original MIPS .pdata c0707f98..c0708023. Semantic name remains unreviewed. */

void FUN_c0707f98(int *param_1)

{
  void *pvVar1;
  
  *param_1 = (int)&PTR_FUN_c0701340;
  FUN_c0707258(param_1);
  if ((HANDLE)param_1[0x10b] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x10b]);
  }
  if (param_1[0x1b9] != 0) {
    pvVar1 = *(void **)(param_1[0x1b9] + 0xc);
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
    operator_delete((void *)param_1[0x1b9]);
  }
  FUN_c070577c((LPCRITICAL_SECTION)(param_1 + 2));
  *param_1 = (int)&PTR_FUN_c0701044;
  return;
}



/* c0708024 FUN_c0708024 */

/* Boundary evidence: original MIPS .pdata c0708024..c070806f. Semantic name remains unreviewed. */

int * FUN_c0708024(int *param_1,uint param_2)

{
  FUN_c0707f98(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0708070 FUN_c0708070 */

/* Boundary evidence: original MIPS .pdata c0708070..c07080d7. Semantic name remains unreviewed. */

undefined4 FUN_c0708070(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x800700b7;
  if (param_1[1] != 0) {
    if (*param_1 != 0) {
      CeFreeAsynchronousBuffer(*param_1,param_1[1],param_1[3],param_1[4]);
    }
    uVar1 = CeCloseCallerBuffer(param_1[1],param_1[2],param_1[3],param_1[4]);
    param_1[1] = 0;
    *param_1 = 0;
    param_1[3] = 0;
  }
  return uVar1;
}



/* c07080d8 FUN_c07080d8 */

/* Boundary evidence: original MIPS .pdata c07080d8..c0708113. Semantic name remains unreviewed. */

void FUN_c07080d8(int *param_1)

{
  (**(code **)(*param_1 + 0x58))();
  return;
}



/* c0708114 FUN_c0708114 */

undefined4 FUN_c0708114(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x84);
  if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 6)) {
    uVar1 = 0;
  }
  else if (iVar2 == 3) {
    uVar1 = 0xc0000011;
  }
  else {
    uVar1 = 0xc0000003;
  }
  return uVar1;
}



/* c0708164 FUN_c0708164 */

/* Boundary evidence: original MIPS .pdata c0708164..c0708207. Semantic name remains unreviewed. */

int FUN_c0708164(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  if (param_2 < 8) {
    iVar1 = *(int *)((param_2 + 0x32) * 4 + param_1);
  }
  else {
    iVar1 = 0;
  }
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x438) != param_3)) {
    iVar1 = 0;
  }
  else {
    InterlockedIncrement((LONG *)(iVar1 + 4));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  return iVar1;
}



/* c0708208 FUN_c0708208 */

/* Boundary evidence: original MIPS .pdata c0708208..c07082a7. Semantic name remains unreviewed. */

undefined4 * FUN_c0708208(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  
  *param_1 = &PTR_FUN_c07014fc;
  param_1[1] = 0;
  if (0xf < param_2) {
    param_2 = 0x10;
  }
  param_1[0x1a] = param_2;
  param_1[0x17] = 0xffffffff;
  memset(param_1 + 2,0,0x54);
  param_1[2] = 0x10000;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  puVar1 = param_1 + 0x1b;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x2b);
  param_1[0x19] = 0;
  param_1[0x18] = 0;
  return param_1;
}



/* c07082a8 FUN_c07082a8 */

/* Boundary evidence: original MIPS .pdata c07082a8..c0708337. Semantic name remains unreviewed. */

void FUN_c07082a8(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  *param_1 = &PTR_FUN_c07014fc;
  uVar3 = 0;
  if (param_1[0x1a] != 0) {
    piVar2 = param_1 + 0x1b;
    do {
      piVar1 = (int *)*piVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1,1);
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar3 < (uint)param_1[0x1a]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  *param_1 = &PTR_FUN_c0701044;
  return;
}



/* c0708338 FUN_c0708338 */

/* Boundary evidence: original MIPS .pdata c0708338..c07083e3. Semantic name remains unreviewed. */

undefined4 FUN_c0708338(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((*(int *)(param_1 + 0x60) == 0) || (*(int *)(param_1 + 100) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    uVar3 = 0;
    *(undefined4 *)(param_1 + 100) = 1;
    if (*(int *)(param_1 + 0x68) != 0) {
      puVar2 = (undefined4 *)(param_1 + 0x6c);
      do {
        if ((int *)*puVar2 != (int *)0x0) {
          (**(code **)(*(int *)*puVar2 + 0x10))();
        }
        uVar3 = uVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (uVar3 < *(uint *)(param_1 + 0x68));
    }
  }
  return uVar1;
}



/* c07083e4 FUN_c07083e4 */

/* Boundary evidence: original MIPS .pdata c07083e4..c070846b. Semantic name remains unreviewed. */

undefined4 FUN_c07083e4(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 100) != 0) {
    uVar2 = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    if (*(int *)(param_1 + 0x68) != 0) {
      piVar1 = (int *)(param_1 + 0x6c);
      do {
        if ((int *)*piVar1 != (int *)0x0) {
          (**(code **)(*(int *)*piVar1 + 0x14))();
        }
        uVar2 = uVar2 + 1;
        piVar1 = piVar1 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0x68));
    }
  }
  return 1;
}



/* c070846c FUN_c070846c */

/* Boundary evidence: original MIPS .pdata c070846c..c07085df. Semantic name remains unreviewed. */

int FUN_c070846c(int param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_38;
  uint local_34;
  
  iVar1 = -0x3ffffff9;
  if (((param_3 != (uint *)0x0) && (param_2 < *(uint *)(param_1 + 0x68))) &&
     (*(int *)((param_2 + 0x1b) * 4 + param_1) != 0)) {
    if ((*param_3 & 2) == 0) {
      memcpy(&local_38,param_3,0x20);
      local_48 = (uint)((local_38 & 1) != 0);
      local_40 = (uint)((local_38 & 0x40000000) != 0);
      local_44 = local_34;
      iVar1 = (**(code **)(param_1 + 0x44))(param_1 + 8,param_2,1,&local_48,0xc);
      if (-1 < iVar1) {
        uVar2 = (*param_3 ^ (uint)(local_48 == 1)) & 1 ^ *param_3;
        *param_3 = uVar2;
        param_3[1] = local_44;
        *param_3 = ((uint)(local_40 != 0) << 0x1e ^ uVar2) & 0x40000000 ^ uVar2;
      }
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x44))(param_1 + 8,param_2,0xc,param_3,0x20);
    }
  }
  return iVar1;
}



/* c07085e0 FUN_c07085e0 */

/* Boundary evidence: original MIPS .pdata c07085e0..c0708653. Semantic name remains unreviewed. */

uint FUN_c07085e0(undefined4 param_1,STRSAFE_LPWSTR param_2,uint param_3)

{
  HRESULT HVar1;
  uint uVar2;
  
  uVar2 = param_3;
  if (5 < param_3) {
    uVar2 = 6;
  }
  if ((param_2 != (STRSAFE_LPWSTR)0x0) && (uVar2 != 0)) {
    HVar1 = StringCchCopyW(param_2,param_3,L"SDBUS");
    if (-1 < HVar1) {
      return uVar2;
    }
    *param_2 = L'\0';
  }
  return 0;
}



/* c0708654 FUN_c0708654 */

/* Boundary evidence: original MIPS .pdata c0708654..c0708aeb. Semantic name remains unreviewed. */

int FUN_c0708654(int param_1,uint *param_2,uint param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int local_11c;
  uint local_f0;
  uint local_ec;
  uint local_d0;
  uint local_cc;
  wchar_t awStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_c0714140;
  iVar6 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x2c);
  if (param_1 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  EnterCriticalSection(lpCriticalSection);
  iVar3 = *(int *)(param_1 + 0x80);
  if (iVar3 != 0) {
    piVar4 = (int *)(param_1 + 0x40);
    do {
      if (*piVar4 != 0) {
        iVar6 = *(int *)(*piVar4 + 0x68) + iVar6;
      }
      piVar4 = piVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if ((param_2 != (uint *)0x0) && (param_3 != 0)) {
    if (param_3 < (uint)(iVar6 * 0x9c)) {
      iVar6 = 0;
    }
    else {
      uVar9 = 0;
      iVar3 = iVar6;
      local_11c = iVar6;
      while ((uVar9 < *(uint *)(param_1 + 0x80) && (iVar3 != 0))) {
        if (*(int *)((uVar9 + 0x10) * 4 + param_1) != 0) {
          uVar7 = 0;
          while( true ) {
            bVar1 = true;
            iVar5 = *(int *)((uVar9 + 0x10) * 4 + param_1);
            if ((*(uint *)(iVar5 + 0x68) <= uVar7) || (iVar3 == 0)) break;
            if (uVar7 < *(uint *)(iVar5 + 0x68)) {
              iVar3 = *(int *)((uVar7 + 0x1b) * 4 + iVar5);
            }
            else {
              iVar3 = 0;
            }
            StringCchCopyW(awStack_b0,0x40,L"Empty Slot");
            if (iVar3 != 0) {
              uVar8 = 0;
              while (bVar1) {
                if (7 < uVar8) {
                  puVar2 = (undefined4 *)FUN_c07031cc(iVar3,0);
                  if (puVar2 != (undefined4 *)0x0) {
                    memcpy(&local_f0,puVar2 + 0x1ce,0x20);
                    param_2[0x24] = (uint)((local_f0 & 1) != 0);
                    param_2[0x25] = local_ec;
                    param_2[0x26] = (uint)((local_f0 & 0x40000000) != 0);
                    param_2[2] = 1;
                    param_2[3] = puVar2[0x123];
                    FUN_c070310c(puVar2);
                  }
                  break;
                }
                puVar2 = (undefined4 *)FUN_c07031cc(iVar3,uVar8);
                if (puVar2 != (undefined4 *)0x0) {
                  if (puVar2[0x108] == 0) {
                    iVar5 = 0;
                  }
                  else {
                    iVar5 = *(int *)(puVar2[0x108] + 0x28);
                  }
                  if (iVar5 != 0) {
                    StringCchCopyW(awStack_b0,0x40,(STRSAFE_LPCWSTR)(puVar2 + 0x112));
                    memcpy(&local_d0,puVar2 + 0x1ce,0x20);
                    param_2[0x24] = (uint)((local_d0 & 1) != 0);
                    param_2[0x25] = local_cc;
                    param_2[0x26] = (uint)((local_d0 & 0x40000000) != 0);
                    param_2[2] = 1;
                    param_2[3] = puVar2[0x123];
                    bVar1 = false;
                  }
                  FUN_c070310c(puVar2);
                }
                uVar8 = uVar8 + 1;
              }
            }
            StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 4),0x40,awStack_b0);
            *param_2 = uVar9;
            param_2[1] = uVar7;
            iVar3 = local_11c + -1;
            param_2 = param_2 + 0x27;
            uVar7 = uVar7 + 1;
            local_11c = iVar3;
          }
        }
        uVar9 = uVar9 + 1;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  FUN_c0712ee4(local_30);
  return iVar6;
}



/* c0708aec FUN_c0708aec */

/* Boundary evidence: original MIPS .pdata c0708aec..c0708b0b. Semantic name remains unreviewed. */

void FUN_c0708aec(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c0708b0c FUN_c0708b0c */

/* Boundary evidence: original MIPS .pdata c0708b0c..c0708b2b. Semantic name remains unreviewed. */

void FUN_c0708b0c(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c0708b2c FUN_c0708b2c */

/* Boundary evidence: original MIPS .pdata c0708b2c..c0708b4b. Semantic name remains unreviewed. */

void FUN_c0708b2c(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c0708b4c FUN_c0708b4c */

/* Boundary evidence: original MIPS .pdata c0708b4c..c0708c5f. Semantic name remains unreviewed. */

undefined4 FUN_c0708b4c(int param_1,int *param_2,undefined4 *param_3,uint param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if ((param_2 != (int *)0x0) && (param_3 != (undefined4 *)0x0)) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x2c);
    if (param_1 == 0) {
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    EnterCriticalSection(lpCriticalSection);
    uVar1 = 0;
    if (*(uint *)(param_1 + 0x80) != 0) {
      piVar3 = (int *)(param_1 + 0x40);
      do {
        if (*piVar3 != 0) {
          uVar2 = *(uint *)(*piVar3 + 0x68);
          if (param_4 < uVar2) {
            iVar4 = *(int *)((uVar1 + 0x10) * 4 + param_1);
            *param_2 = iVar4;
            if (param_4 < *(uint *)(iVar4 + 0x68)) {
              uVar5 = *(undefined4 *)((param_4 + 0x1b) * 4 + iVar4);
            }
            else {
              uVar5 = 0;
            }
            *param_3 = uVar5;
            InterlockedIncrement((LONG *)(*param_2 + 4));
            uVar5 = 1;
            break;
          }
          param_4 = param_4 - uVar2;
        }
        uVar1 = uVar1 + 1;
        piVar3 = piVar3 + 1;
      } while (uVar1 < *(uint *)(param_1 + 0x80));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  }
  return uVar5;
}



/* c0708c60 FUN_c0708c60 */

/* Boundary evidence: original MIPS .pdata c0708c60..c0708d8f. Semantic name remains unreviewed. */

int FUN_c0708c60(int param_1,uint param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_20;
  undefined4 *local_1c;
  
  local_1c = (undefined4 *)0x0;
  local_20 = 0;
  iVar4 = -0x3ffffff8;
  iVar1 = FUN_c0708b4c(param_1,(int *)&local_1c,&local_20,param_2);
  iVar3 = local_20;
  if ((iVar1 != 0) && (local_20 != 0)) {
    memset(param_3,0,0x20);
    iVar4 = FUN_c0708114(iVar3);
    if (-1 < iVar4) {
      iVar4 = -0x3ffffffd;
      puVar2 = (undefined4 *)FUN_c07031cc(iVar3,0);
      if (puVar2 != (undefined4 *)0x0) {
        if (puVar2[0x1b9] != 0) {
          *(undefined4 *)(param_3 + 4) = *(undefined4 *)(puVar2[0x1b9] + 0x14);
          *(undefined4 *)(param_3 + 8) = *(undefined4 *)(puVar2[0x1b9] + 0x18);
          *(uint *)(param_3 + 0xc) = (uint)*(ushort *)(iVar3 + 0xb0);
          *(undefined4 *)(param_3 + 0x10) = puVar2[0x1b2];
          *(undefined4 *)(param_3 + 0x14) = 0xff8000;
          param_3[0x18] = 1;
          *(undefined4 *)(param_3 + 0x1c) = 0x78;
          iVar3 = FUN_c070ca38(iVar3);
          iVar4 = 0;
          *param_3 = (char)iVar3;
        }
        FUN_c070310c(puVar2);
      }
    }
  }
  if (local_1c != (undefined4 *)0x0) {
    FUN_c070310c(local_1c);
  }
  return iVar4;
}



/* c0708d90 FUN_c0708d90 */

/* Boundary evidence: original MIPS .pdata c0708d90..c0708e93. Semantic name remains unreviewed. */

int FUN_c0708d90(int param_1,uint param_2,uint param_3,STRSAFE_LPWSTR param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_20;
  undefined4 *local_1c;
  
  local_1c = (undefined4 *)0x0;
  local_20 = 0;
  iVar4 = -0x3ffffff8;
  iVar2 = FUN_c0708b4c(param_1,(int *)&local_1c,&local_20,param_2);
  iVar1 = local_20;
  if ((iVar2 != 0) && (local_20 != 0)) {
    memset(param_4,0,0x78);
    iVar4 = FUN_c0708114(iVar1);
    if (-1 < iVar4) {
      iVar4 = -0x3ffffffd;
      puVar3 = (undefined4 *)FUN_c07031cc(iVar1,param_3);
      if (puVar3 != (undefined4 *)0x0) {
        StringCchCopyW(param_4,0x20,(STRSAFE_LPCWSTR)(puVar3 + 0x112));
        iVar4 = FUN_c070e530((int)puVar3,(int *)(param_4 + 0x20));
        memcpy(param_4 + 0x32,(void *)((int)puVar3 + 0x70a),0x12);
        FUN_c070310c(puVar3);
      }
    }
  }
  if (local_1c != (undefined4 *)0x0) {
    FUN_c070310c(local_1c);
  }
  return iVar4;
}



/* c0708e94 FUN_c0708e94 */

/* Boundary evidence: original MIPS .pdata c0708e94..c0708f0f. Semantic name remains unreviewed. */

undefined4 FUN_c0708e94(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  undefined4 *local_14;
  
  local_14 = (undefined4 *)0x0;
  local_18 = 0;
  uVar2 = 0xc0000008;
  iVar1 = FUN_c0708b4c(param_1,(int *)&local_14,&local_18,param_2);
  if ((iVar1 != 0) && (local_18 != 0)) {
    *(undefined4 *)(local_18 + 0xac) = param_3;
    uVar2 = 0;
  }
  if (local_14 != (undefined4 *)0x0) {
    FUN_c070310c(local_14);
  }
  return uVar2;
}



/* c0708f10 FUN_c0708f10 */

/* Boundary evidence: original MIPS .pdata c0708f10..c0708f8b. Semantic name remains unreviewed. */

undefined4 FUN_c0708f10(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  undefined4 *local_14;
  
  local_14 = (undefined4 *)0x0;
  local_18 = 0;
  uVar2 = 0;
  iVar1 = FUN_c0708b4c(param_1,(int *)&local_14,&local_18,param_2);
  if ((iVar1 != 0) && (local_18 != 0)) {
    uVar2 = FUN_c070d454(local_18,param_3);
  }
  if (local_14 != (undefined4 *)0x0) {
    FUN_c070310c(local_14);
  }
  return uVar2;
}



/* c0708f8c FUN_c0708f8c */

/* Boundary evidence: original MIPS .pdata c0708f8c..c07092c3. Semantic name remains unreviewed. */

undefined4
FUN_c0708f8c(int *param_1,uint param_2,undefined4 *param_3,int param_4,undefined4 *param_5,
            int param_6,int *param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *_Src;
  undefined4 uVar3;
  size_t _Size;
  DWORD dwErrCode;
  int iVar4;
  undefined1 auStack_c0 [32];
  undefined1 auStack_a0 [120];
  uint local_28;
  
  local_28 = DAT_c0714140;
  iVar4 = -1;
  dwErrCode = 0;
  if (param_2 < 0x19) {
    if (param_2 == 0x18) {
      if ((param_4 == 4) && (param_3 != (undefined4 *)0x0)) {
        uVar2 = *param_3;
        uVar3 = 6;
LAB_c0709034:
        iVar4 = (**(code **)(*param_1 + 0x70))(param_1,uVar2,uVar3);
        if (iVar4 != 0) goto LAB_c0709150;
      }
    }
    else if (param_2 == 8) {
      iVar4 = 4;
      if (param_6 == 4) {
        uVar2 = (**(code **)(*param_1 + 0x60))(param_1,0,0);
        *param_5 = uVar2;
LAB_c0709288:
        if (param_7 != (int *)0x0) {
          if (dwErrCode != 0) goto LAB_c07092a4;
          *param_7 = iVar4;
        }
        goto LAB_c070929c;
      }
    }
    else if (param_2 == 0xc) {
      iVar1 = (**(code **)(*param_1 + 0x60))(param_1,param_5,param_6);
      iVar4 = param_6;
      if (iVar1 != 0) goto LAB_c0709280;
    }
    else if (param_2 == 0x10) {
      iVar4 = 4;
      if ((param_6 == 4) || (param_5 == (undefined4 *)0x0)) {
        *param_5 = 0x60000;
        goto LAB_c0709288;
      }
    }
    else if (((param_2 == 0x14) && (param_4 == 4)) && (param_3 != (undefined4 *)0x0)) {
      uVar2 = *param_3;
      uVar3 = 7;
      goto LAB_c0709034;
    }
  }
  else {
    if (param_2 == 0x1c) {
      if ((param_4 == 4) && (param_3 != (undefined4 *)0x0)) {
        uVar2 = *param_3;
        uVar3 = 5;
        goto LAB_c0709034;
      }
      dwErrCode = 0x57;
LAB_c0709280:
      if (iVar4 != -1) goto LAB_c0709288;
LAB_c070929c:
      if (dwErrCode == 0) goto LAB_c0709150;
      goto LAB_c07092a4;
    }
    iVar4 = 0x20;
    if (param_2 == 0x20) {
      if (param_4 == 4) {
        if (((param_3 != (undefined4 *)0x0) && (param_6 == 0x20)) && (param_5 != (undefined4 *)0x0))
        {
          iVar1 = (**(code **)(*param_1 + 100))(param_1,*param_3,auStack_c0);
          if (iVar1 < 0) {
LAB_c07091fc:
            dwErrCode = 0x1f;
            goto LAB_c0709288;
          }
          _Src = auStack_c0;
          _Size = 0x20;
LAB_c07091ec:
          memcpy(param_5,_Src,_Size);
          goto LAB_c0709288;
        }
      }
      else if ((((param_4 == 8) && (param_3 != (undefined4 *)0x0)) &&
               (iVar4 = 0x78, param_6 == 0x78)) && (param_5 != (undefined4 *)0x0)) {
        iVar1 = (**(code **)(*param_1 + 0x68))(param_1,*param_3,param_3[1],auStack_a0);
        if (iVar1 < 0) goto LAB_c07091fc;
        _Src = auStack_a0;
        _Size = 0x78;
        goto LAB_c07091ec;
      }
    }
    else if (param_2 == 0x24) {
      if ((param_4 == 4) && (param_3 != (undefined4 *)0x0)) {
        uVar2 = *param_3;
        uVar3 = 0;
        goto LAB_c0709138;
      }
    }
    else if (((param_2 == 0x28) && (param_4 == 4)) && (param_3 != (undefined4 *)0x0)) {
      uVar2 = *param_3;
      uVar3 = 1;
LAB_c0709138:
      iVar4 = (**(code **)(*param_1 + 0x6c))(param_1,uVar2,uVar3);
      if (-1 < iVar4) {
LAB_c0709150:
        FUN_c0712ee4(local_28);
        return 1;
      }
    }
  }
  dwErrCode = 0x57;
LAB_c07092a4:
  SetLastError(dwErrCode);
  FUN_c0712ee4(local_28);
  return 0;
}



/* c07092c4 FUN_c07092c4 */

/* Boundary evidence: original MIPS .pdata c07092c4..c070935b. Semantic name remains unreviewed. */

void FUN_c07092c4(int param_1,int param_2)

{
  LPCRITICAL_SECTION p_Var1;
  undefined4 *_Memory;
  
  if (param_2 != 0) {
    p_Var1 = (LPCRITICAL_SECTION)(param_1 + 0x2c);
    if (param_1 == 0) {
      p_Var1 = (LPCRITICAL_SECTION)0x0;
    }
    EnterCriticalSection(p_Var1);
    _Memory = (undefined4 *)(param_2 + -0x10);
    if ((*(int *)(param_2 + -0xc) == -0x25525a34) &&
       (*(int *)(param_2 + -8) == *(int *)(param_1 + 0xac))) {
      *_Memory = *(undefined4 *)(param_1 + 0xa8);
      *(undefined4 **)(param_1 + 0xa8) = _Memory;
    }
    else {
      free(_Memory);
    }
    p_Var1 = (LPCRITICAL_SECTION)(param_1 + 0x2c);
    if (param_1 == 0) {
      p_Var1 = (LPCRITICAL_SECTION)0x0;
    }
    LeaveCriticalSection(p_Var1);
  }
  return;
}



/* c070935c FUN_c070935c */

/* Boundary evidence: original MIPS .pdata c070935c..c07093a3. Semantic name remains unreviewed. */

void FUN_c070935c(int param_1)

{
  if (param_1 != 0) {
    if (DAT_c0714150 == 0) {
      free((void *)(param_1 + -0x10));
    }
    else {
      FUN_c07092c4(DAT_c0714150,param_1);
    }
  }
  return;
}



/* c07093a4 FUN_c07093a4 */

/* Boundary evidence: original MIPS .pdata c07093a4..c070940b. Semantic name remains unreviewed. */

void FUN_c07093a4(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x2c);
  if (param_1 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  EnterCriticalSection(lpCriticalSection);
  while (*(int *)(param_1 + 0xa8) != 0) {
    uVar1 = **(undefined4 **)(param_1 + 0xa8);
    free(*(undefined4 **)(param_1 + 0xa8));
    *(undefined4 *)(param_1 + 0xa8) = uVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  return;
}



/* c070940c FUN_c070940c */

/* Boundary evidence: original MIPS .pdata c070940c..c070945b. Semantic name remains unreviewed. */

void FUN_c070940c(int *param_1)

{
  if ((DAT_c0714150 != (int *)0x0) && (DAT_c0714150 == param_1)) {
    (**(code **)(*DAT_c0714150 + 8))(DAT_c0714150,1);
    DAT_c0714150 = (int *)0x0;
  }
  return;
}



/* c070945c FUN_c070945c */

/* Boundary evidence: original MIPS .pdata c070945c..c07094d3. Semantic name remains unreviewed. */

undefined4 FUN_c070945c(LPCWSTR param_1,undefined4 param_2)

{
  LSTATUS LVar1;
  undefined4 local_18;
  DWORD local_14 [3];
  
  if (DAT_c0714150 != 0) {
    local_14[0] = 4;
    local_14[1] = 0;
    local_18 = param_2;
    LVar1 = RegQueryValueExW(*(HKEY *)(DAT_c0714150 + 0xa4),param_1,(LPDWORD)0x0,local_14 + 1,
                             (LPBYTE)&local_18,local_14);
    if (LVar1 == 0) {
      param_2 = local_18;
    }
  }
  return param_2;
}



/* c07094d4 FUN_c07094d4 */

wchar_t * FUN_c07094d4(int param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = (wchar_t *)(param_1 + 0x84);
  if (*pwVar1 == L'\0') {
    pwVar1 = L"SDBus";
  }
  return pwVar1;
}



/* c07094f4 FUN_c07094f4 */

/* Boundary evidence: original MIPS .pdata c07094f4..c0709547. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_c07094f4(LPCRITICAL_SECTION param_1)

{
  HANDLE pvVar1;
  ULONG_PTR *pUVar2;
  
  InitializeCriticalSection(param_1);
  param_1[3].OwningThread = (HANDLE)0x10;
  pvVar1 = (HANDLE)0x0;
  pUVar2 = &param_1->SpinCount;
  do {
    *pUVar2 = 0;
    pvVar1 = (HANDLE)((int)pvVar1 + 1);
    pUVar2 = pUVar2 + 1;
  } while (pvVar1 < param_1[3].OwningThread);
  return param_1;
}



/* c0709548 FUN_c0709548 */

/* Boundary evidence: original MIPS .pdata c0709548..c07095cf. Semantic name remains unreviewed. */

void FUN_c0709548(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  ULONG_PTR *pUVar2;
  HANDLE pvVar3;
  
  EnterCriticalSection(param_1);
  pvVar3 = (HANDLE)0x0;
  if (param_1[3].OwningThread != (HANDLE)0x0) {
    pUVar2 = &param_1->SpinCount;
    do {
      puVar1 = (undefined4 *)*pUVar2;
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(puVar1,1);
      }
      pvVar3 = (HANDLE)((int)pvVar3 + 1);
      pUVar2 = pUVar2 + 1;
    } while (pvVar3 < param_1[3].OwningThread);
  }
  LeaveCriticalSection(param_1);
  DeleteCriticalSection(param_1);
  return;
}



/* c07095d0 FUN_c07095d0 */

/* Boundary evidence: original MIPS .pdata c07095d0..c0709647. Semantic name remains unreviewed. */

ULONG_PTR FUN_c07095d0(LPCRITICAL_SECTION param_1,HANDLE param_2)

{
  ULONG_PTR UVar1;
  
  EnterCriticalSection(param_1);
  if (param_2 < param_1[3].OwningThread) {
    UVar1 = (&param_1->SpinCount)[(int)param_2];
  }
  else {
    UVar1 = 0;
  }
  if (UVar1 != 0) {
    InterlockedIncrement((LONG *)(UVar1 + 4));
  }
  LeaveCriticalSection(param_1);
  return UVar1;
}



/* c0709648 FUN_c0709648 */

/* Boundary evidence: original MIPS .pdata c0709648..c07096c3. Semantic name remains unreviewed. */

undefined4 * FUN_c0709648(LPCRITICAL_SECTION param_1,HANDLE param_2)

{
  undefined4 *puVar1;
  
  EnterCriticalSection(param_1);
  puVar1 = (undefined4 *)0x0;
  if (param_2 < param_1[3].OwningThread) {
    puVar1 = (undefined4 *)(&param_1->SpinCount)[(int)param_2];
    (&param_1->SpinCount)[(int)param_2] = 0;
  }
  LeaveCriticalSection(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c070310c(puVar1);
  }
  return puVar1;
}



/* c07096c4 FUN_c07096c4 */

/* Boundary evidence: original MIPS .pdata c07096c4..c0709793. Semantic name remains unreviewed. */

ULONG_PTR FUN_c07096c4(LPCRITICAL_SECTION param_1,undefined4 *param_2,ULONG_PTR param_3)

{
  HANDLE pvVar1;
  ULONG_PTR *pUVar2;
  ULONG_PTR UVar3;
  HANDLE pvVar4;
  
  if (param_3 == 0) {
    UVar3 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    pvVar1 = param_1[3].OwningThread;
    pvVar4 = (HANDLE)0x0;
    if (pvVar1 != (HANDLE)0x0) {
      pUVar2 = &param_1->SpinCount;
      do {
        if (*pUVar2 == 0) break;
        pvVar4 = (HANDLE)((int)pvVar4 + 1);
        pUVar2 = pUVar2 + 1;
      } while (pvVar4 < pvVar1);
    }
    UVar3 = 0;
    if (pvVar4 < pvVar1) {
      (&param_1->SpinCount)[(int)pvVar4] = param_3;
      InterlockedIncrement((LONG *)(param_3 + 4));
      UVar3 = param_3;
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = pvVar4;
      }
    }
    LeaveCriticalSection(param_1);
  }
  return UVar3;
}



/* c0709794 FUN_c0709794 */

/* Boundary evidence: original MIPS .pdata c0709794..c0709867. Semantic name remains unreviewed. */

int FUN_c0709794(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + 1;
  iVar1 = -0x7ff8ff49;
  if (*piVar2 == 0) {
    iVar1 = CeOpenCallerBuffer(piVar2,param_2,param_3,param_4,param_5);
    if (-1 < iVar1) {
      *param_1 = 0;
      param_1[2] = param_2;
      param_1[3] = param_3;
      param_1[4] = param_4;
      if ((param_6 != 0) &&
         (iVar1 = CeAllocAsynchronousBuffer(param_1,*piVar2,param_3,param_4), iVar1 < 0)) {
        FUN_c0708070(param_1);
      }
    }
  }
  return iVar1;
}



/* c0709868 FUN_c0709868 */

/* Boundary evidence: original MIPS .pdata c0709868..c07098ef. Semantic name remains unreviewed. */

ULONG_PTR FUN_c0709868(ULONG_PTR param_1)

{
  ULONG_PTR UVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 local_18 [2];
  
  if (param_1 == 0) {
    UVar1 = 0;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c);
    if (DAT_c0714150 == 0) {
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    EnterCriticalSection(lpCriticalSection);
    UVar1 = FUN_c07096c4(lpCriticalSection,local_18,param_1);
    if (UVar1 != 0) {
      *(undefined4 *)(UVar1 + 0x5c) = local_18[0];
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return UVar1;
}



/* c07098f0 FUN_c07098f0 */

/* Boundary evidence: original MIPS .pdata c07098f0..c0709a37. Semantic name remains unreviewed. */

undefined4 FUN_c07098f0(undefined4 *param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = param_1 + -2;
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  uVar3 = 0xc0000008;
  puVar1 = (undefined4 *)
           FUN_c07095d0((LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c),(HANDLE)puVar1[0x17]);
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1 + 2 == param_1) {
      if (param_2 < (uint)puVar1[0x1a]) {
        iVar2 = puVar1[param_2 + 0x1b];
      }
      else {
        iVar2 = 0;
      }
      if ((iVar2 != 0) && (uVar3 = 0, 200 < (int)((uint)*(ushort *)(iVar2 + 0xb0) + param_3))) {
        uVar3 = 0xc0000019;
      }
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_c070310c(puVar1);
    }
  }
  return uVar3;
}



/* c0709a38 FUN_c0709a38 */

/* Boundary evidence: original MIPS .pdata c0709a38..c0709a57. Semantic name remains unreviewed. */

void FUN_c0709a38(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c0709a58 FUN_c0709a58 */

/* Boundary evidence: original MIPS .pdata c0709a58..c0709aa3. Semantic name remains unreviewed. */

undefined4 * FUN_c0709a58(undefined4 *param_1,uint param_2)

{
  FUN_c07082a8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0709aa4 FUN_c0709aa4 */

/* Boundary evidence: original MIPS .pdata c0709aa4..c0709b87. Semantic name remains unreviewed. */

undefined4 FUN_c0709aa4(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  if (*(int *)(param_1 + 0x60) == 0) {
    StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0xc),0x10,L"VER 2.0");
    *(code **)(param_1 + 0x58) = FUN_c07098f0;
    uVar6 = 0;
    *(undefined4 *)(param_1 + 8) = 0x10000;
    if (*(int *)(param_1 + 0x68) != 0) {
      puVar5 = (undefined4 *)(param_1 + 0x6c);
      do {
        puVar1 = operator_new(0x108);
        if (puVar1 == (undefined4 *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = FUN_c070c764(puVar1,uVar6,param_1);
        }
        *puVar5 = piVar2;
        if ((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0xc))(piVar2), iVar3 == 0))
        goto LAB_c0709b6c;
        uVar6 = uVar6 + 1;
        puVar5 = puVar5 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x68));
    }
    uVar4 = 1;
    *(undefined4 *)(param_1 + 0x60) = 1;
  }
  else {
LAB_c0709b6c:
    uVar4 = 0;
  }
  return uVar4;
}



/* c0709b88 FUN_c0709b88 */

/* Boundary evidence: original MIPS .pdata c0709b88..c0709c57. Semantic name remains unreviewed. */

undefined4 * FUN_c0709b88(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  LSTATUS LVar2;
  HKEY hKey;
  LPBYTE lpData;
  DWORD local_18;
  DWORD local_14;
  
  FUN_c0711d2c(param_1,param_2);
  FUN_c07094f4((LPCRITICAL_SECTION)(param_1 + 0xb));
  *param_1 = &PTR_FUN_c0701564;
  param_1[0x29] = 0;
  if (param_2 != 0) {
    uVar1 = OpenDeviceKey(param_2);
    param_1[0x29] = uVar1;
  }
  lpData = (LPBYTE)(param_1 + 0x21);
  hKey = (HKEY)param_1[0x29];
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  lpData[0] = '\0';
  lpData[1] = '\0';
  local_18 = 0x20;
  if (((hKey != (HKEY)0x0) &&
      (LVar2 = RegQueryValueExW(hKey,L"SubBusName",(LPDWORD)0x0,&local_14,lpData,&local_18),
      LVar2 == 0)) && (local_14 == 1)) {
    *(undefined2 *)((int)param_1 + 0xa2) = 0;
    return param_1;
  }
  lpData[0] = '\0';
  lpData[1] = '\0';
  return param_1;
}



/* c0709c60 FUN_c0709c60 */

/* Boundary evidence: original MIPS .pdata c0709c60..c0709cff. Semantic name remains unreviewed. */

void FUN_c0709c60(undefined4 *param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xb);
  *param_1 = &PTR_FUN_c0701564;
  EnterCriticalSection(lpCriticalSection);
  while (param_1[0x2a] != 0) {
    uVar1 = *(undefined4 *)param_1[0x2a];
    free((undefined4 *)param_1[0x2a]);
    param_1[0x2a] = uVar1;
  }
  LeaveCriticalSection(lpCriticalSection);
  if ((HKEY)param_1[0x29] != (HKEY)0x0) {
    RegCloseKey((HKEY)param_1[0x29]);
  }
  FUN_c0709548(lpCriticalSection);
  FUN_c0711dbc(param_1);
  return;
}



/* c0709d00 FUN_c0709d00 */

/* Boundary evidence: original MIPS .pdata c0709d00..c0709d5b. Semantic name remains unreviewed. */

undefined4 FUN_c0709d00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0711d98(param_1);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0xa4) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_c070945c(L"RequestRetryCount",3);
    *(undefined4 *)(param_1 + 0xb0) = uVar2;
    uVar2 = 1;
  }
  return uVar2;
}



/* c0709d5c FUN_c0709d5c */

/* Boundary evidence: original MIPS .pdata c0709d5c..c0709e27. Semantic name remains unreviewed. */

undefined4 * FUN_c0709d5c(int param_1,uint param_2)

{
  void *pvVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)0x0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x2c);
  if (param_1 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  EnterCriticalSection(lpCriticalSection);
  if (*(uint *)(param_1 + 0xac) < param_2) {
    FUN_c07093a4(param_1);
    *(uint *)(param_1 + 0xac) = param_2;
  }
  if (*(int *)(param_1 + 0xa8) == 0) {
    pvVar1 = malloc(*(int *)(param_1 + 0xac) + 0x10);
    *(void **)(param_1 + 0xa8) = pvVar1;
    if (pvVar1 != (void *)0x0) {
      *(undefined4 *)((int)pvVar1 + 4) = 0xdaada5cc;
      *(undefined4 *)(*(int *)(param_1 + 0xa8) + 8) = *(undefined4 *)(param_1 + 0xac);
      **(undefined4 **)(param_1 + 0xa8) = 0;
    }
  }
  puVar2 = *(undefined4 **)(param_1 + 0xa8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = puVar2 + 4;
    *(undefined4 *)(param_1 + 0xa8) = *puVar2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  return puVar3;
}



/* c0709e28 FUN_c0709e28 */

/* Boundary evidence: original MIPS .pdata c0709e28..c0709ea3. Semantic name remains unreviewed. */

void FUN_c0709e28(int param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = (HANDLE)0xffffffff;
  if (param_1 != 0) {
    pvVar1 = *(HANDLE *)(param_1 + 0x5c);
  }
  FUN_c07095d0((LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c),pvVar1);
  return;
}



/* c0709ea4 FUN_c0709ea4 */

/* Boundary evidence: original MIPS .pdata c0709ea4..c0709ec3. Semantic name remains unreviewed. */

void FUN_c0709ea4(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c0709ec4 FUN_c0709ec4 */

/* Boundary evidence: original MIPS .pdata c0709ec4..c0709f83. Semantic name remains unreviewed. */

int FUN_c0709ec4(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar1 = (undefined4 *)
           FUN_c07095d0((LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c),(HANDLE)(param_1 & 0xf));
  if (((param_1 != 0) && ((param_1 & 0xf800) == 0x7800)) && (puVar1 != (undefined4 *)0x0)) {
    uVar3 = param_1 >> 4 & 0xf;
    if (uVar3 < (uint)puVar1[0x1a]) {
      iVar2 = puVar1[uVar3 + 0x1b];
    }
    else {
      iVar2 = 0;
    }
    if (iVar2 != 0) {
      iVar4 = FUN_c0708164(iVar2,param_1 >> 8 & 7,param_1 >> 0x10);
    }
    FUN_c070310c(puVar1);
  }
  return iVar4;
}



/* c0709f84 FUN_c0709f84 */

/* Boundary evidence: original MIPS .pdata c0709f84..c070a03f. Semantic name remains unreviewed. */

int FUN_c0709f84(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar1 = (undefined4 *)
           FUN_c07095d0((LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c),(HANDLE)(param_1 & 0xf));
  if (((param_1 != 0) && ((param_1 & 0xf800) == 0xf800)) && (puVar1 != (undefined4 *)0x0)) {
    uVar3 = param_1 >> 4 & 0xf;
    if (uVar3 < (uint)puVar1[0x1a]) {
      iVar2 = puVar1[uVar3 + 0x1b];
    }
    else {
      iVar2 = 0;
    }
    if (iVar2 != 0) {
      iVar4 = FUN_c07031cc(iVar2,param_1 >> 8 & 7);
    }
    FUN_c070310c(puVar1);
  }
  return iVar4;
}



/* c070a040 FUN_c070a040 */

/* Boundary evidence: original MIPS .pdata c070a040..c070a06f. Semantic name remains unreviewed. */

undefined4 * FUN_c070a040(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x0;
  if (DAT_c0714150 != 0) {
    puVar1 = FUN_c0709d5c(DAT_c0714150,param_1);
  }
  return puVar1;
}



/* c070a070 FUN_c070a070 */

/* Boundary evidence: original MIPS .pdata c070a070..c070a113. Semantic name remains unreviewed. */

int * FUN_c070a070(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  if (DAT_c0714150 == (int *)0x0) {
    puVar2 = operator_new(0xb4);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_c0709b88(puVar2,param_1);
    }
    piVar1 = piVar3;
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)*piVar3)(piVar3), iVar4 == 0)) {
      (**(code **)(*piVar3 + 8))(piVar3,1);
      piVar3 = (int *)0x0;
      piVar1 = piVar3;
    }
  }
  else {
    piVar3 = (int *)0x0;
    piVar1 = DAT_c0714150;
  }
  DAT_c0714150 = piVar1;
  return piVar3;
}



/* c070a114 FUN_c070a114 */

/* Boundary evidence: original MIPS .pdata c070a114..c070a1cf. Semantic name remains unreviewed. */

undefined4 FUN_c070a114(uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  ULONG_PTR UVar4;
  
  if ((param_2 != (undefined4 *)0x0) && (param_1 != 0)) {
    puVar1 = operator_new(0xac);
    if (puVar1 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_c0708208(puVar1,param_1);
    }
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 4))(piVar2);
      if ((iVar3 != 0) && (UVar4 = FUN_c0709868((ULONG_PTR)piVar2), UVar4 != 0)) {
        *param_2 = piVar2 + 2;
        return 0;
      }
      (**(code **)*piVar2)(piVar2,1);
    }
  }
  return 0xc0000007;
}



/* c070a1d0 FUN_c070a1d0 */

/* Boundary evidence: original MIPS .pdata c070a1d0..c070a267. Semantic name remains unreviewed. */

undefined4 FUN_c070a1d0(uint *param_1)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  puVar2 = param_1 + -2;
  if (param_1 == (uint *)0x0) {
    puVar2 = (uint *)0x0;
  }
  piVar1 = (int *)FUN_c0709e28((int)puVar2);
  uVar3 = 0xc0000003;
  if (piVar1 != (int *)0x0) {
    if (*param_1 < 0x10001) {
      (**(code **)(*piVar1 + 8))(piVar1);
      uVar3 = (*(code *)piVar1[0x13])(piVar1 + 2);
    }
    FUN_c070310c(piVar1);
  }
  return uVar3;
}



/* c070a268 FUN_c070a268 */

/* Boundary evidence: original MIPS .pdata c070a268..c070a2f7. Semantic name remains unreviewed. */

undefined4 FUN_c070a268(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xc0000003;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -8;
  }
  piVar1 = (int *)FUN_c0709e28(iVar2);
  if (piVar1 != (int *)0x0) {
    FUN_c0709648((LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c),(HANDLE)piVar1[0x17]);
    (**(code **)(*piVar1 + 0xc))(piVar1);
    uVar3 = (*(code *)piVar1[0x14])(piVar1 + 2);
    FUN_c070310c(piVar1);
  }
  return uVar3;
}



/* c070a2f8 FUN_c070a2f8 */

/* Boundary evidence: original MIPS .pdata c070a2f8..c070a357. Semantic name remains unreviewed. */

void FUN_c070a2f8(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -8;
  }
  puVar1 = (undefined4 *)FUN_c0709e28(iVar2);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c0709648((LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c),(HANDLE)puVar1[0x17]);
    FUN_c070310c(puVar1);
  }
  return;
}



/* c070a358 FUN_c070a358 */

/* Boundary evidence: original MIPS .pdata c070a358..c070a41f. Semantic name remains unreviewed. */

void FUN_c070a358(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  iVar2 = param_1 + -8;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  puVar1 = (undefined4 *)FUN_c0709e28(iVar2);
  if (puVar1 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)(param_1 + -8);
    if (param_1 == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    if (puVar4 == puVar1) {
      if (param_2 < (uint)puVar1[0x1a]) {
        piVar3 = (int *)puVar1[param_2 + 0x1b];
      }
      else {
        piVar3 = (int *)0x0;
      }
      if ((puVar1[0x19] != 0) && (piVar3 != (int *)0x0)) {
        (**(code **)(*piVar3 + 0x20))(piVar3,param_3);
      }
    }
    FUN_c070310c(puVar1);
  }
  return;
}



/* c070a420 FUN_c070a420 */

/* Boundary evidence: original MIPS .pdata c070a420..c070a50b. Semantic name remains unreviewed. */

void FUN_c070a420(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -8;
  }
  puVar1 = (undefined4 *)FUN_c0709e28(iVar2);
  if (puVar1 == (undefined4 *)0x0) {
    NKDbgPrintfW(L"SDBusDriver: Passed invalid SDCARD_HC_CONTEXT \r\n");
  }
  else {
    if (param_4 < (uint)puVar1[0x1a]) {
      piVar3 = (int *)puVar1[param_4 + 0x1b];
    }
    else {
      piVar3 = (int *)0x0;
    }
    if ((puVar1[0x19] != 0) && (piVar3 != (int *)0x0)) {
      if (param_2 == 0) {
        (**(code **)(*piVar3 + 0x1c))(piVar3,param_3);
      }
      else {
        (**(code **)(*piVar3 + 0x18))();
      }
    }
    FUN_c070310c(puVar1);
  }
  return;
}



/* c070a50c FUN_c070a50c */

/* Boundary evidence: original MIPS .pdata c070a50c..c070a663. Semantic name remains unreviewed. */

void FUN_c070a50c(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  HANDLE pvVar3;
  int iVar4;
  int iVar5;
  HANDLE pvVar6;
  
  iVar5 = param_2 + -4;
  if (param_2 == 0) {
    iVar5 = 0;
  }
  pvVar3 = (HANDLE)0xffffffff;
  pvVar6 = pvVar3;
  if (iVar5 != 0) {
    iVar4 = *(int *)(*(int *)(iVar5 + 0x68) + 0x430);
    pvVar3 = *(HANDLE *)(*(int *)(iVar4 + 0x7c) + 0x5c);
    pvVar6 = *(HANDLE *)(iVar4 + 0x80);
  }
  puVar1 = (undefined4 *)FUN_c07095d0((LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c),pvVar3);
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1 + 2 == param_1) {
      if (pvVar6 < (HANDLE)puVar1[0x1a]) {
        piVar2 = (int *)puVar1[(int)pvVar6 + 0x1b];
      }
      else {
        piVar2 = (int *)0x0;
      }
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x38))(piVar2,iVar5,param_3);
      }
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_c070310c(puVar1);
    }
  }
  return;
}



/* c070a664 FUN_c070a664 */

/* Boundary evidence: original MIPS .pdata c070a664..c070a66f. Semantic name remains unreviewed. */

undefined4 FUN_c070a664(void)

{
  return 1;
}



/* c070a670 FUN_c070a670 */

/* Boundary evidence: original MIPS .pdata c070a670..c070a7a7. Semantic name remains unreviewed. */

int FUN_c070a670(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  HANDLE pvVar3;
  int iVar4;
  
  pvVar3 = (HANDLE)0xffffffff;
  iVar4 = 0;
  if (param_1 != (undefined4 *)0x0) {
    pvVar3 = (HANDLE)param_1[0x15];
  }
  puVar1 = (undefined4 *)FUN_c07095d0((LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c),pvVar3);
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1 + 2 == param_1) {
      if (param_2 < (uint)puVar1[0x1a]) {
        iVar2 = puVar1[param_2 + 0x1b];
      }
      else {
        iVar2 = 0;
      }
      if (iVar2 != 0) {
        iVar4 = FUN_c070d214(iVar2);
      }
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_c070310c(puVar1);
    }
  }
  iVar2 = iVar4 + 4;
  if (iVar4 == 0) {
    iVar2 = 0;
  }
  return iVar2;
}



/* c070a7a8 FUN_c070a7a8 */

/* Boundary evidence: original MIPS .pdata c070a7a8..c070a7b3. Semantic name remains unreviewed. */

undefined4 FUN_c070a7a8(void)

{
  return 1;
}



/* c070a7b4 FUN_c070a7b4 */

/* Boundary evidence: original MIPS .pdata c070a7b4..c070a8e7. Semantic name remains unreviewed. */

void FUN_c070a7b4(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  HANDLE pvVar2;
  int iVar3;
  HANDLE pvVar4;
  
  pvVar2 = (HANDLE)0xffffffff;
  pvVar4 = pvVar2;
  if (param_1 != (undefined4 *)0x0) {
    pvVar2 = (HANDLE)param_1[0x15];
    iVar3 = param_2 + -4;
    if (param_2 == 0) {
      iVar3 = 0;
    }
    pvVar4 = *(HANDLE *)(*(int *)(*(int *)(iVar3 + 0x68) + 0x430) + 0x80);
  }
  puVar1 = (undefined4 *)FUN_c07095d0((LPCRITICAL_SECTION)(DAT_c0714150 + 0x2c),pvVar2);
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1 + 2 == param_1) {
      if (pvVar4 < (HANDLE)puVar1[0x1a]) {
        iVar3 = puVar1[(int)pvVar4 + 0x1b];
      }
      else {
        iVar3 = 0;
      }
      if (iVar3 != 0) {
        FUN_c070d278(iVar3,param_2);
      }
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_c070310c(puVar1);
    }
  }
  return;
}



/* c070a8e8 FUN_c070a8e8 */

/* Boundary evidence: original MIPS .pdata c070a8e8..c070a8f3. Semantic name remains unreviewed. */

undefined4 FUN_c070a8e8(void)

{
  return 1;
}



/* c070a8f4 FUN_c070a8f4 */

/* Boundary evidence: original MIPS .pdata c070a8f4..c070a9b7. Semantic name remains unreviewed. */

int FUN_c070a8f4(uint param_1,undefined4 param_2,STRSAFE_LPCWSTR param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = -0x3ffffff9;
  puVar1 = (undefined4 *)FUN_c0709ec4(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_c0704174((int)puVar1,0,param_2,param_3);
    FUN_c070310c(puVar1);
  }
  return iVar2;
}



/* c070a9b8 FUN_c070a9b8 */

/* Boundary evidence: original MIPS .pdata c070a9b8..c070a9d7. Semantic name remains unreviewed. */

void FUN_c070a9b8(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070a9d8 FUN_c070a9d8 */

/* Boundary evidence: original MIPS .pdata c070a9d8..c070aaef. Semantic name remains unreviewed. */

undefined4
FUN_c070a9d8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000007;
  piVar1 = (int *)FUN_c0709ec4(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x14))
                      (piVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c070aaf0 FUN_c070aaf0 */

/* Boundary evidence: original MIPS .pdata c070aaf0..c070ab0f. Semantic name remains unreviewed. */

void FUN_c070aaf0(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070ab10 FUN_c070ab10 */

/* Boundary evidence: original MIPS .pdata c070ab10..c070ac37. Semantic name remains unreviewed. */

undefined4
FUN_c070ab10(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000007;
  piVar1 = (int *)FUN_c0709ec4(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x18))
                      (piVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12,param_13,param_14);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c070ac38 FUN_c070ac38 */

/* Boundary evidence: original MIPS .pdata c070ac38..c070ac57. Semantic name remains unreviewed. */

void FUN_c070ac38(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070ac58 FUN_c070ac58 */

/* Boundary evidence: original MIPS .pdata c070ac58..c070acaf. Semantic name remains unreviewed. */

void FUN_c070ac58(uint param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_c0709f84(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,param_1);
    FUN_c070310c(piVar1);
  }
  return;
}



/* c070acb0 FUN_c070acb0 */

/* Boundary evidence: original MIPS .pdata c070acb0..c070ad87. Semantic name remains unreviewed. */

undefined4 FUN_c070acb0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000007;
  piVar1 = (int *)FUN_c0709ec4(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x34))(piVar1,param_2,param_3,param_4);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c070ad88 FUN_c070ad88 */

/* Boundary evidence: original MIPS .pdata c070ad88..c070ada7. Semantic name remains unreviewed. */

void FUN_c070ad88(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070ada8 FUN_c070ada8 */

/* Boundary evidence: original MIPS .pdata c070ada8..c070aed3. Semantic name remains unreviewed. */

undefined4
FUN_c070ada8(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined1 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar3 = 0xc0000007;
  piVar1 = (int *)FUN_c0709ec4(param_1);
  if (piVar1 != (int *)0x0) {
    piVar4 = piVar1;
    if (((piVar1[0x10d] != 0) && (param_3 == 0)) &&
       (piVar2 = (int *)FUN_c07031cc(piVar1[0x10c],0), piVar2 != (int *)0x0)) {
      FUN_c070310c(piVar1);
      piVar1 = piVar2;
      piVar4 = piVar2;
    }
    uVar3 = (**(code **)(*piVar1 + 0x10))(piVar1,param_2,param_4,param_5,param_6,param_7,piVar4);
    FUN_c070310c(piVar1);
  }
  return uVar3;
}



/* c070aed4 FUN_c070aed4 */

/* Boundary evidence: original MIPS .pdata c070aed4..c070aef3. Semantic name remains unreviewed. */

void FUN_c070aed4(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070aef4 FUN_c070aef4 */

/* Boundary evidence: original MIPS .pdata c070aef4..c070af5f. Semantic name remains unreviewed. */

undefined1 FUN_c070aef4(uint param_1)

{
  undefined1 uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = (int *)FUN_c0709f84(param_1);
  if (piVar2 != (int *)0x0) {
    uVar1 = (**(code **)(*piVar2 + 0x24))(piVar2,param_1);
    FUN_c070310c(piVar2);
  }
  return uVar1;
}



/* c070af60 FUN_c070af60 */

/* Boundary evidence: original MIPS .pdata c070af60..c070b03f. Semantic name remains unreviewed. */

undefined4
FUN_c070af60(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000007;
  piVar1 = (int *)FUN_c0709ec4(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,param_2,param_3,param_4,param_5);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c070b040 FUN_c070b040 */

/* Boundary evidence: original MIPS .pdata c070b040..c070b05f. Semantic name remains unreviewed. */

void FUN_c070b040(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070b060 FUN_c070b060 */

/* Boundary evidence: original MIPS .pdata c070b060..c070b11b. Semantic name remains unreviewed. */

undefined4 FUN_c070b060(uint param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000007;
  piVar1 = (int *)FUN_c0709ec4(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x28))(piVar1,param_2,1);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c070b11c FUN_c070b11c */

/* Boundary evidence: original MIPS .pdata c070b11c..c070b13b. Semantic name remains unreviewed. */

void FUN_c070b11c(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070b13c FUN_c070b13c */

/* Boundary evidence: original MIPS .pdata c070b13c..c070b1b7. Semantic name remains unreviewed. */

void FUN_c070b13c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_c0709ec4(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x28))(piVar1,0,0);
    FUN_c070310c(piVar1);
  }
  return;
}



/* c070b1b8 FUN_c070b1b8 */

/* Boundary evidence: original MIPS .pdata c070b1b8..c070b1d7. Semantic name remains unreviewed. */

void FUN_c070b1b8(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070b1d8 FUN_c070b1d8 */

/* Boundary evidence: original MIPS .pdata c070b1d8..c070b2a7. Semantic name remains unreviewed. */

int FUN_c070b1d8(uint param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = -0x3ffffff9;
  piVar1 = (int *)FUN_c0709ec4(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = FUN_c07104e8(piVar1,param_2,param_3,param_4);
    FUN_c070310c(piVar1);
  }
  return iVar2;
}



/* c070b2a8 FUN_c070b2a8 */

/* Boundary evidence: original MIPS .pdata c070b2a8..c070b2c7. Semantic name remains unreviewed. */

void FUN_c070b2a8(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070b2c8 FUN_c070b2c8 */

/* Boundary evidence: original MIPS .pdata c070b2c8..c070b393. Semantic name remains unreviewed. */

undefined4 FUN_c070b2c8(uint param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000007;
  piVar1 = (int *)FUN_c0709f84(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,param_1,param_2);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c070b394 FUN_c070b394 */

/* Boundary evidence: original MIPS .pdata c070b394..c070b3b3. Semantic name remains unreviewed. */

void FUN_c070b394(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070b3b4 SDGetClientFunctions */

undefined4 SDGetClientFunctions(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0xb3b4  7  SDGetClientFunctions */
  uVar1 = 0xc0000007;
  if ((param_1 != (int *)0x0) && (*param_1 == 0x34)) {
    param_1[1] = (int)FUN_c070a8f4;
    param_1[2] = (int)FUN_c070a9d8;
    param_1[3] = (int)FUN_c070ab10;
    param_1[4] = (int)FUN_c070ac58;
    param_1[5] = (int)FUN_c070acb0;
    param_1[6] = (int)FUN_c070ada8;
    param_1[7] = (int)FUN_c070aef4;
    param_1[8] = (int)FUN_c070af60;
    param_1[9] = (int)FUN_c070b060;
    uVar1 = 0;
    param_1[10] = (int)FUN_c070b13c;
    param_1[0xb] = (int)FUN_c070b1d8;
    param_1[0xc] = (int)FUN_c070b2c8;
  }
  return uVar1;
}



/* c070b46c FUN_c070b46c */

/* Boundary evidence: original MIPS .pdata c070b46c..c070b4b7. Semantic name remains unreviewed. */

undefined4 * FUN_c070b46c(undefined4 *param_1,uint param_2)

{
  FUN_c0709c60(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c070b4b8 FUN_c070b4b8 */

/* Boundary evidence: original MIPS .pdata c070b4b8..c070c313. Semantic name remains unreviewed. */

undefined4
FUN_c070b4b8(int *param_1,uint param_2,uint *param_3,uint param_4,int *param_5,int *param_6,
            int *param_7)

{
  int *piVar1;
  uint *puVar2;
  uint **ppuVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  DWORD DVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *local_180;
  DWORD local_17c;
  int *local_178;
  DWORD local_174;
  int *local_170;
  int local_168;
  int local_164;
  undefined4 local_15c;
  int local_150;
  int local_14c;
  undefined4 local_144;
  uint *local_138;
  uint *local_134;
  undefined4 local_12c;
  int local_120;
  int local_11c;
  undefined4 local_114;
  uint *local_108;
  uint *local_104;
  undefined4 local_fc;
  int local_f0;
  int local_ec;
  undefined4 local_e4;
  uint *local_d8;
  uint *local_d4;
  undefined4 local_cc;
  int local_c0;
  int local_bc;
  undefined4 local_b4;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  char local_98;
  int local_94;
  int local_90;
  uint local_88;
  uint local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  int local_74;
  int local_70;
  int local_6c;
  uint local_68;
  int local_64;
  int local_60;
  undefined4 local_58;
  uint local_54;
  int local_50;
  int local_4c;
  uint local_2c;
  
  local_2c = DAT_c0714140;
  local_178 = param_7;
  uVar6 = 0;
  if (param_2 < 0x2a0511) {
    if (param_2 != 0x2a0510) {
      if (param_2 < 0x2a0045) {
        if ((((param_2 != 0x2a0044) && (param_2 != 0x2a0004)) &&
            ((param_2 != 0x2a0008 && ((param_2 != 0x2a0014 && (param_2 != 0x2a0018)))))) &&
           (param_2 != 0x2a0040)) goto switchD_c070bacc_caseD_2a0515;
      }
      else if (param_2 != 0x2a0080) {
        if (param_2 == 0x2a0500) {
          if ((param_3 != (uint *)0x0) && (0x5b < param_4)) {
            memcpy(&local_88,param_3,0x5c);
            DVar7 = 0xc0000007;
            piVar1 = (int *)FUN_c0709ec4(local_88);
            if (piVar1 != (int *)0x0) {
              DVar7 = FUN_c0704174((int)piVar1,local_80,local_84,(STRSAFE_LPCWSTR)&local_7c);
              goto LAB_c070b9ec;
            }
            goto LAB_c070b7ec;
          }
        }
        else if (param_2 == 0x2a0504) {
          if ((param_3 != (uint *)0x0) && (0x23 < param_4)) {
            memcpy(&local_88,param_3,0x24);
            piVar1 = (int *)FUN_c0709ec4(local_88);
            if (piVar1 == (int *)0x0) goto LAB_c070b95c;
            iVar4 = 8;
            if (local_7c != 0) {
              iVar4 = 4;
            }
            local_164 = 0;
            local_168 = 0;
            local_15c = 0;
            FUN_c0709794(&local_168,local_6c,local_74 * local_70,iVar4,0,1);
            iVar4 = local_168;
            if (local_168 == 0) {
              iVar4 = local_164;
            }
            DVar7 = (**(code **)(*piVar1 + 0x14))
                              (piVar1,local_84 & 0xff,local_80,local_7c,local_78,&local_a8,local_74,
                               local_70,iVar4,local_68 & 0xffff7fff,0,0);
            if ((param_5 != (int *)0x0) && ((int *)0x17 < param_6)) {
              memcpy(param_5,&local_a8,0x18);
            }
            FUN_c070310c(piVar1);
            piVar1 = &local_168;
            goto LAB_c070b94c;
          }
        }
        else {
          if (param_2 != 0x2a0508) {
            if (param_2 == 0x2a050c) {
              if ((param_3 == (uint *)0x0) || (param_4 < 4)) goto LAB_c070b5bc;
              uVar8 = *param_3;
              piVar1 = (int *)FUN_c0709f84(uVar8);
              if (piVar1 == (int *)0x0) goto LAB_c070b5bc;
              (**(code **)(*piVar1 + 0x1c))(piVar1,uVar8);
              goto LAB_c070b690;
            }
            goto switchD_c070bacc_caseD_2a0515;
          }
          if ((((param_3 != (uint *)0x0) && (0x37 < param_4)) && (param_5 != (int *)0x0)) &&
             ((int *)0x3 < param_6)) {
            DVar7 = 0xc0000007;
            memcpy(&local_88,param_3,0x38);
            local_180 = (int *)0x0;
            piVar1 = (int *)FUN_c0709ec4(local_88);
            if (piVar1 != (int *)0x0) {
              iVar4 = 8;
              if (local_7c != 0) {
                iVar4 = 4;
              }
              local_134 = (uint *)0x0;
              local_138 = (uint *)0x0;
              local_12c = 0;
              FUN_c0709794((int *)&local_138,local_6c,local_74 * local_70,iVar4,0,0);
              puVar2 = local_138;
              if (local_138 == (uint *)0x0) {
                puVar2 = local_134;
              }
              DVar7 = (**(code **)(*piVar1 + 0x18))
                                (piVar1,local_84 & 0xff,local_80,local_7c,local_78,local_74,local_70
                                 ,puVar2,local_68,local_58,&local_180,local_54 & 0xffff7fff,0,0);
              FUN_c070310c(piVar1);
              *param_5 = (int)local_180;
              ppuVar3 = &local_138;
              goto LAB_c070b7e4;
            }
            goto LAB_c070b7ec;
          }
        }
        goto LAB_c070bbcc;
      }
      SetLastError(0x32);
      goto LAB_c070ba10;
    }
    if ((param_3 != (uint *)0x0) && (7 < param_4)) {
      DVar7 = 0xc0000007;
      local_174 = 0xc0000007;
      piVar1 = (int *)FUN_c0709ec4(*param_3);
      local_180 = piVar1;
      if (piVar1 != (int *)0x0) {
        DVar7 = (**(code **)(*piVar1 + 0x34))(piVar1,param_3[1],param_5,param_6);
        local_174 = DVar7;
LAB_c070b9ec:
        FUN_c070310c(piVar1);
      }
      goto LAB_c070b7ec;
    }
    goto LAB_c070bbcc;
  }
  switch(param_2) {
  case 0x2a0514:
    if ((param_3 != (uint *)0x0) && (7 < param_4)) {
      DVar7 = 0xc0000007;
      memcpy(&local_a8,param_3,0x1c);
      piVar1 = (int *)FUN_c0709ec4(local_a8);
      uVar8 = local_a4;
      if (piVar1 != (int *)0x0) {
        uVar9 = 4;
        if (local_a4 != 1) {
          uVar9 = 8;
        }
        if (local_98 != '\0') {
          uVar9 = uVar9 | 8;
        }
        local_bc = 0;
        local_c0 = 0;
        local_b4 = 0;
        FUN_c0709794(&local_c0,local_94,local_90,uVar9,0,0);
        iVar4 = local_c0;
        if (local_c0 == 0) {
          iVar4 = local_bc;
        }
        DVar7 = (**(code **)(*piVar1 + 0x10))(piVar1,uVar8,local_9c,local_98,iVar4,local_90);
        FUN_c070310c(piVar1);
        FUN_c0708070(&local_c0);
      }
LAB_c070bcdc:
      SetLastError(DVar7);
joined_r0xc070b974:
      uVar6 = 1;
      if (-1 < (int)DVar7) goto LAB_c070b5bc;
LAB_c070ba10:
      uVar6 = 0;
      goto LAB_c070b5bc;
    }
    break;
  default:
switchD_c070bacc_caseD_2a0515:
    uVar6 = (**(code **)(*param_1 + 0x58))
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
    goto LAB_c070b5bc;
  case 0x2a0518:
    if ((param_3 != (uint *)0x0) && (3 < param_4)) {
      uVar8 = *param_3;
      piVar1 = (int *)FUN_c0709f84(uVar8);
      if (piVar1 != (int *)0x0) {
        uVar6 = (**(code **)(*piVar1 + 0x24))(piVar1,uVar8);
        goto LAB_c070b5bc;
      }
    }
    DVar7 = 0x57;
    goto LAB_c070bbd4;
  case 0x2a051c:
    if ((param_3 != (uint *)0x0) && (0xb < param_4)) {
      DVar7 = 0xc0000007;
      local_17c = 0xc0000007;
      local_a4 = param_3[1];
      uVar8 = param_3[2];
      local_180 = param_6;
      piVar1 = (int *)FUN_c0709ec4(*param_3);
      local_170 = piVar1;
      if (piVar1 != (int *)0x0) {
        DVar7 = (**(code **)(*piVar1 + 0x30))(piVar1,local_a4 & 0xff,param_5,&local_180,uVar8);
        local_17c = DVar7;
        FUN_c070310c(piVar1);
      }
      SetLastError(DVar7);
      if (-1 < (int)DVar7) {
        uVar6 = 1;
        piVar1 = local_180;
        if (param_7 == (int *)0x0) goto LAB_c070b5bc;
LAB_c070c1cc:
        uVar6 = 1;
        *param_7 = (int)piVar1;
        goto LAB_c070b5bc;
      }
      goto LAB_c070ba10;
    }
    break;
  case 0x2a0520:
    if ((param_3 != (uint *)0x0) && (0xf < param_4)) {
      DVar7 = 0xc0000007;
      uVar8 = param_3[1];
      local_a0 = param_3[2];
      local_9c = param_3[3];
      piVar1 = (int *)FUN_c0709ec4(*param_3);
      if (piVar1 != (int *)0x0) {
        DVar7 = (**(code **)(*piVar1 + 0x28))(piVar1,uVar8,1);
        FUN_c070310c(piVar1);
      }
      goto LAB_c070bcdc;
    }
    break;
  case 0x2a0524:
    if ((param_3 != (uint *)0x0) && (3 < param_4)) {
      piVar1 = (int *)FUN_c0709ec4(*param_3);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x28))(piVar1,0,0);
LAB_c070b690:
        FUN_c070310c(piVar1);
      }
LAB_c070b698:
      uVar6 = 1;
      goto LAB_c070b5bc;
    }
    break;
  case 0x2a0528:
    if ((param_3 != (uint *)0x0) && (0xf < param_4)) {
      DVar7 = 0xc0000007;
      uVar10 = param_3[1];
      uVar9 = param_3[2];
      uVar8 = param_3[3];
      piVar1 = (int *)FUN_c0709ec4(*param_3);
      if (piVar1 != (int *)0x0) {
        local_104 = (uint *)0x0;
        local_108 = (uint *)0x0;
        local_fc = 0;
        FUN_c0709794((int *)&local_108,uVar9,uVar8,4,0,0);
        puVar2 = local_108;
        if (local_108 == (uint *)0x0) {
          puVar2 = local_104;
        }
        DVar7 = FUN_c07104e8(piVar1,uVar10,puVar2,uVar8);
        FUN_c070310c(piVar1);
        ppuVar3 = &local_108;
LAB_c070b7e4:
        FUN_c0708070((int *)ppuVar3);
      }
LAB_c070b7ec:
      SetLastError(DVar7);
      if (-1 < (int)DVar7) goto LAB_c070b698;
      goto LAB_c070ba10;
    }
    break;
  case 0x2a052c:
    if ((((param_3 != (uint *)0x0) && (3 < param_4)) && (param_5 != (int *)0x0)) &&
       ((int *)0x17 < param_6)) {
      DVar7 = 0xc0000007;
      uVar8 = *param_3;
      piVar1 = (int *)FUN_c0709f84(uVar8);
      if (piVar1 != (int *)0x0) {
        DVar7 = (**(code **)(*piVar1 + 0x20))(piVar1,uVar8,&local_a8);
        FUN_c070310c(piVar1);
        if (-1 < (int)DVar7) {
          memcpy(param_5,&local_a8,0x18);
        }
      }
      goto LAB_c070b7ec;
    }
    break;
  case 0x2a0530:
    if ((param_5 != (int *)0x0) && ((int *)0x33 < param_6)) {
      DVar7 = SDGetClientFunctions(param_5);
      SetLastError(DVar7);
      if (-1 < (int)DVar7) {
        uVar6 = 1;
        if (param_7 == (int *)0x0) goto LAB_c070b5bc;
        piVar1 = (int *)0x34;
        goto LAB_c070c1cc;
      }
      goto LAB_c070ba10;
    }
    break;
  case 0x2a0534:
    if ((param_3 != (uint *)0x0) && (0x2b < param_4)) {
      memcpy(&local_88,param_3,0x2c);
      piVar1 = (int *)FUN_c0709ec4(local_88);
      if (piVar1 == (int *)0x0) {
LAB_c070b95c:
        DVar7 = 0xc0000007;
      }
      else {
        iVar4 = 8;
        if (local_7c != 0) {
          iVar4 = 4;
        }
        local_11c = 0;
        local_120 = 0;
        local_114 = 0;
        FUN_c0709794(&local_120,local_6c,local_74 * local_70,iVar4,0,1);
        local_14c = 0;
        local_150 = 0;
        local_144 = 0;
        FUN_c0709794(&local_150,local_60,local_64,4,0,0);
        iVar4 = local_150;
        if (local_150 == 0) {
          iVar4 = local_14c;
        }
        iVar5 = local_120;
        if (local_120 == 0) {
          iVar5 = local_11c;
        }
        DVar7 = (**(code **)(*piVar1 + 0x14))
                          (piVar1,local_84 & 0xff,local_80,local_7c,local_78,&local_a8,local_74,
                           local_70,iVar5,local_68,local_64,iVar4);
        if ((param_5 != (int *)0x0) && ((int *)0x17 < param_6)) {
          memcpy(param_5,&local_a8,0x18);
        }
        FUN_c070310c(piVar1);
        FUN_c0708070(&local_150);
        piVar1 = &local_120;
LAB_c070b94c:
        FUN_c0708070(piVar1);
      }
      SetLastError(DVar7);
      goto joined_r0xc070b974;
    }
    break;
  case 0x2a0538:
    if ((((param_3 != (uint *)0x0) && (0x3f < param_4)) && (param_5 != (int *)0x0)) &&
       ((int *)0x3 < param_6)) {
      DVar7 = 0xc0000007;
      memcpy(&local_88,param_3,0x40);
      local_180 = (int *)0x0;
      piVar1 = (int *)FUN_c0709ec4(local_88);
      if (piVar1 != (int *)0x0) {
        iVar4 = 8;
        if (local_7c != 0) {
          iVar4 = 4;
        }
        local_d4 = (uint *)0x0;
        local_d8 = (uint *)0x0;
        local_cc = 0;
        FUN_c0709794((int *)&local_d8,local_6c,local_74 * local_70,iVar4,0,0);
        local_ec = 0;
        local_f0 = 0;
        local_e4 = 0;
        FUN_c0709794(&local_f0,local_4c,local_50,4,0,0);
        iVar4 = local_f0;
        if (local_f0 == 0) {
          iVar4 = local_ec;
        }
        puVar2 = local_d8;
        if (local_d8 == (uint *)0x0) {
          puVar2 = local_d4;
        }
        DVar7 = (**(code **)(*piVar1 + 0x18))
                          (piVar1,local_84 & 0xff,local_80,local_7c,local_78,local_74,local_70,
                           puVar2,local_68,local_58,&local_180,local_54,local_50,iVar4);
        FUN_c070310c(piVar1);
        *param_5 = (int)local_180;
        FUN_c0708070(&local_f0);
        ppuVar3 = &local_d8;
        goto LAB_c070b7e4;
      }
      goto LAB_c070b7ec;
    }
  }
LAB_c070bbcc:
  DVar7 = 0xc0000007;
LAB_c070bbd4:
  SetLastError(DVar7);
LAB_c070b5bc:
  FUN_c0712ee4(local_2c);
  return uVar6;
}



/* c070c314 FUN_c070c314 */

/* Boundary evidence: original MIPS .pdata c070c314..c070c333. Semantic name remains unreviewed. */

void FUN_c070c314(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070c334 FUN_c070c334 */

/* Boundary evidence: original MIPS .pdata c070c334..c070c353. Semantic name remains unreviewed. */

void FUN_c070c334(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070c354 FUN_c070c354 */

/* Boundary evidence: original MIPS .pdata c070c354..c070c397. Semantic name remains unreviewed. */

undefined4 * FUN_c070c354(undefined4 *param_1)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  *param_1 = &PTR_LAB_c0701660;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  return param_1;
}



/* c070c398 FUN_c070c398 */

/* Boundary evidence: original MIPS .pdata c070c398..c070c413. Semantic name remains unreviewed. */

void FUN_c070c398(undefined4 *param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
  *param_1 = &PTR_LAB_c0701660;
  EnterCriticalSection(lpCriticalSection);
  while (param_1[6] != 0) {
    uVar1 = ((undefined4 *)param_1[6])[0x19];
    FUN_c0702360((undefined4 *)param_1[6]);
    param_1[6] = uVar1;
  }
  LeaveCriticalSection(lpCriticalSection);
  DeleteCriticalSection(lpCriticalSection);
  return;
}



/* c070c414 FUN_c070c414 */

/* Boundary evidence: original MIPS .pdata c070c414..c070c59f. Semantic name remains unreviewed. */

undefined4 * FUN_c070c414(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if ((param_1[6] != 0) && (param_1[6] == param_2)) {
    *(int *)(param_2 + 0x3c) = param_3;
    *(uint *)(param_2 + 0x80) = (uint)(param_3 != 1);
    if ((param_3 < 0) && (iVar1 = FUN_c0702870(param_2), iVar1 != 0)) {
      *(undefined4 *)(param_2 + 0x3c) = 1;
      uVar2 = *(uint *)(param_2 + 0x10) & 0xff;
      *(undefined4 *)(param_2 + 0x80) = 0;
      if (uVar2 != 0) {
        uVar2 = uVar2 - 1;
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      *(uint *)(param_2 + 0x10) = uVar2 & 0xff | *(uint *)(param_2 + 0x10);
      iVar1 = (**(code **)*param_1)(param_1,param_2);
      if ((iVar1 < 0) || (iVar1 == 2)) {
        puVar3 = FUN_c070c414(param_1,param_2,iVar1);
      }
    }
    else {
      *(int *)(param_2 + 0x3c) = param_3;
      *(undefined4 *)(param_2 + 0x80) = 1;
      iVar1 = *(int *)(param_2 + 0x6c);
      if (*(int *)(param_2 + 0x6c) == 0) {
        iVar1 = param_2;
      }
      FUN_c07026c4(iVar1);
      puVar3 = (undefined4 *)param_1[6];
      iVar1 = puVar3[0x19];
      FUN_c0702360(puVar3);
      param_1[6] = iVar1;
      if (iVar1 == 0) {
        param_1[7] = 0;
      }
      else {
        iVar1 = (**(code **)*param_1)(param_1,iVar1);
        if ((iVar1 < 0) || (iVar1 == 2)) {
          FUN_c070c414(param_1,param_1[6],iVar1);
        }
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return puVar3;
}



/* c070c5a0 FUN_c070c5a0 */

/* Boundary evidence: original MIPS .pdata c070c5a0..c070c69b. Semantic name remains unreviewed. */

undefined4 * FUN_c070c5a0(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  puVar3 = (undefined4 *)param_1[6];
  puVar2 = (undefined4 *)0x0;
  while (puVar1 = puVar3, puVar1 != (undefined4 *)0x0) {
    if (puVar1 == param_2) goto LAB_c070c600;
    puVar2 = puVar1;
    puVar3 = (undefined4 *)puVar1[0x19];
  }
  puVar3 = (undefined4 *)0x0;
  if (param_2 == (undefined4 *)0x0) {
LAB_c070c600:
    puVar3 = puVar1;
    if (puVar2 == (undefined4 *)0x0) {
      (**(code **)(*param_1 + 4))(param_1,param_2);
    }
    else {
      puVar2[0x19] = puVar1[0x19];
      if (puVar1[0x19] == 0) {
        param_1[7] = (int)puVar2;
      }
      puVar1[0xf] = 0xc0000013;
      puVar1[0x20] = 1;
      puVar2 = (undefined4 *)puVar1[0x1b];
      if ((undefined4 *)puVar1[0x1b] == (undefined4 *)0x0) {
        puVar2 = puVar1;
      }
      FUN_c07026c4((int)puVar2);
      puVar1[0x19] = 0;
      FUN_c0702360(puVar1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return puVar3;
}



/* c070c69c FUN_c070c69c */

/* Boundary evidence: original MIPS .pdata c070c69c..c070c763. Semantic name remains unreviewed. */

undefined4 FUN_c070c69c(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 *puVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if (param_1[6] != 0) {
    puVar1 = *(undefined4 **)(param_1[6] + 100);
    while (puVar1 != (undefined4 *)0x0) {
      puVar4 = (undefined4 *)puVar1[0x19];
      puVar1[0xf] = 0xc0000013;
      puVar1[0x20] = 1;
      puVar2 = (undefined4 *)puVar1[0x1b];
      if ((undefined4 *)puVar1[0x1b] == (undefined4 *)0x0) {
        puVar2 = puVar1;
      }
      FUN_c07026c4((int)puVar2);
      FUN_c0702360(puVar1);
      puVar1 = puVar4;
    }
    *(undefined4 *)(param_1[6] + 100) = 0;
    pcVar3 = *(code **)(*param_1 + 4);
    param_1[7] = param_1[6];
    (*pcVar3)(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return 1;
}



/* c070c764 FUN_c070c764 */

/* Boundary evidence: original MIPS .pdata c070c764..c070c81b. Semantic name remains unreviewed. */

undefined4 * FUN_c070c764(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  FUN_c0710df8(param_1,0x10);
  FUN_c070c354(param_1 + 0x11);
  *param_1 = &PTR_FUN_c0701670;
  param_1[0x11] = &PTR_FUN_c0701668;
  param_1[0x1f] = param_3;
  param_1[0x20] = param_2;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2d));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3a));
  puVar1 = param_1 + 0x32;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x3a);
  param_1[0x21] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x22] = 0;
  return param_1;
}



/* c070c83c FUN_c070c83c */

/* Boundary evidence: original MIPS .pdata c070c83c..c070c8d3. Semantic name remains unreviewed. */

bool FUN_c070c83c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *_Dst;
  
  _Dst = (void *)(param_1 + 0x68);
  if (param_1 == 0) {
    _Dst = (void *)0x0;
  }
  memset(_Dst,0,0x14);
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0xac) = 1;
  *(undefined2 *)(param_1 + 0xb0) = 0;
  FUN_c070945c(L"ThreadPriority",100);
  iVar1 = FUN_c0710b54(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 100) = 1;
    uVar2 = FUN_c070945c(L"Threshold",0x800);
    *(undefined4 *)(param_1 + 0x104) = uVar2;
  }
  return iVar1 != 0;
}



/* c070c8d4 FUN_c070c8d4 */

/* Boundary evidence: original MIPS .pdata c070c8d4..c070ca37. Semantic name remains unreviewed. */

int FUN_c070c8d4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = -0x3ffffffd;
  EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x38) + 0x2c));
  if (*(int *)(param_1 + 0x20) != 0) {
    iVar1 = FUN_c0708114(param_1 + -0x44);
    if ((((-1 < iVar1) && (iVar1 = *(int *)(param_1 + 0x38), *(int *)(iVar1 + 100) != 0)) &&
        (*(int *)(param_1 + 0xb8) == 0)) && (param_2 != 0)) {
      iVar3 = iVar1 + 8;
      *(int *)(param_1 + 0xb8) = param_2;
      *(undefined4 *)(param_1 + 0xbc) = 0;
      if (iVar1 == 0) {
        iVar3 = 0;
      }
      iVar3 = (**(code **)(iVar1 + 0x40))(iVar3,*(undefined4 *)(param_1 + 0x3c),param_2 + 4);
      while (((iVar3 < 0 && (iVar1 = FUN_c0708114(param_1 + -0x44), -1 < iVar1)) &&
             (iVar1 = FUN_c0702870(param_2), iVar1 != 0))) {
        uVar2 = *(uint *)(param_2 + 0x10) & 0xff;
        if (uVar2 != 0) {
          uVar2 = uVar2 - 1;
        }
        *(undefined1 *)(param_2 + 0x10) = 0;
        *(uint *)(param_2 + 0x10) = uVar2 & 0xff | *(uint *)(param_2 + 0x10);
        iVar1 = *(int *)(param_1 + 0x38);
        iVar3 = iVar1 + 8;
        if (iVar1 == 0) {
          iVar3 = 0;
        }
        iVar3 = (**(code **)(iVar1 + 0x40))(iVar3,*(undefined4 *)(param_1 + 0x3c),param_2 + 4);
      }
      if (iVar3 != 1) {
        *(undefined4 *)(param_1 + 0xb8) = 0;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x38) + 0x2c));
  return iVar3;
}



/* c070ca38 FUN_c070ca38 */

/* Boundary evidence: original MIPS .pdata c070ca38..c070caa7. Semantic name remains unreviewed. */

int FUN_c070ca38(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  piVar1 = (int *)(param_1 + 200);
  iVar2 = 8;
  do {
    if (*piVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = iVar2 + -1;
    piVar1 = piVar1 + 1;
  } while (iVar2 != 0);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  return iVar3;
}



/* c070caa8 FUN_c070caa8 */

/* Boundary evidence: original MIPS .pdata c070caa8..c070cb3b. Semantic name remains unreviewed. */

int * FUN_c070caa8(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  piVar2 = (int *)0x0;
  if (param_2 < 8) {
    puVar1 = (undefined4 *)((param_2 + 0x32) * 4 + param_1);
    piVar2 = (int *)*puVar1;
    *puVar1 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2);
    FUN_c070310c(piVar2);
  }
  return piVar2;
}



/* c070cb3c FUN_c070cb3c */

/* Boundary evidence: original MIPS .pdata c070cb3c..c070cbd7. Semantic name remains unreviewed. */

int FUN_c070cb3c(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_3 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
    if ((param_2 < 8) && (piVar1 = (int *)((param_2 + 0x32) * 4 + param_1), *piVar1 == 0)) {
      *piVar1 = param_3;
      InterlockedIncrement((LONG *)(param_3 + 4));
      iVar2 = param_3;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  }
  return iVar2;
}



/* c070cbd8 FUN_c070cbd8 */

/* Boundary evidence: original MIPS .pdata c070cbd8..c070cc37. Semantic name remains unreviewed. */

undefined4 FUN_c070cbd8(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 7;
  piVar2 = (int *)(param_1 + 0xe4);
  do {
    if (*piVar2 != 0) {
      FUN_c070caa8(param_1,uVar1);
    }
    uVar1 = uVar1 - 1;
    piVar2 = piVar2 + -1;
  } while (-1 < (int)uVar1);
  return 1;
}



/* c070cc38 FUN_c070cc38 */

/* Boundary evidence: original MIPS .pdata c070cc38..c070cc93. Semantic name remains unreviewed. */

bool FUN_c070cc38(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 + 0x68;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  iVar3 = *(int *)(param_1 + 0x7c);
  iVar1 = iVar3 + 8;
  if (iVar3 == 0) {
    iVar1 = 0;
  }
  iVar2 = (**(code **)(iVar3 + 0x44))(iVar1,*(undefined4 *)(param_1 + 0x80),0xb,iVar2,0x14);
  return -1 < iVar2;
}



/* c070cc94 FUN_c070cc94 */

/* Boundary evidence: original MIPS .pdata c070cc94..c070ccb7. Semantic name remains unreviewed. */

void FUN_c070cc94(int *param_1)

{
  (**(code **)(*param_1 + 0x28))();
  return;
}



/* c070ccb8 FUN_c070ccb8 */

/* Boundary evidence: original MIPS .pdata c070ccb8..c070ce83. Semantic name remains unreviewed. */

undefined4 FUN_c070ccb8(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  byte local_28 [8];
  
  if ((*(uint *)(param_1 + 0x88) & 1) != 0) {
    piVar1 = (int *)FUN_c07031cc(param_1,0);
    local_28[0] = 0;
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,0,5,0,local_28,1);
      if (-1 < iVar2) {
        local_28[0] = local_28[0] & 0xfe;
        while (local_28[0] != 0) {
          bVar6 = (local_28[0] - 1 ^ local_28[0]) & local_28[0];
          if (bVar6 == 2) {
LAB_c070cde0:
            uVar4 = 1;
          }
          else if (bVar6 == 4) {
            uVar4 = 2;
          }
          else if (bVar6 == 8) {
            uVar4 = 3;
          }
          else if (bVar6 == 0x10) {
            uVar4 = 4;
          }
          else if (bVar6 == 0x20) {
            uVar4 = 5;
          }
          else if (bVar6 == 0x40) {
            uVar4 = 6;
          }
          else {
            if (bVar6 != 0x80) goto LAB_c070cde0;
            uVar4 = 7;
          }
          local_28[0] = ~bVar6 & local_28[0];
          piVar3 = (int *)FUN_c07031cc(param_1,uVar4);
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 0x2c))(piVar3);
            FUN_c070310c(piVar3);
          }
        }
      }
      FUN_c070310c(piVar1);
    }
  }
  iVar5 = *(int *)(param_1 + 0x7c);
  iVar2 = iVar5 + 8;
  if (iVar5 == 0) {
    iVar2 = 0;
  }
  (**(code **)(iVar5 + 0x44))(iVar2,*(undefined4 *)(param_1 + 0x80),4,0,0);
  return 1;
}



/* c070ce84 FUN_c070ce84 */

/* Boundary evidence: original MIPS .pdata c070ce84..c070cf9b. Semantic name remains unreviewed. */

int FUN_c070ce84(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  if (((param_2[0x123] == 3) || (param_2[0x123] == 4)) && (1 < param_3)) {
    uVar3 = 1;
    do {
      iVar1 = (**(code **)(*param_1 + 0x34))(param_1,3,uVar3,param_2);
      if (iVar1 < 0) {
        return iVar1;
      }
      piVar2 = (int *)FUN_c07031cc((int)param_1,uVar3);
      if (piVar2 == (int *)0x0) {
        iVar1 = -0x3ffffffd;
      }
      else {
        iVar1 = FUN_c07064f0(piVar2,param_2);
        if (-1 < iVar1) {
          FUN_c07042e8(piVar2);
        }
        FUN_c070310c(piVar2);
      }
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < param_3);
  }
  return 0;
}



/* c070cf9c FUN_c070cf9c */

/* Boundary evidence: original MIPS .pdata c070cf9c..c070d0d3. Semantic name remains unreviewed. */

undefined4 FUN_c070cf9c(int param_1,int param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = operator_new(0x768);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c0705990(puVar1,param_3,param_1);
  }
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 4))(piVar2);
    if ((iVar3 != 0) && (iVar3 = FUN_c070cb3c(param_1,param_3,(int)piVar2), iVar3 != 0)) {
      piVar2 = (int *)FUN_c07031cc(param_1,param_3);
      if (piVar2 == (int *)0x0) {
        return 0xc0000007;
      }
      if (*(int *)(*(int *)(param_1 + 0x7c) + 100) != 0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        FUN_c07046d8((int)piVar2,param_4);
        piVar2[0x123] = param_2;
      }
      FUN_c070310c(piVar2);
      return 0;
    }
    (**(code **)*piVar2)(piVar2,1);
  }
  return 0xc000000e;
}



/* c070d0d4 FUN_c070d0d4 */

/* Boundary evidence: original MIPS .pdata c070d0d4..c070d183. Semantic name remains unreviewed. */

undefined4 FUN_c070d0d4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x38) + 0x2c));
  iVar3 = *(int *)(param_1 + 0x38);
  if ((((*(int *)(iVar3 + 100) != 0) && (*(int *)(param_1 + 0xb8) != 0)) &&
      (*(int *)(param_1 + 0xbc) == 0)) && (param_2 == *(int *)(param_1 + 0xb8))) {
    iVar2 = param_2 + 4;
    if (param_2 == 0) {
      iVar2 = 0;
    }
    iVar1 = iVar3 + 8;
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    uVar4 = (**(code **)(iVar3 + 0x48))(iVar1,*(undefined4 *)(param_1 + 0x3c),iVar2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x38) + 0x2c));
  return uVar4;
}



/* c070d184 FUN_c070d184 */

/* Boundary evidence: original MIPS .pdata c070d184..c070d213. Semantic name remains unreviewed. */

undefined4 FUN_c070d184(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x7c) + 0x2c));
  if ((*(int *)(param_1 + 0xfc) != 0) && (param_2 == *(int *)(param_1 + 0xfc))) {
    *(undefined4 *)(param_1 + 0xfc) = 0;
    *(undefined4 *)(param_1 + 0x100) = 0;
    FUN_c070c414((undefined4 *)(param_1 + 0x44),param_2,param_3);
    uVar1 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x7c) + 0x2c));
  return uVar1;
}



/* c070d214 FUN_c070d214 */

/* Boundary evidence: original MIPS .pdata c070d214..c070d277. Semantic name remains unreviewed. */

int FUN_c070d214(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x7c) + 0x2c));
  iVar1 = 0;
  if (*(int *)(param_1 + 0xfc) != 0) {
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
    iVar1 = *(int *)(param_1 + 0xfc);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x7c) + 0x2c));
  return iVar1;
}



/* c070d278 FUN_c070d278 */

/* Boundary evidence: original MIPS .pdata c070d278..c070d2e7. Semantic name remains unreviewed. */

void FUN_c070d278(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x7c) + 0x2c));
  if (((*(int *)(param_1 + 0xfc) != 0) && (*(int *)(param_1 + 0xfc) + 4 == param_2)) &&
     (*(int *)(param_1 + 0x100) != 0)) {
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + -1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x7c) + 0x2c));
  return;
}



/* c070d2e8 FUN_c070d2e8 */

/* Boundary evidence: original MIPS .pdata c070d2e8..c070d377. Semantic name remains unreviewed. */

void FUN_c070d2e8(int *param_1,int param_2)

{
  code *pcVar1;
  
  if (param_2 == 1) {
    pcVar1 = *(code **)(*param_1 + 0x28);
  }
  else if (param_2 == 2) {
    pcVar1 = *(code **)(*param_1 + 0x24);
  }
  else {
    if (param_2 != 3) {
      if (param_2 < 5) {
        return;
      }
      if (7 < param_2) {
        return;
      }
      (**(code **)(*param_1 + 0x30))();
      return;
    }
    pcVar1 = *(code **)(*param_1 + 0x2c);
  }
  (*pcVar1)();
  return;
}



/* c070d378 FUN_c070d378 */

/* Boundary evidence: original MIPS .pdata c070d378..c070d3bf. Semantic name remains unreviewed. */

void FUN_c070d378(int param_1,int param_2)

{
  if ((0 < param_2) && ((param_2 < 4 || ((4 < param_2 && (param_2 < 8)))))) {
    FUN_c0710bc8(param_1,param_2,0xffffffff);
  }
  return;
}



/* c070d3c0 FUN_c070d3c0 */

/* Boundary evidence: original MIPS .pdata c070d3c0..c070d3f3. Semantic name remains unreviewed. */

void FUN_c070d3c0(int param_1)

{
  DWORD dwMilliseconds;
  
  dwMilliseconds = *(DWORD *)(param_1 + 0x78);
  if (dwMilliseconds == 0) {
    dwMilliseconds = 500;
  }
  Sleep(dwMilliseconds);
  return;
}



/* c070d3f4 FUN_c070d3f4 */

uint FUN_c070d3f4(int param_1,uint param_2)

{
  uint uVar1;
  
  if ((*(uint *)(param_1 + 0x6c) & param_2) != 0) {
    if ((*(uint *)(param_1 + 0x70) & param_2) != 0) {
      return *(uint *)(param_1 + 0x70);
    }
    uVar1 = 0;
    do {
      if ((1 << (uVar1 & 0x1f) & *(uint *)(param_1 + 0x6c) & param_2) != 0) {
        return 1 << (uVar1 & 0x1f);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x20);
  }
  return 0;
}



/* c070d454 FUN_c070d454 */

/* Boundary evidence: original MIPS .pdata c070d454..c070d4fb. Semantic name remains unreviewed. */

undefined4 FUN_c070d454(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 0x84) == 2) &&
     (piVar1 = (int *)FUN_c07031cc(param_1,0), piVar1 != (int *)0x0)) {
    if (param_2 == 5) {
      uVar3 = 10;
    }
    else if (param_2 == 6) {
      uVar3 = 9;
    }
    else {
      if (param_2 != 7) {
        return 0;
      }
      uVar3 = 0xb;
    }
    iVar2 = FUN_c07104e8(piVar1,uVar3,(uint *)0x0,0);
    FUN_c070310c(piVar1);
    if (-1 < iVar2) {
      return 1;
    }
  }
  return 0;
}



/* c070d4fc FUN_c070d4fc */

/* Boundary evidence: original MIPS .pdata c070d4fc..c070d5e7. Semantic name remains unreviewed. */

undefined4 FUN_c070d4fc(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *_Dst;
  
  _Dst = (uint *)(param_1 + 0x8c);
  memset(_Dst,0,0x20);
  *_Dst = *_Dst | 1;
  *(undefined4 *)(param_1 + 0x90) = 25000000;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  piVar1 = (int *)(param_1 + 200);
  iVar4 = 8;
  do {
    iVar3 = *piVar1;
    if (iVar3 != 0) {
      uVar2 = (*(uint *)(iVar3 + 0x738) ^ *_Dst) & 1 ^ *_Dst;
      *_Dst = uVar2;
      *_Dst = (*(uint *)(iVar3 + 0x738) ^ uVar2) & 0x40000000 ^ uVar2;
      uVar2 = *(uint *)(iVar3 + 0x73c);
      *(uint *)(param_1 + 0x90) = uVar2;
      if (*(uint *)(iVar3 + 0x73c) < uVar2) {
        *(uint *)(param_1 + 0x90) = *(uint *)(iVar3 + 0x73c);
      }
    }
    iVar4 = iVar4 + -1;
    piVar1 = piVar1 + 1;
  } while (iVar4 != 0);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  return 0;
}



/* c070d5e8 FUN_c070d5e8 */

/* Boundary evidence: original MIPS .pdata c070d5e8..c070d683. Semantic name remains unreviewed. */

undefined4 FUN_c070d5e8(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  if ((*(uint *)(param_1 + 0x88) & 1) == 0) {
    iVar2 = *(int *)(param_1 + 0x7c);
    iVar1 = iVar2 + 8;
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    iVar1 = (**(code **)(iVar2 + 0x44))(iVar1,*(undefined4 *)(param_1 + 0x80),2,0,0);
    if (-1 < iVar1) {
      *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 1;
      uVar3 = 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  return uVar3;
}



/* c070d684 FUN_c070d684 */

/* Boundary evidence: original MIPS .pdata c070d684..c070d727. Semantic name remains unreviewed. */

undefined4 FUN_c070d684(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  if ((*(uint *)(param_1 + 0x88) & 1) != 0) {
    iVar2 = *(int *)(param_1 + 0x7c);
    iVar1 = iVar2 + 8;
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    iVar1 = (**(code **)(iVar2 + 0x44))(iVar1,*(undefined4 *)(param_1 + 0x80),3,0,0);
    if (-1 < iVar1) {
      uVar3 = 1;
      *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xfffffffe;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  return uVar3;
}



/* c070d728 FUN_c070d728 */

/* Boundary evidence: original MIPS .pdata c070d728..c070d98b. Semantic name remains unreviewed. */

undefined4 FUN_c070d728(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint local_40;
  undefined4 local_3c;
  
  iVar4 = 0;
  if ((param_2 == 7) || (param_2 == 5)) {
    uVar3 = 0;
    do {
      if (iVar4 < 0) {
        return 0;
      }
      piVar1 = (int *)FUN_c07031cc(param_1,uVar3);
      if (piVar1 != (int *)0x0) {
        iVar4 = FUN_c0705ed4(piVar1,param_2,0);
        if (-1 < iVar4) {
          FUN_c070470c((int)piVar1,3);
        }
        FUN_c070310c(piVar1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 9);
    if (iVar4 < 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x84) = 5;
    *(undefined2 *)(param_1 + 0xb0) = 0;
  }
  if ((param_2 != 7) && (param_2 != 6)) {
    return 1;
  }
  puVar5 = (uint *)(param_1 + 0x8c);
  local_40 = *puVar5;
  local_3c = *(undefined4 *)(param_1 + 0x90);
  *puVar5 = local_40 & 0xfffffffe;
  *(undefined4 *)(param_1 + 0x90) = 100000;
  iVar4 = FUN_c070846c(*(int *)(param_1 + 0x7c),*(uint *)(param_1 + 0x80),puVar5);
  *(undefined4 *)(param_1 + 0x84) = 6;
  uVar3 = 0;
  do {
    if (iVar4 < 0) {
      return 0;
    }
    piVar1 = (int *)FUN_c07031cc(param_1,uVar3);
    if (piVar1 != (int *)0x0) {
      iVar4 = FUN_c0705ed4(piVar1,param_2,1);
      FUN_c070310c(piVar1);
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 9);
  if (-1 < iVar4) {
    *(undefined4 *)(param_1 + 0x84) = 2;
    uVar3 = 0;
    *puVar5 = local_40;
    *(undefined4 *)(param_1 + 0x90) = local_3c;
    do {
      if (iVar4 < 0) break;
      piVar1 = (int *)FUN_c07031cc(param_1,uVar3);
      if (piVar1 != (int *)0x0) {
        iVar4 = FUN_c0707794(piVar1,&local_40);
        FUN_c070310c(piVar1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 8);
    iVar4 = FUN_c070846c(*(int *)(param_1 + 0x7c),*(uint *)(param_1 + 0x80),puVar5);
    uVar3 = 0;
    while (-1 < iVar4) {
      puVar2 = (undefined4 *)FUN_c07031cc(param_1,uVar3);
      if (puVar2 != (undefined4 *)0x0) {
        FUN_c070470c((int)puVar2,2);
        FUN_c070310c(puVar2);
      }
      uVar3 = uVar3 + 1;
      if (7 < uVar3) {
        return 1;
      }
    }
  }
  return 0;
}



/* c070d98c FUN_c070d98c */

/* Boundary evidence: original MIPS .pdata c070d98c..c070da4b. Semantic name remains unreviewed. */

undefined4 FUN_c070d98c(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  param_1[8] = 0;
  FUN_c070c69c(param_1);
  if (param_1[6] != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    puVar1 = (undefined4 *)param_1[6];
    while (puVar1 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)puVar1[0x19];
      puVar1[0x19] = 0;
      puVar1[0xf] = 0xc0000013;
      puVar1[0x20] = 1;
      puVar2 = (undefined4 *)puVar1[0x1b];
      if ((undefined4 *)puVar1[0x1b] == (undefined4 *)0x0) {
        puVar2 = puVar1;
      }
      FUN_c07026c4((int)puVar2);
      FUN_c0702360(puVar1);
      puVar1 = puVar3;
    }
    param_1[6] = 0;
    param_1[7] = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  }
  return 1;
}



/* c070da4c FUN_c070da4c */

/* Boundary evidence: original MIPS .pdata c070da4c..c070dbaf. Semantic name remains unreviewed. */

int FUN_c070da4c(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = -0x3ffffffd;
  if ((param_2 != (undefined4 *)0x0) && (param_1[8] != 0)) {
    bVar1 = false;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    param_2[0x19] = 0;
    if ((param_1[6] == 0) || (param_1[7] == 0)) {
      param_1[6] = param_2;
      bVar1 = true;
    }
    else {
      *(undefined4 **)(param_1[7] + 100) = param_2;
    }
    param_1[7] = param_2;
    InterlockedIncrement(param_2 + 0x1f);
    uVar2 = param_2[4];
    if (bVar1) {
      iVar4 = (**(code **)*param_1)(param_1,param_2);
      if ((iVar4 < 0) || (iVar4 == 2)) {
        if ((uVar2 & 0x80000000) == 0) {
          FUN_c070c414(param_1,(int)param_2,0);
        }
        else {
          iVar3 = param_2[0x19];
          param_1[6] = iVar3;
          if (iVar3 == 0) {
            param_1[7] = 0;
          }
          param_2[0xf] = iVar4;
          param_2[0x20] = (uint)(iVar4 != 1);
          FUN_c0702360(param_2);
        }
      }
    }
    else {
      param_2[4] = uVar2 & 0x7fffffff;
      iVar4 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  }
  return iVar4;
}



/* c070dbb0 FUN_c070dbb0 */

/* Boundary evidence: original MIPS .pdata c070dbb0..c070dc1b. Semantic name remains unreviewed. */

void FUN_c070dbb0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0701670;
  param_1[0x11] = &PTR_FUN_c0701668;
  FUN_c070cbd8((int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3a));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2d));
  FUN_c070c398(param_1 + 0x11);
  FUN_c0710ed4(param_1);
  return;
}



/* c070dc1c FUN_c070dc1c */

/* Boundary evidence: original MIPS .pdata c070dc1c..c070dfa7. Semantic name remains unreviewed. */

undefined4 FUN_c070dc1c(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  DWORD dwMilliseconds;
  int iVar5;
  uint uVar6;
  uint *_Dst;
  uint local_48 [2];
  uint local_40;
  int local_3c;
  
  param_1[0x19] = 1;
  puVar1 = operator_new(0x768);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c0705990(puVar1,0,param_1);
  }
  if (piVar2 == (int *)0x0) {
    return 1;
  }
  iVar3 = (**(code **)(*piVar2 + 4))(piVar2);
  if ((iVar3 == 0) || (iVar3 = FUN_c070cb3c((int)param_1,0,(int)piVar2), iVar3 == 0)) {
    (**(code **)*piVar2)(piVar2,1);
    return 1;
  }
  piVar2 = (int *)FUN_c07031cc((int)param_1,0);
  if (piVar2 == (int *)0x0) {
    return 1;
  }
  (**(code **)(*piVar2 + 8))(piVar2);
  dwMilliseconds = param_1[0x1e];
  param_1[0x21] = 1;
  if (dwMilliseconds == 0) {
    dwMilliseconds = 500;
  }
  Sleep(dwMilliseconds);
  _Dst = (uint *)(param_1 + 0x23);
  memset(_Dst,0,0x20);
  param_1[0x24] = 100000;
  local_48[0] = 0;
  iVar3 = FUN_c070846c(param_1[0x1f],param_1[0x20],_Dst);
  if ((iVar3 < 0) || (iVar3 = FUN_c07073b8(piVar2,(int *)local_48), iVar3 < 0)) goto LAB_c070df58;
  *(undefined2 *)(param_1 + 0x2c) = 0;
  iVar3 = FUN_c0705a9c(piVar2);
  if ((iVar3 < 0) ||
     (((iVar3 = FUN_c070352c(piVar2), iVar3 < 0 || (iVar3 = FUN_c07064f0(piVar2,piVar2), iVar3 < 0))
      || (iVar3 = FUN_c070ce84(param_1,piVar2,local_48[0]), iVar3 < 0)))) goto LAB_c070df58;
  iVar3 = 0;
  uVar6 = 0;
  if (local_48[0] == 0) {
LAB_c070ddf8:
    iVar3 = FUN_c070d4fc((int)param_1);
  }
  else {
    do {
      if (iVar3 < 0) goto LAB_c070de08;
      piVar4 = (int *)FUN_c07031cc((int)param_1,uVar6);
      if (piVar4 != (int *)0x0) {
        iVar3 = FUN_c0707c44(piVar4);
        FUN_c070310c(piVar4);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < local_48[0]);
    if (-1 < iVar3) goto LAB_c070ddf8;
  }
LAB_c070de08:
  uVar6 = 0;
  if (local_48[0] != 0) {
    do {
      if (iVar3 < 0) break;
      piVar4 = (int *)FUN_c07031cc((int)param_1,uVar6);
      if (piVar4 != (int *)0x0) {
        iVar3 = FUN_c0707794(piVar4,_Dst);
        FUN_c070310c(piVar4);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < local_48[0]);
  }
  iVar3 = FUN_c070846c(param_1[0x1f],param_1[0x20],_Dst);
  iVar5 = piVar2[0x123];
  if (iVar5 == 3) {
    piVar2[0x123] = 0;
  }
  else if (iVar5 == 4) {
    piVar2[0x123] = 2;
  }
  else if ((iVar5 == 1) && ((param_1[0x1a] & 0x10U) != 0)) {
    uVar6 = *_Dst | 2;
    local_3c = param_1[0x24];
    local_40 = (uVar6 ^ local_40) & 0x3ffffffc ^ uVar6;
    *_Dst = uVar6;
    FUN_c07104e8(piVar2,0x12,&local_40,0x20);
  }
  if (-1 < iVar3) {
    param_1[0x21] = 4;
    uVar6 = 0;
    if (local_48[0] != 0) {
      do {
        piVar4 = (int *)FUN_c07031cc((int)param_1,uVar6);
        if ((piVar4 != (int *)0x0) && (piVar4[0x123] != 0)) {
          FUN_c0703d4c(piVar4);
          FUN_c070310c(piVar4);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < local_48[0]);
    }
  }
LAB_c070df58:
  FUN_c070310c(piVar2);
  return 1;
}



/* c070dfa8 FUN_c070dfa8 */

/* Boundary evidence: original MIPS .pdata c070dfa8..c070dfdb. Semantic name remains unreviewed. */

undefined4 FUN_c070dfa8(int param_1)

{
  FUN_c070d98c((int *)(param_1 + 0x44));
  FUN_c070cbd8(param_1);
  return 1;
}



/* c070dfdc FUN_c070dfdc */

/* Boundary evidence: original MIPS .pdata c070dfdc..c070e027. Semantic name remains unreviewed. */

undefined4 * FUN_c070dfdc(undefined4 *param_1,uint param_2)

{
  FUN_c070dbb0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c070e028 SDC_Init */

/* Boundary evidence: original MIPS .pdata c070e028..c070e043. Semantic name remains unreviewed. */

void SDC_Init(int param_1)

{
                    /* 0xe028  4  SDC_Init */
  FUN_c070a070(param_1);
  return;
}



/* c070e044 SDC_Close */

undefined4 SDC_Close(void)

{
                    /* 0xe044  1  SDC_Close
                       0xe044  6  SDC_PreDeinit */
  return 1;
}



/* c070e04c SDC_Deinit */

/* Boundary evidence: original MIPS .pdata c070e04c..c070e06b. Semantic name remains unreviewed. */

undefined4 SDC_Deinit(int *param_1)

{
                    /* 0xe04c  2  SDC_Deinit */
  FUN_c070940c(param_1);
  return 1;
}



/* c070e06c SDC_Open */

undefined * SDC_Open(undefined4 param_1,uint param_2)

{
  undefined *puVar1;
  
                    /* 0xe06c  5  SDC_Open */
  puVar1 = (undefined *)0x0;
  if (DAT_c0714150 != 0) {
    if ((param_2 & 0x100) == 0) {
      puVar1 = &DAT_c0714154;
    }
    else {
      puVar1 = &DAT_c071413c;
    }
  }
  return puVar1;
}



/* c070e0a4 SDC_IOControl */

/* Boundary evidence: original MIPS .pdata c070e0a4..c070e147. Semantic name remains unreviewed. */

undefined4 SDC_IOControl(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0xe0a4  3  SDC_IOControl */
  if ((DAT_c0714150 == (int *)0x0) || (param_1 == (int *)0x0)) {
    SetLastError(0x57);
    uVar1 = 0;
  }
  else if (*param_1 == 0) {
    uVar1 = (**(code **)(*DAT_c0714150 + 0x5c))(DAT_c0714150);
  }
  else {
    uVar1 = (**(code **)(*DAT_c0714150 + 0x3c))();
  }
  return uVar1;
}



/* c070e148 SDHCDGetHCFunctions */

undefined4 SDHCDGetHCFunctions(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0xe148  8  SDHCDGetHCFunctions */
  uVar1 = 0xc0000007;
  if ((param_1 != (int *)0x0) && (*param_1 == 0x28)) {
    param_1[1] = (int)FUN_c070a114;
    param_1[2] = (int)FUN_c070a2f8;
    param_1[3] = (int)FUN_c070a1d0;
    param_1[4] = (int)FUN_c070a268;
    param_1[5] = (int)FUN_c070a358;
    param_1[6] = (int)FUN_c070a50c;
    uVar1 = 0;
    param_1[7] = (int)FUN_c070a7b4;
    param_1[8] = (int)FUN_c070a670;
    param_1[9] = (int)FUN_c070a420;
  }
  return uVar1;
}



/* c070e1dc FUN_c070e1dc */

/* Boundary evidence: original MIPS .pdata c070e1dc..c070e20f. Semantic name remains unreviewed. */

undefined4 FUN_c070e1dc(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c070e210 FUN_c070e210 */

undefined4 FUN_c070e210(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x48c);
  uVar1 = 1;
  if ((((iVar2 != 2) && (iVar2 != 1)) && (iVar2 != 4)) || ((*(byte *)(param_1 + 0x49d) & 0x40) == 0)
     ) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c070e250 FUN_c070e250 */

/* Boundary evidence: original MIPS .pdata c070e250..c070e373. Semantic name remains unreviewed. */

undefined4 FUN_c070e250(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x48c) != 3) && (*(int *)(param_1 + 0x48c) != 4)) {
    return 0xc0000007;
  }
  if (param_5 == 0) {
    iVar3 = *(int *)(param_1 + 0x6d4);
  }
  else {
    if (*(int *)(param_1 + 0x434) != 0) {
      piVar1 = (int *)FUN_c07031cc(*(int *)(param_1 + 0x430),0);
      if (piVar1 == (int *)0x0) {
        return 0xc0000007;
      }
      uVar2 = FUN_c070e250((int)piVar1,param_2,param_3,param_4,param_5);
      goto LAB_c070e340;
    }
    iVar3 = *(int *)(*(int *)(param_1 + 0x6e4) + 4);
  }
  if (param_3 == 0) {
    return 0xc0000007;
  }
  piVar1 = (int *)FUN_c07031cc(*(int *)(param_1 + 0x430),0);
  if (piVar1 == (int *)0x0) {
    return 0xc0000007;
  }
  uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,0,iVar3 + param_2,0,param_3,param_4);
LAB_c070e340:
  FUN_c070310c(piVar1);
  return uVar2;
}



/* c070e374 FUN_c070e374 */

/* Boundary evidence: original MIPS .pdata c070e374..c070e52f. Semantic name remains unreviewed. */

int FUN_c070e374(int *param_1)

{
  int iVar1;
  uint local_120 [2];
  char local_118 [14];
  byte local_10a;
  byte local_109;
  byte local_108;
  undefined2 local_fe;
  undefined2 local_fc;
  undefined1 local_fa;
  undefined1 local_f9;
  undefined1 local_f8;
  undefined1 local_f7;
  undefined1 local_f6;
  undefined1 local_f5;
  undefined1 local_f4;
  undefined1 local_f3;
  uint local_18;
  
  local_18 = DAT_c0714140;
  local_120[0] = 0;
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1,0x22,0,local_120,0);
  if (iVar1 < 0) {
LAB_c070e3c4:
    FUN_c0712ee4(local_18);
  }
  else {
    if ((local_120[0] != 0) && (0x17 < local_120[0])) {
      iVar1 = (**(code **)(*param_1 + 0x30))(param_1,0x22,local_118,local_120,0);
      if (iVar1 < 0) goto LAB_c070e3c4;
      if (local_118[0] == '\x01') {
        *(ushort *)((int)param_1 + 0x70a) = (ushort)local_10a;
        *(ushort *)(param_1 + 0x1c3) = (ushort)local_109;
        *(ushort *)((int)param_1 + 0x70e) = (ushort)local_108;
        if (local_120[0] < 0x26) {
          *(undefined2 *)(param_1 + 0x1c4) = 0;
          *(undefined2 *)((int)param_1 + 0x712) = 0;
          *(undefined2 *)(param_1 + 0x1c5) = 0;
          *(undefined2 *)((int)param_1 + 0x716) = 0;
          *(undefined2 *)(param_1 + 0x1c6) = 0;
          *(undefined2 *)((int)param_1 + 0x71a) = 0;
        }
        else {
          *(undefined2 *)(param_1 + 0x1c4) = local_fe;
          *(undefined2 *)((int)param_1 + 0x712) = local_fc;
          *(ushort *)(param_1 + 0x1c5) = CONCAT11(local_f9,local_fa);
          *(ushort *)((int)param_1 + 0x716) = CONCAT11(local_f7,local_f8);
          *(ushort *)(param_1 + 0x1c6) = CONCAT11(local_f5,local_f6);
          *(ushort *)((int)param_1 + 0x71a) = CONCAT11(local_f3,local_f4);
        }
        FUN_c0712ee4(local_18);
        return 0;
      }
    }
    FUN_c0712ee4(local_18);
    iVar1 = -0x3fffffe9;
  }
  return iVar1;
}



/* c070e530 FUN_c070e530 */

/* Boundary evidence: original MIPS .pdata c070e530..c070e777. Semantic name remains unreviewed. */

int FUN_c070e530(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte local_18 [8];
  
  if (((*(int *)(param_1 + 0x434) == 0) || (param_2 == (int *)0x0)) ||
     (piVar1 = (int *)FUN_c07031cc(*(int *)(param_1 + 0x430),0), piVar1 == (int *)0x0)) {
    return -0x3ffffff9;
  }
  *param_2 = *(int *)(piVar1[0x1b9] + 0x14);
  param_2[1] = *(int *)(piVar1[0x1b9] + 0x18);
  param_2[2] = (uint)(((uint)*(byte *)(piVar1[0x1b9] + 0x11) &
                      1 << (*(uint *)(param_1 + 0x434) & 0x1f)) != 0);
  iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,0,*(int *)(param_1 + 0x434) * 0x100 + 2,0,local_18,1)
  ;
  if (iVar2 < 0) {
    return iVar2;
  }
  uVar3 = (uint)((local_18[0] & 1) != 0);
  param_2[3] = uVar3;
  if (uVar3 == 0) {
    param_2[4] = 0;
  }
  else {
    param_2[4] = (uint)((local_18[0] & 2) != 0);
  }
  param_2[5] = *(int *)(param_1 + 0x6c8);
  if (*param_2 == 0) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x70e);
    if ((uVar3 == 0) || (200 < uVar3)) {
      uVar3 = 200;
    }
    if (param_2[2] != 0) {
      *(short *)(param_2 + 6) = (short)uVar3;
      param_2[7] = -uVar3;
      goto LAB_c070e74c;
    }
    *(undefined2 *)(param_2 + 6) = 0;
  }
  else {
    if (param_2[2] != 0) {
      if ((param_2[1] != 0) && (uVar3 != 0)) {
        if (param_2[4] == 0) {
          *(undefined2 *)(param_2 + 6) = *(undefined2 *)(param_1 + 0x716);
          param_2[7] = -(uint)*(ushort *)(param_1 + 0x716);
          iVar2 = (uint)*(ushort *)(param_1 + 0x71a) - (uint)*(ushort *)(param_1 + 0x716);
        }
        else {
          *(undefined2 *)(param_2 + 6) = *(undefined2 *)(param_1 + 0x71a);
          param_2[7] = -(uint)*(ushort *)(param_1 + 0x71a);
          iVar2 = (uint)*(ushort *)(param_1 + 0x716) - (uint)*(ushort *)(param_1 + 0x71a);
        }
        param_2[8] = iVar2;
        return 0;
      }
      *(undefined2 *)(param_2 + 6) = *(undefined2 *)(param_1 + 0x712);
      param_2[7] = -(uint)*(ushort *)(param_1 + 0x712);
      goto LAB_c070e74c;
    }
    if ((param_2[1] == 0) || (uVar3 == 0)) {
      *(undefined2 *)(param_2 + 6) = 0;
      param_2[7] = (uint)*(ushort *)(param_1 + 0x712);
      return 0;
    }
    *(undefined2 *)(param_2 + 6) = 0;
    if (param_2[4] == 0) {
      param_2[7] = (uint)*(ushort *)(param_1 + 0x716);
      goto LAB_c070e74c;
    }
    uVar3 = (uint)*(ushort *)(param_1 + 0x71a);
  }
  param_2[7] = uVar3;
LAB_c070e74c:
  param_2[8] = 0;
  return 0;
}



/* c070e778 FUN_c070e778 */

/* Boundary evidence: original MIPS .pdata c070e778..c070e813. Semantic name remains unreviewed. */

int FUN_c070e778(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 auStack_30 [5];
  undefined4 local_2b;
  uint local_18;
  
  local_18 = DAT_c0714140;
  iVar1 = (**(code **)(*param_1 + 0x14))
                    (param_1,0xd,(uint)*(ushort *)(param_1 + 0x126) << 0x10,2,1,auStack_30,0,0,0,0,0
                     ,0);
  if (-1 < iVar1) {
    *param_2 = local_2b;
  }
  FUN_c0712ee4(local_18);
  return iVar1;
}



/* c070e814 FUN_c070e814 */

/* Boundary evidence: original MIPS .pdata c070e814..c070e893. Semantic name remains unreviewed. */

undefined4 FUN_c070e814(int param_1,void *param_2)

{
  uint *_Src;
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x48c);
  iVar2 = 1;
  if ((((iVar1 != 2) && (iVar1 != 1)) && (iVar1 != 4)) || ((*(byte *)(param_1 + 0x49d) & 0x40) == 0)
     ) {
    iVar2 = 0;
  }
  _Src = (uint *)(param_1 + 0x738);
  *_Src = *_Src & 0x7fffffff | iVar2 << 0x1f;
  memcpy(param_2,_Src,0x20);
  return 0;
}



/* c070e894 FUN_c070e894 */

/* Boundary evidence: original MIPS .pdata c070e894..c070e993. Semantic name remains unreviewed. */

undefined4 FUN_c070e894(int param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x48c) == 3) && (*(int *)(param_1 + 0x434) != 0)) {
    uVar2 = 0xc0000007;
    puVar1 = (undefined4 *)FUN_c07031cc(*(int *)(param_1 + 0x430),0);
    if (puVar1 != (undefined4 *)0x0) {
      *param_2 = *(undefined1 *)(param_1 + 0x6d0);
      param_2[1] = *(undefined1 *)(param_1 + 0x6d1);
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x6d4);
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x6d8);
      param_2[0xc] = *(undefined1 *)(puVar1[0x1b9] + 2);
      uVar2 = 0;
      FUN_c070310c(puVar1);
    }
  }
  else {
    uVar2 = 0xc0000007;
  }
  return uVar2;
}



/* c070e994 FUN_c070e994 */

/* Boundary evidence: original MIPS .pdata c070e994..c070e9b3. Semantic name remains unreviewed. */

void FUN_c070e994(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070e9b4 FUN_c070e9b4 */

/* Boundary evidence: original MIPS .pdata c070e9b4..c070ea4b. Semantic name remains unreviewed. */

void FUN_c070e9b4(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = *param_2;
  local_c = param_2[1];
  iVar2 = *(int *)(*(int *)(param_1 + 0x430) + 0x7c);
  iVar1 = iVar2 + 8;
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  iVar1 = (**(code **)(iVar2 + 0x44))
                    (iVar1,*(undefined4 *)(*(int *)(param_1 + 0x430) + 0x80),6,&local_10,8);
  if (-1 < iVar1) {
    *param_2 = local_10;
    param_2[1] = local_c;
  }
  return;
}



/* c070ea4c FUN_c070ea4c */

/* Boundary evidence: original MIPS .pdata c070ea4c..c070eb0b. Semantic name remains unreviewed. */

bool FUN_c070ea4c(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  bool bVar2;
  undefined4 local_resc;
  HKEY local_18;
  DWORD DStack_14;
  
  bVar2 = false;
  local_resc = param_4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,L"",0,0x20006,(LPSECURITY_ATTRIBUTES)0x0,&local_18,
                          &DStack_14);
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_18,param_3,0,4,(BYTE *)&local_resc,4);
    bVar2 = LVar1 == 0;
    RegCloseKey(local_18);
  }
  return bVar2;
}



/* c070eb0c FUN_c070eb0c */

/* Boundary evidence: original MIPS .pdata c070eb0c..c070ec5b. Semantic name remains unreviewed. */

int FUN_c070eb0c(int param_1,uint param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte local_28;
  byte local_27 [7];
  
  if (param_4 != (uint *)0x0) {
    if (param_3 == 0) {
      *param_4 = 0;
    }
    iVar3 = 0;
    iVar1 = FUN_c070e250(param_1,0,(int)&local_28,1,param_5);
    while( true ) {
      if (iVar1 < 0) {
        return iVar1;
      }
      if (local_28 == 0xff) {
        return iVar1;
      }
      iVar1 = FUN_c070e250(param_1,iVar3 + 1,(int)local_27,1,param_5);
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar2 = (uint)local_27[0];
      if (uVar2 == 0xff) {
        return iVar1;
      }
      if (local_28 == param_2) break;
      iVar3 = uVar2 + iVar3 + 2;
      iVar1 = FUN_c070e250(param_1,iVar3,(int)&local_28,1,param_5);
    }
    if (param_3 == 0) {
      *param_4 = uVar2;
      return iVar1;
    }
    if (uVar2 <= *param_4) {
      iVar3 = FUN_c070e250(param_1,iVar3 + 2,param_3,uVar2,param_5);
      return iVar3;
    }
  }
  return -0x3ffffff9;
}



/* c070ec5c FUN_c070ec5c */

/* Boundary evidence: original MIPS .pdata c070ec5c..c070ee0f. Semantic name remains unreviewed. */

undefined4 FUN_c070ec5c(int param_1,byte *param_2)

{
  byte bVar1;
  
  *param_2 = *(byte *)(param_1 + 0x4ad);
  param_2[1] = *(byte *)(param_1 + 0x4ab);
  param_2[2] = *(byte *)(param_1 + 0x4ac);
  param_2[3] = 0;
  if (*(int *)(param_1 + 0x48c) == 1) {
    param_2[4] = *(byte *)(param_1 + 0x4a5);
    param_2[5] = *(byte *)(param_1 + 0x4a6);
    param_2[6] = *(byte *)(param_1 + 0x4a7);
    param_2[7] = *(byte *)(param_1 + 0x4a8);
    param_2[8] = *(byte *)(param_1 + 0x4a9);
    param_2[9] = *(byte *)(param_1 + 0x4aa);
    param_2[10] = 0;
    bVar1 = *(byte *)(param_1 + 0x4a4);
    param_2[0xb] = bVar1 >> 4;
    param_2[0xc] = bVar1 & 0xf;
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x4a0);
    param_2[0x14] = *(byte *)(param_1 + 0x49f) >> 4;
    *(ushort *)(param_2 + 0x16) = (*(byte *)(param_1 + 0x49f) & 0xf) + 0x7cd;
  }
  else {
    param_2[4] = *(byte *)(param_1 + 0x4a6);
    param_2[5] = *(byte *)(param_1 + 0x4a7);
    param_2[6] = *(byte *)(param_1 + 0x4a8);
    param_2[7] = *(byte *)(param_1 + 0x4a9);
    param_2[8] = *(byte *)(param_1 + 0x4aa);
    param_2[9] = 0;
    param_2[10] = 0;
    bVar1 = *(byte *)(param_1 + 0x4a5);
    param_2[0xb] = bVar1 >> 4;
    param_2[0xc] = bVar1 & 0xf;
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x4a1);
    param_2[0x14] = *(byte *)(param_1 + 0x49f) & 0xf;
    bVar1 = *(byte *)(param_1 + 0x49f) >> 4;
    *(ushort *)(param_2 + 0x16) = (ushort)bVar1;
    *(ushort *)(param_2 + 0x16) = ((ushort)*(byte *)(param_1 + 0x4a0) << 4 | (ushort)bVar1) + 2000;
  }
  memcpy(param_2 + 0x18,(void *)(param_1 + 0x49e),0x10);
  FUN_c070ea4c((HKEY)0x80000002,L"LGE\\SystemInfo",L"eMMCID",(uint)*param_2);
  return 0;
}



/* c070ee10 FUN_c070ee10 */

/* Boundary evidence: original MIPS .pdata c070ee10..c070efe7. Semantic name remains unreviewed. */

uint FUN_c070ee10(undefined4 param_1,int param_2,uint param_3,uint param_4,byte param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 local_18;
  
  local_18 = local_18 & 0xffffff00;
  memset((void *)((int)&local_18 + 1),0,3);
  uVar2 = (uint)param_5;
  if (uVar2 < 0x21) {
    iVar4 = 8;
    uVar7 = (uint)((ulonglong)param_3 * 8);
    uVar3 = uVar2;
    if ((int)((ulonglong)param_3 * 8 >> 0x20) != 0) {
      iVar4 = 0;
      uVar3 = 0xc0000095;
      RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
    }
    uVar5 = uVar2 + param_4;
    if (uVar5 < param_4) {
      iVar4 = 0;
      uVar3 = 0xc0000095;
      RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
    }
    if (uVar5 <= uVar7) {
      uVar5 = param_4 >> 3;
      uVar7 = uVar5 + 4;
      if (param_3 <= uVar5 + 4) {
        uVar7 = param_3;
      }
      if (uVar5 < uVar7) {
        pbVar8 = (byte *)&local_18;
        do {
          bVar1 = *(byte *)(uVar5 + param_2) >> (param_4 & 7);
          uVar5 = uVar5 + 1;
          *pbVar8 = bVar1;
          if (uVar5 != param_3) {
            *pbVar8 = *(char *)(uVar5 + param_2) << (iVar4 - (param_4 & 7) & 0x1f) | bVar1;
          }
          pbVar8 = pbVar8 + 1;
        } while (uVar5 < uVar7);
      }
      if ((int)uVar3 % iVar4 == 0) {
        uVar2 = uVar2 >> 3;
      }
      else {
        iVar6 = uVar3 - 1;
        if (iVar6 < 0) {
          iVar6 = uVar3 + 6;
        }
        pbVar8 = (byte *)((int)&local_18 + (iVar6 >> 3));
        uVar2 = iVar4 - (int)uVar3 % iVar4;
        *pbVar8 = (byte)(((uint)*pbVar8 << (uVar2 & 0x1f) & 0xff) >> (uVar2 & 0x1f));
        uVar2 = (iVar6 >> 3) + 1;
      }
      if (uVar2 == 4) {
        return local_18;
      }
      memset((void *)((int)&local_18 + uVar2),0,4 - uVar2);
      return local_18;
    }
  }
  return 0;
}



/* c070efe8 FUN_c070efe8 */

/* Boundary evidence: original MIPS .pdata c070efe8..c070fa77. Semantic name remains unreviewed. */

undefined4 FUN_c070efe8(int param_1,byte *param_2)

{
  char cVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  void *_Src;
  undefined8 uVar7;
  
  iVar6 = param_1 + 0x4ae;
  uVar2 = FUN_c070ee10(param_1,iVar6,0x10,0x7e,2);
  *param_2 = (byte)uVar2;
  if (*(int *)(param_1 + 0x48c) == 2) {
    if (1 < (uVar2 & 0xff)) {
      return 0xc0000017;
    }
  }
  else if (*(int *)(param_1 + 0x48c) != 1) {
    return 0xc0000007;
  }
  uVar2 = FUN_c070ee10(param_1,iVar6,0x10,0x70,8);
  uVar5 = uVar2 & 7;
  switch((uVar2 & 0xff) >> 3 & 0xf) {
  case 1:
    uVar4 = 0x3ff00000;
    break;
  case 2:
    param_2[8] = 0x33;
    param_2[9] = 0x33;
    param_2[10] = 0x33;
    param_2[0xb] = 0x33;
    param_2[0xc] = 0x33;
    param_2[0xd] = 0x33;
    param_2[0xe] = 0xf3;
    param_2[0xf] = 0x3f;
    goto LAB_c070f19c;
  case 3:
    param_2[8] = 0xcd;
    param_2[9] = 0xcc;
    param_2[10] = 0xcc;
    param_2[0xb] = 0xcc;
    param_2[0xc] = 0xcc;
    param_2[0xd] = 0xcc;
    param_2[0xe] = 0xf4;
    param_2[0xf] = 0x3f;
    goto LAB_c070f19c;
  case 4:
    uVar4 = 0x3ff80000;
    break;
  case 5:
    uVar4 = 0x40000000;
    goto LAB_c070f13c;
  case 6:
    uVar4 = 0x40040000;
    break;
  case 7:
    uVar4 = 0x40080000;
    goto LAB_c070f13c;
  case 8:
    uVar4 = 0x400c0000;
    break;
  case 9:
    uVar4 = 0x40100000;
    goto LAB_c070f13c;
  case 10:
    uVar4 = 0x40120000;
    break;
  case 0xb:
    uVar4 = 0x40140000;
    goto LAB_c070f13c;
  case 0xc:
    uVar4 = 0x40160000;
    break;
  case 0xd:
    uVar4 = 0x40180000;
    goto LAB_c070f13c;
  case 0xe:
    uVar4 = 0x401c0000;
    break;
  case 0xf:
    uVar4 = 0x40200000;
LAB_c070f13c:
    *(undefined4 *)(param_2 + 0xc) = uVar4;
    goto LAB_c070f198;
  default:
    param_2[0xc] = 0;
    param_2[0xd] = 0;
    param_2[0xe] = 0;
    param_2[0xf] = 0;
    goto LAB_c070f198;
  }
  *(undefined4 *)(param_2 + 0xc) = uVar4;
LAB_c070f198:
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
LAB_c070f19c:
  if (uVar5 != 0) {
    uVar7 = *(undefined8 *)(param_2 + 8);
    do {
      uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x40240000);
      uVar5 = uVar5 + 0xff & 0xff;
    } while (uVar5 != 0);
    *(undefined8 *)(param_2 + 8) = uVar7;
  }
  uVar2 = FUN_c070ee10(param_1,iVar6,0x10,0x68,8);
  *(ushort *)(param_2 + 0x10) = (ushort)uVar2 & 0xff;
  uVar2 = FUN_c070ee10(param_1,iVar6,0x10,0x60,8);
  uVar5 = uVar2 & 7;
  switch((uVar2 & 0xff) >> 3 & 0xf) {
  case 1:
    param_2[0x18] = 100;
    param_2[0x19] = 0;
    param_2[0x1a] = 0;
    param_2[0x1b] = 0;
    goto LAB_c070f304;
  case 2:
    uVar4 = 0x78;
    break;
  case 3:
    uVar4 = 0x82;
    goto LAB_c070f298;
  case 4:
    uVar4 = 0x96;
    break;
  case 5:
    param_2[0x18] = 200;
    param_2[0x19] = 0;
    param_2[0x1a] = 0;
    param_2[0x1b] = 0;
    goto LAB_c070f304;
  case 6:
    uVar4 = 0xfa;
    break;
  case 7:
    uVar4 = 300;
    goto LAB_c070f298;
  case 8:
    uVar4 = 0x15e;
    break;
  case 9:
    uVar4 = 400;
    goto LAB_c070f298;
  case 10:
    uVar4 = 0x1c2;
    break;
  case 0xb:
    uVar4 = 500;
    goto LAB_c070f298;
  case 0xc:
    uVar4 = 0x226;
    break;
  case 0xd:
    uVar4 = 600;
    goto LAB_c070f298;
  case 0xe:
    uVar4 = 700;
    break;
  case 0xf:
    uVar4 = 800;
LAB_c070f298:
    *(undefined4 *)(param_2 + 0x18) = uVar4;
    goto LAB_c070f304;
  default:
    param_2[0x18] = 0;
    param_2[0x19] = 0;
    param_2[0x1a] = 0;
    param_2[0x1b] = 0;
    goto LAB_c070f304;
  }
  *(undefined4 *)(param_2 + 0x18) = uVar4;
LAB_c070f304:
  if (uVar5 != 0) {
    iVar6 = *(int *)(param_2 + 0x18);
    do {
      iVar6 = iVar6 * 10;
      uVar5 = uVar5 + 0xff & 0xff;
    } while (uVar5 != 0);
    *(int *)(param_2 + 0x18) = iVar6;
  }
  _Src = (void *)(param_1 + 0x4ae);
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x54,0xc);
  *(short *)(param_2 + 0x1c) = (short)uVar2;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x50,4);
  *(short *)(param_2 + 0x1e) = (short)(1 << (uVar2 & 0x1f));
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x16,4);
  *(short *)(param_2 + 0x36) = (short)(1 << (uVar2 & 0x1f));
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x4f,1);
  param_2[0x20] = uVar2 != 0;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x15,1);
  param_2[0x38] = uVar2 != 0;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x4e,1);
  param_2[0x21] = uVar2 != 0;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x4d,1);
  param_2[0x22] = uVar2 != 0;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x4c,1);
  param_2[0x23] = uVar2 != 0;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x1f,1);
  param_2[0x33] = uVar2 != 0;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0xe,1);
  param_2[0x39] = uVar2 != 0;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0xd,1);
  param_2[0x3a] = uVar2 != 0;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0xc,1);
  param_2[0x3b] = uVar2 != 0;
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x3e,0xc);
  uVar5 = FUN_c070ee10(param_1,(int)_Src,0x10,0x2f,3);
  iVar6 = (1 << (uVar5 + 2 & 0x1f)) * (uVar2 + 1) * (uint)*(ushort *)(param_2 + 0x1e);
  *(int *)(param_2 + 0x24) = iVar6;
  *(int *)(param_1 + 0x730) = iVar6;
  *(undefined4 *)(param_1 + 0x734) = 0;
  if (((*(int *)(param_1 + 0x48c) == 1) && (1 < *param_2)) && (1 < *(byte *)(param_1 + 0x586))) {
    *(int *)(param_1 + 0x730) = *(int *)(param_1 + 0x59a) << 9;
    *(undefined4 *)(param_1 + 0x734) = 0;
    *(int *)(param_2 + 0x24) = *(int *)(param_1 + 0x59a);
  }
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x3b,3);
  *(short *)(param_2 + 0x28) = (short)uVar2;
  switch(uVar2 & 0xffff) {
  case 0:
  case 1:
    param_2[0x28] = 1;
    param_2[0x29] = 0;
    break;
  case 2:
    param_2[0x28] = 5;
    param_2[0x29] = 0;
    break;
  case 3:
    uVar3 = 10;
    goto LAB_c070f64c;
  case 4:
    param_2[0x28] = 0x19;
    param_2[0x29] = 0;
    break;
  case 5:
    param_2[0x28] = 0x23;
    param_2[0x29] = 0;
    break;
  case 6:
    param_2[0x28] = 0x3c;
    param_2[0x29] = 0;
    break;
  case 7:
    uVar3 = 100;
LAB_c070f64c:
    *(undefined2 *)(param_2 + 0x28) = uVar3;
    break;
  default:
    param_2[0x28] = 0;
    param_2[0x29] = 0;
  }
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x35,3);
  *(short *)(param_2 + 0x2c) = (short)uVar2;
  switch(uVar2 & 0xffff) {
  case 0:
  case 1:
    param_2[0x2c] = 1;
    param_2[0x2d] = 0;
    break;
  case 2:
    param_2[0x2c] = 5;
    param_2[0x2d] = 0;
    break;
  case 3:
    uVar3 = 10;
    goto LAB_c070f6dc;
  case 4:
    param_2[0x2c] = 0x19;
    param_2[0x2d] = 0;
    break;
  case 5:
    param_2[0x2c] = 0x23;
    param_2[0x2d] = 0;
    break;
  case 6:
    uVar3 = 0x3c;
    goto LAB_c070f6dc;
  case 7:
    uVar3 = 100;
LAB_c070f6dc:
    *(undefined2 *)(param_2 + 0x2c) = uVar3;
    break;
  default:
    param_2[0x2c] = 0;
    param_2[0x2d] = 0;
  }
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x38,3);
  *(short *)(param_2 + 0x2a) = (short)uVar2;
  switch(uVar2 & 0xffff) {
  case 0:
    param_2[0x2a] = 1;
    param_2[0x2b] = 0;
    break;
  case 1:
    param_2[0x2a] = 5;
    param_2[0x2b] = 0;
    break;
  case 2:
    uVar3 = 10;
    goto LAB_c070f770;
  case 3:
    param_2[0x2a] = 0x19;
    param_2[0x2b] = 0;
    break;
  case 4:
    param_2[0x2a] = 0x23;
    param_2[0x2b] = 0;
    break;
  case 5:
    param_2[0x2a] = 0x2d;
    param_2[0x2b] = 0;
    break;
  case 6:
    uVar3 = 0x50;
    goto LAB_c070f770;
  case 7:
    uVar3 = 200;
LAB_c070f770:
    *(undefined2 *)(param_2 + 0x2a) = uVar3;
    break;
  default:
    param_2[0x2a] = 0;
    param_2[0x2b] = 0;
  }
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x32,3);
  *(short *)(param_2 + 0x2e) = (short)uVar2;
  switch(uVar2 & 0xffff) {
  case 0:
    param_2[0x2e] = 1;
    param_2[0x2f] = 0;
    break;
  case 1:
    param_2[0x2e] = 5;
    param_2[0x2f] = 0;
    break;
  case 2:
    uVar3 = 10;
    goto LAB_c070f808;
  case 3:
    param_2[0x2e] = 0x19;
    param_2[0x2f] = 0;
    break;
  case 4:
    param_2[0x2e] = 0x23;
    param_2[0x2f] = 0;
    break;
  case 5:
    uVar3 = 0x2d;
    goto LAB_c070f808;
  case 6:
    uVar3 = 0x50;
LAB_c070f808:
    *(undefined2 *)(param_2 + 0x2e) = uVar3;
    break;
  case 7:
    param_2[0x2e] = 200;
    param_2[0x2f] = 0;
    break;
  default:
    param_2[0x2e] = 0;
    param_2[0x2f] = 0;
  }
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x1a,3);
  param_2[0x34] = (byte)uVar2;
  if ((*(int *)(param_1 + 0x48c) == 2) && (*param_2 == 1)) {
    param_2[0x28] = 0;
    param_2[0x29] = 0;
    param_2[0x2c] = 0;
    param_2[0x2d] = 0;
    param_2[0x2a] = 200;
    param_2[0x2b] = 0;
    param_2[0x2e] = 200;
    param_2[0x2f] = 0;
    uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x30,0x16);
    *(ulonglong *)(param_1 + 0x730) = (ulonglong)uVar2 * 0x80000;
    *(uint *)(param_2 + 0x24) =
         *(int *)(param_1 + 0x734) << 0x17 | (uint)((ulonglong)uVar2 * 0x80000) >> 9;
  }
  param_2[0x34] = (byte)(1 << (param_2[0x34] & 0x1f));
  uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0xf,1);
  uVar5 = FUN_c070ee10(param_1,(int)_Src,0x10,10,2);
  uVar5 = uVar5 & 0xff;
  if ((uVar2 & 0xff) == 0) {
    if (uVar5 == 0) {
      param_2[0x3c] = 0;
      param_2[0x3d] = 0;
      param_2[0x3e] = 0;
      param_2[0x3f] = 0;
      goto LAB_c070f958;
    }
    if (uVar5 == 1) {
      param_2[0x3c] = 1;
      param_2[0x3d] = 0;
      param_2[0x3e] = 0;
      param_2[0x3f] = 0;
      goto LAB_c070f958;
    }
    if (uVar5 == 2) {
      param_2[0x3c] = 2;
      param_2[0x3d] = 0;
      param_2[0x3e] = 0;
      param_2[0x3f] = 0;
      goto LAB_c070f958;
    }
  }
  param_2[0x3c] = 3;
  param_2[0x3d] = 0;
  param_2[0x3e] = 0;
  param_2[0x3f] = 0;
LAB_c070f958:
  if (*(int *)(param_1 + 0x48c) == 1) {
    param_2[0x30] = 0;
    uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x2a,5);
    uVar5 = FUN_c070ee10(param_1,(int)_Src,0x10,0x25,5);
    param_2[0x31] = ((char)uVar5 + '\x01') * ((char)uVar2 + '\x01');
    uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x20,5);
    cVar1 = (char)uVar2;
  }
  else {
    uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x2e,1);
    param_2[0x30] = uVar2 != 0;
    uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x27,7);
    param_2[0x31] = (char)uVar2 + 1;
    uVar2 = FUN_c070ee10(param_1,(int)_Src,0x10,0x20,7);
    cVar1 = (char)uVar2;
  }
  param_2[0x32] = cVar1 + 1;
  memcpy(param_2 + 0x40,_Src,0x10);
  return 0;
}



/* c070fa78 FUN_c070fa78 */

/* Boundary evidence: original MIPS .pdata c070fa78..c070fdc3. Semantic name remains unreviewed. */

int FUN_c070fa78(int *param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint local_50;
  uint local_4c;
  undefined1 auStack_30 [32];
  
  iVar1 = -0x3ffffff9;
  switch(param_2) {
  case 1:
    if ((0x27 < param_4) && (param_3 != (uint *)0x0)) {
      iVar1 = FUN_c070ec5c((int)param_1,(byte *)param_3);
    }
    break;
  case 2:
    if ((0x4f < param_4) && (param_3 != (uint *)0x0)) {
      iVar1 = FUN_c070efe8((int)param_1,(byte *)param_3);
    }
    break;
  case 3:
    if (param_4 < 2) {
      return -0x3ffffff9;
    }
    if (param_3 == (uint *)0x0) {
      return -0x3ffffff9;
    }
    iVar1 = param_1[0x126];
    *(char *)param_3 = (char)(short)iVar1;
    *(char *)((int)param_3 + 1) = (char)((ushort)(short)iVar1 >> 8);
    goto LAB_c070fb64;
  case 5:
    if (((0xb < param_4) && (param_3 != (uint *)0x0)) &&
       (iVar1 = FUN_c070e814((int)param_1,&local_50), -1 < iVar1)) {
      memcpy(auStack_30,&local_50,0x20);
      *param_3 = (uint)((local_50 & 1) != 0);
      param_3[1] = local_4c;
      param_3[2] = (uint)((local_50 & 0x40000000) != 0);
    }
    break;
  case 6:
    if ((3 < param_4) && (param_3 != (uint *)0x0)) {
      iVar1 = FUN_c070e778(param_1,param_3);
    }
    break;
  case 7:
    if ((0xf < param_4) && (param_3 != (uint *)0x0)) {
      iVar1 = FUN_c070e894((int)param_1,(undefined1 *)param_3);
    }
    break;
  case 8:
    if (param_4 < 0xc) {
      return -0x3ffffff9;
    }
    if (param_3 == (uint *)0x0) {
      return -0x3ffffff9;
    }
    param_3[1] = *(uint *)(param_1[0x10c] + 0x74);
    if ((*(uint *)(param_1[0x10c] + 0x68) & 8) == 0) {
      *param_3 = 0;
    }
    else {
      *param_3 = 1;
    }
    param_3[2] = 0;
LAB_c070fb64:
    iVar1 = 0;
    break;
  case 9:
    if ((7 < param_4) && (param_3 != (uint *)0x0)) {
      iVar1 = FUN_c070e9b4((int)param_1,param_3);
    }
    break;
  case 10:
    if (((3 < param_4) && (param_3 != (uint *)0x0)) &&
       (iVar1 = FUN_c070e814((int)param_1,&local_50), -1 < iVar1)) {
      *param_3 = local_50 >> 0x1f;
    }
    break;
  case 0xc:
    if ((0x1f < param_4) && (param_3 != (uint *)0x0)) {
      iVar1 = FUN_c070e814((int)param_1,param_3);
    }
    break;
  case 0xd:
    if ((0x4b < param_4) && (param_3 != (uint *)0x0)) {
      iVar1 = FUN_c0706d90(param_1,param_3,1);
    }
  }
  return iVar1;
}



/* c070fdc4 FUN_c070fdc4 */

/* Boundary evidence: original MIPS .pdata c070fdc4..c070fde3. Semantic name remains unreviewed. */

void FUN_c070fdc4(int *param_1)

{
  FUN_c0710f8c(param_1);
  return;
}



/* c070fde4 FUN_c070fde4 */

/* Boundary evidence: original MIPS .pdata c070fde4..c071002f. Semantic name remains unreviewed. */

int FUN_c070fde4(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined2 uVar4;
  byte local_50 [8];
  int aiStack_48 [2];
  int local_40;
  int local_2c;
  
  if (*(int *)(param_1 + 0x434) == 0) {
    return -0x3ffffff9;
  }
  iVar1 = FUN_c070e530(param_1,aiStack_48);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (local_40 != param_3) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x430) + 0x7c);
    iVar1 = iVar3 + 8;
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    iVar1 = (**(code **)(iVar3 + 0x58))
                      (iVar1,*(undefined4 *)(*(int *)(param_1 + 0x430) + 0x80),local_2c);
    if (iVar1 < 0) {
      return iVar1;
    }
    local_2c = (uint)*(ushort *)(*(int *)(param_1 + 0x430) + 0xb0) + local_2c;
    if (local_2c < 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (undefined2)local_2c;
    }
    *(undefined2 *)(*(int *)(param_1 + 0x430) + 0xb0) = uVar4;
    piVar2 = (int *)FUN_c07031cc(*(int *)(param_1 + 0x430),0);
    if (piVar2 == (int *)0x0) {
      return -0x3ffffff8;
    }
    if (param_3 == 0) {
      *(byte *)(piVar2[0x1b9] + 0x11) =
           ~(byte)(1 << (*(byte *)(param_1 + 0x6d0) & 0x1f)) & *(byte *)(piVar2[0x1b9] + 0x11);
    }
    else {
      *(byte *)(piVar2[0x1b9] + 0x11) =
           (byte)(1 << (*(byte *)(param_1 + 0x6d0) & 0x1f)) | *(byte *)(piVar2[0x1b9] + 0x11);
    }
    local_50[0] = *(byte *)(piVar2[0x1b9] + 0x11);
    iVar1 = (**(code **)(*piVar2 + 0x10))(piVar2,1,2,0,local_50,1);
    FUN_c070310c(piVar2);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  if (param_3 == 0) {
    return iVar1;
  }
  piVar2 = (int *)FUN_c07031cc(*(int *)(param_1 + 0x430),0);
  if (piVar2 == (int *)0x0) {
    return -0x3ffffff8;
  }
  iVar1 = *param_2;
  if (iVar1 != 0) {
    do {
      Sleep(param_2[1]);
      iVar3 = (**(code **)(*piVar2 + 0x10))(piVar2,0,3,0,local_50,1);
      if ((iVar3 < 0) || ((1 << (*(byte *)(param_1 + 0x6d0) & 0x1f) & (uint)local_50[0]) != 0))
      break;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (iVar1 != 0) goto LAB_c070fffc;
  }
  iVar3 = -0x3fffffee;
LAB_c070fffc:
  FUN_c070310c(piVar2);
  return iVar3;
}



/* c0710030 FUN_c0710030 */

/* Boundary evidence: original MIPS .pdata c0710030..c07101f3. Semantic name remains unreviewed. */

int FUN_c0710030(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  byte local_48 [8];
  int local_40 [3];
  int local_34;
  int local_30;
  int local_20;
  
  if (*(int *)(param_1 + 0x434) == 0) {
    iVar4 = -0x3ffffff9;
  }
  else {
    iVar4 = FUN_c070e530(param_1,local_40);
    if (-1 < iVar4) {
      if ((local_40[0] == 0) || (local_34 == 0)) {
        iVar4 = -0x3ffffff7;
      }
      else if (local_30 == param_2) {
        iVar4 = 0;
      }
      else {
        iVar2 = *(int *)(*(int *)(param_1 + 0x430) + 0x7c);
        iVar4 = iVar2 + 8;
        if (iVar2 == 0) {
          iVar4 = 0;
        }
        iVar4 = (**(code **)(iVar2 + 0x58))
                          (iVar4,*(undefined4 *)(*(int *)(param_1 + 0x430) + 0x80),local_20);
        if (-1 < iVar4) {
          local_20 = (uint)*(ushort *)(*(int *)(param_1 + 0x430) + 0xb0) + local_20;
          if (local_20 < 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = (undefined2)local_20;
          }
          *(undefined2 *)(*(int *)(param_1 + 0x430) + 0xb0) = uVar3;
          piVar1 = (int *)FUN_c07031cc(*(int *)(param_1 + 0x430),0);
          iVar4 = -0x3ffffff8;
          if (piVar1 != (int *)0x0) {
            iVar2 = (uint)*(byte *)(param_1 + 0x6d0) * 0x100 + 2;
            iVar4 = (**(code **)(*piVar1 + 0x10))(piVar1,0,iVar2,0,local_48,1);
            if (-1 < iVar4) {
              if (param_2 == 0) {
                local_48[0] = local_48[0] & 0xfd;
              }
              else {
                local_48[0] = local_48[0] | 2;
              }
              iVar4 = (**(code **)(*piVar1 + 0x10))(piVar1,1,iVar2,0,local_48,1);
            }
            FUN_c070310c(piVar1);
          }
        }
      }
    }
  }
  return iVar4;
}



/* c07101f4 FUN_c07101f4 */

/* Boundary evidence: original MIPS .pdata c07101f4..c0710283. Semantic name remains unreviewed. */

undefined4 FUN_c07101f4(int param_1,undefined2 param_2)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined2 local_18 [4];
  
  bVar1 = *(byte *)(param_1 + 0x6d0);
  local_18[0] = param_2;
  piVar2 = (int *)FUN_c07031cc(*(int *)(param_1 + 0x430),0);
  uVar3 = 0xc0000008;
  if (piVar2 != (int *)0x0) {
    uVar3 = (**(code **)(*piVar2 + 0x10))(piVar2,1,(uint)bVar1 * 0x100 + 0x10,0,local_18,2);
    FUN_c070310c(piVar2);
  }
  return uVar3;
}



/* c0710284 FUN_c0710284 */

/* Boundary evidence: original MIPS .pdata c0710284..c07104e7. Semantic name remains unreviewed. */

int FUN_c0710284(int *param_1,uint *param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_48 [32];
  
  bVar1 = true;
  bVar2 = true;
  uVar6 = 0;
  do {
    if (!bVar2) break;
    puVar3 = (undefined4 *)FUN_c07031cc(param_1[0x10c],uVar6);
    if (puVar3 != (undefined4 *)0x0) {
      if (((uVar6 != param_1[0x10d]) && (puVar3[0x123] != 0)) &&
         (((((*param_2 & 1) != 0 && ((puVar3[0x1ce] & 1) == 0)) ||
           ((uint)puVar3[0x1cf] < param_2[1])) ||
          (((*param_2 & 2) == 0 && ((puVar3[0x1ce] & 2) != 0)))))) {
        bVar1 = false;
        bVar2 = false;
      }
      FUN_c070310c(puVar3);
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 8);
  if (!bVar1) {
    return -0x3ffffff7;
  }
  iVar7 = 0;
  if (((param_1[0x123] == 3) && ((*(uint *)(param_1[0x10c] + 0x88) & 1) != 0)) &&
     (((param_1[0x1ce] ^ *param_2) & 1) != 0)) {
    iVar7 = param_1[0x1b8];
    (**(code **)(*param_1 + 0x28))(param_1,0,0);
  }
  memcpy(auStack_48,param_1 + 0x1ce,0x20);
  bVar2 = false;
  iVar8 = 0;
  do {
    iVar4 = FUN_c070846c(*(int *)(param_1[0x10c] + 0x7c),*(uint *)(param_1[0x10c] + 0x80),param_2);
    bVar1 = -1 < iVar4;
    uVar6 = 0;
    do {
      if (!bVar1) break;
      piVar5 = (int *)FUN_c07031cc(param_1[0x10c],uVar6);
      if (piVar5 != (int *)0x0) {
        iVar4 = FUN_c0707794(piVar5,param_2);
        if (iVar4 < 0) {
          bVar1 = false;
        }
        FUN_c070310c(piVar5);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 8);
    if ((-1 < iVar4) || (bVar2)) {
      if (iVar7 == 0) {
        return iVar8;
      }
      (**(code **)(*param_1 + 0x28))(param_1,iVar7,1);
      return iVar8;
    }
    memcpy(param_2,auStack_48,0x20);
    bVar2 = true;
    iVar8 = iVar4;
  } while( true );
}



/* c07104e8 FUN_c07104e8 */

/* Boundary evidence: original MIPS .pdata c07104e8..c07109c3. Semantic name remains unreviewed. */

int FUN_c07104e8(int *param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint local_38;
  uint local_34;
  
  switch(param_2) {
  case 0:
    if (((param_4 == 8) && (param_3 != (uint *)0x0)) && (param_1[0x123] == 3)) {
      iVar3 = 1;
LAB_c0710590:
      iVar3 = FUN_c070fde4((int)param_1,(int *)param_3,iVar3);
      return iVar3;
    }
    break;
  case 1:
    if (param_1[0x123] == 3) {
      iVar3 = 0;
      param_3 = (uint *)0x0;
      goto LAB_c0710590;
    }
    break;
  case 2:
    if (((param_4 == 4) && (param_3 != (uint *)0x0)) && (param_1[0x123] == 3)) {
      iVar3 = FUN_c07101f4((int)param_1,(short)*param_3);
      return iVar3;
    }
    break;
  case 3:
    if ((param_4 == 8) && (param_3 != (uint *)0x0)) {
      param_1[0x1c9] = *param_3;
      param_1[0x1c8] = param_3[1];
      return 0;
    }
    break;
  case 4:
    if ((param_4 == 0xc) && (param_3 != (uint *)0x0)) {
      memset(&local_38,0,0x20);
      local_34 = param_3[1];
      local_38 = ((uint)(param_3[2] != 0) << 0x1e ^ local_38) & 0x40000000 ^ local_38;
      local_38 = (*param_3 == 1 ^ local_38) & 1 ^ local_38;
      param_3 = &local_38;
LAB_c0710754:
      iVar3 = FUN_c0710284(param_1,param_3);
      return iVar3;
    }
    break;
  case 5:
    if ((param_4 == 4) && (param_3 != (uint *)0x0)) {
      iVar6 = *(int *)(param_1[0x10c] + 0x7c);
      iVar3 = iVar6 + 8;
      if (iVar6 == 0) {
        iVar3 = 0;
      }
      iVar3 = (**(code **)(iVar6 + 0x44))(iVar3,*(undefined4 *)(param_1[0x10c] + 0x80),7,param_3,4);
      return iVar3;
    }
    break;
  case 6:
  case 0xc:
    goto LAB_c07109a0;
  case 7:
    bVar5 = *(byte *)((int)param_1 + 0x709) | 0x10;
    goto LAB_c07106a8;
  case 8:
    bVar5 = *(byte *)((int)param_1 + 0x709) & 0xef;
    goto LAB_c07106b8;
  case 9:
    param_1[0x1d6] = 1;
    bVar1 = true;
    FUN_c070470c((int)param_1,6);
    uVar7 = 0;
    do {
      puVar2 = (undefined4 *)FUN_c07031cc(param_1[0x10c],uVar7);
      if (puVar2 != (undefined4 *)0x0) {
        if ((puVar2[0x1d6] == 0) && (puVar2[0x123] != 0)) {
          bVar1 = false;
        }
        FUN_c070310c(puVar2);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 8);
    if (!bVar1) {
      return 1;
    }
    uVar4 = 6;
    goto LAB_c07107cc;
  case 10:
    bVar1 = true;
    if (param_1[0x1d7] == 0) {
      param_1[0x1d7] = 1;
      FUN_c070470c((int)param_1,5);
    }
    uVar7 = 0;
    do {
      puVar2 = (undefined4 *)FUN_c07031cc(param_1[0x10c],uVar7);
      if (puVar2 != (undefined4 *)0x0) {
        if ((puVar2[0x1d7] == 0) && (puVar2[0x123] != 0)) {
          bVar1 = false;
        }
        FUN_c070310c(puVar2);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 8);
    if (!bVar1) {
      return 1;
    }
    uVar4 = 5;
    goto LAB_c07107cc;
  case 0xb:
    uVar4 = 7;
LAB_c07107cc:
    FUN_c0710bc8(param_1[0x10c],uVar4,0xffffffff);
    return 0;
  case 0xd:
    bVar5 = *(byte *)((int)param_1 + 0x709) | 0x20;
LAB_c07106a8:
    *(byte *)((int)param_1 + 0x709) = bVar5;
LAB_c07109a0:
    return 0;
  case 0xe:
    bVar5 = *(byte *)((int)param_1 + 0x709) & 0xdf;
LAB_c07106b8:
    *(byte *)((int)param_1 + 0x709) = bVar5;
    return 0;
  case 0xf:
    if (param_1[0x123] == 3) {
      iVar3 = 0;
LAB_c07105dc:
      iVar3 = FUN_c0710030((int)param_1,iVar3);
      return iVar3;
    }
    break;
  case 0x10:
    if (param_1[0x123] == 3) {
      iVar3 = 1;
      goto LAB_c07105dc;
    }
    break;
  case 0x11:
    if ((param_4 == 0x24) && ((param_3 != (uint *)0x0 && (param_1[0x123] == 3)))) {
      iVar3 = FUN_c070e530((int)param_1,(int *)param_3);
      return iVar3;
    }
    break;
  case 0x12:
    if ((param_4 == 0x20) && (param_3 != (uint *)0x0)) goto LAB_c0710754;
    break;
  case 0x13:
    if (param_3 == (uint *)0x0) {
      return 0;
    }
    if (0x4b < param_4) {
      iVar3 = FUN_c0706d90(param_1,param_3,0);
      return iVar3;
    }
    return 0;
  case 0x14:
    if (param_3 == (uint *)0x0) {
      return 0;
    }
    if (0x17 < param_4) {
      iVar6 = *(int *)(param_1[0x10c] + 0x7c);
      iVar3 = iVar6 + 8;
      if (iVar6 == 0) {
        iVar3 = 0;
      }
      iVar3 = (**(code **)(iVar6 + 0x44))
                        (iVar3,*(undefined4 *)(param_1[0x10c] + 0x80),0xd,param_3,0x18);
      return iVar3;
    }
    return 0;
  case 0x15:
    if (param_3 == (uint *)0x0) {
      return 0;
    }
    if (0x17 < param_4) {
      iVar6 = *(int *)(param_1[0x10c] + 0x7c);
      iVar3 = iVar6 + 8;
      if (iVar6 == 0) {
        iVar3 = 0;
      }
      iVar3 = (**(code **)(iVar6 + 0x44))
                        (iVar3,*(undefined4 *)(param_1[0x10c] + 0x80),0xe,param_3,0x18);
      return iVar3;
    }
    return 0;
  default:
    return -0x3ffffff9;
  }
  return -0x3ffffff9;
}



/* c07109c4 FUN_c07109c4 */

/* Boundary evidence: original MIPS .pdata c07109c4..c0710a1f. Semantic name remains unreviewed. */

undefined4 FUN_c07109c4(int param_1)

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



/* c0710a20 FUN_c0710a20 */

/* Boundary evidence: original MIPS .pdata c0710a20..c0710a9f. Semantic name remains unreviewed. */

undefined4 FUN_c0710a20(int param_1,DWORD param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  if (((*(int *)(param_1 + 8) == 0) || (iVar1 = FUN_c07109c4(param_1), iVar1 == 0)) ||
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



/* c0710aa0 FUN_c0710aa0 */

/* Boundary evidence: original MIPS .pdata c0710aa0..c0710b13. Semantic name remains unreviewed. */

BOOL FUN_c0710aa0(int param_1)

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



/* c0710b14 FUN_c0710b14 */

/* Boundary evidence: original MIPS .pdata c0710b14..c0710b53. Semantic name remains unreviewed. */

void FUN_c0710b14(undefined4 *param_1)

{
  DWORD dwExitCode;
  
  dwExitCode = (**(code **)*param_1)(param_1);
                    /* WARNING: Subroutine does not return */
  param_1[5] = dwExitCode;
  ExitThread(dwExitCode);
}



/* c0710b54 FUN_c0710b54 */

/* Boundary evidence: original MIPS .pdata c0710b54..c0710bc7. Semantic name remains unreviewed. */

undefined4 FUN_c0710b54(int param_1)

{
  undefined4 uVar1;
  
  if (((*(int *)(param_1 + 0x30) == 0) || (*(int *)(param_1 + 0x34) == 0)) ||
     (*(int *)(param_1 + 0x38) == 0)) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 8) != 0) {
      CeSetThreadPriority();
    }
    FUN_c07109c4(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* c0710bc8 FUN_c0710bc8 */

/* Boundary evidence: original MIPS .pdata c0710bc8..c0710ca3. Semantic name remains unreviewed. */

undefined4 FUN_c0710bc8(int param_1,undefined4 param_2,DWORD param_3)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x38),param_3);
  if (DVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    uVar3 = *(uint *)(param_1 + 0x40);
    iVar2 = uVar3 + 1;
    if (*(int *)(param_1 + 0x2c) - 1U <= uVar3) {
      iVar2 = 0;
    }
    if (iVar2 != *(int *)(param_1 + 0x3c)) {
      *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x30)) = param_2;
      iVar2 = *(uint *)(param_1 + 0x40) + 1;
      if (*(int *)(param_1 + 0x2c) - 1U <= *(uint *)(param_1 + 0x40)) {
        iVar2 = 0;
      }
      *(int *)(param_1 + 0x40) = iVar2;
      EventModify(*(undefined4 *)(param_1 + 0x34),3);
      uVar4 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  }
  return uVar4;
}



/* c0710ca4 FUN_c0710ca4 */

/* Boundary evidence: original MIPS .pdata c0710ca4..c0710d77. Semantic name remains unreviewed. */

undefined4 FUN_c0710ca4(int *param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar2 = param_1[1];
  pcVar3 = WaitForSingleObject_exref;
  while (iVar2 == 0) {
    uVar4 = param_1[0xf];
    WaitForSingleObject_exref = pcVar3;
    if (uVar4 == param_1[0x10]) {
      piVar1 = (int *)param_1[0xd];
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = *(undefined4 *)(uVar4 * 4 + param_1[0xc]);
      iVar2 = uVar4 + 1;
      if (param_1[0xb] - 1U <= uVar4) {
        iVar2 = 0;
      }
      param_1[0xf] = iVar2;
      ReleaseSemaphore((HANDLE)param_1[0xe],1,(LPLONG)0x0);
      pcVar3 = *(code **)(*param_1 + 4);
      piVar1 = param_1;
    }
    (*pcVar3)(piVar1,uVar5);
    pcVar3 = WaitForSingleObject_exref;
    iVar2 = param_1[1];
  }
  WaitForSingleObject_exref = pcVar3;
  return 0;
}



/* c0710d78 FUN_c0710d78 */

/* Boundary evidence: original MIPS .pdata c0710d78..c0710df7. Semantic name remains unreviewed. */

undefined4 * FUN_c0710d78(undefined4 *param_1,SIZE_T param_2,int param_3)

{
  HANDLE pvVar1;
  DWORD dwCreationFlags;
  
  param_1[5] = 0xffffffff;
  *param_1 = &PTR_LAB_c0701714;
  dwCreationFlags = 4;
  param_1[1] = 0;
  if (param_3 == 0) {
    dwCreationFlags = 0;
  }
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,param_2,FUN_c0710b14,param_1,dwCreationFlags,
                        param_1 + 3);
  param_1[2] = pvVar1;
  param_1[4] = param_3;
  return param_1;
}



/* c0710df8 FUN_c0710df8 */

/* Boundary evidence: original MIPS .pdata c0710df8..c0710ed3. Semantic name remains unreviewed. */

undefined4 * FUN_c0710df8(undefined4 *param_1,uint param_2)

{
  void *pvVar1;
  HANDLE pvVar2;
  uint uVar3;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  FUN_c0710d78(param_1,0,1);
  *param_1 = &PTR_FUN_c0701718;
  if (param_2 < 0x11) {
    param_2 = 0x10;
  }
  param_1[0xb] = param_2;
  if (param_2 < 0x40000000) {
    uVar3 = param_2 << 2;
  }
  else {
    uVar3 = 0xffffffff;
  }
  pvVar1 = operator_new(uVar3);
  param_1[0xc] = pvVar1;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,1,(LPCWSTR)0x0);
  param_1[0xd] = pvVar2;
  pvVar2 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,param_1[0xb] + -1,param_1[0xb] + -1,
                            (LPCWSTR)0x0);
  param_1[0xe] = pvVar2;
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  return param_1;
}



/* c0710ed4 FUN_c0710ed4 */

/* Boundary evidence: original MIPS .pdata c0710ed4..c0710f8b. Semantic name remains unreviewed. */

void FUN_c0710ed4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0701718;
  param_1[1] = 1;
  FUN_c07109c4((int)param_1);
  if (param_1[0xd] != 0) {
    EventModify(param_1[0xd],3);
  }
  FUN_c0710a20((int)param_1,5000);
  if ((HANDLE)param_1[0xe] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0xe]);
  }
  if ((HANDLE)param_1[0xd] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0xd]);
  }
  operator_delete((void *)param_1[0xc]);
  *param_1 = &PTR_LAB_c0701714;
  FUN_c0710aa0((int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return;
}



/* c0710f8c FUN_c0710f8c */

/* Boundary evidence: original MIPS .pdata c0710f8c..c07112ef. Semantic name remains unreviewed. */

undefined4 FUN_c0710f8c(int *param_1)

{
  uint uVar1;
  wchar_t *pwVar2;
  uint *puVar3;
  
  puVar3 = (uint *)*param_1;
  do {
    if (puVar3 == (uint *)0x0) {
      return 1;
    }
    NKDbgPrintfW(L"SDBusDriver: Exception caught ExceptionCode:0x%08X, flags:0x%08X, Code Address 0x%08X \r\n"
                 ,*puVar3,puVar3[1],puVar3[3]);
    uVar1 = *puVar3;
    if (uVar1 < 0xc000008e) {
      if (uVar1 == 0xc000008d) {
        pwVar2 = L"        Exception: EXCEPTION_FLT_DENORMAL_OPERAND \n";
      }
      else if (uVar1 < 0xc0000007) {
        if (uVar1 == 0xc0000006) {
          pwVar2 = L"        Exception: EXCEPTION_IN_PAGE_ERROR \n";
        }
        else if (uVar1 == 0x80000001) {
          pwVar2 = L"        Exception: EXCEPTION_GUARD_PAGE \n";
        }
        else if (uVar1 == 0x80000002) {
          pwVar2 = L"        Exception: EXCEPTION_DATATYPE_MISALIGNMENT \n";
        }
        else if (uVar1 == 0x80000003) {
          pwVar2 = L"        Exception: EXCEPTION_BREAKPOINT \n";
        }
        else if (uVar1 == 0x80000004) {
          pwVar2 = L"        Exception: EXCEPTION_SINGLE_STEP \n";
        }
        else {
          if (uVar1 != 0xc0000005) goto switchD_c07111c4_default;
          pwVar2 = L"        Exception: EXCEPTION_ACCESS_VIOLATION \n";
        }
      }
      else if (uVar1 == 0xc0000008) {
        pwVar2 = L"        Exception: EXCEPTION_INVALID_HANDLE \n";
      }
      else if (uVar1 == 0xc000001d) {
        pwVar2 = L"        Exception: EXCEPTION_ILLEGAL_INSTRUCTION \n";
      }
      else if (uVar1 == 0xc0000025) {
        pwVar2 = L"        Exception: EXCEPTION_NONCONTINUABLE_EXCEPTION \n";
      }
      else if (uVar1 == 0xc0000026) {
        pwVar2 = L"        Exception: EXCEPTION_INVALID_DISPOSITION \n";
      }
      else {
        if (uVar1 != 0xc000008c) goto switchD_c07111c4_default;
        pwVar2 = L"        Exception: EXCEPTION_ARRAY_BOUNDS_EXCEEDED \n";
      }
    }
    else if (uVar1 < 0xc00000fe) {
      if (uVar1 == 0xc00000fd) {
        pwVar2 = L"        Exception: EXCEPTION_STACK_OVERFLOW \n";
      }
      else {
        switch(uVar1) {
        case 0xc000008e:
          pwVar2 = L"        Exception: EXCEPTION_FLT_DIVIDE_BY_ZERO \n";
          break;
        case 0xc000008f:
          pwVar2 = L"        Exception: EXCEPTION_FLT_INEXACT_RESULT \n";
          break;
        case 0xc0000090:
          pwVar2 = L"        Exception: EXCEPTION_FLT_INVALID_OPERATION \n";
          break;
        case 0xc0000091:
          pwVar2 = L"        Exception: EXCEPTION_FLT_OVERFLOW \n";
          break;
        case 0xc0000092:
          pwVar2 = L"        Exception: EXCEPTION_FLT_STACK_CHECK \n";
          break;
        case 0xc0000093:
          pwVar2 = L"        Exception: EXCEPTION_FLT_UNDERFLOW \n";
          break;
        case 0xc0000094:
          pwVar2 = L"        Exception: EXCEPTION_INT_DIVIDE_BY_ZERO \n";
          break;
        case 0xc0000095:
          pwVar2 = L"        Exception: EXCEPTION_INT_OVERFLOW \n";
          break;
        case 0xc0000096:
          pwVar2 = L"        Exception: EXCEPTION_PRIV_INSTRUCTION \n";
          break;
        default:
          goto switchD_c07111c4_default;
        }
      }
    }
    else {
switchD_c07111c4_default:
      pwVar2 = L"        Exception: UNKNOWN \n";
    }
    NKDbgPrintfW(pwVar2);
    if (*puVar3 == 0xc0000005) {
      uVar1 = puVar3[4];
      if (uVar1 < 2) {
        pwVar2 = L" EXCEPTION_ACCESS_VIOLATION raised but not enough parameters ; %d \n";
      }
      else {
        uVar1 = puVar3[6];
        if (puVar3[5] == 0) {
          pwVar2 = L"        Read Access Exceptioned at VAddress : 0x%08X \n";
        }
        else {
          pwVar2 = L"        Write Access Exceptioned at VAddress : 0x%08X \n";
        }
      }
      NKDbgPrintfW(pwVar2,uVar1);
    }
    puVar3 = (uint *)puVar3[2];
  } while( true );
}



/* c07112f0 FUN_c07112f0 */

/* Boundary evidence: original MIPS .pdata c07112f0..c071134f. Semantic name remains unreviewed. */

PHKEY FUN_c07112f0(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

{
  LSTATUS LVar1;
  
  *param_1 = (HKEY)0x0;
  if (param_3 != (LPCWSTR)0x0) {
    LVar1 = RegOpenKeyExW(param_2,param_3,0,0,param_1);
    if (LVar1 != 0) {
      *param_1 = (HKEY)0x0;
    }
  }
  return param_1;
}



/* c0711350 FUN_c0711350 */

/* Boundary evidence: original MIPS .pdata c0711350..c07113c3. Semantic name remains unreviewed. */

void FUN_c0711350(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  if (*(int *)(param_1 + 0x24) == 0) {
    HalTranslateBusAddress(param_2,param_3,param_5,param_6,param_7,param_8);
  }
  else {
    TranslateBusAddr(*(int *)(param_1 + 0x24),param_2,param_3,param_4,param_5,param_6,param_7,
                     param_8);
  }
  return;
}



/* c07113c4 FUN_c07113c4 */

/* Boundary evidence: original MIPS .pdata c07113c4..c071142b. Semantic name remains unreviewed. */

void FUN_c07113c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  if (*(int *)(param_1 + 0x24) == 0) {
    HalTranslateSystemAddress(param_2,param_3,param_5,param_6,param_7);
  }
  else {
    TranslateSystemAddr(*(int *)(param_1 + 0x24),param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}



/* c071142c FUN_c071142c */

/* Boundary evidence: original MIPS .pdata c071142c..c071147f. Semantic name remains unreviewed. */

void FUN_c071142c(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  if (*(int *)(param_1 + 0x28) != 0) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



/* c0711480 FUN_c0711480 */

/* Boundary evidence: original MIPS .pdata c0711480..c07114f3. Semantic name remains unreviewed. */

void FUN_c0711480(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = *(int *)(param_1 + 0x28);
  while (iVar1 != 0) {
    LeaveCriticalSection(lpCriticalSection);
    Sleep(10);
    EnterCriticalSection(lpCriticalSection);
    iVar1 = *(int *)(param_1 + 0x28);
  }
  return;
}



/* c07114f4 FUN_c07114f4 */

/* Boundary evidence: original MIPS .pdata c07114f4..c071181f. Semantic name remains unreviewed. */

undefined4 *
FUN_c07114f4(undefined4 *param_1,wchar_t *param_2,wchar_t *param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,
            wchar_t *param_10)

{
  void *_Dst;
  wchar_t *pwVar1;
  STRSAFE_LPWSTR pszDest;
  size_t sVar2;
  LSTATUS LVar3;
  uint uVar4;
  uint uVar5;
  PHKEY ppHVar6;
  DWORD local_30 [2];
  
  ppHVar6 = (PHKEY)(param_1 + 2);
  *param_1 = &PTR_FUN_c0701044;
  param_1[1] = 0;
  FUN_c07112f0(ppHVar6,(HKEY)0x80000002,param_3);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  *param_1 = &PTR_FUN_c0702240;
  param_1[0xc] = param_5;
  param_1[0xb] = param_4;
  param_1[0x16] = param_8;
  param_1[0xd] = param_6;
  uVar5 = 0xffffffff;
  param_1[0xe] = param_7;
  param_1[0x11] = param_9;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0x12] = 0;
  param_1[8] = 0;
  uVar4 = (param_9 + 3U) * 0x10;
  if (0xfffffff < param_9 + 3U) {
    uVar4 = uVar5;
  }
  _Dst = operator_new(uVar4);
  param_1[0x13] = _Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,(param_1[0x11] + 3) * 0x10);
    *(wchar_t **)param_1[0x13] = L"BusParent";
    *(undefined4 *)(param_1[0x13] + 0xc) = 4;
    *(undefined4 **)(param_1[0x13] + 4) = param_1 + 0x16;
    *(undefined4 *)(param_1[0x13] + 8) = 4;
    *(wchar_t **)(param_1[0x13] + 0x10) = L"InterfaceType";
    *(undefined4 *)(param_1[0x13] + 0x1c) = 4;
    *(undefined4 **)(param_1[0x13] + 0x14) = param_1 + 0xb;
    *(undefined4 *)(param_1[0x13] + 0x18) = 4;
  }
  param_1[0x14] = 0;
  if (param_10 == (wchar_t *)0x0) {
    if (param_2 != (wchar_t *)0x0) {
      sVar2 = wcslen(param_2);
      pszDest = malloc((sVar2 + 0x2a) * 2);
      param_1[0x14] = pszDest;
      if (pszDest != (STRSAFE_LPWSTR)0x0) {
        StringCchPrintfW(pszDest,sVar2 + 0x2a,L"%s_%d_%d_%d",param_2,param_1[0xc],param_1[0xd],
                         param_1[0xe]);
      }
    }
  }
  else {
    pwVar1 = _wcsdup(param_10);
    param_1[0x14] = pwVar1;
  }
  if ((param_1[0x14] != 0) && (param_1[0x13] != 0)) {
    *(wchar_t **)(param_1[0x13] + 0x20) = L"BusName";
    *(undefined4 *)(param_1[0x13] + 0x2c) = 1;
    *(undefined4 *)(param_1[0x13] + 0x24) = param_1[0x14];
    sVar2 = wcslen((wchar_t *)param_1[0x14]);
    *(size_t *)(param_1[0x13] + 0x28) = (sVar2 + 1) * 2;
  }
  param_1[0x15] = 0;
  if (param_3 != (wchar_t *)0x0) {
    sVar2 = wcslen(param_3);
    if (sVar2 + 1 < 0x80000000) {
      uVar5 = (sVar2 + 1) * 2;
    }
    pwVar1 = operator_new(uVar5);
    param_1[0x15] = pwVar1;
    if (pwVar1 != (wchar_t *)0x0) {
      wcscpy(pwVar1,param_3);
    }
  }
  param_1[0x12] = 3;
  if (*ppHVar6 != (HKEY)0x0) {
    local_30[0] = 4;
    local_30[1] = 0;
    LVar3 = RegQueryValueExW(*ppHVar6,L"Order",(LPDWORD)0x0,local_30 + 1,(LPBYTE)(param_1 + 0xf),
                             local_30);
    if (LVar3 == 0) goto LAB_c07117a8;
  }
  param_1[0xf] = 0xfffffffe;
LAB_c07117a8:
  if (*ppHVar6 != (HKEY)0x0) {
    local_30[1] = 4;
    local_30[0] = 0;
    LVar3 = RegQueryValueExW(*ppHVar6,L"Flags",(LPDWORD)0x0,local_30,(LPBYTE)(param_1 + 0x10),
                             local_30 + 1);
    if (LVar3 == 0) {
      return param_1;
    }
  }
  param_1[0x10] = 0;
  return param_1;
}



/* c071184c FUN_c071184c */

/* Boundary evidence: original MIPS .pdata c071184c..c07119ef. Semantic name remains unreviewed. */

undefined4 FUN_c071184c(int param_1,int param_2,int *param_3)

{
  size_t sVar1;
  void *pvVar2;
  wchar_t *_Dest;
  int *piVar3;
  uint uVar4;
  size_t *psVar5;
  
  if (param_2 != 0) {
    if ((((param_3 != (int *)0x0) && (*param_3 != 0)) && (param_3[1] != 0)) &&
       (*(int *)(param_1 + 0x4c) != 0)) {
      psVar5 = (size_t *)(param_3 + 2);
      do {
        if ((psVar5 == (size_t *)0x8) ||
           (*(int *)(param_1 + 0x44) + 3U <= *(uint *)(param_1 + 0x48))) break;
        sVar1 = wcslen((wchar_t *)psVar5[-2]);
        uVar4 = (*psVar5 + 2 >> 1) + sVar1 + 1;
        if (uVar4 < 0x80000000) {
          uVar4 = uVar4 * 2;
        }
        else {
          uVar4 = 0xffffffff;
        }
        pvVar2 = operator_new(uVar4);
        *(void **)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c)) = pvVar2;
        _Dest = *(wchar_t **)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c));
        if (_Dest == (wchar_t *)0x0) break;
        wcscpy(_Dest,(wchar_t *)psVar5[-2]);
        piVar3 = (int *)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c));
        piVar3[1] = (sVar1 + 1) * 2 + *piVar3;
        memcpy(*(void **)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c) + 4),
               (void *)psVar5[-1],*psVar5);
        param_2 = param_2 + -1;
        *(size_t *)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c) + 0xc) = psVar5[1];
        sVar1 = *psVar5;
        psVar5 = psVar5 + 4;
        *(size_t *)(*(int *)(param_1 + 0x48) * 0x10 + *(int *)(param_1 + 0x4c) + 8) = sVar1;
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
      } while (param_2 != 0);
    }
    if (param_2 != 0) {
      return 0;
    }
  }
  return 1;
}



/* c07119f0 FUN_c07119f0 */

/* Boundary evidence: original MIPS .pdata c07119f0..c0711bf7. Semantic name remains unreviewed. */

undefined4 FUN_c07119f0(int param_1)

{
  LSTATUS LVar1;
  HMODULE hLibModule;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  DWORD local_120 [2];
  WCHAR aWStack_118 [64];
  BYTE aBStack_98 [128];
  uint local_18;
  
  local_18 = DAT_c0714140;
  if (*(int *)(param_1 + 0x24) == 0) {
    if ((((*(int *)(param_1 + 0x28) == 0) && (*(int *)(param_1 + 0x54) != 0)) &&
        (*(int *)(param_1 + 0x50) != 0)) && (*(int *)(param_1 + 0x4c) != 0)) {
      GetTickCount();
      if (*(HKEY *)(param_1 + 8) == (HKEY)0x0) {
LAB_c0711a6c:
        FUN_c0712ee4(local_18);
        return 0;
      }
      local_120[1] = 0x80;
      local_120[0] = 0;
      LVar1 = RegQueryValueExW(*(HKEY *)(param_1 + 8),L"Entry",(LPDWORD)0x0,local_120,aBStack_98,
                               local_120 + 1);
      if (LVar1 == 0) {
        local_120[0] = 0x80;
        local_120[1] = 0;
        LVar1 = RegQueryValueExW(*(HKEY *)(param_1 + 8),L"Dll",(LPDWORD)0x0,local_120 + 1,
                                 (LPBYTE)aWStack_118,local_120);
        if ((LVar1 == 0) && ((*(uint *)(param_1 + 0x40) & 4) == 0)) {
          if ((*(uint *)(param_1 + 0x40) & 2) == 0) {
            hLibModule = (HMODULE)LoadDriver();
          }
          else {
            hLibModule = LoadLibraryW(aWStack_118);
          }
          if (hLibModule != (HMODULE)0x0) {
            pcVar2 = (code *)GetProcAddressW(hLibModule,aBStack_98);
            if (pcVar2 != (code *)0x0) {
              (*pcVar2)(*(undefined4 *)(param_1 + 0x54));
              uVar4 = 1;
              *(undefined4 *)(param_1 + 0x28) = 1;
              goto LAB_c0711bc4;
            }
            FreeLibrary(hLibModule);
          }
        }
        goto LAB_c0711a6c;
      }
      if (*(int *)(param_1 + 0x4c) == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(param_1 + 0x48);
      }
      iVar3 = ActivateDeviceEx(*(undefined4 *)(param_1 + 0x54),*(int *)(param_1 + 0x4c),uVar4,0);
      uVar4 = 1;
      *(int *)(param_1 + 0x24) = iVar3;
      *(uint *)(param_1 + 0x28) = (uint)(iVar3 != 0);
      if (iVar3 != 0) goto LAB_c0711bc4;
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
LAB_c0711bc4:
  FUN_c0712ee4(local_18);
  return uVar4;
}



/* c0711bf8 FUN_c0711bf8 */

/* Boundary evidence: original MIPS .pdata c0711bf8..c0711c3b. Semantic name remains unreviewed. */

int FUN_c0711bf8(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  if ((*(int *)(param_1 + 0x24) != 0) && (iVar1 = DeactivateDevice(), iVar1 != 0)) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return iVar1;
}



/* c0711c3c FUN_c0711c3c */

/* Boundary evidence: original MIPS .pdata c0711c3c..c0711cb3. Semantic name remains unreviewed. */

undefined4 FUN_c0711c3c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 4) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = HalSetBusDataByOffset
                      (4,*(undefined4 *)(param_1 + 0x30),
                       (*(uint *)(param_1 + 0x38) & 7) << 5 | *(uint *)(param_1 + 0x34) & 0x1f,
                       *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 8),
                       *(undefined4 *)(param_2 + 0xc));
    *(undefined4 *)(param_2 + 0xc) = uVar1;
    uVar1 = 1;
  }
  return uVar1;
}



/* c0711cb4 FUN_c0711cb4 */

/* Boundary evidence: original MIPS .pdata c0711cb4..c0711d2b. Semantic name remains unreviewed. */

undefined4 FUN_c0711cb4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 4) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = HalGetBusDataByOffset
                      (4,*(undefined4 *)(param_1 + 0x30),
                       (*(uint *)(param_1 + 0x38) & 7) << 5 | *(uint *)(param_1 + 0x34) & 0x1f,
                       *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 8),
                       *(undefined4 *)(param_2 + 0xc));
    *(undefined4 *)(param_2 + 0xc) = uVar1;
    uVar1 = 1;
  }
  return uVar1;
}



/* c0711d2c FUN_c0711d2c */

/* Boundary evidence: original MIPS .pdata c0711d2c..c0711d97. Semantic name remains unreviewed. */

undefined4 * FUN_c0711d2c(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  *param_1 = &PTR_FUN_c0702274;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  uVar1 = CreateBusAccessHandle(param_2);
  param_1[9] = uVar1;
  uVar1 = GetDeviceHandleFromContext(param_2);
  param_1[8] = uVar1;
  return param_1;
}



/* c0711d98 FUN_c0711d98 */

undefined4 FUN_c0711d98(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x24) == 0) || (uVar1 = 1, *(int *)(param_1 + 0x20) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0711dbc FUN_c0711dbc */

/* Boundary evidence: original MIPS .pdata c0711dbc..c0711e57. Semantic name remains unreviewed. */

void FUN_c0711dbc(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_FUN_c0702274;
  FUN_c0711480((int)param_1);
  while (param_1[7] != 0) {
    puVar1 = (undefined4 *)param_1[7];
    uVar2 = puVar1[0x17];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    param_1[7] = uVar2;
  }
  if (param_1[9] != 0) {
    CloseBusAccessHandle();
    param_1[9] = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return;
}



/* c0711e58 FUN_c0711e58 */

/* Boundary evidence: original MIPS .pdata c0711e58..c0711eab. Semantic name remains unreviewed. */

undefined4 FUN_c0711e58(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c0711350(param_1,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),param_4,
                         *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                         *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c));
  }
  return uVar1;
}



/* c0711eac FUN_c0711eac */

/* Boundary evidence: original MIPS .pdata c0711eac..c0711ef7. Semantic name remains unreviewed. */

undefined4 FUN_c0711eac(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c07113c4(param_1,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),param_4,
                         *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                         *(undefined4 *)(param_2 + 0x18));
  }
  return uVar1;
}



/* c0711ef8 FUN_c0711ef8 */

/* Boundary evidence: original MIPS .pdata c0711ef8..c0711f6f. Semantic name remains unreviewed. */

undefined4 FUN_c0711ef8(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 != (undefined4 *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 0x40))(param_1,*param_2), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,param_2);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c0711f70 FUN_c0711f70 */

/* Boundary evidence: original MIPS .pdata c0711f70..c0711fe7. Semantic name remains unreviewed. */

undefined4 FUN_c0711f70(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 != (undefined4 *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 0x40))(param_1,*param_2), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_2);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c0711fe8 FUN_c0711fe8 */

/* Boundary evidence: original MIPS .pdata c0711fe8..c071207b. Semantic name remains unreviewed. */

undefined4 FUN_c0711fe8(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((((param_2 != (int *)0x0) && (*param_2 != 0)) && (param_2[1] != 0)) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 0x40))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,*(undefined4 *)param_2[1]);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c071207c FUN_c071207c */

/* Boundary evidence: original MIPS .pdata c071207c..c071210f. Semantic name remains unreviewed. */

undefined4 FUN_c071207c(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((((param_2 != (int *)0x0) && (*param_2 != 0)) && (param_2[1] != 0)) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 0x40))(), piVar1 != (int *)0x0)) {
    uVar3 = 1;
    uVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
    *(undefined4 *)param_2[1] = uVar2;
    FUN_c070310c(piVar1);
  }
  return uVar3;
}



/* c0712110 FUN_c0712110 */

/* Boundary evidence: original MIPS .pdata c0712110..c0712173. Semantic name remains unreviewed. */

undefined4 FUN_c0712110(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)(**(code **)(*param_1 + 0x40))(param_1,param_2,0);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 8))(piVar1);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c0712174 FUN_c0712174 */

/* Boundary evidence: original MIPS .pdata c0712174..c07121d7. Semantic name remains unreviewed. */

undefined4 FUN_c0712174(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)(**(code **)(*param_1 + 0x40))(param_1,param_2,0);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1);
    FUN_c070310c(piVar1);
  }
  return uVar2;
}



/* c07121d8 FUN_c07121d8 */

/* Boundary evidence: original MIPS .pdata c07121d8..c071224b. Semantic name remains unreviewed. */

size_t FUN_c07121d8(undefined4 param_1,wchar_t *param_2,uint param_3)

{
  if (7 < param_3) {
    param_3 = 8;
  }
  if ((param_2 == (wchar_t *)0x0) || (param_3 == 0)) {
    param_3 = 0;
  }
  else {
    wcsncpy(param_2,L"UNKNOWN",param_3);
    param_2[param_3 - 1] = L'\0';
  }
  return param_3;
}



/* c071224c FUN_c071224c */

/* Boundary evidence: original MIPS .pdata c071224c..c071268b. Semantic name remains unreviewed. */

int FUN_c071224c(int *param_1,uint param_2,wchar_t *param_3,uint param_4,uint *param_5,uint param_6,
                int *param_7,undefined4 param_8)

{
  int iVar1;
  size_t sVar2;
  code *pcVar3;
  wchar_t *local_40;
  uint *local_3c;
  uint local_38;
  uint local_34;
  uint *local_30;
  uint local_2c;
  uint *local_28;
  uint *local_24;
  
  if (0x2a0018 < param_2) {
    if ((param_2 == 0x2a0040) || (param_2 == 0x2a0044)) {
      if ((param_3 != (wchar_t *)0x0) && (sVar2 = wcslen(param_3), (sVar2 + 1) * 2 <= param_4)) {
        if (param_2 == 0x2a0040) {
          pcVar3 = *(code **)(*param_1 + 0x24);
        }
        else {
          pcVar3 = *(code **)(*param_1 + 0x28);
        }
        iVar1 = (*pcVar3)(param_1,param_3);
        return iVar1;
      }
    }
    else {
      if (param_2 == 0x2a0048) {
        iVar1 = (**(code **)(*param_1 + 4))(param_1);
        return iVar1;
      }
      if (param_2 == 0x2a0080) {
        if ((((param_3 != (wchar_t *)0x0) && (sVar2 = wcslen(param_3), (sVar2 + 1) * 2 <= param_4))
            && (param_5 != (uint *)0x0)) && (3 < param_6)) {
          iVar1 = (**(code **)(*param_1 + 0x50))(param_1,param_3);
          *param_5 = (uint)(iVar1 != 0);
          if (param_7 == (int *)0x0) {
            return 1;
          }
          *param_7 = 4;
          return 1;
        }
      }
      else {
        if (param_2 != 0x2a0084) {
          return 0;
        }
        if ((param_5 != (uint *)0x0) && (1 < param_6)) {
          iVar1 = (**(code **)(*param_1 + 0x54))(param_1,param_5,param_6 >> 1);
          if (param_7 != (int *)0x0) {
            *param_7 = iVar1 << 1;
          }
          return 1;
        }
      }
    }
    goto LAB_c0712650;
  }
  local_40 = param_3;
  if (param_2 == 0x2a0018) {
LAB_c07122e4:
    if (((param_3 == (wchar_t *)0x0) || (param_4 < 2)) &&
       ((param_5 == (uint *)0x0 || (param_6 < 0x10)))) {
LAB_c0712650:
      SetLastError(0x57);
      return 0;
    }
    local_3c = (uint *)*param_5;
    local_38 = param_5[1];
    local_34 = param_5[2];
    local_30 = param_5 + 3;
    if (param_2 == 0x2a0014) {
      pcVar3 = *(code **)(*param_1 + 0x20);
    }
    else {
      pcVar3 = *(code **)(*param_1 + 0x1c);
    }
  }
  else {
    if (param_2 == 0x2a0004) {
      if (((param_3 != (wchar_t *)0x0) && (1 < param_4)) ||
         ((param_5 != (uint *)0x0 && (0x1f < param_6)))) {
        local_3c = (uint *)*param_5;
        local_38 = param_5[1];
        local_30 = (uint *)param_5[2];
        local_24 = param_5 + 6;
        local_2c = param_5[3];
        pcVar3 = *(code **)(*param_1 + 0xc);
LAB_c0712450:
        local_28 = param_5 + 4;
        iVar1 = (*pcVar3)(param_1,&local_40);
        return iVar1;
      }
      goto LAB_c0712650;
    }
    if (param_2 == 0x2a0008) {
      if (((param_3 != (wchar_t *)0x0) && (1 < param_4)) ||
         ((param_5 != (uint *)0x0 && (0x17 < param_6)))) {
        local_38 = param_5[1];
        local_3c = (uint *)*param_5;
        local_30 = (uint *)param_5[2];
        local_2c = param_5[3];
        pcVar3 = *(code **)(*param_1 + 0x10);
        goto LAB_c0712450;
      }
      goto LAB_c0712650;
    }
    if ((param_2 != 0x2a000c) && (param_2 != 0x2a0010)) {
      if (param_2 != 0x2a0014) {
        return 0;
      }
      goto LAB_c07122e4;
    }
    if (((param_3 == (wchar_t *)0x0) || (param_4 < 2)) &&
       ((param_5 == (uint *)0x0 || (param_6 < 8)))) goto LAB_c0712650;
    local_38 = param_5[1];
    local_3c = param_5;
    if (param_2 == 0x2a000c) {
      pcVar3 = *(code **)(*param_1 + 0x18);
    }
    else {
      if (param_2 != 0x2a0010) goto LAB_c07123e4;
      pcVar3 = *(code **)(*param_1 + 0x14);
    }
  }
  iVar1 = (*pcVar3)(param_1,&local_40,param_8);
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_c07123e4:
  SetLastError(0x57);
  return 0;
}



/* c071268c FUN_c071268c */

/* Boundary evidence: original MIPS .pdata c071268c..c07127bf. Semantic name remains unreviewed. */

int FUN_c071268c(int param_1,wchar_t *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  iVar1 = 0;
  if ((param_2 != (wchar_t *)0x0) && (iVar2 = *(int *)(param_1 + 0x1c), iVar2 != 0)) {
    if ((param_3 == (int *)0x0) || (*param_3 == 0)) {
      iVar1 = _wcsnicmp(param_2,L"$bus\\",5);
      if (iVar1 == 0) {
        param_2 = param_2 + 5;
      }
      iVar2 = *(int *)(param_1 + 0x1c);
      iVar1 = iVar2;
      if (iVar2 == 0) goto LAB_c0712794;
      do {
        iVar1 = _wcsicmp(*(wchar_t **)(iVar2 + 0x50),param_2);
        if (iVar1 == 0) break;
        iVar2 = *(int *)(iVar2 + 0x5c);
      } while (iVar2 != 0);
    }
    else {
      do {
        if (iVar2 == *param_3) break;
        iVar2 = *(int *)(iVar2 + 0x5c);
      } while (iVar2 != 0);
    }
    iVar1 = iVar2;
    if (iVar2 != 0) {
      if ((param_3 != (int *)0x0) && (*param_3 == 0)) {
        *param_3 = iVar2;
      }
      InterlockedIncrement((LONG *)(iVar2 + 4));
    }
  }
LAB_c0712794:
  FUN_c071142c(param_1);
  return iVar1;
}



/* c07127c0 FUN_c07127c0 */

/* Boundary evidence: original MIPS .pdata c07127c0..c071284f. Semantic name remains unreviewed. */

undefined4 FUN_c07127c0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = 0;
  if (param_2 != 0) {
    FUN_c0711480(param_1);
    iVar3 = *(int *)(param_1 + 0x1c);
    if (iVar3 == 0) {
      *(int *)(param_1 + 0x1c) = param_2;
    }
    else {
      piVar4 = (int *)(iVar3 + 0x5c);
      iVar2 = *piVar4;
      while (iVar2 != 0) {
        iVar3 = *piVar4;
        piVar4 = (int *)(iVar3 + 0x5c);
        iVar2 = *piVar4;
      }
      *(int *)(iVar3 + 0x5c) = param_2;
    }
    *(undefined4 *)(param_2 + 0x5c) = 0;
    InterlockedIncrement((LONG *)(param_2 + 4));
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    uVar1 = 1;
  }
  return uVar1;
}



/* c0712850 FUN_c0712850 */

/* Boundary evidence: original MIPS .pdata c0712850..c07128cb. Semantic name remains unreviewed. */

undefined4 FUN_c0712850(int *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 != 0) &&
     (puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x40))(param_1,param_2,0),
     puVar1 != (undefined4 *)0x0)) {
    uVar2 = (**(code **)(*param_1 + 0x4c))(param_1,puVar1);
    FUN_c070310c(puVar1);
  }
  return uVar2;
}



/* c07128cc FUN_c07128cc */

/* Boundary evidence: original MIPS .pdata c07128cc..c071296b. Semantic name remains unreviewed. */

undefined4 FUN_c07128cc(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (param_2 != (undefined4 *)0x0) {
    FUN_c0711480(param_1);
    puVar3 = *(undefined4 **)(param_1 + 0x1c);
    puVar2 = (undefined4 *)0x0;
    while (puVar1 = puVar3, puVar1 != (undefined4 *)0x0) {
      if (puVar1 == param_2) goto LAB_c0712924;
      puVar2 = puVar1;
      puVar3 = (undefined4 *)puVar1[0x17];
    }
    if (param_2 == (undefined4 *)0x0) {
LAB_c0712924:
      uVar4 = 1;
      if (puVar2 == (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0x1c) = puVar1[0x17];
      }
      else {
        puVar2[0x17] = puVar1[0x17];
      }
      puVar1[0x17] = 0;
      FUN_c070310c(puVar1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return uVar4;
}



/* c0712984 FUN_c0712984 */

/* Boundary evidence: original MIPS .pdata c0712984..c0712a83. Semantic name remains unreviewed. */

void FUN_c0712984(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  *param_1 = &PTR_FUN_c0702240;
  if (param_1[9] != 0) {
    FUN_c0711bf8((int)param_1);
  }
  if ((void *)param_1[0x14] != (void *)0x0) {
    free((void *)param_1[0x14]);
  }
  if ((void *)param_1[0x15] != (void *)0x0) {
    operator_delete((void *)param_1[0x15]);
  }
  uVar2 = 3;
  if (3 < (uint)param_1[0x12]) {
    iVar1 = 0x30;
    do {
      if (*(void **)(param_1[0x13] + iVar1) != (void *)0x0) {
        operator_delete(*(void **)(param_1[0x13] + iVar1));
      }
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0x10;
    } while (uVar2 < (uint)param_1[0x12]);
  }
  if ((void *)param_1[0x13] != (void *)0x0) {
    operator_delete((void *)param_1[0x13]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  if ((HKEY)param_1[2] != (HKEY)0x0) {
    RegCloseKey((HKEY)param_1[2]);
  }
  *param_1 = &PTR_FUN_c0701044;
  return;
}



/* c0712a84 FUN_c0712a84 */

/* Boundary evidence: original MIPS .pdata c0712a84..c0712acf. Semantic name remains unreviewed. */

undefined4 * FUN_c0712a84(undefined4 *param_1,uint param_2)

{
  FUN_c0711dbc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0712ad0 FUN_c0712ad0 */

/* Boundary evidence: original MIPS .pdata c0712ad0..c0712b1b. Semantic name remains unreviewed. */

undefined4 * FUN_c0712ad0(undefined4 *param_1,uint param_2)

{
  FUN_c0712984(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0712d7c entry */

/* Boundary evidence: original MIPS .pdata c0712d7c..c0712def. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c0712df0();
    FUN_c0713140();
  }
  uVar1 = FUN_c070e1dc(param_1,param_2);
  if (param_2 == 0) {
    FUN_c07130c8();
  }
  return uVar1;
}



/* c0712df0 FUN_c0712df0 */

/* Boundary evidence: original MIPS .pdata c0712df0..c0712e63. Semantic name remains unreviewed. */

void FUN_c0712df0(void)

{
  uint uVar1;
  
  if ((DAT_c0714140 == 0) || (DAT_c0714140 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0714140 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0714140 == 0) {
      DAT_c0714140 = 0xb064;
    }
  }
  DAT_c0714144 = ~DAT_c0714140;
  return;
}



/* c0712e64 FUN_c0712e64 */

/* Boundary evidence: original MIPS .pdata c0712e64..c0712eb7. Semantic name remains unreviewed. */

void FUN_c0712e64(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0712ee4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0712eb8 FUN_c0712eb8 */

/* Boundary evidence: original MIPS .pdata c0712eb8..c0712ee3. Semantic name remains unreviewed. */

undefined4 FUN_c0712eb8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0712e64(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0712ee4 FUN_c0712ee4 */

/* Boundary evidence: original MIPS .pdata c0712ee4..c0712f2b. Semantic name remains unreviewed. */

void FUN_c0712ee4(uint param_1)

{
  if ((param_1 == DAT_c0714140) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0712f2c FUN_c0712f2c */

/* Boundary evidence: original MIPS .pdata c0712f2c..c0712fa7. Semantic name remains unreviewed. */

void FUN_c0712f2c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c0712e64(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c0712fa8 FUN_c0712fa8 */

/* Boundary evidence: original MIPS .pdata c0712fa8..c07130c7. Semantic name remains unreviewed. */

void FUN_c0712fa8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c0714158 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c0714160;
    if (DAT_c0714160 != (undefined4 *)0x0) {
      while (DAT_c071415c = DAT_c071415c + -1, _Memory <= DAT_c071415c) {
        if ((code *)*DAT_c071415c != (code *)0x0) {
          (*(code *)*DAT_c071415c)();
          _Memory = DAT_c0714160;
        }
      }
      free(_Memory);
      DAT_c071415c = (undefined4 *)0x0;
      DAT_c0714160 = (undefined4 *)0x0;
    }
    FUN_c07130ec((undefined4 *)&DAT_c0701010,(undefined4 *)&DAT_c0701014);
  }
  FUN_c07130ec((undefined4 *)&DAT_c0701018,(undefined4 *)&DAT_c070101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0714164,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c07130c8 FUN_c07130c8 */

/* Boundary evidence: original MIPS .pdata c07130c8..c07130eb. Semantic name remains unreviewed. */

void FUN_c07130c8(void)

{
  FUN_c0712fa8(0,0,1);
  return;
}



/* c07130ec FUN_c07130ec */

/* Boundary evidence: original MIPS .pdata c07130ec..c071313f. Semantic name remains unreviewed. */

void FUN_c07130ec(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0713140 FUN_c0713140 */

/* Boundary evidence: original MIPS .pdata c0713140..c071317b. Semantic name remains unreviewed. */

void FUN_c0713140(void)

{
  FUN_c07130ec((undefined4 *)&DAT_c0701008,(undefined4 *)&DAT_c070100c);
  FUN_c07130ec((undefined4 *)&DAT_c0701000,(undefined4 *)&DAT_c0701004);
  return;
}


