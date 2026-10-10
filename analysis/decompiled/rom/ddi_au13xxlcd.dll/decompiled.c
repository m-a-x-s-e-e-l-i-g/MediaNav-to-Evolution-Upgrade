/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c08d2d78 FUN_c08d2d78 */

/* Boundary evidence: original MIPS .pdata c08d2d78..c08d32a7. Semantic name remains unreviewed. */

undefined4 FUN_c08d2d78(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  byte *pbVar12;
  uint *puVar13;
  byte *pbVar14;
  int iVar15;
  int local_38;
  
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 8);
  if (iVar5 < 0) {
    iVar5 = iVar5 + 3;
  }
  piVar6 = *(int **)(param_1 + 0x14);
  iVar15 = 0;
  local_38 = piVar6[3] - piVar6[1];
  iVar8 = **(int **)(param_1 + 0x18);
  uVar9 = -iVar8 & 7;
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  uVar7 = (piVar6[2] - *piVar6) - uVar9;
  iVar2 = (int)uVar7 >> 3;
  uVar7 = uVar7 & 7;
  iVar10 = 0;
  pbVar12 = (byte *)((*(int **)(param_1 + 0x18))[1] * iVar3 + (iVar8 >> 3) +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar11 = (uint *)((piVar6[1] * (iVar5 >> 2) + *piVar6) * 4 + *(int *)(*(int *)(param_1 + 4) + 4))
  ;
  do {
    piVar6 = (int *)((int)&DAT_c0908ae8 + iVar10);
    *piVar6 = iVar15;
    if (*(int *)(param_1 + 0x3c) != 0) {
      *piVar6 = *(int *)(iVar10 + *(int *)(param_1 + 0x3c));
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar8 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar6);
      *piVar6 = iVar8;
    }
    iVar10 = iVar10 + 4;
    iVar15 = iVar15 + 1;
  } while (iVar10 < 8);
  if (0 < local_38) {
    do {
      bVar1 = *pbVar12;
      puVar13 = puVar11;
      if (uVar9 == 1) {
LAB_c08d2ff4:
        *puVar13 = (&DAT_c0908ae8)[bVar1 & 1] ^ *puVar13;
        puVar13 = puVar13 + 1;
        pbVar14 = pbVar12 + 1;
      }
      else {
        if (uVar9 == 2) {
LAB_c08d2fd0:
          *puVar13 = (&DAT_c0908ae8)[bVar1 >> 1 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d2ff4;
        }
        if (uVar9 == 3) {
LAB_c08d2fac:
          *puVar13 = (&DAT_c0908ae8)[bVar1 >> 2 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d2fd0;
        }
        if (uVar9 == 4) {
LAB_c08d2f88:
          *puVar13 = (&DAT_c0908ae8)[bVar1 >> 3 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d2fac;
        }
        if (uVar9 == 5) {
LAB_c08d2f64:
          *puVar13 = (&DAT_c0908ae8)[bVar1 >> 4 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d2f88;
        }
        if (uVar9 == 6) {
LAB_c08d2f40:
          *puVar13 = (&DAT_c0908ae8)[bVar1 >> 5 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d2f64;
        }
        pbVar14 = pbVar12;
        if (uVar9 == 7) {
          *puVar11 = (&DAT_c0908ae8)[bVar1 >> 6 & 1] ^ *puVar11;
          puVar13 = puVar11 + 1;
          goto LAB_c08d2f40;
        }
      }
      iVar8 = iVar2;
      if (0 < iVar2) {
        do {
          uVar4 = (uint)*pbVar14;
          puVar13[7] = (&DAT_c0908ae8)[uVar4 & 1] ^ puVar13[7];
          puVar13[6] = (&DAT_c0908ae8)[(int)uVar4 >> 1 & 1] ^ puVar13[6];
          puVar13[5] = (&DAT_c0908ae8)[(int)uVar4 >> 2 & 1] ^ puVar13[5];
          puVar13[4] = (&DAT_c0908ae8)[(int)uVar4 >> 3 & 1] ^ puVar13[4];
          puVar13[3] = (&DAT_c0908ae8)[(int)uVar4 >> 4 & 1] ^ puVar13[3];
          puVar13[2] = (&DAT_c0908ae8)[(int)uVar4 >> 5 & 1] ^ puVar13[2];
          puVar13[1] = (&DAT_c0908ae8)[(int)uVar4 >> 6 & 1] ^ puVar13[1];
          *puVar13 = (&DAT_c0908ae8)[(int)uVar4 >> 7] ^ *puVar13;
          puVar13 = puVar13 + 8;
          iVar8 = iVar8 + -1;
          pbVar14 = pbVar14 + 1;
        } while (iVar8 != 0);
      }
      if (uVar7 != 0) {
        bVar1 = *pbVar14;
        if (uVar7 != 1) {
          if (uVar7 != 2) {
            if (uVar7 != 3) {
              if (uVar7 != 4) {
                if (uVar7 != 5) {
                  if (uVar7 != 6) {
                    if (uVar7 != 7) goto LAB_c08d325c;
                    puVar13[6] = (&DAT_c0908ae8)[bVar1 >> 1 & 1] ^ puVar13[6];
                  }
                  puVar13[5] = (&DAT_c0908ae8)[bVar1 >> 2 & 1] ^ puVar13[5];
                }
                puVar13[4] = (&DAT_c0908ae8)[bVar1 >> 3 & 1] ^ puVar13[4];
              }
              puVar13[3] = (&DAT_c0908ae8)[bVar1 >> 4 & 1] ^ puVar13[3];
            }
            puVar13[2] = (&DAT_c0908ae8)[bVar1 >> 5 & 1] ^ puVar13[2];
          }
          puVar13[1] = (&DAT_c0908ae8)[bVar1 >> 6 & 1] ^ puVar13[1];
        }
        *puVar13 = (&DAT_c0908ae8)[bVar1 >> 7] ^ *puVar13;
      }
LAB_c08d325c:
      local_38 = local_38 + -1;
      pbVar12 = pbVar12 + iVar3;
      puVar11 = puVar11 + (iVar5 >> 2);
    } while (local_38 != 0);
  }
  return 0;
}



/* c08d32a8 FUN_c08d32a8 */

/* Boundary evidence: original MIPS .pdata c08d32a8..c08d34b7. Semantic name remains unreviewed. */

undefined4 FUN_c08d32a8(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  uint local_68 [16];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar13 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar4 = *(int **)(param_1 + 0x14);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 3;
  }
  iVar2 = iVar2 >> 2;
  iVar5 = piVar4[2] - *piVar4;
  uVar6 = **(uint **)(param_1 + 0x18);
  iVar11 = piVar4[3] - piVar4[1];
  iVar14 = 0;
  iVar10 = 0;
  pbVar9 = (byte *)((*(uint **)(param_1 + 0x18))[1] * iVar13 + ((int)uVar6 >> 1) +
                   *(int *)(*(int *)(param_1 + 8) + 4));
  puVar12 = (uint *)((piVar4[1] * iVar2 + *piVar4) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar4 = (int *)((int)local_68 + iVar10);
    iVar1 = *(int *)(param_1 + 0x3c);
    *piVar4 = iVar14;
    if (iVar1 != 0) {
      *piVar4 = *(int *)(iVar10 + iVar1);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar4);
      *piVar4 = iVar1;
    }
    iVar10 = iVar10 + 4;
    iVar14 = iVar14 + 1;
  } while (iVar10 < 0x40);
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar11 + -1) * iVar13;
    iVar13 = -iVar13;
    iVar14 = (iVar11 + -1) * iVar2;
    pbVar9 = pbVar9 + iVar10;
    iVar2 = -iVar2;
    puVar12 = puVar12 + iVar14;
  }
  if (0 < iVar11) {
    do {
      puVar7 = puVar12;
      uVar8 = uVar6 & 1;
      iVar10 = iVar5;
      if (0 < iVar5) {
        do {
          if (uVar8 == 0) {
            uVar3 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar3 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          *puVar7 = local_68[uVar3] ^ *puVar7;
          iVar10 = iVar10 + -1;
          puVar7 = puVar7 + 1;
          uVar8 = (uint)(uVar8 == 0);
        } while (iVar10 != 0);
      }
      iVar11 = iVar11 + -1;
      puVar12 = puVar12 + iVar2;
      pbVar9 = pbVar9 + (iVar13 - (iVar5 >> 1));
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d34b8 FUN_c08d34b8 */

undefined4 FUN_c08d34b8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar7 = *(int **)(param_1 + 0x14);
  if (iVar6 < 0) {
    iVar6 = iVar6 + 3;
  }
  iVar6 = iVar6 >> 2;
  iVar3 = piVar7[2] - *piVar7;
  iVar11 = piVar7[3] - piVar7[1];
  iVar2 = (*(int **)(param_1 + 0x18))[1] * iVar4 + *(int *)(*(int *)(param_1 + 8) + 4) +
          **(int **)(param_1 + 0x18);
  puVar10 = (uint *)((piVar7[1] * iVar6 + *piVar7) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar8 = (iVar11 + -1) * iVar4;
    iVar4 = -iVar4;
    iVar1 = (iVar11 + -1) * iVar6;
    iVar2 = iVar8 + iVar2;
    iVar6 = -iVar6;
    puVar10 = puVar10 + iVar1;
  }
  if (0 < iVar11) {
    do {
      iVar8 = 0;
      puVar9 = puVar10;
      if (0 < iVar3) {
        do {
          pbVar5 = (byte *)(iVar8 + iVar2);
          iVar8 = iVar8 + 1;
          *puVar9 = *(uint *)((uint)*pbVar5 * 4 + *(int *)(param_1 + 0x3c)) ^ *puVar9;
          puVar9 = puVar9 + 1;
        } while (iVar8 < iVar3);
      }
      iVar11 = iVar11 + -1;
      puVar10 = puVar10 + iVar6;
      iVar2 = iVar2 + iVar4;
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d35d4 FUN_c08d35d4 */

/* Boundary evidence: original MIPS .pdata c08d35d4..c08d3777. Semantic name remains unreviewed. */

undefined4 FUN_c08d35d4(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined2 *puVar7;
  uint *puVar8;
  uint *puVar9;
  undefined2 *puVar10;
  int iVar11;
  int iVar12;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
  }
  iVar3 = iVar3 >> 1;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar12 = piVar5[2] - *piVar5;
  iVar6 = piVar5[3] - piVar5[1];
  puVar7 = (undefined2 *)
           (((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 2 +
           *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (uint *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar6 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar6 + -1) * iVar4;
    puVar7 = puVar7 + iVar11;
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar6) {
    do {
      puVar9 = puVar8;
      puVar10 = puVar7;
      iVar11 = iVar12;
      if (0 < iVar12) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*puVar10);
          *puVar9 = uVar2 ^ *puVar9;
          iVar11 = iVar11 + -1;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar6 = iVar6 + -1;
      puVar8 = puVar8 + iVar4;
      puVar7 = puVar7 + iVar3;
    } while (iVar6 != 0);
  }
  return 0;
}



/* c08d3778 FUN_c08d3778 */

/* Boundary evidence: original MIPS .pdata c08d3778..c08d391f. Semantic name remains unreviewed. */

undefined4 FUN_c08d3778(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint3 *puVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar9 = piVar5[2] - *piVar5;
  iVar7 = piVar5[3] - piVar5[1];
  puVar6 = (uint3 *)((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18) * 3 +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (uint *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar7 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar7 + -1) * iVar4;
    puVar6 = (uint3 *)(iVar11 + (int)puVar6);
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar7) {
    do {
      puVar10 = puVar8;
      iVar11 = iVar9;
      if (0 < iVar9) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),(uint)*puVar6);
          *puVar10 = uVar2 ^ *puVar10;
          puVar6 = (uint3 *)((int)puVar6 + 3);
          iVar11 = iVar11 + -1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar7 = iVar7 + -1;
      puVar8 = puVar8 + iVar4;
      puVar6 = (uint3 *)((int)puVar6 + iVar3 + iVar9 * -3);
    } while (iVar7 != 0);
  }
  return 0;
}



/* c08d3920 FUN_c08d3920 */

/* Boundary evidence: original MIPS .pdata c08d3920..c08d3adf. Semantic name remains unreviewed. */

undefined4 FUN_c08d3920(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  iVar3 = iVar3 >> 2;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar11 = piVar5[2] - *piVar5;
  iVar8 = piVar5[3] - piVar5[1];
  iVar9 = ((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 4 +
          *(int *)(*(int *)(param_1 + 8) + 4);
  puVar7 = (uint *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar8 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar8 + -1) * iVar4;
    iVar9 = iVar10 * 4 + iVar9;
    iVar4 = -iVar4;
    puVar7 = puVar7 + iVar1;
  }
  if (0 < iVar8) {
    do {
      if (0 < iVar11) {
        puVar6 = puVar7;
        iVar10 = iVar11;
        do {
          if (*(code **)(param_1 + 0x40) == (code *)0x0) {
            *puVar6 = *(uint *)((iVar9 - (int)puVar7) + (int)puVar6) ^ *puVar6;
          }
          else {
            uVar2 = (**(code **)(param_1 + 0x40))
                              (*(undefined4 *)(param_1 + 0x44),
                               *(undefined4 *)((iVar9 - (int)puVar7) + (int)puVar6));
            *puVar6 = uVar2 ^ *puVar6;
          }
          iVar10 = iVar10 + -1;
          puVar6 = puVar6 + 1;
        } while (iVar10 != 0);
      }
      iVar8 = iVar8 + -1;
      puVar7 = puVar7 + iVar4;
      iVar9 = iVar3 * 4 + iVar9;
    } while (iVar8 != 0);
  }
  return 0;
}



/* c08d3ae0 FUN_c08d3ae0 */

/* Boundary evidence: original MIPS .pdata c08d3ae0..c08d3f63. Semantic name remains unreviewed. */

undefined4 FUN_c08d3ae0(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  int local_38;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 8);
  if (iVar6 < 0) {
    iVar6 = iVar6 + 3;
  }
  piVar7 = *(int **)(param_1 + 0x14);
  iVar12 = 0;
  local_38 = piVar7[3] - piVar7[1];
  iVar9 = **(int **)(param_1 + 0x18);
  uVar10 = -iVar9 & 7;
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  uVar8 = (piVar7[2] - *piVar7) - uVar10;
  iVar2 = (int)uVar8 >> 3;
  uVar8 = uVar8 & 7;
  iVar11 = 0;
  pbVar13 = (byte *)((*(int **)(param_1 + 0x18))[1] * iVar4 + (iVar9 >> 3) +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar15 = (undefined4 *)
            ((piVar7[1] * (iVar6 >> 2) + *piVar7) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar7 = (int *)((int)&DAT_c0908af0 + iVar11);
    *piVar7 = iVar12;
    if (*(int *)(param_1 + 0x3c) != 0) {
      *piVar7 = *(int *)(iVar11 + *(int *)(param_1 + 0x3c));
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar9 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar7);
      *piVar7 = iVar9;
    }
    iVar11 = iVar11 + 4;
    iVar12 = iVar12 + 1;
  } while (iVar11 < 8);
  if (0 < local_38) {
    do {
      bVar1 = *pbVar13;
      puVar14 = puVar15;
      if (uVar10 == 1) {
LAB_c08d3d2c:
        pbVar3 = pbVar13 + 1;
        *puVar14 = (&DAT_c0908af0)[bVar1 & 1];
        puVar14 = puVar14 + 1;
      }
      else {
        if (uVar10 == 2) {
LAB_c08d3d10:
          *puVar14 = (&DAT_c0908af0)[bVar1 >> 1 & 1];
          puVar14 = puVar14 + 1;
          goto LAB_c08d3d2c;
        }
        if (uVar10 == 3) {
LAB_c08d3cf4:
          *puVar14 = (&DAT_c0908af0)[bVar1 >> 2 & 1];
          puVar14 = puVar14 + 1;
          goto LAB_c08d3d10;
        }
        if (uVar10 == 4) {
LAB_c08d3cd8:
          *puVar14 = (&DAT_c0908af0)[bVar1 >> 3 & 1];
          puVar14 = puVar14 + 1;
          goto LAB_c08d3cf4;
        }
        if (uVar10 == 5) {
LAB_c08d3cbc:
          *puVar14 = (&DAT_c0908af0)[bVar1 >> 4 & 1];
          puVar14 = puVar14 + 1;
          goto LAB_c08d3cd8;
        }
        if (uVar10 == 6) {
LAB_c08d3ca0:
          *puVar14 = (&DAT_c0908af0)[bVar1 >> 5 & 1];
          puVar14 = puVar14 + 1;
          goto LAB_c08d3cbc;
        }
        pbVar3 = pbVar13;
        if (uVar10 == 7) {
          puVar14 = puVar15 + 1;
          *puVar15 = (&DAT_c0908af0)[bVar1 >> 6 & 1];
          goto LAB_c08d3ca0;
        }
      }
      iVar9 = iVar2;
      if (0 < iVar2) {
        do {
          uVar5 = (uint)*pbVar3;
          puVar14[7] = (&DAT_c0908af0)[uVar5 & 1];
          puVar14[6] = (&DAT_c0908af0)[(int)uVar5 >> 1 & 1];
          puVar14[5] = (&DAT_c0908af0)[(int)uVar5 >> 2 & 1];
          puVar14[4] = (&DAT_c0908af0)[(int)uVar5 >> 3 & 1];
          puVar14[3] = (&DAT_c0908af0)[(int)uVar5 >> 4 & 1];
          puVar14[2] = (&DAT_c0908af0)[(int)uVar5 >> 5 & 1];
          puVar14[1] = (&DAT_c0908af0)[(int)uVar5 >> 6 & 1];
          pbVar3 = pbVar3 + 1;
          *puVar14 = (&DAT_c0908af0)[(int)uVar5 >> 7];
          iVar9 = iVar9 + -1;
          puVar14 = puVar14 + 8;
        } while (iVar9 != 0);
      }
      if (uVar8 != 0) {
        bVar1 = *pbVar3;
        if (uVar8 != 1) {
          if (uVar8 != 2) {
            if (uVar8 != 3) {
              if (uVar8 != 4) {
                if (uVar8 != 5) {
                  if (uVar8 != 6) {
                    if (uVar8 != 7) goto LAB_c08d3f18;
                    puVar14[6] = (&DAT_c0908af0)[bVar1 >> 1 & 1];
                  }
                  puVar14[5] = (&DAT_c0908af0)[bVar1 >> 2 & 1];
                }
                puVar14[4] = (&DAT_c0908af0)[bVar1 >> 3 & 1];
              }
              puVar14[3] = (&DAT_c0908af0)[bVar1 >> 4 & 1];
            }
            puVar14[2] = (&DAT_c0908af0)[bVar1 >> 5 & 1];
          }
          puVar14[1] = (&DAT_c0908af0)[bVar1 >> 6 & 1];
        }
        *puVar14 = (&DAT_c0908af0)[bVar1 >> 7];
      }
LAB_c08d3f18:
      local_38 = local_38 + -1;
      pbVar13 = pbVar13 + iVar4;
      puVar15 = puVar15 + (iVar6 >> 2);
    } while (local_38 != 0);
  }
  return 0;
}



/* c08d3f64 FUN_c08d3f64 */

/* Boundary evidence: original MIPS .pdata c08d3f64..c08d416b. Semantic name remains unreviewed. */

undefined4 FUN_c08d3f64(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int local_68 [16];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar12 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar4 = *(int **)(param_1 + 0x14);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 3;
  }
  iVar2 = iVar2 >> 2;
  iVar5 = piVar4[2] - *piVar4;
  uVar6 = **(uint **)(param_1 + 0x18);
  iVar11 = piVar4[3] - piVar4[1];
  iVar13 = 0;
  iVar10 = 0;
  pbVar9 = (byte *)((*(uint **)(param_1 + 0x18))[1] * iVar12 + ((int)uVar6 >> 1) +
                   *(int *)(*(int *)(param_1 + 8) + 4));
  piVar4 = (int *)((piVar4[1] * iVar2 + *piVar4) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar8 = (int *)((int)local_68 + iVar10);
    iVar1 = *(int *)(param_1 + 0x3c);
    *piVar8 = iVar13;
    if (iVar1 != 0) {
      *piVar8 = *(int *)(iVar10 + iVar1);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar8);
      *piVar8 = iVar1;
    }
    iVar10 = iVar10 + 4;
    iVar13 = iVar13 + 1;
  } while (iVar10 < 0x40);
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar11 + -1) * iVar12;
    iVar12 = -iVar12;
    iVar13 = (iVar11 + -1) * iVar2;
    pbVar9 = pbVar9 + iVar10;
    iVar2 = -iVar2;
    piVar4 = piVar4 + iVar13;
  }
  if (0 < iVar11) {
    do {
      uVar7 = uVar6 & 1;
      piVar8 = piVar4;
      iVar10 = iVar5;
      if (0 < iVar5) {
        do {
          if (uVar7 == 0) {
            uVar3 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar3 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          *piVar8 = local_68[uVar3];
          iVar10 = iVar10 + -1;
          uVar7 = (uint)(uVar7 == 0);
          piVar8 = piVar8 + 1;
        } while (iVar10 != 0);
      }
      iVar11 = iVar11 + -1;
      piVar4 = piVar4 + iVar2;
      pbVar9 = pbVar9 + (iVar12 - (iVar5 >> 1));
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d416c FUN_c08d416c */

/* Boundary evidence: original MIPS .pdata c08d416c..c08d4307. Semantic name remains unreviewed. */

undefined4 FUN_c08d416c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined2 *puVar10;
  int iVar11;
  int iVar12;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
  }
  iVar3 = iVar3 >> 1;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar12 = piVar5[2] - *piVar5;
  iVar6 = piVar5[3] - piVar5[1];
  puVar7 = (undefined2 *)
           (((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 2 +
           *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (undefined4 *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar6 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar6 + -1) * iVar4;
    puVar7 = puVar7 + iVar11;
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar6) {
    do {
      puVar9 = puVar8;
      puVar10 = puVar7;
      iVar11 = iVar12;
      if (0 < iVar12) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*puVar10);
          iVar11 = iVar11 + -1;
          *puVar9 = uVar2;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar6 = iVar6 + -1;
      puVar8 = puVar8 + iVar4;
      puVar7 = puVar7 + iVar3;
    } while (iVar6 != 0);
  }
  return 0;
}



/* c08d4308 FUN_c08d4308 */

/* Boundary evidence: original MIPS .pdata c08d4308..c08d44a7. Semantic name remains unreviewed. */

undefined4 FUN_c08d4308(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint3 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar9 = piVar5[2] - *piVar5;
  iVar7 = piVar5[3] - piVar5[1];
  puVar6 = (uint3 *)((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18) * 3 +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (undefined4 *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar7 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar7 + -1) * iVar4;
    puVar6 = (uint3 *)(iVar11 + (int)puVar6);
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar7) {
    do {
      puVar10 = puVar8;
      iVar11 = iVar9;
      if (0 < iVar9) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),(uint)*puVar6);
          puVar6 = (uint3 *)((int)puVar6 + 3);
          iVar11 = iVar11 + -1;
          *puVar10 = uVar2;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar7 = iVar7 + -1;
      puVar8 = puVar8 + iVar4;
      puVar6 = (uint3 *)((int)puVar6 + iVar3 + iVar9 * -3);
    } while (iVar7 != 0);
  }
  return 0;
}



/* c08d44a8 FUN_c08d44a8 */

/* Boundary evidence: original MIPS .pdata c08d44a8..c08d467b. Semantic name remains unreviewed. */

undefined4 FUN_c08d44a8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *_Dst;
  void *_Src;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  iVar3 = iVar3 >> 2;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar9 = piVar5[2] - *piVar5;
  iVar6 = piVar5[3] - piVar5[1];
  _Src = (void *)(((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 4 +
                 *(int *)(*(int *)(param_1 + 8) + 4));
  _Dst = (undefined4 *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar8 = (iVar6 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar6 + -1) * iVar4;
    _Src = (void *)(iVar8 * 4 + (int)_Src);
    iVar4 = -iVar4;
    _Dst = _Dst + iVar1;
  }
  if (0 < iVar6) {
    if (*(int *)(param_1 + 0x40) == 0) {
      do {
        memcpy(_Dst,_Src,iVar9 * 4);
        iVar6 = iVar6 + -1;
        _Dst = _Dst + iVar4;
        _Src = (void *)(iVar3 * 4 + (int)_Src);
      } while (iVar6 != 0);
    }
    else {
      do {
        if (0 < iVar9) {
          puVar7 = _Dst;
          iVar8 = iVar9;
          do {
            uVar2 = (**(code **)(param_1 + 0x40))
                              (*(undefined4 *)(param_1 + 0x44),
                               *(undefined4 *)(((int)_Src - (int)_Dst) + (int)puVar7));
            iVar8 = iVar8 + -1;
            *puVar7 = uVar2;
            puVar7 = puVar7 + 1;
          } while (iVar8 != 0);
        }
        iVar6 = iVar6 + -1;
        _Dst = _Dst + iVar4;
        _Src = (void *)(iVar3 * 4 + (int)_Src);
      } while (iVar6 != 0);
    }
  }
  return 0;
}



/* c08d467c FUN_c08d467c */

/* Boundary evidence: original MIPS .pdata c08d467c..c08d4bab. Semantic name remains unreviewed. */

undefined4 FUN_c08d467c(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  byte *pbVar12;
  uint *puVar13;
  byte *pbVar14;
  int iVar15;
  int local_38;
  
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 8);
  if (iVar5 < 0) {
    iVar5 = iVar5 + 3;
  }
  piVar6 = *(int **)(param_1 + 0x14);
  iVar15 = 0;
  local_38 = piVar6[3] - piVar6[1];
  iVar8 = **(int **)(param_1 + 0x18);
  uVar9 = -iVar8 & 7;
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  uVar7 = (piVar6[2] - *piVar6) - uVar9;
  iVar2 = (int)uVar7 >> 3;
  uVar7 = uVar7 & 7;
  iVar10 = 0;
  pbVar12 = (byte *)((*(int **)(param_1 + 0x18))[1] * iVar3 + (iVar8 >> 3) +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar11 = (uint *)((piVar6[1] * (iVar5 >> 2) + *piVar6) * 4 + *(int *)(*(int *)(param_1 + 4) + 4))
  ;
  do {
    piVar6 = (int *)((int)&DAT_c0908af8 + iVar10);
    *piVar6 = iVar15;
    if (*(int *)(param_1 + 0x3c) != 0) {
      *piVar6 = *(int *)(iVar10 + *(int *)(param_1 + 0x3c));
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar8 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar6);
      *piVar6 = iVar8;
    }
    iVar10 = iVar10 + 4;
    iVar15 = iVar15 + 1;
  } while (iVar10 < 8);
  if (0 < local_38) {
    do {
      bVar1 = *pbVar12;
      puVar13 = puVar11;
      if (uVar9 == 1) {
LAB_c08d48f8:
        *puVar13 = (&DAT_c0908af8)[bVar1 & 1] & *puVar13;
        puVar13 = puVar13 + 1;
        pbVar14 = pbVar12 + 1;
      }
      else {
        if (uVar9 == 2) {
LAB_c08d48d4:
          *puVar13 = (&DAT_c0908af8)[bVar1 >> 1 & 1] & *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d48f8;
        }
        if (uVar9 == 3) {
LAB_c08d48b0:
          *puVar13 = (&DAT_c0908af8)[bVar1 >> 2 & 1] & *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d48d4;
        }
        if (uVar9 == 4) {
LAB_c08d488c:
          *puVar13 = (&DAT_c0908af8)[bVar1 >> 3 & 1] & *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d48b0;
        }
        if (uVar9 == 5) {
LAB_c08d4868:
          *puVar13 = (&DAT_c0908af8)[bVar1 >> 4 & 1] & *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d488c;
        }
        if (uVar9 == 6) {
LAB_c08d4844:
          *puVar13 = (&DAT_c0908af8)[bVar1 >> 5 & 1] & *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d4868;
        }
        pbVar14 = pbVar12;
        if (uVar9 == 7) {
          *puVar11 = (&DAT_c0908af8)[bVar1 >> 6 & 1] & *puVar11;
          puVar13 = puVar11 + 1;
          goto LAB_c08d4844;
        }
      }
      iVar8 = iVar2;
      if (0 < iVar2) {
        do {
          uVar4 = (uint)*pbVar14;
          puVar13[7] = (&DAT_c0908af8)[uVar4 & 1] & puVar13[7];
          puVar13[6] = (&DAT_c0908af8)[(int)uVar4 >> 1 & 1] & puVar13[6];
          puVar13[5] = (&DAT_c0908af8)[(int)uVar4 >> 2 & 1] & puVar13[5];
          puVar13[4] = (&DAT_c0908af8)[(int)uVar4 >> 3 & 1] & puVar13[4];
          puVar13[3] = (&DAT_c0908af8)[(int)uVar4 >> 4 & 1] & puVar13[3];
          puVar13[2] = (&DAT_c0908af8)[(int)uVar4 >> 5 & 1] & puVar13[2];
          puVar13[1] = (&DAT_c0908af8)[(int)uVar4 >> 6 & 1] & puVar13[1];
          *puVar13 = (&DAT_c0908af8)[(int)uVar4 >> 7] & *puVar13;
          puVar13 = puVar13 + 8;
          iVar8 = iVar8 + -1;
          pbVar14 = pbVar14 + 1;
        } while (iVar8 != 0);
      }
      if (uVar7 != 0) {
        bVar1 = *pbVar14;
        if (uVar7 != 1) {
          if (uVar7 != 2) {
            if (uVar7 != 3) {
              if (uVar7 != 4) {
                if (uVar7 != 5) {
                  if (uVar7 != 6) {
                    if (uVar7 != 7) goto LAB_c08d4b60;
                    puVar13[6] = (&DAT_c0908af8)[bVar1 >> 1 & 1] & puVar13[6];
                  }
                  puVar13[5] = (&DAT_c0908af8)[bVar1 >> 2 & 1] & puVar13[5];
                }
                puVar13[4] = (&DAT_c0908af8)[bVar1 >> 3 & 1] & puVar13[4];
              }
              puVar13[3] = (&DAT_c0908af8)[bVar1 >> 4 & 1] & puVar13[3];
            }
            puVar13[2] = (&DAT_c0908af8)[bVar1 >> 5 & 1] & puVar13[2];
          }
          puVar13[1] = (&DAT_c0908af8)[bVar1 >> 6 & 1] & puVar13[1];
        }
        *puVar13 = (&DAT_c0908af8)[bVar1 >> 7] & *puVar13;
      }
LAB_c08d4b60:
      local_38 = local_38 + -1;
      pbVar12 = pbVar12 + iVar3;
      puVar11 = puVar11 + (iVar5 >> 2);
    } while (local_38 != 0);
  }
  return 0;
}



/* c08d4bac FUN_c08d4bac */

/* Boundary evidence: original MIPS .pdata c08d4bac..c08d4dbb. Semantic name remains unreviewed. */

undefined4 FUN_c08d4bac(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  uint local_68 [16];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar13 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar4 = *(int **)(param_1 + 0x14);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 3;
  }
  iVar2 = iVar2 >> 2;
  iVar5 = piVar4[2] - *piVar4;
  uVar6 = **(uint **)(param_1 + 0x18);
  iVar11 = piVar4[3] - piVar4[1];
  iVar14 = 0;
  iVar10 = 0;
  pbVar9 = (byte *)((*(uint **)(param_1 + 0x18))[1] * iVar13 + ((int)uVar6 >> 1) +
                   *(int *)(*(int *)(param_1 + 8) + 4));
  puVar12 = (uint *)((piVar4[1] * iVar2 + *piVar4) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar4 = (int *)((int)local_68 + iVar10);
    iVar1 = *(int *)(param_1 + 0x3c);
    *piVar4 = iVar14;
    if (iVar1 != 0) {
      *piVar4 = *(int *)(iVar10 + iVar1);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar4);
      *piVar4 = iVar1;
    }
    iVar10 = iVar10 + 4;
    iVar14 = iVar14 + 1;
  } while (iVar10 < 0x40);
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar11 + -1) * iVar13;
    iVar13 = -iVar13;
    iVar14 = (iVar11 + -1) * iVar2;
    pbVar9 = pbVar9 + iVar10;
    iVar2 = -iVar2;
    puVar12 = puVar12 + iVar14;
  }
  if (0 < iVar11) {
    do {
      puVar7 = puVar12;
      uVar8 = uVar6 & 1;
      iVar10 = iVar5;
      if (0 < iVar5) {
        do {
          if (uVar8 == 0) {
            uVar3 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar3 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          *puVar7 = local_68[uVar3] & *puVar7;
          iVar10 = iVar10 + -1;
          puVar7 = puVar7 + 1;
          uVar8 = (uint)(uVar8 == 0);
        } while (iVar10 != 0);
      }
      iVar11 = iVar11 + -1;
      puVar12 = puVar12 + iVar2;
      pbVar9 = pbVar9 + (iVar13 - (iVar5 >> 1));
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d4dbc FUN_c08d4dbc */

undefined4 FUN_c08d4dbc(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar7 = *(int **)(param_1 + 0x14);
  if (iVar6 < 0) {
    iVar6 = iVar6 + 3;
  }
  iVar6 = iVar6 >> 2;
  iVar3 = piVar7[2] - *piVar7;
  iVar11 = piVar7[3] - piVar7[1];
  iVar2 = (*(int **)(param_1 + 0x18))[1] * iVar4 + *(int *)(*(int *)(param_1 + 8) + 4) +
          **(int **)(param_1 + 0x18);
  puVar10 = (uint *)((piVar7[1] * iVar6 + *piVar7) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar8 = (iVar11 + -1) * iVar4;
    iVar4 = -iVar4;
    iVar1 = (iVar11 + -1) * iVar6;
    iVar2 = iVar8 + iVar2;
    iVar6 = -iVar6;
    puVar10 = puVar10 + iVar1;
  }
  if (0 < iVar11) {
    do {
      iVar8 = 0;
      puVar9 = puVar10;
      if (0 < iVar3) {
        do {
          pbVar5 = (byte *)(iVar8 + iVar2);
          iVar8 = iVar8 + 1;
          *puVar9 = *(uint *)((uint)*pbVar5 * 4 + *(int *)(param_1 + 0x3c)) & *puVar9;
          puVar9 = puVar9 + 1;
        } while (iVar8 < iVar3);
      }
      iVar11 = iVar11 + -1;
      puVar10 = puVar10 + iVar6;
      iVar2 = iVar2 + iVar4;
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d4ed8 FUN_c08d4ed8 */

/* Boundary evidence: original MIPS .pdata c08d4ed8..c08d507b. Semantic name remains unreviewed. */

undefined4 FUN_c08d4ed8(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined2 *puVar7;
  uint *puVar8;
  uint *puVar9;
  undefined2 *puVar10;
  int iVar11;
  int iVar12;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
  }
  iVar3 = iVar3 >> 1;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar12 = piVar5[2] - *piVar5;
  iVar6 = piVar5[3] - piVar5[1];
  puVar7 = (undefined2 *)
           (((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 2 +
           *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (uint *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar6 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar6 + -1) * iVar4;
    puVar7 = puVar7 + iVar11;
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar6) {
    do {
      puVar9 = puVar8;
      puVar10 = puVar7;
      iVar11 = iVar12;
      if (0 < iVar12) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*puVar10);
          *puVar9 = uVar2 & *puVar9;
          iVar11 = iVar11 + -1;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar6 = iVar6 + -1;
      puVar8 = puVar8 + iVar4;
      puVar7 = puVar7 + iVar3;
    } while (iVar6 != 0);
  }
  return 0;
}



/* c08d507c FUN_c08d507c */

/* Boundary evidence: original MIPS .pdata c08d507c..c08d5223. Semantic name remains unreviewed. */

undefined4 FUN_c08d507c(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint3 *puVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar9 = piVar5[2] - *piVar5;
  iVar7 = piVar5[3] - piVar5[1];
  puVar6 = (uint3 *)((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18) * 3 +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (uint *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar7 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar7 + -1) * iVar4;
    puVar6 = (uint3 *)(iVar11 + (int)puVar6);
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar7) {
    do {
      puVar10 = puVar8;
      iVar11 = iVar9;
      if (0 < iVar9) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),(uint)*puVar6);
          *puVar10 = uVar2 & *puVar10;
          puVar6 = (uint3 *)((int)puVar6 + 3);
          iVar11 = iVar11 + -1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar7 = iVar7 + -1;
      puVar8 = puVar8 + iVar4;
      puVar6 = (uint3 *)((int)puVar6 + iVar3 + iVar9 * -3);
    } while (iVar7 != 0);
  }
  return 0;
}



/* c08d5224 FUN_c08d5224 */

/* Boundary evidence: original MIPS .pdata c08d5224..c08d53e3. Semantic name remains unreviewed. */

undefined4 FUN_c08d5224(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  iVar3 = iVar3 >> 2;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar11 = piVar5[2] - *piVar5;
  iVar8 = piVar5[3] - piVar5[1];
  iVar9 = ((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 4 +
          *(int *)(*(int *)(param_1 + 8) + 4);
  puVar7 = (uint *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar8 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar8 + -1) * iVar4;
    iVar9 = iVar10 * 4 + iVar9;
    iVar4 = -iVar4;
    puVar7 = puVar7 + iVar1;
  }
  if (0 < iVar8) {
    do {
      if (0 < iVar11) {
        puVar6 = puVar7;
        iVar10 = iVar11;
        do {
          if (*(code **)(param_1 + 0x40) == (code *)0x0) {
            *puVar6 = *(uint *)((iVar9 - (int)puVar7) + (int)puVar6) & *puVar6;
          }
          else {
            uVar2 = (**(code **)(param_1 + 0x40))
                              (*(undefined4 *)(param_1 + 0x44),
                               *(undefined4 *)((iVar9 - (int)puVar7) + (int)puVar6));
            *puVar6 = uVar2 & *puVar6;
          }
          iVar10 = iVar10 + -1;
          puVar6 = puVar6 + 1;
        } while (iVar10 != 0);
      }
      iVar8 = iVar8 + -1;
      puVar7 = puVar7 + iVar4;
      iVar9 = iVar3 * 4 + iVar9;
    } while (iVar8 != 0);
  }
  return 0;
}



/* c08d53e4 FUN_c08d53e4 */

/* Boundary evidence: original MIPS .pdata c08d53e4..c08d5913. Semantic name remains unreviewed. */

undefined4 FUN_c08d53e4(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  byte *pbVar12;
  uint *puVar13;
  byte *pbVar14;
  int iVar15;
  int local_38;
  
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 8);
  if (iVar5 < 0) {
    iVar5 = iVar5 + 3;
  }
  piVar6 = *(int **)(param_1 + 0x14);
  iVar15 = 0;
  local_38 = piVar6[3] - piVar6[1];
  iVar8 = **(int **)(param_1 + 0x18);
  uVar9 = -iVar8 & 7;
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  uVar7 = (piVar6[2] - *piVar6) - uVar9;
  iVar2 = (int)uVar7 >> 3;
  uVar7 = uVar7 & 7;
  iVar10 = 0;
  pbVar12 = (byte *)((*(int **)(param_1 + 0x18))[1] * iVar3 + (iVar8 >> 3) +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar11 = (uint *)((piVar6[1] * (iVar5 >> 2) + *piVar6) * 4 + *(int *)(*(int *)(param_1 + 4) + 4))
  ;
  do {
    piVar6 = (int *)((int)&DAT_c0908b00 + iVar10);
    *piVar6 = iVar15;
    if (*(int *)(param_1 + 0x3c) != 0) {
      *piVar6 = *(int *)(iVar10 + *(int *)(param_1 + 0x3c));
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar8 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar6);
      *piVar6 = iVar8;
    }
    iVar10 = iVar10 + 4;
    iVar15 = iVar15 + 1;
  } while (iVar10 < 8);
  if (0 < local_38) {
    do {
      bVar1 = *pbVar12;
      puVar13 = puVar11;
      if (uVar9 == 1) {
LAB_c08d5660:
        *puVar13 = (&DAT_c0908b00)[bVar1 & 1] | *puVar13;
        puVar13 = puVar13 + 1;
        pbVar14 = pbVar12 + 1;
      }
      else {
        if (uVar9 == 2) {
LAB_c08d563c:
          *puVar13 = (&DAT_c0908b00)[bVar1 >> 1 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d5660;
        }
        if (uVar9 == 3) {
LAB_c08d5618:
          *puVar13 = (&DAT_c0908b00)[bVar1 >> 2 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d563c;
        }
        if (uVar9 == 4) {
LAB_c08d55f4:
          *puVar13 = (&DAT_c0908b00)[bVar1 >> 3 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d5618;
        }
        if (uVar9 == 5) {
LAB_c08d55d0:
          *puVar13 = (&DAT_c0908b00)[bVar1 >> 4 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d55f4;
        }
        if (uVar9 == 6) {
LAB_c08d55ac:
          *puVar13 = (&DAT_c0908b00)[bVar1 >> 5 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d55d0;
        }
        pbVar14 = pbVar12;
        if (uVar9 == 7) {
          *puVar11 = (&DAT_c0908b00)[bVar1 >> 6 & 1] | *puVar11;
          puVar13 = puVar11 + 1;
          goto LAB_c08d55ac;
        }
      }
      iVar8 = iVar2;
      if (0 < iVar2) {
        do {
          uVar4 = (uint)*pbVar14;
          puVar13[7] = (&DAT_c0908b00)[uVar4 & 1] | puVar13[7];
          puVar13[6] = (&DAT_c0908b00)[(int)uVar4 >> 1 & 1] | puVar13[6];
          puVar13[5] = (&DAT_c0908b00)[(int)uVar4 >> 2 & 1] | puVar13[5];
          puVar13[4] = (&DAT_c0908b00)[(int)uVar4 >> 3 & 1] | puVar13[4];
          puVar13[3] = (&DAT_c0908b00)[(int)uVar4 >> 4 & 1] | puVar13[3];
          puVar13[2] = (&DAT_c0908b00)[(int)uVar4 >> 5 & 1] | puVar13[2];
          puVar13[1] = (&DAT_c0908b00)[(int)uVar4 >> 6 & 1] | puVar13[1];
          *puVar13 = (&DAT_c0908b00)[(int)uVar4 >> 7] | *puVar13;
          puVar13 = puVar13 + 8;
          iVar8 = iVar8 + -1;
          pbVar14 = pbVar14 + 1;
        } while (iVar8 != 0);
      }
      if (uVar7 != 0) {
        bVar1 = *pbVar14;
        if (uVar7 != 1) {
          if (uVar7 != 2) {
            if (uVar7 != 3) {
              if (uVar7 != 4) {
                if (uVar7 != 5) {
                  if (uVar7 != 6) {
                    if (uVar7 != 7) goto LAB_c08d58c8;
                    puVar13[6] = (&DAT_c0908b00)[bVar1 >> 1 & 1] | puVar13[6];
                  }
                  puVar13[5] = (&DAT_c0908b00)[bVar1 >> 2 & 1] | puVar13[5];
                }
                puVar13[4] = (&DAT_c0908b00)[bVar1 >> 3 & 1] | puVar13[4];
              }
              puVar13[3] = (&DAT_c0908b00)[bVar1 >> 4 & 1] | puVar13[3];
            }
            puVar13[2] = (&DAT_c0908b00)[bVar1 >> 5 & 1] | puVar13[2];
          }
          puVar13[1] = (&DAT_c0908b00)[bVar1 >> 6 & 1] | puVar13[1];
        }
        *puVar13 = (&DAT_c0908b00)[bVar1 >> 7] | *puVar13;
      }
LAB_c08d58c8:
      local_38 = local_38 + -1;
      pbVar12 = pbVar12 + iVar3;
      puVar11 = puVar11 + (iVar5 >> 2);
    } while (local_38 != 0);
  }
  return 0;
}



/* c08d5914 FUN_c08d5914 */

/* Boundary evidence: original MIPS .pdata c08d5914..c08d5b23. Semantic name remains unreviewed. */

undefined4 FUN_c08d5914(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  uint local_68 [16];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar13 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar4 = *(int **)(param_1 + 0x14);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 3;
  }
  iVar2 = iVar2 >> 2;
  iVar5 = piVar4[2] - *piVar4;
  uVar6 = **(uint **)(param_1 + 0x18);
  iVar11 = piVar4[3] - piVar4[1];
  iVar14 = 0;
  iVar10 = 0;
  pbVar9 = (byte *)((*(uint **)(param_1 + 0x18))[1] * iVar13 + ((int)uVar6 >> 1) +
                   *(int *)(*(int *)(param_1 + 8) + 4));
  puVar12 = (uint *)((piVar4[1] * iVar2 + *piVar4) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar4 = (int *)((int)local_68 + iVar10);
    iVar1 = *(int *)(param_1 + 0x3c);
    *piVar4 = iVar14;
    if (iVar1 != 0) {
      *piVar4 = *(int *)(iVar10 + iVar1);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar4);
      *piVar4 = iVar1;
    }
    iVar10 = iVar10 + 4;
    iVar14 = iVar14 + 1;
  } while (iVar10 < 0x40);
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar11 + -1) * iVar13;
    iVar13 = -iVar13;
    iVar14 = (iVar11 + -1) * iVar2;
    pbVar9 = pbVar9 + iVar10;
    iVar2 = -iVar2;
    puVar12 = puVar12 + iVar14;
  }
  if (0 < iVar11) {
    do {
      puVar7 = puVar12;
      uVar8 = uVar6 & 1;
      iVar10 = iVar5;
      if (0 < iVar5) {
        do {
          if (uVar8 == 0) {
            uVar3 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar3 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          *puVar7 = local_68[uVar3] | *puVar7;
          iVar10 = iVar10 + -1;
          puVar7 = puVar7 + 1;
          uVar8 = (uint)(uVar8 == 0);
        } while (iVar10 != 0);
      }
      iVar11 = iVar11 + -1;
      puVar12 = puVar12 + iVar2;
      pbVar9 = pbVar9 + (iVar13 - (iVar5 >> 1));
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d5b24 FUN_c08d5b24 */

undefined4 FUN_c08d5b24(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar7 = *(int **)(param_1 + 0x14);
  if (iVar6 < 0) {
    iVar6 = iVar6 + 3;
  }
  iVar6 = iVar6 >> 2;
  iVar3 = piVar7[2] - *piVar7;
  iVar11 = piVar7[3] - piVar7[1];
  iVar2 = (*(int **)(param_1 + 0x18))[1] * iVar4 + *(int *)(*(int *)(param_1 + 8) + 4) +
          **(int **)(param_1 + 0x18);
  puVar10 = (uint *)((piVar7[1] * iVar6 + *piVar7) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar8 = (iVar11 + -1) * iVar4;
    iVar4 = -iVar4;
    iVar1 = (iVar11 + -1) * iVar6;
    iVar2 = iVar8 + iVar2;
    iVar6 = -iVar6;
    puVar10 = puVar10 + iVar1;
  }
  if (0 < iVar11) {
    do {
      iVar8 = 0;
      puVar9 = puVar10;
      if (0 < iVar3) {
        do {
          pbVar5 = (byte *)(iVar8 + iVar2);
          iVar8 = iVar8 + 1;
          *puVar9 = *(uint *)((uint)*pbVar5 * 4 + *(int *)(param_1 + 0x3c)) | *puVar9;
          puVar9 = puVar9 + 1;
        } while (iVar8 < iVar3);
      }
      iVar11 = iVar11 + -1;
      puVar10 = puVar10 + iVar6;
      iVar2 = iVar2 + iVar4;
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d5c40 FUN_c08d5c40 */

/* Boundary evidence: original MIPS .pdata c08d5c40..c08d5de3. Semantic name remains unreviewed. */

undefined4 FUN_c08d5c40(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined2 *puVar7;
  uint *puVar8;
  uint *puVar9;
  undefined2 *puVar10;
  int iVar11;
  int iVar12;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
  }
  iVar3 = iVar3 >> 1;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar12 = piVar5[2] - *piVar5;
  iVar6 = piVar5[3] - piVar5[1];
  puVar7 = (undefined2 *)
           (((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 2 +
           *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (uint *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar6 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar6 + -1) * iVar4;
    puVar7 = puVar7 + iVar11;
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar6) {
    do {
      puVar9 = puVar8;
      puVar10 = puVar7;
      iVar11 = iVar12;
      if (0 < iVar12) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*puVar10);
          *puVar9 = uVar2 | *puVar9;
          iVar11 = iVar11 + -1;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar6 = iVar6 + -1;
      puVar8 = puVar8 + iVar4;
      puVar7 = puVar7 + iVar3;
    } while (iVar6 != 0);
  }
  return 0;
}



/* c08d5de4 FUN_c08d5de4 */

/* Boundary evidence: original MIPS .pdata c08d5de4..c08d5f8b. Semantic name remains unreviewed. */

undefined4 FUN_c08d5de4(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint3 *puVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar9 = piVar5[2] - *piVar5;
  iVar7 = piVar5[3] - piVar5[1];
  puVar6 = (uint3 *)((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18) * 3 +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (uint *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar7 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar7 + -1) * iVar4;
    puVar6 = (uint3 *)(iVar11 + (int)puVar6);
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar7) {
    do {
      puVar10 = puVar8;
      iVar11 = iVar9;
      if (0 < iVar9) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),(uint)*puVar6);
          *puVar10 = uVar2 | *puVar10;
          puVar6 = (uint3 *)((int)puVar6 + 3);
          iVar11 = iVar11 + -1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar7 = iVar7 + -1;
      puVar8 = puVar8 + iVar4;
      puVar6 = (uint3 *)((int)puVar6 + iVar3 + iVar9 * -3);
    } while (iVar7 != 0);
  }
  return 0;
}



/* c08d5f8c FUN_c08d5f8c */

/* Boundary evidence: original MIPS .pdata c08d5f8c..c08d614b. Semantic name remains unreviewed. */

undefined4 FUN_c08d5f8c(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  iVar3 = iVar3 >> 2;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar11 = piVar5[2] - *piVar5;
  iVar8 = piVar5[3] - piVar5[1];
  iVar9 = ((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 4 +
          *(int *)(*(int *)(param_1 + 8) + 4);
  puVar7 = (uint *)((piVar5[1] * iVar4 + *piVar5) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar8 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar8 + -1) * iVar4;
    iVar9 = iVar10 * 4 + iVar9;
    iVar4 = -iVar4;
    puVar7 = puVar7 + iVar1;
  }
  if (0 < iVar8) {
    do {
      if (0 < iVar11) {
        puVar6 = puVar7;
        iVar10 = iVar11;
        do {
          if (*(code **)(param_1 + 0x40) == (code *)0x0) {
            *puVar6 = *(uint *)((iVar9 - (int)puVar7) + (int)puVar6) | *puVar6;
          }
          else {
            uVar2 = (**(code **)(param_1 + 0x40))
                              (*(undefined4 *)(param_1 + 0x44),
                               *(undefined4 *)((iVar9 - (int)puVar7) + (int)puVar6));
            *puVar6 = uVar2 | *puVar6;
          }
          iVar10 = iVar10 + -1;
          puVar6 = puVar6 + 1;
        } while (iVar10 != 0);
      }
      iVar8 = iVar8 + -1;
      puVar7 = puVar7 + iVar4;
      iVar9 = iVar3 * 4 + iVar9;
    } while (iVar8 != 0);
  }
  return 0;
}



/* c08d614c FUN_c08d614c */

/* Boundary evidence: original MIPS .pdata c08d614c..c08d655f. Semantic name remains unreviewed. */

undefined4 FUN_c08d614c(int param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  int *piVar18;
  int iVar19;
  int iVar20;
  byte *pbVar21;
  undefined4 *puVar22;
  int *piVar23;
  byte *pbVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  
  iVar14 = *(int *)(*(int *)(param_1 + 4) + 4);
  iVar15 = *(int *)(*(int *)(param_1 + 4) + 8);
  if (iVar15 < 0) {
    iVar15 = iVar15 + 3;
  }
  piVar23 = *(int **)(param_1 + 0x14);
  iVar29 = *piVar23;
  piVar18 = *(int **)(param_1 + 0x18);
  iVar9 = piVar23[2] - iVar29;
  iVar30 = piVar23[1];
  iVar26 = *(int *)(*(int *)(param_1 + 8) + 8);
  iVar16 = piVar18[2] - *piVar18;
  iVar31 = piVar23[3] - iVar30;
  bVar3 = false;
  iVar20 = piVar18[3] - piVar18[1];
  bVar1 = false;
  bVar2 = false;
  iVar32 = 0;
  iVar12 = 0;
  iVar27 = 0;
  bVar5 = false;
  bVar4 = false;
  bVar6 = false;
  bVar7 = false;
  if (iVar16 < iVar9) {
    bVar4 = true;
    iVar8 = iVar9;
    iVar25 = iVar16;
LAB_c08d6248:
    bVar5 = true;
    iVar25 = iVar25 * 2;
    iVar28 = iVar25 + iVar8 * -2;
    if (bVar1) {
      iVar8 = iVar9 * 2 - iVar16;
    }
    else {
      iVar8 = iVar16 * 3 + iVar9 * -2;
    }
  }
  else {
    iVar8 = iVar14;
    iVar25 = iVar14;
    iVar28 = iVar14;
    if (iVar9 < iVar16) {
      bVar1 = true;
      iVar8 = iVar16;
      iVar25 = iVar9;
      goto LAB_c08d6248;
    }
  }
  if (iVar20 < iVar31) {
    bVar2 = true;
    iVar16 = iVar31;
    iVar11 = iVar20;
  }
  else {
    iVar10 = iVar14;
    iVar11 = iVar14;
    iVar16 = iVar14;
    if (iVar20 <= iVar31) goto LAB_c08d630c;
    bVar3 = true;
    bVar7 = true;
    iVar16 = iVar20;
    iVar11 = iVar31;
  }
  bVar6 = true;
  iVar11 = iVar11 * 2;
  iVar10 = iVar11 + iVar16 * -2;
  if (bVar3) {
    iVar16 = iVar31 * 2 - iVar20;
  }
  else {
    iVar16 = iVar20 * 3 + iVar31 * -2;
  }
LAB_c08d630c:
  piVar17 = *(int **)(param_1 + 0x1c);
  if (piVar17 != (int *)0x0) {
    iVar20 = *piVar23;
    if (*piVar23 < *piVar17) {
      iVar20 = *piVar17;
    }
    iVar19 = piVar23[1];
    if (piVar23[1] < piVar17[1]) {
      iVar19 = piVar17[1];
    }
    iVar31 = piVar23[3];
    if (piVar17[3] < piVar23[3]) {
      iVar31 = piVar17[3];
    }
    iVar9 = piVar23[2];
    if (piVar17[2] < piVar23[2]) {
      iVar9 = piVar17[2];
    }
    if (iVar9 <= iVar20) {
      return 0;
    }
    if (iVar31 <= iVar19) {
      return 0;
    }
    iVar32 = iVar20 - iVar29;
    iVar12 = iVar19 - iVar30;
    iVar9 = iVar9 - iVar20;
    iVar31 = iVar31 - iVar19;
  }
  if (bVar4) {
    for (; iVar32 != 0; iVar32 = iVar32 + -1) {
      iVar20 = iVar28;
      if (iVar8 < 0) {
        iVar20 = iVar25;
      }
      iVar8 = iVar8 + iVar20;
    }
  }
  iVar32 = iVar12;
  if (bVar2) {
    for (; iVar32 != 0; iVar32 = iVar32 + -1) {
      iVar20 = iVar11;
      if (-1 < iVar16) {
        iVar27 = iVar27 + 1;
        iVar20 = iVar10;
      }
      iVar16 = iVar16 + iVar20;
    }
  }
  pbVar24 = (byte *)((piVar18[1] + iVar27) * iVar26 + *piVar18 + *(int *)(*(int *)(param_1 + 8) + 4)
                    );
  puVar13 = (undefined4 *)(((iVar30 + iVar12) * (iVar15 >> 2) + iVar29) * 4 + iVar14);
  if (0 < iVar31) {
    do {
      iVar14 = iVar8;
      pbVar21 = pbVar24;
      puVar22 = puVar13;
      iVar32 = iVar9;
      if (0 < iVar9) {
        do {
          if (bVar5) {
            if (!bVar4) {
              for (; iVar14 < 0; iVar14 = iVar14 + iVar25) {
              }
              iVar14 = iVar14 + iVar28;
              goto LAB_c08d64c0;
            }
            *puVar22 = *(undefined4 *)((uint)*pbVar21 * 4 + *(int *)(param_1 + 0x3c));
            if (-1 < iVar14) {
              iVar14 = iVar14 + iVar28;
              goto LAB_c08d64d8;
            }
            iVar14 = iVar14 + iVar25;
          }
          else {
LAB_c08d64c0:
            *puVar22 = *(undefined4 *)((uint)*pbVar21 * 4 + *(int *)(param_1 + 0x3c));
LAB_c08d64d8:
            pbVar21 = pbVar21 + 1;
          }
          iVar32 = iVar32 + -1;
          puVar22 = puVar22 + 1;
        } while (iVar32 != 0);
      }
      if (bVar6) {
        if (-1 < iVar16) {
LAB_c08d6510:
          iVar16 = iVar16 + iVar10;
          goto LAB_c08d6514;
        }
        if (bVar7) {
          do {
            iVar16 = iVar16 + iVar11;
            pbVar24 = pbVar24 + iVar26;
          } while (iVar16 < 0);
          goto LAB_c08d6510;
        }
        iVar16 = iVar16 + iVar11;
      }
      else {
LAB_c08d6514:
        pbVar24 = pbVar24 + iVar26;
      }
      iVar31 = iVar31 + -1;
      puVar13 = puVar13 + (iVar15 >> 2);
    } while (iVar31 != 0);
  }
  return 0;
}



/* c08d6560 FUN_c08d6560 */

/* Boundary evidence: original MIPS .pdata c08d6560..c08d66a3. Semantic name remains unreviewed. */

undefined4 FUN_c08d6560(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  
  if ((*(uint *)(param_1 + 0x24) & 8) == 0) {
    iVar7 = *(int *)(*(int *)(param_1 + 4) + 8);
    iVar5 = *(int *)(*(int *)(param_1 + 8) + 8);
    piVar8 = *(int **)(param_1 + 0x14);
    if (iVar7 < 0) {
      iVar7 = iVar7 + 3;
    }
    iVar7 = iVar7 >> 2;
    iVar4 = piVar8[2] - *piVar8;
    iVar12 = piVar8[3] - piVar8[1];
    iVar3 = (*(int **)(param_1 + 0x18))[1] * iVar5 + *(int *)(*(int *)(param_1 + 8) + 4) +
            **(int **)(param_1 + 0x18);
    puVar11 = (undefined4 *)
              ((piVar8[1] * iVar7 + *piVar8) * 4 + *(int *)(*(int *)(param_1 + 4) + 4));
    if (*(int *)(param_1 + 0x38) == 0) {
      iVar9 = (iVar12 + -1) * iVar5;
      iVar5 = -iVar5;
      iVar1 = (iVar12 + -1) * iVar7;
      iVar3 = iVar9 + iVar3;
      iVar7 = -iVar7;
      puVar11 = puVar11 + iVar1;
    }
    if (0 < iVar12) {
      do {
        iVar9 = 0;
        puVar10 = puVar11;
        if (0 < iVar4) {
          do {
            pbVar6 = (byte *)(iVar9 + iVar3);
            iVar9 = iVar9 + 1;
            *puVar10 = *(undefined4 *)((uint)*pbVar6 * 4 + *(int *)(param_1 + 0x3c));
            puVar10 = puVar10 + 1;
          } while (iVar9 < iVar4);
        }
        iVar12 = iVar12 + -1;
        puVar11 = puVar11 + iVar7;
        iVar3 = iVar3 + iVar5;
      } while (iVar12 != 0);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_c08d614c(param_1);
  }
  return uVar2;
}



/* c08d66a4 FUN_c08d66a4 */

/* Boundary evidence: original MIPS .pdata c08d66a4..c08d6b73. Semantic name remains unreviewed. */

void FUN_c08d66a4(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_2[10];
  if (iVar1 == 0x6666) {
    iVar1 = *(int *)(param_2[2] + 0x1c);
    if (iVar1 == 0) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d2d78((int)param_2);
        return;
      }
    }
    else if (iVar1 == 2) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d32a8((int)param_2);
        return;
      }
    }
    else if (iVar1 == 3) {
      if (param_2[0xf] != 0) {
        FUN_c08d34b8((int)param_2);
        return;
      }
    }
    else if (iVar1 == 4) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d35d4((int)param_2);
        return;
      }
    }
    else if (iVar1 == 5) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d3778((int)param_2);
        return;
      }
    }
    else if ((iVar1 == 6) && ((param_2[9] & 8U) == 0)) {
      FUN_c08d3920((int)param_2);
      return;
    }
  }
  else if (iVar1 == 0x8888) {
    iVar1 = *(int *)(param_2[2] + 0x1c);
    if (iVar1 == 0) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d467c((int)param_2);
        return;
      }
    }
    else if (iVar1 == 2) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d4bac((int)param_2);
        return;
      }
    }
    else if (iVar1 == 3) {
      if (param_2[0xf] != 0) {
        FUN_c08d4dbc((int)param_2);
        return;
      }
    }
    else if (iVar1 == 4) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d4ed8((int)param_2);
        return;
      }
    }
    else if (iVar1 == 5) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d507c((int)param_2);
        return;
      }
    }
    else if ((iVar1 == 6) && ((param_2[9] & 8U) == 0)) {
      FUN_c08d5224((int)param_2);
      return;
    }
  }
  else if (iVar1 == 0xcccc) {
    iVar1 = *(int *)(param_2[2] + 0x1c);
    if (iVar1 == 0) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d3ae0((int)param_2);
        return;
      }
    }
    else if (iVar1 == 2) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d3f64((int)param_2);
        return;
      }
    }
    else if (iVar1 == 3) {
      if (param_2[0xf] != 0) {
        FUN_c08d6560((int)param_2);
        return;
      }
    }
    else if (iVar1 == 4) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d416c((int)param_2);
        return;
      }
    }
    else if (iVar1 == 5) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d4308((int)param_2);
        return;
      }
    }
    else if ((iVar1 == 6) && ((param_2[9] & 8U) == 0)) {
      FUN_c08d44a8((int)param_2);
      return;
    }
  }
  else if (iVar1 == 0xeeee) {
    iVar1 = *(int *)(param_2[2] + 0x1c);
    if (iVar1 == 0) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d53e4((int)param_2);
        return;
      }
    }
    else if (iVar1 == 2) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d5914((int)param_2);
        return;
      }
    }
    else if (iVar1 == 3) {
      if (param_2[0xf] != 0) {
        FUN_c08d5b24((int)param_2);
        return;
      }
    }
    else if (iVar1 == 4) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d5c40((int)param_2);
        return;
      }
    }
    else if (iVar1 == 5) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d5de4((int)param_2);
        return;
      }
    }
    else if ((iVar1 == 6) && ((param_2[9] & 8U) == 0)) {
      FUN_c08d5f8c((int)param_2);
      return;
    }
  }
  FUN_c08ea8b8(param_1,param_2);
  return;
}



/* c08d6b74 FUN_c08d6b74 */

void FUN_c08d6b74(int param_1)

{
  *(undefined1 **)(param_1 + 0x6a1c) = &LAB_c08d2b94;
  *(undefined1 **)(param_1 + 0x6a18) = &LAB_c08d2ce4;
  *(undefined1 **)(param_1 + 0x6a20) = &LAB_c08d2c40;
  *(code **)(param_1 + 0x6a2c) = FUN_c08d66a4;
  *(code **)(param_1 + 0x6a24) = FUN_c08d66a4;
  *(code **)(param_1 + 0x6a28) = FUN_c08d66a4;
  *(code **)(param_1 + 0x6a30) = FUN_c08d66a4;
  return;
}



/* c08d6d90 FUN_c08d6d90 */

/* Boundary evidence: original MIPS .pdata c08d6d90..c08d72b3. Semantic name remains unreviewed. */

undefined4 FUN_c08d6d90(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  ushort *puVar11;
  byte *pbVar12;
  ushort *puVar13;
  byte *pbVar14;
  int iVar15;
  int local_38;
  
  iVar15 = 0;
  piVar6 = *(int **)(param_1 + 0x14);
  uVar3 = *(uint *)(*(int *)(param_1 + 4) + 8) >> 1;
  local_38 = piVar6[3] - piVar6[1];
  iVar8 = **(int **)(param_1 + 0x18);
  uVar9 = -iVar8 & 7;
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  uVar7 = (piVar6[2] - *piVar6) - uVar9;
  iVar2 = (int)uVar7 >> 3;
  uVar7 = uVar7 & 7;
  iVar10 = 0;
  pbVar12 = (byte *)((*(int **)(param_1 + 0x18))[1] * iVar4 + (iVar8 >> 3) +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar11 = (ushort *)((piVar6[1] * uVar3 + *piVar6) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar6 = (int *)((int)&DAT_c0908b08 + iVar10);
    *piVar6 = iVar15;
    if (*(int *)(param_1 + 0x3c) != 0) {
      *piVar6 = *(int *)(*(int *)(param_1 + 0x3c) + iVar10);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar8 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar6);
      *piVar6 = iVar8;
    }
    iVar10 = iVar10 + 4;
    iVar15 = iVar15 + 1;
  } while (iVar10 < 8);
  if (0 < local_38) {
    do {
      bVar1 = *pbVar12;
      puVar13 = puVar11;
      if (uVar9 == 1) {
LAB_c08d7000:
        *puVar13 = (ushort)(&DAT_c0908b08)[bVar1 & 1] ^ *puVar13;
        puVar13 = puVar13 + 1;
        pbVar14 = pbVar12 + 1;
      }
      else {
        if (uVar9 == 2) {
LAB_c08d6fdc:
          *puVar13 = (ushort)(&DAT_c0908b08)[bVar1 >> 1 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d7000;
        }
        if (uVar9 == 3) {
LAB_c08d6fb8:
          *puVar13 = (ushort)(&DAT_c0908b08)[bVar1 >> 2 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d6fdc;
        }
        if (uVar9 == 4) {
LAB_c08d6f94:
          *puVar13 = (ushort)(&DAT_c0908b08)[bVar1 >> 3 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d6fb8;
        }
        if (uVar9 == 5) {
LAB_c08d6f70:
          *puVar13 = (ushort)(&DAT_c0908b08)[bVar1 >> 4 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d6f94;
        }
        if (uVar9 == 6) {
LAB_c08d6f4c:
          *puVar13 = (ushort)(&DAT_c0908b08)[bVar1 >> 5 & 1] ^ *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d6f70;
        }
        pbVar14 = pbVar12;
        if (uVar9 == 7) {
          *puVar11 = (ushort)(&DAT_c0908b08)[bVar1 >> 6 & 1] ^ *puVar11;
          puVar13 = puVar11 + 1;
          goto LAB_c08d6f4c;
        }
      }
      iVar8 = iVar2;
      if (0 < iVar2) {
        do {
          uVar5 = (uint)*pbVar14;
          puVar13[7] = (ushort)(&DAT_c0908b08)[uVar5 & 1] ^ puVar13[7];
          puVar13[6] = (ushort)(&DAT_c0908b08)[(int)uVar5 >> 1 & 1] ^ puVar13[6];
          puVar13[5] = (ushort)(&DAT_c0908b08)[(int)uVar5 >> 2 & 1] ^ puVar13[5];
          puVar13[4] = (ushort)(&DAT_c0908b08)[(int)uVar5 >> 3 & 1] ^ puVar13[4];
          puVar13[3] = (ushort)(&DAT_c0908b08)[(int)uVar5 >> 4 & 1] ^ puVar13[3];
          puVar13[2] = (ushort)(&DAT_c0908b08)[(int)uVar5 >> 5 & 1] ^ puVar13[2];
          puVar13[1] = (ushort)(&DAT_c0908b08)[(int)uVar5 >> 6 & 1] ^ puVar13[1];
          *puVar13 = (ushort)(&DAT_c0908b08)[(int)uVar5 >> 7] ^ *puVar13;
          puVar13 = puVar13 + 8;
          iVar8 = iVar8 + -1;
          pbVar14 = pbVar14 + 1;
        } while (iVar8 != 0);
      }
      if (uVar7 != 0) {
        bVar1 = *pbVar14;
        if (uVar7 != 1) {
          if (uVar7 != 2) {
            if (uVar7 != 3) {
              if (uVar7 != 4) {
                if (uVar7 != 5) {
                  if (uVar7 != 6) {
                    if (uVar7 != 7) goto LAB_c08d7268;
                    puVar13[6] = (ushort)(&DAT_c0908b08)[bVar1 >> 1 & 1] ^ puVar13[6];
                  }
                  puVar13[5] = (ushort)(&DAT_c0908b08)[bVar1 >> 2 & 1] ^ puVar13[5];
                }
                puVar13[4] = (ushort)(&DAT_c0908b08)[bVar1 >> 3 & 1] ^ puVar13[4];
              }
              puVar13[3] = (ushort)(&DAT_c0908b08)[bVar1 >> 4 & 1] ^ puVar13[3];
            }
            puVar13[2] = (ushort)(&DAT_c0908b08)[bVar1 >> 5 & 1] ^ puVar13[2];
          }
          puVar13[1] = (ushort)(&DAT_c0908b08)[bVar1 >> 6 & 1] ^ puVar13[1];
        }
        *puVar13 = (ushort)(&DAT_c0908b08)[bVar1 >> 7] ^ *puVar13;
      }
LAB_c08d7268:
      local_38 = local_38 + -1;
      pbVar12 = pbVar12 + iVar4;
      puVar11 = puVar11 + uVar3;
    } while (local_38 != 0);
  }
  return 0;
}



/* c08d72b4 FUN_c08d72b4 */

/* Boundary evidence: original MIPS .pdata c08d72b4..c08d74c3. Semantic name remains unreviewed. */

undefined4 FUN_c08d72b4(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  int iVar14;
  int local_68 [16];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar13 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar4 = *(int **)(param_1 + 0x14);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  iVar2 = iVar2 >> 1;
  iVar5 = piVar4[2] - *piVar4;
  uVar6 = **(uint **)(param_1 + 0x18);
  iVar11 = piVar4[3] - piVar4[1];
  iVar14 = 0;
  iVar10 = 0;
  pbVar9 = (byte *)((*(uint **)(param_1 + 0x18))[1] * iVar13 + ((int)uVar6 >> 1) +
                   *(int *)(*(int *)(param_1 + 8) + 4));
  puVar12 = (ushort *)((piVar4[1] * iVar2 + *piVar4) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar4 = (int *)((int)local_68 + iVar10);
    iVar1 = *(int *)(param_1 + 0x3c);
    *piVar4 = iVar14;
    if (iVar1 != 0) {
      *piVar4 = *(int *)(iVar10 + iVar1);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar4);
      *piVar4 = iVar1;
    }
    iVar10 = iVar10 + 4;
    iVar14 = iVar14 + 1;
  } while (iVar10 < 0x40);
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar11 + -1) * iVar13;
    iVar13 = -iVar13;
    iVar14 = (iVar11 + -1) * iVar2;
    pbVar9 = pbVar9 + iVar10;
    iVar2 = -iVar2;
    puVar12 = puVar12 + iVar14;
  }
  if (0 < iVar11) {
    do {
      puVar7 = puVar12;
      uVar8 = uVar6 & 1;
      iVar10 = iVar5;
      if (0 < iVar5) {
        do {
          if (uVar8 == 0) {
            uVar3 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar3 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          *puVar7 = (ushort)local_68[uVar3] ^ *puVar7;
          iVar10 = iVar10 + -1;
          puVar7 = puVar7 + 1;
          uVar8 = (uint)(uVar8 == 0);
        } while (iVar10 != 0);
      }
      iVar11 = iVar11 + -1;
      puVar12 = puVar12 + iVar2;
      pbVar9 = pbVar9 + (iVar13 - (iVar5 >> 1));
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d74c4 FUN_c08d74c4 */

undefined4 FUN_c08d74c4(int param_1)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  ushort *puVar10;
  int iVar11;
  
  iVar7 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar8 = *(int **)(param_1 + 0x14);
  if (iVar7 < 0) {
    iVar7 = iVar7 + 1;
  }
  iVar7 = iVar7 >> 1;
  iVar4 = piVar8[2] - *piVar8;
  iVar11 = piVar8[3] - piVar8[1];
  iVar3 = (*(int **)(param_1 + 0x18))[1] * iVar5 + *(int *)(*(int *)(param_1 + 8) + 4) +
          **(int **)(param_1 + 0x18);
  puVar10 = (ushort *)((piVar8[1] * iVar7 + *piVar8) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar9 = (iVar11 + -1) * iVar5;
    iVar5 = -iVar5;
    iVar1 = (iVar11 + -1) * iVar7;
    iVar3 = iVar9 + iVar3;
    iVar7 = -iVar7;
    puVar10 = puVar10 + iVar1;
  }
  if (0 < iVar11) {
    do {
      iVar9 = 0;
      puVar2 = puVar10;
      if (0 < iVar4) {
        do {
          pbVar6 = (byte *)(iVar9 + iVar3);
          iVar9 = iVar9 + 1;
          *puVar2 = (ushort)*(undefined4 *)((uint)*pbVar6 * 4 + *(int *)(param_1 + 0x3c)) ^ *puVar2;
          puVar2 = puVar2 + 1;
        } while (iVar9 < iVar4);
      }
      iVar11 = iVar11 + -1;
      puVar10 = puVar10 + iVar7;
      iVar3 = iVar3 + iVar5;
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d75e0 FUN_c08d75e0 */

/* Boundary evidence: original MIPS .pdata c08d75e0..c08d779b. Semantic name remains unreviewed. */

undefined4 FUN_c08d75e0(int param_1)

{
  int iVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  ushort *puVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar6 = *(int **)(param_1 + 0x14);
  if (iVar5 < 0) {
    iVar5 = iVar5 + 1;
  }
  iVar5 = iVar5 >> 1;
  iVar12 = piVar6[2] - *piVar6;
  iVar9 = piVar6[3] - piVar6[1];
  iVar10 = ((*(int **)(param_1 + 0x18))[1] * iVar4 + **(int **)(param_1 + 0x18)) * 2 +
           *(int *)(*(int *)(param_1 + 8) + 4);
  puVar8 = (ushort *)((piVar6[1] * iVar5 + *piVar6) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar9 + -1) * iVar4;
    iVar4 = -iVar4;
    iVar1 = (iVar9 + -1) * iVar5;
    iVar10 = iVar11 * 2 + iVar10;
    iVar5 = -iVar5;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar9) {
    do {
      if (0 < iVar12) {
        puVar7 = puVar8;
        iVar11 = iVar12;
        do {
          puVar3 = (ushort *)((iVar10 - (int)puVar8) + (int)puVar7);
          if (*(code **)(param_1 + 0x40) == (code *)0x0) {
            *puVar7 = *puVar3 ^ *puVar7;
          }
          else {
            uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*puVar3);
            *puVar7 = uVar2 ^ *puVar7;
          }
          iVar11 = iVar11 + -1;
          puVar7 = puVar7 + 1;
        } while (iVar11 != 0);
      }
      iVar9 = iVar9 + -1;
      puVar8 = puVar8 + iVar5;
      iVar10 = iVar4 * 2 + iVar10;
    } while (iVar9 != 0);
  }
  return 0;
}



/* c08d779c FUN_c08d779c */

/* Boundary evidence: original MIPS .pdata c08d779c..c08d7943. Semantic name remains unreviewed. */

undefined4 FUN_c08d779c(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint3 *puVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  ushort *puVar10;
  int iVar11;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar9 = piVar5[2] - *piVar5;
  iVar7 = piVar5[3] - piVar5[1];
  puVar6 = (uint3 *)((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18) * 3 +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (ushort *)((piVar5[1] * iVar4 + *piVar5) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar7 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar7 + -1) * iVar4;
    puVar6 = (uint3 *)(iVar11 + (int)puVar6);
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar7) {
    do {
      puVar10 = puVar8;
      iVar11 = iVar9;
      if (0 < iVar9) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),(uint)*puVar6);
          *puVar10 = uVar2 ^ *puVar10;
          puVar6 = (uint3 *)((int)puVar6 + 3);
          iVar11 = iVar11 + -1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar7 = iVar7 + -1;
      puVar8 = puVar8 + iVar4;
      puVar6 = (uint3 *)((int)puVar6 + iVar3 + iVar9 * -3);
    } while (iVar7 != 0);
  }
  return 0;
}



/* c08d7944 FUN_c08d7944 */

/* Boundary evidence: original MIPS .pdata c08d7944..c08d7ae3. Semantic name remains unreviewed. */

undefined4 FUN_c08d7944(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  iVar3 = iVar3 >> 2;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar12 = piVar5[2] - *piVar5;
  iVar6 = piVar5[3] - piVar5[1];
  puVar7 = (undefined4 *)
           (((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 4 +
           *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (ushort *)((piVar5[1] * iVar4 + *piVar5) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar6 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar6 + -1) * iVar4;
    puVar7 = puVar7 + iVar11;
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar6) {
    do {
      puVar9 = puVar8;
      puVar10 = puVar7;
      iVar11 = iVar12;
      if (0 < iVar12) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*puVar10);
          *puVar9 = uVar2 ^ *puVar9;
          iVar11 = iVar11 + -1;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar6 = iVar6 + -1;
      puVar8 = puVar8 + iVar4;
      puVar7 = puVar7 + iVar3;
    } while (iVar6 != 0);
  }
  return 0;
}



/* c08d7ae4 FUN_c08d7ae4 */

/* Boundary evidence: original MIPS .pdata c08d7ae4..c08d800b. Semantic name remains unreviewed. */

undefined4 FUN_c08d7ae4(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  ushort *puVar12;
  byte *pbVar13;
  ushort *puVar14;
  int iVar15;
  int local_38;
  
  iVar15 = 0;
  piVar7 = *(int **)(param_1 + 0x14);
  uVar3 = *(uint *)(*(int *)(param_1 + 4) + 8) >> 1;
  local_38 = piVar7[3] - piVar7[1];
  iVar9 = **(int **)(param_1 + 0x18);
  uVar10 = -iVar9 & 7;
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 8);
  uVar8 = (piVar7[2] - *piVar7) - uVar10;
  iVar2 = (int)uVar8 >> 3;
  uVar8 = uVar8 & 7;
  iVar11 = 0;
  pbVar13 = (byte *)((*(int **)(param_1 + 0x18))[1] * iVar5 + (iVar9 >> 3) +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar12 = (ushort *)((piVar7[1] * uVar3 + *piVar7) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar7 = (int *)((int)&DAT_c0908b10 + iVar11);
    *piVar7 = iVar15;
    if (*(int *)(param_1 + 0x3c) != 0) {
      *piVar7 = *(int *)(*(int *)(param_1 + 0x3c) + iVar11);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar9 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar7);
      *piVar7 = iVar9;
    }
    iVar11 = iVar11 + 4;
    iVar15 = iVar15 + 1;
  } while (iVar11 < 8);
  if (0 < local_38) {
    do {
      bVar1 = *pbVar13;
      puVar14 = puVar12;
      if (uVar10 == 1) {
LAB_c08d7d54:
        *puVar14 = (ushort)(&DAT_c0908b10)[bVar1 & 1] & *puVar14;
        puVar14 = puVar14 + 1;
        pbVar4 = pbVar13 + 1;
      }
      else {
        if (uVar10 == 2) {
LAB_c08d7d30:
          *puVar14 = (ushort)(&DAT_c0908b10)[bVar1 >> 1 & 1] & *puVar14;
          puVar14 = puVar14 + 1;
          goto LAB_c08d7d54;
        }
        if (uVar10 == 3) {
LAB_c08d7d0c:
          *puVar14 = (ushort)(&DAT_c0908b10)[bVar1 >> 2 & 1] & *puVar14;
          puVar14 = puVar14 + 1;
          goto LAB_c08d7d30;
        }
        if (uVar10 == 4) {
LAB_c08d7ce8:
          *puVar14 = (ushort)(&DAT_c0908b10)[bVar1 >> 3 & 1] & *puVar14;
          puVar14 = puVar14 + 1;
          goto LAB_c08d7d0c;
        }
        if (uVar10 == 5) {
LAB_c08d7cc4:
          *puVar14 = (ushort)(&DAT_c0908b10)[bVar1 >> 4 & 1] & *puVar14;
          puVar14 = puVar14 + 1;
          goto LAB_c08d7ce8;
        }
        if (uVar10 == 6) {
LAB_c08d7ca0:
          *puVar14 = (ushort)(&DAT_c0908b10)[bVar1 >> 5 & 1] & *puVar14;
          puVar14 = puVar14 + 1;
          goto LAB_c08d7cc4;
        }
        pbVar4 = pbVar13;
        if (uVar10 == 7) {
          *puVar12 = (ushort)(&DAT_c0908b10)[bVar1 >> 6 & 1] & *puVar12;
          puVar14 = puVar12 + 1;
          goto LAB_c08d7ca0;
        }
      }
      iVar9 = iVar2;
      if (0 < iVar2) {
        do {
          uVar6 = (uint)*pbVar4;
          puVar14[7] = (ushort)(&DAT_c0908b10)[uVar6 & 1] & puVar14[7];
          puVar14[6] = (ushort)(&DAT_c0908b10)[(int)uVar6 >> 1 & 1] & puVar14[6];
          puVar14[5] = (ushort)(&DAT_c0908b10)[(int)uVar6 >> 2 & 1] & puVar14[5];
          puVar14[4] = (ushort)(&DAT_c0908b10)[(int)uVar6 >> 3 & 1] & puVar14[4];
          puVar14[3] = (ushort)(&DAT_c0908b10)[(int)uVar6 >> 4 & 1] & puVar14[3];
          puVar14[2] = (ushort)(&DAT_c0908b10)[(int)uVar6 >> 5 & 1] & puVar14[2];
          puVar14[1] = (ushort)(&DAT_c0908b10)[(int)uVar6 >> 6 & 1] & puVar14[1];
          *puVar14 = (ushort)(&DAT_c0908b10)[(int)uVar6 >> 7] & *puVar14;
          puVar14 = puVar14 + 8;
          iVar9 = iVar9 + -1;
          pbVar4 = pbVar4 + 1;
        } while (iVar9 != 0);
      }
      if (uVar8 != 0) {
        bVar1 = *pbVar4;
        if (uVar8 != 1) {
          if (uVar8 != 2) {
            if (uVar8 != 3) {
              if (uVar8 != 4) {
                if (uVar8 != 5) {
                  if (uVar8 != 6) {
                    if (uVar8 != 7) goto LAB_c08d7fc0;
                    puVar14[6] = (ushort)(&DAT_c0908b10)[bVar1 >> 1 & 1] & puVar14[6];
                  }
                  puVar14[5] = (ushort)(&DAT_c0908b10)[bVar1 >> 2 & 1] & puVar14[5];
                }
                puVar14[4] = (ushort)(&DAT_c0908b10)[bVar1 >> 3 & 1] & puVar14[4];
              }
              puVar14[3] = (ushort)(&DAT_c0908b10)[bVar1 >> 4 & 1] & puVar14[3];
            }
            puVar14[2] = (ushort)(&DAT_c0908b10)[bVar1 >> 5 & 1] & puVar14[2];
          }
          puVar14[1] = (ushort)(&DAT_c0908b10)[bVar1 >> 6 & 1] & puVar14[1];
        }
        *puVar14 = (ushort)(&DAT_c0908b10)[bVar1 >> 7] & *puVar14;
      }
LAB_c08d7fc0:
      local_38 = local_38 + -1;
      pbVar13 = pbVar13 + iVar5;
      puVar12 = puVar12 + uVar3;
    } while (local_38 != 0);
  }
  return 0;
}



/* c08d800c FUN_c08d800c */

/* Boundary evidence: original MIPS .pdata c08d800c..c08d821b. Semantic name remains unreviewed. */

undefined4 FUN_c08d800c(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  int iVar14;
  int local_68 [16];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar13 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar4 = *(int **)(param_1 + 0x14);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  iVar2 = iVar2 >> 1;
  iVar5 = piVar4[2] - *piVar4;
  uVar6 = **(uint **)(param_1 + 0x18);
  iVar11 = piVar4[3] - piVar4[1];
  iVar14 = 0;
  iVar10 = 0;
  pbVar9 = (byte *)((*(uint **)(param_1 + 0x18))[1] * iVar13 + ((int)uVar6 >> 1) +
                   *(int *)(*(int *)(param_1 + 8) + 4));
  puVar12 = (ushort *)((piVar4[1] * iVar2 + *piVar4) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar4 = (int *)((int)local_68 + iVar10);
    iVar1 = *(int *)(param_1 + 0x3c);
    *piVar4 = iVar14;
    if (iVar1 != 0) {
      *piVar4 = *(int *)(iVar10 + iVar1);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar4);
      *piVar4 = iVar1;
    }
    iVar10 = iVar10 + 4;
    iVar14 = iVar14 + 1;
  } while (iVar10 < 0x40);
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar11 + -1) * iVar13;
    iVar13 = -iVar13;
    iVar14 = (iVar11 + -1) * iVar2;
    pbVar9 = pbVar9 + iVar10;
    iVar2 = -iVar2;
    puVar12 = puVar12 + iVar14;
  }
  if (0 < iVar11) {
    do {
      puVar7 = puVar12;
      uVar8 = uVar6 & 1;
      iVar10 = iVar5;
      if (0 < iVar5) {
        do {
          if (uVar8 == 0) {
            uVar3 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar3 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          *puVar7 = (ushort)local_68[uVar3] & *puVar7;
          iVar10 = iVar10 + -1;
          puVar7 = puVar7 + 1;
          uVar8 = (uint)(uVar8 == 0);
        } while (iVar10 != 0);
      }
      iVar11 = iVar11 + -1;
      puVar12 = puVar12 + iVar2;
      pbVar9 = pbVar9 + (iVar13 - (iVar5 >> 1));
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d821c FUN_c08d821c */

undefined4 FUN_c08d821c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  ushort *puVar9;
  ushort *puVar10;
  int iVar11;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar7 = *(int **)(param_1 + 0x14);
  if (iVar6 < 0) {
    iVar6 = iVar6 + 1;
  }
  iVar6 = iVar6 >> 1;
  iVar3 = piVar7[2] - *piVar7;
  iVar11 = piVar7[3] - piVar7[1];
  iVar2 = (*(int **)(param_1 + 0x18))[1] * iVar4 + *(int *)(*(int *)(param_1 + 8) + 4) +
          **(int **)(param_1 + 0x18);
  puVar10 = (ushort *)((piVar7[1] * iVar6 + *piVar7) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar8 = (iVar11 + -1) * iVar4;
    iVar4 = -iVar4;
    iVar1 = (iVar11 + -1) * iVar6;
    iVar2 = iVar8 + iVar2;
    iVar6 = -iVar6;
    puVar10 = puVar10 + iVar1;
  }
  if (0 < iVar11) {
    do {
      iVar8 = 0;
      puVar9 = puVar10;
      if (0 < iVar3) {
        do {
          pbVar5 = (byte *)(iVar8 + iVar2);
          iVar8 = iVar8 + 1;
          *puVar9 = (ushort)*(undefined4 *)((uint)*pbVar5 * 4 + *(int *)(param_1 + 0x3c)) & *puVar9;
          puVar9 = puVar9 + 1;
        } while (iVar8 < iVar3);
      }
      iVar11 = iVar11 + -1;
      puVar10 = puVar10 + iVar6;
      iVar2 = iVar2 + iVar4;
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d8338 FUN_c08d8338 */

/* Boundary evidence: original MIPS .pdata c08d8338..c08d84fb. Semantic name remains unreviewed. */

undefined4 FUN_c08d8338(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  ushort *puVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
  }
  iVar3 = iVar3 >> 1;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar11 = piVar5[2] - *piVar5;
  iVar8 = piVar5[3] - piVar5[1];
  iVar9 = ((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 2 +
          *(int *)(*(int *)(param_1 + 8) + 4);
  puVar7 = (ushort *)((piVar5[1] * iVar4 + *piVar5) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar8 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar8 + -1) * iVar4;
    iVar9 = iVar10 * 2 + iVar9;
    iVar4 = -iVar4;
    puVar7 = puVar7 + iVar1;
  }
  if (0 < iVar8) {
    do {
      if (0 < iVar11) {
        puVar6 = puVar7;
        iVar10 = iVar11;
        do {
          if (*(code **)(param_1 + 0x40) == (code *)0x0) {
            *puVar6 = *(ushort *)((iVar9 - (int)puVar7) + (int)puVar6) & *puVar6;
          }
          else {
            uVar2 = (**(code **)(param_1 + 0x40))
                              (*(undefined4 *)(param_1 + 0x44),
                               *(undefined2 *)((iVar9 - (int)puVar7) + (int)puVar6));
            *puVar6 = uVar2 & *puVar6;
          }
          iVar10 = iVar10 + -1;
          puVar6 = puVar6 + 1;
        } while (iVar10 != 0);
      }
      iVar8 = iVar8 + -1;
      puVar7 = puVar7 + iVar4;
      iVar9 = iVar3 * 2 + iVar9;
    } while (iVar8 != 0);
  }
  return 0;
}



/* c08d84fc FUN_c08d84fc */

/* Boundary evidence: original MIPS .pdata c08d84fc..c08d86a3. Semantic name remains unreviewed. */

undefined4 FUN_c08d84fc(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint3 *puVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  ushort *puVar10;
  int iVar11;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar9 = piVar5[2] - *piVar5;
  iVar7 = piVar5[3] - piVar5[1];
  puVar6 = (uint3 *)((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18) * 3 +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (ushort *)((piVar5[1] * iVar4 + *piVar5) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar7 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar7 + -1) * iVar4;
    puVar6 = (uint3 *)(iVar11 + (int)puVar6);
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar7) {
    do {
      puVar10 = puVar8;
      iVar11 = iVar9;
      if (0 < iVar9) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),(uint)*puVar6);
          *puVar10 = uVar2 & *puVar10;
          puVar6 = (uint3 *)((int)puVar6 + 3);
          iVar11 = iVar11 + -1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar7 = iVar7 + -1;
      puVar8 = puVar8 + iVar4;
      puVar6 = (uint3 *)((int)puVar6 + iVar3 + iVar9 * -3);
    } while (iVar7 != 0);
  }
  return 0;
}



/* c08d86a4 FUN_c08d86a4 */

/* Boundary evidence: original MIPS .pdata c08d86a4..c08d8843. Semantic name remains unreviewed. */

undefined4 FUN_c08d86a4(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  iVar3 = iVar3 >> 2;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar12 = piVar5[2] - *piVar5;
  iVar6 = piVar5[3] - piVar5[1];
  puVar7 = (undefined4 *)
           (((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 4 +
           *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (ushort *)((piVar5[1] * iVar4 + *piVar5) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar6 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar6 + -1) * iVar4;
    puVar7 = puVar7 + iVar11;
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar6) {
    do {
      puVar9 = puVar8;
      puVar10 = puVar7;
      iVar11 = iVar12;
      if (0 < iVar12) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*puVar10);
          *puVar9 = uVar2 & *puVar9;
          iVar11 = iVar11 + -1;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar6 = iVar6 + -1;
      puVar8 = puVar8 + iVar4;
      puVar7 = puVar7 + iVar3;
    } while (iVar6 != 0);
  }
  return 0;
}



/* c08d8844 FUN_c08d8844 */

/* Boundary evidence: original MIPS .pdata c08d8844..c08d8caf. Semantic name remains unreviewed. */

undefined4 FUN_c08d8844(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined2 *puVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  undefined2 *puVar14;
  byte *pbVar15;
  int iVar16;
  
  iVar16 = 0;
  piVar7 = *(int **)(param_1 + 0x14);
  uVar3 = *(uint *)(*(int *)(param_1 + 4) + 8) >> 1;
  iVar6 = piVar7[3] - piVar7[1];
  iVar9 = **(int **)(param_1 + 0x18);
  uVar11 = -iVar9 & 7;
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  uVar8 = (piVar7[2] - *piVar7) - uVar11;
  iVar2 = (int)uVar8 >> 3;
  uVar8 = uVar8 & 7;
  iVar12 = 0;
  pbVar13 = (byte *)((*(int **)(param_1 + 0x18))[1] * iVar4 + (iVar9 >> 3) +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar14 = (undefined2 *)((piVar7[1] * uVar3 + *piVar7) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar7 = (int *)((int)&DAT_c0908b18 + iVar12);
    *piVar7 = iVar16;
    if (*(int *)(param_1 + 0x3c) != 0) {
      *piVar7 = *(int *)(iVar12 + *(int *)(param_1 + 0x3c));
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar9 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar7);
      *piVar7 = iVar9;
    }
    iVar12 = iVar12 + 4;
    iVar16 = iVar16 + 1;
  } while (iVar12 < 8);
  if (0 < iVar6) {
    do {
      bVar1 = *pbVar13;
      puVar10 = puVar14;
      if (uVar11 == 1) {
LAB_c08d8a84:
        pbVar15 = pbVar13 + 1;
        *puVar10 = (short)(&DAT_c0908b18)[bVar1 & 1];
        puVar10 = puVar10 + 1;
      }
      else {
        if (uVar11 == 2) {
LAB_c08d8a68:
          *puVar10 = (short)(&DAT_c0908b18)[bVar1 >> 1 & 1];
          puVar10 = puVar10 + 1;
          goto LAB_c08d8a84;
        }
        if (uVar11 == 3) {
LAB_c08d8a4c:
          *puVar10 = (short)(&DAT_c0908b18)[bVar1 >> 2 & 1];
          puVar10 = puVar10 + 1;
          goto LAB_c08d8a68;
        }
        if (uVar11 == 4) {
LAB_c08d8a30:
          *puVar10 = (short)(&DAT_c0908b18)[bVar1 >> 3 & 1];
          puVar10 = puVar10 + 1;
          goto LAB_c08d8a4c;
        }
        if (uVar11 == 5) {
LAB_c08d8a14:
          *puVar10 = (short)(&DAT_c0908b18)[bVar1 >> 4 & 1];
          puVar10 = puVar10 + 1;
          goto LAB_c08d8a30;
        }
        if (uVar11 == 6) {
LAB_c08d89f8:
          *puVar10 = (short)(&DAT_c0908b18)[bVar1 >> 5 & 1];
          puVar10 = puVar10 + 1;
          goto LAB_c08d8a14;
        }
        pbVar15 = pbVar13;
        if (uVar11 == 7) {
          puVar10 = puVar14 + 1;
          *puVar14 = (short)(&DAT_c0908b18)[bVar1 >> 6 & 1];
          goto LAB_c08d89f8;
        }
      }
      iVar9 = iVar2;
      if (0 < iVar2) {
        do {
          uVar5 = (uint)*pbVar15;
          puVar10[7] = (short)(&DAT_c0908b18)[uVar5 & 1];
          puVar10[6] = (short)(&DAT_c0908b18)[(int)uVar5 >> 1 & 1];
          puVar10[5] = (short)(&DAT_c0908b18)[(int)uVar5 >> 2 & 1];
          puVar10[4] = (short)(&DAT_c0908b18)[(int)uVar5 >> 3 & 1];
          puVar10[3] = (short)(&DAT_c0908b18)[(int)uVar5 >> 4 & 1];
          puVar10[2] = (short)(&DAT_c0908b18)[(int)uVar5 >> 5 & 1];
          pbVar15 = pbVar15 + 1;
          puVar10[1] = (short)(&DAT_c0908b18)[(int)uVar5 >> 6 & 1];
          iVar9 = iVar9 + -1;
          *puVar10 = (short)(&DAT_c0908b18)[(int)uVar5 >> 7];
          puVar10 = puVar10 + 8;
        } while (iVar9 != 0);
      }
      if (uVar8 != 0) {
        bVar1 = *pbVar15;
        if (uVar8 != 1) {
          if (uVar8 != 2) {
            if (uVar8 != 3) {
              if (uVar8 != 4) {
                if (uVar8 != 5) {
                  if (uVar8 != 6) {
                    if (uVar8 != 7) goto LAB_c08d8c68;
                    puVar10[6] = (short)(&DAT_c0908b18)[bVar1 >> 1 & 1];
                  }
                  puVar10[5] = (short)(&DAT_c0908b18)[bVar1 >> 2 & 1];
                }
                puVar10[4] = (short)(&DAT_c0908b18)[bVar1 >> 3 & 1];
              }
              puVar10[3] = (short)(&DAT_c0908b18)[bVar1 >> 4 & 1];
            }
            puVar10[2] = (short)(&DAT_c0908b18)[bVar1 >> 5 & 1];
          }
          puVar10[1] = (short)(&DAT_c0908b18)[bVar1 >> 6 & 1];
        }
        *puVar10 = (short)(&DAT_c0908b18)[bVar1 >> 7];
      }
LAB_c08d8c68:
      iVar6 = iVar6 + -1;
      pbVar13 = pbVar13 + iVar4;
      puVar14 = puVar14 + uVar3;
    } while (iVar6 != 0);
  }
  return 0;
}



/* c08d8cb0 FUN_c08d8cb0 */

/* Boundary evidence: original MIPS .pdata c08d8cb0..c08d8eb7. Semantic name remains unreviewed. */

undefined4 FUN_c08d8cb0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  undefined2 *puVar12;
  int iVar13;
  int iVar14;
  int local_68 [16];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar13 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar4 = *(int **)(param_1 + 0x14);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  iVar2 = iVar2 >> 1;
  iVar5 = piVar4[2] - *piVar4;
  uVar6 = **(uint **)(param_1 + 0x18);
  iVar11 = piVar4[3] - piVar4[1];
  iVar14 = 0;
  iVar10 = 0;
  pbVar9 = (byte *)((*(uint **)(param_1 + 0x18))[1] * iVar13 + ((int)uVar6 >> 1) +
                   *(int *)(*(int *)(param_1 + 8) + 4));
  puVar12 = (undefined2 *)((piVar4[1] * iVar2 + *piVar4) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar4 = (int *)((int)local_68 + iVar10);
    iVar1 = *(int *)(param_1 + 0x3c);
    *piVar4 = iVar14;
    if (iVar1 != 0) {
      *piVar4 = *(int *)(iVar10 + iVar1);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar4);
      *piVar4 = iVar1;
    }
    iVar10 = iVar10 + 4;
    iVar14 = iVar14 + 1;
  } while (iVar10 < 0x40);
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar11 + -1) * iVar13;
    iVar13 = -iVar13;
    iVar14 = (iVar11 + -1) * iVar2;
    pbVar9 = pbVar9 + iVar10;
    iVar2 = -iVar2;
    puVar12 = puVar12 + iVar14;
  }
  if (0 < iVar11) {
    do {
      uVar7 = uVar6 & 1;
      puVar8 = puVar12;
      iVar10 = iVar5;
      if (0 < iVar5) {
        do {
          if (uVar7 == 0) {
            uVar3 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar3 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          *puVar8 = (short)local_68[uVar3];
          iVar10 = iVar10 + -1;
          uVar7 = (uint)(uVar7 == 0);
          puVar8 = puVar8 + 1;
        } while (iVar10 != 0);
      }
      iVar11 = iVar11 + -1;
      puVar12 = puVar12 + iVar2;
      pbVar9 = pbVar9 + (iVar13 - (iVar5 >> 1));
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d8eb8 FUN_c08d8eb8 */

/* Boundary evidence: original MIPS .pdata c08d8eb8..c08d908f. Semantic name remains unreviewed. */

undefined4 FUN_c08d8eb8(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined2 *_Dst;
  void *_Src;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
  }
  iVar3 = iVar3 >> 1;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar9 = piVar5[2] - *piVar5;
  iVar6 = piVar5[3] - piVar5[1];
  _Src = (void *)(((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 2 +
                 *(int *)(*(int *)(param_1 + 8) + 4));
  _Dst = (undefined2 *)((piVar5[1] * iVar4 + *piVar5) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar8 = (iVar6 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar6 + -1) * iVar4;
    _Src = (void *)(iVar8 * 2 + (int)_Src);
    iVar4 = -iVar4;
    _Dst = _Dst + iVar1;
  }
  if (0 < iVar6) {
    if (*(int *)(param_1 + 0x40) == 0) {
      do {
        memcpy(_Dst,_Src,iVar9 * 2);
        iVar6 = iVar6 + -1;
        _Dst = _Dst + iVar4;
        _Src = (void *)(iVar3 * 2 + (int)_Src);
      } while (iVar6 != 0);
    }
    else {
      do {
        if (0 < iVar9) {
          puVar7 = _Dst;
          iVar8 = iVar9;
          do {
            uVar2 = (**(code **)(param_1 + 0x40))
                              (*(undefined4 *)(param_1 + 0x44),
                               *(undefined2 *)(((int)_Src - (int)_Dst) + (int)puVar7));
            iVar8 = iVar8 + -1;
            *puVar7 = uVar2;
            puVar7 = puVar7 + 1;
          } while (iVar8 != 0);
        }
        iVar6 = iVar6 + -1;
        _Dst = _Dst + iVar4;
        _Src = (void *)(iVar3 * 2 + (int)_Src);
      } while (iVar6 != 0);
    }
  }
  return 0;
}



/* c08d9090 FUN_c08d9090 */

/* Boundary evidence: original MIPS .pdata c08d9090..c08d922f. Semantic name remains unreviewed. */

undefined4 FUN_c08d9090(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint3 *puVar6;
  int iVar7;
  undefined2 *puVar8;
  int iVar9;
  undefined2 *puVar10;
  int iVar11;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar9 = piVar5[2] - *piVar5;
  iVar7 = piVar5[3] - piVar5[1];
  puVar6 = (uint3 *)((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18) * 3 +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (undefined2 *)((piVar5[1] * iVar4 + *piVar5) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar7 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar7 + -1) * iVar4;
    puVar6 = (uint3 *)(iVar11 + (int)puVar6);
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar7) {
    do {
      puVar10 = puVar8;
      iVar11 = iVar9;
      if (0 < iVar9) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),(uint)*puVar6);
          puVar6 = (uint3 *)((int)puVar6 + 3);
          iVar11 = iVar11 + -1;
          *puVar10 = uVar2;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar7 = iVar7 + -1;
      puVar8 = puVar8 + iVar4;
      puVar6 = (uint3 *)((int)puVar6 + iVar3 + iVar9 * -3);
    } while (iVar7 != 0);
  }
  return 0;
}



/* c08d9230 FUN_c08d9230 */

undefined4 FUN_c08d9230(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  int iVar10;
  
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  iVar4 = iVar4 >> 2;
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar6 = *(int **)(param_1 + 0x14);
  if (iVar5 < 0) {
    iVar5 = iVar5 + 1;
  }
  iVar5 = iVar5 >> 1;
  iVar3 = piVar6[2] - *piVar6;
  iVar10 = piVar6[3] - piVar6[1];
  piVar2 = (int *)(((*(int **)(param_1 + 0x18))[1] * iVar4 + **(int **)(param_1 + 0x18)) * 4 +
                  *(int *)(*(int *)(param_1 + 8) + 4));
  puVar9 = (ushort *)((piVar6[1] * iVar5 + *piVar6) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar1 = (iVar10 + -1) * iVar4;
    iVar4 = -iVar4;
    iVar7 = (iVar10 + -1) * iVar5;
    piVar2 = piVar2 + iVar1;
    iVar5 = -iVar5;
    puVar9 = puVar9 + iVar7;
  }
  if (0 < iVar10) {
    do {
      iVar1 = iVar3;
      puVar8 = puVar9;
      piVar6 = piVar2;
      if (0 < iVar3) {
        do {
          iVar7 = *piVar6;
          *puVar8 = (ushort)((uint)iVar7 >> 8) & 0xf800 | (ushort)(iVar7 >> 5) & 0x7e0 |
                    (ushort)(iVar7 >> 3) & 0x1f;
          iVar1 = iVar1 + -1;
          puVar8 = puVar8 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar1 != 0);
      }
      iVar10 = iVar10 + -1;
      puVar9 = puVar9 + iVar5;
      piVar2 = piVar2 + iVar4;
    } while (iVar10 != 0);
  }
  return 0;
}



/* c08d9374 FUN_c08d9374 */

/* Boundary evidence: original MIPS .pdata c08d9374..c08d9897. Semantic name remains unreviewed. */

undefined4 FUN_c08d9374(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  ushort *puVar11;
  byte *pbVar12;
  ushort *puVar13;
  byte *pbVar14;
  int iVar15;
  int local_38;
  
  iVar15 = 0;
  piVar6 = *(int **)(param_1 + 0x14);
  uVar3 = *(uint *)(*(int *)(param_1 + 4) + 8) >> 1;
  local_38 = piVar6[3] - piVar6[1];
  iVar8 = **(int **)(param_1 + 0x18);
  uVar9 = -iVar8 & 7;
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  uVar7 = (piVar6[2] - *piVar6) - uVar9;
  iVar2 = (int)uVar7 >> 3;
  uVar7 = uVar7 & 7;
  iVar10 = 0;
  pbVar12 = (byte *)((*(int **)(param_1 + 0x18))[1] * iVar4 + (iVar8 >> 3) +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar11 = (ushort *)((piVar6[1] * uVar3 + *piVar6) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar6 = (int *)((int)&DAT_c0908b20 + iVar10);
    *piVar6 = iVar15;
    if (*(int *)(param_1 + 0x3c) != 0) {
      *piVar6 = *(int *)(*(int *)(param_1 + 0x3c) + iVar10);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar8 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar6);
      *piVar6 = iVar8;
    }
    iVar10 = iVar10 + 4;
    iVar15 = iVar15 + 1;
  } while (iVar10 < 8);
  if (0 < local_38) {
    do {
      bVar1 = *pbVar12;
      puVar13 = puVar11;
      if (uVar9 == 1) {
LAB_c08d95e4:
        *puVar13 = (ushort)(&DAT_c0908b20)[bVar1 & 1] | *puVar13;
        puVar13 = puVar13 + 1;
        pbVar14 = pbVar12 + 1;
      }
      else {
        if (uVar9 == 2) {
LAB_c08d95c0:
          *puVar13 = (ushort)(&DAT_c0908b20)[bVar1 >> 1 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d95e4;
        }
        if (uVar9 == 3) {
LAB_c08d959c:
          *puVar13 = (ushort)(&DAT_c0908b20)[bVar1 >> 2 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d95c0;
        }
        if (uVar9 == 4) {
LAB_c08d9578:
          *puVar13 = (ushort)(&DAT_c0908b20)[bVar1 >> 3 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d959c;
        }
        if (uVar9 == 5) {
LAB_c08d9554:
          *puVar13 = (ushort)(&DAT_c0908b20)[bVar1 >> 4 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d9578;
        }
        if (uVar9 == 6) {
LAB_c08d9530:
          *puVar13 = (ushort)(&DAT_c0908b20)[bVar1 >> 5 & 1] | *puVar13;
          puVar13 = puVar13 + 1;
          goto LAB_c08d9554;
        }
        pbVar14 = pbVar12;
        if (uVar9 == 7) {
          *puVar11 = (ushort)(&DAT_c0908b20)[bVar1 >> 6 & 1] | *puVar11;
          puVar13 = puVar11 + 1;
          goto LAB_c08d9530;
        }
      }
      iVar8 = iVar2;
      if (0 < iVar2) {
        do {
          uVar5 = (uint)*pbVar14;
          puVar13[7] = (ushort)(&DAT_c0908b20)[uVar5 & 1] | puVar13[7];
          puVar13[6] = (ushort)(&DAT_c0908b20)[(int)uVar5 >> 1 & 1] | puVar13[6];
          puVar13[5] = (ushort)(&DAT_c0908b20)[(int)uVar5 >> 2 & 1] | puVar13[5];
          puVar13[4] = (ushort)(&DAT_c0908b20)[(int)uVar5 >> 3 & 1] | puVar13[4];
          puVar13[3] = (ushort)(&DAT_c0908b20)[(int)uVar5 >> 4 & 1] | puVar13[3];
          puVar13[2] = (ushort)(&DAT_c0908b20)[(int)uVar5 >> 5 & 1] | puVar13[2];
          puVar13[1] = (ushort)(&DAT_c0908b20)[(int)uVar5 >> 6 & 1] | puVar13[1];
          *puVar13 = (ushort)(&DAT_c0908b20)[(int)uVar5 >> 7] | *puVar13;
          puVar13 = puVar13 + 8;
          iVar8 = iVar8 + -1;
          pbVar14 = pbVar14 + 1;
        } while (iVar8 != 0);
      }
      if (uVar7 != 0) {
        bVar1 = *pbVar14;
        if (uVar7 != 1) {
          if (uVar7 != 2) {
            if (uVar7 != 3) {
              if (uVar7 != 4) {
                if (uVar7 != 5) {
                  if (uVar7 != 6) {
                    if (uVar7 != 7) goto LAB_c08d984c;
                    puVar13[6] = (ushort)(&DAT_c0908b20)[bVar1 >> 1 & 1] | puVar13[6];
                  }
                  puVar13[5] = (ushort)(&DAT_c0908b20)[bVar1 >> 2 & 1] | puVar13[5];
                }
                puVar13[4] = (ushort)(&DAT_c0908b20)[bVar1 >> 3 & 1] | puVar13[4];
              }
              puVar13[3] = (ushort)(&DAT_c0908b20)[bVar1 >> 4 & 1] | puVar13[3];
            }
            puVar13[2] = (ushort)(&DAT_c0908b20)[bVar1 >> 5 & 1] | puVar13[2];
          }
          puVar13[1] = (ushort)(&DAT_c0908b20)[bVar1 >> 6 & 1] | puVar13[1];
        }
        *puVar13 = (ushort)(&DAT_c0908b20)[bVar1 >> 7] | *puVar13;
      }
LAB_c08d984c:
      local_38 = local_38 + -1;
      pbVar12 = pbVar12 + iVar4;
      puVar11 = puVar11 + uVar3;
    } while (local_38 != 0);
  }
  return 0;
}



/* c08d9898 FUN_c08d9898 */

/* Boundary evidence: original MIPS .pdata c08d9898..c08d9aa7. Semantic name remains unreviewed. */

undefined4 FUN_c08d9898(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  int iVar14;
  int local_68 [16];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar13 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar4 = *(int **)(param_1 + 0x14);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  iVar2 = iVar2 >> 1;
  iVar5 = piVar4[2] - *piVar4;
  uVar6 = **(uint **)(param_1 + 0x18);
  iVar11 = piVar4[3] - piVar4[1];
  iVar14 = 0;
  iVar10 = 0;
  pbVar9 = (byte *)((*(uint **)(param_1 + 0x18))[1] * iVar13 + ((int)uVar6 >> 1) +
                   *(int *)(*(int *)(param_1 + 8) + 4));
  puVar12 = (ushort *)((piVar4[1] * iVar2 + *piVar4) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  do {
    piVar4 = (int *)((int)local_68 + iVar10);
    iVar1 = *(int *)(param_1 + 0x3c);
    *piVar4 = iVar14;
    if (iVar1 != 0) {
      *piVar4 = *(int *)(iVar10 + iVar1);
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*piVar4);
      *piVar4 = iVar1;
    }
    iVar10 = iVar10 + 4;
    iVar14 = iVar14 + 1;
  } while (iVar10 < 0x40);
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar10 = (iVar11 + -1) * iVar13;
    iVar13 = -iVar13;
    iVar14 = (iVar11 + -1) * iVar2;
    pbVar9 = pbVar9 + iVar10;
    iVar2 = -iVar2;
    puVar12 = puVar12 + iVar14;
  }
  if (0 < iVar11) {
    do {
      puVar7 = puVar12;
      uVar8 = uVar6 & 1;
      iVar10 = iVar5;
      if (0 < iVar5) {
        do {
          if (uVar8 == 0) {
            uVar3 = (uint)(*pbVar9 >> 4);
          }
          else {
            uVar3 = *pbVar9 & 0xf;
            pbVar9 = pbVar9 + 1;
          }
          *puVar7 = (ushort)local_68[uVar3] | *puVar7;
          iVar10 = iVar10 + -1;
          puVar7 = puVar7 + 1;
          uVar8 = (uint)(uVar8 == 0);
        } while (iVar10 != 0);
      }
      iVar11 = iVar11 + -1;
      puVar12 = puVar12 + iVar2;
      pbVar9 = pbVar9 + (iVar13 - (iVar5 >> 1));
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d9aa8 FUN_c08d9aa8 */

undefined4 FUN_c08d9aa8(int param_1)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  ushort *puVar10;
  int iVar11;
  
  iVar7 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar8 = *(int **)(param_1 + 0x14);
  if (iVar7 < 0) {
    iVar7 = iVar7 + 1;
  }
  iVar7 = iVar7 >> 1;
  iVar4 = piVar8[2] - *piVar8;
  iVar11 = piVar8[3] - piVar8[1];
  iVar3 = (*(int **)(param_1 + 0x18))[1] * iVar5 + *(int *)(*(int *)(param_1 + 8) + 4) +
          **(int **)(param_1 + 0x18);
  puVar10 = (ushort *)((piVar8[1] * iVar7 + *piVar8) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar9 = (iVar11 + -1) * iVar5;
    iVar5 = -iVar5;
    iVar1 = (iVar11 + -1) * iVar7;
    iVar3 = iVar9 + iVar3;
    iVar7 = -iVar7;
    puVar10 = puVar10 + iVar1;
  }
  if (0 < iVar11) {
    do {
      iVar9 = 0;
      puVar2 = puVar10;
      if (0 < iVar4) {
        do {
          pbVar6 = (byte *)(iVar9 + iVar3);
          iVar9 = iVar9 + 1;
          *puVar2 = (ushort)*(undefined4 *)((uint)*pbVar6 * 4 + *(int *)(param_1 + 0x3c)) | *puVar2;
          puVar2 = puVar2 + 1;
        } while (iVar9 < iVar4);
      }
      iVar11 = iVar11 + -1;
      puVar10 = puVar10 + iVar7;
      iVar3 = iVar3 + iVar5;
    } while (iVar11 != 0);
  }
  return 0;
}



/* c08d9bc4 FUN_c08d9bc4 */

/* Boundary evidence: original MIPS .pdata c08d9bc4..c08d9d7f. Semantic name remains unreviewed. */

undefined4 FUN_c08d9bc4(int param_1)

{
  int iVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  ushort *puVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar6 = *(int **)(param_1 + 0x14);
  if (iVar5 < 0) {
    iVar5 = iVar5 + 1;
  }
  iVar5 = iVar5 >> 1;
  iVar12 = piVar6[2] - *piVar6;
  iVar9 = piVar6[3] - piVar6[1];
  iVar10 = ((*(int **)(param_1 + 0x18))[1] * iVar4 + **(int **)(param_1 + 0x18)) * 2 +
           *(int *)(*(int *)(param_1 + 8) + 4);
  puVar8 = (ushort *)((piVar6[1] * iVar5 + *piVar6) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar9 + -1) * iVar4;
    iVar4 = -iVar4;
    iVar1 = (iVar9 + -1) * iVar5;
    iVar10 = iVar11 * 2 + iVar10;
    iVar5 = -iVar5;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar9) {
    do {
      if (0 < iVar12) {
        puVar7 = puVar8;
        iVar11 = iVar12;
        do {
          puVar3 = (ushort *)((iVar10 - (int)puVar8) + (int)puVar7);
          if (*(code **)(param_1 + 0x40) == (code *)0x0) {
            *puVar7 = *puVar3 | *puVar7;
          }
          else {
            uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*puVar3);
            *puVar7 = uVar2 | *puVar7;
          }
          iVar11 = iVar11 + -1;
          puVar7 = puVar7 + 1;
        } while (iVar11 != 0);
      }
      iVar9 = iVar9 + -1;
      puVar8 = puVar8 + iVar5;
      iVar10 = iVar4 * 2 + iVar10;
    } while (iVar9 != 0);
  }
  return 0;
}



/* c08d9d80 FUN_c08d9d80 */

/* Boundary evidence: original MIPS .pdata c08d9d80..c08d9f27. Semantic name remains unreviewed. */

undefined4 FUN_c08d9d80(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint3 *puVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  ushort *puVar10;
  int iVar11;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar9 = piVar5[2] - *piVar5;
  iVar7 = piVar5[3] - piVar5[1];
  puVar6 = (uint3 *)((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18) * 3 +
                    *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (ushort *)((piVar5[1] * iVar4 + *piVar5) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar7 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar7 + -1) * iVar4;
    puVar6 = (uint3 *)(iVar11 + (int)puVar6);
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar7) {
    do {
      puVar10 = puVar8;
      iVar11 = iVar9;
      if (0 < iVar9) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),(uint)*puVar6);
          *puVar10 = uVar2 | *puVar10;
          puVar6 = (uint3 *)((int)puVar6 + 3);
          iVar11 = iVar11 + -1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar7 = iVar7 + -1;
      puVar8 = puVar8 + iVar4;
      puVar6 = (uint3 *)((int)puVar6 + iVar3 + iVar9 * -3);
    } while (iVar7 != 0);
  }
  return 0;
}



/* c08d9f28 FUN_c08d9f28 */

/* Boundary evidence: original MIPS .pdata c08d9f28..c08da0c7. Semantic name remains unreviewed. */

undefined4 FUN_c08d9f28(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  iVar3 = iVar3 >> 2;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  piVar5 = *(int **)(param_1 + 0x14);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = iVar4 >> 1;
  iVar12 = piVar5[2] - *piVar5;
  iVar6 = piVar5[3] - piVar5[1];
  puVar7 = (undefined4 *)
           (((*(int **)(param_1 + 0x18))[1] * iVar3 + **(int **)(param_1 + 0x18)) * 4 +
           *(int *)(*(int *)(param_1 + 8) + 4));
  puVar8 = (ushort *)((piVar5[1] * iVar4 + *piVar5) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar11 = (iVar6 + -1) * iVar3;
    iVar3 = -iVar3;
    iVar1 = (iVar6 + -1) * iVar4;
    puVar7 = puVar7 + iVar11;
    iVar4 = -iVar4;
    puVar8 = puVar8 + iVar1;
  }
  if (0 < iVar6) {
    do {
      puVar9 = puVar8;
      puVar10 = puVar7;
      iVar11 = iVar12;
      if (0 < iVar12) {
        do {
          uVar2 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),*puVar10);
          *puVar9 = uVar2 | *puVar9;
          iVar11 = iVar11 + -1;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      iVar6 = iVar6 + -1;
      puVar8 = puVar8 + iVar4;
      puVar7 = puVar7 + iVar3;
    } while (iVar6 != 0);
  }
  return 0;
}



/* c08da0c8 FUN_c08da0c8 */

/* Boundary evidence: original MIPS .pdata c08da0c8..c08da4db. Semantic name remains unreviewed. */

undefined4 FUN_c08da0c8(int param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined2 *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  int *piVar18;
  int iVar19;
  int iVar20;
  byte *pbVar21;
  undefined2 *puVar22;
  int *piVar23;
  byte *pbVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  
  iVar14 = *(int *)(*(int *)(param_1 + 4) + 4);
  iVar15 = *(int *)(*(int *)(param_1 + 4) + 8);
  if (iVar15 < 0) {
    iVar15 = iVar15 + 1;
  }
  piVar23 = *(int **)(param_1 + 0x14);
  iVar29 = *piVar23;
  piVar18 = *(int **)(param_1 + 0x18);
  iVar9 = piVar23[2] - iVar29;
  iVar30 = piVar23[1];
  iVar26 = *(int *)(*(int *)(param_1 + 8) + 8);
  iVar16 = piVar18[2] - *piVar18;
  iVar31 = piVar23[3] - iVar30;
  bVar3 = false;
  iVar20 = piVar18[3] - piVar18[1];
  bVar1 = false;
  bVar2 = false;
  iVar32 = 0;
  iVar12 = 0;
  iVar27 = 0;
  bVar5 = false;
  bVar4 = false;
  bVar6 = false;
  bVar7 = false;
  if (iVar16 < iVar9) {
    bVar4 = true;
    iVar8 = iVar9;
    iVar25 = iVar16;
LAB_c08da1c4:
    bVar5 = true;
    iVar25 = iVar25 * 2;
    iVar28 = iVar25 + iVar8 * -2;
    if (bVar1) {
      iVar8 = iVar9 * 2 - iVar16;
    }
    else {
      iVar8 = iVar16 * 3 + iVar9 * -2;
    }
  }
  else {
    iVar8 = iVar14;
    iVar25 = iVar14;
    iVar28 = iVar14;
    if (iVar9 < iVar16) {
      bVar1 = true;
      iVar8 = iVar16;
      iVar25 = iVar9;
      goto LAB_c08da1c4;
    }
  }
  if (iVar20 < iVar31) {
    bVar2 = true;
    iVar16 = iVar31;
    iVar11 = iVar20;
  }
  else {
    iVar10 = iVar14;
    iVar11 = iVar14;
    iVar16 = iVar14;
    if (iVar20 <= iVar31) goto LAB_c08da288;
    bVar3 = true;
    bVar7 = true;
    iVar16 = iVar20;
    iVar11 = iVar31;
  }
  bVar6 = true;
  iVar11 = iVar11 * 2;
  iVar10 = iVar11 + iVar16 * -2;
  if (bVar3) {
    iVar16 = iVar31 * 2 - iVar20;
  }
  else {
    iVar16 = iVar20 * 3 + iVar31 * -2;
  }
LAB_c08da288:
  piVar17 = *(int **)(param_1 + 0x1c);
  if (piVar17 != (int *)0x0) {
    iVar20 = *piVar23;
    if (*piVar23 < *piVar17) {
      iVar20 = *piVar17;
    }
    iVar19 = piVar23[1];
    if (piVar23[1] < piVar17[1]) {
      iVar19 = piVar17[1];
    }
    iVar31 = piVar23[3];
    if (piVar17[3] < piVar23[3]) {
      iVar31 = piVar17[3];
    }
    iVar9 = piVar23[2];
    if (piVar17[2] < piVar23[2]) {
      iVar9 = piVar17[2];
    }
    if (iVar9 <= iVar20) {
      return 0;
    }
    if (iVar31 <= iVar19) {
      return 0;
    }
    iVar32 = iVar20 - iVar29;
    iVar12 = iVar19 - iVar30;
    iVar9 = iVar9 - iVar20;
    iVar31 = iVar31 - iVar19;
  }
  if (bVar4) {
    for (; iVar32 != 0; iVar32 = iVar32 + -1) {
      iVar20 = iVar28;
      if (iVar8 < 0) {
        iVar20 = iVar25;
      }
      iVar8 = iVar8 + iVar20;
    }
  }
  iVar32 = iVar12;
  if (bVar2) {
    for (; iVar32 != 0; iVar32 = iVar32 + -1) {
      iVar20 = iVar11;
      if (-1 < iVar16) {
        iVar27 = iVar27 + 1;
        iVar20 = iVar10;
      }
      iVar16 = iVar16 + iVar20;
    }
  }
  pbVar24 = (byte *)((piVar18[1] + iVar27) * iVar26 + *piVar18 + *(int *)(*(int *)(param_1 + 8) + 4)
                    );
  puVar13 = (undefined2 *)(((iVar30 + iVar12) * (iVar15 >> 1) + iVar29) * 2 + iVar14);
  if (0 < iVar31) {
    do {
      iVar14 = iVar8;
      pbVar21 = pbVar24;
      puVar22 = puVar13;
      iVar32 = iVar9;
      if (0 < iVar9) {
        do {
          if (bVar5) {
            if (!bVar4) {
              for (; iVar14 < 0; iVar14 = iVar14 + iVar25) {
              }
              iVar14 = iVar14 + iVar28;
              goto LAB_c08da43c;
            }
            *puVar22 = (short)*(undefined4 *)((uint)*pbVar21 * 4 + *(int *)(param_1 + 0x3c));
            if (-1 < iVar14) {
              iVar14 = iVar14 + iVar28;
              goto LAB_c08da454;
            }
            iVar14 = iVar14 + iVar25;
          }
          else {
LAB_c08da43c:
            *puVar22 = (short)*(undefined4 *)((uint)*pbVar21 * 4 + *(int *)(param_1 + 0x3c));
LAB_c08da454:
            pbVar21 = pbVar21 + 1;
          }
          iVar32 = iVar32 + -1;
          puVar22 = puVar22 + 1;
        } while (iVar32 != 0);
      }
      if (bVar6) {
        if (-1 < iVar16) {
LAB_c08da48c:
          iVar16 = iVar16 + iVar10;
          goto LAB_c08da490;
        }
        if (bVar7) {
          do {
            iVar16 = iVar16 + iVar11;
            pbVar24 = pbVar24 + iVar26;
          } while (iVar16 < 0);
          goto LAB_c08da48c;
        }
        iVar16 = iVar16 + iVar11;
      }
      else {
LAB_c08da490:
        pbVar24 = pbVar24 + iVar26;
      }
      iVar31 = iVar31 + -1;
      puVar13 = puVar13 + (iVar15 >> 1);
    } while (iVar31 != 0);
  }
  return 0;
}



/* c08da4dc FUN_c08da4dc */

/* Boundary evidence: original MIPS .pdata c08da4dc..c08da697. Semantic name remains unreviewed. */

undefined4 FUN_c08da4dc(int param_1)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  ushort *puVar11;
  int iVar12;
  int iVar13;
  
  if ((*(uint *)(param_1 + 0x24) & 8) == 0) {
    iVar5 = *(int *)(*(int *)(param_1 + 4) + 8);
    iVar12 = *(int *)(*(int *)(param_1 + 8) + 8);
    piVar6 = *(int **)(param_1 + 0x14);
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar5 >> 1;
    iVar13 = piVar6[2] - *piVar6;
    iVar10 = piVar6[3] - piVar6[1];
    iVar8 = (*(int **)(param_1 + 0x18))[1] * iVar12 + *(int *)(*(int *)(param_1 + 8) + 4) +
            **(int **)(param_1 + 0x18);
    puVar11 = (ushort *)((piVar6[1] * iVar5 + *piVar6) * 2 + *(int *)(*(int *)(param_1 + 4) + 4));
    if (*(int *)(param_1 + 0x38) == 0) {
      iVar7 = (iVar10 + -1) * iVar12;
      iVar12 = -iVar12;
      iVar2 = (iVar10 + -1) * iVar5;
      iVar8 = iVar7 + iVar8;
      iVar5 = -iVar5;
      puVar11 = puVar11 + iVar2;
    }
    if (0 < iVar10) {
      do {
        iVar7 = 0;
        puVar9 = puVar11;
        if (0 < iVar13) {
          do {
            bVar1 = *(byte *)(iVar7 + iVar8);
            if (*(code **)(param_1 + 0x40) == (code *)0x0) {
              if (*(int *)(param_1 + 0x3c) == 0) {
                *puVar9 = (ushort)bVar1;
              }
              else {
                *puVar9 = (ushort)*(undefined4 *)((uint)bVar1 * 4 + *(int *)(param_1 + 0x3c));
              }
            }
            else {
              uVar3 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),(uint)bVar1);
              *puVar9 = uVar3;
            }
            iVar7 = iVar7 + 1;
            puVar9 = puVar9 + 1;
          } while (iVar7 < iVar13);
        }
        iVar10 = iVar10 + -1;
        puVar11 = puVar11 + iVar5;
        iVar8 = iVar8 + iVar12;
      } while (iVar10 != 0);
    }
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_c08da0c8(param_1);
  }
  return uVar4;
}



/* c08da698 FUN_c08da698 */

/* Boundary evidence: original MIPS .pdata c08da698..c08dab67. Semantic name remains unreviewed. */

void FUN_c08da698(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_2[10];
  if (iVar1 == 0x6666) {
    iVar1 = *(int *)(param_2[2] + 0x1c);
    if (iVar1 == 0) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d6d90((int)param_2);
        return;
      }
    }
    else if (iVar1 == 2) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d72b4((int)param_2);
        return;
      }
    }
    else if (iVar1 == 3) {
      if (param_2[0xf] != 0) {
        FUN_c08d74c4((int)param_2);
        return;
      }
    }
    else if (iVar1 == 4) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d75e0((int)param_2);
        return;
      }
    }
    else if (iVar1 == 5) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d779c((int)param_2);
        return;
      }
    }
    else if ((iVar1 == 6) && ((param_2[9] & 8U) == 0)) {
      FUN_c08d7944((int)param_2);
      return;
    }
  }
  else if (iVar1 == 0x8888) {
    iVar1 = *(int *)(param_2[2] + 0x1c);
    if (iVar1 == 0) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d7ae4((int)param_2);
        return;
      }
    }
    else if (iVar1 == 2) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d800c((int)param_2);
        return;
      }
    }
    else if (iVar1 == 3) {
      if (param_2[0xf] != 0) {
        FUN_c08d821c((int)param_2);
        return;
      }
    }
    else if (iVar1 == 4) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d8338((int)param_2);
        return;
      }
    }
    else if (iVar1 == 5) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d84fc((int)param_2);
        return;
      }
    }
    else if ((iVar1 == 6) && ((param_2[9] & 8U) == 0)) {
      FUN_c08d86a4((int)param_2);
      return;
    }
  }
  else if (iVar1 == 0xcccc) {
    iVar1 = *(int *)(param_2[2] + 0x1c);
    if (iVar1 == 0) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d8844((int)param_2);
        return;
      }
    }
    else if (iVar1 == 2) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d8cb0((int)param_2);
        return;
      }
    }
    else if (iVar1 == 3) {
      if (param_2[0xf] != 0) {
        FUN_c08da4dc((int)param_2);
        return;
      }
    }
    else if (iVar1 == 4) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d8eb8((int)param_2);
        return;
      }
    }
    else if (iVar1 == 5) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d9090((int)param_2);
        return;
      }
    }
    else if ((iVar1 == 6) && ((param_2[9] & 8U) == 0)) {
      FUN_c08d9230((int)param_2);
      return;
    }
  }
  else if (iVar1 == 0xeeee) {
    iVar1 = *(int *)(param_2[2] + 0x1c);
    if (iVar1 == 0) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d9374((int)param_2);
        return;
      }
    }
    else if (iVar1 == 2) {
      if ((param_2[0xf] != 0) && ((param_2[9] & 8U) == 0)) {
        FUN_c08d9898((int)param_2);
        return;
      }
    }
    else if (iVar1 == 3) {
      if (param_2[0xf] != 0) {
        FUN_c08d9aa8((int)param_2);
        return;
      }
    }
    else if (iVar1 == 4) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d9bc4((int)param_2);
        return;
      }
    }
    else if (iVar1 == 5) {
      if ((param_2[9] & 8U) == 0) {
        FUN_c08d9d80((int)param_2);
        return;
      }
    }
    else if ((iVar1 == 6) && ((param_2[9] & 8U) == 0)) {
      FUN_c08d9f28((int)param_2);
      return;
    }
  }
  FUN_c08ea8b8(param_1,param_2);
  return;
}



/* c08dab68 FUN_c08dab68 */

void FUN_c08dab68(int param_1)

{
  *(undefined1 **)(param_1 + 0x6a1c) = &LAB_c08d6bb4;
  *(undefined1 **)(param_1 + 0x6a18) = &LAB_c08d6cfc;
  *(undefined1 **)(param_1 + 0x6a20) = &LAB_c08d6c5c;
  *(code **)(param_1 + 0x6a2c) = FUN_c08da698;
  *(code **)(param_1 + 0x6a24) = FUN_c08da698;
  *(code **)(param_1 + 0x6a28) = FUN_c08da698;
  *(code **)(param_1 + 0x6a30) = FUN_c08da698;
  return;
}



/* c08daba8 DrvEnableDriver */

/* Boundary evidence: original MIPS .pdata c08daba8..c08dabc3. Semantic name remains unreviewed. */

void DrvEnableDriver(int param_1,size_t param_2,void *param_3,undefined4 *param_4)

{
                    /* 0xaba8  1  DrvEnableDriver */
  FUN_c08e3068(param_1,param_2,param_3,param_4);
  return;
}



/* c08dabc4 FUN_c08dabc4 */

/* Boundary evidence: original MIPS .pdata c08dabc4..c08dac77. Semantic name remains unreviewed. */

undefined4 FUN_c08dabc4(wchar_t *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  
  iVar1 = swscanf(param_1,L"{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",param_2,param_2 + 4
                  ,param_2 + 6,&local_28,auStack_24,auStack_20,auStack_1c,auStack_18,auStack_14,
                  auStack_10,auStack_c);
  if (iVar1 == 0xb) {
    uVar3 = 0;
    puVar4 = &local_28;
    do {
      puVar2 = (undefined1 *)(param_2 + 8 + uVar3);
      uVar3 = uVar3 + 1;
      *puVar2 = (char)*puVar4;
      puVar4 = puVar4 + 1;
    } while (uVar3 < 8);
  }
  return 1;
}



/* c08dac78 FUN_c08dac78 */

/* Boundary evidence: original MIPS .pdata c08dac78..c08dad0b. Semantic name remains unreviewed. */

undefined4 FUN_c08dac78(HMODULE param_1)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  undefined1 auStack_230 [16];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c0906fb8;
  iVar1 = FUN_c08dabc4(L"{EB91C7C9-8BF6-4a2d-9AB8-69724EED97D1}",(int)auStack_230);
  uVar3 = 0;
  if ((iVar1 != 0) && (DVar2 = GetModuleFileNameW(param_1,aWStack_220,0x104), uVar3 = 0, DVar2 != 0)
     ) {
    uVar3 = AdvertiseInterface(auStack_230,aWStack_220,1);
  }
  FUN_c08f26d4(local_18);
  return uVar3;
}



/* c08dad0c FUN_c08dad0c */

void FUN_c08dad0c(int param_1)

{
  if ((*(uint *)(*(int *)(param_1 + 0x60d8) + 4) & 0x80000000) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x48) = 1;
    while ((*(uint *)(*(int *)(param_1 + 0x60d8) + 0x48) & 1) == 0) {
      SYNC(0);
    }
    *(uint *)(*(int *)(param_1 + 0x60d8) + 4) =
         *(uint *)(*(int *)(param_1 + 0x60d8) + 4) & 0x7fffffff;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x48) =
           *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x48);
      SYNC(0);
    } while ((*(uint *)(*(int *)(param_1 + 0x60d8) + 0x48) & 4) == 0);
  }
  return;
}



/* c08dae00 FUN_c08dae00 */

/* Boundary evidence: original MIPS .pdata c08dae00..c08db02f. Semantic name remains unreviewed. */

void FUN_c08dae00(int param_1)

{
  undefined4 local_10;
  
  *(undefined4 *)(param_1 + 0x6100) = *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x24);
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    *(undefined4 *)(param_1 + 0x61dc + local_10 * 0x20) =
         *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x100 + local_10 * 0x20);
    *(undefined4 *)(param_1 + local_10 * 0x20 + 0x61e0) =
         *(undefined4 *)(*(int *)(param_1 + 0x60d8) + local_10 * 0x20 + 0x104);
    *(undefined4 *)(param_1 + local_10 * 0x20 + 0x61e4) =
         *(undefined4 *)(*(int *)(param_1 + 0x60d8) + local_10 * 0x20 + 0x108);
    *(undefined4 *)(param_1 + local_10 * 0x20 + 0x61e8) =
         *(undefined4 *)(*(int *)(param_1 + 0x60d8) + local_10 * 0x20 + 0x10c);
  }
  *(undefined4 *)(param_1 + 0x60e4) = *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 8);
  *(undefined4 *)(param_1 + 0x6104) = *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x28);
  *(undefined4 *)(param_1 + 0x6108) = *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x2c);
  if (*(int *)(*(int *)(param_1 + 0x69e0) + 0x3c) != 0) {
    (**(code **)(*(int *)(param_1 + 0x69e0) + 0x3c))(param_1);
  }
  *(undefined4 *)(param_1 + 0x6a08) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x24) = 0;
  SYNC(0);
  return;
}



/* c08db030 FUN_c08db030 */

/* Boundary evidence: original MIPS .pdata c08db030..c08db383. Semantic name remains unreviewed. */

void FUN_c08db030(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  
  if ((*(uint *)(*(int *)(param_1 + 0x60d8) + 4) & 0x80000000) == 0) {
    NKDbgPrintfW(L"LCD Register re-init \r\n");
    puVar1 = (uint *)(*(int *)(param_1 + 0x60d8) + 4);
    *puVar1 = *puVar1 & 0x7fffffff;
    do {
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x48);
      *puVar2 = *puVar2;
    } while ((*(uint *)(*(int *)(param_1 + 0x60d8) + 0x48) & 4) == 0);
    pcVar3 = *(code **)(*(int *)(param_1 + 0x69e0) + 0x3c);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(param_1);
    }
    *(uint *)(*(int *)(param_1 + 0x69dc) + 0x28) =
         *(uint *)(*(int *)(param_1 + 0x69dc) + 0x28) & 0xffffffe7 | 7;
    *(int *)(*(int *)(param_1 + 0x69dc) + 100) = *(int *)(*(int *)(param_1 + 0x69e0) + 0x30) << 1;
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 4) =
         *(undefined4 *)(*(int *)(param_1 + 0x69e0) + 0xc);
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0xc) =
         *(undefined4 *)(*(int *)(param_1 + 0x69e0) + 0x10);
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x10) =
         *(undefined4 *)(*(int *)(param_1 + 0x69e0) + 0x14);
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x14) =
         *(undefined4 *)(*(int *)(param_1 + 0x69e0) + 0x18);
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x18) =
         *(undefined4 *)(*(int *)(param_1 + 0x69e0) + 0x1c);
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x1c) =
         *(undefined4 *)(*(int *)(param_1 + 0x69e0) + 0x20);
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x50) =
         *(undefined4 *)(*(int *)(param_1 + 0x69e0) + 0x24);
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x54) =
         *(undefined4 *)(*(int *)(param_1 + 0x69e0) + 0x28);
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x4c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x48) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x24) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x30) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x48) = 7;
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x4c) = 3;
    puVar1 = (uint *)(*(int *)(param_1 + 0x60d8) + 4);
    *puVar1 = *puVar1 | 0x80000000;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x100) = 0x3fe;
  if (*(int *)(param_1 + 0x50) == 0x20) {
    uVar5 = 0x1a400000;
  }
  else {
    uVar5 = 0xc400000;
    if (*(int *)(param_1 + 0x50) != 0x10) {
      uVar5 = 0x6400000;
    }
  }
  *(uint *)(*(int *)(param_1 + 0x60d8) + 0x104) =
       *(int *)(param_1 + 0x48) * 0x800 - 0x800U | *(int *)(param_1 + 0x4c) - 1U | uVar5;
  if (*(int *)(param_1 + 0x6af8) != 0) {
    puVar1 = (uint *)(*(int *)(param_1 + 0x60d8) + 0x104);
    *puVar1 = *puVar1 | 0x20000000;
  }
  puVar1 = (uint *)(*(int *)(param_1 + 0x60d8) + 0x104);
  *puVar1 = *(int *)(param_1 + 0x6afc) << 0x1e | *puVar1;
  iVar4 = *(int *)(param_1 + 0x50) * *(int *)(param_1 + 0x48);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 7;
  }
  *(uint *)(*(int *)(param_1 + 0x60d8) + 0x108) = (iVar4 >> 3 | 0x8000U) << 8;
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x110);
  *puVar2 = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x10c) = *puVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x114) = 0;
  puVar1 = (uint *)(*(int *)(param_1 + 0x60d8) + 0x24);
  *puVar1 = *puVar1 | 1;
  pcVar3 = *(code **)(*(int *)(param_1 + 0x69e0) + 0x38);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(param_1);
  }
  return;
}



/* c08db384 FUN_c08db384 */

/* Boundary evidence: original MIPS .pdata c08db384..c08db3e3. Semantic name remains unreviewed. */

undefined4 FUN_c08db384(int param_1)

{
  BOOL BVar1;
  DWORD aDStack_10 [2];
  
  BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x6a04),0x220408,(LPVOID)(param_1 + 0x69e4),0x20,
                          (LPVOID)0x0,0,aDStack_10,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    NKDbgPrintfW(L"Cannot free memory\r\n");
  }
  return 1;
}



/* c08db3e4 FUN_c08db3e4 */

/* Boundary evidence: original MIPS .pdata c08db3e4..c08db49f. Semantic name remains unreviewed. */

bool FUN_c08db3e4(int param_1,undefined4 param_2)

{
  BOOL BVar1;
  DWORD aDStack_18 [2];
  
  memset((void *)(param_1 + 0x69e4),0,0x20);
  *(undefined4 *)(param_1 + 0x69f0) = param_2;
  *(undefined4 *)(param_1 + 0x69f8) = 2;
  BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x6a04),0x220404,(void *)(param_1 + 0x69e4),0x20,
                          (LPVOID)0x0,0,aDStack_18,(LPOVERLAPPED)0x0);
  if (BVar1 != 0) {
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x69ec);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x69e8);
  }
  else {
    NKDbgPrintfW(L"Cannot get memory: size:%d\r\n",param_2);
  }
  return BVar1 != 0;
}



/* c08db4a0 FUN_c08db4a0 */

/* Boundary evidence: original MIPS .pdata c08db4a0..c08db907. Semantic name remains unreviewed. */

undefined4 FUN_c08db4a0(int param_1)

{
  wchar_t *lpValueName;
  wchar_t *lpValueName_00;
  LSTATUS LVar1;
  int iVar2;
  DWORD dwIndex;
  DWORD local_268 [2];
  HKEY local_260;
  HKEY local_25c;
  HKEY local_258;
  DWORD local_254;
  int local_250;
  undefined4 local_24c;
  wchar_t *local_248;
  undefined4 local_244;
  wchar_t *local_240;
  undefined4 local_23c;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c0906fb8;
  dwIndex = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\Display\\AU13XXLCD",0,0,&local_260);
  if (LVar1 == 0) {
    local_268[1] = 4;
    local_268[0] = 4;
    RegQueryValueExW(local_260,L"Bpp",(LPDWORD)0x0,local_268 + 1,(LPBYTE)(param_1 + 0x70),local_268)
    ;
    local_268[1] = 4;
    local_268[0] = 4;
    RegQueryValueExW(local_260,L"OffScreenSize",(LPDWORD)0x0,local_268 + 1,(LPBYTE)(param_1 + 0x74),
                     local_268);
    local_268[0] = 0x104;
    RegQueryValueExW(local_260,L"Key",(LPDWORD)0x0,local_268 + 1,(LPBYTE)aWStack_238,local_268);
    local_268[1] = 4;
    local_268[0] = 4;
    RegQueryValueExW(local_260,L"ColorKey",(LPDWORD)0x0,local_268 + 1,(LPBYTE)&local_23c,local_268);
    RegQueryValueExW(local_260,L"ColorKeyMask",(LPDWORD)0x0,local_268 + 1,(LPBYTE)&local_244,
                     local_268);
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x28) = local_23c;
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x2c) = local_244;
    local_268[1] = 4;
    local_268[0] = 4;
    RegQueryValueExW(local_260,L"BackColor",(LPDWORD)0x0,local_268 + 1,(LPBYTE)&local_24c,local_268)
    ;
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 8) = local_24c;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\Display\\AU13XXLCD\\Windows",0,0,&local_258);
    if (LVar1 == 0) {
      local_254 = 0x104;
      LVar1 = RegEnumKeyExW(local_258,0,aWStack_238,&local_254,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,(PFILETIME)0x0);
      if (LVar1 == 0) {
        local_248 = L"FriendlyName";
        local_240 = L"Index";
        do {
          lpValueName_00 = local_240;
          lpValueName = local_248;
          local_254 = 0x104;
          dwIndex = dwIndex + 1;
          RegOpenKeyExW(local_258,aWStack_238,0,0,&local_25c);
          local_268[1] = 4;
          local_268[0] = 4;
          RegQueryValueExW(local_25c,lpValueName_00,(LPDWORD)0x0,local_268 + 1,(LPBYTE)&local_250,
                           local_268);
          local_268[1] = 1;
          iVar2 = local_250 * 0x210 + param_1;
          local_268[0] = 0x208;
          RegQueryValueExW(local_25c,lpValueName,(LPDWORD)0x0,local_268 + 1,(LPBYTE)(iVar2 + 0x6b00)
                           ,local_268);
          local_268[1] = 4;
          local_268[0] = 4;
          RegQueryValueExW(local_25c,L"Pipe",(LPDWORD)0x0,local_268 + 1,(LPBYTE)(iVar2 + 0x6af8),
                           local_268);
          local_268[1] = 4;
          local_268[0] = 4;
          RegQueryValueExW(local_25c,L"Priority",(LPDWORD)0x0,local_268 + 1,(LPBYTE)(iVar2 + 0x6afc)
                           ,local_268);
          RegCloseKey(local_25c);
          NKDbgPrintfW(L"Window(%d) %20s Config. Pipe:%d Priority:%d\r\n",local_250,
                       (LPBYTE)(iVar2 + 0x6b00),*(undefined4 *)(iVar2 + 0x6af8),
                       *(undefined4 *)(iVar2 + 0x6afc));
          LVar1 = RegEnumKeyExW(local_258,dwIndex,aWStack_238,&local_254,(LPDWORD)0x0,(LPWSTR)0x0,
                                (LPDWORD)0x0,(PFILETIME)0x0);
        } while (LVar1 == 0);
      }
      RegCloseKey(local_260);
      RegCloseKey(local_258);
      FUN_c08f26d4(local_30);
      return 1;
    }
  }
  FUN_c08f26d4(local_30);
  return 0;
}



/* c08db908 FUN_c08db908 */

/* Boundary evidence: original MIPS .pdata c08db908..c08db977. Semantic name remains unreviewed. */

void FUN_c08db908(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c08d16d8;
  if ((LPCVOID)param_1[0x1e] != (LPCVOID)0x0) {
    UnmapViewOfFile((LPCVOID)param_1[0x1e]);
  }
  if ((HANDLE)param_1[0x1835] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x1835]);
  }
  FUN_c08db384((int)param_1);
  FUN_c08ea9bc();
  FUN_c08df818(param_1);
  return;
}



/* c08db990 FUN_c08db990 */

/* Boundary evidence: original MIPS .pdata c08db990..c08dbb17. Semantic name remains unreviewed. */

undefined4 FUN_c08db990(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  
  if (param_2 != 0) {
    return 0x80070057;
  }
  puVar5 = &DAT_c08fd0f4;
  if (param_3 != (undefined4 *)0x0) {
    iVar2 = param_1[0x1c];
    if (iVar2 == 8) {
      uVar1 = (*DAT_c0908b6c)(1,0x100,&DAT_c08fd0f4,0,0,0);
    }
    else if (iVar2 == 0x10) {
      puVar4 = *(undefined4 **)(param_1[0x1a78] + 0x34);
      uVar1 = (*DAT_c0908b6c)(2,0,0,*puVar4,puVar4[1],puVar4[2]);
    }
    else {
      if ((iVar2 != 0x18) && (iVar2 != 0x20)) goto LAB_c08dbaa0;
      uVar1 = (*DAT_c0908b6c)(2,0,0,DAT_c08fd524,DAT_c08fd528,DAT_c08fd52c);
    }
    *param_3 = uVar1;
  }
LAB_c08dbaa0:
  if (*(int *)(param_1[4] + 0xc) != 8) {
    iVar2 = 0;
    do {
      uVar3 = (undefined1)iVar2;
      *puVar5 = uVar3;
      puVar5[1] = uVar3;
      puVar5[2] = uVar3;
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar2 < 0x100);
  }
  (**(code **)(*param_1 + 0x1c))(param_1,&DAT_c08fd0f4,0,0x100);
  FUN_c08db030((int)param_1);
  return 0;
}



/* c08dbb18 FUN_c08dbb18 */

/* Boundary evidence: original MIPS .pdata c08dbb18..c08dbb53. Semantic name remains unreviewed. */

undefined4 FUN_c08dbb18(int param_1,void *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    memcpy(param_2,(void *)(param_1 + 0x44),0x18);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



/* c08dbb54 FUN_c08dbb54 */

/* Boundary evidence: original MIPS .pdata c08dbb54..c08dbf2f. Semantic name remains unreviewed. */

void FUN_c08dbb54(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar13 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (((*(int *)(param_1 + 0xa8) == 0) && (*(int *)(param_1 + 0xa0) == 0)) &&
     (*(int *)(param_1 + 0xa4) == 0)) {
    piVar8 = (int *)(param_1 + 0xac);
    iVar9 = *piVar8;
    uVar10 = *(undefined4 *)(param_1 + 0xb0);
    uVar11 = *(undefined4 *)(param_1 + 0xb4);
    uVar12 = *(undefined4 *)(param_1 + 0xb8);
    FUN_c08ead1c(param_1,piVar8);
    iVar14 = *(int *)(param_1 + 0xb0);
    if (iVar14 < *(int *)(param_1 + 0xb8)) {
      do {
        if (-1 < iVar14) {
          if (*(int *)(param_1 + 0x20) <= iVar14) break;
          iVar15 = *piVar8;
          iVar3 = *(int *)(*(int *)(param_1 + 4) + 8) * iVar14 + iVar13;
          iVar2 = (iVar14 - *(int *)(param_1 + 0xb0)) * (*(uint *)(param_1 + 0x70) >> 3) *
                  *(int *)(param_1 + 0xbc) + param_1 + 0xd4;
          if (iVar15 < *(int *)(param_1 + 0xb4)) {
            do {
              if (-1 < iVar15) {
                if (*(int *)(param_1 + 0x1c) <= iVar15) break;
                iVar4 = *(int *)(param_1 + 0x18);
                iVar6 = *piVar8;
                if (iVar4 == 0) {
LAB_c08dbd14:
                  iVar4 = ((iVar14 - *(int *)(param_1 + 0xb0)) * *(int *)(param_1 + 0xbc) - iVar6) +
                          iVar15;
                }
                else if (iVar4 == 1) {
                  iVar4 = (((iVar15 - iVar6) * *(int *)(param_1 + 0xbc) + *(int *)(param_1 + 0xc0))
                          - iVar14) + *(int *)(param_1 + 0xb0) + -1;
                }
                else if (iVar4 == 2) {
                  iVar4 = (((*(int *)(param_1 + 0xc0) - iVar14) + *(int *)(param_1 + 0xb0)) *
                           *(int *)(param_1 + 0xbc) - iVar15) + iVar6 + -1;
                }
                else {
                  if (iVar4 != 4) goto LAB_c08dbd14;
                  iVar4 = (((iVar6 - iVar15) + *(int *)(param_1 + 0xbc) + -1) *
                           *(int *)(param_1 + 0xbc) - *(int *)(param_1 + 0xb0)) + iVar14;
                }
                uVar5 = *(uint *)(param_1 + 0x70) >> 3;
                iVar1 = iVar4 + param_1;
                iVar4 = iVar4 + param_1;
                *(undefined1 *)((iVar15 - iVar6) * uVar5 + iVar2) =
                     *(undefined1 *)(uVar5 * iVar15 + iVar3);
                pbVar7 = (byte *)((*(uint *)(param_1 + 0x70) >> 3) * iVar15 + iVar3);
                *pbVar7 = *(byte *)(iVar1 + 0x50d4) & *pbVar7;
                pbVar7 = (byte *)((*(uint *)(param_1 + 0x70) >> 3) * iVar15 + iVar3);
                *pbVar7 = *pbVar7 ^ *(byte *)(iVar4 + 0x40d4);
                if (8 < *(uint *)(param_1 + 0x70)) {
                  uVar5 = *(uint *)(param_1 + 0x70) >> 3;
                  *(undefined1 *)((iVar15 - *piVar8) * uVar5 + iVar2 + 1) =
                       *(undefined1 *)(uVar5 * iVar15 + iVar3 + 1);
                  iVar6 = (*(uint *)(param_1 + 0x70) >> 3) * iVar15 + iVar3;
                  *(byte *)(iVar6 + 1) = *(byte *)(iVar1 + 0x50d4) & *(byte *)(iVar6 + 1);
                  iVar6 = (*(uint *)(param_1 + 0x70) >> 3) * iVar15 + iVar3;
                  *(byte *)(iVar6 + 1) = *(byte *)(iVar6 + 1) ^ *(byte *)(iVar4 + 0x40d4);
                  if (0x10 < *(uint *)(param_1 + 0x70)) {
                    uVar5 = *(uint *)(param_1 + 0x70) >> 3;
                    *(undefined1 *)((iVar15 - *piVar8) * uVar5 + iVar2 + 2) =
                         *(undefined1 *)(uVar5 * iVar15 + iVar3 + 2);
                    iVar6 = (*(uint *)(param_1 + 0x70) >> 3) * iVar15 + iVar3;
                    *(byte *)(iVar6 + 2) = *(byte *)(iVar1 + 0x50d4) & *(byte *)(iVar6 + 2);
                    iVar6 = (*(uint *)(param_1 + 0x70) >> 3) * iVar15 + iVar3;
                    *(byte *)(iVar6 + 2) = *(byte *)(iVar6 + 2) ^ *(byte *)(iVar4 + 0x40d4);
                  }
                }
              }
              iVar15 = iVar15 + 1;
            } while (iVar15 < *(int *)(param_1 + 0xb4));
          }
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 < *(int *)(param_1 + 0xb8));
    }
    *piVar8 = iVar9;
    *(undefined4 *)(param_1 + 0xb0) = uVar10;
    *(undefined4 *)(param_1 + 0xb4) = uVar11;
    *(undefined4 *)(param_1 + 0xb8) = uVar12;
    *(undefined4 *)(param_1 + 0xa4) = 1;
  }
  return;
}



/* c08dbf30 FUN_c08dbf30 */

/* Boundary evidence: original MIPS .pdata c08dbf30..c08dc167. Semantic name remains unreviewed. */

void FUN_c08dbf30(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar9 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (((*(int *)(param_1 + 0xa8) == 0) && (*(int *)(param_1 + 0xa0) == 0)) &&
     (*(int *)(param_1 + 0xa4) != 0)) {
    piVar4 = (int *)(param_1 + 0xac);
    iVar5 = *piVar4;
    uVar6 = *(undefined4 *)(param_1 + 0xb0);
    uVar7 = *(undefined4 *)(param_1 + 0xb4);
    uVar8 = *(undefined4 *)(param_1 + 0xb8);
    FUN_c08ead1c(param_1,piVar4);
    iVar11 = *(int *)(param_1 + 0xb0);
    if (iVar11 < *(int *)(param_1 + 0xb8)) {
      do {
        if (-1 < iVar11) {
          if (*(int *)(param_1 + 0x20) <= iVar11) break;
          iVar10 = *piVar4;
          iVar2 = *(int *)(*(int *)(param_1 + 4) + 8) * iVar11 + iVar9;
          iVar1 = (iVar11 - *(int *)(param_1 + 0xb0)) * (*(uint *)(param_1 + 0x70) >> 3) *
                  *(int *)(param_1 + 0xbc) + param_1 + 0xd4;
          if (iVar10 < *(int *)(param_1 + 0xb4)) {
            do {
              if (-1 < iVar10) {
                if (*(int *)(param_1 + 0x1c) <= iVar10) break;
                uVar3 = *(uint *)(param_1 + 0x70) >> 3;
                *(undefined1 *)(uVar3 * iVar10 + iVar2) =
                     *(undefined1 *)((iVar10 - *piVar4) * uVar3 + iVar1);
                if (8 < *(uint *)(param_1 + 0x70)) {
                  uVar3 = *(uint *)(param_1 + 0x70) >> 3;
                  *(undefined1 *)(uVar3 * iVar10 + iVar2 + 1) =
                       *(undefined1 *)((iVar10 - *piVar4) * uVar3 + iVar1 + 1);
                  if (0x10 < *(uint *)(param_1 + 0x70)) {
                    uVar3 = *(uint *)(param_1 + 0x70) >> 3;
                    *(undefined1 *)(uVar3 * iVar10 + iVar2 + 2) =
                         *(undefined1 *)((iVar10 - *piVar4) * uVar3 + iVar1 + 2);
                  }
                }
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < *(int *)(param_1 + 0xb4));
          }
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < *(int *)(param_1 + 0xb8));
    }
    *piVar4 = iVar5;
    *(undefined4 *)(param_1 + 0xb0) = uVar6;
    *(undefined4 *)(param_1 + 0xb4) = uVar7;
    *(undefined4 *)(param_1 + 0xb8) = uVar8;
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  return;
}



/* c08dc168 FUN_c08dc168 */

/* Boundary evidence: original MIPS .pdata c08dc168..c08dc2a7. Semantic name remains unreviewed. */

undefined4
FUN_c08dc168(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  uint uVar12;
  
  *(int *)(param_1 + 0xbc) = param_6;
  *(int *)(param_1 + 0xc0) = param_7;
  *(undefined4 *)(param_1 + 0xc4) = param_4;
  *(undefined4 *)(param_1 + 200) = param_5;
  FUN_c08dbf30(param_1);
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0xa0) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0xa0) = 0;
    iVar5 = *(int *)(param_2 + 8);
    iVar3 = *(int *)(param_2 + 4);
    iVar11 = 0;
    if (0 < param_7) {
      iVar4 = param_6;
      if (param_6 < 0) {
        iVar4 = param_6 + 7;
      }
      puVar9 = (undefined1 *)(param_1 + 0x40d4);
      do {
        iVar8 = 0;
        puVar10 = puVar9;
        if (0 < iVar4 >> 3) {
          do {
            uVar12 = 0x80;
            iVar7 = *(int *)(param_2 + 8) * iVar11 + iVar8;
            cVar1 = *(char *)(iVar7 + iVar5 * param_7 + iVar3);
            cVar2 = *(char *)(iVar7 + iVar3);
            iVar7 = 8;
            do {
              uVar6 = 0xff;
              if (((int)cVar2 & uVar12) == 0) {
                uVar6 = 0;
              }
              puVar10[0x1000] = uVar6;
              uVar6 = 0xff;
              if (((int)cVar1 & uVar12) == 0) {
                uVar6 = 0;
              }
              *puVar10 = uVar6;
              uVar12 = (int)uVar12 >> 1;
              iVar7 = iVar7 + -1;
              puVar10 = puVar10 + 1;
            } while (iVar7 != 0);
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar4 >> 3);
        }
        iVar11 = iVar11 + 1;
        puVar9 = puVar9 + param_6;
      } while (iVar11 < param_7);
    }
  }
  return 0;
}



/* c08dc2a8 FUN_c08dc2a8 */

/* Boundary evidence: original MIPS .pdata c08dc2a8..c08dc337. Semantic name remains unreviewed. */

undefined4 FUN_c08dc2a8(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_c08dbf30(param_1);
  if ((param_2 != -1) || (param_3 != -1)) {
    iVar1 = param_2 - *(int *)(param_1 + 0xc4);
    iVar2 = param_3 - *(int *)(param_1 + 200);
    *(int *)(param_1 + 0xac) = iVar1;
    *(int *)(param_1 + 0xb0) = iVar2;
    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xbc) + iVar1;
    *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xc0) + iVar2;
    FUN_c08dbb54(param_1);
  }
  return 0;
}



/* c08dc34c FUN_c08dc34c */

void FUN_c08dc34c(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = *(undefined4 *)(param_1 + 0x78);
  *param_3 = *(undefined4 *)(param_1 + 0x7c);
  return;
}



/* c08dc360 FUN_c08dc360 */

/* Boundary evidence: original MIPS .pdata c08dc360..c08dc5ab. Semantic name remains unreviewed. */

undefined4 FUN_c08dc360(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  if (*(int *)(param_2 + 0x14) == 0) {
    iVar3 = 1;
  }
  else {
    if (*(uint *)(param_2 + 0x10) == 0) {
      trap(0x1c00);
    }
    iVar3 = (uint)(*(int *)(param_2 + 0xc) * *(int *)(param_2 + 0x14)) / *(uint *)(param_2 + 0x10) +
            2;
  }
  switch(*(undefined4 *)(param_2 + 0x1c)) {
  case 0:
    iVar4 = *(int *)(param_2 + 4);
    iVar2 = *(int *)(param_2 + 0xc) + iVar4;
    break;
  case 1:
    iVar5 = *(int *)(param_2 + 8);
    iVar6 = *(int *)(param_2 + 0xc) + iVar5;
    goto LAB_c08dc430;
  case 2:
    iVar5 = *(int *)(param_2 + 8);
    iVar6 = *(int *)(param_2 + 0xc) + iVar5;
    goto LAB_c08dc44c;
  case 3:
    iVar2 = *(int *)(param_2 + 4);
    iVar4 = iVar2 - *(int *)(param_2 + 0xc);
    break;
  case 4:
    iVar2 = *(int *)(param_2 + 4);
    iVar4 = iVar2 - *(int *)(param_2 + 0xc);
    goto LAB_c08dc4ac;
  case 5:
    iVar6 = *(int *)(param_2 + 8);
    iVar5 = iVar6 - *(int *)(param_2 + 0xc);
LAB_c08dc44c:
    iVar2 = *(int *)(param_2 + 4) + 1;
    iVar6 = iVar6 + 1;
    iVar4 = iVar2 - iVar3;
    goto LAB_c08dc4bc;
  case 6:
    iVar6 = *(int *)(param_2 + 8);
    iVar5 = iVar6 - *(int *)(param_2 + 0xc);
LAB_c08dc430:
    iVar4 = *(int *)(param_2 + 4);
    iVar6 = iVar6 + 1;
    iVar2 = iVar4 + iVar3;
    goto LAB_c08dc4bc;
  case 7:
    iVar4 = *(int *)(param_2 + 4);
    iVar2 = *(int *)(param_2 + 0xc) + iVar4;
LAB_c08dc4ac:
    iVar6 = *(int *)(param_2 + 8) + 1;
    iVar5 = iVar6 - iVar3;
    iVar2 = iVar2 + 1;
    goto LAB_c08dc4bc;
  default:
    return 0x80070057;
  }
  iVar5 = *(int *)(param_2 + 8);
  iVar2 = iVar2 + 1;
  iVar6 = iVar5 + iVar3;
LAB_c08dc4bc:
  local_30 = param_1[0x2b];
  local_2c = param_1[0x2c];
  local_28 = param_1[0x2d];
  local_24 = param_1[0x2e];
  FUN_c08ead1c((int)param_1,&local_30);
  if ((((param_1[0x29] != 0) && (param_1[0x28] == 0)) && (local_2c < iVar6)) &&
     (((iVar5 < local_24 && (local_30 < iVar2)) && (iVar4 < local_28)))) {
    FUN_c08dbf30((int)param_1);
    param_1[0x2a] = 1;
  }
  uVar1 = FUN_c08eb320(param_1,param_2);
  if (param_1[0x2a] != 0) {
    param_1[0x2a] = 0;
    FUN_c08dbb54((int)param_1);
  }
  return uVar1;
}



/* c08dc7e4 FUN_c08dc7e4 */

/* Boundary evidence: original MIPS .pdata c08dc7e4..c08dc80f. Semantic name remains unreviewed. */

undefined4 FUN_c08dc7e4(int param_1)

{
  if (*(int *)(param_1 + 0xa8) != 0) {
    *(undefined4 *)(param_1 + 0xa8) = 0;
    FUN_c08dbb54(param_1);
  }
  return 0;
}



/* c08dc8d8 FUN_c08dc8d8 */

/* Boundary evidence: original MIPS .pdata c08dc8d8..c08dcac7. Semantic name remains unreviewed. */

undefined4 FUN_c08dc8d8(int param_1)

{
  int iVar1;
  uint in_stack_00000010;
  int *in_stack_00000014;
  
  if ((((in_stack_00000010 < 0x84) || (in_stack_00000014 == (int *)0x0)) ||
      ((iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0xc), iVar1 != 8 &&
       (((iVar1 != 0x10 && (iVar1 != 0x18)) && (iVar1 != 0x20)))))) || (*in_stack_00000014 != 100))
  {
    SetLastError(0x57);
    return 0xffffffff;
  }
  *in_stack_00000014 = 100;
  in_stack_00000014[1] = *(int *)(*(int *)(param_1 + 4) + 4);
  in_stack_00000014[2] = *(int *)(*(int *)(param_1 + 4) + 8);
  in_stack_00000014[3] = *(int *)(*(int *)(param_1 + 4) + 0x2c);
  in_stack_00000014[4] = *(int *)(*(int *)(param_1 + 4) + 0x30);
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0xc);
  if (iVar1 == 8) {
    in_stack_00000014[5] = 8;
    in_stack_00000014[6] = 0x10;
  }
  else {
    if (iVar1 == 0x10) {
      in_stack_00000014[5] = 0x10;
      iVar1 = 0xa0;
    }
    else {
      if (iVar1 == 0x18) {
        in_stack_00000014[5] = 0x18;
        in_stack_00000014[6] = 0x120;
        goto LAB_c08dc9c8;
      }
      in_stack_00000014[5] = 0x20;
      iVar1 = 0x120;
    }
    in_stack_00000014[6] = iVar1;
  }
LAB_c08dc9c8:
  *(undefined2 *)((int)in_stack_00000014 + 0x2a) = 0x27;
  *(undefined2 *)(in_stack_00000014 + 0x10) = 0x27;
  *(undefined2 *)(in_stack_00000014 + 7) = 0x26;
  *(undefined2 *)((int)in_stack_00000014 + 0x1e) = 0x25;
  *(undefined2 *)(in_stack_00000014 + 10) = 0x28;
  *(undefined2 *)(in_stack_00000014 + 0xd) = 0x25;
  *(undefined2 *)((int)in_stack_00000014 + 0x36) = 0x28;
  *(undefined2 *)((int)in_stack_00000014 + 0x42) = 0x26;
  *(undefined2 *)(in_stack_00000014 + 0x13) = 0xc3;
  *(undefined2 *)((int)in_stack_00000014 + 0x4e) = 0xc5;
  *(undefined2 *)(in_stack_00000014 + 0x16) = 0xc4;
  *(undefined2 *)((int)in_stack_00000014 + 0x5a) = 0xc1;
  *(undefined2 *)(in_stack_00000014 + 0x19) = 0xc5;
  *(undefined2 *)((int)in_stack_00000014 + 0x66) = 0xc2;
  *(undefined2 *)(in_stack_00000014 + 0x1c) = 0x86;
  *(undefined2 *)((int)in_stack_00000014 + 0x72) = 0x86;
  in_stack_00000014[0xc] = 0x186;
  in_stack_00000014[0xe] = 0x5a;
  in_stack_00000014[0x11] = 0x96;
  in_stack_00000014[8] = 0x78;
  in_stack_00000014[9] = 0x14a;
  in_stack_00000014[0xb] = 0x78;
  in_stack_00000014[0xf] = 0x168;
  in_stack_00000014[0x12] = 0x168;
  in_stack_00000014[0x14] = 0xb4;
  in_stack_00000014[0x15] = 0x14a;
  in_stack_00000014[0x17] = 0xd2;
  in_stack_00000014[0x18] = 0x159;
  in_stack_00000014[0x1a] = -0x32;
  in_stack_00000014[0x1b] = 0;
  in_stack_00000014[0x1d] = 0x78;
  in_stack_00000014[0x1e] = 0x168;
  in_stack_00000014[0x1f] = 0;
  in_stack_00000014[0x20] = 0;
  return 1;
}



/* c08dcac8 FUN_c08dcac8 */

/* Boundary evidence: original MIPS .pdata c08dcac8..c08dcbbb. Semantic name remains unreviewed. */

undefined4 FUN_c08dcac8(void)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14 [3];
  
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\GDI\\ROTATION",0,0,&local_18);
  if (LVar1 == 0) {
    local_14[1] = 4;
    local_14[0] = 4;
    LVar1 = RegQueryValueExW(local_18,L"ANGLE",(LPDWORD)0x0,local_14 + 1,(LPBYTE)(local_14 + 2),
                             local_14);
    if (LVar1 == 0) {
      if (local_14[2] != 0) {
        if (local_14[2] == 0x5a) {
          return 1;
        }
        if (local_14[2] == 0xb4) {
          return 2;
        }
        if (local_14[2] == 0x10e) {
          return 4;
        }
      }
    }
    else {
      RegCloseKey(local_18);
    }
  }
  return 0;
}



/* c08dcbbc FUN_c08dcbbc */

void FUN_c08dcbbc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 8);
LAB_c08dcc34:
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0xc);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 8);
        return;
      }
      if (iVar1 != 4) {
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 8);
        goto LAB_c08dcc34;
      }
    }
    uVar2 = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = uVar2;
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
  }
  return;
}



/* c08dcc44 FUN_c08dcc44 */

/* Boundary evidence: original MIPS .pdata c08dcc44..c08dcd13. Semantic name remains unreviewed. */

undefined4 FUN_c08dcc44(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (param_2 == *(int *)(param_1 + 0x18)) {
    return 0;
  }
  FUN_c08dbf30(param_1);
  *(int *)(param_1 + 0x18) = param_2;
  if (param_2 == 0) {
LAB_c08dccb4:
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x1c);
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 2) goto LAB_c08dccb4;
      if (param_2 != 4) goto LAB_c08dccc4;
    }
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x20);
  }
LAB_c08dccc4:
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 4) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = *(undefined4 *)(param_1 + 0xc);
  FUN_c08eaf5c(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2);
  FUN_c08dbb54(param_1);
  return 0;
}



/* c08dcd14 FUN_c08dcd14 */

undefined4 * FUN_c08dcd14(void)

{
  return &DAT_c08fd870;
}



/* c08dcd20 FUN_c08dcd20 */

/* Boundary evidence: original MIPS .pdata c08dcd20..c08dcd6b. Semantic name remains unreviewed. */

undefined4 FUN_c08dcd20(int param_1)

{
  if (*(int *)(param_1 + 0x50) == 0x10) {
    FUN_c08dab68(param_1);
  }
  else if (*(int *)(param_1 + 0x50) == 0x20) {
    FUN_c08d6b74(param_1);
  }
  return 0;
}



/* c08dcd6c FUN_c08dcd6c */

/* Boundary evidence: original MIPS .pdata c08dcd6c..c08dcdbb. Semantic name remains unreviewed. */

void FUN_c08dcd6c(int *param_1)

{
  (**(code **)(*param_1 + 0x30))(param_1);
  (**(code **)(*param_1 + 0x30))(param_1);
  (**(code **)(*param_1 + 0x30))(param_1);
  return;
}



/* c08dcdbc FUN_c08dcdbc */

/* Boundary evidence: original MIPS .pdata c08dcdbc..c08dce4b. Semantic name remains unreviewed. */

void FUN_c08dcdbc(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  
  bVar1 = false;
  do {
    InterruptDone(*(undefined4 *)(param_1 + 0x6a3c));
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x48);
    *puVar2 = *puVar2;
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x6a40),10);
    if ((*(uint *)(*(int *)(param_1 + 0x60d8) + 0x48) & 1) != 0) {
      bVar1 = true;
    }
  } while (!bVar1);
  return;
}



/* c08dce4c FUN_c08dce4c */

/* Boundary evidence: original MIPS .pdata c08dce4c..c08dcf8b. Semantic name remains unreviewed. */

void FUN_c08dce4c(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 0x69e0) + 0x38);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(param_1);
  }
  FUN_c08db030(param_1);
  iVar1 = -0x61e0 - param_1;
  iVar4 = 4;
  puVar3 = (undefined4 *)(param_1 + 0x61e0);
  do {
    *(undefined4 *)(*(int *)(param_1 + 0x60d8) + (-0x60e0 - param_1) + (int)puVar3) = puVar3[-1];
    *(undefined4 *)((int)puVar3 + *(int *)(param_1 + 0x60d8) + iVar1 + 0x104) = *puVar3;
    *(undefined4 *)((int)puVar3 + *(int *)(param_1 + 0x60d8) + iVar1 + 0x108) = puVar3[1];
    iVar4 = iVar4 + -1;
    *(undefined4 *)((int)puVar3 + *(int *)(param_1 + 0x60d8) + iVar1 + 0x10c) = puVar3[2];
    puVar3 = puVar3 + 8;
  } while (iVar4 != 0);
  *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 8) = *(undefined4 *)(param_1 + 0x60e4);
  *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x28) = *(undefined4 *)(param_1 + 0x6104);
  *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x2c) = *(undefined4 *)(param_1 + 0x6108);
  *(undefined4 *)(param_1 + 0x6a08) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x24) = *(undefined4 *)(param_1 + 0x6100);
  return;
}



/* c08dcf8c FUN_c08dcf8c */

/* Boundary evidence: original MIPS .pdata c08dcf8c..c08dd063. Semantic name remains unreviewed. */

void FUN_c08dcf8c(int param_1,int param_2)

{
  NKDbgPrintfW(L"LCD::PowerHandler( From:%d to %d)\r\n",*(undefined4 *)(param_1 + 0x6a0c),param_2);
  if (-1 < param_2) {
    if (param_2 < 3) {
      if ((*(int *)(param_1 + 0x6a0c) != 3) && (*(int *)(param_1 + 0x6a0c) != 4)) {
        return;
      }
      FUN_c08dce4c(param_1);
      return;
    }
    if (param_2 < 5) {
      if (*(int *)(param_1 + 0x6a0c) == 3) {
        return;
      }
      if (*(int *)(param_1 + 0x6a0c) == 4) {
        return;
      }
      FUN_c08dae00(param_1);
      FUN_c08dad0c(param_1);
      return;
    }
  }
  NKDbgPrintfW(L"ERROR: %s %d\r\n",
               "C:\\WINCE600\\PLATFORM\\DbAu13xx\\Src\\Drivers\\DISPLAY\\.\\display.cpp",0x252);
  return;
}



/* c08dd064 FUN_c08dd064 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c08dd064..c08dd5f3. Semantic name remains unreviewed. */

int * FUN_c08dd064(int *param_1)

{
  uint uVar1;
  HANDLE pvVar2;
  DWORD DVar3;
  int *piVar4;
  wchar_t *pwVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  FUN_c08df7d4(param_1);
  *param_1 = (int)&PTR_FUN_c08d16d8;
  param_1[0x1c] = 0x10;
  param_1[0x1d] = 0x200000;
  FUN_c08df760(param_1 + 0x1a91);
  param_1[0x1ab7] = 0;
  uVar1 = MmMapIoSpace(0x15000000,0,0x900,0);
  param_1[0x1836] = uVar1;
  if (uVar1 == 0) {
    NKDbgPrintfW(L"Fail to Map Au1200 LCD registers!\r\n");
  }
  else if (uVar1 != (uVar1 & 0xfffffffc)) {
    NKDbgPrintfW(L"Mapped Au1200 LCD registers to an unaligned address!!! (0x%x)\r\n",uVar1);
  }
  iVar9 = 0x20;
  do {
    *(undefined4 *)(iVar9 + param_1[0x1836] + 0x100) = 0;
    *(undefined4 *)(iVar9 + param_1[0x1836] + 0x104) = 0;
    *(undefined4 *)(iVar9 + param_1[0x1836] + 0x108) = 0;
    iVar6 = iVar9 + param_1[0x1836];
    iVar9 = iVar9 + 0x20;
    *(undefined4 *)(iVar6 + 0x114) = 0;
  } while (iVar9 < 0x80);
  FUN_c08db4a0((int)param_1);
  param_1[0x1a83] = 0;
  param_1[0x1a82] = 1;
  param_1[0x26] = 0;
  param_1[0x1a78] = (int)&PTR_u_Innonux_800x480_c08fd7f0;
  NKDbgPrintfW(L"\r\n\r\nUsing panel %d %s BPP:%d\r\n\r\n",0xb,PTR_u_Innonux_800x480_c08fd7f0,
               param_1[0x1c]);
  iVar9 = *(int *)(param_1[0x1a78] + 4);
  param_1[2] = iVar9;
  iVar6 = *(int *)(param_1[0x1a78] + 8);
  param_1[3] = iVar6;
  param_1[0x1a] = iVar9;
  param_1[0x1b] = iVar6;
  param_1[0x19] = ((uint)param_1[0x1c] >> 3) * iVar9;
  iVar9 = FUN_c08dcac8();
  param_1[6] = iVar9;
  FUN_c08dcbbc((int)param_1);
  iVar9 = param_1[0x1c];
  param_1[0x12] = param_1[2];
  param_1[0x13] = param_1[3];
  param_1[0x11] = 0;
  param_1[0x14] = iVar9;
  param_1[0x15] = 0x3c;
  if (iVar9 == 8) {
    param_1[0x10] = 1;
    param_1[0x16] = 3;
  }
  else if (iVar9 == 0x10) {
    param_1[0x10] = 2;
    param_1[0x16] = 4;
  }
  else {
    if (iVar9 == 0x18) {
      param_1[0x10] = 4;
      iVar9 = 5;
    }
    else {
      if (iVar9 == 0x20) {
        DAT_c08fd870 = 0xff0000;
        DAT_c08fd874 = 0xff00;
        DAT_c08fd878 = 0xff;
        param_1[0x10] = 4;
        param_1[0x16] = 6;
        goto LAB_c08dd2ac;
      }
      param_1[0x10] = 0;
      iVar9 = 9;
    }
    param_1[0x16] = iVar9;
  }
LAB_c08dd2ac:
  pvVar2 = CreateFileW(L"MEM1:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  param_1[0x1a81] = (int)pvVar2;
  if (pvVar2 == (HANDLE)0xffffffff) {
    DVar3 = GetLastError();
    NKDbgPrintfW(L"Cannot open MEM1: %d\r\n",DVar3);
  }
  else {
    iVar6 = param_1[8];
    iVar7 = param_1[0x1b];
    iVar8 = param_1[0x19];
    iVar10 = param_1[7];
    iVar11 = param_1[0x1a];
    iVar9 = param_1[0x13] * param_1[0x14] * param_1[0x12];
    param_1[4] = (int)(param_1 + 0x11);
    if (iVar9 < 0) {
      iVar9 = iVar9 + 7;
    }
    uVar1 = (iVar9 >> 3) + param_1[0x1d] & ~(_DAT_00005b04 - 1U);
    NKDbgPrintfW(L"fbsize: %d, %08x\r\n",uVar1,uVar1);
    FUN_c08db3e4((int)param_1,uVar1);
    NKDbgPrintfW(L"AllocPhysMem(): p=%08X v=%08X\r\n",param_1[0x18],param_1[0x17]);
    if (param_1[0x17] == 0) {
      pwVar5 = L"\n\rERROR: Unable to AllocPhysMem()\n\r";
    }
    else {
      iVar9 = MmMapIoSpace(param_1[0x18],0,uVar1,0);
      param_1[0x17] = iVar9;
      param_1[0x1e] = iVar9;
      if (iVar9 == 0) {
        pwVar5 = L"ERROR: Unable to allocate frame buffer!!!\n";
      }
      else {
        param_1[0x1f] = uVar1;
        param_1[0x1e] =
             iVar9 + ((uint)(iVar7 - iVar6) >> 1) * iVar8 + ((uint)(iVar11 - iVar10) >> 1);
        piVar4 = operator_new(0x14);
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = FUN_c08e0674(piVar4,param_1[0x1f],param_1[0x17],0,(int *)0x0);
        }
        iVar9 = param_1[4];
        param_1[0x27] = (int)piVar4;
        iVar9 = FUN_c08de2c0(param_1,param_1 + 1,*(undefined4 *)(iVar9 + 4),
                             *(undefined4 *)(iVar9 + 8),*(int *)(iVar9 + 0x14),1);
        if (-1 < iVar9) {
          FUN_c08eaf5c(param_1[1],param_1[2],param_1[3],param_1[6]);
          param_1[0x29] = 0;
          param_1[0x28] = 1;
          param_1[0x2a] = 0;
          memset(param_1 + 0x2b,0,0x10);
          param_1[0x1a86] = (int)FUN_c08ea8b8;
          param_1[0x1a87] = (int)FUN_c08ea8b8;
          param_1[0x1a88] = (int)FUN_c08ea8b8;
          param_1[0x1a89] = (int)FUN_c08ea8b8;
          param_1[0x1a8a] = (int)FUN_c08ea8b8;
          param_1[0x1a8b] = (int)FUN_c08ea8b8;
          param_1[0x1a8c] = (int)FUN_c08ea8b8;
          param_1[0x1a8d] = (int)FUN_c08ea8b8;
          param_1[0x1a8e] = (int)FUN_c08ea8b8;
          FUN_c08dcd20((int)param_1);
          FUN_c08dac78(DAT_c0908b84);
          iVar9 = MmMapIoSpace(0x10900000,0,0x114,0);
          param_1[0x1a77] = iVar9;
          if (iVar9 == 0) {
            NKDbgPrintfW(L"Fail to Map TOY registers!\r\n");
          }
          pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
          param_1[0x1a90] = (int)pvVar2;
          if (pvVar2 == (HANDLE)0xffffffff) {
            param_1[0x1a90] = 0;
          }
          iVar9 = InterruptConnect(0,0,0x5b,0);
          param_1[0x1a8f] = iVar9;
          if (iVar9 == 0) {
            NKDbgPrintfW(L"Au12: cannot allocate a sysintr for LCD!\r\n");
          }
          InterruptInitialize(param_1[0x1a8f],param_1[0x1a90],0,0);
          while (DVar3 = WaitForSingleObject((HANDLE)param_1[0x1a90],0), DVar3 == 0) {
            InterruptDone(param_1[0x1a8f]);
          }
          return param_1;
        }
        pwVar5 = L"Couldn\'t allocate primary surface\n";
      }
    }
    NKDbgPrintfW(pwVar5);
  }
  return param_1;
}



/* c08dd5f4 FUN_c08dd5f4 */

/* Boundary evidence: original MIPS .pdata c08dd5f4..c08dd63f. Semantic name remains unreviewed. */

undefined4 * FUN_c08dd5f4(undefined4 *param_1,uint param_2)

{
  FUN_c08db908(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c08dd640 FUN_c08dd640 */

/* Boundary evidence: original MIPS .pdata c08dd640..c08de153. Semantic name remains unreviewed. */

undefined4
FUN_c08dd640(int *param_1,undefined4 param_2,uint param_3,uint param_4,uint *param_5,uint param_6,
            uint *param_7)

{
  size_t _Size;
  undefined4 uVar1;
  wchar_t *pwVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  void *_Src;
  uint uVar13;
  uint uVar14;
  
  if (param_3 == 8) {
    uVar4 = *param_5;
    if ((((uVar4 == 0x20000) || (uVar4 == 0x189e)) || (uVar4 == 0x189d)) ||
       ((((uVar4 == 0x1803 || (uVar4 == 0x1804)) ||
         ((uVar4 == 0x321000 || ((uVar4 == 0x321004 || (uVar4 == 0x32100c)))))) ||
        (uVar4 == 0x321008)))) {
      return 1;
    }
  }
  else if (param_3 == 0x189e) {
    *param_7 = *(byte *)(param_1 + 6) | 0x700;
  }
  else {
    if (param_3 == 0x189d) {
      if ((((param_4 != 0) && (param_4 != 1)) && (param_4 != 2)) && (param_4 != 4)) {
        return 0xfffffffe;
      }
      uVar1 = FUN_c08dcc44((int)param_1,param_4);
      return uVar1;
    }
    if (param_3 == 0x20000) {
      uVar1 = FUN_c08dc8d8((int)param_1);
      return uVar1;
    }
    if ((param_1[0x1a83] != 4) || (param_3 == 0x321008)) {
      if (param_3 < 0x229c69) {
        if (param_3 == 0x229c68) {
          if (param_4 == 0x400) {
            (**(code **)(*param_1 + 0x1c))(param_1,param_5,0,0x100);
            return 1;
          }
          return 1;
        }
        switch(param_3) {
        case 0x229c40:
          if (3 < param_6) {
            *param_7 = *(uint *)(param_1[0x1836] + 4);
            return 1;
          }
          return 1;
        default:
          return 1;
        case 0x229c44:
          goto switchD_c08dd82c_caseD_4;
        case 0x229c48:
          if (param_4 == 4) {
            *(uint *)(param_1[0x1836] + 0x24) =
                 ~(1 << (*param_5 & 0x1f)) & *(uint *)(param_1[0x1836] + 0x24);
            return 1;
          }
          return 1;
        case 0x229c4c:
          if (0x1f < param_4) {
            uVar4 = *param_5;
            *(uint *)((uVar4 + 8) * 0x20 + param_1[0x1836]) = param_5[1];
            if ((param_5[5] & 2) == 0) {
              uVar13 = param_5[2];
              param_5[2] = uVar13 & 0x1fffffff;
              param_5[2] = (param_1[uVar4 * 0x84 + 0x1abf] << 1 | param_1[uVar4 * 0x84 + 0x1abe]) <<
                           0x1d | uVar13 & 0x1fffffff;
            }
            iVar5 = uVar4 * 0x20;
            *(uint *)(iVar5 + param_1[0x1836] + 0x104) = param_5[2];
            *(uint *)(iVar5 + param_1[0x1836] + 0x108) = param_5[3];
            *(uint *)(iVar5 + param_1[0x1836] + 0x114) = param_5[4];
            return 1;
          }
          return 1;
        case 0x229c50:
          if (0x1f < param_4) {
            uVar4 = *param_5;
            *(undefined4 *)((uVar4 + 8) * 0x20 + param_1[0x1836]) = 0;
            iVar5 = uVar4 * 0x20;
            *(undefined4 *)(iVar5 + param_1[0x1836] + 0x104) = 0;
            *(undefined4 *)(iVar5 + param_1[0x1836] + 0x108) = 0;
            *(undefined4 *)(iVar5 + param_1[0x1836] + 0x114) = 0;
            return 1;
          }
          return 1;
        case 0x229c54:
          if (0xb < param_4) {
            uVar4 = *param_5;
            if ((param_5[1] & 1) != 0) {
              (**(code **)(*param_1 + 0x54))(param_1);
            }
            puVar7 = (uint *)(uVar4 * 0x20 + param_1[0x1836] + 0x110);
            *puVar7 = param_5[2];
            *(uint *)(uVar4 * 0x20 + param_1[0x1836] + 0x10c) = *puVar7;
            return 1;
          }
          return 1;
        case 0x229c58:
          if (7 < param_4) {
            *(uint *)(param_1[0x1836] + 0x28) = *param_5;
            *(uint *)(param_1[0x1836] + 0x2c) = param_5[1];
            return 1;
          }
          return 1;
        case 0x229c5c:
          if (7 < param_6) {
            *param_7 = *(uint *)(param_1[0x1836] + 0x28);
            param_7[1] = *(uint *)(param_1[0x1836] + 0x2c);
            return 1;
          }
          return 1;
        case 0x229c60:
          if (param_4 == 4) {
            *(uint *)(param_1[0x1836] + 8) = *param_5;
            return 1;
          }
          return 1;
        case 0x229c64:
          if (3 < param_6) {
            *param_7 = *(uint *)(param_1[0x1836] + 8);
            return 1;
          }
          return 1;
        }
      }
      if (param_3 < 0x233881) {
        if (param_3 == 0x233880) {
          if (param_4 < 0x1c) {
            return 1;
          }
          iVar5 = param_1[0x1836] + *param_5 * 0x20;
          uVar13 = *(uint *)(iVar5 + 0x108) >> 8 & 0x1fff;
          uVar4 = (*(uint *)(iVar5 + 0x104) >> 0xb & 0x7ff) + 1;
          uVar3 = uVar13 / uVar4;
          if (uVar4 == 0) {
            trap(0x1c00);
          }
          _Size = param_5[3] * uVar3;
          iVar8 = param_5[2] * uVar3;
          if ((*(uint *)(iVar5 + 0x114) & 2) == 0) {
            iVar5 = iVar8 + *(int *)(iVar5 + 0x110) + param_5[1];
          }
          else {
            iVar5 = iVar8 + *(int *)(iVar5 + 0x10c) + param_5[1];
          }
          _Src = (void *)(iVar5 + -0x60000000);
          uVar4 = 0;
          if (param_5[4] != 0) {
            do {
              memcpy(param_7,_Src,_Size);
              uVar4 = uVar4 + 1;
              _Src = (void *)((int)_Src + (uVar13 - _Size));
              param_7 = (uint *)(_Size + (int)param_7);
            } while (uVar4 < param_5[4]);
            return 1;
          }
          return 1;
        }
        if (param_3 == 0x229c6c) {
          if (0x3ff < param_6) {
            puVar7 = (uint *)(param_1[0x1836] + 0x400);
            iVar5 = 0x100;
            do {
              uVar4 = *puVar7;
              puVar7 = puVar7 + 1;
              *param_7 = uVar4;
              iVar5 = iVar5 + -1;
              param_7 = param_7 + 1;
            } while (iVar5 != 0);
            return 1;
          }
          return 1;
        }
        if (param_3 != 0x229c74) {
          if (param_3 == 0x229c78) {
            if (param_4 < 0xc) {
              return 1;
            }
            iVar5 = *param_5 * 0x20;
            iVar8 = iVar5 + param_1[0x1836];
            if ((*(uint *)(iVar8 + 0x114) & 2) == 0) {
              *(uint *)(iVar8 + 0x110) = param_5[2];
              *(undefined4 *)(iVar5 + param_1[0x1836] + 0x114) = 1;
              return 1;
            }
            *(uint *)(iVar8 + 0x10c) = param_5[2];
            *(undefined4 *)(iVar5 + param_1[0x1836] + 0x114) = 0;
            return 1;
          }
          if (param_3 != 0x229c7c) {
            return 1;
          }
          if (param_4 == 4) {
            param_1[0x1ab7] = (uint)(*param_5 != 0);
            return 1;
          }
          return 1;
        }
        if (param_4 < 0x20) {
          return 1;
        }
        uVar4 = *param_5;
        if ((param_5[5] & 1) != 0) {
          iVar5 = uVar4 * 0x20;
          param_5[1] = *(uint *)((uVar4 + 8) * 0x20 + param_1[0x1836]);
          param_5[2] = *(uint *)(iVar5 + param_1[0x1836] + 0x104);
          param_5[3] = *(uint *)(iVar5 + param_1[0x1836] + 0x108);
          param_5[4] = *(uint *)(iVar5 + param_1[0x1836] + 0x114);
          return 1;
        }
        uVar10 = param_5[1] >> 0x15;
        uVar6 = param_5[3];
        uVar9 = param_5[1] >> 10 & 0x7ff;
        uVar11 = param_5[2] >> 0xb & 0x7ff;
        uVar14 = param_1[2] - 1;
        uVar13 = uVar6 >> 8 & 0x1fff;
        uVar3 = param_5[2] & 0x7ff;
        uVar12 = uVar6 >> 4 & 0xf;
        if (uVar14 < uVar10) {
          pwVar2 = L"Invalid x_orig: %d\r\n";
          uVar13 = uVar10;
        }
        else if (param_1[3] - 1U < uVar9) {
          pwVar2 = L"Invalid y_orig: %d\r\n";
          uVar13 = uVar9;
        }
        else if (uVar14 < uVar11 + uVar10) {
          pwVar2 = L"Invalid width: %d\r\n";
          uVar13 = uVar11;
        }
        else if (param_1[3] - 1U < uVar3 + uVar9) {
          pwVar2 = L"Invalid height: %d\r\n";
          uVar13 = uVar3;
        }
        else {
          if (uVar13 <= (uint)((param_1[2] + 1) * param_1[0x10])) {
            if ((uVar12 < 3) && ((uVar6 & 0xf) < 3)) {
              (**(code **)(*param_1 + 0x54))(param_1);
              iVar5 = uVar4 * 0x20;
              *(uint *)((uVar4 + 8) * 0x20 + param_1[0x1836]) = param_5[1];
              *(uint *)(iVar5 + param_1[0x1836] + 0x104) = param_5[2];
              *(uint *)(iVar5 + param_1[0x1836] + 0x108) = param_5[3];
              *(uint *)(iVar5 + param_1[0x1836] + 0x114) = param_5[4];
              return 1;
            }
            NKDbgPrintfW(L"Invalid scaler: %d or %d\r\n",uVar12);
            return 0;
          }
          pwVar2 = L"Invalid stride: %d\r\n";
        }
        NKDbgPrintfW(pwVar2,uVar13);
      }
      else {
        if (param_3 == 0x321000) {
          if (param_7 == (uint *)0x0) {
            return 1;
          }
          if (param_6 == 0x30) {
            memset(param_7,0,0x30);
            *(undefined1 *)param_7 = 0x11;
            return 1;
          }
          return 1;
        }
        if (param_3 == 0x321004) {
          if (param_7 == (uint *)0x0) {
            return 1;
          }
          if (param_6 == 4) {
            *param_7 = param_1[0x1a83];
            return 1;
          }
          return 1;
        }
        if (param_3 == 0x321008) {
          if (param_7 == (uint *)0x0) {
            return 1;
          }
          if (param_6 == 4) {
            uVar4 = *param_7;
            (**(code **)(*param_1 + 0xe4))(param_1,uVar4);
            param_1[0x1a83] = uVar4;
            return 1;
          }
          return 1;
        }
        if (param_3 != 0x32100c) {
          return 1;
        }
        if (param_7 == (uint *)0x0) {
          return 1;
        }
        if (param_6 != 4) {
          return 1;
        }
        if ((-1 < (int)*param_7) && ((int)*param_7 < 5)) {
          return 1;
        }
      }
    }
  }
  return 0;
switchD_c08dd82c_caseD_4:
  if (param_4 != 4) {
    return 1;
  }
  if ((*param_5 == 2) && (param_1[0x1ab7] == 0)) {
    NKDbgPrintfW(L"[Error] ~!@#$ Block 0000 OGL Enable m_bOGL_Activate %d / %d\r\n",0,2);
    return 1;
  }
  *(uint *)(param_1[0x1836] + 0x24) = 1 << (*param_5 & 0x1f) | *(uint *)(param_1[0x1836] + 0x24);
  return 1;
}



/* c08de154 FUN_c08de154 */

/* Boundary evidence: original MIPS .pdata c08de154..c08de1a7. Semantic name remains unreviewed. */

void FUN_c08de154(void)

{
  int *piVar1;
  
  if (DAT_c0908b28 == (int *)0x0) {
    piVar1 = operator_new(0x7338);
    if (piVar1 == (int *)0x0) {
      DAT_c0908b28 = (int *)0x0;
    }
    else {
      DAT_c0908b28 = FUN_c08dd064(piVar1);
    }
  }
  return;
}



/* c08de1a8 FUN_c08de1a8 */

/* Boundary evidence: original MIPS .pdata c08de1a8..c08de20b. Semantic name remains unreviewed. */

void FUN_c08de1a8(int *param_1)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  if (param_1[0x1ab8] + 1U < DVar1 - param_1[0x1ab9]) {
    param_1[0x1a84] = param_1[0x1a85];
  }
  else {
    (**(code **)(*param_1 + 0x54))(param_1);
  }
  return;
}



/* c08de20c FUN_c08de20c */

/* Boundary evidence: original MIPS .pdata c08de20c..c08de273. Semantic name remains unreviewed. */

undefined4 FUN_c08de20c(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == param_1[0x1a84]) || (param_2 == param_1[0x1a85])) {
    FUN_c08de1a8(param_1);
  }
  if ((param_2 == param_1[0x1a84]) || (uVar1 = 0, param_2 == param_1[0x1a85])) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c08de274 FUN_c08de274 */

/* Boundary evidence: original MIPS .pdata c08de274..c08de2bf. Semantic name remains unreviewed. */

undefined4 FUN_c08de274(int *param_1)

{
  if ((param_1[0x1a84] != param_1[0x1a85]) &&
     (FUN_c08de1a8(param_1), param_1[0x1a84] != param_1[0x1a85])) {
    return 1;
  }
  return 0;
}



/* c08de2c0 FUN_c08de2c0 */

/* Boundary evidence: original MIPS .pdata c08de2c0..c08de383. Semantic name remains unreviewed. */

void FUN_c08de2c0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  undefined1 auStack_70 [20];
  int local_5c;
  undefined4 local_3c;
  
  (**(code **)(*param_1 + 0xd4))(param_1,auStack_70,*(undefined4 *)param_1[4]);
  if ((param_5 != local_5c) && (param_5 != 8)) {
    local_3c = *(undefined4 *)(&DAT_c08d2234 + param_5 * 4);
  }
  (**(code **)(*param_1 + 0x80))(param_1,param_2,param_3,param_4,param_5,local_3c,param_6);
  return;
}



/* c08de384 FUN_c08de384 */

undefined4 FUN_c08de384(int param_1,int param_2,int param_3,uint param_4)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_2 + 0xb) * 0x20 + *(int *)(param_1 + 0x60d8));
  *puVar1 = (param_3 << 0xb | param_4) << 10 | *puVar1 & 0x3ff;
  return 0;
}



/* c08de3c0 FUN_c08de3c0 */

/* Boundary evidence: original MIPS .pdata c08de3c0..c08de47f. Semantic name remains unreviewed. */

undefined4 FUN_c08de3c0(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = FUN_c08e0c04(param_2);
  if (*(int *)(iVar1 + 0x34) == *(int *)(param_1 + 0x6af0)) {
    puVar2 = (uint *)(*(int *)(param_1 + 0x60d8) + 0x24);
    *puVar2 = *puVar2 & 0xfffffff7;
    *(undefined4 *)(param_1 + 0x6af0) = 0xffffffff;
    *(undefined1 *)(param_1 + 0x6aec) = 0;
    *(undefined1 *)(param_1 + 0x6af4) = 0;
    *(undefined1 *)(param_1 + 0x6af5) = 0;
    puVar2 = (uint *)(*(int *)(param_1 + 0x60d8) + 0x108);
    *puVar2 = *puVar2 & 0xfcffffff;
    puVar2 = (uint *)(*(int *)(param_1 + 0x60d8) + 0x128);
    *puVar2 = *puVar2 & 0xfcffffff;
  }
  return 0;
}



/* c08de480 FUN_c08de480 */

/* Boundary evidence: original MIPS .pdata c08de480..c08de507. Semantic name remains unreviewed. */

undefined4 FUN_c08de480(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_c08e0c04(param_3);
  iVar1 = *(int *)(iVar1 + 0x34);
  piVar2 = (int *)(*(int *)(param_1 + 0x60d8) + param_2 * 0x20 + 0x170);
  *piVar2 = *(int *)(param_1 + 0x60) + iVar1;
  *(int *)(*(int *)(param_1 + 0x60d8) + param_2 * 0x20 + 0x16c) = *piVar2;
  *(int *)(param_2 * 0xc + param_1 + 0x6af0) = iVar1;
  return 0;
}



/* c08de508 FUN_c08de508 */

/* Boundary evidence: original MIPS .pdata c08de508..c08de593. Semantic name remains unreviewed. */

void FUN_c08de508(int *param_1,int param_2,int param_3)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x34);
  if (param_3 != 0) {
    (**(code **)(*param_1 + 0x54))(param_1);
  }
  iVar2 = param_1[0x1836];
  param_1[0x1a85] = param_2;
  *(int *)(iVar2 + 0x110) = param_1[0x18] + iVar3;
  *(int *)(param_1[0x1836] + 0x10c) = *(int *)(iVar2 + 0x110);
  DVar1 = GetTickCount();
  param_1[0x1ab9] = DVar1;
  return;
}



/* c08de5ac FUN_c08de5ac */

/* Boundary evidence: original MIPS .pdata c08de5ac..c08de61b. Semantic name remains unreviewed. */

undefined4 *
FUN_c08de5ac(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9)

{
  FUN_c08e0914(param_1,param_2,param_3,param_5,param_6,param_7,param_8);
  *param_1 = &PTR_FUN_c08d1e0c;
  param_1[0xd] = param_4;
  param_1[0x1f] = param_9;
  param_1[8] = 0;
  return param_1;
}



/* c08de61c FUN_c08de61c */

/* WARNING: Removing unreachable block (ram,0xc08de7c4) */
/* Boundary evidence: original MIPS .pdata c08de61c..c08de8a3. Semantic name remains unreviewed. */

undefined4
FUN_c08de61c(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5,int param_6,
            uint param_7)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((param_6 < 0) || ((5 < param_6 && ((param_6 < 8 || (9 < param_6)))))) {
LAB_c08de86c:
    uVar3 = 0x80070057;
  }
  else {
    if (((param_7 & 4) == 0) &&
       (((param_7 & 1) == 0 &&
        ((param_5 != *(int *)(*(int *)(param_1 + 0x10) + 0x14) || ((param_7 & 2) == 0)))))) {
LAB_c08de7dc:
      iVar4 = *(int *)(&LAB_c08d284c + param_5 * 4);
      puVar2 = operator_new(0x7c);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_c08e0ce8(puVar2,param_3,param_4,iVar4 * param_3 + 0x1fU >> 3 & 0x1ffffffc,
                              param_5,param_6);
      }
      *param_2 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        if (puVar2[1] != 0) {
          return 0;
        }
        (**(code **)*puVar2)(puVar2,1);
      }
    }
    else {
      if (param_5 != *(int *)(*(int *)(param_1 + 0x10) + 0x14)) goto LAB_c08de86c;
      uVar6 = *(int *)(&LAB_c08d284c + param_5 * 4) * param_3 + 0x1f >> 3 & 0xfffffffc;
      FUN_c08e0644(*(int **)(param_1 + 0x9c));
      piVar1 = FUN_c08e0770(*(int **)(param_1 + 0x9c),uVar6 * param_4);
      if (piVar1 == (int *)0x0) {
        if ((param_7 & 1) != 0) {
          *param_2 = 0;
          return 0x8876017c;
        }
        goto LAB_c08de7dc;
      }
      iVar5 = piVar1[2];
      iVar4 = *(int *)(param_1 + 0x5c);
      puVar2 = operator_new(0x80);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_c08de5ac(puVar2,param_3,param_4,iVar5 - iVar4,piVar1[2],uVar6,param_5,param_6,
                              piVar1);
      }
      *param_2 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        return 0;
      }
      FUN_c08e084c(piVar1);
    }
    uVar3 = 0x8007000e;
  }
  return uVar3;
}



/* c08de8a4 FUN_c08de8a4 */

/* Boundary evidence: original MIPS .pdata c08de8a4..c08def13. Semantic name remains unreviewed. */

undefined4
FUN_c08de8a4(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,int param_7,
            int param_8,uint param_9)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  piVar1 = (int *)FUN_c08e0c04(param_2);
  iVar7 = 0;
  piVar3 = (int *)(param_1 + 0x6af0);
  do {
    if (((char)piVar3[-1] != '\0') && (*piVar3 == piVar1[0xd])) break;
    iVar7 = iVar7 + 1;
    piVar3 = piVar3 + 3;
  } while (iVar7 < 1);
  if (iVar7 == 1) {
    iVar7 = 0;
    pcVar4 = (char *)(param_1 + 0x6aec);
    do {
      if (*pcVar4 == '\0') break;
      iVar7 = iVar7 + 1;
      pcVar4 = pcVar4 + 0xc;
    } while (iVar7 < 1);
    if (iVar7 == 1) {
      return 0x88760244;
    }
  }
  NKDbgPrintfW(L"overlayIndex %d\r\n",iVar7);
  pcVar4 = (char *)((iVar7 + 0x8e9) * 0xc + param_1);
  if (*pcVar4 != '\0') goto LAB_c08deb10;
  iVar8 = *(int *)(param_1 + 0x50);
  uVar2 = (**(code **)(*piVar1 + 0x34))(piVar1);
  switch(uVar2) {
  case 0:
    *(undefined4 *)(iVar7 * 0x20 + *(int *)(param_1 + 0x60d8) + 0x164) = 0;
    goto LAB_c08dea48;
  case 1:
    uVar2 = 0x2000000;
    break;
  case 2:
    uVar2 = 0x4000000;
    break;
  case 3:
    uVar2 = 0x6000000;
    break;
  case 4:
    uVar2 = 0xc000000;
    break;
  case 5:
    uVar2 = 0x14000000;
    break;
  default:
    return 0x88760218;
  case 8:
    uVar2 = 0x18000000;
    break;
  case 9:
    uVar2 = 0x1a000000;
  }
  *(undefined4 *)(iVar7 * 0x20 + *(int *)(param_1 + 0x60d8) + 0x164) = uVar2;
LAB_c08dea48:
  iVar9 = iVar7 * 0x20;
  puVar5 = (uint *)(iVar9 + *(int *)(param_1 + 0x60d8) + 0x164);
  *puVar5 = (*(int *)(param_1 + 0x712c) << 1 | *(uint *)(param_1 + 0x7128)) << 0x1d | *puVar5 |
            0x400000;
  puVar5 = (uint *)(iVar9 + *(int *)(param_1 + 0x60d8) + 0x168);
  *puVar5 = *puVar5 & 0xffe000ff;
  puVar5 = (uint *)(iVar9 + *(int *)(param_1 + 0x60d8) + 0x168);
  *puVar5 = (iVar8 * param_3 & 0xfffffff8U | 0x40000) << 5 | *puVar5;
  *(undefined4 *)(iVar9 + *(int *)(param_1 + 0x60d8) + 0x174) = 0;
  FUN_c08de480(param_1,iVar7,param_2);
LAB_c08deb10:
  if ((((((param_9 & 0x100) == 0) && ((param_9 & 0x200) == 0)) && ((param_9 & 0x40) == 0)) &&
      ((param_9 & 0x80) == 0)) ||
     (((char)((*(char *)(param_1 + 0x6af5) != '\0') + (*(char *)(param_1 + 0x6af4) != '\0')) == '\0'
      || (param_7 == *(int *)(*(int *)(param_1 + 0x60d8) + 0x28))))) {
    if (((param_9 & 0x100) == 0) && ((param_9 & 0x200) == 0)) {
      if (((param_9 & 0x40) == 0) && ((param_9 & 0x80) == 0)) {
        iVar8 = iVar7 * 0x20;
        puVar5 = (uint *)(iVar8 + *(int *)(param_1 + 0x60d8) + 0x168);
        *puVar5 = *puVar5 & 0xfcffffff;
        puVar5 = (uint *)(iVar8 + *(int *)(param_1 + 0x60d8) + 0x164);
        *puVar5 = *puVar5 & 0x3fffffff;
        puVar5 = (uint *)(iVar8 + *(int *)(param_1 + 0x60d8) + 0x164);
        *puVar5 = (iVar7 + -2) * 0x40000000 | *puVar5;
      }
      else {
        iVar8 = iVar7 * 0x20;
        *(int *)(*(int *)(param_1 + 0x60d8) + 8) = param_7;
        *(int *)(*(int *)(param_1 + 0x60d8) + 0x28) = param_7;
        *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x2c) = 0xffffff;
        puVar5 = (uint *)(*(int *)(param_1 + 0x60d8) + 0x108);
        *puVar5 = *puVar5 & 0xfcffffff;
        puVar5 = (uint *)(iVar8 + *(int *)(param_1 + 0x60d8) + 0x168);
        *puVar5 = *puVar5 | 0x3000000;
        puVar5 = (uint *)(iVar8 + *(int *)(param_1 + 0x60d8) + 0x164);
        *puVar5 = *puVar5 & 0x3fffffff;
        puVar6 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0x60d8) + 0x164);
        *puVar6 = *puVar6;
        *(undefined1 *)(iVar7 * 0xc + param_1 + 0x6af5) = 1;
      }
    }
    else {
      iVar8 = iVar7 * 0x20;
      *(int *)(*(int *)(param_1 + 0x60d8) + 8) = param_7;
      *(int *)(*(int *)(param_1 + 0x60d8) + 0x28) = param_7;
      *(undefined4 *)(*(int *)(param_1 + 0x60d8) + 0x2c) = 0xffffff;
      puVar5 = (uint *)(*(int *)(param_1 + 0x60d8) + 0x108);
      *puVar5 = *puVar5 | 0x3000000;
      puVar5 = (uint *)(iVar8 + *(int *)(param_1 + 0x60d8) + 0x168);
      *puVar5 = *puVar5 & 0xfcffffff;
      puVar5 = (uint *)(iVar8 + *(int *)(param_1 + 0x60d8) + 0x164);
      *puVar5 = *puVar5 & 0x3fffffff;
      puVar5 = (uint *)(iVar8 + *(int *)(param_1 + 0x60d8) + 0x164);
      *puVar5 = (iVar7 + -2) * 0x40000000 | *puVar5;
      *(undefined1 *)(iVar7 * 0xc + param_1 + 0x6af4) = 1;
    }
    if ((param_9 & 0x10) == 0) {
      iVar8 = (iVar7 + 0xb) * 0x20;
      *(undefined4 *)(iVar8 + *(int *)(param_1 + 0x60d8)) = 0;
    }
    else {
      iVar8 = (iVar7 + 0xb) * 0x20;
      *(uint *)(iVar8 + *(int *)(param_1 + 0x60d8)) = param_8 << 2 | 2;
    }
    puVar5 = (uint *)(iVar8 + *(int *)(param_1 + 0x60d8));
    *puVar5 = (param_5 << 0xb | param_6) << 10 | *puVar5 & 0x3ff;
    puVar5 = (uint *)(iVar7 * 0x20 + *(int *)(param_1 + 0x60d8) + 0x164);
    *puVar5 = (param_3 + -1) * 0x800 | *puVar5 & 0xffc00000 | param_4 - 1U;
    if (*pcVar4 == '\0') {
      *pcVar4 = '\x01';
      puVar5 = (uint *)(*(int *)(param_1 + 0x60d8) + 0x24);
      *puVar5 = 1 << (iVar7 + 3U & 0x1f) | *puVar5;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* c08def14 FUN_c08def14 */

/* Boundary evidence: original MIPS .pdata c08def14..c08def73. Semantic name remains unreviewed. */

undefined4 * FUN_c08def14(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c08d1e0c;
  FUN_c08e084c((int *)param_1[0x1f]);
  FUN_c08e09c4(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c08def88 FUN_c08def88 */

/* Boundary evidence: original MIPS .pdata c08def88..c08defe3. Semantic name remains unreviewed. */

undefined4 FUN_c08def88(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_c0908b28 + 0x50))();
  if (iVar1 == 0) {
    uVar2 = FUN_c08e13f4(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = 0x8876021c;
    uVar2 = 1;
  }
  return uVar2;
}



/* c08defe4 FUN_c08defe4 */

/* Boundary evidence: original MIPS .pdata c08defe4..c08df037. Semantic name remains unreviewed. */

undefined4 FUN_c08defe4(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar1 = (**(code **)(*DAT_c0908b28 + 0x5c))();
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0xc) = 0x8876021c;
  }
  return 1;
}



/* c08df038 FUN_c08df038 */

/* Boundary evidence: original MIPS .pdata c08df038..c08df183. Semantic name remains unreviewed. */

undefined4 FUN_c08df038(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 1) {
    do {
      iVar2 = (**(code **)(*DAT_c0908b28 + 0x30))();
    } while (iVar2 != 0);
    do {
      iVar2 = (**(code **)(*DAT_c0908b28 + 0x30))();
    } while (iVar2 == 0);
  }
  else if (iVar2 == 4) {
    iVar2 = (**(code **)(*DAT_c0908b28 + 0x30))();
    if (iVar2 == 0) {
      do {
        iVar2 = (**(code **)(*DAT_c0908b28 + 0x30))();
      } while (iVar2 == 0);
      do {
        iVar2 = (**(code **)(*DAT_c0908b28 + 0x30))();
      } while (iVar2 != 0);
    }
    else {
      do {
        iVar2 = (**(code **)(*DAT_c0908b28 + 0x30))();
      } while (iVar2 != 0);
    }
  }
  else {
    if (iVar2 != -0x7ffffffa) {
      return 0;
    }
    uVar1 = (**(code **)(*DAT_c0908b28 + 0x30))();
    *(undefined4 *)(param_1 + 8) = uVar1;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 1;
}



/* c08df184 FUN_c08df184 */

/* Boundary evidence: original MIPS .pdata c08df184..c08df27f. Semantic name remains unreviewed. */

undefined4 FUN_c08df184(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = FUN_c08e0c04(*(int *)(param_1 + 4));
  iVar2 = (**(code **)(*DAT_c0908b28 + 0x50))();
  if (iVar2 == 0) {
    (**(code **)(*DAT_c0908b28 + 0x54))();
    iVar2 = 0;
    piVar4 = DAT_c0908b28 + 0x1abc;
    do {
      if ((char)piVar4[-1] == '\0') {
        iVar5 = -1;
      }
      else {
        iVar5 = *piVar4;
      }
      if (iVar5 == *(int *)(iVar1 + 0x34)) {
        uVar3 = FUN_c08de480((int)DAT_c0908b28,iVar2,*(int *)(param_1 + 8));
        *(undefined4 *)(param_1 + 0x10) = uVar3;
        break;
      }
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 3;
    } while (iVar2 < 1);
    if (iVar2 == 1) {
      FUN_c08e1584(param_1);
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 0x8876021c;
  }
  return 1;
}



/* c08df280 FUN_c08df280 */

/* Boundary evidence: original MIPS .pdata c08df280..c08df2d7. Semantic name remains unreviewed. */

undefined4 FUN_c08df280(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_c0908b28 + 0x50))();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x8876021c;
  }
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  return 1;
}



/* c08df2d8 FUN_c08df2d8 */

/* Boundary evidence: original MIPS .pdata c08df2d8..c08df58b. Semantic name remains unreviewed. */

bool FUN_c08df2d8(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  NKDbgPrintfW(L"HalUpdateOverlay\r\n");
  uVar8 = *(uint *)(param_1 + 0x2c);
  if ((uVar8 & 0x20) != 0) {
    iVar1 = FUN_c08de3c0(DAT_c0908b28,*(int *)(param_1 + 0x18));
    goto LAB_c08df550;
  }
  iVar5 = *(int *)(param_1 + 0x24);
  iVar1 = *(int *)(param_1 + 0x1c);
  iVar7 = *(int *)(param_1 + 0x28);
  iVar6 = *(int *)(param_1 + 0x20);
  uVar9 = 0;
  iVar10 = 0xff;
  if ((uVar8 & 0x100) == 0) {
    if ((uVar8 & 0x200) != 0) {
      uVar9 = *(uint *)(param_1 + 0x44);
      goto LAB_c08df3d4;
    }
    if ((uVar8 & 0x40) != 0) {
      uVar9 = *(uint *)(*(int *)(param_1 + 4) + 0x50);
LAB_c08df39c:
      NKDbgPrintfW(L"Destination color keying 0x%08X\r\n",uVar9);
      piVar2 = (int *)FUN_c08e0c04(*(int *)(param_1 + 4));
      goto LAB_c08df3f0;
    }
    if ((uVar8 & 0x80) != 0) {
      uVar9 = *(uint *)(param_1 + 0x3c);
      goto LAB_c08df39c;
    }
  }
  else {
    uVar9 = *(uint *)(*(int *)(param_1 + 4) + 0x48);
LAB_c08df3d4:
    piVar2 = (int *)FUN_c08e0c04(*(int *)(param_1 + 0x18));
    NKDbgPrintfW(L"Source color keying 0x%08X\r\n",uVar9);
LAB_c08df3f0:
    if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x34))(piVar2), iVar3 != 3)) {
      if (iVar3 == 4) {
        uVar9 = ((uVar9 >> 8 & 0xf8) << 8 | uVar9 >> 3 & 0xfc) << 8 | (uVar9 & 0x1f) << 3;
      }
      else {
        if ((iVar3 < 8) || (9 < iVar3)) {
          uVar4 = (**(code **)(*piVar2 + 0x34))(piVar2);
          NKDbgPrintfW(L"Unsupported overlay colorkey pixelformat! %d\r\n",uVar4);
          *(undefined4 *)(param_1 + 0x4c) = 0x80004001;
          return true;
        }
        uVar9 = (uVar9 >> 8 & 0xff | (uVar9 & 0xff) << 8) << 8 | uVar9 >> 0x10 & 0xff;
      }
    }
  }
  uVar8 = *(uint *)(param_1 + 0x2c);
  if (((uVar8 & 0x10) != 0) && (iVar10 = *(int *)(param_1 + 0x38), (uVar8 & 8) != 0)) {
    iVar10 = 0xff - iVar10;
  }
  iVar1 = FUN_c08de8a4(DAT_c0908b28,*(int *)(param_1 + 0x18),iVar5 - iVar1,iVar7 - iVar6,
                       *(int *)(param_1 + 8),*(uint *)(param_1 + 0xc),uVar9,iVar10,uVar8);
LAB_c08df550:
  *(int *)(param_1 + 0x4c) = iVar1;
  return iVar1 == 0;
}



/* c08df58c FUN_c08df58c */

/* Boundary evidence: original MIPS .pdata c08df58c..c08df617. Semantic name remains unreviewed. */

undefined4 FUN_c08df58c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = FUN_c08e0c04(*(int *)(param_1 + 4));
  iVar3 = 0;
  piVar4 = (int *)(DAT_c0908b28 + 0x6af0);
  while( true ) {
    if ((char)piVar4[-1] == '\0') {
      iVar5 = -1;
    }
    else {
      iVar5 = *piVar4;
    }
    if (iVar5 == *(int *)(iVar1 + 0x34)) break;
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 3;
    if (0 < iVar3) {
      return 1;
    }
  }
  uVar2 = FUN_c08de384(DAT_c0908b28,iVar3,*(int *)(param_1 + 0xc),*(uint *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  return 1;
}



/* c08df618 FUN_c08df618 */

/* Boundary evidence: original MIPS .pdata c08df618..c08df75f. Semantic name remains unreviewed. */

void FUN_c08df618(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_18 [2];
  
  iVar2 = FUN_c08df7b8();
  if (DAT_c0908b34 == 0) {
    FUN_c08dc34c(iVar2,local_18,&DAT_c0908b30);
    DAT_c0908b34 = local_18[0];
  }
  memset(param_1,0,0x11c);
  param_1[2] = &DAT_c08fd87c;
  param_1[3] = &DAT_c08fd8c8;
  param_1[5] = &LAB_c08def74;
  param_1[4] = &DAT_c08fd898;
  param_1[6] = 0x80;
  *param_1 = 0x11c;
  param_1[0x46] = 0;
  param_1[7] = DAT_c0908b30;
  uVar1 = DAT_c0908b30;
  param_1[0x1b] = 4;
  param_1[8] = uVar1;
  param_1[0x18] = 0x245;
  param_1[10] = 0x1fe;
  param_1[0xd] = 0xb;
  param_1[0x19] = 1;
  param_1[0x1c] = 8;
  param_1[0x20] = 9999;
  param_1[0x21] = 0x25;
  param_1[0x1f] = 1000;
  param_1[9] = 0;
  param_1[0xb] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x16] = param_1[0x16] | 0x1000;
  param_1[0x10] = param_1[0x10] | 1;
  param_1[0x17] = param_1[0x17] | 0x80010000;
  return;
}



/* c08df760 FUN_c08df760 */

undefined4 FUN_c08df760(undefined4 param_1)

{
  return param_1;
}



/* c08df768 FUN_c08df768 */

undefined4 * FUN_c08df768(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  do {
    if (*(int *)((int)&DAT_c08d2134 + uVar1) == param_1) {
      return &DAT_c08d2134 + iVar2 * 5;
    }
    uVar1 = uVar1 + 0x14;
    iVar2 = iVar2 + 1;
  } while (uVar1 < 0xb4);
  return (undefined4 *)0x0;
}



/* c08df7b8 FUN_c08df7b8 */

/* Boundary evidence: original MIPS .pdata c08df7b8..c08df7d3. Semantic name remains unreviewed. */

void FUN_c08df7b8(void)

{
  FUN_c08de154();
  return;
}



/* c08df7d4 FUN_c08df7d4 */

/* Boundary evidence: original MIPS .pdata c08df7d4..c08df817. Semantic name remains unreviewed. */

undefined4 * FUN_c08df7d4(undefined4 *param_1)

{
  FUN_c08ea8f8(param_1);
  *param_1 = &PTR_FUN_c08d225c;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return param_1;
}



/* c08df818 FUN_c08df818 */

/* Boundary evidence: original MIPS .pdata c08df818..c08df83b. Semantic name remains unreviewed. */

void FUN_c08df818(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c08d225c;
  FUN_c08ea94c(param_1);
  return;
}



/* c08df83c FUN_c08df83c */

/* Boundary evidence: original MIPS .pdata c08df83c..c08df86b. Semantic name remains unreviewed. */

void FUN_c08df83c(int *param_1)

{
  (**(code **)(*param_1 + 0x10))();
  return;
}



/* c08df86c FUN_c08df86c */

/* Boundary evidence: original MIPS .pdata c08df86c..c08df8bf. Semantic name remains unreviewed. */

undefined4 FUN_c08df86c(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x80))
                      (param_1,param_2,*(undefined4 *)(param_3 + 0x20),
                       *(undefined4 *)(param_3 + 0x24),*(undefined4 *)(param_3 + 0x34),
                       *(undefined4 *)(param_3 + 0x38),*(undefined4 *)(param_3 + 0x2c));
  }
  return uVar1;
}



/* c08df8c0 FUN_c08df8c0 */

/* Boundary evidence: original MIPS .pdata c08df8c0..c08df92b. Semantic name remains unreviewed. */

void FUN_c08df8c0(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  int local_10 [2];
  
  iVar1 = (**(code **)(*param_1 + 0x80))(param_1,local_10,param_3,param_4,param_5,param_6,1);
  if (-1 < iVar1) {
    *(undefined4 *)(local_10[0] + 100) = 0;
    *param_7 = *(undefined4 *)(local_10[0] + 0x34);
    *param_2 = local_10[0];
  }
  return;
}



/* c08df92c FUN_c08df92c */

/* Boundary evidence: original MIPS .pdata c08df92c..c08df98f. Semantic name remains unreviewed. */

void FUN_c08df92c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int local_10 [2];
  
  local_10[0] = 0;
  iVar1 = (**(code **)(*param_1 + 0x90))(param_1,local_10,param_3,param_4,param_5,param_6,param_7);
  if (-1 < iVar1) {
    if (param_2 != 0) {
      *(int *)(param_2 + 0x10) = local_10[0];
    }
    *(int *)(local_10[0] + 100) = param_2;
  }
  return;
}



/* c08df990 FUN_c08df990 */

/* Boundary evidence: original MIPS .pdata c08df990..c08dfa13. Semantic name remains unreviewed. */

int FUN_c08df990(int *param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int local_18 [2];
  
  if ((param_2 == (int *)0x0) || (param_3 == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) | 1;
    iVar1 = (**(code **)(*param_1 + 0x7c))(param_1,local_18);
    if (-1 < iVar1) {
      *(undefined4 *)(local_18[0] + 100) = 0;
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(local_18[0] + 0x34);
      }
      *param_2 = local_18[0];
    }
  }
  return iVar1;
}



/* c08dfa14 FUN_c08dfa14 */

/* Boundary evidence: original MIPS .pdata c08dfa14..c08dfa5f. Semantic name remains unreviewed. */

void FUN_c08dfa14(int *param_1,int param_2)

{
  int iVar1;
  int local_10 [2];
  
  local_10[0] = 0;
  iVar1 = (**(code **)(*param_1 + 0x88))(param_1,local_10);
  if (-1 < iVar1) {
    if (param_2 != 0) {
      *(int *)(param_2 + 0x10) = local_10[0];
    }
    *(int *)(local_10[0] + 100) = param_2;
  }
  return;
}



/* c08dfa60 FUN_c08dfa60 */

/* Boundary evidence: original MIPS .pdata c08dfa60..c08dfb33. Semantic name remains unreviewed. */

int FUN_c08dfa60(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_28 [2];
  
  piVar6 = (int *)param_1[1];
  iVar4 = piVar6[7];
  iVar3 = piVar6[0x10];
  iVar2 = piVar6[0xf];
  iVar5 = *param_1;
  uVar1 = (**(code **)(*piVar6 + 0x34))(piVar6);
  iVar2 = (**(code **)(iVar5 + 0x80))(param_1,local_28,iVar2,iVar3,iVar4,uVar1,4);
  if (-1 < iVar2) {
    FUN_c08e0c18(local_28[0],piVar6[0xb],piVar6[0xc],piVar6[0xe]);
    if (param_2 != 0) {
      *(int *)(param_2 + 0x10) = local_28[0];
    }
    *(int *)(local_28[0] + 100) = param_2;
  }
  return iVar2;
}



/* c08dfb34 FUN_c08dfb34 */

/* Boundary evidence: original MIPS .pdata c08dfb34..c08dfbaf. Semantic name remains unreviewed. */

void FUN_c08dfb34(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int local_10 [2];
  
  iVar1 = (**(code **)(*param_1 + 0x80))(param_1,local_10,param_3,param_4,param_5,param_6,param_8);
  if (-1 < iVar1) {
    if (local_10[0] == 0) {
      iVar1 = -0x7fff0001;
    }
    if (-1 < iVar1) {
      if (param_2 != 0) {
        *(int *)(param_2 + 0x10) = local_10[0];
      }
      *(int *)(local_10[0] + 100) = param_2;
    }
  }
  return;
}



/* c08dfbb0 FUN_c08dfbb0 */

/* Boundary evidence: original MIPS .pdata c08dfbb0..c08dfc4b. Semantic name remains unreviewed. */

undefined4
FUN_c08dfbb0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int param_4,int param_5,
            undefined4 param_6,undefined4 param_7,int param_8)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = operator_new(0x7c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c08e0914(puVar1,param_3,param_4,param_7,param_8,param_5,param_6);
  }
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *param_2 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* c08dfc4c FUN_c08dfc4c */

/* Boundary evidence: original MIPS .pdata c08dfc4c..c08dfcb7. Semantic name remains unreviewed. */

void FUN_c08dfc4c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int local_10 [2];
  
  local_10[0] = 0;
  iVar1 = (**(code **)(*param_1 + 0xa4))
                    (param_1,local_10,param_3,param_4,param_5,param_6,param_7,param_8);
  if (-1 < iVar1) {
    if (param_2 != 0) {
      *(int *)(param_2 + 0x10) = local_10[0];
    }
    *(int *)(local_10[0] + 100) = param_2;
  }
  return;
}



/* c08dfcb8 FUN_c08dfcb8 */

/* Boundary evidence: original MIPS .pdata c08dfcb8..c08dfd4f. Semantic name remains unreviewed. */

undefined4 FUN_c08dfcb8(undefined4 param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_3 + 0x30) != 0) {
    puVar1 = operator_new(0x7c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_c08e0914(puVar1,*(undefined4 *)(param_3 + 0x20),*(int *)(param_3 + 0x24),
                            *(undefined4 *)(param_3 + 0x30),*(int *)(param_3 + 0x28),
                            *(int *)(param_3 + 0x34),*(undefined4 *)(param_3 + 0x38));
    }
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    *param_2 = puVar1;
  }
  return 0;
}



/* c08dfd50 FUN_c08dfd50 */

/* Boundary evidence: original MIPS .pdata c08dfd50..c08dfd9b. Semantic name remains unreviewed. */

void FUN_c08dfd50(int *param_1,int param_2)

{
  int iVar1;
  int local_10 [2];
  
  local_10[0] = 0;
  iVar1 = (**(code **)(*param_1 + 0x9c))(param_1,local_10);
  if (-1 < iVar1) {
    if (param_2 != 0) {
      *(int *)(param_2 + 0x10) = local_10[0];
    }
    *(int *)(local_10[0] + 100) = param_2;
  }
  return;
}



/* c08dfd9c FUN_c08dfd9c */

/* Boundary evidence: original MIPS .pdata c08dfd9c..c08dfe4b. Semantic name remains unreviewed. */

undefined4 FUN_c08dfd9c(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_2 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    piVar4 = *(int **)(param_2 + 8);
    if ((piVar4 != (int *)0x0) && (*(int **)(param_2 + 4) != (int *)0x0)) {
      iVar2 = (**(code **)(**(int **)(param_2 + 4) + 0x34))();
      iVar3 = (**(code **)(*piVar4 + 0x34))(piVar4);
      if (iVar3 != iVar2) {
        return 0x80004001;
      }
    }
    uVar1 = (**(code **)(*param_1 + 4))(param_1,param_2);
  }
  return uVar1;
}



/* c08dfe4c FUN_c08dfe4c */

/* Boundary evidence: original MIPS .pdata c08dfe4c..c08dfecf. Semantic name remains unreviewed. */

int FUN_c08dfe4c(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0xac))(param_1,param_2);
    if ((-1 < iVar1) && (iVar1 = (*(code *)*param_2)(param_1,param_2), -1 < iVar1)) {
      iVar1 = (**(code **)(*param_1 + 8))(param_1,param_2);
    }
  }
  return iVar1;
}



/* c08dfed0 FUN_c08dfed0 */

/* Boundary evidence: original MIPS .pdata c08dfed0..c08e005b. Semantic name remains unreviewed. */

void FUN_c08dfed0(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_stack_0000001c;
  int *in_stack_00000020;
  undefined1 auStack_90 [4];
  int local_8c;
  int local_88;
  undefined4 local_80;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_48;
  undefined4 local_44;
  int local_34;
  undefined4 local_30;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0xdc))(param_1);
  memset(auStack_90,0,0x78);
  local_30 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    local_34 = piVar1[1];
  }
  local_48 = 3;
  local_5c = 1;
  local_58 = 1;
  local_44 = 0xff0000;
  if ((((param_3 != 0) && (param_2 == param_3)) &&
      (iVar2 = in_stack_0000001c[1], iVar2 < in_stack_00000020[3])) &&
     (((iVar3 = in_stack_00000020[1], iVar3 < in_stack_0000001c[3] &&
       (*in_stack_0000001c < in_stack_00000020[2])) && (*in_stack_00000020 < in_stack_0000001c[2])))
     ) {
    if (iVar3 == iVar2) {
      if (*in_stack_00000020 < *in_stack_0000001c) {
        local_5c = 0;
      }
      else {
        local_5c = 1;
      }
    }
    else {
      local_58 = 1;
      if (iVar3 < iVar2) {
        local_58 = 0;
      }
    }
  }
  local_8c = param_2;
  local_88 = param_3;
  local_80 = param_4;
  (**(code **)(*param_1 + 0xb0))(param_1,auStack_90);
  return;
}



/* c08e005c FUN_c08e005c */

/* Boundary evidence: original MIPS .pdata c08e005c..c08e00af. Semantic name remains unreviewed. */

void FUN_c08e005c(int *param_1)

{
  (**(code **)(*param_1 + 0xb8))();
  return;
}



/* c08e00b0 FUN_c08e00b0 */

/* Boundary evidence: original MIPS .pdata c08e00b0..c08e00d3. Semantic name remains unreviewed. */

void FUN_c08e00b0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 0xc0))(param_1,param_2,param_4);
  return;
}



/* c08e00d4 FUN_c08e00d4 */

/* Boundary evidence: original MIPS .pdata c08e00d4..c08e013f. Semantic name remains unreviewed. */

void FUN_c08e00d4(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    do {
      iVar1 = (**(code **)(*param_1 + 0x30))(param_1);
    } while (iVar1 != 0);
    do {
      iVar1 = (**(code **)(*param_1 + 0x30))(param_1);
    } while (iVar1 == 0);
  }
  FUN_c08ea9bc();
  return;
}



/* c08e0140 FUN_c08e0140 */

/* Boundary evidence: original MIPS .pdata c08e0140..c08e0477. Semantic name remains unreviewed. */

undefined4
FUN_c08e0140(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int *param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_3 + 4);
  if ((uVar2 & 0x40) == 0) {
    if ((uVar2 & 4) != 0) {
      iVar3 = *(int *)(param_3 + 8);
      puVar1 = FUN_c08df768(iVar3);
      if (puVar1 == (undefined4 *)0x0) {
        return 0x88760218;
      }
      *(undefined4 *)(param_3 + 0xc) = puVar1[1];
      *(undefined4 *)(param_3 + 0x10) = puVar1[2];
      *(undefined4 *)(param_3 + 0x14) = puVar1[3];
      *(undefined4 *)(param_3 + 0x18) = puVar1[4];
      if (iVar3 == 0x56595559) {
        iVar3 = 10;
        goto LAB_c08e0258;
      }
      if (iVar3 == 0x59565955) {
        iVar3 = 0xb;
      }
      else {
        if (iVar3 == 0x32595559) {
          iVar3 = 0xc;
          goto LAB_c08e042c;
        }
        if (iVar3 != 0x32315659) {
          return 0x88760218;
        }
        iVar3 = 0xd;
      }
LAB_c08e0400:
      *param_5 = iVar3;
      goto LAB_c08e0434;
    }
    if ((uVar2 & 0x20) == 0) {
      return 0x88760091;
    }
    if (*(int *)(param_3 + 0xc) != 8) {
      return 0x88760218;
    }
    iVar3 = 3;
  }
  else {
    if ((uVar2 & 1) == 0) {
      *(undefined4 *)(param_3 + 0x1c) = 0;
    }
    iVar3 = *(int *)(param_3 + 0xc);
    if ((iVar3 == 0x10) || (iVar3 == 0xf)) {
      iVar3 = *(int *)(param_3 + 0x1c);
      if ((iVar3 == 0) &&
         (((*(int *)(param_3 + 0x10) == 0xf800 && (*(int *)(param_3 + 0x14) == 0x7e0)) &&
          (*(int *)(param_3 + 0x18) == 0x1f)))) {
        iVar3 = 4;
      }
      else {
        if ((((iVar3 != 0x8000) || (*(int *)(param_3 + 0x10) != 0x7c00)) ||
            (*(int *)(param_3 + 0x14) != 0x3e0)) || (*(int *)(param_3 + 0x18) != 0x1f)) {
          if (((iVar3 == 0xf000) && (*(int *)(param_3 + 0x10) == 0xf00)) &&
             ((*(int *)(param_3 + 0x14) == 0xf0 && (*(int *)(param_3 + 0x18) == 0xf)))) {
            iVar3 = 6;
            goto LAB_c08e0400;
          }
          if (iVar3 != 0) {
            return 0x88760091;
          }
          if (*(int *)(param_3 + 0x10) != 0x7c00) {
            return 0x88760091;
          }
          if (*(int *)(param_3 + 0x14) != 0x3e0) {
            return 0x88760091;
          }
          if (*(int *)(param_3 + 0x18) != 0x1f) {
            return 0x88760091;
          }
          iVar3 = 7;
          goto LAB_c08e042c;
        }
        iVar3 = 5;
      }
      *param_5 = iVar3;
      goto LAB_c08e0434;
    }
    if (iVar3 != 0x18) {
      if (iVar3 != 0x20) {
        return 0x88760091;
      }
      if ((((*(int *)(param_3 + 0x1c) != -0x1000000) || (*(int *)(param_3 + 0x10) != 0xff0000)) ||
          (*(int *)(param_3 + 0x14) != 0xff00)) || (*(int *)(param_3 + 0x18) != 0xff)) {
        if (*(int *)(param_3 + 0x1c) != 0) {
          return 0x88760091;
        }
        if (*(int *)(param_3 + 0x10) != 0xff0000) {
          return 0x88760091;
        }
        if (*(int *)(param_3 + 0x14) != 0xff00) {
          return 0x88760091;
        }
        if (*(int *)(param_3 + 0x18) != 0xff) {
          return 0x88760091;
        }
      }
      iVar3 = 9;
LAB_c08e0258:
      *param_5 = iVar3;
      goto LAB_c08e0434;
    }
    if (((*(int *)(param_3 + 0x1c) != 0) || (*(int *)(param_3 + 0x10) != 0xff0000)) ||
       ((*(int *)(param_3 + 0x14) != 0xff00 || (*(int *)(param_3 + 0x18) != 0xff)))) {
      return 0x88760091;
    }
    iVar3 = 8;
  }
LAB_c08e042c:
  *param_5 = iVar3;
LAB_c08e0434:
  *param_4 = *(undefined4 *)(&UNK_c08d21e8 + *param_5 * 4);
  return 0;
}



/* c08e0478 FUN_c08e0478 */

/* Boundary evidence: original MIPS .pdata c08e0478..c08e05df. Semantic name remains unreviewed. */

int FUN_c08e0478(int *param_1,uint *param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_98 [4];
  int local_94;
  int local_90;
  int local_84;
  undefined1 auStack_80 [52];
  int local_4c;
  
  iVar4 = 0;
  memset(auStack_80,0,0x58);
  uVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)FUN_c08de154();
      iVar4 = (**(code **)(*piVar2 + 0x24))(piVar2,auStack_98,uVar3);
      if (-1 < iVar4) {
        piVar2 = (int *)FUN_c08de154();
        iVar4 = (**(code **)(*piVar2 + 0xd4))(piVar2,auStack_80,uVar3);
        if (iVar4 < 0) {
          local_4c = *(int *)(&DAT_c08d2234 + local_84 * 4);
          iVar4 = 0;
        }
        if ((((local_94 == param_3) && (local_90 == param_4)) && (local_84 == param_5)) &&
           (local_4c == param_6)) {
          *param_2 = uVar3;
          return iVar4;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return iVar4;
}



/* c08e05ec FUN_c08e05ec */

/* Boundary evidence: original MIPS .pdata c08e05ec..c08e0643. Semantic name remains unreviewed. */

undefined4 * FUN_c08e05ec(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c08d225c;
  FUN_c08ea94c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c08e0644 FUN_c08e0644 */

int FUN_c08e0644(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    if (param_1[4] == 0) {
      iVar1 = param_1[3] + iVar1;
    }
  }
  return iVar1;
}



/* c08e0674 FUN_c08e0674 */

int * FUN_c08e0674(int *param_1,int param_2,int param_3,int param_4,int *param_5)

{
  *param_1 = param_4;
  if (param_4 != 0) {
    *(int **)(param_4 + 4) = param_1;
  }
  param_1[1] = (int)param_5;
  if (param_5 != (int *)0x0) {
    *param_5 = (int)param_1;
  }
  param_1[2] = param_3;
  param_1[3] = param_2;
  param_1[4] = 0;
  return param_1;
}



/* c08e06a4 FUN_c08e06a4 */

/* Boundary evidence: original MIPS .pdata c08e06a4..c08e076f. Semantic name remains unreviewed. */

void FUN_c08e06a4(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1[1] == 0) {
    piVar2 = (int *)*param_1;
    if ((int *)*param_1 != (int *)0x0) {
      do {
        piVar1 = piVar2;
        piVar2 = (int *)*piVar1;
      } while ((int *)*piVar1 != (int *)0x0);
      while (piVar1 != param_1) {
        piVar1 = (int *)piVar1[1];
        *(undefined4 *)(*piVar1 + 4) = 0;
        piVar2 = (int *)*piVar1;
        if (piVar2 != (int *)0x0) {
          FUN_c08e06a4(piVar2);
          operator_delete(piVar2);
        }
        *piVar1 = 0;
      }
    }
  }
  else {
    *(int *)(param_1[1] + 0xc) = param_1[3] + *(int *)(param_1[1] + 0xc);
    *(int *)param_1[1] = *param_1;
    if (*param_1 != 0) {
      *(int *)(*param_1 + 4) = param_1[1];
    }
  }
  return;
}



/* c08e0770 FUN_c08e0770 */

/* Boundary evidence: original MIPS .pdata c08e0770..c08e084b. Semantic name remains unreviewed. */

int * FUN_c08e0770(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    do {
      if ((param_1[4] == 0) && (param_2 <= (uint)param_1[3])) break;
      param_1 = (int *)*param_1;
    } while (param_1 != (int *)0x0);
    if (param_1 != (int *)0x0) {
      if (param_2 < (uint)param_1[3]) {
        piVar1 = operator_new(0x14);
        if (piVar1 == (int *)0x0) {
          piVar1 = (int *)0x0;
        }
        else {
          iVar2 = param_1[2];
          iVar3 = param_1[3];
          iVar4 = *param_1;
          *piVar1 = iVar4;
          if (iVar4 != 0) {
            *(int **)(iVar4 + 4) = piVar1;
          }
          piVar1[1] = (int)param_1;
          *param_1 = (int)piVar1;
          piVar1[2] = iVar2 + param_2;
          piVar1[3] = iVar3 - param_2;
          piVar1[4] = 0;
        }
        if (piVar1 == (int *)0x0) {
          return (int *)0x0;
        }
        param_1[3] = param_2;
      }
      param_1[4] = 1;
    }
  }
  return param_1;
}



/* c08e084c FUN_c08e084c */

/* Boundary evidence: original MIPS .pdata c08e084c..c08e08c7. Semantic name remains unreviewed. */

void FUN_c08e084c(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  param_1[4] = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[4] == 0)) {
    FUN_c08e06a4(param_1);
    operator_delete(param_1);
    param_1 = piVar1;
  }
  piVar1 = (int *)*param_1;
  if ((piVar1 != (int *)0x0) && (piVar1[4] == 0)) {
    FUN_c08e06a4(piVar1);
    operator_delete(piVar1);
  }
  return;
}



/* c08e08c8 FUN_c08e08c8 */

/* Boundary evidence: original MIPS .pdata c08e08c8..c08e0913. Semantic name remains unreviewed. */

undefined4 * FUN_c08e08c8(undefined4 *param_1,uint param_2)

{
  FUN_c08eb2b0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c08e0914 FUN_c08e0914 */

/* Boundary evidence: original MIPS .pdata c08e0914..c08e09c3. Semantic name remains unreviewed. */

undefined4 *
FUN_c08e0914(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
            int param_6,undefined4 param_7)

{
  *param_1 = &PTR_FUN_c08d24a8;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_c08eae34((int)param_1,param_2,param_3,param_4,param_5,param_6);
  *param_1 = &PTR_FUN_c08d24ac;
  param_1[0x15] = 0xffffffff;
  param_1[0x16] = param_7;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x18] = 0;
  param_1[0x17] = param_3 * param_5;
  return param_1;
}



/* c08e09c4 FUN_c08e09c4 */

/* Boundary evidence: original MIPS .pdata c08e09c4..c08e0a1b. Semantic name remains unreviewed. */

void FUN_c08e09c4(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_c08d24ac;
  if ((param_1[10] != 0) && (param_1[1] != 0)) {
    uVar1 = RemoteLocalFree();
    param_1[1] = uVar1;
  }
  FUN_c08eb2b0(param_1);
  return;
}



/* c08e0a1c FUN_c08e0a1c */

/* Boundary evidence: original MIPS .pdata c08e0a1c..c08e0aaf. Semantic name remains unreviewed. */

void FUN_c08e0a1c(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = *(int *)(&LAB_c08d284c + param_6 * 4);
  FUN_c08eae34(param_1,param_2,param_3,param_4,param_5,param_6);
  *(undefined4 *)(param_1 + 0x58) = param_7;
  *(uint *)(param_1 + 0x5c) = (iVar1 * param_2 + 0x1fU >> 3 & 0x1ffffffc) * param_3;
  return;
}



/* c08e0acc FUN_c08e0acc */

/* Boundary evidence: original MIPS .pdata c08e0acc..c08e0b0b. Semantic name remains unreviewed. */

uint FUN_c08e0acc(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1[2];
  uVar1 = (**(code **)(*param_1 + 0xc))();
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  return (uint)(iVar2 << 3) / uVar1;
}



/* c08e0b0c FUN_c08e0b0c */

/* Boundary evidence: original MIPS .pdata c08e0b0c..c08e0b5f. Semantic name remains unreviewed. */

void FUN_c08e0b0c(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 0x2c))(param_1,param_2);
  (**(code **)(*param_1 + 0x24))(param_1,param_2);
  return;
}



/* c08e0b60 FUN_c08e0b60 */

/* Boundary evidence: original MIPS .pdata c08e0b60..c08e0b83. Semantic name remains unreviewed. */

void FUN_c08e0b60(int *param_1)

{
  (**(code **)(*param_1 + 0x28))();
  return;
}



/* c08e0c04 FUN_c08e0c04 */

undefined4 FUN_c08e0c04(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1;
}



/* c08e0c18 FUN_c08e0c18 */

/* Boundary evidence: original MIPS .pdata c08e0c18..c08e0c9b. Semantic name remains unreviewed. */

void FUN_c08e0c18(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  FUN_c08eaf5c(param_1,param_2,param_3,param_4);
  if ((*(int *)(param_1 + 0x60) != 0) && ((param_4 == 1 || (param_4 == 4)))) {
    *(undefined4 *)(param_1 + 0x40) = param_3;
    *(undefined4 *)(param_1 + 0x3c) = param_2;
  }
  return;
}



/* c08e0c9c FUN_c08e0c9c */

/* Boundary evidence: original MIPS .pdata c08e0c9c..c08e0ce7. Semantic name remains unreviewed. */

undefined4 * FUN_c08e0c9c(undefined4 *param_1,uint param_2)

{
  FUN_c08e09c4(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c08e0ce8 FUN_c08e0ce8 */

/* Boundary evidence: original MIPS .pdata c08e0ce8..c08e0e0f. Semantic name remains unreviewed. */

undefined4 *
FUN_c08e0ce8(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,int param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint nNumber;
  
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = &PTR_FUN_c08d24ac;
  param_1[10] = 0;
  nNumber = *(int *)(&LAB_c08d284c + param_5 * 4) * param_2 + 0x1fU >> 3 & 0x1ffffffc;
  iVar1 = MulDiv(nNumber,param_3,1);
  if (iVar1 != -1) {
    uVar2 = RemoteLocalAlloc(0,iVar1);
    FUN_c08e0a1c((int)param_1,param_2,param_3,uVar2,nNumber,param_5,param_6);
    param_1[10] = 1;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0x15] = 0xffffffff;
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    param_1[0x18] = 0;
  }
  return param_1;
}



/* c08e0e10 FUN_c08e0e10 */

/* Boundary evidence: original MIPS .pdata c08e0e10..c08e0e47. Semantic name remains unreviewed. */

void FUN_c08e0e10(int param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 != 0) && (puVar1 = *(undefined4 **)(param_1 + 0x10), puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(puVar1,1);
  }
  return;
}



/* c08e0e48 FUN_c08e0e48 */

/* Boundary evidence: original MIPS .pdata c08e0e48..c08e0ee3. Semantic name remains unreviewed. */

undefined4 FUN_c08e0e48(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_c08e0c04(*(int *)(param_1 + 4));
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x14) = 0x88760082;
  }
  else if (*(int *)(param_1 + 8) == 8) {
    (**(code **)(*piVar1 + 0x24))(piVar1,*(undefined4 *)(param_1 + 0xc));
    (**(code **)(*piVar1 + 0x2c))(piVar1,*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x887600d7;
  }
  return 1;
}



/* c08e0ee4 FUN_c08e0ee4 */

/* Boundary evidence: original MIPS .pdata c08e0ee4..c08e0f37. Semantic name remains unreviewed. */

undefined4 FUN_c08e0ee4(int param_1)

{
  int iVar1;
  int iStack_10;
  undefined4 uStack_c;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  if ((*(int *)(param_1 + 8) != 0) &&
     (iVar1 = FUN_c08e16e0(*(int *)(param_1 + 4),&uStack_c,&iStack_10), iVar1 < 0)) {
    *(undefined4 *)(param_1 + 0xc) = 0x88760218;
  }
  return 1;
}



/* c08e0f38 FUN_c08e0f38 */

/* Boundary evidence: original MIPS .pdata c08e0f38..c08e13f3. Semantic name remains unreviewed. */

undefined4 FUN_c08e0f38(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  int local_40;
  uint local_3c;
  int local_38;
  undefined1 auStack_34 [4];
  uint local_30 [2];
  
  iVar4 = *(int *)(param_1 + 4);
  uVar8 = 0;
  local_50 = *(int *)(iVar4 + 0xc);
  local_4c = *(undefined4 *)(iVar4 + 8);
  local_3c = *(uint *)(iVar4 + 4);
  local_38 = *(int *)(iVar4 + 0x50);
  local_48 = 0;
  piVar1 = (int *)FUN_c08df7b8();
  iVar4 = *(int *)(param_1 + 4);
  if (((*(uint *)(iVar4 + 100) & 0x10) != 0) &&
     ((*(int *)(piVar1[1] + 0x38) == 1 || (*(int *)(piVar1[1] + 0x38) == 4)))) {
    local_50 = *(int *)(iVar4 + 8);
    local_4c = *(undefined4 *)(iVar4 + 0xc);
  }
  iVar4 = FUN_c08e16e0(iVar4,&local_44,&local_40);
  if (iVar4 < 0) {
    *(undefined4 *)(param_1 + 0x10) = 0x88760218;
  }
  else {
    uVar10 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        iVar7 = *(int *)(uVar10 * 4 + *(int *)(param_1 + 0xc));
        uVar5 = *(uint *)(iVar7 + 8);
        if (uVar10 == 0) {
          uVar8 = uVar5 & 0x40;
          local_48 = uVar8;
        }
        if (uVar8 == 0) {
          if ((uVar5 & 0x180) == 0) {
            local_30[0] = uVar5 | 0x100;
            local_30[1] = uVar5 | 0x80;
            iVar2 = 2;
          }
          else {
            iVar2 = 1;
            local_30[0] = uVar5;
          }
          iVar6 = 0;
          if (iVar2 != 0) {
            puVar9 = local_30;
            do {
              if ((*puVar9 & 0x100) == 0) {
                if ((local_3c & 0x800) == 0) {
                  iVar4 = (**(code **)(*piVar1 + 0xa8))
                                    (piVar1,iVar7,local_50,local_4c,local_40,local_44,
                                     local_38 * local_50 + 0x1fU >> 3 & 0x1ffffffc,0);
                }
                else {
                  iVar4 = (**(code **)(*piVar1 + 0xa0))
                                    (piVar1,iVar7,local_50,local_4c,local_40,local_44,
                                     *(undefined4 *)(*(int *)(param_1 + 4) + 0x20),
                                     *(undefined4 *)(*(int *)(param_1 + 4) + 0x10));
                }
              }
              else {
                iVar4 = (**(code **)(*piVar1 + 0x8c))
                                  (piVar1,iVar7,local_50,local_4c,local_40,local_44,auStack_34);
              }
              uVar8 = local_48;
              if (-1 < iVar4) goto LAB_c08e1208;
              iVar6 = iVar6 + 1;
              puVar9 = puVar9 + 1;
            } while (iVar6 < iVar2);
          }
LAB_c08e11fc:
          uVar8 = local_48;
          if (iVar4 < 0) {
            *(int *)(param_1 + 0x10) = iVar4;
            return 1;
          }
        }
        else {
          if ((uVar5 & 0x40) == 0) {
            iVar2 = 2;
            if ((uVar5 & 0x180) != 0) {
              iVar2 = 1;
            }
            iVar6 = 0;
            if (iVar2 != 0) {
              do {
                iVar4 = (**(code **)(*piVar1 + 0x94))(piVar1,iVar7);
                uVar8 = local_48;
                if (-1 < iVar4) goto LAB_c08e1208;
                iVar6 = iVar6 + 1;
              } while (iVar6 < iVar2);
            }
            goto LAB_c08e11fc;
          }
          (**(code **)(*(int *)piVar1[1] + 8))((int *)piVar1[1],iVar7);
          iVar4 = 0;
        }
LAB_c08e1208:
        if ((uVar5 & 0x10) != 0) {
          iVar6 = piVar1[1];
          iVar2 = FUN_c08e0c04(iVar7);
          *(undefined4 *)(iVar2 + 0x60) = 1;
          FUN_c08e0c18(iVar2,*(undefined4 *)(iVar2 + 0x2c),*(undefined4 *)(iVar2 + 0x30),
                       *(int *)(iVar6 + 0x38));
        }
        iVar2 = FUN_c08e0c04(iVar7);
        if (*(int *)(iVar2 + 0x20) == 0) {
          *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 0x80;
        }
        else {
          *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 0x100;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(uint *)(param_1 + 8));
    }
    iVar4 = **(int **)(param_1 + 0xc);
    if (iVar4 != 0) {
      iVar7 = FUN_c08e0c04(iVar4);
      iVar2 = *(int *)(iVar7 + 8);
      iVar7 = FUN_c08e0c04(iVar4);
      iVar6 = *(int *)(iVar7 + 0x44);
      iVar7 = FUN_c08e0c04(iVar4);
      iVar7 = *(int *)(iVar7 + 0x38);
      if (iVar7 == 0) {
        *(int *)(*(int *)(param_1 + 4) + 0x10) = iVar2;
        *(int *)(*(int *)(param_1 + 4) + 0x14) = iVar6;
      }
      else if (iVar7 == 1) {
        *(int *)(*(int *)(param_1 + 4) + 0x10) = iVar6;
        *(int *)(*(int *)(param_1 + 4) + 0x14) = -iVar2;
      }
      else if (iVar7 == 2) {
        *(int *)(*(int *)(param_1 + 4) + 0x10) = -iVar2;
        *(int *)(*(int *)(param_1 + 4) + 0x14) = -iVar6;
      }
      else if (iVar7 == 4) {
        *(int *)(*(int *)(param_1 + 4) + 0x10) = -iVar6;
        *(int *)(*(int *)(param_1 + 4) + 0x14) = iVar2;
      }
      piVar1 = (int *)FUN_c08e0c04(iVar4);
      uVar3 = (**(code **)(*piVar1 + 0x44))(piVar1);
      *(undefined4 *)(*(int *)(param_1 + 4) + 0x68) = uVar3;
      *(uint *)(*(int *)(param_1 + 4) + 4) = *(uint *)(*(int *)(param_1 + 4) + 4) | 0x80018;
      iVar4 = FUN_c08e0c04(iVar4);
      if (*(int *)(iVar4 + 0x20) == 0) {
        *(uint *)(*(int *)(param_1 + 4) + 100) = *(uint *)(*(int *)(param_1 + 4) + 100) | 0x80;
      }
      else {
        *(uint *)(*(int *)(param_1 + 4) + 100) = *(uint *)(*(int *)(param_1 + 4) + 100) | 0x100;
      }
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 1;
}



/* c08e13f4 FUN_c08e13f4 */

/* Boundary evidence: original MIPS .pdata c08e13f4..c08e1533. Semantic name remains unreviewed. */

undefined4 FUN_c08e13f4(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_c08e0c04(*(int *)(param_1 + 4));
  if ((*(uint *)(param_1 + 0x1c) & 8) == 0) {
    piVar2 = (int *)FUN_c08df7b8();
    iVar3 = (**(code **)(*piVar2 + 0x58))(piVar2,iVar1);
    if (iVar3 == 0) {
      piVar2 = (int *)FUN_c08df7b8();
      iVar3 = (**(code **)(*piVar2 + 0x5c))(piVar2);
      if (iVar3 == 0) goto LAB_c08e14e4;
    }
    *(undefined4 *)(param_1 + 0x24) = 0x8876021c;
  }
  else {
    piVar2 = (int *)FUN_c08df7b8();
    (**(code **)(*piVar2 + 0x60))(piVar2);
    piVar2 = (int *)FUN_c08df7b8();
    iVar3 = (**(code **)(*piVar2 + 0x58))(piVar2,iVar1);
    if (iVar3 != 0) {
      piVar2 = (int *)FUN_c08df7b8();
      (**(code **)(*piVar2 + 0x54))(piVar2);
      do {
        piVar2 = (int *)FUN_c08df7b8();
        iVar3 = (**(code **)(*piVar2 + 0x58))(piVar2,iVar1);
      } while (iVar3 != 0);
    }
LAB_c08e14e4:
    iVar3 = 0;
    iVar4 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      iVar3 = *(int *)(param_1 + 0xc);
      iVar4 = *(int *)(param_1 + 0x10);
    }
    iVar1 = FUN_c08eb100(iVar1,iVar3,iVar4);
    *(int *)(param_1 + 0x20) = iVar1;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return 1;
}



/* c08e1534 FUN_c08e1534 */

/* Boundary evidence: original MIPS .pdata c08e1534..c08e1583. Semantic name remains unreviewed. */

undefined4 FUN_c08e1534(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_c08df7b8();
  iVar2 = *(int *)(iVar1 + 4);
  iVar1 = FUN_c08e0c04(*(int *)(param_1 + 4));
  if (iVar2 != iVar1) {
    FUN_c08e0e10(*(int *)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return 1;
}



/* c08e1584 FUN_c08e1584 */

/* Boundary evidence: original MIPS .pdata c08e1584..c08e15e3. Semantic name remains unreviewed. */

undefined4 FUN_c08e1584(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = FUN_c08e0c04(*(int *)(param_1 + 8));
  piVar2 = (int *)FUN_c08df7b8();
  (**(code **)(*piVar2 + 0xbc))(piVar2,uVar1,param_1,*(uint *)(param_1 + 0xc) & 1);
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 1;
}



/* c08e1614 HALInit */

/* Boundary evidence: original MIPS .pdata c08e1614..c08e16df. Semantic name remains unreviewed. */

undefined4 HALInit(undefined4 *param_1)

{
                    /* 0x11614  2  HALInit */
  FUN_c08df618(param_1);
  memset(param_1 + 0x26,0,0x80);
  param_1[0x26] = 0x80;
  param_1[0x2a] = 0x80c0;
  param_1[0x2d] = 3;
  param_1[0x2e] = 0x200;
  param_1[0x2f] = 0x89;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x36] = param_1[0x36] | 0x1000;
  param_1[0x30] = param_1[0x30] | 1;
  param_1[0x37] = param_1[0x37] | 0x80010000;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  return 1;
}



/* c08e16e0 FUN_c08e16e0 */

/* Boundary evidence: original MIPS .pdata c08e16e0..c08e189b. Semantic name remains unreviewed. */

int FUN_c08e16e0(int param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined1 auStack_90 [20];
  int local_7c;
  undefined1 auStack_78 [52];
  undefined4 local_44;
  
  if (((param_1 == 0) || (param_2 == (undefined4 *)0x0)) || (param_3 == (int *)0x0)) {
    return -0x7ff8ffa9;
  }
  if ((*(uint *)(param_1 + 4) & 0x1000) == 0) {
    iVar2 = FUN_c08df7b8();
    piVar1 = *(int **)(iVar2 + 4);
    if (piVar1 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar1 + 0x34))(piVar1);
      *param_2 = uVar3;
      *param_3 = piVar1[7];
      return 0;
    }
    piVar1 = (int *)FUN_c08df7b8();
    piVar4 = (int *)FUN_c08df7b8();
    iVar2 = *piVar4;
    uVar3 = (**(code **)(*piVar1 + 0xcc))(piVar1);
    iVar2 = (**(code **)(iVar2 + 0x24))(piVar4,auStack_90,uVar3);
    if (-1 < iVar2) {
      *param_3 = local_7c;
      piVar1 = (int *)FUN_c08df7b8();
      piVar4 = (int *)FUN_c08df7b8();
      iVar2 = *piVar4;
      uVar3 = (**(code **)(*piVar1 + 0xcc))(piVar1);
      iVar2 = (**(code **)(iVar2 + 0xd4))(piVar4,auStack_78,uVar3);
      if (iVar2 < 0) {
        *param_2 = *(undefined4 *)(&DAT_c08d2234 + local_7c * 4);
        return 0;
      }
      *param_2 = local_44;
      return 0;
    }
  }
  else {
    piVar1 = (int *)FUN_c08df7b8();
    iVar2 = (**(code **)(*piVar1 + 200))
                      (piVar1,*(undefined4 *)(param_1 + 100),param_1 + 0x44,param_3,param_2);
    if (-1 < iVar2) {
      return iVar2;
    }
  }
  return -0x7789fde8;
}



/* c08e189c FUN_c08e189c */

/* Boundary evidence: original MIPS .pdata c08e189c..c08e18e7. Semantic name remains unreviewed. */

undefined4 FUN_c08e189c(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_c08ea9bc();
    DisableThreadLibraryCalls(param_1);
    DAT_c0908b84 = param_1;
  }
  return 1;
}



/* c08e18e8 FUN_c08e18e8 */

/* Boundary evidence: original MIPS .pdata c08e18e8..c08e1963. Semantic name remains unreviewed. */

void FUN_c08e18e8(int param_1)

{
  if ((param_1 == 0x7b) || (DAT_c0908b80 == (code *)0x0)) {
    FUN_c08de154();
  }
  else {
    (*DAT_c0908b80)();
  }
  return;
}



/* c08e1964 FUN_c08e1964 */

/* Boundary evidence: original MIPS .pdata c08e1964..c08e196f. Semantic name remains unreviewed. */

undefined4 FUN_c08e1964(void)

{
  return 1;
}



/* c08e1970 FUN_c08e1970 */

/* Boundary evidence: original MIPS .pdata c08e1970..c08e1b3f. Semantic name remains unreviewed. */

void FUN_c08e1970(int param_1,uint *param_2,int param_3)

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
    local_24 = &DAT_c08fd908;
  }
  else if (sVar1 == 4) {
    local_28 = 4;
    if (*(int *)(param_1 + 0x1c) != 6) {
      local_28 = 3;
    }
    local_24 = &DAT_c08fd8f8;
  }
  else {
    iVar2 = (*DAT_c0908b50)(uVar4,&local_24,&local_28);
    if (iVar2 == 0) {
      local_28 = (*DAT_c0908b64)(param_2,param_3,0,0);
      if (local_28 != 0) {
        if (local_28 < 0x40000000) {
          uVar3 = local_28 << 2;
        }
        else {
          uVar3 = 0xffffffff;
        }
        local_24 = operator_new(uVar3);
      }
      if (local_24 == (undefined *)0x0) goto LAB_c08e1b08;
      local_28 = (*DAT_c0908b64)(param_2,param_3,local_28,local_24);
      (*DAT_c0908b54)(uVar4,local_24,local_28);
    }
    uVar5 = 1;
  }
LAB_c08e1b08:
  *(uint *)(param_1 + 0x10) = local_28;
  *(undefined4 *)(param_1 + 0x14) = uVar5;
  *(undefined **)(param_1 + 0xc) = local_24;
  *(uint *)(param_1 + 0x18) = uVar4;
  return;
}



/* c08e1b40 FUN_c08e1b40 */

undefined4 FUN_c08e1b40(int param_1,int param_2)

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
    puVar4 = &DAT_c08fd908;
    if (*(int *)(param_2 + 0x2c) == 6) {
      uVar2 = 4;
      goto LAB_c08e1bf4;
    }
  }
  else {
    if (sVar1 != 4) {
      if ((sVar1 == 2) || (sVar1 == 1)) {
        puVar4 = *(undefined **)(param_2 + 0x38);
      }
      goto LAB_c08e1bf4;
    }
    puVar4 = &DAT_c08fd8f8;
    if (*(int *)(param_2 + 0x2c) == 6) {
      uVar2 = 4;
      goto LAB_c08e1bf4;
    }
  }
  uVar2 = 3;
LAB_c08e1bf4:
  *(undefined4 *)(iVar3 + 0x10) = uVar2;
  *(undefined4 *)(iVar3 + 0x14) = 0;
  *(undefined **)(iVar3 + 0xc) = puVar4;
  *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(param_2 + 0x44);
  return 0;
}



/* c08e1c10 FUN_c08e1c10 */

/* Boundary evidence: original MIPS .pdata c08e1c10..c08e1c3f. Semantic name remains unreviewed. */

undefined4 FUN_c08e1c10(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x38))();
  }
  return 0;
}



/* c08e1c40 FUN_c08e1c40 */

/* Boundary evidence: original MIPS .pdata c08e1c40..c08e1c6b. Semantic name remains unreviewed. */

void FUN_c08e1c40(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x3c))();
  }
  return;
}



/* c08e1c6c FUN_c08e1c6c */

/* Boundary evidence: original MIPS .pdata c08e1c6c..c08e1de7. Semantic name remains unreviewed. */

void FUN_c08e1c6c(double param_1,double param_2,int *param_3,undefined4 param_4,int param_5,
                 uint param_6,int *param_7,undefined4 param_8,undefined4 *param_9)

{
  int iVar1;
  
  if (param_5 == 8) {
    if ((*param_7 != 0x183a) && (*param_7 != 0x1839)) {
      (**(code **)(*param_3 + 0x40))(param_3,param_4,8,param_6,param_7,param_8,param_9);
    }
  }
  else if (param_5 == 0x183a) {
    FUN_c08fc260(param_9);
  }
  else if (param_5 == 0x1839) {
    iVar1 = FUN_c08fc274(param_6,*param_7);
    if (iVar1 != 0) {
      FUN_c08f30ac(param_1,param_2,param_6,*param_7);
    }
  }
  else {
    (**(code **)(*param_3 + 0x40))();
  }
  return;
}



/* c08e1de8 FUN_c08e1de8 */

/* Boundary evidence: original MIPS .pdata c08e1de8..c08e1df3. Semantic name remains unreviewed. */

undefined4 FUN_c08e1de8(void)

{
  return 1;
}



/* c08e1df4 FUN_c08e1df4 */

/* Boundary evidence: original MIPS .pdata c08e1df4..c08e1e33. Semantic name remains unreviewed. */

void FUN_c08e1df4(void)

{
  undefined4 *puVar1;
  
  FUN_c08ecd48();
  puVar1 = (undefined4 *)FUN_c08e18e8(0x7b);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  return;
}



/* c08e1e34 FUN_c08e1e34 */

/* Boundary evidence: original MIPS .pdata c08e1e34..c08e1e6f. Semantic name remains unreviewed. */

void FUN_c08e1e34(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x78))(param_1);
  if (iVar1 != 0) {
    param_1[5] = 0;
  }
  return;
}



/* c08e1e70 FUN_c08e1e70 */

/* Boundary evidence: original MIPS .pdata c08e1e70..c08e1e93. Semantic name remains unreviewed. */

void FUN_c08e1e70(int param_1)

{
  (*DAT_c0908b74)(*(undefined4 *)(param_1 + 0x14));
  return;
}



/* c08e1e94 FUN_c08e1e94 */

/* Boundary evidence: original MIPS .pdata c08e1e94..c08e1ee7. Semantic name remains unreviewed. */

void FUN_c08e1e94(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_c0908b70)(*(int *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                          *(undefined4 *)(param_1 + 0xc),
                          *(undefined4 *)
                           (&DAT_c08d2870 + *(int *)(*(int *)(param_1 + 4) + 0x1c) * 4));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  return;
}



/* c08e1ee8 FUN_c08e1ee8 */

/* Boundary evidence: original MIPS .pdata c08e1ee8..c08e1f97. Semantic name remains unreviewed. */

int FUN_c08e1ee8(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_18 [2];
  
  iVar1 = (**(code **)(*param_1 + 0x10))
                    (param_1,local_18,param_2,param_3,*(undefined4 *)(&LAB_c08d2894 + param_4 * 4),2
                    );
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = (*DAT_c0908b78)(local_18[0],param_2,param_3,param_4);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    *(int *)(local_18[0] + 0x48) = iVar1;
  }
  return iVar1;
}



/* c08e1f98 FUN_c08e1f98 */

/* Boundary evidence: original MIPS .pdata c08e1f98..c08e1fdb. Semantic name remains unreviewed. */

void FUN_c08e1f98(undefined4 *param_1)

{
  (*DAT_c0908b74)(param_1[0x12]);
  (**(code **)*param_1)(param_1,1);
  return;
}



/* c08e1fdc FUN_c08e1fdc */

/* Boundary evidence: original MIPS .pdata c08e1fdc..c08e2003. Semantic name remains unreviewed. */

void FUN_c08e1fdc(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 0x18))();
  return;
}



/* c08e2004 FUN_c08e2004 */

/* Boundary evidence: original MIPS .pdata c08e2004..c08e213f. Semantic name remains unreviewed. */

undefined4
FUN_c08e2004(int param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 param_5,
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
  
  FUN_c08edc74(&local_60,param_2,(int *)0x0,(int *)0x0);
  FUN_c08edc74(&local_b0,param_3,(int *)0x0,(int *)0x0);
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 == (int *)0x0) {
    FUN_c08eb2b0(auStack_ac);
    FUN_c08eb2b0(auStack_5c);
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
    FUN_c08eb2b0(auStack_ac);
    FUN_c08eb2b0(auStack_5c);
  }
  return uVar4;
}



/* c08e2140 FUN_c08e2140 */

/* Boundary evidence: original MIPS .pdata c08e2140..c08e21cb. Semantic name remains unreviewed. */

undefined4
FUN_c08e2140(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_410 [1024];
  
  if (((param_5 < 0x101) &&
      (uVar1 = (*DAT_c0908b48)(param_2,param_4,param_5,auStack_410), uVar1 != 0)) &&
     (iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,auStack_410,param_4 & 0xffff,uVar1 & 0xffff),
     -1 < iVar2)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* c08e21cc FUN_c08e21cc */

/* Boundary evidence: original MIPS .pdata c08e21cc..c08e25db. Semantic name remains unreviewed. */

undefined4
FUN_c08e21cc(int *param_1,int param_2,int param_3,int *param_4,undefined4 param_5,uint param_6)

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
  FUN_c08edd5c(aiStack_418,*(int *)(param_2 + 4));
  FUN_c08edc74(&local_3a0,param_1,(int *)0x0,(int *)0x0);
  local_3f4 = local_3a0;
  local_3c8 = param_5;
  local_3d8 = *param_4;
  piVar8 = (int *)param_1[2];
  uVar7 = 1;
  local_3d0 = (uint)CONCAT11((&DAT_c08fd918)[param_6 >> 8 & 0xf],(&DAT_c08fd918)[param_6 & 0xf]);
  DAT_c0908b88 = 0;
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
      iVar2 = (*DAT_c0908b5c)(param_4);
    }
    local_3e8 = iVar2;
    if (iVar2 == 0) {
      FUN_c08eb2b0(auStack_39c);
      FUN_c08eddbc(aiStack_418);
      return 0;
    }
  }
  iVar2 = (**(code **)(*piVar8 + 4))(piVar8,&uStack_3f8);
  if (-1 < iVar2) {
    (*DAT_c0908b68)(param_2);
    local_444 = local_42c;
    uVar9 = local_42c;
    iVar2 = local_430;
    iVar5 = local_430;
    do {
      iVar3 = (*DAT_c0908b44)(param_2,&local_440);
      iVar10 = local_43c;
      if (local_43c == 0) break;
      if ((local_440 & 1) == 0) {
        iVar4 = FUN_c08edde4(aiStack_418,iVar5,local_444,*local_438,local_438[1]);
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
          iVar4 = FUN_c08edde4(aiStack_418,*piVar8,piVar8[1],piVar8[2],piVar8[3]);
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
        iVar10 = FUN_c08edde4(aiStack_418,local_438[iVar4 * 2],(local_438 + iVar4 * 2)[1],iVar2,
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
LAB_c08e2558:
      iVar5 = FUN_c08ee128(aiStack_418,&uStack_3f8,piVar6,local_420);
    }
    else {
      if (*(char *)(local_430 + 0x14) == '\x01') {
        piVar6 = (int *)(local_430 + 4);
        goto LAB_c08e2558;
      }
      local_350 = 0;
      iVar10 = 1;
      iVar5 = local_424;
      while( true ) {
        piVar6 = aiStack_34c;
        while (local_350 != 0) {
          local_350 = local_350 + -1;
          iVar5 = FUN_c08ee128(aiStack_418,&uStack_3f8,piVar6,piVar8);
          piVar6 = piVar6 + 4;
          if (iVar5 < 0) goto LAB_c08e256c;
        }
        if (iVar10 == 0) break;
        iVar10 = (*DAT_c0908b4c)(iVar2,0x324,&local_350);
      }
    }
LAB_c08e256c:
    iVar2 = (**(code **)(*piVar8 + 8))(piVar8,&uStack_3f8);
    if (((-1 < iVar5) && (-1 < iVar2)) && (!bVar1)) goto LAB_c08e259c;
  }
  uVar7 = 0;
LAB_c08e259c:
  FUN_c08eb2b0(auStack_39c);
  FUN_c08eddbc(aiStack_418);
  return uVar7;
}



/* c08e25dc FUN_c08e25dc */

/* Boundary evidence: original MIPS .pdata c08e25dc..c08e289f. Semantic name remains unreviewed. */

undefined4
FUN_c08e25dc(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,uint *param_5)

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
  
  FUN_c08edc74(&local_c8,param_3,(int *)0x0,(int *)0x0);
  FUN_c08edc74(&local_78,param_2,param_3,&local_c8);
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
    iVar5 = *(int *)(&LAB_c08d284c + iVar6 * 4) * *(int *)(local_c8 + 0x2c);
    iVar3 = iVar5 + 7;
    if (iVar3 < 0) {
      iVar3 = iVar5 + 0xe;
    }
    uVar7 = (iVar3 >> 3) + 3U & 0xfffffffc;
    iVar5 = *(int *)(local_c8 + 0x30) * uVar7 + 0x4c;
    if ((((param_5 != (uint *)0x0) && (param_5[1] != 1)) && (*(short *)((int)param_5 + 10) != 8)) &&
       (*(short *)((int)param_5 + 10) != 4)) {
      iVar3 = (*DAT_c0908b64)(param_5,2,0,0);
      iVar5 = iVar3 * 4 + iVar5;
    }
  }
  else {
    uVar7 = *(uint *)(local_c8 + 8);
  }
  iVar5 = (*DAT_c0908b58)(param_1,iVar5);
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
    FUN_c08eae34(iVar5,*(undefined4 *)(local_c8 + 0x2c),*(undefined4 *)(local_c8 + 0x30),uVar2,uVar7
                 ,iVar6);
    if (bVar1) {
      FUN_c08ecdc4((int *)param_5,aiStack_dc,&uStack_e0,&iStack_e4);
      if ((param_5 != (uint *)0x0) && (param_5[1] != 1)) {
        FUN_c08e1970(iVar5,param_5,2);
        FUN_c08e1970(local_c8,param_5,1);
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
      FUN_c08ea8b8((int *)param_2[2],&iStack_120);
    }
  }
  FUN_c08eb2b0(auStack_74);
  FUN_c08eb2b0(auStack_c4);
  return uVar4;
}



/* c08e28a0 FUN_c08e28a0 */

/* Boundary evidence: original MIPS .pdata c08e28a0..c08e29d3. Semantic name remains unreviewed. */

size_t FUN_c08e28a0(int param_1,size_t param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  piVar1 = (int *)FUN_c08e18e8(param_1);
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



/* c08e29d4 FUN_c08e29d4 */

/* Boundary evidence: original MIPS .pdata c08e29d4..c08e2d13. Semantic name remains unreviewed. */

int * FUN_c08e29d4(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
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
  piVar2 = (int *)FUN_c08e18e8(in_stack_00000028);
  if (piVar2 == (int *)0x0) {
LAB_c08e2a14:
    piVar2 = (int *)0x0;
  }
  else {
    if (DAT_c08fd92c != 0) {
      iVar3 = FUN_c08ecc84();
      if (iVar3 == 0) goto LAB_c08e2a14;
      DAT_c08fd92c = 0;
      bVar1 = true;
    }
    if ((*(short *)(param_1 + 0x46) == 0x18) && (in_stack_0000001c != (uint *)0x0)) {
      iVar3 = (**(code **)(*piVar2 + 0x2c))
                        (piVar2,*(undefined4 *)(param_1 + 0xc0),in_stack_0000001c + 0x49);
      if (iVar3 < 0) goto LAB_c08e2a14;
      iVar3 = *(int *)(piVar2[1] + 0x1c);
      puVar4 = FUN_c08dcd14();
      FUN_c08ef8ec(iVar3,(int)puVar4);
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
    if (PTR_FUN_c0906fb4 != (undefined *)0x0) {
      in_stack_00000014[0xd] = 7;
    }
    if (DAT_c090c6e0 != 0) {
      in_stack_00000014[0xd] = in_stack_00000014[0xd] | 0x10;
    }
    if ((bVar1) && (in_stack_0000001c != (uint *)0x0)) {
      local_5c = 0;
      puVar5 = (uint *)(**(code **)(*piVar2 + 0x74))(piVar2);
      local_60[0] = 0;
      (**(code **)(*piVar2 + 0x24))(piVar2,auStack_58,*(undefined4 *)piVar2[4]);
      (**(code **)(*piVar2 + 0x20))(piVar2,&local_5c,local_60);
      DAT_c0908b90 = FUN_c08fc350((int)auStack_58,puVar5,local_5c,(uint)local_60[0]);
    }
    if ((8 < *(uint *)(param_1 + 0xa8)) && (DAT_c0908b8c != 0)) {
      DAT_c0908b94 = 0x1000000;
    }
    if (7 < *(uint *)(param_1 + 0xa8)) {
      if (DAT_c0908b90 != 0) {
        DAT_c0908b94 = DAT_c0908b94 | 0x100;
      }
      DAT_c0908b94 = DAT_c0908b94 | 0x400;
    }
    uVar6 = (**(code **)(*piVar2 + 0x44))(piVar2);
    in_stack_00000014[0xc] = (uVar6 | DAT_c0908b94) & 0x1000700;
    if (in_stack_0000001c != (uint *)0x0) {
      uVar6 = (**(code **)(*piVar2 + 0x44))(piVar2);
      *in_stack_0000001c = uVar6 | DAT_c0908b94;
    }
  }
  return piVar2;
}



/* c08e2d14 FUN_c08e2d14 */

/* Boundary evidence: original MIPS .pdata c08e2d14..c08e2fe7. Semantic name remains unreviewed. */

undefined4 FUN_c08e2d14(undefined4 param_1,undefined4 *param_2)

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



/* c08e2fe8 FUN_c08e2fe8 */

/* Boundary evidence: original MIPS .pdata c08e2fe8..c08e2ff3. Semantic name remains unreviewed. */

undefined4 FUN_c08e2fe8(void)

{
  return 1;
}



/* c08e2ff4 FUN_c08e2ff4 */

/* Boundary evidence: original MIPS .pdata c08e2ff4..c08e2fff. Semantic name remains unreviewed. */

undefined4 FUN_c08e2ff4(void)

{
  return 1;
}



/* c08e3000 FUN_c08e3000 */

/* Boundary evidence: original MIPS .pdata c08e3000..c08e3067. Semantic name remains unreviewed. */

void FUN_c08e3000(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  FUN_c08e18e8(0);
  puVar1 = FUN_c08dcd14();
  if (puVar1 != (undefined4 *)0x0) {
    *param_1 = *puVar1;
    *param_2 = puVar1[1];
    *param_3 = puVar1[2];
  }
  return;
}



/* c08e3068 FUN_c08e3068 */

/* Boundary evidence: original MIPS .pdata c08e3068..c08e31fb. Semantic name remains unreviewed. */

undefined4 FUN_c08e3068(int param_1,size_t param_2,void *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  DAT_c0908b58 = *param_4;
  DAT_c0908b5c = param_4[1];
  DAT_c0908b60 = param_4[2];
  DAT_c0908b4c = param_4[3];
  DAT_c0908b48 = param_4[4];
  DAT_c0908b68 = param_4[5];
  DAT_c0908b44 = param_4[6];
  DAT_c0908b40 = param_4[7];
  DAT_c0908b64 = param_4[8];
  DAT_c0908b70 = param_4[9];
  DAT_c0908b74 = param_4[10];
  DAT_c0908b78 = param_4[0xb];
  DAT_c0908b6c = param_4[0xc];
  DAT_c0908b50 = param_4[0xd];
  DAT_c0908b54 = param_4[0xe];
  DAT_c0908b7c = param_4[0xf];
  if ((param_1 == 0x40001) && (((param_2 == 0x74 || (param_2 == 0x78)) || (param_2 == 0x7c)))) {
    memcpy(param_3,&PTR_FUN_c08d27c8,param_2);
    if (param_2 == 0x7c) {
      *(undefined4 *)((int)param_3 + 0x6c) = DAT_c090c6e0;
      *(undefined **)((int)param_3 + 0x70) = PTR_FUN_c0906fb4;
    }
    else if (param_2 == 0x78) {
      *(undefined4 *)((int)param_3 + 0x6c) = DAT_c090c6e0;
    }
    DAT_c0908b8c = FUN_c08f29b0(FUN_c08e3000);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c08e31fc FUN_c08e31fc */

/* Boundary evidence: original MIPS .pdata c08e31fc..c08e3a67. Semantic name remains unreviewed. */

undefined4
FUN_c08e31fc(int *param_1,int *param_2,int *param_3,int param_4,uint *param_5,int *param_6,
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
  FUN_c08edc74((int *)&local_3f0,param_1,(int *)0x0,(int *)0x0);
  FUN_c08edc74((int *)&local_440,param_2,param_1,(int *)&local_3f0);
  FUN_c08edc74(&local_3a0,param_3,(int *)0x0,(int *)0x0);
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
        FUN_c08eaf5c((int)local_440,local_440[0xc],local_440[0xb],iVar1);
        local_484 = *param_7;
        local_488 = param_7[1];
        local_47c = param_7[2];
        local_480 = param_7[3];
        param_7 = &local_488;
      }
      else {
        FUN_c08eaf5c((int)local_440,local_440[0xb],local_440[0xc],iVar1);
      }
    }
    local_4e0 = local_440;
    local_4d0 = param_7;
    if ((param_7 == (int *)0x0) || (param_6 == (int *)0x0)) goto LAB_c08e3558;
    if ((param_6[2] - *param_6 != param_7[2] - *param_7) ||
       (param_6[3] - param_6[1] != param_7[3] - param_7[1])) {
      param_12 = param_12 | 8;
    }
  }
  DAT_c0908b88 = (uint *)0x0;
  if (((param_5 != (uint *)0x0) && (local_440 != (undefined4 *)0x0)) &&
     (FUN_c08e1970((int)local_3f0,param_5,2), param_5[1] == 4)) {
    DAT_c0908b88 = param_5;
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
    if (param_9 == (int *)0x0) goto LAB_c08e3558;
    if (*param_9 == -1) {
      iVar1 = param_9[1];
      if (iVar1 == 0) {
        iVar1 = (*DAT_c0908b5c)(param_9);
      }
      local_4d8 = iVar1;
      if (iVar1 == 0) goto LAB_c08e3558;
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
                           *(undefined4 *)(&LAB_c08d2894 + local_510[0xb] * 4),2);
        if (iVar1 < 0) {
LAB_c08e3558:
          FUN_c08eb2b0(auStack_39c);
          FUN_c08eb2b0(auStack_43c);
          FUN_c08eb2b0(auStack_3ec);
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
        iVar1 = FUN_c08e31fc(&local_478,local_510,(int *)0x0,0,(uint *)0x0,&local_508,param_7,
                             (int *)0x0,(int *)0x0,0,0xcccc,0,1,0xff0000);
        if (iVar1 == 0) {
          if (local_514 != (undefined4 *)0x0) {
            (**(code **)*local_514)(local_514,1);
          }
          goto LAB_c08e3558;
        }
        local_4d0 = &local_508;
        local_4e0 = local_514;
      }
    }
  }
  else if (local_4e0 != (undefined4 *)0x0) {
    FUN_c08ecdc4((int *)param_5,local_4ac + 2,local_4ac + 1,local_4ac);
  }
  iVar1 = 0;
  if ((param_5 != (uint *)0x0) && (local_4e0 != (undefined4 *)0x0)) {
    FUN_c08e1970((int)local_4e0,param_5,1);
  }
  FUN_c08e1b40((int)&uStack_4e8,(int)local_48c);
  piVar8 = local_490;
  local_4cc = (undefined1 *)0x0;
  if ((param_4 != 0) && (*(char *)(param_4 + 0x14) == '\x01')) {
    local_4cc = (undefined1 *)(param_4 + 4);
  }
  iVar2 = (**(code **)(*local_490 + 4))(local_490,&uStack_4e8);
  if (-1 < iVar2) {
    if ((param_4 == 0) || (*(char *)(param_4 + 0x14) != '\x03')) {
      iVar1 = FUN_c08e2d14(piVar8,&uStack_4e8);
    }
    else {
      (*DAT_c0908b60)(param_4,1,0,uVar7,0);
      local_350 = 0;
      iVar2 = 1;
      while( true ) {
        puVar4 = auStack_34c;
        while (local_350 != 0) {
          local_350 = local_350 + -1;
          local_4cc = puVar4;
          iVar1 = FUN_c08e2d14(piVar8,&uStack_4e8);
          puVar4 = puVar4 + 0x10;
          if (iVar1 < 0) goto LAB_c08e39dc;
        }
        if (iVar2 == 0) break;
        iVar2 = (*DAT_c0908b4c)(param_4,0x324,&local_350);
      }
    }
LAB_c08e39dc:
    iVar2 = (**(code **)(*piVar8 + 8))(piVar8,&uStack_4e8);
    if (local_514 != (undefined4 *)0x0) {
      (**(code **)*local_514)(local_514,1);
    }
    if ((-1 < iVar1) && (-1 < iVar2)) goto LAB_c08e3a20;
  }
  uVar5 = 0;
LAB_c08e3a20:
  FUN_c08eb2b0(auStack_39c);
  FUN_c08eb2b0(auStack_43c);
  FUN_c08eb2b0(auStack_3ec);
  return uVar5;
}



/* c08e3a68 FUN_c08e3a68 */

/* Boundary evidence: original MIPS .pdata c08e3a68..c08e3ad3. Semantic name remains unreviewed. */

void FUN_c08e3a68(int *param_1,int *param_2,int *param_3,int param_4,uint *param_5,
                 undefined4 param_6,int *param_7,int *param_8,int *param_9,int *param_10,
                 undefined4 param_11,uint param_12,undefined4 param_13,uint param_14)

{
  FUN_c08e31fc(param_1,param_2,param_3,param_4,param_5,param_7,param_8,param_9,param_10,param_11,
               param_12,param_14,param_13,0xff0000);
  return;
}



/* c08e3ad4 FUN_c08e3ad4 */

/* Boundary evidence: original MIPS .pdata c08e3ad4..c08e3b43. Semantic name remains unreviewed. */

void FUN_c08e3ad4(int *param_1,int *param_2,int param_3,uint *param_4,int *param_5,int *param_6,
                 int param_7)

{
  int local_10 [2];
  
  local_10[0] = param_7;
  FUN_c08e31fc(param_1,param_2,(int *)0x0,param_3,param_4,param_5,param_6,(int *)0x0,local_10,0,
               0xcccc,4,1,0xff0000);
  return;
}



/* c08e3b44 FUN_c08e3b44 */

/* Boundary evidence: original MIPS .pdata c08e3b44..c08e3bfb. Semantic name remains unreviewed. */

void FUN_c08e3b44(int *param_1,int *param_2,int *param_3,int param_4,uint *param_5,int *param_6,
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
  FUN_c08e31fc(param_1,param_2,param_3,param_4,param_5,param_6,&local_18,param_8,param_9,param_10,
               param_11,0,1,0xff0000);
  return;
}



/* c08e3bfc FUN_c08e3bfc */

/* Boundary evidence: original MIPS .pdata c08e3bfc..c08e3c6f. Semantic name remains unreviewed. */

void FUN_c08e3bfc(int *param_1,int param_2,int *param_3,undefined4 param_4,uint param_5)

{
  FUN_c08e3b44(param_1,(int *)0x0,(int *)0x0,param_2,(uint *)0x0,(int *)(param_2 + 4),(int *)0x0,
               (int *)0x0,param_3,param_4,
               (uint)CONCAT11((&DAT_c08fd918)[param_5 >> 8 & 0xf],(&DAT_c08fd918)[param_5 & 0xf]));
  return;
}



/* c08e3c70 FUN_c08e3c70 */

/* Boundary evidence: original MIPS .pdata c08e3c70..c08e591f. Semantic name remains unreviewed. */

undefined4 FUN_c08e3c70(undefined4 param_1,int param_2)

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
      if ((*(int *)(&LAB_c08d284c + *(int *)(iVar26 + 0x1c) * 4) == 0x20) &&
         (((local_208 | local_214 | local_204) & 0xff000000) == 0)) {
        local_21c = 0xff000000;
      }
    }
    else if ((*(int *)(iVar26 + 0x10) == 4) &&
            (8 < *(int *)(&LAB_c08d284c + *(int *)(iVar26 + 0x1c) * 4))) {
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
    goto LAB_c08e4394;
  }
  piVar27 = *(int **)(param_2 + 0x18);
  iVar26 = piVar27[2] - *piVar27;
  iVar30 = piVar27[3] - piVar27[1];
  if (iVar26 < local_1dc) {
    local_14c = 1;
    iVar13 = local_1dc;
    iVar21 = iVar26;
LAB_c08e4108:
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
      goto LAB_c08e4108;
    }
    local_1d0 = local_220;
    local_1e8 = local_220;
    local_210 = local_220;
  }
  if (iVar30 < local_148) {
    bVar7 = true;
    iVar26 = local_148;
    iVar13 = iVar30;
LAB_c08e4194:
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
      goto LAB_c08e4194;
    }
    local_1d4 = local_220;
    local_144 = local_220;
  }
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar35 = FUN_c08ee774(&local_48,*(int **)(param_2 + 0x1c),piVar23);
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
LAB_c08e42b0:
      local_210 = local_210 + local_1d0;
LAB_c08e42b4:
      iVar33 = iVar33 + 1;
    }
    else {
      if (local_14c == 0) goto LAB_c08e42b4;
      if (-1 < (int)local_210) goto LAB_c08e42b0;
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
LAB_c08e4394:
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
       (FUN_c08eec6c((int *)&local_1c8,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
                     *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar33,iVar26),
       local_134 = local_1ac, uVar20 != 0)) &&
      (iVar43 = *(int *)(param_2 + 8), 8 < *(int *)(&LAB_c08d284c + *(int *)(iVar43 + 0x1c) * 4)))
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
    FUN_c08ef174((int *)&local_b8,iVar13,*(int *)(param_2 + 0x34),*(int *)(param_2 + 0x38),&local_38
                );
  }
  if (*(int *)(param_2 + 0xc) == 0) {
    local_104 = (byte *)0x0;
  }
  else {
    FUN_c08eec6c((int *)&local_108,*(int *)(param_2 + 0xc),*(int *)(param_2 + 0x34),
                 *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x2c),iVar33,iVar26);
  }
  iVar33 = *(int *)(param_2 + 4);
  local_164 = *(int *)(&LAB_c08d284c + *(int *)(iVar33 + 0x1c) * 4);
  if (local_164 < 8) {
    FUN_c08eec6c((int *)&local_188,iVar33,iVar47,iVar41,piVar23,iVar39,iVar35);
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
LAB_c08e5758:
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
                    goto LAB_c08e4ec0;
                  }
                  goto LAB_c08e5024;
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
            else if (uVar22 != 0xaa) goto LAB_c08e5024;
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
LAB_c08e4ec0:
                uVar32 = uVar12 & uVar31;
              }
              else if (uVar22 != 0xcc) goto LAB_c08e5024;
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
LAB_c08e5024:
                uVar32 = FUN_c08ee588(uVar20,uVar31,local_84,uVar22,(byte)iVar33);
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
LAB_c08e51c4:
              iVar43 = 1;
LAB_c08e51c8:
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
                  goto LAB_c08e51c8;
                }
                if (uVar31 != 0xff) goto LAB_c08e51c4;
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
              uVar31 = FUN_c08ee68c(uVar32,*puVar17);
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
                  uVar20 = FUN_c08ee68c(local_194,*puVar17);
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
          goto LAB_c08e5758;
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



/* c08e5920 FUN_c08e5920 */

/* Boundary evidence: original MIPS .pdata c08e5920..c08e61fb. Semantic name remains unreviewed. */

undefined4 FUN_c08e5920(undefined4 param_1,int param_2)

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
  FUN_c08ee6ec(*(int *)(param_2 + 4),(int)auStack_78,(int *)auStack_88);
  iVar16 = iVar20;
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar20 = FUN_c08ee774(&local_98,*(int **)(param_2 + 0x1c),*(int **)(param_2 + 0x14));
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
  iVar24 = *(int *)(&LAB_c08d284c + *(int *)(iVar20 + 0x1c) * 4);
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
  FUN_c08eec6c((int *)&local_130,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
               *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar21,iVar22 + -1);
  FUN_c08eec6c((int *)&local_f0,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
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
            uVar5 = FUN_c08ee804(uVar5,uVar6,0x100 - uVar8,uVar8,auStack_78,auStack_88);
          }
          uVar6 = local_fc;
          if (local_fc != local_bc) {
            uVar6 = FUN_c08ee804(local_fc,local_bc,0x100 - uVar8,uVar8,auStack_78,auStack_88);
          }
          do {
            iVar22 = local_b0;
            uVar7 = local_f8;
            iVar21 = local_12c;
            iVar20 = local_ec;
            if (local_160 <= iVar9) goto LAB_c08e6194;
            iVar9 = iVar9 + 1;
            uVar7 = uVar5;
            if (uVar5 != uVar6) {
              uVar7 = FUN_c08ee804(uVar5,uVar6,0x100 - (uVar13 >> 8),uVar13 >> 8,auStack_78,
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
LAB_c08e6194:
      uVar13 = local_150 + iVar26 & 0xffff0000;
      local_150 = local_150 + iVar26 & 0xffff;
      local_158 = local_158 + -1;
      puVar23 = local_b4;
    } while (local_158 != 0);
  }
  return 0;
}



/* c08e61fc FUN_c08e61fc */

/* Boundary evidence: original MIPS .pdata c08e61fc..c08e6b07. Semantic name remains unreviewed. */

undefined4 FUN_c08e61fc(undefined4 param_1,int param_2)

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
  FUN_c08ee6ec(*(int *)(param_2 + 4),(int)auStack_48,(int *)auStack_58);
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar12 = FUN_c08ee774(&local_38,*(int **)(param_2 + 0x1c),*(int **)(param_2 + 0x14));
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
  iVar10 = *(int *)(&LAB_c08d284c + *(int *)(iVar5 + 0x1c) * 4);
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
  FUN_c08eec6c((int *)&local_f8,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
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
                      FUN_c08eeb8c((ushort *)&local_bc,local_c4,0x80,0x80,auStack_48,auStack_58);
                      uVar3 = local_c0;
                      puVar14 = local_cc;
                    }
                    else if (iVar10 == 0x18) {
                      FUN_c08eebcc((byte *)&local_bc,local_c4,0x80,0x80,auStack_48,auStack_58);
                      uVar3 = local_c0;
                      puVar14 = local_cc;
                    }
                    else if (iVar10 == 0x20) {
                      FUN_c08eec30(&local_bc,local_c4,0x80,0x80,auStack_48,auStack_58);
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
                  FUN_c08eeb8c((ushort *)local_100,local_bc,local_b8,iVar7,auStack_48,auStack_58);
                }
                else if (iVar10 == 0x18) {
                  FUN_c08eebcc((byte *)local_100,local_bc,local_b8,iVar7,auStack_48,auStack_58);
                }
                else if (iVar10 == 0x20) {
                  FUN_c08eec30(local_100,local_bc,local_b8,iVar7,auStack_48,auStack_58);
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



/* c08e6b08 FUN_c08e6b08 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c08e6b08..c08e8aff. Semantic name remains unreviewed. */

undefined4 FUN_c08e6b08(undefined4 param_1,int param_2)

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
      if ((*(int *)(&LAB_c08d284c + *(int *)(iVar30 + 0x1c) * 4) == 0x20) &&
         ((((uint)local_274 | (uint)local_270 | (uint)local_210) & 0xff000000) == 0)) {
        local_260 = (byte *)0xff000000;
      }
    }
    else if ((*(int *)(iVar30 + 0x10) == 4) &&
            (8 < *(int *)(&LAB_c08d284c + *(int *)(iVar30 + 0x1c) * 4))) {
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
LAB_c08e7250:
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
         (FUN_c08eeea0((int *)&local_208,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
                       *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar39,iVar30),
         local_1a0 = local_1ec, uVar29 != 0)) &&
        (iVar44 = *(int *)(param_2 + 8), 8 < *(int *)(&LAB_c08d284c + *(int *)(iVar44 + 0x1c) * 4)))
       && ((*(int *)(iVar44 + 0x10) == 4 || (*(int *)(iVar44 + 0x10) == 3)))) {
      puVar23 = *(uint **)(iVar44 + 0xc);
      local_1a0 = (byte *)(puVar23[2] | puVar23[1] | *puVar23);
    }
    if (*(int *)(param_2 + 0x10) != 0) {
      FUN_c08ef174((int *)&local_a8,*(int *)(param_2 + 0x10),*(int *)(param_2 + 0x34),
                   *(int *)(param_2 + 0x38),&local_38);
    }
    if ((bVar22 == bVar24) || (*(int *)(param_2 + 0xc) != 0)) {
      if (*(int *)(param_2 + 0xc) == 0) {
        local_f4 = (byte *)0x0;
      }
      else {
        FUN_c08eec6c((int *)&local_f8,*(int *)(param_2 + 0xc),*(int *)(param_2 + 0x34),
                     *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x2c),iVar39,iVar30);
      }
      if ((bVar22 == bVar24) || (local_f8 != (byte *)0x0)) {
        iVar39 = *(int *)(param_2 + 4);
        local_16c = *(int *)(&LAB_c08d284c + *(int *)(iVar39 + 0x1c) * 4);
        if (local_16c < 8) {
LAB_c08e7538:
          FUN_c08eeea0((int *)&local_190,iVar39,(int)local_264,iVar47,piVar28,iVar43,iVar41);
          bVar4 = false;
        }
        else {
          if (*(int *)(iVar39 + 0x38) != 0) {
            local_13c = 1;
            goto LAB_c08e7538;
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
                  goto LAB_c08e7840;
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
LAB_c08e7840:
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
                      puVar15 = (undefined1 *)FUN_c08ef00c((int)&local_208);
                      local_1d4 = CONCAT31(local_1d4._1_3_,*puVar15);
                      uVar29 = local_1d4;
                    }
                    else if (local_1e4 == 0x10) {
                      puVar16 = (undefined2 *)FUN_c08ef00c((int)&local_208);
                      local_1d4 = CONCAT22(local_1d4._2_2_,*puVar16);
                      uVar29 = local_1d4;
                    }
                    else if (local_1e4 == 0x18) {
                      pbVar38 = (byte *)FUN_c08ef00c((int)&local_208);
                      uVar29 = ((uint)pbVar38[2] * 0x100 + (uint)pbVar38[1]) * 0x100 +
                               (uint)*pbVar38;
                    }
                    else if (local_1e4 == 0x20) {
                      puVar23 = (uint *)FUN_c08ef00c((int)&local_208);
                      uVar29 = *puVar23;
                    }
                    local_1b0 = local_1b0 + local_1c8;
                    goto LAB_c08e7b24;
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
LAB_c08e7b24:
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
LAB_c08e891c:
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
                      pbVar17 = (byte *)FUN_c08ef00c((int)&local_190);
                      *pbVar17 = bVar36;
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x10) {
                      puVar16 = (undefined2 *)FUN_c08ef00c((int)&local_190);
                      *puVar16 = (short)uVar29;
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x18) {
                      puVar15 = (undefined1 *)FUN_c08ef00c((int)&local_190);
                      *puVar15 = (char)local_1d4;
                      puVar15[1] = (char)(local_1d4 >> 8);
                      puVar15[2] = (char)(local_1d4 >> 0x10);
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x20) {
                      puVar23 = (uint *)FUN_c08ef00c((int)&local_190);
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
                      puVar15 = (undefined1 *)FUN_c08ef00c((int)&local_190);
                      local_15c = CONCAT31(local_15c._1_3_,*puVar15);
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x10) {
                      puVar16 = (undefined2 *)FUN_c08ef00c((int)&local_190);
                      local_15c = CONCAT22(local_15c._2_2_,*puVar16);
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x18) {
                      pbVar17 = (byte *)FUN_c08ef00c((int)&local_190);
                      local_15c = ((uint)pbVar17[2] * 0x100 + (uint)pbVar17[1]) * 0x100 +
                                  (uint)*pbVar17;
                      uVar29 = local_1d4;
                    }
                    else if (local_16c == 0x20) {
                      puVar23 = (uint *)FUN_c08ef00c((int)&local_190);
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
LAB_c08e807c:
                        uVar37 = ~uVar37;
                      }
                      else if (uVar27 == 0) {
                        uVar37 = 0;
                      }
                      else {
                        if (uVar27 == 0x11) {
                          uVar37 = local_15c | uVar29;
                          goto LAB_c08e807c;
                        }
                        if (uVar27 == 0x22) {
                          uVar37 = ~uVar29 & local_15c;
                        }
                        else if (uVar27 == 0x33) {
                          uVar37 = ~uVar29;
                        }
                        else {
                          if (uVar27 != 0x44) goto LAB_c08e81c8;
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
                        goto LAB_c08e80bc;
                      }
LAB_c08e80d0:
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
                          if (uVar27 == 0xc0) goto LAB_c08e80d0;
                          uVar14 = 0xcc;
LAB_c08e80bc:
                          uVar37 = uVar29;
                          if (uVar27 != uVar14) {
LAB_c08e81c8:
                            uVar37 = FUN_c08ee588(local_15c,uVar29,local_74,uVar27,(byte)local_16c);
                          }
                        }
                        goto LAB_c08e8228;
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
                        if (uVar27 != 0xff) goto LAB_c08e81c8;
                        uVar37 = 0xffffffff;
                      }
                    }
                  }
LAB_c08e8228:
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
LAB_c08e8630:
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
                        if (uVar29 != 0xff) goto LAB_c08e8630;
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
                      uVar29 = FUN_c08ee68c(uVar37,*puVar23);
                      uVar14 = 1;
                      uVar37 = 0;
                      uVar34 = local_214;
                      pbVar40 = local_22c;
                      pbVar42 = local_198;
                      if (1 < uVar27) {
                        do {
                          puVar23 = puVar23 + 1;
                          uVar34 = FUN_c08ee68c(local_1d4,*puVar23);
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
                  goto LAB_c08e891c;
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
        goto LAB_c08e8874;
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
LAB_c08e712c:
      iVar30 = iVar43;
      if (!bVar5) {
        for (; local_268 < 0; local_268 = local_244 + local_268) {
          iVar39 = iVar39 + 1;
        }
        local_268 = local_250 + local_268;
      }
      for (; iVar30 != 0; iVar30 = iVar30 + -1) {
        if (bVar5) {
          if (bVar4) goto LAB_c08e7184;
          if (-1 < local_268) goto LAB_c08e7180;
          local_268 = local_244 + local_268;
        }
        else {
          for (; local_268 < 0; local_268 = local_244 + local_268) {
            iVar39 = iVar39 + 1;
          }
LAB_c08e7180:
          local_268 = local_250 + local_268;
LAB_c08e7184:
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
      goto LAB_c08e7250;
    }
    iVar41 = FUN_c08ee774((int *)&local_228,*(int **)(param_2 + 0x1c),piVar28);
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
      goto LAB_c08e712c;
    }
LAB_c08e8874:
    uVar13 = 0;
  }
  return uVar13;
}



/* c08e8b00 FUN_c08e8b00 */

/* Boundary evidence: original MIPS .pdata c08e8b00..c08e975f. Semantic name remains unreviewed. */

undefined4 FUN_c08e8b00(undefined4 param_1,int param_2)

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
  FUN_c08ee6ec(*(int *)(param_2 + 4),(int)auStack_48,(int *)auStack_38);
  iVar21 = iVar30;
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar30 = FUN_c08ee774(&local_58,*(int **)(param_2 + 0x1c),*(int **)(param_2 + 0x14));
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
  local_17c = *(int *)(&LAB_c08d284c + *(int *)(iVar30 + 0x1c) * 4);
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
    FUN_c08eeea0((int *)&local_1a0,*(int *)(param_2 + 4),*(int *)(param_2 + 0x34),
                 *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x14),iVar21,iVar29);
  }
  FUN_c08eeea0((int *)&local_138,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
               *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x18),iVar31,iVar33 + -1);
  FUN_c08eeea0((int *)&local_d0,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
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
                  pbVar9 = (byte *)FUN_c08ef00c((int)&local_138);
                  local_104 = (uint)*pbVar9;
                }
                else if (local_114 == 0x10) {
                  puVar4 = (ushort *)FUN_c08ef00c((int)&local_138);
                  local_104 = (uint)*puVar4;
                }
                else if (local_114 == 0x18) {
                  pbVar9 = (byte *)FUN_c08ef00c((int)&local_138);
                  local_104 = ((uint)pbVar9[2] * 0x100 + (uint)pbVar9[1]) * 0x100 | (uint)*pbVar9;
                }
                else if (local_114 == 0x20) {
                  puVar8 = (uint *)FUN_c08ef00c((int)&local_138);
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
                  pbVar9 = (byte *)FUN_c08ef00c((int)&local_d0);
                  local_9c = (uint)*pbVar9;
                }
                else if (local_ac == 0x10) {
                  puVar4 = (ushort *)FUN_c08ef00c((int)&local_d0);
                  local_9c = (uint)*puVar4;
                }
                else if (local_ac == 0x18) {
                  pbVar9 = (byte *)FUN_c08ef00c((int)&local_d0);
                  local_9c = ((uint)pbVar9[2] * 0x100 + (uint)pbVar9[1]) * 0x100 | (uint)*pbVar9;
                }
                else if (local_ac == 0x20) {
                  puVar8 = (uint *)FUN_c08ef00c((int)&local_d0);
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
            uVar6 = FUN_c08ee804(uVar6,uVar7,0x100 - uVar32,uVar32,auStack_48,auStack_38);
          }
          uVar7 = local_104;
          if (local_104 != local_9c) {
            uVar7 = FUN_c08ee804(local_104,local_9c,0x100 - uVar32,uVar32,auStack_48,auStack_38);
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
            if (local_1c4 <= iVar13) goto LAB_c08e96f4;
            iVar13 = iVar13 + 1;
            uVar5 = uVar6;
            if (uVar6 != uVar7) {
              uVar5 = FUN_c08ee804(uVar6,uVar7,0x100 - (uVar19 >> 8),uVar19 >> 8,auStack_48,
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
                puVar10 = (undefined2 *)FUN_c08ef00c((int)&local_1a0);
                local_16c = CONCAT22(local_16c._2_2_,*puVar10);
              }
              else if (local_17c == 0x18) {
                pbVar9 = (byte *)FUN_c08ef00c((int)&local_1a0);
                local_16c = ((uint)pbVar9[2] * 0x100 + (uint)pbVar9[1]) * 0x100 + (uint)*pbVar9;
              }
              else if (local_17c == 0x20) {
                puVar8 = (uint *)FUN_c08ef00c((int)&local_1a0);
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
                puVar10 = (undefined2 *)FUN_c08ef00c((int)&local_1a0);
                *puVar10 = (short)uVar5;
              }
              else if (local_17c == 0x18) {
                pbVar9 = (byte *)FUN_c08ef00c((int)&local_1a0);
                *pbVar9 = (byte)uVar5;
                pbVar9[1] = bVar12;
                pbVar9[2] = bVar15;
              }
              else if (local_17c == 0x20) {
                puVar8 = (uint *)FUN_c08ef00c((int)&local_1a0);
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
LAB_c08e96f4:
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



/* c08e9760 FUN_c08e9760 */

/* Boundary evidence: original MIPS .pdata c08e9760..c08ea48b. Semantic name remains unreviewed. */

undefined4 FUN_c08e9760(undefined4 param_1,int param_2)

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
  FUN_c08ee6ec(*(int *)(param_2 + 4),(int)auStack_b0,(int *)auStack_c0);
  if (*(int **)(param_2 + 0x1c) != (int *)0x0) {
    iVar15 = FUN_c08ee774(&local_38,*(int **)(param_2 + 0x1c),*(int **)(param_2 + 0x14));
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
  local_7c = *(int *)(&LAB_c08d284c + *(int *)(iVar11 + 0x1c) * 4);
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
    FUN_c08eeea0((int *)&local_a0,*(int *)(param_2 + 4),*(int *)(param_2 + 0x34),
                 *(int *)(param_2 + 0x38),*(int **)(param_2 + 0x14),iVar13,iVar14);
  }
  FUN_c08eeea0((int *)&local_190,*(int *)(param_2 + 8),*(int *)(param_2 + 0x34),
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
                pbVar6 = (byte *)FUN_c08ef00c((int)&local_190);
                local_15c = (uint)*pbVar6;
                puVar5 = local_164;
              }
              else if (local_16c == 0x10) {
                puVar7 = (ushort *)FUN_c08ef00c((int)&local_190);
                local_15c = (uint)*puVar7;
                puVar5 = local_164;
              }
              else if (local_16c == 0x18) {
                pbVar6 = (byte *)FUN_c08ef00c((int)&local_190);
                local_15c = ((uint)pbVar6[2] * 0x100 + (uint)pbVar6[1]) * 0x100 | (uint)*pbVar6;
                puVar5 = local_164;
              }
              else if (local_16c == 0x20) {
                puVar5 = (uint *)FUN_c08ef00c((int)&local_190);
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
                        pbVar6 = (byte *)FUN_c08ef00c((int)&local_190);
                        local_15c = (uint)*pbVar6;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x10) {
                        puVar7 = (ushort *)FUN_c08ef00c((int)&local_190);
                        local_15c = (uint)*puVar7;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x18) {
                        pbVar6 = (byte *)FUN_c08ef00c((int)&local_190);
                        local_15c = ((uint)pbVar6[2] * 0x100 + (uint)pbVar6[1]) * 0x100 |
                                    (uint)*pbVar6;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x20) {
                        puVar5 = (uint *)FUN_c08ef00c((int)&local_190);
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
                        pbVar6 = (byte *)FUN_c08ef00c((int)&local_190);
                        local_15c = (uint)*pbVar6;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x10) {
                        puVar7 = (ushort *)FUN_c08ef00c((int)&local_190);
                        local_15c = (uint)*puVar7;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x18) {
                        pbVar6 = (byte *)FUN_c08ef00c((int)&local_190);
                        local_15c = ((uint)pbVar6[2] * 0x100 + (uint)pbVar6[1]) * 0x100 |
                                    (uint)*pbVar6;
                        puVar5 = local_164;
                      }
                      else if (local_16c == 0x20) {
                        puVar5 = (uint *)FUN_c08ef00c((int)&local_190);
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
                      FUN_c08eeb8c((ushort *)&local_11c,local_15c,0x80,0x80,auStack_b0,auStack_c0);
                      puVar5 = local_164;
                    }
                    else if (local_7c == 0x18) {
                      FUN_c08eebcc((byte *)&local_11c,local_15c,0x80,0x80,auStack_b0,auStack_c0);
                      puVar5 = local_164;
                    }
                    else if (local_7c == 0x20) {
                      FUN_c08eec30(&local_11c,local_15c,0x80,0x80,auStack_b0,auStack_c0);
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
                  FUN_c08eeb8c((ushort *)local_128,local_11c,local_124,local_120,auStack_b0,
                               auStack_c0);
                }
                else if (local_7c == 0x18) {
                  FUN_c08eebcc((byte *)local_128,local_11c,local_124,local_120,auStack_b0,auStack_c0
                              );
                }
                else if (local_7c == 0x20) {
                  FUN_c08eec30(local_128,local_11c,local_124,local_120,auStack_b0,auStack_c0);
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
              pvVar8 = (void *)FUN_c08ef00c((int)&local_a0);
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



/* c08ea48c FUN_c08ea48c */

/* Boundary evidence: original MIPS .pdata c08ea48c..c08ea8b7. Semantic name remains unreviewed. */

void FUN_c08ea48c(int *param_1,int *param_2,int param_3)

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
    *param_2 = (int)FUN_c08e3c70;
    if (param_2[10] == 0xaaf0) {
      FUN_c08fc4ec(param_2);
      FUN_c08f39f4(param_2);
    }
    if ((code *)*param_2 == FUN_c08e3c70) {
      FUN_c08f68e8(param_2);
      FUN_c08ea9b4();
      FUN_c08f3ad0(param_2);
      FUN_c08f3d2c(param_2);
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
        *param_2 = (int)FUN_c08e5920;
      }
      else if ((param_2[0x12] == 4) &&
              (((param_2[10] == 0xcccc && (piVar3 = (int *)param_2[6], iVar6 <= piVar3[2] - *piVar3)
                ) && (iVar5 <= piVar3[3] - piVar3[1])))) {
        *param_2 = (int)FUN_c08e61fc;
      }
    }
    if ((code *)*param_2 == FUN_c08e3c70) {
      FUN_c08f01c8(param_2);
    }
  }
  else {
    *param_2 = (int)FUN_c08e6b08;
    if (param_2[10] == 0xaaf0) {
      FUN_c08fc4ec(param_2);
      FUN_c08f39f4(param_2);
    }
    if ((code *)*param_2 == FUN_c08e6b08) {
      FUN_c08ea9b4();
      FUN_c08f3ad0(param_2);
      FUN_c08f3d2c(param_2);
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
        *param_2 = (int)FUN_c08e8b00;
      }
      else if ((param_2[0x12] == 4) &&
              (((param_2[10] == 0xcccc && (piVar3 = (int *)param_2[6], iVar6 <= piVar3[2] - *piVar3)
                ) && (iVar5 <= piVar3[3] - piVar3[1])))) {
        *param_2 = (int)FUN_c08e9760;
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



/* c08ea8b8 FUN_c08ea8b8 */

/* Boundary evidence: original MIPS .pdata c08ea8b8..c08ea8d7. Semantic name remains unreviewed. */

void FUN_c08ea8b8(int *param_1,int *param_2)

{
  FUN_c08ea48c(param_1,param_2,-0x3f715748);
  return;
}



/* c08ea8d8 FUN_c08ea8d8 */

/* Boundary evidence: original MIPS .pdata c08ea8d8..c08ea8f7. Semantic name remains unreviewed. */

void FUN_c08ea8d8(int *param_1,int *param_2)

{
  FUN_c08ea48c(param_1,param_2,-0x3f715728);
  return;
}



/* c08ea8f8 FUN_c08ea8f8 */

/* Boundary evidence: original MIPS .pdata c08ea8f8..c08ea94b. Semantic name remains unreviewed. */

undefined4 * FUN_c08ea8f8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c08d28bc;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_c08ef2a0();
  return param_1;
}



/* c08ea94c FUN_c08ea94c */

void FUN_c08ea94c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c08d28bc;
  return;
}



/* c08ea9b4 FUN_c08ea9b4 */

undefined4 FUN_c08ea9b4(void)

{
  return 0;
}



/* c08ea9bc FUN_c08ea9bc */

void FUN_c08ea9bc(void)

{
  return;
}



/* c08ea9c4 FUN_c08ea9c4 */

/* Boundary evidence: original MIPS .pdata c08ea9c4..c08eacfb. Semantic name remains unreviewed. */

undefined4 FUN_c08ea9c4(undefined4 param_1,undefined4 *param_2)

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
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,u_Drivers_Display_GPE_c08fdd30,0,0,&local_2c);
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



/* c08ead1c FUN_c08ead1c */

void FUN_c08ead1c(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *param_2;
  iVar4 = param_2[1];
  iVar3 = param_2[2];
  iVar1 = *(int *)(param_1 + 0x18);
  iVar5 = param_2[3];
  if (iVar1 == 1) {
    *param_2 = iVar4;
    param_2[2] = iVar5;
    param_2[1] = *(int *)(param_1 + 0x20) - iVar3;
    param_2[3] = *(int *)(param_1 + 0x20) - iVar2;
  }
  else if (iVar1 == 2) {
    *param_2 = *(int *)(param_1 + 0x1c) - iVar3;
    param_2[2] = *(int *)(param_1 + 0x1c) - iVar2;
    param_2[1] = *(int *)(param_1 + 0x20) - iVar5;
    param_2[3] = *(int *)(param_1 + 0x20) - iVar4;
  }
  else if (iVar1 == 4) {
    *param_2 = *(int *)(param_1 + 0x1c) - iVar5;
    iVar1 = *(int *)(param_1 + 0x1c);
    param_2[1] = iVar2;
    param_2[2] = iVar1 - iVar4;
    param_2[3] = iVar3;
  }
  return;
}



/* c08eadd0 FUN_c08eadd0 */

/* Boundary evidence: original MIPS .pdata c08eadd0..c08eadeb. Semantic name remains unreviewed. */

void FUN_c08eadd0(void)

{
  FUN_c08dcd14();
  return;
}



/* c08eadec FUN_c08eadec */

/* Boundary evidence: original MIPS .pdata c08eadec..c08eae33. Semantic name remains unreviewed. */

undefined4 FUN_c08eadec(int param_1)

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



/* c08eae34 FUN_c08eae34 */

void FUN_c08eae34(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  *(int *)(param_1 + 0x44) = *(int *)(&LAB_c08d284c + param_6 * 4) >> 3;
  return;
}



/* c08eae8c FUN_c08eae8c */

void FUN_c08eae8c(int param_1,int param_2)

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



/* c08eaf5c FUN_c08eaf5c */

void FUN_c08eaf5c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

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



/* c08eaf98 FUN_c08eaf98 */

void FUN_c08eaf98(int param_1,int *param_2)

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



/* c08eb04c FUN_c08eb04c */

void FUN_c08eb04c(int param_1,int *param_2)

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



/* c08eb100 FUN_c08eb100 */

int FUN_c08eb100(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&LAB_c08d284c + *(int *)(param_1 + 0x1c) * 4);
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



/* c08eb234 FUN_c08eb234 */

/* Boundary evidence: original MIPS .pdata c08eb234..c08eb26b. Semantic name remains unreviewed. */

void FUN_c08eb234(undefined4 *param_1)

{
  if (param_1[2] != 0) {
    (*DAT_c0908b7c)(param_1[3],*param_1,param_1[1]);
  }
  return;
}



/* c08eb26c FUN_c08eb26c */

/* Boundary evidence: original MIPS .pdata c08eb26c..c08eb2af. Semantic name remains unreviewed. */

undefined4 * FUN_c08eb26c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c08d28bc;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c08eb2b0 FUN_c08eb2b0 */

/* Boundary evidence: original MIPS .pdata c08eb2b0..c08eb31f. Semantic name remains unreviewed. */

void FUN_c08eb2b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c08d24a8;
  if ((param_1[10] != 0) && ((void *)param_1[1] != (void *)0x0)) {
    operator_delete((void *)param_1[1]);
  }
  if (param_1[5] != 0) {
    (*DAT_c0908b7c)(param_1[6],param_1[3],param_1[4]);
  }
  return;
}



/* c08eb320 FUN_c08eb320 */

/* WARNING: Removing unreachable block (ram,0xc08eb430) */
/* Boundary evidence: original MIPS .pdata c08eb320..c08ebb5f. Semantic name remains unreviewed. */

undefined4 FUN_c08eb320(int *param_1,int param_2)

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
  iVar22 = *(int *)(&LAB_c08d284c + *(int *)(iVar13 + 0x1c) * 4);
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
      goto LAB_c08eb80c;
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
      goto LAB_c08eb7f8;
    case 6:
      iVar27 = 3;
LAB_c08eb7f8:
      iVar31 = -iVar21;
      break;
    case 7:
      iVar27 = -iVar21;
LAB_c08eb80c:
      iVar31 = 3;
      break;
    default:
      goto LAB_c08ebb30;
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
        goto LAB_c08eb908;
      case 3:
        *pbVar20 = ~bVar1 & *pbVar20;
        bVar12 = ~bVar3 & pbVar20[2];
        pbVar20[1] = ~bVar2 & pbVar20[1];
        goto LAB_c08eb944;
      case 4:
        *pbVar20 = ~bVar1;
        pbVar20[1] = ~bVar2;
        bVar12 = ~bVar3;
LAB_c08eb944:
        pbVar20[2] = bVar12;
        break;
      case 5:
        *pbVar20 = ~*pbVar20 & bVar1;
        bVar12 = ~pbVar20[2] & bVar3;
        pbVar20[1] = ~pbVar20[1] & bVar2;
        goto LAB_c08eb990;
      case 6:
        pbVar20[1] = ~pbVar20[1];
        bVar12 = ~pbVar20[2];
        *pbVar20 = ~*pbVar20;
        goto LAB_c08eb990;
      case 7:
        *pbVar20 = *pbVar20 ^ bVar1;
        pbVar20[1] = bVar2 ^ pbVar20[1];
        pbVar20[2] = pbVar20[2] ^ bVar3;
        break;
      case 8:
        *pbVar20 = ~(*pbVar20 & bVar1);
        bVar14 = bVar2 & pbVar20[1];
        bVar12 = pbVar20[2] & bVar3;
        goto LAB_c08eb908;
      case 9:
        *pbVar20 = *pbVar20 & bVar1;
        pbVar20[1] = bVar2 & pbVar20[1];
        pbVar20[2] = pbVar20[2] & bVar3;
        break;
      case 10:
        *pbVar20 = ~(*pbVar20 ^ bVar1);
        bVar14 = bVar2 ^ pbVar20[1];
        bVar12 = pbVar20[2] ^ bVar3;
LAB_c08eb908:
        bVar12 = ~bVar12;
        bVar14 = ~bVar14;
LAB_c08eb90c:
        pbVar20[1] = bVar14;
        pbVar20[2] = bVar12;
        break;
      case 0xb:
        break;
      case 0xc:
        *pbVar20 = ~bVar1 | *pbVar20;
        bVar14 = ~bVar2 | pbVar20[1];
        bVar12 = ~bVar3 | pbVar20[2];
        goto LAB_c08eb90c;
      case 0xd:
        *pbVar20 = bVar1;
        pbVar20[1] = bVar2;
        pbVar20[2] = bVar3;
        break;
      case 0xe:
        *pbVar20 = ~*pbVar20 | bVar1;
        bVar14 = ~pbVar20[1] | bVar2;
        bVar12 = ~pbVar20[2] | bVar3;
        goto LAB_c08eb90c;
      case 0xf:
        bVar12 = pbVar20[2] | bVar3;
        *pbVar20 = *pbVar20 | bVar1;
        pbVar20[1] = bVar2 | pbVar20[1];
LAB_c08eb990:
        pbVar20[2] = bVar12;
        break;
      case 0x10:
        *pbVar20 = 0xff;
        pbVar20[1] = 0xff;
        pbVar20[2] = 0xff;
        break;
      default:
        goto LAB_c08ebb30;
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
    goto LAB_c08eb524;
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
    goto LAB_c08eb510;
  case 6:
    iVar26 = 1;
LAB_c08eb510:
    iVar27 = -iVar21;
    break;
  case 7:
    iVar31 = -iVar21;
LAB_c08eb524:
    iVar25 = 1;
    break;
  default:
LAB_c08ebb30:
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
        goto LAB_c08eb644;
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
        goto LAB_c08eb644;
      case 9:
        uVar11 = uVar15 & uVar23;
        break;
      case 10:
        uVar15 = uVar15 ^ uVar23;
LAB_c08eb644:
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
        goto LAB_c08ebb30;
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



/* c08ebb60 FUN_c08ebb60 */

/* Boundary evidence: original MIPS .pdata c08ebb60..c08ebbbb. Semantic name remains unreviewed. */

void FUN_c08ebb60(int param_1,int param_2,int param_3,undefined *param_4)

{
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*(code *)param_4)(param_1);
    param_1 = param_1 + param_2;
  }
  return;
}



/* c08ebbbc FUN_c08ebbbc */

/* Boundary evidence: original MIPS .pdata c08ebbbc..c08ebcaf. Semantic name remains unreviewed. */

undefined4 FUN_c08ebbbc(int *param_1,int param_2)

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



/* c08ebcb0 FUN_c08ebcb0 */

int FUN_c08ebcb0(undefined4 *param_1,int param_2)

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
          if (uVar4 == (int)*(short *)((int)param_1 + 0xe)) goto LAB_c08ebdb0;
          iVar2 = uVar4 * 2;
          *(undefined2 *)(*(short *)(param_1[2] + iVar2) * 2 + param_1[1]) =
               *(undefined2 *)(param_1[1] + iVar2);
          *(undefined2 *)(*(short *)(param_1[1] + iVar2) * 2 + param_1[2]) =
               *(undefined2 *)(param_1[2] + iVar2);
          *(short *)(*(short *)((int)param_1 + 0xe) * 2 + param_1[1]) = sVar3;
          *(undefined2 *)(param_1[2] + iVar2) = *(undefined2 *)((int)param_1 + 0xe);
        }
        *(short *)((int)param_1 + 0xe) = sVar3;
LAB_c08ebdb0:
        return (int)sVar3;
      }
      uVar4 = uVar4 + 1;
      piVar1 = piVar1 + 1;
    } while (uVar4 < *(ushort *)(param_1 + 4));
  }
  return -1;
}



/* c08ebdbc FUN_c08ebdbc */

/* Boundary evidence: original MIPS .pdata c08ebdbc..c08ebe23. Semantic name remains unreviewed. */

void FUN_c08ebdbc(undefined4 *param_1)

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



/* c08ebe24 FUN_c08ebe24 */

/* Boundary evidence: original MIPS .pdata c08ebe24..c08ebf13. Semantic name remains unreviewed. */

void FUN_c08ebe24(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  
  *(short *)(param_1 + 0x12) = (short)param_4;
  if (param_4 == 2) {
    (*DAT_c0908b64)(param_2,param_3,3,param_1);
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



/* c08ebf14 FUN_c08ebf14 */

/* Boundary evidence: original MIPS .pdata c08ebf14..c08ebf67. Semantic name remains unreviewed. */

void FUN_c08ebf14(int param_1,int param_2)

{
  FUN_c08ebe24(param_1,param_2,1,(uint)*(ushort *)(param_2 + 8));
  FUN_c08ebe24(param_1 + 0x14,param_2,2,(uint)*(ushort *)(param_2 + 10));
  return;
}



/* c08ebf68 FUN_c08ebf68 */

/* Boundary evidence: original MIPS .pdata c08ebf68..c08ec1f7. Semantic name remains unreviewed. */

void FUN_c08ebf68(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined2 *puVar6;
  short sVar7;
  uint uVar8;
  
  FUN_c08ebe24(param_1 + 0x6cc,param_2,1,(uint)*(ushort *)(param_2 + 8));
  uVar1 = (*DAT_c0908b64)(param_2,2,0,0);
  *(ushort *)(param_1 + 0x6c8) = uVar1;
  if (0x100 < uVar1) {
    *(undefined2 *)(param_1 + 0x6c8) = 0x100;
  }
  (*DAT_c0908b64)(param_2,2,*(undefined2 *)(param_1 + 0x6c8),param_1 + 0x2c8);
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



/* c08ec1f8 FUN_c08ec1f8 */

/* Boundary evidence: original MIPS .pdata c08ec1f8..c08ec21f. Semantic name remains unreviewed. */

undefined3 FUN_c08ec1f8(undefined4 param_1,undefined4 param_2)

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



/* c08ec2a4 FUN_c08ec2a4 */

uint FUN_c08ec2a4(int param_1,uint param_2)

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



/* c08ec4e4 FUN_c08ec4e4 */

/* Boundary evidence: original MIPS .pdata c08ec4e4..c08ec6a7. Semantic name remains unreviewed. */

uint FUN_c08ec4e4(int param_1,uint param_2,uint *param_3,uint param_4)

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
        uVar4 = FUN_c08ee68c(param_4,*param_3);
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



/* c08ec6a8 FUN_c08ec6a8 */

/* Boundary evidence: original MIPS .pdata c08ec6a8..c08ec7c3. Semantic name remains unreviewed. */

uint FUN_c08ec6a8(int param_1,int param_2,uint *param_3,uint param_4)

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



/* c08ec7d8 FUN_c08ec7d8 */

/* Boundary evidence: original MIPS .pdata c08ec7d8..c08ec9eb. Semantic name remains unreviewed. */

void FUN_c08ec7d8(uint *param_1,int param_2)

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
  
  uVar2 = (*DAT_c0908b64)(param_2,1,0,0);
  uVar2 = uVar2 & 0xffff;
  if (0x100 < uVar2) {
    uVar2 = 0x100;
  }
  puVar6 = param_1 + 5;
  (*DAT_c0908b64)(param_2,1,uVar2,puVar6);
  if (*(ushort *)(param_2 + 10) == 1) {
    uVar3 = (*DAT_c0908b64)(param_2,2,0,0);
    uVar3 = uVar3 & 0xffff;
    if (0x100 < uVar3) {
      uVar3 = 0x100;
    }
    (*DAT_c0908b64)(param_2,2,uVar3,auStack_420);
    if (uVar2 != 0) {
      uVar5 = 0;
      do {
        uVar4 = FUN_c08ec4e4(1,uVar3,auStack_420,*puVar6);
        uVar5 = uVar5 + 1 & 0xffff;
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
      } while (uVar5 < uVar2);
    }
  }
  else {
    FUN_c08ebe24((int)param_1,param_2,2,(uint)*(ushort *)(param_2 + 10));
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



/* c08ec9ec FUN_c08ec9ec */

/* Boundary evidence: original MIPS .pdata c08ec9ec..c08ecc83. Semantic name remains unreviewed. */

int FUN_c08ec9ec(int param_1,uint param_2)

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
  iVar3 = FUN_c08ebcb0((int *)(param_1 + 0x40),local_res4);
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
        local_30 = FUN_c08ec2a4(param_1,local_res4);
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
      uVar4 = FUN_c08ee68c(local_30,*(uint *)((iVar3 + 0xb2) * 4 + param_1));
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



/* c08ecc84 FUN_c08ecc84 */

/* Boundary evidence: original MIPS .pdata c08ecc84..c08ecd47. Semantic name remains unreviewed. */

undefined4 FUN_c08ecc84(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_c08ebbbc(&DAT_c0909da0,10);
  if ((((iVar1 == 0) || (iVar1 = FUN_c08ebbbc(&DAT_c0909ddc,2), iVar1 == 0)) ||
      (iVar1 = FUN_c08ebbbc(&DAT_c0909dc8,10), iVar1 == 0)) ||
     (iVar1 = FUN_c08ebbbc(&DAT_c0909db4,4), iVar1 == 0)) {
LAB_c08ecd30:
    uVar2 = 0;
  }
  else {
    piVar3 = (int *)&DAT_c0909e30;
    do {
      iVar1 = FUN_c08ebbbc(piVar3,0x10);
      if (iVar1 == 0) goto LAB_c08ecd30;
      piVar3 = piVar3 + 0x1b8;
    } while ((int)piVar3 < -0x3f6f5410);
    uVar2 = 1;
  }
  return uVar2;
}



/* c08ecd48 FUN_c08ecd48 */

/* Boundary evidence: original MIPS .pdata c08ecd48..c08ecdc3. Semantic name remains unreviewed. */

void FUN_c08ecd48(void)

{
  undefined4 *puVar1;
  
  FUN_c08ebdbc(&DAT_c0909da0);
  FUN_c08ebdbc(&DAT_c0909ddc);
  FUN_c08ebdbc(&DAT_c0909dc8);
  FUN_c08ebdbc(&DAT_c0909db4);
  puVar1 = (undefined4 *)&DAT_c0909e30;
  do {
    FUN_c08ebdbc(puVar1);
    puVar1 = puVar1 + 0x1b8;
  } while ((int)puVar1 < -0x3f6f5410);
  return;
}



/* c08ecdc4 FUN_c08ecdc4 */

/* Boundary evidence: original MIPS .pdata c08ecdc4..c08ed223. Semantic name remains unreviewed. */

void FUN_c08ecdc4(int *param_1,int *param_2,undefined4 *param_3,int *param_4)

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
        iVar3 = FUN_c08ebcb0(&DAT_c0909dc8,iVar6);
        if (iVar3 == -1) {
          *(short *)(DAT_c0909dd6 * 2 + DAT_c0909dcc) = DAT_c0909dd4;
          *(short *)(DAT_c0909dd4 * 2 + DAT_c0909dd0) = DAT_c0909dd6;
          iVar3 = (int)DAT_c0909dd4;
          DAT_c0909dd6 = DAT_c0909dd4;
          DAT_c0909dd4 = *(short *)(iVar3 * 2 + DAT_c0909dcc);
          *(int *)(iVar3 * 4 + DAT_c0909dc8) = iVar6;
          iVar3 = (int)DAT_c0909dd6;
        }
        piVar4 = (int *)(&DAT_c0909d78 + iVar3 * 4);
        *piVar4 = iVar6;
        pcVar5 = (code *)&LAB_c08ec4cc;
      }
      else {
        if (sVar1 == 1) {
          iVar3 = FUN_c08ebcb0(&DAT_c0909db4,*param_1);
          if (iVar3 == -1) {
            iVar6 = *param_1;
            *(short *)(DAT_c0909dc2 * 2 + DAT_c0909db8) = DAT_c0909dc0;
            *(short *)(DAT_c0909dc0 * 2 + DAT_c0909dbc) = DAT_c0909dc2;
            iVar3 = (int)DAT_c0909dc0;
            DAT_c0909dc2 = DAT_c0909dc0;
            DAT_c0909dc0 = *(short *)(iVar3 * 2 + DAT_c0909db8);
            *(int *)(iVar3 * 4 + DAT_c0909db4) = iVar6;
            iVar3 = (int)DAT_c0909dc2;
            FUN_c08ec7d8((uint *)(iVar3 * 0x414 + -0x3f6f72d8),(int)param_1);
          }
          *param_4 = iVar3 * 0x414 + -0x3f6f72c4;
          return;
        }
        if (sVar2 != 1) {
          if (((sVar1 != 2) && (sVar1 != 4)) && (sVar1 != 8)) {
            return;
          }
          if (((sVar2 != 2) && (sVar2 != 4)) && (sVar2 != 8)) {
            return;
          }
          *param_3 = (&PTR_FUN_c08d2a08)
                     [(uint)(byte)(&DAT_c08fdd58)[*(ushort *)(param_1 + 2) >> 1] * 4 +
                      (uint)(byte)(&DAT_c08fdd58)[*(ushort *)((int)param_1 + 10) >> 1] + -4];
          if (((*(ushort *)((int)param_1 + 10) | *(ushort *)(param_1 + 2)) & 2) == 0) {
            return;
          }
          iVar3 = FUN_c08ebcb0(&DAT_c0909da0,*param_1);
          if (iVar3 == -1) {
            iVar6 = *param_1;
            *(short *)(DAT_c0909dae * 2 + DAT_c0909da4) = DAT_c0909dac;
            *(short *)(DAT_c0909dac * 2 + DAT_c0909da8) = DAT_c0909dae;
            iVar3 = (int)DAT_c0909dac;
            DAT_c0909dae = DAT_c0909dac;
            DAT_c0909dac = *(short *)(iVar3 * 2 + DAT_c0909da4);
            *(int *)(iVar3 * 4 + DAT_c0909da0) = iVar6;
            iVar3 = (int)DAT_c0909dae;
            FUN_c08ebf14(iVar3 * 0x28 + -0x3f6f7468,(int)param_1);
          }
          *param_2 = iVar3 * 0x28 + -0x3f6f7468;
          return;
        }
        iVar3 = FUN_c08ebcb0(&DAT_c0909ddc,*param_1);
        if (iVar3 == -1) {
          iVar6 = *param_1;
          *(short *)(DAT_c0909dea * 2 + DAT_c0909de0) = DAT_c0909de8;
          *(short *)(DAT_c0909de8 * 2 + DAT_c0909de4) = DAT_c0909dea;
          iVar3 = (int)DAT_c0909de8;
          DAT_c0909dea = DAT_c0909de8;
          DAT_c0909de8 = *(short *)(iVar3 * 2 + DAT_c0909de0);
          *(int *)(iVar3 * 4 + DAT_c0909ddc) = iVar6;
          iVar3 = (int)DAT_c0909dea;
          FUN_c08ebf68((int)(&DAT_c0909df0 + iVar3 * 0x6e0),(int)param_1);
        }
        pcVar5 = FUN_c08ec9ec;
        piVar4 = (int *)(&DAT_c0909df0 + iVar3 * 0x6e0);
      }
      *param_2 = (int)piVar4;
      *param_3 = pcVar5;
    }
  }
  return;
}



/* c08ed224 FUN_c08ed224 */

/* Boundary evidence: original MIPS .pdata c08ed224..c08ed283. Semantic name remains unreviewed. */

void FUN_c08ed224(undefined4 param_1,undefined4 *param_2)

{
  (*(code *)*param_2)(param_1,param_2);
  return;
}



/* c08ed284 FUN_c08ed284 */

/* Boundary evidence: original MIPS .pdata c08ed284..c08ed28f. Semantic name remains unreviewed. */

undefined4 FUN_c08ed284(void)

{
  return 1;
}



/* c08ed290 FUN_c08ed290 */

/* Boundary evidence: original MIPS .pdata c08ed290..c08edc73. Semantic name remains unreviewed. */

undefined4
FUN_c08ed290(int *param_1,undefined4 param_2,int *param_3,undefined4 param_4,undefined4 *param_5,
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
  FUN_c08edc74(&local_3a0,param_1,(int *)0x0,(int *)0x0);
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
LAB_c08edc38:
    FUN_c08eb2b0(auStack_39c);
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
      goto LAB_c08ed47c;
    }
    piVar16 = param_3 + 1;
  }
  local_4b4 = 0;
LAB_c08ed47c:
  puVar21 = &DAT_c08d2a38;
  local_350 = 1 - local_4b4;
  local_484 = &DAT_c08d2a38;
  local_4a4 = local_48c;
  local_4b0 = local_490;
  uVar17 = local_48c;
  uVar11 = local_490;
  do {
    if (local_350 == 0) {
      if (local_4b4 == 0) {
        (**(code **)(*local_494 + 0xc))(local_494,&uStack_478,3);
        FUN_c08eb2b0(auStack_39c);
        return 1;
      }
      local_4b4 = (*DAT_c0908b4c)(param_3,0x324,&local_350);
      piVar16 = local_34c;
      if (local_350 != 0) goto LAB_c08ed4e0;
    }
    else {
LAB_c08ed4e0:
      local_454 = 0;
      if (bVar1) {
        local_440 = *piVar16;
        local_43c = piVar16[1];
        local_438 = piVar16[2];
        local_434 = piVar16[3];
        FUN_c08eaf98(local_450,&local_440);
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
      (*DAT_c0908b68)(param_2);
      do {
        local_488 = (*DAT_c0908b44)(param_2,&local_4c0);
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
LAB_c08ed7ec:
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
              if (iVar10 <= (int)uVar14) goto LAB_c08ed7ec;
            }
          }
          iVar8 = 0;
          if ((uVar23 & 0x90) == 0x90) {
            if ((uVar14 != 0) && (uVar12 == uVar14 + 8)) {
              iVar5 = iVar5 + -1;
            }
            if ((uVar24 != 0) && (uVar13 != uVar24 + 8)) goto LAB_c08ed82c;
          }
          else {
LAB_c08ed82c:
            if (uVar24 != 0) {
              if (uVar13 == 0) {
                if ((uVar11 & 0x80) == 0) {
                  uVar11 = 7;
                }
                else {
                  uVar11 = 8;
                }
                if (uVar11 < uVar24) {
LAB_c08ed894:
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
                if (iVar10 <= (int)uVar24) goto LAB_c08ed894;
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
                if ((int)uVar13 <= (int)uVar11) goto LAB_c08edb2c;
              }
              else {
                if (iVar8 < iVar15) {
                  if (uVar18 == 0) {
                    trap(0x1c00);
                  }
                  uVar11 = ((iVar15 - iVar8) * uVar17 + iVar10 + uVar18) / uVar18 + uVar11;
                  iVar8 = iVar15;
                  if (iVar6 <= (int)uVar11) goto LAB_c08edaac;
                }
                if ((int)uVar11 < (int)uVar13) {
                  if (uVar17 == 0) {
                    trap(0x1c00);
                  }
                  iVar8 = ((((uVar13 - uVar11) + -1) * uVar18 - iVar10) - 1) / uVar17 + iVar8 + 1;
                  uVar11 = uVar13;
                  if (iVar25 <= iVar8) goto LAB_c08edaac;
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
                    if (iVar5 < iVar15) goto LAB_c08edaac;
                  }
LAB_c08edb2c:
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
                      FUN_c08eae8c(local_450,(int)&uStack_478);
                    }
                    iVar5 = FUN_c08ed224(local_494,&uStack_478);
                    if (iVar5 < 0) goto LAB_c08edc38;
                    local_454 = iVar7 + local_454 & 0x1f;
                    puVar19 = local_4b8;
                  }
                }
              }
            }
          }
LAB_c08edaac:
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



/* c08edc74 FUN_c08edc74 */

/* Boundary evidence: original MIPS .pdata c08edc74..c08edd5b. Semantic name remains unreviewed. */

int * FUN_c08edc74(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  
  piVar1 = param_1 + 1;
  *piVar1 = (int)&PTR_FUN_c08d24a8;
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
    FUN_c08eae34((int)piVar1,param_2[4],param_2[5],param_2[8],param_2[9],
                 *(int *)(&LAB_c08d2894 + param_2[0xb] * 4));
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



/* c08edd5c FUN_c08edd5c */

/* Boundary evidence: original MIPS .pdata c08edd5c..c08eddbb. Semantic name remains unreviewed. */

undefined4 * FUN_c08edd5c(undefined4 *param_1,int param_2)

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



/* c08eddbc FUN_c08eddbc */

/* Boundary evidence: original MIPS .pdata c08eddbc..c08edde3. Semantic name remains unreviewed. */

void FUN_c08eddbc(undefined4 *param_1)

{
  if ((HLOCAL)*param_1 != (HLOCAL)0x0) {
    LocalFree((HLOCAL)*param_1);
  }
  return;
}



/* c08edde4 FUN_c08edde4 */

/* Boundary evidence: original MIPS .pdata c08edde4..c08ee127. Semantic name remains unreviewed. */

undefined4 FUN_c08edde4(int *param_1,int param_2,uint param_3,int param_4,uint param_5)

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



/* c08ee128 FUN_c08ee128 */

/* Boundary evidence: original MIPS .pdata c08ee128..c08ee587. Semantic name remains unreviewed. */

int FUN_c08ee128(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

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



/* c08ee588 FUN_c08ee588 */

/* Boundary evidence: original MIPS .pdata c08ee588..c08ee68b. Semantic name remains unreviewed. */

uint FUN_c08ee588(uint param_1,uint param_2,uint param_3,uint param_4,byte param_5)

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
    uVar1 = FUN_c08ee588(param_1 >> 0x10,param_2 >> 0x10,param_3 >> 0x10,param_4,param_5 - 0x10);
    uVar2 = FUN_c08ee588(param_1,param_2,param_3,param_4,0x10);
    uVar2 = uVar2 | uVar1 << 0x10;
  }
  return uVar2;
}



/* c08ee68c FUN_c08ee68c */

int FUN_c08ee68c(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (param_1 & 0xff) - (param_2 & 0xff);
  iVar1 = (param_1 >> 8 & 0xff) - (param_2 >> 8 & 0xff);
  iVar2 = (param_1 >> 0x10 & 0xff) - (param_2 >> 0x10 & 0xff);
  return iVar2 * iVar2 + iVar1 * iVar1 + iVar3 * iVar3;
}



/* c08ee6ec FUN_c08ee6ec */

void FUN_c08ee6ec(int param_1,int param_2,int *param_3)

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



/* c08ee774 FUN_c08ee774 */

undefined4 FUN_c08ee774(int *param_1,int *param_2,int *param_3)

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



/* c08ee804 FUN_c08ee804 */

/* Boundary evidence: original MIPS .pdata c08ee804..c08ee997. Semantic name remains unreviewed. */

uint FUN_c08ee804(uint param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

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



/* c08ee998 FUN_c08ee998 */

/* Boundary evidence: original MIPS .pdata c08ee998..c08eeb8b. Semantic name remains unreviewed. */

uint FUN_c08ee998(uint param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

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



/* c08eeb8c FUN_c08eeb8c */

/* Boundary evidence: original MIPS .pdata c08eeb8c..c08eebcb. Semantic name remains unreviewed. */

void FUN_c08eeb8c(ushort *param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  
  uVar1 = FUN_c08ee998((uint)*param_1,param_2,param_3,param_4,param_5,param_6);
  *param_1 = (ushort)uVar1;
  return;
}



/* c08eebcc FUN_c08eebcc */

/* Boundary evidence: original MIPS .pdata c08eebcc..c08eec2f. Semantic name remains unreviewed. */

void FUN_c08eebcc(byte *param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  
  uVar1 = FUN_c08ee998(((uint)param_1[2] * 0x100 + (uint)param_1[1]) * 0x100 + (uint)*param_1,
                       param_2,param_3,param_4,param_5,param_6);
  *param_1 = (byte)uVar1;
  param_1[1] = (byte)(uVar1 >> 8);
  param_1[2] = (byte)(uVar1 >> 0x10);
  return;
}



/* c08eec30 FUN_c08eec30 */

/* Boundary evidence: original MIPS .pdata c08eec30..c08eec6b. Semantic name remains unreviewed. */

void FUN_c08eec30(uint *param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  
  uVar1 = FUN_c08ee998(*param_1,param_2,param_3,param_4,param_5,param_6);
  *param_1 = uVar1;
  return;
}



/* c08eec6c FUN_c08eec6c */

/* WARNING: Removing unreachable block (ram,0xc08eed44) */

void FUN_c08eec6c(int *param_1,int param_2,int param_3,int param_4,int *param_5,int param_6,
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
  iVar2 = *(int *)(&LAB_c08d284c + *(int *)(param_2 + 0x1c) * 4);
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



/* c08eeea0 FUN_c08eeea0 */

/* Boundary evidence: original MIPS .pdata c08eeea0..c08ef00b. Semantic name remains unreviewed. */

void FUN_c08eeea0(int *param_1,int param_2,int param_3,int param_4,int *param_5,int param_6,
                 int param_7)

{
  int iVar1;
  int iVar2;
  
  param_1[0x15] = (uint)(*(int *)(param_2 + 0x38) != 0);
  *(undefined2 *)(param_1 + 0x12) = 0;
  param_1[9] = *(int *)(&LAB_c08d284c + *(int *)(param_2 + 0x1c) * 4);
  param_1[0xf] = 0;
  *param_1 = 0;
  param_1[0xb] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[0xe] = 0;
  if (*(int *)(param_2 + 0x38) == 0) {
    FUN_c08eec6c(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
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



/* c08ef00c FUN_c08ef00c */

int FUN_c08ef00c(int param_1)

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



/* c08ef174 FUN_c08ef174 */

/* Boundary evidence: original MIPS .pdata c08ef174..c08ef29f. Semantic name remains unreviewed. */

void FUN_c08ef174(int *param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_5[3] == 0) {
    param_5[3] = *(int *)(param_2 + 0x30);
  }
  FUN_c08eec6c(param_1,param_2,param_3,param_4,param_5,0,0);
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
  uVar3 = *(int *)(&LAB_c08d284c + *(int *)(param_2 + 0x1c) * 4) * (param_1[0x10] - iVar1) >> 3 &
          0xfffffffc;
  param_1[0x14] = uVar3;
  if (param_3 == 0) {
    param_1[0x14] = -uVar3;
  }
  return;
}



/* c08ef2a0 FUN_c08ef2a0 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c08ef2a0..c08ef503. Semantic name remains unreviewed. */

int FUN_c08ef2a0(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  LPVOID lpAddress;
  int iVar5;
  
  lpAddress = (LPVOID)0x0;
  iVar2 = FUN_c08f0dd0(-0x3f7022a0);
  if ((iVar2 != 0) && (iVar2 = FUN_c08f22f0(&DAT_c090aeb8), iVar2 != 0)) {
    lpAddress = VirtualAlloc((LPVOID)0x0,0x10000,0x1000,0x40);
    if (lpAddress == (LPVOID)0x0) {
      iVar2 = 0;
    }
    if (iVar2 != 0) {
      DAT_c090aed0 = VirtualAlloc((LPVOID)0x0,0x1000,0x1000,4);
      if (DAT_c090aed0 == (LPVOID)0x0) {
        iVar2 = 0;
      }
      if (iVar2 != 0) {
        DAT_c090aed4 = VirtualAlloc((LPVOID)0x0,0x1000,0x1000,4);
        if (DAT_c090aed4 == (LPVOID)0x0) {
          iVar2 = 0;
        }
        if (iVar2 != 0) {
          memset(&DAT_c090ae30,0,0x88);
          DAT_c090ae34 = 0x10;
          iVar5 = 0;
          uVar4 = 0;
          puVar1 = (undefined4 *)&DAT_c090ae30;
          do {
            *(LPVOID *)((int)&DAT_c090abbc + uVar4) = lpAddress;
            *(undefined4 *)((int)&DAT_c090abb0 + uVar4) = 0;
            *(undefined4 *)((int)&DAT_c090abb4 + uVar4) = 0;
            *(undefined4 *)((int)&DAT_c090abc8 + uVar4) = 0;
            uVar3 = puVar1[3];
            *(int *)((int)&DAT_c090abb8 + uVar4) = iVar5;
            *(undefined4 *)((int)&DAT_c090abc0 + uVar4) = 0;
            *(undefined4 *)((int)&DAT_c090abc4 + uVar4) = 0;
            puVar1[3] = uVar3 & 0xc00400ff | 0x80040000;
            *(undefined1 *)(puVar1 + 3) = 1;
            *(undefined4 *)((int)&DAT_c090abd0 + uVar4) = 0;
            *(undefined4 *)((int)&DAT_c090abcc + uVar4) = 0;
            puVar1[2] = lpAddress;
            uVar4 = uVar4 + 0x28;
            puVar1[3] = puVar1[3] | 0x40000000;
            lpAddress = (LPVOID)((int)lpAddress + 0x1000);
            iVar5 = iVar5 + 1;
            puVar1 = puVar1 + 2;
          } while (uVar4 < 0x280);
          CeSetExtendedPdata(&DAT_c090ae30);
          DAT_c090aed8 = 1;
          return iVar2;
        }
      }
    }
  }
  if (DAT_c090aed4 != (LPVOID)0x0) {
    VirtualFree(DAT_c090aed4,0x1000,0x4000);
    DAT_c090aed4 = (LPVOID)0x0;
  }
  if (DAT_c090aed0 != (LPVOID)0x0) {
    VirtualFree(DAT_c090aed0,0x1000,0x4000);
    DAT_c090aed0 = (LPVOID)0x0;
  }
  if (lpAddress != (LPVOID)0x0) {
    VirtualFree(lpAddress,0x10000,0x4000);
  }
  DAT_c090aed8 = 1;
  return 0;
}



/* c08ef504 FUN_c08ef504 */

void FUN_c08ef504(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0x78;
  do {
    *(undefined4 *)((int)&DAT_c090abb0 + uVar4) = 0;
    *(undefined4 *)((int)&DAT_c090abb4 + uVar4) = 0;
    *(undefined4 *)((int)&DAT_c090abc0 + uVar4) = 0;
    *(undefined4 *)((int)&DAT_c090abc4 + uVar4) = 0;
    puVar1 = (undefined4 *)((int)&DAT_c090abc8 + uVar4);
    puVar2 = (undefined4 *)((int)&DAT_c090abcc + uVar4);
    puVar3 = (undefined4 *)((int)&DAT_c090abd0 + uVar4);
    uVar4 = uVar4 + 0x28;
    *puVar1 = 0;
    *puVar2 = 0;
    *puVar3 = 0;
  } while (uVar4 < 0x280);
  return;
}



/* c08ef55c FUN_c08ef55c */

undefined4 * FUN_c08ef55c(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  while ((*param_1 != *(int *)((int)&DAT_c090abb0 + uVar1) ||
         (param_1[1] != *(int *)((int)&DAT_c090abb4 + uVar1)))) {
    uVar1 = uVar1 + 0x28;
    iVar2 = iVar2 + 1;
    if (0x27f < uVar1) {
      return (undefined4 *)0x0;
    }
  }
  (&DAT_c090abc4)[iVar2 * 10] = DAT_c090aed8;
  return &DAT_c090abb0 + iVar2 * 10;
}



/* c08ef5d4 FUN_c08ef5d4 */

void FUN_c08ef5d4(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 3;
  iVar2 = 4;
  uVar1 = 0xa0;
  uVar3 = DAT_c090ac3c;
  do {
    if (*(uint *)((int)&DAT_c090abc4 + uVar1) < uVar3) {
      uVar3 = *(uint *)((int)&DAT_c090abc4 + uVar1);
      iVar4 = iVar2;
    }
    uVar1 = uVar1 + 0x28;
    iVar2 = iVar2 + 1;
  } while (uVar1 < 0x280);
  (&DAT_c090abb0)[iVar4 * 10] = *param_1;
  (&DAT_c090abb4)[iVar4 * 10] = param_1[1];
  (&DAT_c090abc4)[iVar4 * 10] = DAT_c090aed8;
  (&DAT_c090abc0)[iVar4 * 10] = 0;
  (&DAT_c090abc8)[iVar4 * 10] = 0;
  (&DAT_c090abcc)[iVar4 * 10] = 0;
  (&DAT_c090abd0)[iVar4 * 10] = 0;
  return;
}



/* c08ef684 FUN_c08ef684 */

/* Boundary evidence: original MIPS .pdata c08ef684..c08ef757. Semantic name remains unreviewed. */

undefined4 * FUN_c08ef684(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_c08ef55c((int *)param_1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_c08ef5d4(param_1);
    FUN_c08f0634(-0x3f7022a0,DAT_c090aed0,param_1);
    CacheRangeFlush(puVar1[3],0x1000,2);
    uVar2 = (*DAT_c090aeb8)(puVar1[2],DAT_c090aed0,param_1,puVar1[3]);
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



/* c08ef758 FUN_c08ef758 */

undefined4 FUN_c08ef758(int *param_1,int param_2)

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



/* c08ef8ec FUN_c08ef8ec */

/* Boundary evidence: original MIPS .pdata c08ef8ec..c08efb0f. Semantic name remains unreviewed. */

undefined4 FUN_c08ef8ec(int param_1,int param_2)

{
  uint uVar1;
  uint local_28;
  undefined4 local_24;
  int local_20 [4];
  
  if (DAT_c090aeb8 == (code *)0x0) {
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
  uVar1 = FUN_c08ef758(local_20,param_1);
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
      if (param_1 != 6) goto LAB_c08ef9a8;
      local_24._0_2_ = (ushort)local_24 | 8;
    }
    local_24 = (uint)(ushort)local_24;
  }
LAB_c08ef9a8:
  local_24 = CONCAT22(0xf0f0,(ushort)local_24);
  FUN_c08f0634(-0x3f7022a0,DAT_c090aed0,&local_28);
  CacheRangeFlush(DAT_c090abbc,0x1000,2);
  DAT_c090abc0 = (*DAT_c090aeb8)(DAT_c090abb8,DAT_c090aed0,&local_28,DAT_c090abbc);
  CacheRangeFlush(DAT_c090abbc,0x1000,4);
  local_24 = CONCAT22(0xaaf0,(ushort)local_24);
  FUN_c08f0634(-0x3f7022a0,DAT_c090aed0,&local_28);
  CacheRangeFlush(DAT_c090ac0c,0x1000,2);
  DAT_c090ac10 = (*DAT_c090aeb8)(DAT_c090ac08,DAT_c090aed0,&local_28,DAT_c090ac0c);
  CacheRangeFlush(DAT_c090ac0c,0x1000,4);
  local_28 = (local_28 << 4 ^ local_28) & 0xf0 ^ local_28;
  local_24 = CONCAT22(0xcccc,((ushort)local_24 << 2 ^ (ushort)local_24) & 0x10 ^ (ushort)local_24);
  FUN_c08f0634(-0x3f7022a0,DAT_c090aed0,&local_28);
  CacheRangeFlush(DAT_c090abe4,0x1000,2);
  DAT_c090abe8 = (*DAT_c090aeb8)(DAT_c090abe0,DAT_c090aed0,&local_28,DAT_c090abe4);
  CacheRangeFlush(DAT_c090abe4,0x1000,4);
  FUN_c08eb234(local_20);
  return 0;
}



/* c08efb10 FUN_c08efb10 */

/* Boundary evidence: original MIPS .pdata c08efb10..c08f00ab. Semantic name remains unreviewed. */

undefined4 FUN_c08efb10(int param_1,uint *param_2)

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
  uVar8 = FUN_c08ef758((int *)(*(int *)(param_1 + 4) + 0xc),*(int *)(*(int *)(param_1 + 4) + 0x1c));
  uVar8 = (uVar8 ^ *param_2) & 0xf ^ *param_2;
  *param_2 = uVar8;
  uVar8 = ((uint)(*(int *)(*(int *)(param_1 + 4) + 0x20) == 0) << 0x18 ^ uVar8) & 0x1000000 ^ uVar8;
  *param_2 = uVar8;
  if (DAT_c0908b88 != 0) {
    *param_2 = uVar8 & 0xfffffff8 | 8;
  }
  if (bVar1) {
    *param_2 = *param_2 | 0x10000000;
  }
  if (bVar2) {
    *param_2 = *param_2 | 0x20000000;
  }
  if (bVar3) {
    iVar16 = FUN_c08ef758((int *)(*(int *)(param_1 + 8) + 0xc),
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
LAB_c08efea8:
    *param_2 = uVar12;
  }
  else if (bVar4) {
    uVar12 = uVar12 & 0xfff4ffff | 0x40000;
    goto LAB_c08efea8;
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
    if (iVar9 != 6) goto LAB_c08f0054;
    uVar11 = (ushort)param_2[1] | 8;
  }
  *(ushort *)(param_2 + 1) = uVar11;
LAB_c08f0054:
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(*(int *)(param_1 + 8) + 0x1c) == 5)) {
    *(ushort *)(param_2 + 1) = (ushort)param_2[1] | 0x10;
  }
  return 1;
}



/* c08f00ac FUN_c08f00ac */

/* Boundary evidence: original MIPS .pdata c08f00ac..c08f01c7. Semantic name remains unreviewed. */

undefined4 FUN_c08f00ac(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint auStack_9a0 [95];
  undefined4 local_824;
  
  DAT_c090aed8 = DAT_c090aed8 + 1;
  if (DAT_c090aed8 == 0) {
    FUN_c08ef504();
  }
  puVar1 = FUN_c08ef684((uint *)(param_2 + 0x50));
  uVar4 = 0x80004005;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = DAT_c090aed8;
    iVar2 = puVar1[7];
    uVar3 = puVar1[6];
    puVar1[7] = iVar2 + 1U;
    if ((uVar3 < 4) && (*(uint *)(&DAT_c090aec0 + uVar3 * 4) < iVar2 + 1U)) {
      CacheRangeFlush(puVar1[3],0x1000,2);
      iVar2 = (*DAT_c090aebc)(puVar1[2],puVar1[3],uVar3 + 1);
      if (iVar2 != 0) {
        CacheRangeFlush(puVar1[3],0x1000,4);
        puVar1[6] = uVar3 + 1;
      }
    }
    FUN_c08f1278(param_2,auStack_9a0);
    (*(code *)puVar1[4])(auStack_9a0,puVar1[3]);
    uVar4 = local_824;
  }
  return uVar4;
}



/* c08f01c8 FUN_c08f01c8 */

/* Boundary evidence: original MIPS .pdata c08f01c8..c08f023b. Semantic name remains unreviewed. */

void FUN_c08f01c8(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if (((param_1[9] & 0x14) == 0) && (DAT_c090aeb8 != 0)) {
    FUN_c08efb10((int)param_1,param_1 + 0x14);
    puVar1 = FUN_c08ef684(param_1 + 0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *param_1 = FUN_c08f00ac;
    }
  }
  return;
}



/* c08f023c FUN_c08f023c */

/* Boundary evidence: original MIPS .pdata c08f023c..c08f03af. Semantic name remains unreviewed. */

int FUN_c08f023c(int param_1,int param_2)

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
    *(short *)(&DAT_c090aee0 + iVar6) = (short)((uint)iVar3 >> 0x10);
    (&DAT_c090aee2)[iVar6] = (char)((uint)iVar7 >> 0x10) - (char)((uint)iVar3 >> 0x10);
    (&DAT_c090aee3)[iVar6] = local_2c;
    iVar7 = (iVar5 + 1) * 0x10000 >> 0x10;
    if (local_2c == 0xff) {
      bVar1 = true;
    }
  } while (!bVar1);
  return (iVar7 - param_2) * 0x10000 >> 0x10;
}



/* c08f03b0 FUN_c08f03b0 */

/* Boundary evidence: original MIPS .pdata c08f03b0..c08f0633. Semantic name remains unreviewed. */

int FUN_c08f03b0(int param_1,uint param_2,int param_3)

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
      *(short *)(&DAT_c090b2e0 + iVar7) = (short)((uint)iVar8 >> 0x10);
      (&DAT_c090b2e3)[iVar7] = (char)uVar11;
      puVar6 = (uint *)(iVar9 * 4 + param_1);
      (&DAT_c090b2e2)[iVar7] = (char)((uint)iVar5 >> 0x10) - (char)((uint)iVar8 >> 0x10);
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



/* c08f0634 FUN_c08f0634 */

/* Boundary evidence: original MIPS .pdata c08f0634..c08f096b. Semantic name remains unreviewed. */

undefined4 FUN_c08f0634(int param_1,int param_2,uint *param_3)

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
  
  uVar7 = FUN_c08f10b4(param_3);
  uVar6 = *param_3;
  bVar2 = *(byte *)((int)param_3 + 6);
  bVar3 = *(byte *)((int)param_3 + 7);
  iVar9 = 0;
  iVar12 = 0;
  if (0 < DAT_c090aedc) {
    psVar14 = &DAT_c090b6e0;
    iVar15 = DAT_c090aedc;
    do {
      uVar11 = (uint)bVar2;
      if (iVar9 <= *psVar14) {
        iVar10 = (int)psVar14[1];
        sVar8 = (short)iVar9;
        if (iVar10 == 0x19) {
          if ((uVar7 & 0x1000000) != 0) {
            if (uVar11 == bVar3) {
              pbVar13 = &DAT_c090aee2 + uVar11 * 4;
              sVar5 = *(short *)(&DAT_c090aee0 + uVar11 * 4);
              bVar4 = *pbVar13;
LAB_c08f07e4:
              memcpy((void *)(iVar12 * 4 + param_2),(void *)(sVar5 * 4 + param_1),(uint)bVar4 << 2);
              iVar12 = (uint)*pbVar13 + iVar12;
            }
            else {
              memcpy((void *)(iVar12 * 4 + param_2),
                     (void *)((*(short *)(&DAT_c090aee0 + uVar11 * 4) + -3) * 4 + param_1),
                     ((byte)(&DAT_c090aee2)[uVar11 * 4] + 4) * 4);
              iVar9 = (uint)bVar3 * 4;
              iVar12 = (int)(((uint)(byte)(&DAT_c090aee2)[uVar11 * 4] + iVar12 + 4) * 0x10000) >>
                       0x10;
              memcpy((void *)(iVar12 * 4 + param_2),
                     (void *)((*(short *)(&DAT_c090aee0 + iVar9) + -3) * 4 + param_1),
                     ((byte)(&DAT_c090aee2)[iVar9] + 4) * 4);
              iVar12 = (uint)(byte)(&DAT_c090aee2)[iVar9] + iVar12 + 4;
            }
            iVar12 = iVar12 * 0x10000 >> 0x10;
          }
LAB_c08f07fc:
          sVar8 = psVar14[3] + sVar8 + 2;
        }
        else {
          if (iVar10 == 0x13) {
            if ((uVar7 & 0x40000) != 0) {
              iVar9 = (uint)(byte)uVar6 * 4;
              pbVar13 = &DAT_c090b2e2 + iVar9;
              sVar5 = *(short *)(&DAT_c090b2e0 + iVar9);
              bVar4 = *pbVar13;
              goto LAB_c08f07e4;
            }
            goto LAB_c08f07fc;
          }
          if (iVar10 < 1) {
            if (iVar10 < 0) {
              bVar1 = (1 << (-iVar10 - 1U & 0x1f) & uVar7) == 0;
              sVar8 = sVar8 + 1;
              goto LAB_c08f0898;
            }
            memcpy((void *)(iVar12 * 4 + param_2),(void *)(iVar9 * 4 + param_1),(int)psVar14[2] << 2
                  );
            iVar12 = (psVar14[2] + iVar12) * 0x10000 >> 0x10;
            sVar8 = psVar14[3] + sVar8;
          }
          else {
            bVar1 = (1 << (iVar10 - 1U & 0x1f) & uVar7) != 0;
            sVar8 = sVar8 + 2;
LAB_c08f0898:
            iVar9 = (int)sVar8;
            if (bVar1) goto LAB_c08f091c;
            sVar8 = psVar14[3] + sVar8;
          }
        }
        iVar9 = (int)sVar8;
      }
LAB_c08f091c:
      psVar14 = psVar14 + 4;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  return 1;
}



/* c08f096c FUN_c08f096c */

/* Boundary evidence: original MIPS .pdata c08f096c..c08f0dcf. Semantic name remains unreviewed. */

int FUN_c08f096c(int param_1,uint param_2,uint param_3,int param_4,short param_5)

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
  sVar1 = (&DAT_c090b6e2)[param_4 * 4];
  bVar2 = false;
  iVar14 = 0;
  local_58 = 0;
  local_5e = param_5;
  bVar3 = false;
  iVar15 = DAT_c090aedc;
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
        *(undefined2 *)((int)&DAT_c090b6e4 + iVar17) = uVar13;
        *(undefined2 *)((int)&DAT_c090b6e6 + iVar17) = uVar13;
        iVar14 = 0;
      }
      uVar5 = local_38[0] & 0x1f;
      iVar17 = iVar15 * 8;
      DAT_c090aedc = iVar15 + 1;
      (&DAT_c090b6e2)[iVar15 * 4] = (short)uVar5 + 1;
      (&DAT_c090b6e6)[iVar15 * 4] = 0;
      (&DAT_c090b6e0)[iVar15 * 4] = uVar10;
      iVar12 = (iVar12 + iVar7) * 0x10000;
      (&DAT_c090b6e4)[iVar15 * 4] = 0;
      iVar7 = iVar12 >> 0x10;
      sVar11 = (short)((uint)iVar12 >> 0x10);
      bVar2 = bVar3;
      if (uVar5 == 0x12) {
        iVar12 = FUN_c08f03b0(param_1,uVar4,iVar7);
        iVar12 = iVar12 + iVar7;
        iVar7 = FUN_c08f096c(param_1,uVar9,uVar4,iVar15,(short)iVar12);
      }
      else {
        if (uVar5 != 0x18) {
          iVar12 = FUN_c08f096c(param_1,uVar9,uVar4,iVar15,sVar11);
          iVar12 = iVar12 + iVar7;
          iVar16 = DAT_c090aedc;
          goto LAB_c08f0d24;
        }
        iVar12 = FUN_c08f023c(param_1,iVar7);
        iVar12 = iVar12 + iVar7;
        iVar7 = FUN_c08f096c(param_1,uVar9,uVar4,iVar15,(short)iVar12);
      }
      iVar16 = DAT_c090aedc;
      iVar12 = (iVar7 + iVar12) * 0x10000;
      (&DAT_c090b6e6)[iVar15 * 4] = (short)((uint)iVar12 >> 0x10) - sVar11;
LAB_c08f0d28:
      iVar7 = (int)local_5e;
      iVar12 = iVar12 >> 0x10;
    }
    else {
      if (uVar6 != param_2) {
        if (uVar6 == param_3) {
          if (0 < iVar14) {
            *(undefined2 *)((int)&DAT_c090b6e4 + iVar17) = uVar13;
            *(undefined2 *)((int)&DAT_c090b6e6 + iVar17) = uVar13;
          }
          iVar17 = iVar15 * 8;
          (&DAT_c090b6e0)[iVar15 * 4] = uVar10;
          iVar16 = iVar15 + 1;
          DAT_c090aedc = iVar16;
          (&DAT_c090b6e2)[iVar15 * 4] = 0;
          (&DAT_c090b6e4)[iVar15 * 4] = 0;
          (&DAT_c090b6e6)[iVar15 * 4] = (short)iVar7;
        }
        else {
          iVar16 = iVar15;
          if (iVar14 == 0) {
            iVar17 = iVar15 * 8;
            (&DAT_c090b6e0)[iVar15 * 4] = uVar10;
            iVar16 = iVar15 + 1;
            DAT_c090aedc = iVar16;
            (&DAT_c090b6e2)[iVar15 * 4] = 0;
            (&DAT_c090b6e4)[iVar15 * 4] = 0;
            (&DAT_c090b6e6)[iVar15 * 4] = 0;
          }
          iVar14 = (iVar14 + iVar7) * 0x10000 >> 0x10;
        }
        iVar12 = iVar12 + iVar7;
LAB_c08f0d24:
        iVar12 = iVar12 * 0x10000;
        goto LAB_c08f0d28;
      }
      bVar2 = true;
      bVar3 = true;
      if (0 < iVar14) {
        *(undefined2 *)((int)&DAT_c090b6e4 + iVar17) = uVar13;
        *(undefined2 *)((int)&DAT_c090b6e6 + iVar17) = uVar13;
        iVar14 = 0;
      }
      (&DAT_c090b6e0)[iVar15 * 4] = uVar10;
      (&DAT_c090b6e2)[iVar15 * 4] = -sVar1;
      iVar12 = (iVar12 + iVar7) * 0x10000;
      iVar7 = iVar12 >> 0x10;
      iVar16 = iVar15 + 1;
      DAT_c090aedc = iVar16;
      (&DAT_c090b6e4)[iVar15 * 4] = 0;
      (&DAT_c090b6e6)[iVar15 * 4] = 0;
      local_5e = (short)((uint)iVar12 >> 0x10);
      iVar12 = iVar7;
      local_58 = iVar15;
    }
    iVar15 = iVar16;
    if (uVar6 == param_3) {
      if (bVar2) {
        (&DAT_c090b6e6)[param_4 * 4] = ((short)iVar7 - param_5) + -1;
        (&DAT_c090b6e6)[local_58 * 4] = (short)iVar12 - (short)iVar7;
      }
      else {
        (&DAT_c090b6e6)[param_4 * 4] = (short)iVar12 - param_5;
      }
      return (iVar12 - param_5) * 0x10000 >> 0x10;
    }
  } while( true );
}



/* c08f0dd0 FUN_c08f0dd0 */

/* Boundary evidence: original MIPS .pdata c08f0dd0..c08f10b3. Semantic name remains unreviewed. */

undefined4 FUN_c08f0dd0(int param_1)

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
  
  DAT_c090aedc = 0;
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
        (&DAT_c090b6e4)[iVar10 * 4] = (short)iVar9;
        (&DAT_c090b6e6)[iVar10 * 4] = (short)iVar9;
        iVar9 = 0;
      }
      DAT_c090aedc = iVar7 + 1;
      uVar5 = local_38[0] & 0x1f;
      iVar10 = (iVar11 + iVar4) * 0x10000;
      (&DAT_c090b6e0)[iVar7 * 4] = (short)iVar11;
      (&DAT_c090b6e2)[iVar7 * 4] = (short)uVar5 + 1;
      iVar4 = iVar10 >> 0x10;
      sVar1 = (short)((uint)iVar10 >> 0x10);
      if (uVar5 == 0x12) {
        iVar11 = FUN_c08f03b0(param_1,uVar2,iVar4);
        iVar11 = iVar11 + iVar4;
        iVar10 = FUN_c08f096c(param_1,uVar12,uVar2,iVar7,(short)iVar11);
      }
      else {
        if (uVar5 != 0x18) {
          iVar11 = FUN_c08f096c(param_1,uVar12,uVar2,iVar7,sVar1);
          iVar11 = iVar11 + iVar4;
          iVar8 = DAT_c090aedc;
          iVar10 = iVar7;
          goto LAB_c08f1040;
        }
        iVar11 = FUN_c08f023c(param_1,iVar4);
        iVar11 = iVar11 + iVar4;
        iVar10 = FUN_c08f096c(param_1,uVar12,uVar2,iVar7,(short)iVar11);
      }
      iVar8 = DAT_c090aedc;
      iVar11 = (iVar10 + iVar11) * 0x10000;
      (&DAT_c090b6e6)[iVar7 * 4] = (short)((uint)iVar11 >> 0x10) - sVar1;
      iVar10 = iVar7;
    }
    else {
      iVar8 = iVar7;
      if (iVar9 == 0) {
        (&DAT_c090b6e0)[iVar7 * 4] = (short)iVar11;
        iVar8 = iVar7 + 1;
        DAT_c090aedc = iVar8;
        (&DAT_c090b6e2)[iVar7 * 4] = 0;
        (&DAT_c090b6e4)[iVar7 * 4] = 0;
        (&DAT_c090b6e6)[iVar7 * 4] = 0;
        iVar10 = iVar7;
      }
      iVar11 = iVar11 + iVar4;
      iVar9 = (iVar9 + iVar4) * 0x10000 >> 0x10;
LAB_c08f1040:
      iVar11 = iVar11 * 0x10000;
    }
    iVar11 = iVar11 >> 0x10;
    iVar7 = iVar8;
    if (uVar3 == 0x1f000000) {
      if (0 < iVar9) {
        (&DAT_c090b6e4)[iVar10 * 4] = (short)iVar9;
        (&DAT_c090b6e6)[iVar10 * 4] = (short)iVar9;
      }
      return 1;
    }
  } while( true );
}



/* c08f10b4 FUN_c08f10b4 */

uint FUN_c08f10b4(uint *param_1)

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
    goto LAB_c08f1260;
  }
  if ((uVar2 & 8) == 0) {
    if ((uVar2 & 1) != 0) {
      uVar4 = uVar4 | 0x4000000;
      goto LAB_c08f1260;
    }
    if ((uVar2 & 4) == 0) goto LAB_c08f1260;
    uVar5 = 0x10000000;
  }
  else {
    uVar5 = 0x20000000;
  }
  uVar4 = uVar4 | uVar5;
LAB_c08f1260:
  if ((uVar2 >> 4 & 1) != 0) {
    uVar4 = uVar4 | 0x2000000;
  }
  return uVar4;
}



/* c08f1278 FUN_c08f1278 */

/* WARNING: Removing unreachable block (ram,0xc08f1cfc) */
/* WARNING: Removing unreachable block (ram,0xc08f1af4) */
/* WARNING: Removing unreachable block (ram,0xc08f2004) */
/* Boundary evidence: original MIPS .pdata c08f1278..c08f2273. Semantic name remains unreviewed. */

void FUN_c08f1278(int param_1,uint *param_2)

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
  if (((*puVar16 & 0xf) == 8) && (DAT_c0908b88 != 0)) {
    param_2[0x60] = **(uint **)(DAT_c0908b88 + 0x10);
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
             (1 << (*(uint *)(&LAB_c08d284c + *(int *)(iVar3 + 0x1c) * 4) & 0x1f)) << 2);
    }
  }
  uVar7 = FUN_c08f10b4(puVar16);
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
  if ((uVar7 & 0x80000) == 0) goto LAB_c08f18ac;
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
      if (uVar8 == 0) goto LAB_c08f177c;
    }
    else if (uVar8 == 0) {
      iVar15 = iVar18 - iVar20;
    }
    else {
LAB_c08f177c:
      iVar15 = iVar14 - iVar21;
    }
    if ((uVar7 & 4) == 0) {
      iVar19 = iVar11 - iVar13;
      if (uVar4 == 0) goto LAB_c08f17a4;
    }
    else if (uVar4 == 0) {
      iVar19 = iVar11 - iVar13;
    }
    else {
LAB_c08f17a4:
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
      if ((uVar7 & 8) == 0) goto LAB_c08f1874;
      uVar8 = param_2[0x20];
      if (-1 < (int)uVar8) {
        param_2[0x20] = param_2[3] + uVar8;
        goto LAB_c08f1874;
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
LAB_c08f1874:
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
LAB_c08f18ac:
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
    iVar17 = *(int *)(&LAB_c08d284c + *(int *)(iVar12 + 0x1c) * 4);
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
    iVar17 = *(int *)(&LAB_c08d284c + *(int *)(iVar17 + 0x1c) * 4);
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
    iVar3 = *(int *)(&LAB_c08d284c + *(int *)(iVar3 + 0x1c) * 4);
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
    iVar3 = *(int *)(&LAB_c08d284c + *(int *)(*(int *)(param_1 + 4) + 0x1c) * 4);
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



/* c08f2274 FUN_c08f2274 */

/* Boundary evidence: original MIPS .pdata c08f2274..c08f22ef. Semantic name remains unreviewed. */

void FUN_c08f2274(int *param_1,int *param_2,int param_3,uint *param_4,int *param_5,int *param_6,
                 undefined4 *param_7)

{
  FUN_c08e31fc(param_1,param_2,(int *)0x0,param_3,param_4,param_5,param_6,(int *)0x0,(int *)0x0,0,
               0xcccc,0x10,1,*param_7);
  return;
}



/* c08f22f0 FUN_c08f22f0 */

undefined4 FUN_c08f22f0(undefined4 *param_1)

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



/* c08f2420 FUN_c08f2420 */

/* Boundary evidence: original MIPS .pdata c08f2420..c08f255b. Semantic name remains unreviewed. */

int FUN_c08f2420(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c090c9e0 != (code *)0x0) {
      iVar2 = (*DAT_c090c9e0)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c08f24d0;
    FUN_c08f28b4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c08e189c(param_1,param_2);
  }
LAB_c08f24d0:
  if (((param_2 == 0) && (FUN_c08f283c(), iVar1 != 0)) && (DAT_c090c9e0 != (code *)0x0)) {
    iVar1 = (*DAT_c090c9e0)(param_1,0,param_3);
  }
  return iVar1;
}



/* c08f255c FUN_c08f255c */

/* Boundary evidence: original MIPS .pdata c08f255c..c08f2587. Semantic name remains unreviewed. */

void FUN_c08f255c(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c08f2588 entry */

/* Boundary evidence: original MIPS .pdata c08f2588..c08f25df. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c08f25e0();
  }
  FUN_c08f2420(param_1,param_2,param_3);
  return;
}



/* c08f25e0 FUN_c08f25e0 */

/* Boundary evidence: original MIPS .pdata c08f25e0..c08f2653. Semantic name remains unreviewed. */

void FUN_c08f25e0(void)

{
  uint uVar1;
  
  if ((DAT_c0906fb8 == 0) || (DAT_c0906fb8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0906fb8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0906fb8 == 0) {
      DAT_c0906fb8 = 0xb064;
    }
  }
  DAT_c0906fbc = ~DAT_c0906fb8;
  return;
}



/* c08f2654 FUN_c08f2654 */

/* Boundary evidence: original MIPS .pdata c08f2654..c08f26a7. Semantic name remains unreviewed. */

void FUN_c08f2654(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c08f26d4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c08f26a8 FUN_c08f26a8 */

/* Boundary evidence: original MIPS .pdata c08f26a8..c08f26d3. Semantic name remains unreviewed. */

undefined4 FUN_c08f26a8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c08f2654(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c08f26d4 FUN_c08f26d4 */

/* Boundary evidence: original MIPS .pdata c08f26d4..c08f271b. Semantic name remains unreviewed. */

void FUN_c08f26d4(uint param_1)

{
  if ((param_1 == DAT_c0906fb8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c08f271c FUN_c08f271c */

/* Boundary evidence: original MIPS .pdata c08f271c..c08f283b. Semantic name remains unreviewed. */

void FUN_c08f271c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c090c6e4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c090c9d8;
    if (DAT_c090c9d8 != (undefined4 *)0x0) {
      while (DAT_c090c9d4 = DAT_c090c9d4 + -1, _Memory <= DAT_c090c9d4) {
        if ((code *)*DAT_c090c9d4 != (code *)0x0) {
          (*(code *)*DAT_c090c9d4)();
          _Memory = DAT_c090c9d8;
        }
      }
      free(_Memory);
      DAT_c090c9d4 = (undefined4 *)0x0;
      DAT_c090c9d8 = (undefined4 *)0x0;
    }
    FUN_c08f2860((undefined4 *)&DAT_c08d1014,(undefined4 *)&DAT_c08d1018);
  }
  FUN_c08f2860((undefined4 *)&DAT_c08d101c,(undefined4 *)&DAT_c08d1020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c090c9dc,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c08f283c FUN_c08f283c */

/* Boundary evidence: original MIPS .pdata c08f283c..c08f285f. Semantic name remains unreviewed. */

void FUN_c08f283c(void)

{
  FUN_c08f271c(0,0,1);
  return;
}



/* c08f2860 FUN_c08f2860 */

/* Boundary evidence: original MIPS .pdata c08f2860..c08f28b3. Semantic name remains unreviewed. */

void FUN_c08f2860(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c08f28b4 FUN_c08f28b4 */

/* Boundary evidence: original MIPS .pdata c08f28b4..c08f28ef. Semantic name remains unreviewed. */

void FUN_c08f28b4(void)

{
  FUN_c08f2860((undefined4 *)&DAT_c08d100c,(undefined4 *)&DAT_c08d1010);
  FUN_c08f2860((undefined4 *)&DAT_c08d1000,(undefined4 *)&DAT_c08d1008);
  return;
}



/* c08f29b0 FUN_c08f29b0 */

undefined4 FUN_c08f29b0(undefined4 param_1)

{
  DAT_c090c798 = param_1;
  return 1;
}



/* c08f29c0 FUN_c08f29c0 */

/* Boundary evidence: original MIPS .pdata c08f29c0..c08f2bd3. Semantic name remains unreviewed. */

undefined4 FUN_c08f29c0(undefined4 param_1,int param_2)

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
    puVar11 = &DAT_c08d2a68;
  }
  else if (cVar1 == -1) {
    puVar11 = &UNK_c08d2a58;
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
              pcVar2 = (char *)FUN_c08eb100(*(int *)(param_2 + 4),iVar3,iVar13);
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



/* c08f2bd4 FUN_c08f2bd4 */

/* Boundary evidence: original MIPS .pdata c08f2bd4..c08f2d53. Semantic name remains unreviewed. */

void FUN_c08f2bd4(double param_1,double param_2,int param_3)

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



/* c08f2d54 FUN_c08f2d54 */

uint FUN_c08f2d54(uint *param_1,uint param_2,int param_3)

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



/* c08f2e60 FUN_c08f2e60 */

/* Boundary evidence: original MIPS .pdata c08f2e60..c08f2fb3. Semantic name remains unreviewed. */

void FUN_c08f2e60(int param_1)

{
  int iVar1;
  uint local_18;
  uint local_14;
  uint local_10 [2];
  
  if (DAT_c090c798 == (code *)0x0) {
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
    (*DAT_c090c798)(&local_18,&local_14,local_10);
  }
  DAT_c090c6e8 = local_18;
  DAT_c090c6ec = local_14;
  iVar1 = 0;
  DAT_c090c6f0 = local_10[0];
  for (; local_18 != 0; local_18 = local_18 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c090c6f8 = iVar1 + -8;
  iVar1 = 0;
  for (; local_14 != 0; local_14 = local_14 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c090c700 = iVar1 + -8;
  iVar1 = 0;
  for (; local_10[0] != 0; local_10[0] = local_10[0] >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c090c708 = iVar1 + -8;
  DAT_c090c6f4 = 0;
  if (DAT_c090c6f8 < 0) {
    DAT_c090c6f4 = -DAT_c090c6f8;
    DAT_c090c6f8 = 0;
  }
  DAT_c090c6fc = 0;
  if (DAT_c090c700 < 0) {
    DAT_c090c6fc = -DAT_c090c700;
    DAT_c090c700 = 0;
  }
  DAT_c090c704 = 0;
  if (DAT_c090c708 < 0) {
    DAT_c090c704 = -DAT_c090c708;
    DAT_c090c708 = 0;
  }
  return;
}



/* c08f2fb4 FUN_c08f2fb4 */

/* Boundary evidence: original MIPS .pdata c08f2fb4..c08f30ab. Semantic name remains unreviewed. */

void FUN_c08f2fb4(double param_1,double param_2)

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
  FUN_c08f2bd4(param_1,param_2,-0x3f6f3918);
  return;
}



/* c08f30ac FUN_c08f30ac */

/* Boundary evidence: original MIPS .pdata c08f30ac..c08f31d3. Semantic name remains unreviewed. */

undefined4 FUN_c08f30ac(double param_1,double param_2,uint param_3,int param_4)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_res0 [4];
  HKEY local_10;
  DWORD DStack_c;
  
  local_res0[0] = param_3;
  if (param_4 == 0) {
LAB_c08f3178:
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
    FUN_c08f2bd4(param_1,param_2,-0x3f6f3918);
    return 1;
  }
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"System\\GDI\\Gamma",0,(LPWSTR)0x0,0,0,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_10,&DStack_c);
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_10,L"Gamma Value",0,4,(BYTE *)local_res0,4);
    if (LVar1 == 0) {
      RegCloseKey(local_10);
      goto LAB_c08f3178;
    }
    RegCloseKey(local_10);
  }
  return 0;
}



/* c08f31d4 FUN_c08f31d4 */

/* Boundary evidence: original MIPS .pdata c08f31d4..c08f347b. Semantic name remains unreviewed. */

undefined4 FUN_c08f31d4(double param_1,double param_2,undefined4 param_3,int param_4)

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
  if (DAT_c090c79c == '\0') {
    FUN_c08f2e60(0x10);
    FUN_c08f2fb4(param_1,param_2);
    DAT_c090c79c = '\x01';
  }
  uVar12 = (uint)uVar1;
  DAT_c090c70c = ((DAT_c090c6e8 & uVar12) >> (DAT_c090c6f8 & 0x1f)) << (DAT_c090c6f4 & 0x1f);
  DAT_c090c710 = ((DAT_c090c6ec & uVar12) >> (DAT_c090c700 & 0x1f)) << (DAT_c090c6fc & 0x1f);
  DAT_c090c714 = ((DAT_c090c6f0 & uVar12) >> (DAT_c090c708 & 0x1f)) << (DAT_c090c704 & 0x1f);
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
              puVar2 = (ushort *)FUN_c08eb100(*(int *)(param_4 + 4),iVar9,iVar4);
            }
            if (uVar8 == 0xf) {
              *puVar2 = uVar1;
            }
            else {
              uVar8 = FUN_c08f2d54(&DAT_c090c6e8,(uint)*puVar2,uVar8);
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



/* c08f347c FUN_c08f347c */

/* Boundary evidence: original MIPS .pdata c08f347c..c08f3757. Semantic name remains unreviewed. */

undefined4 FUN_c08f347c(double param_1,double param_2,undefined4 param_3,int param_4)

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
  if (DAT_c090c79c == '\0') {
    FUN_c08f2e60(0x18);
    FUN_c08f2fb4(param_1,param_2);
    DAT_c090c79c = '\x01';
  }
  DAT_c090c70c = ((DAT_c090c6e8 & uVar12) >> (DAT_c090c6f8 & 0x1f)) << (DAT_c090c6f4 & 0x1f);
  DAT_c090c710 = ((DAT_c090c6ec & uVar12) >> (DAT_c090c700 & 0x1f)) << (DAT_c090c6fc & 0x1f);
  DAT_c090c714 = ((DAT_c090c6f0 & uVar12) >> (DAT_c090c708 & 0x1f)) << (DAT_c090c704 & 0x1f);
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
              puVar2 = (uint3 *)FUN_c08eb100(*(int *)(param_4 + 4),iVar8,iVar4);
            }
            local_50 = uVar12;
            if (uVar7 != 0xf) {
              local_50 = FUN_c08f2d54(&DAT_c090c6e8,(uint)*puVar2,uVar7);
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



/* c08f3758 FUN_c08f3758 */

/* Boundary evidence: original MIPS .pdata c08f3758..c08f39f3. Semantic name remains unreviewed. */

undefined4 FUN_c08f3758(double param_1,double param_2,undefined4 param_3,int param_4)

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
  if (DAT_c090c79c == '\0') {
    FUN_c08f2e60(0x20);
    FUN_c08f2fb4(param_1,param_2);
    DAT_c090c79c = '\x01';
  }
  DAT_c090c70c = ((DAT_c090c6e8 & uVar6) >> (DAT_c090c6f8 & 0x1f)) << (DAT_c090c6f4 & 0x1f);
  DAT_c090c710 = ((DAT_c090c6ec & uVar6) >> (DAT_c090c700 & 0x1f)) << (DAT_c090c6fc & 0x1f);
  DAT_c090c714 = ((DAT_c090c6f0 & uVar6) >> (DAT_c090c708 & 0x1f)) << (DAT_c090c704 & 0x1f);
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
              puVar2 = (uint *)FUN_c08eb100(*(int *)(param_4 + 4),iVar8,iVar4);
            }
            if (uVar7 == 0xf) {
              *puVar2 = uVar6;
            }
            else {
              uVar7 = FUN_c08f2d54(&DAT_c090c6e8,*puVar2,uVar7);
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



/* c08f39f4 FUN_c08f39f4 */

undefined4 FUN_c08f39f4(undefined4 *param_1)

{
  int iVar1;
  
  if (((param_1[10] & 0xffff) == 0xaaf0) && (*(int *)(param_1[3] + 0x1c) == 2)) {
    iVar1 = *(int *)(&LAB_c08d284c + *(int *)(param_1[1] + 0x1c) * 4);
    if (iVar1 < 0x19) {
      if (iVar1 == 0x18) {
        *param_1 = FUN_c08f347c;
        return 0;
      }
      if (iVar1 == 8) {
        *param_1 = FUN_c08f29c0;
        return 0;
      }
      if (iVar1 == 0x10) {
        *param_1 = FUN_c08f31d4;
        return 0;
      }
    }
    else if (iVar1 == 0x20) {
      *param_1 = FUN_c08f3758;
    }
  }
  return 0;
}



/* c08f3ad0 FUN_c08f3ad0 */

undefined4 FUN_c08f3ad0(undefined4 *param_1)

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
        *param_1 = FUN_c08f8088;
        return 0;
      }
      if (*(int *)(param_1[3] + 0x1c) != 2) {
        return 0;
      }
      pcVar2 = FUN_c08f8064;
      goto LAB_c08f3d08;
    }
    if (uVar3 != 0) {
      if (uVar3 == 0x5555) {
        pcVar2 = FUN_c08f8338;
      }
      else if (uVar3 == 0x5a5a) {
        if (param_1[8] != -1) {
          pcVar2 = FUN_c08f8494;
          goto LAB_c08f3d08;
        }
        pcVar2 = FUN_c08f8614;
      }
      else if (uVar3 == 0x6666) {
        if (param_1[2] == 0) {
          return 0;
        }
        if (*(int *)(param_1[2] + 0x1c) != 3) {
          return 0;
        }
        pcVar2 = FUN_c08f8964;
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
        pcVar2 = FUN_c08f8dcc;
      }
      goto LAB_c08f3d20;
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
        pcVar2 = FUN_c08f731c;
      }
      else {
        if (iVar1 != 2) {
          if (iVar1 != 0) {
            return 0;
          }
          pcVar2 = FUN_c08f6b08;
          goto LAB_c08f3d20;
        }
        pcVar2 = FUN_c08f7108;
      }
      goto LAB_c08f3d08;
    }
    if (uVar3 == 0xeeee) {
      if (param_1[2] == 0) {
        return 0;
      }
      if (*(int *)(param_1[2] + 0x1c) != 3) {
        return 0;
      }
      pcVar2 = FUN_c08f7720;
LAB_c08f3d20:
      *param_1 = pcVar2;
      return 0;
    }
    if (uVar3 != 0xf0f0) {
      if (uVar3 != 0xffff) {
        return 0;
      }
      param_1[8] = 0xffffff;
      pcVar2 = FUN_c08f8250;
      goto LAB_c08f3d20;
    }
    if (param_1[8] == -1) {
      pcVar2 = FUN_c08f7b88;
      goto LAB_c08f3d20;
    }
  }
  pcVar2 = FUN_c08f8250;
LAB_c08f3d08:
  *param_1 = pcVar2;
  return 0;
}



/* c08f3d2c FUN_c08f3d2c */

undefined4 FUN_c08f3d2c(undefined4 *param_1)

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
        pcVar1 = FUN_c08f9f18;
      }
      else {
        if (iVar2 != 2) {
          if (iVar2 != 0) {
            return 0;
          }
          pcVar1 = FUN_c08f96d0;
          goto LAB_c08f3f18;
        }
        pcVar1 = FUN_c08f9cf4;
      }
      goto LAB_c08f3e50;
    }
    if (uVar3 != 0) {
      if (uVar3 == 0x6666) {
        if (param_1[2] == 0) {
          return 0;
        }
        if (*(int *)(param_1[2] + 0x1c) != 4) {
          return 0;
        }
        pcVar1 = FUN_c08fa450;
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
            pcVar1 = FUN_c08fada0;
          }
          else {
            if (*(int *)(param_1[3] + 0x1c) != 2) {
              return 0;
            }
            pcVar1 = FUN_c08fad7c;
          }
          goto LAB_c08f3e50;
        }
        if (param_1[2] == 0) {
          return 0;
        }
        if (*(int *)(param_1[2] + 0x1c) != 4) {
          return 0;
        }
        pcVar1 = FUN_c08fa8e0;
      }
      goto LAB_c08f3f18;
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
      pcVar1 = FUN_c08f9234;
LAB_c08f3f18:
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
  pcVar1 = FUN_c08fa33c;
LAB_c08f3e50:
  *param_1 = pcVar1;
  return 0;
}



/* c08f3f24 FUN_c08f3f24 */

undefined4 FUN_c08f3f24(int param_1)

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



/* c08f3f98 FUN_c08f3f98 */

undefined4 FUN_c08f3f98(int param_1)

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



/* c08f401c FUN_c08f401c */

/* Boundary evidence: original MIPS .pdata c08f401c..c08f4113. Semantic name remains unreviewed. */

undefined4 FUN_c08f401c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (((((*(int *)(param_1 + 0x28) != 0xcccc) || ((*(uint *)(param_1 + 0x24) & 0x10) == 0)) ||
       (iVar1 = FUN_c08f3f98(*(int *)(param_1 + 8)), iVar1 == 0)) ||
      (((iVar1 = FUN_c08f3f24(*(int *)(param_1 + 4)), iVar1 == 0 || (*(int *)(param_1 + 0x10) != 0))
       || ((*(int *)(param_1 + 0xc) != 0 ||
           ((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x40) == 0)))))))) ||
     ((*(int *)(param_1 + 0x34) == 0 ||
      ((((*(int *)(param_1 + 0x38) == 0 || (piVar3 = *(int **)(param_1 + 0x14), piVar3[2] < *piVar3)
         ) || (piVar3[3] < piVar3[1])) || (uVar2 = 1, *(int *)(param_1 + 0x4c) == 0xff0000)))))) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c08f4114 FUN_c08f4114 */

/* Boundary evidence: original MIPS .pdata c08f4114..c08f496b. Semantic name remains unreviewed. */

undefined4 FUN_c08f4114(undefined4 param_1,int param_2)

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
          if (!bVar2) goto LAB_c08f4400;
          if (-1 < local_78) goto LAB_c08f43fc;
          local_78 = iVar25 + local_78;
        }
        else {
          for (; local_78 < 0; local_78 = iVar25 + local_78) {
            iVar17 = iVar17 + 1;
          }
LAB_c08f43fc:
          local_78 = iVar26 + local_78;
LAB_c08f4400:
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
                goto LAB_c08f4624;
              }
              do {
                iVar18 = iVar25 + iVar18;
                puVar22 = puVar22 + 1;
              } while (iVar18 < 0);
            }
            iVar18 = iVar26 + iVar18;
          }
LAB_c08f4624:
          uVar15 = 0xff;
          if ((cVar1 != '\x01') || (uVar15 = uVar10 >> 0x18, uVar15 != 0)) {
            uVar13 = (uint)*puVar24;
            uVar11 = 3;
            if (uVar15 == 0xff) {
              if (uVar12 != 0xff) {
                uVar11 = 1;
                goto LAB_c08f4680;
              }
              uVar11 = uVar10 >> 3 & 0x1f0000 | uVar10 & 0xfc00;
              uVar15 = uVar10;
            }
            else {
              if (uVar12 == 0xff) {
                uVar11 = 2;
              }
LAB_c08f4680:
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



/* c08f496c FUN_c08f496c */

/* Boundary evidence: original MIPS .pdata c08f496c..c08f49bb. Semantic name remains unreviewed. */

undefined4 FUN_c08f496c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c08f401c(param_1);
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



/* c08f49bc FUN_c08f49bc */

/* Boundary evidence: original MIPS .pdata c08f49bc..c08f4deb. Semantic name remains unreviewed. */

undefined4 FUN_c08f49bc(undefined4 param_1,int param_2)

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
                  goto LAB_c08f4b40;
                }
                uVar10 = uVar2 >> 3 & 0x1f0000 | uVar2 & 0xfc00;
                uVar9 = uVar2;
              }
              else {
                if (uVar8 == 0xff) {
                  uVar3 = 2;
                }
LAB_c08f4b40:
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



/* c08f4dec FUN_c08f4dec */

undefined4 FUN_c08f4dec(int param_1)

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



/* c08f4e88 FUN_c08f4e88 */

/* Boundary evidence: original MIPS .pdata c08f4e88..c08f4fff. Semantic name remains unreviewed. */

undefined4
FUN_c08f4e88(uint *param_1,uint param_2,uint *param_3,uint param_4,int param_5,int param_6,
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



/* c08f5000 FUN_c08f5000 */

/* Boundary evidence: original MIPS .pdata c08f5000..c08f527b. Semantic name remains unreviewed. */

undefined4 FUN_c08f5000(undefined4 param_1,int param_2)

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
      uVar3 = FUN_c08f4e88(puVar16,uVar14,puVar4,uVar13,uVar5,iVar2,uVar9);
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



/* c08f527c FUN_c08f527c */

/* Boundary evidence: original MIPS .pdata c08f527c..c08f5337. Semantic name remains unreviewed. */

undefined4 FUN_c08f527c(int param_1)

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
     ((iVar1 = FUN_c08f3f24(iVar4), iVar1 == 0 ||
      ((iVar1 = FUN_c08f3f24(iVar3), iVar1 == 0 || (uVar2 = 1, iVar4 == iVar3)))))) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c08f5338 FUN_c08f5338 */

/* Boundary evidence: original MIPS .pdata c08f5338..c08f5577. Semantic name remains unreviewed. */

undefined4 FUN_c08f5338(undefined4 param_1,int param_2)

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



/* c08f5578 FUN_c08f5578 */

undefined4 FUN_c08f5578(int param_1)

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



/* c08f56f0 FUN_c08f56f0 */

undefined4 FUN_c08f56f0(int param_1)

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



/* c08f579c FUN_c08f579c */

/* Boundary evidence: original MIPS .pdata c08f579c..c08f5843. Semantic name remains unreviewed. */

undefined4 FUN_c08f579c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((((*(int *)(param_1 + 0x28) != 0xcccc) || (*(int *)(param_1 + 0x20) != -1)) ||
        (iVar1 = FUN_c08f3f98(*(int *)(param_1 + 8)), iVar1 == 0)) ||
       ((iVar1 = FUN_c08f3f24(*(int *)(param_1 + 4)), iVar1 == 0 ||
        ((*(uint *)(param_1 + 0x24) & 0x1c) != 0)))) ||
      ((*(int *)(param_1 + 0x10) != 0 ||
       ((*(int *)(param_1 + 0xc) != 0 || (*(int *)(param_1 + 0x3c) != 0)))))) ||
     (uVar2 = 1, *(int *)(param_1 + 0x40) == 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c08f5924 FUN_c08f5924 */

/* Boundary evidence: original MIPS .pdata c08f5924..c08f59df. Semantic name remains unreviewed. */

undefined4 FUN_c08f5924(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x28) == 0xcccc) && (*(int *)(param_1 + 0x20) == -1)) {
    iVar2 = *(int *)(param_1 + 8);
    iVar1 = FUN_c08f3f24(iVar2);
    if ((((iVar1 != 0) &&
         (((iVar1 = FUN_c08f3f98(*(int *)(param_1 + 4)), iVar1 != 0 && (iVar2 != 0)) &&
          ((*(uint *)(param_1 + 0x24) & 0x1c) == 0)))) &&
        (((*(int *)(param_1 + 0x10) == 0 && (*(int *)(param_1 + 0xc) == 0)) &&
         (*(int *)(param_1 + 0x3c) == 0)))) && (*(int *)(param_1 + 0x40) != 0)) {
      return 1;
    }
  }
  return 0;
}



/* c08f5ac4 FUN_c08f5ac4 */

undefined4 FUN_c08f5ac4(int param_1)

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



/* c08f5b68 FUN_c08f5b68 */

/* Boundary evidence: original MIPS .pdata c08f5b68..c08f5c97. Semantic name remains unreviewed. */

undefined4 FUN_c08f5b68(undefined4 param_1,int param_2)

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



/* c08f5c98 FUN_c08f5c98 */

undefined4 FUN_c08f5c98(int param_1)

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



/* c08f5d3c FUN_c08f5d3c */

/* Boundary evidence: original MIPS .pdata c08f5d3c..c08f5e5b. Semantic name remains unreviewed. */

undefined4 FUN_c08f5d3c(undefined4 param_1,int param_2)

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



/* c08f5e5c FUN_c08f5e5c */

undefined4 FUN_c08f5e5c(int param_1)

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



/* c08f5ffc FUN_c08f5ffc */

undefined4 FUN_c08f5ffc(int param_1)

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



/* c08f611c FUN_c08f611c */

undefined4 FUN_c08f611c(int param_1)

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



/* c08f6188 FUN_c08f6188 */

/* Boundary evidence: original MIPS .pdata c08f6188..c08f625b. Semantic name remains unreviewed. */

undefined4 FUN_c08f6188(undefined4 param_1,int param_2)

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



/* c08f625c FUN_c08f625c */

/* Boundary evidence: original MIPS .pdata c08f625c..c08f68e7. Semantic name remains unreviewed. */

undefined4 FUN_c08f625c(undefined4 param_1,int param_2)

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
        if (!bVar5) goto LAB_c08f6604;
        if (-1 < iVar12) goto LAB_c08f6600;
        iVar12 = local_50 + iVar12;
      }
      else {
        for (; iVar12 < 0; iVar12 = local_50 + iVar12) {
          iVar13 = iVar13 + 1;
        }
LAB_c08f6600:
        iVar12 = local_58 + iVar12;
LAB_c08f6604:
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
          goto LAB_c08f6810;
        }
        do {
          iVar32 = local_54 + iVar32;
          psVar16 = (short *)((int)psVar16 + iVar14);
        } while (iVar32 < 0);
      }
      iVar32 = local_5c + iVar32;
    }
LAB_c08f6810:
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
              goto LAB_c08f687c;
            }
            do {
              iVar13 = local_50 + iVar13;
              psVar16 = (short *)((int)psVar16 + iVar21);
            } while (iVar13 < 0);
          }
          iVar13 = local_58 + iVar13;
        }
LAB_c08f687c:
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



/* c08f68e8 FUN_c08f68e8 */

/* Boundary evidence: original MIPS .pdata c08f68e8..c08f6b07. Semantic name remains unreviewed. */

undefined4 FUN_c08f68e8(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (((DAT_c090c7a0 != 0) && (iVar2 = param_1[1], iVar2 != 0)) && (*(int *)(iVar2 + 0x38) == 0)) {
    if (((param_1[9] & 0x10) != 0) && (param_1[0x13] == 0xff0000)) {
      param_1[9] = param_1[9] & 0xffffffef;
    }
    iVar2 = *(int *)(iVar2 + 0x1c);
    if (iVar2 == 4) {
      iVar2 = FUN_c08f496c((int)param_1);
      if (iVar2 == 0) {
        iVar2 = FUN_c08f401c((int)param_1);
        if (iVar2 == 0) {
          iVar2 = FUN_c08f579c((int)param_1);
          if (iVar2 == 0) {
            iVar2 = FUN_c08f5c98((int)param_1);
            if (iVar2 == 0) {
              iVar2 = FUN_c08f527c((int)param_1);
              if (iVar2 == 0) {
                iVar2 = FUN_c08f5578((int)param_1);
                if (iVar2 == 0) {
                  iVar2 = FUN_c08f56f0((int)param_1);
                  if (iVar2 == 0) {
                    return 0;
                  }
                  pcVar1 = FUN_c08f625c;
                }
                else {
                  pcVar1 = (code *)&LAB_c08f561c;
                }
              }
              else {
                pcVar1 = FUN_c08f5338;
              }
            }
            else {
              pcVar1 = FUN_c08f5d3c;
            }
          }
          else {
            pcVar1 = (code *)&LAB_c08f5844;
          }
        }
        else {
          pcVar1 = FUN_c08f4114;
        }
      }
      else {
        pcVar1 = FUN_c08f49bc;
      }
    }
    else if (iVar2 == 5) {
      iVar2 = FUN_c08f4dec((int)param_1);
      if (iVar2 == 0) {
        iVar2 = FUN_c08f5ac4((int)param_1);
        if (iVar2 == 0) {
          iVar2 = FUN_c08f611c((int)param_1);
          if (iVar2 == 0) {
            return 0;
          }
          pcVar1 = FUN_c08f6188;
        }
        else {
          pcVar1 = FUN_c08f5b68;
        }
      }
      else {
        pcVar1 = FUN_c08f5000;
      }
    }
    else {
      if (iVar2 != 6) {
        return 0;
      }
      iVar2 = FUN_c08f5924((int)param_1);
      if (iVar2 == 0) {
        iVar2 = FUN_c08f5ffc((int)param_1);
        if (iVar2 == 0) {
          iVar2 = FUN_c08f5e5c((int)param_1);
          if (iVar2 == 0) {
            return 0;
          }
          pcVar1 = (code *)&LAB_c08f5ef8;
        }
        else {
          pcVar1 = (code *)&LAB_c08f6068;
        }
      }
      else {
        pcVar1 = (code *)&LAB_c08f59e0;
      }
    }
    *param_1 = pcVar1;
    return 0;
  }
  return 1;
}



/* c08f6b08 FUN_c08f6b08 */

/* Boundary evidence: original MIPS .pdata c08f6b08..c08f7107. Semantic name remains unreviewed. */

undefined4 FUN_c08f6b08(undefined4 param_1,int param_2)

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
    piVar12 = (int *)((int)&DAT_c090c7a4 + iVar11);
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
LAB_c08f6d70:
          *puVar9 = (char)(&DAT_c090c7a4)[bVar1 & 1];
          puVar9 = puVar9 + 1;
          pbVar15 = pbVar17;
        }
        else {
          if (uVar10 == 2) {
LAB_c08f6d54:
            *puVar9 = (char)(&DAT_c090c7a4)[bVar1 >> 1 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08f6d70;
          }
          if (uVar10 == 3) {
LAB_c08f6d38:
            *puVar9 = (char)(&DAT_c090c7a4)[bVar1 >> 2 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08f6d54;
          }
          if (uVar10 == 4) {
LAB_c08f6d1c:
            *puVar9 = (char)(&DAT_c090c7a4)[bVar1 >> 3 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08f6d38;
          }
          if (uVar10 == 5) {
LAB_c08f6d00:
            *puVar9 = (char)(&DAT_c090c7a4)[bVar1 >> 4 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08f6d1c;
          }
          if (uVar10 == 6) {
LAB_c08f6ce4:
            *puVar9 = (char)(&DAT_c090c7a4)[bVar1 >> 5 & 1];
            puVar9 = puVar9 + 1;
            goto LAB_c08f6d00;
          }
          pbVar15 = local_4c;
          if (uVar10 == 7) {
            puVar9 = local_48 + 1;
            *local_48 = (char)(&DAT_c090c7a4)[bVar1 >> 6 & 1];
            goto LAB_c08f6ce4;
          }
        }
        iVar8 = iVar16;
        if (0 < iVar16) {
          do {
            uVar5 = (uint)*pbVar15;
            puVar9[7] = (char)(&DAT_c090c7a4)[uVar5 & 1];
            puVar9[6] = (char)(&DAT_c090c7a4)[(int)uVar5 >> 1 & 1];
            puVar9[5] = (char)(&DAT_c090c7a4)[(int)uVar5 >> 2 & 1];
            puVar9[4] = (char)(&DAT_c090c7a4)[(int)uVar5 >> 3 & 1];
            puVar9[3] = (char)(&DAT_c090c7a4)[(int)uVar5 >> 4 & 1];
            puVar9[2] = (char)(&DAT_c090c7a4)[(int)uVar5 >> 5 & 1];
            pbVar15 = pbVar15 + 1;
            puVar9[1] = (char)(&DAT_c090c7a4)[(int)uVar5 >> 6 & 1];
            iVar8 = iVar8 + -1;
            *puVar9 = (char)(&DAT_c090c7a4)[(int)uVar5 >> 7];
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
                    if (uVar7 != 7) goto LAB_c08f709c;
                    puVar9[6] = (char)(&DAT_c090c7a4)[bVar1 >> 1 & 1];
                  }
                  puVar9[5] = (char)(&DAT_c090c7a4)[bVar1 >> 2 & 1];
                }
                puVar9[4] = (char)(&DAT_c090c7a4)[bVar1 >> 3 & 1];
              }
              puVar9[3] = (char)(&DAT_c090c7a4)[bVar1 >> 4 & 1];
            }
            puVar9[2] = (char)(&DAT_c090c7a4)[bVar1 >> 5 & 1];
          }
          puVar9[1] = (char)(&DAT_c090c7a4)[bVar1 >> 6 & 1];
        }
        *puVar9 = (char)(&DAT_c090c7a4)[bVar1 >> 7];
      }
      else {
        bVar1 = *local_4c;
        iVar8 = *piVar18;
        uVar13 = uVar10;
        for (uVar5 = uVar10; uVar5 != 0; uVar5 = uVar5 - 1) {
          uVar13 = uVar13 - 1;
          puVar9 = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar8,iVar6);
          *puVar9 = (char)(&DAT_c090c7a4)[bVar1 >> (uVar13 & 0x1f) & 1];
          iVar8 = iVar8 + 1;
        }
        pbVar15 = pbVar17;
        local_3c = iVar16;
        if (0 < iVar16) {
          do {
            bVar1 = *pbVar15;
            iVar11 = 0x7ffffff9;
            do {
              puVar9 = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar8,iVar6);
              *puVar9 = (char)(&DAT_c090c7a4)[bVar1 & 1];
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
            puVar9 = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar8,iVar6);
            uVar13 = uVar5 & 0x1f;
            uVar5 = uVar5 + 1;
            *puVar9 = (char)(&DAT_c090c7a4)[bVar1 >> uVar13 & 1];
            iVar8 = iVar8 + 1;
          } while ((int)uVar5 < (int)uVar7);
        }
      }
LAB_c08f709c:
      local_4c = local_4c + iVar2;
      pbVar17 = pbVar17 + iVar2;
      local_48 = local_48 + iVar3;
      iVar6 = iVar6 + 1;
    } while (iVar6 < piVar18[3]);
  }
  return 0;
}



/* c08f7108 FUN_c08f7108 */

/* Boundary evidence: original MIPS .pdata c08f7108..c08f731b. Semantic name remains unreviewed. */

undefined4 FUN_c08f7108(undefined4 param_1,int param_2)

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
            puVar2 = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar9,iVar3);
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



/* c08f731c FUN_c08f731c */

/* Boundary evidence: original MIPS .pdata c08f731c..c08f771f. Semantic name remains unreviewed. */

undefined4 FUN_c08f731c(undefined4 param_1,int param_2)

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
    if (bVar2) goto LAB_c08f74d0;
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
        puVar3 = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 8),iVar11,iVar4);
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
        puVar3 = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar13,iVar8);
        iVar13 = iVar13 + 1;
        *puVar3 = *puVar12;
      }
      iVar8 = iVar8 + 1;
      puVar6 = puVar6 + local_40;
      puVar10 = puVar10 + local_40;
    } while (iVar8 < piVar9[3]);
    return 0;
  }
LAB_c08f74d0:
  if (*(int *)(iVar4 + 0x38) == *(int *)(iVar5 + 0x38)) {
    local_34 = piVar7;
    local_30 = piVar7;
    if ((!bVar2) && (!bVar1)) {
      FUN_c08eaf98(iVar4,piVar7);
      FUN_c08eaf98(*(int *)(param_2 + 4),piVar9);
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
      FUN_c08eb04c(*(int *)(param_2 + 8),piVar7);
      FUN_c08eb04c(*(int *)(param_2 + 4),piVar9);
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
                     FUN_c08eb100(*(int *)(param_2 + 4),*piVar9 + iVar4,piVar9[1] + iVar13);
            puVar10 = (undefined1 *)
                      FUN_c08eb100(*(int *)(param_2 + 8),*piVar7 + iVar4,piVar7[1] + iVar13);
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



/* c08f7720 FUN_c08f7720 */

/* Boundary evidence: original MIPS .pdata c08f7720..c08f7b87. Semantic name remains unreviewed. */

undefined4 FUN_c08f7720(undefined4 param_1,int param_2)

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
          pbVar2 = (byte *)FUN_c08eb100(*(int *)(param_2 + 8),iVar5,iVar17);
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
  else if (uVar4 == 0) goto LAB_c08f78d8;
  if (!bVar1) {
    pbVar8 = (byte *)(piVar14[1] * iVar17 + *(int *)(iVar5 + 4) + *piVar14);
    if (piVar16[3] <= iVar9) {
      return 0;
    }
    pbVar11 = pbVar8 + iVar12;
    do {
      iVar15 = *piVar16;
      for (pbVar13 = pbVar8; pbVar13 < pbVar11; pbVar13 = pbVar13 + 1) {
        pbVar2 = (byte *)FUN_c08eb100(*(int *)(param_2 + 4),iVar15,iVar9);
        iVar15 = iVar15 + 1;
        *pbVar2 = *pbVar2 | *pbVar13;
      }
      iVar9 = iVar9 + 1;
      pbVar8 = pbVar8 + iVar17;
      pbVar11 = pbVar11 + iVar17;
    } while (iVar9 < piVar16[3]);
    return 0;
  }
LAB_c08f78d8:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar7 + 0x38)) {
    uVar3 = uVar4;
    uVar6 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c08eaf98(iVar5,piVar14);
      FUN_c08eaf98(*(int *)(param_2 + 4),piVar16);
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
      FUN_c08eb04c(*(int *)(param_2 + 8),piVar14);
      FUN_c08eb04c(*(int *)(param_2 + 4),piVar16);
    }
  }
  else {
    iVar17 = 0;
    if (0 < iVar10) {
      do {
        iVar15 = 0;
        if (0 < iVar12) {
          do {
            pbVar8 = (byte *)FUN_c08eb100(*(int *)(param_2 + 4),*piVar16 + iVar15,
                                          piVar16[1] + iVar17);
            pbVar11 = (byte *)FUN_c08eb100(*(int *)(param_2 + 8),*piVar14 + iVar15,
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



/* c08f7b88 FUN_c08f7b88 */

/* Boundary evidence: original MIPS .pdata c08f7b88..c08f8063. Semantic name remains unreviewed. */

undefined4 FUN_c08f7b88(undefined4 param_1,int param_2)

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
            _Dst = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 4),local_5c,iVar6);
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
                _Dst = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 4),local_5c,iVar6);
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
            _Dst = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 4),local_5c,iVar6);
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



/* c08f8064 FUN_c08f8064 */

/* Boundary evidence: original MIPS .pdata c08f8064..c08f8087. Semantic name remains unreviewed. */

void FUN_c08f8064(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = FUN_c08f29c0;
  FUN_c08f29c0(param_1,(int)param_2);
  return;
}



/* c08f8088 FUN_c08f8088 */

/* Boundary evidence: original MIPS .pdata c08f8088..c08f824f. Semantic name remains unreviewed. */

undefined4 FUN_c08f8088(undefined4 param_1,int param_2)

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
            if (!bVar1) goto LAB_c08f81d0;
          }
          else {
            if (bVar1) {
              puVar2 = (undefined1 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar5,iVar13);
            }
            *puVar2 = (char)uVar3;
LAB_c08f81d0:
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



/* c08f8250 FUN_c08f8250 */

/* Boundary evidence: original MIPS .pdata c08f8250..c08f8337. Semantic name remains unreviewed. */

undefined4 FUN_c08f8250(undefined4 param_1,int param_2)

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
    FUN_c08eaf98(*(int *)(param_2 + 4),piVar4);
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
    FUN_c08eb04c(*(int *)(param_2 + 4),piVar4);
  }
  return 0;
}



/* c08f8338 FUN_c08f8338 */

/* Boundary evidence: original MIPS .pdata c08f8338..c08f8493. Semantic name remains unreviewed. */

undefined4 FUN_c08f8338(undefined4 param_1,int param_2)

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
    FUN_c08eaf98(*(int *)(param_2 + 4),piVar7);
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
    FUN_c08eb04c(*(int *)(param_2 + 4),piVar7);
  }
  return 0;
}



/* c08f8494 FUN_c08f8494 */

/* Boundary evidence: original MIPS .pdata c08f8494..c08f8613. Semantic name remains unreviewed. */

undefined4 FUN_c08f8494(undefined4 param_1,int param_2)

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
    FUN_c08eaf98(*(int *)(param_2 + 4),piVar9);
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
    FUN_c08eb04c(*(int *)(param_2 + 4),piVar9);
  }
  return 0;
}



/* c08f8614 FUN_c08f8614 */

/* Boundary evidence: original MIPS .pdata c08f8614..c08f8963. Semantic name remains unreviewed. */

undefined4 FUN_c08f8614(undefined4 param_1,int param_2)

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
            pbVar2 = (byte *)FUN_c08eb100(*(int *)(param_2 + 4),**(int **)(param_2 + 0x14) + iVar9,
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



/* c08f8964 FUN_c08f8964 */

/* Boundary evidence: original MIPS .pdata c08f8964..c08f8dcb. Semantic name remains unreviewed. */

undefined4 FUN_c08f8964(undefined4 param_1,int param_2)

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
          pbVar2 = (byte *)FUN_c08eb100(*(int *)(param_2 + 8),iVar5,iVar17);
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
  else if (uVar4 == 0) goto LAB_c08f8b1c;
  if (!bVar1) {
    pbVar8 = (byte *)(piVar12[1] * iVar17 + *(int *)(iVar5 + 4) + *piVar12);
    if (piVar16[3] <= iVar9) {
      return 0;
    }
    pbVar11 = pbVar8 + iVar13;
    do {
      iVar15 = *piVar16;
      for (pbVar14 = pbVar8; pbVar14 < pbVar11; pbVar14 = pbVar14 + 1) {
        pbVar2 = (byte *)FUN_c08eb100(*(int *)(param_2 + 4),iVar15,iVar9);
        iVar15 = iVar15 + 1;
        *pbVar2 = *pbVar2 ^ *pbVar14;
      }
      iVar9 = iVar9 + 1;
      pbVar8 = pbVar8 + iVar17;
      pbVar11 = pbVar11 + iVar17;
    } while (iVar9 < piVar16[3]);
    return 0;
  }
LAB_c08f8b1c:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar7 + 0x38)) {
    uVar3 = uVar4;
    uVar6 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c08eaf98(iVar5,piVar12);
      FUN_c08eaf98(*(int *)(param_2 + 4),piVar16);
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
      FUN_c08eb04c(*(int *)(param_2 + 8),piVar12);
      FUN_c08eb04c(*(int *)(param_2 + 4),piVar16);
    }
  }
  else {
    iVar17 = 0;
    if (0 < iVar10) {
      do {
        iVar15 = 0;
        if (0 < iVar13) {
          do {
            pbVar8 = (byte *)FUN_c08eb100(*(int *)(param_2 + 4),*piVar16 + iVar15,
                                          piVar16[1] + iVar17);
            pbVar11 = (byte *)FUN_c08eb100(*(int *)(param_2 + 8),*piVar12 + iVar15,
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



/* c08f8dcc FUN_c08f8dcc */

/* Boundary evidence: original MIPS .pdata c08f8dcc..c08f9233. Semantic name remains unreviewed. */

undefined4 FUN_c08f8dcc(undefined4 param_1,int param_2)

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
          pbVar2 = (byte *)FUN_c08eb100(*(int *)(param_2 + 8),iVar5,iVar17);
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
  else if (uVar4 == 0) goto LAB_c08f8f84;
  if (!bVar1) {
    pbVar8 = (byte *)(piVar14[1] * iVar17 + *(int *)(iVar5 + 4) + *piVar14);
    if (piVar16[3] <= iVar9) {
      return 0;
    }
    pbVar11 = pbVar8 + iVar12;
    do {
      iVar15 = *piVar16;
      for (pbVar13 = pbVar8; pbVar13 < pbVar11; pbVar13 = pbVar13 + 1) {
        pbVar2 = (byte *)FUN_c08eb100(*(int *)(param_2 + 4),iVar15,iVar9);
        iVar15 = iVar15 + 1;
        *pbVar2 = *pbVar2 & *pbVar13;
      }
      iVar9 = iVar9 + 1;
      pbVar8 = pbVar8 + iVar17;
      pbVar11 = pbVar11 + iVar17;
    } while (iVar9 < piVar16[3]);
    return 0;
  }
LAB_c08f8f84:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar7 + 0x38)) {
    uVar3 = uVar4;
    uVar6 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c08eaf98(iVar5,piVar14);
      FUN_c08eaf98(*(int *)(param_2 + 4),piVar16);
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
      FUN_c08eb04c(*(int *)(param_2 + 8),piVar14);
      FUN_c08eb04c(*(int *)(param_2 + 4),piVar16);
    }
  }
  else {
    iVar17 = 0;
    if (0 < iVar10) {
      do {
        iVar15 = 0;
        if (0 < iVar12) {
          do {
            pbVar8 = (byte *)FUN_c08eb100(*(int *)(param_2 + 4),*piVar16 + iVar15,
                                          piVar16[1] + iVar17);
            pbVar11 = (byte *)FUN_c08eb100(*(int *)(param_2 + 8),*piVar14 + iVar15,
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



/* c08f9234 FUN_c08f9234 */

/* Boundary evidence: original MIPS .pdata c08f9234..c08f96cf. Semantic name remains unreviewed. */

undefined4 FUN_c08f9234(undefined4 param_1,int param_2)

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
          puVar2 = (ushort *)FUN_c08eb100(*(int *)(param_2 + 8),iVar11,iVar5);
          *puVar3 = *puVar3 | *puVar2;
          iVar11 = iVar11 + 1;
        }
        iVar5 = iVar5 + 1;
        puVar9 = puVar9 + uVar14;
      } while (iVar5 < piVar12[3]);
      return 0;
    }
  }
  else if (uVar4 == 0) goto LAB_c08f9404;
  if (!bVar1) {
    puVar9 = (ushort *)((piVar12[1] * uVar15 + *piVar12) * 2 + *(int *)(iVar5 + 4));
    if (piVar16[3] <= iVar10) {
      return 0;
    }
    do {
      iVar5 = *piVar16;
      for (puVar3 = puVar9; puVar3 < puVar9 + iVar13; puVar3 = puVar3 + 1) {
        puVar2 = (ushort *)FUN_c08eb100(*(int *)(param_2 + 4),iVar5,iVar10);
        iVar5 = iVar5 + 1;
        *puVar2 = *puVar2 | *puVar3;
      }
      iVar10 = iVar10 + 1;
      puVar9 = puVar9 + uVar15;
    } while (iVar10 < piVar16[3]);
    return 0;
  }
LAB_c08f9404:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar8 + 0x38)) {
    uVar6 = uVar4;
    uVar7 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c08eaf98(iVar5,piVar12);
      FUN_c08eaf98(*(int *)(param_2 + 4),piVar16);
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
      FUN_c08eb04c(*(int *)(param_2 + 8),piVar12);
      FUN_c08eb04c(*(int *)(param_2 + 4),piVar16);
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
                     FUN_c08eb100(*(int *)(param_2 + 4),*piVar16 + iVar8,piVar16[1] + iVar5);
            puVar3 = (ushort *)
                     FUN_c08eb100(*(int *)(param_2 + 8),*piVar12 + iVar8,piVar12[1] + iVar5);
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



/* c08f96d0 FUN_c08f96d0 */

/* Boundary evidence: original MIPS .pdata c08f96d0..c08f9cf3. Semantic name remains unreviewed. */

undefined4 FUN_c08f96d0(undefined4 param_1,int param_2)

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
    piVar14 = (int *)((int)&DAT_c090c7ac + iVar13);
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
LAB_c08f994c:
          *puVar3 = (short)(&DAT_c090c7ac)[bVar1 & 1];
          puVar3 = puVar3 + 1;
          pbVar18 = pbVar10;
        }
        else {
          if (uVar12 == 2) {
LAB_c08f9930:
            *puVar3 = (short)(&DAT_c090c7ac)[bVar1 >> 1 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08f994c;
          }
          if (uVar12 == 3) {
LAB_c08f9914:
            *puVar3 = (short)(&DAT_c090c7ac)[bVar1 >> 2 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08f9930;
          }
          if (uVar12 == 4) {
LAB_c08f98f8:
            *puVar3 = (short)(&DAT_c090c7ac)[bVar1 >> 3 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08f9914;
          }
          if (uVar12 == 5) {
LAB_c08f98dc:
            *puVar3 = (short)(&DAT_c090c7ac)[bVar1 >> 4 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08f98f8;
          }
          if (uVar12 == 6) {
LAB_c08f98c0:
            *puVar3 = (short)(&DAT_c090c7ac)[bVar1 >> 5 & 1];
            puVar3 = puVar3 + 1;
            goto LAB_c08f98dc;
          }
          pbVar18 = local_4c;
          if (uVar12 == 7) {
            puVar3 = puVar19 + 1;
            *puVar19 = (short)(&DAT_c090c7ac)[bVar1 >> 6 & 1];
            goto LAB_c08f98c0;
          }
        }
        iVar9 = iVar4;
        if (0 < iVar4) {
          do {
            uVar6 = (uint)*pbVar18;
            puVar3[7] = (short)(&DAT_c090c7ac)[uVar6 & 1];
            puVar3[6] = (short)(&DAT_c090c7ac)[(int)uVar6 >> 1 & 1];
            puVar3[5] = (short)(&DAT_c090c7ac)[(int)uVar6 >> 2 & 1];
            puVar3[4] = (short)(&DAT_c090c7ac)[(int)uVar6 >> 3 & 1];
            puVar3[3] = (short)(&DAT_c090c7ac)[(int)uVar6 >> 4 & 1];
            puVar3[2] = (short)(&DAT_c090c7ac)[(int)uVar6 >> 5 & 1];
            pbVar18 = pbVar18 + 1;
            puVar3[1] = (short)(&DAT_c090c7ac)[(int)uVar6 >> 6 & 1];
            iVar9 = iVar9 + -1;
            *puVar3 = (short)(&DAT_c090c7ac)[(int)uVar6 >> 7];
            puVar3 = puVar3 + 8;
          } while (iVar9 != 0);
        }
        bVar1 = *pbVar18;
        if (uVar8 == 1) {
LAB_c08f9b10:
          *puVar3 = (short)(&DAT_c090c7ac)[bVar1 >> 7];
        }
        else {
          if (uVar8 == 2) {
LAB_c08f9af8:
            puVar3[1] = (short)(&DAT_c090c7ac)[bVar1 >> 6 & 1];
            goto LAB_c08f9b10;
          }
          if (uVar8 == 3) {
LAB_c08f9ae0:
            puVar3[2] = (short)(&DAT_c090c7ac)[bVar1 >> 5 & 1];
            goto LAB_c08f9af8;
          }
          if (uVar8 == 4) {
LAB_c08f9ac8:
            puVar3[3] = (short)(&DAT_c090c7ac)[bVar1 >> 4 & 1];
            goto LAB_c08f9ae0;
          }
          if (uVar8 == 5) {
LAB_c08f9ab0:
            puVar3[4] = (short)(&DAT_c090c7ac)[bVar1 >> 3 & 1];
            goto LAB_c08f9ac8;
          }
          if (uVar8 == 6) {
LAB_c08f9a98:
            puVar3[5] = (short)(&DAT_c090c7ac)[bVar1 >> 2 & 1];
            goto LAB_c08f9ab0;
          }
          if (uVar8 == 7) {
            puVar3[6] = (short)(&DAT_c090c7ac)[bVar1 >> 1 & 1];
            goto LAB_c08f9a98;
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
          puVar3 = (undefined2 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar9,iVar7);
          *puVar3 = (short)(&DAT_c090c7ac)[bVar1 >> (uVar15 & 0x1f) & 1];
          iVar9 = iVar9 + 1;
        }
        pbVar18 = pbVar10;
        local_3c = iVar4;
        if (0 < iVar4) {
          do {
            bVar1 = *pbVar18;
            iVar13 = 0x7ffffff9;
            do {
              puVar3 = (undefined2 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar9,iVar7);
              *puVar3 = (short)(&DAT_c090c7ac)[bVar1 & 1];
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
            puVar3 = (undefined2 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar9,iVar7);
            uVar15 = uVar6 & 0x1f;
            uVar6 = uVar6 + 1;
            *puVar3 = (short)(&DAT_c090c7ac)[bVar1 >> uVar15 & 1];
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



/* c08f9cf4 FUN_c08f9cf4 */

/* Boundary evidence: original MIPS .pdata c08f9cf4..c08f9f17. Semantic name remains unreviewed. */

undefined4 FUN_c08f9cf4(undefined4 param_1,int param_2)

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
            puVar2 = (undefined2 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar8,iVar4);
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



/* c08f9f18 FUN_c08f9f18 */

/* Boundary evidence: original MIPS .pdata c08f9f18..c08fa33b. Semantic name remains unreviewed. */

undefined4 FUN_c08f9f18(undefined4 param_1,int param_2)

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
    if (bVar2) goto LAB_c08fa0e0;
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
        puVar3 = (undefined2 *)FUN_c08eb100(*(int *)(param_2 + 8),iVar12,iVar5);
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
        puVar3 = (undefined2 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar5,iVar9);
        iVar5 = iVar5 + 1;
        *puVar3 = *puVar4;
      }
      iVar9 = iVar9 + 1;
      puVar8 = puVar8 + uVar13;
    } while (iVar9 < piVar11[3]);
    return 0;
  }
LAB_c08fa0e0:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar6 + 0x38)) {
    local_40 = piVar11;
    local_3c = piVar11;
    if ((!bVar2) && (!bVar1)) {
      FUN_c08eaf98(iVar5,piVar10);
      FUN_c08eaf98(*(int *)(param_2 + 4),piVar11);
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
      FUN_c08eb04c(*(int *)(param_2 + 8),piVar10);
      FUN_c08eb04c(*(int *)(param_2 + 4),piVar11);
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
                     FUN_c08eb100(*(int *)(param_2 + 4),*piVar11 + iVar6,piVar11[1] + iVar5);
            puVar4 = (undefined2 *)
                     FUN_c08eb100(*(int *)(param_2 + 8),*piVar10 + iVar6,piVar10[1] + iVar5);
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



/* c08fa33c FUN_c08fa33c */

/* Boundary evidence: original MIPS .pdata c08fa33c..c08fa44f. Semantic name remains unreviewed. */

undefined4 FUN_c08fa33c(undefined4 param_1,int param_2)

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
    FUN_c08eaf98(*(int *)(param_2 + 4),piVar6);
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
    FUN_c08eb04c(*(int *)(param_2 + 4),piVar6);
  }
  return 0;
}



/* c08fa450 FUN_c08fa450 */

/* Boundary evidence: original MIPS .pdata c08fa450..c08fa8df. Semantic name remains unreviewed. */

undefined4 FUN_c08fa450(undefined4 param_1,int param_2)

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
          puVar2 = (ushort *)FUN_c08eb100(*(int *)(param_2 + 8),iVar11,iVar5);
          *puVar3 = *puVar3 ^ *puVar2;
          iVar11 = iVar11 + 1;
        }
        iVar5 = iVar5 + 1;
        puVar9 = puVar9 + uVar13;
      } while (iVar5 < piVar12[3]);
      return 0;
    }
  }
  else if (uVar4 == 0) goto LAB_c08fa620;
  if (!bVar1) {
    puVar9 = (ushort *)((piVar12[1] * uVar14 + *piVar12) * 2 + *(int *)(iVar5 + 4));
    if (piVar16[3] <= iVar10) {
      return 0;
    }
    do {
      iVar5 = *piVar16;
      for (puVar3 = puVar9; puVar3 < puVar9 + iVar15; puVar3 = puVar3 + 1) {
        puVar2 = (ushort *)FUN_c08eb100(*(int *)(param_2 + 4),iVar5,iVar10);
        iVar5 = iVar5 + 1;
        *puVar2 = *puVar2 ^ *puVar3;
      }
      iVar10 = iVar10 + 1;
      puVar9 = puVar9 + uVar14;
    } while (iVar10 < piVar16[3]);
    return 0;
  }
LAB_c08fa620:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar8 + 0x38)) {
    uVar6 = uVar4;
    uVar7 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c08eaf98(iVar5,piVar12);
      FUN_c08eaf98(*(int *)(param_2 + 4),piVar16);
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
      FUN_c08eb04c(*(int *)(param_2 + 8),piVar12);
      FUN_c08eb04c(*(int *)(param_2 + 4),piVar16);
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
                     FUN_c08eb100(*(int *)(param_2 + 4),*piVar16 + iVar8,piVar16[1] + iVar5);
            puVar3 = (ushort *)
                     FUN_c08eb100(*(int *)(param_2 + 8),*piVar12 + iVar8,piVar12[1] + iVar5);
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



/* c08fa8e0 FUN_c08fa8e0 */

/* Boundary evidence: original MIPS .pdata c08fa8e0..c08fad7b. Semantic name remains unreviewed. */

undefined4 FUN_c08fa8e0(undefined4 param_1,int param_2)

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
          puVar2 = (ushort *)FUN_c08eb100(*(int *)(param_2 + 8),iVar11,iVar5);
          *puVar3 = *puVar3 & *puVar2;
          iVar11 = iVar11 + 1;
        }
        iVar5 = iVar5 + 1;
        puVar9 = puVar9 + uVar14;
      } while (iVar5 < piVar12[3]);
      return 0;
    }
  }
  else if (uVar4 == 0) goto LAB_c08faab0;
  if (!bVar1) {
    puVar9 = (ushort *)((piVar12[1] * uVar15 + *piVar12) * 2 + *(int *)(iVar5 + 4));
    if (piVar16[3] <= iVar10) {
      return 0;
    }
    do {
      iVar5 = *piVar16;
      for (puVar3 = puVar9; puVar3 < puVar9 + iVar13; puVar3 = puVar3 + 1) {
        puVar2 = (ushort *)FUN_c08eb100(*(int *)(param_2 + 4),iVar5,iVar10);
        iVar5 = iVar5 + 1;
        *puVar2 = *puVar2 & *puVar3;
      }
      iVar10 = iVar10 + 1;
      puVar9 = puVar9 + uVar15;
    } while (iVar10 < piVar16[3]);
    return 0;
  }
LAB_c08faab0:
  if (*(int *)(iVar5 + 0x38) == *(int *)(iVar8 + 0x38)) {
    uVar6 = uVar4;
    uVar7 = uVar4;
    if ((uVar4 != 0) && (bVar1)) {
      FUN_c08eaf98(iVar5,piVar12);
      FUN_c08eaf98(*(int *)(param_2 + 4),piVar16);
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
      FUN_c08eb04c(*(int *)(param_2 + 8),piVar12);
      FUN_c08eb04c(*(int *)(param_2 + 4),piVar16);
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
                     FUN_c08eb100(*(int *)(param_2 + 4),*piVar16 + iVar8,piVar16[1] + iVar5);
            puVar3 = (ushort *)
                     FUN_c08eb100(*(int *)(param_2 + 8),*piVar12 + iVar8,piVar12[1] + iVar5);
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



/* c08fad7c FUN_c08fad7c */

/* Boundary evidence: original MIPS .pdata c08fad7c..c08fad9f. Semantic name remains unreviewed. */

void FUN_c08fad7c(double param_1,double param_2,undefined4 param_3,undefined4 *param_4)

{
  *param_4 = FUN_c08f31d4;
  FUN_c08f31d4(param_1,param_2,param_3,(int)param_4);
  return;
}



/* c08fada0 FUN_c08fada0 */

/* Boundary evidence: original MIPS .pdata c08fada0..c08faf67. Semantic name remains unreviewed. */

undefined4 FUN_c08fada0(undefined4 param_1,int param_2)

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
              puVar2 = (undefined2 *)FUN_c08eb100(*(int *)(param_2 + 4),iVar5,iVar13);
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



/* c08faf68 FUN_c08faf68 */

uint FUN_c08faf68(uint param_1)

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
  if (0 < DAT_c090c9d0) {
    pbVar1 = (byte *)(DAT_c090c9cc + 2);
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
    } while ((int)uVar6 < DAT_c090c9d0);
  }
  return uVar7;
}



/* c08fb030 FUN_c08fb030 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c08fb030..c08fb467. Semantic name remains unreviewed. */

void FUN_c08fb030(int param_1,uint *param_2,uint param_3,uint param_4)

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
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  byte *pbVar13;
  int local_50;
  
  iVar5 = DAT_c090c9cc;
  iVar11 = 1;
  DAT_c090c98c = DAT_c0906fc0;
  DAT_c090c7b4 = param_4;
  DAT_c090c984 = param_3;
  DAT_c090c988 = param_1;
  if (param_1 == 1) {
    uVar9 = *(uint *)(param_3 * 4 + DAT_c090c9cc);
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
  pbVar13 = &DAT_c0908920;
  puVar10 = (uint *)&DAT_c090c7b8;
  puVar12 = puVar10;
  do {
    puVar12 = (uint *)((int)puVar12 + 2);
    puVar10 = puVar10 + 1;
    uVar4 = param_2[0xd];
    bVar1 = *(byte *)((*(int *)(&DAT_c0907000 + (uint)*pbVar13 * 4) * local_50 + 0x80000 >> 0x14) +
                      uVar4 + uVar8);
    bVar2 = *(byte *)((*(int *)(&DAT_c0907000 + (uint)pbVar13[1] * 4) * iVar7 + 0x80000 >> 0x14) +
                      uVar4 + uVar6);
    bVar3 = *(byte *)((*(int *)(&DAT_c0907000 + (uint)pbVar13[2] * 4) * iVar5 + 0x80000 >> 0x14) +
                      uVar4 + uVar9);
    if (param_1 == 1) {
      uVar4 = FUN_c08faf68((uint)CONCAT21(CONCAT11(bVar3,bVar2),bVar1));
      (&DAT_c090c7b8)[iVar11] = (char)uVar4;
    }
    else {
      uVar4 = ((uint)bVar3 << (param_2[5] & 0x1f)) >> (param_2[4] & 0x1f) & param_2[8] |
              ((uint)bVar2 << (param_2[3] & 0x1f)) >> (param_2[2] & 0x1f) & param_2[7] |
              ((uint)bVar1 << (param_2[1] & 0x1f)) >> (*param_2 & 0x1f) & param_2[6];
      if (param_1 == 2) {
        *(short *)puVar12 = (short)uVar4;
      }
      else if (param_1 == 4) {
        *puVar10 = uVar4;
      }
    }
    iVar11 = iVar11 + 1;
    pbVar13 = pbVar13 + 4;
  } while (iVar11 < 0x72);
  if (param_1 == 2) {
    _DAT_c090c7b8 = CONCAT22(DAT_c090c7ba,(short)param_4);
    DAT_c090c89c = (undefined2)param_3;
    uVar9 = _DAT_c090c7b8;
    uVar8 = DAT_c090c980;
  }
  else {
    uVar9 = param_4;
    uVar8 = param_3;
    if ((param_1 != 4) && (uVar9 = _DAT_c090c7b8, uVar8 = DAT_c090c980, param_1 == 1)) {
      _DAT_c090c7b8 = CONCAT31(_DAT_c090c7b9,(char)param_4);
      DAT_c090c82a = (undefined1)param_3;
      uVar9 = _DAT_c090c7b8;
    }
  }
  DAT_c090c980 = uVar8;
  _DAT_c090c7b8 = uVar9;
  return;
}



/* c08fb468 FUN_c08fb468 */

/* Boundary evidence: original MIPS .pdata c08fb468..c08fb4f7. Semantic name remains unreviewed. */

undefined1 * FUN_c08fb468(int param_1,uint param_2,uint param_3,uint *param_4)

{
  if ((((param_3 != DAT_c090c7b4) || (param_2 != DAT_c090c984)) || (param_1 != DAT_c090c988)) ||
     ((DAT_c0906fc0 != DAT_c090c98c || ((param_1 == 1 && (DAT_c090c9cc == 0)))))) {
    FUN_c08fb030(param_1,param_4,param_2,param_3);
  }
  return &DAT_c090c7b8;
}



/* c08fb4f8 FUN_c08fb4f8 */

/* Boundary evidence: original MIPS .pdata c08fb4f8..c08fb62b. Semantic name remains unreviewed. */

void FUN_c08fb4f8(int param_1,int param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *(uint *)(param_2 * 4 + DAT_c090c9cc);
  iVar2 = *(int *)(param_1 + 0x30);
  uVar4 = (uint)*(byte *)((uVar3 & 0xff) + iVar2);
  iVar1 = *(int *)(param_1 + 0x34);
  uVar5 = (uint)*(byte *)((uVar3 >> 8 & 0xff) + iVar2);
  uVar3 = (uint)*(byte *)((uVar3 >> 0x10 & 0xff) + iVar2);
  FUN_c08faf68((uint)CONCAT12(*(undefined1 *)
                               (((int)(*(int *)(&DAT_c0907000 + (uint)param_3[2] * 4) *
                                       (*(int *)(param_1 + 0x2c) - uVar3) + 0x80000) >> 0x14) +
                                iVar1 + uVar3),
                              CONCAT11(*(undefined1 *)
                                        (((int)(*(int *)(&DAT_c0907000 + (uint)param_3[1] * 4) *
                                                (*(int *)(param_1 + 0x28) - uVar5) + 0x80000) >>
                                         0x14) + iVar1 + uVar5),
                                       *(undefined1 *)
                                        (((int)(*(int *)(&DAT_c0907000 + (uint)*param_3 * 4) *
                                                (*(int *)(param_1 + 0x24) - uVar4) + 0x80000) >>
                                         0x14) + iVar1 + uVar4))));
  return;
}



/* c08fb62c FUN_c08fb62c */

/* Boundary evidence: original MIPS .pdata c08fb62c..c08fb7c7. Semantic name remains unreviewed. */

uint FUN_c08fb62c(uint *param_1,uint param_2,byte *param_3)

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
  return ((uint)*(byte *)(((int)(*(int *)(&DAT_c0907000 + (uint)param_3[2] * 4) *
                                 (param_1[0xb] - uVar3) + 0x80000) >> 0x14) + uVar4 + uVar3) <<
         (param_1[5] & 0x1f)) >> (param_1[4] & 0x1f) & param_1[8] |
         ((uint)*(byte *)(((int)(*(int *)(&DAT_c0907000 + (uint)param_3[1] * 4) *
                                 (param_1[10] - uVar2) + 0x80000) >> 0x14) + uVar4 + uVar2) <<
         (param_1[3] & 0x1f)) >> (param_1[2] & 0x1f) & param_1[7] |
         ((uint)*(byte *)(((int)(*(int *)(&DAT_c0907000 + (uint)*param_3 * 4) * (param_1[9] - uVar1)
                                + 0x80000) >> 0x14) + uVar4 + uVar1) << (param_1[1] & 0x1f)) >>
         (*param_1 & 0x1f) & param_1[6];
}



/* c08fb7c8 FUN_c08fb7c8 */

/* Boundary evidence: original MIPS .pdata c08fb7c8..c08fb9a7. Semantic name remains unreviewed. */

undefined4 FUN_c08fb7c8(undefined4 param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  byte *pbVar14;
  int iVar15;
  
  uVar1 = *(ushort *)(param_2 + 0x20);
  piVar9 = *(int **)(param_2 + 0x14);
  iVar11 = piVar9[1];
  iVar12 = *piVar9;
  iVar8 = piVar9[2];
  iVar6 = piVar9[3];
  iVar10 = *(int *)(*(int *)(param_2 + 0xc) + 8);
  iVar15 = *(int *)(*(int *)(param_2 + 4) + 8);
  pbVar14 = (byte *)((*(int **)(param_2 + 0x2c))[1] * iVar10 + *(int *)(*(int *)(param_2 + 0xc) + 4)
                    + **(int **)(param_2 + 0x2c));
  puVar13 = (ushort *)(iVar11 * iVar15 + iVar12 * 2 + *(int *)(*(int *)(param_2 + 4) + 4));
  uVar2 = *puVar13;
  puVar5 = FUN_c08fb468(2,(uint)uVar1,(uint)uVar2,&DAT_c090c990);
  for (iVar6 = iVar6 - iVar11; iVar11 = iVar8 - iVar12, puVar3 = puVar13, pbVar4 = pbVar14,
      iVar6 != 0; iVar6 = iVar6 + -1) {
    for (; iVar11 != 0; iVar11 = iVar11 + -1) {
      uVar7 = (uint)*pbVar4;
      if (uVar7 != 0) {
        if (uVar7 == 0x72) {
          *puVar3 = uVar1;
        }
        else if ((uint)*puVar3 == (uint)uVar2) {
          *puVar3 = *(ushort *)(puVar5 + uVar7 * 2);
        }
        else {
          uVar7 = FUN_c08fb62c(&DAT_c090c990,(uint)*puVar3,(byte *)(uVar7 * 4 + -0x3f6f76e4));
          *puVar3 = (ushort)uVar7;
        }
      }
      puVar3 = puVar3 + 1;
      pbVar4 = pbVar4 + 1;
    }
    puVar13 = (ushort *)((int)puVar13 + iVar15);
    pbVar14 = pbVar14 + iVar10;
  }
  return 0;
}



/* c08fb9a8 FUN_c08fb9a8 */

/* Boundary evidence: original MIPS .pdata c08fb9a8..c08fbbe3. Semantic name remains unreviewed. */

undefined4 FUN_c08fb9a8(undefined4 param_1,int param_2)

{
  uint3 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint3 *puVar8;
  uint3 *puVar9;
  uint3 *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  uint local_3c;
  uint local_38;
  int local_34;
  int local_30;
  
  piVar4 = *(int **)(param_2 + 0x14);
  local_3c = *(uint *)(param_2 + 0x20) & 0xffffff;
  iVar7 = *piVar4;
  iVar3 = piVar4[2];
  local_30 = *(int *)(*(int *)(param_2 + 0xc) + 8);
  iVar14 = *(int *)(*(int *)(param_2 + 4) + 8);
  iVar13 = piVar4[3] - piVar4[1];
  pbVar11 = (byte *)((*(int **)(param_2 + 0x2c))[1] * local_30 +
                     *(int *)(*(int *)(param_2 + 0xc) + 4) + **(int **)(param_2 + 0x2c));
  puVar8 = (uint3 *)(piVar4[1] * iVar14 + iVar7 * 3 + *(int *)(*(int *)(param_2 + 4) + 4));
  uVar1 = *puVar8;
  local_34 = iVar14;
  puVar2 = FUN_c08fb468(4,local_3c,(uint)uVar1,&DAT_c090c990);
  if (iVar13 != 0) {
    puVar10 = (uint3 *)((int)puVar8 + (iVar3 - iVar7) * 3);
    pbVar12 = pbVar11;
    puVar9 = puVar8;
    do {
      for (; puVar8 < puVar10; puVar8 = (uint3 *)((int)puVar8 + 3)) {
        uVar6 = (uint)*pbVar11;
        if (uVar6 != 0) {
          if (uVar6 == 0x72) {
            puVar5 = &local_3c;
          }
          else if ((uint)*puVar8 == (uint)uVar1) {
            puVar5 = (uint *)(puVar2 + uVar6 * 4);
          }
          else {
            local_38 = FUN_c08fb62c(&DAT_c090c990,(uint)*puVar8,(byte *)(uVar6 * 4 + -0x3f6f76e4));
            puVar5 = &local_38;
          }
          *(char *)puVar8 = (char)*puVar5;
          *(undefined1 *)((int)puVar8 + 1) = *(undefined1 *)((int)puVar5 + 1);
          *(undefined1 *)((int)puVar8 + 2) = *(undefined1 *)((int)puVar5 + 2);
        }
        pbVar11 = pbVar11 + 1;
        iVar14 = local_34;
      }
      iVar13 = iVar13 + -1;
      pbVar11 = pbVar12 + local_30;
      puVar8 = (uint3 *)((int)puVar9 + iVar14);
      puVar10 = (uint3 *)((int)puVar10 + iVar14);
      pbVar12 = pbVar11;
      puVar9 = puVar8;
    } while (iVar13 != 0);
  }
  return 0;
}



/* c08fbbe4 FUN_c08fbbe4 */

/* Boundary evidence: original MIPS .pdata c08fbbe4..c08fbdab. Semantic name remains unreviewed. */

undefined4 FUN_c08fbbe4(undefined4 param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  
  iVar6 = *(int *)(*(int *)(param_2 + 0xc) + 8);
  piVar4 = *(int **)(param_2 + 0x14);
  iVar14 = *(int *)(*(int *)(param_2 + 4) + 8);
  iVar2 = piVar4[2];
  iVar7 = *piVar4;
  iVar13 = piVar4[3] - piVar4[1];
  uVar15 = *(uint *)(param_2 + 0x20);
  pbVar11 = (byte *)((*(int **)(param_2 + 0x2c))[1] * iVar6 + *(int *)(*(int *)(param_2 + 0xc) + 4)
                    + **(int **)(param_2 + 0x2c));
  puVar8 = (uint *)(piVar4[1] * iVar14 + iVar7 * 4 + *(int *)(*(int *)(param_2 + 4) + 4));
  uVar3 = *puVar8;
  puVar1 = FUN_c08fb468(4,uVar15,uVar3,&DAT_c090c990);
  if (iVar13 != 0) {
    puVar10 = puVar8 + (iVar2 - iVar7);
    pbVar12 = pbVar11;
    puVar9 = puVar8;
    do {
      for (; puVar8 < puVar10; puVar8 = puVar8 + 1) {
        uVar5 = (uint)*pbVar11;
        if (uVar5 != 0) {
          if (uVar5 == 0x72) {
            *puVar8 = uVar15;
          }
          else if (*puVar8 == uVar3) {
            *puVar8 = *(uint *)(puVar1 + uVar5 * 4);
          }
          else {
            uVar5 = FUN_c08fb62c(&DAT_c090c990,*puVar8,(byte *)(uVar5 * 4 + -0x3f6f76e4));
            *puVar8 = uVar5;
          }
        }
        pbVar11 = pbVar11 + 1;
      }
      iVar13 = iVar13 + -1;
      pbVar11 = pbVar12 + iVar6;
      puVar8 = (uint *)((int)puVar9 + iVar14);
      puVar10 = (uint *)((int)puVar10 + iVar14);
      pbVar12 = pbVar11;
      puVar9 = puVar8;
    } while (iVar13 != 0);
  }
  return 0;
}



/* c08fbdac FUN_c08fbdac */

/* Boundary evidence: original MIPS .pdata c08fbdac..c08fbf77. Semantic name remains unreviewed. */

undefined4 FUN_c08fbdac(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  bVar1 = *(byte *)(param_2 + 0x20);
  piVar6 = *(int **)(param_2 + 0x14);
  iVar9 = *piVar6;
  iVar5 = piVar6[2];
  iVar8 = *(int *)(*(int *)(param_2 + 0xc) + 8);
  iVar14 = piVar6[3] - piVar6[1];
  iVar15 = *(int *)(*(int *)(param_2 + 4) + 8);
  iVar13 = (*(int **)(param_2 + 0x2c))[1] * iVar8 + *(int *)(*(int *)(param_2 + 0xc) + 4) +
           **(int **)(param_2 + 0x2c);
  pbVar11 = (byte *)(piVar6[1] * iVar15 + *(int *)(*(int *)(param_2 + 4) + 4) + iVar9);
  bVar2 = *pbVar11;
  puVar4 = FUN_c08fb468(1,(uint)bVar1,(uint)bVar2,&DAT_c090c990);
  if (iVar14 != 0) {
    pbVar12 = pbVar11 + (iVar5 - iVar9);
    do {
      if (pbVar11 < pbVar12) {
        pbVar10 = pbVar11;
        do {
          uVar7 = (uint)pbVar10[iVar13 - (int)pbVar11];
          if (uVar7 != 0) {
            if (uVar7 == 0x72) {
              *pbVar10 = bVar1;
            }
            else if ((uint)*pbVar10 == (uint)bVar2) {
              *pbVar10 = puVar4[uVar7];
            }
            else {
              bVar3 = FUN_c08fb4f8(-0x3f6f3670,(uint)*pbVar10,(byte *)(uVar7 * 4 + -0x3f6f76e4));
              *pbVar10 = bVar3;
            }
          }
          pbVar10 = pbVar10 + 1;
        } while (pbVar10 < pbVar12);
      }
      iVar14 = iVar14 + -1;
      iVar13 = iVar13 + iVar8;
      pbVar11 = pbVar11 + iVar15;
      pbVar12 = pbVar12 + iVar15;
    } while (iVar14 != 0);
  }
  return 0;
}



/* c08fbf78 FUN_c08fbf78 */

void FUN_c08fbf78(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  DAT_c090c9a8 = param_1;
  DAT_c090c9ac = param_2;
  iVar1 = 0;
  DAT_c090c9b0 = param_3;
  for (; param_1 != 0; param_1 = param_1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c090c994 = iVar1 + -8;
  iVar1 = 0;
  for (; param_2 != 0; param_2 = param_2 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c090c99c = iVar1 + -8;
  iVar1 = 0;
  for (; param_3 != 0; param_3 = param_3 >> 1) {
    iVar1 = iVar1 + 1;
  }
  DAT_c090c9a4 = iVar1 + -8;
  DAT_c090c990 = 0;
  if (DAT_c090c994 < 0) {
    DAT_c090c990 = -DAT_c090c994;
    DAT_c090c994 = 0;
  }
  DAT_c090c998 = 0;
  if (DAT_c090c99c < 0) {
    DAT_c090c998 = -DAT_c090c99c;
    DAT_c090c99c = 0;
  }
  DAT_c090c9a0 = 0;
  if (DAT_c090c9a4 < 0) {
    DAT_c090c9a0 = -DAT_c090c9a4;
    DAT_c090c9a4 = 0;
  }
  DAT_c090c988 = 0;
  return;
}



/* c08fc044 FUN_c08fc044 */

void FUN_c08fc044(uint param_1)

{
  DAT_c0906fc0 = param_1;
  DAT_c090c98c = 0;
  if (param_1 < 0x44c) {
    DAT_c090c9c0 = &DAT_c090701c;
    DAT_c090c9c4 = &DAT_c090701c;
  }
  else if (param_1 < 0x4b0) {
    DAT_c090c9c0 = &DAT_c090711c;
    DAT_c090c9c4 = &DAT_c090721c;
  }
  else if (param_1 < 0x514) {
    DAT_c090c9c0 = &DAT_c090731c;
    DAT_c090c9c4 = &DAT_c090741c;
  }
  else if (param_1 < 0x578) {
    DAT_c090c9c0 = &DAT_c090751c;
    DAT_c090c9c4 = &DAT_c090761c;
  }
  else if (param_1 < 0x5dc) {
    DAT_c090c9c0 = &DAT_c090771c;
    DAT_c090c9c4 = &DAT_c090781c;
  }
  else if (param_1 < 0x640) {
    DAT_c090c9c0 = &DAT_c090791c;
    DAT_c090c9c4 = &DAT_c0907a1c;
  }
  else if (param_1 < 0x6a4) {
    DAT_c090c9c0 = &DAT_c0907b1c;
    DAT_c090c9c4 = &DAT_c0907c1c;
  }
  else if (param_1 < 0x708) {
    DAT_c090c9c0 = &DAT_c0907d1c;
    DAT_c090c9c4 = &DAT_c0907e1c;
  }
  else if (param_1 < 0x76c) {
    DAT_c090c9c0 = &DAT_c0907f1c;
    DAT_c090c9c4 = &DAT_c090801c;
  }
  else if (param_1 < 2000) {
    DAT_c090c9c0 = &DAT_c090811c;
    DAT_c090c9c4 = &DAT_c090821c;
  }
  else if (param_1 < 0x834) {
    DAT_c090c9c0 = &DAT_c090831c;
    DAT_c090c9c4 = &DAT_c090841c;
  }
  else if (param_1 < 0x898) {
    DAT_c090c9c0 = &DAT_c090851c;
    DAT_c090c9c4 = &DAT_c090861c;
  }
  else {
    DAT_c090c9c0 = &DAT_c090871c;
    DAT_c090c9c4 = &DAT_c090881c;
  }
  return;
}



/* c08fc260 FUN_c08fc260 */

undefined4 FUN_c08fc260(undefined4 *param_1)

{
  *param_1 = DAT_c0906fc0;
  return 1;
}



/* c08fc274 FUN_c08fc274 */

/* Boundary evidence: original MIPS .pdata c08fc274..c08fc34f. Semantic name remains unreviewed. */

undefined4 FUN_c08fc274(uint param_1,int param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  uint local_res0 [4];
  HKEY local_10;
  DWORD DStack_c;
  
  local_res0[0] = param_1;
  if (param_2 == 0) {
LAB_c08fc338:
    FUN_c08fc044(local_res0[0]);
    uVar2 = 1;
  }
  else {
    LVar1 = RegCreateKeyExW((HKEY)0x80000002,u_System_GDI_Gamma_c0906fc4,0,(LPWSTR)0x0,0,0,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_10,&DStack_c);
    if (LVar1 == 0) {
      LVar1 = RegSetValueExW(local_10,u_Gamma_Value_c0906fe8,0,4,(BYTE *)local_res0,4);
      if (LVar1 == 0) {
        RegCloseKey(local_10);
        goto LAB_c08fc338;
      }
      RegCloseKey(local_10);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* c08fc350 FUN_c08fc350 */

/* Boundary evidence: original MIPS .pdata c08fc350..c08fc4eb. Semantic name remains unreviewed. */

undefined4 FUN_c08fc350(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

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
  if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
    uVar4 = 0;
    uVar1 = DAT_c090c9cc;
    uVar2 = DAT_c090c9d0;
  }
  else {
    LVar3 = RegCreateKeyExW((HKEY)0x80000002,u_System_GDI_Gamma_c0906fc4,0,(LPWSTR)0x0,0,0,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_2c,&local_30);
    uVar4 = 1;
    if (LVar3 == 0) {
      if (local_30 == 2) {
        local_24[1] = 4;
        local_24[0] = 4;
        LVar3 = RegQueryValueExW(local_2c,u_Gamma_Value_c0906fe8,(LPDWORD)0x0,local_24 + 1,
                                 (LPBYTE)&local_30,local_24);
        if (LVar3 == 0) {
          local_28 = local_30;
        }
      }
      else if (local_30 == 1) {
        RegSetValueExW(local_2c,u_Gamma_Value_c0906fe8,0,4,(BYTE *)&local_28,4);
      }
      RegCloseKey(local_2c);
    }
    FUN_c08fc044(local_28);
    uVar1 = param_3;
    uVar2 = param_4;
    if (8 < *(int *)(param_1 + 0xc)) {
      FUN_c08fbf78(*param_2,param_2[1],param_2[2]);
      uVar1 = DAT_c090c9cc;
      uVar2 = DAT_c090c9d0;
    }
  }
  DAT_c090c9d0 = uVar2;
  DAT_c090c9cc = uVar1;
  return uVar4;
}



/* c08fc4ec FUN_c08fc4ec */

undefined4 FUN_c08fc4ec(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((param_1[10] & 0xffff) != 0xaaf0) {
    return 0;
  }
  if (*(int *)(param_1[3] + 0x1c) != 3) {
    return 0;
  }
  iVar2 = *(int *)(&LAB_c08d284c + *(int *)(param_1[1] + 0x1c) * 4);
  if (iVar2 == 8) {
    pcVar1 = FUN_c08fbdac;
LAB_c08fc590:
    *param_1 = pcVar1;
  }
  else {
    if (iVar2 == 0x10) {
      pcVar1 = FUN_c08fb7c8;
    }
    else {
      if (iVar2 == 0x18) {
        pcVar1 = FUN_c08fb9a8;
        goto LAB_c08fc590;
      }
      if (iVar2 != 0x20) {
        return 0;
      }
      pcVar1 = FUN_c08fbbe4;
    }
    *param_1 = pcVar1;
  }
  return 0;
}



/* c08fc67c FUN_c08fc67c */

/* Boundary evidence: original MIPS .pdata c08fc67c..c08fc6ab. Semantic name remains unreviewed. */

void FUN_c08fc67c(void)

{
  FUN_c08ebb60(-0x3f6f6210,0x6e0,2,&LAB_c08ec7c4);
  return;
}


