/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 80104488 FUN_80104488 */

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80104488(void)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined4 *puVar2;
  
  setCopReg(0,Cause,0);
  setCopReg(0,EntryHi,0);
  setCopReg(0,Context,0);
  setCopReg(0,EntryLo0,0);
  setCopReg(0,EntryLo1,0);
  setCopReg(0,PageMask,0);
  setCopReg(0,Count,0);
  setCopReg(0,Wired,0);
  setCopReg(0,Index,0);
  puVar2 = (undefined4 *)&DAT_a1530000;
  iVar1 = 0x2000;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    iVar1 = iVar1 + -0x20;
    puVar2 = puVar2 + 8;
  } while (0 < iVar1);
  _DAT_a15318a4 = 0x81128d6c;
  FUN_80104548(0x81128d6c);
  FUN_80104684(0xa1531800);
  UNRECOVERED_JUMPTABLE = (code *)FUN_801045ec(0x81128d6c);
                    /* WARNING: Could not recover jumptable at 0x80104540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&DAT_a1530000,&UNK_80105530);
  return;
}



/* 80104548 FUN_80104548 */

void FUN_80104548(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    iVar3 = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar3);
      if (puVar2[2] != 0) {
        FUN_80104a98(puVar2[1],*puVar2);
      }
      iVar1 = puVar2[2];
      if (iVar1 != puVar2[3]) {
        FUN_80105364(puVar2[1] + iVar1,0,puVar2[3] - iVar1);
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x10;
    } while (uVar4 < *(uint *)(param_1 + 0x20));
  }
  return;
}



/* 801045ec FUN_801045ec */

int FUN_801045ec(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_1 + 0x54;
  uVar3 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    do {
      iVar1 = FUN_801046a0(*(undefined4 *)(iVar2 + 0x10),"kernel.dll");
      if (iVar1 == 0) {
        iVar2 = *(int *)(iVar2 + 0x14);
        if (iVar2 == 0) {
          return 0;
        }
        return *(int *)(iVar2 + 8) + *(int *)(iVar2 + 4);
      }
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x20;
    } while (uVar3 < *(uint *)(param_1 + 0x10));
  }
  return 0;
}



/* 80104684 FUN_80104684 */

void FUN_80104684(int param_1)

{
  *(undefined4 *)(param_1 + 0xd4) = 0x8112b080;
  *(undefined4 *)(param_1 + 200) = 0x8112b000;
  return;
}



/* 801046a0 FUN_801046a0 */

void FUN_801046a0(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = *param_1;
  while( true ) {
    iVar2 = FUN_801054fc((int)cVar1);
    iVar3 = FUN_801054fc((int)*param_2);
    if ((iVar2 != iVar3) || (*param_2 == '\0')) break;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    param_2 = param_2 + 1;
  }
  return;
}



/* 80104a98 FUN_80104a98 */

int * FUN_80104a98(int *param_1,int *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  piVar5 = param_1;
  if (7 < (int)param_3) {
    if ((((uint)param_2 ^ (uint)param_1) & 3) == 0) {
      uVar3 = -(int)param_2 & 3;
      param_3 = param_3 - uVar3;
      if (uVar3 != 0) {
        uVar10 = (uint)param_2 & 3;
        puVar1 = (uint *)((int)param_2 - uVar10);
        param_2 = (int *)((int)param_2 + uVar3);
        uVar2 = (uint)param_1 & 3;
        *(uint *)((int)param_1 - uVar2) =
             *(uint *)((int)param_1 - uVar2) & 0xffffffffU >> (4 - uVar2) * 8 |
             (*puVar1 >> uVar10 * 8) << uVar2 * 8;
        piVar5 = (int *)((int)param_1 + uVar3);
      }
      uVar3 = param_3 & 0x1f;
      if (param_3 != uVar3) {
        piVar6 = (int *)((param_3 - uVar3) + (int)param_2);
        piVar7 = piVar5;
        do {
          iVar8 = *param_2;
          iVar9 = param_2[1];
          iVar11 = param_2[2];
          iVar12 = param_2[3];
          iVar13 = param_2[4];
          iVar14 = param_2[5];
          iVar15 = param_2[6];
          iVar4 = param_2[7];
          param_2 = param_2 + 8;
          *piVar7 = iVar8;
          piVar7[1] = iVar9;
          piVar7[2] = iVar11;
          piVar7[3] = iVar12;
          piVar7[4] = iVar13;
          piVar7[5] = iVar14;
          piVar7[6] = iVar15;
          piVar5 = piVar7 + 8;
          piVar7[7] = iVar4;
          piVar7 = piVar5;
          param_3 = uVar3;
        } while (param_2 != piVar6);
      }
      uVar3 = param_3 & 3;
      if (param_3 != uVar3) {
        piVar6 = (int *)((param_3 - uVar3) + (int)param_2);
        piVar7 = piVar5;
        do {
          iVar4 = *param_2;
          param_2 = param_2 + 1;
          piVar5 = piVar7 + 1;
          *piVar7 = iVar4;
          piVar7 = piVar5;
          param_3 = uVar3;
        } while (param_2 != piVar6);
      }
    }
    else {
      uVar3 = -(int)param_1 & 3;
      piVar7 = param_1;
      if (uVar3 != 0) {
        iVar4 = *param_2;
        param_2 = (int *)((int)param_2 + uVar3);
        uVar10 = (uint)param_1 & 3;
        *(uint *)((int)param_1 - uVar10) =
             *(uint *)((int)param_1 - uVar10) & 0xffffffffU >> (4 - uVar10) * 8 |
             iVar4 << uVar10 * 8;
        piVar7 = (int *)((int)param_1 + uVar3);
      }
      uVar10 = param_3 - uVar3 & 3;
      piVar6 = (int *)(((param_3 - uVar3) - uVar10) + (int)param_2);
      do {
        iVar4 = *param_2;
        param_2 = param_2 + 1;
        piVar5 = piVar7 + 1;
        *piVar7 = iVar4;
        piVar7 = piVar5;
        param_3 = uVar10;
      } while (param_2 != piVar6);
    }
  }
  piVar7 = (int *)(param_3 + (int)param_2);
  if (0 < (int)param_3) {
    do {
      iVar4 = *param_2;
      param_2 = (int *)((int)param_2 + 1);
      *(char *)piVar5 = (char)iVar4;
      piVar5 = (int *)((int)piVar5 + 1);
    } while (param_2 != piVar7);
  }
  return param_1;
}



/* 80105364 FUN_80105364 */

undefined4 * FUN_80105364(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar1 = CONCAT11(param_2,param_2);
  uVar3 = CONCAT22(uVar1,uVar1);
  uVar4 = -(int)param_1 & 3;
  uVar5 = param_3 - uVar4;
  puVar2 = param_1;
  if ((int)uVar5 < 1) {
LAB_801054dc:
    puVar8 = puVar2;
    if (param_3 != 0) {
      do {
        puVar9 = (undefined4 *)((int)puVar8 + 1);
        *(undefined1 *)puVar8 = param_2;
        puVar8 = puVar9;
      } while (puVar9 != (undefined4 *)((int)puVar2 + param_3));
    }
    return param_1;
  }
  if (uVar4 != 0) {
    uVar7 = (uint)param_1 & 3;
    if (uVar7 == 0) {
      *param_1 = uVar3;
    }
    else if (uVar7 == 1) {
      *(undefined1 *)param_1 = param_2;
      *(short *)((int)param_1 + 1) = (short)((uint)uVar3 >> 8);
    }
    else {
      *(undefined1 *)param_1 = param_2;
      if (uVar7 == 2) {
        *(undefined2 *)param_1 = uVar1;
      }
    }
    puVar2 = (undefined4 *)((int)param_1 + uVar4);
  }
  while( true ) {
    uVar4 = uVar5 & 0x1f;
    uVar7 = uVar5 - uVar4;
    puVar8 = (undefined4 *)((int)puVar2 + uVar7);
    if (uVar7 == 0) goto LAB_801054b8;
    if (((uint)puVar2 & 4) == 0) break;
    *puVar2 = uVar3;
    puVar2 = puVar2 + 1;
    uVar5 = (uVar4 + uVar7) - 4;
  }
  if ((uVar7 & 0x20) == 0) goto LAB_80105470;
  *puVar2 = uVar3;
  puVar2[1] = uVar3;
  puVar2[2] = uVar3;
  puVar2[3] = uVar3;
  puVar2[4] = uVar3;
  puVar2[5] = uVar3;
  puVar2[6] = uVar3;
  puVar2[7] = uVar3;
  for (puVar2 = puVar2 + 8; uVar5 = uVar4, puVar2 != puVar8; puVar2 = puVar2 + 0x10) {
LAB_80105470:
    *puVar2 = uVar3;
    puVar2[1] = uVar3;
    puVar2[2] = uVar3;
    puVar2[3] = uVar3;
    puVar2[4] = uVar3;
    puVar2[5] = uVar3;
    puVar2[6] = uVar3;
    puVar2[7] = uVar3;
    puVar2[8] = uVar3;
    puVar2[9] = uVar3;
    puVar2[10] = uVar3;
    puVar2[0xb] = uVar3;
    puVar2[0xc] = uVar3;
    puVar2[0xd] = uVar3;
    puVar2[0xe] = uVar3;
    puVar2[0xf] = uVar3;
  }
LAB_801054b8:
  iVar6 = uVar5 - (uVar5 & 3);
  puVar9 = (undefined4 *)((int)puVar2 + iVar6);
  puVar8 = puVar2;
  param_3 = uVar5;
  if (iVar6 != 0) {
    do {
      puVar2 = puVar8 + 1;
      *puVar8 = uVar3;
      puVar8 = puVar2;
      param_3 = uVar5 & 3;
    } while (puVar2 != puVar9);
  }
  goto LAB_801054dc;
}



/* 801054fc FUN_801054fc */

int FUN_801054fc(int param_1)

{
  if ((0x40 < param_1) && (param_1 < 0x5b)) {
    param_1 = param_1 + 0x20;
  }
  return param_1;
}



/* 80105584 FUN_80105584 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80105584(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  (**(code **)(_DAT_8152e958 + 8))(param_1,&local_res4);
  return;
}



/* 801055bc FUN_801055bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801055bc(void)

{
  (**(code **)(_DAT_8152e958 + 0x10))();
  return;
}



/* 801055e4 FUN_801055e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801055e4(void)

{
  (**(code **)(_DAT_8152e958 + 0x20))();
  return;
}



/* 8010560c FUN_8010560c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010560c(void)

{
  (**(code **)(_DAT_8152e958 + 0x24))();
  return;
}



/* 80105634 FUN_80105634 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80105634(void)

{
  (**(code **)(_DAT_8152e958 + 0x18))();
  return;
}



/* 8010565c FUN_8010565c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010565c(void)

{
  (**(code **)(_DAT_8152e958 + 0x28))();
  return;
}



/* 80105684 FUN_80105684 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80105684(void)

{
  (**(code **)(_DAT_8152e958 + 0x34))();
  return;
}



/* 801056ac FUN_801056ac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801056ac(void)

{
  (**(code **)(_DAT_8152e958 + 0x38))();
  return;
}



/* 801056d4 FUN_801056d4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801056d4(void)

{
  (**(code **)(_DAT_8152e958 + 0x3c))();
  return;
}



/* 801056fc FUN_801056fc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801056fc(void)

{
  (**(code **)(_DAT_8152e958 + 0x60))();
  return;
}



/* 80105724 FUN_80105724 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80105724(void)

{
  (**(code **)(_DAT_8152e958 + 0x58))();
  return;
}



/* 80105770 FUN_80105770 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80105770(void)

{
  (**(code **)(_DAT_8152e958 + 0x68))();
  return;
}



/* 801057a4 FUN_801057a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801057a4(void)

{
  (**(code **)(_DAT_8152e958 + 0x84))();
  return;
}



/* 801057cc FUN_801057cc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801057cc(void)

{
  (**(code **)(_DAT_8152e958 + 0x94))();
  return;
}



/* 801057f4 FUN_801057f4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801057f4(void)

{
  (**(code **)(_DAT_8152e958 + 0xa8))();
  return;
}



/* 8010581c FUN_8010581c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010581c(void)

{
  (**(code **)(_DAT_8152e958 + 0xac))();
  return;
}



/* 80105844 FUN_80105844 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80105844(undefined4 param_1)

{
  undefined4 local_18 [2];
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = _DAT_8112b210;
  local_10 = 0;
  local_18[0] = param_1;
  (**(code **)(_DAT_8152e958 + 0xb4))(local_18);
  FUN_8010b76c(local_c);
  return;
}



/* 80105888 FUN_80105888 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80105888(void)

{
  (**(code **)(_DAT_8152e958 + 0xb8))();
  return;
}



/* 801058b0 FUN_801058b0 */

undefined4 FUN_801058b0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x5800);
}



/* 801058b8 FUN_801058b8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801058b8(void)

{
  (**(code **)(_DAT_8152e958 + 0xbc))();
  return;
}



/* 801058e0 FUN_801058e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_801058e0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OEMIoControl(0x%x, 0x%x, %d, 0x%x, %d, 0x%x)\r\n",param_1,param_2,param_3,
                 param_4,param_5,param_6);
  }
  if ((_DAT_8152ca4c == 0) && (param_1 == 0x10100b4)) {
    FUN_80105634(0x8152ca50);
    _DAT_8152ca4c = 1;
  }
  iVar2 = 0;
  iVar1 = 0;
  do {
    if (*(uint *)((int)&DAT_80101150 + iVar1) == param_1) break;
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0xc;
  } while ((&PTR_FUN_80101158)[iVar2 * 3] != (undefined *)0x0);
  if ((&PTR_FUN_80101158)[iVar2 * 3] == (undefined *)0x0) {
    FUN_801055bc(0x32);
    if ((_DAT_8112ca24 & 0x1000) != 0) {
      FUN_80105584(L"OEMIoControl: Unsupported Code 0x%x - device 0x%04x func %d\r\n",param_1,
                   param_1 >> 0x10,param_1 >> 2 & 0xfff);
    }
  }
  else {
    if ((_DAT_8152ca4c != 0) && ((*(uint *)(&UNK_80101154 + iVar2 * 0xc) & 1) == 0)) {
      FUN_801055e4(0x8152ca50);
    }
    uVar3 = (*(code *)(&PTR_FUN_80101158)[iVar2 * 3])
                      (param_1,param_2,param_3,param_4,param_5,param_6);
    if ((_DAT_8152ca4c != 0) && ((*(uint *)(&UNK_80101154 + iVar2 * 0xc) & 1) == 0)) {
      FUN_8010560c(0x8152ca50);
    }
  }
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OEMIoControl(rc = %d)\r\n",uVar3);
  }
  return uVar3;
}



/* 80105b24 FUN_80105b24 */

undefined4 FUN_80105b24(undefined4 param_1,undefined2 *param_2)

{
  *param_2 = 1;
  param_2[1] = 1;
  *(undefined4 *)(param_2 + 6) = 0x20000;
  param_2[10] = 0xff;
  param_2[0x14] = 0xff;
  *(undefined4 *)(param_2 + 0xe) = 0x1400000;
  *(undefined4 *)(param_2 + 2) = 0x800000;
  *(undefined4 *)(param_2 + 4) = 0xa00000;
  *(undefined4 *)(param_2 + 8) = 0x10000;
  param_2[0xb] = 0xf7;
  *(undefined4 *)(param_2 + 0xc) = 0xa00000;
  *(undefined4 *)(param_2 + 0x10) = 0x10000;
  *(undefined4 *)(param_2 + 0x12) = 0x10000;
  param_2[0x15] = 0xfb;
  FUN_80105584(L"[SF][OAL] loader pool:%d, file pool:%d\r\n[SF][OAL] no OEMIdle\r\n",0x800000);
  return 1;
}



/* 80105ba8 FUN_80105ba8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_80105ba8(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoCtlHalInitRTC(...)\r\n");
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if ((param_2 == 0) || (param_3 < 0x10)) {
    if ((_DAT_8112ca24 & 1) != 0) {
      FUN_80105584(L"ERROR: OALIoCtlHalInitRTC: INVALID PARAMETER\r\n");
    }
  }
  else {
    uVar1 = FUN_80108948(param_2);
  }
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIoCtlHalInitRTC(rc = %d)\r\n",uVar1);
  }
  return uVar1;
}



/* 80105c98 FUN_80105c98 */

undefined4 FUN_80105c98(void)

{
  FUN_801055bc(0x32);
  return 0;
}



/* 80105cb8 FUN_80105cb8 */

undefined4 FUN_80105cb8(void)

{
  FUN_801055bc(0x32);
  return 0;
}



/* 80105cd8 FUN_80105cd8 */

undefined4 FUN_80105cd8(void)

{
  FUN_801055bc(0x32);
  return 0;
}



/* 80105cf8 FUN_80105cf8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80105cf8(void)

{
  FUN_80105584(L"OALIoCtlHalReboot\r\n");
  _DAT_b0900018 = 0x5741524d;
  if ((*(int *)(_DAT_8112b218 + 8) == 0x544f4f42) && (*(int *)(_DAT_8112b218 + 0x88) != 0)) {
    _DAT_8112b21c = entry;
  }
  else {
    _DAT_b090001c = entry;
    _DAT_8112b21c = entry;
    FUN_80105584(L"Soft Reset\r\n");
  }
  (*_DAT_8112b21c)();
  return 1;
}



/* 80105da0 FUN_80105da0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80105da0(void)

{
  if ((_DAT_8112ca24 & 4) != 0) {
    FUN_80105584(L"+OALIoCtlHalPostInit\r\n");
  }
  if ((_DAT_8112ca24 & 4) != 0) {
    FUN_80105584(L"-OALIoCtlHalPostInit\r\n");
  }
  return 1;
}



/* 80105e00 FUN_80105e00 */

undefined4
FUN_80105e00(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  
  *param_6 = 4;
  if (param_4 == (undefined4 *)0x0) {
    return 1;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 1;
  }
  switch(*param_2) {
  case 0:
    *param_4 = 0xa070004;
    return 1;
  case 1:
    uVar1 = 0x8070004;
    break;
  case 2:
    uVar1 = 0x4f54271a;
    goto LAB_80105e80;
  case 3:
    uVar1 = 0xa0ef002b;
    break;
  case 4:
    uVar1 = 0x228cd050;
    goto LAB_80105e80;
  case 5:
    uVar1 = 0x5f60ce8;
    break;
  case 6:
    uVar1 = 0x13f08030;
LAB_80105e80:
    *param_4 = uVar1;
    return 1;
  case 7:
    uVar1 = 0x5030776;
    break;
  default:
    *param_6 = 0;
    return 0;
  }
  *param_4 = uVar1;
  return 1;
}



/* 80105ed8 FUN_80105ed8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80105ed8(void)

{
  undefined4 *in_a3;
  uint in_stack_00000010;
  undefined4 *in_stack_00000014;
  
  if ((in_a3 == (undefined4 *)0x0) || (in_stack_00000010 < 0x30)) {
    *in_stack_00000014 = 0;
  }
  else {
    in_a3[10] = cop0_reg22;
    *in_a3 = PRId;
    FUN_80105364(in_a3 + 2,0,0x20);
    in_a3[2] = _DAT_b0002000;
    in_a3[3] = _DAT_b0002004;
    in_a3[4] = _DAT_b0002008;
    *in_stack_00000014 = 0x30;
  }
  return 1;
}



/* 80105ffc FUN_80105ffc */

undefined4 FUN_80105ffc(void)

{
  undefined4 uVar1;
  undefined4 *in_a3;
  undefined4 *in_stack_00000014;
  
  uVar1 = FUN_8010b27c();
  *in_a3 = uVar1;
  *in_stack_00000014 = 4;
  return 1;
}



/* 80106034 FUN_80106034 */

undefined4 FUN_80106034(void)

{
  undefined4 uVar1;
  undefined4 *in_a3;
  undefined4 *in_stack_00000014;
  
  uVar1 = FUN_8010b2a4();
  *in_a3 = uVar1;
  *in_stack_00000014 = 4;
  return 1;
}



/* 8010606c FUN_8010606c */

undefined4
FUN_8010606c(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_8010b2f0();
  uVar2 = FUN_8010b4e4(*param_2,param_2[1],param_2[2],param_2[3]);
  FUN_8010b308(uVar1);
  *param_4 = uVar2;
  *param_6 = 4;
  return 1;
}



/* 801060dc FUN_801060dc */

undefined4
FUN_801060dc(undefined4 param_1,int *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if ((param_2 != (int *)0x0) && (0xf < param_3)) {
    uVar2 = FUN_8010b2f0();
    iVar1 = *param_2 * 0xc;
    puVar3 = (undefined4 *)(iVar1 + -0x4effd000);
    if (param_2[1] == 0) {
      *(undefined4 *)(iVar1 + -0x4effcff8) = 0xf;
      SYNC(0);
      *puVar3 = 0;
      SYNC(0);
      *(undefined4 *)(iVar1 + -0x4effcffc) = 2;
      SYNC(0);
      *(undefined4 *)(iVar1 + -0x4effcffc) = 1;
      SYNC(0);
      *(undefined4 *)(iVar1 + -0x4effcff8) = 0;
      SYNC(0);
    }
    else {
      *(undefined4 *)(iVar1 + -0x4effcffc) = 3;
      SYNC(0);
      *puVar3 = 0x1fffffe;
      *(undefined4 *)(iVar1 + -0x4effcff8) = 1;
      *(undefined4 *)(iVar1 + -0x4effcff8) = 3;
      *(undefined4 *)(iVar1 + -0x4effcff8) = 7;
      *(undefined4 *)(iVar1 + -0x4effcff8) = 0xf;
      SYNC(0);
      *puVar3 = 0x1ffffff;
      SYNC(0);
      *(undefined4 *)(iVar1 + -0x4effcffc) = 2;
      SYNC(0);
      *(undefined4 *)(iVar1 + -0x4effcff8) = 0x1f;
      SYNC(0);
    }
    FUN_8010b308(uVar2);
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  return 1;
}



/* 8010626c FUN_8010626c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8010626c(undefined4 param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_20;
  int local_1c;
  uint local_18;
  int local_14;
  
  FUN_8010851c(&local_20);
  FUN_8010851c(&local_18);
  if ((local_14 < local_1c) || ((local_1c == local_14 && (local_18 <= local_20)))) {
    *(uint *)(_DAT_8152ca40 * 4 + -0x7eed35c0) = local_20;
    *(int *)((_DAT_8152ca40 + 1) * 4 + -0x7eed35c0) = local_1c;
  }
  else {
    *(uint *)(_DAT_8152ca40 * 4 + -0x7eed35c0) = local_18;
    *(int *)((_DAT_8152ca40 + 1) * 4 + -0x7eed35c0) = local_14;
  }
  iVar3 = _DAT_8152ca40 + 2;
  _DAT_8152ca40 = _DAT_8152ca40 + 3;
  *(undefined4 *)(iVar3 * 4 + -0x7eed35c0) = *param_2;
  uVar2 = FUN_801058b0(8);
  iVar3 = _DAT_8152ca40 * 4;
  _DAT_8152ca40 = _DAT_8152ca40 + 1;
  bVar1 = 0xfffff < _DAT_8152ca40;
  *(undefined4 *)(iVar3 + -0x7eed35c0) = uVar2;
  if (bVar1) {
    _DAT_8152ca40 = 0;
  }
  return 1;
}



/* 80106390 FUN_80106390 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80106390(void)

{
  undefined4 in_a3;
  undefined4 *in_stack_00000014;
  
  FUN_80105584(L"OALIoCtlReadEv: Set index\r\n");
  *in_stack_00000014 = _DAT_8152ca40;
  FUN_80105584(L"OALIoCtlReadEv: Copy\r\n");
  FUN_80104a98(in_a3,0x8112ca40,0x400000);
  return 1;
}



/* 801063f0 FUN_801063f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_801063f0(void)

{
  bool bVar1;
  
  _DAT_8152e960 = FUN_8010b3a4();
  *(undefined4 *)(_DAT_8112b238 + 0x28) = _DAT_8152d038;
  SYNC(0);
  _DAT_8152e564 = _DAT_8152e564 + 1;
  bVar1 = _DAT_8152e564 != 0x2b;
  if (bVar1) {
    *(int *)(_DAT_8152e958 + 200) = *(int *)(_DAT_8152e958 + 200) + 1;
    _DAT_8152e654 = _DAT_8152e654 + (uint)(_DAT_8152e650 + _DAT_8152e95c < _DAT_8152e650);
    _DAT_8152e650 = _DAT_8152e650 + _DAT_8152e95c;
  }
  else {
    _DAT_8152e564 = 0;
  }
  return bVar1;
}



/* 801064e0 FUN_801064e0 */

undefined4 FUN_801064e0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_8010b3c4();
  FUN_8010b3cc(uVar1);
  return 0;
}



/* 80106508 FUN_80106508 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80106508(void)

{
  int iVar1;
  int local_1c;
  uint local_18;
  int local_10;
  
  local_18 = *(uint *)(_DAT_8112b238 + 0x30);
  if (local_18 == 0x7f) {
    FUN_80105584(L"SPURIOUS INRQ\r\n");
  }
  if (local_18 == 0x54) {
    local_10 = FUN_801063f0();
  }
  else {
    if (local_18 == 0x4b) {
      iVar1 = FUN_8010b560(*(undefined4 *)(_DAT_8112b234 + 0x1004));
      *(undefined4 *)(_DAT_8112b234 + iVar1 * 0x100 + 0x10) = 0;
      local_18 = iVar1 + 0xa0;
    }
    iVar1 = *(int *)(local_18 * 8 + -0x7ead359c);
    _DAT_8152e560 = _DAT_8152e560 + 1;
    *(undefined4 *)(_DAT_8112b238 + 0x50) = *(undefined4 *)(iVar1 * 0x38 + -0x7ead3008);
    *(undefined4 *)(_DAT_8112b238 + 0x54) = *(undefined4 *)(iVar1 * 0x38 + -0x7ead3004);
    *(undefined4 *)(_DAT_8112b238 + 0x58) = *(undefined4 *)(iVar1 * 0x38 + -0x7ead3000);
    *(undefined4 *)(_DAT_8112b238 + 0x5c) = *(undefined4 *)(iVar1 * 0x38 + -0x7ead2ffc);
    SYNC(0);
    *(undefined4 *)(_DAT_8112b238 + 0x20) = *(undefined4 *)(iVar1 * 0x38 + -0x7ead3008);
    *(undefined4 *)(_DAT_8112b238 + 0x24) = *(undefined4 *)(iVar1 * 0x38 + -0x7ead3004);
    *(undefined4 *)(_DAT_8112b238 + 0x28) = *(undefined4 *)(iVar1 * 0x38 + -0x7ead3000);
    *(undefined4 *)(_DAT_8112b238 + 0x2c) = *(undefined4 *)(iVar1 * 0x38 + -0x7ead2ffc);
    SYNC(0);
    *(uint *)(_DAT_8112b234 + 0x100c) =
         *(uint *)(_DAT_8112b234 + 0x100c) & ~*(uint *)(iVar1 * 0x38 + -0x7ead2ff4);
    local_1c = FUN_801056d4(local_18 & 0xff);
    if (local_1c == 3) {
      local_1c = *(int *)(local_18 * 8 + -0x7ead359c);
    }
    local_10 = local_1c;
  }
  return local_10;
}



/* 801067f8 FUN_801067f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801067f8(uint param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  
  local_18 = 1;
  if (param_1 < 0x49) {
    if (*(int *)(param_1 * 0x38 + -0x7ead2ff4) != 0) {
      uVar1 = FUN_8010b2f0();
      *(uint *)(_DAT_8112b234 + 0x100c) =
           *(uint *)(_DAT_8112b234 + 0x100c) | *(uint *)(param_1 * 0x38 + -0x7ead2ff4);
      FUN_8010b308(uVar1);
    }
    *(undefined4 *)(_DAT_8112b238 + 0x40) = *(undefined4 *)(param_1 * 0x38 + -0x7ead3008);
    *(undefined4 *)(_DAT_8112b238 + 0x44) = *(undefined4 *)(param_1 * 0x38 + -0x7ead3004);
    *(undefined4 *)(_DAT_8112b238 + 0x48) = *(undefined4 *)(param_1 * 0x38 + -0x7ead3000);
    *(undefined4 *)(_DAT_8112b238 + 0x4c) = *(undefined4 *)(param_1 * 0x38 + -0x7ead2ffc);
    SYNC(0);
  }
  else {
    FUN_80105584(L"OEMInterruptEnable::Invalid SYSINTR\r\n");
    local_18 = 0;
  }
  return local_18;
}



/* 8010699c FUN_8010699c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010699c(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 < 0x49) {
    iVar1 = param_1 * 0x38;
    uVar3 = *(uint *)(iVar1 + -0x7ead2ff4);
    if (uVar3 != 0) {
      FUN_80105584(L"OEMInterruptDisable:: DDMA:mask%x, inten:%x\r\n",uVar3,
                   *(undefined4 *)(_DAT_8112b234 + 0x100c));
      uVar2 = FUN_8010b2f0();
      *(uint *)(_DAT_8112b234 + 0x100c) =
           ~*(uint *)(iVar1 + -0x7ead2ff4) & *(uint *)(_DAT_8112b234 + 0x100c);
      FUN_8010b308(uVar2);
    }
    *(undefined4 *)(_DAT_8112b238 + 0x50) = *(undefined4 *)(iVar1 + -0x7ead3008);
    *(undefined4 *)(_DAT_8112b238 + 0x54) = *(undefined4 *)(iVar1 + -0x7ead3004);
    *(undefined4 *)(_DAT_8112b238 + 0x58) = *(undefined4 *)(iVar1 + -0x7ead3000);
    *(undefined4 *)(_DAT_8112b238 + 0x5c) = *(undefined4 *)(iVar1 + -0x7ead2ffc);
  }
  return;
}



/* 80106a98 FUN_80106a98 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80106a98(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 0x49) {
    iVar1 = param_1 * 0x38;
    if (*(uint *)(iVar1 + -0x7ead2ff4) != 0) {
      uVar2 = FUN_8010b2f0();
      *(uint *)(_DAT_8112b234 + 0x100c) =
           *(uint *)(iVar1 + -0x7ead2ff4) | *(uint *)(_DAT_8112b234 + 0x100c);
      FUN_8010b308(uVar2);
    }
    *(undefined4 *)(_DAT_8112b238 + 0x40) = *(undefined4 *)(iVar1 + -0x7ead3008);
    *(undefined4 *)(_DAT_8112b238 + 0x44) = *(undefined4 *)(iVar1 + -0x7ead3004);
    *(undefined4 *)(_DAT_8112b238 + 0x48) = *(undefined4 *)(iVar1 + -0x7ead3000);
    *(undefined4 *)(_DAT_8112b238 + 0x4c) = *(undefined4 *)(iVar1 + -0x7ead2ffc);
  }
  return;
}



/* 80106b74 FUN_80106b74 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80106b74(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  uint *puVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  
  iVar9 = 0;
  bVar1 = false;
  iVar10 = 0;
  uVar2 = FUN_8010b2f0();
  iVar5 = 0;
  uVar4 = 0;
  do {
    uVar3 = param_3 >> (uVar4 & 0x1f) & 0xff;
    if (((uVar3 != 0) || (iVar5 < 1)) &&
       (iVar10 = iVar10 + 1, *(int *)(uVar3 * 8 + -0x7ead359c) != 0)) {
      bVar1 = true;
    }
    uVar4 = uVar4 + 8;
    iVar5 = iVar5 + 1;
  } while ((int)uVar4 < 0x20);
  if (bVar1) {
    if (iVar10 == 1) {
      iVar5 = param_3 * 8;
      uVar4 = *(uint *)(iVar5 + -0x7ead3598);
      if (uVar4 < 6) {
        iVar10 = 0x10;
        psVar6 = (short *)&DAT_8152d39a;
        do {
          iVar9 = iVar10;
          if (*psVar6 == 0) break;
          psVar6 = psVar6 + 0x1c;
          iVar10 = iVar10 + 1;
          iVar9 = 0;
        } while ((int)psVar6 < -0x7ead2025);
        if (iVar9 != 0) {
          *(uint *)(iVar5 + -0x7ead3598) = uVar4 + 1;
          if (param_3 < 0x80) {
            puVar7 = (uint *)((iVar9 * 0xe + (param_3 >> 5)) * 4 + -0x7ead3008);
            *puVar7 = 1 << (param_3 & 0x1f) | *puVar7;
          }
          pbVar8 = (byte *)(iVar5 + -0x7ead2024);
          *(uint *)(iVar9 * 0x38 + -0x7ead301c) = param_3;
          *(char *)((uint)*pbVar8 + iVar5 + -0x7ead2022) = (char)iVar9;
          *(undefined2 *)(iVar9 * 0x38 + -0x7ead2fe6) = 1;
          *pbVar8 = *pbVar8 + 1;
        }
      }
    }
  }
  else {
    iVar5 = 0x10;
    psVar6 = (short *)&DAT_8152d39a;
    do {
      iVar9 = iVar5;
      if (*psVar6 == 0) break;
      psVar6 = psVar6 + 0x1c;
      iVar5 = iVar5 + 1;
      iVar9 = 0;
    } while ((int)psVar6 < -0x7ead2025);
    if (iVar9 != 0) {
      iVar5 = iVar9 * 0x38;
      iVar10 = 0;
      uVar4 = 0;
      *(undefined2 *)(iVar5 + -0x7ead2fe8) = 0;
      *(uint *)(iVar5 + -0x7ead301c) = param_3;
      do {
        uVar3 = param_3 >> (uVar4 & 0x1f);
        uVar11 = uVar3 & 0xff;
        if ((uVar11 != 0) || (iVar10 < 1)) {
          if (0x7f < uVar11) {
            if ((0x9f < uVar11) && (uVar11 < 0xb0)) {
              *(uint *)(iVar5 + -0x7ead2ff4) =
                   1 << (uVar11 - 0xa0 & 0x1f) | *(uint *)(iVar5 + -0x7ead2ff4);
            }
          }
          else {
            puVar7 = (uint *)((iVar9 * 0xe + (uVar11 >> 5)) * 4 + -0x7ead3008);
            *puVar7 = 1 << (uVar3 & 0x1f) | *puVar7;
          }
          *(int *)(uVar11 * 8 + -0x7ead359c) = iVar9;
          *(undefined4 *)(uVar11 * 8 + -0x7ead3598) = 0;
          if (((param_4 >> (uVar4 & 0x1f) & 0xff) != 0) && (0x7f >= uVar11)) {
            *(uint *)((uVar11 + 0x400) * 4 + _DAT_8112b238) = param_4;
          }
        }
        uVar4 = uVar4 + 8;
        iVar10 = iVar10 + 1;
      } while ((int)uVar4 < 0x20);
      *(undefined2 *)(iVar5 + -0x7ead2fe6) = 1;
    }
  }
  FUN_8010b308(uVar2);
  return iVar9;
}



/* 80106ec4 FUN_80106ec4 */

void FUN_80106ec4(uint param_1)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  
  uVar2 = FUN_8010b2f0();
  if (((0xf < param_1) && (param_1 < 0x49)) && (*(short *)(param_1 * 0x38 + -0x7ead2fe6) != 0)) {
    iVar9 = 0;
    puVar11 = (uint *)(param_1 * 0x38 + -0x7ead301c);
    uVar8 = 0;
    do {
      uVar5 = *puVar11 >> (uVar8 & 0x1f) & 0xff;
      if ((uVar5 != 0) || (iVar9 == 0)) {
        iVar7 = uVar5 * 8;
        piVar10 = (int *)(iVar7 + -0x7ead3598);
        if (*piVar10 == 0) {
          FUN_8010699c(param_1);
          *piVar10 = 0;
          *(undefined4 *)(iVar7 + -0x7ead359c) = 0;
        }
        else {
          pbVar3 = (byte *)(iVar7 + -0x7ead2024);
          bVar4 = *pbVar3 - 1;
          iVar6 = *piVar10 + -1;
          *pbVar3 = bVar4;
          bVar1 = *(byte *)((uint)bVar4 + iVar7 + -0x7ead2022);
          *piVar10 = iVar6;
          if (iVar6 == 0) {
            *(uint *)(iVar7 + -0x7ead359c) = (uint)bVar1;
          }
          else {
            uVar5 = 0;
            if (bVar4 != 0) {
              do {
                if (*(byte *)(iVar7 + -0x7ead2022 + uVar5) == param_1) {
                  *(byte *)(iVar7 + uVar5 + -0x7ead2022) = bVar1;
                  break;
                }
                uVar5 = uVar5 + 1;
              } while (uVar5 < *pbVar3);
            }
          }
        }
      }
      uVar8 = uVar8 + 8;
      iVar9 = iVar9 + 1;
    } while (uVar8 < 0x20);
    FUN_80105364(puVar11,0,0x38);
  }
  FUN_8010b308(uVar2);
  return;
}



/* 80107088 FUN_80107088 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80107088(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  _DAT_8152eb7c = *(undefined4 *)(_DAT_8112b238 + 0x80);
  _DAT_8152eb80 = *(undefined4 *)(_DAT_8112b238 + 0x84);
  puVar3 = (undefined4 *)(_DAT_8112b238 + 0x1000);
  _DAT_8152eb84 = *(undefined4 *)(_DAT_8112b238 + 0x88);
  uVar2 = 0;
  _DAT_8152eb88 = *(undefined4 *)(_DAT_8112b238 + 0x8c);
  _DAT_8152eb8c = *(undefined4 *)(_DAT_8112b238 + 0x40);
  _DAT_8152eb90 = *(undefined4 *)(_DAT_8112b238 + 0x44);
  _DAT_8152eb94 = *(undefined4 *)(_DAT_8112b238 + 0x48);
  _DAT_8152eb98 = *(undefined4 *)(_DAT_8112b238 + 0x4c);
  _DAT_8152eb9c = *(undefined4 *)(_DAT_8112b238 + 0x60);
  do {
    puVar1 = (undefined4 *)(&DAT_8152e980 + uVar2);
    uVar2 = uVar2 + 4;
    *puVar1 = *puVar3;
    puVar3 = puVar3 + 1;
  } while (uVar2 < 0x1fc);
  return;
}



/* 8010710c FUN_8010710c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010710c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0x1000;
  do {
    puVar2 = (undefined4 *)(uVar3 + 0x8152d980);
    puVar1 = (undefined4 *)(uVar3 + _DAT_8112b238);
    uVar3 = uVar3 + 4;
    *puVar1 = *puVar2;
  } while (uVar3 < 0x11fc);
  *(undefined4 *)(_DAT_8112b238 + 0x80) = _DAT_8152eb7c;
  *(undefined4 *)(_DAT_8112b238 + 0x84) = _DAT_8152eb80;
  *(undefined4 *)(_DAT_8112b238 + 0x88) = _DAT_8152eb84;
  *(undefined4 *)(_DAT_8112b238 + 0x8c) = _DAT_8152eb88;
  *(undefined4 *)(_DAT_8112b238 + 0x40) = _DAT_8152eb8c;
  *(undefined4 *)(_DAT_8112b238 + 0x44) = _DAT_8152eb90;
  *(undefined4 *)(_DAT_8112b238 + 0x48) = _DAT_8152eb94;
  *(undefined4 *)(_DAT_8112b238 + 0x4c) = _DAT_8152eb98;
  *(undefined4 *)(_DAT_8112b238 + 0x60) = _DAT_8152eb9c;
  return;
}



/* 801071b4 FUN_801071b4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_801071b4(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,uint param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoCtlHalRequestIrq\r\n");
  }
  if ((((param_2 == 0) || (param_3 != 0x14)) || (param_4 == (undefined4 *)0x0)) || (param_5 < 4)) {
    FUN_801055bc(0x57);
    if ((_DAT_8112ca24 & 2) != 0) {
      FUN_80105584(L"WARN: IOCTL_HAL_REQUEST_IRQ invalid parameters\r\n");
    }
  }
  else {
    uVar1 = 1;
    *param_4 = *(undefined4 *)(param_2 + 0x10);
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 4;
    }
  }
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIoCtlHalRequestSysIntr(rc = %d)\r\n",uVar1);
  }
  return uVar1;
}



/* 801072ec FUN_801072ec */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801072ec(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIntrRequestSysIntr(%d, 0x%08x, 0x%08x irq:0x%08x)\r\n",param_1,param_2,
                 param_3,*param_2);
  }
  uVar1 = FUN_80106b74(0,0,*param_2,0);
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIntrRequestSysIntr(sysIntr = %d)\r\n",uVar1);
  }
  return uVar1;
}



/* 80107398 FUN_80107398 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80107398(undefined4 param_1)

{
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIntrReleaseSysIntr(%d)\r\n",param_1);
  }
  FUN_80106ec4(param_1);
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIntrReleaseSysIntr\r\n");
  }
  return 1;
}



/* 80107564 FUN_80107564 */

void FUN_80107564(void)

{
  FUN_80106508();
  return;
}



/* 80107580 FUN_80107580 */

void FUN_80107580(void)

{
  FUN_80106508();
  return;
}



/* 8010759c FUN_8010759c */

void FUN_8010759c(void)

{
  FUN_80106508();
  return;
}



/* 801075b8 FUN_801075b8 */

void FUN_801075b8(void)

{
  FUN_80106508();
  return;
}



/* 801075d4 FUN_801075d4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801075d4(void)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint *puVar4;
  
  FUN_80108dc8(L"+OEMInterruptInit\r\n");
  FUN_80105364(0x8152cfe4,0,0xff8);
  uVar2 = 0;
  do {
    *(undefined4 *)(uVar2 + 0x8152ca64) = 0;
    *(undefined4 *)(uVar2 + 0x8152ca68) = 0;
    puVar3 = (undefined1 *)(uVar2 + 0x8152dfdc);
    uVar2 = uVar2 + 8;
    *puVar3 = 0;
  } while (uVar2 < 0x579);
  _DAT_8152d01c = 0x54;
  _DAT_8152d038 = 0x100000;
  _DAT_8152d052 = 1;
  _DAT_8152d364 = 0x55;
  _DAT_8152d380 = 0x200000;
  _DAT_8152cd0c = 0x10;
  _DAT_8152d39a = 1;
  _DAT_8152d2bc = 0x53;
  _DAT_8152d2d8 = 0x80000;
  _DAT_8152ccfc = 0xd;
  _DAT_8152d2f2 = 1;
  _DAT_8152d214 = 0x54;
  _DAT_8152d230 = 0x100000;
  _DAT_8152cd04 = 10;
  _DAT_8152d24a = 1;
  iVar1 = FUN_80105684(0,FUN_80107564);
  if ((((iVar1 != 0) && (iVar1 = FUN_80105684(1,FUN_80107580), iVar1 != 0)) &&
      (iVar1 = FUN_80105684(2,FUN_8010759c), iVar1 != 0)) &&
     (iVar1 = FUN_80105684(3,FUN_801075b8), iVar1 != 0)) {
    FUN_80105684(5,FUN_801064e0);
  }
  FUN_80108dc8(L"+OEMInterruptInit Disable All...\r\n");
  *(undefined4 *)(_DAT_8112b238 + 0x50) = 0xffffffff;
  *(undefined4 *)(_DAT_8112b238 + 0x54) = 0xffffffff;
  *(undefined4 *)(_DAT_8112b238 + 0x58) = 0xffffffff;
  *(undefined4 *)(_DAT_8112b238 + 0x5c) = 0xffffffff;
  *(undefined4 *)(_DAT_8112b238 + 0x60) = 10;
  *(undefined4 *)(_DAT_8112b238 + 0x60) = 0xa00;
  FUN_80108dc8(L"+OEMInterruptInit Parsing Platform GPINT Configuration table...");
  for (puVar4 = (uint *)&DAT_8112b23c; *puVar4 != 0xffffffff; puVar4 = puVar4 + 4) {
    if (*puVar4 < 0x80) {
      *(uint *)((*puVar4 + 0x400) * 4 + _DAT_8112b238) = puVar4[3];
    }
    if (puVar4[2] != 0) {
      *(int *)((((int)*puVar4 >> 5) + 0x10) * 4 + _DAT_8112b238) = 1 << (*puVar4 & 0x1f);
    }
  }
  FUN_80108dc8(L"\r\nDONE\r\n");
  FUN_80108dc8(L"-OEMInterruptInit\r\n");
  return;
}



/* 80107818 FUN_80107818 */

void FUN_80107818(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_801067f8(param_1,0,0);
  }
  else {
    FUN_8010699c();
  }
  return;
}



/* 80107850 FUN_80107850 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_80107850(undefined4 param_1,int *param_2,uint param_3,int *param_4,uint param_5,
            undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar5 = param_3 >> 2;
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoCtlHalRequestSysIntr\r\n");
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 4;
  }
  if (((param_2 == (int *)0x0) || (uVar5 == 0)) || ((param_3 & 3) != 0)) {
LAB_801079bc:
    FUN_801055bc(0x57);
    uVar2 = 0x49d;
  }
  else {
    if (param_4 == (int *)0x0) {
      if (param_6 != (undefined4 *)0x0) goto LAB_801079bc;
    }
    else if (3 < param_5) {
      if ((uVar5 < 2) || (*param_2 != -1)) {
        if (uVar5 == 1) {
          iVar3 = 0;
          iVar1 = 1;
          goto LAB_80107994;
        }
        FUN_801055bc(0x57);
        uVar2 = 0x4c2;
      }
      else {
        if ((2 < uVar5) &&
           (((iVar3 = param_2[1], iVar3 == 8 || (iVar3 == 1)) || ((iVar3 == 2 || (iVar3 == 4)))))) {
          param_2 = param_2 + 2;
          iVar1 = uVar5 - 2;
LAB_80107994:
          uVar4 = 1;
          iVar1 = FUN_801072ec(iVar1,param_2,iVar3);
          *param_4 = iVar1;
          if (iVar1 == -1) {
            uVar4 = 0;
          }
          goto LAB_801079d8;
        }
        FUN_801055bc(0x57);
        uVar2 = 0x4b7;
      }
      goto LAB_801079c8;
    }
    FUN_801055bc(0x7a);
    uVar2 = 0x4a5;
  }
LAB_801079c8:
  uVar4 = 0;
  FUN_80105584(L"WARN: IOCTL_HAL_REQUEST_SYSINTR invalid parameters %d\r\n",uVar2);
LAB_801079d8:
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoCtlHalRequestSysIntr(rc = %d)\r\n",uVar4);
  }
  return uVar4;
}



/* 80107a2c FUN_80107a2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_80107a2c(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoCtlHalRequestSysIntr\r\n");
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if ((param_2 == (undefined4 *)0x0) || (param_3 != 4)) {
    if ((_DAT_8112ca24 & 2) != 0) {
      FUN_80105584(L"WARN: IOCTL_HAL_RELEASE_SYSINTR invalid parameters\r\n");
    }
    FUN_801055bc(0x57);
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_80107398(*param_2);
  }
  if (((_DAT_8112ca24 & 0x4000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoCtlHalRequestSysIntr(rc = %d)\r\n",uVar1);
  }
  return uVar1;
}



/* 80107b1c FUN_80107b1c */

/* Boundary evidence: original MIPS .pdata 80107b1c..8010ad7f. Semantic name remains unreviewed. */

undefined4 FUN_80107b1c(void)

{
  return 0;
}



/* 80107b24 FUN_80107b24 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80107b24(void)

{
  if ((_DAT_8112ca24 & 4) != 0) {
    FUN_80105584(L"+InitClock\r\n");
  }
  FUN_801085cc();
  if ((_DAT_8112ca24 & 4) != 0) {
    FUN_80105584(L"-InitClock\r\n");
  }
  return;
}



/* 80107b88 FUN_80107b88 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80107b88(undefined4 param_1,ushort *param_2)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  short *psVar4;
  short *psVar5;
  short sVar6;
  undefined4 local_38;
  undefined1 auStack_34 [4];
  short local_30 [18];
  undefined4 local_c;
  
  local_c = _DAT_8112b210;
  iVar1 = FUN_80105724(0x80000002,param_1,0,0,0,0,0,&local_38,auStack_34);
  if (iVar1 == 0) {
    iVar1 = 0;
    psVar4 = local_30;
    do {
      uVar3 = *param_2;
      uVar2 = uVar3 >> 4 & 0xf;
      sVar6 = uVar2 + 0x30;
      if (9 < uVar2) {
        sVar6 = uVar2 + 0x37;
      }
      uVar2 = uVar3 & 0xf;
      *psVar4 = sVar6;
      sVar6 = uVar2 + 0x30;
      if (9 < uVar2) {
        sVar6 = uVar2 + 0x37;
      }
      psVar4[1] = sVar6;
      psVar4[2] = 0x2d;
      sVar6 = 0x30;
      if (9 < uVar3 >> 0xc) {
        sVar6 = 0x37;
      }
      psVar4[3] = (uVar3 >> 0xc) + sVar6;
      uVar3 = uVar3 >> 8 & 0xf;
      sVar6 = uVar3 + 0x30;
      if (9 < uVar3) {
        sVar6 = uVar3 + 0x37;
      }
      psVar4[4] = sVar6;
      psVar5 = psVar4 + 5;
      if (iVar1 < 2) {
        *psVar5 = 0x2d;
        psVar5 = psVar4 + 6;
      }
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 1;
      psVar4 = psVar5;
    } while (iVar1 < 3);
    *psVar5 = 0;
    FUN_80105770(local_38,L"NetworkAddress",0,1,local_30,0x24);
    FUN_801056fc(local_38);
  }
  FUN_8010b76c(local_c);
  return;
}



/* 80107ce4 FUN_80107ce4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80107ce4(void)

{
  int iVar1;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined4 local_14;
  
  local_14 = _DAT_8112b210;
  _DAT_8152e56c = 1;
  local_1c = _DAT_bfe00008;
  local_1a = _DAT_bfe0000a;
  local_18 = _DAT_bfe0000c;
  FUN_80107b88(L"Comm\\AU1MAC2\\Parms",&local_1c);
  FUN_80105584(L"pBootArgs->BootVer: %d \r\n",*(undefined4 *)(_DAT_8112b544 + 0x90));
  iVar1 = FUN_80105724(0x80000002,L"LGE\\SystemInfo",0,0,0,0,0,&local_20,&local_1c);
  if (iVar1 == 0) {
    FUN_80105770(local_20,L"Bootversion",0,4,_DAT_8112b544 + 0x90,4);
    FUN_80105770(local_20,L"BootSequence",0,4,_DAT_8112b544 + 0x94,4);
    FUN_801056fc(local_20);
  }
  FUN_8010b76c(local_14);
  return 1;
}



/* 80107e20 FUN_80107e20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80107e20(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  wchar_t *pwVar4;
  
  FUN_8010565c();
  FUN_80108dc8(L"+OEMInit\r\n");
  FUN_80105584(L"Address OEMTlbMissHandler %08X\r\n",&LAB_801043d8);
  FUN_80104a98(&LAB_801043d8,0xa0000000,0x80);
  FUN_80104a98(0xa0000000,&LAB_80104460,0x40);
  *(undefined4 *)(_DAT_8112b20c + 0x114) = 0;
  FUN_80108dc8(L"LGE ULC");
  FUN_80108dc8(&DAT_801022ac);
  *(code **)(_DAT_8112b20c + 0xa0) = FUN_80108f2c;
  *(code **)(_DAT_8112b20c + 0xa4) = FUN_80108fa0;
  *(undefined4 *)(_DAT_8112b20c + 0x50) = 0x14;
  FUN_8010b0a0();
  iVar2 = _DAT_b0900018;
  _DAT_8152eba0 = 4;
  _DAT_b090001c = _DAT_81128d74;
  _DAT_8152e568 = _DAT_b0900018;
  _DAT_b0900018 = 0;
  if (iVar2 == 0x5741524d) {
    pwVar4 = L"Warm Reboot\r\n";
  }
  else {
    pwVar4 = L"Cold Boot\r\n";
    FUN_80105364(_DAT_81128d84,0,0xc);
  }
  FUN_80108dc8(pwVar4);
  FUN_801075d4();
  FUN_80107b24();
  bVar1 = true;
  uVar3 = FUN_8010b404();
  if (uVar3 < 0x2030204) {
    if (uVar3 == 0x2030203) {
      pwVar4 = L"Au1100 BD ";
    }
    else if (uVar3 < 0x1030201) {
      if (uVar3 != 0x1030200) {
        if (uVar3 == 0x30100) {
          pwVar4 = L"Au1000 DA ";
        }
        else if (uVar3 == 0x30201) {
          pwVar4 = L"Au1000 HA ";
        }
        else {
          if (uVar3 != 0x30202) {
            if (uVar3 == 0x30203) {
              pwVar4 = L"Au1000 HC ";
            }
            else {
              if (uVar3 != 0x30204) goto LAB_801081d4;
              pwVar4 = L"Au1000 HD ";
            }
            goto LAB_8010801c;
          }
          pwVar4 = L"Au1000 HB ";
        }
        goto LAB_801081e8;
      }
      pwVar4 = L"Au1500 AB ";
    }
    else if (uVar3 == 0x1030201) {
      pwVar4 = L"Au1500 AC ";
    }
    else if (uVar3 == 0x1030202) {
      pwVar4 = L"Au1500 AD ";
    }
    else if (uVar3 == 0x2030200) {
      pwVar4 = L"Au1100 AB ";
    }
    else if (uVar3 == 0x2030201) {
      pwVar4 = L"Au1100 BA ";
    }
    else {
      if (uVar3 != 0x2030202) goto LAB_801081d4;
      pwVar4 = L"Au1100 BC ";
    }
  }
  else {
    if (0x5030202 < uVar3) {
      if ((((uVar3 == 0x800c8000) || (uVar3 == 0x800c8001)) || (uVar3 == 0x800c8002)) ||
         (uVar3 == 0x800c8003)) {
        pwVar4 = L"Au13xx AA ";
      }
      else {
LAB_801081d4:
        pwVar4 = L"Unknown Au1x00! ";
      }
LAB_801081e8:
      FUN_80108dc8(pwVar4);
      bVar1 = false;
      goto LAB_801081f4;
    }
    if (uVar3 == 0x5030202) {
      pwVar4 = L"Au1210 AD ";
    }
    else if (uVar3 == 0x2030204) {
      pwVar4 = L"Au1100 BE ";
    }
    else {
      if (uVar3 == 0x3030200) {
        pwVar4 = L"Au1550 AA ";
        goto LAB_801081e8;
      }
      if (uVar3 == 0x4030200) {
        pwVar4 = L"Au1200 AB ";
      }
      else if (uVar3 == 0x4030201) {
        pwVar4 = L"Au1200 AC ";
      }
      else {
        if (uVar3 != 0x4030202) goto LAB_801081d4;
        pwVar4 = L"Au1250 AD ";
      }
    }
  }
LAB_8010801c:
  FUN_80108dc8(pwVar4);
LAB_801081f4:
  FUN_80105584(L"(PRId %08X) @ %dMHZ\r\n",uVar3,(_DAT_b0900060 & 0x7f) * 0xc);
  if (bVar1) {
    FUN_80108dc8(L"BCLK switching enabled\r\n");
    _DAT_b090003c = _DAT_b090003c | 0x60;
  }
  FUN_8010bd08(0x1010138,0,0,0,0,0);
  FUN_80108dc8(L"-OEMInit\r\n");
  return;
}



/* 80108284 FUN_80108284 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80108284(void)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar1 = _DAT_8112b548;
  uVar2 = 0;
  puVar3 = _DAT_8112b548;
  do {
    *(uint *)(uVar2 + 0x8152e584) = *puVar3;
    *(uint *)(uVar2 + 0x8152e588) = puVar3[1];
    *puVar3 = *puVar3 & 0xfffffffe;
    do {
    } while ((puVar3[5] & 1) == 0);
    uVar2 = uVar2 + 8;
    puVar3 = puVar3 + 0x40;
  } while (uVar2 < 0x80);
  _DAT_8152e604 = puVar1[0x400];
  _DAT_8152e608 = puVar1[0x402];
  _DAT_8152e60c = puVar1[0x403];
  return;
}



/* 80108308 FUN_80108308 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80108308(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar1 = _DAT_8112b548;
  uVar3 = 0;
  puVar4 = _DAT_8112b548;
  do {
    puVar2 = (undefined4 *)(uVar3 + 0x8152e588);
    *puVar4 = *(undefined4 *)(uVar3 + 0x8152e584);
    uVar3 = uVar3 + 8;
    puVar4[1] = *puVar2;
    puVar4 = puVar4 + 0x40;
  } while (uVar3 < 0x80);
  puVar1[0x400] = _DAT_8152e604;
  puVar1[0x402] = _DAT_8152e608;
  puVar1[0x403] = _DAT_8152e60c;
  return;
}



/* 80108368 FUN_80108368 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80108368(void)

{
  undefined4 uVar1;
  
  FUN_80108dc8(L"OemPowerOff: \r\n");
  _DAT_b090001c = &LAB_801092e8;
  _DAT_8152e568 = 0x51ee50;
  FUN_80108284();
  FUN_80107088();
  _DAT_8152e570 = _DAT_b0900020;
  _DAT_8152e578 = _DAT_b0900028;
  _DAT_8152e57c = _DAT_b0900064;
  _DAT_8152e580 = _DAT_b0900068;
  _DAT_8152e574 = _DAT_b0900024;
  _DAT_b0900110 = 0;
  _DAT_b0900018 = 0x51ee50;
  FUN_8010b5f8(400000);
  FUN_80108fe8();
  uVar1 = FUN_8010b2f0();
  FUN_8010ad80(0,0,6);
  _DAT_b0900018 = 0;
  FUN_80108e54();
  FUN_80108dc8(L"\r\nOemPowerOff: Awakened!\r\n");
  _DAT_b0900028 = _DAT_8152e578;
  _DAT_b0900020 = _DAT_8152e570;
  _DAT_b0900064 = _DAT_8152e57c;
  _DAT_b0900068 = _DAT_8152e580;
  _DAT_b0900024 = _DAT_8152e574;
  _DAT_b090005c = 0;
  _DAT_b0900018 = 0;
  FUN_8010710c();
  FUN_80108308();
  FUN_8010b308(uVar1);
  FUN_80108dc8(L"\r\nOemPowerOff: Awakened!\r\n");
  return;
}



/* 801084d8 FUN_801084d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_801084d8(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_8010b3a4();
  if (uVar1 < _DAT_8152e960) {
    iVar2 = ~_DAT_8152e960 + uVar1 + 1;
  }
  else {
    iVar2 = uVar1 - _DAT_8152e960;
  }
  return iVar2;
}



/* 8010851c FUN_8010851c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8010851c(uint *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = FUN_8010b2f0();
  uVar4 = FUN_801084d8();
  iVar2 = _DAT_8152e654;
  iVar1 = _DAT_8152e650;
  FUN_8010b308(uVar3);
  *param_1 = uVar4 + iVar1;
  param_1[1] = iVar2 + (uint)(uVar4 + iVar1 < uVar4);
  return 1;
}



/* 8010859c FUN_8010859c */

undefined4 FUN_8010859c(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_8010b27c();
  *param_1 = uVar1;
  param_1[1] = 0;
  return 1;
}



/* 801085cc FUN_801085cc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801085cc(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  
  _DAT_8112b554 = FUN_8010b27c();
  _DAT_8152e95c = FUN_8010b27c();
  _DAT_8152e95c = _DAT_8152e95c / 1000;
  *(undefined4 *)(_DAT_8152e958 + 0xd0) = 0;
  *(undefined4 *)(_DAT_8152e958 + 0xd4) = 0;
  *(code **)(_DAT_8112b20c + 0x34) = FUN_8010859c;
  bVar1 = _DAT_8152e658 == 0;
  *(code **)(_DAT_8112b20c + 0x30) = FUN_8010851c;
  if (bVar1) {
    puVar3 = (undefined4 *)&DAT_8152e610;
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 3;
    } while ((int)puVar3 < -0x7ead19cc);
    _DAT_8152e610 = 0x10;
    _DAT_8152e658 = 1;
  }
  if ((_DAT_b0900014 & 0x20) == 0) {
    do {
    } while( true );
  }
  do {
  } while ((_DAT_b0900014 & 0x800080) != 0);
  _DAT_b0900044 = (uint)(_DAT_8112b558 << 0xf) / 1000 - 1;
  do {
  } while ((_DAT_b0900014 & 0x100010) != 0);
  _DAT_b0900000 = 0x7fff;
  do {
  } while ((_DAT_b0900014 & 0x100010) != 0);
  do {
  } while ((_DAT_b0900014 & 0x800080) != 0);
  if (_DAT_8152e568 != 0x51ee50) {
    do {
    } while ((_DAT_b0900014 & 0x10000) != 0);
    _DAT_b0900048 = 0;
  }
  do {
  } while ((_DAT_b0900014 & 0x910000) != 0);
  do {
  } while ((_DAT_b0900014 & 0x91) != 0);
  _DAT_b0900014 = _DAT_b0900014 & 0xffffd7ff | 0x2800;
  *(undefined4 *)(_DAT_8152e958 + 200) = _DAT_b0900058;
  iVar2 = FUN_8010b3a4();
  FUN_8010b3cc(iVar2 + _DAT_8152e95c);
  FUN_80105584(L"Using RTCTICK tick source\r\n");
  return;
}



/* 801087f4 FUN_801087f4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801087f4(undefined4 param_1)

{
  longlong local_10;
  
  local_10 = (ulonglong)_DAT_b0900040 * 10000000 + _DAT_8152e660;
  FUN_8010581c(&local_10,param_1);
  return;
}



/* 8010885c FUN_8010885c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010885c(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint local_10;
  int local_c;
  
  iVar2 = FUN_801057f4(param_1,&local_10);
  if (iVar2 != 0) {
    uVar1 = (uint)((ulonglong)_DAT_b0900040 * 10000000);
    _DAT_8152e660 = local_10 - uVar1;
    _DAT_8152e664 =
         (local_c - (int)((ulonglong)_DAT_b0900040 * 10000000 >> 0x20)) - (uint)(local_10 < uVar1);
  }
  return;
}



/* 801088c8 FUN_801088c8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_801088c8(undefined4 param_1)

{
  int iVar1;
  uint local_10;
  int local_c;
  
  iVar1 = FUN_801057f4(param_1,&local_10);
  if (iVar1 != 0) {
    _DAT_b0900010 =
         FUN_8010b998(local_10 - _DAT_8152e660,
                      (local_c - _DAT_8152e664) - (uint)(local_10 < _DAT_8152e660),10000000,0);
    FUN_80106a98(0xd);
  }
  return iVar1;
}



/* 80108948 FUN_80108948 */

undefined4 FUN_80108948(void)

{
  FUN_8010885c();
  return 1;
}



/* 80108968 FUN_80108968 */

undefined4 FUN_80108968(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar1 = FUN_8010b2f0();
  iVar3 = 0;
  uVar2 = 0;
  do {
    if (*(int *)(&DAT_8152e610 + uVar2) == 0) {
      *(undefined4 *)(&DAT_8152e610 + iVar3 * 0xc) = 0x48;
      break;
    }
    uVar2 = uVar2 + 0xc;
    iVar3 = iVar3 + 1;
  } while (uVar2 < 0x24);
  FUN_8010b308(uVar1);
  if (iVar3 != 3) {
    uVar4 = FUN_80106b74(0,0,iVar3 + 0x55,0);
    FUN_80106a98(uVar4);
    *(undefined4 *)(&DAT_8152e610 + iVar3 * 0xc) = uVar4;
  }
  FUN_80105584(L"-OEMInterruptConnectTimer() = %x(i::%d)\r\n",uVar4,iVar3);
  return uVar4;
}



/* 80108a4c FUN_80108a4c */

void FUN_80108a4c(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  do {
    if (param_1 == *(int *)(&DAT_8152e610 + uVar1)) break;
    uVar1 = uVar1 + 0xc;
    iVar2 = iVar2 + 1;
  } while (uVar1 < 0x24);
  if (iVar2 != 3) {
    FUN_80106ec4();
    *(undefined4 *)(&DAT_8152e610 + iVar2 * 0xc) = 0;
  }
  return;
}



/* 80108ac8 FUN_80108ac8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80108ac8(int param_1,uint param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = 0;
  uVar6 = 0;
  uVar5 = 0;
  do {
    if (param_1 == *(int *)(&DAT_8152e610 + uVar5)) break;
    uVar5 = uVar5 + 0xc;
    uVar6 = uVar6 + 1;
  } while (uVar5 < 0x24);
  if (uVar6 != 3) {
    if (_DAT_8112b558 == 0) {
      trap(0x1c00);
    }
    lVar1 = (ulonglong)((param_2 / 10000) / _DAT_8112b558) * 0x8000;
    iVar4 = FUN_8010b998((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),32000,0);
    iVar2 = _DAT_b0900058;
    uVar5 = 0x20000 << (uVar6 & 0x1f);
    do {
    } while ((_DAT_b0900014 & uVar5) != 0);
    *(int *)(uVar6 * 4 + -0x4f6fffb4) = iVar4 + 1 + _DAT_b0900058;
    do {
    } while ((_DAT_b0900014 & uVar5) != 0);
    FUN_80106a98(param_1);
    uVar3 = 1;
    *(int *)(uVar6 * 0xc + -0x7ead19ec) = iVar2;
    *(int *)(uVar6 * 0xc + -0x7ead19e8) = iVar4 + 1;
  }
  return uVar3;
}



/* 80108c24 FUN_80108c24 */

bool FUN_80108c24(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  uVar2 = 0;
  do {
    if (param_1 == *(int *)(&DAT_8152e610 + uVar2)) break;
    uVar2 = uVar2 + 0xc;
    iVar1 = iVar1 + 1;
  } while (uVar2 < 0x24);
  if (iVar1 != 3) {
    FUN_8010699c();
  }
  return iVar1 != 3;
}



/* 80108c84 FUN_80108c84 */

undefined4 FUN_80108c84(void)

{
  undefined4 uVar1;
  undefined4 *in_a3;
  undefined4 *in_stack_00000014;
  
  uVar1 = FUN_80108968();
  *in_a3 = uVar1;
  *in_stack_00000014 = 4;
  return 1;
}



/* 80108cbc FUN_80108cbc */

undefined4 FUN_80108cbc(undefined4 param_1,undefined4 *param_2)

{
  FUN_80108a4c(*param_2);
  return 1;
}



/* 80108cdc FUN_80108cdc */

undefined4
FUN_80108cdc(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined1 *param_4,
            undefined4 param_5,undefined4 *param_6)

{
  undefined1 uVar1;
  
  uVar1 = FUN_80108ac8(*param_2,param_2[1]);
  *param_4 = uVar1;
  *param_6 = 1;
  return 1;
}



/* 80108d20 FUN_80108d20 */

undefined4
FUN_80108d20(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined1 *param_4,
            undefined4 param_5,undefined4 *param_6)

{
  undefined1 uVar1;
  
  uVar1 = FUN_80108c24(*param_2);
  *param_4 = uVar1;
  *param_6 = 1;
  return 1;
}



/* 80108dc8 FUN_80108dc8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80108dc8(ushort *param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = _DAT_8112b564;
  iVar3 = _DAT_8112b560;
  uVar1 = *param_1;
  uVar2 = 0;
  do {
    if (uVar1 == 0) {
      return;
    }
    uVar5 = uVar1 & 0xff;
    if ((uVar5 == 10) && (uVar2 != 0xd)) {
      if (iVar4 != 0) {
        do {
        } while ((*(uint *)(iVar3 + 0x1c) & 0x20) == 0);
        *(undefined4 *)(iVar3 + 4) = 0xd;
        goto LAB_80108e20;
      }
    }
    else {
LAB_80108e20:
      if (iVar4 != 0) {
        do {
        } while ((*(uint *)(iVar3 + 0x1c) & 0x20) == 0);
        *(uint *)(iVar3 + 4) = uVar5;
      }
    }
    param_1 = param_1 + 1;
    uVar1 = *param_1;
    uVar2 = uVar5;
  } while( true );
}



/* 80108e54 FUN_80108e54 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80108e54(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _DAT_8112b560;
  *(undefined4 *)(_DAT_8112b560 + 0x100) = 0;
  *(undefined4 *)(iVar1 + 0x100) = 1;
  *(undefined4 *)(iVar1 + 0x100) = 3;
  *(undefined4 *)(iVar1 + 0x10) = 0x31;
  *(undefined4 *)(iVar1 + 0x14) = 3;
  *(undefined4 *)(iVar1 + 0x18) = 3;
  uVar2 = FUN_8010b2a4();
  *(uint *)(_DAT_8112b560 + 0x28) = uVar2 / 0x1c2000;
  FUN_80108dc8(L"\r\n\r\n");
  return;
}



/* 80108ec8 FUN_80108ec8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80108ec8(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_80105888();
  FUN_80105844(uVar1);
  iVar2 = FUN_8010b3c4();
  uVar3 = FUN_8010b3a4();
  uVar4 = _DAT_8112b56c + iVar2;
  if (uVar4 <= uVar3) {
    uVar4 = _DAT_8112b56c + uVar3;
  }
  FUN_8010b3cc(uVar4);
  return 0;
}



/* 80108f2c FUN_80108f2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80108f2c(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_8010b27c();
  FUN_801056ac(5,FUN_801064e0);
  FUN_80105684(5,FUN_80108ec8);
  _DAT_8112b570 = 0;
  FUN_80109444((uVar1 / 1000000) * param_1);
  return;
}



/* 80108fa0 FUN_80108fa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80108fa0(void)

{
  FUN_80105584(L"+OEMProfileTimerDisable: hit count = %d\r\n",_DAT_8112b570);
  FUN_801056ac(5,FUN_80108ec8);
  FUN_80105684(5,FUN_801064e0);
  return;
}



/* 80108fe8 FUN_80108fe8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80108fe8(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStackX_0 [16];
  
  _DAT_8152e8c0 = 0;
  _DAT_8152e8d8 = _DAT_b0900058;
  _DAT_8152e8e8 = Index;
  _DAT_8152e8ec = Random;
  _DAT_8152e8f0 = EntryLo0;
  _DAT_8152e8f4 = EntryLo1;
  _DAT_8152e8f8 = Context;
  _DAT_8152e8fc = PageMask;
  _DAT_8152e900 = Wired;
  _DAT_8152e904 = Count;
  _DAT_8152e908 = EntryHi;
  _DAT_8152e90c = Compare;
  _DAT_8152e910 = Status;
  _DAT_8152e914 = Cause;
  _DAT_8152e918 = EPC;
  _DAT_8152e91c = Config;
  _DAT_8152e920 = LLAddr;
  _DAT_8152e924 = WatchLo;
  _DAT_8152e928 = XContext;
  _DAT_8152e92c = ErrCtl;
  _DAT_8152e930 = TagLo;
  _DAT_8152e934 = TagHi;
  _DAT_8152e938 = ErrorEPC;
  _DAT_8152e8c4 = (undefined1 *)register0x00000074;
  FUN_80109238();
  FUN_8010b614();
  SYNC(0);
  SYNC(0);
  SYNC(0);
  iVar1 = -0x7fef6e94;
  iVar2 = 0xc0;
  do {
    cacheOp(0x14,iVar1);
    iVar2 = iVar2 + -0x20;
    iVar1 = iVar1 + 0x20;
  } while (-1 < iVar2);
  SYNC(0);
  SYNC(0);
  SYNC(0);
  SYNC(0);
  SYNC(0);
  SYNC(0);
  SYNC(0);
  SYNC(0);
  do {
  } while ((_DAT_b4000850 & 0x3000000) != 0x3000000);
  SYNC(0);
  SYNC(0);
  SYNC(0);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* 80109238 FUN_80109238 */

void FUN_80109238(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)&DAT_8152e668;
  iVar2 = 0;
  do {
    setCopReg(0,Index,iVar2);
    EntryHi = TLB_read_indexed_entryHi(Index);
    EntryLo0 = TLB_read_indexed_entryLo0(Index);
    EntryLo1 = TLB_read_indexed_entryLo1(Index);
    PageMask = TLB_read_indexed_entryPageMask(Index);
    iVar2 = iVar2 + 1;
    *puVar1 = EntryLo0;
    puVar1[1] = EntryLo1;
    puVar1[2] = EntryHi;
    puVar1[3] = PageMask;
    puVar1 = puVar1 + 4;
  } while (iVar2 != 0x20);
  return;
}



/* 80109298 FUN_80109298 */

void FUN_80109298(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)&DAT_8152e668;
  iVar2 = 0;
  do {
    setCopReg(0,EntryLo0,*puVar1);
    setCopReg(0,EntryLo1,puVar1[1]);
    setCopReg(0,EntryHi,puVar1[2]);
    setCopReg(0,PageMask,puVar1[3]);
    setCopReg(0,Index,iVar2);
    iVar2 = iVar2 + 1;
    TLB_write_indexed_entry(Index,EntryHi,EntryLo0,EntryLo1,PageMask);
    puVar1 = puVar1 + 4;
  } while (iVar2 != 0x20);
  return;
}



/* 80109444 FUN_80109444 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80109444(int param_1)

{
  _DAT_8112b56c = param_1;
  setCopReg(0,Compare,Count + param_1);
  return 0;
}



/* 80109580 FUN_80109580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_80109580(undefined4 param_1,uint *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            undefined4 *param_6)

{
  uint *puVar1;
  wchar_t *pwVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  uVar6 = 0;
  if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoCtlHalDdkCall(...)\r\n");
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if ((param_2 == (uint *)0x0) || (param_3 < 4)) {
    FUN_801055bc(0x57);
    if ((_DAT_8112ca24 & 1) == 0) goto LAB_80109858;
    pwVar2 = L"ERROR:OALIoctlHalDdkCall: INVALID PARAMETER\r\n";
LAB_8010984c:
    FUN_80105584(pwVar2);
    goto LAB_80109858;
  }
  uVar5 = *param_2;
  if (uVar5 < 6) {
    if (uVar5 != 5) {
      if (uVar5 == 1) {
        if (param_2[2] != 4) {
LAB_8010969c:
          if ((_DAT_8112ca24 & 1) == 0) goto LAB_80109858;
          pwVar2 = L"ERROR: OALIoctlHalDdkCall: Unsupported bus type\r\n";
          goto LAB_8010984c;
        }
        local_30 = 5;
        local_2c = param_2[3] >> 8;
        local_28 = ((param_2[3] & 0xff) << 8 | param_2[4] & 0x1f) << 8 | param_2[4] >> 5 & 7;
        uVar4 = param_2[5];
        uVar3 = param_2[7];
        uVar5 = param_2[6];
        puVar1 = &local_30;
LAB_80109658:
        uVar5 = FUN_80107b1c(puVar1,uVar5,uVar3,uVar4);
      }
      else {
        if (uVar5 == 2) {
          if (param_2[2] != 4) goto LAB_8010969c;
          local_30 = 5;
          local_2c = param_2[3] >> 8;
          local_28 = ((param_2[3] & 0xff) << 8 | param_2[4] & 0x1f) << 8 | param_2[4] >> 5 & 7;
          uVar4 = param_2[5];
          uVar3 = param_2[7];
          uVar5 = param_2[6];
          puVar1 = &local_30;
        }
        else {
          if (uVar5 != 3) {
            if (uVar5 != 4) goto LAB_801097b0;
            uVar4 = param_2[9];
            uVar3 = param_2[8];
            uVar5 = param_2[7];
            puVar1 = param_2 + 2;
            goto LAB_80109658;
          }
          uVar4 = param_2[9];
          uVar3 = param_2[8];
          uVar5 = param_2[7];
          puVar1 = param_2 + 2;
        }
        uVar5 = FUN_80107b1c(puVar1,uVar5,uVar3,uVar4);
      }
      param_2[1] = uVar5;
      uVar6 = 1;
      goto LAB_80109858;
    }
    uVar5 = FUN_801098a0(param_2[2],param_2[3],param_2[6],param_2[7],param_2 + 4,param_2 + 6);
  }
  else if (uVar5 == 6) {
    uVar5 = FUN_801099a4(param_2[2],param_2[3],param_2[6],param_2[7],param_2 + 6);
  }
  else if (uVar5 == 7) {
    uVar5 = FUN_80109a64(param_2[2],param_2[3]);
  }
  else {
    if (uVar5 != 8) {
LAB_801097b0:
      FUN_801055bc(0x57);
      if ((_DAT_8112ca24 & 1) != 0) {
        FUN_80105584(L"ERROR: OALIoctlHalDdkCall: Unsupported function code 0x%08x\r\n",*param_2);
      }
      goto LAB_80109858;
    }
    uVar5 = FUN_80109ae8(param_2[2],param_2[3]);
  }
  param_2[1] = uVar5;
  uVar6 = 1;
LAB_80109858:
  if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIoCtlHalDdkCall(rc = %d)\r\n",uVar6);
  }
  return uVar6;
}



/* 801098a0 FUN_801098a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_801098a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoTranslateBusAddress(%d, %d, 0x%08x%08x, %d)\r\n",param_1,param_2,param_4,
                 param_3,*param_5);
  }
  if (((param_5 != (undefined4 *)0x0) && (param_6 != (undefined4 *)0x0)) && (param_1 == 0)) {
    *param_6 = param_3;
    param_6[1] = param_4;
    *param_5 = 0;
    uVar1 = 1;
  }
  if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALTranslateBusAddress(addressSpace = %d, systemAddress = 0x%08x%08x, rc = %d)\r\n"
                 ,*param_5,param_6[1],*param_6,uVar1);
  }
  return uVar1;
}



/* 801099a4 FUN_801099a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_801099a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALTranslateSystemAddress(%d, %d, 0x%08x%08x)\r\n",param_1,param_2,param_4,
                 param_3);
  }
  if (param_5 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    *param_5 = param_3;
    param_5[1] = param_4;
    if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
      FUN_80105584(L"-OALTranslateSystemAddress(busAddress = 0x%08x%08x, rc = 1)\r\n",param_4,
                   param_3);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 80109a64 FUN_80109a64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80109a64(undefined4 param_1,undefined4 param_2)

{
  if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoBusPowerOff(%d, %d)\r\n",param_1,param_2);
  }
  if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIoBusPowerOff(rc = %d)\r\n",0);
  }
  return 0;
}



/* 80109ae8 FUN_80109ae8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80109ae8(undefined4 param_1,undefined4 param_2)

{
  if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoBusPowerOn(%d, %d)\r\n",param_1,param_2);
  }
  if (((_DAT_8112ca24 & 0x400) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIoBusPowerOn(rc = %d)\r\n",0);
  }
  return 0;
}



/* 80109b6c FUN_80109b6c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_80109b6c(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 param_5,undefined4 *param_6)

{
  undefined4 *puVar1;
  wchar_t *pwVar2;
  
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if ((param_2 == (undefined4 *)0x0) || (param_3 != 4)) {
    FUN_801055bc(0x57);
    if ((_DAT_8112ca24 & 2) == 0) {
      return 0;
    }
    pwVar2 = L"ERROR: OALIoCtlHalUpdateMode: Invalid input buffer\r\n";
  }
  else {
    puVar1 = (undefined4 *)FUN_8010bd3c(5);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_2;
      return 1;
    }
    FUN_801055bc(0x32);
    if ((_DAT_8112ca24 & 2) == 0) {
      return 0;
    }
    pwVar2 = L"ERROR: OALIoCtlHalUpdateMode: Device doesn\'t support Update Mode\r\n";
  }
  FUN_80105584(pwVar2);
  return 0;
}



/* 80109c38 FUN_80109c38 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_80109c38(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,int param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  
  if ((((param_2 == 0) && (param_3 == 0)) && (param_4 != (undefined4 *)0x0)) && (param_5 == 4)) {
    *param_4 = 0;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 4;
    }
    uVar1 = 1;
  }
  else {
    FUN_801055bc(0x57);
    uVar1 = 0;
  }
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIoCtlHalGetRegSecureKeys(rc = %d)\r\n",uVar1);
  }
  return uVar1;
}



/* 80109cd8 FUN_80109cd8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80109cd8(void)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined2 *in_a3;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint in_stack_00000010;
  undefined4 *in_stack_00000014;
  
  uVar3 = 0;
  if ((_DAT_8112ca24 & 4) != 0) {
    FUN_80105584(L"+OALIoCtlProcessorInfo(...)\r\n");
  }
  if (in_stack_00000014 != (undefined4 *)0x0) {
    *in_stack_00000014 = 0x240;
  }
  if (in_a3 == (undefined2 *)0x0) {
    if (in_stack_00000010 == 0) {
LAB_80109e94:
      FUN_801055bc(0x7a);
      if ((_DAT_8112ca24 & 2) == 0) goto LAB_80109ec0;
      pwVar2 = L"WARN: OALIoCtlProcessorInfo: Buffer too small\r\n";
    }
    else {
      FUN_801055bc(0x57);
      if ((_DAT_8112ca24 & 2) == 0) goto LAB_80109ec0;
      pwVar2 = L"WARN: OALIoCtlProcessorInfo: Invalid output buffer\r\n";
    }
  }
  else {
    if (in_stack_00000010 < 0x240) goto LAB_80109e94;
    iVar1 = FUN_801057a4(_DAT_8112b230);
    uVar4 = (iVar1 + 1) * 2;
    if (uVar4 < 0x51) {
      iVar1 = FUN_801057a4(_DAT_8112b22c);
      uVar5 = (iVar1 + 1) * 2;
      if (uVar5 < 0x51) {
        iVar1 = FUN_801057a4(_DAT_8112b228);
        uVar6 = (iVar1 + 1) * 2;
        if (uVar6 < 0xc9) {
          FUN_80105364(in_a3,0,0x240);
          uVar3 = 1;
          *in_a3 = 1;
          FUN_80104a98(in_a3 + 1,_DAT_8112b230,uVar4);
          FUN_80104a98(in_a3 + 0x2a,_DAT_8112b22c,uVar5);
          FUN_80104a98(in_a3 + 0xb7,_DAT_8112b228,uVar6);
          *(undefined4 *)(in_a3 + 0x11c) = _DAT_8152ca44;
          *(undefined4 *)(in_a3 + 0x11e) = _DAT_8152ca48;
          goto LAB_80109ec0;
        }
        if ((_DAT_8112ca24 & 1) == 0) goto LAB_80109ec0;
        pwVar2 = L"ERROR:OALIoCtlProcessorInfo: Vendor value too big\r\n";
      }
      else {
        if ((_DAT_8112ca24 & 1) == 0) goto LAB_80109ec0;
        pwVar2 = L"ERROR:OALIoCtlProcessorInfo: Name value too big\r\n";
      }
    }
    else {
      if ((_DAT_8112ca24 & 1) == 0) goto LAB_80109ec0;
      pwVar2 = L"ERROR:OALIoCtlProcessorInfo: Core value too big\r\n";
    }
  }
  FUN_80105584(pwVar2);
LAB_80109ec0:
  if ((_DAT_8112ca24 & 4) != 0) {
    FUN_80105584(L"-OALIoCtlProcessorInfo(rc = %d)\r\n",uVar3);
  }
  return uVar3;
}



/* 80109f10 FUN_80109f10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80109f10(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_a3;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint in_stack_00000010;
  uint *in_stack_00000014;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 auStack_50 [16];
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [16];
  undefined4 local_28;
  
  local_28 = _DAT_8112b210;
  uVar5 = 0;
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoctlHalGetRandomSeed(...)\r\n");
  }
  if ((in_a3 == 0) || (0x400 < in_stack_00000010)) {
    FUN_801055bc(0x57);
    if ((_DAT_8112ca24 & 2) != 0) {
      FUN_80105584(L"WARN: OALIoCtlHalGetRandomSeed: Invalid parameter\r\n");
    }
  }
  else {
    if (*(int *)(_DAT_8112b20c + 0x30) == 0) {
      if (in_stack_00000014 != (uint *)0x0) {
        *in_stack_00000014 = 0;
      }
      uVar2 = 0x32;
    }
    else {
      iVar1 = (**(code **)(_DAT_8112b20c + 0x30))(&local_58);
      if (iVar1 != 0) {
        uVar7 = 8;
        local_40 = local_58;
        local_3c = local_54;
        iVar1 = FUN_801087f4(auStack_50);
        if (iVar1 != 0) {
          uVar7 = 0x18;
          FUN_80104a98(auStack_38,auStack_50,0x10);
        }
        uVar6 = uVar7;
        if (in_stack_00000010 < uVar7) {
          uVar3 = 0;
          uVar4 = in_stack_00000010;
          do {
            *(byte *)((int)&local_40 + uVar3) =
                 *(byte *)((int)&local_40 + uVar4) ^ *(byte *)((int)&local_40 + uVar3);
            if (uVar3 < in_stack_00000010) {
              uVar3 = uVar3 + 1;
            }
            else {
              uVar3 = 0;
            }
            uVar4 = uVar4 + 1;
            uVar6 = in_stack_00000010;
          } while (uVar4 < uVar7);
        }
        FUN_80104a98(in_a3,&local_40,uVar6);
        if (uVar6 < in_stack_00000010) {
          FUN_80105364(in_a3 + uVar6,0,in_stack_00000010 - uVar6);
        }
        if (in_stack_00000014 != (uint *)0x0) {
          *in_stack_00000014 = uVar6;
        }
        uVar5 = 1;
        goto LAB_8010a0f8;
      }
      if (in_stack_00000014 != (uint *)0x0) {
        *in_stack_00000014 = 0;
      }
      uVar2 = 0x42b;
    }
    FUN_801055bc(uVar2);
  }
LAB_8010a0f8:
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIoCtlHalGetRandomSeed(rc = %d)\r\n",uVar5);
  }
  FUN_8010b76c(local_28);
  return uVar5;
}



/* 8010a150 FUN_8010a150 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8010a150(void)

{
  int iVar1;
  wchar_t *pwVar2;
  uint uVar3;
  int in_a3;
  uint in_stack_00000010;
  undefined4 *in_stack_00000014;
  
  FUN_80105584(
              L"Warning: you are calling IOCTL_HAL_GET_UUID, which has been deprecated.  Use IOCTL_HAL_GET_DEVICE_INFO instead.\r\n"
              );
  if (in_stack_00000014 != (undefined4 *)0x0) {
    *in_stack_00000014 = 0x10;
  }
  if (in_a3 == 0) {
    if (in_stack_00000010 != 0) {
      FUN_801055bc(0x57);
      if ((_DAT_8112ca24 & 2) == 0) {
        return 0;
      }
      pwVar2 = L"WARN: OALIoCtlHalGetUUID: Invalid output buffer\r\n";
      goto LAB_8010a2b0;
    }
  }
  else if (0xf < in_stack_00000010) {
    iVar1 = FUN_8010bd3c(3);
    if (iVar1 == 0) {
      iVar1 = FUN_8010bd3c(1);
      if (iVar1 == 0) {
        FUN_801055bc(0x32);
        if ((_DAT_8112ca24 & 1) == 0) {
          return 0;
        }
        pwVar2 = L"ERROR: OALIoCtlHalGetUUID: Device doesn\'t support UUID\r\n";
        goto LAB_8010a2b0;
      }
      FUN_80105584(
                  L"Warning: IOCTL_HAL_GET_UUID is using IOCTL_HAL_GET_DEVICEID and returning potentially nonunique data.\r\n"
                  );
      uVar3 = FUN_8010ba28(iVar1);
      if (uVar3 < 0x10) {
        FUN_80104a98(in_a3,&DAT_801032b4,0x10 - uVar3);
        in_a3 = (in_a3 - uVar3) + 0x10;
      }
    }
    else {
      uVar3 = 0x10;
    }
    FUN_80104a98(in_a3,iVar1,uVar3);
    return 1;
  }
  FUN_801055bc(0x7a);
  if ((_DAT_8112ca24 & 2) == 0) {
    return 0;
  }
  pwVar2 = L"WARN: OALIoCtlHalGetUUID: Buffer too small\r\n";
LAB_8010a2b0:
  FUN_80105584(pwVar2);
  return 0;
}



/* 8010a2d8 FUN_8010a2d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8010a2d8(int param_1,uint *param_2,uint *param_3,uint *param_4,undefined4 param_5)

{
  wchar_t *pwVar1;
  
  if ((param_1 == 0) && (*param_2 != 0)) {
    FUN_801055bc(0x57);
    if ((_DAT_8112ca24 & 1) == 0) {
      return 0;
    }
    pwVar1 = 
    L"ERROR: OALIoCtlHalGetDeviceinfo::%s: Invalid parameter: nonzero buffer size supplied with invalid buffer\r\n"
    ;
  }
  else {
    if (param_3 != (uint *)0x0) {
      *param_3 = *param_4;
    }
    if ((param_1 != 0) && (*param_4 <= *param_2)) {
      return 1;
    }
    FUN_801055bc(0x7a);
    if ((_DAT_8112ca24 & 2) == 0) {
      return 0;
    }
    pwVar1 = L"WARN: OALIoCtlHalGetDeviceinfo::%s: Buffer too small\r\n";
  }
  FUN_80105584(pwVar1,param_5);
  return 0;
}



/* 8010a394 FUN_8010a394 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8010a394(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  char *pcVar1;
  uint uVar2;
  short *psVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_res4 [3];
  int local_40 [2];
  short local_38 [18];
  undefined4 local_14;
  
  local_14 = _DAT_8112b210;
  *param_4 = L"SPI_GETBOOTMENAME";
  local_res4[0] = param_2;
  pcVar1 = (char *)FUN_8010bd3c(1);
  if (pcVar1 == (char *)0x0) {
    uVar4 = *param_4;
    FUN_801055bc(0x32);
    if ((_DAT_8112ca24 & 1) != 0) {
      FUN_80105584(L"ERROR: OALIoCtlHalGetDeviceInfo: Device doesn\'t support IOCTL_HAL_GET_DEVICE_INFO::%s\r\n"
                   ,uVar4);
    }
    iVar5 = 0;
  }
  else {
    uVar2 = 0;
    psVar3 = local_38;
    do {
      if (*pcVar1 == '\0') break;
      uVar2 = uVar2 + 1;
      *psVar3 = (short)*pcVar1;
      pcVar1 = pcVar1 + 1;
      psVar3 = psVar3 + 1;
    } while (uVar2 < 0x10);
    local_38[uVar2] = 0;
    iVar5 = FUN_801057a4(local_38);
    local_40[0] = (iVar5 + 1) * 2;
    iVar5 = FUN_8010a2d8(param_1,local_res4,param_3,local_40,*param_4);
    if (iVar5 != 0) {
      FUN_801057cc(param_1,local_38);
    }
  }
  FUN_8010b76c(local_14);
  return iVar5;
}



/* 8010a4c4 FUN_8010a4c4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8010a4c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_res4 [3];
  undefined4 local_20 [2];
  
  *param_4 = L"SPI_GETUUID";
  local_res4[0] = param_2;
  iVar1 = FUN_8010bd3c(3);
  if (iVar1 == 0) {
    uVar2 = *param_4;
    FUN_801055bc(0x32);
    if ((_DAT_8112ca24 & 1) != 0) {
      FUN_80105584(L"ERROR: OALIoCtlHalGetDeviceInfo: Device doesn\'t support IOCTL_HAL_GET_DEVICE_INFO::%s\r\n"
                   ,uVar2);
    }
    iVar3 = 0;
  }
  else {
    local_20[0] = 0x10;
    iVar3 = FUN_8010a2d8(param_1,local_res4,param_3,local_20,*param_4);
    if (iVar3 != 0) {
      FUN_80104a98(param_1,iVar1,0x10);
    }
  }
  return iVar3;
}



/* 8010a5a8 FUN_8010a5a8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_8010a5a8(undefined4 param_1,uint *param_2,int param_3,undefined4 *param_4,wchar_t *param_5,
            undefined4 param_6)

{
  int iVar1;
  wchar_t *pwVar2;
  uint uVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  wchar_t *local_28;
  wchar_t *local_24;
  
  pwVar5 = L"";
  local_28 = L"";
  uVar4 = 0;
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoCtlHalGetDeviceInfo(...)\r\n");
  }
  if (((((uint)param_2 & 3) == 0) && (param_2 != (uint *)0x0)) && (param_3 == 4)) {
    uVar3 = *param_2;
    if (uVar3 < 0x105) {
      if (uVar3 == 0x104) {
        pwVar5 = L"SPI_GETPLATFORMNAME";
        local_28 = param_5;
        iVar1 = FUN_801057a4(_DAT_8112b220);
        local_24 = (wchar_t *)((iVar1 + 1) * 2);
        iVar1 = FUN_8010a2d8(param_4,&local_28,param_6,&local_24,L"SPI_GETPLATFORMNAME");
        pwVar2 = _DAT_8112b220;
joined_r0x8010a820:
        uVar4 = 0;
        if (iVar1 == 0) goto LAB_8010a938;
LAB_8010a6d0:
        FUN_801057cc(param_4,pwVar2);
      }
      else {
        if (uVar3 != 0xe0) {
          if (uVar3 == 0x101) {
            FUN_80105584(
                        L"Warning: you are requesting IOCTL_HAL_GET_DEVICE_INFO::SPI_GETPLATFORMTYPE, which has been deprecated.  Use IOCTL_HAL_GET_DEVICE_INFO::SPI_GETPLATFORMNAME instead.\r\n"
                        );
            local_24 = (wchar_t *)0x104;
            uVar4 = FUN_801058e0(0x1010004,&local_24,4,param_4,param_5,param_6);
            pwVar5 = L"SPI_GETPLATFORMTYPE";
            goto LAB_8010a938;
          }
          if (uVar3 == 0x102) {
            pwVar5 = L"SPI_GETOEMINFO";
            local_28 = param_5;
            iVar1 = FUN_801057a4(_DAT_8112b224);
            local_24 = (wchar_t *)((iVar1 + 1) * 2);
            iVar1 = FUN_8010a2d8(param_4,&local_28,param_6,&local_24,L"SPI_GETOEMINFO");
            pwVar2 = _DAT_8112b224;
            goto joined_r0x8010a820;
          }
          if (uVar3 != 0x103) goto LAB_8010a854;
          pwVar5 = L"SPI_GETPROJECTNAME";
          local_24 = param_5;
          iVar1 = FUN_801057a4(L"CEBase");
          local_28 = (wchar_t *)((iVar1 + 1) * 2);
          iVar1 = FUN_8010a2d8(param_4,&local_24,param_6,&local_28,L"SPI_GETPROJECTNAME");
          uVar4 = 0;
          if (iVar1 == 0) goto LAB_8010a938;
          pwVar2 = L"CEBase";
          goto LAB_8010a6d0;
        }
        pwVar5 = L"SPI_GETPLATFORMVERSION";
        local_28 = param_5;
        local_24 = (wchar_t *)0x8;
        iVar1 = FUN_8010a2d8(param_4,&local_28,param_6,&local_24,L"SPI_GETPLATFORMVERSION");
        uVar4 = 0;
        if (iVar1 == 0) goto LAB_8010a938;
        *param_4 = 6;
        param_4[1] = 0;
      }
LAB_8010a6d8:
      uVar4 = 1;
      goto LAB_8010a938;
    }
    if (uVar3 == 0x105) {
      uVar4 = FUN_8010a394(param_4,param_5,param_6,&local_28);
      pwVar5 = local_28;
      goto LAB_8010a938;
    }
    if (uVar3 == 0x107) {
      uVar4 = FUN_8010a4c4(param_4,param_5,param_6,&local_28);
      pwVar5 = local_28;
      goto LAB_8010a938;
    }
    if (uVar3 == 0x108) {
      pwVar5 = L"SPI_GETGUIDPATTERN";
      local_28 = param_5;
      local_24 = (wchar_t *)0x10;
      iVar1 = FUN_8010a2d8(param_4,&local_28,param_6,&local_24,L"SPI_GETGUIDPATTERN");
      uVar4 = 0;
      if (iVar1 == 0) goto LAB_8010a938;
      FUN_80104a98(param_4,&DAT_80103a0c,0x10);
      goto LAB_8010a6d8;
    }
LAB_8010a854:
    FUN_801055bc(0x57);
    if ((_DAT_8112ca24 & 1) == 0) goto LAB_8010a938;
    pwVar2 = L"ERROR: OALIoCtlHalGetDeviceInfo: Invalid request\r\n";
  }
  else {
    FUN_801055bc(0x57);
    if ((_DAT_8112ca24 & 1) == 0) goto LAB_8010a938;
    pwVar2 = L"ERROR: OALIoCtlHalGetDeviceInfo: Invalid parameter\r\n";
  }
  FUN_80105584(pwVar2);
LAB_8010a938:
  if (((_DAT_8112ca24 & 4) != 0) && ((_DAT_8112ca24 & 0x1000) != 0)) {
    FUN_80105584(L"-OALIoCtlHalGetDeviceInfo(SPI = %s, rc = %d)\r\n",pwVar5,uVar4);
  }
  return uVar4;
}



/* 8010a98c FUN_8010a98c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8010a98c(void)

{
  int iVar1;
  wchar_t *pwVar2;
  uint *in_a3;
  undefined1 *puVar3;
  uint uVar4;
  short *psVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint in_stack_00000010;
  uint *in_stack_00000014;
  undefined4 local_170;
  undefined4 local_16c;
  undefined1 local_168 [24];
  short local_150 [20];
  undefined1 auStack_128 [256];
  undefined4 local_28;
  
  local_28 = _DAT_8112b210;
  local_170 = 0x104;
  local_16c = 0x105;
  uVar6 = 0;
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"+OALIoctlHalGetDeviceID(...)\r\n");
  }
  FUN_80105584(
              L"Warning: you are requesting IOCTL_HAL_GET_DEVICEID, which has been deprecated.  Use IOCTL_HAL_GET_DEVICE_INFO instead.\r\n"
              );
  iVar1 = FUN_801058e0(0x1010004,&local_170,4,auStack_128,0x100,0);
  if (iVar1 == 0) {
    if ((_DAT_8112ca24 & 2) == 0) goto LAB_8010aba8;
    pwVar2 = 
    L"WARN: OALIoCtlHalGetDeviceID: Call to IOCTL_HAL_GET_DEVICE_INFO::SPI_GETPLATFORMNAME failed.\r\n"
    ;
  }
  else {
    iVar1 = FUN_801057a4(auStack_128);
    uVar8 = (iVar1 + 1) * 2;
    iVar1 = FUN_801058e0(0x1010004,&local_16c,4,local_150,0x22,0);
    if (iVar1 == 0) {
      if ((_DAT_8112ca24 & 2) == 0) goto LAB_8010aba8;
      pwVar2 = 
      L"WARN: OALIoCtlHalGetDeviceID: Call to IOCTL_HAL_GET_DEVICE_INFO::SPI_GETBOOTMENAME failed.\r\n"
      ;
    }
    else {
      uVar4 = 0;
      psVar5 = local_150;
      do {
        if (*psVar5 == 0) break;
        puVar3 = local_168 + uVar4;
        uVar4 = uVar4 + 1;
        *puVar3 = (char)*psVar5;
        psVar5 = psVar5 + 1;
      } while (uVar4 < 0x10);
      local_168[uVar4] = 0;
      iVar1 = FUN_8010ba28(local_168);
      uVar7 = iVar1 + 1;
      uVar4 = uVar7 + uVar8 + 0x14;
      if (in_stack_00000014 != (uint *)0x0) {
        *in_stack_00000014 = uVar4;
      }
      if ((in_a3 != (uint *)0x0) && (0x13 < in_stack_00000010)) {
        *in_a3 = uVar4;
        if (in_stack_00000010 < uVar4) {
          FUN_801055bc(0x7a);
        }
        else {
          in_a3[1] = 0x14;
          in_a3[2] = uVar8;
          FUN_80104a98(in_a3 + 5,auStack_128,uVar8);
          in_a3[3] = uVar8 + 0x14;
          in_a3[4] = uVar7;
          FUN_80104a98((int)in_a3 + uVar8 + 0x14,local_168,uVar7);
          uVar6 = 1;
        }
        goto LAB_8010aba8;
      }
      FUN_801055bc(0x57);
      if ((_DAT_8112ca24 & 2) == 0) goto LAB_8010aba8;
      pwVar2 = L"WARN: OALIoCtlHalGetDeviceID: Invalid parameter\r\n";
    }
  }
  FUN_80105584(pwVar2);
LAB_8010aba8:
  if (((_DAT_8112ca24 & 0x1000) != 0) && ((_DAT_8112ca24 & 4) != 0)) {
    FUN_80105584(L"-OALIoCtlHalGetDeviceID(rc = %d)\r\n",uVar6);
  }
  FUN_8010b76c(local_28);
  return uVar6;
}



/* 8010ac00 FUN_8010ac00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8010ac00(void)

{
  wchar_t *pwVar1;
  undefined4 *in_a3;
  undefined4 uVar2;
  uint in_stack_00000010;
  undefined4 *in_stack_00000014;
  
  uVar2 = 0;
  if ((_DAT_8112ca24 & 4) != 0) {
    FUN_80105584(L"+OALIoctlHalGetCacheInfo(...)\r\n");
  }
  if (in_stack_00000014 != (undefined4 *)0x0) {
    *in_stack_00000014 = 0x38;
  }
  if (in_a3 == (undefined4 *)0x0) {
    if (in_stack_00000010 == 0) goto LAB_8010ad1c;
    FUN_801055bc(0x57);
    if ((_DAT_8112ca24 & 2) == 0) goto LAB_8010ad48;
    pwVar1 = L"WARN: OALIoctlHalGetCacheInfo: Invalid output buffer passed\r\n";
  }
  else {
    if (0x37 < in_stack_00000010) {
      FUN_80105364(in_a3,0,0x38);
      uVar2 = 1;
      *in_a3 = _DAT_8152eba0;
      in_a3[2] = _DAT_8152ebac;
      in_a3[3] = _DAT_8152eba8;
      in_a3[1] = _DAT_8152ebb0;
      in_a3[5] = _DAT_8152ebbc;
      in_a3[6] = _DAT_8152ebb8;
      in_a3[4] = _DAT_8152ebc0;
      in_a3[7] = _DAT_8152ebc4;
      in_a3[9] = _DAT_8152ebd0;
      in_a3[10] = _DAT_8152ebcc;
      in_a3[8] = _DAT_8152ebd4;
      in_a3[0xc] = _DAT_8152ebe0;
      in_a3[0xd] = _DAT_8152ebdc;
      in_a3[0xb] = _DAT_8152ebe4;
      goto LAB_8010ad48;
    }
LAB_8010ad1c:
    FUN_801055bc(0x7a);
    if ((_DAT_8112ca24 & 2) == 0) goto LAB_8010ad48;
    pwVar1 = L"WARN: OALIoctlHalGetCacheInfo: Buffer too small\r\n";
  }
  FUN_80105584(pwVar1);
LAB_8010ad48:
  if ((_DAT_8112ca24 & 4) != 0) {
    FUN_80105584(L"-OALIoctlHalGetCacheInfo(rc = %d)\r\n",uVar2);
  }
  return uVar2;
}



/* 8010ad80 FUN_8010ad80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010ad80(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (((_DAT_8112ca24 & 0x20) != 0) && ((_DAT_8112ca24 & 0x8000) != 0)) {
    FUN_80105584(L"+OEMCacheRangeFlush(0x%08x, %d, 0x%08x)\r\n",param_1,param_2,param_3);
  }
  if ((param_3 & 1) == 0) {
    if ((param_3 & 4) != 0) {
      if (param_2 == 0) {
        if (param_1 == 0) {
LAB_8010ae68:
          FUN_8010b220();
        }
      }
      else {
        uVar1 = ~(_DAT_8152ebbc - 1U) & param_1;
        param_2 = (param_1 - uVar1) + param_2;
        if (_DAT_8152ebc0 <= param_2) goto LAB_8010ae68;
        FUN_8010b1f4(uVar1,param_2);
      }
    }
  }
  else if (param_2 == 0) {
    if (param_1 == 0) {
LAB_8010ae04:
      FUN_8010b220();
    }
  }
  else {
    uVar1 = ~(_DAT_8152ebbc - 1U) & param_1;
    param_2 = (param_1 - uVar1) + param_2;
    if (_DAT_8152ebc0 <= param_2) goto LAB_8010ae04;
    FUN_8010b250(uVar1,param_2);
  }
  if ((param_3 & 2) != 0) {
    if (param_2 == 0) {
      if (param_1 != 0) goto LAB_8010af0c;
    }
    else if ((param_1 - (~(_DAT_8152ebac - 1U) & param_1)) + param_2 < _DAT_8152ebb0) {
      FUN_8010b198();
      goto LAB_8010af0c;
    }
    FUN_8010b1c4();
  }
LAB_8010af0c:
  if ((param_3 & 0x18) != 0) {
    FUN_8010af6c();
  }
  if (((_DAT_8112ca24 & 0x20) != 0) && ((_DAT_8112ca24 & 0x8000) != 0)) {
    FUN_80105584(L"-OEMCacheRangeFlush\r\n");
  }
  return;
}



/* 8010af6c FUN_8010af6c */

void FUN_8010af6c(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  setCopReg(0,Status,Status & 0xfffe);
  iVar2 = -0x80000000;
  iVar3 = 0x1f;
  do {
    setCopReg(0,EntryLo0,0);
    setCopReg(0,EntryLo1,0);
    setCopReg(0,EntryHi,iVar2);
    setCopReg(0,Index,iVar3);
    iVar2 = iVar2 + 0x2000;
    TLB_write_indexed_entry(Index,EntryHi,EntryLo0,EntryLo1,PageMask);
    bVar1 = iVar3 != Wired;
    iVar3 = iVar3 + -1;
  } while (bVar1);
  setCopReg(0,EntryHi,EntryHi);
  setCopReg(0,Status,Status);
  return;
}



/* 8010b0a0 FUN_8010b0a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010b0a0(void)

{
  int iVar1;
  int iVar2;
  
  _DAT_8152eba4 = 1 << (Config1 >> 0x16 & 7) + 6;
  iVar1 = (Config1 >> 0x13 & 7) + 1;
  _DAT_8152ebac = 1 << iVar1;
  iVar2 = (Config1 >> 0x10 & 7) + 1;
  _DAT_8152eba8 = iVar2;
  _DAT_8152ebb0 = 0;
  do {
    _DAT_8152ebb0 = _DAT_8152ebb0 + (_DAT_8152eba4 << iVar1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _DAT_8152ebb4 = 1 << (Config1 >> 0xd & 7) + 6;
  iVar1 = (Config1 >> 10 & 7) + 1;
  _DAT_8152ebbc = 1 << iVar1;
  iVar2 = (Config1 >> 7 & 7) + 1;
  _DAT_8152ebb8 = iVar2;
  _DAT_8152ebc0 = 0;
  do {
    _DAT_8152ebc0 = _DAT_8152ebc0 + (_DAT_8152ebb4 << iVar1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _DAT_8152ebc8 = 0;
  _DAT_8152ebd0 = 0;
  _DAT_8152ebcc = 0;
  _DAT_8152ebd4 = 0;
  _DAT_8152ebd8 = 0;
  _DAT_8152ebe0 = 0;
  _DAT_8152ebdc = 0;
  _DAT_8152ebe4 = 0;
  _DAT_8152eba0 = 0;
  _DAT_8152ebc4 = 0;
  return;
}



/* 8010b198 FUN_8010b198 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010b198(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_1 + param_2;
  do {
    cacheOp(0x10,param_1);
    param_1 = param_1 + _DAT_8152ebac;
  } while (param_1 < uVar1);
  return;
}



/* 8010b1c4 FUN_8010b1c4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010b1c4(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = -0x80000000;
  do {
    cacheOp(0,iVar2);
    bVar1 = (_DAT_8152ebb0 + -0x80000000) - _DAT_8152ebac != iVar2;
    iVar2 = iVar2 + _DAT_8152ebac;
  } while (bVar1);
  return;
}



/* 8010b1f4 FUN_8010b1f4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010b1f4(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_1 + param_2;
  do {
    cacheOp(0x19,param_1);
    param_1 = param_1 + _DAT_8152ebbc;
  } while (param_1 < uVar1);
  return;
}



/* 8010b220 FUN_8010b220 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010b220(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = -0x80000000;
  do {
    cacheOp(1,iVar2);
    bVar1 = (_DAT_8152ebc0 + -0x80000000) - _DAT_8152ebbc != iVar2;
    iVar2 = iVar2 + _DAT_8152ebbc;
  } while (bVar1);
  return;
}



/* 8010b250 FUN_8010b250 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010b250(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_1 + param_2;
  do {
    cacheOp(0x15,param_1);
    param_1 = param_1 + _DAT_8152ebbc;
  } while (param_1 < uVar1);
  return;
}



/* 8010b27c FUN_8010b27c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8010b27c(void)

{
  return (_DAT_b0900060 & 0x7f) * 12000000;
}



/* 8010b2a4 FUN_8010b2a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8010b2a4(void)

{
  uint uVar1;
  
  uVar1 = (_DAT_b090003c & 3) + 2;
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  return ((_DAT_b0900060 & 0x7f) * 12000000) / uVar1 >> 1;
}



/* 8010b2f0 FUN_8010b2f0 */

uint FUN_8010b2f0(void)

{
  setCopReg(0,Status,Status & 0xfffffffe);
  return Status & 1;
}



/* 8010b308 FUN_8010b308 */

uint FUN_8010b308(uint param_1)

{
  setCopReg(0,Status,param_1 | Status & 0xfffffffe);
  return Status & 1;
}



/* 8010b3a4 FUN_8010b3a4 */

undefined4 FUN_8010b3a4(void)

{
  return Count;
}



/* 8010b3c4 FUN_8010b3c4 */

undefined4 FUN_8010b3c4(void)

{
  return Compare;
}



/* 8010b3cc FUN_8010b3cc */

void FUN_8010b3cc(undefined4 param_1)

{
  setCopReg(0,Compare,param_1);
  return;
}



/* 8010b404 FUN_8010b404 */

undefined4 FUN_8010b404(void)

{
  return PRId;
}



/* 8010b4e4 FUN_8010b4e4 */

int FUN_8010b4e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  setCopReg(0,Wired,Wired + 1);
  setCopReg(0,EntryHi,param_1);
  setCopReg(0,EntryLo0,param_2);
  setCopReg(0,EntryLo1,param_3);
  setCopReg(0,PageMask,param_4);
  setCopReg(0,Index,Wired);
  TLB_write_indexed_entry(Index,EntryHi,EntryLo0,EntryLo1,PageMask);
  setCopReg(0,EntryHi,EntryHi);
  setCopReg(0,PageMask,PageMask);
  return Wired;
}



/* 8010b560 FUN_8010b560 */

int FUN_8010b560(undefined4 param_1)

{
  return 0x1f - LZCOUNT(param_1);
}



/* 8010b570 FUN_8010b570 */

void FUN_8010b570(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_8010b3a4();
  uVar2 = FUN_8010b27c();
  uVar2 = (uVar2 / 1000000 + 1) * param_1 + uVar1;
  while (uVar2 < uVar1) {
    uVar1 = FUN_8010b3a4();
  }
  do {
    uVar1 = FUN_8010b3a4();
  } while (uVar1 < uVar2);
  return;
}



/* 8010b5f8 FUN_8010b5f8 */

void FUN_8010b5f8(void)

{
  FUN_8010b570();
  return;
}



/* 8010b614 FUN_8010b614 */

void FUN_8010b614(void)

{
  uint uVar1;
  
  uVar1 = 0x80000000;
  do {
    cacheOp(1,uVar1);
    uVar1 = uVar1 + 0x20;
  } while (uVar1 < 0x80004000);
  return;
}



/* 8010b6ec FUN_8010b6ec */

void FUN_8010b6ec(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_8010b76c(*(undefined4 *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 8010b740 FUN_8010b740 */

undefined4 FUN_8010b740(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  FUN_8010b6ec(param_2,param_4,*(undefined4 *)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 8010b76c FUN_8010b76c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010b76c(uint param_1)

{
  if ((param_1 == _DAT_8112b210) && (param_1 >> 0x10 == 0)) {
    return;
  }
  FUN_801058b8();
  return;
}



/* 8010b7b4 FUN_8010b7b4 */

void FUN_8010b7b4(uint *param_1,uint *param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar7 = CONCAT44(param_6,param_5);
  iVar4 = 0;
  uVar5 = param_4;
  if (param_4 == 0) {
    if (param_3 != 0) {
      iVar4 = 0x20;
      for (uVar5 = param_3; (uVar5 & 0x80000000) == 0; uVar5 = uVar5 << 1) {
        iVar4 = iVar4 + 1;
      }
    }
  }
  else {
    for (; (uVar5 & 0x80000000) == 0; uVar5 = uVar5 << 1) {
      iVar4 = iVar4 + 1;
    }
  }
  iVar3 = 0;
  uVar5 = param_6;
  if (param_6 == 0) {
    if (param_5 != 0) {
      iVar3 = 0x20;
      for (uVar5 = param_5; (uVar5 & 0x80000000) == 0; uVar5 = uVar5 << 1) {
        iVar3 = iVar3 + 1;
      }
    }
  }
  else {
    for (; (uVar5 & 0x80000000) == 0; uVar5 = uVar5 << 1) {
      iVar3 = iVar3 + 1;
    }
  }
  iVar3 = iVar3 - iVar4;
  if (0 < iVar3) {
    uVar7 = FUN_8010ba48(param_5,param_6,iVar3);
  }
  uVar5 = 0;
  uVar6 = 0;
  do {
    uVar2 = (uint)((ulonglong)uVar7 >> 0x20);
    uVar1 = (uint)uVar7;
    if (iVar3 < 0) {
      *param_1 = uVar5;
      param_1[1] = uVar6;
      *param_2 = param_3;
      param_2[1] = param_4;
      return;
    }
    iVar3 = iVar3 + -1;
    uVar7 = FUN_8010ba48(uVar5,uVar6,1);
    uVar6 = (uint)((ulonglong)uVar7 >> 0x20);
    uVar5 = (uint)uVar7;
    if (param_4 == uVar2) {
      if (uVar1 <= param_3) {
LAB_8010b91c:
        param_4 = (param_4 - (param_3 < uVar1)) - uVar2;
        param_3 = param_3 - uVar1;
        uVar5 = uVar5 | 1;
      }
    }
    else if (uVar2 < param_4) goto LAB_8010b91c;
    uVar7 = FUN_8010ba90(uVar1,uVar2,1);
  } while( true );
}



/* 8010b998 FUN_8010b998 */

undefined8 FUN_8010b998(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined1 auStack_10 [8];
  
  if (param_4 == 0) {
    if (param_3 == 0) {
      FUN_8010bcbc();
      local_18 = 0;
      local_14 = 0;
      goto LAB_8010ba1c;
    }
    if (param_3 < 0x10000) {
      FUN_8010bb20(&local_18,auStack_10,param_1,param_2,param_3,0);
      goto LAB_8010ba1c;
    }
  }
  FUN_8010b7b4(&local_18,auStack_10,param_1,param_2,param_3,param_4);
LAB_8010ba1c:
  return CONCAT44(local_14,local_18);
}



/* 8010ba28 FUN_8010ba28 */

int FUN_8010ba28(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = param_1 + -1;
  do {
    pcVar1 = (char *)(iVar2 + 1);
    iVar2 = iVar2 + 1;
  } while (*pcVar1 != '\0');
  return iVar2 - param_1;
}



/* 8010ba48 FUN_8010ba48 */

longlong FUN_8010ba48(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0x20 - (param_3 & 0x3f);
  if ((int)uVar2 < 1) {
    return (ulonglong)(param_1 << (param_3 & 0x1f)) << 0x20;
  }
  uVar1 = param_2 << (param_3 & 0x1f);
  if ((param_3 & 0x3f) != 0) {
    uVar2 = param_1 >> (uVar2 & 0x1f);
    param_1 = param_1 << (param_3 & 0x1f);
    uVar1 = uVar1 | uVar2;
  }
  return CONCAT44(uVar1,param_1);
}



/* 8010ba90 FUN_8010ba90 */

ulonglong FUN_8010ba90(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0x20 - (param_3 & 0x3f);
  if ((int)uVar1 < 1) {
    return (ulonglong)(param_2 >> (param_3 & 0x1f));
  }
  param_1 = param_1 >> (param_3 & 0x1f);
  if ((param_3 & 0x3f) != 0) {
    uVar1 = param_2 << (uVar1 & 0x1f);
    param_2 = param_2 >> (param_3 & 0x1f);
    param_1 = param_1 | uVar1;
  }
  return CONCAT44(param_2,param_1);
}



/* 8010bb20 FUN_8010bb20 */

void FUN_8010bb20(uint *param_1,uint *param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  uint uVar1;
  
  if (param_6 == 0) {
    if (param_4 == 0) {
      *param_1 = param_3 / param_5;
      param_1[1] = 0;
      *param_2 = param_3 % param_5;
      param_2[1] = 0;
      return;
    }
    if (param_5 >> 0x10 == 0) {
      *(short *)((int)param_1 + 6) = (short)((param_4 >> 0x10) / param_5);
      uVar1 = (param_4 >> 0x10) % param_5 << 0x10 | param_4 & 0xffff;
      *(short *)(param_1 + 1) = (short)(uVar1 / param_5);
      uVar1 = uVar1 % param_5 << 0x10 | param_3 >> 0x10;
      *(short *)((int)param_1 + 2) = (short)(uVar1 / param_5);
      uVar1 = uVar1 % param_5 << 0x10 | param_3 & 0xffff;
      *(short *)param_1 = (short)(uVar1 / param_5);
      param_2[1] = 0;
      *param_2 = uVar1 % param_5;
      return;
    }
  }
  if ((param_4 <= param_6) && ((param_4 < param_6 || (param_3 < param_5)))) {
    *param_1 = 0;
    param_1[1] = 0;
    *param_2 = param_3;
    param_2[1] = param_4;
    return;
  }
  trap(0);
  FUN_8010bce8(0xc0000094,0,0,0);
  return;
}



/* 8010bcbc FUN_8010bcbc */

void FUN_8010bcbc(void)

{
  FUN_8010bce8(0xc0000094,0,0,0);
  return;
}



/* 8010bce8 FUN_8010bce8 */

void FUN_8010bce8(void)

{
  (*(code *)&SUB_ffffbb8e)();
  return;
}



/* 8010bd08 FUN_8010bd08 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8010bd08(void)

{
  (**(code **)(_DAT_8152e958 + 0x80))();
  return;
}



/* 8010bd3c FUN_8010bd3c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8010bd3c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((_DAT_8112ca24 & 2) != 0) {
    FUN_80105584(L"+OALArgsQuery(%d)\r\n",param_1);
  }
  if (((_DAT_a00ffc00 == 0x53475241) && (_DAT_a00ffc04 == 1)) && (_DAT_a00ffc06 == 1)) {
    if (param_1 == 1) {
      uVar1 = 0xa00ffc08;
    }
    else if (param_1 == 2) {
      uVar1 = 0xa00ffc18;
    }
  }
  if ((_DAT_8112ca24 & 2) != 0) {
    FUN_80105584(L"-OALArgsQuery(pData = 0x%08x)\r\n",uVar1);
  }
  return uVar1;
}


