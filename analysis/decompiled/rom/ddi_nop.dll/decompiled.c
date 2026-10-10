/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0891494 FUN_c0891494 */

/* Boundary evidence: original MIPS .pdata c0891494..c08914df. Semantic name remains unreviewed. */

undefined4 * FUN_c0891494(undefined4 *param_1,uint param_2)

{
  FUN_c0894ac8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c08914e0 DrvEnableDriver */

/* Boundary evidence: original MIPS .pdata c08914e0..c08914fb. Semantic name remains unreviewed. */

void DrvEnableDriver(int param_1,size_t param_2,void *param_3,undefined4 *param_4)

{
                    /* 0x14e0  1  DrvEnableDriver */
  FUN_c0893484(param_1,param_2,param_3,param_4);
  return;
}



/* c08914fc FUN_c08914fc */

/* Boundary evidence: original MIPS .pdata c08914fc..c08916bb. Semantic name remains unreviewed. */

undefined4 * FUN_c08914fc(undefined4 *param_1)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  FUN_c089408c(param_1);
  *param_1 = &PTR_FUN_c0891050;
  FUN_c0891cb0();
  param_1[9] = 0;
  param_1[2] = DAT_c08b10c0;
  param_1[10] = DAT_c08b10c0;
  param_1[3] = DAT_c08b10c4;
  param_1[0xb] = DAT_c08b10c4;
  param_1[0xc] = 2;
  param_1[0xd] = 0x3c;
  param_1[0xe] = 1;
  param_1[4] = param_1 + 9;
  if (DAT_c08bc854 == 0) {
    puVar1 = operator_new(0x4c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_c089498c(puVar1,param_1[2],param_1[3],1);
    }
    param_1[1] = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_c0891cb0();
    }
  }
  else {
    iVar6 = DAT_c08b10d8 * DAT_c08b10c0;
    if (iVar6 < 0) {
      iVar6 = iVar6 + 3;
    }
    pvVar2 = VirtualAlloc((LPVOID)0x0,iVar6 >> 2,0x2000,1);
    param_1[0xf] = pvVar2;
    VirtualCopy(pvVar2,DAT_c08bc854,iVar6 >> 2,0x204);
    puVar1 = operator_new(0x4c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      iVar6 = DAT_c08b10d8;
      if (DAT_c08b10d8 < 0) {
        iVar6 = DAT_c08b10d8 + 3;
      }
      uVar5 = param_1[0xf];
      uVar4 = param_1[3];
      uVar3 = param_1[2];
      *puVar1 = &PTR_FUN_c089104c;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      FUN_c0894510((int)puVar1,uVar3,uVar4,uVar5,iVar6 >> 2,1);
    }
    param_1[1] = puVar1;
  }
  return param_1;
}



/* c08916bc FUN_c08916bc */

/* Boundary evidence: original MIPS .pdata c08916bc..c0891723. Semantic name remains unreviewed. */

undefined4 FUN_c08916bc(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    if (param_3 != (undefined4 *)0x0) {
      uVar1 = (*DAT_c08bc884)(1,4,0xc08b10a4,0,0,0);
      *param_3 = uVar1;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



/* c0891724 FUN_c0891724 */

/* Boundary evidence: original MIPS .pdata c0891724..c089175f. Semantic name remains unreviewed. */

undefined4 FUN_c0891724(int param_1,void *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    memcpy(param_2,(void *)(param_1 + 0x24),0x18);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



/* c0891760 FUN_c0891760 */

/* Boundary evidence: original MIPS .pdata c0891760..c08917b7. Semantic name remains unreviewed. */

undefined4 FUN_c0891760(undefined4 param_1,int param_2)

{
  if (param_2 == -1) {
    FUN_c0891cb0();
  }
  FUN_c0891cb0();
  return 0;
}



/* c08917b8 FUN_c08917b8 */

undefined4 FUN_c08917b8(void)

{
  return 0;
}



/* c08917fc FUN_c08917fc */

/* Boundary evidence: original MIPS .pdata c08917fc..c08918a7. Semantic name remains unreviewed. */

undefined4
FUN_c08917fc(undefined4 param_1,undefined4 *param_2,int param_3,int param_4,int param_5,uint param_6
            )

{
  undefined4 *puVar1;
  
  if ((param_6 & 1) == 0) {
    puVar1 = operator_new(0x4c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_c089498c(puVar1,param_3,param_4,param_5);
    }
    *param_2 = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      if (puVar1[1] != 0) {
        return 0;
      }
      (**(code **)*puVar1)(puVar1,1);
    }
  }
  return 0x8007000e;
}



/* c08918a8 FUN_c08918a8 */

/* Boundary evidence: original MIPS .pdata c08918a8..c0891ad7. Semantic name remains unreviewed. */

int FUN_c08918a8(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_c0894b38(param_1,param_2);
  if (-1 < iVar1) {
    if ((*(int *)(param_2 + 0x14) != 0) && (*(int *)(param_2 + 0x10) == 0)) {
      trap(0x1c00);
    }
    switch(*(undefined4 *)(param_2 + 0x1c)) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    default:
      return -0x7ff8ffa9;
    }
    FUN_c0891cb0();
  }
  return iVar1;
}



/* c0891b30 FUN_c0891b30 */

/* Boundary evidence: original MIPS .pdata c0891b30..c0891bbf. Semantic name remains unreviewed. */

int FUN_c0891b30(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_c089bfc0(param_1,param_2);
  if (-1 < iVar1) {
    FUN_c0891cb0();
  }
  return iVar1;
}



/* c0891c04 FUN_c0891c04 */

undefined * FUN_c0891c04(void)

{
  return &DAT_c08b10b4;
}



/* c0891c10 FUN_c0891c10 */

/* Boundary evidence: original MIPS .pdata c0891c10..c0891c63. Semantic name remains unreviewed. */

void FUN_c0891c10(void)

{
  undefined4 *puVar1;
  
  if (DAT_c08bc850 == (undefined4 *)0x0) {
    puVar1 = operator_new(0x40);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_c08bc850 = (undefined4 *)0x0;
    }
    else {
      DAT_c08bc850 = FUN_c08914fc(puVar1);
    }
  }
  return;
}



/* c0891c64 FUN_c0891c64 */

/* Boundary evidence: original MIPS .pdata c0891c64..c0891caf. Semantic name remains unreviewed. */

undefined4 * FUN_c0891c64(undefined4 *param_1,uint param_2)

{
  FUN_c08940e0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0891cb0 FUN_c0891cb0 */

void FUN_c0891cb0(void)

{
  return;
}



/* c0891cb8 FUN_c0891cb8 */

/* Boundary evidence: original MIPS .pdata c0891cb8..c0891d03. Semantic name remains unreviewed. */

undefined4 FUN_c0891cb8(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_c0891cb0();
    DisableThreadLibraryCalls(param_1);
    DAT_c08bc89c = param_1;
  }
  return 1;
}



/* c0891d04 FUN_c0891d04 */

/* Boundary evidence: original MIPS .pdata c0891d04..c0891d7f. Semantic name remains unreviewed. */

void FUN_c0891d04(int param_1)

{
  if ((param_1 == 0x7b) || (DAT_c08bc898 == (code *)0x0)) {
    FUN_c0891c10();
  }
  else {
    (*DAT_c08bc898)();
  }
  return;
}



/* c0891d80 FUN_c0891d80 */

/* Boundary evidence: original MIPS .pdata c0891d80..c0891d8b. Semantic name remains unreviewed. */

undefined4 FUN_c0891d80(void)

{
  return 1;
}



/* c0891d8c FUN_c0891d8c */

/* Boundary evidence: original MIPS .pdata c0891d8c..c0891f5b. Semantic name remains unreviewed. */

void FUN_c0891d8c(int param_1,uint *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint local_28;
  undefined *local_24;
  
  if (param_2 == (uint *)0x0) {
    return;
  }
  if (param_1 == 0) {
    return;
  }
  sVar1 = *(short *)((int)param_2 + 10);
  uVar4 = *param_2 >> 0x10;
  if (param_3 == 1) {
    sVar1 = (short)param_2[2];
    uVar4 = *param_2 & 0xffff;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    return;
  }
  local_28 = 0;
  uVar5 = 0;
  local_24 = (undefined *)0x0;
  if (sVar1 == 8) {
    local_28 = 4;
    if (*(int *)(param_1 + 0x1c) != 6) {
      local_28 = 3;
    }
    local_24 = &DAT_c08b10ec;
  }
  else if (sVar1 == 4) {
    local_28 = 4;
    if (*(int *)(param_1 + 0x1c) != 6) {
      local_28 = 3;
    }
    local_24 = &DAT_c08b10dc;
  }
  else {
    iVar2 = (*DAT_c08bc868)(uVar4,&local_24,&local_28);
    if (iVar2 == 0) {
      local_28 = (*DAT_c08bc87c)(param_2,param_3,0,0);
      if (local_28 != 0) {
        if (local_28 < 0x40000000) {
          uVar3 = local_28 << 2;
        }
        else {
          uVar3 = 0xffffffff;
        }
        local_24 = operator_new(uVar3);
      }
      if (local_24 == (undefined *)0x0) goto LAB_c0891f24;
      local_28 = (*DAT_c08bc87c)(param_2,param_3,local_28,local_24);
      (*DAT_c08bc86c)(uVar4,local_24,local_28);
    }
    uVar5 = 1;
  }
LAB_c0891f24:
  *(uint *)(param_1 + 0x10) = local_28;
  *(undefined4 *)(param_1 + 0x14) = uVar5;
  *(undefined **)(param_1 + 0xc) = local_24;
  *(uint *)(param_1 + 0x18) = uVar4;
  return;
}



/* c0891f5c FUN_c0891f5c */

undefined4 FUN_c0891f5c(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  if ((*(uint *)(param_1 + 0x28) & 0xffff) != 0xaaf0) {
    return 0;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x1c);
  if ((iVar3 != 3) && (iVar3 != 2)) {
    return 0;
  }
  sVar1 = *(short *)(param_2 + 0x3c);
  iVar3 = *(int *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_2 + 0x40);
  puVar4 = (undefined *)0x0;
  if (sVar1 == 8) {
    puVar4 = &DAT_c08b10ec;
    if (*(int *)(param_2 + 0x2c) == 6) {
      uVar2 = 4;
      goto LAB_c0892010;
    }
  }
  else {
    if (sVar1 != 4) {
      if ((sVar1 == 2) || (sVar1 == 1)) {
        puVar4 = *(undefined **)(param_2 + 0x38);
      }
      goto LAB_c0892010;
    }
    puVar4 = &DAT_c08b10dc;
    if (*(int *)(param_2 + 0x2c) == 6) {
      uVar2 = 4;
      goto LAB_c0892010;
    }
  }
  uVar2 = 3;
LAB_c0892010:
  *(undefined4 *)(iVar3 + 0x10) = uVar2;
  *(undefined4 *)(iVar3 + 0x14) = 0;
  *(undefined **)(iVar3 + 0xc) = puVar4;
  *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(param_2 + 0x44);
  return 0;
}



/* c089202c FUN_c089202c */

/* Boundary evidence: original MIPS .pdata c089202c..c089205b. Semantic name remains unreviewed. */

undefined4 FUN_c089202c(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x38))();
  }
  return 0;
}



/* c089205c FUN_c089205c */

/* Boundary evidence: original MIPS .pdata c089205c..c0892087. Semantic name remains unreviewed. */

void FUN_c089205c(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x3c))();
  }
  return;
}



/* c0892088 FUN_c0892088 */

/* Boundary evidence: original MIPS .pdata c0892088..c0892203. Semantic name remains unreviewed. */

void FUN_c0892088(double param_1,double param_2,int *param_3,undefined4 param_4,int param_5,
                 uint param_6,int *param_7,undefined4 param_8,undefined4 *param_9)

{
  int iVar1;
  
  if (param_5 == 8) {
    if ((*param_7 != 0x183a) && (*param_7 != 0x1839)) {
      (**(code **)(*param_3 + 0x40))(param_3,param_4,8,param_6,param_7,param_8,param_9);
    }
  }
  else if (param_5 == 0x183a) {
    FUN_c089fc64(param_9);
  }
  else if (param_5 == 0x1839) {
    iVar1 = FUN_c089fc78(param_6,*param_7);
    if (iVar1 != 0) {
      FUN_c089e7f0(param_1,param_2,param_6,*param_7);
    }
  }
  else {
    (**(code **)(*param_3 + 0x40))();
  }
  return;
}



/* c0892204 FUN_c0892204 */

/* Boundary evidence: original MIPS .pdata c0892204..c089220f. Semantic name remains unreviewed. */

undefined4 FUN_c0892204(void)

{
  return 1;
}



/* c0892210 FUN_c0892210 */

/* Boundary evidence: original MIPS .pdata c0892210..c089224f. Semantic name remains unreviewed. */

void FUN_c0892210(void)

{
  undefined4 *puVar1;
  
  FUN_c089d1c8();
  puVar1 = (undefined4 *)FUN_c0891d04(0x7b);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  return;
}



/* c0892250 FUN_c0892250 */

/* Boundary evidence: original MIPS .pdata c0892250..c089228b. Semantic name remains unreviewed. */

void FUN_c0892250(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x78))(param_1);
  if (iVar1 != 0) {
    param_1[5] = 0;
  }
  return;
}



/* c089228c FUN_c089228c */

/* Boundary evidence: original MIPS .pdata c089228c..c08922af. Semantic name remains unreviewed. */

void FUN_c089228c(int param_1)

{
  (*DAT_c08bc88c)(*(undefined4 *)(param_1 + 0x14));
  return;
}



/* c08922b0 FUN_c08922b0 */

/* Boundary evidence: original MIPS .pdata c08922b0..c0892303. Semantic name remains unreviewed. */

void FUN_c08922b0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_c08bc888)(*(int *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                          *(undefined4 *)(param_1 + 0xc),
                          *(undefined4 *)
                           (&DAT_c0891178 + *(int *)(*(int *)(param_1 + 4) + 0x1c) * 4));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  return;
}



/* c0892304 FUN_c0892304 */

/* Boundary evidence: original MIPS .pdata c0892304..c08923b3. Semantic name remains unreviewed. */

int FUN_c0892304(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_18 [2];
  
  iVar1 = (**(code **)(*param_1 + 0x10))
                    (param_1,local_18,param_2,param_3,*(undefined4 *)(&LAB_c089119c + param_4 * 4),2
                    );
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = (*DAT_c08bc890)(local_18[0],param_2,param_3,param_4);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    *(int *)(local_18[0] + 0x48) = iVar1;
  }
  return iVar1;
}



/* c08923b4 FUN_c08923b4 */

/* Boundary evidence: original MIPS .pdata c08923b4..c08923f7. Semantic name remains unreviewed. */

void FUN_c08923b4(undefined4 *param_1)

{
  (*DAT_c08bc88c)(param_1[0x12]);
  (**(code **)*param_1)(param_1,1);
  return;
}



/* c08923f8 FUN_c08923f8 */

/* Boundary evidence: original MIPS .pdata c08923f8..c089241f. Semantic name remains unreviewed. */

void FUN_c08923f8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 0x18))();
  return;
}



/* c0892420 FUN_c0892420 */

/* Boundary evidence: original MIPS .pdata c0892420..c089255b. Semantic name remains unreviewed. */

undefined4
FUN_c0892420(int param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int local_b0;
  undefined4 auStack_ac [19];
  int local_60;
  undefined4 auStack_5c [19];
  
  FUN_c08a0ba8(&local_60,param_2,(int *)0x0,(int *)0x0);
  FUN_c08a0ba8(&local_b0,param_3,(int *)0x0,(int *)0x0);
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 == (int *)0x0) {
    FUN_c0894ac8(auStack_ac);
    FUN_c0894ac8(auStack_5c);
    uVar4 = 0;
  }
  else {
    if (param_2 == (int *)0x0) {
      iVar2 = 0;
      iVar1 = 0;
    }
    else {
      iVar2 = param_2[5] >> 1;
      iVar1 = param_2[4];
    }
    iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3,local_60,local_b0,param_5,param_6,iVar1,iVar2);
    if (iVar2 < 0) {
      uVar4 = 0;
    }
    else {
      if ((((0 < param_7) && (0 < param_8)) || (param_7 == -1)) || (param_8 == -1)) {
        (**(code **)(*piVar3 + 0x18))(piVar3);
      }
      uVar4 = 2;
    }
    FUN_c0894ac8(auStack_ac);
    FUN_c0894ac8(auStack_5c);
  }
  return uVar4;
}



/* c089255c FUN_c089255c */

/* Boundary evidence: original MIPS .pdata c089255c..c08925e7. Semantic name remains unreviewed. */

undefined4
FUN_c089255c(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_410 [1024];
  
  if (((param_5 < 0x101) &&
      (uVar1 = (*DAT_c08bc860)(param_2,param_4,param_5,auStack_410), uVar1 != 0)) &&
     (iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,auStack_410,param_4 & 0xffff,uVar1 & 0xffff),
     -1 < iVar2)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* c08925e8 FUN_c08925e8 */

/* Boundary evidence: original MIPS .pdata c08925e8..c08929f7. Semantic name remains unreviewed. */

undefined4
FUN_c08925e8(int *param_1,int param_2,int param_3,int *param_4,undefined4 param_5,uint param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint local_444;
  uint local_440;
  int local_43c;
  int *local_438;
  int local_430;
  uint local_42c;
  int local_428;
  int local_424;
  int *local_420;
  int aiStack_418 [8];
  undefined4 uStack_3f8;
  int local_3f4;
  undefined4 local_3f0;
  undefined4 local_3ec;
  int local_3e8;
  undefined4 local_3e4;
  undefined4 local_3dc;
  int local_3d8;
  undefined4 local_3d4;
  uint local_3d0;
  undefined4 local_3cc;
  undefined4 local_3c8;
  undefined4 local_3c4;
  undefined4 local_3c0;
  undefined4 local_3bc;
  undefined4 local_3b8;
  undefined4 local_3b0;
  undefined4 local_3ac;
  int local_3a0;
  undefined4 auStack_39c [19];
  int local_350;
  int aiStack_34c [201];
  
  local_430 = param_3;
  local_428 = param_2;
  FUN_c08a0c90(aiStack_418,*(int *)(param_2 + 4));
  FUN_c08a0ba8(&local_3a0,param_1,(int *)0x0,(int *)0x0);
  local_3f4 = local_3a0;
  local_3c8 = param_5;
  local_3d8 = *param_4;
  piVar8 = (int *)param_1[2];
  uVar7 = 1;
  local_3d0 = (uint)CONCAT11((&DAT_c08b10fc)[param_6 >> 8 & 0xf],(&DAT_c08b10fc)[param_6 & 0xf]);
  DAT_c08bc8a0 = 0;
  local_424 = 0;
  bVar1 = false;
  local_3f0 = 0;
  local_3ec = 0;
  local_3e4 = 0;
  local_3cc = 0;
  local_3dc = 0;
  local_3c4 = 1;
  local_3c0 = 1;
  local_3d4 = 0;
  local_3e8 = 0;
  local_3bc = 0;
  local_3b8 = 0;
  local_3b0 = 0;
  local_3ac = 0xff0000;
  local_420 = piVar8;
  if (*param_4 == -1) {
    iVar2 = param_4[1];
    if (iVar2 == 0) {
      iVar2 = (*DAT_c08bc874)(param_4);
    }
    local_3e8 = iVar2;
    if (iVar2 == 0) {
      FUN_c0894ac8(auStack_39c);
      FUN_c08a0cf0(aiStack_418);
      return 0;
    }
  }
  iVar2 = (**(code **)(*piVar8 + 4))(piVar8,&uStack_3f8);
  if (-1 < iVar2) {
    (*DAT_c08bc880)(param_2);
    local_444 = local_42c;
    uVar9 = local_42c;
    iVar2 = local_430;
    iVar5 = local_430;
    do {
      iVar3 = (*DAT_c08bc85c)(param_2,&local_440);
      iVar10 = local_43c;
      if (local_43c == 0) break;
      if ((local_440 & 1) == 0) {
        iVar4 = FUN_c08a0d18(aiStack_418,iVar5,local_444,*local_438,local_438[1]);
        if (iVar4 < 0) {
          bVar1 = true;
          iVar3 = 0;
        }
      }
      else {
        iVar2 = *local_438;
        uVar9 = local_438[1];
      }
      iVar10 = iVar10 + -1;
      iVar4 = 0;
      if (0 < iVar10) {
        iVar12 = 0;
        iVar11 = iVar10;
        do {
          piVar8 = (int *)(iVar12 + (int)local_438);
          iVar4 = FUN_c08a0d18(aiStack_418,*piVar8,piVar8[1],piVar8[2],piVar8[3]);
          if (iVar4 < 0) {
            bVar1 = true;
            iVar3 = 0;
          }
          iVar11 = iVar11 + -1;
          iVar12 = iVar12 + 8;
          iVar4 = iVar10;
        } while (iVar11 != 0);
      }
      if ((local_440 & 2) == 0) {
        local_444 = (local_438 + iVar4 * 2)[1];
        iVar5 = local_438[iVar4 * 2];
      }
      else {
        iVar10 = FUN_c08a0d18(aiStack_418,local_438[iVar4 * 2],(local_438 + iVar4 * 2)[1],iVar2,
                              uVar9);
        if (iVar10 < 0) {
          bVar1 = true;
          iVar3 = 0;
        }
      }
      param_2 = local_428;
    } while (iVar3 != 0);
    piVar8 = local_420;
    iVar2 = local_430;
    if ((local_430 == 0) || (*(char *)(local_430 + 0x14) == '\0')) {
      piVar6 = (int *)0x0;
LAB_c0892974:
      iVar5 = FUN_c08a105c(aiStack_418,&uStack_3f8,piVar6,local_420);
    }
    else {
      if (*(char *)(local_430 + 0x14) == '\x01') {
        piVar6 = (int *)(local_430 + 4);
        goto LAB_c0892974;
      }
      local_350 = 0;
      iVar10 = 1;
      iVar5 = local_424;
      while( true ) {
        piVar6 = aiStack_34c;
        while (local_350 != 0) {
          local_350 = local_350 + -1;
          iVar5 = FUN_c08a105c(aiStack_418,&uStack_3f8,piVar6,piVar8);
          piVar6 = piVar6 + 4;
          if (iVar5 < 0) goto LAB_c0892988;
        }
        if (iVar10 == 0) break;
        iVar10 = (*DAT_c08bc864)(iVar2,0x324,&local_350);
      }
    }
LAB_c0892988:
    iVar2 = (**(code **)(*piVar8 + 8))(piVar8,&uStack_3f8);
    if (((-1 < iVar5) && (-1 < iVar2)) && (!bVar1)) goto LAB_c08929b8;
  }
  uVar7 = 0;
LAB_c08929b8:
  FUN_c0894ac8(auStack_39c);
  FUN_c08a0cf0(aiStack_418);
  return uVar7;
}



/* c08929f8 FUN_c08929f8 */

/* Boundary evidence: original MIPS .pdata c08929f8..c0892cbb. Semantic name remains unreviewed. */

undefined4
FUN_c08929f8(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,uint *param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int iStack_120;
  int local_11c;
  int local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 *local_10c;
  undefined4 *local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  int iStack_e4;
  undefined4 uStack_e0;
  int aiStack_dc [5];
  int local_c8;
  undefined4 auStack_c4 [19];
  int local_78;
  undefined4 auStack_74 [19];
  
  FUN_c08a0ba8(&local_c8,param_3,(int *)0x0,(int *)0x0);
  FUN_c08a0ba8(&local_78,param_2,param_3,&local_c8);
  iVar6 = *(int *)(local_78 + 0x1c);
  if (iVar6 == 5) {
    iVar6 = 6;
  }
  uVar4 = 1;
  if ((*(int *)(local_c8 + 0x1c) != iVar6) || (bVar1 = false, param_5[1] != 1)) {
    bVar1 = true;
  }
  iVar5 = 0x4c;
  if (bVar1) {
    iVar5 = *(int *)(&LAB_c0891154 + iVar6 * 4) * *(int *)(local_c8 + 0x2c);
    iVar3 = iVar5 + 7;
    if (iVar3 < 0) {
      iVar3 = iVar5 + 0xe;
    }
    uVar7 = (iVar3 >> 3) + 3U & 0xfffffffc;
    iVar5 = *(int *)(local_c8 + 0x30) * uVar7 + 0x4c;
    if ((((param_5 != (uint *)0x0) && (param_5[1] != 1)) && (*(short *)((int)param_5 + 10) != 8)) &&
       (*(short *)((int)param_5 + 10) != 4)) {
      iVar3 = (*DAT_c08bc87c)(param_5,2,0,0);
      iVar5 = iVar3 * 4 + iVar5;
    }
  }
  else {
    uVar7 = *(uint *)(local_c8 + 8);
  }
  iVar5 = (*DAT_c08bc870)(param_1,iVar5);
  if (iVar5 == 0) {
    uVar4 = 0;
  }
  else {
    if (bVar1) {
      uVar2 = iVar5 + 0x4fU & 0xfffffffc;
    }
    else {
      uVar2 = *(uint *)(local_c8 + 4);
    }
    FUN_c0894510(iVar5,*(undefined4 *)(local_c8 + 0x2c),*(undefined4 *)(local_c8 + 0x30),uVar2,uVar7
                 ,iVar6);
    if (bVar1) {
      FUN_c089d244((int *)param_5,aiStack_dc,&uStack_e0,&iStack_e4);
      if ((param_5 != (uint *)0x0) && (param_5[1] != 1)) {
        FUN_c0891d8c(iVar5,param_5,2);
        FUN_c0891d8c(local_c8,param_5,1);
      }
      local_128 = *(undefined4 *)(local_c8 + 0x2c);
      local_124 = *(undefined4 *)(local_c8 + 0x30);
      local_10c = &local_130;
      local_100 = 0xffffffff;
      local_108 = &local_130;
      local_12c = 0;
      local_130 = 0;
      local_118 = local_c8;
      local_114 = 0;
      local_110 = 0;
      local_104 = 0;
      local_fc = 0;
      local_f8 = 0xcccc;
      local_f4 = 0;
      local_f0 = 0;
      local_ec = 1;
      local_e8 = 1;
      aiStack_dc[1] = 0;
      aiStack_dc[2] = 0xff0000;
      local_11c = iVar5;
      FUN_c089bfc0((int *)param_2[2],&iStack_120);
    }
  }
  FUN_c0894ac8(auStack_74);
  FUN_c0894ac8(auStack_c4);
  return uVar4;
}



/* c0892cbc FUN_c0892cbc */

/* Boundary evidence: original MIPS .pdata c0892cbc..c0892def. Semantic name remains unreviewed. */

size_t FUN_c0892cbc(int param_1,size_t param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  piVar1 = (int *)FUN_c0891d04(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1);
    if (param_3 == (void *)0x0) {
      return iVar2 * 0xd8;
    }
    if (param_2 == iVar2 * 0xd8) {
      memset(param_3,0,param_2);
      iVar4 = 0;
      if (iVar2 < 1) {
        return param_2;
      }
      puVar3 = (undefined4 *)((int)param_3 + 0xb0);
      do {
        (**(code **)(*piVar1 + 0x24))(piVar1,puVar3 + 4,iVar4);
        puVar3[-0x2c] = 0x500047;
        puVar3[-0x2b] = 0x45;
        *(undefined2 *)(puVar3 + -0x1b) = 0xc0;
        *(undefined2 *)((int)puVar3 + -0x6a) = 0x18;
        puVar3[-0x1a] = 0x7c0000;
        iVar4 = iVar4 + 1;
        puVar3[-2] = puVar3[7];
        puVar3[-1] = puVar3[5];
        *puVar3 = puVar3[6];
        puVar3[2] = puVar3[8];
        puVar3 = puVar3 + 0x36;
      } while (iVar4 < iVar2);
      return param_2;
    }
  }
  return 0;
}



/* c0892df0 FUN_c0892df0 */

/* Boundary evidence: original MIPS .pdata c0892df0..c089312f. Semantic name remains unreviewed. */

int * FUN_c0892df0(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *in_stack_00000014;
  uint *in_stack_0000001c;
  int in_stack_00000028;
  ushort local_60 [2];
  undefined4 local_5c;
  undefined1 auStack_58 [24];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  bVar1 = false;
  piVar2 = (int *)FUN_c0891d04(in_stack_00000028);
  if (piVar2 == (int *)0x0) {
LAB_c0892e30:
    piVar2 = (int *)0x0;
  }
  else {
    if (DAT_c08b1110 != 0) {
      iVar3 = FUN_c089d104();
      if (iVar3 == 0) goto LAB_c0892e30;
      DAT_c08b1110 = 0;
      bVar1 = true;
    }
    if ((*(short *)(param_1 + 0x46) == 0x18) && (in_stack_0000001c != (uint *)0x0)) {
      iVar3 = (**(code **)(*piVar2 + 0x2c))
                        (piVar2,*(undefined4 *)(param_1 + 0xc0),in_stack_0000001c + 0x49);
      if (iVar3 < 0) goto LAB_c0892e30;
      iVar3 = *(int *)(piVar2[1] + 0x1c);
      puVar4 = FUN_c0891c04();
      FUN_c08a4ccc(iVar3,(int)puVar4);
    }
    iVar3 = (**(code **)(*piVar2 + 0x70))(piVar2,&local_40);
    if (iVar3 == 0) {
      local_40 = 0x40;
      local_3c = 0x3c;
      local_38 = 0x60;
      local_34 = 0x60;
      local_30 = 1;
      local_2c = 1;
      local_28 = 1;
    }
    in_stack_00000014[3] = local_3c;
    *in_stack_00000014 = 0x40001;
    in_stack_00000014[1] = 1;
    in_stack_00000014[2] = local_40;
    in_stack_00000014[4] = *(undefined4 *)(param_1 + 0xac);
    in_stack_00000014[5] = *(undefined4 *)(param_1 + 0xb0);
    in_stack_00000014[10] = local_38;
    in_stack_00000014[0xb] = local_34;
    in_stack_00000014[6] = *(undefined4 *)(param_1 + 0xa8);
    in_stack_00000014[7] = 1;
    uVar6 = *(uint *)(param_1 + 0xa8);
    in_stack_00000014[0x11] = local_30;
    in_stack_00000014[8] = 1 << (uVar6 & 0x1f);
    in_stack_00000014[0x12] = local_2c;
    in_stack_00000014[0x13] = local_28;
    iVar3 = (**(code **)(*piVar2 + 0x34))(piVar2);
    uVar6 = 0x100;
    if (iVar3 == 0) {
      uVar6 = 0;
    }
    in_stack_00000014[9] = uVar6 | 0x12801;
    in_stack_00000014[0xd] = 0;
    if (PTR_FUN_c08b35f0 != (undefined *)0x0) {
      in_stack_00000014[0xd] = 7;
    }
    if (PTR_FUN_c08b306c != (undefined *)0x0) {
      in_stack_00000014[0xd] = in_stack_00000014[0xd] | 0x10;
    }
    if ((bVar1) && (in_stack_0000001c != (uint *)0x0)) {
      local_5c = 0;
      puVar5 = (undefined4 *)(**(code **)(*piVar2 + 0x74))(piVar2);
      local_60[0] = 0;
      (**(code **)(*piVar2 + 0x24))(piVar2,auStack_58,*(undefined4 *)piVar2[4]);
      (**(code **)(*piVar2 + 0x20))(piVar2,&local_5c,local_60);
      DAT_c08bc8a8 = FUN_c089ff4c((int)auStack_58,puVar5,local_5c,(uint)local_60[0]);
    }
    if ((8 < *(uint *)(param_1 + 0xa8)) && (DAT_c08bc8a4 != 0)) {
      DAT_c08bc8ac = 0x1000000;
    }
    if (7 < *(uint *)(param_1 + 0xa8)) {
      if (DAT_c08bc8a8 != 0) {
        DAT_c08bc8ac = DAT_c08bc8ac | 0x100;
      }
      DAT_c08bc8ac = DAT_c08bc8ac | 0x400;
    }
    uVar6 = (**(code **)(*piVar2 + 0x44))(piVar2);
    in_stack_00000014[0xc] = (uVar6 | DAT_c08bc8ac) & 0x1000700;
    if (in_stack_0000001c != (uint *)0x0) {
      uVar6 = (**(code **)(*piVar2 + 0x44))(piVar2);
      *in_stack_0000001c = uVar6 | DAT_c08bc8ac;
    }
  }
  return piVar2;
}



/* c0893130 FUN_c0893130 */

/* Boundary evidence: original MIPS .pdata c0893130..c0893403. Semantic name remains unreviewed. */

undefined4 FUN_c0893130(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  undefined1 auStack_78 [20];
  int *local_64;
  int *local_60;
  undefined4 local_5c;
  int *local_4c;
  
  piVar4 = (int *)param_2[7];
  if ((piVar4 == (int *)0x0) || ((param_2[9] & 8) != 0)) {
    uVar3 = (*(code *)*param_2)(param_1,param_2);
  }
  else {
    iVar7 = *piVar4;
    iVar8 = piVar4[1];
    iVar10 = piVar4[2];
    iVar9 = piVar4[3];
    memcpy(auStack_78,param_2,0x58);
    local_64 = &local_b0;
    piVar4 = (int *)param_2[5];
    local_b0 = *piVar4;
    local_ac = piVar4[1];
    iVar6 = piVar4[2];
    iVar5 = piVar4[3];
    local_a8 = iVar6;
    if (iVar6 < local_b0) {
      local_a8 = local_b0;
      local_b0 = iVar6;
    }
    local_a4 = iVar5;
    if (iVar5 < local_ac) {
      local_a4 = local_ac;
      local_ac = iVar5;
    }
    if (local_b0 < iVar7) {
      local_b0 = iVar7;
    }
    if (local_ac < iVar8) {
      local_ac = iVar8;
    }
    if (iVar9 < local_a4) {
      local_a4 = iVar9;
    }
    if (iVar10 < local_a8) {
      local_a8 = iVar10;
    }
    if ((local_b0 < local_a8) && (local_ac < local_a4)) {
      piVar4 = (int *)param_2[5];
      iVar5 = local_b0 - *piVar4;
      iVar7 = local_ac - piVar4[1];
      iVar8 = local_a8 - piVar4[2];
      iVar6 = local_a4 - piVar4[3];
      if ((((iVar5 != 0) || (iVar7 != 0)) || (iVar8 != 0)) || (iVar6 != 0)) {
        if (local_60 != (int *)0x0) {
          local_a0 = *local_60;
          piVar4 = local_60 + 1;
          piVar1 = local_60 + 2;
          piVar2 = local_60 + 3;
          local_60 = &local_a0;
          local_a0 = local_a0 + iVar5;
          local_98 = *piVar1 + iVar8;
          local_9c = *piVar4 + iVar7;
          local_94 = *piVar2 + iVar6;
        }
        if (local_4c != (int *)0x0) {
          local_90 = *local_4c;
          piVar4 = local_4c + 1;
          piVar1 = local_4c + 2;
          piVar2 = local_4c + 3;
          local_4c = &local_90;
          local_90 = local_90 + iVar5;
          local_88 = *piVar1 + iVar8;
          local_8c = *piVar4 + iVar7;
          local_84 = *piVar2 + iVar6;
        }
      }
      local_5c = 0;
      uVar3 = (*(code *)*param_2)(param_1,auStack_78);
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



/* c0893404 FUN_c0893404 */

/* Boundary evidence: original MIPS .pdata c0893404..c089340f. Semantic name remains unreviewed. */

undefined4 FUN_c0893404(void)

{
  return 1;
}



/* c0893410 FUN_c0893410 */

/* Boundary evidence: original MIPS .pdata c0893410..c089341b. Semantic name remains unreviewed. */

undefined4 FUN_c0893410(void)

{
  return 1;
}



/* c089341c FUN_c089341c */

/* Boundary evidence: original MIPS .pdata c089341c..c0893483. Semantic name remains unreviewed. */

void FUN_c089341c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  FUN_c0891d04(0);
  puVar1 = (undefined4 *)FUN_c0891c04();
  if (puVar1 != (undefined4 *)0x0) {
    *param_1 = *puVar1;
    *param_2 = puVar1[1];
    *param_3 = puVar1[2];
  }
  return;
}



/* c0893484 FUN_c0893484 */

/* Boundary evidence: original MIPS .pdata c0893484..c0893617. Semantic name remains unreviewed. */

undefined4 FUN_c0893484(int param_1,size_t param_2,void *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  DAT_c08bc870 = *param_4;
  DAT_c08bc874 = param_4[1];
  DAT_c08bc878 = param_4[2];
  DAT_c08bc864 = param_4[3];
  DAT_c08bc860 = param_4[4];
  DAT_c08bc880 = param_4[5];
  DAT_c08bc85c = param_4[6];
  DAT_c08bc858 = param_4[7];
  DAT_c08bc87c = param_4[8];
  DAT_c08bc888 = param_4[9];
  DAT_c08bc88c = param_4[10];
  DAT_c08bc890 = param_4[0xb];
  DAT_c08bc884 = param_4[0xc];
  DAT_c08bc868 = param_4[0xd];
  DAT_c08bc86c = param_4[0xe];
  DAT_c08bc894 = param_4[0xf];
  if ((param_1 == 0x40001) && (((param_2 == 0x74 || (param_2 == 0x78)) || (param_2 == 0x7c)))) {
    memcpy(param_3,&PTR_FUN_c08910d0,param_2);
    if (param_2 == 0x7c) {
      *(undefined **)((int)param_3 + 0x6c) = PTR_FUN_c08b306c;
      *(undefined **)((int)param_3 + 0x70) = PTR_FUN_c08b35f0;
    }
    else if (param_2 == 0x78) {
      *(undefined **)((int)param_3 + 0x6c) = PTR_FUN_c08b306c;
    }
    DAT_c08bc8a4 = FUN_c089e0f4(FUN_c089341c);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0893618 FUN_c0893618 */

/* Boundary evidence: original MIPS .pdata c0893618..c0893e83. Semantic name remains unreviewed. */

undefined4
FUN_c0893618(int *param_1,int *param_2,int *param_3,int param_4,uint *param_5,int *param_6,
            int *param_7,int *param_8,int *param_9,undefined4 param_10,uint param_11,uint param_12,
            undefined4 param_13,undefined4 param_14)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 *local_514;
  int *local_510;
  int local_508;
  int local_504;
  int local_500;
  int local_4fc;
  int local_4f8;
  int local_4f4;
  int local_4f0;
  int local_4ec;
  undefined4 uStack_4e8;
  undefined4 *local_4e4;
  undefined4 *local_4e0;
  int local_4dc;
  int local_4d8;
  int *local_4d4;
  int *local_4d0;
  undefined1 *local_4cc;
  int local_4c8;
  uint local_4c4;
  uint local_4c0;
  int *local_4bc;
  undefined4 local_4b8;
  undefined4 local_4b4;
  undefined4 local_4b0;
  int local_4ac [3];
  undefined4 local_4a0;
  undefined4 local_49c;
  int *local_490;
  int *local_48c;
  int local_488;
  int local_484;
  int local_480;
  int local_47c;
  int local_478;
  int *local_474;
  int *local_470;
  int local_468;
  int local_464;
  undefined4 local_45c;
  undefined4 local_458;
  undefined4 local_454;
  int local_44c;
  undefined2 local_446;
  undefined4 *local_440;
  undefined4 auStack_43c [19];
  undefined4 *local_3f0;
  undefined4 auStack_3ec [19];
  int local_3a0;
  undefined4 auStack_39c [19];
  int local_350;
  undefined1 auStack_34c [804];
  
  local_490 = (int *)param_1[2];
  local_514 = (undefined4 *)0x0;
  local_510 = param_2;
  local_48c = param_1;
  FUN_c08a0ba8((int *)&local_3f0,param_1,(int *)0x0,(int *)0x0);
  FUN_c08a0ba8((int *)&local_440,param_2,param_1,(int *)&local_3f0);
  FUN_c08a0ba8(&local_3a0,param_3,(int *)0x0,(int *)0x0);
  uVar5 = 1;
  uVar7 = 4;
  if (((param_11 >> 2 ^ param_11) & 0x3333) == 0) {
    local_4d0 = (int *)0x0;
    local_4e0 = (undefined4 *)0x0;
    if ((param_12 & 8) != 0) {
      iVar1 = param_6[2];
      if (iVar1 < *param_6) {
        param_6[2] = *param_6;
        *param_6 = iVar1;
      }
      iVar1 = param_6[3];
      if (iVar1 < param_6[1]) {
        param_6[3] = param_6[1];
        param_6[1] = iVar1;
      }
      param_12 = param_12 & 0xfffffff7;
    }
  }
  else {
    if ((*(ushort *)((int)param_2 + 0x32) & 0x8000) != 0) {
      iVar1 = local_3f0[0xe];
      if ((iVar1 == 1) || (iVar1 == 4)) {
        FUN_c0894638((int)local_440,local_440[0xc],local_440[0xb],iVar1);
        local_484 = *param_7;
        local_488 = param_7[1];
        local_47c = param_7[2];
        local_480 = param_7[3];
        param_7 = &local_488;
      }
      else {
        FUN_c0894638((int)local_440,local_440[0xb],local_440[0xc],iVar1);
      }
    }
    local_4e0 = local_440;
    local_4d0 = param_7;
    if ((param_7 == (int *)0x0) || (param_6 == (int *)0x0)) goto LAB_c0893974;
    if ((param_6[2] - *param_6 != param_7[2] - *param_7) ||
       (param_6[3] - param_6[1] != param_7[3] - param_7[1])) {
      param_12 = param_12 | 8;
    }
  }
  DAT_c08bc8a0 = (uint *)0x0;
  if (((param_5 != (uint *)0x0) && (local_440 != (undefined4 *)0x0)) &&
     (FUN_c0891d8c((int)local_3f0,param_5,2), param_5[1] == 4)) {
    DAT_c08bc8a0 = param_5;
  }
  if (param_8 == (int *)0x0) {
    local_4f8 = *param_7;
    local_4f4 = param_7[1];
    local_4f0 = param_7[2];
    local_4ec = param_7[3];
  }
  else {
    local_4f4 = param_8[1];
    local_4f8 = *param_8;
    local_4ec = (param_6[3] - param_6[1]) + local_4f4;
    local_4f0 = (param_6[2] - *param_6) + local_4f8;
  }
  local_4e4 = local_3f0;
  local_4a0 = param_13;
  local_4d4 = param_6;
  local_4b4 = 1;
  local_4b0 = 1;
  local_4c0 = param_11;
  local_4ac[0] = 0;
  local_4ac[1] = 0;
  local_4d8 = 0;
  local_4c8 = -1;
  local_49c = param_14;
  local_4c4 = param_12;
  if (((param_11 >> 4 ^ param_11) & 0xf0f) == 0) {
    local_4b8 = 0;
    if (param_9 != (int *)0x0) {
      local_4c8 = *param_9;
    }
  }
  else {
    local_4b8 = param_10;
    if (param_9 == (int *)0x0) goto LAB_c0893974;
    if (*param_9 == -1) {
      iVar1 = param_9[1];
      if (iVar1 == 0) {
        iVar1 = (*DAT_c08bc874)(param_9);
      }
      local_4d8 = iVar1;
      if (iVar1 == 0) goto LAB_c0893974;
    }
    else {
      local_4b8 = 0;
      local_4c8 = *param_9;
    }
  }
  if (((param_11 >> 8 ^ param_11) & 0xff) == 0) {
    local_4bc = (int *)0x0;
    local_4dc = 0;
  }
  else {
    local_4bc = &local_4f8;
    local_4dc = local_3a0;
  }
  if (local_4e4 == local_4e0) {
    if ((param_12 & 8) == 0) {
      iVar1 = param_6[1];
      if (((iVar1 < param_7[3]) && (iVar2 = param_7[1], iVar2 < param_6[3])) &&
         ((iVar6 = *param_6, iVar6 < param_7[2] && (iVar3 = *param_7, iVar3 < param_6[2])))) {
        if (iVar2 == iVar1) {
          if (iVar3 < iVar6) {
            local_4b4 = 0;
          }
          else {
            local_4b4 = 1;
          }
        }
        else {
          local_4b0 = 1;
          if (iVar2 < iVar1) {
            local_4b0 = 0;
          }
        }
        if (iVar1 < iVar2) {
          if (iVar6 < iVar3) {
            uVar7 = 0;
          }
          else {
            uVar7 = 1;
          }
        }
        else if (iVar6 < iVar3) {
          uVar7 = 2;
        }
        else {
          uVar7 = 3;
        }
      }
    }
    else {
      iVar2 = *param_6;
      local_500 = param_6[2];
      iVar1 = param_6[1];
      local_4fc = param_6[3];
      local_508 = iVar2;
      if (local_500 < iVar2) {
        local_508 = local_500;
        local_500 = iVar2;
      }
      local_504 = iVar1;
      if (local_4fc < iVar1) {
        local_504 = local_4fc;
        local_4fc = iVar1;
      }
      if (((local_504 < param_7[3]) && (param_7[1] < local_4fc)) &&
         ((local_508 < param_7[2] && (*param_7 < local_500)))) {
        piVar8 = (int *)local_510[2];
        iVar2 = param_7[2] - *param_7;
        iVar6 = param_7[3] - param_7[1];
        local_478 = 0;
        memset(&local_474,0,0x30);
        iVar1 = (**(code **)(*piVar8 + 0x10))
                          (piVar8,&local_514,iVar2,iVar6,
                           *(undefined4 *)(&LAB_c089119c + local_510[0xb] * 4),2);
        if (iVar1 < 0) {
LAB_c0893974:
          FUN_c0894ac8(auStack_39c);
          FUN_c0894ac8(auStack_43c);
          FUN_c0894ac8(auStack_3ec);
          return 0;
        }
        local_474 = &local_478;
        local_454 = local_514[2];
        local_44c = local_510[0xb];
        local_45c = local_514[1];
        local_446 = *(undefined2 *)((int)local_510 + 0x32);
        local_508 = 0;
        local_504 = 0;
        local_500 = iVar2;
        local_4fc = iVar6;
        local_470 = piVar8;
        local_468 = iVar2;
        local_464 = iVar6;
        local_458 = local_45c;
        iVar1 = FUN_c0893618(&local_478,local_510,(int *)0x0,0,(uint *)0x0,&local_508,param_7,
                             (int *)0x0,(int *)0x0,0,0xcccc,0,1,0xff0000);
        if (iVar1 == 0) {
          if (local_514 != (undefined4 *)0x0) {
            (**(code **)*local_514)(local_514,1);
          }
          goto LAB_c0893974;
        }
        local_4d0 = &local_508;
        local_4e0 = local_514;
      }
    }
  }
  else if (local_4e0 != (undefined4 *)0x0) {
    FUN_c089d244((int *)param_5,local_4ac + 2,local_4ac + 1,local_4ac);
  }
  iVar1 = 0;
  if ((param_5 != (uint *)0x0) && (local_4e0 != (undefined4 *)0x0)) {
    FUN_c0891d8c((int)local_4e0,param_5,1);
  }
  FUN_c0891f5c((int)&uStack_4e8,(int)local_48c);
  piVar8 = local_490;
  local_4cc = (undefined1 *)0x0;
  if ((param_4 != 0) && (*(char *)(param_4 + 0x14) == '\x01')) {
    local_4cc = (undefined1 *)(param_4 + 4);
  }
  iVar2 = (**(code **)(*local_490 + 4))(local_490,&uStack_4e8);
  if (-1 < iVar2) {
    if ((param_4 == 0) || (*(char *)(param_4 + 0x14) != '\x03')) {
      iVar1 = FUN_c0893130(piVar8,&uStack_4e8);
    }
    else {
      (*DAT_c08bc878)(param_4,1,0,uVar7,0);
      local_350 = 0;
      iVar2 = 1;
      while( true ) {
        puVar4 = auStack_34c;
        while (local_350 != 0) {
          local_350 = local_350 + -1;
          local_4cc = puVar4;
          iVar1 = FUN_c0893130(piVar8,&uStack_4e8);
          puVar4 = puVar4 + 0x10;
          if (iVar1 < 0) goto LAB_c0893df8;
        }
        if (iVar2 == 0) break;
        iVar2 = (*DAT_c08bc864)(param_4,0x324,&local_350);
      }
    }
LAB_c0893df8:
    iVar2 = (**(code **)(*piVar8 + 8))(piVar8,&uStack_4e8);
    if (local_514 != (undefined4 *)0x0) {
      (**(code **)*local_514)(local_514,1);
    }
    if ((-1 < iVar1) && (-1 < iVar2)) goto LAB_c0893e3c;
  }
  uVar5 = 0;
LAB_c0893e3c:
  FUN_c0894ac8(auStack_39c);
  FUN_c0894ac8(auStack_43c);
  FUN_c0894ac8(auStack_3ec);
  return uVar5;
}



/* c0893e84 FUN_c0893e84 */

/* Boundary evidence: original MIPS .pdata c0893e84..c0893eef. Semantic name remains unreviewed. */

void FUN_c0893e84(int *param_1,int *param_2,int *param_3,int param_4,uint *param_5,
                 undefined4 param_6,int *param_7,int *param_8,int *param_9,int *param_10,
                 undefined4 param_11,uint param_12,undefined4 param_13,uint param_14)

{
  FUN_c0893618(param_1,param_2,param_3,param_4,param_5,param_7,param_8,param_9,param_10,param_11,
               param_12,param_14,param_13,0xff0000);
  return;
}



/* c0893ef0 FUN_c0893ef0 */

/* Boundary evidence: original MIPS .pdata c0893ef0..c0893f5f. Semantic name remains unreviewed. */

void FUN_c0893ef0(int *param_1,int *param_2,int param_3,uint *param_4,int *param_5,int *param_6,
                 int param_7)

{
  int local_10 [2];
  
  local_10[0] = param_7;
  FUN_c0893618(param_1,param_2,(int *)0x0,param_3,param_4,param_5,param_6,(int *)0x0,local_10,0,
               0xcccc,4,1,0xff0000);
  return;
}



/* c0893f60 FUN_c0893f60 */

/* Boundary evidence: original MIPS .pdata c0893f60..c0894017. Semantic name remains unreviewed. */

void FUN_c0893f60(int *param_1,int *param_2,int *param_3,int param_4,uint *param_5,int *param_6,
                 int *param_7,int *param_8,int *param_9,undefined4 param_10,uint param_11)

{
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (param_7 == (int *)0x0) {
    local_14 = 0;
    local_18 = 0;
  }
  else {
    local_14 = param_7[1];
    local_18 = *param_7;
  }
  local_c = (param_6[3] - param_6[1]) + local_14;
  local_10 = (param_6[2] - *param_6) + local_18;
  FUN_c0893618(param_1,param_2,param_3,param_4,param_5,param_6,&local_18,param_8,param_9,param_10,
               param_11,0,1,0xff0000);
  return;
}



/* c0894018 FUN_c0894018 */

/* Boundary evidence: original MIPS .pdata c0894018..c089408b. Semantic name remains unreviewed. */

void FUN_c0894018(int *param_1,int param_2,int *param_3,undefined4 param_4,uint param_5)

{
  FUN_c0893f60(param_1,(int *)0x0,(int *)0x0,param_2,(uint *)0x0,(int *)(param_2 + 4),(int *)0x0,
               (int *)0x0,param_3,param_4,
               (uint)CONCAT11((&DAT_c08b10fc)[param_5 >> 8 & 0xf],(&DAT_c08b10fc)[param_5 & 0xf]));
  return;
}



/* c089408c FUN_c089408c */

/* Boundary evidence: original MIPS .pdata c089408c..c08940df. Semantic name remains unreviewed. */

undefined4 * FUN_c089408c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c08911c4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_c08a4680();
  return param_1;
}



/* c08940e0 FUN_c08940e0 */

void FUN_c08940e0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c08911c4;
  return;
}



/* c0894154 FUN_c0894154 */

/* Boundary evidence: original MIPS .pdata c0894154..c089448b. Semantic name remains unreviewed. */

undefined4 FUN_c0894154(undefined4 param_1,undefined4 *param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  DWORD local_38;
  DWORD local_34;
  undefined4 local_30;
  HKEY local_2c;
  
  uVar2 = 1;
  uVar3 = 0x60;
  uVar5 = 0x40;
  uVar6 = 0x3c;
  uVar7 = 0x60;
  uVar8 = 1;
  uVar4 = 1;
  uVar9 = 0;
  if (param_2 != (undefined4 *)0x0) {
    uVar9 = 1;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,u_Drivers_Display_GPE_c08b1514,0,0,&local_2c);
    if (LVar1 == 0) {
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_2c,L"HorizontalSize",(LPDWORD)0x0,&local_34,(LPBYTE)&local_30,
                               &local_38);
      if ((LVar1 == 0) && (local_34 == 4)) {
        uVar5 = local_30;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_2c,L"VerticalSize",(LPDWORD)0x0,&local_34,(LPBYTE)&local_30,
                               &local_38);
      if ((LVar1 == 0) && (local_34 == 4)) {
        uVar6 = local_30;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_2c,L"LogicalPixelsX",(LPDWORD)0x0,&local_34,(LPBYTE)&local_30,
                               &local_38);
      if ((LVar1 == 0) && (local_34 == 4)) {
        uVar3 = local_30;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_2c,L"LogicalPixelsY",(LPDWORD)0x0,&local_34,(LPBYTE)&local_30,
                               &local_38);
      if ((LVar1 == 0) && (local_34 == 4)) {
        uVar7 = local_30;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_2c,L"AspectRatioX",(LPDWORD)0x0,&local_34,(LPBYTE)&local_30,
                               &local_38);
      if ((LVar1 == 0) && (local_34 == 4)) {
        uVar2 = local_30;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_2c,L"AspectRatioY",(LPDWORD)0x0,&local_34,(LPBYTE)&local_30,
                               &local_38);
      if ((LVar1 == 0) && (local_34 == 4)) {
        uVar8 = local_30;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_2c,L"AspectRatioXY",(LPDWORD)0x0,&local_34,(LPBYTE)&local_30,
                               &local_38);
      if ((LVar1 == 0) && (local_34 == 4)) {
        uVar4 = local_30;
      }
      RegCloseKey(local_2c);
    }
    *param_2 = uVar5;
    param_2[1] = uVar6;
    param_2[2] = uVar3;
    param_2[3] = uVar7;
    param_2[4] = uVar2;
    param_2[5] = uVar8;
    param_2[6] = uVar4;
  }
  return uVar9;
}



/* c08944ac FUN_c08944ac */

/* Boundary evidence: original MIPS .pdata c08944ac..c08944c7. Semantic name remains unreviewed. */

void FUN_c08944ac(void)

{
  FUN_c0891c04();
  return;
}



/* c08944c8 FUN_c08944c8 */

/* Boundary evidence: original MIPS .pdata c08944c8..c089450f. Semantic name remains unreviewed. */

undefined4 FUN_c08944c8(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 1;
}



/* c0894510 FUN_c0894510 */

void FUN_c0894510(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  *(undefined4 *)(param_1 + 8) = param_5;
  *(int *)(param_1 + 0x1c) = param_6;
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  *(undefined4 *)(param_1 + 0x30) = param_3;
  *(undefined4 *)(param_1 + 4) = param_4;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(int *)(param_1 + 0x44) = *(int *)(&LAB_c0891154 + param_6 * 4) >> 3;
  return;
}



/* c0894568 FUN_c0894568 */

void FUN_c0894568(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 == 1) {
    iVar2 = *(int *)(param_2 + 4);
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 8);
    iVar1 = *(int *)(param_2 + 0x1c) + -2;
    *(int *)(param_2 + 8) = (*(int *)(param_1 + 0x40) - iVar2) + -1;
    if (iVar1 < 0) {
      iVar1 = *(int *)(param_2 + 0x1c) + 6;
    }
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 != 4) {
        return;
      }
      uVar3 = *(undefined4 *)(param_2 + 4);
      iVar1 = *(int *)(param_2 + 0x1c) + -6;
      *(int *)(param_2 + 4) = (*(int *)(param_1 + 0x3c) - *(int *)(param_2 + 8)) + -1;
      *(undefined4 *)(param_2 + 8) = uVar3;
      if (iVar1 < 0) {
        iVar1 = *(int *)(param_2 + 0x1c) + 2;
      }
      *(int *)(param_2 + 0x1c) = iVar1;
      return;
    }
    *(int *)(param_2 + 4) = (*(int *)(param_1 + 0x3c) - *(int *)(param_2 + 4)) + -1;
    iVar1 = *(int *)(param_2 + 0x1c) + -4;
    *(int *)(param_2 + 8) = (*(int *)(param_1 + 0x40) - *(int *)(param_2 + 8)) + -1;
    if (iVar1 < 0) {
      iVar1 = *(int *)(param_2 + 0x1c) + 4;
    }
  }
  *(int *)(param_2 + 0x1c) = iVar1;
  return;
}



/* c0894638 FUN_c0894638 */

void FUN_c0894638(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(int *)(param_1 + 0x38) = param_4;
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  *(undefined4 *)(param_1 + 0x30) = param_3;
  if ((param_4 == 1) || (param_4 == 4)) {
    *(undefined4 *)(param_1 + 0x40) = param_2;
    *(undefined4 *)(param_1 + 0x3c) = param_3;
  }
  else {
    *(undefined4 *)(param_1 + 0x3c) = param_2;
    *(undefined4 *)(param_1 + 0x40) = param_3;
  }
  return;
}



/* c0894674 FUN_c0894674 */

void FUN_c0894674(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *param_2;
  iVar4 = param_2[1];
  iVar3 = param_2[2];
  iVar1 = *(int *)(param_1 + 0x38);
  iVar5 = param_2[3];
  if (iVar1 == 1) {
    *param_2 = iVar4;
    param_2[2] = iVar5;
    param_2[1] = *(int *)(param_1 + 0x40) - iVar3;
    param_2[3] = *(int *)(param_1 + 0x40) - iVar2;
  }
  else if (iVar1 == 2) {
    *param_2 = *(int *)(param_1 + 0x3c) - iVar3;
    param_2[2] = *(int *)(param_1 + 0x3c) - iVar2;
    param_2[1] = *(int *)(param_1 + 0x40) - iVar5;
    param_2[3] = *(int *)(param_1 + 0x40) - iVar4;
  }
  else if (iVar1 == 4) {
    *param_2 = *(int *)(param_1 + 0x3c) - iVar5;
    iVar1 = *(int *)(param_1 + 0x3c);
    param_2[1] = iVar2;
    param_2[2] = iVar1 - iVar4;
    param_2[3] = iVar3;
  }
  return;
}



/* c0894728 FUN_c0894728 */

void FUN_c0894728(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *param_2;
  iVar5 = param_2[1];
  iVar2 = param_2[2];
  iVar1 = *(int *)(param_1 + 0x38);
  iVar4 = param_2[3];
  if (iVar1 == 1) {
    param_2[1] = iVar3;
    param_2[3] = iVar2;
    *param_2 = *(int *)(param_1 + 0x40) - iVar4;
    param_2[2] = *(int *)(param_1 + 0x40) - iVar5;
  }
  else if (iVar1 == 2) {
    *param_2 = *(int *)(param_1 + 0x3c) - iVar2;
    param_2[2] = *(int *)(param_1 + 0x3c) - iVar3;
    param_2[1] = *(int *)(param_1 + 0x40) - iVar4;
    param_2[3] = *(int *)(param_1 + 0x40) - iVar5;
  }
  else if (iVar1 == 4) {
    param_2[1] = *(int *)(param_1 + 0x3c) - iVar2;
    iVar1 = *(int *)(param_1 + 0x3c);
    *param_2 = iVar5;
    param_2[3] = iVar1 - iVar3;
    param_2[2] = iVar4;
  }
  return;
}



/* c08947dc FUN_c08947dc */

int FUN_c08947dc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&LAB_c0891154 + *(int *)(param_1 + 0x1c) * 4);
  iVar1 = *(int *)(param_1 + 4);
  if (iVar3 == 0xf) {
    iVar3 = 0x10;
  }
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 == 0) {
    iVar3 = (iVar3 * param_2 >> 3) + *(int *)(param_1 + 8) * param_3;
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        iVar3 = ((*(int *)(param_1 + 0x40) - param_3) + -1) * *(int *)(param_1 + 8) +
                (((*(int *)(param_1 + 0x3c) - param_2) + -1) * iVar3 >> 3);
      }
      else {
        if (iVar2 != 4) {
          return iVar1;
        }
        iVar3 = (((*(int *)(param_1 + 0x3c) - param_3) + -1) * iVar3 >> 3) +
                *(int *)(param_1 + 8) * param_2;
      }
      return iVar3 + iVar1;
    }
    iVar3 = ((*(int *)(param_1 + 0x40) - param_2) + -1) * *(int *)(param_1 + 8) +
            (iVar3 * param_3 >> 3);
  }
  return iVar3 + iVar1;
}



/* c0894910 FUN_c0894910 */

/* Boundary evidence: original MIPS .pdata c0894910..c0894947. Semantic name remains unreviewed. */

void FUN_c0894910(undefined4 *param_1)

{
  if (param_1[2] != 0) {
    (*DAT_c08bc894)(param_1[3],*param_1,param_1[1]);
  }
  return;
}



/* c0894948 FUN_c0894948 */

/* Boundary evidence: original MIPS .pdata c0894948..c089498b. Semantic name remains unreviewed. */

undefined4 * FUN_c0894948(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c08911c4;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c089498c FUN_c089498c */

/* Boundary evidence: original MIPS .pdata c089498c..c0894ac7. Semantic name remains unreviewed. */

undefined4 * FUN_c089498c(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  
  *param_1 = &PTR_FUN_c089104c;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  memset(param_1 + 3,0,0x10);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[7] = 9;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  if ((0 < param_2) && (0 < param_3)) {
    param_1[7] = param_4;
    param_1[0xb] = param_2;
    param_1[0xc] = param_3;
    iVar3 = *(int *)(&LAB_c0891154 + param_4 * 4) * param_2 + 7;
    if (iVar3 < 0) {
      iVar3 = *(int *)(&LAB_c0891154 + param_4 * 4) * param_2 + 0xe;
    }
    uVar2 = (iVar3 >> 3) + 3U & 0xfffffffc;
    param_1[2] = uVar2;
    pvVar1 = operator_new(uVar2 * param_3);
    param_1[10] = 1;
    param_1[1] = pvVar1;
    param_1[0x11] = *(int *)(&LAB_c0891154 + param_1[7] * 4) >> 3;
  }
  return param_1;
}



/* c0894ac8 FUN_c0894ac8 */

/* Boundary evidence: original MIPS .pdata c0894ac8..c0894b37. Semantic name remains unreviewed. */

void FUN_c0894ac8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c089104c;
  if ((param_1[10] != 0) && ((void *)param_1[1] != (void *)0x0)) {
    operator_delete((void *)param_1[1]);
  }
  if (param_1[5] != 0) {
    (*DAT_c08bc894)(param_1[6],param_1[3],param_1[4]);
  }
  return;
}



/* c0894b38 FUN_c0894b38 */

/* WARNING: Removing unreachable block (ram,0xc0894c48) */
/* Boundary evidence: original MIPS .pdata c0894b38..c0895377. Semantic name remains unreviewed. */

undefined4 FUN_c0894b38(int *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint *puVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  int iVar13;
  byte bVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  uint *puVar18;
  int iVar19;
  byte *pbVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  uint *puVar28;
  ushort uVar29;
  uint uVar30;
  int iVar31;
  uint local_128 [32];
  uint local_a8 [32];
  
  iVar13 = *(int *)(param_2 + 0x28);
  iVar27 = 0;
  iVar22 = *(int *)(&LAB_c0891154 + *(int *)(iVar13 + 0x1c) * 4);
  iVar6 = *(int *)(param_2 + 0x14);
  uVar23 = (2 << (iVar22 - 1U & 0x1f)) - 1;
  uVar4 = *(ushort *)(param_2 + 0x34);
  iVar24 = *(int *)(param_2 + 0x18) + iVar6;
  iVar8 = iVar6 - *(int *)(param_2 + 0x10);
  bVar7 = (byte)(uVar4 >> 8);
  uVar9 = *(uint *)(param_2 + 0x20);
  uVar30 = *(uint *)(param_2 + 0x24);
  iVar21 = *(int *)(iVar13 + 8);
  iVar31 = 0;
  iVar25 = 0;
  iVar26 = 0;
  if (*(int *)(iVar13 + 0x20) != 0) {
    (**(code **)(*param_1 + 0x60))();
  }
  if (iVar22 == 0x18) {
    iVar27 = iVar21;
    iVar31 = iVar21;
    switch(*(undefined4 *)(param_2 + 0x1c)) {
    case 0:
      goto LAB_c0895024;
    case 1:
      iVar27 = 3;
      break;
    case 2:
      iVar27 = -3;
      break;
    case 3:
      iVar31 = -3;
      break;
    case 4:
      iVar27 = -iVar21;
      iVar31 = -3;
      break;
    case 5:
      iVar27 = -3;
      goto LAB_c0895010;
    case 6:
      iVar27 = 3;
LAB_c0895010:
      iVar31 = -iVar21;
      break;
    case 7:
      iVar27 = -iVar21;
LAB_c0895024:
      iVar31 = 3;
      break;
    default:
      goto LAB_c0895348;
    }
    bVar1 = *(byte *)(param_2 + 0x2c);
    bVar2 = *(byte *)(param_2 + 0x2d);
    bVar3 = *(byte *)(param_2 + 0x2e);
    iVar13 = *(int *)(param_2 + 0xc);
    pbVar20 = (byte *)(*(int *)(param_2 + 8) * iVar21 + *(int *)(param_2 + 4) * 3 +
                      *(int *)(*(int *)(param_2 + 0x28) + 4));
    do {
      if (iVar13 == 0) {
        return 0;
      }
      uVar23 = uVar30 & 0x1f;
      uVar30 = uVar30 + 1;
      bVar12 = bVar7;
      if ((uVar9 >> uVar23 & 1) == 0) {
        bVar12 = (byte)uVar4;
      }
      switch(bVar12) {
      case 1:
        *pbVar20 = 0;
        pbVar20[1] = 0;
        pbVar20[2] = 0;
        break;
      case 2:
        *pbVar20 = ~(*pbVar20 | bVar1);
        bVar12 = pbVar20[2] | bVar3;
        bVar14 = bVar2 | pbVar20[1];
        goto LAB_c0895120;
      case 3:
        *pbVar20 = ~bVar1 & *pbVar20;
        bVar12 = ~bVar3 & pbVar20[2];
        pbVar20[1] = ~bVar2 & pbVar20[1];
        goto LAB_c089515c;
      case 4:
        *pbVar20 = ~bVar1;
        pbVar20[1] = ~bVar2;
        bVar12 = ~bVar3;
LAB_c089515c:
        pbVar20[2] = bVar12;
        break;
      case 5:
        *pbVar20 = ~*pbVar20 & bVar1;
        bVar12 = ~pbVar20[2] & bVar3;
        pbVar20[1] = ~pbVar20[1] & bVar2;
        goto LAB_c08951a8;
      case 6:
        pbVar20[1] = ~pbVar20[1];
        bVar12 = ~pbVar20[2];
        *pbVar20 = ~*pbVar20;
        goto LAB_c08951a8;
      case 7:
        *pbVar20 = *pbVar20 ^ bVar1;
        pbVar20[1] = bVar2 ^ pbVar20[1];
        pbVar20[2] = pbVar20[2] ^ bVar3;
        break;
      case 8:
        *pbVar20 = ~(*pbVar20 & bVar1);
        bVar14 = bVar2 & pbVar20[1];
        bVar12 = pbVar20[2] & bVar3;
        goto LAB_c0895120;
      case 9:
        *pbVar20 = *pbVar20 & bVar1;
        pbVar20[1] = bVar2 & pbVar20[1];
        pbVar20[2] = pbVar20[2] & bVar3;
        break;
      case 10:
        *pbVar20 = ~(*pbVar20 ^ bVar1);
        bVar14 = bVar2 ^ pbVar20[1];
        bVar12 = pbVar20[2] ^ bVar3;
LAB_c0895120:
        bVar12 = ~bVar12;
        bVar14 = ~bVar14;
LAB_c0895124:
        pbVar20[1] = bVar14;
        pbVar20[2] = bVar12;
        break;
      case 0xb:
        break;
      case 0xc:
        *pbVar20 = ~bVar1 | *pbVar20;
        bVar14 = ~bVar2 | pbVar20[1];
        bVar12 = ~bVar3 | pbVar20[2];
        goto LAB_c0895124;
      case 0xd:
        *pbVar20 = bVar1;
        pbVar20[1] = bVar2;
        pbVar20[2] = bVar3;
        break;
      case 0xe:
        *pbVar20 = ~*pbVar20 | bVar1;
        bVar14 = ~pbVar20[1] | bVar2;
        bVar12 = ~pbVar20[2] | bVar3;
        goto LAB_c0895124;
      case 0xf:
        bVar12 = pbVar20[2] | bVar3;
        *pbVar20 = *pbVar20 | bVar1;
        pbVar20[1] = bVar2 | pbVar20[1];
LAB_c08951a8:
        pbVar20[2] = bVar12;
        break;
      case 0x10:
        *pbVar20 = 0xff;
        pbVar20[1] = 0xff;
        pbVar20[2] = 0xff;
        break;
      default:
        goto LAB_c0895348;
      }
      pbVar20 = pbVar20 + iVar31;
      if (iVar6 != 0) {
        if (iVar24 < 0) {
          iVar24 = iVar6 + iVar24;
        }
        else {
          pbVar20 = pbVar20 + iVar27;
          iVar24 = iVar8 + iVar24;
        }
      }
      iVar13 = iVar13 + -1;
    } while( true );
  }
  iVar13 = 0x20 / iVar22;
  if (iVar22 == 0) {
    trap(0x1c00);
  }
  if (0 < iVar13) {
    uVar11 = *(uint *)(param_2 + 0x2c);
    uVar15 = 0;
    iVar17 = 0;
    iVar19 = iVar13;
    do {
      uVar10 = uVar15;
      if (iVar22 < 8) {
        uVar10 = 8U - iVar22 ^ uVar15;
      }
      *(uint *)((int)local_a8 + iVar17) = (uVar11 & uVar23) << (uVar10 & 0x1f);
      *(uint *)((int)local_128 + iVar17) = uVar23 << (uVar10 & 0x1f);
      uVar15 = uVar15 + iVar22;
      iVar19 = iVar19 + -1;
      iVar17 = iVar17 + 4;
    } while (iVar19 != 0);
  }
  switch(*(undefined4 *)(param_2 + 0x1c)) {
  case 0:
    iVar31 = iVar21;
    goto LAB_c0894d3c;
  case 1:
    iVar26 = 1;
    iVar27 = iVar21;
    break;
  case 2:
    iVar26 = -1;
    iVar27 = iVar21;
    break;
  case 3:
    iVar25 = -1;
    iVar31 = iVar21;
    break;
  case 4:
    iVar25 = -1;
    iVar31 = -iVar21;
    break;
  case 5:
    iVar26 = -1;
    goto LAB_c0894d28;
  case 6:
    iVar26 = 1;
LAB_c0894d28:
    iVar27 = -iVar21;
    break;
  case 7:
    iVar31 = -iVar21;
LAB_c0894d3c:
    iVar25 = 1;
    break;
  default:
LAB_c0895348:
    return 0x80070057;
  }
  iVar19 = *(int *)(param_2 + 4);
  puVar5 = (uint *)((iVar19 * iVar22 >> 3 & 0xfffffffcU) + *(int *)(param_2 + 8) * iVar21 +
                   *(int *)(*(int *)(param_2 + 0x28) + 4));
  iVar21 = iVar19 % iVar13;
  if (iVar13 == 0) {
    trap(0x1c00);
  }
  if ((iVar13 == -1) && (iVar19 == -0x80000000)) {
    trap(0x1800);
  }
  uVar23 = *puVar5;
  iVar22 = *(int *)(param_2 + 0xc);
  if (iVar22 != 0) {
    puVar18 = local_128 + iVar21;
    puVar28 = local_a8 + iVar21;
    do {
      uVar11 = uVar30 & 0x1f;
      uVar30 = uVar30 + 1;
      uVar15 = *puVar28;
      uVar29 = (ushort)bVar7;
      if ((uVar9 >> uVar11 & 1) == 0) {
        uVar29 = uVar4 & 0xff;
      }
      uVar11 = uVar23;
      switch(uVar29) {
      case 1:
        uVar11 = 0;
        break;
      case 2:
        uVar15 = uVar15 | uVar23;
        goto LAB_c0894e5c;
      case 3:
        uVar11 = ~uVar15 & uVar23;
        break;
      case 4:
        uVar11 = ~uVar15;
        break;
      case 5:
        uVar11 = ~uVar23 & uVar15;
        break;
      case 6:
        uVar11 = ~uVar23;
        break;
      case 7:
        uVar11 = uVar15 ^ uVar23;
        break;
      case 8:
        uVar15 = uVar15 & uVar23;
        goto LAB_c0894e5c;
      case 9:
        uVar11 = uVar15 & uVar23;
        break;
      case 10:
        uVar15 = uVar15 ^ uVar23;
LAB_c0894e5c:
        uVar11 = ~uVar15;
        break;
      case 0xb:
        break;
      case 0xc:
        uVar11 = ~uVar15 | uVar23;
        break;
      case 0xd:
        uVar11 = uVar15;
        break;
      case 0xe:
        uVar11 = ~uVar23 | uVar15;
        break;
      case 0xf:
        uVar11 = uVar15 | uVar23;
        break;
      case 0x10:
        uVar11 = 0xffffffff;
        break;
      default:
        goto LAB_c0895348;
      }
      uVar23 = ~*puVar18 & uVar23 | *puVar18 & uVar11;
      if (iVar22 == 1) {
        *puVar5 = uVar23;
        return 0;
      }
      puVar16 = (uint *)((int)puVar5 + iVar27);
      iVar21 = iVar21 + iVar25;
      puVar28 = puVar28 + iVar25;
      puVar18 = puVar18 + iVar25;
      if (iVar6 != 0) {
        if (iVar24 < 0) {
          iVar24 = iVar6 + iVar24;
        }
        else {
          puVar16 = (uint *)((int)puVar16 + iVar31);
          iVar21 = iVar21 + iVar26;
          puVar28 = puVar28 + iVar26;
          puVar18 = puVar18 + iVar26;
          iVar24 = iVar8 + iVar24;
        }
      }
      if (iVar21 < 0) {
        puVar16 = puVar16 + -1;
        iVar21 = iVar21 + iVar13;
        puVar28 = puVar28 + iVar13;
        puVar18 = puVar18 + iVar13;
      }
      else if (iVar13 <= iVar21) {
        puVar16 = puVar16 + 1;
        iVar21 = iVar21 - iVar13;
        puVar28 = puVar28 + -iVar13;
        puVar18 = puVar18 + -iVar13;
      }
      if (puVar16 != puVar5) {
        *puVar5 = uVar23;
        uVar23 = *puVar16;
        puVar5 = puVar16;
      }
      iVar22 = iVar22 + -1;
    } while (iVar22 != 0);
  }
  return 0;
}



/* c0895378 FUN_c0895378 */

/* Boundary evidence: original MIPS .pdata c0895378..c0897027. Semantic name remains unreviewed. */

undefined4 FUN_c0895378(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  byte *pbVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  byte bVar16;
  uint *puVar17;
  byte *pbVar18;
  byte bVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int *piVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  int *piVar27;
  byte *pbVar28;
  byte *pbVar29;
  int iVar30;
  uint uVar31;
  uint uVar32;
  int iVar33;
  uint uVar34;
  int iVar35;
  uint uVar36;
  uint uVar37;
  byte *pbVar38;
  int iVar39;
  byte *pbVar40;
  int iVar41;
  byte *pbVar42;
  int iVar43;
  byte *pbVar44;
  uint uVar45;
  uint uVar46;
  int iVar47;
  byte local_228;
  uint local_224;
  uint local_220;
  uint local_21c;
  uint local_218;
  uint local_214;
  uint local_210;
  uint local_208;
  uint local_204;
  uint local_200;
  uint local_1fc;
  uint local_1f4;
  int local_1f0;
  byte *local_1ec;
  uint local_1e8;
  uint local_1e0;
  int local_1dc;
  uint local_1d4;
  uint local_1d0;
  byte *local_1c8;
  byte *local_1c4;
  byte *local_1c0;
  byte *local_1bc;
  int local_1b8;
  int local_1b0;
  byte *local_1ac;
  int local_1a8;
  byte local_1a0;
  byte *local_19c;
  byte *local_198;
  uint local_194;
  byte *local_190;
  uint *local_188;
  int local_184;
  uint local_180;
  uint local_17c;
  int local_178;
  int local_174;
  uint local_16c;
  int local_168;
  int local_164;
  byte local_160;
  uint *local_15c;
  uint local_158;
  uint local_154;
  uint local_150;
  int local_14c;
  int local_148;
  uint local_144;
  uint local_140;
  int local_13c;
  byte *local_138;
  byte *local_134;
  byte *local_130;
  int local_12c;
  byte *local_128;
  byte *local_124;
  byte *local_120;
  int local_11c;
  byte *local_118;
  uint local_114;
  int local_110;
  byte *local_108;
  byte *local_104;
  byte *local_100;
  byte *local_fc;
  int local_f8;
  int local_e8;
  byte local_e0;
  byte *local_dc;
  byte *local_d8;
  byte *local_d0;
  uint local_cc;
  byte *local_c8;
  uint local_c4;
  int local_c0;
  uint *local_b8;
  int local_b4;
  uint local_b0;
  uint local_ac;
  int local_a8;
  int local_98;
  byte local_90;
  uint *local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint *local_64;
  uint *local_60;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  uVar25 = *(uint *)(param_2 + 0x28);
  piVar23 = *(int **)(param_2 + 0x14);
  bVar16 = (byte)(uVar25 >> 8);
  bVar19 = (byte)uVar25;
  local_1dc = piVar23[2] - *piVar23;
  local_c0 = 0;
  local_148 = piVar23[3] - piVar23[1];
  bVar9 = false;
  local_c4 = (uint)(((uVar25 >> 1 ^ uVar25) & 0x5555) != 0);
  cVar3 = *(char *)(param_2 + 0x4f);
  iVar47 = *(int *)(param_2 + 0x34);
  iVar41 = *(int *)(param_2 + 0x38);
  piVar23 = *(int **)(param_2 + 0x14);
  bVar5 = false;
  iVar39 = 0;
  iVar35 = 0;
  iVar33 = 0;
  local_11c = 0;
  iVar43 = 0;
  local_14c = 0;
  bVar8 = false;
  local_13c = 0;
  bVar7 = false;
  local_12c = 0;
  if ((cVar3 != '\0') && (cVar3 != '\x01')) {
    return 0x80004001;
  }
  local_110 = 0;
  if (*(int *)(param_2 + 0x4c) == 0xff0000) {
    local_204 = local_224;
    local_214 = local_224;
    local_208 = local_224;
    local_1fc = local_224;
    local_200 = local_224;
    local_1f4 = local_224;
    local_1e0 = local_224;
    local_114 = 0;
    local_21c = local_224;
    local_140 = local_220;
  }
  else {
    iVar26 = *(int *)(param_2 + 4);
    local_114 = 0xff000000;
    if (*(int *)(iVar26 + 0x10) == 3) {
      puVar17 = *(uint **)(iVar26 + 0xc);
      local_204 = *puVar17;
      local_214 = puVar17[1];
      local_208 = puVar17[2];
      local_21c = 0;
      if ((*(int *)(&LAB_c0891154 + *(int *)(iVar26 + 0x1c) * 4) == 0x20) &&
         (((local_208 | local_214 | local_204) & 0xff000000) == 0)) {
        local_21c = 0xff000000;
      }
    }
    else if ((*(int *)(iVar26 + 0x10) == 4) &&
            (8 < *(int *)(&LAB_c0891154 + *(int *)(iVar26 + 0x1c) * 4))) {
      puVar17 = *(uint **)(iVar26 + 0xc);
      local_204 = *puVar17;
      local_214 = puVar17[1];
      local_208 = puVar17[2];
      local_21c = puVar17[3];
    }
    else {
      local_204 = 0xff;
      local_214 = 0xff00;
      local_208 = 0xff0000;
      local_21c = 0xff000000;
      local_12c = 1;
    }
    local_1fc = 0;
    for (uVar20 = local_204; (uVar20 != 0 && ((uVar20 & 1) == 0)); uVar20 = uVar20 >> 1) {
      local_1fc = local_1fc + 1;
    }
    local_200 = 0;
    for (uVar20 = local_214; (uVar20 != 0 && ((uVar20 & 1) == 0)); uVar20 = uVar20 >> 1) {
      local_200 = local_200 + 1;
    }
    local_1f4 = 0;
    for (uVar20 = local_208; (uVar20 != 0 && ((uVar20 & 1) == 0)); uVar20 = uVar20 >> 1) {
      local_1f4 = local_1f4 + 1;
    }
    local_1e0 = 0;
    for (uVar20 = local_21c; (uVar20 != 0 && ((uVar20 & 1) == 0)); uVar20 = uVar20 >> 1) {
      local_1e0 = local_1e0 + 1;
    }
    if (cVar3 == '\0') {
      local_114 = 0;
      local_140 = local_220;
    }
    else {
      iVar26 = *(int *)(*(int *)(param_2 + 8) + 0x10);
      if (iVar26 == 4) {
        local_114 = *(uint *)(*(int *)(*(int *)(param_2 + 8) + 0xc) + 0xc);
      }
      else if (iVar26 != 3) {
        local_114 = 0;
      }
      local_140 = 0;
      for (uVar20 = local_114; (uVar20 & 1) == 0; uVar20 = uVar20 >> 1) {
        local_140 = local_140 + 1;
      }
    }
    local_c4 = 1;
    local_110 = 1;
  }
  bVar6 = false;
  if ((local_1dc < 0) || (local_148 < 0)) {
    iVar26 = *piVar23;
    local_58 = iVar26;
    piVar27 = piVar23 + 1;
    local_54 = *piVar27;
    piVar1 = piVar23 + 2;
    local_50 = *piVar1;
    piVar2 = piVar23 + 3;
    piVar23 = &local_58;
    local_4c = *piVar2;
    if (local_1dc < 0) {
      local_1dc = -local_1dc;
      local_58 = *piVar1;
      local_50 = iVar26;
      if (iVar47 == 0) {
        iVar47 = 1;
      }
      else {
        iVar47 = 0;
      }
    }
    if (local_148 < 0) {
      local_148 = -local_148;
      local_54 = *piVar2;
      local_4c = *piVar27;
      if (iVar41 == 0) {
        iVar41 = 1;
      }
      else {
        iVar41 = 0;
      }
    }
  }
  if ((*(uint *)(param_2 + 0x24) & 8) == 0) {
    local_1d0 = local_220;
    local_1e8 = local_220;
    local_210 = local_220;
    local_1d4 = local_220;
    local_144 = local_220;
    local_218 = local_220;
    iVar26 = iVar43;
    goto LAB_c0895a9c;
  }
  piVar27 = *(int **)(param_2 + 0x18);
  iVar26 = piVar27[2] - *piVar27;
  iVar30 = piVar27[3] - piVar27[1];
  if (iVar26 < local_1dc) {
    local_14c = 1;
    iVar13 = local_1dc;
    iVar21 = iVar26;
LAB_c0895810:
    local_1e8 = iVar21 * 2;
    local_1d0 = local_1e8 + iVar13 * -2;
    local_11c = 1;
    if (bVar5) {
      local_210 = local_1dc * 2 - iVar26;
    }
    else {
      local_210 = iVar26 * 3 + local_1dc * -2;
    }
  }
  else {
    if (local_1dc < iVar26) {
      bVar5 = true;
      iVar13 = iVar26;
      iVar21 = local_1dc;
      goto LAB_c0895810;
    }
    local_1d0 = local_220;
    local_1e8 = local_220;
    local_210 = local_220;
  }
  if (iVar30 < local_148) {
    bVar7 = true;
    iVar26 = local_148;
    iVar13 = iVar30;
LAB_c089589c:
    local_144 = iVar13 * 2;
    local_1d4 = local_144 + iVar26 * -2;
    bVar8 = true;
    if (bVar6) {
      local_220 = local_148 * 2 - iVar30;
    }
    else {
      local_220 = iVar30 * 3 + local_148 * -2;
    }
  }
  else {
    if (local_148 < iVar30) {
      bVar6 = true;
      local_13c = 1;
      iVar26 = iVar30;
      iVar13 = local_148;
      goto LAB_c089589c;
    }
    local_1d4 = local_220;
    local_144 = local_220;
  }
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar35 = FUN_c08a5678(&local_48,*(int **)(param_2 + 0x1c),piVar23);
    if (iVar35 != 0) {
      return 0;
    }
    if (iVar47 == 0) {
      iVar39 = piVar23[2] - local_40;
    }
    else {
      iVar39 = local_48 - *piVar23;
    }
    if (iVar41 == 0) {
      iVar35 = piVar23[3] - local_3c;
    }
    else {
      iVar35 = local_44 - piVar23[1];
    }
    local_1dc = local_40 - local_48;
    local_148 = local_3c - local_44;
  }
  iVar26 = iVar39;
  if (bVar5) {
    for (; (int)local_210 < 0; local_210 = local_210 + local_1e8) {
      iVar33 = iVar33 + 1;
    }
    local_210 = local_210 + local_1d0;
  }
  for (; iVar26 != 0; iVar26 = iVar26 + -1) {
    if (bVar5) {
      for (; (int)local_210 < 0; local_210 = local_210 + local_1e8) {
        iVar33 = iVar33 + 1;
      }
LAB_c08959b8:
      local_210 = local_210 + local_1d0;
LAB_c08959bc:
      iVar33 = iVar33 + 1;
    }
    else {
      if (local_14c == 0) goto LAB_c08959bc;
      if (-1 < (int)local_210) goto LAB_c08959b8;
      local_210 = local_210 + local_1e8;
    }
  }
  iVar26 = iVar35;
  if (local_13c == 0) {
    local_218 = local_220;
    iVar30 = iVar35;
    if (bVar7) {
      for (; iVar26 = iVar43, iVar30 != 0; iVar30 = iVar30 + -1) {
        uVar20 = local_144;
        if (-1 < (int)local_218) {
          iVar43 = iVar43 + 1;
          uVar20 = local_1d4;
        }
        local_218 = local_218 + uVar20;
      }
    }
  }
  else {
    local_218 = local_1d4 * iVar35 + local_220;
  }
LAB_c0895a9c:
  uVar20 = *(uint *)(param_2 + 0x24) & 4;
  pbVar18 = *(byte **)(param_2 + 0x20);
  local_b8 = (uint *)0x0;
  local_8c = (uint *)0x0;
  local_108 = (byte *)0x0;
  local_dc = (byte *)0x0;
  local_1c8 = (byte *)0x0;
  local_19c = (byte *)0x0;
  local_134 = pbVar18;
  local_cc = uVar20;
  if ((((*(int *)(param_2 + 8) != 0) &&
       (FUN_c08a5b70((int *)&local_1c8,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
                     *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar33,iVar26),
       local_134 = local_1ac, uVar20 != 0)) &&
      (iVar43 = *(int *)(param_2 + 8), 8 < *(int *)(&LAB_c0891154 + *(int *)(iVar43 + 0x1c) * 4)))
     && ((*(int *)(iVar43 + 0x10) == 4 || (*(int *)(iVar43 + 0x10) == 3)))) {
    puVar17 = *(uint **)(iVar43 + 0xc);
    local_134 = (byte *)(puVar17[2] | puVar17[1] | *puVar17);
  }
  iVar43 = *(int *)(param_2 + 0x10);
  if (iVar43 != 0) {
    piVar27 = *(int **)(param_2 + 0x30);
    if (piVar27 == (int *)0x0) {
      iVar30 = 0;
      iVar43 = 0;
    }
    else {
      iVar30 = *(int *)(iVar43 + 0x30) - piVar27[1];
      iVar43 = *(int *)(iVar43 + 0x2c) - *piVar27;
    }
    iVar13 = *(int *)(param_2 + 0x10);
    iVar21 = *(int *)(iVar13 + 0x2c);
    if (iVar21 == 0) {
      trap(0x1c00);
    }
    if ((iVar21 == -1) && (*piVar23 + iVar43 == -0x80000000)) {
      trap(0x1800);
    }
    local_38 = (*piVar23 + iVar43) % iVar21;
    iVar21 = *(int *)(iVar13 + 0x2c);
    if (iVar21 == 0) {
      trap(0x1c00);
    }
    if ((iVar21 == -1) && (piVar23[2] + iVar43 == -0x80000000)) {
      trap(0x1800);
    }
    local_30 = (piVar23[2] + iVar43) % iVar21;
    iVar43 = *(int *)(iVar13 + 0x30);
    if (iVar43 == 0) {
      trap(0x1c00);
    }
    if ((iVar43 == -1) && (piVar23[1] + iVar30 == -0x80000000)) {
      trap(0x1800);
    }
    local_34 = (piVar23[1] + iVar30) % iVar43;
    iVar43 = *(int *)(iVar13 + 0x30);
    local_2c = (piVar23[3] + iVar30) % iVar43;
    if (iVar43 == 0) {
      trap(0x1c00);
    }
    if ((iVar43 == -1) && (piVar23[3] + iVar30 == -0x80000000)) {
      trap(0x1800);
    }
    FUN_c08a6078((int *)&local_b8,iVar13,*(int *)(param_2 + 0x34),*(int *)(param_2 + 0x38),&local_38
                );
  }
  if (*(int *)(param_2 + 0xc) == 0) {
    local_104 = (byte *)0x0;
  }
  else {
    FUN_c08a5b70((int *)&local_108,*(int *)(param_2 + 0xc),*(int *)(param_2 + 0x34),
                 *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x2c),iVar33,iVar26);
  }
  iVar33 = *(int *)(param_2 + 4);
  local_164 = *(int *)(&LAB_c0891154 + *(int *)(iVar33 + 0x1c) * 4);
  if (local_164 < 8) {
    FUN_c08a5b70((int *)&local_188,iVar33,iVar47,iVar41,piVar23,iVar39,iVar35);
    bVar5 = false;
  }
  else {
    bVar5 = true;
    bVar9 = true;
    if (iVar41 == 0) {
      local_184 = -*(int *)(iVar33 + 8);
      iVar33 = ((piVar23[3] - iVar35) + -1) * *(int *)(iVar33 + 8) + *(int *)(iVar33 + 4);
    }
    else {
      iVar33 = *(int *)(param_2 + 4);
      local_184 = *(int *)(iVar33 + 8);
      iVar33 = (piVar23[1] + iVar35) * *(int *)(iVar33 + 8) + *(int *)(iVar33 + 4);
    }
    local_168 = local_164 >> 3;
    if (iVar47 == 0) {
      if (local_164 < 0) {
        local_168 = local_164 + 7 >> 3;
      }
      local_168 = -local_168;
      iVar43 = -(((piVar23[2] - iVar39) + -1) * local_168);
    }
    else {
      if (local_164 < 0) {
        local_168 = local_164 + 7 >> 3;
      }
      iVar43 = (*piVar23 + iVar39) * local_168;
    }
    local_188 = (uint *)(iVar33 + iVar43);
    local_16c = (2 << (local_164 - 1U & 0x1f)) - 1;
    local_150 = 0;
  }
  local_c8 = pbVar18;
  pbVar29 = pbVar18;
  if (bVar8) {
    local_c8 = local_104;
    pbVar29 = local_1c4;
  }
  uVar20 = local_154;
  iVar33 = local_164;
  pbVar28 = local_1c4;
  pbVar38 = pbVar18;
  pbVar40 = pbVar18;
  pbVar42 = pbVar18;
  pbVar44 = pbVar18;
  local_228 = bVar19;
  local_1ec = pbVar18;
  local_138 = pbVar18;
  local_130 = pbVar18;
  local_128 = pbVar18;
  local_124 = pbVar18;
  local_120 = pbVar18;
  puVar17 = local_b8;
  if (*(int *)(param_2 + 0x28) == 0) {
    local_194 = 0;
    uVar31 = local_194;
    local_84 = local_194;
  }
  else {
    uVar31 = local_16c;
    local_194 = local_16c;
    local_84 = local_16c;
    if (*(int *)(param_2 + 0x28) != 0xffff) {
      uVar25 = uVar25 & 0xff;
      local_194 = *(uint *)(param_2 + 0x20) & local_16c;
      uVar31 = local_194;
      local_84 = local_194;
      if (((((bVar16 != uVar25) || (local_cc != 0)) || (local_110 != 0)) || (local_11c != 0)) ||
         ((uVar25 != 0xcc && ((uVar25 != 0xf0 || (*(int *)(param_2 + 0x10) != 0)))))) {
        local_c0 = 1;
      }
    }
  }
  do {
    puVar11 = local_188;
    if (local_148 == 0) {
      return 0;
    }
    local_148 = local_148 + -1;
    if (bVar8) {
      uVar25 = local_1d4;
      if (local_13c == 0) {
        pbVar28 = pbVar29;
        local_1c4 = pbVar29;
        local_104 = local_c8;
        if ((int)local_218 < 0) {
          local_1c4 = (byte *)0x0;
          local_104 = (byte *)0x0;
          uVar25 = local_144;
          pbVar28 = (byte *)0x0;
        }
      }
      else {
        for (; (int)local_218 < 0; local_218 = local_218 + local_144) {
          local_1c8 = pbVar28 + (int)local_1c8;
          local_108 = local_104 + (int)local_108;
        }
      }
      local_218 = local_218 + uVar25;
    }
    pbVar10 = local_1c8;
    if (local_1c8 != (byte *)0x0) {
      local_19c = local_1c8;
      pbVar10 = pbVar28 + (int)local_1c8;
      if (local_1b0 == 0) {
        local_198 = *(byte **)local_1c8;
        local_190 = local_1bc;
      }
    }
    local_1c8 = pbVar10;
    if (local_108 != (byte *)0x0) {
      local_dc = local_108;
      local_d8 = *(byte **)local_108;
      local_108 = local_104 + (int)local_108;
      local_d0 = local_fc;
    }
    local_b8 = puVar17;
    if (puVar17 != (uint *)0x0) {
      local_60 = (uint *)((int)puVar17 - local_68);
      iVar43 = local_70 + -1;
      local_b8 = local_64;
      local_70 = local_6c;
      if (iVar43 != 0) {
        local_b8 = (uint *)(local_b4 + (int)puVar17);
        local_70 = iVar43;
      }
      local_88 = *puVar17;
      local_8c = puVar17;
      local_80 = local_ac;
      local_7c = local_74;
    }
    local_188 = (uint *)((int)puVar11 + local_184);
    if (!bVar5) {
      local_158 = *puVar11;
      local_150 = local_17c;
    }
    if (local_14c != 0) {
      local_138 = local_dc;
      local_130 = local_d8;
      local_1ec = local_d0;
      local_128 = local_19c;
      local_120 = local_198;
      local_124 = local_190;
      pbVar38 = local_dc;
      pbVar40 = local_d8;
      pbVar42 = local_d0;
    }
    local_1f0 = 0;
    uVar25 = local_210;
    local_15c = puVar11;
    local_118 = pbVar44;
    if (0 < local_1dc) {
      do {
        if (local_19c != (byte *)0x0) {
          if (local_1b0 == 0) {
            if (((uint)local_190 & 0xff00) == 0) {
              local_19c = local_19c + local_1a8;
              local_190 = local_1c0;
              local_198 = *(byte **)local_19c;
            }
            uVar31 = (uint)local_190 >> 0x10;
            local_190 = local_190 + local_1b8;
            uVar31 = (uint)local_198 >> ((uVar31 ^ local_1a0) & 0x1f);
          }
          else {
            pbVar44 = local_19c + 2;
            pbVar28 = local_19c + 1;
            bVar4 = *local_19c;
            local_19c = local_19c + local_1a8;
            uVar31 = ((uint)*pbVar44 * 0x100 + (uint)*pbVar28) * 0x100 + (uint)bVar4;
          }
          uVar31 = uVar31 & (uint)local_1ac;
          pbVar44 = (byte *)(uVar31 & (uint)local_134);
          if (*(int *)(param_2 + 0x3c) != 0) {
            uVar31 = *(uint *)(uVar31 * 4 + *(int *)(param_2 + 0x3c));
          }
          local_194 = uVar31;
          local_118 = pbVar44;
          if (*(code **)(param_2 + 0x40) != (code *)0x0) {
            uVar31 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),uVar31);
            puVar11 = local_15c;
            uVar20 = local_154;
            iVar33 = local_164;
            local_194 = uVar31;
            bVar5 = bVar9;
          }
        }
        if (local_c0 == 0) {
LAB_c0896e60:
          if (bVar5) {
            if (iVar33 == 8) {
              *(byte *)puVar11 = (byte)uVar31;
              puVar11 = local_15c;
              uVar20 = local_154;
              iVar33 = local_164;
              uVar31 = local_194;
            }
            else if (iVar33 == 0x10) {
              *(short *)puVar11 = (short)uVar31;
              puVar11 = local_15c;
              uVar20 = local_154;
              iVar33 = local_164;
              uVar31 = local_194;
            }
            else if (iVar33 == 0x18) {
              *(byte *)puVar11 = (byte)uVar31;
              *(byte *)((int)local_15c + 1) = (byte)(local_194 >> 8);
              *(byte *)((int)local_15c + 2) = (byte)(local_194 >> 0x10);
              puVar11 = local_15c;
              uVar20 = local_154;
              iVar33 = local_164;
              uVar31 = local_194;
            }
            else if (iVar33 == 0x20) {
              *puVar11 = uVar31;
              puVar11 = local_15c;
              uVar20 = local_154;
              iVar33 = local_164;
              uVar31 = local_194;
            }
            puVar11 = (uint *)((int)puVar11 + local_168);
            local_15c = puVar11;
          }
          else {
            uVar32 = local_150 >> 0x10 ^ (uint)local_160;
            local_158 = ~(local_16c << (uVar32 & 0x1f)) & local_158 | uVar31 << (uVar32 & 0x1f);
            local_150 = local_174 + local_150;
            bVar5 = bVar9;
            if ((local_150 & 0xff00) == 0) {
              *puVar11 = local_158;
              puVar11 = (uint *)((int)local_15c + local_168);
              local_150 = local_180;
              uVar20 = local_154;
              iVar33 = local_164;
              uVar31 = local_194;
              local_15c = puVar11;
              if (local_1f0 != local_1dc + -1) {
                local_158 = *puVar11;
              }
            }
          }
        }
        else {
          if (local_8c != (uint *)0x0) {
            iVar43 = local_7c + -1;
            if (local_7c == 0) {
              local_8c = local_60;
              local_80 = local_b0;
              local_88 = *local_60;
              local_7c = local_78 + -1;
            }
            else {
              local_7c = iVar43;
              if ((local_80 & 0xff00) == 0) {
                local_8c = (uint *)(local_98 + (int)local_8c);
                local_80 = local_b0;
                local_88 = *local_8c;
              }
            }
            local_84 = local_88 >> ((local_80 >> 0x10 ^ (uint)local_90) & 0x1f);
            local_80 = local_a8 + local_80;
          }
          if (local_dc != (byte *)0x0) {
            if (((uint)local_d0 & 0xff00) == 0) {
              local_dc = local_dc + local_e8;
              local_d0 = local_100;
              local_d8 = *(byte **)local_dc;
            }
            local_228 = bVar16;
            if ((1 << (((uint)local_d0 >> 0x10 ^ (uint)local_e0) & 0x1f) & (uint)local_d8) != 0) {
              local_228 = bVar19;
            }
            local_d0 = local_d0 + local_f8;
          }
          if (local_11c != 0) {
            if (local_14c == 0) {
              if ((int)uVar25 < 0) {
                do {
                  if (local_1b0 == 0) {
                    if (((uint)local_190 & 0xff00) == 0) {
                      local_19c = local_19c + local_1a8;
                      local_190 = local_1c0;
                      if (local_1f0 != local_1dc + -1) {
                        local_198 = *(byte **)local_19c;
                      }
                    }
                    local_190 = local_190 + local_1b8;
                  }
                  else {
                    local_19c = local_19c + local_1a8;
                  }
                  if (*(int *)(param_2 + 0xc) != 0) {
                    if (((uint)local_d0 & 0xff00) == 0) {
                      local_dc = local_dc + local_e8;
                      local_d0 = local_100;
                      local_d8 = *(byte **)local_dc;
                    }
                    local_d0 = local_d0 + local_f8;
                  }
                  uVar25 = uVar25 + local_1e8;
                  pbVar44 = local_118;
                } while ((int)uVar25 < 0);
              }
              uVar25 = uVar25 + local_1d0;
            }
            else if ((int)uVar25 < 0) {
              uVar25 = uVar25 + local_1e8;
              local_19c = local_128;
              local_198 = local_120;
              local_190 = local_124;
              local_dc = pbVar38;
              local_d8 = pbVar40;
              local_d0 = pbVar42;
            }
            else {
              uVar25 = uVar25 + local_1d0;
              local_138 = local_dc;
              local_130 = local_d8;
              local_1ec = local_d0;
              local_128 = local_19c;
              local_120 = local_198;
              local_124 = local_190;
              pbVar38 = local_dc;
              pbVar40 = local_d8;
              pbVar42 = local_d0;
            }
          }
          if (local_c4 != 0) {
            if (bVar5) {
              if (iVar33 == 8) {
                local_154 = CONCAT31(local_154._1_3_,(byte)*puVar11);
                uVar20 = local_154;
              }
              else if (iVar33 == 0x10) {
                local_154 = CONCAT22(local_154._2_2_,(short)*puVar11);
                uVar20 = local_154;
              }
              else if (iVar33 == 0x18) {
                local_154 = ((uint)*(byte *)((int)puVar11 + 2) * 0x100 +
                            (uint)*(byte *)((int)puVar11 + 1)) * 0x100 + (uint)(byte)*puVar11;
                uVar20 = local_154;
              }
              else if (iVar33 == 0x20) {
                local_154 = *puVar11;
                uVar20 = local_154;
              }
            }
            else {
              local_154 = local_158 >> ((local_150 >> 0x10 ^ (uint)local_160) & 0x1f);
              uVar20 = local_154;
            }
          }
          uVar22 = (uint)local_228;
          uVar32 = uVar31;
          if (uVar22 < 0xad) {
            if (uVar22 == 0xac) {
              uVar32 = (uVar20 ^ uVar31) & local_84 ^ uVar31;
            }
            else if (uVar22 < 0x56) {
              if (uVar22 == 0x55) {
                uVar32 = ~uVar20;
              }
              else if (uVar22 == 0) {
                uVar32 = 0;
              }
              else if (uVar22 == 0x11) {
                uVar32 = ~(uVar20 | uVar31);
              }
              else if (uVar22 == 0x22) {
                uVar32 = ~uVar31 & uVar20;
              }
              else {
                if (uVar22 != 0x33) {
                  if (uVar22 == 0x44) {
                    uVar12 = ~uVar20;
                    goto LAB_c08965c8;
                  }
                  goto LAB_c089672c;
                }
                uVar32 = ~uVar31;
              }
            }
            else if (uVar22 == 0x5a) {
              uVar32 = uVar20 ^ local_84;
            }
            else if (uVar22 == 0x66) {
              uVar32 = uVar20 ^ uVar31;
            }
            else if (uVar22 == 0x88) {
              uVar32 = uVar20 & uVar31;
            }
            else if (uVar22 != 0xaa) goto LAB_c089672c;
          }
          else if (uVar22 < 0xe3) {
            if (uVar22 == 0xe2) {
              uVar32 = ~uVar31 & uVar20 | local_84 & uVar31;
            }
            else if (uVar22 == 0xb8) {
              uVar32 = ~uVar31 & local_84 | uVar20 & uVar31;
            }
            else if (uVar22 == 0xbb) {
              uVar32 = ~uVar31 | uVar20;
            }
            else {
              uVar12 = local_84;
              if (uVar22 == 0xc0) {
LAB_c08965c8:
                uVar32 = uVar12 & uVar31;
              }
              else if (uVar22 != 0xcc) goto LAB_c089672c;
            }
          }
          else if (uVar22 == 0xee) {
            uVar32 = uVar20 | uVar31;
          }
          else {
            uVar32 = local_84;
            if (uVar22 != 0xf0) {
              if (uVar22 == 0xfb) {
                uVar32 = ~uVar31 | uVar20 | local_84;
              }
              else if (uVar22 == 0xff) {
                uVar32 = 0xffffffff;
              }
              else {
LAB_c089672c:
                uVar32 = FUN_c08a548c(uVar20,uVar31,local_84,uVar22,(byte)iVar33);
                puVar11 = local_15c;
                uVar20 = local_154;
                iVar33 = local_164;
              }
            }
          }
          if (local_110 != 0) {
            uVar31 = (uint)*(byte *)(param_2 + 0x4e);
            uVar22 = 0;
            puVar17 = (uint *)0x0;
            if (local_12c != 0) {
              puVar17 = *(uint **)(*(int *)(param_2 + 4) + 0xc);
              uVar22 = *(uint *)(*(int *)(param_2 + 4) + 0x10);
              uVar32 = puVar17[uVar32];
              uVar20 = puVar17[uVar20 & local_16c];
              local_154 = uVar20;
            }
            uVar14 = (uVar32 & local_214) >> (local_200 & 0x1f);
            uVar46 = (uVar32 & local_204) >> (local_1fc & 0x1f);
            uVar45 = (uVar32 & local_21c) >> (local_1e0 & 0x1f);
            uVar12 = (uVar32 & local_208) >> (local_1f4 & 0x1f);
            uVar34 = (uVar20 & local_204) >> (local_1fc & 0x1f);
            uVar36 = (uVar20 & local_214) >> (local_200 & 0x1f);
            uVar37 = (uVar20 & local_208) >> (local_1f4 & 0x1f);
            uVar15 = (uVar20 & local_21c) >> (local_1e0 & 0x1f);
            if (*(char *)(param_2 + 0x4f) == '\0') {
LAB_c08968cc:
              iVar43 = 1;
LAB_c08968d0:
              if ((*(byte *)(param_2 + 0x4d) & 0x20) != 0) {
                uVar24 = local_21c >> (local_1e0 & 0x1f);
                uVar45 = (uVar24 & 0xff) - uVar45;
                uVar31 = uVar24 - uVar31 & 0xff;
              }
              if ((*(byte *)(param_2 + 0x4d) & 0x40) != 0) {
                uVar15 = (local_21c >> (local_1e0 & 0x1f) & 0xff) - uVar15;
              }
              if (iVar43 == 3) {
                uVar14 = (uVar45 << 0x10 | uVar14) * uVar31 + 0x800080;
                uVar31 = (uVar46 << 0x10 | uVar12) * uVar31 + 0x800080;
                uVar32 = (uVar14 >> 8 & 0xff00ff) + uVar14;
                uVar14 = ((uVar31 >> 8 & 0xff00ff) + uVar31 >> 8 ^
                         (uVar14 >> 8 & 0xffff00ff) + uVar14) & 0xff00ff ^ uVar32;
                uVar31 = 0xff - (uVar32 >> 0x18) & 0xff;
                uVar32 = (uVar15 << 0x10 | uVar36) * uVar31 + 0x800080;
                uVar31 = (uVar34 << 0x10 | uVar37) * uVar31 + 0x800080;
                uVar12 = ((uVar32 >> 8 & 0xff00ff) + uVar32 >> 8 & 0xff00ff) +
                         (uVar14 >> 8 & 0xff00ff);
                uVar32 = ((uVar31 >> 8 & 0xff00ff) + uVar31 >> 8 & 0xff00ff) + (uVar14 & 0xff00ff);
                uVar31 = (local_21c >> (local_1e0 & 0x1f)) << 0x10;
                if (uVar31 < (uVar12 & 0xffff0000)) {
                  uVar12 = uVar12 & 0xffff | uVar31;
                }
                uVar31 = local_214 >> (local_200 & 0x1f);
                if (uVar31 < (uVar12 & 0xffff)) {
                  uVar12 = uVar12 & 0xff0000 | uVar31;
                }
                uVar31 = (local_204 >> (local_1fc & 0x1f)) << 0x10;
                if (uVar31 < (uVar32 & 0xffff0000)) {
                  uVar32 = uVar32 & 0xffff | uVar31;
                }
                uVar31 = local_208 >> (local_1f4 & 0x1f);
                if (uVar31 < (uVar32 & 0xffff)) {
                  uVar32 = uVar32 & 0xff0000 | uVar31;
                }
                uVar32 = uVar12 << 8 | uVar32;
              }
              else if (iVar43 == 2) {
                uVar31 = (uVar15 << 0x10 | uVar36) * (0xff - uVar45) + 0x800080;
                uVar32 = (uVar34 << 0x10 | uVar37) * (0xff - uVar45) + 0x800080;
                uVar31 = ((uVar31 >> 8 & 0xff00ff) + uVar31 >> 8 & 0xff00ff) +
                         (uVar45 << 0x10 | uVar14);
                uVar32 = ((uVar32 >> 8 & 0xff00ff) + uVar32 >> 8 & 0xff00ff) +
                         (uVar46 << 0x10 | uVar12);
                uVar12 = (local_21c >> (local_1e0 & 0x1f)) << 0x10;
                if (uVar12 < (uVar31 & 0xffff0000)) {
                  uVar31 = uVar31 & 0xffff | uVar12;
                }
                uVar12 = local_214 >> (local_200 & 0x1f);
                if (uVar12 < (uVar31 & 0xffff)) {
                  uVar31 = uVar31 & 0xff0000 | uVar12;
                }
                uVar12 = (local_204 >> (local_1fc & 0x1f)) << 0x10;
                if (uVar12 < (uVar32 & 0xffff0000)) {
                  uVar32 = uVar32 & 0xffff | uVar12;
                }
                uVar12 = local_208 >> (local_1f4 & 0x1f);
                if (uVar12 < (uVar32 & 0xffff)) {
                  uVar32 = uVar32 & 0xff0000 | uVar12;
                }
                uVar32 = uVar31 << 8 | uVar32;
              }
              else if (iVar43 == 1) {
                uVar37 = uVar34 << 0x10 | uVar37;
                uVar36 = uVar15 << 0x10 | uVar36;
                uVar32 = ((uVar46 << 0x10 | uVar12) - uVar37) * uVar31 + uVar37 * 0xff + 0x800080;
                uVar31 = ((uVar45 << 0x10 | uVar14) - uVar36) * uVar31 + uVar36 * 0xff + 0x800080;
                uVar32 = ((uVar32 >> 8 & 0xff00ff) + uVar32 >> 8 ^
                         (uVar31 >> 8 & 0xffff00ff) + uVar31) & 0xff00ff ^
                         (uVar31 >> 8 & 0xff00ff) + uVar31;
              }
            }
            else {
              uVar45 = ((uint)pbVar44 & local_114) >> (local_140 & 0x1f);
              if (uVar45 == 0) {
                uVar32 = ((uVar15 << 8 | uVar34) << 8 | uVar36) << 8 | uVar37;
              }
              else {
                if (uVar45 != 0xff) {
                  if (uVar31 == 0xff) {
                    iVar43 = 2;
                  }
                  else {
                    iVar43 = 3;
                  }
                  goto LAB_c08968d0;
                }
                if (uVar31 != 0xff) goto LAB_c08968cc;
                uVar32 = ((uVar46 | 0xff00) << 8 | uVar14) << 8 | uVar12;
              }
            }
            uVar32 = (uVar32 >> 8 & 0xff) << (local_200 & 0x1f) & local_214 |
                     (uVar32 >> 0x10 & 0xff) << (local_1fc & 0x1f) & local_204 |
                     (uVar32 & 0xff) << (local_1f4 & 0x1f) & local_208 |
                     (uVar32 >> 0x18) << (local_1e0 & 0x1f) & local_21c;
            pbVar38 = local_138;
            pbVar40 = local_130;
            pbVar42 = local_1ec;
            if (local_12c != 0) {
              local_194 = uVar32;
              uVar31 = FUN_c08a5590(uVar32,*puVar17);
              uVar12 = 1;
              uVar32 = 0;
              puVar11 = local_15c;
              uVar20 = local_154;
              iVar33 = local_164;
              pbVar38 = local_138;
              pbVar40 = local_130;
              if (1 < uVar22) {
                do {
                  puVar17 = puVar17 + 1;
                  uVar20 = FUN_c08a5590(local_194,*puVar17);
                  if (uVar20 < uVar31) {
                    uVar32 = uVar12;
                    uVar31 = uVar20;
                  }
                  uVar12 = uVar12 + 1;
                  puVar11 = local_15c;
                  uVar20 = local_154;
                  iVar33 = local_164;
                  pbVar38 = local_138;
                  pbVar40 = local_130;
                } while (uVar12 < uVar22);
              }
            }
          }
          uVar31 = uVar32 & local_16c;
          local_194 = uVar31;
          if ((local_228 != 0xaa) && ((bVar5 = bVar9, local_cc == 0 || (pbVar44 != pbVar18))))
          goto LAB_c0896e60;
          if (bVar9) {
            puVar11 = (uint *)((int)puVar11 + local_168);
            local_15c = puVar11;
            bVar5 = bVar9;
          }
          else {
            local_150 = local_178 + local_150;
            bVar5 = bVar9;
            if ((local_150 & 0xff00) == 0) {
              if ((local_150 & 0xff) != 0) {
                *puVar11 = local_158;
                puVar11 = local_15c;
                uVar20 = local_154;
                iVar33 = local_164;
              }
              puVar11 = (uint *)((int)puVar11 + local_168);
              local_150 = local_180;
              local_158 = *puVar11;
              local_15c = puVar11;
            }
          }
        }
        local_1f0 = local_1f0 + 1;
        pbVar28 = local_1c4;
      } while (local_1f0 < local_1dc);
    }
    pbVar44 = local_118;
    puVar17 = local_b8;
    if ((local_150 & 0xff) != 0) {
      *puVar11 = local_158;
      uVar31 = local_194;
      pbVar28 = local_1c4;
      iVar33 = local_164;
      uVar20 = local_154;
    }
  } while( true );
}



/* c0897028 FUN_c0897028 */

/* Boundary evidence: original MIPS .pdata c0897028..c0897903. Semantic name remains unreviewed. */

undefined4 FUN_c0897028(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint *puVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  uint local_164;
  int local_160;
  int local_158;
  uint local_150;
  int local_144;
  int local_13c;
  uint *local_130;
  int local_12c;
  uint local_128;
  uint local_124;
  int local_120;
  int local_118;
  uint local_114;
  int local_110;
  byte local_108;
  uint *local_104;
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint *local_f0;
  int local_ec;
  uint local_e8;
  uint local_e4;
  int local_e0;
  int local_d8;
  uint local_d4;
  int local_d0;
  byte local_c8;
  uint *local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint *local_b4;
  int local_b0;
  uint local_ac;
  int local_a8;
  uint local_a4;
  int local_a0;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  uint auStack_88 [4];
  uint auStack_78 [17];
  uint local_34;
  
  piVar15 = *(int **)(param_2 + 0x14);
  uVar18 = *(uint *)(param_2 + 0x28);
  local_160 = piVar15[2] - *piVar15;
  local_158 = piVar15[3] - piVar15[1];
  local_a4 = (uint)(((uVar18 >> 1 ^ uVar18) & 0x5555) != 0);
  piVar15 = *(int **)(param_2 + 0x18);
  iVar20 = 0;
  iVar11 = piVar15[2];
  iVar9 = *piVar15;
  iVar14 = piVar15[3];
  iVar12 = piVar15[1];
  iVar16 = (iVar11 - iVar9) * 0x10000;
  iVar25 = iVar16 / local_160;
  iVar19 = 0;
  iVar21 = 0;
  iVar22 = 0;
  if (local_160 == 0) {
    trap(0x1c00);
  }
  if ((local_160 == -1) && (iVar16 == -0x80000000)) {
    trap(0x1800);
  }
  iVar16 = (iVar14 - iVar12) * 0x10000;
  iVar26 = iVar16 / local_158;
  if (local_158 == 0) {
    trap(0x1c00);
  }
  if ((local_158 == -1) && (iVar16 == -0x80000000)) {
    trap(0x1800);
  }
  local_150 = iVar26 - 0x10000U >> 1;
  uVar17 = iVar25 - 0x10000U >> 1;
  FUN_c08a55f0(*(int *)(param_2 + 4),(int)auStack_78,(int *)auStack_88);
  iVar16 = iVar20;
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar20 = FUN_c08a5678(&local_98,*(int **)(param_2 + 0x1c),*(int **)(param_2 + 0x14));
    if (iVar20 != 0) {
      return 0;
    }
    piVar15 = *(int **)(param_2 + 0x14);
    if (*(int *)(param_2 + 0x34) == 0) {
      iVar20 = piVar15[2] - local_90;
    }
    else {
      iVar20 = local_98 - *piVar15;
    }
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar19 = piVar15[3] - local_8c;
    }
    else {
      iVar19 = local_94 - piVar15[1];
    }
    local_160 = local_90 - local_98;
    local_158 = local_8c - local_94;
    iVar16 = iVar20;
  }
  for (; iVar24 = iVar19, iVar20 != 0; iVar20 = iVar20 + -1) {
    uVar17 = (uVar17 & 0xffff) + iVar25;
    iVar21 = (uVar17 >> 0x10) + iVar21;
  }
  for (; local_150 = local_150 & 0xffff, iVar24 != 0; iVar24 = iVar24 + -1) {
    local_150 = local_150 + iVar26;
    iVar22 = (local_150 >> 0x10) + iVar22;
  }
  iVar20 = *(int *)(param_2 + 4);
  iVar24 = *(int *)(&LAB_c0891154 + *(int *)(iVar20 + 0x1c) * 4);
  piVar15 = *(int **)(param_2 + 0x14);
  if (*(int *)(param_2 + 0x38) == 0) {
    iVar20 = *(int *)(*(int *)(param_2 + 4) + 8);
    local_13c = -iVar20;
    iVar20 = ((piVar15[3] - iVar19) + -1) * iVar20 + *(int *)(*(int *)(param_2 + 4) + 4);
  }
  else {
    local_13c = *(int *)(iVar20 + 8);
    iVar20 = (piVar15[1] + iVar19) * local_13c + *(int *)(iVar20 + 4);
  }
  local_144 = iVar24 >> 3;
  if (*(int *)(param_2 + 0x34) == 0) {
    if (iVar24 < 0) {
      local_144 = iVar24 + 7 >> 3;
    }
    local_144 = -local_144;
    iVar16 = -(((piVar15[2] - iVar16) + -1) * local_144);
  }
  else {
    if (iVar24 < 0) {
      local_144 = iVar24 + 7 >> 3;
    }
    iVar16 = (*piVar15 + iVar16) * local_144;
  }
  local_ac = (2 << (iVar24 - 1U & 0x1f)) - 1;
  FUN_c08a5b70((int *)&local_130,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
               *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar21,iVar22 + -1);
  FUN_c08a5b70((int *)&local_f0,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
               *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar21,iVar22);
  iVar22 = (iVar14 - iVar12) - iVar22;
  local_a8 = (iVar11 - iVar9) - iVar21;
  uVar13 = 1;
  local_a0 = 0;
  if (0 < local_158) {
    local_164 = local_34;
    uVar7 = local_f8;
    iVar21 = local_12c;
    puVar23 = (uint *)(iVar16 + iVar20);
    iVar20 = local_ec;
    local_b0 = iVar22;
    do {
      uVar8 = local_150 >> 8;
      local_b4 = (uint *)((int)puVar23 + local_13c);
      local_104 = local_130;
      local_c4 = local_f0;
      if (uVar13 == 0) {
        local_a0 = local_a0 + -1;
        local_104 = (uint *)((int)local_130 - iVar21);
        local_c4 = (uint *)((int)local_f0 - iVar20);
      }
      local_130 = (uint *)((int)local_104 + iVar21);
      local_f0 = (uint *)((int)local_c4 + iVar20);
      bVar3 = local_a0 != 0;
      bVar4 = local_a0 < iVar22;
      local_a0 = local_a0 + 1;
      if ((local_118 == 0) && (bVar3)) {
        local_100 = *local_104;
        local_f8 = local_124;
        uVar7 = local_124;
      }
      if ((local_d8 == 0) && (bVar4)) {
        local_c0 = *local_c4;
        local_b8 = local_e4;
      }
      iVar9 = 0;
      iVar11 = 0;
      uVar13 = uVar17 & 0xffff;
      if (0 < local_160) {
        do {
          uVar6 = local_bc;
          uVar5 = local_fc;
          if (iVar11 < local_a8) {
            iVar11 = iVar11 + 1;
            if (bVar3) {
              if (local_118 == 0) {
                if ((uVar7 & 0xff00) == 0) {
                  local_104 = (uint *)(local_110 + (int)local_104);
                  local_100 = *local_104;
                  uVar7 = local_128;
                }
                local_fc = local_100 >> ((uVar7 >> 0x10 ^ (uint)local_108) & 0x1f);
                local_f8 = local_120 + uVar7;
              }
              else {
                pbVar1 = (byte *)((int)local_104 + 2);
                pbVar2 = (byte *)((int)local_104 + 1);
                uVar7 = *local_104;
                local_104 = (uint *)(local_110 + (int)local_104);
                local_fc = ((uint)*pbVar1 * 0x100 + (uint)*pbVar2) * 0x100 + (uint)(byte)uVar7;
              }
              local_fc = local_114 & local_fc;
              if (*(int *)(param_2 + 0x3c) != 0) {
                local_fc = *(uint *)(local_fc * 4 + *(int *)(param_2 + 0x3c));
              }
              if (*(code **)(param_2 + 0x40) != (code *)0x0) {
                local_fc = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),local_fc);
              }
            }
            local_bc = local_fc;
            if (bVar4) {
              if (local_d8 == 0) {
                if ((local_b8 & 0xff00) == 0) {
                  local_c4 = (uint *)(local_d0 + (int)local_c4);
                  local_b8 = local_e8;
                  local_c0 = *local_c4;
                }
                uVar7 = local_b8 >> 0x10;
                local_b8 = local_e0 + local_b8;
                local_bc = local_c0 >> ((uVar7 ^ local_c8) & 0x1f);
              }
              else {
                pbVar1 = (byte *)((int)local_c4 + 2);
                pbVar2 = (byte *)((int)local_c4 + 1);
                uVar7 = *local_c4;
                local_c4 = (uint *)(local_d0 + (int)local_c4);
                local_bc = ((uint)*pbVar1 * 0x100 + (uint)*pbVar2) * 0x100 + (uint)(byte)uVar7;
              }
              local_bc = local_d4 & local_bc;
              if (*(int *)(param_2 + 0x3c) != 0) {
                local_bc = *(uint *)(local_bc * 4 + *(int *)(param_2 + 0x3c));
              }
              if (*(code **)(param_2 + 0x40) != (code *)0x0) {
                local_bc = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),local_bc);
              }
            }
            if (!bVar3) {
              local_fc = local_bc;
            }
          }
          if (iVar11 == 1) {
            uVar6 = local_bc;
            uVar5 = local_fc;
          }
          if (uVar5 != uVar6) {
            uVar5 = FUN_c08a5708(uVar5,uVar6,0x100 - uVar8,uVar8,auStack_78,auStack_88);
          }
          uVar6 = local_fc;
          if (local_fc != local_bc) {
            uVar6 = FUN_c08a5708(local_fc,local_bc,0x100 - uVar8,uVar8,auStack_78,auStack_88);
          }
          do {
            iVar22 = local_b0;
            uVar7 = local_f8;
            iVar21 = local_12c;
            iVar20 = local_ec;
            if (local_160 <= iVar9) goto LAB_c089789c;
            iVar9 = iVar9 + 1;
            uVar7 = uVar5;
            if (uVar5 != uVar6) {
              uVar7 = FUN_c08a5708(uVar5,uVar6,0x100 - (uVar13 >> 8),uVar13 >> 8,auStack_78,
                                   auStack_88);
            }
            uVar10 = uVar13 + iVar25;
            uVar13 = uVar10 & 0xffff;
            if (local_a4 != 0) {
              if (iVar24 == 0x10) {
                local_34 = CONCAT22(local_34._2_2_,(short)*puVar23);
                local_164 = local_34;
              }
              else if (iVar24 == 0x18) {
                local_164 = ((uint)*(byte *)((int)puVar23 + 2) * 0x100 +
                            (uint)*(byte *)((int)puVar23 + 1)) * 0x100 + (uint)(byte)*puVar23;
                local_34 = local_164;
              }
              else if (iVar24 == 0x20) {
                local_164 = *puVar23;
                local_34 = local_164;
              }
            }
            if ((char)uVar18 == -0x78) {
              uVar7 = local_164 & uVar7;
            }
            else if ((char)uVar18 == -0x12) {
              uVar7 = local_164 | uVar7;
            }
            uVar7 = uVar7 & local_ac;
            if (iVar24 == 0x10) {
              *(short *)puVar23 = (short)uVar7;
            }
            else if (iVar24 == 0x18) {
              *(byte *)puVar23 = (byte)uVar7;
              *(byte *)((int)puVar23 + 1) = (byte)(uVar7 >> 8);
              *(byte *)((int)puVar23 + 2) = (byte)(uVar7 >> 0x10);
            }
            else if (iVar24 == 0x20) {
              *puVar23 = uVar7;
            }
            puVar23 = (uint *)((int)puVar23 + local_144);
          } while ((uVar10 & 0xffff0000) == 0);
          iVar22 = local_b0;
          uVar7 = local_f8;
          iVar21 = local_12c;
          iVar20 = local_ec;
        } while (iVar9 < local_160);
      }
LAB_c089789c:
      uVar13 = local_150 + iVar26 & 0xffff0000;
      local_150 = local_150 + iVar26 & 0xffff;
      local_158 = local_158 + -1;
      puVar23 = local_b4;
    } while (local_158 != 0);
  }
  return 0;
}



/* c0897904 FUN_c0897904 */

/* Boundary evidence: original MIPS .pdata c0897904..c089820f. Semantic name remains unreviewed. */

undefined4 FUN_c0897904(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  void *_Dst;
  int iVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint *local_100;
  uint *local_f8;
  int local_f4;
  uint local_f0;
  uint local_ec;
  int local_e8;
  int local_e0;
  int local_d8;
  byte local_d0;
  uint *local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  int local_b8;
  uint local_b4;
  int local_b0;
  void *local_ac;
  uint local_a8;
  int local_a4;
  int local_a0;
  uint local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  uint local_88;
  uint local_84;
  uint *local_80;
  uint *local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint *local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint auStack_58 [4];
  uint auStack_48 [4];
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  piVar4 = *(int **)(param_2 + 0x14);
  iVar7 = 0;
  piVar6 = *(int **)(param_2 + 0x18);
  iVar12 = piVar4[2] - *piVar4;
  iVar11 = piVar4[3] - piVar4[1];
  iVar5 = (piVar6[2] - *piVar6) * 0x10000;
  uVar15 = iVar5 / iVar12;
  iVar8 = 0;
  if (iVar12 == 0) {
    trap(0x1c00);
  }
  if ((iVar12 == -1) && (iVar5 == -0x80000000)) {
    trap(0x1800);
  }
  iVar5 = (piVar6[3] - piVar6[1]) * 0x10000;
  uVar16 = iVar5 / iVar11;
  if (iVar11 == 0) {
    trap(0x1c00);
  }
  if ((iVar11 == -1) && (iVar5 == -0x80000000)) {
    trap(0x1800);
  }
  local_b0 = iVar11;
  local_a4 = iVar12;
  local_88 = uVar15;
  local_74 = uVar16;
  FUN_c08a55f0(*(int *)(param_2 + 4),(int)auStack_48,(int *)auStack_58);
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar12 = FUN_c08a5678(&local_38,*(int **)(param_2 + 0x1c),*(int **)(param_2 + 0x14));
    if (iVar12 != 0) {
      return 0;
    }
    piVar4 = *(int **)(param_2 + 0x14);
    if (*(int *)(param_2 + 0x34) == 0) {
      iVar7 = piVar4[2] - local_30;
    }
    else {
      iVar7 = local_38 - *piVar4;
    }
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar8 = piVar4[3] - local_2c;
    }
    else {
      iVar8 = local_34 - piVar4[1];
    }
    iVar12 = local_30 - local_38;
    iVar11 = local_2c - local_34;
    local_b0 = iVar11;
    local_a4 = iVar12;
  }
  uVar3 = 0;
  if (iVar7 != 0) {
    uVar3 = uVar15 * iVar7;
  }
  local_78 = uVar3 & 0xffff;
  uVar15 = 0;
  if (iVar8 != 0) {
    uVar15 = uVar16 * iVar8;
  }
  local_a8 = uVar15 & 0xffff;
  iVar5 = *(int *)(param_2 + 4);
  iVar10 = *(int *)(&LAB_c0891154 + *(int *)(iVar5 + 0x1c) * 4);
  piVar4 = *(int **)(param_2 + 0x14);
  if (*(int *)(param_2 + 0x38) == 0) {
    iVar5 = *(int *)(*(int *)(param_2 + 4) + 8);
    local_98 = -iVar5;
    iVar5 = ((piVar4[3] - iVar8) + -1) * iVar5 + *(int *)(*(int *)(param_2 + 4) + 4);
  }
  else {
    local_98 = *(int *)(iVar5 + 8);
    iVar5 = (piVar4[1] + iVar8) * local_98 + *(int *)(iVar5 + 4);
  }
  iVar8 = iVar10 >> 3;
  if (*(int *)(param_2 + 0x34) == 0) {
    local_94 = iVar8;
    if (iVar10 < 0) {
      local_94 = iVar10 + 7 >> 3;
    }
    local_94 = -local_94;
    iVar7 = -(((piVar4[2] - iVar7) + -1) * local_94);
  }
  else {
    local_94 = iVar8;
    if (iVar10 < 0) {
      local_94 = iVar10 + 7 >> 3;
    }
    iVar7 = (iVar7 + *piVar4) * local_94;
  }
  pvVar9 = (void *)(iVar7 + iVar5);
  local_b4 = (2 << (iVar10 - 1U & 0x1f)) - 1;
  local_ac = pvVar9;
  FUN_c08a5b70((int *)&local_f8,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
               *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),uVar3 >> 0x10,uVar15 >> 0x10);
  local_cc = local_f8;
  if (iVar10 < 0) {
    iVar8 = iVar10 + 7 >> 3;
  }
  uVar15 = iVar8 * iVar12;
  local_68 = uVar15;
  local_100 = operator_new(uVar15);
  if (local_100 != (uint *)0x0) {
    uVar3 = 0;
    local_cc = local_f8;
    local_6c = local_100;
    if (0 < iVar11) {
      uVar16 = uVar16 >> 0x10;
      local_70 = uVar16;
      do {
        memset(local_100,0,uVar15);
        if (0 < (int)uVar3) {
          iVar5 = (uVar3 - 1 >> 0x10) + 1;
          do {
            local_f8 = (uint *)(local_f4 + (int)local_f8);
            iVar5 = iVar5 + -1;
            local_cc = local_f8;
          } while (iVar5 != 0);
        }
        if (local_e0 == 0) {
          local_c8 = *local_cc;
          local_c0 = local_ec;
        }
        local_a0 = 0;
        uVar3 = local_c0;
        _Dst = pvVar9;
        local_80 = local_f8;
        local_7c = local_cc;
        if (0 < (int)uVar16) {
          do {
            iVar5 = local_a0;
            iVar7 = 0x100;
            local_90 = 0x100;
            local_b8 = 0;
            if (0 < local_a0) {
              iVar7 = 0x80;
              local_90 = 0x80;
              local_b8 = 0x80;
            }
            uVar15 = 0;
            local_9c = local_78;
            if (local_e0 == 0) {
              uVar2 = uVar3;
              if ((uVar3 & 0xff00) == 0) {
                local_c8 = *local_cc;
                uVar2 = local_f0;
              }
              uVar3 = local_e8 + uVar2;
              uVar2 = local_c8 >> ((uVar2 >> 0x10 ^ (uint)local_d0) & 0x1f);
              local_c0 = uVar3;
            }
            else {
              uVar2 = ((uint)*(byte *)((int)local_cc + 2) * 0x100 +
                      (uint)*(byte *)((int)local_cc + 1)) * 0x100 + (uint)(byte)*local_cc;
            }
            if (*(int *)(param_2 + 0x3c) != 0) {
              uVar2 = *(uint *)(uVar2 * 4 + *(int *)(param_2 + 0x3c));
            }
            if (*(code **)(param_2 + 0x40) != (code *)0x0) {
              local_c4 = uVar2;
              uVar2 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),uVar2);
              uVar3 = local_c0;
            }
            uVar2 = uVar2 & local_b4;
            local_c4 = uVar2;
            if (0 < iVar12) {
              uVar16 = local_88 >> 0x10;
              local_8c = iVar12;
              local_84 = uVar16;
              do {
                puVar13 = local_cc;
                local_c4 = uVar2;
                if (0 < (int)uVar15) {
                  iVar12 = (uVar15 - 1 >> 0x10) + 1;
                  do {
                    if (local_e0 == 0) {
                      uVar15 = uVar3;
                      if ((uVar3 & 0xff00) == 0) {
                        puVar13 = (uint *)(local_d8 + (int)puVar13);
                        local_c8 = *puVar13;
                        uVar15 = local_f0;
                        local_cc = puVar13;
                      }
                      uVar3 = local_e8 + uVar15;
                      uVar15 = local_c8 >> ((uVar15 >> 0x10 ^ (uint)local_d0) & 0x1f);
                      local_c0 = uVar3;
                    }
                    else {
                      puVar13 = (uint *)(local_d8 + (int)puVar13);
                      uVar15 = ((uint)*(byte *)((int)puVar13 + 2) * 0x100 +
                               (uint)*(byte *)((int)puVar13 + 1)) * 0x100 + (uint)(byte)*puVar13;
                      local_cc = puVar13;
                    }
                    if (*(int *)(param_2 + 0x3c) != 0) {
                      uVar15 = *(uint *)(uVar15 * 4 + *(int *)(param_2 + 0x3c));
                    }
                    if (*(code **)(param_2 + 0x40) != (code *)0x0) {
                      local_c4 = uVar15;
                      uVar15 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),uVar15)
                      ;
                      uVar3 = local_c0;
                      puVar13 = local_cc;
                    }
                    local_c4 = uVar15 & local_b4;
                    iVar12 = iVar12 + -1;
                  } while (iVar12 != 0);
                }
                uVar15 = local_b4;
                uVar2 = local_c4;
                local_64 = local_c8;
                local_bc = local_c4;
                local_60 = uVar3;
                if (1 < (int)uVar16) {
                  iVar12 = uVar16 - 1;
                  puVar14 = puVar13;
                  do {
                    if (local_e0 == 0) {
                      uVar16 = uVar3;
                      if ((uVar3 & 0xff00) == 0) {
                        puVar14 = (uint *)(local_d8 + (int)puVar14);
                        local_c8 = *puVar14;
                        uVar16 = local_f0;
                        local_cc = puVar14;
                      }
                      uVar3 = local_e8 + uVar16;
                      uVar16 = local_c8 >> ((uVar16 >> 0x10 ^ (uint)local_d0) & 0x1f);
                      local_c0 = uVar3;
                    }
                    else {
                      puVar14 = (uint *)(local_d8 + (int)puVar14);
                      uVar16 = ((uint)*(byte *)((int)puVar14 + 2) * 0x100 +
                               (uint)*(byte *)((int)puVar14 + 1)) * 0x100 + (uint)(byte)*puVar14;
                      local_cc = puVar14;
                    }
                    if (*(int *)(param_2 + 0x3c) != 0) {
                      uVar16 = *(uint *)(uVar16 * 4 + *(int *)(param_2 + 0x3c));
                    }
                    if (*(code **)(param_2 + 0x40) != (code *)0x0) {
                      local_c4 = uVar16;
                      uVar16 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),uVar16)
                      ;
                      uVar3 = local_c0;
                      puVar14 = local_cc;
                    }
                    local_c4 = uVar16 & uVar15;
                    if (iVar10 == 0x10) {
                      FUN_c08a5a90((ushort *)&local_bc,local_c4,0x80,0x80,auStack_48,auStack_58);
                      uVar3 = local_c0;
                      puVar14 = local_cc;
                    }
                    else if (iVar10 == 0x18) {
                      FUN_c08a5ad0((byte *)&local_bc,local_c4,0x80,0x80,auStack_48,auStack_58);
                      uVar3 = local_c0;
                      puVar14 = local_cc;
                    }
                    else if (iVar10 == 0x20) {
                      FUN_c08a5b34(&local_bc,local_c4,0x80,0x80,auStack_48,auStack_58);
                      uVar3 = local_c0;
                      puVar14 = local_cc;
                    }
                    iVar12 = iVar12 + -1;
                    uVar16 = local_84;
                    iVar7 = local_90;
                  } while (iVar12 != 0);
                }
                uVar3 = local_60;
                uVar1 = local_64;
                if (iVar10 == 0x10) {
                  FUN_c08a5a90((ushort *)local_100,local_bc,local_b8,iVar7,auStack_48,auStack_58);
                }
                else if (iVar10 == 0x18) {
                  FUN_c08a5ad0((byte *)local_100,local_bc,local_b8,iVar7,auStack_48,auStack_58);
                }
                else if (iVar10 == 0x20) {
                  FUN_c08a5b34(local_100,local_bc,local_b8,iVar7,auStack_48,auStack_58);
                }
                local_100 = (uint *)((int)local_100 + local_94);
                uVar15 = local_9c + local_88 & 0xffff0000;
                local_9c = local_9c + local_88 & 0xffff;
                local_8c = local_8c + -1;
                local_cc = puVar13;
                local_c8 = uVar1;
                local_c0 = uVar3;
              } while (local_8c != 0);
              local_8c = 0;
              iVar5 = local_a0;
              local_100 = local_6c;
              iVar12 = local_a4;
              uVar16 = local_70;
              local_c4 = uVar2;
            }
            local_f8 = (uint *)(local_f4 + (int)local_f8);
            if (local_e0 == 0) {
              local_c8 = *local_f8;
              local_c0 = local_ec;
              uVar3 = local_ec;
            }
            local_a0 = iVar5 + 1;
            _Dst = local_ac;
            uVar15 = local_68;
            local_cc = local_f8;
          } while (local_a0 < (int)uVar16);
        }
        pvVar9 = (void *)((int)_Dst + local_98);
        local_ac = pvVar9;
        memcpy(_Dst,local_100,uVar15);
        local_cc = local_7c;
        local_f8 = local_80;
        uVar3 = local_a8 + local_74 & 0xffff0000;
        local_a8 = local_a8 + local_74 & 0xffff;
        local_b0 = local_b0 + -1;
      } while (local_b0 != 0);
    }
    operator_delete(local_100);
    return 0;
  }
  return 0x80004005;
}



/* c0898210 FUN_c0898210 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0898210..c089a207. Semantic name remains unreviewed. */

undefined4 FUN_c0898210(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  byte *pbVar11;
  byte *pbVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined1 *puVar15;
  undefined2 *puVar16;
  byte *pbVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  byte bVar22;
  uint *puVar23;
  byte bVar24;
  byte *pbVar25;
  int iVar26;
  uint uVar27;
  int *piVar28;
  uint uVar29;
  int iVar30;
  int *piVar31;
  byte *pbVar32;
  byte *pbVar33;
  uint uVar34;
  int iVar35;
  byte bVar36;
  uint uVar37;
  byte *pbVar38;
  int iVar39;
  byte *pbVar40;
  int iVar41;
  byte *pbVar42;
  int iVar43;
  int iVar44;
  int iVar45;
  uint uVar46;
  int iVar47;
  byte local_280;
  uint local_27c;
  uint local_278;
  byte *local_274;
  byte *local_270;
  int local_268;
  byte *local_264;
  byte *local_260;
  byte *local_25c;
  byte *local_258;
  uint local_254;
  uint local_250;
  byte *local_24c;
  byte *local_248;
  uint local_244;
  uint local_23c;
  byte *local_22c;
  byte *local_228;
  byte *local_224;
  int local_220;
  int local_21c;
  uint local_218;
  uint local_214;
  byte *local_210;
  byte *local_208;
  byte *local_204;
  byte *local_200;
  byte *local_1fc;
  int local_1f8;
  int local_1f0;
  byte *local_1ec;
  int local_1e8;
  int local_1e4;
  byte local_1e0;
  byte *local_1dc;
  byte *local_1d8;
  uint local_1d4;
  byte *local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1b4;
  byte *local_1b0;
  byte *local_1ac;
  byte *local_1a8;
  byte *local_1a4;
  byte *local_1a0;
  uint local_19c;
  byte *local_198;
  uint *local_190;
  int local_18c;
  uint local_188;
  uint local_184;
  int local_180;
  int local_17c;
  uint local_174;
  int local_170;
  int local_16c;
  byte local_168;
  uint *local_164;
  uint local_160;
  uint local_15c;
  uint local_158;
  int local_150;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  uint local_128;
  uint local_124;
  byte *local_120;
  int local_11c;
  byte *local_118;
  int local_114;
  byte *local_110;
  int local_10c;
  byte *local_108;
  uint local_104;
  byte *local_100;
  byte *local_fc;
  byte *local_f8;
  byte *local_f4;
  byte *local_f0;
  byte *local_ec;
  int local_e8;
  int local_d8;
  byte local_d0;
  byte *local_cc;
  byte *local_c8;
  byte *local_c0;
  int local_bc;
  byte *local_b8;
  uint local_b4;
  uint local_b0;
  uint *local_a8;
  int local_a4;
  uint local_a0;
  uint local_9c;
  int local_98;
  int local_88;
  byte local_80;
  uint *local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  uint *local_54;
  uint *local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  uVar29 = *(uint *)(param_2 + 0x28);
  piVar28 = *(int **)(param_2 + 0x14);
  bVar22 = (byte)(uVar29 >> 8);
  bVar24 = (byte)uVar29;
  local_214 = piVar28[2] - *piVar28;
  local_bc = 0;
  local_218 = piVar28[3] - piVar28[1];
  local_b0 = (uint)(((uVar29 >> 1 ^ uVar29) & 0x5555) != 0);
  local_264 = *(byte **)(param_2 + 0x34);
  cVar3 = *(char *)(param_2 + 0x4f);
  bVar9 = false;
  iVar47 = *(int *)(param_2 + 0x38);
  piVar28 = *(int **)(param_2 + 0x14);
  iVar43 = 0;
  iVar41 = 0;
  iVar39 = 0;
  iVar44 = 0;
  local_114 = 0;
  bVar8 = false;
  local_128 = 0;
  local_19c = 0;
  bVar10 = false;
  local_268 = 0;
  local_10c = 0;
  if ((cVar3 != '\0') && (cVar3 != '\x01')) {
    return 0x80004001;
  }
  local_11c = 0;
  if (*(int *)(param_2 + 0x4c) == 0xff0000) {
    local_210 = local_228;
    local_270 = local_228;
    local_274 = local_228;
    local_260 = local_228;
    local_258 = local_228;
    local_24c = local_228;
    local_248 = local_228;
    local_25c = local_228;
    local_104 = (uint)local_22c;
    local_124 = local_27c;
  }
  else {
    iVar30 = *(int *)(param_2 + 4);
    if (*(int *)(iVar30 + 0x10) == 3) {
      puVar23 = *(uint **)(iVar30 + 0xc);
      local_210 = (byte *)*puVar23;
      local_270 = (byte *)puVar23[1];
      local_274 = (byte *)puVar23[2];
      local_260 = (byte *)0x0;
      if ((*(int *)(&LAB_c0891154 + *(int *)(iVar30 + 0x1c) * 4) == 0x20) &&
         ((((uint)local_274 | (uint)local_270 | (uint)local_210) & 0xff000000) == 0)) {
        local_260 = (byte *)0xff000000;
      }
    }
    else if ((*(int *)(iVar30 + 0x10) == 4) &&
            (8 < *(int *)(&LAB_c0891154 + *(int *)(iVar30 + 0x1c) * 4))) {
      puVar23 = *(uint **)(iVar30 + 0xc);
      local_210 = (byte *)*puVar23;
      local_270 = (byte *)puVar23[1];
      local_274 = (byte *)puVar23[2];
      local_260 = (byte *)puVar23[3];
    }
    else {
      local_210 = (byte *)0xff;
      local_270 = (byte *)0xff00;
      local_274 = (byte *)0xff0000;
      local_260 = (byte *)0xff000000;
      local_10c = 1;
    }
    local_258 = (byte *)0x0;
    for (pbVar25 = local_210; (pbVar25 != (byte *)0x0 && (((uint)pbVar25 & 1) == 0));
        pbVar25 = (byte *)((uint)pbVar25 >> 1)) {
      local_258 = local_258 + 1;
    }
    local_24c = (byte *)0x0;
    for (pbVar25 = local_270; (pbVar25 != (byte *)0x0 && (((uint)pbVar25 & 1) == 0));
        pbVar25 = (byte *)((uint)pbVar25 >> 1)) {
      local_24c = local_24c + 1;
    }
    local_248 = (byte *)0x0;
    for (pbVar25 = local_274; (pbVar25 != (byte *)0x0 && (((uint)pbVar25 & 1) == 0));
        pbVar25 = (byte *)((uint)pbVar25 >> 1)) {
      local_248 = local_248 + 1;
    }
    local_25c = (byte *)0x0;
    for (pbVar25 = local_260; (pbVar25 != (byte *)0x0 && (((uint)pbVar25 & 1) == 0));
        pbVar25 = (byte *)((uint)pbVar25 >> 1)) {
      local_25c = local_25c + 1;
    }
    if (cVar3 == '\0') {
      local_104 = (uint)local_22c;
      local_124 = local_27c;
    }
    else {
      iVar30 = *(int *)(*(int *)(param_2 + 8) + 0x10);
      if (iVar30 == 4) {
        local_104 = *(uint *)(*(int *)(*(int *)(param_2 + 8) + 0xc) + 0xc);
      }
      else {
        local_104 = 0xff000000;
        if (iVar30 != 3) {
          local_104 = (uint)local_22c;
        }
      }
      local_124 = 0;
      for (uVar29 = local_104; (uVar29 & 1) == 0; uVar29 = uVar29 >> 1) {
        local_124 = local_124 + 1;
      }
    }
    local_b0 = 1;
    local_11c = 1;
  }
  if (((int)local_214 < 0) || ((int)local_218 < 0)) {
    iVar30 = *piVar28;
    local_48 = iVar30;
    piVar31 = piVar28 + 1;
    local_44 = *piVar31;
    piVar1 = piVar28 + 2;
    local_40 = *piVar1;
    piVar2 = piVar28 + 3;
    piVar28 = &local_48;
    local_3c = *piVar2;
    if ((int)local_214 < 0) {
      local_214 = -local_214;
      local_48 = *piVar1;
      local_40 = iVar30;
      local_264 = (byte *)(uint)(local_264 == (byte *)0x0);
    }
    if ((int)local_218 < 0) {
      local_218 = -local_218;
      local_44 = *piVar2;
      local_3c = *piVar31;
      if (iVar47 == 0) {
        iVar47 = 1;
      }
      else {
        iVar47 = 0;
      }
    }
  }
  if ((*(uint *)(param_2 + 0x24) & 8) == 0) {
    local_250 = local_27c;
    local_244 = local_27c;
    local_254 = local_27c;
    local_23c = local_27c;
    local_278 = local_27c;
    iVar30 = iVar44;
LAB_c0898958:
    iVar44 = *(int *)(param_2 + 0x10);
    uVar29 = *(uint *)(param_2 + 0x24) & 4;
    local_228 = *(byte **)(param_2 + 0x20);
    if (iVar44 != 0) {
      piVar31 = *(int **)(param_2 + 0x30);
      if (piVar31 == (int *)0x0) {
        iVar45 = 0;
        iVar44 = 0;
      }
      else {
        iVar45 = *(int *)(iVar44 + 0x30) - piVar31[1];
        iVar44 = *(int *)(iVar44 + 0x2c) - *piVar31;
      }
      iVar35 = *(int *)(param_2 + 0x10);
      iVar26 = *(int *)(iVar35 + 0x2c);
      if (iVar26 == 0) {
        trap(0x1c00);
      }
      if ((iVar26 == -1) && (*piVar28 + iVar44 == -0x80000000)) {
        trap(0x1800);
      }
      local_38 = (*piVar28 + iVar44) % iVar26;
      iVar26 = *(int *)(iVar35 + 0x2c);
      if (iVar26 == 0) {
        trap(0x1c00);
      }
      if ((iVar26 == -1) && (piVar28[2] + iVar44 == -0x80000000)) {
        trap(0x1800);
      }
      local_30 = (piVar28[2] + iVar44) % iVar26;
      iVar44 = *(int *)(iVar35 + 0x30);
      if (iVar44 == 0) {
        trap(0x1c00);
      }
      if ((iVar44 == -1) && (piVar28[1] + iVar45 == -0x80000000)) {
        trap(0x1800);
      }
      local_34 = (piVar28[1] + iVar45) % iVar44;
      iVar44 = *(int *)(iVar35 + 0x30);
      if (iVar44 == 0) {
        trap(0x1c00);
      }
      if ((iVar44 == -1) && (piVar28[3] + iVar45 == -0x80000000)) {
        trap(0x1800);
      }
      local_2c = (piVar28[3] + iVar45) % iVar44;
    }
    local_a8 = (uint *)0x0;
    local_7c = (uint *)0x0;
    local_f8 = (byte *)0x0;
    local_cc = (byte *)0x0;
    local_1cc = 0;
    local_208 = (byte *)0x0;
    local_1dc = (byte *)0x0;
    local_1a0 = local_228;
    local_b4 = uVar29;
    if ((((*(int *)(param_2 + 8) != 0) &&
         (FUN_c08a5da4((int *)&local_208,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
                       *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar39,iVar30),
         local_1a0 = local_1ec, uVar29 != 0)) &&
        (iVar44 = *(int *)(param_2 + 8), 8 < *(int *)(&LAB_c0891154 + *(int *)(iVar44 + 0x1c) * 4)))
       && ((*(int *)(iVar44 + 0x10) == 4 || (*(int *)(iVar44 + 0x10) == 3)))) {
      puVar23 = *(uint **)(iVar44 + 0xc);
      local_1a0 = (byte *)(puVar23[2] | puVar23[1] | *puVar23);
    }
    if (*(int *)(param_2 + 0x10) != 0) {
      FUN_c08a6078((int *)&local_a8,*(int *)(param_2 + 0x10),*(int *)(param_2 + 0x34),
                   *(int *)(param_2 + 0x38),&local_38);
    }
    if ((bVar22 == bVar24) || (*(int *)(param_2 + 0xc) != 0)) {
      if (*(int *)(param_2 + 0xc) == 0) {
        local_f4 = (byte *)0x0;
      }
      else {
        FUN_c08a5b70((int *)&local_f8,*(int *)(param_2 + 0xc),*(int *)(param_2 + 0x34),
                     *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x2c),iVar39,iVar30);
      }
      if ((bVar22 == bVar24) || (local_f8 != (byte *)0x0)) {
        iVar39 = *(int *)(param_2 + 4);
        local_16c = *(int *)(&LAB_c0891154 + *(int *)(iVar39 + 0x1c) * 4);
        if (local_16c < 8) {
LAB_c0898c40:
          FUN_c08a5da4((int *)&local_190,iVar39,(int)local_264,iVar47,piVar28,iVar43,iVar41);
          bVar4 = false;
        }
        else {
          if (*(int *)(iVar39 + 0x38) != 0) {
            local_13c = 1;
            goto LAB_c0898c40;
          }
          bVar4 = true;
          local_13c = 0;
          bVar10 = true;
          if (iVar47 == 0) {
            iVar39 = *(int *)(param_2 + 4);
            local_18c = -*(int *)(iVar39 + 8);
            iVar39 = ((piVar28[3] - iVar41) + -1) * *(int *)(iVar39 + 8) + *(int *)(iVar39 + 4);
          }
          else {
            iVar39 = *(int *)(param_2 + 4);
            local_18c = *(int *)(iVar39 + 8);
            iVar39 = (piVar28[1] + iVar41) * *(int *)(iVar39 + 8) + *(int *)(iVar39 + 4);
          }
          local_170 = local_16c >> 3;
          if (local_264 == (byte *)0x0) {
            if (local_16c < 0) {
              local_170 = local_16c + 7 >> 3;
            }
            local_170 = -local_170;
            iVar44 = -(((piVar28[2] - iVar43) + -1) * local_170);
          }
          else {
            if (local_16c < 0) {
              local_170 = local_16c + 7 >> 3;
            }
            iVar44 = (*piVar28 + iVar43) * local_170;
          }
          local_190 = (uint *)(iVar39 + iVar44);
          local_174 = 0xffffffff >> (0x20U - local_16c & 0x1f);
          local_158 = 0;
        }
        local_b8 = local_228;
        pbVar25 = local_228;
        if (bVar9) {
          local_b8 = local_f4;
          pbVar25 = local_204;
        }
        if (*(int *)(param_2 + 0x28) == 0) {
          uVar29 = 0;
        }
        else {
          uVar29 = local_174;
          if ((*(int *)(param_2 + 0x28) != 0xffff) &&
             (((((uVar29 = *(uint *)(param_2 + 0x20) & local_174, bVar22 != bVar24 ||
                 (local_b4 != 0)) || (local_11c != 0)) || (local_114 != 0)) ||
              ((bVar24 != 0xcc && ((bVar24 != 0xf0 || (*(int *)(param_2 + 0x10) != 0)))))))) {
            local_bc = 1;
          }
        }
        if (local_218 != 0) {
          local_fc = local_228;
          local_120 = local_228;
          local_118 = local_228;
          local_108 = local_228;
          local_110 = local_228;
          local_22c = local_224;
          local_198 = local_228;
          local_100 = local_228;
          local_264 = local_228;
          pbVar17 = local_204;
          pbVar32 = local_1a4;
          pbVar38 = local_228;
          uVar34 = local_214;
          pbVar40 = local_224;
          pbVar42 = local_228;
          local_280 = bVar24;
          local_1d4 = uVar29;
          local_74 = uVar29;
          do {
            puVar23 = local_a8;
            local_218 = local_218 - 1;
            if (bVar9) {
              if (local_128 == 0) {
                pbVar33 = pbVar25;
                pbVar11 = pbVar25;
                pbVar12 = local_b8;
                if ((int)local_278 < 0) {
                  local_278 = local_278 + local_23c;
                  if (local_19c != 0) {
                    pbVar17 = (byte *)0x0;
                    local_204 = (byte *)0x0;
                    local_f4 = (byte *)0x0;
                  }
                  goto LAB_c0898f48;
                }
              }
              else {
                for (; pbVar33 = pbVar17, pbVar11 = local_204, pbVar12 = local_f4,
                    (int)local_278 < 0; local_278 = local_278 + local_23c) {
                  if (local_1b4 == 0) {
                    local_208 = pbVar17 + (int)local_208;
                  }
                  else {
                    pbVar32 = pbVar32 + (int)pbVar17;
                  }
                  local_f8 = local_f4 + (int)local_f8;
                  pbVar38 = local_264;
                  local_1a4 = pbVar32;
                }
              }
              local_f4 = pbVar12;
              local_204 = pbVar11;
              pbVar17 = pbVar33;
              local_278 = local_278 + local_254;
            }
LAB_c0898f48:
            pbVar33 = pbVar32;
            if (local_208 == (byte *)0x0) {
              pbVar11 = local_208;
              if (local_1cc != 0) {
                pbVar33 = pbVar32 + (int)pbVar17;
                local_1b0 = local_1a8;
                local_1ac = pbVar32;
                local_1a4 = pbVar33;
              }
            }
            else {
              local_1dc = local_208;
              pbVar11 = pbVar17 + (int)local_208;
              if (local_1f0 == 0) {
                local_1d8 = *(byte **)local_208;
                local_1d0 = local_1fc;
              }
            }
            local_208 = pbVar11;
            if (local_f8 != (byte *)0x0) {
              local_cc = local_f8;
              local_c8 = *(byte **)local_f8;
              local_c0 = local_ec;
              local_f8 = local_f4 + (int)local_f8;
            }
            if (local_a8 != (uint *)0x0) {
              local_7c = local_a8;
              local_50 = (uint *)((int)local_a8 - local_58);
              local_60 = local_60 + -1;
              if (local_60 == 0) {
                local_a8 = local_54;
                local_60 = local_5c;
              }
              else {
                local_a8 = (uint *)(local_a4 + (int)local_a8);
              }
              local_78 = *puVar23;
              local_70 = local_9c;
              local_6c = local_64;
            }
            if (local_13c == 0) {
              local_164 = local_190;
              local_190 = (uint *)((int)local_190 + local_18c);
            }
            else {
              local_134 = local_12c;
              local_12c = local_12c + local_18c;
              local_138 = local_130;
            }
            if (!bVar4) {
              local_158 = local_184;
            }
            if (bVar8) {
              local_fc = local_cc;
              local_118 = local_c8;
              local_110 = local_c0;
              if (local_1b4 == 0) {
                local_120 = local_1dc;
                local_108 = local_1d8;
                local_100 = local_1d0;
              }
              else {
                local_198 = local_1b0;
                local_22c = local_1ac;
                pbVar40 = local_1ac;
                pbVar42 = local_1b0;
              }
            }
            iVar44 = 0;
            iVar39 = local_268;
            pbVar32 = local_120;
            if (0 < (int)uVar34) {
              do {
                if (local_1dc == (byte *)0x0) {
                  if (local_1cc != 0) {
                    if (local_1e4 == 8) {
                      puVar15 = (undefined1 *)FUN_c08a5f10((int)&local_208);
                      local_1d4 = CONCAT31(local_1d4._1_3_,*puVar15);
                      uVar29 = local_1d4;
                    }
                    else if (local_1e4 == 0x10) {
                      puVar16 = (undefined2 *)FUN_c08a5f10((int)&local_208);
                      local_1d4 = CONCAT22(local_1d4._2_2_,*puVar16);
                      uVar29 = local_1d4;
                    }
                    else if (local_1e4 == 0x18) {
                      pbVar38 = (byte *)FUN_c08a5f10((int)&local_208);
                      uVar29 = ((uint)pbVar38[2] * 0x100 + (uint)pbVar38[1]) * 0x100 +
                               (uint)*pbVar38;
                    }
                    else if (local_1e4 == 0x20) {
                      puVar23 = (uint *)FUN_c08a5f10((int)&local_208);
                      uVar29 = *puVar23;
                    }
                    local_1b0 = local_1b0 + local_1c8;
                    goto LAB_c089922c;
                  }
                }
                else {
                  if (local_1f0 == 0) {
                    if (((uint)local_1d0 & 0xff00) == 0) {
                      local_1dc = local_1dc + local_1e8;
                      local_1d0 = local_200;
                      local_1d8 = *(byte **)local_1dc;
                    }
                    uVar29 = (uint)local_1d8 >> (((uint)local_1d0 >> 0x10 ^ (uint)local_1e0) & 0x1f)
                    ;
                    local_1d0 = local_1d0 + local_1f8;
                  }
                  else {
                    uVar29 = ((uint)local_1dc[2] * 0x100 + (uint)local_1dc[1]) * 0x100 +
                             (uint)*local_1dc;
                    local_1dc = local_1dc + local_1e8;
                  }
LAB_c089922c:
                  uVar29 = uVar29 & (uint)local_1ec;
                  pbVar38 = (byte *)(uVar29 & (uint)local_1a0);
                  if (*(int *)(param_2 + 0x3c) != 0) {
                    uVar29 = *(uint *)(uVar29 * 4 + *(int *)(param_2 + 0x3c));
                  }
                  local_264 = pbVar38;
                  local_1d4 = uVar29;
                  if (*(code **)(param_2 + 0x40) != (code *)0x0) {
                    uVar29 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),uVar29);
                    local_1d4 = uVar29;
                  }
                }
                if (local_bc == 0) {
LAB_c089a024:
                  bVar36 = (byte)uVar29;
                  if (local_13c == 0) {
                    if (bVar10) {
                      if (local_16c == 8) {
                        *(byte *)local_164 = bVar36;
                        uVar29 = local_1d4;
                      }
                      else if (local_16c == 0x10) {
                        *(short *)local_164 = (short)uVar29;
                        uVar29 = local_1d4;
                      }
                      else if (local_16c == 0x18) {
                        *(byte *)local_164 = bVar36;
                        *(byte *)((int)local_164 + 1) = (byte)(local_1d4 >> 8);
                        *(byte *)((int)local_164 + 2) = (byte)(local_1d4 >> 0x10);
                        uVar29 = local_1d4;
                      }
                      else if (local_16c == 0x20) {
                        *local_164 = uVar29;
                        uVar29 = local_1d4;
                      }
                      local_164 = (uint *)((int)local_164 + local_170);
                    }
                    else {
                      uVar27 = local_158 >> 0x10 ^ (uint)local_168;
                      local_160 = ~(local_174 << (uVar27 & 0x1f)) & local_160 |
                                  uVar29 << (uVar27 & 0x1f);
                      local_158 = local_17c + local_158;
                      if ((local_158 & 0xff00) == 0) {
                        *local_164 = local_160;
                        local_158 = local_188;
                        local_164 = (uint *)((int)local_164 + local_170);
                        uVar29 = local_1d4;
                        if (iVar44 != uVar34 - 1) {
                          local_160 = *local_164;
                        }
                      }
                    }
                  }
                  else {
                    if (local_16c == 8) {
                      pbVar17 = (byte *)FUN_c08a5f10((int)&local_190);
                      *pbVar17 = bVar36;
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x10) {
                      puVar16 = (undefined2 *)FUN_c08a5f10((int)&local_190);
                      *puVar16 = (short)uVar29;
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x18) {
                      puVar15 = (undefined1 *)FUN_c08a5f10((int)&local_190);
                      *puVar15 = (char)local_1d4;
                      puVar15[1] = (char)(local_1d4 >> 8);
                      puVar15[2] = (char)(local_1d4 >> 0x10);
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x20) {
                      puVar23 = (uint *)FUN_c08a5f10((int)&local_190);
                      *puVar23 = local_1d4;
                      uVar29 = local_1d4;
                    }
                    local_138 = local_138 + local_150;
                  }
                }
                else {
                  if (local_7c != (uint *)0x0) {
                    iVar41 = local_6c + -1;
                    if (local_6c == 0) {
                      local_7c = local_50;
                      local_70 = local_a0;
                      local_78 = *local_50;
                      local_6c = local_68 + -1;
                    }
                    else {
                      local_6c = iVar41;
                      if ((local_70 & 0xff00) == 0) {
                        local_7c = (uint *)(local_88 + (int)local_7c);
                        local_70 = local_a0;
                        local_78 = *local_7c;
                      }
                    }
                    local_74 = local_78 >> ((local_70 >> 0x10 ^ (uint)local_80) & 0x1f);
                    local_70 = local_98 + local_70;
                  }
                  if (local_cc != (byte *)0x0) {
                    if (((uint)local_c0 & 0xff00) == 0) {
                      local_cc = local_cc + local_d8;
                      local_c0 = local_f0;
                      local_c8 = *(byte **)local_cc;
                    }
                    local_280 = bVar22;
                    if ((1 << (((uint)local_c0 >> 0x10 ^ (uint)local_d0) & 0x1f) & (uint)local_c8)
                        != 0) {
                      local_280 = bVar24;
                    }
                    local_c0 = local_c0 + local_e8;
                  }
                  pbVar17 = local_1b0;
                  pbVar33 = local_1ac;
                  if (local_114 != 0) {
                    if (bVar8) {
                      if (iVar39 < 0) {
                        iVar39 = iVar39 + local_244;
                        local_cc = local_fc;
                        local_c8 = local_118;
                        local_c0 = local_110;
                        pbVar17 = pbVar42;
                        pbVar33 = pbVar40;
                        if (local_1b4 == 0) {
                          local_1d8 = local_108;
                          local_1d0 = local_100;
                          local_1dc = pbVar32;
                          pbVar17 = local_1b0;
                          pbVar33 = local_1ac;
                        }
                      }
                      else {
                        iVar39 = iVar39 + local_250;
                        local_fc = local_cc;
                        local_118 = local_c8;
                        local_110 = local_c0;
                        if (local_1b4 == 0) {
                          local_120 = local_1dc;
                          local_108 = local_1d8;
                          local_100 = local_1d0;
                          pbVar32 = local_1dc;
                        }
                        else {
                          local_198 = local_1b0;
                          local_22c = local_1ac;
                          pbVar40 = local_1ac;
                          pbVar42 = local_1b0;
                        }
                      }
                    }
                    else {
                      if (iVar39 < 0) {
                        do {
                          if (local_1b4 == 0) {
                            if (local_1f0 == 0) {
                              if (((uint)local_1d0 & 0xff00) == 0) {
                                local_1dc = local_1dc + local_1e8;
                                local_1d0 = local_200;
                                if (iVar44 != uVar34 - 1) {
                                  local_1d8 = *(byte **)local_1dc;
                                }
                              }
                              local_1d0 = local_1d0 + local_1f8;
                            }
                            else {
                              local_1dc = local_1dc + local_1e8;
                            }
                          }
                          else {
                            local_1b0 = local_1b0 + local_1c8;
                          }
                          if (*(int *)(param_2 + 0xc) != 0) {
                            if (((uint)local_c0 & 0xff00) == 0) {
                              local_cc = local_cc + local_d8;
                              local_c0 = local_f0;
                              local_c8 = *(byte **)local_cc;
                            }
                            local_c0 = local_c0 + local_e8;
                          }
                          iVar39 = iVar39 + local_244;
                          pbVar32 = local_120;
                        } while (iVar39 < 0);
                      }
                      iVar39 = iVar39 + local_250;
                      pbVar17 = local_1b0;
                    }
                  }
                  local_1ac = pbVar33;
                  local_1b0 = pbVar17;
                  if (local_b0 != 0) {
                    if (local_13c == 0) {
                      if (bVar10) {
                        if (local_16c == 8) {
                          local_15c = CONCAT31(local_15c._1_3_,(byte)*local_164);
                        }
                        else if (local_16c == 0x10) {
                          local_15c = CONCAT22(local_15c._2_2_,(short)*local_164);
                        }
                        else if (local_16c == 0x18) {
                          local_15c = ((uint)*(byte *)((int)local_164 + 2) * 0x100 +
                                      (uint)*(byte *)((int)local_164 + 1)) * 0x100 +
                                      (uint)(byte)*local_164;
                        }
                        else if (local_16c == 0x20) {
                          local_15c = *local_164;
                        }
                      }
                      else {
                        local_15c = local_160 >> ((local_158 >> 0x10 ^ (uint)local_168) & 0x1f);
                      }
                    }
                    else if (local_16c == 8) {
                      puVar15 = (undefined1 *)FUN_c08a5f10((int)&local_190);
                      local_15c = CONCAT31(local_15c._1_3_,*puVar15);
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x10) {
                      puVar16 = (undefined2 *)FUN_c08a5f10((int)&local_190);
                      local_15c = CONCAT22(local_15c._2_2_,*puVar16);
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x18) {
                      pbVar17 = (byte *)FUN_c08a5f10((int)&local_190);
                      local_15c = ((uint)pbVar17[2] * 0x100 + (uint)pbVar17[1]) * 0x100 +
                                  (uint)*pbVar17;
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x20) {
                      puVar23 = (uint *)FUN_c08a5f10((int)&local_190);
                      local_15c = *puVar23;
                      uVar29 = local_1d4;
                    }
                  }
                  uVar27 = (uint)local_280;
                  if (uVar27 < 0xad) {
                    if (uVar27 == 0xac) {
                      uVar37 = (local_15c ^ uVar29) & local_74 ^ uVar29;
                    }
                    else if (uVar27 < 0x56) {
                      uVar37 = local_15c;
                      if (uVar27 == 0x55) {
LAB_c0899784:
                        uVar37 = ~uVar37;
                      }
                      else if (uVar27 == 0) {
                        uVar37 = 0;
                      }
                      else {
                        if (uVar27 == 0x11) {
                          uVar37 = local_15c | uVar29;
                          goto LAB_c0899784;
                        }
                        if (uVar27 == 0x22) {
                          uVar37 = ~uVar29 & local_15c;
                        }
                        else if (uVar27 == 0x33) {
                          uVar37 = ~uVar29;
                        }
                        else {
                          if (uVar27 != 0x44) goto LAB_c08998d0;
                          uVar37 = ~local_15c & uVar29;
                        }
                      }
                    }
                    else if (uVar27 == 0x5a) {
                      uVar37 = local_15c ^ local_74;
                    }
                    else if (uVar27 == 0x66) {
                      uVar37 = local_15c ^ uVar29;
                    }
                    else {
                      uVar37 = local_15c;
                      if (uVar27 != 0x88) {
                        uVar14 = 0xaa;
                        goto LAB_c08997c4;
                      }
LAB_c08997d8:
                      uVar37 = uVar37 & uVar29;
                    }
                  }
                  else if (uVar27 < 0xe3) {
                    if (uVar27 == 0xe2) {
                      uVar37 = ~uVar29 & local_15c;
                      uVar27 = local_74;
                    }
                    else {
                      if (uVar27 != 0xb8) {
                        if (uVar27 == 0xbb) {
                          uVar37 = ~uVar29 | local_15c;
                        }
                        else {
                          uVar37 = local_74;
                          if (uVar27 == 0xc0) goto LAB_c08997d8;
                          uVar14 = 0xcc;
LAB_c08997c4:
                          uVar37 = uVar29;
                          if (uVar27 != uVar14) {
LAB_c08998d0:
                            uVar37 = FUN_c08a548c(local_15c,uVar29,local_74,uVar27,(byte)local_16c);
                          }
                        }
                        goto LAB_c0899930;
                      }
                      uVar37 = ~uVar29 & local_74;
                      uVar27 = local_15c;
                    }
                    uVar37 = uVar37 | uVar27 & uVar29;
                  }
                  else if (uVar27 == 0xee) {
                    uVar37 = local_15c | uVar29;
                  }
                  else {
                    uVar37 = local_74;
                    if (uVar27 != 0xf0) {
                      if (uVar27 == 0xfb) {
                        uVar37 = ~uVar29 | local_15c | local_74;
                      }
                      else {
                        if (uVar27 != 0xff) goto LAB_c08998d0;
                        uVar37 = 0xffffffff;
                      }
                    }
                  }
LAB_c0899930:
                  if (local_11c != 0) {
                    uVar29 = (uint)*(byte *)(param_2 + 0x4e);
                    uVar27 = 0;
                    puVar23 = (uint *)0x0;
                    if (local_10c != 0) {
                      puVar23 = *(uint **)(*(int *)(param_2 + 4) + 0xc);
                      uVar27 = *(uint *)(*(int *)(param_2 + 4) + 0x10);
                      uVar37 = puVar23[uVar37];
                      local_15c = puVar23[local_15c & local_174];
                    }
                    uVar46 = (uVar37 & (uint)local_210) >> ((uint)local_258 & 0x1f);
                    uVar18 = (uVar37 & (uint)local_270) >> ((uint)local_24c & 0x1f);
                    uVar14 = (uVar37 & (uint)local_274) >> ((uint)local_248 & 0x1f);
                    uVar34 = (uVar37 & (uint)local_260) >> ((uint)local_25c & 0x1f);
                    uVar21 = (local_15c & (uint)local_210) >> ((uint)local_258 & 0x1f);
                    uVar20 = (local_15c & (uint)local_270) >> ((uint)local_24c & 0x1f);
                    uVar19 = (local_15c & (uint)local_274) >> ((uint)local_248 & 0x1f);
                    uVar37 = (local_15c & (uint)local_260) >> ((uint)local_25c & 0x1f);
                    if (*(char *)(param_2 + 0x4f) == '\0') {
LAB_c0899d38:
                      uVar19 = uVar21 << 0x10 | uVar19;
                      uVar20 = uVar37 << 0x10 | uVar20;
                      uVar37 = ((uVar46 << 0x10 | uVar14) - uVar19) * uVar29 + uVar19 * 0xff +
                               0x800080;
                      uVar29 = ((uVar34 << 0x10 | uVar18) - uVar20) * uVar29 + uVar20 * 0xff +
                               0x800080;
                      uVar19 = ((uVar37 >> 8 & 0xff00ff) + uVar37 >> 8 ^
                               (uVar29 >> 8 & 0xffff00ff) + uVar29) & 0xff00ff ^
                               (uVar29 >> 8 & 0xff00ff) + uVar29;
                    }
                    else {
                      uVar34 = ((uint)pbVar38 & local_104) >> (local_124 & 0x1f);
                      if (uVar34 == 0) {
                        uVar19 = ((uVar37 << 8 | uVar21) << 8 | uVar20) << 8 | uVar19;
                      }
                      else if (uVar34 == 0xff) {
                        uVar34 = 0xff;
                        if (uVar29 != 0xff) goto LAB_c0899d38;
                        uVar19 = ((uVar46 | 0xff00) << 8 | uVar18) << 8 | uVar14;
                      }
                      else if (uVar29 == 0xff) {
                        uVar29 = (uVar37 << 0x10 | uVar20) * (0xff - uVar34) + 0x800080;
                        uVar37 = (uVar21 << 0x10 | uVar19) * (0xff - uVar34) + 0x800080;
                        uVar34 = ((uVar29 >> 8 & 0xff00ff) + uVar29 >> 8 & 0xff00ff) +
                                 (uVar34 << 0x10 | uVar18);
                        uVar29 = ((uint)local_260 >> ((uint)local_25c & 0x1f)) << 0x10;
                        uVar19 = ((uVar37 >> 8 & 0xff00ff) + uVar37 >> 8 & 0xff00ff) +
                                 (uVar46 << 0x10 | uVar14);
                        if (uVar29 < (uVar34 & 0xffff0000)) {
                          uVar34 = uVar34 & 0xffff | uVar29;
                        }
                        uVar29 = (uint)local_270 >> ((uint)local_24c & 0x1f);
                        if (uVar29 < (uVar34 & 0xffff)) {
                          uVar34 = uVar34 & 0xff0000 | uVar29;
                        }
                        uVar29 = ((uint)local_210 >> ((uint)local_258 & 0x1f)) << 0x10;
                        if (uVar29 < (uVar19 & 0xffff0000)) {
                          uVar19 = uVar19 & 0xffff | uVar29;
                        }
                        uVar29 = (uint)local_274 >> ((uint)local_248 & 0x1f);
                        if (uVar29 < (uVar19 & 0xffff)) {
                          uVar19 = uVar19 & 0xff0000 | uVar29;
                        }
                        uVar19 = uVar34 << 8 | uVar19;
                      }
                      else {
                        uVar18 = (uVar34 << 0x10 | uVar18) * uVar29 + 0x800080;
                        uVar29 = (uVar46 << 0x10 | uVar14) * uVar29 + 0x800080;
                        uVar34 = (uVar18 >> 8 & 0xff00ff) + uVar18;
                        uVar14 = ((uVar29 >> 8 & 0xff00ff) + uVar29 >> 8 ^
                                 (uVar18 >> 8 & 0xffff00ff) + uVar18) & 0xff00ff ^ uVar34;
                        uVar29 = 0xff - (uVar34 >> 0x18) & 0xff;
                        uVar34 = (uVar37 << 0x10 | uVar20) * uVar29 + 0x800080;
                        uVar29 = (uVar21 << 0x10 | uVar19) * uVar29 + 0x800080;
                        uVar34 = ((uVar34 >> 8 & 0xff00ff) + uVar34 >> 8 & 0xff00ff) +
                                 (uVar14 >> 8 & 0xff00ff);
                        uVar19 = ((uVar29 >> 8 & 0xff00ff) + uVar29 >> 8 & 0xff00ff) +
                                 (uVar14 & 0xff00ff);
                        uVar29 = ((uint)local_260 >> ((uint)local_25c & 0x1f)) << 0x10;
                        if (uVar29 < (uVar34 & 0xffff0000)) {
                          uVar34 = uVar34 & 0xffff | uVar29;
                        }
                        uVar29 = (uint)local_270 >> ((uint)local_24c & 0x1f);
                        if (uVar29 < (uVar34 & 0xffff)) {
                          uVar34 = uVar34 & 0xff0000 | uVar29;
                        }
                        uVar29 = ((uint)local_210 >> ((uint)local_258 & 0x1f)) << 0x10;
                        if (uVar29 < (uVar19 & 0xffff0000)) {
                          uVar19 = uVar19 & 0xffff | uVar29;
                        }
                        uVar29 = (uint)local_274 >> ((uint)local_248 & 0x1f);
                        if (uVar29 < (uVar19 & 0xffff)) {
                          uVar19 = uVar19 & 0xff0000 | uVar29;
                        }
                        uVar19 = uVar34 << 8 | uVar19;
                      }
                    }
                    uVar37 = (uVar19 >> 8 & 0xff) << ((uint)local_24c & 0x1f) & (uint)local_270 |
                             (uVar19 >> 0x10 & 0xff) << ((uint)local_258 & 0x1f) & (uint)local_210 |
                             (uVar19 & 0xff) << ((uint)local_248 & 0x1f) & (uint)local_274 |
                             (uVar19 >> 0x18) << ((uint)local_25c & 0x1f) & (uint)local_260;
                    uVar34 = local_214;
                    pbVar42 = local_198;
                    if (local_10c != 0) {
                      local_1d4 = uVar37;
                      uVar29 = FUN_c08a5590(uVar37,*puVar23);
                      uVar14 = 1;
                      uVar37 = 0;
                      uVar34 = local_214;
                      pbVar40 = local_22c;
                      pbVar42 = local_198;
                      if (1 < uVar27) {
                        do {
                          puVar23 = puVar23 + 1;
                          uVar34 = FUN_c08a5590(local_1d4,*puVar23);
                          if (uVar34 < uVar29) {
                            uVar37 = uVar14;
                            uVar29 = uVar34;
                          }
                          uVar14 = uVar14 + 1;
                          uVar34 = local_214;
                          pbVar42 = local_198;
                        } while (uVar14 < uVar27);
                      }
                    }
                  }
                  uVar29 = uVar37 & local_174;
                  pbVar38 = local_264;
                  local_1d4 = uVar29;
                  if ((local_280 != 0xaa) && ((local_b4 == 0 || (local_264 != local_228))))
                  goto LAB_c089a024;
                  if (local_13c == 0) {
                    if (bVar10) {
                      local_164 = (uint *)((int)local_164 + local_170);
                    }
                    else {
                      local_158 = local_180 + local_158;
                      if ((local_158 & 0xff00) == 0) {
                        if ((local_158 & 0xff) != 0) {
                          *local_164 = local_160;
                        }
                        local_164 = (uint *)((int)local_164 + local_170);
                        local_158 = local_188;
                        local_160 = *local_164;
                      }
                    }
                  }
                  else {
                    local_138 = local_138 + local_150;
                  }
                }
                iVar44 = iVar44 + 1;
                pbVar17 = local_204;
                pbVar33 = local_1a4;
                bVar4 = bVar10;
              } while (iVar44 < (int)uVar34);
            }
            pbVar32 = pbVar33;
            if ((local_158 & 0xff) != 0) {
              *local_164 = local_160;
              pbVar17 = local_204;
              pbVar32 = local_1a4;
              uVar29 = local_1d4;
            }
          } while (local_218 != 0);
        }
        goto LAB_c0899f7c;
      }
    }
    uVar13 = 0x80070057;
  }
  else {
    piVar31 = *(int **)(param_2 + 0x18);
    uVar29 = piVar31[2] - *piVar31;
    bVar4 = (int)local_214 <= (int)uVar29;
    uVar34 = piVar31[3] - piVar31[1];
    local_250 = local_27c;
    local_244 = local_27c;
    if (!bVar4) {
      local_250 = local_214;
      local_244 = uVar29;
    }
    bVar8 = !bVar4;
    bVar5 = (int)uVar29 <= (int)local_214;
    if (!bVar5) {
      local_250 = uVar29;
      local_244 = local_214;
    }
    if ((!bVar4) || (!bVar5)) {
      local_244 = local_244 * 2;
      local_250 = local_244 + local_250 * -2;
      local_114 = 1;
      if (bVar5) {
        local_268 = uVar29 * 3 + local_214 * -2;
      }
      else {
        local_268 = local_214 * 2 - uVar29;
      }
    }
    bVar6 = (int)uVar34 < (int)local_218;
    local_254 = local_27c;
    local_23c = local_27c;
    if (bVar6) {
      local_254 = local_218;
      local_23c = uVar34;
    }
    local_19c = (uint)bVar6;
    bVar7 = (int)local_218 < (int)uVar34;
    if (bVar7) {
      local_254 = uVar34;
      local_23c = local_218;
    }
    local_128 = (uint)bVar7;
    if ((bVar6) || (bVar7)) {
      local_23c = local_23c * 2;
      local_254 = local_23c + local_254 * -2;
      bVar9 = true;
      if (bVar7) {
        local_27c = local_218 * 2 - uVar34;
      }
      else {
        local_27c = uVar34 * 3 + local_218 * -2;
      }
    }
    if (*(int **)(param_2 + 0x1c) == (int *)0x0) {
LAB_c0898834:
      iVar30 = iVar43;
      if (!bVar5) {
        for (; local_268 < 0; local_268 = local_244 + local_268) {
          iVar39 = iVar39 + 1;
        }
        local_268 = local_250 + local_268;
      }
      for (; iVar30 != 0; iVar30 = iVar30 + -1) {
        if (bVar5) {
          if (bVar4) goto LAB_c089888c;
          if (-1 < local_268) goto LAB_c0898888;
          local_268 = local_244 + local_268;
        }
        else {
          for (; local_268 < 0; local_268 = local_244 + local_268) {
            iVar39 = iVar39 + 1;
          }
LAB_c0898888:
          local_268 = local_250 + local_268;
LAB_c089888c:
          iVar39 = iVar39 + 1;
        }
      }
      iVar30 = iVar41;
      if (local_128 == 0) {
        local_278 = local_27c;
        iVar45 = iVar41;
        if (local_19c != 0) {
          for (; iVar30 = iVar44, iVar45 != 0; iVar45 = iVar45 + -1) {
            uVar29 = local_23c;
            if (-1 < (int)local_278) {
              iVar44 = iVar44 + 1;
              uVar29 = local_254;
            }
            local_278 = local_278 + uVar29;
          }
        }
      }
      else {
        local_278 = local_254 * iVar41 + local_27c;
      }
      goto LAB_c0898958;
    }
    iVar41 = FUN_c08a5678((int *)&local_228,*(int **)(param_2 + 0x1c),piVar28);
    if (iVar41 == 0) {
      if (local_264 == (byte *)0x0) {
        iVar43 = piVar28[2] - local_220;
      }
      else {
        iVar43 = (int)local_228 - *piVar28;
      }
      if (iVar47 == 0) {
        iVar41 = piVar28[3] - local_21c;
      }
      else {
        iVar41 = (int)local_224 - piVar28[1];
      }
      local_214 = local_220 - (int)local_228;
      local_218 = local_21c - (int)local_224;
      goto LAB_c0898834;
    }
LAB_c0899f7c:
    uVar13 = 0;
  }
  return uVar13;
}



/* c089a208 FUN_c089a208 */

/* Boundary evidence: original MIPS .pdata c089a208..c089ae67. Semantic name remains unreviewed. */

undefined4 FUN_c089a208(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  byte *pbVar9;
  undefined2 *puVar10;
  uint *puVar11;
  byte bVar12;
  int iVar13;
  uint uVar14;
  byte bVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int *piVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint *puVar24;
  uint *puVar25;
  uint *puVar26;
  uint *puVar27;
  uint *puVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int local_1c4;
  uint local_1bc;
  int local_1b0;
  uint *local_1a0;
  int local_19c;
  uint local_184;
  int local_180;
  int local_17c;
  uint *local_174;
  uint local_16c;
  undefined4 local_168;
  int local_160;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  uint *local_138;
  int local_134;
  uint local_130;
  uint local_12c;
  int local_128;
  int local_120;
  uint local_11c;
  int local_118;
  int local_114;
  byte local_110;
  uint *local_10c;
  uint local_108;
  uint local_104;
  uint local_100;
  int local_fc;
  int local_f8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  uint *local_d0;
  int local_cc;
  uint local_c8;
  uint local_c4;
  int local_c0;
  int local_b8;
  uint local_b4;
  int local_b0;
  int local_ac;
  byte local_a8;
  uint *local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  int local_90;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint auStack_48 [4];
  uint auStack_38 [4];
  
  piVar20 = *(int **)(param_2 + 0x14);
  uVar23 = *(uint *)(param_2 + 0x28);
  local_1c4 = piVar20[2] - *piVar20;
  iVar35 = piVar20[3] - piVar20[1];
  local_5c = (uint)(((uVar23 >> 1 ^ uVar23) & 0x5555) != 0);
  piVar20 = *(int **)(param_2 + 0x18);
  iVar30 = 0;
  iVar16 = piVar20[2];
  iVar13 = *piVar20;
  iVar18 = piVar20[3];
  iVar17 = piVar20[1];
  iVar21 = (iVar16 - iVar13) * 0x10000;
  iVar36 = iVar21 / local_1c4;
  iVar29 = 0;
  iVar31 = 0;
  iVar33 = 0;
  if (local_1c4 == 0) {
    trap(0x1c00);
  }
  if ((local_1c4 == -1) && (iVar21 == -0x80000000)) {
    trap(0x1800);
  }
  iVar21 = (iVar18 - iVar17) * 0x10000;
  iVar37 = iVar21 / iVar35;
  if (iVar35 == 0) {
    trap(0x1c00);
  }
  if ((iVar35 == -1) && (iVar21 == -0x80000000)) {
    trap(0x1800);
  }
  local_1bc = iVar37 - 0x10000U >> 1;
  uVar22 = iVar36 - 0x10000U >> 1;
  FUN_c08a55f0(*(int *)(param_2 + 4),(int)auStack_48,(int *)auStack_38);
  iVar21 = iVar30;
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar30 = FUN_c08a5678(&local_58,*(int **)(param_2 + 0x1c),*(int **)(param_2 + 0x14));
    if (iVar30 != 0) {
      return 0;
    }
    piVar20 = *(int **)(param_2 + 0x14);
    if (*(int *)(param_2 + 0x34) == 0) {
      iVar30 = piVar20[2] - local_50;
    }
    else {
      iVar30 = local_58 - *piVar20;
    }
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar29 = piVar20[3] - local_4c;
    }
    else {
      iVar29 = local_54 - piVar20[1];
    }
    local_1c4 = local_50 - local_58;
    iVar35 = local_4c - local_54;
    iVar21 = iVar30;
  }
  for (; iVar34 = iVar29, iVar30 != 0; iVar30 = iVar30 + -1) {
    uVar22 = (uVar22 & 0xffff) + iVar36;
    iVar31 = (uVar22 >> 0x10) + iVar31;
  }
  for (; local_1bc = local_1bc & 0xffff, iVar34 != 0; iVar34 = iVar34 + -1) {
    local_1bc = local_1bc + iVar37;
    iVar33 = (local_1bc >> 0x10) + iVar33;
  }
  iVar30 = *(int *)(param_2 + 4);
  local_17c = *(int *)(&LAB_c0891154 + *(int *)(iVar30 + 0x1c) * 4);
  if (*(int *)(iVar30 + 0x38) == 0) {
    piVar20 = *(int **)(param_2 + 0x14);
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar30 = *(int *)(param_2 + 4);
      local_19c = -*(int *)(iVar30 + 8);
      iVar30 = ((piVar20[3] - iVar29) + -1) * *(int *)(iVar30 + 8) + *(int *)(iVar30 + 4);
    }
    else {
      local_19c = *(int *)(iVar30 + 8);
      iVar30 = (piVar20[1] + iVar29) * *(int *)(iVar30 + 8) + *(int *)(iVar30 + 4);
    }
    local_180 = local_17c >> 3;
    if (*(int *)(param_2 + 0x34) == 0) {
      if (local_17c < 0) {
        local_180 = local_17c + 7 >> 3;
      }
      local_180 = -local_180;
      iVar21 = -(((piVar20[2] - iVar21) + -1) * local_180);
    }
    else {
      if (local_17c < 0) {
        local_180 = local_17c + 7 >> 3;
      }
      iVar21 = (*piVar20 + iVar21) * local_180;
    }
    local_1a0 = (uint *)(iVar21 + iVar30);
    local_184 = (2 << (local_17c - 1U & 0x1f)) - 1;
    local_14c = 0;
    local_168 = 0;
  }
  else {
    FUN_c08a5da4((int *)&local_1a0,*(int *)(param_2 + 4),*(int *)(param_2 + 0x34),
                 *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x14),iVar21,iVar29);
  }
  FUN_c08a5da4((int *)&local_138,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
               *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar31,iVar33 + -1);
  FUN_c08a5da4((int *)&local_d0,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
               *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar31,iVar33);
  local_64 = (iVar16 - iVar13) - iVar31;
  iVar33 = (iVar18 - iVar17) - iVar33;
  uVar19 = 1;
  local_68 = 0;
  local_1b0 = 0;
  iVar31 = local_134;
  puVar8 = local_1a0;
  iVar30 = local_19c;
  iVar13 = local_13c;
  iVar16 = local_cc;
  puVar24 = local_138;
  uVar5 = local_100;
  puVar26 = local_10c;
  puVar27 = local_d0;
  iVar17 = local_d4;
  iVar18 = local_6c;
  local_60 = iVar33;
  if (0 < iVar35) {
    do {
      if (local_14c == 0) {
        puVar11 = (uint *)((int)puVar8 + iVar30);
        iVar21 = iVar13;
        local_1a0 = puVar11;
        local_174 = puVar8;
      }
      else {
        local_13c = iVar13 + iVar30;
        local_148 = local_140;
        puVar11 = puVar8;
        iVar21 = local_13c;
        local_144 = iVar13;
      }
      uVar32 = local_1bc >> 8;
      if (uVar19 == 0) {
        local_68 = local_68 + -1;
        if (local_e4 == 0) {
          puVar24 = (uint *)((int)puVar24 - iVar31);
          puVar27 = (uint *)((int)puVar27 - iVar16);
          local_138 = puVar24;
          local_d0 = puVar27;
        }
        else {
          iVar17 = iVar17 - iVar31;
          iVar18 = iVar18 - iVar16;
          local_d4 = iVar17;
          local_6c = iVar18;
        }
      }
      iVar29 = iVar17;
      iVar34 = iVar18;
      if (puVar24 == (uint *)0x0) {
        puVar25 = puVar24;
        puVar28 = puVar27;
        if (local_fc != 0) {
          iVar29 = iVar17 + iVar31;
          iVar34 = iVar18 + iVar16;
          local_e0 = local_d8;
          local_78 = local_70;
          local_dc = iVar17;
          local_d4 = iVar29;
          local_74 = iVar18;
          local_6c = iVar34;
        }
      }
      else {
        local_138 = (uint *)((int)puVar24 + iVar31);
        local_d0 = (uint *)((int)puVar27 + iVar16);
        puVar25 = local_138;
        puVar26 = puVar24;
        puVar28 = local_d0;
        local_10c = puVar24;
        local_a4 = puVar27;
      }
      bVar2 = local_68 != 0;
      bVar3 = local_68 < iVar33;
      local_68 = local_68 + 1;
      if (puVar25 != (uint *)0x0) {
        if ((local_120 == 0) && (bVar2)) {
          local_108 = *puVar26;
          local_100 = local_12c;
          uVar5 = local_12c;
        }
        if ((local_b8 == 0) && (bVar3)) {
          local_a0 = *local_a4;
          local_98 = local_c4;
        }
      }
      iVar13 = 0;
      iVar17 = 0;
      uVar19 = uVar22 & 0xffff;
      if (0 < local_1c4) {
        do {
          uVar7 = local_9c;
          uVar6 = local_104;
          if (iVar17 < local_64) {
            iVar17 = iVar17 + 1;
            if (bVar2) {
              if (puVar26 == (uint *)0x0) {
                if (local_114 == 8) {
                  pbVar9 = (byte *)FUN_c08a5f10((int)&local_138);
                  local_104 = (uint)*pbVar9;
                }
                else if (local_114 == 0x10) {
                  puVar4 = (ushort *)FUN_c08a5f10((int)&local_138);
                  local_104 = (uint)*puVar4;
                }
                else if (local_114 == 0x18) {
                  pbVar9 = (byte *)FUN_c08a5f10((int)&local_138);
                  local_104 = ((uint)pbVar9[2] * 0x100 + (uint)pbVar9[1]) * 0x100 | (uint)*pbVar9;
                }
                else if (local_114 == 0x20) {
                  puVar8 = (uint *)FUN_c08a5f10((int)&local_138);
                  local_104 = *puVar8;
                }
                local_e0 = local_e0 + local_f8;
              }
              else if (local_120 == 0) {
                if ((uVar5 & 0xff00) == 0) {
                  local_10c = (uint *)(local_118 + (int)puVar26);
                  local_108 = *local_10c;
                  uVar5 = local_130;
                }
                local_104 = local_108 >> ((uVar5 >> 0x10 ^ (uint)local_110) & 0x1f);
                local_100 = local_128 + uVar5;
              }
              else {
                local_10c = (uint *)(local_118 + (int)puVar26);
                local_104 = ((uint)*(byte *)((int)puVar26 + 2) * 0x100 +
                            (uint)*(byte *)((int)puVar26 + 1)) * 0x100 + (uint)(byte)*puVar26;
              }
              local_104 = local_11c & local_104;
              if (*(int *)(param_2 + 0x3c) != 0) {
                local_104 = *(uint *)(local_104 * 4 + *(int *)(param_2 + 0x3c));
              }
              if (*(code **)(param_2 + 0x40) != (code *)0x0) {
                local_104 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),local_104)
                ;
              }
            }
            uVar5 = local_104;
            if (bVar3) {
              if (local_a4 == (uint *)0x0) {
                if (local_ac == 8) {
                  pbVar9 = (byte *)FUN_c08a5f10((int)&local_d0);
                  local_9c = (uint)*pbVar9;
                }
                else if (local_ac == 0x10) {
                  puVar4 = (ushort *)FUN_c08a5f10((int)&local_d0);
                  local_9c = (uint)*puVar4;
                }
                else if (local_ac == 0x18) {
                  pbVar9 = (byte *)FUN_c08a5f10((int)&local_d0);
                  local_9c = ((uint)pbVar9[2] * 0x100 + (uint)pbVar9[1]) * 0x100 | (uint)*pbVar9;
                }
                else if (local_ac == 0x20) {
                  puVar8 = (uint *)FUN_c08a5f10((int)&local_d0);
                  local_9c = *puVar8;
                }
                local_78 = local_78 + local_90;
              }
              else if (local_b8 == 0) {
                if ((local_98 & 0xff00) == 0) {
                  local_a4 = (uint *)(local_b0 + (int)local_a4);
                  local_98 = local_c8;
                  local_a0 = *local_a4;
                }
                uVar5 = local_98 >> 0x10;
                local_98 = local_c0 + local_98;
                local_9c = local_a0 >> ((uVar5 ^ local_a8) & 0x1f);
              }
              else {
                pbVar9 = (byte *)((int)local_a4 + 2);
                pbVar1 = (byte *)((int)local_a4 + 1);
                uVar5 = *local_a4;
                local_a4 = (uint *)(local_b0 + (int)local_a4);
                local_9c = ((uint)*pbVar9 * 0x100 + (uint)*pbVar1) * 0x100 + (uint)(byte)uVar5;
              }
              local_9c = local_b4 & local_9c;
              if (*(int *)(param_2 + 0x3c) != 0) {
                local_9c = *(uint *)(local_9c * 4 + *(int *)(param_2 + 0x3c));
              }
              uVar5 = local_9c;
              if (*(code **)(param_2 + 0x40) != (code *)0x0) {
                uVar5 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),local_9c);
              }
            }
            local_9c = uVar5;
            if (!bVar2) {
              local_104 = local_9c;
            }
          }
          if (iVar17 == 1) {
            uVar7 = local_9c;
            uVar6 = local_104;
          }
          if (uVar6 != uVar7) {
            uVar6 = FUN_c08a5708(uVar6,uVar7,0x100 - uVar32,uVar32,auStack_48,auStack_38);
          }
          uVar7 = local_104;
          if (local_104 != local_9c) {
            uVar7 = FUN_c08a5708(local_104,local_9c,0x100 - uVar32,uVar32,auStack_48,auStack_38);
          }
          do {
            iVar31 = local_134;
            puVar11 = local_1a0;
            iVar30 = local_19c;
            iVar21 = local_13c;
            iVar16 = local_cc;
            puVar25 = local_138;
            uVar5 = local_100;
            puVar26 = local_10c;
            puVar28 = local_d0;
            iVar33 = local_60;
            iVar29 = local_d4;
            iVar34 = local_6c;
            if (local_1c4 <= iVar13) goto LAB_c089adfc;
            iVar13 = iVar13 + 1;
            uVar5 = uVar6;
            if (uVar6 != uVar7) {
              uVar5 = FUN_c08a5708(uVar6,uVar7,0x100 - (uVar19 >> 8),uVar19 >> 8,auStack_48,
                                   auStack_38);
            }
            uVar14 = uVar19 + iVar36;
            uVar19 = uVar14 & 0xffff;
            if (local_5c != 0) {
              if (local_14c == 0) {
                if (local_17c == 0x10) {
                  local_16c = CONCAT22(local_16c._2_2_,(short)*local_174);
                }
                else if (local_17c == 0x18) {
                  local_16c = ((uint)*(byte *)((int)local_174 + 2) * 0x100 +
                              (uint)*(byte *)((int)local_174 + 1)) * 0x100 + (uint)(byte)*local_174;
                }
                else if (local_17c == 0x20) {
                  local_16c = *local_174;
                }
              }
              else if (local_17c == 0x10) {
                puVar10 = (undefined2 *)FUN_c08a5f10((int)&local_1a0);
                local_16c = CONCAT22(local_16c._2_2_,*puVar10);
              }
              else if (local_17c == 0x18) {
                pbVar9 = (byte *)FUN_c08a5f10((int)&local_1a0);
                local_16c = ((uint)pbVar9[2] * 0x100 + (uint)pbVar9[1]) * 0x100 + (uint)*pbVar9;
              }
              else if (local_17c == 0x20) {
                puVar8 = (uint *)FUN_c08a5f10((int)&local_1a0);
                local_16c = *puVar8;
              }
            }
            if ((char)uVar23 == -0x78) {
              uVar5 = local_16c & uVar5;
            }
            else if ((char)uVar23 == -0x12) {
              uVar5 = local_16c | uVar5;
            }
            uVar5 = uVar5 & local_184;
            bVar12 = (byte)(uVar5 >> 8);
            bVar15 = (byte)(uVar5 >> 0x10);
            if (local_14c == 0) {
              if (local_17c == 0x10) {
                *(short *)local_174 = (short)uVar5;
              }
              else if (local_17c == 0x18) {
                *(byte *)local_174 = (byte)uVar5;
                *(byte *)((int)local_174 + 1) = bVar12;
                *(byte *)((int)local_174 + 2) = bVar15;
              }
              else if (local_17c == 0x20) {
                *local_174 = uVar5;
              }
              local_174 = (uint *)((int)local_174 + local_180);
            }
            else {
              if (local_17c == 0x10) {
                puVar10 = (undefined2 *)FUN_c08a5f10((int)&local_1a0);
                *puVar10 = (short)uVar5;
              }
              else if (local_17c == 0x18) {
                pbVar9 = (byte *)FUN_c08a5f10((int)&local_1a0);
                *pbVar9 = (byte)uVar5;
                pbVar9[1] = bVar12;
                pbVar9[2] = bVar15;
              }
              else if (local_17c == 0x20) {
                puVar8 = (uint *)FUN_c08a5f10((int)&local_1a0);
                *puVar8 = uVar5;
              }
              local_148 = local_148 + local_160;
            }
          } while ((uVar14 & 0xffff0000) == 0);
          iVar31 = local_134;
          puVar11 = local_1a0;
          iVar30 = local_19c;
          iVar21 = local_13c;
          iVar16 = local_cc;
          puVar25 = local_138;
          uVar5 = local_100;
          puVar26 = local_10c;
          puVar28 = local_d0;
          iVar33 = local_60;
          iVar29 = local_d4;
          iVar34 = local_6c;
        } while (iVar13 < local_1c4);
      }
LAB_c089adfc:
      uVar19 = local_1bc + iVar37 & 0xffff0000;
      local_1bc = local_1bc + iVar37 & 0xffff;
      local_1b0 = local_1b0 + 1;
      puVar8 = puVar11;
      iVar13 = iVar21;
      puVar24 = puVar25;
      puVar27 = puVar28;
      iVar17 = iVar29;
      iVar18 = iVar34;
    } while (local_1b0 < iVar35);
  }
  return 0;
}



/* c089ae68 FUN_c089ae68 */

/* Boundary evidence: original MIPS .pdata c089ae68..c089bb93. Semantic name remains unreviewed. */

undefined4 FUN_c089ae68(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  byte *pbVar6;
  ushort *puVar7;
  void *pvVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  uint *_Dst;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint *local_190;
  int local_18c;
  uint local_188;
  uint local_184;
  int local_180;
  int local_178;
  int local_170;
  int local_16c;
  byte local_168;
  uint *local_164;
  uint local_160;
  uint local_15c;
  uint local_158;
  int local_150;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  uint *local_128;
  int local_124;
  int local_120;
  uint local_11c;
  uint *local_118;
  uint local_114;
  uint local_110;
  int local_10c;
  uint local_108;
  int local_104;
  int local_100;
  uint local_fc;
  int local_f8;
  int local_f4;
  uint local_f0;
  uint local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  uint *local_d8;
  uint local_d4;
  uint *local_d0;
  uint *local_cc;
  int local_c8;
  int local_c4;
  uint auStack_c0 [4];
  uint auStack_b0 [4];
  void *local_a0;
  int local_9c;
  uint local_84;
  int local_80;
  int local_7c;
  void *local_74;
  undefined4 local_68;
  int local_60;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  piVar10 = *(int **)(param_2 + 0x14);
  iVar13 = 0;
  piVar12 = *(int **)(param_2 + 0x18);
  iVar15 = piVar10[2] - *piVar10;
  iVar16 = piVar10[3] - piVar10[1];
  iVar11 = (piVar12[2] - *piVar12) * 0x10000;
  uVar17 = iVar11 / iVar15;
  iVar14 = 0;
  if (iVar15 == 0) {
    trap(0x1c00);
  }
  if ((iVar15 == -1) && (iVar11 == -0x80000000)) {
    trap(0x1800);
  }
  iVar11 = (piVar12[3] - piVar12[1]) * 0x10000;
  uVar18 = iVar11 / iVar16;
  if (iVar16 == 0) {
    trap(0x1c00);
  }
  if ((iVar16 == -1) && (iVar11 == -0x80000000)) {
    trap(0x1800);
  }
  local_114 = uVar18;
  local_110 = uVar17;
  local_f8 = iVar16;
  local_f4 = iVar15;
  FUN_c08a55f0(*(int *)(param_2 + 4),(int)auStack_b0,(int *)auStack_c0);
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar15 = FUN_c08a5678(&local_38,*(int **)(param_2 + 0x1c),*(int **)(param_2 + 0x14));
    if (iVar15 != 0) {
      return 0;
    }
    piVar10 = *(int **)(param_2 + 0x14);
    if (*(int *)(param_2 + 0x34) == 0) {
      iVar13 = piVar10[2] - local_30;
    }
    else {
      iVar13 = local_38 - *piVar10;
    }
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar14 = piVar10[3] - local_2c;
    }
    else {
      iVar14 = local_34 - piVar10[1];
    }
    iVar15 = local_30 - local_38;
    iVar16 = local_2c - local_34;
    local_f8 = iVar16;
    local_f4 = iVar15;
  }
  uVar9 = 0;
  if (iVar13 != 0) {
    uVar9 = uVar17 * iVar13;
  }
  local_ec = uVar9 & 0xffff;
  uVar17 = 0;
  if (iVar14 != 0) {
    uVar17 = uVar18 * iVar14;
  }
  local_108 = uVar17 & 0xffff;
  iVar11 = *(int *)(param_2 + 4);
  local_7c = *(int *)(&LAB_c0891154 + *(int *)(iVar11 + 0x1c) * 4);
  if (*(int *)(iVar11 + 0x38) == 0) {
    piVar10 = *(int **)(param_2 + 0x14);
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar11 = *(int *)(param_2 + 4);
      local_9c = -*(int *)(iVar11 + 8);
      iVar11 = ((piVar10[3] - iVar14) + -1) * *(int *)(iVar11 + 8) + *(int *)(iVar11 + 4);
    }
    else {
      local_9c = *(int *)(iVar11 + 8);
      iVar11 = (piVar10[1] + iVar14) * *(int *)(iVar11 + 8) + *(int *)(iVar11 + 4);
    }
    local_80 = local_7c >> 3;
    if (*(int *)(param_2 + 0x34) == 0) {
      if (local_7c < 0) {
        local_80 = local_7c + 7 >> 3;
      }
      local_80 = -local_80;
      iVar13 = -(((piVar10[2] - iVar13) + -1) * local_80);
    }
    else {
      if (local_7c < 0) {
        local_80 = local_7c + 7 >> 3;
      }
      iVar13 = (iVar13 + *piVar10) * local_80;
    }
    local_a0 = (void *)(iVar13 + iVar11);
    local_84 = (2 << (local_7c - 1U & 0x1f)) - 1;
    local_4c = 0;
    local_68 = 0;
  }
  else {
    FUN_c08a5da4((int *)&local_a0,*(int *)(param_2 + 4),*(int *)(param_2 + 0x34),
                 *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x14),iVar13,iVar14);
  }
  FUN_c08a5da4((int *)&local_190,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
               *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),uVar9 >> 0x10,uVar17 >> 0x10);
  if (local_13c == 0) {
    local_164 = local_190;
  }
  else {
    local_138 = local_130;
    local_134 = local_12c;
  }
  iVar11 = local_7c;
  if (local_7c < 0) {
    iVar11 = local_7c + 7;
  }
  uVar17 = (iVar11 >> 3) * iVar15;
  local_d4 = uVar17;
  puVar5 = operator_new(uVar17);
  if (puVar5 != (uint *)0x0) {
    local_100 = 0;
    uVar18 = 0;
    _Dst = puVar5;
    local_118 = puVar5;
    if (0 < iVar16) {
      do {
        iVar11 = local_100;
        memset(_Dst,0,uVar17);
        if (0 < (int)uVar18) {
          iVar13 = (uVar18 - 1 >> 0x10) + 1;
          if (local_13c == 0) {
            do {
              local_190 = (uint *)(local_18c + (int)local_190);
              iVar13 = iVar13 + -1;
              local_164 = local_190;
            } while (iVar13 != 0);
          }
          else {
            do {
              local_134 = local_12c + local_18c;
              iVar13 = iVar13 + -1;
              local_138 = local_130;
              local_12c = local_134;
            } while (iVar13 != 0);
          }
        }
        if ((local_190 != (uint *)0x0) && (local_178 == 0)) {
          local_160 = *local_164;
          local_158 = local_184;
        }
        local_c4 = local_138;
        local_e8 = local_134;
        local_e4 = local_130;
        local_dc = local_12c;
        local_d8 = local_190;
        local_10c = 0;
        puVar5 = local_164;
        local_cc = local_164;
        if (local_114 >> 0x10 != 0) {
          do {
            iVar11 = local_10c;
            local_120 = 0x100;
            local_124 = 0;
            if (0 < local_10c) {
              local_120 = 0x80;
              local_124 = 0x80;
            }
            uVar17 = 0;
            local_fc = local_ec;
            local_128 = _Dst;
            if (puVar5 == (uint *)0x0) {
              if (local_16c == 8) {
                pbVar6 = (byte *)FUN_c08a5f10((int)&local_190);
                local_15c = (uint)*pbVar6;
                puVar5 = local_164;
              }
              else if (local_16c == 0x10) {
                puVar7 = (ushort *)FUN_c08a5f10((int)&local_190);
                local_15c = (uint)*puVar7;
                puVar5 = local_164;
              }
              else if (local_16c == 0x18) {
                pbVar6 = (byte *)FUN_c08a5f10((int)&local_190);
                local_15c = ((uint)pbVar6[2] * 0x100 + (uint)pbVar6[1]) * 0x100 | (uint)*pbVar6;
                puVar5 = local_164;
              }
              else if (local_16c == 0x20) {
                puVar5 = (uint *)FUN_c08a5f10((int)&local_190);
                local_15c = *puVar5;
                puVar5 = local_164;
              }
              local_138 = local_138 + local_150;
            }
            else if (local_178 == 0) {
              if ((local_158 & 0xff00) == 0) {
                local_158 = local_188;
                local_160 = *puVar5;
              }
              local_15c = local_160 >> ((local_158 >> 0x10 ^ (uint)local_168) & 0x1f);
              local_158 = local_180 + local_158;
            }
            else {
              local_15c = ((uint)*(byte *)((int)puVar5 + 2) * 0x100 +
                          (uint)*(byte *)((int)puVar5 + 1)) * 0x100 + (uint)(byte)*puVar5;
            }
            if (*(int *)(param_2 + 0x3c) != 0) {
              local_15c = *(uint *)(local_15c * 4 + *(int *)(param_2 + 0x3c));
            }
            if (*(code **)(param_2 + 0x40) != (code *)0x0) {
              local_15c = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),local_15c);
              puVar5 = local_164;
            }
            uVar18 = local_15c & local_84;
            if (0 < iVar15) {
              uVar9 = local_110 >> 0x10;
              local_104 = iVar15;
              local_f0 = uVar9;
              do {
                local_15c = uVar18;
                if (0 < (int)uVar17) {
                  iVar15 = (uVar17 - 1 >> 0x10) + 1;
                  do {
                    if (puVar5 == (uint *)0x0) {
                      if (local_16c == 8) {
                        pbVar6 = (byte *)FUN_c08a5f10((int)&local_190);
                        local_15c = (uint)*pbVar6;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x10) {
                        puVar7 = (ushort *)FUN_c08a5f10((int)&local_190);
                        local_15c = (uint)*puVar7;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x18) {
                        pbVar6 = (byte *)FUN_c08a5f10((int)&local_190);
                        local_15c = ((uint)pbVar6[2] * 0x100 + (uint)pbVar6[1]) * 0x100 |
                                    (uint)*pbVar6;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x20) {
                        puVar5 = (uint *)FUN_c08a5f10((int)&local_190);
                        local_15c = *puVar5;
                        puVar5 = local_164;
                      }
                      local_138 = local_138 + local_150;
                    }
                    else if (local_178 == 0) {
                      if ((local_158 & 0xff00) == 0) {
                        puVar5 = (uint *)(local_170 + (int)puVar5);
                        local_158 = local_188;
                        local_160 = *puVar5;
                        local_164 = puVar5;
                      }
                      local_15c = local_160 >> ((local_158 >> 0x10 ^ (uint)local_168) & 0x1f);
                      local_158 = local_180 + local_158;
                    }
                    else {
                      puVar5 = (uint *)(local_170 + (int)puVar5);
                      local_15c = ((uint)*(byte *)((int)puVar5 + 2) * 0x100 +
                                  (uint)*(byte *)((int)puVar5 + 1)) * 0x100 + (uint)(byte)*puVar5;
                      local_164 = puVar5;
                    }
                    if (*(int *)(param_2 + 0x3c) != 0) {
                      local_15c = *(uint *)(local_15c * 4 + *(int *)(param_2 + 0x3c));
                    }
                    if (*(code **)(param_2 + 0x40) != (code *)0x0) {
                      local_15c = (**(code **)(param_2 + 0x40))
                                            (*(undefined4 *)(param_2 + 0x44),local_15c);
                      puVar5 = local_164;
                    }
                    local_15c = local_15c & local_84;
                    iVar15 = iVar15 + -1;
                    uVar9 = local_f0;
                  } while (iVar15 != 0);
                }
                uVar2 = local_158;
                uVar18 = local_15c;
                uVar1 = local_160;
                local_c8 = local_138;
                local_e0 = local_134;
                local_11c = local_15c;
                local_d0 = puVar5;
                if (1 < (int)uVar9) {
                  iVar15 = uVar9 - 1;
                  do {
                    if (puVar5 == (uint *)0x0) {
                      if (local_16c == 8) {
                        pbVar6 = (byte *)FUN_c08a5f10((int)&local_190);
                        local_15c = (uint)*pbVar6;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x10) {
                        puVar7 = (ushort *)FUN_c08a5f10((int)&local_190);
                        local_15c = (uint)*puVar7;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x18) {
                        pbVar6 = (byte *)FUN_c08a5f10((int)&local_190);
                        local_15c = ((uint)pbVar6[2] * 0x100 + (uint)pbVar6[1]) * 0x100 |
                                    (uint)*pbVar6;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x20) {
                        puVar5 = (uint *)FUN_c08a5f10((int)&local_190);
                        local_15c = *puVar5;
                        puVar5 = local_164;
                      }
                      local_138 = local_138 + local_150;
                    }
                    else if (local_178 == 0) {
                      if ((local_158 & 0xff00) == 0) {
                        puVar5 = (uint *)(local_170 + (int)puVar5);
                        local_158 = local_188;
                        local_160 = *puVar5;
                        local_164 = puVar5;
                      }
                      local_15c = local_160 >> ((local_158 >> 0x10 ^ (uint)local_168) & 0x1f);
                      local_158 = local_180 + local_158;
                    }
                    else {
                      puVar5 = (uint *)(local_170 + (int)puVar5);
                      local_15c = ((uint)*(byte *)((int)puVar5 + 2) * 0x100 +
                                  (uint)*(byte *)((int)puVar5 + 1)) * 0x100 + (uint)(byte)*puVar5;
                      local_164 = puVar5;
                    }
                    if (*(int *)(param_2 + 0x3c) != 0) {
                      local_15c = *(uint *)(local_15c * 4 + *(int *)(param_2 + 0x3c));
                    }
                    if (*(code **)(param_2 + 0x40) != (code *)0x0) {
                      local_15c = (**(code **)(param_2 + 0x40))
                                            (*(undefined4 *)(param_2 + 0x44),local_15c);
                      puVar5 = local_164;
                    }
                    local_15c = local_15c & local_84;
                    if (local_7c == 0x10) {
                      FUN_c08a5a90((ushort *)&local_11c,local_15c,0x80,0x80,auStack_b0,auStack_c0);
                      puVar5 = local_164;
                    }
                    else if (local_7c == 0x18) {
                      FUN_c08a5ad0((byte *)&local_11c,local_15c,0x80,0x80,auStack_b0,auStack_c0);
                      puVar5 = local_164;
                    }
                    else if (local_7c == 0x20) {
                      FUN_c08a5b34(&local_11c,local_15c,0x80,0x80,auStack_b0,auStack_c0);
                      puVar5 = local_164;
                    }
                    iVar15 = iVar15 + -1;
                    uVar9 = local_f0;
                  } while (iVar15 != 0);
                }
                iVar11 = local_c8;
                puVar5 = local_d0;
                iVar15 = local_e0;
                if (local_7c == 0x10) {
                  FUN_c08a5a90((ushort *)local_128,local_11c,local_124,local_120,auStack_b0,
                               auStack_c0);
                }
                else if (local_7c == 0x18) {
                  FUN_c08a5ad0((byte *)local_128,local_11c,local_124,local_120,auStack_b0,auStack_c0
                              );
                }
                else if (local_7c == 0x20) {
                  FUN_c08a5b34(local_128,local_11c,local_124,local_120,auStack_b0,auStack_c0);
                }
                local_128 = (uint *)((int)local_128 + local_80);
                uVar17 = local_fc + local_110 & 0xffff0000;
                local_fc = local_fc + local_110 & 0xffff;
                local_104 = local_104 + -1;
                local_164 = puVar5;
                local_160 = uVar1;
                local_158 = uVar2;
                local_138 = iVar11;
                local_134 = iVar15;
              } while (local_104 != 0);
              local_104 = 0;
              _Dst = local_118;
              iVar11 = local_10c;
              iVar15 = local_f4;
            }
            if (local_190 == (uint *)0x0) {
              local_134 = local_12c + local_18c;
              local_138 = local_130;
              local_12c = local_134;
            }
            else {
              puVar5 = (uint *)(local_18c + (int)local_190);
              local_190 = puVar5;
              local_164 = puVar5;
              if (local_178 == 0) {
                local_160 = *puVar5;
                local_158 = local_184;
              }
            }
            local_10c = iVar11 + 1;
            uVar17 = local_d4;
            iVar11 = local_100;
            local_15c = uVar18;
          } while (local_10c < (int)(local_114 >> 0x10));
        }
        pvVar8 = local_a0;
        puVar4 = local_cc;
        puVar3 = local_d8;
        if (local_4c == 0) {
          local_74 = local_a0;
          local_a0 = (void *)((int)local_a0 + local_9c);
          memcpy(pvVar8,_Dst,uVar17);
          puVar5 = _Dst;
        }
        else {
          local_44 = local_3c;
          local_3c = local_3c + local_9c;
          local_48 = local_40;
          iVar13 = local_7c;
          if (local_7c < 0) {
            iVar13 = local_7c + 7;
          }
          iVar14 = iVar15;
          puVar5 = local_118;
          if (0 < iVar15) {
            do {
              pvVar8 = (void *)FUN_c08a5f10((int)&local_a0);
              memcpy(pvVar8,_Dst,iVar13 >> 3);
              _Dst = (uint *)((iVar13 >> 3) + (int)_Dst);
              iVar14 = iVar14 + -1;
              local_48 = local_48 + local_60;
              puVar5 = local_118;
            } while (iVar14 != 0);
          }
        }
        local_138 = local_c4;
        local_134 = local_e8;
        uVar18 = local_108 + local_114 & 0xffff0000;
        local_108 = local_108 + local_114 & 0xffff;
        local_130 = local_e4;
        local_12c = local_dc;
        local_100 = iVar11 + 1;
        _Dst = puVar5;
        local_190 = puVar3;
        local_164 = puVar4;
      } while (local_100 < local_f8);
    }
    operator_delete(puVar5);
    return 0;
  }
  return 0x80004005;
}



/* c089bb94 FUN_c089bb94 */

/* Boundary evidence: original MIPS .pdata c089bb94..c089bfbf. Semantic name remains unreviewed. */

void FUN_c089bb94(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *param_2;
  iVar4 = 0;
  if (param_3 != iVar1) {
    iVar4 = iVar1;
  }
  if ((*(int *)(param_2[1] + 0x38) == 0) &&
     ((param_2[2] == 0 || (*(int *)(param_2[2] + 0x38) == 0)))) {
    *param_2 = (int)FUN_c0895378;
    if (param_2[10] == 0xaaf0) {
      FUN_c08a0af8(param_2);
      FUN_c089f138(param_2);
    }
    if ((code *)*param_2 == FUN_c0895378) {
      FUN_c08a914c(param_2);
      FUN_c08917b8();
      FUN_c08a6334(param_2);
      FUN_c08a6590(param_2);
    }
    piVar3 = (int *)param_2[5];
    iVar6 = piVar3[2] - *piVar3;
    iVar5 = piVar3[3] - piVar3[1];
    if (((param_2[9] == 8) && (param_2[0xd] != 0)) &&
       (((param_2[0xe] != 0 && ((3 < *(int *)(param_2[1] + 0x1c) && (0 < iVar6)))) && (0 < iVar5))))
    {
      if (((param_2[0x12] == 5) &&
          (((iVar2 = param_2[10], iVar2 == 0xcccc || (iVar2 == 0xeeee)) || (iVar2 == 0x8888)))) &&
         ((piVar3 = (int *)param_2[6], piVar3[2] - *piVar3 <= iVar6 &&
          (piVar3[3] - piVar3[1] <= iVar5)))) {
        *param_2 = (int)FUN_c0897028;
      }
      else if ((param_2[0x12] == 4) &&
              (((param_2[10] == 0xcccc && (piVar3 = (int *)param_2[6], iVar6 <= piVar3[2] - *piVar3)
                ) && (iVar5 <= piVar3[3] - piVar3[1])))) {
        *param_2 = (int)FUN_c0897904;
      }
    }
    if ((code *)*param_2 == FUN_c0895378) {
      FUN_c08a62c0(param_2);
    }
  }
  else {
    *param_2 = (int)FUN_c0898210;
    if (param_2[10] == 0xaaf0) {
      FUN_c08a0af8(param_2);
      FUN_c089f138(param_2);
    }
    if ((code *)*param_2 == FUN_c0898210) {
      FUN_c08917b8();
      FUN_c08a6334(param_2);
      FUN_c08a6590(param_2);
    }
    piVar3 = (int *)param_2[5];
    iVar6 = piVar3[2] - *piVar3;
    iVar5 = piVar3[3] - piVar3[1];
    if (((((param_2[9] == 8) && (param_2[0xd] != 0)) && (param_2[0xe] != 0)) &&
        ((3 < *(int *)(param_2[1] + 0x1c) && (0 < iVar6)))) && (0 < iVar5)) {
      if ((param_2[0x12] == 5) &&
         ((((iVar2 = param_2[10], iVar2 == 0xcccc || (iVar2 == 0xeeee)) || (iVar2 == 0x8888)) &&
          ((piVar3 = (int *)param_2[6], piVar3[2] - *piVar3 <= iVar6 &&
           (piVar3[3] - piVar3[1] <= iVar5)))))) {
        *param_2 = (int)FUN_c089a208;
      }
      else if ((param_2[0x12] == 4) &&
              (((param_2[10] == 0xcccc && (piVar3 = (int *)param_2[6], iVar6 <= piVar3[2] - *piVar3)
                ) && (iVar5 <= piVar3[3] - piVar3[1])))) {
        *param_2 = (int)FUN_c089ae68;
      }
    }
  }
  if (((*(int *)(param_2[1] + 0x20) != 0) ||
      ((param_2[2] != 0 && (*(int *)(param_2[2] + 0x20) != 0)))) ||
     (((param_2[3] != 0 && (*(int *)(param_2[3] + 0x20) != 0)) ||
      ((param_2[4] != 0 && (*(int *)(param_2[4] + 0x20) != 0)))))) {
    (**(code **)(*param_1 + 0x60))(param_1);
  }
  (*(code *)*param_2)(param_1,param_2);
  if (param_3 != iVar1) {
    *param_2 = iVar4;
  }
  return;
}



/* c089bfc0 FUN_c089bfc0 */

/* Boundary evidence: original MIPS .pdata c089bfc0..c089bfdf. Semantic name remains unreviewed. */

void FUN_c089bfc0(int *param_1,int *param_2)

{
  FUN_c089bb94(param_1,param_2,-0x3f764040);
  return;
}



/* c089bfe0 FUN_c089bfe0 */

/* Boundary evidence: original MIPS .pdata c089bfe0..c089c03b. Semantic name remains unreviewed. */

void FUN_c089bfe0(int param_1,int param_2,int param_3,undefined *param_4)

{
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*(code *)param_4)(param_1);
    param_1 = param_1 + param_2;
  }
  return;
}



/* c089c03c FUN_c089c03c */

/* Boundary evidence: original MIPS .pdata c089c03c..c089c12f. Semantic name remains unreviewed. */

undefined4 FUN_c089c03c(int *param_1,int param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  pvVar1 = malloc(param_2 << 2);
  *param_1 = (int)pvVar1;
  pvVar1 = malloc(param_2 << 1);
  param_1[1] = (int)pvVar1;
  pvVar1 = malloc(param_2 << 1);
  param_1[2] = (int)pvVar1;
  if (((*param_1 == 0) || (param_1[1] == 0)) || (pvVar1 == (void *)0x0)) {
    uVar2 = 0;
  }
  else {
    *(short *)(param_1 + 4) = (short)param_2;
    if (param_2 != 0) {
      iVar5 = 0;
      iVar6 = 0;
      uVar3 = 0;
      do {
        *(undefined4 *)(iVar6 + *param_1) = 0;
        uVar4 = uVar3 + 1;
        *(short *)(iVar5 + param_1[1]) = (short)uVar3 + -1;
        *(short *)(param_1[2] + iVar5) = (short)uVar4;
        iVar6 = iVar6 + 4;
        iVar5 = iVar5 + 2;
        uVar3 = uVar4;
      } while (uVar4 < *(ushort *)(param_1 + 4));
    }
    *(undefined2 *)((int)param_1 + 0xe) = 0;
    uVar2 = 1;
    *(short *)(param_1 + 3) = (short)param_1[4] + -1;
  }
  return uVar2;
}



/* c089c130 FUN_c089c130 */

int FUN_c089c130(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(short *)(param_1 + 4) != 0) {
    piVar1 = (int *)*param_1;
    do {
      if (*piVar1 == param_2) {
        sVar3 = (short)uVar4;
        if (uVar4 == (int)*(short *)(param_1 + 3)) {
          *(undefined2 *)(param_1 + 3) = *(undefined2 *)(param_1[1] + uVar4 * 2);
          *(short *)(*(short *)((int)param_1 + 0xe) * 2 + param_1[1]) = sVar3;
          *(undefined2 *)(param_1[2] + uVar4 * 2) = *(undefined2 *)((int)param_1 + 0xe);
        }
        else {
          if (uVar4 == (int)*(short *)((int)param_1 + 0xe)) goto LAB_c089c230;
          iVar2 = uVar4 * 2;
          *(undefined2 *)(*(short *)(param_1[2] + iVar2) * 2 + param_1[1]) =
               *(undefined2 *)(param_1[1] + iVar2);
          *(undefined2 *)(*(short *)(param_1[1] + iVar2) * 2 + param_1[2]) =
               *(undefined2 *)(param_1[2] + iVar2);
          *(short *)(*(short *)((int)param_1 + 0xe) * 2 + param_1[1]) = sVar3;
          *(undefined2 *)(param_1[2] + iVar2) = *(undefined2 *)((int)param_1 + 0xe);
        }
        *(short *)((int)param_1 + 0xe) = sVar3;
LAB_c089c230:
        return (int)sVar3;
      }
      uVar4 = uVar4 + 1;
      piVar1 = piVar1 + 1;
    } while (uVar4 < *(ushort *)(param_1 + 4));
  }
  return -1;
}



/* c089c23c FUN_c089c23c */

/* Boundary evidence: original MIPS .pdata c089c23c..c089c2a3. Semantic name remains unreviewed. */

void FUN_c089c23c(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  if ((void *)param_1[2] != (void *)0x0) {
    free((void *)param_1[2]);
    param_1[2] = 0;
  }
  return;
}



/* c089c2a4 FUN_c089c2a4 */

/* Boundary evidence: original MIPS .pdata c089c2a4..c089c393. Semantic name remains unreviewed. */

void FUN_c089c2a4(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  
  *(short *)(param_1 + 0x12) = (short)param_4;
  if (param_4 == 2) {
    (*DAT_c08bc87c)(param_2,param_3,3,param_1);
    uVar4 = 0;
    do {
      puVar3 = (uint *)(uVar4 * 4 + param_1);
      uVar1 = *puVar3;
      if (uVar1 == 0) {
        *(undefined1 *)(uVar4 + param_1 + 0xc) = 0;
        *(undefined1 *)(uVar4 + param_1 + 0xf) = 0;
      }
      else {
        cVar2 = '\0';
        do {
          uVar1 = uVar1 >> 1;
          cVar2 = cVar2 + '\x01';
        } while (uVar1 != 0);
        *(char *)(uVar4 + param_1 + 0xc) = ' ' - cVar2;
        for (uVar1 = *puVar3; (uVar1 & 1) == 0; uVar1 = uVar1 >> 1) {
        }
        cVar2 = '\0';
        for (; uVar1 != 0; uVar1 = uVar1 >> 1) {
          cVar2 = cVar2 + '\x01';
        }
        *(char *)(uVar4 + param_1 + 0xf) = cVar2;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
  }
  return;
}



/* c089c394 FUN_c089c394 */

/* Boundary evidence: original MIPS .pdata c089c394..c089c3e7. Semantic name remains unreviewed. */

void FUN_c089c394(int param_1,int param_2)

{
  FUN_c089c2a4(param_1,param_2,1,(uint)*(ushort *)(param_2 + 8));
  FUN_c089c2a4(param_1 + 0x14,param_2,2,(uint)*(ushort *)(param_2 + 10));
  return;
}



/* c089c3e8 FUN_c089c3e8 */

/* Boundary evidence: original MIPS .pdata c089c3e8..c089c677. Semantic name remains unreviewed. */

void FUN_c089c3e8(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined2 *puVar6;
  short sVar7;
  uint uVar8;
  
  FUN_c089c2a4(param_1 + 0x6cc,param_2,1,(uint)*(ushort *)(param_2 + 8));
  uVar1 = (*DAT_c08bc87c)(param_2,2,0,0);
  *(ushort *)(param_1 + 0x6c8) = uVar1;
  if (0x100 < uVar1) {
    *(undefined2 *)(param_1 + 0x6c8) = 0x100;
  }
  (*DAT_c08bc87c)(param_2,2,*(undefined2 *)(param_1 + 0x6c8),param_1 + 0x2c8);
  *(undefined2 *)(param_1 + 0x2c4) = 0;
  iVar3 = 0;
  *(undefined2 *)(param_1 + 0x2c2) = 0x100;
  do {
    iVar2 = iVar3 + 0x12a;
    iVar3 = (iVar3 + 1) * 0x10000 >> 0x10;
    *(undefined2 *)(iVar2 * 2 + param_1) = 0xffff;
  } while (iVar3 < 0x37);
  if (*(short *)(param_1 + 0x6c8) != 0) {
    iVar3 = 0;
    do {
      uVar8 = *(uint *)((iVar3 + 0xb2) * 4 + param_1);
      uVar8 = (uVar8 >> 0xb & 0x1f) + (uVar8 >> 0x15 & 7) + (uVar8 >> 4 & 0xf);
      puVar6 = (undefined2 *)((uVar8 + 0x12a) * 2 + param_1);
      *(undefined2 *)((iVar3 + 0x2a) * 2 + param_1) = *puVar6;
      *puVar6 = (short)iVar3;
      if (*(ushort *)(param_1 + 0x2c4) < uVar8) {
        *(short *)(param_1 + 0x2c4) = (short)uVar8;
      }
      if (uVar8 < *(ushort *)(param_1 + 0x2c2)) {
        *(short *)(param_1 + 0x2c2) = (short)uVar8;
      }
      iVar3 = (iVar3 + 1) * 0x10000 >> 0x10;
    } while (iVar3 < (int)(uint)*(ushort *)(param_1 + 0x6c8));
  }
  uVar8 = *(ushort *)(param_1 + 0x2c4) + 1;
  sVar7 = *(short *)((*(ushort *)(param_1 + 0x2c4) + 0x12a) * 2 + param_1);
  *(short *)(param_1 + 0x2c4) = (short)uVar8;
  *(undefined2 *)(((uVar8 & 0xffff) + 0x12a) * 2 + param_1) = 0xffff;
  iVar3 = (int)((*(ushort *)(param_1 + 0x2c4) - 2) * 0x10000) >> 0x10;
  if ((int)(uint)*(ushort *)(param_1 + 0x2c2) <= iVar3) {
    do {
      psVar5 = (short *)((iVar3 + 0x12a) * 2 + param_1);
      iVar2 = (int)*psVar5;
      if (iVar2 == -1) {
        *psVar5 = sVar7;
      }
      else {
        while (psVar4 = (short *)((iVar2 + 0x2a) * 2 + param_1), *psVar4 != -1) {
          iVar2 = (int)*psVar4;
        }
        *(short *)((iVar2 + 0x2a) * 2 + param_1) = sVar7;
        sVar7 = *psVar5;
      }
      iVar3 = (iVar3 + -1) * 0x10000 >> 0x10;
    } while ((int)(uint)*(ushort *)(param_1 + 0x2c2) <= iVar3);
  }
  uVar8 = 0;
  if (*(short *)(param_1 + 0x50) != 0) {
    iVar3 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x40) + iVar3) = 0xffffffff;
      uVar8 = uVar8 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar8 < *(ushort *)(param_1 + 0x50));
  }
  return;
}



/* c089c678 FUN_c089c678 */

/* Boundary evidence: original MIPS .pdata c089c678..c089c69f. Semantic name remains unreviewed. */

undefined3 FUN_c089c678(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_res4;
  undefined1 uStackX_6;
  undefined4 local_8;
  
  uStackX_6 = (undefined1)((uint)param_2 >> 0x10);
  local_res4 = (undefined1)param_2;
  local_8 = CONCAT31((int3)((uint)param_2 >> 8),uStackX_6);
  local_8._0_3_ = CONCAT12(local_res4,(undefined2)local_8);
  return (undefined3)local_8;
}



/* c089c724 FUN_c089c724 */

uint FUN_c089c724(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (*(uint *)(param_1 + 0x6cc) & param_2) << (*(byte *)(param_1 + 0x6d8) & 0x1f);
  uVar1 = (*(uint *)(param_1 + 0x6d0) & param_2) << (*(byte *)(param_1 + 0x6d9) & 0x1f);
  uVar2 = (*(uint *)(param_1 + 0x6d4) & param_2) << (*(byte *)(param_1 + 0x6da) & 0x1f);
  return (((uVar1 >> (*(byte *)(param_1 + 0x6dc) & 0x1f) | uVar1) & 0xff000000 |
          (uVar3 >> (*(byte *)(param_1 + 0x6db) & 0x1f) | uVar3) >> 8) >> 8 |
         (uVar2 >> (*(byte *)(param_1 + 0x6dd) & 0x1f) | uVar2) & 0xff000000) >> 8;
}



/* c089c964 FUN_c089c964 */

/* Boundary evidence: original MIPS .pdata c089c964..c089cb27. Semantic name remains unreviewed. */

uint FUN_c089c964(int param_1,uint param_2,uint *param_3,uint param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 local_resc;
  undefined1 uStackX_e;
  undefined4 local_28;
  
  local_28 = 0;
  if (param_1 == 1) {
    uVar5 = 0x7fffffff;
    uVar3 = 0;
    if (param_2 != 0) {
      do {
        uVar4 = FUN_c08a5590(param_4,*param_3);
        param_3 = param_3 + 1;
        if ((uVar4 <= uVar5) && (local_28 = uVar3, uVar5 = uVar4, uVar4 == 0)) {
          return uVar3;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < param_2);
    }
  }
  else if (param_1 == 2) {
    if (((*param_3 == 0xf800) && (param_3[1] == 0x7e0)) && (param_3[2] == 0x1f)) {
      local_28 = param_4 >> 0x13 & 0x1f | param_4 >> 5 & param_3[1] & 0x7ff | (param_4 & 0xf8) << 8;
    }
    else {
      local_28 = 0;
      uVar5 = 0x18;
      do {
        bVar1 = param_2 == 0;
        param_2 = param_2 - 1;
        if (bVar1) {
          return local_28;
        }
        uVar4 = 0x20;
        for (uVar3 = *param_3; uVar3 != 0; uVar3 = uVar3 >> 1) {
          uVar4 = (int)((uVar4 - 1) * 0x1000000) >> 0x18;
        }
        local_28 = (param_4 << (uVar5 & 0x1f)) >> (uVar4 & 0x1f) & *param_3 | local_28;
        uVar5 = (int)((uVar5 - 8) * 0x1000000) >> 0x18;
        param_3 = param_3 + 1;
      } while (-1 < (int)uVar5);
    }
  }
  else {
    local_28 = param_4;
    if (param_1 != 4) {
      if (param_1 == 8) {
        uStackX_e = (undefined1)(param_4 >> 0x10);
        local_resc = (undefined1)param_4;
        local_28 = CONCAT31((int3)(param_4 >> 8),uStackX_e);
        uVar2 = local_28;
        local_28._3_1_ = (undefined1)(param_4 >> 0x18);
        local_28._0_3_ = CONCAT12(local_resc,(short)uVar2);
      }
      else {
        local_28 = 0;
      }
    }
  }
  return local_28;
}



/* c089cb28 FUN_c089cb28 */

/* Boundary evidence: original MIPS .pdata c089cb28..c089cc43. Semantic name remains unreviewed. */

uint FUN_c089cb28(int param_1,int param_2,uint *param_3,uint param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined1 local_resc;
  undefined1 uStackX_e;
  undefined4 local_18;
  uint local_10 [4];
  
  local_10[0] = 0xff;
  puVar7 = local_10;
  local_10[1] = 0xff00;
  local_10[2] = 0xff0000;
  if (param_1 == 1) {
    local_18 = param_3[param_4];
  }
  else if (param_1 == 2) {
    local_18 = 0;
    uVar6 = 0x18;
    do {
      bVar1 = param_2 == 0;
      param_2 = param_2 + -1;
      if (bVar1) {
        return local_18;
      }
      uVar5 = 0;
      uVar3 = 0x20;
      for (uVar4 = *param_3; uVar4 != 0; uVar4 = uVar4 >> 1) {
        if ((uVar4 & 1) != 0) {
          uVar5 = uVar5 + 1;
        }
        uVar3 = (int)((uVar3 - 1) * 0x1000000) >> 0x18;
      }
      uVar4 = (*param_3 & param_4) << (uVar3 & 0x1f);
      param_3 = param_3 + 1;
      local_18 = (uVar4 >> (uVar5 & 0x1f) | uVar4) >> (uVar6 & 0x1f) & *puVar7 | local_18;
      uVar6 = (int)((uVar6 - 8) * 0x1000000) >> 0x18;
      puVar7 = puVar7 + 1;
    } while (-1 < (int)uVar6);
  }
  else {
    local_18 = param_4;
    if (param_1 != 4) {
      if (param_1 == 8) {
        uStackX_e = (undefined1)(param_4 >> 0x10);
        local_resc = (undefined1)param_4;
        local_18 = CONCAT31((int3)(param_4 >> 8),uStackX_e);
        uVar2 = local_18;
        local_18._3_1_ = (undefined1)(param_4 >> 0x18);
        local_18._0_3_ = CONCAT12(local_resc,(short)uVar2);
      }
      else {
        local_18 = 0;
      }
    }
  }
  return local_18;
}



/* c089cc58 FUN_c089cc58 */

/* Boundary evidence: original MIPS .pdata c089cc58..c089ce6b. Semantic name remains unreviewed. */

void FUN_c089cc58(uint *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 local_428;
  undefined1 local_424;
  undefined1 uStack_422;
  uint auStack_420 [256];
  
  uVar2 = (*DAT_c08bc87c)(param_2,1,0,0);
  uVar2 = uVar2 & 0xffff;
  if (0x100 < uVar2) {
    uVar2 = 0x100;
  }
  puVar6 = param_1 + 5;
  (*DAT_c08bc87c)(param_2,1,uVar2,puVar6);
  if (*(ushort *)(param_2 + 10) == 1) {
    uVar3 = (*DAT_c08bc87c)(param_2,2,0,0);
    uVar3 = uVar3 & 0xffff;
    if (0x100 < uVar3) {
      uVar3 = 0x100;
    }
    (*DAT_c08bc87c)(param_2,2,uVar3,auStack_420);
    if (uVar2 != 0) {
      uVar5 = 0;
      do {
        uVar4 = FUN_c089c964(1,uVar3,auStack_420,*puVar6);
        uVar5 = uVar5 + 1 & 0xffff;
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
      } while (uVar5 < uVar2);
    }
  }
  else {
    FUN_c089c2a4((int)param_1,param_2,2,(uint)*(ushort *)(param_2 + 10));
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        if (*(short *)(param_2 + 10) == 2) {
          uVar5 = param_1[uVar3 + 5];
          param_1[uVar3 + 5] =
               (uVar5 << 8) >> (*(byte *)((int)param_1 + 0xe) & 0x1f) & param_1[2] |
               (uVar5 << 0x10) >> (*(byte *)((int)param_1 + 0xd) & 0x1f) & param_1[1] |
               (uVar5 << 0x18) >> ((byte)param_1[3] & 0x1f) & *param_1;
        }
        if (*(short *)(param_2 + 10) == 8) {
          uVar5 = param_1[uVar3 + 5];
          uStack_422 = (undefined1)(uVar5 >> 0x10);
          local_424 = (undefined1)uVar5;
          local_428 = CONCAT31((int3)(uVar5 >> 8),uStack_422);
          uVar1 = local_428;
          local_428._3_1_ = (undefined1)(uVar5 >> 0x18);
          local_428._0_3_ = CONCAT12(local_424,(short)uVar1);
          param_1[uVar3 + 5] = local_428;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < uVar2);
    }
  }
  return;
}



/* c089ce6c FUN_c089ce6c */

/* Boundary evidence: original MIPS .pdata c089ce6c..c089d103. Semantic name remains unreviewed. */

int FUN_c089ce6c(int param_1,uint param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_res4;
  undefined4 local_30;
  
  iVar9 = 0;
  local_res4 = param_2;
  if ((*(short *)(param_1 + 0x6de) != 4) && (*(short *)(param_1 + 0x6de) != 8)) {
    local_res4 = (*(uint *)(param_1 + 0x6d4) | *(uint *)(param_1 + 0x6d0) |
                 *(uint *)(param_1 + 0x6cc)) & param_2;
  }
  iVar3 = FUN_c089c130((int *)(param_1 + 0x40),local_res4);
  if (iVar3 == -1) {
    local_30 = local_res4;
    if (*(short *)(param_1 + 0x6de) != 4) {
      if (*(short *)(param_1 + 0x6de) == 8) {
        local_30 = CONCAT31((int3)(local_res4 >> 8),local_res4._2_1_);
        uVar2 = local_30;
        local_30._3_1_ = (undefined1)(local_res4 >> 0x18);
        local_30._0_3_ = CONCAT12((undefined1)local_res4,(short)uVar2);
      }
      else {
        local_30 = FUN_c089c724(param_1,local_res4);
      }
    }
    uVar4 = (uint)*(ushort *)(param_1 + 0x2c2);
    uVar7 = (local_30 >> 0xb & 0x1f) + (local_30 >> 0x15 & 7) + (local_30 >> 4 & 0xf);
    uVar8 = uVar4;
    if (uVar4 + 4 <= uVar7) {
      uVar8 = uVar7 - 4;
    }
    uVar5 = (uint)*(ushort *)(param_1 + 0x2c4);
    uVar6 = uVar5;
    if ((int)uVar7 <= (int)(uVar5 - 5)) {
      uVar6 = uVar7 + 5;
    }
    uVar7 = uVar8 & 0xffff;
    if (*(short *)(((uVar8 & 0xffff) + 0x12a) * 2 + param_1) ==
        *(short *)((uVar6 + 0x12a) * 2 + param_1)) {
      uVar7 = uVar4;
      uVar6 = uVar5;
    }
    uVar8 = 0x10000000;
    sVar1 = *(short *)((uVar7 + 0x12a) * 2 + param_1);
    while (iVar3 = (int)sVar1, iVar3 != *(short *)((uVar6 + 0x12a) * 2 + param_1)) {
      uVar4 = FUN_c08a5590(local_30,*(uint *)((iVar3 + 0xb2) * 4 + param_1));
      if (uVar4 < uVar8) {
        iVar9 = iVar3;
        uVar8 = uVar4;
      }
      sVar1 = *(short *)((iVar3 + 0x2a) * 2 + param_1);
    }
    *(undefined2 *)(*(short *)(param_1 + 0x4e) * 2 + *(int *)(param_1 + 0x44)) =
         *(undefined2 *)(param_1 + 0x4c);
    *(undefined2 *)(*(short *)(param_1 + 0x4c) * 2 + *(int *)(param_1 + 0x48)) =
         *(undefined2 *)(param_1 + 0x4e);
    *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4c);
    *(undefined2 *)(param_1 + 0x4c) =
         *(undefined2 *)(*(short *)(param_1 + 0x4c) * 2 + *(int *)(param_1 + 0x44));
    *(uint *)(*(short *)(param_1 + 0x4e) * 4 + *(int *)(param_1 + 0x40)) = local_res4;
    *(int *)(*(short *)(param_1 + 0x4e) * 4 + param_1) = iVar9;
  }
  else {
    iVar9 = *(int *)(iVar3 * 4 + param_1);
  }
  return iVar9;
}



/* c089d104 FUN_c089d104 */

/* Boundary evidence: original MIPS .pdata c089d104..c089d1c7. Semantic name remains unreviewed. */

undefined4 FUN_c089d104(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_c089c03c(&DAT_c08bdab8,10);
  if ((((iVar1 == 0) || (iVar1 = FUN_c089c03c(&DAT_c08bdaf4,2), iVar1 == 0)) ||
      (iVar1 = FUN_c089c03c(&DAT_c08bdae0,10), iVar1 == 0)) ||
     (iVar1 = FUN_c089c03c(&DAT_c08bdacc,4), iVar1 == 0)) {
LAB_c089d1b0:
    uVar2 = 0;
  }
  else {
    piVar3 = (int *)&DAT_c08bdb48;
    do {
      iVar1 = FUN_c089c03c(piVar3,0x10);
      if (iVar1 == 0) goto LAB_c089d1b0;
      piVar3 = piVar3 + 0x1b8;
    } while ((int)piVar3 < -0x3f7416f8);
    uVar2 = 1;
  }
  return uVar2;
}



/* c089d1c8 FUN_c089d1c8 */

/* Boundary evidence: original MIPS .pdata c089d1c8..c089d243. Semantic name remains unreviewed. */

void FUN_c089d1c8(void)

{
  undefined4 *puVar1;
  
  FUN_c089c23c(&DAT_c08bdab8);
  FUN_c089c23c(&DAT_c08bdaf4);
  FUN_c089c23c(&DAT_c08bdae0);
  FUN_c089c23c(&DAT_c08bdacc);
  puVar1 = (undefined4 *)&DAT_c08bdb48;
  do {
    FUN_c089c23c(puVar1);
    puVar1 = puVar1 + 0x1b8;
  } while ((int)puVar1 < -0x3f7416f8);
  return;
}



/* c089d244 FUN_c089d244 */

/* Boundary evidence: original MIPS .pdata c089d244..c089d6a3. Semantic name remains unreviewed. */

void FUN_c089d244(int *param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  int iVar6;
  
  *param_2 = 0;
  *param_4 = 0;
  *param_3 = 0;
  if ((((param_1 != (int *)0x0) && (sVar1 = (short)param_1[2], sVar1 != 0x10)) &&
      (sVar2 = *(short *)((int)param_1 + 10), sVar2 != 0x10)) && (iVar3 = param_1[1], iVar3 != 1)) {
    if (iVar3 == 2) {
      *param_4 = param_1[4];
    }
    else {
      if (iVar3 == 4) {
        iVar6 = *(int *)param_1[4];
        iVar3 = FUN_c089c130(&DAT_c08bdae0,iVar6);
        if (iVar3 == -1) {
          *(short *)(DAT_c08bdaee * 2 + DAT_c08bdae4) = DAT_c08bdaec;
          *(short *)(DAT_c08bdaec * 2 + DAT_c08bdae8) = DAT_c08bdaee;
          iVar3 = (int)DAT_c08bdaec;
          DAT_c08bdaee = DAT_c08bdaec;
          DAT_c08bdaec = *(short *)(iVar3 * 2 + DAT_c08bdae4);
          *(int *)(iVar3 * 4 + DAT_c08bdae0) = iVar6;
          iVar3 = (int)DAT_c08bdaee;
        }
        piVar4 = (int *)(&DAT_c08bda90 + iVar3 * 4);
        *piVar4 = iVar6;
        pcVar5 = (code *)&LAB_c089c94c;
      }
      else {
        if (sVar1 == 1) {
          iVar3 = FUN_c089c130(&DAT_c08bdacc,*param_1);
          if (iVar3 == -1) {
            iVar6 = *param_1;
            *(short *)(DAT_c08bdada * 2 + DAT_c08bdad0) = DAT_c08bdad8;
            *(short *)(DAT_c08bdad8 * 2 + DAT_c08bdad4) = DAT_c08bdada;
            iVar3 = (int)DAT_c08bdad8;
            DAT_c08bdada = DAT_c08bdad8;
            DAT_c08bdad8 = *(short *)(iVar3 * 2 + DAT_c08bdad0);
            *(int *)(iVar3 * 4 + DAT_c08bdacc) = iVar6;
            iVar3 = (int)DAT_c08bdada;
            FUN_c089cc58((uint *)(iVar3 * 0x414 + -0x3f7435c0),(int)param_1);
          }
          *param_4 = iVar3 * 0x414 + -0x3f7435ac;
          return;
        }
        if (sVar2 != 1) {
          if (((sVar1 != 2) && (sVar1 != 4)) && (sVar1 != 8)) {
            return;
          }
          if (((sVar2 != 2) && (sVar2 != 4)) && (sVar2 != 8)) {
            return;
          }
          *param_3 = (&PTR_FUN_c0891310)
                     [(uint)(byte)(&DAT_c08b153c)[*(ushort *)(param_1 + 2) >> 1] * 4 +
                      (uint)(byte)(&DAT_c08b153c)[*(ushort *)((int)param_1 + 10) >> 1] + -4];
          if (((*(ushort *)((int)param_1 + 10) | *(ushort *)(param_1 + 2)) & 2) == 0) {
            return;
          }
          iVar3 = FUN_c089c130(&DAT_c08bdab8,*param_1);
          if (iVar3 == -1) {
            iVar6 = *param_1;
            *(short *)(DAT_c08bdac6 * 2 + DAT_c08bdabc) = DAT_c08bdac4;
            *(short *)(DAT_c08bdac4 * 2 + DAT_c08bdac0) = DAT_c08bdac6;
            iVar3 = (int)DAT_c08bdac4;
            DAT_c08bdac6 = DAT_c08bdac4;
            DAT_c08bdac4 = *(short *)(iVar3 * 2 + DAT_c08bdabc);
            *(int *)(iVar3 * 4 + DAT_c08bdab8) = iVar6;
            iVar3 = (int)DAT_c08bdac6;
            FUN_c089c394(iVar3 * 0x28 + -0x3f743750,(int)param_1);
          }
          *param_2 = iVar3 * 0x28 + -0x3f743750;
          return;
        }
        iVar3 = FUN_c089c130(&DAT_c08bdaf4,*param_1);
        if (iVar3 == -1) {
          iVar6 = *param_1;
          *(short *)(DAT_c08bdb02 * 2 + DAT_c08bdaf8) = DAT_c08bdb00;
          *(short *)(DAT_c08bdb00 * 2 + DAT_c08bdafc) = DAT_c08bdb02;
          iVar3 = (int)DAT_c08bdb00;
          DAT_c08bdb02 = DAT_c08bdb00;
          DAT_c08bdb00 = *(short *)(iVar3 * 2 + DAT_c08bdaf8);
          *(int *)(iVar3 * 4 + DAT_c08bdaf4) = iVar6;
          iVar3 = (int)DAT_c08bdb02;
          FUN_c089c3e8((int)(&DAT_c08bdb08 + iVar3 * 0x6e0),(int)param_1);
        }
        pcVar5 = FUN_c089ce6c;
        piVar4 = (int *)(&DAT_c08bdb08 + iVar3 * 0x6e0);
      }
      *param_2 = (int)piVar4;
      *param_3 = pcVar5;
    }
  }
  return;
}



/* c089d6a4 FUN_c089d6a4 */

/* Boundary evidence: original MIPS .pdata c089d6a4..c089d703. Semantic name remains unreviewed. */

void FUN_c089d6a4(undefined4 param_1,undefined4 *param_2)

{
  (*(code *)*param_2)(param_1,param_2);
  return;
}



/* c089d704 FUN_c089d704 */

/* Boundary evidence: original MIPS .pdata c089d704..c089d70f. Semantic name remains unreviewed. */

undefined4 FUN_c089d704(void)

{
  return 1;
}



/* c089d710 FUN_c089d710 */

/* Boundary evidence: original MIPS .pdata c089d710..c089e0f3. Semantic name remains unreviewed. */

undefined4
FUN_c089d710(int *param_1,undefined4 param_2,int *param_3,undefined4 param_4,undefined4 *param_5,
            undefined4 param_6,uint *param_7,uint param_8)

{
  bool bVar1;
  bool bVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  int iVar20;
  undefined *puVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  uint local_4c0;
  uint local_4bc;
  uint *local_4b8;
  int local_4b4;
  uint local_4b0;
  uint *local_4ac;
  uint *local_4a8;
  uint local_4a4;
  uint local_4a0;
  uint local_49c;
  int *local_498;
  int *local_494;
  uint local_490;
  uint local_48c;
  int local_488;
  undefined *local_484;
  undefined4 local_480;
  undefined4 uStack_478;
  int local_474;
  int local_470;
  int local_46c;
  uint local_468;
  uint local_464;
  int local_460;
  uint local_45c;
  uint local_458;
  uint local_454;
  int local_450;
  undefined4 local_44c;
  int *local_448;
  undefined2 local_444;
  int local_440;
  int local_43c;
  int local_438;
  int local_434;
  int local_430 [3];
  undefined4 local_424;
  int local_420;
  int local_41c;
  int local_418;
  int local_414;
  int local_410;
  int local_40c;
  int local_408;
  int local_404;
  int local_400;
  int local_3fc;
  int local_3f8;
  int local_3f4;
  int local_3f0;
  int local_3ec;
  int local_3e8;
  int local_3e4;
  int local_3e0;
  int local_3dc;
  int local_3d8;
  int local_3d4;
  int local_3d0;
  int local_3cc;
  int local_3c8;
  int local_3c4;
  int local_3c0;
  int local_3bc;
  int local_3b8;
  int local_3b4;
  int local_3b0;
  int local_3ac;
  int local_3a8;
  int local_3a4;
  int local_3a0;
  undefined4 auStack_39c [19];
  int local_350;
  int local_34c [201];
  
  piVar16 = (int *)param_1[2];
  local_498 = param_3;
  local_494 = piVar16;
  local_480 = param_2;
  FUN_c08a0ba8(&local_3a0,param_1,(int *)0x0,(int *)0x0);
  uVar11 = 0;
  local_44c = *param_5;
  local_444 = (undefined2)param_8;
  local_450 = local_3a0;
  local_458 = 0;
  bVar1 = *(int *)(local_3a0 + 0x38) != 0;
  if ((param_7 != (uint *)0x0) && (((param_8 >> 8 ^ param_8) & 0xff) != 0)) {
    if ((*param_7 & 2) == 0) {
      if ((param_7[6] != 0) && (uVar17 = param_7[5], uVar17 != 0)) {
        uVar13 = 0;
        uVar23 = 0;
        uVar12 = 0;
        do {
          uVar12 = uVar12 % uVar17;
          if (uVar17 == 0) {
            trap(0x1c00);
          }
          piVar4 = (int *)(uVar12 * 4 + param_7[6]);
          iVar5 = 0;
          if (0 < *piVar4) {
            do {
              if (0x1f < (int)uVar13) break;
              uVar11 = uVar23 << (uVar13 & 0x1f) | uVar11;
              iVar5 = iVar5 + 1;
              uVar13 = uVar13 + 1;
              local_458 = uVar11;
            } while (iVar5 < *piVar4);
          }
          uVar23 = uVar23 ^ 1;
          if (uVar12 == 0x40) {
            uVar11 = 0;
            local_458 = uVar11;
            break;
          }
          uVar12 = uVar12 + 1;
        } while ((int)uVar13 < 0x20);
      }
    }
    else {
      uVar11 = 0xaaaaaaaa;
      local_458 = uVar11;
    }
    if ((*param_7 & 4) != 0) {
      local_458 = ~uVar11;
    }
  }
  iVar5 = (**(code **)(*piVar16 + 0xc))(piVar16,&uStack_478,1);
  if (iVar5 < 0) {
LAB_c089e0b8:
    FUN_c0894ac8(auStack_39c);
    return 0;
  }
  if ((param_3 == (int *)0x0) || ((char)param_3[5] == '\0')) {
    local_430[1] = 0;
    local_430[0] = 0;
    piVar16 = local_430;
    local_430[2] = *(undefined4 *)(local_450 + 0x2c);
    local_424 = *(undefined4 *)(local_450 + 0x30);
  }
  else {
    if ((char)param_3[5] != '\x01') {
      local_4b4 = 1;
      piVar16 = local_498;
      goto LAB_c089d8fc;
    }
    piVar16 = param_3 + 1;
  }
  local_4b4 = 0;
LAB_c089d8fc:
  puVar21 = &DAT_c0891340;
  local_350 = 1 - local_4b4;
  local_484 = &DAT_c0891340;
  local_4a4 = local_48c;
  local_4b0 = local_490;
  uVar17 = local_48c;
  uVar11 = local_490;
  do {
    if (local_350 == 0) {
      if (local_4b4 == 0) {
        (**(code **)(*local_494 + 0xc))(local_494,&uStack_478,3);
        FUN_c0894ac8(auStack_39c);
        return 1;
      }
      local_4b4 = (*DAT_c08bc864)(param_3,0x324,&local_350);
      piVar16 = local_34c;
      if (local_350 != 0) goto LAB_c089d960;
    }
    else {
LAB_c089d960:
      local_454 = 0;
      if (bVar1) {
        local_440 = *piVar16;
        local_43c = piVar16[1];
        local_438 = piVar16[2];
        local_434 = piVar16[3];
        FUN_c0894674(local_450,&local_440);
      }
      local_40c = *piVar16;
      local_418 = piVar16[2];
      local_410 = piVar16[1];
      local_420 = local_40c;
      local_41c = local_410;
      local_3e0 = 1 - local_418;
      local_404 = local_418;
      local_3f8 = local_418;
      local_3e4 = local_418;
      local_3d8 = 1 - local_40c;
      local_414 = piVar16[3];
      local_3fc = 1 - local_414;
      local_3f4 = 1 - local_410;
      local_408 = local_414;
      local_400 = local_40c;
      local_3f0 = local_3fc;
      local_3ec = local_40c;
      local_3e8 = local_3f4;
      local_3dc = local_410;
      local_3d4 = local_414;
      local_3d0 = local_410;
      local_3cc = local_3e0;
      local_3c8 = local_414;
      local_3c4 = local_3d8;
      local_3c0 = local_3e0;
      local_3bc = local_3fc;
      local_3b8 = local_3d8;
      local_3b4 = local_3f4;
      local_3b0 = local_3fc;
      local_3ac = local_3e0;
      local_3a8 = local_3f4;
      local_3a4 = local_3d8;
      (*DAT_c08bc880)(param_2);
      do {
        local_488 = (*DAT_c08bc85c)(param_2,&local_4c0);
        local_4a0 = local_4bc;
        param_3 = local_498;
        if (local_4bc == 0) break;
        if ((local_4c0 & 1) == 0) {
          local_4a8 = &local_490;
          local_4ac = local_4b8;
        }
        else {
          uVar11 = *local_4b8;
          uVar17 = local_4b8[1];
          local_4ac = local_4b8 + 2;
          local_4a0 = local_4bc - 1;
          local_4a8 = local_4b8;
          local_4b0 = uVar11;
          local_4a4 = uVar17;
        }
        local_49c = 0;
        puVar19 = local_4b8;
        do {
          if (local_49c < local_4a0) {
            uVar11 = *local_4ac;
            uVar17 = local_4ac[1];
            uVar12 = *local_4a8;
            uVar13 = local_4a8[1];
            puVar3 = local_4ac + 2;
            local_4a8 = local_4ac;
          }
          else {
            uVar12 = puVar19[local_4bc * 2 + -2];
            uVar13 = puVar19[local_4bc * 2 + -1];
            local_490 = uVar12;
            local_48c = uVar13;
            puVar3 = local_4ac;
            if ((local_4c0 & 8) == 0) break;
          }
          local_4ac = puVar3;
          uVar23 = 0;
          if ((int)uVar11 < (int)uVar12) {
            uVar12 = -uVar12;
            uVar11 = -uVar11;
            uVar23 = 0x200;
          }
          if ((int)uVar17 < (int)uVar13) {
            uVar13 = -uVar13;
            uVar17 = -uVar17;
            uVar23 = uVar23 | 8;
          }
          uVar18 = uVar11;
          uVar24 = uVar12;
          if ((int)(uVar11 - uVar12) < (int)(uVar17 - uVar13)) {
            uVar23 = uVar23 | 5;
            uVar18 = uVar17;
            uVar24 = uVar13;
            uVar13 = uVar12;
            uVar17 = uVar11;
          }
          uVar18 = uVar18 - uVar24;
          uVar17 = uVar17 - uVar13;
          if (uVar18 == uVar17) {
            uVar23 = uVar23 | 0x10;
          }
          uVar11 = *(uint *)(puVar21 + (uVar23 >> 2 & 7) * 4);
          uVar23 = uVar11 | uVar23;
          iVar20 = (int)uVar24 >> 4;
          iVar22 = (int)uVar13 >> 4;
          uVar24 = uVar24 & 0xf;
          uVar13 = uVar13 & 0xf;
          uVar14 = uVar24 + uVar18 & 0xf;
          uVar12 = uVar13 + uVar17 & 0xf;
          iVar8 = (int)(uVar24 + uVar18) >> 4;
          iVar7 = (int)(((uVar13 + 8) * uVar18 - uVar24 * uVar17) - (uint)((uVar11 & 0x8000) != 0))
                  >> 4;
          iVar5 = iVar8 + -1;
          if (uVar14 != 0) {
            if (uVar12 == 0) {
              if ((uVar11 & 0x80) == 0) {
                uVar9 = 7;
              }
              else {
                uVar9 = 8;
              }
              if (uVar9 < uVar14) {
LAB_c089dc6c:
                iVar5 = iVar8;
              }
            }
            else {
              if (uVar12 < 8) {
                iVar10 = 8 - uVar12;
              }
              else {
                iVar10 = uVar12 - 8;
              }
              if (iVar10 <= (int)uVar14) goto LAB_c089dc6c;
            }
          }
          iVar8 = 0;
          if ((uVar23 & 0x90) == 0x90) {
            if ((uVar14 != 0) && (uVar12 == uVar14 + 8)) {
              iVar5 = iVar5 + -1;
            }
            if ((uVar24 != 0) && (uVar13 != uVar24 + 8)) goto LAB_c089dcac;
          }
          else {
LAB_c089dcac:
            if (uVar24 != 0) {
              if (uVar13 == 0) {
                if ((uVar11 & 0x80) == 0) {
                  uVar11 = 7;
                }
                else {
                  uVar11 = 8;
                }
                if (uVar11 < uVar24) {
LAB_c089dd14:
                  iVar8 = 1;
                }
              }
              else {
                if (uVar13 < 8) {
                  iVar10 = 8 - uVar13;
                }
                else {
                  iVar10 = uVar13 - 8;
                }
                if (iVar10 <= (int)uVar24) goto LAB_c089dd14;
              }
            }
          }
          bVar2 = iVar7 < (int)(uVar18 - (-iVar8 & uVar17));
          if (bVar2) {
            iVar10 = (~(iVar8 - 1U) & uVar17) - uVar18;
          }
          else {
            iVar10 = (~(iVar8 - 1U) & uVar17) + uVar18 * -2;
          }
          uVar11 = (uint)!bVar2;
          iVar10 = iVar10 + iVar7;
          iVar7 = (iVar5 - iVar8) + 1;
          if (0 < iVar7) {
            piVar4 = &local_420;
            uVar12 = uVar23 & 0x200;
            if (uVar12 != 0) {
              piVar4 = &local_3e0;
            }
            piVar4 = piVar4 + (uVar23 >> 2 & 3) * 4;
            iVar25 = piVar4[2] - iVar20;
            iVar6 = piVar4[3] - iVar22;
            iVar15 = *piVar4 - iVar20;
            uVar13 = piVar4[1] - iVar22;
            if ((((int)uVar11 < iVar6) && (iVar8 < iVar25)) && (iVar15 <= iVar5)) {
              if (iVar25 <= iVar5) {
                iVar5 = iVar25 + -1;
              }
              if ((uVar18 == 0) || (uVar17 == 0)) {
                if (iVar8 < iVar15) {
                  iVar8 = iVar15;
                }
                if ((int)uVar13 <= (int)uVar11) goto LAB_c089dfac;
              }
              else {
                if (iVar8 < iVar15) {
                  if (uVar18 == 0) {
                    trap(0x1c00);
                  }
                  uVar11 = ((iVar15 - iVar8) * uVar17 + iVar10 + uVar18) / uVar18 + uVar11;
                  iVar8 = iVar15;
                  if (iVar6 <= (int)uVar11) goto LAB_c089df2c;
                }
                if ((int)uVar11 < (int)uVar13) {
                  if (uVar17 == 0) {
                    trap(0x1c00);
                  }
                  iVar8 = ((((uVar13 - uVar11) + -1) * uVar18 - iVar10) - 1) / uVar17 + iVar8 + 1;
                  uVar11 = uVar13;
                  if (iVar25 <= iVar8) goto LAB_c089df2c;
                }
                iVar25 = (iVar5 - iVar8) * uVar17 + iVar10 + uVar18;
                if (uVar18 == 0) {
                  trap(0x1c00);
                }
                if ((uVar18 == 0xffffffff) && (iVar25 == -0x80000000)) {
                  trap(0x1800);
                }
                iVar25 = iVar25 / (int)uVar18 + uVar11;
                if ((int)uVar13 <= iVar25) {
                  if (iVar6 <= iVar25) {
                    iVar5 = (((iVar6 - uVar11) + -1) * uVar18 - iVar10) + -1;
                    if (uVar17 == 0) {
                      trap(0x1c00);
                    }
                    if ((uVar17 == 0xffffffff) && (iVar5 == -0x80000000)) {
                      trap(0x1800);
                    }
                    iVar5 = iVar5 / (int)uVar17 + iVar8;
                    if (iVar5 < iVar15) goto LAB_c089df2c;
                  }
LAB_c089dfac:
                  iVar15 = iVar8 + iVar20;
                  iVar6 = uVar11 + iVar22;
                  if ((uVar23 & 5) != 0) {
                    iVar15 = uVar11 + iVar22;
                    iVar6 = iVar8 + iVar20;
                  }
                  if ((uVar23 & 8) != 0) {
                    iVar6 = -iVar6;
                  }
                  if (uVar12 != 0) {
                    iVar15 = -iVar15;
                  }
                  uVar11 = 7;
                  if ((uVar23 & 8) == 0) {
                    uVar11 = 0;
                  }
                  uVar13 = 3;
                  if (uVar12 == 0) {
                    uVar13 = 0;
                  }
                  iVar5 = (iVar5 - iVar8) + 1;
                  if (0 < iVar5) {
                    local_45c = uVar13 ^ (uVar23 & 5) != 0 ^ uVar11;
                    local_474 = iVar15;
                    local_470 = iVar6;
                    local_46c = iVar5;
                    local_468 = uVar18;
                    local_464 = uVar17;
                    local_460 = iVar10;
                    local_448 = piVar16;
                    if (bVar1) {
                      local_448 = &local_440;
                      FUN_c0894568(local_450,(int)&uStack_478);
                    }
                    iVar5 = FUN_c089d6a4(local_494,&uStack_478);
                    if (iVar5 < 0) goto LAB_c089e0b8;
                    local_454 = iVar7 + local_454 & 0x1f;
                    puVar19 = local_4b8;
                  }
                }
              }
            }
          }
LAB_c089df2c:
          local_49c = local_49c + 1;
          uVar17 = local_4a4;
          uVar11 = local_4b0;
          puVar21 = local_484;
        } while (local_49c <= local_4a0);
        uVar17 = local_4a4;
        param_3 = local_498;
        param_2 = local_480;
        uVar11 = local_4b0;
      } while (local_488 != 0);
    }
    piVar16 = piVar16 + 4;
    local_350 = local_350 + -1;
  } while( true );
}



/* c089e0f4 FUN_c089e0f4 */

undefined4 FUN_c089e0f4(undefined4 param_1)

{
  DAT_c08be978 = param_1;
  return 1;
}



/* c089e104 FUN_c089e104 */

/* Boundary evidence: original MIPS .pdata c089e104..c089e317. Semantic name remains unreviewed. */

undefined4 FUN_c089e104(undefined4 param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  undefined *puVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  
  iVar3 = *(int *)(param_2 + 4);
  iVar5 = *(int *)(*(int *)(param_2 + 0xc) + 8);
  cVar1 = *(char *)(param_2 + 0x20);
  iVar14 = *(int *)(iVar3 + 8);
  puVar15 = *(uint **)(param_2 + 0x2c);
  piVar12 = *(int **)(param_2 + 0x14);
  iVar4 = *(int *)(iVar3 + 0x38);
  puVar11 = (undefined *)0x0;
  iVar13 = piVar12[1];
  pbVar6 = (byte *)(puVar15[1] * iVar5 + ((int)*puVar15 >> 1) +
                   *(int *)(*(int *)(param_2 + 0xc) + 4));
  pcVar7 = (char *)(iVar13 * iVar14 + *(int *)(iVar3 + 4) + *piVar12);
  if (cVar1 == '\0') {
    puVar11 = &DAT_c0891370;
  }
  else if (cVar1 == -1) {
    puVar11 = &UNK_c0891360;
  }
  if (iVar13 < piVar12[3]) {
    do {
      iVar3 = *piVar12;
      uVar9 = *puVar15 & 1;
      pcVar2 = pcVar7;
      pbVar10 = pbVar6;
      if (iVar3 < piVar12[2]) {
        do {
          if (uVar9 == 0) {
            uVar8 = (uint)(*pbVar10 >> 4);
          }
          else {
            uVar8 = *pbVar10 & 0xf;
            pbVar10 = pbVar10 + 1;
          }
          uVar9 = (uint)(uVar9 == 0);
          if (uVar8 != 0) {
            if (iVar4 != 0) {
              pcVar2 = (char *)FUN_c08947dc(*(int *)(param_2 + 4),iVar3,iVar13);
            }
            if (puVar11 == (undefined *)0x0) {
              if (8 < uVar8) {
                *pcVar2 = cVar1;
              }
            }
            else {
              *pcVar2 = puVar11[uVar8];
            }
          }
          iVar3 = iVar3 + 1;
          pcVar2 = pcVar2 + 1;
        } while (iVar3 < piVar12[2]);
      }
      pbVar6 = pbVar6 + iVar5;
      pcVar7 = pcVar7 + iVar14;
      iVar13 = iVar13 + 1;
    } while (iVar13 < piVar12[3]);
  }
  return 0;
}



/* c089e318 FUN_c089e318 */

/* Boundary evidence: original MIPS .pdata c089e318..c089e497. Semantic name remains unreviewed. */

void FUN_c089e318(double param_1,double param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 extraout_v0;
  undefined4 uVar3;
  undefined4 extraout_v0_00;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = 0;
  uVar1 = __fpdiv(0x3f800000);
  puVar5 = (undefined4 *)(param_3 + 0x30);
  do {
    if (iVar4 < 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = __litofp(iVar4);
      uVar2 = __fpadd(uVar2,0x3f800000);
    }
    uVar2 = __fpmul(uVar2,0x3d800000);
    __fptodp(uVar1);
    __fptodp(uVar2);
    pow(param_1,param_2);
    uVar3 = __dptofp(extraout_v0,extraout_v1);
    uVar3 = __fpmul(uVar3,0x47800000);
    uVar3 = __fptoul(uVar3);
    *puVar5 = uVar3;
    __fptodp(uVar1);
    uVar2 = __fpsub(0x3f800000,uVar2);
    __fptodp(uVar2);
    pow(param_1,param_2);
    uVar2 = __dptofp(extraout_v0_00,extraout_v1_00);
    uVar2 = __fpmul(uVar2,0x47800000);
    uVar2 = __fpsub(0x47800000,uVar2);
    uVar2 = __fptoul(uVar2);
    iVar4 = iVar4 + 1;
    puVar5[0x10] = uVar2;
    puVar5 = puVar5 + 1;
  } while (iVar4 < 0x10);
  return;
}



/* c089e498 FUN_c089e498 */

uint FUN_c089e498(uint *param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar7 = ((*param_1 & param_2) << (param_1[3] & 0x1f)) >> (param_1[4] & 0x1f);
  iVar4 = param_1[9] - uVar7;
  puVar1 = param_1 + 0x1c;
  if (-1 < iVar4) {
    puVar1 = param_1 + 0xc;
  }
  puVar2 = param_1 + 0x1c;
  uVar8 = ((param_1[1] & param_2) << (param_1[5] & 0x1f)) >> (param_1[6] & 0x1f);
  iVar5 = param_1[10] - uVar8;
  if (-1 < iVar5) {
    puVar2 = param_1 + 0xc;
  }
  uVar9 = ((param_1[2] & param_2) << (param_1[7] & 0x1f)) >> (param_1[8] & 0x1f);
  iVar6 = param_1[0xb] - uVar9;
  puVar3 = param_1 + 0x1c;
  if (-1 < iVar6) {
    puVar3 = param_1 + 0xc;
  }
  return ((puVar3[param_3] * iVar6 + uVar9 * 0x10000 >> 0x10) << (param_1[8] & 0x1f)) >>
         (param_1[7] & 0x1f) & param_1[2] |
         ((puVar2[param_3] * iVar5 + uVar8 * 0x10000 >> 0x10) << (param_1[6] & 0x1f)) >>
         (param_1[5] & 0x1f) & param_1[1] |
         ((puVar1[param_3] * iVar4 + uVar7 * 0x10000 >> 0x10) << (param_1[4] & 0x1f)) >>
         (param_1[3] & 0x1f) & *param_1;
}



/* c089e5a4 FUN_c089e5a4 */

/* Boundary evidence: original MIPS .pdata c089e5a4..c089e6f7. Semantic name remains unreviewed. */

void FUN_c089e5a4(int param_1)

{
  int iVar1;
  uint local_18;
  uint local_14;
  uint local_10 [2];
  
  if (DAT_c08be978 == (code *)0x0) {
    if (param_1 == 0x10) {
      local_18 = 0xf800;
      local_14 = 0x7e0;
      local_10[0] = 0x1f;
    }
    else if ((param_1 == 0x18) || (param_1 == 0x20)) {
      local_18 = 0xff0000;
      local_14 = 0xff00;
      local_10[0] = 0xff;
    }
    else {
      local_10[0] = 0;
      local_14 = 0;
      local_18 = 0;
    }
  }
  else {
    (*DAT_c08be978)(&local_18,&local_14,local_10);
  }
  DAT_c08be8c8 = local_18;
  DAT_c08be8cc = local_14;
  iVar1 = 0;
  DAT_c08be8d0 = local_10[0];
  for (; local_18 != 0; local_18 = local_18 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c08be8d8 = iVar1 + -8;
  iVar1 = 0;
  for (; local_14 != 0; local_14 = local_14 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c08be8e0 = iVar1 + -8;
  iVar1 = 0;
  for (; local_10[0] != 0; local_10[0] = local_10[0] >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c08be8e8 = iVar1 + -8;
  DAT_c08be8d4 = 0;
  if (DAT_c08be8d8 < 0) {
    DAT_c08be8d4 = -DAT_c08be8d8;
    DAT_c08be8d8 = 0;
  }
  DAT_c08be8dc = 0;
  if (DAT_c08be8e0 < 0) {
    DAT_c08be8dc = -DAT_c08be8e0;
    DAT_c08be8e0 = 0;
  }
  DAT_c08be8e4 = 0;
  if (DAT_c08be8e8 < 0) {
    DAT_c08be8e4 = -DAT_c08be8e8;
    DAT_c08be8e8 = 0;
  }
  return;
}



/* c089e6f8 FUN_c089e6f8 */

/* Boundary evidence: original MIPS .pdata c089e6f8..c089e7ef. Semantic name remains unreviewed. */

void FUN_c089e6f8(double param_1,double param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  uint local_18;
  HKEY local_14;
  DWORD local_10 [2];
  
  local_18 = 0x91a;
  local_14 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"System\\GDI\\Gamma",0,0,&local_14);
  if (LVar1 == 0) {
    local_10[0] = 4;
    RegQueryValueExW(local_14,L"Gamma Value",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_18,local_10);
    if (local_18 < 0x3e9) {
      local_18 = 1000;
    }
    else if (2999 < local_18) {
      local_18 = 3000;
    }
    RegCloseKey(local_14);
  }
  uVar2 = __ultofp(local_18);
  __fpdiv(uVar2,0x447a0000);
  FUN_c089e318(param_1,param_2,-0x3f741738);
  return;
}



/* c089e7f0 FUN_c089e7f0 */

/* Boundary evidence: original MIPS .pdata c089e7f0..c089e917. Semantic name remains unreviewed. */

undefined4 FUN_c089e7f0(double param_1,double param_2,uint param_3,int param_4)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_res0 [4];
  HKEY local_10;
  DWORD DStack_c;
  
  local_res0[0] = param_3;
  if (param_4 == 0) {
LAB_c089e8bc:
    if (local_res0[0] < 0x3e9) {
      uVar3 = 1000;
    }
    else {
      uVar3 = local_res0[0];
      if (2999 < local_res0[0]) {
        uVar3 = 3000;
      }
    }
    uVar2 = __ultofp(uVar3);
    __fpdiv(uVar2,0x447a0000);
    FUN_c089e318(param_1,param_2,-0x3f741738);
    return 1;
  }
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"System\\GDI\\Gamma",0,(LPWSTR)0x0,0,0,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_10,&DStack_c);
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_10,L"Gamma Value",0,4,(BYTE *)local_res0,4);
    if (LVar1 == 0) {
      RegCloseKey(local_10);
      goto LAB_c089e8bc;
    }
    RegCloseKey(local_10);
  }
  return 0;
}



/* c089e918 FUN_c089e918 */

/* Boundary evidence: original MIPS .pdata c089e918..c089ebbf. Semantic name remains unreviewed. */

undefined4 FUN_c089e918(double param_1,double param_2,undefined4 param_3,int param_4)

{
  ushort uVar1;
  ushort *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  int *piVar11;
  uint uVar12;
  byte *local_40;
  ushort *local_3c;
  
  iVar4 = *(int *)(param_4 + 4);
  iVar6 = *(int *)(*(int *)(param_4 + 0xc) + 8);
  uVar1 = *(ushort *)(param_4 + 0x20);
  iVar7 = *(int *)(iVar4 + 8);
  puVar3 = *(uint **)(param_4 + 0x2c);
  piVar11 = *(int **)(param_4 + 0x14);
  iVar5 = *(int *)(iVar4 + 0x38);
  local_40 = (byte *)(puVar3[1] * iVar6 + ((int)*puVar3 >> 1) +
                     *(int *)(*(int *)(param_4 + 0xc) + 4));
  local_3c = (ushort *)(piVar11[1] * iVar7 + *piVar11 * 2 + *(int *)(iVar4 + 4));
  if (DAT_c08be97c == '\0') {
    FUN_c089e5a4(0x10);
    FUN_c089e6f8(param_1,param_2);
    DAT_c08be97c = '\x01';
  }
  uVar12 = (uint)uVar1;
  DAT_c08be8ec = ((DAT_c08be8c8 & uVar12) >> (DAT_c08be8d8 & 0x1f)) << (DAT_c08be8d4 & 0x1f);
  DAT_c08be8f0 = ((DAT_c08be8cc & uVar12) >> (DAT_c08be8e0 & 0x1f)) << (DAT_c08be8dc & 0x1f);
  DAT_c08be8f4 = ((DAT_c08be8d0 & uVar12) >> (DAT_c08be8e8 & 0x1f)) << (DAT_c08be8e4 & 0x1f);
  iVar4 = piVar11[1];
  if (iVar4 < piVar11[3]) {
    do {
      iVar9 = *piVar11;
      uVar12 = *puVar3 & 1;
      puVar2 = local_3c;
      pbVar10 = local_40;
      if (iVar9 < piVar11[2]) {
        do {
          if (uVar12 == 0) {
            uVar8 = (uint)(*pbVar10 >> 4);
          }
          else {
            uVar8 = *pbVar10 & 0xf;
            pbVar10 = pbVar10 + 1;
          }
          uVar12 = (uint)(uVar12 == 0);
          if (uVar8 != 0) {
            if (iVar5 != 0) {
              puVar2 = (ushort *)FUN_c08947dc(*(int *)(param_4 + 4),iVar9,iVar4);
            }
            if (uVar8 == 0xf) {
              *puVar2 = uVar1;
            }
            else {
              uVar8 = FUN_c089e498(&DAT_c08be8c8,(uint)*puVar2,uVar8);
              *puVar2 = (ushort)uVar8;
            }
          }
          iVar9 = iVar9 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar9 < piVar11[2]);
      }
      local_40 = local_40 + iVar6;
      local_3c = (ushort *)((int)local_3c + iVar7);
      iVar4 = iVar4 + 1;
    } while (iVar4 < piVar11[3]);
  }
  return 0;
}



/* c089ebc0 FUN_c089ebc0 */

/* Boundary evidence: original MIPS .pdata c089ebc0..c089ee9b. Semantic name remains unreviewed. */

undefined4 FUN_c089ebc0(double param_1,double param_2,undefined4 param_3,int param_4)

{
  uint *puVar1;
  uint3 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  undefined4 local_50;
  byte *local_44;
  uint3 *local_40;
  
  iVar4 = *(int *)(param_4 + 4);
  iVar5 = *(int *)(*(int *)(param_4 + 0xc) + 8);
  iVar6 = *(int *)(iVar4 + 8);
  puVar1 = *(uint **)(param_4 + 0x2c);
  uVar12 = *(uint *)(param_4 + 0x20) & 0xffffff;
  piVar11 = *(int **)(param_4 + 0x14);
  iVar3 = *(int *)(iVar4 + 0x38);
  local_44 = (byte *)(puVar1[1] * iVar5 + ((int)*puVar1 >> 1) +
                     *(int *)(*(int *)(param_4 + 0xc) + 4));
  local_40 = (uint3 *)(piVar11[1] * iVar6 + *piVar11 * 3 + *(int *)(iVar4 + 4));
  if (DAT_c08be97c == '\0') {
    FUN_c089e5a4(0x18);
    FUN_c089e6f8(param_1,param_2);
    DAT_c08be97c = '\x01';
  }
  DAT_c08be8ec = ((DAT_c08be8c8 & uVar12) >> (DAT_c08be8d8 & 0x1f)) << (DAT_c08be8d4 & 0x1f);
  DAT_c08be8f0 = ((DAT_c08be8cc & uVar12) >> (DAT_c08be8e0 & 0x1f)) << (DAT_c08be8dc & 0x1f);
  DAT_c08be8f4 = ((DAT_c08be8d0 & uVar12) >> (DAT_c08be8e8 & 0x1f)) << (DAT_c08be8e4 & 0x1f);
  iVar4 = piVar11[1];
  if (iVar4 < piVar11[3]) {
    do {
      iVar8 = *piVar11;
      uVar10 = *puVar1 & 1;
      puVar2 = local_40;
      pbVar9 = local_44;
      if (iVar8 < piVar11[2]) {
        do {
          if (uVar10 == 0) {
            uVar7 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar7 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          uVar10 = (uint)(uVar10 == 0);
          if (uVar7 != 0) {
            if (iVar3 != 0) {
              puVar2 = (uint3 *)FUN_c08947dc(*(int *)(param_4 + 4),iVar8,iVar4);
            }
            local_50 = uVar12;
            if (uVar7 != 0xf) {
              local_50 = FUN_c089e498(&DAT_c08be8c8,(uint)*puVar2,uVar7);
            }
            *(undefined1 *)puVar2 = (undefined1)local_50;
            *(undefined1 *)((int)puVar2 + 1) = local_50._1_1_;
            *(undefined1 *)((int)puVar2 + 2) = local_50._2_1_;
          }
          iVar8 = iVar8 + 1;
          puVar2 = (uint3 *)((int)puVar2 + 3);
        } while (iVar8 < piVar11[2]);
      }
      local_44 = local_44 + iVar5;
      local_40 = (uint3 *)((int)local_40 + iVar6);
      iVar4 = iVar4 + 1;
    } while (iVar4 < piVar11[3]);
  }
  return 0;
}



/* c089ee9c FUN_c089ee9c */

/* Boundary evidence: original MIPS .pdata c089ee9c..c089f137. Semantic name remains unreviewed. */

undefined4 FUN_c089ee9c(double param_1,double param_2,undefined4 param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  byte *local_40;
  uint *local_3c;
  
  iVar4 = *(int *)(param_4 + 4);
  iVar5 = *(int *)(*(int *)(param_4 + 0xc) + 8);
  iVar12 = *(int *)(iVar4 + 8);
  puVar1 = *(uint **)(param_4 + 0x2c);
  uVar6 = *(uint *)(param_4 + 0x20);
  piVar11 = *(int **)(param_4 + 0x14);
  iVar3 = *(int *)(iVar4 + 0x38);
  local_40 = (byte *)(puVar1[1] * iVar5 + ((int)*puVar1 >> 1) +
                     *(int *)(*(int *)(param_4 + 0xc) + 4));
  local_3c = (uint *)(iVar12 * piVar11[1] + *piVar11 * 4 + *(int *)(iVar4 + 4));
  if (DAT_c08be97c == '\0') {
    FUN_c089e5a4(0x20);
    FUN_c089e6f8(param_1,param_2);
    DAT_c08be97c = '\x01';
  }
  DAT_c08be8ec = ((DAT_c08be8c8 & uVar6) >> (DAT_c08be8d8 & 0x1f)) << (DAT_c08be8d4 & 0x1f);
  DAT_c08be8f0 = ((DAT_c08be8cc & uVar6) >> (DAT_c08be8e0 & 0x1f)) << (DAT_c08be8dc & 0x1f);
  DAT_c08be8f4 = ((DAT_c08be8d0 & uVar6) >> (DAT_c08be8e8 & 0x1f)) << (DAT_c08be8e4 & 0x1f);
  iVar4 = piVar11[1];
  if (iVar4 < piVar11[3]) {
    do {
      iVar8 = *piVar11;
      uVar10 = *puVar1 & 1;
      puVar2 = local_3c;
      pbVar9 = local_40;
      if (iVar8 < piVar11[2]) {
        do {
          if (uVar10 == 0) {
            uVar7 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar7 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          uVar10 = (uint)(uVar10 == 0);
          if (uVar7 != 0) {
            if (iVar3 != 0) {
              puVar2 = (uint *)FUN_c08947dc(*(int *)(param_4 + 4),iVar8,iVar4);
            }
            if (uVar7 == 0xf) {
              *puVar2 = uVar6;
            }
            else {
              uVar7 = FUN_c089e498(&DAT_c08be8c8,*puVar2,uVar7);
              *puVar2 = uVar7;
            }
          }
          iVar8 = iVar8 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar8 < piVar11[2]);
      }
      local_40 = local_40 + iVar5;
      local_3c = (uint *)((int)local_3c + iVar12);
      iVar4 = iVar4 + 1;
    } while (iVar4 < piVar11[3]);
  }
  return 0;
}



/* c089f138 FUN_c089f138 */

undefined4 FUN_c089f138(undefined4 *param_1)

{
  int iVar1;
  
  if (((param_1[10] & 0xffff) == 0xaaf0) && (*(int *)(param_1[3] + 0x1c) == 2)) {
    iVar1 = *(int *)(&LAB_c0891154 + *(int *)(param_1[1] + 0x1c) * 4);
    if (iVar1 < 0x19) {
      if (iVar1 == 0x18) {
        *param_1 = FUN_c089ebc0;
        return 0;
      }
      if (iVar1 == 8) {
        *param_1 = FUN_c089e104;
        return 0;
      }
      if (iVar1 == 0x10) {
        *param_1 = FUN_c089e918;
        return 0;
      }
    }
    else if (iVar1 == 0x20) {
      *param_1 = FUN_c089ee9c;
    }
  }
  return 0;
}



/* c089f214 FUN_c089f214 */

uint FUN_c089f214(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = 0x7fffffff;
  uVar7 = 0;
  uVar6 = 0;
  if (0 < DAT_c08bebb0) {
    pbVar1 = (byte *)(DAT_c08beba8 + 2);
    do {
      iVar2 = (param_1 >> 8 & 0xff) - (uint)pbVar1[-1];
      iVar4 = (param_1 & 0xff) - (uint)pbVar1[-2];
      iVar3 = (param_1 >> 0x10 & 0xff) - (uint)*pbVar1;
      uVar5 = iVar3 * iVar3 + iVar2 * iVar2 + iVar4 * iVar4;
      if (uVar5 == 0) {
        return uVar6;
      }
      if (uVar5 < uVar8) {
        uVar7 = uVar6;
        uVar8 = uVar5;
      }
      uVar6 = uVar6 + 1 & 0xffff;
      pbVar1 = pbVar1 + 4;
    } while ((int)uVar6 < DAT_c08bebb0);
  }
  return uVar7;
}



/* c089f2dc FUN_c089f2dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c089f2dc..c089f713. Semantic name remains unreviewed. */

void FUN_c089f2dc(int param_1,uint *param_2,uint param_3,uint param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  uint *puVar12;
  undefined2 *puVar13;
  int local_50;
  
  iVar5 = DAT_c08beba8;
  DAT_c08beba0 = DAT_c08b1544;
  DAT_c08beba4 = *(undefined4 *)(param_5 + 0x48);
  DAT_c08beb94 = param_3;
  DAT_c08beb98 = param_4;
  DAT_c08beb9c = param_1;
  if (param_1 == 1) {
    uVar9 = *(uint *)(param_3 * 4 + DAT_c08beba8);
    uVar4 = param_2[0xc];
    param_2[9] = (uint)*(byte *)((uVar9 & 0xff) + uVar4);
    param_2[10] = (uint)*(byte *)((uVar9 >> 8 & 0xff) + uVar4);
    param_2[0xb] = (uint)*(byte *)((uVar9 >> 0x10 & 0xff) + uVar4);
    uVar6 = *(uint *)(param_4 * 4 + iVar5);
    uVar8 = (uint)*(byte *)((uVar6 & 0xff) + uVar4);
    uVar9 = (uint)*(byte *)((uVar6 >> 0x10 & 0xff) + uVar4);
    uVar6 = (uint)*(byte *)((uVar6 >> 8 & 0xff) + uVar4);
    local_50 = param_2[9] - uVar8;
    iVar7 = param_2[10] - uVar6;
    iVar5 = param_2[0xb] - uVar9;
  }
  else {
    uVar9 = param_2[0xc];
    param_2[9] = (uint)*(byte *)((((param_2[6] & param_3) << (*param_2 & 0x1f)) >>
                                  (param_2[1] & 0x1f) & 0xff) + uVar9);
    param_2[10] = (uint)*(byte *)((((param_2[7] & param_3) << (param_2[2] & 0x1f)) >>
                                   (param_2[3] & 0x1f) & 0xff) + uVar9);
    uVar4 = (uint)*(byte *)((((param_2[8] & param_3) << (param_2[4] & 0x1f)) >> (param_2[5] & 0x1f)
                            & 0xff) + uVar9);
    param_2[0xb] = uVar4;
    uVar8 = (uint)*(byte *)((((param_2[6] & param_4) << (*param_2 & 0x1f)) >> (param_2[1] & 0x1f) &
                            0xff) + uVar9);
    uVar6 = (uint)*(byte *)((((param_2[7] & param_4) << (param_2[2] & 0x1f)) >> (param_2[3] & 0x1f)
                            & 0xff) + uVar9);
    local_50 = param_2[9] - uVar8;
    uVar9 = (uint)*(byte *)((((param_2[8] & param_4) << (param_2[4] & 0x1f)) >> (param_2[5] & 0x1f)
                            & 0xff) + uVar9);
    iVar7 = param_2[10] - uVar6;
    iVar5 = uVar4 - uVar9;
  }
  iVar10 = 1;
  pbVar11 = &DAT_c08b2ea4;
  puVar12 = &DAT_c08be9cc;
  puVar13 = &DAT_c08be9ca;
  do {
    uVar4 = param_2[0xd];
    bVar1 = *(byte *)((*(int *)(&DAT_c08b1584 + (uint)*pbVar11 * 4) * local_50 + 0x80000 >> 0x14) +
                      uVar4 + uVar8);
    bVar2 = *(byte *)((*(int *)(&DAT_c08b1584 + (uint)pbVar11[1] * 4) * iVar7 + 0x80000 >> 0x14) +
                      uVar4 + uVar6);
    bVar3 = *(byte *)((*(int *)(&DAT_c08b1584 + (uint)pbVar11[2] * 4) * iVar5 + 0x80000 >> 0x14) +
                      uVar4 + uVar9);
    if (param_1 == 1) {
      uVar4 = (uint)CONCAT21(CONCAT11(bVar3,bVar2),bVar1);
LAB_c089f5f0:
      uVar4 = FUN_c089f214(uVar4);
      (&DAT_c08be9c8)[iVar10] = (char)uVar4;
    }
    else {
      uVar4 = ((uint)bVar3 << (param_2[5] & 0x1f)) >> (param_2[4] & 0x1f) & param_2[8] |
              ((uint)bVar2 << (param_2[3] & 0x1f)) >> (param_2[2] & 0x1f) & param_2[7] |
              ((uint)bVar1 << (param_2[1] & 0x1f)) >> (*param_2 & 0x1f) & param_2[6];
      if (param_1 == 2) {
        *puVar13 = (short)uVar4;
      }
      else {
        if (param_1 != 4) goto LAB_c089f5f0;
        *puVar12 = uVar4;
      }
    }
    iVar10 = iVar10 + 1;
    puVar13 = puVar13 + 1;
    puVar12 = puVar12 + 1;
    pbVar11 = pbVar11 + 4;
    if (0x71 < iVar10) {
      if (param_1 == 2) {
        _DAT_c08be9c8 = CONCAT22(DAT_c08be9ca,(short)param_4);
        DAT_c08beaac = (undefined2)param_3;
        uVar9 = _DAT_c08be9c8;
        uVar8 = DAT_c08beb90;
      }
      else {
        uVar9 = param_4;
        uVar8 = param_3;
        if (param_1 != 4) {
          _DAT_c08be9c8 = CONCAT31(_DAT_c08be9c9,(char)param_4);
          DAT_c08bea3a = (undefined1)param_3;
          uVar9 = _DAT_c08be9c8;
          uVar8 = DAT_c08beb90;
        }
      }
      DAT_c08beb90 = uVar8;
      _DAT_c08be9c8 = uVar9;
      return;
    }
  } while( true );
}



/* c089f714 FUN_c089f714 */

/* Boundary evidence: original MIPS .pdata c089f714..c089f8af. Semantic name remains unreviewed. */

uint FUN_c089f714(uint *param_1,uint param_2,byte *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1[0xc];
  uVar1 = (uint)*(byte *)((((param_1[6] & param_2) << (*param_1 & 0x1f)) >> (param_1[1] & 0x1f) &
                          0xff) + uVar3);
  uVar4 = param_1[0xd];
  uVar2 = (uint)*(byte *)((((param_1[7] & param_2) << (param_1[2] & 0x1f)) >> (param_1[3] & 0x1f) &
                          0xff) + uVar3);
  uVar3 = (uint)*(byte *)((((param_1[8] & param_2) << (param_1[4] & 0x1f)) >> (param_1[5] & 0x1f) &
                          0xff) + uVar3);
  return ((uint)*(byte *)(((int)(*(int *)(&DAT_c08b1584 + (uint)param_3[2] * 4) *
                                 (param_1[0xb] - uVar3) + 0x80000) >> 0x14) + uVar4 + uVar3) <<
         (param_1[5] & 0x1f)) >> (param_1[4] & 0x1f) & param_1[8] |
         ((uint)*(byte *)(((int)(*(int *)(&DAT_c08b1584 + (uint)param_3[1] * 4) *
                                 (param_1[10] - uVar2) + 0x80000) >> 0x14) + uVar4 + uVar2) <<
         (param_1[3] & 0x1f)) >> (param_1[2] & 0x1f) & param_1[7] |
         ((uint)*(byte *)(((int)(*(int *)(&DAT_c08b1584 + (uint)*param_3 * 4) * (param_1[9] - uVar1)
                                + 0x80000) >> 0x14) + uVar4 + uVar1) << (param_1[1] & 0x1f)) >>
         (*param_1 & 0x1f) & param_1[6];
}



/* c089f8b0 FUN_c089f8b0 */

/* Boundary evidence: original MIPS .pdata c089f8b0..c089f9e3. Semantic name remains unreviewed. */

void FUN_c089f8b0(int param_1,int param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *(uint *)(param_2 * 4 + DAT_c08beba8);
  iVar2 = *(int *)(param_1 + 0x30);
  uVar4 = (uint)*(byte *)((uVar3 & 0xff) + iVar2);
  iVar1 = *(int *)(param_1 + 0x34);
  uVar5 = (uint)*(byte *)((uVar3 >> 8 & 0xff) + iVar2);
  uVar3 = (uint)*(byte *)((uVar3 >> 0x10 & 0xff) + iVar2);
  FUN_c089f214((uint)CONCAT12(*(undefined1 *)
                               (((int)(*(int *)(&DAT_c08b1584 + (uint)param_3[2] * 4) *
                                       (*(int *)(param_1 + 0x2c) - uVar3) + 0x80000) >> 0x14) +
                                iVar1 + uVar3),
                              CONCAT11(*(undefined1 *)
                                        (((int)(*(int *)(&DAT_c08b1584 + (uint)param_3[1] * 4) *
                                                (*(int *)(param_1 + 0x28) - uVar5) + 0x80000) >>
                                         0x14) + iVar1 + uVar5),
                                       *(undefined1 *)
                                        (((int)(*(int *)(&DAT_c08b1584 + (uint)*param_3 * 4) *
                                                (*(int *)(param_1 + 0x24) - uVar4) + 0x80000) >>
                                         0x14) + iVar1 + uVar4))));
  return;
}



/* c089f9e4 FUN_c089f9e4 */

void FUN_c089f9e4(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  DAT_c08be9a4 = param_1;
  DAT_c08be9a8 = param_2;
  iVar1 = 0;
  DAT_c08be9ac = param_3;
  for (; param_1 != 0; param_1 = param_1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c08be990 = iVar1 + -8;
  iVar1 = 0;
  for (; param_2 != 0; param_2 = param_2 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c08be998 = iVar1 + -8;
  iVar1 = 0;
  for (; param_3 != 0; param_3 = param_3 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c08be9a0 = iVar1 + -8;
  DAT_c08be98c = 0;
  if (DAT_c08be990 < 0) {
    DAT_c08be98c = -DAT_c08be990;
    DAT_c08be990 = 0;
  }
  DAT_c08be994 = 0;
  if (DAT_c08be998 < 0) {
    DAT_c08be994 = -DAT_c08be998;
    DAT_c08be998 = 0;
  }
  DAT_c08be99c = 0;
  if (DAT_c08be9a0 < 0) {
    DAT_c08be99c = -DAT_c08be9a0;
    DAT_c08be9a0 = 0;
  }
  DAT_c08beb9c = 0;
  return;
}



/* c089faac FUN_c089faac */

void FUN_c089faac(uint param_1)

{
  DAT_c08b1544 = param_1;
  DAT_c08beba0 = 0;
  if (param_1 < 0x44c) {
    DAT_c08be9c0 = &DAT_c08b15a0;
    DAT_c08be9bc = &DAT_c08b15a0;
  }
  else if (param_1 < 0x4b0) {
    DAT_c08be9bc = &DAT_c08b16a0;
    DAT_c08be9c0 = &DAT_c08b17a0;
  }
  else if (param_1 < 0x514) {
    DAT_c08be9bc = &DAT_c08b18a0;
    DAT_c08be9c0 = &DAT_c08b19a0;
  }
  else if (param_1 < 0x578) {
    DAT_c08be9bc = &DAT_c08b1aa0;
    DAT_c08be9c0 = &DAT_c08b1ba0;
  }
  else if (param_1 < 0x5dc) {
    DAT_c08be9bc = &DAT_c08b1ca0;
    DAT_c08be9c0 = &DAT_c08b1da0;
  }
  else if (param_1 < 0x640) {
    DAT_c08be9bc = &DAT_c08b1ea0;
    DAT_c08be9c0 = &DAT_c08b1fa0;
  }
  else if (param_1 < 0x6a4) {
    DAT_c08be9bc = &DAT_c08b20a0;
    DAT_c08be9c0 = &DAT_c08b21a0;
  }
  else if (param_1 < 0x708) {
    DAT_c08be9bc = &DAT_c08b22a0;
    DAT_c08be9c0 = &DAT_c08b23a0;
  }
  else if (param_1 < 0x76c) {
    DAT_c08be9bc = &DAT_c08b24a0;
    DAT_c08be9c0 = &DAT_c08b25a0;
  }
  else if (param_1 < 2000) {
    DAT_c08be9bc = &DAT_c08b26a0;
    DAT_c08be9c0 = &DAT_c08b27a0;
  }
  else if (param_1 < 0x834) {
    DAT_c08be9bc = &DAT_c08b28a0;
    DAT_c08be9c0 = &DAT_c08b29a0;
  }
  else if (param_1 < 0x898) {
    DAT_c08be9bc = &DAT_c08b2aa0;
    DAT_c08be9c0 = &DAT_c08b2ba0;
  }
  else {
    DAT_c08be9bc = &DAT_c08b2ca0;
    DAT_c08be9c0 = &DAT_c08b2da0;
  }
  return;
}



/* c089fc64 FUN_c089fc64 */

undefined4 FUN_c089fc64(undefined4 *param_1)

{
  *param_1 = DAT_c08b1544;
  return 1;
}



/* c089fc78 FUN_c089fc78 */

/* Boundary evidence: original MIPS .pdata c089fc78..c089fd53. Semantic name remains unreviewed. */

undefined4 FUN_c089fc78(uint param_1,int param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  uint local_res0 [4];
  HKEY local_10;
  DWORD DStack_c;
  
  local_res0[0] = param_1;
  if (param_2 == 0) {
LAB_c089fd3c:
    FUN_c089faac(local_res0[0]);
    uVar2 = 1;
  }
  else {
    LVar1 = RegCreateKeyExW((HKEY)0x80000002,u_System_GDI_Gamma_c08b1548,0,(LPWSTR)0x0,0,0,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_10,&DStack_c);
    if (LVar1 == 0) {
      LVar1 = RegSetValueExW(local_10,u_Gamma_Value_c08b156c,0,4,(BYTE *)local_res0,4);
      if (LVar1 == 0) {
        RegCloseKey(local_10);
        goto LAB_c089fd3c;
      }
      RegCloseKey(local_10);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* c089fd54 FUN_c089fd54 */

/* Boundary evidence: original MIPS .pdata c089fd54..c089fe5f. Semantic name remains unreviewed. */

void FUN_c089fd54(uint param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  if (param_1 < 2) {
    DAT_c08beba8 = *(int *)(param_3 + 0xc);
    if ((DAT_c08beba8 == 0) || (DAT_c08bebb0 = *(int *)(param_3 + 0x10), DAT_c08bebb0 == 0)) {
      DAT_c08beba8 = DAT_c08bebac;
      DAT_c08bebb0 = DAT_c08bebb4;
    }
  }
  else {
    iVar4 = *(int *)(param_3 + 0x10);
    uVar1 = DAT_c08be980;
    uVar2 = DAT_c08be984;
    uVar3 = DAT_c08be988;
    if ((iVar4 != 0) && (puVar5 = *(uint **)(param_3 + 0xc), puVar5 != (uint *)0x0)) {
      if ((iVar4 == 3) || (iVar4 == 4)) {
        uVar1 = *puVar5;
        uVar2 = puVar5[1];
        uVar3 = puVar5[2];
      }
      else if (param_1 == 2) {
        uVar1 = 0xf800;
        uVar2 = 0x7e0;
        uVar3 = 0x1f;
      }
      else if (param_1 == 4) {
        uVar1 = 0xff0000;
        uVar2 = 0xff00;
        uVar3 = 0xff;
      }
      else {
        uVar1 = 0;
        uVar2 = 0;
        uVar3 = 0;
      }
    }
    FUN_c089f9e4(uVar1,uVar2,uVar3);
  }
  return;
}



/* c089fe60 FUN_c089fe60 */

/* Boundary evidence: original MIPS .pdata c089fe60..c089ff4b. Semantic name remains unreviewed. */

undefined1 * FUN_c089fe60(uint param_1,uint param_2,uint param_3,int param_4,uint *param_5)

{
  if ((((*(int *)(param_4 + 0x48) != DAT_c08beba4) || (param_3 != DAT_c08beb98)) ||
      (param_2 != DAT_c08beb94)) ||
     (((param_1 != DAT_c08beb9c || (DAT_c08b1544 != DAT_c08beba0)) ||
      ((param_1 == 1 && (DAT_c08beba8 == 0)))))) {
    FUN_c089fd54(param_1,param_2,param_4);
    FUN_c089f2dc(param_1,param_5,param_2,param_3,param_4);
  }
  return &DAT_c08be9c8;
}



/* c089ff4c FUN_c089ff4c */

/* Boundary evidence: original MIPS .pdata c089ff4c..c08a00f3. Semantic name remains unreviewed. */

undefined4 FUN_c089ff4c(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  uint local_30;
  HKEY local_2c;
  uint local_28;
  DWORD local_24 [3];
  
  local_28 = 0x5dc;
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    uVar4 = 0;
    uVar1 = DAT_c08bebac;
    uVar2 = DAT_c08bebb4;
  }
  else {
    LVar3 = RegCreateKeyExW((HKEY)0x80000002,u_System_GDI_Gamma_c08b1548,0,(LPWSTR)0x0,0,0,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_2c,&local_30);
    uVar4 = 1;
    if (LVar3 == 0) {
      if (local_30 == 2) {
        local_24[1] = 4;
        local_24[0] = 4;
        LVar3 = RegQueryValueExW(local_2c,u_Gamma_Value_c08b156c,(LPDWORD)0x0,local_24 + 1,
                                 (LPBYTE)&local_30,local_24);
        if (LVar3 == 0) {
          local_28 = local_30;
        }
      }
      else if (local_30 == 1) {
        RegSetValueExW(local_2c,u_Gamma_Value_c08b156c,0,4,(BYTE *)&local_28,4);
      }
      RegCloseKey(local_2c);
    }
    FUN_c089faac(local_28);
    uVar1 = param_3;
    uVar2 = param_4;
    if (8 < *(int *)(param_1 + 0xc)) {
      DAT_c08be980 = *param_2;
      DAT_c08be984 = param_2[1];
      DAT_c08be988 = param_2[2];
      uVar1 = DAT_c08bebac;
      uVar2 = DAT_c08bebb4;
    }
  }
  DAT_c08bebb4 = uVar2;
  DAT_c08bebac = uVar1;
  return uVar4;
}



/* c08a00f4 FUN_c08a00f4 */

/* Boundary evidence: original MIPS .pdata c08a00f4..c08a035f. Semantic name remains unreviewed. */

undefined4 FUN_c08a00f4(undefined4 param_1,int param_2)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  undefined1 *puVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  ushort *puVar11;
  int iVar12;
  byte *pbVar13;
  byte *pbVar14;
  ushort *local_48;
  
  iVar6 = *(int *)(param_2 + 4);
  puVar7 = *(ushort **)(*(int *)(param_2 + 0xc) + 8);
  uVar2 = *(ushort *)(param_2 + 0x20);
  iVar10 = *(int *)(iVar6 + 8);
  piVar9 = *(int **)(param_2 + 0x14);
  bVar1 = *(int *)(iVar6 + 0x38) != 0;
  pbVar14 = (byte *)((*(int **)(param_2 + 0x2c))[1] * (int)puVar7 + **(int **)(param_2 + 0x2c) +
                    *(int *)(*(int *)(param_2 + 0xc) + 4));
  if (bVar1) {
    puVar11 = (ushort *)FUN_c08947dc(*(int *)(param_2 + 4),*piVar9,piVar9[1]);
  }
  else {
    puVar11 = (ushort *)(piVar9[1] * iVar10 + *piVar9 * 2 + *(int *)(iVar6 + 4));
  }
  uVar3 = *puVar11;
  puVar4 = FUN_c089fe60(2,(uint)uVar2,(uint)uVar3,*(int *)(param_2 + 4),&DAT_c08be98c);
  iVar6 = piVar9[1];
  puVar5 = puVar7;
  local_48 = puVar11;
  if (iVar6 < piVar9[3]) {
    do {
      if (!bVar1) {
        puVar5 = puVar11;
      }
      iVar12 = *piVar9;
      pbVar13 = pbVar14;
      if (iVar12 < piVar9[2]) {
        do {
          uVar8 = (uint)*pbVar13;
          if (uVar8 != 0) {
            if (bVar1) {
              puVar5 = (ushort *)FUN_c08947dc(*(int *)(param_2 + 4),iVar12,iVar6);
            }
            if (uVar8 == 0x72) {
              *puVar5 = uVar2;
            }
            else if ((uint)*puVar5 == (uint)uVar3) {
              *puVar5 = *(ushort *)(puVar4 + uVar8 * 2);
            }
            else {
              uVar8 = FUN_c089f714(&DAT_c08be98c,(uint)*puVar5,&DAT_c08b2ea0 + uVar8 * 4);
              *puVar5 = (ushort)uVar8;
            }
          }
          if (!bVar1) {
            puVar5 = puVar5 + 1;
          }
          iVar12 = iVar12 + 1;
          puVar11 = local_48;
          pbVar13 = pbVar13 + 1;
        } while (iVar12 < piVar9[2]);
      }
      if (!bVar1) {
        puVar11 = (ushort *)((int)puVar11 + iVar10);
        local_48 = puVar11;
      }
      pbVar14 = pbVar14 + (int)puVar7;
      iVar6 = iVar6 + 1;
    } while (iVar6 < piVar9[3]);
  }
  return 0;
}



/* c08a0360 FUN_c08a0360 */

/* Boundary evidence: original MIPS .pdata c08a0360..c08a0617. Semantic name remains unreviewed. */

undefined4 FUN_c08a0360(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  uint3 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  uint *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint3 *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint3 *local_50;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  uint3 *local_30;
  
  iVar4 = *(int *)(param_2 + 4);
  local_30 = *(uint3 **)(*(int *)(param_2 + 0xc) + 8);
  local_34 = *(int *)(iVar4 + 8);
  uVar8 = *(uint *)(param_2 + 0x20) & 0xffffff;
  piVar7 = *(int **)(param_2 + 0x14);
  bVar1 = *(int *)(iVar4 + 0x38) != 0;
  pbVar12 = (byte *)((*(int **)(param_2 + 0x2c))[1] * (int)local_30 + **(int **)(param_2 + 0x2c) +
                    *(int *)(*(int *)(param_2 + 0xc) + 4));
  local_40 = uVar8;
  if (bVar1) {
    puVar10 = (uint3 *)FUN_c08947dc(*(int *)(param_2 + 4),*piVar7,piVar7[1]);
  }
  else {
    puVar10 = (uint3 *)(piVar7[1] * local_34 + *piVar7 * 3 + *(int *)(iVar4 + 4));
  }
  local_3c = (uint)*puVar10;
  puVar2 = FUN_c089fe60(4,uVar8,local_3c,*(int *)(param_2 + 4),&DAT_c08be98c);
  iVar4 = piVar7[1];
  puVar3 = local_30;
  local_50 = puVar10;
  if (iVar4 < piVar7[3]) {
    do {
      if (!bVar1) {
        puVar3 = puVar10;
      }
      iVar9 = *piVar7;
      pbVar11 = pbVar12;
      if (iVar9 < piVar7[2]) {
        do {
          if (bVar1) {
            puVar3 = (uint3 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar9,iVar4);
          }
          uVar8 = (uint)*pbVar11;
          if (uVar8 == 0) {
            if (!bVar1) {
              puVar3 = (uint3 *)((int)puVar3 + 3);
            }
          }
          else {
            if (uVar8 == 0x72) {
              puVar6 = &local_40;
            }
            else if (*puVar3 == local_3c) {
              puVar6 = (uint *)(puVar2 + uVar8 * 4);
            }
            else {
              local_38 = FUN_c089f714(&DAT_c08be98c,(uint)*puVar3,&DAT_c08b2ea0 + uVar8 * 4);
              puVar6 = &local_38;
            }
            *(char *)puVar3 = (char)*puVar6;
            *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)puVar6 + 1);
            puVar5 = (undefined1 *)((int)puVar3 + 2);
            puVar3 = (uint3 *)((int)puVar3 + 3);
            *puVar5 = *(undefined1 *)((int)puVar6 + 2);
          }
          iVar9 = iVar9 + 1;
          puVar10 = local_50;
          pbVar11 = pbVar11 + 1;
        } while (iVar9 < piVar7[2]);
      }
      if (!bVar1) {
        puVar10 = (uint3 *)((int)puVar10 + local_34);
        local_50 = puVar10;
      }
      pbVar12 = pbVar12 + (int)local_30;
      iVar4 = iVar4 + 1;
    } while (iVar4 < piVar7[3]);
  }
  return 0;
}



/* c08a0618 FUN_c08a0618 */

/* Boundary evidence: original MIPS .pdata c08a0618..c08a0893. Semantic name remains unreviewed. */

undefined4 FUN_c08a0618(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint *puVar9;
  uint *puVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  byte *pbVar15;
  uint *local_48;
  
  iVar4 = *(int *)(param_2 + 4);
  iVar6 = *(int *)(*(int *)(param_2 + 0xc) + 8);
  iVar12 = *(int *)(iVar4 + 8);
  uVar7 = *(uint *)(param_2 + 0x20);
  piVar8 = *(int **)(param_2 + 0x14);
  bVar1 = *(int *)(iVar4 + 0x38) != 0;
  pbVar11 = (byte *)((*(int **)(param_2 + 0x2c))[1] * iVar6 + *(int *)(*(int *)(param_2 + 0xc) + 4)
                    + **(int **)(param_2 + 0x2c));
  if (bVar1) {
    puVar9 = (uint *)FUN_c08947dc(*(int *)(param_2 + 4),*piVar8,piVar8[1]);
  }
  else {
    puVar9 = (uint *)(iVar12 * piVar8[1] + *piVar8 * 4 + *(int *)(iVar4 + 4));
  }
  uVar3 = *puVar9;
  puVar2 = FUN_c089fe60(4,uVar7,uVar3,*(int *)(param_2 + 4),&DAT_c08be98c);
  iVar4 = piVar8[1];
  local_48 = puVar9;
  if (iVar4 < piVar8[3]) {
    do {
      iVar14 = *piVar8;
      puVar10 = puVar9;
      pbVar15 = pbVar11;
      if (iVar14 < piVar8[2]) {
        do {
          uVar5 = (uint)*pbVar15;
          uVar13 = *puVar9 & 0xff000000;
          if (uVar5 != 0) {
            if (bVar1) {
              puVar9 = (uint *)FUN_c08947dc(*(int *)(param_2 + 4),iVar14,iVar4);
            }
            if (uVar5 == 0x72) {
              *puVar9 = uVar13 | uVar7;
            }
            else if (*puVar9 == uVar3) {
              *puVar9 = *(uint *)(puVar2 + uVar5 * 4) | uVar13;
            }
            else {
              uVar5 = FUN_c089f714(&DAT_c08be98c,*puVar9,&DAT_c08b2ea0 + uVar5 * 4);
              *puVar9 = uVar5 | uVar13;
            }
          }
          if (!bVar1) {
            puVar9 = puVar9 + 1;
          }
          iVar14 = iVar14 + 1;
          puVar10 = local_48;
          pbVar15 = pbVar15 + 1;
        } while (iVar14 < piVar8[2]);
      }
      if (!bVar1) {
        puVar10 = (uint *)((int)puVar10 + iVar12);
        local_48 = puVar10;
      }
      pbVar11 = pbVar11 + iVar6;
      iVar4 = iVar4 + 1;
      puVar9 = puVar10;
    } while (iVar4 < piVar8[3]);
  }
  return 0;
}



/* c08a0894 FUN_c08a0894 */

/* Boundary evidence: original MIPS .pdata c08a0894..c08a0af7. Semantic name remains unreviewed. */

undefined4 FUN_c08a0894(undefined4 param_1,int param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  int *piVar10;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *local_48;
  
  iVar7 = *(int *)(param_2 + 4);
  pbVar9 = *(byte **)(*(int *)(param_2 + 0xc) + 8);
  bVar2 = *(byte *)(param_2 + 0x20);
  iVar11 = *(int *)(iVar7 + 8);
  piVar10 = *(int **)(param_2 + 0x14);
  bVar1 = *(int *)(iVar7 + 0x38) != 0;
  pbVar15 = (byte *)((*(int **)(param_2 + 0x2c))[1] * (int)pbVar9 +
                     *(int *)(*(int *)(param_2 + 0xc) + 4) + **(int **)(param_2 + 0x2c));
  if (bVar1) {
    pbVar12 = (byte *)FUN_c08947dc(*(int *)(param_2 + 4),*piVar10,piVar10[1]);
  }
  else {
    pbVar12 = (byte *)(piVar10[1] * iVar11 + *piVar10 + *(int *)(iVar7 + 4));
  }
  bVar3 = *pbVar12;
  puVar5 = FUN_c089fe60(1,(uint)bVar2,(uint)bVar3,*(int *)(param_2 + 4),&DAT_c08be98c);
  iVar7 = piVar10[1];
  pbVar6 = pbVar9;
  local_48 = pbVar12;
  if (iVar7 < piVar10[3]) {
    do {
      if (!bVar1) {
        pbVar6 = pbVar12;
      }
      iVar13 = *piVar10;
      pbVar14 = pbVar15;
      if (iVar13 < piVar10[2]) {
        do {
          uVar8 = (uint)*pbVar14;
          if (uVar8 != 0) {
            if (bVar1) {
              pbVar6 = (byte *)FUN_c08947dc(*(int *)(param_2 + 4),iVar13,iVar7);
            }
            if (uVar8 == 0x72) {
              *pbVar6 = bVar2;
            }
            else if ((uint)*pbVar6 == (uint)bVar3) {
              *pbVar6 = puVar5[uVar8];
            }
            else {
              bVar4 = FUN_c089f8b0(-0x3f741674,(uint)*pbVar6,&DAT_c08b2ea0 + uVar8 * 4);
              *pbVar6 = bVar4;
            }
          }
          if (!bVar1) {
            pbVar6 = pbVar6 + 1;
          }
          iVar13 = iVar13 + 1;
          pbVar12 = local_48;
          pbVar14 = pbVar14 + 1;
        } while (iVar13 < piVar10[2]);
      }
      if (!bVar1) {
        pbVar12 = pbVar12 + iVar11;
        local_48 = pbVar12;
      }
      pbVar15 = pbVar15 + (int)pbVar9;
      iVar7 = iVar7 + 1;
    } while (iVar7 < piVar10[3]);
  }
  return 0;
}



/* c08a0af8 FUN_c08a0af8 */

undefined4 FUN_c08a0af8(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((param_1[10] & 0xffff) != 0xaaf0) {
    return 0;
  }
  if (*(int *)(param_1[3] + 0x1c) != 3) {
    return 0;
  }
  iVar2 = *(int *)(&LAB_c0891154 + *(int *)(param_1[1] + 0x1c) * 4);
  if (iVar2 == 8) {
    pcVar1 = FUN_c08a0894;
LAB_c08a0b9c:
    *param_1 = pcVar1;
  }
  else {
    if (iVar2 == 0x10) {
      pcVar1 = FUN_c08a00f4;
    }
    else {
      if (iVar2 == 0x18) {
        pcVar1 = FUN_c08a0360;
        goto LAB_c08a0b9c;
      }
      if (iVar2 != 0x20) {
        return 0;
      }
      pcVar1 = FUN_c08a0618;
    }
    *param_1 = pcVar1;
  }
  return 0;
}



/* c08a0ba8 FUN_c08a0ba8 */

/* Boundary evidence: original MIPS .pdata c08a0ba8..c08a0c8f. Semantic name remains unreviewed. */

int * FUN_c08a0ba8(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  
  piVar1 = param_1 + 1;
  *piVar1 = (int)&PTR_FUN_c089104c;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0xb] = 0;
  if (param_2 == (int *)0x0) {
    *param_1 = 0;
  }
  else if (param_2 == param_3) {
    *param_1 = *param_4;
  }
  else if (*param_2 == 0) {
    *param_1 = (int)piVar1;
    FUN_c0894510((int)piVar1,param_2[4],param_2[5],param_2[8],param_2[9],
                 *(int *)(&LAB_c089119c + param_2[0xb] * 4));
    *(int *)(*param_1 + 0x48) = param_2[1];
    if ((*(ushort *)((int)param_2 + 0x32) & 8) != 0) {
      *(undefined4 *)(*param_1 + 0x24) = 1;
    }
  }
  else {
    *param_1 = *param_2;
  }
  return param_1;
}



/* c08a0c90 FUN_c08a0c90 */

/* Boundary evidence: original MIPS .pdata c08a0c90..c08a0cef. Semantic name remains unreviewed. */

undefined4 * FUN_c08a0c90(undefined4 *param_1,int param_2)

{
  HLOCAL pvVar1;
  
  pvVar1 = LocalAlloc(0,param_2 * 0x34);
  *param_1 = pvVar1;
  if (pvVar1 == (HLOCAL)0x0) {
    param_2 = 0;
  }
  param_1[4] = param_2;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  return param_1;
}



/* c08a0cf0 FUN_c08a0cf0 */

/* Boundary evidence: original MIPS .pdata c08a0cf0..c08a0d17. Semantic name remains unreviewed. */

void FUN_c08a0cf0(undefined4 *param_1)

{
  if ((HLOCAL)*param_1 != (HLOCAL)0x0) {
    LocalFree((HLOCAL)*param_1);
  }
  return;
}



/* c08a0d18 FUN_c08a0d18 */

/* Boundary evidence: original MIPS .pdata c08a0d18..c08a105b. Semantic name remains unreviewed. */

undefined4 FUN_c08a0d18(int *param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  HLOCAL pvVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = param_1[4];
  if (iVar2 <= param_1[5]) {
    if ((HLOCAL)*param_1 == (HLOCAL)0x0) {
      pvVar1 = LocalAlloc(0,(iVar2 + 200) * 0x34);
    }
    else {
      pvVar1 = LocalReAlloc((HLOCAL)*param_1,(iVar2 + 200) * 0x34,2);
    }
    if (pvVar1 == (HLOCAL)0x0) {
      return 0x8007000e;
    }
    *param_1 = (int)pvVar1;
    param_1[4] = param_1[4] + 200;
  }
  if ((int)param_3 < (int)param_5) {
    *(undefined4 *)(param_1[5] * 0x34 + *param_1 + 0x18) = 1;
    uVar3 = param_5;
    iVar2 = param_2;
  }
  else {
    *(undefined4 *)(param_1[5] * 0x34 + *param_1 + 0x18) = 0xffffffff;
    uVar3 = param_3;
    param_3 = param_5;
    iVar2 = param_4;
    param_4 = param_2;
  }
  if ((int)(param_3 + 0xf & 0xfffffff0) < (int)(uVar3 + 0xf & 0xfffffff0)) {
    iVar6 = param_4 - iVar2;
    iVar5 = uVar3 - param_3;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar4 = 0;
    while ((param_3 & 0xf) != 0) {
      param_3 = param_3 + 1;
      iVar2 = iVar6 / iVar5 + iVar2;
      iVar4 = iVar4 + iVar6 % iVar5;
      if (iVar6 % iVar5 < 0) {
        if (iVar4 <= -iVar5) {
          iVar4 = iVar4 + iVar5;
          iVar2 = iVar2 + -1;
        }
      }
      else if (0 < iVar4) {
        iVar4 = iVar4 - iVar5;
        iVar2 = iVar2 + 1;
      }
    }
    *(int *)(param_1[5] * 0x34 + *param_1) = (int)param_3 >> 4;
    *(int *)(param_1[5] * 0x34 + *param_1 + 8) = (int)(uVar3 + 0xf) >> 4;
    *(int *)(param_1[5] * 0x34 + *param_1 + 0x1c) = iVar2;
    iVar6 = iVar6 * 0x10;
    *(undefined4 *)(param_1[5] * 0x34 + *param_1 + 4) = 0;
    *(undefined4 *)(param_1[5] * 0x34 + *param_1 + 0xc) = 0;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    *(int *)(param_1[5] * 0x34 + *param_1 + 0x20) = iVar6 / iVar5;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    *(int *)(param_1[5] * 0x34 + *param_1 + 0x24) = iVar6 % iVar5;
    *(int *)(param_1[5] * 0x34 + *param_1 + 0x30) = iVar5;
    *(int *)(param_1[5] * 0x34 + *param_1 + 0x2c) = iVar4;
    param_1[5] = param_1[5] + 1;
  }
  return 0;
}



/* c08a105c FUN_c08a105c */

/* Boundary evidence: original MIPS .pdata c08a105c..c08a14bb. Semantic name remains unreviewed. */

int FUN_c08a105c(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined1 local_38 [16];
  
  param_2[5] = local_38;
  if (0 < param_1[5]) {
    piVar7 = param_1 + 1;
    piVar9 = (int *)*piVar7;
    if (piVar9 == (int *)0x0) {
      piVar9 = (int *)*param_1;
      iVar11 = 0;
      if (0 < param_1[5]) {
        piVar6 = param_1 + 2;
        do {
          piVar2 = (int *)*piVar7;
          piVar4 = piVar7;
          if (piVar2 != (int *)0x0) {
            do {
              if (*piVar9 <= *piVar2) break;
              piVar4 = piVar2 + 1;
              piVar2 = (int *)*piVar4;
            } while (piVar2 != (int *)0x0);
          }
          piVar9[1] = *piVar4;
          *piVar4 = (int)piVar9;
          iVar3 = *piVar6;
          piVar4 = piVar6;
          if (iVar3 != 0) {
            do {
              if (piVar9[2] <= *(int *)(iVar3 + 8)) break;
              piVar4 = (int *)(iVar3 + 0xc);
              iVar3 = *piVar4;
            } while (iVar3 != 0);
          }
          if (*piVar4 == 0) {
            param_1[7] = piVar9[2];
          }
          iVar11 = iVar11 + 1;
          piVar9[3] = *piVar4;
          *piVar4 = (int)piVar9;
          piVar9 = piVar9 + 0xd;
        } while (iVar11 < param_1[5]);
      }
      piVar9 = (int *)*piVar7;
      param_1[6] = *piVar9;
    }
    if ((param_3 == (int *)0x0) || ((param_1[6] < param_3[3] && (param_3[1] <= param_1[7])))) {
      piVar7 = param_1 + 3;
      iVar11 = param_1[2];
      *piVar7 = 0;
      iVar3 = param_1[6];
      while ((iVar3 < param_1[7] && ((param_3 == (int *)0x0 || (iVar3 < param_3[3]))))) {
        iVar10 = iVar3 + 1;
        *(int *)(param_2[5] + 4) = iVar3;
        *(int *)(param_2[5] + 0xc) = iVar10;
        for (; (piVar9 != (int *)0x0 && (*piVar9 <= iVar3)); piVar9 = (int *)piVar9[1]) {
          piVar9[10] = piVar9[0xb];
          piVar9[4] = piVar9[7];
          piVar6 = piVar7;
          while ((iVar5 = *piVar6, iVar5 != 0 && (*(int *)(iVar5 + 0x10) < piVar9[7]))) {
            piVar6 = (int *)(iVar5 + 0x14);
          }
          piVar9[5] = *piVar6;
          *piVar6 = (int)piVar9;
        }
        for (; (iVar11 != 0 && (piVar6 = piVar7, *(int *)(iVar11 + 8) <= iVar3));
            iVar11 = *(int *)(iVar11 + 0xc)) {
          while ((iVar5 = *piVar6, iVar5 != 0 && (iVar5 != iVar11))) {
            piVar6 = (int *)(iVar5 + 0x14);
          }
          if (*piVar6 != 0) {
            *piVar6 = *(int *)(*piVar6 + 0x14);
          }
        }
        do {
          bVar1 = false;
          piVar6 = piVar7;
          if (*piVar7 == 0) break;
          do {
            iVar8 = *piVar6;
            iVar5 = *(int *)(iVar8 + 0x14);
            if (iVar5 == 0) break;
            if (*(int *)(iVar5 + 0x10) < *(int *)(iVar8 + 0x10)) {
              *piVar6 = iVar5;
              bVar1 = true;
              *(undefined4 *)(iVar8 + 0x14) = *(undefined4 *)(*(int *)(iVar8 + 0x14) + 0x14);
              *(int *)(*piVar6 + 0x14) = iVar8;
            }
            piVar6 = (int *)(*piVar6 + 0x14);
          } while (*piVar6 != 0);
        } while (bVar1);
        if ((param_3 == (int *)0x0) || (param_3[1] <= iVar3)) {
          for (iVar3 = *piVar7; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
            iVar8 = *(int *)(iVar3 + 0x10) + 0xf >> 4;
            for (iVar5 = *(int *)(iVar3 + 0x18); iVar5 != 0; iVar5 = *(int *)(iVar3 + 0x18) + iVar5)
            {
              iVar3 = *(int *)(iVar3 + 0x14);
              if (iVar3 == 0) {
                return -0x7ff8ffa9;
              }
            }
            iVar5 = *(int *)(iVar3 + 0x10) + 0xf >> 4;
            if (param_3 != (int *)0x0) {
              if (iVar8 < *param_3) {
                iVar8 = *param_3;
              }
              if (param_3[2] < iVar5) {
                iVar5 = param_3[2];
              }
            }
            if (iVar8 < iVar5) {
              *(int *)param_2[5] = iVar8;
              *(int *)(param_2[5] + 8) = iVar5;
              iVar5 = (*(code *)*param_2)(param_4,param_2);
              if (iVar5 < 0) {
                return iVar5;
              }
            }
          }
        }
        for (iVar5 = *piVar7; iVar3 = iVar10, iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x14)) {
          iVar8 = *(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0x10);
          *(int *)(iVar5 + 0x10) = iVar8;
          iVar3 = *(int *)(iVar5 + 0x28) + *(int *)(iVar5 + 0x24);
          *(int *)(iVar5 + 0x28) = iVar3;
          if (*(int *)(iVar5 + 0x24) < 0) {
            if (iVar3 <= -*(int *)(iVar5 + 0x30)) {
              *(int *)(iVar5 + 0x28) = *(int *)(iVar5 + 0x30) + iVar3;
              *(int *)(iVar5 + 0x10) = iVar8 + -1;
            }
          }
          else if (0 < iVar3) {
            *(int *)(iVar5 + 0x28) = iVar3 - *(int *)(iVar5 + 0x30);
            *(int *)(iVar5 + 0x10) = iVar8 + 1;
          }
        }
      }
    }
  }
  return 0;
}



/* c08a14bc FUN_c08a14bc */

/* Boundary evidence: original MIPS .pdata c08a14bc..c08a15b3. Semantic name remains unreviewed. */

int FUN_c08a14bc(uint param_1,int param_2,uint param_3,int param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0 && param_2 == 0) {
    return 0;
  }
  if (param_3 == 0 && param_4 == 0) {
    return 0;
  }
  if ((param_2 < 1) && (param_2 != 0)) {
    param_2 = -(uint)(param_1 != 0) - param_2;
    param_1 = -param_1;
    uVar2 = param_3;
  }
  else {
    if ((0 < param_4) || (param_4 == 0)) goto LAB_c08a1540;
    uVar2 = -param_3;
    param_4 = -(uint)(param_3 != 0) - param_4;
  }
  uVar3 = 1;
  param_3 = uVar2;
LAB_c08a1540:
  uVar2 = (uint)((ulonglong)param_1 * (ulonglong)param_3);
  iVar1 = __ll_div(uVar2 - uVar3,
                   (param_1 * param_4 + param_2 * param_3 +
                   (int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20)) - (uint)(uVar2 < uVar3),
                   param_5,param_6);
  if (uVar3 != 0) {
    iVar1 = -1 - iVar1;
  }
  return iVar1;
}



/* c08a15b4 FUN_c08a15b4 */

/* Boundary evidence: original MIPS .pdata c08a15b4..c08a1e4b. Semantic name remains unreviewed. */

void FUN_c08a15b4(int param_1,int param_2)

{
  bool bVar1;
  SIZE_T uBytes;
  uint *_Src;
  int iVar3;
  void *_Dst;
  void *pvVar4;
  uint *puVar5;
  int iVar6;
  DWORD dwErrCode;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  uint *puVar30;
  uint uVar31;
  uint uVar32;
  int iVar33;
  uint uVar34;
  uint local_9c;
  uint local_98;
  uint local_90;
  uint local_88;
  uint local_44;
  uint local_3c;
  uint local_34;
  uint local_2c;
  longlong lVar2;
  
  iVar8 = *(int *)(param_1 + 8);
  iVar29 = *(int *)(param_2 + 0x2c);
  bVar1 = *(int *)(param_1 + 0x38) != 0;
  local_3c = *(uint *)(param_2 + 0x44);
  local_44 = *(uint *)(param_2 + 0x34);
  local_34 = *(uint *)(param_2 + 0x3c);
  local_2c = *(uint *)(param_2 + 0x4c);
  local_90 = *(uint *)(param_2 + 0x30);
  local_88 = *(uint *)(param_2 + 0x38);
  local_98 = *(uint *)(param_2 + 0x40);
  local_9c = *(uint *)(param_2 + 0x48);
  iVar33 = *(int *)(param_2 + 0x20);
  iVar27 = *(int *)(param_2 + 0x24);
  if (*(int *)(param_2 + 0x98) == 0) {
    if (((int)*(uint *)(param_2 + 0x28) < 0) ||
       (lVar2 = (ulonglong)*(uint *)(param_2 + 0x28) * 4, uBytes = (SIZE_T)lVar2,
       (int)((ulonglong)lVar2 >> 0x20) != 0)) {
      dwErrCode = 0x57;
    }
    else {
      _Src = LocalAlloc(0x40,uBytes);
      if (_Src != (uint *)0x0) {
        uVar18 = *(uint *)(param_2 + 0x70);
        iVar14 = *(int *)(param_2 + 0x74);
        uVar24 = *(uint *)(param_2 + 0x78);
        iVar6 = *(int *)(param_2 + 0x7c);
        uVar31 = *(uint *)(param_2 + 0x80);
        iVar3 = *(int *)(param_2 + 0x84);
        uVar32 = *(uint *)(param_2 + 0x88);
        iVar7 = *(int *)(param_2 + 0x8c);
        uVar9 = *(uint *)(param_2 + 0xa0);
        if (0 < (int)uVar9) {
          iVar23 = (int)uVar9 >> 0x1f;
          uVar10 = (uint)((ulonglong)uVar9 * (ulonglong)uVar18);
          local_90 = uVar10 + local_90;
          local_44 = uVar9 * iVar14 + iVar23 * uVar18 +
                     (int)((ulonglong)uVar9 * (ulonglong)uVar18 >> 0x20) + local_44 +
                     (uint)(local_90 < uVar10);
          uVar10 = (uint)((ulonglong)uVar9 * (ulonglong)uVar24);
          local_88 = uVar10 + local_88;
          local_34 = uVar9 * iVar6 + iVar23 * uVar24 +
                     (int)((ulonglong)uVar9 * (ulonglong)uVar24 >> 0x20) + local_34 +
                     (uint)(local_88 < uVar10);
          uVar10 = (uint)((ulonglong)uVar9 * (ulonglong)uVar31);
          local_98 = uVar10 + local_98;
          local_3c = uVar9 * iVar3 + iVar23 * uVar31 +
                     (int)((ulonglong)uVar9 * (ulonglong)uVar31 >> 0x20) + local_3c +
                     (uint)(local_98 < uVar10);
          uVar10 = (uint)((ulonglong)uVar9 * (ulonglong)uVar32);
          local_9c = uVar10 + local_9c;
          local_2c = uVar9 * iVar7 + iVar23 * uVar32 +
                     (int)((ulonglong)uVar9 * (ulonglong)uVar32 >> 0x20) + local_2c +
                     (uint)(local_9c < uVar10);
        }
        puVar30 = _Src;
        for (iVar23 = *(int *)(param_2 + 0x28); iVar23 != 0; iVar23 = iVar23 + -1) {
          *puVar30 = (int)((local_2c >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xc4) & 0x1f)) >>
                     (*(uint *)(param_2 + 0xb4) & 0x1f) & *(uint *)(param_2 + 0xd4) |
                     (int)((local_3c >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xc0) & 0x1f)) >>
                     (*(uint *)(param_2 + 0xb0) & 0x1f) & *(uint *)(param_2 + 0xd0) |
                     (int)((local_34 >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xbc) & 0x1f)) >>
                     (*(uint *)(param_2 + 0xac) & 0x1f) & *(uint *)(param_2 + 0xcc) |
                     (int)((local_44 >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xb8) & 0x1f)) >>
                     (*(uint *)(param_2 + 0xa8) & 0x1f) & *(uint *)(param_2 + 200);
          local_88 = uVar24 + local_88;
          local_90 = uVar18 + local_90;
          local_34 = iVar6 + local_34 + (uint)(local_88 < uVar24);
          local_98 = uVar31 + local_98;
          local_44 = iVar14 + local_44 + (uint)(local_90 < uVar18);
          local_3c = iVar3 + local_3c + (uint)(local_98 < uVar31);
          local_9c = uVar32 + local_9c;
          local_2c = iVar7 + local_2c + (uint)(local_9c < uVar32);
          puVar30 = puVar30 + 1;
        }
        _Dst = (void *)FUN_c08947dc(param_1,iVar33,iVar27);
        pvVar4 = (void *)FUN_c08947dc(param_1,iVar33,iVar27 + iVar29);
        if (bVar1) {
          iVar8 = 0;
          if (0 < iVar29) {
            iVar3 = *(int *)(param_2 + 0x28);
            do {
              iVar6 = 0;
              if (0 < iVar3) {
                puVar30 = _Src;
                do {
                  puVar5 = (uint *)FUN_c08947dc(param_1,iVar6 + iVar33,iVar8 + iVar27);
                  iVar6 = iVar6 + 1;
                  *puVar5 = *puVar30;
                  iVar3 = *(int *)(param_2 + 0x28);
                  puVar30 = puVar30 + 1;
                } while (iVar6 < iVar3);
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < iVar29);
          }
        }
        else {
          for (; _Dst != pvVar4; _Dst = (void *)((int)_Dst + iVar8)) {
            memcpy(_Dst,_Src,uBytes);
          }
        }
        LocalFree(_Src);
        return;
      }
      dwErrCode = 0xe;
    }
    SetLastError(dwErrCode);
  }
  else {
    iVar7 = *(int *)(param_2 + 0x6c);
    uVar32 = *(uint *)(param_2 + 0x50);
    iVar14 = *(int *)(param_2 + 0x54);
    uVar9 = *(uint *)(param_2 + 0x58);
    iVar6 = *(int *)(param_2 + 0x5c);
    uVar24 = *(uint *)(param_2 + 0x60);
    iVar3 = *(int *)(param_2 + 100);
    uVar18 = *(uint *)(param_2 + 0x68);
    uVar31 = *(uint *)(param_2 + 0xa4);
    if (0 < (int)uVar31) {
      iVar23 = (int)uVar31 >> 0x1f;
      uVar10 = (uint)((ulonglong)uVar31 * (ulonglong)uVar32);
      local_90 = uVar10 + local_90;
      local_44 = uVar31 * iVar14 + iVar23 * uVar32 +
                 (int)((ulonglong)uVar31 * (ulonglong)uVar32 >> 0x20) + local_44 +
                 (uint)(local_90 < uVar10);
      uVar10 = (uint)((ulonglong)uVar31 * (ulonglong)uVar9);
      local_88 = uVar10 + local_88;
      local_34 = uVar31 * iVar6 + iVar23 * uVar9 +
                 (int)((ulonglong)uVar31 * (ulonglong)uVar9 >> 0x20) + local_34 +
                 (uint)(local_88 < uVar10);
      uVar10 = (uint)((ulonglong)uVar31 * (ulonglong)uVar24);
      local_98 = uVar10 + local_98;
      local_3c = uVar31 * iVar3 + iVar23 * uVar24 +
                 (int)((ulonglong)uVar31 * (ulonglong)uVar24 >> 0x20) + local_3c +
                 (uint)(local_98 < uVar10);
      uVar10 = (uint)((ulonglong)uVar31 * (ulonglong)uVar18);
      local_9c = uVar10 + local_9c;
      local_2c = uVar31 * iVar7 + iVar23 * uVar18 +
                 (int)((ulonglong)uVar31 * (ulonglong)uVar18 >> 0x20) + local_2c +
                 (uint)(local_9c < uVar10);
    }
    iVar33 = FUN_c08947dc(param_1,iVar33,iVar27);
    while (iVar29 != 0) {
      uVar31 = *(uint *)(param_2 + 0xc4);
      uVar12 = *(uint *)(param_2 + 0xb4);
      uVar10 = *(uint *)(param_2 + 0xb0);
      uVar15 = *(uint *)(param_2 + 0xd4);
      uVar13 = *(uint *)(param_2 + 0xd0);
      uVar19 = *(uint *)(param_2 + 0xc0);
      uVar16 = *(uint *)(param_2 + 0xbc);
      uVar20 = *(uint *)(param_2 + 0xac);
      uVar22 = *(uint *)(param_2 + 0xb8);
      uVar11 = *(uint *)(param_2 + 0xcc);
      uVar17 = *(uint *)(param_2 + 0xa8);
      uVar21 = *(uint *)(param_2 + 200);
      uVar25 = *(uint *)(param_2 + 0x28);
      iVar28 = *(int *)(param_2 + 0x20);
      iVar29 = iVar29 + -1;
      uVar34 = 0;
      iVar23 = iVar33;
      if (bVar1) {
        iVar23 = FUN_c08947dc(param_1,iVar28,iVar27);
      }
      if (uVar25 != 0) {
        iVar26 = 0;
        do {
          *(uint *)(iVar26 + iVar23) =
               (int)((local_2c >> 0x10 & 0xff) << (uVar31 & 0x1f)) >> (uVar12 & 0x1f) & uVar15 |
               (int)((local_3c >> 0x10 & 0xff) << (uVar19 & 0x1f)) >> (uVar10 & 0x1f) & uVar13 |
               (int)((local_34 >> 0x10 & 0xff) << (uVar16 & 0x1f)) >> (uVar20 & 0x1f) & uVar11 |
               (int)((local_44 >> 0x10 & 0xff) << (uVar22 & 0x1f)) >> (uVar17 & 0x1f) & uVar21;
          if (bVar1) {
            iVar28 = iVar28 + 1;
            iVar23 = FUN_c08947dc(param_1,iVar28,iVar27);
            uVar25 = uVar25 - 1;
          }
          else {
            uVar34 = uVar34 + 1;
            iVar26 = iVar26 + 4;
          }
        } while (uVar34 < uVar25);
      }
      local_90 = uVar32 + local_90;
      local_44 = iVar14 + local_44 + (uint)(local_90 < uVar32);
      local_88 = uVar9 + local_88;
      local_34 = iVar6 + local_34 + (uint)(local_88 < uVar9);
      local_98 = uVar24 + local_98;
      local_3c = iVar3 + local_3c + (uint)(local_98 < uVar24);
      local_9c = uVar18 + local_9c;
      local_2c = iVar7 + local_2c + (uint)(local_9c < uVar18);
      iVar27 = iVar27 + 1;
      iVar33 = iVar33 + iVar8;
    }
  }
  return;
}



/* c08a1e4c FUN_c08a1e4c */

/* Boundary evidence: original MIPS .pdata c08a1e4c..c08a25c3. Semantic name remains unreviewed. */

void FUN_c08a1e4c(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  SIZE_T uBytes;
  uint uVar4;
  undefined1 *puVar5;
  void *_Dst;
  undefined1 *puVar6;
  uint uVar7;
  DWORD dwErrCode;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  undefined1 *puVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined1 local_88;
  undefined1 uStack_87;
  undefined1 uStack_86;
  undefined1 local_84;
  undefined1 uStack_83;
  undefined1 uStack_82;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_3c;
  uint local_2c;
  longlong lVar3;
  
  iVar10 = *(int *)(param_1 + 8);
  iVar15 = *(int *)(param_2 + 0x2c);
  bVar1 = *(int *)(param_1 + 0x38) != 0;
  uVar17 = *(uint *)(param_2 + 0x34);
  local_3c = *(uint *)(param_2 + 0x3c);
  local_2c = *(uint *)(param_2 + 0x44);
  local_6c = *(uint *)(param_2 + 0x30);
  local_74 = *(uint *)(param_2 + 0x38);
  local_70 = *(uint *)(param_2 + 0x40);
  iVar19 = *(int *)(param_2 + 0x20);
  iVar18 = *(int *)(param_2 + 0x24);
  if (*(int *)(param_2 + 0x98) == 0) {
    uVar13 = *(uint *)(param_2 + 0x70);
    iVar12 = *(int *)(param_2 + 0x74);
    uVar7 = *(uint *)(param_2 + 0x78);
    iVar9 = *(int *)(param_2 + 0x7c);
    uVar4 = *(uint *)(param_2 + 0x80);
    iVar8 = *(int *)(param_2 + 0x84);
    uVar11 = *(uint *)(param_2 + 0xa0);
    if (0 < (int)uVar11) {
      iVar14 = (int)uVar11 >> 0x1f;
      uVar2 = (uint)((ulonglong)uVar11 * (ulonglong)uVar13);
      local_6c = uVar2 + local_6c;
      uVar17 = uVar11 * iVar12 + iVar14 * uVar13 +
               (int)((ulonglong)uVar11 * (ulonglong)uVar13 >> 0x20) + uVar17 +
               (uint)(local_6c < uVar2);
      uVar2 = (uint)((ulonglong)uVar11 * (ulonglong)uVar7);
      local_74 = uVar2 + local_74;
      local_3c = uVar11 * iVar9 + iVar14 * uVar7 +
                 (int)((ulonglong)uVar11 * (ulonglong)uVar7 >> 0x20) + local_3c +
                 (uint)(local_74 < uVar2);
      uVar2 = (uint)((ulonglong)uVar11 * (ulonglong)uVar4);
      local_70 = uVar2 + local_70;
      local_2c = uVar11 * iVar8 + iVar14 * uVar4 +
                 (int)((ulonglong)uVar11 * (ulonglong)uVar4 >> 0x20) + local_2c +
                 (uint)(local_70 < uVar2);
    }
    if (((int)*(uint *)(param_2 + 0x28) < 0) ||
       (lVar3 = (ulonglong)*(uint *)(param_2 + 0x28) * 3, uBytes = (SIZE_T)lVar3,
       (int)((ulonglong)lVar3 >> 0x20) != 0)) {
      dwErrCode = 0x57;
    }
    else {
      puVar5 = LocalAlloc(0x40,uBytes);
      if (puVar5 != (undefined1 *)0x0) {
        for (puVar16 = puVar5; puVar16 != puVar5 + uBytes; puVar16 = puVar16 + 3) {
          uVar11 = (int)((local_2c >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xc0) & 0x1f)) >>
                   (*(uint *)(param_2 + 0xb0) & 0x1f) & *(uint *)(param_2 + 0xd0) |
                   (int)((local_3c >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xbc) & 0x1f)) >>
                   (*(uint *)(param_2 + 0xac) & 0x1f) & *(uint *)(param_2 + 0xcc) |
                   (int)((uVar17 >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xb8) & 0x1f)) >>
                   (*(uint *)(param_2 + 0xa8) & 0x1f) & *(uint *)(param_2 + 200);
          uStack_87 = (undefined1)(uVar11 >> 8);
          uStack_86 = (undefined1)(uVar11 >> 0x10);
          local_74 = uVar7 + local_74;
          puVar16[2] = uStack_86;
          puVar16[1] = uStack_87;
          local_6c = uVar13 + local_6c;
          local_3c = iVar9 + local_3c + (uint)(local_74 < uVar7);
          local_70 = uVar4 + local_70;
          uVar17 = iVar12 + uVar17 + (uint)(local_6c < uVar13);
          local_88 = (undefined1)uVar11;
          local_2c = iVar8 + local_2c + (uint)(local_70 < uVar4);
          *puVar16 = local_88;
        }
        _Dst = (void *)FUN_c08947dc(param_1,iVar19,iVar18);
        if (bVar1) {
          iVar10 = 0;
          if (0 < iVar15) {
            iVar8 = *(int *)(param_2 + 0x28);
            do {
              iVar9 = 0;
              if (0 < iVar8) {
                puVar16 = puVar5 + 2;
                do {
                  puVar6 = (undefined1 *)FUN_c08947dc(param_1,iVar9 + iVar19,iVar10 + iVar18);
                  iVar9 = iVar9 + 1;
                  *puVar6 = puVar16[-2];
                  puVar6[1] = puVar16[-1];
                  puVar6[2] = *puVar16;
                  iVar8 = *(int *)(param_2 + 0x28);
                  puVar16 = puVar16 + 3;
                } while (iVar9 < iVar8);
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < iVar15);
          }
        }
        else {
          for (; iVar15 != 0; iVar15 = iVar15 + -1) {
            memcpy(_Dst,puVar5,uBytes);
            _Dst = (void *)((int)_Dst + iVar10);
          }
        }
        LocalFree(puVar5);
        return;
      }
      dwErrCode = 0xe;
    }
    SetLastError(dwErrCode);
  }
  else {
    puVar5 = (undefined1 *)FUN_c08947dc(param_1,iVar19,iVar18);
    uVar7 = *(uint *)(param_2 + 0x50);
    iVar8 = *(int *)(param_2 + 0x54);
    uVar11 = *(uint *)(param_2 + 0x58);
    iVar9 = *(int *)(param_2 + 0x5c);
    uVar13 = *(uint *)(param_2 + 0x60);
    iVar19 = *(int *)(param_2 + 100);
    uVar4 = *(uint *)(param_2 + 0xa4);
    if (0 < (int)uVar4) {
      iVar12 = (int)uVar4 >> 0x1f;
      uVar2 = (uint)((ulonglong)uVar4 * (ulonglong)uVar7);
      local_6c = uVar2 + local_6c;
      uVar17 = uVar4 * iVar8 + iVar12 * uVar7 + (int)((ulonglong)uVar4 * (ulonglong)uVar7 >> 0x20) +
               uVar17 + (uint)(local_6c < uVar2);
      uVar2 = (uint)((ulonglong)uVar4 * (ulonglong)uVar11);
      local_74 = uVar2 + local_74;
      local_3c = uVar4 * iVar9 + iVar12 * uVar11 +
                 (int)((ulonglong)uVar4 * (ulonglong)uVar11 >> 0x20) + local_3c +
                 (uint)(local_74 < uVar2);
      uVar2 = (uint)((ulonglong)uVar4 * (ulonglong)uVar13);
      local_70 = uVar2 + local_70;
      local_2c = uVar4 * iVar19 + iVar12 * uVar13 +
                 (int)((ulonglong)uVar4 * (ulonglong)uVar13 >> 0x20) + local_2c +
                 (uint)(local_70 < uVar2);
    }
    while (iVar15 != 0) {
      iVar15 = iVar15 + -1;
      puVar6 = (undefined1 *)
               FUN_c08947dc(param_1,*(int *)(param_2 + 0x28) + *(int *)(param_2 + 0x20),iVar18);
      iVar12 = *(int *)(param_2 + 0x20);
      puVar16 = puVar5;
      if (bVar1) {
        puVar16 = (undefined1 *)FUN_c08947dc(param_1,iVar12,iVar18);
      }
      if (puVar16 != puVar6) {
        do {
          uVar4 = (int)((uVar17 >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xb8) & 0x1f)) >>
                  (*(uint *)(param_2 + 0xa8) & 0x1f) & *(uint *)(param_2 + 200) |
                  (int)((local_3c >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xbc) & 0x1f)) >>
                  (*(uint *)(param_2 + 0xac) & 0x1f) & *(uint *)(param_2 + 0xcc) |
                  (int)((local_2c >> 0x10 & 0xff) << (*(uint *)(param_2 + 0xc0) & 0x1f)) >>
                  (*(uint *)(param_2 + 0xb0) & 0x1f) & *(uint *)(param_2 + 0xd0);
          local_84 = (undefined1)uVar4;
          uStack_83 = (undefined1)(uVar4 >> 8);
          uStack_82 = (undefined1)(uVar4 >> 0x10);
          *puVar16 = local_84;
          puVar16[1] = uStack_83;
          puVar16[2] = uStack_82;
          puVar16 = puVar16 + 3;
          if (bVar1) {
            iVar12 = iVar12 + 1;
            puVar16 = (undefined1 *)FUN_c08947dc(param_1,iVar12,iVar18);
          }
        } while (puVar16 != puVar6);
      }
      local_6c = uVar7 + local_6c;
      uVar17 = iVar8 + uVar17 + (uint)(local_6c < uVar7);
      local_74 = uVar11 + local_74;
      local_3c = iVar9 + local_3c + (uint)(local_74 < uVar11);
      local_70 = uVar13 + local_70;
      local_2c = iVar19 + local_2c + (uint)(local_70 < uVar13);
      puVar5 = puVar5 + iVar10;
      iVar18 = iVar18 + 1;
    }
  }
  return;
}



/* c08a25c4 FUN_c08a25c4 */

/* Boundary evidence: original MIPS .pdata c08a25c4..c08a2c0b. Semantic name remains unreviewed. */

void FUN_c08a25c4(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  uint local_b0;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_60;
  uint local_54;
  
  iVar17 = *(int *)(param_2 + 0x24);
  iVar12 = *(int *)(param_2 + 0x2c) + iVar17;
  iVar6 = *(int *)(param_2 + 0x74);
  iVar7 = *(int *)(param_2 + 0x7c);
  iVar8 = *(int *)(param_2 + 0x84);
  uVar2 = *(uint *)(param_2 + 0x70);
  uVar20 = *(uint *)(param_2 + 0x78);
  uVar21 = *(uint *)(param_2 + 0x80);
  uVar13 = *(uint *)(param_2 + 0x50);
  iVar14 = *(int *)(param_2 + 0x54);
  uVar1 = *(uint *)(param_2 + 0x58);
  iVar4 = *(int *)(param_2 + 0x5c);
  uVar5 = *(uint *)(param_2 + 0x60);
  iVar3 = *(int *)(param_2 + 100);
  local_a8 = *(uint *)(param_2 + 0x30);
  local_a4 = *(uint *)(param_2 + 0x34);
  local_9c = *(uint *)(param_2 + 0x38);
  local_94 = *(uint *)(param_2 + 0x3c);
  local_8c = *(uint *)(param_2 + 0x40);
  local_84 = *(uint *)(param_2 + 0x44);
  uVar9 = *(uint *)(param_2 + 0xa4);
  if (uVar9 != 0) {
    iVar15 = (int)uVar9 >> 0x1f;
    uVar11 = (uint)((ulonglong)uVar9 * (ulonglong)uVar13);
    local_a8 = uVar11 + local_a8;
    local_a4 = uVar9 * iVar14 + iVar15 * uVar13 +
               (int)((ulonglong)uVar9 * (ulonglong)uVar13 >> 0x20) + local_a4 +
               (uint)(local_a8 < uVar11);
    uVar11 = (uint)((ulonglong)uVar9 * (ulonglong)uVar1);
    local_9c = uVar11 + local_9c;
    local_94 = uVar9 * iVar4 + iVar15 * uVar1 + (int)((ulonglong)uVar9 * (ulonglong)uVar1 >> 0x20) +
               local_94 + (uint)(local_9c < uVar11);
    uVar11 = (uint)((ulonglong)uVar9 * (ulonglong)uVar5);
    local_8c = uVar11 + local_8c;
    local_84 = uVar9 * iVar3 + iVar15 * uVar5 + (int)((ulonglong)uVar9 * (ulonglong)uVar5 >> 0x20) +
               local_84 + (uint)(local_8c < uVar11);
  }
  iVar15 = *(int *)(param_2 + 0x90);
  iVar10 = *(int *)(param_1 + 0x38);
  if (iVar17 < iVar12) {
    uVar9 = *(int *)(param_2 + 0x94) + iVar17;
    do {
      iVar18 = *(int *)(param_2 + 0x20);
      uVar11 = *(uint *)(param_2 + 0xa0);
      local_b0 = local_84;
      local_a0 = local_9c;
      local_90 = local_8c;
      local_88 = local_a8;
      local_60 = local_94;
      local_54 = local_a4;
      if (uVar11 != 0) {
        iVar16 = (int)uVar11 >> 0x1f;
        uVar22 = (uint)((ulonglong)uVar11 * (ulonglong)uVar2);
        local_88 = uVar22 + local_a8;
        local_54 = uVar11 * iVar6 + iVar16 * uVar2 +
                   (int)((ulonglong)uVar11 * (ulonglong)uVar2 >> 0x20) + local_a4 +
                   (uint)(local_88 < uVar22);
        uVar22 = (uint)((ulonglong)uVar11 * (ulonglong)uVar20);
        local_a0 = uVar22 + local_9c;
        local_60 = uVar11 * iVar7 + iVar16 * uVar20 +
                   (int)((ulonglong)uVar11 * (ulonglong)uVar20 >> 0x20) + local_94 +
                   (uint)(local_a0 < uVar22);
        uVar22 = (uint)((ulonglong)uVar11 * (ulonglong)uVar21);
        local_90 = uVar22 + local_8c;
        local_b0 = uVar11 * iVar8 + iVar16 * uVar21 +
                   (int)((ulonglong)uVar11 * (ulonglong)uVar21 >> 0x20) + local_84 +
                   (uint)(local_90 < uVar22);
      }
      uVar22 = iVar18 + iVar15;
      iVar16 = FUN_c08947dc(param_1,iVar18,iVar17);
      uVar11 = *(uint *)(param_2 + 0x28);
      local_98 = 0;
      if (uVar11 != 0) {
        iVar19 = 0;
        do {
          iVar23 = *(int *)(&DAT_c08b3070 + (uVar22 & 3) * 4 + (uVar9 & 3) * 0x10);
          if (param_3 == 0) {
            *(ushort *)(iVar19 + iVar16) =
                 (ushort)((int)((uint)(byte)(&DAT_c08b3530)[(local_60 >> 2) + iVar23 >> 0x10] <<
                               (*(uint *)(param_2 + 0xbc) & 0x1f)) >>
                         (*(uint *)(param_2 + 0xac) & 0x1f)) &
                 (ushort)*(undefined4 *)(param_2 + 0xcc) |
                 (ushort)((int)((uint)(byte)(&DAT_c08b3530)[(local_b0 >> 3) + iVar23 >> 0x10] <<
                               (*(uint *)(param_2 + 0xc0) & 0x1f)) >>
                         (*(uint *)(param_2 + 0xb0) & 0x1f)) &
                 (ushort)*(undefined4 *)(param_2 + 0xd0) |
                 (ushort)((int)((uint)(byte)(&DAT_c08b3530)[(local_54 >> 3) + iVar23 >> 0x10] <<
                               (*(uint *)(param_2 + 0xb8) & 0x1f)) >>
                         (*(uint *)(param_2 + 0xa8) & 0x1f)) &
                 (ushort)*(undefined4 *)(param_2 + 200);
          }
          else {
            *(ushort *)(iVar19 + iVar16) =
                 (ushort)(((uint)(byte)(&DAT_c08b3570)[(local_60 >> 2) + iVar23 >> 0x10] |
                          (uint)(byte)(&DAT_c08b3530)[(local_54 >> 3) + iVar23 >> 0x10] << 6) << 5)
                 | (ushort)(byte)(&DAT_c08b3530)[(local_b0 >> 3) + iVar23 >> 0x10];
          }
          uVar22 = uVar22 + 1;
          if (iVar10 == 0) {
            local_98 = local_98 + 1;
            iVar19 = iVar19 + 2;
          }
          else {
            iVar18 = iVar18 + 1;
            iVar16 = FUN_c08947dc(param_1,iVar18,iVar17);
            uVar11 = uVar11 - 1;
          }
          local_54 = local_54 + iVar6 + (uint)(local_88 + uVar2 < local_88);
          local_60 = local_60 + iVar7 + (uint)(local_a0 + uVar20 < local_a0);
          local_b0 = local_b0 + iVar8 + (uint)(local_90 + uVar21 < local_90);
          local_a0 = local_a0 + uVar20;
          local_90 = local_90 + uVar21;
          local_88 = local_88 + uVar2;
        } while (local_98 < uVar11);
      }
      local_a4 = local_a4 + iVar14 + (uint)(local_a8 + uVar13 < local_a8);
      local_94 = local_94 + iVar4 + (uint)(local_9c + uVar1 < local_9c);
      local_84 = local_84 + iVar3 + (uint)(local_8c + uVar5 < local_8c);
      iVar17 = iVar17 + 1;
      uVar9 = uVar9 + 1;
      local_a8 = local_a8 + uVar13;
      local_9c = local_9c + uVar1;
      local_8c = local_8c + uVar5;
    } while (iVar17 < iVar12);
  }
  return;
}



/* c08a2c0c FUN_c08a2c0c */

/* Boundary evidence: original MIPS .pdata c08a2c0c..c08a2c27. Semantic name remains unreviewed. */

void FUN_c08a2c0c(int param_1,int param_2)

{
  FUN_c08a25c4(param_1,param_2,1);
  return;
}



/* c08a2c28 FUN_c08a2c28 */

/* Boundary evidence: original MIPS .pdata c08a2c28..c08a2c7b. Semantic name remains unreviewed. */

void FUN_c08a2c28(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0xb8) = 10;
  *(undefined4 *)(param_2 + 0xbc) = 5;
  *(undefined4 *)(param_2 + 0xc0) = 0;
  *(undefined4 *)(param_2 + 0xb0) = 0;
  *(undefined4 *)(param_2 + 0xac) = 0;
  *(undefined4 *)(param_2 + 0xa8) = 0;
  *(undefined4 *)(param_2 + 200) = 0x7c00;
  *(undefined4 *)(param_2 + 0xcc) = 0x3e0;
  *(undefined4 *)(param_2 + 0xd0) = 0x1f;
  FUN_c08a25c4(param_1,param_2,0);
  return;
}



/* c08a2c7c FUN_c08a2c7c */

/* Boundary evidence: original MIPS .pdata c08a2c7c..c08a2c97. Semantic name remains unreviewed. */

void FUN_c08a2c7c(int param_1,int param_2)

{
  FUN_c08a25c4(param_1,param_2,0);
  return;
}



/* c08a2c98 FUN_c08a2c98 */

/* Boundary evidence: original MIPS .pdata c08a2c98..c08a330f. Semantic name remains unreviewed. */

void FUN_c08a2c98(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  byte *pbVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_3c;
  uint local_34;
  uint local_2c;
  
  iVar12 = *(int *)(param_1 + 8);
  iVar24 = *(int *)(param_2 + 0x24);
  iVar16 = *(int *)(param_2 + 0x2c) + iVar24;
  iVar6 = *(int *)(param_2 + 0x74);
  iVar7 = *(int *)(param_2 + 0x7c);
  uVar8 = *(uint *)(param_2 + 0x80);
  iVar9 = *(int *)(param_2 + 0x84);
  uVar23 = *(uint *)(param_2 + 0x70);
  uVar25 = *(uint *)(param_2 + 0x78);
  uVar15 = *(uint *)(param_2 + 0x50);
  uVar2 = *(uint *)(param_2 + 0x58);
  iVar3 = *(int *)(param_2 + 0x5c);
  uVar4 = *(uint *)(param_2 + 0x60);
  iVar5 = iVar24 * iVar12 + *(int *)(param_1 + 4);
  iVar13 = *(int *)(param_2 + 0x54);
  iVar21 = *(int *)(param_2 + 100);
  local_c0 = *(uint *)(param_2 + 0x30);
  local_d0 = *(uint *)(param_2 + 0x34);
  local_cc = *(uint *)(param_2 + 0x38);
  local_c4 = *(uint *)(param_2 + 0x3c);
  local_bc = *(uint *)(param_2 + 0x40);
  local_b4 = *(uint *)(param_2 + 0x44);
  uVar10 = *(uint *)(param_2 + 0xa4);
  if (uVar10 != 0) {
    iVar18 = (int)uVar10 >> 0x1f;
    uVar11 = (uint)((ulonglong)uVar10 * (ulonglong)uVar15);
    local_c0 = uVar11 + local_c0;
    local_d0 = uVar10 * iVar13 + iVar18 * uVar15 +
               (int)((ulonglong)uVar10 * (ulonglong)uVar15 >> 0x20) + local_d0 +
               (uint)(local_c0 < uVar11);
    uVar11 = (uint)((ulonglong)uVar10 * (ulonglong)uVar2);
    local_cc = uVar11 + local_cc;
    local_c4 = uVar10 * iVar3 + iVar18 * uVar2 + (int)((ulonglong)uVar10 * (ulonglong)uVar2 >> 0x20)
               + local_c4 + (uint)(local_cc < uVar11);
    uVar11 = (uint)((ulonglong)uVar10 * (ulonglong)uVar4);
    local_bc = uVar11 + local_bc;
    local_b4 = uVar10 * iVar21 + iVar18 * uVar4 +
               (int)((ulonglong)uVar10 * (ulonglong)uVar4 >> 0x20) + local_b4 +
               (uint)(local_bc < uVar11);
  }
  iVar19 = *(int *)(param_2 + 0x90);
  iVar18 = *(int *)(param_1 + 0x38);
  if (iVar24 < iVar16) {
    uVar10 = *(int *)(param_2 + 0x94) + iVar24;
    do {
      uVar11 = *(uint *)(param_2 + 0xa0);
      local_3c = local_d0;
      local_c8 = local_cc;
      local_b8 = local_bc;
      local_b0 = local_c0;
      local_34 = local_c4;
      local_2c = local_b4;
      if (uVar11 != 0) {
        iVar20 = (int)uVar11 >> 0x1f;
        uVar17 = (uint)((ulonglong)uVar11 * (ulonglong)uVar23);
        local_b0 = uVar17 + local_c0;
        local_3c = uVar11 * iVar6 + iVar20 * uVar23 +
                   (int)((ulonglong)uVar11 * (ulonglong)uVar23 >> 0x20) + local_d0 +
                   (uint)(local_b0 < uVar17);
        uVar17 = (uint)((ulonglong)uVar11 * (ulonglong)uVar25);
        local_c8 = uVar17 + local_cc;
        local_34 = uVar11 * iVar7 + iVar20 * uVar25 +
                   (int)((ulonglong)uVar11 * (ulonglong)uVar25 >> 0x20) + local_c4 +
                   (uint)(local_c8 < uVar17);
        uVar17 = (uint)((ulonglong)uVar11 * (ulonglong)uVar8);
        local_b8 = uVar17 + local_bc;
        local_2c = uVar11 * iVar9 + iVar20 * uVar8 +
                   (int)((ulonglong)uVar11 * (ulonglong)uVar8 >> 0x20) + local_b4 +
                   (uint)(local_b8 < uVar17);
      }
      uVar11 = *(uint *)(param_2 + 0x20);
      if (param_3 == 0) {
        trap(0x1c00);
      }
      if ((param_3 == -1) && (uVar11 == 0x80000000)) {
        trap(0x1800);
      }
      pbVar22 = (byte *)((int)uVar11 / param_3 + iVar5);
      iVar20 = *(int *)(param_2 + 0x28) + uVar11;
      if ((int)uVar11 < iVar20) {
        uVar17 = uVar11 + iVar19;
        do {
          uVar14 = (uint)(byte)(&DAT_c08b31b0)[(uVar17 & 0xf) + (uVar10 & 0xf) * 0x10];
          bVar1 = (**(code **)(param_2 + 0xd8))
                            (*(undefined4 *)(param_2 + 0xdc),
                             (uint)CONCAT21(CONCAT11((&DAT_c08b33b0)
                                                     [(local_3c >> 0x10 & 0xff) + uVar14],
                                                     (&DAT_c08b33b0)
                                                     [(local_34 >> 0x10 & 0xff) + uVar14]),
                                            (&DAT_c08b33b0)[(local_2c >> 0x10 & 0xff) + uVar14]));
          if (iVar18 != 0) {
            pbVar22 = (byte *)FUN_c08947dc(param_1,uVar11,iVar24);
          }
          if (param_3 == 1) {
            *pbVar22 = bVar1;
LAB_c08a3170:
            pbVar22 = pbVar22 + 1;
          }
          else if (param_3 == 2) {
            if ((uVar11 & 1) != 0) {
              *pbVar22 = *pbVar22 & 0xf0 | bVar1;
              goto LAB_c08a3170;
            }
            *pbVar22 = *pbVar22 & 0xf | bVar1 << 4;
          }
          local_3c = local_3c + iVar6 + (uint)(local_b0 + uVar23 < local_b0);
          local_34 = local_34 + iVar7 + (uint)(local_c8 + uVar25 < local_c8);
          local_2c = local_2c + iVar9 + (uint)(local_b8 + uVar8 < local_b8);
          uVar11 = uVar11 + 1;
          uVar17 = uVar17 + 1;
          local_c8 = local_c8 + uVar25;
          local_b8 = local_b8 + uVar8;
          local_b0 = local_b0 + uVar23;
        } while ((int)uVar11 < iVar20);
      }
      iVar5 = iVar5 + iVar12;
      local_d0 = local_d0 + iVar13 + (uint)(local_c0 + uVar15 < local_c0);
      local_c4 = local_c4 + iVar3 + (uint)(local_cc + uVar2 < local_cc);
      local_b4 = local_b4 + iVar21 + (uint)(local_bc + uVar4 < local_bc);
      iVar24 = iVar24 + 1;
      uVar10 = uVar10 + 1;
      local_cc = local_cc + uVar2;
      local_c0 = local_c0 + uVar15;
      local_bc = local_bc + uVar4;
    } while (iVar24 < iVar16);
  }
  return;
}



/* c08a3310 FUN_c08a3310 */

/* Boundary evidence: original MIPS .pdata c08a3310..c08a332b. Semantic name remains unreviewed. */

void FUN_c08a3310(int param_1,int param_2)

{
  FUN_c08a2c98(param_1,param_2,1);
  return;
}



/* c08a332c FUN_c08a332c */

/* Boundary evidence: original MIPS .pdata c08a332c..c08a3347. Semantic name remains unreviewed. */

void FUN_c08a332c(int param_1,int param_2)

{
  FUN_c08a2c98(param_1,param_2,2);
  return;
}



/* c08a3348 FUN_c08a3348 */

/* Boundary evidence: original MIPS .pdata c08a3348..c08a39af. Semantic name remains unreviewed. */

void FUN_c08a3348(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  byte *pbVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  uint local_cc;
  uint local_c4;
  uint local_bc;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_3c;
  uint local_34;
  uint local_2c;
  
  iVar8 = *(int *)(param_1 + 8);
  iVar22 = *(int *)(param_2 + 0x24);
  iVar13 = *(int *)(param_2 + 0x2c) + iVar22;
  iVar3 = *(int *)(param_2 + 0x74);
  iVar4 = *(int *)(param_2 + 0x7c);
  iVar5 = *(int *)(param_2 + 0x84);
  iVar16 = *(int *)(param_2 + 0x28);
  uVar25 = *(uint *)(param_2 + 0x70);
  uVar27 = *(uint *)(param_2 + 0x78);
  uVar29 = *(uint *)(param_2 + 0x80);
  uVar10 = *(uint *)(param_2 + 0x50);
  uVar1 = *(uint *)(param_2 + 0x58);
  iVar17 = *(int *)(param_2 + 0x5c);
  iVar23 = iVar22 * iVar8 + *(int *)(param_1 + 4);
  iVar9 = *(int *)(param_2 + 0x54);
  uVar2 = *(uint *)(param_2 + 0x60);
  iVar20 = *(int *)(param_2 + 100);
  local_cc = *(uint *)(param_2 + 0x30);
  local_c4 = *(uint *)(param_2 + 0x34);
  local_bc = *(uint *)(param_2 + 0x38);
  local_b4 = *(uint *)(param_2 + 0x3c);
  local_ac = *(uint *)(param_2 + 0x40);
  local_a4 = *(uint *)(param_2 + 0x44);
  uVar6 = *(uint *)(param_2 + 0xa4);
  if (uVar6 != 0) {
    iVar14 = (int)uVar6 >> 0x1f;
    uVar7 = (uint)((ulonglong)uVar6 * (ulonglong)uVar10);
    local_cc = uVar7 + local_cc;
    local_c4 = uVar6 * iVar9 + iVar14 * uVar10 + (int)((ulonglong)uVar6 * (ulonglong)uVar10 >> 0x20)
               + local_c4 + (uint)(local_cc < uVar7);
    uVar7 = (uint)((ulonglong)uVar6 * (ulonglong)uVar1);
    local_bc = uVar7 + local_bc;
    local_b4 = uVar6 * iVar17 + iVar14 * uVar1 + (int)((ulonglong)uVar6 * (ulonglong)uVar1 >> 0x20)
               + local_b4 + (uint)(local_bc < uVar7);
    uVar7 = (uint)((ulonglong)uVar6 * (ulonglong)uVar2);
    local_ac = uVar7 + local_ac;
    local_a4 = uVar6 * iVar20 + iVar14 * uVar2 + (int)((ulonglong)uVar6 * (ulonglong)uVar2 >> 0x20)
               + local_a4 + (uint)(local_ac < uVar7);
  }
  iVar12 = *(int *)(param_2 + 0x90);
  iVar14 = *(int *)(param_1 + 0x38);
  if (iVar22 < iVar13) {
    uVar6 = *(int *)(param_2 + 0x94) + iVar22;
    do {
      iVar21 = *(int *)(param_2 + 0x20);
      iVar18 = iVar21 + iVar16;
      uVar7 = *(uint *)(param_2 + 0xa0);
      local_b0 = local_bc;
      local_a8 = local_cc;
      local_a0 = local_ac;
      local_3c = local_c4;
      local_34 = local_b4;
      local_2c = local_a4;
      if (uVar7 != 0) {
        iVar15 = (int)uVar7 >> 0x1f;
        uVar11 = (uint)((ulonglong)uVar7 * (ulonglong)uVar25);
        local_a8 = uVar11 + local_cc;
        local_3c = uVar7 * iVar3 + iVar15 * uVar25 +
                   (int)((ulonglong)uVar7 * (ulonglong)uVar25 >> 0x20) + local_c4 +
                   (uint)(local_a8 < uVar11);
        uVar11 = (uint)((ulonglong)uVar7 * (ulonglong)uVar27);
        local_b0 = uVar11 + local_bc;
        local_34 = uVar7 * iVar4 + iVar15 * uVar27 +
                   (int)((ulonglong)uVar7 * (ulonglong)uVar27 >> 0x20) + local_b4 +
                   (uint)(local_b0 < uVar11);
        uVar11 = (uint)((ulonglong)uVar7 * (ulonglong)uVar29);
        local_a0 = uVar11 + local_ac;
        local_2c = uVar7 * iVar5 + iVar15 * uVar29 +
                   (int)((ulonglong)uVar7 * (ulonglong)uVar29 >> 0x20) + local_a4 +
                   (uint)(local_a0 < uVar11);
      }
      uVar11 = *(uint *)(param_2 + 0x20);
      uVar7 = uVar11;
      if ((int)uVar11 < 0) {
        uVar7 = uVar11 + 7;
      }
      pbVar24 = (byte *)(((int)uVar7 >> 3) + iVar23);
      uVar11 = uVar11 & 7;
      if (iVar21 < iVar18) {
        uVar7 = iVar21 + iVar12;
        do {
          iVar15 = ((byte)(&DAT_c08b31b0)[(uVar7 & 0xf) + (uVar6 & 0xf) * 0x10] & 0x7f) * 2;
          iVar30 = 0xff;
          if ((local_3c >> 0x10 & 0xff) + iVar15 < 0xff) {
            iVar30 = 0;
          }
          uVar28 = 0xff;
          if ((local_34 >> 0x10 & 0xff) + iVar15 < 0xff) {
            uVar28 = 0;
          }
          uVar26 = 0xff;
          if ((local_2c >> 0x10 & 0xff) + iVar15 < 0xff) {
            uVar26 = 0;
          }
          if (iVar14 != 0) {
            pbVar24 = (byte *)FUN_c08947dc(param_1,iVar21,iVar22);
          }
          uVar19 = 7 - uVar11;
          iVar15 = (**(code **)(param_2 + 0xd8))
                             (*(undefined4 *)(param_2 + 0xdc),(iVar30 << 8 | uVar28) << 8 | uVar26);
          uVar11 = uVar11 + 1;
          *pbVar24 = ~(byte)(1 << (uVar19 & 0x1f)) & *pbVar24 | (byte)(iVar15 << (uVar19 & 0x1f));
          if (uVar11 == 8) {
            uVar11 = 0;
            pbVar24 = pbVar24 + 1;
          }
          local_3c = local_3c + iVar3 + (uint)(local_a8 + uVar25 < local_a8);
          local_34 = local_34 + iVar4 + (uint)(local_b0 + uVar27 < local_b0);
          local_2c = local_2c + iVar5 + (uint)(local_a0 + uVar29 < local_a0);
          iVar21 = iVar21 + 1;
          uVar7 = uVar7 + 1;
          local_b0 = local_b0 + uVar27;
          local_a8 = local_a8 + uVar25;
          local_a0 = local_a0 + uVar29;
        } while (iVar21 < iVar18);
      }
      iVar23 = iVar23 + iVar8;
      local_c4 = local_c4 + iVar9 + (uint)(local_cc + uVar10 < local_cc);
      local_b4 = local_b4 + iVar17 + (uint)(local_bc + uVar1 < local_bc);
      local_a4 = local_a4 + iVar20 + (uint)(local_ac + uVar2 < local_ac);
      iVar22 = iVar22 + 1;
      uVar6 = uVar6 + 1;
      local_cc = local_cc + uVar10;
      local_bc = local_bc + uVar1;
      local_ac = local_ac + uVar2;
    } while (iVar22 < iVar13);
  }
  return;
}



/* c08a39b0 FUN_c08a39b0 */

/* Boundary evidence: original MIPS .pdata c08a39b0..c08a3baf. Semantic name remains unreviewed. */

undefined4 FUN_c08a39b0(int *param_1,int *param_2,undefined *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined ***pppuVar9;
  int *piVar10;
  int iVar11;
  undefined **local_c0 [3];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_98;
  undefined1 auStack_70 [4];
  undefined ***local_6c;
  undefined4 local_3c;
  undefined4 local_38;
  
  piVar10 = (int *)param_1[2];
  local_c0[0] = &PTR_FUN_c089104c;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_98 = 0;
  memset(auStack_70,0,0x58);
  iVar2 = *param_2;
  iVar11 = param_2[4];
  iVar1 = iVar2;
  if (iVar2 <= iVar11) {
    iVar1 = iVar11;
  }
  iVar4 = param_2[1];
  iVar5 = param_2[5];
  param_2[8] = iVar1;
  iVar3 = iVar4;
  if (iVar4 <= iVar5) {
    iVar3 = iVar5;
  }
  param_2[9] = iVar3;
  iVar6 = param_2[2];
  if (param_2[6] <= param_2[2]) {
    iVar6 = param_2[6];
  }
  param_2[10] = iVar6 - iVar1;
  iVar7 = param_2[3];
  if (param_2[7] <= param_2[3]) {
    iVar7 = param_2[7];
  }
  param_2[0xb] = iVar7 - iVar3;
  if ((iVar6 - iVar1 < 0) || (iVar7 - iVar3 < 0)) {
    FUN_c0894ac8(local_c0);
    uVar8 = 1;
  }
  else {
    iVar2 = iVar2 - iVar11;
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    param_2[0x28] = iVar2;
    iVar4 = iVar4 - iVar5;
    if (iVar4 < 1) {
      iVar4 = 0;
    }
    param_2[0x29] = iVar4;
    pppuVar9 = (undefined ***)*param_1;
    if (pppuVar9 == (undefined ***)0x0) {
      pppuVar9 = local_c0;
      FUN_c0894510((int)local_c0,param_1[4],param_1[5],param_1[8],param_1[9],
                   *(int *)(&LAB_c089119c + param_1[0xb] * 4));
    }
    uVar8 = 1;
    local_38 = 1;
    local_3c = 1;
    local_6c = pppuVar9;
    iVar1 = (**(code **)(*piVar10 + 4))(piVar10,auStack_70);
    if (iVar1 < 0) {
      FUN_c0894ac8(local_c0);
      uVar8 = 0;
    }
    else {
      if (pppuVar9[8] != (undefined **)0x0) {
        (**(code **)(*piVar10 + 0x60))(piVar10);
      }
      (*(code *)param_3)(pppuVar9,param_2);
      (**(code **)(*piVar10 + 8))(piVar10,auStack_70);
      FUN_c0894ac8(local_c0);
    }
  }
  return uVar8;
}



/* c08a3bb0 FUN_c08a3bb0 */

/* Boundary evidence: original MIPS .pdata c08a3bb0..c08a4603. Semantic name remains unreviewed. */

undefined4
FUN_c08a3bb0(int *param_1,int param_2,int *param_3,int param_4,undefined4 param_5,int *param_6,
            uint param_7,undefined4 param_8,undefined4 *param_9,int param_10)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  undefined4 extraout_v1_01;
  undefined4 extraout_v1_02;
  undefined4 extraout_v1_03;
  undefined4 extraout_v1_04;
  undefined4 extraout_v1_05;
  undefined4 extraout_v1_06;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  code *local_468;
  int local_460;
  int local_45c;
  int local_458;
  int local_454;
  int local_450;
  int local_44c;
  int local_448;
  int local_444;
  undefined4 local_430;
  int local_42c;
  undefined4 local_428;
  int local_424;
  undefined4 local_420;
  int local_41c;
  undefined4 local_418;
  int local_414;
  int local_410;
  undefined4 local_40c;
  int local_408;
  undefined4 local_404;
  int local_400;
  undefined4 local_3fc;
  int local_3f8;
  undefined4 local_3f4;
  int local_3f0;
  undefined4 local_3ec;
  int local_3e8;
  undefined4 local_3e4;
  int local_3e0;
  undefined4 local_3dc;
  int local_3d8;
  undefined4 local_3d4;
  undefined4 local_3d0;
  undefined4 local_3cc;
  int local_3c8;
  undefined4 local_3b8;
  undefined4 local_3b4;
  undefined4 local_3b0;
  undefined4 local_3ac;
  int local_3a8;
  int local_3a4;
  int local_3a0;
  int local_39c;
  uint local_398;
  uint local_394;
  uint local_390;
  uint local_38c;
  undefined4 uStack_388;
  int iStack_384;
  int aiStack_380 [2];
  int local_378;
  int local_370;
  int local_36c;
  int local_368;
  int local_364;
  int local_360;
  int local_35c;
  int local_358;
  int local_354;
  int local_350;
  int local_34c [201];
  
  iVar6 = param_1[0xb];
  if (iVar6 == 1) {
    FUN_c089d244(param_3,&iStack_384,&uStack_388,aiStack_380);
    local_468 = FUN_c08a3348;
  }
  else if (iVar6 == 2) {
    FUN_c089d244(param_3,&iStack_384,&uStack_388,aiStack_380);
    local_468 = FUN_c08a332c;
  }
  else if (iVar6 == 3) {
    FUN_c089d244(param_3,&iStack_384,&uStack_388,aiStack_380);
    local_468 = FUN_c08a3310;
  }
  else if (iVar6 == 4) {
    puVar11 = (uint *)param_3[4];
    if (((*puVar11 == 0xf800) && (puVar11[1] == 0x7e0)) && (puVar11[2] == 0x1f)) {
      local_468 = FUN_c08a2c0c;
    }
    else if (((*puVar11 == 0x7c00) && (puVar11[1] == 0x3e0)) && (puVar11[2] == 0x1f)) {
      local_468 = FUN_c08a2c28;
    }
    else {
      iVar6 = 0;
      local_3a8 = 0;
      for (uVar14 = *puVar11; uVar14 != 0; uVar14 = uVar14 >> 1) {
        if ((uVar14 & 1) != 0) {
          iVar6 = iVar6 + 1;
        }
        local_3a8 = local_3a8 + 1;
      }
      local_3a8 = local_3a8 - iVar6;
      local_3b8 = 0;
      iVar6 = 0;
      local_3a4 = 0;
      for (uVar14 = puVar11[1]; uVar14 != 0; uVar14 = uVar14 >> 1) {
        if ((uVar14 & 1) != 0) {
          iVar6 = iVar6 + 1;
        }
        local_3a4 = local_3a4 + 1;
      }
      local_3a4 = local_3a4 - iVar6;
      local_3b4 = 0;
      iVar6 = 0;
      local_3a0 = 0;
      for (uVar14 = puVar11[2]; uVar14 != 0; uVar14 = uVar14 >> 1) {
        if ((uVar14 & 1) != 0) {
          iVar6 = iVar6 + 1;
        }
        local_3a0 = local_3a0 + 1;
      }
      local_3a0 = local_3a0 - iVar6;
      local_3b0 = 0;
      local_398 = *puVar11;
      local_394 = puVar11[1];
      local_390 = puVar11[2];
      local_468 = FUN_c08a2c7c;
      local_38c = 0;
    }
  }
  else if (iVar6 == 5) {
    local_468 = FUN_c08a1e4c;
    if (*(short *)((int)param_3 + 10) == 8) {
      local_390 = 0xff;
      local_3a8 = 0x10;
      local_3a0 = 0;
      local_398 = 0xff0000;
    }
    else {
      if (*(short *)((int)param_3 + 10) != 4) {
        puVar11 = (uint *)param_3[4];
        iVar6 = 0;
        local_3a8 = 0;
        for (uVar14 = *puVar11; uVar14 != 0; uVar14 = uVar14 >> 1) {
          if ((uVar14 & 1) != 0) {
            iVar6 = iVar6 + 1;
          }
          local_3a8 = local_3a8 + 1;
        }
        local_3a8 = local_3a8 - iVar6;
        local_3b8 = 0;
        iVar6 = 0;
        local_3a4 = 0;
        for (uVar14 = puVar11[1]; uVar14 != 0; uVar14 = uVar14 >> 1) {
          if ((uVar14 & 1) != 0) {
            iVar6 = iVar6 + 1;
          }
          local_3a4 = local_3a4 + 1;
        }
        local_3a4 = local_3a4 - iVar6;
        local_3b4 = 0;
        iVar6 = 0;
        local_3a0 = 0;
        for (uVar14 = puVar11[2]; uVar14 != 0; uVar14 = uVar14 >> 1) {
          if ((uVar14 & 1) != 0) {
            iVar6 = iVar6 + 1;
          }
          local_3a0 = local_3a0 + 1;
        }
        local_3a0 = local_3a0 - iVar6;
        local_3b0 = 0;
        local_398 = *puVar11;
        local_394 = puVar11[1];
        local_390 = puVar11[2];
        local_38c = 0;
        goto LAB_c08a40f0;
      }
      local_3a0 = 0x10;
      local_3a8 = 0;
      local_398 = 0xff;
      local_390 = 0xff0000;
    }
    local_394 = 0xff00;
    local_3a4 = 8;
    local_3b8 = 0;
    local_3b4 = 0;
    local_3b0 = 0;
    local_3ac = 0;
    local_39c = 0;
    local_38c = 0;
  }
  else if (iVar6 == 6) {
    local_468 = FUN_c08a15b4;
    if (*(short *)((int)param_3 + 10) == 8) {
      local_3a8 = 0x10;
      local_3a0 = 0;
      local_398 = 0xff0000;
      local_390 = 0xff;
    }
    else {
      if (*(short *)((int)param_3 + 10) != 4) {
        puVar11 = (uint *)param_3[4];
        iVar6 = 0;
        local_3a8 = 0;
        for (uVar14 = *puVar11; uVar14 != 0; uVar14 = uVar14 >> 1) {
          if ((uVar14 & 1) != 0) {
            iVar6 = iVar6 + 1;
          }
          local_3a8 = local_3a8 + 1;
        }
        local_3a8 = local_3a8 - iVar6;
        local_3b8 = 0;
        iVar6 = 0;
        local_3a4 = 0;
        for (uVar14 = puVar11[1]; uVar14 != 0; uVar14 = uVar14 >> 1) {
          if ((uVar14 & 1) != 0) {
            iVar6 = iVar6 + 1;
          }
          local_3a4 = local_3a4 + 1;
        }
        local_3a4 = local_3a4 - iVar6;
        local_3b4 = 0;
        iVar6 = 0;
        local_3a0 = 0;
        for (uVar14 = puVar11[2]; uVar14 != 0; uVar14 = uVar14 >> 1) {
          if ((uVar14 & 1) != 0) {
            iVar6 = iVar6 + 1;
          }
          local_3a0 = local_3a0 + 1;
        }
        local_3a0 = local_3a0 - iVar6;
        local_3b0 = 0;
        local_398 = *puVar11;
        local_394 = puVar11[1];
        local_390 = puVar11[2];
        local_38c = 0;
        if (param_3[3] == 4) {
          iVar6 = 0;
          local_39c = 0;
          for (uVar14 = puVar11[3]; uVar14 != 0; uVar14 = uVar14 >> 1) {
            if ((uVar14 & 1) != 0) {
              iVar6 = iVar6 + 1;
            }
            local_39c = local_39c + 1;
          }
          local_39c = local_39c - iVar6;
          local_3ac = 0;
          local_38c = puVar11[3];
        }
        goto LAB_c08a40f0;
      }
      local_3a0 = 0x10;
      local_398 = 0xff;
      local_3a8 = 0;
      local_390 = 0xff0000;
    }
    local_394 = 0xff00;
    local_39c = 0x18;
    local_3a4 = 8;
    local_3b8 = 0;
    local_3b4 = 0;
    local_3b0 = 0;
    local_3ac = 0;
    local_38c = 0xff000000;
  }
LAB_c08a40f0:
  uVar14 = 0;
  if (param_7 != 0) {
    do {
      piVar7 = (int *)(*param_6 * 0x10 + param_4);
      piVar9 = (int *)(param_6[1] * 0x10 + param_4);
      local_358 = piVar7[2];
      local_354 = piVar7[3];
      piVar8 = &local_360;
      piVar13 = &local_370;
      local_360 = *piVar7;
      local_35c = piVar7[1];
      local_370 = *piVar9;
      local_36c = piVar9[1];
      local_368 = piVar9[2];
      local_364 = piVar9[3];
      if (param_10 == 0) {
        if (*piVar9 < *piVar7) {
          piVar8 = &local_370;
          piVar13 = &local_360;
        }
        iVar6 = piVar13[1];
        if (iVar6 < piVar8[1]) {
          piVar13[1] = piVar8[1];
          piVar8[1] = iVar6;
        }
      }
      else {
        if (piVar9[1] < piVar7[1]) {
          piVar8 = &local_370;
          piVar13 = &local_360;
        }
        iVar6 = *piVar13;
        if (iVar6 < *piVar8) {
          *piVar13 = *piVar8;
          *piVar8 = iVar6;
        }
      }
      iVar6 = piVar13[1];
      local_448 = *piVar13;
      iVar15 = *piVar8;
      iVar16 = piVar8[1];
      local_3d0 = *param_9;
      local_3cc = param_9[1];
      iVar12 = local_448 - iVar15;
      iVar10 = iVar6 - iVar16;
      local_3c8 = param_10;
      if (iVar12 < 1) {
        return 1;
      }
      if (iVar10 < 1) {
        return 1;
      }
      local_430 = 0;
      local_42c = (uint)*(ushort *)(piVar8 + 2) << 8;
      uVar2 = *(ushort *)((int)piVar8 + 10);
      local_424 = (uint)uVar2 << 8;
      uVar3 = *(ushort *)(piVar8 + 3);
      local_41c = (uint)uVar3 << 8;
      uVar4 = *(ushort *)((int)piVar8 + 0xe);
      local_414 = (uint)uVar4 << 8;
      iVar5 = (uint)*(ushort *)(piVar13 + 2) * 0x100 + (uint)*(ushort *)(piVar8 + 2) * -0x100;
      local_428 = 0;
      local_420 = 0;
      local_418 = 0;
      local_450 = iVar15;
      local_44c = iVar16;
      local_444 = iVar6;
      local_378 = local_448;
      if (param_10 == 0) {
        iVar10 = iVar12 >> 0x1f;
        local_3f8 = 0;
        local_3f4 = 0;
        local_400 = 0;
        local_3fc = 0;
        local_408 = 0;
        local_404 = 0;
        local_410 = 0;
        local_40c = 0;
        local_3f0 = FUN_c08a14bc(0,iVar5,1,0,iVar12,iVar10);
        local_3ec = extraout_v1;
        local_3e8 = FUN_c08a14bc(0,(uint)*(ushort *)((int)piVar13 + 10) * 0x100 +
                                   (uint)uVar2 * -0x100,1,0,iVar12,iVar10);
        local_3e4 = extraout_v1_00;
        local_3e0 = FUN_c08a14bc(0,(uint)*(ushort *)(piVar13 + 3) * 0x100 + (uint)uVar3 * -0x100,1,0
                                 ,iVar12,iVar10);
        local_3dc = extraout_v1_01;
        local_3d8 = FUN_c08a14bc(0,(uint)*(ushort *)((int)piVar13 + 0xe) * 0x100 +
                                   (uint)uVar4 * -0x100,1,0,iVar12,iVar10);
        local_3d4 = extraout_v1_02;
      }
      else {
        iVar12 = iVar10 >> 0x1f;
        local_3d8 = 0;
        local_3d4 = 0;
        local_3e0 = 0;
        local_3dc = 0;
        local_3e8 = 0;
        local_3e4 = 0;
        local_3f0 = 0;
        local_3ec = 0;
        local_410 = FUN_c08a14bc(0,iVar5,1,0,iVar10,iVar12);
        local_40c = extraout_v1_03;
        local_408 = FUN_c08a14bc(0,(uint)*(ushort *)((int)piVar13 + 10) * 0x100 +
                                   (uint)uVar2 * -0x100,1,0,iVar10,iVar12);
        local_404 = extraout_v1_04;
        local_400 = FUN_c08a14bc(0,(uint)*(ushort *)(piVar13 + 3) * 0x100 + (uint)uVar3 * -0x100,1,0
                                 ,iVar10,iVar12);
        local_3fc = extraout_v1_05;
        local_3f8 = FUN_c08a14bc(0,(uint)*(ushort *)((int)piVar13 + 0xe) * 0x100 +
                                   (uint)uVar4 * -0x100,1,0,iVar10,iVar12);
        local_3f4 = extraout_v1_06;
      }
      if (param_2 == 0) {
LAB_c08a457c:
        local_458 = local_378;
        local_460 = iVar15;
        local_45c = iVar16;
        local_454 = iVar6;
LAB_c08a4594:
        iVar6 = FUN_c08a39b0(param_1,&local_460,local_468);
        if (iVar6 == 0) {
          return 0;
        }
      }
      else {
        bVar1 = *(byte *)(param_2 + 0x14);
        if (bVar1 < 2) {
          if (bVar1 == 0) goto LAB_c08a457c;
          local_458 = *(int *)(param_2 + 0xc);
          local_460 = *(int *)(param_2 + 4);
          local_45c = *(int *)(param_2 + 8);
          local_454 = *(int *)(param_2 + 0x10);
          goto LAB_c08a4594;
        }
        if (bVar1 == 3) {
          (*DAT_c08bc878)(param_2,1,0,4,0);
          local_350 = 0;
          iVar6 = 1;
          while( true ) {
            piVar7 = local_34c;
            while (local_350 != 0) {
              local_460 = *piVar7;
              local_350 = local_350 + -1;
              local_45c = piVar7[1];
              local_458 = piVar7[2];
              local_454 = piVar7[3];
              piVar7 = piVar7 + 4;
              iVar10 = FUN_c08a39b0(param_1,&local_460,local_468);
              if (iVar10 == 0) {
                return 0;
              }
            }
            if (iVar6 == 0) break;
            iVar6 = (*DAT_c08bc864)(param_2,0x324,&local_350);
          }
        }
      }
      uVar14 = uVar14 + 1;
      param_6 = param_6 + 2;
    } while (uVar14 < param_7);
  }
  return 1;
}



/* c08a4604 FUN_c08a4604 */

/* Boundary evidence: original MIPS .pdata c08a4604..c08a467f. Semantic name remains unreviewed. */

void FUN_c08a4604(int *param_1,int *param_2,int param_3,uint *param_4,int *param_5,int *param_6,
                 undefined4 *param_7)

{
  FUN_c0893618(param_1,param_2,(int *)0x0,param_3,param_4,param_5,param_6,(int *)0x0,(int *)0x0,0,
               0xcccc,0x10,1,*param_7);
  return;
}



/* c08a4680 FUN_c08a4680 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c08a4680..c08a48e3. Semantic name remains unreviewed. */

int FUN_c08a4680(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  LPVOID lpAddress;
  int iVar5;
  
  lpAddress = (LPVOID)0x0;
  iVar2 = FUN_c08a9f30(-0x3f74ca0c);
  if ((iVar2 != 0) && (iVar2 = FUN_c08a936c(&DAT_c08beec0), iVar2 != 0)) {
    lpAddress = VirtualAlloc((LPVOID)0x0,0x10000,0x1000,0x40);
    if (lpAddress == (LPVOID)0x0) {
      iVar2 = 0;
    }
    if (iVar2 != 0) {
      DAT_c08beed8 = VirtualAlloc((LPVOID)0x0,0x1000,0x1000,4);
      if (DAT_c08beed8 == (LPVOID)0x0) {
        iVar2 = 0;
      }
      if (iVar2 != 0) {
        DAT_c08beedc = VirtualAlloc((LPVOID)0x0,0x1000,0x1000,4);
        if (DAT_c08beedc == (LPVOID)0x0) {
          iVar2 = 0;
        }
        if (iVar2 != 0) {
          memset(&DAT_c08bee38,0,0x88);
          DAT_c08bee3c = 0x10;
          iVar5 = 0;
          uVar4 = 0;
          puVar1 = (undefined4 *)&DAT_c08bee38;
          do {
            *(LPVOID *)((int)&DAT_c08bebc4 + uVar4) = lpAddress;
            *(undefined4 *)((int)&DAT_c08bebb8 + uVar4) = 0;
            *(undefined4 *)((int)&DAT_c08bebbc + uVar4) = 0;
            *(undefined4 *)((int)&DAT_c08bebd0 + uVar4) = 0;
            uVar3 = puVar1[3];
            *(int *)((int)&DAT_c08bebc0 + uVar4) = iVar5;
            *(undefined4 *)((int)&DAT_c08bebc8 + uVar4) = 0;
            *(undefined4 *)((int)&DAT_c08bebcc + uVar4) = 0;
            puVar1[3] = uVar3 & 0xc00400ff | 0x80040000;
            *(undefined1 *)(puVar1 + 3) = 1;
            *(undefined4 *)((int)&DAT_c08bebd8 + uVar4) = 0;
            *(undefined4 *)((int)&DAT_c08bebd4 + uVar4) = 0;
            puVar1[2] = lpAddress;
            uVar4 = uVar4 + 0x28;
            puVar1[3] = puVar1[3] | 0x40000000;
            lpAddress = (LPVOID)((int)lpAddress + 0x1000);
            iVar5 = iVar5 + 1;
            puVar1 = puVar1 + 2;
          } while (uVar4 < 0x280);
          CeSetExtendedPdata(&DAT_c08bee38);
          DAT_c08beee0 = 1;
          return iVar2;
        }
      }
    }
  }
  if (DAT_c08beedc != (LPVOID)0x0) {
    VirtualFree(DAT_c08beedc,0x1000,0x4000);
    DAT_c08beedc = (LPVOID)0x0;
  }
  if (DAT_c08beed8 != (LPVOID)0x0) {
    VirtualFree(DAT_c08beed8,0x1000,0x4000);
    DAT_c08beed8 = (LPVOID)0x0;
  }
  if (lpAddress != (LPVOID)0x0) {
    VirtualFree(lpAddress,0x10000,0x4000);
  }
  DAT_c08beee0 = 1;
  return 0;
}



/* c08a48e4 FUN_c08a48e4 */

void FUN_c08a48e4(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0x78;
  do {
    *(undefined4 *)((int)&DAT_c08bebb8 + uVar4) = 0;
    *(undefined4 *)((int)&DAT_c08bebbc + uVar4) = 0;
    *(undefined4 *)((int)&DAT_c08bebc8 + uVar4) = 0;
    *(undefined4 *)((int)&DAT_c08bebcc + uVar4) = 0;
    puVar1 = (undefined4 *)((int)&DAT_c08bebd0 + uVar4);
    puVar2 = (undefined4 *)((int)&DAT_c08bebd4 + uVar4);
    puVar3 = (undefined4 *)((int)&DAT_c08bebd8 + uVar4);
    uVar4 = uVar4 + 0x28;
    *puVar1 = 0;
    *puVar2 = 0;
    *puVar3 = 0;
  } while (uVar4 < 0x280);
  return;
}



/* c08a493c FUN_c08a493c */

undefined4 * FUN_c08a493c(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  while ((*param_1 != *(int *)((int)&DAT_c08bebb8 + uVar1) ||
         (param_1[1] != *(int *)((int)&DAT_c08bebbc + uVar1)))) {
    uVar1 = uVar1 + 0x28;
    iVar2 = iVar2 + 1;
    if (0x27f < uVar1) {
      return (undefined4 *)0x0;
    }
  }
  (&DAT_c08bebcc)[iVar2 * 10] = DAT_c08beee0;
  return &DAT_c08bebb8 + iVar2 * 10;
}



/* c08a49b4 FUN_c08a49b4 */

void FUN_c08a49b4(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 3;
  iVar2 = 4;
  uVar1 = 0xa0;
  uVar3 = DAT_c08bec44;
  do {
    if (*(uint *)((int)&DAT_c08bebcc + uVar1) < uVar3) {
      uVar3 = *(uint *)((int)&DAT_c08bebcc + uVar1);
      iVar4 = iVar2;
    }
    uVar1 = uVar1 + 0x28;
    iVar2 = iVar2 + 1;
  } while (uVar1 < 0x280);
  (&DAT_c08bebb8)[iVar4 * 10] = *param_1;
  (&DAT_c08bebbc)[iVar4 * 10] = param_1[1];
  (&DAT_c08bebcc)[iVar4 * 10] = DAT_c08beee0;
  (&DAT_c08bebc8)[iVar4 * 10] = 0;
  (&DAT_c08bebd0)[iVar4 * 10] = 0;
  (&DAT_c08bebd4)[iVar4 * 10] = 0;
  (&DAT_c08bebd8)[iVar4 * 10] = 0;
  return;
}



/* c08a4a64 FUN_c08a4a64 */

/* Boundary evidence: original MIPS .pdata c08a4a64..c08a4b37. Semantic name remains unreviewed. */

undefined4 * FUN_c08a4a64(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_c08a493c((int *)param_1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_c08a49b4(param_1);
    FUN_c08a9794(-0x3f74ca0c,DAT_c08beed8,param_1);
    CacheRangeFlush(puVar1[3],0x1000,2);
    uVar2 = (*DAT_c08beec0)(puVar1[2],DAT_c08beed8,param_1,puVar1[3]);
    puVar1[4] = uVar2;
    CacheRangeFlush(puVar1[3],0x1000,4);
    if (puVar1[4] == 0) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1[8] = 0;
      puVar1 = (undefined4 *)0x0;
    }
  }
  return puVar1;
}



/* c08a4b38 FUN_c08a4b38 */

undefined4 FUN_c08a4b38(int *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = 0;
  if (-1 < param_2) {
    if (param_2 < 4) {
      uVar1 = 7;
    }
    else if (param_2 == 4) {
      piVar2 = (int *)*param_1;
      uVar1 = 9;
      if (piVar2 != (int *)0x0) {
        if (((*piVar2 == 0xf800) && (piVar2[1] == 0x7e0)) && (piVar2[2] == 0x1f)) {
          uVar1 = 5;
        }
        else if (((param_1[1] == 3) && (*piVar2 == 0x7a00)) &&
                ((piVar2[1] == 0x3e0 && (piVar2[2] == 0x1f)))) {
          uVar1 = 6;
        }
      }
    }
    else if (param_2 == 5) {
      piVar2 = (int *)*param_1;
      uVar1 = 9;
      if (piVar2 != (int *)0x0) {
        if (((*piVar2 == 0xff0000) && (piVar2[1] == 0xff00)) && (piVar2[2] == 0xff)) {
          uVar1 = 3;
        }
        else if (((*piVar2 == 0xff) && (piVar2[1] == 0xff00)) && (piVar2[2] == 0xff0000)) {
          uVar1 = 4;
        }
      }
    }
    else if (param_2 == 6) {
      piVar2 = (int *)*param_1;
      uVar1 = 9;
      if (piVar2 != (int *)0x0) {
        if (((*piVar2 == 0xff0000) && (piVar2[1] == 0xff00)) && (piVar2[2] == 0xff)) {
          uVar1 = 1;
        }
        else if (((*piVar2 == 0xff) && (piVar2[1] == 0xff00)) && (piVar2[2] == 0xff0000)) {
          uVar1 = 2;
        }
      }
    }
  }
  return uVar1;
}



/* c08a4ccc FUN_c08a4ccc */

/* Boundary evidence: original MIPS .pdata c08a4ccc..c08a4eef. Semantic name remains unreviewed. */

undefined4 FUN_c08a4ccc(int param_1,int param_2)

{
  uint uVar1;
  uint local_28;
  undefined4 local_24;
  int local_20 [4];
  
  if (DAT_c08beec0 == (code *)0x0) {
    return 0;
  }
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  if (param_2 != 0) {
    local_20[1] = 3;
  }
  local_28 = 0;
  local_24 = 0;
  local_20[0] = param_2;
  uVar1 = FUN_c08a4b38(local_20,param_1);
  local_28 = uVar1 & 0xf | 0xc000;
  if (param_1 == 3) {
    local_24 = (uint)((ushort)local_24 | 1);
  }
  else {
    if (param_1 == 4) {
      local_24._0_2_ = (ushort)local_24 | 2;
    }
    else if (param_1 == 5) {
      local_24._0_2_ = (ushort)local_24 | 4;
    }
    else {
      if (param_1 != 6) goto LAB_c08a4d88;
      local_24._0_2_ = (ushort)local_24 | 8;
    }
    local_24 = (uint)(ushort)local_24;
  }
LAB_c08a4d88:
  local_24 = CONCAT22(0xf0f0,(ushort)local_24);
  FUN_c08a9794(-0x3f74ca0c,DAT_c08beed8,&local_28);
  CacheRangeFlush(DAT_c08bebc4,0x1000,2);
  DAT_c08bebc8 = (*DAT_c08beec0)(DAT_c08bebc0,DAT_c08beed8,&local_28,DAT_c08bebc4);
  CacheRangeFlush(DAT_c08bebc4,0x1000,4);
  local_24 = CONCAT22(0xaaf0,(ushort)local_24);
  FUN_c08a9794(-0x3f74ca0c,DAT_c08beed8,&local_28);
  CacheRangeFlush(DAT_c08bec14,0x1000,2);
  DAT_c08bec18 = (*DAT_c08beec0)(DAT_c08bec10,DAT_c08beed8,&local_28,DAT_c08bec14);
  CacheRangeFlush(DAT_c08bec14,0x1000,4);
  local_28 = (local_28 << 4 ^ local_28) & 0xf0 ^ local_28;
  local_24 = CONCAT22(0xcccc,((ushort)local_24 << 2 ^ (ushort)local_24) & 0x10 ^ (ushort)local_24);
  FUN_c08a9794(-0x3f74ca0c,DAT_c08beed8,&local_28);
  CacheRangeFlush(DAT_c08bebec,0x1000,2);
  DAT_c08bebf0 = (*DAT_c08beec0)(DAT_c08bebe8,DAT_c08beed8,&local_28,DAT_c08bebec);
  CacheRangeFlush(DAT_c08bebec,0x1000,4);
  FUN_c0894910(local_20);
  return 0;
}



/* c08a4ef0 FUN_c08a4ef0 */

/* Boundary evidence: original MIPS .pdata c08a4ef0..c08a548b. Semantic name remains unreviewed. */

undefined4 FUN_c08a4ef0(int param_1,uint *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  
  uVar11 = *(ushort *)(param_1 + 0x28);
  bVar3 = ((uVar11 >> 2 ^ uVar11) & 0x3333) != 0;
  iVar9 = *(int *)(param_1 + 0x10);
  uVar12 = *(uint *)(param_1 + 0x24);
  iVar10 = *(int *)(param_1 + 0x4c);
  bVar4 = false;
  bVar5 = false;
  bVar1 = false;
  bVar6 = false;
  bVar2 = false;
  bVar7 = false;
  if ((bVar3) && ((uVar12 & 8) != 0)) {
    piVar13 = *(int **)(param_1 + 0x18);
    piVar15 = *(int **)(param_1 + 0x14);
    iVar16 = piVar15[2] - *piVar15;
    bVar1 = iVar16 < 0;
    iVar14 = piVar15[3] - piVar15[1];
    if (bVar1) {
      iVar16 = -iVar16;
    }
    bVar2 = iVar14 < 0;
    if (bVar2) {
      iVar14 = -iVar14;
    }
    if (piVar13[2] - *piVar13 < iVar16) {
      bVar5 = true;
    }
    else if (iVar16 < piVar13[2] - *piVar13) {
      bVar4 = true;
    }
    if (piVar13[3] - piVar13[1] < iVar14) {
      bVar6 = true;
    }
    else if (iVar14 < piVar13[3] - piVar13[1]) {
      bVar7 = true;
    }
  }
  *param_2 = 0;
  param_2[1] = 0;
  uVar8 = FUN_c08a4b38((int *)(*(int *)(param_1 + 4) + 0xc),*(int *)(*(int *)(param_1 + 4) + 0x1c));
  uVar8 = (uVar8 ^ *param_2) & 0xf ^ *param_2;
  *param_2 = uVar8;
  uVar8 = ((uint)(*(int *)(*(int *)(param_1 + 4) + 0x20) == 0) << 0x18 ^ uVar8) & 0x1000000 ^ uVar8;
  *param_2 = uVar8;
  if (DAT_c08bc8a0 != 0) {
    *param_2 = uVar8 & 0xfffffff8 | 8;
  }
  if (bVar1) {
    *param_2 = *param_2 | 0x10000000;
  }
  if (bVar2) {
    *param_2 = *param_2 | 0x20000000;
  }
  if (bVar3) {
    iVar16 = FUN_c08a4b38((int *)(*(int *)(param_1 + 8) + 0xc),
                          *(int *)(*(int *)(param_1 + 8) + 0x1c));
    uVar8 = (iVar16 << 4 ^ *param_2) & 0xf0 ^ *param_2;
    *param_2 = uVar8;
    *param_2 = ((uint)(*(int *)(*(int *)(param_1 + 8) + 0x20) == 0) << 0x19 ^ uVar8) & 0x2000000 ^
               uVar8;
  }
  if (iVar9 != 0) {
    uVar8 = ((uint)(*(int *)(param_1 + 0x20) == -1) << 0xd ^ *param_2) & 0x2000 ^ *param_2;
    *param_2 = uVar8;
    if ((uVar8 & 0x2000) != 0) {
      *param_2 = ((uint)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) == 0) << 0x1a ^ uVar8) &
                 0x4000000 ^ uVar8;
    }
  }
  if ((uVar12 & 4) != 0) {
    *param_2 = *param_2 & 0xff7fffff | 0x400000;
  }
  uVar12 = ((uint)(*(int *)(param_1 + 0x34) != 0) << 0xe ^ *param_2) & 0x4000 ^ *param_2;
  *param_2 = uVar12;
  uVar12 = ((uint)(*(int *)(param_1 + 0x38) != 0) << 0xf ^ uVar12) & 0x8000 ^ uVar12;
  *param_2 = uVar12;
  if (bVar5) {
    uVar12 = uVar12 & 0xfff1ffff | 0x10000;
LAB_c08a5288:
    *param_2 = uVar12;
  }
  else if (bVar4) {
    uVar12 = uVar12 & 0xfff4ffff | 0x40000;
    goto LAB_c08a5288;
  }
  if (bVar6) {
    *param_2 = *param_2 | 0x20000;
  }
  else if (bVar7) {
    *param_2 = *param_2 | 0x80000;
  }
  if (iVar10 != 0xff0000) {
    uVar12 = ((uint)(*(char *)(param_1 + 0x4e) != -1) << 0x14 ^ *param_2) & 0x300000 ^ *param_2;
    *param_2 = uVar12;
    iVar9 = 2;
    if (*(char *)(param_1 + 0x4f) != '\x01') {
      iVar9 = 0;
    }
    *param_2 = ((iVar9 << 0x14 | uVar12) ^ uVar12) & 0x300000 ^ uVar12;
  }
  iVar9 = *(int *)(param_1 + 0x48);
  *(ushort *)((int)param_2 + 6) = uVar11;
  *param_2 = (iVar9 << 8 ^ *param_2) & 0x1f00 ^ *param_2;
  if (*(char *)((int)param_2 + 6) != *(char *)((int)param_2 + 7)) {
    *param_2 = ((uint)(*(int *)(*(int *)(param_1 + 0xc) + 0x20) == 0) << 0x1b ^ *param_2) &
               0x8000000 ^ *param_2;
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    *param_2 = *param_2 | 0x40000000;
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    *param_2 = *param_2 | 0x80000000;
  }
  iVar9 = *(int *)(*(int *)(param_1 + 4) + 0x1c);
  if (iVar9 == 3) {
    uVar11 = (ushort)param_2[1] | 1;
  }
  else if (iVar9 == 4) {
    uVar11 = (ushort)param_2[1] | 2;
  }
  else if (iVar9 == 5) {
    uVar11 = (ushort)param_2[1] | 4;
  }
  else {
    if (iVar9 != 6) goto LAB_c08a5434;
    uVar11 = (ushort)param_2[1] | 8;
  }
  *(ushort *)(param_2 + 1) = uVar11;
LAB_c08a5434:
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(*(int *)(param_1 + 8) + 0x1c) == 5)) {
    *(ushort *)(param_2 + 1) = (ushort)param_2[1] | 0x10;
  }
  return 1;
}



/* c08a548c FUN_c08a548c */

/* Boundary evidence: original MIPS .pdata c08a548c..c08a558f. Semantic name remains unreviewed. */

uint FUN_c08a548c(uint param_1,uint param_2,uint param_3,uint param_4,byte param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_5 < 0x19) {
    uVar2 = 0;
    uVar1 = 1;
    uVar3 = param_3 << 2;
    uVar4 = param_2 << 1;
    while (param_5 != 0) {
      param_5 = param_5 - 1;
      if ((1 << (param_1 & 1 | uVar4 & 2 | uVar3 & 4) & param_4) != 0) {
        uVar2 = uVar1 | uVar2;
      }
      uVar3 = uVar3 >> 1;
      uVar4 = uVar4 >> 1;
      param_1 = param_1 >> 1;
      uVar1 = uVar1 << 1;
    }
  }
  else {
    uVar1 = FUN_c08a548c(param_1 >> 0x10,param_2 >> 0x10,param_3 >> 0x10,param_4,param_5 - 0x10);
    uVar2 = FUN_c08a548c(param_1,param_2,param_3,param_4,0x10);
    uVar2 = uVar2 | uVar1 << 0x10;
  }
  return uVar2;
}



/* c08a5590 FUN_c08a5590 */

int FUN_c08a5590(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (param_1 & 0xff) - (param_2 & 0xff);
  iVar1 = (param_1 >> 8 & 0xff) - (param_2 >> 8 & 0xff);
  iVar2 = (param_1 >> 0x10 & 0xff) - (param_2 >> 0x10 & 0xff);
  return iVar2 * iVar2 + iVar1 * iVar1 + iVar3 * iVar3;
}



/* c08a55f0 FUN_c08a55f0 */

void FUN_c08a55f0(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    iVar4 = 0;
    piVar3 = param_3;
    do {
      uVar2 = *(uint *)(*(int *)(param_1 + 0xc) + iVar4);
      iVar5 = 0;
      *(uint *)((param_2 - (int)param_3) + (int)piVar3) = uVar2;
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        iVar5 = iVar5 + 1;
      }
      *piVar3 = iVar5;
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + 4;
      piVar3 = piVar3 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  if (*(int *)(param_1 + 0x10) == 3) {
    *(undefined4 *)(param_2 + 0xc) = 0;
    param_3[3] = 0;
  }
  return;
}



/* c08a5678 FUN_c08a5678 */

undefined4 FUN_c08a5678(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  iVar5 = param_3[1];
  if (param_3[1] <= param_2[1]) {
    iVar5 = param_2[1];
  }
  param_1[1] = iVar5;
  iVar4 = *param_3;
  if (*param_3 <= *param_2) {
    iVar4 = *param_2;
  }
  *param_1 = iVar4;
  iVar3 = param_3[3];
  if (param_2[3] <= param_3[3]) {
    iVar3 = param_2[3];
  }
  param_1[3] = iVar3;
  iVar2 = param_3[2];
  if (param_2[2] <= param_3[2]) {
    iVar2 = param_2[2];
  }
  param_1[2] = iVar2;
  if ((iVar2 <= iVar4) || (iVar3 <= iVar5)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c08a5708 FUN_c08a5708 */

/* Boundary evidence: original MIPS .pdata c08a5708..c08a589b. Semantic name remains unreviewed. */

uint FUN_c08a5708(uint param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = param_6[1];
  uVar7 = param_6[3];
  uVar5 = param_6[2];
  uVar3 = *param_6;
  uVar2 = param_5[3];
  uVar1 = param_5[1];
  uVar4 = (((uVar2 & param_1) >> (uVar7 & 0x1f)) << 0x10 | (uVar1 & param_1) >> (uVar6 & 0x1f)) *
          param_3 + (((uVar2 & param_2) >> (uVar7 & 0x1f)) << 0x10 |
                    (uVar1 & param_2) >> (uVar6 & 0x1f)) * param_4;
  uVar1 = ((((*param_5 & param_1) >> (uVar3 & 0x1f)) << 0x10 |
           (param_5[2] & param_1) >> (uVar5 & 0x1f)) * param_3 +
           (((*param_5 & param_2) >> (uVar3 & 0x1f)) << 0x10 |
           (param_5[2] & param_2) >> (uVar5 & 0x1f)) * param_4 >> 8 ^
          (((uVar2 & param_1) >> (uVar7 & 0x1f)) << 0x10 | (uVar1 & param_1) >> (uVar6 & 0x1f)) *
          param_3 + (((uVar2 & param_2) >> (uVar7 & 0x1f)) << 0x10 |
                    (uVar1 & param_2) >> (uVar6 & 0x1f)) * param_4) & 0xff00ff ^ uVar4;
  return (uVar1 >> 0x10 & 0xff) << (uVar3 & 0x1f) | (uVar1 >> 8 & 0xff) << (uVar6 & 0x1f) |
         (uVar1 & 0xff) << (uVar5 & 0x1f) | (uVar4 >> 0x18) << (uVar7 & 0x1f);
}



/* c08a589c FUN_c08a589c */

/* Boundary evidence: original MIPS .pdata c08a589c..c08a5a8f. Semantic name remains unreviewed. */

uint FUN_c08a589c(uint param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar9 = *param_5;
  uVar7 = param_6[1];
  uVar8 = param_6[3];
  uVar2 = param_6[2];
  uVar1 = *param_6;
  uVar3 = param_5[3];
  uVar4 = param_5[1];
  uVar6 = (((uVar3 & param_1) >> (uVar8 & 0x1f)) << 0x10 | (uVar4 & param_1) >> (uVar7 & 0x1f)) *
          param_3 + (((uVar3 & param_2) >> (uVar8 & 0x1f)) << 0x10 |
                    (uVar4 & param_2) >> (uVar7 & 0x1f)) * param_4;
  uVar5 = ((((uVar9 & param_1) >> (uVar1 & 0x1f)) << 0x10 | (param_5[2] & param_1) >> (uVar2 & 0x1f)
           ) * param_3 +
           (((uVar9 & param_2) >> (uVar1 & 0x1f)) << 0x10 | (param_5[2] & param_2) >> (uVar2 & 0x1f)
           ) * param_4 >> 8 ^
          (((uVar3 & param_1) >> (uVar8 & 0x1f)) << 0x10 | (uVar4 & param_1) >> (uVar7 & 0x1f)) *
          param_3 + (((uVar3 & param_2) >> (uVar8 & 0x1f)) << 0x10 |
                    (uVar4 & param_2) >> (uVar7 & 0x1f)) * param_4) & 0xff00ff ^ uVar6;
  uVar4 = (uVar5 >> 0x10 & 0xff) << (uVar1 & 0x1f);
  uVar3 = (uVar5 >> 8 & 0xff) << (uVar7 & 0x1f);
  uVar2 = (uVar5 & 0xff) << (uVar2 & 0x1f);
  uVar1 = (uVar6 >> 0x18) << (uVar8 & 0x1f);
  if (uVar9 < uVar4) {
    uVar4 = uVar9;
  }
  if (param_5[1] < uVar3) {
    uVar3 = param_5[1];
  }
  if (param_5[2] < uVar2) {
    uVar2 = param_5[2];
  }
  if (param_5[3] < uVar1) {
    uVar1 = param_5[3];
  }
  return uVar1 | uVar2 | uVar3 | uVar4;
}



/* c08a5a90 FUN_c08a5a90 */

/* Boundary evidence: original MIPS .pdata c08a5a90..c08a5acf. Semantic name remains unreviewed. */

void FUN_c08a5a90(ushort *param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  
  uVar1 = FUN_c08a589c((uint)*param_1,param_2,param_3,param_4,param_5,param_6);
  *param_1 = (ushort)uVar1;
  return;
}



/* c08a5ad0 FUN_c08a5ad0 */

/* Boundary evidence: original MIPS .pdata c08a5ad0..c08a5b33. Semantic name remains unreviewed. */

void FUN_c08a5ad0(byte *param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  
  uVar1 = FUN_c08a589c(((uint)param_1[2] * 0x100 + (uint)param_1[1]) * 0x100 + (uint)*param_1,
                       param_2,param_3,param_4,param_5,param_6);
  *param_1 = (byte)uVar1;
  param_1[1] = (byte)(uVar1 >> 8);
  param_1[2] = (byte)(uVar1 >> 0x10);
  return;
}



/* c08a5b34 FUN_c08a5b34 */

/* Boundary evidence: original MIPS .pdata c08a5b34..c08a5b6f. Semantic name remains unreviewed. */

void FUN_c08a5b34(uint *param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  
  uVar1 = FUN_c08a589c(*param_1,param_2,param_3,param_4,param_5,param_6);
  *param_1 = uVar1;
  return;
}



/* c08a5b70 FUN_c08a5b70 */

/* WARNING: Removing unreachable block (ram,0xc08a5c48) */

void FUN_c08a5b70(int *param_1,int param_2,int param_3,int param_4,int *param_5,int param_6,
                 int param_7)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  *param_1 = *(int *)(param_2 + 4);
  if (param_4 == 0) {
    param_1[1] = -*(int *)(param_2 + 8);
    *param_1 = ((param_5[3] - param_7) + -1) * *(int *)(param_2 + 8) + *param_1;
  }
  else {
    param_1[1] = *(int *)(param_2 + 8);
    *param_1 = (param_5[1] + param_7) * *(int *)(param_2 + 8) + *param_1;
  }
  iVar2 = *(int *)(&LAB_c0891154 + *(int *)(param_2 + 0x1c) * 4);
  param_1[9] = iVar2;
  if (iVar2 < 8) {
    cVar1 = '\b' - (char)iVar2;
  }
  else {
    cVar1 = '\0';
  }
  *(char *)(param_1 + 10) = cVar1;
  if (param_1[9] == 0) {
    trap(0x1c00);
  }
  param_1[2] = 0x20 / param_1[9] << 8;
  if (param_3 == 0) {
    iVar2 = (param_5[2] - param_6) + -1;
    param_1[4] = (param_1[9] * -0x100 + -1) * 0x100;
    param_1[2] = (0x20 - param_1[9]) * 0x10000 | param_1[2];
  }
  else {
    iVar2 = *param_5 + param_6;
    param_1[4] = (param_1[9] * 0x100 + -1) * 0x100;
  }
  param_1[5] = param_1[4] + 1;
  uVar3 = (uint)(*(int *)(param_2 + 0x1c) == 5);
  param_1[6] = uVar3;
  if (uVar3 == 0) {
    param_1[3] = param_1[2];
    *param_1 = (param_1[9] * iVar2 >> 3 & 0xfffffffcU) + *param_1;
    uVar3 = (uint)param_1[2] >> 0x10;
    while (((uVar3 ^ param_1[9] * iVar2) & 0x1f) != 0) {
      param_1[3] = param_1[3] + param_1[4];
      uVar3 = (uint)*(ushort *)((int)param_1 + 0xe);
    }
    param_1[8] = 4;
  }
  else {
    param_1[8] = 3;
    *param_1 = iVar2 * 3 + *param_1;
  }
  if (param_3 == 0) {
    param_1[8] = -param_1[8];
  }
  param_1[7] = (2 << (param_1[9] - 1U & 0x1f)) + -1;
  return;
}



/* c08a5da4 FUN_c08a5da4 */

/* Boundary evidence: original MIPS .pdata c08a5da4..c08a5f0f. Semantic name remains unreviewed. */

void FUN_c08a5da4(int *param_1,int param_2,int param_3,int param_4,int *param_5,int param_6,
                 int param_7)

{
  int iVar1;
  int iVar2;
  
  param_1[0x15] = (uint)(*(int *)(param_2 + 0x38) != 0);
  *(undefined2 *)(param_1 + 0x12) = 0;
  param_1[9] = *(int *)(&LAB_c0891154 + *(int *)(param_2 + 0x1c) * 4);
  param_1[0xf] = 0;
  *param_1 = 0;
  param_1[0xb] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[0xe] = 0;
  if (*(int *)(param_2 + 0x38) == 0) {
    FUN_c08a5b70(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    param_1[0xf] = *(int *)(param_2 + 4);
    param_1[0x17] = 0;
    param_1[0x16] = 0;
    param_1[0x19] = 0;
    param_1[0x18] = 0;
    *(short *)(param_1 + 0x12) = (short)*(undefined4 *)(param_2 + 0x38);
    param_1[0x11] = *(int *)(param_2 + 8);
    param_1[0x13] = *(int *)(param_2 + 0x3c) + -1;
    param_1[0x14] = *(int *)(param_2 + 0x40) + -1;
    if (param_4 == 0) {
      param_1[1] = -1;
      param_1[0x19] = (param_5[3] - param_7) + -1;
    }
    else {
      param_1[1] = 1;
      param_1[0x19] = param_5[1] + param_7;
    }
    if (param_3 == 0) {
      param_1[0x10] = -1;
      iVar1 = (param_5[2] - param_6) + -1;
    }
    else {
      param_1[0x10] = 1;
      iVar1 = *param_5 + param_6;
    }
    iVar2 = param_1[9];
    param_1[0x18] = iVar1;
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = iVar2 + 7;
    }
    param_1[8] = iVar1 >> 3;
    param_1[7] = 0xffffffff >> (0x20U - iVar2 & 0x1f);
  }
  return;
}



/* c08a5f10 FUN_c08a5f10 */

int FUN_c08a5f10(int param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)(param_1 + 0x48);
  if (sVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x5c) * *(int *)(param_1 + 0x44) +
            *(int *)(param_1 + 0x58) * *(int *)(param_1 + 0x20);
  }
  else {
    if (sVar1 == 1) {
      return (*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x58)) * *(int *)(param_1 + 0x44) +
             *(int *)(param_1 + 0x5c) * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x3c);
    }
    if (sVar1 == 2) {
      return (*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x5c)) * *(int *)(param_1 + 0x44) +
             (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x58)) * *(int *)(param_1 + 0x20) +
             *(int *)(param_1 + 0x3c);
    }
    if (sVar1 == 4) {
      return (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x5c)) * *(int *)(param_1 + 0x20) +
             *(int *)(param_1 + 0x58) * *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x3c);
    }
    iVar2 = *(int *)(param_1 + 0x5c) * *(int *)(param_1 + 0x44) +
            *(int *)(param_1 + 0x58) * *(int *)(param_1 + 0x20);
  }
  return iVar2 + *(int *)(param_1 + 0x3c);
}



/* c08a6078 FUN_c08a6078 */

/* Boundary evidence: original MIPS .pdata c08a6078..c08a61a3. Semantic name remains unreviewed. */

void FUN_c08a6078(int *param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_5[3] == 0) {
    param_5[3] = *(int *)(param_2 + 0x30);
  }
  FUN_c08a5b70(param_1,param_2,param_3,param_4,param_5,0,0);
  iVar1 = *(int *)(param_2 + 0x2c);
  param_1[0x10] = iVar1;
  param_1[0x13] = *(int *)(param_2 + 0x30);
  if (param_3 == 0) {
    iVar1 = param_5[2];
  }
  else {
    iVar1 = iVar1 - *param_5;
  }
  param_1[0x11] = iVar1;
  if (param_4 == 0) {
    iVar2 = param_5[3];
  }
  else {
    iVar2 = param_1[0x13] - param_5[1];
  }
  param_1[0x12] = iVar2;
  param_1[0x15] = *param_1 - (param_1[0x13] - iVar2) * param_1[1];
  uVar3 = *(int *)(&LAB_c0891154 + *(int *)(param_2 + 0x1c) * 4) * (param_1[0x10] - iVar1) >> 3 &
          0xfffffffc;
  param_1[0x14] = uVar3;
  if (param_3 == 0) {
    param_1[0x14] = -uVar3;
  }
  return;
}



/* c08a61a4 FUN_c08a61a4 */

/* Boundary evidence: original MIPS .pdata c08a61a4..c08a62bf. Semantic name remains unreviewed. */

undefined4 FUN_c08a61a4(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint auStack_9a0 [95];
  undefined4 local_824;
  
  DAT_c08beee0 = DAT_c08beee0 + 1;
  if (DAT_c08beee0 == 0) {
    FUN_c08a48e4();
  }
  puVar1 = FUN_c08a4a64((uint *)(param_2 + 0x50));
  uVar4 = 0x80004005;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = DAT_c08beee0;
    iVar2 = puVar1[7];
    uVar3 = puVar1[6];
    puVar1[7] = iVar2 + 1U;
    if ((uVar3 < 4) && (*(uint *)(&DAT_c08beec8 + uVar3 * 4) < iVar2 + 1U)) {
      CacheRangeFlush(puVar1[3],0x1000,2);
      iVar2 = (*DAT_c08beec4)(puVar1[2],puVar1[3],uVar3 + 1);
      if (iVar2 != 0) {
        CacheRangeFlush(puVar1[3],0x1000,4);
        puVar1[6] = uVar3 + 1;
      }
    }
    FUN_c08aa3d8(param_2,auStack_9a0);
    (*(code *)puVar1[4])(auStack_9a0,puVar1[3]);
    uVar4 = local_824;
  }
  return uVar4;
}



/* c08a62c0 FUN_c08a62c0 */

/* Boundary evidence: original MIPS .pdata c08a62c0..c08a6333. Semantic name remains unreviewed. */

void FUN_c08a62c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if (((param_1[9] & 0x14) == 0) && (DAT_c08beec0 != 0)) {
    FUN_c08a4ef0((int)param_1,param_1 + 0x14);
    puVar1 = FUN_c08a4a64(param_1 + 0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *param_1 = FUN_c08a61a4;
    }
  }
  return;
}



/* c08a6334 FUN_c08a6334 */

undefined4 FUN_c08a6334(undefined4 *param_1)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  
  if (*(int *)(param_1[1] + 0x1c) != 3) {
    return 0;
  }
  if ((param_1[9] & 0x1c) != 0) {
    return 0;
  }
  if (param_1[0xf] != 0) {
    return 0;
  }
  if (param_1[0x10] != 0) {
    return 0;
  }
  uVar3 = param_1[10];
  if (uVar3 < 0xaaf1) {
    if (uVar3 == 0xaaf0) {
      if (param_1[8] == -1) {
        return 0;
      }
      if (*(int *)(param_1[3] + 0x1c) == 0) {
        *param_1 = FUN_c08ac954;
        return 0;
      }
      if (*(int *)(param_1[3] + 0x1c) != 2) {
        return 0;
      }
      pcVar2 = FUN_c08ac930;
      goto LAB_c08a656c;
    }
    if (uVar3 != 0) {
      if (uVar3 == 0x5555) {
        pcVar2 = FUN_c08acc04;
      }
      else if (uVar3 == 0x5a5a) {
        if (param_1[8] != -1) {
          pcVar2 = FUN_c08acd60;
          goto LAB_c08a656c;
        }
        pcVar2 = FUN_c08acee0;
      }
      else if (uVar3 == 0x6666) {
        if (param_1[2] == 0) {
          return 0;
        }
        if (*(int *)(param_1[2] + 0x1c) != 3) {
          return 0;
        }
        pcVar2 = FUN_c08ad230;
      }
      else {
        if (uVar3 != 0x8888) {
          return 0;
        }
        if (param_1[2] == 0) {
          return 0;
        }
        if (*(int *)(param_1[2] + 0x1c) != 3) {
          return 0;
        }
        pcVar2 = FUN_c08ad698;
      }
      goto LAB_c08a6584;
    }
    param_1[8] = 0;
  }
  else {
    if (uVar3 == 0xcccc) {
      if (param_1[2] == 0) {
        return 0;
      }
      iVar1 = *(int *)(param_1[2] + 0x1c);
      if (iVar1 == 3) {
        pcVar2 = FUN_c08abbe8;
      }
      else {
        if (iVar1 != 2) {
          if (iVar1 != 0) {
            return 0;
          }
          pcVar2 = FUN_c08ab3d4;
          goto LAB_c08a6584;
        }
        pcVar2 = FUN_c08ab9d4;
      }
      goto LAB_c08a656c;
    }
    if (uVar3 == 0xeeee) {
      if (param_1[2] == 0) {
        return 0;
      }
      if (*(int *)(param_1[2] + 0x1c) != 3) {
        return 0;
      }
      pcVar2 = FUN_c08abfec;
LAB_c08a6584:
      *param_1 = pcVar2;
      return 0;
    }
    if (uVar3 != 0xf0f0) {
      if (uVar3 != 0xffff) {
        return 0;
      }
      param_1[8] = 0xffffff;
      pcVar2 = FUN_c08acb1c;
      goto LAB_c08a6584;
    }
    if (param_1[8] == -1) {
      pcVar2 = FUN_c08ac454;
      goto LAB_c08a6584;
    }
  }
  pcVar2 = FUN_c08acb1c;
LAB_c08a656c:
  *param_1 = pcVar2;
  return 0;
}



/* c08a6590 FUN_c08a6590 */

undefined4 FUN_c08a6590(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1[1] + 0x1c) != 4) {
    return 0;
  }
  if ((param_1[9] & 0x1c) != 0) {
    return 0;
  }
  if (param_1[0xf] != 0) {
    return 0;
  }
  if (param_1[0x10] != 0) {
    return 0;
  }
  uVar3 = param_1[10];
  if (uVar3 < 0xcccd) {
    if (uVar3 == 0xcccc) {
      if (param_1[2] == 0) {
        return 0;
      }
      iVar2 = *(int *)(param_1[2] + 0x1c);
      if (iVar2 == 4) {
        pcVar1 = FUN_c08ae7e4;
      }
      else {
        if (iVar2 != 2) {
          if (iVar2 != 0) {
            return 0;
          }
          pcVar1 = FUN_c08adf9c;
          goto LAB_c08a677c;
        }
        pcVar1 = FUN_c08ae5c0;
      }
      goto LAB_c08a66b4;
    }
    if (uVar3 != 0) {
      if (uVar3 == 0x6666) {
        if (param_1[2] == 0) {
          return 0;
        }
        if (*(int *)(param_1[2] + 0x1c) != 4) {
          return 0;
        }
        pcVar1 = FUN_c08aed1c;
      }
      else {
        if (uVar3 != 0x8888) {
          if (uVar3 != 0xaaf0) {
            return 0;
          }
          if (param_1[8] == -1) {
            return 0;
          }
          if (*(int *)(param_1[3] + 0x1c) == 0) {
            pcVar1 = FUN_c08af66c;
          }
          else {
            if (*(int *)(param_1[3] + 0x1c) != 2) {
              return 0;
            }
            pcVar1 = FUN_c08af648;
          }
          goto LAB_c08a66b4;
        }
        if (param_1[2] == 0) {
          return 0;
        }
        if (*(int *)(param_1[2] + 0x1c) != 4) {
          return 0;
        }
        pcVar1 = FUN_c08af1ac;
      }
      goto LAB_c08a677c;
    }
    param_1[8] = 0;
  }
  else {
    if (uVar3 == 0xeeee) {
      if (param_1[2] == 0) {
        return 0;
      }
      if (*(int *)(param_1[2] + 0x1c) != 4) {
        return 0;
      }
      pcVar1 = FUN_c08adb00;
LAB_c08a677c:
      *param_1 = pcVar1;
      return 0;
    }
    if (uVar3 == 0xf0f0) {
      if (param_1[8] == -1) {
        return 0;
      }
    }
    else {
      if (uVar3 != 0xffff) {
        return 0;
      }
      param_1[8] = 0xffffff;
    }
  }
  pcVar1 = FUN_c08aec08;
LAB_c08a66b4:
  *param_1 = pcVar1;
  return 0;
}



/* c08a6788 FUN_c08a6788 */

undefined4 FUN_c08a6788(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x1c) != 4)) ||
      ((undefined4 *)(param_1 + 0xc) == (undefined4 *)0x0)) ||
     (((*(int *)(param_1 + 0x10) != 3 || (piVar2 = *(int **)(param_1 + 0xc), *piVar2 != 0xf800)) ||
      ((piVar2[1] != 0x7e0 || (uVar1 = 1, piVar2[2] != 0x1f)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a67fc FUN_c08a67fc */

undefined4 FUN_c08a67fc(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (((((param_1 == 0) || (*(int *)(param_1 + 0x1c) != 6)) ||
       ((undefined4 *)(param_1 + 0xc) == (undefined4 *)0x0)) ||
      ((*(int *)(param_1 + 0x10) != 4 || (piVar2 = *(int **)(param_1 + 0xc), *piVar2 != 0xff0000))))
     || ((piVar2[1] != 0xff00 || ((piVar2[2] != 0xff || (uVar1 = 1, piVar2[3] != -0x1000000)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a6880 FUN_c08a6880 */

/* Boundary evidence: original MIPS .pdata c08a6880..c08a6977. Semantic name remains unreviewed. */

undefined4 FUN_c08a6880(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (((((*(int *)(param_1 + 0x28) != 0xcccc) || ((*(uint *)(param_1 + 0x24) & 0x10) == 0)) ||
       (iVar1 = FUN_c08a67fc(*(int *)(param_1 + 8)), iVar1 == 0)) ||
      (((iVar1 = FUN_c08a6788(*(int *)(param_1 + 4)), iVar1 == 0 || (*(int *)(param_1 + 0x10) != 0))
       || ((*(int *)(param_1 + 0xc) != 0 ||
           ((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) == 0)))))))) ||
     ((*(int *)(param_1 + 0x34) == 0 ||
      ((((*(int *)(param_1 + 0x38) == 0 || (piVar3 = *(int **)(param_1 + 0x14), piVar3[2] < *piVar3)
         ) || (piVar3[3] < piVar3[1])) || (uVar2 = 1, *(int *)(param_1 + 0x4c) == 0xff0000)))))) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c08a6978 FUN_c08a6978 */

/* Boundary evidence: original MIPS .pdata c08a6978..c08a71cf. Semantic name remains unreviewed. */

undefined4 FUN_c08a6978(undefined4 param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ushort *puVar14;
  uint uVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int *piVar20;
  int iVar21;
  uint *puVar22;
  int *piVar23;
  ushort *puVar24;
  int iVar25;
  int iVar26;
  uint *puVar27;
  uint uVar28;
  int iVar29;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_64;
  int local_54;
  
  piVar20 = *(int **)(param_2 + 0x14);
  local_54 = piVar20[2] - *piVar20;
  uVar12 = (uint)*(byte *)(param_2 + 0x4e);
  iVar9 = piVar20[3] - piVar20[1];
  cVar1 = *(char *)(param_2 + 0x4f);
  piVar23 = *(int **)(param_2 + 0x18);
  iVar26 = 0;
  iVar25 = 0;
  iVar8 = 0;
  iVar17 = 0;
  iVar21 = 0;
  bVar7 = false;
  bVar2 = false;
  bVar6 = false;
  bVar4 = false;
  local_78 = 0;
  local_7c = 0;
  local_74 = 0;
  local_70 = 0;
  local_64 = 0;
  if (uVar12 != 0) {
    iVar18 = iVar21;
    if ((*(uint *)(param_2 + 0x24) & 8) != 0) {
      iVar18 = piVar23[2] - *piVar23;
      iVar19 = piVar23[3] - piVar23[1];
      bVar2 = iVar18 < local_54;
      if (bVar2) {
        iVar25 = iVar18;
        iVar26 = local_54;
      }
      bVar3 = iVar18 <= local_54;
      if (!bVar3) {
        iVar25 = local_54;
        iVar26 = iVar18;
      }
      if ((bVar2) || (!bVar3)) {
        iVar25 = iVar25 * 2;
        bVar7 = true;
        iVar26 = iVar25 + iVar26 * -2;
        if (bVar3) {
          local_78 = iVar18 * 3 + local_54 * -2;
        }
        else {
          local_78 = local_54 * 2 - iVar18;
        }
      }
      bVar4 = iVar19 < iVar9;
      if (bVar4) {
        local_74 = iVar9;
        local_70 = iVar19;
      }
      bVar5 = iVar19 <= iVar9;
      if (!bVar5) {
        local_74 = iVar19;
        local_70 = iVar9;
      }
      if ((bVar4) || (!bVar5)) {
        local_70 = local_70 * 2;
        local_74 = local_70 + local_74 * -2;
        bVar6 = true;
        if (bVar5) {
          local_7c = iVar19 * 3 + iVar9 * -2;
        }
        else {
          local_7c = iVar9 * 2 - iVar19;
        }
      }
      piVar16 = *(int **)(param_2 + 0x1c);
      if (piVar16 != (int *)0x0) {
        local_64 = *piVar20;
        if (*piVar20 < *piVar16) {
          local_64 = *piVar16;
        }
        iVar8 = piVar20[1];
        if (piVar20[1] < piVar16[1]) {
          iVar8 = piVar16[1];
        }
        iVar9 = piVar20[3];
        if (piVar16[3] < piVar20[3]) {
          iVar9 = piVar16[3];
        }
        local_54 = piVar20[2];
        if (piVar16[2] < piVar20[2]) {
          local_54 = piVar16[2];
        }
        if (local_54 <= local_64) {
          return 0;
        }
        if (iVar9 <= iVar8) {
          return 0;
        }
        local_54 = local_54 - local_64;
        local_64 = local_64 - *piVar20;
        iVar9 = iVar9 - iVar8;
        iVar8 = iVar8 - piVar20[1];
      }
      iVar18 = local_64;
      if (!bVar3) {
        for (; local_78 < 0; local_78 = iVar25 + local_78) {
          iVar17 = iVar17 + 1;
        }
        local_78 = iVar26 + local_78;
      }
      for (; iVar18 != 0; iVar18 = iVar18 + -1) {
        if (bVar3) {
          if (!bVar2) goto LAB_c08a6c64;
          if (-1 < local_78) goto LAB_c08a6c60;
          local_78 = iVar25 + local_78;
        }
        else {
          for (; local_78 < 0; local_78 = iVar25 + local_78) {
            iVar17 = iVar17 + 1;
          }
LAB_c08a6c60:
          local_78 = iVar26 + local_78;
LAB_c08a6c64:
          iVar17 = iVar17 + 1;
        }
      }
      iVar18 = iVar8;
      if (bVar5) {
        iVar19 = iVar8;
        if (bVar4) {
          for (; iVar18 = iVar21, iVar19 != 0; iVar19 = iVar19 + -1) {
            iVar18 = local_70;
            if (-1 < local_7c) {
              iVar21 = iVar21 + 1;
              iVar18 = local_74;
            }
            local_7c = iVar18 + local_7c;
          }
        }
      }
      else {
        local_7c = iVar8 * local_74 + local_7c;
      }
    }
    iVar21 = *(int *)(*(int *)(param_2 + 8) + 8);
    iVar19 = *(int *)(*(int *)(param_2 + 4) + 8);
    iVar8 = piVar20[1] + iVar8;
    puVar27 = (uint *)((piVar23[1] + iVar18) * iVar21 + (*piVar23 + iVar17) * 4 +
                      *(int *)(*(int *)(param_2 + 8) + 4));
    puVar14 = (ushort *)
              ((*piVar20 + local_64) * 2 + iVar8 * iVar19 + *(int *)(*(int *)(param_2 + 4) + 4));
    iVar17 = local_7c;
    while (puVar24 = puVar14, puVar22 = puVar27, iVar9 != 0) {
      iVar9 = iVar9 + -1;
      iVar8 = iVar8 + 1;
      bVar3 = false;
      if (bVar6) {
        if (bVar4) {
          if (iVar17 < 0) {
            iVar17 = local_70 + iVar17;
            bVar3 = true;
            local_7c = iVar17;
          }
          else {
            iVar17 = local_74 + iVar17;
            local_7c = iVar17;
          }
        }
        else {
          for (; iVar17 < 0; iVar17 = local_70 + iVar17) {
            puVar22 = (uint *)((int)puVar22 + iVar21);
          }
          iVar17 = local_74 + iVar17;
          local_7c = iVar17;
        }
      }
      iVar18 = iVar21;
      if (bVar3) {
        iVar18 = 0;
      }
      puVar27 = (uint *)(iVar18 + (int)puVar22);
      puVar14 = (ushort *)((int)puVar24 + iVar19);
      if (0 < local_54) {
        uVar28 = *piVar20 + local_64 + iVar8;
        iVar18 = local_78;
        iVar29 = local_54;
        do {
          uVar10 = *puVar22;
          uVar28 = uVar28 + 1;
          bVar3 = false;
          if (bVar7) {
            if (iVar18 < 0) {
              if (bVar2) {
                bVar3 = true;
                iVar18 = iVar25 + iVar18;
                goto LAB_c08a6e88;
              }
              do {
                iVar18 = iVar25 + iVar18;
                puVar22 = puVar22 + 1;
              } while (iVar18 < 0);
            }
            iVar18 = iVar26 + iVar18;
          }
LAB_c08a6e88:
          uVar15 = 0xff;
          if ((cVar1 != '\x01') || (uVar15 = uVar10 >> 0x18, uVar15 != 0)) {
            uVar13 = (uint)*puVar24;
            uVar11 = 3;
            if (uVar15 == 0xff) {
              if (uVar12 != 0xff) {
                uVar11 = 1;
                goto LAB_c08a6ee4;
              }
              uVar11 = uVar10 >> 3 & 0x1f0000 | uVar10 & 0xfc00;
              uVar15 = uVar10;
            }
            else {
              if (uVar12 == 0xff) {
                uVar11 = 2;
              }
LAB_c08a6ee4:
              uVar15 = (((uVar13 & 0xf800) << 3 | uVar13 & 0x7e0) << 2 | uVar13 & 0x1f) << 3;
              if ((uVar28 & 1) != 0) {
                uVar15 = uVar15 | 0x70307;
              }
              if (uVar11 == 3) {
                uVar13 = (uVar10 >> 8 & 0xff00ff) * uVar12 + 0x800080;
                uVar10 = (uVar10 & 0xff00ff) * uVar12 + 0x800080;
                uVar10 = ((uVar10 >> 8 & 0xff00ff) + uVar10 >> 8 ^
                         (uVar13 >> 8 & 0xffff00ff) + uVar13) & 0xff00ff ^
                         (uVar13 >> 8 & 0xff00ff) + uVar13;
              }
              if ((uVar11 & 2) == 0) {
                if (uVar11 == 1) {
                  uVar11 = uVar15 >> 8 & 0xff00ff;
                  uVar15 = ((uVar10 & 0xff00ff) - (uVar15 & 0xff00ff)) * uVar12 +
                           (uVar15 & 0xff00ff) * 0xff + 0x800080;
                  uVar10 = ((uVar10 >> 8 & 0xff00ff) - uVar11) * uVar12 + uVar11 * 0xff + 0x800080;
                  uVar15 = ((uVar15 >> 8 & 0xff00ff) + uVar15 >> 8 ^
                           (uVar10 >> 8 & 0xffff00ff) + uVar10) & 0xff00ff ^
                           (uVar10 >> 8 & 0xff00ff) + uVar10;
                }
              }
              else {
                iVar17 = 0xff - (uVar10 >> 0x18);
                uVar11 = (uVar15 >> 8 & 0xff00ff) * iVar17 + 0x800080;
                uVar15 = (uVar15 & 0xff00ff) * iVar17 + 0x800080;
                uVar11 = ((uVar11 >> 8 & 0xff00ff) + uVar11 >> 8 & 0xff00ff) +
                         (uVar10 >> 8 & 0xff00ff);
                uVar15 = ((uVar15 >> 8 & 0xff00ff) + uVar15 >> 8 & 0xff00ff) + (uVar10 & 0xff00ff);
                if ((uVar11 & 0xff00) != 0) {
                  uVar11 = 0xff;
                }
                if ((uVar15 & 0xff000000) != 0) {
                  uVar15 = uVar15 & 0xffff | 0xff0000;
                }
                if ((uVar15 & 0xff00) != 0) {
                  uVar15 = uVar15 & 0xff0000 | 0xff;
                }
                uVar15 = uVar11 << 8 | uVar15;
              }
              uVar11 = uVar15 >> 3 & 0x1f0000 | uVar15 & 0xfc00;
            }
            *puVar24 = (ushort)((uVar11 >> 2 | uVar15 & 0xf8) >> 3);
          }
          if (bVar3) {
            iVar17 = 0;
          }
          else {
            iVar17 = 4;
          }
          puVar22 = (uint *)(iVar17 + (int)puVar22);
          iVar29 = iVar29 + -1;
          puVar24 = puVar24 + 1;
          iVar17 = local_7c;
        } while (iVar29 != 0);
      }
    }
  }
  return 0;
}



/* c08a71d0 FUN_c08a71d0 */

/* Boundary evidence: original MIPS .pdata c08a71d0..c08a721f. Semantic name remains unreviewed. */

undefined4 FUN_c08a71d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c08a6880(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if ((*(uint *)(param_1 + 0x24) & 0x1c) == 0x10) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* c08a7220 FUN_c08a7220 */

/* Boundary evidence: original MIPS .pdata c08a7220..c08a764f. Semantic name remains unreviewed. */

undefined4 FUN_c08a7220(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  ushort *puVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  ushort *puVar17;
  uint *puVar18;
  int iVar19;
  
  piVar7 = *(int **)(param_2 + 0x14);
  iVar14 = piVar7[3] - piVar7[1];
  uVar11 = *(uint *)(*(int *)(param_2 + 4) + 8);
  uVar12 = *(uint *)(*(int *)(param_2 + 8) + 8);
  uVar8 = (uint)*(byte *)(param_2 + 0x4e);
  cVar1 = *(char *)(param_2 + 0x4f);
  iVar19 = piVar7[2] - *piVar7;
  if (uVar8 != 0) {
    iVar4 = piVar7[1];
    puVar17 = (ushort *)(iVar4 * uVar11 + *piVar7 * 2 + *(int *)(*(int *)(param_2 + 4) + 4));
    puVar18 = (uint *)((*(int **)(param_2 + 0x18))[1] * uVar12 + *(int *)(*(int *)(param_2 + 8) + 4)
                      + **(int **)(param_2 + 0x18) * 4);
    if (0 < iVar14) {
      do {
        iVar4 = iVar4 + 1;
        if (0 < iVar19) {
          uVar16 = *piVar7 + iVar4;
          puVar5 = puVar18;
          puVar6 = puVar17;
          iVar15 = iVar19;
          do {
            uVar9 = (uint)*puVar6;
            uVar2 = *puVar5;
            uVar16 = uVar16 + 1;
            uVar10 = 0xff;
            if ((cVar1 != '\x01') || (uVar10 = uVar2 >> 0x18, uVar10 != 0)) {
              uVar3 = 3;
              if (uVar10 == 0xff) {
                if (uVar8 != 0xff) {
                  uVar3 = 1;
                  goto LAB_c08a73a4;
                }
                uVar10 = uVar2 >> 3 & 0x1f0000 | uVar2 & 0xfc00;
                uVar9 = uVar2;
              }
              else {
                if (uVar8 == 0xff) {
                  uVar3 = 2;
                }
LAB_c08a73a4:
                uVar9 = (((uVar9 & 0xf800) << 3 | uVar9 & 0x7e0) << 2 | uVar9 & 0x1f) << 3;
                if ((uVar16 & 1) != 0) {
                  uVar9 = uVar9 | 0x70307;
                }
                if (uVar3 == 3) {
                  uVar10 = (uVar2 >> 8 & 0xff00ff) * uVar8 + 0x800080;
                  uVar2 = (uVar2 & 0xff00ff) * uVar8 + 0x800080;
                  uVar2 = ((uVar2 >> 8 & 0xff00ff) + uVar2 >> 8 ^
                          (uVar10 >> 8 & 0xffff00ff) + uVar10) & 0xff00ff ^
                          (uVar10 >> 8 & 0xff00ff) + uVar10;
                }
                if ((uVar3 & 2) == 0) {
                  if (uVar3 == 1) {
                    uVar10 = uVar9 >> 8 & 0xff00ff;
                    uVar9 = ((uVar2 & 0xff00ff) - (uVar9 & 0xff00ff)) * uVar8 +
                            (uVar9 & 0xff00ff) * 0xff + 0x800080;
                    uVar2 = ((uVar2 >> 8 & 0xff00ff) - uVar10) * uVar8 + uVar10 * 0xff + 0x800080;
                    uVar9 = ((uVar9 >> 8 & 0xff00ff) + uVar9 >> 8 ^
                            (uVar2 >> 8 & 0xffff00ff) + uVar2) & 0xff00ff ^
                            (uVar2 >> 8 & 0xff00ff) + uVar2;
                  }
                }
                else {
                  iVar13 = 0xff - (uVar2 >> 0x18);
                  uVar10 = (uVar9 >> 8 & 0xff00ff) * iVar13 + 0x800080;
                  uVar9 = (uVar9 & 0xff00ff) * iVar13 + 0x800080;
                  uVar10 = ((uVar10 >> 8 & 0xff00ff) + uVar10 >> 8 & 0xff00ff) +
                           (uVar2 >> 8 & 0xff00ff);
                  uVar9 = ((uVar9 >> 8 & 0xff00ff) + uVar9 >> 8 & 0xff00ff) + (uVar2 & 0xff00ff);
                  if ((uVar10 & 0xff00) != 0) {
                    uVar10 = 0xff;
                  }
                  if ((uVar9 & 0xff000000) != 0) {
                    uVar9 = uVar9 & 0xffff | 0xff0000;
                  }
                  if ((uVar9 & 0xff00) != 0) {
                    uVar9 = uVar9 & 0xff0000 | 0xff;
                  }
                  uVar9 = uVar10 << 8 | uVar9;
                }
                uVar10 = uVar9 >> 3 & 0x1f0000 | uVar9 & 0xfc00;
              }
              *puVar6 = (ushort)((uVar10 >> 2 | uVar9 & 0xf8) >> 3);
            }
            puVar5 = puVar5 + 1;
            iVar15 = iVar15 + -1;
            puVar6 = puVar6 + 1;
          } while (iVar15 != 0);
        }
        puVar17 = (ushort *)((uVar11 & 0xfffffffe) + (int)puVar17);
        iVar14 = iVar14 + -1;
        puVar18 = (uint *)((uVar12 & 0xfffffffc) + (int)puVar18);
      } while (iVar14 != 0);
    }
  }
  return 0;
}



/* c08a7650 FUN_c08a7650 */

undefined4 FUN_c08a7650(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((((((*(int *)(param_1 + 0x28) != 0xcccc) || ((*(uint *)(param_1 + 0x24) & 0x1c) != 0x10)) ||
        (iVar2 = *(int *)(param_1 + 8), iVar2 == 0)) ||
       ((iVar3 = *(int *)(param_1 + 4), iVar3 == 0 || (*(int *)(param_1 + 0x10) != 0)))) ||
      ((*(int *)(param_1 + 0xc) != 0 ||
       ((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) != 0)))))) ||
     ((*(int *)(iVar3 + 0x1c) != 5 || ((*(int *)(iVar2 + 0x1c) != 5 || (uVar1 = 1, iVar3 == iVar2)))
      ))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a76ec FUN_c08a76ec */

/* Boundary evidence: original MIPS .pdata c08a76ec..c08a7863. Semantic name remains unreviewed. */

undefined4
FUN_c08a76ec(uint *param_1,uint param_2,uint *param_3,uint param_4,int param_5,int param_6,
            int param_7)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (0 < param_6) {
    do {
      if (0 < param_5 * 3) {
        iVar1 = (param_5 * 3 - 1U >> 2) + 1;
        puVar2 = param_3;
        puVar3 = param_1;
        do {
          uVar6 = *puVar3;
          uVar4 = *puVar2;
          puVar3 = puVar3 + 1;
          uVar5 = uVar4;
          if ((param_7 != 0) && (uVar5 = uVar6, param_7 != 0xff)) {
            uVar5 = uVar4 >> 8 & 0xff00ff;
            uVar4 = ((uVar6 & 0xff00ff) - (uVar4 & 0xff00ff)) * param_7 + (uVar4 & 0xff00ff) * 0xff
                    + 0x800080;
            uVar5 = ((uVar6 >> 8 & 0xff00ff) - uVar5) * param_7 + uVar5 * 0xff + 0x800080;
            uVar5 = ((uVar4 >> 8 & 0xff00ff) + uVar4 >> 8 ^ (uVar5 >> 8 & 0xffff00ff) + uVar5) &
                    0xff00ff ^ (uVar5 >> 8 & 0xff00ff) + uVar5;
          }
          *puVar2 = uVar5;
          iVar1 = iVar1 + -1;
          puVar2 = puVar2 + 1;
        } while (iVar1 != 0);
      }
      param_6 = param_6 + -1;
      param_1 = (uint *)((param_2 & 0xfffffffc) + (int)param_1);
      param_3 = (uint *)((param_4 & 0xfffffffc) + (int)param_3);
    } while (param_6 != 0);
  }
  return 0;
}



/* c08a7864 FUN_c08a7864 */

/* Boundary evidence: original MIPS .pdata c08a7864..c08a7adf. Semantic name remains unreviewed. */

undefined4 FUN_c08a7864(undefined4 param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint *puVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  
  piVar8 = *(int **)(param_2 + 0x14);
  uVar9 = (uint)*(byte *)(param_2 + 0x4e);
  uVar13 = *(uint *)(*(int *)(param_2 + 4) + 8);
  uVar14 = *(uint *)(*(int *)(param_2 + 8) + 8);
  iVar2 = piVar8[3] - piVar8[1];
  uVar5 = piVar8[2] - *piVar8;
  if (uVar9 != 0) {
    puVar4 = (uint *)(piVar8[1] * uVar13 + *piVar8 * 3 + *(int *)(*(int *)(param_2 + 4) + 4));
    puVar16 = (uint *)((*(int **)(param_2 + 0x18))[1] * uVar14 + *(int *)(*(int *)(param_2 + 8) + 4)
                      + **(int **)(param_2 + 0x18) * 3);
    if (((((uint)puVar4 & 3) == 0) && (((uint)puVar16 & 3) == 0)) && ((uVar5 & 3) == 0)) {
      uVar3 = FUN_c08a76ec(puVar16,uVar14,puVar4,uVar13,uVar5,iVar2,uVar9);
      return uVar3;
    }
    if (0 < iVar2) {
      do {
        if (0 < (int)uVar5) {
          puVar6 = (undefined1 *)((int)puVar16 + 2);
          puVar7 = puVar4;
          uVar15 = uVar5;
          do {
            uVar1 = CONCAT11((char)*puVar7,*(undefined1 *)((int)puVar7 + 1));
            uVar12 = (uint)CONCAT21(CONCAT11(puVar6[-2],puVar6[-1]),*puVar6);
            if (uVar9 != 0xff) {
              uVar10 = CONCAT21(uVar1,puVar6[(int)puVar4 - (int)puVar16]) & 0xff00ff;
              uVar11 = uVar1 & 0xff00ff;
              uVar12 = ((uVar12 & 0xff00ff) - uVar10) * uVar9 + uVar10 * 0xff + 0x800080;
              uVar10 = ((CONCAT11(puVar6[-2],puVar6[-1]) & 0xff00ff) - uVar11) * uVar9 +
                       uVar11 * 0xff + 0x800080;
              uVar12 = ((uVar12 >> 8 & 0xff00ff) + uVar12 >> 8 ^ (uVar10 >> 8 & 0xffff00ff) + uVar10
                       ) & 0xff00ff ^ (uVar10 >> 8 & 0xff00ff) + uVar10;
            }
            uVar12 = uVar12 & 0xffffff;
            *(char *)puVar7 = (char)(uVar12 >> 0x10);
            *(char *)((int)puVar7 + 1) = (char)(uVar12 >> 8);
            puVar6[(int)puVar4 - (int)puVar16] = (char)uVar12;
            puVar7 = (uint *)((int)puVar7 + 3);
            uVar15 = uVar15 - 1;
            puVar6 = puVar6 + 3;
          } while (uVar15 != 0);
        }
        iVar2 = iVar2 + -1;
        puVar16 = (uint *)((int)puVar16 + uVar14);
        puVar4 = (uint *)((int)puVar4 + uVar13);
      } while (iVar2 != 0);
    }
  }
  return 0;
}



/* c08a7ae0 FUN_c08a7ae0 */

/* Boundary evidence: original MIPS .pdata c08a7ae0..c08a7b9b. Semantic name remains unreviewed. */

undefined4 FUN_c08a7ae0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((((((*(int *)(param_1 + 0x28) != 0xcccc) || ((*(uint *)(param_1 + 0x24) & 0x1c) != 0x10)) ||
        (iVar3 = *(int *)(param_1 + 8), iVar3 == 0)) ||
       ((iVar4 = *(int *)(param_1 + 4), iVar4 == 0 || (*(int *)(param_1 + 0x10) != 0)))) ||
      ((*(int *)(param_1 + 0xc) != 0 ||
       ((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) != 0)))))) ||
     ((iVar1 = FUN_c08a6788(iVar4), iVar1 == 0 ||
      ((iVar1 = FUN_c08a6788(iVar3), iVar1 == 0 || (uVar2 = 1, iVar4 == iVar3)))))) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c08a7b9c FUN_c08a7b9c */

/* Boundary evidence: original MIPS .pdata c08a7b9c..c08a7ddb. Semantic name remains unreviewed. */

undefined4 FUN_c08a7b9c(undefined4 param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  
  piVar8 = *(int **)(param_2 + 0x14);
  iVar4 = piVar8[3] - piVar8[1];
  uVar9 = *(uint *)(*(int *)(param_2 + 4) + 8);
  uVar12 = *(uint *)(*(int *)(param_2 + 8) + 8);
  uVar6 = (uint)*(byte *)(param_2 + 0x4e);
  iVar14 = piVar8[2] - *piVar8;
  if (uVar6 != 0) {
    puVar5 = (ushort *)(piVar8[1] * uVar9 + *piVar8 * 2 + *(int *)(*(int *)(param_2 + 4) + 4));
    iVar2 = (*(int **)(param_2 + 0x18))[1] * uVar12 + *(int *)(*(int *)(param_2 + 8) + 4) +
            **(int **)(param_2 + 0x18) * 2;
    if (0 < iVar4) {
      do {
        if (0 < iVar14) {
          puVar1 = puVar5;
          iVar3 = iVar14;
          do {
            uVar7 = (uint)*puVar1;
            uVar11 = *(ushort *)((iVar2 - (int)puVar5) + (int)puVar1);
            uVar10 = (uint)uVar11;
            if (uVar6 != 0xff) {
              uVar13 = (uVar7 & 0xf800) << 5 | uVar7 & 0x1f;
              uVar7 = (uVar7 & 0x7e0) >> 5;
              uVar13 = (((uVar10 & 0xf800) << 5 | uVar10 & 0x1f) - uVar13) * uVar6 + uVar13 * 0xff +
                       0x800080;
              uVar7 = (((uVar10 & 0x7e0 | 0x1fe00000) >> 5) - uVar7) * uVar6 + uVar7 * 0xff +
                      0x800080;
              uVar7 = ((uVar13 >> 8 & 0xff00ff) + uVar13 >> 8 ^ (uVar7 >> 8 & 0xffff00ff) + uVar7) &
                      0xff00ff ^ (uVar7 >> 8 & 0xff00ff) + uVar7;
              uVar11 = (ushort)((uVar7 >> 2 & 0x7c000 | uVar7 & 0x3f00) >> 3) | (ushort)uVar7 & 0x1f
              ;
            }
            *puVar1 = uVar11;
            iVar3 = iVar3 + -1;
            puVar1 = puVar1 + 1;
          } while (iVar3 != 0);
        }
        iVar4 = iVar4 + -1;
        iVar2 = (uVar12 & 0xfffffffe) + iVar2;
        puVar5 = (ushort *)((uVar9 & 0xfffffffe) + (int)puVar5);
      } while (iVar4 != 0);
    }
  }
  return 0;
}



/* c08a7ddc FUN_c08a7ddc */

undefined4 FUN_c08a7ddc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((((((*(int *)(param_1 + 0x28) != 0xcccc) || (*(int *)(param_1 + 0x20) == -1)) ||
        (iVar2 = *(int *)(param_1 + 8), iVar2 == 0)) ||
       (((*(uint *)(param_1 + 0x24) & 0x1c) != 4 || (*(int *)(param_1 + 0x10) != 0)))) ||
      ((*(int *)(param_1 + 0xc) != 0 ||
       ((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) != 0)))))) ||
     ((*(int *)(*(int *)(param_1 + 4) + 0x1c) != 4 ||
      ((*(int *)(iVar2 + 0x1c) != 4 || (uVar1 = 1, *(int *)(param_1 + 4) == iVar2)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a7f54 FUN_c08a7f54 */

undefined4 FUN_c08a7f54(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((((*(int *)(param_1 + 0x28) != 0xcccc) || (iVar2 = *(int *)(param_1 + 8), iVar2 == 0)) ||
       (*(int *)(param_1 + 0x48) == 5)) ||
      (((((*(uint *)(param_1 + 0x24) & 0x10) != 0 || ((*(uint *)(param_1 + 0x24) & 0xc) == 0)) ||
        ((*(int *)(param_1 + 0x10) != 0 ||
         ((*(int *)(param_1 + 0xc) != 0 || (*(int *)(param_1 + 0x3c) != 0)))))) ||
       (*(int *)(param_1 + 0x40) != 0)))) ||
     (((*(int *)(*(int *)(param_1 + 4) + 0x1c) != 4 || (*(int *)(iVar2 + 0x1c) != 4)) ||
      (uVar1 = 1, *(int *)(param_1 + 4) == iVar2)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a8000 FUN_c08a8000 */

/* Boundary evidence: original MIPS .pdata c08a8000..c08a80a7. Semantic name remains unreviewed. */

undefined4 FUN_c08a8000(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((((*(int *)(param_1 + 0x28) != 0xcccc) || (*(int *)(param_1 + 0x20) != -1)) ||
        (iVar1 = FUN_c08a67fc(*(int *)(param_1 + 8)), iVar1 == 0)) ||
       ((iVar1 = FUN_c08a6788(*(int *)(param_1 + 4)), iVar1 == 0 ||
        ((*(uint *)(param_1 + 0x24) & 0x1c) != 0)))) ||
      ((*(int *)(param_1 + 0x10) != 0 ||
       ((*(int *)(param_1 + 0xc) != 0 || (*(int *)(param_1 + 0x3c) != 0)))))) ||
     (uVar2 = 1, *(int *)(param_1 + 0x40) == 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c08a8188 FUN_c08a8188 */

/* Boundary evidence: original MIPS .pdata c08a8188..c08a8243. Semantic name remains unreviewed. */

undefined4 FUN_c08a8188(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x28) == 0xcccc) && (*(int *)(param_1 + 0x20) == -1)) {
    iVar2 = *(int *)(param_1 + 8);
    iVar1 = FUN_c08a6788(iVar2);
    if ((((iVar1 != 0) &&
         (((iVar1 = FUN_c08a67fc(*(int *)(param_1 + 4)), iVar1 != 0 && (iVar2 != 0)) &&
          ((*(uint *)(param_1 + 0x24) & 0x1c) == 0)))) &&
        (((*(int *)(param_1 + 0x10) == 0 && (*(int *)(param_1 + 0xc) == 0)) &&
         (*(int *)(param_1 + 0x3c) == 0)))) && (*(int *)(param_1 + 0x40) != 0)) {
      return 1;
    }
  }
  return 0;
}



/* c08a8328 FUN_c08a8328 */

undefined4 FUN_c08a8328(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((((((*(int *)(param_1 + 0x28) != 0xcccc) || (*(int *)(param_1 + 0x20) == -1)) ||
        (iVar2 = *(int *)(param_1 + 8), iVar2 == 0)) ||
       (((*(uint *)(param_1 + 0x24) & 0x1c) != 0 || (*(int *)(param_1 + 0x10) != 0)))) ||
      ((*(int *)(param_1 + 0xc) != 0 ||
       ((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) != 0)))))) ||
     ((*(int *)(*(int *)(param_1 + 4) + 0x1c) != 5 ||
      ((*(int *)(iVar2 + 0x1c) != 5 || (uVar1 = 1, *(int *)(param_1 + 4) == iVar2)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a83cc FUN_c08a83cc */

/* Boundary evidence: original MIPS .pdata c08a83cc..c08a84fb. Semantic name remains unreviewed. */

undefined4 FUN_c08a83cc(undefined4 param_1,int param_2)

{
  size_t _Size;
  int *piVar1;
  int iVar2;
  void *_Dst;
  void *_Src;
  size_t sVar3;
  size_t sVar4;
  
  piVar1 = *(int **)(param_2 + 0x14);
  sVar3 = *(size_t *)(*(int *)(param_2 + 4) + 8);
  iVar2 = piVar1[3] - piVar1[1];
  sVar4 = *(size_t *)(*(int *)(param_2 + 8) + 8);
  _Dst = (void *)(piVar1[1] * sVar3 + *piVar1 * 3 + *(int *)(*(int *)(param_2 + 4) + 4));
  _Size = (piVar1[2] - *piVar1) * 3;
  _Src = (void *)((*(int **)(param_2 + 0x18))[1] * sVar4 + *(int *)(*(int *)(param_2 + 8) + 4) +
                 **(int **)(param_2 + 0x18) * 3);
  if ((sVar3 == _Size) && (sVar3 == sVar4)) {
    memcpy(_Dst,_Src,iVar2 * sVar3);
  }
  else if (0 < iVar2) {
    do {
      memcpy(_Dst,_Src,_Size);
      iVar2 = iVar2 + -1;
      _Src = (void *)((int)_Src + sVar4);
      _Dst = (void *)((int)_Dst + sVar3);
    } while (iVar2 != 0);
  }
  return 0;
}



/* c08a84fc FUN_c08a84fc */

undefined4 FUN_c08a84fc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((((((*(int *)(param_1 + 0x28) != 0xcccc) || (*(int *)(param_1 + 0x20) == -1)) ||
        (iVar2 = *(int *)(param_1 + 8), iVar2 == 0)) ||
       (((*(uint *)(param_1 + 0x24) & 0x1c) != 0 || (*(int *)(param_1 + 0x10) != 0)))) ||
      ((*(int *)(param_1 + 0xc) != 0 ||
       ((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) != 0)))))) ||
     ((*(int *)(*(int *)(param_1 + 4) + 0x1c) != 4 ||
      ((*(int *)(iVar2 + 0x1c) != 4 || (uVar1 = 1, *(int *)(param_1 + 4) == iVar2)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a85a0 FUN_c08a85a0 */

/* Boundary evidence: original MIPS .pdata c08a85a0..c08a86bf. Semantic name remains unreviewed. */

undefined4 FUN_c08a85a0(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *_Dst;
  void *_Src;
  uint uVar5;
  uint uVar6;
  
  piVar3 = *(int **)(param_2 + 0x14);
  uVar2 = *(uint *)(*(int *)(param_2 + 4) + 8);
  uVar5 = uVar2 >> 1;
  iVar4 = piVar3[3] - piVar3[1];
  uVar6 = *(uint *)(*(int *)(param_2 + 8) + 8) >> 1;
  uVar1 = piVar3[2] - *piVar3;
  _Dst = (void *)((piVar3[1] * uVar5 + *piVar3) * 2 + *(int *)(*(int *)(param_2 + 4) + 4));
  _Src = (void *)(((*(int **)(param_2 + 0x18))[1] * uVar6 + **(int **)(param_2 + 0x18)) * 2 +
                 *(int *)(*(int *)(param_2 + 8) + 4));
  if ((uVar5 == uVar1) && (uVar5 == uVar6)) {
    memcpy(_Dst,_Src,iVar4 * uVar2);
  }
  else if (0 < iVar4) {
    do {
      memcpy(_Dst,_Src,uVar1 * 2);
      iVar4 = iVar4 + -1;
      _Src = (void *)(uVar6 * 2 + (int)_Src);
      _Dst = (void *)(uVar5 * 2 + (int)_Dst);
    } while (iVar4 != 0);
  }
  return 0;
}



/* c08a86c0 FUN_c08a86c0 */

undefined4 FUN_c08a86c0(int param_1)

{
  undefined4 uVar1;
  
  if ((((((*(int *)(param_1 + 0x28) != 0xaaf0) || (*(int *)(param_1 + 0x20) == -1)) ||
        (*(int *)(param_1 + 8) != 0)) ||
       (((*(uint *)(param_1 + 0x24) & 0x1c) != 0 || (*(int *)(param_1 + 0x10) != 0)))) ||
      ((*(int *)(param_1 + 0xc) == 0 ||
       ((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) != 0)))))) ||
     ((*(int *)(*(int *)(param_1 + 4) + 0x1c) != 6 ||
      (uVar1 = 1, *(int *)(*(int *)(param_1 + 0xc) + 0x1c) != 0)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a8860 FUN_c08a8860 */

undefined4 FUN_c08a8860(int param_1)

{
  undefined4 uVar1;
  
  if ((((*(int *)(param_1 + 0x28) != 0xf0f0) || (*(int *)(param_1 + 0x20) == -1)) ||
      ((*(uint *)(param_1 + 0x24) & 0x1c) != 0)) ||
     (((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) != 0)) ||
      (uVar1 = 1, *(int *)(*(int *)(param_1 + 4) + 0x1c) != 6)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a8980 FUN_c08a8980 */

undefined4 FUN_c08a8980(int param_1)

{
  undefined4 uVar1;
  
  if ((((*(int *)(param_1 + 0x28) != 0xf0f0) || (*(int *)(param_1 + 0x20) == -1)) ||
      ((*(uint *)(param_1 + 0x24) & 0x1c) != 0)) ||
     (((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) != 0)) ||
      (uVar1 = 1, *(int *)(*(int *)(param_1 + 4) + 0x1c) != 5)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08a89ec FUN_c08a89ec */

/* Boundary evidence: original MIPS .pdata c08a89ec..c08a8abf. Semantic name remains unreviewed. */

undefined4 FUN_c08a89ec(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  undefined1 local_8 [8];
  
  piVar1 = *(int **)(param_2 + 0x14);
  iVar9 = *(int *)(*(int *)(param_2 + 4) + 8);
  iVar8 = piVar1[3] - piVar1[1];
  uVar5 = *(undefined4 *)(param_2 + 0x20);
  local_8[0] = (char)uVar5;
  local_8[1] = (char)((uint)uVar5 >> 8);
  puVar6 = (undefined1 *)(piVar1[1] * iVar9 + *piVar1 * 3 + *(int *)(*(int *)(param_2 + 4) + 4));
  local_8[2] = (char)((uint)uVar5 >> 0x10);
  if (0 < iVar8) {
    puVar7 = puVar6 + (piVar1[2] - *piVar1) * 3;
    do {
      iVar3 = 0;
      for (puVar4 = puVar6; puVar4 < puVar7; puVar4 = puVar4 + 1) {
        puVar2 = local_8 + iVar3;
        iVar3 = iVar3 + 1;
        *puVar4 = *puVar2;
        if (iVar3 == 3) {
          iVar3 = 0;
        }
      }
      iVar8 = iVar8 + -1;
      puVar6 = puVar6 + iVar9;
      puVar7 = puVar7 + iVar9;
    } while (iVar8 != 0);
  }
  return 0;
}



/* c08a8ac0 FUN_c08a8ac0 */

/* Boundary evidence: original MIPS .pdata c08a8ac0..c08a914b. Semantic name remains unreviewed. */

undefined4 FUN_c08a8ac0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  short sVar3;
  short sVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  short *psVar16;
  int *piVar17;
  uint uVar18;
  int iVar19;
  short *psVar20;
  int iVar21;
  short *psVar22;
  int iVar23;
  int *piVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int *piVar28;
  int iVar29;
  int iVar30;
  short *psVar31;
  int iVar32;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  piVar24 = *(int **)(param_2 + 0x14);
  uVar18 = *(uint *)(param_2 + 0x24);
  iVar26 = piVar24[2] - *piVar24;
  iVar21 = *(int *)(param_2 + 0x34);
  iVar14 = *(int *)(param_2 + 0x38);
  sVar3 = *(short *)(param_2 + 0x20);
  piVar28 = *(int **)(param_2 + 0x18);
  iVar11 = piVar24[3] - piVar24[1];
  iVar12 = 0;
  iVar32 = 0;
  iVar25 = 0;
  iVar23 = 0;
  iVar13 = 0;
  iVar27 = 0;
  bVar10 = false;
  bVar5 = false;
  bVar9 = false;
  bVar7 = false;
  local_58 = 0;
  local_50 = 0;
  local_5c = 0;
  local_54 = 0;
  iVar29 = iVar14;
  iVar30 = iVar21;
  if ((iVar26 < 0) || (iVar11 < 0)) {
    iVar15 = *piVar24;
    piVar17 = piVar24 + 1;
    piVar1 = piVar24 + 2;
    piVar2 = piVar24 + 3;
    piVar24 = &local_38;
    local_38 = iVar15;
    local_34 = *piVar17;
    local_30 = *piVar1;
    local_2c = *piVar2;
    if (iVar26 < 0) {
      local_38 = *piVar1;
      iVar26 = -iVar26;
      local_30 = iVar15;
      if (iVar21 == 0) {
        iVar30 = 1;
      }
      else {
        iVar30 = 0;
      }
    }
    if (iVar11 < 0) {
      local_34 = *piVar2;
      iVar11 = -iVar11;
      local_2c = *piVar17;
      if (iVar14 == 0) {
        iVar29 = 1;
      }
      else {
        iVar29 = 0;
      }
    }
  }
  iVar15 = iVar27;
  if ((uVar18 & 8) != 0) {
    iVar15 = piVar28[2] - *piVar28;
    bVar5 = iVar15 < iVar26;
    iVar19 = piVar28[3] - piVar28[1];
    if (bVar5) {
      local_58 = iVar26;
      local_50 = iVar15;
    }
    bVar6 = iVar15 <= iVar26;
    if (!bVar6) {
      local_58 = iVar15;
      local_50 = iVar26;
    }
    if ((bVar5) || (!bVar6)) {
      bVar10 = true;
      local_50 = local_50 * 2;
      local_58 = local_50 + local_58 * -2;
      if (bVar6) {
        iVar12 = iVar15 * 3 + iVar26 * -2;
      }
      else {
        iVar12 = iVar26 * 2 - iVar15;
      }
    }
    bVar7 = iVar19 < iVar11;
    if (bVar7) {
      local_5c = iVar11;
      local_54 = iVar19;
    }
    bVar8 = iVar19 <= iVar11;
    if (!bVar8) {
      local_5c = iVar19;
      local_54 = iVar11;
    }
    if ((bVar7) || (!bVar8)) {
      bVar9 = true;
      local_54 = local_54 * 2;
      local_5c = local_54 + local_5c * -2;
      if (bVar8) {
        iVar32 = iVar19 * 3 + iVar11 * -2;
      }
      else {
        iVar32 = iVar11 * 2 - iVar19;
      }
    }
    piVar17 = *(int **)(param_2 + 0x1c);
    if (piVar17 != (int *)0x0) {
      iVar21 = *piVar24;
      if (*piVar24 < *piVar17) {
        iVar21 = *piVar17;
      }
      iVar15 = piVar24[1];
      if (piVar24[1] < piVar17[1]) {
        iVar15 = piVar17[1];
      }
      iVar11 = piVar24[3];
      if (piVar17[3] < piVar24[3]) {
        iVar11 = piVar17[3];
      }
      iVar26 = piVar24[2];
      if (piVar17[2] < piVar24[2]) {
        iVar26 = piVar17[2];
      }
      if (iVar26 <= iVar21) {
        return 0;
      }
      if (iVar11 <= iVar15) {
        return 0;
      }
      if (iVar30 == 0) {
        iVar25 = piVar24[2] - iVar26;
      }
      else {
        iVar25 = iVar21 - *piVar24;
      }
      if (iVar29 == 0) {
        iVar23 = piVar24[3] - iVar11;
      }
      else {
        iVar23 = iVar15 - piVar24[1];
      }
      iVar26 = iVar26 - iVar21;
      iVar11 = iVar11 - iVar15;
      iVar21 = *(int *)(param_2 + 0x34);
    }
    iVar15 = iVar25;
    if (!bVar6) {
      for (; iVar12 < 0; iVar12 = local_50 + iVar12) {
        iVar13 = iVar13 + 1;
      }
      iVar12 = local_58 + iVar12;
    }
    for (; iVar15 != 0; iVar15 = iVar15 + -1) {
      if (bVar6) {
        if (!bVar5) goto LAB_c08a8e68;
        if (-1 < iVar12) goto LAB_c08a8e64;
        iVar12 = local_50 + iVar12;
      }
      else {
        for (; iVar12 < 0; iVar12 = local_50 + iVar12) {
          iVar13 = iVar13 + 1;
        }
LAB_c08a8e64:
        iVar12 = local_58 + iVar12;
LAB_c08a8e68:
        iVar13 = iVar13 + 1;
      }
    }
    iVar15 = iVar23;
    if (bVar8) {
      if ((bVar7) && (iVar19 = iVar23, iVar15 = iVar27, iVar23 != 0)) {
        do {
          iVar21 = local_54;
          if (-1 < iVar32) {
            iVar27 = iVar27 + 1;
            iVar21 = local_5c;
          }
          iVar32 = iVar21 + iVar32;
          iVar19 = iVar19 + -1;
        } while (iVar19 != 0);
        iVar21 = *(int *)(param_2 + 0x34);
        iVar15 = iVar27;
      }
    }
    else {
      iVar32 = iVar23 * local_5c + iVar32;
    }
  }
  if (iVar14 == 0) {
    iVar27 = *(int *)(*(int *)(param_2 + 8) + 8);
    iVar14 = -iVar27;
    iVar27 = ((piVar28[3] - iVar15) + -1) * iVar27 + *(int *)(*(int *)(param_2 + 8) + 4);
  }
  else {
    iVar14 = *(int *)(*(int *)(param_2 + 8) + 8);
    iVar27 = (piVar28[1] + iVar15) * iVar14 + *(int *)(*(int *)(param_2 + 8) + 4);
  }
  iVar15 = 2;
  if (iVar21 == 0) {
    iVar13 = (piVar28[2] - iVar13) + -1;
    iVar21 = -2;
  }
  else {
    iVar13 = iVar13 + *piVar28;
    iVar21 = 2;
  }
  if (iVar29 == 0) {
    iVar19 = *(int *)(*(int *)(param_2 + 4) + 8);
    iVar29 = -iVar19;
    iVar23 = ((piVar24[3] - iVar23) + -1) * iVar19 + *(int *)(*(int *)(param_2 + 4) + 4);
  }
  else {
    iVar29 = *(int *)(*(int *)(param_2 + 4) + 8);
    iVar23 = (piVar24[1] + iVar23) * iVar29 + *(int *)(*(int *)(param_2 + 4) + 4);
  }
  if (iVar30 == 0) {
    iVar25 = (piVar24[2] - iVar25) + -1;
    iVar15 = -2;
  }
  else {
    iVar25 = *piVar24 + iVar25;
  }
  psVar22 = (short *)(iVar13 * 2 + iVar27);
  psVar31 = (short *)(iVar25 * 2 + iVar23);
  do {
    psVar20 = psVar31;
    psVar16 = psVar22;
    if (iVar11 == 0) {
      return 0;
    }
    iVar11 = iVar11 + -1;
    bVar6 = false;
    if (bVar9) {
      if (iVar32 < 0) {
        if (bVar7) {
          iVar32 = local_54 + iVar32;
          bVar6 = true;
          goto LAB_c08a9074;
        }
        do {
          iVar32 = local_54 + iVar32;
          psVar16 = (short *)((int)psVar16 + iVar14);
        } while (iVar32 < 0);
      }
      iVar32 = local_5c + iVar32;
    }
LAB_c08a9074:
    iVar13 = iVar14;
    if (bVar6) {
      iVar13 = 0;
    }
    psVar22 = (short *)(iVar13 + (int)psVar16);
    psVar31 = (short *)((int)psVar20 + iVar29);
    iVar13 = iVar12;
    iVar25 = iVar26;
    if (0 < iVar26) {
      do {
        sVar4 = *psVar16;
        bVar6 = false;
        if (bVar10) {
          if (iVar13 < 0) {
            if (bVar5) {
              iVar13 = local_50 + iVar13;
              bVar6 = true;
              goto LAB_c08a90e0;
            }
            do {
              iVar13 = local_50 + iVar13;
              psVar16 = (short *)((int)psVar16 + iVar21);
            } while (iVar13 < 0);
          }
          iVar13 = local_58 + iVar13;
        }
LAB_c08a90e0:
        if (((uVar18 & 4) == 0) || (sVar4 != sVar3)) {
          *psVar20 = sVar4;
        }
        iVar30 = 0;
        if (!bVar6) {
          iVar30 = iVar21;
        }
        psVar16 = (short *)(iVar30 + (int)psVar16);
        iVar25 = iVar25 + -1;
        psVar20 = (short *)((int)psVar20 + iVar15);
      } while (iVar25 != 0);
    }
  } while( true );
}



/* c08a914c FUN_c08a914c */

/* Boundary evidence: original MIPS .pdata c08a914c..c08a936b. Semantic name remains unreviewed. */

undefined4 FUN_c08a914c(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (((DAT_c08beee4 != 0) && (iVar2 = param_1[1], iVar2 != 0)) && (*(int *)(iVar2 + 0x38) == 0)) {
    if (((param_1[9] & 0x10) != 0) && (param_1[0x13] == 0xff0000)) {
      param_1[9] = param_1[9] & 0xffffffef;
    }
    iVar2 = *(int *)(iVar2 + 0x1c);
    if (iVar2 == 4) {
      iVar2 = FUN_c08a71d0((int)param_1);
      if (iVar2 == 0) {
        iVar2 = FUN_c08a6880((int)param_1);
        if (iVar2 == 0) {
          iVar2 = FUN_c08a8000((int)param_1);
          if (iVar2 == 0) {
            iVar2 = FUN_c08a84fc((int)param_1);
            if (iVar2 == 0) {
              iVar2 = FUN_c08a7ae0((int)param_1);
              if (iVar2 == 0) {
                iVar2 = FUN_c08a7ddc((int)param_1);
                if (iVar2 == 0) {
                  iVar2 = FUN_c08a7f54((int)param_1);
                  if (iVar2 == 0) {
                    return 0;
                  }
                  pcVar1 = FUN_c08a8ac0;
                }
                else {
                  pcVar1 = (code *)&LAB_c08a7e80;
                }
              }
              else {
                pcVar1 = FUN_c08a7b9c;
              }
            }
            else {
              pcVar1 = FUN_c08a85a0;
            }
          }
          else {
            pcVar1 = (code *)&LAB_c08a80a8;
          }
        }
        else {
          pcVar1 = FUN_c08a6978;
        }
      }
      else {
        pcVar1 = FUN_c08a7220;
      }
    }
    else if (iVar2 == 5) {
      iVar2 = FUN_c08a7650((int)param_1);
      if (iVar2 == 0) {
        iVar2 = FUN_c08a8328((int)param_1);
        if (iVar2 == 0) {
          iVar2 = FUN_c08a8980((int)param_1);
          if (iVar2 == 0) {
            return 0;
          }
          pcVar1 = FUN_c08a89ec;
        }
        else {
          pcVar1 = FUN_c08a83cc;
        }
      }
      else {
        pcVar1 = FUN_c08a7864;
      }
    }
    else {
      if (iVar2 != 6) {
        return 0;
      }
      iVar2 = FUN_c08a8188((int)param_1);
      if (iVar2 == 0) {
        iVar2 = FUN_c08a8860((int)param_1);
        if (iVar2 == 0) {
          iVar2 = FUN_c08a86c0((int)param_1);
          if (iVar2 == 0) {
            return 0;
          }
          pcVar1 = (code *)&LAB_c08a875c;
        }
        else {
          pcVar1 = (code *)&LAB_c08a88cc;
        }
      }
      else {
        pcVar1 = (code *)&LAB_c08a8244;
      }
    }
    *param_1 = pcVar1;
    return 0;
  }
  return 1;
}



/* c08a936c FUN_c08a936c */

undefined4 FUN_c08a936c(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 2;
  *param_1 = 0;
  param_1[1] = 0;
  do {
    *puVar1 = 0xffffffff;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 6);
  return 0;
}



/* c08a939c FUN_c08a939c */

/* Boundary evidence: original MIPS .pdata c08a939c..c08a950f. Semantic name remains unreviewed. */

int FUN_c08a939c(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  byte local_2c;
  
  bVar1 = false;
  iVar7 = param_2;
  do {
    puVar4 = (uint *)(iVar7 * 4 + param_1);
    uVar2 = *puVar4;
    iVar3 = (uVar2 & 1) + (uVar2 >> 2 & 3);
    memcpy(&local_30,puVar4 + 1,iVar3 * 4);
    if ((((uVar2 & 0xff800000) != 0x8800000) || (local_30 != 0x2000000)) || (iVar3 != 2)) break;
    iVar3 = (iVar7 + 3) * 0x10000;
    iVar7 = iVar3;
    while (iVar5 = iVar7 >> 0x10, *(uint *)(iVar5 * 4 + param_1) != (uVar2 & 0xfff0 | 0x4000000)) {
      iVar7 = (iVar5 + 1) * 0x10000;
    }
    iVar6 = (uint)local_2c * 4;
    *(short *)(&DAT_c08beeec + iVar6) = (short)((uint)iVar3 >> 0x10);
    (&DAT_c08beeee)[iVar6] = (char)((uint)iVar7 >> 0x10) - (char)((uint)iVar3 >> 0x10);
    (&DAT_c08beeef)[iVar6] = local_2c;
    iVar7 = (iVar5 + 1) * 0x10000 >> 0x10;
    if (local_2c == 0xff) {
      bVar1 = true;
    }
  } while (!bVar1);
  return (iVar7 - param_2) * 0x10000 >> 0x10;
}



/* c08a9510 FUN_c08a9510 */

/* Boundary evidence: original MIPS .pdata c08a9510..c08a9793. Semantic name remains unreviewed. */

int FUN_c08a9510(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int local_38;
  uint local_34;
  
  bVar1 = false;
  bVar2 = false;
  puVar6 = (uint *)(param_3 * 4 + param_1);
  iVar9 = param_3;
  do {
    uVar3 = *puVar6;
    iVar5 = (uVar3 & 1) + (uVar3 >> 2 & 3);
    memcpy(&local_38,puVar6 + 1,iVar5 * 4);
    if ((((uVar3 & 0xff800000) != 0x8800000) || (local_38 != 0x4000000)) || (iVar5 != 2)) break;
    iVar9 = (iVar9 + 3) * 0x10000 >> 0x10;
    puVar6 = (uint *)(iVar9 * 4 + param_1);
    uVar10 = local_34 & 0xf;
    local_38 = 0x4000000;
    uVar4 = *puVar6;
    while (uVar4 != (uVar3 & 0xfff0 | 0x4000000)) {
      uVar4 = *puVar6;
      iVar5 = (uVar4 & 1) + (uVar4 >> 2 & 3);
      memcpy(&local_38,puVar6 + 1,iVar5 * 4);
      bVar1 = bVar2;
      if ((((uVar4 & 0xff800000) != 0x8800000) || (local_38 != 0x4000001)) || (iVar5 != 2)) break;
      iVar8 = (iVar9 + 3) * 0x10000;
      uVar11 = (local_34 & 0xf) << 4 | uVar10;
      iVar5 = iVar8;
      while (iVar9 = iVar5 >> 0x10, *(uint *)(iVar9 * 4 + param_1) != (uVar4 & 0xfff0 | 0x4000000))
      {
        iVar5 = (iVar9 + 1) * 0x10000;
      }
      iVar7 = uVar11 * 4;
      iVar9 = (iVar9 + 1) * 0x10000 >> 0x10;
      *(short *)(&DAT_c08bf2ec + iVar7) = (short)((uint)iVar8 >> 0x10);
      (&DAT_c08bf2ef)[iVar7] = (char)uVar11;
      puVar6 = (uint *)(iVar9 * 4 + param_1);
      (&DAT_c08bf2ee)[iVar7] = (char)((uint)iVar5 >> 0x10) - (char)((uint)iVar8 >> 0x10);
      uVar4 = *puVar6;
    }
    iVar9 = (iVar9 + 1) * 0x10000 >> 0x10;
    puVar6 = (uint *)(iVar9 * 4 + param_1);
    if (*puVar6 == param_2) {
      bVar1 = true;
      bVar2 = true;
    }
  } while (!bVar1);
  return (iVar9 - param_3) * 0x10000 >> 0x10;
}



/* c08a9794 FUN_c08a9794 */

/* Boundary evidence: original MIPS .pdata c08a9794..c08a9acb. Semantic name remains unreviewed. */

undefined4 FUN_c08a9794(int param_1,int param_2,uint *param_3)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  short *psVar14;
  int iVar15;
  
  uVar7 = FUN_c08aa214(param_3);
  uVar6 = *param_3;
  bVar2 = *(byte *)((int)param_3 + 6);
  bVar3 = *(byte *)((int)param_3 + 7);
  iVar9 = 0;
  iVar12 = 0;
  if (0 < DAT_c08beee8) {
    psVar14 = &DAT_c08bf6ec;
    iVar15 = DAT_c08beee8;
    do {
      uVar11 = (uint)bVar2;
      if (iVar9 <= *psVar14) {
        iVar10 = (int)psVar14[1];
        sVar8 = (short)iVar9;
        if (iVar10 == 0x19) {
          if ((uVar7 & 0x1000000) != 0) {
            if (uVar11 == bVar3) {
              pbVar13 = &DAT_c08beeee + uVar11 * 4;
              sVar5 = *(short *)(&DAT_c08beeec + uVar11 * 4);
              bVar4 = *pbVar13;
LAB_c08a9944:
              memcpy((void *)(iVar12 * 4 + param_2),(void *)(sVar5 * 4 + param_1),(uint)bVar4 << 2);
              iVar12 = (uint)*pbVar13 + iVar12;
            }
            else {
              memcpy((void *)(iVar12 * 4 + param_2),
                     (void *)((*(short *)(&DAT_c08beeec + uVar11 * 4) + -3) * 4 + param_1),
                     ((byte)(&DAT_c08beeee)[uVar11 * 4] + 4) * 4);
              iVar9 = (uint)bVar3 * 4;
              iVar12 = (int)(((uint)(byte)(&DAT_c08beeee)[uVar11 * 4] + iVar12 + 4) * 0x10000) >>
                       0x10;
              memcpy((void *)(iVar12 * 4 + param_2),
                     (void *)((*(short *)(&DAT_c08beeec + iVar9) + -3) * 4 + param_1),
                     ((byte)(&DAT_c08beeee)[iVar9] + 4) * 4);
              iVar12 = (uint)(byte)(&DAT_c08beeee)[iVar9] + iVar12 + 4;
            }
            iVar12 = iVar12 * 0x10000 >> 0x10;
          }
LAB_c08a995c:
          sVar8 = psVar14[3] + sVar8 + 2;
        }
        else {
          if (iVar10 == 0x13) {
            if ((uVar7 & 0x40000) != 0) {
              iVar9 = (uint)(byte)uVar6 * 4;
              pbVar13 = &DAT_c08bf2ee + iVar9;
              sVar5 = *(short *)(&DAT_c08bf2ec + iVar9);
              bVar4 = *pbVar13;
              goto LAB_c08a9944;
            }
            goto LAB_c08a995c;
          }
          if (iVar10 < 1) {
            if (iVar10 < 0) {
              bVar1 = (1 << (-iVar10 - 1U & 0x1f) & uVar7) == 0;
              sVar8 = sVar8 + 1;
              goto LAB_c08a99f8;
            }
            memcpy((void *)(iVar12 * 4 + param_2),(void *)(iVar9 * 4 + param_1),(int)psVar14[2] << 2
                  );
            iVar12 = (psVar14[2] + iVar12) * 0x10000 >> 0x10;
            sVar8 = psVar14[3] + sVar8;
          }
          else {
            bVar1 = (1 << (iVar10 - 1U & 0x1f) & uVar7) != 0;
            sVar8 = sVar8 + 2;
LAB_c08a99f8:
            iVar9 = (int)sVar8;
            if (bVar1) goto LAB_c08a9a7c;
            sVar8 = psVar14[3] + sVar8;
          }
        }
        iVar9 = (int)sVar8;
      }
LAB_c08a9a7c:
      psVar14 = psVar14 + 4;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  return 1;
}



/* c08a9acc FUN_c08a9acc */

/* Boundary evidence: original MIPS .pdata c08a9acc..c08a9f2f. Semantic name remains unreviewed. */

int FUN_c08a9acc(int param_1,uint param_2,uint param_3,int param_4,short param_5)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  undefined2 uVar10;
  short sVar11;
  int iVar12;
  undefined2 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  short local_5e;
  int local_58;
  uint local_38 [4];
  
  iVar12 = (int)param_5;
  iVar17 = param_4 * 8;
  sVar1 = (&DAT_c08bf6ee)[param_4 * 4];
  bVar2 = false;
  iVar14 = 0;
  local_58 = 0;
  local_5e = param_5;
  bVar3 = false;
  iVar15 = DAT_c08beee8;
  do {
    puVar8 = (uint *)(iVar12 * 4 + param_1);
    uVar6 = *puVar8;
    iVar7 = (uVar6 & 1) + (uVar6 >> 2 & 3);
    memcpy(local_38,puVar8 + 1,iVar7 * 4);
    iVar7 = iVar7 + 1;
    uVar10 = (undefined2)iVar12;
    uVar13 = (undefined2)iVar14;
    if ((uVar6 & 0xff800000) == 0x2000000) {
      uVar4 = uVar6 >> 4 & 0xfff;
      uVar9 = (uVar4 | 0x300000) << 4;
      uVar4 = (uVar4 | 0x400000) << 4;
      if (0 < iVar14) {
        *(undefined2 *)((int)&DAT_c08bf6f0 + iVar17) = uVar13;
        *(undefined2 *)((int)&DAT_c08bf6f2 + iVar17) = uVar13;
        iVar14 = 0;
      }
      uVar5 = local_38[0] & 0x1f;
      iVar17 = iVar15 * 8;
      DAT_c08beee8 = iVar15 + 1;
      (&DAT_c08bf6ee)[iVar15 * 4] = (short)uVar5 + 1;
      (&DAT_c08bf6f2)[iVar15 * 4] = 0;
      (&DAT_c08bf6ec)[iVar15 * 4] = uVar10;
      iVar12 = (iVar12 + iVar7) * 0x10000;
      (&DAT_c08bf6f0)[iVar15 * 4] = 0;
      iVar7 = iVar12 >> 0x10;
      sVar11 = (short)((uint)iVar12 >> 0x10);
      bVar2 = bVar3;
      if (uVar5 == 0x12) {
        iVar12 = FUN_c08a9510(param_1,uVar4,iVar7);
        iVar12 = iVar12 + iVar7;
        iVar7 = FUN_c08a9acc(param_1,uVar9,uVar4,iVar15,(short)iVar12);
      }
      else {
        if (uVar5 != 0x18) {
          iVar12 = FUN_c08a9acc(param_1,uVar9,uVar4,iVar15,sVar11);
          iVar12 = iVar12 + iVar7;
          iVar16 = DAT_c08beee8;
          goto LAB_c08a9e84;
        }
        iVar12 = FUN_c08a939c(param_1,iVar7);
        iVar12 = iVar12 + iVar7;
        iVar7 = FUN_c08a9acc(param_1,uVar9,uVar4,iVar15,(short)iVar12);
      }
      iVar16 = DAT_c08beee8;
      iVar12 = (iVar7 + iVar12) * 0x10000;
      (&DAT_c08bf6f2)[iVar15 * 4] = (short)((uint)iVar12 >> 0x10) - sVar11;
LAB_c08a9e88:
      iVar7 = (int)local_5e;
      iVar12 = iVar12 >> 0x10;
    }
    else {
      if (uVar6 != param_2) {
        if (uVar6 == param_3) {
          if (0 < iVar14) {
            *(undefined2 *)((int)&DAT_c08bf6f0 + iVar17) = uVar13;
            *(undefined2 *)((int)&DAT_c08bf6f2 + iVar17) = uVar13;
          }
          iVar17 = iVar15 * 8;
          (&DAT_c08bf6ec)[iVar15 * 4] = uVar10;
          iVar16 = iVar15 + 1;
          DAT_c08beee8 = iVar16;
          (&DAT_c08bf6ee)[iVar15 * 4] = 0;
          (&DAT_c08bf6f0)[iVar15 * 4] = 0;
          (&DAT_c08bf6f2)[iVar15 * 4] = (short)iVar7;
        }
        else {
          iVar16 = iVar15;
          if (iVar14 == 0) {
            iVar17 = iVar15 * 8;
            (&DAT_c08bf6ec)[iVar15 * 4] = uVar10;
            iVar16 = iVar15 + 1;
            DAT_c08beee8 = iVar16;
            (&DAT_c08bf6ee)[iVar15 * 4] = 0;
            (&DAT_c08bf6f0)[iVar15 * 4] = 0;
            (&DAT_c08bf6f2)[iVar15 * 4] = 0;
          }
          iVar14 = (iVar14 + iVar7) * 0x10000 >> 0x10;
        }
        iVar12 = iVar12 + iVar7;
LAB_c08a9e84:
        iVar12 = iVar12 * 0x10000;
        goto LAB_c08a9e88;
      }
      bVar2 = true;
      bVar3 = true;
      if (0 < iVar14) {
        *(undefined2 *)((int)&DAT_c08bf6f0 + iVar17) = uVar13;
        *(undefined2 *)((int)&DAT_c08bf6f2 + iVar17) = uVar13;
        iVar14 = 0;
      }
      (&DAT_c08bf6ec)[iVar15 * 4] = uVar10;
      (&DAT_c08bf6ee)[iVar15 * 4] = -sVar1;
      iVar12 = (iVar12 + iVar7) * 0x10000;
      iVar7 = iVar12 >> 0x10;
      iVar16 = iVar15 + 1;
      DAT_c08beee8 = iVar16;
      (&DAT_c08bf6f0)[iVar15 * 4] = 0;
      (&DAT_c08bf6f2)[iVar15 * 4] = 0;
      local_5e = (short)((uint)iVar12 >> 0x10);
      iVar12 = iVar7;
      local_58 = iVar15;
    }
    iVar15 = iVar16;
    if (uVar6 == param_3) {
      if (bVar2) {
        (&DAT_c08bf6f2)[param_4 * 4] = ((short)iVar7 - param_5) + -1;
        (&DAT_c08bf6f2)[local_58 * 4] = (short)iVar12 - (short)iVar7;
      }
      else {
        (&DAT_c08bf6f2)[param_4 * 4] = (short)iVar12 - param_5;
      }
      return (iVar12 - param_5) * 0x10000 >> 0x10;
    }
  } while( true );
}



/* c08a9f30 FUN_c08a9f30 */

/* Boundary evidence: original MIPS .pdata c08a9f30..c08aa213. Semantic name remains unreviewed. */

undefined4 FUN_c08a9f30(int param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint local_38 [4];
  
  DAT_c08beee8 = 0;
  iVar10 = 0;
  iVar11 = 0;
  iVar9 = 0;
  iVar7 = 0;
  do {
    puVar6 = (uint *)(iVar11 * 4 + param_1);
    uVar3 = *puVar6;
    iVar4 = (uVar3 & 1) + (uVar3 >> 2 & 3);
    memcpy(local_38,puVar6 + 1,iVar4 * 4);
    iVar4 = iVar4 + 1;
    if ((uVar3 & 0xff800000) == 0x2000000) {
      uVar2 = uVar3 >> 4 & 0xfff;
      uVar12 = (uVar2 | 0x300000) << 4;
      uVar2 = (uVar2 | 0x400000) << 4;
      if (0 < iVar9) {
        (&DAT_c08bf6f0)[iVar10 * 4] = (short)iVar9;
        (&DAT_c08bf6f2)[iVar10 * 4] = (short)iVar9;
        iVar9 = 0;
      }
      DAT_c08beee8 = iVar7 + 1;
      uVar5 = local_38[0] & 0x1f;
      iVar10 = (iVar11 + iVar4) * 0x10000;
      (&DAT_c08bf6ec)[iVar7 * 4] = (short)iVar11;
      (&DAT_c08bf6ee)[iVar7 * 4] = (short)uVar5 + 1;
      iVar4 = iVar10 >> 0x10;
      sVar1 = (short)((uint)iVar10 >> 0x10);
      if (uVar5 == 0x12) {
        iVar11 = FUN_c08a9510(param_1,uVar2,iVar4);
        iVar11 = iVar11 + iVar4;
        iVar10 = FUN_c08a9acc(param_1,uVar12,uVar2,iVar7,(short)iVar11);
      }
      else {
        if (uVar5 != 0x18) {
          iVar11 = FUN_c08a9acc(param_1,uVar12,uVar2,iVar7,sVar1);
          iVar11 = iVar11 + iVar4;
          iVar8 = DAT_c08beee8;
          iVar10 = iVar7;
          goto LAB_c08aa1a0;
        }
        iVar11 = FUN_c08a939c(param_1,iVar4);
        iVar11 = iVar11 + iVar4;
        iVar10 = FUN_c08a9acc(param_1,uVar12,uVar2,iVar7,(short)iVar11);
      }
      iVar8 = DAT_c08beee8;
      iVar11 = (iVar10 + iVar11) * 0x10000;
      (&DAT_c08bf6f2)[iVar7 * 4] = (short)((uint)iVar11 >> 0x10) - sVar1;
      iVar10 = iVar7;
    }
    else {
      iVar8 = iVar7;
      if (iVar9 == 0) {
        (&DAT_c08bf6ec)[iVar7 * 4] = (short)iVar11;
        iVar8 = iVar7 + 1;
        DAT_c08beee8 = iVar8;
        (&DAT_c08bf6ee)[iVar7 * 4] = 0;
        (&DAT_c08bf6f0)[iVar7 * 4] = 0;
        (&DAT_c08bf6f2)[iVar7 * 4] = 0;
        iVar10 = iVar7;
      }
      iVar11 = iVar11 + iVar4;
      iVar9 = (iVar9 + iVar4) * 0x10000 >> 0x10;
LAB_c08aa1a0:
      iVar11 = iVar11 * 0x10000;
    }
    iVar11 = iVar11 >> 0x10;
    iVar7 = iVar8;
    if (uVar3 == 0x1f000000) {
      if (0 < iVar9) {
        (&DAT_c08bf6f0)[iVar10 * 4] = (short)iVar9;
        (&DAT_c08bf6f2)[iVar10 * 4] = (short)iVar9;
      }
      return 1;
    }
  } while( true );
}



/* c08aa214 FUN_c08aa214 */

uint FUN_c08aa214(uint *param_1)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *param_1 >> 0xd;
  uVar4 = uVar5 & 0x7fffe;
  if ((((*(ushort *)((int)param_1 + 6) >> 4 ^ *(ushort *)((int)param_1 + 6)) & 0xf0f) != 0) &&
     ((uVar5 & 1) == 0)) {
    uVar4 = uVar4 | 1;
  }
  if ((uVar4 & 0x78) != 0) {
    uVar4 = uVar4 | 0x80000;
  }
  sVar1 = *(short *)((int)param_1 + 6);
  if ((((sVar1 == -0x3334) || (sVar1 == -0xf10)) || (sVar1 == -1)) || (bVar3 = true, sVar1 == 0)) {
    bVar3 = false;
  }
  if (((*(ushort *)((int)param_1 + 6) >> 1 ^ *(ushort *)((int)param_1 + 6)) & 0x5555) != 0) {
    uVar4 = uVar4 | 0x100000;
  }
  if (((*(ushort *)((int)param_1 + 6) >> 2 ^ *(ushort *)((int)param_1 + 6)) & 0x3333) != 0) {
    uVar4 = uVar4 | 0x200000;
  }
  if ((uVar5 & 1) == 1) {
    uVar4 = uVar4 | 0x400000;
    bVar3 = true;
  }
  if (*(char *)((int)param_1 + 6) != *(char *)((int)param_1 + 7)) {
    uVar4 = uVar4 | 0x800000;
  }
  if (bVar3) {
    uVar4 = uVar4 | 0x1000000;
  }
  uVar2 = (ushort)param_1[1];
  if ((uVar2 & 2) != 0) {
    uVar4 = uVar4 | 0x8000000;
    goto LAB_c08aa3c0;
  }
  if ((uVar2 & 8) == 0) {
    if ((uVar2 & 1) != 0) {
      uVar4 = uVar4 | 0x4000000;
      goto LAB_c08aa3c0;
    }
    if ((uVar2 & 4) == 0) goto LAB_c08aa3c0;
    uVar5 = 0x10000000;
  }
  else {
    uVar5 = 0x20000000;
  }
  uVar4 = uVar4 | uVar5;
LAB_c08aa3c0:
  if ((uVar2 >> 4 & 1) != 0) {
    uVar4 = uVar4 | 0x2000000;
  }
  return uVar4;
}



/* c08aa3d8 FUN_c08aa3d8 */

/* WARNING: Removing unreachable block (ram,0xc08aae5c) */
/* WARNING: Removing unreachable block (ram,0xc08aac54) */
/* WARNING: Removing unreachable block (ram,0xc08ab164) */
/* Boundary evidence: original MIPS .pdata c08aa3d8..c08ab3d3. Semantic name remains unreviewed. */

void FUN_c08aa3d8(int param_1,uint *param_2)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *_Dst;
  int iVar15;
  uint *puVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint local_34;
  uint local_30;
  
  iVar3 = *(int *)(param_1 + 4);
  if (((undefined4 *)(iVar3 + 0xc) != (undefined4 *)0x0) &&
     (pvVar1 = *(void **)(iVar3 + 0xc), pvVar1 != (void *)0x0)) {
    puVar16 = param_2 + 0x60;
    memcpy(puVar16,pvVar1,*(int *)(iVar3 + 0x10) << 2);
    if (*(int *)(iVar3 + 0x10) == 3) {
      param_2[99] = 0;
      param_2[0x67] = 0;
      param_2[0x6b] = 0;
    }
    if (((*(int *)(param_1 + 0x40) != 0) && ((*(uint *)(param_1 + 0x50) & 0xf) == 9)) &&
       (iVar9 = 0, 0 < *(int *)(iVar3 + 0x10))) {
      do {
        uVar8 = 0;
        for (uVar7 = *puVar16; (uVar7 & 0x80000000) == 0; uVar7 = uVar7 << 1) {
          uVar8 = uVar8 + 1;
        }
        uVar4 = 0;
        for (; uVar7 != 0; uVar7 = uVar7 << 1) {
          uVar4 = uVar4 + 1;
        }
        puVar16[4] = uVar8;
        puVar16[8] = uVar4;
        iVar9 = iVar9 + 1;
        puVar16 = puVar16 + 1;
      } while (iVar9 < *(int *)(iVar3 + 0x10));
    }
  }
  puVar16 = (uint *)(param_1 + 0x50);
  if (((*puVar16 & 0xf) == 8) && (DAT_c08bc8a0 != 0)) {
    param_2[0x60] = **(uint **)(DAT_c08bc8a0 + 0x10);
  }
  iVar3 = *(int *)(param_1 + 8);
  if (iVar3 != 0) {
    if (*(void **)(param_1 + 0x3c) == (void *)0x0) {
      if (((undefined4 *)(iVar3 + 0xc) != (undefined4 *)0x0) &&
         (pvVar1 = *(void **)(iVar3 + 0xc), pvVar1 != (void *)0x0)) {
        _Dst = param_2 + 0x160;
        memcpy(_Dst,pvVar1,*(int *)(iVar3 + 0x10) << 2);
        if (*(int *)(iVar3 + 0x10) == 3) {
          param_2[0x163] = 0;
          param_2[0x167] = 0;
          param_2[0x16b] = 0;
        }
        if (((*(int *)(param_1 + 0x40) != 0) && ((*puVar16 & 0xf0) == 0x90)) &&
           (iVar9 = 0, 0 < *(int *)(iVar3 + 0x10))) {
          do {
            uVar8 = 0;
            for (uVar7 = *_Dst; (uVar7 & 0x80000000) == 0; uVar7 = uVar7 << 1) {
              uVar8 = uVar8 + 1;
            }
            uVar4 = 0;
            for (; uVar7 != 0; uVar7 = uVar7 << 1) {
              uVar4 = uVar4 + 1;
            }
            _Dst[4] = uVar8;
            _Dst[8] = uVar4;
            iVar9 = iVar9 + 1;
            _Dst = _Dst + 1;
          } while (iVar9 < *(int *)(iVar3 + 0x10));
        }
      }
    }
    else {
      memcpy(param_2 + 0x160,*(void **)(param_1 + 0x3c),
             (1 << (*(uint *)(&LAB_c0891154 + *(int *)(iVar3 + 0x1c) * 4) & 0x1f)) << 2);
    }
  }
  uVar7 = FUN_c08aa214(puVar16);
  param_2[0x260] = uVar7;
  param_2[0x5f] = 0;
  piVar5 = *(int **)(param_1 + 0x14);
  iVar15 = 0;
  iVar13 = piVar5[2];
  local_30 = *(uint *)(param_1 + 0x34);
  local_34 = *(uint *)(param_1 + 0x38);
  iVar20 = *piVar5;
  iVar18 = piVar5[1];
  iVar9 = piVar5[3];
  iVar19 = 0;
  iVar3 = 0;
  iVar17 = 0;
  if (*(int *)(param_1 + 4) != -0xc) {
    param_2[0x22] = *(uint *)(*(int *)(param_1 + 4) + 0x10);
  }
  param_2[1] = *(uint *)(param_1 + 0x28) >> 8;
  *param_2 = *(uint *)(param_1 + 0x28) & 0xff;
  uVar8 = uVar7 & 0x8000;
  param_2[0x21] = *(uint *)(param_1 + 0x20);
  uVar4 = (*(int **)(param_1 + 0x14))[2] - **(int **)(param_1 + 0x14);
  param_2[0x2b] = uVar4;
  param_2[0x2c] = *(int *)(*(int *)(param_1 + 0x14) + 0xc) - *(int *)(*(int *)(param_1 + 0x14) + 4);
  iVar14 = iVar13;
  if (uVar8 != 0) {
    param_2[0x2b] = -uVar4;
    local_30 = (uint)(local_30 == 0);
    iVar14 = iVar20;
    iVar20 = iVar13;
  }
  uVar4 = uVar7 & 0x10000;
  iVar13 = iVar18;
  if (uVar4 != 0) {
    param_2[0x2c] = -param_2[0x2c];
    local_34 = (uint)(local_34 == 0);
    iVar13 = iVar9;
    iVar9 = iVar18;
  }
  iVar18 = iVar17;
  if ((uVar7 & 0x80000) == 0) goto LAB_c08aaa0c;
  piVar5 = *(int **)(param_1 + 0x18);
  iVar18 = piVar5[2] - *piVar5;
  iVar11 = piVar5[3] - piVar5[1];
  if ((uVar7 & 8) != 0) {
    param_2[2] = iVar18 * 2;
    param_2[3] = iVar18 * 2 + param_2[0x2b] * -2;
    param_2[0x20] = iVar18 * 3 + param_2[0x2b] * -2;
  }
  uVar2 = uVar7 & 0x20;
  if (uVar2 != 0) {
    uVar6 = param_2[0x2b] * 2;
    param_2[2] = uVar6;
    param_2[3] = uVar6 + iVar18 * -2;
    param_2[0x20] = param_2[0x2b] * 2 - iVar18;
  }
  if ((uVar7 & 0x10) != 0) {
    param_2[4] = iVar11 * 2;
    param_2[5] = iVar11 * 2 + param_2[0x2c] * -2;
    param_2[0x2a] = iVar11 * 3 + param_2[0x2c] * -2;
  }
  if ((uVar7 & 0x40) != 0) {
    uVar6 = param_2[0x2c] * 2;
    param_2[4] = uVar6;
    param_2[5] = uVar6 + iVar11 * -2;
    param_2[0x2a] = param_2[0x2c] * 2 - iVar11;
  }
  piVar5 = *(int **)(param_1 + 0x1c);
  if (piVar5 != (int *)0x0) {
    iVar18 = iVar20;
    if (iVar20 < *piVar5) {
      iVar18 = *piVar5;
    }
    iVar11 = iVar13;
    if (iVar13 < piVar5[1]) {
      iVar11 = piVar5[1];
    }
    iVar21 = iVar14;
    if (piVar5[2] < iVar14) {
      iVar21 = piVar5[2];
    }
    iVar10 = iVar9;
    if (piVar5[3] < iVar9) {
      iVar10 = piVar5[3];
    }
    if (iVar21 < iVar18) {
      iVar21 = iVar18;
    }
    if (iVar10 < iVar11) {
      iVar10 = iVar11;
    }
    if ((uVar7 & 2) == 0) {
      iVar15 = iVar18 - iVar20;
      if (uVar8 == 0) goto LAB_c08aa8dc;
    }
    else if (uVar8 == 0) {
      iVar15 = iVar18 - iVar20;
    }
    else {
LAB_c08aa8dc:
      iVar15 = iVar14 - iVar21;
    }
    if ((uVar7 & 4) == 0) {
      iVar19 = iVar11 - iVar13;
      if (uVar4 == 0) goto LAB_c08aa904;
    }
    else if (uVar4 == 0) {
      iVar19 = iVar11 - iVar13;
    }
    else {
LAB_c08aa904:
      iVar19 = iVar9 - iVar10;
    }
    param_2[0x2b] = iVar21 - iVar18;
    param_2[0x2c] = iVar10 - iVar11;
  }
  iVar18 = iVar15;
  if (uVar2 != 0) {
    if ((int)param_2[0x20] < 0) {
      do {
        uVar8 = param_2[0x20];
        param_2[0x20] = param_2[2] + uVar8;
        iVar3 = iVar3 + 1;
      } while ((int)(param_2[2] + uVar8) < 0);
    }
    param_2[0x20] = param_2[3] + param_2[0x20];
  }
  for (; iVar18 != 0; iVar18 = iVar18 + -1) {
    if (uVar2 == 0) {
      if ((uVar7 & 8) == 0) goto LAB_c08aa9d4;
      uVar8 = param_2[0x20];
      if (-1 < (int)uVar8) {
        param_2[0x20] = param_2[3] + uVar8;
        goto LAB_c08aa9d4;
      }
      param_2[0x20] = param_2[2] + uVar8;
    }
    else {
      if ((int)param_2[0x20] < 0) {
        do {
          uVar8 = param_2[0x20];
          param_2[0x20] = param_2[2] + uVar8;
          iVar3 = iVar3 + 1;
        } while ((int)(param_2[2] + uVar8) < 0);
      }
      param_2[0x20] = param_2[3] + param_2[0x20];
LAB_c08aa9d4:
      iVar3 = iVar3 + 1;
    }
  }
  iVar18 = iVar19;
  if ((uVar7 & 0x40) == 0) {
    if (((uVar7 & 0x10) != 0) && (iVar18 = iVar17, iVar19 != 0)) {
      uVar8 = param_2[0x2a];
      iVar18 = iVar19;
      do {
        if ((int)uVar8 < 0) {
          uVar4 = param_2[4];
        }
        else {
          uVar4 = param_2[5];
          iVar17 = iVar17 + 1;
        }
        uVar8 = uVar4 + uVar8;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
      param_2[0x2a] = uVar8;
      iVar18 = iVar17;
    }
  }
  else {
    param_2[0x2a] = param_2[5] * iVar19 + param_2[0x2a];
  }
LAB_c08aaa0c:
  if ((uVar7 & 0x400000) != 0) {
    piVar5 = *(int **)(param_1 + 0x30);
    iVar11 = 0;
    iVar17 = 0;
    if (piVar5 != (int *)0x0) {
      iVar11 = *(int *)(*(int *)(param_1 + 0x10) + 0x30) - piVar5[1];
      iVar17 = *(int *)(*(int *)(param_1 + 0x10) + 0x2c) - *piVar5;
    }
    iVar12 = *(int *)(param_1 + 0x10);
    iVar10 = *(int *)(iVar12 + 0x2c);
    iVar21 = (iVar17 + iVar20) % iVar10;
    if (iVar10 == 0) {
      trap(0x1c00);
    }
    if ((iVar10 == -1) && (iVar17 + iVar20 == -0x80000000)) {
      trap(0x1800);
    }
    uVar8 = (iVar17 + iVar14) % iVar10;
    if (iVar10 == 0) {
      trap(0x1c00);
    }
    if ((iVar10 == -1) && (iVar17 + iVar14 == -0x80000000)) {
      trap(0x1800);
    }
    iVar17 = *(int *)(iVar12 + 0x30);
    iVar10 = (iVar11 + iVar13) % iVar17;
    if (iVar17 == 0) {
      trap(0x1c00);
    }
    if ((iVar17 == -1) && (iVar11 + iVar13 == -0x80000000)) {
      trap(0x1800);
    }
    uVar4 = (iVar11 + iVar9) % iVar17;
    if (iVar17 == 0) {
      trap(0x1c00);
    }
    if ((iVar17 == -1) && (iVar11 + iVar9 == -0x80000000)) {
      trap(0x1800);
    }
    param_2[0x3a] = *(uint *)(iVar12 + 4);
    param_2[0x39] = *(uint *)(iVar12 + 0x2c);
    param_2[0x17] = *(uint *)(iVar12 + 0x30);
    if (uVar4 == 0) {
      uVar4 = *(uint *)(iVar12 + 0x30);
    }
    if (*(int *)(param_1 + 0x38) == 0) {
      param_2[0x16] = -*(int *)(iVar12 + 8);
      iVar17 = *(int *)(iVar12 + 8);
      param_2[0x37] = uVar4;
      param_2[0x3a] = (uVar4 - 1) * iVar17 + param_2[0x3a];
    }
    else {
      param_2[0x16] = *(uint *)(iVar12 + 8);
      iVar17 = *(int *)(iVar12 + 8);
      param_2[0x37] = param_2[0x17] - iVar10;
      param_2[0x3a] = iVar17 * iVar10 + param_2[0x3a];
    }
    iVar17 = *(int *)(&LAB_c0891154 + *(int *)(iVar12 + 0x1c) * 4);
    if (iVar17 < 8) {
      uVar4 = 8 - iVar17;
    }
    else {
      uVar4 = 0;
    }
    param_2[0x13] = uVar4;
    if (iVar17 == 0) {
      trap(0x1c00);
    }
    uVar4 = 0x20 / iVar17 << 8;
    param_2[0x11] = uVar4;
    if (*(int *)(param_1 + 0x34) == 0) {
      param_2[0x18] = uVar8;
      param_2[0x12] = (iVar17 * -0x100 + -1) * 0x100;
      param_2[0x11] = (0x20 - iVar17) * 0x10000 | uVar4;
      iVar21 = uVar8 - 1;
    }
    else {
      param_2[0x12] = (iVar17 * 0x100 + -1) * 0x100;
      param_2[0x18] = param_2[0x39] - iVar21;
    }
    uVar8 = iVar21 * iVar17;
    param_2[0x10] = param_2[0x11];
    uVar4 = ((int)uVar8 >> 3 & 0xfffffffcU) + param_2[0x3a];
    param_2[0x3a] = uVar4;
    if (((param_2[0x11] >> 0x10 ^ uVar8) & 0x1f) != 0) {
      do {
        param_2[0x10] = param_2[0x12] + param_2[0x10];
      } while (((*(ushort *)((int)param_2 + 0x42) ^ uVar8) & 0x1f) != 0);
    }
    param_2[0x15] = uVar4 - (param_2[0x17] - param_2[0x37]) * param_2[0x16];
    uVar8 = (int)((param_2[0x39] - param_2[0x18]) * iVar17) >> 3 & 0xfffffffc;
    param_2[0x14] = uVar8;
    if (*(int *)(param_1 + 0x34) == 0) {
      param_2[0x14] = -uVar8;
    }
  }
  if ((uVar7 & 0x200000) != 0) {
    iVar17 = *(int *)(param_1 + 8);
    piVar5 = *(int **)(param_1 + 0x18);
    param_2[0x31] = *(uint *)(iVar17 + 4);
    if (*(int *)(param_1 + 0x38) == 0) {
      param_2[0x32] = -*(int *)(iVar17 + 8);
      param_2[0x31] = ((piVar5[3] - iVar18) + -1) * *(int *)(iVar17 + 8) + param_2[0x31];
    }
    else {
      param_2[0x32] = *(uint *)(iVar17 + 8);
      param_2[0x31] = (piVar5[1] + iVar18) * *(int *)(iVar17 + 8) + param_2[0x31];
    }
    iVar17 = *(int *)(&LAB_c0891154 + *(int *)(iVar17 + 0x1c) * 4);
    if (iVar17 < 8) {
      uVar8 = 8 - iVar17;
    }
    else {
      uVar8 = 0;
    }
    param_2[0xf] = uVar8;
    if (iVar17 == 0) {
      trap(0x1c00);
    }
    uVar8 = 0x20 / iVar17 << 8;
    param_2[0xd] = uVar8;
    iVar11 = iVar17 * 0x100;
    if (*(int *)(param_1 + 0x34) == 0) {
      iVar11 = iVar17 * -0x100;
      iVar21 = (piVar5[2] - iVar3) + -1;
      param_2[0xd] = (0x20 - iVar17) * 0x10000 | uVar8;
    }
    else {
      iVar21 = *piVar5 + iVar3;
    }
    param_2[0xe] = (iVar11 + -1) * 0x100;
    if ((uVar7 & 0x2000000) == 0) {
      uVar8 = iVar21 * iVar17;
      param_2[0xc] = param_2[0xd];
      param_2[0x31] = ((int)uVar8 >> 3 & 0xfffffffcU) + param_2[0x31];
      if (((param_2[0xd] >> 0x10 ^ uVar8) & 0x1f) != 0) {
        do {
          param_2[0xc] = param_2[0xe] + param_2[0xc];
        } while (((*(ushort *)((int)param_2 + 0x32) ^ uVar8) & 0x1f) != 0);
      }
    }
    else {
      param_2[0x31] = iVar21 * 3 + param_2[0x31];
    }
    uVar8 = (2 << (iVar17 - 1U & 0x1f)) - 1;
    param_2[0x1e] = uVar8;
    param_2[0x1f] = uVar8;
  }
  if ((uVar7 & 0x800000) != 0) {
    iVar17 = *(int *)(param_1 + 0xc);
    piVar5 = *(int **)(param_1 + 0x2c);
    param_2[0x3e] = *(uint *)(iVar17 + 4);
    if (*(int *)(param_1 + 0x38) == 0) {
      param_2[0x3f] = -*(int *)(iVar17 + 8);
      param_2[0x3e] = ((piVar5[3] - iVar18) + -1) * *(int *)(iVar17 + 8) + param_2[0x3e];
    }
    else {
      param_2[0x3f] = *(uint *)(iVar17 + 8);
      param_2[0x3e] = (piVar5[1] + iVar18) * *(int *)(iVar17 + 8) + param_2[0x3e];
    }
    param_2[0x1c] = 7;
    param_2[0x1a] = 0x800;
    if (*(int *)(param_1 + 0x34) == 0) {
      uVar4 = (piVar5[2] - iVar3) - 1;
      uVar8 = 0xfffeff00;
      param_2[0x1a] = 0x70800;
    }
    else {
      uVar4 = *piVar5 + iVar3;
      uVar8 = 0xff00;
    }
    param_2[0x1b] = uVar8;
    param_2[0x19] = param_2[0x1a];
    param_2[0x3e] = ((int)uVar4 >> 3) + param_2[0x3e];
    if (((param_2[0x1a] >> 0x10 ^ uVar4) & 7) != 0) {
      do {
        param_2[0x19] = param_2[0x1b] + param_2[0x19];
      } while (((*(ushort *)((int)param_2 + 0x66) ^ uVar4) & 7) != 0);
    }
  }
  if (((((uVar7 & 0x4000000) == 0) && ((uVar7 & 0x8000000) == 0)) && ((uVar7 & 0x10000000) == 0)) &&
     ((uVar7 & 0x20000000) == 0)) {
    iVar3 = *(int *)(param_1 + 4);
    uVar8 = *(uint *)(iVar3 + 4);
    param_2[0x2d] = uVar8;
    if (local_34 == 0) {
      param_2[0xb] = -*(uint *)(iVar3 + 8);
      param_2[0x2d] = ((iVar9 - iVar19) + -1) * *(int *)(iVar3 + 8) + param_2[0x2d];
    }
    else {
      param_2[0xb] = *(uint *)(iVar3 + 8);
      param_2[0x2d] = (iVar13 + iVar19) * *(int *)(iVar3 + 8) + uVar8;
    }
    iVar3 = *(int *)(&LAB_c0891154 + *(int *)(iVar3 + 0x1c) * 4);
    if (iVar3 < 8) {
      uVar8 = 8 - iVar3;
    }
    else {
      uVar8 = 0;
    }
    param_2[10] = uVar8;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    uVar8 = 0x20 / iVar3 << 8;
    iVar9 = iVar3 * 0x100;
    param_2[7] = uVar8;
    if (local_30 == 0) {
      iVar20 = (iVar14 - iVar15) + -1;
      param_2[7] = (0x20 - iVar3) * 0x10000 | uVar8;
      iVar9 = iVar3 * -0x100;
    }
    else {
      iVar20 = iVar20 + iVar15;
    }
    uVar4 = (iVar9 + -1) * 0x100;
    param_2[8] = uVar4 + 1;
    param_2[9] = uVar4;
    param_2[6] = param_2[7];
    param_2[0x2d] = (iVar20 * iVar3 >> 3 & 0xfffffffcU) + param_2[0x2d];
    uVar8 = param_2[7] >> 0x10;
    while (((uVar8 ^ iVar20 * iVar3) & 0x1f) != 0) {
      param_2[6] = uVar4 + param_2[6];
      uVar8 = (uint)*(ushort *)((int)param_2 + 0x1a);
    }
    param_2[0x1d] = (2 << (iVar3 - 1U & 0x1f)) - 1;
  }
  else {
    iVar3 = *(int *)(&LAB_c0891154 + *(int *)(*(int *)(param_1 + 4) + 0x1c) * 4);
    if (local_34 == 0) {
      param_2[0xb] = -*(int *)(*(int *)(param_1 + 4) + 8);
      param_2[0x2d] =
           ((iVar9 - iVar19) + -1) * *(int *)(*(int *)(param_1 + 4) + 8) +
           *(int *)(*(int *)(param_1 + 4) + 4);
    }
    else {
      param_2[0xb] = *(uint *)(*(int *)(param_1 + 4) + 8);
      param_2[0x2d] =
           (iVar13 + iVar19) * *(int *)(*(int *)(param_1 + 4) + 8) +
           *(int *)(*(int *)(param_1 + 4) + 4);
    }
    iVar9 = iVar3 >> 3;
    if (local_30 == 0) {
      if (iVar3 < 0) {
        iVar9 = iVar3 + 7 >> 3;
      }
      uVar8 = ((iVar14 - iVar15) + -1) * iVar9 + param_2[0x2d];
    }
    else {
      if (iVar3 < 0) {
        iVar9 = iVar3 + 7 >> 3;
      }
      uVar8 = iVar9 * (iVar20 + iVar15) + param_2[0x2d];
    }
    param_2[0x2d] = uVar8;
    param_2[0x1d] = (2 << (iVar3 - 1U & 0x1f)) - 1;
    param_2[0x52] = 0;
  }
  if (((uVar7 & 0x40) != 0) || ((uVar7 & 0x10) != 0)) {
    param_2[0x35] = param_2[0x3f];
    param_2[0x33] = param_2[0x32];
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    param_2[0x4d] = 0;
  }
  else if (*(int *)(param_1 + 0x28) == 0xffff) {
    param_2[0x4d] = param_2[0x1d];
  }
  else {
    param_2[0x4d] = param_2[0x1d] & param_2[0x21];
  }
  param_2[0x4e] = param_2[0x4d];
  param_2[0x50] = *(uint *)(param_1 + 0x50) & 0xf;
  param_2[0x51] = *(uint *)(param_1 + 0x50) >> 4 & 0xf;
  return;
}



/* c08ab3d4 FUN_c08ab3d4 */

/* Boundary evidence: original MIPS .pdata c08ab3d4..c08ab9d3. Semantic name remains unreviewed. */

undefined4 FUN_c08ab3d4(undefined4 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  byte *pbVar15;
  int iVar16;
  byte *pbVar17;
  int *piVar18;
  byte *local_4c;
  undefined1 *local_48;
  int local_3c;
  
  iVar6 = *(int *)(param_2 + 4);
  iVar2 = *(int *)(*(int *)(param_2 + 8) + 8);
  iVar3 = *(int *)(iVar6 + 8);
  piVar18 = *(int **)(param_2 + 0x14);
  iVar4 = *(int *)(iVar6 + 0x38);
  iVar8 = **(int **)(param_2 + 0x18);
  uVar10 = -iVar8 & 7;
  uVar7 = (piVar18[2] - *piVar18) - uVar10;
  iVar16 = (int)uVar7 >> 3;
  uVar7 = uVar7 & 7;
  iVar14 = 0;
  iVar11 = 0;
  local_4c = (byte *)((*(int **)(param_2 + 0x18))[1] * iVar2 + (iVar8 >> 3) +
                     *(int *)(*(int *)(param_2 + 8) + 4));
  local_48 = (undefined1 *)(piVar18[1] * iVar3 + *piVar18 + *(int *)(iVar6 + 4));
  do {
    piVar12 = (int *)((int)&DAT_c08c06ec + iVar11);
    *piVar12 = iVar14;
    if (*(int *)(param_2 + 0x3c) != 0) {
      *piVar12 = *(int *)(*(int *)(param_2 + 0x3c) + iVar11);
    }
    if (*(code **)(param_2 + 0x40) != (code *)0x0) {
      iVar6 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),*piVar12);
      *piVar12 = iVar6;
    }
    iVar11 = iVar11 + 4;
    iVar14 = iVar14 + 1;
  } while (iVar11 < 8);
  iVar6 = piVar18[1];
  if (iVar6 < piVar18[3]) {
    pbVar17 = local_4c + 1;
    do {
      if (iVar4 == 0) {
        bVar1 = *local_4c;
        puVar9 = local_48;
        if (uVar10 == 1) {
LAB_c08ab63c:
          *puVar9 = (char)(&DAT_c08c06ec)[bVar1 & 1];
          puVar9 = puVar9 + 1;
          pbVar15 = pbVar17;
        }
        else {
          if (uVar10 == 2) {
LAB_c08ab620:
            *puVar9 = (char)(&DAT_c08c06ec)[bVar1 >> 1 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08ab63c;
          }
          if (uVar10 == 3) {
LAB_c08ab604:
            *puVar9 = (char)(&DAT_c08c06ec)[bVar1 >> 2 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08ab620;
          }
          if (uVar10 == 4) {
LAB_c08ab5e8:
            *puVar9 = (char)(&DAT_c08c06ec)[bVar1 >> 3 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08ab604;
          }
          if (uVar10 == 5) {
LAB_c08ab5cc:
            *puVar9 = (char)(&DAT_c08c06ec)[bVar1 >> 4 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08ab5e8;
          }
          if (uVar10 == 6) {
LAB_c08ab5b0:
            *puVar9 = (char)(&DAT_c08c06ec)[bVar1 >> 5 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08ab5cc;
          }
          pbVar15 = local_4c;
          if (uVar10 == 7) {
            puVar9 = local_48 + 1;
            *local_48 = (char)(&DAT_c08c06ec)[bVar1 >> 6 & 1];
            goto LAB_c08ab5b0;
          }
        }
        iVar8 = iVar16;
        if (0 < iVar16) {
          do {
            uVar5 = (uint)*pbVar15;
            puVar9[7] = (char)(&DAT_c08c06ec)[uVar5 & 1];
            puVar9[6] = (char)(&DAT_c08c06ec)[(int)uVar5 >> 1 & 1];
            puVar9[5] = (char)(&DAT_c08c06ec)[(int)uVar5 >> 2 & 1];
            puVar9[4] = (char)(&DAT_c08c06ec)[(int)uVar5 >> 3 & 1];
            puVar9[3] = (char)(&DAT_c08c06ec)[(int)uVar5 >> 4 & 1];
            puVar9[2] = (char)(&DAT_c08c06ec)[(int)uVar5 >> 5 & 1];
            pbVar15 = pbVar15 + 1;
            puVar9[1] = (char)(&DAT_c08c06ec)[(int)uVar5 >> 6 & 1];
            iVar8 = iVar8 + -1;
            *puVar9 = (char)(&DAT_c08c06ec)[(int)uVar5 >> 7];
            puVar9 = puVar9 + 8;
          } while (iVar8 != 0);
        }
        bVar1 = *pbVar15;
        if (uVar7 != 1) {
          if (uVar7 != 2) {
            if (uVar7 != 3) {
              if (uVar7 != 4) {
                if (uVar7 != 5) {
                  if (uVar7 != 6) {
                    if (uVar7 != 7) goto LAB_c08ab968;
                    puVar9[6] = (char)(&DAT_c08c06ec)[bVar1 >> 1 & 1];
                  }
                  puVar9[5] = (char)(&DAT_c08c06ec)[bVar1 >> 2 & 1];
                }
                puVar9[4] = (char)(&DAT_c08c06ec)[bVar1 >> 3 & 1];
              }
              puVar9[3] = (char)(&DAT_c08c06ec)[bVar1 >> 4 & 1];
            }
            puVar9[2] = (char)(&DAT_c08c06ec)[bVar1 >> 5 & 1];
          }
          puVar9[1] = (char)(&DAT_c08c06ec)[bVar1 >> 6 & 1];
        }
        *puVar9 = (char)(&DAT_c08c06ec)[bVar1 >> 7];
      }
      else {
        bVar1 = *local_4c;
        iVar8 = *piVar18;
        uVar13 = uVar10;
        for (uVar5 = uVar10; uVar5 != 0; uVar5 = uVar5 - 1) {
          uVar13 = uVar13 - 1;
          puVar9 = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar8,iVar6);
          *puVar9 = (char)(&DAT_c08c06ec)[bVar1 >> (uVar13 & 0x1f) & 1];
          iVar8 = iVar8 + 1;
        }
        pbVar15 = pbVar17;
        local_3c = iVar16;
        if (0 < iVar16) {
          do {
            bVar1 = *pbVar15;
            iVar11 = 0x7ffffff9;
            do {
              puVar9 = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar8,iVar6);
              *puVar9 = (char)(&DAT_c08c06ec)[bVar1 & 1];
              bVar1 = 1 < bVar1;
              iVar11 = iVar11 + -1;
              iVar8 = iVar8 + 1;
            } while (iVar11 != 0);
            local_3c = local_3c + -1;
            pbVar15 = pbVar15 + 1;
          } while (local_3c != 0);
        }
        bVar1 = *pbVar15;
        uVar5 = 0;
        if (uVar7 != 0) {
          do {
            puVar9 = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar8,iVar6);
            uVar13 = uVar5 & 0x1f;
            uVar5 = uVar5 + 1;
            *puVar9 = (char)(&DAT_c08c06ec)[bVar1 >> uVar13 & 1];
            iVar8 = iVar8 + 1;
          } while ((int)uVar5 < (int)uVar7);
        }
      }
LAB_c08ab968:
      local_4c = local_4c + iVar2;
      pbVar17 = pbVar17 + iVar2;
      local_48 = local_48 + iVar3;
      iVar6 = iVar6 + 1;
    } while (iVar6 < piVar18[3]);
  }
  return 0;
}



/* c08ab9d4 FUN_c08ab9d4 */

/* Boundary evidence: original MIPS .pdata c08ab9d4..c08abbe7. Semantic name remains unreviewed. */

undefined4 FUN_c08ab9d4(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  byte *pbVar12;
  uint uVar13;
  byte *pbVar14;
  undefined1 *local_78;
  int local_68 [16];
  
  iVar3 = *(int *)(param_2 + 4);
  iVar5 = *(int *)(*(int *)(param_2 + 8) + 8);
  iVar6 = *(int *)(iVar3 + 8);
  puVar4 = *(uint **)(param_2 + 0x18);
  piVar11 = *(int **)(param_2 + 0x14);
  bVar1 = *(int *)(iVar3 + 0x38) != 0;
  iVar10 = 0;
  iVar9 = 0;
  pbVar14 = (byte *)(puVar4[1] * iVar5 + ((int)*puVar4 >> 1) + *(int *)(*(int *)(param_2 + 8) + 4));
  local_78 = (undefined1 *)(piVar11[1] * iVar6 + *(int *)(iVar3 + 4) + *piVar11);
  do {
    piVar7 = (int *)((int)local_68 + iVar9);
    iVar3 = *(int *)(param_2 + 0x3c);
    *piVar7 = iVar10;
    if (iVar3 != 0) {
      *piVar7 = *(int *)(iVar9 + iVar3);
    }
    if (*(code **)(param_2 + 0x40) != (code *)0x0) {
      iVar3 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),*piVar7);
      *piVar7 = iVar3;
    }
    iVar9 = iVar9 + 4;
    iVar10 = iVar10 + 1;
  } while (iVar9 < 0x40);
  iVar3 = piVar11[1];
  if (iVar3 < piVar11[3]) {
    do {
      iVar9 = *piVar11;
      uVar8 = *puVar4 & 1;
      puVar2 = local_78;
      pbVar12 = pbVar14;
      if (iVar9 < piVar11[2]) {
        do {
          if (uVar8 == 0) {
            uVar13 = (uint)(*pbVar12 >> 4);
          }
          else {
            uVar13 = *pbVar12 & 0xf;
            pbVar12 = pbVar12 + 1;
          }
          uVar8 = (uint)(uVar8 == 0);
          if (bVar1) {
            puVar2 = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar9,iVar3);
          }
          *puVar2 = (char)local_68[uVar13];
          if (!bVar1) {
            puVar2 = puVar2 + 1;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < piVar11[2]);
      }
      pbVar14 = pbVar14 + iVar5;
      local_78 = local_78 + iVar6;
      iVar3 = iVar3 + 1;
    } while (iVar3 < piVar11[3]);
  }
  return 0;
}



/* c08abbe8 FUN_c08abbe8 */

/* Boundary evidence: original MIPS .pdata c08abbe8..c08abfeb. Semantic name remains unreviewed. */

undefined4 FUN_c08abbe8(undefined4 param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  size_t _Size;
  undefined1 *puVar6;
  int *piVar7;
  int iVar8;
  void *_Src;
  int *piVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  int iVar13;
  int local_40;
  void *local_38;
  int *local_34;
  int *local_30;
  
  iVar4 = *(int *)(param_2 + 8);
  piVar7 = *(int **)(param_2 + 0x18);
  local_40 = *(int *)(iVar4 + 8);
  bVar1 = *(int *)(iVar4 + 0x38) == 0;
  iVar5 = *(int *)(param_2 + 4);
  piVar9 = *(int **)(param_2 + 0x14);
  iVar13 = *(int *)(iVar5 + 8);
  bVar2 = *(int *)(iVar5 + 0x38) == 0;
  iVar8 = piVar9[1];
  iVar11 = piVar9[3] - iVar8;
  _Size = piVar9[2] - *piVar9;
  if (bVar1) {
    if (bVar2) goto LAB_c08abd9c;
  }
  else if (bVar2) {
    iVar4 = piVar7[1];
    puVar6 = (undefined1 *)(iVar8 * iVar13 + *(int *)(iVar5 + 4) + *piVar9);
    if (piVar7[3] <= iVar4) {
      return 0;
    }
    puVar10 = puVar6 + _Size;
    do {
      iVar11 = *piVar7;
      for (puVar12 = puVar6; puVar12 < puVar10; puVar12 = puVar12 + 1) {
        puVar3 = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 8),iVar11,iVar4);
        *puVar12 = *puVar3;
        iVar11 = iVar11 + 1;
      }
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + iVar13;
      puVar10 = puVar10 + iVar13;
    } while (iVar4 < piVar7[3]);
    return 0;
  }
  if (bVar1) {
    puVar6 = (undefined1 *)(piVar7[1] * local_40 + *(int *)(iVar4 + 4) + *piVar7);
    if (piVar9[3] <= iVar8) {
      return 0;
    }
    puVar10 = puVar6 + _Size;
    do {
      iVar13 = *piVar9;
      for (puVar12 = puVar6; puVar12 < puVar10; puVar12 = puVar12 + 1) {
        puVar3 = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar13,iVar8);
        iVar13 = iVar13 + 1;
        *puVar3 = *puVar12;
      }
      iVar8 = iVar8 + 1;
      puVar6 = puVar6 + local_40;
      puVar10 = puVar10 + local_40;
    } while (iVar8 < piVar9[3]);
    return 0;
  }
LAB_c08abd9c:
  if (*(int *)(iVar4 + 0x38) == *(int *)(iVar5 + 0x38)) {
    local_34 = piVar7;
    local_30 = piVar7;
    if ((!bVar2) && (!bVar1)) {
      FUN_c0894674(iVar4,piVar7);
      FUN_c0894674(*(int *)(param_2 + 4),piVar9);
      local_34 = *(int **)(param_2 + 0x34);
      iVar11 = piVar9[3] - piVar9[1];
      local_30 = *(int **)(param_2 + 0x38);
      _Size = piVar9[2] - *piVar9;
      *(uint *)(param_2 + 0x34) = (uint)(*piVar9 <= *piVar7);
      *(uint *)(param_2 + 0x38) = (uint)(piVar9[1] <= piVar7[1]);
    }
    _Src = (void *)(piVar7[1] * local_40 + *(int *)(*(int *)(param_2 + 8) + 4) + *piVar7);
    local_38 = (void *)(piVar9[1] * iVar13 + *(int *)(*(int *)(param_2 + 4) + 4) + *piVar9);
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar4 = (iVar11 + -1) * local_40;
      local_40 = -local_40;
      iVar5 = (iVar11 + -1) * iVar13;
      _Src = (void *)(iVar4 + (int)_Src);
      iVar13 = -iVar13;
      local_38 = (void *)(iVar5 + (int)local_38);
    }
    if (0 < iVar11) {
      do {
        memmove(local_38,_Src,_Size);
        iVar11 = iVar11 + -1;
        _Src = (void *)((int)_Src + local_40);
        local_38 = (void *)((int)local_38 + iVar13);
      } while (iVar11 != 0);
    }
    if ((!bVar2) && (!bVar1)) {
      *(int **)(param_2 + 0x34) = local_34;
      *(int **)(param_2 + 0x38) = local_30;
      FUN_c0894728(*(int *)(param_2 + 8),piVar7);
      FUN_c0894728(*(int *)(param_2 + 4),piVar9);
    }
  }
  else {
    iVar13 = 0;
    if (0 < iVar11) {
      do {
        iVar4 = 0;
        if (0 < (int)_Size) {
          do {
            puVar6 = (undefined1 *)
                     FUN_c08947dc(*(int *)(param_2 + 4),*piVar9 + iVar4,piVar9[1] + iVar13);
            puVar10 = (undefined1 *)
                      FUN_c08947dc(*(int *)(param_2 + 8),*piVar7 + iVar4,piVar7[1] + iVar13);
            iVar4 = iVar4 + 1;
            *puVar6 = *puVar10;
          } while (iVar4 < (int)_Size);
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < iVar11);
    }
  }
  return 0;
}



/* c08abfec FUN_c08abfec */

/* Boundary evidence: original MIPS .pdata c08abfec..c08ac453. Semantic name remains unreviewed. */

undefined4 FUN_c08abfec(undefined4 param_1,int param_2)

{
  bool bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  int *piVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  
  iVar5 = *(int *)(param_2 + 8);
  piVar14 = *(int **)(param_2 + 0x18);
  iVar17 = *(int *)(iVar5 + 8);
  bVar1 = *(int *)(iVar5 + 0x38) != 0;
  iVar7 = *(int *)(param_2 + 4);
  piVar16 = *(int **)(param_2 + 0x14);
  iVar15 = *(int *)(iVar7 + 8);
  uVar4 = (uint)(*(int *)(iVar7 + 0x38) != 0);
  iVar9 = piVar16[1];
  iVar10 = piVar16[3] - iVar9;
  iVar12 = piVar16[2] - *piVar16;
  if (bVar1) {
    if (uVar4 == 0) {
      iVar17 = piVar14[1];
      pbVar8 = (byte *)(iVar9 * iVar15 + *(int *)(iVar7 + 4) + *piVar16);
      if (piVar14[3] <= iVar17) {
        return 0;
      }
      pbVar11 = pbVar8 + iVar12;
      do {
        iVar5 = *piVar14;
        for (pbVar13 = pbVar8; pbVar13 < pbVar11; pbVar13 = pbVar13 + 1) {
          pbVar2 = (byte *)FUN_c08947dc(*(int *)(param_2 + 8),iVar5,iVar17);
          *pbVar13 = *pbVar13 | *pbVar2;
          iVar5 = iVar5 + 1;
        }
        iVar17 = iVar17 + 1;
        pbVar8 = pbVar8 + iVar15;
        pbVar11 = pbVar11 + iVar15;
      } while (iVar17 < piVar14[3]);
      return 0;
    }
  }
  else if (uVar4 == 0) goto LAB_c08ac1a4;
  if (!bVar1) {
    pbVar8 = (byte *)(piVar14[1] * iVar17 + *(int *)(iVar5 + 4) + *piVar14);
    if (piVar16[3] <= iVar9) {
      return 0;
    }
    pbVar11 = pbVar8 + iVar12;
    do {
      iVar15 = *piVar16;
      for (pbVar13 = pbVar8; pbVar13 < pbVar11; pbVar13 = pbVar13 + 1) {
        pbVar2 = (byte *)FUN_c08947dc(*(int *)(param_2 + 4),iVar15,iVar9);
        iVar15 = iVar15 + 1;
        *pbVar2 = *pbVar2 | *pbVar13;
      }
      iVar9 = iVar9 + 1;
      pbVar8 = pbVar8 + iVar17;
      pbVar11 = pbVar11 + iVar17;
    } while (iVar9 < piVar16[3]);
    return 0;
  }
LAB_c08ac1a4:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar7 + 0x38)) {
    uVar3 = uVar4;
    uVar6 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c0894674(iVar5,piVar14);
      FUN_c0894674(*(int *)(param_2 + 4),piVar16);
      iVar10 = piVar16[3] - piVar16[1];
      iVar12 = piVar16[2] - *piVar16;
      uVar3 = *(uint *)(param_2 + 0x34);
      uVar6 = *(uint *)(param_2 + 0x38);
      *(uint *)(param_2 + 0x34) = (uint)(*piVar16 <= *piVar14);
      *(uint *)(param_2 + 0x38) = (uint)(piVar16[1] <= piVar14[1]);
    }
    iVar5 = piVar14[1] * iVar17 + *(int *)(*(int *)(param_2 + 8) + 4) + *piVar14;
    pbVar8 = (byte *)(piVar16[1] * iVar15 + *(int *)(*(int *)(param_2 + 4) + 4) + *piVar16);
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar7 = (iVar10 + -1) * iVar17;
      iVar17 = -iVar17;
      iVar9 = (iVar10 + -1) * iVar15;
      iVar5 = iVar7 + iVar5;
      iVar15 = -iVar15;
      pbVar8 = pbVar8 + iVar9;
    }
    if (0 < iVar10) {
      if (*(int *)(param_2 + 0x34) == 0) {
        pbVar11 = pbVar8 + iVar12 + -1;
        iVar5 = iVar5 + iVar12 + -1;
        do {
          if (pbVar8 <= pbVar11) {
            pbVar13 = pbVar11;
            do {
              *pbVar13 = pbVar13[iVar5 - (int)pbVar11] | *pbVar13;
              pbVar13 = pbVar13 + -1;
            } while (pbVar8 <= pbVar13);
          }
          iVar10 = iVar10 + -1;
          iVar5 = iVar5 + iVar17;
          pbVar8 = pbVar8 + iVar15;
          pbVar11 = pbVar11 + iVar15;
        } while (iVar10 != 0);
      }
      else {
        pbVar11 = pbVar8 + iVar12;
        do {
          if (pbVar8 < pbVar11) {
            pbVar13 = pbVar8;
            do {
              *pbVar13 = pbVar13[iVar5 - (int)pbVar8] | *pbVar13;
              pbVar13 = pbVar13 + 1;
            } while (pbVar13 < pbVar11);
          }
          iVar10 = iVar10 + -1;
          iVar5 = iVar5 + iVar17;
          pbVar8 = pbVar8 + iVar15;
          pbVar11 = pbVar11 + iVar15;
        } while (iVar10 != 0);
      }
    }
    if ((uVar4 != 0) && (bVar1)) {
      *(uint *)(param_2 + 0x34) = uVar3;
      *(uint *)(param_2 + 0x38) = uVar6;
      FUN_c0894728(*(int *)(param_2 + 8),piVar14);
      FUN_c0894728(*(int *)(param_2 + 4),piVar16);
    }
  }
  else {
    iVar17 = 0;
    if (0 < iVar10) {
      do {
        iVar15 = 0;
        if (0 < iVar12) {
          do {
            pbVar8 = (byte *)FUN_c08947dc(*(int *)(param_2 + 4),*piVar16 + iVar15,
                                          piVar16[1] + iVar17);
            pbVar11 = (byte *)FUN_c08947dc(*(int *)(param_2 + 8),*piVar14 + iVar15,
                                           piVar14[1] + iVar17);
            iVar15 = iVar15 + 1;
            *pbVar8 = *pbVar11 | *pbVar8;
          } while (iVar15 < iVar12);
        }
        iVar17 = iVar17 + 1;
      } while (iVar17 < iVar10);
    }
  }
  return 0;
}



/* c08ac454 FUN_c08ac454 */

/* Boundary evidence: original MIPS .pdata c08ac454..c08ac92f. Semantic name remains unreviewed. */

undefined4 FUN_c08ac454(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  size_t sVar10;
  size_t sVar11;
  size_t _Size;
  size_t _Size_00;
  undefined1 *_Dst;
  undefined1 *_Src;
  int iVar12;
  undefined1 *puVar13;
  int iVar14;
  size_t local_60;
  int local_5c;
  int local_54;
  int local_48;
  
  iVar6 = *(int *)(param_2 + 0x10);
  iVar8 = *(int *)(param_2 + 4);
  iVar3 = *(int *)(iVar8 + 8);
  iVar2 = *(int *)(iVar8 + 4);
  iVar5 = *(int *)(iVar6 + 8);
  iVar14 = *(int *)(iVar6 + 0x30);
  _Size_00 = *(size_t *)(iVar6 + 0x2c);
  puVar4 = *(undefined1 **)(iVar6 + 4);
  sVar10 = (*(int **)(param_2 + 0x14))[2] - **(int **)(param_2 + 0x14);
  bVar1 = *(int *)(iVar8 + 0x38) == 0;
  sVar11 = 0;
  local_54 = 0;
  local_60 = 0;
  if (*(int *)(param_2 + 0x30) == 0) {
    iVar6 = **(int **)(param_2 + 0x14);
    local_48 = iVar6 % (int)_Size_00;
    if (_Size_00 == 0) {
      trap(0x1c00);
    }
    if ((_Size_00 == 0xffffffff) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = (*(int **)(param_2 + 0x14))[1];
    iVar8 = iVar6 % iVar14;
    if (iVar14 == 0) {
      trap(0x1c00);
    }
    if ((iVar14 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
  }
  else {
    iVar6 = **(int **)(param_2 + 0x14) - **(int **)(param_2 + 0x30);
    if (_Size_00 == 0) {
      trap(0x1c00);
    }
    if ((_Size_00 == 0xffffffff) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = iVar6 % (int)_Size_00 + _Size_00;
    local_48 = iVar6 % (int)_Size_00;
    if (_Size_00 == 0) {
      trap(0x1c00);
    }
    if ((_Size_00 == 0xffffffff) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = (*(int **)(param_2 + 0x30))[1];
    if (iVar14 == 0) {
      trap(0x1c00);
    }
    if ((iVar14 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = iVar14 - iVar6 % iVar14;
    iVar8 = iVar6 % iVar14;
    if (iVar14 == 0) {
      trap(0x1c00);
    }
    if ((iVar14 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
  }
  if (((local_48 == 0) || (sVar11 = _Size_00 - local_48, _Size = sVar10, (int)sVar11 <= (int)sVar10)
      ) && (_Size = sVar11, (int)sVar11 < (int)sVar10)) {
    if (_Size_00 == 0) {
      trap(0x1c00);
    }
    if ((_Size_00 == 0xffffffff) && (sVar10 - sVar11 == -0x80000000)) {
      trap(0x1800);
    }
    local_54 = ((int)(sVar10 - sVar11) / (int)_Size_00) * _Size_00;
  }
  if ((int)(local_54 + _Size) < (int)sVar10) {
    local_60 = (sVar10 - local_54) - _Size;
  }
  piVar9 = *(int **)(param_2 + 0x14);
  iVar6 = piVar9[1];
  if (iVar6 < piVar9[3]) {
    iVar7 = iVar6 * iVar3;
    iVar8 = iVar6 + iVar8;
    _Dst = puVar4;
    do {
      if (bVar1) {
        _Dst = (undefined1 *)(iVar7 + *piVar9 + iVar2);
      }
      if (iVar14 == 0) {
        trap(0x1c00);
      }
      if ((iVar14 == -1) && (iVar8 == -0x80000000)) {
        trap(0x1800);
      }
      _Src = puVar4 + (iVar8 % iVar14) * iVar5;
      if (bVar1) {
        memcpy(_Dst,_Src + local_48,_Size);
        iVar12 = 0;
        if (0 < local_54) {
          puVar13 = _Dst + _Size;
          do {
            memcpy(puVar13,_Src,_Size_00);
            iVar12 = iVar12 + _Size_00;
            puVar13 = puVar13 + _Size_00;
          } while (iVar12 < local_54);
        }
        memcpy(_Dst + local_54 + _Size,_Src,local_60);
      }
      else {
        local_5c = *piVar9;
        puVar13 = _Src + local_48;
        sVar10 = _Size;
        if (0 < (int)_Size) {
          do {
            _Dst = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 4),local_5c,iVar6);
            *_Dst = *puVar13;
            puVar13 = puVar13 + 1;
            sVar10 = sVar10 - 1;
            local_5c = local_5c + 1;
          } while (sVar10 != 0);
        }
        iVar12 = 0;
        if (0 < local_54) {
          do {
            puVar13 = _Src;
            sVar10 = _Size_00;
            if (0 < (int)_Size_00) {
              do {
                _Dst = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 4),local_5c,iVar6);
                *_Dst = *puVar13;
                sVar10 = sVar10 - 1;
                local_5c = local_5c + 1;
                puVar13 = puVar13 + 1;
              } while (sVar10 != 0);
            }
            iVar12 = iVar12 + _Size_00;
          } while (iVar12 < local_54);
        }
        sVar10 = local_60;
        if (0 < (int)local_60) {
          do {
            _Dst = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 4),local_5c,iVar6);
            *_Dst = *_Src;
            _Src = _Src + 1;
            sVar10 = sVar10 - 1;
            local_5c = local_5c + 1;
          } while (sVar10 != 0);
        }
      }
      piVar9 = *(int **)(param_2 + 0x14);
      iVar7 = iVar7 + iVar3;
      iVar6 = iVar6 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar6 < piVar9[3]);
  }
  return 0;
}



/* c08ac930 FUN_c08ac930 */

/* Boundary evidence: original MIPS .pdata c08ac930..c08ac953. Semantic name remains unreviewed. */

void FUN_c08ac930(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = FUN_c089e104;
  FUN_c089e104(param_1,(int)param_2);
  return;
}



/* c08ac954 FUN_c08ac954 */

/* Boundary evidence: original MIPS .pdata c08ac954..c08acb1b. Semantic name remains unreviewed. */

undefined4 FUN_c08ac954(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  byte *pbVar12;
  int iVar13;
  byte *pbVar14;
  
  iVar5 = *(int *)(param_2 + 4);
  iVar9 = *(int *)(*(int *)(param_2 + 0xc) + 8);
  iVar8 = *(int *)(iVar5 + 8);
  uVar3 = *(undefined4 *)(param_2 + 0x20);
  piVar11 = *(int **)(param_2 + 0x14);
  bVar1 = *(int *)(iVar5 + 0x38) != 0;
  iVar13 = piVar11[1];
  uVar6 = **(uint **)(param_2 + 0x2c);
  pbVar14 = (byte *)((*(uint **)(param_2 + 0x2c))[1] * iVar9 + ((int)uVar6 >> 3) +
                    *(int *)(*(int *)(param_2 + 0xc) + 4));
  puVar7 = (undefined1 *)(iVar13 * iVar8 + *(int *)(iVar5 + 4) + *piVar11);
  if (iVar13 < piVar11[3]) {
    do {
      uVar4 = (uint)*pbVar14;
      iVar5 = *piVar11;
      pbVar12 = pbVar14 + 1;
      puVar2 = puVar7;
      uVar10 = 0x80 >> (uVar6 & 7);
      if (iVar5 < piVar11[2]) {
        do {
          if (uVar10 == 0) {
            uVar4 = (uint)*pbVar12;
            uVar10 = 0x80;
            pbVar12 = pbVar12 + 1;
          }
          if ((uVar10 & uVar4) == 0) {
            if (!bVar1) goto LAB_c08aca9c;
          }
          else {
            if (bVar1) {
              puVar2 = (undefined1 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar5,iVar13);
            }
            *puVar2 = (char)uVar3;
LAB_c08aca9c:
            puVar2 = puVar2 + 1;
          }
          iVar5 = iVar5 + 1;
          uVar10 = uVar10 >> 1;
        } while (iVar5 < piVar11[2]);
      }
      pbVar14 = pbVar14 + iVar9;
      puVar7 = puVar7 + iVar8;
      iVar13 = iVar13 + 1;
    } while (iVar13 < piVar11[3]);
  }
  return 0;
}



/* c08acb1c FUN_c08acb1c */

/* Boundary evidence: original MIPS .pdata c08acb1c..c08acc03. Semantic name remains unreviewed. */

undefined4 FUN_c08acb1c(undefined4 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *_Dst;
  int iVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_2 + 0x20);
  iVar6 = *(int *)(*(int *)(param_2 + 4) + 8);
  piVar4 = *(int **)(param_2 + 0x14);
  if (*(int *)(*(int *)(param_2 + 4) + 0x38) != 0) {
    FUN_c0894674(*(int *)(param_2 + 4),piVar4);
  }
  iVar3 = *piVar4;
  iVar5 = piVar4[3] - piVar4[1];
  iVar2 = piVar4[2];
  _Dst = (void *)(piVar4[1] * iVar6 + *(int *)(*(int *)(param_2 + 4) + 4) + iVar3);
  if (0 < iVar5) {
    do {
      memset(_Dst,(uint)bVar1,iVar2 - iVar3);
      iVar5 = iVar5 + -1;
      _Dst = (void *)((int)_Dst + iVar6);
    } while (iVar5 != 0);
  }
  if (*(int *)(*(int *)(param_2 + 4) + 0x38) != 0) {
    FUN_c0894728(*(int *)(param_2 + 4),piVar4);
  }
  return 0;
}



/* c08acc04 FUN_c08acc04 */

/* Boundary evidence: original MIPS .pdata c08acc04..c08acd5f. Semantic name remains unreviewed. */

undefined4 FUN_c08acc04(undefined4 param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  iVar8 = *(int *)(*(int *)(param_2 + 4) + 8);
  piVar7 = *(int **)(param_2 + 0x14);
  if (*(int *)(*(int *)(param_2 + 4) + 0x38) != 0) {
    FUN_c0894674(*(int *)(param_2 + 4),piVar7);
  }
  iVar9 = piVar7[3] - piVar7[1];
  uVar4 = piVar7[2] - *piVar7;
  puVar2 = (uint *)(piVar7[1] * iVar8 + *(int *)(*(int *)(param_2 + 4) + 4) + *piVar7);
  uVar6 = 4 - ((uint)puVar2 & 3);
  if (uVar4 <= uVar6) {
    uVar6 = uVar4;
  }
  uVar6 = uVar6 & 3;
  uVar10 = uVar4 - uVar6 & 0xfffffffc;
  if (0 < iVar9) {
    puVar1 = (uint *)(uVar6 + (int)puVar2);
    puVar3 = puVar2;
    do {
      for (; puVar2 < puVar1; puVar2 = (uint *)((int)puVar2 + 1)) {
        *(byte *)puVar2 = ~(byte)*puVar2;
      }
      puVar5 = (uint *)((int)puVar2 + uVar10);
      for (; puVar2 < puVar5; puVar2 = puVar2 + 1) {
        *puVar2 = ~*puVar2;
      }
      puVar5 = (uint *)((int)puVar2 + ((uVar4 - uVar10) - uVar6));
      for (; puVar2 < puVar5; puVar2 = (uint *)((int)puVar2 + 1)) {
        *(byte *)puVar2 = ~(byte)*puVar2;
      }
      iVar9 = iVar9 + -1;
      puVar2 = (uint *)((int)puVar3 + iVar8);
      puVar1 = (uint *)((int)puVar1 + iVar8);
      puVar3 = puVar2;
    } while (iVar9 != 0);
  }
  if (*(int *)(*(int *)(param_2 + 4) + 0x38) != 0) {
    FUN_c0894728(*(int *)(param_2 + 4),piVar7);
  }
  return 0;
}



/* c08acd60 FUN_c08acd60 */

/* Boundary evidence: original MIPS .pdata c08acd60..c08acedf. Semantic name remains unreviewed. */

undefined4 FUN_c08acd60(undefined4 param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  
  bVar1 = *(byte *)(param_2 + 0x20);
  iVar10 = *(int *)(*(int *)(param_2 + 4) + 8);
  piVar9 = *(int **)(param_2 + 0x14);
  if (*(int *)(*(int *)(param_2 + 4) + 0x38) != 0) {
    FUN_c0894674(*(int *)(param_2 + 4),piVar9);
  }
  iVar11 = piVar9[3] - piVar9[1];
  uVar6 = piVar9[2] - *piVar9;
  puVar4 = (uint *)(piVar9[1] * iVar10 + *(int *)(*(int *)(param_2 + 4) + 4) + *piVar9);
  uVar8 = 4 - ((uint)puVar4 & 3);
  if (uVar6 <= uVar8) {
    uVar8 = uVar6;
  }
  uVar8 = uVar8 & 3;
  uVar2 = uVar6 - uVar8 & 0xfffffffc;
  if (0 < iVar11) {
    puVar3 = (uint *)(uVar8 + (int)puVar4);
    puVar5 = puVar4;
    do {
      for (; puVar4 < puVar3; puVar4 = (uint *)((int)puVar4 + 1)) {
        *(byte *)puVar4 = (byte)*puVar4 ^ bVar1;
      }
      puVar7 = (uint *)((int)puVar4 + uVar2);
      for (; puVar4 < puVar7; puVar4 = puVar4 + 1) {
        *puVar4 = *puVar4 ^ CONCAT22(CONCAT11(bVar1,bVar1),CONCAT11(bVar1,bVar1));
      }
      puVar7 = (uint *)((int)puVar4 + ((uVar6 - uVar2) - uVar8));
      for (; puVar4 < puVar7; puVar4 = (uint *)((int)puVar4 + 1)) {
        *(byte *)puVar4 = (byte)*puVar4 ^ bVar1;
      }
      iVar11 = iVar11 + -1;
      puVar4 = (uint *)((int)puVar5 + iVar10);
      puVar3 = (uint *)((int)puVar3 + iVar10);
      puVar5 = puVar4;
    } while (iVar11 != 0);
  }
  if (*(int *)(*(int *)(param_2 + 4) + 0x38) != 0) {
    FUN_c0894728(*(int *)(param_2 + 4),piVar9);
  }
  return 0;
}



/* c08acee0 FUN_c08acee0 */

/* Boundary evidence: original MIPS .pdata c08acee0..c08ad22f. Semantic name remains unreviewed. */

undefined4 FUN_c08acee0(undefined4 param_1,int param_2)

{
  bool bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int local_40;
  
  iVar4 = *(int *)(param_2 + 0x10);
  iVar6 = *(int *)(param_2 + 4);
  iVar7 = *(int *)(iVar6 + 8);
  iVar12 = *(int *)(iVar6 + 4);
  iVar13 = *(int *)(iVar4 + 8);
  pbVar3 = *(byte **)(iVar4 + 4);
  iVar8 = (*(int **)(param_2 + 0x14))[2] - **(int **)(param_2 + 0x14);
  iVar10 = *(int *)(iVar4 + 0x30);
  iVar4 = *(int *)(iVar4 + 0x2c);
  bVar1 = *(int *)(iVar6 + 0x38) != 0;
  if (*(int *)(param_2 + 0x30) == 0) {
    iVar6 = **(int **)(param_2 + 0x14);
    local_40 = iVar6 % iVar4;
    if (iVar4 == 0) {
      trap(0x1c00);
    }
    if ((iVar4 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = (*(int **)(param_2 + 0x14))[1];
    iVar14 = iVar6 % iVar10;
    if (iVar10 == 0) {
      trap(0x1c00);
    }
    if ((iVar10 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
  }
  else {
    iVar6 = **(int **)(param_2 + 0x14) - **(int **)(param_2 + 0x30);
    if (iVar4 == 0) {
      trap(0x1c00);
    }
    if ((iVar4 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = iVar6 % iVar4 + iVar4;
    local_40 = iVar6 % iVar4;
    if (iVar4 == 0) {
      trap(0x1c00);
    }
    if ((iVar4 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = (*(int **)(param_2 + 0x30))[1];
    if (iVar10 == 0) {
      trap(0x1c00);
    }
    if ((iVar10 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = iVar10 - iVar6 % iVar10;
    iVar14 = iVar6 % iVar10;
    if (iVar10 == 0) {
      trap(0x1c00);
    }
    if ((iVar10 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
  }
  piVar5 = *(int **)(param_2 + 0x14);
  iVar6 = piVar5[1];
  if (iVar6 < piVar5[3]) {
    iVar11 = iVar6 * iVar7;
    iVar14 = iVar6 + iVar14;
    pbVar2 = pbVar3;
    do {
      if (!bVar1) {
        pbVar2 = (byte *)(iVar11 + *piVar5 + iVar12);
      }
      if (iVar10 == 0) {
        trap(0x1c00);
      }
      if ((iVar10 == -1) && (iVar14 == -0x80000000)) {
        trap(0x1800);
      }
      iVar9 = 0;
      if (0 < iVar8) {
        do {
          if (bVar1) {
            pbVar2 = (byte *)FUN_c08947dc(*(int *)(param_2 + 4),**(int **)(param_2 + 0x14) + iVar9,
                                          iVar6);
          }
          if (iVar4 == 0) {
            trap(0x1c00);
          }
          if ((iVar4 == -1) && (iVar9 + local_40 == -0x80000000)) {
            trap(0x1800);
          }
          *pbVar2 = pbVar3[(iVar9 + local_40) % iVar4 + (iVar14 % iVar10) * iVar13] ^ *pbVar2;
          if (!bVar1) {
            pbVar2 = pbVar2 + 1;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar8);
      }
      piVar5 = *(int **)(param_2 + 0x14);
      iVar6 = iVar6 + 1;
      iVar11 = iVar11 + iVar7;
      iVar14 = iVar14 + 1;
    } while (iVar6 < piVar5[3]);
  }
  return 0;
}



/* c08ad230 FUN_c08ad230 */

/* Boundary evidence: original MIPS .pdata c08ad230..c08ad697. Semantic name remains unreviewed. */

undefined4 FUN_c08ad230(undefined4 param_1,int param_2)

{
  bool bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  int *piVar12;
  int iVar13;
  byte *pbVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  
  iVar5 = *(int *)(param_2 + 8);
  piVar12 = *(int **)(param_2 + 0x18);
  iVar17 = *(int *)(iVar5 + 8);
  bVar1 = *(int *)(iVar5 + 0x38) != 0;
  iVar7 = *(int *)(param_2 + 4);
  piVar16 = *(int **)(param_2 + 0x14);
  iVar15 = *(int *)(iVar7 + 8);
  uVar4 = (uint)(*(int *)(iVar7 + 0x38) != 0);
  iVar9 = piVar16[1];
  iVar10 = piVar16[3] - iVar9;
  iVar13 = piVar16[2] - *piVar16;
  if (bVar1) {
    if (uVar4 == 0) {
      iVar17 = piVar12[1];
      pbVar8 = (byte *)(iVar9 * iVar15 + *(int *)(iVar7 + 4) + *piVar16);
      if (piVar12[3] <= iVar17) {
        return 0;
      }
      pbVar11 = pbVar8 + iVar13;
      do {
        iVar5 = *piVar12;
        for (pbVar14 = pbVar8; pbVar14 < pbVar11; pbVar14 = pbVar14 + 1) {
          pbVar2 = (byte *)FUN_c08947dc(*(int *)(param_2 + 8),iVar5,iVar17);
          *pbVar14 = *pbVar14 ^ *pbVar2;
          iVar5 = iVar5 + 1;
        }
        iVar17 = iVar17 + 1;
        pbVar8 = pbVar8 + iVar15;
        pbVar11 = pbVar11 + iVar15;
      } while (iVar17 < piVar12[3]);
      return 0;
    }
  }
  else if (uVar4 == 0) goto LAB_c08ad3e8;
  if (!bVar1) {
    pbVar8 = (byte *)(piVar12[1] * iVar17 + *(int *)(iVar5 + 4) + *piVar12);
    if (piVar16[3] <= iVar9) {
      return 0;
    }
    pbVar11 = pbVar8 + iVar13;
    do {
      iVar15 = *piVar16;
      for (pbVar14 = pbVar8; pbVar14 < pbVar11; pbVar14 = pbVar14 + 1) {
        pbVar2 = (byte *)FUN_c08947dc(*(int *)(param_2 + 4),iVar15,iVar9);
        iVar15 = iVar15 + 1;
        *pbVar2 = *pbVar2 ^ *pbVar14;
      }
      iVar9 = iVar9 + 1;
      pbVar8 = pbVar8 + iVar17;
      pbVar11 = pbVar11 + iVar17;
    } while (iVar9 < piVar16[3]);
    return 0;
  }
LAB_c08ad3e8:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar7 + 0x38)) {
    uVar3 = uVar4;
    uVar6 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c0894674(iVar5,piVar12);
      FUN_c0894674(*(int *)(param_2 + 4),piVar16);
      iVar10 = piVar16[3] - piVar16[1];
      iVar13 = piVar16[2] - *piVar16;
      uVar3 = *(uint *)(param_2 + 0x34);
      uVar6 = *(uint *)(param_2 + 0x38);
      *(uint *)(param_2 + 0x34) = (uint)(*piVar16 <= *piVar12);
      *(uint *)(param_2 + 0x38) = (uint)(piVar16[1] <= piVar12[1]);
    }
    iVar5 = piVar12[1] * iVar17 + *(int *)(*(int *)(param_2 + 8) + 4) + *piVar12;
    pbVar8 = (byte *)(piVar16[1] * iVar15 + *(int *)(*(int *)(param_2 + 4) + 4) + *piVar16);
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar7 = (iVar10 + -1) * iVar17;
      iVar17 = -iVar17;
      iVar9 = (iVar10 + -1) * iVar15;
      iVar5 = iVar7 + iVar5;
      iVar15 = -iVar15;
      pbVar8 = pbVar8 + iVar9;
    }
    if (0 < iVar10) {
      if (*(int *)(param_2 + 0x34) == 0) {
        pbVar11 = pbVar8 + iVar13 + -1;
        iVar5 = iVar5 + iVar13 + -1;
        do {
          if (pbVar8 <= pbVar11) {
            pbVar14 = pbVar11;
            do {
              *pbVar14 = pbVar14[iVar5 - (int)pbVar11] ^ *pbVar14;
              pbVar14 = pbVar14 + -1;
            } while (pbVar8 <= pbVar14);
          }
          iVar10 = iVar10 + -1;
          iVar5 = iVar5 + iVar17;
          pbVar8 = pbVar8 + iVar15;
          pbVar11 = pbVar11 + iVar15;
        } while (iVar10 != 0);
      }
      else {
        pbVar11 = pbVar8 + iVar13;
        do {
          if (pbVar8 < pbVar11) {
            pbVar14 = pbVar8;
            do {
              *pbVar14 = pbVar14[iVar5 - (int)pbVar8] ^ *pbVar14;
              pbVar14 = pbVar14 + 1;
            } while (pbVar14 < pbVar11);
          }
          iVar10 = iVar10 + -1;
          iVar5 = iVar5 + iVar17;
          pbVar8 = pbVar8 + iVar15;
          pbVar11 = pbVar11 + iVar15;
        } while (iVar10 != 0);
      }
    }
    if ((uVar4 != 0) && (bVar1)) {
      *(uint *)(param_2 + 0x34) = uVar3;
      *(uint *)(param_2 + 0x38) = uVar6;
      FUN_c0894728(*(int *)(param_2 + 8),piVar12);
      FUN_c0894728(*(int *)(param_2 + 4),piVar16);
    }
  }
  else {
    iVar17 = 0;
    if (0 < iVar10) {
      do {
        iVar15 = 0;
        if (0 < iVar13) {
          do {
            pbVar8 = (byte *)FUN_c08947dc(*(int *)(param_2 + 4),*piVar16 + iVar15,
                                          piVar16[1] + iVar17);
            pbVar11 = (byte *)FUN_c08947dc(*(int *)(param_2 + 8),*piVar12 + iVar15,
                                           piVar12[1] + iVar17);
            iVar15 = iVar15 + 1;
            *pbVar8 = *pbVar11 ^ *pbVar8;
          } while (iVar15 < iVar13);
        }
        iVar17 = iVar17 + 1;
      } while (iVar17 < iVar10);
    }
  }
  return 0;
}



/* c08ad698 FUN_c08ad698 */

/* Boundary evidence: original MIPS .pdata c08ad698..c08adaff. Semantic name remains unreviewed. */

undefined4 FUN_c08ad698(undefined4 param_1,int param_2)

{
  bool bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  int *piVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  
  iVar5 = *(int *)(param_2 + 8);
  piVar14 = *(int **)(param_2 + 0x18);
  iVar17 = *(int *)(iVar5 + 8);
  bVar1 = *(int *)(iVar5 + 0x38) != 0;
  iVar7 = *(int *)(param_2 + 4);
  piVar16 = *(int **)(param_2 + 0x14);
  iVar15 = *(int *)(iVar7 + 8);
  uVar4 = (uint)(*(int *)(iVar7 + 0x38) != 0);
  iVar9 = piVar16[1];
  iVar10 = piVar16[3] - iVar9;
  iVar12 = piVar16[2] - *piVar16;
  if (bVar1) {
    if (uVar4 == 0) {
      iVar17 = piVar14[1];
      pbVar8 = (byte *)(iVar9 * iVar15 + *(int *)(iVar7 + 4) + *piVar16);
      if (piVar14[3] <= iVar17) {
        return 0;
      }
      pbVar11 = pbVar8 + iVar12;
      do {
        iVar5 = *piVar14;
        for (pbVar13 = pbVar8; pbVar13 < pbVar11; pbVar13 = pbVar13 + 1) {
          pbVar2 = (byte *)FUN_c08947dc(*(int *)(param_2 + 8),iVar5,iVar17);
          *pbVar13 = *pbVar13 & *pbVar2;
          iVar5 = iVar5 + 1;
        }
        iVar17 = iVar17 + 1;
        pbVar8 = pbVar8 + iVar15;
        pbVar11 = pbVar11 + iVar15;
      } while (iVar17 < piVar14[3]);
      return 0;
    }
  }
  else if (uVar4 == 0) goto LAB_c08ad850;
  if (!bVar1) {
    pbVar8 = (byte *)(piVar14[1] * iVar17 + *(int *)(iVar5 + 4) + *piVar14);
    if (piVar16[3] <= iVar9) {
      return 0;
    }
    pbVar11 = pbVar8 + iVar12;
    do {
      iVar15 = *piVar16;
      for (pbVar13 = pbVar8; pbVar13 < pbVar11; pbVar13 = pbVar13 + 1) {
        pbVar2 = (byte *)FUN_c08947dc(*(int *)(param_2 + 4),iVar15,iVar9);
        iVar15 = iVar15 + 1;
        *pbVar2 = *pbVar2 & *pbVar13;
      }
      iVar9 = iVar9 + 1;
      pbVar8 = pbVar8 + iVar17;
      pbVar11 = pbVar11 + iVar17;
    } while (iVar9 < piVar16[3]);
    return 0;
  }
LAB_c08ad850:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar7 + 0x38)) {
    uVar3 = uVar4;
    uVar6 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c0894674(iVar5,piVar14);
      FUN_c0894674(*(int *)(param_2 + 4),piVar16);
      iVar10 = piVar16[3] - piVar16[1];
      iVar12 = piVar16[2] - *piVar16;
      uVar3 = *(uint *)(param_2 + 0x34);
      uVar6 = *(uint *)(param_2 + 0x38);
      *(uint *)(param_2 + 0x34) = (uint)(*piVar16 <= *piVar14);
      *(uint *)(param_2 + 0x38) = (uint)(piVar16[1] <= piVar14[1]);
    }
    iVar5 = piVar14[1] * iVar17 + *(int *)(*(int *)(param_2 + 8) + 4) + *piVar14;
    pbVar8 = (byte *)(piVar16[1] * iVar15 + *(int *)(*(int *)(param_2 + 4) + 4) + *piVar16);
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar7 = (iVar10 + -1) * iVar17;
      iVar17 = -iVar17;
      iVar9 = (iVar10 + -1) * iVar15;
      iVar5 = iVar7 + iVar5;
      iVar15 = -iVar15;
      pbVar8 = pbVar8 + iVar9;
    }
    if (0 < iVar10) {
      if (*(int *)(param_2 + 0x34) == 0) {
        pbVar11 = pbVar8 + iVar12 + -1;
        iVar5 = iVar5 + iVar12 + -1;
        do {
          if (pbVar8 <= pbVar11) {
            pbVar13 = pbVar11;
            do {
              *pbVar13 = pbVar13[iVar5 - (int)pbVar11] & *pbVar13;
              pbVar13 = pbVar13 + -1;
            } while (pbVar8 <= pbVar13);
          }
          iVar10 = iVar10 + -1;
          iVar5 = iVar5 + iVar17;
          pbVar8 = pbVar8 + iVar15;
          pbVar11 = pbVar11 + iVar15;
        } while (iVar10 != 0);
      }
      else {
        pbVar11 = pbVar8 + iVar12;
        do {
          if (pbVar8 < pbVar11) {
            pbVar13 = pbVar8;
            do {
              *pbVar13 = pbVar13[iVar5 - (int)pbVar8] & *pbVar13;
              pbVar13 = pbVar13 + 1;
            } while (pbVar13 < pbVar11);
          }
          iVar10 = iVar10 + -1;
          iVar5 = iVar5 + iVar17;
          pbVar8 = pbVar8 + iVar15;
          pbVar11 = pbVar11 + iVar15;
        } while (iVar10 != 0);
      }
    }
    if ((uVar4 != 0) && (bVar1)) {
      *(uint *)(param_2 + 0x34) = uVar3;
      *(uint *)(param_2 + 0x38) = uVar6;
      FUN_c0894728(*(int *)(param_2 + 8),piVar14);
      FUN_c0894728(*(int *)(param_2 + 4),piVar16);
    }
  }
  else {
    iVar17 = 0;
    if (0 < iVar10) {
      do {
        iVar15 = 0;
        if (0 < iVar12) {
          do {
            pbVar8 = (byte *)FUN_c08947dc(*(int *)(param_2 + 4),*piVar16 + iVar15,
                                          piVar16[1] + iVar17);
            pbVar11 = (byte *)FUN_c08947dc(*(int *)(param_2 + 8),*piVar14 + iVar15,
                                           piVar14[1] + iVar17);
            iVar15 = iVar15 + 1;
            *pbVar8 = *pbVar11 & *pbVar8;
          } while (iVar15 < iVar12);
        }
        iVar17 = iVar17 + 1;
      } while (iVar17 < iVar10);
    }
  }
  return 0;
}



/* c08adb00 FUN_c08adb00 */

/* Boundary evidence: original MIPS .pdata c08adb00..c08adf9b. Semantic name remains unreviewed. */

undefined4 FUN_c08adb00(undefined4 param_1,int param_2)

{
  bool bVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  
  iVar5 = *(int *)(param_2 + 8);
  piVar12 = *(int **)(param_2 + 0x18);
  uVar15 = *(uint *)(iVar5 + 8) >> 1;
  bVar1 = *(int *)(iVar5 + 0x38) != 0;
  iVar8 = *(int *)(param_2 + 4);
  piVar16 = *(int **)(param_2 + 0x14);
  uVar14 = *(uint *)(iVar8 + 8) >> 1;
  uVar4 = (uint)(*(int *)(iVar8 + 0x38) != 0);
  iVar10 = piVar16[1];
  iVar11 = piVar16[3] - iVar10;
  iVar13 = piVar16[2] - *piVar16;
  if (bVar1) {
    if (uVar4 == 0) {
      iVar5 = piVar12[1];
      puVar9 = (ushort *)((iVar10 * uVar14 + *piVar16) * 2 + *(int *)(iVar8 + 4));
      if (piVar12[3] <= iVar5) {
        return 0;
      }
      do {
        iVar11 = *piVar12;
        for (puVar3 = puVar9; puVar3 < puVar9 + iVar13; puVar3 = puVar3 + 1) {
          puVar2 = (ushort *)FUN_c08947dc(*(int *)(param_2 + 8),iVar11,iVar5);
          *puVar3 = *puVar3 | *puVar2;
          iVar11 = iVar11 + 1;
        }
        iVar5 = iVar5 + 1;
        puVar9 = puVar9 + uVar14;
      } while (iVar5 < piVar12[3]);
      return 0;
    }
  }
  else if (uVar4 == 0) goto LAB_c08adcd0;
  if (!bVar1) {
    puVar9 = (ushort *)((piVar12[1] * uVar15 + *piVar12) * 2 + *(int *)(iVar5 + 4));
    if (piVar16[3] <= iVar10) {
      return 0;
    }
    do {
      iVar5 = *piVar16;
      for (puVar3 = puVar9; puVar3 < puVar9 + iVar13; puVar3 = puVar3 + 1) {
        puVar2 = (ushort *)FUN_c08947dc(*(int *)(param_2 + 4),iVar5,iVar10);
        iVar5 = iVar5 + 1;
        *puVar2 = *puVar2 | *puVar3;
      }
      iVar10 = iVar10 + 1;
      puVar9 = puVar9 + uVar15;
    } while (iVar10 < piVar16[3]);
    return 0;
  }
LAB_c08adcd0:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar8 + 0x38)) {
    uVar6 = uVar4;
    uVar7 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c0894674(iVar5,piVar12);
      FUN_c0894674(*(int *)(param_2 + 4),piVar16);
      iVar11 = piVar16[3] - piVar16[1];
      iVar13 = piVar16[2] - *piVar16;
      uVar7 = *(uint *)(param_2 + 0x34);
      uVar6 = *(uint *)(param_2 + 0x38);
      *(uint *)(param_2 + 0x34) = (uint)(*piVar16 <= *piVar12);
      *(uint *)(param_2 + 0x38) = (uint)(piVar16[1] <= piVar12[1]);
    }
    iVar5 = (piVar12[1] * uVar15 + *piVar12) * 2 + *(int *)(*(int *)(param_2 + 8) + 4);
    puVar9 = (ushort *)((piVar16[1] * uVar14 + *piVar16) * 2 + *(int *)(*(int *)(param_2 + 4) + 4));
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar8 = (iVar11 + -1) * uVar15;
      uVar15 = -uVar15;
      iVar10 = (iVar11 + -1) * uVar14;
      iVar5 = iVar8 * 2 + iVar5;
      uVar14 = -uVar14;
      puVar9 = puVar9 + iVar10;
    }
    if (0 < iVar11) {
      if (*(int *)(param_2 + 0x34) == 0) {
        do {
          puVar3 = puVar9 + iVar13 + -1;
          if (puVar9 <= puVar3) {
            iVar8 = (iVar13 * 2 + -2) - (int)puVar3;
            do {
              *puVar3 = *(ushort *)(iVar8 + iVar5 + (int)puVar3) | *puVar3;
              puVar3 = puVar3 + -1;
            } while (puVar9 <= puVar3);
          }
          iVar11 = iVar11 + -1;
          iVar5 = uVar15 * 2 + iVar5;
          puVar9 = puVar9 + uVar14;
        } while (iVar11 != 0);
      }
      else {
        do {
          if (puVar9 < puVar9 + iVar13) {
            puVar3 = puVar9;
            do {
              *puVar3 = *(ushort *)((iVar5 - (int)puVar9) + (int)puVar3) | *puVar3;
              puVar3 = puVar3 + 1;
            } while (puVar3 < puVar9 + iVar13);
          }
          iVar11 = iVar11 + -1;
          iVar5 = uVar15 * 2 + iVar5;
          puVar9 = puVar9 + uVar14;
        } while (iVar11 != 0);
      }
    }
    if ((uVar4 != 0) && (bVar1)) {
      *(uint *)(param_2 + 0x38) = uVar6;
      *(uint *)(param_2 + 0x34) = uVar7;
      FUN_c0894728(*(int *)(param_2 + 8),piVar12);
      FUN_c0894728(*(int *)(param_2 + 4),piVar16);
    }
  }
  else {
    iVar5 = 0;
    if (0 < iVar11) {
      do {
        iVar8 = 0;
        if (0 < iVar13) {
          do {
            puVar9 = (ushort *)
                     FUN_c08947dc(*(int *)(param_2 + 4),*piVar16 + iVar8,piVar16[1] + iVar5);
            puVar3 = (ushort *)
                     FUN_c08947dc(*(int *)(param_2 + 8),*piVar12 + iVar8,piVar12[1] + iVar5);
            iVar8 = iVar8 + 1;
            *puVar9 = *puVar3 | *puVar9;
          } while (iVar8 < iVar13);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar11);
    }
  }
  return 0;
}



/* c08adf9c FUN_c08adf9c */

/* Boundary evidence: original MIPS .pdata c08adf9c..c08ae5bf. Semantic name remains unreviewed. */

undefined4 FUN_c08adf9c(undefined4 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  byte *pbVar18;
  undefined2 *puVar19;
  byte *local_4c;
  int local_3c;
  
  iVar7 = *(int *)(param_2 + 4);
  iVar2 = *(int *)(*(int *)(param_2 + 8) + 8);
  piVar17 = *(int **)(param_2 + 0x14);
  uVar11 = *(uint *)(iVar7 + 8) >> 1;
  iVar5 = *(int *)(iVar7 + 0x38);
  iVar9 = **(int **)(param_2 + 0x18);
  uVar12 = -iVar9 & 7;
  uVar8 = (piVar17[2] - *piVar17) - uVar12;
  iVar4 = (int)uVar8 >> 3;
  uVar8 = uVar8 & 7;
  iVar16 = 0;
  iVar13 = 0;
  local_4c = (byte *)((*(int **)(param_2 + 0x18))[1] * iVar2 + (iVar9 >> 3) +
                     *(int *)(*(int *)(param_2 + 8) + 4));
  puVar19 = (undefined2 *)((piVar17[1] * uVar11 + *piVar17) * 2 + *(int *)(iVar7 + 4));
  do {
    piVar14 = (int *)((int)&DAT_c08c06f4 + iVar13);
    *piVar14 = iVar16;
    if (*(int *)(param_2 + 0x3c) != 0) {
      *piVar14 = *(int *)(*(int *)(param_2 + 0x3c) + iVar13);
    }
    if (*(code **)(param_2 + 0x40) != (code *)0x0) {
      iVar7 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),*piVar14);
      *piVar14 = iVar7;
    }
    iVar13 = iVar13 + 4;
    iVar16 = iVar16 + 1;
  } while (iVar13 < 8);
  iVar7 = piVar17[1];
  if (iVar7 < piVar17[3]) {
    pbVar10 = local_4c + 1;
    do {
      if (iVar5 == 0) {
        bVar1 = *local_4c;
        puVar3 = puVar19;
        if (uVar12 == 1) {
LAB_c08ae218:
          *puVar3 = (short)(&DAT_c08c06f4)[bVar1 & 1];
          puVar3 = puVar3 + 1;
          pbVar18 = pbVar10;
        }
        else {
          if (uVar12 == 2) {
LAB_c08ae1fc:
            *puVar3 = (short)(&DAT_c08c06f4)[bVar1 >> 1 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08ae218;
          }
          if (uVar12 == 3) {
LAB_c08ae1e0:
            *puVar3 = (short)(&DAT_c08c06f4)[bVar1 >> 2 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08ae1fc;
          }
          if (uVar12 == 4) {
LAB_c08ae1c4:
            *puVar3 = (short)(&DAT_c08c06f4)[bVar1 >> 3 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08ae1e0;
          }
          if (uVar12 == 5) {
LAB_c08ae1a8:
            *puVar3 = (short)(&DAT_c08c06f4)[bVar1 >> 4 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08ae1c4;
          }
          if (uVar12 == 6) {
LAB_c08ae18c:
            *puVar3 = (short)(&DAT_c08c06f4)[bVar1 >> 5 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08ae1a8;
          }
          pbVar18 = local_4c;
          if (uVar12 == 7) {
            puVar3 = puVar19 + 1;
            *puVar19 = (short)(&DAT_c08c06f4)[bVar1 >> 6 & 1];
            goto LAB_c08ae18c;
          }
        }
        iVar9 = iVar4;
        if (0 < iVar4) {
          do {
            uVar6 = (uint)*pbVar18;
            puVar3[7] = (short)(&DAT_c08c06f4)[uVar6 & 1];
            puVar3[6] = (short)(&DAT_c08c06f4)[(int)uVar6 >> 1 & 1];
            puVar3[5] = (short)(&DAT_c08c06f4)[(int)uVar6 >> 2 & 1];
            puVar3[4] = (short)(&DAT_c08c06f4)[(int)uVar6 >> 3 & 1];
            puVar3[3] = (short)(&DAT_c08c06f4)[(int)uVar6 >> 4 & 1];
            puVar3[2] = (short)(&DAT_c08c06f4)[(int)uVar6 >> 5 & 1];
            pbVar18 = pbVar18 + 1;
            puVar3[1] = (short)(&DAT_c08c06f4)[(int)uVar6 >> 6 & 1];
            iVar9 = iVar9 + -1;
            *puVar3 = (short)(&DAT_c08c06f4)[(int)uVar6 >> 7];
            puVar3 = puVar3 + 8;
          } while (iVar9 != 0);
        }
        bVar1 = *pbVar18;
        if (uVar8 == 1) {
LAB_c08ae3dc:
          *puVar3 = (short)(&DAT_c08c06f4)[bVar1 >> 7];
        }
        else {
          if (uVar8 == 2) {
LAB_c08ae3c4:
            puVar3[1] = (short)(&DAT_c08c06f4)[bVar1 >> 6 & 1];
            goto LAB_c08ae3dc;
          }
          if (uVar8 == 3) {
LAB_c08ae3ac:
            puVar3[2] = (short)(&DAT_c08c06f4)[bVar1 >> 5 & 1];
            goto LAB_c08ae3c4;
          }
          if (uVar8 == 4) {
LAB_c08ae394:
            puVar3[3] = (short)(&DAT_c08c06f4)[bVar1 >> 4 & 1];
            goto LAB_c08ae3ac;
          }
          if (uVar8 == 5) {
LAB_c08ae37c:
            puVar3[4] = (short)(&DAT_c08c06f4)[bVar1 >> 3 & 1];
            goto LAB_c08ae394;
          }
          if (uVar8 == 6) {
LAB_c08ae364:
            puVar3[5] = (short)(&DAT_c08c06f4)[bVar1 >> 2 & 1];
            goto LAB_c08ae37c;
          }
          if (uVar8 == 7) {
            puVar3[6] = (short)(&DAT_c08c06f4)[bVar1 >> 1 & 1];
            goto LAB_c08ae364;
          }
        }
        puVar19 = puVar19 + uVar11;
      }
      else {
        bVar1 = *local_4c;
        iVar9 = *piVar17;
        uVar15 = uVar12;
        for (uVar6 = uVar12; uVar6 != 0; uVar6 = uVar6 - 1) {
          uVar15 = uVar15 - 1;
          puVar3 = (undefined2 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar9,iVar7);
          *puVar3 = (short)(&DAT_c08c06f4)[bVar1 >> (uVar15 & 0x1f) & 1];
          iVar9 = iVar9 + 1;
        }
        pbVar18 = pbVar10;
        local_3c = iVar4;
        if (0 < iVar4) {
          do {
            bVar1 = *pbVar18;
            iVar13 = 0x7ffffff9;
            do {
              puVar3 = (undefined2 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar9,iVar7);
              *puVar3 = (short)(&DAT_c08c06f4)[bVar1 & 1];
              bVar1 = 1 < bVar1;
              iVar13 = iVar13 + -1;
              iVar9 = iVar9 + 1;
            } while (iVar13 != 0);
            local_3c = local_3c + -1;
            pbVar18 = pbVar18 + 1;
          } while (local_3c != 0);
        }
        bVar1 = *pbVar18;
        uVar6 = 0;
        if (uVar8 != 0) {
          do {
            puVar3 = (undefined2 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar9,iVar7);
            uVar15 = uVar6 & 0x1f;
            uVar6 = uVar6 + 1;
            *puVar3 = (short)(&DAT_c08c06f4)[bVar1 >> uVar15 & 1];
            iVar9 = iVar9 + 1;
          } while ((int)uVar6 < (int)uVar8);
        }
      }
      local_4c = local_4c + iVar2;
      pbVar10 = pbVar10 + iVar2;
      puVar19 = puVar19 + uVar11;
      iVar7 = iVar7 + 1;
    } while (iVar7 < piVar17[3]);
  }
  return 0;
}



/* c08ae5c0 FUN_c08ae5c0 */

/* Boundary evidence: original MIPS .pdata c08ae5c0..c08ae7e3. Semantic name remains unreviewed. */

undefined4 FUN_c08ae5c0(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined2 *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  undefined2 *local_78;
  byte *local_74;
  int local_68 [16];
  
  iVar4 = *(int *)(param_2 + 4);
  iVar5 = *(int *)(*(int *)(param_2 + 8) + 8);
  puVar3 = *(uint **)(param_2 + 0x18);
  uVar11 = *(uint *)(iVar4 + 8) >> 1;
  piVar10 = *(int **)(param_2 + 0x14);
  bVar1 = *(int *)(iVar4 + 0x38) != 0;
  iVar9 = 0;
  iVar8 = 0;
  local_74 = (byte *)(puVar3[1] * iVar5 + ((int)*puVar3 >> 1) + *(int *)(*(int *)(param_2 + 8) + 4))
  ;
  local_78 = (undefined2 *)((piVar10[1] * uVar11 + *piVar10) * 2 + *(int *)(iVar4 + 4));
  do {
    piVar6 = (int *)((int)local_68 + iVar8);
    iVar4 = *(int *)(param_2 + 0x3c);
    *piVar6 = iVar9;
    if (iVar4 != 0) {
      *piVar6 = *(int *)(iVar8 + iVar4);
    }
    if (*(code **)(param_2 + 0x40) != (code *)0x0) {
      iVar4 = (**(code **)(param_2 + 0x40))(*(undefined4 *)(param_2 + 0x44),*piVar6);
      *piVar6 = iVar4;
    }
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + 1;
  } while (iVar8 < 0x40);
  iVar4 = piVar10[1];
  if (iVar4 < piVar10[3]) {
    do {
      iVar8 = *piVar10;
      uVar7 = *puVar3 & 1;
      puVar2 = local_78;
      pbVar12 = local_74;
      if (iVar8 < piVar10[2]) {
        do {
          if (uVar7 == 0) {
            uVar13 = (uint)(*pbVar12 >> 4);
          }
          else {
            uVar13 = *pbVar12 & 0xf;
            pbVar12 = pbVar12 + 1;
          }
          uVar7 = (uint)(uVar7 == 0);
          if (bVar1) {
            puVar2 = (undefined2 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar8,iVar4);
          }
          *puVar2 = (short)local_68[uVar13];
          if (!bVar1) {
            puVar2 = puVar2 + 1;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < piVar10[2]);
      }
      local_74 = local_74 + iVar5;
      local_78 = local_78 + uVar11;
      iVar4 = iVar4 + 1;
    } while (iVar4 < piVar10[3]);
  }
  return 0;
}



/* c08ae7e4 FUN_c08ae7e4 */

/* Boundary evidence: original MIPS .pdata c08ae7e4..c08aec07. Semantic name remains unreviewed. */

undefined4 FUN_c08ae7e4(undefined4 param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined2 *puVar8;
  void *_Src;
  int iVar9;
  void *_Dst;
  int *piVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int *local_40;
  int *local_3c;
  
  iVar5 = *(int *)(param_2 + 8);
  piVar10 = *(int **)(param_2 + 0x18);
  uVar13 = *(uint *)(iVar5 + 8) >> 1;
  bVar1 = *(int *)(iVar5 + 0x38) == 0;
  iVar6 = *(int *)(param_2 + 4);
  piVar11 = *(int **)(param_2 + 0x14);
  uVar7 = *(uint *)(iVar6 + 8) >> 1;
  bVar2 = *(int *)(iVar6 + 0x38) == 0;
  iVar9 = piVar11[1];
  iVar12 = piVar11[3] - iVar9;
  iVar14 = piVar11[2] - *piVar11;
  if (bVar1) {
    if (bVar2) goto LAB_c08ae9ac;
  }
  else if (bVar2) {
    iVar5 = piVar10[1];
    puVar8 = (undefined2 *)((iVar9 * uVar7 + *piVar11) * 2 + *(int *)(iVar6 + 4));
    if (piVar10[3] <= iVar5) {
      return 0;
    }
    do {
      iVar12 = *piVar10;
      for (puVar4 = puVar8; puVar4 < puVar8 + iVar14; puVar4 = puVar4 + 1) {
        puVar3 = (undefined2 *)FUN_c08947dc(*(int *)(param_2 + 8),iVar12,iVar5);
        *puVar4 = *puVar3;
        iVar12 = iVar12 + 1;
      }
      iVar5 = iVar5 + 1;
      puVar8 = puVar8 + uVar7;
    } while (iVar5 < piVar10[3]);
    return 0;
  }
  if (bVar1) {
    puVar8 = (undefined2 *)((piVar10[1] * uVar13 + *piVar10) * 2 + *(int *)(iVar5 + 4));
    if (piVar11[3] <= iVar9) {
      return 0;
    }
    do {
      iVar5 = *piVar11;
      for (puVar4 = puVar8; puVar4 < puVar8 + iVar14; puVar4 = puVar4 + 1) {
        puVar3 = (undefined2 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar5,iVar9);
        iVar5 = iVar5 + 1;
        *puVar3 = *puVar4;
      }
      iVar9 = iVar9 + 1;
      puVar8 = puVar8 + uVar13;
    } while (iVar9 < piVar11[3]);
    return 0;
  }
LAB_c08ae9ac:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar6 + 0x38)) {
    local_40 = piVar11;
    local_3c = piVar11;
    if ((!bVar2) && (!bVar1)) {
      FUN_c0894674(iVar5,piVar10);
      FUN_c0894674(*(int *)(param_2 + 4),piVar11);
      local_40 = *(int **)(param_2 + 0x34);
      iVar12 = piVar11[3] - piVar11[1];
      local_3c = *(int **)(param_2 + 0x38);
      iVar14 = piVar11[2] - *piVar11;
      *(uint *)(param_2 + 0x34) = (uint)(*piVar11 <= *piVar10);
      *(uint *)(param_2 + 0x38) = (uint)(piVar11[1] <= piVar10[1]);
    }
    _Src = (void *)((piVar10[1] * uVar13 + *piVar10) * 2 + *(int *)(*(int *)(param_2 + 8) + 4));
    _Dst = (void *)((piVar11[1] * uVar7 + *piVar11) * 2 + *(int *)(*(int *)(param_2 + 4) + 4));
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar5 = (iVar12 + -1) * uVar13;
      uVar13 = -uVar13;
      iVar6 = (iVar12 + -1) * uVar7;
      _Src = (void *)(iVar5 * 2 + (int)_Src);
      uVar7 = -uVar7;
      _Dst = (void *)(iVar6 * 2 + (int)_Dst);
    }
    if (0 < iVar12) {
      do {
        memmove(_Dst,_Src,iVar14 << 1);
        iVar12 = iVar12 + -1;
        _Src = (void *)(uVar13 * 2 + (int)_Src);
        _Dst = (void *)(uVar7 * 2 + (int)_Dst);
      } while (iVar12 != 0);
    }
    if ((!bVar2) && (!bVar1)) {
      *(int **)(param_2 + 0x34) = local_40;
      *(int **)(param_2 + 0x38) = local_3c;
      FUN_c0894728(*(int *)(param_2 + 8),piVar10);
      FUN_c0894728(*(int *)(param_2 + 4),piVar11);
    }
  }
  else {
    iVar5 = 0;
    if (0 < iVar12) {
      do {
        iVar6 = 0;
        if (0 < iVar14) {
          do {
            puVar8 = (undefined2 *)
                     FUN_c08947dc(*(int *)(param_2 + 4),*piVar11 + iVar6,piVar11[1] + iVar5);
            puVar4 = (undefined2 *)
                     FUN_c08947dc(*(int *)(param_2 + 8),*piVar10 + iVar6,piVar10[1] + iVar5);
            iVar6 = iVar6 + 1;
            *puVar8 = *puVar4;
          } while (iVar6 < iVar14);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar12);
    }
  }
  return 0;
}



/* c08aec08 FUN_c08aec08 */

/* Boundary evidence: original MIPS .pdata c08aec08..c08aed1b. Semantic name remains unreviewed. */

undefined4 FUN_c08aec08(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  
  iVar1 = *(int *)(param_2 + 4);
  uVar7 = *(uint *)(iVar1 + 8);
  iVar8 = *(int *)(iVar1 + 4);
  piVar6 = *(int **)(param_2 + 0x14);
  uVar9 = *(undefined4 *)(param_2 + 0x20);
  if (*(int *)(iVar1 + 0x38) != 0) {
    FUN_c0894674(*(int *)(param_2 + 4),piVar6);
  }
  iVar3 = *piVar6;
  iVar1 = piVar6[3] - piVar6[1];
  iVar2 = piVar6[2];
  puVar5 = (undefined2 *)(piVar6[1] * uVar7 + iVar3 * 2 + iVar8);
  if (0 < iVar1) {
    do {
      if ((puVar5 < puVar5 + (iVar2 - iVar3)) &&
         (iVar8 = ((uint)((int)(puVar5 + (iVar2 - iVar3)) + (-1 - (int)puVar5)) >> 1) + 1,
         iVar8 != 0)) {
        puVar4 = puVar5;
        do {
          *puVar4 = (short)uVar9;
          puVar4 = puVar4 + 1;
        } while (puVar4 != puVar5 + iVar8);
      }
      iVar1 = iVar1 + -1;
      puVar5 = (undefined2 *)((uVar7 & 0xfffffffe) + (int)puVar5);
    } while (iVar1 != 0);
  }
  if (*(int *)(*(int *)(param_2 + 4) + 0x38) != 0) {
    FUN_c0894728(*(int *)(param_2 + 4),piVar6);
  }
  return 0;
}



/* c08aed1c FUN_c08aed1c */

/* Boundary evidence: original MIPS .pdata c08aed1c..c08af1ab. Semantic name remains unreviewed. */

undefined4 FUN_c08aed1c(undefined4 param_1,int param_2)

{
  bool bVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  
  iVar5 = *(int *)(param_2 + 8);
  piVar12 = *(int **)(param_2 + 0x18);
  uVar14 = *(uint *)(iVar5 + 8) >> 1;
  bVar1 = *(int *)(iVar5 + 0x38) != 0;
  iVar8 = *(int *)(param_2 + 4);
  piVar16 = *(int **)(param_2 + 0x14);
  uVar13 = *(uint *)(iVar8 + 8) >> 1;
  uVar4 = (uint)(*(int *)(iVar8 + 0x38) != 0);
  iVar10 = piVar16[1];
  iVar11 = piVar16[3] - iVar10;
  iVar15 = piVar16[2] - *piVar16;
  if (bVar1) {
    if (uVar4 == 0) {
      iVar5 = piVar12[1];
      puVar9 = (ushort *)((iVar10 * uVar13 + *piVar16) * 2 + *(int *)(iVar8 + 4));
      if (piVar12[3] <= iVar5) {
        return 0;
      }
      do {
        iVar11 = *piVar12;
        for (puVar3 = puVar9; puVar3 < puVar9 + iVar15; puVar3 = puVar3 + 1) {
          puVar2 = (ushort *)FUN_c08947dc(*(int *)(param_2 + 8),iVar11,iVar5);
          *puVar3 = *puVar3 ^ *puVar2;
          iVar11 = iVar11 + 1;
        }
        iVar5 = iVar5 + 1;
        puVar9 = puVar9 + uVar13;
      } while (iVar5 < piVar12[3]);
      return 0;
    }
  }
  else if (uVar4 == 0) goto LAB_c08aeeec;
  if (!bVar1) {
    puVar9 = (ushort *)((piVar12[1] * uVar14 + *piVar12) * 2 + *(int *)(iVar5 + 4));
    if (piVar16[3] <= iVar10) {
      return 0;
    }
    do {
      iVar5 = *piVar16;
      for (puVar3 = puVar9; puVar3 < puVar9 + iVar15; puVar3 = puVar3 + 1) {
        puVar2 = (ushort *)FUN_c08947dc(*(int *)(param_2 + 4),iVar5,iVar10);
        iVar5 = iVar5 + 1;
        *puVar2 = *puVar2 ^ *puVar3;
      }
      iVar10 = iVar10 + 1;
      puVar9 = puVar9 + uVar14;
    } while (iVar10 < piVar16[3]);
    return 0;
  }
LAB_c08aeeec:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar8 + 0x38)) {
    uVar6 = uVar4;
    uVar7 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c0894674(iVar5,piVar12);
      FUN_c0894674(*(int *)(param_2 + 4),piVar16);
      iVar11 = piVar16[3] - piVar16[1];
      iVar15 = piVar16[2] - *piVar16;
      uVar7 = *(uint *)(param_2 + 0x34);
      uVar6 = *(uint *)(param_2 + 0x38);
      *(uint *)(param_2 + 0x34) = (uint)(*piVar16 <= *piVar12);
      *(uint *)(param_2 + 0x38) = (uint)(piVar16[1] <= piVar12[1]);
    }
    iVar5 = (piVar12[1] * uVar14 + *piVar12) * 2 + *(int *)(*(int *)(param_2 + 8) + 4);
    puVar9 = (ushort *)((piVar16[1] * uVar13 + *piVar16) * 2 + *(int *)(*(int *)(param_2 + 4) + 4));
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar8 = (iVar11 + -1) * uVar14;
      uVar14 = -uVar14;
      iVar10 = (iVar11 + -1) * uVar13;
      iVar5 = iVar8 * 2 + iVar5;
      uVar13 = -uVar13;
      puVar9 = puVar9 + iVar10;
    }
    if (0 < iVar11) {
      if (*(int *)(param_2 + 0x34) == 0) {
        do {
          puVar3 = puVar9 + iVar15 + -1;
          if (puVar9 <= puVar3) {
            iVar8 = (iVar15 * 2 + -2) - (int)puVar3;
            do {
              *puVar3 = *(ushort *)(iVar8 + iVar5 + (int)puVar3) ^ *puVar3;
              puVar3 = puVar3 + -1;
            } while (puVar9 <= puVar3);
          }
          iVar11 = iVar11 + -1;
          iVar5 = uVar14 * 2 + iVar5;
          puVar9 = puVar9 + uVar13;
        } while (iVar11 != 0);
      }
      else {
        do {
          if (puVar9 < puVar9 + iVar15) {
            puVar3 = puVar9;
            do {
              *puVar3 = *(ushort *)((iVar5 - (int)puVar9) + (int)puVar3) ^ *puVar3;
              puVar3 = puVar3 + 1;
            } while (puVar3 < puVar9 + iVar15);
          }
          iVar11 = iVar11 + -1;
          iVar5 = uVar14 * 2 + iVar5;
          puVar9 = puVar9 + uVar13;
        } while (iVar11 != 0);
      }
    }
    if ((uVar4 != 0) && (bVar1)) {
      *(uint *)(param_2 + 0x38) = uVar6;
      *(uint *)(param_2 + 0x34) = uVar7;
      FUN_c0894728(*(int *)(param_2 + 8),piVar12);
      FUN_c0894728(*(int *)(param_2 + 4),piVar16);
    }
  }
  else {
    iVar5 = 0;
    if (0 < iVar11) {
      do {
        iVar8 = 0;
        if (0 < iVar15) {
          do {
            puVar9 = (ushort *)
                     FUN_c08947dc(*(int *)(param_2 + 4),*piVar16 + iVar8,piVar16[1] + iVar5);
            puVar3 = (ushort *)
                     FUN_c08947dc(*(int *)(param_2 + 8),*piVar12 + iVar8,piVar12[1] + iVar5);
            iVar8 = iVar8 + 1;
            *puVar9 = *puVar3 ^ *puVar9;
          } while (iVar8 < iVar15);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar11);
    }
  }
  return 0;
}



/* c08af1ac FUN_c08af1ac */

/* Boundary evidence: original MIPS .pdata c08af1ac..c08af647. Semantic name remains unreviewed. */

undefined4 FUN_c08af1ac(undefined4 param_1,int param_2)

{
  bool bVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  
  iVar5 = *(int *)(param_2 + 8);
  piVar12 = *(int **)(param_2 + 0x18);
  uVar15 = *(uint *)(iVar5 + 8) >> 1;
  bVar1 = *(int *)(iVar5 + 0x38) != 0;
  iVar8 = *(int *)(param_2 + 4);
  piVar16 = *(int **)(param_2 + 0x14);
  uVar14 = *(uint *)(iVar8 + 8) >> 1;
  uVar4 = (uint)(*(int *)(iVar8 + 0x38) != 0);
  iVar10 = piVar16[1];
  iVar11 = piVar16[3] - iVar10;
  iVar13 = piVar16[2] - *piVar16;
  if (bVar1) {
    if (uVar4 == 0) {
      iVar5 = piVar12[1];
      puVar9 = (ushort *)((iVar10 * uVar14 + *piVar16) * 2 + *(int *)(iVar8 + 4));
      if (piVar12[3] <= iVar5) {
        return 0;
      }
      do {
        iVar11 = *piVar12;
        for (puVar3 = puVar9; puVar3 < puVar9 + iVar13; puVar3 = puVar3 + 1) {
          puVar2 = (ushort *)FUN_c08947dc(*(int *)(param_2 + 8),iVar11,iVar5);
          *puVar3 = *puVar3 & *puVar2;
          iVar11 = iVar11 + 1;
        }
        iVar5 = iVar5 + 1;
        puVar9 = puVar9 + uVar14;
      } while (iVar5 < piVar12[3]);
      return 0;
    }
  }
  else if (uVar4 == 0) goto LAB_c08af37c;
  if (!bVar1) {
    puVar9 = (ushort *)((piVar12[1] * uVar15 + *piVar12) * 2 + *(int *)(iVar5 + 4));
    if (piVar16[3] <= iVar10) {
      return 0;
    }
    do {
      iVar5 = *piVar16;
      for (puVar3 = puVar9; puVar3 < puVar9 + iVar13; puVar3 = puVar3 + 1) {
        puVar2 = (ushort *)FUN_c08947dc(*(int *)(param_2 + 4),iVar5,iVar10);
        iVar5 = iVar5 + 1;
        *puVar2 = *puVar2 & *puVar3;
      }
      iVar10 = iVar10 + 1;
      puVar9 = puVar9 + uVar15;
    } while (iVar10 < piVar16[3]);
    return 0;
  }
LAB_c08af37c:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar8 + 0x38)) {
    uVar6 = uVar4;
    uVar7 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c0894674(iVar5,piVar12);
      FUN_c0894674(*(int *)(param_2 + 4),piVar16);
      iVar11 = piVar16[3] - piVar16[1];
      iVar13 = piVar16[2] - *piVar16;
      uVar7 = *(uint *)(param_2 + 0x34);
      uVar6 = *(uint *)(param_2 + 0x38);
      *(uint *)(param_2 + 0x34) = (uint)(*piVar16 <= *piVar12);
      *(uint *)(param_2 + 0x38) = (uint)(piVar16[1] <= piVar12[1]);
    }
    iVar5 = (piVar12[1] * uVar15 + *piVar12) * 2 + *(int *)(*(int *)(param_2 + 8) + 4);
    puVar9 = (ushort *)((piVar16[1] * uVar14 + *piVar16) * 2 + *(int *)(*(int *)(param_2 + 4) + 4));
    if (*(int *)(param_2 + 0x38) == 0) {
      iVar8 = (iVar11 + -1) * uVar15;
      uVar15 = -uVar15;
      iVar10 = (iVar11 + -1) * uVar14;
      iVar5 = iVar8 * 2 + iVar5;
      uVar14 = -uVar14;
      puVar9 = puVar9 + iVar10;
    }
    if (0 < iVar11) {
      if (*(int *)(param_2 + 0x34) == 0) {
        do {
          puVar3 = puVar9 + iVar13 + -1;
          if (puVar9 <= puVar3) {
            iVar8 = (iVar13 * 2 + -2) - (int)puVar3;
            do {
              *puVar3 = *(ushort *)(iVar8 + iVar5 + (int)puVar3) & *puVar3;
              puVar3 = puVar3 + -1;
            } while (puVar9 <= puVar3);
          }
          iVar11 = iVar11 + -1;
          iVar5 = uVar15 * 2 + iVar5;
          puVar9 = puVar9 + uVar14;
        } while (iVar11 != 0);
      }
      else {
        do {
          if (puVar9 < puVar9 + iVar13) {
            puVar3 = puVar9;
            do {
              *puVar3 = *(ushort *)((iVar5 - (int)puVar9) + (int)puVar3) & *puVar3;
              puVar3 = puVar3 + 1;
            } while (puVar3 < puVar9 + iVar13);
          }
          iVar11 = iVar11 + -1;
          iVar5 = uVar15 * 2 + iVar5;
          puVar9 = puVar9 + uVar14;
        } while (iVar11 != 0);
      }
    }
    if ((uVar4 != 0) && (bVar1)) {
      *(uint *)(param_2 + 0x38) = uVar6;
      *(uint *)(param_2 + 0x34) = uVar7;
      FUN_c0894728(*(int *)(param_2 + 8),piVar12);
      FUN_c0894728(*(int *)(param_2 + 4),piVar16);
    }
  }
  else {
    iVar5 = 0;
    if (0 < iVar11) {
      do {
        iVar8 = 0;
        if (0 < iVar13) {
          do {
            puVar9 = (ushort *)
                     FUN_c08947dc(*(int *)(param_2 + 4),*piVar16 + iVar8,piVar16[1] + iVar5);
            puVar3 = (ushort *)
                     FUN_c08947dc(*(int *)(param_2 + 8),*piVar12 + iVar8,piVar12[1] + iVar5);
            iVar8 = iVar8 + 1;
            *puVar9 = *puVar3 & *puVar9;
          } while (iVar8 < iVar13);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar11);
    }
  }
  return 0;
}



/* c08af648 FUN_c08af648 */

/* Boundary evidence: original MIPS .pdata c08af648..c08af66b. Semantic name remains unreviewed. */

void FUN_c08af648(double param_1,double param_2,undefined4 param_3,undefined4 *param_4)

{
  *param_4 = FUN_c089e918;
  FUN_c089e918(param_1,param_2,param_3,(int)param_4);
  return;
}



/* c08af66c FUN_c08af66c */

/* Boundary evidence: original MIPS .pdata c08af66c..c08af833. Semantic name remains unreviewed. */

undefined4 FUN_c08af66c(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  byte *pbVar12;
  int iVar13;
  byte *pbVar14;
  
  iVar5 = *(int *)(param_2 + 4);
  iVar9 = *(int *)(*(int *)(param_2 + 0xc) + 8);
  iVar8 = *(int *)(iVar5 + 8);
  uVar3 = *(undefined4 *)(param_2 + 0x20);
  piVar11 = *(int **)(param_2 + 0x14);
  bVar1 = *(int *)(iVar5 + 0x38) != 0;
  iVar13 = piVar11[1];
  uVar7 = **(uint **)(param_2 + 0x2c);
  pbVar14 = (byte *)((*(uint **)(param_2 + 0x2c))[1] * iVar9 + ((int)uVar7 >> 3) +
                    *(int *)(*(int *)(param_2 + 0xc) + 4));
  puVar6 = (undefined2 *)(iVar13 * iVar8 + *piVar11 * 2 + *(int *)(iVar5 + 4));
  if (iVar13 < piVar11[3]) {
    do {
      uVar4 = (uint)*pbVar14;
      iVar5 = *piVar11;
      pbVar12 = pbVar14 + 1;
      puVar2 = puVar6;
      uVar10 = 0x80 >> (uVar7 & 7);
      if (iVar5 < piVar11[2]) {
        do {
          if (uVar10 == 0) {
            uVar4 = (uint)*pbVar12;
            uVar10 = 0x80;
            pbVar12 = pbVar12 + 1;
          }
          if ((uVar10 & uVar4) != 0) {
            if (bVar1) {
              puVar2 = (undefined2 *)FUN_c08947dc(*(int *)(param_2 + 4),iVar5,iVar13);
            }
            *puVar2 = (short)uVar3;
          }
          if (!bVar1) {
            puVar2 = puVar2 + 1;
          }
          iVar5 = iVar5 + 1;
          uVar10 = uVar10 >> 1;
        } while (iVar5 < piVar11[2]);
      }
      pbVar14 = pbVar14 + iVar9;
      puVar6 = (undefined2 *)((int)puVar6 + iVar8);
      iVar13 = iVar13 + 1;
    } while (iVar13 < piVar11[3]);
  }
  return 0;
}



/* c08af8b4 FUN_c08af8b4 */

/* Boundary evidence: original MIPS .pdata c08af8b4..c08af9ef. Semantic name remains unreviewed. */

int FUN_c08af8b4(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c08c070c != (code *)0x0) {
      iVar2 = (*DAT_c08c070c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c08af964;
    FUN_c08afc0c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0891cb8(param_1,param_2);
  }
LAB_c08af964:
  if (((param_2 == 0) && (FUN_c08afb94(), iVar1 != 0)) && (DAT_c08c070c != (code *)0x0)) {
    iVar1 = (*DAT_c08c070c)(param_1,0,param_3);
  }
  return iVar1;
}



/* c08af9f0 FUN_c08af9f0 */

/* Boundary evidence: original MIPS .pdata c08af9f0..c08afa1b. Semantic name remains unreviewed. */

void FUN_c08af9f0(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c08afa1c entry */

/* Boundary evidence: original MIPS .pdata c08afa1c..c08afa73. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c08afc48();
  }
  FUN_c08af8b4(param_1,param_2,param_3);
  return;
}



/* c08afa74 FUN_c08afa74 */

/* Boundary evidence: original MIPS .pdata c08afa74..c08afb93. Semantic name remains unreviewed. */

void FUN_c08afa74(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c08c06fc = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c08c0704;
    if (DAT_c08c0704 != (undefined4 *)0x0) {
      while (DAT_c08c0700 = DAT_c08c0700 + -1, _Memory <= DAT_c08c0700) {
        if ((code *)*DAT_c08c0700 != (code *)0x0) {
          (*(code *)*DAT_c08c0700)();
          _Memory = DAT_c08c0704;
        }
      }
      free(_Memory);
      DAT_c08c0700 = (undefined4 *)0x0;
      DAT_c08c0704 = (undefined4 *)0x0;
    }
    FUN_c08afbb8((undefined4 *)&DAT_c0891014,(undefined4 *)&DAT_c0891018);
  }
  FUN_c08afbb8((undefined4 *)&DAT_c089101c,(undefined4 *)&DAT_c0891020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c08c0708,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c08afb94 FUN_c08afb94 */

/* Boundary evidence: original MIPS .pdata c08afb94..c08afbb7. Semantic name remains unreviewed. */

void FUN_c08afb94(void)

{
  FUN_c08afa74(0,0,1);
  return;
}



/* c08afbb8 FUN_c08afbb8 */

/* Boundary evidence: original MIPS .pdata c08afbb8..c08afc0b. Semantic name remains unreviewed. */

void FUN_c08afbb8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c08afc0c FUN_c08afc0c */

/* Boundary evidence: original MIPS .pdata c08afc0c..c08afc47. Semantic name remains unreviewed. */

void FUN_c08afc0c(void)

{
  FUN_c08afbb8((undefined4 *)&DAT_c089100c,(undefined4 *)&DAT_c0891010);
  FUN_c08afbb8((undefined4 *)&DAT_c0891000,(undefined4 *)&DAT_c0891008);
  return;
}



/* c08afc48 FUN_c08afc48 */

/* Boundary evidence: original MIPS .pdata c08afc48..c08afcbb. Semantic name remains unreviewed. */

void FUN_c08afc48(void)

{
  uint uVar1;
  
  if ((DAT_c08bc848 == 0) || (DAT_c08bc848 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c08bc848 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c08bc848 == 0) {
      DAT_c08bc848 = 0xb064;
    }
  }
  DAT_c08bc84c = ~DAT_c08bc848;
  return;
}



/* c08afe4c FUN_c08afe4c */

/* Boundary evidence: original MIPS .pdata c08afe4c..c08afe7b. Semantic name remains unreviewed. */

void FUN_c08afe4c(void)

{
  FUN_c089bfe0(-0x3f7424f8,0x6e0,2,&LAB_c089cc44);
  return;
}


