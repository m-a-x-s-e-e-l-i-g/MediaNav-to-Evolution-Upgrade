/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c00f47d4 FUN_c00f47d4 */

uint FUN_c00f47d4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0x20;
  if ((param_1 & 1) == 0) {
    uVar3 = 0;
  }
  uVar2 = 2;
  if ((param_1 & 2) == 0) {
    uVar2 = 0;
  }
  uVar4 = 4;
  if ((param_1 & 4) == 0) {
    uVar4 = 0;
  }
  uVar1 = 0x800;
  if ((param_1 & 0x10) == 0) {
    uVar1 = 0;
  }
  uVar3 = uVar1 | (param_1 & 8) != 0 | uVar4 | uVar2 | uVar3;
  if (uVar3 == 0) {
    uVar3 = 0x80;
  }
  return uVar3;
}



/* c00f4848 FUN_c00f4848 */

int * FUN_c00f4848(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = DAT_c0136c80;
  if (param_1 == *DAT_c0136c80) {
    piVar2 = DAT_c0136c80 + 3;
    DAT_c0136c80 = (int *)DAT_c0136c80[3];
    *piVar2 = 0;
  }
  else {
    piVar2 = (int *)DAT_c0136c80[3];
    while (piVar1 = piVar2, piVar1 != (int *)0x0) {
      if (param_1 == *piVar1) {
        piVar3[3] = piVar1[3];
        piVar1[3] = 0;
        return piVar1;
      }
      piVar3 = piVar1;
      piVar2 = (int *)piVar1[3];
    }
    piVar3 = (int *)0x0;
  }
  return piVar3;
}



/* c00f48b4 FUN_c00f48b4 */

void FUN_c00f48b4(int param_1)

{
  *(undefined4 *)(param_1 + 0x418) = 0;
  *(undefined4 *)(param_1 + 0x43c) = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  *(undefined4 *)(param_1 + 0x45c) = 0;
  return;
}



/* c00f48c8 FUN_c00f48c8 */

/* Boundary evidence: original MIPS .pdata c00f48c8..c00f495f. Semantic name remains unreviewed. */

void FUN_c00f48c8(int param_1)

{
  if (DAT_c013e7b4 != (code *)0x0) {
    if (*(int *)(param_1 + 0x418) != 0) {
      (*DAT_c013e7b4)(param_1 + 0x410);
    }
    if (*(int *)(param_1 + 0x43c) != 0) {
      (*DAT_c013e7b4)(param_1 + 0x434);
    }
  }
  FUN_c01017f4(param_1);
  return;
}



/* c00f4960 FUN_c00f4960 */

/* Boundary evidence: original MIPS .pdata c00f4960..c00f496b. Semantic name remains unreviewed. */

undefined4 FUN_c00f4960(void)

{
  return 1;
}



/* c00f496c FUN_c00f496c */

/* Boundary evidence: original MIPS .pdata c00f496c..c00f4a63. Semantic name remains unreviewed. */

uint FUN_c00f496c(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  
  uVar3 = 1;
  for (uVar1 = param_2 >> 0x10; uVar1 != 0; uVar1 = uVar1 >> 4) {
    uVar3 = uVar3 + 1;
  }
  if ((((param_1 != (uint *)0x0) && (uVar3 <= (ushort)param_1[2])) && (*param_1 != 0)) &&
     (uVar1 = FUN_c0101c94(-0x3fec6e20,*param_1), uVar1 != 0)) {
    uVar2 = (uint)(ushort)param_1[2];
    do {
      uVar2 = uVar2 + 0xffff & 0xffff;
      if (uVar2 == 0) {
        return uVar1;
      }
      uVar1 = *(uint *)((param_2 >> ((uVar2 + 3) * 4 & 0x1f) & 0xf) * 4 + uVar1);
    } while ((uVar1 != 0) && (uVar1 = FUN_c0101c94(-0x3fec6e20,uVar1), uVar1 != 0));
  }
  return 0;
}



/* c00f4a64 FUN_c00f4a64 */

/* Boundary evidence: original MIPS .pdata c00f4a64..c00f4ce3. Semantic name remains unreviewed. */

bool FUN_c00f4a64(int param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint local_34;
  
  uVar3 = 0xffffffff;
  uVar2 = uVar3;
  if (param_2 < 4) {
    uVar2 = (0x10 << ((param_2 & 7) << 2)) << 0xc;
  }
  uVar4 = uVar3;
  if ((param_3 < param_4) && (param_4 - param_3 <= uVar2)) {
    uVar4 = param_4 >> ((param_2 + 3) * 4 & 0x1f) & 0xf;
  }
  if (param_2 == 0) {
    iVar5 = 0xf;
    if ((int)uVar4 < 0xf) {
      puVar6 = (uint *)(param_1 + 0x3c);
      do {
        if (iVar5 < 0) break;
        if (*puVar6 != 0) {
          FUN_c010297c(-0x3fec6e20);
          FUN_c01037f0(&DAT_c01391e0,*puVar6);
          FUN_c01029e4(-0x3fec6e20,1,puVar6,*puVar6,4);
          *puVar6 = 0;
          FUN_c0102aa4(&DAT_c01391e0);
        }
        iVar5 = iVar5 + -1;
        puVar6 = puVar6 + -1;
      } while ((int)uVar4 < iVar5);
    }
  }
  else {
    if ((int)(param_2 - 1) < 4) {
      uVar3 = (0x10 << ((param_2 - 1) * 4 & 0x1f)) << 0xc;
    }
    iVar5 = 0xf;
    local_34 = uVar3 * 0xf + param_3;
    if ((int)uVar4 < 0x10) {
      do {
        if (iVar5 < 0) break;
        puVar6 = (uint *)(iVar5 * 4 + param_1);
        if ((*puVar6 != 0) && (uVar2 = FUN_c0101c94(-0x3fec6e20,*puVar6), uVar2 != 0)) {
          FUN_c010297c(-0x3fec6e20);
          bVar1 = FUN_c00f4a64(uVar2,param_2 + 0xffff & 0xffff,local_34,param_4);
          if (CONCAT31(extraout_var,bVar1) == 1) {
            FUN_c01037f0(&DAT_c01391e0,*puVar6);
            FUN_c01029e4(-0x3fec6e20,1,puVar6,*puVar6,4);
            *puVar6 = 0;
            if (iVar5 <= (int)uVar4) {
              iVar5 = -1;
              uVar4 = uVar4 - 1;
            }
          }
          FUN_c0102aa4(&DAT_c01391e0);
        }
        local_34 = local_34 - uVar3;
        iVar5 = iVar5 + -1;
      } while ((int)uVar4 <= iVar5);
    }
  }
  return uVar4 == 0xffffffff;
}



/* c00f4ce4 FUN_c00f4ce4 */

/* Boundary evidence: original MIPS .pdata c00f4ce4..c00f4f67. Semantic name remains unreviewed. */

void FUN_c00f4ce4(uint param_1,uint param_2)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  undefined3 extraout_var;
  int iVar4;
  uint *puVar5;
  ushort uVar6;
  uint uVar7;
  uint *puVar8;
  
  if ((param_1 != 0) && (puVar2 = (uint *)FUN_c0101c94(-0x3fec6e20,param_1), puVar2 != (uint *)0x0))
  {
    if ((*puVar2 == 0) ||
       (puVar3 = (uint *)FUN_c0101c94(-0x3fec6e20,*puVar2), puVar3 == (uint *)0x0)) {
      puVar3 = puVar2 + 2;
      uVar6 = 1;
      FUN_c01029e4(-0x3fec6e20,1,puVar3,(uint)(ushort)*puVar3,2);
      if (param_2 == 0) {
        *(ushort *)puVar3 = 0;
      }
      else {
        for (uVar7 = param_2 >> 0x10; uVar7 != 0; uVar7 = uVar7 >> 4) {
          uVar6 = uVar6 + 1;
        }
        *(ushort *)puVar3 = uVar6;
      }
    }
    else {
      puVar8 = puVar2 + 2;
      bVar1 = FUN_c00f4a64((int)puVar3,(uint)(ushort)((ushort)*puVar8 - 1),0,param_2);
      if (CONCAT31(extraout_var,bVar1) == 1) {
        FUN_c010297c(-0x3fec6e20);
        FUN_c01037f0(&DAT_c01391e0,*puVar2);
        FUN_c01029e4(-0x3fec6e20,1,puVar2,*puVar2,4);
        *puVar2 = 0;
        FUN_c01029e4(-0x3fec6e20,1,puVar8,(uint)(ushort)*puVar8,2);
        *(ushort *)puVar8 = 0;
        FUN_c0102aa4(&DAT_c01391e0);
      }
      else {
        do {
          if ((ushort)*puVar8 < 2) break;
          iVar4 = 0xf;
          puVar5 = puVar3 + 0xf;
          do {
            if (*puVar5 != 0) break;
            iVar4 = iVar4 + -1;
            puVar5 = puVar5 + -1;
          } while (-1 < iVar4);
          if (0 < iVar4) break;
          if (iVar4 == 0) {
            FUN_c010297c(-0x3fec6e20);
            uVar7 = *puVar2;
            FUN_c01029e4(-0x3fec6e20,1,puVar2,uVar7,4);
            *puVar2 = *puVar3;
            FUN_c01037f0(&DAT_c01391e0,uVar7);
            FUN_c01029e4(-0x3fec6e20,1,puVar8,(uint)(ushort)*puVar8,2);
            *(ushort *)puVar8 = (ushort)*puVar8 - 1;
            FUN_c0102aa4(&DAT_c01391e0);
          }
          puVar3 = (uint *)FUN_c0101c94(-0x3fec6e20,*puVar2);
        } while (puVar3 != (uint *)0x0);
      }
    }
    puVar3 = puVar2 + 1;
    FUN_c01029e4(-0x3fec6e20,1,puVar3,*puVar3,4);
    *puVar3 = param_2;
    FUN_c0104fd8(&DAT_c01391e0,(int)(puVar2 + -3));
  }
  return;
}



/* c00f4f68 FUN_c00f4f68 */

/* Boundary evidence: original MIPS .pdata c00f4f68..c00f503b. Semantic name remains unreviewed. */

uint * FUN_c00f4f68(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar1 = FUN_c0103dc8(&DAT_c01391e0,3,0x40,0,0);
  if (puVar1 == (uint *)0x0) {
    puVar3 = (uint *)0x0;
  }
  else {
    puVar3 = puVar1 + 3;
    *puVar3 = *param_1;
    FUN_c01029e4(-0x3fec6e20,1,param_1,*param_1,4);
    *param_1 = puVar1[2];
    uVar4 = 1;
    do {
      uVar2 = uVar4 + 1 & 0xffff;
      puVar3[uVar4] = 0;
      uVar4 = uVar2;
    } while (uVar2 < 0x10);
  }
  return puVar3;
}



/* c00f503c FUN_c00f503c */

/* Boundary evidence: original MIPS .pdata c00f503c..c00f5147. Semantic name remains unreviewed. */

undefined4 FUN_c00f503c(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  ushort uVar3;
  uint *puVar4;
  int iVar5;
  
  iVar5 = 1;
  for (uVar2 = param_2 >> 0x10; uVar2 != 0; uVar2 = uVar2 >> 4) {
    iVar5 = iVar5 + 1;
  }
  if ((*param_1 == 0) && (iVar5 != 0)) {
    puVar4 = param_1 + 2;
    FUN_c01029e4(-0x3fec6e20,1,puVar4,(uint)(ushort)*puVar4,2);
    *(ushort *)puVar4 = (ushort)iVar5;
  }
  else {
    puVar4 = param_1 + 2;
    FUN_c01029e4(-0x3fec6e20,1,puVar4,(uint)(ushort)*puVar4,2);
    uVar3 = (ushort)*puVar4;
    while ((int)(uint)uVar3 < iVar5) {
      puVar1 = FUN_c00f4f68(param_1);
      if (puVar1 == (uint *)0x0) {
        return 0;
      }
      uVar3 = (ushort)*puVar4 + 1;
      *(ushort *)puVar4 = uVar3;
    }
  }
  return 1;
}



/* c00f5148 FUN_c00f5148 */

/* Boundary evidence: original MIPS .pdata c00f5148..c00f5243. Semantic name remains unreviewed. */

uint * FUN_c00f5148(uint *param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = FUN_c00f503c(param_1,param_2);
  if ((iVar1 == 0) ||
     (((*param_1 == 0 ||
       (puVar2 = (uint *)FUN_c0101c94(-0x3fec6e20,*param_1), puVar2 == (uint *)0x0)) &&
      (puVar2 = FUN_c00f4f68(param_1), puVar2 == (uint *)0x0)))) {
LAB_c00f5220:
    puVar2 = (uint *)0x0;
  }
  else {
    iVar1 = (ushort)param_1[2] - 1;
    if (0 < iVar1) {
      uVar5 = ((ushort)param_1[2] + 2) * 4;
      do {
        uVar4 = puVar2[param_2 >> (uVar5 & 0x1f) & 0xf];
        if ((uVar4 == 0) || (iVar3 = FUN_c0101d64(-0x3fec6e20,uVar4), iVar3 == 0)) {
          puVar2 = FUN_c00f4f68(puVar2 + (param_2 >> (uVar5 & 0x1f) & 0xf));
          if (puVar2 == (uint *)0x0) goto LAB_c00f5220;
        }
        else {
          puVar2 = (uint *)(iVar3 + 0xc);
        }
        iVar1 = iVar1 + -1;
        uVar5 = uVar5 - 4;
      } while (0 < iVar1);
    }
  }
  return puVar2;
}



/* c00f5244 FUN_c00f5244 */

void FUN_c00f5244(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &DAT_c013a768;
  do {
    if (*piVar1 == param_1) {
      return;
    }
    piVar1 = piVar1 + 0x405;
  } while ((int)piVar1 < -0x3fec1848);
  iVar2 = 0;
  piVar1 = &DAT_c013a768;
  do {
    if (((*(ushort *)((int)piVar1 + 6) & 1) != 0) && (*piVar1 == 0)) goto LAB_c00f5304;
    piVar1 = piVar1 + 0x405;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < -0x3fec1848);
  iVar2 = 0;
  piVar1 = &DAT_c013a768;
  while (*piVar1 != 0) {
    piVar1 = piVar1 + 0x405;
    iVar2 = iVar2 + 1;
    if (-0x3fec1849 < (int)piVar1) {
      return;
    }
  }
LAB_c00f5304:
  (&DAT_c013a768)[iVar2 * 0x405] = param_1;
  return;
}



/* c00f5310 FUN_c00f5310 */

/* Boundary evidence: original MIPS .pdata c00f5310..c00f53bf. Semantic name remains unreviewed. */

bool FUN_c00f5310(int param_1)

{
  uint *puVar1;
  
  FUN_c010297c(-0x3fec6e20);
  puVar1 = FUN_c0103dc8(&DAT_c01391e0,0xf,0x1002,1,0);
  if (puVar1 != (uint *)0x0) {
    FUN_c0102aa4(&DAT_c01391e0);
    (&DAT_c013a768)[param_1 * 0x405] = puVar1[2];
  }
  else {
    FUN_c01036ac(&DAT_c01391e0);
  }
  return puVar1 != (uint *)0x0;
}



/* c00f53c0 FUN_c00f53c0 */

/* Boundary evidence: original MIPS .pdata c00f53c0..c00f56bb. Semantic name remains unreviewed. */

undefined4 FUN_c00f53c0(int param_1)

{
  int iVar1;
  uint *puVar2;
  size_t sVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  ushort *puVar7;
  ushort uVar8;
  void *local_38;
  void *local_30;
  
  iVar1 = param_1 * 0x1014;
  puVar7 = &DAT_c013a76e + param_1 * 0x80a;
  if ((*puVar7 & 1) == 0) {
    return 1;
  }
  puVar2 = (uint *)FUN_c0101c94(-0x3fec6e20,(&DAT_c013a764)[param_1 * 0x405]);
  if (puVar2 == (uint *)0x0) {
    return 0;
  }
  uVar5 = (uint)*(ushort *)(&DAT_c013a76c + iVar1);
  if (uVar5 != 0) {
    do {
      if (*(char *)(iVar1 + -0x3fec588f + uVar5) != '\0') break;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
    if (uVar5 != 0) {
      if ((((*puVar7 & 2) == 0) && (uVar5 != 1)) &&
         (sVar3 = BinaryCompress(iVar1 + -0x3fec588e,uVar5,DAT_c0139404,uVar5 - 1),
         sVar3 != 0xffffffff)) {
        uVar8 = 1;
        uVar5 = sVar3;
        local_38 = DAT_c0139404;
      }
      else {
        local_38 = (void *)(iVar1 + -0x3fec588e);
        uVar8 = 2;
      }
      goto LAB_c00f5500;
    }
  }
  uVar8 = 4;
  local_38 = local_30;
LAB_c00f5500:
  puVar4 = (uint *)FUN_c00f496c(puVar2,(&DAT_c013a760)[param_1 * 0x405]);
  if (puVar4 == (uint *)0x0) {
    return 0;
  }
  FUN_c010297c(-0x3fec6e20);
  FUN_c01029e4(-0x3fec6e20,1,puVar2 + 6,puVar2[6],4);
  puVar2 = puVar2 + 5;
  FUN_c01029e4(-0x3fec6e20,1,puVar2,*puVar2,4);
  GetCurrentFT(puVar2);
  puVar2 = puVar4;
  if (uVar8 != 4) {
    puVar6 = &DAT_c013a768 + param_1 * 0x405;
    puVar2 = FUN_c0103dc8(&DAT_c01391e0,6,uVar5 + 2,1,*puVar6);
    if (puVar2 == (uint *)0x0) {
      FUN_c01036ac(&DAT_c01391e0);
      return 0;
    }
    if (puVar2[2] == *puVar6) {
      *puVar6 = 0;
    }
    *(ushort *)(puVar2 + 3) = ((((ushort)*puVar2 & 0xfffc) - (short)uVar5) + -2) * 0x1000 | uVar8;
    memcpy((void *)((int)puVar2 + 0xe),local_38,uVar5);
  }
  uVar5 = (uint)(&DAT_c013a760)[param_1 * 0x405] >> 0xc & 0xf;
  puVar6 = puVar4 + uVar5;
  if (*puVar6 != 0) {
    FUN_c01037f0(&DAT_c01391e0,*puVar6);
  }
  FUN_c01029e4(-0x3fec6e20,1,puVar4 + uVar5,*puVar6,4);
  if (uVar8 == 4) {
    *puVar6 = 0;
  }
  else {
    *puVar6 = puVar2[2];
  }
  *puVar7 = *puVar7 & 0xfffe;
  FUN_c0102aa4(&DAT_c01391e0);
  return 1;
}



/* c00f56bc FUN_c00f56bc */

/* Boundary evidence: original MIPS .pdata c00f56bc..c00f5733. Semantic name remains unreviewed. */

void FUN_c00f56bc(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_c013a764;
  do {
    if ((param_1 == 0) || (*piVar1 == param_1)) {
      FUN_c00f53c0(iVar2);
    }
    piVar1 = piVar1 + 0x405;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < -0x3fec184c);
  return;
}



/* c00f5734 FUN_c00f5734 */

/* Boundary evidence: original MIPS .pdata c00f5734..c00f5803. Semantic name remains unreviewed. */

uint FUN_c00f5734(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = DAT_c013e7b0;
  uVar4 = DAT_c013e7b0 + 1 & 3;
  iVar1 = DAT_c013e7b0 * 0x405;
  if ((((&DAT_c013a764)[iVar1] == 0) || (((&DAT_c013a76e)[DAT_c013e7b0 * 0x80a] & 1) == 0)) ||
     (DAT_c013e7b0 = uVar4, iVar2 = FUN_c00f53c0(uVar3), uVar4 = DAT_c013e7b0, iVar2 != 0)) {
    DAT_c013e7b0 = uVar4;
    (&DAT_c013a764)[iVar1] = param_1;
    (&DAT_c013a760)[uVar3 * 0x405] = param_2;
    (&DAT_c013a76e)[uVar3 * 0x80a] = 0;
    uVar3 = uVar3 & 0xffff;
  }
  else {
    uVar3 = 0xffff;
  }
  return uVar3;
}



/* c00f5804 FUN_c00f5804 */

/* Boundary evidence: original MIPS .pdata c00f5804..c00f58fb. Semantic name remains unreviewed. */

uint * FUN_c00f5804(uint *param_1,wchar_t *param_2,size_t param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  if ((param_3 != 0) && ((param_3 != 1 || (*param_2 != L'.')))) {
    if ((param_3 == 2) && ((*param_2 == L'.' && (param_2[1] == L'.')))) {
      param_1 = (uint *)FUN_c0101c94(-0x3fec6e20,param_1[3]);
    }
    else {
      while ((uVar3 != 0 &&
             (puVar1 = (uint *)FUN_c0101c94(-0x3fec6e20,uVar3), puVar1 != (uint *)0x0))) {
        iVar2 = FUN_c00fc6b0(param_2,param_3,(wchar_t *)(puVar1 + 8),
                             (uint)*(ushort *)((int)puVar1 + 0x1e));
        if (iVar2 != 0) {
          return puVar1;
        }
        uVar3 = puVar1[4];
      }
      param_1 = (uint *)0x0;
    }
  }
  return param_1;
}



/* c00f58fc FUN_c00f58fc */

/* Boundary evidence: original MIPS .pdata c00f58fc..c00f5a2f. Semantic name remains unreviewed. */

undefined4 FUN_c00f58fc(uint *param_1,wchar_t *param_2,size_t param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 == 1) {
    if (*param_2 == L'.') {
      return 1;
    }
  }
  else if (((param_3 == 2) && (*param_2 == L'.')) && (param_2[1] == L'.')) {
    uVar3 = FUN_c0101c94(-0x3fec6e20,*(uint *)(*param_1 + 0xc));
    *param_1 = uVar3;
    if (uVar3 == 0) {
      return 0;
    }
    return 1;
  }
  uVar3 = *(uint *)*param_1;
  while( true ) {
    if ((uVar3 == 0) || (puVar1 = (uint *)FUN_c0101d64(-0x3fec6e20,uVar3), puVar1 == (uint *)0x0)) {
      return 0;
    }
    if (((*puVar1 & 0xf0000000) == 0x40000000) &&
       (iVar2 = FUN_c00fc6b0(param_2,param_3,(wchar_t *)(puVar1 + 0xb),
                             (uint)*(ushort *)((int)puVar1 + 0x2a)), iVar2 != 0)) break;
    uVar3 = puVar1[7];
  }
  *param_1 = (uint)(puVar1 + 3);
  return 1;
}



/* c00f5a30 FUN_c00f5a30 */

/* Boundary evidence: original MIPS .pdata c00f5a30..c00f5b47. Semantic name remains unreviewed. */

undefined4 FUN_c00f5a30(wchar_t *param_1,uint *param_2,undefined4 *param_3)

{
  wchar_t wVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  wchar_t *pwVar5;
  
  uVar2 = FUN_c0101c94(-0x3fec6e20,0);
  *param_2 = uVar2;
  pwVar5 = param_1;
  if (uVar2 == 0) {
    RaiseException(1,1,0,(ULONG_PTR *)0x0);
LAB_c00f5a8c:
    SetLastError(3);
    uVar3 = 0;
  }
  else {
    while (*param_1 != L'\0') {
      wVar1 = *param_1;
      while (((wVar1 != L'\0' && (wVar1 != L'\\')) && (wVar1 != L'/'))) {
        param_1 = param_1 + 1;
        wVar1 = *param_1;
      }
      if (*param_1 != L'\0') {
        if ((pwVar5 != param_1) &&
           (iVar4 = FUN_c00f58fc(param_2,pwVar5,(int)param_1 - (int)pwVar5 >> 1), iVar4 == 0))
        goto LAB_c00f5a8c;
        param_1 = param_1 + 1;
        pwVar5 = param_1;
      }
    }
    *param_3 = pwVar5;
    uVar3 = 1;
  }
  return uVar3;
}



/* c00f5b48 FUN_c00f5b48 */

/* Boundary evidence: original MIPS .pdata c00f5b48..c00f5bb3. Semantic name remains unreviewed. */

void FUN_c00f5b48(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = (int *)DAT_c013e7b8;
  uVar1 = FUN_c0101c94(-0x3fec6e20,param_1);
  if (uVar1 != 0) {
    uVar2 = *(undefined4 *)(uVar1 + 0x10);
    for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      if (piVar3[3] == param_1) {
        piVar3[3] = uVar2;
      }
    }
  }
  return;
}



/* c00f5bb4 FUN_c00f5bb4 */

/* Boundary evidence: original MIPS .pdata c00f5bb4..c00f5cf3. Semantic name remains unreviewed. */

void FUN_c00f5bb4(uint param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar1 = (uint *)FUN_c0101d64(-0x3fec6e20,param_1);
  if (((puVar1 != (uint *)0x0) && ((*puVar1 & 1) == 0)) &&
     (uVar2 = FUN_c0101c94(-0x3fec6e20,param_1), uVar2 != 0)) {
    FUN_c010297c(-0x3fec6e20);
    if (param_3 == 0) {
      puVar3 = (undefined4 *)FUN_c0101c94(-0x3fec6e20,param_2);
      if (puVar3 != (undefined4 *)0x0) {
        FUN_c01029e4(-0x3fec6e20,1,puVar3,*puVar3,4);
        *puVar3 = *(undefined4 *)(uVar2 + 0x10);
      }
    }
    else {
      uVar4 = FUN_c0101c94(-0x3fec6e20,param_3);
      if (uVar4 != 0) {
        puVar3 = (undefined4 *)(uVar4 + 0x10);
        FUN_c01029e4(-0x3fec6e20,1,puVar3,*puVar3,4);
        *puVar3 = *(undefined4 *)(uVar2 + 0x10);
      }
    }
    if (*(int *)(uVar2 + 4) != 0) {
      FUN_c00f4ce4(param_1,0);
    }
    FUN_c01037f0(&DAT_c01391e0,param_1);
    FUN_c0102aa4(&DAT_c01391e0);
  }
  return;
}



/* c00f5cf4 FUN_c00f5cf4 */

/* Boundary evidence: original MIPS .pdata c00f5cf4..c00f5eab. Semantic name remains unreviewed. */

void FUN_c00f5cf4(int param_1,uint *param_2,uint param_3)

{
  ushort uVar1;
  ushort *puVar2;
  size_t _Size;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  
  if (param_3 < param_2[1]) {
    uVar3 = param_2[1] - param_3;
    if (uVar3 < 0x1000) {
      puVar5 = (ushort *)(&DAT_c013a76c + param_1 * 0x1014);
      *puVar5 = (ushort)uVar3;
    }
    else {
      puVar5 = (ushort *)(&DAT_c013a76c + param_1 * 0x1014);
      *puVar5 = 0x1000;
    }
    iVar4 = param_1 * 0x1014;
    uVar3 = FUN_c00f496c(param_2,param_3);
    if ((((uVar3 == 0) || (uVar3 = *(uint *)((param_3 >> 0xc & 0xf) * 4 + uVar3), uVar3 == 0)) ||
        (puVar2 = (ushort *)FUN_c0101c94(-0x3fec6e20,uVar3), puVar2 == (ushort *)0x0)) ||
       (uVar1 = *puVar2, (uVar1 & 4) != 0)) {
      _Size = (size_t)*puVar5;
    }
    else {
      uVar3 = ((*(uint *)(puVar2 + -6) & 0xffffffc) - (uint)(uVar1 >> 0xc)) - 2;
      if ((uVar1 & 1) == 0) {
        memcpy((void *)(iVar4 + -0x3fec588e),puVar2 + 1,uVar3);
      }
      else {
        uVar3 = BinaryDecompress(puVar2 + 1,uVar3 & 0xffff,iVar4 + -0x3fec588e,0x1000,0);
      }
      if (*puVar5 <= uVar3) {
        return;
      }
      _Size = *puVar5 - uVar3;
      iVar4 = iVar4 + uVar3;
    }
    memset((void *)(iVar4 + -0x3fec588e),0,_Size);
  }
  else {
    *(undefined2 *)(&DAT_c013a76c + param_1 * 0x1014) = 0;
  }
  return;
}



/* c00f5eac FUN_c00f5eac */

/* Boundary evidence: original MIPS .pdata c00f5eac..c00f600b. Semantic name remains unreviewed. */

undefined4 FUN_c00f5eac(uint param_1,uint param_2,size_t param_3,void *param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar1 = (uint *)FUN_c0101c94(-0x3fec6e20,param_1);
  if (puVar1 == (uint *)0x0) {
    dwErrCode = 6;
LAB_c00f5f0c:
    SetLastError(dwErrCode);
    uVar2 = 0;
  }
  else {
    uVar5 = param_2 & 0xfffff000;
    uVar4 = 0;
    uVar3 = 0;
    do {
      if ((*(uint *)((int)&DAT_c013a764 + uVar3) == param_1) &&
         (*(uint *)((int)&DAT_c013a760 + uVar3) == uVar5)) break;
      uVar3 = uVar3 + 0x1014;
      uVar4 = uVar4 + 1;
    } while (uVar3 < 0x4050);
    if (uVar4 == 4) {
      uVar4 = FUN_c00f5734(param_1,uVar5);
      if (uVar4 == 0xffff) {
        dwErrCode = 0x70;
        goto LAB_c00f5f0c;
      }
      FUN_c00f5cf4(uVar4,puVar1,uVar5);
    }
    memcpy(param_4,(void *)(uVar4 * 0x1014 + (param_2 & 0xfff) + -0x3fec588e),param_3);
    uVar2 = 1;
  }
  return uVar2;
}



/* c00f600c FUN_c00f600c */

/* Boundary evidence: original MIPS .pdata c00f600c..c00f62df. Semantic name remains unreviewed. */

undefined4 FUN_c00f600c(uint param_1,uint param_2,uint param_3,void *param_4,ushort param_5)

{
  bool bVar1;
  bool bVar2;
  uint *puVar3;
  undefined3 extraout_var;
  uint *puVar4;
  DWORD dwErrCode;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  
  puVar3 = (uint *)FUN_c0101c94(-0x3fec6e20,param_1);
  if (puVar3 == (uint *)0x0) {
    dwErrCode = 6;
LAB_c00f606c:
    SetLastError(dwErrCode);
  }
  else {
    uVar9 = param_2 & 0xfffff000;
    uVar5 = (ushort)param_2 & 0xfff;
    uVar6 = uVar5 + (short)param_3;
    uVar8 = 0;
    uVar7 = 0;
    do {
      if ((*(uint *)((int)&DAT_c013a764 + uVar7) == param_1) &&
         (*(uint *)((int)&DAT_c013a760 + uVar7) == uVar9)) break;
      uVar7 = uVar7 + 0x1014;
      uVar8 = uVar8 + 1;
    } while (uVar7 < 0x4050);
    if (uVar8 == 4) {
      uVar8 = FUN_c00f5734(param_1,uVar9);
      if (uVar8 == 0xffff) {
        dwErrCode = 0x70;
        goto LAB_c00f606c;
      }
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    FUN_c010297c(-0x3fec6e20);
    puVar10 = &DAT_c013a76e + uVar8 * 0x80a;
    if (((*puVar10 & 1) != 0) ||
       ((((&DAT_c013a768)[uVar8 * 0x405] != 0 ||
         (bVar2 = FUN_c00f5310(uVar8), CONCAT31(extraout_var,bVar2) != 0)) &&
        ((uVar7 = FUN_c00f496c(puVar3,uVar9), uVar7 != 0 ||
         (puVar4 = FUN_c00f5148(puVar3,uVar9), puVar4 != (uint *)0x0)))))) {
      uVar7 = puVar3[1];
      if (uVar7 < uVar6 + uVar9) {
        FUN_c01029e4(-0x3fec6e20,1,puVar3 + 1,uVar7,4);
        puVar3[1] = uVar6 + uVar9;
      }
      FUN_c0102aa4(&DAT_c01391e0);
      if (bVar1) {
        FUN_c00f5cf4(uVar8,puVar3,uVar9);
      }
      memcpy((void *)((uint)uVar5 + uVar8 * 0x1014 + -0x3fec588e),param_4,param_3);
      if ((uint)*(ushort *)(&DAT_c013a76c + uVar8 * 0x1014) < (param_3 & 0xffff) + (uint)uVar5) {
        *(ushort *)(&DAT_c013a76c + uVar8 * 0x1014) = uVar6;
      }
      uVar5 = 2;
      if ((param_5 & 0x80) == 0) {
        uVar5 = 0;
      }
      *puVar10 = *puVar10 | uVar5 | 1;
      return 1;
    }
    FUN_c01036ac(&DAT_c01391e0);
    SetLastError(0x70);
    if (bVar1) {
      (&DAT_c013a764)[uVar8 * 0x405] = 0;
    }
  }
  return 0;
}



/* c00f62e0 FUN_c00f62e0 */

/* Boundary evidence: original MIPS .pdata c00f62e0..c00f6443. Semantic name remains unreviewed. */

undefined4 FUN_c00f62e0(uint param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  DWORD dwErrCode;
  uint *puVar4;
  
  puVar1 = (uint *)FUN_c0101c94(-0x3fec6e20,param_1);
  if (puVar1 == (uint *)0x0) {
    dwErrCode = 6;
LAB_c00f632c:
    SetLastError(dwErrCode);
    return 0;
  }
  iVar2 = FUN_c0104fd0();
  if (iVar2 == 0) {
    return 0;
  }
  FUN_c010297c(-0x3fec6e20);
  uVar3 = FUN_c0101c94(-0x3fec6e20,param_1);
  if (uVar3 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar3 + 4);
    if (param_2 < uVar3) {
      FUN_c01029e4(-0x3fec6e20,4,param_1,param_2,0);
      FUN_c00f4ce4(param_1,param_2);
      goto LAB_c00f6414;
    }
  }
  if (uVar3 < param_2) {
    iVar2 = FUN_c00f503c(puVar1,param_2);
    if (iVar2 == 0) {
      FUN_c01036ac(&DAT_c01391e0);
      dwErrCode = 0x70;
      goto LAB_c00f632c;
    }
    puVar4 = puVar1 + 1;
    FUN_c01029e4(-0x3fec6e20,1,puVar4,*puVar4,4);
    *puVar4 = param_2;
    FUN_c0104fd8(&DAT_c01391e0,(int)(puVar1 + -3));
  }
LAB_c00f6414:
  FUN_c0102aa4(&DAT_c01391e0);
  return 1;
}



/* c00f6444 FUN_c00f6444 */

/* Boundary evidence: original MIPS .pdata c00f6444..c00f64c7. Semantic name remains unreviewed. */

void FUN_c00f6444(undefined4 *param_1)

{
  uint *puVar1;
  
  FUN_c010297c((int)param_1);
  puVar1 = FUN_c0103dc8(param_1,4,0x20,0,0);
  if (puVar1 == (uint *)0x0) {
    FUN_c01036ac(param_1);
  }
  else {
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[3] = 0;
    *(undefined2 *)(puVar1 + 10) = 0x100;
    *(undefined2 *)((int)puVar1 + 0x2a) = 0;
    GetCurrentFT(puVar1 + 8);
    FUN_c0102aa4(param_1);
  }
  return;
}



/* c00f64c8 FSD_GetFileTime */

/* Boundary evidence: original MIPS .pdata c00f64c8..c00f6653. Semantic name remains unreviewed. */

undefined4 FSD_GetFileTime(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
                    /* 0x64c8  27  FSD_GetFileTime */
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((*(ushort *)(param_1 + 8) & 1) == 0) {
    SetLastError(5);
  }
  else {
    uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(param_1 + 0xc));
    if (uVar1 == 0) {
      SetLastError(2);
    }
    else {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(uVar1 + 0x14);
        param_2[1] = *(undefined4 *)(uVar1 + 0x18);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(uVar1 + 0x14);
        param_3[1] = *(undefined4 *)(uVar1 + 0x18);
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(uVar1 + 0x14);
        param_4[1] = *(undefined4 *)(uVar1 + 0x18);
      }
      uVar2 = 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar2;
}



/* c00f6654 FUN_c00f6654 */

/* Boundary evidence: original MIPS .pdata c00f6654..c00f665f. Semantic name remains unreviewed. */

undefined4 FUN_c00f6654(void)

{
  return 1;
}



/* c00f6660 FUN_c00f6660 */

/* Boundary evidence: original MIPS .pdata c00f6660..c00f666b. Semantic name remains unreviewed. */

undefined4 FUN_c00f6660(void)

{
  return 1;
}



/* c00f666c FSD_SetEndOfFile */

/* Boundary evidence: original MIPS .pdata c00f666c..c00f67bb. Semantic name remains unreviewed. */

undefined4 FSD_SetEndOfFile(uint *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0x666c  29  FSD_SetEndOfFile */
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((param_1[2] & 2) == 0) {
    SetLastError(5);
  }
  else {
    FUN_c00f56bc(param_1[3]);
    uVar1 = param_1[3];
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      if ((&DAT_c013a764)[iVar2 * 0x405] == uVar1) {
        (&DAT_c013a764)[iVar2 * 0x405] = 0;
      }
    }
    uVar3 = FUN_c00f62e0(param_1[3],*param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar3;
}



/* c00f67bc FUN_c00f67bc */

/* Boundary evidence: original MIPS .pdata c00f67bc..c00f67c7. Semantic name remains unreviewed. */

undefined4 FUN_c00f67bc(void)

{
  return 1;
}



/* c00f67c8 FUN_c00f67c8 */

/* Boundary evidence: original MIPS .pdata c00f67c8..c00f67d3. Semantic name remains unreviewed. */

undefined4 FUN_c00f67c8(void)

{
  return 1;
}



/* c00f67d4 FSD_DeviceIoControl */

/* Boundary evidence: original MIPS .pdata c00f67d4..c00f67fb. Semantic name remains unreviewed. */

undefined4 FSD_DeviceIoControl(void)

{
                    /* 0x67d4  30  FSD_DeviceIoControl */
  SetLastError(0x32);
  return 0;
}



/* c00f67fc FSD_GetFileSize */

/* Boundary evidence: original MIPS .pdata c00f67fc..c00f68eb. Semantic name remains unreviewed. */

undefined4 FSD_GetFileSize(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
                    /* 0x67fc  23  FSD_GetFileSize */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(param_1 + 0xc));
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = *(undefined4 *)(uVar1 + 4);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar2;
}



/* c00f68ec FUN_c00f68ec */

/* Boundary evidence: original MIPS .pdata c00f68ec..c00f68f7. Semantic name remains unreviewed. */

undefined4 FUN_c00f68ec(void)

{
  return 1;
}



/* c00f68f8 FUN_c00f68f8 */

/* Boundary evidence: original MIPS .pdata c00f68f8..c00f6903. Semantic name remains unreviewed. */

undefined4 FUN_c00f68f8(void)

{
  return 1;
}



/* c00f6904 FSD_SetFilePointer */

/* Boundary evidence: original MIPS .pdata c00f6904..c00f6baf. Semantic name remains unreviewed. */

uint FSD_SetFilePointer(uint *param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  DWORD dwErrCode;
  
                    /* 0x6904  24  FSD_SetFilePointer */
  uVar3 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  dwErrCode = 0;
  if ((param_1[2] & 3) == 0) {
    dwErrCode = 5;
    goto LAB_c00f6b00;
  }
  if (param_4 == 0) {
    if ((int)param_2 < 0) {
LAB_c00f6ac4:
      dwErrCode = 0x83;
      goto LAB_c00f6b00;
    }
    if ((param_3 == (int *)0x0) || (*param_3 == 0)) {
      *param_1 = param_2;
      uVar3 = param_2;
      goto LAB_c00f6b00;
    }
  }
  else if (param_4 == 1) {
    if ((((-1 < (int)param_2) || (param_3 == (int *)0x0)) || (*param_3 == -1)) &&
       ((((int)param_2 < 0 || (param_3 == (int *)0x0)) || (*param_3 == 0)))) {
      uVar1 = *param_1;
      if ((int)param_2 < 0) {
        if (uVar1 < -param_2) goto LAB_c00f6ac4;
      }
      else if (-uVar1 - 1 < param_2) goto LAB_c00f6a1c;
      uVar3 = uVar1 + param_2;
LAB_c00f6a1c:
      *param_1 = uVar3;
      goto LAB_c00f6b00;
    }
  }
  else if (param_4 == 2) {
    uVar1 = FUN_c0101c94(-0x3fec6e20,param_1[3]);
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = *(uint *)(uVar1 + 4);
    }
    if ((((-1 < (int)param_2) || (param_3 == (int *)0x0)) || (*param_3 == -1)) &&
       ((((int)param_2 < 0 || (param_3 == (int *)0x0)) || (*param_3 == 0)))) {
      if ((int)param_2 < 0) {
        if (uVar2 < -param_2) goto LAB_c00f6ac4;
      }
      else if (-*param_1 - 1 < param_2) goto LAB_c00f6a1c;
      uVar3 = uVar2 + param_2;
      goto LAB_c00f6a1c;
    }
  }
  dwErrCode = 0x57;
LAB_c00f6b00:
  if ((dwErrCode == 0) && (param_3 != (int *)0x0)) {
    *param_3 = 0;
  }
  SetLastError(dwErrCode);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar3;
}



/* c00f6bb0 FUN_c00f6bb0 */

/* Boundary evidence: original MIPS .pdata c00f6bb0..c00f6bbb. Semantic name remains unreviewed. */

undefined4 FUN_c00f6bb0(void)

{
  return 1;
}



/* c00f6bbc FUN_c00f6bbc */

/* Boundary evidence: original MIPS .pdata c00f6bbc..c00f6bc7. Semantic name remains unreviewed. */

undefined4 FUN_c00f6bbc(void)

{
  return 1;
}



/* c00f6bc8 FUN_c00f6bc8 */

/* Boundary evidence: original MIPS .pdata c00f6bc8..c00f6cfb. Semantic name remains unreviewed. */

undefined4 FUN_c00f6bc8(uint param_1,undefined2 *param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  uint uVar7;
  
  uVar2 = FUN_c0101c94(-0x3fec6e20,param_1);
  if (uVar2 == 0) {
    SetLastError(2);
LAB_c00f6c18:
    uVar3 = 0;
  }
  else {
    uVar4 = FUN_c0101c94(-0x3fec6e20,0);
    if (uVar2 == uVar4) {
      *param_2 = 0x5c;
      param_2[1] = 0;
    }
    else {
      uVar7 = 0;
      uVar5 = uVar2;
      do {
        if (uVar5 == uVar4) break;
        uVar7 = *(ushort *)(uVar5 + 0x1e) + uVar7 + 1;
        uVar5 = FUN_c0101c94(-0x3fec6e20,*(uint *)(uVar5 + 0xc));
      } while (uVar5 != 0);
      if (0x103 < uVar7) goto LAB_c00f6c18;
      puVar6 = param_2 + uVar7;
      *puVar6 = 0;
      do {
        if (uVar2 == uVar4) break;
        uVar1 = *(ushort *)(uVar2 + 0x1e);
        memcpy(puVar6 + -(uint)uVar1,(void *)(uVar2 + 0x20),(uint)uVar1 << 1);
        puVar6 = puVar6 + -(uint)uVar1 + -1;
        *puVar6 = 0x5c;
        uVar2 = FUN_c0101c94(-0x3fec6e20,*(uint *)(uVar2 + 0xc));
      } while (uVar2 != 0);
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* c00f6cfc FUN_c00f6cfc */

/* Boundary evidence: original MIPS .pdata c00f6cfc..c00f6e0b. Semantic name remains unreviewed. */

undefined2 * FUN_c00f6cfc(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  
  uVar1 = FUN_c0101c94(-0x3fec6e20,param_1);
  uVar2 = FUN_c0101c94(-0x3fec6e20,0);
  if (uVar1 == uVar2) {
    puVar4 = (undefined2 *)(param_2 + -4);
    *(undefined2 *)(param_2 + -2) = 0;
    *puVar4 = 0x5c;
  }
  else {
    puVar4 = (undefined2 *)(param_2 + -2);
    *puVar4 = 0;
    uVar5 = 1;
    while( true ) {
      if (uVar1 == 0) {
        return puVar4;
      }
      if (uVar1 == uVar2) {
        return puVar4;
      }
      uVar3 = (uint)*(ushort *)(uVar1 + 0x1e);
      uVar5 = uVar3 + uVar5 + 1;
      if (0x104 < uVar5) break;
      memcpy(puVar4 + -uVar3,(void *)(uVar1 + 0x20),uVar3 << 1);
      puVar4 = puVar4 + -uVar3 + -1;
      *puVar4 = 0x5c;
      uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(uVar1 + 0xc));
    }
    puVar4 = (undefined2 *)0x0;
  }
  return puVar4;
}



/* c00f6e0c FUN_c00f6e0c */

/* Boundary evidence: original MIPS .pdata c00f6e0c..c00f6ffb. Semantic name remains unreviewed. */

undefined4 FUN_c00f6e0c(uint param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  HRESULT HVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  wchar_t local_230 [260];
  uint local_28;
  
  local_28 = DAT_c0136c78;
  uVar2 = FUN_c0101c94(-0x3fec6e20,param_1 & 0xffffff);
  if (uVar2 == 0) {
    SetLastError(2);
  }
  else {
    iVar3 = FUN_c00fb110(&DAT_c01391e0,local_230,0x104);
    if (iVar3 != 0) {
      if ((local_230[0] == L'\0') || (local_230[0] == L'\\')) {
        iVar3 = StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0xc),0x104,local_230);
      }
      else {
        HVar4 = StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0xc),0x104,L"\\");
        if (HVar4 < 0) goto LAB_c00f6e7c;
        iVar3 = StringCchCatW((STRSAFE_LPWSTR)(param_2 + 0xc),0x104,local_230);
      }
      if (-1 < iVar3) {
        uVar6 = 2;
        *(undefined2 *)(param_2 + 2) = 2;
        uVar1 = *(ushort *)(uVar2 + 0x1c);
        uVar8 = 0x20;
        if ((uVar1 & 1) == 0) {
          uVar8 = 0;
        }
        if ((uVar1 & 2) == 0) {
          uVar6 = 0;
        }
        uVar7 = 4;
        if ((uVar1 & 4) == 0) {
          uVar7 = 0;
        }
        uVar5 = 0x800;
        if ((uVar1 & 0x10) == 0) {
          uVar5 = 0;
        }
        *(uint *)(param_2 + 4) = uVar5 | (uVar1 & 8) != 0 | uVar7 | uVar6 | uVar8 | 0x10;
        uVar2 = FUN_c0101ea4(-0x3fec6e20,*(uint *)(uVar2 + 0xc));
        *(uint *)(param_2 + 8) = uVar2;
        iVar3 = FUN_c00f6bc8(param_1 & 0xffffff,local_230);
        if ((iVar3 != 0) &&
           (HVar4 = StringCchCatW((STRSAFE_LPWSTR)(param_2 + 0xc),0x104,local_230), -1 < HVar4)) {
          FUN_c013331c(local_28);
          return 1;
        }
      }
    }
  }
LAB_c00f6e7c:
  FUN_c013331c(local_28);
  return 0;
}



/* c00f6ffc FUN_c00f6ffc */

/* Boundary evidence: original MIPS .pdata c00f6ffc..c00f71b3. Semantic name remains unreviewed. */

undefined4 FUN_c00f6ffc(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  HRESULT HVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  wchar_t local_230 [260];
  uint local_28;
  
  local_28 = DAT_c0136c78;
  uVar6 = param_1 & 0xffffff;
  uVar1 = FUN_c0101c94(-0x3fec6e20,uVar6);
  if (uVar1 == 0) {
    SetLastError(2);
  }
  else {
    iVar2 = FUN_c00fb110(&DAT_c01391e0,local_230,0x104);
    if (iVar2 != 0) {
      if ((local_230[0] == L'\0') || (local_230[0] == L'\\')) {
        iVar2 = StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0xc),0x104,local_230);
      }
      else {
        HVar3 = StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0xc),0x104,L"\\");
        if (HVar3 < 0) goto LAB_c00f706c;
        iVar2 = StringCchCatW((STRSAFE_LPWSTR)(param_2 + 0xc),0x104,local_230);
      }
      if (-1 < iVar2) {
        *(undefined2 *)(param_2 + 2) = 1;
        uVar4 = FUN_c00f47d4((uint)*(ushort *)(uVar1 + 0x1c));
        *(uint *)(param_2 + 4) = uVar4;
        uVar4 = FUN_c0101ea4(-0x3fec6e20,*(uint *)(uVar1 + 0xc));
        *(uint *)(param_2 + 8) = uVar4;
        *(undefined4 *)(param_2 + 0x214) = *(undefined4 *)(uVar1 + 0x14);
        *(undefined4 *)(param_2 + 0x218) = *(undefined4 *)(uVar1 + 0x18);
        uVar1 = FUN_c0101c94(-0x3fec6e20,uVar6);
        uVar5 = 0;
        if (uVar1 != 0) {
          uVar5 = *(undefined4 *)(uVar1 + 4);
        }
        *(undefined4 *)(param_2 + 0x21c) = uVar5;
        iVar2 = FUN_c00f6bc8(uVar6,local_230);
        if ((iVar2 != 0) &&
           (HVar3 = StringCchCatW((STRSAFE_LPWSTR)(param_2 + 0xc),0x104,local_230), -1 < HVar3)) {
          FUN_c013331c(local_28);
          return 1;
        }
      }
    }
  }
LAB_c00f706c:
  FUN_c013331c(local_28);
  return 0;
}



/* c00f71b4 FSD_GetFileInformationByHandle */

/* Boundary evidence: original MIPS .pdata c00f71b4..c00f7377. Semantic name remains unreviewed. */

undefined4 FSD_GetFileInformationByHandle(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
                    /* 0x71b4  25  FSD_GetFileInformationByHandle */
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  param_2[7] = 0;
  param_2[10] = 1;
  param_2[0xb] = 0;
  uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(param_1 + 0xc));
  if (uVar1 == 0) {
    SetLastError(6);
  }
  else {
    uVar2 = FUN_c00f47d4((uint)*(ushort *)(uVar1 + 0x1c));
    *param_2 = uVar2;
    param_2[1] = *(uint *)(uVar1 + 0x14);
    param_2[2] = *(uint *)(uVar1 + 0x18);
    param_2[3] = *(uint *)(uVar1 + 0x14);
    param_2[4] = *(uint *)(uVar1 + 0x18);
    param_2[5] = *(uint *)(uVar1 + 0x14);
    param_2[6] = *(uint *)(uVar1 + 0x18);
    param_2[8] = 0;
    uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(param_1 + 0xc));
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = *(uint *)(uVar1 + 4);
    }
    param_2[9] = uVar2;
    uVar1 = FUN_c0101ea4(-0x3fec6e20,*(uint *)(param_1 + 0xc));
    param_2[0xc] = uVar1;
    uVar1 = FUN_c0101ea4(-0x3fec6e20,*(uint *)(param_1 + 0xc));
    param_2[0xd] = uVar1;
    uVar3 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar3;
}



/* c00f7378 FUN_c00f7378 */

/* Boundary evidence: original MIPS .pdata c00f7378..c00f7383. Semantic name remains unreviewed. */

undefined4 FUN_c00f7378(void)

{
  return 1;
}



/* c00f7384 FUN_c00f7384 */

/* Boundary evidence: original MIPS .pdata c00f7384..c00f738f. Semantic name remains unreviewed. */

undefined4 FUN_c00f7384(void)

{
  return 1;
}



/* c00f7390 FSD_FlushFileBuffers */

/* Boundary evidence: original MIPS .pdata c00f7390..c00f7483. Semantic name remains unreviewed. */

bool FSD_FlushFileBuffers(int param_1)

{
  bool bVar1;
  
                    /* 0x7390  26  FSD_FlushFileBuffers */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  bVar1 = (*(ushort *)(param_1 + 8) & 2) == 0;
  if (bVar1) {
    SetLastError(5);
  }
  else {
    FUN_c00f56bc(*(int *)(param_1 + 0xc));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return !bVar1;
}



/* c00f7484 FUN_c00f7484 */

/* Boundary evidence: original MIPS .pdata c00f7484..c00f748f. Semantic name remains unreviewed. */

undefined4 FUN_c00f7484(void)

{
  return 1;
}



/* c00f7490 FUN_c00f7490 */

/* Boundary evidence: original MIPS .pdata c00f7490..c00f749b. Semantic name remains unreviewed. */

undefined4 FUN_c00f7490(void)

{
  return 1;
}



/* c00f749c FUN_c00f749c */

/* Boundary evidence: original MIPS .pdata c00f749c..c00f75af. Semantic name remains unreviewed. */

undefined4 FUN_c00f749c(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = FUN_c0101c94(-0x3fec6e20,param_1[3]);
  if (uVar1 != 0) {
    if (DAT_c0136c80 != (int *)0x0) {
      piVar2 = DAT_c0136c80;
      do {
        if (param_1[3] == *piVar2) goto LAB_c00f7508;
        piVar2 = (int *)piVar2[3];
      } while (piVar2 != (int *)0x0);
    }
    piVar2 = (int *)0x0;
LAB_c00f7508:
    if ((piVar2 != (int *)0x0) &&
       (*(LPCRITICAL_SECTION *)(piVar2[1] + 0xc) != (LPCRITICAL_SECTION)0x0)) {
      EnterCriticalSection(*(LPCRITICAL_SECTION *)(piVar2[1] + 0xc));
      *(undefined4 *)piVar2[1] = *param_1;
      *(undefined4 *)(piVar2[1] + 4) = 0;
      *(undefined4 *)(piVar2[1] + 8) = 0;
      if ((*(ushort *)(param_1 + 2) & 2) != 0) {
        *(uint *)(piVar2[1] + 8) = *(uint *)(piVar2[1] + 8) | 0x40000000;
      }
      if ((*(ushort *)(param_1 + 2) & 1) != 0) {
        *(uint *)(piVar2[1] + 8) = *(uint *)(piVar2[1] + 8) | 0x80000000;
      }
      *param_2 = piVar2[1];
      return 1;
    }
  }
  return 0;
}



/* c00f75b0 FUN_c00f75b0 */

/* Boundary evidence: original MIPS .pdata c00f75b0..c00f7643. Semantic name remains unreviewed. */

undefined4 FUN_c00f75b0(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(param_1 + 0xc));
  if (uVar1 != 0) {
    if (DAT_c0136c80 != (int *)0x0) {
      piVar2 = DAT_c0136c80;
      do {
        if (*(int *)(param_1 + 0xc) == *piVar2) goto LAB_c00f7610;
        piVar2 = (int *)piVar2[3];
      } while (piVar2 != (int *)0x0);
    }
    piVar2 = (int *)0x0;
LAB_c00f7610:
    if ((piVar2 != (int *)0x0) &&
       (*(LPCRITICAL_SECTION *)(piVar2[1] + 0xc) != (LPCRITICAL_SECTION)0x0)) {
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)(piVar2[1] + 0xc));
      return 1;
    }
  }
  return 0;
}



/* c00f7644 FSD_LockFileEx */

/* Boundary evidence: original MIPS .pdata c00f7644..c00f76c3. Semantic name remains unreviewed. */

void FSD_LockFileEx(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
                    /* 0x7644  33  FSD_LockFileEx */
  FSDMGR_InstallFileLock(FUN_c00f749c,FUN_c00f75b0,param_1,param_2,0,param_4,param_5,param_6,0);
  return;
}



/* c00f76c4 FUN_c00f76c4 */

/* Boundary evidence: original MIPS .pdata c00f76c4..c00f76cf. Semantic name remains unreviewed. */

undefined4 FUN_c00f76c4(void)

{
  return 1;
}



/* c00f76d0 FSD_UnlockFileEx */

/* Boundary evidence: original MIPS .pdata c00f76d0..c00f7747. Semantic name remains unreviewed. */

void FSD_UnlockFileEx(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5)

{
                    /* 0x76d0  34  FSD_UnlockFileEx */
  FSDMGR_RemoveFileLock(FUN_c00f749c,FUN_c00f75b0,param_1,0,param_3,param_4,param_5);
  return;
}



/* c00f7748 FUN_c00f7748 */

/* Boundary evidence: original MIPS .pdata c00f7748..c00f7753. Semantic name remains unreviewed. */

undefined4 FUN_c00f7748(void)

{
  return 1;
}



/* c00f7754 FUN_c00f7754 */

/* Boundary evidence: original MIPS .pdata c00f7754..c00f7deb. Semantic name remains unreviewed. */

undefined4 FUN_c00f7754(wchar_t *param_1,wchar_t *param_2,int param_3)

{
  wchar_t *pwVar1;
  int iVar2;
  size_t sVar3;
  uint *puVar4;
  size_t sVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  undefined2 *puVar9;
  uint uVar10;
  DWORD DVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  wchar_t *pwVar18;
  uint *puVar19;
  wchar_t *local_48;
  wchar_t *local_44;
  uint local_40;
  uint *local_3c;
  int local_38;
  undefined4 local_34;
  uint *local_30;
  uint *local_2c;
  
  local_34 = 0;
  local_44 = (wchar_t *)0x0;
  local_48 = (wchar_t *)0x0;
  iVar2 = FUN_c00f5a30(param_1,(uint *)&local_3c,&local_44);
  if ((((iVar2 == 0) ||
       (iVar2 = FUN_c00f5a30(param_2,(uint *)&local_30,&local_48), pwVar18 = local_44, iVar2 == 0))
      || (sVar3 = wcslen(local_44), puVar19 = local_3c, sVar3 == 0)) ||
     (puVar4 = FUN_c00f5804(local_3c,pwVar18,sVar3), pwVar1 = local_48, puVar4 == (uint *)0x0)) {
    DVar11 = 2;
  }
  else {
    sVar5 = wcslen(local_48);
    if (sVar5 != 0) {
      local_40 = puVar4[-1];
      if (((puVar4[-3] & 0xf0000000) == 0x40000000) && ((puVar4[7] & 0x100) != 0)) {
        SetLastError(5);
        return local_34;
      }
      iVar2 = FUN_c00fc600((ushort *)pwVar1,sVar5);
      if (iVar2 != 0) {
        iVar2 = FUN_c0104fd0();
        if (iVar2 == 0) {
          return local_34;
        }
        local_38 = sVar5 + 1;
        puVar6 = (uint *)FUN_c0101c94(-0x3fec6e20,0);
        iVar2 = local_38;
        local_2c = puVar6;
        if (local_30 != (uint *)0x0) {
          iVar2 = sVar5 + 1;
          puVar7 = local_30;
          do {
            pwVar18 = local_44;
            puVar19 = local_3c;
            if (puVar7 == puVar6) break;
            iVar2 = (uint)*(ushort *)((int)puVar7 + 0x1e) + iVar2 + 1;
            puVar7 = (uint *)FUN_c0101c94(-0x3fec6e20,puVar7[3]);
            pwVar18 = local_44;
            puVar19 = local_3c;
          } while (puVar7 != (uint *)0x0);
        }
        local_38 = iVar2;
        if (0x103 < local_38) {
          SetLastError(0xce);
          return local_34;
        }
        if (((puVar19 == local_30) &&
            (iVar8 = FUN_c00fc6b0(pwVar18,sVar3,local_48,sVar5), iVar2 = DAT_c013a758, iVar8 != 0))
           || (puVar6 = FUN_c00f5804(local_30,local_48,sVar5), iVar2 = DAT_c013a758,
              puVar6 == (uint *)0x0)) {
          for (; uVar10 = local_40, iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
            if (((*(uint *)(iVar2 + 0xc) == local_40) && ((*(ushort *)(iVar2 + 8) & 8) != 0)) &&
               ((*(ushort *)(iVar2 + 8) & 6) != 0)) {
              DVar11 = 0x20;
              goto LAB_c00f7db4;
            }
          }
          FUN_c010297c(-0x3fec6e20);
          puVar9 = FUN_c00f6cfc(uVar10,param_3 + 0x208);
          *(undefined2 **)(param_3 + 0x41c) = puVar9;
          if (puVar9 != (undefined2 *)0x0) {
            *(undefined4 *)(param_3 + 0x410) = 0x24;
            if ((puVar4[-3] & 0xf0000000) == 0x40000000) {
              *(undefined4 *)(param_3 + 0x414) = 0x20000;
              uVar12 = puVar4[7];
              uVar17 = 0x20;
              if ((uVar12 & 1) == 0) {
                uVar17 = 0;
              }
              uVar16 = 2;
              if ((uVar12 & 2) == 0) {
                uVar16 = 0;
              }
              uVar15 = 4;
              if ((uVar12 & 4) == 0) {
                uVar15 = 0;
              }
              uVar13 = 0x800;
              if ((uVar12 & 0x10) == 0) {
                uVar13 = 0;
              }
              *(uint *)(param_3 + 0x424) =
                   uVar13 | (uVar12 & 8) != 0 | uVar15 | uVar16 | uVar17 | 0x10;
              *(uint *)(param_3 + 0x428) = puVar4[5];
              *(uint *)(param_3 + 0x42c) = puVar4[6];
              *(undefined4 *)(param_3 + 0x430) = 0;
            }
            else {
              *(undefined4 *)(param_3 + 0x414) = 1;
              uVar12 = FUN_c00f47d4((uint)(ushort)puVar4[7]);
              *(uint *)(param_3 + 0x424) = uVar12;
              *(uint *)(param_3 + 0x428) = puVar4[5];
              *(uint *)(param_3 + 0x42c) = puVar4[6];
              uVar12 = FUN_c0101c94(-0x3fec6e20,puVar4[-1]);
              uVar14 = 0;
              if (uVar12 != 0) {
                uVar14 = *(undefined4 *)(uVar12 + 4);
              }
              *(undefined4 *)(param_3 + 0x430) = uVar14;
            }
          }
          if (puVar19 != local_30) {
            puVar6 = local_30;
            if ((puVar4[-3] & 0xf0000000) == 0x40000000) {
              for (; (puVar6 != (uint *)0x0 &&
                     (puVar7 = (uint *)FUN_c0101c94(-0x3fec6e20,0), puVar6 != puVar7));
                  puVar6 = (uint *)FUN_c0101c94(-0x3fec6e20,puVar6[3])) {
                if (puVar6 == puVar4) {
                  DVar11 = 5;
                  goto LAB_c00f7b5c;
                }
              }
            }
            uVar12 = *puVar19;
            if (uVar12 == uVar10) {
              FUN_c01029e4(-0x3fec6e20,1,puVar19,uVar12,4);
              *puVar19 = puVar4[4];
            }
            else {
              do {
                uVar17 = FUN_c0101c94(-0x3fec6e20,uVar12);
                if (uVar17 == 0) break;
                uVar12 = *(uint *)(uVar17 + 0x10);
              } while (uVar12 != uVar10);
              puVar6 = (uint *)(uVar17 + 0x10);
              FUN_c01029e4(-0x3fec6e20,1,puVar6,*puVar6,4);
              *puVar6 = puVar4[4];
            }
            puVar6 = puVar4 + 4;
            FUN_c01029e4(-0x3fec6e20,1,puVar6,*puVar6,4);
            *puVar6 = *local_30;
            FUN_c01029e4(-0x3fec6e20,1,local_30,*local_30,4);
            uVar10 = local_40;
            puVar6 = puVar4 + 3;
            *local_30 = local_40;
            FUN_c01029e4(-0x3fec6e20,1,puVar6,*puVar6,4);
            *puVar6 = local_30[-1];
          }
          puVar6 = FUN_c0103dc8(&DAT_c01391e0,puVar4[-3] >> 0x1c,(sVar5 + 0x10) * 2,0,0);
          if (puVar6 != (uint *)0x0) {
            puVar6[6] = puVar4[3];
            puVar6[7] = puVar4[4];
            puVar6[8] = puVar4[5];
            puVar6[9] = puVar4[6];
            *(short *)(puVar6 + 10) = (short)puVar4[7];
            *(short *)((int)puVar6 + 0x2a) = (short)sVar5;
            puVar6[3] = *puVar4;
            puVar6[4] = puVar4[1];
            *(short *)(puVar6 + 5) = (short)puVar4[2];
            local_2c = puVar6;
            memcpy(puVar6 + 0xb,local_48,sVar5 << 1);
            FUN_c0103a9c(&DAT_c01391e0,puVar6[2],uVar10);
            FUN_c01029e4(-0x3fec6e20,1,puVar6 + 1,puVar6[1],4);
            FUN_c0104fd8(&DAT_c01391e0,(int)puVar6);
            FUN_c0102aa4(&DAT_c01391e0);
            local_34 = 1;
            uVar12 = puVar6[2];
            if ((*local_2c & 0xf0000000) == 0x40000000) {
              uVar14 = 0x405;
            }
            else {
              uVar14 = 0x404;
            }
            *(undefined4 *)(param_3 + 0x458) = uVar14;
            uVar10 = FUN_c0101ea4(-0x3fec6e20,uVar10);
            *(uint *)(param_3 + 0x460) = uVar10;
            uVar10 = FUN_c0101ea4(-0x3fec6e20,puVar19[-1]);
            *(uint *)(param_3 + 0x468) = uVar10;
            *(undefined4 *)(param_3 + 0x45c) = 0x401;
            uVar10 = FUN_c0101ea4(-0x3fec6e20,uVar12);
            *(uint *)(param_3 + 0x464) = uVar10;
            uVar10 = FUN_c0101ea4(-0x3fec6e20,local_30[-1]);
            *(uint *)(param_3 + 0x46c) = uVar10;
            if (*(int *)(param_3 + 0x41c) == 0) {
              return local_34;
            }
            puVar9 = FUN_c00f6cfc(uVar12,param_3 + 0x410);
            *(undefined2 **)(param_3 + 0x420) = puVar9;
            if (puVar9 == (undefined2 *)0x0) {
              return local_34;
            }
            *(undefined4 *)(param_3 + 0x418) = 0x2001;
            return local_34;
          }
          DVar11 = 0x70;
          local_2c = (uint *)0x0;
LAB_c00f7b5c:
          SetLastError(DVar11);
          FUN_c01036ac(&DAT_c01391e0);
          return local_34;
        }
        DVar11 = 0xb7;
        goto LAB_c00f7db4;
      }
    }
    DVar11 = 0x7b;
  }
LAB_c00f7db4:
  SetLastError(DVar11);
  return local_34;
}



/* c00f7dec FUN_c00f7dec */

/* Boundary evidence: original MIPS .pdata c00f7dec..c00f7f17. Semantic name remains unreviewed. */

undefined4 FUN_c00f7dec(wchar_t *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  size_t sVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  wchar_t *local_20;
  uint *local_1c;
  
  uVar5 = 0;
  if (param_1 == (wchar_t *)0x0) {
LAB_c00f7e90:
    iVar1 = DAT_c0139420 - 0x6000;
    if (DAT_c0139420 < 0x6001) {
      iVar1 = 0;
    }
    iVar4 = DAT_c013941c - 0x6000;
    if (DAT_c013941c < 0x6001) {
      iVar4 = 0;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = iVar4;
      param_2[1] = 0;
    }
    if (param_4 != (int *)0x0) {
      *param_4 = iVar4;
      param_4[1] = 0;
    }
    if (param_3 != (int *)0x0) {
      *param_3 = iVar1;
      param_3[1] = 0;
    }
    uVar5 = 1;
  }
  else {
    iVar1 = FUN_c00f5a30(param_1,(uint *)&local_1c,&local_20);
    if (iVar1 != 0) {
      sVar2 = wcslen(local_20);
      puVar3 = FUN_c00f5804(local_1c,local_20,sVar2);
      if ((puVar3 != (uint *)0x0) && ((puVar3[-3] & 0xf0000000) == 0x40000000)) goto LAB_c00f7e90;
    }
    SetLastError(3);
  }
  return uVar5;
}



/* c00f7f18 FUN_c00f7f18 */

/* Boundary evidence: original MIPS .pdata c00f7f18..c00f823f. Semantic name remains unreviewed. */

undefined4 FUN_c00f7f18(wchar_t *param_1,uint param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  uint *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  DWORD dwErrCode;
  undefined4 uVar6;
  uint uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  wchar_t *local_30;
  uint *local_2c;
  
  iVar1 = FUN_c00f5a30(param_1,(uint *)&local_2c,&local_30);
  if (iVar1 == 0) {
    dwErrCode = 3;
  }
  else {
    sVar2 = wcslen(local_30);
    if (sVar2 == 0) {
      dwErrCode = 0x7b;
    }
    else {
      puVar3 = FUN_c00f5804(local_2c,local_30,sVar2);
      if (puVar3 != (uint *)0x0) {
        uVar11 = 4;
        if ((puVar3[-3] >> 0x1c == 5) || (puVar3[-3] >> 0x1c == 4)) {
          iVar1 = FUN_c0104fd0();
          if (iVar1 == 0) {
            return 0;
          }
          FUN_c010297c(-0x3fec6e20);
          puVar13 = puVar3 + 7;
          uVar14 = 2;
          FUN_c01029e4(-0x3fec6e20,1,puVar13,(uint)(ushort)*puVar13,2);
          uVar10 = 2;
          if ((param_2 & 2) == 0) {
            uVar10 = 0;
          }
          uVar9 = 4;
          if ((param_2 & 4) == 0) {
            uVar9 = 0;
          }
          uVar8 = 8;
          if ((param_2 & 1) == 0) {
            uVar8 = 0;
          }
          *(ushort *)puVar13 =
               (ushort)*puVar13 & 0xfff0 | uVar8 | uVar9 | uVar10 | (ushort)((param_2 & 0x20) != 0);
          if ((puVar3[-3] & 0xf0000000) == 0x50000000) {
            FUN_c01029e4(-0x3fec6e20,1,puVar3 + -2,puVar3[-2],4);
          }
          FUN_c0104fd8(&DAT_c01391e0,(int)(puVar3 + -3));
          FUN_c0102aa4(&DAT_c01391e0);
          uVar12 = puVar3[-1];
          *(undefined4 *)(param_3 + 0x458) = 0x406;
          uVar4 = FUN_c0101ea4(-0x3fec6e20,uVar12);
          *(uint *)(param_3 + 0x460) = uVar4;
          uVar4 = FUN_c0101ea4(-0x3fec6e20,puVar3[3]);
          *(uint *)(param_3 + 0x468) = uVar4;
          puVar5 = FUN_c00f6cfc(uVar12,param_3 + 0x208);
          *(undefined2 **)(param_3 + 0x41c) = puVar5;
          if (puVar5 == (undefined2 *)0x0) {
            return 1;
          }
          *(undefined4 *)(param_3 + 0x418) = 0x2001;
          *(undefined4 *)(param_3 + 0x410) = 0x24;
          if ((puVar3[-3] & 0xf0000000) == 0x40000000) {
            *(undefined4 *)(param_3 + 0x414) = 0x1000;
            uVar4 = *puVar13;
            uVar12 = 0x20;
            if ((uVar4 & 1) == 0) {
              uVar12 = 0;
            }
            if ((uVar4 & 2) == 0) {
              uVar14 = 0;
            }
            if ((uVar4 & 4) == 0) {
              uVar11 = 0;
            }
            uVar7 = 0x800;
            if ((uVar4 & 0x10) == 0) {
              uVar7 = 0;
            }
            *(uint *)(param_3 + 0x424) = uVar7 | (uVar4 & 8) != 0 | uVar11 | uVar14 | uVar12 | 0x10;
            *(uint *)(param_3 + 0x428) = puVar3[5];
            *(uint *)(param_3 + 0x42c) = puVar3[6];
            *(undefined4 *)(param_3 + 0x430) = 0;
            return 1;
          }
          *(undefined4 *)(param_3 + 0x414) = 0x2000;
          uVar11 = FUN_c00f47d4((uint)(ushort)*puVar13);
          *(uint *)(param_3 + 0x424) = uVar11;
          *(uint *)(param_3 + 0x428) = puVar3[5];
          *(uint *)(param_3 + 0x42c) = puVar3[6];
          uVar11 = FUN_c0101c94(-0x3fec6e20,uVar12);
          uVar6 = 0;
          if (uVar11 != 0) {
            uVar6 = *(undefined4 *)(uVar11 + 4);
          }
          *(undefined4 *)(param_3 + 0x430) = uVar6;
          return 1;
        }
      }
      dwErrCode = 2;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c00f8240 FUN_c00f8240 */

/* Boundary evidence: original MIPS .pdata c00f8240..c00f8367. Semantic name remains unreviewed. */

uint FUN_c00f8240(wchar_t *param_1)

{
  uint uVar1;
  int iVar2;
  size_t sVar3;
  uint *puVar4;
  uint uVar5;
  DWORD dwErrCode;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  wchar_t *local_18;
  uint *local_14;
  
  iVar2 = FUN_c00f5a30(param_1,(uint *)&local_14,&local_18);
  if (iVar2 == 0) {
    dwErrCode = 3;
  }
  else {
    sVar3 = wcslen(local_18);
    puVar4 = FUN_c00f5804(local_14,local_18,sVar3);
    if (puVar4 != (uint *)0x0) {
      if (puVar4[-3] >> 0x1c == 5) {
        uVar5 = FUN_c00f47d4((uint)(ushort)puVar4[7]);
        return uVar5;
      }
      uVar5 = 4;
      if (puVar4[-3] >> 0x1c == 4) {
        uVar1 = puVar4[7];
        uVar7 = 0x20;
        if ((uVar1 & 1) == 0) {
          uVar7 = 0;
        }
        uVar8 = 2;
        if ((uVar1 & 2) == 0) {
          uVar8 = 0;
        }
        if ((uVar1 & 4) == 0) {
          uVar5 = 0;
        }
        uVar6 = 0x800;
        if ((uVar1 & 0x10) == 0) {
          uVar6 = 0;
        }
        return uVar6 | (uVar1 & 8) != 0 | uVar5 | uVar8 | uVar7 | 0x10;
      }
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c00f8368 FUN_c00f8368 */

/* Boundary evidence: original MIPS .pdata c00f8368..c00f853f. Semantic name remains unreviewed. */

undefined4 FUN_c00f8368(uint param_1,int param_2,uint *param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = FUN_c0101c94(-0x3fec6e20,param_1);
  if (uVar2 != 0) {
    iVar3 = MatchesWildcardMask(*(undefined2 *)(param_2 + 0x14),param_2 + 0x16,
                                *(undefined2 *)(uVar2 + 0x1e),(void *)(uVar2 + 0x20));
    if (iVar3 != 0) {
      param_3[1] = *(uint *)(uVar2 + 0x14);
      param_3[2] = *(uint *)(uVar2 + 0x18);
      param_3[3] = *(uint *)(uVar2 + 0x14);
      param_3[4] = *(uint *)(uVar2 + 0x18);
      param_3[5] = *(uint *)(uVar2 + 0x14);
      param_3[6] = *(uint *)(uVar2 + 0x18);
      param_3[7] = 0;
      if ((*(uint *)(uVar2 - 0xc) & 0xf0000000) == 0x40000000) {
        uVar1 = *(ushort *)(uVar2 + 0x1c);
        uVar7 = 0x20;
        if ((uVar1 & 1) == 0) {
          uVar7 = 0;
        }
        uVar6 = 2;
        if ((uVar1 & 2) == 0) {
          uVar6 = 0;
        }
        uVar5 = 4;
        if ((uVar1 & 4) == 0) {
          uVar5 = 0;
        }
        uVar4 = 0x800;
        if ((uVar1 & 0x10) == 0) {
          uVar4 = 0;
        }
        *param_3 = uVar4 | (uVar1 & 8) != 0 | uVar5 | uVar6 | uVar7 | 0x10;
        param_3[8] = 0;
      }
      else {
        uVar7 = FUN_c00f47d4((uint)*(ushort *)(uVar2 + 0x1c));
        *param_3 = uVar7;
        uVar7 = FUN_c0101c94(-0x3fec6e20,param_1);
        uVar6 = 0;
        if (uVar7 != 0) {
          uVar6 = *(uint *)(uVar7 + 4);
        }
        param_3[8] = uVar6;
      }
      uVar7 = FUN_c0101ea4(-0x3fec6e20,param_1);
      param_3[9] = uVar7;
      uVar7 = (uint)*(ushort *)(uVar2 + 0x1e);
      if (0x103 < uVar7) {
        uVar7 = 0x103;
      }
      memcpy(param_3 + 10,(void *)(uVar2 + 0x20),uVar7 << 1);
      *(undefined2 *)((uVar7 + 0x14) * 2 + (int)param_3) = 0;
      return 1;
    }
  }
  return 0;
}



/* c00f8540 FUN_c00f8540 */

/* Boundary evidence: original MIPS .pdata c00f8540..c00f8603. Semantic name remains unreviewed. */

int FUN_c00f8540(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  while ((iVar3 != 0 && (uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(param_1 + 0xc)), uVar1 != 0))) {
    iVar2 = FUN_c00f8368(*(uint *)(param_1 + 0xc),param_1,param_2);
    iVar3 = *(int *)(uVar1 + 0x10);
    *(int *)(param_1 + 0xc) = iVar3;
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | 8;
  SetLastError(0x12);
  return 0;
}



/* c00f8604 FSD_FindNextFileW */

/* Boundary evidence: original MIPS .pdata c00f8604..c00f86cf. Semantic name remains unreviewed. */

int FSD_FindNextFileW(int param_1,uint *param_2)

{
  int iVar1;
  
                    /* 0x8604  36  FSD_FindNextFileW */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  iVar1 = FUN_c00f8540(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return iVar1;
}



/* c00f86d0 FUN_c00f86d0 */

/* Boundary evidence: original MIPS .pdata c00f86d0..c00f86db. Semantic name remains unreviewed. */

undefined4 FUN_c00f86d0(void)

{
  return 1;
}



/* c00f86dc FUN_c00f86dc */

/* Boundary evidence: original MIPS .pdata c00f86dc..c00f86e7. Semantic name remains unreviewed. */

undefined4 FUN_c00f86dc(void)

{
  return 1;
}



/* c00f86e8 FSD_FindClose */

/* Boundary evidence: original MIPS .pdata c00f86e8..c00f880f. Semantic name remains unreviewed. */

undefined4 FSD_FindClose(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x86e8  35  FSD_FindClose */
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  piVar1 = DAT_c013e7b8;
  if (DAT_c013e7b8 == param_1) {
    DAT_c013e7b8 = (int *)*param_1;
  }
  else {
    do {
      piVar2 = piVar1;
      if (piVar2 == (int *)0x0) goto LAB_c00f8770;
      piVar1 = (int *)*piVar2;
    } while ((int *)*piVar2 != param_1);
    if (piVar2 == (int *)0x0) {
LAB_c00f8770:
      SetLastError(6);
      goto LAB_c00f87a8;
    }
    *piVar2 = *param_1;
  }
  LocalFree(param_1);
  uVar3 = 1;
LAB_c00f87a8:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar3;
}



/* c00f8810 FUN_c00f8810 */

/* Boundary evidence: original MIPS .pdata c00f8810..c00f881b. Semantic name remains unreviewed. */

undefined4 FUN_c00f8810(void)

{
  return 1;
}



/* c00f881c FUN_c00f881c */

/* Boundary evidence: original MIPS .pdata c00f881c..c00f89cf. Semantic name remains unreviewed. */

undefined4 * FUN_c00f881c(wchar_t *param_1,uint *param_2)

{
  wchar_t wVar1;
  int iVar2;
  size_t sVar3;
  undefined4 *hMem;
  DWORD dwErrCode;
  uint uVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  wchar_t *local_20;
  undefined4 *local_1c;
  
  iVar2 = FUN_c00f5a30(param_1,(uint *)&local_1c,&local_20);
  if (iVar2 == 0) {
    dwErrCode = 3;
  }
  else {
    sVar3 = wcslen(local_20);
    if ((sVar3 == 0) || (0x104 < sVar3)) {
      dwErrCode = 0x7b;
    }
    else {
      hMem = LocalAlloc(0,0x220);
      if (hMem != (undefined4 *)0x0) {
        *(undefined2 *)(hMem + 2) = 0;
        pwVar6 = (wchar_t *)((int)hMem + 0x16);
        hMem[1] = 0;
        uVar4 = 0;
        *(short *)(hMem + 5) = (short)sVar3;
        if (sVar3 != 0) {
          pwVar5 = local_20 + 2;
          do {
            wVar1 = *local_20;
            *pwVar6 = wVar1;
            pwVar6 = pwVar6 + 1;
            if ((((wVar1 == L'*') && (2 < sVar3 - uVar4)) && (local_20[1] == L'.')) &&
               (*pwVar5 == L'*')) {
              local_20 = local_20 + 2;
              *(short *)(hMem + 5) = *(short *)(hMem + 5) + -2;
              uVar4 = uVar4 + 2;
              pwVar5 = pwVar5 + 2;
            }
            uVar4 = uVar4 + 1;
            local_20 = local_20 + 1;
            pwVar5 = pwVar5 + 1;
          } while (uVar4 < sVar3);
        }
        *(ushort *)(hMem + 2) = *(ushort *)(hMem + 2) | 0x20;
        hMem[4] = local_1c[-1];
        hMem[3] = *local_1c;
        iVar2 = FUN_c00f8540((int)hMem,param_2);
        if (iVar2 == 0) {
          LocalFree(hMem);
          return (undefined4 *)0xffffffff;
        }
        *hMem = DAT_c013e7b8;
        DAT_c013e7b8 = hMem;
        return hMem;
      }
      dwErrCode = 0xe;
    }
  }
  SetLastError(dwErrCode);
  return (undefined4 *)0xffffffff;
}



/* c00f89d0 FUN_c00f89d0 */

/* Boundary evidence: original MIPS .pdata c00f89d0..c00f8f57. Semantic name remains unreviewed. */

undefined4 FUN_c00f89d0(uint *param_1,wchar_t *param_2,uint *param_3,wchar_t *param_4,int param_5)

{
  size_t sVar1;
  size_t sVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined2 *puVar7;
  DWORD dwErrCode;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *local_40;
  uint *local_3c;
  uint *local_38;
  
  sVar1 = wcslen(param_2);
  if ((sVar1 != 0) && (sVar2 = wcslen(param_4), sVar2 != 0)) {
    uVar12 = *param_1;
    puVar9 = param_3;
    local_3c = param_3;
    while (uVar12 != 0) {
      puVar3 = (uint *)FUN_c0101d64(-0x3fec6e20,uVar12);
      if (puVar3 == (uint *)0x0) goto LAB_c00f8b64;
      if ((*puVar3 & 0xf0000000) == 0x50000000) {
        puVar9 = puVar3 + 3;
        iVar4 = FUN_c00fc6b0(param_2,sVar1,(wchar_t *)(puVar3 + 0xb),
                             (uint)*(ushort *)((int)puVar3 + 0x2a));
        local_3c = puVar9;
        if (iVar4 != 0) {
          iVar4 = DAT_c013a758;
          if ((puVar3[10] & 8) == 0) goto joined_r0xc00f8b30;
          goto LAB_c00f8b10;
        }
      }
      uVar12 = puVar3[7];
    }
  }
  goto LAB_c00f8ab8;
joined_r0xc00f8b30:
  if (iVar4 == 0) goto LAB_c00f8b50;
  if (*(uint *)(iVar4 + 0xc) == uVar12) goto LAB_c00f8bf8;
  iVar4 = *(int *)(iVar4 + 4);
  goto joined_r0xc00f8b30;
joined_r0xc00f8c18:
  if (iVar4 == 0) goto LAB_c00f8c38;
  if (*(uint *)(iVar4 + 0xc) == uVar11) goto LAB_c00f8bf8;
  iVar4 = *(int *)(iVar4 + 4);
  goto joined_r0xc00f8c18;
LAB_c00f8c38:
  iVar4 = FUN_c0104fd0();
  if (iVar4 == 0) {
    return 0;
  }
LAB_c00f8c4c:
  if (uVar11 != 0) {
    uVar6 = FUN_c0101ea4(-0x3fec6e20,uVar11);
    puVar7 = FUN_c00f6cfc(uVar11,param_5 + 0x208);
    *(undefined2 **)(param_5 + 0x41c) = puVar7;
    if (puVar7 != (undefined2 *)0x0) {
      *(undefined4 *)(param_5 + 0x410) = 0x24;
      *(undefined4 *)(param_5 + 0x418) = 0x2001;
      *(undefined4 *)(param_5 + 0x414) = 4;
    }
    FUN_c010297c(-0x3fec6e20);
    uVar10 = *puVar9;
    FUN_c01029e4(-0x3fec6e20,1,puVar9,uVar10,4);
    *puVar9 = *puVar3;
    FUN_c01029e4(-0x3fec6e20,1,puVar3,*puVar3,4);
    puVar9 = puVar9 + 1;
    *puVar3 = uVar10;
    uVar10 = *puVar9;
    FUN_c01029e4(-0x3fec6e20,1,puVar9,uVar10,4);
    puVar3 = local_40 + 1;
    *puVar9 = *puVar3;
    FUN_c01029e4(-0x3fec6e20,1,puVar3,*puVar3,4);
    *puVar3 = uVar10;
    puVar3 = local_3c + 2;
    uVar10 = *puVar3;
    FUN_c01029e4(-0x3fec6e20,1,puVar3,(uint)(ushort)uVar10,2);
    puVar9 = local_40 + 2;
    *(ushort *)puVar3 = (ushort)*puVar9;
    FUN_c01029e4(-0x3fec6e20,1,puVar9,(uint)(ushort)*puVar9,2);
    *(ushort *)puVar9 = (ushort)uVar10;
    puVar9 = local_3c + 6;
    FUN_c01029e4(-0x3fec6e20,1,puVar9,*puVar9,4);
    puVar3 = local_3c + 5;
    FUN_c01029e4(-0x3fec6e20,1,puVar3,*puVar3,4);
    *puVar9 = local_40[6];
    *puVar3 = local_40[5];
    FUN_c0104fd8(&DAT_c01391e0,(int)(local_3c + -3));
    puVar9 = &DAT_c013a764;
    do {
      if (*puVar9 == uVar11) {
        *puVar9 = 0;
      }
      puVar9 = puVar9 + 0x405;
    } while ((int)puVar9 < -0x3fec184c);
    FUN_c00f5b48(uVar11);
    FUN_c010297c(-0x3fec6e20);
    if (local_38 == (uint *)0x0) {
      uVar10 = 0;
    }
    else {
      uVar10 = local_38[2];
    }
    FUN_c01029e4(-0x3fec6e20,2,uVar11,param_3[-1],uVar10);
    if (local_38 == (uint *)0x0) {
      uVar10 = 0;
    }
    else {
      uVar10 = local_38[2];
    }
    FUN_c00f5bb4(uVar11,param_3[-1],uVar10);
    FUN_c0102aa4(&DAT_c01391e0);
    FUN_c0102aa4(&DAT_c01391e0);
    *(undefined4 *)(param_5 + 0x458) = 0x404;
    *(uint *)(param_5 + 0x460) = uVar6;
    uVar11 = FUN_c0101ea4(-0x3fec6e20,param_3[-1]);
    *(uint *)(param_5 + 0x468) = uVar11;
    *(undefined4 *)(param_5 + 0x45c) = 0x406;
    uVar11 = FUN_c0101ea4(-0x3fec6e20,uVar12);
    *(uint *)(param_5 + 0x464) = uVar11;
    uVar11 = FUN_c0101ea4(-0x3fec6e20,local_3c[3]);
    *(uint *)(param_5 + 0x46c) = uVar11;
    puVar7 = FUN_c00f6cfc(uVar12,param_5 + 0x410);
    *(undefined2 **)(param_5 + 0x440) = puVar7;
    if (puVar7 != (undefined2 *)0x0) {
      *(undefined4 *)(param_5 + 0x434) = 0x24;
      *(undefined4 *)(param_5 + 0x43c) = 0x2001;
      *(undefined4 *)(param_5 + 0x438) = 0x2000;
      uVar11 = FUN_c00f47d4((uint)(ushort)local_3c[7]);
      *(uint *)(param_5 + 0x448) = uVar11;
      *(uint *)(param_5 + 0x44c) = local_3c[5];
      *(uint *)(param_5 + 0x450) = local_3c[6];
      uVar12 = FUN_c0101c94(-0x3fec6e20,uVar12);
      uVar8 = 0;
      if (uVar12 != 0) {
        uVar8 = *(undefined4 *)(uVar12 + 4);
      }
      *(undefined4 *)(param_5 + 0x454) = uVar8;
      return 1;
    }
    return 1;
  }
  goto LAB_c00f8ab8;
LAB_c00f8bf8:
  dwErrCode = 5;
  goto LAB_c00f8abc;
LAB_c00f8b50:
  iVar4 = FUN_c0104fd0();
  if (iVar4 == 0) {
    return 0;
  }
LAB_c00f8b64:
  if (uVar12 != 0) {
    uVar11 = *param_3;
    local_38 = (uint *)0x0;
    puVar3 = param_3;
    local_40 = param_3;
    while (uVar11 != 0) {
      puVar5 = (uint *)FUN_c0101d64(-0x3fec6e20,uVar11);
      if (puVar5 == (uint *)0x0) goto LAB_c00f8c4c;
      if ((*puVar5 & 0xf0000000) == 0x50000000) {
        puVar3 = puVar5 + 3;
        iVar4 = FUN_c00fc6b0(param_4,sVar2,(wchar_t *)(puVar5 + 0xb),
                             (uint)*(ushort *)((int)puVar5 + 0x2a));
        local_40 = puVar3;
        if (iVar4 != 0) {
          iVar4 = DAT_c013a758;
          if ((puVar5[10] & 8) != 0) {
LAB_c00f8b10:
            SetLastError(5);
            return 0;
          }
          goto joined_r0xc00f8c18;
        }
      }
      local_38 = puVar5;
      uVar11 = puVar5[7];
    }
  }
LAB_c00f8ab8:
  dwErrCode = 3;
LAB_c00f8abc:
  SetLastError(dwErrCode);
  return 0;
}



/* c00f8f58 FUN_c00f8f58 */

/* Boundary evidence: original MIPS .pdata c00f8f58..c00f91c3. Semantic name remains unreviewed. */

undefined4 FUN_c00f8f58(uint *param_1,wchar_t *param_2,int param_3)

{
  uint *puVar1;
  size_t sVar2;
  uint *puVar3;
  int iVar4;
  undefined2 *puVar5;
  DWORD dwErrCode;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  sVar2 = wcslen(param_2);
  if (sVar2 == 0) {
    dwErrCode = 3;
  }
  else {
    uVar8 = *param_1;
    puVar1 = (uint *)0x0;
    while ((uVar8 != 0 && (puVar3 = (uint *)FUN_c0101d64(-0x3fec6e20,uVar8), puVar3 != (uint *)0x0))
          ) {
      if (((*puVar3 & 0xf0000000) == 0x50000000) &&
         (iVar4 = FUN_c00fc6b0(param_2,sVar2,(wchar_t *)(puVar3 + 0xb),
                               (uint)*(ushort *)((int)puVar3 + 0x2a)), iVar4 != 0)) {
        iVar4 = DAT_c013a758;
        if ((puVar3[10] & 8) != 0) {
          SetLastError(5);
          return 0;
        }
        while( true ) {
          if (iVar4 == 0) {
            iVar4 = FUN_c0104fd0();
            if (iVar4 == 0) {
              return 0;
            }
            puVar3 = &DAT_c013a764;
            do {
              if (*puVar3 == uVar8) {
                *puVar3 = 0;
              }
              puVar3 = puVar3 + 0x405;
            } while ((int)puVar3 < -0x3fec184c);
            FUN_c00f5b48(uVar8);
            puVar5 = FUN_c00f6cfc(uVar8,param_3 + 0x208);
            *(undefined2 **)(param_3 + 0x41c) = puVar5;
            if (puVar5 != (undefined2 *)0x0) {
              *(undefined4 *)(param_3 + 0x410) = 0x24;
              *(undefined4 *)(param_3 + 0x418) = 0x2001;
              *(undefined4 *)(param_3 + 0x414) = 4;
            }
            FUN_c010297c(-0x3fec6e20);
            if (puVar1 == (uint *)0x0) {
              uVar7 = 0;
            }
            else {
              uVar7 = puVar1[2];
            }
            FUN_c01029e4(-0x3fec6e20,2,uVar8,param_1[-1],uVar7);
            uVar7 = FUN_c0101ea4(-0x3fec6e20,uVar8);
            if (puVar1 == (uint *)0x0) {
              uVar6 = 0;
            }
            else {
              uVar6 = puVar1[2];
            }
            FUN_c00f5bb4(uVar8,param_1[-1],uVar6);
            FUN_c0102aa4(&DAT_c01391e0);
            *(uint *)(param_3 + 0x460) = uVar7;
            *(undefined4 *)(param_3 + 0x458) = 0x404;
            uVar8 = FUN_c0101ea4(-0x3fec6e20,param_1[-1]);
            *(uint *)(param_3 + 0x468) = uVar8;
            return 1;
          }
          if (*(uint *)(iVar4 + 0xc) == uVar8) break;
          iVar4 = *(int *)(iVar4 + 4);
        }
        dwErrCode = 0x20;
        goto LAB_c00f9024;
      }
      uVar8 = puVar3[7];
      puVar1 = puVar3;
    }
    dwErrCode = 2;
  }
LAB_c00f9024:
  SetLastError(dwErrCode);
  return 0;
}



/* c00f91c4 FUN_c00f91c4 */

/* Boundary evidence: original MIPS .pdata c00f91c4..c00f940f. Semantic name remains unreviewed. */

undefined4 FUN_c00f91c4(uint *param_1,wchar_t *param_2,int param_3)

{
  size_t sVar1;
  uint *puVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  sVar1 = wcslen(param_2);
  if (sVar1 != 0) {
    uVar7 = *param_1;
    puVar6 = (uint *)0x0;
    while ((uVar7 != 0 && (puVar2 = (uint *)FUN_c0101d64(-0x3fec6e20,uVar7), puVar2 != (uint *)0x0))
          ) {
      if ((*puVar2 & 0xf0000000) == 0x40000000) {
        iVar3 = FUN_c00fc6b0(param_2,sVar1,(wchar_t *)(puVar2 + 0xb),
                             (uint)*(ushort *)((int)puVar2 + 0x2a));
        if (iVar3 != 0) {
          if (puVar2[3] != 0) {
            SetLastError(0x91);
            return 0;
          }
          if ((puVar2[10] & 0x108) == 0) {
            iVar3 = FUN_c0104fd0();
            if (iVar3 == 0) {
              return 0;
            }
            FUN_c00f5b48(uVar7);
            puVar4 = FUN_c00f6cfc(uVar7,param_3 + 0x208);
            *(undefined2 **)(param_3 + 0x41c) = puVar4;
            if (puVar4 != (undefined2 *)0x0) {
              *(undefined4 *)(param_3 + 0x410) = 0x24;
              *(undefined4 *)(param_3 + 0x418) = 0x2001;
              *(undefined4 *)(param_3 + 0x414) = 0x10;
            }
            FUN_c010297c(-0x3fec6e20);
            if (puVar6 == (uint *)0x0) {
              FUN_c01029e4(-0x3fec6e20,1,param_1,*param_1,4);
              *param_1 = puVar2[7];
            }
            else {
              puVar6 = puVar6 + 7;
              FUN_c01029e4(-0x3fec6e20,1,puVar6,*puVar6,4);
              *puVar6 = puVar2[7];
            }
            uVar5 = FUN_c0101ea4(-0x3fec6e20,uVar7);
            FUN_c01037f0(&DAT_c01391e0,uVar7);
            FUN_c0102aa4(&DAT_c01391e0);
            *(uint *)(param_3 + 0x460) = uVar5;
            *(undefined4 *)(param_3 + 0x458) = 0x405;
            uVar7 = FUN_c0101ea4(-0x3fec6e20,param_1[-1]);
            *(uint *)(param_3 + 0x468) = uVar7;
            return 1;
          }
          SetLastError(5);
          return 0;
        }
      }
      uVar7 = puVar2[7];
      puVar6 = puVar2;
    }
  }
  SetLastError(3);
  return 0;
}



/* c00f9410 FUN_c00f9410 */

/* Boundary evidence: original MIPS .pdata c00f9410..c00f96b3. Semantic name remains unreviewed. */

undefined4 FUN_c00f9410(uint *param_1,wchar_t *param_2,int param_3,int param_4)

{
  size_t sVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined2 *puVar6;
  DWORD dwErrCode;
  size_t sVar7;
  undefined2 uVar8;
  
  sVar1 = wcslen(param_2);
  if ((sVar1 == 0) || (puVar2 = FUN_c00f5804(param_1,param_2,sVar1), puVar2 != (uint *)0x0)) {
    dwErrCode = 0xb7;
  }
  else {
    puVar2 = (uint *)FUN_c0101c94(-0x3fec6e20,0);
    if (((param_1 == puVar2) && (sVar1 == 5)) && (param_2[4] == L':')) {
      dwErrCode = 0x7b;
    }
    else {
      iVar3 = FUN_c00fc600((ushort *)param_2,sVar1);
      if (iVar3 == 0) {
        dwErrCode = 0x7b;
      }
      else {
        puVar4 = (uint *)FUN_c0101c94(-0x3fec6e20,0);
        sVar7 = sVar1;
        for (puVar2 = param_1; (puVar2 != (uint *)0x0 && (puVar2 != puVar4));
            puVar2 = (uint *)FUN_c0101c94(-0x3fec6e20,puVar2[3])) {
          sVar7 = (uint)*(ushort *)((int)puVar2 + 0x1e) + sVar7 + 1;
        }
        if (0x103 < (int)(sVar7 + 1)) {
          SetLastError(0xce);
          return 0;
        }
        FUN_c010297c(-0x3fec6e20);
        puVar2 = FUN_c0103dc8(&DAT_c01391e0,4,(sVar1 + 0x10) * 2,0,0);
        if (puVar2 != (uint *)0x0) {
          *(short *)((int)puVar2 + 0x2a) = (short)sVar1;
          memcpy(puVar2 + 0xb,param_2,sVar1 << 1);
          puVar2[6] = param_1[-1];
          uVar8 = 0x100;
          puVar2[7] = *param_1;
          puVar2[3] = 0;
          if (param_3 == 0) {
            uVar8 = 0;
          }
          *(undefined2 *)(puVar2 + 10) = uVar8;
          GetCurrentFT(puVar2 + 8);
          FUN_c01029e4(-0x3fec6e20,1,param_1,*param_1,4);
          *param_1 = puVar2[2];
          FUN_c0102aa4(&DAT_c01391e0);
          *(undefined4 *)(param_4 + 0x458) = 0x401;
          uVar5 = FUN_c0101ea4(-0x3fec6e20,puVar2[2]);
          *(uint *)(param_4 + 0x460) = uVar5;
          uVar5 = FUN_c0101ea4(-0x3fec6e20,puVar2[6]);
          *(uint *)(param_4 + 0x468) = uVar5;
          puVar6 = FUN_c00f6cfc(puVar2[2],param_4 + 0x208);
          *(undefined2 **)(param_4 + 0x41c) = puVar6;
          if (puVar6 != (undefined2 *)0x0) {
            *(undefined4 *)(param_4 + 0x410) = 0x24;
            *(undefined4 *)(param_4 + 0x418) = 0x2001;
            *(undefined4 *)(param_4 + 0x414) = 8;
            *(undefined4 *)(param_4 + 0x424) = 0x10;
            *(uint *)(param_4 + 0x428) = puVar2[8];
            *(uint *)(param_4 + 0x42c) = puVar2[9];
            *(undefined4 *)(param_4 + 0x430) = 0;
            return 1;
          }
          return 1;
        }
        FUN_c01036ac(&DAT_c01391e0);
        dwErrCode = 0x70;
      }
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c00f96b4 FUN_c00f96b4 */

/* Boundary evidence: original MIPS .pdata c00f96b4..c00f970f. Semantic name remains unreviewed. */

undefined4 FUN_c00f96b4(wchar_t *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *local_18;
  uint *local_14;
  
  uVar2 = 0;
  iVar1 = FUN_c00f5a30(param_1,(uint *)&local_14,&local_18);
  if (iVar1 != 0) {
    uVar2 = FUN_c00f9410(local_14,local_18,0,param_3);
  }
  return uVar2;
}



/* c00f9710 FUN_c00f9710 */

/* Boundary evidence: original MIPS .pdata c00f9710..c00f9773. Semantic name remains unreviewed. */

undefined4 FUN_c00f9710(wchar_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint *local_488;
  wchar_t *local_484;
  undefined1 auStack_480 [1136];
  uint local_10;
  
  local_10 = DAT_c0136c78;
  iVar1 = FUN_c00f5a30(param_1,(uint *)&local_488,&local_484);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_c00f9410(local_488,local_484,1,(int)auStack_480);
  }
  FUN_c013331c(local_10);
  return uVar2;
}



/* c00f9774 FUN_c00f9774 */

/* Boundary evidence: original MIPS .pdata c00f9774..c00f97d3. Semantic name remains unreviewed. */

undefined4 FUN_c00f9774(wchar_t *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *local_18;
  uint *local_14;
  
  uVar2 = 0;
  iVar1 = FUN_c00f5a30(param_1,(uint *)&local_14,&local_18);
  if ((iVar1 != 0) && (iVar1 = FUN_c00f91c4(local_14,local_18,param_2), iVar1 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* c00f97d4 FUN_c00f97d4 */

/* Boundary evidence: original MIPS .pdata c00f97d4..c00fa0b3. Semantic name remains unreviewed. */

undefined4 *
FUN_c00f97d4(wchar_t *param_1,uint param_2,uint param_3,undefined4 param_4,int param_5,uint param_6,
            undefined4 param_7,undefined4 param_8,int param_9)

{
  uint *puVar1;
  int iVar2;
  size_t sVar3;
  uint *puVar4;
  undefined4 *hMem;
  uint *puVar5;
  uint uVar6;
  undefined2 *puVar7;
  HLOCAL hMem_00;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD DVar8;
  ushort uVar9;
  ushort uVar10;
  size_t sVar11;
  ushort uVar12;
  ushort uVar13;
  uint *puVar14;
  ushort uVar15;
  wchar_t *pwVar16;
  uint *local_40;
  undefined4 *local_3c;
  wchar_t *local_38;
  uint local_34;
  uint local_30;
  
  local_3c = (undefined4 *)0xffffffff;
  local_34 = param_2;
  local_30 = param_3;
  SetLastError(0);
  iVar2 = FUN_c00f5a30(param_1,(uint *)&local_40,&local_38);
  pwVar16 = local_38;
  if (iVar2 == 0) {
    DVar8 = 3;
LAB_c00f9848:
    SetLastError(DVar8);
    return local_3c;
  }
  sVar3 = wcslen(local_38);
  if (sVar3 == 0) {
    DVar8 = 0x7b;
    goto LAB_c00f9848;
  }
  puVar4 = FUN_c00f5804(local_40,pwVar16,sVar3);
  if (puVar4 == (uint *)0x0) {
    if (param_5 == 3) {
      DVar8 = 2;
      goto LAB_c00f9848;
    }
  }
  else if ((param_5 == 1) || ((puVar4[-3] & 0xf0000000) != 0x50000000)) {
    DVar8 = 0x50;
    goto LAB_c00f9848;
  }
  if (puVar4 == (uint *)0x0) {
    if (param_5 == 5) {
      DVar8 = 2;
      goto LAB_c00f9848;
    }
  }
  else {
    SetLastError(0xb7);
    for (iVar2 = (int)DAT_c013a758; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      if ((*(uint *)(iVar2 + 0xc) == puVar4[-1]) &&
         (((((uVar15 = *(ushort *)(iVar2 + 8), (uVar15 & 4) != 0 && ((param_2 & 0x80000000) != 0))
            || (((uVar15 & 8) != 0 && (((param_2 & 0x40000000) != 0 || (param_5 == 2)))))) ||
           (((uVar15 & 1) != 0 && ((param_3 & 1) == 0)))) ||
          (((uVar15 & 2) != 0 && ((param_3 & 2) == 0)))))) {
        DVar8 = 0x20;
        goto LAB_c00f9848;
      }
    }
    if ((((param_2 & 0x40000000) != 0) || (param_5 == 2)) || (param_5 == 5)) {
      if ((puVar4[7] & 8) != 0) {
        SetLastError(5);
        return local_3c;
      }
      iVar2 = FUN_c0104fd0();
      if (iVar2 == 0) {
        return local_3c;
      }
    }
    if (((param_2 & 0x40000000) == 0) && (param_5 == 5)) {
      DVar8 = 5;
      goto LAB_c00f9848;
    }
  }
  hMem = LocalAlloc(0,0x18);
  if (hMem == (undefined4 *)0x0) {
    DVar8 = 0xe;
    goto LAB_c00f9848;
  }
  if (((puVar4 == (uint *)0x0) || (param_5 == 2)) || (param_5 == 5)) {
    if ((DAT_c0139464 == 0) || (DAT_c013a75c != 0 || (param_6 & 0x10000000) != 0)) {
      param_6 = param_6 & 0xfffff7ff | 0x10000000;
    }
    else {
      param_6 = param_6 | 0x800;
    }
  }
  if (puVar4 == (uint *)0x0) {
    puVar4 = (uint *)FUN_c0101c94(-0x3fec6e20,0);
    puVar14 = local_40;
    if ((((local_40 == puVar4) && (sVar3 == 5)) && (pwVar16[4] == L':')) ||
       (iVar2 = FUN_c00fc600((ushort *)pwVar16,sVar3), iVar2 == 0)) {
      DVar8 = 0x7b;
    }
    else {
      puVar5 = (uint *)FUN_c0101c94(-0x3fec6e20,0);
      sVar11 = sVar3;
      for (puVar4 = puVar14; (puVar4 != (uint *)0x0 && (puVar4 != puVar5));
          puVar4 = (uint *)FUN_c0101c94(-0x3fec6e20,puVar4[3])) {
        sVar11 = (uint)*(ushort *)((int)puVar4 + 0x1e) + sVar11 + 1;
      }
      if (0x103 < (int)(sVar11 + 1)) {
        SetLastError(0xce);
        goto LAB_c00f9b0c;
      }
      FUN_c010297c(-0x3fec6e20);
      puVar5 = FUN_c0103dc8(&DAT_c01391e0,5,(sVar3 + 0x10) * 2,0,0);
      local_40 = puVar5;
      if (puVar5 != (uint *)0x0) {
        puVar4 = puVar5 + 3;
        *(short *)((int)puVar5 + 0x2a) = (short)sVar3;
        memcpy(puVar5 + 0xb,pwVar16,sVar3 << 1);
        puVar5[6] = puVar14[-1];
        puVar5[7] = *puVar14;
        uVar15 = 2;
        *puVar4 = 0;
        puVar5[4] = 0;
        *(undefined2 *)(puVar5 + 5) = 0;
        if ((param_6 & 2) == 0) {
          uVar15 = 0;
        }
        uVar13 = 4;
        if ((param_6 & 4) == 0) {
          uVar13 = 0;
        }
        uVar12 = 8;
        if ((param_6 & 1) == 0) {
          uVar12 = 0;
        }
        uVar9 = 0x10;
        if ((param_6 & 0x800) == 0) {
          uVar9 = 0;
        }
        *(ushort *)(puVar5 + 10) = uVar9 | uVar12 | uVar13 | uVar15 | 1;
        GetCurrentFT(puVar5 + 8);
        FUN_c01029e4(-0x3fec6e20,1,puVar14,*puVar14,4);
        puVar1 = local_40;
        *puVar14 = local_40[2];
        FUN_c0102aa4(&DAT_c01391e0);
        uVar6 = FUN_c0101ea4(-0x3fec6e20,puVar1[2]);
        *(undefined4 *)(param_9 + 0x458) = 0x401;
        *(uint *)(param_9 + 0x460) = uVar6;
        uVar6 = FUN_c0101ea4(-0x3fec6e20,puVar5[6]);
        *(uint *)(param_9 + 0x468) = uVar6;
        puVar7 = FUN_c00f6cfc(local_40[2],param_9 + 0x208);
        *(undefined2 **)(param_9 + 0x41c) = puVar7;
        if (puVar7 != (undefined2 *)0x0) {
          *(undefined4 *)(param_9 + 0x410) = 0x24;
          *(undefined4 *)(param_9 + 0x418) = 0x2001;
          *(undefined4 *)(param_9 + 0x414) = 2;
          *(uint *)(param_9 + 0x424) = param_6;
          *(uint *)(param_9 + 0x428) = puVar5[8];
          *(uint *)(param_9 + 0x42c) = puVar5[9];
          *(undefined4 *)(param_9 + 0x430) = 0;
        }
        goto LAB_c00f9e9c;
      }
      FUN_c01036ac(&DAT_c01391e0);
      DVar8 = 0x70;
    }
    SetLastError(DVar8);
LAB_c00f9b0c:
    LocalFree(hMem);
    return local_3c;
  }
  pwVar16 = (wchar_t *)puVar4[-1];
  local_38 = pwVar16;
  FUN_c00f56bc((int)pwVar16);
  puVar14 = &DAT_c013a764;
  do {
    if ((wchar_t *)*puVar14 == pwVar16) {
      *puVar14 = 0;
    }
    puVar14 = puVar14 + 0x405;
  } while ((int)puVar14 < -0x3fec184c);
  if ((param_5 == 2) || (param_5 == 5)) {
    FUN_c010297c(-0x3fec6e20);
    pwVar16 = local_38;
    if (param_5 == 2) {
      uVar15 = 2;
      if ((param_6 & 2) == 0) {
        uVar15 = 0;
      }
      uVar13 = 4;
      if ((param_6 & 4) == 0) {
        uVar13 = 0;
      }
      uVar12 = 8;
      if ((param_6 & 1) == 0) {
        uVar12 = 0;
      }
      uVar9 = 0x10;
      if ((param_6 & 0x800) == 0) {
        uVar9 = 0;
      }
      *(ushort *)(puVar4 + 7) = uVar9 | uVar12 | uVar13 | uVar15 | 1;
    }
    if (*puVar4 != 0) {
      FUN_c01029e4(-0x3fec6e20,4,local_38,0,0);
      FUN_c00f4ce4((uint)pwVar16,0);
    }
    FUN_c0102aa4(&DAT_c01391e0);
    *(undefined4 *)(param_9 + 0x458) = 0x406;
    uVar6 = FUN_c0101ea4(-0x3fec6e20,puVar4[-1]);
    *(uint *)(param_9 + 0x460) = uVar6;
    uVar6 = FUN_c0101ea4(-0x3fec6e20,puVar4[3]);
    *(uint *)(param_9 + 0x468) = uVar6;
    puVar7 = FUN_c00f6cfc(puVar4[-1],param_9 + 0x208);
    *(undefined2 **)(param_9 + 0x41c) = puVar7;
    if (puVar7 != (undefined2 *)0x0) {
      *(undefined4 *)(param_9 + 0x410) = 0x24;
      *(undefined4 *)(param_9 + 0x418) = 0x2001;
      *(undefined4 *)(param_9 + 0x414) = 0x2000;
      uVar6 = FUN_c00f47d4((uint)(ushort)puVar4[7]);
      *(uint *)(param_9 + 0x424) = uVar6;
      *(uint *)(param_9 + 0x428) = puVar4[5];
      *(uint *)(param_9 + 0x42c) = puVar4[6];
      *(undefined4 *)(param_9 + 0x430) = 0;
    }
  }
  if ((puVar4[7] & 0x10) == 0) {
    param_6 = param_6 | 0x10000000;
  }
LAB_c00f9e9c:
  uVar13 = 2;
  uVar15 = 0x10;
  uVar6 = puVar4[-1];
  hMem[5] = &DAT_c01391e0;
  hMem[3] = uVar6;
  for (puVar4 = DAT_c0136c80; puVar4 != (uint *)0x0; puVar4 = (uint *)puVar4[3]) {
    if (uVar6 == *puVar4) goto LAB_c00f9ed8;
  }
  puVar4 = (uint *)0x0;
LAB_c00f9ed8:
  if (puVar4 == (uint *)0x0) {
    puVar4 = LocalAlloc(0x40,0x10);
    if (puVar4 == (uint *)0x0) {
      SetLastError(0xe);
    }
    else {
      *puVar4 = hMem[3];
      puVar4[1] = 0;
      puVar4[2] = 1;
      puVar4[3] = 0;
      hMem_00 = LocalAlloc(0x40,0x20);
      if (hMem_00 == (HLOCAL)0x0) {
        SetLastError(0xe);
      }
      else {
        *(undefined4 *)((int)hMem_00 + 0x14) = 0;
        *(undefined4 *)((int)hMem_00 + 0x10) = 0;
        *(undefined4 *)((int)hMem_00 + 0x18) = 0;
        *(undefined4 *)((int)hMem_00 + 0x1c) = 0;
        lpCriticalSection = LocalAlloc(0x40,0x14);
        *(LPCRITICAL_SECTION *)((int)hMem_00 + 0xc) = lpCriticalSection;
        if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
          InitializeCriticalSection(lpCriticalSection);
        }
        if (*(int *)((int)hMem_00 + 0xc) != 0) {
          puVar4[1] = (uint)hMem_00;
          puVar4[3] = (uint)DAT_c0136c80;
          DAT_c0136c80 = puVar4;
          goto LAB_c00f9fe0;
        }
        SetLastError(0xe);
        LocalFree(hMem_00);
      }
      LocalFree(puVar4);
    }
    LocalFree(hMem);
    *(undefined4 *)(param_9 + 0x418) = 0;
    return local_3c;
  }
  puVar4[2] = puVar4[2] + 1;
LAB_c00f9fe0:
  if ((local_34 & 0x40000000) == 0) {
    uVar13 = 0;
  }
  uVar12 = 0;
  if ((local_30 & 1) == 0) {
    uVar12 = 4;
  }
  uVar9 = 0;
  if ((local_30 & 2) == 0) {
    uVar9 = 8;
  }
  uVar10 = 0x80;
  if ((param_6 & 0x10000000) == 0) {
    uVar10 = 0;
  }
  if ((param_6 & 0x80000000) == 0) {
    uVar15 = 0;
  }
  *(ushort *)(hMem + 2) =
       uVar15 | uVar10 | uVar9 | uVar12 | uVar13 | (ushort)((local_34 & 0x80000000) != 0);
  *hMem = 0;
  hMem[1] = DAT_c013a758;
  DAT_c013a758 = hMem;
  return hMem;
}



/* c00fa0b4 FSD_CloseFile */

/* Boundary evidence: original MIPS .pdata c00fa0b4..c00fa46f. Semantic name remains unreviewed. */

undefined4 FSD_CloseFile(HLOCAL param_1)

{
  HLOCAL pvVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  HLOCAL pvVar5;
  undefined1 auStack_498 [520];
  undefined1 auStack_290 [520];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined2 *local_7c;
  uint local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_5c;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  uint local_28;
  
                    /* 0xa0b4  20  FSD_CloseFile */
  local_28 = DAT_c0136c78;
  local_80 = 0;
  local_5c = 0;
  local_40 = 0;
  local_3c = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c00f56bc(*(int *)((int)param_1 + 0xc));
  pvVar1 = DAT_c013a758;
  piVar2 = DAT_c0136c80;
  if (DAT_c013a758 == param_1) {
    DAT_c013a758 = *(HLOCAL *)((int)param_1 + 4);
  }
  else {
    do {
      pvVar5 = pvVar1;
      if (pvVar5 == (HLOCAL)0x0) goto LAB_c00fa17c;
      pvVar1 = *(HLOCAL *)((int)pvVar5 + 4);
    } while (*(HLOCAL *)((int)pvVar5 + 4) != param_1);
    if (pvVar5 != (HLOCAL)0x0) {
      *(undefined4 *)((int)pvVar5 + 4) = *(undefined4 *)((int)param_1 + 4);
      piVar2 = DAT_c0136c80;
    }
  }
LAB_c00fa17c:
  do {
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
LAB_c00fa1a4:
      if (piVar2 != (int *)0x0) {
        FSDMGR_RemoveFileLockEx(FUN_c00f749c,FUN_c00f75b0,param_1);
        iVar4 = piVar2[2];
        piVar2[2] = iVar4 + -1;
        if (iVar4 + -1 == 0) {
          iVar4 = piVar2[1];
          piVar2 = FUN_c00f4848(*(int *)((int)param_1 + 0xc));
          if (*(int *)(iVar4 + 0x1c) != 0) {
            FSDMGR_EmptyLockContainer(iVar4);
          }
          if (*(HANDLE *)(iVar4 + 0x14) != (HANDLE)0x0) {
            CloseHandle(*(HANDLE *)(iVar4 + 0x14));
          }
          if (*(LPCRITICAL_SECTION *)(iVar4 + 0xc) != (LPCRITICAL_SECTION)0x0) {
            DeleteCriticalSection(*(LPCRITICAL_SECTION *)(iVar4 + 0xc));
            LocalFree(*(HLOCAL *)(iVar4 + 0xc));
          }
          LocalFree((HLOCAL)piVar2[1]);
          LocalFree(piVar2);
        }
      }
      if (((*(ushort *)((int)param_1 + 8) & 0x40) != 0) &&
         (iVar4 = FUN_c0101d64(-0x3fec6e20,*(uint *)((int)param_1 + 0xc)), iVar4 != 0)) {
        FUN_c010297c(-0x3fec6e20);
        FUN_c01029e4(-0x3fec6e20,1,(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 4),4);
        FUN_c0104fd8(&DAT_c01391e0,iVar4);
        FUN_c0102aa4(&DAT_c01391e0);
        local_40 = 0x406;
        local_38 = FUN_c0101ea4(-0x3fec6e20,*(uint *)((int)param_1 + 0xc));
        local_30 = FUN_c0101ea4(-0x3fec6e20,*(uint *)(iVar4 + 0x18));
        local_7c = FUN_c00f6cfc(*(uint *)((int)param_1 + 0xc),(int)auStack_290);
        if (local_7c != (undefined2 *)0x0) {
          local_88 = 0x24;
          local_80 = 0x2001;
          local_84 = 0x2000;
          local_74 = FUN_c00f47d4((uint)*(ushort *)(iVar4 + 0x28));
          local_70 = *(undefined4 *)(iVar4 + 0x20);
          local_6c = *(undefined4 *)(iVar4 + 0x24);
          uVar3 = FUN_c0101c94(-0x3fec6e20,*(uint *)((int)param_1 + 0xc));
          local_68 = 0;
          if (uVar3 != 0) {
            local_68 = *(undefined4 *)(uVar3 + 4);
          }
        }
      }
      LocalFree(param_1);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      FUN_c00f48c8((int)auStack_498);
      FUN_c013331c(local_28);
      return 1;
    }
    if (*(int *)((int)param_1 + 0xc) == *piVar2) goto LAB_c00fa1a4;
    piVar2 = (int *)piVar2[3];
  } while( true );
}



/* c00fa470 FUN_c00fa470 */

/* Boundary evidence: original MIPS .pdata c00fa470..c00fa47b. Semantic name remains unreviewed. */

undefined4 FUN_c00fa470(void)

{
  return 1;
}



/* c00fa47c FUN_c00fa47c */

/* Boundary evidence: original MIPS .pdata c00fa47c..c00fa487. Semantic name remains unreviewed. */

undefined4 FUN_c00fa47c(void)

{
  return 1;
}



/* c00fa488 FUN_c00fa488 */

/* Boundary evidence: original MIPS .pdata c00fa488..c00fa493. Semantic name remains unreviewed. */

undefined4 FUN_c00fa488(void)

{
  return 1;
}



/* c00fa494 FSD_SetFileTime */

/* Boundary evidence: original MIPS .pdata c00fa494..c00fa7d3. Semantic name remains unreviewed. */

undefined4 FSD_SetFileTime(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 auStack_4a0 [520];
  undefined1 auStack_298 [520];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined2 *local_84;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_64;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  uint local_38;
  uint local_30;
  
                    /* 0xa494  28  FSD_SetFileTime */
  local_30 = DAT_c0136c78;
  uVar5 = 0;
  local_88 = 0;
  local_64 = 0;
  local_48 = 0;
  local_44 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c00f56bc(*(int *)(param_1 + 0xc));
  if ((*(ushort *)(param_1 + 8) & 2) == 0) {
    SetLastError(5);
    goto LAB_c00fa730;
  }
  uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(param_1 + 0xc));
  if (uVar1 == 0) {
    SetLastError(6);
    goto LAB_c00fa730;
  }
  iVar2 = FUN_c0104fd0();
  if (iVar2 == 0) goto LAB_c00fa730;
  FUN_c010297c(-0x3fec6e20);
  puVar4 = (undefined4 *)(uVar1 + 0x14);
  uVar5 = 1;
  FUN_c01029e4(-0x3fec6e20,1,puVar4,*puVar4,4);
  FUN_c01029e4(-0x3fec6e20,1,(undefined4 *)(uVar1 + 0x18),*(undefined4 *)(uVar1 + 0x18),4);
  if (param_4 == (undefined4 *)0x0) {
    if (param_2 != (undefined4 *)0x0) {
      *puVar4 = *param_2;
      uVar3 = param_2[1];
      goto LAB_c00fa640;
    }
    if (param_3 != (undefined4 *)0x0) {
      *puVar4 = *param_3;
      uVar3 = param_3[1];
      goto LAB_c00fa640;
    }
  }
  else {
    *puVar4 = *param_4;
    uVar3 = param_4[1];
LAB_c00fa640:
    *(undefined4 *)(uVar1 + 0x18) = uVar3;
  }
  FUN_c01029e4(-0x3fec6e20,1,uVar1 - 8,*(undefined4 *)(uVar1 - 8),4);
  FUN_c0104fd8(&DAT_c01391e0,uVar1 - 0xc);
  FUN_c0102aa4(&DAT_c01391e0);
  local_48 = 0x406;
  local_40 = FUN_c0101ea4(-0x3fec6e20,*(uint *)(uVar1 - 4));
  local_38 = FUN_c0101ea4(-0x3fec6e20,*(uint *)(uVar1 + 0xc));
  local_84 = FUN_c00f6cfc(*(uint *)(uVar1 - 4),(int)auStack_298);
  if (local_84 != (undefined2 *)0x0) {
    local_90 = 0x24;
    local_88 = 0x2001;
    local_8c = 0x2000;
    local_7c = FUN_c00f47d4((uint)*(ushort *)(uVar1 + 0x1c));
    local_78 = *puVar4;
    local_74 = *(undefined4 *)(uVar1 + 0x18);
    uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(uVar1 - 4));
    local_70 = 0;
    if (uVar1 != 0) {
      local_70 = *(undefined4 *)(uVar1 + 4);
    }
  }
LAB_c00fa730:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c00f48c8((int)auStack_4a0);
  FUN_c013331c(local_30);
  return uVar5;
}



/* c00fa7d4 FUN_c00fa7d4 */

/* Boundary evidence: original MIPS .pdata c00fa7d4..c00fa7df. Semantic name remains unreviewed. */

undefined4 FUN_c00fa7d4(void)

{
  return 1;
}



/* c00fa7e0 FUN_c00fa7e0 */

/* Boundary evidence: original MIPS .pdata c00fa7e0..c00fa7eb. Semantic name remains unreviewed. */

undefined4 FUN_c00fa7e0(void)

{
  return 1;
}



/* c00fa7ec FUN_c00fa7ec */

/* Boundary evidence: original MIPS .pdata c00fa7ec..c00fa977. Semantic name remains unreviewed. */

undefined4 FUN_c00fa7ec(uint *param_1,void *param_2,uint param_3,uint *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  DWORD dwErrCode;
  uint uVar3;
  
  if (((param_4 == (uint *)0x0) || (*param_4 = 0, param_2 == (void *)0x0)) || (param_5 != 0)) {
    dwErrCode = 0x57;
  }
  else if ((param_1[2] & 1) == 0) {
    dwErrCode = 5;
  }
  else {
    iVar1 = FSDMGR_TestFileLock(FUN_c00f749c,FUN_c00f75b0,param_1,1,param_3);
    if (iVar1 != 0) {
      uVar2 = FUN_c0101c94(-0x3fec6e20,param_1[3]);
      if (uVar2 != 0) {
        if (*param_1 < *(uint *)(uVar2 + 4)) {
          uVar2 = *(uint *)(uVar2 + 4) - *param_1;
          if (uVar2 < param_3) {
            param_3 = uVar2;
          }
          *param_4 = param_3;
          while (param_3 != 0) {
            uVar2 = 0x1000 - (*param_1 & 0xfff);
            if (param_3 < uVar2) {
              uVar2 = param_3;
            }
            iVar1 = FUN_c00f5eac(param_1[3],*param_1,uVar2,param_2);
            if (iVar1 == 0) {
              return 0;
            }
            uVar3 = *param_1 + uVar2;
            param_2 = (void *)(uVar2 + (int)param_2);
            param_3 = param_3 - uVar2;
            if (uVar3 < *param_1) {
              *param_1 = 0xffffffff;
            }
            else {
              *param_1 = uVar3;
            }
          }
        }
      }
      return 1;
    }
    dwErrCode = 5;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c00fa978 FSD_ReadFile */

/* Boundary evidence: original MIPS .pdata c00fa978..c00faa6b. Semantic name remains unreviewed. */

undefined4 FSD_ReadFile(uint *param_1,void *param_2,uint param_3,uint *param_4,int param_5)

{
  undefined4 uVar1;
  
                    /* 0xa978  21  FSD_ReadFile */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar1 = FUN_c00fa7ec(param_1,param_2,param_3,param_4,param_5);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar1;
}



/* c00faa6c FUN_c00faa6c */

/* Boundary evidence: original MIPS .pdata c00faa6c..c00faa77. Semantic name remains unreviewed. */

undefined4 FUN_c00faa6c(void)

{
  return 1;
}



/* c00faa78 FUN_c00faa78 */

/* Boundary evidence: original MIPS .pdata c00faa78..c00faa83. Semantic name remains unreviewed. */

undefined4 FUN_c00faa78(void)

{
  return 1;
}



/* c00faa84 FSD_ReadFileWithSeek */

/* Boundary evidence: original MIPS .pdata c00faa84..c00fabdf. Semantic name remains unreviewed. */

undefined4
FSD_ReadFileWithSeek
          (uint *param_1,void *param_2,uint param_3,uint *param_4,int param_5,uint param_6,
          int param_7)

{
  undefined4 uVar1;
  
                    /* 0xaa84  31  FSD_ReadFileWithSeek */
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((((param_2 == (void *)0x0) && (param_3 == 0)) && (param_4 == (uint *)0x0)) &&
     ((param_6 == 0 && (param_7 == 0)))) {
    uVar1 = 1;
  }
  else if (param_7 == 0) {
    *param_1 = param_6;
    uVar1 = FUN_c00fa7ec(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    SetLastError(0x57);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar1;
}



/* c00fabe0 FUN_c00fabe0 */

/* Boundary evidence: original MIPS .pdata c00fabe0..c00fabeb. Semantic name remains unreviewed. */

undefined4 FUN_c00fabe0(void)

{
  return 1;
}



/* c00fabec FUN_c00fabec */

/* Boundary evidence: original MIPS .pdata c00fabec..c00fadc7. Semantic name remains unreviewed. */

undefined4 FUN_c00fabec(uint *param_1,void *param_2,uint param_3,int *param_4,int param_5)

{
  int iVar1;
  DWORD dwErrCode;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar5 = 0;
  if (param_4 == (int *)0x0) {
    SetLastError(0x57);
    return 0;
  }
  *param_4 = 0;
  if ((param_2 == (void *)0x0) || (param_5 != 0)) {
    dwErrCode = 0x57;
  }
  else if ((param_1[2] & 2) == 0) {
    dwErrCode = 5;
  }
  else {
    iVar1 = FSDMGR_TestFileLock(FUN_c00f749c,FUN_c00f75b0,param_1,0,param_3);
    if (iVar1 != 0) {
      if (-*param_1 - 1 < param_3) {
        SetLastError(0x70);
      }
      else {
        *(ushort *)(param_1 + 2) = (ushort)param_1[2] | 0x40;
        while (param_3 != 0) {
          uVar3 = 0x1000 - (*param_1 & 0xfff);
          if (param_3 < uVar3) {
            uVar3 = param_3;
          }
          iVar1 = FUN_c00f600c(param_1[3],*param_1,uVar3 & 0xffff,param_2,(ushort)param_1[2]);
          if (iVar1 == 0) goto LAB_c00fad94;
          uVar2 = *param_1 + uVar3;
          param_3 = param_3 - uVar3;
          iVar5 = uVar3 + iVar5;
          param_2 = (void *)(uVar3 + (int)param_2);
          if (uVar2 < *param_1) {
            *param_1 = 0xffffffff;
          }
          else {
            *param_1 = uVar2;
          }
          if ((param_1[2] & 0x10) != 0) {
            FUN_c00f56bc(param_1[3]);
          }
        }
        uVar4 = 1;
      }
      goto LAB_c00fad94;
    }
    dwErrCode = 5;
  }
  SetLastError(dwErrCode);
LAB_c00fad94:
  *param_4 = iVar5;
  return uVar4;
}



/* c00fadc8 FSD_WriteFile */

/* Boundary evidence: original MIPS .pdata c00fadc8..c00faebb. Semantic name remains unreviewed. */

undefined4 FSD_WriteFile(uint *param_1,void *param_2,uint param_3,int *param_4,int param_5)

{
  undefined4 uVar1;
  
                    /* 0xadc8  22  FSD_WriteFile */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar1 = FUN_c00fabec(param_1,param_2,param_3,param_4,param_5);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar1;
}



/* c00faebc FUN_c00faebc */

/* Boundary evidence: original MIPS .pdata c00faebc..c00faec7. Semantic name remains unreviewed. */

undefined4 FUN_c00faebc(void)

{
  return 1;
}



/* c00faec8 FUN_c00faec8 */

/* Boundary evidence: original MIPS .pdata c00faec8..c00faed3. Semantic name remains unreviewed. */

undefined4 FUN_c00faec8(void)

{
  return 1;
}



/* c00faed4 FSD_WriteFileWithSeek */

/* Boundary evidence: original MIPS .pdata c00faed4..c00fb003. Semantic name remains unreviewed. */

undefined4
FSD_WriteFileWithSeek
          (uint *param_1,void *param_2,uint param_3,int *param_4,int param_5,uint param_6,
          int param_7)

{
  undefined4 uVar1;
  
                    /* 0xaed4  32  FSD_WriteFileWithSeek */
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (param_7 == 0) {
    *param_1 = param_6;
    uVar1 = FUN_c00fabec(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    SetLastError(0x57);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar1;
}



/* c00fb004 FUN_c00fb004 */

/* Boundary evidence: original MIPS .pdata c00fb004..c00fb00f. Semantic name remains unreviewed. */

undefined4 FUN_c00fb004(void)

{
  return 1;
}



/* c00fb010 FUN_c00fb010 */

/* Boundary evidence: original MIPS .pdata c00fb010..c00fb01b. Semantic name remains unreviewed. */

undefined4 FUN_c00fb010(void)

{
  return 1;
}



/* c00fb01c FUN_c00fb01c */

/* Boundary evidence: original MIPS .pdata c00fb01c..c00fb07b. Semantic name remains unreviewed. */

undefined4 FUN_c00fb01c(wchar_t *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *local_18;
  uint *local_14;
  
  uVar2 = 0;
  iVar1 = FUN_c00f5a30(param_1,(uint *)&local_14,&local_18);
  if ((iVar1 != 0) && (iVar1 = FUN_c00f8f58(local_14,local_18,param_2), iVar1 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* c00fb07c FUN_c00fb07c */

/* Boundary evidence: original MIPS .pdata c00fb07c..c00fb10f. Semantic name remains unreviewed. */

undefined4 FUN_c00fb07c(wchar_t *param_1,wchar_t *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *local_20;
  wchar_t *local_1c;
  uint *local_18;
  uint *local_14;
  
  local_1c = (wchar_t *)0x0;
  local_20 = (wchar_t *)0x0;
  uVar2 = 0;
  iVar1 = FUN_c00f5a30(param_1,(uint *)&local_14,&local_1c);
  if ((iVar1 != 0) && (iVar1 = FUN_c00f5a30(param_2,(uint *)&local_18,&local_20), iVar1 != 0)) {
    iVar1 = FUN_c00f89d0(local_14,local_1c,local_18,local_20,param_3);
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* c00fb110 FUN_c00fb110 */

/* Boundary evidence: original MIPS .pdata c00fb110..c00fb183. Semantic name remains unreviewed. */

undefined4 FUN_c00fb110(undefined4 param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  
  if (((DAT_c0136c88 == 0) ||
      (iVar1 = FSDMGR_GetVolumeName(DAT_c0136c88,param_2,param_3), iVar1 == 0)) &&
     (HVar2 = StringCchCopyW(param_2,param_3,L""), HVar2 < 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* c00fb184 FSD_MountDisk */

/* Boundary evidence: original MIPS .pdata c00fb184..c00fb29f. Semantic name remains unreviewed. */

undefined4 FSD_MountDisk(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
                    /* 0xb184  3  FSD_MountDisk */
  local_18 = DAT_c0136c78;
  iVar1 = FSDMGR_GetRegistryString(param_1,L"Folder",awStack_220,0x104);
  if (iVar1 == 0) {
    StringCchCopyW(awStack_220,0x104,L"Object Store");
  }
  iVar1 = FSDMGR_GetRegistryValue(param_1,L"DisableFileCompression",&DAT_c013a75c);
  uVar2 = 1;
  if (iVar1 == 0) {
    DAT_c013a75c = 1;
  }
  if (DAT_c0136c88 == 0) {
    local_228[0] = 0;
    DAT_c0136c84 = param_1;
    DAT_c0136c88 = FSDMGR_RegisterVolume(param_1,awStack_220,&DAT_c01391e0);
    FSDMGR_GetMountFlags(DAT_c0136c88,local_228);
    if ((local_228[0] & 4) != 0) {
      FUN_c00f9710(L"Windows");
      FUN_c00f9710(L"\\Temp");
    }
    if (DAT_c0136c88 == 0) {
      uVar2 = 0;
    }
  }
  FUN_c013331c(local_18);
  return uVar2;
}



/* c00fb2a0 FSD_UnmountDisk */

/* Boundary evidence: original MIPS .pdata c00fb2a0..c00fb2c3. Semantic name remains unreviewed. */

undefined4 FSD_UnmountDisk(void)

{
                    /* 0xb2a0  4  FSD_UnmountDisk */
  FSDMGR_DeregisterVolume(DAT_c0136c88);
  return 1;
}



/* c00fb2c4 FSD_CreateDirectoryW */

/* Boundary evidence: original MIPS .pdata c00fb2c4..c00fb3c3. Semantic name remains unreviewed. */

undefined4 FSD_CreateDirectoryW(undefined4 param_1,wchar_t *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 auStack_490 [1136];
  uint local_20;
  
                    /* 0xb2c4  5  FSD_CreateDirectoryW */
  local_20 = DAT_c0136c78;
  FUN_c00f48b4((int)auStack_490);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar1 = FUN_c00f96b4(param_2,param_3,(int)auStack_490);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c00f48c8((int)auStack_490);
  FUN_c013331c(local_20);
  return uVar1;
}



/* c00fb3c4 FUN_c00fb3c4 */

/* Boundary evidence: original MIPS .pdata c00fb3c4..c00fb3cf. Semantic name remains unreviewed. */

undefined4 FUN_c00fb3c4(void)

{
  return 1;
}



/* c00fb3d0 FUN_c00fb3d0 */

/* Boundary evidence: original MIPS .pdata c00fb3d0..c00fb3db. Semantic name remains unreviewed. */

undefined4 FUN_c00fb3d0(void)

{
  return 1;
}



/* c00fb3dc FSD_CreateFileW */

/* Boundary evidence: original MIPS .pdata c00fb3dc..c00fb64f. Semantic name remains unreviewed. */

undefined4 *
FSD_CreateFileW(undefined4 param_1,undefined4 param_2,wchar_t *param_3,uint param_4,uint param_5,
               undefined4 param_6,int param_7,uint param_8,undefined4 param_9)

{
  undefined4 *puVar1;
  undefined1 auStack_4a0 [1136];
  uint local_30;
  
                    /* 0xb3dc  6  FSD_CreateFileW */
  local_30 = DAT_c0136c78;
  if ((((param_7 == 1) || (param_7 == 2)) || (param_7 == 3)) || ((param_7 == 4 || (param_7 == 5))))
  {
    if (((param_4 & 0x1fffffff) == 0) &&
       (((param_5 & 0xfffffffc) == 0 && ((param_8 & 0x47fff758) == 0)))) {
      if (param_8 != 0x80) {
        param_8 = param_8 & 0xffffff7f;
      }
      FUN_c00f48b4((int)auStack_4a0);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      puVar1 = FUN_c00f97d4(param_3,param_4 & 0xdfffffff,param_5,param_6,param_7,param_8,param_9,
                            param_2,(int)auStack_4a0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      FUN_c00f48c8((int)auStack_4a0);
      if (puVar1 != (undefined4 *)0xffffffff) {
        puVar1 = (undefined4 *)FSDMGR_CreateFileHandle(DAT_c0136c88,param_2,puVar1);
      }
      FUN_c013331c(local_30);
      return puVar1;
    }
    SetLastError(0x57);
  }
  else {
    SetLastError(0x57);
  }
  FUN_c013331c(local_30);
  return (undefined4 *)0xffffffff;
}



/* c00fb650 FUN_c00fb650 */

/* Boundary evidence: original MIPS .pdata c00fb650..c00fb65b. Semantic name remains unreviewed. */

undefined4 FUN_c00fb650(void)

{
  return 1;
}



/* c00fb65c FUN_c00fb65c */

/* Boundary evidence: original MIPS .pdata c00fb65c..c00fb667. Semantic name remains unreviewed. */

undefined4 FUN_c00fb65c(void)

{
  return 1;
}



/* c00fb668 FSD_DeleteAndRenameFileW */

/* Boundary evidence: original MIPS .pdata c00fb668..c00fb767. Semantic name remains unreviewed. */

undefined4 FSD_DeleteAndRenameFileW(undefined4 param_1,wchar_t *param_2,wchar_t *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_490 [1136];
  uint local_20;
  
                    /* 0xb668  7  FSD_DeleteAndRenameFileW */
  local_20 = DAT_c0136c78;
  FUN_c00f48b4((int)auStack_490);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar1 = FUN_c00fb07c(param_2,param_3,(int)auStack_490);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c00f48c8((int)auStack_490);
  FUN_c013331c(local_20);
  return uVar1;
}



/* c00fb768 FUN_c00fb768 */

/* Boundary evidence: original MIPS .pdata c00fb768..c00fb773. Semantic name remains unreviewed. */

undefined4 FUN_c00fb768(void)

{
  return 1;
}



/* c00fb774 FUN_c00fb774 */

/* Boundary evidence: original MIPS .pdata c00fb774..c00fb77f. Semantic name remains unreviewed. */

undefined4 FUN_c00fb774(void)

{
  return 1;
}



/* c00fb780 FSD_DeleteFileW */

/* Boundary evidence: original MIPS .pdata c00fb780..c00fb86f. Semantic name remains unreviewed. */

undefined4 FSD_DeleteFileW(undefined4 param_1,wchar_t *param_2)

{
  undefined4 uVar1;
  undefined1 auStack_488 [1136];
  uint local_18;
  
                    /* 0xb780  8  FSD_DeleteFileW */
  local_18 = DAT_c0136c78;
  FUN_c00f48b4((int)auStack_488);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar1 = FUN_c00fb01c(param_2,(int)auStack_488);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c00f48c8((int)auStack_488);
  FUN_c013331c(local_18);
  return uVar1;
}



/* c00fb870 FUN_c00fb870 */

/* Boundary evidence: original MIPS .pdata c00fb870..c00fb87b. Semantic name remains unreviewed. */

undefined4 FUN_c00fb870(void)

{
  return 1;
}



/* c00fb87c FUN_c00fb87c */

/* Boundary evidence: original MIPS .pdata c00fb87c..c00fb887. Semantic name remains unreviewed. */

undefined4 FUN_c00fb87c(void)

{
  return 1;
}



/* c00fb888 FSD_FindFirstFileW */

/* Boundary evidence: original MIPS .pdata c00fb888..c00fb99f. Semantic name remains unreviewed. */

undefined4 *
FSD_FindFirstFileW(undefined4 param_1,undefined4 param_2,wchar_t *param_3,uint *param_4)

{
  undefined4 *puVar1;
  
                    /* 0xb888  9  FSD_FindFirstFileW */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  puVar1 = FUN_c00f881c(param_3,param_4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (puVar1 != (undefined4 *)0xffffffff) {
    puVar1 = (undefined4 *)FSDMGR_CreateSearchHandle(DAT_c0136c88,param_2,puVar1);
  }
  return puVar1;
}



/* c00fb9a0 FUN_c00fb9a0 */

/* Boundary evidence: original MIPS .pdata c00fb9a0..c00fb9ab. Semantic name remains unreviewed. */

undefined4 FUN_c00fb9a0(void)

{
  return 1;
}



/* c00fb9ac FUN_c00fb9ac */

/* Boundary evidence: original MIPS .pdata c00fb9ac..c00fb9b7. Semantic name remains unreviewed. */

undefined4 FUN_c00fb9ac(void)

{
  return 1;
}



/* c00fb9b8 FSD_GetDiskFreeSpaceW */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fb9b8..c00fbb23. Semantic name remains unreviewed. */

int FSD_GetDiskFreeSpaceW
              (undefined4 param_1,wchar_t *param_2,undefined4 *param_3,undefined4 *param_4,
              undefined4 *param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int aiStack_20 [2];
  
                    /* 0xb9b8  10  FSD_GetDiskFreeSpaceW */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  iVar1 = FUN_c00f7dec(param_2,aiStack_20,&local_28,&local_30);
  iVar4 = iVar1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar3 = _DAT_00005b04;
  if (iVar1 != 0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 1;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = uVar3;
    }
    if (param_5 != (undefined4 *)0x0) {
      uVar2 = __ull_div(local_30,local_2c,uVar3,0,iVar4);
      *param_5 = uVar2;
    }
    if (param_6 != (undefined4 *)0x0) {
      uVar3 = __ull_div(local_28,local_24,uVar3,0,iVar4);
      *param_6 = uVar3;
    }
  }
  return iVar1;
}



/* c00fbb24 FUN_c00fbb24 */

/* Boundary evidence: original MIPS .pdata c00fbb24..c00fbb2f. Semantic name remains unreviewed. */

undefined4 FUN_c00fbb24(void)

{
  return 1;
}



/* c00fbb30 FUN_c00fbb30 */

/* Boundary evidence: original MIPS .pdata c00fbb30..c00fbb3b. Semantic name remains unreviewed. */

undefined4 FUN_c00fbb30(void)

{
  return 1;
}



/* c00fbb3c FSD_GetFileAttributesW */

/* Boundary evidence: original MIPS .pdata c00fbb3c..c00fbbff. Semantic name remains unreviewed. */

uint FSD_GetFileAttributesW(undefined4 param_1,wchar_t *param_2)

{
  uint uVar1;
  
                    /* 0xbb3c  12  FSD_GetFileAttributesW */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar1 = FUN_c00f8240(param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar1;
}



/* c00fbc00 FUN_c00fbc00 */

/* Boundary evidence: original MIPS .pdata c00fbc00..c00fbc0b. Semantic name remains unreviewed. */

undefined4 FUN_c00fbc00(void)

{
  return 1;
}



/* c00fbc0c FUN_c00fbc0c */

/* Boundary evidence: original MIPS .pdata c00fbc0c..c00fbc17. Semantic name remains unreviewed. */

undefined4 FUN_c00fbc0c(void)

{
  return 1;
}



/* c00fbc18 FSD_GetVolumeInfo */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fbc18..c00fbc8f. Semantic name remains unreviewed. */

bool FSD_GetVolumeInfo(undefined4 param_1,int *param_2)

{
  int iVar1;
  
                    /* 0xbc18  13  FSD_GetVolumeInfo */
  iVar1 = *param_2;
  if (iVar1 == 0x94) {
    param_2[0x22] = 0;
    param_2[1] = 0;
    param_2[0x24] = 0x49;
    param_2[0x23] = _DAT_00005b04;
    StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 2),0x20,L"RAMFS");
    StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0x12),0x20,L"ObjectStore");
  }
  return iVar1 == 0x94;
}



/* c00fbc90 FSD_MoveFileW */

/* Boundary evidence: original MIPS .pdata c00fbc90..c00fbd8f. Semantic name remains unreviewed. */

undefined4 FSD_MoveFileW(undefined4 param_1,wchar_t *param_2,wchar_t *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_490 [1136];
  uint local_20;
  
                    /* 0xbc90  14  FSD_MoveFileW */
  local_20 = DAT_c0136c78;
  FUN_c00f48b4((int)auStack_490);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar1 = FUN_c00f7754(param_2,param_3,(int)auStack_490);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c00f48c8((int)auStack_490);
  FUN_c013331c(local_20);
  return uVar1;
}



/* c00fbd90 FUN_c00fbd90 */

/* Boundary evidence: original MIPS .pdata c00fbd90..c00fbd9b. Semantic name remains unreviewed. */

undefined4 FUN_c00fbd90(void)

{
  return 1;
}



/* c00fbd9c FUN_c00fbd9c */

/* Boundary evidence: original MIPS .pdata c00fbd9c..c00fbda7. Semantic name remains unreviewed. */

undefined4 FUN_c00fbd9c(void)

{
  return 1;
}



/* c00fbda8 FSD_Notify */

/* Boundary evidence: original MIPS .pdata c00fbda8..c00fbe4f. Semantic name remains unreviewed. */

void FSD_Notify(undefined4 param_1,uint param_2)

{
                    /* 0xbda8  15  FSD_Notify */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((param_2 & 2) != 0) {
    FUN_c00f56bc(0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return;
}



/* c00fbe50 FUN_c00fbe50 */

/* Boundary evidence: original MIPS .pdata c00fbe50..c00fbe5b. Semantic name remains unreviewed. */

undefined4 FUN_c00fbe50(void)

{
  return 1;
}



/* c00fbe5c FUN_c00fbe5c */

/* Boundary evidence: original MIPS .pdata c00fbe5c..c00fbe67. Semantic name remains unreviewed. */

undefined4 FUN_c00fbe5c(void)

{
  return 1;
}



/* c00fbe68 FSD_RegisterFileSystemFunction */

void FSD_RegisterFileSystemFunction(undefined4 param_1,undefined4 param_2)

{
                    /* 0xbe68  16  FSD_RegisterFileSystemFunction */
  DAT_c013e7b4 = param_2;
  return;
}



/* c00fbe74 FSD_RemoveDirectoryW */

/* Boundary evidence: original MIPS .pdata c00fbe74..c00fbf63. Semantic name remains unreviewed. */

undefined4 FSD_RemoveDirectoryW(undefined4 param_1,wchar_t *param_2)

{
  undefined4 uVar1;
  undefined1 auStack_488 [1136];
  uint local_18;
  
                    /* 0xbe74  17  FSD_RemoveDirectoryW */
  local_18 = DAT_c0136c78;
  FUN_c00f48b4((int)auStack_488);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar1 = FUN_c00f9774(param_2,(int)auStack_488);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c00f48c8((int)auStack_488);
  FUN_c013331c(local_18);
  return uVar1;
}



/* c00fbf64 FUN_c00fbf64 */

/* Boundary evidence: original MIPS .pdata c00fbf64..c00fbf6f. Semantic name remains unreviewed. */

undefined4 FUN_c00fbf64(void)

{
  return 1;
}



/* c00fbf70 FUN_c00fbf70 */

/* Boundary evidence: original MIPS .pdata c00fbf70..c00fbf7b. Semantic name remains unreviewed. */

undefined4 FUN_c00fbf70(void)

{
  return 1;
}



/* c00fbf7c FSD_SetFileAttributesW */

/* Boundary evidence: original MIPS .pdata c00fbf7c..c00fc077. Semantic name remains unreviewed. */

undefined4 FSD_SetFileAttributesW(undefined4 param_1,wchar_t *param_2,uint param_3)

{
  undefined4 uVar1;
  undefined1 auStack_490 [1136];
  uint local_20;
  
                    /* 0xbf7c  18  FSD_SetFileAttributesW */
  local_20 = DAT_c0136c78;
  FUN_c00f48b4((int)auStack_490);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  uVar1 = FUN_c00f7f18(param_2,param_3,(int)auStack_490);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c00f48c8((int)auStack_490);
  FUN_c013331c(local_20);
  return uVar1;
}



/* c00fc078 FUN_c00fc078 */

/* Boundary evidence: original MIPS .pdata c00fc078..c00fc083. Semantic name remains unreviewed. */

undefined4 FUN_c00fc078(void)

{
  return 1;
}



/* c00fc084 FUN_c00fc084 */

/* Boundary evidence: original MIPS .pdata c00fc084..c00fc08f. Semantic name remains unreviewed. */

undefined4 FUN_c00fc084(void)

{
  return 1;
}



/* c00fc090 FUN_c00fc090 */

/* Boundary evidence: original MIPS .pdata c00fc090..c00fc12f. Semantic name remains unreviewed. */

void FUN_c00fc090(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HRESULT HVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  size_t local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c0136c78;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  HVar1 = StringCchVPrintfW(awStack_218,0x104,param_1,(va_list)&local_res4);
  if ((-1 < HVar1) && (HVar1 = StringCchLengthW(awStack_218,0x104,local_220), -1 < HVar1)) {
    CeLogData(1,0x4a,awStack_218,(local_220[0] + 1) * 2 & 0xffff,0,0x40000000,0,0);
  }
  FUN_c013331c(local_10);
  return;
}



/* c00fc130 FUN_c00fc130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fc130..c00fc197. Semantic name remains unreviewed. */

void FUN_c00fc130(void)

{
  undefined4 local_10 [2];
  
  if (((_DAT_00005b68 & 0x20000000) != 0) && ((_DAT_00005b68 & 0x10000) != 0)) {
    local_10[0] = 10;
    CeLogData(1,0x67,local_10,4,0,0x10000,0,0);
  }
  return;
}



/* c00fc198 FUN_c00fc198 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fc198..c00fc1ff. Semantic name remains unreviewed. */

void FUN_c00fc198(void)

{
  undefined4 local_10 [2];
  
  if (((_DAT_00005b68 & 0x20000000) != 0) && ((_DAT_00005b68 & 0x10000) != 0)) {
    local_10[0] = 0xb;
    CeLogData(1,0x67,local_10,4,0,0x10000,0,0);
  }
  return;
}



/* c00fc200 FUN_c00fc200 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fc200..c00fc267. Semantic name remains unreviewed. */

void FUN_c00fc200(void)

{
  undefined4 local_10 [2];
  
  if (((_DAT_00005b68 & 0x20000000) != 0) && ((_DAT_00005b68 & 0x10000) != 0)) {
    local_10[0] = 0xc;
    CeLogData(1,0x67,local_10,4,0,0x10000,0,0);
  }
  return;
}



/* c00fc268 FUN_c00fc268 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fc268..c00fc2cf. Semantic name remains unreviewed. */

void FUN_c00fc268(void)

{
  undefined4 local_10 [2];
  
  if (((_DAT_00005b68 & 0x20000000) != 0) && ((_DAT_00005b68 & 0x10000) != 0)) {
    local_10[0] = 0xd;
    CeLogData(1,0x67,local_10,4,0,0x10000,0,0);
  }
  return;
}



/* c00fc2d0 FUN_c00fc2d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fc2d0..c00fc337. Semantic name remains unreviewed. */

void FUN_c00fc2d0(void)

{
  undefined4 local_10 [2];
  
  if (((_DAT_00005b68 & 0x20000000) != 0) && ((_DAT_00005b68 & 0x10000) != 0)) {
    local_10[0] = 0xe;
    CeLogData(1,0x67,local_10,4,0,0x10000,0,0);
  }
  return;
}



/* c00fc338 FUN_c00fc338 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fc338..c00fc41b. Semantic name remains unreviewed. */

void FUN_c00fc338(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  size_t local_228 [2];
  undefined4 local_220;
  wchar_t awStack_21c [260];
  uint local_14;
  
  local_14 = DAT_c0136c78;
  if (((_DAT_00005b68 & 0x20000000) != 0) && ((_DAT_00005b68 & 0x10000) != 0)) {
    local_228[0] = 0;
    local_220 = 0xf;
    if ((param_1 != (STRSAFE_PCNZWCH)0x0) &&
       (HVar1 = StringCchLengthW(param_1,0x104,local_228), -1 < HVar1)) {
      StringCchCopyNW(awStack_21c,0x104,param_1,local_228[0]);
      local_228[0] = local_228[0] + 1;
    }
    CeLogData(1,0x67,&local_220,(local_228[0] + 2) * 2 & 0xffff,0,0x10000,0,0);
  }
  FUN_c013331c(local_14);
  return;
}



/* c00fc41c FUN_c00fc41c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fc41c..c00fc483. Semantic name remains unreviewed. */

void FUN_c00fc41c(void)

{
  undefined4 local_10 [2];
  
  if (((_DAT_00005b68 & 0x20000000) != 0) && ((_DAT_00005b68 & 0x10000) != 0)) {
    local_10[0] = 0x28;
    CeLogData(1,0x67,local_10,4,0,0x10000,0,0);
  }
  return;
}



/* c00fc484 FUN_c00fc484 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fc484..c00fc4fb. Semantic name remains unreviewed. */

void FUN_c00fc484(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (((_DAT_00005b68 & 0x20000000) != 0) &&
     (((DAT_c0136824 & 0x20000) != 0 || ((_DAT_00005b68 & 0x1000) != 0)))) {
    if (param_2 == 0) {
      uVar1 = 0x2d;
    }
    else {
      uVar1 = 0x2b;
    }
    FUN_c00fc090(L"%cCompactVol %s",uVar1,param_1,param_4);
  }
  return;
}



/* c00fc4fc FUN_c00fc4fc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c00fc4fc..c00fc59f. Semantic name remains unreviewed. */

void FUN_c00fc4fc(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  size_t local_10 [2];
  
  if (((DAT_c0136824 & 0x20000) != 0) && ((_DAT_00005b68 & 0x20000000) != 0)) {
    local_10[0] = 0;
    HVar1 = StringCchLengthW(param_1,0x7fffffff,local_10);
    if (-1 < HVar1) {
      CeLogData(1,0x4a,param_1,(local_10[0] + 1) * 2 & 0xffff,0,0x40000000,0,0);
    }
  }
  return;
}



/* c00fc5a0 FUN_c00fc5a0 */

/* Boundary evidence: original MIPS .pdata c00fc5a0..c00fc5ff. Semantic name remains unreviewed. */

BOOL FUN_c00fc5a0(LPCWSTR param_1)

{
  BOOL BVar1;
  
  BVar1 = CreateDirectoryW(param_1,(LPSECURITY_ATTRIBUTES)0x0);
  if (BVar1 != 0) {
    SetFileAttributesW(param_1,4);
  }
  return BVar1;
}



/* c00fc600 FUN_c00fc600 */

undefined4 FUN_c00fc600(ushort *param_1,uint param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (param_2 < 0x104) {
    while (param_2 != 0) {
      uVar1 = *param_1;
      param_2 = param_2 - 1;
      if ((((((uVar1 < 0x20) || (uVar1 == 0x2a)) || (uVar1 == 0x5c)) ||
           ((uVar1 == 0x2f || (uVar1 == 0x3f)))) ||
          ((uVar1 == 0x3e || ((uVar1 == 0x3c || (uVar1 == 0x3a)))))) ||
         ((uVar1 == 0x22 || (uVar1 == 0x7c)))) goto LAB_c00fc60c;
      param_1 = param_1 + 1;
    }
    uVar2 = 1;
  }
  else {
LAB_c00fc60c:
    uVar2 = 0;
  }
  return uVar2;
}



/* c00fc6b0 FUN_c00fc6b0 */

/* Boundary evidence: original MIPS .pdata c00fc6b0..c00fc6eb. Semantic name remains unreviewed. */

undefined4 FUN_c00fc6b0(wchar_t *param_1,size_t param_2,wchar_t *param_3,size_t param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 == param_4) && (iVar1 = _wcsnicmp(param_1,param_3,param_2), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c00fc6ec FUN_c00fc6ec */

/* Boundary evidence: original MIPS .pdata c00fc6ec..c00fcdbb. Semantic name remains unreviewed. */

int FUN_c00fc6ec(void)

{
  short sVar1;
  LSTATUS LVar2;
  HLOCAL pvVar3;
  size_t sVar4;
  size_t sVar5;
  HMODULE hLibModule;
  int iVar6;
  wchar_t *_Str;
  code *pcVar7;
  undefined2 *puVar8;
  int *piVar9;
  int iVar10;
  HKEY local_30;
  DWORD local_2c;
  
  iVar10 = 0;
  if (DAT_c0136ca8 == 0) {
    hLibModule = (HMODULE)LoadDriver(L"EVENTLOG.DLL");
    if (DAT_c0136cbc != (int *)0x0) {
      return 0;
    }
    if (hLibModule == (HMODULE)0x0) {
      return 0;
    }
    DAT_c0136cbc = LocalAlloc(0x40,0x44);
    local_30 = (HKEY)hLibModule;
    pcVar7 = FreeLibrary_exref;
    if (DAT_c0136cbc != (int *)0x0) {
      memset(DAT_c0136cbc,0,0x44);
      iVar6 = GetProcAddressW(hLibModule,L"EventLogInit");
      DAT_c0136cbc[8] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogStart");
      DAT_c0136cbc[9] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogDeregisterEventSource");
      DAT_c0136cbc[6] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogRegisterEventSource");
      DAT_c0136cbc[5] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogReportEvent");
      DAT_c0136cbc[4] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogClearEventLog");
      DAT_c0136cbc[7] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogOpenEventLog");
      DAT_c0136cbc[0xb] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogCloseEventLog");
      DAT_c0136cbc[0xc] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogBackupEventLog");
      DAT_c0136cbc[0xd] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogLockEventLog");
      DAT_c0136cbc[0xe] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogUnLockEventLog");
      DAT_c0136cbc[0xf] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"EventLogReadEventLogRaw");
      DAT_c0136cbc[0x10] = iVar6;
      iVar6 = GetProcAddressW(hLibModule,L"RemoveHandlesOfProcess");
      DAT_c0136cbc[10] = iVar6;
      if ((((DAT_c0136cbc[8] == 0) || (DAT_c0136cbc[9] == 0)) || (DAT_c0136cbc[5] == 0)) ||
         (((DAT_c0136cbc[6] == 0 || (DAT_c0136cbc[4] == 0)) || (DAT_c0136cbc[7] == 0)))) {
        FreeLibrary(hLibModule);
        if (DAT_c0136cbc == (int *)0x0) {
          return 0;
        }
        LocalFree(DAT_c0136cbc);
        DAT_c0136cbc = (int *)0x0;
      }
      else {
        iVar10 = 1;
      }
      if (DAT_c0136cbc == (int *)0x0) {
        return iVar10;
      }
      (*(code *)DAT_c0136cbc[8])();
      return iVar10;
    }
LAB_c00fcb64:
    (*pcVar7)(local_30);
  }
  else {
    if (DAT_c0136ca8 < 1) {
      return 0;
    }
    if (2 < DAT_c0136ca8) {
      return 0;
    }
    if (DAT_c0136cbc == (int *)0x0) {
      return 0;
    }
    if ((*DAT_c0136cbc == 0) &&
       (LVar2 = RegOpenKeyExW((HKEY)&DAT_80000002,L"System\\ObjectStore",0,0xf003f,&local_30),
       LVar2 == 0)) {
      local_2c = 4;
      RegQueryValueExW(local_30,L"EnableEventLog",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)DAT_c0136cbc,
                       &local_2c);
      RegCloseKey(local_30);
      if (*DAT_c0136cbc == 0) {
        LocalFree(DAT_c0136cbc);
        DAT_c0136cbc = (int *)0x0;
        return 0;
      }
    }
    if ((DAT_c0136cbc[2] == 0) &&
       (LVar2 = RegOpenKeyExW((HKEY)&DAT_80000002,L"System\\ObjectStore",0,0xf003f,&local_30),
       LVar2 == 0)) {
      local_2c = 0;
      LVar2 = RegQueryValueExW(local_30,L"EventLogPath",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                               &local_2c);
      if (LVar2 == 0) {
        pvVar3 = LocalAlloc(0x40,local_2c);
        DAT_c0136cbc[2] = (int)pvVar3;
        if ((LPBYTE)DAT_c0136cbc[2] == (LPBYTE)0x0) {
          return 0;
        }
        LVar2 = RegQueryValueExW(local_30,L"EventLogPath",(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPBYTE)DAT_c0136cbc[2],&local_2c);
        if (LVar2 != 0) {
          LocalFree((HLOCAL)DAT_c0136cbc[2]);
          DAT_c0136cbc[2] = 0;
          pcVar7 = RegCloseKey_exref;
          goto LAB_c00fcb64;
        }
      }
      RegCloseKey(local_30);
    }
    if ((DAT_c0136cbc[1] == 0) &&
       (LVar2 = RegOpenKeyExW((HKEY)&DAT_80000002,L"System\\ObjectStore",0,0xf003f,&local_30),
       LVar2 == 0)) {
      local_2c = 0;
      LVar2 = RegQueryValueExW(local_30,L"EventLogStore",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                               &local_2c);
      if (LVar2 == 0) {
        pvVar3 = LocalAlloc(0x40,local_2c);
        DAT_c0136cbc[1] = (int)pvVar3;
        if ((LPBYTE)DAT_c0136cbc[1] == (LPBYTE)0x0) {
          return 0;
        }
        LVar2 = RegQueryValueExW(local_30,L"EventLogStore",(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPBYTE)DAT_c0136cbc[1],&local_2c);
        if (LVar2 != 0) {
          LocalFree((HLOCAL)DAT_c0136cbc[1]);
          DAT_c0136cbc[1] = 0;
          pcVar7 = RegCloseKey_exref;
          goto LAB_c00fcb64;
        }
      }
      RegCloseKey(local_30);
      iVar10 = 1;
    }
    piVar9 = DAT_c0136cbc;
    _Str = (wchar_t *)DAT_c0136cbc[1];
    if (((_Str != (wchar_t *)0x0) || (DAT_c0136cbc[2] != 0)) && (DAT_c0136cbc[3] == 0)) {
      if (_Str == (wchar_t *)0x0) {
        sVar4 = 0;
      }
      else {
        sVar4 = wcslen(_Str);
      }
      if ((wchar_t *)piVar9[2] == (wchar_t *)0x0) {
        sVar5 = 0;
      }
      else {
        sVar5 = wcslen((wchar_t *)piVar9[2]);
      }
      pvVar3 = LocalAlloc(0x40,(sVar5 + sVar4 + 4) * 2);
      DAT_c0136cbc[3] = (int)pvVar3;
      if (DAT_c0136cbc[1] != 0) {
        wcscpy((wchar_t *)DAT_c0136cbc[3],L"\\");
        wcscat((wchar_t *)DAT_c0136cbc[3],(wchar_t *)DAT_c0136cbc[1]);
      }
      if ((wchar_t *)DAT_c0136cbc[2] != (wchar_t *)0x0) {
        wcscat((wchar_t *)DAT_c0136cbc[3],(wchar_t *)DAT_c0136cbc[2]);
      }
      piVar9 = DAT_c0136cbc;
      sVar4 = wcslen((wchar_t *)DAT_c0136cbc[3]);
      puVar8 = (undefined2 *)(sVar4 * 2 + piVar9[3]);
      sVar1 = puVar8[-1];
      if ((sVar1 != 0x5c) && (sVar1 != 0x2f)) {
        *puVar8 = 0x5c;
        *(undefined2 *)(DAT_c0136cbc[3] + sVar4 * 2 + 2) = 0;
        piVar9 = DAT_c0136cbc;
      }
      iVar10 = (*(code *)piVar9[9])(piVar9[3]);
      if (iVar10 == 0) {
        *DAT_c0136cbc = 0;
      }
    }
  }
  return iVar10;
}



/* c00fcdbc FUN_c00fcdbc */

/* Boundary evidence: original MIPS .pdata c00fcdbc..c00fcf3f. Semantic name remains unreviewed. */

undefined4 FUN_c00fcdbc(int *param_1,undefined4 *param_2)

{
  HANDLE hFindFile;
  int iVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  DWORD local_22c;
  uint local_20;
  
  local_20 = DAT_c0136c78;
  uVar2 = 0;
  if ((param_1 == (int *)0x0) || (param_2 == (undefined4 *)0x0)) goto LAB_c00fcf14;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (*param_1 == 0) {
    if ((DAT_c0139520 == 0) ||
       (iVar1 = wcsncmp((wchar_t *)&DAT_c0139524,(wchar_t *)(param_1 + 1),0x104), iVar1 != 0)) {
      dwErrCode = 0x57;
      goto LAB_c00fcef0;
    }
    DAT_c0139520 = 0;
    uVar2 = 1;
  }
  else if (DAT_c0139520 == 0) {
    hFindFile = FindFirstFileW(L"\\",(LPWIN32_FIND_DATAW)&stack0xfffffdb0);
    if (hFindFile == (HANDLE)0xffffffff) {
      param_2[1] = 0xffffffff;
    }
    else {
      param_2[1] = local_22c;
      FindClose(hFindFile);
    }
    uVar2 = 1;
    DAT_c0139520 = 1;
    StringCchCopyW((STRSAFE_LPWSTR)&DAT_c0139524,0x104,(STRSAFE_LPCWSTR)(param_1 + 1));
    *param_2 = 8;
  }
  else {
    dwErrCode = 0x20;
LAB_c00fcef0:
    SetLastError(dwErrCode);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
LAB_c00fcf14:
  FUN_c013331c(local_20);
  return uVar2;
}



/* c00fcf40 FUN_c00fcf40 */

/* Boundary evidence: original MIPS .pdata c00fcf40..c00fd03f. Semantic name remains unreviewed. */

void FUN_c00fcf40(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = CeGetCallerTrust();
  if (iVar1 == 2) {
    if (((param_1 & 2) != 0) && (DAT_c0136c8c == 0)) {
      FUN_c0115e9c();
      FUN_c010e7d0((uint *)0x0,param_2,param_3,param_4);
      FUN_c00fe400();
      KernelLibIoControl(1,0x22,0,0,0,0,0);
      STOREMGR_NotifyFileSystems(param_1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      DAT_c0136c8c = 1;
    }
    if (((param_1 & 1) != 0) && (DAT_c0136c8c == 1)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      STOREMGR_NotifyFileSystems(param_1);
      DAT_c0136c8c = 0;
    }
  }
  else {
    SetLastError(5);
  }
  return;
}



/* c00fd040 FUN_c00fd040 */

/* Boundary evidence: original MIPS .pdata c00fd040..c00fd063. Semantic name remains unreviewed. */

void FUN_c00fd040(void)

{
  SetLastError(5);
  return;
}



/* c00fd064 FUN_c00fd064 */

/* Boundary evidence: original MIPS .pdata c00fd064..c00fd167. Semantic name remains unreviewed. */

undefined4 FUN_c00fd064(uint param_1,int param_2)

{
  HANDLE hFindFile;
  DWORD local_250 [5];
  DWORD local_23c;
  DWORD local_238;
  DWORD local_230;
  DWORD local_22c;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c0136c78;
  *(undefined2 *)(param_2 + 2) = 1;
  GetRomFileInfo(param_1 >> 0xc & 0xf,local_250,param_1 & 0xfff);
  *(DWORD *)(param_2 + 4) = local_250[0];
  *(undefined4 *)(param_2 + 8) = 0xffffffff;
  *(undefined2 *)(param_2 + 0xc) = 0x5c;
  memcpy((void *)(param_2 + 0xe),L"Windows",0xe);
  *(undefined2 *)(param_2 + 0x1c) = 0x5c;
  wcsncpy((wchar_t *)(param_2 + 0x1e),awStack_228,0xfb);
  *(DWORD *)(param_2 + 0x214) = local_23c;
  *(undefined2 *)(param_2 + 0x212) = 0;
  *(DWORD *)(param_2 + 0x218) = local_238;
  *(DWORD *)(param_2 + 0x21c) = local_230;
  hFindFile = FindFirstFileW(L"Windows",(LPWIN32_FIND_DATAW)local_250);
  if (hFindFile != (HANDLE)0xffffffff) {
    *(DWORD *)(param_2 + 8) = local_22c;
    FindClose(hFindFile);
  }
  FUN_c013331c(local_20);
  return 1;
}



/* c00fd168 FUN_c00fd168 */

/* Boundary evidence: original MIPS .pdata c00fd168..c00fd4c7. Semantic name remains unreviewed. */

uint FUN_c00fd168(uint *param_1,uint param_2,short *param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  bVar1 = false;
  uVar3 = param_2 >> 0x1c;
  CeGetCallerTrust();
  if ((param_2 == 0) || (param_2 == 0xffffffff)) {
    SetLastError(0x57);
    return 0;
  }
  if (((param_1 == (uint *)0x0) || ((param_1[3] & param_1[2] & param_1[1] & *param_1) == 0xffffffff)
      ) || (((char)*param_1 != -1 && ((param_2 & 0xc0000000) != 0x40000000)))) {
    if ((param_3 == (short *)0x0) || (*param_3 != 1)) {
      SetLastError(0x57);
      uVar2 = 0;
      goto LAB_c00fd324;
    }
    if (uVar3 == 0xe) {
      uVar2 = STOREMGR_GetOidInfoEx(param_2 & 0xffffff,param_3);
      goto LAB_c00fd324;
    }
    if (uVar3 == 3) {
      uVar2 = FUN_c01177e8((int *)param_1,param_2,param_3);
      goto LAB_c00fd324;
    }
    if (uVar3 == 8) {
      uVar2 = FUN_c01067f4(param_1,param_2,param_3);
      goto LAB_c00fd324;
    }
  }
  else {
    uVar2 = FUN_c011a188();
LAB_c00fd324:
    bVar1 = true;
  }
  if (bVar1) {
    return uVar2;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (uVar3 == 0) {
    if ((param_1 == (uint *)0x0) ||
       (((param_1[3] == 0 && param_1[2] == 0) && param_1[1] == 0) && *param_1 == 0)) {
      uVar2 = FUN_c0103434(-0x3fec6e20,param_2,(int)param_3);
      goto LAB_c00fd41c;
    }
  }
  else if (uVar3 == 1) {
    uVar2 = FUN_c00fd064(param_2,(int)param_3);
    goto LAB_c00fd41c;
  }
  SetLastError(0x57);
LAB_c00fd41c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar2;
}



/* c00fd4c8 FUN_c00fd4c8 */

/* Boundary evidence: original MIPS .pdata c00fd4c8..c00fd4d3. Semantic name remains unreviewed. */

undefined4 FUN_c00fd4c8(void)

{
  return 1;
}



/* c00fd4d4 FUN_c00fd4d4 */

/* Boundary evidence: original MIPS .pdata c00fd4d4..c00fd4df. Semantic name remains unreviewed. */

undefined4 FUN_c00fd4d4(void)

{
  return 1;
}



/* c00fd4e0 FUN_c00fd4e0 */

/* Boundary evidence: original MIPS .pdata c00fd4e0..c00fd4eb. Semantic name remains unreviewed. */

undefined4 FUN_c00fd4e0(void)

{
  return 1;
}



/* c00fd4ec FUN_c00fd4ec */

/* Boundary evidence: original MIPS .pdata c00fd4ec..c00fd713. Semantic name remains unreviewed. */

undefined4 FUN_c00fd4ec(wchar_t *param_1,int param_2)

{
  wchar_t wVar1;
  bool bVar2;
  BOOL BVar3;
  DWORD DVar4;
  wchar_t *_Str;
  wchar_t *pwVar5;
  
  wVar1 = *param_1;
  _Str = param_1;
  while (((wVar1 != L'\0' && (wVar1 != L'\\')) && (wVar1 != L'/'))) {
    _Str = _Str + 1;
    wVar1 = *_Str;
  }
  if (*_Str == L'\0') {
    _Str = (wchar_t *)0x0;
  }
  if (_Str == param_1) {
    param_1 = param_1 + 1;
    wVar1 = *param_1;
    _Str = param_1;
    while (((wVar1 != L'\0' && (wVar1 != L'\\')) && (wVar1 != L'/'))) {
      _Str = _Str + 1;
      wVar1 = *_Str;
    }
    if (*_Str == L'\0') {
      _Str = (wchar_t *)0x0;
    }
    if (_Str == param_1) {
      return 0;
    }
  }
  if ((_Str == (wchar_t *)0x0) && (param_2 == 0)) {
    _Str = wcschr(param_1,L'\0');
    pwVar5 = _Str;
  }
  else {
    pwVar5 = (wchar_t *)0x0;
  }
  bVar2 = true;
  while( true ) {
    if (_Str == (wchar_t *)0x0) {
      return 1;
    }
    if (*_Str != L'\0') {
      pwVar5 = _Str + 1;
      wVar1 = *pwVar5;
      while (((wVar1 != L'\0' && (wVar1 != L'\\')) && (wVar1 != L'/'))) {
        pwVar5 = pwVar5 + 1;
        wVar1 = *pwVar5;
      }
      if (*pwVar5 == L'\0') {
        pwVar5 = (wchar_t *)0x0;
      }
    }
    if (param_2 == 0) {
      if (pwVar5 == (wchar_t *)0x0) {
        pwVar5 = wcschr(_Str,L'\0');
      }
      else if (pwVar5 == _Str) {
        pwVar5 = (wchar_t *)0x0;
      }
    }
    wVar1 = *_Str;
    *_Str = L'\0';
    BVar3 = CreateDirectoryW(param_1,(LPSECURITY_ATTRIBUTES)0x0);
    *_Str = wVar1;
    if (((BVar3 == 0) && (DVar4 = GetLastError(), DVar4 != 0xb7)) && ((DVar4 != 0x50 && (!bVar2))))
    break;
    bVar2 = false;
    _Str = pwVar5;
  }
  return 0;
}



/* c00fd714 FUN_c00fd714 */

/* Boundary evidence: original MIPS .pdata c00fd714..c00fd9eb. Semantic name remains unreviewed. */

uint FUN_c00fd714(LPCWSTR param_1,uint param_2,LPDWORD param_3,LPCWSTR param_4,wchar_t *param_5,
                 int param_6,int param_7)

{
  wchar_t wVar1;
  LSTATUS LVar2;
  size_t sVar3;
  DWORD DVar4;
  LPCWSTR pWVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  DWORD local_244;
  uint local_240;
  DWORD local_23c;
  wchar_t local_238 [260];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  local_240 = param_2;
  if (param_1 == (LPCWSTR)0x0) {
    SetLastError(0x57);
    FUN_c013331c(local_30);
    uVar7 = 0;
  }
  else {
    local_244 = 0x206;
    LVar2 = RegQueryValueExW((HKEY)&DAT_80000002,param_4,param_3,&local_23c,(LPBYTE)local_238,
                             &local_244);
    if ((LVar2 == 0) && (local_23c == 1)) {
      param_5 = local_238;
      *(undefined2 *)((int)local_238 + (local_244 & 0xfffffffe)) = 0;
    }
    sVar3 = wcslen(param_5);
    uVar8 = sVar3 + 1;
    iVar9 = 0;
    iVar6 = 0;
    wVar1 = *param_5;
    if ((wVar1 != L'\\') && (wVar1 != L'/')) {
      iVar6 = 1;
    }
    if ((((param_6 == 0) && (1 < uVar8)) && (param_5[sVar3 - 1] != L'\\')) &&
       (param_5[sVar3 - 1] != L'/')) {
      iVar6 = iVar6 + 1;
    }
    uVar7 = iVar6 + uVar8;
    if (local_240 < uVar7) {
      SetLastError(0x7a);
    }
    else {
      pWVar5 = param_1;
      if ((wVar1 != L'\\') && (wVar1 != L'/')) {
        *param_1 = L'\\';
        pWVar5 = param_1 + 1;
        iVar9 = 1;
      }
      memcpy(pWVar5,param_5,uVar8 * 2);
      uVar7 = (iVar9 + uVar8) - 1;
      if (param_6 == 0) {
        pWVar5 = param_1 + uVar7;
        if ((pWVar5[-1] != L'\\') && (pWVar5[-1] != L'/')) {
          *pWVar5 = L'\\';
          pWVar5[1] = L'\0';
          uVar7 = iVar9 + uVar8;
        }
      }
      if (((param_7 != 0) && (uVar7 != 0)) &&
         (DVar4 = GetFileAttributesW(param_1), DVar4 == 0xffffffff)) {
        SetLastError(3);
        uVar7 = 0;
      }
    }
    FUN_c013331c(local_30);
  }
  return uVar7;
}



/* c00fd9ec FUN_c00fd9ec */

/* Boundary evidence: original MIPS .pdata c00fd9ec..c00fd9f7. Semantic name remains unreviewed. */

undefined4 FUN_c00fd9ec(void)

{
  return 1;
}



/* c00fd9f8 FUN_c00fd9f8 */

/* Boundary evidence: original MIPS .pdata c00fd9f8..c00fdb23. Semantic name remains unreviewed. */

uint FUN_c00fd9f8(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c0136c78;
  uVar1 = FUN_c00fd714(aWStack_228,0x104,(LPDWORD)L"System\\FileSys",L"TempPath",L"\\Temp\\",0,1);
  if (uVar1 < 0x104) {
    if (param_2 >> 1 < uVar1 + 1) {
      SetLastError(0x7a);
      FUN_c013331c(local_20);
      return uVar1 + 1;
    }
    if ((param_1 == 0) ||
       (iVar2 = CeSafeCopyMemory(param_1,aWStack_228,(uVar1 + 1) * 2), iVar2 != 0)) {
      FUN_c013331c(local_20);
      return uVar1;
    }
    SetLastError(0x57);
  }
  else {
    SetLastError(0xd);
  }
  FUN_c013331c(local_20);
  return 0;
}



/* c00fdb24 FUN_c00fdb24 */

/* Boundary evidence: original MIPS .pdata c00fdb24..c00fdbeb. Semantic name remains unreviewed. */

undefined4 FUN_c00fdb24(DWORD *param_1)

{
  BOOL BVar1;
  ULARGE_INTEGER local_28;
  ULARGE_INTEGER local_20;
  ULARGE_INTEGER local_18;
  
  BVar1 = GetDiskFreeSpaceExW((LPCWSTR)0x0,&local_20,&local_28,&local_18);
  if (BVar1 == 0) {
    local_20.s.LowPart = 0;
    local_28.s.LowPart = 0;
  }
  param_1[1] = local_20.s.LowPart;
  *param_1 = local_28.s.LowPart;
  return 1;
}



/* c00fdbec FUN_c00fdbec */

/* Boundary evidence: original MIPS .pdata c00fdbec..c00fdbf7. Semantic name remains unreviewed. */

undefined4 FUN_c00fdbec(void)

{
  return 1;
}



/* c00fdbf8 FUN_c00fdbf8 */

/* Boundary evidence: original MIPS .pdata c00fdbf8..c00fdffb. Semantic name remains unreviewed. */

int FUN_c00fdbf8(LPCWSTR param_1,int param_2,LPWIN32_FIND_DATAW param_3,int param_4,int param_5,
                int param_6,int param_7)

{
  undefined4 *hMem;
  int iVar1;
  size_t sVar2;
  BOOL BVar3;
  DWORD dwErrCode;
  wchar_t *_Str;
  HANDLE hFindFile;
  int iVar4;
  undefined4 uVar5;
  wchar_t local_238;
  wchar_t awStack_236 [259];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  iVar4 = -1;
  uVar5 = 0xffffffff;
  if ((((param_4 != 0x230) || (param_2 != 0)) || (2 < param_5)) ||
     ((param_6 != 0 || (param_7 != 0)))) {
    SetLastError(0x57);
    FUN_c013331c(local_30);
    return -1;
  }
  hMem = LocalAlloc(0,0x21c);
  if (hMem == (undefined4 *)0x0) {
    dwErrCode = 0xe;
  }
  else {
    hMem[3] = 0;
    if (param_5 == 2) {
      hFindFile = (HANDLE)0xffffffff;
      iVar1 = CeGetCanonicalPathNameW(param_1,&local_238,0x104,0,uVar5,0xffffffff);
      if (iVar1 == 0) {
LAB_c00fdd0c:
        LocalFree(hMem);
        goto LAB_c00fdf5c;
      }
      _Str = &local_238;
      if ((local_238 == L'\\') || (local_238 == L'/')) {
        _Str = awStack_236;
      }
      sVar2 = wcslen(_Str);
      hMem[4] = sVar2;
      if (sVar2 < 0x104) {
        memcpy(hMem + 5,_Str,(hMem[4] + 1) * 2);
        if (DAT_c0136c90 != (code *)0x0) {
          do {
            iVar1 = hMem[3];
            hMem[3] = iVar1 + 1;
            iVar1 = (*DAT_c0136c90)(iVar1,param_3);
            if (iVar1 == 0) goto LAB_c00fddb0;
            sVar2 = wcslen((wchar_t *)&param_3->dwReserved1);
            iVar1 = MatchesWildcardMask(hMem[4],hMem + 5,sVar2,&param_3->dwReserved1);
          } while (iVar1 == 0);
          goto LAB_c00fdec0;
        }
LAB_c00fddb0:
        LocalFree(hMem);
        goto LAB_c00fddbc;
      }
      LocalFree(hMem);
      dwErrCode = 0x57;
    }
    else {
      hFindFile = FindFirstFileW(param_1,param_3);
      if (hFindFile == (HANDLE)0xffffffff) goto LAB_c00fdd0c;
      if (param_5 != 1) {
LAB_c00fdec0:
        hMem[1] = hFindFile;
        hMem[2] = param_5;
        iVar4 = CreateAPIHandle(DAT_c0139504,hMem);
        if (iVar4 == 0) {
          LocalFree(hMem);
          FindClose(hFindFile);
          SetLastError(0xe);
          iVar4 = -1;
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
          *hMem = DAT_c0136c94;
          DAT_c0136c94 = hMem;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
        }
        goto LAB_c00fdf5c;
      }
      do {
        if ((param_3->dwFileAttributes & 0x10) != 0) goto LAB_c00fdec0;
        BVar3 = FindNextFileW(hFindFile,param_3);
      } while (BVar3 != 0);
      LocalFree(hMem);
      FindClose(hFindFile);
LAB_c00fddbc:
      dwErrCode = 0x12;
    }
  }
  SetLastError(dwErrCode);
LAB_c00fdf5c:
  FUN_c013331c(local_30);
  return iVar4;
}



/* c00fdffc FUN_c00fdffc */

/* Boundary evidence: original MIPS .pdata c00fdffc..c00fe007. Semantic name remains unreviewed. */

undefined4 FUN_c00fdffc(void)

{
  return 1;
}



/* c00fe008 FUN_c00fe008 */

/* Boundary evidence: original MIPS .pdata c00fe008..c00fe1ab. Semantic name remains unreviewed. */

int FUN_c00fe008(int param_1,LPWIN32_FIND_DATAW param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  BOOL BVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_3 == 0x230) {
    if (*(int *)(param_1 + 8) == 2) {
      if (DAT_c0136c90 != (code *)0x0) {
        do {
          iVar1 = (*DAT_c0136c90)(*(undefined4 *)(param_1 + 0xc),param_2);
          if (iVar1 == 0) goto LAB_c00fe0f0;
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          sVar2 = wcslen((wchar_t *)&param_2->dwReserved1);
          iVar1 = MatchesWildcardMask(*(undefined4 *)(param_1 + 0x10),param_1 + 0x14,sVar2,
                                      &param_2->dwReserved1);
        } while (iVar1 == 0);
        iVar4 = 1;
      }
LAB_c00fe0f0:
      if (iVar4 == 0) {
        SetLastError(0x12);
      }
    }
    else {
      do {
        BVar3 = FindNextFileW(*(HANDLE *)(param_1 + 4),param_2);
        if (BVar3 == 0) {
          return 0;
        }
      } while ((*(int *)(param_1 + 8) == 1) && ((param_2->dwFileAttributes & 0x10) == 0));
      iVar4 = 1;
    }
  }
  else {
    SetLastError(0x57);
    iVar4 = 0;
  }
  return iVar4;
}



/* c00fe1ac FUN_c00fe1ac */

/* Boundary evidence: original MIPS .pdata c00fe1ac..c00fe1b7. Semantic name remains unreviewed. */

undefined4 FUN_c00fe1ac(void)

{
  return 1;
}



/* c00fe1b8 FUN_c00fe1b8 */

/* Boundary evidence: original MIPS .pdata c00fe1b8..c00fe32f. Semantic name remains unreviewed. */

int FUN_c00fe1b8(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  HANDLE hFindFile;
  
  iVar3 = 0;
  hFindFile = (HANDLE)0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  piVar1 = DAT_c0136c94;
  if (DAT_c0136c94 == param_1) {
    DAT_c0136c94 = (int *)*param_1;
  }
  else {
    do {
      piVar2 = piVar1;
      if (piVar2 == (int *)0x0) goto LAB_c00fe254;
      piVar1 = (int *)*piVar2;
    } while ((int *)*piVar2 != param_1);
    if (piVar2 == (int *)0x0) {
LAB_c00fe254:
      SetLastError(6);
      goto LAB_c00fe294;
    }
    *piVar2 = *param_1;
  }
  hFindFile = (HANDLE)param_1[1];
  LocalFree(param_1);
  iVar3 = 1;
LAB_c00fe294:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((iVar3 != 0) && (hFindFile != (HANDLE)0xffffffff)) {
    FindClose(hFindFile);
  }
  return iVar3;
}



/* c00fe330 FUN_c00fe330 */

/* Boundary evidence: original MIPS .pdata c00fe330..c00fe33b. Semantic name remains unreviewed. */

undefined4 FUN_c00fe330(void)

{
  return 1;
}



/* c00fe33c FUN_c00fe33c */

/* Boundary evidence: original MIPS .pdata c00fe33c..c00fe3ff. Semantic name remains unreviewed. */

void FUN_c00fe33c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = param_2;
  STOREMGR_ProcNotify(param_1);
  if (param_1 == 0) {
    FUN_c01091a8(param_2);
    FUN_c0105010(param_2);
    FUN_c0117900(param_2,iVar1,param_3,param_4);
    FUN_c0118be4(param_2);
    FUN_c01100f4(0,param_2);
    if (DAT_c0136cbc != 0) {
      (**(code **)(DAT_c0136cbc + 0x28))(param_2);
    }
  }
  else if ((param_1 != 4) && (param_1 == 6)) {
    CompactAllHeaps();
  }
  return;
}



/* c00fe400 FUN_c00fe400 */

void FUN_c00fe400(void)

{
  return;
}



/* c00fe408 FUN_c00fe408 */

/* Boundary evidence: original MIPS .pdata c00fe408..c00fe673. Semantic name remains unreviewed. */

uint FUN_c00fe408(int param_1,int param_2,int *param_3,uint param_4,int *param_5,uint param_6)

{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  
  if (param_2 == 0x90080) {
    if (param_3 == (int *)0x0) {
      return 0;
    }
    if (param_4 < 4) {
      return 0;
    }
    if (param_5 == (int *)0x0) {
      return 0;
    }
    if (param_6 < 0x90) {
      return 0;
    }
    if ((*param_3 == 0) && (*param_5 == 0x90)) {
      param_5[1] = 0;
      param_5[3] = 0x1000;
      param_5[2] = 8;
      memset(param_5 + 0x14,0,4);
      memset(param_5 + 4,0,4);
      return 1;
    }
  }
  else {
    if (param_2 == 0x90084) {
      FUN_c0115e9c();
      FUN_c010e7d0((uint *)0x0,param_2,param_3,param_4);
      FUN_c00fe400();
      KernelLibIoControl(1,0x22,0,0,0,0,0);
      return 0;
    }
    if (param_2 == 0x9008c) {
      if (param_3 == (int *)0x0) {
        return 0;
      }
      if (param_4 < 4) {
        return 0;
      }
      if (param_5 == (int *)0x0) {
        return 0;
      }
      if (param_6 < 0x14) {
        return 0;
      }
      bVar1 = FUN_c01099cc((uint *)*param_3,param_1,param_5);
      return CONCAT31(extraout_var,bVar1);
    }
    if (param_2 == 0x90094) {
      if ((((param_3 != (int *)0x0) && (param_4 == 0x20c)) && (param_5 != (int *)0x0)) &&
         (param_6 == 8)) {
        uVar2 = FUN_c00fcdbc(param_3,param_5);
        return uVar2;
      }
    }
    else {
      if (param_2 != 0x9009c) {
        SetLastError(0x57);
        return 0;
      }
      if ((param_3 != (int *)0x0) && (param_4 == 0x28)) {
        uVar2 = FUN_c01019f0(param_3);
        return uVar2;
      }
    }
  }
  SetLastError(0x57);
  return 0;
}



/* c00fe674 FUN_c00fe674 */

/* Boundary evidence: original MIPS .pdata c00fe674..c00fe67f. Semantic name remains unreviewed. */

undefined4 FUN_c00fe674(void)

{
  return 1;
}



/* c00fe680 FUN_c00fe680 */

/* Boundary evidence: original MIPS .pdata c00fe680..c00fe72f. Semantic name remains unreviewed. */

void FUN_c00fe680(int param_1,int param_2,int *param_3,uint param_4,int *param_5,uint param_6,
                 undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  
  iVar1 = __GetUserKData(0xc);
  if (param_1 == 0) {
    FUN_c00fe408(iVar1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    STOREMGR_FsIoControlW(iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return;
}



/* c00fe730 FUN_c00fe730 */

/* Boundary evidence: original MIPS .pdata c00fe730..c00fe7db. Semantic name remains unreviewed. */

void FUN_c00fe730(int param_1,int param_2,int *param_3,uint param_4,int *param_5,uint param_6,
                 undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  
  iVar1 = GetCallerVMProcessId();
  if (param_1 == 0) {
    FUN_c00fe408(iVar1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    STOREMGR_FsIoControlW(iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return;
}



/* c00fe7dc FUN_c00fe7dc */

/* Boundary evidence: original MIPS .pdata c00fe7dc..c00fe80b. Semantic name remains unreviewed. */

bool FUN_c00fe7dc(void)

{
  int iVar1;
  
  iVar1 = STOREMGR_StartBootPhase();
  return iVar1 == 0;
}



/* c00fe80c FUN_c00fe80c */

/* Boundary evidence: original MIPS .pdata c00fe80c..c00fea07. Semantic name remains unreviewed. */

void FUN_c00fe80c(void)

{
  LSTATUS LVar1;
  DWORD DVar2;
  int iVar3;
  DWORD local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c0136c78;
  local_228[0] = 0x208;
  LVar1 = RegQueryValueExW((HKEY)&DAT_80000002,L"OEMFSDll",(LPDWORD)L"System\\ObjectStore",
                           (LPDWORD)0x0,(LPBYTE)awStack_220,local_228);
  if (LVar1 != 0) {
    StringCchCopyW(awStack_220,0x104,L"\\windows\\oemregistry.dll");
  }
  DVar2 = GetFileAttributesW(awStack_220);
  if ((DVar2 != 0xffffffff) && ((DVar2 & 4) != 0)) {
    DAT_c0136d30 = LoadDriver(awStack_220);
    if (DAT_c0136d30 != 0) {
      iVar3 = GetProcAddressW(DAT_c0136d30,L"ReadRegData");
      if (iVar3 != 0) {
        DAT_c0136d24 = GetProcAddressW(DAT_c0136d30,L"ReadRegData");
      }
      iVar3 = GetProcAddressW(DAT_c0136d30,L"WriteRegData");
      if (iVar3 != 0) {
        DAT_c0136d28 = GetProcAddressW(DAT_c0136d30,L"WriteRegData");
      }
      iVar3 = GetProcAddressW(DAT_c0136d30,L"ReadGenericData");
      if (iVar3 != 0) {
        DAT_c0136ca0 = GetProcAddressW(DAT_c0136d30,L"ReadGenericData");
      }
      iVar3 = GetProcAddressW(DAT_c0136d30,L"WriteGenericData");
      if (iVar3 != 0) {
        DAT_c0136ca4 = GetProcAddressW(DAT_c0136d30,L"WriteGenericData");
      }
      DAT_c0136d2c = (code *)GetProcAddressW(DAT_c0136d30,L"RegistryOperation");
      if (DAT_c0136d2c != (code *)0x0) {
        FUN_c01123f8((wchar_t *)0x0);
        (*DAT_c0136d2c)(5);
        FUN_c00fc268();
      }
    }
  }
  FUN_c013331c(local_18);
  return;
}



/* c00fea08 FUN_c00fea08 */

/* Boundary evidence: original MIPS .pdata c00fea08..c00feaab. Semantic name remains unreviewed. */

undefined4 FUN_c00fea08(LPCWSTR param_1,int *param_2,DWORD param_3)

{
  HLOCAL pvVar1;
  LSTATUS LVar2;
  DWORD local_res8 [2];
  DWORD aDStack_18 [2];
  
  local_res8[0] = param_3;
  if (*param_2 == 0) {
    pvVar1 = LocalAlloc(0,0x208);
    *param_2 = (int)pvVar1;
    if (pvVar1 == (HLOCAL)0x0) {
      return 0;
    }
    local_res8[0] = 0x208;
  }
  LVar2 = RegQueryValueExW((HKEY)&DAT_80000002,param_1,(LPDWORD)L"init\\BootVars",aDStack_18,
                           (LPBYTE)*param_2,local_res8);
  if (LVar2 != 0) {
    return 0;
  }
  return 1;
}



/* c00feaac FUN_c00feaac */

/* Boundary evidence: original MIPS .pdata c00feaac..c00febeb. Semantic name remains unreviewed. */

undefined4 FUN_c00feaac(undefined4 param_1,STRSAFE_LPWSTR param_2,size_t param_3,undefined4 param_4)

{
  HANDLE hObject;
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  undefined4 uVar4;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c [2];
  undefined4 local_154;
  undefined4 local_150;
  undefined1 auStack_148 [28];
  wchar_t awStack_12c [132];
  uint local_24;
  
  local_24 = DAT_c0136c78;
  uVar4 = 0;
  memset(local_15c,0,0x10);
  local_160 = 0x14;
  local_15c[0] = 0;
  local_154 = 0x124;
  local_150 = 1;
  hObject = (HANDLE)CreateMsgQueue(0,&local_160);
  if (hObject != (HANDLE)0x0) {
    iVar1 = RequestDeviceNotifications(param_1,hObject,1);
    if (iVar1 != 0) {
      local_168 = 0;
      local_164 = 0;
      iVar2 = ReadMsgQueue(hObject,auStack_148,0x124,&local_168,param_4,&local_164);
      uVar4 = 0;
      if (iVar2 != 0) {
        HVar3 = StringCchCopyW(param_2,param_3,awStack_12c);
        uVar4 = 1;
        if (HVar3 < 0) {
          uVar4 = 0;
        }
      }
      StopDeviceNotifications(iVar1);
    }
    CloseHandle(hObject);
  }
  FUN_c013331c(local_24);
  return uVar4;
}



/* c00febec FUN_c00febec */

/* Boundary evidence: original MIPS .pdata c00febec..c00ff6cb. Semantic name remains unreviewed. */

undefined4 FUN_c00febec(ushort *param_1)

{
  undefined *_Dst;
  HMODULE hLibModule;
  int iVar1;
  BOOL BVar2;
  HANDLE pvVar3;
  undefined4 uVar4;
  LSTATUS LVar5;
  ushort **local_348;
  ushort *local_344;
  undefined *local_340;
  int *local_33c;
  undefined *local_338;
  undefined *local_334;
  undefined4 *local_330;
  undefined **local_32c;
  undefined *local_328;
  undefined **local_324;
  ushort *local_320;
  HKEY local_31c;
  undefined4 local_318 [2];
  SYSTEMTIME local_310;
  DWORD aDStack_300 [2];
  undefined1 auStack_2f8 [8];
  _FILETIME _Stack_2f0;
  _TIME_ZONE_INFORMATION local_2e8;
  ushort *apuStack_238 [130];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  local_344 = param_1;
  RegisterDbgZones(DAT_c0136c9c,u_FileSys_c01363e4);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  local_33c = &DAT_c0139520;
  DAT_c0139520 = 0;
  local_334 = &DAT_c01394a0;
  memset(&DAT_c01394a0,-1,0x10);
  memset(&DAT_c01394c0,0xff,0x40);
  DAT_c01394c0 = 0x40;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c01394c4);
  FUN_c011059c();
  local_348 = (ushort **)FUN_c011d730();
  DAT_c01391e0 = 0;
  DAT_c01391e4 = 0;
  DAT_c01393fc = &DAT_c013a740;
  DAT_c0139404 = &DAT_c0139740;
  DAT_c0139400 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  wcscpy((wchar_t *)&DAT_c01391f0,L"SystemHeap");
  memset(&DAT_c013943c,0,0x10);
  hLibModule = LoadLibraryW(L"coredll.dll");
  if (hLibModule != (HMODULE)0x0) {
    DAT_c0136c90 = GetProcAddressW(hLibModule,L"GetDeviceByIndex");
    FreeLibrary(hLibModule);
    iVar1 = FUN_c0102258(&DAT_c01391e0,0,0);
    if (iVar1 != 0) {
      if (*(int *)(DAT_c01391e8 + 8) != 0x4d494b45) {
        DAT_c0136c98 = 1;
      }
      local_324 = &PTR_FUN_c00f1ca8;
      local_328 = &DAT_c00f2278;
      local_32c = &PTR_FUN_c00f17f4;
      local_338 = &DAT_c00f1cb8;
      local_340 = &DAT_c00f2270;
      local_330 = &DAT_c0136cb0;
      do {
        if (DAT_c0136c98 == 0) {
          iVar1 = FUN_c0104764(&DAT_c01391e0);
          if (iVar1 != 0) goto LAB_c00fefc8;
        }
        else {
          local_310.wYear = 0x7d6;
          local_310.wMonth = 1;
          local_310.wDayOfWeek = 0;
          local_310.wDay = 1;
          local_310.wHour = 0xc;
          local_310.wMinute = 0;
          local_310.wSecond = 0;
          local_310.wMilliseconds = 0;
          BVar2 = SystemTimeToFileTime(&local_310,&_Stack_2f0);
          if (BVar2 != 0) {
            FileTimeToSystemTime(&_Stack_2f0,&local_310);
          }
          KernelIoControl(0x1010038,&local_310,0x10,0,0,auStack_2f8);
          iVar1 = FUN_c01031b8(&DAT_c01391e0,7);
          if (iVar1 == 0) break;
LAB_c00fefc8:
          DAT_c0139464 = 1;
          KernelLibIoControl(1,3,0,0,&DAT_c0139464,4,0);
          FSD_FsIoControl();
          pvVar3 = HeapCreate(0x1000,0,0);
          *local_330 = pvVar3;
          if (DAT_c013a754 == 0) {
            DAT_c013a754 = CreateAPISet(local_340,0x95,&PTR_FUN_c00f134c,&DAT_c00f1800);
            RegisterDirectMethods(DAT_c013a754,&PTR_FUN_c00f15a0);
            RegisterAPISet(DAT_c013a754,0x54);
          }
          if (DAT_c0139504 == 0) {
            DAT_c0139504 = CreateAPISet(local_328,3,local_32c,local_338);
            RegisterDirectMethods(DAT_c0139504,local_324);
            RegisterAPISet(DAT_c0139504,0x80000008);
          }
          FUN_c011db90();
          STOREMGR_Initialize();
          FUN_c00fc198();
          FUN_c00fc6ec();
          iVar1 = FUN_c0109650(0,param_1);
          if ((iVar1 != 0) || (iVar1 = FUN_c0109650(1,param_1), iVar1 != 0)) {
            FUN_c011d4fc();
            FUN_c0116f84();
            if (local_348 == (ushort **)0x0) {
              local_344 = (ushort *)0x0;
              local_348 = &local_344;
              iVar1 = FUN_c00fea08(L"RequireCertMod",(int *)&local_348,4);
              if ((iVar1 != 0) && (local_344 == (ushort *)0x1)) {
                NKDbgPrintfW(L"Certmod load error.  Certmod is required !!! Boot halted\r\n");
                do {
                    /* WARNING: Do nothing block with infinite loop */
                } while( true );
              }
            }
            uVar4 = FUN_c011d8ac(&PTR_u_rsaenh_dll_c0136828);
            FUN_c0115e78();
            FUN_c011d8ac(uVar4);
            local_320 = (ushort *)0x0;
            local_348 = &local_320;
            iVar1 = FUN_c00fea08(L"NoDefaultUser",(int *)&local_348,4);
            if ((iVar1 == 0) || (local_320 == (ushort *)0x0)) {
              local_348 = apuStack_238;
              FUN_c00fc4fc(L"Logging in default user");
              iVar1 = FUN_c00fea08(L"DefaultUser",(int *)&local_348,0x208);
              if (iVar1 == 0) {
                wcscpy((wchar_t *)apuStack_238,L"default");
              }
              SetCurrentUser(apuStack_238,0,0,1);
            }
            FUN_c00fc268();
            FUN_c00fe80c();
            DAT_c0136ca8 = 2;
            KernelLibIoControl(1,0x1d,0,0,0,0,0);
            FUN_c00fe400();
            FUN_c00fc6ec();
            if ((*param_1 & 4) == 0) {
              InitLocale();
            }
            else {
              ReinitLocale();
            }
            STOREMGR_StartBootPhase(2);
            FUN_c011d4fc();
            FUN_c01179a0();
            FSD_FsIoControl();
            FUN_c011d800();
            if (DAT_c0136c98 != 0) {
              FUN_c00fc200();
            }
            GetTimeZoneInformation(&local_2e8);
            SetTimeZoneBias(local_2e8.StandardBias + local_2e8.Bias,
                            local_2e8.DaylightBias + local_2e8.Bias);
            local_318[0] = 0;
            if ((local_2e8.StandardDate.wMonth != 0) && (local_2e8.DaylightDate.wMonth != 0)) {
              aDStack_300[1] = 4;
              LVar5 = RegCreateKeyExW((HKEY)&DAT_80000002,L"Software\\Microsoft\\Clock",0,L"Prefs",0
                                      ,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_31c,aDStack_300);
              if (LVar5 == 0) {
                RegQueryValueExW(local_31c,L"HomeDST",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_318,
                                 aDStack_300 + 1);
                RegCloseKey(local_31c);
              }
            }
            SetDaylightTime(local_318[0]);
            _Dst = local_334;
            if ((*local_33c != 0) &&
               (iVar1 = CeFsIoControlW(local_33c + 1,0x900a0,0,0,local_334,0x10,0,0), iVar1 == 0)) {
              memset(_Dst,-1,0x10);
            }
            FUN_c013331c(local_30);
            return 1;
          }
        }
        DAT_c0136c98 = 1;
        NotifyForceCleanboot();
        DAT_c0136c98 = 1;
      } while( true );
    }
  }
  FUN_c013331c(local_30);
  return 0;
}



/* c00ff6cc FUN_c00ff6cc */

/* Boundary evidence: original MIPS .pdata c00ff6cc..c00ff6d7. Semantic name remains unreviewed. */

undefined4 FUN_c00ff6cc(void)

{
  return 1;
}



/* c00ff6d8 FUN_c00ff6d8 */

/* Boundary evidence: original MIPS .pdata c00ff6d8..c00ff6e3. Semantic name remains unreviewed. */

undefined4 FUN_c00ff6d8(void)

{
  return 1;
}



/* c00ff6e4 FUN_c00ff6e4 */

/* Boundary evidence: original MIPS .pdata c00ff6e4..c00ff6ef. Semantic name remains unreviewed. */

undefined4 FUN_c00ff6e4(void)

{
  return 1;
}



/* c00ff6f0 FUN_c00ff6f0 */

/* Boundary evidence: original MIPS .pdata c00ff6f0..c00ff787. Semantic name remains unreviewed. */

void FUN_c00ff6f0(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (DAT_c0139730 != (int *)0x0) {
    if (param_1 == 0) {
LAB_c00ff774:
      EventModify(DAT_c013972c,3);
    }
    else {
      uVar2 = 0;
      piVar1 = DAT_c0139730;
      if (DAT_c0139500 != 0) {
        do {
          if (*piVar1 == param_1) {
            DAT_c0139730[uVar2 * 0x95 + 1] = 1;
            goto LAB_c00ff774;
          }
          uVar2 = uVar2 + 1;
          piVar1 = piVar1 + 0x95;
        } while (uVar2 < DAT_c0139500);
      }
    }
  }
  return;
}



/* c00ff788 FUN_c00ff788 */

/* Boundary evidence: original MIPS .pdata c00ff788..c00ff913. Semantic name remains unreviewed. */

void FUN_c00ff788(void)

{
  LSTATUS LVar1;
  LPWSTR lpValueName;
  int iVar2;
  DWORD dwIndex;
  HKEY local_28;
  DWORD local_24;
  DWORD local_20 [2];
  
  LVar1 = RegOpenKeyExW((HKEY)&DAT_80000002,L"System\\Events",0,0,&local_28);
  if (LVar1 == 0) {
    LVar1 = RegQueryInfoKeyW(local_28,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_24,(LPDWORD)0x0,
                             (LPDWORD)0x0,(PFILETIME)0x0);
    if ((LVar1 == 0) && (local_24 != 0)) {
      local_24 = local_24 + 1;
      lpValueName = LocalAlloc(0,local_24 * 2);
      if (lpValueName != (LPWSTR)0x0) {
        local_20[0] = local_24;
        dwIndex = 0;
        iVar2 = RegEnumValueW(local_28,0,lpValueName,local_20,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                              (LPDWORD)0x0);
        while (iVar2 == 0) {
          CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,lpValueName);
          dwIndex = dwIndex + 1;
          local_20[0] = local_24;
          iVar2 = RegEnumValueW(local_28,dwIndex,lpValueName,local_20,(LPDWORD)0x0,(LPDWORD)0x0,
                                (LPBYTE)0x0,(LPDWORD)0x0);
        }
        LocalFree(lpValueName);
      }
    }
    RegCloseKey(local_28);
  }
  return;
}



/* c00ff914 FUN_c00ff914 */

/* Boundary evidence: original MIPS .pdata c00ff914..c00ff9af. Semantic name remains unreviewed. */

undefined4 FUN_c00ff914(LPCWSTR param_1)

{
  HMODULE hLibModule;
  LPTHREAD_START_ROUTINE lpStartAddress;
  HANDLE hObject;
  
  hLibModule = LoadLibraryW(param_1);
  if (hLibModule != (HMODULE)0x0) {
    lpStartAddress = (LPTHREAD_START_ROUTINE)GetProcAddressA(hLibModule,2);
    if ((lpStartAddress != (LPTHREAD_START_ROUTINE)0x0) &&
       (hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,lpStartAddress,hLibModule,0,(LPDWORD)0x0
                              ), hObject != (HANDLE)0x0)) {
      CloseHandle(hObject);
      return 1;
    }
    FreeLibrary(hLibModule);
  }
  return 0;
}



/* c00ff9b0 FUN_c00ff9b0 */

/* Boundary evidence: original MIPS .pdata c00ff9b0..c01000cf. Semantic name remains unreviewed. */

void FUN_c00ff9b0(ushort param_1)

{
  ushort uVar1;
  HANDLE *lpHandles;
  uint *puVar2;
  HANDLE pvVar3;
  LSTATUS LVar4;
  int iVar5;
  uint uVar6;
  size_t sVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  ushort *puVar11;
  DWORD DVar12;
  DWORD DVar13;
  STRSAFE_PCNZWCH lpApplicationName;
  DWORD local_5b0;
  DWORD local_5ac;
  ushort local_5a8;
  HKEY local_5a4;
  HANDLE *local_5a0;
  uint *local_59c;
  DWORD aDStack_598 [2];
  undefined1 auStack_590 [600];
  WCHAR aWStack_338 [6];
  wchar_t awStack_32c [122];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  local_5a8 = param_1;
  puVar2 = LocalAlloc(0x40,0x4a80);
  local_59c = puVar2;
  if (puVar2 != (uint *)0x0) {
    DAT_c013972c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    local_5a0 = &DAT_c013972c;
    DAT_c0139730 = puVar2;
    pvVar3 = OpenEventW(0x1f0003,0,L"SYSTEM/FSReady");
    if (pvVar3 != (HANDLE)0x0) {
      EventModify(pvVar3,3);
      CloseHandle(pvVar3);
    }
    WaitForSingleObject(DAT_c013972c,0xffffffff);
    FUN_c00ff788();
    DAT_c0136cac = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"SYSTEM/SystemStarted");
    LVar4 = RegOpenKeyExW((HKEY)&DAT_80000002,L"init",0,0xf003f,&local_5a4);
    puVar10 = puVar2;
    if (LVar4 == 0) {
      local_5ac = 0x80;
      local_5b0 = 0x208;
      DVar12 = 0;
      iVar5 = RegEnumValueW(local_5a4,0,aWStack_338,&local_5ac,(LPDWORD)0x0,aDStack_598,
                            (LPBYTE)awStack_238,&local_5b0);
      while (iVar5 == 0) {
        DVar12 = DVar12 + 1;
        iVar5 = wcsncmp(aWStack_338,L"Launch",6);
        if (iVar5 == 0) {
          if (local_5b0 < 0x209) {
            uVar6 = _wtol(awStack_32c);
            uVar9 = 0;
            puVar8 = puVar2;
            if (DAT_c0139500 != 0) {
              do {
                if (uVar6 == *puVar8) break;
                uVar9 = uVar9 + 1;
                puVar8 = puVar8 + 0x95;
              } while (uVar9 < DAT_c0139500);
            }
            if (uVar9 == DAT_c0139500) {
              if (DAT_c0139500 == 0x20) goto LAB_c00ffd30;
              puVar2[DAT_c0139500 * 0x95] = uVar6;
              DAT_c0139500 = DAT_c0139500 + 1;
            }
            wcscpy((wchar_t *)(puVar2 + uVar9 * 0x95 + 0x12),awStack_238);
            sVar7 = wcslen(awStack_238);
            iVar5 = _wcsicmp(awStack_238 + (sVar7 - 4),L".dll");
            puVar2[uVar9 * 0x95 + 0x94] = (uint)(iVar5 == 0);
          }
        }
        else {
          iVar5 = wcsncmp(aWStack_338,L"Depend",6);
          if (((iVar5 == 0) && (local_5b0 < 0x41)) && ((local_5b0 & 1) == 0)) {
            uVar6 = _wtol(awStack_32c);
            uVar9 = 0;
            puVar8 = puVar2;
            if (DAT_c0139500 != 0) {
              do {
                if (uVar6 == *puVar8) break;
                uVar9 = uVar9 + 1;
                puVar8 = puVar8 + 0x95;
              } while (uVar9 < DAT_c0139500);
            }
            if (uVar9 == DAT_c0139500) {
              if (DAT_c0139500 == 0x20) goto LAB_c00ffd30;
              puVar2[DAT_c0139500 * 0x95] = uVar6;
              DAT_c0139500 = DAT_c0139500 + 1;
            }
            memcpy(puVar2 + uVar9 * 0x95 + 2,awStack_238,local_5b0);
            if (local_5b0 != 0x40) {
              *(undefined2 *)(((local_5b0 >> 1) + uVar9 * 0x12a + 4) * 2 + (int)puVar2) = 0;
            }
          }
        }
LAB_c00ffd30:
        local_5ac = 0x80;
        local_5b0 = 0x208;
        iVar5 = RegEnumValueW(local_5a4,DVar12,aWStack_338,&local_5ac,(LPDWORD)0x0,aDStack_598,
                              (LPBYTE)awStack_238,&local_5b0);
      }
      RegCloseKey(local_5a4);
      local_5ac = 1;
      if (1 < DAT_c0139500) {
        do {
          DVar12 = local_5ac;
          local_5b0 = 0;
          if (local_5ac != 0) {
            do {
              if (puVar2[local_5ac * 0x95] < puVar2[local_5b0 * 0x95]) break;
              local_5b0 = local_5b0 + 1;
            } while (local_5b0 < local_5ac);
          }
          DVar13 = local_5b0;
          puVar8 = puVar2 + local_5ac * 0x95;
          memcpy(auStack_590,puVar8,0x254);
          for (; DVar13 < DVar12; DVar12 = DVar12 - 1) {
            memcpy(puVar8,puVar8 + -0x95,0x254);
            puVar8 = puVar8 + -0x95;
            DVar13 = local_5b0;
          }
          memcpy(puVar2 + DVar13 * 0x95,auStack_590,0x254);
          local_5ac = local_5ac + 1;
        } while (local_5ac < DAT_c0139500);
      }
      lpHandles = local_5a0;
      uVar6 = 0;
      if (DAT_c0139500 != 0) {
        puVar8 = puVar2 + 0x94;
        do {
          puVar11 = (ushort *)((int)DAT_c0139730 + (int)puVar8 + (-0x248 - (int)puVar2));
          uVar1 = *puVar11;
          while (uVar1 != 0) {
            uVar9 = 0;
            puVar10 = DAT_c0139730;
            if (DAT_c0139500 != 0) {
              do {
                if (*puVar10 == (uint)uVar1) break;
                uVar9 = uVar9 + 1;
                puVar10 = puVar10 + 0x95;
              } while (uVar9 < DAT_c0139500);
            }
            if ((uVar9 != DAT_c0139500) && (DAT_c0139730[uVar9 * 0x95 + 1] == 0)) {
              WaitForMultipleObjects(1,lpHandles,0,0xffffffff);
              goto LAB_c010002c;
            }
            puVar11 = puVar11 + 1;
            uVar1 = *puVar11;
          }
          if (((local_5a8 & 1) == 0) ||
             (iVar5 = _wcsicmp((wchar_t *)(puVar8 + -0x82),L"device.dll"), iVar5 != 0)) {
            _itow(puVar8[-0x94],aWStack_338,10);
            lpApplicationName = (STRSAFE_PCNZWCH)(puVar8 + -0x82);
            FUN_c00fc338(lpApplicationName);
            if (*puVar8 == 0) {
              iVar5 = CreateProcessW(lpApplicationName,aWStack_338,(LPSECURITY_ATTRIBUTES)0x0,
                                     (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                                     (LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
            }
            else {
              iVar5 = FUN_c00ff914(lpApplicationName);
            }
            if (iVar5 == 0) goto LAB_c010001c;
          }
          else {
            FUN_c00fc4fc(L"Signalling boot phase 2");
            pvVar3 = OpenEventW(0x1f0003,0,L"SYSTEM/BootPhase2");
            if (pvVar3 == (HANDLE)0x0) {
LAB_c010001c:
              puVar8[-0x93] = 1;
            }
            else {
              EventModify(pvVar3,3);
              CloseHandle(pvVar3);
            }
          }
          uVar6 = uVar6 + 1;
          puVar8 = puVar8 + 0x95;
LAB_c010002c:
          puVar10 = local_59c;
        } while (uVar6 < DAT_c0139500);
      }
    }
    DAT_c0139730 = (uint *)0x0;
    CloseHandle(*local_5a0);
    LocalFree(puVar10);
    PSLNotify(5,0,0);
    FUN_c00fc41c();
    if (DAT_c0136cac != (HANDLE)0x0) {
      EventModify(DAT_c0136cac,3);
    }
  }
  FUN_c013331c(local_30);
  return;
}



/* c01000d0 FileSysMain */

/* Boundary evidence: original MIPS .pdata c01000d0..c010057b. Semantic name remains unreviewed. */

undefined4 FileSysMain(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  LCID LVar3;
  LSTATUS LVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort local_38 [2];
  HKEY local_34;
  DWORD local_30 [2];
  
                    /* 0x100d0  2  FileSysMain */
  local_38[0] = 0;
  iVar1 = WaitForAPIReady(0x54,0);
  if ((iVar1 == 0) ||
     (DAT_c0136c9c = param_1, iVar2 = FUN_c00febec(local_38), iVar1 = DAT_c01391e8, iVar2 == 0)) {
    return 0;
  }
  if (DAT_c0136c98 != 0) {
    LVar3 = GetSystemDefaultLCID();
    *(LCID *)(iVar1 + 0xf8) = LVar3 << 8 | *(uint *)(iVar1 + 0xf8) & 0xff;
    FUN_c0123018();
    FUN_c00fc2d0();
    *(undefined4 *)(DAT_c01391e8 + 8) = 0x4d494b45;
  }
  FUN_c00fc130();
  LVar4 = RegOpenKeyExW((HKEY)&DAT_80000002,L"System\\ObjectStore",0,0,&local_34);
  if (LVar4 == 0) {
    local_30[0] = 4;
    LVar4 = RegQueryValueExW(local_34,L"RunappsPrio256",(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPBYTE)&DAT_c01394dc,local_30);
    if (LVar4 == 0) {
      CeSetThreadPriority(DAT_c01394d8,DAT_c01394dc);
    }
    RegCloseKey(local_34);
  }
  LVar4 = RegOpenKeyExW((HKEY)&DAT_80000002,L"System\\ObjectStore",0,0,&local_34);
  if (LVar4 == 0) {
    local_30[0] = 4;
    RegQueryValueExW(local_34,L"AllowSystemAccess",(LPDWORD)0x0,(LPDWORD)0x0,&DAT_c0136cb4,local_30)
    ;
    RegCloseKey(local_34);
  }
  FUN_c00ff9b0(local_38[0]);
  FUN_c011330c();
  FUN_c0121298();
  DAT_c01394d8 = 0x41;
  DAT_c01394dc = CeGetThreadPriority(0x41);
  uVar6 = 0;
  uVar5 = 0;
  LVar4 = RegOpenKeyExW((HKEY)&DAT_80000002,L"System\\ObjectStore",0,0,&local_34);
  if (LVar4 == 0) {
    local_30[0] = 4;
    uVar6 = 0;
    uVar5 = 0;
    LVar4 = RegQueryValueExW(local_34,L"CompactionPrio256",(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPBYTE)&DAT_c01394dc,local_30);
    if (LVar4 == 0) {
      CeSetThreadPriority(DAT_c01394d8,DAT_c01394dc);
    }
    RegCloseKey(local_34);
  }
  DAT_c01394e4 = DAT_c01394dc;
  DAT_c01394ec = DAT_c01394dc;
  if (DAT_c01394e0 != -1) {
    CeSetThreadPriority();
  }
  if (DAT_c01394e8 != -1) {
    CeSetThreadPriority(DAT_c01394e8,DAT_c01394ec);
  }
  DAT_c0136ca8 = 6;
  do {
    Sleep(0);
    WaitForSingleObject(DAT_c0139400,0xffffffff);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    FUN_c00fc484(&DAT_c01391f0,1,uVar5,uVar6);
    do {
      iVar1 = FUN_c0104344(&DAT_c01391e0);
      if (iVar1 != 0) break;
    } while (DAT_c013941c < 0x40001);
    FUN_c00fc484(&DAT_c01391f0,0,uVar5,uVar6);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  } while( true );
}



/* c010057c FUN_c010057c */

/* Boundary evidence: original MIPS .pdata c010057c..c0100587. Semantic name remains unreviewed. */

undefined4 FUN_c010057c(void)

{
  return 1;
}



/* c0100588 FUN_c0100588 */

/* Boundary evidence: original MIPS .pdata c0100588..c010067b. Semantic name remains unreviewed. */

undefined4 FUN_c0100588(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  HMODULE hLibModule;
  
  iVar1 = WaitForAPIReady(0x51,0);
  if (iVar1 == 0) {
    if (DAT_c0136830 == (code *)0xffffffff) {
      hLibModule = LoadLibraryW(L"coredll.dll");
      DAT_c0136830 = (code *)GetProcAddressW(hLibModule,L"PostMessageW");
      FreeLibrary(hLibModule);
    }
    if (DAT_c0136830 == (code *)0x0) {
      uVar2 = 1;
    }
    else {
      uVar2 = (*DAT_c0136830)(param_1,param_2,param_3,param_4);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c010067c FUN_c010067c */

/* Boundary evidence: original MIPS .pdata c010067c..c010076b. Semantic name remains unreviewed. */

undefined4
FUN_c010067c(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
            undefined4 param_5,undefined2 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[4] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar1 = (*(code *)DAT_c0136cbc[4])
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  return uVar1;
}



/* c010076c FUN_c010076c */

/* Boundary evidence: original MIPS .pdata c010076c..c0100777. Semantic name remains unreviewed. */

undefined4 FUN_c010076c(void)

{
  return 1;
}



/* c0100778 FUN_c0100778 */

/* Boundary evidence: original MIPS .pdata c0100778..c0100867. Semantic name remains unreviewed. */

undefined4 FUN_c0100778(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = __GetUserKData(0xc);
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[5] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar2 = (*(code *)DAT_c0136cbc[5])(uVar1,param_1,param_2);
  }
  return uVar2;
}



/* c0100868 FUN_c0100868 */

/* Boundary evidence: original MIPS .pdata c0100868..c0100873. Semantic name remains unreviewed. */

undefined4 FUN_c0100868(void)

{
  return 1;
}



/* c0100874 FUN_c0100874 */

/* Boundary evidence: original MIPS .pdata c0100874..c010095f. Semantic name remains unreviewed. */

undefined4 FUN_c0100874(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = GetCallerVMProcessId();
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[5] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar2 = (*(code *)DAT_c0136cbc[5])(uVar1,param_1,param_2);
  }
  return uVar2;
}



/* c0100960 FUN_c0100960 */

/* Boundary evidence: original MIPS .pdata c0100960..c010096b. Semantic name remains unreviewed. */

undefined4 FUN_c0100960(void)

{
  return 1;
}



/* c010096c FUN_c010096c */

/* Boundary evidence: original MIPS .pdata c010096c..c0100a2b. Semantic name remains unreviewed. */

undefined4 FUN_c010096c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[6] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar1 = (*(code *)DAT_c0136cbc[6])();
  }
  return uVar1;
}



/* c0100a2c FUN_c0100a2c */

/* Boundary evidence: original MIPS .pdata c0100a2c..c0100a37. Semantic name remains unreviewed. */

undefined4 FUN_c0100a2c(void)

{
  return 1;
}



/* c0100a38 FUN_c0100a38 */

/* Boundary evidence: original MIPS .pdata c0100a38..c0100af7. Semantic name remains unreviewed. */

undefined4 FUN_c0100a38(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[7] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar1 = (*(code *)DAT_c0136cbc[7])();
  }
  return uVar1;
}



/* c0100af8 FUN_c0100af8 */

/* Boundary evidence: original MIPS .pdata c0100af8..c0100b03. Semantic name remains unreviewed. */

undefined4 FUN_c0100af8(void)

{
  return 1;
}



/* c0100b04 FUN_c0100b04 */

/* Boundary evidence: original MIPS .pdata c0100b04..c0100bc3. Semantic name remains unreviewed. */

undefined4 FUN_c0100b04(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[0xb] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar1 = (*(code *)DAT_c0136cbc[0xb])();
  }
  return uVar1;
}



/* c0100bc4 FUN_c0100bc4 */

/* Boundary evidence: original MIPS .pdata c0100bc4..c0100bcf. Semantic name remains unreviewed. */

undefined4 FUN_c0100bc4(void)

{
  return 1;
}



/* c0100bd0 FUN_c0100bd0 */

/* Boundary evidence: original MIPS .pdata c0100bd0..c0100c8f. Semantic name remains unreviewed. */

undefined4 FUN_c0100bd0(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[0xc] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar1 = (*(code *)DAT_c0136cbc[0xc])();
  }
  return uVar1;
}



/* c0100c90 FUN_c0100c90 */

/* Boundary evidence: original MIPS .pdata c0100c90..c0100c9b. Semantic name remains unreviewed. */

undefined4 FUN_c0100c90(void)

{
  return 1;
}



/* c0100c9c FUN_c0100c9c */

/* Boundary evidence: original MIPS .pdata c0100c9c..c0100d5b. Semantic name remains unreviewed. */

undefined4 FUN_c0100c9c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[0xd] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar1 = (*(code *)DAT_c0136cbc[0xd])();
  }
  return uVar1;
}



/* c0100d5c FUN_c0100d5c */

/* Boundary evidence: original MIPS .pdata c0100d5c..c0100d67. Semantic name remains unreviewed. */

undefined4 FUN_c0100d5c(void)

{
  return 1;
}



/* c0100d68 FUN_c0100d68 */

/* Boundary evidence: original MIPS .pdata c0100d68..c0100e27. Semantic name remains unreviewed. */

undefined4 FUN_c0100d68(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[0xe] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar1 = (*(code *)DAT_c0136cbc[0xe])();
  }
  return uVar1;
}



/* c0100e28 FUN_c0100e28 */

/* Boundary evidence: original MIPS .pdata c0100e28..c0100e33. Semantic name remains unreviewed. */

undefined4 FUN_c0100e28(void)

{
  return 1;
}



/* c0100e34 FUN_c0100e34 */

/* Boundary evidence: original MIPS .pdata c0100e34..c0100ef3. Semantic name remains unreviewed. */

undefined4 FUN_c0100e34(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[0xf] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar1 = (*(code *)DAT_c0136cbc[0xf])();
  }
  return uVar1;
}



/* c0100ef4 FUN_c0100ef4 */

/* Boundary evidence: original MIPS .pdata c0100ef4..c0100eff. Semantic name remains unreviewed. */

undefined4 FUN_c0100ef4(void)

{
  return 1;
}



/* c0100f00 FUN_c0100f00 */

/* Boundary evidence: original MIPS .pdata c0100f00..c0100fbf. Semantic name remains unreviewed. */

undefined4 FUN_c0100f00(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_c0136cbc == (int *)0x0) || (*DAT_c0136cbc == 0)) || (DAT_c0136cbc[0x10] == 0)) {
    SetLastError(0x424);
  }
  else {
    uVar1 = (*(code *)DAT_c0136cbc[0x10])();
  }
  return uVar1;
}



/* c0100fc0 FUN_c0100fc0 */

/* Boundary evidence: original MIPS .pdata c0100fc0..c0100fcb. Semantic name remains unreviewed. */

undefined4 FUN_c0100fc0(void)

{
  return 1;
}



/* c0100fcc FUN_c0100fcc */

/* Boundary evidence: original MIPS .pdata c0100fcc..c01010bf. Semantic name remains unreviewed. */

HANDLE FUN_c0100fcc(undefined4 param_1,wchar_t *param_2,uint param_3)

{
  HANDLE hObject;
  uint uVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  uVar3 = 0x2000;
  if ((param_3 & 0x20) == 0) {
    uVar3 = 0;
  }
  hObject = (HANDLE)FSINT_CreateFileW(param_2,0x80000000,1,0,3,uVar3,0);
  if (hObject != (HANDLE)0xffffffff) {
    SetLastError(0);
    uVar1 = FUN_c011d8bc(hObject,param_2,0,0);
    if ((uVar1 & 4) != 0) {
      return hObject;
    }
    CloseHandle(hObject);
    DVar2 = GetLastError();
    hObject = (HANDLE)0xffffffff;
    if (DVar2 != 0) {
      return (HANDLE)0xffffffff;
    }
  }
  SetLastError(2);
  return hObject;
}



/* c01010c0 FUN_c01010c0 */

/* Boundary evidence: original MIPS .pdata c01010c0..c01010e7. Semantic name remains unreviewed. */

undefined4 FUN_c01010c0(void)

{
  SetLastError(0x201b);
  return 0xffffffff;
}



/* c01010e8 FUN_c01010e8 */

/* Boundary evidence: original MIPS .pdata c01010e8..c010110f. Semantic name remains unreviewed. */

undefined4 FUN_c01010e8(void)

{
  SetLastError(0x201b);
  return 0;
}



/* c0101110 FUN_c0101110 */

/* Boundary evidence: original MIPS .pdata c0101110..c01012cb. Semantic name remains unreviewed. */

HANDLE FUN_c0101110(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                   int param_6,int param_7)

{
  int iVar1;
  HANDLE hSourceProcessHandle;
  HANDLE hTargetProcessHandle;
  BOOL BVar2;
  HANDLE local_28;
  LPCWSTR local_24;
  LPWIN32_FIND_DATAW local_20 [2];
  
  local_28 = (HANDLE)0xffffffff;
  local_24 = (LPCWSTR)0x0;
  local_20[0] = (LPWIN32_FIND_DATAW)0x0;
  iVar1 = CeAllocDuplicateBuffer(&local_24,param_1,0,5);
  if ((iVar1 < 0) || (iVar1 = CeAllocDuplicateBuffer(local_20,param_3,param_4,8), iVar1 < 0)) {
    SetLastError(0x57);
  }
  else {
    local_28 = (HANDLE)FUN_c00fdbf8(local_24,param_2,local_20[0],param_4,param_5,param_6,param_7);
    iVar1 = CeFreeDuplicateBuffer(local_24,param_1,0,5);
    if (iVar1 < 0) {
      if (local_28 != (HANDLE)0xffffffff) {
        FindClose(local_28);
        local_28 = (HANDLE)0xffffffff;
      }
      SetLastError(0x57);
    }
    iVar1 = CeFreeDuplicateBuffer(local_20[0],param_3,param_4,8);
    if (iVar1 < 0) {
      if (local_28 != (HANDLE)0xffffffff) {
        FindClose(local_28);
        local_28 = (HANDLE)0xffffffff;
      }
      SetLastError(0x57);
    }
    if (local_28 == (HANDLE)0xffffffff) {
      return (HANDLE)0xffffffff;
    }
    hSourceProcessHandle = (HANDLE)__GetUserKData(0xc);
    hTargetProcessHandle = (HANDLE)GetCallerVMProcessId();
    BVar2 = DuplicateHandle(hSourceProcessHandle,local_28,hTargetProcessHandle,&local_28,0,0,3);
    if (BVar2 != 0) {
      return local_28;
    }
  }
  return (HANDLE)0xffffffff;
}



/* c01012cc FUN_c01012cc */

/* Boundary evidence: original MIPS .pdata c01012cc..c010136b. Semantic name remains unreviewed. */

int FUN_c01012cc(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  LPWIN32_FIND_DATAW local_18 [2];
  
  local_18[0] = (LPWIN32_FIND_DATAW)0x0;
  iVar1 = CeAllocDuplicateBuffer(local_18,param_2,param_3,8);
  if (-1 < iVar1) {
    iVar1 = FUN_c00fe008(param_1,local_18[0],param_3);
    iVar2 = CeFreeDuplicateBuffer(local_18[0],param_2,param_3,8);
    if (-1 < iVar2) {
      return iVar1;
    }
  }
  SetLastError(0x57);
  return 0;
}



/* c010136c FUN_c010136c */

/* Boundary evidence: original MIPS .pdata c010136c..c01013ff. Semantic name remains unreviewed. */

HANDLE FUN_c010136c(undefined4 param_1,wchar_t *param_2,uint param_3)

{
  HANDLE hSourceHandle;
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  HANDLE local_10 [2];
  
  hSourceHandle = FUN_c0100fcc(param_1,param_2,param_3);
  local_10[0] = (HANDLE)0xffffffff;
  if (hSourceHandle != (HANDLE)0xffffffff) {
    hTargetProcessHandle = (HANDLE)GetCallerVMProcessId();
    BVar1 = DuplicateHandle((HANDLE)0x42,hSourceHandle,hTargetProcessHandle,local_10,0,0,3);
    if (BVar1 == 0) {
      CloseHandle(hSourceHandle);
      SetLastError(8);
    }
  }
  return local_10[0];
}



/* c0101400 FUN_c0101400 */

/* Boundary evidence: original MIPS .pdata c0101400..c0101427. Semantic name remains unreviewed. */

undefined4 FUN_c0101400(void)

{
  SetLastError(0x201b);
  return 0xffffffff;
}



/* c0101428 FUN_c0101428 */

/* Boundary evidence: original MIPS .pdata c0101428..c010144f. Semantic name remains unreviewed. */

undefined4 FUN_c0101428(void)

{
  SetLastError(0x201b);
  return 0;
}



/* c0101450 FUN_c0101450 */

/* Boundary evidence: original MIPS .pdata c0101450..c01015af. Semantic name remains unreviewed. */

undefined4 FUN_c0101450(void)

{
  undefined4 uVar1;
  int iVar2;
  LPVOID _Dst;
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [40];
  
  SetThreadPriority((HANDLE)0x41,0);
  iVar2 = ReadMsgQueue(DAT_c0136cc0,auStack_50,0x24,auStack_54,0xffffffff,auStack_58);
  while (iVar2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    uVar1 = DAT_c0139460;
    iVar2 = DAT_c0139454;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    if ((iVar2 != 0) && (_Dst = HeapAlloc(DAT_c0136cb0,0,0x24), _Dst != (LPVOID)0x0)) {
      memcpy(_Dst,auStack_50,0x24);
      *(undefined4 *)((int)_Dst + 4) = uVar1;
      iVar2 = FUN_c0100588(iVar2,0x3fd,0,_Dst);
      if (iVar2 == 0) {
        HeapFree(DAT_c0136cb0,0,_Dst);
      }
    }
    iVar2 = ReadMsgQueue(DAT_c0136cc0,auStack_50,0x24,auStack_54,0xffffffff,auStack_58);
  }
  return 0;
}



/* c01015b0 FUN_c01015b0 */

/* Boundary evidence: original MIPS .pdata c01015b0..c01015d7. Semantic name remains unreviewed. */

undefined4 FUN_c01015b0(void)

{
  SetLastError(0x32);
  return 0;
}



/* c01015d8 FUN_c01015d8 */

/* Boundary evidence: original MIPS .pdata c01015d8..c01017db. Semantic name remains unreviewed. */

undefined4 FUN_c01015d8(int param_1)

{
  undefined4 uVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (DAT_c0136cc8 == (HANDLE)0x0) {
    local_38 = 0x14;
    local_34 = 1;
    local_30 = 0;
    local_2c = 0x24;
    local_28 = 0;
    DAT_c0136cc4 = CreateMsgQueue(0,&local_38);
    if (DAT_c0136cc4 == 0) goto LAB_c010175c;
    local_28 = 1;
    DAT_c0136cc0 = OpenMsgQueue(0x42,DAT_c0136cc4,&local_38);
    if (DAT_c0136cc0 == 0) {
      CloseMsgQueue(DAT_c0136cc4);
      DAT_c0136cc4 = 0;
      goto LAB_c010175c;
    }
    DAT_c0136cc8 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0101450,(LPVOID)0x0,0,(LPDWORD)0x0
                               );
  }
  if (param_1 == 0) {
    DAT_c0139454 = 0;
  }
  else {
    if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 8) != 1)) {
      SetLastError(0x57);
      goto LAB_c010175c;
    }
    DAT_c0139458 = *(undefined4 *)(param_1 + 0xc);
    DAT_c0139460 = *(undefined4 *)(param_1 + 0x10);
    DAT_c0139454 = *(int *)(param_1 + 4);
    DAT_c013945c = GetCallerVMProcessId();
  }
  uVar1 = 1;
LAB_c010175c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar1;
}



/* c01017dc FUN_c01017dc */

/* Boundary evidence: original MIPS .pdata c01017dc..c01017e7. Semantic name remains unreviewed. */

undefined4 FUN_c01017dc(void)

{
  return 1;
}



/* c01017e8 FUN_c01017e8 */

/* Boundary evidence: original MIPS .pdata c01017e8..c01017f3. Semantic name remains unreviewed. */

undefined4 FUN_c01017e8(void)

{
  return 1;
}



/* c01017f4 FUN_c01017f4 */

/* Boundary evidence: original MIPS .pdata c01017f4..c0101913. Semantic name remains unreviewed. */

void FUN_c01017f4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_40 [2];
  int local_38;
  undefined1 auStack_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  iVar2 = DAT_c013945c;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((iVar2 != 0) && (iVar1 = GetCallerVMProcessId(), iVar2 != iVar1)) {
    iVar2 = *(int *)(param_1 + 0x458);
    if (iVar2 != 0) {
      local_40[0] = 0x24;
      memset(auStack_34,0,0x10);
      local_24 = *(undefined4 *)(param_1 + 0x460);
      local_20 = *(undefined4 *)(param_1 + 0x468);
      local_38 = iVar2;
      if (DAT_c0136cc4 != 0) {
        WriteMsgQueue(DAT_c0136cc4,local_40,0x24,0,0);
      }
    }
    iVar2 = DAT_c0136cc4;
    iVar1 = *(int *)(param_1 + 0x45c);
    if (iVar1 != 0) {
      local_40[0] = 0x24;
      memset(auStack_34,0,0x10);
      local_24 = *(undefined4 *)(param_1 + 0x464);
      local_20 = *(undefined4 *)(param_1 + 0x46c);
      if (iVar2 != 0) {
        local_38 = iVar1;
        WriteMsgQueue(iVar2,local_40,0x24,0,0);
      }
    }
  }
  return;
}



/* c0101914 FUN_c0101914 */

/* Boundary evidence: original MIPS .pdata c0101914..c01019ef. Semantic name remains unreviewed. */

void FUN_c0101914(void *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_40 [40];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  iVar2 = DAT_c013945c;
  if (DAT_c0139520 != 0) {
    iVar3 = memcmp((void *)((int)param_1 + 0xc),&DAT_c01394a0,0x10);
    bVar1 = true;
    if (iVar3 == 0) goto LAB_c0101974;
  }
  bVar1 = false;
LAB_c0101974:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (((!bVar1) && (iVar2 != 0)) && (iVar3 = GetCallerVMProcessId(), iVar2 != iVar3)) {
    memcpy(auStack_40,param_1,0x24);
    if (DAT_c0136cc4 != 0) {
      WriteMsgQueue(DAT_c0136cc4,auStack_40,0x24,0,0);
    }
  }
  return;
}



/* c01019f0 FUN_c01019f0 */

/* Boundary evidence: original MIPS .pdata c01019f0..c0101ab3. Semantic name remains unreviewed. */

undefined4 FUN_c01019f0(int *param_1)

{
  int iVar1;
  undefined4 local_38 [2];
  int local_30;
  undefined1 auStack_2c [16];
  int local_1c;
  int local_18;
  
  if (param_1 != (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    iVar1 = DAT_c013945c;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    if ((iVar1 != 0) && (iVar1 != *param_1)) {
      local_38[0] = 0x24;
      memset(auStack_2c,0,0x10);
      local_30 = param_1[3];
      local_1c = param_1[8];
      local_18 = param_1[9];
      if (DAT_c0136cc4 != 0) {
        WriteMsgQueue(DAT_c0136cc4,local_38,0x24,0,0);
      }
    }
  }
  return 1;
}



/* c0101ab4 FUN_c0101ab4 */

/* Boundary evidence: original MIPS .pdata c0101ab4..c0101b0f. Semantic name remains unreviewed. */

void FUN_c0101ab4(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (param_1 == DAT_c013945c) {
    DAT_c0139454 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return;
}



/* c0101b10 FUN_c0101b10 */

/* Boundary evidence: original MIPS .pdata c0101b10..c0101baf. Semantic name remains unreviewed. */

void FUN_c0101b10(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HRESULT HVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  size_t local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c0136c78;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  HVar1 = StringCchVPrintfW(awStack_218,0x104,param_1,(va_list)&local_res4);
  if ((-1 < HVar1) && (HVar1 = StringCchLengthW(awStack_218,0x104,local_220), -1 < HVar1)) {
    CeLogData(1,0x4a,awStack_218,(local_220[0] + 1) * 2 & 0xffff,0,0x40000000,0,0);
  }
  FUN_c013331c(local_10);
  return;
}



/* c0101bb0 FUN_c0101bb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0101bb0..c0101c93. Semantic name remains unreviewed. */

void FUN_c0101bb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  uint uVar2;
  undefined1 auStack_58 [80];
  
  if (((_DAT_00005b68 & 0x20000000) != 0) &&
     (((DAT_c0136824 & 0x20000) != 0 || ((_DAT_00005b68 & 0x1000) != 0)))) {
    FUN_c0101b10(L"FlushVol %s",param_1,param_3,param_4);
    dwErrCode = GetLastError();
    uVar1 = __GetUserKData(8);
    uVar2 = GetThreadCallStack(uVar1,0x14,auStack_58,0,0);
    if (uVar2 != 0) {
      CeLogData(1,0x5b,auStack_58,(uVar2 & 0x3fff) << 2,0,0x40000000,0,0);
    }
    SetLastError(dwErrCode);
  }
  return;
}



/* c0101c94 FUN_c0101c94 */

/* Boundary evidence: original MIPS .pdata c0101c94..c0101d63. Semantic name remains unreviewed. */

uint FUN_c0101c94(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_c0106a7c(param_2);
  if (iVar1 == 0) {
    if (param_2 < 0x400000) {
      uVar2 = param_2 >> 10 & 0xffff;
      if ((uVar2 == 0) || (*(int *)(uVar2 * 4 + *(int *)(param_1 + 0x238)) != 0)) {
        iVar1 = *(int *)(uVar2 * 4 + *(int *)(param_1 + 0x238)) + *(int *)(param_1 + 0x230) + 0xc;
        if ((iVar1 != 0) && (uVar2 = *(uint *)((param_2 & 0x3ff) * 4 + iVar1), (uVar2 & 1) != 0)) {
          return (uVar2 & 0xffffffc) + *(int *)(param_1 + 0x230) + 0xc;
        }
      }
    }
    param_2 = 0;
  }
  return param_2;
}



/* c0101d64 FUN_c0101d64 */

int FUN_c0101d64(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2 >> 10 & 0xffff;
  if ((uVar1 == 0) || (*(int *)(uVar1 * 4 + *(int *)(param_1 + 0x238)) != 0)) {
    iVar2 = *(int *)(uVar1 * 4 + *(int *)(param_1 + 0x238)) + *(int *)(param_1 + 0x230) + 0xc;
    if ((iVar2 != 0) && (uVar1 = *(uint *)((param_2 & 0x3ff) * 4 + iVar2), (uVar1 & 1) != 0)) {
      return (uVar1 & 0xffffffc) + *(int *)(param_1 + 0x230);
    }
  }
  return 0;
}



/* c0101de8 FUN_c0101de8 */

int FUN_c0101de8(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if ((param_2 & 0xffffff) < 0x400000) {
    uVar1 = param_2 >> 10 & 0x3fff;
    if ((uVar1 == 0) || (*(int *)(uVar1 * 4 + *(int *)(param_1 + 0x238)) != 0)) {
      iVar2 = *(int *)(uVar1 * 4 + *(int *)(param_1 + 0x238)) + *(int *)(param_1 + 0x230) + 0xc;
      if ((iVar2 != 0) &&
         ((uVar1 = *(uint *)((param_2 & 0x3ff) * 4 + iVar2), (uVar1 & 1) != 0 &&
          ((param_2 & 0xf000000) == (uVar1 >> 4 & 0xf000000))))) {
        return (uVar1 & 0xffffffc) + *(int *)(param_1 + 0x230) + 0xc;
      }
    }
  }
  return 0;
}



/* c0101ea4 FUN_c0101ea4 */

uint FUN_c0101ea4(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2 >> 10 & 0xffff;
  if ((((uVar1 == 0) || (*(int *)(uVar1 * 4 + *(int *)(param_1 + 0x238)) != 0)) &&
      (iVar2 = *(int *)(uVar1 * 4 + *(int *)(param_1 + 0x238)) + *(int *)(param_1 + 0x230) + 0xc,
      iVar2 != 0)) && (uVar1 = *(uint *)((param_2 & 0x3ff) * 4 + iVar2), (uVar1 & 1) != 0)) {
    uVar1 = uVar1 >> 4 & 0xf000000 | *(int *)(param_1 + 0xc) << 0x1c | param_2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0101f34 FUN_c0101f34 */

/* Boundary evidence: original MIPS .pdata c0101f34..c0102023. Semantic name remains unreviewed. */

void FUN_c0101f34(undefined4 *param_1,int param_2)

{
  if (param_1 == &DAT_c01391e0) {
    if (param_2 != 0) {
      if (0x20000 < DAT_c013941c) {
        return;
      }
      if (DAT_c013941c + param_2 < 0x20000) {
        return;
      }
      goto LAB_c010200c;
    }
    if ((uRamc013942c < 6) && (0x20000 < DAT_c013941c)) {
      return;
    }
  }
  else {
    if (param_2 != 0) {
      if (0x5ff4 < (uint)param_1[0x8f]) {
        return;
      }
      if (param_1[0x8f] + param_2 + 0xcU < 0x5ff4) {
        return;
      }
      goto LAB_c010200c;
    }
    if ((*(ushort *)(param_1 + 0x93) < 0xc) && (0x5ff4 < (uint)param_1[0x8f])) {
      return;
    }
  }
  *(undefined2 *)(param_1 + 0x93) = 0;
LAB_c010200c:
  EventModify(param_1[0x88],3);
  return;
}



/* c0102024 FUN_c0102024 */

void FUN_c0102024(int param_1,uint *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  if (7 < (*param_2 & 0xffffffc)) {
    puVar1 = param_2 + 3;
    *puVar1 = 0;
    puVar2 = *(undefined4 **)(param_1 + 0x248);
    param_2[4] = (uint)puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = puVar1;
    }
    *(uint **)(param_1 + 0x248) = puVar1;
  }
  return;
}



/* c0102064 FUN_c0102064 */

void FUN_c0102064(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  
  if (7 < (*param_2 & 0xffffffc)) {
    puVar1 = (undefined4 *)param_2[4];
    if (param_2[3] == 0) {
      *(undefined4 **)(param_1 + 0x248) = puVar1;
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = 0;
      }
    }
    else {
      *(undefined4 **)(param_2[3] + 4) = puVar1;
      if (*(int *)(param_2[3] + 4) != 0) {
        *(uint *)param_2[4] = param_2[3];
      }
    }
  }
  return;
}



/* c01020c0 FUN_c01020c0 */

/* Boundary evidence: original MIPS .pdata c01020c0..c0102257. Semantic name remains unreviewed. */

undefined4 FUN_c01020c0(int *param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  *param_3 = 0;
  if (param_1 == (int *)0x0) {
LAB_c0102220:
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
    do {
      uVar7 = param_1[1];
      *param_3 = DAT_c013944c * uVar7 + *param_3;
      uVar6 = 0;
      if (uVar7 != 0) {
        do {
          uVar2 = uVar6 + 1;
          iVar8 = 1;
          if (uVar2 < uVar7) {
            piVar3 = param_1 + uVar6 + 3;
            uVar4 = param_2;
            do {
              uVar4 = DAT_c013944c + uVar4;
              if ((piVar3[-1] + DAT_c013944c != *piVar3) || ((uVar4 & 0x1ffffff) == 0)) break;
              uVar2 = uVar2 + 1;
              iVar8 = iVar8 + 1;
              piVar3 = piVar3 + 1;
            } while (uVar2 < uVar7);
          }
          iVar1 = VirtualCopy(param_2,param_1[uVar6 + 2],DAT_c013944c * iVar8,4);
          if (iVar1 == 0) goto LAB_c0102220;
          iVar1 = KernelLibIoControl(1,0xc,param_2,iVar8 << 0xc,0,0x40000000,0);
          if (iVar1 != 0) {
            DAT_c0136ccc = 1;
          }
          uVar6 = iVar8 + uVar6;
          param_2 = DAT_c013944c * iVar8 + param_2;
        } while (uVar6 < uVar7);
      }
      param_1 = (int *)*param_1;
    } while (param_1 != (int *)0x0);
  }
  return uVar5;
}



/* c0102258 FUN_c0102258 */

/* Boundary evidence: original MIPS .pdata c0102258..c0102693. Semantic name remains unreviewed. */

undefined4 FUN_c0102258(undefined4 *param_1,uint param_2,int param_3)

{
  int iVar1;
  LPVOID pvVar2;
  DWORD DVar3;
  undefined4 uVar4;
  HANDLE hFileMappingObject;
  BOOL BVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  DWORD *pDVar9;
  DWORD dwDesiredAccess;
  HANDLE hFile;
  uint uVar10;
  DWORD local_60;
  DWORD local_5c;
  DWORD local_58 [2];
  _SYSTEM_INFO _Stack_50;
  
  GetSystemInfo(&_Stack_50);
  DAT_c013944c = _Stack_50.dwPageSize;
  if (param_1 == &DAT_c01391e0) {
    iVar1 = GetFSHeapInfo();
    DAT_c0139450 = 0;
    piVar6 = (int *)(iVar1 + 0x10);
    iVar8 = 0x10;
    do {
      DAT_c0139450 = *piVar6 + DAT_c0139450;
      iVar8 = iVar8 + -1;
      piVar6 = piVar6 + 3;
    } while (iVar8 != 0);
    if (0x7ff0000 < DAT_c0139450) {
      DAT_c0139450 = 0x7ff0000;
    }
    DAT_c0139410 = VirtualAlloc((LPVOID)0xc8000000,DAT_c0139450,0x2000,1);
    if (DAT_c0139410 == (LPVOID)0x0) {
      return 0;
    }
    DAT_c0139450 = DAT_c0139450 - 0x1000;
    iVar1 = VirtualCopy(DAT_c0139410,iVar1,0x1000,0x204);
    pvVar2 = DAT_c0139410;
    if (iVar1 != 0) {
      DAT_c01391e8 = DAT_c0139410;
      if (*(int *)((int)DAT_c0139410 + 4) != 0x4d494b45) {
        return 0;
      }
      iVar1 = FUN_c01020c0(*(int **)((int)DAT_c0139410 + 0xcc),(int)DAT_c0139410 + 0x1000,
                           &DAT_c0139420);
      pvVar2 = DAT_c0139410;
      if (iVar1 != 0) goto LAB_c01023a8;
    }
LAB_c0102358:
    VirtualFree(pvVar2,0,0x8000);
    return 0;
  }
  if (param_3 == 0) {
    hFile = (HANDLE)0xffffffff;
    dwDesiredAccess = 4;
    pDVar9 = param_1 + 0x90;
    if ((HANDLE)param_1[0x8a] == (HANDLE)0xffffffff) {
      *pDVar9 = 0xc000;
    }
    else {
      DVar3 = GetFileSize((HANDLE)param_1[0x8a],local_58);
      *pDVar9 = DVar3;
      iVar1 = ReadFileWithSeek(param_1[0x8a],&local_5c,4,&local_60,0,0x20,0);
      if (((iVar1 != 0) && (local_60 == 4)) && (local_5c != 0)) {
        *pDVar9 = local_5c;
      }
      if (*pDVar9 == 0) {
        return 0;
      }
      if (local_58[0] != 0) {
        return 0;
      }
    }
    if ((param_2 & 0x20) == 0) {
      if ((param_2 & 8) == 0) {
        DVar3 = 0x20000004;
      }
      else {
        hFile = (HANDLE)param_1[0x8a];
        DVar3 = 4;
        param_1[0x8a] = 0xffffffff;
      }
      dwDesiredAccess = 0xf001f;
      uVar4 = FUN_c0123644(*pDVar9);
      param_1[0x94] = uVar4;
    }
    else {
      DVar3 = 2;
      param_1[0x94] = *pDVar9;
    }
    hFileMappingObject =
         CreateFileMappingW((HANDLE)param_1[0x8a],(LPSECURITY_ATTRIBUTES)0x0,DVar3,0,param_1[0x94],
                            (LPCWSTR)0x0);
    param_1[0x8b] = hFileMappingObject;
    if (hFileMappingObject == (HANDLE)0x0) {
      return 0;
    }
    pvVar2 = MapViewOfFile(hFileMappingObject,dwDesiredAccess,0,0,0);
    param_1[2] = pvVar2;
    if (pvVar2 == (LPVOID)0x0) {
      return 0;
    }
    *pDVar9 = *pDVar9 - 0x1000;
    if (((param_2 & 8) != 0) && (hFile != (HANDLE)0xffffffff)) {
      SetFilePointer(hFile,0,(PLONG)0x0,0);
      pvVar2 = (LPVOID)param_1[2];
      uVar10 = *pDVar9 + 0x1000;
      uVar7 = 0x1000;
      do {
        if (uVar10 < uVar7) {
          uVar7 = uVar10;
        }
        BVar5 = ReadFile(hFile,pvVar2,uVar7,&local_60,(LPOVERLAPPED)0x0);
        if ((BVar5 == 0) || (local_60 != uVar7)) {
          CloseHandle(hFile);
          return 0;
        }
        uVar10 = uVar10 - uVar7;
        pvVar2 = (LPVOID)((int)pvVar2 + uVar7);
      } while (uVar10 != 0);
      CloseHandle(hFile);
    }
  }
  else {
    pvVar2 = VirtualAlloc((LPVOID)0x0,*(SIZE_T *)(param_3 + 8),0x2000,1);
    if (pvVar2 == (LPVOID)0x0) {
      return 0;
    }
    uVar7 = *(uint *)(param_3 + 0xc) & 0xfffffe8c;
    *(uint *)(param_3 + 0xc) = uVar7;
    iVar1 = VirtualCopy(pvVar2,*(undefined4 *)(param_3 + 4),*(undefined4 *)(param_3 + 8),uVar7 | 4);
    if (iVar1 == 0) goto LAB_c0102358;
    param_1[2] = pvVar2;
    param_1[0x8b] = 0xffffffff;
    param_1[0x90] = *(int *)(param_3 + 8) + -0x1000;
    param_1[0x94] = *(undefined4 *)(param_3 + 8);
  }
LAB_c01023a8:
  iVar1 = param_1[0x90] + -0x4000;
  iVar8 = param_1[2] + 0x5000;
  param_1[0x90] = iVar1;
  param_1[0x8e] = param_1[2] + 0x1000;
  param_1[0x8c] = iVar8;
  param_1[0x8d] = iVar8 + iVar1;
  param_1[0x91] = iVar8;
  return 1;
}



/* c0102694 FUN_c0102694 */

/* Boundary evidence: original MIPS .pdata c0102694..c010276f. Semantic name remains unreviewed. */

undefined4 FUN_c0102694(int param_1,int param_2,int param_3,undefined4 param_4)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x22c) == -1) {
LAB_c0102708:
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
    if (*(int *)(param_1 + 8) != 0) {
      FUN_c0101bb0(param_1 + 0x10,param_2,param_3,param_4);
      BVar1 = FlushViewOfFile(*(LPCVOID *)(param_1 + 8),
                              *(int *)(param_1 + 0x234) - (int)*(LPCVOID *)(param_1 + 8));
      if (BVar1 == 0) {
        if (param_3 == 0) goto LAB_c0102708;
        uVar2 = 1;
      }
      UnmapViewOfFile(*(LPCVOID *)(param_1 + 8));
    }
    CloseHandle(*(HANDLE *)(param_1 + 0x22c));
    if ((param_2 != 0) && (*(HANDLE *)(param_1 + 0x228) != (HANDLE)0xffffffff)) {
      CloseHandle(*(HANDLE *)(param_1 + 0x228));
    }
  }
  return uVar2;
}



/* c0102770 FUN_c0102770 */

void FUN_c0102770(int *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = DAT_c01391e8;
  iVar5 = 0;
  for (piVar3 = *(int **)(DAT_c01391e8 + 0xcc); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    iVar5 = piVar3[1] + iVar5 + 1;
  }
  if (param_1 != (int *)0x0) {
    *param_1 = iVar5;
  }
  if (param_2 != (uint *)0x0) {
    piVar3 = (int *)(iVar4 + 0x10);
    *param_2 = 0;
    iVar4 = 0x10;
    do {
      iVar2 = *piVar3;
      uVar1 = *param_2;
      piVar3 = piVar3 + 3;
      iVar4 = iVar4 + -1;
      *param_2 = iVar2 + uVar1;
    } while (iVar4 != 0);
    if (DAT_c013944c == 0) {
      trap(0x1c00);
    }
    *param_2 = (iVar2 + uVar1) / DAT_c013944c - iVar5;
  }
  return;
}



/* c0102800 FUN_c0102800 */

/* Boundary evidence: original MIPS .pdata c0102800..c010297b. Semantic name remains unreviewed. */

undefined4 FUN_c0102800(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  int aiStack_28 [2];
  
  iVar1 = DAT_c01391e8;
  iVar2 = FUN_c01020c0(param_2,*(int *)(param_1 + 0x230) + *(int *)(param_1 + 0x240),aiStack_28);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    FUN_c0105008(param_1,*(int *)(param_1 + 0x230) + *(int *)(param_1 + 0x240));
    *(uint *)(*(int *)(param_1 + 0x230) + *(int *)(param_1 + 0x240)) =
         DAT_c013944c * param_3 - 0xcU | 1;
    puVar7 = (uint *)(*(int *)(param_1 + 0x230) + *(int *)(param_1 + 0x240));
    if (7 < (*puVar7 & 0xffffffc)) {
      puVar5 = puVar7 + 3;
      *puVar5 = 0;
      puVar6 = *(undefined4 **)(param_1 + 0x248);
      puVar7[4] = (uint)puVar6;
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = puVar5;
      }
      *(uint **)(param_1 + 0x248) = puVar5;
    }
    *(int *)(param_1 + 0x23c) = DAT_c013944c * param_3 + *(int *)(param_1 + 0x23c) + -0xc;
    CacheSync(4);
    puVar6 = *(undefined4 **)(iVar1 + 0xcc);
    do {
      puVar4 = puVar6;
      puVar6 = (undefined4 *)*puVar4;
    } while (puVar6 != (undefined4 *)0x0);
    *puVar4 = param_2;
    CacheSync(4);
    uVar3 = 1;
    DAT_c0139420 = DAT_c013944c * param_3 + DAT_c0139420;
    DAT_c0139414 = DAT_c0139410 + DAT_c0139420;
  }
  return uVar3;
}



/* c010297c FUN_c010297c */

/* Boundary evidence: original MIPS .pdata c010297c..c01029e3. Semantic name remains unreviewed. */

void FUN_c010297c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (0xef < *(uint *)(iVar1 + 0xe8)) {
    RaiseException(1,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)(*(int *)(iVar1 + 0xe8) * 0x10 + iVar1 + 0xfc) = 0;
  *(int *)(iVar1 + 0xe8) = *(int *)(iVar1 + 0xe8) + 1;
  return;
}



/* c01029e4 FUN_c01029e4 */

/* Boundary evidence: original MIPS .pdata c01029e4..c0102aa3. Semantic name remains unreviewed. */

void FUN_c01029e4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (0xef < *(uint *)(iVar1 + 0xe8)) {
    RaiseException(1,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)(*(int *)(iVar1 + 0xe8) * 0x10 + iVar1 + 0xfc) = param_2;
  *(undefined4 *)((*(int *)(iVar1 + 0xe8) + 0x10) * 0x10 + iVar1) = param_3;
  *(undefined4 *)(*(int *)(iVar1 + 0xe8) * 0x10 + iVar1 + 0x104) = param_4;
  *(undefined4 *)(*(int *)(iVar1 + 0xe8) * 0x10 + iVar1 + 0x108) = param_5;
  *(int *)(iVar1 + 0xe8) = *(int *)(iVar1 + 0xe8) + 1;
  return;
}



/* c0102aa4 FUN_c0102aa4 */

/* Boundary evidence: original MIPS .pdata c0102aa4..c0102b3f. Semantic name remains unreviewed. */

void FUN_c0102aa4(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_18 [8];
  
  iVar4 = param_1[2];
  iVar3 = *(int *)(iVar4 + 0xe8) + -1;
  piVar2 = (int *)(iVar3 * 0x10 + iVar4 + 0xfc);
  iVar1 = *piVar2;
  while (iVar1 != 0) {
    piVar2 = piVar2 + -4;
    iVar3 = iVar3 + -1;
    iVar1 = *piVar2;
  }
  if (param_1 == &DAT_c01391e0) {
    if (DAT_c0136ccc == 0) {
      CacheSync(4);
    }
    else {
      CacheRangeFlush(auStack_18,4,0x24);
    }
  }
  *(int *)(iVar4 + 0xe8) = iVar3;
  return;
}



/* c0102b40 FUN_c0102b40 */

/* Boundary evidence: original MIPS .pdata c0102b40..c0102ce7. Semantic name remains unreviewed. */

void FUN_c0102b40(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  size_t _Size;
  int iVar4;
  uint uVar5;
  
  iVar1 = *param_2;
  iVar3 = *(int *)(param_1 + 8);
  if (iVar1 == 1) {
    iVar1 = param_2[3];
    if (iVar1 == 1) {
      *(char *)((*(int *)(param_1 + 0x230) - *(int *)(iVar3 + 0xe4)) + param_2[1]) =
           (char)param_2[2];
    }
    else if (iVar1 == 2) {
      *(short *)((*(int *)(param_1 + 0x230) - *(int *)(iVar3 + 0xe4)) + param_2[1]) =
           (short)param_2[2];
    }
    else if (iVar1 == 4) {
      *(int *)((*(int *)(param_1 + 0x230) - *(int *)(iVar3 + 0xe4)) + param_2[1]) = param_2[2];
    }
  }
  else if (iVar1 == 2) {
    FUN_c00f5bb4(param_2[1],param_2[2],param_2[3]);
  }
  else if (iVar1 == 3) {
    iVar3 = *(int *)(param_1 + 0x230) - *(int *)(iVar3 + 0xe4);
    iVar1 = param_2[2];
    iVar4 = param_2[1] + iVar3;
    uVar5 = (*(uint *)(iVar4 + -0xc) & 0xffffffc) + 0xc;
    while (iVar2 = param_2[3], iVar2 != 0) {
      if (uVar5 == 0) {
        trap(0x1c00);
      }
      _Size = (iVar2 - 1U) % uVar5 + 1;
      memcpy((void *)((iVar2 - _Size) + iVar1 + iVar3),(void *)((iVar2 - _Size) + iVar4),_Size);
      CacheSync(4);
      param_2[3] = param_2[3] - _Size;
    }
  }
  else if (iVar1 == 4) {
    FUN_c00f4ce4(param_2[1],param_2[2]);
  }
  return;
}



/* c0102ce8 FUN_c0102ce8 */

/* Boundary evidence: original MIPS .pdata c0102ce8..c0102e23. Semantic name remains unreviewed. */

void FUN_c0102ce8(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar2 = (uint *)((int)param_2 + (*param_2 & 0xffffffc) + 0xc);
  iVar3 = 0;
  if (puVar2 == *(uint **)(param_1 + 0x234)) {
    puVar2 = *(uint **)(param_1 + 0x230);
  }
  if (param_2 < puVar2) {
    do {
      if ((*puVar2 & 1) == 0) break;
      FUN_c0102064(param_1,puVar2);
      iVar3 = (*puVar2 & 0xffffffc) + iVar3 + 0xc;
      puVar2 = (uint *)((int)puVar2 + (*puVar2 & 0xffffffc) + 0xc);
      iVar4 = iVar4 + 0xc;
      if (puVar2 == *(uint **)(param_1 + 0x234)) {
        puVar2 = *(uint **)(param_1 + 0x230);
      }
    } while (param_2 < puVar2);
    if (iVar3 != 0) {
      *param_2 = *param_2 + iVar3;
      CacheSync(4);
      if (((*param_2 & 0xffffffc) < iVar3 + 8U) && (7 < (*param_2 & 0xffffffc))) {
        puVar2 = param_2 + 3;
        *puVar2 = 0;
        puVar1 = *(undefined4 **)(param_1 + 0x248);
        param_2[4] = (uint)puVar1;
        if (puVar1 != (undefined4 *)0x0) {
          *puVar1 = puVar2;
        }
        *(uint **)(param_1 + 0x248) = puVar2;
      }
      *(int *)(param_1 + 0x23c) = iVar4 + *(int *)(param_1 + 0x23c);
    }
  }
  return;
}



/* c0102e24 FUN_c0102e24 */

/* Boundary evidence: original MIPS .pdata c0102e24..c0102f5f. Semantic name remains unreviewed. */

void FUN_c0102e24(undefined4 *param_1,uint *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = (*param_2 & 0xffffffc) - param_3;
  FUN_c0102064((int)param_1,param_2);
  if (0xc < uVar4) {
    puVar3 = (uint *)((int)param_2 + param_3 + 0xc);
    FUN_c010297c((int)param_1);
    FUN_c0105008(param_1,(int)puVar3);
    uVar4 = uVar4 - 0xc;
    *puVar3 = uVar4 | 1;
    if (7 < (uVar4 & 0xffffffc)) {
      puVar1 = (undefined4 *)((int)param_2 + param_3 + 0x18);
      *puVar1 = 0;
      puVar2 = (undefined4 *)param_1[0x92];
      *(undefined4 **)((int)param_2 + param_3 + 0x1c) = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = puVar1;
      }
      param_1[0x92] = puVar1;
    }
    FUN_c01029e4((int)param_1,1,param_2,*param_2,4);
    FUN_c01029e4((int)param_1,1,param_2 + 1,param_2[1],4);
    FUN_c0105008(param_1,(int)param_2);
    *param_2 = param_3 | 1;
    FUN_c0102aa4(param_1);
    param_1[0x8f] = param_1[0x8f] + -0xc;
  }
  return;
}



/* c0102f60 FUN_c0102f60 */

/* Boundary evidence: original MIPS .pdata c0102f60..c01031b7. Semantic name remains unreviewed. */

void FUN_c0102f60(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  undefined4 *puVar9;
  
  iVar1 = FUN_c0101d64(param_1,param_2);
  iVar2 = FUN_c0101d64(param_1,param_3);
  uVar3 = *(undefined4 *)(iVar2 + 4);
  puVar9 = (undefined4 *)(iVar1 + 4);
  uVar4 = *puVar9;
  uVar6 = param_2 >> 10 & 0xffff;
  if ((uVar6 == 0) || (iVar5 = *(int *)(param_1 + 0x238), *(int *)(uVar6 * 4 + iVar5) != 0)) {
    iVar5 = *(int *)(param_1 + 0x238);
    iVar8 = *(int *)(uVar6 * 4 + iVar5) + *(int *)(param_1 + 0x230) + 0xc;
  }
  else {
    iVar8 = 0;
  }
  uVar6 = param_3 >> 10 & 0xffff;
  if ((uVar6 == 0) || (*(int *)(uVar6 * 4 + iVar5) != 0)) {
    iVar5 = *(int *)(uVar6 * 4 + iVar5) + *(int *)(param_1 + 0x230) + 0xc;
  }
  else {
    iVar5 = 0;
  }
  puVar7 = (uint *)(iVar1 + 8);
  FUN_c01029e4(param_1,1,puVar7,*puVar7,4);
  *puVar7 = param_3;
  puVar7 = (uint *)((param_3 & 0x3ff) * 4 + iVar5);
  FUN_c01029e4(param_1,1,puVar7,*puVar7,4);
  *puVar7 = iVar1 - *(int *)(param_1 + 0x230) | *puVar7 & 0xf0000001 | 1;
  FUN_c01029e4(param_1,1,puVar9,*puVar9,4);
  puVar7 = (uint *)(iVar2 + 8);
  *puVar9 = uVar3;
  FUN_c01029e4(param_1,1,puVar7,*puVar7,4);
  *puVar7 = param_2;
  puVar7 = (uint *)((param_2 & 0x3ff) * 4 + iVar8);
  FUN_c01029e4(param_1,1,puVar7,*puVar7,4);
  *puVar7 = iVar2 - *(int *)(param_1 + 0x230) | *puVar7 & 0xf0000001 | 1;
  puVar9 = (undefined4 *)(iVar2 + 4);
  FUN_c01029e4(param_1,1,puVar9,*puVar9,4);
  *puVar9 = uVar4;
  return;
}



/* c01031b8 FUN_c01031b8 */

/* Boundary evidence: original MIPS .pdata c01031b8..c0103337. Semantic name remains unreviewed. */

undefined4 FUN_c01031b8(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  memset((void *)param_1[0x8e],0,0x4000);
  puVar4 = (undefined4 *)param_1[0x8c];
  *puVar4 = 0x20001004;
  FUN_c0104fb4(param_1,(int)puVar4);
  piVar3 = puVar4 + 3;
  puVar4[2] = 0;
  *(undefined4 *)param_1[0x8e] = 0;
  iVar1 = 0x40000;
  *(undefined2 *)(puVar4 + 0x403) = 0;
  do {
    *piVar3 = iVar1;
    iVar1 = iVar1 + 0x40000;
    piVar3 = piVar3 + 1;
  } while (iVar1 < 0x10000000);
  puVar4[0x402] = 0;
  param_1[0x92] = 0;
  param_1[0x8f] = param_1[0x90] + -0x101c;
  FUN_c0105008(param_1,param_1[0x8c] + 0x1010);
  *(uint *)(param_1[0x8c] + 0x1010) = param_1[0x8f] | 1;
  iVar1 = param_1[0x8c];
  if (7 < (*(uint *)(iVar1 + 0x1010) & 0xffffffc)) {
    puVar4 = (undefined4 *)(iVar1 + 0x101c);
    *puVar4 = 0;
    puVar2 = (undefined4 *)param_1[0x92];
    *(undefined4 **)(iVar1 + 0x1020) = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = puVar4;
    }
    param_1[0x92] = puVar4;
  }
  *(undefined4 *)(param_1[2] + 0xe8) = 0;
  *(undefined4 *)(param_1[2] + 0xe4) = param_1[0x8c];
  *(undefined4 *)(param_1[2] + 0xf4) = 0;
  *(undefined4 *)(param_1[2] + 0xec) = 0xffffffff;
  *(undefined4 *)(param_1[2] + 0xf0) = 0xffffffff;
  *(undefined4 *)(param_1[2] + 0xf8) = 0;
  if ((param_2 & 1) != 0) {
    FUN_c00f6444(param_1);
  }
  if ((param_2 & 2) != 0) {
    FUN_c011dae0(param_1);
  }
  return 1;
}



/* c0103338 FUN_c0103338 */

/* Boundary evidence: original MIPS .pdata c0103338..c0103433. Semantic name remains unreviewed. */

void FUN_c0103338(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  
  puVar4 = *(uint **)(param_1 + 0x230);
  *(undefined4 *)(param_1 + 0x23c) = 0;
  *(undefined4 *)(param_1 + 0x248) = 0;
  *(undefined4 *)(param_1 + 0x244) = *(undefined4 *)(param_1 + 0x234);
  do {
    uVar2 = *puVar4;
    if ((uVar2 & 1) == 0) {
      if ((uVar2 & 0xf0000000) == 0xf0000000) {
        FUN_c00f5244(puVar4[2]);
      }
    }
    else {
      if (7 < (uVar2 & 0xffffffc)) {
        puVar3 = puVar4 + 3;
        *puVar3 = 0;
        puVar1 = *(undefined4 **)(param_1 + 0x248);
        puVar4[4] = (uint)puVar1;
        if (puVar1 != (undefined4 *)0x0) {
          *puVar1 = puVar3;
        }
        *(uint **)(param_1 + 0x248) = puVar3;
      }
      *(uint *)(param_1 + 0x23c) = (*puVar4 & 0xffffffc) + *(int *)(param_1 + 0x23c);
      if (puVar4 < *(uint **)(param_1 + 0x244)) {
        *(uint **)(param_1 + 0x244) = puVar4;
      }
    }
    puVar4 = (uint *)((int)puVar4 + (*puVar4 & 0xffffffc) + 0xc);
    if (puVar4 == *(uint **)(param_1 + 0x234)) {
      puVar4 = *(uint **)(param_1 + 0x230);
    }
  } while (puVar4 != *(uint **)(param_1 + 0x230));
  return;
}



/* c0103434 FUN_c0103434 */

/* Boundary evidence: original MIPS .pdata c0103434..c010353f. Semantic name remains unreviewed. */

uint FUN_c0103434(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  
  iVar2 = FUN_c0101de8(param_1,param_2);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(iVar2 + -0xc) >> 0x1c;
    if (uVar3 == 4) {
      uVar3 = FUN_c00f6e0c(param_2,param_3);
      return uVar3;
    }
    if (uVar3 == 5) {
      uVar3 = FUN_c00f6ffc(param_2,param_3);
      return uVar3;
    }
    if (uVar3 == 7) {
      uVar3 = FUN_c011de58(param_1,param_2,param_3);
      return uVar3;
    }
    if (uVar3 == 8) {
      bVar1 = FUN_c0125e24(param_1,param_2,param_3);
      return CONCAT31(extraout_var,bVar1);
    }
  }
  SetLastError(0x57);
  return 0;
}



/* c0103540 FUN_c0103540 */

/* Boundary evidence: original MIPS .pdata c0103540..c0103607. Semantic name remains unreviewed. */

undefined4 FUN_c0103540(int param_1,undefined *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 0x230);
  if (puVar2 < *(uint **)(param_1 + 0x234)) {
    do {
      if ((((*puVar2 & 1) == 0) && (*puVar2 >> 0x1c == param_3)) &&
         (iVar1 = (*(code *)param_2)(param_1,param_3,puVar2 + 3,param_4), iVar1 == 0)) {
        return 0;
      }
      puVar2 = (uint *)((int)puVar2 + (*puVar2 & 0xffffffc) + 0xc);
    } while (puVar2 < *(uint **)(param_1 + 0x234));
  }
  return 1;
}



/* c0103608 FUN_c0103608 */

/* Boundary evidence: original MIPS .pdata c0103608..c01036ab. Semantic name remains unreviewed. */

void FUN_c0103608(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (7 < (*param_2 & 0xffffffc)) {
    puVar3 = param_2 + 3;
    FUN_c01029e4(param_1,1,puVar3,*puVar3,4);
    puVar2 = param_2 + 4;
    FUN_c01029e4(param_1,1,puVar2,*puVar2,4);
    *puVar3 = 0;
    puVar1 = *(undefined4 **)(param_1 + 0x248);
    *puVar2 = (uint)puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = puVar3;
    }
    *(uint **)(param_1 + 0x248) = puVar3;
  }
  return;
}



/* c01036ac FUN_c01036ac */

/* Boundary evidence: original MIPS .pdata c01036ac..c0103767. Semantic name remains unreviewed. */

void FUN_c01036ac(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1[2];
  iVar4 = *(int *)(iVar3 + 0xe8) + -1;
  piVar2 = (int *)(iVar4 * 0x10 + iVar3 + 0xfc);
  iVar1 = *piVar2;
  while (iVar1 != 0) {
    FUN_c0102b40((int)param_1,piVar2);
    iVar4 = iVar4 + -1;
    piVar2 = (int *)(iVar4 * 0x10 + iVar3 + 0xfc);
    iVar1 = *piVar2;
  }
  CacheSync(4);
  *(int *)(iVar3 + 0xe8) = iVar4;
  FUN_c0103338((int)param_1);
  if ((*(int *)(iVar3 + 0xe8) == 0) && (*(int *)(param_1[2] + 0xec) != -1)) {
    FUN_c0120c10(param_1);
  }
  return;
}



/* c0103768 FUN_c0103768 */

/* Boundary evidence: original MIPS .pdata c0103768..c01037ef. Semantic name remains unreviewed. */

void FUN_c0103768(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (*(int *)(iVar1 + 0xe8) == 0) {
    if (param_1[0x8f] == 0) {
      FUN_c0103338((int)param_1);
    }
  }
  else {
    do {
      FUN_c01036ac(param_1);
    } while (*(int *)(iVar1 + 0xe8) != 0);
  }
  if (*(int *)(param_1[2] + 0xec) != -1) {
    FUN_c0120c10(param_1);
  }
  return;
}



/* c01037f0 FUN_c01037f0 */

/* Boundary evidence: original MIPS .pdata c01037f0..c0103a9b. Semantic name remains unreviewed. */

void FUN_c01037f0(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  
  if (param_2 == 0) {
    RaiseException(1,1,0,(ULONG_PTR *)0x0);
  }
  else {
    puVar1 = (uint *)FUN_c0101d64((int)param_1,param_2);
    uVar2 = *puVar1;
    uVar3 = param_2 >> 10 & 0xffff;
    if ((uVar3 == 0) || (*(int *)(uVar3 * 4 + param_1[0x8e]) != 0)) {
      iVar5 = *(int *)(uVar3 * 4 + param_1[0x8e]) + param_1[0x8c] + 0xc;
    }
    else {
      iVar5 = 0;
    }
    puVar4 = (uint *)((param_2 & 0x3ff) * 4 + iVar5);
    FUN_c01029e4((int)param_1,1,puVar4,*puVar4,4);
    puVar6 = (ushort *)(iVar5 + 0x1000);
    *puVar4 = (*puVar4 & 0xf0000000) + 0x10000000 | (uint)*puVar6 << 0x12;
    FUN_c01029e4((int)param_1,1,puVar6,(uint)*puVar6,2);
    *puVar6 = (ushort)(param_2 & 0x3ff);
    uVar7 = *puVar1 & 0xffffffc;
    puVar4 = puVar1;
    uVar3 = uVar7;
    while( true ) {
      puVar4 = (uint *)((int)puVar4 + (*puVar4 & 0xffffffc) + 0xc);
      if (puVar4 == (uint *)param_1[0x8d]) {
        puVar4 = (uint *)param_1[0x8c];
      }
      if ((puVar4 <= puVar1) || ((*puVar4 & 1) == 0)) break;
      FUN_c0102064((int)param_1,puVar4);
      uVar3 = (*puVar4 & 0xffffffc) + uVar3 + 0xc;
      uVar7 = uVar7 + 0xc;
    }
    FUN_c01029e4((int)param_1,1,puVar1,*puVar1,4);
    FUN_c01029e4((int)param_1,1,puVar1 + 1,puVar1[1],4);
    FUN_c0105008(param_1,(int)puVar1);
    *puVar1 = uVar3 | 1;
    FUN_c0103608((int)param_1,puVar1);
    param_1[0x8f] = param_1[0x8f] + uVar7;
    *(short *)(param_1 + 0x93) = *(short *)(param_1 + 0x93) + 1;
    if (puVar1 < (uint *)param_1[0x91]) {
      param_1[0x91] = puVar1;
    }
    uVar3 = param_1[0x96] + (uVar2 & 0xffffffc) + 4;
    param_1[0x96] = uVar3;
    uVar2 = *(uint *)(param_1[2] + 0xf8);
    if (((uVar2 & 0x10) == 0) && (0x5fff < uVar3)) {
      *(uint *)(param_1[2] + 0xf8) = uVar2 | 0x10;
    }
    FUN_c0101f34(param_1,0);
  }
  return;
}



/* c0103a9c FUN_c0103a9c */

/* Boundary evidence: original MIPS .pdata c0103a9c..c0103dc7. Semantic name remains unreviewed. */

void FUN_c0103a9c(undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  
  iVar1 = FUN_c0101d64((int)param_1,param_2);
  puVar2 = (uint *)FUN_c0101d64((int)param_1,param_3);
  uVar3 = puVar2[1];
  uVar4 = param_2 >> 10 & 0xffff;
  if ((uVar4 == 0) || (*(int *)(uVar4 * 4 + param_1[0x8e]) != 0)) {
    iVar6 = *(int *)(uVar4 * 4 + param_1[0x8e]) + param_1[0x8c] + 0xc;
  }
  else {
    iVar6 = 0;
  }
  puVar5 = (uint *)((param_2 & 0x3ff) * 4 + iVar6);
  FUN_c01029e4((int)param_1,1,puVar5,*puVar5,4);
  puVar7 = (ushort *)(iVar6 + 0x1000);
  *puVar5 = (uint)*puVar7 << 0x12 | (*puVar5 & 0xf0000000) + 0x10000000;
  FUN_c01029e4((int)param_1,1,puVar7,(uint)*puVar7,2);
  *puVar7 = (ushort)(param_2 & 0x3ff);
  uVar8 = *puVar2 & 0xffffffc;
  puVar5 = puVar2;
  uVar4 = uVar8;
  while( true ) {
    puVar5 = (uint *)((int)puVar5 + (*puVar5 & 0xffffffc) + 0xc);
    if (puVar5 == (uint *)param_1[0x8d]) {
      puVar5 = (uint *)param_1[0x8c];
    }
    if ((puVar5 <= puVar2) || ((*puVar5 & 1) == 0)) break;
    FUN_c0102064((int)param_1,puVar5);
    uVar4 = (*puVar5 & 0xffffffc) + uVar4 + 0xc;
    uVar8 = uVar8 + 0xc;
  }
  FUN_c01029e4((int)param_1,1,puVar2,*puVar2,4);
  puVar5 = puVar2 + 1;
  FUN_c01029e4((int)param_1,1,puVar5,*puVar5,4);
  *puVar5 = *(uint *)(iVar1 + 4);
  FUN_c0105008(param_1,(int)puVar2);
  *puVar2 = uVar4 | 1;
  FUN_c0103608((int)param_1,puVar2);
  param_1[0x8f] = uVar8 + param_1[0x8f];
  *(short *)(param_1 + 0x93) = *(short *)(param_1 + 0x93) + 1;
  if (puVar2 < (uint *)param_1[0x91]) {
    param_1[0x91] = puVar2;
  }
  FUN_c0101f34(param_1,0);
  puVar2 = (uint *)(iVar1 + 8);
  FUN_c01029e4((int)param_1,1,puVar2,*puVar2,4);
  uVar4 = param_3 >> 10 & 0xffff;
  *puVar2 = param_3;
  if ((uVar4 == 0) || (*(int *)(uVar4 * 4 + param_1[0x8e]) != 0)) {
    iVar6 = *(int *)(uVar4 * 4 + param_1[0x8e]) + param_1[0x8c] + 0xc;
  }
  else {
    iVar6 = 0;
  }
  puVar2 = (uint *)((param_3 & 0x3ff) * 4 + iVar6);
  FUN_c01029e4((int)param_1,1,puVar2,*puVar2,4);
  *puVar2 = iVar1 - param_1[0x8c] | *puVar2 & 0xf0000001 | 1;
  *(uint *)(iVar1 + 4) = uVar3;
  return;
}



/* c0103dc8 FUN_c0103dc8 */

/* Boundary evidence: original MIPS .pdata c0103dc8..c0104343. Semantic name remains unreviewed. */

uint * FUN_c0103dc8(undefined4 *param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint local_34;
  
  local_34 = 0;
  uVar10 = 0;
  puVar11 = (uint *)0x0;
  bVar1 = false;
  if (param_2 == 2) {
    uVar6 = 0x1004;
    local_34 = param_3;
  }
  else {
    uVar10 = 0;
    iVar7 = 0;
    do {
      if ((uVar10 == 0) || (*(int *)(param_1[0x8e] + iVar7) != 0)) {
        iVar5 = *(int *)(param_1[0x8e] + iVar7) + param_1[0x8c];
        puVar11 = (uint *)(iVar5 + 0xc);
        if ((puVar11 != (uint *)0x0) && ((*(short *)(iVar5 + 0x100c) != 0 || ((*puVar11 & 1) == 0)))
           ) break;
      }
      else {
        puVar11 = (uint *)0x0;
      }
      iVar7 = iVar7 + 4;
      uVar10 = uVar10 + 1;
    } while (iVar7 < 0x4000);
    uVar6 = param_3;
    if (uVar10 == 0x1000) {
      piVar2 = (int *)param_1[0x8e];
      uVar10 = 1;
      do {
        piVar2 = piVar2 + 1;
        if (*piVar2 == 0) {
          FUN_c010297c((int)param_1);
          puVar9 = FUN_c0103dc8(param_1,2,uVar10,1,0);
          if (puVar9 == (uint *)0x0) {
            FUN_c01036ac(param_1);
            if (param_5 == 0) {
              return (uint *)0x0;
            }
            bVar1 = true;
          }
          else {
            puVar11 = puVar9 + 3;
            *(undefined2 *)(puVar9 + 0x403) = 0;
            uVar12 = 0x40000;
            puVar4 = puVar11;
            do {
              *puVar4 = uVar12;
              uVar12 = uVar12 + 0x40000;
              puVar4 = puVar4 + 1;
            } while ((int)uVar12 < 0x10000000);
            puVar9[0x402] = 0;
            puVar3 = (undefined4 *)(uVar10 * 4 + param_1[0x8e]);
            FUN_c01029e4((int)param_1,1,puVar3,*puVar3,4);
            *(int *)(uVar10 * 4 + param_1[0x8e]) = (int)puVar9 - param_1[0x8c];
            FUN_c0102aa4(param_1);
          }
          break;
        }
        uVar10 = uVar10 + 1;
      } while ((int)uVar10 < 0x1000);
      if (uVar10 == 0x1000) {
        return (uint *)0x0;
      }
    }
  }
  uVar12 = uVar6 + 3 & 0xfffffffc;
  if (uVar12 < uVar6) {
    return (uint *)0x0;
  }
  if ((((param_4 & 1) == 0) && ((uint)param_1[0x8f] < 0x6001)) && (param_1 == &DAT_c01391e0)) {
    return (uint *)0x0;
  }
  if (!bVar1) {
    if (uVar12 < (uint)param_1[0x8f]) {
      for (iVar7 = param_1[0x92]; iVar7 != 0; iVar7 = *(int *)(iVar7 + 4)) {
        puVar9 = (uint *)(iVar7 + -0xc);
        FUN_c0102ce8((int)param_1,puVar9);
        if (uVar12 <= (*puVar9 & 0xffffffc)) goto LAB_c01041a8;
      }
    }
    if (param_1 == &DAT_c01391e0) {
LAB_c010406c:
      puVar9 = (uint *)0x0;
    }
    else {
      puVar9 = (uint *)param_1[0x8d];
      iVar7 = FUN_c012385c((int)param_1,0x6000);
      if (iVar7 == 0) goto LAB_c010406c;
LAB_c01041a8:
      FUN_c0102e24(param_1,puVar9,uVar12);
    }
    if (puVar9 != (uint *)0x0) {
      param_1[0x8f] = param_1[0x8f] - (*puVar9 & 0xffffffc);
      if (param_2 != 2) {
        FUN_c0104fd0();
        puVar8 = puVar11 + 0x400;
        uVar6 = (uint)(ushort)*puVar8;
        local_34 = uVar10 * 0x400 + uVar6;
        FUN_c01029e4((int)param_1,1,puVar8,uVar6,2);
        puVar4 = puVar11 + uVar6;
        *(ushort *)puVar8 = (ushort)(puVar11[(ushort)*puVar8] >> 0x12) & 0x3ff;
        FUN_c01029e4((int)param_1,1,puVar4,*puVar4,4);
        *puVar4 = (int)puVar9 - param_1[0x8c] | *puVar4 & 0xf0000001 | 1;
      }
      puVar9[2] = local_34;
      FUN_c01029e4((int)param_1,1,puVar9,*puVar9,4);
      FUN_c01029e4((int)param_1,1,puVar9 + 1,puVar9[1],4);
      goto LAB_c01042d0;
    }
  }
  if (param_5 == 0) {
    return (uint *)0x0;
  }
  puVar9 = (uint *)FUN_c0101d64((int)param_1,param_5);
  if ((puVar9 == (uint *)0x0) || ((*puVar9 & 0xffffffc) < uVar12)) {
    return (uint *)0x0;
  }
  FUN_c01029e4((int)param_1,1,puVar9,*puVar9,4);
  puVar11 = puVar9 + 1;
  FUN_c01029e4((int)param_1,1,puVar11,*puVar11,4);
  FUN_c0105008(param_1,(int)puVar9);
  uVar10 = *puVar9;
  *puVar9 = uVar10 & 0xffffffc | 1;
  if (7 < (uVar10 & 0xffffffc)) {
    puVar4 = puVar9 + 3;
    *puVar4 = 0;
    puVar3 = (undefined4 *)param_1[0x92];
    puVar9[4] = (uint)puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar4;
    }
    param_1[0x92] = puVar4;
  }
  FUN_c0102e24(param_1,puVar9,uVar12);
  puVar9[2] = param_5;
  FUN_c01029e4((int)param_1,1,puVar9,*puVar9,4);
  FUN_c01029e4((int)param_1,1,puVar11,*puVar11,4);
LAB_c01042d0:
  *puVar9 = *puVar9 & 0xffffffc | param_2 << 0x1c;
  FUN_c0104fb4(param_1,(int)puVar9);
  FUN_c0101f34(param_1,uVar12);
  return puVar9;
}



/* c0104344 FUN_c0104344 */

/* Boundary evidence: original MIPS .pdata c0104344..c0104763. Semantic name remains unreviewed. */

undefined4 FUN_c0104344(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  uint _Size;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  
  iVar12 = param_1[2];
  puVar10 = (uint *)param_1[0x91];
  puVar8 = (uint *)param_1[0x8d];
  if (puVar10 != puVar8) {
    uVar2 = *puVar10;
    while ((uVar2 & 1) == 0) {
      puVar6 = (uint *)((int)puVar10 + (*puVar10 & 0xffffffc) + 0xc);
      puVar9 = puVar6;
      if (puVar6 == puVar8) {
        puVar9 = (uint *)param_1[0x8c];
      }
      if (puVar9 <= puVar10) break;
      if (puVar6 == puVar8) {
        puVar6 = (uint *)param_1[0x8c];
      }
      puVar10 = puVar6;
      uVar2 = *puVar6;
    }
    param_1[0x91] = puVar10;
    if ((*puVar10 & 1) != 0) {
      FUN_c0102ce8((int)param_1,puVar10);
      puVar8 = (uint *)((int)puVar10 + (*puVar10 & 0xffffffc) + 0xc);
      if (puVar8 == (uint *)param_1[0x8d]) {
        puVar8 = (uint *)param_1[0x8c];
      }
      if (puVar10 < puVar8) {
        FUN_c0102064((int)param_1,puVar10);
        FUN_c010297c((int)param_1);
        FUN_c01029e4((int)param_1,1,puVar8,*puVar8,4);
        puVar6 = puVar8 + 1;
        FUN_c01029e4((int)param_1,1,puVar6,*puVar6,4);
        puVar9 = puVar8 + 2;
        FUN_c01029e4((int)param_1,1,puVar9,*puVar9,4);
        uVar3 = *puVar8;
        uVar11 = *puVar10 & 0xffffffc;
        uVar2 = uVar3 & 0xffffffc;
        uVar4 = *puVar6;
        uVar5 = *puVar9;
        if (uVar11 < uVar2) {
          puVar8 = puVar8 + 3;
          puVar9 = puVar10 + 3;
          FUN_c01029e4((int)param_1,3,puVar9,puVar8,0);
          _Size = uVar11 + 0xc;
          for (; uVar2 != 0; uVar2 = uVar2 - _Size) {
            if (uVar2 < _Size) {
              _Size = uVar2;
            }
            memcpy(puVar9,puVar8,_Size);
            CacheSync(4);
            iVar7 = *(int *)(iVar12 + 0xe8) * 0x10 + iVar12;
            *(uint *)(iVar7 + 0xf8) = _Size + *(int *)(iVar7 + 0xf8);
            puVar9 = (uint *)(_Size + (int)puVar9);
            puVar8 = (uint *)(_Size + (int)puVar8);
          }
        }
        else {
          memcpy(puVar10 + 3,puVar8 + 3,uVar2);
        }
        FUN_c01029e4((int)param_1,1,puVar10,*puVar10,4);
        puVar8 = puVar10 + 1;
        FUN_c01029e4((int)param_1,1,puVar8,*puVar8,4);
        puVar9 = puVar10 + 2;
        FUN_c01029e4((int)param_1,1,puVar9,*puVar9,4);
        *puVar8 = uVar4;
        *puVar9 = uVar5;
        *puVar10 = uVar3;
        puVar8 = (uint *)((int)puVar10 + (uVar3 & 0xffffffc) + 0xc);
        if (puVar8 == (uint *)param_1[0x8d]) {
          puVar8 = (uint *)param_1[0x8c];
        }
        FUN_c0105008(param_1,(int)puVar8);
        *puVar8 = uVar11 | 1;
        FUN_c0103608((int)param_1,puVar8);
        if (uVar3 >> 0x1c == 2) {
          puVar1 = (undefined4 *)(*puVar9 * 4 + param_1[0x8e]);
          FUN_c01029e4((int)param_1,1,puVar1,*puVar1,4);
          *(int *)(*puVar9 * 4 + param_1[0x8e]) = (int)puVar10 - param_1[0x8c];
        }
        else {
          uVar2 = *puVar9 >> 10 & 0xffff;
          if ((uVar2 == 0) || (*(int *)(uVar2 * 4 + param_1[0x8e]) != 0)) {
            iVar12 = *(int *)(uVar2 * 4 + param_1[0x8e]) + param_1[0x8c] + 0xc;
          }
          else {
            iVar12 = 0;
          }
          puVar9 = (uint *)((*puVar9 & 0x3ff) * 4 + iVar12);
          FUN_c01029e4((int)param_1,1,puVar9,*puVar9,4);
          *puVar9 = (int)puVar10 - param_1[0x8c] | *puVar9 & 0xf0000001 | 1;
        }
        param_1[0x91] = puVar8;
        FUN_c0102aa4(param_1);
        return 0;
      }
    }
  }
  EventModify(param_1[0x88],2);
  return 1;
}



/* c0104764 FUN_c0104764 */

/* Boundary evidence: original MIPS .pdata c0104764..c010479b. Semantic name remains unreviewed. */

undefined4 FUN_c0104764(undefined4 *param_1)

{
  FUN_c0103768(param_1);
  *(undefined4 *)(param_1[2] + 0xe4) = param_1[0x8c];
  return 1;
}



/* c010479c FUN_c010479c */

/* Boundary evidence: original MIPS .pdata c010479c..c0104887. Semantic name remains unreviewed. */

undefined4 FUN_c010479c(int *param_1,uint *param_2,undefined4 *param_3)

{
  int local_20;
  uint local_1c;
  
  local_20 = 0;
  local_1c = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  *param_3 = DAT_c013944c;
  FUN_c0102770(&local_20,&local_1c);
  *param_1 = local_20;
  *param_2 = local_1c;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return 1;
}



/* c0104888 FUN_c0104888 */

/* Boundary evidence: original MIPS .pdata c0104888..c0104893. Semantic name remains unreviewed. */

undefined4 FUN_c0104888(void)

{
  return 1;
}



/* c0104894 FUN_c0104894 */

/* Boundary evidence: original MIPS .pdata c0104894..c010489f. Semantic name remains unreviewed. */

undefined4 FUN_c0104894(void)

{
  return 1;
}



/* c01048a0 FUN_c01048a0 */

/* Boundary evidence: original MIPS .pdata c01048a0..c0104b6b. Semantic name remains unreviewed. */

undefined4 FUN_c01048a0(undefined4 *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  SIZE_T dwSize;
  SIZE_T SVar8;
  LPVOID lpAddress;
  undefined4 uVar9;
  uint uVar10;
  
  iVar7 = DAT_c01391e8;
  do {
    iVar4 = FUN_c0104344(param_1);
  } while (iVar4 == 0);
  puVar6 = (uint *)param_1[0x91];
  if (((puVar6 == (uint *)param_1[0x8d]) || ((*puVar6 & 1) == 0)) ||
     ((uint *)(param_3 + param_1[0x8c]) < puVar6 + 0x1803)) {
    uVar9 = 0;
  }
  else {
    FUN_c010297c((int)param_1);
    uVar9 = 1;
    FUN_c01029e4((int)param_1,1,(undefined4 *)param_1[0x91],*(undefined4 *)param_1[0x91],4);
    FUN_c01029e4((int)param_1,1,(undefined4 *)(param_1[0x91] + 4),*(undefined4 *)(param_1[0x91] + 4)
                 ,4);
    FUN_c0105008(param_1,param_1[0x91]);
    *(uint *)param_1[0x91] = ((param_3 - (int)param_1[0x91]) + param_1[0x8c]) - 0xcU | 1;
    FUN_c0102aa4(param_1);
    iVar5 = param_1[0x8c];
    iVar4 = param_1[0x8d];
    lpAddress = (LPVOID)(iVar5 + param_3);
    param_1[0x8f] = (param_1[0x8f] - param_1[0x90]) + param_3;
    param_1[0x90] = param_3;
    param_1[0x8d] = lpAddress;
    param_1[0x91] = iVar5;
    uVar10 = (param_3 + 0x4000U) / DAT_c013944c;
    SVar8 = (iVar4 - iVar5) - param_3;
    if (DAT_c013944c == 0) {
      trap(0x1c00);
    }
    piVar3 = *(int **)(iVar7 + 0xcc);
    piVar2 = (int *)0x0;
    while ((piVar1 = piVar3, piVar1 != (int *)0x0 && ((uint)piVar1[1] < uVar10))) {
      uVar10 = uVar10 - piVar1[1];
      piVar2 = piVar1;
      piVar3 = (int *)*piVar1;
    }
    if (uVar10 == piVar1[1]) {
      iVar7 = *piVar1;
      *piVar1 = 0;
      CacheSync(4);
      GiveKPhys(param_2,1);
      *param_2 = iVar7;
    }
    else {
      memcpy((void *)(*param_2 + 8),piVar1 + 2,uVar10 << 2);
      *(undefined4 *)*param_2 = 0;
      *(uint *)(*param_2 + 4) = uVar10;
      CacheSync(4);
      if (piVar2 == (int *)0x0) {
        *(int *)(iVar7 + 0xcc) = *param_2;
      }
      else {
        *piVar2 = *param_2;
      }
      CacheSync(4);
      memmove(piVar1 + 2,piVar1 + uVar10 + 2,(piVar1[1] - uVar10) * 4);
      piVar1[1] = piVar1[1] - uVar10;
      *param_2 = (int)piVar1;
    }
    for (; SVar8 != 0; SVar8 = SVar8 - dwSize) {
      dwSize = SVar8;
      if ((((int)lpAddress + (SVar8 - 1) ^ (uint)lpAddress) & 0xfe000000) != 0) {
        dwSize = 0x2000000 - ((uint)lpAddress & 0x1ffffff);
      }
      VirtualFree(lpAddress,dwSize,0x4000);
      lpAddress = (LPVOID)(dwSize + (int)lpAddress);
    }
  }
  return uVar9;
}



/* c0104b6c FUN_c0104b6c */

/* Boundary evidence: original MIPS .pdata c0104b6c..c0104f9b. Semantic name remains unreviewed. */

undefined4 FUN_c0104b6c(uint param_1)

{
  int iVar1;
  int iVar2;
  DWORD dwErrCode;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *local_48;
  int *local_44;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  
  iVar2 = DAT_c01391e8;
  uVar5 = 3;
  local_40 = 3;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  FUN_c0102770((int *)&local_38,&local_34);
  if (DAT_c013944c == 0) {
    trap(0x1c00);
  }
  if ((local_38 + local_34 < 0x20000 / DAT_c013944c + param_1) || (param_1 < 0x20000 / DAT_c013944c)
     ) {
LAB_c0104f00:
    dwErrCode = 0x57;
LAB_c0104f04:
    SetLastError(dwErrCode);
  }
  else {
    if (DAT_c013944c == 0) {
      trap(0x1c00);
    }
    if (DAT_c0139450 / DAT_c013944c < param_1) {
      param_1 = DAT_c0139450 / DAT_c013944c;
    }
    if (param_1 < local_38) {
      iVar1 = GetKPhys(&local_44,1);
      if (iVar1 == 0) goto LAB_c0104f14;
      local_30 = 1;
      uVar3 = param_1;
      for (local_48 = *(int **)(iVar2 + 0xcc);
          (local_48 != (int *)0x0 && ((uint)local_48[1] <= uVar3)); local_48 = (int *)*local_48) {
        uVar3 = (uVar3 - local_48[1]) - 1;
        local_30 = local_30 + 1;
      }
      iVar2 = FUN_c01048a0(&DAT_c01391e0,(int *)&local_44,
                           (param_1 - local_30) * DAT_c013944c + -0x4000);
      if (iVar2 == 0) {
        dwErrCode = 0x70;
        goto LAB_c0104f04;
      }
      do {
        local_48 = (int *)*local_44;
        GiveKPhys(local_44 + 2,local_44[1]);
        GiveKPhys(&local_44,1);
        local_44 = local_48;
      } while (local_48 != (int *)0x0);
    }
    else if (local_38 + 1 < param_1) {
      uVar8 = ((param_1 - local_38) + 0xfe) / 0xff;
      uVar3 = (param_1 - local_38) - uVar8;
      local_44 = (int *)0x0;
      local_3c = uVar3;
      if ((uVar8 == 0) && (uVar3 != 0)) goto LAB_c0104f00;
      for (uVar7 = 0; piVar4 = local_44, uVar6 = uVar3, local_2c = uVar7, uVar7 < uVar8;
          uVar7 = uVar7 + 1) {
        iVar2 = GetKPhys(&local_48,1);
        if (iVar2 == 0) goto LAB_c0104dcc;
        *local_48 = (int)local_44;
        local_44 = local_48;
      }
      while (local_48 = piVar4, uVar6 != 0) {
        uVar8 = 0xfe;
        if (uVar6 < 0xff) {
          uVar8 = uVar6;
        }
        iVar2 = GetKPhys(piVar4 + 2,uVar8);
        piVar4 = local_48;
        if (iVar2 == 0) goto LAB_c0104e68;
        local_48[1] = uVar8;
        local_3c = uVar6 - uVar8;
        piVar4 = (int *)*local_48;
        uVar6 = local_3c;
      }
      iVar2 = FUN_c0102800(-0x3fec6e20,local_44,uVar3);
      if (iVar2 == 0) goto LAB_c0104f14;
    }
    uVar5 = 0;
    local_40 = 0;
  }
  goto LAB_c0104f14;
LAB_c0104dcc:
  while (local_44 != (int *)0x0) {
    local_48 = (int *)*local_44;
    GiveKPhys(&local_44,1);
    local_44 = local_48;
  }
  goto LAB_c0104f14;
LAB_c0104e68:
  while (local_44 != piVar4) {
    local_48 = (int *)*local_44;
    GiveKPhys(local_44 + 2,local_44[1]);
    GiveKPhys(&local_44,1);
    local_44 = local_48;
  }
  while (local_44 != (int *)0x0) {
    local_48 = (int *)*local_44;
    GiveKPhys(&local_44,1);
    local_44 = local_48;
  }
LAB_c0104f14:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar5;
}



/* c0104f9c FUN_c0104f9c */

/* Boundary evidence: original MIPS .pdata c0104f9c..c0104fa7. Semantic name remains unreviewed. */

undefined4 FUN_c0104f9c(void)

{
  return 1;
}



/* c0104fa8 FUN_c0104fa8 */

/* Boundary evidence: original MIPS .pdata c0104fa8..c0104fb3. Semantic name remains unreviewed. */

undefined4 FUN_c0104fa8(void)

{
  return 1;
}



/* c0104fb4 FUN_c0104fb4 */

void FUN_c0104fb4(undefined4 param_1,int param_2)

{
  *(int *)(param_2 + 4) = *(int *)(DAT_c01391e8 + 0xf4) << 0x1c;
  return;
}



/* c0104fd0 FUN_c0104fd0 */

undefined4 FUN_c0104fd0(void)

{
  return 1;
}



/* c0104fd8 FUN_c0104fd8 */

void FUN_c0104fd8(undefined4 param_1,int param_2)

{
  *(uint *)(param_2 + 4) =
       (*(int *)(DAT_c01391e8 + 0xf4) << 0x1c | *(uint *)(param_2 + 4)) & 0xbfffffff;
  return;
}



/* c0105008 FUN_c0105008 */

void FUN_c0105008(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 4) = 0;
  return;
}



/* c0105010 FUN_c0105010 */

/* Boundary evidence: original MIPS .pdata c0105010..c010502b. Semantic name remains unreviewed. */

void FUN_c0105010(int param_1)

{
  FUN_c0101ab4(param_1);
  return;
}



/* c010502c FUN_c010502c */

/* Boundary evidence: original MIPS .pdata c010502c..c0105103. Semantic name remains unreviewed. */

int FUN_c010502c(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 *local_30;
  undefined1 auStack_28 [16];
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = 0;
  if (param_3 == (undefined4 *)0x0) {
    SetLastError(0x57);
  }
  else if (DAT_c0139520 != 0) {
    local_38 = 2;
    local_30 = auStack_28;
    local_34 = 0x18;
    local_18 = param_2;
    local_14 = param_4;
    iVar1 = CeFsIoControlW(&DAT_c0139524,0x90098,&local_38,0xc,&local_40,8,0,0);
    iVar2 = 0;
    if ((iVar1 != 0) && (iVar2 = local_3c, local_3c != 0)) {
      *param_3 = local_40;
    }
  }
  return iVar2;
}



/* c0105104 FUN_c0105104 */

/* Boundary evidence: original MIPS .pdata c0105104..c01051d7. Semantic name remains unreviewed. */

int FUN_c0105104(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 *local_30;
  undefined1 auStack_28 [16];
  undefined4 local_18;
  
  iVar2 = 0;
  if (param_3 == (undefined4 *)0x0) {
    SetLastError(0x57);
  }
  else if (DAT_c0139520 != 0) {
    local_38 = 5;
    local_30 = auStack_28;
    local_34 = 0x14;
    local_18 = param_2;
    iVar1 = CeFsIoControlW(&DAT_c0139524,0x90098,&local_38,0xc,&local_40,8,0,0);
    iVar2 = 0;
    if ((iVar1 != 0) && (iVar2 = local_3c, local_3c != 0)) {
      *param_3 = local_40;
    }
  }
  return iVar2;
}



/* c01051d8 FUN_c01051d8 */

/* Boundary evidence: original MIPS .pdata c01051d8..c010529b. Semantic name remains unreviewed. */

undefined4 FUN_c01051d8(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  *param_1 = *(undefined4 *)(DAT_c01391e8 + 0xf4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return 1;
}



/* c010529c FUN_c010529c */

/* Boundary evidence: original MIPS .pdata c010529c..c01052a7. Semantic name remains unreviewed. */

undefined4 FUN_c010529c(void)

{
  return 1;
}



/* c01052a8 FUN_c01052a8 */

/* Boundary evidence: original MIPS .pdata c01052a8..c01052b3. Semantic name remains unreviewed. */

undefined4 FUN_c01052a8(void)

{
  return 1;
}



/* c01052cc FUN_c01052cc */

/* Boundary evidence: original MIPS .pdata c01052cc..c010569b. Semantic name remains unreviewed. */

int FUN_c01052cc(int *param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_34;
  
  local_34 = 0;
  if ((param_2 == 0) || (param_2 == 0xffffffff)) {
    SetLastError(0x57);
  }
  else if (param_2 >> 0x1c == 8) {
    local_34 = FUN_c010502c(param_1,param_2,param_3,param_4);
  }
  else {
    if (((param_1 == (int *)0x0) ||
        (((param_1[3] == 0 && param_1[2] == 0) && param_1[1] == 0) && *param_1 == 0)) &&
       (param_2 >> 0x1c == 0)) {
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c013a740;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      local_34 = 0;
      iVar1 = FUN_c0101de8(-0x3fec6e20,param_2);
      if (iVar1 == 0) {
        SetLastError(0x3ee);
      }
      else {
        *param_3 = *(uint *)(iVar1 + -8) >> 0x1c & 3;
        if ((param_4 & 1) != 0) {
          *(uint *)(iVar1 + -8) = *(uint *)(iVar1 + -8) | 0x40000000;
        }
        local_34 = 1;
      }
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
      iVar1 = IsProcessDying();
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)PTR_DAT_c0136c70;
        if (((param_1 != (int *)0x0) &&
            (((param_1[3] != 0 || param_1[2] != 0) || param_1[1] != 0) || *param_1 != 0)) &&
           (puVar2 = FUN_c0124094(param_1,2), puVar2 == (undefined4 *)0x0)) {
          SetLastError(0x57);
          puVar2 = (undefined4 *)0x0;
        }
        if (puVar2 == (undefined4 *)0x0) {
          SetLastError(0x57);
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
          local_34 = 0;
          iVar1 = FUN_c0101de8((int)puVar2,param_2);
          if (iVar1 == 0) {
            SetLastError(0x3ee);
          }
          else {
            *param_3 = *(uint *)(iVar1 + -8) >> 0x1c & 3;
            if ((param_4 & 1) != 0) {
              *(uint *)(iVar1 + -8) = *(uint *)(iVar1 + -8) | 0x40000000;
            }
            local_34 = 1;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
        }
      }
      else {
        SetLastError(0x10dc);
      }
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c0139480;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return local_34;
}



/* c010569c FUN_c010569c */

/* Boundary evidence: original MIPS .pdata c010569c..c01056a7. Semantic name remains unreviewed. */

undefined4 FUN_c010569c(void)

{
  return 1;
}



/* c01056a8 FUN_c01056a8 */

/* Boundary evidence: original MIPS .pdata c01056a8..c01056b3. Semantic name remains unreviewed. */

undefined4 FUN_c01056a8(void)

{
  return 1;
}



/* c01056b4 FUN_c01056b4 */

/* Boundary evidence: original MIPS .pdata c01056b4..c01056bf. Semantic name remains unreviewed. */

undefined4 FUN_c01056b4(void)

{
  return 1;
}



/* c01056c0 FUN_c01056c0 */

/* Boundary evidence: original MIPS .pdata c01056c0..c01056cb. Semantic name remains unreviewed. */

undefined4 FUN_c01056c0(void)

{
  return 1;
}



/* c01056cc FUN_c01056cc */

/* Boundary evidence: original MIPS .pdata c01056cc..c01056d7. Semantic name remains unreviewed. */

undefined4 FUN_c01056cc(void)

{
  return 1;
}



/* c01056d8 FUN_c01056d8 */

/* Boundary evidence: original MIPS .pdata c01056d8..c01056e3. Semantic name remains unreviewed. */

undefined4 FUN_c01056d8(void)

{
  return 1;
}



/* c01056e4 FUN_c01056e4 */

/* Boundary evidence: original MIPS .pdata c01056e4..c0105b07. Semantic name remains unreviewed. */

undefined4 FUN_c01056e4(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 local_54;
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined1 auStack_38 [16];
  uint local_28;
  uint local_24;
  
  local_54 = 0;
  if ((param_2 == 0) || (param_2 == 0xffffffff)) {
    SetLastError(0x57);
  }
  else if (param_2 >> 0x1c == 8) {
    local_54 = 0;
    if (DAT_c0139520 != 0) {
      local_48 = 3;
      local_44 = 0x18;
      local_40 = auStack_38;
      local_28 = param_2;
      local_24 = param_3;
      iVar1 = CeFsIoControlW(&DAT_c0139524,0x90098,&local_48,0xc,local_50,4,0,0);
      local_54 = 0;
      if (iVar1 != 0) {
        local_54 = local_50[0];
      }
    }
  }
  else {
    if (((param_1 == (int *)0x0) ||
        (((param_1[3] == 0 && param_1[2] == 0) && param_1[1] == 0) && *param_1 == 0)) &&
       (param_2 >> 0x1c == 0)) {
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c013a740;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      local_54 = 0;
      iVar1 = FUN_c0101de8(-0x3fec6e20,param_2);
      if (iVar1 == 0) {
        SetLastError(0x3ee);
      }
      else {
        if ((*(uint *)(iVar1 + -8) & 0x40000000) != 0) {
          *(uint *)(iVar1 + -8) = ~((param_3 & 3) << 0x1c) & *(uint *)(iVar1 + -8);
        }
        local_54 = 1;
      }
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
      iVar1 = IsProcessDying();
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)PTR_DAT_c0136c70;
        if (((param_1 != (int *)0x0) &&
            (((param_1[3] != 0 || param_1[2] != 0) || param_1[1] != 0) || *param_1 != 0)) &&
           (puVar2 = FUN_c0124094(param_1,2), puVar2 == (undefined4 *)0x0)) {
          SetLastError(0x57);
          puVar2 = (undefined4 *)0x0;
        }
        if (puVar2 == (undefined4 *)0x0) {
          SetLastError(0x57);
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
          local_54 = 0;
          iVar1 = FUN_c0101de8((int)puVar2,param_2);
          if (iVar1 == 0) {
            SetLastError(0x3ee);
          }
          else {
            if ((*(uint *)(iVar1 + -8) & 0x40000000) != 0) {
              *(uint *)(iVar1 + -8) = ~((param_3 & 3) << 0x1c) & *(uint *)(iVar1 + -8);
            }
            local_54 = 1;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
        }
      }
      else {
        SetLastError(0x10dc);
      }
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c0139480;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return local_54;
}



/* c0105b08 FUN_c0105b08 */

/* Boundary evidence: original MIPS .pdata c0105b08..c0105b13. Semantic name remains unreviewed. */

undefined4 FUN_c0105b08(void)

{
  return 1;
}



/* c0105b14 FUN_c0105b14 */

/* Boundary evidence: original MIPS .pdata c0105b14..c0105b1f. Semantic name remains unreviewed. */

undefined4 FUN_c0105b14(void)

{
  return 1;
}



/* c0105b20 FUN_c0105b20 */

/* Boundary evidence: original MIPS .pdata c0105b20..c0105b2b. Semantic name remains unreviewed. */

undefined4 FUN_c0105b20(void)

{
  return 1;
}



/* c0105b2c FUN_c0105b2c */

/* Boundary evidence: original MIPS .pdata c0105b2c..c0105b37. Semantic name remains unreviewed. */

undefined4 FUN_c0105b2c(void)

{
  return 1;
}



/* c0105b38 FUN_c0105b38 */

/* Boundary evidence: original MIPS .pdata c0105b38..c0105b43. Semantic name remains unreviewed. */

undefined4 FUN_c0105b38(void)

{
  return 1;
}



/* c0105b44 FUN_c0105b44 */

/* Boundary evidence: original MIPS .pdata c0105b44..c0105b4f. Semantic name remains unreviewed. */

undefined4 FUN_c0105b44(void)

{
  return 1;
}



/* c0105b50 FUN_c0105b50 */

/* Boundary evidence: original MIPS .pdata c0105b50..c0105f57. Semantic name remains unreviewed. */

uint FUN_c0105b50(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  uint local_54;
  uint local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined1 auStack_38 [16];
  uint local_28;
  int local_24;
  
  local_54 = 0;
  if ((param_2 == 0) || (param_2 == 0xffffffff)) {
    SetLastError(0x57);
  }
  else if (param_2 >> 0x1c == 8) {
    local_54 = 0;
    if (DAT_c0139520 != 0) {
      local_48 = 4;
      local_44 = 0x18;
      local_40 = auStack_38;
      local_28 = param_2;
      local_24 = param_3;
      iVar1 = CeFsIoControlW(&DAT_c0139524,0x90098,&local_48,0xc,local_50,4,0,0);
      local_54 = 0;
      if (iVar1 != 0) {
        local_54 = local_50[0];
      }
    }
  }
  else {
    if (((param_1 == (int *)0x0) ||
        (((param_1[3] == 0 && param_1[2] == 0) && param_1[1] == 0) && *param_1 == 0)) &&
       (param_2 >> 0x1c == 0)) {
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c013a740;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      iVar1 = FUN_c0101de8(-0x3fec6e20,param_2);
      if (iVar1 == 0) {
        SetLastError(0x3ee);
      }
      else {
        *(uint *)(iVar1 + -8) = (param_3 << 0x1c | *(uint *)(iVar1 + -8)) & 0xbfffffff;
      }
      local_54 = (uint)(iVar1 != 0);
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
      iVar1 = IsProcessDying();
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)PTR_DAT_c0136c70;
        if (((param_1 != (int *)0x0) &&
            (((param_1[3] != 0 || param_1[2] != 0) || param_1[1] != 0) || *param_1 != 0)) &&
           (puVar2 = FUN_c0124094(param_1,2), puVar2 == (undefined4 *)0x0)) {
          SetLastError(0x57);
          puVar2 = (undefined4 *)0x0;
        }
        if (puVar2 == (undefined4 *)0x0) {
          SetLastError(0x57);
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
          iVar1 = FUN_c0101de8((int)puVar2,param_2);
          if (iVar1 == 0) {
            SetLastError(0x3ee);
          }
          else {
            *(uint *)(iVar1 + -8) = (param_3 << 0x1c | *(uint *)(iVar1 + -8)) & 0xbfffffff;
          }
          local_54 = (uint)(iVar1 != 0);
          LeaveCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
        }
      }
      else {
        SetLastError(0x10dc);
      }
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c0139480;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return local_54;
}



/* c0105f58 FUN_c0105f58 */

/* Boundary evidence: original MIPS .pdata c0105f58..c0105f63. Semantic name remains unreviewed. */

undefined4 FUN_c0105f58(void)

{
  return 1;
}



/* c0105f64 FUN_c0105f64 */

/* Boundary evidence: original MIPS .pdata c0105f64..c0105f6f. Semantic name remains unreviewed. */

undefined4 FUN_c0105f64(void)

{
  return 1;
}



/* c0105f70 FUN_c0105f70 */

/* Boundary evidence: original MIPS .pdata c0105f70..c0105f7b. Semantic name remains unreviewed. */

undefined4 FUN_c0105f70(void)

{
  return 1;
}



/* c0105f7c FUN_c0105f7c */

/* Boundary evidence: original MIPS .pdata c0105f7c..c0105f87. Semantic name remains unreviewed. */

undefined4 FUN_c0105f7c(void)

{
  return 1;
}



/* c0105f88 FUN_c0105f88 */

/* Boundary evidence: original MIPS .pdata c0105f88..c0105f93. Semantic name remains unreviewed. */

undefined4 FUN_c0105f88(void)

{
  return 1;
}



/* c0105f94 FUN_c0105f94 */

/* Boundary evidence: original MIPS .pdata c0105f94..c0105f9f. Semantic name remains unreviewed. */

undefined4 FUN_c0105f94(void)

{
  return 1;
}



/* c0105fa0 FUN_c0105fa0 */

/* Boundary evidence: original MIPS .pdata c0105fa0..c0106327. Semantic name remains unreviewed. */

uint FUN_c0105fa0(int *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  uint local_2c;
  
  local_2c = 0;
  if (((param_3 == (uint *)0x0) || (param_2 == 0)) || (param_2 == 0xffffffff)) {
    SetLastError(0x57);
  }
  else if (param_2 >> 0x1c == 8) {
    local_2c = FUN_c0105104(param_1,param_2,param_3);
  }
  else {
    if (((param_1 == (int *)0x0) ||
        (((param_1[3] == 0 && param_1[2] == 0) && param_1[1] == 0) && *param_1 == 0)) &&
       (param_2 >> 0x1c == 0)) {
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c013a740;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      iVar1 = FUN_c0101de8(-0x3fec6e20,param_2);
      if (iVar1 == 0) {
        SetLastError(0x3ee);
      }
      else {
        *param_3 = *(uint *)(iVar1 + -8) >> 0x1f;
      }
      local_2c = (uint)(iVar1 != 0);
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
      iVar1 = IsProcessDying();
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)PTR_DAT_c0136c70;
        if (((param_1 != (int *)0x0) &&
            (((param_1[3] != 0 || param_1[2] != 0) || param_1[1] != 0) || *param_1 != 0)) &&
           (puVar2 = FUN_c0124094(param_1,2), puVar2 == (undefined4 *)0x0)) {
          SetLastError(0x57);
          puVar2 = (undefined4 *)0x0;
        }
        if (puVar2 == (undefined4 *)0x0) {
          SetLastError(0x57);
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
          iVar1 = FUN_c0101de8((int)puVar2,param_2);
          if (iVar1 == 0) {
            SetLastError(0x3ee);
          }
          else {
            *param_3 = *(uint *)(iVar1 + -8) >> 0x1f;
          }
          local_2c = (uint)(iVar1 != 0);
          LeaveCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
        }
      }
      else {
        SetLastError(0x10dc);
      }
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c0139480;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return local_2c;
}



/* c0106328 FUN_c0106328 */

/* Boundary evidence: original MIPS .pdata c0106328..c0106333. Semantic name remains unreviewed. */

undefined4 FUN_c0106328(void)

{
  return 1;
}



/* c0106334 FUN_c0106334 */

/* Boundary evidence: original MIPS .pdata c0106334..c010633f. Semantic name remains unreviewed. */

undefined4 FUN_c0106334(void)

{
  return 1;
}



/* c0106340 FUN_c0106340 */

/* Boundary evidence: original MIPS .pdata c0106340..c010634b. Semantic name remains unreviewed. */

undefined4 FUN_c0106340(void)

{
  return 1;
}



/* c010634c FUN_c010634c */

/* Boundary evidence: original MIPS .pdata c010634c..c0106357. Semantic name remains unreviewed. */

undefined4 FUN_c010634c(void)

{
  return 1;
}



/* c0106358 FUN_c0106358 */

/* Boundary evidence: original MIPS .pdata c0106358..c0106363. Semantic name remains unreviewed. */

undefined4 FUN_c0106358(void)

{
  return 1;
}



/* c0106364 FUN_c0106364 */

/* Boundary evidence: original MIPS .pdata c0106364..c010636f. Semantic name remains unreviewed. */

undefined4 FUN_c0106364(void)

{
  return 1;
}



/* c0106370 FUN_c0106370 */

/* Boundary evidence: original MIPS .pdata c0106370..c01067ab. Semantic name remains unreviewed. */

undefined4 FUN_c0106370(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 local_54;
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined1 auStack_38 [16];
  uint local_28;
  uint local_24;
  
  local_54 = 0;
  if ((param_2 == 0) || (param_2 == 0xffffffff)) {
    SetLastError(0x57);
  }
  else if (param_2 >> 0x1c == 8) {
    local_54 = 0;
    if (DAT_c0139520 != 0) {
      local_48 = 6;
      local_44 = 0x18;
      local_40 = auStack_38;
      local_28 = param_2;
      local_24 = param_3;
      iVar1 = CeFsIoControlW(&DAT_c0139524,0x90098,&local_48,0xc,local_50,4,0,0);
      local_54 = 0;
      if (iVar1 != 0) {
        local_54 = local_50[0];
      }
    }
  }
  else {
    if (((param_1 == (int *)0x0) ||
        (((param_1[3] == 0 && param_1[2] == 0) && param_1[1] == 0) && *param_1 == 0)) &&
       (param_2 >> 0x1c == 0)) {
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c013a740;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      local_54 = 0;
      iVar1 = FUN_c0101de8(-0x3fec6e20,param_2);
      if (iVar1 == 0) {
        SetLastError(0x3ee);
      }
      else {
        if ((param_3 & 1) == 0) {
          uVar3 = *(uint *)(iVar1 + -8) & 0x7fffffff;
        }
        else {
          uVar3 = *(uint *)(iVar1 + -8) | 0x80000000;
        }
        *(uint *)(iVar1 + -8) = uVar3;
        local_54 = 1;
      }
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
      iVar1 = IsProcessDying();
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)PTR_DAT_c0136c70;
        if (((param_1 != (int *)0x0) &&
            (((param_1[3] != 0 || param_1[2] != 0) || param_1[1] != 0) || *param_1 != 0)) &&
           (puVar2 = FUN_c0124094(param_1,2), puVar2 == (undefined4 *)0x0)) {
          SetLastError(0x57);
          puVar2 = (undefined4 *)0x0;
        }
        if (puVar2 == (undefined4 *)0x0) {
          SetLastError(0x57);
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
          local_54 = 0;
          iVar1 = FUN_c0101de8((int)puVar2,param_2);
          if (iVar1 == 0) {
            SetLastError(0x3ee);
          }
          else {
            if ((param_3 & 1) == 0) {
              uVar3 = *(uint *)(iVar1 + -8) & 0x7fffffff;
            }
            else {
              uVar3 = *(uint *)(iVar1 + -8) | 0x80000000;
            }
            *(uint *)(iVar1 + -8) = uVar3;
            local_54 = 1;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
        }
      }
      else {
        SetLastError(0x10dc);
      }
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c0139480;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return local_54;
}



/* c01067ac FUN_c01067ac */

/* Boundary evidence: original MIPS .pdata c01067ac..c01067b7. Semantic name remains unreviewed. */

undefined4 FUN_c01067ac(void)

{
  return 1;
}



/* c01067b8 FUN_c01067b8 */

/* Boundary evidence: original MIPS .pdata c01067b8..c01067c3. Semantic name remains unreviewed. */

undefined4 FUN_c01067b8(void)

{
  return 1;
}



/* c01067c4 FUN_c01067c4 */

/* Boundary evidence: original MIPS .pdata c01067c4..c01067cf. Semantic name remains unreviewed. */

undefined4 FUN_c01067c4(void)

{
  return 1;
}



/* c01067d0 FUN_c01067d0 */

/* Boundary evidence: original MIPS .pdata c01067d0..c01067db. Semantic name remains unreviewed. */

undefined4 FUN_c01067d0(void)

{
  return 1;
}



/* c01067dc FUN_c01067dc */

/* Boundary evidence: original MIPS .pdata c01067dc..c01067e7. Semantic name remains unreviewed. */

undefined4 FUN_c01067dc(void)

{
  return 1;
}



/* c01067e8 FUN_c01067e8 */

/* Boundary evidence: original MIPS .pdata c01067e8..c01067f3. Semantic name remains unreviewed. */

undefined4 FUN_c01067e8(void)

{
  return 1;
}



/* c01067f4 FUN_c01067f4 */

/* Boundary evidence: original MIPS .pdata c01067f4..c01068b3. Semantic name remains unreviewed. */

int FUN_c01067f4(undefined4 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_260;
  undefined4 local_25c;
  undefined1 *local_258;
  undefined1 auStack_250 [16];
  undefined4 local_240;
  undefined1 auStack_238 [544];
  int local_18;
  
  if (DAT_c0139520 == 0) {
    iVar2 = 0;
  }
  else {
    local_258 = auStack_250;
    local_260 = 1;
    local_25c = 0x14;
    local_240 = param_2;
    iVar1 = CeFsIoControlW(&DAT_c0139524,0x90098,&local_260,0xc,auStack_238,0x224,0,0);
    iVar2 = 0;
    if ((iVar1 != 0) && (iVar2 = local_18, local_18 != 0)) {
      memcpy(param_3,auStack_238,0x220);
    }
  }
  return iVar2;
}



/* c01068b4 FUN_c01068b4 */

/* Boundary evidence: original MIPS .pdata c01068b4..c01068f3. Semantic name remains unreviewed. */

undefined4 FUN_c01068b4(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136cd4 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_c0136cd4)();
  }
  return uVar1;
}



/* c01068f4 FUN_c01068f4 */

/* Boundary evidence: original MIPS .pdata c01068f4..c010692b. Semantic name remains unreviewed. */

undefined4 FUN_c01068f4(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136cd0 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_c0136cd0)();
  }
  return uVar1;
}



/* c010692c FUN_c010692c */

/* Boundary evidence: original MIPS .pdata c010692c..c0106963. Semantic name remains unreviewed. */

undefined4 FUN_c010692c(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136cdc == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_c0136cdc)();
  }
  return uVar1;
}



/* c0106964 FUN_c0106964 */

/* Boundary evidence: original MIPS .pdata c0106964..c010699b. Semantic name remains unreviewed. */

undefined4 FUN_c0106964(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136cd8 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_c0136cd8)();
  }
  return uVar1;
}



/* c01069bc FUN_c01069bc */

/* Boundary evidence: original MIPS .pdata c01069bc..c0106a7b. Semantic name remains unreviewed. */

LPVOID FUN_c01069bc(SIZE_T param_1)

{
  LPVOID pvVar1;
  
  if ((DAT_c0136cf4 == (HANDLE)0x0) &&
     (DAT_c0136cf4 = HeapCreate(0,0x1000,0x40000), DAT_c0136cf4 == (HANDLE)0x0)) {
    return (LPVOID)0x0;
  }
  pvVar1 = HeapAlloc(DAT_c0136cf4,8,param_1);
  if (pvVar1 != (LPVOID)0x0) {
    if ((DAT_c013683c == (LPVOID)0xffffffff) || (pvVar1 < DAT_c013683c)) {
      DAT_c013683c = pvVar1;
    }
    if ((DAT_c0136840 == (LPVOID)0xffffffff) || (DAT_c0136840 < pvVar1)) {
      DAT_c0136840 = pvVar1;
    }
  }
  return pvVar1;
}



/* c0106a7c FUN_c0106a7c */

undefined4 FUN_c0106a7c(uint param_1)

{
  undefined4 uVar1;
  
  if ((((DAT_c0136cf4 == 0) || (DAT_c013683c == 0xffffffff)) || (DAT_c0136840 == 0xffffffff)) ||
     ((param_1 < DAT_c013683c || (uVar1 = 1, DAT_c0136840 < param_1)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0106ad8 FUN_c0106ad8 */

undefined4 FUN_c0106ad8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*(byte *)(param_1 + 0xe) & 8) == 8) &&
     (*(int *)(((uint)*(byte *)(param_1 + 0xd) + (uint)*(byte *)(param_1 + 0xc) + 8) * 2 + param_1)
      != DAT_c0136ce4)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c0106b28 FUN_c0106b28 */

/* Boundary evidence: original MIPS .pdata c0106b28..c0106be7. Semantic name remains unreviewed. */

LPVOID FUN_c0106b28(void)

{
  LPVOID pvVar1;
  
  if ((DAT_c0136cf8 == (HANDLE)0x0) &&
     (DAT_c0136cf8 = HeapCreate(0,0x1000,0x100000), DAT_c0136cf8 == (HANDLE)0x0)) {
    return (LPVOID)0x0;
  }
  pvVar1 = HeapAlloc(DAT_c0136cf8,8,0x58);
  if (pvVar1 != (LPVOID)0x0) {
    DAT_c0136cfc = DAT_c0136cfc + 1;
    if ((DAT_c0136844 == (LPVOID)0xffffffff) || (pvVar1 < DAT_c0136844)) {
      DAT_c0136844 = pvVar1;
    }
    if ((DAT_c0136848 == (LPVOID)0xffffffff) || (DAT_c0136848 < pvVar1)) {
      DAT_c0136848 = pvVar1;
    }
  }
  return pvVar1;
}



/* c0106be8 FUN_c0106be8 */

undefined4 FUN_c0106be8(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((0x7fffffff < param_1) && (param_1 < 0x80000004)) ||
     (((DAT_c0136cf8 != 0 &&
       (((DAT_c0136848 != 0xffffffff && (DAT_c0136844 != 0xffffffff)) && (DAT_c0136844 <= param_1)))
       ) && (param_1 <= DAT_c0136848)))) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c0106c68 FUN_c0106c68 */

/* Boundary evidence: original MIPS .pdata c0106c68..c0106d0f. Semantic name remains unreviewed. */

void FUN_c0106c68(undefined4 *param_1)

{
  DAT_c0136ce8 = DAT_c0136ce8 + 1;
  if (param_1 != &DAT_c01391e0) {
    param_1[0x95] = param_1[0x95] + 1;
  }
  if ((DAT_c0136cec != 0) && (DAT_c0136cf0 != 0)) {
    SetEventData(DAT_c0136cf0,DAT_c0136ce8);
    if (DAT_c0136834 == 0) {
      trap(0x1c00);
    }
    if (DAT_c0136ce8 % DAT_c0136834 == 0) {
      EventModify(DAT_c0136cf0,3);
    }
  }
  return;
}



/* c0106d10 FUN_c0106d10 */

/* Boundary evidence: original MIPS .pdata c0106d10..c0106dff. Semantic name remains unreviewed. */

void FUN_c0106d10(void)

{
  int iVar1;
  SIZE_T local_18;
  undefined1 auStack_14 [4];
  
  if ((((DAT_c0136ce0 == (HLOCAL)0x0) &&
       (iVar1 = KernelIoControl(0x101008c,0,0,&local_18,4,auStack_14), iVar1 != 0)) &&
      (local_18 != 0)) &&
     ((DAT_c0136ce0 = LocalAlloc(0,local_18), DAT_c0136ce0 != (HLOCAL)0x0 &&
      (iVar1 = KernelIoControl(0x101008c,0,0,DAT_c0136ce0,local_18,auStack_14), iVar1 == 0)))) {
    LocalFree(DAT_c0136ce0);
    DAT_c0136ce0 = (HLOCAL)0x0;
  }
  return;
}



/* c0106e00 FUN_c0106e00 */

/* Boundary evidence: original MIPS .pdata c0106e00..c0106e0b. Semantic name remains unreviewed. */

undefined4 FUN_c0106e00(void)

{
  return 1;
}



/* c0106e0c FUN_c0106e0c */

/* Boundary evidence: original MIPS .pdata c0106e0c..c0106f3f. Semantic name remains unreviewed. */

undefined4 FUN_c0106e0c(wchar_t *param_1,size_t param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  ushort *puVar4;
  uint uVar5;
  
  uVar5 = 0;
  do {
    if (((((uint)*(ushort *)((int)&DAT_c00f2948 + uVar5) & param_3 >> 0x10) != 0) &&
        (param_2 == *(ushort *)((int)&DAT_c00f294a + uVar5))) &&
       (iVar1 = _wcsnicmp(param_1,*(wchar_t **)((int)&PTR_u_comm_c00f294c + uVar5),param_2),
       iVar1 == 0)) {
      return 1;
    }
    uVar5 = uVar5 + 8;
  } while (uVar5 < 0x38);
  if ((DAT_c0136ce0 != (uint *)0x0) && (uVar5 = 0, *DAT_c0136ce0 != 0)) {
    iVar1 = 0;
    puVar3 = DAT_c0136ce0;
    do {
      puVar4 = (ushort *)(puVar3[1] + iVar1);
      if (((((uint)*puVar4 & param_3 >> 0x10) != 0) && (param_2 == puVar4[1])) &&
         (iVar2 = _wcsnicmp(param_1,*(wchar_t **)(puVar4 + 2),param_2), puVar3 = DAT_c0136ce0,
         iVar2 == 0)) {
        return 1;
      }
      uVar5 = uVar5 + 1;
      iVar1 = iVar1 + 8;
    } while (uVar5 < *puVar3);
  }
  return 0;
}



/* c0106f40 FUN_c0106f40 */

/* Boundary evidence: original MIPS .pdata c0106f40..c01070c7. Semantic name remains unreviewed. */

undefined4
FUN_c0106f40(undefined4 *param_1,int param_2,int param_3,wchar_t *param_4,uint param_5,void *param_6
            ,uint param_7,undefined4 *param_8,uint *param_9)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if ((param_5 < 0x100) && (param_7 < 0x100)) {
    if ((*param_9 & 1) != 0) {
      if ((param_4 == (wchar_t *)0x0) ||
         (iVar1 = FUN_c0106e0c(param_4,param_5,*param_9), iVar1 == 0)) {
        *param_9 = 0;
      }
      else {
        *param_9 = 2;
      }
    }
    puVar2 = FUN_c01069bc((param_5 + param_7 + 10) * 2);
    if (puVar2 == (undefined4 *)0x0) {
      uVar3 = 0x70;
    }
    else {
      puVar2[1] = 0;
      puVar2[2] = 0;
      *(char *)(puVar2 + 3) = (char)param_5;
      *(char *)((int)puVar2 + 0xd) = (char)param_7;
      *(undefined1 *)((int)puVar2 + 0xe) = 0;
      if (param_4 != (wchar_t *)0x0) {
        memcpy(puVar2 + 4,param_4,param_5 << 1);
      }
      if (param_7 != 0) {
        memcpy((void *)((param_5 + 8) * 2 + (int)puVar2),param_6,param_7 << 1);
      }
      *(byte *)((int)puVar2 + 0xe) = *(byte *)((int)puVar2 + 0xe) | 8;
      *(undefined4 *)((param_5 + param_7 + 8) * 2 + (int)puVar2) = DAT_c0136ce4;
      *puVar2 = *param_1;
      *(undefined4 **)(param_3 * 4 + param_2) = puVar2;
      *param_1 = puVar2;
      if (param_8 != (undefined4 *)0x0) {
        *param_8 = 1;
      }
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0x57;
  }
  return uVar3;
}



/* c01070c8 FUN_c01070c8 */

/* Boundary evidence: original MIPS .pdata c01070c8..c0107217. Semantic name remains unreviewed. */

undefined4
FUN_c01070c8(undefined4 param_1,void *param_2,int param_3,int param_4,undefined4 *param_5,
            void *param_6,undefined4 param_7)

{
  LPVOID _Dst;
  
  if (param_3 == 0) {
    if (((void *)0x7fffffff < param_6) && (param_6 < (void *)0x80000004)) {
      if (param_5 == (undefined4 *)0x0) {
        return 0;
      }
      *param_5 = param_6;
      return 0;
    }
    _Dst = FUN_c0106b28();
    if (_Dst == (LPVOID)0x0) {
      return 0xe;
    }
    memcpy(_Dst,param_6,0x58);
    *(LPVOID *)_Dst = _Dst;
  }
  else {
    _Dst = FUN_c0106b28();
    if (_Dst == (LPVOID)0x0) {
      return 0xe;
    }
    *(LPVOID *)_Dst = _Dst;
    *(char *)((int)_Dst + 9) = (char)param_3;
    memcpy((void *)((int)_Dst + 0x18),param_2,param_3 << 2);
    *(undefined4 *)((int)_Dst + 4) = param_7;
    *(undefined4 *)((*(byte *)((int)_Dst + 9) + 6) * 4 + (int)_Dst) =
         *(undefined4 *)(param_3 * 4 + (int)param_2);
    *(undefined1 *)((int)_Dst + 8) = 0xf5;
    *(uint *)((int)_Dst + 0x10) = (uint)(param_4 == 2);
  }
  *(LPVOID *)((int)_Dst + 0xc) = DAT_c01391b4;
  DAT_c01391b4 = _Dst;
  *param_5 = _Dst;
  return 0;
}



/* c0107218 FUN_c0107218 */

/* Boundary evidence: original MIPS .pdata c0107218..c0107387. Semantic name remains unreviewed. */

void FUN_c0107218(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (puVar3 = *(undefined4 **)(param_2 + 8), puVar3 != (undefined4 *)0x0) {
    iVar1 = FUN_c0106a7c((uint)puVar3);
    puVar2 = puVar3;
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)FUN_c0101c94(-0x3fec6e20,(uint)puVar3);
    }
    if (puVar2 == (undefined4 *)0x0) break;
    *(undefined4 *)(param_2 + 8) = *puVar2;
    if (DAT_c0136cf4 != (HANDLE)0x0) {
      HeapFree(DAT_c0136cf4,0,puVar3);
    }
  }
  puVar3 = *(undefined4 **)(param_2 + 4);
  while( true ) {
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    iVar1 = FUN_c0106a7c((uint)puVar3);
    puVar2 = puVar3;
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)FUN_c0101c94(-0x3fec6e20,(uint)puVar3);
    }
    if (puVar2 == (undefined4 *)0x0) break;
    FUN_c0107218(param_1,(int)puVar2);
    for (iVar1 = DAT_c01391b4; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
      if (*(undefined4 **)((*(byte *)(iVar1 + 9) + 6) * 4 + iVar1) == puVar3) {
        *(undefined1 *)(iVar1 + 8) = 0xc2;
      }
    }
    *(undefined4 *)(param_2 + 4) = *puVar2;
    if (DAT_c0136cf4 != (HANDLE)0x0) {
      HeapFree(DAT_c0136cf4,0,puVar3);
    }
    puVar3 = *(undefined4 **)(param_2 + 4);
  }
  return;
}



/* c0107388 FUN_c0107388 */

/* Boundary evidence: original MIPS .pdata c0107388..c0107543. Semantic name remains unreviewed. */

void FUN_c0107388(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)(param_2 + 8);
  while (puVar4 = (undefined4 *)*puVar7, puVar4 != (undefined4 *)0x0) {
    iVar2 = FUN_c0106a7c((uint)puVar4);
    puVar1 = puVar4;
    if (iVar2 == 0) {
      puVar1 = (undefined4 *)FUN_c0101c94(-0x3fec6e20,(uint)puVar4);
    }
    if (puVar1 == (undefined4 *)0x0) break;
    FUN_c010297c(-0x3fec6e20);
    FUN_c01029e4(-0x3fec6e20,1,puVar7,*puVar7,4);
    *puVar7 = *puVar1;
    FUN_c01037f0(&DAT_c01391e0,(uint)puVar4);
    FUN_c0102aa4(&DAT_c01391e0);
  }
  puVar6 = (uint *)(param_2 + 4);
  puVar5 = (uint *)*puVar6;
  while( true ) {
    if (puVar5 == (uint *)0x0) {
      return;
    }
    iVar2 = FUN_c0106a7c((uint)puVar5);
    puVar3 = puVar5;
    if (iVar2 == 0) {
      puVar3 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar5);
    }
    if (puVar3 == (uint *)0x0) break;
    FUN_c0107388(param_1,(int)puVar3);
    for (iVar2 = DAT_c01391b4; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      if ((uint *)*(uint *)((*(byte *)(iVar2 + 9) + 6) * 4 + iVar2) == puVar5) {
        *(undefined1 *)(iVar2 + 8) = 0xc2;
      }
    }
    FUN_c010297c(-0x3fec6e20);
    FUN_c01029e4(-0x3fec6e20,1,puVar6,*puVar6,4);
    *puVar6 = *puVar3;
    FUN_c01037f0(&DAT_c01391e0,(uint)puVar5);
    FUN_c0102aa4(&DAT_c01391e0);
    puVar5 = (uint *)*puVar6;
  }
  return;
}



/* c0107544 FUN_c0107544 */

/* Boundary evidence: original MIPS .pdata c0107544..c01076eb. Semantic name remains unreviewed. */

undefined4 FUN_c0107544(undefined4 param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  for (iVar3 = DAT_c01391b4; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
    if (*(int **)((*(byte *)(iVar3 + 9) + 6) * 4 + iVar3) == param_3) {
      return 5;
    }
  }
  iVar3 = FUN_c0106a7c((uint)param_3);
  piVar1 = param_3;
  if (iVar3 == 0) {
    piVar1 = (int *)FUN_c0101c94(-0x3fec6e20,(uint)param_3);
  }
  if (piVar1 != (int *)0x0) {
    iVar3 = FUN_c0106ad8((int)piVar1);
    if (iVar3 == 0) {
      FUN_c0107218(param_1,(int)piVar1);
    }
    else {
      piVar1[1] = 0;
      piVar1[2] = 0;
    }
    piVar4 = (int *)*param_2;
    if (piVar4 == param_3) {
      *param_2 = *piVar1;
LAB_c01076a4:
      if (DAT_c0136cf4 != (HANDLE)0x0) {
        HeapFree(DAT_c0136cf4,0,param_3);
      }
      return 0;
    }
    iVar3 = FUN_c0106a7c((uint)piVar4);
    if (iVar3 == 0) {
      piVar4 = (int *)FUN_c0101c94(-0x3fec6e20,(uint)piVar4);
    }
    if (piVar4 != (int *)0x0) {
      do {
        piVar2 = (int *)*piVar4;
        if ((piVar2 == (int *)0x0) || (piVar2 == param_3)) break;
        iVar3 = FUN_c0106a7c((uint)piVar2);
        if (iVar3 == 0) {
          piVar2 = (int *)FUN_c0101c94(-0x3fec6e20,(uint)piVar2);
        }
        piVar4 = piVar2;
      } while (piVar2 != (int *)0x0);
      if ((piVar4 != (int *)0x0) && (*piVar4 != 0)) {
        *piVar4 = *piVar1;
        goto LAB_c01076a4;
      }
    }
  }
  return 0x57;
}



/* c01076ec FUN_c01076ec */

/* Boundary evidence: original MIPS .pdata c01076ec..c010796f. Semantic name remains unreviewed. */

undefined4 FUN_c01076ec(undefined4 param_1,int *param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  
  for (iVar4 = DAT_c01391b4; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {
    if (*(int **)((*(byte *)(iVar4 + 9) + 6) * 4 + iVar4) == param_3) {
      return 5;
    }
  }
  iVar4 = FUN_c0106a7c((uint)param_3);
  piVar1 = param_3;
  if (iVar4 == 0) {
    piVar1 = (int *)FUN_c0101c94(-0x3fec6e20,(uint)param_3);
  }
  if (piVar1 == (int *)0x0) {
LAB_c0107944:
    uVar2 = 0x57;
  }
  else {
    pbVar5 = (byte *)((int)piVar1 + 0xe);
    if ((*pbVar5 & 8) == 8) {
      iVar4 = FUN_c0106ad8((int)piVar1);
      if (iVar4 == 0) {
        FUN_c0107218(param_1,(int)piVar1);
      }
    }
    else {
      FUN_c0107388(param_1,(int)piVar1);
    }
    iVar4 = FUN_c0106a7c((uint)param_3);
    if (iVar4 != 0) {
      uVar2 = FUN_c0107544(param_1,param_2,param_3);
      return uVar2;
    }
    FUN_c010297c(-0x3fec6e20);
    if ((*pbVar5 & 2) == 2) {
      FUN_c01029e4(-0x3fec6e20,1,pbVar5,(uint)*pbVar5,1);
    }
    else {
      piVar6 = (int *)*param_2;
      if (piVar6 != param_3) {
        iVar4 = FUN_c0106a7c((uint)piVar6);
        if (iVar4 == 0) {
          piVar6 = (int *)FUN_c0101c94(-0x3fec6e20,(uint)piVar6);
        }
        if (piVar6 != (int *)0x0) {
          do {
            piVar3 = (int *)*piVar6;
            if ((piVar3 == (int *)0x0) || (piVar3 == param_3)) break;
            iVar4 = FUN_c0106a7c((uint)piVar3);
            if (iVar4 == 0) {
              piVar3 = (int *)FUN_c0101c94(-0x3fec6e20,(uint)piVar3);
            }
            piVar6 = piVar3;
          } while (piVar3 != (int *)0x0);
          if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
            FUN_c01029e4(-0x3fec6e20,1,piVar6,*piVar6,4);
            *piVar6 = *piVar1;
            goto LAB_c0107914;
          }
        }
        FUN_c01036ac(&DAT_c01391e0);
        goto LAB_c0107944;
      }
      FUN_c01029e4(-0x3fec6e20,1,param_2,piVar6,4);
      *param_2 = *piVar1;
LAB_c0107914:
      FUN_c01037f0(&DAT_c01391e0,(uint)param_3);
    }
    FUN_c0102aa4(&DAT_c01391e0);
    FUN_c0106c68(&DAT_c01391e0);
    uVar2 = 0;
  }
  return uVar2;
}



/* c0107970 FUN_c0107970 */

/* Boundary evidence: original MIPS .pdata c0107970..c0107b03. Semantic name remains unreviewed. */

undefined4
FUN_c0107970(undefined4 param_1,uint *param_2,wchar_t *param_3,undefined2 param_4,void *param_5,
            uint param_6,undefined4 param_7,byte param_8)

{
  size_t sVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  
  sVar1 = wcslen(param_3);
  if ((sVar1 < 0x100) && (param_6 < 0x1001)) {
    if ((param_8 & 8) == 0) {
      puVar3 = FUN_c0103dc8(&DAT_c01391e0,0xd,(sVar1 + 6) * 2 + param_6,0,0);
      puVar2 = puVar3 + 3;
      if (puVar3 == (uint *)0x0) {
        puVar2 = (uint *)0x0;
      }
    }
    else {
      puVar2 = FUN_c01069bc((sVar1 + 6) * 2 + param_6);
    }
    if (puVar2 == (uint *)0x0) {
      uVar4 = 0x70;
    }
    else {
      *(undefined2 *)(puVar2 + 1) = param_4;
      *(char *)(puVar2 + 2) = (char)sVar1;
      *(short *)((int)puVar2 + 6) = (short)param_6;
      *(undefined1 *)((int)puVar2 + 9) = 0;
      memcpy((void *)((int)puVar2 + 10),param_3,sVar1 << 1);
      memcpy((void *)((sVar1 + 5) * 2 + (int)puVar2),param_5,param_6);
      *(byte *)((int)puVar2 + 9) = param_8 & 0xf9 | *(byte *)((int)puVar2 + 9);
      *puVar2 = *param_2;
      if ((param_8 & 8) == 0) {
        FUN_c01029e4(-0x3fec6e20,1,param_2,*param_2,4);
        *param_2 = puVar2[-1];
        FUN_c0106c68(&DAT_c01391e0);
      }
      else {
        *param_2 = (uint)puVar2;
      }
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0x57;
  }
  return uVar4;
}



/* c0107b04 FUN_c0107b04 */

/* Boundary evidence: original MIPS .pdata c0107b04..c0107cb7. Semantic name remains unreviewed. */

undefined4
FUN_c0107b04(undefined4 param_1,uint *param_2,wchar_t *param_3,undefined4 param_4,uint *param_5)

{
  uint *puVar1;
  size_t _MaxCount;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  _MaxCount = wcslen(param_3);
  puVar3 = (uint *)*param_2;
  puVar4 = (uint *)0x0;
  while( true ) {
    puVar1 = puVar3;
    if (puVar1 == (uint *)0x0) {
      return 2;
    }
    iVar2 = FUN_c0106a7c((uint)puVar1);
    puVar3 = puVar1;
    if (iVar2 == 0) {
      puVar3 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar1);
    }
    if (puVar3 == (uint *)0x0) break;
    if ((_MaxCount == (byte)puVar3[2]) &&
       (iVar2 = _wcsnicmp((wchar_t *)((int)puVar3 + 10),param_3,_MaxCount), iVar2 == 0)) {
      if (puVar1 == (uint *)0x0) {
        return 2;
      }
      *param_5 = (uint)puVar1;
      if (puVar4 == (uint *)0x0) {
        if ((*(byte *)((int)puVar3 + 9) & 8) != 8) {
          FUN_c01029e4(-0x3fec6e20,1,param_2,*param_2,4);
        }
        *param_2 = *puVar3;
      }
      else {
        iVar2 = FUN_c0106a7c((uint)puVar4);
        if (iVar2 == 0) {
          puVar4 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar4);
        }
        if (puVar4 == (uint *)0x0) {
          return 0x57;
        }
        if ((*(byte *)((int)puVar3 + 9) & 8) != 8) {
          FUN_c01029e4(-0x3fec6e20,1,puVar4,*puVar4,4);
        }
        *puVar4 = *puVar3;
      }
      if ((*(byte *)((int)puVar3 + 9) & 8) != 8) {
        FUN_c0106c68(&DAT_c01391e0);
      }
      return 0;
    }
    puVar3 = (uint *)*puVar3;
    puVar4 = puVar1;
  }
  return 2;
}



/* c0107cb8 FUN_c0107cb8 */

/* Boundary evidence: original MIPS .pdata c0107cb8..c01081a3. Semantic name remains unreviewed. */

int FUN_c0107cb8(undefined4 param_1,uint *param_2,wchar_t *param_3,uint param_4,wchar_t *param_5,
                uint param_6,undefined4 param_7,byte param_8)

{
  size_t _MaxCount;
  int iVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *_Dst;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  wchar_t *pwVar8;
  int iVar9;
  LPVOID local_2c;
  
  pwVar8 = (wchar_t *)0x0;
  local_2c = (LPVOID)0x0;
  _MaxCount = wcslen(param_3);
  iVar9 = 1;
  puVar7 = (uint *)*param_2;
  pwVar3 = param_5;
  if (*param_2 == 0) {
LAB_c0107e2c:
    if ((param_4 == 1) || (param_4 == 2)) goto LAB_c0107e40;
LAB_c0107f28:
    _Dst = param_5;
    if ((param_4 == 7) && (param_5 != (wchar_t *)0x0)) {
      uVar6 = 4;
      if (param_6 < 4) {
        iVar9 = 4 - param_6;
LAB_c0107f74:
        uVar4 = iVar9 + param_6;
        if ((param_6 <= uVar4) && (uVar4 < 0x1001)) {
          _Dst = LocalAlloc(0x40,uVar4);
          pwVar2 = param_5;
          pwVar8 = _Dst;
          if (_Dst == (wchar_t *)0x0) goto LAB_c0107f0c;
          memcpy(_Dst,param_5,param_6);
          pwVar3 = _Dst;
          goto LAB_c0107fc4;
        }
      }
      else {
        uVar4 = param_6;
        if ((param_6 & 1) != 0) goto LAB_c0107f74;
LAB_c0107fc4:
        if (_Dst[(uVar4 >> 1) - 1] == L'\0') {
          param_6 = uVar4;
          if (_Dst[(uVar4 >> 1) - 2] == L'\0') goto LAB_c0108040;
          uVar6 = 2;
        }
        param_6 = uVar6 + uVar4;
        if ((uVar6 <= param_6) && (param_6 < 0x1001)) {
          pwVar3 = LocalAlloc(0x40,param_6);
          pwVar2 = _Dst;
          if (pwVar3 == (wchar_t *)0x0) goto LAB_c0107f0c;
          memcpy(pwVar3,_Dst,uVar4);
          goto LAB_c0108040;
        }
      }
LAB_c0107f60:
      iVar9 = 0x57;
      pwVar2 = pwVar8;
    }
    else {
LAB_c0108040:
      if ((param_8 & 8) == 0) {
        FUN_c010297c(-0x3fec6e20);
      }
      iVar9 = FUN_c0107b04(param_1,param_2,param_3,param_7,(uint *)&local_2c);
      pwVar2 = pwVar8;
      if (((iVar9 == 0) || (iVar9 == 2)) &&
         (iVar9 = FUN_c0107970(param_1,param_2,param_3,(short)param_4,pwVar3,param_6,param_7,param_8
                              ), iVar9 != 0)) {
        if ((param_8 & 8) == 0) {
          FUN_c01036ac(&DAT_c01391e0);
        }
      }
      else {
        if (local_2c != (LPVOID)0x0) {
          if ((param_8 & 8) == 0) {
            FUN_c01037f0(&DAT_c01391e0,(uint)local_2c);
          }
          else if (DAT_c0136cf4 != (HANDLE)0x0) {
            HeapFree(DAT_c0136cf4,0,local_2c);
          }
        }
        if ((param_8 & 8) == 0) {
          FUN_c0102aa4(&DAT_c01391e0);
        }
      }
    }
  }
  else {
    do {
      puVar5 = puVar7;
      iVar1 = FUN_c0106a7c((uint)puVar5);
      if (iVar1 == 0) {
        puVar5 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar5);
      }
      if (puVar5 == (uint *)0x0) goto LAB_c0107e2c;
      if ((_MaxCount == (byte)puVar5[2]) &&
         (iVar1 = _wcsnicmp((wchar_t *)((int)puVar5 + 10),param_3,_MaxCount), iVar1 == 0)) break;
      puVar7 = (uint *)*puVar5;
      puVar5 = (uint *)0x0;
    } while (puVar7 != (uint *)0x0);
    if (((puVar5 == (uint *)0x0) || ((param_6 & 0xffff) != (uint)*(ushort *)((int)puVar5 + 6))) ||
       ((param_4 & 0xffff) != (uint)(ushort)puVar5[1])) goto LAB_c0107e2c;
    if (param_4 != 1) {
      iVar1 = memcmp(param_5,(void *)(((byte)puVar5[2] + 5) * 2 + (int)puVar5),param_6);
      if (iVar1 == 0) {
        return 0x7de;
      }
      goto LAB_c0107e2c;
    }
    iVar1 = wcsncmp(param_5,(wchar_t *)(((byte)puVar5[2] + 5) * 2 + (int)puVar5),param_6 >> 1);
    if (iVar1 == 0) {
      return 0x7de;
    }
LAB_c0107e40:
    if (param_5 == (wchar_t *)0x0) goto LAB_c0107f28;
    if (((param_6 & 1) != 0) || (uVar6 = param_6, pwVar2 = param_5, param_6 == 0)) {
      uVar4 = 1;
      if (param_6 == 0) {
        uVar4 = 2;
      }
      uVar6 = uVar4 + param_6;
      if ((uVar6 < uVar4) || (0x1000 < uVar6)) {
        return 0x57;
      }
      pwVar2 = LocalAlloc(0x40,uVar6);
      if (pwVar2 == (wchar_t *)0x0) {
        iVar9 = 0xe;
        goto LAB_c010814c;
      }
      memcpy(pwVar2,param_5,param_6);
      pwVar8 = pwVar2;
    }
    param_6 = uVar6;
    param_5 = pwVar2;
    pwVar3 = pwVar2;
    if (*(short *)((int)pwVar2 + ((uVar6 & 0xfffffffe) - 2)) == 0) goto LAB_c0107f28;
    param_6 = uVar6 + 2;
    _Dst = pwVar2;
    if ((param_6 < 2) || (0x1000 < param_6)) goto LAB_c0107f60;
    pwVar3 = LocalAlloc(0x40,param_6);
    if (pwVar3 != (wchar_t *)0x0) {
      memcpy(pwVar3,pwVar2,uVar6);
      goto LAB_c0107f28;
    }
LAB_c0107f0c:
    iVar9 = 0xe;
    _Dst = pwVar2;
    pwVar2 = pwVar8;
  }
  if (pwVar3 != _Dst) {
    LocalFree(pwVar3);
  }
LAB_c010814c:
  if (pwVar2 != (wchar_t *)0x0) {
    LocalFree(pwVar2);
  }
  return iVar9;
}



/* c01081a4 FUN_c01081a4 */

/* Boundary evidence: original MIPS .pdata c01081a4..c010834b. Semantic name remains unreviewed. */

void FUN_c01081a4(undefined4 param_1,uint *param_2,int param_3,wchar_t *param_4,undefined4 *param_5)

{
  uint *puVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  
  if (param_3 == 0) {
    wcscpy((wchar_t *)&DAT_c0137180,L"\\");
  }
  else {
    wcscpy((wchar_t *)&DAT_c0137180,L"");
    iVar5 = param_3;
    puVar1 = param_2;
    if (0 < param_3) {
      do {
        wcscat((wchar_t *)&DAT_c0137180,L"\\");
        uVar4 = puVar1[1];
        iVar2 = FUN_c0106a7c(uVar4);
        if (iVar2 == 0) {
          uVar4 = FUN_c0101c94(-0x3fec6e20,uVar4);
        }
        if (uVar4 != 0) {
          sVar3 = wcslen((wchar_t *)&DAT_c0137180);
          memcpy(&DAT_c0137180 + sVar3 * 2,(void *)(uVar4 + 0x10),(uint)*(byte *)(uVar4 + 0xc) << 1)
          ;
          *(undefined2 *)(&DAT_c0137180 + (*(byte *)(uVar4 + 0xc) + sVar3) * 2) = 0;
        }
        iVar5 = iVar5 + -1;
        puVar1 = puVar1 + 1;
      } while (iVar5 != 0);
    }
  }
  if (param_4 != (wchar_t *)0x0) {
    if (param_3 != 0) {
      wcscat((wchar_t *)&DAT_c0137180,L"\\");
    }
    wcscat((wchar_t *)&DAT_c0137180,param_4);
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = (&DAT_c01391c0)[3 - *param_2 & 0xff];
  }
  return;
}



/* c010834c FUN_c010834c */

/* Boundary evidence: original MIPS .pdata c010834c..c01084bb. Semantic name remains unreviewed. */

undefined4 FUN_c010834c(uint *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint auStack_58 [16];
  
  uVar2 = 0;
  if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
    if ((param_1 != (uint *)0x0) &&
       (((param_1 >= (uint *)0x80000000 && (param_1 < (uint *)0x80000004)) ||
        (((uint *)*param_1 == param_1 && ((char)param_1[2] == -0xb)))))) {
      uVar3 = param_1[*(byte *)((int)param_1 + 9) + 6];
      iVar1 = FUN_c0106a7c(uVar3);
      if (iVar1 == 0) {
        uVar3 = FUN_c0101c94(-0x3fec6e20,uVar3);
      }
      if (uVar3 != 0) {
        uVar3 = (uint)*(byte *)((int)param_1 + 9);
        if (0xe < uVar3) {
          uVar3 = 0xf;
        }
        memcpy(auStack_58,param_1 + 6,(uVar3 + 1) * 4);
        uVar2 = 1;
        FUN_c01081a4(1,auStack_58,uVar3,(wchar_t *)0x0,param_2);
      }
    }
  }
  else {
    wcscpy((wchar_t *)&DAT_c0137180,L"\\");
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = (&DAT_c01391cc)[-(int)param_1];
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* c01084bc FUN_c01084bc */

/* Boundary evidence: original MIPS .pdata c01084bc..c0108547. Semantic name remains unreviewed. */

void FUN_c01084bc(int param_1,wchar_t *param_2,int param_3)

{
  HRESULT HVar1;
  
  if ((1 < DAT_c0136ca8) &&
     (HVar1 = StringCbCatW((STRSAFE_LPWSTR)&DAT_c0137180,0x2020,L"\\"), -1 < HVar1)) {
    FUN_c013221c(param_1,(wchar_t *)&DAT_c0137180,param_2,0,param_3);
  }
  return;
}



/* c0108548 FUN_c0108548 */

/* Boundary evidence: original MIPS .pdata c0108548..c0108963. Semantic name remains unreviewed. */

undefined4
FUN_c0108548(uint *param_1,int param_2,void *param_3,uint param_4,uint *param_5,undefined4 param_6,
            void *param_7,uint param_8,uint *param_9)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  
  uVar5 = 0x57;
  uVar6 = param_4 >> 1;
  uVar8 = param_8 >> 1;
  if (DAT_c0136ca8 < 1) {
    uVar5 = 0x426;
  }
  else {
    iVar1 = FUN_c0106be8((uint)param_1);
    if (iVar1 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      if ((param_1 != (uint *)0x0) &&
         ((((param_1 >= (uint *)0x80000000 && (param_1 < (uint *)0x80000004)) ||
           (((uint *)*param_1 == param_1 && ((char)param_1[2] == -0xb)))) &&
          ((((param_3 != (void *)0x0 && (param_5 != (uint *)0x0)) && (uVar6 != 0)) &&
           ((param_9 != (uint *)0x0 || (param_7 == (void *)0x0)))))))) {
        puVar7 = (uint *)0x0;
        if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
          uVar2 = param_1[*(byte *)((int)param_1 + 9) + 6];
          iVar1 = FUN_c0106a7c(uVar2);
          if (iVar1 == 0) {
            uVar2 = FUN_c0101c94(-0x3fec6e20,uVar2);
          }
          if (uVar2 != 0) {
            puVar7 = *(uint **)(uVar2 + 4);
          }
        }
        else {
          if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
            uVar2 = 0;
          }
          else {
            uVar2 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
          }
          if (uVar2 != 0) {
            puVar7 = *(uint **)((int)param_1 * 4 + uVar2);
          }
        }
        iVar1 = param_2 + 1;
        if (iVar1 == 0) {
          puVar7 = (uint *)0x0;
        }
        while (puVar7 != (uint *)0x0) {
          if (iVar1 == 0) {
LAB_c01087cc:
            if (puVar7 != (uint *)0x0) {
              iVar1 = FUN_c0106a7c((uint)puVar7);
              if (iVar1 == 0) {
                puVar7 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar7);
              }
              if (puVar7 != (uint *)0x0) {
                uVar2 = (uint)*(byte *)((int)puVar7 + 0xc);
                if (uVar6 <= uVar2) {
                  uVar2 = uVar6 - 1;
                }
                memcpy(param_3,(void *)((int)puVar7 + 0x10),uVar2 * 2);
                *(undefined2 *)(uVar2 * 2 + (int)param_3) = 0;
                *param_5 = uVar2;
                if (param_9 != (uint *)0x0) {
                  uVar6 = (uint)*(byte *)((int)puVar7 + 0xd);
                  if ((uVar8 <= uVar6) && (uVar6 = uVar8, uVar8 != 0)) {
                    uVar6 = uVar8 - 1;
                  }
                  memcpy(param_7,(void *)((*(byte *)((int)puVar7 + 0xc) + 8) * 2 + (int)puVar7),
                         uVar6 * 2);
                  *(undefined2 *)(uVar6 * 2 + (int)param_7) = 0;
                  *param_9 = uVar6;
                }
                uVar5 = 0;
                if (uVar2 != *(byte *)((int)puVar7 + 0xc)) {
                  uVar5 = 0xea;
                }
              }
              goto LAB_c01088d8;
            }
            break;
          }
          iVar3 = FUN_c0106a7c((uint)puVar7);
          puVar4 = puVar7;
          if (iVar3 == 0) {
            puVar4 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar7);
          }
          if (puVar4 == (uint *)0x0) goto LAB_c01087cc;
          iVar3 = FUN_c0106ad8((int)puVar4);
          if (iVar3 != 0) {
            iVar1 = iVar1 + 1;
          }
          iVar1 = iVar1 + -1;
          if (iVar1 != 0) {
            puVar7 = (uint *)*puVar4;
          }
        }
        uVar5 = 0x103;
      }
LAB_c01088d8:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    }
  }
  return uVar5;
}



/* c0108964 FUN_c0108964 */

/* Boundary evidence: original MIPS .pdata c0108964..c010896f. Semantic name remains unreviewed. */

undefined4 FUN_c0108964(void)

{
  return 1;
}



/* c0108970 FUN_c0108970 */

/* Boundary evidence: original MIPS .pdata c0108970..c010897b. Semantic name remains unreviewed. */

undefined4 FUN_c0108970(void)

{
  return 1;
}



/* c010897c FUN_c010897c */

/* Boundary evidence: original MIPS .pdata c010897c..c01089c3. Semantic name remains unreviewed. */

void FUN_c010897c(uint *param_1,int param_2,void *param_3,uint param_4,uint *param_5,
                 undefined4 param_6,void *param_7,uint param_8,uint *param_9)

{
  FUN_c0108548(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



/* c01089c4 FUN_c01089c4 */

/* Boundary evidence: original MIPS .pdata c01089c4..c0108f07. Semantic name remains unreviewed. */

undefined4
FUN_c01089c4(uint *param_1,void *param_2,uint param_3,uint *param_4,undefined4 param_5,int *param_6,
            uint *param_7,uint *param_8,int *param_9,uint *param_10,uint *param_11)

{
  int iVar1;
  uint uVar2;
  void *_Src;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  
  uVar3 = 0x57;
  iVar7 = 0;
  local_5c = 0;
  local_58 = 0;
  iVar8 = 0;
  local_54 = 0;
  local_50 = 0;
  if (DAT_c0136ca8 < 1) {
    return 0x426;
  }
  iVar1 = FUN_c0106be8((uint)param_1);
  if (iVar1 == 0) {
    return 0x57;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((param_1 != (uint *)0x0) &&
     ((((param_1 >= (uint *)0x80000000 && (param_1 < (uint *)0x80000004)) ||
       (((uint *)*param_1 == param_1 && ((char)param_1[2] == -0xb)))) &&
      ((param_4 != (uint *)0x0 || (param_2 == (void *)0x0)))))) {
    uVar3 = 0;
    if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
      uVar2 = param_1[*(byte *)((int)param_1 + 9) + 6];
      iVar1 = FUN_c0106a7c(uVar2);
      if (iVar1 == 0) {
        uVar2 = FUN_c0101c94(-0x3fec6e20,uVar2);
      }
      if (uVar2 == 0) goto LAB_c0108e7c;
      puVar4 = *(uint **)(uVar2 + 4);
      puVar5 = *(uint **)(uVar2 + 8);
      uVar6 = (uint)*(byte *)(uVar2 + 0xd);
      _Src = (void *)((*(byte *)(uVar2 + 0xc) + 8) * 2 + uVar2);
    }
    else {
      if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
      }
      if (uVar2 == 0) goto LAB_c0108e7c;
      uVar6 = 0;
      _Src = (void *)0x0;
      puVar4 = *(uint **)((int)param_1 * 4 + uVar2);
      puVar5 = *(uint **)((int)(param_1 + 1) * 4 + uVar2);
    }
    if (param_2 != (void *)0x0) {
      if (param_3 >> 1 < uVar6 + 1) {
        *param_4 = uVar6;
        uVar3 = 0xea;
        goto LAB_c0108e7c;
      }
      if (_Src != (void *)0x0) {
        memcpy(param_2,_Src,uVar6 << 1);
      }
      *(undefined2 *)(uVar6 * 2 + (int)param_2) = 0;
      *param_4 = uVar6;
    }
    for (; puVar4 != (uint *)0x0; puVar4 = (uint *)*puVar4) {
      iVar1 = FUN_c0106a7c((uint)puVar4);
      if (iVar1 == 0) {
        puVar4 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar4);
      }
      if (puVar4 == (uint *)0x0) break;
      if ((param_7 != (uint *)0x0) && (local_5c < (byte)puVar4[3])) {
        local_5c = (uint)(byte)puVar4[3];
      }
      if ((param_8 != (uint *)0x0) && (local_58 < *(byte *)((int)puVar4 + 0xd))) {
        local_58 = (uint)*(byte *)((int)puVar4 + 0xd);
      }
      if (param_6 != (int *)0x0) {
        if (((*(byte *)((int)puVar4 + 0xe) & 2) == 2) ||
           (iVar1 = FUN_c0106ad8((int)puVar4), iVar1 != 0)) {
          if ((*(byte *)((int)puVar4 + 0xe) & 4) == 4) {
            iVar7 = iVar7 + -1;
          }
        }
        else {
          iVar7 = iVar7 + 1;
        }
      }
    }
    if (param_7 != (uint *)0x0) {
      *param_7 = local_5c;
    }
    if (param_8 != (uint *)0x0) {
      *param_8 = local_58;
    }
    if (param_6 != (int *)0x0) {
      *param_6 = iVar7;
    }
    for (; puVar5 != (uint *)0x0; puVar5 = (uint *)*puVar5) {
      iVar7 = FUN_c0106a7c((uint)puVar5);
      if (iVar7 == 0) {
        puVar5 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar5);
      }
      if (puVar5 == (uint *)0x0) break;
      if ((param_10 != (uint *)0x0) && (local_54 < (byte)puVar5[2])) {
        local_54 = (uint)(byte)puVar5[2];
      }
      if ((param_11 != (uint *)0x0) && (local_50 < *(ushort *)((int)puVar5 + 6))) {
        local_50 = (uint)*(ushort *)((int)puVar5 + 6);
      }
      if (param_9 != (int *)0x0) {
        if ((*(byte *)((int)puVar5 + 9) & 2) == 2) {
          if ((*(byte *)((int)puVar5 + 9) & 4) == 4) {
            iVar8 = iVar8 + -1;
          }
        }
        else {
          iVar8 = iVar8 + 1;
        }
      }
    }
    if (param_10 != (uint *)0x0) {
      *param_10 = local_54;
    }
    if (param_11 != (uint *)0x0) {
      *param_11 = local_50;
    }
    if (param_9 != (int *)0x0) {
      *param_9 = iVar8;
    }
    uVar3 = 0;
  }
LAB_c0108e7c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar3;
}



/* c0108f08 FUN_c0108f08 */

/* Boundary evidence: original MIPS .pdata c0108f08..c0108f13. Semantic name remains unreviewed. */

undefined4 FUN_c0108f08(void)

{
  return 1;
}



/* c0108f14 FUN_c0108f14 */

/* Boundary evidence: original MIPS .pdata c0108f14..c0108f1f. Semantic name remains unreviewed. */

undefined4 FUN_c0108f14(void)

{
  return 1;
}



/* c0108f20 FUN_c0108f20 */

/* Boundary evidence: original MIPS .pdata c0108f20..c0108f7f. Semantic name remains unreviewed. */

void FUN_c0108f20(uint *param_1,void *param_2,uint param_3,uint *param_4,undefined4 param_5,
                 int *param_6,uint *param_7,uint *param_8,int *param_9,uint *param_10,uint *param_11
                 )

{
  FUN_c01089c4(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11);
  return;
}



/* c0108f80 FUN_c0108f80 */

/* Boundary evidence: original MIPS .pdata c0108f80..c010918f. Semantic name remains unreviewed. */

undefined4 FUN_c0108f80(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint *lpMem;
  uint *puVar4;
  
  uVar3 = 0x57;
  if (DAT_c0136ca8 < 1) {
    uVar3 = 0x426;
  }
  else {
    iVar2 = FUN_c0106be8((uint)param_1);
    if ((iVar2 != 0) && (param_1 != (uint *)0x0)) {
      if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
        puVar1 = DAT_c01391b4;
        puVar4 = (uint *)0x0;
        while (lpMem = puVar1, lpMem != (uint *)0x0) {
          if (lpMem == param_1) {
            if (lpMem != (uint *)0x0) {
              uVar3 = 0;
              if ((5 < DAT_c0136ca8) && ((DAT_c0137178 & 1) != 0)) {
                uVar3 = FUN_c0113344(param_1,param_2,param_3,param_4);
              }
              puVar1 = (uint *)lpMem[3];
              if (puVar4 != (uint *)0x0) {
                puVar4[3] = lpMem[3];
                puVar1 = DAT_c01391b4;
              }
              DAT_c01391b4 = puVar1;
              *(undefined1 *)(lpMem + 2) = 0;
              *lpMem = 0;
              if (DAT_c0136cf8 != (HANDLE)0x0) {
                HeapFree(DAT_c0136cf8,0,lpMem);
                DAT_c0136cfc = DAT_c0136cfc + -1;
              }
            }
            break;
          }
          puVar4 = lpMem;
          puVar1 = (uint *)lpMem[3];
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      }
      else {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



/* c0109190 FUN_c0109190 */

/* Boundary evidence: original MIPS .pdata c0109190..c010919b. Semantic name remains unreviewed. */

undefined4 FUN_c0109190(void)

{
  return 1;
}



/* c010919c FUN_c010919c */

/* Boundary evidence: original MIPS .pdata c010919c..c01091a7. Semantic name remains unreviewed. */

undefined4 FUN_c010919c(void)

{
  return 1;
}



/* c01091a8 FUN_c01091a8 */

/* Boundary evidence: original MIPS .pdata c01091a8..c0109307. Semantic name remains unreviewed. */

void FUN_c01091a8(int param_1)

{
  undefined4 *puVar1;
  undefined4 *lpMem;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  puVar1 = DAT_c01391b4;
  puVar2 = (undefined4 *)0x0;
  while (lpMem = puVar1, lpMem != (undefined4 *)0x0) {
    if (lpMem[1] == param_1) {
      if (puVar2 == (undefined4 *)0x0) {
        DAT_c01391b4 = (undefined4 *)lpMem[3];
      }
      else {
        puVar2[3] = lpMem[3];
      }
      *(undefined1 *)(lpMem + 2) = 0;
      *lpMem = 0;
      if (DAT_c0136cf8 != (HANDLE)0x0) {
        HeapFree(DAT_c0136cf8,0,lpMem);
        DAT_c0136cfc = DAT_c0136cfc + -1;
      }
      puVar1 = DAT_c01391b4;
      if (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)puVar2[3];
      }
    }
    else {
      puVar1 = (undefined4 *)lpMem[3];
      puVar2 = lpMem;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return;
}



/* c0109308 FUN_c0109308 */

/* Boundary evidence: original MIPS .pdata c0109308..c0109313. Semantic name remains unreviewed. */

undefined4 FUN_c0109308(void)

{
  return 1;
}



/* c0109314 FUN_c0109314 */

/* Boundary evidence: original MIPS .pdata c0109314..c010931f. Semantic name remains unreviewed. */

undefined4 FUN_c0109314(void)

{
  return 1;
}



/* c0109320 FUN_c0109320 */

/* Boundary evidence: original MIPS .pdata c0109320..c010937f. Semantic name remains unreviewed. */

void FUN_c0109320(void)

{
  do {
    WaitForSingleObject(DAT_c0136cf0,DAT_c0136838);
    RegFlushKey((HKEY)&DAT_80000002);
    RegFlushKey((HKEY)0x80000001);
  } while( true );
}



/* c0109380 FUN_c0109380 */

/* Boundary evidence: original MIPS .pdata c0109380..c010964f. Semantic name remains unreviewed. */

void FUN_c0109380(void)

{
  LSTATUS LVar1;
  DWORD local_248 [2];
  HKEY local_240;
  int local_23c;
  DWORD aDStack_238 [2];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c0136c78;
  local_23c = 0;
  LVar1 = RegOpenKeyExW((HKEY)&DAT_80000002,L"System\\ObjectStore\\RegFlush",0,0,&local_240);
  if (LVar1 != 0) goto LAB_c0109624;
  local_248[1] = 0x208;
  LVar1 = RegQueryValueExW(local_240,L"ActivityName",(LPDWORD)0x0,local_248,(LPBYTE)aWStack_230,
                           local_248 + 1);
  if ((LVar1 == 0) && (local_248[0] == 1)) {
    DAT_c0136cf0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,aWStack_230);
    if (DAT_c0136cf0 != (HANDLE)0x0) {
      SetEventData(DAT_c0136cf0,0);
    }
  }
  local_248[1] = 4;
  LVar1 = RegQueryValueExW(local_240,L"ActivityThreshold",(LPDWORD)0x0,local_248,
                           (LPBYTE)&DAT_c0136834,local_248 + 1);
  if ((LVar1 != 0) || (local_248[0] != 4)) {
    DAT_c0136834 = 10;
  }
  local_248[1] = 4;
  LVar1 = RegQueryValueExW(local_240,L"SpawnThread",(LPDWORD)0x0,local_248,(LPBYTE)&local_23c,
                           local_248 + 1);
  if (((LVar1 == 0) && (local_248[0] == 4)) && (local_23c == 1)) {
    if (DAT_c0136cf0 == (HANDLE)0x0) {
      DAT_c0136cf0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if (DAT_c0136cf0 == (HANDLE)0x0) goto LAB_c0109614;
    }
    LVar1 = RegQueryValueExW(local_240,L"FlushPriority256",(LPDWORD)0x0,local_248,
                             (LPBYTE)&DAT_c01394f4,local_248 + 1);
    if ((LVar1 != 0) || (local_248[0] != 4)) {
      DAT_c01394f4 = 0xff;
    }
    LVar1 = RegQueryValueExW(local_240,L"FlushPeriod",(LPDWORD)0x0,local_248,(LPBYTE)&DAT_c0136838,
                             local_248 + 1);
    if ((LVar1 != 0) || (local_248[0] != 4)) {
      DAT_c0136838 = 0xffffffff;
    }
    DAT_c01394f0 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0109320,(LPVOID)0x0,0,aDStack_238)
    ;
    if (DAT_c01394f0 != (HANDLE)0x0) {
      CeSetThreadPriority(DAT_c01394f0,DAT_c01394f4);
    }
  }
LAB_c0109614:
  RegCloseKey(local_240);
LAB_c0109624:
  FUN_c013331c(local_28);
  return;
}



/* c0109650 FUN_c0109650 */

/* Boundary evidence: original MIPS .pdata c0109650..c01096d7. Semantic name remains unreviewed. */

void FUN_c0109650(undefined4 param_1,ushort *param_2)

{
  DAT_c01391c4 = FUN_c01316a4(L"HKLM");
  DAT_c01391c8 = FUN_c01316a4(L"HKCU");
  DAT_c01391cc = FUN_c01316a4(L"HKCR");
  DAT_c01391c0 = FUN_c01316a4(L"HKU");
  FUN_c0112edc(param_1,param_2);
  return;
}



/* c01096d8 FUN_c01096d8 */

/* Boundary evidence: original MIPS .pdata c01096d8..c010987f. Semantic name remains unreviewed. */

undefined4 FUN_c01096d8(uint *param_1,undefined4 param_2,uint param_3,HANDLE param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_24;
  
  uVar3 = 0xffffffff;
  if (DAT_c0136ca8 < 1) {
    SetLastError(0x426);
  }
  else {
    iVar1 = FUN_c0106be8((uint)param_1);
    if (iVar1 == 0) {
      SetLastError(0x57);
    }
    else {
      uVar2 = 0;
      if ((param_3 & 1) != 0) {
        uVar2 = 2;
      }
      if ((param_3 & 4) != 0) {
        uVar2 = uVar2 | 0x15;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      iVar1 = FUN_c010834c(param_1,&local_24);
      if (iVar1 != 0) {
        uVar3 = FUN_c0131c40(local_24,param_4,(wchar_t *)&DAT_c0137180,param_2,
                             param_3 & 0xf0000000 | uVar2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    }
  }
  return uVar3;
}



/* c0109880 FUN_c0109880 */

/* Boundary evidence: original MIPS .pdata c0109880..c010988b. Semantic name remains unreviewed. */

undefined4 FUN_c0109880(void)

{
  return 1;
}



/* c010988c FUN_c010988c */

/* Boundary evidence: original MIPS .pdata c010988c..c0109897. Semantic name remains unreviewed. */

undefined4 FUN_c010988c(void)

{
  return 1;
}



/* c0109898 FUN_c0109898 */

/* Boundary evidence: original MIPS .pdata c0109898..c01098eb. Semantic name remains unreviewed. */

void FUN_c0109898(uint *param_1,undefined4 param_2,uint param_3)

{
  HANDLE pvVar1;
  
  pvVar1 = (HANDLE)__GetUserKData(0xc);
  FUN_c01096d8(param_1,param_2,param_3,pvVar1);
  return;
}



/* c01098ec FUN_c01098ec */

/* Boundary evidence: original MIPS .pdata c01098ec..c010993b. Semantic name remains unreviewed. */

void FUN_c01098ec(uint *param_1,undefined4 param_2,uint param_3)

{
  HANDLE pvVar1;
  
  pvVar1 = (HANDLE)GetCallerVMProcessId();
  FUN_c01096d8(param_1,param_2,param_3,pvVar1);
  return;
}



/* c010993c FUN_c010993c */

/* Boundary evidence: original MIPS .pdata c010993c..c0109967. Semantic name remains unreviewed. */

void FUN_c010993c(HANDLE param_1)

{
  FUN_c0132968(param_1,0,0,0,0,0);
  return;
}



/* c0109968 FUN_c0109968 */

/* Boundary evidence: original MIPS .pdata c0109968..c0109993. Semantic name remains unreviewed. */

void FUN_c0109968(undefined4 param_1)

{
  FUN_c013283c(param_1,0,0,0,0,0);
  return;
}



/* c0109994 FUN_c0109994 */

/* Boundary evidence: original MIPS .pdata c0109994..c01099af. Semantic name remains unreviewed. */

void FUN_c0109994(HANDLE param_1)

{
  FUN_c0132bd8(param_1);
  return;
}



/* c01099b0 FUN_c01099b0 */

/* Boundary evidence: original MIPS .pdata c01099b0..c01099cb. Semantic name remains unreviewed. */

void FUN_c01099b0(void)

{
  FUN_c0132b8c();
  return;
}



/* c01099cc FUN_c01099cc */

/* Boundary evidence: original MIPS .pdata c01099cc..c0109d5b. Semantic name remains unreviewed. */

bool FUN_c01099cc(uint *param_1,int param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  bool bVar4;
  uint cchDest;
  STRSAFE_LPWSTR local_38;
  uint *local_34;
  undefined4 local_30;
  
  bVar4 = false;
  local_30 = 0;
  local_38 = (STRSAFE_LPWSTR)0x0;
  iVar2 = __GetUserKData(0xc);
  bVar1 = param_2 != iVar2;
  if (DAT_c0136ca8 < 1) {
    SetLastError(0x426);
  }
  else {
    iVar2 = FUN_c0106be8((uint)param_1);
    if (iVar2 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      param_3[2] = 0;
      if (*param_3 == 0x14) {
        if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
          if (*(char *)((int)param_1 + 9) == '\0') {
            param_3[1] = 0;
          }
          else {
            param_3[1] = param_1[6];
          }
          if ((param_1[4] & 1) != 0) {
            param_3[2] = 1;
          }
        }
        else {
          param_3[1] = (int)param_1;
        }
        if ((param_3[4] == 0) ||
           (((bVar1 && (iVar2 = CeOpenCallerBuffer(&local_34,param_3[4],4,0xd,0), iVar2 < 0)) ||
            (cchDest = *local_34, 0x7ffffffe < cchDest)))) {
          SetLastError(0x57);
        }
        else {
          FUN_c010834c(param_1,(undefined4 *)0x0);
          if ((param_3[3] == 0) || (cchDest == 0)) {
            bVar4 = true;
            local_30 = 1;
          }
          else if ((bVar1) &&
                  (iVar2 = CeOpenCallerBuffer(&local_38,param_3[3],cchDest << 1,8,0), iVar2 < 0)) {
            SetLastError(0x57);
          }
          else {
            sVar3 = wcslen((wchar_t *)&DAT_c0137180);
            bVar4 = cchDest < sVar3 + 1;
            if (bVar4) {
              SetLastError(0x7a);
            }
            else {
              StringCchCopyW(local_38,cchDest,(STRSAFE_LPCWSTR)&DAT_c0137180);
              local_30 = 1;
            }
            bVar4 = !bVar4;
            if (bVar1) {
              CeCloseCallerBuffer(local_38,param_3[3],cchDest << 1,8);
            }
          }
          sVar3 = wcslen((wchar_t *)&DAT_c0137180);
          *local_34 = sVar3 + 1;
          if (bVar1) {
            CeCloseCallerBuffer(local_34,param_3[4],4,0xd);
          }
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      return bVar4;
    }
    SetLastError(0x57);
  }
  return false;
}



/* c0109d5c FUN_c0109d5c */

/* Boundary evidence: original MIPS .pdata c0109d5c..c0109d67. Semantic name remains unreviewed. */

undefined4 FUN_c0109d5c(void)

{
  return 1;
}



/* c0109d68 FUN_c0109d68 */

/* Boundary evidence: original MIPS .pdata c0109d68..c0109d73. Semantic name remains unreviewed. */

undefined4 FUN_c0109d68(void)

{
  return 1;
}



/* c0109d74 FUN_c0109d74 */

/* Boundary evidence: original MIPS .pdata c0109d74..c010a133. Semantic name remains unreviewed. */

int FUN_c0109d74(undefined4 param_1,uint *param_2,int param_3,uint param_4,wchar_t *param_5,
                uint param_6,void *param_7,uint param_8,undefined4 *param_9,int param_10,
                uint *param_11,uint param_12)

{
  byte bVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  
  if ((param_6 < 0x100) && (param_8 < 0x100)) {
    if ((param_10 == 0) || (FUN_c010297c(-0x3fec6e20), param_5 == (wchar_t *)0x0)) {
      piVar7 = (int *)*param_2;
      while (piVar7 != (int *)0x0) {
        iVar5 = FUN_c0106a7c((uint)piVar7);
        piVar2 = piVar7;
        if (iVar5 == 0) {
          piVar2 = (int *)FUN_c0101c94(-0x3fec6e20,(uint)piVar7);
        }
        if (piVar2 == (int *)0x0) {
          iVar5 = 2;
          goto LAB_c010a0d0;
        }
        if (param_5 == (wchar_t *)0x0) {
          if (piVar7 == *(int **)((param_4 & 0xff) * 4 + param_3)) goto LAB_c0109e84;
        }
        else if ((param_6 == *(byte *)(piVar2 + 3)) &&
                (iVar5 = _wcsnicmp((wchar_t *)(piVar2 + 4),param_5,param_6), iVar5 == 0)) {
LAB_c0109e84:
          if ((*param_11 & 1) != 0) {
            if ((param_5 == (wchar_t *)0x0) ||
               (iVar5 = FUN_c0106e0c(param_5,param_6,*param_11), iVar5 == 0)) {
              *param_11 = 0;
            }
            else {
              *param_11 = 2;
            }
          }
          if (((*(byte *)((int)piVar2 + 0xe) & 8) == 8) &&
             (iVar5 = FUN_c0106ad8((int)piVar2), iVar5 != 0)) {
            piVar2[1] = 0;
            piVar2[2] = 0;
            if (param_10 == 0) {
              FUN_c01076ec(param_1,(int *)param_2,piVar7);
              *(undefined4 *)((param_4 & 0xff) * 4 + param_3) = 0;
              return 2;
            }
            goto LAB_c0109f70;
          }
          *(int **)((param_4 & 0xff) * 4 + param_3) = piVar7;
          goto LAB_c0109f60;
        }
        piVar7 = (int *)*piVar2;
      }
    }
    else {
      *(undefined4 *)(param_4 * 4 + param_3) = 0;
    }
    if (param_10 == 0) {
      iVar5 = 2;
    }
    else {
LAB_c0109f70:
      if ((*param_11 & 1) != 0) {
        if ((param_5 == (wchar_t *)0x0) ||
           (iVar5 = FUN_c0106e0c(param_5,param_6,*param_11), iVar5 == 0)) {
          *param_11 = 0;
        }
        else {
          *param_11 = 2;
        }
      }
      iVar5 = 4;
      if ((param_12 & 1) == 0) {
        iVar5 = 0;
      }
      iVar8 = (param_6 + param_8 + 8) * 2;
      puVar3 = FUN_c0103dc8(&DAT_c01391e0,0xc,iVar8 + iVar5,0,0);
      puVar6 = puVar3 + 3;
      if (puVar3 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      if (puVar6 == (uint *)0x0) {
        iVar5 = 0x70;
      }
      else {
        *(undefined1 *)((int)puVar6 + 0xe) = 0;
        puVar6[1] = 0;
        puVar6[2] = 0;
        *(char *)(puVar6 + 3) = (char)param_6;
        if (param_5 != (wchar_t *)0x0) {
          memcpy(puVar6 + 4,param_5,param_6 << 1);
        }
        *(char *)((int)puVar6 + 0xd) = (char)param_8;
        if (param_8 != 0) {
          memcpy((void *)((param_6 + 8) * 2 + (int)puVar6),param_7,param_8 << 1);
        }
        bVar1 = *(byte *)((int)puVar6 + 0xe);
        *(byte *)((int)puVar6 + 0xe) = bVar1;
        if ((param_12 & 1) != 0) {
          *(byte *)((int)puVar6 + 0xe) = bVar1 | 8;
          *(undefined4 *)(iVar8 + (int)puVar6) = DAT_c0136ce4;
        }
        *puVar6 = *param_2;
        FUN_c01029e4(-0x3fec6e20,1,param_2,*param_2,4);
        uVar4 = puVar6[-1];
        *(uint *)((param_4 & 0xff) * 4 + param_3) = uVar4;
        *param_2 = uVar4;
        if (param_9 != (undefined4 *)0x0) {
          *param_9 = 1;
        }
        FUN_c0106c68(&DAT_c01391e0);
LAB_c0109f60:
        iVar5 = 0;
      }
LAB_c010a0d0:
      if (param_10 != 0) {
        if (iVar5 == 0) {
          FUN_c0102aa4(&DAT_c01391e0);
        }
        else {
          FUN_c01036ac(&DAT_c01391e0);
        }
      }
    }
  }
  else {
    iVar5 = 0x57;
  }
  return iVar5;
}



/* c010a134 FUN_c010a134 */

/* Boundary evidence: original MIPS .pdata c010a134..c010a53b. Semantic name remains unreviewed. */

int FUN_c010a134(undefined4 param_1,uint param_2,uint *param_3,undefined1 *param_4,
                undefined4 *param_5,uint *param_6)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  wchar_t wVar4;
  wchar_t *_Str2;
  int *piVar5;
  wchar_t *pwVar6;
  uint uVar7;
  uint _MaxCount;
  int *piVar8;
  
  _Str2 = (wchar_t *)*param_5;
  if (_Str2 != (wchar_t *)0x0) {
    if (*_Str2 == L'\\') {
      _Str2 = _Str2 + 1;
    }
    if (_Str2 == (wchar_t *)0x0) {
      return 0;
    }
    if (*_Str2 == L'\0') {
      return 0;
    }
    if ((param_2 < 0x80000000) || (0x80000003 < param_2)) {
      uVar1 = *(uint *)((*(byte *)(param_2 + 9) + 6) * 4 + param_2);
      iVar2 = FUN_c0106a7c(uVar1);
      if (iVar2 == 0) {
        uVar1 = FUN_c0101c94(-0x3fec6e20,uVar1);
      }
      if (uVar1 == 0) {
        return 0x57;
      }
      uVar7 = (uint)*(byte *)(param_2 + 9);
      if (0xe < uVar7) {
        uVar7 = 0xf;
      }
      memcpy(param_3,(void *)(param_2 + 0x18),(uVar7 + 1) * 4);
      piVar8 = (int *)(uVar1 + 4);
    }
    else {
      if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
        uVar1 = 0;
      }
      else {
        uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
      }
      if (uVar1 == 0) {
        return 0x57;
      }
      *param_3 = param_2;
      uVar7 = 0;
      piVar8 = (int *)(param_2 * 4 + uVar1);
    }
    if (piVar8 == (int *)0x0) {
      return 0x57;
    }
    do {
      wVar4 = *_Str2;
      pwVar6 = _Str2;
      if (wVar4 == L'\0') {
        return 0x57;
      }
      do {
        if (wVar4 == L'\\') break;
        pwVar6 = pwVar6 + 1;
        wVar4 = *pwVar6;
      } while (wVar4 != L'\0');
      if (pwVar6 == _Str2) {
        return 0x57;
      }
      if (0xe < uVar7) {
        return 0x57;
      }
      uVar1 = uVar7 + 1;
      _MaxCount = (int)pwVar6 - (int)_Str2 >> 1;
      if (_MaxCount < 0x100) {
        piVar5 = (int *)*piVar8;
        while (piVar5 != (int *)0x0) {
          iVar2 = FUN_c0106a7c((uint)piVar5);
          piVar3 = piVar5;
          if (iVar2 == 0) {
            piVar3 = (int *)FUN_c0101c94(-0x3fec6e20,(uint)piVar5);
          }
          if (piVar3 == (int *)0x0) {
LAB_c010a448:
            iVar2 = 2;
            goto LAB_c010a454;
          }
          if ((_MaxCount == *(byte *)(piVar3 + 3)) &&
             (iVar2 = _wcsnicmp((wchar_t *)(piVar3 + 4),_Str2,_MaxCount), iVar2 == 0)) {
            if ((*param_6 & 1) != 0) {
              iVar2 = FUN_c0106e0c(_Str2,_MaxCount,*param_6);
              if (iVar2 == 0) {
                *param_6 = 0;
              }
              else {
                *param_6 = 2;
              }
            }
            if (((*(byte *)((int)piVar3 + 0xe) & 8) == 8) &&
               (iVar2 = FUN_c0106ad8((int)piVar3), iVar2 != 0)) {
              piVar3[1] = 0;
              piVar3[2] = 0;
              FUN_c01076ec(param_1,piVar8,piVar5);
              param_3[uVar1 & 0xff] = 0;
              goto LAB_c010a448;
            }
            iVar2 = 0;
            param_3[uVar1 & 0xff] = (uint)piVar5;
            goto LAB_c010a454;
          }
          piVar5 = (int *)*piVar3;
        }
        iVar2 = 2;
      }
      else {
        iVar2 = 0x57;
      }
LAB_c010a454:
      if (iVar2 != 0) {
        *param_4 = (char)uVar7;
        *param_5 = _Str2;
        return iVar2;
      }
      wVar4 = *pwVar6;
      _Str2 = pwVar6;
      while (wVar4 == L'\\') {
        _Str2 = _Str2 + 1;
        wVar4 = *_Str2;
      }
      if (*_Str2 != L'\0') {
        uVar7 = param_3[uVar1 & 0xff];
        iVar2 = FUN_c0106a7c(uVar7);
        if (iVar2 == 0) {
          uVar7 = FUN_c0101c94(-0x3fec6e20,uVar7);
        }
        if (uVar7 == 0) {
          return 0x57;
        }
        piVar8 = (int *)(uVar7 + 4);
      }
      uVar7 = uVar1 & 0xff;
    } while (*_Str2 != L'\0');
    *param_4 = (char)uVar1;
    *param_5 = _Str2;
  }
  return 0;
}



/* c010a53c FUN_c010a53c */

/* Boundary evidence: original MIPS .pdata c010a53c..c010a8c3. Semantic name remains unreviewed. */

int FUN_c010a53c(undefined4 param_1,int *param_2,byte *param_3,wchar_t *param_4,wchar_t *param_5,
                undefined4 *param_6,undefined4 param_7,uint param_8)

{
  int iVar1;
  size_t sVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  
  uVar7 = (uint)*param_3;
  if (uVar7 == 0) {
    if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
    }
    if (uVar6 != 0) {
      puVar9 = (uint *)(*param_2 * 4 + uVar6);
      goto LAB_c010a60c;
    }
  }
  else {
    uVar6 = param_2[uVar7];
    iVar1 = FUN_c0106a7c(uVar6);
    if (iVar1 == 0) {
      uVar6 = FUN_c0101c94(-0x3fec6e20,uVar6);
    }
    if (uVar6 != 0) {
      puVar9 = (uint *)(uVar6 + 4);
LAB_c010a60c:
      if (puVar9 != (uint *)0x0) {
        if (param_5 == (wchar_t *)0x0) {
          sVar2 = 0;
        }
        else {
          sVar2 = wcslen(param_5);
        }
        pwVar5 = param_4;
        uVar6 = uVar7;
        if (param_4 != (wchar_t *)0x0) {
          do {
            wVar3 = *pwVar5;
            pwVar4 = pwVar5;
            if (wVar3 == L'\0') goto LAB_c010a88c;
            do {
              if (wVar3 == L'\\') break;
              pwVar4 = pwVar4 + 1;
              wVar3 = *pwVar4;
            } while (wVar3 != L'\0');
            if ((pwVar4 == pwVar5) || (0xe < uVar6)) goto LAB_c010a88c;
            wVar3 = *pwVar4;
            while (wVar3 == L'\\') {
              pwVar4 = pwVar4 + 1;
              wVar3 = *pwVar4;
            }
            pwVar5 = pwVar4;
            uVar6 = uVar6 + 1 & 0xff;
            uVar8 = uVar7;
          } while (*pwVar4 != L'\0');
          do {
            wVar3 = *param_4;
            pwVar5 = param_4;
            uVar7 = uVar8;
            if (wVar3 == L'\0') goto LAB_c010a88c;
            do {
              if (wVar3 == L'\\') break;
              pwVar5 = pwVar5 + 1;
              wVar3 = *pwVar5;
            } while (wVar3 != L'\0');
            if ((pwVar5 == param_4) || (0xe < uVar8)) goto LAB_c010a88c;
            if (uVar8 == 0) {
LAB_c010a7a4:
              uVar7 = uVar8 + 1 & 0xff;
              iVar1 = FUN_c0109d74(param_1,puVar9,(int)param_2,uVar7,param_4,
                                   (int)pwVar5 - (int)param_4 >> 1,param_5,sVar2,param_6,1,&param_7,
                                   param_8);
            }
            else {
              uVar7 = param_2[uVar8];
              iVar1 = FUN_c0106a7c(uVar7);
              if (iVar1 == 0) {
                uVar7 = FUN_c0101c94(-0x3fec6e20,uVar7);
              }
              if ((uVar7 == 0) || ((*(byte *)(uVar7 + 0xe) & 8) != 8)) goto LAB_c010a7a4;
              uVar7 = uVar8 + 1 & 0xff;
              iVar1 = FUN_c0106f40(puVar9,(int)param_2,uVar7,param_4,(int)pwVar5 - (int)param_4 >> 1
                                   ,param_5,sVar2,param_6,&param_7);
            }
            if (iVar1 != 0) goto LAB_c010a890;
            wVar3 = *pwVar5;
            param_4 = pwVar5;
            while (wVar3 == L'\\') {
              param_4 = param_4 + 1;
              wVar3 = *param_4;
            }
            if (*param_4 != L'\0') {
              uVar6 = param_2[uVar7];
              iVar1 = FUN_c0106a7c(uVar6);
              if (iVar1 == 0) {
                uVar6 = FUN_c0101c94(-0x3fec6e20,uVar6);
              }
              puVar9 = (uint *)(uVar6 + 4);
              if (uVar6 == 0) {
                puVar9 = (uint *)0x0;
              }
            }
            uVar8 = uVar7;
          } while (*param_4 != L'\0');
        }
        iVar1 = 0;
        uVar8 = uVar7;
        goto LAB_c010a890;
      }
    }
  }
LAB_c010a88c:
  iVar1 = 0x57;
  uVar8 = uVar7;
LAB_c010a890:
  *param_3 = (byte)uVar8;
  return iVar1;
}



/* c010a8c4 FUN_c010a8c4 */

/* Boundary evidence: original MIPS .pdata c010a8c4..c010abd7. Semantic name remains unreviewed. */

undefined4
FUN_c010a8c4(uint *param_1,wchar_t *param_2,short *param_3,uint *param_4,void *param_5,uint *param_6
            )

{
  byte bVar1;
  int iVar2;
  size_t _MaxCount;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  byte local_78 [4];
  uint local_74;
  short *local_70 [2];
  uint auStack_68 [16];
  
  uVar5 = 0x57;
  puVar3 = (uint *)0x0;
  if ((param_1 != (uint *)0x0) &&
     ((((param_1 >= (uint *)0x80000000 && (param_1 < (uint *)0x80000004)) ||
       (((uint *)*param_1 == param_1 && ((char)param_1[2] == -0xb)))) &&
      ((param_6 != (uint *)0x0 || (param_5 == (void *)0x0)))))) {
    if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
      param_2 = L"Default";
    }
    if ((param_3 == (short *)0x0) || (*param_3 == 0)) {
      if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
        uVar4 = param_1[*(byte *)((int)param_1 + 9) + 6];
        iVar2 = FUN_c0106a7c(uVar4);
        if (iVar2 == 0) {
          uVar4 = FUN_c0101c94(-0x3fec6e20,uVar4);
        }
        if (uVar4 != 0) {
          puVar3 = *(uint **)(uVar4 + 8);
        }
      }
      else {
        if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
        }
        if (uVar4 != 0) {
          puVar3 = *(uint **)((int)(param_1 + 1) * 4 + uVar4);
        }
      }
    }
    else {
      local_78[0] = 0;
      local_74 = 0;
      local_70[0] = param_3;
      iVar2 = FUN_c010a134(1,(uint)param_1,auStack_68,local_78,local_70,&local_74);
      if (iVar2 == 0) {
        uVar4 = auStack_68[local_78[0]];
        iVar2 = FUN_c0106a7c(uVar4);
        if (iVar2 == 0) {
          uVar4 = FUN_c0101c94(-0x3fec6e20,uVar4);
        }
        if (uVar4 != 0) {
          puVar3 = *(uint **)(uVar4 + 8);
        }
      }
    }
    uVar5 = 2;
    _MaxCount = wcslen(param_2);
    for (; puVar3 != (uint *)0x0; puVar3 = (uint *)*puVar3) {
      iVar2 = FUN_c0106a7c((uint)puVar3);
      if (iVar2 == 0) {
        puVar3 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar3);
      }
      if (puVar3 == (uint *)0x0) {
        return 2;
      }
      if (((byte)puVar3[2] == _MaxCount) &&
         (iVar2 = _wcsnicmp((wchar_t *)((int)puVar3 + 10),param_2,_MaxCount), iVar2 == 0)) {
        if ((*(byte *)((int)puVar3 + 9) & 4) == 4) {
          return 2;
        }
        uVar5 = 0;
        if (param_4 != (uint *)0x0) {
          *param_4 = (uint)(ushort)puVar3[1];
        }
        if (param_5 == (void *)0x0) {
          if (param_6 == (uint *)0x0) {
            return 0;
          }
        }
        else {
          uVar4 = (uint)*(ushort *)((int)puVar3 + 6);
          if (*param_6 < uVar4) {
            bVar1 = (byte)puVar3[2];
            uVar5 = 0xea;
            uVar4 = *param_6;
          }
          else {
            bVar1 = (byte)puVar3[2];
          }
          memcpy(param_5,(void *)((bVar1 + 5) * 2 + (int)puVar3),uVar4);
        }
        *param_6 = (uint)*(ushort *)((int)puVar3 + 6);
        return uVar5;
      }
    }
  }
  return uVar5;
}



/* c010abd8 FUN_c010abd8 */

/* Boundary evidence: original MIPS .pdata c010abd8..c010af77. Semantic name remains unreviewed. */

int FUN_c010abd8(uint *param_1,short *param_2,wchar_t *param_3,undefined2 *param_4,uint *param_5,
                uint param_6,uint param_7,undefined4 *param_8)

{
  int iVar1;
  HMODULE hInstance;
  void *_Src;
  uint uVar2;
  WCHAR *pWVar3;
  size_t _Size;
  UINT UVar4;
  UINT uID;
  WCHAR local_238 [259];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_c0136c78;
  UVar4 = 0xffffffff;
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 1;
  }
  if ((param_5 == (uint *)0x0) || (0x103 < *param_5)) {
    iVar1 = 0;
    if (param_8 == (undefined4 *)0x0) {
      iVar1 = 0xd;
    }
    goto LAB_c010aef8;
  }
  local_32 = 0;
  param_7 = 0x15;
  *param_5 = 0x103;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  iVar1 = FUN_c010a8c4(param_1,param_3,param_2,&param_7,local_238,param_5);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (iVar1 == 0) {
    iVar1 = 0xd;
    pWVar3 = local_238;
    while( true ) {
      uID = UVar4;
      if ((local_238 + 0x101 <= pWVar3) || (uID = 0xffffffff, *pWVar3 == L'\0')) goto LAB_c010ada4;
      if (*pWVar3 == L',') break;
      pWVar3 = pWVar3 + 1;
    }
    *pWVar3 = L'\0';
    if (pWVar3[1] == L'#') {
      UVar4 = _wtol(pWVar3 + 2);
    }
    pWVar3 = local_238;
    uID = UVar4;
LAB_c010ada4:
    if (((pWVar3 == local_238) && (uID != 0xffffffff)) &&
       (hInstance = LoadLibraryExW(local_238,(HANDLE)0x0,2), hInstance != (HMODULE)0x0)) {
      _Src = (void *)LoadStringW(hInstance,uID,(LPWSTR)0x0,0);
      if (_Src != (void *)0x0) {
        uVar2 = (uint)*(ushort *)((int)_Src + -2);
        if ((uVar2 != 0) && (*(short *)((int)_Src + uVar2 * 2 + -2) == 0)) {
          uVar2 = uVar2 - 1;
        }
        if (0x7fe < uVar2) {
          uVar2 = 0x7fe;
        }
        _Size = uVar2 * 2;
        if (param_4 == (undefined2 *)0x0) {
LAB_c010ae8c:
          iVar1 = 0;
        }
        else {
          if (_Size + 2 <= param_6) {
            memcpy(param_4,_Src,_Size);
            param_4[uVar2] = 0;
            goto LAB_c010ae8c;
          }
          iVar1 = 0xea;
        }
        *param_5 = _Size + 2;
      }
      FreeLibrary(hInstance);
    }
  }
  if (iVar1 == 0xd) {
    *param_5 = 0;
    if ((param_4 != (undefined2 *)0x0) && (1 < param_6)) {
      *param_4 = 0;
    }
    iVar1 = 0;
  }
LAB_c010aef8:
  FUN_c013331c(local_30);
  return iVar1;
}



/* c010af78 FUN_c010af78 */

/* Boundary evidence: original MIPS .pdata c010af78..c010af83. Semantic name remains unreviewed. */

undefined4 FUN_c010af78(void)

{
  return 1;
}



/* c010af84 FUN_c010af84 */

/* Boundary evidence: original MIPS .pdata c010af84..c010af8f. Semantic name remains unreviewed. */

undefined4 FUN_c010af84(void)

{
  return 1;
}



/* c010af90 FUN_c010af90 */

/* Boundary evidence: original MIPS .pdata c010af90..c010af9b. Semantic name remains unreviewed. */

undefined4 FUN_c010af90(void)

{
  return 1;
}



/* c010af9c FUN_c010af9c */

/* Boundary evidence: original MIPS .pdata c010af9c..c010b2ab. Semantic name remains unreviewed. */

int FUN_c010af9c(undefined4 *param_1,wchar_t *param_2,undefined4 param_3,wchar_t *param_4,
                uint param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8,int *param_9,
                undefined4 param_10)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  wchar_t *local_res4 [3];
  byte local_80 [4];
  uint local_7c;
  int local_78;
  int local_74;
  int local_70;
  uint auStack_68 [16];
  
  iVar3 = 0x57;
  local_70 = 0x57;
  if (DAT_c0136ca8 < 1) {
    iVar3 = 0x426;
  }
  else {
    local_res4[0] = param_2;
    iVar2 = FUN_c0106be8((uint)param_1);
    if (iVar2 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      iVar2 = local_70;
      if ((param_1 != (undefined4 *)0x0) &&
         (((param_1 >= (undefined4 *)0x80000000 && (param_1 < (undefined4 *)0x80000004)) ||
          (((undefined4 *)*param_1 == param_1 && (*(char *)(param_1 + 2) == -0xb)))))) {
        local_80[0] = 0;
        local_78 = 2;
        memset(auStack_68,0,0x40);
        iVar2 = local_70;
        if (param_8 != (undefined4 *)0x0) {
          if ((param_1 < (undefined4 *)0x80000000) || ((undefined4 *)0x80000003 < param_1)) {
            local_7c = 2;
            if ((param_1[4] & 1) == 0) {
              local_7c = 0;
            }
          }
          else {
            local_7c = (1 << ((uint)(param_1 + -0x20000000) & 0x1f)) << 0x10 | 1;
          }
          iVar3 = FUN_c010a134(1,(uint)param_1,auStack_68,local_80,local_res4,&local_7c);
          uVar1 = local_7c;
          iVar5 = 2;
          if (iVar3 == 2) {
            local_74 = iVar3;
            iVar3 = FUN_c010a53c(1,(int *)auStack_68,local_80,local_res4[0],param_4,&local_78,
                                 local_7c,param_5);
            iVar5 = local_78;
          }
          if (param_9 != (int *)0x0) {
            *param_9 = iVar5;
          }
          local_74 = iVar3;
          iVar2 = iVar3;
          if (iVar3 == 0) {
            uVar4 = (uint)local_80[0];
            iVar3 = FUN_c01070c8(1,auStack_68,uVar4,uVar1,param_8,param_1,param_10);
            local_74 = iVar3;
            iVar2 = iVar3;
            if (((iVar5 == 1) && (iVar3 == 0)) &&
               (FUN_c01081a4(1,auStack_68,uVar4,(wchar_t *)0x0,&local_78), 1 < DAT_c0136ca8)) {
              FUN_c0132470(local_78,(wchar_t *)&DAT_c0137180,1,1);
            }
          }
        }
      }
      local_70 = iVar2;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    }
  }
  return iVar3;
}



/* c010b2ac FUN_c010b2ac */

/* Boundary evidence: original MIPS .pdata c010b2ac..c010b2b7. Semantic name remains unreviewed. */

undefined4 FUN_c010b2ac(void)

{
  return 1;
}



/* c010b2b8 FUN_c010b2b8 */

/* Boundary evidence: original MIPS .pdata c010b2b8..c010b2c3. Semantic name remains unreviewed. */

undefined4 FUN_c010b2b8(void)

{
  return 1;
}



/* c010b2c4 FUN_c010b2c4 */

/* Boundary evidence: original MIPS .pdata c010b2c4..c010b34f. Semantic name remains unreviewed. */

void FUN_c010b2c4(undefined4 *param_1,wchar_t *param_2,undefined4 param_3,wchar_t *param_4,
                 uint param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8,int *param_9
                 )

{
  undefined4 uVar1;
  
  uVar1 = __GetUserKData(0xc);
  FUN_c010af9c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,uVar1);
  return;
}



/* c010b350 FUN_c010b350 */

/* Boundary evidence: original MIPS .pdata c010b350..c010b4b3. Semantic name remains unreviewed. */

int FUN_c010b350(undefined4 *param_1,int param_2,undefined4 param_3,int param_4,uint param_5,
                undefined4 param_6,int param_7,undefined4 *param_8,int *param_9)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  wchar_t *local_38;
  wchar_t *local_34;
  undefined1 auStack_30 [16];
  
  local_38 = (wchar_t *)0x0;
  local_34 = (wchar_t *)0x0;
  uVar1 = GetCallerVMProcessId();
  if (param_7 == 0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    iVar2 = CeSafeCopyMemory(auStack_30,param_7,0xc);
    if (iVar2 == 0) {
      return 0x57;
    }
    puVar3 = auStack_30;
  }
  if (((param_2 == 0) || (iVar2 = CeAllocDuplicateBuffer(&local_38,param_2,0,5), -1 < iVar2)) &&
     ((param_4 == 0 || (iVar2 = CeAllocDuplicateBuffer(&local_34,param_4,0,5), -1 < iVar2)))) {
    iVar2 = FUN_c010af9c(param_1,local_38,param_3,local_34,param_5,param_6,puVar3,param_8,param_9,
                         uVar1);
    CeFreeDuplicateBuffer(local_38,param_2,0,5);
    CeFreeDuplicateBuffer(local_34,param_4,0,5);
  }
  else {
    CeFreeDuplicateBuffer(local_38,param_2,0,5);
    iVar2 = 0xe;
  }
  return iVar2;
}



/* c010b4b4 FUN_c010b4b4 */

/* Boundary evidence: original MIPS .pdata c010b4b4..c010b6b7. Semantic name remains unreviewed. */

int FUN_c010b4b4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 local_res4 [3];
  byte local_68 [4];
  uint local_64;
  int local_60;
  uint auStack_58 [16];
  
  iVar2 = 0x57;
  local_60 = 0x57;
  if (DAT_c0136ca8 < 1) {
    iVar2 = 0x426;
  }
  else {
    local_res4[0] = param_2;
    iVar1 = FUN_c0106be8((uint)param_1);
    if (iVar1 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      iVar1 = local_60;
      if ((param_1 != (undefined4 *)0x0) &&
         ((((param_1 >= (undefined4 *)0x80000000 && (param_1 < (undefined4 *)0x80000004)) ||
           (((undefined4 *)*param_1 == param_1 && (*(char *)(param_1 + 2) == -0xb)))) &&
          (local_68[0] = 0, param_5 != (undefined4 *)0x0)))) {
        if ((param_1 < (undefined4 *)0x80000000) || ((undefined4 *)0x80000003 < param_1)) {
          local_64 = 2;
          if ((param_1[4] & 1) == 0) {
            local_64 = 0;
          }
        }
        else {
          local_64 = (1 << ((uint)(param_1 + -0x20000000) & 0x1f)) << 0x10 | 1;
        }
        iVar2 = FUN_c010a134(1,(uint)param_1,auStack_58,local_68,local_res4,&local_64);
        iVar1 = iVar2;
        if (iVar2 == 0) {
          iVar2 = FUN_c01070c8(1,auStack_58,(uint)local_68[0],local_64,param_5,param_1,param_6);
          iVar1 = iVar2;
        }
      }
      local_60 = iVar1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    }
  }
  return iVar2;
}



/* c010b6b8 FUN_c010b6b8 */

/* Boundary evidence: original MIPS .pdata c010b6b8..c010b6c3. Semantic name remains unreviewed. */

undefined4 FUN_c010b6b8(void)

{
  return 1;
}



/* c010b6c4 FUN_c010b6c4 */

/* Boundary evidence: original MIPS .pdata c010b6c4..c010b6cf. Semantic name remains unreviewed. */

undefined4 FUN_c010b6c4(void)

{
  return 1;
}



/* c010b6d0 FUN_c010b6d0 */

/* Boundary evidence: original MIPS .pdata c010b6d0..c010b73b. Semantic name remains unreviewed. */

void FUN_c010b6d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  undefined4 uVar1;
  
  uVar1 = __GetUserKData(0xc);
  FUN_c010b4b4(param_1,param_2,param_3,param_4,param_5,uVar1);
  return;
}



/* c010b73c FUN_c010b73c */

/* Boundary evidence: original MIPS .pdata c010b73c..c010b7f7. Semantic name remains unreviewed. */

int FUN_c010b73c(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  uVar1 = GetCallerVMProcessId();
  if ((param_2 == 0) || (iVar2 = CeAllocDuplicateBuffer(local_20,param_2,0,5), -1 < iVar2)) {
    iVar2 = FUN_c010b4b4(param_1,local_20[0],param_3,param_4,param_5,uVar1);
    CeFreeDuplicateBuffer(local_20[0],param_2,0,5);
  }
  else {
    iVar2 = 0xe;
  }
  return iVar2;
}



/* c010b7f8 FUN_c010b7f8 */

/* Boundary evidence: original MIPS .pdata c010b7f8..c010ba93. Semantic name remains unreviewed. */

int FUN_c010b7f8(uint *param_1,wchar_t *param_2,uint param_3,wchar_t *param_4,uint param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  byte bVar6;
  undefined4 uVar7;
  uint uVar8;
  byte local_70 [4];
  uint local_6c;
  uint *local_68;
  uint auStack_64 [15];
  
  bVar2 = false;
  if (param_1 == (uint *)0x0) {
    return 0x57;
  }
  if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
    if ((uint *)*param_1 != param_1) {
      return 0x57;
    }
    if ((char)param_1[2] != -0xb) {
      return 0x57;
    }
  }
  bVar1 = false;
  local_6c = param_3;
  if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
    uVar7 = 2;
    if ((param_1[4] & 1) == 0) {
      uVar7 = 0;
    }
    uVar8 = (uint)*(byte *)((int)param_1 + 9);
    if (0xe < uVar8) {
      uVar8 = 0xf;
    }
    local_70[0] = (byte)uVar8;
    memcpy(&local_68,param_1 + 6,(uVar8 + 1) * 4);
  }
  else {
    uVar7 = 0;
    local_70[0] = 0;
    local_68 = param_1;
  }
  iVar3 = FUN_c010a53c(1,(int *)&local_68,local_70,(wchar_t *)0x0,(wchar_t *)0x0,(undefined4 *)0x0,
                       uVar7,0);
  uVar8 = (uint)local_70[0];
  if (iVar3 != 0) {
    return iVar3;
  }
  bVar6 = 8;
  if (uVar8 == 0) {
    if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
    }
    if (uVar5 != 0) {
      puVar4 = (uint *)((int)(param_1 + 1) * 4 + uVar5);
      goto LAB_c010b9b4;
    }
  }
  else {
    uVar5 = auStack_64[uVar8 - 1];
    iVar3 = FUN_c0106a7c(uVar5);
    if (iVar3 == 0) {
      uVar5 = FUN_c0101c94(-0x3fec6e20,uVar5);
    }
    bVar1 = (*(byte *)(uVar5 + 0xe) & 8) == 8;
    puVar4 = (uint *)(uVar5 + 8);
LAB_c010b9b4:
    if (puVar4 != (uint *)0x0) {
      if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
        param_2 = L"Default";
      }
      if (!bVar1) {
        bVar6 = 0;
      }
      iVar3 = FUN_c0107cb8(1,puVar4,param_2,local_6c,param_4,param_5,uVar7,bVar6);
      if (iVar3 == 0x7de) {
        bVar2 = true;
        iVar3 = 0;
      }
      goto LAB_c010ba28;
    }
  }
  iVar3 = 2;
LAB_c010ba28:
  if ((iVar3 == 0) && (!bVar2)) {
    FUN_c01081a4(1,(uint *)&local_68,uVar8,(wchar_t *)0x0,&local_6c);
    FUN_c01084bc(local_6c,param_2,3);
  }
  return iVar3;
}



/* c010ba94 FUN_c010ba94 */

/* Boundary evidence: original MIPS .pdata c010ba94..c010bbbb. Semantic name remains unreviewed. */

int FUN_c010ba94(uint *param_1,wchar_t *param_2,undefined4 param_3,uint param_4,wchar_t *param_5,
                uint param_6)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x57;
  if (DAT_c0136ca8 < 1) {
    iVar2 = 0x426;
  }
  else {
    iVar1 = FUN_c0106be8((uint)param_1);
    if (iVar1 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      iVar2 = FUN_c010b7f8(param_1,param_2,param_4,param_5,param_6);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    }
  }
  return iVar2;
}



/* c010bbbc FUN_c010bbbc */

/* Boundary evidence: original MIPS .pdata c010bbbc..c010bbc7. Semantic name remains unreviewed. */

undefined4 FUN_c010bbbc(void)

{
  return 1;
}



/* c010bbc8 FUN_c010bbc8 */

/* Boundary evidence: original MIPS .pdata c010bbc8..c010bbd3. Semantic name remains unreviewed. */

undefined4 FUN_c010bbc8(void)

{
  return 1;
}



/* c010bbd4 FUN_c010bbd4 */

/* Boundary evidence: original MIPS .pdata c010bbd4..c010bc87. Semantic name remains unreviewed. */

int FUN_c010bbd4(uint *param_1,int param_2,undefined4 param_3,uint param_4,wchar_t *param_5,
                uint param_6)

{
  int iVar1;
  wchar_t *local_20 [2];
  
  local_20[0] = (wchar_t *)0x0;
  if ((param_2 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_20,param_2,0,5), -1 < iVar1)) {
    iVar1 = FUN_c010ba94(param_1,local_20[0],param_3,param_4,param_5,param_6);
    CeFreeDuplicateBuffer(local_20[0],param_2,0,5);
  }
  else {
    iVar1 = 0xe;
  }
  return iVar1;
}



/* c010bc88 FUN_c010bc88 */

/* Boundary evidence: original MIPS .pdata c010bc88..c010c08f. Semantic name remains unreviewed. */

int FUN_c010bc88(uint *param_1,wchar_t *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  byte local_80 [4];
  LPCRITICAL_SECTION local_7c;
  int local_78;
  LPVOID local_74;
  int local_70;
  int local_6c;
  uint *local_68;
  uint auStack_64 [15];
  
  iVar3 = 0x57;
  local_70 = 0x57;
  if (DAT_c0136ca8 < 1) {
    iVar3 = 0x426;
  }
  else {
    iVar2 = FUN_c0106be8((uint)param_1);
    if (iVar2 != 0) {
      local_7c = (LPCRITICAL_SECTION)&DAT_c013a740;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c013a740;
      iVar2 = local_70;
      if ((param_1 != (uint *)0x0) &&
         (((param_1 >= (uint *)0x80000000 && (param_1 < (uint *)0x80000004)) ||
          (((uint *)*param_1 == param_1 && ((char)param_1[2] == -0xb)))))) {
        local_74 = (LPVOID)0x0;
        puVar5 = (uint *)0x0;
        local_6c = 0;
        bVar1 = false;
        if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
          uVar6 = 2;
          if ((param_1[4] & 1) == 0) {
            uVar6 = 0;
          }
          uVar7 = (uint)*(byte *)((int)param_1 + 9);
          if (0xe < uVar7) {
            uVar7 = 0xf;
          }
          local_80[0] = (byte)uVar7;
          memcpy(&local_68,param_1 + 6,(uVar7 + 1) * 4);
        }
        else {
          uVar6 = 0;
          local_80[0] = 0;
          local_68 = param_1;
        }
        iVar3 = FUN_c010a53c(1,(int *)&local_68,local_80,(wchar_t *)0x0,(wchar_t *)0x0,
                             (undefined4 *)0x0,uVar6,0);
        local_78 = iVar3;
        iVar2 = iVar3;
        if (iVar3 == 0) {
          uVar7 = (uint)local_80[0];
          if (uVar7 == 0) {
            if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
              uVar4 = 0;
            }
            else {
              uVar4 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
            }
            if (uVar4 != 0) {
              puVar5 = (uint *)((int)(param_1 + 1) * 4 + uVar4);
            }
          }
          else {
            uVar4 = auStack_64[uVar7 - 1];
            iVar3 = FUN_c0106a7c(uVar4);
            if (iVar3 == 0) {
              uVar4 = FUN_c0101c94(-0x3fec6e20,uVar4);
            }
            bVar1 = (*(byte *)(uVar4 + 0xe) & 8) == 8;
            puVar5 = (uint *)(uVar4 + 8);
          }
          if (puVar5 == (uint *)0x0) {
            iVar3 = 2;
            local_78 = 2;
            lpCriticalSection = local_7c;
            iVar2 = iVar3;
          }
          else {
            if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
              param_2 = L"Default";
            }
            if (!bVar1) {
              FUN_c010297c(-0x3fec6e20);
            }
            iVar3 = FUN_c0107b04(1,puVar5,param_2,uVar6,(uint *)&local_74);
            local_78 = iVar3;
            if (local_74 != (LPVOID)0x0) {
              if (bVar1) {
                if (DAT_c0136cf4 != (HANDLE)0x0) {
                  HeapFree(DAT_c0136cf4,0,local_74);
                }
              }
              else {
                FUN_c01037f0(&DAT_c01391e0,(uint)local_74);
              }
            }
            if (!bVar1) {
              FUN_c0102aa4(&DAT_c01391e0);
            }
            lpCriticalSection = local_7c;
            iVar2 = iVar3;
            if (iVar3 == 0) {
              FUN_c01081a4(1,(uint *)&local_68,uVar7,(wchar_t *)0x0,&local_6c);
              FUN_c01084bc(local_6c,param_2,2);
              lpCriticalSection = local_7c;
            }
          }
        }
      }
      local_70 = iVar2;
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar3;
}



/* c010c090 FUN_c010c090 */

/* Boundary evidence: original MIPS .pdata c010c090..c010c09b. Semantic name remains unreviewed. */

undefined4 FUN_c010c090(void)

{
  return 1;
}



/* c010c09c FUN_c010c09c */

/* Boundary evidence: original MIPS .pdata c010c09c..c010c0a7. Semantic name remains unreviewed. */

undefined4 FUN_c010c09c(void)

{
  return 1;
}



/* c010c0a8 FUN_c010c0a8 */

/* Boundary evidence: original MIPS .pdata c010c0a8..c010c12b. Semantic name remains unreviewed. */

int FUN_c010c0a8(uint *param_1,int param_2)

{
  int iVar1;
  wchar_t *local_18 [2];
  
  local_18[0] = (wchar_t *)0x0;
  if ((param_2 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_18,param_2,0,5), -1 < iVar1)) {
    iVar1 = FUN_c010bc88(param_1,local_18[0]);
    CeFreeDuplicateBuffer(local_18[0],param_2,0,5);
  }
  else {
    iVar1 = 0xe;
  }
  return iVar1;
}



/* c010c12c FUN_c010c12c */

/* Boundary evidence: original MIPS .pdata c010c12c..c010c51f. Semantic name remains unreviewed. */

int FUN_c010c12c(uint *param_1,short *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  byte local_288 [4];
  int local_284;
  short *local_280;
  uint local_27c [17];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  iVar4 = 0x57;
  local_284 = 0x57;
  local_280 = param_2;
  if (DAT_c0136ca8 < 1) {
    FUN_c013331c(DAT_c0136c78);
    iVar5 = 0x426;
  }
  else {
    iVar1 = FUN_c0106be8((uint)param_1);
    iVar5 = iVar4;
    if (iVar1 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      iVar1 = local_284;
      if ((param_1 != (uint *)0x0) &&
         (((param_1 >= (uint *)0x80000000 && (param_1 < (uint *)0x80000004)) ||
          (((uint *)*param_1 == param_1 && ((char)param_1[2] == -0xb)))))) {
        local_288[0] = 0;
        piVar7 = (int *)0x0;
        if ((param_2 != (short *)0x0) && (*param_2 != 0)) {
          if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
            local_27c[0] = 2;
            if ((param_1[4] & 1) == 0) {
              local_27c[0] = 0;
            }
          }
          else {
            local_27c[0] = (1 << ((uint)(param_1 + -0x20000000) & 0x1f)) << 0x10 | 1;
          }
          iVar5 = FUN_c010a134(1,(uint)param_1,local_27c + 1,local_288,&local_280,local_27c);
          iVar1 = iVar5;
          if (iVar5 == 0) {
            uVar3 = (uint)local_288[0];
            if (uVar3 == 0) {
              iVar5 = 5;
              iVar1 = iVar5;
            }
            else {
              piVar8 = (int *)local_27c[uVar3 + 1];
              iVar5 = FUN_c0106a7c((uint)piVar8);
              piVar2 = piVar8;
              if (iVar5 == 0) {
                piVar2 = (int *)FUN_c0101c94(-0x3fec6e20,(uint)piVar8);
              }
              if (piVar2 != (int *)0x0) {
                wcscpy(awStack_238,L"");
                wcsncat(awStack_238,(wchar_t *)(piVar2 + 4),(uint)*(byte *)(piVar2 + 3));
              }
              if (uVar3 < 2) {
                if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
                  uVar6 = 0;
                }
                else {
                  uVar6 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
                }
                if (uVar6 != 0) {
                  piVar7 = (int *)(local_27c[1] * 4 + uVar6);
                }
              }
              else {
                uVar6 = local_27c[uVar3];
                iVar5 = FUN_c0106a7c(uVar6);
                if (iVar5 == 0) {
                  uVar6 = FUN_c0101c94(-0x3fec6e20,uVar6);
                }
                if (uVar6 != 0) {
                  piVar7 = (int *)(uVar6 + 4);
                }
              }
              iVar5 = iVar4;
              iVar1 = local_284;
              if (((piVar7 != (int *)0x0) &&
                  (iVar5 = FUN_c01076ec(1,piVar7,piVar8), iVar1 = iVar5, iVar5 == 0)) &&
                 (local_284 = iVar5,
                 FUN_c01081a4(1,local_27c + 1,uVar3 + 0xff & 0xff,awStack_238,&local_280),
                 iVar1 = local_284, 1 < DAT_c0136ca8)) {
                FUN_c0132470((int)local_280,(wchar_t *)&DAT_c0137180,1,2);
                iVar1 = local_284;
              }
            }
          }
        }
      }
      local_284 = iVar1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
    }
    FUN_c013331c(local_30);
  }
  return iVar5;
}



/* c010c520 FUN_c010c520 */

/* Boundary evidence: original MIPS .pdata c010c520..c010c52b. Semantic name remains unreviewed. */

undefined4 FUN_c010c520(void)

{
  return 1;
}



/* c010c52c FUN_c010c52c */

/* Boundary evidence: original MIPS .pdata c010c52c..c010c537. Semantic name remains unreviewed. */

undefined4 FUN_c010c52c(void)

{
  return 1;
}



/* c010c538 FUN_c010c538 */

/* Boundary evidence: original MIPS .pdata c010c538..c010c5bb. Semantic name remains unreviewed. */

int FUN_c010c538(uint *param_1,int param_2)

{
  int iVar1;
  short *local_18 [2];
  
  local_18[0] = (short *)0x0;
  if ((param_2 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_18,param_2,0,5), -1 < iVar1)) {
    iVar1 = FUN_c010c12c(param_1,local_18[0]);
    CeFreeDuplicateBuffer(local_18[0],param_2,0,5);
  }
  else {
    iVar1 = 0xe;
  }
  return iVar1;
}



/* c010c5bc FUN_c010c5bc */

/* Boundary evidence: original MIPS .pdata c010c5bc..c010cac3. Semantic name remains unreviewed. */

int FUN_c010c5bc(uint *param_1,int param_2,wchar_t *param_3,uint param_4,uint *param_5,
                undefined4 param_6,uint *param_7,undefined2 *param_8,uint param_9,uint *param_10)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint local_4c;
  uint local_48;
  
  iVar5 = 0x57;
  local_48 = 0;
  uVar9 = 0;
  local_4c = 0;
  uVar8 = 0;
  uVar6 = param_4 >> 1;
  if (DAT_c0136ca8 < 1) {
    iVar5 = 0x426;
  }
  else {
    iVar2 = FUN_c0106be8((uint)param_1);
    if (iVar2 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      if (((param_1 != (uint *)0x0) &&
          ((((param_1 >= (uint *)0x80000000 && (param_1 < (uint *)0x80000004)) ||
            (((uint *)*param_1 == param_1 && ((char)param_1[2] == -0xb)))) &&
           (((param_3 != (wchar_t *)0x0 && (param_5 != (uint *)0x0)) && (uVar6 != 0)))))) &&
         ((param_10 != (uint *)0x0 || (param_8 == (undefined2 *)0x0)))) {
        if (param_7 != (uint *)0x0) {
          local_48 = *param_7;
        }
        puVar7 = (uint *)0x0;
        if ((param_1 < (uint *)0x80000000) || ((uint *)0x80000003 < param_1)) {
          uVar8 = param_1[*(byte *)((int)param_1 + 9) + 6];
          iVar2 = FUN_c0106a7c(uVar8);
          if (iVar2 == 0) {
            uVar8 = FUN_c0101c94(-0x3fec6e20,uVar8);
          }
          if (uVar8 != 0) {
            puVar7 = *(uint **)(uVar8 + 8);
          }
        }
        else {
          if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
            uVar8 = 0;
          }
          else {
            uVar8 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
          }
          if (uVar8 != 0) {
            puVar7 = *(uint **)((int)(param_1 + 1) * 4 + uVar8);
          }
        }
        iVar2 = param_2 + 1;
        if (iVar2 == 0) {
          puVar7 = (uint *)0x0;
        }
        while (uVar8 = param_9, uVar9 = local_4c, puVar7 != (uint *)0x0) {
          if (iVar2 == 0) {
LAB_c010c868:
            if (puVar7 != (uint *)0x0) {
              iVar2 = FUN_c0106a7c((uint)puVar7);
              if (iVar2 == 0) {
                puVar7 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar7);
              }
              if (puVar7 != (uint *)0x0) {
                uVar9 = (uint)*(byte *)((int)puVar7 + 8);
                if (uVar6 <= uVar9) {
                  uVar9 = uVar6 - 1;
                }
                memcpy(param_3,(void *)((int)puVar7 + 10),uVar9 * 2);
                param_3[uVar9] = L'\0';
                *param_5 = uVar9;
                uVar1 = *(ushort *)((int)puVar7 + 4);
                if (param_7 != (uint *)0x0) {
                  *param_7 = (uint)uVar1;
                }
                if (param_8 == (undefined2 *)0x0) {
                  if (param_10 != (uint *)0x0) {
                    *param_10 = (uint)*(ushort *)((int)puVar7 + 6);
                  }
                }
                else {
                  uVar9 = param_9;
                  if (*(ushort *)((int)puVar7 + 6) < param_9) {
                    uVar9 = (uint)*(ushort *)((int)puVar7 + 6);
                  }
                  memcpy(param_8,(void *)((*(byte *)((int)puVar7 + 8) + 5) * 2 + (int)puVar7),uVar9)
                  ;
                  *param_10 = uVar9;
                }
                iVar5 = 0;
                uVar9 = (uint)uVar1;
              }
              goto LAB_c010c9a0;
            }
            break;
          }
          iVar3 = FUN_c0106a7c((uint)puVar7);
          puVar4 = puVar7;
          if (iVar3 == 0) {
            puVar4 = (uint *)FUN_c0101c94(-0x3fec6e20,(uint)puVar7);
          }
          if (puVar4 == (uint *)0x0) goto LAB_c010c868;
          iVar2 = iVar2 + -1;
          if (iVar2 != 0) {
            puVar7 = (uint *)*puVar4;
          }
        }
        iVar5 = 0x103;
      }
LAB_c010c9a0:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      if (((((iVar5 == 0) || (iVar5 == 0xea)) && (uVar9 == 0x15)) && (local_48 != 0x15)) &&
         (((param_8 != (undefined2 *)0x0 || (param_10 != (uint *)0x0)) || (param_7 != (uint *)0x0)))
         ) {
        iVar5 = FUN_c010abd8(param_1,(short *)0x0,param_3,param_8,param_10,uVar8,local_48,param_7);
      }
    }
  }
  return iVar5;
}



/* c010cac4 FUN_c010cac4 */

/* Boundary evidence: original MIPS .pdata c010cac4..c010cacf. Semantic name remains unreviewed. */

undefined4 FUN_c010cac4(void)

{
  return 1;
}



/* c010cad0 FUN_c010cad0 */

/* Boundary evidence: original MIPS .pdata c010cad0..c010cadb. Semantic name remains unreviewed. */

undefined4 FUN_c010cad0(void)

{
  return 1;
}



/* c010cadc FUN_c010cadc */

/* Boundary evidence: original MIPS .pdata c010cadc..c010cbdf. Semantic name remains unreviewed. */

int FUN_c010cadc(uint *param_1,int param_2,wchar_t *param_3,uint param_4,uint *param_5,
                undefined4 param_6,int param_7,undefined2 *param_8,uint param_9,uint *param_10)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint local_28 [2];
  
  local_28[0] = 0;
  if (param_7 == 0) {
    puVar3 = (uint *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(local_28,param_7,4);
    if (iVar1 == 0) {
      return 0x57;
    }
    puVar3 = local_28;
  }
  iVar1 = FUN_c010c5bc(param_1,param_2,param_3,param_4,param_5,param_6,puVar3,param_8,param_9,
                       param_10);
  if ((iVar1 != 0) && (iVar1 != 0xea)) {
    return iVar1;
  }
  if (param_7 == 0) {
    return iVar1;
  }
  iVar2 = CeSafeCopyMemory(param_7,puVar3,4);
  if (iVar2 == 0) {
    return 0x57;
  }
  return iVar1;
}



/* c010cbe0 FUN_c010cbe0 */

/* Boundary evidence: original MIPS .pdata c010cbe0..c010cf2b. Semantic name remains unreviewed. */

int FUN_c010cbe0(uint *param_1,wchar_t *param_2,short *param_3,uint *param_4,undefined2 *param_5,
                uint param_6,uint *param_7)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_48;
  int local_44;
  uint local_40;
  wchar_t *local_3c;
  uint local_38;
  short *local_34;
  uint *local_30;
  
  iVar3 = 0x57;
  local_44 = 0x57;
  uVar5 = 0;
  local_38 = 0;
  local_40 = 0;
  local_48 = 0;
  if (DAT_c0136ca8 < 1) {
    iVar3 = 0x426;
  }
  else {
    local_3c = param_2;
    local_34 = param_3;
    local_30 = param_1;
    iVar1 = FUN_c0106be8((uint)param_1);
    if (iVar1 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      if (param_4 != (uint *)0x0) {
        uVar5 = *param_4;
        local_38 = uVar5;
      }
      local_48 = param_6;
      iVar3 = FUN_c010a8c4(param_1,local_3c,param_3,&local_40,param_5,&local_48);
      uVar4 = local_40;
      if (param_4 != (uint *)0x0) {
        *param_4 = local_40;
      }
      if (param_7 != (uint *)0x0) {
        *param_7 = local_48;
      }
      local_44 = iVar3;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      if ((((iVar3 == 0) || (iVar3 == 0xea)) && (uVar4 == 0x15)) && (uVar5 != 0x15)) {
        puVar2 = &local_48;
        if (param_7 == (uint *)0x0) {
          puVar2 = (uint *)0x0;
        }
        iVar3 = FUN_c010abd8(local_30,local_34,local_3c,param_5,puVar2,param_6,uVar5,param_4);
        if (param_7 != (uint *)0x0) {
          *param_7 = local_48;
        }
        uVar4 = 1;
      }
      if (((iVar3 == 0) && (param_5 != (undefined2 *)0x0)) &&
         ((param_7 != (uint *)0x0 && (local_48 = local_48 >> 1, uVar4 != 0)))) {
        if (uVar4 < 3) {
          if (1 < param_6) {
            if (local_48 == 0) {
              local_48 = 1;
              *param_7 = 2;
            }
            param_5[local_48 - 1] = 0;
            return 0;
          }
          uVar5 = 2;
        }
        else {
          if (uVar4 != 7) {
            return 0;
          }
          if (3 < param_6) {
            if (local_48 < 2) {
              local_48 = 2;
              *param_7 = 4;
            }
            param_5[local_48 - 2] = 0;
            param_5[local_48 - 1] = 0;
            return 0;
          }
          uVar5 = 4;
        }
        iVar3 = 0xea;
        *param_7 = uVar5;
      }
    }
  }
  return iVar3;
}



/* c010cf2c FUN_c010cf2c */

/* Boundary evidence: original MIPS .pdata c010cf2c..c010cf37. Semantic name remains unreviewed. */

undefined4 FUN_c010cf2c(void)

{
  return 1;
}



/* c010cf38 FUN_c010cf38 */

/* Boundary evidence: original MIPS .pdata c010cf38..c010cf43. Semantic name remains unreviewed. */

undefined4 FUN_c010cf38(void)

{
  return 1;
}



/* c010cf44 FUN_c010cf44 */

/* Boundary evidence: original MIPS .pdata c010cf44..c010cf4f. Semantic name remains unreviewed. */

undefined4 FUN_c010cf44(void)

{
  return 1;
}



/* c010cf50 FUN_c010cf50 */

/* Boundary evidence: original MIPS .pdata c010cf50..c010d0cf. Semantic name remains unreviewed. */

int FUN_c010cf50(uint *param_1,int param_2,int param_3,int param_4,undefined2 *param_5,uint param_6,
                uint *param_7)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  wchar_t *local_28;
  short *local_24;
  uint local_20 [2];
  
  local_20[0] = 0;
  local_28 = (wchar_t *)0x0;
  local_24 = (short *)0x0;
  if (param_4 == 0) {
    puVar3 = (uint *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(local_20,param_4,4);
    if (iVar1 == 0) {
      return 0x57;
    }
    puVar3 = local_20;
  }
  if (((param_2 == 0) || (iVar1 = CeAllocDuplicateBuffer(&local_28,param_2,0,5), -1 < iVar1)) &&
     ((param_3 == 0 || (iVar1 = CeAllocDuplicateBuffer(&local_24,param_3,0,5), -1 < iVar1)))) {
    iVar1 = FUN_c010cbe0(param_1,local_28,local_24,puVar3,param_5,param_6,param_7);
    if ((((iVar1 == 0) || (iVar1 == 0xea)) && (param_4 != 0)) &&
       (iVar2 = CeSafeCopyMemory(param_4,puVar3,4), iVar2 == 0)) {
      iVar1 = 0x57;
    }
    CeFreeDuplicateBuffer(local_28,param_2,0,5);
    CeFreeDuplicateBuffer(local_24,param_3,0,5);
  }
  else {
    CeFreeDuplicateBuffer(local_28,param_2,0,5);
    iVar1 = 0xe;
  }
  return iVar1;
}



/* c010d0d0 FUN_c010d0d0 */

/* Boundary evidence: original MIPS .pdata c010d0d0..c010d3ff. Semantic name remains unreviewed. */

int FUN_c010d0d0(uint *param_1,wchar_t *param_2,uint param_3,void *param_4,uint param_5,
                wchar_t *param_6,uint param_7,uint param_8)

{
  int iVar1;
  int iVar2;
  HLOCAL _Buf1;
  wchar_t *pwVar3;
  SIZE_T local_40;
  wchar_t *local_3c;
  uint local_38;
  uint local_34;
  uint *local_30;
  HLOCAL local_2c;
  
  _Buf1 = (HLOCAL)0x0;
  local_2c = (HLOCAL)0x0;
  if (DAT_c0136ca8 < 1) {
    return 0x426;
  }
  local_3c = param_2;
  local_34 = param_3;
  local_30 = param_1;
  iVar1 = FUN_c0106be8((uint)param_1);
  if (iVar1 == 0) {
    return 0x57;
  }
  if (param_5 == 0) {
    param_4 = (void *)0x0;
  }
  pwVar3 = (wchar_t *)0x0;
  if (param_7 != 0) {
    pwVar3 = param_6;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((((param_4 == (void *)0x0) || (pwVar3 == (wchar_t *)0x0)) || (0x1000 < param_5)) ||
     (0x1000 < param_7)) {
    iVar1 = 0x57;
    goto LAB_c010d358;
  }
  iVar1 = FUN_c010a8c4(param_1,local_3c,(short *)0x0,&local_38,(void *)0x0,&local_40);
  if ((iVar1 != 2) || ((param_8 & 1) == 0)) {
    if (iVar1 != 0) goto LAB_c010d358;
    if (local_38 != local_34) {
      if (local_38 != local_34) {
        iVar1 = 0x65d;
      }
      goto LAB_c010d358;
    }
  }
  if (iVar1 == 0) {
    _Buf1 = LocalAlloc(0,local_40);
    local_2c = _Buf1;
    iVar1 = FUN_c010a8c4(local_30,local_3c,(short *)0x0,&local_38,_Buf1,&local_40);
    if (iVar1 == 0) {
      iVar1 = 0;
      if ((param_5 == local_40) && (iVar2 = memcmp(_Buf1,param_4,param_5), iVar2 == 0)) {
        if ((param_8 & 2) != 0) {
          iVar1 = 0xb7;
        }
      }
      else if ((param_8 & 2) == 0) {
        iVar1 = 0x491;
      }
    }
    else {
      iVar1 = 0x57;
    }
    if (iVar1 != 0) goto LAB_c010d2e8;
  }
  else {
LAB_c010d2e8:
    if (iVar1 != 2) goto LAB_c010d358;
  }
  iVar1 = FUN_c010b7f8(local_30,local_3c,local_34,pwVar3,param_7);
LAB_c010d358:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if (_Buf1 != (HLOCAL)0x0) {
    LocalFree(_Buf1);
  }
  return iVar1;
}



/* c010d400 FUN_c010d400 */

/* Boundary evidence: original MIPS .pdata c010d400..c010d40b. Semantic name remains unreviewed. */

undefined4 FUN_c010d400(void)

{
  return 1;
}



/* c010d40c FUN_c010d40c */

/* Boundary evidence: original MIPS .pdata c010d40c..c010d417. Semantic name remains unreviewed. */

undefined4 FUN_c010d40c(void)

{
  return 1;
}



/* c010d418 FUN_c010d418 */

/* Boundary evidence: original MIPS .pdata c010d418..c010d4db. Semantic name remains unreviewed. */

int FUN_c010d418(uint *param_1,int param_2,uint param_3,void *param_4,uint param_5,wchar_t *param_6,
                uint param_7,uint param_8)

{
  int iVar1;
  wchar_t *local_20 [2];
  
  local_20[0] = (wchar_t *)0x0;
  if ((param_2 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_20,param_2,0,5), -1 < iVar1)) {
    iVar1 = FUN_c010d0d0(param_1,local_20[0],param_3,param_4,param_5,param_6,param_7,param_8);
    CeFreeDuplicateBuffer(local_20[0],param_2,0,5);
  }
  else {
    iVar1 = 0xe;
  }
  return iVar1;
}



/* c010d4dc FUN_c010d4dc */

/* Boundary evidence: original MIPS .pdata c010d4dc..c010d503. Semantic name remains unreviewed. */

undefined4 FUN_c010d4dc(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d504 FUN_c010d504 */

/* Boundary evidence: original MIPS .pdata c010d504..c010d52b. Semantic name remains unreviewed. */

undefined4 FUN_c010d504(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d52c FUN_c010d52c */

/* Boundary evidence: original MIPS .pdata c010d52c..c010d553. Semantic name remains unreviewed. */

undefined4 FUN_c010d52c(void)

{
  SetLastError(0x32);
  return 0xffffffff;
}



/* c010d554 FUN_c010d554 */

/* Boundary evidence: original MIPS .pdata c010d554..c010d57b. Semantic name remains unreviewed. */

undefined4 FUN_c010d554(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d57c FUN_c010d57c */

/* Boundary evidence: original MIPS .pdata c010d57c..c010d5a3. Semantic name remains unreviewed. */

undefined4 FUN_c010d57c(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d5a4 FUN_c010d5a4 */

/* Boundary evidence: original MIPS .pdata c010d5a4..c010d5cb. Semantic name remains unreviewed. */

undefined4 FUN_c010d5a4(void)

{
  SetLastError(0x32);
  return 0xffffffff;
}



/* c010d5cc FUN_c010d5cc */

/* Boundary evidence: original MIPS .pdata c010d5cc..c010d5f3. Semantic name remains unreviewed. */

undefined4 FUN_c010d5cc(void)

{
  SetLastError(0x32);
  return 0xffffffff;
}



/* c010d5f4 FUN_c010d5f4 */

/* Boundary evidence: original MIPS .pdata c010d5f4..c010d61b. Semantic name remains unreviewed. */

undefined4 FUN_c010d5f4(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d61c FUN_c010d61c */

/* Boundary evidence: original MIPS .pdata c010d61c..c010d643. Semantic name remains unreviewed. */

undefined4 FUN_c010d61c(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d644 FUN_c010d644 */

/* Boundary evidence: original MIPS .pdata c010d644..c010d66b. Semantic name remains unreviewed. */

undefined4 FUN_c010d644(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d66c FUN_c010d66c */

/* Boundary evidence: original MIPS .pdata c010d66c..c010d693. Semantic name remains unreviewed. */

undefined4 FUN_c010d66c(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d694 FUN_c010d694 */

/* Boundary evidence: original MIPS .pdata c010d694..c010d6bb. Semantic name remains unreviewed. */

undefined4 FUN_c010d694(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d6bc FUN_c010d6bc */

/* Boundary evidence: original MIPS .pdata c010d6bc..c010d6e3. Semantic name remains unreviewed. */

undefined4 FUN_c010d6bc(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d6e4 FUN_c010d6e4 */

/* Boundary evidence: original MIPS .pdata c010d6e4..c010d70b. Semantic name remains unreviewed. */

undefined4 FUN_c010d6e4(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d70c FUN_c010d70c */

/* Boundary evidence: original MIPS .pdata c010d70c..c010d733. Semantic name remains unreviewed. */

undefined4 FUN_c010d70c(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d734 FUN_c010d734 */

/* Boundary evidence: original MIPS .pdata c010d734..c010d75b. Semantic name remains unreviewed. */

undefined4 FUN_c010d734(void)

{
  SetLastError(0x32);
  return 0xffffffff;
}



/* c010d75c FUN_c010d75c */

/* Boundary evidence: original MIPS .pdata c010d75c..c010d783. Semantic name remains unreviewed. */

undefined4 FUN_c010d75c(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d784 FUN_c010d784 */

/* Boundary evidence: original MIPS .pdata c010d784..c010d7ab. Semantic name remains unreviewed. */

undefined4 FUN_c010d784(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d7ac FUN_c010d7ac */

/* Boundary evidence: original MIPS .pdata c010d7ac..c010d7d3. Semantic name remains unreviewed. */

undefined4 FUN_c010d7ac(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d7d4 FUN_c010d7d4 */

/* Boundary evidence: original MIPS .pdata c010d7d4..c010d7fb. Semantic name remains unreviewed. */

undefined4 FUN_c010d7d4(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d7fc FUN_c010d7fc */

/* Boundary evidence: original MIPS .pdata c010d7fc..c010d823. Semantic name remains unreviewed. */

undefined4 FUN_c010d7fc(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d824 FUN_c010d824 */

/* Boundary evidence: original MIPS .pdata c010d824..c010d84b. Semantic name remains unreviewed. */

undefined4 FUN_c010d824(void)

{
  SetLastError(0x32);
  return 0;
}



/* c010d84c FUN_c010d84c */

/* Boundary evidence: original MIPS .pdata c010d84c..c010d9b7. Semantic name remains unreviewed. */

int FUN_c010d84c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint *_Buf1;
  uint auStack_28 [4];
  
  if (param_1 != 0) {
    iVar1 = CeSafeCopyMemory(auStack_28,param_1,0x10,param_4,0xffffffff);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return -1;
    }
    _Buf1 = auStack_28;
    if (param_1 != 0) goto LAB_c010d8c8;
  }
  _Buf1 = (uint *)0x0;
LAB_c010d8c8:
  if (((_Buf1 == (uint *)0x0) || (iVar1 = memcmp(_Buf1,&DAT_c00f2b58,0x10), iVar1 == 0)) ||
     ((char)*_Buf1 != -1)) {
    iVar1 = FUN_c011ef14(_Buf1,param_2);
  }
  else {
    iVar1 = memcmp(_Buf1,&DAT_c00f2b48,0x10);
    if (iVar1 == 0) {
      memset(_Buf1,-1,0x10);
    }
    iVar1 = FUN_c01192b8();
  }
  return iVar1;
}



/* c010d9b8 FUN_c010d9b8 */

/* Boundary evidence: original MIPS .pdata c010d9b8..c010d9c3. Semantic name remains unreviewed. */

undefined4 FUN_c010d9b8(void)

{
  return 1;
}



/* c010d9c4 FUN_c010d9c4 */

/* Boundary evidence: original MIPS .pdata c010d9c4..c010da4f. Semantic name remains unreviewed. */

HANDLE FUN_c010d9c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HANDLE hSourceProcessHandle;
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  HANDLE local_18 [2];
  
  local_18[0] = (HANDLE)FUN_c010d84c(param_1,param_2,param_3,param_4);
  if (local_18[0] != (HANDLE)0xffffffff) {
    hSourceProcessHandle = (HANDLE)__GetUserKData(0xc);
    hTargetProcessHandle = (HANDLE)GetCallerVMProcessId();
    BVar1 = DuplicateHandle(hSourceProcessHandle,local_18[0],hTargetProcessHandle,local_18,0,0,3);
    if (BVar1 == 0) {
      local_18[0] = (HANDLE)0xffffffff;
    }
  }
  return local_18[0];
}



/* c010da50 FUN_c010da50 */

/* Boundary evidence: original MIPS .pdata c010da50..c010dadb. Semantic name remains unreviewed. */

void FUN_c010da50(int *param_1,short *param_2)

{
  if ((param_1 == (int *)0x0) || ((char)*param_1 != -1)) {
    FUN_c01212b8(param_1,param_2);
  }
  else {
    FUN_c01194b4(param_1,param_2);
  }
  return;
}



/* c010dadc FUN_c010dadc */

/* Boundary evidence: original MIPS .pdata c010dadc..c010dae7. Semantic name remains unreviewed. */

undefined4 FUN_c010dadc(void)

{
  return 1;
}



/* c010dae8 FUN_c010dae8 */

/* Boundary evidence: original MIPS .pdata c010dae8..c010dbe3. Semantic name remains unreviewed. */

undefined4 FUN_c010dae8(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  uint local_9b8;
  uint local_9b4;
  uint local_9b0;
  uint local_9ac;
  short asStack_9a8 [1230];
  uint local_c;
  
  local_c = DAT_c0136c78;
  if ((param_1 == 0) || (iVar1 = CeSafeCopyMemory(&local_9b8,param_1,0x10), iVar1 == 0)) {
LAB_c010db7c:
    SetLastError(0x57);
    FUN_c013331c(local_c);
    uVar3 = 0;
  }
  else {
    if (((char)local_9b8 == -1) && ((local_9b8 & local_9b4 & local_9b0 & local_9ac) != 0xffffffff))
    {
      if (param_2 != 0) {
        uVar3 = 0x99c;
        goto LAB_c010db68;
      }
LAB_c010dbc4:
      psVar2 = (short *)0x0;
    }
    else {
      if (param_2 == 0) goto LAB_c010dbc4;
      uVar3 = 0x27c;
LAB_c010db68:
      iVar1 = CeSafeCopyMemory(asStack_9a8,param_2,uVar3);
      if (iVar1 == 0) goto LAB_c010db7c;
      psVar2 = asStack_9a8;
    }
    uVar3 = FUN_c010da50((int *)&local_9b8,psVar2);
    FUN_c013331c(local_c);
  }
  return uVar3;
}



/* c010dbe4 FUN_c010dbe4 */

/* Boundary evidence: original MIPS .pdata c010dbe4..c010dc83. Semantic name remains unreviewed. */

void FUN_c010dbe4(int *param_1,uint param_2,uint *param_3)

{
  if (((param_1 == (int *)0x0) || ((char)*param_1 != -1)) && ((param_2 & 0xc0000000) != 0x40000000))
  {
    FUN_c0121be8(param_1,param_2,param_3);
  }
  else {
    FUN_c01195ac();
  }
  return;
}



/* c010dc84 FUN_c010dc84 */

/* Boundary evidence: original MIPS .pdata c010dc84..c010dc8f. Semantic name remains unreviewed. */

undefined4 FUN_c010dc84(void)

{
  return 1;
}



/* c010dc90 FUN_c010dc90 */

/* Boundary evidence: original MIPS .pdata c010dc90..c010dd9b. Semantic name remains unreviewed. */

undefined4 FUN_c010dc90(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint local_9c0;
  uint local_9bc;
  uint local_9b8;
  uint local_9b4;
  uint auStack_9b0 [615];
  uint local_14;
  
  local_14 = DAT_c0136c78;
  if ((param_1 == 0) || (iVar1 = CeSafeCopyMemory(&local_9c0,param_1,0x10), iVar1 == 0)) {
LAB_c010dd2c:
    SetLastError(0x57);
    FUN_c013331c(local_14);
    uVar2 = 0;
  }
  else {
    if (((char)local_9c0 == -1) && ((local_9c0 & local_9bc & local_9b8 & local_9b4) != 0xffffffff))
    {
      if (param_3 != 0) {
        uVar2 = 0x99c;
        goto LAB_c010dd18;
      }
LAB_c010dd78:
      puVar3 = (uint *)0x0;
    }
    else {
      if (param_3 == 0) goto LAB_c010dd78;
      uVar2 = 0x27c;
LAB_c010dd18:
      iVar1 = CeSafeCopyMemory(auStack_9b0,param_3,uVar2);
      if (iVar1 == 0) goto LAB_c010dd2c;
      puVar3 = auStack_9b0;
    }
    uVar2 = FUN_c010dbe4((int *)&local_9c0,param_2,puVar3);
    FUN_c013331c(local_14);
  }
  return uVar2;
}



/* c010dd9c FUN_c010dd9c */

/* Boundary evidence: original MIPS .pdata c010dd9c..c010df23. Semantic name remains unreviewed. */

int FUN_c010dd9c(uint *param_1,uint *param_2,PCNZWCH param_3,short *param_4,undefined4 param_5,
                int param_6,int param_7)

{
  int iVar1;
  
  iVar1 = -1;
  if (param_1 == (uint *)0x0) {
    SetLastError(0x57);
  }
  else {
    iVar1 = memcmp(param_1,&DAT_c00f2b58,0x10);
    if ((iVar1 == 0) || ((char)*param_1 != -1)) {
      iVar1 = FUN_c011f744(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      iVar1 = memcmp(param_1,&DAT_c00f2b48,0x10);
      if (iVar1 == 0) {
        memset(param_1,-1,0x10);
      }
      iVar1 = FUN_c0119698(param_1,param_2,param_3,param_4,param_5,param_6);
    }
  }
  return iVar1;
}



/* c010df24 FUN_c010df24 */

/* Boundary evidence: original MIPS .pdata c010df24..c010df2f. Semantic name remains unreviewed. */

undefined4 FUN_c010df24(void)

{
  return 1;
}



/* c010df30 FUN_c010df30 */

/* Boundary evidence: original MIPS .pdata c010df30..c010dfa3. Semantic name remains unreviewed. */

void FUN_c010df30(uint *param_1,uint *param_2,PCNZWCH param_3,short *param_4,undefined4 param_5,
                 int param_6)

{
  int iVar1;
  
  iVar1 = __GetUserKData(0xc);
  FUN_c010dd9c(param_1,param_2,param_3,param_4,param_5,param_6,iVar1);
  return;
}



/* c010dfa4 FUN_c010dfa4 */

/* Boundary evidence: original MIPS .pdata c010dfa4..c010e19b. Semantic name remains unreviewed. */

HANDLE FUN_c010dfa4(int param_1,uint *param_2,int param_3,int param_4,undefined4 param_5,int param_6
                   )

{
  int iVar1;
  int iVar2;
  HANDLE hSourceProcessHandle;
  HANDLE hTargetProcessHandle;
  BOOL BVar3;
  DWORD dwErrCode;
  undefined4 uVar4;
  short *psVar5;
  undefined1 *puVar6;
  HANDLE local_d8;
  PCNZWCH local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  undefined1 auStack_c0 [24];
  short asStack_a8 [68];
  
  local_d8 = (HANDLE)0xffffffff;
  iVar1 = GetCallerVMProcessId();
  local_d4 = (PCNZWCH)0x0;
  if ((param_1 == 0) || (iVar2 = CeSafeCopyMemory(&local_d0,param_1,0x10), iVar2 == 0)) {
LAB_c010e088:
    dwErrCode = 0x57;
    goto LAB_c010e08c;
  }
  if (param_6 == 0) {
    puVar6 = (undefined1 *)0x0;
  }
  else {
    iVar2 = CeSafeCopyMemory(auStack_c0,param_6,0x14);
    if (iVar2 == 0) goto LAB_c010e088;
    puVar6 = auStack_c0;
  }
  if (((char)local_d0 == -1) && ((local_d0 & local_cc & local_c8 & local_c4) != 0xffffffff)) {
    if (param_4 == 0) goto LAB_c010e0dc;
    uVar4 = 0x88;
LAB_c010e074:
    iVar2 = CeSafeCopyMemory(asStack_a8,param_4,uVar4);
    if (iVar2 == 0) goto LAB_c010e088;
    psVar5 = asStack_a8;
  }
  else {
    if (param_4 != 0) {
      uVar4 = 0x20;
      goto LAB_c010e074;
    }
LAB_c010e0dc:
    psVar5 = (short *)0x0;
  }
  if ((param_3 == 0) || (iVar2 = CeAllocDuplicateBuffer(&local_d4,param_3,0,5), -1 < iVar2)) {
    local_d8 = (HANDLE)FUN_c010dd9c(&local_d0,param_2,local_d4,psVar5,param_5,(int)puVar6,iVar1);
    if (local_d8 != (HANDLE)0xffffffff) {
      hSourceProcessHandle = (HANDLE)__GetUserKData(0xc);
      hTargetProcessHandle = (HANDLE)GetCallerVMProcessId();
      BVar3 = DuplicateHandle(hSourceProcessHandle,local_d8,hTargetProcessHandle,&local_d8,0,0,3);
      if (BVar3 == 0) {
        local_d8 = (HANDLE)0xffffffff;
      }
    }
    CeFreeDuplicateBuffer(local_d4,param_3,0,5);
    return local_d8;
  }
  dwErrCode = 0xe;
LAB_c010e08c:
  SetLastError(dwErrCode);
  return (HANDLE)0xffffffff;
}



/* c010e19c FUN_c010e19c */

/* Boundary evidence: original MIPS .pdata c010e19c..c010e24f. Semantic name remains unreviewed. */

void FUN_c010e19c(uint *param_1,uint param_2)

{
  if (((param_1 == (uint *)0x0) || ((char)*param_1 != -1)) ||
     ((param_1[3] & param_1[2] & param_1[1] & *param_1) == 0xffffffff)) {
    FUN_c01217c4((int *)param_1,param_2);
  }
  else {
    FUN_c01197cc();
  }
  return;
}



/* c010e250 FUN_c010e250 */

/* Boundary evidence: original MIPS .pdata c010e250..c010e25b. Semantic name remains unreviewed. */

undefined4 FUN_c010e250(void)

{
  return 1;
}



/* c010e25c FUN_c010e25c */

/* Boundary evidence: original MIPS .pdata c010e25c..c010e2c3. Semantic name remains unreviewed. */

undefined4 FUN_c010e25c(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint auStack_18 [4];
  
  if (param_1 == 0) {
    puVar3 = (uint *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_18,param_1,0x10);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar3 = auStack_18;
  }
  uVar2 = FUN_c010e19c(puVar3,param_2);
  return uVar2;
}



/* c010e2c4 FUN_c010e2c4 */

/* Boundary evidence: original MIPS .pdata c010e2c4..c010e467. Semantic name remains unreviewed. */

int FUN_c010e2c4(int param_1,wchar_t *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if ((param_1 != 0) && (iVar1 = CeSafeCopyMemory(&local_28,param_1,0x10,param_4,0), iVar1 != 0)) {
    if (((local_28 & local_24 & local_20 & local_1c) == 0xffffffff) || ((char)local_28 != -1)) {
      iVar1 = FUN_c01176c0(&local_28,param_2,param_3 >> 1);
    }
    else {
      iVar1 = memcmp(&local_28,&DAT_c00f2b48,0x10);
      if (iVar1 == 0) {
        memset(&local_28,-1,0x10);
      }
      iVar1 = FUN_c0119f84();
    }
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = CeSafeCopyMemory(param_1,&local_28,0x10);
    if (iVar2 != 0) {
      return iVar1;
    }
  }
  SetLastError(0x57);
  return 0;
}



/* c010e468 FUN_c010e468 */

/* Boundary evidence: original MIPS .pdata c010e468..c010e473. Semantic name remains unreviewed. */

undefined4 FUN_c010e468(void)

{
  return 1;
}



/* c010e474 FUN_c010e474 */

/* Boundary evidence: original MIPS .pdata c010e474..c010e5b3. Semantic name remains unreviewed. */

int FUN_c010e474(undefined4 *param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c0136c78;
  iVar1 = CeGetCanonicalPathNameW(param_2,aWStack_228,0x104,0);
  if (iVar1 == 0) {
    SetLastError(0x57);
  }
  iVar2 = 0;
  if (iVar1 != 0) {
    if ((param_3 & 0x80000000) == 0) {
      iVar2 = FUN_c0117244(param_1,aWStack_228,param_3,param_4);
    }
    else {
      iVar2 = FUN_c01190bc(param_1,aWStack_228,param_3 & 0x7fffffff,param_4);
    }
  }
  FUN_c013331c(local_20);
  return iVar2;
}



/* c010e5b4 FUN_c010e5b4 */

/* Boundary evidence: original MIPS .pdata c010e5b4..c010e5bf. Semantic name remains unreviewed. */

undefined4 FUN_c010e5b4(void)

{
  return 1;
}



/* c010e5c0 FUN_c010e5c0 */

/* Boundary evidence: original MIPS .pdata c010e5c0..c010e613. Semantic name remains unreviewed. */

void FUN_c010e5c0(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = __GetUserKData(0xc);
  FUN_c010e474(param_1,param_2,param_3,iVar1);
  return;
}



/* c010e614 FUN_c010e614 */

/* Boundary evidence: original MIPS .pdata c010e614..c010e663. Semantic name remains unreviewed. */

void FUN_c010e614(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = GetCallerVMProcessId();
  FUN_c010e474(param_1,param_2,param_3,iVar1);
  return;
}



/* c010e664 FUN_c010e664 */

/* Boundary evidence: original MIPS .pdata c010e664..c010e717. Semantic name remains unreviewed. */

void FUN_c010e664(uint *param_1,int param_2)

{
  if (((param_1 == (uint *)0x0) || ((char)*param_1 != -1)) ||
     ((param_1[3] & param_1[2] & param_1[1] & *param_1) == 0xffffffff)) {
    FUN_c01175b8((int *)param_1,param_2);
  }
  else {
    FUN_c0118f18(param_1,param_2);
  }
  return;
}



/* c010e718 FUN_c010e718 */

/* Boundary evidence: original MIPS .pdata c010e718..c010e723. Semantic name remains unreviewed. */

undefined4 FUN_c010e718(void)

{
  return 1;
}



/* c010e724 FUN_c010e724 */

/* Boundary evidence: original MIPS .pdata c010e724..c010e757. Semantic name remains unreviewed. */

void FUN_c010e724(uint *param_1)

{
  int iVar1;
  
  iVar1 = __GetUserKData(0xc);
  FUN_c010e664(param_1,iVar1);
  return;
}



/* c010e758 FUN_c010e758 */

/* Boundary evidence: original MIPS .pdata c010e758..c010e7cf. Semantic name remains unreviewed. */

undefined4 FUN_c010e758(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint auStack_20 [4];
  
  iVar1 = GetCallerVMProcessId();
  if (param_1 == 0) {
    puVar4 = (uint *)0x0;
  }
  else {
    iVar2 = CeSafeCopyMemory(auStack_20,param_1,0x10);
    if (iVar2 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar4 = auStack_20;
  }
  uVar3 = FUN_c010e664(puVar4,iVar1);
  return uVar3;
}



/* c010e7d0 FUN_c010e7d0 */

/* Boundary evidence: original MIPS .pdata c010e7d0..c010e8cb. Semantic name remains unreviewed. */

void FUN_c010e7d0(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == (uint *)0x0) {
    FUN_c0117474((int *)0x0,param_2,param_3,param_4);
    FUN_c011a070(0);
  }
  else if (((char)*param_1 == -1) &&
          ((param_1[3] & param_1[2] & param_1[1] & *param_1) != 0xffffffff)) {
    FUN_c011a070((int)param_1);
  }
  else {
    FUN_c0117474((int *)param_1,param_2,param_3,param_4);
  }
  return;
}



/* c010e8cc FUN_c010e8cc */

/* Boundary evidence: original MIPS .pdata c010e8cc..c010e8d7. Semantic name remains unreviewed. */

undefined4 FUN_c010e8cc(void)

{
  return 1;
}



/* c010e8d8 FUN_c010e8d8 */

/* Boundary evidence: original MIPS .pdata c010e8d8..c010e937. Semantic name remains unreviewed. */

undefined4 FUN_c010e8d8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint auStack_18 [4];
  
  if (param_1 == 0) {
    puVar3 = (uint *)0x0;
    param_1 = param_2;
  }
  else {
    param_3 = 0x10;
    iVar1 = CeSafeCopyMemory(auStack_18);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar3 = auStack_18;
  }
  uVar2 = FUN_c010e7d0(puVar3,param_1,param_3,param_4);
  return uVar2;
}



/* c010e938 FUN_c010e938 */

/* Boundary evidence: original MIPS .pdata c010e938..c010e9d3. Semantic name remains unreviewed. */

void FUN_c010e938(uint *param_1,LCID param_2)

{
  if (((param_1 == (uint *)0x0) || ((char)*param_1 != -1)) ||
     ((param_1[3] & param_1[2] & param_1[1] & *param_1) == 0xffffffff)) {
    FUN_c011e074((int *)param_1,param_2);
  }
  else {
    FUN_c011a274();
  }
  return;
}



/* c010e9d4 FUN_c010e9d4 */

/* Boundary evidence: original MIPS .pdata c010e9d4..c010e9df. Semantic name remains unreviewed. */

undefined4 FUN_c010e9d4(void)

{
  return 1;
}



/* c010e9e0 FUN_c010e9e0 */

/* Boundary evidence: original MIPS .pdata c010e9e0..c010ea47. Semantic name remains unreviewed. */

void FUN_c010e9e0(int param_1,LCID param_2)

{
  int iVar1;
  uint *puVar2;
  uint auStack_18 [4];
  
  if (param_1 == 0) {
    puVar2 = (uint *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_18,param_1,0x10);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return;
    }
    puVar2 = auStack_18;
  }
  FUN_c010e938(puVar2,param_2);
  return;
}



/* c010ea48 FUN_c010ea48 */

/* Boundary evidence: original MIPS .pdata c010ea48..c010eaf7. Semantic name remains unreviewed. */

undefined4 FUN_c010ea48(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == (char *)0x0) || (*param_1 != -1)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011a32c();
  }
  return uVar1;
}



/* c010eaf8 FUN_c010eaf8 */

/* Boundary evidence: original MIPS .pdata c010eaf8..c010eb03. Semantic name remains unreviewed. */

undefined4 FUN_c010eaf8(void)

{
  return 1;
}



/* c010eb04 FUN_c010eb04 */

/* Boundary evidence: original MIPS .pdata c010eb04..c010ec5b. Semantic name remains unreviewed. */

undefined4 FUN_c010eb04(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  char local_28 [16];
  
  if (param_3 * 0x14 == param_5) {
    if ((param_1 != 0) && (iVar1 = CeSafeCopyMemory(local_28,param_1,0x10), iVar1 != 0)) {
      if (local_28[0] == -1) {
        uVar2 = FUN_c011a32c();
        return uVar2;
      }
      SetLastError(0x32);
      return 0;
    }
    SetLastError(0x57);
  }
  else {
    SetLastError(0x57);
  }
  return 0;
}



/* c010ec5c FUN_c010ec5c */

/* Boundary evidence: original MIPS .pdata c010ec5c..c010ec67. Semantic name remains unreviewed. */

undefined4 FUN_c010ec5c(void)

{
  return 1;
}



/* c010ec68 FUN_c010ec68 */

/* Boundary evidence: original MIPS .pdata c010ec68..c010ed17. Semantic name remains unreviewed. */

undefined4 FUN_c010ec68(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == (char *)0x0) || (*param_1 != -1)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011a420();
  }
  return uVar1;
}



/* c010ed18 FUN_c010ed18 */

/* Boundary evidence: original MIPS .pdata c010ed18..c010ed23. Semantic name remains unreviewed. */

undefined4 FUN_c010ed18(void)

{
  return 1;
}



/* c010ed24 FUN_c010ed24 */

/* Boundary evidence: original MIPS .pdata c010ed24..c010ee7b. Semantic name remains unreviewed. */

undefined4 FUN_c010ed24(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  char local_28 [16];
  
  if (param_3 * 0x14 == param_5) {
    if ((param_1 != 0) && (iVar1 = CeSafeCopyMemory(local_28,param_1,0x10), iVar1 != 0)) {
      if (local_28[0] == -1) {
        uVar2 = FUN_c011a420();
        return uVar2;
      }
      SetLastError(0x32);
      return 0;
    }
    SetLastError(0x57);
  }
  else {
    SetLastError(0x57);
  }
  return 0;
}



/* c010ee7c FUN_c010ee7c */

/* Boundary evidence: original MIPS .pdata c010ee7c..c010ee87. Semantic name remains unreviewed. */

undefined4 FUN_c010ee7c(void)

{
  return 1;
}



/* c010ee88 FUN_c010ee88 */

/* Boundary evidence: original MIPS .pdata c010ee88..c010ef33. Semantic name remains unreviewed. */

undefined4 FUN_c010ee88(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == (char *)0x0) || (*param_1 != -1)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011a6e8();
  }
  return uVar1;
}



/* c010ef34 FUN_c010ef34 */

/* Boundary evidence: original MIPS .pdata c010ef34..c010ef3f. Semantic name remains unreviewed. */

undefined4 FUN_c010ef34(void)

{
  return 1;
}



/* c010ef40 FUN_c010ef40 */

/* Boundary evidence: original MIPS .pdata c010ef40..c010f087. Semantic name remains unreviewed. */

undefined4 FUN_c010ef40(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  char local_28 [16];
  
  if (param_3 << 2 == param_5) {
    if ((param_1 != 0) && (iVar1 = CeSafeCopyMemory(local_28,param_1,0x10,param_4,0), iVar1 != 0)) {
      if (local_28[0] == -1) {
        uVar2 = FUN_c011a6e8();
        return uVar2;
      }
      SetLastError(0x32);
      return 0;
    }
    SetLastError(0x57);
  }
  else {
    SetLastError(0x57);
  }
  return 0;
}



/* c010f088 FUN_c010f088 */

/* Boundary evidence: original MIPS .pdata c010f088..c010f093. Semantic name remains unreviewed. */

undefined4 FUN_c010f088(void)

{
  return 1;
}



/* c010f094 FUN_c010f094 */

/* Boundary evidence: original MIPS .pdata c010f094..c010f10b. Semantic name remains unreviewed. */

void FUN_c010f094(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                 undefined4 param_5)

{
  FUN_c0118d80(param_1,param_2,param_3,param_4 & 0x7fffffff,param_5);
  return;
}



/* c010f10c FUN_c010f10c */

/* Boundary evidence: original MIPS .pdata c010f10c..c010f117. Semantic name remains unreviewed. */

undefined4 FUN_c010f10c(void)

{
  return 1;
}



/* c010f118 FUN_c010f118 */

/* Boundary evidence: original MIPS .pdata c010f118..c010f17b. Semantic name remains unreviewed. */

void FUN_c010f118(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  uVar1 = __GetUserKData(0xc);
  FUN_c010f094(param_1,param_2,param_3,param_4,uVar1);
  return;
}



/* c010f17c FUN_c010f17c */

/* Boundary evidence: original MIPS .pdata c010f17c..c010f1db. Semantic name remains unreviewed. */

void FUN_c010f17c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  uVar1 = GetCallerVMProcessId();
  FUN_c010f094(param_1,param_2,param_3,param_4,uVar1);
  return;
}



/* c010f1dc FUN_c010f1dc */

/* Boundary evidence: original MIPS .pdata c010f1dc..c010f287. Semantic name remains unreviewed. */

int FUN_c010f1dc(char *param_1)

{
  int iVar1;
  
  iVar1 = -1;
  if ((param_1 == (char *)0x0) || (*param_1 != -1)) {
    SetLastError(0x32);
  }
  else {
    iVar1 = FUN_c011a7d4();
  }
  return iVar1;
}



/* c010f288 FUN_c010f288 */

/* Boundary evidence: original MIPS .pdata c010f288..c010f293. Semantic name remains unreviewed. */

undefined4 FUN_c010f288(void)

{
  return 1;
}



/* c010f294 FUN_c010f294 */

/* Boundary evidence: original MIPS .pdata c010f294..c010f31f. Semantic name remains unreviewed. */

HANDLE FUN_c010f294(char *param_1)

{
  HANDLE hSourceProcessHandle;
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  HANDLE local_18 [2];
  
  local_18[0] = (HANDLE)FUN_c010f1dc(param_1);
  if (local_18[0] != (HANDLE)0xffffffff) {
    hSourceProcessHandle = (HANDLE)__GetUserKData(0xc);
    hTargetProcessHandle = (HANDLE)GetCallerVMProcessId();
    BVar1 = DuplicateHandle(hSourceProcessHandle,local_18[0],hTargetProcessHandle,local_18,0,0,3);
    if (BVar1 == 0) {
      local_18[0] = (HANDLE)0xffffffff;
    }
  }
  return local_18[0];
}



/* c010f320 FUN_c010f320 */

/* Boundary evidence: original MIPS .pdata c010f320..c010f3cb. Semantic name remains unreviewed. */

undefined4 FUN_c010f320(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == (char *)0x0) || (*param_1 != -1)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011b55c();
  }
  return uVar1;
}



/* c010f3cc FUN_c010f3cc */

/* Boundary evidence: original MIPS .pdata c010f3cc..c010f3d7. Semantic name remains unreviewed. */

undefined4 FUN_c010f3cc(void)

{
  return 1;
}



/* c010f3d8 FUN_c010f3d8 */

/* Boundary evidence: original MIPS .pdata c010f3d8..c010f483. Semantic name remains unreviewed. */

undefined4 FUN_c010f3d8(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == (char *)0x0) || (*param_1 != -1)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011b648();
  }
  return uVar1;
}



/* c010f484 FUN_c010f484 */

/* Boundary evidence: original MIPS .pdata c010f484..c010f48f. Semantic name remains unreviewed. */

undefined4 FUN_c010f484(void)

{
  return 1;
}



/* c010f490 FUN_c010f490 */

/* Boundary evidence: original MIPS .pdata c010f490..c010f54f. Semantic name remains unreviewed. */

undefined4 FUN_c010f490(char *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 == (char *)0x0) || (*param_1 != -1)) && ((param_3 & 0xc0000000) != 0x40000000)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011b734();
  }
  return uVar1;
}



/* c010f550 FUN_c010f550 */

/* Boundary evidence: original MIPS .pdata c010f550..c010f55b. Semantic name remains unreviewed. */

undefined4 FUN_c010f550(void)

{
  return 1;
}



/* c010f55c FUN_c010f55c */

/* Boundary evidence: original MIPS .pdata c010f55c..c010f61b. Semantic name remains unreviewed. */

undefined4 FUN_c010f55c(char *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 == (char *)0x0) || (*param_1 != -1)) && ((param_3 & 0xc0000000) != 0x40000000)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011b820();
  }
  return uVar1;
}



/* c010f61c FUN_c010f61c */

/* Boundary evidence: original MIPS .pdata c010f61c..c010f627. Semantic name remains unreviewed. */

undefined4 FUN_c010f61c(void)

{
  return 1;
}



/* c010f628 FUN_c010f628 */

/* Boundary evidence: original MIPS .pdata c010f628..c010f6e7. Semantic name remains unreviewed. */

undefined4 FUN_c010f628(char *param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 == (char *)0x0) || (*param_1 != -1)) && ((param_2 & 0xc0000000) != 0x40000000)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011b90c();
  }
  return uVar1;
}



/* c010f6e8 FUN_c010f6e8 */

/* Boundary evidence: original MIPS .pdata c010f6e8..c010f6f3. Semantic name remains unreviewed. */

undefined4 FUN_c010f6e8(void)

{
  return 1;
}



/* c010f6f4 FUN_c010f6f4 */

/* Boundary evidence: original MIPS .pdata c010f6f4..c010f79f. Semantic name remains unreviewed. */

undefined4 FUN_c010f6f4(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == (char *)0x0) || (*param_1 != -1)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011c494();
  }
  return uVar1;
}



/* c010f7a0 FUN_c010f7a0 */

/* Boundary evidence: original MIPS .pdata c010f7a0..c010f7ab. Semantic name remains unreviewed. */

undefined4 FUN_c010f7a0(void)

{
  return 1;
}



/* c010f7ac FUN_c010f7ac */

/* Boundary evidence: original MIPS .pdata c010f7ac..c010f863. Semantic name remains unreviewed. */

undefined4 FUN_c010f7ac(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == (char *)0x0) || (*param_1 != -1)) {
    SetLastError(0x32);
  }
  else {
    uVar1 = FUN_c011c580();
  }
  return uVar1;
}



/* c010f864 FUN_c010f864 */

/* Boundary evidence: original MIPS .pdata c010f864..c010f86f. Semantic name remains unreviewed. */

undefined4 FUN_c010f864(void)

{
  return 1;
}



/* c010f870 FUN_c010f870 */

/* Boundary evidence: original MIPS .pdata c010f870..c010f977. Semantic name remains unreviewed. */

BOOL FUN_c010f870(undefined4 param_1,int *param_2,int param_3)

{
  uint *puVar1;
  BOOL BVar2;
  
  BVar2 = 0;
  if (*param_2 == param_3) {
    puVar1 = (uint *)(param_2 + 3);
    if (puVar1 != (uint *)0x0) {
      if ((((*puVar1 & param_2[4] & param_2[5] & param_2[6]) != 0xffffffff) &&
          (((*puVar1 != 0 || param_2[4] != 0) || param_2[5] != 0) || param_2[6] != 0)) &&
         ((char)*puVar1 == -1)) {
        BVar2 = FUN_c011c66c();
        return BVar2;
      }
    }
    BVar2 = FUN_c0120eb4(param_1,param_2);
  }
  else {
    SetLastError(0x57);
  }
  return BVar2;
}



/* c010f978 FUN_c010f978 */

/* Boundary evidence: original MIPS .pdata c010f978..c010f983. Semantic name remains unreviewed. */

undefined4 FUN_c010f978(void)

{
  return 1;
}



/* c010f984 FUN_c010f984 */

/* Boundary evidence: original MIPS .pdata c010f984..c010fa3f. Semantic name remains unreviewed. */

void FUN_c010f984(void *param_1)

{
  int iVar1;
  void *_Buf1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  for (_Buf1 = DAT_c0136d04; _Buf1 != (void *)0x0; _Buf1 = *(void **)((int)_Buf1 + 0x18)) {
    iVar1 = memcmp(_Buf1,&DAT_c00f2b68,0x10);
    if ((iVar1 == 0) || (iVar1 = memcmp(_Buf1,param_1,0x10), iVar1 == 0)) {
      WriteMsgQueue(*(undefined4 *)((int)_Buf1 + 0x10),param_1,*(int *)((int)param_1 + 0x18) + 0x1e,
                    0,0);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  return;
}



/* c010fa40 FUN_c010fa40 */

/* Boundary evidence: original MIPS .pdata c010fa40..c010fb07. Semantic name remains unreviewed. */

void FUN_c010fa40(void *param_1)

{
  int iVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  for (piVar2 = (int *)DAT_c0136d00; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    iVar1 = memcmp(param_1,&DAT_c00f2b68,0x10);
    if ((iVar1 == 0) || (iVar1 = memcmp(param_1,piVar2 + 2,0x10), iVar1 == 0)) {
      WriteMsgQueue(*(undefined4 *)((int)param_1 + 0x10),piVar2 + 2,piVar2[8] + 0x1e,0,0);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  return;
}



/* c010fb08 FUN_c010fb08 */

/* Boundary evidence: original MIPS .pdata c010fb08..c010fc03. Semantic name remains unreviewed. */

undefined4 * FUN_c010fb08(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *_Dst;
  int iVar1;
  undefined4 local_30 [4];
  undefined4 local_20;
  
  _Dst = LocalAlloc(0,0x1c);
  if (_Dst != (undefined4 *)0x0) {
    local_30[0] = 0x14;
    local_20 = 0;
    _Dst[5] = param_3;
    iVar1 = OpenMsgQueue(param_3,param_2,local_30);
    _Dst[4] = iVar1;
    if (iVar1 != 0) {
      if (param_1 == (undefined4 *)0x0) {
        memset(_Dst,0,0x10);
      }
      else {
        *_Dst = *param_1;
        _Dst[1] = param_1[1];
        _Dst[2] = param_1[2];
        _Dst[3] = param_1[3];
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
      _Dst[6] = DAT_c0136d04;
      DAT_c0136d04 = _Dst;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
      return _Dst;
    }
    LocalFree(_Dst);
  }
  return (undefined4 *)0x0;
}



/* c010fc04 FUN_c010fc04 */

/* Boundary evidence: original MIPS .pdata c010fc04..c010fcc3. Semantic name remains unreviewed. */

void FUN_c010fc04(HLOCAL param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  bVar1 = false;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  piVar2 = &DAT_c0136d04;
  iVar3 = DAT_c0136d04;
  do {
    if (iVar3 == 0) {
LAB_c010fc74:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
      if ((bVar1) && (*(int *)((int)param_1 + 0x14) == param_2)) {
        CloseHandle(*(HANDLE *)((int)param_1 + 0x10));
        LocalFree(param_1);
      }
      return;
    }
    if ((HLOCAL)*piVar2 == param_1) {
      bVar1 = true;
      *piVar2 = *(int *)((int)param_1 + 0x18);
      goto LAB_c010fc74;
    }
    piVar2 = (int *)(*piVar2 + 0x18);
    iVar3 = *piVar2;
  } while( true );
}



/* c010fcc4 FUN_c010fcc4 */

/* Boundary evidence: original MIPS .pdata c010fcc4..c010fd7f. Semantic name remains unreviewed. */

int FUN_c010fcc4(void *param_1,wchar_t *param_2)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
    iVar3 = 0;
  }
  else {
    sVar1 = wcslen(param_2);
    iVar3 = sVar1 + 1;
  }
  piVar4 = (int *)DAT_c0136d00;
  while ((piVar4 != (int *)0x0 &&
         (((iVar2 = memcmp(piVar4 + 2,param_1,0x10), iVar2 != 0 || (piVar4[8] != iVar3 << 1)) ||
          (iVar2 = memcmp(piVar4 + 9,param_2,iVar3 << 1), iVar2 != 0))))) {
    piVar4 = (int *)*piVar4;
  }
  return (int)piVar4;
}



/* c010fd80 FUN_c010fd80 */

/* Boundary evidence: original MIPS .pdata c010fd80..c010fe93. Semantic name remains unreviewed. */

bool FUN_c010fd80(undefined4 param_1,undefined4 *param_2,wchar_t *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  size_t sVar2;
  undefined4 *_Dst;
  
  sVar2 = wcslen(param_3);
  sVar2 = sVar2 * 2;
  _Dst = LocalAlloc(0x40,sVar2 + 0x28);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,sVar2 + 0x28);
    _Dst[1] = param_5;
    _Dst[2] = *param_2;
    _Dst[3] = param_2[1];
    _Dst[4] = param_2[2];
    _Dst[5] = param_2[3];
    _Dst[6] = param_4;
    _Dst[7] = 1;
    _Dst[8] = sVar2 + 2;
    memcpy(_Dst + 9,param_3,sVar2);
    puVar1 = _Dst;
    *_Dst = DAT_c0136d00;
    DAT_c0136d00 = puVar1;
    FUN_c010f984(_Dst + 2);
  }
  else {
    SetLastError(0xe);
  }
  return _Dst != (undefined4 *)0x0;
}



/* c010fe94 FUN_c010fe94 */

/* Boundary evidence: original MIPS .pdata c010fe94..c010ff3b. Semantic name remains unreviewed. */

undefined4 FUN_c010fe94(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_1[1] == param_2) {
    param_1[7] = 0;
    FUN_c010f984(param_1 + 2);
    piVar2 = DAT_c0136d00;
    if (DAT_c0136d00 == param_1) {
      DAT_c0136d00 = (int *)*param_1;
    }
    else {
      do {
        piVar1 = piVar2;
        if (piVar1 == (int *)0x0) goto LAB_c010ff20;
        piVar2 = (int *)*piVar1;
      } while ((int *)*piVar1 != param_1);
      *piVar1 = *param_1;
    }
LAB_c010ff20:
    LocalFree(param_1);
    uVar3 = 1;
  }
  else {
    SetLastError(5);
    uVar3 = 0;
  }
  return uVar3;
}



/* c010ff3c FUN_c010ff3c */

/* Boundary evidence: original MIPS .pdata c010ff3c..c01100e7. Semantic name remains unreviewed. */

uint FUN_c010ff3c(undefined4 *param_1,wchar_t *param_2,undefined4 param_3,int param_4,int param_5)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  DWORD dwErrCode;
  uint uVar3;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (wchar_t *)0x0)) {
    SetLastError(0x57);
    return 0;
  }
  if (*param_2 == L'\0') {
    SetLastError(0x57);
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  piVar2 = (int *)FUN_c010fcc4(param_1,param_2);
  if (param_4 == 0) {
    if (piVar2 != (int *)0x0) {
      uVar3 = FUN_c010fe94(piVar2,param_5);
      goto LAB_c0110054;
    }
    dwErrCode = 2;
  }
  else {
    if (piVar2 == (int *)0x0) {
      bVar1 = FUN_c010fd80(0,param_1,param_2,param_3,param_5);
      uVar3 = CONCAT31(extraout_var,bVar1);
      goto LAB_c0110054;
    }
    dwErrCode = 0xb7;
  }
  SetLastError(dwErrCode);
  uVar3 = 0;
LAB_c0110054:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  return uVar3;
}



/* c01100e8 FUN_c01100e8 */

/* Boundary evidence: original MIPS .pdata c01100e8..c01100f3. Semantic name remains unreviewed. */

undefined4 FUN_c01100e8(void)

{
  return 1;
}



/* c01100f4 FUN_c01100f4 */

/* Boundary evidence: original MIPS .pdata c01100f4..c011019f. Semantic name remains unreviewed. */

void FUN_c01100f4(undefined4 param_1,int param_2)

{
  HLOCAL pvVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  HLOCAL pvVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  uVar2 = 1;
  piVar3 = (int *)DAT_c0136d00;
  do {
    pvVar5 = DAT_c0136d04;
    if (piVar3 == (int *)0x0) break;
    iVar4 = *piVar3;
    if (piVar3[1] == param_2) {
      uVar2 = FUN_c010ff3c(piVar3 + 2,(wchar_t *)(piVar3 + 9),0,0,param_2);
    }
    piVar3 = (int *)iVar4;
    pvVar5 = DAT_c0136d04;
  } while (uVar2 != 0);
  while (pvVar1 = pvVar5, pvVar1 != (HLOCAL)0x0) {
    pvVar5 = *(HLOCAL *)((int)pvVar1 + 0x18);
    if (*(int *)((int)pvVar1 + 0x14) == param_2) {
      FUN_c010fc04(pvVar1,param_2);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  return;
}



/* c01101a0 FUN_c01101a0 */

/* Boundary evidence: original MIPS .pdata c01101a0..c0110203. Semantic name remains unreviewed. */

void FUN_c01101a0(undefined4 *param_1,wchar_t *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = __GetUserKData(0xc);
  FUN_c010ff3c(param_1,param_2,param_3,param_4,iVar1);
  return;
}



/* c0110204 FUN_c0110204 */

/* Boundary evidence: original MIPS .pdata c0110204..c01102cb. Semantic name remains unreviewed. */

uint FUN_c0110204(undefined4 *param_1,wchar_t *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  iVar1 = GetCallerVMProcessId();
  if ((param_2 == (wchar_t *)0x0) ||
     (iVar2 = CeAllocDuplicateBuffer(local_20,param_2,0,5), -1 < iVar2)) {
    uVar3 = FUN_c010ff3c(param_1,param_2,param_3,param_4,iVar1);
    if (param_2 != (wchar_t *)0x0) {
      CeFreeDuplicateBuffer(local_20[0],param_2,0,5);
    }
  }
  else {
    SetLastError(0xe);
    uVar3 = 0;
  }
  return uVar3;
}



/* c01102cc FUN_c01102cc */

/* Boundary evidence: original MIPS .pdata c01102cc..c01103ff. Semantic name remains unreviewed. */

undefined4 * FUN_c01102cc(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_30 [4];
  uint local_20;
  
  local_20 = DAT_c0136c78;
  uVar1 = GetCallerVMProcessId();
  if (param_1 != 0) {
    iVar2 = CeSafeCopyMemory(auStack_30,param_1,0x10);
    if (iVar2 == 0) {
      SetLastError(0x57);
      FUN_c013331c(local_20);
      return (undefined4 *)0x0;
    }
    puVar3 = auStack_30;
    if (param_1 != 0) goto LAB_c0110378;
  }
  puVar3 = (undefined4 *)0x0;
LAB_c0110378:
  puVar3 = FUN_c010fb08(puVar3,param_2,uVar1);
  if ((puVar3 != (undefined4 *)0x0) && (param_3 != 0)) {
    FUN_c010fa40(puVar3);
  }
  FUN_c013331c(local_20);
  return puVar3;
}



/* c0110400 FUN_c0110400 */

/* Boundary evidence: original MIPS .pdata c0110400..c011040b. Semantic name remains unreviewed. */

undefined4 FUN_c0110400(void)

{
  return 1;
}



/* c011040c FUN_c011040c */

/* Boundary evidence: original MIPS .pdata c011040c..c01104c3. Semantic name remains unreviewed. */

undefined4 * FUN_c011040c(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = __GetUserKData(0xc);
  puVar2 = FUN_c010fb08(param_1,param_2,uVar1);
  if ((puVar2 != (undefined4 *)0x0) && (param_3 != 0)) {
    FUN_c010fa40(puVar2);
  }
  return puVar2;
}



/* c01104c4 FUN_c01104c4 */

/* Boundary evidence: original MIPS .pdata c01104c4..c01104cf. Semantic name remains unreviewed. */

undefined4 FUN_c01104c4(void)

{
  return 1;
}



/* c01104d0 FUN_c01104d0 */

/* Boundary evidence: original MIPS .pdata c01104d0..c0110533. Semantic name remains unreviewed. */

undefined4 FUN_c01104d0(HLOCAL param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = GetCallerVMProcessId();
  if ((param_1 == (HLOCAL)0x0) || (param_1 == (HLOCAL)0xffffffff)) {
    SetLastError(0x57);
    uVar2 = 0;
  }
  else {
    FUN_c010fc04(param_1,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}



/* c0110534 FUN_c0110534 */

/* Boundary evidence: original MIPS .pdata c0110534..c011059b. Semantic name remains unreviewed. */

undefined4 FUN_c0110534(HLOCAL param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __GetUserKData(0xc);
  if ((param_1 == (HLOCAL)0x0) || (param_1 == (HLOCAL)0xffffffff)) {
    SetLastError(0x57);
    uVar2 = 0;
  }
  else {
    FUN_c010fc04(param_1,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}



/* c011059c FUN_c011059c */

/* Boundary evidence: original MIPS .pdata c011059c..c01105d7. Semantic name remains unreviewed. */

void FUN_c011059c(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d08);
  DAT_c0136d04 = 0;
  DAT_c0136d00 = 0;
  return;
}



/* c01105d8 FUN_c01105d8 */

/* Boundary evidence: original MIPS .pdata c01105d8..c0110707. Semantic name remains unreviewed. */

int FUN_c01105d8(int param_1)

{
  int iVar1;
  int iVar2;
  int local_28;
  uint local_24;
  
  iVar2 = 1;
  if ((DAT_c0136d1c == 0) &&
     ((iVar2 = 1, DAT_c0136d2c == (code *)0x0 || (iVar2 = (*DAT_c0136d2c)(8), iVar2 != 0)))) {
    iVar1 = (*DAT_c0136ca0)(0,0,0,&local_24,4,&local_28);
    if ((iVar1 != 0) && (local_28 == 4)) {
      *(uint *)(param_1 + 0xf8) = local_24 & 7 | *(uint *)(param_1 + 0xf8);
      iVar2 = (*DAT_c0136ca0)(0,4,0,param_1 + 0xd4,0x10,&local_28);
      if (iVar2 != 0) {
        DAT_c0136d1c = 1;
      }
    }
    if (DAT_c0136d2c != (code *)0x0) {
      (*DAT_c0136d2c)(9);
    }
  }
  return iVar2;
}



/* c0110708 FUN_c0110708 */

/* Boundary evidence: original MIPS .pdata c0110708..c01107d7. Semantic name remains unreviewed. */

undefined4 FUN_c0110708(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res0 [4];
  
  uVar2 = 1;
  local_res0[0] = param_1;
  iVar1 = (*DAT_c0136d2c)(6);
  if (iVar1 != 0) {
    local_res0[0] = local_res0[0] & 7;
    iVar1 = (*DAT_c0136ca4)(0,0,0,local_res0,4);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = (*DAT_c0136ca4)(0,4,0,param_2,0x10);
    }
    if (DAT_c0136d2c != (code *)0x0) {
      (*DAT_c0136d2c)(7);
    }
  }
  return uVar2;
}



/* c01107d8 FUN_c01107d8 */

/* Boundary evidence: original MIPS .pdata c01107d8..c0110937. Semantic name remains unreviewed. */

undefined4 FUN_c01107d8(wchar_t *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint auStack_28 [4];
  
  puVar1 = FUN_c0111ab0();
  uVar4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)puVar1[0x87]);
  iVar5 = puVar1[2];
  if (iVar5 == 0) {
    uVar4 = 0;
  }
  else {
    if (DAT_c0136ca0 != 0) {
      FUN_c01105d8(iVar5);
    }
    if (param_1 == (wchar_t *)0x0) {
      uVar3 = *(uint *)(iVar5 + 0xf8) & 1;
    }
    else {
      iVar2 = FUN_c012a5fc(param_1,auStack_28);
      if (iVar2 == 0) goto LAB_c01108b8;
      uVar3 = memcmp(auStack_28,(void *)(iVar5 + 0xd4),0x10);
    }
    if (uVar3 == 0) {
      uVar4 = 1;
    }
  }
LAB_c01108b8:
  LeaveCriticalSection((LPCRITICAL_SECTION)puVar1[0x87]);
  return uVar4;
}



/* c0110938 FUN_c0110938 */

/* Boundary evidence: original MIPS .pdata c0110938..c0110943. Semantic name remains unreviewed. */

undefined4 FUN_c0110938(void)

{
  return 1;
}



/* c0110944 FUN_c0110944 */

/* Boundary evidence: original MIPS .pdata c0110944..c011094f. Semantic name remains unreviewed. */

undefined4 FUN_c0110944(void)

{
  return 1;
}



/* c0110950 FUN_c0110950 */

/* Boundary evidence: original MIPS .pdata c0110950..c01109df. Semantic name remains unreviewed. */

undefined4 FUN_c0110950(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *local_18 [2];
  
  local_18[0] = (wchar_t *)0x0;
  if ((param_1 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_18,param_1,0,5), -1 < iVar1)) {
    uVar2 = FUN_c01107d8(local_18[0]);
    CeFreeDuplicateBuffer(local_18[0],param_1,0,5);
  }
  else {
    SetLastError(0xe);
    uVar2 = 0;
  }
  return uVar2;
}



/* c01109e0 FUN_c01109e0 */

/* Boundary evidence: original MIPS .pdata c01109e0..c0110cc3. Semantic name remains unreviewed. */

BOOL FUN_c01109e0(wchar_t *param_1,wchar_t *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *_Dst;
  BOOL BVar7;
  int iVar8;
  uint auStack_30 [4];
  
  puVar1 = FUN_c0111ab0();
  BVar7 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)puVar1[0x87]);
  iVar8 = puVar1[2];
  if (DAT_c0136ca0 != 0) {
    FUN_c01105d8(iVar8);
  }
  if (param_1 == (wchar_t *)0x0) {
    uVar6 = *(uint *)(iVar8 + 0xf8) & 1;
  }
  else {
    iVar2 = FUN_c012a5fc(param_1,auStack_30);
    if (iVar2 == 0) goto LAB_c0110c3c;
    uVar6 = memcmp(auStack_30,(void *)(iVar8 + 0xd4),0x10);
  }
  if (uVar6 == 0) {
    if (param_2 == (wchar_t *)0x0) {
      uVar6 = *(uint *)(iVar8 + 0xf8) & 0xfffffffa;
      memset(auStack_30,0,0x10);
    }
    else {
      iVar2 = FUN_c012a5fc(param_2,auStack_30);
      if (iVar2 == 0) goto LAB_c0110c3c;
      uVar6 = *(uint *)(iVar8 + 0xf8) | 1;
    }
    puVar3 = (uint *)(iVar8 + 0xf8);
    if ((DAT_c0136ca4 == 0) || (iVar2 = FUN_c0110708(uVar6,auStack_30), iVar2 != 0)) {
      FUN_c010297c((int)puVar1);
      BVar7 = 1;
      FUN_c01029e4((int)puVar1,1,puVar3,*puVar3,4);
      *puVar3 = uVar6;
      _Dst = (undefined4 *)(iVar8 + 0xd4);
      FUN_c01029e4((int)puVar1,1,_Dst,*_Dst,4);
      FUN_c01029e4((int)puVar1,1,(undefined4 *)(iVar8 + 0xd8),*(undefined4 *)(iVar8 + 0xd8),4);
      FUN_c01029e4((int)puVar1,1,(undefined4 *)(iVar8 + 0xdc),*(undefined4 *)(iVar8 + 0xdc),4);
      uVar5 = *(undefined4 *)(iVar8 + 0xe0);
      FUN_c01029e4((int)puVar1,1,(undefined4 *)(iVar8 + 0xe0),uVar5,4);
      puVar3 = auStack_30;
      uVar4 = 0x10;
      memcpy(_Dst,puVar3,0x10);
      FUN_c0102aa4(puVar1);
      if (puVar1 != &DAT_c01391e0) {
        FUN_c0101bb0(puVar1 + 4,puVar3,uVar4,uVar5);
        BVar7 = FlushViewOfFile((LPCVOID)puVar1[2],puVar1[0x8d] - (int)puVar1[2]);
      }
    }
  }
LAB_c0110c3c:
  LeaveCriticalSection((LPCRITICAL_SECTION)puVar1[0x87]);
  return BVar7;
}



/* c0110cc4 FUN_c0110cc4 */

/* Boundary evidence: original MIPS .pdata c0110cc4..c0110ccf. Semantic name remains unreviewed. */

undefined4 FUN_c0110cc4(void)

{
  return 1;
}



/* c0110cd0 FUN_c0110cd0 */

/* Boundary evidence: original MIPS .pdata c0110cd0..c0110cdb. Semantic name remains unreviewed. */

undefined4 FUN_c0110cd0(void)

{
  return 1;
}



/* c0110cdc FUN_c0110cdc */

/* Boundary evidence: original MIPS .pdata c0110cdc..c0110dc3. Semantic name remains unreviewed. */

BOOL FUN_c0110cdc(int param_1,int param_2)

{
  int iVar1;
  BOOL BVar2;
  wchar_t *local_18;
  wchar_t *local_14;
  
  local_18 = (wchar_t *)0x0;
  local_14 = (wchar_t *)0x0;
  if (((param_1 == 0) || (iVar1 = CeAllocDuplicateBuffer(&local_18,param_1,0,5), -1 < iVar1)) &&
     ((param_2 == 0 || (iVar1 = CeAllocDuplicateBuffer(&local_14,param_2,0,5), -1 < iVar1)))) {
    BVar2 = FUN_c01109e0(local_18,local_14);
    CeFreeDuplicateBuffer(local_18,param_1,0,5);
    CeFreeDuplicateBuffer(local_14,param_2,0,5);
  }
  else {
    CeFreeDuplicateBuffer(local_18,param_1,0,5);
    SetLastError(0xe);
    BVar2 = 0;
  }
  return BVar2;
}



/* c0110dc4 FUN_c0110dc4 */

/* Boundary evidence: original MIPS .pdata c0110dc4..c0110edb. Semantic name remains unreviewed. */

byte FUN_c0110dc4(void)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = 0;
  puVar1 = FUN_c0111ab0();
  if (puVar1 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)puVar1[0x87]);
    iVar3 = puVar1[2];
    bVar2 = 0;
    if (iVar3 != 0) {
      if (DAT_c0136ca0 != 0) {
        FUN_c01105d8(iVar3);
      }
      bVar2 = (*(uint *)(iVar3 + 0xf8) & 2) != 0;
      if ((*(uint *)(iVar3 + 0xf8) & 4) != 0) {
        bVar2 = bVar2 | 2;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)puVar1[0x87]);
  }
  return bVar2;
}



/* c0110edc FUN_c0110edc */

/* Boundary evidence: original MIPS .pdata c0110edc..c0110ee7. Semantic name remains unreviewed. */

undefined4 FUN_c0110edc(void)

{
  return 1;
}



/* c0110ee8 FUN_c0110ee8 */

/* Boundary evidence: original MIPS .pdata c0110ee8..c0110ef3. Semantic name remains unreviewed. */

undefined4 FUN_c0110ee8(void)

{
  return 1;
}



/* c0110ef4 FUN_c0110ef4 */

/* Boundary evidence: original MIPS .pdata c0110ef4..c011111b. Semantic name remains unreviewed. */

int FUN_c0110ef4(uint param_1,wchar_t *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  BOOL BVar3;
  
  puVar1 = FUN_c0111ab0();
  BVar3 = 0;
  if ((param_1 & 3) == 2) {
    SetLastError(0x57);
    BVar3 = 0;
  }
  else {
    if (puVar1 != (undefined4 *)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)puVar1[0x87]);
      iVar2 = FUN_c01107d8(param_2);
      if ((iVar2 != 0) && (iVar2 = puVar1[2], iVar2 != 0)) {
        if ((param_1 & 1) == 0) {
          *(uint *)(iVar2 + 0xf8) = *(uint *)(iVar2 + 0xf8) & 0xfffffffd;
        }
        else {
          *(uint *)(iVar2 + 0xf8) = *(uint *)(iVar2 + 0xf8) | 2;
        }
        if ((param_1 & 2) == 0) {
          *(uint *)(iVar2 + 0xf8) = *(uint *)(iVar2 + 0xf8) & 0xfffffffb;
        }
        else {
          *(uint *)(iVar2 + 0xf8) = *(uint *)(iVar2 + 0xf8) | 4;
        }
        if (puVar1 == &DAT_c01391e0) {
          if (DAT_c0136ca4 == 0) {
            BVar3 = 1;
          }
          else {
            BVar3 = FUN_c0110708(*(uint *)(iVar2 + 0xf8),iVar2 + 0xd4);
          }
        }
        else {
          BVar3 = FlushViewOfFile((LPCVOID)puVar1[2],puVar1[0x8d] - (int)puVar1[2]);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)puVar1[0x87]);
    }
    if (BVar3 == 0) {
      SetLastError(5);
    }
  }
  return BVar3;
}



/* c011111c FUN_c011111c */

/* Boundary evidence: original MIPS .pdata c011111c..c0111127. Semantic name remains unreviewed. */

undefined4 FUN_c011111c(void)

{
  return 1;
}



/* c0111128 FUN_c0111128 */

/* Boundary evidence: original MIPS .pdata c0111128..c0111133. Semantic name remains unreviewed. */

undefined4 FUN_c0111128(void)

{
  return 1;
}



/* c0111134 FUN_c0111134 */

/* Boundary evidence: original MIPS .pdata c0111134..c01111c7. Semantic name remains unreviewed. */

int FUN_c0111134(uint param_1,int param_2)

{
  int iVar1;
  wchar_t *local_18 [2];
  
  local_18[0] = (wchar_t *)0x0;
  if ((param_2 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_18,param_2,0,5), -1 < iVar1)) {
    iVar1 = FUN_c0110ef4(param_1,local_18[0]);
    CeFreeDuplicateBuffer(local_18[0],param_2,0,5);
  }
  else {
    SetLastError(0xe);
    iVar1 = 0;
  }
  return iVar1;
}



/* c01111c8 FUN_c01111c8 */

/* Boundary evidence: original MIPS .pdata c01111c8..c01115f3. Semantic name remains unreviewed. */

uint FUN_c01111c8(wchar_t *param_1,int param_2,undefined4 param_3,int param_4)

{
  size_t cchCount1;
  size_t cchCount2;
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  wchar_t *_Dest;
  wchar_t *pwVar4;
  uint uVar5;
  WCHAR local_238 [259];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_c0136c78;
  uVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c01391a0);
  if (param_1 == (wchar_t *)0x0) {
    pwVar4 = (wchar_t *)0x0;
    goto LAB_c0111414;
  }
  cchCount1 = wcslen(param_1);
  pwVar4 = DAT_c0137170;
  if ((cchCount1 != 0) && (DAT_c0137170 != (wchar_t *)0x0)) {
    cchCount2 = wcslen(DAT_c0137170);
    iVar1 = CompareStringW(0x800,1,param_1,cchCount1,pwVar4,cchCount2);
    if (iVar1 == 2) {
      if (DAT_c0137174 == 0) {
        uVar5 = FUN_c012bb10(param_1,param_2,param_3);
        DAT_c0137174 = uVar5;
      }
      else {
        SetLastError(0x524);
      }
      goto LAB_c0111568;
    }
  }
  if ((cchCount1 == 0) || (iVar1 = FUN_c00fc600((ushort *)param_1,cchCount1), iVar1 == 0)) {
    DVar2 = 0x7b;
LAB_c011150c:
    SetLastError(DVar2);
  }
  else {
    pwVar4 = LocalAlloc(0,(cchCount1 + 1) * 2);
    if (pwVar4 != (wchar_t *)0x0) {
      wcscpy(pwVar4,param_1);
      iVar1 = FUN_c01132d0(local_238,0x104);
      if (iVar1 != 0) {
        for (_Dest = local_238; *_Dest != L'\0'; _Dest = _Dest + 1) {
        }
        wcsncpy(_Dest,pwVar4,0x104 - ((int)_Dest - (int)local_238 >> 1));
        local_32 = 0;
        DVar2 = GetFileAttributesW(local_238);
        if (DVar2 == 0xffffffff) {
          if (param_4 == 0) {
            DVar2 = 0x525;
            goto LAB_c011150c;
          }
          iVar1 = FUN_c00fd4ec(local_238,0);
          if (iVar1 == 0) goto LAB_c011151c;
        }
LAB_c0111414:
        DVar2 = FUN_c01131a8();
        if ((DVar2 != 0) && (DVar2 != 0x32)) {
          if (pwVar4 != (wchar_t *)0x0) {
            LocalFree(pwVar4);
          }
          goto LAB_c011150c;
        }
        if (DAT_c0137170 != (wchar_t *)0x0) {
          LocalFree(DAT_c0137170);
        }
        DAT_c0137170 = pwVar4;
        SetLastError(0);
        uVar3 = FUN_c012bb10(pwVar4,param_2,param_3);
        if (uVar3 == 0) {
          DAT_c0137174 = 0;
          if (param_2 != 0) goto LAB_c011151c;
        }
        else {
          DAT_c0137174 = (uint)(pwVar4 != (wchar_t *)0x0);
        }
        uVar5 = 1;
      }
    }
  }
LAB_c011151c:
  if (uVar5 == 0) {
    FUN_c01131a8();
    FUN_c012bb10((wchar_t *)0x0,0,0);
    DAT_c0137174 = 0;
    if (DAT_c0137170 != (wchar_t *)0x0) {
      LocalFree(DAT_c0137170);
      DAT_c0137170 = (wchar_t *)0x0;
    }
  }
LAB_c0111568:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c01391a0);
  FUN_c013331c(local_30);
  return uVar5;
}



/* c01115f4 FUN_c01115f4 */

/* Boundary evidence: original MIPS .pdata c01115f4..c01115ff. Semantic name remains unreviewed. */

undefined4 FUN_c01115f4(void)

{
  return 1;
}



/* c0111600 FUN_c0111600 */

/* Boundary evidence: original MIPS .pdata c0111600..c01116b3. Semantic name remains unreviewed. */

uint FUN_c0111600(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  wchar_t *local_20 [2];
  
  local_20[0] = (wchar_t *)0x0;
  if ((param_1 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_20,param_1,0,5), -1 < iVar1)) {
    uVar2 = FUN_c01111c8(local_20[0],param_2,param_3,param_4);
    CeFreeDuplicateBuffer(local_20[0],param_1,0,5);
  }
  else {
    SetLastError(0xe);
    uVar2 = 0;
  }
  return uVar2;
}



/* c01116b4 FUN_c01116b4 */

/* Boundary evidence: original MIPS .pdata c01116b4..c01117bb. Semantic name remains unreviewed. */

uint FUN_c01116b4(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c01391a0);
  if (DAT_c0137170 == (wchar_t *)0x0) {
    FUN_c012bb10((wchar_t *)0x0,0,0);
    SetLastError(2);
  }
  else {
    uVar1 = FUN_c012bb10(DAT_c0137170,param_1,param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c01391a0);
  return uVar1;
}



/* c01117bc FUN_c01117bc */

/* Boundary evidence: original MIPS .pdata c01117bc..c01117c7. Semantic name remains unreviewed. */

undefined4 FUN_c01117bc(void)

{
  return 1;
}



/* c01117c8 FUN_c01117c8 */

/* Boundary evidence: original MIPS .pdata c01117c8..c0111aa3. Semantic name remains unreviewed. */

undefined4 FUN_c01117c8(wchar_t *param_1,int param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  LPCRITICAL_SECTION p_Var4;
  wchar_t *_Source;
  uint uVar5;
  size_t sVar6;
  uint local_250;
  LPCRITICAL_SECTION local_24c;
  undefined4 local_248;
  int local_244;
  int local_240;
  int local_23c;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  uVar3 = 0;
  local_248 = 0;
  local_244 = param_2;
  local_240 = param_2;
  iVar1 = FUN_c012bbc8(&local_250,param_2);
  if ((iVar1 == 0) || ((param_3 != 1 && (param_3 != 2)))) {
    SetLastError(0x57);
    FUN_c013331c(local_30);
    return 0;
  }
  local_24c = (LPCRITICAL_SECTION)&DAT_c01391a0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c01391a0);
  _Source = DAT_c0137170;
  if (DAT_c0137170 == (wchar_t *)0x0) {
    p_Var4 = (LPCRITICAL_SECTION)&DAT_c01391a0;
    if (param_3 == 1) {
      if ((local_250 != 0) && (param_1 != (wchar_t *)0x0)) {
        *param_1 = L'\0';
      }
      local_250 = 0;
      uVar3 = 1;
      local_248 = 1;
    }
    else {
      SetLastError(3);
    }
  }
  else {
    sVar2 = wcslen(DAT_c0137170);
    iVar1 = sVar2 + 1;
    sVar6 = 0;
    if (param_3 == 2) {
      local_23c = iVar1;
      iVar1 = FUN_c01132d0(aWStack_238,0x104);
      p_Var4 = local_24c;
      if (iVar1 == 0) goto LAB_c0111a04;
      sVar6 = wcslen(aWStack_238);
      iVar1 = sVar2 + 2;
      _Source = DAT_c0137170;
    }
    uVar5 = sVar6 + iVar1;
    local_23c = iVar1;
    if ((local_250 < uVar5) || (param_1 == (wchar_t *)0x0)) {
      SetLastError(0x7a);
      p_Var4 = local_24c;
      param_2 = local_244;
      local_250 = uVar5;
    }
    else {
      if (param_3 == 2) {
        wcscpy(param_1,aWStack_238);
        param_1 = param_1 + sVar6;
        _Source = DAT_c0137170;
      }
      wcscpy(param_1,_Source);
      if (param_3 == 2) {
        param_1[iVar1 + -2] = L'\\';
        param_1[iVar1 + -1] = L'\0';
      }
      uVar3 = 1;
      local_248 = 1;
      p_Var4 = local_24c;
      param_2 = local_244;
      local_250 = uVar5 - 1;
    }
  }
LAB_c0111a04:
  LeaveCriticalSection(p_Var4);
  CeSafeCopyMemory(param_2,&local_250,4);
  FUN_c013331c(local_30);
  return uVar3;
}



/* c0111aa4 FUN_c0111aa4 */

/* Boundary evidence: original MIPS .pdata c0111aa4..c0111aaf. Semantic name remains unreviewed. */

undefined4 FUN_c0111aa4(void)

{
  return 1;
}



/* c0111ab0 FUN_c0111ab0 */

undefined4 * FUN_c0111ab0(void)

{
  return &DAT_c01391e0;
}



/* c0111abc FUN_c0111abc */

/* Boundary evidence: original MIPS .pdata c0111abc..c0111c93. Semantic name remains unreviewed. */

undefined4 FUN_c0111abc(HANDLE param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  int iVar3;
  uint lDistanceToMove;
  int iVar4;
  uint local_28;
  DWORD local_24;
  
  DVar1 = SetFilePointer(param_1,0,(PLONG)0x0,2);
  SetFilePointer(param_1,0,(PLONG)0x0,0);
  BVar2 = ReadFile(param_1,&local_28,4,&local_24,(LPOVERLAPPED)0x0);
  if (((((BVar2 != 0) && (local_24 == 4)) && (local_28 == 0x1d8374b2)) &&
      ((BVar2 = ReadFile(param_1,&local_28,4,&local_24,(LPOVERLAPPED)0x0), BVar2 != 0 &&
       (local_24 == 4)))) && (local_28 == DVar1)) {
    iVar4 = DVar1 - 8;
    iVar3 = ReadFile(param_1,&local_28,4,&local_24,(LPOVERLAPPED)0x0);
    while ((iVar3 != 0 && (local_24 == 4))) {
      if (local_28 >> 0x10 == 0) {
        return 0;
      }
      if (2 < local_28 >> 0x10) {
        return 0;
      }
      lDistanceToMove = local_28 & 0xffff;
      if (0x2202 < lDistanceToMove) {
        return 0;
      }
      if (iVar4 - 4U < lDistanceToMove) {
        return 0;
      }
      SetFilePointer(param_1,lDistanceToMove,(PLONG)0x0,1);
      iVar4 = (iVar4 - (local_28 & 0xffff)) + -4;
      iVar3 = ReadFile(param_1,&local_28,4,&local_24,(LPOVERLAPPED)0x0);
    }
    if (iVar4 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c0111c94 FUN_c0111c94 */

/* Boundary evidence: original MIPS .pdata c0111c94..c0111d3f. Semantic name remains unreviewed. */

void FUN_c0111c94(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  while ((uVar2 != 0 && (puVar1 = (uint *)FUN_c0101c94(-0x3fec6e20,*param_1), puVar1 != (uint *)0x0)
         )) {
    FUN_c010297c(-0x3fec6e20);
    uVar2 = *puVar1;
    FUN_c01037f0(&DAT_c01391e0,*param_1);
    FUN_c01029e4(-0x3fec6e20,1,param_1,*param_1,4);
    *param_1 = uVar2;
    FUN_c0102aa4(&DAT_c01391e0);
    uVar2 = *param_1;
  }
  return;
}



/* c0111d40 FUN_c0111d40 */

/* Boundary evidence: original MIPS .pdata c0111d40..c0111e27. Semantic name remains unreviewed. */

void FUN_c0111d40(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  
  if ((*param_1 != 0) &&
     (puVar1 = (uint *)FUN_c0101c94(-0x3fec6e20,*param_1), puVar1 != (uint *)0x0)) {
    FUN_c0111d40(puVar1);
    iVar2 = FUN_c0106ad8((int)puVar1);
    if (iVar2 == 0) {
      if ((*(byte *)((int)puVar1 + 0xe) & 8) == 8) {
        FUN_c0107218(1,(int)puVar1);
      }
      else {
        FUN_c0111c94(puVar1 + 2);
        FUN_c0111d40(puVar1 + 1);
      }
    }
    FUN_c010297c(-0x3fec6e20);
    FUN_c01037f0(&DAT_c01391e0,*param_1);
    FUN_c01029e4(-0x3fec6e20,1,param_1,*param_1,4);
    *param_1 = 0;
    FUN_c0102aa4(&DAT_c01391e0);
  }
  return;
}



/* c0111e28 FUN_c0111e28 */

/* Boundary evidence: original MIPS .pdata c0111e28..c0111ec7. Semantic name remains unreviewed. */

BOOL FUN_c0111e28(HANDLE param_1,LPVOID param_2,DWORD param_3,LPDWORD param_4)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  
  iVar1 = DAT_c0136d20;
  DAT_c0136d20 = 0;
  if (param_1 == (HANDLE)0xffffffff) {
    BVar2 = 1;
    DVar3 = (*DAT_c0136d24)(iVar1 != 0);
    *param_4 = DVar3;
    if ((DVar3 == 0) || (DVar3 == 0xffffffff)) {
      BVar2 = 0;
    }
  }
  else {
    BVar2 = ReadFile(param_1,param_2,param_3,param_4,(LPOVERLAPPED)0x0);
  }
  return BVar2;
}



/* c0111ec8 FUN_c0111ec8 */

/* Boundary evidence: original MIPS .pdata c0111ec8..c0112023. Semantic name remains unreviewed. */

undefined4 FUN_c0111ec8(int param_1,HANDLE param_2,LPCVOID param_3,uint param_4,uint param_5)

{
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_28 [2];
  
  iVar2 = DAT_c0136d20;
  DAT_c0136d20 = 0;
  if (param_5 != 0) {
    param_5 = param_5 << 0x10 | param_4 & 0xffff;
    if (param_1 == 0) {
      BVar1 = WriteFile(param_2,&param_5,4,local_28,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        return 0;
      }
      if (local_28[0] != 4) {
        return 0;
      }
      goto LAB_c0111f9c;
    }
    iVar2 = (*DAT_c0136d28)(iVar2 != 0,&param_5,4);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = 0;
  }
  if (param_1 != 0) {
    uVar3 = (*DAT_c0136d28)(iVar2 != 0,param_3,param_4);
    return uVar3;
  }
LAB_c0111f9c:
  BVar1 = WriteFile(param_2,param_3,param_4,local_28,(LPOVERLAPPED)0x0);
  if ((BVar1 != 0) && (local_28[0] == param_4)) {
    return 1;
  }
  return 0;
}



/* c0112024 FUN_c0112024 */

/* Boundary evidence: original MIPS .pdata c0112024..c011230b. Semantic name remains unreviewed. */

undefined4 FUN_c0112024(HANDLE param_1,int param_2)

{
  wchar_t *hMem;
  uint *puVar1;
  BOOL BVar2;
  uint uVar3;
  wchar_t *pwVar4;
  LPDWORD pDVar5;
  int iVar6;
  undefined4 uVar7;
  uint *local_38;
  DWORD local_34;
  uint local_30;
  int iStack_2c;
  
  local_38 = (uint *)0x0;
  uVar7 = 0;
  hMem = LocalAlloc(0,0x2202);
  if (hMem == (wchar_t *)0x0) {
    uVar7 = 0;
  }
  else {
    DAT_c0136cec = 0;
    if (param_2 != 0) {
      if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
        puVar1 = (uint *)0x0;
      }
      else {
        puVar1 = (uint *)FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
      }
      if (puVar1 != (uint *)0x0) {
        iVar6 = 4;
        do {
          FUN_c0111c94(puVar1 + 4);
          FUN_c0111d40(puVar1);
          puVar1 = puVar1 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
    DAT_c0136d20 = 1;
    if (param_1 != (HANDLE)0xffffffff) {
      SetFilePointer(param_1,8,(PLONG)0x0,0);
    }
    pDVar5 = &local_34;
    uVar3 = 4;
    puVar1 = &local_30;
    local_34 = 0;
    BVar2 = FUN_c0111e28(param_1,puVar1,4,pDVar5);
    if (BVar2 != 0) {
      while ((local_34 == 4 && (uVar3 = local_30 & 0xffff, uVar3 < 0x2202))) {
        pDVar5 = &local_34;
        pwVar4 = hMem;
        BVar2 = FUN_c0111e28(param_1,hMem,uVar3,pDVar5);
        if ((BVar2 == 0) || (local_34 != (local_30 & 0xffff))) {
LAB_c01122f4:
          if (local_38 != (uint *)0x0) {
LAB_c01122fc:
            FUN_c0108f80(local_38,pwVar4,uVar3,pDVar5);
          }
          goto LAB_c01122b4;
        }
        if (local_30 >> 0x10 != 1) {
          if (local_30 >> 0x10 != 2) goto LAB_c01122f4;
          pDVar5 = (LPDWORD)(uint)(ushort)*hMem;
          pwVar4 = hMem + 3;
          uVar3 = 0;
          iVar6 = FUN_c010ba94(local_38,pwVar4,0,(uint)pDVar5,hMem + (byte)hMem[1] + 3,
                               (uint)(ushort)hMem[2]);
          if (iVar6 == 0) goto LAB_c011226c;
          goto LAB_c01122fc;
        }
        if (local_38 != (uint *)0x0) {
          FUN_c0108f80(local_38,pwVar4,uVar3,pDVar5);
        }
        if ((byte)hMem[1] == 0) {
          local_38 = (uint *)((byte)*hMem + 0x80000000);
        }
        else {
          if (*(byte *)((int)hMem + 3) == 0) {
            pwVar4 = (wchar_t *)0x0;
          }
          else {
            pwVar4 = hMem + (byte)hMem[1] + 2;
          }
          iVar6 = FUN_c010b2c4((undefined4 *)((byte)*hMem + 0x80000000),hMem + 2,0,pwVar4,0,0,0,
                               &local_38,&iStack_2c);
          if (iVar6 != 0) goto LAB_c01122b4;
        }
LAB_c011226c:
        pDVar5 = &local_34;
        uVar3 = 4;
        puVar1 = &local_30;
        BVar2 = FUN_c0111e28(param_1,puVar1,4,pDVar5);
        if (BVar2 == 0) break;
      }
    }
    if (local_38 != (uint *)0x0) {
      FUN_c0108f80(local_38,puVar1,uVar3,pDVar5);
    }
    if ((param_1 != (HANDLE)0xffffffff) || (local_34 != 0xffffffff)) {
      uVar7 = 1;
    }
LAB_c01122b4:
    LocalFree(hMem);
    DAT_c0136cec = 1;
  }
  return uVar7;
}



/* c011230c FUN_c011230c */

/* Boundary evidence: original MIPS .pdata c011230c..c01123f7. Semantic name remains unreviewed. */

undefined4 FUN_c011230c(LPCWSTR param_1)

{
  DWORD DVar1;
  HANDLE hObject;
  int iVar2;
  undefined4 uVar3;
  
  DVar1 = GetFileAttributesW(param_1);
  if (((DVar1 != 0xffffffff) && ((DVar1 & 4) != 0)) &&
     (hObject = CreateFileW(param_1,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0),
     hObject != (HANDLE)0xffffffff)) {
    iVar2 = FUN_c0111abc(hObject);
    uVar3 = 1;
    if ((iVar2 != 0) && (iVar2 = FUN_c0112024(hObject,1), iVar2 != 0)) {
      uVar3 = 0;
    }
    CloseHandle(hObject);
    DeleteFileW(param_1);
    return uVar3;
  }
  return 2;
}



/* c01123f8 FUN_c01123f8 */

/* Boundary evidence: original MIPS .pdata c01123f8..c0112597. Semantic name remains unreviewed. */

BOOL FUN_c01123f8(wchar_t *param_1)

{
  int iVar1;
  DWORD DVar2;
  BOOL BVar3;
  
  BVar3 = 0;
  if (param_1 == (wchar_t *)0x0) {
    iVar1 = (*DAT_c0136d2c)(3);
    if (iVar1 != 0) {
      FUN_c0112024((HANDLE)0xffffffff,0);
      (*DAT_c0136d2c)(4);
    }
  }
  else {
    iVar1 = _wcsicmp(param_1,L"\\Windows\\Restore.fdf");
    if (iVar1 == 0) {
      BVar3 = 1;
    }
    else {
      BVar3 = MoveFileW(param_1,L"\\Windows\\Restore.fdf");
      if ((BVar3 != 0) ||
         ((BVar3 = CopyFileW(param_1,L"\\Windows\\Restore.fdf",0), BVar3 != 0 &&
          (DeleteFileW(param_1), BVar3 != 0)))) {
        DVar2 = GetFileAttributesW(L"\\Windows\\Restore.fdf");
        SetFileAttributesW(L"\\Windows\\Restore.fdf",DVar2 & 0xfffffffe | 4);
      }
    }
  }
  return BVar3;
}



/* c0112598 FUN_c0112598 */

/* Boundary evidence: original MIPS .pdata c0112598..c01125a3. Semantic name remains unreviewed. */

undefined4 FUN_c0112598(void)

{
  return 1;
}



/* c01125a4 FUN_c01125a4 */

/* Boundary evidence: original MIPS .pdata c01125a4..c0112633. Semantic name remains unreviewed. */

BOOL FUN_c01125a4(int param_1)

{
  int iVar1;
  BOOL BVar2;
  wchar_t *local_18 [2];
  
  local_18[0] = (wchar_t *)0x0;
  if ((param_1 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_18,param_1,0,5), -1 < iVar1)) {
    BVar2 = FUN_c01123f8(local_18[0]);
    CeFreeDuplicateBuffer(local_18[0],param_1,0,5);
  }
  else {
    SetLastError(0xe);
    BVar2 = 0;
  }
  return BVar2;
}



/* c0112634 FUN_c0112634 */

/* Boundary evidence: original MIPS .pdata c0112634..c011275b. Semantic name remains unreviewed. */

undefined4 FUN_c0112634(int param_1,HANDLE param_2,undefined2 *param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  
  while ((param_4 != 0 &&
         (puVar1 = (uint *)FUN_c0101c94(-0x3fec6e20,param_4), puVar1 != (uint *)0x0))) {
    *param_3 = (short)puVar1[1];
    *(char *)(param_3 + 1) = (char)puVar1[2] + '\x01';
    param_3[2] = *(undefined2 *)((int)puVar1 + 6);
    memcpy(param_3 + 3,(void *)((int)puVar1 + 10),(uint)(byte)puVar1[2] << 1);
    param_3[(byte)puVar1[2] + 3] = 0;
    memcpy(param_3 + *(byte *)(param_3 + 1) + 3,(void *)(((byte)puVar1[2] + 5) * 2 + (int)puVar1),
           (uint)*(ushort *)((int)puVar1 + 6));
    iVar2 = FUN_c0111ec8(param_1,param_2,param_3,
                         (*(byte *)(param_3 + 1) + 3) * 2 + (uint)(ushort)param_3[2],2);
    if (iVar2 == 0) {
      return 0;
    }
    param_4 = *puVar1;
  }
  return 1;
}



/* c011275c FUN_c011275c */

/* Boundary evidence: original MIPS .pdata c011275c..c0112a3b. Semantic name remains unreviewed. */

undefined4
FUN_c011275c(int param_1,HANDLE param_2,undefined2 *param_3,undefined4 param_4,void *param_5,
            ushort param_6,uint param_7)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  
  if (param_7 != 0) {
    uVar5 = (uint)param_6;
    do {
      puVar1 = (uint *)FUN_c0101c94(-0x3fec6e20,param_7);
      if (puVar1 == (uint *)0x0) {
        return 1;
      }
      if ((*(byte *)((int)puVar1 + 0xe) & 8) == 0) {
        if ((puVar1[1] == 0) || (puVar1[2] != 0)) {
          *(char *)param_3 = (char)param_4;
          if (uVar5 == 0) {
            *(char *)(param_3 + 1) = (char)puVar1[3] + '\x01';
            memcpy(param_3 + 2,puVar1 + 4,(uint)(byte)puVar1[3] << 1);
            param_3[(byte)puVar1[3] + 2] = 0;
          }
          else {
            *(char *)(param_3 + 1) = (char)puVar1[3] + (char)param_6 + '\x02';
            memcpy(param_3 + 2,param_5,uVar5 << 1);
            param_3[uVar5 + 2] = 0x5c;
            memcpy(param_3 + uVar5 + 3,puVar1 + 4,(uint)(byte)puVar1[3] << 1);
            param_3[(byte)puVar1[3] + uVar5 + 3] = 0;
          }
          if (*(char *)((int)puVar1 + 0xd) == '\0') {
            *(undefined1 *)((int)param_3 + 3) = 0;
          }
          else {
            *(char *)((int)param_3 + 3) = *(char *)((int)puVar1 + 0xd) + '\x01';
            memcpy(param_3 + *(byte *)(param_3 + 1) + 2,
                   (void *)(((byte)puVar1[3] + 8) * 2 + (int)puVar1),
                   (uint)*(byte *)((int)puVar1 + 0xd));
            param_3[(uint)*(byte *)((int)puVar1 + 0xd) + (uint)*(byte *)(param_3 + 1) + 2] = 0;
          }
          iVar2 = FUN_c0111ec8(param_1,param_2,param_3,
                               ((uint)*(byte *)((int)param_3 + 3) + (uint)*(byte *)(param_3 + 1) + 2
                               ) * 2,1);
          if (iVar2 == 0) {
            return 0;
          }
          if ((puVar1[2] != 0) &&
             (iVar2 = FUN_c0112634(param_1,param_2,param_3,puVar1[2]), iVar2 == 0)) {
            return 0;
          }
        }
        if (uVar5 == 0) {
          memcpy(param_5,puVar1 + 4,(uint)(byte)puVar1[3] << 1);
          uVar3 = (uint)(byte)puVar1[3];
        }
        else {
          puVar4 = (undefined2 *)(uVar5 * 2 + (int)param_5);
          *puVar4 = 0x5c;
          memcpy(puVar4 + 1,puVar1 + 4,(uint)(byte)puVar1[3] << 1);
          uVar3 = (byte)puVar1[3] + uVar5 + 1 & 0xffff;
        }
        *(undefined2 *)(uVar3 * 2 + (int)param_5) = 0;
        if ((puVar1[1] != 0) &&
           (iVar2 = FUN_c011275c(param_1,param_2,param_3,param_4,param_5,(ushort)uVar3,puVar1[1]),
           iVar2 == 0)) {
          return 0;
        }
      }
      param_7 = *puVar1;
    } while (param_7 != 0);
  }
  return 1;
}



/* c0112a3c FUN_c0112a3c */

/* Boundary evidence: original MIPS .pdata c0112a3c..c0112ce7. Semantic name remains unreviewed. */

undefined4 FUN_c0112a3c(int param_1,HANDLE param_2)

{
  uint uVar1;
  undefined2 *hMem;
  HLOCAL hMem_00;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  undefined4 uVar5;
  DWORD local_30 [2];
  
  uVar5 = 0;
  if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
  }
  if ((uVar1 == 0) || (hMem = LocalAlloc(0,0x2202), hMem == (undefined2 *)0x0)) {
    return 0;
  }
  hMem_00 = LocalAlloc(0,0x2000);
  if (hMem_00 == (HLOCAL)0x0) {
    uVar5 = 0;
    goto LAB_c0112cb0;
  }
  local_30[0] = 0x1d8374b2;
  DAT_c0136d20 = 1;
  if ((param_1 != 0) ||
     ((iVar2 = FUN_c0111ec8(0,param_2,local_30,4,0), iVar2 != 0 &&
      (DVar3 = SetFilePointer(param_2,4,(PLONG)0x0,1), DVar3 != 0xffffffff)))) {
    local_30[0] = 0;
    do {
      if (*(int *)((local_30[0] + 4) * 4 + uVar1) != 0) {
        *(char *)hMem = (char)local_30[0];
        *(undefined1 *)(hMem + 1) = 0;
        *(undefined1 *)((int)hMem + 3) = 0;
        iVar2 = FUN_c0111ec8(param_1,param_2,hMem,4,1);
        if ((iVar2 == 0) ||
           (iVar2 = FUN_c0112634(param_1,param_2,hMem,*(uint *)((local_30[0] + 4) * 4 + uVar1)),
           iVar2 == 0)) goto LAB_c0112c20;
      }
      uVar4 = *(uint *)(local_30[0] * 4 + uVar1);
      if (((uVar4 != 0) &&
          (iVar2 = FUN_c011275c(param_1,param_2,hMem,local_30[0],hMem_00,0,uVar4), iVar2 == 0)) ||
         (local_30[0] = local_30[0] + 1, 3 < local_30[0])) goto LAB_c0112c20;
    } while( true );
  }
LAB_c0112ca8:
  LocalFree(hMem_00);
LAB_c0112cb0:
  LocalFree(hMem);
  return uVar5;
LAB_c0112c20:
  if (local_30[0] == 4) {
    if (param_1 == 0) {
      local_30[0] = SetFilePointer(param_2,0,(PLONG)0x0,2);
      SetFilePointer(param_2,4,(PLONG)0x0,0);
      iVar2 = FUN_c0111ec8(0,param_2,local_30,4,0);
      if (iVar2 == 0) goto LAB_c0112ca8;
    }
    else {
      FUN_c0111ec8(param_1,param_2,(LPCVOID)0x0,0,0);
    }
    uVar5 = 1;
  }
  goto LAB_c0112ca8;
}



/* c0112ce8 FUN_c0112ce8 */

/* Boundary evidence: original MIPS .pdata c0112ce8..c0112e33. Semantic name remains unreviewed. */

int FUN_c0112ce8(LPCWSTR param_1)

{
  HANDLE hObject;
  int iVar1;
  
  iVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  hObject = CreateFileW(param_1,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,4,(HANDLE)0x0);
  if (hObject != (HANDLE)0xffffffff) {
    iVar1 = FUN_c0112a3c(0,hObject);
    CloseHandle(hObject);
    if (iVar1 == 0) {
      DeleteFileW(param_1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return iVar1;
}



/* c0112e34 FUN_c0112e34 */

/* Boundary evidence: original MIPS .pdata c0112e34..c0112e3f. Semantic name remains unreviewed. */

undefined4 FUN_c0112e34(void)

{
  return 1;
}



/* c0112e40 FUN_c0112e40 */

/* Boundary evidence: original MIPS .pdata c0112e40..c0112e4b. Semantic name remains unreviewed. */

undefined4 FUN_c0112e40(void)

{
  return 1;
}



/* c0112e4c FUN_c0112e4c */

/* Boundary evidence: original MIPS .pdata c0112e4c..c0112edb. Semantic name remains unreviewed. */

int FUN_c0112e4c(int param_1)

{
  int iVar1;
  LPCWSTR local_18 [2];
  
  local_18[0] = (LPCWSTR)0x0;
  if ((param_1 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_18,param_1,0,5), -1 < iVar1)) {
    iVar1 = FUN_c0112ce8(local_18[0]);
    CeFreeDuplicateBuffer(local_18[0],param_1,0,5);
  }
  else {
    SetLastError(0xe);
    iVar1 = 0;
  }
  return iVar1;
}



/* c0112edc FUN_c0112edc */

/* Boundary evidence: original MIPS .pdata c0112edc..c01131a7. Semantic name remains unreviewed. */

undefined4 FUN_c0112edc(undefined4 param_1,ushort *param_2)

{
  bool bVar1;
  bool bVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined1 auStack_30 [8];
  
  DAT_c0136d24 = ReadRegistryFromOEM;
  bVar2 = false;
  bVar1 = false;
  DAT_c0136d28 = &LAB_c01312ec;
  FUN_c00fc4fc(L"+prgInitRegistry");
  if (DAT_c01391a8 == 0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c01391a0);
  }
  FUN_c0106d10();
  if (*(uint *)(DAT_c01391e8 + 0xf0) == 0xffffffff) {
    FUN_c010297c(-0x3fec6e20);
    puVar3 = FUN_c0103dc8(&DAT_c01391e0,0xb,0x24,0,0);
    FUN_c0102aa4(&DAT_c01391e0);
    if (puVar3 != (uint *)0x0) {
      puVar6 = puVar3 + 0xb;
      puVar3[6] = 0;
      puVar3[5] = 0;
      puVar3[4] = 0;
      puVar3[3] = 0;
      puVar3[10] = 0;
      puVar3[9] = 0;
      puVar3[8] = 0;
      puVar3[7] = 0;
      *puVar6 = 1;
      *(uint *)(DAT_c01391e8 + 0xf0) = puVar3[2];
      DAT_c0136ca8 = 1;
LAB_c0113100:
      do {
        FUN_c00fc4fc(L"Restore registry from default.fdf");
        iVar5 = FUN_c011230c(L"\\Windows\\Default.fdf");
        if (iVar5 == 1) {
          return 0;
        }
LAB_c0113054:
        DAT_c0136ce4 = *puVar6;
        DAT_c0136ca8 = 1;
        FUN_c00fc4fc(L"Restore registry from OEM");
        if ((!bVar1) && (iVar5 = (*DAT_c0136d24)(1,auStack_30,4), iVar5 == 4)) {
          bVar1 = true;
          iVar5 = FUN_c0112024((HANDLE)0xffffffff,1);
          if (iVar5 == 0) goto LAB_c0113100;
        }
        FUN_c00fe7dc();
        FUN_c00fc4fc(L"Restore registry from restore.fdf");
        if (bVar2) goto LAB_c0113124;
        bVar1 = false;
        bVar2 = true;
        iVar5 = FUN_c011230c(L"\\Windows\\Restore.fdf");
        if (iVar5 != 1) {
LAB_c0113124:
          FUN_c00fc4fc(L"Kernel registry init");
          KernelIoControl(0x10100b0,0,0,0,0,0);
          FUN_c00fc4fc(L"-prgInitRegistry");
          InitLocale();
          *param_2 = *param_2 | 4;
          FUN_c00fe7dc();
          return 1;
        }
      } while( true );
    }
  }
  else {
    uVar4 = FUN_c0101c94(-0x3fec6e20,*(uint *)(DAT_c01391e8 + 0xf0));
    if (uVar4 != 0) {
      puVar6 = (uint *)(uVar4 + 0x20);
      *puVar6 = *puVar6 + 1;
      goto LAB_c0113054;
    }
  }
  return 0;
}



/* c01131a8 FUN_c01131a8 */

undefined4 FUN_c01131a8(void)

{
  return 0x32;
}



/* c01131b0 FUN_c01131b0 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c01131b0..c01132cf. Semantic name remains unreviewed. */

undefined4 FUN_c01131b0(wchar_t *param_1,uint param_2)

{
  uint uVar1;
  size_t _Count;
  short *psVar2;
  short sStack_22a;
  undefined1 auStack_228 [520];
  uint local_20;
  
  local_20 = DAT_c0136c78;
  uVar1 = FUN_c00fd714((LPCWSTR)auStack_228,0x104,(LPDWORD)L"init\\BootVars",L"SystemHive",
                       L"Windows\\",1,0);
  if (uVar1 != 0) {
    _Count = wcslen((wchar_t *)auStack_228);
    if (_Count != 0) {
      psVar2 = &sStack_22a + _Count;
      do {
        if ((*psVar2 == 0x5c) || (*psVar2 == 0x2f)) break;
        _Count = _Count - 1;
        psVar2 = psVar2 + -1;
      } while (_Count != 0);
    }
    if (_Count + 1 <= param_2) {
      wcsncpy(param_1,(wchar_t *)auStack_228,_Count);
      param_1[_Count] = L'\0';
      FUN_c013331c(local_20);
      return 1;
    }
  }
  FUN_c013331c(local_20);
  return 0;
}



/* c01132d0 FUN_c01132d0 */

/* Boundary evidence: original MIPS .pdata c01132d0..c011330b. Semantic name remains unreviewed. */

void FUN_c01132d0(LPCWSTR param_1,uint param_2)

{
  FUN_c00fd714(param_1,param_2,(LPDWORD)L"init\\BootVars",L"ProfileDir",L"\\profiles\\",0,0);
  return;
}



/* c011330c FUN_c011330c */

/* Boundary evidence: original MIPS .pdata c011330c..c0113343. Semantic name remains unreviewed. */

undefined4 FUN_c011330c(void)

{
  FUN_c00fc4fc(L"Finalize Registry");
  FUN_c0109380();
  DAT_c0136cec = 1;
  return 1;
}



/* c0113344 FUN_c0113344 */

/* Boundary evidence: original MIPS .pdata c0113344..c011352f. Semantic name remains unreviewed. */

undefined4 FUN_c0113344(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x57;
  iVar1 = FUN_c0106be8((uint)param_1);
  if (iVar1 != 0) {
    if ((DAT_c0136ce8 == 0) ||
       ((DAT_c0136ce8 = 0, DAT_c0136d2c != (code *)0x0 && (iVar1 = (*DAT_c0136d2c)(1), iVar1 == 0)))
       ) {
      uVar2 = 0;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      if (DAT_c0136cf0 != 0) {
        SetEventData(DAT_c0136cf0,0);
      }
      if ((((uint *)0x7fffffff < param_1) && (param_1 < (uint *)0x80000004)) ||
         (((uint *)*param_1 == param_1 && ((char)param_1[2] == -0xb)))) {
        iVar1 = (*DAT_c0136d28)(0x80000000,0,0);
        if (iVar1 == 0) {
          uVar2 = 0x32;
        }
        else {
          iVar1 = FUN_c0112a3c(1,(HANDLE)0x0);
          if (iVar1 != 0) {
            uVar2 = 0;
          }
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
      if (DAT_c0136d2c != (code *)0x0) {
        (*DAT_c0136d2c)(2);
      }
    }
  }
  return uVar2;
}



/* c0113530 FUN_c0113530 */

/* Boundary evidence: original MIPS .pdata c0113530..c011353b. Semantic name remains unreviewed. */

undefined4 FUN_c0113530(void)

{
  return 1;
}



/* c011353c FUN_c011353c */

/* Boundary evidence: original MIPS .pdata c011353c..c0113547. Semantic name remains unreviewed. */

undefined4 FUN_c011353c(void)

{
  return 1;
}



/* c0113548 FUN_c0113548 */

/* Boundary evidence: original MIPS .pdata c0113548..c0113803. Semantic name remains unreviewed. */

DWORD FUN_c0113548(int param_1,uint param_2,int param_3,void *param_4,uint *param_5)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [96];
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [20];
  uint local_24;
  
  uVar3 = DAT_c0136c78;
  local_24 = DAT_c0136c78;
  if (param_1 != 0) {
    if ((param_2 < 8) || (param_3 != 1)) {
      FUN_c013331c(DAT_c0136c78);
      return 0x80070057;
    }
    if (param_5 != (uint *)0x0) {
      uVar4 = *param_5;
      if (param_4 == (void *)0x0) {
        *param_5 = 0x14;
        FUN_c013331c(uVar3);
        return 0;
      }
      *param_5 = 0;
      local_b0 = 0x107;
      iVar1 = KernelIoControl(0x1010004,&local_b0,4,auStack_48,0x10,&local_ac,param_4,param_5,uVar4)
      ;
      if (iVar1 == 0) {
        DVar2 = GetLastError();
        if ((int)DVar2 < 1) {
          DVar2 = GetLastError();
        }
        else {
          DVar2 = GetLastError();
          DVar2 = DVar2 & 0xffff | 0x80070000;
        }
        FUN_c013331c(local_24);
        return DVar2;
      }
      A_SHAInit(auStack_a8);
      A_SHAUpdate(auStack_a8,auStack_48,local_ac);
      A_SHAUpdate(auStack_a8,param_1,param_2);
      A_SHAFinal(auStack_a8,auStack_38);
      DVar2 = 0;
      if (uVar4 < 0x14) {
        DVar2 = 0x8007007a;
        uVar3 = uVar4;
      }
      else {
        uVar3 = 0x14;
      }
      memcpy(param_4,auStack_38,uVar3);
      if (0x13 < uVar4) {
        uVar4 = 0x14;
      }
      *param_5 = uVar4;
      FUN_c013331c(local_24);
      return DVar2;
    }
  }
  FUN_c013331c(DAT_c0136c78);
  return 0x80004003;
}



/* c0113804 FUN_c0113804 */

/* Boundary evidence: original MIPS .pdata c0113804..c011380f. Semantic name remains unreviewed. */

undefined4 FUN_c0113804(void)

{
  return 1;
}



/* c0113810 FUN_c0113810 */

/* Boundary evidence: original MIPS .pdata c0113810..c011381b. Semantic name remains unreviewed. */

undefined4 FUN_c0113810(void)

{
  return 1;
}



/* c011381c FUN_c011381c */

/* Boundary evidence: original MIPS .pdata c011381c..c01138a3. Semantic name remains unreviewed. */

void FUN_c011381c(int param_1,uint param_2,int param_3,void *param_4,uint param_5,uint *param_6)

{
  DWORD DVar1;
  uint local_10 [2];
  
  local_10[0] = param_5;
  DVar1 = FUN_c0113548(param_1,param_2,param_3,param_4,local_10);
  if ((-1 < (int)DVar1) || (DVar1 == 0x8007007a)) {
    *param_6 = local_10[0];
  }
  return;
}



/* c01138a4 FUN_c01138a4 */

/* Boundary evidence: original MIPS .pdata c01138a4..c01138af. Semantic name remains unreviewed. */

undefined4 FUN_c01138a4(void)

{
  return 1;
}



/* c01138b0 FUN_c01138b0 */

/* Boundary evidence: original MIPS .pdata c01138b0..c011390f. Semantic name remains unreviewed. */

undefined * FUN_c01138b0(void)

{
  if ((DAT_c0136d48 & 1) == 0) {
    DAT_c0136d48 = DAT_c0136d48 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d34);
    FUN_c0133624(FUN_c0133a64);
  }
  return &DAT_c0136d34;
}



/* c0113910 FUN_c0113910 */

/* Boundary evidence: original MIPS .pdata c0113910..c0113967. Semantic name remains unreviewed. */

undefined4
FUN_c0113910(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 *puVar1;
  
  if (param_2 == 0x8004) {
    puVar1 = LocalAlloc(0x40,0x60);
    *param_5 = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0x8004;
      A_SHAInit(puVar1 + 1);
      return 1;
    }
  }
  return 0;
}



/* c0113968 FUN_c0113968 */

/* Boundary evidence: original MIPS .pdata c0113968..c01139a7. Semantic name remains unreviewed. */

undefined4 FUN_c0113968(int *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0x8004)) {
    uVar1 = 0;
  }
  else {
    A_SHAUpdate(param_1 + 1);
    uVar1 = 1;
  }
  return uVar1;
}



/* c01139a8 FUN_c01139a8 */

/* Boundary evidence: original MIPS .pdata c01139a8..c0113a5b. Semantic name remains unreviewed. */

bool FUN_c01139a8(int *param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  bool bVar1;
  
  bVar1 = false;
  if (((param_1 == (int *)0x0) || (param_4 == (uint *)0x0)) || (param_3 == (undefined4 *)0x0)) {
    bVar1 = false;
  }
  else if (*param_1 == 0x8004) {
    if (param_2 == 2) {
      bVar1 = 0x13 < *param_4;
      if (bVar1) {
        A_SHAFinal(param_1 + 1,param_3);
      }
      *param_4 = 0x14;
    }
    else if (param_2 == 4) {
      bVar1 = 3 < *param_4;
      if (bVar1) {
        *param_3 = 0x14;
      }
      *param_4 = 4;
    }
  }
  return bVar1;
}



/* c0113a5c FUN_c0113a5c */

/* Boundary evidence: original MIPS .pdata c0113a5c..c0113ab3. Semantic name remains unreviewed. */

undefined4 FUN_c0113a5c(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    if (*param_1 == 0x8004) {
      iVar2 = 0x60;
      piVar3 = param_1;
      do {
        *(undefined1 *)piVar3 = 0;
        iVar2 = iVar2 + -1;
        piVar3 = (int *)((int)piVar3 + 1);
      } while (iVar2 != 0);
    }
    LocalFree(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* c0113ab4 FUN_c0113ab4 */

/* Boundary evidence: original MIPS .pdata c0113ab4..c0113b33. Semantic name remains unreviewed. */

undefined4 * FUN_c0113ab4(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  
  if ((param_1 == 0x6801) && (0xf < param_3)) {
    puVar1 = LocalAlloc(0x40,0x106);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0x6801;
      FUN_c01314cc(puVar1 + 1,0x10,param_2);
    }
  }
  else {
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}



/* c0113b34 FUN_c0113b34 */

/* Boundary evidence: original MIPS .pdata c0113b34..c0113be7. Semantic name remains unreviewed. */

bool FUN_c0113b34(undefined4 param_1,int param_2,int *param_3,undefined4 param_4,undefined4 *param_5
                 )

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint local_30 [2];
  undefined4 local_28 [5];
  uint local_14;
  
  local_14 = DAT_c0136c78;
  if (param_2 == 0x6801) {
    iVar4 = 0x14;
    local_30[0] = 0x14;
    bVar1 = FUN_c01139a8(param_3,2,local_28,local_30);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      puVar2 = FUN_c0113ab4(0x6801,(int)local_28,local_30[0]);
      *param_5 = puVar2;
      puVar3 = local_28;
      do {
        *(undefined1 *)puVar3 = 0;
        iVar4 = iVar4 + -1;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      } while (iVar4 != 0);
      FUN_c013331c(local_14);
      return puVar2 != (undefined4 *)0x0;
    }
  }
  FUN_c013331c(local_14);
  return false;
}



/* c0113be8 FUN_c0113be8 */

/* Boundary evidence: original MIPS .pdata c0113be8..c0113c37. Semantic name remains unreviewed. */

undefined4 FUN_c0113be8(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if (*param_1 == 0x6801) {
    iVar2 = 0x106;
    piVar3 = param_1;
    do {
      *(undefined1 *)piVar3 = 0;
      iVar2 = iVar2 + -1;
      piVar3 = (int *)((int)piVar3 + 1);
    } while (iVar2 != 0);
    LocalFree(param_1);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0113c38 FUN_c0113c38 */

/* Boundary evidence: original MIPS .pdata c0113c38..c0113ca7. Semantic name remains unreviewed. */

undefined4
FUN_c0113c38(undefined4 param_1,int *param_2,int param_3,undefined4 param_4,int param_5,
            byte *param_6,int *param_7)

{
  undefined4 uVar1;
  
  if ((((param_2 == (int *)0x0) || (*param_2 != 0x6801)) || (param_3 != 0)) || (param_5 != 0)) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    FUN_c0131560((int)(param_2 + 1),*param_7,param_6);
    uVar1 = 1;
  }
  return uVar1;
}



/* c0113ca8 FUN_c0113ca8 */

/* Boundary evidence: original MIPS .pdata c0113ca8..c0113cdf. Semantic name remains unreviewed. */

void FUN_c0113ca8(undefined4 param_1,int *param_2,int param_3,undefined4 param_4,int param_5,
                 byte *param_6,int *param_7)

{
  FUN_c0113c38(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* c0113ce0 FUN_c0113ce0 */

/* Boundary evidence: original MIPS .pdata c0113ce0..c0113d53. Semantic name remains unreviewed. */

void FUN_c0113ce0(int *param_1,void *param_2,uint param_3)

{
  uint _Size;
  
  _Size = 0x3c - *param_1;
  if (_Size != 0) {
    if (param_3 <= _Size) {
      _Size = param_3;
    }
    memcpy((void *)((int)param_1 + *param_1 + 4),param_2,_Size);
    *param_1 = *param_1 + _Size;
  }
  return;
}



/* c0113d54 FUN_c0113d54 */

/* Boundary evidence: original MIPS .pdata c0113d54..c0113dfb. Semantic name remains unreviewed. */

void FUN_c0113d54(LPBYTE param_1)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14;
  DWORD DStack_10;
  DWORD DStack_c;
  
  local_14 = 0x14;
  local_18 = (HKEY)0x0;
  LVar1 = RegCreateKeyExW((HKEY)&DAT_80000002,L"Comm\\Security\\Crypto",0,(LPWSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_18,&DStack_10);
  if (LVar1 == 0) {
    RegQueryValueExW(local_18,L"Seed",(LPDWORD)0x0,&DStack_c,param_1,&local_14);
  }
  return;
}



/* c0113dfc FUN_c0113dfc */

/* Boundary evidence: original MIPS .pdata c0113dfc..c0113eab. Semantic name remains unreviewed. */

void FUN_c0113dfc(BYTE *param_1)

{
  LSTATUS LVar1;
  HKEY local_10;
  DWORD DStack_c;
  
  local_10 = (HKEY)0x0;
  LVar1 = RegCreateKeyExW((HKEY)&DAT_80000002,L"Comm\\Security\\Crypto",0,(LPWSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_10,&DStack_c);
  if (LVar1 == 0) {
    RegSetValueExW(local_10,L"Seed",0,3,param_1,0x14);
    RegCloseKey(local_10);
  }
  return;
}



/* c0113eac FUN_c0113eac */

/* Boundary evidence: original MIPS .pdata c0113eac..c0113f0f. Semantic name remains unreviewed. */

void FUN_c0113eac(void *param_1,void *param_2,uint param_3)

{
  if (0x13 < param_3) {
    param_3 = 0x14;
  }
  memcpy(param_2,param_1,param_3);
  memset((void *)(param_3 + (int)param_2),0,0x14 - param_3);
  return;
}



/* c0113f10 FUN_c0113f10 */

/* Boundary evidence: original MIPS .pdata c0113f10..c0113f6f. Semantic name remains unreviewed. */

void FUN_c0113f10(void *param_1,void *param_2,uint param_3)

{
  if (0x13 < param_3) {
    param_3 = 0x14;
  }
  memcpy(param_1,param_2,param_3);
  memset((void *)(param_3 + (int)param_1),0,0x14 - param_3);
  return;
}



/* c0113f70 FUN_c0113f70 */

/* Boundary evidence: original MIPS .pdata c0113f70..c0113f8f. Semantic name remains unreviewed. */

void FUN_c0113f70(void)

{
  FUN_c0113d54(&DAT_c0136e88);
  return;
}



/* c0113f90 FUN_c0113f90 */

/* Boundary evidence: original MIPS .pdata c0113f90..c0113faf. Semantic name remains unreviewed. */

void FUN_c0113f90(void)

{
  FUN_c0113dfc(&DAT_c0136e88);
  return;
}



/* c0113fb0 FUN_c0113fb0 */

/* Boundary evidence: original MIPS .pdata c0113fb0..c011408b. Semantic name remains unreviewed. */

undefined4 FUN_c0113fb0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  uint local_28 [2];
  
  local_28[0] = 0x14;
  piVar2 = LocalAlloc(0x40,0x60);
  if (piVar2 != (int *)0x0) {
    *piVar2 = 0x8004;
    A_SHAInit(piVar2 + 1);
    if (*piVar2 == 0x8004) {
      A_SHAUpdate(piVar2 + 1,param_1,param_2);
      bVar1 = FUN_c01139a8(piVar2,2,param_3,local_28);
      if ((CONCAT31(extraout_var,bVar1) != 0) && (iVar3 = FUN_c0113a5c(piVar2), iVar3 != 0)) {
        return 1;
      }
    }
  }
  return 0;
}



/* c011408c FUN_c011408c */

/* Boundary evidence: original MIPS .pdata c011408c..c01142e7. Semantic name remains unreviewed. */

undefined4
FUN_c011408c(void *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 *param_6,int *param_7)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  int local_100;
  int local_fc;
  uint local_f8 [16];
  uint local_b8 [16];
  undefined1 auStack_78 [64];
  undefined1 auStack_38 [20];
  uint local_24;
  
  local_24 = DAT_c0136c78;
  uVar4 = 0;
  memset(local_f8,0,0x40);
  memset(local_b8,0,0x40);
  local_100 = 0;
  if (0x40 < param_2) {
    param_2 = 0x40;
  }
  memcpy(local_f8,param_1,param_2);
  memcpy(local_b8,param_1,param_2);
  uVar2 = 0;
  do {
    puVar3 = (uint *)((int)local_b8 + uVar2);
    *(uint *)((int)local_f8 + uVar2) = *(uint *)((int)local_f8 + uVar2) ^ 0x36363636;
    uVar2 = uVar2 + 4;
    *puVar3 = *puVar3 ^ 0x5c5c5c5c;
  } while (uVar2 < 0x40);
  iVar1 = (**(code **)*param_7)(param_7,0,param_5,0,0,&local_100);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_7 + 4))(param_7,local_100,local_f8,0x40,0);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_7 + 4))(param_7,local_100,param_3,param_4,0);
      if (iVar1 != 0) {
        memcpy(auStack_78,local_b8,0x40);
        local_fc = 0x14;
        iVar1 = (**(code **)(*param_7 + 8))(param_7,local_100,2,auStack_38,&local_fc,0);
        if (iVar1 != 0) {
          iVar1 = (**(code **)*param_7)(param_7,0,param_5,0,0,param_6);
          if (iVar1 != 0) {
            iVar1 = (**(code **)(*param_7 + 4))(param_7,*param_6,auStack_78,local_fc + 0x40,0);
            if (iVar1 != 0) {
              uVar4 = 1;
            }
          }
        }
      }
    }
  }
  if (local_100 != 0) {
    (**(code **)(*param_7 + 0xc))(param_7);
  }
  FUN_c013331c(local_24);
  return uVar4;
}



/* c01142e8 FUN_c01142e8 */

/* Boundary evidence: original MIPS .pdata c01142e8..c0114573. Semantic name remains unreviewed. */

int FUN_c01142e8(undefined4 param_1,undefined4 param_2,void *param_3,uint param_4,int param_5,
                void *param_6,uint param_7,int *param_8)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  void *_Dst;
  undefined1 *hMem;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int local_68;
  undefined4 local_64;
  void *local_60;
  uint local_58 [6];
  uint local_40 [5];
  uint local_2c;
  
  local_2c = DAT_c0136c78;
  local_60 = param_6;
  local_64 = param_1;
  if (param_4 < 0x10000001) {
    hMem = LocalAlloc(0,param_4 + 4);
    if (hMem != (undefined1 *)0x0) {
      if ((param_5 != 0) && (param_7 < 0x15)) {
        memcpy(hMem,param_3,param_4);
        *(undefined4 *)(hMem + param_4) = 0x1000000;
        local_68 = 0;
        memset(local_40,0,0x14);
        uVar3 = local_64;
        iVar4 = (**(code **)(*param_8 + 0x2c))
                          (param_8,local_64,param_2,hMem,param_4 + 4,0x8004,&local_68);
        do {
          bVar1 = iVar4 == 0;
          param_5 = param_5 + -1;
          iVar4 = 0;
          if (bVar1) break;
          local_64 = 0x14;
          iVar5 = (**(code **)(*param_8 + 8))(param_8,local_68,2,local_58,&local_64,0);
          (**(code **)(*param_8 + 0xc))(param_8,local_68);
          uVar8 = 0;
          local_68 = 0;
          do {
            puVar7 = (uint *)((int)local_40 + uVar8);
            puVar6 = (uint *)((int)local_58 + uVar8);
            uVar8 = uVar8 + 4;
            *puVar7 = *puVar6 ^ *puVar7;
          } while (uVar8 < 0x14);
          iVar4 = 0;
          if (iVar5 != 0) {
            iVar4 = (**(code **)(*param_8 + 0x2c))
                              (param_8,uVar3,param_2,local_58,local_64,0x8004,&local_68);
          }
        } while (param_5 != 0);
        _Dst = local_60;
        puVar2 = hMem;
        if (local_68 != 0) {
          (**(code **)(*param_8 + 0xc))(param_8);
        }
        for (; param_4 != 0; param_4 = param_4 - 1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        LocalFree(hMem);
        if (iVar4 != 0) {
          memcpy(_Dst,local_40,param_7);
        }
        FUN_c013331c(local_2c);
        return iVar4;
      }
      LocalFree(hMem);
    }
  }
  FUN_c013331c(local_2c);
  return 0;
}



/* c0114574 FUN_c0114574 */

/* Boundary evidence: original MIPS .pdata c0114574..c0114823. Semantic name remains unreviewed. */

void FUN_c0114574(int *param_1)

{
  int iVar1;
  HMODULE pHVar2;
  uint uVar3;
  _SYSTEMTIME local_48;
  _MEMORYSTATUS local_38;
  uint local_18;
  
  local_18 = DAT_c0136c78;
  local_48._0_8_ = CeGetRandomSeed();
  FUN_c0113ce0(param_1,&local_48,8);
  local_48.wYear = 0;
  local_48.wMonth = 0;
  iVar1 = KernelIoControl(0x10100d0,0,0,&local_38,0x10,&local_48);
  if ((iVar1 != 0) && (local_48._0_4_ != 0)) {
    uVar3 = local_48._0_4_;
    if (0xf < (uint)local_48._0_4_) {
      uVar3 = 0x10;
    }
    FUN_c0113ce0(param_1,&local_38,uVar3);
  }
  local_48.wYear = 0;
  local_48.wMonth = 0;
  iVar1 = KernelIoControl(0x10100f8,0,0,&local_38,8,&local_48);
  if ((iVar1 != 0) && (local_48._0_4_ != 0)) {
    uVar3 = local_48._0_4_;
    if (7 < (uint)local_48._0_4_) {
      uVar3 = 8;
    }
    FUN_c0113ce0(param_1,&local_38,uVar3);
  }
  GetLocalTime(&local_48);
  SystemTimeToFileTime(&local_48,(LPFILETIME)&local_38);
  FUN_c0113ce0(param_1,&local_38,8);
  local_48._0_4_ = __GetUserKData(0xc);
  FUN_c0113ce0(param_1,&local_48,4);
  local_48._0_4_ = __GetUserKData(8);
  FUN_c0113ce0(param_1,&local_48,4);
  local_48._0_4_ = GetTickCount();
  FUN_c0113ce0(param_1,&local_48,4);
  iVar1 = WaitForAPIReady(0x51,0);
  if (iVar1 == 0) {
    if (DAT_c0136ebc == (code *)0x0) {
      pHVar2 = GetModuleHandleW(L"COREDLL.DLL");
      DAT_c0136ebc = (code *)GetProcAddressW(pHVar2,L"GetMessagePos");
      goto LAB_c0114748;
    }
  }
  else {
LAB_c0114748:
    if (DAT_c0136ebc == (code *)0x0) goto LAB_c0114770;
  }
  local_48._0_4_ = (*DAT_c0136ebc)();
  FUN_c0113ce0(param_1,&local_48,4);
LAB_c0114770:
  local_38.dwLength = 0x20;
  GlobalMemoryStatus(&local_38);
  local_48.wYear = local_38.dwAvailPhys._2_2_;
  FUN_c0113ce0(param_1,&local_48,2);
  local_48.wYear = local_38.dwAvailPageFile._2_2_;
  FUN_c0113ce0(param_1,&local_48,2);
  local_48.wYear._0_1_ = local_38.dwAvailVirtual._2_1_;
  FUN_c0113ce0(param_1,&local_48,1);
  iVar1 = GetStoreInformation(&local_48);
  if (iVar1 != 0) {
    FUN_c0113ce0(param_1,&local_48,4);
    FUN_c0113ce0(param_1,&local_48.wDayOfWeek,4);
  }
  FUN_c013331c(local_18);
  return;
}



/* c0114824 FUN_c0114824 */

/* Boundary evidence: original MIPS .pdata c0114824..c01149c7. Semantic name remains unreviewed. */

void FUN_c0114824(LONG *param_1)

{
  LSTATUS LVar1;
  LONG LVar2;
  LONG Value;
  HKEY local_38;
  DWORD local_34;
  DWORD local_30;
  int local_2c;
  
  if (param_1 != (LONG *)0x0) {
    *param_1 = 0;
  }
  if (DAT_c0136e9c == 0) {
    Value = 0;
    LVar2 = 0;
    local_38 = (HKEY)0x0;
    LVar1 = RegOpenKeyExW((HKEY)&DAT_80000002,L"Comm\\Security\\DPAPI",0,0,&local_38);
    if (LVar1 == 0) {
      local_34 = 4;
      LVar1 = RegQueryValueExW(local_38,L"Algorithm",(LPDWORD)0x0,&local_30,(LPBYTE)&local_2c,
                               &local_34);
      if ((((LVar1 == 0) && (local_30 == 4)) && (local_34 == 4)) && (Value = 1, local_2c == 1)) {
        LVar2 = 1;
      }
    }
    InterlockedExchange((LONG *)&DAT_c0136ea0,Value);
    InterlockedExchange((LONG *)&DAT_c0136ea4,LVar2);
    InterlockedExchange(&DAT_c0136e9c,1);
    if (local_38 != (HKEY)0x0) {
      RegCloseKey(local_38);
    }
  }
  LVar2 = InterlockedCompareExchange((LONG *)&DAT_c0136ea0,0,0);
  InterlockedCompareExchange((LONG *)&DAT_c0136ea4,0,0);
  if (param_1 != (LONG *)0x0) {
    *param_1 = LVar2;
  }
  return;
}



/* c01149c8 FUN_c01149c8 */

/* Boundary evidence: original MIPS .pdata c01149c8..c0114b83. Semantic name remains unreviewed. */

undefined4 FUN_c01149c8(byte *param_1,uint *param_2)

{
  int local_d8;
  undefined1 auStack_d4 [60];
  byte abStack_98 [104];
  undefined1 auStack_30 [20];
  uint local_1c;
  
  local_1c = DAT_c0136c78;
  if (DAT_c013684c < 5000) {
    A_SHAInit(abStack_98);
    A_SHAUpdate(abStack_98,&DAT_c0136ea8,0x14);
    A_SHAUpdate(abStack_98,param_1,*param_2);
    A_SHAFinal(abStack_98,&DAT_c0136ea8);
  }
  else {
    FUN_c0113eac(&DAT_c0136e88,auStack_30,0x14);
    A_SHAInit(abStack_98);
    A_SHAUpdate(abStack_98,&DAT_c0136ea8,0x14);
    local_d8 = 0;
    FUN_c0114574(&local_d8);
    A_SHAUpdate(abStack_98,auStack_d4,local_d8);
    A_SHAUpdate(abStack_98,param_1,*param_2);
    A_SHAUpdate(abStack_98,auStack_30,0x14);
    A_SHAFinal(abStack_98,&DAT_c0136ea8);
    DAT_c013684c = 0;
    FUN_c01314cc((int *)&DAT_c0136d50,0x14,-0x3fec9158);
    FUN_c0131560(-0x3fec92b0,100,abStack_98);
    A_SHAInit(abStack_98);
    A_SHAUpdate(abStack_98,&DAT_c0136ea8,0x14);
    A_SHAFinal(abStack_98,&DAT_c0136ea8);
    FUN_c0113f10(&DAT_c0136e88,&DAT_c0136ea8,0x14);
  }
  if (5000 - DAT_c013684c < *param_2) {
    *param_2 = 5000 - DAT_c013684c;
  }
  FUN_c0131560(-0x3fec92b0,*param_2,param_1);
  DAT_c013684c = *param_2 + DAT_c013684c;
  FUN_c013331c(local_1c);
  return 1;
}



/* c0114b84 FUN_c0114b84 */

/* Boundary evidence: original MIPS .pdata c0114b84..c0114e8f. Semantic name remains unreviewed. */

void FUN_c0114b84(void)

{
  LONG LVar1;
  HMODULE hLibModule;
  int iVar2;
  LONG local_18;
  int local_14;
  
  LVar1 = InterlockedCompareExchange((LONG *)&DAT_c0136e80,0,0);
  if (((LVar1 == 0) && (FUN_c0114824(&local_14), local_14 != 0)) &&
     (hLibModule = LoadLibraryW(L"coredll.dll"), hLibModule != (HMODULE)0x0)) {
    LVar1 = GetProcAddressW(hLibModule,L"CryptCreateHash");
    InterlockedCompareExchange(&DAT_c0136e54,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptHashData");
    InterlockedCompareExchange(&DAT_c0136e58,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptGetHashParam");
    InterlockedCompareExchange(&DAT_c0136e5c,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptDestroyHash");
    InterlockedCompareExchange(&DAT_c0136e60,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptDeriveKey");
    InterlockedCompareExchange(&DAT_c0136e64,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptDestroyKey");
    InterlockedCompareExchange(&DAT_c0136e68,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptEncrypt");
    InterlockedCompareExchange(&DAT_c0136e6c,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptDecrypt");
    InterlockedCompareExchange(&DAT_c0136e70,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptGenRandom");
    InterlockedCompareExchange(&DAT_c0136e74,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptAcquireContextW");
    InterlockedCompareExchange((LONG *)&DAT_c0136e78,LVar1,0);
    LVar1 = GetProcAddressW(hLibModule,L"CryptReleaseContext");
    InterlockedCompareExchange((LONG *)&DAT_c0136e7c,LVar1,0);
    if (((((DAT_c0136e54 != 0) && (DAT_c0136e58 != 0)) &&
         ((DAT_c0136e5c != 0 && ((DAT_c0136e60 != 0 && (DAT_c0136e64 != 0)))))) &&
        (DAT_c0136e68 != 0)) &&
       ((((DAT_c0136e6c != 0 && (DAT_c0136e70 != 0)) && (DAT_c0136e74 != 0)) &&
        ((DAT_c0136e78 != (code *)0x0 && (DAT_c0136e7c != (code *)0x0)))))) {
      iVar2 = (*DAT_c0136e78)(&local_18,0,0,0x18,0xf0000040);
      if (iVar2 != 0) {
        LVar1 = InterlockedCompareExchange((LONG *)&DAT_c0136e84,local_18,0);
        if (LVar1 != 0) {
          (*DAT_c0136e7c)(local_18,0);
        }
        LVar1 = InterlockedCompareExchange((LONG *)&DAT_c0136e80,(LONG)hLibModule,0);
        if (LVar1 != 0) {
          FreeLibrary(hLibModule);
        }
      }
    }
  }
  return;
}



/* c0114e90 FUN_c0114e90 */

/* Boundary evidence: original MIPS .pdata c0114e90..c0114ef7. Semantic name remains unreviewed. */

undefined4 FUN_c0114e90(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint local_18 [2];
  
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      local_18[0] = param_2 - uVar1;
      FUN_c01149c8((byte *)(uVar1 + param_3),local_18);
      uVar1 = local_18[0] + uVar1;
    } while (uVar1 < param_2);
  }
  return 1;
}



/* c0114ef8 FUN_c0114ef8 */

/* Boundary evidence: original MIPS .pdata c0114ef8..c0114fab. Semantic name remains unreviewed. */

bool FUN_c0114ef8(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = CeImpersonateCurrentProcess();
  if (iVar1 != 0) {
    FUN_c0114e90(0,param_2,param_1);
    CeRevertToSelf();
  }
  return iVar1 != 0;
}



/* c0114fac FUN_c0114fac */

/* Boundary evidence: original MIPS .pdata c0114fac..c0114fb7. Semantic name remains unreviewed. */

undefined4 FUN_c0114fac(void)

{
  return 1;
}



/* c0114fb8 FUN_c0114fb8 */

/* Boundary evidence: original MIPS .pdata c0114fb8..c0114ff3. Semantic name remains unreviewed. */

void FUN_c0114fb8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  (*(code *)**(undefined4 **)(param_1 + 8))
            ((*(undefined4 **)(param_1 + 8))[0xc],param_3,param_4,param_5,param_6);
  return;
}



/* c0114ff4 FUN_c0114ff4 */

/* Boundary evidence: original MIPS .pdata c0114ff4..c011502f. Semantic name remains unreviewed. */

void FUN_c0114ff4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(*(int *)(param_1 + 8) + 4))(param_2,param_3,param_4,param_5);
  return;
}



/* c0115030 FUN_c0115030 */

/* Boundary evidence: original MIPS .pdata c0115030..c0115073. Semantic name remains unreviewed. */

void FUN_c0115030(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  (**(code **)(*(int *)(param_1 + 8) + 8))(param_2,param_3,param_4,param_5,param_6);
  return;
}



/* c0115074 FUN_c0115074 */

/* Boundary evidence: original MIPS .pdata c0115074..c0115097. Semantic name remains unreviewed. */

void FUN_c0115074(int param_1,undefined4 param_2)

{
  (**(code **)(*(int *)(param_1 + 8) + 0xc))(param_2);
  return;
}



/* c0115098 FUN_c0115098 */

/* Boundary evidence: original MIPS .pdata c0115098..c011517f. Semantic name remains unreviewed. */

undefined4 FUN_c0115098(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  iVar1 = (**(code **)param_1[2])(((undefined4 *)param_1[2])[0xc],0x800e,0,0,&local_20);
  if ((iVar1 != 0) &&
     (iVar1 = (**(code **)(param_1[2] + 4))(local_20,param_3,param_4,0), iVar1 != 0)) {
    (**(code **)(*param_1 + 0x14))(param_1,0,param_2,local_20,4,&local_1c);
  }
  if (local_20 != 0) {
    (**(code **)(*param_1 + 0xc))(param_1);
  }
  return local_1c;
}



/* c0115180 FUN_c0115180 */

/* Boundary evidence: original MIPS .pdata c0115180..c01151bb. Semantic name remains unreviewed. */

void FUN_c0115180(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  (**(code **)(*(int *)(param_1 + 8) + 0x10))
            (*(undefined4 *)(*(int *)(param_1 + 8) + 0x30),param_3,param_4,param_5,param_6);
  return;
}



/* c01151bc FUN_c01151bc */

/* Boundary evidence: original MIPS .pdata c01151bc..c01151df. Semantic name remains unreviewed. */

void FUN_c01151bc(int param_1,undefined4 param_2)

{
  (**(code **)(*(int *)(param_1 + 8) + 0x14))(param_2);
  return;
}



/* c01151e0 FUN_c01151e0 */

/* Boundary evidence: original MIPS .pdata c01151e0..c011522b. Semantic name remains unreviewed. */

void FUN_c01151e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  (**(code **)(*(int *)(param_1 + 8) + 0x18))
            (param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



/* c011522c FUN_c011522c */

/* Boundary evidence: original MIPS .pdata c011522c..c011526f. Semantic name remains unreviewed. */

void FUN_c011522c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  (**(code **)(*(int *)(param_1 + 8) + 0x1c))(param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c0115270 FUN_c0115270 */

/* Boundary evidence: original MIPS .pdata c0115270..c011529b. Semantic name remains unreviewed. */

void FUN_c0115270(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*(int *)(param_1 + 8) + 0x20))
            (*(undefined4 *)(*(int *)(param_1 + 8) + 0x30),param_3,param_4);
  return;
}



/* c011529c FUN_c011529c */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c011529c..c01153a7. Semantic name remains unreviewed. */

undefined4 FUN_c011529c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_20 [2];
  
  local_20[1] = 0x14;
  local_20[0] = 0;
  uVar2 = 0;
  iVar1 = (**(code **)*param_1)(param_1,*(undefined4 *)(param_1[2] + 0x30),0x8004,0,0,local_20);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 4))(param_1,local_20[0],param_2,param_3,0);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_1 + 8))(param_1,local_20[0],2,param_4,local_20 + 1,0);
      if (iVar1 != 0) {
        uVar2 = 1;
      }
    }
  }
  if (local_20[0] != 0) {
    (**(code **)(*param_1 + 0xc))(param_1);
  }
  return uVar2;
}



/* c01153a8 FUN_c01153a8 */

/* Boundary evidence: original MIPS .pdata c01153a8..c01153ef. Semantic name remains unreviewed. */

void FUN_c01153a8(int *param_1,void *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 *param_7)

{
  FUN_c011408c(param_2,param_3,param_4,param_5,param_6,param_7,param_1);
  return;
}



/* c01153f8 FUN_c01153f8 */

/* Boundary evidence: original MIPS .pdata c01153f8..c0115e47. Semantic name remains unreviewed. */

undefined4
FUN_c01153f8(size_t *param_1,wchar_t *param_2,int *param_3,undefined4 param_4,undefined4 param_5,
            uint param_6,uint *param_7,int *param_8)

{
  size_t sVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  DWORD DVar11;
  int *piVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int local_e4;
  size_t local_e0;
  wchar_t *local_dc;
  undefined4 *local_d8;
  size_t local_d4;
  int *local_d0;
  size_t *local_cc;
  size_t local_c8;
  undefined4 *local_c4;
  size_t *local_c0;
  size_t local_bc;
  uint local_b8;
  int local_b4;
  uint *local_b0;
  int local_ac;
  uint *local_a8;
  int local_a4;
  wchar_t *local_a0;
  size_t *local_9c;
  void *local_98;
  int *local_94;
  size_t local_90 [2];
  undefined4 auStack_88 [4];
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [24];
  undefined1 auStack_40 [16];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  local_a8 = param_7;
  local_d0 = param_8;
  local_d8 = (undefined4 *)0x0;
  local_c4 = (undefined4 *)0x0;
  local_98 = (void *)0x0;
  iVar13 = 0;
  local_a4 = 0;
  local_b0 = param_7;
  local_d4 = 0;
  local_b4 = 0x14;
  iVar15 = 0x10;
  local_c8 = 0x10;
  local_dc = param_2;
  local_cc = param_1;
  local_a0 = param_2;
  local_9c = param_1;
  local_94 = param_3;
  local_c0 = (size_t *)(**(code **)(*param_8 + 0x30))(param_8);
  local_e4 = 0;
  local_ac = 0;
  DVar11 = 0;
  if (local_dc == (wchar_t *)0x0) {
    local_e0 = 0;
  }
  else {
    sVar1 = wcslen(local_dc);
    local_e0 = (sVar1 + 1) * 2;
  }
  if (((param_7 == (uint *)0x0) || (param_1 == (size_t *)0x0)) ||
     (uVar3 = *param_1 + 0x10, uVar3 < *param_1)) {
LAB_c01156a4:
    DVar11 = 0x57;
  }
  else {
    uVar7 = 0xffffffff;
    iVar10 = -0x7ff8fdea;
    iVar4 = iVar10;
    uVar8 = uVar7;
    if (0x6b < local_e0 + 0x6c) {
      iVar4 = 0;
      uVar8 = local_e0 + 0x6c;
    }
    local_d4 = uVar3;
    if (iVar4 < 0) goto LAB_c01156a4;
    uVar5 = uVar7;
    iVar4 = iVar10;
    if (uVar8 <= uVar8 + 4) {
      iVar4 = 0;
      uVar5 = uVar8 + 4;
    }
    if (iVar4 < 0) goto LAB_c01156a4;
    uVar8 = uVar7;
    iVar4 = iVar10;
    if (uVar5 <= uVar5 + 4) {
      iVar4 = 0;
      uVar8 = uVar5 + 4;
    }
    if (iVar4 < 0) goto LAB_c01156a4;
    if (uVar8 <= uVar8 + uVar3) {
      iVar10 = 0;
      uVar7 = uVar8 + uVar3;
    }
    if (iVar10 < 0) goto LAB_c01156a4;
    puVar9 = (undefined4 *)param_7[1];
    if ((puVar9 == (undefined4 *)0x0) || (*param_7 < uVar7)) {
      *param_7 = uVar7;
      *local_b0 = uVar7;
      DVar11 = 0x7a;
    }
    else {
      local_98 = (void *)param_1[1];
      if (local_98 == (void *)0x0) goto LAB_c01156a4;
      local_d8 = puVar9;
      local_c4 = puVar9;
      if (param_3 == (int *)0x0) {
        iVar13 = 0;
        local_a4 = iVar13;
      }
      else {
        iVar13 = param_3[1];
        local_a4 = iVar13;
        if ((*param_3 != 0) && (iVar13 == 0)) goto LAB_c01156a4;
      }
    }
  }
  local_bc = local_e0;
  if (DVar11 != 0) {
    SetLastError(DVar11);
    FUN_c013331c(local_30);
    return 0;
  }
  uVar3 = param_6 & 0x20000004;
  local_b8 = uVar3;
  iVar4 = FUN_c012b5b4(uVar3,auStack_88,local_78,&local_c8,0);
  if (iVar4 == 0) {
    DVar11 = GetLastError();
    if ((DVar11 != 0x80090001) || ((param_6 & 4) != 0)) goto LAB_c0115d34;
    uVar3 = uVar3 | 4;
    local_b8 = uVar3;
    iVar4 = FUN_c012b5b4(uVar3,auStack_88,local_78,&local_c8,0);
    if (iVar4 != 0) goto LAB_c01157e8;
  }
  else {
LAB_c01157e8:
    DVar11 = 0;
    (**(code **)(*param_8 + 0x28))(param_8,local_78,local_c8,local_58);
    iVar4 = (**(code **)(*param_8 + 0x24))(param_8,0,0x10,local_68);
    if ((iVar4 != 0) &&
       (iVar4 = (**(code **)(*param_8 + 0x2c))(param_8,local_58,0x14,local_68,0x10,0x8004,&local_e4)
       , iVar4 != 0)) {
      if ((iVar13 != 0) &&
         (iVar4 = (**(code **)(*param_8 + 4))(param_8,local_e4,iVar13,*param_3,0), iVar4 == 0)) {
        DVar11 = GetLastError();
      }
      if (DVar11 != 0) goto LAB_c0115d34;
      iVar4 = (**(code **)(*param_8 + 0x14))(param_8,0,local_c0,local_e4,4,&local_ac);
      if (iVar4 != 0) {
        (**(code **)(*param_8 + 0xc))(param_8,local_e4);
        local_e4 = 0;
        iVar4 = (**(code **)(*param_8 + 0x24))(param_8,0,0x10,auStack_40);
        if ((iVar4 != 0) &&
           (iVar4 = (**(code **)(*param_8 + 0x2c))
                              (param_8,local_58,0x14,auStack_40,0x10,0x8004,&local_e4), iVar4 != 0))
        {
          if ((iVar13 != 0) &&
             (iVar13 = (**(code **)(*param_8 + 4))(param_8,local_e4,iVar13,*param_3,0), iVar13 == 0)
             ) {
            DVar11 = GetLastError();
          }
          puVar9 = local_d8;
          if (DVar11 == 0) {
            uVar14 = (**(code **)(*param_8 + 0x34))(param_8);
            *puVar9 = uVar14;
            memcpy(puVar9 + 1,auStack_88,0x10);
            puVar9[6] = local_e0;
            memcpy(puVar9 + 7,local_dc,local_e0);
            puVar2 = (undefined4 *)(local_e0 + (int)(puVar9 + 7));
            *puVar2 = local_c0;
            puVar2[1] = 0x10;
            puVar2[2] = 0x10;
            memcpy(puVar2 + 3,local_68,0x10);
            puVar2[7] = 0;
            puVar2[8] = 0x8004;
            puVar2[9] = 0x10;
            puVar2[10] = 0x10;
            memcpy(puVar2 + 0xb,auStack_40,0x10);
            local_c0 = puVar2 + 0xf;
            puVar9[5] = uVar3;
            local_90[0] = *local_cc;
            puVar2 = puVar2 + 0x10;
            memcpy(puVar2,local_98,local_90[0]);
            iVar13 = (**(code **)(*param_8 + 0x1c))
                               (param_8,0,local_ac,0,1,0,puVar2,local_90,local_d4);
            if (iVar13 == 0) {
              DVar11 = GetLastError();
            }
            else {
              local_d4 = local_90[0];
              *local_c0 = local_90[0];
              piVar12 = (int *)(local_90[0] + (int)puVar2);
              iVar13 = (**(code **)(*param_8 + 4))
                                 (param_8,local_e4,puVar9,(int)piVar12 - (int)puVar9,0);
              if (iVar13 == 0) {
                DVar11 = GetLastError();
              }
              else {
                iVar13 = (**(code **)(*param_8 + 8))(param_8,local_e4,2,piVar12 + 1,&local_b4,0);
                if (iVar13 == 0) {
                  DVar11 = GetLastError();
                }
                else {
                  *piVar12 = local_b4;
                  uVar3 = (int)(piVar12 + 1) + (local_b4 - (int)puVar9);
                  *param_7 = uVar3;
                  *local_b0 = uVar3;
                  DVar11 = 0;
                }
              }
            }
          }
          goto LAB_c0115d34;
        }
      }
    }
  }
  DVar11 = GetLastError();
LAB_c0115d34:
  uVar14 = 1;
  puVar6 = local_58;
  iVar13 = 0x14;
  do {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  puVar6 = local_68;
  do {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  puVar6 = local_78;
  for (sVar1 = local_c8; sVar1 != 0; sVar1 = sVar1 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  if (local_ac != 0) {
    (**(code **)(*param_8 + 0x18))(param_8);
  }
  if (local_e4 != 0) {
    (**(code **)(*param_8 + 0xc))(param_8);
  }
  if ((DVar11 != 0) && (SetLastError(DVar11), DVar11 != 0)) {
    uVar14 = 0;
  }
  FUN_c013331c(local_30);
  return uVar14;
}



/* c0115e48 FUN_c0115e48 */

/* Boundary evidence: original MIPS .pdata c0115e48..c0115e53. Semantic name remains unreviewed. */

undefined4 FUN_c0115e48(void)

{
  return 1;
}



/* c0115e54 FUN_c0115e54 */

/* Boundary evidence: original MIPS .pdata c0115e54..c0115e5f. Semantic name remains unreviewed. */

undefined4 FUN_c0115e54(void)

{
  return 1;
}



/* c0115e60 FUN_c0115e60 */

/* Boundary evidence: original MIPS .pdata c0115e60..c0115e6b. Semantic name remains unreviewed. */

undefined4 FUN_c0115e60(void)

{
  return 1;
}



/* c0115e6c FUN_c0115e6c */

/* Boundary evidence: original MIPS .pdata c0115e6c..c0115e77. Semantic name remains unreviewed. */

undefined4 FUN_c0115e6c(void)

{
  return 1;
}



/* c0115e78 FUN_c0115e78 */

/* Boundary evidence: original MIPS .pdata c0115e78..c0115e9b. Semantic name remains unreviewed. */

void FUN_c0115e78(void)

{
  FUN_c0114b84();
  FUN_c0113f70();
  return;
}



/* c0115e9c FUN_c0115e9c */

/* Boundary evidence: original MIPS .pdata c0115e9c..c0115eb7. Semantic name remains unreviewed. */

void FUN_c0115e9c(void)

{
  FUN_c0113f90();
  return;
}



/* c0115eb8 FUN_c0115eb8 */

/* Boundary evidence: original MIPS .pdata c0115eb8..c0115eef. Semantic name remains unreviewed. */

void FUN_c0115eb8(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_c0113910(param_2,param_3,param_4,param_5,param_6);
  return;
}



/* c0115ef0 FUN_c0115ef0 */

/* Boundary evidence: original MIPS .pdata c0115ef0..c0115f1f. Semantic name remains unreviewed. */

void FUN_c0115ef0(undefined4 param_1,int *param_2)

{
  FUN_c0113968(param_2);
  return;
}



/* c0115f20 FUN_c0115f20 */

/* Boundary evidence: original MIPS .pdata c0115f20..c0115f57. Semantic name remains unreviewed. */

void FUN_c0115f20(undefined4 param_1,int *param_2,int param_3,undefined4 *param_4,uint *param_5)

{
  FUN_c01139a8(param_2,param_3,param_4,param_5);
  return;
}



/* c0115f58 FUN_c0115f58 */

/* Boundary evidence: original MIPS .pdata c0115f58..c0115f73. Semantic name remains unreviewed. */

void FUN_c0115f58(undefined4 param_1,int *param_2)

{
  FUN_c0113a5c(param_2);
  return;
}



/* c0115f74 FUN_c0115f74 */

/* Boundary evidence: original MIPS .pdata c0115f74..c0115f9b. Semantic name remains unreviewed. */

void FUN_c0115f74(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  FUN_c0113ab4(param_2,param_3,param_4);
  return;
}



/* c0115f9c FUN_c0115f9c */

/* Boundary evidence: original MIPS .pdata c0115f9c..c0115fd3. Semantic name remains unreviewed. */

void FUN_c0115f9c(undefined4 param_1,undefined4 param_2,int param_3,int *param_4,undefined4 param_5,
                 undefined4 *param_6)

{
  FUN_c0113b34(param_2,param_3,param_4,param_5,param_6);
  return;
}



/* c0115fd4 FUN_c0115fd4 */

/* Boundary evidence: original MIPS .pdata c0115fd4..c0115fef. Semantic name remains unreviewed. */

void FUN_c0115fd4(undefined4 param_1,int *param_2)

{
  FUN_c0113be8(param_2);
  return;
}



/* c0115ff0 FUN_c0115ff0 */

/* Boundary evidence: original MIPS .pdata c0115ff0..c011603f. Semantic name remains unreviewed. */

void FUN_c0115ff0(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
                 int param_6,byte *param_7,int *param_8)

{
  FUN_c0113c38(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c0116040 FUN_c0116040 */

/* Boundary evidence: original MIPS .pdata c0116040..c0116087. Semantic name remains unreviewed. */

void FUN_c0116040(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
                 int param_6,byte *param_7,int *param_8)

{
  FUN_c0113ca8(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c0116088 FUN_c0116088 */

/* Boundary evidence: original MIPS .pdata c0116088..c01160af. Semantic name remains unreviewed. */

void FUN_c0116088(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  FUN_c0114e90(param_2,param_3,param_4);
  return;
}



/* c01160b0 FUN_c01160b0 */

/* Boundary evidence: original MIPS .pdata c01160b0..c01160d7. Semantic name remains unreviewed. */

void FUN_c01160b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_c0113fb0(param_2,param_3,param_4);
  return;
}



/* c01160d8 FUN_c01160d8 */

/* Boundary evidence: original MIPS .pdata c01160d8..c011611f. Semantic name remains unreviewed. */

void FUN_c01160d8(int *param_1,void *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 *param_7)

{
  FUN_c011408c(param_2,param_3,param_4,param_5,param_6,param_7,param_1);
  return;
}



/* c0116130 FUN_c0116130 */

/* Boundary evidence: original MIPS .pdata c0116130..c0116193. Semantic name remains unreviewed. */

int FUN_c0116130(int param_1)

{
  int iVar1;
  LONG LVar2;
  
  iVar1 = FUN_c0114824((LONG *)0x0);
  if (((iVar1 != 0) && (iVar1 == 1)) &&
     (LVar2 = InterlockedCompareExchange((LONG *)&DAT_c0136e80,0,0), LVar2 != 0)) {
    param_1 = param_1 + 0xc;
  }
  return param_1;
}



/* c0116194 FUN_c0116194 */

/* Boundary evidence: original MIPS .pdata c0116194..c01161df. Semantic name remains unreviewed. */

int FUN_c0116194(int param_1)

{
  LONG LVar1;
  int iVar2;
  
  LVar1 = InterlockedCompareExchange((LONG *)&DAT_c0136e80,0,0);
  if (LVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + 0xc;
  }
  return iVar2;
}



/* c01161e0 FUN_c01161e0 */

undefined4 * FUN_c01161e0(undefined4 *param_1)

{
  param_1[1] = 0x6801;
  param_1[2] = 1;
  *param_1 = &PTR_FUN_c00f3210;
  param_1[4] = 0x660e;
  param_1[3] = &PTR_FUN_c00f31d8;
  param_1[5] = &DAT_c0136e54;
  param_1[6] = 2;
  return param_1;
}



/* c011622c FUN_c011622c */

/* Boundary evidence: original MIPS .pdata c011622c..c0116367. Semantic name remains unreviewed. */

undefined4
FUN_c011622c(undefined4 param_1,size_t param_2,wchar_t *param_3,undefined4 param_4,int param_5,
            uint param_6,undefined4 param_7,uint param_8,uint *param_9)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  size_t local_38;
  undefined4 local_34;
  undefined4 auStack_30 [8];
  
  uVar3 = 0;
  local_40 = param_5;
  local_48 = param_8;
  local_44 = param_7;
  local_3c = param_4;
  local_38 = param_2;
  local_34 = param_1;
  iVar1 = CeImpersonateCurrentProcess();
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    FUN_c01161e0(auStack_30);
    piVar2 = (int *)FUN_c0116130((int)auStack_30);
    if (piVar2 == (int *)0x0) {
      SetLastError(0xe);
    }
    else {
      uVar3 = FUN_c01153f8(&local_38,param_3,&local_40,0,0,param_6,&local_48,piVar2);
      *param_9 = local_48;
    }
    CeRevertToSelf();
  }
  return uVar3;
}



/* c0116368 FUN_c0116368 */

/* Boundary evidence: original MIPS .pdata c0116368..c0116373. Semantic name remains unreviewed. */

undefined4 FUN_c0116368(void)

{
  return 1;
}



/* c0116374 FUN_c0116374 */

/* Boundary evidence: original MIPS .pdata c0116374..c0116e1b. Semantic name remains unreviewed. */

undefined4
FUN_c0116374(uint *param_1,undefined4 *param_2,int *param_3,undefined4 param_4,undefined4 param_5,
            uint param_6,uint *param_7)

{
  uint *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  size_t sVar6;
  uint uVar7;
  uint uVar8;
  uint _Size;
  size_t *psVar9;
  void *_Dst;
  DWORD dwErrCode;
  int *piVar10;
  undefined4 uVar11;
  STRSAFE_PCNZWCH pwVar12;
  STRSAFE_PCNZWCH pwVar13;
  int iVar14;
  uint local_138;
  STRSAFE_PCNZWCH local_12c;
  int local_128;
  uint local_124;
  size_t local_120;
  int *local_11c;
  HLOCAL local_118;
  uint local_114;
  uint *local_110;
  STRSAFE_PCNZWCH local_10c;
  HLOCAL local_108;
  uint local_104;
  size_t local_100;
  uint *local_fc;
  int local_f8;
  int local_f4;
  uint local_f0;
  uint *local_ec;
  undefined4 *local_e8;
  uint local_e4;
  uint *local_e0;
  size_t local_dc;
  STRSAFE_PCNZWCH local_d8;
  int *local_d4;
  uint *local_d0;
  undefined4 *local_cc;
  uint *local_c8;
  int local_c4;
  size_t local_c0;
  undefined4 local_bc;
  int aiStack_b8 [8];
  undefined4 auStack_98 [4];
  undefined1 local_88 [24];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [20];
  uint local_2c;
  
  local_2c = DAT_c0136c78;
  local_fc = param_7;
  local_ec = param_7;
  local_e8 = param_2;
  local_e0 = param_1;
  local_d4 = param_3;
  local_cc = param_2;
  local_c8 = param_1;
  FUN_c01161e0(aiStack_b8);
  piVar10 = (int *)0x0;
  local_11c = (int *)0x0;
  local_110 = param_7;
  local_d0 = param_7;
  dwErrCode = 0;
  local_d8 = (STRSAFE_PCNZWCH)0x0;
  iVar14 = 0;
  local_f4 = 0;
  local_f8 = 0;
  local_128 = 0;
  local_124 = 0;
  local_118 = (HLOCAL)0x0;
  local_108 = (HLOCAL)0x0;
  local_120 = 0;
  local_dc = 0;
  local_114 = 0;
  local_e4 = 0;
  local_138 = 0;
  local_f0 = 0;
  local_12c = (STRSAFE_PCNZWCH)0x0;
  local_10c = (STRSAFE_PCNZWCH)0x0;
  local_100 = 0x10;
  memset(auStack_98,0,0x10);
  memset(local_88,0,0x14);
  pwVar13 = (STRSAFE_PCNZWCH)param_1[1];
  pwVar12 = pwVar13;
  local_d8 = pwVar13;
  if (pwVar13 == (STRSAFE_PCNZWCH)0x0) {
LAB_c01168c8:
    dwErrCode = 0x57;
    local_12c = (STRSAFE_PCNZWCH)0x0;
    goto LAB_c01168d8;
  }
  if (param_3 == (int *)0x0) {
    iVar14 = 0;
  }
  else {
    iVar14 = param_3[1];
    if ((*param_3 != 0) && (local_f4 = iVar14, iVar14 == 0)) goto LAB_c01168c8;
  }
  uVar7 = *param_1;
  local_f4 = iVar14;
  if (uVar7 < 0x1c) {
LAB_c01164f4:
    dwErrCode = 0xd;
    local_12c = (STRSAFE_PCNZWCH)0x0;
  }
  else {
    if (*(uint *)pwVar13 == 1) {
      piVar10 = aiStack_b8;
    }
    else {
      if (*(uint *)pwVar13 != 2) goto LAB_c01164f4;
      piVar10 = (int *)FUN_c0116194((int)aiStack_b8);
    }
    local_11c = piVar10;
    if (piVar10 == (int *)0x0) goto LAB_c01164f4;
    memcpy(auStack_98,pwVar13 + 2,0x10);
    local_138 = *(uint *)(pwVar13 + 10);
    pwVar12 = pwVar13 + 0xc;
    local_f0 = local_138;
    if (((local_138 ^ param_6) & 0x20000000) == 0) {
      uVar8 = *(uint *)pwVar12;
      pwVar12 = pwVar13 + 0xe;
      uVar7 = uVar7 - 0x1c;
      if ((uVar8 + 0xc < uVar8) || (uVar7 < uVar8 + 0xc)) goto LAB_c01165c4;
      if (uVar8 == 0) {
LAB_c0116670:
        local_120 = *(size_t *)pwVar12;
        local_c4 = *(int *)(pwVar12 + 2);
        local_114 = *(uint *)(pwVar12 + 4);
        pwVar12 = pwVar12 + 6;
        local_e4 = local_114;
        local_dc = local_120;
        if (((0x10 < local_114) || (local_114 + 4 < local_114)) || (uVar7 - 0xc < local_114 + 4))
        goto LAB_c0116660;
        memcpy(local_60,pwVar12,local_114);
        uVar8 = *(uint *)(local_114 + (int)pwVar12);
        pwVar12 = (STRSAFE_PCNZWCH)((uint *)(local_114 + (int)pwVar12) + 1);
        uVar7 = ((uVar7 - 0xc) - local_114) - 4;
        if ((uVar8 + 0xc < uVar8) || (uVar7 < uVar8 + 0xc)) goto LAB_c0116660;
        local_118 = LocalAlloc(0x40,uVar8);
        local_108 = local_118;
        if (local_118 != (HLOCAL)0x0) {
          memcpy(local_118,pwVar12,uVar8);
          puVar4 = (undefined4 *)(uVar8 + (int)pwVar12);
          local_bc = *puVar4;
          _Size = puVar4[2];
          pwVar12 = (STRSAFE_PCNZWCH)(puVar4 + 3);
          uVar7 = (uVar7 - uVar8) - 0xc;
          local_104 = _Size;
          if ((_Size < 0x11) && (_Size <= uVar7)) {
            memcpy(auStack_50,pwVar12,_Size);
            pwVar12 = (STRSAFE_PCNZWCH)(_Size + (int)pwVar12);
            uVar7 = uVar7 - _Size;
            if (3 < uVar7) {
              local_124 = *(uint *)pwVar12;
              pwVar12 = pwVar12 + 2;
              if ((local_124 <= local_124 + 0x18) && (local_124 + 0x18 <= uVar7 - 4)) {
                if ((local_fc[1] == 0) || (*local_fc < local_124)) {
                  *local_fc = local_124;
                  *local_110 = local_124;
                  dwErrCode = 0x7a;
                }
                goto LAB_c01168d8;
              }
            }
          }
          goto LAB_c0116660;
        }
        dwErrCode = 0xe;
      }
      else {
        local_10c = pwVar12;
        HVar2 = StringCbLengthW(pwVar12,uVar8,&local_c0);
        local_12c = pwVar12;
        if ((-1 < HVar2) && (local_c0 == uVar8 - 2)) {
          pwVar12 = (STRSAFE_PCNZWCH)(uVar8 + (int)pwVar12);
          uVar7 = uVar7 - uVar8;
          goto LAB_c0116670;
        }
LAB_c0116660:
        dwErrCode = 0xd;
      }
    }
    else {
LAB_c01165c4:
      dwErrCode = 0xd;
      local_12c = (STRSAFE_PCNZWCH)0x0;
    }
  }
LAB_c01168d8:
  uVar11 = 1;
  if (dwErrCode == 0) {
    iVar3 = FUN_c012b5b4(local_138,auStack_98,local_70,&local_100,1);
    if (iVar3 == 0) {
      dwErrCode = GetLastError();
    }
    else {
      (**(code **)(*piVar10 + 0x28))(piVar10,local_70,local_100,local_88);
      iVar3 = (**(code **)(*piVar10 + 0x2c))
                        (piVar10,local_88,0x14,local_60,local_114,0x8004,&local_128);
      if ((iVar3 != 0) &&
         (((iVar14 == 0 ||
           (iVar3 = (**(code **)(*piVar10 + 4))(piVar10,local_128,iVar14,*param_3,0), iVar3 != 0))
          && (iVar3 = (**(code **)(*piVar10 + 0x14))
                                (piVar10,0,local_120,local_128,local_c4 << 0x13 | 4,&local_f8),
             iVar3 != 0)))) {
        (**(code **)(*piVar10 + 0xc))(piVar10,local_128);
        local_128 = 0;
        iVar3 = (**(code **)(*piVar10 + 0x2c))
                          (piVar10,local_88,0x14,auStack_50,local_104,local_bc,&local_128);
        if ((iVar3 != 0) &&
           (((iVar14 == 0 ||
             (iVar14 = (**(code **)(*piVar10 + 4))(piVar10,local_128,iVar14,*param_3,0), iVar14 != 0
             )) && (iVar14 = (**(code **)(*piVar10 + 4))
                                       (piVar10,local_128,pwVar13,
                                        (local_124 - (int)pwVar13) + (int)pwVar12,0), iVar14 != 0)))
           ) {
          psVar9 = (size_t *)(local_124 + (int)pwVar12);
          local_120 = 0x14;
          iVar14 = (**(code **)(*piVar10 + 8))(piVar10,local_128,2,auStack_40,&local_120,0);
          if (iVar14 == 0) {
            dwErrCode = GetLastError();
          }
          else if ((*psVar9 == local_120) &&
                  (iVar14 = memcmp(psVar9 + 1,auStack_40,local_120), puVar1 = local_fc, iVar14 == 0)
                  ) {
            _Dst = (void *)local_fc[1];
            if (_Dst == (void *)0x0) {
              dwErrCode = 0x57;
            }
            else {
              memcpy(_Dst,pwVar12,local_124);
              iVar14 = (**(code **)(*piVar10 + 0x20))(piVar10,0,local_f8,0,1,0,_Dst,&local_124);
              if (iVar14 == 0) {
                dwErrCode = GetLastError();
                if (dwErrCode == 0x80090005) {
                  dwErrCode = 0xd;
                }
              }
              else {
                *puVar1 = local_124;
                *local_110 = local_124;
                if (local_e8 != (undefined4 *)0x0) {
                  pwVar12 = (STRSAFE_PCNZWCH)0x0;
                  if (local_12c != (STRSAFE_PCNZWCH)0x0) {
                    pwVar12 = (STRSAFE_PCNZWCH)((int)local_12c + (local_e0[1] - (int)pwVar13));
                    local_10c = pwVar12;
                  }
                  *local_e8 = pwVar12;
                }
                dwErrCode = 0;
              }
            }
          }
          else {
            dwErrCode = 0xd;
          }
          goto LAB_c0116cf0;
        }
      }
      dwErrCode = GetLastError();
    }
  }
LAB_c0116cf0:
  iVar14 = 0x14;
  puVar5 = local_88;
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  puVar5 = local_60;
  iVar14 = 0x10;
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  puVar5 = local_70;
  for (sVar6 = local_100; sVar6 != 0; sVar6 = sVar6 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  if (local_f8 != 0) {
    (**(code **)(*piVar10 + 0x18))(piVar10);
  }
  if (local_128 != 0) {
    (**(code **)(*piVar10 + 0xc))(piVar10);
  }
  if (local_118 != (HLOCAL)0x0) {
    LocalFree(local_118);
  }
  if ((dwErrCode != 0) && (SetLastError(dwErrCode), dwErrCode != 0)) {
    uVar11 = 0;
  }
  FUN_c013331c(local_2c);
  return uVar11;
}



/* c0116e1c FUN_c0116e1c */

/* Boundary evidence: original MIPS .pdata c0116e1c..c0116e27. Semantic name remains unreviewed. */

undefined4 FUN_c0116e1c(void)

{
  return 1;
}



/* c0116e28 FUN_c0116e28 */

/* Boundary evidence: original MIPS .pdata c0116e28..c0116e33. Semantic name remains unreviewed. */

undefined4 FUN_c0116e28(void)

{
  return 1;
}



/* c0116e34 FUN_c0116e34 */

/* Boundary evidence: original MIPS .pdata c0116e34..c0116f77. Semantic name remains unreviewed. */

undefined4
FUN_c0116e34(int param_1,uint param_2,undefined4 *param_3,int *param_4,undefined4 param_5,
            int param_6,uint param_7,undefined4 param_8,uint param_9,uint *param_10)

{
  int iVar1;
  undefined4 uVar2;
  int local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  
  local_34 = 0;
  local_28 = param_6;
  local_24 = param_5;
  local_30 = param_9;
  local_2c = param_8;
  local_38 = 0;
  local_20 = param_2;
  local_1c = param_1;
  iVar1 = CeImpersonateCurrentProcess();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_c0116374(&local_20,&local_38,&local_28,0,0,param_7,&local_30);
    if (local_38 == 0) {
      *param_3 = 0;
      *param_4 = 0;
    }
    else {
      *param_3 = 1;
      *param_4 = local_38 - param_1;
    }
    *param_10 = local_30;
    local_34 = uVar2;
    CeRevertToSelf();
  }
  return uVar2;
}



/* c0116f78 FUN_c0116f78 */

/* Boundary evidence: original MIPS .pdata c0116f78..c0116f83. Semantic name remains unreviewed. */

undefined4 FUN_c0116f78(void)

{
  return 1;
}



/* c0116f84 FUN_c0116f84 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0116f84..c0117243. Semantic name remains unreviewed. */

undefined4 FUN_c0116f84(void)

{
  int iVar1;
  LSTATUS LVar2;
  HRESULT HVar3;
  DWORD DVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_458 [3];
  DWORD local_44c;
  undefined1 auStack_448 [16];
  wchar_t local_438;
  short local_436;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c0136c78;
  uVar6 = 0;
  local_458[0] = 0;
  if ((undefined **)PTR_DAT_c0136c70 == &DAT_c01391e0) {
    iVar1 = FUN_c00feaac(&DAT_c00f32b8,&local_438,0x104,0);
    if (iVar1 != 0) {
      local_44c = 0x208;
      LVar2 = RegQueryValueExW((HKEY)&DAT_80000002,L"DefaultDBVol",(LPDWORD)L"System\\ObjectStore",
                               (LPDWORD)(local_458 + 2),(LPBYTE)awStack_230,&local_44c);
      if ((LVar2 == 0) && (local_458[2] == 1)) {
        if (((local_438 == L'\\') || (local_438 == L'/')) && (local_436 == 0)) {
          local_438 = L'\0';
        }
        HVar3 = StringCchCatW(&local_438,0x104,L"\\");
        if (((-1 < HVar3) && (HVar3 = StringCchCatW(&local_438,0x104,awStack_230), -1 < HVar3)) &&
           ((DVar4 = GetFileAttributesW(&local_438), DVar4 != 0xffffffff ||
            (iVar1 = FUN_c00fd4ec(&local_438,1), iVar1 != 0)))) {
          local_458[1] = 1;
          KernelIoControl(0x10100c4,local_458 + 1,4,local_458,4,0);
          uVar5 = 2;
          if (local_458[0] == 0) {
            uVar5 = 4;
          }
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
          iVar1 = __GetUserKData(0xc);
          iVar1 = FUN_c0125b28(auStack_448,&local_438,0,uVar5,0x82,(int *)&PTR_DAT_c0136850,0x7000,
                               iVar1);
          if (iVar1 == 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
          }
          else {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
            PTR_DAT_c0136c70 = (undefined *)FUN_c0124094((int *)auStack_448,2);
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
            if (PTR_DAT_c0136c70 != DAT_c01391e0) {
              FUN_c0123fc4((int *)PTR_DAT_c0136c70);
              *(undefined **)PTR_DAT_c0136c70 = DAT_c01391e0;
              DAT_c01391e0 = PTR_DAT_c0136c70;
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
            SetLastError(0);
            uVar6 = 1;
          }
        }
      }
      goto LAB_c0117214;
    }
    DVar4 = 0x15;
  }
  else {
    DVar4 = 0xb7;
  }
  SetLastError(DVar4);
LAB_c0117214:
  FUN_c013331c(local_28);
  return uVar6;
}



/* c0117244 FUN_c0117244 */

/* Boundary evidence: original MIPS .pdata c0117244..c0117467. Semantic name remains unreviewed. */

int FUN_c0117244(void *param_1,LPCWSTR param_2,uint param_3,int param_4)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  ushort uVar4;
  
  iVar3 = 0;
  iVar1 = CeGetCallerTrust();
  uVar4 = 2;
  if ((iVar1 == 2) || (iVar1 = IsSystemFile(param_2), iVar1 == 0)) {
    DVar2 = GetFileAttributesW(param_2);
    if ((DVar2 != 0xffffffff) && ((DVar2 & 1) != 0)) {
      uVar4 = 0x22;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
    iVar1 = IsProcessDying();
    if (iVar1 == 0) {
      iVar3 = FUN_c0125b28(param_1,param_2,0,param_3,uVar4,(int *)&PTR_DAT_c0136850,0x7000,param_4);
    }
    else {
      SetLastError(0x10dc);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
    if (iVar3 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c01394c4);
      DAT_c01394e0 = DAT_c0136858;
      if ((DAT_c01394e4 != -1) && (DAT_c0136858 != -1)) {
        CeSetThreadPriority();
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c01394c4);
    }
  }
  else {
    SetLastError(5);
  }
  return iVar3;
}



/* c0117468 FUN_c0117468 */

/* Boundary evidence: original MIPS .pdata c0117468..c0117473. Semantic name remains unreviewed. */

undefined4 FUN_c0117468(void)

{
  return 1;
}



/* c0117474 FUN_c0117474 */

/* Boundary evidence: original MIPS .pdata c0117474..c01175ab. Semantic name remains unreviewed. */

BOOL FUN_c0117474(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  BOOL BVar2;
  
  BVar2 = 0;
  if (param_1 == (int *)0x0) {
    FUN_c0120d34();
    BVar2 = 1;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
    iVar1 = IsProcessDying();
    if (iVar1 == 0) {
      BVar2 = FUN_c0124220(param_1,-0x3fec97b0,&DAT_c0136ec8,param_4);
      if (DAT_c0136ed0 != 0) {
        SetEventData(DAT_c0136ed0,DAT_c0136ec8);
      }
    }
    else {
      SetLastError(0x10dc);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  }
  return BVar2;
}



/* c01175ac FUN_c01175ac */

/* Boundary evidence: original MIPS .pdata c01175ac..c01175b7. Semantic name remains unreviewed. */

undefined4 FUN_c01175ac(void)

{
  return 1;
}



/* c01175b8 FUN_c01175b8 */

/* Boundary evidence: original MIPS .pdata c01175b8..c01176b3. Semantic name remains unreviewed. */

undefined4 FUN_c01175b8(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar1 = IsProcessDying();
  if (iVar1 == 0) {
    uVar2 = FUN_c0124ecc(param_1,-0x3fec97b0,param_2);
  }
  else {
    SetLastError(0x10dc);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return uVar2;
}



/* c01176b4 FUN_c01176b4 */

/* Boundary evidence: original MIPS .pdata c01176b4..c01176bf. Semantic name remains unreviewed. */

undefined4 FUN_c01176b4(void)

{
  return 1;
}



/* c01176c0 FUN_c01176c0 */

/* Boundary evidence: original MIPS .pdata c01176c0..c01177db. Semantic name remains unreviewed. */

undefined4 FUN_c01176c0(uint *param_1,wchar_t *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (0x103 < param_3) {
    param_3 = 0x104;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar1 = IsProcessDying();
  if (iVar1 == 0) {
    uVar2 = FUN_c012430c(param_1,param_2,param_3,-0x3fec97b0);
  }
  else {
    SetLastError(0x10dc);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return uVar2;
}



/* c01177dc FUN_c01177dc */

/* Boundary evidence: original MIPS .pdata c01177dc..c01177e7. Semantic name remains unreviewed. */

undefined4 FUN_c01177dc(void)

{
  return 1;
}



/* c01177e8 FUN_c01177e8 */

/* Boundary evidence: original MIPS .pdata c01177e8..c01178f3. Semantic name remains unreviewed. */

uint FUN_c01177e8(int *param_1,uint param_2,short *param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar1 = IsProcessDying();
  if (iVar1 == 0) {
    uVar2 = FUN_c0124990(param_1,param_2,param_3,-0x3fec97b0);
  }
  else {
    SetLastError(0x10dc);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return uVar2;
}



/* c01178f4 FUN_c01178f4 */

/* Boundary evidence: original MIPS .pdata c01178f4..c01178ff. Semantic name remains unreviewed. */

undefined4 FUN_c01178f4(void)

{
  return 1;
}



/* c0117900 FUN_c0117900 */

/* Boundary evidence: original MIPS .pdata c0117900..c0117993. Semantic name remains unreviewed. */

void FUN_c0117900(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  FUN_c0124ba4(param_1,-0x3fec97b0,param_3,param_4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return;
}



/* c0117994 FUN_c0117994 */

/* Boundary evidence: original MIPS .pdata c0117994..c011799f. Semantic name remains unreviewed. */

undefined4 FUN_c0117994(void)

{
  return 1;
}



/* c01179a0 FUN_c01179a0 */

/* Boundary evidence: original MIPS .pdata c01179a0..c0118a1b. Semantic name remains unreviewed. */

void FUN_c01179a0(void)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  
  pHVar1 = LoadLibraryW(L"sqlcese30.sys.dll");
  if (pHVar1 != (HMODULE)0x0) {
    DAT_c0136ec4 = LocalAlloc(0x40,0xd0);
    if (DAT_c0136ec4 != (HLOCAL)0x0) {
      uVar2 = GetProcAddressW(pHVar1,L"SqlCeOnServerLoad");
      *(undefined4 *)((int)DAT_c0136ec4 + 4) = uVar2;
      if (*(int *)((int)DAT_c0136ec4 + 4) == 0) {
        LocalFree(DAT_c0136ec4);
        DAT_c0136ec4 = (HLOCAL)0x0;
      }
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbAddDatabaseProps");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x18) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x18) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbAddSyncPartner");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x8c) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x8c) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbAttachCustomTrackingData");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xc0) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xc0) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbBeginSyncSession");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xa0) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xa0) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbBeginTransaction");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x84) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x84) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbChangeDatabaseLCID");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x74) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x74) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbCloseHandle");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x6c) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x6c) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbCreateDatabase");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x14) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x14) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbCreateSession");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x78) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x78) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbDeleteDatabase");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x2c) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x2c) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbDeleteRecord");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x4c) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x4c) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbEndSyncSession");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xa4) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xa4) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbEndTransaction");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x88) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x88) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbEnumDBVolumes");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x30) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x30) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbFindFirstDatabase");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x34) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x34) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbFindNextChangedRecord");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xb0) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xb0) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbFindNextDatabase");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x38) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x38) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbFlushDBVol");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x10) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x10) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbFreeNotification");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x70) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x70) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbGetChangedRecordCnt");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xa8) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xa8) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbGetChangedRecords");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xac) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xac) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbGetCustomTrackingData");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xc4) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xc4) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbGetDBInformationByHandle");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x28) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x28) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbGetDatabaseSession");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x80) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x80) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbGetPropChangeInfo");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xb4) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xb4) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbGetRecordChangeInfo");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xb8) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xb8) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbMarkRecord");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xbc) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xbc) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbMountDBVol");
    *(undefined4 *)((int)DAT_c0136ec4 + 8) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 8) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbOidGetInfo");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x68) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x68) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbOpenDatabase");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x3c) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x3c) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbOpenStream");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x50) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x50) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbPurgeTrackingData");
    *(undefined4 *)((int)DAT_c0136ec4 + 200) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 200) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbReadRecordProps");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x44) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x44) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbRemoveDatabaseProps");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x1c) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x1c) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbRemoveDatabaseTracking");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x98) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x98) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbRemoveSyncPartner");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x90) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x90) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbSeekDatabase");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x40) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x40) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbSetDatabaseInfo");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x24) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x24) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbSetSessionOption");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x7c) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x7c) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbStreamRead");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x54) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x54) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbStreamSaveChanges");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x5c) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x5c) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbStreamSeek");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x60) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x60) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbStreamSetSize");
    *(undefined4 *)((int)DAT_c0136ec4 + 100) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 100) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbStreamWrite");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x58) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x58) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbTrackDatabase");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x94) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x94) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbTrackProperty");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x9c) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x9c) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbUnmountDBVol");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xc) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xc) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbWriteRecordProps");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x48) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x48) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbGetDatabaseProps");
    *(undefined4 *)((int)DAT_c0136ec4 + 0x20) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0x20) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
    if (DAT_c0136ec4 == (HLOCAL)0x0) {
      return;
    }
    uVar2 = GetProcAddressW(pHVar1,L"EdbPurgeTrackingGenerations");
    *(undefined4 *)((int)DAT_c0136ec4 + 0xcc) = uVar2;
    if (*(int *)((int)DAT_c0136ec4 + 0xcc) == 0) {
      LocalFree(DAT_c0136ec4);
      DAT_c0136ec4 = (HLOCAL)0x0;
    }
  }
  if (DAT_c0136ec4 != (HLOCAL)0x0) {
    DAT_c013716c = CreateAPISet(&DAT_c00f3528,3,&PTR_FUN_c00f3328,&DAT_c00f33a8);
    DAT_c0137168 = CreateAPISet(&DAT_c00f3520,0x1d,&PTR_FUN_c00f33c0,&DAT_c00f3438);
    RegisterAPISet(DAT_c013716c,0x8000000a);
    RegisterAPISet(DAT_c0137168,0x80000009);
    RegisterDirectMethods(DAT_c0137168,&PTR_FUN_c00f3334);
    (**(code **)((int)DAT_c0136ec4 + 4))();
  }
  return;
}



/* c0118a1c FUN_c0118a1c */

/* Boundary evidence: original MIPS .pdata c0118a1c..c0118a43. Semantic name remains unreviewed. */

undefined4 FUN_c0118a1c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c0118a44 FUN_c0118a44 */

/* Boundary evidence: original MIPS .pdata c0118a44..c0118aef. Semantic name remains unreviewed. */

bool FUN_c0118a44(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = LocalAlloc(0x40,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
    puVar1[5] = DAT_c0136ec0;
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
    DAT_c0136ec0 = puVar1;
    puVar1[3] = param_2[3];
    puVar1[4] = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  }
  return puVar1 != (undefined4 *)0x0;
}



/* c0118af0 FUN_c0118af0 */

/* Boundary evidence: original MIPS .pdata c0118af0..c0118be3. Semantic name remains unreviewed. */

bool FUN_c0118af0(int param_1,void *param_2)

{
  void *pvVar1;
  void *_Buf1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  pvVar1 = (void *)0x0;
  _Buf1 = DAT_c0136ec0;
  do {
    if (_Buf1 == (void *)0x0) {
LAB_c0118b9c:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
      if (_Buf1 != (void *)0x0) {
        LocalFree(_Buf1);
      }
      return _Buf1 != (void *)0x0;
    }
    if ((*(int *)((int)_Buf1 + 0x10) == param_1) && (iVar2 = memcmp(_Buf1,param_2,0x10), iVar2 == 0)
       ) {
      if (pvVar1 == (void *)0x0) {
        DAT_c0136ec0 = *(void **)((int)_Buf1 + 0x14);
      }
      else {
        *(undefined4 *)((int)pvVar1 + 0x14) = *(undefined4 *)((int)_Buf1 + 0x14);
      }
      goto LAB_c0118b9c;
    }
    pvVar1 = _Buf1;
    _Buf1 = *(void **)((int)_Buf1 + 0x14);
  } while( true );
}



/* c0118be4 FUN_c0118be4 */

/* Boundary evidence: original MIPS .pdata c0118be4..c0118d27. Semantic name remains unreviewed. */

void FUN_c0118be4(int param_1)

{
  HLOCAL pvVar1;
  HLOCAL hMem;
  
  if (DAT_c0136ec4 == 0) {
    return;
  }
  do {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
    pvVar1 = (HLOCAL)0x0;
    for (hMem = DAT_c0136ec0; hMem != (HLOCAL)0x0; hMem = *(HLOCAL *)((int)hMem + 0x14)) {
      if (*(int *)((int)hMem + 0x10) == param_1) {
        if (pvVar1 == (HLOCAL)0x0) {
          DAT_c0136ec0 = *(HLOCAL *)((int)hMem + 0x14);
        }
        else {
          *(undefined4 *)((int)pvVar1 + 0x14) = *(undefined4 *)((int)hMem + 0x14);
        }
        break;
      }
      pvVar1 = hMem;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
    if (hMem == (HLOCAL)0x0) {
      return;
    }
    (**(code **)(DAT_c0136ec4 + 0xc))(hMem);
    LocalFree(hMem);
  } while( true );
}



/* c0118d28 FUN_c0118d28 */

/* Boundary evidence: original MIPS .pdata c0118d28..c0118d7f. Semantic name remains unreviewed. */

undefined4 FUN_c0118d28(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x28) = param_1;
  *(undefined4 *)(in_v0 + -0x2c) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x2c) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x28),0);
  }
  return 1;
}



/* c0118d80 FUN_c0118d80 */

/* Boundary evidence: original MIPS .pdata c0118d80..c0118ebf. Semantic name remains unreviewed. */

undefined4
FUN_c0118d80(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4,
            undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  DWORD dwErrCode;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar3 = 0;
  }
  else {
    iVar2 = (**(code **)(DAT_c0136ec4 + 8))(param_1,param_2,param_3,param_4 & 0x7fffffff);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      bVar1 = FUN_c0118a44(param_5,param_1);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        dwErrCode = GetLastError();
        (**(code **)(DAT_c0136ec4 + 0xc))(param_1);
        SetLastError(dwErrCode);
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}



/* c0118ec0 FUN_c0118ec0 */

/* Boundary evidence: original MIPS .pdata c0118ec0..c0118f17. Semantic name remains unreviewed. */

undefined4 FUN_c0118ec0(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x20) = param_1;
  *(undefined4 *)(in_v0 + -0x24) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x24) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x20),0);
  }
  return 1;
}



/* c0118f18 FUN_c0118f18 */

/* Boundary evidence: original MIPS .pdata c0118f18..c0119063. Semantic name remains unreviewed. */

undefined4 FUN_c0118f18(undefined4 *param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  int iVar3;
  DWORD dwErrCode;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar2 = 0;
  }
  else {
    bVar1 = FUN_c0118af0(param_2,param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      SetLastError(0x57);
      uVar2 = 0;
    }
    else {
      iVar3 = (**(code **)(DAT_c0136ec4 + 0xc))(param_1);
      if (iVar3 == 0) {
        dwErrCode = GetLastError();
        FUN_c0118a44(param_2,param_1);
        SetLastError(dwErrCode);
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



/* c0119064 FUN_c0119064 */

/* Boundary evidence: original MIPS .pdata c0119064..c01190bb. Semantic name remains unreviewed. */

undefined4 FUN_c0119064(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x20) = param_1;
  *(undefined4 *)(in_v0 + -0x24) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x24) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x20),0);
  }
  return 1;
}



/* c01190bc FUN_c01190bc */

/* Boundary evidence: original MIPS .pdata c01190bc..c01190df. Semantic name remains unreviewed. */

void FUN_c01190bc(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  FUN_c0118d80(param_1,param_2,0,param_3,param_4);
  return;
}



/* c01190e0 FUN_c01190e0 */

/* Boundary evidence: original MIPS .pdata c01190e0..c0119173. Semantic name remains unreviewed. */

undefined4 FUN_c01190e0(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x6c))();
  }
  return uVar1;
}



/* c0119174 FUN_c0119174 */

/* Boundary evidence: original MIPS .pdata c0119174..c01191cb. Semantic name remains unreviewed. */

undefined4 FUN_c0119174(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c01191cc FUN_c01191cc */

/* Boundary evidence: original MIPS .pdata c01191cc..c011925f. Semantic name remains unreviewed. */

undefined4 FUN_c01191cc(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x28))();
  }
  return uVar1;
}



/* c0119260 FUN_c0119260 */

/* Boundary evidence: original MIPS .pdata c0119260..c01192b7. Semantic name remains unreviewed. */

undefined4 FUN_c0119260(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c01192b8 FUN_c01192b8 */

/* Boundary evidence: original MIPS .pdata c01192b8..c011936f. Semantic name remains unreviewed. */

int FUN_c01192b8(void)

{
  int iVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    iVar1 = -1;
  }
  else {
    iVar1 = (**(code **)(DAT_c0136ec4 + 0x34))();
    if (iVar1 != -1) {
      iVar1 = CreateAPIHandle(DAT_c013716c,iVar1);
    }
  }
  return iVar1;
}



/* c0119370 FUN_c0119370 */

/* Boundary evidence: original MIPS .pdata c0119370..c01193c7. Semantic name remains unreviewed. */

undefined4 FUN_c0119370(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c01193c8 FUN_c01193c8 */

/* Boundary evidence: original MIPS .pdata c01193c8..c011945b. Semantic name remains unreviewed. */

undefined4 FUN_c01193c8(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x38))();
  }
  return uVar1;
}



/* c011945c FUN_c011945c */

/* Boundary evidence: original MIPS .pdata c011945c..c01194b3. Semantic name remains unreviewed. */

undefined4 FUN_c011945c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c01194b4 FUN_c01194b4 */

/* Boundary evidence: original MIPS .pdata c01194b4..c0119553. Semantic name remains unreviewed. */

undefined4 FUN_c01194b4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x14))(param_1,param_2,0,0,0);
  }
  return uVar1;
}



/* c0119554 FUN_c0119554 */

/* Boundary evidence: original MIPS .pdata c0119554..c01195ab. Semantic name remains unreviewed. */

undefined4 FUN_c0119554(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c01195ac FUN_c01195ac */

/* Boundary evidence: original MIPS .pdata c01195ac..c011963f. Semantic name remains unreviewed. */

undefined4 FUN_c01195ac(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x24))();
  }
  return uVar1;
}



/* c0119640 FUN_c0119640 */

/* Boundary evidence: original MIPS .pdata c0119640..c0119697. Semantic name remains unreviewed. */

undefined4 FUN_c0119640(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c0119698 FUN_c0119698 */

/* Boundary evidence: original MIPS .pdata c0119698..c0119773. Semantic name remains unreviewed. */

int FUN_c0119698(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    iVar1 = -1;
  }
  else {
    iVar1 = (**(code **)(DAT_c0136ec4 + 0x3c))(0,param_1,param_2,param_3,param_4,param_5,param_6);
    if (iVar1 != -1) {
      iVar1 = CreateAPIHandle(DAT_c0137168,iVar1);
    }
  }
  return iVar1;
}



/* c0119774 FUN_c0119774 */

/* Boundary evidence: original MIPS .pdata c0119774..c01197cb. Semantic name remains unreviewed. */

undefined4 FUN_c0119774(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c01197cc FUN_c01197cc */

/* Boundary evidence: original MIPS .pdata c01197cc..c011985f. Semantic name remains unreviewed. */

undefined4 FUN_c01197cc(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x2c))();
  }
  return uVar1;
}



/* c0119860 FUN_c0119860 */

/* Boundary evidence: original MIPS .pdata c0119860..c01198b7. Semantic name remains unreviewed. */

undefined4 FUN_c0119860(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c01198b8 FUN_c01198b8 */

/* Boundary evidence: original MIPS .pdata c01198b8..c011995f. Semantic name remains unreviewed. */

undefined4 FUN_c01198b8(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x40))();
  }
  return uVar1;
}



/* c0119960 FUN_c0119960 */

/* Boundary evidence: original MIPS .pdata c0119960..c01199b7. Semantic name remains unreviewed. */

undefined4 FUN_c0119960(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c01199b8 FUN_c01199b8 */

/* Boundary evidence: original MIPS .pdata c01199b8..c0119a5b. Semantic name remains unreviewed. */

undefined4 FUN_c01199b8(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x40))();
  }
  return uVar1;
}



/* c0119a5c FUN_c0119a5c */

/* Boundary evidence: original MIPS .pdata c0119a5c..c0119ab3. Semantic name remains unreviewed. */

undefined4 FUN_c0119a5c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c0119ab4 FUN_c0119ab4 */

/* Boundary evidence: original MIPS .pdata c0119ab4..c0119b47. Semantic name remains unreviewed. */

undefined4 FUN_c0119ab4(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x4c))();
  }
  return uVar1;
}



/* c0119b48 FUN_c0119b48 */

/* Boundary evidence: original MIPS .pdata c0119b48..c0119b9f. Semantic name remains unreviewed. */

undefined4 FUN_c0119b48(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c0119ba0 FUN_c0119ba0 */

/* Boundary evidence: original MIPS .pdata c0119ba0..c0119c4b. Semantic name remains unreviewed. */

undefined4 FUN_c0119ba0(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x44))();
  }
  return uVar1;
}



/* c0119c4c FUN_c0119c4c */

/* Boundary evidence: original MIPS .pdata c0119c4c..c0119ca3. Semantic name remains unreviewed. */

undefined4 FUN_c0119c4c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c0119ca4 FUN_c0119ca4 */

/* Boundary evidence: original MIPS .pdata c0119ca4..c0119d7f. Semantic name remains unreviewed. */

undefined4 FUN_c0119ca4(void)

{
  undefined4 uVar1;
  int iVar2;
  uint in_a3;
  undefined2 *puVar3;
  undefined1 *puVar4;
  int in_stack_00000010;
  int in_stack_0000001c;
  undefined2 local_20 [4];
  
  puVar3 = local_20;
  local_20[0] = (undefined2)(in_a3 >> 2);
  if (in_stack_00000010 == 0) {
    puVar3 = (undefined2 *)0x0;
  }
  puVar4 = &stack0x00000018;
  if (in_stack_0000001c == 0) {
    puVar4 = (undefined1 *)0x0;
  }
  uVar1 = FUN_c0119ba0();
  if (((in_stack_00000010 != 0) &&
      (iVar2 = CeSafeCopyMemory(in_stack_00000010,puVar3,2), iVar2 == 0)) ||
     ((in_stack_0000001c != 0 && (iVar2 = CeSafeCopyMemory(in_stack_0000001c,puVar4,4), iVar2 == 0))
     )) {
    SetLastError(0x57);
    uVar1 = 0;
  }
  return uVar1;
}



/* c0119d80 FUN_c0119d80 */

/* Boundary evidence: original MIPS .pdata c0119d80..c0119e2b. Semantic name remains unreviewed. */

undefined4 FUN_c0119d80(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x48))(param_1,param_2,param_4 >> 4 & 0xffff,param_3,1);
  }
  return uVar1;
}



/* c0119e2c FUN_c0119e2c */

/* Boundary evidence: original MIPS .pdata c0119e2c..c0119e83. Semantic name remains unreviewed. */

undefined4 FUN_c0119e2c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c0119e84 FUN_c0119e84 */

/* Boundary evidence: original MIPS .pdata c0119e84..c0119f2b. Semantic name remains unreviewed. */

undefined4 FUN_c0119e84(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x48))(param_1,param_2,param_4 >> 4 & 0xffff,param_3,0);
  }
  return uVar1;
}



/* c0119f2c FUN_c0119f2c */

/* Boundary evidence: original MIPS .pdata c0119f2c..c0119f83. Semantic name remains unreviewed. */

undefined4 FUN_c0119f2c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c0119f84 FUN_c0119f84 */

/* Boundary evidence: original MIPS .pdata c0119f84..c011a017. Semantic name remains unreviewed. */

undefined4 FUN_c0119f84(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x30))();
  }
  return uVar1;
}



/* c011a018 FUN_c011a018 */

/* Boundary evidence: original MIPS .pdata c011a018..c011a06f. Semantic name remains unreviewed. */

undefined4 FUN_c011a018(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011a070 FUN_c011a070 */

/* Boundary evidence: original MIPS .pdata c011a070..c011a12f. Semantic name remains unreviewed. */

undefined4 FUN_c011a070(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (DAT_c0136ec4 == 0) {
      return 1;
    }
  }
  else if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    return 0;
  }
  uVar1 = (**(code **)(DAT_c0136ec4 + 0x10))();
  return uVar1;
}



/* c011a130 FUN_c011a130 */

/* Boundary evidence: original MIPS .pdata c011a130..c011a187. Semantic name remains unreviewed. */

undefined4 FUN_c011a130(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011a188 FUN_c011a188 */

/* Boundary evidence: original MIPS .pdata c011a188..c011a21b. Semantic name remains unreviewed. */

undefined4 FUN_c011a188(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x68))();
  }
  return uVar1;
}



/* c011a21c FUN_c011a21c */

/* Boundary evidence: original MIPS .pdata c011a21c..c011a273. Semantic name remains unreviewed. */

undefined4 FUN_c011a21c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011a274 FUN_c011a274 */

/* Boundary evidence: original MIPS .pdata c011a274..c011a2d3. Semantic name remains unreviewed. */

void FUN_c011a274(void)

{
  if (DAT_c0136ec4 != 0) {
    (**(code **)(DAT_c0136ec4 + 0x74))();
  }
  return;
}



/* c011a2d4 FUN_c011a2d4 */

/* Boundary evidence: original MIPS .pdata c011a2d4..c011a32b. Semantic name remains unreviewed. */

undefined4 FUN_c011a2d4(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0xc) = param_1;
  *(undefined4 *)(in_v0 + -0x10) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x10) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0xc),0);
  }
  return 1;
}



/* c011a32c FUN_c011a32c */

/* Boundary evidence: original MIPS .pdata c011a32c..c011a3c7. Semantic name remains unreviewed. */

undefined4 FUN_c011a32c(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x14))();
  }
  return uVar1;
}



/* c011a3c8 FUN_c011a3c8 */

/* Boundary evidence: original MIPS .pdata c011a3c8..c011a41f. Semantic name remains unreviewed. */

undefined4 FUN_c011a3c8(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011a420 FUN_c011a420 */

/* Boundary evidence: original MIPS .pdata c011a420..c011a4bb. Semantic name remains unreviewed. */

undefined4 FUN_c011a420(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x18))();
  }
  return uVar1;
}



/* c011a4bc FUN_c011a4bc */

/* Boundary evidence: original MIPS .pdata c011a4bc..c011a513. Semantic name remains unreviewed. */

undefined4 FUN_c011a4bc(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011a514 FUN_c011a514 */

/* Boundary evidence: original MIPS .pdata c011a514..c011a5a7. Semantic name remains unreviewed. */

undefined4 FUN_c011a514(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x20))();
  }
  return uVar1;
}



/* c011a5a8 FUN_c011a5a8 */

/* Boundary evidence: original MIPS .pdata c011a5a8..c011a5ff. Semantic name remains unreviewed. */

undefined4 FUN_c011a5a8(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011a600 FUN_c011a600 */

/* Boundary evidence: original MIPS .pdata c011a600..c011a6e7. Semantic name remains unreviewed. */

undefined4
FUN_c011a600(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ushort local_20 [4];
  
  uVar3 = 0;
  local_20[0] = 0;
  if (param_2 != 0) {
    iVar1 = CeSafeCopyMemory(local_20,param_2,2);
    if (iVar1 == 0) goto LAB_c011a6b4;
    uVar3 = (uint)local_20[0];
  }
  if ((param_4 == uVar3 << 2) && (param_6 == uVar3 * 0x14)) {
    uVar2 = FUN_c011a514();
    if (param_2 == 0) {
      return uVar2;
    }
    iVar1 = CeSafeCopyMemory(param_2,local_20,2);
    if (iVar1 != 0) {
      return uVar2;
    }
  }
LAB_c011a6b4:
  SetLastError(0x57);
  return 0;
}



/* c011a6e8 FUN_c011a6e8 */

/* Boundary evidence: original MIPS .pdata c011a6e8..c011a77b. Semantic name remains unreviewed. */

undefined4 FUN_c011a6e8(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x1c))();
  }
  return uVar1;
}



/* c011a77c FUN_c011a77c */

/* Boundary evidence: original MIPS .pdata c011a77c..c011a7d3. Semantic name remains unreviewed. */

undefined4 FUN_c011a77c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011a7d4 FUN_c011a7d4 */

/* Boundary evidence: original MIPS .pdata c011a7d4..c011a88b. Semantic name remains unreviewed. */

int FUN_c011a7d4(void)

{
  int iVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    iVar1 = -1;
  }
  else {
    iVar1 = (**(code **)(DAT_c0136ec4 + 0x78))();
    if (iVar1 != -1) {
      iVar1 = CreateAPIHandle(DAT_c0137168,iVar1);
    }
  }
  return iVar1;
}



/* c011a88c FUN_c011a88c */

/* Boundary evidence: original MIPS .pdata c011a88c..c011a8e3. Semantic name remains unreviewed. */

undefined4 FUN_c011a88c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011a8e4 FUN_c011a8e4 */

/* Boundary evidence: original MIPS .pdata c011a8e4..c011a977. Semantic name remains unreviewed. */

undefined4 FUN_c011a8e4(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x7c))();
  }
  return uVar1;
}



/* c011a978 FUN_c011a978 */

/* Boundary evidence: original MIPS .pdata c011a978..c011a9cf. Semantic name remains unreviewed. */

undefined4 FUN_c011a978(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011a9d0 FUN_c011a9d0 */

/* Boundary evidence: original MIPS .pdata c011a9d0..c011aa87. Semantic name remains unreviewed. */

int FUN_c011a9d0(void)

{
  int iVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    iVar1 = -1;
  }
  else {
    iVar1 = (**(code **)(DAT_c0136ec4 + 0x80))();
    if (iVar1 != -1) {
      iVar1 = CreateAPIHandle(DAT_c0137168,iVar1);
    }
  }
  return iVar1;
}



/* c011aa88 FUN_c011aa88 */

/* Boundary evidence: original MIPS .pdata c011aa88..c011aadf. Semantic name remains unreviewed. */

undefined4 FUN_c011aa88(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011aae0 FUN_c011aae0 */

/* Boundary evidence: original MIPS .pdata c011aae0..c011ab73. Semantic name remains unreviewed. */

HANDLE FUN_c011aae0(void)

{
  HANDLE hSourceProcessHandle;
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  HANDLE local_18 [2];
  
  local_18[0] = (HANDLE)FUN_c011a9d0();
  if ((local_18[0] != (HANDLE)0x0) && (local_18[0] != (HANDLE)0xffffffff)) {
    hSourceProcessHandle = (HANDLE)__GetUserKData(0xc);
    hTargetProcessHandle = (HANDLE)GetCallerVMProcessId();
    BVar1 = DuplicateHandle(hSourceProcessHandle,local_18[0],hTargetProcessHandle,local_18,0,0,3);
    if (BVar1 == 0) {
      local_18[0] = (HANDLE)0xffffffff;
    }
  }
  return local_18[0];
}



/* c011ab74 FUN_c011ab74 */

/* Boundary evidence: original MIPS .pdata c011ab74..c011ac07. Semantic name remains unreviewed. */

undefined4 FUN_c011ab74(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x84))();
  }
  return uVar1;
}



/* c011ac08 FUN_c011ac08 */

/* Boundary evidence: original MIPS .pdata c011ac08..c011ac5f. Semantic name remains unreviewed. */

undefined4 FUN_c011ac08(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011ac60 FUN_c011ac60 */

/* Boundary evidence: original MIPS .pdata c011ac60..c011acf3. Semantic name remains unreviewed. */

undefined4 FUN_c011ac60(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x88))();
  }
  return uVar1;
}



/* c011acf4 FUN_c011acf4 */

/* Boundary evidence: original MIPS .pdata c011acf4..c011ad4b. Semantic name remains unreviewed. */

undefined4 FUN_c011acf4(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011ad4c FUN_c011ad4c */

/* Boundary evidence: original MIPS .pdata c011ad4c..c011ae1b. Semantic name remains unreviewed. */

int FUN_c011ad4c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    iVar1 = -1;
  }
  else {
    iVar1 = (**(code **)(DAT_c0136ec4 + 0x3c))();
    if (iVar1 != -1) {
      iVar1 = CreateAPIHandle(DAT_c0137168,iVar1);
    }
  }
  return iVar1;
}



/* c011ae1c FUN_c011ae1c */

/* Boundary evidence: original MIPS .pdata c011ae1c..c011ae73. Semantic name remains unreviewed. */

undefined4 FUN_c011ae1c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011ae74 FUN_c011ae74 */

/* Boundary evidence: original MIPS .pdata c011ae74..c011af1b. Semantic name remains unreviewed. */

HANDLE FUN_c011ae74(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  HANDLE hSourceProcessHandle;
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  HANDLE local_18 [2];
  
  local_18[0] = (HANDLE)FUN_c011ad4c(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if ((local_18[0] != (HANDLE)0x0) && (local_18[0] != (HANDLE)0xffffffff)) {
    hSourceProcessHandle = (HANDLE)__GetUserKData(0xc);
    hTargetProcessHandle = (HANDLE)GetCallerVMProcessId();
    BVar1 = DuplicateHandle(hSourceProcessHandle,local_18[0],hTargetProcessHandle,local_18,0,0,3);
    if (BVar1 == 0) {
      local_18[0] = (HANDLE)0xffffffff;
    }
  }
  return local_18[0];
}



/* c011af1c FUN_c011af1c */

/* Boundary evidence: original MIPS .pdata c011af1c..c011afd3. Semantic name remains unreviewed. */

int FUN_c011af1c(void)

{
  int iVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    iVar1 = -1;
  }
  else {
    iVar1 = (**(code **)(DAT_c0136ec4 + 0x50))();
    if (iVar1 != -1) {
      iVar1 = CreateAPIHandle(DAT_c0137168,iVar1);
    }
  }
  return iVar1;
}



/* c011afd4 FUN_c011afd4 */

/* Boundary evidence: original MIPS .pdata c011afd4..c011b02b. Semantic name remains unreviewed. */

undefined4 FUN_c011afd4(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b02c FUN_c011b02c */

/* Boundary evidence: original MIPS .pdata c011b02c..c011b0bf. Semantic name remains unreviewed. */

HANDLE FUN_c011b02c(void)

{
  HANDLE hSourceProcessHandle;
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  HANDLE local_18 [2];
  
  local_18[0] = (HANDLE)FUN_c011af1c();
  if ((local_18[0] != (HANDLE)0x0) && (local_18[0] != (HANDLE)0xffffffff)) {
    hSourceProcessHandle = (HANDLE)__GetUserKData(0xc);
    hTargetProcessHandle = (HANDLE)GetCallerVMProcessId();
    BVar1 = DuplicateHandle(hSourceProcessHandle,local_18[0],hTargetProcessHandle,local_18,0,0,3);
    if (BVar1 == 0) {
      local_18[0] = (HANDLE)0xffffffff;
    }
  }
  return local_18[0];
}



/* c011b0c0 FUN_c011b0c0 */

/* Boundary evidence: original MIPS .pdata c011b0c0..c011b153. Semantic name remains unreviewed. */

undefined4 FUN_c011b0c0(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x54))();
  }
  return uVar1;
}



/* c011b154 FUN_c011b154 */

/* Boundary evidence: original MIPS .pdata c011b154..c011b1ab. Semantic name remains unreviewed. */

undefined4 FUN_c011b154(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b1ac FUN_c011b1ac */

/* Boundary evidence: original MIPS .pdata c011b1ac..c011b23f. Semantic name remains unreviewed. */

undefined4 FUN_c011b1ac(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x58))();
  }
  return uVar1;
}



/* c011b240 FUN_c011b240 */

/* Boundary evidence: original MIPS .pdata c011b240..c011b297. Semantic name remains unreviewed. */

undefined4 FUN_c011b240(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b298 FUN_c011b298 */

/* Boundary evidence: original MIPS .pdata c011b298..c011b32b. Semantic name remains unreviewed. */

undefined4 FUN_c011b298(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x5c))();
  }
  return uVar1;
}



/* c011b32c FUN_c011b32c */

/* Boundary evidence: original MIPS .pdata c011b32c..c011b383. Semantic name remains unreviewed. */

undefined4 FUN_c011b32c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b384 FUN_c011b384 */

/* Boundary evidence: original MIPS .pdata c011b384..c011b417. Semantic name remains unreviewed. */

undefined4 FUN_c011b384(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x60))();
  }
  return uVar1;
}



/* c011b418 FUN_c011b418 */

/* Boundary evidence: original MIPS .pdata c011b418..c011b46f. Semantic name remains unreviewed. */

undefined4 FUN_c011b418(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b470 FUN_c011b470 */

/* Boundary evidence: original MIPS .pdata c011b470..c011b503. Semantic name remains unreviewed. */

undefined4 FUN_c011b470(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 100))();
  }
  return uVar1;
}



/* c011b504 FUN_c011b504 */

/* Boundary evidence: original MIPS .pdata c011b504..c011b55b. Semantic name remains unreviewed. */

undefined4 FUN_c011b504(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b55c FUN_c011b55c */

/* Boundary evidence: original MIPS .pdata c011b55c..c011b5ef. Semantic name remains unreviewed. */

undefined4 FUN_c011b55c(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x8c))();
  }
  return uVar1;
}



/* c011b5f0 FUN_c011b5f0 */

/* Boundary evidence: original MIPS .pdata c011b5f0..c011b647. Semantic name remains unreviewed. */

undefined4 FUN_c011b5f0(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b648 FUN_c011b648 */

/* Boundary evidence: original MIPS .pdata c011b648..c011b6db. Semantic name remains unreviewed. */

undefined4 FUN_c011b648(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x90))();
  }
  return uVar1;
}



/* c011b6dc FUN_c011b6dc */

/* Boundary evidence: original MIPS .pdata c011b6dc..c011b733. Semantic name remains unreviewed. */

undefined4 FUN_c011b6dc(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b734 FUN_c011b734 */

/* Boundary evidence: original MIPS .pdata c011b734..c011b7c7. Semantic name remains unreviewed. */

undefined4 FUN_c011b734(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x94))();
  }
  return uVar1;
}



/* c011b7c8 FUN_c011b7c8 */

/* Boundary evidence: original MIPS .pdata c011b7c8..c011b81f. Semantic name remains unreviewed. */

undefined4 FUN_c011b7c8(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b820 FUN_c011b820 */

/* Boundary evidence: original MIPS .pdata c011b820..c011b8b3. Semantic name remains unreviewed. */

undefined4 FUN_c011b820(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x98))();
  }
  return uVar1;
}



/* c011b8b4 FUN_c011b8b4 */

/* Boundary evidence: original MIPS .pdata c011b8b4..c011b90b. Semantic name remains unreviewed. */

undefined4 FUN_c011b8b4(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b90c FUN_c011b90c */

/* Boundary evidence: original MIPS .pdata c011b90c..c011b99f. Semantic name remains unreviewed. */

undefined4 FUN_c011b90c(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x9c))();
  }
  return uVar1;
}



/* c011b9a0 FUN_c011b9a0 */

/* Boundary evidence: original MIPS .pdata c011b9a0..c011b9f7. Semantic name remains unreviewed. */

undefined4 FUN_c011b9a0(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011b9f8 FUN_c011b9f8 */

/* Boundary evidence: original MIPS .pdata c011b9f8..c011bab3. Semantic name remains unreviewed. */

undefined4
FUN_c011b9f8(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xa0))
                      (param_1,param_2,*param_3,param_3[1],*param_4,param_4[1],param_5,param_6);
  }
  return uVar1;
}



/* c011bab4 FUN_c011bab4 */

/* Boundary evidence: original MIPS .pdata c011bab4..c011bb0b. Semantic name remains unreviewed. */

undefined4 FUN_c011bab4(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011bb0c FUN_c011bb0c */

/* Boundary evidence: original MIPS .pdata c011bb0c..c011bb9f. Semantic name remains unreviewed. */

undefined4 FUN_c011bb0c(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xa4))();
  }
  return uVar1;
}



/* c011bba0 FUN_c011bba0 */

/* Boundary evidence: original MIPS .pdata c011bba0..c011bbf7. Semantic name remains unreviewed. */

undefined4 FUN_c011bba0(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011bbf8 FUN_c011bbf8 */

/* Boundary evidence: original MIPS .pdata c011bbf8..c011bc8b. Semantic name remains unreviewed. */

undefined4 FUN_c011bbf8(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xa8))();
  }
  return uVar1;
}



/* c011bc8c FUN_c011bc8c */

/* Boundary evidence: original MIPS .pdata c011bc8c..c011bce3. Semantic name remains unreviewed. */

undefined4 FUN_c011bc8c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011bce4 FUN_c011bce4 */

/* Boundary evidence: original MIPS .pdata c011bce4..c011bd9b. Semantic name remains unreviewed. */

int FUN_c011bce4(void)

{
  int iVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    iVar1 = -1;
  }
  else {
    iVar1 = (**(code **)(DAT_c0136ec4 + 0xac))();
    if (iVar1 != -1) {
      iVar1 = CreateAPIHandle(DAT_c0137168,iVar1);
    }
  }
  return iVar1;
}



/* c011bd9c FUN_c011bd9c */

/* Boundary evidence: original MIPS .pdata c011bd9c..c011bdf3. Semantic name remains unreviewed. */

undefined4 FUN_c011bd9c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011bdf4 FUN_c011bdf4 */

/* Boundary evidence: original MIPS .pdata c011bdf4..c011be87. Semantic name remains unreviewed. */

HANDLE FUN_c011bdf4(void)

{
  HANDLE hSourceProcessHandle;
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  HANDLE local_18 [2];
  
  local_18[0] = (HANDLE)FUN_c011bce4();
  if ((local_18[0] != (HANDLE)0x0) && (local_18[0] != (HANDLE)0xffffffff)) {
    hSourceProcessHandle = (HANDLE)__GetUserKData(0xc);
    hTargetProcessHandle = (HANDLE)GetCallerVMProcessId();
    BVar1 = DuplicateHandle(hSourceProcessHandle,local_18[0],hTargetProcessHandle,local_18,0,0,3);
    if (BVar1 == 0) {
      local_18[0] = (HANDLE)0xffffffff;
    }
  }
  return local_18[0];
}



/* c011be88 FUN_c011be88 */

/* Boundary evidence: original MIPS .pdata c011be88..c011bf1b. Semantic name remains unreviewed. */

undefined4 FUN_c011be88(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xb0))();
  }
  return uVar1;
}



/* c011bf1c FUN_c011bf1c */

/* Boundary evidence: original MIPS .pdata c011bf1c..c011bf73. Semantic name remains unreviewed. */

undefined4 FUN_c011bf1c(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011bf74 FUN_c011bf74 */

/* Boundary evidence: original MIPS .pdata c011bf74..c011c007. Semantic name remains unreviewed. */

undefined4 FUN_c011bf74(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xb4))();
  }
  return uVar1;
}



/* c011c008 FUN_c011c008 */

/* Boundary evidence: original MIPS .pdata c011c008..c011c05f. Semantic name remains unreviewed. */

undefined4 FUN_c011c008(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011c060 FUN_c011c060 */

/* Boundary evidence: original MIPS .pdata c011c060..c011c0f3. Semantic name remains unreviewed. */

undefined4 FUN_c011c060(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xb8))();
  }
  return uVar1;
}



/* c011c0f4 FUN_c011c0f4 */

/* Boundary evidence: original MIPS .pdata c011c0f4..c011c14b. Semantic name remains unreviewed. */

undefined4 FUN_c011c0f4(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011c14c FUN_c011c14c */

/* Boundary evidence: original MIPS .pdata c011c14c..c011c1df. Semantic name remains unreviewed. */

undefined4 FUN_c011c14c(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xbc))();
  }
  return uVar1;
}



/* c011c1e0 FUN_c011c1e0 */

/* Boundary evidence: original MIPS .pdata c011c1e0..c011c237. Semantic name remains unreviewed. */

undefined4 FUN_c011c1e0(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011c238 FUN_c011c238 */

/* Boundary evidence: original MIPS .pdata c011c238..c011c2cb. Semantic name remains unreviewed. */

undefined4 FUN_c011c238(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xc0))();
  }
  return uVar1;
}



/* c011c2cc FUN_c011c2cc */

/* Boundary evidence: original MIPS .pdata c011c2cc..c011c323. Semantic name remains unreviewed. */

undefined4 FUN_c011c2cc(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011c324 FUN_c011c324 */

/* Boundary evidence: original MIPS .pdata c011c324..c011c3b7. Semantic name remains unreviewed. */

undefined4 FUN_c011c324(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xc4))();
  }
  return uVar1;
}



/* c011c3b8 FUN_c011c3b8 */

/* Boundary evidence: original MIPS .pdata c011c3b8..c011c40f. Semantic name remains unreviewed. */

undefined4 FUN_c011c3b8(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011c410 FUN_c011c410 */

/* Boundary evidence: original MIPS .pdata c011c410..c011c487. Semantic name remains unreviewed. */

void FUN_c011c410(void)

{
  undefined4 in_a3;
  undefined4 *in_stack_00000010;
  
  FUN_c011c324();
  if (in_stack_00000010 != (undefined4 *)0x0) {
    *in_stack_00000010 = in_a3;
  }
  return;
}



/* c011c488 FUN_c011c488 */

/* Boundary evidence: original MIPS .pdata c011c488..c011c493. Semantic name remains unreviewed. */

undefined4 FUN_c011c488(void)

{
  return 1;
}



/* c011c494 FUN_c011c494 */

/* Boundary evidence: original MIPS .pdata c011c494..c011c527. Semantic name remains unreviewed. */

undefined4 FUN_c011c494(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 200))();
  }
  return uVar1;
}



/* c011c528 FUN_c011c528 */

/* Boundary evidence: original MIPS .pdata c011c528..c011c57f. Semantic name remains unreviewed. */

undefined4 FUN_c011c528(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011c580 FUN_c011c580 */

/* Boundary evidence: original MIPS .pdata c011c580..c011c613. Semantic name remains unreviewed. */

undefined4 FUN_c011c580(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0xcc))();
  }
  return uVar1;
}



/* c011c614 FUN_c011c614 */

/* Boundary evidence: original MIPS .pdata c011c614..c011c66b. Semantic name remains unreviewed. */

undefined4 FUN_c011c614(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011c66c FUN_c011c66c */

/* Boundary evidence: original MIPS .pdata c011c66c..c011c6ff. Semantic name remains unreviewed. */

undefined4 FUN_c011c66c(void)

{
  undefined4 uVar1;
  
  if (DAT_c0136ec4 == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_c0136ec4 + 0x70))();
  }
  return uVar1;
}



/* c011c700 FUN_c011c700 */

/* Boundary evidence: original MIPS .pdata c011c700..c011c757. Semantic name remains unreviewed. */

undefined4 FUN_c011c700(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 **)(in_v0 + -0x14) = param_1;
  *(undefined4 *)(in_v0 + -0x18) = *(undefined4 *)*param_1;
  if (*(int *)(in_v0 + -0x18) != 0x3eb) {
    ReportFault(*(undefined4 *)(in_v0 + -0x14),0);
  }
  return 1;
}



/* c011c758 FUN_c011c758 */

/* Boundary evidence: original MIPS .pdata c011c758..c011c9cf. Semantic name remains unreviewed. */

int FUN_c011c758(wchar_t *param_1,wchar_t *param_2,LPCWSTR param_3)

{
  uint uVar1;
  HLOCAL lpBuffer;
  size_t sVar2;
  size_t sVar3;
  BOOL BVar4;
  wchar_t *_Dest;
  HANDLE hFile;
  int iVar5;
  HANDLE hFile_00;
  uint local_30;
  DWORD DStack_2c;
  
  iVar5 = 0;
  hFile = (HANDLE)0xffffffff;
  hFile_00 = (HANDLE)0xffffffff;
  _Dest = (LPCWSTR)0x0;
  lpBuffer = LocalAlloc(0,0x100a);
  if (lpBuffer != (HLOCAL)0x0) {
    sVar2 = wcslen(param_1);
    sVar3 = wcslen(param_2);
    if (((sVar2 != 0) && (sVar3 != 0)) &&
       (_Dest = LocalAlloc(0,(sVar3 + sVar2 + 10) * 2), _Dest != (wchar_t *)0x0)) {
      wcscpy(_Dest,param_1);
      if (_Dest[sVar2 - 1] != L'\\') {
        wcscat(_Dest,L"\\");
      }
      wcscat(_Dest,param_2);
      hFile_00 = CreateFileW(param_3,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
      if ((hFile_00 != (HANDLE)0xffffffff) &&
         (hFile = CreateFileW(_Dest,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0),
         hFile != (HANDLE)0xffffffff)) {
        SetFilePointer(hFile,0,(PLONG)0x0,0);
        do {
          BVar4 = ReadFile(hFile_00,lpBuffer,0x1000,&local_30,(LPOVERLAPPED)0x0);
          uVar1 = local_30;
          if ((BVar4 == 0) || (local_30 == 0)) break;
          BVar4 = WriteFile(hFile,lpBuffer,local_30,&DStack_2c,(LPOVERLAPPED)0x0);
          if (BVar4 == 0) goto LAB_c011c944;
        } while (0xfff < uVar1);
        iVar5 = 1;
      }
    }
LAB_c011c944:
    LocalFree(lpBuffer);
    if (_Dest != (LPCWSTR)0x0) {
      LocalFree(_Dest);
    }
    if (hFile_00 != (HANDLE)0xffffffff) {
      CloseHandle(hFile_00);
    }
    if ((hFile != (HANDLE)0xffffffff) && (CloseHandle(hFile), iVar5 == 0)) {
      DeleteFileW(_Dest);
    }
  }
  return iVar5;
}



/* c011c9d0 FUN_c011c9d0 */

/* Boundary evidence: original MIPS .pdata c011c9d0..c011cad7. Semantic name remains unreviewed. */

short FUN_c011c9d0(void)

{
  short sVar1;
  BOOL BVar2;
  uint uVar3;
  LPVOID lpBuffer;
  uint local_20 [2];
  
  lpBuffer = DAT_c0137158;
  if (DAT_c0137154 == 0) {
    do {
      if ((DAT_c013715c == 0) || (0x2000 < DAT_c013715c)) {
        BVar2 = ReadFile(DAT_c0137160,lpBuffer,0x2000,local_20,(LPOVERLAPPED)0x0);
        if (BVar2 == 0) {
          return -1;
        }
        if (local_20[0] < 0x2000) {
          *(undefined2 *)((local_20[0] & 0xfffffffe) + (int)DAT_c0137158) = 0xffff;
        }
        DAT_c013715c = 1;
        lpBuffer = DAT_c0137158;
      }
      uVar3 = DAT_c013715c + 2;
      sVar1 = *(short *)((int)lpBuffer + (DAT_c013715c - 1));
      DAT_c013715c = uVar3;
    } while (sVar1 == 0xd);
  }
  else {
    DAT_c0137154 = 0;
    sVar1 = DAT_c0137164;
  }
  return sVar1;
}



/* c011cad8 FUN_c011cad8 */

uint FUN_c011cad8(int param_1,uint param_2)

{
  if (param_1 < 0x2a) {
    if (param_1 == 0x29) {
      return param_2 & 0x40;
    }
    if (param_1 == 10) {
      return param_2 & 0x80;
    }
    if (param_1 == 0x20) {
      return param_2 & 1;
    }
    if (param_1 == 0x22) {
      return param_2 & 0x10;
    }
    if (param_1 == 0x28) {
      return param_2 & 0x20;
    }
  }
  else {
    if (param_1 == 0x2c) {
      return param_2 & 8;
    }
    if (param_1 == 0x2d) {
      return param_2 & 2;
    }
    if (param_1 == 0x2e) {
      return param_2 & 0x100;
    }
    if (param_1 == 0x3a) {
      return param_2 & 4;
    }
  }
  return 0;
}



/* c011cba8 FUN_c011cba8 */

/* Boundary evidence: original MIPS .pdata c011cba8..c011ce67. Semantic name remains unreviewed. */

undefined4 FUN_c011cba8(uint *param_1,short *param_2,uint param_3)

{
  short sVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  uint uVar3;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  uint uVar4;
  int iVar2;
  
  do {
    if ((param_3 & 1) == 0) {
      sVar1 = FUN_c011c9d0();
      iVar2 = CONCAT22(extraout_var,sVar1);
    }
    else {
      do {
        sVar1 = FUN_c011c9d0();
        iVar2 = CONCAT22(extraout_var_01,sVar1);
        if (iVar2 == -1) break;
      } while ((iVar2 == 0x20) || (iVar2 == 9));
    }
    if (iVar2 == 0xffff) {
      return 0xffffffff;
    }
    if ((iVar2 != 0x3b) && (iVar2 != 0x23)) break;
    do {
      sVar1 = FUN_c011c9d0();
      if (CONCAT22(extraout_var_00,sVar1) == 10) break;
    } while (CONCAT22(extraout_var_00,sVar1) != -1);
    DAT_c0136c64 = DAT_c0136c64 + 1;
  } while( true );
  uVar3 = FUN_c011cad8(iVar2,param_3);
  if (uVar3 != 0) {
    if (iVar2 == 10) {
      return 6;
    }
    if (iVar2 == 0x22) {
      return 5;
    }
    if (iVar2 == 0x28) {
      return 4;
    }
    if (iVar2 == 0x29) {
      return 3;
    }
    if (iVar2 == 0x2c) {
      return 1;
    }
    if (iVar2 == 0x2e) {
      return 0x1d;
    }
    if (iVar2 == 0x3a) {
      sVar1 = FUN_c011c9d0();
      iVar2 = CONCAT22(extraout_var_02,sVar1);
      if (iVar2 == 0x2d) {
        return 2;
      }
      if (iVar2 == -1) {
        return 0xffffffff;
      }
    }
  }
  *param_2 = (short)iVar2;
  uVar3 = 1;
  do {
    param_2 = param_2 + 1;
    sVar1 = FUN_c011c9d0();
    iVar2 = CONCAT22(extraout_var_03,sVar1);
    if (iVar2 < 0x23) {
      if (iVar2 != 0x22) {
        if (iVar2 == -1) {
          return 0xffffffff;
        }
        if ((iVar2 != 10) && (iVar2 != 0x20)) goto LAB_c011cdf4;
      }
LAB_c011cde0:
      uVar4 = FUN_c011cad8(iVar2,param_3);
      if (uVar4 != 0) {
        if (DAT_c0137154 != 0) {
          return 0;
        }
        DAT_c0137154 = 1;
        DAT_c0137164 = sVar1;
        *param_1 = uVar3;
        return 7;
      }
    }
    else if ((0x27 < iVar2) &&
            ((iVar2 < 0x2a || ((0x2b < iVar2 && ((iVar2 < 0x2f || (iVar2 == 0x3a))))))))
    goto LAB_c011cde0;
LAB_c011cdf4:
    uVar3 = uVar3 + 1;
    *param_2 = sVar1;
    if (0x103 < uVar3) {
      return 0;
    }
  } while( true );
}



/* c011ce68 FUN_c011ce68 */

/* Boundary evidence: original MIPS .pdata c011ce68..c011d00f. Semantic name remains unreviewed. */

int FUN_c011ce68(void)

{
  wchar_t wVar1;
  int iVar2;
  uint uVar3;
  wchar_t *pwVar4;
  uint local_228 [2];
  wchar_t local_220 [260];
  uint local_18;
  
  local_18 = DAT_c0136c78;
  iVar2 = FUN_c011cba8(local_228,local_220,0x1ff);
  if (iVar2 != 7) {
    FUN_c013331c(local_18);
    return iVar2;
  }
  if (local_228[0] < 0x10) {
    local_220[local_228[0]] = L'\0';
    if (local_228[0] != 0) {
      pwVar4 = local_220;
      uVar3 = local_228[0];
      do {
        wVar1 = towupper(*pwVar4);
        uVar3 = uVar3 - 1;
        *pwVar4 = wVar1;
        pwVar4 = pwVar4 + 1;
      } while (uVar3 != 0);
    }
    if (local_220[0] == L'D') {
      iVar2 = wcscmp(local_220,L"DIRECTORY");
      if ((iVar2 == 0) || (iVar2 = wcscmp(local_220,L"DIR"), iVar2 == 0)) {
        FUN_c013331c(local_18);
        return 0x1e;
      }
    }
    else if (local_220[0] == L'F') {
      iVar2 = wcscmp(local_220,L"FILE");
      if (iVar2 == 0) {
        FUN_c013331c(local_18);
        return 0x1f;
      }
    }
    else if (local_220[0] == L'P') {
      iVar2 = wcscmp(local_220,L"PERMDIR");
      if (iVar2 == 0) {
        FUN_c013331c(local_18);
        return 0x20;
      }
    }
    else if ((local_220[0] == L'R') && (iVar2 = wcscmp(local_220,L"ROOT"), iVar2 == 0)) {
      FUN_c013331c(local_18);
      return 0x15;
    }
  }
  FUN_c013331c(local_18);
  return 0;
}



/* c011d010 FUN_c011d010 */

/* Boundary evidence: original MIPS .pdata c011d010..c011d08f. Semantic name remains unreviewed. */

int FUN_c011d010(short *param_1)

{
  int iVar1;
  uint local_18 [2];
  
  iVar1 = FUN_c011ce68();
  if (((iVar1 == 5) && (iVar1 = FUN_c011cba8(local_18,param_1,0x10), iVar1 == 7)) &&
     (iVar1 = FUN_c011ce68(), iVar1 == 5)) {
    param_1[local_18[0]] = 0;
    iVar1 = 0x1c;
  }
  return iVar1;
}



/* c011d090 FUN_c011d090 */

/* Boundary evidence: original MIPS .pdata c011d090..c011d377. Semantic name remains unreviewed. */

undefined4 FUN_c011d090(wchar_t *param_1)

{
  bool bVar1;
  LPCWSTR hMem;
  wchar_t *_Str;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  DWORD DVar5;
  wchar_t *_Dest;
  undefined4 uVar6;
  
  _Dest = (wchar_t *)0x0;
  hMem = LocalAlloc(0,0x20a);
  if (hMem != (LPCWSTR)0x0) {
    _Str = LocalAlloc(0,0x20a);
    if (_Str != (wchar_t *)0x0) {
      iVar2 = FUN_c011ce68();
      if (iVar2 == 6) {
LAB_c011d320:
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
        do {
          bVar1 = false;
          if (iVar2 == 0x1e) {
LAB_c011d158:
            iVar2 = FUN_c011ce68();
            if (iVar2 != 4) goto LAB_c011d320;
            iVar2 = FUN_c011d010(_Str);
            if (iVar2 != 0x1c) {
              *_Str = L'\0';
              goto LAB_c011d320;
            }
            sVar3 = wcslen(param_1);
            sVar4 = wcslen(_Str);
            _Dest = LocalAlloc(0,(sVar4 + sVar3 + 10) * 2);
            if (_Dest == (wchar_t *)0x0) goto LAB_c011d320;
            wcscpy(_Dest,param_1);
            if ((*_Dest != L'\\') || (_Dest[1] != L'\0')) {
              wcscat(_Dest,L"\\");
            }
            wcscat(_Dest,_Str);
            if (bVar1) {
              iVar2 = FUN_c00fc5a0(_Dest);
            }
            else {
              iVar2 = CreateDirectoryW(_Dest,(LPSECURITY_ATTRIBUTES)0x0);
            }
            if ((iVar2 == 0) && (DVar5 = GetLastError(), DVar5 != 0xb7)) goto LAB_c011d320;
          }
          else {
            if (iVar2 != 0x1f) {
              if (iVar2 == 0x20) {
                bVar1 = true;
                goto LAB_c011d158;
              }
              goto LAB_c011d320;
            }
            iVar2 = FUN_c011ce68();
            if (iVar2 != 4) goto LAB_c011d320;
            iVar2 = FUN_c011d010(_Str);
            if (iVar2 != 0x1c) {
              *_Str = L'\0';
LAB_c011d314:
              *hMem = L'\0';
              goto LAB_c011d320;
            }
            iVar2 = FUN_c011ce68();
            if (iVar2 != 1) goto LAB_c011d320;
            iVar2 = FUN_c011d010(hMem);
            if (iVar2 == 0x1c) {
              iVar2 = 0x1a;
            }
            if (iVar2 != 0x1a) goto LAB_c011d314;
            iVar2 = FUN_c011c758(param_1,_Str,hMem);
            if (iVar2 == 0) goto LAB_c011d320;
          }
          iVar2 = FUN_c011ce68();
          if (iVar2 != 3) goto LAB_c011d320;
          iVar2 = FUN_c011ce68();
          if ((iVar2 == 6) || (iVar2 == -1)) break;
          if (iVar2 != 1) goto LAB_c011d320;
          iVar2 = FUN_c011ce68();
        } while ((iVar2 != 6) || (iVar2 = FUN_c011ce68(), iVar2 != 6));
      }
      LocalFree(hMem);
      LocalFree(_Str);
      if (_Dest == (wchar_t *)0x0) {
        return uVar6;
      }
      LocalFree(_Dest);
      return uVar6;
    }
    LocalFree(hMem);
  }
  return 0;
}



/* c011d378 FUN_c011d378 */

/* Boundary evidence: original MIPS .pdata c011d378..c011d4fb. Semantic name remains unreviewed. */

undefined4 FUN_c011d378(LPCWSTR param_1)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  bVar1 = false;
  iVar2 = FUN_c011ce68();
  while (iVar2 == 6) {
    DAT_c0136c64 = DAT_c0136c64 + 1;
    iVar2 = FUN_c011ce68();
  }
  uVar5 = 0x15;
  if (iVar2 == 0x15) {
    *param_1 = L'\\';
    param_1[1] = L'\0';
    DVar3 = FUN_c011ce68();
    DVar4 = 2;
LAB_c011d4c4:
    if (DVar3 == DVar4) goto LAB_c011d4d0;
  }
  else {
    uVar5 = 0x1e;
    if (iVar2 == 0x1e) {
LAB_c011d408:
      iVar2 = FUN_c011ce68();
      if (iVar2 == 4) {
        iVar2 = FUN_c011d010(param_1);
        if (iVar2 == 0x1c) {
          iVar2 = 0x1a;
        }
        if (((iVar2 == 0x1a) && (iVar2 = FUN_c011ce68(), iVar2 == 3)) &&
           (iVar2 = FUN_c011ce68(), iVar2 == 2)) {
          if (bVar1) {
            iVar2 = FUN_c00fc5a0(param_1);
          }
          else {
            iVar2 = CreateDirectoryW(param_1,(LPSECURITY_ATTRIBUTES)0x0);
          }
          if (iVar2 != 0) goto LAB_c011d4d0;
          DVar3 = GetLastError();
          DVar4 = 0xb7;
          goto LAB_c011d4c4;
        }
      }
    }
    else {
      if (iVar2 == 0x20) {
        bVar1 = true;
        goto LAB_c011d408;
      }
      uVar5 = 0xffffffff;
      if (iVar2 == -1) goto LAB_c011d4d0;
      *param_1 = L'\0';
    }
  }
  uVar5 = 0;
LAB_c011d4d0:
  DAT_c0136c64 = DAT_c0136c64 + 1;
  return uVar5;
}



/* c011d4fc FUN_c011d4fc */

/* Boundary evidence: original MIPS .pdata c011d4fc..c011d72f. Semantic name remains unreviewed. */

void FUN_c011d4fc(void)

{
  short sVar1;
  int iVar2;
  HANDLE hObject;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  iVar2 = FUN_c00feaac(&DAT_c00f3da8,awStack_238,0x104,0);
  if (iVar2 != 0) {
    DAT_c013715c = 0;
    hObject = CreateFileW(L"\\Windows\\initobj.dat",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                          (HANDLE)0x0);
    if ((hObject != (HANDLE)0xffffffff) &&
       (DAT_c0137158 = LocalAlloc(0,0x2000), DAT_c0137158 == (HLOCAL)0x0)) {
      CloseHandle(hObject);
      hObject = (HANDLE)0xffffffff;
    }
    DAT_c0137160 = hObject;
    if (hObject != (HANDLE)0xffffffff) {
      iVar2 = FUN_c011d378(awStack_238);
      if (iVar2 == 0x15) {
        iVar2 = 0x15;
        do {
          if (((iVar2 == 0x15) || (iVar2 == 0x1e)) || (iVar2 == 0x20)) {
            iVar2 = FUN_c011d090(awStack_238);
            if (iVar2 == 0) {
              do {
                sVar1 = FUN_c011c9d0();
                if (CONCAT22(extraout_var_00,sVar1) == 10) break;
              } while (CONCAT22(extraout_var_00,sVar1) != -1);
            }
          }
          else {
            do {
              if (iVar2 == -1) break;
              sVar1 = FUN_c011c9d0();
              iVar2 = CONCAT22(extraout_var,sVar1);
            } while (iVar2 != 10);
          }
          iVar2 = FUN_c011d378(awStack_238);
        } while (iVar2 != -1);
        CloseHandle(DAT_c0137160);
        if (DAT_c0137158 != (HLOCAL)0x0) {
          LocalFree(DAT_c0137158);
        }
        DAT_c0137160 = CreateFileW(L"\\Windows\\initobj.dat",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0
                                   ,1,0x80,(HANDLE)0x0);
        if (DAT_c0137160 != (HANDLE)0xffffffff) {
          CloseHandle(DAT_c0137160);
        }
      }
      else {
        CloseHandle(DAT_c0137160);
        if (DAT_c0137158 != (HLOCAL)0x0) {
          LocalFree(DAT_c0137158);
        }
      }
    }
  }
  FUN_c013331c(local_30);
  return;
}



/* c011d730 FUN_c011d730 */

/* Boundary evidence: original MIPS .pdata c011d730..c011d7ff. Semantic name remains unreviewed. */

undefined4 FUN_c011d730(void)

{
  DAT_c0137148 = LoadLibraryW(L"CertMod.dll");
  if (DAT_c0137148 != (HMODULE)0x0) {
    DAT_c0137144 = GetProcAddressW(DAT_c0137148,L"CertInit");
    DAT_c0137150 = GetProcAddressW(DAT_c0137148,L"CertVerify");
    if ((DAT_c0137144 != 0) && (DAT_c0137150 != 0)) {
      return 1;
    }
    NKDbgPrintfW(L"!!Invalid OEM Certification Module, Trust Model disabled!!\r\n");
    FreeLibrary(DAT_c0137148);
    DAT_c0137148 = (HMODULE)0x0;
    DAT_c0137144 = 0;
    DAT_c0137150 = 0;
  }
  return 0;
}



/* c011d800 FUN_c011d800 */

/* Boundary evidence: original MIPS .pdata c011d800..c011d8ab. Semantic name remains unreviewed. */

undefined4 FUN_c011d800(void)

{
  int iVar1;
  DWORD DVar2;
  
  if (DAT_c0137150 != 0) {
    iVar1 = (*DAT_c0137144)();
    if (iVar1 != 0) {
      return 1;
    }
    DVar2 = GetLastError();
    NKDbgPrintfW(L"!!Initialized function of OEM Certification Module failed. Trust Model disabled!!. gle=0x%0X\r\n"
                 ,DVar2);
    FreeLibrary(DAT_c0137148);
    DAT_c0137148 = (HMODULE)0x0;
    DAT_c0137144 = (code *)0x0;
    DAT_c0137150 = 0;
  }
  return 0;
}



/* c011d8ac FUN_c011d8ac */

undefined4 FUN_c011d8ac(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_c013714c;
  DAT_c013714c = param_1;
  return uVar1;
}



/* c011d8bc FUN_c011d8bc */

/* Boundary evidence: original MIPS .pdata c011d8bc..c011d9f7. Semantic name remains unreviewed. */

undefined4 FUN_c011d8bc(undefined4 param_1,wchar_t *param_2,undefined4 param_3,uint param_4)

{
  wchar_t *pwVar1;
  DWORD DVar2;
  int iVar3;
  wchar_t *_Str2;
  int iVar4;
  undefined4 local_30 [2];
  
  local_30[0] = 0;
  if (DAT_c0137150 == (code *)0x0) {
LAB_c011d904:
    local_30[0] = 4;
  }
  else {
    if (DAT_c013714c != (int *)0x0) {
      pwVar1 = wcsrchr(param_2,L'\\');
      _Str2 = pwVar1 + 1;
      if (pwVar1 == (wchar_t *)0x0) {
        _Str2 = param_2;
      }
      iVar4 = 0;
      if (*DAT_c013714c != 0) {
        iVar3 = 0;
        do {
          iVar3 = _wcsicmp(*(wchar_t **)(iVar3 + (int)DAT_c013714c),_Str2);
          if (iVar3 == 0) goto LAB_c011d904;
          iVar4 = iVar4 + 1;
          iVar3 = iVar4 * 4;
        } while (DAT_c013714c[iVar4] != 0);
      }
    }
    iVar4 = (*DAT_c0137150)(param_1,param_2,param_3,param_4 >> 1,local_30);
    if (iVar4 == 0) {
      DVar2 = GetLastError();
      NKDbgPrintfW(L"!!CertVerify failed for file %s. gle=0x%0X\r\n",param_2,DVar2);
    }
  }
  return local_30[0];
}



/* c011d9f8 FUN_c011d9f8 */

/* Boundary evidence: original MIPS .pdata c011d9f8..c011da9f. Semantic name remains unreviewed. */

void FUN_c011d9f8(undefined4 *param_1)

{
  if (param_1 != &DAT_c01391e0) {
    DAT_c0136ec8 = DAT_c0136ec8 + 1;
    param_1[0x95] = param_1[0x95] + 1;
    if ((DAT_c0136ecc != 0) && (DAT_c0136ed0 != 0)) {
      SetEventData(DAT_c0136ed0,DAT_c0136ec8);
      if (DAT_c0136c68 == 0) {
        trap(0x1c00);
      }
      if (DAT_c0136ec8 % DAT_c0136c68 == 0) {
        EventModify(DAT_c0136ed0,3);
      }
    }
  }
  return;
}



/* c011daa0 FUN_c011daa0 */

/* Boundary evidence: original MIPS .pdata c011daa0..c011dadf. Semantic name remains unreviewed. */

uint * FUN_c011daa0(undefined4 *param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  
  puVar1 = FUN_c0103dc8(param_1,param_2,param_3,param_4,0);
  if (puVar1 == (uint *)0x0) {
    SetLastError(0x70);
    puVar1 = (uint *)0x0;
  }
  else {
    puVar1 = puVar1 + 3;
  }
  return puVar1;
}



/* c011dae0 FUN_c011dae0 */

/* Boundary evidence: original MIPS .pdata c011dae0..c011db8f. Semantic name remains unreviewed. */

undefined4 FUN_c011dae0(undefined4 *param_1)

{
  uint *puVar1;
  
  FUN_c010297c((int)param_1);
  puVar1 = FUN_c0103dc8(param_1,10,0xc,0,0);
  if (puVar1 == (uint *)0x0) {
    SetLastError(0x70);
  }
  else if (puVar1 + 3 != (uint *)0x0) {
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    *(uint *)(param_1[2] + 0xec) = puVar1[2];
    FUN_c0102aa4(param_1);
    return 1;
  }
  FUN_c0103768(param_1);
  *(undefined4 *)(param_1[2] + 0xec) = 0xffffffff;
  return 0;
}



/* c011db90 FUN_c011db90 */

/* Boundary evidence: original MIPS .pdata c011db90..c011dc57. Semantic name remains unreviewed. */

void FUN_c011db90(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  if (DAT_c0137138 == 0) {
    DAT_c0137138 = CreateAPISet(&DAT_c00f43b8,3,&PTR_FUN_c00f41b8,&DAT_c00f4238);
    DAT_c013713c = CreateAPISet(&DAT_c00f43b0,0x1d,&PTR_FUN_c00f41c4,&DAT_c00f42c8);
    RegisterDirectMethods(DAT_c013713c,&PTR_FUN_c00f4250);
    RegisterAPISet(DAT_c0137138,0x8000000a);
    RegisterAPISet(DAT_c013713c,0x80000009);
  }
  FUN_c0124e1c(&PTR_DAT_c0136850);
  return;
}



/* c011dc58 FUN_c011dc58 */

/* Boundary evidence: original MIPS .pdata c011dc58..c011de57. Semantic name remains unreviewed. */

undefined4 FUN_c011dc58(int param_1,uint param_2,undefined2 *param_3)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = FUN_c0101de8(param_1,param_2);
  if ((iVar1 == 0) || ((*(uint *)(iVar1 + -0xc) & 0xf0000000) != 0x70000000)) {
    iVar1 = 0;
  }
  if (iVar1 == 0) {
    SetLastError(0x57);
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
    *param_3 = 1;
    *(uint *)(param_3 + 2) = (uint)*(ushort *)(iVar1 + 0x50) << 0x10 | 0x17;
    *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(param_3 + 0x26) = *(undefined4 *)(iVar1 + 0x48);
    param_3[1] = *(undefined2 *)(iVar1 + 0x4c);
    *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)(iVar1 + 0x5c);
    *(undefined4 *)(param_3 + 0x2a) = *(undefined4 *)(iVar1 + 0x54);
    *(undefined4 *)(param_3 + 0x2c) = *(undefined4 *)(iVar1 + 0x58);
    if ((*(uint *)(iVar1 + 0x74) & 8) == 0) {
      uVar3 = 0;
      if (*(short *)(iVar1 + 0x4c) != 0) {
        do {
          puVar2 = (ushort *)((uVar3 + 2) * 0x40 + iVar1);
          param_3[uVar3 * 0x10 + 0x2e] = 1;
          param_3[uVar3 * 0x10 + 0x2f] = *puVar2;
          if (*puVar2 != 0) {
            uVar6 = 0;
            do {
              iVar4 = uVar6 + uVar3 * 0x10;
              iVar7 = uVar3 * 8 + uVar6;
              *(undefined4 *)(param_3 + (iVar7 + 0x19) * 2) =
                   *(undefined4 *)((iVar4 + 0x1a) * 4 + iVar1);
              *(undefined4 *)(param_3 + (iVar7 + 0x1c) * 2) =
                   *(undefined4 *)((iVar4 + 0x1d) * 4 + iVar1);
              uVar6 = uVar6 + 1 & 0xffff;
            } while (uVar6 < *puVar2);
          }
          if ((*(uint *)(param_3 + uVar3 * 0x10 + 0x38) & 0x200) == 0) {
            param_3[(uVar3 + 3) * 0x10] = 0;
          }
          else {
            *(uint *)(param_3 + uVar3 * 0x10 + 0x38) =
                 *(uint *)(param_3 + uVar3 * 0x10 + 0x38) & 0xfffffdff;
            param_3[(uVar3 + 3) * 0x10] = 0x200;
          }
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < *(ushort *)(iVar1 + 0x4c));
      }
    }
    else {
      param_3[1] = 0;
    }
    wcscpy(param_3 + 4,(wchar_t *)(iVar1 + 8));
  }
  return uVar5;
}



/* c011de58 FUN_c011de58 */

/* Boundary evidence: original MIPS .pdata c011de58..c011de7b. Semantic name remains unreviewed. */

void FUN_c011de58(int param_1,uint param_2,int param_3)

{
  *(undefined2 *)(param_3 + 2) = 3;
  FUN_c011dc58(param_1,param_2,(undefined2 *)(param_3 + 4));
  return;
}



/* c011de7c FUN_c011de7c */

/* Boundary evidence: original MIPS .pdata c011de7c..c011e04f. Semantic name remains unreviewed. */

undefined4 FUN_c011de7c(int param_1,short *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 local_20;
  
  local_20 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar1 = IsProcessDying();
  if (iVar1 == 0) {
    if ((((param_1 == 0) || (*(int *)(param_1 + 0x10) == 0)) || (*(int *)(param_1 + 0x14) == 0)) ||
       ((param_2 == (short *)0x0 || (*param_2 != 1)))) {
      SetLastError(0x57);
    }
    else {
      EnterCriticalSection(*(LPCRITICAL_SECTION *)(*(int *)(param_1 + 0x10) + 0x21c));
      uVar2 = FUN_c0101ea4(*(int *)(param_1 + 0x10),*(uint *)(param_1 + 0x14));
      *(uint *)(param_2 + 10) = uVar2;
      iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 8);
      *(undefined4 *)(param_2 + 2) = *(undefined4 *)(iVar1 + 0xc);
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar1 + 0x10);
      *(undefined4 *)(param_2 + 6) = *(undefined4 *)(iVar1 + 0x14);
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar1 + 0x18);
      local_20 = FUN_c011dc58(*(int *)(param_1 + 0x10),uVar2,param_2 + 0xc);
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)(*(int *)(param_1 + 0x10) + 0x21c));
    }
  }
  else {
    SetLastError(0x10dc);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return local_20;
}



/* c011e050 FUN_c011e050 */

/* Boundary evidence: original MIPS .pdata c011e050..c011e05b. Semantic name remains unreviewed. */

undefined4 FUN_c011e050(void)

{
  return 1;
}



/* c011e05c FUN_c011e05c */

/* Boundary evidence: original MIPS .pdata c011e05c..c011e067. Semantic name remains unreviewed. */

undefined4 FUN_c011e05c(void)

{
  return 1;
}



/* c011e068 FUN_c011e068 */

/* Boundary evidence: original MIPS .pdata c011e068..c011e073. Semantic name remains unreviewed. */

undefined4 FUN_c011e068(void)

{
  return 1;
}



/* c011e074 FUN_c011e074 */

/* Boundary evidence: original MIPS .pdata c011e074..c011e46b. Semantic name remains unreviewed. */

void FUN_c011e074(int *param_1,LCID param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  ushort *puVar7;
  
  BVar1 = IsValidLocale(param_2,2);
  if (BVar1 == 0) {
    SetLastError(0x57);
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
    iVar2 = IsProcessDying();
    if (iVar2 == 0) {
      if ((param_1 == (int *)0x0) || (puVar3 = FUN_c0124094(param_1,2), puVar3 == (undefined4 *)0x0)
         ) {
        SetLastError(0x57);
        puVar3 = (undefined4 *)0x0;
      }
      if (puVar3 != (undefined4 *)0x0) {
        EnterCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
        if (((*(uint *)(puVar3[2] + 0xec) == 0xffffffff) ||
            (puVar4 = (uint *)FUN_c0101c94((int)puVar3,*(uint *)(puVar3[2] + 0xec)),
            puVar4 == (uint *)0x0)) || ((puVar4[-3] & 0xf0000000) != 0xa0000000)) {
          puVar4 = (uint *)0x0;
        }
        if (puVar4 != (uint *)0x0) {
          if ((*(ushort *)((int)puVar3 + 0x24e) & 0x20) == 0) {
            if (param_2 != *(uint *)(puVar3[2] + 0xf8) >> 8) {
              FUN_c010297c((int)puVar3);
              uVar6 = *puVar4;
              puVar5 = (uint *)FUN_c0101c94((int)puVar3,uVar6);
              if ((puVar5 == (uint *)0x0) || ((puVar5[-3] & 0xf0000000) != 0x70000000)) {
                puVar5 = (uint *)0x0;
              }
              while ((uVar6 != 0 && (puVar5 != (uint *)0x0))) {
                puVar7 = (ushort *)((int)puVar5 + 0x4e);
                FUN_c01029e4((int)puVar3,1,puVar7,(uint)*puVar7,2);
                *puVar7 = *puVar7 | 0xff00;
                uVar6 = *puVar5;
                puVar5 = (uint *)FUN_c0101c94((int)puVar3,uVar6);
                if ((puVar5 == (uint *)0x0) || ((puVar5[-3] & 0xf0000000) != 0x70000000)) {
                  puVar5 = (uint *)0x0;
                }
              }
              FUN_c0102aa4(puVar3);
              *(uint *)(puVar3[2] + 0xf8) = *(uint *)(puVar3[2] + 0xf8) & 0xff | param_2 << 8;
              uVar6 = *puVar4;
              puVar4 = (uint *)FUN_c0101c94((int)puVar3,uVar6);
              if ((puVar4 == (uint *)0x0) || ((puVar4[-3] & 0xf0000000) != 0x70000000)) {
                puVar4 = (uint *)0x0;
              }
              while ((uVar6 != 0 && (puVar4 != (uint *)0x0))) {
                if ((*(ushort *)((int)puVar4 + 0x4e) & 0xff00) != 0) {
                  FUN_c012d470(puVar3,(int)puVar4);
                }
                uVar6 = *puVar4;
                puVar4 = (uint *)FUN_c0101c94((int)puVar3,uVar6);
                if ((puVar4 == (uint *)0x0) || ((puVar4[-3] & 0xf0000000) != 0x70000000)) {
                  puVar4 = (uint *)0x0;
                }
              }
            }
          }
          else {
            SetLastError(5);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
      }
    }
    else {
      SetLastError(0x10dc);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  }
  return;
}



/* c011e46c FUN_c011e46c */

/* Boundary evidence: original MIPS .pdata c011e46c..c011e477. Semantic name remains unreviewed. */

undefined4 FUN_c011e46c(void)

{
  return 1;
}



/* c011e478 FUN_c011e478 */

/* Boundary evidence: original MIPS .pdata c011e478..c011e483. Semantic name remains unreviewed. */

undefined4 FUN_c011e478(void)

{
  return 1;
}



/* c011e484 FUN_c011e484 */

/* Boundary evidence: original MIPS .pdata c011e484..c011e48f. Semantic name remains unreviewed. */

undefined4 FUN_c011e484(void)

{
  return 1;
}



/* c011e490 FUN_c011e490 */

undefined4 FUN_c011e490(short *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if ((((param_1 == (short *)0x0) || (uVar1 = 1, *param_1 != 1)) ||
      (uVar2 = (uint)(ushort)param_1[1], uVar2 == 0)) || (3 < uVar2)) {
LAB_c011e530:
    uVar1 = 0;
  }
  else {
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        uVar3 = *(uint *)(param_1 + (uVar4 + 2) * 2) & 0xffff;
        if (uVar3 < 0x14) {
          if ((uVar3 < 0x12) && ((uVar3 < 2 || (((3 < uVar3 && (uVar3 != 5)) && (uVar3 != 0xb))))))
          goto LAB_c011e530;
        }
        else if ((uVar3 != 0x1f) && (uVar3 != 0x40)) goto LAB_c011e530;
        uVar5 = uVar4 + 1 & 0xffff;
        for (uVar3 = uVar5; uVar3 < uVar2; uVar3 = uVar3 + 1 & 0xffff) {
          if (*(uint *)(param_1 + (uVar4 + 2) * 2) == *(uint *)(param_1 + (uVar3 + 2) * 2))
          goto LAB_c011e530;
        }
        uVar2 = *(uint *)(param_1 + (uVar4 + 5) * 2);
        if ((uVar2 & 0x200) != 0) goto LAB_c011e530;
        *(uint *)(param_1 + (uVar4 + 5) * 2) = uVar2 & 0xfffffff7;
        uVar2 = (uint)(ushort)param_1[1];
        uVar4 = uVar5;
      } while (uVar5 < uVar2);
    }
  }
  return uVar1;
}



/* c011e5e8 FUN_c011e5e8 */

/* Boundary evidence: original MIPS .pdata c011e5e8..c011e793. Semantic name remains unreviewed. */

undefined4 FUN_c011e5e8(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (*(ushort *)(param_1 + 2) < 5) {
    uVar9 = 0;
    if (*(ushort *)(param_1 + 2) != 0) {
      do {
        iVar2 = FUN_c011e490((short *)(uVar9 * 0x20 + param_1 + 0x5c));
        if (iVar2 == 0) goto LAB_c011e76c;
        uVar9 = uVar9 + 1 & 0xffff;
      } while (uVar9 < *(ushort *)(param_1 + 2));
    }
    uVar6 = (uint)*(ushort *)(param_1 + 2);
    uVar9 = 0;
    uVar3 = 1;
    if (uVar6 != 0) {
      do {
        uVar4 = uVar9 + 1 & 0xffff;
        if (uVar4 < uVar6) {
          uVar10 = (uint)*(ushort *)(uVar9 * 0x20 + param_1 + 0x5e);
          uVar8 = uVar4;
          do {
            uVar7 = (uint)*(ushort *)(uVar8 * 0x20 + param_1 + 0x5e);
            if (uVar10 < uVar7) {
              uVar7 = uVar10;
            }
            bVar1 = true;
            uVar5 = 0;
            if (uVar7 == 0) goto LAB_c011e76c;
            do {
              if (!bVar1) goto LAB_c011e738;
              if (*(int *)((uVar9 * 8 + uVar5 + 0x19) * 4 + param_1) !=
                  *(int *)((uVar8 * 8 + uVar5 + 0x19) * 4 + param_1)) {
                bVar1 = false;
              }
              uVar5 = uVar5 + 1 & 0xffff;
            } while (uVar5 < uVar7);
            if (bVar1) goto LAB_c011e76c;
LAB_c011e738:
            uVar8 = uVar8 + 1 & 0xffff;
          } while (uVar8 < uVar6);
        }
        uVar9 = uVar4;
      } while (uVar4 < uVar6);
    }
  }
  else {
LAB_c011e76c:
    uVar3 = 0;
  }
  return uVar3;
}



/* c011e794 FUN_c011e794 */

/* Boundary evidence: original MIPS .pdata c011e794..c011e8e3. Semantic name remains unreviewed. */

uint FUN_c011e794(int param_1,PCNZWCH param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(*(int *)(param_1 + 8) + 0xec);
  if (((uVar4 == 0xffffffff) ||
      (puVar2 = (uint *)FUN_c0101c94(param_1,uVar4), puVar2 == (uint *)0x0)) ||
     ((puVar2[-3] & 0xf0000000) != 0xa0000000)) {
    puVar2 = (uint *)0x0;
  }
  uVar4 = 0;
  if (puVar2 != (uint *)0x0) {
    uVar4 = *puVar2;
  }
  uVar1 = 0;
  while (uVar4 != 0) {
    puVar2 = (uint *)FUN_c0101c94(param_1,uVar4);
    if ((puVar2 == (uint *)0x0) || ((puVar2[-3] & 0xf0000000) != 0x70000000)) {
      puVar2 = (uint *)0x0;
    }
    if ((puVar2 == (uint *)0x0) ||
       (iVar3 = CompareStringW(0x800,1,param_2,-1,(PCNZWCH)(puVar2 + 2),-1), iVar3 == 2)) break;
    uVar1 = uVar4;
    uVar4 = *puVar2;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar1;
  }
  return uVar4;
}



/* c011e8e4 FUN_c011e8e4 */

/* Boundary evidence: original MIPS .pdata c011e8e4..c011ea6b. Semantic name remains unreviewed. */

undefined4 FUN_c011e8e4(undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_c012d56c((int)param_1,(int)param_2);
  FUN_c010297c((int)param_1);
  uVar4 = param_2[-1];
  if (((*(uint *)(param_1[2] + 0xec) == 0xffffffff) ||
      (puVar1 = (uint *)FUN_c0101c94((int)param_1,*(uint *)(param_1[2] + 0xec)),
      puVar1 == (uint *)0x0)) || ((puVar1[-3] & 0xf0000000) != 0xa0000000)) {
    puVar1 = (uint *)0x0;
  }
  if (puVar1 == (uint *)0x0) goto LAB_c011ea2c;
  uVar3 = *puVar1;
  if (uVar4 == uVar3) {
    FUN_c01029e4((int)param_1,1,puVar1,uVar3,4);
  }
  else {
    if (uVar3 == 0) goto LAB_c011ea2c;
    do {
      puVar1 = (uint *)FUN_c0101c94((int)param_1,uVar3);
      if ((puVar1 == (uint *)0x0) || ((puVar1[-3] & 0xf0000000) != 0x70000000)) {
        puVar1 = (uint *)0x0;
      }
    } while (((puVar1 != (uint *)0x0) && (uVar2 = *puVar1, uVar2 != uVar4)) &&
            (uVar3 = uVar2, uVar2 != 0));
    if ((uVar3 == 0) || (puVar1 == (uint *)0x0)) goto LAB_c011ea2c;
    FUN_c01029e4((int)param_1,1,puVar1,*puVar1,4);
  }
  *puVar1 = *param_2;
LAB_c011ea2c:
  FUN_c01037f0(param_1,uVar4);
  FUN_c0102aa4(param_1);
  return 1;
}



/* c011ea6c FUN_c011ea6c */

/* Boundary evidence: original MIPS .pdata c011ea6c..c011ef13. Semantic name remains unreviewed. */

undefined4 FUN_c011ea6c(undefined4 *param_1,uint *param_2,uint *param_3)

{
  short sVar1;
  uint *puVar2;
  bool bVar3;
  uint *puVar4;
  DWORD DVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint *_Dst;
  uint uVar12;
  
  FUN_c010297c((int)param_1);
  puVar4 = FUN_c0103dc8(param_1,7,0x164,2,0);
  if (puVar4 == (uint *)0x0) {
    SetLastError(0x70);
  }
  else {
    _Dst = puVar4 + 3;
    if (_Dst != (uint *)0x0) {
      memset(_Dst,0,0x164);
      *_Dst = *param_2;
      if ((param_3[1] & 2) == 0) {
        puVar4[4] = param_2[1];
      }
      else {
        puVar4[4] = param_3[0x12];
      }
      if ((param_3[1] & 0x10) == 0) {
        uVar6 = (undefined2)param_2[0x14];
      }
      else {
        uVar6 = (undefined2)(param_3[1] >> 0x10);
      }
      *(undefined2 *)(puVar4 + 0x17) = uVar6;
      puVar2 = param_3;
      if ((param_3[1] & 1) == 0) {
        puVar2 = param_2;
      }
      wcsncpy((wchar_t *)(puVar4 + 5),(wchar_t *)(puVar2 + 2),0x1f);
      *(undefined2 *)((int)puVar4 + 0x52) = 0;
      if ((param_3[1] & 8) == 0) {
        puVar4[0x18] = param_2[0x15];
        puVar4[0x19] = param_2[0x16];
      }
      else {
        puVar4[0x18] = param_3[0x15];
        puVar4[0x19] = param_3[0x16];
      }
      if ((param_3[1] & 4) == 0) {
        *(short *)(puVar4 + 0x16) = (short)param_2[0x13];
        puVar4[0x15] = param_2[0x12];
        puVar4[0x1a] = param_2[0x17];
        memcpy(puVar4 + 0x1c,param_2 + 0x19,0x100);
      }
      else {
        sVar1 = *(short *)((int)param_3 + 2);
        *(short *)(puVar4 + 0x16) = sVar1;
        if (sVar1 == 0) {
          puVar4[0x20] = 8;
          puVar4[0x1d] = 0;
          *(undefined2 *)(puVar4 + 0x23) = 1;
          *(undefined2 *)(puVar4 + 0x16) = 1;
        }
        else {
          uVar10 = 0;
          if (sVar1 != 0) {
            do {
              *(undefined2 *)(_Dst + (uVar10 + 2) * 0x10) =
                   *(undefined2 *)((int)param_3 + uVar10 * 0x20 + 0x5e);
              uVar12 = 0;
              if (*(short *)((int)param_3 + uVar10 * 0x20 + 0x5e) != 0) {
                do {
                  iVar11 = uVar12 + uVar10 * 8;
                  iVar8 = uVar10 * 0x10 + uVar12;
                  _Dst[iVar8 + 0x1a] = param_3[iVar11 + 0x19];
                  _Dst[iVar8 + 0x1d] = param_3[iVar11 + 0x1c];
                  uVar12 = uVar12 + 1 & 0xffff;
                } while (uVar12 < *(ushort *)((int)param_3 + uVar10 * 0x20 + 0x5e));
              }
              if ((param_3[(uVar10 + 3) * 8] & 0x200) != 0) {
                _Dst[uVar10 * 0x10 + 0x1d] = _Dst[uVar10 * 0x10 + 0x1d] | 0x200;
              }
              uVar10 = uVar10 + 1 & 0xffff;
            } while (uVar10 < *(ushort *)((int)param_3 + 2));
          }
        }
        uVar10 = 0;
        while( true ) {
          uVar7 = (uint)(ushort)puVar4[0x16];
          uVar9 = (uint)(ushort)param_2[0x13];
          uVar12 = uVar7;
          if (uVar7 <= uVar9) {
            uVar12 = uVar9;
          }
          if (uVar12 <= uVar10) break;
          bVar3 = true;
          if ((uVar10 < uVar9) && (uVar10 < uVar7)) {
            uVar12 = 0;
            if ((ushort)_Dst[(uVar10 + 2) * 0x10] != 0) {
              do {
                if (!bVar3) goto LAB_c011ee00;
                iVar11 = uVar10 * 0x10 + uVar12;
                iVar8 = iVar11 + 0x1a;
                if ((param_2[iVar8] != _Dst[iVar8]) ||
                   (iVar11 = iVar11 + 0x1d, param_2[iVar11] != _Dst[iVar11])) {
                  bVar3 = false;
                }
                uVar12 = uVar12 + 1 & 0xffff;
              } while (uVar12 < (ushort)_Dst[(uVar10 + 2) * 0x10]);
              goto LAB_c011edd4;
            }
LAB_c011eddc:
            memcpy(_Dst + uVar10 * 0x10 + 0x19,param_2 + uVar10 * 0x10 + 0x19,0x40);
          }
          else {
            bVar3 = false;
LAB_c011edd4:
            if (bVar3) goto LAB_c011eddc;
LAB_c011ee00:
            *(ushort *)((int)puVar4 + 0x5a) =
                 (ushort)(1 << (uVar10 + 8 & 0x1f)) | *(ushort *)((int)puVar4 + 0x5a);
          }
          uVar10 = uVar10 + 1 & 0xffff;
        }
        puVar4[0x15] = param_2[0x12];
        puVar4[0x1a] = *puVar4 & 0xffffffc;
      }
      FUN_c0102f60((int)param_1,puVar4[2],param_2[-1]);
      if ((((*(ushort *)((int)puVar4 + 0x5a) & 0xff00) == 0) ||
          (iVar11 = FUN_c012d470(param_1,(int)_Dst), iVar11 != 0)) ||
         ((DVar5 = GetLastError(), DVar5 != 5 && (DVar5 = GetLastError(), DVar5 != 0xb7)))) {
        FUN_c01037f0(param_1,param_2[-1]);
        FUN_c0102aa4(param_1);
        return 1;
      }
      FUN_c010297c((int)param_1);
      *(ushort *)((int)param_2 + 0x4e) = *(ushort *)((int)param_2 + 0x4e) | 0xff00;
      FUN_c0102aa4(param_1);
    }
  }
  FUN_c01036ac(param_1);
  return 0;
}



/* c011ef14 FUN_c011ef14 */

/* Boundary evidence: original MIPS .pdata c011ef14..c011f173. Semantic name remains unreviewed. */

undefined4 FUN_c011ef14(uint *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *hMem;
  undefined4 *puVar2;
  DWORD dwErrCode;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar1 = IsProcessDying();
  if (iVar1 != 0) {
    SetLastError(0x10dc);
    goto LAB_c011f128;
  }
  hMem = LocalAlloc(0,0x24);
  if (hMem == (undefined4 *)0x0) {
LAB_c011f0c0:
    dwErrCode = 0xe;
  }
  else {
    if ((param_1 == (uint *)0x0) ||
       ((param_1[3] & param_1[2] & param_1[1] & *param_1) == 0xffffffff)) {
      hMem[7] = 1;
      memset(hMem + 2,0,0x10);
LAB_c011f094:
      hMem[8] = param_2;
      hMem[6] = 0;
      iVar1 = CreateAPIHandle(DAT_c0137138,hMem);
      hMem[1] = iVar1;
      if (iVar1 != 0) {
        *hMem = DAT_c0137140;
        uVar3 = hMem[1];
        DAT_c0137140 = hMem;
        goto LAB_c011f128;
      }
      goto LAB_c011f0c0;
    }
    puVar2 = FUN_c0124094((int *)param_1,2);
    if (puVar2 == (undefined4 *)0x0) {
      SetLastError(0x57);
      puVar2 = (undefined4 *)0x0;
    }
    if (puVar2 != (undefined4 *)0x0) {
      hMem[2] = *param_1;
      hMem[3] = param_1[1];
      hMem[4] = param_1[2];
      hMem[5] = param_1[3];
      hMem[7] = 0;
      goto LAB_c011f094;
    }
    dwErrCode = 0x57;
  }
  SetLastError(dwErrCode);
  if (hMem != (undefined4 *)0x0) {
    LocalFree(hMem);
  }
LAB_c011f128:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return uVar3;
}



/* c011f174 FUN_c011f174 */

/* Boundary evidence: original MIPS .pdata c011f174..c011f17f. Semantic name remains unreviewed. */

undefined4 FUN_c011f174(void)

{
  return 1;
}



/* c011f180 FUN_c011f180 */

/* Boundary evidence: original MIPS .pdata c011f180..c011f62b. Semantic name remains unreviewed. */

uint FUN_c011f180(int param_1,void *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  DWORD dwErrCode;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar2 = IsProcessDying();
  if (iVar2 == 0) {
    uVar6 = 0;
    if (((int *)(param_1 + 8) == (int *)0x0) ||
       (puVar3 = FUN_c0124094((int *)(param_1 + 8),2), puVar3 == (undefined4 *)0x0)) {
      SetLastError(0x57);
      puVar3 = (undefined4 *)0x0;
    }
    if (puVar3 == (undefined4 *)0x0) {
      dwErrCode = 0x3fa;
    }
    else {
      bVar1 = false;
      do {
        EnterCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
        if (*(uint *)(param_1 + 0x18) == 0) {
          if (((*(uint *)(puVar3[2] + 0xec) == 0xffffffff) ||
              (puVar4 = (uint *)FUN_c0101c94((int)puVar3,*(uint *)(puVar3[2] + 0xec)),
              puVar4 == (uint *)0x0)) || ((puVar4[-3] & 0xf0000000) != 0xa0000000)) {
            puVar4 = (uint *)0x0;
          }
          if (puVar4 != (uint *)0x0) {
LAB_c011f35c:
            uVar6 = *puVar4;
          }
          while (uVar6 != 0) {
            puVar4 = (uint *)FUN_c0101c94((int)puVar3,uVar6);
            if ((puVar4 == (uint *)0x0) || ((puVar4[-3] & 0xf0000000) != 0x70000000)) {
              puVar4 = (uint *)0x0;
            }
            if (puVar4 == (uint *)0x0) goto LAB_c011f3a8;
            if ((*(uint *)(param_1 + 0x20) == 0) || (*(uint *)(param_1 + 0x20) == puVar4[1])) {
              uVar5 = FUN_c0101ea4((int)puVar3,uVar6);
              if (param_2 != (void *)0x0) {
                if (puVar3 == (undefined4 *)0x0) {
                  iVar2 = -1;
                }
                else {
                  if ((puVar3 != &DAT_c01391e0) && (puVar3 != (undefined4 *)PTR_DAT_c0136c70)) {
                    memcpy(param_2,(void *)(puVar3[2] + 0xc),0x10);
                    goto LAB_c011f464;
                  }
                  iVar2 = 0;
                }
                memset(param_2,iVar2,0x10);
              }
LAB_c011f464:
              *(uint *)(param_1 + 0x18) = uVar5;
              break;
            }
            uVar6 = *puVar4;
          }
          bVar1 = true;
        }
        else {
          puVar4 = (uint *)FUN_c0101de8((int)puVar3,*(uint *)(param_1 + 0x18));
          if ((puVar4 == (uint *)0x0) || ((puVar4[-3] & 0xf0000000) != 0x70000000)) {
            puVar4 = (uint *)0x0;
          }
          if (puVar4 != (uint *)0x0) goto LAB_c011f35c;
          SetLastError(0x57);
LAB_c011f3a8:
          SetLastError(0x3fa);
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
        if (!bVar1) goto LAB_c011f5d8;
        if ((uVar5 != 0) || (*(int *)(param_1 + 0x1c) == 0)) break;
        puVar3 = (undefined4 *)FUN_c01241b8(puVar3,2);
        if (puVar3 == (undefined4 *)0x0) {
          iVar2 = -1;
LAB_c011f55c:
          memset((void *)(param_1 + 8),iVar2,0x10);
        }
        else {
          if ((puVar3 == &DAT_c01391e0) || (puVar3 == (undefined4 *)PTR_DAT_c0136c70)) {
            iVar2 = 0;
            goto LAB_c011f55c;
          }
          memcpy((void *)(param_1 + 8),(void *)(puVar3[2] + 0xc),0x10);
        }
        *(undefined4 *)(param_1 + 0x18) = 0;
      } while (puVar3 != (undefined4 *)0x0);
      if ((!bVar1) || (uVar5 != 0)) goto LAB_c011f5d8;
      dwErrCode = 0x103;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(0x10dc);
  }
LAB_c011f5d8:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return uVar5;
}



/* c011f62c FUN_c011f62c */

/* Boundary evidence: original MIPS .pdata c011f62c..c011f637. Semantic name remains unreviewed. */

undefined4 FUN_c011f62c(void)

{
  return 1;
}



/* c011f638 FUN_c011f638 */

/* Boundary evidence: original MIPS .pdata c011f638..c011f643. Semantic name remains unreviewed. */

undefined4 FUN_c011f638(void)

{
  return 1;
}



/* c011f644 FUN_c011f644 */

/* Boundary evidence: original MIPS .pdata c011f644..c011f64f. Semantic name remains unreviewed. */

undefined4 FUN_c011f644(void)

{
  return 1;
}



/* c011f650 FUN_c011f650 */

/* Boundary evidence: original MIPS .pdata c011f650..c011f737. Semantic name remains unreviewed. */

undefined4 FUN_c011f650(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  piVar1 = DAT_c0137140;
  if (DAT_c0137140 == param_1) {
    DAT_c0137140 = (int *)*param_1;
  }
  else {
    do {
      piVar2 = piVar1;
      piVar1 = (int *)*piVar2;
    } while (piVar1 != param_1);
    *piVar2 = *param_1;
  }
  LocalFree(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return 1;
}



/* c011f738 FUN_c011f738 */

/* Boundary evidence: original MIPS .pdata c011f738..c011f743. Semantic name remains unreviewed. */

undefined4 FUN_c011f738(void)

{
  return 1;
}



/* c011f744 FUN_c011f744 */

/* Boundary evidence: original MIPS .pdata c011f744..c011fed7. Semantic name remains unreviewed. */

undefined4
FUN_c011f744(uint *param_1,uint *param_2,PCNZWCH param_3,short *param_4,undefined4 param_5,
            int param_6,int param_7)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *hMem;
  undefined4 local_50;
  uint auStack_48 [4];
  int aiStack_38 [4];
  
  local_50 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar2 = IsProcessDying();
  if (iVar2 != 0) {
    SetLastError(0x10dc);
    goto LAB_c011fe84;
  }
  uVar10 = 0;
  if ((param_1[3] & param_1[2] & param_1[1] & *param_1) == 0xffffffff) {
    memset(aiStack_38,0,0x10);
    *param_2 = 0;
    puVar3 = FUN_c0124094(aiStack_38,2);
    if (puVar3 == (undefined4 *)0x0) {
      SetLastError(0x57);
      puVar3 = (undefined4 *)0x0;
    }
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)FUN_c01241b8(puVar3,2)) {
      EnterCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
      uVar10 = FUN_c011e794((int)puVar3,param_3,(uint *)0x0);
      LeaveCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
      if (uVar10 != 0) break;
    }
  }
  else {
    puVar3 = FUN_c0124094((int *)param_1,2);
    if ((puVar3 == (undefined4 *)0x0) ||
       ((*param_2 != 0 &&
        (((uVar8 = *param_2 >> 0x1c, uVar8 == 0 && (puVar3 != &DAT_c01391e0)) ||
         ((uVar8 == 3 && (puVar3 == &DAT_c01391e0)))))))) {
      SetLastError(0x57);
      puVar3 = (undefined4 *)0x0;
    }
    if (puVar3 == (undefined4 *)0x0) goto LAB_c011fe84;
    if (*param_2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
      uVar10 = FUN_c011e794((int)puVar3,param_3,(uint *)0x0);
      LeaveCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
    }
  }
  if ((*param_2 == 0) && (uVar10 == 0)) {
    SetLastError(2);
    goto LAB_c011fe84;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
  hMem = (undefined4 *)0x0;
  if (*param_2 == 0) {
    uVar8 = FUN_c0101c94((int)puVar3,uVar10);
    if ((uVar8 == 0) || ((*(uint *)(uVar8 - 0xc) & 0xf0000000) != 0x70000000)) {
      uVar8 = 0;
    }
    uVar10 = FUN_c0101ea4((int)puVar3,uVar10);
    *param_2 = uVar10;
  }
  else {
    uVar8 = FUN_c0101de8((int)puVar3,*param_2);
    if ((uVar8 == 0) || ((*(uint *)(uVar8 - 0xc) & 0xf0000000) != 0x70000000)) {
      uVar8 = 0;
    }
  }
  if (uVar8 == 0) {
    uVar5 = 0x57;
    pcVar7 = SetLastError_exref;
LAB_c011fdd8:
    (*pcVar7)(uVar5);
LAB_c011fde0:
    if (hMem != (undefined4 *)0x0) {
      LocalFree(hMem);
    }
  }
  else {
    hMem = LocalAlloc(0,0x3c);
    if (hMem == (undefined4 *)0x0) {
LAB_c011fb60:
      uVar5 = 0xe;
      pcVar7 = SetLastError_exref;
      goto LAB_c011fdd8;
    }
    hMem[4] = puVar3;
    hMem[3] = param_5;
    if (param_6 == 0) {
      hMem[10] = 0;
    }
    else {
      hMem[10] = *(undefined4 *)(param_6 + 4);
      hMem[0xb] = *(undefined4 *)(param_6 + 0xc);
      hMem[0xc] = *(undefined4 *)(param_6 + 8);
      hMem[0xd] = *(undefined4 *)(param_6 + 0x10);
    }
    hMem[5] = *(undefined4 *)(uVar8 - 4);
    hMem[0xe] = 0;
    hMem[2] = param_7;
    *(undefined2 *)(hMem + 9) = 0;
    if ((param_4 != (short *)0x0) && (*(int *)(param_4 + 4) != 0)) {
      if (*param_4 == 1) {
        while( true ) {
          uVar10 = (uint)*(ushort *)(hMem + 9);
          if (*(ushort *)(uVar8 + 0x4c) <= uVar10) break;
          if ((uint)(ushort)param_4[1] <= (uint)*(ushort *)((uVar10 + 2) * 0x40 + uVar8)) {
            bVar1 = true;
            for (uVar9 = 0; uVar9 < (ushort)param_4[1]; uVar9 = uVar9 + 1 & 0xffff) {
              if (!bVar1) goto LAB_c011fcb0;
              if (*(int *)((uVar10 * 0x10 + uVar9 + 0x1a) * 4 + uVar8) !=
                  *(int *)(param_4 + (uVar9 + 2) * 2)) {
                bVar1 = false;
              }
            }
            if (bVar1) break;
          }
LAB_c011fcb0:
          *(ushort *)(hMem + 9) = *(ushort *)(hMem + 9) + 1;
        }
        if (*(short *)(hMem + 9) != *(short *)(uVar8 + 0x4c)) goto LAB_c011fcdc;
      }
      SetLastError(0x57);
      goto LAB_c011fde0;
    }
LAB_c011fcdc:
    if (((1 << (*(ushort *)(hMem + 9) + 8 & 0x1f) & (uint)*(ushort *)(uVar8 + 0x4e)) != 0) &&
       (iVar2 = FUN_c012d470(puVar3,uVar8), iVar2 == 0)) {
      uVar5 = 0x70;
      pcVar7 = SetLastError_exref;
      goto LAB_c011fdd8;
    }
    puVar4 = FUN_c012d5d8(auStack_48,(int)puVar3,uVar8,
                          (uint)*(ushort *)(hMem + 9) * 0x40 + uVar8 + 100,2,0,hMem + 6,(void *)0x0)
    ;
    hMem[6] = *puVar4;
    hMem[7] = puVar4[1];
    hMem[8] = puVar4[2];
    iVar2 = CreateAPIHandle(DAT_c013713c,hMem);
    hMem[1] = iVar2;
    if (iVar2 == 0) goto LAB_c011fb60;
    puVar6 = (undefined4 *)hMem[4];
    if (((puVar6 != (undefined4 *)0x0) && (puVar6 != (undefined4 *)PTR_DAT_c0136c70)) &&
       (iVar2 = FUN_c01234d4(puVar6,param_7,1), iVar2 == 0)) {
      uVar5 = hMem[1];
      pcVar7 = CloseHandle_exref;
      goto LAB_c011fdd8;
    }
    local_50 = hMem[1];
    *hMem = DAT_c0137134;
    DAT_c0137134 = hMem;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
LAB_c011fe84:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return local_50;
}



/* c011fed8 FUN_c011fed8 */

/* Boundary evidence: original MIPS .pdata c011fed8..c011fee3. Semantic name remains unreviewed. */

undefined4 FUN_c011fed8(void)

{
  return 1;
}



/* c011fee4 FUN_c011fee4 */

/* Boundary evidence: original MIPS .pdata c011fee4..c011feef. Semantic name remains unreviewed. */

undefined4 FUN_c011fee4(void)

{
  return 1;
}



/* c011fef0 FUN_c011fef0 */

/* Boundary evidence: original MIPS .pdata c011fef0..c011fefb. Semantic name remains unreviewed. */

undefined4 FUN_c011fef0(void)

{
  return 1;
}



/* c011fefc FUN_c011fefc */

/* Boundary evidence: original MIPS .pdata c011fefc..c011ff07. Semantic name remains unreviewed. */

undefined4 FUN_c011fefc(void)

{
  return 1;
}



/* c011ff08 FUN_c011ff08 */

/* Boundary evidence: original MIPS .pdata c011ff08..c011ff13. Semantic name remains unreviewed. */

undefined4 FUN_c011ff08(void)

{
  return 1;
}



/* c011ff14 FUN_c011ff14 */

/* Boundary evidence: original MIPS .pdata c011ff14..c011ff1f. Semantic name remains unreviewed. */

undefined4 FUN_c011ff14(void)

{
  return 1;
}



/* c011ff20 FUN_c011ff20 */

/* Boundary evidence: original MIPS .pdata c011ff20..c011ff2b. Semantic name remains unreviewed. */

undefined4 FUN_c011ff20(void)

{
  return 1;
}



/* c011ff2c FUN_c011ff2c */

void FUN_c011ff2c(int param_1)

{
  int *piVar1;
  
  for (piVar1 = (int *)DAT_c0137134; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    if (piVar1[4] == param_1) {
      piVar1[4] = 0;
    }
  }
  return;
}



/* c011ff60 FUN_c011ff60 */

/* Boundary evidence: original MIPS .pdata c011ff60..c012008f. Semantic name remains unreviewed. */

undefined4 FUN_c011ff60(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  piVar2 = (int *)param_1[4];
  if (((piVar2 == (int *)0x0) || (piVar2 == (int *)PTR_DAT_c0136c70)) ||
     (iVar1 = FUN_c0124cd4(piVar2,param_1[2],1,-0x3fec97b0), iVar1 != 0)) {
    piVar2 = DAT_c0137134;
    if (DAT_c0137134 == param_1) {
      DAT_c0137134 = (int *)*param_1;
    }
    else {
      do {
        piVar3 = piVar2;
        piVar2 = (int *)*piVar3;
      } while (piVar2 != param_1);
      *piVar3 = *param_1;
    }
    LocalFree(param_1);
    uVar4 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return uVar4;
}



/* c0120090 FUN_c0120090 */

/* Boundary evidence: original MIPS .pdata c0120090..c012009b. Semantic name remains unreviewed. */

undefined4 FUN_c0120090(void)

{
  return 1;
}



/* c012009c FUN_c012009c */

/* Boundary evidence: original MIPS .pdata c012009c..c0120683. Semantic name remains unreviewed. */

uint FUN_c012009c(int param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  size_t sVar5;
  uint uVar6;
  DWORD dwErrCode;
  uint uVar7;
  undefined4 *puVar8;
  uint local_80;
  uint local_68;
  uint local_64;
  uint local_60;
  uint auStack_58 [4];
  uint auStack_48 [4];
  uint auStack_38 [4];
  
  local_80 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar1 = IsProcessDying();
  if (iVar1 != 0) {
    SetLastError(0x10dc);
    goto LAB_c0120624;
  }
  puVar8 = *(undefined4 **)(param_1 + 0x10);
  if (puVar8 == (undefined4 *)0x0) goto LAB_c0120624;
  EnterCriticalSection((LPCRITICAL_SECTION)puVar8[0x87]);
  uVar2 = FUN_c0101c94((int)puVar8,*(uint *)(param_1 + 0x14));
  if ((uVar2 == 0) || ((*(uint *)(uVar2 - 0xc) & 0xf0000000) != 0x70000000)) {
    uVar2 = 0;
  }
  if (uVar2 == 0) goto LAB_c012058c;
  if (((1 << (*(ushort *)(param_1 + 0x24) + 8 & 0x1f) & (uint)*(ushort *)(uVar2 + 0x4e)) == 0) ||
     (iVar1 = FUN_c012d470(puVar8,uVar2), iVar1 != 0)) {
    if (param_2 < 0x11) {
      if (param_2 == 0x10) goto LAB_c01203a0;
      if (param_2 == 1) {
        piVar4 = (int *)FUN_c0101de8((int)puVar8,param_3);
        if ((piVar4 == (int *)0x0) || ((piVar4[-3] & 0xf0000000U) != 0x80000000)) {
          piVar4 = (int *)0x0;
        }
        if ((piVar4 == (int *)0x0) || (*piVar4 != *(int *)(param_1 + 0x14))) goto LAB_c012058c;
        local_64 = param_3 & 0xffffff;
        local_68 = 0xffffffff;
        if (param_5 != (uint *)0x0) {
          puVar3 = FUN_c012d5d8(auStack_48,(int)puVar8,uVar2,
                                (uint)*(ushort *)(param_1 + 0x24) * 0x40 + uVar2 + 100,8,0,&local_68
                                ,(void *)0x0);
          goto LAB_c01204ec;
        }
        goto LAB_c0120504;
      }
      if ((param_2 == 2) || (param_2 == 4)) {
LAB_c0120268:
        puVar3 = FUN_c012d5d8(auStack_58,(int)puVar8,uVar2,
                              (uint)*(ushort *)(param_1 + 0x24) * 0x40 + uVar2 + 100,param_2,param_3
                              ,&local_68,(void *)0x0);
        goto LAB_c01204ec;
      }
      if (param_2 != 8) goto LAB_c012058c;
      if (*(int *)(param_1 + 0x38) == 0) {
LAB_c0120250:
        local_68 = *(uint *)(param_1 + 0x18);
        local_64 = *(uint *)(param_1 + 0x1c);
        local_60 = *(uint *)(param_1 + 0x20);
        goto LAB_c0120268;
      }
      if (param_3 != 0) {
        if (param_3 != 0) {
          param_3 = param_3 - 1;
        }
        goto LAB_c0120250;
      }
      SetLastError(0x19);
      goto LAB_c01205a0;
    }
    if ((param_2 != 0x20) && (param_2 != 0x40)) {
      if (param_2 != 0x80) goto LAB_c012058c;
      local_68 = *(uint *)(param_1 + 0x18);
      local_64 = *(uint *)(param_1 + 0x1c);
      local_60 = *(uint *)(param_1 + 0x20);
    }
LAB_c01203a0:
    if (((param_3 == 0) || (param_4 == 0)) || (3 < param_4)) {
LAB_c012058c:
      dwErrCode = 0x57;
      goto LAB_c0120590;
    }
    for (uVar6 = 0; uVar6 < param_4; uVar6 = uVar6 + 1 & 0xffff) {
      puVar3 = (uint *)(uVar6 * 0x10 + param_3);
      uVar7 = *puVar3;
      if ((uVar7 == 0) ||
         (*(uint *)(((uint)*(ushort *)(param_1 + 0x24) * 0x10 + uVar6 + 0x1a) * 4 + uVar2) != uVar7)
         ) {
        SetLastError(0x57);
        goto LAB_c01205a0;
      }
      if ((uVar7 & 0xffff) == 0x41) {
        *(short *)(puVar3 + 1) = (short)puVar3[2] + 2;
      }
      else if ((uVar7 & 0xffff) == 0x1f) {
        sVar5 = wcslen((wchar_t *)puVar3[2]);
        *(short *)(puVar3 + 1) = ((short)sVar5 + 1) * 2;
      }
      *(undefined2 *)((int)puVar3 + 6) = 0;
    }
    if ((param_2 == 0x80) && (*(int *)(param_1 + 0x38) != 0)) {
      param_2 = 0;
    }
    puVar3 = FUN_c012d898(auStack_38,(int)puVar8,uVar2,
                          (uint)*(ushort *)(param_1 + 0x24) * 0x40 + uVar2 + 100,param_2,param_3,
                          (ushort)param_4,&local_68);
LAB_c01204ec:
    local_68 = *puVar3;
    local_64 = puVar3[1];
    local_60 = puVar3[2];
LAB_c0120504:
    uVar6 = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    if (local_64 == 0) {
      SetLastError(0x19);
      local_80 = 0;
      goto LAB_c01205a4;
    }
    local_80 = FUN_c0101ea4((int)puVar8,local_64);
    *(uint *)(param_1 + 0x18) = local_68;
    *(uint *)(param_1 + 0x1c) = local_64;
    *(uint *)(param_1 + 0x20) = local_60;
    if (param_5 != (uint *)0x0) {
      uVar6 = FUN_c012ddbc((int)puVar8,(uint)*(ushort *)(param_1 + 0x24) * 0x40 + uVar2 + 100,
                           local_68,local_64,(ushort)local_60);
      goto LAB_c01205a4;
    }
  }
  else {
    dwErrCode = 0x70;
LAB_c0120590:
    SetLastError(dwErrCode);
LAB_c01205a0:
    uVar6 = 0;
LAB_c01205a4:
    if (param_5 != (uint *)0x0) {
      *param_5 = uVar6;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)puVar8[0x87]);
LAB_c0120624:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  FUN_c012bc10((HLOCAL)0x0);
  return local_80;
}



/* c0120684 FUN_c0120684 */

/* Boundary evidence: original MIPS .pdata c0120684..c012068f. Semantic name remains unreviewed. */

undefined4 FUN_c0120684(void)

{
  return 1;
}



/* c0120690 FUN_c0120690 */

/* Boundary evidence: original MIPS .pdata c0120690..c012069b. Semantic name remains unreviewed. */

undefined4 FUN_c0120690(void)

{
  return 1;
}



/* c012069c FUN_c012069c */

/* Boundary evidence: original MIPS .pdata c012069c..c01206a7. Semantic name remains unreviewed. */

undefined4 FUN_c012069c(void)

{
  return 1;
}



/* c01206a8 FUN_c01206a8 */

/* Boundary evidence: original MIPS .pdata c01206a8..c01207c3. Semantic name remains unreviewed. */

uint FUN_c01206a8(int param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  int iVar1;
  DWORD dwErrCode;
  uint uVar2;
  uint local_20 [2];
  
  local_20[0] = 0;
  if ((((param_2 == 0x10) || (param_2 == 0x40)) || (param_2 == 0x20)) ||
     (uVar2 = param_3, param_2 == 0x80)) {
    if (((param_3 == 0) || (param_4 == 0)) || (3 < param_4)) {
      dwErrCode = 0x57;
    }
    else {
      iVar1 = CeOpenCallerBuffer(local_20,param_3,param_4 << 4,4,1);
      uVar2 = local_20[0];
      if (-1 < iVar1) goto LAB_c0120750;
      dwErrCode = 0xe;
    }
    SetLastError(dwErrCode);
    uVar2 = 0;
  }
  else {
LAB_c0120750:
    uVar2 = FUN_c012009c(param_1,param_2,uVar2,param_4,param_5);
    if (local_20[0] != 0) {
      CeCloseCallerBuffer(local_20[0],param_3,param_4 << 4,4);
    }
  }
  return uVar2;
}



/* c01207c4 FUN_c01207c4 */

/* Boundary evidence: original MIPS .pdata c01207c4..c0120917. Semantic name remains unreviewed. */

undefined4 FUN_c01207c4(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  if (*(int *)(param_3 + 4) != 0) {
    if (((*(uint *)(param_1[2] + 0xec) == 0xffffffff) ||
        (uVar1 = FUN_c0101c94((int)param_1,*(uint *)(param_1[2] + 0xec)), uVar1 == 0)) ||
       ((*(uint *)(uVar1 - 0xc) & 0xf0000000) != 0xa0000000)) {
      uVar1 = 0;
    }
    puVar2 = (ushort *)(param_2 + 0x4e);
    FUN_c01029e4((int)param_1,1,puVar2,(uint)*puVar2,2);
    *puVar2 = *puVar2 | 0x20;
    if (uVar1 != 0) {
      puVar3 = (undefined4 *)(uVar1 + 8);
      FUN_c01029e4((int)param_1,1,puVar3,*puVar3,4);
      *puVar3 = *(undefined4 *)(param_3 + 4);
    }
  }
  *(uint *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) - (*(uint *)(param_3 + -0xc) & 0xffffffc);
  FUN_c01037f0(param_1,*(uint *)(param_3 + -4));
  piVar4 = (int *)(param_2 + 0x48);
  FUN_c01029e4((int)param_1,1,piVar4,*piVar4,4);
  *piVar4 = *piVar4 + -1;
  return 1;
}



/* c0120918 FUN_c0120918 */

/* Boundary evidence: original MIPS .pdata c0120918..c0120aab. Semantic name remains unreviewed. */

undefined4 FUN_c0120918(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  ushort local_68 [2];
  HLOCAL local_64;
  HLOCAL local_60;
  uint local_5c;
  undefined4 auStack_58 [12];
  
  local_64 = (HLOCAL)0x0;
  local_5c = 0;
  uVar3 = 0;
  local_60 = (HLOCAL)0x0;
  uVar2 = 0;
  if (*(short *)(param_2 + 0x4c) != 0) {
    puVar4 = (ushort *)(param_2 + 0x4e);
    do {
      uVar5 = 1 << (uVar2 + 8 & 0x1f);
      if ((*puVar4 & uVar5) == 0) {
        iVar6 = uVar2 * 0x40 + param_2 + 100;
        iVar1 = FUN_c01273c4((int)param_1,param_2,param_3,iVar6,auStack_58,local_68,(int *)&local_64
                             ,&local_5c);
        if (iVar1 == 0) goto LAB_c0120a54;
        FUN_c01029e4((int)param_1,1,puVar4,uVar5 & 0xffff | (uint)*puVar4,2);
        iVar1 = FUN_c012dcf4(param_1,iVar6,*(uint *)(param_3 + -4),(int)auStack_58,local_68[0],0,
                             &local_60);
        if (iVar1 == 0) goto LAB_c0120a54;
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < *(ushort *)(param_2 + 0x4c));
  }
  uVar3 = FUN_c01207c4(param_1,param_2,param_3);
LAB_c0120a54:
  if (local_64 != (HLOCAL)0x0) {
    LocalFree(local_64);
  }
  if (local_60 != (HLOCAL)0x0) {
    LocalFree(local_60);
  }
  return uVar3;
}



/* c0120aac FUN_c0120aac */

/* Boundary evidence: original MIPS .pdata c0120aac..c0120c0f. Semantic name remains unreviewed. */

void FUN_c0120aac(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  uint *puVar4;
  
  if (((*(uint *)(param_1[2] + 0xec) == 0xffffffff) ||
      (uVar1 = FUN_c0101c94((int)param_1,*(uint *)(param_1[2] + 0xec)), uVar1 == 0)) ||
     ((*(uint *)(uVar1 - 0xc) & 0xf0000000) != 0xa0000000)) {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
    puVar4 = (uint *)(uVar1 + 8);
    uVar1 = *puVar4;
    while (uVar1 != 0) {
      puVar2 = (uint *)FUN_c0101c94((int)param_1,*puVar4);
      if (puVar2 == (uint *)0x0) {
        return;
      }
      FUN_c010297c((int)param_1);
      piVar3 = (int *)(param_2 + 0x5c);
      FUN_c01029e4((int)param_1,1,piVar3,*piVar3,4);
      *piVar3 = *piVar3 - (puVar2[-3] & 0xffffffc);
      uVar1 = *puVar2;
      FUN_c01037f0(param_1,*puVar4);
      FUN_c01029e4((int)param_1,1,puVar4,*puVar4,4);
      *puVar4 = uVar1;
      FUN_c0102aa4(param_1);
      uVar1 = *puVar4;
    }
    FUN_c010297c((int)param_1);
    *(ushort *)(param_2 + 0x4e) = *(ushort *)(param_2 + 0x4e) & 0xffdf;
    FUN_c0102aa4(param_1);
  }
  return;
}



/* c0120c10 FUN_c0120c10 */

/* Boundary evidence: original MIPS .pdata c0120c10..c0120d33. Semantic name remains unreviewed. */

void FUN_c0120c10(undefined4 *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (((*(uint *)(param_1[2] + 0xec) == 0xffffffff) ||
      (puVar1 = (uint *)FUN_c0101c94((int)param_1,*(uint *)(param_1[2] + 0xec)),
      puVar1 == (uint *)0x0)) || ((puVar1[-3] & 0xf0000000) != 0xa0000000)) {
    puVar1 = (uint *)0x0;
  }
  if (puVar1 != (uint *)0x0) {
    uVar2 = *puVar1;
    while (uVar2 != 0) {
      puVar1 = (uint *)FUN_c0101c94((int)param_1,uVar2);
      if ((puVar1 == (uint *)0x0) || ((puVar1[-3] & 0xf0000000) != 0x70000000)) {
        puVar1 = (uint *)0x0;
      }
      if (puVar1 == (uint *)0x0) {
        return;
      }
      if ((*(ushort *)((int)puVar1 + 0x4e) & 0x20) != 0) {
        FUN_c0120aac(param_1,(int)puVar1);
      }
      if ((*(ushort *)((int)puVar1 + 0x4e) & 8) == 0) {
        if ((*(ushort *)((int)puVar1 + 0x4e) & 0xff00) != 0) {
          FUN_c012d470(param_1,(int)puVar1);
        }
      }
      else {
        FUN_c011e8e4(param_1,puVar1);
      }
      uVar2 = *puVar1;
    }
  }
  return;
}



/* c0120d34 FUN_c0120d34 */

/* Boundary evidence: original MIPS .pdata c0120d34..c0120ea7. Semantic name remains unreviewed. */

void FUN_c0120d34(void)

{
  int iVar1;
  undefined4 in_a3;
  int aiStack_240 [4];
  undefined1 auStack_230 [520];
  uint local_28;
  
  local_28 = DAT_c0136c78;
  memset(aiStack_240,-1,0x10);
  while (iVar1 = CeEnumDBVolumes(aiStack_240,auStack_230,0x104), iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
    iVar1 = IsProcessDying();
    if (iVar1 == 0) {
      FUN_c0124220(aiStack_240,-0x3fec97b0,&DAT_c0136ec8,in_a3);
      if (DAT_c0136ed0 != 0) {
        SetEventData(DAT_c0136ed0,DAT_c0136ec8);
      }
    }
    else {
      SetLastError(0x10dc);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  }
  FUN_c013331c(local_28);
  return;
}



/* c0120ea8 FUN_c0120ea8 */

/* Boundary evidence: original MIPS .pdata c0120ea8..c0120eb3. Semantic name remains unreviewed. */

undefined4 FUN_c0120ea8(void)

{
  return 1;
}



/* c0120eb4 FUN_c0120eb4 */

/* Boundary evidence: original MIPS .pdata c0120eb4..c0120f6b. Semantic name remains unreviewed. */

BOOL FUN_c0120eb4(undefined4 param_1,LPCVOID param_2)

{
  BOOL BVar1;
  BOOL BVar2;
  
  BVar2 = 0;
  BVar1 = HeapValidate(DAT_c0136cb0,0,param_2);
  if (BVar1 != 0) {
    BVar2 = HeapFree(DAT_c0136cb0,0,param_2);
  }
  return BVar2;
}



/* c0120f6c FUN_c0120f6c */

/* Boundary evidence: original MIPS .pdata c0120f6c..c0120f77. Semantic name remains unreviewed. */

undefined4 FUN_c0120f6c(void)

{
  return 1;
}



/* c0120f78 FUN_c0120f78 */

/* Boundary evidence: original MIPS .pdata c0120f78..c0120fb7. Semantic name remains unreviewed. */

void FUN_c0120f78(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  
  do {
    DVar1 = DAT_c0136c6c;
    WaitForSingleObject(DAT_c0136ed0,DAT_c0136c6c);
    FUN_c010e7d0((uint *)0x0,DVar1,param_3,param_4);
  } while( true );
}



/* c0120fb8 FUN_c0120fb8 */

/* Boundary evidence: original MIPS .pdata c0120fb8..c0121297. Semantic name remains unreviewed. */

void FUN_c0120fb8(void)

{
  LSTATUS LVar1;
  DWORD local_248 [2];
  HKEY local_240;
  int local_23c;
  DWORD aDStack_238 [2];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c0136c78;
  local_23c = 0;
  LVar1 = RegOpenKeyExW((HKEY)&DAT_80000002,L"System\\ObjectStore\\DBFlush",0,0,&local_240);
  if (LVar1 != 0) goto LAB_c0121258;
  local_248[1] = 0x208;
  LVar1 = RegQueryValueExW(local_240,L"ActivityName",(LPDWORD)0x0,local_248,(LPBYTE)aWStack_230,
                           local_248 + 1);
  if ((LVar1 == 0) && (local_248[0] == 1)) {
    DAT_c0136ed0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,aWStack_230);
    if (DAT_c0136ed0 != (HANDLE)0x0) {
      SetEventData(DAT_c0136ed0,0);
    }
  }
  local_248[1] = 4;
  LVar1 = RegQueryValueExW(local_240,L"ActivityThreshold",(LPDWORD)0x0,local_248,
                           (LPBYTE)&DAT_c0136c68,local_248 + 1);
  if ((LVar1 != 0) || (local_248[0] != 4)) {
    DAT_c0136c68 = 100;
  }
  local_248[1] = 4;
  LVar1 = RegQueryValueExW(local_240,L"SpawnThread",(LPDWORD)0x0,local_248,(LPBYTE)&local_23c,
                           local_248 + 1);
  if (((LVar1 == 0) && (local_248[0] == 4)) && (local_23c == 1)) {
    if (DAT_c0136ed0 == (HANDLE)0x0) {
      DAT_c0136ed0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if (DAT_c0136ed0 == (HANDLE)0x0) goto LAB_c0121248;
    }
    LVar1 = RegQueryValueExW(local_240,L"FlushPriority256",(LPDWORD)0x0,local_248,
                             (LPBYTE)&DAT_c01394fc,local_248 + 1);
    if ((LVar1 != 0) || (local_248[0] != 4)) {
      DAT_c01394fc = 0xff;
    }
    LVar1 = RegQueryValueExW(local_240,L"FlushPeriod",(LPDWORD)0x0,local_248,(LPBYTE)&DAT_c0136c6c,
                             local_248 + 1);
    if ((LVar1 != 0) || (local_248[0] != 4)) {
      DAT_c0136c6c = 0xffffffff;
    }
    DAT_c01394f8 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0120f78,(LPVOID)0x0,0,aDStack_238)
    ;
    if (DAT_c01394f8 != (HANDLE)0x0) {
      CeSetThreadPriority(DAT_c01394f8,DAT_c01394fc);
    }
  }
LAB_c0121248:
  RegCloseKey(local_240);
LAB_c0121258:
  if (DAT_c0136ed0 != (HANDLE)0x0) {
    DAT_c0136ecc = 1;
  }
  FUN_c013331c(local_28);
  return;
}



/* c0121298 FUN_c0121298 */

/* Boundary evidence: original MIPS .pdata c0121298..c01212b7. Semantic name remains unreviewed. */

undefined4 FUN_c0121298(void)

{
  FUN_c0120fb8();
  return 1;
}



/* c01212b8 FUN_c01212b8 */

/* Boundary evidence: original MIPS .pdata c01212b8..c012179f. Semantic name remains unreviewed. */

uint FUN_c01212b8(int *param_1,short *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  BOOL BVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  DWORD DVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 local_88 [2];
  undefined4 local_80;
  undefined1 auStack_7c [16];
  uint local_6c;
  undefined4 local_68;
  _BY_HANDLE_FILE_INFORMATION local_60;
  
  uVar9 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar2 = IsProcessDying();
  if (iVar2 != 0) {
    SetLastError(0x10dc);
    goto LAB_c0121734;
  }
  if ((param_1 == (int *)0x0) || (puVar3 = FUN_c0124094(param_1,2), puVar3 == (undefined4 *)0x0)) {
    SetLastError(0x57);
    puVar3 = (undefined4 *)0x0;
  }
  if (puVar3 == (undefined4 *)0x0) goto LAB_c0121734;
  EnterCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
  bVar1 = false;
  if ((param_2 == (short *)0x0) || (*param_2 != 1)) {
LAB_c0121498:
    DVar8 = 0x57;
LAB_c0121470:
    SetLastError(DVar8);
    goto LAB_c01216a8;
  }
  if (((*(ushort *)((int)puVar3 + 0x24e) & 0x20) != 0) ||
     ((((*(uint *)(param_2 + 2) & 0x20000) != 0 && (puVar3 != &DAT_c01391e0)) &&
      ((BVar4 = GetFileInformationByHandle((HANDLE)puVar3[0x8a],&local_60), BVar4 == 0 ||
       ((local_60.dwFileAttributes & 4) == 0)))))) {
    SetLastError(5);
    goto LAB_c01216a8;
  }
  uVar5 = FUN_c011e794((int)puVar3,param_2 + 4,(uint *)0x0);
  if (uVar5 != 0) {
    DVar8 = 0x34;
    goto LAB_c0121470;
  }
  iVar2 = FUN_c011e5e8((int)param_2);
  if (iVar2 == 0) goto LAB_c0121498;
  FUN_c010297c((int)puVar3);
  bVar1 = true;
  puVar6 = FUN_c0103dc8(puVar3,7,0x164,0,0);
  if (puVar6 == (uint *)0x0) {
    DVar8 = 0x70;
LAB_c01214dc:
    SetLastError(DVar8);
LAB_c01216a8:
    if (bVar1) {
      FUN_c01036ac(puVar3);
    }
  }
  else {
    puVar10 = puVar6 + 3;
    if (puVar10 == (uint *)0x0) goto LAB_c01216a8;
    memset(puVar6 + 4,0,0x160);
    puVar6[4] = *(uint *)(param_2 + 0x24);
    *(short *)(puVar6 + 0x17) = param_2[3];
    wcsncpy((wchar_t *)(puVar6 + 5),param_2 + 4,0x1f);
    *(undefined2 *)((int)puVar6 + 0x52) = 0;
    *(short *)(puVar6 + 0x16) = param_2[1];
    puVar6[0x1a] = *puVar6 & 0xffffffc;
    GetCurrentFT(puVar6 + 0x18);
    iVar2 = FUN_c012cf00((int)puVar3,(int)puVar10,(int)param_2);
    if (iVar2 == 0) goto LAB_c01216a8;
    if (((*(uint *)(puVar3[2] + 0xec) == 0xffffffff) ||
        (puVar7 = (uint *)FUN_c0101c94((int)puVar3,*(uint *)(puVar3[2] + 0xec)),
        puVar7 == (uint *)0x0)) || ((puVar7[-3] & 0xf0000000) != 0xa0000000)) {
      puVar7 = (uint *)0x0;
    }
    if (puVar7 == (uint *)0x0) {
      DVar8 = 0x57;
      goto LAB_c01214dc;
    }
    *puVar10 = *puVar7;
    FUN_c01029e4((int)puVar3,1,puVar7,*puVar7,4);
    *puVar7 = puVar6[2];
    FUN_c0102aa4(puVar3);
    uVar9 = FUN_c0101ea4((int)puVar3,puVar6[2]);
    local_88[0] = 0x24;
    local_80 = 0x401;
    if ((puVar3 == &DAT_c01391e0) || (puVar3 == (undefined4 *)PTR_DAT_c0136c70)) {
      memset(auStack_7c,0,0x10);
    }
    else {
      memcpy(auStack_7c,(void *)(puVar3[2] + 0xc),0x10);
    }
    local_68 = 0;
    local_6c = uVar9;
    FUN_c011d9f8(puVar3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)puVar3[0x87]);
LAB_c0121734:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  if (uVar9 != 0) {
    FUN_c0126818((undefined4 *)0x0,local_88);
  }
  return uVar9;
}



/* c01217a0 FUN_c01217a0 */

/* Boundary evidence: original MIPS .pdata c01217a0..c01217ab. Semantic name remains unreviewed. */

undefined4 FUN_c01217a0(void)

{
  return 1;
}



/* c01217ac FUN_c01217ac */

/* Boundary evidence: original MIPS .pdata c01217ac..c01217b7. Semantic name remains unreviewed. */

undefined4 FUN_c01217ac(void)

{
  return 1;
}



/* c01217b8 FUN_c01217b8 */

/* Boundary evidence: original MIPS .pdata c01217b8..c01217c3. Semantic name remains unreviewed. */

undefined4 FUN_c01217b8(void)

{
  return 1;
}



/* c01217c4 FUN_c01217c4 */

/* Boundary evidence: original MIPS .pdata c01217c4..c0121bc3. Semantic name remains unreviewed. */

int FUN_c01217c4(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  DWORD dwErrCode;
  int *piVar4;
  int iVar5;
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined1 auStack_44 [16];
  uint local_34;
  undefined4 local_30;
  
  iVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar1 = IsProcessDying();
  if (iVar1 != 0) {
    SetLastError(0x10dc);
    goto LAB_c0121b5c;
  }
  if (((param_1 == (int *)0x0) || (puVar2 = FUN_c0124094(param_1,2), puVar2 == (undefined4 *)0x0))
     || ((param_2 != 0 &&
         (((param_2 >> 0x1c == 0 && (puVar2 != &DAT_c01391e0)) ||
          ((param_2 >> 0x1c == 3 && (puVar2 == &DAT_c01391e0)))))))) {
    SetLastError(0x57);
    puVar2 = (undefined4 *)0x0;
  }
  if (puVar2 == (undefined4 *)0x0) goto LAB_c0121b5c;
  EnterCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
  puVar3 = (uint *)FUN_c0101de8((int)puVar2,param_2);
  if ((puVar3 == (uint *)0x0) || ((puVar3[-3] & 0xf0000000) != 0x70000000)) {
    puVar3 = (uint *)0x0;
  }
  if (puVar3 == (uint *)0x0) {
    dwErrCode = 0x57;
LAB_c0121958:
    SetLastError(dwErrCode);
  }
  else {
    piVar4 = DAT_c0137134;
    if ((*(ushort *)((int)puVar2 + 0x24e) & 0x20) == 0) {
      for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        if (((undefined4 *)piVar4[4] == puVar2) && (piVar4[5] == (param_2 & 0xffffff))) {
          dwErrCode = 0x20;
          goto LAB_c0121958;
        }
      }
      iVar1 = FUN_c0104fd0();
      if (iVar1 != 0) {
        FUN_c010297c((int)puVar2);
        *(ushort *)((int)puVar3 + 0x4e) = *(ushort *)((int)puVar3 + 0x4e) | 8;
        FUN_c0102aa4(puVar2);
        iVar1 = FUN_c011e8e4(puVar2,puVar3);
        if (iVar1 == 0) {
          FUN_c010297c((int)puVar2);
          *(ushort *)((int)puVar3 + 0x4e) = *(ushort *)((int)puVar3 + 0x4e) & 0xfff7;
          FUN_c0102aa4(puVar2);
        }
        else {
          local_50[0] = 0x24;
          local_48 = 0x402;
          if (puVar2 == (undefined4 *)0x0) {
            iVar1 = -1;
LAB_c0121aa8:
            memset(auStack_44,iVar1,0x10);
          }
          else {
            if ((puVar2 == &DAT_c01391e0) || (puVar2 == (undefined4 *)PTR_DAT_c0136c70)) {
              iVar1 = 0;
              goto LAB_c0121aa8;
            }
            memcpy(auStack_44,(void *)(puVar2[2] + 0xc),0x10);
          }
          local_30 = 0;
          local_34 = param_2;
          FUN_c011d9f8(puVar2);
          iVar5 = 1;
        }
      }
    }
    else {
      SetLastError(5);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
LAB_c0121b5c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  if (iVar5 != 0) {
    FUN_c0126818((undefined4 *)0x0,local_50);
  }
  return iVar5;
}



/* c0121bc4 FUN_c0121bc4 */

/* Boundary evidence: original MIPS .pdata c0121bc4..c0121bcf. Semantic name remains unreviewed. */

undefined4 FUN_c0121bc4(void)

{
  return 1;
}



/* c0121bd0 FUN_c0121bd0 */

/* Boundary evidence: original MIPS .pdata c0121bd0..c0121bdb. Semantic name remains unreviewed. */

undefined4 FUN_c0121bd0(void)

{
  return 1;
}



/* c0121bdc FUN_c0121bdc */

/* Boundary evidence: original MIPS .pdata c0121bdc..c0121be7. Semantic name remains unreviewed. */

undefined4 FUN_c0121bdc(void)

{
  return 1;
}



/* c0121be8 FUN_c0121be8 */

/* Boundary evidence: original MIPS .pdata c0121be8..c0121fdf. Semantic name remains unreviewed. */

int FUN_c0121be8(int *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  BOOL BVar4;
  uint uVar5;
  DWORD dwErrCode;
  int *piVar6;
  int iVar7;
  _BY_HANDLE_FILE_INFORMATION local_60;
  
  iVar7 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar1 = IsProcessDying();
  if (iVar1 != 0) {
    SetLastError(0x10dc);
    goto LAB_c0121f8c;
  }
  if (((param_1 == (int *)0x0) || (puVar2 = FUN_c0124094(param_1,2), puVar2 == (undefined4 *)0x0))
     || ((param_2 != 0 &&
         (((param_2 >> 0x1c == 0 && (puVar2 != &DAT_c01391e0)) ||
          ((param_2 >> 0x1c == 3 && (puVar2 == &DAT_c01391e0)))))))) {
    SetLastError(0x57);
    puVar2 = (undefined4 *)0x0;
  }
  if (puVar2 == (undefined4 *)0x0) goto LAB_c0121f8c;
  EnterCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
  puVar3 = (uint *)FUN_c0101de8((int)puVar2,param_2);
  if ((puVar3 == (uint *)0x0) || ((puVar3[-3] & 0xf0000000) != 0x70000000)) {
    puVar3 = (uint *)0x0;
  }
  if (((puVar3 == (uint *)0x0) || (param_3 == (uint *)0x0)) || ((short)*param_3 != 1)) {
LAB_c0121f04:
    dwErrCode = 0x57;
LAB_c0121f08:
    SetLastError(dwErrCode);
  }
  else if (((*(ushort *)((int)puVar2 + 0x24e) & 0x20) == 0) &&
          ((((param_3[1] & 0x20000) == 0 || (puVar2 == &DAT_c01391e0)) ||
           ((BVar4 = GetFileInformationByHandle((HANDLE)puVar2[0x8a],&local_60), BVar4 != 0 &&
            ((local_60.dwFileAttributes & 4) != 0)))))) {
    iVar1 = FUN_c0104fd0();
    if (iVar1 != 0) {
      if (((param_3[1] & 1) != 0) &&
         (uVar5 = FUN_c011e794((int)puVar2,(PCNZWCH)(param_3 + 2),(uint *)0x0), uVar5 != 0)) {
        dwErrCode = 0x34;
        goto LAB_c0121f08;
      }
      piVar6 = DAT_c0137134;
      if ((param_3[1] & 4) != 0) {
        for (; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
          if (((undefined4 *)piVar6[4] == puVar2) && (piVar6[5] == (param_2 & 0xffffff))) {
            dwErrCode = 0x20;
            goto LAB_c0121f08;
          }
        }
        iVar1 = FUN_c011e5e8((int)param_3);
        if (iVar1 == 0) goto LAB_c0121f04;
      }
      iVar7 = FUN_c011ea6c(puVar2,puVar3,param_3);
      if (iVar7 != 0) {
        FUN_c011d9f8(puVar2);
      }
    }
  }
  else {
    SetLastError(5);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
LAB_c0121f8c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return iVar7;
}



/* c0121fe0 FUN_c0121fe0 */

/* Boundary evidence: original MIPS .pdata c0121fe0..c0121feb. Semantic name remains unreviewed. */

undefined4 FUN_c0121fe0(void)

{
  return 1;
}



/* c0121fec FUN_c0121fec */

/* Boundary evidence: original MIPS .pdata c0121fec..c0121ff7. Semantic name remains unreviewed. */

undefined4 FUN_c0121fec(void)

{
  return 1;
}



/* c0121ff8 FUN_c0121ff8 */

/* Boundary evidence: original MIPS .pdata c0121ff8..c0122003. Semantic name remains unreviewed. */

undefined4 FUN_c0121ff8(void)

{
  return 1;
}



/* c0122004 FUN_c0122004 */

/* Boundary evidence: original MIPS .pdata c0122004..c01224d7. Semantic name remains unreviewed. */

int FUN_c0122004(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint *puVar5;
  DWORD dwErrCode;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  int local_74;
  undefined4 *local_6c;
  uint auStack_60 [4];
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined1 auStack_44 [16];
  uint local_34;
  uint local_30;
  
  iVar8 = 0;
  local_6c = (undefined4 *)0x0;
  local_74 = 1;
  iVar6 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar2 = IsProcessDying();
  if (iVar2 == 0) {
    puVar7 = *(undefined4 **)(param_1 + 0x10);
    if (puVar7 != (undefined4 *)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)puVar7[0x87]);
      do {
        bVar1 = false;
        piVar3 = (int *)FUN_c0101de8((int)puVar7,param_2);
        if ((piVar3 == (int *)0x0) || ((piVar3[-3] & 0xf0000000U) != 0x80000000)) {
          piVar3 = (int *)0x0;
        }
        uVar4 = FUN_c0101c94((int)puVar7,*(uint *)(param_1 + 0x14));
        if ((uVar4 == 0) || ((*(uint *)(uVar4 - 0xc) & 0xf0000000) != 0x70000000)) {
          uVar4 = 0;
        }
        if (((piVar3 == (int *)0x0) || (*piVar3 != *(int *)(param_1 + 0x14))) || (uVar4 == 0)) {
          dwErrCode = 0x57;
LAB_c0122160:
          SetLastError(dwErrCode);
LAB_c0122390:
          if (bVar1) {
            FUN_c01036ac(puVar7);
          }
        }
        else {
          if ((*(ushort *)((int)puVar7 + 0x24e) & 0x20) != 0) {
            dwErrCode = 5;
            goto LAB_c0122160;
          }
          iVar2 = FUN_c0104fd0();
          if (iVar2 == 0) goto LAB_c0122390;
          FUN_c010297c((int)puVar7);
          FUN_c01029e4((int)puVar7,1,(undefined4 *)(uVar4 + 0x5c),*(undefined4 *)(uVar4 + 0x5c),4);
          bVar1 = true;
          for (piVar9 = (int *)DAT_c0137134; piVar9 != (int *)0x0; piVar9 = (int *)*piVar9) {
            if (((piVar9[4] == *(int *)(param_1 + 0x10)) && (piVar9[5] == *(int *)(param_1 + 0x14)))
               && (piVar9[7] == (param_2 & 0xffffff))) {
              puVar5 = FUN_c012d5d8(auStack_60,piVar9[4],uVar4,
                                    (uint)*(ushort *)(piVar9 + 9) * 0x40 + uVar4 + 100,8,1,
                                    (uint *)(piVar9 + 6),(void *)0x0);
              piVar9[6] = *puVar5;
              piVar9[7] = puVar5[1];
              piVar9[8] = puVar5[2];
              if ((piVar9[3] & 1U) == 0) {
                piVar9[0xe] = param_2;
              }
            }
          }
          iVar6 = FUN_c0120918(puVar7,uVar4,(int)piVar3);
          if (iVar6 == 0) goto LAB_c0122390;
          FUN_c0102aa4(puVar7);
          if ((*(ushort *)(uVar4 + 0x4e) & 0x20) != 0) {
            FUN_c0120aac(puVar7,uVar4);
          }
          local_50[0] = 0x24;
          local_48 = 0x403;
          if (puVar7 == (undefined4 *)0x0) {
            iVar2 = -1;
LAB_c0122328:
            memset(auStack_44,iVar2,0x10);
          }
          else {
            if ((puVar7 == &DAT_c01391e0) || (puVar7 == (undefined4 *)PTR_DAT_c0136c70)) {
              iVar2 = 0;
              goto LAB_c0122328;
            }
            memcpy(auStack_44,(void *)(puVar7[2] + 0xc),0x10);
          }
          local_34 = param_2;
          local_30 = FUN_c0101ea4((int)puVar7,*(uint *)(param_1 + 0x14));
          FUN_c011d9f8(puVar7);
          iVar8 = 1;
        }
      } while ((iVar6 == 0) && (bVar1 = local_74 != 0, local_74 = local_74 + -1, bVar1));
      LeaveCriticalSection((LPCRITICAL_SECTION)puVar7[0x87]);
    }
    if (iVar8 != 0) {
      local_6c = FUN_c0126904(param_1,(int)local_50);
    }
  }
  else {
    SetLastError(0x10dc);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  if (iVar8 != 0) {
    FUN_c0126818(local_6c,local_50);
  }
  return iVar8;
}



/* c01224d8 FUN_c01224d8 */

/* Boundary evidence: original MIPS .pdata c01224d8..c01224e3. Semantic name remains unreviewed. */

undefined4 FUN_c01224d8(void)

{
  return 1;
}



/* c01224e4 FUN_c01224e4 */

/* Boundary evidence: original MIPS .pdata c01224e4..c01224ef. Semantic name remains unreviewed. */

undefined4 FUN_c01224e4(void)

{
  return 1;
}



/* c01224f0 FUN_c01224f0 */

/* Boundary evidence: original MIPS .pdata c01224f0..c01224fb. Semantic name remains unreviewed. */

undefined4 FUN_c01224f0(void)

{
  return 1;
}



/* c01224fc FUN_c01224fc */

/* Boundary evidence: original MIPS .pdata c01224fc..c01225cb. Semantic name remains unreviewed. */

undefined4 FUN_c01224fc(undefined1 *param_1)

{
  BOOL BVar1;
  DWORD local_18 [2];
  
  if (*(int *)((int)DAT_c0137130 + 0xfa4) == 4000) {
    BVar1 = ReadFile(*(HANDLE *)((int)DAT_c0137130 + 4000),DAT_c0137130,4000,local_18,
                     (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      return 0;
    }
    *(undefined4 *)((int)DAT_c0137130 + 0xfa4) = 0;
    *(DWORD *)((int)DAT_c0137130 + 0xfa8) = local_18[0];
    *(DWORD *)((int)DAT_c0137130 + 0xfac) = *(int *)((int)DAT_c0137130 + 0xfac) + local_18[0];
  }
  if (*(int *)((int)DAT_c0137130 + 0xfa8) <= *(int *)((int)DAT_c0137130 + 0xfa4)) {
    return 0;
  }
  *param_1 = *(undefined1 *)((int)DAT_c0137130 + *(int *)((int)DAT_c0137130 + 0xfa4));
  *(int *)((int)DAT_c0137130 + 0xfa4) = *(int *)((int)DAT_c0137130 + 0xfa4) + 1;
  return 1;
}



/* c01225cc FUN_c01225cc */

/* Boundary evidence: original MIPS .pdata c01225cc..c012268f. Semantic name remains unreviewed. */

void FUN_c01225cc(void)

{
  int iVar1;
  char local_10 [8];
  
  do {
    iVar1 = FUN_c01224fc(local_10);
    if ((iVar1 == 0) || (local_10[0] == ':')) goto LAB_c0122658;
  } while ((local_10[0] != ']') && (local_10[0] != '['));
LAB_c0122670:
  *(int *)(DAT_c0137130 + 0xfa4) = *(int *)(DAT_c0137130 + 0xfa4) + -1;
  return;
LAB_c0122658:
  do {
    iVar1 = FUN_c01224fc(local_10);
    if (iVar1 == 0) {
      return;
    }
  } while ((((local_10[0] == ' ') || (local_10[0] == '\t')) || (local_10[0] == '\n')) ||
          (local_10[0] == '\r'));
  goto LAB_c0122670;
}



/* c0122690 FUN_c0122690 */

/* Boundary evidence: original MIPS .pdata c0122690..c012277f. Semantic name remains unreviewed. */

bool FUN_c0122690(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char local_18 [8];
  
  iVar4 = 0;
  iVar3 = 0;
  do {
    iVar1 = FUN_c01224fc(local_18);
    if (iVar1 == 0) break;
    iVar1 = (int)local_18[0];
    if ((iVar1 < 0x30) || (0x39 < iVar1)) {
      if ((iVar1 < 0x61) || (0x66 < iVar1)) {
        if ((iVar1 < 0x41) || (0x46 < iVar1)) {
          *(int *)(DAT_c0137130 + 0xfa4) = *(int *)(DAT_c0137130 + 0xfa4) + -1;
          break;
        }
        uVar2 = iVar1 + 0xc9;
      }
      else {
        uVar2 = iVar1 + 0xa9;
      }
    }
    else {
      uVar2 = iVar1 + 0xd0;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 * 0x10 + (uVar2 & 0xff);
  } while (iVar3 != 8);
  *param_1 = iVar4;
  return iVar3 != 0;
}



/* c0122780 FUN_c0122780 */

/* Boundary evidence: original MIPS .pdata c0122780..c0122977. Semantic name remains unreviewed. */

undefined4 FUN_c0122780(ushort *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  byte local_30 [8];
  
  uVar7 = *param_2;
  uVar6 = 1;
  iVar1 = FUN_c01224fc(local_30);
  if ((iVar1 == 0) || (local_30[0] != 0x22)) {
    return 0;
  }
  iVar1 = FUN_c01224fc(local_30);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if (uVar7 <= uVar6) {
      return 0;
    }
    if (local_30[0] == 0x22) {
      *param_1 = 0;
      *param_2 = uVar6;
      return 1;
    }
    if (local_30[0] == 0x5c) {
      iVar1 = FUN_c01224fc(local_30);
      if (iVar1 == 0) {
        return 0;
      }
      if (local_30[0] == 0x22) {
        *param_1 = 0x22;
      }
      else {
        if (local_30[0] != 0x58) {
          if (local_30[0] == 0x5c) {
            *param_1 = 0x5c;
            goto LAB_c012291c;
          }
          if (local_30[0] != 0x78) {
            return 0;
          }
        }
        uVar5 = 0;
        iVar1 = 0;
        do {
          iVar2 = FUN_c01224fc(local_30);
          if (iVar2 == 0) {
            return 0;
          }
          uVar3 = (ushort)local_30[0];
          uVar4 = uVar3 - 0x30;
          if (9 < uVar4) {
            uVar4 = uVar3 - 0x37;
            if (0xf < uVar4) {
              uVar4 = uVar3 - 0x57;
            }
            if (0xf < uVar4) {
              return 0;
            }
          }
          iVar1 = iVar1 + 1;
          uVar5 = uVar5 << 4 | uVar4 & 0xf;
        } while (iVar1 < 4);
        *param_1 = uVar5;
      }
    }
    else {
      if (local_30[0] == 10) {
        return 0;
      }
      if (local_30[0] == 0xd) {
        return 0;
      }
      *param_1 = (ushort)local_30[0];
    }
LAB_c012291c:
    param_1 = param_1 + 1;
    uVar6 = uVar6 + 1;
    iVar1 = FUN_c01224fc(local_30);
  } while( true );
}



/* c0122978 FUN_c0122978 */

/* Boundary evidence: original MIPS .pdata c0122978..c0122c23. Semantic name remains unreviewed. */

undefined4 FUN_c0122978(undefined2 *param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  char local_30;
  char local_2f [3];
  uint local_2c;
  
  uVar7 = 0;
  memset(param_1,0,0xdc);
  *param_1 = 1;
  FUN_c01225cc();
  local_2c = 0x20;
  iVar3 = FUN_c0122780(param_1 + 4,&local_2c);
  if (iVar3 != 0) {
    FUN_c01225cc();
    bVar1 = FUN_c0122690((int *)(param_1 + 0x24));
    if (CONCAT31(extraout_var,bVar1) != 0) {
      FUN_c01225cc();
      bVar1 = FUN_c0122690((int *)&local_2c);
      if ((CONCAT31(extraout_var_00,bVar1) != 0) && (local_2c < 5)) {
        param_1[1] = (short)local_2c;
        uVar6 = 0;
        if ((local_2c & 0xffff) != 0) {
          do {
            bVar1 = false;
            FUN_c01225cc();
            FUN_c01224fc(&local_30);
            if ((local_30 == ']') || (local_30 == '[')) {
              bVar1 = true;
              do {
                iVar3 = FUN_c01224fc(local_2f);
                if (iVar3 == 0) goto LAB_c0122ad8;
              } while ((local_2f[0] == ' ') || (local_2f[0] == '\t'));
              *(int *)(DAT_c0137130 + 0xfa4) = *(int *)(DAT_c0137130 + 0xfa4) + -1;
LAB_c0122ad8:
              bVar2 = FUN_c0122690((int *)&local_2c);
              if (CONCAT31(extraout_var_01,bVar2) == 0) {
                return 0;
              }
              if (3 < local_2c) {
                return 0;
              }
              puVar4 = param_1 + uVar6 * 0x10;
              puVar4[0x2f] = (short)local_2c;
              FUN_c01225cc();
            }
            else {
              *(int *)(DAT_c0137130 + 0xfa4) = *(int *)(DAT_c0137130 + 0xfa4) + -1;
              puVar4 = param_1 + uVar6 * 0x10;
              puVar4[0x2f] = 1;
            }
            puVar4[0x2e] = 1;
            uVar5 = 0;
            if (puVar4[0x2f] != 0) {
              do {
                iVar3 = uVar5 + uVar6 * 8;
                bVar2 = FUN_c0122690((int *)(param_1 + (iVar3 + 0x19) * 2));
                if (CONCAT31(extraout_var_02,bVar2) == 0) {
                  return 0;
                }
                FUN_c01225cc();
                bVar2 = FUN_c0122690((int *)(param_1 + (iVar3 + 0x1c) * 2));
                if (CONCAT31(extraout_var_03,bVar2) == 0) {
                  return 0;
                }
                if (uVar5 + 1 < (uint)(ushort)puVar4[0x2f]) {
                  FUN_c01225cc();
                }
                uVar5 = uVar5 + 1 & 0xffff;
              } while (uVar5 < (ushort)puVar4[0x2f]);
            }
            if (bVar1) {
              FUN_c01225cc();
              FUN_c01224fc(&local_30);
              if ((local_30 != ']') && (local_30 != '[')) {
                return 0;
              }
            }
            uVar6 = uVar6 + 1 & 0xffff;
          } while (uVar6 < (ushort)param_1[1]);
        }
        uVar7 = 1;
      }
    }
  }
  return uVar7;
}



/* c0122c24 FUN_c0122c24 */

/* Boundary evidence: original MIPS .pdata c0122c24..c0122db3. Semantic name remains unreviewed. */

bool FUN_c0122c24(ushort *param_1)

{
  ushort uVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  char local_18 [4];
  uint local_14;
  
  puVar5 = (ushort *)((uint)*param_1 * 0x10 + *(int *)(param_1 + 2));
  FUN_c01225cc();
  FUN_c0122690((int *)puVar5);
  FUN_c01225cc();
  uVar1 = *puVar5;
  if (uVar1 < 0x13) {
    if (((uVar1 != 0x12) && (uVar1 != 2)) && (uVar1 != 3)) {
      if (uVar1 == 5) goto LAB_c0122d1c;
      if (uVar1 != 0xb) {
        return false;
      }
    }
  }
  else if (uVar1 != 0x13) {
    if (uVar1 == 0x1f) {
      local_14 = 0x400;
      puVar4 = LocalAlloc(0,0x800);
      *(ushort **)(puVar5 + 4) = puVar4;
      if (puVar4 == (ushort *)0x0) {
        return false;
      }
      iVar3 = FUN_c0122780(puVar4,&local_14);
      goto LAB_c0122cc0;
    }
    if (uVar1 != 0x40) {
      return false;
    }
LAB_c0122d1c:
    bVar2 = FUN_c0122690((int *)(puVar5 + 6));
    if (CONCAT31(extraout_var_00,bVar2) == 0) {
      return false;
    }
    do {
      iVar3 = FUN_c01224fc(local_18);
      if (iVar3 == 0) goto LAB_c0122cb8;
    } while ((local_18[0] == ' ') || (local_18[0] == '\t'));
    *(int *)(DAT_c0137130 + 0xfa4) = *(int *)(DAT_c0137130 + 0xfa4) + -1;
  }
LAB_c0122cb8:
  bVar2 = FUN_c0122690((int *)(puVar5 + 4));
  iVar3 = CONCAT31(extraout_var,bVar2);
LAB_c0122cc0:
  if (iVar3 != 0) {
    *param_1 = *param_1 + 1;
  }
  return iVar3 != 0;
}



/* c0122db4 FUN_c0122db4 */

/* Boundary evidence: original MIPS .pdata c0122db4..c0122e4b. Semantic name remains unreviewed. */

void FUN_c0122db4(ushort *param_1)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != (ushort *)0x0) && (*(int *)(param_1 + 2) != 0)) && (iVar2 = 0, *param_1 != 0)) {
    iVar1 = 0;
    do {
      if (*(short *)(*(int *)(param_1 + 2) + iVar1) == 0x1f) {
        LocalFree(*(HLOCAL *)((short *)(*(int *)(param_1 + 2) + iVar1) + 4));
        *(undefined4 *)(*(int *)(param_1 + 2) + iVar1 + 8) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10;
    } while (iVar2 < (int)(uint)*param_1);
  }
  return;
}



/* c0122e4c FUN_c0122e4c */

/* Boundary evidence: original MIPS .pdata c0122e4c..c0123017. Semantic name remains unreviewed. */

HANDLE FUN_c0122e4c(undefined4 param_1,int param_2)

{
  ushort uVar1;
  bool bVar2;
  DWORD DVar3;
  HANDLE hObject;
  int iVar4;
  undefined1 *puVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  HANDLE pvVar9;
  uint uVar10;
  int local_248 [2];
  undefined2 local_240 [3];
  ushort local_23a;
  int local_1f4;
  undefined1 auStack_1e0 [2];
  ushort auStack_1de [223];
  
  bVar2 = true;
  local_248[0] = CeCreateDatabaseEx2(param_1,param_2);
  if (local_248[0] == 0) {
    DVar3 = GetLastError();
    if (DVar3 != 0x34) {
      return (HANDLE)0xffffffff;
    }
    bVar2 = false;
  }
  hObject = (HANDLE)CeOpenDatabaseEx2(param_1,local_248,param_2 + 8,0,0,0);
  pvVar9 = (HANDLE)0xffffffff;
  if ((hObject != (HANDLE)0xffffffff) && (pvVar9 = hObject, !bVar2)) {
    local_240[0] = 1;
    iVar4 = CeOidGetInfoEx2(param_1,local_248[0],local_240);
    if ((iVar4 == 0) ||
       ((local_1f4 != *(int *)(param_2 + 0x48) ||
        (uVar1 = *(ushort *)(param_2 + 2), local_23a != uVar1)))) {
LAB_c0122f08:
      CloseHandle(hObject);
      pvVar9 = (HANDLE)0xffffffff;
    }
    else {
      puVar5 = auStack_1e0;
      uVar6 = 0;
      if (uVar1 != 0) {
        iVar4 = param_2 + 0x5c;
        do {
          uVar7 = (uint)*(ushort *)(iVar4 + 2);
          if (*(ushort *)((int)auStack_1de + (iVar4 - (param_2 + 0x5c))) != uVar7)
          goto LAB_c0122f08;
          uVar10 = 0;
          if (uVar7 != 0) {
            do {
              iVar8 = (uVar10 + 2) * 4;
              if ((*(int *)(puVar5 + iVar8) != *(int *)(iVar8 + iVar4)) ||
                 (iVar8 = (uVar10 + 5) * 4, *(int *)(puVar5 + iVar8) != *(int *)(iVar8 + iVar4)))
              goto LAB_c0122f08;
              uVar10 = uVar10 + 1 & 0xffff;
            } while (uVar10 < uVar7);
          }
          uVar6 = uVar6 + 1;
          puVar5 = puVar5 + 0x20;
          iVar4 = iVar4 + 0x20;
        } while (uVar6 < uVar1);
      }
    }
  }
  return pvVar9;
}



/* c0123018 FUN_c0123018 */

/* Boundary evidence: original MIPS .pdata c0123018..c01233bb. Semantic name remains unreviewed. */

void FUN_c0123018(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  HANDLE pvVar4;
  void *_Dst;
  int iVar5;
  undefined3 extraout_var;
  uint uVar6;
  uint uVar7;
  char local_128;
  char local_127 [7];
  undefined4 local_120;
  void *local_11c;
  undefined1 auStack_118 [16];
  undefined2 auStack_108 [110];
  uint local_2c;
  
  local_2c = DAT_c0136c78;
  uVar6 = 0;
  bVar1 = false;
  bVar2 = false;
  local_120 = (HANDLE)0x0;
  local_11c = (void *)0x0;
  memset(auStack_118,0,0x10);
  DAT_c0137130 = LocalAlloc(0,0xfb0);
  _Dst = (HLOCAL)0x0;
  if (DAT_c0137130 == (HLOCAL)0x0) {
LAB_c012333c:
    FUN_c0122db4((ushort *)&local_120);
    if (DAT_c0137130 != (HLOCAL)0x0) {
      if (*(HANDLE *)((int)DAT_c0137130 + 4000) != (HANDLE)0xffffffff) {
        CloseHandle(*(HANDLE *)((int)DAT_c0137130 + 4000));
      }
      LocalFree(DAT_c0137130);
    }
    if (_Dst != (HLOCAL)0x0) {
      LocalFree(_Dst);
    }
    FUN_c013331c(local_2c);
    return;
  }
  pvVar4 = CreateFileW(L"\\windows\\initdb.ini",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                       (HANDLE)0x0);
  *(HANDLE *)((int)DAT_c0137130 + 4000) = pvVar4;
  if (*(int *)((int)DAT_c0137130 + 4000) == -1) goto LAB_c012333c;
  *(undefined4 *)((int)DAT_c0137130 + 0xfac) = 0;
  uVar7 = 0x14;
  *(undefined4 *)((int)DAT_c0137130 + 0xfa4) = 4000;
  local_120 = (HANDLE)CONCAT22(0x14,(ushort)local_120);
  _Dst = LocalAlloc(0,0x140);
  local_11c = _Dst;
  if (_Dst == (HLOCAL)0x0) goto LAB_c012333c;
  iVar5 = FUN_c01224fc(local_127);
  pvVar4 = local_120;
joined_r0xc0123124:
  if (iVar5 == 0) goto LAB_c012333c;
  if ((local_127[0] == '\n') || (local_127[0] == '\r')) {
    *(int *)((int)DAT_c0137130 + 0xfa4) = *(int *)((int)DAT_c0137130 + 0xfa4) + -1;
  }
  else {
    if (local_127[0] == 'D') {
      if (((!bVar1) && (iVar5 = FUN_c0122978(auStack_108), iVar5 != 0)) &&
         (pvVar4 = FUN_c0122e4c(auStack_118,(int)auStack_108), pvVar4 != (HANDLE)0xffffffff)) {
        bVar1 = true;
        goto LAB_c01232c8;
      }
      goto LAB_c012333c;
    }
    if (local_127[0] == 'R') {
      if ((bVar1) && (!bVar2)) {
        uVar6 = 0;
        local_120 = (HANDLE)((uint)local_120 & 0xffff0000);
        memset(_Dst,0,uVar7 << 4);
        bVar2 = true;
        goto LAB_c01232c8;
      }
      goto LAB_c012333c;
    }
    if (local_127[0] == 'F') {
      if (((bVar1) && (bVar2)) &&
         (bVar3 = FUN_c0122c24((ushort *)&local_120), _Dst = local_11c,
         CONCAT31(extraout_var,bVar3) != 0)) {
        uVar7 = (uint)local_120 >> 0x10;
        uVar6 = (uint)local_120 & 0xffff;
        goto LAB_c01232c8;
      }
      goto LAB_c012333c;
    }
    if (local_127[0] != 'E') {
      if ((local_127[0] != ' ') && (local_127[0] != '\t')) {
        if (local_127[0] == ';') goto LAB_c01232c8;
        goto LAB_c012333c;
      }
      goto LAB_c0123320;
    }
    if (bVar2) {
      iVar5 = CeWriteRecordProps(pvVar4,0,uVar6,_Dst);
      if (iVar5 != 0) {
        FUN_c0122db4((ushort *)&local_120);
        bVar2 = false;
        goto LAB_c01232c8;
      }
      goto LAB_c012333c;
    }
    if (bVar1) {
      CloseHandle(pvVar4);
      bVar1 = false;
    }
  }
LAB_c01232c8:
  do {
    iVar5 = FUN_c01224fc(&local_128);
    if ((iVar5 == 0) || (local_128 == '\n')) break;
  } while (local_128 != '\r');
  do {
    iVar5 = FUN_c01224fc(&local_128);
    if (iVar5 == 0) goto LAB_c0123320;
  } while ((local_128 == '\n') || (local_128 == '\r'));
  *(int *)((int)DAT_c0137130 + 0xfa4) = *(int *)((int)DAT_c0137130 + 0xfa4) + -1;
LAB_c0123320:
  iVar5 = FUN_c01224fc(local_127);
  goto joined_r0xc0123124;
}



/* c01233bc FUN_c01233bc */

/* Boundary evidence: original MIPS .pdata c01233bc..c012345b. Semantic name remains unreviewed. */

void FUN_c01233bc(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HRESULT HVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  size_t local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c0136c78;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  HVar1 = StringCchVPrintfW(awStack_218,0x104,param_1,(va_list)&local_res4);
  if ((-1 < HVar1) && (HVar1 = StringCchLengthW(awStack_218,0x104,local_220), -1 < HVar1)) {
    CeLogData(1,0x4a,awStack_218,(local_220[0] + 1) * 2 & 0xffff,0,0x40000000,0,0);
  }
  FUN_c013331c(local_10);
  return;
}



/* c012345c FUN_c012345c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c012345c..c01234d3. Semantic name remains unreviewed. */

void FUN_c012345c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (((_DAT_00005b68 & 0x20000000) != 0) &&
     (((DAT_c0136824 & 0x20000) != 0 || ((_DAT_00005b68 & 0x1000) != 0)))) {
    if (param_2 == 0) {
      uVar1 = 0x2d;
    }
    else {
      uVar1 = 0x2b;
    }
    FUN_c01233bc(L"%cResizeVol %s",uVar1,param_1,param_4);
  }
  return;
}



/* c01234d4 FUN_c01234d4 */

/* Boundary evidence: original MIPS .pdata c01234d4..c01235ff. Semantic name remains unreviewed. */

undefined4 FUN_c01234d4(undefined4 *param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((param_1 == &DAT_c01391e0) || (1 < param_3)) {
LAB_c0123508:
    uVar3 = 0;
  }
  else {
    piVar1 = (int *)param_1[0x86];
    if (piVar1 != (int *)0x0) {
      do {
        if (*piVar1 == param_2) break;
        piVar1 = (int *)piVar1[3];
      } while (piVar1 != (int *)0x0);
      if (piVar1 != (int *)0x0) {
        iVar2 = piVar1[param_3 + 1];
        if (iVar2 != -1) {
          piVar1[param_3 + 1] = iVar2 + 1;
          return 1;
        }
        SetLastError(0x216);
        goto LAB_c0123508;
      }
    }
    piVar1 = LocalAlloc(0x40,0x10);
    if (piVar1 == (int *)0x0) {
      SetLastError(0xe);
    }
    else {
      uVar3 = 1;
      *piVar1 = param_2;
      piVar1[param_3 + 1] = 1;
      piVar1[3] = param_1[0x86];
      param_1[0x86] = piVar1;
    }
  }
  return uVar3;
}



/* c0123600 FUN_c0123600 */

/* Boundary evidence: original MIPS .pdata c0123600..c0123643. Semantic name remains unreviewed. */

void FUN_c0123600(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = Random();
  *param_1 = uVar1;
  uVar1 = Random();
  param_1[1] = uVar1;
  uVar1 = Random();
  param_1[2] = uVar1;
  uVar1 = Random();
  param_1[3] = uVar1;
  *(undefined1 *)param_1 = 0;
  return;
}



/* c0123644 FUN_c0123644 */

undefined4 FUN_c0123644(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x20001) {
    uVar1 = 0x40000;
  }
  else if (param_1 < 0x40001) {
    uVar1 = 0x60000;
  }
  else if (param_1 < 0x60001) {
    uVar1 = 0x80000;
  }
  else if (param_1 < 0x80001) {
    uVar1 = 0xc0000;
  }
  else if (param_1 < 0x100001) {
    uVar1 = 0x200000;
  }
  else if (param_1 < 0x300001) {
    uVar1 = 0x400000;
  }
  else {
    uVar1 = 0x800000;
    if (0x700000 < param_1) {
      uVar1 = 0x1000000;
    }
  }
  return uVar1;
}



/* c012370c FUN_c012370c */

/* Boundary evidence: original MIPS .pdata c012370c..c012385b. Semantic name remains unreviewed. */

undefined4
FUN_c012370c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_280 [620];
  uint local_14;
  
  local_14 = DAT_c0136c78;
  if ((param_1[0x8a] != -1) && ((uint)param_1[0x94] < 0x1000000)) {
    FUN_c012345c(param_1 + 4,1,param_3,param_4);
    BVar1 = FlushViewOfFile((LPCVOID)param_1[2],param_1[0x8d] - (int)param_1[2]);
    if (BVar1 != 0) {
      memcpy(auStack_280,param_1,0x26c);
      param_1[0x94] = 0;
      param_1[0x90] = 0;
      param_1[0x8b] = 0;
      param_1[2] = 0;
      param_1[0x8e] = 0;
      param_1[0x91] = 0;
      param_1[0x8d] = 0;
      param_1[0x8c] = 0;
      iVar2 = FUN_c0102258(param_1,0,0);
      if (iVar2 != 0) {
        FUN_c0103338((int)param_1);
        iVar2 = FUN_c0104764(param_1);
        uVar3 = 1;
        if (iVar2 != 0) {
          FUN_c0102694((int)auStack_280,0,1,param_4);
          FUN_c012345c(param_1 + 4,0,uVar3,param_4);
          FUN_c013331c(local_14);
          return 1;
        }
        FUN_c0102694((int)param_1,0,1,param_4);
      }
      memcpy(param_1,auStack_280,0x26c);
    }
  }
  FUN_c013331c(local_14);
  return 0;
}



/* c012385c FUN_c012385c */

/* Boundary evidence: original MIPS .pdata c012385c..c0123ad3. Semantic name remains unreviewed. */

undefined4 FUN_c012385c(int param_1,int param_2)

{
  int iVar1;
  BOOL BVar2;
  uint *puVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  int local_30;
  uint local_2c;
  uint local_28 [2];
  uint local_20;
  uint local_1c;
  
  local_28[0] = param_2 - 0xcU | 1;
  if (*(int *)(param_1 + 0x228) == -1) {
    if ((*(ushort *)(param_1 + 0x24e) & 0x40) == 0) {
      uVar6 = *(int *)(param_1 + 0x240) + 0x5000;
      local_2c = uVar6 + param_2;
      *(uint *)(*(int *)(param_1 + 8) + 0x20) = local_2c;
LAB_c0123a50:
      *(uint *)(*(int *)(param_1 + 8) + 0x20) = local_2c;
      *(uint *)(*(int *)(param_1 + 0x230) + uVar6 + -0x5000) = local_28[0];
      *(int *)(param_1 + 0x234) = *(int *)(param_1 + 0x234) + param_2;
      *(int *)(param_1 + 0x240) = *(int *)(param_1 + 0x240) + param_2;
      *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + param_2 + -0xc;
      FUN_c0102024(param_1,(uint *)(*(int *)(param_1 + 0x230) + uVar6 + -0x5000));
      return 1;
    }
  }
  else {
    piVar5 = &local_30;
    uVar4 = 8;
    puVar3 = &local_20;
    iVar1 = ReadFileWithSeek();
    if ((((iVar1 != 0) && (local_30 == 8)) && (local_20 < 3)) && (local_1c != 0)) {
      uVar6 = local_1c;
      if (local_20 != 0) {
        FUN_c0101bb0(param_1 + 0x10,puVar3,uVar4,piVar5);
        BVar2 = FlushViewOfFile(*(LPCVOID *)(param_1 + 8),
                                *(int *)(param_1 + 0x234) - (int)*(LPCVOID *)(param_1 + 8));
        uVar6 = local_1c;
        if (BVar2 == 0) {
          return 0;
        }
      }
      local_2c = uVar6 + param_2;
      if ((uVar6 <= local_2c) && (local_2c <= *(uint *)(param_1 + 0x250))) {
        SetFilePointer(*(HANDLE *)(param_1 + 0x228),local_2c,(PLONG)0x0,0);
        BVar2 = SetEndOfFile(*(HANDLE *)(param_1 + 0x228));
        if ((((BVar2 != 0) &&
             ((BVar2 = FlushFileBuffers(*(HANDLE *)(param_1 + 0x228)), BVar2 != 0 &&
              (iVar1 = WriteFileWithSeek(*(undefined4 *)(param_1 + 0x228),local_28,4,&local_30,0,
                                         uVar6,0), iVar1 != 0)))) &&
            ((local_30 == 4 &&
             (((BVar2 = FlushFileBuffers(*(HANDLE *)(param_1 + 0x228)), BVar2 != 0 &&
               (iVar1 = WriteFileWithSeek(*(undefined4 *)(param_1 + 0x228),&local_2c,4,&local_30,0,
                                          0x20,0), iVar1 != 0)) && (local_30 == 4)))))) &&
           (BVar2 = FlushFileBuffers(*(HANDLE *)(param_1 + 0x228)), BVar2 != 0)) goto LAB_c0123a50;
      }
    }
  }
  return 0;
}



/* c0123ad4 FUN_c0123ad4 */

/* Boundary evidence: original MIPS .pdata c0123ad4..c0123b2f. Semantic name remains unreviewed. */

undefined4
FUN_c0123ad4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((uint)param_1[0x8f] < 0x2008) && ((uint)param_1[0x94] <= param_1[0x90] + 0xb000)) &&
     (iVar1 = FUN_c012370c(param_1,param_2,param_3,param_4), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c0123b30 FUN_c0123b30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0123b30..c0123f17. Semantic name remains unreviewed. */

undefined4 FUN_c0123b30(LPCWSTR param_1)

{
  HANDLE hFile;
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  int local_128;
  undefined1 auStack_124 [4];
  int local_120;
  int local_10c;
  uint local_108;
  int local_40;
  uint local_30 [2];
  
  local_128 = 0;
  memset(auStack_124,0,0xf8);
  uVar6 = 0;
  hFile = CreateFileW(param_1,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    iVar1 = ReadFileWithSeek(hFile,&local_128,0xfc,&local_138,0,0,0);
    if ((((iVar1 == 0) || (local_138 != 0xfc)) || (local_128 != 0x400)) || (local_120 != 0x4d494b45)
       ) goto LAB_c0123ed0;
    if ((((local_30[0] & 0x10) != 0) && (local_10c == 0)) && (local_40 == 0)) {
      uVar5 = 0x5000;
      do {
        uVar4 = uVar5;
        iVar1 = ReadFileWithSeek(hFile,&local_12c,4,&local_138,0,uVar4,0);
        if ((iVar1 == 0) || (local_138 != 4)) goto LAB_c0123ed0;
        local_130 = (local_12c & 0xffffffc) + 0xc;
        uVar5 = local_130 + uVar4;
      } while (uVar5 < local_108);
      if (uVar5 != local_108) goto LAB_c0123ed0;
      if ((local_12c & 1) != 0) {
        local_134 = (_DAT_00005b04 + uVar4) - 1 & ~(_DAT_00005b04 - 1U);
        if ((local_134 < uVar4 + 0xc) && (uVar4 < uVar4 + 0xc)) {
          local_134 = _DAT_00005b04 + local_134;
        }
        if ((local_134 + 0xc < local_108) && (local_134 < local_134 + 0xc)) {
          local_130 = (local_108 - local_134) - 0xc | 1;
          iVar1 = WriteFileWithSeek(hFile,&local_130,4,&local_138,0,local_134,0);
          if ((iVar1 == 0) || ((local_138 != 4 || (BVar2 = FlushFileBuffers(hFile), BVar2 == 0))))
          goto LAB_c0123ed0;
          local_130 = (local_134 - uVar4) - 0xc | 1;
          iVar1 = WriteFileWithSeek(hFile,&local_130,4,&local_138,0,uVar4,0);
          if ((iVar1 == 0) || ((local_138 != 4 || (BVar2 = FlushFileBuffers(hFile), BVar2 == 0))))
          goto LAB_c0123ed0;
          iVar1 = WriteFileWithSeek(hFile,&local_134,4,&local_138,0,0x20,0);
          if (((iVar1 == 0) ||
              (((local_138 != 4 || (BVar2 = FlushFileBuffers(hFile), BVar2 == 0)) ||
               (DVar3 = SetFilePointer(hFile,local_134,(PLONG)0x0,0), DVar3 == 0xffffffff)))) ||
             ((BVar2 = SetEndOfFile(hFile), BVar2 == 0 ||
              (BVar2 = FlushFileBuffers(hFile), BVar2 == 0)))) goto LAB_c0123ed0;
        }
      }
      local_30[0] = local_30[0] & 0xffffffef;
      iVar1 = WriteFileWithSeek(hFile,local_30,4,&local_138,0,0xf8,0);
      if ((iVar1 == 0) || ((local_138 != 4 || (BVar2 = FlushFileBuffers(hFile), BVar2 == 0))))
      goto LAB_c0123ed0;
    }
  }
  uVar6 = 1;
LAB_c0123ed0:
  if (hFile != (HANDLE)0xffffffff) {
    CloseHandle(hFile);
  }
  return uVar6;
}



/* c0123f18 FUN_c0123f18 */

/* Boundary evidence: original MIPS .pdata c0123f18..c0123fc3. Semantic name remains unreviewed. */

void FUN_c0123f18(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = &DAT_c01391e0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  iVar1 = DAT_c01391e0;
  if ((*(ushort *)(param_1 + 0x24e) & 2) == 0) {
    if (DAT_c01391e4 != 0) {
      piVar2 = &DAT_c01391e4;
      do {
        piVar3 = (int *)*piVar2;
        piVar2 = piVar3 + 1;
      } while (*piVar2 != 0);
    }
    piVar3[1] = param_1;
  }
  else {
    while (iVar1 != 0) {
      piVar3 = (int *)*piVar3;
      iVar1 = *piVar3;
    }
    *piVar3 = param_1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return;
}



/* c0123fc4 FUN_c0123fc4 */

/* Boundary evidence: original MIPS .pdata c0123fc4..c0124093. Semantic name remains unreviewed. */

void FUN_c0123fc4(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  piVar2 = &DAT_c01391e0;
  if ((*(ushort *)((int)param_1 + 0x24e) & 2) == 0) {
    do {
      piVar1 = piVar2;
      if (piVar1[1] == 0) break;
      piVar2 = (int *)piVar1[1];
    } while ((int *)piVar1[1] != param_1);
    if (piVar1[1] != 0) {
      piVar1[1] = param_1[1];
    }
  }
  else if (DAT_c01391e0 != 0) {
    do {
      piVar1 = (int *)*piVar2;
      if (piVar1 == param_1) break;
      piVar2 = piVar1;
    } while (*piVar1 != 0);
    if (*piVar2 != 0) {
      *piVar2 = *param_1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return;
}



/* c0124094 FUN_c0124094 */

/* Boundary evidence: original MIPS .pdata c0124094..c01241b7. Semantic name remains unreviewed. */

undefined4 * FUN_c0124094(int *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((param_1 == (int *)0x0) ||
     (((param_1[3] == 0 && param_1[2] == 0) && param_1[1] == 0) && *param_1 == 0)) {
    puVar3 = (undefined4 *)PTR_DAT_c0136c70;
    if ((param_2 & 2) == 0) {
      puVar3 = &DAT_c01391e0;
    }
  }
  else {
    puVar3 = DAT_c01391e4;
    puVar1 = DAT_c01391e0;
    if ((param_2 & 2) == 0) {
      while ((puVar3 != (undefined4 *)0x0 &&
             (iVar2 = memcmp(puVar3 + 0x97,param_1,0x10), iVar2 != 0))) {
        puVar3 = (undefined4 *)puVar3[1];
      }
    }
    else {
      while ((puVar3 = puVar1, puVar1 != (undefined4 *)0x0 &&
             (iVar2 = memcmp(puVar1 + 0x97,param_1,0x10), iVar2 != 0))) {
        puVar1 = (undefined4 *)*puVar1;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return puVar3;
}



/* c01241b8 FUN_c01241b8 */

/* Boundary evidence: original MIPS .pdata c01241b8..c012421f. Semantic name remains unreviewed. */

undefined4 FUN_c01241b8(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  if ((param_2 & 2) == 0) {
    uVar1 = param_1[1];
  }
  else {
    uVar1 = *param_1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  return uVar1;
}



/* c0124220 FUN_c0124220 */

/* Boundary evidence: original MIPS .pdata c0124220..c012430b. Semantic name remains unreviewed. */

BOOL FUN_c0124220(int *param_1,int param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  BOOL BVar2;
  DWORD dwErrCode;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == (int *)0x0) {
LAB_c01242d0:
    SetLastError(0x57);
  }
  else {
    uVar3 = (uint)*(ushort *)(param_2 + 4);
    piVar4 = param_3;
    puVar1 = FUN_c0124094(param_1,uVar3);
    if (puVar1 == (undefined4 *)0x0) goto LAB_c01242d0;
    if (puVar1 != &DAT_c01391e0) {
      if ((*(ushort *)((int)puVar1 + 0x24e) & 8) == 0) {
        FUN_c0101bb0(puVar1 + 4,uVar3,piVar4,param_4);
        BVar2 = FlushViewOfFile((LPCVOID)puVar1[2],puVar1[0x8d] - (int)puVar1[2]);
        iVar6 = *param_3;
        iVar5 = puVar1[0x95];
        *param_3 = iVar6 - iVar5;
        if (iVar6 - iVar5 < 0) {
          *param_3 = 0;
        }
        puVar1[0x95] = 0;
        return BVar2;
      }
      dwErrCode = 0x32;
      goto LAB_c01242e4;
    }
  }
  dwErrCode = 0x57;
LAB_c01242e4:
  SetLastError(dwErrCode);
  return 0;
}



/* c012430c FUN_c012430c */

/* Boundary evidence: original MIPS .pdata c012430c..c01244b7. Semantic name remains unreviewed. */

undefined4 FUN_c012430c(uint *param_1,wchar_t *param_2,uint param_3,int param_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  size_t sVar3;
  DWORD dwErrCode;
  int _Val;
  
  if ((param_1[3] & param_1[2] & param_1[1] & *param_1) == 0xffffffff) {
    puVar2 = (undefined4 *)PTR_DAT_c0136c70;
    if ((*(ushort *)(param_4 + 4) & 2) == 0) {
      puVar2 = &DAT_c01391e0;
    }
  }
  else {
    puVar2 = FUN_c0124094((int *)param_1,(uint)*(ushort *)(param_4 + 4));
    if (puVar2 == (undefined4 *)0x0) {
      SetLastError(0x57);
      dwErrCode = 0x57;
LAB_c01243c4:
      SetLastError(dwErrCode);
      return 0;
    }
    puVar2 = (undefined4 *)FUN_c01241b8(puVar2,(uint)*(ushort *)(param_4 + 4));
    if (puVar2 == (undefined4 *)0x0) {
      dwErrCode = 0x103;
      goto LAB_c01243c4;
    }
  }
  puVar1 = PTR_DAT_c0136c70;
  if (param_2 == (wchar_t *)0x0) {
LAB_c0124478:
    SetLastError(0x7a);
    return 0;
  }
  sVar3 = wcslen((wchar_t *)(puVar2 + 4));
  if (param_3 <= sVar3) goto LAB_c0124478;
  if (puVar2 == (undefined4 *)0x0) {
    _Val = -1;
  }
  else {
    if ((puVar2 != &DAT_c01391e0) && (puVar2 != (undefined4 *)puVar1)) {
      memcpy(param_1,(void *)(puVar2[2] + 0xc),0x10);
      goto LAB_c0124464;
    }
    _Val = 0;
  }
  memset(param_1,_Val,0x10);
LAB_c0124464:
  wcscpy(param_2,(wchar_t *)(puVar2 + 4));
  return 1;
}



/* c01244b8 FUN_c01244b8 */

/* Boundary evidence: original MIPS .pdata c01244b8..c012465f. Semantic name remains unreviewed. */

undefined4 FUN_c01244b8(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  uVar5 = 1;
  FUN_c0123fc4(param_1);
  if (param_1[0x88] != 0) {
    uVar3 = 0;
    if (*(int *)(param_2 + 0x10) != 0) {
      piVar2 = (int *)(param_2 + 0x14);
      do {
        if (*piVar2 == param_1[0x88]) break;
        uVar3 = uVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar3 < *(uint *)(param_2 + 0x10));
    }
    if (uVar3 < *(int *)(param_2 + 0x10) - 1U) {
      puVar4 = (undefined4 *)((uVar3 + 5) * 4 + param_2);
      do {
        uVar3 = uVar3 + 1;
        *puVar4 = puVar4[1];
        puVar4 = puVar4 + 1;
      } while (uVar3 < *(int *)(param_2 + 0x10) - 1U);
    }
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + -1;
    EventModify(param_1[0x88],3);
    CloseHandle((HANDLE)param_1[0x88]);
  }
  FUN_c011ff2c((int)param_1);
  if (param_1[0x8b] == -1) {
    if ((HANDLE)param_1[0x8a] == (HANDLE)0xffffffff) {
      if (((*(ushort *)((int)param_1 + 0x24e) & 0x40) != 0) && ((LPVOID)param_1[2] != (LPVOID)0x0))
      {
        VirtualFree((LPVOID)param_1[2],param_1[0x90] + 0x5000,0x4000);
        VirtualFree((LPVOID)param_1[2],0,0x8000);
      }
    }
    else {
      CloseHandle((HANDLE)param_1[0x8a]);
    }
  }
  else {
    iVar1 = FUN_c0102694((int)param_1,1,1,param_4);
    if (iVar1 != 2) {
      uVar5 = 0;
    }
  }
  LocalFree(param_1);
  if (*(int *)(param_2 + 0x10) == 0) {
    LocalFree(*(HLOCAL *)(param_2 + 0xc));
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  return uVar5;
}



/* c0124660 FUN_c0124660 */

/* Boundary evidence: original MIPS .pdata c0124660..c0124983. Semantic name remains unreviewed. */

void FUN_c0124660(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  code **ppcVar9;
  undefined4 uVar10;
  
  bVar1 = false;
  uVar10 = 0;
  puVar7 = (undefined4 *)0x0;
  puVar8 = (undefined4 *)0x0;
  ppcVar9 = &WaitForMultipleObjects_exref;
  do {
    Sleep(0);
    if (puVar7 == (undefined4 *)0x0) {
      uVar6 = 0x100;
      if ((uint)param_1[4] < 0x101) {
        uVar6 = param_1[4];
      }
      param_4 = 0xffffffff;
      param_3 = 0;
      iVar2 = (**ppcVar9)(uVar6,param_1 + 5,0,0xffffffff,puVar8,ppcVar9,uVar10);
      if (iVar2 != 0) goto LAB_c012472c;
    }
    else {
LAB_c012472c:
      EnterCriticalSection((LPCRITICAL_SECTION)*param_1);
      if (puVar7 == (undefined4 *)0x0) {
LAB_c0124790:
        puVar7 = (undefined4 *)FUN_c01241b8(&DAT_c01391e0,(uint)*(ushort *)(param_1 + 1));
        puVar8 = puVar7;
        if (puVar7 != (undefined4 *)0x0) {
          do {
            DVar4 = WaitForSingleObject((HANDLE)puVar7[0x88],0);
            if (DVar4 != 0x102) break;
            puVar7 = (undefined4 *)FUN_c01241b8(puVar7,(uint)*(ushort *)(param_1 + 1));
          } while (puVar7 != (undefined4 *)0x0);
          puVar8 = puVar7;
          if (puVar7 != (undefined4 *)0x0) goto LAB_c01247f4;
        }
      }
      else {
        puVar3 = (undefined4 *)FUN_c01241b8(&DAT_c01391e0,(uint)*(ushort *)(param_1 + 1));
        if (puVar3 == (undefined4 *)0x0) {
LAB_c0124780:
          puVar7 = (undefined4 *)0x0;
          puVar8 = (undefined4 *)0x0;
        }
        else {
          do {
            if (puVar3 == puVar7) break;
            puVar3 = (undefined4 *)FUN_c01241b8(puVar3,(uint)*(ushort *)(param_1 + 1));
          } while (puVar3 != (undefined4 *)0x0);
          if (puVar3 == (undefined4 *)0x0) goto LAB_c0124780;
        }
        if (puVar7 == (undefined4 *)0x0) goto LAB_c0124790;
LAB_c01247f4:
        DVar4 = WaitForSingleObject((HANDLE)puVar7[0x88],0);
        if (DVar4 == 0x102) {
          if (puVar7 != (undefined4 *)0x0) {
            puVar7 = (undefined4 *)0x0;
            puVar8 = (undefined4 *)0x0;
          }
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)puVar7[0x87]);
          uVar6 = 1;
          FUN_c00fc484(puVar7 + 4,1,param_3,param_4);
          do {
            uVar5 = FUN_c0123644(puVar7[0x90]);
            if (((uint)puVar7[0x94] < uVar5) && ((*(ushort *)((int)puVar7 + 0x24e) & 0x40) == 0)) {
              FUN_c012370c(puVar7,uVar6,param_3,param_4);
            }
            iVar2 = FUN_c0104344(puVar7);
          } while ((iVar2 == 0) && ((uint)puVar7[0x8f] < 0xc001));
          FUN_c00fc484(puVar7 + 4,0,param_3,param_4);
          LeaveCriticalSection((LPCRITICAL_SECTION)puVar7[0x87]);
        }
      }
      if (param_1[4] == 0) {
        CloseHandle((HANDLE)param_1[2]);
        param_1[2] = 0;
        bVar1 = true;
        uVar10 = 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    }
    if (bVar1) {
      return;
    }
  } while( true );
}



/* c0124984 FUN_c0124984 */

/* Boundary evidence: original MIPS .pdata c0124984..c012498f. Semantic name remains unreviewed. */

undefined4 FUN_c0124984(void)

{
  return 1;
}



/* c0124990 FUN_c0124990 */

/* Boundary evidence: original MIPS .pdata c0124990..c0124b8b. Semantic name remains unreviewed. */

uint FUN_c0124990(int *param_1,uint param_2,short *param_3,int param_4)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int aiStack_30 [4];
  
  uVar3 = 0;
  if (*param_3 != 1) {
    SetLastError(0x57);
    return 0;
  }
  uVar1 = *(ushort *)(param_4 + 4);
  if (uVar1 == 2) {
    if (param_1 == (int *)0x0) {
      memset(aiStack_30,0,0x10);
      param_1 = aiStack_30;
      goto LAB_c0124a24;
    }
LAB_c0124a2c:
    puVar2 = FUN_c0124094(param_1,(uint)uVar1);
    if ((puVar2 != (undefined4 *)0x0) &&
       ((param_2 == 0 ||
        (((param_2 >> 0x1c != 0 || (puVar2 == &DAT_c01391e0)) &&
         ((param_2 >> 0x1c != 3 || (puVar2 != &DAT_c01391e0)))))))) goto LAB_c0124ac0;
  }
  else {
LAB_c0124a24:
    if (param_1 != (int *)0x0) goto LAB_c0124a2c;
  }
  SetLastError(0x57);
  puVar2 = (undefined4 *)0x0;
LAB_c0124ac0:
  if (puVar2 == (undefined4 *)0x0) {
    SetLastError(0x57);
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
    uVar3 = FUN_c0103434((int)puVar2,param_2,(int)param_3);
    LeaveCriticalSection((LPCRITICAL_SECTION)puVar2[0x87]);
  }
  return uVar3;
}



/* c0124b8c FUN_c0124b8c */

/* Boundary evidence: original MIPS .pdata c0124b8c..c0124b97. Semantic name remains unreviewed. */

undefined4 FUN_c0124b8c(void)

{
  return 1;
}



/* c0124b98 FUN_c0124b98 */

/* Boundary evidence: original MIPS .pdata c0124b98..c0124ba3. Semantic name remains unreviewed. */

undefined4 FUN_c0124b98(void)

{
  return 1;
}



/* c0124ba4 FUN_c0124ba4 */

/* Boundary evidence: original MIPS .pdata c0124ba4..c0124cd3. Semantic name remains unreviewed. */

void FUN_c0124ba4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *hMem;
  int *piVar5;
  int *piVar6;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
  piVar6 = *(int **)PTR_DAT_c0136c70;
  do {
    do {
      piVar1 = piVar6;
      if (piVar1 == (int *)0x0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c013a740);
        return;
      }
      piVar6 = (int *)*piVar1;
      hMem = (int *)piVar1[0x86];
      piVar5 = (int *)0x0;
    } while ((int *)piVar1[0x86] == (int *)0x0);
    do {
      piVar3 = hMem;
      hMem = piVar3;
      if (*piVar3 == param_1) break;
      hMem = (int *)piVar3[3];
      piVar5 = piVar3;
    } while (hMem != (int *)0x0);
    if ((hMem != (int *)0x0) && (piVar3 = hMem + 1, *piVar3 != 0)) {
      uVar4 = 8;
      *piVar3 = 0;
      iVar2 = memcmp(&DAT_c00f45a0,piVar3,8);
      if (iVar2 == 0) {
        if (piVar5 == (int *)0x0) {
          piVar1[0x86] = hMem[3];
        }
        else {
          piVar5[3] = hMem[3];
        }
        LocalFree(hMem);
      }
      if (piVar1[0x86] == 0) {
        FUN_c01244b8(piVar1,param_2,uVar4,param_4);
      }
    }
  } while( true );
}



/* c0124cd4 FUN_c0124cd4 */

/* Boundary evidence: original MIPS .pdata c0124cd4..c0124e1b. Semantic name remains unreviewed. */

undefined4 FUN_c0124cd4(int *param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *hMem;
  int *piVar5;
  
  if ((param_1 != &DAT_c01391e0) && (param_3 < 2)) {
    hMem = (int *)param_1[0x86];
    piVar5 = (int *)0x0;
    if ((int *)param_1[0x86] != (int *)0x0) {
      do {
        piVar4 = hMem;
        hMem = piVar4;
        if (*piVar4 == param_2) break;
        hMem = (int *)piVar4[3];
        piVar5 = piVar4;
      } while (hMem != (int *)0x0);
      if (hMem != (int *)0x0) {
        iVar3 = hMem[param_3 + 1];
        if (iVar3 == 0) {
          SetLastError(5);
          return 0;
        }
        uVar2 = 8;
        hMem[param_3 + 1] = iVar3 + -1;
        iVar3 = param_4;
        iVar1 = memcmp(&DAT_c00f45a0,hMem + 1,8);
        if (iVar1 == 0) {
          if (piVar5 == (int *)0x0) {
            param_1[0x86] = hMem[3];
          }
          else {
            piVar5[3] = hMem[3];
          }
          LocalFree(hMem);
          if (param_1[0x86] != 0) {
            return 1;
          }
          uVar2 = FUN_c01244b8(param_1,param_4,uVar2,iVar3);
          return uVar2;
        }
        return 1;
      }
    }
    SetLastError(5);
  }
  return 0;
}



/* c0124e1c FUN_c0124e1c */

/* Boundary evidence: original MIPS .pdata c0124e1c..c0124ecb. Semantic name remains unreviewed. */

undefined4 FUN_c0124e1c(LPVOID param_1)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(int *)((int)param_1 + 0x10) == 0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)param_1 + 0x14) = pvVar1;
    if (*(int *)((int)param_1 + 0x14) != 0) {
      *(undefined4 *)((int)param_1 + 0x10) = 1;
      pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0124660,param_1,0,(LPDWORD)0x0);
      *(HANDLE *)((int)param_1 + 8) = pvVar1;
      if (pvVar1 != (HANDLE)0x0) {
        return 1;
      }
      CloseHandle(*(HANDLE *)((int)param_1 + 0x14));
      *(undefined4 *)((int)param_1 + 0x14) = 0;
      *(undefined4 *)((int)param_1 + 0x10) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* c0124ecc FUN_c0124ecc */

/* Boundary evidence: original MIPS .pdata c0124ecc..c0124f7b. Semantic name remains unreviewed. */

undefined4 FUN_c0124ecc(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((param_1 == (int *)0x0) ||
     (piVar1 = FUN_c0124094(param_1,(uint)*(ushort *)(param_2 + 4)), piVar1 == (int *)0x0)) {
    SetLastError(0x57);
  }
  else if ((piVar1 != &DAT_c01391e0) && (piVar1 != (int *)PTR_DAT_c0136c70)) {
    uVar2 = FUN_c0124cd4(piVar1,param_3,0,param_2);
    return uVar2;
  }
  SetLastError(0x57);
  return 0;
}



/* c0124f7c FUN_c0124f7c */

/* Boundary evidence: original MIPS .pdata c0124f7c..c0125b1b. Semantic name remains unreviewed. */

int * FUN_c0124f7c(LPCWSTR param_1,DWORD param_2,DWORD param_3,LPDWORD param_4,int *param_5,
                  uint param_6)

{
  WCHAR WVar1;
  int *piVar2;
  HANDLE pvVar3;
  HLOCAL pvVar4;
  int iVar5;
  LCID LVar6;
  undefined4 *puVar7;
  BOOL BVar8;
  DWORD DVar9;
  LPDWORD lpNumberOfBytesWritten;
  WCHAR *pWVar10;
  uint uVar11;
  DWORD DVar12;
  DWORD local_54;
  DWORD local_50;
  DWORD local_4c;
  DWORD local_48;
  int *local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  
  local_44 = (int *)0x0;
  local_54 = 0;
  local_40 = 0;
  DVar9 = param_3;
  lpNumberOfBytesWritten = param_4;
  local_48 = param_2;
  piVar2 = LocalAlloc(0x40,0x26c);
  local_44 = piVar2;
  if (piVar2 == (int *)0x0) {
    SetLastError(8);
    goto LAB_c0125ab8;
  }
  piVar2[0x8b] = -1;
  piVar2[0x8a] = -1;
  if (((uint)param_4 & 8) == 0) {
    local_3c = (uint)param_4 & 0x20;
    if (local_3c == 0) {
      DVar12 = 0xc0000000;
    }
    else {
      DVar12 = 0x80000000;
    }
    if (((param_3 == 3) || (param_3 == 4)) && (local_3c == 0)) {
      FUN_c0123b30(param_1);
    }
    lpNumberOfBytesWritten = (LPDWORD)0x0;
    DVar9 = 0;
    pvVar3 = CreateFileW(param_1,DVar12,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x90000000,(HANDLE)0x0);
    piVar2[0x8a] = (int)pvVar3;
    if (pvVar3 == (HANDLE)0xffffffff) {
      if ((param_3 == 3) || (param_3 == 5)) {
        SetLastError(2);
        goto LAB_c0125ab8;
      }
    }
    else {
      local_54 = 0xb7;
      local_40 = 0xb7;
      if ((param_3 == 3) || (param_3 == 4)) {
        lpNumberOfBytesWritten = &local_50;
        DVar9 = 4;
        iVar5 = ReadFileWithSeek(piVar2[0x8a],&local_4c,4,lpNumberOfBytesWritten,0,8,0);
        if ((iVar5 == 0) || ((local_50 != 4 || (local_4c != 0x4d494b45)))) {
          SetLastError(5);
          goto LAB_c0125ab8;
        }
        if (((uint)param_4 & 2) != 0) {
          lpNumberOfBytesWritten = &local_50;
          DVar9 = 4;
          iVar5 = ReadFileWithSeek(piVar2[0x8a],&local_4c,4,lpNumberOfBytesWritten,0,0xec,0);
          if (((iVar5 == 0) || (local_50 != 4)) || (local_4c == 0xffffffff)) {
            SetLastError(5);
            goto LAB_c0125ab8;
          }
        }
        if (((uint)param_4 & 4) != 0) {
          lpNumberOfBytesWritten = &local_50;
          DVar9 = 4;
          iVar5 = ReadFileWithSeek(piVar2[0x8a],&local_4c,4,lpNumberOfBytesWritten,0,0xf0,0);
          if (((iVar5 == 0) || (local_50 != 4)) || (local_4c == 0xffffffff)) {
            SetLastError(5);
            goto LAB_c0125ab8;
          }
        }
      }
    }
    if ((((param_3 == 2) || (param_3 == 5)) || (piVar2[0x8a] == -1)) && (param_1 != (LPCWSTR)0x0)) {
      if (local_3c != 0) {
        SetLastError(0x57);
        goto LAB_c0125ab8;
      }
      if (param_6 < 0x7001) {
        param_6 = 0x7000;
      }
      if ((HANDLE)piVar2[0x8a] != (HANDLE)0xffffffff) {
        CloseHandle((HANDLE)piVar2[0x8a]);
      }
      uVar11 = 6;
      if (((uint)param_4 & 0x84) == 0) {
        uVar11 = 0x80;
      }
      lpNumberOfBytesWritten = (LPDWORD)0x0;
      DVar9 = 0;
      pvVar3 = CreateFileW(param_1,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,uVar11 | 0x90000000,
                           (HANDLE)0x0);
      piVar2[0x8a] = (int)pvVar3;
      if (pvVar3 == (HANDLE)0xffffffff) goto LAB_c0125ab8;
      local_38 = 0;
      local_30 = 0;
      local_34 = param_6;
      SetFilePointer((HANDLE)piVar2[0x8a],0x1c,(PLONG)0x0,0);
      lpNumberOfBytesWritten = &local_4c;
      DVar9 = 0xc;
      BVar8 = WriteFile((HANDLE)piVar2[0x8a],&local_38,0xc,lpNumberOfBytesWritten,(LPOVERLAPPED)0x0)
      ;
      if ((BVar8 == 0) || (local_4c != 0xc)) goto LAB_c0125ab8;
      lpNumberOfBytesWritten = (LPDWORD)0x0;
      DVar9 = 0;
      SetFilePointer((HANDLE)piVar2[0x8a],param_6,(PLONG)0x0,0);
      SetEndOfFile((HANDLE)piVar2[0x8a]);
      BVar8 = FlushFileBuffers((HANDLE)piVar2[0x8a]);
      if (BVar8 == 0) goto LAB_c0125ab8;
      DVar12 = GetFileSize((HANDLE)piVar2[0x8a],(LPDWORD)0x0);
      if (DVar12 < param_6) {
        SetLastError(0x70);
        goto LAB_c0125ab8;
      }
      local_38 = 0x400;
      local_34 = 0;
      local_30 = 0;
      SetFilePointer((HANDLE)piVar2[0x8a],0,(PLONG)0x0,0);
      lpNumberOfBytesWritten = &local_4c;
      DVar9 = 0xc;
      BVar8 = WriteFile((HANDLE)piVar2[0x8a],&local_38,0xc,lpNumberOfBytesWritten,(LPOVERLAPPED)0x0)
      ;
      if (((BVar8 == 0) || (local_4c != 0xc)) ||
         (BVar8 = FlushFileBuffers((HANDLE)piVar2[0x8a]), BVar8 == 0)) goto LAB_c0125ab8;
    }
    else if (param_3 == 1) {
      SetLastError(0xb7);
      goto LAB_c0125ab8;
    }
  }
  else if (param_1 == (LPCWSTR)0x0) {
    piVar2[0x8a] = -1;
  }
  else {
    lpNumberOfBytesWritten = (LPDWORD)0x0;
    DVar9 = 0;
    pvVar3 = CreateFileW(param_1,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,param_3,0x80,(HANDLE)0x0);
    piVar2[0x8a] = (int)pvVar3;
    if (pvVar3 == (HANDLE)0xffffffff) goto LAB_c0125ab8;
  }
  if (param_5[3] == 0) {
    pvVar4 = LocalAlloc(0,0x1000);
    param_5[3] = (int)pvVar4;
    if (pvVar4 == (HLOCAL)0x0) {
      SetLastError(8);
      goto LAB_c0125ab8;
    }
  }
  piVar2[0x89] = param_5[3];
  *(short *)((int)piVar2 + 0x24e) = (short)param_4;
  piVar2[3] = 3;
  piVar2[0x87] = *param_5;
  if (param_1 == (LPCWSTR)0x0) {
    if (local_48 == 0) {
      *(undefined2 *)(piVar2 + 4) = 0;
    }
    else {
      StringCchCopyW((STRSAFE_LPWSTR)(piVar2 + 4),0x104,L"Hive RAM Region");
    }
  }
  else {
    pWVar10 = (WCHAR *)(piVar2 + 4);
    iVar5 = 0x104;
    do {
      if (iVar5 == 0) break;
      WVar1 = *param_1;
      *pWVar10 = WVar1;
      pWVar10 = pWVar10 + 1;
      param_1 = param_1 + 1;
      iVar5 = iVar5 + -1;
    } while (WVar1 != L'\0');
    pWVar10[-1] = L'\0';
  }
  lpNumberOfBytesWritten = (LPDWORD)0x0;
  DVar9 = 0;
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  piVar2[0x88] = (int)pvVar3;
  if (pvVar3 == (HANDLE)0x0) {
    SetLastError(8);
  }
  else {
    param_5[param_5[4] + 5] = (int)pvVar3;
    param_5[4] = param_5[4] + 1;
    EventModify(param_5[5],1);
    uVar11 = (uint)param_4 & 0xffff;
    DVar9 = local_48;
    iVar5 = FUN_c0102258(piVar2,(uint)param_4 & 0x68,local_48);
    if (iVar5 == 0) goto LAB_c0125ab8;
    if (local_48 != 0) {
      if (*(int *)(piVar2[2] + 8) == 0x4d494b45) {
        if (((param_3 == 1) || (param_3 == 5)) || (param_3 == 2)) {
          *(undefined4 *)(piVar2[2] + 4) = 0;
          *(undefined4 *)(piVar2[2] + 8) = 0;
        }
      }
      else if (param_3 == 3) goto LAB_c0125ab8;
    }
    if (*(int *)(piVar2[2] + 8) == 0x4d494b45) {
      if (((uint)param_4 & 0x20) != 0) goto LAB_c012597c;
      iVar5 = FUN_c0104764(piVar2);
    }
    else {
      if (((uint)param_4 & 0x20) != 0) {
        SetLastError(0x57);
        goto LAB_c0125ab8;
      }
      iVar5 = FUN_c01031b8(piVar2,uVar11);
      if (iVar5 == 0) goto LAB_c0125ab8;
      FUN_c0123600((undefined4 *)(piVar2[2] + 0xc));
      *(undefined4 *)(piVar2[2] + 8) = 0x4d494b45;
      if (((uint)param_4 & 2) != 0) {
        iVar5 = piVar2[2];
        LVar6 = GetSystemDefaultLCID();
        *(LCID *)(iVar5 + 0xf8) = LVar6 << 8 | *(uint *)(iVar5 + 0xf8) & 0xff;
      }
      if (piVar2[0x8a] == -1) goto LAB_c012597c;
      iVar5 = FlushViewOfFile((LPCVOID)piVar2[2],piVar2[0x8d] - piVar2[2]);
    }
    if (iVar5 != 0) {
LAB_c012597c:
      do {
        puVar7 = (undefined4 *)FUN_c01241b8(&DAT_c01391e0,uVar11);
        while( true ) {
          if (puVar7 == (undefined4 *)0x0) goto LAB_c0125a60;
          DVar9 = 0x10;
          iVar5 = memcmp((void *)(piVar2[2] + 0xc),(void *)(puVar7[2] + 0xc),0x10);
          if (iVar5 == 0) break;
          puVar7 = (undefined4 *)FUN_c01241b8(puVar7,uVar11);
        }
        if (puVar7 == (undefined4 *)0x0) break;
        if (((uint)param_4 & 0x20) != 0) {
          SetLastError(0xb7);
          goto LAB_c0125ab8;
        }
        FUN_c0123600((undefined4 *)(piVar2[2] + 0xc));
        BVar8 = FlushViewOfFile((LPCVOID)piVar2[2],piVar2[0x8d] - piVar2[2]);
        if (BVar8 == 0) goto LAB_c0125ab8;
      } while (puVar7 != (undefined4 *)0x0);
LAB_c0125a60:
      FUN_c0123f18((int)piVar2);
      piVar2[0x96] = 0;
      piVar2[0x95] = 0;
      SetLastError(local_54);
      return piVar2;
    }
  }
LAB_c0125ab8:
  if (piVar2 != (int *)0x0) {
    FUN_c01244b8(piVar2,(int)param_5,DVar9,lpNumberOfBytesWritten);
  }
  return (int *)0x0;
}



/* c0125b1c FUN_c0125b1c */

/* Boundary evidence: original MIPS .pdata c0125b1c..c0125b27. Semantic name remains unreviewed. */

undefined4 FUN_c0125b1c(void)

{
  return 1;
}



/* c0125b28 FUN_c0125b28 */

/* Boundary evidence: original MIPS .pdata c0125b28..c0125e23. Semantic name remains unreviewed. */

undefined4
FUN_c0125b28(void *param_1,LPCWSTR param_2,DWORD param_3,uint param_4,ushort param_5,int *param_6,
            uint param_7,int param_8)

{
  int *piVar1;
  int iVar2;
  DWORD dwErrCode;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  LPDWORD pDVar7;
  
  uVar5 = param_4 & 0xffff;
  SetLastError(0);
  if (((uVar5 == 0) || (param_1 == (void *)0x0)) || (5 < uVar5)) {
    SetLastError(0x57);
LAB_c0125df0:
    uVar6 = 0;
  }
  else {
    pDVar7 = (LPDWORD)(uint)param_5;
    if ((((param_5 & 0x10) == 0) && (param_2 != (LPCWSTR)0x0)) &&
       (piVar1 = (int *)FUN_c01241b8(&DAT_c01391e0,(uint)pDVar7), piVar1 != (int *)0x0)) {
      do {
        iVar2 = CompareStringW(0x800,0x30001,(PCNZWCH)(piVar1 + 4),-1,param_2,-1);
        if (iVar2 == 2) break;
        piVar1 = (int *)FUN_c01241b8(piVar1,(uint)pDVar7);
      } while (piVar1 != (int *)0x0);
      if (piVar1 == (int *)0x0) goto LAB_c0125ccc;
      if (uVar5 == 1) {
        dwErrCode = 0xb7;
LAB_c0125c48:
        SetLastError(dwErrCode);
        return 0;
      }
      if ((uVar5 == 2) || (uVar5 == 5)) {
        SetLastError(5);
        piVar1 = (int *)0x0;
      }
      else {
        if (piVar1 == (int *)PTR_DAT_c0136c70) {
          dwErrCode = 5;
          goto LAB_c0125c48;
        }
        if (uVar5 == 4) {
          SetLastError(0xb7);
        }
      }
    }
    else {
LAB_c0125ccc:
      iVar2 = FUN_c0124e1c(param_6);
      if (iVar2 == 0) goto LAB_c0125df0;
      memset(param_1,-1,0x10);
      piVar1 = FUN_c0124f7c(param_2,param_3,uVar5,pDVar7,param_6,param_7);
    }
    uVar6 = 0;
    if (piVar1 != (int *)0x0) {
      uVar3 = 0;
      piVar4 = param_6;
      iVar2 = FUN_c01234d4(piVar1,param_8,0);
      if (iVar2 == 0) {
        if (piVar1[0x86] == 0) {
          FUN_c01244b8(piVar1,(int)param_6,uVar3,piVar4);
        }
      }
      else {
        if (((param_5 & 2) != 0) && ((param_5 & 0x20) == 0)) {
          *(undefined1 *)(piVar1[2] + 0xc) = 0;
        }
        if ((piVar1 == &DAT_c01391e0) || (piVar1 == (int *)PTR_DAT_c0136c70)) {
          memset(param_1,0,0x10);
        }
        else {
          memcpy(param_1,(void *)(piVar1[2] + 0xc),0x10);
        }
        iVar2 = piVar1[2];
        uVar6 = 1;
        piVar1[0x97] = *(int *)(iVar2 + 0xc);
        piVar1[0x98] = *(int *)(iVar2 + 0x10);
        piVar1[0x99] = *(int *)(iVar2 + 0x14);
        piVar1[0x9a] = *(int *)(iVar2 + 0x18);
      }
    }
  }
  return uVar6;
}



/* c0125e24 FUN_c0125e24 */

/* Boundary evidence: original MIPS .pdata c0125e24..c0125eb7. Semantic name remains unreviewed. */

bool FUN_c0125e24(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_c0101de8(param_1,param_2);
  if ((puVar1 == (uint *)0x0) || ((puVar1[-3] & 0xf0000000) != 0x80000000)) {
    puVar1 = (uint *)0x0;
  }
  if (puVar1 != (uint *)0x0) {
    *(undefined2 *)(param_3 + 2) = 4;
    uVar2 = FUN_c0101ea4(param_1,*puVar1);
    *(uint *)(param_3 + 4) = uVar2;
  }
  else {
    SetLastError(0x57);
  }
  return puVar1 != (uint *)0x0;
}



/* c0125eb8 FUN_c0125eb8 */

/* Boundary evidence: original MIPS .pdata c0125eb8..c0125fb3. Semantic name remains unreviewed. */

bool FUN_c0125eb8(undefined4 param_1,int param_2,void *param_3,void *param_4)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar3 = (uint)*(ushort *)(param_2 + 4);
  uVar2 = 0;
  uVar4 = *(ushort *)(param_2 + 6) & 0x3fff;
  if ((*(ushort *)(param_2 + 4) & 0xc000) == 0) {
    uVar2 = BinaryDecompress(param_3,uVar4,param_4,uVar3 & 0xfff,0);
  }
  else if ((uVar3 & 0xc000) == 0x4000) {
    uVar2 = StringDecompress(param_3,uVar4,param_4,uVar3 & 0xfff);
  }
  else if ((uVar3 & 0xc000) == 0x8000) {
    memcpy(param_4,param_3,uVar3 & 0xfff);
    uVar2 = *(ushort *)(param_2 + 4) & 0xfff;
  }
  bVar1 = uVar2 == (*(ushort *)(param_2 + 4) & 0xfff);
  if (!bVar1) {
    SetLastError(0x1f);
  }
  return bVar1;
}



/* c0125fb4 FUN_c0125fb4 */

/* Boundary evidence: original MIPS .pdata c0125fb4..c01260ff. Semantic name remains unreviewed. */

undefined4 FUN_c0125fb4(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  if (*(ushort *)(param_1 + 0x4c) != 0) {
    do {
      iVar1 = uVar4 * 0x40 + param_1;
      uVar5 = 0;
      if (*(ushort *)(iVar1 + 0x80) != 0) {
        do {
          if (((*(uint *)((uVar5 + 4) * 4 + iVar1 + 100) & 0x400) != 0) ||
             ((*(uint *)(iVar1 + 0x74) & 0x200) != 0)) {
            piVar3 = param_4;
            if (0 < param_3) {
              iVar2 = 0;
              do {
                if (*piVar3 == *(int *)((uVar5 + 1) * 4 + iVar1 + 100)) {
                  if ((*(ushort *)((int)piVar3 + 6) & 0x200) != 0) goto LAB_c01260e8;
                  break;
                }
                iVar2 = iVar2 + 0x10;
                piVar3 = piVar3 + 4;
              } while (iVar2 >> 4 < param_3);
            }
            if ((param_2 == 0) && (param_3 <= (int)piVar3 - (int)param_4 >> 4)) {
LAB_c01260e8:
              SetLastError(5);
              return 0;
            }
          }
          uVar5 = uVar5 + 1 & 0xffff;
        } while (uVar5 < *(ushort *)(iVar1 + 0x80));
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < *(ushort *)(param_1 + 0x4c));
  }
  return 1;
}



/* c0126100 FUN_c0126100 */

/* Boundary evidence: original MIPS .pdata c0126100..c01261d7. Semantic name remains unreviewed. */

ushort FUN_c0126100(ushort param_1,short *param_2)

{
  short sVar1;
  
  sVar1 = 0;
  if (0x13 < param_1) {
    if (param_1 != 0x1f) {
      if (param_1 == 0x40) {
LAB_c01261ac:
        sVar1 = 8;
        goto LAB_c01261c0;
      }
      if (param_1 != 0x41) goto LAB_c0126188;
    }
    sVar1 = *param_2 + 2;
    goto LAB_c01261c0;
  }
  if (param_1 < 0x12) {
    if (param_1 < 2) {
LAB_c0126188:
      RaiseException(1,1,0,(ULONG_PTR *)0x0);
      goto LAB_c01261c0;
    }
    if (3 < param_1) {
      if (param_1 == 5) goto LAB_c01261ac;
      if (param_1 != 0xb) goto LAB_c0126188;
    }
  }
  sVar1 = 4;
LAB_c01261c0:
  return sVar1 + 3U & 0xfffc;
}



/* c01261d8 FUN_c01261d8 */

/* Boundary evidence: original MIPS .pdata c01261d8..c0126357. Semantic name remains unreviewed. */

uint FUN_c01261d8(short *param_1,short *param_2)

{
  int iVar1;
  size_t _Size;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = (((ushort)param_2[3] & 0xf0) >> 4) * 0xffc;
  iVar4 = 0;
  uVar3 = 0;
  if (iVar1 != 0) {
    uVar3 = iVar1 + 0xfffeU & 0xffff;
  }
  if (*param_2 == 0x1f) {
    iVar4 = *(int *)(param_2 + 4);
  }
  else if (*param_2 == 0x41) {
    iVar4 = *(int *)(param_2 + 6);
  }
  else {
    RaiseException(1,1,0,(ULONG_PTR *)0x0);
  }
  if (uVar3 == 0) {
    *param_1 = param_2[2] + -2;
    uVar2 = (ushort)param_2[2] - 2;
    param_1 = param_1 + 1;
    if (0xff9 < uVar2) {
      uVar2 = 0xffa;
    }
    _Size = uVar2 & 0xffff;
    uVar2 = _Size + 2 & 0xffff;
  }
  else {
    uVar2 = ((ushort)param_2[2] - uVar3) - 2;
    if (0xffb < uVar2) {
      uVar2 = 0xffc;
    }
    _Size = uVar2 & 0xffff;
    uVar2 = _Size;
  }
  memcpy(param_1,(void *)(uVar3 + iVar4),_Size);
  param_2[3] = ((short)(((ushort)param_2[3] & 0xf0) >> 4) + 1) * 0x10 | param_2[3] & 0xff0fU;
  return uVar2;
}



/* c0126358 FUN_c0126358 */

/* Boundary evidence: original MIPS .pdata c0126358..c01264af. Semantic name remains unreviewed. */

void FUN_c0126358(short *param_1,ushort *param_2)

{
  ushort uVar1;
  void *_Src;
  size_t _Size;
  undefined4 uVar2;
  
  if (param_2 == (ushort *)0x0) {
    return;
  }
  if (param_2[2] == 0) {
    return;
  }
  uVar1 = *param_2;
  if (0x13 < uVar1) {
    if (uVar1 == 0x1f) {
      *param_1 = param_2[2] - 2;
      _Src = *(void **)(param_2 + 4);
      _Size = param_2[2] - 2;
    }
    else {
      if (uVar1 == 0x40) {
LAB_c0126458:
        *(undefined4 *)param_1 = *(undefined4 *)(param_2 + 4);
        *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_2 + 6);
        return;
      }
      if (uVar1 != 0x41) goto LAB_c012641c;
      *param_1 = param_2[2] - 2;
      _Size = *(size_t *)(param_2 + 4);
      _Src = *(void **)(param_2 + 6);
    }
    memcpy(param_1 + 1,_Src,_Size);
    return;
  }
  if (uVar1 < 0x12) {
    if (uVar1 < 2) {
LAB_c012641c:
      RaiseException(1,1,0,(ULONG_PTR *)0x0);
      return;
    }
    if (3 < uVar1) {
      if (uVar1 == 5) goto LAB_c0126458;
      if (uVar1 != 0xb) goto LAB_c012641c;
      uVar2 = 1;
      if (*(int *)(param_2 + 4) == 0) {
        uVar2 = 0;
      }
      goto LAB_c01263ec;
    }
  }
  uVar2 = *(undefined4 *)(param_2 + 4);
LAB_c01263ec:
  *(undefined4 *)param_1 = uVar2;
  return;
}



/* c01264b0 FUN_c01264b0 */

/* Boundary evidence: original MIPS .pdata c01264b0..c0126817. Semantic name remains unreviewed. */

undefined4 FUN_c01264b0(int param_1,int param_2,ushort *param_3,int param_4)

{
  ushort uVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  wchar_t *_Str;
  uint *puVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  
  uVar1 = param_3[3];
  uVar8 = uVar1 & 0xf00;
  param_3[3] = uVar8;
  if ((uVar1 & 0x200) != 0) {
    param_3[2] = 0;
    goto LAB_c01266ac;
  }
  uVar1 = *param_3;
  if (uVar1 < 0x13) {
    if (((uVar1 != 0x12) && (uVar1 != 2)) && (uVar1 != 3)) {
      if (uVar1 == 5) {
LAB_c0126610:
        param_3[2] = 8;
        goto LAB_c01266ac;
      }
      if (uVar1 != 0xb) goto LAB_c0126698;
    }
  }
  else if (uVar1 != 0x13) {
    if (uVar1 == 0x1f) {
      _Str = *(wchar_t **)(param_3 + 4);
      if (_Str == (wchar_t *)0x0) {
        iVar7 = 0;
      }
      else {
        sVar2 = wcslen(_Str);
        iVar7 = sVar2 << 1;
      }
      uVar9 = iVar7 + 2;
      if (0xffbf < uVar9) {
LAB_c01265b4:
        SetLastError(0x57);
        return 0;
      }
      if ((param_4 != 0) && ((_Str != (wchar_t *)0x0 || (iVar7 != 0)))) {
        if ((iVar7 < 0) || ((int)_Str < 0x10000)) goto LAB_c0126698;
        uVar4 = (int)_Str + iVar7;
LAB_c0126684:
        if (0x7fffffff < uVar4) {
LAB_c0126698:
          SetLastError(0x57);
          return 0;
        }
      }
    }
    else {
      if (uVar1 == 0x40) goto LAB_c0126610;
      if (uVar1 != 0x41) goto LAB_c0126698;
      iVar7 = *(int *)(param_3 + 4);
      uVar9 = iVar7 + 2;
      if (0xffbf < uVar9) goto LAB_c01265b4;
      if ((param_4 != 0) && ((iVar3 = *(int *)(param_3 + 6), iVar3 != 0 || (iVar7 != 0)))) {
        if ((iVar7 < 0) || (iVar3 < 0x10000)) goto LAB_c0126698;
        uVar4 = iVar3 + iVar7;
        goto LAB_c0126684;
      }
    }
    param_3[2] = (ushort)uVar9;
    goto LAB_c01266ac;
  }
  param_3[2] = 4;
LAB_c01266ac:
  puVar6 = (uint *)(param_2 + 0x74);
  param_3[3] = uVar8;
  if ((*puVar6 & 8) == 0) {
    if (*(short *)(param_2 + 0x4c) != 0) {
      uVar9 = 0;
      do {
        puVar5 = (ushort *)((uVar9 + 2) * 0x40 + param_2);
        uVar4 = 0;
        if (*puVar5 != 0) {
          do {
            if (*(int *)((uVar4 + uVar9 * 0x10 + 0x1a) * 4 + param_2) == *(int *)param_3) {
              iVar7 = uVar9 * 0x40 + param_2;
              param_3[3] = (ushort)(1 << (uVar9 + 0xc & 0x1f)) | param_3[3];
              FUN_c01029e4(param_1,1,uVar9 * 0x40 + param_2 + 0x74,*(undefined4 *)(iVar7 + 0x74),4);
              *(uint *)(iVar7 + 0x74) = *(uint *)(iVar7 + 0x74) | 0x80000000;
              break;
            }
            uVar4 = uVar4 + 1 & 0xffff;
          } while (uVar4 < *puVar5);
        }
        uVar9 = uVar9 + 1 & 0xffff;
      } while (uVar9 < *(ushort *)(param_2 + 0x4c));
    }
  }
  else {
    param_3[3] = uVar8 | 0x1000;
    FUN_c01029e4(param_1,1,puVar6,*puVar6,4);
    *puVar6 = *puVar6 | 0x80000000;
  }
  if (0xffb < param_3[2]) {
    param_3[3] = param_3[3] | 8;
  }
  return 1;
}



/* c0126818 FUN_c0126818 */

/* Boundary evidence: original MIPS .pdata c0126818..c0126903. Semantic name remains unreviewed. */

void FUN_c0126818(undefined4 *param_1,void *param_2)

{
  LPVOID _Dst;
  int iVar1;
  undefined4 *puVar2;
  
  FUN_c0101914(param_2);
  while (param_1 != (undefined4 *)0x0) {
    if (param_1[1] == 0) {
      FUN_c0100588(*param_1,*(undefined4 *)((int)param_2 + 8),*(undefined4 *)((int)param_2 + 0x1c),
                   *(undefined4 *)((int)param_2 + 0x20));
    }
    else {
      _Dst = HeapAlloc(DAT_c0136cb0,0,0x24);
      if (_Dst != (LPVOID)0x0) {
        memcpy(_Dst,param_2,0x24);
        *(undefined4 *)((int)_Dst + 4) = param_1[3];
        iVar1 = FUN_c0100588(*param_1,0x3fd,0,_Dst);
        if (iVar1 == 0) {
          HeapFree(DAT_c0136cb0,0,_Dst);
        }
      }
    }
    puVar2 = (undefined4 *)param_1[4];
    LocalFree(param_1);
    param_1 = puVar2;
  }
  return;
}



/* c0126904 FUN_c0126904 */

/* Boundary evidence: original MIPS .pdata c0126904..c0126a2f. Semantic name remains unreviewed. */

undefined4 * FUN_c0126904(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  puVar3 = (undefined4 *)0x0;
  piVar1 = DAT_c0137134;
  if (param_1 != 0) {
    for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      puVar2 = puVar3;
      if ((((piVar1 != (int *)param_1) && (piVar1[4] != 0)) &&
          (piVar1[4] == *(int *)(param_1 + 0x10))) &&
         ((piVar1[5] == (*(uint *)(param_2 + 0x20) & 0xffffff) && (piVar1[10] != 0)))) {
        if (puVar3 == (undefined4 *)0x0) {
          puVar2 = LocalAlloc(0,0x14);
          puVar4 = puVar2;
        }
        else {
          puVar2 = LocalAlloc(0,0x14);
          puVar3[4] = puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) {
          return puVar4;
        }
        puVar2[4] = 0;
        *puVar2 = piVar1[10];
        if ((piVar1[0xc] & 1U) == 0) {
          puVar2[1] = 0;
        }
        else {
          puVar2[1] = piVar1[2];
          puVar2[3] = piVar1[0xd];
          puVar2[2] = piVar1[0xb];
        }
      }
      puVar3 = puVar2;
    }
  }
  return puVar4;
}



/* c0126a30 FUN_c0126a30 */

/* Boundary evidence: original MIPS .pdata c0126a30..c0126bfb. Semantic name remains unreviewed. */

short * FUN_c0126a30(int param_1,int param_2,uint param_3,uint *param_4,int *param_5)

{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  HLOCAL pvVar4;
  undefined3 extraout_var;
  undefined2 extraout_var_00;
  uint uVar5;
  uint *puVar6;
  short *psVar7;
  uint *puVar8;
  uint *puVar9;
  
  psVar7 = (short *)0x0;
  puVar6 = (uint *)(param_2 + 4);
  bVar1 = false;
  do {
    if (puVar6 == (uint *)0x0) {
      return psVar7;
    }
    if (bVar1) {
      return psVar7;
    }
    bVar1 = false;
    if ((puVar6[1] & 0xfff) != 0) {
      puVar9 = puVar6 + 2;
      puVar8 = puVar9;
      do {
        uVar5 = *puVar8;
        if (param_3 == (uVar5 & 0xfffffeff)) {
          bVar1 = true;
        }
        puVar8 = puVar8 + 1;
      } while ((uVar5 & 0x100) == 0);
      if (bVar1) {
        if (*param_5 == 0) {
          pvVar4 = LocalAlloc(0,0x1000);
          *param_5 = (int)pvVar4;
          if (pvVar4 == (HLOCAL)0x0) {
            SetLastError(8);
            return (short *)0x0;
          }
        }
        if (((param_4 == (uint *)0x0) || ((uint *)*param_4 != puVar6)) &&
           (bVar2 = FUN_c0125eb8(param_2,(int)puVar6,puVar8,(void *)*param_5),
           CONCAT31(extraout_var,bVar2) == 0)) {
          return (short *)0x0;
        }
        if (param_4 != (uint *)0x0) {
          *param_4 = (uint)puVar6;
        }
        psVar7 = (short *)*param_5;
        do {
          if (param_3 == (*puVar9 & 0xfffffeff)) break;
          uVar3 = FUN_c0126100((ushort)(*puVar9 & 0xfffffeff),psVar7);
          uVar5 = *puVar9;
          psVar7 = (short *)(CONCAT22(extraout_var_00,uVar3) + (int)psVar7);
          puVar9 = puVar9 + 1;
        } while ((uVar5 & 0x100) == 0);
      }
    }
    if (((*puVar6 == 0) || (puVar6 = (uint *)FUN_c0101c94(param_1,*puVar6), puVar6 == (uint *)0x0))
       || ((puVar6[-3] & 0xf0000000) != 0x90000000)) {
      puVar6 = (uint *)0x0;
    }
  } while( true );
}



/* c0126bfc FUN_c0126bfc */

/* Boundary evidence: original MIPS .pdata c0126bfc..c01273c3. Semantic name remains unreviewed. */

undefined4
FUN_c0126bfc(int param_1,int param_2,uint param_3,ushort *param_4,int param_5,int *param_6,
            uint *param_7,undefined4 param_8,int param_9)

{
  bool bVar1;
  uint *puVar2;
  undefined3 extraout_var;
  HLOCAL pvVar3;
  DWORD dwErrCode;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  ushort local_50;
  undefined4 *local_4c;
  uint *local_3c;
  uint *local_38;
  
  local_38 = (uint *)0x0;
  uVar12 = 0;
  local_4c = (undefined4 *)0x0;
  if (param_5 == 0) {
    uVar9 = 0;
    puVar2 = (uint *)(param_2 + 4);
    *param_4 = 0;
    while (puVar2 != (uint *)0x0) {
      puVar11 = puVar2 + 2;
      if ((puVar2[1] & 0xfff) != 0) {
        do {
          uVar5 = *puVar11;
          if (uVar5 != uVar9) {
            *param_4 = *param_4 + 1;
            uVar5 = *puVar11;
            uVar9 = uVar5;
          }
          puVar11 = puVar11 + 1;
        } while ((uVar5 & 0x100) == 0);
      }
      if (((*puVar2 == 0) || (puVar2 = (uint *)FUN_c0101c94(param_1,*puVar2), puVar2 == (uint *)0x0)
          ) || ((puVar2[-3] & 0xf0000000) != 0x90000000)) {
        puVar2 = (uint *)0x0;
      }
    }
  }
  puVar2 = (uint *)(param_2 + 4);
  do {
    uVar4 = (uint)*param_4;
    puVar6 = (undefined4 *)*param_6;
    uVar9 = 0;
    uVar5 = uVar4 * 0x10;
    local_50 = 0;
    local_3c = puVar2;
    if (((puVar6 != (undefined4 *)0x0) && (uVar5 <= *param_7)) &&
       ((local_4c = puVar6 + uVar4 * 4, param_5 != 0 && (uVar7 = 0, uVar4 != 0)))) {
      do {
        *puVar6 = *(undefined4 *)(uVar7 * 4 + param_5);
        *(undefined2 *)((int)puVar6 + 6) = 0x100;
        *(undefined2 *)(puVar6 + 1) = 0;
        uVar7 = uVar7 + 1 & 0xffff;
        puVar6 = puVar6 + 4;
      } while (uVar7 < *param_4);
    }
    while ((local_3c != (uint *)0x0 && (local_50 < *param_4))) {
      if ((local_3c[1] & 0xfff) != 0) {
        puVar10 = local_3c + 2;
        puVar11 = puVar10;
        do {
          uVar4 = *puVar11;
          puVar11 = puVar11 + 1;
        } while ((uVar4 & 0x100) == 0);
        if ((local_38 != local_3c) &&
           (bVar1 = FUN_c0125eb8(param_2,(int)local_3c,puVar11,*(void **)(param_1 + 0x224)),
           local_38 = local_3c, CONCAT31(extraout_var,bVar1) == 0)) {
          return 0;
        }
        puVar11 = *(uint **)(param_1 + 0x224);
        do {
          uVar4 = *puVar10;
          puVar8 = (uint *)0x0;
          uVar7 = uVar4 & 0xfffffeff;
          if ((param_5 != 0) && (uVar13 = 0, uVar9 = 0xffff, *param_4 != 0)) {
            do {
              uVar9 = uVar13;
              if (*(uint *)(uVar13 * 4 + param_5) == uVar7) break;
              uVar13 = uVar13 + 1 & 0xffff;
              uVar9 = 0xffff;
            } while (uVar13 < *param_4);
          }
          if (((*param_6 != 0) && (uVar5 <= *param_7)) && (uVar9 != 0xffff)) {
            puVar8 = (uint *)(uVar9 * 0x10 + *param_6);
            *puVar8 = uVar7;
            *(undefined2 *)((int)puVar8 + 6) = 0;
          }
          uVar4 = uVar4 & 0xfeff;
          if (uVar4 < 0x14) {
            if (uVar4 < 0x12) {
              if (uVar4 < 2) {
LAB_c0126f58:
                RaiseException(1,1,0,(ULONG_PTR *)0x0);
                goto LAB_c01271f0;
              }
              if (3 < uVar4) {
                if (uVar4 == 5) goto LAB_c012706c;
                if (uVar4 != 0xb) goto LAB_c0126f58;
              }
            }
            if ((uVar9 != 0xffff) && (puVar8 != (uint *)0x0)) {
              puVar8[2] = *puVar11;
            }
            puVar11 = puVar11 + 1;
          }
          else if (uVar4 == 0x1f) {
            if (uVar12 == 0) {
              uVar12 = (ushort)*puVar11 + 2 & 0xffff;
              uVar4 = uVar12 - 2;
              if (0xff9 < uVar4) {
                uVar4 = 0xffa;
              }
              uVar4 = uVar4 & 0xffff;
              if (((uVar9 != 0xffff) &&
                  (uVar5 = (uVar12 + 3 & 0xfffffffc) + uVar5, puVar8 != (uint *)0x0)) &&
                 (uVar5 <= *param_7)) {
                puVar8[2] = (uint)local_4c;
                memcpy(local_4c,(ushort *)((int)puVar11 + 2),uVar4);
                local_4c = (undefined4 *)(uVar4 + (int)local_4c);
                if (uVar12 == uVar4 + 2) {
                  *(undefined2 *)local_4c = 0;
                  local_4c = (undefined4 *)((int)local_4c + 2);
                }
              }
              uVar12 = uVar12 - uVar4 & 0xffff;
              puVar11 = (uint *)((uVar4 + 5 & 0xfffffffc) + (int)puVar11);
              if (uVar12 == 2) {
                uVar12 = 0;
              }
            }
            else {
              uVar4 = uVar12 - 2;
              if (0xffb < uVar4) {
                uVar4 = 0xffc;
              }
              uVar4 = uVar4 & 0xffff;
              if (((uVar9 != 0xffff) && (puVar8 != (uint *)0x0)) && (uVar5 <= *param_7)) {
                memcpy(local_4c,puVar11,uVar4);
                local_4c = (undefined4 *)(uVar4 + (int)local_4c);
                if (uVar12 == uVar4 + 2) {
                  *(undefined2 *)local_4c = 0;
                  local_4c = (undefined4 *)((int)local_4c + 2);
                }
              }
              uVar12 = uVar12 - uVar4 & 0xffff;
              puVar11 = (uint *)((uVar4 + 3 & 0xfffffffc) + (int)puVar11);
              if (uVar12 == 2) {
                uVar12 = 0;
              }
            }
          }
          else if (uVar4 == 0x40) {
LAB_c012706c:
            if ((uVar9 != 0xffff) && (puVar8 != (uint *)0x0)) {
              puVar8[2] = *puVar11;
              puVar8[3] = puVar11[1];
            }
            puVar11 = puVar11 + 2;
          }
          else {
            if (uVar4 != 0x41) goto LAB_c0126f58;
            if (uVar12 == 0) {
              uVar12 = (uint)(ushort)*puVar11;
              uVar4 = uVar12;
              if (0xff9 < uVar12) {
                uVar4 = 0xffa;
              }
              if (((uVar9 != 0xffff) &&
                  (uVar5 = (uVar12 + 3 & 0xfffffffc) + uVar5, puVar8 != (uint *)0x0)) &&
                 (uVar5 <= *param_7)) {
                puVar8[2] = uVar12;
                puVar8[3] = (uint)local_4c;
                memcpy(local_4c,(ushort *)((int)puVar11 + 2),uVar4);
                local_4c = (undefined4 *)(uVar4 + (int)local_4c);
              }
              uVar12 = uVar12 - uVar4;
              uVar4 = uVar4 + 5;
            }
            else {
              uVar4 = uVar12;
              if (0xffb < uVar12) {
                uVar4 = 0xffc;
              }
              if (((uVar9 != 0xffff) && (puVar8 != (uint *)0x0)) && (uVar5 <= *param_7)) {
                memcpy(local_4c,puVar11,uVar4);
                local_4c = (undefined4 *)(uVar4 + (int)local_4c);
              }
              uVar12 = uVar12 - uVar4;
              uVar4 = uVar4 + 3;
            }
            uVar12 = uVar12 & 0xffff;
            puVar11 = (uint *)((uVar4 & 0xfffffffc) + (int)puVar11);
          }
LAB_c01271f0:
          if ((uVar9 != 0xffff) && (uVar12 == 0)) {
            local_50 = local_50 + 1;
            local_4c = (undefined4 *)((int)local_4c + 3U & 0xfffffffc);
          }
          if ((param_5 == 0) && (uVar12 == 0)) {
            uVar9 = uVar9 + 1 & 0xffff;
          }
          uVar4 = *puVar10;
          puVar10 = puVar10 + 1;
        } while ((uVar4 & 0x100) == 0);
      }
      if (((*local_3c == 0) ||
          (local_3c = (uint *)FUN_c0101c94(param_1,*local_3c), local_3c == (uint *)0x0)) ||
         ((local_3c[-3] & 0xf0000000) != 0x90000000)) {
        local_3c = (uint *)0x0;
      }
    }
    pvVar3 = (HLOCAL)*param_6;
    if ((pvVar3 != (HLOCAL)0x0) && (uVar5 <= *param_7)) {
      return 1;
    }
    if ((param_3 & 1) == 0) {
LAB_c0127364:
      if (param_7 != (uint *)0x0) {
        *param_7 = uVar5;
        dwErrCode = 0x7a;
        goto LAB_c012737c;
      }
LAB_c0127378:
      dwErrCode = 0x57;
LAB_c012737c:
      SetLastError(dwErrCode);
      return 0;
    }
    if (param_9 != 0) {
      if (pvVar3 != (HLOCAL)0x0) {
        LocalFree(pvVar3);
      }
      pvVar3 = LocalAlloc(0,uVar5);
      *param_6 = (int)pvVar3;
    }
    if (*param_6 == 0) goto LAB_c0127364;
    if (param_7 == (uint *)0x0) goto LAB_c0127378;
    *param_7 = uVar5;
  } while( true );
}



/* c01273c4 FUN_c01273c4 */

/* Boundary evidence: original MIPS .pdata c01273c4..c0127663. Semantic name remains unreviewed. */

undefined4
FUN_c01273c4(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5,
            undefined2 *param_6,int *param_7,uint *param_8)

{
  int iVar1;
  size_t sVar2;
  wchar_t *_Str;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  ushort *puVar7;
  undefined4 uVar8;
  uint uVar9;
  ushort local_28 [4];
  
  uVar8 = 1;
  if ((*(uint *)(param_4 + 0x10) & 8) == 0) {
    local_28[0] = *(ushort *)(param_4 + 0x1c);
    iVar1 = FUN_c0126bfc(param_1,param_3,1,local_28,param_4 + 4,param_7,param_8,0,1);
    if (iVar1 == 0) {
      uVar8 = 0;
    }
    else {
      *param_6 = *(undefined2 *)(param_4 + 0x1c);
      uVar4 = (uint)*(ushort *)(param_4 + 0x1c);
      if (uVar4 != 0) {
        uVar9 = 0;
        do {
          piVar6 = (int *)*param_7;
          iVar1 = *(int *)((uVar9 + 1) * 4 + param_4);
          if (*piVar6 != iVar1) {
            iVar5 = 0;
            do {
              if ((int)uVar4 <= iVar5 >> 4) break;
              piVar6 = piVar6 + 4;
              iVar5 = iVar5 + 0x10;
            } while (*piVar6 != iVar1);
          }
          puVar7 = (ushort *)(param_5 + uVar9 * 4);
          if ((*piVar6 == iVar1) && ((*(ushort *)((int)piVar6 + 6) & 0x100) == 0)) {
            *(int *)puVar7 = *piVar6;
            uVar3 = *puVar7;
            puVar7[3] = *(ushort *)((int)piVar6 + 6);
            if (uVar3 < 0x14) {
              if (uVar3 < 0x12) {
                if (uVar3 < 2) {
LAB_c0127584:
                  RaiseException(1,1,0,(ULONG_PTR *)0x0);
                  goto LAB_c012761c;
                }
                if (3 < uVar3) {
                  if (uVar3 == 5) goto LAB_c01275c4;
                  if (uVar3 != 0xb) goto LAB_c0127584;
                }
              }
              *(int *)(puVar7 + 4) = piVar6[2];
              puVar7[2] = 4;
            }
            else if (uVar3 == 0x1f) {
              _Str = (wchar_t *)piVar6[2];
              *(wchar_t **)(puVar7 + 4) = _Str;
              sVar2 = wcslen(_Str);
              puVar7[2] = ((short)sVar2 + 1) * 2;
            }
            else {
              if (uVar3 == 0x40) {
LAB_c01275c4:
                uVar3 = 8;
                *(int *)(puVar7 + 4) = piVar6[2];
                *(int *)(puVar7 + 6) = piVar6[3];
              }
              else {
                if (uVar3 != 0x41) goto LAB_c0127584;
                *(int *)(puVar7 + 4) = piVar6[2];
                *(int *)(puVar7 + 6) = piVar6[3];
                uVar3 = (short)piVar6[2] + 2;
              }
              puVar7[2] = uVar3;
            }
          }
          else {
            *(int *)puVar7 = iVar1;
            puVar7[3] = 0x100;
            puVar7[2] = 0;
          }
LAB_c012761c:
          uVar9 = uVar9 + 1 & 0xffff;
          uVar4 = (uint)*(ushort *)(param_4 + 0x1c);
        } while (uVar9 < uVar4);
      }
    }
  }
  else {
    *param_6 = 1;
    *param_5 = 0;
    *(undefined2 *)((int)param_5 + 6) = 0;
    *(undefined2 *)(param_5 + 1) = 0;
  }
  return uVar8;
}



/* c0127664 FUN_c0127664 */

/* Boundary evidence: original MIPS .pdata c0127664..c01279cb. Semantic name remains unreviewed. */

undefined4 FUN_c0127664(int param_1,int param_2,int param_3,uint param_4,int *param_5)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  ushort local_b6;
  HLOCAL local_b4;
  uint local_b0 [2];
  uint local_a8;
  uint local_a4;
  uint local_a0;
  int local_98;
  int local_94 [11];
  uint auStack_68 [4];
  undefined4 uStack_58;
  int local_54 [11];
  
  uVar11 = 0;
  local_b6 = 0;
  local_b4 = (HLOCAL)0x0;
  local_b0[0] = 0;
  uVar12 = 0;
  uVar10 = 0;
  uVar6 = param_4;
  if (*(short *)(param_2 + 0x4c) == 0) {
LAB_c0127980:
    uVar12 = 1;
LAB_c0127984:
    if (local_b4 != (HLOCAL)0x0) {
      LocalFree(local_b4);
    }
    return uVar12;
  }
  do {
    iVar5 = uVar10 * 0x40 + param_2;
    iVar9 = iVar5 + 100;
    if ((*(uint *)(iVar5 + 0x74) & 0x200) != 0) {
      bVar2 = false;
      if (param_3 != 0) {
        iVar3 = FUN_c01273c4(param_1,param_2,param_3,iVar9,&uStack_58,&local_b6,(int *)&local_b4,
                             local_b0);
        if (iVar3 == 0) goto LAB_c0127984;
        uVar11 = (uint)local_b6;
        uVar6 = param_4 & 0xffff;
      }
      uVar1 = *(ushort *)(iVar5 + 0x80);
      if (uVar1 != 0) {
        uVar8 = 0;
        do {
          iVar5 = *(int *)((uVar8 + 1) * 4 + iVar9);
          (&local_98)[uVar8 * 4] = iVar5;
          piVar7 = param_5;
          if (0 < (int)uVar6) {
            iVar3 = 0;
            do {
              if (*piVar7 == iVar5) {
                bVar2 = true;
                if ((*(ushort *)((int)piVar7 + 6) & 0x200) == 0) {
                  iVar5 = piVar7[1];
                  *(undefined2 *)((int)local_94 + (uVar8 * 8 + 1) * 2) = 0;
                  *(short *)(local_94 + uVar8 * 4) = (short)iVar5;
                  iVar5 = piVar7[3];
                  local_94[uVar8 * 4 + 1] = piVar7[2];
                  local_94[uVar8 * 4 + 2] = iVar5;
                }
                else {
                  *(undefined2 *)((int)local_94 + (uVar8 * 8 + 1) * 2) = 0x100;
                  *(undefined2 *)(local_94 + uVar8 * 4) = 0;
                }
                break;
              }
              iVar3 = iVar3 + 0x10;
              piVar7 = piVar7 + 4;
            } while (iVar3 >> 4 < (int)uVar6);
          }
          if ((int)uVar6 <= (int)piVar7 - (int)param_5 >> 4) {
            if ((param_3 == 0) || (uVar11 <= uVar8)) {
              *(undefined2 *)((int)local_94 + (uVar8 * 8 + 1) * 2) = 0x100;
              *(undefined2 *)(local_94 + uVar8 * 4) = 0;
            }
            else {
              *(undefined2 *)((int)local_94 + (uVar8 * 8 + 1) * 2) =
                   *(undefined2 *)((int)local_54 + (uVar8 * 8 + 1) * 2);
              *(short *)(local_94 + uVar8 * 4) = (short)local_54[uVar8 * 4];
              iVar5 = local_54[uVar8 * 4 + 2];
              local_94[uVar8 * 4 + 1] = local_54[uVar8 * 4 + 1];
              local_94[uVar8 * 4 + 2] = iVar5;
            }
          }
          uVar8 = uVar8 + 1 & 0xffff;
        } while (uVar8 < uVar1);
        if (bVar2) {
          puVar4 = FUN_c012d898(auStack_68,param_1,param_2,iVar9,0x20,(int)&local_98,uVar1,&local_a8
                               );
          local_a8 = *puVar4;
          local_a4 = puVar4[1];
          local_a0 = puVar4[2];
          if (local_a4 != 0) {
            uVar6 = FUN_c0101ea4(param_1,local_a4);
            iVar5 = FUN_c0101de8(param_1,uVar6);
            if ((iVar5 == 0) || ((*(uint *)(iVar5 + -0xc) & 0xf0000000) != 0x80000000)) {
              iVar5 = 0;
            }
            if ((param_3 == 0) || (iVar5 != param_3)) {
              SetLastError(0xb7);
              goto LAB_c0127984;
            }
          }
        }
      }
    }
    uVar10 = uVar10 + 1 & 0xffff;
    if (*(ushort *)(param_2 + 0x4c) <= uVar10) goto LAB_c0127980;
    uVar6 = param_4 & 0xffff;
  } while( true );
}



/* c01279cc FUN_c01279cc */

/* Boundary evidence: original MIPS .pdata c01279cc..c0128913. Semantic name remains unreviewed. */

uint * FUN_c01279cc(undefined4 *param_1,int param_2,uint *param_3,uint param_4,uint *param_5,
                   int param_6)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined2 extraout_var_02;
  uint *puVar4;
  int iVar5;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  short sVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  short *_Dst;
  int iVar14;
  short *_Src;
  uint uVar15;
  ushort *puVar16;
  uint uVar17;
  uint *puVar18;
  ushort local_9e;
  uint local_9c;
  ushort local_98 [2];
  uint *local_94;
  int local_90;
  uint *local_8c;
  uint *local_88;
  uint local_84;
  uint *local_80;
  uint local_7c;
  HLOCAL local_78;
  uint *local_74;
  uint local_70;
  HLOCAL local_6c;
  uint *local_68;
  undefined4 *local_64;
  uint *local_60;
  uint local_58 [12];
  size_t _Size;
  
  local_8c = (uint *)0x0;
  local_84 = 0;
  bVar1 = true;
  puVar12 = (uint *)0x0;
  local_78 = (HLOCAL)0x0;
  local_70 = 0;
  local_6c = (HLOCAL)0x0;
  local_68 = (uint *)0x0;
  if (param_3 != (uint *)0x0) {
    puVar12 = param_3 + 1;
  }
  uVar15 = param_4;
  local_94 = param_3;
  local_90 = param_2;
  local_80 = param_3;
  local_7c = param_4;
  local_64 = param_1;
  if (0 < (int)param_4) {
    iVar14 = 0;
    puVar8 = param_5;
    do {
      iVar3 = FUN_c01264b0((int)param_1,param_2,(ushort *)puVar8,param_6);
      if (iVar3 == 0) goto LAB_c01288a8;
      iVar14 = iVar14 + 0x10;
      puVar8 = puVar8 + 4;
    } while (iVar14 >> 4 < (int)local_7c);
    uVar15 = param_4 & 0xffff;
  }
  iVar14 = FUN_c0125fb4(param_2,(int)param_3,uVar15,(int *)param_5);
  if ((iVar14 != 0) &&
     (iVar14 = FUN_c0127664((int)param_1,param_2,(int)param_3,uVar15,(int *)param_5), iVar14 != 0))
  {
    puVar8 = (uint *)0x0;
    if (param_3 != (uint *)0x0) {
      uVar15 = 0;
      if ((param_4 & 0xffff) != 0) {
        uVar10 = 0;
        do {
          iVar14 = uVar10 * 0x10;
          uVar10 = uVar10 + 1 & 0xffff;
          uVar15 = *(ushort *)((int)param_5 + iVar14 + 6) >> 0xc | uVar15;
        } while (uVar10 < (param_4 & 0xffff));
      }
      uVar10 = 0;
      if (*(short *)(param_2 + 0x4c) != 0) {
        do {
          if ((1 << (uVar10 & 0x1f) & uVar15) != 0) {
            puVar16 = (ushort *)(param_2 + 0x4e);
            uVar17 = 1 << (uVar10 + 8 & 0x1f);
            if ((*puVar16 & uVar17) == 0) {
              iVar3 = uVar10 * 0x40 + param_2;
              iVar14 = FUN_c01273c4((int)param_1,local_90,(int)param_3,iVar3 + 100,local_58,local_98
                                    ,(int *)&local_78,&local_70);
              if (iVar14 == 0) goto LAB_c0128894;
              FUN_c01029e4((int)param_1,1,puVar16,uVar17 & 0xffff | (uint)*puVar16,2);
              iVar14 = FUN_c012dcf4(param_1,iVar3 + 100,param_3[-1],(int)local_58,local_98[0],
                                    &local_84,&local_6c);
              param_2 = local_90;
              if (iVar14 == 0) goto LAB_c0128894;
              FUN_c01029e4((int)param_1,1,uVar10 * 0x40 + local_90 + 0x74,
                           *(undefined4 *)(iVar3 + 0x74),4);
              *(uint *)(iVar3 + 0x74) = *(uint *)(iVar3 + 0x74) & 0x7fffffff;
            }
          }
          uVar10 = uVar10 + 1 & 0xffff;
          puVar8 = local_8c;
        } while (uVar10 < *(ushort *)(param_2 + 0x4c));
      }
    }
    local_88 = param_5;
    puVar4 = param_3;
    do {
      while( true ) {
        uVar15 = param_4 & 0xffff;
        if (((puVar12 == (uint *)0x0) && ((int)local_7c <= (int)local_88 - (int)param_5 >> 4)) &&
           (!bVar1)) {
          if ((puVar4 == (uint *)0x0) || (uVar15 = 0, *(short *)(param_2 + 0x4c) == 0))
          goto LAB_c0128590;
          goto LAB_c01284ec;
        }
        uVar10 = 0;
        local_9e = 0;
        local_98[0] = 0;
        local_60 = local_88;
        if (puVar12 == (uint *)0x0) break;
        puVar18 = puVar12 + 2;
        if (puVar8 == (uint *)0x0) {
          uVar17 = local_94[-3];
        }
        else {
          uVar17 = puVar12[-3];
        }
        if ((uVar17 & 2) == 0) {
          uVar15 = (ushort)puVar12[1] & 0xfff;
          puVar13 = puVar18;
          uVar2 = 0;
          if (((ushort)puVar12[1] & 0xfff) != 0) {
            do {
              local_98[0] = uVar2;
              if ((uVar10 & 0x1f) == 0) {
                local_58[uVar10 >> 5] = 0;
              }
              if ((short)param_4 != 0) {
                puVar8 = param_5;
                sVar9 = (short)param_4;
                do {
                  sVar9 = sVar9 + -1;
                  if (*puVar8 == (*puVar13 & 0xfffffeff)) goto LAB_c0127ec4;
                  puVar8 = puVar8 + 4;
                } while (sVar9 != 0);
              }
              puVar8 = (uint *)0x0;
LAB_c0127ec4:
              if (puVar8 != (uint *)0x0) {
                local_58[uVar10 >> 5] = 1 << (uVar10 & 0x1f) | local_58[uVar10 >> 5];
                local_98[0] = local_98[0] + 1;
              }
              uVar7 = *puVar13;
              uVar17 = uVar10 + 1;
              uVar10 = uVar17 & 0xffff;
              puVar13 = puVar13 + 1;
              uVar2 = local_98[0];
            } while ((uVar7 & 0x100) == 0);
            local_9e = (ushort)uVar17;
            param_2 = local_90;
          }
          if ((local_98[0] == 0) &&
             ((uVar10 = ((ushort)local_88[1] + 3 & 0xfffffffc) + uVar15, puVar8 = puVar12,
              puVar4 = local_94, 0xffc < uVar10 || (uVar10 < uVar15)))) goto LAB_c0128488;
          _Dst = (short *)param_1[0x89];
          bVar1 = FUN_c0125eb8(local_94,(int)puVar12,puVar13,_Dst);
          if (CONCAT31(extraout_var,bVar1) != 0) {
            puVar13 = local_94;
            if (local_9e != 0) {
              uVar15 = 0;
              _Src = _Dst;
              do {
                uVar2 = FUN_c0126100((ushort)*puVar18 & 0xfeff,_Src);
                _Size = CONCAT22(extraout_var_02,uVar2);
                if ((1 << (uVar15 & 0x1f) & local_58[uVar15 >> 5]) == 0) {
                  if (_Dst != _Src) {
                    memcpy(_Dst,_Src,_Size);
                  }
                  _Dst = (short *)(_Size + (int)_Dst);
                }
                uVar15 = uVar15 + 1 & 0xffff;
                _Src = (short *)(_Size + (int)_Src);
                puVar18 = puVar18 + 1;
                param_1 = local_64;
                param_2 = local_90;
                puVar13 = local_94;
              } while (uVar15 < local_9e);
            }
            goto LAB_c0128020;
          }
          goto LAB_c0128894;
        }
        local_74 = puVar8;
        if (puVar8 == (uint *)0x0) goto LAB_c0128894;
        if (uVar15 != 0) {
          puVar13 = param_5;
          do {
            uVar15 = uVar15 + 0xffff & 0xffff;
            if (*puVar13 == (*puVar18 & 0xfffffeff)) goto LAB_c0127d48;
            puVar13 = puVar13 + 4;
          } while (uVar15 != 0);
        }
        puVar13 = (uint *)0x0;
LAB_c0127d48:
        do {
          puVar4 = puVar12;
          puVar12 = puVar4;
          if (puVar4[2] != *puVar18) break;
          if (((*puVar4 == 0) ||
              (puVar12 = (uint *)FUN_c0101c94((int)param_1,*puVar4), puVar12 == (uint *)0x0)) ||
             ((puVar12[-3] & 0xf0000000) != 0x90000000)) {
            puVar12 = (uint *)0x0;
          }
          if (puVar13 != (uint *)0x0) {
            FUN_c01029e4((int)param_1,1,puVar4,*puVar4,4);
            *puVar4 = local_84;
            local_84 = puVar4[-1];
          }
          puVar8 = puVar4;
        } while (puVar12 != (uint *)0x0);
        puVar18 = local_74;
        param_2 = local_90;
        puVar4 = local_94;
        local_8c = puVar8;
        if (puVar13 != (uint *)0x0) {
          local_8c = local_74;
          FUN_c01029e4((int)param_1,1,local_74,*local_74,4);
          if (puVar12 == (uint *)0x0) {
            uVar15 = 0;
          }
          else {
            uVar15 = puVar12[-1];
          }
          *puVar18 = uVar15;
          puVar8 = puVar18;
          puVar4 = local_94;
        }
      }
      _Dst = (short *)param_1[0x89];
      puVar13 = puVar4;
LAB_c0128020:
      uVar15 = local_7c;
      puVar18 = local_88;
      puVar8 = puVar12;
      puVar4 = local_94;
      if (_Dst != (short *)0x0) {
        uVar10 = 0;
        local_9c = 0;
        local_74 = (uint *)0x0;
        if ((((local_8c == (uint *)0x0) || (puVar12 != (uint *)0x0)) ||
            ((int)local_7c <= (int)local_88 - (int)param_5 >> 4)) ||
           (((ushort)local_88[1] + 3 & 0xfffffffc) < 0xffd)) {
          puVar8 = local_88;
          if ((int)local_88 - (int)param_5 >> 4 < (int)local_7c) {
            do {
              param_2 = local_90;
              local_9c = uVar10;
              if (0xffc < (int)((((ushort)puVar8[1] + 3 & 0xfffffffc) - param_1[0x89]) + (int)_Dst))
              break;
              if ((ushort)puVar8[1] != 0) {
                FUN_c0126358(_Dst,(ushort *)puVar8);
                _Dst = (short *)(((ushort)puVar8[1] + 3 & 0xfffffffc) + (int)_Dst);
                uVar10 = uVar10 + 1 & 0xffff;
              }
              puVar8 = puVar8 + 4;
              param_2 = local_90;
              local_9c = uVar10;
            } while ((int)puVar8 - (int)param_5 >> 4 < (int)uVar15);
          }
        }
        else {
          uVar15 = FUN_c01261d8(_Dst,(short *)local_88);
          local_9c = 1;
          local_74 = (uint *)0x1;
          _Dst = (short *)((uVar15 + 3 & 0xfffc) + (int)_Dst);
          puVar8 = local_88;
          if (uVar15 < 0xffc) {
            puVar8 = puVar18 + 4;
          }
        }
        local_88 = puVar8;
        uVar10 = (int)_Dst - param_1[0x89];
        uVar17 = uVar10 & 0xffff;
        uVar15 = uVar17;
        if (((*(ushort *)(param_2 + 0x50) & 1) == 0) && (uVar17 != 1)) {
          if (uVar17 == 0) {
            uVar15 = 0;
            goto LAB_c01281e8;
          }
          uVar7 = StringCompress(param_1[0x89],uVar17,0,uVar17 - 1);
          if (((uVar7 == 0xffffffff) || (uVar7 == 0)) || (uVar17 <= uVar7)) goto LAB_c01281e8;
          uVar15 = uVar7 & 0xffff;
          uVar2 = 0x4000;
        }
        else {
LAB_c01281e8:
          uVar2 = 0x8000;
        }
        iVar14 = (local_9c - local_98[0]) + (uint)local_9e;
        if (iVar14 < 2) {
          iVar14 = 1;
        }
        uVar7 = (iVar14 + 2) * 4 + uVar15;
        if ((0xffff < uVar7) || ((local_8c == (uint *)0x0 && (0xfffb < uVar7)))) goto LAB_c0128894;
        uVar7 = uVar7 & 0xffff;
        if (local_8c == (uint *)0x0) {
          uVar7 = uVar7 + 4 & 0xffff;
        }
        if (puVar13 == (uint *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = 2;
        }
        iVar14 = 9;
        if (local_8c == (uint *)0x0) {
          iVar14 = 8;
        }
        puVar4 = FUN_c011daa0(param_1,iVar14,uVar7,uVar6);
        if (puVar4 == (uint *)0x0) goto LAB_c0128894;
        *(uint *)(param_2 + 0x5c) = (puVar4[-3] & 0xffffffc) + *(int *)(param_2 + 0x5c);
        puVar8 = puVar4;
        if (local_8c == (uint *)0x0) {
          *puVar4 = *(uint *)(param_2 + -4);
          puVar8 = puVar4 + 1;
          local_80 = puVar4;
        }
        if (puVar12 == (uint *)0x0) {
          *puVar8 = 0;
        }
        else {
          *puVar8 = *puVar12;
        }
        if (local_74 != (uint *)0x0) {
          puVar8[-3] = puVar8[-3] | 2;
        }
        *(ushort *)(puVar8 + 1) = uVar2 | (ushort)uVar10;
        *(short *)((int)puVar8 + 6) = (short)uVar15;
        if (uVar15 != 0) {
          puVar4 = puVar8 + 2;
          puVar18 = local_60;
          if (puVar12 != (uint *)0x0) {
            puVar11 = puVar12 + 2;
            if (local_9e != 0) {
              uVar10 = 0;
              do {
                if ((1 << (uVar10 & 0x1f) & local_58[uVar10 >> 5]) == 0) {
                  *puVar4 = *puVar11 & 0xfffffeff;
                  puVar4 = puVar4 + 1;
                }
                uVar10 = uVar10 + 1 & 0xffff;
                puVar11 = puVar11 + 1;
                puVar13 = local_94;
                param_2 = local_90;
              } while (uVar10 < local_9e);
            }
          }
          while (local_9c != 0) {
            if ((short)puVar18[1] != 0) {
              *puVar4 = *puVar18;
              puVar4 = puVar4 + 1;
              local_9c = local_9c + 0xffff & 0xffff;
            }
            puVar18 = puVar18 + 4;
          }
          puVar4[-1] = puVar4[-1] | 0x100;
          if (uVar2 == 0x4000) {
            StringCompress(param_1[0x89],uVar17,puVar4,uVar15);
          }
          else {
            memcpy(puVar4,(void *)param_1[0x89],uVar17);
          }
        }
        puVar18 = local_8c;
        if (local_8c != (uint *)0x0) {
          FUN_c01029e4((int)param_1,1,local_8c,*local_8c,4);
          *puVar18 = puVar8[-1];
        }
        puVar4 = puVar13;
        if ((puVar12 != (uint *)0x0) && (puVar18 != (uint *)0x0)) {
          FUN_c01029e4((int)param_1,1,puVar12,*puVar12,4);
          *puVar12 = local_84;
          local_84 = puVar12[-1];
        }
      }
LAB_c0128488:
      local_8c = puVar8;
      if (puVar8 == (uint *)0x0) goto LAB_c0128894;
      if (((*puVar8 == 0) ||
          (puVar12 = (uint *)FUN_c0101c94((int)param_1,*puVar8), puVar12 == (uint *)0x0)) ||
         ((puVar12[-3] & 0xf0000000) != 0x90000000)) {
        puVar12 = (uint *)0x0;
      }
      bVar1 = false;
    } while( true );
  }
  goto LAB_c01288a8;
LAB_c01284ec:
  do {
    iVar14 = uVar15 * 0x40 + param_2;
    if ((*(uint *)(iVar14 + 0x74) & 0x80000000) != 0) {
      uVar17 = (uint)*(ushort *)(param_2 + 0x4e);
      uVar10 = 1 << (uVar15 + 8 & 0x1f);
      if ((uVar17 & uVar10) == 0) {
        FUN_c01029e4((int)param_1,1,(ushort *)(param_2 + 0x4e),uVar10 & 0xffff | uVar17,2);
        iVar14 = FUN_c012dcf4(param_1,iVar14 + 100,puVar4[-1],0,0,&local_84,param_1 + 0x89);
        if (iVar14 == 0) goto LAB_c0128894;
      }
    }
    uVar15 = uVar15 + 1 & 0xffff;
  } while (uVar15 < *(ushort *)(param_2 + 0x4c));
LAB_c0128590:
  if (*(short *)(param_2 + 0x4c) != 0) {
    puVar16 = (ushort *)(param_2 + 0x4e);
    uVar15 = 0;
    do {
      uVar10 = 1 << (uVar15 + 8 & 0x1f);
      iVar14 = 0;
      bVar1 = false;
      if ((*puVar16 & uVar10) == 0) {
        FUN_c01029e4((int)param_1,1,puVar16,uVar10 & 0xffff | (uint)*puVar16,2);
        uVar10 = 0;
        if ((param_4 & 0xffff) != 0) {
          do {
            iVar3 = local_90;
            puVar4 = local_94;
            if (bVar1) goto LAB_c0128724;
            if ((1 << (uVar15 + 0xc & 0x1f) & (uint)*(ushort *)((int)param_5 + uVar10 * 0x10 + 6))
                != 0) {
              iVar5 = FUN_c01273c4((int)param_1,local_90,(int)local_80,
                                   uVar15 * 0x40 + local_90 + 100,local_58,local_98,(int *)&local_78
                                   ,&local_70);
              if (iVar5 != 0) {
                puVar12 = local_94;
                if (local_94 == (uint *)0x0) {
                  puVar12 = local_80;
                }
                bVar1 = FUN_c012dbfc((int)param_1,iVar3,uVar15,(int)local_58,local_98[0],puVar12[-1]
                                    );
                iVar14 = CONCAT31(extraout_var_00,bVar1);
              }
              bVar1 = true;
            }
            uVar10 = uVar10 + 1 & 0xffff;
          } while (uVar10 < (param_4 & 0xffff));
          puVar4 = local_94;
          if (bVar1) goto LAB_c0128724;
        }
        puVar4 = local_94;
        if ((local_94 == (uint *)0x0) && (local_80 != (uint *)0x0)) {
          bVar1 = FUN_c012dbfc((int)param_1,local_90,uVar15,0,0,local_80[-1]);
          iVar14 = CONCAT31(extraout_var_01,bVar1);
          bVar1 = true;
        }
      }
LAB_c0128724:
      param_2 = local_90;
      iVar3 = uVar15 * 0x40 + local_90;
      FUN_c01029e4((int)param_1,1,uVar15 * 0x40 + local_90 + 0x74,*(undefined4 *)(iVar3 + 0x74),4);
      *(uint *)(iVar3 + 0x74) = *(uint *)(iVar3 + 0x74) & 0x7fffffff;
      if ((bVar1) && (iVar14 == 0)) {
        FUN_c010297c((int)param_1);
        *puVar16 = *puVar16 | 0xff00;
        FUN_c0102aa4(param_1);
        goto LAB_c0128894;
      }
      uVar15 = uVar15 + 1 & 0xffff;
    } while (uVar15 < *(ushort *)(param_2 + 0x4c));
  }
  puVar12 = local_80;
  if ((puVar4 != (uint *)0x0) && (local_80 != puVar4)) {
    *(uint *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) - (puVar4[-3] & 0xffffffc);
    FUN_c0103a9c(param_1,local_80[-1],puVar4[-1]);
  }
  if (local_84 != 0) {
    if (((*(uint *)(param_1[2] + 0xec) == 0xffffffff) ||
        (uVar15 = FUN_c0101c94((int)param_1,*(uint *)(param_1[2] + 0xec)), uVar15 == 0)) ||
       ((*(uint *)(uVar15 - 0xc) & 0xf0000000) != 0xa0000000)) {
      uVar15 = 0;
    }
    puVar16 = (ushort *)(param_2 + 0x4e);
    FUN_c01029e4((int)param_1,1,puVar16,(uint)*puVar16,2);
    *puVar16 = *puVar16 | 0x20;
    if (uVar15 != 0) {
      puVar8 = (uint *)(uVar15 + 8);
      FUN_c01029e4((int)param_1,1,puVar8,*puVar8,4);
      *puVar8 = local_84;
    }
  }
  if (puVar12 == (uint *)0x0) {
    SetLastError(0x57);
  }
  local_68 = puVar12;
LAB_c0128894:
  if (local_78 != (HLOCAL)0x0) {
    LocalFree(local_78);
  }
LAB_c01288a8:
  if (local_6c != (HLOCAL)0x0) {
    LocalFree(local_6c);
  }
  return local_68;
}



/* c0128914 FUN_c0128914 */

/* Boundary evidence: original MIPS .pdata c0128914..c0128c73. Semantic name remains unreviewed. */

uint FUN_c0128914(int param_1,uint param_2,ushort *param_3,int param_4,int *param_5,uint *param_6,
                 undefined4 param_7)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  DWORD dwErrCode;
  undefined4 *puVar5;
  uint local_44;
  uint auStack_38 [4];
  
  local_44 = 0;
  if ((param_2 & 1) != 0) {
    SetLastError(0x32);
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar1 = IsProcessDying();
  if (iVar1 != 0) {
    SetLastError(0x10dc);
    goto LAB_c0128c20;
  }
  puVar5 = *(undefined4 **)(param_1 + 0x10);
  if (puVar5 == (undefined4 *)0x0) goto LAB_c0128c20;
  EnterCriticalSection((LPCRITICAL_SECTION)puVar5[0x87]);
  if (*(int *)(param_1 + 0x38) == 0) {
    if (*(uint *)(param_1 + 0x1c) == 0) {
      dwErrCode = 0x103;
    }
    else {
      puVar2 = (uint *)FUN_c0101c94((int)puVar5,*(uint *)(param_1 + 0x1c));
      if ((puVar2 == (uint *)0x0) || ((puVar2[-3] & 0xf0000000) != 0x80000000)) {
        puVar2 = (uint *)0x0;
      }
      if (puVar2 != (uint *)0x0) {
        iVar1 = FUN_c0126bfc((int)puVar5,(int)puVar2,param_2,param_3,param_4,param_5,param_6,param_7
                             ,0);
        if (iVar1 != 0) {
          if ((*(uint *)(param_1 + 0xc) & 1) != 0) {
            uVar3 = FUN_c0101c94((int)puVar5,*puVar2);
            if ((uVar3 == 0) || ((*(uint *)(uVar3 - 0xc) & 0xf0000000) != 0x70000000)) {
              uVar3 = 0;
            }
            if (uVar3 == 0) goto LAB_c0128a6c;
            if (((1 << (*(ushort *)(param_1 + 0x24) + 8 & 0x1f) & (uint)*(ushort *)(uVar3 + 0x4e))
                 != 0) && (iVar1 = FUN_c012d470(puVar5,uVar3), iVar1 == 0)) {
              dwErrCode = 0x70;
              goto LAB_c0128a18;
            }
            puVar4 = FUN_c012d5d8(auStack_38,(int)puVar5,uVar3,
                                  (uint)*(ushort *)(param_1 + 0x24) * 0x40 + uVar3 + 100,8,1,
                                  (uint *)(param_1 + 0x18),(void *)0x0);
            *(uint *)(param_1 + 0x18) = *puVar4;
            *(uint *)(param_1 + 0x1c) = puVar4[1];
            *(uint *)(param_1 + 0x20) = puVar4[2];
          }
          local_44 = FUN_c0101ea4((int)puVar5,puVar2[-1]);
        }
        goto LAB_c0128bb0;
      }
LAB_c0128a6c:
      dwErrCode = 0x57;
    }
LAB_c0128a18:
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(0x3fa);
  }
LAB_c0128bb0:
  LeaveCriticalSection((LPCRITICAL_SECTION)puVar5[0x87]);
LAB_c0128c20:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  return local_44;
}



/* c0128c74 FUN_c0128c74 */

/* Boundary evidence: original MIPS .pdata c0128c74..c0128c7f. Semantic name remains unreviewed. */

undefined4 FUN_c0128c74(void)

{
  return 1;
}



/* c0128c80 FUN_c0128c80 */

/* Boundary evidence: original MIPS .pdata c0128c80..c0128c8b. Semantic name remains unreviewed. */

undefined4 FUN_c0128c80(void)

{
  return 1;
}



/* c0128c8c FUN_c0128c8c */

/* Boundary evidence: original MIPS .pdata c0128c8c..c0128c97. Semantic name remains unreviewed. */

undefined4 FUN_c0128c8c(void)

{
  return 1;
}



/* c0128c98 FUN_c0128c98 */

/* Boundary evidence: original MIPS .pdata c0128c98..c0128d73. Semantic name remains unreviewed. */

uint FUN_c0128c98(int param_1,uint param_2,int param_3,uint param_4,int param_5,undefined4 param_6,
                 undefined4 param_7,int param_8,undefined4 param_9)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  uint *puVar5;
  ushort local_20 [4];
  
  iVar3 = param_8;
  puVar4 = local_20;
  local_20[0] = (ushort)(param_4 >> 2);
  if (param_5 == 0) {
    puVar4 = (ushort *)0x0;
  }
  puVar5 = &param_7;
  if (param_8 == 0) {
    puVar5 = (uint *)0x0;
  }
  uVar1 = FUN_c0128914(param_1,param_2,puVar4,param_3,&param_6,puVar5,param_9);
  if (((param_5 != 0) && (iVar2 = CeSafeCopyMemory(param_5,puVar4,2), iVar2 == 0)) ||
     ((iVar3 != 0 && (iVar3 = CeSafeCopyMemory(iVar3,puVar5,4), iVar3 == 0)))) {
    SetLastError(0x57);
    uVar1 = 0;
  }
  return uVar1;
}



/* c0128d74 FUN_c0128d74 */

/* Boundary evidence: original MIPS .pdata c0128d74..c0128e53. Semantic name remains unreviewed. */

uint FUN_c0128d74(int param_1,uint param_2,int param_3,uint param_4,int param_5,undefined4 param_6,
                 undefined4 param_7,int param_8,undefined4 param_9)

{
  int iVar1;
  uint uVar2;
  int local_20 [2];
  
  local_20[0] = 0;
  if ((param_3 == 0) || (iVar1 = CeAllocDuplicateBuffer(local_20,param_3,param_4,4), -1 < iVar1)) {
    uVar2 = FUN_c0128c98(param_1,param_2,local_20[0],param_4,param_5,param_6,param_7,param_8,param_9
                        );
    if (local_20[0] != 0) {
      CeFreeDuplicateBuffer(local_20[0],param_3,param_4,4);
    }
  }
  else {
    SetLastError(0xe);
    uVar2 = 0;
  }
  return uVar2;
}



/* c0128e54 FUN_c0128e54 */

/* Boundary evidence: original MIPS .pdata c0128e54..c0128f57. Semantic name remains unreviewed. */

uint * FUN_c0128e54(undefined4 *param_1,int param_2,uint *param_3,uint param_4,uint *param_5,
                   int param_6)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  
  puVar1 = FUN_c01279cc(param_1,param_2,param_3,param_4,param_5,param_6);
  if (puVar1 == (uint *)0x0) {
    puVar1 = (uint *)0x0;
  }
  else {
    if (param_3 == (uint *)0x0) {
      piVar3 = (int *)(param_2 + 0x48);
      FUN_c01029e4((int)param_1,1,piVar3,*piVar3,4);
      *piVar3 = *piVar3 + 1;
    }
    if (0 < (int)param_4) {
      puVar2 = param_5 + 1;
      do {
        *(undefined2 *)puVar2 = 0;
        *(ushort *)((int)puVar2 + 2) = *(ushort *)((int)puVar2 + 2) & 0xf00;
        puVar2 = puVar2 + 4;
      } while ((-4 - (int)param_5) + (int)puVar2 >> 4 < (int)param_4);
    }
  }
  return puVar1;
}



/* c0128f58 FUN_c0128f58 */

/* Boundary evidence: original MIPS .pdata c0128f58..c0129447. Semantic name remains unreviewed. */

uint FUN_c0128f58(int param_1,uint param_2,uint param_3,uint *param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  DWORD dwErrCode;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint *puVar9;
  undefined4 *local_58;
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined1 auStack_44 [16];
  uint local_34;
  uint local_30;
  
  uVar6 = 0;
  local_58 = (undefined4 *)0x0;
  uVar3 = param_2;
  uVar5 = param_3;
  puVar4 = param_4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  iVar2 = IsProcessDying();
  if (iVar2 != 0) {
    SetLastError(0x10dc);
    goto LAB_c01293dc;
  }
  puVar8 = *(undefined4 **)(param_1 + 0x10);
  if (puVar8 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)puVar8[0x87]);
    puVar9 = (uint *)0x0;
    bVar1 = false;
    if ((*(ushort *)((int)puVar8 + 0x24e) & 0x20) == 0) {
      if ((puVar8 != &DAT_c01391e0) && (iVar2 = FUN_c0123ad4(puVar8,uVar3,uVar5,puVar4), iVar2 == 0)
         ) goto LAB_c01291e0;
      uVar3 = FUN_c0101c94((int)puVar8,*(uint *)(param_1 + 0x14));
      if ((uVar3 == 0) || ((*(uint *)(uVar3 - 0xc) & 0xf0000000) != 0x70000000)) {
        uVar3 = 0;
      }
      if (uVar3 == 0) {
        dwErrCode = 0x57;
LAB_c01290ac:
        SetLastError(dwErrCode);
        goto LAB_c01291e0;
      }
      if (param_2 == 0) {
LAB_c0129134:
        if (*(int *)(uVar3 + 0x48) == 0xffff) {
          dwErrCode = 0x10da;
          goto LAB_c01290ac;
        }
      }
      else {
        puVar9 = (uint *)FUN_c0101de8((int)puVar8,param_2);
        if ((puVar9 == (uint *)0x0) || ((puVar9[-3] & 0xf0000000) != 0x80000000)) {
          puVar9 = (uint *)0x0;
        }
        if ((puVar9 == (uint *)0x0) || (*puVar9 != *(uint *)(param_1 + 0x14))) {
          SetLastError(0x57);
          goto LAB_c01291e0;
        }
        if (param_2 == 0) goto LAB_c0129134;
      }
      if ((puVar9 != (uint *)0x0) && (iVar2 = FUN_c0104fd0(), iVar2 == 0)) goto LAB_c01291e0;
      FUN_c010297c((int)puVar8);
      bVar1 = true;
      FUN_c01029e4((int)puVar8,1,(undefined4 *)(uVar3 + 0x5c),*(undefined4 *)(uVar3 + 0x5c),4);
      puVar4 = FUN_c0128e54(puVar8,uVar3,puVar9,param_3 & 0xffff,param_4,param_5);
      if (puVar4 == (uint *)0x0) goto LAB_c01291e0;
      FUN_c01029e4((int)puVar8,1,puVar4 + -2,puVar4[-2],4);
      FUN_c0104fd8(puVar8,(int)(puVar4 + -3));
      FUN_c01029e4((int)puVar8,1,(undefined4 *)(uVar3 + 0x58),*(undefined4 *)(uVar3 + 0x58),4);
      puVar7 = (undefined4 *)(uVar3 + 0x54);
      FUN_c01029e4((int)puVar8,1,puVar7,*puVar7,4);
      GetCurrentFT(puVar7);
      FUN_c0102aa4(puVar8);
      if ((*(ushort *)(uVar3 + 0x4e) & 0x20) != 0) {
        FUN_c0120aac(puVar8,uVar3);
      }
      uVar6 = FUN_c0101ea4((int)puVar8,puVar4[-1]);
      local_50[0] = 0x24;
      local_48 = 0x406;
      if (param_2 == 0) {
        local_48 = 0x401;
      }
      if ((puVar8 == &DAT_c01391e0) || (puVar8 == (undefined4 *)PTR_DAT_c0136c70)) {
        memset(auStack_44,0,0x10);
      }
      else {
        memcpy(auStack_44,(void *)(puVar8[2] + 0xc),0x10);
      }
      local_34 = uVar6;
      local_30 = FUN_c0101ea4((int)puVar8,*(uint *)(param_1 + 0x14));
      FUN_c011d9f8(puVar8);
    }
    else {
      SetLastError(5);
LAB_c01291e0:
      if (bVar1) {
        FUN_c01036ac(puVar8);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)puVar8[0x87]);
  }
  if (uVar6 != 0) {
    local_58 = FUN_c0126904(param_1,(int)local_50);
  }
LAB_c01293dc:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0139480);
  if (uVar6 != 0) {
    FUN_c0126818(local_58,local_50);
  }
  return uVar6;
}



/* c0129448 FUN_c0129448 */

/* Boundary evidence: original MIPS .pdata c0129448..c0129453. Semantic name remains unreviewed. */

undefined4 FUN_c0129448(void)

{
  return 1;
}



/* c0129454 FUN_c0129454 */

/* Boundary evidence: original MIPS .pdata c0129454..c012945f. Semantic name remains unreviewed. */

undefined4 FUN_c0129454(void)

{
  return 1;
}



/* c0129460 FUN_c0129460 */

/* Boundary evidence: original MIPS .pdata c0129460..c012946b. Semantic name remains unreviewed. */

undefined4 FUN_c0129460(void)

{
  return 1;
}



/* c012946c FUN_c012946c */

/* Boundary evidence: original MIPS .pdata c012946c..c0129497. Semantic name remains unreviewed. */

void FUN_c012946c(int param_1,uint param_2,uint *param_3,uint param_4)

{
  FUN_c0128f58(param_1,param_2,param_4 >> 4 & 0xffff,param_3,0);
  return;
}



/* c0129498 FUN_c0129498 */

/* Boundary evidence: original MIPS .pdata c0129498..c0129563. Semantic name remains unreviewed. */

uint FUN_c0129498(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *local_20 [2];
  
  local_20[0] = (uint *)0x0;
  uVar3 = param_4 >> 4 & 0xffff;
  if (((param_3 == 0) || (uVar3 == 0)) ||
     (iVar1 = CeAllocDuplicateBuffer(local_20,param_3,uVar3 << 4,4), -1 < iVar1)) {
    uVar2 = FUN_c0128f58(param_1,param_2,uVar3,local_20[0],1);
    CeFreeDuplicateBuffer(local_20[0],param_3,uVar3 << 4,4);
  }
  else {
    SetLastError(0xe);
    uVar2 = 0;
  }
  return uVar2;
}



/* c01295a8 FUN_c01295a8 */

/* Boundary evidence: original MIPS .pdata c01295a8..c0129627. Semantic name remains unreviewed. */

void FUN_c01295a8(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 ushort param_6,int param_7,undefined *param_8)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (*(code *)param_8)(param_2,param_3,param_4);
  uVar2 = iVar1 + param_5 + param_7 + *param_1;
  *param_1 = (uVar2 >> (0x20 - param_6 & 0x1f) | uVar2 << (param_6 & 0x1f)) + param_2;
  return;
}



/* c0129628 FUN_c0129628 */

/* Boundary evidence: original MIPS .pdata c0129628..c012a447. Semantic name remains unreviewed. */

void FUN_c0129628(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  local_38 = *param_1;
  iVar4 = param_1[1];
  iVar3 = param_1[2];
  local_34 = param_1[3];
  local_30 = iVar3;
  local_2c = iVar4;
  FUN_c01295a8(&local_38,iVar4,iVar3,local_34,*param_2,7,-0x28955b88,&LAB_c0129564);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar4,iVar3,param_2[1],0xc,-0x173848aa,&LAB_c0129564);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar4,param_2[2],0x11,0x242070db,&LAB_c0129564);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[3],0x16,-0x3e423112,&LAB_c0129564);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[4],7,-0xa83f051,&LAB_c0129564);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[5],0xc,0x4787c62a,&LAB_c0129564);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[6],0x11,-0x57cfb9ed,&LAB_c0129564);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[7],0x16,-0x2b96aff,&LAB_c0129564);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[8],7,0x698098d8,&LAB_c0129564);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[9],0xc,-0x74bb0851,&LAB_c0129564);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[10],0x11,-0xa44f,&LAB_c0129564);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[0xb],0x16,-0x76a32842,&LAB_c0129564);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[0xc],7,0x6b901122,&LAB_c0129564);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[0xd],0xc,-0x2678e6d,&LAB_c0129564);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[0xe],0x11,-0x5986bc72,&LAB_c0129564);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[0xf],0x16,0x49b40821,&LAB_c0129564);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[1],5,-0x9e1da9e,&LAB_c0129578);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[6],9,-0x3fbf4cc0,&LAB_c0129578);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[0xb],0xe,0x265e5a51,&LAB_c0129578);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,*param_2,0x14,-0x16493856,&LAB_c0129578);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[5],5,-0x29d0efa3,&LAB_c0129578);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[10],9,0x2441453,&LAB_c0129578);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[0xf],0xe,-0x275e197f,&LAB_c0129578);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[4],0x14,-0x182c0438,&LAB_c0129578);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[9],5,0x21e1cde6,&LAB_c0129578);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[0xe],9,-0x3cc8f82a,&LAB_c0129578);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[3],0xe,-0xb2af279,&LAB_c0129578);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[8],0x14,0x455a14ed,&LAB_c0129578);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[0xd],5,-0x561c16fb,&LAB_c0129578);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[2],9,-0x3105c08,&LAB_c0129578);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[7],0xe,0x676f02d9,&LAB_c0129578);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[0xc],0x14,-0x72d5b376,&LAB_c0129578);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[5],4,-0x5c6be,&LAB_c012958c);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[8],0xb,-0x788e097f,&LAB_c012958c);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[0xb],0x10,0x6d9d6122,&LAB_c012958c);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[0xe],0x17,-0x21ac7f4,&LAB_c012958c);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[1],4,-0x5b4115bc,&LAB_c012958c);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[4],0xb,0x4bdecfa9,&LAB_c012958c);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[7],0x10,-0x944b4a0,&LAB_c012958c);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[10],0x17,-0x41404390,&LAB_c012958c);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[0xd],4,0x289b7ec6,&LAB_c012958c);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,*param_2,0xb,-0x155ed806,&LAB_c012958c);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[3],0x10,-0x2b10cf7b,&LAB_c012958c);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[6],0x17,0x4881d05,&LAB_c012958c);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[9],4,-0x262b2fc7,&LAB_c012958c);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[0xc],0xb,-0x1924661b,&LAB_c012958c);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[0xf],0x10,0x1fa27cf8,&LAB_c012958c);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[2],0x17,-0x3b53a99b,&LAB_c012958c);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,*param_2,6,-0xbd6ddbc,&LAB_c0129598);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[7],10,0x432aff97,&LAB_c0129598);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[0xe],0xf,-0x546bdc59,&LAB_c0129598);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[5],0x15,-0x36c5fc7,&LAB_c0129598);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[0xc],6,0x655b59c3,&LAB_c0129598);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[3],10,-0x70f3336e,&LAB_c0129598);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[10],0xf,-0x100b83,&LAB_c0129598);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[1],0x15,-0x7a7ba22f,&LAB_c0129598);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[8],6,0x6fa87e4f,&LAB_c0129598);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[0xf],10,-0x1d31920,&LAB_c0129598);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[6],0xf,-0x5cfebcec,&LAB_c0129598);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[0xd],0x15,0x4e0811a1,&LAB_c0129598);
  iVar2 = local_2c;
  FUN_c01295a8(&local_38,local_2c,iVar4,iVar3,param_2[4],6,-0x8ac817e,&LAB_c0129598);
  iVar1 = local_38;
  FUN_c01295a8(&local_34,local_38,iVar2,iVar4,param_2[0xb],10,-0x42c50dcb,&LAB_c0129598);
  iVar3 = local_34;
  FUN_c01295a8(&local_30,local_34,iVar1,iVar2,param_2[2],0xf,0x2ad7d2bb,&LAB_c0129598);
  iVar4 = local_30;
  FUN_c01295a8(&local_2c,local_30,iVar3,iVar1,param_2[9],0x15,-0x14792c6f,&LAB_c0129598);
  *param_1 = *param_1 + iVar1;
  param_1[1] = param_1[1] + local_2c;
  param_1[2] = param_1[2] + iVar4;
  param_1[3] = iVar3 + param_1[3];
  return;
}



/* c012a448 FUN_c012a448 */

/* Boundary evidence: original MIPS .pdata c012a448..c012a513. Semantic name remains unreviewed. */

void FUN_c012a448(uint *param_1,undefined1 *param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint local_58 [16];
  
  uVar2 = *param_1;
  uVar4 = param_3 * 8 + uVar2;
  uVar5 = uVar2 >> 3 & 0x3f;
  if (uVar4 < uVar2) {
    param_1[1] = param_1[1] + 1;
  }
  *param_1 = uVar4;
  if (param_3 != 0) {
    do {
      param_3 = param_3 + -1;
      *(undefined1 *)((int)(param_1 + 6) + uVar5) = *param_2;
      uVar5 = uVar5 + 1;
      param_2 = param_2 + 1;
      if (uVar5 == 0x40) {
        puVar1 = local_58;
        puVar3 = param_1 + 6;
        do {
          *puVar1 = *puVar3;
          puVar1 = puVar1 + 1;
          puVar3 = puVar3 + 1;
        } while (puVar1 != (uint *)&stack0xffffffe8);
        FUN_c0129628((int *)(param_1 + 2),(int *)local_58);
        uVar5 = 0;
      }
    } while (param_3 != 0);
  }
  return;
}



/* c012a514 FUN_c012a514 */

/* Boundary evidence: original MIPS .pdata c012a514..c012a5fb. Semantic name remains unreviewed. */

void FUN_c012a514(uint *param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint local_98 [14];
  uint local_60;
  uint local_5c;
  undefined1 local_58;
  undefined1 auStack_57 [63];
  uint local_18;
  
  local_18 = DAT_c0136c78;
  local_58 = 0x80;
  memset(auStack_57,0,0x3f);
  local_60 = *param_1;
  local_5c = param_1[1];
  uVar4 = local_60 >> 3 & 0x3f;
  if (uVar4 < 0x38) {
    iVar2 = 0x38 - uVar4;
  }
  else {
    iVar2 = 0x78 - uVar4;
  }
  FUN_c012a448(param_1,&local_58,iVar2);
  puVar3 = local_98;
  puVar1 = param_1 + 6;
  do {
    *puVar3 = *puVar1;
    puVar3 = puVar3 + 1;
    puVar1 = puVar1 + 1;
  } while (puVar3 != &local_60);
  puVar1 = param_1 + 2;
  FUN_c0129628((int *)puVar1,(int *)local_98);
  iVar2 = 4;
  do {
    *param_2 = *puVar1;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
    param_2 = param_2 + 1;
  } while (iVar2 != 0);
  FUN_c013331c(local_18);
  return;
}



/* c012a5fc FUN_c012a5fc */

/* Boundary evidence: original MIPS .pdata c012a5fc..c012a6a7. Semantic name remains unreviewed. */

undefined4 FUN_c012a5fc(wchar_t *param_1,uint *param_2)

{
  size_t sVar1;
  uint auStack_70 [2];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_18;
  
  local_18 = DAT_c0136c78;
  memset(auStack_70,0,0x58);
  local_68 = 0x67452301;
  local_64 = 0xefcdab89;
  local_60 = 0x98badcfe;
  local_5c = 0x10325476;
  sVar1 = wcslen(param_1);
  FUN_c012a448(auStack_70,(undefined1 *)param_1,(sVar1 + 1) * 2);
  FUN_c012a514(auStack_70,param_2);
  FUN_c013331c(local_18);
  return 1;
}



/* c012a6a8 FUN_c012a6a8 */

undefined4 FUN_c012a6a8(uint param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + param_2;
  *param_5 = 0xffffffff;
  if (param_1 <= uVar1) {
    uVar2 = uVar1 + param_3;
    *param_5 = uVar1;
    *param_5 = 0xffffffff;
    if (uVar1 <= uVar2) {
      *param_5 = 0xffffffff;
      if (uVar2 <= uVar2 + param_4) {
        *param_5 = uVar2 + param_4;
        return 0;
      }
    }
  }
  return 0xc0000095;
}



/* c012a708 FUN_c012a708 */

/* Boundary evidence: original MIPS .pdata c012a708..c012a86b. Semantic name remains unreviewed. */

undefined4 FUN_c012a708(void)

{
  LONG LVar1;
  LSTATUS LVar2;
  DWORD local_30;
  undefined4 local_2c;
  DWORD local_28 [2];
  
  local_30 = 4;
  LVar1 = InterlockedIncrement((LONG *)&DAT_c013710c);
  if (LVar1 == 1) {
    local_2c = 0;
    LVar2 = RegQueryValueExW((HKEY)&DAT_80000002,L"NoEncryption",(LPDWORD)L"init\\BootVars",local_28
                             ,(LPBYTE)&local_2c,&local_30);
    if (LVar2 == 0) {
      DAT_c0137104 = local_2c;
    }
    local_30 = 0x208;
    LVar2 = RegQueryValueExW((HKEY)&DAT_80000002,L"MasterKeyFileDir",(LPDWORD)L"init\\BootVars",
                             local_28,(LPBYTE)&DAT_c0136ed4,&local_30);
    if ((LVar2 == 0) && (local_28[0] == 1)) {
      DAT_c01370da = 0;
    }
    local_2c = 0;
    local_30 = 4;
    LVar2 = RegQueryValueExW((HKEY)&DAT_80000002,L"MasterKeysInRegistry",(LPDWORD)L"init\\BootVars",
                             local_28,(LPBYTE)&local_2c,&local_30);
    if (LVar2 == 0) {
      DAT_c0137108 = local_2c;
    }
  }
  else {
    InterlockedDecrement((LONG *)&DAT_c013710c);
  }
  return 1;
}



/* c012a86c FUN_c012a86c */

/* Boundary evidence: original MIPS .pdata c012a86c..c012a9eb. Semantic name remains unreviewed. */

wchar_t * FUN_c012a86c(wchar_t *param_1)

{
  longlong lVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  wchar_t *_Dest;
  uint local_f0 [2];
  wchar_t awStack_e8 [99];
  undefined2 local_22;
  uint local_20;
  
  local_20 = DAT_c0136c78;
  if (DAT_c0136ed4 == 0) {
    wcscpy(awStack_e8,L"\\Windows\\");
    FUN_c01131b0(awStack_e8,100);
  }
  else {
    wcsncpy(awStack_e8,&DAT_c0136ed4,100);
    local_22 = 0;
  }
  sVar2 = wcslen(awStack_e8);
  if (param_1 == (wchar_t *)0x0) {
    param_1 = L"System";
  }
  sVar3 = wcslen(param_1);
  iVar4 = FUN_c012a6a8(sVar2,1,sVar3,4,local_f0);
  if (((iVar4 < 0) || (local_f0[0] + 1 < local_f0[0])) ||
     (lVar1 = (ulonglong)(local_f0[0] + 1) * 2, (int)((ulonglong)lVar1 >> 0x20) != 0)) {
    FUN_c013331c(local_20);
    _Dest = (wchar_t *)0x0;
  }
  else {
    _Dest = LocalAlloc(0x40,(SIZE_T)lVar1);
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,awStack_e8);
      if (_Dest[sVar2 - 1] != L'\\') {
        wcscat(_Dest,L"\\");
      }
      wcscat(_Dest,param_1);
      wcscat(_Dest,L".mky");
    }
    FUN_c013331c(local_20);
  }
  return _Dest;
}



/* c012a9ec FUN_c012a9ec */

/* Boundary evidence: original MIPS .pdata c012a9ec..c012aa7b. Semantic name remains unreviewed. */

wchar_t * FUN_c012a9ec(wchar_t *param_1)

{
  size_t sVar1;
  wchar_t *_Dest;
  
  if (param_1 == (wchar_t *)0x0) {
    param_1 = L"System";
  }
  sVar1 = wcslen(param_1);
  _Dest = LocalAlloc(0x40,(sVar1 + 0x12) * 2);
  if (_Dest != (wchar_t *)0x0) {
    wcscpy(_Dest,L"System\\DPAPIKeys");
    wcscat(_Dest,L"\\");
    wcscat(_Dest,param_1);
  }
  return _Dest;
}



/* c012aa7c FUN_c012aa7c */

/* Boundary evidence: original MIPS .pdata c012aa7c..c012ac1f. Semantic name remains unreviewed. */

bool FUN_c012aa7c(wchar_t *param_1,BYTE *param_2)

{
  wchar_t *lpFileName;
  LSTATUS LVar1;
  HKEY hFile;
  BOOL BVar2;
  code *pcVar3;
  bool bVar4;
  HKEY local_20;
  DWORD DStack_1c;
  
  bVar4 = false;
  if (DAT_c0137108 == 0) {
    lpFileName = FUN_c012a86c(param_1);
    if (lpFileName == (wchar_t *)0x0) {
      return false;
    }
    hFile = CreateFileW(lpFileName,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,6,(HANDLE)0x0);
    if (hFile == (HKEY)0xffffffff) goto LAB_c012abf8;
    local_20 = (HKEY)0x34;
    BVar2 = WriteFile(hFile,param_2,0x34,(LPDWORD)&local_20,(LPOVERLAPPED)0x0);
    pcVar3 = CloseHandle_exref;
    if ((BVar2 == 0) || (local_20 != (HKEY)0x34)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
  }
  else {
    lpFileName = FUN_c012a9ec(param_1);
    if (lpFileName == (wchar_t *)0x0) {
      return false;
    }
    LVar1 = RegCreateKeyExW((HKEY)&DAT_80000002,lpFileName,0,(LPWSTR)0x0,0,0,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_20,&DStack_1c);
    if (LVar1 != 0) goto LAB_c012abf8;
    LVar1 = RegSetValueExW(local_20,(LPCWSTR)0x0,0,3,param_2,0x34);
    bVar4 = LVar1 == 0;
    hFile = local_20;
    pcVar3 = RegCloseKey_exref;
  }
  (*pcVar3)(hFile);
LAB_c012abf8:
  LocalFree(lpFileName);
  return bVar4;
}



/* c012ac20 FUN_c012ac20 */

/* Boundary evidence: original MIPS .pdata c012ac20..c012add3. Semantic name remains unreviewed. */

undefined4 FUN_c012ac20(wchar_t *param_1,LPBYTE param_2)

{
  wchar_t *lpFileName;
  LSTATUS LVar1;
  HKEY hFile;
  BOOL BVar2;
  code *pcVar3;
  undefined4 uVar4;
  DWORD local_28;
  HKEY local_24;
  DWORD local_20 [2];
  
  uVar4 = 0;
  if (DAT_c0137108 == 0) {
    lpFileName = FUN_c012a86c(param_1);
    if (lpFileName == (wchar_t *)0x0) {
      return 0;
    }
    hFile = CreateFileW(lpFileName,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,6,(HANDLE)0x0);
    if (hFile == (HKEY)0xffffffff) goto LAB_c012ada8;
    local_24 = (HKEY)0x34;
    BVar2 = ReadFile(hFile,param_2,0x34,(LPDWORD)&local_24,(LPOVERLAPPED)0x0);
    pcVar3 = CloseHandle_exref;
    if ((BVar2 == 0) || (uVar4 = 1, local_24 != (HKEY)0x34)) {
      uVar4 = 0;
    }
  }
  else {
    lpFileName = FUN_c012a9ec(param_1);
    if (lpFileName == (wchar_t *)0x0) {
      return 0;
    }
    LVar1 = RegOpenKeyExW((HKEY)&DAT_80000002,lpFileName,0,0,&local_24);
    if (LVar1 != 0) goto LAB_c012ada8;
    local_28 = 0x34;
    LVar1 = RegQueryValueExW(local_24,(LPCWSTR)0x0,(LPDWORD)0x0,local_20,param_2,&local_28);
    hFile = local_24;
    pcVar3 = RegCloseKey_exref;
    if (((LVar1 == 0) && (local_20[0] == 3)) && (local_28 == 0x34)) {
      uVar4 = 1;
    }
  }
  (*pcVar3)(hFile);
LAB_c012ada8:
  LocalFree(lpFileName);
  return uVar4;
}



/* c012add4 FUN_c012add4 */

/* Boundary evidence: original MIPS .pdata c012add4..c012b03b. Semantic name remains unreviewed. */

uint FUN_c012add4(wchar_t *param_1,undefined4 param_2,undefined4 param_3,void *param_4,int *param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined1 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 local_78;
  undefined4 local_74;
  undefined2 local_70;
  ushort local_6e;
  undefined2 local_6c;
  undefined1 local_6a;
  undefined1 local_69;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [24];
  undefined1 local_38 [20];
  uint local_24;
  
  local_24 = DAT_c0136c78;
  iVar8 = 0x34;
  memset(&local_70,0,0x34);
  memcpy(auStack_60,param_4,0x10);
  local_70 = (**(code **)(*param_5 + 0x34))(param_5);
  local_6a = 8;
  local_6e = DAT_c0136c74;
  local_6c = 0;
  local_69 = 0x10;
  (**(code **)(*param_5 + 0x24))(param_5,0,8,auStack_68);
  iVar7 = 0x14;
  iVar2 = FUN_c01142e8(param_2,param_3,auStack_68,8,(uint)DAT_c0136c74,local_38,0x14,param_5);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = (**(code **)(*param_5 + 0x2c))(param_5,local_38,0x14,&local_70,0x20,0x8004,&local_74);
    if (uVar3 != 0) {
      local_78 = 0x14;
      (**(code **)(*param_5 + 8))(param_5,local_74,2,auStack_50,&local_78,0);
      (**(code **)(*param_5 + 0xc))(param_5,local_74);
      iVar2 = (**(code **)(*param_5 + 0x10))(param_5,0x6801,local_38,0x14);
      local_78 = 0x24;
      if (iVar2 != 0) {
        iVar4 = (**(code **)(*param_5 + 0x1c))(param_5,0,iVar2,0,1,0,auStack_60,&local_78,0x24);
        (**(code **)(*param_5 + 0x18))(param_5,iVar2);
        uVar3 = 0;
        if (iVar4 != 0) {
          bVar1 = FUN_c012aa7c(param_1,(BYTE *)&local_70);
          uVar3 = CONCAT31(extraout_var,bVar1);
        }
      }
    }
  }
  puVar5 = local_38;
  do {
    *puVar5 = 0;
    iVar7 = iVar7 + -1;
    puVar5 = puVar5 + 1;
  } while (iVar7 != 0);
  puVar6 = &local_70;
  do {
    *(undefined1 *)puVar6 = 0;
    iVar8 = iVar8 + -1;
    puVar6 = (undefined2 *)((int)puVar6 + 1);
  } while (iVar8 != 0);
  FUN_c013331c(local_24);
  return uVar3;
}



/* c012b03c FUN_c012b03c */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c012b03c..c012b30b. Semantic name remains unreviewed. */

undefined4 FUN_c012b03c(undefined4 param_1,undefined4 param_2,short *param_3)

{
  short sVar1;
  undefined ***pppuVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int local_80 [4];
  undefined **local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined **local_64;
  undefined4 local_60;
  undefined4 *local_5c;
  undefined4 local_58;
  undefined1 local_50 [24];
  undefined1 auStack_38 [20];
  uint local_24;
  
  local_24 = DAT_c0136c78;
  local_6c = 0x6801;
  local_70 = &PTR_FUN_c00f3210;
  sVar1 = *param_3;
  local_60 = 0x660e;
  local_64 = &PTR_FUN_c00f31d8;
  local_68 = 1;
  local_5c = &DAT_c0136e54;
  local_58 = 2;
  if (((((sVar1 != 1) && (sVar1 != 2)) || (param_3[1] == 0)) ||
      ((32000 < (ushort)param_3[1] || (8 < *(byte *)(param_3 + 3))))) ||
     (*(char *)((int)param_3 + 7) != '\x10')) goto LAB_c012b148;
  if (sVar1 == 1) {
    pppuVar2 = &local_70;
LAB_c012b130:
    if (pppuVar2 != (undefined ***)0x0) {
      iVar7 = 0x14;
      iVar3 = FUN_c01142e8(param_1,param_2,param_3 + 4,(uint)*(byte *)(param_3 + 3),
                           (uint)(ushort)param_3[1],local_50,0x14,(int *)pppuVar2);
      uVar6 = 0;
      if (iVar3 != 0) {
        uVar6 = 0;
        local_80[0] = 0;
        local_80[1] = 0x14;
        iVar3 = (*(code *)(*pppuVar2)[4])(pppuVar2,0x6801,local_50,0x14);
        local_80[2] = 0x24;
        if (iVar3 != 0) {
          iVar4 = (*(code *)(*pppuVar2)[8])(pppuVar2,0,iVar3,0,1,0,param_3 + 8,local_80 + 2);
          if (((iVar4 != 0) &&
              (iVar4 = (*(code *)(*pppuVar2)[0xb])
                                 (pppuVar2,local_50,0x14,param_3,0x20,0x8004,local_80), iVar4 != 0))
             && ((iVar4 = (*(code *)(*pppuVar2)[2])
                                    (pppuVar2,local_80[0],2,auStack_38,local_80 + 1,0), iVar4 != 0
                 && (iVar4 = memcmp(auStack_38,param_3 + 0x10,0x14), iVar4 == 0)))) {
            uVar6 = 1;
          }
          (*(code *)(*pppuVar2)[6])(pppuVar2,iVar3);
        }
        if (local_80[0] != 0) {
          (*(code *)(*pppuVar2)[3])(pppuVar2);
        }
      }
      puVar5 = local_50;
      do {
        *puVar5 = 0;
        iVar7 = iVar7 + -1;
        puVar5 = puVar5 + 1;
      } while (iVar7 != 0);
      FUN_c013331c(local_24);
      return uVar6;
    }
  }
  else if (sVar1 == 2) {
    pppuVar2 = (undefined ***)FUN_c0116194((int)&local_70);
    goto LAB_c012b130;
  }
  SetLastError(0xd);
LAB_c012b148:
  FUN_c013331c(local_24);
  return 0;
}



/* c012b30c FUN_c012b30c */

/* Boundary evidence: original MIPS .pdata c012b30c..c012b5b3. Semantic name remains unreviewed. */

uint FUN_c012b30c(int *param_1)

{
  int iVar1;
  BOOL BVar2;
  size_t sVar3;
  uint uVar4;
  undefined4 local_288;
  int local_284;
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  wchar_t awStack_270 [128];
  short asStack_170 [8];
  undefined1 auStack_160 [40];
  undefined1 auStack_138 [8];
  undefined1 auStack_130 [24];
  undefined1 auStack_118 [128];
  undefined1 auStack_98 [128];
  uint local_18;
  
  local_18 = DAT_c0136c78;
  iVar1 = (**(code **)*param_1)(param_1,0,0x8004,0,0,&local_288);
  if (iVar1 == 0) {
    FUN_c013331c(local_18);
    uVar4 = 0;
  }
  else {
    BVar2 = SystemParametersInfoW(0x102,0x100,awStack_270,0);
    if (BVar2 != 0) {
      sVar3 = wcslen(awStack_270);
      (**(code **)(*param_1 + 4))(param_1,local_288,awStack_270,sVar3 << 1,0);
    }
    local_27c = 0x104;
    local_274 = 0x105;
    iVar1 = KernelIoControl(0x1010004,&local_27c,4,auStack_98,0x80,&local_278);
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 4))(param_1,local_288,auStack_98,local_278,0);
    }
    iVar1 = KernelIoControl(0x1010004,&local_274,4,auStack_118,0x80,&local_280);
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 4))(param_1,local_288,auStack_118,local_280,0);
    }
    local_284 = 0;
    iVar1 = KernelIoControl(0x10100f8,0,0,auStack_138,8,&local_284);
    if ((iVar1 != 0) && (local_284 != 0)) {
      (**(code **)(*param_1 + 4))(param_1,local_288,auStack_138,local_284,0);
    }
    local_284 = 0x14;
    (**(code **)(*param_1 + 8))(param_1,local_288,2,auStack_130,&local_284,0);
    (**(code **)(*param_1 + 0xc))(param_1,local_288);
    iVar1 = FUN_c012ac20((wchar_t *)0x0,(LPBYTE)asStack_170);
    if ((iVar1 == 0) || (iVar1 = FUN_c012b03c(auStack_130,0x14,asStack_170), iVar1 == 0)) {
      (**(code **)(*param_1 + 0x24))(param_1,0,0x10,&DAT_c01370f4);
      uVar4 = FUN_c012add4((wchar_t *)0x0,auStack_130,0x14,&DAT_c01370f4,param_1);
    }
    else {
      memcpy(&DAT_c01370f4,auStack_160,0x10);
      uVar4 = 1;
    }
    DAT_c01370ec = uVar4;
    FUN_c013331c(local_18);
  }
  return uVar4;
}



/* c012b5b4 FUN_c012b5b4 */

/* Boundary evidence: original MIPS .pdata c012b5b4..c012b8e3. Semantic name remains unreviewed. */

undefined4 FUN_c012b5b4(uint param_1,undefined4 *param_2,void *param_3,size_t *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  DWORD dwErrCode;
  undefined4 uVar4;
  undefined4 local_68;
  undefined4 local_64;
  undefined **local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined **local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  undefined4 local_48;
  undefined1 auStack_40 [20];
  uint local_2c;
  
  local_2c = DAT_c0136c78;
  local_5c = 0x6801;
  local_60 = &PTR_FUN_c00f3210;
  local_58 = 1;
  local_50 = 0x660e;
  local_54 = &PTR_FUN_c00f31d8;
  local_4c = &DAT_c0136e54;
  local_48 = 2;
  piVar1 = (int *)FUN_c0116130((int)&local_60);
  if (piVar1 == (int *)0x0) {
    dwErrCode = 0xe;
  }
  else {
    uVar4 = 0;
    FUN_c012a708();
    if ((param_5 == 0) || (iVar2 = memcmp(param_2,&DAT_c00f46a8,0x10), iVar2 == 0)) {
      if ((DAT_c01370ec != 0) || (uVar3 = FUN_c012b30c(piVar1), uVar3 != 0)) {
        if ((param_1 & 4) == 0) {
          if (DAT_c01370f0 == 0) {
            SetLastError(0x80090001);
          }
          else {
            local_64 = 0x14;
            if (0x10 < *param_4) {
              *param_4 = 0x10;
            }
            iVar2 = (**(code **)*piVar1)(piVar1,0,0x8004,0,0,&local_68);
            if ((((iVar2 == 0) ||
                 (iVar2 = (**(code **)(*piVar1 + 4))(piVar1,local_68,&DAT_c01370dc,0x10,0),
                 iVar2 == 0)) ||
                (iVar2 = (**(code **)(*piVar1 + 4))(piVar1,local_68,&DAT_c01370f4,0x10,0),
                iVar2 == 0)) ||
               ((iVar2 = (**(code **)(*piVar1 + 8))(piVar1,local_68,2,auStack_40,&local_64,0),
                iVar2 == 0 || (iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,local_68), iVar2 == 0))))
            {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
              if (param_3 != (void *)0x0) {
                memcpy(param_3,auStack_40,*param_4);
              }
            }
            if (param_2 != (undefined4 *)0x0) {
              *param_2 = 0;
              param_2[1] = 0;
              param_2[2] = 0;
              param_2[3] = 0;
            }
          }
        }
        else {
          if (0x10 < *param_4) {
            *param_4 = 0x10;
          }
          if (param_3 != (void *)0x0) {
            memcpy(param_3,&DAT_c01370f4,*param_4);
          }
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = 0;
            param_2[1] = 0;
            param_2[2] = 0;
            param_2[3] = 0;
          }
          uVar4 = 1;
        }
        FUN_c013331c(local_2c);
        return uVar4;
      }
      dwErrCode = 0x80090020;
    }
    else {
      dwErrCode = 0x80090011;
    }
  }
  SetLastError(dwErrCode);
  FUN_c013331c(local_2c);
  return 0;
}



/* c012b8e4 FUN_c012b8e4 */

/* Boundary evidence: original MIPS .pdata c012b8e4..c012bb0f. Semantic name remains unreviewed. */

uint FUN_c012b8e4(wchar_t *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  uint uVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  int iVar4;
  undefined1 *puVar5;
  short asStack_58 [8];
  undefined1 local_48 [36];
  uint local_24;
  
  local_24 = DAT_c0136c78;
  FUN_c012a708();
  pwVar3 = DAT_c01370f0;
  if (param_1 == (wchar_t *)0x0) {
    if (DAT_c01370f0 != (wchar_t *)0x0) {
      LocalFree(DAT_c01370f0);
      DAT_c01370f0 = (wchar_t *)0x0;
    }
    iVar4 = 0x10;
    puVar5 = &DAT_c01370dc;
    do {
      *puVar5 = 0;
      iVar4 = iVar4 + -1;
      puVar5 = puVar5 + 1;
    } while (iVar4 != 0);
    FUN_c013331c(local_24);
    return 1;
  }
  if (DAT_c01370f0 != (wchar_t *)0x0) {
    iVar4 = wcscmp(param_1,DAT_c01370f0);
    if (iVar4 == 0) {
      uVar1 = FUN_c012add4(pwVar3,param_2,param_3,&DAT_c01370dc,param_4);
      goto LAB_c012bae0;
    }
    FUN_c012b8e4((wchar_t *)0x0,0,0,param_4);
  }
  sVar2 = wcslen(param_1);
  pwVar3 = LocalAlloc(0x40,(sVar2 + 1) * 2);
  DAT_c01370f0 = pwVar3;
  if (pwVar3 == (wchar_t *)0x0) {
    uVar1 = 0;
  }
  else {
    wcscpy(pwVar3,param_1);
    iVar4 = FUN_c012ac20(pwVar3,(LPBYTE)asStack_58);
    if (iVar4 == 0) {
      (**(code **)(*param_4 + 0x24))(param_4,0,0x10,&DAT_c01370dc);
      uVar1 = FUN_c012add4(DAT_c01370f0,param_2,param_3,&DAT_c01370dc,param_4);
    }
    else {
      uVar1 = FUN_c012b03c(param_2,param_3,asStack_58);
      if (uVar1 == 0) {
        SetLastError(0x52e);
        Sleep(1000);
      }
      else {
        iVar4 = 0x10;
        memcpy(&DAT_c01370dc,local_48,0x10);
        puVar5 = local_48;
        do {
          *puVar5 = 0;
          iVar4 = iVar4 + -1;
          puVar5 = puVar5 + 1;
        } while (iVar4 != 0);
      }
    }
    if (uVar1 == 0) {
      LocalFree(DAT_c01370f0);
      DAT_c01370f0 = (wchar_t *)0x0;
    }
  }
LAB_c012bae0:
  FUN_c013331c(local_24);
  return uVar1;
}



/* c012bb10 FUN_c012bb10 */

/* Boundary evidence: original MIPS .pdata c012bb10..c012bbc7. Semantic name remains unreviewed. */

uint FUN_c012bb10(wchar_t *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  undefined **local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined **local_24;
  undefined4 local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  
  local_30 = &PTR_FUN_c00f3210;
  local_2c = 0x6801;
  local_28 = 1;
  local_20 = 0x660e;
  local_24 = &PTR_FUN_c00f31d8;
  local_1c = &DAT_c0136e54;
  local_18 = 2;
  piVar1 = (int *)FUN_c0116130((int)&local_30);
  if (piVar1 == (int *)0x0) {
    SetLastError(0xe);
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_c012b8e4(param_1,param_2,param_3,piVar1);
  }
  return uVar2;
}



/* c012bbc8 FUN_c012bbc8 */

/* Boundary evidence: original MIPS .pdata c012bbc8..c012bc0f. Semantic name remains unreviewed. */

undefined4 FUN_c012bbc8(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 != 0) && (iVar1 = CeSafeCopyMemory(param_1), iVar1 != 0)) {
    uVar2 = param_1;
  }
  return uVar2;
}



/* c012bc10 FUN_c012bc10 */

/* Boundary evidence: original MIPS .pdata c012bc10..c012bc33. Semantic name remains unreviewed. */

void FUN_c012bc10(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    LocalFree(param_1);
  }
  return;
}



/* c012bc34 FUN_c012bc34 */

undefined4 FUN_c012bc34(int param_1)

{
  if (param_1 < 0x13) {
    if (param_1 == 0x12) {
      return 2;
    }
    if (param_1 == 2) {
      return 2;
    }
    if (param_1 == 3) {
      return 4;
    }
    if (param_1 == 5) {
      return 8;
    }
    if (param_1 == 0xb) {
      return 2;
    }
  }
  else {
    if (param_1 == 0x13) {
      return 4;
    }
    if (param_1 == 0x1f) {
      return 4;
    }
    if (param_1 == 0x40) {
      return 8;
    }
  }
  return 0;
}



/* c012bcc4 FUN_c012bcc4 */

/* Boundary evidence: original MIPS .pdata c012bcc4..c012be0f. Semantic name remains unreviewed. */

undefined4 FUN_c012bcc4(undefined2 *param_1,int param_2,int param_3)

{
  ushort uVar1;
  DWORD dwErrCode;
  undefined2 uVar2;
  
  if (((*(uint *)((param_3 + 4) * 4 + param_2) & 0x400) != 0) ||
     ((*(uint *)(param_2 + 0x10) & 0x200) != 0)) {
    dwErrCode = 5;
    goto LAB_c012bdf0;
  }
  uVar1 = *(ushort *)((param_3 + 1) * 4 + param_2);
  if (uVar1 < 0x13) {
    if ((uVar1 != 0x12) && (uVar1 != 2)) {
      if (uVar1 == 3) goto LAB_c012bdd8;
      if (uVar1 == 5) {
        *param_1 = 0xe79a;
        param_1[1] = 0xe79a;
        param_1[2] = 0xe79a;
        param_1[3] = 0xe79a;
        return 1;
      }
      if (uVar1 != 0xb) goto LAB_c012bda0;
    }
    uVar2 = 0xf79a;
LAB_c012bdcc:
    *param_1 = uVar2;
    return 1;
  }
  if (uVar1 == 0x13) {
LAB_c012bdd8:
    *param_1 = 0xfbd7;
    param_1[1] = 0x14a6;
    return 1;
  }
  if (uVar1 == 0x1f) {
    uVar2 = 0xfffe;
    goto LAB_c012bdcc;
  }
  if (uVar1 == 0x40) {
    *param_1 = 0;
    param_1[1] = 0xab;
    param_1[2] = 0x4a;
    param_1[3] = 0x8903;
    return 1;
  }
LAB_c012bda0:
  dwErrCode = 0x57;
LAB_c012bdf0:
  SetLastError(dwErrCode);
  return 0;
}



/* c012be10 FUN_c012be10 */

/* Boundary evidence: original MIPS .pdata c012be10..c012c037. Semantic name remains unreviewed. */

short FUN_c012be10(short *param_1,short *param_2,int param_3,short param_4)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  
  if (param_3 < 0x13) {
    if ((param_3 != 0x12) && (param_3 != 2)) {
      if (param_3 == 3) goto LAB_c012bfb8;
      if (param_3 == 5) {
        bVar2 = true;
        if ((((*param_1 != -0x1866) || (param_1[1] != -0x1866)) || (param_1[2] != -0x1866)) ||
           (bVar1 = true, param_1[3] != -0x1866)) {
          bVar1 = false;
        }
        if (((*param_2 == -0x1866) && (param_2[1] == -0x1866)) &&
           ((param_2[2] == -0x1866 && (param_2[3] == -0x1866)))) goto LAB_c012bff8;
        goto LAB_c012bff4;
      }
      if (param_3 != 0xb) goto LAB_c012bf20;
    }
    sVar3 = -0x866;
LAB_c012be64:
    bVar2 = true;
    bVar1 = *param_1 == sVar3;
    if (*param_2 == sVar3) goto LAB_c012bff8;
  }
  else if (param_3 == 0x13) {
LAB_c012bfb8:
    bVar2 = true;
    if ((*param_1 != -0x429) || (bVar1 = true, param_1[1] != 0x14a6)) {
      bVar1 = false;
    }
    if ((*param_2 == -0x429) && (param_2[1] == 0x14a6)) goto LAB_c012bff8;
  }
  else {
    if (param_3 == 0x1f) {
      sVar3 = -2;
      goto LAB_c012be64;
    }
    if (param_3 != 0x40) {
LAB_c012bf20:
      SetLastError(0x57);
      return -1;
    }
    bVar2 = true;
    if ((((*param_1 != 0) || (param_1[1] != 0xab)) || (param_1[2] != 0x4a)) ||
       (bVar1 = true, param_1[3] != -0x76fd)) {
      bVar1 = false;
    }
    if (((*param_2 == 0) && (param_2[1] == 0xab)) &&
       ((param_2[2] == 0x4a && (param_2[3] == -0x76fd)))) goto LAB_c012bff8;
  }
LAB_c012bff4:
  bVar2 = false;
LAB_c012bff8:
  if (bVar1) {
    sVar3 = 2;
    if (!bVar2) {
      sVar3 = param_4;
    }
  }
  else if (bVar2) {
    sVar3 = 4 - param_4;
  }
  else {
    sVar3 = -1;
  }
  return sVar3;
}



/* c012c038 FUN_c012c038 */

/* Boundary evidence: original MIPS .pdata c012c038..c012c31f. Semantic name remains unreviewed. */

short * FUN_c012c038(int param_1,uint param_2,short *param_3,short *param_4)

{
  short *psVar1;
  undefined1 uVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (param_3 == param_4) {
    param_3 = (short *)0x0;
  }
  if (param_2 != 0) {
    uVar5 = 0;
    do {
      uVar3 = *(ushort *)(uVar5 * 4 + param_1);
      if (uVar3 < 0x13) {
        if ((uVar3 != 0x12) && (uVar3 != 2)) {
          if (uVar3 == 3) goto LAB_c012c28c;
          if (uVar3 == 5) {
            if (param_3 != (short *)0x0) {
              *(undefined4 *)param_4 = *(undefined4 *)param_3;
              psVar1 = param_3 + 2;
              param_3 = param_3 + 4;
              *(undefined4 *)(param_4 + 2) = *(undefined4 *)psVar1;
            }
            if ((((*param_4 == -0x1866) && (param_4[1] == -0x1866)) && (param_4[2] == -0x1866)) &&
               (param_4[3] == -0x1866)) {
              *param_4 = -0x1866;
              param_4[1] = -0x1865;
              param_4[2] = -0x1866;
              param_4[3] = -0x1866;
            }
LAB_c012c264:
            param_4 = param_4 + 4;
            goto LAB_c012c2d4;
          }
          if (uVar3 != 0xb) goto LAB_c012c1dc;
        }
        if (param_3 != (short *)0x0) {
          uVar2 = *(undefined1 *)((int)param_3 + 1);
          *(char *)param_4 = (char)*param_3;
          *(undefined1 *)((int)param_4 + 1) = uVar2;
          param_3 = param_3 + 1;
        }
        if (*param_4 == -0x866) {
          *param_4 = -0x865;
        }
        param_4 = param_4 + 1;
      }
      else {
        if (uVar3 == 0x13) {
LAB_c012c28c:
          if (param_3 != (short *)0x0) {
            uVar4 = *(undefined4 *)param_3;
            param_3 = param_3 + 2;
            *(undefined4 *)param_4 = uVar4;
          }
          if ((*param_4 == -0x429) && (param_4[1] == 0x14a6)) {
            *param_4 = -0x429;
            param_4[1] = 0x14a7;
          }
        }
        else {
          if (uVar3 != 0x1f) {
            if (uVar3 == 0x40) {
              if (param_3 != (short *)0x0) {
                *(undefined4 *)param_4 = *(undefined4 *)param_3;
                psVar1 = param_3 + 2;
                param_3 = param_3 + 4;
                *(undefined4 *)(param_4 + 2) = *(undefined4 *)psVar1;
              }
              if ((((*param_4 == 0) && (param_4[1] == 0xab)) && (param_4[2] == 0x4a)) &&
                 (param_4[3] == -0x76fd)) {
                *param_4 = 0;
                param_4[1] = 0xab;
                param_4[2] = 0x4a;
                param_4[3] = -0x76fc;
              }
              goto LAB_c012c264;
            }
LAB_c012c1dc:
            SetLastError(0x57);
            goto LAB_c012c2d4;
          }
          if (param_3 != (short *)0x0) {
            uVar4 = *(undefined4 *)param_3;
            param_3 = param_3 + 2;
            *(undefined4 *)param_4 = uVar4;
          }
        }
        param_4 = param_4 + 2;
      }
LAB_c012c2d4:
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < param_2);
  }
  return param_4;
}



/* c012c320 FUN_c012c320 */

/* Boundary evidence: original MIPS .pdata c012c320..c012c5ef. Semantic name remains unreviewed. */

short * FUN_c012c320(int param_1,int param_2,int param_3,uint param_4,short *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  
  if ((*(uint *)(param_1 + 0x10) & 8) == 0) {
    if (param_3 == 0) {
      uVar5 = 0;
      psVar6 = param_5;
      if (*(short *)(param_1 + 0x1c) != 0) {
        do {
          iVar1 = FUN_c012bcc4(psVar6,param_1,uVar5);
          if (iVar1 == 0) {
            return (short *)0x0;
          }
          iVar1 = FUN_c012bc34((uint)*(ushort *)((uVar5 + 1) * 4 + param_1));
          uVar5 = uVar5 + 1 & 0xffff;
          psVar6 = (short *)(iVar1 + (int)psVar6);
        } while (uVar5 < *(ushort *)(param_1 + 0x1c));
      }
    }
    else {
      uVar5 = 0;
      psVar6 = param_5;
      if (param_4 != 0) {
        do {
          uVar4 = (uint)*(ushort *)((uVar5 + 1) * 4 + param_1);
          uVar2 = FUN_c012bc34(uVar4);
          if (uVar2 == 0) {
            return (short *)0x0;
          }
          iVar1 = uVar5 * 0x10 + param_3;
          if (((*(ushort *)(iVar1 + 6) & 0x100) == 0) && ((*(ushort *)(iVar1 + 6) & 0x200) == 0)) {
            if (uVar4 < 0x13) {
              if ((uVar4 != 0x12) && (uVar4 != 2)) {
                if (uVar4 == 3) goto LAB_c012c548;
                if (uVar4 == 5) goto LAB_c012c4c0;
                if (uVar4 != 0xb) {
                  return (short *)0x0;
                }
              }
              *psVar6 = *(short *)(iVar1 + 8);
            }
            else if (uVar4 == 0x13) {
LAB_c012c548:
              *(undefined4 *)psVar6 = *(undefined4 *)(iVar1 + 8);
            }
            else if (uVar4 == 0x1f) {
              iVar3 = DBCanonicalize(*(uint *)(*(int *)(*(int *)(param_2 + 4) + 8) + 0xf8) >> 8,
                                     *(undefined4 *)(iVar1 + 8),*(ushort *)(iVar1 + 4) >> 1,psVar6);
              if (iVar3 == 0) {
                *psVar6 = -0x101;
              }
              *(undefined4 *)((uVar5 + 6) * 4 + param_2) = *(undefined4 *)(iVar1 + 8);
              *(undefined2 *)((uVar5 + 0x12) * 2 + param_2) = *(undefined2 *)(iVar1 + 4);
            }
            else {
              if (uVar4 != 0x40) {
                return (short *)0x0;
              }
LAB_c012c4c0:
              *(undefined4 *)psVar6 = *(undefined4 *)(iVar1 + 8);
              *(undefined4 *)(psVar6 + 2) = *(undefined4 *)(iVar1 + 0xc);
            }
            FUN_c012c038(iVar1,1,psVar6,psVar6);
          }
          else {
            iVar1 = FUN_c012bcc4(psVar6,param_1,uVar5);
            if (iVar1 == 0) {
              return (short *)0x0;
            }
          }
          psVar6 = (short *)((uVar2 & 0xffff) + (int)psVar6);
          uVar5 = uVar5 + 1 & 0xffff;
        } while (uVar5 < param_4);
      }
    }
  }
  else {
    *(undefined4 *)param_5 = *(undefined4 *)(param_2 + 8);
  }
  return param_5;
}



/* c012c5f0 FUN_c012c5f0 */

/* Boundary evidence: original MIPS .pdata c012c5f0..c012cb0b. Semantic name remains unreviewed. */

uint FUN_c012c5f0(int param_1,int param_2,PCNZWCH param_3,PCNZWCH param_4,ushort param_5,
                 uint param_6,uint param_7)

{
  ushort uVar1;
  bool bVar2;
  short sVar3;
  undefined2 extraout_var;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint *puVar13;
  
  uVar6 = (uint)param_5;
  uVar7 = *(uint *)((uVar6 + 4) * 4 + param_2);
  if ((uVar7 & 8) != 0) {
    if (*(uint *)param_4 < *(uint *)param_3) {
      return 3;
    }
    if (*(uint *)param_4 <= *(uint *)param_3) {
      return 2;
    }
    return 1;
  }
  sVar3 = 1;
  if (((uVar7 & 1) != 0) == ((uVar7 & 4) != 0)) {
    sVar3 = 3;
  }
  puVar13 = (uint *)((uVar6 + 1) * 4 + param_2);
  sVar3 = FUN_c012be10(param_3,param_4,(uint)(ushort)*puVar13,sVar3);
  if (CONCAT22(extraout_var,sVar3) != 0xffff) {
    return CONCAT22(extraout_var,sVar3);
  }
  uVar1 = (ushort)*puVar13;
  if (uVar1 < 0x13) {
    if (uVar1 == 0x12) {
      if ((ushort)*param_4 < (ushort)*param_3) {
        return 3;
      }
      if ((ushort)*param_4 <= (ushort)*param_3) {
        return 2;
      }
      return 1;
    }
    if (uVar1 != 2) {
      if (uVar1 == 3) {
        if (*(int *)param_4 < *(int *)param_3) {
          return 3;
        }
        bVar2 = *(int *)param_3 < *(int *)param_4;
LAB_c012c7f0:
        if (!bVar2) {
          return 2;
        }
        return 1;
      }
      if (uVar1 == 5) {
        uVar10 = *(undefined4 *)param_3;
        uVar11 = *(undefined4 *)(param_3 + 2);
        uVar9 = *(undefined4 *)param_4;
        uVar12 = *(undefined4 *)(param_4 + 2);
        iVar4 = __gtd(uVar10,uVar11,uVar9,uVar12);
        if (iVar4 != 0) {
          return 3;
        }
        iVar4 = __ltd(uVar10,uVar11,uVar9,uVar12);
        if (iVar4 == 0) {
          return 2;
        }
        return 1;
      }
      if (uVar1 != 0xb) goto LAB_c012c85c;
    }
    if (*param_4 < *param_3) {
      return 3;
    }
    if (*param_4 <= *param_3) {
      return 2;
    }
    return 1;
  }
  if (uVar1 == 0x13) {
    if (*(uint *)param_4 < *(uint *)param_3) {
      return 3;
    }
    if (*(uint *)param_4 <= *(uint *)param_3) {
      return 2;
    }
    return 1;
  }
  if (uVar1 == 0x1f) {
    if ((*param_4 == L'\xfeff') || (*param_3 == L'\xfeff')) {
      uVar7 = 2;
    }
    else {
      uVar7 = CompareStringW(*(uint *)(*(int *)(*(int *)(param_1 + 4) + 8) + 0xf8) >> 8,
                             *(uint *)((uVar6 + 0xb) * 4 + param_1) | 1,param_3,2,param_4,2);
      uVar7 = uVar7 & 0xffff;
      if (uVar7 == 0) {
        return 0;
      }
    }
    if (uVar7 != 2) {
      return uVar7;
    }
    if (param_6 == *(uint *)(param_2 + 0x28)) {
      return 2;
    }
    if (param_7 == *(uint *)(param_2 + 0x28)) {
      return 2;
    }
    bVar2 = false;
    if (*(uint *)(param_1 + 8) != param_6) {
      if (*(uint *)(param_1 + 8) != param_7) {
        return 1;
      }
      bVar2 = true;
      param_7 = param_6;
    }
    piVar8 = (int *)((uVar6 + 6) * 4 + param_1);
    if (*piVar8 != 0) {
      uVar7 = FUN_c0101c94(*(int *)(param_1 + 4),param_7);
      if ((uVar7 == 0) || ((*(uint *)(uVar7 - 0xc) & 0xf0000000) != 0x80000000)) {
        uVar7 = 0;
      }
      if (uVar7 != 0) {
        puVar5 = (ushort *)
                 FUN_c0126a30(*(int *)(param_1 + 4),uVar7,*puVar13,(uint *)0x0,
                              *(int **)(param_1 + 0x14));
        if (puVar5 == (ushort *)0x0) {
          return 0;
        }
        uVar7 = 0xffa;
        if (*puVar5 < 0xffb) {
          uVar7 = (uint)*puVar5;
        }
        uVar6 = CompareStringW(*(uint *)(*(int *)(*(int *)(param_1 + 4) + 8) + 0xf8) >> 8,
                               *(DWORD *)((uVar6 + 0xb) * 4 + param_1),(PCNZWCH)*piVar8,
                               *(ushort *)((uVar6 + 0x12) * 2 + param_1) - 2 >> 1,
                               (PCNZWCH)(puVar5 + 1),uVar7 >> 1);
        uVar6 = uVar6 & 0xffff;
        if (uVar6 == 0) {
          return 0;
        }
        if (bVar2) {
          return 4 - uVar6 & 0xffff;
        }
        return uVar6;
      }
    }
  }
  else if (uVar1 == 0x40) {
    if (*(uint *)(param_4 + 2) < *(uint *)(param_3 + 2)) {
      uVar6 = 3;
    }
    else {
      uVar6 = 1;
      if (*(uint *)(param_4 + 2) <= *(uint *)(param_3 + 2)) {
        uVar6 = 2;
      }
    }
    if (uVar6 != 2) {
      return uVar6;
    }
    if (*(uint *)param_4 < *(uint *)param_3) {
      return 3;
    }
    bVar2 = *(uint *)param_3 < *(uint *)param_4;
    goto LAB_c012c7f0;
  }
LAB_c012c85c:
  SetLastError(0x570);
  return 0;
}



/* c012cb0c FUN_c012cb0c */

/* Boundary evidence: original MIPS .pdata c012cb0c..c012cca7. Semantic name remains unreviewed. */

uint FUN_c012cb0c(int param_1,int param_2,PCNZWCH param_3,PCNZWCH param_4,uint param_5,uint param_6,
                 ushort param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  PCNZWCH local_38;
  PCNZWCH local_34;
  
  uVar5 = 2;
  uVar4 = (uint)param_7;
  if ((uint)*(ushort *)(param_2 + 0x1c) < (uint)param_7) {
    uVar4 = (uint)*(ushort *)(param_2 + 0x1c);
  }
  if ((param_5 == *(uint *)(param_2 + 0x28)) || (uVar1 = 2, param_5 != param_6)) {
    uVar3 = *(uint *)(param_2 + 0x10);
    uVar6 = 0;
    uVar1 = uVar5;
    local_38 = param_3;
    local_34 = param_4;
    if (uVar4 != 0) {
      do {
        if (uVar5 != 2) {
          return uVar5;
        }
        uVar1 = FUN_c012c5f0(param_1,param_2,local_38,local_34,(ushort)uVar6,param_5,param_6);
        if (uVar1 != 0) {
          if ((*(uint *)((uVar6 + 4) * 4 + param_2) & 1) != 0) {
            uVar1 = 4 - uVar1 & 0xffff;
          }
          if ((uVar3 & 8) == 0) {
            iVar2 = FUN_c012bc34((uint)*(ushort *)((uVar6 + 1) * 4 + param_2));
            local_38 = (PCNZWCH)(iVar2 + (int)local_38);
            local_34 = (PCNZWCH)(iVar2 + (int)local_34);
          }
        }
        uVar6 = uVar6 + 1 & 0xffff;
        uVar5 = uVar1;
      } while (uVar6 < uVar4);
    }
  }
  return uVar1;
}



/* c012cca8 FUN_c012cca8 */

void FUN_c012cca8(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  *param_1 = 0x4e908ed2;
  uVar3 = 0;
  param_1[1] = param_2;
  param_1[5] = param_4;
  param_1[2] = param_5;
  param_1[3] = param_6;
  param_1[4] = param_7;
  do {
    param_1[uVar3 + 6] = 0;
    *(undefined2 *)((uVar3 + 0x12) * 2 + (int)param_1) = 0;
    if ((param_3 == 0) || (*(ushort *)(param_3 + 0x1c) <= uVar3)) {
      param_1[uVar3 + 0xb] = 0;
    }
    else {
      uVar2 = *(uint *)((uVar3 + 4) * 4 + param_3);
      uVar1 = (uint)((uVar2 & 2) != 0);
      if ((uVar2 & 0x40) != 0) {
        uVar1 = uVar1 | 0x10000;
      }
      if ((uVar2 & 0x10) != 0) {
        uVar1 = uVar1 | 2;
      }
      if ((uVar2 & 0x20) != 0) {
        uVar1 = uVar1 | 4;
      }
      if ((uVar2 & 0x80) != 0) {
        uVar1 = uVar1 | 0x20000;
      }
      if ((uVar2 & 0x100) != 0) {
        uVar1 = uVar1 | 0x1000;
      }
      param_1[uVar3 + 0xb] = uVar1;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 3);
  return;
}



/* c012cdd0 FUN_c012cdd0 */

/* Boundary evidence: original MIPS .pdata c012cdd0..c012ceff. Semantic name remains unreviewed. */

undefined4 FUN_c012cdd0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  *(undefined4 *)(param_2 + 0x20) = 0x400;
  *(undefined4 *)(param_2 + 0x24) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x28) = 0;
  uVar4 = 0;
  *(undefined2 *)(param_2 + 0x2c) = 0;
  uVar3 = 1;
  *(undefined2 *)(param_2 + 0x2e) = 0;
  if (*(short *)(param_2 + 0x1c) != 0) {
    do {
      if ((*(uint *)((uVar4 + 4) * 4 + param_2) & 8) == 0) {
        uVar2 = (uint)*(ushort *)((uVar4 + 1) * 4 + param_2);
        iVar1 = FUN_c012bc34(uVar2);
        if (iVar1 == 0) {
          RaiseException(1,1,0,(ULONG_PTR *)0x0);
          goto LAB_c012ceb4;
        }
        if (uVar2 == 0x1f) {
          *(undefined2 *)(param_2 + 0x2e) = 1;
        }
      }
      else {
        iVar1 = 4;
      }
      *(short *)(param_2 + 0x2c) = *(short *)(param_2 + 0x2c) + (short)iVar1;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < *(ushort *)(param_2 + 0x1c));
  }
  iVar1 = FUN_c012e0e0(param_1,param_2);
  if (iVar1 == 0) {
LAB_c012ceb4:
    uVar3 = 0;
  }
  return uVar3;
}



/* c012cf00 FUN_c012cf00 */

/* Boundary evidence: original MIPS .pdata c012cf00..c012d067. Semantic name remains unreviewed. */

int FUN_c012cf00(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  undefined4 auStack_60 [4];
  uint local_50;
  uint local_28;
  
  local_28 = DAT_c0136c78;
  iVar7 = 1;
  FUN_c012cca8(auStack_60,param_1,0,param_1 + 0x224,0,0,0);
  if (*(short *)(param_2 + 0x4c) == 0) {
    *(undefined4 *)(param_3 + 0x70) = 8;
    *(undefined4 *)(param_3 + 100) = 0;
    *(undefined2 *)(param_3 + 0x60) = 0;
    *(undefined2 *)(param_3 + 0x5e) = 1;
    *(undefined2 *)(param_2 + 0x4c) = 1;
  }
  iVar9 = 0;
  if (*(short *)(param_2 + 0x4c) != 0) {
    puVar8 = (ushort *)(param_3 + 0x60);
    puVar6 = (ushort *)(param_2 + 0x80);
    do {
      puVar3 = puVar8 + 8;
      uVar1 = puVar8[-1];
      local_50 = iVar9 << 0x18 | *(uint *)(param_2 + -4);
      iVar5 = 0;
      *puVar6 = uVar1;
      if (uVar1 != 0) {
        puVar4 = puVar6 + -0xc;
        do {
          iVar5 = iVar5 + 1;
          *(undefined4 *)puVar4 = *(undefined4 *)(puVar3 + -6);
          uVar2 = *(undefined4 *)puVar3;
          puVar3 = puVar3 + 2;
          *(undefined4 *)(puVar4 + 6) = uVar2;
          puVar4 = puVar4 + 2;
        } while (iVar5 < (int)(uint)*puVar6);
      }
      if ((*puVar8 & 0x200) != 0) {
        *(uint *)(puVar6 + -6) = *(uint *)(puVar6 + -6) | 0x200;
      }
      if (iVar7 == 0) {
LAB_c012d01c:
        iVar7 = 0;
      }
      else {
        iVar5 = FUN_c012cdd0(auStack_60,(int)(puVar6 + -0xe));
        iVar7 = 1;
        if (iVar5 == 0) goto LAB_c012d01c;
      }
      iVar9 = iVar9 + 1;
      puVar8 = puVar8 + 0x10;
      puVar6 = puVar6 + 0x20;
    } while (iVar9 < (int)(uint)*(ushort *)(param_2 + 0x4c));
  }
  FUN_c013331c(local_28);
  return iVar7;
}



/* c012d068 FUN_c012d068 */

/* Boundary evidence: original MIPS .pdata c012d068..c012d233. Semantic name remains unreviewed. */

undefined4 FUN_c012d068(int param_1,int param_2,int param_3)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  ushort local_220 [2];
  HLOCAL local_21c;
  uint local_218 [2];
  undefined4 auStack_210 [12];
  undefined4 auStack_1e0 [2];
  uint local_1d8;
  WCHAR aWStack_1a8 [192];
  uint local_28;
  
  local_28 = DAT_c0136c78;
  uVar6 = 0;
  uVar5 = 0;
  local_21c = (HLOCAL)0x0;
  local_218[0] = 0;
  if (*(short *)(param_2 + 0x4c) != 0) {
    do {
      if ((1 << (uVar5 + 8 & 0x1f) & (uint)*(ushort *)(param_2 + 0x4e)) != 0) {
        iVar4 = uVar5 * 0x40 + param_2 + 100;
        if (param_3 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(undefined4 *)(param_3 + -4);
        }
        FUN_c012cca8(auStack_1e0,param_1,iVar4,param_1 + 0x224,uVar3,0,
                     uVar5 << 0x18 | *(uint *)(param_2 + -4));
        if (param_3 == 0) {
          iVar4 = FUN_c012cdd0(auStack_1e0,iVar4);
        }
        else {
          iVar1 = FUN_c01273c4(param_1,param_2,param_3,iVar4,auStack_210,local_220,(int *)&local_21c
                               ,local_218);
          if ((iVar1 == 0) ||
             (psVar2 = FUN_c012c320(iVar4,(int)auStack_1e0,(int)auStack_210,(uint)local_220[0],
                                    aWStack_1a8), psVar2 == (short *)0x0)) goto LAB_c012d1e8;
          iVar4 = FUN_c012fd8c((int)auStack_1e0,iVar4,aWStack_1a8,local_1d8,3);
        }
        if (iVar4 == 0) goto LAB_c012d1e8;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < *(ushort *)(param_2 + 0x4c));
  }
  uVar6 = 1;
LAB_c012d1e8:
  if (local_21c != (HLOCAL)0x0) {
    LocalFree(local_21c);
  }
  FUN_c013331c(local_28);
  return uVar6;
}



/* c012d234 FUN_c012d234 */

/* Boundary evidence: original MIPS .pdata c012d234..c012d2fb. Semantic name remains unreviewed. */

undefined4 FUN_c012d234(undefined4 *param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_3;
  uVar1 = uVar2 & 0xffffff;
  if (uVar1 == param_4) {
    uVar1 = FUN_c0101c94((int)param_1,uVar1);
    if ((uVar1 == 0) || ((*(uint *)(uVar1 - 0xc) & 0xf0000000) != 0x70000000)) {
      uVar1 = 0;
    }
    if ((uVar1 != 0) && ((1 << ((uVar2 >> 0x18) + 8 & 0x1f) & (uint)*(ushort *)(uVar1 + 0x4e)) != 0)
       ) {
      FUN_c010297c((int)param_1);
      FUN_c01037f0(param_1,param_3[-1]);
      FUN_c0102aa4(param_1);
    }
  }
  return 1;
}



/* c012d2fc FUN_c012d2fc */

/* Boundary evidence: original MIPS .pdata c012d2fc..c012d3af. Semantic name remains unreviewed. */

undefined4 FUN_c012d2fc(undefined4 *param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  if (*param_3 == param_4) {
    FUN_c010297c((int)param_1);
    uVar1 = FUN_c0101c94((int)param_1,param_4);
    if ((uVar1 == 0) || ((*(uint *)(uVar1 - 0xc) & 0xf0000000) != 0x70000000)) {
      uVar1 = 0;
    }
    if ((uVar1 == 0) || (iVar2 = FUN_c012d068((int)param_1,uVar1,(int)param_3), iVar2 == 0)) {
      uVar3 = 0;
    }
    FUN_c0102aa4(param_1);
  }
  return uVar3;
}



/* c012d3b0 FUN_c012d3b0 */

/* Boundary evidence: original MIPS .pdata c012d3b0..c012d46f. Semantic name remains unreviewed. */

undefined4 FUN_c012d3b0(undefined4 *param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  
  if (*param_3 == param_4) {
    uVar1 = FUN_c0101c94((int)param_1,param_4);
    if ((uVar1 == 0) || ((*(uint *)(uVar1 - 0xc) & 0xf0000000) != 0x70000000)) {
      uVar1 = 0;
    }
    if (uVar1 == 0) {
      return 0;
    }
    FUN_c010297c((int)param_1);
    FUN_c01207c4(param_1,uVar1,(int)param_3);
    FUN_c0102aa4(param_1);
    if ((*(ushort *)(uVar1 + 0x4e) & 0x20) != 0) {
      FUN_c0120aac(param_1,uVar1);
    }
  }
  return 1;
}



/* c012d470 FUN_c012d470 */

/* Boundary evidence: original MIPS .pdata c012d470..c012d56b. Semantic name remains unreviewed. */

undefined4 FUN_c012d470(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_c010297c((int)param_1);
  *(ushort *)(param_2 + 0x4e) = *(ushort *)(param_2 + 0x4e) | 0xff00;
  FUN_c0102aa4(param_1);
  FUN_c0103540((int)param_1,FUN_c012d234,0xe,*(undefined4 *)(param_2 + -4));
  FUN_c010297c((int)param_1);
  iVar1 = FUN_c012d068((int)param_1,param_2,0);
  FUN_c0102aa4(param_1);
  if ((iVar1 == 0) ||
     (iVar1 = FUN_c0103540((int)param_1,FUN_c012d2fc,8,*(undefined4 *)(param_2 + -4)), iVar1 == 0))
  {
    FUN_c0103540((int)param_1,FUN_c012d234,0xe,*(undefined4 *)(param_2 + -4));
    uVar2 = 0;
  }
  else {
    FUN_c010297c((int)param_1);
    *(ushort *)(param_2 + 0x4e) = *(ushort *)(param_2 + 0x4e) & 0xff;
    FUN_c0102aa4(param_1);
    uVar2 = 1;
  }
  return uVar2;
}



/* c012d56c FUN_c012d56c */

/* Boundary evidence: original MIPS .pdata c012d56c..c012d5d7. Semantic name remains unreviewed. */

undefined4 FUN_c012d56c(int param_1,int param_2)

{
  *(ushort *)(param_2 + 0x4e) = *(ushort *)(param_2 + 0x4e) | 0xff00;
  FUN_c0103540(param_1,FUN_c012d234,0xe,*(undefined4 *)(param_2 + -4));
  FUN_c0103540(param_1,FUN_c012d3b0,8,*(undefined4 *)(param_2 + -4));
  return 1;
}



/* c012d5d8 FUN_c012d5d8 */

/* Boundary evidence: original MIPS .pdata c012d5d8..c012d897. Semantic name remains unreviewed. */

uint * FUN_c012d5d8(uint *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6
                   ,uint *param_7,void *param_8)

{
  uint *puVar1;
  DWORD DVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort local_238 [2];
  HLOCAL local_234;
  HLOCAL local_230;
  uint local_22c;
  uint auStack_228 [4];
  undefined4 auStack_218 [12];
  undefined4 auStack_1e8 [2];
  uint local_1e0;
  HLOCAL *local_1d4;
  WCHAR aWStack_1b0 [192];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  local_230 = (HLOCAL)0x0;
  local_22c = 0;
  FUN_c012cca8(auStack_1e8,param_2,param_4,param_2 + 0x224,0,0,0);
  puVar1 = FUN_c0130714(auStack_228,(int)auStack_1e8,param_4,param_6,param_5,*param_7,param_7[1],
                        param_7[2],param_8);
  uVar5 = puVar1[1];
  uVar6 = puVar1[2];
  *param_1 = *puVar1;
  param_1[1] = uVar5;
  param_1[2] = uVar6;
  if ((((param_5 == 8) && (uVar5 == *(uint *)(param_4 + 0x28))) &&
      (DVar2 = GetLastError(), DVar2 == 0x57)) && (param_7[1] != *(uint *)(param_4 + 0x28))) {
    local_234 = (HLOCAL)0x0;
    uVar5 = FUN_c0101c94(param_2,param_7[1]);
    if ((uVar5 == 0) || ((*(uint *)(uVar5 - 0xc) & 0xf0000000) != 0x80000000)) {
      uVar5 = 0;
    }
    if (uVar5 == 0) {
      SetLastError(0x57);
    }
    else {
      local_1e0 = param_7[1];
      local_1d4 = &local_234;
      iVar3 = FUN_c01273c4(param_2,param_3,uVar5,param_4,auStack_218,local_238,(int *)&local_230,
                           &local_22c);
      if (iVar3 != 0) {
        psVar4 = FUN_c012c320(param_4,(int)auStack_1e8,(int)auStack_218,(uint)local_238[0],
                              aWStack_1b0);
        if (psVar4 != (short *)0x0) {
          puVar1 = FUN_c0130c44(auStack_228,(int)auStack_1e8,param_4,2,aWStack_1b0,param_7[1],0xffff
                               );
          uVar6 = puVar1[1];
          uVar5 = *puVar1;
          uVar7 = puVar1[2];
          uVar8 = *(uint *)(param_4 + 0x28);
          *param_1 = uVar5;
          param_1[1] = uVar6;
          param_1[2] = uVar7;
          if (uVar6 != uVar8) {
            puVar1 = FUN_c0130714(auStack_228,(int)auStack_1e8,param_4,param_6,8,uVar5,uVar6,uVar7,
                                  param_8);
            uVar5 = puVar1[1];
            uVar6 = puVar1[2];
            *param_1 = *puVar1;
            param_1[1] = uVar5;
            param_1[2] = uVar6;
          }
          if (local_234 != (HLOCAL)0x0) {
            LocalFree(local_234);
          }
        }
      }
    }
  }
  if (local_230 != (HLOCAL)0x0) {
    LocalFree(local_230);
  }
  FUN_c013331c(local_30);
  return param_1;
}



/* c012d898 FUN_c012d898 */

/* Boundary evidence: original MIPS .pdata c012d898..c012dbfb. Semantic name remains unreviewed. */

uint * FUN_c012d898(uint *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6
                   ,ushort param_7,uint *param_8)

{
  bool bVar1;
  short *psVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint local_388;
  uint local_384;
  undefined4 local_380;
  uint auStack_378 [4];
  undefined4 auStack_368 [2];
  uint local_360;
  WCHAR aWStack_330 [192];
  WCHAR aWStack_1b0 [192];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  FUN_c012cca8(auStack_368,param_2,param_4,param_2 + 0x224,0xfffffffe,0,0);
  psVar2 = FUN_c012c320(param_4,(int)auStack_368,param_6,(uint)param_7,aWStack_330);
  if (psVar2 == (short *)0x0) {
    *param_1 = *(uint *)(param_4 + 0x24);
    param_1[1] = *(uint *)(param_4 + 0x28);
    param_1[2] = local_380;
    goto LAB_c012dbc0;
  }
  if (param_5 == 0x10) {
    puVar3 = FUN_c0130c44(auStack_378,(int)auStack_368,param_4,1,aWStack_330,local_360,param_7);
    uVar7 = puVar3[2];
    uVar6 = *puVar3;
    uVar5 = puVar3[1];
    local_380._2_2_ = (short)(uVar7 >> 0x10);
    bVar1 = local_380._2_2_ == 2;
    local_388 = uVar6;
    local_384 = uVar5;
    local_380 = uVar7;
    if ((bVar1) && (uVar6 != *(uint *)(param_4 + 0x24))) {
      puVar3 = FUN_c012d5d8(auStack_378,param_2,param_3,param_4,8,-1,&local_388,aWStack_1b0);
LAB_c012d9f0:
      uVar6 = *puVar3;
      uVar5 = puVar3[1];
      uVar7 = puVar3[2];
      if (uVar6 == *(uint *)(param_4 + 0x24)) {
LAB_c012dbb0:
        uVar5 = *(uint *)(param_4 + 0x28);
      }
    }
  }
  else if (param_5 == 0x40) {
    puVar3 = FUN_c0130c44(auStack_378,(int)auStack_368,param_4,4,aWStack_330,local_360,param_7);
    uVar7 = puVar3[2];
    uVar6 = *puVar3;
    uVar5 = puVar3[1];
    local_380._2_2_ = (short)(uVar7 >> 0x10);
    bVar1 = local_380._2_2_ == 1;
    local_388 = uVar6;
    local_384 = uVar5;
    local_380 = uVar7;
    if ((bVar1) && (uVar6 != *(uint *)(param_4 + 0x24))) {
      puVar3 = FUN_c012d5d8(auStack_378,param_2,param_3,param_4,8,1,&local_388,aWStack_1b0);
      goto LAB_c012d9f0;
    }
  }
  else {
    iVar8 = 1;
    if (param_5 == 0x20) {
      puVar3 = FUN_c0130c44(auStack_378,(int)auStack_368,param_4,1,aWStack_330,local_360,param_7);
      uVar5 = *puVar3;
      *param_8 = uVar5;
      param_8[1] = puVar3[1];
      param_8[2] = puVar3[2];
      if ((*(short *)((int)param_8 + 10) == 2) && (uVar5 != *(uint *)(param_4 + 0x24))) {
        uVar5 = puVar3[1];
        uVar6 = puVar3[2];
        *param_1 = *puVar3;
        param_1[1] = uVar5;
        param_1[2] = uVar6;
        goto LAB_c012dbc0;
      }
    }
    else if (param_5 == 0) {
      iVar8 = 0;
    }
    puVar3 = FUN_c012d5d8(auStack_378,param_2,param_3,param_4,8,iVar8,param_8,aWStack_1b0);
    uVar6 = *puVar3;
    uVar5 = puVar3[1];
    uVar7 = puVar3[2];
    if ((uVar6 == *(uint *)(param_4 + 0x24)) ||
       (uVar4 = FUN_c012cb0c((int)auStack_368,param_4,aWStack_330,aWStack_1b0,local_360,uVar5,
                             param_7), uVar4 != 2)) goto LAB_c012dbb0;
  }
  *param_1 = uVar6;
  param_1[1] = uVar5;
  param_1[2] = uVar7;
LAB_c012dbc0:
  FUN_c013331c(local_30);
  return param_1;
}



/* c012dbfc FUN_c012dbfc */

/* Boundary evidence: original MIPS .pdata c012dbfc..c012dcf3. Semantic name remains unreviewed. */

bool FUN_c012dbfc(int param_1,int param_2,int param_3,int param_4,ushort param_5,uint param_6)

{
  short *psVar1;
  bool bVar2;
  int iVar3;
  undefined4 auStack_1d8 [14];
  WCHAR aWStack_1a0 [192];
  uint local_20;
  
  local_20 = DAT_c0136c78;
  iVar3 = param_3 * 0x40 + param_2 + 100;
  FUN_c012cca8(auStack_1d8,param_1,iVar3,param_1 + 0x224,param_6,0,
               *(uint *)(param_2 + -4) & 0xffffff | param_3 << 0x18);
  psVar1 = FUN_c012c320(iVar3,(int)auStack_1d8,param_4,(uint)param_5,aWStack_1a0);
  if (psVar1 == (short *)0x0) {
    FUN_c013331c(local_20);
    bVar2 = false;
  }
  else {
    iVar3 = FUN_c012fd8c((int)auStack_1d8,iVar3,aWStack_1a0,param_6,3);
    bVar2 = iVar3 != 0;
    FUN_c013331c(local_20);
  }
  return bVar2;
}



/* c012dcf4 FUN_c012dcf4 */

/* Boundary evidence: original MIPS .pdata c012dcf4..c012ddbb. Semantic name remains unreviewed. */

undefined4
FUN_c012dcf4(undefined4 param_1,int param_2,uint param_3,int param_4,ushort param_5,
            undefined4 param_6,undefined4 param_7)

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 auStack_1d0 [14];
  WCHAR aWStack_198 [192];
  uint local_18;
  
  local_18 = DAT_c0136c78;
  FUN_c012cca8(auStack_1d0,param_1,param_2,param_7,param_3,param_6,0);
  psVar1 = FUN_c012c320(param_2,(int)auStack_1d0,param_4,(uint)param_5,aWStack_198);
  if ((psVar1 == (short *)0x0) ||
     (iVar3 = FUN_c0130590((int)auStack_1d0,param_2,aWStack_198,param_3), iVar3 == 0)) {
    FUN_c013331c(local_18);
    uVar2 = 0;
  }
  else {
    FUN_c013331c(local_18);
    uVar2 = 1;
  }
  return uVar2;
}



/* c012ddbc FUN_c012ddbc */

/* Boundary evidence: original MIPS .pdata c012ddbc..c012de4b. Semantic name remains unreviewed. */

uint FUN_c012ddbc(int param_1,int param_2,uint param_3,int param_4,ushort param_5)

{
  uint uVar1;
  undefined4 auStack_50 [14];
  uint local_18;
  
  local_18 = DAT_c0136c78;
  FUN_c012cca8(auStack_50,param_1,param_2,param_1 + 0x224,0,0,0);
  uVar1 = FUN_c0130b50((int)auStack_50,param_2,param_3,param_4,param_5);
  FUN_c013331c(local_18);
  return uVar1;
}



/* c012de4c FUN_c012de4c */

/* Boundary evidence: original MIPS .pdata c012de4c..c012deaf. Semantic name remains unreviewed. */

uint FUN_c012de4c(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 == *(uint *)(param_2 + 0x24)) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c0101c94(*(int *)(param_1 + 4),param_3);
    if ((uVar1 == 0) || ((*(uint *)(uVar1 - 0xc) & 0xf0000000) != 0xe0000000)) {
      uVar1 = 0;
    }
    if (uVar1 != 0) {
      uVar1 = uVar1 + 4;
    }
  }
  return uVar1;
}



/* c012deb0 FUN_c012deb0 */

/* Boundary evidence: original MIPS .pdata c012deb0..c012df17. Semantic name remains unreviewed. */

uint FUN_c012deb0(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0x20) + 4;
  if ((uVar2 < *(uint *)(param_2 + 0x20)) ||
     (puVar1 = FUN_c011daa0(*(undefined4 **)(param_1 + 4),0xe,uVar2,0), puVar1 == (uint *)0x0)) {
    uVar2 = *(uint *)(param_2 + 0x24);
  }
  else {
    *puVar1 = *(uint *)(param_1 + 0x10);
    uVar2 = puVar1[-1];
  }
  return uVar2;
}



/* c012df18 FUN_c012df18 */

/* Boundary evidence: original MIPS .pdata c012df18..c012dfab. Semantic name remains unreviewed. */

undefined4 FUN_c012df18(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    FUN_c01037f0(*(undefined4 **)(param_1 + 4),param_3);
  }
  else {
    puVar1 = (undefined4 *)FUN_c0101c94((int)*(undefined4 **)(param_1 + 4),param_3);
    if ((puVar1 == (undefined4 *)0x0) || ((puVar1[-3] & 0xf0000000) != 0xe0000000)) {
      puVar1 = (undefined4 *)0x0;
    }
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = **(undefined4 **)(param_1 + 0xc);
      **(uint **)(param_1 + 0xc) = param_3;
    }
  }
  return 1;
}



/* c012dfac FUN_c012dfac */

/* Boundary evidence: original MIPS .pdata c012dfac..c012e017. Semantic name remains unreviewed. */

int FUN_c012dfac(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((param_3 + 0xc) * 4 + param_2);
  FUN_c01029e4(*(int *)(param_1 + 4),1,(param_3 + 0xc) * 4 + param_2,*puVar1,4);
  *puVar1 = param_4;
  return param_2;
}



/* c012e018 FUN_c012e018 */

/* Boundary evidence: original MIPS .pdata c012e018..c012e0df. Semantic name remains unreviewed. */

undefined2 * FUN_c012e018(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  
  uVar1 = FUN_c012deb0(param_1,param_2);
  puVar2 = (undefined2 *)FUN_c012de4c(param_1,param_2,uVar1);
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = (undefined2 *)0x0;
  }
  else {
    *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(param_2 + 0x24);
    puVar2[1] = 0;
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 6) = param_3;
    iVar3 = FUN_c012dfac(param_1,param_2,0,uVar1);
    FUN_c012dfac(param_1,iVar3,1,*(int *)(param_2 + 0x34) + 1);
  }
  return puVar2;
}



/* c012e0e0 FUN_c012e0e0 */

/* Boundary evidence: original MIPS .pdata c012e0e0..c012e1a7. Semantic name remains unreviewed. */

undefined4 FUN_c012e0e0(int param_1,int param_2)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = *(ushort *)(param_2 + 0x2c) + 4;
  uVar4 = (*(int *)(param_2 + 0x20) + 0xfff0U & 0xffff) / uVar2;
  uVar3 = 0;
  if (uVar2 == 0) {
    trap(0x1c00);
  }
  uVar2 = uVar4 + 0xffff;
  uVar5 = ((uVar2 & 0xffff) << 1) / 3;
  *(short *)(param_2 + 0x3a) = (short)uVar2;
  *(short *)(param_2 + 0x38) = (short)uVar4;
  *(short *)(param_2 + 0x3c) = (short)uVar5;
  if (((2 < uVar5) && (1 < (int)(*(ushort *)(param_2 + 0x3a) - uVar5))) &&
     (puVar1 = FUN_c012e018(param_1,param_2,*(undefined4 *)(param_2 + 0x24)),
     puVar1 != (undefined2 *)0x0)) {
    *(undefined4 *)(param_2 + 0x34) = 0;
    *puVar1 = 2;
    uVar3 = 1;
  }
  return uVar3;
}



/* c012e1a8 FUN_c012e1a8 */

/* Boundary evidence: original MIPS .pdata c012e1a8..c012e4d7. Semantic name remains unreviewed. */

undefined4
FUN_c012e1a8(int param_1,int param_2,PCNZWCH param_3,uint param_4,ushort *param_5,ushort param_6,
            undefined4 *param_7,ushort param_8)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar5 = 0;
  if (param_5[1] == 0) {
    param_7[1] = *(undefined4 *)(param_2 + 0x28);
    *param_7 = *(undefined4 *)(param_2 + 0x24);
    *(undefined2 *)(param_7 + 2) = 0;
    *(undefined2 *)((int)param_7 + 10) = 0;
LAB_c012e224:
    uVar4 = 0;
  }
  else {
    uVar7 = 0;
    iVar8 = param_5[1] - 1;
    uVar4 = 1;
    if (-1 < iVar8) {
      do {
        uVar1 = *(ushort *)(param_2 + 0x2c);
        uVar5 = (int)(iVar8 + uVar7) >> 1;
        uVar2 = *(ushort *)(param_2 + 0x38);
        if ((*param_5 & 2) == 0) {
          uVar6 = *(uint *)(param_5 + (uVar5 + 3) * 2);
          do {
            puVar3 = (ushort *)FUN_c012de4c(param_1,param_2,uVar6);
            if (puVar3 == (ushort *)0x0) break;
            if ((*puVar3 & 2) == 0) {
              uVar6 = (uint)puVar3[1];
            }
            else {
              uVar6 = puVar3[1] - 1;
            }
            uVar6 = *(uint *)(puVar3 + (uVar6 + 3) * 2);
          } while ((*puVar3 & 2) == 0);
        }
        else {
          uVar6 = *(uint *)(param_5 + (uVar5 + 3) * 2);
        }
        uVar6 = FUN_c012cb0c(param_1,param_2,
                             (PCNZWCH)((uVar2 + 4) * 4 + uVar1 * uVar5 + (int)param_5),param_3,uVar6
                             ,param_4,param_8);
        *(short *)((int)param_7 + 10) = (short)uVar6;
        if (uVar6 == 0) goto LAB_c012e224;
        if ((param_6 & 0x8000) == 0) {
LAB_c012e360:
          if (((uVar6 == 2) && ((*(ushort *)(param_2 + 0x2e) & 1) != 0)) && ((*param_5 & 2) == 0)) {
            uVar6 = *(uint *)(param_5 + (uVar5 + 4) * 2);
            while( true ) {
              puVar3 = (ushort *)FUN_c012de4c(param_1,param_2,uVar6);
              if (puVar3 == (ushort *)0x0) goto LAB_c012e224;
              if ((*puVar3 & 2) != 0) break;
              uVar6 = *(uint *)(puVar3 + 6);
            }
            uVar6 = FUN_c012cb0c(param_1,param_2,
                                 (PCNZWCH)(puVar3 + (*(ushort *)(param_2 + 0x38) + 4) * 2),param_3,
                                 *(uint *)(puVar3 + 6),param_4,param_8);
            *(short *)((int)param_7 + 10) = (short)uVar6;
            if (uVar6 == 0) goto LAB_c012e224;
          }
        }
        else if (uVar6 == 2) {
          if ((*param_5 & 2) == 0) goto LAB_c012e360;
          SetLastError(0xb7);
          goto LAB_c012e224;
        }
        if ((*(short *)((int)param_7 + 10) == 1) ||
           (((param_6 & 0x7fff) == 3 && (*(short *)((int)param_7 + 10) == 2)))) {
          uVar7 = uVar5 + 1;
        }
        else {
          iVar8 = uVar5 - 1;
        }
      } while ((int)uVar7 <= iVar8);
    }
    if ((*param_5 & 2) == 0) {
      uVar5 = uVar7;
    }
    *(short *)(param_7 + 2) = (short)uVar5;
    param_7[1] = *(undefined4 *)(param_5 + ((uVar5 & 0xffff) + 3) * 2);
  }
  return uVar4;
}



/* c012e4d8 FUN_c012e4d8 */

/* Boundary evidence: original MIPS .pdata c012e4d8..c012e64b. Semantic name remains unreviewed. */

undefined4
FUN_c012e4d8(int param_1,int param_2,PCNZWCH param_3,uint param_4,ushort param_5,ushort *param_6,
            uint *param_7,ushort param_8)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  
  *param_7 = *(uint *)(param_2 + 0x30);
  if (param_6 != (ushort *)0x0) {
    *param_6 = 0;
  }
  puVar1 = (ushort *)FUN_c012de4c(param_1,param_2,*param_7);
  while( true ) {
    if ((puVar1 == (ushort *)0x0) ||
       (iVar2 = FUN_c012e1a8(param_1,param_2,param_3,param_4,puVar1,param_5,param_7,param_8),
       iVar2 == 0)) {
      return 0;
    }
    if (param_6 != (ushort *)0x0) {
      *(uint *)(param_6 + (*param_6 + 6) * 2) = *param_7;
      param_6[*param_6 + 1] = (ushort)param_7[2];
      *param_6 = *param_6 + 1;
    }
    if ((*puVar1 & 2) != 0) break;
    uVar3 = *(uint *)(puVar1 + ((ushort)param_7[2] + 3) * 2);
    *param_7 = uVar3;
    puVar1 = (ushort *)FUN_c012de4c(param_1,param_2,uVar3);
  }
  return 1;
}



/* c012e64c FUN_c012e64c */

/* Boundary evidence: original MIPS .pdata c012e64c..c012e87f. Semantic name remains unreviewed. */

undefined4
FUN_c012e64c(int param_1,int param_2,PCNZWCH param_3,uint param_4,ushort param_5,undefined4 *param_6
            ,ushort param_7)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(param_2 + 0x30));
  if (puVar1 != (ushort *)0x0) {
    if (puVar1[1] == 0) {
      *param_6 = *(undefined4 *)(param_2 + 0x30);
      *(undefined2 *)(param_6 + 2) = 0;
      *(undefined2 *)((int)param_6 + 10) = 3;
      param_6[1] = 0;
      return 1;
    }
    if (*(int *)(puVar1 + 4) == *(int *)(param_2 + 0x24)) {
      *param_6 = *(undefined4 *)(param_2 + 0x30);
      iVar2 = FUN_c012e1a8(param_1,param_2,param_3,param_4,puVar1,param_5,param_6,param_7);
    }
    else {
      uVar3 = FUN_c012cb0c(param_1,param_2,
                           (PCNZWCH)((uint)*(ushort *)(param_2 + 0x2c) * (puVar1[1] - 1) +
                                     (*(ushort *)(param_2 + 0x38) + 4) * 4 + (int)puVar1),param_3,
                           *(uint *)(puVar1 + (puVar1[1] + 2) * 2),param_4,param_7);
      *(short *)((int)param_6 + 10) = (short)uVar3;
      if (uVar3 == 0) {
        return 0;
      }
      if ((uVar3 == 1) || ((param_5 == 3 && (uVar3 == 2)))) {
        *param_6 = *(undefined4 *)(puVar1 + 4);
        puVar1 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar1 + 4));
        if (puVar1 == (ushort *)0x0) {
          return 0;
        }
        iVar2 = FUN_c012e1a8(param_1,param_2,param_3,param_4,puVar1,param_5,param_6,param_7);
      }
      else {
        *param_6 = *(undefined4 *)(param_2 + 0x30);
        iVar2 = FUN_c012e1a8(param_1,param_2,param_3,param_4,puVar1,param_5,param_6,param_7);
      }
    }
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}



/* c012e880 FUN_c012e880 */

/* Boundary evidence: original MIPS .pdata c012e880..c012ebb3. Semantic name remains unreviewed. */

uint * FUN_c012e880(uint *param_1,int param_2,int param_3,int param_4,PCNZWCH param_5,uint param_6,
                   ushort *param_7,ushort param_8)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  *param_1 = *(uint *)(param_3 + 0x24);
  uVar4 = 1;
  if (param_4 != 1) {
    uVar4 = 3;
  }
  if (*(uint *)(param_3 + 0x34) < 4) {
    iVar1 = FUN_c012e64c(param_2,param_3,param_5,param_6,uVar4,param_1,param_8);
    if (iVar1 == 0) goto LAB_c012e9a4;
    *param_7 = 0;
    *(uint *)(param_7 + 0xc) = *param_1;
    param_7[1] = (ushort)param_1[2];
  }
  else {
    iVar1 = FUN_c012e4d8(param_2,param_3,param_5,param_6,uVar4,param_7,param_1,param_8);
    if (iVar1 == 0) goto LAB_c012e9a4;
    *param_7 = *param_7 - 1;
  }
  if (param_4 != 2) {
    return param_1;
  }
  uVar6 = *param_1;
  puVar2 = (ushort *)FUN_c012de4c(param_2,param_3,uVar6);
  puVar3 = puVar2;
  while (puVar3 != (ushort *)0x0) {
    if (*(short *)((int)param_1 + 10) == 1) {
      return param_1;
    }
    if ((*(short *)((int)param_1 + 10) == 2) &&
       (param_6 == *(uint *)(puVar2 + ((ushort)param_1[2] + 3) * 2))) {
      return param_1;
    }
    uVar5 = (uint)*param_7;
    puVar3 = param_7 + uVar5 + 1;
    puVar7 = (uint *)(param_7 + (uVar5 + 6) * 2);
    do {
      uVar4 = *puVar3;
      *puVar3 = uVar4 - 1;
      if (uVar4 != 0) break;
      if ((uVar6 != *puVar7) &&
         (puVar2 = (ushort *)FUN_c012de4c(param_2,param_3,*puVar7), puVar2 == (ushort *)0x0))
      goto LAB_c012e9a4;
      if (*(uint *)(puVar2 + 2) == *(uint *)(param_3 + 0x24)) {
        return param_1;
      }
      *puVar7 = *(uint *)(puVar2 + 2);
      uVar6 = *(uint *)(puVar2 + 2);
      puVar2 = (ushort *)FUN_c012de4c(param_2,param_3,uVar6);
      if (puVar2 == (ushort *)0x0) goto LAB_c012e9a4;
      *puVar3 = puVar2[1] - (ushort)((*puVar2 & 2) != 0);
      uVar5 = uVar5 - 1;
      puVar7 = puVar7 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < (int)uVar5);
    uVar5 = *(uint *)(param_7 + (*param_7 + 6) * 2);
    *param_1 = uVar5;
    if ((uVar6 != uVar5) &&
       (puVar2 = (ushort *)FUN_c012de4c(param_2,param_3,uVar5), uVar6 = uVar5,
       puVar2 == (ushort *)0x0)) break;
    uVar4 = param_7[*param_7 + 1];
    *(ushort *)(param_1 + 2) = uVar4;
    uVar5 = *(uint *)(puVar2 + (uVar4 + 3) * 2);
    param_1[1] = uVar5;
    puVar3 = (ushort *)
             FUN_c012cb0c(param_2,param_3,
                          (PCNZWCH)((uint)*(ushort *)(param_3 + 0x2c) * (uint)(ushort)param_1[2] +
                                    (*(ushort *)(param_3 + 0x38) + 4) * 4 + (int)puVar2),param_5,
                          uVar5,param_6,param_8);
    *(short *)((int)param_1 + 10) = (short)puVar3;
  }
LAB_c012e9a4:
  *param_1 = *(uint *)(param_3 + 0x24);
  param_1[1] = *(uint *)(param_3 + 0x28);
  *(undefined2 *)(param_1 + 2) = 0;
  return param_1;
}



/* c012ebb4 FUN_c012ebb4 */

/* Boundary evidence: original MIPS .pdata c012ebb4..c012ecdf. Semantic name remains unreviewed. */

void FUN_c012ebb4(int param_1,int param_2,void *param_3,undefined4 param_4,ushort param_5,
                 ushort param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *_Src;
  
  uVar1 = (uint)param_6;
  _Src = (undefined4 *)((uVar1 + 3) * 4 + param_2);
  memmove((void *)((uVar1 + 4) * 4 + param_2),_Src,((*(ushort *)(param_2 + 2) - uVar1) + 1) * 4);
  uVar1 = (uint)param_5;
  uVar2 = (uint)*(ushort *)(param_1 + 0x2c);
  iVar3 = (*(ushort *)(param_1 + 0x38) + 4) * 4;
  memmove((void *)((uVar1 + 1) * uVar2 + iVar3 + param_2),(void *)(uVar1 * uVar2 + iVar3 + param_2),
          (*(ushort *)(param_2 + 2) - uVar1) * uVar2);
  *_Src = param_4;
  memcpy((void *)(*(ushort *)(param_1 + 0x2c) * uVar1 + (*(ushort *)(param_1 + 0x38) + 4) * 4 +
                 param_2),param_3,(uint)*(ushort *)(param_1 + 0x2c));
  *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 1;
  return;
}



/* c012ece0 FUN_c012ece0 */

/* Boundary evidence: original MIPS .pdata c012ece0..c012eef3. Semantic name remains unreviewed. */

void FUN_c012ece0(int param_1,ushort *param_2,int param_3,int param_4,ushort param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  
  if ((*param_2 & 2) == 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x2c);
    iVar1 = (*(ushort *)(param_1 + 0x38) + 4) * 4;
    memcpy((void *)(*(ushort *)(param_3 + 2) * uVar2 + iVar1 + param_3),
           (void *)((param_5 - 1) * uVar2 + iVar1 + param_4),uVar2);
    *(short *)(param_3 + 2) = *(short *)(param_3 + 2) + 1;
  }
  memmove((void *)((*(ushort *)(param_3 + 2) + 3) * 4 + param_3),param_2 + 6,param_6 << 2);
  iVar1 = *(ushort *)(param_1 + 0x38) + 4;
  memmove((void *)((uint)*(ushort *)(param_1 + 0x2c) * (uint)*(ushort *)(param_3 + 2) + iVar1 * 4 +
                  param_3),param_2 + iVar1 * 2,(uint)*(ushort *)(param_1 + 0x2c) * param_6);
  memmove(param_2 + 6,param_2 + (param_6 + 3) * 2,(((uint)param_2[1] - param_6) + 1) * 4);
  iVar1 = *(ushort *)(param_1 + 0x38) + 4;
  memmove(param_2 + iVar1 * 2,
          (void *)((uint)*(ushort *)(param_1 + 0x2c) * param_6 + iVar1 * 4 + (int)param_2),
          ((uint)param_2[1] - param_6) * (uint)*(ushort *)(param_1 + 0x2c));
  *(short *)(param_3 + 2) = *(short *)(param_3 + 2) + (short)param_6;
  param_2[1] = param_2[1] - (short)param_6;
  if (param_4 != 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x2c);
    iVar1 = (*(ushort *)(param_1 + 0x38) + 4) * 4;
    memcpy((void *)((param_5 - 1) * uVar2 + iVar1 + param_4),
           (void *)((*(ushort *)(param_3 + 2) - 1) * uVar2 + iVar1 + param_3),uVar2);
  }
  if ((*param_2 & 2) == 0) {
    *(short *)(param_3 + 2) = *(short *)(param_3 + 2) + -1;
  }
  return;
}



/* c012eef4 FUN_c012eef4 */

/* Boundary evidence: original MIPS .pdata c012eef4..c012f12f. Semantic name remains unreviewed. */

void FUN_c012eef4(int param_1,ushort *param_2,int param_3,int param_4,ushort param_5,int param_6)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  memmove((void *)((param_6 + 3) * 4 + param_3),(void *)(param_3 + 0xc),
          (*(ushort *)(param_3 + 2) + 1) * 4);
  iVar2 = (*(ushort *)(param_1 + 0x38) + 4) * 4;
  memmove((void *)((uint)*(ushort *)(param_1 + 0x2c) * param_6 + iVar2 + param_3),
          (void *)(iVar2 + param_3),
          (uint)*(ushort *)(param_1 + 0x2c) * (uint)*(ushort *)(param_3 + 2));
  iVar2 = param_6;
  if ((*param_2 & 2) == 0) {
    uVar4 = (uint)*(ushort *)(param_1 + 0x2c);
    iVar2 = param_6 + -1;
    iVar3 = (*(ushort *)(param_1 + 0x38) + 4) * 4;
    memcpy((void *)(iVar2 * uVar4 + iVar3 + param_3),(void *)(param_5 * uVar4 + iVar3 + param_4),
           uVar4);
    *(undefined4 *)((param_6 + 2) * 4 + param_3) = *(undefined4 *)(param_2 + (param_2[1] + 3) * 2);
    *(short *)(param_3 + 2) = *(short *)(param_3 + 2) + 1;
  }
  memmove((void *)(param_3 + 0xc),param_2 + (((uint)param_2[1] - iVar2) + 3) * 2,iVar2 << 2);
  iVar3 = (*(ushort *)(param_1 + 0x38) + 4) * 4;
  memmove((void *)(iVar3 + param_3),
          (void *)(((uint)param_2[1] - iVar2) * (uint)*(ushort *)(param_1 + 0x2c) + iVar3 +
                  (int)param_2),(uint)*(ushort *)(param_1 + 0x2c) * iVar2);
  *(short *)(param_3 + 2) = *(short *)(param_3 + 2) + (short)iVar2;
  uVar1 = param_2[1];
  param_2[1] = (ushort)((uint)uVar1 - iVar2);
  if (param_4 != 0) {
    uVar4 = (uint)*(ushort *)(param_1 + 0x2c);
    iVar3 = (*(ushort *)(param_1 + 0x38) + 4) * 4;
    memcpy((void *)(param_5 * uVar4 + iVar3 + param_4),
           (void *)((((uint)uVar1 - iVar2 & 0xffff) - 1) * uVar4 + iVar3 + (int)param_2),uVar4);
  }
  if ((*param_2 & 2) == 0) {
    param_2[1] = param_2[1] - 1;
  }
  return;
}



/* c012f130 FUN_c012f130 */

/* Boundary evidence: original MIPS .pdata c012f130..c012f28b. Semantic name remains unreviewed. */

ushort * FUN_c012f130(int param_1,int param_2,undefined4 param_3,ushort *param_4,undefined4 param_5,
                     int param_6,int param_7,ushort param_8)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  
  uVar1 = FUN_c012deb0(param_1,param_2);
  if ((uVar1 == *(uint *)(param_2 + 0x24)) ||
     (puVar2 = (ushort *)FUN_c012de4c(param_1,param_2,uVar1), puVar2 == (ushort *)0x0)) {
    puVar2 = (ushort *)0x0;
  }
  else {
    *(undefined4 *)(puVar2 + 2) = param_3;
    *(undefined4 *)(puVar2 + 4) = param_5;
    *puVar2 = *param_4;
    puVar2[1] = 0;
    *(uint *)(param_4 + 4) = uVar1;
    if (param_6 != 0) {
      *(uint *)(param_6 + 4) = uVar1;
    }
    iVar3 = FUN_c012dfac(param_1,param_2,1,*(int *)(param_2 + 0x34) + 1);
    if (param_7 != 0) {
      FUN_c012ebb4(iVar3,param_7,
                   (void *)((param_4[1] - 1) * (uint)*(ushort *)(iVar3 + 0x2c) +
                            (*(ushort *)(param_2 + 0x38) + 4) * 4 + (int)param_4),uVar1,param_8 - 1,
                   param_8);
    }
    if ((*puVar2 & 2) == 0) {
      *(undefined4 *)(puVar2 + 6) = *(undefined4 *)(param_4 + (param_4[1] + 3) * 2);
      param_4[1] = param_4[1] - 1;
    }
  }
  return puVar2;
}



/* c012f28c FUN_c012f28c */

/* Boundary evidence: original MIPS .pdata c012f28c..c012f517. Semantic name remains unreviewed. */

void FUN_c012f28c(int param_1,ushort *param_2,ushort *param_3,ushort *param_4,int param_5,
                 ushort param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_6 == 0) {
    param_3 = (ushort *)0x0;
  }
  if (param_6 == *(ushort *)(param_5 + 2)) {
    param_4 = (ushort *)0x0;
  }
  uVar2 = (uint)(param_4 != (ushort *)0x0) + (uint)(param_3 != (ushort *)0x0) + 1;
  if (param_3 == (ushort *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)param_3[1];
  }
  if (param_4 == (ushort *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (uint)param_4[1];
  }
  uVar3 = (uVar2 >> 1) + (uint)param_2[1] + uVar1 + uVar3;
  if (uVar2 == 0) {
    trap(0x1c00);
  }
  if ((uVar2 == 0xffffffff) && (uVar3 == 0x80000000)) {
    trap(0x1800);
  }
  uVar2 = uVar3 / uVar2 & 0xffff;
  if (param_3 == (ushort *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = param_3[1] - uVar2;
  }
  if (param_4 == (ushort *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_4[1] - uVar2;
  }
  while ((iVar5 != 0 || (iVar4 != 0))) {
    if (iVar4 < 0) {
      uVar2 = -iVar4;
      if ((int)(uint)param_2[1] <= -iVar4) {
        uVar2 = (uint)param_2[1];
      }
      FUN_c012eef4(param_1,param_2,(int)param_4,param_5,param_6,uVar2);
      iVar4 = uVar2 + iVar4;
    }
    if (0 < iVar5) {
      iVar6 = (uint)*(ushort *)(param_1 + 0x38) - (uint)param_2[1];
      if (iVar5 < iVar6) {
        iVar6 = iVar5;
      }
      FUN_c012eef4(param_1,param_3,(int)param_2,param_5,param_6 - 1,iVar6);
      iVar5 = iVar5 - iVar6;
    }
    if (iVar5 < 0) {
      uVar2 = -iVar5;
      if ((int)(uint)param_2[1] <= -iVar5) {
        uVar2 = (uint)param_2[1];
      }
      FUN_c012ece0(param_1,param_2,(int)param_3,param_5,param_6,uVar2);
      iVar5 = uVar2 + iVar5;
    }
    if (0 < iVar4) {
      iVar6 = (uint)*(ushort *)(param_1 + 0x38) - (uint)param_2[1];
      if (iVar4 < iVar6) {
        iVar6 = iVar4;
      }
      FUN_c012ece0(param_1,param_4,(int)param_2,param_5,param_6 + 1,iVar6);
      iVar4 = iVar4 - iVar6;
    }
  }
  return;
}



/* c012f518 FUN_c012f518 */

/* Boundary evidence: original MIPS .pdata c012f518..c012f95b. Semantic name remains unreviewed. */

undefined4 FUN_c012f518(int param_1,int param_2)

{
  uint uVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  if (*(int *)(param_2 + 0x34) == 4) {
    uVar1 = FUN_c012de4c(param_1,param_2,*(uint *)(param_2 + 0x30));
    if ((((uVar1 != 0) &&
         (puVar2 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(uVar1 + 0xc)),
         puVar2 != (ushort *)0x0)) &&
        (puVar3 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(uVar1 + 0x10)),
        puVar3 != (ushort *)0x0)) &&
       (puVar4 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(uVar1 + 0x14)),
       puVar4 != (ushort *)0x0)) {
      uVar8 = (uint)*(ushort *)(param_2 + 0x3c) * 3;
      if (uVar8 <= (uint)puVar2[1] + (uint)puVar3[1] + (uint)puVar4[1]) {
        FUN_c012f28c(param_2,puVar3,puVar2,puVar4,uVar1,1);
        return 1;
      }
      uVar10 = *(uint *)(param_2 + 0x30);
      uVar11 = *(uint *)(puVar2 + 4);
      uVar9 = uVar8 - 1;
      if ((int)(uVar8 - 1) < 0) {
        uVar9 = uVar8;
      }
      FUN_c012eef4(param_2,puVar3,(int)puVar4,uVar1,1,((int)uVar9 >> 1 & 0xffffU) - (uint)puVar4[1])
      ;
      FUN_c012ece0(param_2,puVar3,(int)puVar2,uVar1,1,(uint)puVar3[1]);
      *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(puVar3 + 4);
      *(undefined4 *)(puVar4 + 2) = *(undefined4 *)(puVar3 + 2);
      param_2 = FUN_c012dfac(param_1,param_2,0,*(undefined4 *)(puVar3 + 2));
      FUN_c012df18(param_1,param_2,uVar10);
      FUN_c012df18(param_1,param_2,uVar11);
      uVar6 = 2;
LAB_c012f6d0:
      FUN_c012dfac(param_1,param_2,1,uVar6);
      return 1;
    }
  }
  else if (*(int *)(param_2 + 0x34) == 2) {
    uVar1 = *(uint *)(param_2 + 0x30);
    puVar2 = (ushort *)FUN_c012de4c(param_1,param_2,uVar1);
    if ((puVar2 != (ushort *)0x0) &&
       (puVar3 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar2 + 4)),
       puVar3 != (ushort *)0x0)) {
      uVar8 = (uint)puVar3[1];
      uVar9 = puVar2[1] + uVar8 & 0xffff;
      if (uVar9 <= (uint)*(ushort *)(param_2 + 0x3a) << 1) {
        if (*(ushort *)(param_2 + 0x3a) <= uVar9) {
          iVar7 = puVar2[1] - uVar8;
          if (iVar7 < 0) {
            iVar7 = iVar7 + 1;
          }
          iVar7 = iVar7 >> 1;
          if (0 < iVar7) {
            FUN_c012eef4(param_2,puVar2,(int)puVar3,0,0,iVar7);
            return 1;
          }
          FUN_c012ece0(param_2,puVar3,(int)puVar2,0,0,-iVar7);
          return 1;
        }
        FUN_c012ece0(param_2,puVar3,(int)puVar2,0,0,uVar8);
        FUN_c012df18(param_1,param_2,*(uint *)(puVar2 + 4));
        *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(param_2 + 0x24);
        uVar6 = 1;
        goto LAB_c012f6d0;
      }
      puVar5 = FUN_c012e018(param_1,param_2,uVar1);
      if ((puVar5 != (undefined2 *)0x0) &&
         (puVar4 = FUN_c012f130(param_1,param_2,uVar1,puVar2,*(undefined4 *)(puVar2 + 4),(int)puVar3
                                ,(int)puVar5,1), puVar4 != (ushort *)0x0)) {
        FUN_c012ebb4(param_2,(int)puVar5,
                     (void *)((puVar4[1] - 1) * (uint)*(ushort *)(param_2 + 0x2c) +
                              (*(ushort *)(param_2 + 0x38) + 4) * 4 + (int)puVar4),
                     *(undefined4 *)(puVar4 + 4),1,2);
        FUN_c012f28c(param_2,puVar4,puVar2,puVar3,(int)puVar5,1);
        return 1;
      }
    }
  }
  else {
    puVar2 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(param_2 + 0x30));
    if (puVar2 != (ushort *)0x0) {
      if (puVar2[1] <= *(ushort *)(param_2 + 0x3a)) {
        return 1;
      }
      puVar3 = FUN_c012f130(param_1,param_2,*(undefined4 *)(param_2 + 0x30),puVar2,
                            *(undefined4 *)(param_2 + 0x24),0,0,0);
      if (puVar3 != (ushort *)0x0) {
        FUN_c012eef4(param_2,puVar2,(int)puVar3,0,0,(uint)(puVar2[1] >> 1));
        return 1;
      }
    }
  }
  return 0;
}



/* c012f95c FUN_c012f95c */

/* Boundary evidence: original MIPS .pdata c012f95c..c012fd8b. Semantic name remains unreviewed. */

undefined4 FUN_c012f95c(int param_1,int param_2,uint param_3,ushort *param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  ushort uVar10;
  uint local_34;
  
  puVar1 = (ushort *)FUN_c012de4c(param_1,param_2,param_3);
  if (puVar1 == (ushort *)0x0) {
LAB_c012f9bc:
    uVar9 = 0;
  }
  else {
    uVar9 = 1;
    local_34 = param_3;
    if (*(ushort *)(param_2 + 0x3a) < puVar1[1]) {
      do {
        uVar7 = (uint)*param_4;
        if (uVar7 == 0) {
          puVar6 = FUN_c012e018(param_1,param_2,local_34);
          if ((puVar6 != (undefined2 *)0x0) &&
             (puVar2 = FUN_c012f130(param_1,param_2,local_34,puVar1,*(undefined4 *)(param_2 + 0x24),
                                    0,(int)puVar6,1), puVar2 != (ushort *)0x0)) {
            FUN_c012eef4(param_2,puVar1,(int)puVar2,(int)puVar6,0,(uint)(puVar1[1] >> 1));
            return 1;
          }
          goto LAB_c012f9bc;
        }
        local_34 = *(uint *)(param_4 + (uVar7 + 5) * 2);
        uVar10 = param_4[uVar7];
        puVar2 = (ushort *)FUN_c012de4c(param_1,param_2,local_34);
        if (puVar2 == (ushort *)0x0) goto LAB_c012f9bc;
        puVar3 = puVar1;
        puVar4 = puVar1;
        if (puVar2[1] == 1) {
          if (*(uint *)(puVar1 + 2) == *(uint *)(param_2 + 0x24)) {
            puVar4 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar1 + 4));
          }
          else {
            puVar3 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar1 + 2));
          }
          if ((puVar3 == (ushort *)0x0) || (puVar4 == (ushort *)0x0)) goto LAB_c012f9bc;
          if ((uint)puVar3[1] + (uint)puVar4[1] <= (uint)*(ushort *)(param_2 + 0x3a) << 1) {
            iVar8 = (uint)puVar3[1] - (uint)puVar4[1];
            if (iVar8 < 0) {
              iVar8 = iVar8 + 1;
            }
            iVar8 = iVar8 >> 1;
            if (0 < iVar8) {
              FUN_c012eef4(param_2,puVar3,(int)puVar4,(int)puVar2,0,iVar8);
              return 1;
            }
            FUN_c012ece0(param_2,puVar4,(int)puVar3,(int)puVar2,1,-iVar8);
            return 1;
          }
          uVar10 = 1;
          puVar1 = FUN_c012f130(param_1,param_2,*(undefined4 *)(puVar4 + 2),puVar3,
                                *(undefined4 *)(puVar3 + 4),(int)puVar4,(int)puVar2,1);
joined_r0xc012fc44:
          puVar5 = puVar1;
          if (puVar5 == (ushort *)0x0) goto LAB_c012f9bc;
        }
        else {
          if (uVar10 == 0) {
            puVar5 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar1 + 4));
            if ((puVar5 == (ushort *)0x0) ||
               (puVar4 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar5 + 4)),
               puVar4 == (ushort *)0x0)) goto LAB_c012f9bc;
            uVar10 = 1;
          }
          else if (uVar10 == puVar2[1]) {
            puVar5 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar1 + 2));
            if ((puVar5 == (ushort *)0x0) ||
               (puVar3 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar5 + 2)),
               puVar3 == (ushort *)0x0)) goto LAB_c012f9bc;
            uVar10 = uVar10 - 1;
          }
          else {
            puVar3 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar1 + 2));
            if ((puVar3 == (ushort *)0x0) ||
               (puVar4 = (ushort *)FUN_c012de4c(param_1,param_2,*(uint *)(puVar1 + 4)),
               puVar5 = puVar1, puVar4 == (ushort *)0x0)) goto LAB_c012f9bc;
          }
          if ((uint)*(ushort *)(param_2 + 0x3a) * 3 <
              (uint)puVar5[1] + (uint)puVar3[1] + (uint)puVar4[1]) {
            if (puVar3 == puVar1) {
              puVar1 = FUN_c012f130(param_1,param_2,*(undefined4 *)(puVar5 + 2),puVar3,
                                    *(undefined4 *)(puVar3 + 4),(int)puVar5,(int)puVar2,uVar10);
              puVar4 = puVar5;
            }
            else {
              uVar10 = uVar10 + 1;
              puVar1 = FUN_c012f130(param_1,param_2,*(undefined4 *)(puVar4 + 2),puVar5,
                                    *(undefined4 *)(puVar5 + 4),(int)puVar4,(int)puVar2,uVar10);
              puVar3 = puVar5;
            }
            goto joined_r0xc012fc44;
          }
        }
        FUN_c012f28c(param_2,puVar5,puVar3,puVar4,(int)puVar2,uVar10);
        *param_4 = *param_4 - 1;
        puVar1 = puVar2;
      } while (*(ushort *)(param_2 + 0x3a) < puVar2[1]);
    }
  }
  return uVar9;
}



/* c012fd8c FUN_c012fd8c */

/* Boundary evidence: original MIPS .pdata c012fd8c..c012ffcf. Semantic name remains unreviewed. */

undefined4 FUN_c012fd8c(int param_1,int param_2,PCNZWCH param_3,uint param_4,ushort param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort *puVar4;
  undefined1 *puVar5;
  undefined1 auStackY_a8 [16];
  ushort local_80 [12];
  undefined1 auStack_68 [16];
  uint local_38 [2];
  short local_30;
  short local_2e;
  uint local_2c;
  
  puVar5 = auStack_68;
  local_2c = DAT_c0136c78;
  puVar4 = (ushort *)0x0;
  if ((*(uint *)(param_2 + 0x10) & 0x200) != 0) {
    param_5 = param_5 | 0x8000;
  }
  uVar3 = 1;
  if (*(uint *)(param_2 + 0x34) < 4) {
    iVar1 = FUN_c012e64c(param_1,param_2,param_3,param_4,param_5,local_38,0xffff);
    if (iVar1 == 0) goto LAB_c012fe48;
  }
  else {
    puVar5 = auStackY_a8;
    puVar4 = local_80;
    iVar1 = FUN_c012e4d8(param_1,param_2,param_3,param_4,param_5,puVar4,local_38,0xffff);
    if (iVar1 == 0) goto LAB_c012fe48;
    local_80[0] = local_80[0] - 1;
  }
  uVar2 = FUN_c012de4c(param_1,param_2,local_38[0]);
  if (uVar2 != 0) {
    if ((local_2e == 3) || ((local_2e == 2 && (param_5 == 3)))) {
      *(short *)(puVar5 + 0x14) = local_30;
      *(short *)(puVar5 + 0x10) = local_30;
      FUN_c012ebb4(param_2,uVar2,param_3,param_4,*(ushort *)(puVar5 + 0x10),
                   *(ushort *)(puVar5 + 0x14));
    }
    else {
      *(short *)(puVar5 + 0x14) = local_30 + 1;
      *(short *)(puVar5 + 0x10) = local_30 + 1;
      FUN_c012ebb4(param_2,uVar2,param_3,param_4,*(ushort *)(puVar5 + 0x10),
                   *(ushort *)(puVar5 + 0x14));
    }
    iVar1 = param_2;
    if (*(int *)(param_2 + 0x34) == 0) {
      iVar1 = FUN_c012dfac(param_1,param_2,1,1);
    }
    if (*(ushort *)(param_2 + 0x3a) < *(ushort *)(uVar2 + 2)) {
      if (*(uint *)(param_2 + 0x34) < 4) {
        uVar3 = FUN_c012f518(param_1,iVar1);
      }
      else {
        uVar3 = FUN_c012f95c(param_1,iVar1,local_38[0],puVar4);
      }
    }
    FUN_c013331c(local_2c);
    return uVar3;
  }
LAB_c012fe48:
  FUN_c013331c(local_2c);
  return 0;
}



/* c012ffd0 FUN_c012ffd0 */

/* Boundary evidence: original MIPS .pdata c012ffd0..c01300a7. Semantic name remains unreviewed. */

void FUN_c012ffd0(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  memmove((void *)((param_4 + 3) * 4 + param_2),(void *)((param_4 + 4) * 4 + param_2),
          ((uint)*(ushort *)(param_2 + 2) - param_4) * 4);
  uVar1 = (uint)*(ushort *)(param_1 + 0x2c);
  iVar2 = (*(ushort *)(param_1 + 0x38) + 4) * 4;
  memmove((void *)(param_3 * uVar1 + iVar2 + param_2),
          (void *)((param_3 + 1) * uVar1 + iVar2 + param_2),
          (((uint)*(ushort *)(param_2 + 2) - param_3) + -1) * uVar1);
  *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + -1;
  return;
}



/* c01300a8 FUN_c01300a8 */

/* WARNING: Removing unreachable block (ram,0xc013035c) */
/* Boundary evidence: original MIPS .pdata c01300a8..c013058f. Semantic name remains unreviewed. */

undefined4 FUN_c01300a8(int param_1,int param_2,uint param_3,ushort *param_4)

{
  undefined4 uVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  ushort uVar10;
  uint uVar11;
  
  if (*(uint *)(param_2 + 0x34) < 5) {
    uVar1 = FUN_c012f518(param_1,param_2);
  }
  else {
    puVar2 = (ushort *)FUN_c012de4c(param_1,param_2,param_3);
    if (puVar2 == (ushort *)0x0) {
LAB_c013055c:
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
      iVar7 = param_2;
      if (puVar2[1] < *(ushort *)(param_2 + 0x3c)) {
        do {
          uVar8 = (uint)*param_4;
          if (uVar8 == 0) {
            return 1;
          }
          uVar11 = (uint)param_4[uVar8];
          puVar3 = (ushort *)FUN_c012de4c(param_1,iVar7,*(uint *)(param_4 + (uVar8 + 5) * 2));
          if (puVar3 == (ushort *)0x0) goto LAB_c013055c;
          if (puVar3[1] == 1) {
            if (*(uint *)(puVar2 + 2) == *(uint *)(iVar7 + 0x24)) {
              puVar5 = (ushort *)FUN_c012de4c(param_1,iVar7,*(uint *)(puVar2 + 4));
            }
            else {
              puVar4 = (ushort *)FUN_c012de4c(param_1,iVar7,*(uint *)(puVar2 + 2));
              puVar5 = puVar2;
              puVar2 = puVar4;
            }
            if ((puVar2 == (ushort *)0x0) || (puVar5 == (ushort *)0x0)) goto LAB_c013055c;
            if ((int)((uint)puVar2[1] + (uint)puVar5[1]) < (int)(*(ushort *)(param_2 + 0x3a) - 1)) {
              FUN_c012ece0(iVar7,puVar5,(int)puVar2,(int)puVar3,1,(uint)puVar5[1]);
              FUN_c012ebb4(iVar7,(int)puVar2,puVar3 + (*(ushort *)(param_2 + 0x38) + 4) * 2,
                           *(undefined4 *)(puVar5 + 6),puVar2[1],puVar2[1] + 1);
              uVar1 = *(undefined4 *)(puVar5 + 2);
              FUN_c012df18(param_1,iVar7,*(uint *)(param_2 + 0x30));
              FUN_c012df18(param_1,iVar7,*(uint *)(puVar2 + 4));
              *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(iVar7 + 0x24);
              iVar7 = FUN_c012dfac(param_1,iVar7,0,uVar1);
              FUN_c012dfac(param_1,iVar7,1,*(int *)(param_2 + 0x34) + -2);
              return 1;
            }
            iVar9 = (uint)puVar2[1] - (uint)puVar5[1];
            if (iVar9 < 0) {
              iVar9 = iVar9 + 1;
            }
            iVar9 = iVar9 >> 1;
            if (iVar9 < 1) {
              FUN_c012ece0(iVar7,puVar5,(int)puVar2,(int)puVar3,1,-iVar9);
            }
            else {
              FUN_c012eef4(iVar7,puVar2,(int)puVar5,(int)puVar3,0,iVar9);
            }
          }
          else {
            if (uVar11 == 0) {
              puVar4 = (ushort *)FUN_c012de4c(param_1,iVar7,*(uint *)(puVar2 + 4));
              if ((puVar4 == (ushort *)0x0) ||
                 (puVar6 = (ushort *)FUN_c012de4c(param_1,iVar7,*(uint *)(puVar4 + 4)),
                 puVar6 == (ushort *)0x0)) goto LAB_c013055c;
              uVar11 = 1;
              puVar5 = puVar2;
            }
            else if (uVar11 == puVar3[1]) {
              puVar4 = (ushort *)FUN_c012de4c(param_1,iVar7,*(uint *)(puVar2 + 2));
              if ((puVar4 == (ushort *)0x0) ||
                 (puVar5 = (ushort *)FUN_c012de4c(param_1,iVar7,*(uint *)(puVar4 + 2)),
                 puVar5 == (ushort *)0x0)) goto LAB_c013055c;
              uVar11 = uVar11 + 0xffff & 0xffff;
              puVar6 = puVar2;
            }
            else {
              puVar5 = (ushort *)FUN_c012de4c(param_1,iVar7,*(uint *)(puVar2 + 2));
              if ((puVar5 == (ushort *)0x0) ||
                 (puVar6 = (ushort *)FUN_c012de4c(param_1,iVar7,*(uint *)(puVar2 + 4)),
                 puVar4 = puVar2, puVar6 == (ushort *)0x0)) goto LAB_c013055c;
            }
            uVar8 = (uint)puVar6[1] + (uint)puVar4[1] + (uint)puVar5[1] & 0xffff;
            uVar10 = (ushort)uVar11;
            if ((uint)*(ushort *)(param_2 + 0x3c) * 3 <= uVar8) {
              FUN_c012f28c(iVar7,puVar4,puVar5,puVar6,(int)puVar3,uVar10);
              return 1;
            }
            FUN_c012eef4(iVar7,puVar4,(int)puVar6,(int)puVar3,uVar10,
                         ((int)(uVar8 + 1) >> 1) - (uint)puVar6[1]);
            FUN_c012ece0(iVar7,puVar4,(int)puVar5,(int)puVar3,uVar10,(uint)puVar4[1]);
            if ((*puVar4 & 2) == 0) {
              FUN_c012ebb4(iVar7,(int)puVar5,
                           (void *)((uVar11 - 1) * (uint)*(ushort *)(iVar7 + 0x2c) +
                                    (*(ushort *)(param_2 + 0x38) + 4) * 4 + (int)puVar3),
                           *(undefined4 *)(puVar4 + 6),puVar5[1],puVar5[1] + 1);
            }
            FUN_c012ffd0(iVar7,(int)puVar3,uVar11 + 0xffff & 0xffff,uVar11);
            uVar8 = *(uint *)(puVar5 + 4);
            *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(puVar4 + 4);
            *(undefined4 *)(puVar6 + 2) = *(undefined4 *)(puVar4 + 2);
            FUN_c012df18(param_1,iVar7,uVar8);
            iVar7 = FUN_c012dfac(param_1,iVar7,1,*(int *)(param_2 + 0x34) + -1);
          }
          *param_4 = *param_4 - 1;
          puVar2 = puVar3;
        } while (puVar3[1] < *(ushort *)(param_2 + 0x3c));
      }
    }
  }
  return uVar1;
}



/* c0130590 FUN_c0130590 */

/* Boundary evidence: original MIPS .pdata c0130590..c0130713. Semantic name remains unreviewed. */

undefined4 FUN_c0130590(int param_1,int param_2,PCNZWCH param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort auStack_80 [34];
  uint local_3c;
  undefined4 local_38;
  uint auStack_30 [3];
  uint local_24;
  
  local_24 = DAT_c0136c78;
  puVar1 = FUN_c012e880(auStack_30,param_1,param_2,2,param_3,param_4,auStack_80,0xffff);
  uVar4 = *puVar1;
  local_3c = puVar1[1];
  local_38 = puVar1[2];
  uVar2 = FUN_c012de4c(param_1,param_2,uVar4);
  if (((uVar2 == 0) || (local_38._2_2_ != 2)) || (uVar4 == *(uint *)(param_2 + 0x24))) {
    FUN_c013331c(local_24);
    uVar3 = 0;
  }
  else {
    FUN_c012ffd0(param_2,uVar2,local_38 & 0xffff,local_38 & 0xffff);
    uVar3 = 1;
    if (*(ushort *)(uVar2 + 2) == 0) {
      FUN_c012dfac(param_1,param_2,1,0);
    }
    else if (*(ushort *)(uVar2 + 2) < *(ushort *)(param_2 + 0x3c)) {
      if (*(uint *)(param_2 + 0x34) < 5) {
        FUN_c012f518(param_1,param_2);
      }
      else {
        FUN_c01300a8(param_1,param_2,uVar4,auStack_80);
      }
    }
    FUN_c013331c(local_24);
  }
  return uVar3;
}



/* c0130714 FUN_c0130714 */

/* Boundary evidence: original MIPS .pdata c0130714..c0130b43. Semantic name remains unreviewed. */

uint * FUN_c0130714(uint *param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                   int param_7,uint param_8,void *param_9)

{
  ushort *puVar1;
  DWORD dwErrCode;
  uint uVar2;
  uint uVar3;
  
  SetLastError(0);
  uVar2 = param_8;
  if (*(int *)(param_3 + 0x34) == 0) {
LAB_c0130794:
    param_8 = uVar2;
    dwErrCode = 0x19;
LAB_c0130798:
    SetLastError(dwErrCode);
  }
  else if (param_5 == 8) {
    puVar1 = (ushort *)FUN_c012de4c(param_2,param_3,param_6);
    if ((((puVar1 == (ushort *)0x0) || ((*puVar1 & 2) == 0)) ||
        (uVar3 = param_8 & 0xffff, puVar1[1] <= uVar3)) ||
       (*(int *)(puVar1 + (uVar3 + 3) * 2) != param_7)) {
      dwErrCode = 0x57;
      goto LAB_c0130798;
    }
joined_r0xc0130940:
    do {
      while( true ) {
        param_8 = uVar2;
        if (param_4 < 1) goto joined_r0xc0130a0c;
        param_8._2_2_ = (ushort)(uVar2 >> 0x10);
        if ((int)(uint)puVar1[1] <= (int)(uVar3 + param_4)) break;
        uVar2 = uVar3 + param_4;
        uVar3 = uVar2 & 0xffff;
        param_8 = CONCAT22(param_8._2_2_,(short)uVar2);
        param_4 = 0;
        uVar2 = param_8;
      }
      param_6 = *(uint *)(puVar1 + 4);
      if (param_6 == *(uint *)(param_3 + 0x24)) goto LAB_c0130794;
      param_4 = (uVar3 - puVar1[1]) + param_4;
      uVar3 = 0;
      param_8 = (uint)param_8._2_2_ << 0x10;
      puVar1 = (ushort *)FUN_c012de4c(param_2,param_3,param_6);
      uVar2 = param_8;
    } while (puVar1 != (ushort *)0x0);
  }
  else if (param_5 == 2) {
    param_6 = *(uint *)(param_3 + 0x30);
    while (puVar1 = (ushort *)FUN_c012de4c(param_2,param_3,param_6), puVar1 != (ushort *)0x0) {
      if ((*puVar1 & 2) != 0) {
        uVar3 = 0;
        goto LAB_c013093c;
      }
      param_6 = *(uint *)(puVar1 + 6);
    }
  }
  else if (param_5 == 4) {
    param_6 = *(uint *)(param_3 + 0x30);
    if (*(int *)(param_3 + 0x34) == 2) {
      uVar2 = FUN_c012de4c(param_2,param_3,param_6);
      if (uVar2 != 0) {
        param_6 = *(uint *)(uVar2 + 8);
        puVar1 = (ushort *)FUN_c012de4c(param_2,param_3,param_6);
        if (puVar1 != (ushort *)0x0) {
LAB_c013092c:
          uVar3 = puVar1[1] + 0xffff & 0xffff;
LAB_c013093c:
          param_8 = CONCAT22(param_8._2_2_,(short)uVar3);
          uVar2 = param_8;
          goto joined_r0xc0130940;
        }
      }
    }
    else {
      while (puVar1 = (ushort *)FUN_c012de4c(param_2,param_3,param_6), puVar1 != (ushort *)0x0) {
        if ((*puVar1 & 2) != 0) goto LAB_c013092c;
        param_6 = *(uint *)(puVar1 + (puVar1[1] + 3) * 2);
      }
    }
  }
  else {
    SetLastError(0x57);
  }
LAB_c0130af0:
  uVar2 = *(uint *)(param_3 + 0x28);
  *param_1 = *(uint *)(param_3 + 0x24);
  param_1[1] = uVar2;
LAB_c0130b00:
  param_1[2] = param_8;
  return param_1;
joined_r0xc0130a0c:
  if (-1 < param_4) goto LAB_c0130a80;
  if ((int)(uVar3 + param_4) < 0) {
    param_6 = *(uint *)(puVar1 + 2);
    uVar2 = param_8;
    if (param_6 == *(uint *)(param_3 + 0x24)) goto LAB_c0130794;
    param_4 = uVar3 + param_4 + 1;
    puVar1 = (ushort *)FUN_c012de4c(param_2,param_3,param_6);
    if (puVar1 == (ushort *)0x0) goto LAB_c0130af0;
    uVar2 = puVar1[1] + 0xffff;
  }
  else {
    uVar2 = uVar3 + param_4;
    param_4 = 0;
  }
  uVar3 = uVar2 & 0xffff;
  param_8._2_2_ = (ushort)(param_8 >> 0x10);
  param_8 = CONCAT22(param_8._2_2_,(short)uVar2);
  goto joined_r0xc0130a0c;
LAB_c0130a80:
  uVar2 = *(uint *)(puVar1 + (uVar3 + 3) * 2);
  if (param_9 != (void *)0x0) {
    memcpy(param_9,(void *)((*(ushort *)(param_3 + 0x38) + 4) * 4 +
                            *(ushort *)(param_3 + 0x2c) * uVar3 + (int)puVar1),
           (uint)*(ushort *)(param_3 + 0x2c));
  }
  *param_1 = param_6;
  param_1[1] = uVar2;
  goto LAB_c0130b00;
}



/* c0130b44 FUN_c0130b44 */

/* Boundary evidence: original MIPS .pdata c0130b44..c0130b4f. Semantic name remains unreviewed. */

undefined4 FUN_c0130b44(void)

{
  return 1;
}



/* c0130b50 FUN_c0130b50 */

/* Boundary evidence: original MIPS .pdata c0130b50..c0130c43. Semantic name remains unreviewed. */

uint FUN_c0130b50(int param_1,int param_2,uint param_3,int param_4,ushort param_5)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = (ushort *)FUN_c012de4c(param_1,param_2,param_3);
  if ((((puVar1 == (ushort *)0x0) || ((*puVar1 & 2) == 0)) ||
      (uVar4 = (uint)param_5, puVar1[1] <= uVar4)) ||
     (*(int *)(puVar1 + (uVar4 + 3) * 2) != param_4)) {
    SetLastError(0x57);
LAB_c0130c1c:
    uVar4 = 0xffffffff;
  }
  else {
    uVar3 = *(uint *)(puVar1 + 2);
    if (uVar3 != *(uint *)(param_2 + 0x24)) {
      do {
        uVar2 = FUN_c012de4c(param_1,param_2,uVar3);
        if (uVar2 == 0) goto LAB_c0130c1c;
        uVar3 = *(uint *)(uVar2 + 4);
        uVar4 = *(ushort *)(uVar2 + 2) + uVar4;
      } while (uVar3 != *(uint *)(param_2 + 0x24));
    }
  }
  return uVar4;
}



/* c0130c44 FUN_c0130c44 */

/* Boundary evidence: original MIPS .pdata c0130c44..c0130e1b. Semantic name remains unreviewed. */

uint * FUN_c0130c44(uint *param_1,int param_2,int param_3,int param_4,PCNZWCH param_5,uint param_6,
                   ushort param_7)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint auStack_80 [4];
  ushort auStack_70 [32];
  uint local_30;
  
  local_30 = DAT_c0136c78;
  if (param_4 == 4) {
    iVar2 = 1;
  }
  else {
    iVar2 = 3;
    if (param_4 != 5) {
      iVar2 = param_4;
    }
  }
  puVar1 = FUN_c012e880(auStack_80,param_2,param_3,iVar2,param_5,param_6,auStack_70,param_7);
  uVar3 = *puVar1;
  uVar4 = puVar1[1];
  uVar5 = puVar1[2];
  uVar6 = *(uint *)(param_3 + 0x24);
  *param_1 = uVar3;
  param_1[1] = uVar4;
  param_1[2] = uVar5;
  if ((uVar3 != uVar6) && (param_4 != 2)) {
    if (((param_4 == 1) || (param_4 == 5)) && (*(short *)((int)param_1 + 10) == 3)) {
      puVar1 = FUN_c0130714(auStack_80,param_2,param_3,-1,8,*puVar1,puVar1[1],puVar1[2],(void *)0x0)
      ;
    }
    else {
      if (((param_4 != 3) && (param_4 != 4)) || (*(short *)((int)param_1 + 10) != 1))
      goto LAB_c0130de4;
      puVar1 = FUN_c0130714(auStack_80,param_2,param_3,1,8,*puVar1,puVar1[1],puVar1[2],(void *)0x0);
    }
    uVar4 = puVar1[1];
    uVar3 = *puVar1;
    param_1[2] = puVar1[2];
    *(short *)((int)param_1 + 10) = (short)param_4;
    param_1[1] = uVar4;
    *param_1 = uVar3;
  }
LAB_c0130de4:
  FUN_c013331c(local_30);
  return param_1;
}



/* c01314cc FUN_c01314cc */

void FUN_c01314cc(int *param_1,uint param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = 0x3020100;
  iVar6 = 0x40;
  piVar2 = param_1;
  do {
    *piVar2 = iVar4;
    piVar2 = piVar2 + 1;
    iVar6 = iVar6 + -1;
    iVar4 = iVar4 + 0x4040404;
  } while (iVar6 != 0);
  *(undefined1 *)(param_1 + 0x40) = 0;
  uVar3 = 0;
  *(undefined1 *)((int)param_1 + 0x101) = 0;
  uVar7 = 0;
  uVar5 = 0;
  do {
    bVar1 = *(byte *)(uVar5 + (int)param_1);
    uVar7 = (uint)*(byte *)(uVar3 + param_3) + (uint)bVar1 + uVar7 & 0xff;
    *(byte *)(uVar5 + (int)param_1) = *(byte *)(uVar7 + (int)param_1);
    *(byte *)(uVar7 + (int)param_1) = bVar1;
    uVar3 = uVar3 + 1 & 0xff;
    uVar5 = uVar5 + 1;
    if (uVar3 == param_2) {
      uVar3 = 0;
    }
  } while (uVar5 < 0x100);
  return;
}



/* c0131560 FUN_c0131560 */

void FUN_c0131560(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  uVar2 = (uint)*(byte *)(param_1 + 0x100);
  uVar4 = (uint)*(byte *)(param_1 + 0x101);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar2 = uVar2 + 1 & 0xff;
    pbVar3 = (byte *)(uVar2 + param_1);
    bVar1 = *pbVar3;
    uVar4 = bVar1 + uVar4 & 0xff;
    *pbVar3 = *(byte *)(uVar4 + param_1);
    *(byte *)(uVar4 + param_1) = bVar1;
    *param_3 = *(byte *)(((uint)*pbVar3 + (uint)bVar1 & 0xff) + param_1) ^ *param_3;
    param_3 = param_3 + 1;
  }
  *(char *)(param_1 + 0x100) = (char)uVar2;
  *(char *)(param_1 + 0x101) = (char)uVar4;
  return;
}



/* c01315cc FSD_FsIoControl */

undefined4 FSD_FsIoControl(void)

{
                    /* 0x415cc  19  FSD_FsIoControl */
  return 0;
}



/* c01315d4 FUN_c01315d4 */

/* Boundary evidence: original MIPS .pdata c01315d4..c01316a3. Semantic name remains unreviewed. */

undefined4 * FUN_c01315d4(wchar_t *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  size_t sVar2;
  void *_Dst;
  uint uVar3;
  uint _Size;
  
  puVar1 = operator_new(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    sVar2 = wcslen(param_1);
    _Size = (sVar2 + 1) * 2;
    *puVar1 = 0x47444744;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[4] = 0;
    puVar1[2] = param_2;
    puVar1[3] = 0;
    if (_Size < 0x80000000) {
      uVar3 = (sVar2 + 1) * 4;
    }
    else {
      uVar3 = 0xffffffff;
    }
    _Dst = operator_new(uVar3);
    puVar1[1] = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_1,_Size);
    }
  }
  return puVar1;
}



/* c01316a4 FUN_c01316a4 */

/* Boundary evidence: original MIPS .pdata c01316a4..c01317f3. Semantic name remains unreviewed. */

undefined4 * FUN_c01316a4(wchar_t *param_1)

{
  size_t sVar1;
  undefined4 *puVar2;
  void *_Dst;
  uint uVar3;
  uint _Size;
  
  sVar1 = wcslen(param_1);
  _Size = (sVar1 + 1) * 2;
  puVar2 = operator_new(0x2c);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0xffffffff;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 1));
    *puVar2 = 0x47544754;
    puVar2[7] = 0;
    if (_Size < 0x80000000) {
      uVar3 = (sVar1 + 1) * 4;
    }
    else {
      uVar3 = 0xffffffff;
    }
    _Dst = operator_new(uVar3);
    puVar2[6] = _Dst;
    puVar2[9] = 0;
    puVar2[8] = 0;
    puVar2[10] = 0;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_1,_Size);
    }
    if (DAT_c0137124 == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0137110);
      DAT_c0137124 = CreateAPISet(&DAT_c00f47a8,3,&DAT_c00f4784,&DAT_c00f4790);
      RegisterDirectMethods(DAT_c0137124,&PTR_FUN_c00f4778);
      RegisterAPISet(DAT_c0137124,0x80000008);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0137110);
    if (DAT_c0137128 != (undefined4 *)0x0) {
      puVar2[10] = DAT_c0137128;
    }
    DAT_c0137128 = puVar2;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0137110);
  }
  return puVar2;
}



/* c01317f4 FUN_c01317f4 */

/* Boundary evidence: original MIPS .pdata c01317f4..c013184f. Semantic name remains unreviewed. */

void FUN_c01317f4(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x20);
  while (iVar1 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x20) = puVar2[3];
    operator_delete((void *)*puVar2);
    operator_delete(puVar2);
    iVar1 = *(int *)(param_1 + 0x20);
  }
  return;
}



/* c0131850 FUN_c0131850 */

/* Boundary evidence: original MIPS .pdata c0131850..c0131c3f. Semantic name remains unreviewed. */

undefined4 *
FUN_c0131850(int param_1,wchar_t *param_2,int *param_3,int param_4,int param_5,undefined4 *param_6)

{
  wchar_t wVar1;
  size_t sVar2;
  wchar_t *_Dest;
  wchar_t *pwVar3;
  uint uVar4;
  wchar_t *_Str1;
  undefined4 *puVar5;
  wchar_t *_Str;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  char local_38;
  undefined4 *local_30;
  int local_2c;
  
  puVar8 = *(undefined4 **)(param_1 + 0x1c);
  wVar1 = *param_2;
  while ((wVar1 != L'\0' && (wVar1 == L'\\'))) {
    param_2 = param_2 + 1;
    wVar1 = *param_2;
  }
  sVar2 = wcslen(param_2);
  uVar6 = 0xffffffff;
  uVar4 = (sVar2 + 1) * 2;
  if (0x7fffffff < sVar2 + 1) {
    uVar4 = uVar6;
  }
  _Dest = operator_new(uVar4);
  if (_Dest == (wchar_t *)0x0) {
LAB_c0131900:
    puVar5 = (undefined4 *)0x0;
  }
  else {
    wcscpy(_Dest,param_2);
    local_30 = (undefined4 *)0x0;
    puVar5 = (undefined4 *)0x0;
    if (param_3 != (int *)0x0) {
      *param_3 = 0;
    }
    local_38 = '\0';
    _Str1 = _Dest;
    local_2c = param_4;
    if (*_Dest != L'\0') {
      do {
        wVar1 = *_Str1;
        _Str = _Str1;
        while ((wVar1 != L'\0' && (*_Str != L'\\'))) {
          _Str = _Str + 1;
          wVar1 = *_Str;
        }
        if (*_Str == L'\0') {
          if (local_2c != 0) {
            local_2c = 0;
            goto LAB_c0131a64;
          }
          if ((*_Str1 != L'\0') && (param_3 != (int *)0x0)) {
            sVar2 = wcslen(_Str1);
            uVar4 = (sVar2 + 1) * 2;
            if (0x7fffffff < sVar2 + 1) {
              uVar4 = uVar6;
            }
            pwVar3 = operator_new(uVar4);
            *param_3 = (int)pwVar3;
            if (pwVar3 != (wchar_t *)0x0) {
              wcscpy(pwVar3,_Str1);
            }
          }
        }
        else {
          *_Str = L'\0';
          _Str = _Str + 1;
LAB_c0131a64:
          puVar7 = (undefined4 *)0x0;
          puVar9 = puVar8;
          if (puVar8 != (undefined4 *)0x0) {
            do {
              puVar9 = puVar8;
              if ((wchar_t *)puVar8[1] == (wchar_t *)0x0) goto LAB_c0131ab0;
              uVar4 = _wcsicmp(_Str1,(wchar_t *)puVar8[1]);
            } while ((0 < (int)uVar4) &&
                    (puVar9 = (undefined4 *)puVar8[7], uVar4 = uVar6, puVar7 = puVar8,
                    puVar8 = puVar9, puVar9 != (undefined4 *)0x0));
            if (uVar4 == 0) {
              puVar8 = (undefined4 *)puVar9[5];
              puVar5 = puVar9;
              local_30 = puVar9;
              goto LAB_c01319d8;
            }
          }
LAB_c0131ab0:
          if (param_5 != 0) {
            if ((param_6 != (undefined4 *)0x0) && ((*_Str != L'\0' || (param_3 == (int *)0x0)))) {
              *param_6 = 0;
            }
            if (*_Str == L'\0') {
              if (((*_Str1 == L'\0') || (param_3 == (int *)0x0)) || (param_6 == (undefined4 *)0x0))
              goto LAB_c0131c08;
              sVar2 = wcslen(_Str1);
              if (sVar2 + 1 < 0x80000000) {
                uVar6 = (sVar2 + 1) * 2;
              }
              pwVar3 = operator_new(uVar6);
              *param_3 = (int)pwVar3;
            }
            else {
              if (param_3 == (int *)0x0) goto LAB_c0131c08;
              sVar2 = wcslen(_Str);
              if (sVar2 + 1 < 0x80000000) {
                uVar6 = (sVar2 + 1) * 2;
              }
              pwVar3 = operator_new(uVar6);
              *param_3 = (int)pwVar3;
              _Str1 = _Str;
            }
            if (pwVar3 == (wchar_t *)0x0) goto LAB_c0131c08;
            goto LAB_c0131c00;
          }
          puVar5 = FUN_c01315d4(_Str1,param_1);
          if (puVar5 == (undefined4 *)0x0) goto LAB_c0131900;
          *(char *)(puVar5 + 9) = local_38;
          if (puVar7 == (undefined4 *)0x0) {
            if (local_30 == (undefined4 *)0x0) {
              *(undefined4 **)(param_1 + 0x1c) = puVar5;
            }
            else {
              local_30[5] = puVar5;
            }
          }
          else {
            puVar7[7] = puVar5;
          }
          if (puVar9 != (undefined4 *)0x0) {
            puVar9[8] = puVar5;
          }
          puVar5[8] = puVar7;
          puVar5[7] = puVar9;
          puVar5[6] = local_30;
          puVar8 = (undefined4 *)0x0;
          local_30 = puVar5;
          if (*(int *)(param_1 + 0x1c) == 0) {
            *(undefined4 **)(param_1 + 0x1c) = puVar5;
          }
        }
LAB_c01319d8:
        local_38 = local_38 + '\x01';
        _Str1 = _Str;
      } while (*_Str != L'\0');
      if (((puVar5 != (undefined4 *)0x0) && (param_3 != (int *)0x0)) &&
         ((*param_3 == 0 && ((wchar_t *)puVar5[1] != (wchar_t *)0x0)))) {
        sVar2 = wcslen((wchar_t *)puVar5[1]);
        if (sVar2 + 1 < 0x80000000) {
          uVar6 = (sVar2 + 1) * 2;
        }
        pwVar3 = operator_new(uVar6);
        *param_3 = (int)pwVar3;
        if (pwVar3 != (wchar_t *)0x0) {
          _Str1 = (wchar_t *)puVar5[1];
LAB_c0131c00:
          wcscpy(pwVar3,_Str1);
        }
      }
    }
LAB_c0131c08:
    operator_delete(_Dest);
  }
  return puVar5;
}



/* c0131c40 FUN_c0131c40 */

/* Boundary evidence: original MIPS .pdata c0131c40..c0131e8b. Semantic name remains unreviewed. */

undefined4
FUN_c0131c40(int param_1,HANDLE param_2,wchar_t *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  HANDLE pvVar3;
  BOOL BVar4;
  int iVar5;
  LPHANDLE lpTargetHandle;
  HANDLE local_20;
  HANDLE local_1c;
  
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  puVar1 = FUN_c0131850(param_1,param_3,(int *)0x0,1,0,(undefined4 *)0x0);
  puVar2 = operator_new(0x34);
  if (puVar2 == (undefined4 *)0x0) {
LAB_c0131cac:
    if (param_1 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    }
    return 0xffffffff;
  }
  puVar2[6] = 0;
  *puVar2 = 0x44474447;
  puVar2[2] = param_5;
  puVar2[1] = param_2;
  puVar2[3] = param_4;
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  puVar2[4] = pvVar3;
  if (pvVar3 == (HANDLE)0x0) {
    operator_delete(puVar2);
    goto LAB_c0131cac;
  }
  puVar2[10] = puVar1;
  puVar2[0xc] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    if (param_1 == 0) goto LAB_c0131d80;
    puVar2[0xb] = *(undefined4 *)(param_1 + 0x20);
    if (*(int *)(param_1 + 0x20) != 0) {
      *(undefined4 **)(*(int *)(param_1 + 0x20) + 0x30) = puVar2;
    }
    *(undefined4 **)(param_1 + 0x20) = puVar2;
  }
  else {
    puVar2[0xb] = puVar1[3];
    if (puVar1[3] != 0) {
      *(undefined4 **)(puVar1[3] + 0x30) = puVar2;
    }
    puVar1[3] = puVar2;
  }
  if (param_1 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
LAB_c0131d80:
  puVar2[7] = param_1;
  local_20 = (HANDLE)CreateAPIHandle(DAT_c0137124,puVar2);
  pvVar3 = (HANDLE)__GetUserKData(0xc);
  lpTargetHandle = (LPHANDLE)(puVar2 + 5);
  BVar4 = DuplicateHandle(pvVar3,local_20,param_2,lpTargetHandle,0,0,3);
  if (BVar4 == 0) {
    return 0xffffffff;
  }
  iVar5 = SetEventData(puVar2[4],*lpTargetHandle);
  if (iVar5 != 0) {
    pvVar3 = (HANDLE)__GetUserKData(0xc);
    BVar4 = DuplicateHandle(pvVar3,(HANDLE)puVar2[4],param_2,&local_1c,0,0,2);
    if (BVar4 != 0) {
      return local_1c;
    }
  }
  pvVar3 = (HANDLE)__GetUserKData(0xc);
  DuplicateHandle(param_2,*lpTargetHandle,pvVar3,&local_20,0,0,3);
  CloseHandle(local_20);
  return 0xffffffff;
}



/* c0131e8c FUN_c0131e8c */

/* Boundary evidence: original MIPS .pdata c0131e8c..c0131f6b. Semantic name remains unreviewed. */

void FUN_c0131e8c(int param_1,void *param_2)

{
  void *pvVar1;
  
  while ((((param_2 != (void *)0x0 && (*(int *)((int)param_2 + 0x10) == 0)) &&
          (*(int *)((int)param_2 + 0xc) == 0)) && (*(int *)((int)param_2 + 0x14) == 0))) {
    pvVar1 = *(void **)((int)param_2 + 0x18);
    if (pvVar1 == (void *)0x0) {
      if (*(void **)(param_1 + 0x1c) == param_2) {
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)((int)param_2 + 0x1c);
      }
    }
    else if (*(void **)((int)pvVar1 + 0x14) == param_2) {
      *(undefined4 *)((int)pvVar1 + 0x14) = *(undefined4 *)((int)param_2 + 0x1c);
    }
    if (*(int *)((int)param_2 + 0x20) != 0) {
      *(undefined4 *)(*(int *)((int)param_2 + 0x20) + 0x1c) = *(undefined4 *)((int)param_2 + 0x1c);
    }
    if (*(int *)((int)param_2 + 0x1c) != 0) {
      *(undefined4 *)(*(int *)((int)param_2 + 0x1c) + 0x20) = *(undefined4 *)((int)param_2 + 0x20);
    }
    if (*(void **)((int)param_2 + 4) != (void *)0x0) {
      operator_delete(*(void **)((int)param_2 + 4));
    }
    operator_delete(param_2);
    param_2 = pvVar1;
  }
  return;
}



/* c0131f6c FUN_c0131f6c */

/* Boundary evidence: original MIPS .pdata c0131f6c..c013204f. Semantic name remains unreviewed. */

undefined4 FUN_c0131f6c(void *param_1)

{
  int iVar1;
  
  if (*(int *)((int)param_1 + 0x1c) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)((int)param_1 + 0x1c) + 4));
    iVar1 = *(int *)((int)param_1 + 0x28);
    if (iVar1 == 0) {
      if (*(void **)(*(int *)((int)param_1 + 0x1c) + 0x20) == param_1) {
        *(undefined4 *)(*(int *)((int)param_1 + 0x1c) + 0x20) = *(undefined4 *)((int)param_1 + 0x2c)
        ;
      }
    }
    else if (*(void **)(iVar1 + 0xc) == param_1) {
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)((int)param_1 + 0x2c);
    }
    if (*(int *)((int)param_1 + 0x30) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x30) + 0x2c) = *(undefined4 *)((int)param_1 + 0x2c);
    }
    if (*(int *)((int)param_1 + 0x2c) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x2c) + 0x30) = *(undefined4 *)((int)param_1 + 0x30);
    }
    if (*(void **)((int)param_1 + 0x28) != (void *)0x0) {
      FUN_c0131e8c(*(int *)((int)param_1 + 0x1c),*(void **)((int)param_1 + 0x28));
    }
    if (*(int *)((int)param_1 + 0x1c) != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)((int)param_1 + 0x1c) + 4));
    }
  }
  FUN_c01317f4((int)param_1);
  CloseHandle(*(HANDLE *)((int)param_1 + 0x10));
  operator_delete(param_1);
  return 1;
}



/* c0132050 FUN_c0132050 */

/* Boundary evidence: original MIPS .pdata c0132050..c013216b. Semantic name remains unreviewed. */

void FUN_c0132050(int param_1,wchar_t *param_2,uint param_3,undefined4 param_4)

{
  size_t sVar1;
  undefined4 *puVar2;
  wchar_t *_Dest;
  uint uVar3;
  
  if (param_2 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_2);
    for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x2c)) {
      if ((((*(uint *)(param_1 + 8) & 0x80000000) != 0) && ((*(uint *)(param_1 + 8) & param_3) != 0)
          ) && (puVar2 = operator_new(0x10), puVar2 != (undefined4 *)0x0)) {
        puVar2[1] = sVar1 << 1;
        if (sVar1 + 1 < 0x80000000) {
          uVar3 = (sVar1 + 1) * 2;
        }
        else {
          uVar3 = 0xffffffff;
        }
        _Dest = operator_new(uVar3);
        *puVar2 = _Dest;
        if (_Dest != (wchar_t *)0x0) {
          wcscpy(_Dest,param_2);
        }
        puVar2[2] = param_4;
        puVar2[3] = 0;
        if (*(int *)(param_1 + 0x20) == 0) {
          *(undefined4 **)(param_1 + 0x20) = puVar2;
        }
        if (*(int *)(param_1 + 0x24) != 0) {
          *(undefined4 **)(*(int *)(param_1 + 0x24) + 0xc) = puVar2;
        }
        *(undefined4 **)(param_1 + 0x24) = puVar2;
      }
    }
  }
  return;
}



/* c013216c FUN_c013216c */

/* Boundary evidence: original MIPS .pdata c013216c..c013221b. Semantic name remains unreviewed. */

void FUN_c013216c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x2c)) {
    if ((param_2 != 0) || (*(int *)(param_1 + 0xc) != 0)) {
      if (param_3 == 0) {
        uVar1 = *(uint *)(param_1 + 8) & 1;
      }
      else {
        uVar1 = *(uint *)(param_1 + 8) & 2;
      }
      if (uVar1 != 0) {
        if (*(int *)(param_1 + 0x18) == 0) {
          EventModify(*(undefined4 *)(param_1 + 0x10),3);
        }
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      }
    }
  }
  return;
}



/* c013221c FUN_c013221c */

/* Boundary evidence: original MIPS .pdata c013221c..c013246f. Semantic name remains unreviewed. */

void FUN_c013221c(int param_1,wchar_t *param_2,wchar_t *param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint uVar5;
  wchar_t *local_38;
  int local_34;
  wchar_t *local_30;
  
  local_34 = 1;
  local_38 = (wchar_t *)0x0;
  local_30 = param_2;
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  uVar5 = 2;
  if ((param_4 == 0) || ((param_5 != 2 && (param_5 != 4)))) {
    if (param_3 == (wchar_t *)0x0) {
      puVar1 = FUN_c0131850(param_1,local_30,(int *)&local_38,0,1,&local_34);
      pwVar4 = local_38;
      param_3 = local_38;
    }
    else {
      puVar1 = FUN_c0131850(param_1,local_30,(int *)0x0,0,1,&local_34);
      pwVar4 = (wchar_t *)0x0;
    }
    iVar2 = local_34;
    if (local_34 == 0) goto LAB_c01323f0;
    if (param_4 == 0) {
      uVar5 = 1;
    }
    if (puVar1 == (undefined4 *)0x0) {
      iVar3 = *(int *)(param_1 + 0x20);
    }
    else {
      iVar3 = puVar1[3];
    }
  }
  else {
    puVar1 = FUN_c0131850(param_1,local_30,(int *)&local_38,param_4,1,(undefined4 *)0x0);
    pwVar4 = local_38;
    if (puVar1 == (undefined4 *)0x0) {
LAB_c0132308:
      if (pwVar4 != (wchar_t *)0x0) {
        operator_delete(pwVar4);
        local_38 = (wchar_t *)0x0;
      }
    }
    else if (local_38 != (wchar_t *)0x0) {
      iVar2 = wcscmp(local_38,(wchar_t *)puVar1[1]);
      if (iVar2 == 0) {
        FUN_c0132050(puVar1[3],L"\\",2,2);
        FUN_c013216c(puVar1[3],1,param_4);
      }
      goto LAB_c0132308;
    }
    puVar1 = FUN_c0131850(param_1,local_30,(int *)&local_38,0,1,&local_34);
    iVar2 = local_34;
    pwVar4 = local_38;
    if (local_34 == 0) goto LAB_c01323f0;
    if (puVar1 == (undefined4 *)0x0) {
      iVar3 = *(int *)(param_1 + 0x20);
    }
    else {
      iVar3 = puVar1[3];
    }
    uVar5 = 2;
    param_3 = local_38;
  }
  iVar2 = local_34;
  FUN_c0132050(iVar3,param_3,uVar5,param_5);
LAB_c01323f0:
  if (pwVar4 != (wchar_t *)0x0) {
    operator_delete(pwVar4);
  }
  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[6]) {
    FUN_c013216c(puVar1[3],iVar2,param_4);
    iVar2 = 0;
  }
  if (param_1 != 0) {
    FUN_c013216c(*(int *)(param_1 + 0x20),iVar2,param_4);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return;
}



/* c0132470 FUN_c0132470 */

/* Boundary evidence: original MIPS .pdata c0132470..c0132493. Semantic name remains unreviewed. */

void FUN_c0132470(int param_1,wchar_t *param_2,int param_3,int param_4)

{
  FUN_c013221c(param_1,param_2,(wchar_t *)0x0,param_3,param_4);
  return;
}



/* c0132494 FUN_c0132494 */

/* Boundary evidence: original MIPS .pdata c0132494..c0132823. Semantic name remains unreviewed. */

int FUN_c0132494(int param_1,int param_2)

{
  DWORD dwErrCode;
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_48;
  
  iVar6 = 1;
  iVar7 = *(int *)(param_1 + 0x1c);
  SetLastError(0);
  if (iVar7 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar7 + 4));
  }
  EventModify(*(undefined4 *)(param_1 + 0x10),2);
  if ((param_2 == 0) || (*(int *)(param_1 + 0x18) == 0)) {
    if (*(int *)(param_1 + 0x18) == 0) {
      if (param_2 != 0) {
        **(undefined4 **)(param_2 + 0xc) = 0;
        **(undefined4 **)(param_2 + 0x10) = 0;
        SetLastError(0x103);
        iVar6 = 0;
      }
    }
    else {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    }
  }
  else {
    uVar10 = 0;
    uVar8 = 0;
    local_48 = 0;
    puVar2 = (uint *)0x0;
    uVar5 = 0;
    while (puVar4 = *(undefined4 **)(param_1 + 0x20), puVar4 != (undefined4 *)0x0) {
      if ((puVar4[1] + 2 < 2) || (uVar9 = puVar4[1] + 0x12, uVar9 < 0x10)) {
        SetLastError(0x216);
        iVar6 = 0;
        break;
      }
      if ((uVar9 & 3) != 0) {
        uVar9 = (uVar9 - (uVar9 & 3)) + 4;
      }
      uVar1 = uVar9 + local_48;
      if ((*(uint *)(param_2 + 8) < uVar1) || (uVar1 < uVar9)) {
        if (uVar10 == 0) {
          dwErrCode = 0x7a;
        }
        else {
          dwErrCode = 0xea;
        }
        SetLastError(dwErrCode);
        break;
      }
      if (puVar2 != (uint *)0x0) {
        *puVar2 = uVar5;
      }
      puVar2 = (uint *)(*(int *)(param_2 + 4) + local_48);
      *puVar2 = 0;
      puVar2[1] = puVar4[2];
      puVar2[2] = puVar4[1];
      memcpy(puVar2 + 3,(void *)*puVar4,puVar4[1] + 2);
      uVar10 = uVar10 + 1;
      *(undefined4 *)(param_1 + 0x20) = puVar4[3];
      operator_delete((void *)*puVar4);
      operator_delete(puVar4);
      uVar5 = uVar9;
      local_48 = uVar1;
    }
    iVar3 = *(int *)(param_1 + 0x20);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if (*(int *)(param_2 + 0x10) != 0) {
      for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
        uVar8 = *(int *)(iVar3 + 4) + uVar8 + 0x12;
        if ((uVar8 & 3) != 0) {
          uVar8 = (uVar8 - (uVar8 & 3)) + 4;
        }
      }
      **(uint **)(param_2 + 0x10) = uVar8;
    }
    if (*(uint **)(param_2 + 0xc) != (uint *)0x0) {
      **(uint **)(param_2 + 0xc) = local_48;
    }
    if (uVar10 < *(uint *)(param_1 + 0x18)) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) - uVar10;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
  }
  if ((iVar6 != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    EventModify(*(undefined4 *)(param_1 + 0x10),3);
  }
  if (iVar7 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar7 + 4));
  }
  return iVar6;
}



/* c0132824 FUN_c0132824 */

/* Boundary evidence: original MIPS .pdata c0132824..c013282f. Semantic name remains unreviewed. */

undefined4 FUN_c0132824(void)

{
  return 1;
}



/* c0132830 FUN_c0132830 */

/* Boundary evidence: original MIPS .pdata c0132830..c013283b. Semantic name remains unreviewed. */

undefined4 FUN_c0132830(void)

{
  return 1;
}



/* c013283c FUN_c013283c */

/* Boundary evidence: original MIPS .pdata c013283c..c013295b. Semantic name remains unreviewed. */

undefined4
FUN_c013283c(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  iVar1 = GetEventData();
  if (iVar1 == 0) {
    SetLastError(6);
    uVar2 = 0;
  }
  else if ((((param_2 == 0) && (param_3 == 0)) && (param_4 == 0)) &&
          ((param_5 == 0 && (param_6 == 0)))) {
    uVar2 = (*(code *)&SUB_ffff9bfa)(iVar1,0,0);
  }
  else {
    local_24 = param_5;
    local_20 = param_6;
    local_30 = param_2;
    local_2c = param_3;
    local_28 = param_4;
    uVar2 = (*(code *)&SUB_ffff9bfa)(iVar1,&local_30,0x14);
  }
  return uVar2;
}



/* c013295c FUN_c013295c */

/* Boundary evidence: original MIPS .pdata c013295c..c0132967. Semantic name remains unreviewed. */

undefined4 FUN_c013295c(void)

{
  return 1;
}



/* c0132968 FUN_c0132968 */

/* Boundary evidence: original MIPS .pdata c0132968..c0132b7f. Semantic name remains unreviewed. */

undefined4 FUN_c0132968(HANDLE param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  HANDLE pvVar1;
  BOOL BVar2;
  HANDLE hSourceProcessHandle;
  undefined4 uVar3;
  code *pcVar4;
  HANDLE local_res0 [4];
  HANDLE local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  local_res0[0] = param_1;
  pvVar1 = (HANDLE)GetCallerVMProcessId();
  BVar2 = DuplicateHandle(pvVar1,local_res0[0],(HANDLE)0x42,local_res0,0,0,2);
  if (BVar2 != 0) {
    pvVar1 = (HANDLE)GetEventData(local_res0[0]);
    if (pvVar1 == (HANDLE)0x0) {
      CloseHandle(local_res0[0]);
      pvVar1 = (HANDLE)0x6;
      pcVar4 = SetLastError_exref;
    }
    else {
      hSourceProcessHandle = (HANDLE)GetCallerVMProcessId();
      BVar2 = DuplicateHandle(hSourceProcessHandle,pvVar1,(HANDLE)0x42,&local_40,0,0,2);
      pvVar1 = local_res0[0];
      pcVar4 = CloseHandle_exref;
      if (BVar2 != 0) {
        if ((((param_2 == 0) && (param_3 == 0)) && (param_4 == 0)) &&
           ((param_5 == 0 && (param_6 == 0)))) {
          uVar3 = (*(code *)&SUB_ffff9bfa)(local_40,0,0);
        }
        else {
          local_2c = param_5;
          local_28 = param_6;
          local_38 = param_2;
          local_34 = param_3;
          local_30 = param_4;
          uVar3 = (*(code *)&SUB_ffff9bfa)(local_40,&local_38,0x14);
        }
        local_3c = uVar3;
        CloseHandle(local_res0[0]);
        CloseHandle(local_40);
        return uVar3;
      }
    }
    (*pcVar4)(pvVar1);
  }
  return 0;
}



/* c0132b80 FUN_c0132b80 */

/* Boundary evidence: original MIPS .pdata c0132b80..c0132b8b. Semantic name remains unreviewed. */

undefined4 FUN_c0132b80(void)

{
  return 1;
}



/* c0132b8c FUN_c0132b8c */

/* Boundary evidence: original MIPS .pdata c0132b8c..c0132bd7. Semantic name remains unreviewed. */

BOOL FUN_c0132b8c(void)

{
  HANDLE hObject;
  BOOL BVar1;
  
  hObject = (HANDLE)GetEventData();
  if (hObject == (HANDLE)0x0) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = CloseHandle(hObject);
  }
  return BVar1;
}



/* c0132bd8 FUN_c0132bd8 */

/* Boundary evidence: original MIPS .pdata c0132bd8..c0132cdb. Semantic name remains unreviewed. */

BOOL FUN_c0132bd8(HANDLE param_1)

{
  HANDLE pvVar1;
  BOOL BVar2;
  HANDLE hSourceProcessHandle;
  HANDLE local_res0 [4];
  HANDLE local_20 [2];
  
  local_res0[0] = param_1;
  pvVar1 = (HANDLE)GetCallerVMProcessId();
  BVar2 = DuplicateHandle(pvVar1,local_res0[0],(HANDLE)0x42,local_res0,0,0,3);
  if (BVar2 != 0) {
    pvVar1 = (HANDLE)GetEventData(local_res0[0]);
    if (pvVar1 == (HANDLE)0x0) {
      CloseHandle(local_res0[0]);
      SetLastError(6);
    }
    else {
      CloseHandle(local_res0[0]);
      hSourceProcessHandle = (HANDLE)GetCallerVMProcessId();
      BVar2 = DuplicateHandle(hSourceProcessHandle,pvVar1,(HANDLE)0x42,local_20,0,0,3);
      if (BVar2 != 0) {
        BVar2 = CloseHandle(local_20[0]);
        return BVar2;
      }
    }
  }
  return 0;
}



/* c013303c FUN_c013303c */

/* Boundary evidence: original MIPS .pdata c013303c..c0133067. Semantic name remains unreviewed. */

undefined4 FUN_c013303c(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0133068 FUN_c0133068 */

/* Boundary evidence: original MIPS .pdata c0133068..c01331a3. Semantic name remains unreviewed. */

int FUN_c0133068(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c013e7c8 != (code *)0x0) {
      iVar2 = (*DAT_c013e7c8)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0133118;
    FUN_c01337ec();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c013303c(param_1,param_2);
  }
LAB_c0133118:
  if (((param_2 == 0) && (FUN_c0133774(), iVar1 != 0)) && (DAT_c013e7c8 != (code *)0x0)) {
    iVar1 = (*DAT_c013e7c8)(param_1,0,param_3);
  }
  return iVar1;
}



/* c01331a4 FUN_c01331a4 */

/* Boundary evidence: original MIPS .pdata c01331a4..c01331cf. Semantic name remains unreviewed. */

void FUN_c01331a4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c01331d0 entry */

/* Boundary evidence: original MIPS .pdata c01331d0..c0133227. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c0133228();
  }
  FUN_c0133068(param_1,param_2,param_3);
  return;
}



/* c0133228 FUN_c0133228 */

/* Boundary evidence: original MIPS .pdata c0133228..c013329b. Semantic name remains unreviewed. */

void FUN_c0133228(void)

{
  uint uVar1;
  
  if ((DAT_c0136c78 == 0) || (DAT_c0136c78 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0136c78 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0136c78 == 0) {
      DAT_c0136c78 = 0xb064;
    }
  }
  DAT_c0136c7c = ~DAT_c0136c78;
  return;
}



/* c013329c FUN_c013329c */

/* Boundary evidence: original MIPS .pdata c013329c..c01332ef. Semantic name remains unreviewed. */

void FUN_c013329c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c013331c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c01332f0 FUN_c01332f0 */

/* Boundary evidence: original MIPS .pdata c01332f0..c013331b. Semantic name remains unreviewed. */

undefined4 FUN_c01332f0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c013329c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c013331c FUN_c013331c */

/* Boundary evidence: original MIPS .pdata c013331c..c0133363. Semantic name remains unreviewed. */

void FUN_c013331c(uint param_1)

{
  if ((param_1 == DAT_c0136c78) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0133364 FUN_c0133364 */

/* Boundary evidence: original MIPS .pdata c0133364..c01333df. Semantic name remains unreviewed. */

void FUN_c0133364(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c013329c(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c01333e0 FUN_c01333e0 */

/* Boundary evidence: original MIPS .pdata c01333e0..c01334eb. Semantic name remains unreviewed. */

undefined4 FUN_c01333e0(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c013e7c0;
  puVar3 = DAT_c013e7bc;
  iVar4 = (int)DAT_c013e7bc - (int)DAT_c013e7c0;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c0133424:
    param_1 = 0;
  }
  else {
    if (DAT_c013e7c0 != (void *)0x0) {
      uVar1 = _msize(DAT_c013e7c0);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c0133498:
        if (pvVar2 == (void *)0x0) goto LAB_c0133424;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c0133498;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c013e7bc = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c013e7c0 = pvVar2;
  }
  return param_1;
}



/* c01334ec FUN_c01334ec */

/* Boundary evidence: original MIPS .pdata c01334ec..c01335d7. Semantic name remains unreviewed. */

undefined4 FUN_c01334ec(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c013e7c4 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c013e7c4,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c013e7c4 == (LPCRITICAL_SECTION)0x0) goto LAB_c0133590;
  }
  EnterCriticalSection(DAT_c013e7c4);
LAB_c0133590:
  uVar2 = FUN_c01333e0(param_1);
  FUN_c01335d8();
  return uVar2;
}



/* c01335d8 FUN_c01335d8 */

/* Boundary evidence: original MIPS .pdata c01335d8..c0133623. Semantic name remains unreviewed. */

void FUN_c01335d8(void)

{
  if (DAT_c013e7c4 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c013e7c4);
  }
  return;
}



/* c0133624 FUN_c0133624 */

/* Boundary evidence: original MIPS .pdata c0133624..c0133653. Semantic name remains unreviewed. */

undefined4 FUN_c0133624(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c01334ec(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c0133654 FUN_c0133654 */

/* Boundary evidence: original MIPS .pdata c0133654..c0133773. Semantic name remains unreviewed. */

void FUN_c0133654(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c013712c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c013e7c0;
    if (DAT_c013e7c0 != (undefined4 *)0x0) {
      while (DAT_c013e7bc = DAT_c013e7bc + -1, _Memory <= DAT_c013e7bc) {
        if ((code *)*DAT_c013e7bc != (code *)0x0) {
          (*(code *)*DAT_c013e7bc)();
          _Memory = DAT_c013e7c0;
        }
      }
      free(_Memory);
      DAT_c013e7bc = (undefined4 *)0x0;
      DAT_c013e7c0 = (undefined4 *)0x0;
    }
    FUN_c0133798((undefined4 *)&DAT_c00f1014,(undefined4 *)&DAT_c00f1018);
  }
  FUN_c0133798((undefined4 *)&DAT_c00f101c,(undefined4 *)&DAT_c00f1020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c013e7c4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0133774 FUN_c0133774 */

/* Boundary evidence: original MIPS .pdata c0133774..c0133797. Semantic name remains unreviewed. */

void FUN_c0133774(void)

{
  FUN_c0133654(0,0,1);
  return;
}



/* c0133798 FUN_c0133798 */

/* Boundary evidence: original MIPS .pdata c0133798..c01337eb. Semantic name remains unreviewed. */

void FUN_c0133798(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c01337ec FUN_c01337ec */

/* Boundary evidence: original MIPS .pdata c01337ec..c0133827. Semantic name remains unreviewed. */

void FUN_c01337ec(void)

{
  FUN_c0133798((undefined4 *)&DAT_c00f100c,(undefined4 *)&DAT_c00f1010);
  FUN_c0133798((undefined4 *)&DAT_c00f1000,(undefined4 *)&DAT_c00f1008);
  return;
}



/* c0133a48 FUN_c0133a48 */

/* Boundary evidence: original MIPS .pdata c0133a48..c0133a63. Semantic name remains unreviewed. */

void FUN_c0133a48(void)

{
  FUN_c01138b0();
  return;
}



/* c0133a64 FUN_c0133a64 */

/* Boundary evidence: original MIPS .pdata c0133a64..c0133a83. Semantic name remains unreviewed. */

void FUN_c0133a64(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0136d34);
  return;
}


