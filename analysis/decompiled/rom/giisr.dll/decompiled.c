/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c07e1040 entry */

undefined4 entry(void)

{
  return 1;
}



/* c07e1048 CreateInstance */

uint CreateInstance(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
                    /* 0x1048  1  CreateInstance */
  if (DAT_c07e2500 < 0x20) {
    DAT_c07e2500 = DAT_c07e2500 + 1;
    uVar1 = 0;
    piVar2 = &DAT_c07e2480;
    do {
      if (*piVar2 == 0) break;
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 1;
    } while ((int)uVar1 < 0x20);
    if (uVar1 < 0x20) {
      (&DAT_c07e2480)[uVar1] = 1;
      iVar3 = uVar1 * 0x20;
      *(undefined4 *)(&DAT_c07e2000 + iVar3) = 3;
      *(undefined4 *)(&DAT_c07e2004 + iVar3) = 0;
      *(undefined4 *)(&DAT_c07e200c + iVar3) = 0;
      *(undefined4 *)(&DAT_c07e2400 + uVar1 * 4) = 0;
      return uVar1;
    }
  }
  return 0xffffffff;
}



/* c07e1100 DestroyInstance */

void DestroyInstance(int param_1)

{
                    /* 0x1100  2  DestroyInstance */
  if ((&DAT_c07e2480)[param_1] != 0) {
    (&DAT_c07e2480)[param_1] = 0;
    DAT_c07e2500 = DAT_c07e2500 + -1;
  }
  return;
}



/* c07e1134 IOControl */

undefined4
IOControl(int param_1,int param_2,undefined1 *param_3,int param_4,undefined4 *param_5,int param_6,
         int *param_7)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1134  3  IOControl */
  if (param_7 != (int *)0x0) {
    *param_7 = 0;
  }
  if (param_2 == 0x100) {
    iVar2 = 0x20;
    if ((param_4 == 0x20) && (param_3 != (undefined1 *)0x0)) {
      iVar1 = param_1 * 0x20 - (int)param_3;
      do {
        iVar2 = iVar2 + -1;
        param_3[(int)(&DAT_c07e2000 + iVar1)] = *param_3;
        param_3 = param_3 + 1;
      } while (iVar2 != 0);
      return 1;
    }
  }
  else if (param_2 == 0x101) {
    iVar2 = *(int *)(&DAT_c07e2014 + param_1 * 0x20);
    if (((param_6 == iVar2) && (*(int *)(&DAT_c07e2004 + param_1 * 0x20) != 0)) &&
       (param_5 != (undefined4 *)0x0)) {
      if (param_7 != (int *)0x0) {
        *param_7 = iVar2;
      }
      iVar2 = *(int *)(&DAT_c07e2014 + param_1 * 0x20);
      if (iVar2 == 1) {
        *(char *)param_5 = (char)*(undefined4 *)(&DAT_c07e2400 + param_1 * 4);
        return 1;
      }
      if (iVar2 == 2) {
        *(short *)param_5 = (short)*(undefined4 *)(&DAT_c07e2400 + param_1 * 4);
        return 1;
      }
      if (iVar2 == 4) {
        *param_5 = *(undefined4 *)(&DAT_c07e2400 + param_1 * 4);
        return 1;
      }
      if (param_7 != (int *)0x0) {
        *param_7 = 0;
      }
    }
  }
  return 0;
}



/* c07e1278 ISRHandler */

/* Boundary evidence: original MIPS .pdata c07e1278..c07e14cb. Semantic name remains unreviewed. */

undefined4 ISRHandler(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  
                    /* 0x1278  4  ISRHandler */
  iVar7 = param_1 * 0x20;
  uVar9 = *(uint *)(&DAT_c07e2018 + iVar7);
  if (*(int *)(&DAT_c07e2004 + iVar7) == 0) {
    uVar3 = *(undefined4 *)(&DAT_c07e2000 + iVar7);
  }
  else {
    puVar5 = *(undefined4 **)(&DAT_c07e2010 + iVar7);
    if (puVar5 != (undefined4 *)0x0) {
      puVar8 = (uint *)(&DAT_c07e2400 + param_1 * 4);
      iVar6 = *(int *)(&DAT_c07e2008 + iVar7);
      *puVar8 = 0;
      if (iVar6 == 0) {
        iVar6 = *(int *)(&DAT_c07e2014 + iVar7);
        if (iVar6 == 1) {
          uVar1 = FUN_c07e14cc((undefined1 *)puVar5);
          iVar6 = *(int *)(&DAT_c07e200c + iVar7);
          *puVar8 = CONCAT31(extraout_var_01,uVar1);
          if (iVar6 != 0) {
            uVar1 = FUN_c07e14cc(*(undefined1 **)(iVar7 + -0x3f81dfe4));
            uVar9 = CONCAT31(extraout_var_02,uVar1);
          }
        }
        else if (iVar6 == 2) {
          uVar2 = FUN_c07e14d4((undefined2 *)puVar5);
          iVar6 = *(int *)(&DAT_c07e200c + iVar7);
          *puVar8 = CONCAT22(extraout_var_05,uVar2);
          if (iVar6 != 0) {
            uVar2 = FUN_c07e14d4(*(undefined2 **)(iVar7 + -0x3f81dfe4));
            uVar9 = CONCAT22(extraout_var_06,uVar2);
          }
        }
        else if (iVar6 == 4) {
          uVar4 = FUN_c07e14dc(puVar5);
          iVar6 = *(int *)(&DAT_c07e200c + iVar7);
          *puVar8 = uVar4;
          if (iVar6 != 0) {
            uVar9 = FUN_c07e14dc(*(undefined4 **)(iVar7 + -0x3f81dfe4));
          }
        }
      }
      else {
        iVar6 = *(int *)(&DAT_c07e2014 + iVar7);
        if (iVar6 == 1) {
          uVar1 = FUN_c07e14cc((undefined1 *)puVar5);
          iVar6 = *(int *)(&DAT_c07e200c + iVar7);
          *puVar8 = CONCAT31(extraout_var,uVar1);
          if (iVar6 != 0) {
            uVar1 = FUN_c07e14cc(*(undefined1 **)(iVar7 + -0x3f81dfe4));
            uVar9 = CONCAT31(extraout_var_00,uVar1);
          }
        }
        else if (iVar6 == 2) {
          uVar2 = FUN_c07e14d4((undefined2 *)puVar5);
          iVar6 = *(int *)(&DAT_c07e200c + iVar7);
          *puVar8 = CONCAT22(extraout_var_03,uVar2);
          if (iVar6 != 0) {
            uVar2 = FUN_c07e14d4(*(undefined2 **)(iVar7 + -0x3f81dfe4));
            uVar9 = CONCAT22(extraout_var_04,uVar2);
          }
        }
        else if (iVar6 == 4) {
          uVar4 = FUN_c07e14dc(puVar5);
          iVar6 = *(int *)(&DAT_c07e200c + iVar7);
          *puVar8 = uVar4;
          if (iVar6 != 0) {
            uVar9 = FUN_c07e14dc(*(undefined4 **)(iVar7 + -0x3f81dfe4));
          }
        }
      }
      if ((uVar9 & *puVar8) != 0) {
        return *(undefined4 *)(&DAT_c07e2000 + iVar7);
      }
    }
    uVar3 = 3;
  }
  return uVar3;
}



/* c07e14cc FUN_c07e14cc */

undefined1 FUN_c07e14cc(undefined1 *param_1)

{
  return *param_1;
}



/* c07e14d4 FUN_c07e14d4 */

undefined2 FUN_c07e14d4(undefined2 *param_1)

{
  return *param_1;
}



/* c07e14dc FUN_c07e14dc */

undefined4 FUN_c07e14dc(undefined4 *param_1)

{
  return *param_1;
}


